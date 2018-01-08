unit uCachedDataHandler;

interface

uses
  Generics.Collections,
  cmpRoomerDataset
  , uTableEntityList
  ;

type
  /// <summary>
  ///   Handler of timestamp data of cached tables
  /// </summary>
  TCachedTimeStampHandler = class(TInterfacedObject, ICachedTimestampHandler)
  private
    function GetStaticTablesLastUpdates(aRSet: TRoomerDataset; const aTableName: string = ''): boolean;
  public
    function RefreshTimeStampFromServer(aTable: TCachedTableEntity): boolean;
    procedure RefreshTimeStampsFromServer(aTableDict: TTableDictionary);
  end;


implementation

uses
  SysUtils,
  uUtils,
  uD,
  uAppGlobal
  , Data.DB
  ;

function TCachedTimeStampHandler.GetStaticTablesLastUpdates(aRSet: TRoomerDataset; const aTableName: string): boolean;
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

procedure TCachedTimeStampHandler.RefreshTimeStampsFromServer(aTableDict: TTableDictionary);
var lTableRefreshSet : TRoomerDataset;
    lTable: TCachedTableEntity;
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
        if aTableDict.TryGetValue(fldTableName.AsString, lTable) then
          lTable.LastUpdateOnServerUTC := fldLastUpdate.AsDateTime;
        lTableRefreshSet.Next;
      end;
    end;
  finally
    lTableRefreshSet.Free;
  end;
end;

function TCachedTimeStampHandler.RefreshTimeStampFromServer(aTable: TCachedTableEntity): boolean;
var lTableRefreshSet : TRoomerDataset;
begin
  Result := false;
  if d.roomerMainDataSet.OfflineMode then
    exit;
  lTableRefreshSet := CreateNewDataSet;
  try
    lTableRefreshSet.RoomerDataSet := nil;
    if GetStaticTablesLastUpdates(lTableRefreshSet, aTable.TableName) then
    begin
      lTableRefreshSet.First;
      if not lTableRefreshSet.Eof then
      begin
        aTable.LastUpdateOnServerUTC := lTableRefreshSet.FieldByName('lastupdate').AsDateTime;
        Result := true;
      end;
    end;
  finally
    lTableRefreshSet.Free;
  end;
end;


initialization

finalization

end.
