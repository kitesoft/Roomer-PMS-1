unit uTableEntityList;

interface

uses
  cmpRoomerDataset
  , Generics.Collections
  , SysUtils
  ;

type

  ERefreshTableException = class(Exception);

  TCachedTableEntity = class;
  TTableDictionary = class;

  ICachedTimestampHandler = interface(IUnknown)
    ['{59C9CAC4-3504-44A7-89B1-7F19A23A7089}']
    function RefreshTimeStampFromServer(aTable: TCachedTableEntity): boolean;
    procedure RefreshTimeStampsFromServer(aTableDict: TTableDictionary);
  end;

  TCachedTableRefreshedEvent = procedure(aTable: TCachedTableEntity) of object;

  TCachedTableEntity = class
  private
    FTableName: String;
    FSql: String;
    FRSet: TRoomerDataSet;
    FRefreshEnabled : Boolean;
    FCacheTimeStampHandler: ICachedTimestampHandler;
    FLastUpdateOnServerUTC: TDateTime;
    FCachedTableRefreshedEvent: TCachedTableRefreshedEvent;
    function GetFilename: String;
    function ReadFromFile: String;
    procedure SaveToFile(const data: String);
    function FileTimeStamp: TDateTime;

    function IsStale: boolean;
    procedure SetLastUpdateOnServer(const Value: TDateTime);
  public
    constructor Create(const tableName : String; aTimestampHandler: ICachedTimestampHandler; const sqlExtension : String = '');
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
    property OnRefresh: TCachedTableRefreshedEvent read FCachedTableRefreshedEvent write FCachedTableRefreshedEvent;
  end;

  TTableDictionary = class(TObjectDictionary<String, TCachedTableEntity>)
  private
    FCachedTimestampHandler: ICachedTimestampHandler;
    function GetTableEntityByName(aName: string): TCachedTableEntity;
    function GetDatasetByName(aName: string): TRoomerDataset;
    procedure InitializeTables;
  public
    constructor Create;
    procedure RefreshAllIfNeeded;
    procedure RefreshAllLocally(ForceRefresh : Boolean = true);
    procedure RefreshTimeStampsFromServer;

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
  FCachedTimestampHandler := TCachedTimeStampHandler.Create;
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

  Add('rooms', TCachedTableEntity.Create('rooms', FCachedTimestampHandler, 'ORDER BY OrderIndex Desc, Room ASC'));

  Add('maintenancecodes', TCachedTableEntity.Create('maintenancecodes', FCachedTimestampHandler));
  Add('maintenanceroomnotes', TCachedTableEntity.Create('maintenanceroomnotes', FCachedTimestampHandler));
  Add('staffmembers', TCachedTableEntity.Create('staffmembers', FCachedTimestampHandler));

  Add('locations', TCachedTableEntity.Create('locations', FCachedTimestampHandler));
  Add('packages', TCachedTableEntity.Create('packages', FCachedTimestampHandler));
  Add('packageitems', TCachedTableEntity.Create('packageitems', FCachedTimestampHandler));
  Add('roomtyperules', TCachedTableEntity.Create('roomtyperules', FCachedTimestampHandler));
  Add('vatcodes', TCachedTableEntity.Create('vatcodes', FCachedTimestampHandler));
  Add('items', TCachedTableEntity.Create('items', FCachedTimestampHandler));
  Add('itemtypes', TCachedTableEntity.Create('itemtypes', FCachedTimestampHandler));
  Add('roomtypegroups', TCachedTableEntity.Create('roomtypegroups', FCachedTimestampHandler));
  Add('roomtypes', TCachedTableEntity.Create('roomtypes', FCachedTimestampHandler));
  Add('channels', TCachedTableEntity.Create('channels', FCachedTimestampHandler));
  Add('channelmanagers', TCachedTableEntity.Create('channelmanagers', FCachedTimestampHandler));
  Add('currencies', TCachedTableEntity.Create('currencies', FCachedTimestampHandler));
  Add('control', TCachedTableEntity.Create('control', FCachedTimestampHandler, ' LIMIT 1'));
  Add('countries', TCachedTableEntity.Create('countries', FCachedTimestampHandler));
  Add('countrygroups', TCachedTableEntity.Create('countrygroups', FCachedTimestampHandler));
  Add('customers', TCachedTableEntity.Create('customers', FCachedTimestampHandler));

  Add('paygroups', TCachedTableEntity.Create('paygroups', FCachedTimestampHandler));
  Add('paytypes', TCachedTableEntity.Create('paytypes', FCachedTimestampHandler));
  Add('personprofiles', TCachedTableEntity.Create('personprofiles', FCachedTimestampHandler));
  Add('bookkeepingcodes', TCachedTableEntity.Create('bookkeepingcodes', FCachedTimestampHandler));
  Add('tblseasons', TCachedTableEntity.Create('tblseasons', FCachedTimestampHandler));
  Add('tblpricecodes', TCachedTableEntity.Create('tblpricecodes', FCachedTimestampHandler));
  Add('customertypes', TCachedTableEntity.Create('customertypes', FCachedTimestampHandler));

  Add('channelplancodes', TCachedTableEntity.Create('channelplancodes', FCachedTimestampHandler));
  Add('pms_settings', TCachedTableEntity.Create('pms_settings', FCachedTimestampHandler));
  Add('tblMaidActions', TCachedTableEntity.Create('tblMaidActions', FCachedTimestampHandler));
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

procedure TTableDictionary.RefreshTimeStampsFromServer;
begin
  FCachedTimestampHandler.RefreshTimeStampsFromServer(Self);
end;
{ TTableEntity }

constructor TCachedTableEntity.Create(const tableName : String; aTimestampHandler: ICachedTimestampHandler; const sqlExtension : String = '');
begin
  FSql := format('SELECT * FROM %s %s', [tableName, sqlExtension]);
  FTableName := tableName;
  FRSet := CreateNewDataSet;
  FRSet.CommandType := cmdText;
  FRSet.CommandText := FSql;
  FRefreshEnabled := True;
  FCacheTimeStampHandler := aTimestampHandler;
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
    FCacheTimeStampHandler.RefreshTimeStampFromServer(Self);
    if assigned(FCachedTableRefreshedEvent) then
      FCachedTableRefreshedEvent(Self);
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
    FCacheTimeStampHandler.RefreshTimeStampFromServer(Self);
    if assigned(FCachedTableRefreshedEvent) then
      FCachedTableRefreshedEvent(Self);
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
