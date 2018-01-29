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
  , AdvSmoothProgressBar, Vcl.ComCtrls, sStatusBar, cxTextEdit, sEdit, Vcl.Buttons, sSpeedButton
  , uRoomerForm, cxCalendar, cxCalc, cxCheckBox, dxmdaset
   ;

type
  TfrmCurrencyHistory = class(TfrmBaseRoomerForm)
    m_Currencyhistory: TdxMemData;
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
    m_CurrencyhistoryLogtime: TDateTimeField;
    m_CurrencyhistoryCurrency: TWideStringField;
    m_CurrencyhistoryDescription: TWideStringField;
    m_CurrencyhistoryRate: TFloatField;
    m_CurrencyhistoryActive: TBooleanField;
    m_CurrencyhistoryCurrencySign: TWideStringField;
    m_CurrencyhistorylastUpdate: TDateTimeField;
    m_CurrencyhistoryDisplayFormat: TWideStringField;
    m_CurrencyhistoryDecimals: TIntegerField;
    m_CurrencyhistoryAction: TWideStringField;
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
    procedure m_CurrencyhistoryAfterScroll(DataSet: TDataSet);
    procedure btnReportClick(Sender: TObject);
  private
    FCurrency: string;
    FOrigCaption: string;
    function ConstructSQL: string;
    procedure SetCurrency(const Value: string);
  protected
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
    procedure DoShow; override;
  public
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

procedure TfrmCurrencyHistory.DoShow;
begin
  FOrigCaption := Caption;
  inherited;
  RefreshData;
end;

procedure TfrmCurrencyHistory.m_CurrencyhistoryAfterScroll(DataSet: TDataSet);
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
  m_Currencyhistory.DisableControls;
  try
    rset := CreateNewDataSet;
    try
      hData.rSet_bySQL(rset, ConstructSQL);
      rset.First;
      m_Currencyhistory.Close;
      m_Currencyhistory.LoadFromDataSet(rset);
    finally
      FreeAndNil(rset);
    end;

    m_Currencyhistory.First;

  finally
    m_Currencyhistory.EnableControls;
  end;
end;

procedure TfrmCurrencyHistory.DoUpdateControls;
var
  lDataAvailable: boolean;
begin
  Caption := FOrigCaption + Format(' - (%s)', [FCurrency]);

  if LoadingData then
    Exit;

  inherited;

  lDataAvailable := m_Currencyhistory.Active and NOT m_Currencyhistory.Eof;
  btnExcel.Enabled := lDataAvailable;
  btnReport.Enabled := lDataAvailable;
end;


end.
