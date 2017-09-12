unit uTaxes;

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
  , Vcl.Buttons
  , Vcl.StdCtrls
  , Vcl.ComCtrls
  , Vcl.Menus
  , Vcl.ExtCtrls
  , Data.DB
  , shellapi
  , Hdata
  , _glob
  , ug
  , uStringUtils
  , uUtils

  , kbmMemTable

  , uAppGlobal
  , sSkinProvider
  , sSpeedButton
  , sEdit
  , sPageControl
  , sStatusBar
  , sLabel
  , sButton
  , sPanel

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
  , dxPScxGridLnk
  , dxPScxGridLayoutViewLnk
  , dxPScxEditorProducers
  , dxPScxExtEditorProducers
  , dxPSCore
  , dxPScxCommon

  , cmpRoomerDataSet
  , cmpRoomerConnection


  , dxSkinsCore, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin, dxSkinOffice2013White,
  dxSkinsDefaultPainters, dxSkinscxPCPainter, cxDropDownEdit, cxButtonEdit, dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, cxPropertiesStore,
  dxmdaset, sCheckBox, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld, dxPScxPivotGridLnk, dxSkinBlack, dxSkinBlue, dxSkinBlueprint,
  dxSkinDarkRoom, dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast, dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky,
  dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black, dxSkinOffice2007Blue, dxSkinOffice2007Green, dxSkinOffice2007Pink,
  dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue, dxSkinOffice2010Silver, dxSkinPumpkin, dxSkinSeven,
  dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver, dxSkinSpringTime, dxSkinStardust, dxSkinSummer2008, dxSkinValentine,
  dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue
  , uRoomerGridForm, uRoomerDialogForm, cxGridBandedTableView, cxGridDBBandedTableView, cxCalendar, cxCurrencyEdit
  , uCurrencyHandler, cxCalc, cxCheckBox
  ;

type
  TfrmTaxes = class(TfrmBaseRoomerGridForm)
    mnuOther: TPopupMenu;
    mnuiPrint: TMenuItem;
    mnuiAllowGridEdit: TMenuItem;
    N2: TMenuItem;
    Export1: TMenuItem;
    mnuiGridToExcel: TMenuItem;
    mnuiGridToHtml: TMenuItem;
    mnuiGridToText: TMenuItem;
    mnuiGridToXml: TMenuItem;
    grPrinter: TdxComponentPrinter;
    prLink_grData: TdxGridReportLink;
    m_: TdxMemData;
    m_ID: TIntegerField;
    A1: TMenuItem;
    m_Description: TWideStringField;
    m_Amount: TFloatField;
    m_Tax_Type: TWideStringField;
    m_Tax_Base: TWideStringField;
    m_Time_Due: TWideStringField;
    m_ReTaxable: TWideStringField;
    m_Booking_Item_Id: TIntegerField;
    m_Hotel_Id: TWideStringField;
    m_Booking_Item: TWideStringField;
    m_Incl_Excl: TWideStringField;
    m_Netto_Amount_Based: TWideStringField;
    m_Value_Formula: TWideStringField;
    m_Valid_From: TDateField;
    m_Valid_To: TDateField;
    PopupMenu1: TPopupMenu;
    C1: TMenuItem;
    m_TaxChildren: TWideStringField;
    cLabFilter: TsLabel;
    btnClear: TsSpeedButton;
    btnDelete: TsButton;
    btnOther: TsButton;
    edFilter: TsEdit;
    chkActive: TsCheckBox;
    btnInsert: TsButton;
    btnEdit: TsButton;
    btnRefresh: TsButton;
    tvDataRecId: TcxGridDBBandedColumn;
    tvDataID: TcxGridDBBandedColumn;
    tvDataDescription: TcxGridDBBandedColumn;
    tvDataAmount: TcxGridDBBandedColumn;
    tvDataTax_Type: TcxGridDBBandedColumn;
    tvDataTax_Base: TcxGridDBBandedColumn;
    tvDataTime_Due: TcxGridDBBandedColumn;
    tvDataReTaxable: TcxGridDBBandedColumn;
    tvDataBooking_Item_Id: TcxGridDBBandedColumn;
    tvDataHotel_Id: TcxGridDBBandedColumn;
    tvDataBooking_Item: TcxGridDBBandedColumn;
    tvDataIncl_Excl: TcxGridDBBandedColumn;
    tvDataNetto_Amount_Based: TcxGridDBBandedColumn;
    tvDataValue_Formula: TcxGridDBBandedColumn;
    tvDataValid_From: TcxGridDBBandedColumn;
    tvDataValid_To: TcxGridDBBandedColumn;
    tvDataTaxChildren: TcxGridDBBandedColumn;
    m_After_discount: TWideStringField;
    tvDataAfter_discount: TcxGridDBBandedColumn;
    procedure m_BeforeInsert(DataSet: TDataSet);
    procedure m_BeforePost(DataSet: TDataSet);
    procedure m_NewRecord(DataSet: TDataSet);
    procedure BtnOkClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
    procedure btnDeleteClick(Sender: TObject);
    procedure mnuiPrintClick(Sender: TObject);
    procedure mnuiGridToExcelClick(Sender: TObject);
    procedure mnuiGridToHtmlClick(Sender: TObject);
    procedure mnuiGridToTextClick(Sender: TObject);
    procedure mnuiGridToXmlClick(Sender: TObject);
    procedure btnEditClick(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure edFilterChange(Sender: TObject);
    procedure btnInsertClick(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure chkActiveClick(Sender: TObject);
    procedure A1Click(Sender: TObject);
    procedure tvDataBooking_Item_IdPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure tvDataBooking_ItemPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption; var Error: Boolean);
    procedure C1Click(Sender: TObject);
    procedure tvDataAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure tvDataIncl_ExclPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
      var Error: Boolean);
    procedure tvDataValid_FromPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
      var Error: Boolean);
    procedure tvDataValid_ToPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
      var Error: Boolean);
  private
    { Private declarations }
    zFirstTime       : boolean;
    zData: recTaxesHolder;
    FCurrencyhandler: TCurrencyHandler;
    procedure fillHolder;
    procedure applyFilter;
    function CheckMultipleValidTaxes: boolean;

  protected
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;

  public
    constructor Create(aOwner: TComponent); override;
  end;

function EditTaxes() : boolean;

implementation

{$R *.dfm}

uses
    uD
  , uDImages
  , prjConst
  , uSqlDefinitions
  , UITypes
  , uItems2
  , DateUtils
  ;



//////////////////////////////////////////////////////////////////////////////////////////////
//  unit global functions
//////////////////////////////////////////////////////////////////////////////////////////////

function EditTaxes() : boolean;
var _frmTaxes: TfrmTaxes;
begin
  _frmTaxes := TfrmTaxes.Create(nil);
  try
    Result := (_frmTaxes.ShowModal = mrOk);
  finally
    _frmTaxes.Free;
  end;
end;

///////////////////////////////////////////////////////////////////////
                    { Private declarations }
///////////////////////////////////////////////////////////////////////


Procedure TfrmTaxes.DoLoadData;
var
  s    : string;
  rSet : TRoomerDataSet;
begin
  inherited;
  m_.DisableControls;
  rSet := CreateNewDataSet;
  try
    s := select_Taxes_fillGridFromDataset;
    if rSet_bySQL(rSet,s,false) then
    begin
      if m_.active then m_.Close;
      m_.LoadFromDataSet(rSet);
    end;
  finally
    freeandnil(rSet);
    m_.EnableControls;
  end;
  tvdata.ApplyBestFit;
end;

procedure TfrmTaxes.fillHolder;
begin
  initTaxesHolder(zData);
  zData.ID                 := m_ID.AsInteger;
  zData.Description        := m_Description.AsString;
  zData.Hotel_Id        := m_Hotel_Id.AsString;
  zData.Tax_Type       := m_Tax_Type.AsString;
  zData.Tax_Base       := m_Tax_Base.AsString;
  zData.Time_Due       := m_Time_Due.AsString;
  zData.ReTaxable       := m_ReTaxable.AsString;
  zData.TaxChildren     := m_TaxChildren.AsString;
  zData.Booking_Item_Id       := m_Booking_Item_Id.AsInteger;
  zData.Booking_Item    := m_Booking_Item.AsString;
  zData.Incl_Excl    := m_Incl_Excl.AsString;
  zData.NETTO_AMOUNT_BASED    := m_Netto_Amount_Based.AsString;
  zData.AFTER_DISCOUNT    := m_After_discount.AsString;
  zData.VALUE_FORMULA    := m_Value_Formula.AsString;
  zData.VALID_FROM    := m_Valid_From.AsDateTime;
  zData.VALID_TO    := m_Valid_To.AsDateTime;

  zData.Amount  := m_Amount.AsFloat;
end;

procedure TfrmTaxes.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  inherited;
  CanClose := CheckMultipleValidTaxes;
end;

procedure TfrmTaxes.chkActiveClick(Sender: TObject);
begin
  btnRefresh.Click;
end;

constructor TfrmTaxes.Create(aOwner: TComponent);
begin
  inherited;
  FCurrencyhandler := TCurrencyHandler.Create(g.qNativeCurrency);
end;

procedure TfrmTaxes.edFilterChange(Sender: TObject);
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

procedure TfrmTaxes.A1Click(Sender: TObject);
begin
  tvdata.ApplyBestFit;
end;

procedure TfrmTaxes.applyFilter;
begin
  tvData.DataController.Filter.Options := [fcoCaseInsensitive];
  tvData.DataController.Filter.Root.BoolOperatorKind := fboOr;
  tvData.DataController.Filter.Root.Clear;
  tvData.DataController.Filter.Root.AddItem(tvDataDescription,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvData.DataController.Filter.Active := True;
end;


////////////////////////////////////////////////////////////////////////////////////////
// memory table
////////////////////////////////////////////////////////////////////////////////////////



procedure TfrmTaxes.m_BeforeInsert(DataSet: TDataSet);
begin
  if zFirstTime then exit;
  tvData.GetColumnByFieldName('Description').Focused := True;
end;


procedure TfrmTaxes.m_BeforePost(DataSet: TDataSet);
var
  nID : integer;
begin
  initTaxesHolder(zData);
  try
    zData.ID                := m_ID.AsInteger;
    zData.Description       := m_Description.AsString;
    zData.Amount            := m_Amount.AsFloat;
    zData.Hotel_Id          := m_Hotel_Id.AsString;
    zData.Tax_Type          := m_Tax_Type.AsString;
    zData.Tax_Base          := m_Tax_Base.AsString;
    zData.Time_Due          := m_Time_Due.AsString;
    zData.ReTaxable         := m_ReTaxable.AsString;
    zData.TaxChildren       := m_TaxChildren.AsString;
    zData.Booking_Item_Id   := m_Booking_Item_Id.AsInteger;
    zData.Booking_Item      := m_Booking_Item.AsString;
    zData.Incl_Excl         := m_Incl_Excl.AsString;
    zData.NETTO_AMOUNT_BASED := m_Netto_Amount_Based.AsString;
    zData.AFTER_DISCOUNT     := m_After_discount.AsString;
    zData.VALUE_FORMULA     := m_Value_Formula.AsString;
    zData.VALID_FROM        := m_Valid_From.AsDateTime;
    zData.VALID_TO          := m_Valid_To.AsDateTime;
  except
    Abort;
    Exit;
  end;

  if zData.Description = ''  then
  begin
   // showmessage('Description is requierd - set value or use [ESC] to cancel ');
	  showmessage(GetTranslatedText('shTx_Rates_DescriptionRequired'));
    tvData.GetColumnByFieldName('Description').Focused := True;
    abort;
    exit;
  end;

  if zData.Booking_Item.IsEmpty then
  begin
    showmessage(GetTranslatedText('shTx_Taxes_BookingItemRequired'));
    tvData.GetColumnByFieldName('Booking_item').Focused := True;
    abort;
    exit
  end;

  if (zData.Valid_From > zData.Valid_to) then
  begin
    showmessage(GetTranslatedText('shTx_Taxes_InvalidDates'));
    tvData.GetColumnByFieldName('Booking_item').Focused := True;
    abort;
    exit
  end;


  if tvData.DataController.DataSource.State = dsEdit then
  begin
    if UPD_Taxes(zData) then
      glb.ForceTableRefresh
    else
    begin
      abort;
      exit;
    end;
  end;

  if tvData.DataController.DataSource.State = dsInsert then
  begin
    if ins_Taxes(zData,nID) then
    begin
      m_.FieldByName('ID').AsInteger := nID;
      glb.ForceTableRefresh;
    end else
    begin
      abort;
      exit;
    end;
  end;
end;

function TfrmTaxes.CheckMultipleValidTaxes: boolean;
begin
  Result := CheckNoTaxesOverlap(d.roomerMainDataSet.hotelId) or
              (MessageDlg(GetTranslatedText('shTx_Taxes_OverlappingDates'), mtWarning, mbOKCancel, 0, mbCancel) = mrOk);
end;

procedure TfrmTaxes.m_NewRecord(DataSet: TDataSet);
var rec : recTaxesHolder;
begin
  InitTaxesHolder(Rec);
  dataset['Hotel_Id']      := rec.Hotel_Id;
  dataset['Description']     := rec.Description;
  dataset['Tax_Type']     := rec.Tax_Type;
  dataset['Tax_Base']     := rec.Tax_Base;
  dataset['Time_Due']     := rec.Time_Due;
  dataset['Amount']     := rec.Amount;
  dataset['TaxChildren'] := rec.TaxChildren;
  dataset['INCL_EXCL'] := rec.Incl_Excl;
  dataset['Retaxable'] := rec.ReTaxable;
  dataset['Booking_Item_Id']  := rec.Booking_Item_Id;
  dataset['Booking_Item']:= rec.Booking_Item;
  dataset['NETTO_AMOUNT_BASED']:= rec.NETTO_AMOUNT_BASED;
  dataset.FieldByName('After_discount').AsString:= rec.AFTER_DISCOUNT;
  dataset['VALUE_FORMULA'] := rec.VALUE_FORMULA;
  dataset['VALID_FROM'] := rec.VALID_FROM;
  dataset['VALID_TO'] := rec.VALID_TO;
end;

procedure TfrmTaxes.DoUpdateControls;
begin
  DialogButtons := [mbClose];
  m_.ReadOnly := False;
end;
////////////////////////////////////////////////////////////////////////////
//  Filter
/////////////////////////////////////////////////////////////////////////////


procedure TfrmTaxes.tvDataAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  inherited;
  if m_Tax_Type.AsString = 'FIXED_AMOUNT' then
    aProperties := FCurrencyhandler.GetcxEditProperties
  else
    TcxCalcEditProperties(aProperties).DisplayFormat := '0.0 %';
end;

procedure TfrmTaxes.tvDataBooking_ItemPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption; var Error: Boolean);
var
  CurrValue : string;
begin
  currValue := m_.fieldbyname('Booking_Item').asstring;

  error := false;
  if trim(displayValue) = '' then
  begin
    error := true;
    //errortext := 'Description '+' - '+'is required - Use ESC to cancel';
	  errortext := 'Booking Item is Required'; // GetTranslatedText('shTx_Rates_DescriptionIsRequired');
    exit;
  end;

  if NOT hdata.itemExist(displayValue) then // ,g.qLogLevel,g.qProgramPath) then
  begin
    error := true;
    //errortext := displayvalue+'N�tt gildi er til � annari f�rslu. Noti� ESC-hnappin til a� h�tta vi�';
    errortext := displayvalue+'  Does not exist.'; //  +GetTranslatedText('shNewValueExistInAnotherRecor');
    exit;
  end;
end;

procedure TfrmTaxes.tvDataBooking_Item_IdPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
var
  theData : recItemHolder;
begin
  fillholder;
  theData.Item := zData.Booking_Item;
  openItems(actlookup,true,theData);
  if theData.Item <> '' then
  begin
    m_.Edit;
    m_.FieldByName('Booking_Item').asString := theData.Item;
  end;
end;

procedure TfrmTaxes.tvDataIncl_ExclPropertiesValidate(Sender: TObject; var DisplayValue: Variant;
  var ErrorText: TCaption; var Error: Boolean);
begin
  inherited;
  Error := ((m_Tax_Base.AsString = 'BOOKING') or (m_Tax_Base.AsString = 'GUEST_NIGHT')) and (DisplayValue <> 'EXCLUDED');
  if Error then
    ErrorText := 'only "EXCLUDED" allowed for Taxbase "GUEST_NIGHT"';
end;

procedure TfrmTaxes.tvDataValid_FromPropertiesValidate(Sender: TObject; var DisplayValue: Variant;
  var ErrorText: TCaption; var Error: Boolean);
begin
  inherited;
  Error :=  (m_Valid_To.AsDateTime < VarToDateTime(DisplayValue));
  if Error then
    ErrorText := 'Valid To must be before Valid From ';
end;

procedure TfrmTaxes.tvDataValid_ToPropertiesValidate(Sender: TObject; var DisplayValue: Variant;
  var ErrorText: TCaption; var Error: Boolean);
begin
  inherited;
  Error := (m_Valid_From.AsDateTime > VarToDateTime(DisplayValue));
  if Error then
    ErrorText := 'Valid From must be after Valid To';
end;

//////////////////////////////////////////////////////////////////////////
//  Buttons
//////////////////////////////////////////////////////////////////////////


procedure TfrmTaxes.BtnOkClick(Sender: TObject);
begin
  fillHolder;
end;

procedure TfrmTaxes.btnRefreshClick(Sender: TObject);
begin
  RefreshData;
  zFirstTime := false;
end;

procedure TfrmTaxes.C1Click(Sender: TObject);
begin
  DuplicateCurrentRow(m_);
  tvData.Columns[0].Focused := True;
end;

procedure TfrmTaxes.btnCancelClick(Sender: TObject);
begin
  initTaxesHolder(zData);
end;

procedure TfrmTaxes.btnClearClick(Sender: TObject);
begin
  edFilter.Text := '';
end;

procedure TfrmTaxes.btnDeleteClick(Sender: TObject);
begin
  m_.Delete;
end;

procedure TfrmTaxes.btnEditClick(Sender: TObject);
begin
  grData.SetFocus;
  tvData.GetColumnByFieldName('Description').Focused := True;
  m_.Edit;
  showmessage(GetTranslatedText('shTx_Rates_EditInGrid'));
end;

procedure TfrmTaxes.btnInsertClick(Sender: TObject);
begin
  if m_.Active = false then m_.Open;
  grData.SetFocus;
  m_.Insert;
  tvData.GetColumnByFieldName('Description').Focused := True;
end;

//---------------------------------------------------------------------------
// Menu in other actions
//-----------------------------------------------------------------------------


procedure TfrmTaxes.mnuiPrintClick(Sender: TObject);
begin
  grPrinter.PrintTitle := caption;
  prLink_grData.ReportTitle.Text := caption;
  grPrinter.Preview(true, prLink_grData);
end;

procedure TfrmTaxes.mnuiGridToExcelClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToExcel(sFilename, grData, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
  //  To export ot xlsx form then use this
  //  ExportGridToXLSX(sFilename, grData, true, true, true);
  //  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xlsx'), nil, nil, sw_shownormal);
end;

procedure TfrmTaxes.mnuiGridToHtmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToHtml(sFilename, grData, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.html'), nil, nil, sw_shownormal);
end;

procedure TfrmTaxes.mnuiGridToTextClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToText(sFilename, grData, true, true,';','','','txt');
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.txt'), nil, nil, sw_shownormal);
end;

procedure TfrmTaxes.mnuiGridToXmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToXml(sFilename, grData, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xml'), nil, nil, sw_shownormal);
end;

end.

