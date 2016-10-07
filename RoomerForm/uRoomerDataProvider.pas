unit uRoomerDataProvider;

interface

uses
    cmpRoomerDataset
  , SysUtils
  , kbmMemTable
  ;

type

  ERoomerDataProviderException = class(Exception);

  /// <summary>
  ///   Base and abstract class that provides the data for a RoomerForm. <br />
  ///  Contains methods to populate different memorybased datasets with the resulting data stored in a
  ///  TRoomerDataset
  /// </summary>
  TRoomerDataProvider = class abstract(TObject)
  protected
    /// <summary>
    ///   Return a roomerdataset with updated data <br />
    ///  Note that the caller of this function is not responsible for the destruction of this TRoomerdataset!
    /// </summary>
    function GetData: TRoomerDataset; virtual; abstract;
    function GetIsReadOnly: boolean; virtual; abstract;
  public
    procedure LoadDataIntoKbmMemTable(aKbmTable: TkbmMemTable);
    function ContainsData: boolean;  virtual; abstract;
    property IsReadOnly: boolean read GetIsReadOnly;
  end;

  TRoomerDataProviderClass = class of TROomerDataProvider;

  /// <summary>
  ///   Implementation of TRoomerDataProvider that gets its data from an SQL statement
  /// </summary>
  TRoomerSQLDataProvider = class(TROomerDataProvider)
  private
    FRoomerDataset: TRoomerDataset;
  protected
    function GetData: TRoomerDataset; override;
    function ConstructSQLStatement: string; virtual;
    function GetIsReadOnly: boolean; override;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    function ContainsData: boolean; override;
  end;

  /// <summary>
  ///   Implementation of TRoomerDataProvider that gets its data from a base table stored in AppGlobal object
  /// </summary>
  TRoomerBaseTableDataProvider = class(TRoomerDataProvider)
  private
    FBaseTableName: string;
    procedure SetBaseTableName(const Value: string);
  protected
    function GetData: TRoomerDataset; override;
    function GetIsReadOnly: boolean; override;
  public
    function ContainsData: boolean; override;
    property BaseTableName: string read FBaseTableName write SetBaseTableName;
  end;

implementation

uses
    hData
  , uD
  , uAppGlobal
  , VCL.Controls
  , VCL.Forms
  , uUtils
  ;



function TRoomerSQLDataProvider.ContainsData: boolean;
begin
  Result := FRoomerDataset.RecordCount > 0;
end;

constructor TRoomerSQLDataProvider.Create;
begin
  FRoomerDataset := CreateNewDataset;
end;

destructor TRoomerSQLDataProvider.Destroy;
begin
  FRoomerDataset.Free;
  inherited;
end;

function TRoomerSQLDataProvider.GetIsReadOnly: boolean;
begin
  Result := True;
end;

procedure TRoomerDataProvider.LoadDataIntoKbmMemTable(aKbmTable: TkbmMemTable);
var
  lSaveCursor: TCursor;
begin

  lSaveCursor := Screen.Cursor;

  try
    Screen.Cursor := crHourGlass;
    if not aKbmTable.Active then
      aKbmTable.Open;
    aKbmTable.DisableControls;
    try
      akbmTable.EmptyTable;
      LoadKbmMemtableFromDataSetQuiet(aKbmTable, GetData, []);
    finally
      akbmTable.EnableControls;
    end;

  finally
    Screen.Cursor := lSaveCursor;
  end;

end;
{ TRoomerSQLDataProvider }

function TRoomerSQLDataProvider.ConstructSQLStatement: string;
begin
  // if not overridden then no data is delivered
  Result := 'SELECT ''<NO SQL SPECIFIED>'' as Result';
end;


{ TRoomerBaseTableDataProvider }

function TRoomerBaseTableDataProvider.GetIsReadOnly: boolean;
begin
  Result := False;
end;

function TRoomerBaseTableDataProvider.ContainsData: boolean;
begin
  Result := GetData.RecordCount > 0;
end;

function TRoomerBaseTableDataProvider.GetData: TRoomerDataset;
begin
  inherited;
  glb.RefreshTableIfNeeded(FBaseTableName);
  Result := glb.GetDataSetFromDictionary(FBaseTableName);
end;

procedure TRoomerBaseTableDataProvider.SetBaseTableName(const Value: string);
begin
  if assigned(glb.TableEntityByTableName(Value)) then
    FBaseTableName := Value
  else
    raise ERoomerDataProviderException.CreateFmt('Base table [%s] not found in dictionary', [Value]);
end;

function TRoomerSQLDataProvider.GetData: TRoomerDataset;
begin
  inherited;
  hData.rSet_bySQL(FRoomerDataset, ConstructSQLStatement, false);
  FRoomerDataset.First;
  Result := FRoomerDataset;
end;

end.
