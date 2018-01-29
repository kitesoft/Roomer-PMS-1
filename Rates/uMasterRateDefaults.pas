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
  , cmpRoomerDataset, Vcl.Mask, sMaskEdit, sCustomComboEdit, sToolEdit, sSplitter, sListView, sComboBox, uRoomerForm,
  cxCurrencyEdit
  ;

type
  TfrmMasterRateDefaults = class(TfrmBaseRoomerForm)
    pnlHolder: TsPanel;
    panBtn: TsPanel;
    BtnOk: TsButton;
    mnuOther: TPopupMenu;
    mnuiPrint: TMenuItem;
    N2: TMenuItem;
    Export1: TMenuItem;
    mnuiGridToExcel: TMenuItem;
    mnuiGridToHtml: TMenuItem;
    mnuiGridToText: TMenuItem;
    mnuiGridToXml: TMenuItem;
    m_: TdxMemData;
    DS: TDataSource;
    grPrinter: TdxComponentPrinter;
    prLink_grData: TdxGridReportLink;
    sPanel1: TsPanel;
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
    m_id: TIntegerField;
    sPanel4: TsPanel;
    lvRateCodes: TsListView;
    sPanel3: TsPanel;
    lbStartFrom: TsLabel;
    cbxChannelManager: TsComboBox;
    sLabel1: TsLabel;
    cbxPlanCode: TsComboBox;
    sPanel5: TsPanel;
    grData: TcxGrid;
    tvData: TcxGridDBTableView;
    tvDataRecId: TcxGridDBColumn;
    tvDatafromDate: TcxGridDBColumn;
    tvDatastop: TcxGridDBColumn;
    tvDataprice: TcxGridDBColumn;
    tvDatasingleUsePrice: TcxGridDBColumn;
    tvDataavailability: TcxGridDBColumn;
    tvDataminStay: TcxGridDBColumn;
    tvDatamaxStay: TcxGridDBColumn;
    tvDataclosedOnArrival: TcxGridDBColumn;
    tvDataclosedOnDeparture: TcxGridDBColumn;
    tvDatalengthOfStayArrivalDateBased: TcxGridDBColumn;
    lvData: TcxGridLevel;
    sPanel6: TsPanel;
    btnNew: TsButton;
    btnEdit: TsButton;
    btnDelete: TsButton;
    btnOther: TsButton;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
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
    procedure cbxChannelManagerCloseUp(Sender: TObject);
    procedure cbxPlanCodeCloseUp(Sender: TObject);
    procedure lvRateCodesChange(Sender: TObject; Item: TListItem; Change: TItemChange);
    procedure tvDatapriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
  private
    FIsUpdating : Boolean;
    FSelectedChannel : Integer;
    FSelectedPlanCode : Integer;
    FSelectedRate : Integer;
    procedure prepareSelectableList;
    procedure prepareRateListview(rateList : String);
  protected
    procedure DoLoadData; override;
    { Private declarations }
  public
    { Public declarations }
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
  , uD
  , uDateUtils
  , uSqlUtils
  , uRoomerCurrencymanager;

procedure EditMasterRateDefaults;
begin
  with TfrmMasterRateDefaults.Create(nil) do
  try
    ShowModal;
  finally
    Free;
  end;
end;


procedure TfrmMasterRateDefaults.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  if tvdata.DataController.DataSet.State in [dsInsert, dsEdit] then
    tvdata.DataController.Post;
  d.roomerMainDataSet.SystemPrepareChannelRates;
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

procedure TfrmMasterRateDefaults.btnRefreshClick(Sender: TObject);
begin
  Refreshdata;
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

procedure TfrmMasterRateDefaults.edtLastDateChange(Sender: TObject);
begin
  RefreshData;
end;

procedure TfrmMasterRateDefaults.DoLoadData;
var rSet : TRoomerDataSet;
begin
  inherited;
  if NOT Assigned(lvRateCodes.Selected) then exit;

  if ComponentRunning(Self) then
  begin
    m_.DisableControls;
    try
      rSet := CreateNewDataSet;
      try
        FSelectedRate := Integer(lvRateCodes.Selected.Data);
        hData.rSet_bySQL(rSet,
                            format('SELECT DATE(fromDate) AS fromDate, price, availability, minStay, maxStay, closedOnArrival, ' +
                                   'closedOnDeparture, stop, lengthOfStayArrivalDateBased, singleUsePrice, id ' +
                                   'FROM channelmasterratesdefaults WHERE channelManager=%d AND planCodeId=%d AND roomClassId=%d ORDER BY fromDate',
                                  [FSelectedChannel,
                                   FSelectedPlanCode,
                                   FSelectedRate]));
        rSet.First;
        if m_.active then m_.Close;
        m_.LoadFromDataSet(rSet);
        m_.Open;
      finally
        rSet.Free;
      end;
    finally
      m_.EnableControls;
    end;
  end;
end;

procedure TfrmMasterRateDefaults.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if (Key = VK_ESCAPE) and (m_.State IN [dsInsert, dsEdit]) then
  begin
    m_.Cancel;
    Key := 0;
  end;
end;

procedure TfrmMasterRateDefaults.FormShow(Sender: TObject);
begin
  prepareSelectableList;
  grData.SetFocus;
end;

procedure TfrmMasterRateDefaults.lvRateCodesChange(Sender: TObject; Item: TListItem; Change: TItemChange);
begin
  RefreshData;
end;

procedure TfrmMasterRateDefaults.prepareSelectableList;

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

  cbxPlanCodeCloseUp(cbxPlanCode);
  cbxChannelManagerCloseUp(cbxChannelManager);
end;

procedure TfrmMasterRateDefaults.tvDatapriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  inherited;
  RoomerCurrencyManager.DefaultCurrencyDefinition.SetcxEditProperties( aProperties);
end;

procedure TfrmMasterRateDefaults.prepareRateListview(rateList : String);
var id : Integer;
    strId : String;
    sIdList : TStrings;

    lvItem : TListItem;
begin
  lvRateCodes.OnChange := nil;
  lvRateCodes.Items.BeginUpdate;
  sIdList := TStringList.Create;
  try
    lvRateCodes.Items.Clear;
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
    sIdList.Free;
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
  id : Integer;
begin
  if LoadingData then exit;

  s := '';
  s := s+GetTranslatedText('shDeleteMasterRatesDefault')+' '+RoomerDateToString(DataSet['fromDate']) + #13#13;
  s := s+GetTranslatedText('shContinue');

  if MessageDlg(s,mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
    Abort
  else
  begin
    id := DataSet['id'];
    s := format(
         'DELETE FROM channelmasterratesdefaults WHERE id=%d',
         [id]);

    d.roomerMainDataSet.DoCommand(s);
  end;
end;

procedure TfrmMasterRateDefaults.m_BeforeInsert(DataSet: TDataSet);
begin
  if LoadingData then exit;
  tvData.GetColumnByFieldName('fromDate').Focused := True;
end;

procedure TfrmMasterRateDefaults.m_BeforePost(DataSet: TDataSet);
var s : String;
    id : Integer;
begin
  if LoadingData then exit;
  if FIsUpdating then exit;

  if dataset['fromDate'] < TDateTime.Today then raise Exception.Create(GetTranslatedText('DateCanNotBeFromThePast'));
  if dataset['price'] < 1.00 then raise Exception.Create(GetTranslatedText('RateIsTooLow'));
  if dataset['availability'] < -1 then raise Exception.Create(GetTranslatedText('AvailabilityIsTooLow'));
  if dataset['minStay'] < 0 then raise Exception.Create(GetTranslatedText('MinStayIsTooLow'));
  if (dataset['maxStay'] < 0) OR ((dataset['maxStay'] < dataset['minStay']) AND (dataset['maxStay'] > 0)) then raise Exception.Create(GetTranslatedText('MaxStayCanNotBeLowerThanMinStay'));
  if dataset['singleUsePrice'] < 0.00 then raise Exception.Create(GetTranslatedText('SingleUseRateIsTooLow'));

  FIsUpdating := True;
  try
    if DataSet.State = dsInsert then
    begin
      s := format(
           'INSERT INTO channelmasterratesdefaults (fromDate, ' +
           'price, availability, minstay, maxStay, closedOnArrival, closedOnDeparture, stop, lengthOfStayArrivalDateBased, ' +
           'singleUsePrice, channelManager, planCodeId, roomClassId) VALUES(' +
           '%s, %s, %d, %d, %d, %s, %s, %s, %s, %s, %d, %d, %d)',
           [_db(DataSet.FieldByName('fromDate').AsDateTime),
            _db(DataSet.FieldByName('price').AsFloat),
            DataSet.FieldByName('availability').AsInteger,
            DataSet.FieldByName('minStay').AsInteger,
            DataSet.FieldByName('maxStay').AsInteger,
            _db(DataSet.FieldByName('closedOnArrival').AsBoolean),
            _db(DataSet.FieldByName('closedOnDeparture').AsBoolean),
            _db(DataSet.FieldByName('stop').AsBoolean),
            _db(DataSet.FieldByName('lengthOfStayArrivalDateBased').AsBoolean),
            _db(DataSet.FieldByName('singleUsePrice').AsFloat),
            FSelectedChannel,
            FSelectedPlanCode,
            FSelectedRate]);

      id := d.roomerMainDataSet.DoCommand(s);
      if id <= 0 then
        raise Exception.Create('Adding master rate default unsuccessfully.');
      DataSet['id'] := id;
    end else
    if DataSet.State = dsEdit then
    begin
      id := DataSet['id'];
      s := format(
           'UPDATE channelmasterratesdefaults SET fromDate=%s, ' +
           'price=%s, availability=%d, minstay=%d, maxStay=%d, closedOnArrival=%s, closedOnDeparture=%s, stop=%s, lengthOfStayArrivalDateBased=%s, ' +
           'singleUsePrice=%s, channelManager=%d, planCodeId=%d, roomClassId=%d WHERE id=%d',
           [_db(DataSet.FieldByName('fromDate').AsDateTime),
            _db(DataSet.FieldByName('price').AsFloat),
            DataSet.FieldByName('availability').AsInteger,
            DataSet.FieldByName('minStay').AsInteger,
            DataSet.FieldByName('maxStay').AsInteger,
            _db(DataSet.FieldByName('closedOnArrival').AsBoolean),
            _db(DataSet.FieldByName('closedOnDeparture').AsBoolean),
            _db(DataSet.FieldByName('stop').AsBoolean),
            _db(DataSet.FieldByName('lengthOfStayArrivalDateBased').AsBoolean),
            _db(DataSet.FieldByName('singleUsePrice').AsFloat),
            FSelectedChannel,
            FSelectedPlanCode,
            FSelectedRate,
            id]);

      d.roomerMainDataSet.DoCommand(s);
    end;
  finally
    FIsUpdating := False;
  end;
end;

procedure TfrmMasterRateDefaults.m_NewRecord(DataSet: TDataSet);
begin
  if LoadingData then exit;

  if glb.LocateSpecificRecord('roomtypegroups', 'id', FSelectedRate) then
  begin
    dataset['fromDate'] := TDateTime.Today;
    dataset['stop'] := IIF(glb.RoomTypeGroups['connectStopSellToMasterRate'], glb.RoomTypeGroups['defStopSale'], False);
    dataset['price'] := IIF(glb.RoomTypeGroups['connectRateToMasterRate'], glb.RoomTypeGroups.FieldByName('defRate').AsFloat, 0.00);
    dataset['availability'] := IIF(glb.RoomTypeGroups['connectAvailabilityToMasterRate'], glb.RoomTypeGroups.FieldByName('defAvailability').AsInteger, -1);
    dataset['minStay'] := IIF(glb.RoomTypeGroups['connectMinStayToMasterRate'], glb.RoomTypeGroups.FieldByName('defMinStay').AsInteger, 0);
    dataset['maxStay'] := IIF(glb.RoomTypeGroups['connectMaxStayToMasterRate'], glb.RoomTypeGroups.FieldByName('defMaxStay').AsInteger, 0);
    dataset['closedOnArrival'] := IIF(glb.RoomTypeGroups['connectCOAToMasterRate'], glb.RoomTypeGroups['defClosedToArrival'], False);
    dataset['closedOnDeparture'] := IIF(glb.RoomTypeGroups['connectCODToMasterRate'], glb.RoomTypeGroups['defClosedToDeparture'], False);
    dataset['lengthOfStayArrivalDateBased'] := IIF(glb.RoomTypeGroups['connectLOSToMasterRate'], False, False);
    dataset['singleUsePrice'] := 0.00; // IIF(glb.RoomTypeGroups['connectSingleUseRateToMasterRate'], 0.00, 0.00);
  end else
  begin
    dataset['fromDate'] := TDateTime.Today;
    dataset['stop'] := False;
    dataset['price'] := 0.00;
    dataset['availability'] := -1;
    dataset['minStay'] := 0;
    dataset['maxStay'] := 0;
    dataset['closedOnArrival'] := False;
    dataset['closedOnDeparture'] := False;
    dataset['lengthOfStayArrivalDateBased'] := False;
    dataset['singleUsePrice'] := 0.00;
  end;
end;

end.
