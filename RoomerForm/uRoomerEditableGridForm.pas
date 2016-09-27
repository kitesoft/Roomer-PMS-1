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
  ;

type
  TfrmRoomerEditableGridForm = class(TfrmBaseRoomerGridForm)
    acNew: TAction;
    acEdit: TAction;
    acDelete: TAction;
    acPost: TAction;
    acCancel: TAction;
    btnOther: TsButton;
    dxBarManager: TdxBarManager;
    dxRibbonTab1: TdxRibbonTab;
    dxRibbon: TdxRibbon;
    dxBarPostCancel: TdxBar;
    btnPostRibbon: TdxBarLargeButton;
    bntCancelRibbon: TdxBarLargeButton;
    dxBarLargeButton1: TdxBarLargeButton;
    dxBarLargeButton2: TdxBarLargeButton;
    dxBarLargeButton3: TdxBarLargeButton;
    dxBarLargeButton4: TdxBarLargeButton;
    dxBarLargeButton5: TdxBarLargeButton;
    dxBarLargeButton6: TdxBarLargeButton;
    mnuOther: TPopupMenu;
    mnuiPrint: TMenuItem;
    mnuiAllowGridEdit: TMenuItem;
    N2: TMenuItem;
    Export1: TMenuItem;
    mnuiGridToExcel: TMenuItem;
    mnuiGridToHtml: TMenuItem;
    mnuiGridToText: TMenuItem;
    mnuiGridToXml: TMenuItem;
    procedure acPostExecute(Sender: TObject);
    procedure acEditExecute(Sender: TObject);
    procedure acDeleteExecute(Sender: TObject);
    procedure acCancelExecute(Sender: TObject);
    procedure acPostUpdate(Sender: TObject);
    procedure acNewExecute(Sender: TObject);
    procedure acNewUpdate(Sender: TObject);
    procedure acEditUpdate(Sender: TObject);
    procedure acDeleteUpdate(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

implementation

{$R *.dfm}

procedure TfrmRoomerEditableGridForm.acCancelExecute(Sender: TObject);
begin
  inherited;
  dsGridData.DataSet.Cancel;
end;

procedure TfrmRoomerEditableGridForm.acDeleteExecute(Sender: TObject);
begin
  inherited;
  dsGridData.Dataset.Delete;
end;

procedure TfrmRoomerEditableGridForm.acDeleteUpdate(Sender: TObject);
begin
  inherited;
  acNew.Enabled := dsGridData.Dataset.State = dsBrowse;
end;

procedure TfrmRoomerEditableGridForm.acEditExecute(Sender: TObject);
begin
  inherited;
  dsGridData.Dataset.Edit;
end;

procedure TfrmRoomerEditableGridForm.acEditUpdate(Sender: TObject);
begin
  inherited;
  acEdit.Enabled := dsGridData.Dataset.State = dsBrowse;
end;

procedure TfrmRoomerEditableGridForm.acNewExecute(Sender: TObject);
begin
  inherited;
  dsGridData.DataSet.Insert;
end;

procedure TfrmRoomerEditableGridForm.acNewUpdate(Sender: TObject);
begin
  inherited;
  acNew.Enabled := dsGridData.Dataset.State = dsBrowse;
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

end.
