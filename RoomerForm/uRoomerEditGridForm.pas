unit uRoomerEditGridForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerGridForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  cxStyles, dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxPSGlbl,
  dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns,
  dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, Vcl.Menus, dxPSCore, dxPScxCommon, System.Actions, Vcl.ActnList,
  cxGridBandedTableView, cxGridTableView, cxClasses, cxPropertiesStore, Vcl.StdCtrls, sButton, sEdit, sCheckBox, sLabel,
  Vcl.Buttons, sSpeedButton, Vcl.ExtCtrls, sPanel, cxGridLevel, cxGridCustomView, cxGridCustomTableView,
  cxGridDBBandedTableView, cxGrid, Vcl.ComCtrls, sStatusBar;

type
  /// <summary>
  /// BaseRoomerGridForm extended with editing capabilities
  /// </summary>
  TfrmBaseRoomerEditGridForm = class(TfrmBaseRoomerGridForm)
    pnlGridButons: TsPanel;
    btnDelete: TsButton;
    btnOther: TsButton;
    btnInsert: TsButton;
    btnEdit: TsButton;
    pnlFilter: TsPanel;
    btnClear: TsSpeedButton;
    cLabFilter: TsLabel;
    chkActive: TsCheckBox;
    edFilter: TsEdit;
    acNew: TAction;
    acEdit: TAction;
    acDelete: TAction;
    pmnuOther: TPopupMenu;
    Print1: TMenuItem;
    procedure btnClearClick(Sender: TObject);
    procedure edFilterChange(Sender: TObject);
    procedure chkActiveClick(Sender: TObject);
    procedure acNewExecute(Sender: TObject);
    procedure acEditExecute(Sender: TObject);
    procedure acDeleteExecute(Sender: TObject);
    procedure alGridActionsUpdate(Action: TBasicAction; var Handled: Boolean);
    procedure dsDataStateChange(Sender: TObject);
  private
    FActiveFieldName: string;
    procedure ApplyFilter;
    { Private declarations }
  protected
    procedure DoUpdateControls; override;
    procedure DoShow; override;
  public
    { Public declarations }
    /// <summary>
    ///   Name of the boolean field in the dataset that should be used to filter out non-active records
    /// </summary>
    property ActiveFieldName: string read FActiveFieldName write FActiveFieldName;
  end;


implementation

{$R *.dfm}

procedure TfrmBaseRoomerEditGridForm.btnClearClick(Sender: TObject);
begin
  inherited;
  edFilter.Text := '';
end;

procedure TfrmBaseRoomerEditGridForm.chkActiveClick(Sender: TObject);
begin
  inherited;
  ApplyFilter;
end;

procedure TfrmBaseRoomerEditGridForm.DoShow;
begin
  inherited;
  pmnuOther.Items.Add(GridExporter.ExportSubMenu);
  chkActive.Visible := not FActiveFieldName.IsEmpty;
end;

procedure TfrmBaseRoomerEditGridForm.DoUpdateControls;
begin
  inherited;
  with tvData.OptionsData do
  begin
    Appending := FormMode in [TRoomerGridFormMode.Edit];
    Deleting  := FormMode in [TRoomerGridFormMode.Edit];
    Editing   := FormMode in [TRoomerGridFormMode.Edit];
    Inserting := FormMode in [TRoomerGridFormMode.Edit];
  end;
end;

procedure TfrmBaseRoomerEditGridForm.dsDataStateChange(Sender: TObject);
begin
  inherited;
  if not CodeFieldName.IsEmpty then
    tvData.GetColumnByFieldName(CodeFieldName).Options.Editing := (dsData.State = dsInsert);
end;

procedure TfrmBaseRoomerEditGridForm.edFilterChange(Sender: TObject);
begin
  ApplyFilter;
end;

procedure TfrmBaseRoomerEditGridForm.ApplyFilter;
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

procedure TfrmBaseRoomerEditGridForm.acDeleteExecute(Sender: TObject);
begin
  inherited;
  tvData.Controller.DeleteSelection;
end;

procedure TfrmBaseRoomerEditGridForm.acEditExecute(Sender: TObject);
begin
  inherited;
  tvData.DataController.Edit;
end;

procedure TfrmBaseRoomerEditGridForm.acNewExecute(Sender: TObject);
begin
  inherited;
  tvData.DataController.Insert;
end;


procedure TfrmBaseRoomerEditGridForm.alGridActionsUpdate(Action: TBasicAction; var Handled: Boolean);
begin
  inherited;
  acNew.Enabled := FormMode in [TRoomerGridFormMode.Edit];
  acEdit.Enabled := (FormMode in [TRoomerGridFormMode.Edit]) and HasData;
  acDelete.Enabled := (FormMode in [TRoomerGridFormMode.Edit]) and HasData
end;

end.
