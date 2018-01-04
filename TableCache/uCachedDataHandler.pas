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
    function GetStaticTablesLastUpdates(aRSet: TRoomerDataset; const aTableName: string = ''): boolean;
    function UpdateLastUpdateOnServer(const aTableName: string): boolean;
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
  , Data.DB
  ;

var
  gCachedDataHandler: TCachedDataHandler;

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
  RefreshTabelStateList;
end;

function TCachedDataHandler.CurrentTableDate(const TableName: String): TDateTime;
var datePair : TDatePair;
begin
  result := 0;
  if FTableStates.TryGetValue(TableName, datePair) then
    result := datePair.LastUpdateOnServerUTC;
end;

destructor TCachedDataHandler.Destroy;
begin
  FTableStates.Free;
  inherited;
end;

function TCachedDataHandler.GetStaticTablesLastUpdates(aRSet: TRoomerDataset; const aTableName: string): boolean;
var
  url: string;
begin
  Result := false;
  try
    if NOT aRSet.OfflineMode then
    begin
      url := 'messaging/statictableslastupdates';
      if not aTableName.IsEmpty then
        url := url + '/' + aTableName;
      aRSet.OpenDatasetFromUrlAsString(url, false, 0, '');
      Result := true;
    end;
  except
    // Ignore ...
  end;
end;

procedure TCachedDataHandler.MarkTableAsRefreshed(const TableName: String);
var datePair : TDatePair;
begin
  if UpdateLastUpdateOnServer(TableName) and FTableStates.TryGetValue(TableName, datePair) then
    datePair.LocalFileDate := datePair.LastUpdateOnServerUTC;
end;

procedure TCachedDataHandler.MarkTableAsRefreshed(const TableName: String; dt: TDateTime);
var datePair : TDatePair;
begin
  if FTableStates.TryGetValue(TableName, datePair) then
  begin
    datePair.LocalFileDate := dt;
    datePair.LastUpdateOnServerUTC := dt;
  end;
end;

procedure TCachedDataHandler.RefreshTabelStateList;
var lTableRefreshSet : TRoomerDataset;
    lDatePair : TDatePair;
    fldTableName: TField;
    fldLastUpdate: TField;
begin
  if d.roomerMainDataSet.OfflineMode then
    exit;
  lTableRefreshSet := CreateNewDataSet;
  try
    lTableRefreshSet.RoomerDataSet := nil;
    if GetStaticTablesLastUpdates(lTableRefreshSet) then
    begin
      fldTableName := lTableRefreshSet.FieldByName('tablename');
      fldLastUpdate := lTableRefreshSet.FieldByName('lastupdate');

      lTableRefreshSet.First;
      while not lTableRefreshSet.Eof do
      begin
        if FTableStates.TryGetValue(fldTableName.AsString, ldatePair) then
            ldatePair.LastUpdateOnServerUTC := fldLastUpdate.AsDateTime
        else
        begin
          ldatePair := TDatePair.Create;
          try
            ldatePair.LocalFileDate := glb.TableList.TableEntity[fldTableName.AsString].LocalFileDate;
            ldatePair.LastUpdateOnServerUTC := fldLastUpdate.AsDateTime;
            FTableStates.Add(fldTableName.AsString, ldatePair);
          except
            ldatePair.Free;
            raise;
          end;
        end;
        lTableRefreshSet.Next;
      end;
    end;
  finally
    lTableRefreshSet.Free;
  end;
end;

function TCachedDataHandler.TableNeedsRefresh(const TableName: String): Boolean;
var datePair : TDatePair;
begin
  result := true;
  if FTableStates.TryGetValue(TableName, datePair) then
    result := datePair.IsChanged;
end;


function TCachedDataHandler.UpdateLastUpdateOnServer(const aTableName: string): boolean;
var lTableRefreshSet : TRoomerDataset;
    lDatePair : TDatePair;
    fldTableName: TField;
    fldLastUpdate: TField;
begin
  Result := false;
  if d.roomerMainDataSet.OfflineMode then
    exit;
  lTableRefreshSet := CreateNewDataSet;
  try
    lTableRefreshSet.RoomerDataSet := nil;
    if GetStaticTablesLastUpdates(lTableRefreshSet, aTableName) then
    begin
      fldTableName := lTableRefreshSet.FieldByName('tablename');
      fldLastUpdate := lTableRefreshSet.FieldByName('lastupdate');

      lTableRefreshSet.First;
      if not lTableRefreshSet.Eof then
      begin
        if FTableStates.TryGetValue(fldTableName.AsString, ldatePair) then
            ldatePair.LastUpdateOnServerUTC := fldLastUpdate.AsDateTime
        else
        begin
          ldatePair := TDatePair.Create;
          try
            ldatePair.LocalFileDate := glb.TableList.TableEntity[fldTableName.AsString].LocalFileDate;
            ldatePair.LastUpdateOnServerUTC := fldLastUpdate.AsDateTime;
            FTableStates.Add(fldTableName.AsString, ldatePair);
          except
            ldatePair.Free;
            raise;
          end;
        end;
      end;
    end;
  finally
    lTableRefreshSet.Free;
  end;
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
