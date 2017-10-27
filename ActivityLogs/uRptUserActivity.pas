unit uRptUserActivity;

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
    pnmuGridMenu: TPopupMenu;
    mnuCheckin: TMenuItem;
    mnuProfile: TMenuItem;
    mnuInvoice: TMenuItem;
    mnuRoomInvoice: TMenuItem;
    mnuGroupInvoice: TMenuItem;
    lblFrom: TsLabel;
    lblTo: TsLabel;
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
    procedure odsActivityLogsAfterScroll(DataSet: TDataSet);
    procedure btnExcelClick(Sender: TObject);
  private
    FCatsAndActions: TUserActivityCategoriesOverview;
    FLogEventFragment: TUserActivityLogFragment;
    procedure PopulateComboboxes;
    function GetCurrentEvent: TUserActivityLogEventType;
    { Private declarations }

    property CurrentEvent: TUserActivityLogEventType read GetCurrentEvent;
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
  , uReservationProfile
  , TypInfo
  , hData
  , uFinishedInvoices2
  , cxGridExportLink
  , uG
  , SHellApi
  , UITypes
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

procedure TfrmUserActivityReport.btnExcelClick(Sender: TObject);
var
  sFilename: string;
  s: string;
begin
  datetimeTostring(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_Log';
  ExportGridToExcel(sFilename, grActivityLog, false, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmUserActivityReport.btnInvoiceClick(Sender: TObject);
var
  lInvNr: integer;
begin
  inherited;
  lInvNr := StrToIntDef(CurrentEvent.Code,0);
  if (lInvNr >0) and InvoiceExists(lInvNr) then
    ViewInvoice2(lInvNr, false, false, false, false, '')
  else
    MessageDlg('No valid invoicenumber in Code column', mtInformation, [mbOk], 0);
end;

procedure TfrmUserActivityReport.btnProfileClick(Sender: TObject);
begin
  inherited;

  if RV_Exists(CurrentEvent.Reservation) then
    if RR_Exists(CurrentEvent.Roomreservation) then
      EditReservation(CurrentEvent.Reservation, CurrentEvent.Roomreservation)
    else
      EditReservation(CurrentEvent.Reservation, 0)
  else
    MessageDlg('No valid reservationnumber in column', mtInformation, [mbOk], 0);
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
  iList: IObjectList;
begin
  inherited;
  FLogEventFragment.Clear;
  lApi := TUserActivityLogAPICaller.Create;
  try
    grActivityLogDBTableView.BeginUpdate(lsimPending);
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

      odsActivityLogs.DisableControls;
      try
        lApi.GetLogFragment(lParams, FLogEventFragment);
        if Supports(FLogEventFragment.LogEventList, IObjectList, IList) then
          odsActivityLogs.DataList := iList;
        odsActivityLogs.First;
      finally
        odsActivityLogs.EnableControls;
      end;

      // Update column definitions in view
      grActivityLogDBTableView.DataController.CreateAllItems();
    finally
      grActivityLogDBTableView.EndUpdate;
    end;

    grActivityLogDBTableView.ApplyBestFit;

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

  dtDateTo.Date := max(dtDateFrom.Date, dtDateTo.Date);

  lEvent := odsActivityLogs.GetCurrentModel<TUserActivityLogEventType>;
  btnProfile.Enabled := assigned(lEvent) and ((lEvent.Reservation > 0) or (lEvent.Roomreservation > 0));
  btnInvoice.Enabled := assigned(lEvent) and (lEvent.Category.Equals(GetEnumName(TypeInfo(TActivityType), Ord(INVOICE)))
                        and ((lEvent.Reservation > 0) or (lEvent.Roomreservation > 0)));
  btnExcel.Enabled := (odsActivityLogs.RecordCount > 0);
end;

procedure TfrmUserActivityReport.FormShow(Sender: TObject);
var
  lOldCursor: TCursor;
begin
  inherited;

  dtDateFrom.Date := now;
  dtDateTo.Date := now;
  dtDateTo.MaxDate := now;
  PopulateComboboxes;
  btnRefresh.Constraints.MaxHeight := 37;

  lOldCursor := Screen.Cursor;
  Screen.Cursor := crHourGlass;
  try
    PushActivityLogs(true);
  finally
    Screen.Cursor := lOldCursor;
  end;
end;

function TfrmUserActivityReport.GetCurrentEvent: TUserActivityLogEventType;
begin
  if odsActivityLogs.Active then
    Result := odsActivityLogs.GetCurrentModel<TUserActivityLogEventType>
  else
    Result := nil;
end;

procedure TfrmUserActivityReport.odsActivityLogsAfterScroll(DataSet: TDataSet);
begin
  inherited;
  if not Dataset.ControlsDisabled then
    UpdateControls;
end;

end.
