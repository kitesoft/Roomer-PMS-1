unit uDailyTotalsReport;

interface

uses
  Windows,
  Messages,
  SysUtils,
  Variants,
  Classes,
  Graphics,
  Controls,
  Forms,
  Dialogs,
  StdCtrls,
  ExtCtrls,

  dateUtils,
  Menus,
  shellapi,
  DB,
  ADODB,

  _glob,
  hData,
  ug,
  dxCore,
  cxGridExportLink,
  cxGraphics,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  cxControls,
  cxContainer,
  cxEdit,
  cxTextEdit,
  cxMaskEdit,
  cxDropDownEdit,
  cxButtons,
  cxPCdxBarPopupMenu,
  cxGroupBox,
  dxStatusBar,
  cxPC,
  cxStyles,
  cxCustomData,
  cxFilter,
  cxData,
  cxDataStorage,
  cxDBData,
  cxClasses,
  cxCustomPivotGrid,
  cxDBPivotGrid,
  cxGridLevel,
  cxGridCustomView,
  cxGridCustomTableView,
  cxGridTableView,
  cxGridDBTableView,
  cxGrid,
  cxLabel,
  dxmdaset,
  cxPivotGridCustomDataSet,
  cxPivotGridSummaryDataSet,
  cxRadioGroup,
  cxCurrencyEdit,
  cxCalc,
  cxGridChartView,
  cxGridDBChartView,
  cxNavigator,

  ppVar,
  ppCtrls,
  ppPrnabl,
  ppClass,
  ppBands,
  ppCache,
  ppDB,
  ppDesignLayer,
  ppParameter,
  ppDBPipe,
  ppComm,
  ppRelatv,
  ppProd,
  ppReport,
  ppStrtch,
  ppSubRpt,
  ppPageBreak,
  cxCheckBox,

  //fix wwdbdatetimepicker,
  kbmMemTable, AdvEdit, AdvEdBtn, PlannerDatePicker
  , uUtils
  , cmpRoomerDataSet
  , cmpRoomerConnection, dxSkinsCore, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin, dxSkinOffice2013White,
  dxSkinsDefaultPainters, dxSkinscxPCPainter, dxSkinsdxStatusBarPainter, cxPropertiesStore, sLabel, sGroupBox, sCheckBox, sPanel,
  Vcl.ComCtrls, sPageControl, sButton, Vcl.Mask, sMaskEdit, sCustomComboEdit, sTooledit, sStatusBar, sComboBox, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld,
  dxSkinBlack, dxSkinBlue, dxSkinBlueprint, dxSkinDarkRoom, dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast,
  dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky, dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black, dxSkinOffice2007Blue,
  dxSkinOffice2007Green, dxSkinOffice2007Pink, dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue, dxSkinOffice2010Silver,
  dxSkinPumpkin, dxSkinSeven, dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver, dxSkinSpringTime, dxSkinStardust,
  dxSkinSummer2008, dxSkinValentine, dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue,
  uRoomerForm, dxPScxCommon, dxPScxGridLnk

  ;

type
  TfrmDailyTotalsReport = class(TfrmBaseRoomerForm)
    pageMain: TsPageControl;
    sheetMain: TsTabSheet;
    Panel1: TsPanel;
    btnExcelS1: TsButton;
    Panel3: TsPanel;
    gbxPeriodSelection: TsGroupBox;
    btnRefresh: TsButton;
    mTrxList: TdxMemData;
    mTrxListDS: TDataSource;
    tvTrxList : TcxGridDBTableView;
    lvTrxList : TcxGridLevel;
    gTrxList : TcxGrid;
    StoreMain: TcxPropertiesStore;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
    mTrxListdate: TDateField;
    mTrxListDEF: TIntegerField;
    mTrxListTNT: TIntegerField;
    mTrxListCXL: TIntegerField;
    mTrxListOPT: TIntegerField;
    mTrxListTotalACC: TFloatField;
    mTrxListTotalACCWOVat: TFloatField;
    mTrxListTotalAUX: TFloatField;
    mTrxListTotalAUXWOVat: TFloatField;
    mTrxListTotal: TFloatField;
    mTrxListTotalWOVat: TFloatField;
    tvTrxListRecId: TcxGridDBColumn;
    tvTrxListdate: TcxGridDBColumn;
    tvTrxListDEF: TcxGridDBColumn;
    tvTrxListTNT: TcxGridDBColumn;
    tvTrxListCXL: TcxGridDBColumn;
    tvTrxListOPT: TcxGridDBColumn;
    tvTrxListTotalACC: TcxGridDBColumn;
    tvTrxListTotalACCWOVat: TcxGridDBColumn;
    tvTrxListTotalAUX: TcxGridDBColumn;
    tvTrxListTotalAUXWOVat: TcxGridDBColumn;
    tvTrxListTotal: TcxGridDBColumn;
    tvTrxListTotalWOVat: TcxGridDBColumn;
    procedure btnRefreshClick(Sender : TObject);
    procedure FormClose(Sender : TObject; var Action : TCloseAction);
    procedure btnExcelS1Click(Sender : TObject);
    procedure FormCreate(Sender: TObject);
    procedure cbxYearCloseUp(Sender: TObject);
    procedure mTrxListAfterScroll(DataSet: TDataSet);
    procedure tvTrxListPriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
  private
    { Private declarations }
  protected
    procedure DoShow; override;
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
  public
    { Public declarations }
  end;

procedure ShowDailySalesReport;

implementation

uses
    uD
  , uReservationProfile
  , uFinishedInvoices2
  , uGuestProfile2
  , uRptbViewer
  , uSqlDefinitions
  , uAppGlobal
  , uDImages
  , uMain
  , uSQLUtils
  , uFrmOptInMessage
  , uDateUtils
  , ComObj
  , MSXML
  ;


{$R *.dfm}

procedure ShowDailySalesReport;
var _frmDailyTotalsReport : TfrmDailyTotalsReport;
begin
  _frmDailyTotalsReport := TfrmDailyTotalsReport.Create(nil);
  try
    _frmDailyTotalsReport.ShowModal;
  finally
    _frmDailyTotalsReport.Free;
  end;
end;

procedure TfrmDailyTotalsReport.btnExcelS1Click(Sender : TObject);
var
  sFilename : string;
  s : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_FinanceMutations';
  try
    ExportGridToExcel(sFilename, gTrxList, true, true, true,'xls');
    ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
  except
    on e: exception do
    begin
      showMessage('Exporting '+sFilename+' '+e.message);
    end;
  end;
end;


procedure TfrmDailyTotalsReport.mTrxListAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmDailyTotalsReport.btnRefreshClick(Sender : TObject);
begin
  RefreshData;
end;

procedure TfrmDailyTotalsReport.DoLoadData;
var
  xml : string;
  sFrom, sTo : String;
  rSet : TRoomerDataSet;
begin
  screen.Cursor := crHourGlass;
  mTrxList.DisableControls;
  try
    d.roomerMainDataSet.SetTimeZoneComparedToUTC('');
    sFrom := format('%sT00:00:01', [uDateUtils.dateToSqlString(dtDateFrom.Date)]);
    sTo := format('%sT23:59:59', [uDateUtils.dateToSqlString(dtDateTo.Date)]);

    xml := d.roomerMainDataSet.downloadUrlAsString(  d.roomerMainDataSet.RoomerUri + format('statistics/dailysales?startdate=%s&enddate=%s',
      [sFrom, sTo]));

    rSet := CreateNewDataSet;
    rSet.OpenDataset(xml);

    rSet.First;
    while NOT rSet.Eof  do
    begin
      mTrxList.Append;

      mTrxListdate.AsDateTime := rSet['BusinessDate'];
      mTrxListDEF.AsInteger := rSet['DEF'];
      mTrxListTNT.AsInteger := rSet['TNT'];
      mTrxListCXL.AsInteger := rSet['CXL'];
      mTrxListOPT.AsInteger := rSet['OPT'];
      mTrxListTotalACC.AsFloat := rSet['TotalACC'];
      mTrxListTotalACCWOVat.AsFloat := rSet['TotalACCWOVat'];
      mTrxListTotalAUX.AsFloat := rSet['TotalAUX'];
      mTrxListTotalAUXWOVat.AsFloat := rSet['TotalAUXWOVat'];
      mTrxListTotal.AsFloat := rSet['Total'];
      mTrxListTotalWOVat.AsFloat := rSet['TotalWOVat'];

      mTrxList.Post;

      rSet.Next;
    end;

    mTrxList.First;
  finally
    mTrxList.EnableControls;
    d.roomerMainDataSet.SetTimeZoneComparedToUTC('UTC');
    screen.Cursor := crDefault;
  end;
end;


procedure TfrmDailyTotalsReport.tvTrxListPriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmDailyTotalsReport.cbxYearCloseUp(Sender: TObject);
begin
  UpdateControls;
end;

procedure TfrmDailyTotalsReport.FormClose(Sender : TObject; var Action : TCloseAction);
begin
  if frmRptbViewer <> nil then
    freeandNil(frmRptbViewer);
end;

procedure TfrmDailyTotalsReport.FormCreate(Sender: TObject);
begin
  dtDateFrom.Date := Trunc(now);
  dtDateTo.Date := Trunc(now);
end;

procedure TfrmDailyTotalsReport.DoShow;
begin
  inherited;
end;

procedure TfrmDailyTotalsReport.DoUpdateControls;
begin
  btnExcelS1.Enabled := NOT (mTrxList.Eof OR mTrxList.Bof);
end;

// -------------------------------------------------------------------------------
//
// Buttons
//
//
// --------------------------------------------------------------------------------

end.
