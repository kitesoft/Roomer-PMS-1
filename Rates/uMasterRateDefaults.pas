unit uMasterRateDefaults;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, sEdit, sButton, Vcl.Buttons, sSpeedButton, sLabel, Vcl.ExtCtrls,
  sPanel, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, dxSkinsCore, dxSkinCaramel,
  dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter, cxCustomData,
  cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, cxTextEdit, cxDropDownEdit, dxPSGlbl,
  dxPSUtl, dxPSEngn, dxPrnPg, dxBkgnd, dxWrap, dxPrnDev, dxPSCompsProvider, dxPSFillPatterns, dxPSEdgePatterns,
  dxPSPDFExportCore, dxPSPDFExport, cxDrawTextUtils, dxPSPrVwStd, dxPSPrVwAdv, dxPSPrVwRibbon,
  dxPScxPageControlProducer, dxPScxGridLnk, dxPScxGridLayoutViewLnk, dxPScxEditorProducers, dxPScxExtEditorProducers,
  dxSkinsdxBarPainter, dxSkinsdxRibbonPainter, dxPSCore, dxPScxCommon, dxmdaset, cxPropertiesStore, Vcl.Menus,
  cxGridLevel, cxGridCustomTableView, cxGridTableView, cxGridDBTableView, cxClasses, cxGridCustomView, cxGrid,
  Vcl.ComCtrls, sStatusBar, sCheckBox, cxCalendar
  , cmpRoomerDataset, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, sSplitter, sListView, sComboBox
  ;

type
  TfrmMasterRateDefaults = class(TForm)
    pnlHolder: TsPanel;
    sPanel2: TsPanel;
    btnDelete: TsButton;
    btnOther: TsButton;
    btnNew: TsButton;
    btnEdit: TsButton;
    sbMain: TsStatusBar;
    panBtn: TsPanel;
    btnCancel: TsButton;
    BtnOk: TsButton;
    mnuOther: TPopupMenu;
    mnuiPrint: TMenuItem;
    N2: TMenuItem;
    Export1: TMenuItem;
    mnuiGridToExcel: TMenuItem;
    mnuiGridToHtml: TMenuItem;
    mnuiGridToText: TMenuItem;
    mnuiGridToXml: TMenuItem;
    FormStore: TcxPropertiesStore;
    m_: TdxMemData;
    DS: TDataSource;
    grPrinter: TdxComponentPrinter;
    prLink_grData: TdxGridReportLink;
    lbStartFrom: TsLabel;
    cbxChannelManager: TsComboBox;
    cbxPlanCode: TsComboBox;
    sLabel1: TsLabel;
    sPanel1: TsPanel;
    grData: TcxGrid;
    tvData: TcxGridDBTableView;
    lvData: TcxGridLevel;
    lvRateCodes: TsListView;
    sSplitter1: TsSplitter;
    m_fromDate: TDateField;
    m_price: TFloatField;
    m_availability: TIntegerField;
    m_minStay: TIntegerField;
    m_maxStay: TIntegerField;
    m_closedOnArrival: TBooleanField;
    m_closedOnDeparture: TBooleanField;
    m_stop: TBooleanField;
    m_lengthOfStayArrivalDateBased: TBooleanField;
    m_singleUsePrice: TFloatField;
    tvDataRecId: TcxGridDBColumn;
    tvDatafromDate: TcxGridDBColumn;
    tvDataprice: TcxGridDBColumn;
    tvDataavailability: TcxGridDBColumn;
    tvDataminStay: TcxGridDBColumn;
    tvDatamaxStay: TcxGridDBColumn;
    tvDataclosedOnArrival: TcxGridDBColumn;
    tvDataclosedOnDeparture: TcxGridDBColumn;
    tvDatastop: TcxGridDBColumn;
    tvDatalengthOfStayArrivalDateBased: TcxGridDBColumn;
    tvDatasingleUsePrice: TcxGridDBColumn;
    m_id: TIntegerField;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCreate(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure FormShow(Sender: TObject);
    procedure m_BeforeDelete(DataSet: TDataSet);
    procedure m_BeforeInsert(DataSet: TDataSet);
    procedure m_BeforePost(DataSet: TDataSet);
    procedure m_NewRecord(DataSet: TDataSet);
    procedure btnDeleteClick(Sender: TObject);
    procedure btnEditClick(Sender: TObject);
    procedure btnNewClick(Sender: TObject);
    procedure mnuiPrintClick(Sender: TObject);
    procedure mnuiGridToExcelClick(Sender: TObject);
    procedure mnuiGridToHtmlClick(Sender: TObject);
    procedure mnuiGridToTextClick(Sender: TObject);
    procedure mnuiGridToXmlClick(Sender: TObject);
    procedure edtLastDateChange(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure BtnOkClick(Sender: TObject);
    procedure cbxChannelManagerCloseUp(Sender: TObject);
    procedure cbxPlanCodeCloseUp(Sender: TObject);
    procedure lvRateCodesChange(Sender: TObject; Item: TListItem; Change: TItemChange);
  private
    FDirty : Boolean;
    FUpdatingGrid: Boolean;
    FRecordSet: TRoomerDataSet;
    FSelectedChannel : Integer;
    FSelectedPlanCode : Integer;
    procedure fillGridFromDataset;
    procedure ShowError(const aOperation: string);
    procedure prepareSelectableList;
    procedure prepareRateListview(rateList : String);
    { Private declarations }
  public
    { Public declarations }
    constructor Create(Owner: TComponent); override;
    destructor Destroy; override;
  end;


procedure EditMasterRateDefaults;

implementation

{$R *.dfm}

uses
  uDateTimeHelper
  , DateUtils
  , uAppGlobal
  , uUtils
  , hData
  , cxGridExportLink
  , ShellAPI
  , UITypes
  , uG
  , PrjConst
  , _Glob
  , uD;

procedure EditMasterRateDefaults;
begin
  with TfrmMasterRateDefaults.Create(nil) do
  try
    ShowModal;
  finally
    Free;
  end;
end;


procedure TfrmMasterRateDefaults.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);
  FDirty := False;
end;

procedure TfrmMasterRateDefaults.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  FRecordSet := nil;
end;

procedure TfrmMasterRateDefaults.btnDeleteClick(Sender: TObject);
begin
  m_.Delete;
end;

procedure TfrmMasterRateDefaults.btnEditClick(Sender: TObject);
begin
  m_.Edit;
end;

procedure TfrmMasterRateDefaults.btnNewClick(Sender: TObject);
begin
  m_.Insert;
end;

procedure TfrmMasterRateDefaults.BtnOkClick(Sender: TObject);
begin
  if tvdata.DataController.DataSet.State in [dsInsert, dsEdit] then
    tvdata.DataController.Post;
end;

procedure TfrmMasterRateDefaults.btnRefreshClick(Sender: TObject);
begin
  FillGridFromdataset;
end;

procedure TfrmMasterRateDefaults.cbxChannelManagerCloseUp(Sender: TObject);
var rSet : TRoomerDataSet;
begin
  //
   if TsComboBox(Sender).ItemIndex >= 0 then
   begin
     FSelectedChannel := Integer(TsComboBox(Sender).Items.Objects[TsComboBox(Sender).ItemIndex]);
     if glb.LocateSpecificRecord('channelmanagers', 'id', FSelectedChannel) then
     begin
       rSet := CreateNewDataSet;
       try
         if hData.rSet_bySQL(rSet, format('SELECT GROUP_CONCAT(DISTINCT roomClassId) AS RATE_LIST FROM channelclassrelations WHERE channelId IN (%s)', [glb.ChannelManagersSet['channels']])) then
         prepareRateListview(rSet['RATE_LIST']);
       finally
         rSet.Free;
       end;
     end;
   end;
end;

procedure TfrmMasterRateDefaults.cbxPlanCodeCloseUp(Sender: TObject);
begin
  //
   if TsComboBox(Sender).ItemIndex >= 0 then
   begin
     FSelectedPlanCode := Integer(TsComboBox(Sender).Items.Objects[TsComboBox(Sender).ItemIndex]);
   end;
end;

constructor TfrmMasterRateDefaults.Create(Owner: TComponent);
begin
  FRecordSet := d.roomerMainDataSet.CreateNewDataset;
  inherited;
end;

destructor TfrmMasterRateDefaults.Destroy;
begin
  inherited;
  FRecordSet.Free;
end;

procedure TfrmMasterRateDefaults.edtLastDateChange(Sender: TObject);
begin
  fillGridFromDataset;
end;

procedure TfrmMasterRateDefaults.fillGridFromDataset;
var rSet : TRoomerDataSet;
begin
  if NOT Assigned(lvRateCodes.Selected) then exit;

  if ComponentRunning(Self) then
  begin
    FUpdatingGrid := true;
    m_.DisableControls;
    try
      rSet := CreateNewDataSet;
      try
        hData.rSet_bySQL(rSet,
                            format('SELECT DATE(fromDate) AS fromDate, price, availability, minStay, maxStay, closedOnArrival, ' +
                                   'closedOnDeparture, stop, lengthOfStayArrivalDateBased, singleUsePrice, id ' +
                                   'FROM channelmasterratesdefaults WHERE channelManager=%d AND planCodeId=%d AND roomClassId=%d',
                                  [FSelectedChannel,
                                   FSelectedPlanCode,
                                   Integer(lvRateCodes.Selected.Data)]));
        rSet.First;
        if m_.active then m_.Close;
        m_.LoadFromDataSet(rSet);
        m_.Open;
      finally
        rSet.Free;
      end;
    finally
      m_.EnableControls;
      FUpdatingGrid := False;
    end;
  end;
end;

procedure TfrmMasterRateDefaults.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    btnCancel.Click;
end;

procedure TfrmMasterRateDefaults.FormShow(Sender: TObject);
begin
  prepareSelectableList;
  fillGridFromDataset;
  grData.SetFocus;
end;

procedure TfrmMasterRateDefaults.lvRateCodesChange(Sender: TObject; Item: TListItem; Change: TItemChange);
begin
  fillGridFromDataset;
end;

procedure TfrmMasterRateDefaults.prepareSelectableList;
var rSet : TRoomerDataset;

  procedure AddList(RSet : TRoomerDataset; IdField, NameField : String; cbx : TsComboBox);
  begin
    cbx.Items.Clear;
    RSet.First;
    while NOT RSet.Eof do
    begin
      if RSet['active'] then
        cbx.Items.AddObject(RSet[NameField], Pointer(RSet.FieldByName(IdField).AsInteger));
      RSet.Next;
    end;
    cbx.ItemIndex := ABS(ORD(cbx.Items.Count > 0) - 1);
  end;
begin
  cbxChannelManager.OnCloseUp := nil;
  cbxPlanCode.OnCloseUp := nil;
  try
    AddList(glb.ChannelManagersSet, 'id', 'Description', cbxChannelManager);
    AddList(glb.ChannelPlanCodes, 'id', 'description', cbxPlanCode);
  finally
    cbxChannelManager.OnCloseUp := cbxChannelManagerCloseUp;
    cbxPlanCode.OnCloseUp := cbxPlanCodeCloseUp;
  end;

  cbxChannelManagerCloseUp(cbxChannelManager);
end;

procedure TfrmMasterRateDefaults.prepareRateListview(rateList : String);
var rSet : TRoomerDataset;
    id : Integer;
    strId : String;
    sIdList : TStrings;

    lvItem : TListItem;
begin
  lvRateCodes.OnChange := nil;
  lvRateCodes.Items.BeginUpdate;
  try
    lvRateCodes.Items.Clear;
    sIdList := TStringList.Create;
    uUtils.SplitString(rateList, sIdList, ',');
    for strId in sIdList do
    begin
      id := strToInt(strId);
      if glb.LocateSpecificRecord('roomtypegroups', 'id', id) then
      begin
        lvItem := lvRateCodes.Items.Add;
        lvItem.Caption := glb.RoomTypeGroups['Code'];
        lvItem.SubItems.Add(glb.RoomTypeGroups['Description']);
        lvItem.Data := Pointer(id);
      end;
    end;
  finally
    lvRateCodes.Items.EndUpdate;
    lvRateCodes.OnChange := lvRateCodesChange;
  end;
end;

procedure TfrmMasterRateDefaults.mnuiGridToExcelClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToExcel(sFilename, grData, true, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil, sw_shownormal);
end;

procedure TfrmMasterRateDefaults.mnuiGridToHtmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToHtml(sFilename, grData, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.html'), nil, nil, sw_shownormal);
end;

procedure TfrmMasterRateDefaults.mnuiGridToTextClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToText(sFilename, grData, true, true,';','','','txt');
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.txt'), nil, nil, sw_shownormal);
end;

procedure TfrmMasterRateDefaults.mnuiGridToXmlClick(Sender: TObject);
var
  sFilename : string;
begin
  sFilename := g.qProgramPath + caption;
  ExportGridToXml(sFilename, grData, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xml'), nil, nil, sw_shownormal);
end;

procedure TfrmMasterRateDefaults.mnuiPrintClick(Sender: TObject);
begin
  grPrinter.PrintTitle := caption;
  prLink_grData.ReportTitle.Text := caption;
  grPrinter.Preview(true, prLink_grData);
end;

procedure TfrmMasterRateDefaults.m_BeforeDelete(DataSet: TDataSet);
var
  s : string;
//  lCaller: TMasterRateDefaultsAPICaller;
begin
  if FUpdatingGrid then exit;

  s := '';
  s := s+GetTranslatedText('shDeleteDayClosingTime')+' '+m_fromDate.ToString;
  s := s+GetTranslatedText('shContinue');

  if MessageDlg(s,mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
    Abort
  else
  begin

//    lCaller := TMasterRateDefaultsAPICaller.Create;
//    try
//      if not lCaller.DeleteDayClosingTime(Dataset['day']) then
//        ShowError('delete of DayClosing Timestamp');
////        Abort;
//    finally
//      lCaller.Free;
//    end;
  end;
end;

procedure TfrmMasterRateDefaults.m_BeforeInsert(DataSet: TDataSet);
begin
  if FUpdatingGrid then exit;
  tvData.GetColumnByFieldName('fromDate').Focused := True;
end;

procedure TfrmMasterRateDefaults.m_BeforePost(DataSet: TDataSet);
//var
//  lCaller: TMasterRateDefaultsAPICaller;
begin
//  if FUpdatingGrid then exit;
//
//  lCaller := TMasterRateDefaultsAPICaller.Create;
//  try
//    if tvData.DataController.DataSource.State = dsEdit then
//    begin
//      if not lCaller.UpdateDayClosingTime(Dataset['day'], Dataset['closingtimestamp']) then
//        ShowError('update of DayCLosing Timestamp');
//    end
//    else if tvData.DataController.DataSource.State = dsInsert then
//      if not lCaller.InsertDayClosingTime(Dataset['day'], Dataset['closingtimestamp']) then
//        ShowError('insert of DayCLosing Timestamp. Cannot enter multiple closing times for the same day');
//
//    FDirty := True;
//  finally
//    lCaller.Free;
//  end;
end;

procedure TfrmMasterRateDefaults.m_NewRecord(DataSet: TDataSet);
begin
  dataset['fromDate'] := TDateTime.Today
end;

procedure TfrmMasterRateDefaults.ShowError(const aOperation: string);
begin
  raise Exception.CreateFmt('Error occured during %s.'+ #10 + 'Operation is cancelled', [aOperation]);
end;

end.
