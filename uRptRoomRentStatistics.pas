unit uRptRoomRentStatistics;

interface

uses
    Winapi.Windows
  , Winapi.Messages
  , System.SysUtils
  , System.Variants
  , System.Classes
  , Vcl.Graphics
  , Vcl.Controls
  , Vcl.Forms
  , Vcl.Dialogs
  , Data.DB
  , Vcl.StdCtrls
  , Vcl.Mask
  , shellapi
  , math


  , kbmMemTable
  ,cmpRoomerDataSet
  ,cmpRoomerConnection

  , _glob
  , ug
  , hData
  , uUtils
  , uAppGlobal


  , sMaskEdit
  , sCustomComboEdit
  , sTooledit
  , sButton
  , sComboBox
  , sGroupBox
  , Vcl.ExtCtrls
  , sPanel

  , cxGridExportLink
  , cxGraphics
  , cxControls
  , cxLookAndFeels
  , cxLookAndFeelPainters
  , dxSkinsCore, cxStyles, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin, dxSkinOffice2013White, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, cxDBData, cxCalc, cxCurrencyEdit,
  cxPropertiesStore, AdvChartPaneEditor, VCLTee.TeEngine, VCLTee.Series, VCLTee.TeeProcs, VCLTee.Chart, cxGridLevel, cxGridCustomTableView,
  cxGridTableView, cxGridBandedTableView, cxGridDBBandedTableView, cxClasses, cxGridCustomView, cxGridDBTableView, cxGrid, Vcl.ComCtrls,
  sPageControl, sStatusBar, sCheckBox, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld, dxSkinBlack, dxSkinBlue, dxSkinBlueprint,
  dxSkinDarkRoom, dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast, dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky,
  dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black, dxSkinOffice2007Blue, dxSkinOffice2007Green, dxSkinOffice2007Pink,
  dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue, dxSkinOffice2010Silver, dxSkinPumpkin, dxSkinSeven,
  dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver, dxSkinSpringTime, dxSkinStardust, dxSkinSummer2008, dxSkinValentine,
  dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue, ppDB, ppDBPipe, ppParameter, ppDesignLayer, ppVar, ppBands,
  ppCtrls, ppPrnabl, ppClass, ppCache, ppComm, ppRelatv, ppProd, ppReport

  ;

type
  TfrmRptRoomRentStatistics = class(TForm)
    Panel3: TsPanel;
    cxGroupBox2: TsGroupBox;
    cbxMonth: TsComboBox;
    cbxYear: TsComboBox;
    btnRefresh: TsButton;
    gbxSelectDates: TsGroupBox;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    sStatusBar1: TsStatusBar;
    kbmStat: TkbmMemTable;
    StatDS: TDataSource;
    pageMain: TsPageControl;
    tabStatGrid: TsTabSheet;
    tabGraph: TsTabSheet;
    sPanel1: TsPanel;
    grStat: TcxGrid;
    tvStat: TcxGridDBTableView;
    btnGuestsExcel: TsButton;
    lvStat: TcxGridLevel;
    tvStats: TcxGridDBBandedTableView;
    tvStatsADate: TcxGridDBBandedColumn;
    tvStatssoldRooms: TcxGridDBBandedColumn;
    tvStatsrevenue: TcxGridDBBandedColumn;
    tvStatstotalDiscount: TcxGridDBBandedColumn;
    tvStatsmaxRate: TcxGridDBBandedColumn;
    tvStatsminRate: TcxGridDBBandedColumn;
    tvStatsaverageRate: TcxGridDBBandedColumn;
    tvStatscheckedInToday: TcxGridDBBandedColumn;
    tvStatsarrivingRooms: TcxGridDBBandedColumn;
    tvStatsnoShow: TcxGridDBBandedColumn;
    tvStatsdepartingRooms: TcxGridDBBandedColumn;
    tvStatsdepartedRooms: TcxGridDBBandedColumn;
    tvStatsoccupiedRooms: TcxGridDBBandedColumn;
    tvStatstotalRooms: TcxGridDBBandedColumn;
    tvStatslocalCurrency: TcxGridDBBandedColumn;
    tvStatstotalGuests: TcxGridDBBandedColumn;
    tvStatsocc: TcxGridDBBandedColumn;
    tvStatsadr: TcxGridDBBandedColumn;
    tvStatsrevPar: TcxGridDBBandedColumn;
    chkCompareLasYear: TsCheckBox;
    pageCharts: TsPageControl;
    tabOcc: TsTabSheet;
    sPanel2: TsPanel;
    sButton2: TsButton;
    Chart1: TChart;
    AdvChartPanesEditorDialog1: TAdvChartPanesEditorDialog;
    Series1: TLineSeries;
    FormStore: TcxPropertiesStore;
    kbmStatReport: TkbmMemTable;
    dsStatReport: TDataSource;
    plStats: TppDBPipeline;
    rptStats: TppReport;
    ppHeaderBand1: TppHeaderBand;
    ppLine1: TppLine;
    ppLabel4: TppLabel;
    ppLabel5: TppLabel;
    rlabFrom: TppLabel;
    rLabTo: TppLabel;
    ppLabel6: TppLabel;
    rLabHotelName: TppLabel;
    rlabUser: TppLabel;
    rLabTimeCreated: TppLabel;
    ppLine11: TppLine;
    ppDetailBand1: TppDetailBand;
    ppFooterBand1: TppFooterBand;
    ppSystemVariable1: TppSystemVariable;
    ppLabel8: TppLabel;
    ppLine2: TppLine;
    ppDesignLayers1: TppDesignLayers;
    ppDesignLayer1: TppDesignLayer;
    ppParameterList1: TppParameterList;
    btnReport: TsButton;
    ppLabel1: TppLabel;
    ppDBText1: TppDBText;
    ppLabel2: TppLabel;
    ppDBText2: TppDBText;
    ppLabel3: TppLabel;
    ppDBText3: TppDBText;
    ppLabel7: TppLabel;
    ppDBText4: TppDBText;
    ppLabel9: TppLabel;
    ppDBText5: TppDBText;
    ppLine3: TppLine;
    ppLine4: TppLine;
    ppLabel10: TppLabel;
    ppDBText6: TppDBText;
    ppLabel11: TppLabel;
    ppDBText7: TppDBText;
    ppLabel12: TppLabel;
    ppDBText8: TppDBText;
    ppLabel13: TppLabel;
    ppDBText9: TppDBText;
    ppLabel14: TppLabel;
    ppDBText10: TppDBText;
    ppLabel15: TppLabel;
    ppDBText11: TppDBText;
    ppLine5: TppLine;
    ppLine6: TppLine;
    ppLabel16: TppLabel;
    ppDBText12: TppDBText;
    ppLabel17: TppLabel;
    ppDBText13: TppDBText;
    ppLabel18: TppLabel;
    ppDBText14: TppDBText;
    ppLabel19: TppLabel;
    ppDBText15: TppDBText;
    ppLabel20: TppLabel;
    ppDBText16: TppDBText;
    ppLabel21: TppLabel;
    ppDBText17: TppDBText;
    ppLabel22: TppLabel;
    ppDBText18: TppDBText;
    ppLabel23: TppLabel;
    ppLabel24: TppLabel;
    ppLabel25: TppLabel;
    ppSummaryBand1: TppSummaryBand;
    ppLine7: TppLine;
    ppDBCalc1: TppDBCalc;
    ppDBCalc2: TppDBCalc;
    ppDBCalc3: TppDBCalc;
    ppDBCalc4: TppDBCalc;
    ppDBCalc5: TppDBCalc;
    ppDBCalc6: TppDBCalc;
    ppDBCalc7: TppDBCalc;
    ppDBCalc8: TppDBCalc;
    ppDBCalc9: TppDBCalc;
    ppDBCalc10: TppDBCalc;
    ppDBCalc12: TppDBCalc;
    ppDBCalc13: TppDBCalc;
    ppDBCalc14: TppDBCalc;
    ppDBCalc15: TppDBCalc;
    ppDBCalc16: TppDBCalc;
    ppDBCalc17: TppDBCalc;
    tvStatsooo: TcxGridDBBandedColumn;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure dtDateFromChange(Sender: TObject);
    procedure cbxMonthCloseUp(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure btnGuestsExcelClick(Sender: TObject);
    procedure tvStatsrevenueGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure sButton2Click(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure btnReportClick(Sender: TObject);
  private
    { Private declarations }

    zDateFrom : Tdate;
    zDateTo   : Tdate;
    zYear     : integer;
    zMonth    : integer;
    zSetDates : boolean;


    procedure ShowData;
  public
    { Public declarations }
  end;

function ShowRoomRentStatistics : boolean;

implementation

{$R *.dfm}

uses
  uD,
  uRoomerLanguage,
  uDimages,
  uRoomerDefinitions,
  uReservationStateDefinitions,
  uRptbViewer, uSQLUtils;

function ShowRoomRentStatistics : boolean;
var
  frm: TfrmRptRoomRentStatistics;
begin
  frm := TfrmRptRoomRentStatistics.Create(nil);
  try
    Result := frm.ShowModal = mrOk;
  finally
    frm.Free;
  end;
end;

procedure TfrmRptRoomRentStatistics.ShowData;
var
  y, m, d : word;
  lastDay : integer;
begin
  decodeDate(now, y, m, d);
  zYear := y;
  zMonth := m;
  cbxMonth.ItemIndex := zMonth;

  cbxYear.ItemIndex := cbxYear.Items.IndexOf(inttostr(zYear));

  zDateFrom := encodeDate(y, m, 1);
  lastDay := DaysInMonth(y, m);
  zDateTo := encodeDate(y, m, lastDay);
  dtDateFrom.Date := zDateFrom;
  dtDateTo.Date := zDateTo;
  zSetDates := true;
end;


procedure TfrmRptRoomRentStatistics.tvStatsrevenueGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmRptRoomRentStatistics.btnGuestsExcelClick(Sender: TObject);
var
  sFilename : string;
  s         : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_StatData';
  ExportGridToExcel(sFilename, grStat {grGroupInvoiceSums}, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmRptRoomRentStatistics.btnRefreshClick(Sender: TObject);
var
  s    : string;
  rset1: TRoomerDataset;
  ExecutionPlan : TRoomerExecutionPlan;

begin
  ExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try

  s := 'SELECT id, pd.date '#10+
       '  , DATE(IFNULL(ADate, pd.date)) AS ADate '#10+
       '  , soldRooms as soldRooms '#10+
       '  , revenue '#10+
       '  , occ '#10+
       '  , adr '#10+
       '  , revPar '#10+
       '  , totalDiscount '#10+
       '  , maxRate '#10+
       '  , minRate '#10+
       '  , averageRate '#10 +
       '  , checkedInToday '#10+
       '  , arrivingRooms '#10+
       '  , noShow '#10+
       '  , departingRooms '#10+
       '  , departedRooms '#10+
       '  , occupiedRooms '#10+
       '  , totalRooms - OOORooms as totalRooms '#10+
       '  , OOORooms '#10+
       '  , totalGuests, '#10 +
       '  (SELECT NativeCurrency FROM control LIMIT 1) AS localCurrency '#10 +
       'FROM predefineddates pd '#10 +
       'LEFT OUTER JOIN '#10 +
       ' ( '#10 +
       '	 SELECT baseData1.*, '#10 +
       '     CASE WHEN (totalrooms - OOORooms) <> 0 '#10 +
       '			 THEN soldRooms/(totalRooms - OOORooms)*100 '#10 +
       '       ELSE 0 '#10 +
       '     END AS occ, '#10 +
       '			revenue/soldRooms AS adr, '#10 +
       '     CASE WHEN (totalrooms - OOORooms) <> 0 '#10 +
       '			 THEN revenue/(totalRooms - OOORooms) '#10+
       '       ELSE 0 '#10+
       '     END as RevPar '#10 +
       ' '#10 +
       '	 FROM ( '#10 +
       '		 SELECT DATE(pdd.date) AS ADate, '#10 +
       '				COUNT(rd.id) AS soldRooms, '#10 +
       '				SUM(CASE WHEN rd.paid '#10 +
       '				      -- the invoiced price for one day, negative if creditted '#10 +
       '				      THEN (SELECT sum(price * sign(number)) from invoicelines il where il.invoicenumber > 0 and il.roomreservationalias = rd.roomreservation and il.itemid= c.RoomRentItem) '#10 +
       '				      ELSE IF(rd.Discount > 0, RoomRate - IF(isPercentage, RoomRate * rd.Discount / 100, rd.Discount), RoomRate) * curr.aValue '#10 +
       '				    END) as Revenue, '#10 +
       '				SUM(CASE WHEN rd.paid '#10 +
       '				      -- the invoiced discount for one day, negated if creditted '#10 +
       '				      THEN - (SELECT sum(price * sign(number)) from invoicelines il where il.invoicenumber > 0 and il.roomreservationalias = rd.roomreservation and il.itemid= c.DiscountItem) '#10 +
       '				      ELSE IF(rd.Discount > 0, IF(isPercentage, RoomRate * rd.Discount / 100, rd.Discount), 0) * curr.AValue '#10 +
       '				    END) as TotalDiscount, '#10 +
       '				MAX(RoomRate * curr.AValue) AS maxRate, '#10 +
       '				MIN(RoomRate * curr.AValue) AS minRate, '#10 +
       '				AVG(RoomRate * curr.AValue) AS averageRate, '#10 +
       '				(SELECT COUNT(rd.id) FROM roomsdate rd '#10 +
       '				  LEFT JOIN rooms r on r.room=rd.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '				  WHERE rd.adate=pdd.date AND rd.ResFlag=''G'' and RR_Arrival(rd.roomreservation, false)=pdd.date '#10 +
       '                AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or r.room is not null)) AS checkedInToday, '#10+
       '				(SELECT COUNT(rd.id) FROM roomsdate rd '#10 +
       '				  LEFT JOIN rooms r on r.room=rd.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '				  WHERE rd.adate=pdd.date AND rd.ResFlag=''P'' and RR_Arrival(rd.roomreservation, false)=pdd.date '#10 +
       '                AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or r.room is not null)) AS arrivingRooms, '#10+
       '        (SELECT count(rd.id) from roomsdate rd '#10+
       '					 LEFT JOIN rooms r on r.room=rd.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '           WHERE rd.aDate = pdd.date and rd.ResFlag = ''N'' '#10+
       '                AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or r.room is not null)) as NoShow, '#10+
       '				(SELECT COUNT(rd.id) FROM roomsdate rd '#10 +
       '					LEFT JOIN rooms r on r.room=rd.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '          WHERE rd.aDate = DATE_ADD(pdd.date, INTERVAL -1 DAY) AND rd.ResFlag=''G''and RR_Departure(rd.roomreservation, false) = pdd.date '#10 +
       '                AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or r.room is not null)) AS departingRooms, '#10+
       '				(SELECT COUNT(rd.id) FROM roomsdate rd '#10 +
       '					LEFT JOIN rooms r on r.room=rd.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '          WHERE rd.aDate = DATE_ADD(pdd.date, INTERVAL -1 DAY) AND rd.ResFlag=''D''and RR_Departure(rd.roomreservation, false) = pdd.date '#10 +
       '                AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or r.room is not null)) AS departedRooms, '#10+
       '				(SELECT COUNT(rd2.id) FROM roomsdate rd2 '#10 +
       '					LEFT JOIN rooms r on r.room=rd2.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '					WHERE ADate=pdd.date AND ResFlag=''G'' '#10 +
       '                AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or r.room is not null)) AS occupiedRooms, '#10+
       '				(SELECT COUNT(id) FROM rooms WHERE hidden=0 AND Active=1 AND Statistics=1 AND wildCard=0) AS totalRooms, '#10 +
       '				SUM((SELECT COUNT(id) FROM persons WHERE RoomReservation=rd.RoomReservation)) AS totalGuests, '#10 +
       '				(SELECT COUNT(rd2.room) '#10 +
       '				  FROM roomsdate rd2 '#10 +
       '				  LEFT JOIN rooms rm2 on rm2.room = rd2.room AND rm2.active AND rm2.statistics AND NOT rm2.hidden '#10 +
       '				  JOIN reservations r on r.reservation = rd2.reservation and r.outOfOrderBlocking '#10 +
       '				  where rd2.aDate = rd.aDate'#10 +
       '               AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or rm2.room is not null) '#10+
       '				 ) AS OOORooms '#10 +
       '		 FROM predefineddates pdd '#10 +
       '		 JOIN roomsdate rd on pdd.date=rd.ADate AND (NOT rd.ResFlag IN (''X'',''C'',''O'')) '#10 +
       '		 LEFT JOIN rooms rm on rm.room = rd.room AND rm.active AND rm.statistics AND NOT rm.hidden and rm.wildcard=0  '#10 +
       '		 JOIN reservations r on r.Reservation=rd.Reservation AND r.outOfOrderBlocking=0 '#10 +
       '     JOIN control c '#10 +
       '		 JOIN currencies curr on curr.Currency=rd.Currency '#10 +
       '		 WHERE '#10 +
       '				((pdd.date>=%s AND pdd.date<=%s)) '#10 +
       '		    AND (SUBSTR(rd.room, 1, 1) = ''<'' OR rm.room is not null) '#10 +
       '		 GROUP BY pdd.date '#10 +
       '		 ORDER BY pdd.date '#10 +
       '		 ) baseData1 '#10 +
       '	UNION '#10 +
       '	 SELECT baseData2.*, '#10 +
       '			CAST(0.00 AS DECIMAL) AS occ, '#10 +
       '			CAST(0.00 AS DECIMAL) AS adr, '#10 +
       '			CAST(0.00 AS DECIMAL) AS revPar '#10 +
       '	 FROM ( '#10 +
       '		 SELECT DATE(pdd.date) AS ADate, '#10 +
       '				CAST(0 AS SIGNED) AS soldRooms, '#10 +
       '				CAST(0.00 AS DECIMAL) AS revenue, '#10 +
       '				CAST(0.00 AS DECIMAL) AS totalDiscount, '#10 +
       '				CAST(0.00 AS DECIMAL) AS maxRate, '#10 +
       '				CAST(0.00 AS DECIMAL) AS minRate, '#10 +
       '				CAST(0.00 AS DECIMAL) AS averageRate, '#10 +
       '				CAST(0 AS SIGNED) AS checkedInToday, '#10 +
       '				CAST(0 AS SIGNED) AS arrivingRooms, '#10 +
       '        (SELECT count(rd.id) from roomsdate rd '#10+
       '					 LEFT JOIN rooms r on r.room=rd.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '           WHERE rd.aDate = pdd.date and rd.ResFlag = ''N'' '#10+
       '                AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or r.room is not null)) as NoShow, '#10+
       '				(SELECT COUNT(rd.id) FROM roomsdate rd '#10 +
       '					LEFT JOIN rooms r on r.room=rd.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '          WHERE rd.aDate = DATE_ADD(pdd.date, INTERVAL -1 DAY) AND rd.ResFlag=''G''and RR_Departure(rd.roomreservation, false) = pdd.date '#10+
       '                AND (SUBSTR(rd.room, 1, 1) = ''<'' OR r.room is not null)) AS departingRooms, '#10 +
       '				(SELECT COUNT(rd.id) FROM roomsdate rd '#10 +
       '					JOIN rooms r on r.room=rd.room and r.wildcard=0 and r.active=1 and statistics=1 and hidden=0 '#10 +
       '          WHERE rd.aDate = DATE_ADD(pdd.date, INTERVAL -1 DAY) AND rd.ResFlag=''D''and RR_Departure(rd.roomreservation, false) = pdd.date '#10+
       '                AND (SUBSTR(rd.room, 1, 1) = ''<'' OR r.room is not null)) AS departedRooms, '#10 +
       '				CAST(0 AS SIGNED) AS occupiedRooms, '#10 +
       '				(SELECT COUNT(id) FROM rooms WHERE hidden=0 AND Active=1 AND Statistics=1 AND wildCard=0) AS totalRooms, '#10 +
       '				CAST(0 AS SIGNED) AS totalGuests, '#10 +
       '				CAST(0 AS SIGNED) AS oooRooms '#10 +
       '		 FROM predefineddates pdd '#10 +
       '		 WHERE '#10 +
       '				((pdd.date>=%s AND pdd.date<=%s)) '#10 +
       '		 AND ISNULL((SELECT id FROM roomsdate WHERE ADate=pdd.date AND NOT(ResFlag IN (''X'',''C'')) LIMIT 1)) '#10 +
       '		 GROUP BY pdd.date '#10 +
       '		 ORDER BY pdd.date '#10 +
       '		 ) baseData2 '#10 +
       '	) AllData '#10 +
       ' on DATE(pd.date) = AllData.aDate '#10 +
       ' WHERE '#10 +
       '	((pd.date>=%s AND pd.date<=%s)) '#10 +
       ' ORDER BY date ';

    s := format(s, [_db(zDateFrom,true), _db(zDateTo,true),
                    _db(zDateFrom,true), _db(zDateTo,true),
                    _db(zDateFrom,true), _db(zDateTo,true)]);
    ExecutionPlan.AddQuery(s);
    CopyToClipboard(s);
    //////////////////// Execute!


    screen.Cursor := crHourGlass;
    kbmStat.DisableControls;
    try
      ExecutionPlan.Execute(ptQuery);

      //////////////////// RoomsDate
      rSet1 := ExecutionPlan.Results[0];

      if kbmStat.Active then kbmStat.Close;
      kbmStat.open;
      LoadKbmMemtableFromDataSetQuiet(kbmStat,rSet1,[]);
      kbmStat.First;

    finally
      screen.cursor := crDefault;
      kbmStat.EnableControls;
    end;
  finally
    ExecutionPlan.Free;
  end;



end;

procedure TfrmRptRoomRentStatistics.btnReportClick(Sender: TObject);
begin

  kbmStatReport.LoadFromDataSet(kbmStat, []);

  if frmRptbViewer <> nil then
    freeandNil(frmRptbViewer);
  frmRptbViewer := TfrmRptbViewer.Create(nil);
  try
    screen.Cursor := crHourglass;
    try
      frmRptbViewer.ppViewer1.Reset;
      frmRptbViewer.ppViewer1.Report := rptStats;
      frmRptbViewer.ppViewer1.GotoPage(1);
      rptStats.PrintToDevices;
    finally
      screen.Cursor := crDefault;
    end;

    frmRptbViewer.showmodal;

  finally
    FreeAndNil(frmRptbViewer);
  end;
end;

procedure TfrmRptRoomRentStatistics.cbxMonthCloseUp(Sender: TObject);
var
  y, m : word;
  lastDay : integer;

begin
  if cbxYear.ItemIndex < 1 then
    exit;
  if cbxMonth.ItemIndex < 1 then
    exit;
  zSetDates := false;
  y := StrToInt(cbxYear.Items[cbxYear.ItemIndex]);
//  y := cbxYear.ItemIndex + 2010;
  m := cbxMonth.ItemIndex;

  zDateFrom := encodeDate(y, m, 1);
  lastDay := DaysInMonth(y, m);
  zDateTo := encodeDate(y, m, lastDay);
  dtDateFrom.Date := zDateFrom;
  dtDateTo.Date := zDateTo;
  zSetDates := true;
end;

procedure TfrmRptRoomRentStatistics.dtDateFromChange(Sender: TObject);
begin
  if zSetDates then
  begin
    zDateFrom := dtDateFrom.Date;
    zDateTo := dtDateTo.Date;

    cbxYear.ItemIndex := 0;
    cbxMonth.ItemIndex := 0;
  end;
end;

procedure TfrmRptRoomRentStatistics.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  //**
end;

procedure TfrmRptRoomRentStatistics.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self); PlaceFormOnVisibleMonitor(self);
  glb.fillListWithMonthsLong(cbxMonth.Items, 1);
  glb.fillListWithYears(cbxYear.Items, 1, False);
end;

procedure TfrmRptRoomRentStatistics.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    Close;
end;

procedure TfrmRptRoomRentStatistics.FormShow(Sender: TObject);
begin
  //**
  _restoreForm(self);
  showdata;
end;

procedure TfrmRptRoomRentStatistics.sButton2Click(Sender: TObject);
var
  aValue : integer;
  sDate  : string;
  dtDate : Tdate;

begin
  Chart1.Series[0].Clear;
  kbmStat.DisableControls;
  try
    kbmstat.SortFields := 'ADate';
    kbmstat.Sort([]);
    kbmStat.First;
    while not kbmstat.eof do
    begin
      aValue := kbmStat.FieldByName('occ').AsInteger;
      dtDate := kbmStat.fieldbyname('aDate').asdatetime;
      dateTimeTostring(sDate,'mmm dd',dtDate);
      Chart1.Series[0].Add(aValue,sDate, clBlue);
      kbmStat.Next;
    end;
  finally
    kbmStat.EnableControls;
  end;

end;

end.

