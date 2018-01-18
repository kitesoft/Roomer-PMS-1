unit uCurrencies;


//** gsgsgssgs

interface

uses
    Windows
  , Messages
  , SysUtils
  , Variants
  , system.uiTypes
  , Classes
  , Graphics
  , Controls
  , Forms
  , Dialogs
  , Menus
  , ImgList
  , StdCtrls
  , Mask
  , ExtCtrls
  , Grids
  , Buttons
  , shellapi
  , uDImages

  , ADODB
  , db
  , DBTables
  , DBCtrls
  , ComCtrls

  , hData
  , uAppGlobal
  , _glob
  , ug

  , dxCore
  , cxGridExportLink
  , cxGraphics
  , cxControls
  , cxLookAndFeels
  , cxLookAndFeelPainters
  , cxStyles
  , cxCustomData
  , cxFilter
  , cxData
  , cxDataStorage
  , cxEdit
  , cxNavigator
  , cxDBData
  , cxGridCustomTableView
  , cxGridTableView
  , cxGridDBTableView
  , cxGridLevel
  , cxClasses
  , cxGridCustomView
  , cxGrid
  , cxTextEdit
  , cxContainer
  , cxDBEdit
  , cxGridCardView
  , cxGridDBCardView
  , cxGridCustomLayoutView
  , dxLayoutContainer
  , cxGridLayoutView
  , cxGridDBLayoutView
  , cxSpinEdit
  , dxPSGlbl
  , dxPSUtl
  , dxPSEngn
  , dxPrnPg
  , dxBkgnd
  , dxWrap
  , dxPrnDev
  , dxPSCompsProvider
  , dxPSFillPatterns
  , dxPSEdgePatterns
  , dxPSPDFExportCore
  , dxPSPDFExport
  , cxDrawTextUtils
  , dxPSPrVwStd
  , dxPSPrVwAdv
  , dxPSPrVwRibbon
  , dxPScxPageControlProducer
  , dxPScxEditorProducers
  , dxPScxExtEditorProducers
  , dxPSCore
  , dxPScxGridLnk
  , dxPScxGridLayoutViewLnk
  , dxPScxCommon
  , dxmdaset
  , cxGridBandedTableView
  , cxGridDBBandedTableView
  , cxCalc
  , cxCustomPivotGrid

  , PrjConst
  , cmpRoomerDataSet
  , cmpRoomerConnection

  , sLabel
  , sCustomComboEdit
  , sComboBoxes
  , sComboEdit
  , sSpeedButton
  , sEdit
  , sCheckBox
  , sButton
  , sPanel
  , sStatusBar, dxSkinsCore, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin, dxSkinOffice2013White, dxSkinsDefaultPainters,
  dxSkinscxPCPainter, dxPScxPivotGridLnk, dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, cxPropertiesStore, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld,
  dxSkinBlack, dxSkinBlue, dxSkinBlueprint, dxSkinDarkRoom, dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast,
  dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky, dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black, dxSkinOffice2007Blue,
  dxSkinOffice2007Green, dxSkinOffice2007Pink, dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue, dxSkinOffice2010Silver,
  dxSkinPumpkin, dxSkinSeven, dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver, dxSkinSpringTime, dxSkinStardust,
  dxSkinSummer2008, dxSkinValentine, dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue, cxMaskEdit
  , uRoomerEditGridForm, cxCheckBox, System.Actions, Vcl.ActnList, uRoomerGridForm
  ;

type
  TfrmCurrencies = class(TfrmBaseRoomerEditGridForm)
    m_: TdxMemData;
    m_Currency: TWideStringField;
    m_Description: TWideStringField;
    mnuOther: TPopupMenu;
    mnuiPrint: TMenuItem;
    mnuiAllowGridEdit: TMenuItem;
    N2: TMenuItem;
    Export1: TMenuItem;
    mnuiGridToExcel: TMenuItem;
    mnuiGridToHtml: TMenuItem;
    mnuiGridToText: TMenuItem;
    mnuiGridToXml: TMenuItem;
    m_AValue: TFloatField;
    m_ID: TIntegerField;
    m_active: TBooleanField;
    m_displayformat: TWideStringField;
    m_decimals: TIntegerField;
    m_SellValue: TFloatField;
    m_CurrencySign: TWideStringField;
    btnHistory: TsButton;
    tvDataRecId: TcxGridDBBandedColumn;
    tvDataCurrency: TcxGridDBBandedColumn;
    tvDataDescription: TcxGridDBBandedColumn;
    tvDataAValue: TcxGridDBBandedColumn;
    tvDataactive: TcxGridDBBandedColumn;
    tvDatadisplayformat: TcxGridDBBandedColumn;
    tvDatadecimals: TcxGridDBBandedColumn;
    tvDataCurrencySign: TcxGridDBBandedColumn;
    tvDataID: TcxGridDBBandedColumn;
    tvDataSellValue: TcxGridDBBandedColumn;
    procedure FormCreate(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
    procedure btnInsertClick(Sender: TObject);
    procedure btnEditClick(Sender: TObject);
    procedure btnDeleteClick(Sender: TObject);
    procedure BtnOkClick(Sender: TObject);
    procedure btnCloseClick(Sender: TObject);
    procedure mnuiPrintClick(Sender: TObject);
    procedure mnuiAllowGridEditClick(Sender: TObject);
    procedure mnuiGridToExcelClick(Sender: TObject);
    procedure mnuiGridToHtmlClick(Sender: TObject);
    procedure mnuiGridToTextClick(Sender: TObject);
    procedure mnuiGridToXmlClick(Sender: TObject);
    procedure m_BeforePost(DataSet: TDataSet);
    procedure tvDataCurrencyPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption; var Error: Boolean);
    procedure edFilterChange(Sender: TObject);
    procedure tvDataDataControllerFilterChanged(Sender: TObject);
    procedure tvDataAValuePropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption; var Error: Boolean);
    procedure m_NewRecord(DataSet: TDataSet);
    procedure tvDataDblClick(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure chkActiveClick(Sender: TObject);
    procedure m_BeforeDelete(DataSet: TDataSet);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormShow(Sender: TObject);
    procedure btnHistoryClick(Sender: TObject);
    procedure dsDataStateChange(Sender: TObject);

  private
    { Private declarations }
    //**
    zAllowGridEdit   : boolean;
    zFilterOn        : boolean;
    procedure fillHolder;
    procedure changeAllowgridEdit;
    Procedure chkFilter;
    procedure applyFilter;
  protected
    procedure DoLoadData; override;
    procedure DoShow; override;
  public
    { Public declarations }
    zAct               : TActTableAction;
    zData              : recCurrencyHolder;


    embedded : Boolean;
    EmbedWindowCloseEvent : TNotifyEvent;

  end;

function Currencies(aMode: TRoomerGridFormMode; var theData : recCurrencyHolder; embedPanel : TsPanel = nil; WindowCloseEvent : TNotifyEvent = nil) : boolean;

var
  frmCurrencies: TfrmCurrencies;
  frmCurrenciesX: TfrmCurrencies;

implementation

uses
   uD
  , uSqlDefinitions
  , uUtils
  , uRoomerCurrencymanager, RoomerCurrencyEdit, uRptCurrencyHistory, uActivityLogs;

{$R *.dfm}

//////////////////////////////////////////////////////////////////////////////////////////////
//  unit global functions
//////////////////////////////////////////////////////////////////////////////////////////////

function Currencies(aMode: TRoomerGridFormMode; var theData : recCurrencyHolder; embedPanel : TsPanel = nil; WindowCloseEvent : TNotifyEvent = nil) : boolean;
var _frmCurrencies: TfrmCurrencies;
begin
  result := false;
  _frmCurrencies := TfrmCurrencies.Create(nil);
  try
    _frmCurrencies.zData := theData;
//    _frmCurrencies.zAct := act;
//    _frmCurrencies.embedded := (act = actNone) AND
//                                    (embedPanel <> nil);
//    _frmCurrencies.EmbedWindowCloseEvent := WindowCloseEvent;
//    if _frmCurrencies.embedded then
//    begin
//      _frmCurrencies.pnlHolder.parent := embedPanel;
//      embedPanel.Update;
//      frmCurrenciesX := _frmCurrencies;
//    end
//    else
//    begin
      _frmCurrencies.ShowModal(aMode);
      if _frmCurrencies.modalresult = mrOk then
      begin
        theData := _frmCurrencies.zData;
        result := true;
      end
      else
      begin
        theData.init;
      end;
//    end;
  finally
//    if (act <> actNone) OR
//      (embedPanel = nil) then
      freeandnil(_frmCurrencies);
  end;
end;


///////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////////////////////////////////

procedure  TfrmCurrencies.fillHolder;
begin
  zData.init;
  zData.ID                       := m_.fieldbyname('ID').asInteger;
  zData.currency                 := m_.fieldbyname('currency').asstring;
  zData.Description              := m_.fieldbyname('Description').asstring;
  zData.Value                    := m_.fieldbyname('Avalue').asFloat;
  zData.active                   := m_['Active'];
end;

procedure TfrmCurrencies.changeAllowgridEdit;
begin
  if zAllowGridEdit then
  begin
//    tvDataCurrency.Options.Editing       := true;
    tvDataDescription.Options.Editing    := true;
    tvDataAValue.Options.Editing         := true;
    tvDataActive.Options.Editing         := true;
  end else
  begin
    tvDataCurrency.Options.Editing       := false;
    tvDataDescription.Options.Editing    := false;
    tvDataAValue.Options.Editing         := false;
    tvDataActive.Options.Editing         := false;
  end;
end;


procedure TfrmCurrencies.chkActiveClick(Sender: TObject);
begin
  RefreshData;
end;

Procedure TfrmCurrencies.ChkFilter;
var
  sFilter : string;
  rC1,rc2   : integer;
begin
  sFilter := edFilter.text;
  rc1 := tvData.DataController.RecordCount;
  rc2 := tvData.DataController.FilteredRecordCount;

  zFilterON := rc1 <> rc2;
end;


procedure TfrmCurrencies.DoLoadData;
var
  s    : string;
  rSet : TRoomerDataSet;
  active : boolean;
  lID: integer;
begin
  inherited;

  if m_.Active then
    lId := m_ID.AsInteger
  else
    lId := 0;

  active := chkActive.Checked;
  rSet := CreateNewDataSet;
  try
		s := select_Currencies_fillGridFromDataset_byActive;
    if active then
      s := s + ' WHERE active';
    if rSet_bySQL(rSet,s) then
    begin
      if m_.active then m_.Close;
      m_.LoadFromDataSet(rSet);
      m_.Locate('ID', lid, []);
    end;
  finally
    freeandnil(rSet);
  end;

end;

/////////////////////////////////////////////////////////////
// Form actions
/////////////////////////////////////////////////////////////

procedure TfrmCurrencies.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  glb.EnableOrDisableTableRefresh('currencies', True);
end;

procedure TfrmCurrencies.FormCreate(Sender: TObject);
begin
  zAct        := actNone;
end;

procedure TfrmCurrencies.FormShow(Sender: TObject);
begin
  glb.EnableOrDisableTableRefresh('currencies', False);
  RefreshData;
end;

////////////////////////////////////////////////////////////////////////////////////////
// memory table
////////////////////////////////////////////////////////////////////////////////////////

procedure TfrmCurrencies.m_BeforeDelete(DataSet: TDataSet);
var
  s : string;
begin
  fillHolder;

  if hdata.CurrencyExistsInOther(zData.Currency) then
  begin
    Showmessage(format(GetTranslatedText('shExistsInRelatedDataCannotDelete'), ['Currency', zData.Description]));
    Abort;
    exit;
  end;

  s := '';
  s := s+GetTranslatedText('shDeleteCurrency')+' '+zData.Currency+' '+chr(10);
  s := s+GetTranslatedText('shContinue');

  if MessageDlg(s,mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    screen.Cursor := crHourGlass;
    try
      if Del_CurrencyBycurrency(zData.Currency) then
        AddCurrencyActivityLog(d.roomerMainDataSet.username, DELETE_CURRENCY, zData.Currency, zData.Value, 0, zData.active, zData.Decimals, '')
      else
        abort

    finally
      screen.Cursor := crDefault;
    end;
  end else
  begin
    abort;
  end;
end;

procedure TfrmCurrencies.m_BeforePost(DataSet: TDataSet);
var
  nID : integer;
begin
  if LoadingData then Exit;
  nId := 0;

  zData.init;
  zData.ReadFromDataset(dataset);

  if tvData.DataController.DataSource.State = dsEdit then
  begin
    if UPD_Currency(zData) then
    begin
      AddCurrencyActivityLog(d.roomerMainDataSet.username, CHANGE_CURRENCY, zData.Currency, m_AValue.OldValue, m_AValue.AsFloat, m_active.AsBoolean, m_decimals.AsInteger, '');
      glb.RefreshOnServerTimestamp;
    end else
    begin
      abort;
      exit;
    end;
  end;
  if tvData.DataController.DataSource.State = dsInsert then
  begin

    if dataset.FieldByName('Currency').AsString = ''  then
    begin
      //showmessage('Currency requierd - set value or use [ESC] to cancel ');
	    showmessage(GetTranslatedText('shTx_Currencies_Required'));
      tvData.GetColumnByFieldName('currency').Focused := True;
      abort;
      exit;
    end;

    if ins_Currency(zData,nID) then
    begin
      AddCurrencyActivityLog(d.roomerMainDataSet.username, ADD_CURRENCY, zData.Currency, 0, m_AValue.AsFloat, m_active.AsBoolean, m_decimals.AsInteger, '');
      m_.FieldByName('ID').AsInteger := nID;
      glb.RefreshOnServerTimestamp;
    end else
    begin
      abort;
      exit;
    end;
  end;
end;

procedure TfrmCurrencies.m_NewRecord(DataSet: TDataSet);
begin
  dataset.FieldByName('AValue').AsFloat := 1;
  dataset['Active'] := true;
  dataset['currency'] := '';
  dataset['description'] := '';
end;

procedure TfrmCurrencies.DoShow;
begin
  inherited;
  if ZAct = actLookup then
  begin
    mnuiAllowGridEdit.Checked := false;
    DialogButtons := mbOKCancel;
  end else
  begin
    mnuiAllowGridEdit.Checked := true;
    DialogButtons := [mbClose];
  end;
  //-C
  zAllowGridEdit := mnuiAllowGridEdit.Checked;
  changeAllowGridEdit;
  chkFilter;
end;

procedure TfrmCurrencies.dsDataStateChange(Sender: TObject);
begin
  inherited;
  tvDataCurrency.Options.Editing := (m_.State = dsInsert);
end;

////////////////////////////////////////////////////////////////////////////////////////
//  tvFunctions
////////////////////////////////////////////////////////////////////////////////////////

procedure TfrmCurrencies.tvDataCurrencyPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
  var Error: Boolean);
var
  CurrValue : string;
begin
  currValue := m_.fieldbyname('currency').asstring;

  error := false;
  if trim(displayValue) = '' then
  begin
    error := true;
    //errortext := 'Currency code '+' - '+'is required - Use ESC to cancel';
	  errortext := GetTranslatedText('shTx_Currencies_CodeIsRequired');
    exit;
  end;

  if hdata.CurrencyExist(displayValue) then
  begin
    error := true;
    //errortext := displayvalue+'Nýtt gildi er til í annari færslu. Notið ESC-hnappin til að hætta við';
    errortext := displayvalue+GetTranslatedText('shNewValueExistInAnotherRecor');
    exit
  end;

  if tvData.DataController.DataSource.State = dsEdit then
  begin
    if hdata.currencyExistsInOther(currValue) then
    begin
      error := true;
      // errortext := displayvalue+'Eldra gildi fannst í tengdri færslu ekki hægt að breyta - Notið 'ESC-hnappin til að hætta við';
      errortext := displayvalue+GetTranslatedText('shOldValueUsedInRelatedDataC');
      exit;
    end;
  end;
end;


procedure TfrmCurrencies.tvDataAValuePropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
  var Error: Boolean);
//var
//  CurrValue : double;
begin
//  currValue := LocalFloatValue(m_.fieldbyname('AValue').asString);
  if (displayValue = 0) then
  begin
    error := true;
    //errortext := 'Rate'+' '+'can not be 0'+'  '+'Use ESC- to cancel';
	errortext := GetTranslatedText('shTx_Currencies_RateCannotBeZeroCancel');
  end;
end;


procedure TfrmCurrencies.tvDataDblClick(Sender: TObject);
begin
  if ZAct = actLookup then
  begin
    btnOK.Click
  end else
  begin
    btnedit.click
  end;
end;



////////////////////////////////////////////////////////////////////////////
//  Filter
/////////////////////////////////////////////////////////////////////////////

procedure TfrmCurrencies.tvDataDataControllerFilterChanged(Sender: TObject);
begin
  chkFilter;
end;

procedure TfrmCurrencies.ApplyFilter;
begin
  tvData.DataController.Filter.Options := [fcoCaseInsensitive];
  tvData.DataController.Filter.Root.BoolOperatorKind := fboOr;
  tvData.DataController.Filter.Root.Clear;
  tvData.DataController.Filter.Root.AddItem(tvDataCurrency,foLike,'%'+Uppercase(edFilter.Text)+'%','%'+Uppercase(edFilter.Text)+'%');
  tvData.DataController.Filter.Root.AddItem(tvDataDescription,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvData.DataController.Filter.Active := True;
end;

procedure TfrmCurrencies.edFilterChange(Sender: TObject);
begin
  if edFilter.Text = '' then
  begin
    tvData.DataController.Filter.Root.Clear;
    tvData.DataController.Filter.Active := false;
  end else
  begin
    applyFilter;
  end;
end;



//////////////////////////////////////////////////////////////////////////
//  Buttons
//////////////////////////////////////////////////////////////////////////

procedure TfrmCurrencies.BtnOkClick(Sender: TObject);
begin
  fillHolder;
end;

procedure TfrmCurrencies.btnCancelClick(Sender: TObject);
begin
  zData.init
end;

procedure TfrmCurrencies.btnClearClick(Sender: TObject);
begin
  edFilter.Text := '';
end;

procedure TfrmCurrencies.btnCloseClick(Sender: TObject);
begin
  if embedded then
    Close;
end;

procedure TfrmCurrencies.btnInsertClick(Sender: TObject);
begin
  mnuiAllowGridEdit.Checked := true;
  zAllowGridEdit := mnuiAllowGridEdit.Checked;
  changeAllowGridEdit;
  if m_.Active = false then m_.Open;
  grData.SetFocus;
  m_.Insert;
  tvData.GetColumnByFieldName('currency').Focused := True;
end;

procedure TfrmCurrencies.btnEditClick(Sender: TObject);
begin
  mnuiAllowGridEdit.Checked := true;
  zAllowGridEdit := mnuiAllowGridEdit.Checked;
  changeAllowGridEdit;
  grData.SetFocus;
  tvData.GetColumnByFieldName('currency').Focused := True;
  //showmessage('edit in grid');
  showmessage(GetTranslatedText('shTx_Currencies_EditInGrid'));
end;

procedure TfrmCurrencies.btnHistoryClick(Sender: TObject);
begin
  inherited;
  ShowCurrencyHistory(m_Currency.AsString);
end;

procedure TfrmCurrencies.btnDeleteClick(Sender: TObject);
begin
  m_.Delete;
end;

////---------------------------------------------------------------------------
/// Menu in other actions
///-----------------------------------------------------------------------------

procedure TfrmCurrencies.mnuiAllowGridEditClick(Sender: TObject);
begin

  mnuiAllowGridEdit.Checked := not mnuiAllowGridEdit.Checked;
  zAllowGridEdit := mnuiAllowGridEdit.Checked;
  changeAllowGridEdit;
end;

procedure TfrmCurrencies.mnuiGridToExcelClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToExcel(sFilename, grData, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmCurrencies.mnuiGridToHtmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToHtml(sFilename, grData, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.html'), nil, nil, sw_shownormal);
end;

procedure TfrmCurrencies.mnuiGridToTextClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToText(sFilename, grData, true, true,';','','','txt');
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.txt'), nil, nil, sw_shownormal);
end;

procedure TfrmCurrencies.mnuiGridToXmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToXml(sFilename, grData, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xml'), nil, nil, sw_shownormal);
end;

procedure TfrmCurrencies.mnuiPrintClick(Sender: TObject);
begin
  grPrinter.PrintTitle := caption;
  prLink_grData.ReportTitle.Text := caption;
  grPrinter.Preview(true, prLink_grData);
end;


end.
