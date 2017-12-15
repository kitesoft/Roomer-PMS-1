unit uCachedDataHandler;

interface

uses
  Generics.Collections,
  cmpRoomerDataset
  ;

type
  TDatePair = class
  public
    LocalFileDate : TDateTime;
    LastUpdateOnServerUTC : TDateTime;
    function IsChanged: boolean;
  end;

  /// <summary>
  ///   Handler of timestamp data of cached tables
  /// </summary>
  TCachedDataHandler = class
  private
    FTableStates : TObjectDictionary<String, TDatePair>;
    function GetTableUpdateTimeStamps(aRSet: TRoomerDataset): boolean;
  public
    constructor Create;
    destructor Destroy; override;

    function TableNeedsRefresh(const TableName : String) : Boolean;
    procedure MarkTableAsRefreshed(const TableName: String); overload;
    procedure MarkTableAsRefreshed(const TableName: String; dt : TDateTime); overload;
    function CurrentTableDate(const TableName: String): TDateTime;
    procedure RefreshTabelStateList;

  end;

function CachedDataHandler: TCachedDataHandler;
procedure ClearCachedDataHandler;

implementation

uses
  SysUtils,
  uUtils,
  uD,
  uAppGlobal,
  DateUtils
  ;

var
  gCachedDataHandler: TCachedDataHandler;

const
  cLastUpdateSuffix = '_lastUpdate';
  cLastUpdateFieldFormat = '%s' + cLastUpdateSuffix;

function CachedDataHandler: TCachedDataHandler;
begin
  if not assigned(gCachedDataHandler) then
    gCachedDataHandler := TCachedDataHandler.Create;

  Result := gCachedDataHandler;
end;

procedure ClearCachedDataHandler;
begin
  FreeAndNil(gCachedDataHandler);
end;
{ TCachedDataHandler }

constructor TCachedDataHandler.Create;
begin
  FTableStates := TObjectDictionary<String, TDatePair>.Create([doOwnsValues], TCaseInsensitiveEqualityComparer.Create);
end;

function TCachedDataHandler.CurrentTableDate(const TableName: String): TDateTime;
var datePair : TDatePair;
    key : String;
begin
  result := 0;
  key := format(cLastUpdateFieldFormat, [TableName]).tolower;
  if FTableStates.TryGetValue(key, datePair) then
    result := datePair.LastUpdateOnServerUTC;
end;

destructor TCachedDataHandler.Destroy;
begin
  FTableStates.Free;
  inherited;
end;

function TCachedDataHandler.GetTableUpdateTimeStamps(aRSet: TRoomerDataset): boolean;
begin
  Result := true;
  try
    if NOT aRSet.OfflineMode then
      aRSet.OpenDatasetFromUrlAsString('messaging/lastchanges', false, 0, '');
  except
    // Ignore ...
    Result := false;
  end;
end;

procedure TCachedDataHandler.MarkTableAsRefreshed(const TableName: String);
var datePair : TDatePair;
    key : String;
begin
  key := format(cLastUpdateFieldFormat, [TableName]);
  if FTableStates.TryGetValue(key, datePair) then
    datePair.LocalFileDate := datePair.LastUpdateOnServerUTC;
end;

procedure TCachedDataHandler.MarkTableAsRefreshed(const TableName: String; dt: TDateTime);
var datePair : TDatePair;
    key : String;
begin
  key := format(cLastUpdateFieldFormat, [TableName]);
  if FTableStates.TryGetValue(key, datePair) then
  begin
    datePair.LocalFileDate := dt;
    datePair.LastUpdateOnServerUTC := dt;
  end;
end;

procedure TCachedDataHandler.RefreshTabelStateList;
var TableRefreshSet : TRoomerDataset;

    i : integer;
    datePair : TDatePair;
    key : String;
    tablename: string;
begin
  if d.roomerMainDataSet.OfflineMode then
    exit;
  TableRefreshSet := CreateNewDataSet;
  try
    TableRefreshSet.RoomerDataSet := nil;
    if GetTableUpdateTimeStamps(TableRefreshSet) then
    begin
      TableRefreshSet.First;
      if not TableRefreshSet.Eof then
      begin
        for i := 0 to TableRefreshSet.Fields.Count - 1 do
        begin
          key := TableRefreshSet.Fields[i].FieldName;
          if FTableStates.TryGetValue(key, datePair) then
            datePair.LastUpdateOnServerUTC := TableRefreshSet.fieldByName(key).AsDateTime
          else
          begin
            datePair := TDatePair.Create;
            try
//              datePair.LocalFileDate := TableRefreshSet.fieldByName(key).AsDateTime;
              tablename := copy(key, 0, key.length -length(cLastUpdateSuffix));
              datePair.LocalFileDate := glb.TableList.TableEntity[tableName].LocalFileDate;
              datePair.LastUpdateOnServerUTC := TableRefreshSet.fieldByName(key).AsDateTime;
              FTableStates.Add(key, datePair);
            except
              datePair.Free;
              raise;
            end;
          end;
        end;
      end;
    end;
  finally
    freeandnil(TableRefreshSet);
  end;
end;

function TCachedDataHandler.TableNeedsRefresh(const TableName: String): Boolean;
var datePair : TDatePair;
    key : String;
begin
  result := true;

  key := format(cLastUpdateFieldFormat, [TableName]);
  if FTableStates.TryGetValue(key, datePair) then
    result := datePair.IsChanged;
end;


{ TDatePair }

function TDatePair.IsChanged: boolean;
begin
  result := TTimeZone.Local.ToUniversalTime(LocalFileDate) <> LastUpdateOnServerUTC;
end;


initialization

finalization
  ClearCachedDataHandler;

end.
