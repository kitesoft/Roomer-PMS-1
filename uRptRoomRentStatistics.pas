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
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, dxPSCore, htmlhint, dxScreenTip, dxCustomHint, cxHint,
  uFraDateFromToSelection
  ;

type
  TfrmRptRoomRentStatistics = class(TForm)
    Panel3: TsPanel;
    btnRefresh: TsButton;
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
    btnReportStats: TsButton;
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
    grdPrinterLinkComparison: TdxGridReportLink;
    grdPrinterLinkStats: TdxGridReportLink;
    kbmComparisonweekdayBase: TStringField;
    kbmComparisonweekday: TStringField;
    fraDateFromToSelection: TfraDateFromToSelection;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure btnGuestsExcelClick(Sender: TObject);
    procedure tvStatsGetDefaultCurrencyProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure sButton2Click(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure btnComparisonReportClick(Sender: TObject);
    procedure tvStatsHideZeroValues(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure ppHeaderBand1BeforePrint(Sender: TObject);
    procedure tvStatsDataControllerSummaryAfterSummary(ASender: TcxDataSummary);
    procedure rptStatsBeforePrint(Sender: TObject);
    procedure cbxComparisonPeriodChange(Sender: TObject);
    procedure kbmComparisonCalcFields(DataSet: TDataSet);
    procedure clbComparisonDataSelectionClickCheck(Sender: TObject);
    procedure btnComparisonExcelClick(Sender: TObject);
    procedure tvComparisonDataControllerSummaryAfterSummary(ASender: TcxDataSummary);
    procedure btnReportStatsClick(Sender: TObject);
    procedure GetWeekdayFilterValues(Sender: TcxCustomGridTableItem;
      AValueList: TcxDataFilterValueList);
  private
    { Private declarations }

    FDataLoadingThreads: integer;
    FCompareData: TRoomRentCompareDataSet;
    FBaseBandOrigCaption: string;
    FCompareBandOrigCaption: string;
    FLoadingData: boolean;

    function GetFooterSummaryValueOrZero(aColumn: TcxGridDBBandedColumn): variant;

    procedure SetFooterSummaryValue(aColumn: TcxGridDBBandedColumn; aValue: Variant);
    function GetFooterSummaryText(aColumn: TcxGridDBBandedColumn): string;
    procedure LoadDataInDataset(aDataset: TDataSet; aStatistics: THotelStatisticsList; aComparisonFieldsOnly: boolean = false);
    procedure LoadBaseDataInComparisonDataset(aOffset: integer);
    procedure LoadBaseDataInDataset(aStatistics: THotelStatisticsList);
    procedure LoadComparisonDataInDataset(aStatistics: THotelStatisticsList);
    procedure UpdateCompareDataColumns;
    procedure CalculateTvComparisonFooterSummary(RevenueCol, SellableCol, SoldCol, OccCol, RevparCol, AdrCOl: TcxGridDBBandedColumn);
    procedure CalculateTvComparisonDiffFooterSummary;
    procedure UpdateControls;
    procedure SetLoadingData(const Value: boolean);
    function GroupingByMonth: boolean;

    property LoadingData: boolean read FLoadingData write SetLoadingData;
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

  cDefaultIncludeddReservationStates: TReservationStateSet = [TReservationState.rsReservation, TReservationState.rsGuests, TReservationState.rsDeparted,
                                                              TReservationState.rsAllotment, tReservationState.rsBlocked];

function ShowRoomRentStatistics : boolean;
var
  frm: TfrmRptRoomRentStatistics;
begin
  frm := TfrmRptRoomRentStatistics.Create(nil);
  try
    Result := frm.ShowModal = mrOk;
    Screen.Cursor := crDefault;
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
  if not kbmComparisonADateBase.IsNUll then
  begin
    if kbmComparisontotalSellableRoomsBase.AsInteger <> 0 then
    begin
      kbmComparisonoccBase.asFloat := kbmComparisonsoldRoomsBase.AsInteger / kbmComparisontotalSellableRoomsBase.AsInteger * 100;
      kbmComparisonrevParBase.asFloat := kbmComparisonrevenueBase.asFloat / kbmComparisontotalSellableRoomsBase.AsInteger;
    end
    else
    begin
      kbmComparisonoccBase.asFloat := 0;
      kbmComparisonrevParBase.asFloat := 0;
    end;

    if kbmComparisonsoldRoomsBase.AsInteger <> 0 then
      kbmComparisonadrBase.asFloat := kbmComparisonrevenueBase.AsFloat / kbmComparisonsoldRoomsBase.AsInteger
    else
      kbmComparisonadrBase.asFloat := 0;
  end;

  if not kbmComparisonADate.IsNUll then
  begin
    if kbmComparisontotalSellableRooms.AsInteger <> 0 then
    begin
      kbmComparisonocc.asFloat := kbmComparisonsoldRooms.AsInteger / kbmComparisontotalSellableRooms.AsInteger * 100;
      kbmComparisonrevPar.asFloat := kbmComparisonrevenue.asFloat / kbmComparisontotalSellableRooms.AsInteger;
    end
    else
    begin
      kbmComparisonocc.asFloat := 0;
      kbmComparisonrevPar.asFloat := 0;
    end;

    if kbmComparisonsoldRooms.AsInteger <> 0 then
      kbmComparisonadr.asFloat := kbmComparisonrevenue.AsFloat / kbmComparisonsoldRooms.AsInteger
    else
      kbmComparisonadr.asFloat := 0;
  end;

  if not kbmComparisonADate.IsNull and not kbmComparisonADateBase.IsNull then
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


procedure TfrmRptRoomRentStatistics.SetLoadingData(const Value: boolean);
begin
  FLoadingData := Value;

  btnRefresh.Enabled := not FLoadingData;
  if FLoadingData then
    Screen.Cursor := crHourGlass
  else
    Screen.Cursor := crDefault;
end;

procedure TfrmRptRoomRentStatistics.tvComparisonDataControllerSummaryAfterSummary(ASender: TcxDataSummary);
begin
  CalculateTvComparisonFooterSummary(tvComparisonRevenueBase, tvComparisontotalSellableRoomsBase, tvComparisonsoldRoomsBase,
                                     tvComparisonOccBase, tvComparisonrevParBase, tvComparisonadrBase);
  CalculateTvComparisonFooterSummary(tvComparisonRevenue, tvComparisontotalSellableRooms, tvComparisonsoldRooms,
                                     tvComparisonOcc, tvComparisonrevPar, tvComparisonadr);

  CalculateTvComparisonDiffFooterSummary;
end;


procedure TfrmRptRoomRentStatistics.GetWeekdayFilterValues(Sender: TcxCustomGridTableItem;
  AValueList: TcxDataFilterValueList);
var
  i: integer;
begin
  aValueList.SortByDisplayText := false;
  for i := 1 to 7 do
    aValueList.Add(fviValue, FormatSettings.ShortDayNames[i], FormatSettings.LongDayNames[i], true);
end;

procedure TfrmRptRoomRentStatistics.CalculateTvComparisonDiffFooterSummary;
begin
  SetFooterSummaryValue(tvComparisonOccDiff, GetFooterSummaryValueOrZero(tvComparisonOccBase) - GetFooterSummaryValueOrZero(tvComparisonOcc));
  SetFooterSummaryValue(tvComparisonADRDiff, GetFooterSummaryValueOrZero(tvComparisonAdrBase) - GetFooterSummaryValueOrZero(tvComparisonAdr));
  SetFooterSummaryValue(tvComparisonRevparDiff, GetFooterSummaryValueOrZero(tvComparisonRevParBase) - GetFooterSummaryValueOrZero(tvComparisonrevPar));
end;

procedure TfrmRptRoomRentStatistics.CalculateTvComparisonFooterSummary(RevenueCol, SellableCol, SoldCol, OccCol, RevparCol, AdrCOl: TcxGridDBBandedColumn);
var
  lSoldRooms: integer;
  lSellableRooms: integer;
  lRevenue: double;

begin
  lRevenue :=  GetFooterSummaryValueOrZero(RevenueCol);
  lSellableRooms := GetFooterSummaryValueOrZero(SellableCol);
  lSoldRooms := GetFooterSummaryValueOrZero(SoldCol);

  if lSellableRooms <> 0 then
  begin
    SetFooterSummaryValue(OccCol, 100 * lSoldRooms / lSellableRooms);
    SetFooterSummaryValue(RevparCol, lRevenue / lSellableRooms);
  end
  else
  begin
    SetFooterSummaryValue(OccCol, 0);
    SetFooterSummaryValue(RevparCol, 0);
  end;

  // ADR
  if lSoldRooms <> 0 then
    SetFooterSummaryValue(AdrCOl, lRevenue / lSoldRooms)
  else
    SetFooterSummaryValue(AdrCOl, 0);

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
  ExportGridToExcel(sFilename, grdComparison, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmRptRoomRentStatistics.UpdateControls;
begin
  if pcMain.ActivePage = tsComparison then
  begin
    tvComparisonDateBaseDay.Visible := rgCompareOn.ItemIndex = 0;
    tvComparisonDateDay.Visible := rgCompareOn.ItemIndex = 0;

    if rgCompareOn.ItemIndex = 0 then
    begin
      TcxCustomDateEditProperties( tvComparisonaDateBase.Properties).DisplayFormat := FormatSettings.ShortDateFormat;
      TcxCustomDateEditProperties( tvComparisonADate.Properties).DisplayFormat := FormatSettings.ShortDateFormat;
    end
    else
    begin
      TcxCustomDateEditProperties( tvComparisonaDateBase.Properties).DisplayFormat := 'mmm yyyy';
      TcxCustomDateEditProperties( tvComparisonaDate.Properties).DisplayFormat := 'mmm yyyy';
    end;
  end;

end;


procedure TfrmRptRoomRentStatistics.btnGuestsExcelClick(Sender: TObject);
var
  sFilename : string;
  s         : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_StatData';
  ExportGridToExcel(sFilename, grStat, true, true, true);
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

  LoadingData := true;

  lExcludedReservationStates := cAllReservationStatesSet;
  for i:= 0 to clbIncludedStates.Items.Count-1 do
    if clbIncludedStates.Checked[i] then
      Exclude(lExcludedReservationStates, TReservationState(Integer(clbIncludedStates.Items.Objects[i])));

  kbmStat.Close;
  kbmComparison.Close;

  inc(FDataLoadingThreads);
  THotelStatisticsMobileAPICallerThreaded.GetRoomRentStatistics(fraDateFromToSelection.StartDate, fraDateFromToSelection.EndDate, lExcludedReservationStates, LoadBaseDataInDataset);
  if pcMain.ActivePage = tsComparison then
  begin
    inc(FDataLoadingThreads);

    if fraDateFromToSelection.IsFullMonthSelected then  // limit compare data to end of year / month
      lCompareToDate := dtComparisonStart.Date.EndOfMonth
    else  // Manually selected period, just calculated based on number of days
      lCompareToDate := dtComparisonStart.Date.AddDays(fraDateFromToSelection.DayCount);

    THotelStatisticsMobileAPICallerThreaded.GetRoomRentStatistics(dtComparisonStart.Date,
                                                                  lCompareToDate,
                                                                  lExcludedReservationStates,
                                                                  LoadComparisonDataInDataset);

    tvComparison.Bands[0].Caption := FBaseBandOrigCaption + Format(cBandCaptionFormat, [fraDateFromToSelection.dtDateFrom.Text, fraDateFromToSelection.dtDateTo.Text]);
    tvComparison.Bands[1].Caption := FCompareBandOrigCaption +
                                      Format(cBandCaptionFormat, [dtComparisonStart.Text,
                                                                  FormatDateTime(FormatSettings.ShortDateFormat, lCompareToDate)]);
  end;

  UpdateControls;

end;

procedure TfrmRptRoomRentStatistics.btnReportStatsClick(Sender: TObject);
begin
  grdPrinter.Print(True, nil, grdPrinterLinkStats);
end;

procedure TfrmRptRoomRentStatistics.LoadBaseDataInDataset(aStatistics: THotelStatisticsList);
begin
  dec(FDataLoadingThreads);
  LoadDataInDataset(kbmStat, aStatistics);
  if pcMain.ActivePage = tsComparison then
  begin
    if GroupingByMonth then
      LoadBaseDataInComparisonDataset((dtComparisonStart.Date.Year - fraDateFromToSelection.StartDate.Year) * 12 +
                                      (dtComparisonStart.Date.Month- fraDateFromToSelection.StartDate.Month))
    else
      LoadBaseDataInComparisonDataset(trunc(dtComparisonStart.Date - fraDateFromToSelection.StartDate));
    kbmStat.Close; // Avoid display of aggregated data when switching back to stats tab
  end;

  LoadingData := (FDataLoadingThreads <> 0);
end;

procedure TfrmRptRoomRentStatistics.LoadComparisonDataInDataset(aStatistics: THotelStatisticsList);
begin
  dec(FDataLoadingThreads);
  LoadDataInDataset(kbmComparison, aStatistics, true);
  LoadingData := (FDataLoadingThreads <> 0);
end;

procedure TfrmRptRoomRentStatistics.LoadDataInDataset(aDataset: TDataSet; aStatistics: THotelStatisticsList; aComparisonFieldsOnly: boolean);
var
  lStat: TSingleDateStatistics;
  lCurrentDate: TDateTime;
begin

  aDataset.DisableControls;
  try
    aDataset.Open;

    for lStat in aStatistics.StatisticsPerDateList do
    begin
      lCurrentDate := lStat.Date;
      if GroupingByMonth then
        lCurrentDate := lCurrentDate.StartOfMonth;

      if aDataset.Locate('aDate', lCurrentDate, []) then
        aDataset.Edit
      else
      begin
        aDataSet.Append;
        aDataset.FieldByName('ADate').AsDateTime := lCurrentDate;
        aDataset.FieldByName('weekday').AsString := lCurrentdate.ToString('ddd');
        aDataset.FieldByName('minRate').asFloat := lStat.Statistic['MINRATE'].Value;
        aDataset.FieldByName('maxRate').asFloat := lStat.Statistic['MAXRATE'].Value;
      end;
      try
        aDataset.FieldByName('revenue').asFloat := aDataset.FieldByName('revenue').asFloat  + lStat.Statistic['REVENUE'].Value;
        aDataset.FieldByName('currency').asString := RoomerCurrencyManager.DefaultCurrency;
        aDataset.FieldByName('totalDiscount').asFloat := aDataset.FieldByName('totalDiscount').asFloat + lStat.Statistic['DISCOUNT'].Value;
        aDataset.FieldByName('maxRate').asFloat := max(aDataset.FieldByName('maxRate').asFloat, lStat.Statistic['MAXRATE'].Value);
        aDataset.FieldByName('minRate').asFloat := min(aDataset.FieldByName('minRate').asFloat, lStat.Statistic['MINRATE'].Value);
        aDataset.FieldByName('totalGuests').AsInteger := aDataset.FieldByName('totalGuests').AsInteger + trunc(lStat.Statistic['GUESTCOUNT'].Value);
        aDataset.FieldByName('totalSellableRooms').AsInteger := aDataset.FieldByName('totalSellableRooms').AsInteger + trunc(lStat.Statistic['TOTAL_SELLABLE_ROOMS'].Value);
        aDataset.FieldByName('oooROoms').AsInteger := aDataset.FieldByName('oooROoms').AsInteger  + trunc(lStat.Statistic['OOOROOMS'].Value);
        aDataset.FieldByName('soldRooms').AsInteger := aDataset.FieldByName('soldRooms').AsInteger + trunc(lStat.Statistic['ROOMS_SOLD'].Value);
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
        aDataSet.Post;

        aDataset.Edit;
        if aDataset.FieldByName('totalSellableRooms').AsInteger <> 0 then
        begin
          aDataset.FieldByName('occ').asFloat := aDataset.FieldByName('soldRooms').AsInteger / aDataset.FieldByName('totalSellableRooms').AsInteger * 100;
          aDataset.FieldByName('revPar').asFloat := aDataset.FieldByName('revenue').AsFloat / aDataset.FieldByName('totalSellableRooms').AsInteger;
        end
        else
        begin
          aDataset.FieldByName('occ').asFloat := 0;
          aDataset.FieldByName('revPar').asFloat := 0;
        end;

        if aDataset.FieldByName('soldRooms').AsInteger <> 0 then
          aDataset.FieldByName('adr').asFloat := aDataset.FieldByName('revenue').AsFloat / aDataset.FieldByName('soldRooms').AsInteger
        else
          aDataset.FieldByName('adr').asFloat := 0;

        aDataset.Post;
      except
        aDataset.Cancel;
        raise;
      end;

    end;
    aDataset.First;

  finally
    aDataset.EnableControls;
  end;
end;

function TfrmRptRoomRentStatistics.GroupingByMonth: boolean;
begin
  Result := (pcMain.ActivePage = tsComparison) and (rgCompareOn.ItemIndex = 1);
end;

procedure TfrmRptRoomRentStatistics.LoadBaseDataInComparisonDataset(aOffset: integer);
var
  lCurrentDate: TDateTime;
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
      if GroupingByMonth then
        lCurrentDate := kbmStat.FieldByName('adate').asDateTime.StartOfMonth.AddMonths(aOffset)
      else
        lCurrentDate := kbmStat.FieldByName('adate').asDateTime.AddDays(aOffset);

      if kbmComparison.Locate('aDate', lCurrentDate, []) then
        kbmComparison.Edit
      else
      begin
        kbmComparison.Append;
        if not fraDateFromToSelection.IsFullMonthSelected or (lCurrentDate.Month = dtComparisonStart.Date.Month) then // dont roll over into next month
        begin
          kbmComparisonADate.AsDateTime := lCurrentDate;
          kbmComparisonweekday.AsString := lCurrentDate.ToString('ddd');
        end;
        kbmComparisonmaxRateBase.AsFloat := kbmStat.FieldByName('maxRate').asFloat;
        kbmComparisonminRateBase.AsFloat := kbmStat.FieldByName('minRate').asFloat;
      end;

      try
        kbmComparisonaDateBase.AsDateTime := kbmStat.FieldByName('adate').asDateTime;
        kbmComparisonweekdayBase.AsString := kbmComparisonaDateBase.AsDateTime.ToString('ddd');
        kbmComparisonrevenueBase.asFloat :=                     kbmComparisonrevenueBase.asFloat + kbmStat.FieldByName('revenue').asFloat;
        kbmComparisontotalDiscountBase.asFloat :=               kbmComparisontotalDiscountBase.asFloat + kbmStat.FieldByName('totalDiscount').asFloat;
        kbmComparisonmaxRateBase.asFloat :=                     max(kbmComparisonmaxRateBase.asFloat, kbmStat.FieldByName('maxRate').asFloat);
        kbmComparisonminRateBase.asFloat :=                     min(kbmComparisonminRateBase.asFloat, kbmStat.FieldByName('minRate').asFloat);
        kbmComparisontotalGuestsBase.AsInteger :=               kbmComparisontotalGuestsBase.AsInteger + kbmStat.FieldByName('totalGuests').AsInteger;
        kbmComparisontotalSellableRoomsBase.AsInteger :=        kbmComparisontotalSellableRoomsBase.AsInteger + kbmStat.FieldByName('totalSellableRooms').AsInteger;
        kbmComparisonoooROomsBase.AsInteger :=                  kbmComparisonoooROomsBase.AsInteger + kbmStat.FieldByName('oooROoms').AsInteger;
        kbmComparisonsoldRoomsBase.AsInteger :=                 kbmComparisonsoldRoomsBase.AsInteger +  kbmStat.FieldByName('soldRooms').AsInteger;
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

procedure TfrmRptRoomRentStatistics.btnComparisonReportClick(Sender: TObject);
begin
  grdPrinter.Print(True, nil, grdPrinterLinkComparison);
end;

procedure TfrmRptRoomRentStatistics.cbxComparisonPeriodChange(Sender: TObject);
begin
  if cbxComparisonPeriod.Itemindex = -1 then
    Exit;

  case TRoomRentComparePeriod.FromItemIndex(cbxComparisonPeriod.ItemIndex) of
    TRoomRentComparePeriod.PreviousYear:     dtComparisonStart.Date := fraDateFromToSelection.StartDate.AddYears(-1);
    TRoomRentComparePeriod.PreviousMonth:    dtComparisonStart.Date := fraDateFromToSelection.StartDate.AddMonths(-1);
    TRoomRentComparePeriod.NextYear:     dtComparisonStart.Date := fraDateFromToSelection.StartDate.AddYears(1);
    TRoomRentComparePeriod.NextMonth:    dtComparisonStart.Date := fraDateFromToSelection.StartDate.AddMonths(1);
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

procedure TfrmRptRoomRentStatistics.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self); PlaceFormOnVisibleMonitor(self);
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
    clbIncludedStates.Checked[i] := TReservationState(Integer(clbIncludedStates.Items.Objects[i])) in cDefaultIncludeddReservationStates;
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

  pcMain.ActivePage := tabStatGrid;
  fraDateFromToSelection.OndatesChanged := cbxComparisonPeriodChange;
end;

procedure TfrmRptRoomRentStatistics.ppHeaderBand1BeforePrint(Sender : TObject);
var
  s : string;
begin
  rlabFrom.Caption := FormatDateTime('ddddd', fraDateFromToSelection.StartDate);
  rlabTo.Caption := FormatDateTime('ddddd', fraDateFromToSelection.EndDate);
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


end.

