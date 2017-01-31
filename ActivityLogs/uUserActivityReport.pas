unit uUserActivityReport;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, uRoomerForm, cxGridTableView, cxStyles, dxPScxCommon, dxPScxGridLnk, cxClasses,
  cxPropertiesStore, Vcl.ComCtrls, sStatusBar, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters,
  dxSkinsCore, dxSkinCaramel, dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, dxPSGlbl,
  dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns,
  dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, Vcl.StdCtrls, sEdit, sSpinEdit, sLabel, Vcl.Menus, dxPSCore, cxGridLevel,
  cxGridCustomView, cxGridCustomTableView, cxGridDBTableView, cxGrid, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit,
  sGroupBox, sButton, Vcl.ExtCtrls, sPanel, sComboBox

  , uRoomerHotelServicesCommunicationModel_RequestsResponses
  ;

type
  TfrmUserActivityReport = class(TfrmBaseRoomerForm)
    pnlFilter: TsPanel;
    btnRefresh: TsButton;
    gbxSelectDates: TsGroupBox;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    pnlExportButtons: TsPanel;
    btnExcel: TsButton;
    btnProfile: TsButton;
    btnInvoice: TsButton;
    btnReport: TsButton;
    grArrivalsList: TcxGrid;
    grArrivalsListDBTableView1: TcxGridDBTableView;
    lvArrivalsListLevel1: TcxGridLevel;
    grdPrinter: TdxComponentPrinter;
    grdPrinterLink1: TdxGridReportLink;
    pmnuInvoiceMenu: TPopupMenu;
    R1: TMenuItem;
    G1: TMenuItem;
    pnmuGridMenu: TPopupMenu;
    mnuCheckin: TMenuItem;
    mnuProfile: TMenuItem;
    mnuInvoice: TMenuItem;
    mnuRoomInvoice: TMenuItem;
    mnuGroupInvoice: TMenuItem;
    lblFrom: TsLabel;
    lblTo: TsLabel;
    tmFrom: TsTimePicker;
    tmTo: TsTimePicker;
    gbxRestrictions: TsGroupBox;
    lblCategory: TsLabel;
    lbAction: TsLabel;
    cbxCategories: TsComboBox;
    cbxActions: TsComboBox;
    procedure FormShow(Sender: TObject);
  private
    FCatsAndActions: TUserActivityCategoriesOverview;
    procedure PopulateComboboxes;
    { Private declarations }

  protected
    procedure DoUpdateControls; override;
    procedure DoLoadData; override;
  public
    { Public declarations }
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
  end;

procedure ShowUserActivityReport;

implementation

uses
  uHotelServicesAPICaller
  ;

{$R *.dfm}

procedure ShowUserActivityReport;
begin
  with TfrmUserActivityReport.Create(nil) do
  try
    ShowModal;
  finally
    Free;
  end;
end;

procedure TfrmUserActivityReport.PopulateComboboxes;
var
  lAPi: TUserActivityLogAPICaller;
begin
  cbxCategories.Clear;
  lApi := TUserActivityLogAPICaller.Create;
  try
    lApi.GetAllCategoriesAndActionsForHotel(FCatsAndActions);
  finally
    lApi.Free;
  end;

  FCatsAndActions.AddCategoryNamesAsString(cbxCategories.Items);
  cbxCategories.ItemIndex := -1;
end;

constructor TfrmUserActivityReport.Create(aOwner: TComponent);
begin
  inherited;
  FCatsAndActions := TUserActivityCategoriesOverview.Create;
end;

destructor TfrmUserActivityReport.Destroy;
begin
  FCatsAndActions.Free;
  inherited;
end;

procedure TfrmUserActivityReport.DoLoadData;
begin
  inherited;

end;

procedure TfrmUserActivityReport.DoUpdateControls;
begin
  inherited;
  cbxCategories.Enabled := cbxCategories.Items.Count > 0;
  cbxActions.Enabled := (cbxCategories.ItemIndex <> -1);
end;

procedure TfrmUserActivityReport.FormShow(Sender: TObject);
begin
  inherited;

  PopulateComboboxes;
end;

end.
