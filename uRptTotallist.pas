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
  , uRoomerForm, dxPScxCommon, dxPScxGridLnk, AdvSmoothProgressBar, Vcl.ComCtrls, sStatusBar;



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
    lvTotallistroomsStay: TcxGridDBBandedColumn;
    lvTotallistpaxStay: TcxGridDBBandedColumn;
    lvTotallistroomsWaitinglist: TcxGridDBBandedColumn;
    lvTotallistpaxWaitinglist: TcxGridDBBandedColumn;
    lvTotallistRoomsAllotment: TcxGridDBBandedColumn;
    lvTotallistpaxAllotment: TcxGridDBBandedColumn;
    lvTotallistroomsTotal: TcxGridDBBandedColumn;
    lvTotallistpaxTotal: TcxGridDBBandedColumn;
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
  protected
    procedure DoLoadData; override;
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
  , uSQLUtils;


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

{$REGION 'SQL statement'}
      s := '   SELECT ' +
           '     pd.date AS dtDate, ' +
           '     SUM(IF(rr.status IN (''P'',''G'',''D'',''W'',''Z'',''Q'') AND rr.arrival = rd.ADate AND rr.arrival = pd.date, 1, 0)) AS roomsArrival, ' +
           '     SUM(IF(rr.status IN (''P'',''G'',''D'',''W'',''Z'',''Q'') AND rr.arrival = rd.ADate AND rr.arrival = pd.date, p.numGuests, 0)) AS paxArrival, ' +
           '     dep.numRooms AS roomsDeparture, ' +
           '     dep.numGuests AS paxDeparture, ' +
           '     SUM(IF(rr.status IN (''P'',''G'',''D'',''W'',''Z'',''Q'') AND (rr.arrival <= pd.date) AND (rr.departure > pd.date), 1, 0)) AS roomsInHouse, ' +
           '     SUM(IF(rr.status IN (''P'',''G'',''D'',''W'',''Z'',''Q'') AND (rr.arrival <= pd.date) AND (rr.departure > pd.date), p.numGuests, 0)) AS paxInHouse, ' +
           '     SUM(IF(rr.status IN (''P'',''G'',''D'',''W'',''Z'',''Q'') AND (rr.arrival < pd.date) AND (rr.departure > pd.date), 1, 0)) AS roomsStay, ' +
           '     SUM(IF(rr.status IN (''P'',''G'',''D'',''W'',''Z'',''Q'') AND (rr.arrival < pd.date) AND (rr.departure > pd.date), p.numGuests, 0)) AS paxStay, ' +
           '     SUM(IF(rr.status IN (''O'') AND DATE(rd.Adate) = pd.Date AND rd.resflag IN (''O'') , 1, 0)) AS roomsWaitinglist, ' +
           '     SUM(IF(rr.status IN (''O'') AND DATE(rd.Adate) = pd.Date AND rd.resflag IN (''O'') , p.numGuests, 0)) AS paxWaitinglist, ' +
           '     SUM(IF(rr.status IN (''L'') AND DATE(rd.Adate) = pd.Date AND rd.resflag IN (''L'') , 1, 0)) AS roomsWaitinglistNonOptional, ' +
           '     SUM(IF(rr.status IN (''L'') AND DATE(rd.Adate) = pd.Date AND rd.resflag IN (''L'') , p.numGuests, 0)) AS paxWaitinglistNonOptional, ' +
           '     SUM(IF(rr.status IN (''A'') AND DATE(rd.Adate) = pd.Date AND rd.resflag IN (''A'') , 1, 0)) AS roomsAllotmennt, ' +
           '     SUM(IF(rr.status IN (''A'') AND DATE(rd.Adate) = pd.Date AND rd.resflag IN (''A'') , p.numGuests, 0)) AS paxAllotment, ' +
           '     SUM(IF(rr.status IN (''P'',''G'',''D'',''W'',''Z'',''Q'',''L'',''A'') AND (rr.arrival <= pd.date) AND (rr.departure >= pd.date), 1, 0)) AS roomsTotal, ' +
           '     SUM(IF(rr.status IN (''P'',''G'',''D'',''W'',''Z'',''Q'',''L'',''A'') AND (rr.arrival <= pd.date) AND (rr.departure >= pd.date) , p.numGuests, 0)) AS paxTotal, ' +
           '     SUM(IF(rr.status IN (''B'') AND r.outOfOrderBlocking=1 AND DATE(rd.Adate) = pd.Date AND rd.resflag IN (''B'') , 1, 0)) AS roomsOutOfOrder, ' +
           '     SUM(IF(rr.status IN (''B'') AND r.outOfOrderBlocking=1 AND DATE(rd.Adate) = pd.Date AND rd.resflag IN (''B'') , p.numGuests, 0)) AS paxOutOfOrder ' +
           'FROM ' +
           '    predefineddates pd ' +
           '    JOIN roomsdate rd ON rd.ADate=pd.date AND NOT rd.resFlag IN (''X'',''C'') ' +
           '    JOIN roomreservations rr ON rr.RoomReservation=rd.RoomReservation ' +
           '    JOIN reservations r ON r.Reservation=rr.Reservation ' +
           '    LEFT JOIN (SELECT RoomReservation, COUNT(id) AS numGuests FROM persons GROUP BY RoomReservation) AS p ON p.RoomReservation=rr.RoomReservation ' +
           '    LEFT JOIN (SELECT rr.departure, SUM(p.numGuests) AS numGuests, COUNT(rr.id) AS numRooms FROM roomreservations rr ' +
           '                    JOIN (SELECT RoomReservation, COUNT(p.id) numGuests FROM persons p GROUP BY p.RoomReservation) p ON p.RoomReservation=rr.RoomReservation ' +
           '                    WHERE ((rr.departure >= %s AND rr.departure<=%s)) AND status IN (''P'',''G'',''D'',''W'',''Z'',''Q'') ' +
           '                    GROUP BY rr.departure) dep ON dep.departure=pd.date ' +
           '	LEFT OUTER JOIN rooms ON (rooms.room = rr.room AND rooms.wildcard = 0) ' +
           'WHERE ' +
           '    ((pd.date >= %s AND pd.date<=%s)) ' +
           '    AND ((rr.room LIKE ''<%s'') OR (rooms.active = 1)) ';

    s := format(s, [_db(zDateFrom, true), _db(zDateTo, true), _db(zDateFrom, true), _db(zDateTo, true), '%']);
    if not zLocationInString.IsEmpty then
       s := s + format(' AND (rooms.location in (%s)) ', [zLocationInString]);
    s := s + 'GROUP BY pd.date';

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

end.
