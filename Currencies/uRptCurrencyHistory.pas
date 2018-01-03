unit uRptCurrencyHistory;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Data.DB, kbmMemTable, cxClasses, cxPropertiesStore, Vcl.StdCtrls, sRadioButton,
  acPNG, sLabel, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, sGroupBox, sButton, Vcl.ExtCtrls, sPanel,
  uDImages, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinsdxStatusBarPainter, cxStyles,
  dxSkinscxPCPainter, cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, cxDBData, cxGridLevel,
  cxGridCustomTableView, cxGridTableView, cxGridBandedTableView, cxGridDBBandedTableView, cxGridCustomView, cxGrid,
  cxGridDBTableView, Vcl.Grids, Vcl.DBGrids, Vcl.Menus, cxTimeEdit, dxPSGlbl, dxPSUtl, dxPSEngn, dxPrnPg,
  dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns, dxPSPDFExportCore, dxPSPDFExport,
  cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon, dxPScxPageControlProducer, dxPScxGridLnk,
  dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers, dxSkinsdxBarPainter, dxSkinsdxRibbonPainter,
  dxPScxCommon, dxPSCore, dxStatusBar
  , uCurrencyHandler, AdvSmoothProgressBar, Vcl.ComCtrls, sStatusBar, cxTextEdit, sEdit, Vcl.Buttons, sSpeedButton
  , uRoomerForm, cxCalendar, cxCalc, cxCheckBox
   ;

type
  TfrmCurrencyHistory = class(TfrmBaseRoomerForm)
    kbmCurrencyhistory: TkbmMemTable;
    dsData: TDataSource;
    pnlTop: TsPanel;
    btnExcel: TsButton;
    grCurrencyHistory: TcxGrid;
    lvCurrencyHistory: TcxGridLevel;
    tvCurrencyHistory: TcxGridDBTableView;
    btnReport: TsButton;
    grdPrinter: TdxComponentPrinter;
    grdPrinterLink1: TdxGridReportLink;
    pnlFilter: TsPanel;
    cLabFilter: TsLabel;
    btnClear: TsSpeedButton;
    edFilter: TsEdit;
    timFilter: TTimer;
    kbmCurrencyhistoryLogtime: TDateTimeField;
    kbmCurrencyhistoryCurrency: TWideStringField;
    kbmCurrencyhistoryDescription: TWideStringField;
    kbmCurrencyhistoryRate: TFloatField;
    kbmCurrencyhistoryActive: TBooleanField;
    kbmCurrencyhistoryCurrencySign: TWideStringField;
    kbmCurrencyhistorylastUpdate: TDateTimeField;
    kbmCurrencyhistoryDisplayFormat: TWideStringField;
    kbmCurrencyhistoryDecimals: TIntegerField;
    kbmCurrencyhistoryAction: TWideStringField;
    tvCurrencyHistoryLogtime: TcxGridDBColumn;
    tvCurrencyHistoryCurrency: TcxGridDBColumn;
    tvCurrencyHistoryDescription: TcxGridDBColumn;
    tvCurrencyHistoryRate: TcxGridDBColumn;
    tvCurrencyHistoryActive: TcxGridDBColumn;
    tvCurrencyHistoryCurrencySign: TcxGridDBColumn;
    tvCurrencyHistorylastUpdate: TcxGridDBColumn;
    tvCurrencyHistoryDisplayFormat: TcxGridDBColumn;
    tvCurrencyHistoryDecimals: TcxGridDBColumn;
    tvCurrencyHistoryAction: TcxGridDBColumn;
    btnRefresh: TsButton;
    procedure btnExcelClick(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure kbmCurrencyhistoryAfterScroll(DataSet: TDataSet);
    procedure btnReportClick(Sender: TObject);
    procedure timFilterTimer(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure edFilterChange(Sender: TObject);
  private
    FCurrency: string;
    function ConstructSQL: string;
    procedure SetCurrency(const Value: string);
  protected
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
    procedure DoShow; override;
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    property Currency: string read FCurrency write SetCurrency;
  end;


/// <summary>
///   Global access point for showing the curerency history report form
/// </summary>
procedure ShowCurrencyHistory(const aCurrency: string);

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
  , uRptbViewer
  , uDataSetFilterUtils
  , uSQLUtils;

const

  cSQL = ' SELECT currencies_ID, '#10 +
          ' Currency, '#10 +
          ' Description, '#10 +
          ' AValue as Rate, '#10 +
          ' SellValue, '#10 +
          ' Active, '#10 +
          ' CurrencySign, '#10 +
          ' lastUpdate, '#10 +
          ' displayFormat, '#10 +
          ' decimals, '#10 +
          ' guid, '#10 +
          ' action, '#10 +
          ' logtime '#10 +
          ' FROM currencies_history '#10 +
          ' WHERE currency = %s '#10 +
          ' ORDER by logtime desc'#10 ;

procedure ShowCurrencyHistory(const aCurrency: string);
begin
  with TfrmCurrencyHistory.Create(nil) do
    try
      Currency := aCurrency;
      ShowModal;
    finally
      Free;
    end;
end;

procedure TfrmCurrencyHistory.btnClearClick(Sender: TObject);
begin
  edFilter.Text := '';
end;

procedure TfrmCurrencyHistory.btnExcelClick(Sender: TObject);
var
  sFilename : string;
  s         : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_CurrencyHistoryList';
  ExportGridToExcel(sFilename, grCurrencyHistory, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmCurrencyHistory.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
end;

procedure TfrmCurrencyHistory.btnReportClick(Sender: TObject);
var
  lTitle: string;
begin
  lTitle := Format('%s for %s', [Caption, Currency]);
  grdPrinter.PrintTitle := lTitle;
  grdPrinterLink1.ReportTitle.Text := lTitle;
  grdPrinter.Print(True, nil, grdPrinterLink1);
end;

function TfrmCurrencyHistory.ConstructSQL: string;
begin
  Result := Format(cSQL, [_db(FCurrency)]);
  CopyToClipboard(Result);
end;

constructor TfrmCurrencyHistory.Create(aOwner: TComponent);
begin
  inherited;
end;

destructor TfrmCurrencyHistory.Destroy;
begin
  inherited;
end;

procedure TfrmCurrencyHistory.DoShow;
begin
  inherited;
end;

procedure TfrmCurrencyHistory.edFilterChange(Sender: TObject);
begin
  if edFilter.Text = '' then
  begin
    StopFilter(kbmCurrencyhistory, timFilter, tvCurrencyHistory);
  end else
  begin
    applyFilter(kbmCurrencyhistory, edFilter.Text, timFilter, tvCurrencyHistory);
  end;
end;

procedure TfrmCurrencyHistory.kbmCurrencyhistoryAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmCurrencyHistory.SetCurrency(const Value: string);
begin
  FCurrency := Value;
end;

procedure TfrmCurrencyHistory.DoLoadData;
var
  rset: TRoomerDataset;
begin
  kbmCurrencyhistory.DisableControls;
  try
    rset := CreateNewDataSet;
    try
      hData.rSet_bySQL(rset, ConstructSQL);
      rset.First;
      if not kbmCurrencyhistory.Active then
        kbmCurrencyhistory.Open;
      LoadKbmMemtableFromDataSetQuiet(kbmCurrencyhistory,rset,[]);
    finally
      FreeAndNil(rset);
    end;

    kbmCurrencyhistory.First;

  finally
    kbmCurrencyhistory.EnableControls;
  end;
end;

procedure TfrmCurrencyHistory.timFilterTimer(Sender: TObject);
begin
  timFilter.Enabled := False;
  kbmCurrencyhistory.filtered := True;
  tvCurrencyHistory.DataController.Filter.Refresh;
end;

procedure TfrmCurrencyHistory.DoUpdateControls;
var
  lDataAvailable: boolean;
begin
  if LoadingData then
    Exit;

  inherited;

  lDataAvailable := kbmCurrencyhistory.Active and NOT kbmCurrencyhistory.Eof;
  btnExcel.Enabled := lDataAvailable;
  btnReport.Enabled := lDataAvailable;
end;


end.
