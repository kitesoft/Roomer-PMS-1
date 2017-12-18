unit uFinanceTransactionReport;

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
  TfrmFinanceTransactionReport = class(TfrmBaseRoomerForm)
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
    mTrxListtransactionId: TWideStringField;
    mTrxListTransactionAmountNet: TFloatField;
    mTrxListTransactionAmountGross: TFloatField;
    mTrxListBusinessDate: TDateField;
    mTrxListTransactionCode: TWideStringField;
    mTrxListTransactionCodeGroup: TWideStringField;
    mTrxListTransactionCodeSubgroup: TWideStringField;
    mTrxListUpdateTimestamp: TDateTimeField;
    mTrxListReservationID: TWideStringField;
    mTrxListRoomReservationID: TIntegerField;
    mTrxListreportStart: TDateTimeField;
    mTrxListreportEnd: TDateTimeField;
    mTrxListisChanged: TBooleanField;
    mTrxListCodeDescription: TWideStringField;
    mTrxListCodeGroupDescription: TWideStringField;
    tvTrxListRecId: TcxGridDBColumn;
    tvTrxListtransactionId: TcxGridDBColumn;
    tvTrxListTransactionAmountNet: TcxGridDBColumn;
    tvTrxListTransactionAmountGross: TcxGridDBColumn;
    tvTrxListBusinessDate: TcxGridDBColumn;
    tvTrxListTransactionCode: TcxGridDBColumn;
    tvTrxListTransactionCodeGroup: TcxGridDBColumn;
    tvTrxListTransactionCodeSubgroup: TcxGridDBColumn;
    tvTrxListUpdateTimestamp: TcxGridDBColumn;
    tvTrxListReservationID: TcxGridDBColumn;
    tvTrxListRoomReservationID: TcxGridDBColumn;
    tvTrxListreportStart: TcxGridDBColumn;
    tvTrxListreportEnd: TcxGridDBColumn;
    tvTrxListisChanged: TcxGridDBColumn;
    tvTrxListCodeDescription: TcxGridDBColumn;
    tvTrxListCodeGroupDescription: TcxGridDBColumn;
    dtDateFrom: TsDateEdit;
    dtDateTo: TsDateEdit;
    sLabel1: TsLabel;
    sLabel2: TsLabel;
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

procedure ShowFinanceMutationsReport;

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

procedure ShowFinanceMutationsReport;
var _frmFinanceTransactionReport : TfrmFinanceTransactionReport;
begin
  _frmFinanceTransactionReport := TfrmFinanceTransactionReport.Create(nil);
  try
    _frmFinanceTransactionReport.ShowModal;
  finally
    _frmFinanceTransactionReport.Free;
  end;
end;

procedure TfrmFinanceTransactionReport.btnExcelS1Click(Sender : TObject);
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


procedure TfrmFinanceTransactionReport.mTrxListAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmFinanceTransactionReport.btnRefreshClick(Sender : TObject);
begin
  RefreshData;
end;

procedure TfrmFinanceTransactionReport.DoLoadData;
var
  xml : string;
  sFrom, sTo : String;
  Doc: IXMLDomDocument;
  node: IXMLDomNode;
  nodes_tab: IXMLDomNodeList;
  i : Integer;
  l: Integer;
begin
  screen.Cursor := crHourGlass;
  mTrxList.DisableControls;
  try
    d.roomerMainDataSet.SetTimeZoneComparedToUTC('');
    sFrom := format('%sT00:00:01', [uDateUtils.dateToSqlString(dtDateFrom.Date)]);
    sTo := format('%sT23:59:59', [uDateUtils.dateToSqlString(dtDateTo.Date)]);

    xml := d.roomerMainDataSet.downloadUrlAsString(  d.roomerMainDataSet.RoomerUri + format('statistics/aggragatedsales?startdateTime=%s&enddateTime=%s',
      [sFrom, sTo]));

    Doc := CreateOleObject('Microsoft.XMLDOM') as IXMLDOMDocument;
    Doc.async := False;
    Doc.loadXML(xml);
    if Doc.parseError.errorCode <> 0 then
      raise Exception.Create('XML Load error:' + Doc.parseError.reason);

    if mTrxList.Active then
      mTrxList.Close;
    mTrxList.open;

    nodes_tab := Doc.selectNodes('/finances/financeTransaction');

    for i := 0 to nodes_tab.length - 1 do
    begin
      node := nodes_tab.item[i];
      if node.NodeName = 'financeTransaction' then
      begin
        mTrxList.Append;
        for l := 0 to node.childNodes.length - 1 do
        begin
          if node.childNodes[l].NodeName = 'TransactionID' then
            mTrxListtransactionId.AsString := node.childNodes[l].Text;
          if node.childNodes[l].NodeName = 'TransactionAmountNet' then
            mTrxListTransactionAmountNet.AsFloat := _StrToFloat(node.childNodes[l].Text);
          if node.childNodes[l].NodeName = 'TransactionAmountGross' then
            mTrxListTransactionAmountGross.AsFloat := _StrToFloat(node.childNodes[l].Text);
          if node.childNodes[l].NodeName = 'BusinessDate' then
            mTrxListBusinessDate.AsDateTime := uDateUtils.XmlStringToDate(node.childNodes[l].Text);
          if node.childNodes[l].NodeName = 'TransactionCode' then
          begin
            mTrxListTransactionCode.AsString := node.childNodes[l].Text;
            if glb.LocateSpecificRecord('items', 'Item', node.childNodes[l].Text) then
              mTrxListCodeDescription.AsString := glb.Items['Description'];
          end;
          if node.childNodes[l].NodeName = 'TransactionCodeGroup' then
          begin
            mTrxListTransactionCodeGroup.AsString := node.childNodes[l].Text;
            if glb.LocateSpecificRecord('itemtypes', 'ItemType', node.childNodes[l].Text) then
              mTrxListCodeGroupDescription.AsString := glb.ItemTypes['Description'];
          end;
          if node.childNodes[l].NodeName = 'TransactionCodeSubgroup' then
            mTrxListTransactionCodeSubgroup.AsString := node.childNodes[l].Text;
          if node.childNodes[l].NodeName = 'UpdateTimestamp' then
            mTrxListUpdateTimestamp.AsDateTime := uDateUtils.XmlStringToDate(node.childNodes[l].Text);
          if node.childNodes[l].NodeName = 'ReservationID' then
            mTrxListReservationID.AsString := node.childNodes[l].Text;
          if node.childNodes[l].NodeName = 'RoomReservationID' then
            mTrxListRoomReservationID.AsInteger := StrToInt(node.childNodes[l].Text);
//          if node.childNodes[l].NodeName = 'reportStart' then
//            mTrxListreportStart.AsDateTime := node.childNodes[l].Text;
//          if node.childNodes[l].NodeName = 'reportEnd' then
//            mTrxListreportEnd.AsDateTime := node.childNodes[l].Text;
//          if node.childNodes[l].NodeName = 'isChanged' then
//            mTrxListisChanged.AsBoolean := node.childNodes[l].Text;
//          if node.childNodes[l].NodeName = 'CodeDescription' then
//            mTrxListCodeDescription.AsString := node.childNodes[l].Text;
//          if node.childNodes[l].NodeName = 'CodeGroupDescription' then
//            mTrxListCodeGroupDescription.AsString := node.childNodes[l].Text;
        end;
        mTrxList.Post;
      end;
    end;

    mTrxList.First;
  finally
    mTrxList.EnableControls;
    d.roomerMainDataSet.SetTimeZoneComparedToUTC('UTC');
    screen.Cursor := crDefault;
  end;
end;


procedure TfrmFinanceTransactionReport.tvTrxListPriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmFinanceTransactionReport.cbxYearCloseUp(Sender: TObject);
begin
  UpdateControls;
end;

procedure TfrmFinanceTransactionReport.FormClose(Sender : TObject; var Action : TCloseAction);
begin
  if frmRptbViewer <> nil then
    freeandNil(frmRptbViewer);
end;

procedure TfrmFinanceTransactionReport.FormCreate(Sender: TObject);
begin
  dtDateFrom.Date := Trunc(now);
  dtDateTo.Date := Trunc(now);
end;

procedure TfrmFinanceTransactionReport.DoShow;
begin
  inherited;
end;

procedure TfrmFinanceTransactionReport.DoUpdateControls;
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
