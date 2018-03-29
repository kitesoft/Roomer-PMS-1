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
  ppCtrls, ppPrnabl, ppClass, ppCache, ppComm, ppRelatv, ppProd, ppReport, cxCalendar, sListBox, sCheckListBox,
  cxTextEdit

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
    tvStatsHighestRate: TcxGridDBBandedColumn;
    tvStatsLowestRate: TcxGridDBBandedColumn;
    tvStatscheckedInToday: TcxGridDBBandedColumn;
    tvStatsremainingArrivals: TcxGridDBBandedColumn;
    tvStatsnoShow: TcxGridDBBandedColumn;
    tvStatsRemainingDepartures: TcxGridDBBandedColumn;
    tvStatsdepartedRooms: TcxGridDBBandedColumn;
    tvStatsInHouse: TcxGridDBBandedColumn;
    tvStatsTotalSellableRooms: TcxGridDBBandedColumn;
    tvStatslocalCurrency: TcxGridDBBandedColumn;
    tvStatstotalGuests: TcxGridDBBandedColumn;
    tvStatsOccupancy: TcxGridDBBandedColumn;
    tvStatsadr: TcxGridDBBandedColumn;
    tvStatsrevPar: TcxGridDBBandedColumn;
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
    redtRevenue: TppDBText;
    ppLabel3: TppLabel;
    ppDBText3: TppDBText;
    ppLabel7: TppLabel;
    redtADR: TppDBText;
    ppLabel9: TppLabel;
    redtRevPar: TppDBText;
    ppLine3: TppLine;
    ppLine4: TppLine;
    ppLabel11: TppLabel;
    redtDiscount: TppDBText;
    ppLabel12: TppLabel;
    redtMaxRate: TppDBText;
    ppLabel13: TppLabel;
    redtMinRate: TppDBText;
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
    edtRevTotal: TppDBCalc;
    redtDiscountTotal: TppDBCalc;
    redtMaxrateMax: TppDBCalc;
    redtMinRateMin: TppDBCalc;
    ppDBCalc10: TppDBCalc;
    ppDBCalc12: TppDBCalc;
    ppDBCalc13: TppDBCalc;
    ppDBCalc14: TppDBCalc;
    ppDBCalc15: TppDBCalc;
    ppDBCalc16: TppDBCalc;
    ppDBCalc17: TppDBCalc;
    tvStatsooo: TcxGridDBBandedColumn;
    tvStatsWeekday: TcxGridDBBandedColumn;
    tvStatsExpectedDepartures: TcxGridDBBandedColumn;
    tvStatsArrivedRooms: TcxGridDBBandedColumn;
    tvStatsExpectedArrivals: TcxGridDBBandedColumn;
    gbxIncludedStates: TsGroupBox;
    clbIncludedStates: TsCheckListBox;
    rLabCurrency: TppLabel;
    rLabCurrencyCode: TppLabel;
    redtFullDate: TppDBText;
    ppLabel10: TppLabel;
    ppDBText2: TppDBText;
    ppLine1: TppLine;
    ppLabel26: TppLabel;
    ppDBText4: TppDBText;
    ppLabel27: TppLabel;
    ppDBText5: TppDBText;
    ppLabel28: TppLabel;
    ppDBText6: TppDBText;
    ppDBCalc11: TppDBCalc;
    ppDBCalc18: TppDBCalc;
    ppDBCalc19: TppDBCalc;
    ppDBCalc20: TppDBCalc;
    ppDBCalc2: TppDBCalc;
    redtOccSummary: TppLabel;
    redtADRSummary: TppLabel;
    redtRevParSummary: TppLabel;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure dtDateFromChange(Sender: TObject);
    procedure cbxMonthChange(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure btnGuestsExcelClick(Sender: TObject);
    procedure tvStatsGetDefaultCurrencyProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure sButton2Click(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure btnReportClick(Sender: TObject);
    procedure tvStatsHideZeroValues(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure ppHeaderBand1BeforePrint(Sender: TObject);
    procedure tvStatsrevenueGetCellHint(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      ACellViewInfo: TcxGridTableDataCellViewInfo; const AMousePos: TPoint; var AHintText: TCaption;
      var AIsHintMultiLine: Boolean; var AHintTextRect: TRect);
    procedure tvStatsDataControllerSummaryAfterSummary(ASender: TcxDataSummary);
    procedure rptStatsBeforePrint(Sender: TObject);
  private
    { Private declarations }

    zSetDates : boolean;
    function GetSummaryValueOrZero(aColumn: TcxGridDBBandedColumn): variant;
    procedure SetSummaryValue(aColumn: TcxGridDBBandedColumn; aValue: Variant);
    function GetSummaryText(aColumn: TcxGridDBBandedColumn): string;
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
  uRptbViewer
  , uSQLUtils
  , uHotelStatisticsAPI
  , uHotelStatistics
  , uRoomerCurrencymanager
  , uDateTimeHelper
  , DateUtils
  , uVCLUtils;

const
  cSelectableReservationStates : TReservationStateSet = [TReservationState.rsReservation, TReservationState.rsGuests, TReservationState.rsDeparted,
                                                         TReservationState.rsAllotment, TReservationState.rsBlocked, TReservationState.rsNoShow,
                                                         TReservationState.rsOptionalBooking, TReservationState.rsWaitingList];

  cDisabledReservationStates  : TReservationStateSet = [TReservationState.rsReservation, TReservationState.rsGuests, TReservationState.rsDeparted];

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


function TfrmRptRoomRentStatistics.GetSummaryValueOrZero(aColumn: TcxGridDBBandedColumn): variant;
var
  idx: integer;
begin
  with tvStats.Datacontroller.Summary do
  begin
    idx := FooterSummaryItems.IndexOfItemLink(aColumn);
    if (idx < 0) or VarIsNull(FooterSummaryValues[idx]) then
      Result := 0
    else
      result := FooterSummaryValues[idx];
  end;
end;

function TfrmRptRoomRentStatistics.GetSummaryText(aColumn: TcxGridDBBandedColumn): string;
var
  idx: integer;
begin
  with tvStats.Datacontroller.Summary do
  begin
    idx := FooterSummaryItems.IndexOfItemLink(aColumn);
    if (idx < 0)  then
      Result := ''
    else
      Result := FooterSummaryTexts[idx];
  end;
end;

procedure TfrmRptRoomRentStatistics.SetSummaryValue(aColumn: TcxGridDBBandedColumn; aValue: Variant);
var
  idx: integer;
begin
  with tvStats.Datacontroller.Summary do
  begin
    idx := FooterSummaryItems.IndexOfItemLink(aColumn);
    if (idx < 0) or VarIsNull(aValue) then
      FooterSummaryValues[idx] := 0
    else
      FooterSummaryValues[idx] := aValue;
  end;
end;


procedure TfrmRptRoomRentStatistics.tvStatsDataControllerSummaryAfterSummary(ASender: TcxDataSummary);
var
  lSoldRooms: integer;
  lSellableRooms: integer;
  lRevenue: double;

begin

  lRevenue :=  GetSummaryValueOrZero(tvStatsrevenue);
  lSellableRooms := GetSummaryValueOrZero(tvStatsTotalSellableRooms);
  lSoldRooms := GetSummaryValueOrZero(tvStatssoldRooms);

  if lSellableRooms <> 0 then
  begin
    SetSummaryValue(tvStatsOccupancy, 100 * lSoldRooms / lSellableRooms);
    SetSummaryValue(tvStatsrevPar, lRevenue / lSellableRooms);
  end
  else
  begin
    SetSummaryValue(tvStatsOccupancy, 0);
    SetSummaryValue(tvStatsrevPar, 0);
  end;

  // ADR
  if lSoldRooms <> 0 then
    SetSummaryValue(tvStatsadr, lRevenue / lSoldRooms)
  else
    SetSummaryValue(tvStatsadr, 0);

end;

procedure TfrmRptRoomRentStatistics.tvStatsGetDefaultCurrencyProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := RoomerCurrencyManager.DefaultCurrencyDefinition.GetcxEditProperties;
end;

procedure TfrmRptRoomRentStatistics.tvStatsHideZeroValues(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  if aRecord.Values[Sender.Index] = 0 then
    aText := '';
end;

procedure TfrmRptRoomRentStatistics.tvStatsrevenueGetCellHint(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; ACellViewInfo: TcxGridTableDataCellViewInfo; const AMousePos: TPoint;
  var AHintText: TCaption; var AIsHintMultiLine: Boolean; var AHintTextRect: TRect);
begin
//
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
  lAPICaller: THotelStatisticsMobileAPICaller;
  lStatistics: THotelStatisticsList;
  lStat: TSingleDateStatistics;
  lExcludedReservationStates: TReservationStateSet;
  i: integer;
begin

  kbmStat.DisableControls;
  lAPICaller := THotelStatisticsMobileAPICaller.Create;
  lStatistics := THotelStatisticsList.Create;
  try
    screen.Cursor := crHourGlass;

    kbmStat.Close;
    kbmStat.Open;

    lExcludedReservationStates := cAllReservationStatesSet;
    for i:= 0 to clbIncludedStates.Items.Count-1 do
      if clbIncludedStates.Checked[i] then
        Exclude(lExcludedReservationStates, TReservationState(Integer(clbIncludedStates.Items.Objects[i])));

    lAPICaller.GetRoomRentStatistics(dtDateFrom.Date, dtDateTo.Date, lExcludedReservationStates, lStatistics);

    for lStat in lStatistics.StatisticsPerDateList do
    begin
      kbmStat.Append;
      try
        kbmStat.FieldByName('ADate').AsDateTime := lStat.Date;
        kbmStat.FieldByName('revenue').asFloat := lStat.Statistic['REVENUE'].Value;
        kbmStat.FieldByName('occ').asFloat := lStat.Statistic['OCCUPANCY'].Value;
        kbmStat.FieldByName('adr').asFloat := lStat.Statistic['ADR'].Value;
        kbmStat.FieldByName('revPar').asFloat := lStat.Statistic['REVPAR'].Value;
        kbmStat.FieldByName('currency').asString := RoomerCurrencyManager.DefaultCurrency;
        kbmStat.FieldByName('totalDiscount').asFloat := lStat.Statistic['DISCOUNT'].Value;
        kbmStat.FieldByName('maxRate').asFloat := lStat.Statistic['MAXRATE'].Value;
        kbmStat.FieldByName('minRate').asFloat := lStat.Statistic['MINRATE'].Value;
        kbmStat.FieldByName('totalGuests').AsInteger := trunc(lStat.Statistic['GUESTCOUNT'].Value);
        kbmStat.FieldByName('totalSellableRooms').AsInteger := trunc(lStat.Statistic['TOTAL_SELLABLE_ROOMS'].Value);
        kbmStat.FieldByName('oooROoms').AsInteger := trunc(lStat.Statistic['OOOROOMS'].Value);
        kbmStat.FieldByName('soldRooms').AsInteger := trunc(lStat.Statistic['ROOMS_SOLD'].Value);
        kbmStat.FieldByName('inHouse').AsInteger := trunc(lStat.Statistic['IN_HOUSE'].Value);
        kbmStat.FieldByName('checkedInToday').AsInteger := trunc(lStat.Statistic['CHECKED_IN_TODAY'].Value);
        kbmStat.FieldByName('remainingArrivals').AsInteger := trunc(lStat.Statistic['REMAINING_ARRIVALS'].Value);
        kbmStat.FieldByName('noShow').AsInteger := trunc(lStat.Statistic['NOSHOWS'].Value);
        kbmStat.FieldByName('remainingDepartures').AsInteger := trunc(lStat.Statistic['REMAINING_DEPARTURES'].Value);
        kbmStat.FieldByName('departedRooms').AsInteger := trunc(lStat.Statistic['DEPARTED_ROOMS'].Value);
        kbmStat.FieldByName('expectedArrivals').AsInteger := trunc(lStat.Statistic['EXPECTED_ARRIVALS'].Value);
        kbmStat.FieldByName('arrivedRooms').AsInteger := trunc(lStat.Statistic['ARRIVED_ROOMS'].Value);
        kbmStat.FieldByName('expectedDepartures').AsInteger := trunc(lStat.Statistic['EXPECTED_DEPARTURES'].Value);

        kbmStat.Post;
      except
        kbmStat.Cancel;
        raise;
      end;

    end;
    kbmStat.First;

  finally
    lAPICaller.Free;
    lStatistics.Free;
    Screen.Cursor := crDefault;
    kbmStat.EnableControls;
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

procedure TfrmRptRoomRentStatistics.cbxMonthChange(Sender: TObject);
var
  y, m : word;
begin
  if cbxYear.ItemIndex < 0 then
    exit;
  if cbxMonth.ItemIndex < 0 then
    exit;
  zSetDates := false;
  try
    y := StrToInt(cbxYear.Items[cbxYear.ItemIndex]);
    m := cbxMonth.ItemIndex+1;

    dtDateFrom.Date := encodeDate(y, m, 1);
    dtDateTo.Date := dtDateFrom.Date.EndOfMonth;
  finally
    zSetDates := true;
  end;

end;

procedure TfrmRptRoomRentStatistics.dtDateFromChange(Sender: TObject);
begin
  if zSetDates then
  begin
    cbxYear.ItemIndex := -1;
    cbxMonth.ItemIndex := -1;
  end;
end;

procedure TfrmRptRoomRentStatistics.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self); PlaceFormOnVisibleMonitor(self);
  glb.fillListWithMonthsLong(cbxMonth.Items, 0);
  glb.fillListWithYears(cbxYear.Items, 0, False);
end;

procedure TfrmRptRoomRentStatistics.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    Close;
end;

procedure TfrmRptRoomRentStatistics.FormShow(Sender: TObject);
var
  i: integer;
begin
  _restoreForm(self);

  cSelectableReservationStates.AsStrings(clbIncludedStates.Items);
  for i := 0 to clbIncludedStates.Items.Count-1 do
  begin
    clbIncludedStates.ItemEnabled[i] := not (TReservationState(Integer(clbIncludedStates.Items.Objects[i])) in cDisabledReservationStates);
    clbIncludedStates.Checked[i] := TReservationState(Integer(clbIncludedStates.Items.Objects[i])) in cDisabledReservationStates;
  end;

  zSetDates := false;
  try
    cbxMonth.ItemIndex := Now.Month -1;
    cbxYear.ItemIndex := Now.Year - StrToInt(cbxYear.Items[0]);
    dtDateFrom.Date := Now.StartOfMonth;
    dtDateTo.Date := Now.EndOfMonth;
  finally
    zSetDates := true;
  end;
end;

procedure TfrmRptRoomRentStatistics.ppHeaderBand1BeforePrint(Sender : TObject);
var
  s : string;
begin
  rlabFrom.Caption := FormatDateTime('ddddd', dtDateFrom.Date);
  rlabTo.Caption := FormatDateTime('ddddd', dtDateTo.Date);
  rLabHotelName.Caption := g.qHotelName;
  rLabTimeCreated.Caption := 'Created : ' + FormatDateTime('', now);
  rLabCurrencyCode.Caption := RoomerCurrencyManager.DefaultCurrency;

  s := 'User : ' + g.qUser;
  if g.qusername <> '' then
    s := s + ' - ' + g.qusername;
  rlabUser.Caption := s;

end;

procedure TfrmRptRoomRentStatistics.rptStatsBeforePrint(Sender: TObject);
var
  lFormat: string;
begin
  lFormat := RoomerCurrencyManager.DefaultCurrencyDefinition.DisplayFormat(false);
  redtRevenue.DisplayFormat := lFormat;
  redtADR.DisplayFormat := lFormat;
  redtRevPar.DisplayFormat := lFormat;
  redtDiscount.DisplayFormat := lFormat;
  redtMaxRate.DisplayFormat := lFormat;
  redtMinRate.DisplayFormat := lFormat;
  edtRevTotal.DisplayFormat := lFormat;
  redtDiscountTotal.DisplayFormat := lFormat;
  redtMaxrateMax.DisplayFormat := lFormat;
  redtMinRateMin.DisplayFormat := lFormat;

  redtFullDate.DisplayFormat := FormatSettings.ShortDateFormat;

  redtOccSummary.Text := GetSummaryText(tvStatsOccupancy);
  redtADRSummary.Text := GetSummaryText(tvStatsadr);
  redtRevParSummary.Text := GetSummaryText(tvStatsrevPar);
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

