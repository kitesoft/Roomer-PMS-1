unit uTableEntityList;

interface

uses
  cmpRoomerDataset
  , Generics.Collections
  , SysUtils
  ;

type

  ERefreshTableException = class(Exception);

  TCachedTableEntity = class
  private
    FTableName: String;
    FSql: String;
    FRSet: TRoomerDataSet;
    FRefreshEnabled : Boolean;
    FLastUpdateOnServerUTC: TDateTime;
    function GetFilename: String;
    function ReadFromFile: String;
    procedure SaveToFile(const data: String);
    function FileTimeStamp: TDateTime;

    function IsStale: boolean;
    procedure SetLastUpdateOnServer(const Value: TDateTime);
  public
    constructor Create(const tableName : String; const sqlExtension : String = '');
    destructor Destroy; override;
    /// <summary>
    ///   Forcibly reload the data from the server and save it in local cache file
    /// </summary>
    procedure RefreshFromServer;
    /// <summary>
    ///   Reload data from local cache file. If this file is empty or ForceRefresh is True then RefreshFromServer is called
    /// </summary>
    procedure RefreshLocally(ForceRefresh : Boolean = true);
    /// <summary>
    ///   Calls RefreshFromServer if server-timestamp is higher then local file timestamp
    /// </summary>
    procedure RefreshIfNeeded;

    property TableName : String read FTableName;
    property RSet : TRoomerDataSet read FRSet;
    property RefreshEnabled : Boolean read FRefreshEnabled write FRefreshEnabled;
    property LastUpdateOnServerUTC: TDateTime read FLastUpdateOnServerUTC write SetLastUpdateOnServer;
    /// <summary>
    ///   Filedatetime of the locally stored cache file in local time, is the last time that RefreshFromServer has been done
    /// </summary>
    property LocalFileDate: TDateTime read FileTimeStamp;
  end;

  TTableDictionary = class(TObjectDictionary<String, TCachedTableEntity>)
  private
    function GetTableEntityByName(aName: string): TCachedTableEntity;
    function GetDatasetByName(aName: string): TRoomerDataset;
    procedure InitializeTables;
  public
    constructor Create;
    procedure RefreshAllIfNeeded;
    procedure RefreshAllLocally(ForceRefresh : Boolean = true);

    property TableEntity[aName: string]: TCachedTableEntity read GetTableEntityByName;
    property Dataset[aName: string]: TRoomerDataset read GetDatasetByName;
  end;

const
  cRoomerTableFileName = 'RoomerTable_%s.src';



implementation

uses
  uD
  , Windows
  , AdODB
  , uMessageList
  , uUtils
  , IOUtils
  , uStringUtils
  , DateUtils
  , uFileSystemUtils
  , uAppGlobal
  , PrjConst
  , uCachedDataHandler;
{ TTableDictionary }

constructor TTableDictionary.Create;
begin
  inherited Create([doOwnsValues], TCaseInsensitiveEqualityComparer.Create);
  InitializeTables;
end;

function TTableDictionary.GetDatasetByName(aName: string): TRoomerDataset;
var
  lTable: TCachedTableEntity;
begin
  if TryGetValue(aName, lTable) then
    Result := lTable.RSet
  else
    Result := nil;
end;

function TTableDictionary.GetTableEntityByName(aName: string): TCachedTableEntity;
begin
  if NOT TryGetValue(aName, result) then
    result := nil;
end;

procedure TTableDictionary.InitializeTables;
begin

  Add('rooms', TCachedTableEntity.Create('rooms', 'ORDER BY OrderIndex Desc, Room ASC'));

  Add('maintenancecodes', TCachedTableEntity.Create('maintenancecodes'));
  Add('maintenanceroomnotes', TCachedTableEntity.Create('maintenanceroomnotes'));
  Add('staffmembers', TCachedTableEntity.Create('staffmembers'));

  Add('locations', TCachedTableEntity.Create('locations'));
  Add('packages', TCachedTableEntity.Create('packages'));
  Add('packageitems', TCachedTableEntity.Create('packageitems'));
  Add('roomtyperules', TCachedTableEntity.Create('roomtyperules'));
  Add('vatcodes', TCachedTableEntity.Create('vatcodes'));
  Add('items', TCachedTableEntity.Create('items'));
  Add('itemtypes', TCachedTableEntity.Create('itemtypes'));
  Add('roomtypegroups', TCachedTableEntity.Create('roomtypegroups'));
  Add('roomtypes', TCachedTableEntity.Create('roomtypes'));
  Add('channels', TCachedTableEntity.Create('channels'));
  Add('channelmanagers', TCachedTableEntity.Create('channelmanagers'));
  Add('currencies', TCachedTableEntity.Create('currencies'));
  Add('control', TCachedTableEntity.Create('control', ' LIMIT 1'));
  Add('countries', TCachedTableEntity.Create('countries'));
  Add('countrygroups', TCachedTableEntity.Create('countrygroups'));
  Add('customers', TCachedTableEntity.Create('customers'));

  Add('paygroups', TCachedTableEntity.Create('paygroups'));
  Add('paytypes', TCachedTableEntity.Create('paytypes'));
  Add('personprofiles', TCachedTableEntity.Create('personprofiles'));
  Add('bookkeepingcodes', TCachedTableEntity.Create('bookkeepingcodes'));
  Add('tblseasons', TCachedTableEntity.Create('tblseasons'));
  Add('tblpricecodes', TCachedTableEntity.Create('tblpricecodes'));
  Add('customertypes', TCachedTableEntity.Create('customertypes'));

  Add('channelplancodes', TCachedTableEntity.Create('channelplancodes'));
  Add('pms_settings', TCachedTableEntity.Create('pms_settings'));
  Add('tblMaidActions', TCachedTableEntity.Create('tblMaidActions'));
end;

procedure TTableDictionary.RefreshAllLocally(ForceRefresh: Boolean);
var
  lTable : TCachedTableEntity;
begin
  for lTable in Values do
    lTable.RefreshLocally(ForceRefresh);
end;

procedure TTableDictionary.RefreshAllIfNeeded;
var
  lTable : TCachedTableEntity;
begin
  for lTable in Values do
    lTable.RefreshIfNeeded;
end;

{ TTableEntity }

constructor TCachedTableEntity.Create(const tableName : String; const sqlExtension: String = '');
begin
  FSql := format('SELECT * FROM %s %s', [tableName, sqlExtension]);
  FTableName := tableName;
  FRSet := CreateNewDataSet;
  FRSet.CommandType := cmdText;
  FRSet.CommandText := FSql;
  FRefreshEnabled := True;
end;

destructor TCachedTableEntity.Destroy;
begin
  FRSet.Free;
  inherited;
end;

procedure TCachedTableEntity.RefreshFromServer;
begin
  if NOT FRefreshEnabled then
    exit;

  FRSet.Close;
  try
    OutputDebugString(PChar(Format('Refreshing cachedtable [%s] from server', [FTableName])));
    FRSet.Open(true, false, True); // Open(doLowerCase: Boolean = true; setLastAccess: Boolean = true; Threaded: Boolean = False);
    SaveToFile(FRSet.SavedLastResult);
    FRSet.First;
    CachedDataHandler.UpdateLastUpdateOnServer(Self);
  except
    raise ERefreshTableException.CreateFmt('Error while refreshing cachedtable [%s] from server', [FTableName]);
  end;
end;

procedure TCachedTableEntity.RefreshLocally(ForceRefresh : Boolean = true);
var localData : STring;
begin
  if NOT FRefreshEnabled then
    exit;

  if FRSet.Active then FRSet.Close;

  localData := ReadFromFile;
  if ForceRefresh or localData.IsEmpty then
    RefreshFromServer
  else
  try
    FRSet.OpenDataset(localData);
    CachedDataHandler.UpdateLastUpdateOnServer(Self);
  except
    RefreshFromServer;
  end
end;

procedure TCachedTableEntity.SaveToFile(const data : String);
begin
  SaveToTextFile(GetFilename, data);
end;

procedure TCachedTableEntity.SetLastUpdateOnServer(const Value: TDateTime);
begin
  FLastUpdateOnServerUTC := Value;
  RefreshIfNeeded;
end;

function TCachedTableEntity.ReadFromFile : String;
begin
  result := ReadFromTextFile(GetFilename);
end;

function TCachedTableEntity.FileTimeStamp : TDateTime;
begin
  result := GetFileTimeStamp(GetFilename);
end;

function TCachedTableEntity.GetFilename : String;
begin
  Result := TPath.Combine(glb.GetDataCacheLocation, format(cRoomerTableFileName, [FTableName]));
end;

function TCachedTableEntity.IsStale: boolean;
begin
  Result := TTimeZone.Local.ToUniversalTime(FileTimeStamp) < LastUpdateOnServerUTC;
end;

procedure TCachedTableEntity.RefreshIfNeeded;
begin
  if d.roomerMainDataSet.OfflineMode OR (NOT d.roomerMainDataSet.LoggedIn) then
    exit;

  if NOT FileExists(GetFilename) OR IsStale then
    RefreshFromServer;
end;

end.
