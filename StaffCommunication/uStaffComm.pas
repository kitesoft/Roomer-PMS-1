unit uStaffComm;

interface

// unit added 2013-02-28 HJ

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
  , Generics.Collections
  , Data.DB
  , shellapi
  , _glob
  , Hdata
  , ug
  , uD
  , uFrmKeyPairSelector
  , RoomerCloudEntities

  , kbmMemTable

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
  , cmpRoomerConnection, dxSkinsCore, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin, dxSkinOffice2013White,
  dxSkinsDefaultPainters, dxSkinscxPCPainter, cxCalc, cxButtonEdit, dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, cxPropertiesStore, dxmdaset,
  dxPScxPivotGridLnk, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld, sCheckBox, dxSkinBlack, dxSkinBlue, dxSkinBlueprint,
  dxSkinDarkRoom, dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast, dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky,
  dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black, dxSkinOffice2007Blue, dxSkinOffice2007Green, dxSkinOffice2007Pink,
  dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue, dxSkinOffice2010Silver, dxSkinPumpkin, dxSkinSeven,
  dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver, dxSkinSpringTime, dxSkinStardust, dxSkinSummer2008, dxSkinValentine,
  dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue, cxMemo, cxDropDownEdit, sBitBtn, Vcl.Mask, sMaskEdit,
  sCustomComboEdit, sToolEdit
  , uROomerGridForm, uRoomerForm, cxGridBandedTableView, cxGridDBBandedTableView

  ;

type
  TfrmStaffComm = class(TfrmBaseRoomerGridForm)
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
    m_date: TDateField;
    m_lastUpdate: TDateTimeField;
    m_notes: TWideMemoField;
    m_action: TWideStringField;
    m_user: TWideStringField;
    m_lastChangedBy: TWideStringField;
    cLabFilter: TsLabel;
    btnClear: TsSpeedButton;
    btnDelete: TsButton;
    btnOther: TsButton;
    edFilter: TsEdit;
    btnInsert: TsButton;
    btnEdit: TsButton;
    dtDate: TsDateEdit;
    btNextDay: TsBitBtn;
    btnPeviousDay: TsBitBtn;
    tvDatalastUpdate: TcxGridDBBandedColumn;
    tvDatanotes: TcxGridDBBandedColumn;
    tvDataaction: TcxGridDBBandedColumn;
    tvDatalastChangedBy: TcxGridDBBandedColumn;
    tvDataRecId: TcxGridDBBandedColumn;
    tvDataID: TcxGridDBBandedColumn;
    tvDatadate: TcxGridDBBandedColumn;
    tvDatauser: TcxGridDBBandedColumn;
    chkShowAllNotes: TsCheckBox;
    procedure FormCreate(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure m_BeforeDelete(DataSet: TDataSet);
    procedure m_BeforePost(DataSet: TDataSet);
    procedure m_NewRecord(DataSet: TDataSet);
    procedure tvDataDescriptionPropertiesValidate(Sender: TObject;
      var DisplayValue: Variant; var ErrorText: TCaption; var Error: Boolean);
    procedure BtnOkClick(Sender: TObject);
    procedure btnCancelClick(Sender: TObject);
    procedure tvDataDataControllerFilterChanged(Sender: TObject);
    procedure tvDataDataControllerSortingChanged(Sender: TObject);
    procedure btnDeleteClick(Sender: TObject);
    procedure mnuiPrintClick(Sender: TObject);
    procedure mnuiAllowGridEditClick(Sender: TObject);
    procedure mnuiGridToExcelClick(Sender: TObject);
    procedure mnuiGridToHtmlClick(Sender: TObject);
    procedure mnuiGridToTextClick(Sender: TObject);
    procedure mnuiGridToXmlClick(Sender: TObject);
    procedure btnEditClick(Sender: TObject);
    procedure btnClearClick(Sender: TObject);
    procedure edFilterChange(Sender: TObject);
    procedure btnInsertClick(Sender: TObject);
    procedure chkActiveClick(Sender: TObject);
    procedure tvData2actionGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure btnPeviousDayClick(Sender: TObject);
    procedure btNextDayClick(Sender: TObject);
    procedure dtDateChange(Sender: TObject);
    procedure tvDataCellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
      AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
  private
    { Private declarations }
    zFirstTime       : boolean;
    zAllowGridEdit   : boolean;
    zFilterOn        : boolean;

    Lookup : Boolean;
    zSortStr         : string;

    procedure fillHolder;
    procedure changeAllowgridEdit;
    Procedure chkFilter;
    procedure applyFilter;
    function GetDate: TDate;
    procedure SetDate(const Value: TDate);
    procedure DeleteSelectedRows;
  protected
    procedure DoUpdateControls; override;
    procedure DoLoadData; override;
  public
    { Public declarations }
    zAct   : TActTableAction;
    zData  : recDayNotesHolder;
    property Date: TDate read GetDate write SetDate;
  end;

function openDayNotes(ADate : TDateTime; act : TActTableAction; Lookup : Boolean; var theData : recDayNotesHolder) : boolean;

var
  frmStaffComm: TfrmStaffComm;

implementation

{$R *.dfm}

uses
  prjConst
  , uSqlDefinitions
  , uItemTypes2
  , uMessageList
  , uAppGlobal
  , uDimages
  , uFrmTaxItemLink
  , uBookKeepingCodes
  , uStaffCommunication
  , uMain
  , uFrmStaffNote
  , uUtils
  , UITypes
  , uStaffCommunicationDefinitions, uSQLUtils;


//////////////////////////////////////////////////////////////////////////////////////////////
//  unit global functions
//////////////////////////////////////////////////////////////////////////////////////////////

function openDayNotes(aDate : TDateTime; act : TActTableAction; Lookup : Boolean; var theData : recDayNotesHolder) : boolean;
var _frmStaffComm : TfrmStaffComm;
begin
  result := false;
  _frmStaffComm := TfrmStaffComm.Create(nil);
  try
    _frmStaffComm.zData := theData;
    _frmStaffComm.Date := ADate;
    _frmStaffComm.Lookup := Lookup;
    _frmStaffComm.zAct := act;
    _frmStaffComm.ShowModal;
    if _frmStaffComm.modalresult = mrOk then
    begin
      theData := _frmStaffComm.zData;
      result := true;
    end
    else
    begin
      theData.ADate := 0;
      theData.Notes := '';
    end;
  finally
    freeandnil(_frmStaffComm);
  end;
end;


///////////////////////////////////////////////////////////////////////
                    { Private declarations }
///////////////////////////////////////////////////////////////////////


procedure TfrmStaffComm.DoLoadData;
var
  rSet: TRoomerDataSet;
  sql: string;
begin
  inherited;
  Caption := 'Notes for ' + DateToStr(dtDate.Date);
  zFirstTime := true;

  if m_.active then m_.Close;

  if chkShowAllNotes.Checked then
    sql := format('SELECT * FROM daynotes WHERE date>=%s ORDER BY date asc', [_db(dtDate.Date)])
  else
    sql := format('SELECT * FROM daynotes WHERE date=%s', [_db(dtDate.Date)]);

  rSet := d.roomerMainDataSet.ActivateNewDataset(d.roomerMainDataSet.SystemFreeQuery(sql));
  try
    if zSortStr = '' then zSortStr := 'id';
    rSet.Sort := 'Id';
    try
      rSet.First;
      if NOT rSet.Eof then
      begin
        m_.LoadFromDataSet(rSet);
      end;
    finally
      rSet.Filter := '';
      rSet.Filtered := False;
    end;
  finally
    rSet.Free;
    zFirstTime := false;
  end;
end;

procedure TfrmStaffComm.DoUpdateControls;
begin
  inherited;
  tvDatadate.Visible := chkShowAllNotes.Checked;
end;

procedure TfrmStaffComm.fillHolder;
begin
  zData.ID                    := m_.FieldByName('ID').AsInteger;
  zData.User                  := m_['user'];
  zData.ADate                 := m_['date'];
  zData.Notes                 := m_['notes'];
  zData.AAction               := TStaffCommAction.FromString( m_['action']);
  zData.LastChangedBy         := m_['lastChangedBy'];
  zData.LastUpdate            := m_['lastUpdate'];
end;

procedure TfrmStaffComm.changeAllowgridEdit;
begin
  tvDatanotes.Options.Editing           := zAllowGridEdit;
  tvDataaction.Options.Editing          := zAllowGridEdit;
end;


procedure TfrmStaffComm.chkActiveClick(Sender: TObject);
begin
  if tvdata.DataController.DataSet.State = dsEdit then
  begin
    tvdata.DataController.Post;
  end;
  RefreshData;
end;

procedure TfrmStaffComm.chkFilter;
var
  sFilter : string;
  rC1,rc2   : integer;
begin
  sFilter := edFilter.text;
  rc1 := tvData.DataController.RecordCount;
  rc2 := tvData.DataController.FilteredRecordCount;
  zFilterON := rc1 <> rc2;
end;


procedure TfrmStaffComm.dtDateChange(Sender: TObject);
begin
  RefreshData;
end;

procedure TfrmStaffComm.edFilterChange(Sender: TObject);
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

procedure TfrmStaffComm.applyFilter;
begin
  tvData.DataController.Filter.Options := [fcoCaseInsensitive];
  tvData.DataController.Filter.Root.BoolOperatorKind := fboOr;
  tvData.DataController.Filter.Root.Clear;
  tvData.DataController.Filter.Root.AddItem(tvDatanotes,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvData.DataController.Filter.Root.AddItem(tvDatauser,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvData.DataController.Filter.Root.AddItem(tvDatalastChangedBy,foLike,'%'+edFilter.Text+'%','%'+edFilter.Text+'%');
  tvData.DataController.Filter.Active := True;
end;


/////////////////////////////////////////////////////////////
// Form actions
/////////////////////////////////////////////////////////////

procedure TfrmStaffComm.FormCreate(Sender: TObject);
begin
  zFirstTime  := true;
  zAct        := actNone;
end;

procedure TfrmStaffComm.FormShow(Sender: TObject);
begin
//**
  //-C
  zAllowGridEdit := mnuiAllowGridEdit.Checked;
  changeAllowGridEdit;
  chkFilter;
  zFirstTime := false;
  RefreshData;
end;

function TfrmStaffComm.GetDate: TDate;
begin
  Result := dtDate.Date;
end;

procedure TfrmStaffComm.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  glb.EnableOrDisableTableRefresh('items', True);
end;



////////////////////////////////////////////////////////////////////////////////////////
// memory table
////////////////////////////////////////////////////////////////////////////////////////

procedure TfrmStaffComm.m_BeforeDelete(DataSet: TDataSet);
var
  s : string;
begin
  fillHolder;

  s := '';
  s := s+GetTranslatedText('shDeleteSelectedLine')+#10#10+zData.Notes+' '+chr(10);
  s := s+GetTranslatedText('shContinue');

  if MessageDlg(s,mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    d.roomerMainDataSet.DoCommand('DELETE FROM daynotes WHERE ID=' + inttostr(dataSet['ID']));
  end else
  begin
    abort
  end;
end;

procedure TfrmStaffComm.m_BeforePost(DataSet: TDataSet);
begin
  if zFirstTime then exit;
  initDayNotes(zData);
  zData.ID                    := dataset.FieldByName('ID').AsInteger;
  zData.User                  := dataset['user'];
  zData.ADate                 := dataset['date'];
  zData.Notes                 := dataset['notes'];
  zData.AAction               := TStaffCommAction.FromString(dataset['action']);
  zData.LastChangedBy         := dataset['lastChangedBy'];
  zData.LastUpdate            := dataset['lastUpdate'];

  if Dataset.State = dsEdit then
  begin
    if NOT UPD_DayNotes(zData) then
    begin
      abort;
      exit;
    end;
  end;
  if Dataset.State = dsInsert then
  begin
    if not INS_DayNotes(zData) then
    begin
      abort;
      exit;
    end;
  end;
  glb.ForceTableRefresh;
  RefreshData;
end;



procedure TfrmStaffComm.m_NewRecord(DataSet: TDataSet);
begin
  dataset['user']            := d.roomerMainDataSet.username;
  dataset['date']            := Date;
  dataset['notes']           := '';
  dataset['action']          := scaNoActionNeeded.ToDB;
  dataset['lastChangedBy']   := d.roomerMainDataSet.username;
  dataset['lastUpdate']      := now;
end;

procedure TfrmStaffComm.btNextDayClick(Sender: TObject);
begin
  dtdate.Date := dtdate.Date + 1;

end;

procedure TfrmStaffComm.btnPeviousDayClick(Sender: TObject);
begin
  dtdate.Date := dtdate.Date - 1;
end;

procedure TfrmStaffComm.SetDate(const Value: TDate);
begin
  dtDate.Date := Value;
end;

////////////////////////////////////////////////////////////////////////////////////////
//  table View Functions
////////////////////////////////////////////////////////////////////////////////////////

procedure TfrmStaffComm.tvDataDescriptionPropertiesValidate(Sender: TObject;
  var DisplayValue: Variant; var ErrorText: TCaption; var Error: Boolean);
var
  CurrValue : string;
begin
  currValue := m_.fieldbyname('Description').asstring;

  error := false;
  if trim(displayValue) = '' then
  begin
    error := true;
   // errortext := 'Description '+' - '+'is required - Use ESC to cancel';
	errortext := GetTranslatedText('shTx_StaffComm_DescriptionIsRequired');
    exit;
  end;

  if hdata.RoomrateDescriptionExist(displayValue) then
  begin
    error := true;
    //errortext := displayvalue+'Nýtt gildi er til í annari færslu. Notið ESC-hnappin til að hætta við';
    errortext := displayvalue+'  '+GetTranslatedText('shNewValueExistInAnotherRecor');
    exit
  end;
//
  if tvData.DataController.DataSource.State = dsEdit then
  begin
    if hdata.payTypeExistsInOther(currValue) then
    begin
      error := true;
      errortext := displayvalue+' - '+GetTranslatedText('shOldValueUsedInRelatedDataC');
      exit;
    end;
  end;
end;

procedure TfrmStaffComm.tvDataCellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
  AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
begin
  inherited;
  if ZAct = actLookup then
    btnOK.Click
  else
    btnEdit.Click;
end;

////////////////////////////////////////////////////////////////////////////
//  Filter
/////////////////////////////////////////////////////////////////////////////

procedure TfrmStaffComm.tvData2actionGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AText: string);
begin
  aText := TStaffCommAction.FromString(aText).AsReadableString;
end;

procedure TfrmStaffComm.tvDataDataControllerFilterChanged(Sender: TObject);
begin
  chkFilter;
end;

procedure TfrmStaffComm.tvDataDataControllerSortingChanged(Sender: TObject);
var
  i : integer;
  s : string;
  serval : boolean;
begin
  s := '';
  serval := false;
  for i :=  0 to tvData.SortedItemCount - 1 do
  begin
    if serval then s := s+', ';
    s := s+TcxGridDBColumn(tvData.SortedItems[I]).DataBinding.FieldName;
    serval := true;
    if tvData.SortedItems[i].SortOrder = soDescending then
    s := s + ' DESC';
  end;
  zSortStr := s;
end;

//////////////////////////////////////////////////////////////////////////
//  Buttons
//////////////////////////////////////////////////////////////////////////


procedure TfrmStaffComm.BtnOkClick(Sender: TObject);
begin
  fillHolder;
end;

procedure TfrmStaffComm.btnCancelClick(Sender: TObject);
begin
  initDayNotes(zData);
end;

procedure TfrmStaffComm.btnClearClick(Sender: TObject);
begin
  edFilter.Text := '';
end;

procedure TfrmStaffComm.DeleteSelectedRows;
var
  i: integer;
  Lstr: TStrings;
  s: string;
  sql: string;
begin
  s := '';
  s := s+GetTranslatedText('shDeleteSelectedLines') + chr(10);
  s := s+GetTranslatedText('shContinue');

  if MessageDlg(s,mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    lStr := TStringlist.Create;
    try
      for i := 0 to PRED(tvData.Controller.SelectedRowCount ) do
        lStr.Add(IntToStr(tvData.Controller.SelectedRows[i].Values[tvDataID.Index]));

      lStr.Delimiter := ',';
      lStr.QuoteChar := ' ';
      sql := 'DELETE FROM daynotes WHERE ID in (' + lStr.DelimitedText + ')';

      d.roomerMainDataSet.DoCommand(sql);

    finally
      lStr.Free;
    end;
  end;
  RefreshData;
end;

procedure TfrmStaffComm.btnDeleteClick(Sender: TObject);
begin
  if tvData.Controller.SelectedRowCount > 1 then
    DeleteSelectedRows
  else
    m_.Delete;
end;

procedure TfrmStaffComm.btnEditClick(Sender: TObject);
var
  Dummy: TDate;
begin
  initDayNotes(zData);
  FillHolder;

  if EditDayNote(zData.ADate, false, zData, Dummy) then
  begin
    m_.Edit;
    m_['notes'] := zData.Notes;
    m_['action'] := zData.AAction.ToDB;
    m_.Post;
  end;

end;

procedure TfrmStaffComm.btnInsertClick(Sender: TObject);
var
  endDate: TDate;
begin
  if m_.Active = false then m_.Open;

  initDayNotes(zData);
  zData.aDate := dtDate.Date;

  if EditDayNote(zData.ADate, true, zData, endDate) then
  begin
    m_.DisableControls;
    try
      INS_DayNotes(zData, endDate);
    finally
      m_.EnableControls;
      RefreshData;
    end;
  end;
end;

//---------------------------------------------------------------------------
// Menu in other actions
//-----------------------------------------------------------------------------

procedure TfrmStaffComm.mnuiAllowGridEditClick(Sender: TObject);
begin
  if zFirstTime then exit;
  mnuiAllowGridEdit.Checked := not mnuiAllowGridEdit.Checked;
  zAllowGridEdit := mnuiAllowGridEdit.Checked;
  changeAllowGridEdit;
end;


procedure TfrmStaffComm.mnuiPrintClick(Sender: TObject);
begin
  grPrinter.PrintTitle := caption;
  prLink_grData.ReportTitle.Text := caption;
  grPrinter.Preview(true, prLink_grData);
end;

procedure TfrmStaffComm.mnuiGridToExcelClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToExcel(sFilename, grData, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmStaffComm.mnuiGridToHtmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToHtml(sFilename, grData, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.html'), nil, nil, sw_shownormal);
end;

procedure TfrmStaffComm.mnuiGridToTextClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToText(sFilename, grData, true, true,';','','','txt');
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.txt'), nil, nil, sw_shownormal);
end;

procedure TfrmStaffComm.mnuiGridToXmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToXml(sFilename, grData, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xml'), nil, nil, sw_shownormal);
end;

end.

