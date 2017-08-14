unit uGridColumnFieldValuePropagator;

interface

uses
  Data.DB
  , cxGridDBBandedTableView
  ;

type
  TPropagateDirection = (pdDown, pdUp, pdAll);

  TGridColumnFieldValuePropagator = class(TObject)
  private
  public
    /// <summary>
    ///   Copies the value of aField in the current record to other records until end of table (BOF or EOF depending on aDirection)
    ///  Notice that the current order of the records and active index is important!
    /// </summary>
    procedure Propagate(aField: TField; aDirection: TPropagateDirection); overload;

    /// <summary>
    ///   Copies the value in aColumn in the current row of the grid to other records until end of grid (BOF or EOF depending on aDirection)
    ///  Notice that the current order of the rows is important!
    /// </summary>
    procedure Propagate(aColumn: TcxGridDBBandedColumn; aDirection: TPropagateDirection); overload;

  end;

implementation

uses
  cxGridDBDataDefinitions
  ;

{ TFieldValuePropagator }

procedure TGridColumnFieldValuePropagator.Propagate(aField: TField; aDirection: TPropagateDirection);
var
  ds: TDataset;
  bm: TBookmark;
  lBuffer: TArray<Byte>;
begin

  ds := aField.DataSet;
  if not ds.Active then
    Exit;

  if aField.isBlob then // to be implemented, using BlobStream
    Exit;

  ds.CheckBrowseMode;

  bm := ds.Bookmark;
  ds.DisableControls;
  try
    SetLength(lBuffer, aField.DataSize);
    aField.GetData(lBuffer);
    if aDirection = pdAll then
      ds.First;

    while not (ds.Bof or ds.Eof) do
    begin
      try
        ds.Edit;
        aField.SetData(lBuffer);
        ds.Post;
      except
        ds.Cancel;
        raise;
      end;
      if aDirection = pdUp then
        ds.Prior
      else
        ds.Next;
    end;

  finally
    bm := ds.Bookmark;
    ds.EnableControls
  end;

end;

procedure TGridColumnFieldValuePropagator.Propagate(aColumn: TcxGridDBBandedColumn; aDirection: TPropagateDirection);
var
  dc: TcxGridDBDataController;
  ds: TDataset;
  fld: TField;
  bm: TBookmark;
  lFirst, lLast: integer;
  i: integer;
  lBuffer: TArray<Byte>;
begin
  dc := aColumn.DataBinding.DataController;
  ds := dc.DataSet;

  Assert(dc.DataModeController.SyncMode, 'Datacontroler not synced with dataset');
  Assert(dc.KeyFieldNames<>'', 'Syncmode not enabled because there is no keyfield specified');

  bm := ds.Bookmark;
  dc.BeginFullUpdate;
  ds.DisableControls;
  try

    case aDirection of
      pdDown: begin
                lFirst := dc.FocusedRowIndex + 1;
                lLast := dc.RowCount;
              end;
      pdUp:   begin
                lFirst := 0;
                lLast := dc.FocusedRowIndex -1;
              end;
      pdAll:  begin
                lFirst := 0;
                lLast := dc.RowCount;
              end;
    else
      Exit;
    end;

    fld := aColumn.DataBinding.Field;
    if fld.isBlob then // to be implemented, using BlobStream
      Exit;

    SetLength(lBuffer, fld.DataSize);
    fld.GetData(lBuffer);

    for i := lFirst to lLast do
    begin
      dc.FocusedRowIndex := i;
      ds.Edit;
      try
        fld.SetData(lBuffer);
        ds.Post;
      except
        ds.Cancel;
        raise;
      end;
    end;

  finally
    ds.Bookmark := bm;
    ds.EnableControls;
    dc.EndFullUpdate;
  end;
end;

end.
