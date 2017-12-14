unit uRptArrivals;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, kbmMemTable, cxClasses, cxPropertiesStore, Vcl.StdCtrls, sRadioButton,
  acPNG, sLabel, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, sGroupBox, sButton, Vcl.ExtCtrls, sPanel,
  uDImages, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter, cxStyles,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, cxDBData, cxGridLevel,
  cxGridCustomTableView, cxGridTableView, cxGridBandedTableView, cxGridDBBandedTableView, cxGridCustomView, cxGrid,
  cxGridDBTableView, Vcl.Grids, Vcl.DBGrids, Vcl.Menus, cxTimeEdit, uRoomerForm, dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg,
  dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport,
  cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon, dxPScxPageControlProducer, dxPScxGridLnk,
  dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers, dxSkinsdxBarPainter, dxSkinsdxRibbonPainter,
  dxPScxCommon, dxPSCore, dxStatusBar
  , uCurrencyHandler, AdvSmoothProgressBar, Vcl.ComCtrls, sStatusBar, cxTextEdit, sEdit, Vcl.Buttons, sSpeedButton  ;

type
  TfrmArrivalsReport = class(TfrmBaseRoomerForm)
    kbmArrivalsList: TkbmMemTable;
    ArrivalsListDS: TDataSource;
    pnlFilter: TsPanel;
    btnRefresh: TsButton;
    gbxSelectDates: TsGroupBox;
    rbToday: TsRadioButton;
    rbTomorrow: TsRadioButton;
    rbManualRange: TsRadioButton;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    pnlExportButtons: TsPanel;
    btnExcel: TsButton;
    grArrivalsList: TcxGrid;
    lvArrivalsListLevel1: TcxGridLevel;
    grArrivalsListDBTableView1: TcxGridDBTableView;
    kbmArrivalsListfldRoom: TStringField;
    kbmArrivalsListfldRoomtype: TStringField;
    kbmArrivalsListfldRoomerReservationID: TIntegerField;
    kbmArrivalsListfldGuestName: TStringField;
    kbmArrivalsListfldCompanyCode: TStringField;
    kbmArrivalsListfldArrival: TDateField;
    kbmArrivalsListfldDeparture: TDateField;
    kbmArrivalsListfldNumGuests: TIntegerField;
    cxStyleRepository1: TcxStyleRepository;
    cxStyle1: TcxStyle;
    kbmArrivalsListAverageRoomRate: TFloatField;
    kbmArrivalsListExpectedTimeOfArrival: TStringField;
    btnCheckIn: TsButton;
    btnProfile: TsButton;
    btnInvoice: TsButton;
    pmnuInvoiceMenu: TPopupMenu;
    R1: TMenuItem;
    G1: TMenuItem;
    grArrivalsListDBTableView1Room: TcxGridDBColumn;
    grArrivalsListDBTableView1Roomtype: TcxGridDBColumn;
    grArrivalsListDBTableView1RoomerReservationID: TcxGridDBColumn;
    grArrivalsListDBTableView1GuestName: TcxGridDBColumn;
    grArrivalsListDBTableView1CompanyCode: TcxGridDBColumn;
    grArrivalsListDBTableView1Arrival: TcxGridDBColumn;
    grArrivalsListDBTableView1Departure: TcxGridDBColumn;
    grArrivalsListDBTableView1NumGuests: TcxGridDBColumn;
    grArrivalsListDBTableView1AverageRoomRate: TcxGridDBColumn;
    grArrivalsListDBTableView1ExpectedTimeOfArrival: TcxGridDBColumn;
    kbmArrivalsListRoomerRoomReservationID: TIntegerField;
    grArrivalsListDBTableView1RoomerRoomReservationID: TcxGridDBColumn;
    pnmuGridMenu: TPopupMenu;
    mnuCheckin: TMenuItem;
    mnuProfile: TMenuItem;
    mnuInvoice: TMenuItem;
    mnuRoomInvoice: TMenuItem;
    mnuGroupInvoice: TMenuItem;
    btnReport: TsButton;
    grdPrinter: TdxComponentPrinter;
    grdPrinterLink1: TdxGridReportLink;
    cxStyleRepository2: TcxStyleRepository;
    cxStyle2: TcxStyle;
    cxStyle3: TcxStyle;
    cxStyle4: TcxStyle;
    cxStyle5: TcxStyle;
    cxStyle6: TcxStyle;
    cxStyle7: TcxStyle;
    cxStyle8: TcxStyle;
    cxStyle9: TcxStyle;
    cxStyle10: TcxStyle;
    cxStyle11: TcxStyle;
    cxStyle12: TcxStyle;
    cxStyle13: TcxStyle;
    cxStyle14: TcxStyle;
    dxGridReportLinkStyleSheet1: TdxGridReportLinkStyleSheet;
    sPanel1: TsPanel;
    cLabFilter: TsLabel;
    btnClear: TsSpeedButton;
    edFilter: TsEdit;
    timFilter: TTimer;
    btnAllocateRoom: TsButton;
    procedure rbRadioButtonClick(Sender: TObject);
    procedure btnExcelClick(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure kbmArrivalsListAfterScroll(DataSet: TDataSet);
    procedure btnCheckInClick(Sender: TObject);
    procedure mnuRoomInvoiceClick(Sender: TObject);
    procedure btnProfileClick(Sender: TObject);
    procedure mnuGroupInvoiceClick(Sender: TObject);
    procedure grArrivalsListDBTableView1CellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton;
      AShift: TShiftState; var AHandled: Boolean);
    procedure dtDateFromCloseUp(Sender: TObject);
    procedure dtDateToCloseUp(Sender: TObject);
    procedure grArrivalsListDBTableView1ExpectedTimeOfArrivalGetDisplayText(Sender: TcxCustomGridTableItem;
      ARecord: TcxCustomGridRecord; var AText: string);
    procedure btnReportClick(Sender: TObject);
    procedure grArrivalsListDBTableView1AverageRoomRateGetProperties(Sender: TcxCustomGridTableItem;
      ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
    procedure timFilterTimer(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure edFilterChange(Sender: TObject);
    procedure btnAllocateRoomClick(Sender: TObject);
  private
    FRefreshingdata: boolean;
    FCurrencyhandler: TCurrencyHandler;
    { Private declarations }
    procedure SetManualDates(aFrom, aTo: TDate);
    function ConstructSQL: string;
  protected
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
    procedure DoShow; override;
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    { Public declarations }
  end;


/// <summary>
///   Global access point for showing the arrival report form, If Modalresult is OK then True is returned
/// </summary>
function ShowArrivalsReport(AutoClick : Boolean = False; Tomorrow : Boolean = False): boolean;

implementation

{$R *.dfm}

uses
    uRoomerLanguage
  , uAppGlobal
  , uG
  , uUtils
  , cxGridExportLink
  , ShellApi
  , cmpRoomerDataset
  , uD
  , PrjConst
  , hData
  , uAlerts
  , uProvideARoom2
  , uGuestCheckInForm
  , uReservationProfile
  , uRptbViewer
  , uReservationStateChangeHandler
  , uReservationStateDefinitions
  , uDataSetFilterUtils
  , ufrmInvoiceEdit, uInvoiceDefinitions;

const
  cSQL = 'SELECT '#10 +
          '  co.CompanyID, '#10 +
          '  rd.Room, '#10 +
          '  rd.RoomType, '#10 +
          '  r.Reservation AS RoomerReservationId, '#10 +
          '  rd.RoomReservation AS RoomerRoomReservationId, '#10 +
          '  pe.Name AS GuestName, '#10 +
          '  r.Customer AS CompanyCode, '#10 +
          '  r.Name AS CompanyName, '#10 +
          '  (SELECT AVG(rd1.RoomRate) FROM roomsdate rd1 WHERE rd1.RoomReservation=rr.RoomReservation AND (rd1.ResFlag NOT IN (''X'',''C''))) AS AverageRoomRate, '#10 +
          '  CAST(rr.Arrival AS DATE) as Arrival, '#10 +
          '  CAST(rr.Departure AS DATE) as Departure,   '#10 +
          '  ( SELECT COUNT(id) '#10 +
          '    FROM persons pe1 '#10 +
          '    WHERE pe1.RoomReservation=rd.RoomReservation) AS NumGuests, '#10 +
          '  rr.ExpectedTimeOfArrival as ExpectedTimeOfArrival '#10 +
          'FROM roomsdate rd '#10 +
          'JOIN roomreservations rr ON rr.RoomReservation=rd.RoomReservation '#10 +
          'JOIN reservations r ON r.Reservation=rd.Reservation '#10 +
          'JOIN persons pe ON pe.RoomReservation=rd.RoomReservation AND pe.MainName=1 '#10 +
          ', control co '#10 +
          'WHERE ( SELECT rd1.ADate '#10 +
          '        FROM roomsdate rd1 '#10 +
          '        WHERE rd1.RoomReservation=rd.RoomReservation AND (rd1.ResFlag = ''P'') '#10 +
          '        ORDER BY rd1.ADate LIMIT 1)=rd.ADate '#10 +
          '      AND (rd.ResFlag = ''P'') '#10 +
          '      %s '#10 +
          'GROUP BY rd.aDate, rd.RoomReservation '#10 +
          'ORDER BY rd.aDate, rd.Room ';

  cSqlForSingleDate = '      AND rd.ADate = ''%s'' ';
  cSqlForDateRange = '      AND rd.ADate >= ''%s'' AND rd.ADate <= ''%s'' ';


function ShowArrivalsReport(AutoClick : Boolean = False; Tomorrow : Boolean = False): boolean;
var
  frm: TfrmArrivalsReport;
begin
  frm := TfrmArrivalsReport.Create(nil);
  try
    if Tomorrow then
    begin
      frm.rbTomorrow.Checked := True;
      frm.UpdateControls;
    end;
    if AutoClick then
      frm.btnRefresh.Click;
    frm.ShowModal;
    Result := (frm.modalresult = mrOk);
  finally
    frm.Free;
  end;
end;

procedure TfrmArrivalsReport.btnAllocateRoomClick(Sender: TObject);
begin
  inherited;
  if ProvideARoom2(kbmArrivalsListRoomerRoomReservationID.AsInteger) <> '' then
    RefreshData;
end;

procedure TfrmArrivalsReport.btnCheckInClick(Sender: TObject);
var
  lStateChangeHandler: TRoomReservationStateChangeHandler;
begin

  lStateChangeHandler := TRoomReservationStateChangeHandler.Create(kbmArrivalsList['RoomerReservationID'], kbmArrivalsList['RoomerRoomReservationID']);
  try
    if lStateChangeHandler.ChangeState(rsGuests) then
       RefreshData;
  finally
    lStateChangeHandler.Free;
  end;

end;

procedure TfrmArrivalsReport.btnClearClick(Sender: TObject);
begin
  edFilter.Text := '';
end;

procedure TfrmArrivalsReport.btnExcelClick(Sender: TObject);
var
  sFilename : string;
  s         : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_ArrivalsList';
  ExportGridToExcel(sFilename, grArrivalsList, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmArrivalsReport.btnProfileClick(Sender: TObject);
begin
  if EditReservation(kbmArrivalsList['RoomerReservationID'], kbmArrivalsList['RoomerRoomReservationID']) then
    RefreshData;
end;

procedure TfrmArrivalsReport.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
end;

procedure TfrmArrivalsReport.btnReportClick(Sender: TObject);
var
  lTitle: string;
begin
  if dtDateFrom.Date = dtDateTo.Date then
    lTitle := Format('%s for %s', [Caption, dtDateFrom.Text])
  else
    lTitle := Format('%s from %s until %s', [Caption, dtDateFrom.Text, dtDateTo.text]);
  grdPrinter.PrintTitle := lTitle;
  grdPrinterLink1.ReportTitle.Text := lTitle;
  grdPrinter.Print(True, nil, grdPrinterLink1);
end;

function TfrmArrivalsReport.ConstructSQL: string;
var s : String;
begin
  if rbToday.Checked OR rbTomorrow.Checked then
    s := Format(cSqlForSingleDate, [FormatDateTime('yyyy-mm-dd', dtDateFrom.Date)])
  else
    s := Format(cSqlForDateRange, [FormatDateTime('yyyy-mm-dd', dtDateFrom.Date),
                                   FormatDateTime('yyyy-mm-dd', dtDateTo.Date)]);
  Result := Format(cSQL, [s]);
  CopyToClipboard(Result);
end;

constructor TfrmArrivalsReport.Create(aOwner: TComponent);
begin
  FCurrencyhandler := TCurrencyHandler.Create(g.qNativeCurrency);
  inherited;
end;

destructor TfrmArrivalsReport.Destroy;
begin
  inherited;
  FCurrencyhandler.Free;
end;

procedure TfrmArrivalsReport.DoShow;
begin
  inherited;
  RefreshData;
end;

procedure TfrmArrivalsReport.dtDateFromCloseUp(Sender: TObject);
begin
 if dtDateFrom.Date > dtDateTo.Date then
   dtDateTo.Date := dtDateFrom.Date;
end;

procedure TfrmArrivalsReport.dtDateToCloseUp(Sender: TObject);
begin
 if dtDateFrom.Date > dtDateTo.Date then
   dtDateFrom.Date := dtDateTo.Date;
end;

procedure TfrmArrivalsReport.edFilterChange(Sender: TObject);
begin
  if edFilter.Text = '' then
  begin
    StopFilter(kbmArrivalsList, timFilter, grArrivalsListDBTableView1);
  end else
  begin
    applyFilter(kbmArrivalsList, edFilter.Text, timFilter, grArrivalsListDBTableView1);
  end;
end;

procedure TfrmArrivalsReport.mnuGroupInvoiceClick(Sender: TObject);
begin
  EditInvoice(kbmArrivalsList['RoomerReservationID'], 0, TInvoiceType.itDebitInvoice, 0, false);
end;

procedure TfrmArrivalsReport.grArrivalsListDBTableView1AverageRoomRateGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  AProperties := FCurrencyhandler.GetcxEditProperties;
end;

procedure TfrmArrivalsReport.grArrivalsListDBTableView1CellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
  AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
begin
  btnProfile.Click;
end;

procedure TfrmArrivalsReport.grArrivalsListDBTableView1ExpectedTimeOfArrivalGetDisplayText(
  Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AText: string);
var
  lTime: TDateTime;
begin
  if not aText.IsEmpty and TryStrToTime(aText, lTime) then
    DateTimeToString(aText, FormatSettings.ShortTimeFormat, StrTodateTime(aText));

end;

procedure TfrmArrivalsReport.kbmArrivalsListAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmArrivalsReport.mnuRoomInvoiceClick(Sender: TObject);
begin
  EditInvoice(kbmArrivalsList['RoomerReservationID'], kbmArrivalsList['RoomerRoomReservationID'], TInvoiceType.itDebitInvoice, 0, false);
end;

procedure TfrmArrivalsReport.rbRadioButtonClick(Sender: TObject);
begin
  UpdateControls;
end;

procedure TfrmArrivalsReport.DoLoadData;
var
  s    : string;
  rset1: TRoomerDataset;
begin
  if NOT btnRefresh.Enabled then exit;

  btnRefresh.Enabled := False;
  Screen.Cursor := crHourglass;
  try

    kbmArrivalsList.DisableControls;
    try
      FRefreshingdata := True; // UpdateControls still called when updating dataset, despite DisableControls
      rSet1 := CreateNewDataSet;
      try
        s := ConstructSQL;

        hData.rSet_bySQL(rSet1, s);
        rSet1.First;
        if not kbmArrivalsList.Active then
          kbmArrivalsList.Open;
        LoadKbmMemtableFromDataSetQuiet(kbmArrivalsList,rSet1,[]);
      finally
        FreeAndNil(rSet1);
      end;

      kbmArrivalsList.First;

    finally
      FRefreshingdata := False;
      kbmArrivalsList.EnableControls;
    end;
  finally
    btnRefresh.Enabled := True;
    Screen.Cursor := crDefault;
  end;
end;

procedure TfrmArrivalsReport.SetManualDates(aFrom, aTo: TDate);
begin
  dtDateFrom.Date := aFrom;
  dtDateTo.Date := aTo;
end;

procedure TfrmArrivalsReport.timFilterTimer(Sender: TObject);
begin
  timFilter.Enabled := False;
  kbmArrivalsList.filtered := True;
  grArrivalsListDBTableView1.DataController.Filter.Refresh;
end;

procedure TfrmArrivalsReport.DoUpdateControls;
var
  lDataAvailable: boolean;
begin
  if FRefreshingData then
    Exit;

  inherited;

  dtDateFrom.Enabled := rbManualRange.Checked;
  dtDateTo.Enabled := rbManualRange.Checked;

  if rbToday.Checked then
    SetManualDates(Now, now)
  else if rbTomorrow.Checked then
    SetManualDates(Now+1, Now+1);

  lDataAvailable := kbmArrivalsList.Active and NOT kbmArrivalsList.Eof;
  btnCheckIn.Enabled := lDataAvailable;
  btnProfile.Enabled := lDataAvailable;
  btnInvoice.Enabled := lDataAvailable;
  btnAllocateRoom.Enabled := lDataAvailable;
  btnExcel.Enabled := lDataAvailable;
end;


end.
