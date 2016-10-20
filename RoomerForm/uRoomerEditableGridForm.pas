unit uRoomerEditableGridForm;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs
  , uRoomerGridForm, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, dxSkinsCore,
  dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter,
  cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxSkinsdxStatusBarPainter,
  dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns,
  dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, System.Actions, Vcl.ActnList, dxPScxCommon, cxClasses, dxPSCore,
  kbmMemTable, cxPropertiesStore, dxStatusBar, cxGridLevel, cxGridCustomView, cxGridCustomTableView, cxGridTableView,
  cxGridDBTableView, cxGrid, Vcl.StdCtrls, sButton, Vcl.ExtCtrls, sPanel, dxRibbonSkins, dxBarDBNav, dxBar, dxRibbon,
  Vcl.Menus
  , uRoomerDetailForm
  , uDImages
  ;

type

  TfrmRoomerEditableGridForm = class(TfrmBaseRoomerGridForm)
    acNew: TAction;
    acEdit: TAction;
    acDelete: TAction;
    acPost: TAction;
    acCancel: TAction;
    mnuOther: TPopupMenu;
    mnuiPrint: TMenuItem;
    mnuiAllowGridEdit: TMenuItem;
    N2: TMenuItem;
    mnuExport: TMenuItem;
    mnuiGridToExcel: TMenuItem;
    mnuiGridToHtml: TMenuItem;
    mnuiGridToText: TMenuItem;
    mnuiGridToXml: TMenuItem;
    btnOther: TsButton;
    btnDelete: TsButton;
    btnEdit: TsButton;
    btnInsert: TsButton;
    btnrefresh: TsButton;
    btnPost: TsButton;
    procedure acPostExecute(Sender: TObject);
    procedure acEditExecute(Sender: TObject);
    procedure acDeleteExecute(Sender: TObject);
    procedure acCancelExecute(Sender: TObject);
    procedure acPostUpdate(Sender: TObject);
    procedure acNewExecute(Sender: TObject);
    procedure acNewUpdate(Sender: TObject);
    procedure acEditUpdate(Sender: TObject);
    procedure acDeleteUpdate(Sender: TObject);
    procedure vwTableViewCellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
      AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
    procedure acCancelUpdate(Sender: TObject);
    procedure kbmGridDataBeforePost(DataSet: TDataSet);
  private
    FAllowGridEdit: boolean;
    procedure SetAllowGridEdit(const Value: boolean);
    function GridIsEditable: boolean;
    { Private declarations }
  protected
    FDetailFormClass: TfrmBaseRoomerDetailFormClass;
    procedure UpdateControls; override;
    function ValidateCurrentData: boolean; virtual;
  public
    { Public declarations }
    /// <summary>
    ///   Allow direct editing of data in grid. If not allowed then a DetailFormClass should be assigned
    //    to allow changing of data
    /// </summary>
    property AllowGridEdit: boolean read FAllowGridEdit write SetAllowGridEdit;
    /// <summary>
    ///   If assigned and AllowGridEdit is False this is the form used to edit and display detail data
    /// </summary>
    property DetailFormClass: TfrmBaseRoomerDetailFormClass read FDetailFormClass;
  end;

implementation

{$R *.dfm}

procedure TfrmRoomerEditableGridForm.acCancelExecute(Sender: TObject);
begin
  inherited;
  dsGridData.DataSet.Cancel;
end;

procedure TfrmRoomerEditableGridForm.acCancelUpdate(Sender: TObject);
begin
  inherited;
  acCancel.Enabled := (dsGridData.Dataset.State in [dsEdit, dsInsert])
end;

procedure TfrmRoomerEditableGridForm.acDeleteExecute(Sender: TObject);
begin
  inherited;
  if FAllowGridEdit then
    dsGridData.Dataset.Delete
  else if TRoomerDetailFormFactory.ShowDetailModal(FDetailFormClass, fmDelete, DataProvider) then
    RefreshData;
end;

procedure TfrmRoomerEditableGridForm.acDeleteUpdate(Sender: TObject);
begin
  inherited;
  acDelete.Enabled := (dsGridData.Dataset.State = dsBrowse) and
                   (FAllowGridEdit or Assigned(FDetailFormClass));
end;

procedure TfrmRoomerEditableGridForm.acEditExecute(Sender: TObject);
begin
  inherited;
  if FAllowGridEdit then
    dsGridData.Dataset.Edit
  else if TRoomerDetailFormFactory.ShowDetailModal(FDetailFormClass, fmEdit, DataProvider) then
    RefreshData;
end;

procedure TfrmRoomerEditableGridForm.acEditUpdate(Sender: TObject);
begin
  inherited;
  acEdit.Enabled := (dsGridData.Dataset.State = dsBrowse)  and
                   (FAllowGridEdit or Assigned(FDetailFormClass));
end;

procedure TfrmRoomerEditableGridForm.acNewExecute(Sender: TObject);
begin
  inherited;
  if FAllowGridEdit then
    dsGridData.DataSet.Insert
  else if TRoomerDetailFormFactory.ShowDetailModal(FDetailFormClass, fmInsert, DataProvider) then
    RefreshData;
end;

procedure TfrmRoomerEditableGridForm.acNewUpdate(Sender: TObject);
begin
  inherited;
  acNew.Enabled := (dsGridData.Dataset.State = dsBrowse) and
                   (FAllowGridEdit or Assigned(FDetailFormClass));
end;

procedure TfrmRoomerEditableGridForm.acPostExecute(Sender: TObject);
begin
  inherited;
  dsGridData.DataSet.Post;
end;

procedure TfrmRoomerEditableGridForm.acPostUpdate(Sender: TObject);
begin
  inherited;
  acPost.Enabled := dsGridData.DataSet.State in [dsEdit, dsInsert];
end;

function TfrmRoomerEditableGridForm.GridIsEditable: boolean;
begin
  Result := FAllowGridEdit and (not assigned(DataProvider) or not DataProvider.IsReadOnly);
end;

procedure TfrmRoomerEditableGridForm.kbmGridDataBeforePost(DataSet: TDataSet);
begin
  inherited;
  if not (Dataset.ControlsDisabled or ValidateCurrentData) then
    Abort;
end;

procedure TfrmRoomerEditableGridForm.SetAllowGridEdit(const Value: boolean);
begin
  FAllowGridEdit := Value;
  UpdateControls;
end;

procedure TfrmRoomerEditableGridForm.UpdateControls;
begin
  inherited;
  with vwTableView.OptionsData do
  begin
    Appending := FAllowGridEdit;
    Deleting := FAllowGridEdit;
    Editing := FAllowGridEdit;
    Inserting := FAllowGridEdit;
  end;
end;

function TfrmRoomerEditableGridForm.ValidateCurrentData: boolean;
begin
  // if no validation needed .. assume everything is correct
  Result := True;
end;

procedure TfrmRoomerEditableGridForm.vwTableViewCellDblClick(Sender: TcxCustomGridTableView;
  ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
begin
  inherited;
  if acEdit.Enabled then
    acEdit.Execute;
end;

end.
