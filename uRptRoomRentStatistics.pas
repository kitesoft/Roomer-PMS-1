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
  , uHotelStatistics, dxPScxCommon, dxPScxGridLnk
  , uRoomRentStatisticsDefinitions, dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider,
  dxPSFillPatterns, dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv,
  dxPSPrVwRibbon, dxPScxPageControlProducer, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, dxPSCore
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
    pcMain: TsPageControl;
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
    tsComparison: TsTabSheet;
    sPanel3: TsPanel;
    gbxComparisonStartDate: TsGroupBox;
    dtComparisonStart: TsDateEdit;
    gbxComparisonPeriod: TsGroupBox;
    cbxComparisonPeriod: TsComboBox;
    rgCompareOn: TsRadioGroup;
    gbxComparisonData: TsGroupBox;
    clbComparisonDataSelection: TsCheckListBox;
    gbxComparisonRoomTypes: TsGroupBox;
    clbCompareRoomTypes: TsCheckListBox;
    pnlExportButtons: TsPanel;
    btnComparisonExcel: TsButton;
    btnComparisonReport: TsButton;
    grdComparison: TcxGrid;
    kbmComparison: TkbmMemTable;
    kbmComparisonADate: TDateField;
    kbmComparisonrevenueBase: TFloatField;
    kbmComparisonoccBase: TFloatField;
    kbmComparisonadrBase: TFloatField;
    kbmComparisonrevParBase: TFloatField;
    kbmComparisontotalDiscountBase: TFloatField;
    kbmComparisonmaxRateBase: TFloatField;
    kbmComparisonminRateBase: TFloatField;
    kbmComparisontotalGuestsBase: TIntegerField;
    kbmComparisontotalSellableRoomsBase: TIntegerField;
    kbmComparisonoooRoomsBase: TIntegerField;
    kbmComparisonsoldRoomsBase: TIntegerField;
    kbmComparisonrevenue: TFloatField;
    kbmComparisonocc: TFloatField;
    kbmComparisonadr: TFloatField;
    kbmComparisonrevPar: TFloatField;
    kbmComparisontotalDiscount: TFloatField;
    kbmComparisonmaxRate: TFloatField;
    kbmComparisonminRate: TFloatField;
    kbmComparisontotalGuests: TIntegerField;
    kbmComparisontotalSellableRooms: TIntegerField;
    kbmComparisonoooRooms: TIntegerField;
    kbmComparisonsoldRooms: TIntegerField;
    dsComparison: TDataSource;
    grdComparisonDBBandedTableView1: TcxGridDBBandedTableView;
    lvComparison: TcxGridLevel;
    tvComparison: TcxGridDBBandedTableView;
    kbmComparisoncurrency: TWideStringField;
    kbmComparisonADateBase: TDateField;
    cxsrRoomerStyleRepository: TcxStyleRepository;
    cxstBandHeader: TcxStyle;
    cxstCaption: TcxStyle;
    cxstCardCaptionRow: TcxStyle;
    cxstCardRowCaption: TcxStyle;
    cxstContent: TcxStyle;
    cxstContentEven: TcxStyle;
    cxstContentOdd: TcxStyle;
    cxstFilterBar: TcxStyle;
    cxstFooter: TcxStyle;
    cxstGroup: TcxStyle;
    cxstHeader: TcxStyle;
    cxstPreview: TcxStyle;
    cxstSelection: TcxStyle;
    cxstReportBandHeader: TcxStyle;
    cxstReportCaption: TcxStyle;
    cxstReportCardCaptionRow: TcxStyle;
    cxstReportCardRowCaption: TcxStyle;
    cxstReportContent: TcxStyle;
    cxstReportContentEven: TcxStyle;
    cxstReportContentOdd: TcxStyle;
    cxstReportFilterBar: TcxStyle;
    cxstReportFooter: TcxStyle;
    cxstReportGroup: TcxStyle;
    cxstReportHeader: TcxStyle;
    cxstReportPreview: TcxStyle;
    cxstReportSelection: TcxStyle;
    dxssRoomerGridReportLink: TdxGridReportLinkStyleSheet;
    cxssRoomerGridTableView: TcxGridTableViewStyleSheet;
    cxssRoomerGridBandedTableView: TcxGridBandedTableViewStyleSheet;
    cxstBandHeaderBackground: TcxStyle;
    kbmComparisonrevenueDiff: TFloatField;
    kbmComparisonOccDiff: TFloatField;
    kbmComparisonAdrDiff: TFloatField;
    kbmComparisonRevParDiff: TFloatField;
    kbmComparisonTotalDiscountDiff: TFloatField;
    kbmComparisonMaxRateDiff: TFloatField;
    kbmComparisonMinRateDiff: TFloatField;
    kbmComparisonTotalGuestsDiff: TIntegerField;
    kbmComparisonTotalSellableRoomsDiff: TIntegerField;
    kbmComparisonOooRoomsDiff: TIntegerField;
    kbmComparisonSoldRoomsDiff: TIntegerField;
    tvComparisonaDateBase: TcxGridDBBandedColumn;
    tvComparisonRevenueBase: TcxGridDBBandedColumn;
    tvComparisonOccBase: TcxGridDBBandedColumn;
    tvComparisonadrBase: TcxGridDBBandedColumn;
    tvComparisonrevParBase: TcxGridDBBandedColumn;
    tvComparisontotalDiscountBase: TcxGridDBBandedColumn;
    tvComparisonmaxRateBase: TcxGridDBBandedColumn;
    tvComparisonminRateBase: TcxGridDBBandedColumn;
    tvComparisontotalGuestsBase: TcxGridDBBandedColumn;
    tvComparisontotalSellableRoomsBase: TcxGridDBBandedColumn;
    tvComparisonoooRoomsBase: TcxGridDBBandedColumn;
    tvComparisonsoldRoomsBase: TcxGridDBBandedColumn;
    tvComparisonrevenue: TcxGridDBBandedColumn;
    tvComparisonADate: TcxGridDBBandedColumn;
    tvComparisonocc: TcxGridDBBandedColumn;
    tvComparisonadr: TcxGridDBBandedColumn;
    tvComparisonrevPar: TcxGridDBBandedColumn;
    tvComparisontotalDiscount: TcxGridDBBandedColumn;
    tvComparisonmaxRate: TcxGridDBBandedColumn;
    tvComparisonminRate: TcxGridDBBandedColumn;
    tvComparisontotalGuests: TcxGridDBBandedColumn;
    tvComparisontotalSellableRooms: TcxGridDBBandedColumn;
    tvComparisonoooRooms: TcxGridDBBandedColumn;
    tvComparisonsoldRooms: TcxGridDBBandedColumn;
    tvComparisonRevenueDiff: TcxGridDBBandedColumn;
    tvComparisonOccDiff: TcxGridDBBandedColumn;
    tvComparisonAdrDiff: TcxGridDBBandedColumn;
    tvComparisonRevParDiff: TcxGridDBBandedColumn;
    tvComparisonTotalDiscountDiff: TcxGridDBBandedColumn;
    tvComparisonMaxRateDiff: TcxGridDBBandedColumn;
    tvComparisonMinRateDiff: TcxGridDBBandedColumn;
    tvComparisonTotalGuestsDiff: TcxGridDBBandedColumn;
    tvComparisonTotalSellableRoomsDiff: TcxGridDBBandedColumn;
    tvComparisonOooRoomsDiff: TcxGridDBBandedColumn;
    tvComparisonSoldRoomsDiff: TcxGridDBBandedColumn;
    tvComparisonDateBaseDay: TcxGridDBBandedColumn;
    tvComparisonDateDay: TcxGridDBBandedColumn;
    grdPrinter: TdxComponentPrinter;
    grdPrinterLink1: TdxGridReportLink;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure dtDateChange(Sender: TObject);
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
    procedure cbxComparisonPeriodChange(Sender: TObject);
    procedure kbmComparisonCalcFields(DataSet: TDataSet);
    procedure clbComparisonDataSelectionClickCheck(Sender: TObject);
    procedure rgCompareOnChange(Sender: TObject);
    procedure tvComparisonDataControllerSummaryAfterSummary(ASender: TcxDataSummary);
    procedure btnComparisonExcelClick(Sender: TObject);
  private
    { Private declarations }

    zSetDates : boolean;
    FDataLoadingThreads: integer;
    FCompareData: TRoomRentCompareDataSet;
    FBaseBandOrigCaption: string;
    FCompareBandOrigCaption: string;

    function GetFooterSummaryValueOrZero(aColumn: TcxGridDBBandedColumn): variant;

    procedure SetFooterSummaryValue(aColumn: TcxGridDBBandedColumn; aValue: Variant);
    function GetFooterSummaryText(aColumn: TcxGridDBBandedColumn): string;
    procedure LoadDataInDataset(aDataset: TDataSet; aStatistics: THotelStatisticsList; aComparisonFieldsOnly: boolean = false);
    procedure LoadBaseDataInComparisonDataset(aDaysOffset: integer);
    procedure LoadBaseDataInDataset(aStatistics: THotelStatisticsList);
    procedure LoadComparisonDataInDataset(aStatistics: THotelStatisticsList);
    procedure UpdateCompareDataColumns;
    procedure CalculateComparisonSummaries(ASender: TcxDataSummary);
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
  , uRoomerCurrencymanager
  , uDateTimeHelper
  , DateUtils
  , uVCLUtils
  ;

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


function TfrmRptRoomRentStatistics.GetFooterSummaryValueOrZero(aColumn: TcxGridDBBandedColumn): variant;
var
  idx: integer;
begin
  with aColumn.DataBinding.DataController.Summary do
  begin
    idx := FooterSummaryItems.IndexOfItemLink(aColumn);
    if (idx < 0) or VarIsNull(FooterSummaryValues[idx]) then
      Result := 0
    else
      result := FooterSummaryValues[idx];
  end;
end;

procedure TfrmRptRoomRentStatistics.kbmComparisonCalcFields(DataSet: TDataSet);
begin
  kbmComparisonrevenueDiff.AsFloat := kbmComparisonrevenueBase.AsFloat - kbmComparisonrevenue.AsFloat;
  kbmComparisonOccDiff.AsFloat := kbmComparisonoccBase.AsFloat - kbmComparisonocc.AsFloat;
  kbmComparisonAdrDiff.AsFloat := kbmComparisonadrBase.AsFloat - kbmComparisonadr.AsFloat;
  kbmComparisonRevParDiff.AsFloat := kbmComparisonrevParBase.AsFloat - kbmComparisonrevPar.AsFloat;
  kbmComparisonTotalDiscountDiff.AsFloat := kbmComparisontotalDiscountBase.AsFloat - kbmComparisontotalDiscount.AsFloat;
  kbmComparisonMaxRateDiff.AsInteger := kbmComparisonmaxRateBase.AsInteger - kbmComparisonmaxRate.AsInteger;
  kbmComparisonMinRateDiff.AsInteger := kbmComparisonminRateBase.asInteger - kbmComparisonminRate.AsInteger;
  kbmComparisonTotalGuestsDiff.AsInteger := kbmComparisontotalGuestsBase.AsInteger - kbmComparisontotalGuests.AsInteger;
  kbmComparisonTotalSellableRoomsDiff.AsInteger := kbmComparisontotalSellableRoomsBase.AsInteger - kbmComparisontotalSellableRooms.AsInteger;
  kbmComparisonOooRoomsDiff.AsInteger := kbmComparisonoooRoomsBase.AsInteger - kbmComparisonoooRooms.AsInteger;
  kbmComparisonSoldRoomsDiff.AsInteger := kbmComparisonsoldRoomsBase.AsInteger - kbmComparisonsoldRooms.AsInteger;
end;

function TfrmRptRoomRentStatistics.GetFooterSummaryText(aColumn: TcxGridDBBandedColumn): string;
var
  idx: integer;
begin
  with aColumn.DataBinding.DataController.Summary do
  begin
    idx := FooterSummaryItems.IndexOfItemLink(aColumn);
    if (idx < 0)  then
      Result := ''
    else
      Result := FooterSummaryTexts[idx];
  end;
end;

procedure TfrmRptRoomRentStatistics.SetFooterSummaryValue(aColumn: TcxGridDBBandedColumn; aValue: Variant);
var
  idx: integer;
begin
  with aColumn.DataBinding.DataController.Summary do
  begin
    idx := FooterSummaryItems.IndexOfItemLink(aColumn);
    if (idx < 0) or VarIsNull(aValue) then
      FooterSummaryValues[idx] := 0
    else
      FooterSummaryValues[idx] := aValue;
  end;
end;


procedure TfrmRptRoomRentStatistics.tvComparisonDataControllerSummaryAfterSummary(ASender: TcxDataSummary);
begin
  CalculateComparisonSummaries(aSender);
end;

procedure TfrmRptRoomRentStatistics.tvStatsDataControllerSummaryAfterSummary(ASender: TcxDataSummary);
var
  lSoldRooms: integer;
  lSellableRooms: integer;
  lRevenue: double;

begin
  lRevenue :=  GetFooterSummaryValueOrZero(tvStatsrevenue);
  lSellableRooms := GetFooterSummaryValueOrZero(tvStatsTotalSellableRooms);
  lSoldRooms := GetFooterSummaryValueOrZero(tvStatssoldRooms);

  if lSellableRooms <> 0 then
  begin
    SetFooterSummaryValue(tvStatsOccupancy, 100 * lSoldRooms / lSellableRooms);
    SetFooterSummaryValue(tvStatsrevPar, lRevenue / lSellableRooms);
  end
  else
  begin
    SetFooterSummaryValue(tvStatsOccupancy, 0);
    SetFooterSummaryValue(tvStatsrevPar, 0);
  end;

  // ADR
  if lSoldRooms <> 0 then
    SetFooterSummaryValue(tvStatsadr, lRevenue / lSoldRooms)
  else
    SetFooterSummaryValue(tvStatsadr, 0);

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

procedure TfrmRptRoomRentStatistics.UpdateCompareDataColumns;
var
  i: integer;
begin
  tvComparison.BeginUpdate();
  try
    for i := 0 to tvComparison.ColumnCount -1 do
      if tvCOmparison.Columns[i].Tag > 0 then
        tvComparison.Columns[i].Visible := TRoomRentCompareData(tvCOmparison.Columns[i].Tag) in FCompareData;

  finally
    tvComparison.EndUpdate;
  end;
end;

procedure TfrmRptRoomRentStatistics.btnComparisonExcelClick(Sender: TObject);
var
  sFilename : string;
  s         : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_StatCompare';
  ExportGridToExcel(sFilename, grdComparison {grGroupInvoiceSums}, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
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
  lExcludedReservationStates: TReservationStateSet;
  i: integer;
  lCompareToDate: TDateTime;
const
  cBandCaptionFormat = ' ( %s - %s )';
begin

  btnRefresh.Enabled := false;

  lExcludedReservationStates := cAllReservationStatesSet;
  for i:= 0 to clbIncludedStates.Items.Count-1 do
    if clbIncludedStates.Checked[i] then
      Exclude(lExcludedReservationStates, TReservationState(Integer(clbIncludedStates.Items.Objects[i])));

  kbmStat.Close;
  kbmComparison.Close;

  inc(FDataLoadingThreads);
  THotelStatisticsMobileAPICallerThreaded.GetRoomRentStatistics(dtDateFrom.Date, dtDateTo.Date, lExcludedReservationStates, LoadBaseDataInDataset);
  if pcMain.ActivePage = tsComparison then
  begin
    inc(FDataLoadingThreads);
    lCompareToDate := dtComparisonStart.Date.AddDays(trunc(dtDateTo.Date - dtDateFrom.Date));
    THotelStatisticsMobileAPICallerThreaded.GetRoomRentStatistics(dtComparisonStart.Date,
                                                                  lCompareToDate,
                                                                  lExcludedReservationStates,
                                                                  LoadComparisonDataInDataset);

    tvComparison.Bands[0].Caption := FBaseBandOrigCaption + Format(cBandCaptionFormat, [dtDateFrom.Text, dtDateTo.Text]);
    tvComparison.Bands[1].Caption := FCompareBandOrigCaption +
                                      Format(cBandCaptionFormat, [dtComparisonStart.Text,
                                                                  FormatDateTime(FormatSettings.ShortDateFormat, lCompareToDate)]);
  end;
end;

procedure TfrmRptRoomRentStatistics.LoadBaseDataInDataset(aStatistics: THotelStatisticsList);
begin
  dec(FDataLoadingThreads);
  LoadDataInDataset(kbmStat, aStatistics);
  if pcMain.ActivePage = tsComparison then
    LoadBaseDataInComparisonDataset(trunc(dtComparisonStart.Date - dtDateFrom.Date));

  btnRefresh.Enabled := (FDataLoadingThreads = 0);
end;

procedure TfrmRptRoomRentStatistics.LoadComparisonDataInDataset(aStatistics: THotelStatisticsList);
begin
  dec(FDataLoadingThreads);
  LoadDataInDataset(kbmComparison, aStatistics, true);
  btnRefresh.Enabled := (FDataLoadingThreads = 0);
end;

procedure TfrmRptRoomRentStatistics.LoadDataInDataset(aDataset: TDataSet; aStatistics: THotelStatisticsList; aComparisonFieldsOnly: boolean);
var
  lStat: TSingleDateStatistics;
begin

  aDataset.DisableControls;
  try
    screen.Cursor := crHourGlass;
    aDataset.Open;

    for lStat in aStatistics.StatisticsPerDateList do
    begin
      if aDataset.Locate('aDate', lStat.Date, []) then
        aDataset.Edit
      else
      begin
        aDataSet.Append;
        aDataset.FieldByName('ADate').AsDateTime := lStat.Date;
      end;
      try
        aDataset.FieldByName('revenue').asFloat := lStat.Statistic['REVENUE'].Value;
        aDataset.FieldByName('occ').asFloat := lStat.Statistic['OCCUPANCY'].Value;
        aDataset.FieldByName('adr').asFloat := lStat.Statistic['ADR'].Value;
        aDataset.FieldByName('revPar').asFloat := lStat.Statistic['REVPAR'].Value;
        aDataset.FieldByName('currency').asString := RoomerCurrencyManager.DefaultCurrency;
        aDataset.FieldByName('totalDiscount').asFloat := lStat.Statistic['DISCOUNT'].Value;
        aDataset.FieldByName('maxRate').asFloat := lStat.Statistic['MAXRATE'].Value;
        aDataset.FieldByName('minRate').asFloat := lStat.Statistic['MINRATE'].Value;
        aDataset.FieldByName('totalGuests').AsInteger := trunc(lStat.Statistic['GUESTCOUNT'].Value);
        aDataset.FieldByName('totalSellableRooms').AsInteger := trunc(lStat.Statistic['TOTAL_SELLABLE_ROOMS'].Value);
        aDataset.FieldByName('oooROoms').AsInteger := trunc(lStat.Statistic['OOOROOMS'].Value);
        aDataset.FieldByName('soldRooms').AsInteger := trunc(lStat.Statistic['ROOMS_SOLD'].Value);
        if not aComparisonFieldsOnly then
        begin
          aDataset.FieldByName('inHouse').AsInteger := trunc(lStat.Statistic['IN_HOUSE'].Value);
          aDataset.FieldByName('checkedInToday').AsInteger := trunc(lStat.Statistic['CHECKED_IN_TODAY'].Value);
          aDataset.FieldByName('remainingArrivals').AsInteger := trunc(lStat.Statistic['REMAINING_ARRIVALS'].Value);
          aDataset.FieldByName('noShow').AsInteger := trunc(lStat.Statistic['NOSHOWS'].Value);
          aDataset.FieldByName('remainingDepartures').AsInteger := trunc(lStat.Statistic['REMAINING_DEPARTURES'].Value);
          aDataset.FieldByName('departedRooms').AsInteger := trunc(lStat.Statistic['DEPARTED_ROOMS'].Value);
          aDataset.FieldByName('expectedArrivals').AsInteger := trunc(lStat.Statistic['EXPECTED_ARRIVALS'].Value);
          aDataset.FieldByName('arrivedRooms').AsInteger := trunc(lStat.Statistic['ARRIVED_ROOMS'].Value);
          aDataset.FieldByName('expectedDepartures').AsInteger := trunc(lStat.Statistic['EXPECTED_DEPARTURES'].Value);
        end;

        aDataset.Post;
      except
        aDataset.Cancel;
        raise;
      end;

    end;
    aDataset.First;

  finally
    Screen.Cursor := crDefault;
    aDataset.EnableControls;
  end;
end;

procedure TfrmRptRoomRentStatistics.LoadBaseDataInComparisonDataset(aDaysOffset: integer);
begin
  tvComparison.DataController.BeginFullUpdate;
  kbmComparison.DisableControls;
  kbmStat.DisableControls;
  try
    if not kbmComparison.Active then
      kbmComparison.Open;

    kbmStat.First;
    while not kbmStat.Eof do
    begin
      if kbmComparison.Locate('aDate', kbmStat.FieldByName('adate').asDateTime.AddDays(aDaysOffset), []) then
        kbmComparison.Edit
      else
      begin
        kbmComparison.Append;
        kbmComparisonADate.AsDateTime := kbmStat.FieldByName('adate').asDateTime.AddDays(aDaysOffset);
      end;

      try
        kbmComparisonaDateBase.AsDateTime :=                      kbmStat.FieldByName('adate').asDateTime;
        kbmComparisonrevenueBase.asFloat :=                       kbmStat.FieldByName('revenue').asFloat;
        kbmComparisonoccBase.asFloat :=                           kbmStat.FieldByName('occ').asFloat;
        kbmComparisonadrBase.asFloat :=                           kbmStat.FieldByName('adr').asFloat;
        kbmComparisonrevParBase.asFloat :=                        kbmStat.FieldByName('revPar').asFloat;
        kbmComparisontotalDiscountBase.asFloat :=                 kbmStat.FieldByName('totalDiscount').asFloat;
        kbmComparisonmaxRateBase.asFloat :=                       kbmStat.FieldByName('maxRate').asFloat;
        kbmComparisonminRateBase.asFloat :=                       kbmStat.FieldByName('minRate').asFloat;
        kbmComparisontotalGuestsBase.AsInteger :=                 kbmStat.FieldByName('totalGuests').AsInteger;
        kbmComparisontotalSellableRoomsBase.AsInteger :=          kbmStat.FieldByName('totalSellableRooms').AsInteger;
        kbmComparisonoooROomsBase.AsInteger :=                    kbmStat.FieldByName('oooROoms').AsInteger;
        kbmComparisonsoldRoomsBase.AsInteger :=                   kbmStat.FieldByName('soldRooms').AsInteger;

        kbmComparison.Post;
      except
        kbmComparison.Cancel;
        raise;
      end;
      kbmStat.Next;
    end;

    kbmComparison.First;

  finally
    kbmComparison.EnableControls;
    kbmStat.EnableControls;
    tvComparison.DataController.EndFullUpdate;
  end;
end;

procedure TfrmRptRoomRentStatistics.btnReportClick(Sender: TObject);
begin
  grdPrinter.Print(True, nil, grdPrinterLink1);
end;

procedure TfrmRptRoomRentStatistics.cbxComparisonPeriodChange(Sender: TObject);
begin
  if cbxComparisonPeriod.Itemindex = -1 then
    Exit;

  case TRoomRentComparePeriod.FromItemIndex(cbxComparisonPeriod.ItemIndex) of
    TRoomRentComparePeriod.PreviousYear:     dtComparisonStart.Date := dtDateFrom.Date.AddYears(-1);
    TRoomRentComparePeriod.PreviousMonth:    dtComparisonStart.Date := dtDateFrom.Date.AddMonths(-1);
    TRoomRentComparePeriod.NextYear:     dtComparisonStart.Date := dtDateFrom.Date.AddYears(1);
    TRoomRentComparePeriod.NextMonth:    dtComparisonStart.Date := dtDateFrom.Date.AddMonths(1);
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

procedure TfrmRptRoomRentStatistics.clbComparisonDataSelectionClickCheck(Sender: TObject);
var
  i: integer;
begin
  FCompareData := [];
  for i := 0 to clbComparisonDataSelection.Items.Count-1 do
    if clbComparisonDataSelection.Checked[i] then
      Include(FCompareData, TRoomRentCompareData(Integer(clbComparisonDataSelection.items.Objects[i])));

  UpdateCompareDataColumns;
end;

procedure TfrmRptRoomRentStatistics.dtDateChange(Sender: TObject);
begin
  if zSetDates then
  begin
    cbxYear.ItemIndex := -1;
    cbxMonth.ItemIndex := -1;
  end;

  cbxComparisonPeriodChange(nil);
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

  TRoomRentComparePeriod.AsStrings(cbxComparisonPeriod.Items);
  cbxComparisonPeriod.ItemIndex := 0;
  TRoomRentCompareData.AsStrings(clbComparisonDataSelection.Items);

  clbComparisonDataSelection.Checked[TRoomRentCompareData.Revenue.ToItemIndex] := true;
  clbComparisonDataSelection.Checked[TRoomRentCompareData.Occupancy.ToItemIndex] := true;
  clbComparisonDataSelection.Checked[TRoomRentCompareData.Adr.ToItemIndex] := true;
  clbComparisonDataSelection.Checked[TRoomRentCompareData.Adr.ToItemIndex] := true;
  clbComparisonDataSelectionClickCheck(nil);

  clbCompareRoomTypes.Items.BeginUpdate;
  try
    clbCompareRoomTypes.Items.Clear;
    with glb.RoomTypesSet do
    begin
      First;
      while not Eof do
      begin
        clbCompareRoomTypes.Items.AddObject(FieldByName('roomtype').asString, TObject(fieldByName('ID').AsInteger));
        Next;
      end;
    end;
  finally
    clbCompareRoomTypes.Items.EndUpdate;
  end;

  FBaseBandOrigCaption := tvComparison.Bands[0].Caption;
  FCompareBandOrigCaption := tvComparison.Bands[1].Caption;

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

procedure TfrmRptRoomRentStatistics.rgCompareOnChange(Sender: TObject);
begin
  if rgCompareOn.ItemIndex = 1 then
    tvComparisonaDateBase.GroupIndex := 1
  else
    tvComparisonaDateBase.GroupIndex := -1
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

  redtOccSummary.Text := GetFooterSummaryText(tvStatsOccupancy);
  redtADRSummary.Text := GetFooterSummaryText(tvStatsadr);
  redtRevParSummary.Text := GetFooterSummaryText(tvStatsrevPar);
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


procedure TfrmRptRoomRentStatistics.CalculateComparisonSummaries(ASender: TcxDataSummary);

    procedure CalcGroupSummary(ADataGroupIndex: Integer);
    var
      i: Integer;
      lRevenueBase, lRevenueCompare: double;
      lSellableBase, lSoldBase: Integer;
      lSellableCompare, lSoldCompare: Integer;
      lSummaryItems : TcxDataGroupSummaryItems;
      Records: TList;

    begin
      Records := TList.Create;

      try
        with ASender, DataController, Groups do
        begin
          lSummaryItems := GroupSummaryItems[Level[ADataGroupIndex]];
          if assigned(lSummaryItems) then
          begin
            LoadRecordIndexes(Records, ADataGroupIndex);
            lRevenueBase := 0.0;
            lSellableBase := 0;
            lSoldBase := 0;
            lRevenueCompare := 0.0;
            lSellableCompare := 0;
            lSoldCompare := 0;

            for i := 0 to Records.Count - 1 do
            begin
              lRevenueBase := lRevenueBase + Values[Integer(Records[i]), tvComparisonRevenueBase.Index];
              lSellableBase := lSellableBase + Values[Integer(Records[i]), tvComparisontotalSellableRoomsBase.Index];
              lSoldBase := lSoldBase + Values[Integer(Records[i]), tvComparisonsoldRoomsBase.Index];
              lRevenueCompare := lRevenueCompare + Values[Integer(Records[i]), tvComparisonrevenue.Index];
              lSellableCompare := lSellableCompare + Values[Integer(Records[i]), tvComparisontotalSellableRooms.Index];
              lSoldCompare := lSoldCompare + Values[Integer(Records[i]), tvComparisonsoldRooms.Index];
            end;

            if lSellableBase <> 0 then
            begin
              GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonOccBase)] := lSoldBase / lSellableBase * 100;
              GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonrevParBase)] := lRevenueBase / lSellableBase;
            end;
            if lSoldBase <> 0 then
              GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonadrBase)] := lRevenueBase / lSoldBase;

            if lSellableCompare <> 0 then
            begin
              GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonocc)] := lSoldCompare / lSellableCompare * 100;
              GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonrevPar)] := lRevenueCompare / lSellableCompare;
            end;
            if lSoldCompare <> 0 then
              GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonadr)] := lRevenueCompare / lSoldCompare;


            GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonOccDiff)] :=
               GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonOccBase)] - GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonocc)];

            GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonrevParDiff)] :=
               GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonrevParBase)] - GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonrevPar)];

            GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonadrDiff)] :=
               GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonadrBase)] - GroupSummaryValues[ADataGroupIndex, lSummaryItems.IndexOfItemLink(tvComparisonadr)];
          end;
        end;
      finally
        Records.Free;
      end;
   end;

    procedure CalcGroupSummariesByDataGroupIndex(ADataGroupIndex: Integer);
    var
      i : integer;
    begin
      with ASender.DataController.Groups do
      begin
        if Level[ADataGroupIndex] >= GroupingItemCount - 1 then
          Exit;

        for i := 0 to ChildCount[ADataGroupIndex] - 1 do
          begin
            CalcGroupSummary(ChildDataGroupIndex[ADataGroupIndex, i]);
            CalcGroupSummariesByDataGroupIndex(ChildDataGroupIndex[ADataGroupIndex, i]);
          end;
      end;
    end;

begin
  if (FDataLoadingThreads = 0) and (aSender.DataController.RecordCount > 0) then
    CalcGroupSummariesByDataGroupIndex(-1);
end;

end.

