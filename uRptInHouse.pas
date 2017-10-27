unit uRptInHouse;

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
  , uCurrencyHandler, AdvSmoothProgressBar, Vcl.ComCtrls, sStatusBar, cxTextEdit, Vcl.Buttons, sSpeedButton, sEdit  ;

type
  TfrmInHouseReport = class(TfrmBaseRoomerForm)
    kbmInHouseList: TkbmMemTable;
    InHouseListDS: TDataSource;
    pnlFilter: TsPanel;
    btnRefresh: TsButton;
    pnlExportButtons: TsPanel;
    btnExcel: TsButton;
    grInHouseList: TcxGrid;
    lvInHouseListLevel1: TcxGridLevel;
    grInHouseListDBTableView1: TcxGridDBTableView;
    kbmInHouseListfldRoom: TStringField;
    kbmInHouseListfldRoomtype: TStringField;
    kbmInHouseListfldRoomerReservationID: TIntegerField;
    kbmInHouseListfldGuestName: TStringField;
    kbmInHouseListfldCompanyCode: TStringField;
    kbmInHouseListfldArrival: TDateField;
    kbmInHouseListfldDeparture: TDateField;
    kbmInHouseListfldNumGuests: TIntegerField;
    cxStyleRepository1: TcxStyleRepository;
    cxStyle1: TcxStyle;
    kbmInHouseListAverageRoomRate: TFloatField;
    kbmInHouseListExpectedTimeOfDeparture: TStringField;
    btnProfile: TsButton;
    btnInvoice: TsButton;
    pmnuInvoiceMenu: TPopupMenu;
    R1: TMenuItem;
    G1: TMenuItem;
    grInHouseListDBTableView1Room: TcxGridDBColumn;
    grInHouseListDBTableView1Roomtype: TcxGridDBColumn;
    grInHouseListDBTableView1RoomerReservationID: TcxGridDBColumn;
    grInHouseListDBTableView1GuestName: TcxGridDBColumn;
    grInHouseListDBTableView1CompanyCode: TcxGridDBColumn;
    grInHouseListDBTableView1Arrival: TcxGridDBColumn;
    grInHouseListDBTableView1Departure: TcxGridDBColumn;
    grInHouseListDBTableView1NumGuests: TcxGridDBColumn;
    grInHouseListDBTableView1AverageRoomRate: TcxGridDBColumn;
    grInHouseListDBTableView1ExpectedTimeOfDeparture: TcxGridDBColumn;
    kbmInHouseListRoomerRoomReservationID: TIntegerField;
    grInHouseListDBTableView1RoomerRoomReservationID: TcxGridDBColumn;
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
    btnCheckOut: TsButton;
    sPanel1: TsPanel;
    cLabFilter: TsLabel;
    edFilter: TsEdit;
    btnClear: TsSpeedButton;
    timFilter: TTimer;
    procedure rbRadioButtonClick(Sender: TObject);
    procedure btnExcelClick(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure kbmInHouseListAfterScroll(DataSet: TDataSet);
    procedure mnuRoomInvoiceClick(Sender: TObject);
    procedure btnProfileClick(Sender: TObject);
    procedure mnuGroupInvoiceClick(Sender: TObject);
    procedure grInHouseListDBTableView1CellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton;
      AShift: TShiftState; var AHandled: Boolean);
    procedure grInHouseListDBTableView1ExpectedTimeOfDepartureGetDisplayText(Sender: TcxCustomGridTableItem;
      ARecord: TcxCustomGridRecord; var AText: string);
    procedure btnReportClick(Sender: TObject);
    procedure grInHouseListDBTableView1AverageRoomRateGetProperties(Sender: TcxCustomGridTableItem;
      ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
    procedure btnCheckOutClick(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure timFilterTimer(Sender: TObject);
    procedure edFilterChange(Sender: TObject);
  private
    FRefreshingdata: boolean;
    FCurrencyhandler: TCurrencyHandler;
    { Private declarations }
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
function ShowInHouseReport(AutoClick : Boolean = False): boolean;

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
  , ufrmInvoiceEdit;

const
  cSQL = 'SELECT DISTINCT '#10 +
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
          '  rr.ExpectedCheckOutTime as ExpectedTimeOfDeparture '#10 +
          'FROM roomsdate rd '#10 +
          'JOIN roomreservations rr ON rr.RoomReservation=rd.RoomReservation '#10 +
          'JOIN reservations r ON r.Reservation=rd.Reservation '#10 +
          'JOIN persons pe ON pe.RoomReservation=rd.RoomReservation AND pe.MainName=1 '#10 +
          ', control co '#10 +
          'WHERE (rd.ResFlag = ''G'') '#10 +
          'AND rd.ADate IN (''%s'', ''%s'') '#10 +
          'GROUP BY rd.aDate, rd.RoomReservation '#10 +
          'ORDER BY rd.aDate, rd.Room ';

function ShowInHouseReport(AutoClick : Boolean = False): boolean;
var
  frm: TfrmInHouseReport;
begin
  frm := TfrmInHouseReport.Create(nil);
  try
    if AutoClick then
      frm.btnRefresh.Click;
    frm.ShowModal;
    Result := (frm.modalresult = mrOk);
  finally
    frm.Free;
  end;
end;

procedure TfrmInHouseReport.btnCheckOutClick(Sender: TObject);
var
  lStateChangeHandler: TRoomReservationStateChangeHandler;
begin

  lStateChangeHandler := TRoomReservationStateChangeHandler.Create(kbmInHouseList['RoomerReservationID'], kbmInHouseList['RoomerRoomReservationID']);
  try
    if lStateChangeHandler.ChangeState(rsDeparted) then
       Refreshdata;
  finally
    lStateChangeHandler.Free;
  end;
end;

procedure TfrmInHouseReport.btnClearClick(Sender: TObject);
begin
  edFilter.Text := '';
end;


procedure TfrmInHouseReport.edFilterChange(Sender: TObject);
begin
  if edFilter.Text = '' then
  begin
    StopFilter(kbmInHouseList, timFilter, grInHouseListDBTableView1);
  end else
  begin
    applyFilter(kbmInHouseList, edFilter.Text, timFilter, grInHouseListDBTableView1);
  end;
end;

procedure TfrmInHouseReport.btnExcelClick(Sender: TObject);
var
  sFilename : string;
  s         : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_InHouseList';
  ExportGridToExcel(sFilename, grInHouseList, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmInHouseReport.btnProfileClick(Sender: TObject);
begin
  if EditReservation(kbmInHouseList['RoomerReservationID'], kbmInHouseList['RoomerRoomReservationID']) then
    RefreshData;
end;

procedure TfrmInHouseReport.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
end;

procedure TfrmInHouseReport.btnReportClick(Sender: TObject);
var
  lTitle: string;
begin
  lTitle := Format('%s for %s', [Caption, DateTimeToStr(Now)]);
  grdPrinter.PrintTitle := lTitle;
  grdPrinterLink1.ReportTitle.Text := lTitle;
  grdPrinter.Print(True, nil, grdPrinterLink1);
end;

function TfrmInHouseReport.ConstructSQL: string;
begin
  Result := Format(cSQL, [FormatDateTime('yyyy-mm-dd', now), FormatDateTime('yyyy-mm-dd', now-1)]);
  CopyToClipboard(Result);
end;

constructor TfrmInHouseReport.Create(aOwner: TComponent);
begin
  FCurrencyhandler := TCurrencyHandler.Create(g.qNativeCurrency);
  inherited;
end;

destructor TfrmInHouseReport.Destroy;
begin
  inherited;
  FCurrencyhandler.Free;
end;

procedure TfrmInHouseReport.DoShow;
begin
  inherited;
  RefreshData;
end;

procedure TfrmInHouseReport.mnuGroupInvoiceClick(Sender: TObject);
begin
  EditInvoice(kbmInHouseList['RoomerReservationID'], 0, 0, 0, false);
end;

procedure TfrmInHouseReport.grInHouseListDBTableView1AverageRoomRateGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  AProperties := FCurrencyhandler.GetcxEditProperties;
end;

procedure TfrmInHouseReport.grInHouseListDBTableView1CellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
  AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
begin
  btnProfile.Click;
end;

procedure TfrmInHouseReport.grInHouseListDBTableView1ExpectedTimeOfDepartureGetDisplayText(
  Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AText: string);
var
  lTime: TDateTime;
begin
  if not aText.IsEmpty and TryStrToTime(aText, lTime) then
    DateTimeToString(aText, FormatSettings.ShortTimeFormat, StrTodateTime(aText));

end;

procedure TfrmInHouseReport.kbmInHouseListAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmInHouseReport.mnuRoomInvoiceClick(Sender: TObject);
begin
  EditInvoice(kbmInHouseList['RoomerReservationID'], kbmInHouseList['RoomerRoomReservationID'], 0, 0, false);
end;

procedure TfrmInHouseReport.rbRadioButtonClick(Sender: TObject);
begin
  UpdateControls;
end;

procedure TfrmInHouseReport.timFilterTimer(Sender: TObject);
begin
  timFilter.Enabled := False;
  kbmInHouseList.filtered := True;
  grInHouseListDBTableView1.DataController.Filter.Refresh;
end;

procedure TfrmInHouseReport.DoLoadData;
var
  s    : string;
  rset1: TRoomerDataset;
begin
  if NOT btnRefresh.Enabled then exit;

  btnRefresh.Enabled := False;
  Screen.Cursor := crHourglass;
  try

    kbmInHouseList.DisableControls;
    try
      FRefreshingdata := True; // UpdateControls still called when updating dataset, despite DisableControls
      rSet1 := CreateNewDataSet;
      try
        s := ConstructSQL;

        hData.rSet_bySQL(rSet1, s);
        rSet1.First;
        if not kbmInHouseList.Active then
          kbmInHouseList.Open;
        LoadKbmMemtableFromDataSetQuiet(kbmInHouseList,rSet1,[]);
      finally
        FreeAndNil(rSet1);
      end;

      kbmInHouseList.First;

    finally
      FRefreshingdata := False;
      kbmInHouseList.EnableControls;
    end;
  finally
    btnRefresh.Enabled := True;
    Screen.Cursor := crDefault;
  end;
end;

procedure TfrmInHouseReport.DoUpdateControls;
var
  lDataAvailable: boolean;
begin
  if FRefreshingData then
    Exit;

  inherited;

  lDataAvailable := kbmInHouseList.Active and NOT kbmInHouseList.Eof;
  btnCheckOut.Enabled := lDataAvailable;
  btnProfile.Enabled := lDataAvailable;
  btnInvoice.Enabled := lDataAvailable;
end;


end.
