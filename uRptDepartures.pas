unit uRptDepartures;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, kbmMemTable, cxClasses, cxPropertiesStore, Vcl.StdCtrls, sRadioButton,
  acPNG, sLabel, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, sGroupBox, sButton, Vcl.ExtCtrls, sPanel,
  uDImages, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter, cxStyles,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, cxDBData, cxGridLevel,
  cxGridCustomTableView, cxGridTableView, cxGridBandedTableView, cxGridDBBandedTableView, cxGridCustomView, cxGrid,
  dxStatusBar, cxGridDBTableView, Vcl.Grids, Vcl.DBGrids, Vcl.Menus, _glob,
  cxCurrencyEdit, uCurrencyHandler, cxCalendar, cxTimeEdit,
  uRoomerForm, dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns,
  dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, dxPScxCommon, dxPSCore, cxLabel, AdvSmoothProgressBar, Vcl.ComCtrls,
  sStatusBar, cxTextEdit;

type
  TfrmDeparturesReport = class(TfrmBaseRoomerForm)
    kbmDeparturesList: TkbmMemTable;
    DeparturesListDS: TDataSource;
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
    cxStyleRepository1: TcxStyleRepository;
    cxStyle1: TcxStyle;
    btnCheckOut: TsButton;
    btnProfile: TsButton;
    btnInvoice: TsButton;
    pmnuInvoiceMenu: TPopupMenu;
    R1: TMenuItem;
    G1: TMenuItem;
    pnmuGridMenu: TPopupMenu;
    mnuCheckin: TMenuItem;
    mnuProfile: TMenuItem;
    mnuInvoice: TMenuItem;
    mnuRoomInvoice: TMenuItem;
    mnuGroupInvoice: TMenuItem;
    lvDeparturesList: TcxGridLevel;
    grDeparturesList: TcxGrid;
    tvDeparturesList: TcxGridDBTableView;
    tvDeparturesListRoomerReservationId: TcxGridDBColumn;
    tvDeparturesListRoom: TcxGridDBColumn;
    tvDeparturesListRoomType: TcxGridDBColumn;
    tvDeparturesListGuestName: TcxGridDBColumn;
    tvDeparturesListNumGuests: TcxGridDBColumn;
    tvDeparturesListArrival: TcxGridDBColumn;
    tvDeparturesListDeparture: TcxGridDBColumn;
    tvDeparturesListExpectedCheckOutTime: TcxGridDBColumn;
    tvDeparturesListCompanyName: TcxGridDBColumn;
    tvDeparturesListAverageRatePerNight: TcxGridDBColumn;
    tvDeparturesListBalance: TcxGridDBColumn;
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
    btnPrintGrid: TsButton;
    procedure rbRadioButtonClick(Sender: TObject);
    procedure btnExcelClick(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure kbmDeparturesListAfterScroll(DataSet: TDataSet);
    procedure btnCheckOutClick(Sender: TObject);
    procedure mnuRoomInvoiceClick(Sender: TObject);
    procedure btnProfileClick(Sender: TObject);
    procedure mnuGroupInvoiceClick(Sender: TObject);
    procedure grDeparturessListDBTableView1CellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton;
      AShift: TShiftState; var AHandled: Boolean);
    procedure dtDateFromCloseUp(Sender: TObject);
    procedure dtDateToCloseUp(Sender: TObject);
    procedure tvDeparturesList2AverageRatePerNightGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure btnPrintGridClick(Sender: TObject);
    procedure tvDeparturesListExpectedCheckOutTimeGetDisplayText(Sender: TcxCustomGridTableItem;
      ARecord: TcxCustomGridRecord; var AText: string);
  private
    FRefreshingdata: boolean;
    FCurrencyhandler: TCurrencyHandler;
    { Private declarations }
    procedure SetManualDates(aFrom, aTo: TDate);
    function getsql(DateFrom,DateTo : Tdate) : string;
  protected
    procedure DoUpdateControls; override;
    procedure DoLoadData; override;
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;

  end;


/// <summary>
///   Global access point for showing the arrival report form, If Modalresult is OK then True is returned
/// </summary>
function ShowDeparturesReport: boolean;

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
  , uInvoice
  , uReservationProfile
  , uReservationStateDefinitions, uReservationStateChangeHandler, uInvoiceContainer, uSQLUtils;


const

WM_REFRESH_DATA = WM_User + 51;


function TfrmDeparturesReport.getsql(DateFrom,DateTo : Tdate) : string;
var
 s : string;
begin


  s := ' SELECT '#10;

  s := s + ' Room, '#10;
    s := s + ' GuestName, '#10;
    s := s + ' Reservation AS RoomerReservationId, '#10;
    s := s + ' CompanyName, '#10;
    s := s + ' CAST(Arrival AS DATE) AS Arrival, '#10;
    s := s + ' CAST(Departure AS DATE) AS Departure, '#10;
    s := s + ' RoomType, '#10;
    s := s + ' NumGuests, '#10;
    s := s + ' AvrageRate as AverageRatePerNight, '#10;
    s := s + ' TotalRent + TotalSale - TotalPayments AS Balance, '#10;
    s := s + ' ExpectedCheckOutTime, '#10;
    s := s + ' RoomReservation AS RoomerRoomReservationId '#10;
    s := s + ' FROM '#10;
    s := s + '    (SELECT -- zzz '#10;
    s := s + '        yyy.Reservation, '#10;
    s := s + '        yyy.RoomReservation, '#10;
    s := s + '        yyy.Room, '#10;
    s := s + '        yyy.RoomType, '#10;
    s := s + '        pe.Name AS GuestName, '#10;
    s := s + '        cu.Surname AS CompanyName, '#10;
    s := s + '        rr.Arrival , '#10;
    s := s + '        rr.Departure, '#10;
    s := s + '        if (Paid=1, 0, ROUND(SUM(RateWithDiscount + IFNULL(IF(CityTaxIncl, 0, CityTaxPerDay), 0.00)), 2) * CurrencyRate) AS TotalRent, '#10;
    s := s + '        IFNULL((SELECT '#10;
    s := s + '                    SUM(Number * Price) '#10;
    s := s + '                FROM '#10;
    s := s + '                    invoicelines il '#10;
    s := s + '                WHERE '#10;
    s := s + '                    InvoiceNumber = - 1 '#10;
    s := s + '                        AND RoomReservation = yyy.RoomReservation), 0.00) AS TotalSale, '#10;
    s := s + '        IFNULL((SELECT '#10;
    s := s + '                    SUM(Amount) '#10;
    s := s + '                FROM '#10;
    s := s + '                    payments '#10;
    s := s + '                WHERE '#10;
    s := s + '                    InvoiceNumber = - 1 '#10;
    s := s + '                        AND RoomReservation = yyy.RoomReservation), 0.00) AS TotalPayments, '#10;
    s := s + '        yyy.NumGuests, '#10;
    s := s + '        yyy.NumNights, '#10;
    s := s + '        rr.ExpectedCheckOutTime, '#10;
    s := s + '        rr.Avragerate '#10;
    s := s + '    FROM '#10;
    s := s + '        (SELECT  -- yyy '#10;
    s := s + '            CurrencyRate, '#10;
    s := s + '            ResFlag, '#10;
    s := s + '            IF(Discount > 0, IF(isPercentage, RateIncl - (RateIncl * Discount / 100), RateIncl - Discount), RateIncl) AS RateWithDiscount, '#10;
    s := s + '            CityTaxInCl, '#10;
    s := s + '            xxx.NumNights, '#10;
    s := s + '            xxx.NumGuests, '#10;
    s := s + '            IF(CityTaxIncl, 0, '#10;
    s := s + '                -- ---------- city tax per unit ----------------------------- '#10;
    s := s + '                IF(taxPercentage, taxBaseAmount * taxAmount / 100, taxAmount) '#10;
    s := s + '                * '#10;
    s := s + '                --  Unit is:  "room"  or          "#guests nights"                    or   "#guests"                         or   "per booking" '#10;
    s := s + '                IF(taxPerRoomNight, 1,      IF(taxPerGuestNight, xxx.NumGuests, IF(taxPerGuest, xxx.NumGuests / xxx.NumNights, IF(taxPerBooking, 1 / xxx.NumNights, 1))))) / CurrencyRate AS CityTaxPerDay, '#10;
    s := s + '            xxx.RoomReservation, '#10;
    s := s + '            xxx.Reservation, '#10;
    s := s + '            xxx.Room, '#10;
    s := s + '            xxx.RoomType, '#10;
    s := s + '            Paid '#10;
    s := s + '        FROM '#10;
    s := s + '            (SELECT  -- xxx '#10;
    s := s + '                rd.ResFlag, '#10;
    s := s + '                Paid, '#10;
    s := s + '                RoomRate AS RateIncl, '#10;
    s := s + '                RoomRate / (1 + vc.VATPercentage / 100) AS RateExcl, '#10;
    s := s + '                TO_BOOL(IF(tx.INCL_EXCL = ''INCLUDED'' '#10;
    s := s + '                    OR (tx.INCL_EXCL = ''PER_CUSTOMER'' '#10;
    s := s + '                    AND cu.StayTaxIncluted), 1, 0)) AS CityTaxInCl, '#10;
    s := s + '                tx.AMOUNT AS taxAmount, '#10;
    s := s + '                TO_BOOL(IF(tx.TAX_TYPE = ''FIXED_AMOUNT'', 0, 1)) AS taxPercentage, '#10;
    s := s + '                TO_BOOL(IF(tx.TAX_BASE = ''ROOM_NIGHT'', 1, 0)) AS taxPerRoomNight, '#10;
    s := s + '                TO_BOOL(IF(tx.TAX_BASE = ''GUEST_NIGHT'', 1, 0)) AS taxPerGuestNight, '#10;
    s := s + '                TO_BOOL(IF(tx.TAX_BASE = ''GUEST'', 1, 0)) AS taxPerGuest, '#10;
    s := s + '                TO_BOOL(IF(tx.TAX_BASE = ''BOOKING'', 1, 0)) AS taxPerBooking, '#10;
    s := s + '                IF(tx.NETTO_AMOUNT_BASED = ''FALSE'', RoomRate, RoomRate / (1 + vc.VATPercentage / 100)) AS taxBaseAmount, '#10;
    s := s + '                (SELECT '#10;
    s := s + '                        COUNT(rd1.ID) '#10;
    s := s + '                    FROM '#10;
    s := s + '                        roomsdate rd1 '#10;
    s := s + '                    WHERE '#10;
    s := s + '                        rd1.RoomReservation = rr.RoomReservation '#10;
    s := s + '                            AND NOT rd1.ResFlag IN (''X'' , ''C'', ''D'') '#10;
    s := s + '                    GROUP BY rd1.RoomReservation) AS NumNights, '#10;
    s := s + '                (SELECT '#10;
    s := s + '                        COUNT(pe.ID) '#10;
    s := s + '                    FROM '#10;
    s := s + '                        persons pe '#10;
    s := s + '                    WHERE '#10;
    s := s + '                        pe.RoomReservation = rr.RoomReservation '#10;
    s := s + '                    GROUP BY pe.RoomReservation) AS NumGuests, '#10;
    s := s + '                cur.Currency AS Currency, '#10;
    s := s + '                cur.AValue AS CurrencyRate, '#10;
    s := s + '                rd.Discount, '#10;
    s := s + '                rd.isPercentage, '#10;
    s := s + '                rd.RoomReservation, '#10;
    s := s + '                rd.Reservation, '#10;
    s := s + '                rd.Room, '#10;
    s := s + '                rd.RoomType '#10;
    s := s + '            FROM '#10;
    s := s + '                roomsdate rd '#10;
    s := s + '            JOIN currencies cur ON cur.Currency = rd.Currency '#10;
    s := s + '            JOIN roomreservations rr ON rr.RoomReservation = rd.RoomReservation '#10;
    s := s + '            JOIN reservations r ON r.Reservation = rd.Reservation '#10;
    s := s + '            JOIN customers cu ON cu.Customer = r.Customer '#10;
    s := s + '            JOIN control co '#10;
    s := s + '            JOIN home100.TAXES tx ON HOTEL_ID = co.CompanyId '#10;
    s := s + '                AND VALID_FROM <= rd.ADate '#10;
    s := s + '                AND VALID_TO >= rd.ADate '#10;
    s := s + '            JOIN items i ON i.Item = co.RoomRentItem '#10;
    s := s + '            JOIN itemtypes it ON it.ItemType = i.ItemType '#10;
    s := s + '            JOIN vatcodes vc ON vc.VATCode = it.VATCode, '#10;
    s := s + '            (SELECT '+_db(DateFrom, True)+' AS StartDate, '+_db(DateTo, True)+' AS EndDate) AS params '#10;
    s := s + '            WHERE '#10;
    s := s + '                rr.departure between params.Startdate and params.EndDate '#10;
    s := s + '                AND NOT ResFlag IN (''X'' , ''C'', ''D'') '#10;
    s := s + '            ) xxx '#10;
    s := s + '        ) yyy '#10;
    s := s + '    JOIN roomreservations rr ON rr.RoomReservation = yyy.RoomReservation '#10;
    s := s + '    JOIN reservations r ON r.Reservation = yyy.Reservation '#10;
    s := s + '    JOIN customers cu ON cu.Customer = r.Customer AND cu.Active '#10;
    s := s + '    JOIN persons pe ON pe.RoomReservation = yyy.RoomReservation AND pe.MainName = 1 '#10;
    s := s + '    JOIN hotelconfigurations ho '#10;
    s := s + '    GROUP BY yyy.RoomReservation , Departure '#10;
    s := s + '  ) zzz '#10;
    s := s + ' ORDER BY Departure , Room '#10;


  result := s;

end;


function ShowDeparturesReport: boolean;
var
  frm: TfrmDeparturesReport;
begin
  frm := TfrmDeparturesReport.Create(nil);
  try
    frm.ShowModal;
    Result := (frm.modalresult = mrOk);
  finally
    frm.Free;
  end;
end;

procedure TfrmDeparturesReport.btnCheckOutClick(Sender: TObject);
var
  lStateChangeHandler: TRoomReservationStateChangeHandler;
begin

  lStateChangeHandler := TRoomReservationStateChangeHandler.Create(kbmDeparturesList['RoomerReservationID'], kbmDeparturesList['RoomerRoomReservationID']);
  try
    if lStateChangeHandler.ChangeState(rsDeparted) then
       Refreshdata;
  finally
    lStateChangeHandler.Free;
  end;

end;

procedure TfrmDeparturesReport.btnExcelClick(Sender: TObject);
var
  sFilename : string;
  s         : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_DeparturesList';
  ExportGridToExcel(sFilename, grDeparturesList, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmDeparturesReport.btnPrintGridClick(Sender: TObject);
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

procedure TfrmDeparturesReport.btnProfileClick(Sender: TObject);
begin
  if EditReservation(kbmDeparturesList['RoomerReservationID'], kbmDeparturesList['RoomerRoomReservationID']) then
    RefreshData;
end;

procedure TfrmDeparturesReport.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
end;

constructor TfrmDeparturesReport.Create(aOwner: TComponent);
begin
  FCurrencyhandler := TCurrencyHandler.Create(g.qNativeCurrency);
  inherited;
end;

destructor TfrmDeparturesReport.Destroy;
begin
  inherited;
  FCurrencyhandler.Free;
end;

procedure TfrmDeparturesReport.dtDateFromCloseUp(Sender: TObject);
begin
 if dtDateFrom.Date > dtDateTo.Date then
   dtDateTo.Date := dtDateFrom.Date;
end;

procedure TfrmDeparturesReport.dtDateToCloseUp(Sender: TObject);
begin
 if dtDateFrom.Date > dtDateTo.Date then
   dtDateFrom.Date := dtDateTo.Date;
end;

procedure TfrmDeparturesReport.mnuGroupInvoiceClick(Sender: TObject);
begin
  EditInvoice(kbmDeparturesList['RoomerReservationID'], 0, 0, 0, 0, 0, false);
end;

procedure TfrmDeparturesReport.grDeparturessListDBTableView1CellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
  AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
begin
  btnProfile.Click;
end;

procedure TfrmDeparturesReport.kbmDeparturesListAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmDeparturesReport.mnuRoomInvoiceClick(Sender: TObject);
begin
  EditInvoice(kbmDeparturesList['RoomerReservationID'], kbmDeparturesList['RoomerRoomReservationID'], 0, 0, 0, 0, false);
end;

procedure TfrmDeparturesReport.rbRadioButtonClick(Sender: TObject);
begin
  UpdateControls;
end;

procedure TfrmDeparturesReport.DoLoadData;
var
  s    : string;
  rset1: TRoomerDataset;
begin
  inherited;
  if NOT btnRefresh.Enabled then exit;

  btnRefresh.Enabled := False;
  Screen.Cursor := crHourglass;
  try

    kbmDeparturesList.DisableControls;
    try
      FRefreshingdata := True; // UpdateControls still called when updating dataset, despite DisableControls
      rSet1 := CreateNewDataSet;
      try
        s := getsql(dtDateFrom.Date,dtDateTo.Date);
        copyToClipboard(s);

        hData.rSet_bySQL(rSet1, s, false);
        rSet1.First;
        if not kbmDeparturesList.Active then
          kbmDeparturesList.Open;
        LoadKbmMemtableFromDataSetQuiet(kbmDeparturesList,rSet1,[]);

      finally
        FreeAndNil(rSet1);
      end;

      kbmDeparturesList.First;

    finally
      FRefreshingdata := False;
      kbmDeparturesList.EnableControls;
    end;
  finally
    btnRefresh.Enabled := True;
    Screen.Cursor := crDefault;
  end;
end;

procedure TfrmDeparturesReport.SetManualDates(aFrom, aTo: TDate);
begin
  dtDateFrom.Date := aFrom;
  dtDateTo.Date := aTo;
end;

procedure TfrmDeparturesReport.tvDeparturesList2AverageRatePerNightGetProperties(
  Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := FCurrencyhandler.GetcxEditProperties;
end;

procedure TfrmDeparturesReport.tvDeparturesListExpectedCheckOutTimeGetDisplayText(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  inherited;
      //
end;

procedure TfrmDeparturesReport.DoUpdateControls;
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

  lDataAvailable := kbmDeparturesList.Active and NOT kbmDeparturesList.Eof;
  btnCheckOut.Enabled := lDataAvailable;
  btnProfile.Enabled := lDataAvailable;
  btnInvoice.Enabled := lDataAvailable;
end;

end.


