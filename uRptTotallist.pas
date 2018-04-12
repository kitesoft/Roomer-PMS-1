unit uRptTotallist;

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


  , kbmMemTable
  ,cmpRoomerDataSet
  ,cmpRoomerConnection

  , _glob
  , ug
  , hData
  , uUtils
  , uappGlobal


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
  , dxSkinsCore
  , cxStyles
  , dxSkinscxPCPainter
  , cxCustomData
  , cxFilter
  , cxData
  , cxDataStorage
  , cxEdit
  , cxNavigator
  , cxDBData
  , cxGridLevel
  , cxClasses
  , cxGridCustomView
  , cxGridCustomTableView
  , cxGridTableView
  , cxGridDBTableView
  , cxGrid
  , dxStatusBar
  , cxGridBandedTableView
  , cxGridDBBandedTableView

  , dxSkinMcSkin, dxSkinOffice2013White, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter, dxSkinDarkSide, dxSkinDevExpressDarkStyle,
  cxPropertiesStore, sLabel, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld, dxSkinBlack, dxSkinBlue, dxSkinBlueprint, dxSkinDarkRoom,
  dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast, dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky,
  dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black, dxSkinOffice2007Blue, dxSkinOffice2007Green, dxSkinOffice2007Pink,
  dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue, dxSkinOffice2010Silver, dxSkinPumpkin, dxSkinSeven,
  dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver, dxSkinSpringTime, dxSkinStardust, dxSkinSummer2008, dxSkinValentine,
  dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue
  , uRoomerForm, dxPScxCommon, dxPScxGridLnk, AdvSmoothProgressBar, Vcl.ComCtrls, sStatusBar, cxCalc;



type
    // See https://promoir.atlassian.net/wiki/x/B4BEB for an explanation of the different states

  TfrmRptTotallist = class(TfrmBaseRoomerForm)
    Panel3: TsPanel;
    cxGroupBox2: TsGroupBox;
    cbxMonth: TsComboBox;
    cbxYear: TsComboBox;
    btnRefresh: TsButton;
    gbxSelectDates: TsGroupBox;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    Panel5: TsPanel;
    btnExcel: TsButton;
    grTotallist: TcxGrid;
    kbmTotallist: TkbmMemTable;
    TotallistDS: TDataSource;
    lvTotallistLevel1: TcxGridLevel;
    lvTotallist: TcxGridDBBandedTableView;
    lvTotallistdtDate: TcxGridDBBandedColumn;
    lvTotallistWeekNr: TcxGridDBBandedColumn;
    lvTotallistroomsArrival: TcxGridDBBandedColumn;
    lvTotallistpaxArrival: TcxGridDBBandedColumn;
    lvTotallistroomsInhouse: TcxGridDBBandedColumn;
    lvTotallistpaxInhouse: TcxGridDBBandedColumn;
    lvTotallistroomsDeparture: TcxGridDBBandedColumn;
    lvTotallistpaxDeparture: TcxGridDBBandedColumn;
    lvTotallistroomsStayOver: TcxGridDBBandedColumn;
    lvTotallistpaxStayOver: TcxGridDBBandedColumn;
    lvTotallistroomsWaitinglist: TcxGridDBBandedColumn;
    lvTotallistpaxWaitinglist: TcxGridDBBandedColumn;
    lvTotallistRoomsAllotment: TcxGridDBBandedColumn;
    lvTotallistpaxAllotment: TcxGridDBBandedColumn;
    lvTotallistroomsTotal: TcxGridDBBandedColumn;
    lvTotallistpaxTotal: TcxGridDBBandedColumn;
    lvTotallistroomsBlocked: TcxGridDBBandedColumn;
    lvTotallistpaxBlocked: TcxGridDBBandedColumn;
    lvTotallistroomsOutOfOrder: TcxGridDBBandedColumn;
    lvTotallistpaxOutOfOrder: TcxGridDBBandedColumn;
    FormStore: TcxPropertiesStore;
    labLocationsList: TsLabel;
    labLocations: TsLabel;
    lvTotallistroomsWaitinglistNonOptional: TcxGridDBBandedColumn;
    lvTotallistpaxWaitinglistNonOptional: TcxGridDBBandedColumn;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure dtDateFromChange(Sender: TObject);
    procedure cbxMonthCloseUp(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure btnExcelClick(Sender: TObject);
    procedure lvTotallistHideZeroValue(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure lvTotallistWeekNrGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
  private
    { Private declarations }

    zDateFrom : Tdate;
    zDateTo   : Tdate;
    zYear     : integer;
    zMonth    : integer;
    zSetDates : boolean;

    zLocationInString : string;

//    function LocationInString : string;
    procedure ShowData;
    procedure SetColumnGroupHeaders;
  protected
    procedure DoLoadData; override;
    procedure DoShow; override;
  public
    { Public declarations }
  end;

function rptTotalList : boolean;

var
  frmRptTotallist: TfrmRptTotallist;

implementation

{$R *.dfm}

uses
    uD
  , uRoomerLanguage
  , uDImages
  , uRoomerDefinitions
  , uMain, uReservationStateDefinitions
  , DateUtils
  , uSQLUtils, PrjConst
  , uDateTimeHelper
  ;


function rptTotalList : boolean;
begin
  frmRptTotallist := TfrmRptTotallist.Create(nil);
  try
    frmRptTotallist.ShowModal;
    Result := (frmRptTotallist.modalresult = mrOk);
  finally
    freeandnil(frmRptTotallist);
  end;
end;


procedure TfrmRptTotallist.SetColumnGroupHeaders;
begin
  lvTotallist.Bands[0].Caption := GetTranslatedText('shTX_TotalListheaderDates');
  lvTotallist.Bands[1].Caption := GetTranslatedText('shTX_TotalListheaderTotal');
  lvTotallist.Bands[2].Caption := GetTranslatedText('shTX_TotalListheaderArrival');
  lvTotallist.Bands[3].Caption := GetTranslatedText('shTX_TotalListheaderInhouse');
  lvTotallist.Bands[4].Caption := GetTranslatedText('shTX_TotalListheaderDeparture');
  lvTotallist.Bands[5].Caption := GetTranslatedText('shTX_TotalListheaderStayOver');
  lvTotallist.Bands[6].Caption := GetTranslatedText('shTX_TotalListheaderOptionalBooking');
  lvTotallist.Bands[7].Caption := GetTranslatedText('shTX_TotalListheaderAllotments');
  lvTotallist.Bands[8].Caption := GetTranslatedText('shTX_TotalListheaderBlocked');
  lvTotallist.Bands[9].Caption := GetTranslatedText('shTX_TotalListheaderOutOfOrder');
  lvTotallist.Bands[10].Caption := GetTranslatedText('shTX_TotalListheaderWaitingList');
  lvTotallist.Bands[11].Caption := GetTranslatedText('shTX_TotalListheaderNoShow');

end;

procedure TfrmRptTotallist.ShowData;
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
  lastDay := DaysInaMonth(y, m);
  zDateTo := encodeDate(y, m, lastDay);
  dtDateFrom.Date := zDateFrom;
  dtDateTo.Date := zDateTo;
  zSetDates := true;
end;


procedure TfrmRptTotallist.btnExcelClick(Sender: TObject);
var
  sFilename : string;
  s         : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_Totallist';
  ExportGridToExcel(sFilename, grTotallist {grGroupInvoiceSums}, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmRptTotallist.DoLoadData;
var
  lExecutionPlan: TRoomerExecutionPlan;
  rSet1: TRoomerDataSet;
  lList: TSet_Of_Integer;
  lLocationClause: string;
  s: string;

const
  cAllReservations: TReservationStateSet = [rsReservation, rsGuests, rsDeparted, rsWaitingList, rsTmp1, rsAllotment, rsBlocked, rsAwaitingPayment, rsAwaitingPayConfirm];
  cArrivalReservations: TReservationStateSet = [rsReservation, rsGuests, rsDeparted, rsTmp1, rsAwaitingPayment, rsAwaitingPayConfirm];
  cDepartureReservations: TReservationStateSet = [rsReservation, rsGuests, rsDeparted, rsTmp1, rsAwaitingPayment, rsAwaitingPayConfirm];
  cInhouseReservations: TReservationStateSet = [rsReservation, rsGuests, rsDeparted, rsTmp1, rsAwaitingPayment, rsAwaitingPayConfirm];
  cStayOverReservations: TReservationStateSet = [rsReservation, rsGuests, rsDeparted, rsTmp1, rsAwaitingPayment, rsAwaitingPayConfirm];

begin
  inherited;

  lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try

    // See https://promoir.atlassian.net/wiki/x/B4BEB for an explanation of the different states
    // See https://promoir.atlassian.net/wiki/spaces/RP1/pages/71598087/Explanation+of+columns+in+TotalList

{$REGION 'SQL statement'}
    lList := frmMain.FilteredLocations;
    try
      lLocationClause := glb.LocationSQLInString(lList, true);
    finally
      lList.Free;
    end;

      s := '   SELECT '#10 +
           '         date as dtDate '#10 +
           '       , SUM(IF(PREV_DAY IS NULL AND RES_FLAG IS NOT NULL AND not outoforderblocking, 1, 0)) AS roomsArrival '#10 +
           '       , SUM(IF(PREV_DAY IS NULL AND RES_FLAG IS NOT NULL AND not outoforderblocking, numGuests, 0)) AS paxArrival '#10 +
           '       , SUM(IF(PREV_DAY IS NOT NULL AND RES_FLAG IS NULL, 1, 0)) AS roomsDeparture '#10 +
           '       , SUM(IF(PREV_DAY IS NOT NULL AND RES_FLAG IS NULL, numGuests, 0)) AS paxDeparture '#10 +
           '   --    , SUM(IF(PREV_DAY = ''G'' OR RES_FLAG = ''G'', 1, 0)) AS roomsInHouse -- Roomrent stats method '#10 +
           '   --    , SUM(IF(PREV_DAY = ''G'' OR RES_FLAG = ''G'', numGuests, 0)) AS paxInHouse -- Roomrent stats method '#10 +
           '       , SUM(IF(RES_FLAG IN (''P'',''G'',''D'',''W'',''Z'',''Q''), 1, 0)) AS roomsInHouse -- Totallist method '#10 +
           '       , SUM(IF(RES_FLAG IN (''P'',''G'',''D'',''W'',''Z'',''Q''), numGuests, 0)) AS paxInHouse -- TotalList method '#10 +
           '       , SUM(IF(RES_FLAG IN (''P'',''G'',''D'',''W'',''Z'',''Q'') AND PREV_DAY IN (''P'',''G'',''D'',''W'',''Z'',''Q''), 1, 0)) AS roomsStayOver '#10 +
           '       , SUM(IF(RES_FLAG IN (''P'',''G'',''D'',''W'',''Z'',''Q'') AND PREV_DAY IN (''P'',''G'',''D'',''W'',''Z'',''Q''), numGuests, 0)) AS paxStayOver '#10 +
           '       , SUM(IF(RES_FLAG IN (''O''), 1, 0)) AS roomsWaitingList '#10 +
           '       , SUM(IF(RES_FLAG IN (''O''), numGuests, 0)) AS paxWaitingList '#10 +
           '       , SUM(IF(RES_FLAG IN (''L''), 1, 0)) AS roomsWaitinglistNonOptional '#10 +
           '       , SUM(IF(RES_FLAG IN (''L''), numGuests, 0)) AS paxWaitinglistNonOptional '#10 +
           '       , SUM(IF(RES_FLAG IN (''A''), 1, 0)) AS roomsAllotment '#10 +
           '       , SUM(IF(RES_FLAG IN (''A''), numGuests, 0)) AS paxAllotment '#10 +
           '       , SUM(IF(RES_FLAG IN (''N''), 1, 0)) AS roomsNoShow '#10 +
           '       , SUM(IF(RES_FLAG IN (''N''), numGuests, 0)) AS paxNoShow '#10 +
           '       , SUM(IF(RES_FLAG IN (''B'') AND not outOfOrderBlocking, 1, 0)) AS roomsBlocked '#10 +
           '       , SUM(IF(RES_FLAG IN (''B'') AND not outOfOrderBlocking, numGuests, 0)) AS paxBlocked '#10 +
           '       , SUM(IF(outOfOrderBlocking, 1, 0)) AS roomsOutOfOrder '#10 +
           '       , SUM(IF(outOfOrderBlocking, numGuests, 0)) AS paxOutOfOrder '#10 +
           '       , SUM(IF(RES_FLAG IN (''P'',''G'',''D'',''W'',''Z'',''Q'',''L'',''A'',''N'', ''B'') and not outOfOrderBlocking, 1, 0)) AS roomsTotal  -- totallist method '#10 +
           '       , SUM(IF(RES_FLAG IN (''P'',''G'',''D'',''W'',''Z'',''Q'',''L'',''A'', ''N'', ''B'') and not outOfOrderBlocking, numGuests, 0)) AS paxTotal -- totallist method '#10 +
           '   FROM '#10 +
           '       ( '#10 +
           '           SELECT date '#10 +
           '           FROM predefineddates '#10 +
           '       ) base '#10 +
           '       LEFT JOIN ( '#10 +
           '           SELECT -- TMP_RD_STATS '#10 +
           '               rd.ADate AS rdDate, '#10 +
           '               rd.ResFlag AS RES_FLAG, '#10 +
           '               r.outoforderblocking, '#10 +
           '               (SELECT rd0.ResFlag '#10 +
           '                FROM roomsdate rd0 '#10 +
           '                WHERE rd0.RoomReservation = rd.RoomReservation '#10 +
           '                      AND rd0.ADate = DATE_ADD(rd.ADate, INTERVAL - 1 DAY) AND rd0.ResFlag NOT IN (''X'', ''C'')) AS PREV_DAY, '#10 +
           '               (SELECT count(person) from persons p where p.roomreservation=rd.roomreservation) as numGuests '#10 +
           '           FROM roomsdate rd '#10 +
           '           JOIN reservations r on r.reservation=rd.reservation '#10 +
           '           LEFT JOIN rooms rm2 on (rm2.room = rd.room AND rm2.active AND rm2.statistics AND NOT rm2.hidden and not rm2.wildcard AND rm2.location in (%s)) '#10 +
           '           WHERE %s <= rd.ADate AND rd.ADate <= %s '#10 +
           '           AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or rm2.room is not null) '#10 +
           '           AND rd.ResFlag NOT IN (''X'', ''C'') '#10 +
           ' '#10 +
           '           UNION ALL '#10 +
           ' '#10 +
           '           SELECT -- Add reservations from "yesterday" that are leaving or have left "today" '#10 +
           '               CAST(rd.ADate AS date) + INTERVAL 1 DAY AS rdDate, '#10 +
           '               NULL AS RES_FLAG, '#10 +
           '               false, '#10 +
           '               rd.ResFlag AS PREV_DAY '#10 +
           '               ,(SELECT count(person) from persons p where p.roomreservation=rd.roomreservation) as numGuests '#10 +
           '           FROM roomsdate rd '#10 +
           '           LEFT JOIN rooms rm2 on (rm2.room = rd.room AND rm2.active AND rm2.statistics AND NOT rm2.hidden and not rm2.wildcard AND rm2.location in (%s)) '#10 +
           '           WHERE %s - INTERVAL 1 DAY <= rd.ADate AND rd.ADate <= %s - INTERVAL 1 DAY '#10 +
           '           AND (SUBSTRING(rd.Room, 1, 1) = ''<'' or rm2.room is not null) '#10 +
           '           AND rd.ResFlag NOT IN (''X'', ''C'') '#10 +
           '           AND NOT EXISTS(SELECT rd0.ResFlag FROM roomsdate rd0 WHERE rd0.RoomReservation = rd.RoomReservation AND rd0.ADate = DATE_ADD(rd.ADate, INTERVAL 1 DAY) AND rd0.ResFlag NOT IN (''X'', ''C'')) '#10 +
           '       ) AS _TMP_RD_STATS ON (_TMP_RD_STATS.rdDate = base.date) '#10 +
           '   WHERE %s <= base.date AND base.date <= %s '#10 +
           '   GROUP BY dtDate '#10 +
           '   ORDER by dtDate '#10;

    s := format(s, [lLocationClause,  _db(zDateFrom, true), _db(zDateTo, true), lLocationClause, _db(zDateFrom, true), _db(zDateTo, true), _db(zDateFrom, true), _db(zDateTo, true)]);

{$ENDREGION}

    CopyToClipboard(s);
    lExecutionPlan.AddQuery(s);


    screen.Cursor := crHourGlass;
    kbmTotallist.DisableControls;
    try
      lExecutionPlan.Execute(ptQuery);

      rSet1 := lExecutionPlan.Results[0];

      if kbmTotallist.Active then kbmTotallist.Close;
      kbmTotallist.open;
      LoadKbmMemtableFromDataSetQuiet(kbmTotallist,rSet1,[]);
      kbmTotallist.First;

    finally
      screen.cursor := crDefault;
      kbmTotallist.EnableControls;
    end;

  finally
    lExecutionPlan.Free;
  end;

end;

procedure TfrmRptTotallist.DoShow;
begin
  inherited;
  SetColumnGroupHeaders;
end;

procedure TfrmRptTotallist.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
end;

procedure TfrmRptTotallist.cbxMonthCloseUp(Sender: TObject);
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
  m := cbxMonth.ItemIndex;

  zDateFrom := encodeDate(y, m, 1);
  lastDay := DaysInAMonth(y, m);
  zDateTo := encodeDate(y, m, lastDay);
  dtDateFrom.Date := zDateFrom;
  dtDateTo.Date := zDateTo;
  zSetDates := true;
end;

procedure TfrmRptTotallist.dtDateFromChange(Sender: TObject);
begin
  if zSetDates then
  begin
    zDateFrom := dtDateFrom.Date;
    zDateTo := dtDateTo.Date;

    cbxYear.ItemIndex := 0;
    cbxMonth.ItemIndex := 0;
  end;
end;

procedure TfrmRptTotallist.FormCreate(Sender: TObject);
begin
  glb.fillListWithMonthsLong(cbxMonth.Items, 1);
  glb.fillListWithYears(cbxYear.Items, 1, False);
end;


procedure TfrmRptTotallist.FormShow(Sender: TObject);
var
  lLocations: TSet_Of_Integer;
begin
  lLocations := frmmain.FilteredLocations;
  try
    zLocationInString := glb.LocationSQLInString(lLocations);
  finally
    lLocations.Free;
  end;

  if zLocationInString = '' then
  begin
    labLocationsList.caption := 'All Locations';
  end else
  begin
    labLocationsList.caption := zLocationInString;
  end;
  showdata;
end;

procedure TfrmRptTotallist.lvTotallistHideZeroValue(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  inherited;
  if aText = '0' then aText := '';
end;

procedure TfrmRptTotallist.lvTotallistWeekNrGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AText: string);
var
  lDate: TDateTime;
begin
  inherited;
  try
    lDate := aRecord.Values[lvTotalListdtDate.Index];
    aText := IntToStr(lDate.WeekOfYear);
  except
    aText := '';
  end;
end;

end.
