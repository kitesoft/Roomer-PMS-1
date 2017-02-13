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

  , uRoomerHotelServicesCommunicationModel_RequestsResponses, Data.Bind.DBScope, Data.Bind.Components,
  Data.Bind.ObjectScope, Vcl.Grids, Vcl.DBGrids, Spring.Data.VirtualDataSet, Spring.Data.ObjectDataSet
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
    grActivityLog: TcxGrid;
    grActivityLogDBTableView: TcxGridDBTableView;
    lvActivityLogsLevel: TcxGridLevel;
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
    cbxCategories: TsComboBox;
    odsActivityLogs: TObjectDataSet;
    dsGrid: TDataSource;
    edReservation: TsEdit;
    edRoomreservation: TsEdit;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    procedure FormShow(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure cbxCategoriesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure btnProfileClick(Sender: TObject);
    procedure btnInvoiceClick(Sender: TObject);
  private
    FCatsAndActions: TUserActivityCategoriesOverview;
    FLogEventFragment: TUserActivityLogFragment;
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
  , Spring.Collections
  , Math
  , uActivityLogs
  , uInvoice
  , uReservationProfile
  , TypInfo
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

procedure TfrmUserActivityReport.btnInvoiceClick(Sender: TObject);
var
  lEvent: TUserActivityLogEventType;
begin
  inherited;
  lEvent := odsActivityLogs.GetCurrentModel<TUserActivityLogEventType>;
  EditInvoice(lEvent.Reservation, lEvent.Roomreservation, 0, 0, 0, 0, false);
end;

procedure TfrmUserActivityReport.btnProfileClick(Sender: TObject);
var
  lEvent: TUserActivityLogEventType;
begin
  inherited;
  lEvent := odsActivityLogs.GetCurrentModel<TUserActivityLogEventType>;
  if EditReservation(lEvent.Reservation, lEvent.Roomreservation) then
    RefreshData;

end;

procedure TfrmUserActivityReport.btnRefreshClick(Sender: TObject);
begin
  inherited;
  RefreshData;
end;

procedure TfrmUserActivityReport.cbxCategoriesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  inherited;
  if Key = VK_DELETE then
  begin
    cbxCategories.ItemIndex := -1;
    Key := 0;
  end;
end;

constructor TfrmUserActivityReport.Create(aOwner: TComponent);
var
  iList: IObjectList;
begin
  inherited;
  FCatsAndActions := TUserActivityCategoriesOverview.Create;
  FLogEventFragment := TUserActivityLogFragment.Create;
  if Supports(FLogEventFragment.LogEventList, IObjectList, IList) then
    odsActivityLogs.DataList := iList;
  odsActivityLogs.Open;
end;

destructor TfrmUserActivityReport.Destroy;
begin
  FCatsAndActions.Free;
  FLogEventFragment.Free;
  inherited;
end;

procedure TfrmUserActivityReport.DoLoadData;
var
  lAPi: TUserActivityLogAPICaller;
  lParams: TUserActivityLogAPICaller.TAPICallParameters;
begin
  inherited;
  FLogEventFragment.Clear;
  lApi := TUserActivityLogAPICaller.Create;
  try
    while grActivityLogDBTableView.ColumnCount > 0 do
      grActivityLogDBTableView.Columns[0].Free;

    lParams.DoneAfterDate := dtDateFrom.Date;
    lParams.DoneBeforeDate := dtDateTo.Date;
    lParams.AffectAfterDate := 0;
    lParams.AffectBeforeDate := 0;
    lParams.Category := cbxCategories.Text;
    lParams.Action := '';
    lParams.Reservation := StrToIntDef(edReservation.Text, 0);
    lParams.RoomReservation := StrToIntDef(edRoomreservation.Text, 0);
    lApi.GetLogFragment(lParams, FLogEventFragment);
    odsActivityLogs.First;

    // Update column definitions in view
    grActivityLogDBTableView.DataController.CreateAllItems();

  finally
    lApi.Free;
  end;
end;

procedure TfrmUserActivityReport.DoUpdateControls;
var
  lEvent: TUserActivityLogEventType;
begin
  inherited;
  cbxCategories.Enabled := cbxCategories.Items.Count > 0;

  dtDateTo.Date := min(dtDateFrom.Date, dtDateTo.Date);

  lEvent := odsActivityLogs.GetCurrentModel<TUserActivityLogEventType>;
  if assigned(lEvent) then
  begin
    btnProfile.Enabled := (lEvent.Reservation > 0) or (lEvent.Roomreservation > 0);
    btnInvoice.Enabled := (lEvent.Category.Equals(GetEnumName(TypeInfo(TActivityType), Ord(INVOICE)))
                            and ((lEvent.Reservation > 0) or (lEvent.Roomreservation > 0)));
  end;
end;

procedure TfrmUserActivityReport.FormShow(Sender: TObject);
begin
  inherited;
  dtDateFrom.Date := now;
  dtDateTo.Date := now;
  dtDateTo.MaxDate := now;
  tmTo.Time := now;
  PopulateComboboxes;
end;

end.
