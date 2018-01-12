unit uRoomerGridForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses,
  cxPropertiesStore, Vcl.ComCtrls, sStatusBar, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData,
  Vcl.ExtCtrls, sPanel, cxGridLevel, cxGridCustomView, cxGridCustomTableView, cxGridDBTableView, cxGrid,
  cxGridBandedTableView, cxGridDBBandedTableView
  ,uRoomerForm
  , uRoomerDialogForm, Vcl.StdCtrls, sButton
  , uG, System.Actions, Vcl.ActnList, dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev,
  dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd,
  dxPSPrVwAdv, dxPSPrVwRibbon, dxPScxPageControlProducer, dxPScxGridLayoutViewLnk, dxPScxEditorProducers,
  dxPScxExtEditorProducers, dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, dxPSCore, sLabel, sEdit, sCheckBox,
  Vcl.Buttons, sSpeedButton, Vcl.Menus, dxCore, uRoomerGridExporters
  ;

type

  {$SCOPEDENUMS ON}
  TRoomerGridFormMode = (Browse, SelectSingle {,SelectMultiple});

  /// <summary>
  ///   RoomerDialogForm extended with a Grid with a basic dataview.
  ///   The default view is connected to the global stylesheet and the columnorder and width of all defined views are saved
  ///   in the psRoomerBase properties store.
  ///  Notice that it is only possible for TcxGridDBBandedTableViews to persist the columnorder, columns in a normal TcxGridDBTableView
  ///  do not support this.
  /// </summary>
  TfrmBaseRoomerGridForm = class(TfrmBaseRoomerDialogForm)
    grData: TcxGrid;
    pnlTop: TsPanel;
    dsData: TDataSource;
    tvData: TcxGridDBBandedTableView;
    lvData: TcxGridLevel;
    cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet;
    alGridActions: TActionList;
    acNew: TAction;
    acEdit: TAction;
    acDelete: TAction;
    acPrint: TAction;
    acAllowGridEdit: TAction;
    pnlFilter: TsPanel;
    pnlGridButons: TsPanel;
    btnDelete: TsButton;
    btnOther: TsButton;
    btnInsert: TsButton;
    btnEdit: TsButton;
    grPrinter: TdxComponentPrinter;
    prLink_grData: TdxGridReportLink;
    btnClear: TsSpeedButton;
    chkActive: TsCheckBox;
    edFilter: TsEdit;
    cLabFilter: TsLabel;
    pmnuOther: TPopupMenu;
    Print1: TMenuItem;
    procedure alGridActionsUpdate(Action: TBasicAction; var Handled: Boolean);
    procedure acPrintExecute(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure edFilterChange(Sender: TObject);
    procedure chkActiveClick(Sender: TObject);
    procedure acNewExecute(Sender: TObject);
    procedure acEditExecute(Sender: TObject);
    procedure acDeleteExecute(Sender: TObject);
    procedure tvDataCellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
      AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
    procedure dsDataStateChange(Sender: TObject);
  private
    FFormMode: TRoomerGridFormMode;
    FActiveFieldName: string;
    FCodeFieldName: string;
    FGridExporter: TRoomerGridExporters;
    procedure ApplyFilter;
    function GetSelectedCode: string;
    procedure SetSelectedCode(const Value: string);
  protected
    procedure Loaded; override;
    /// <summary>
    ///   Adds columnindex and width of all columns of all TcxGridDBBandedTableViews in aGrid to the ppRoomerBase propertiesStore.
    ///   This will keep the user defined order and width of columns persistent
    /// </summary>
    procedure AddViewColumnPropsToStore(aGrid: TcxGrid);
    /// <summary>
    ///   Called from the Loaded procedure, sets the default settings of the Grid
    /// </summary>
    procedure InitializeGridProperties; virtual;
    procedure DoShow; override;
    procedure DoClose(var Action: TCloseAction); override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure DoUpdateControls; override;
    property FormMode: TRoomerGridFormMode read FFormMode;
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    { Public declarations }
    function ShowModal(aMode: TRoomerGridFormMode): TModalresult; reintroduce; overload;
    function ShowModal(aMode: TActTableAction): TModalresult; reintroduce; overload; deprecated 'Use TRoomerGridFormMode in stead';

    property CodeFieldName: string read FCodeFieldName write FCodeFieldName;
    /// <summary>
    ///   Name of the boolean field in the dataset that should be used to filter out non-active records
    /// </summary>
    property ActiveFieldName: string read FActiveFieldName write FActiveFieldName;
    /// <summary>
    ///   Identifying code of the currently selected record, can also be set to navigate to that record
    /// </summary>
    property SelectedCode: string read GetSelectedCode write SetSelectedCode;
  end;

implementation

{$R *.dfm}

uses
  PrjConst
  ;

{ TfrmBaseRoomerGridForm }

procedure TfrmBaseRoomerGridForm.Loaded;
begin
  inherited;
  AddViewColumnPropsToStore(grData);
  InitializeGridProperties;
end;

procedure TfrmBaseRoomerGridForm.SetSelectedCode(const Value: string);
begin
  if not FCodeFieldName.IsEmpty then
    dsData.DataSet.Locate(FCodeFieldName, value, [loCaseInsensitive]);
end;

function TfrmBaseRoomerGridForm.ShowModal(aMode: TActTableAction): TModalresult;
begin
  if aMode = actLookup then
    Result := ShowModal(TRoomerGridFormMode.SelectSingle)
  else
    Result := ShowModal(TRoomerGridFormMode.Browse);
end;

function TfrmBaseRoomerGridForm.ShowModal(aMode: TRoomerGridFormMode): TModalresult;
begin
  FFormMode := aMode;
  Result := inherited ShowModal;
end;

procedure TfrmBaseRoomerGridForm.tvDataCellDblClick(Sender: TcxCustomGridTableView;
  ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
begin
  inherited;
  if FFormMode = TRoomerGridFormMode.SelectSingle then
    btnOk.Click;
end;

procedure TfrmBaseRoomerGridForm.alGridActionsUpdate(Action: TBasicAction; var Handled: Boolean);
begin
  inherited;
  acNew.Enabled := FFormMode in [TRoomerGridFormMode.Browse];
  acEdit.Enabled := (FFormMode in [TRoomerGridFormMode.Browse]) and not dsData.DataSet.IsEmpty;
  acDelete.Enabled := (FormMode in [TRoomerGridFormMode.Browse]) and not dsData.DataSet.IsEmpty;
end;

procedure TfrmBaseRoomerGridForm.btnClearClick(Sender: TObject);
begin
  inherited;
  edFilter.Text := '';
end;

procedure TfrmBaseRoomerGridForm.chkActiveClick(Sender: TObject);
begin
  inherited;
  ApplyFilter;
end;

constructor TfrmBaseRoomerGridForm.Create(aOwner: TComponent);
begin
  inherited;
  FGridExporter := TRoomerGridExporters.Create(grData, Caption);
end;

destructor TfrmBaseRoomerGridForm.Destroy;
begin
  FGridExporter.Free;
  inherited;
end;

procedure TfrmBaseRoomerGridForm.DoClose(var Action: TCloseAction);
begin
  if assigned(dsData.DataSet) and (dsData.Dataset.Active) then
    dsData.DataSet.CheckBrowseMode;
  inherited;
end;

procedure TfrmBaseRoomerGridForm.DoShow;
begin
  inherited;
  pmnuOther.Items.Add(FGridExporter.ExportSubMenu);

  if not FCodeFieldName.IsEmpty then
    with tvData.GetColumnByFieldName(FCodeFieldName) do
    begin
      Options.Editing := false;
      SortOrder := soAscending;
    end;

  case FFormMode of
    TRoomerGridFormMode.Browse:       DialogButtons := [mbClose];
    TRoomerGridFormMode.SelectSingle: DialogButtons := mbOKCancel;
  end;

  chkActive.Visible := not FActiveFieldName.IsEmpty;
end;

procedure TfrmBaseRoomerGridForm.DoUpdateControls;
begin
  inherited;

  with tvData.OptionsData do
  begin
    Appending := FFormMode in [TRoomerGridFormMode.Browse];
    Deleting  := FFormMode in [TRoomerGridFormMode.Browse];
    Editing   := FFormMode in [TRoomerGridFormMode.Browse];
    Inserting := FFormMode in [TRoomerGridFormMode.Browse];
  end;

  btnOk.Enabled := tvData.DataController.DataSet.Active and not tvData.DataController.IsEOF;
end;

procedure TfrmBaseRoomerGridForm.dsDataStateChange(Sender: TObject);
begin
  inherited;
  if not FCodeFieldName.IsEmpty then
    tvData.GetColumnByFieldName(FCodeFieldName).Options.Editing := (dsData.State = dsInsert);
end;

procedure TfrmBaseRoomerGridForm.edFilterChange(Sender: TObject);
begin
  ApplyFilter;
end;

function TfrmBaseRoomerGridForm.GetSelectedCode: string;
begin
  if not FCodeFieldName.IsEmpty then
    Result := dsData.DataSet.FieldByName(FCodeFieldName).AsString
  else
    Result := '';
end;

procedure TfrmBaseRoomerGridForm.ApplyFilter;
var
  lText: string;
  i: integer;
begin

  tvData.DataController.Filter.Options := [fcoCaseInsensitive];
  tvData.DataController.Filter.Root.BoolOperatorKind := fboOr;
  tvData.DataController.Filter.Root.Clear;

  if edFilter.Text <> '' then
  begin
    lText := '%' + UpperCase(edFilter.Text) + '%';
    for i := 0 to tvData.ColumnCount -1 do
    begin
      if tvData.Columns[i].Visible then
        tvData.DataController.Filter.Root.AddItem(tvData.Columns[i], foLike, lText, lText);
    end;
  end;
  tvData.DataController.Filter.Active := True;

  if chkActive.Checked and not FActiveFieldName.IsEmpty then
  begin
    dsData.DataSet.Filter := FActiveFieldName + ' = true';
    dsData.dataset.Filtered := true;
  end
  else
    dsData.dataset.Filtered := false;

  UpdateControls;
end;

procedure TfrmBaseRoomerGridForm.InitializeGridProperties;
begin
  tvData.OptionsView.NoDataToDisplayInfoText := GetTranslatedText('shBaseGridForm_NoDataToDisplay');
end;

procedure TfrmBaseRoomerGridForm.KeyDown(var Key: Word; Shift: TShiftState);
begin
  if (Key = VK_ESCAPE) and (dsData.DataSet.State in [dsEdit, dsInsert]) then
    dsData.DataSet.Cancel
  else
    inherited;
end;

procedure TfrmBaseRoomerGridForm.acDeleteExecute(Sender: TObject);
begin
  inherited;
  tvData.Controller.DeleteSelection;
end;

procedure TfrmBaseRoomerGridForm.acEditExecute(Sender: TObject);
begin
  inherited;
  tvData.DataController.Edit;
end;

procedure TfrmBaseRoomerGridForm.acNewExecute(Sender: TObject);
begin
  inherited;
  tvData.DataController.Insert;
end;

procedure TfrmBaseRoomerGridForm.acPrintExecute(Sender: TObject);
begin
  inherited;
  grPrinter.PrintTitle := caption;
  prLink_grData.ReportTitle.Text := caption;
  grPrinter.Preview(true, prLink_grData);
end;

procedure TfrmBaseRoomerGridForm.AddViewColumnPropsToStore(aGrid: TcxGrid);
var
  v: integer;
  c: integer;
  lStoreComp: TcxPropertiesStoreComponent;
begin
  for v := 0 to aGrid.viewCount -1 do
    if aGrid.Views[v] is TcxGridDBBandedTableView then
      with TcxGridDBBandedTableView(aGrid.Views[v]) do
        for c := 0 to ColumnCount-1 do
        begin
          if not psRoomerBase.Components.FindComponentItemByComponent(Columns[c], lStoreComp) then
          begin
            lStoreComp := psRoomerBase.Components.Add;
            lStoreComp.Component := Columns[c];
            lStoreComp.Properties.Add('Position.ColumnIndex');
            lStoreComp.Properties.Add('Width');
          end;
        end;
end;

end.
