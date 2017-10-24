unit uItemTransactionsReport;

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
  TfrmItemTransactionsReport = class(TfrmBaseRoomerForm)
    pageMain: TsPageControl;
    sheetMain: TsTabSheet;
    Panel1: TsPanel;
    btnExcelS1: TsButton;
    Panel3: TsPanel;
    gbxPeriodSelection: TsGroupBox;
    cbxMonth: TsComboBox;
    cbxYear: TsComboBox;
    btnRefresh: TsButton;
    mTrxList: TdxMemData;
    mTrxListReservation: TIntegerField;
    mTrxListCustomer: TWideStringField;
    mTrxListName: TWideStringField;
    mTrxListDS: TDataSource;
    tvTrxList : TcxGridDBTableView;
    lvTrxList : TcxGridLevel;
    gTrxList : TcxGrid;
    StoreMain: TcxPropertiesStore;
    btnShowReservation: TsButton;
    mTrxListGuestName: TWideStringField;
    mTrxListEVENT: TStringField;
    mTrxListContactName: TWideStringField;
    mTrxListArrival: TDateField;
    mTrxListDeparture: TDateField;
    mTrxListBookingId: TWideStringField;
    mTrxListRoom: TWideStringField;
    tvTrxListRecId: TcxGridDBColumn;
    tvTrxListReservation: TcxGridDBColumn;
    tvTrxListCustomer: TcxGridDBColumn;
    tvTrxListName: TcxGridDBColumn;
    tvTrxListGuestName: TcxGridDBColumn;
    tvTrxListEVENT: TcxGridDBColumn;
    tvTrxListContactName: TcxGridDBColumn;
    tvTrxListArrival: TcxGridDBColumn;
    tvTrxListDeparture: TcxGridDBColumn;
    tvTrxListBookingId: TcxGridDBColumn;
    tvTrxListRoom: TcxGridDBColumn;
    mTrxListSource: TWideStringField;
    mTrxListRoomReservation: TIntegerField;
    mTrxListItemId: TWideStringField;
    mTrxListPrice: TFloatField;
    mTrxListNumber: TFloatField;
    mTrxListTotal: TFloatField;
    mTrxListCountry: TWideStringField;
    mTrxListNationality: TWideStringField;
    tvTrxListSource: TcxGridDBColumn;
    tvTrxListItemId: TcxGridDBColumn;
    tvTrxListNumber: TcxGridDBColumn;
    tvTrxListPrice: TcxGridDBColumn;
    tvTrxListTotal: TcxGridDBColumn;
    tvTrxListRoomReservation: TcxGridDBColumn;
    tvTrxListCountry: TcxGridDBColumn;
    tvTrxListNationality: TcxGridDBColumn;
    mTrxListInvoiceNumber: TIntegerField;
    tvTrxListInvoiceNumber: TcxGridDBColumn;
    mTrxListItemName: TWideStringField;
    tvTrxListItemName: TcxGridDBColumn;
    tvTrxListdate: TcxGridDBColumn;
    tvTrxListtime: TcxGridDBColumn;
    mTrxListdate: TDateField;
    mTrxListtime: TTimeField;
    btnShowInvoice: TsButton;
    mTrxListGroupInvoice: TBooleanField;
    procedure btnRefreshClick(Sender : TObject);
    procedure btnShowReservationClick(Sender : TObject);
    procedure FormClose(Sender : TObject; var Action : TCloseAction);
    procedure tvTrxListDblClick(Sender : TObject);
    procedure btnExcelS1Click(Sender : TObject);
    procedure FormCreate(Sender: TObject);
    procedure cbxYearCloseUp(Sender: TObject);
    procedure mTrxListAfterScroll(DataSet: TDataSet);
    procedure tvTrxListInvoiceNumberGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AText: string);
    procedure tvTrxListPriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
    procedure btnShowInvoiceClick(Sender: TObject);
  private
    { Private declarations }
  protected
    procedure DoShow; override;
    procedure DoLoadData; override;
    procedure DoUpdateControls; override;
  public
    { Public declarations }
  end;

procedure ShowItemTransactionsReport;

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
  , ufrmInvoiceEdit;


{$R *.dfm}

procedure ShowItemTransactionsReport;
var _frmItemTransactionsReport : TfrmItemTransactionsReport;
begin
  _frmItemTransactionsReport := TfrmItemTransactionsReport.Create(nil);
  try
    _frmItemTransactionsReport.ShowModal;
  finally
    _frmItemTransactionsReport.Free;
  end;
end;

procedure TfrmItemTransactionsReport.btnExcelS1Click(Sender : TObject);
var
  sFilename : string;
  s : string;
begin
  dateTimeToString(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_ItemTransactions';
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


procedure TfrmItemTransactionsReport.mTrxListAfterScroll(DataSet: TDataSet);
begin
  UpdateControls;
end;

procedure TfrmItemTransactionsReport.btnRefreshClick(Sender : TObject);
begin
  RefreshData;
end;

procedure TfrmItemTransactionsReport.DoLoadData;
var
  sql : string;
  rSet : TRoomerDataSet;
  sFrom, sTo : String;
  sdF, sdT, sm : String;
begin
  screen.Cursor := crHourGlass;
  mTrxList.DisableControls;
  try
    d.roomerMainDataSet.SetTimeZoneComparedToUTC('');
    sdT := IntToStr(DaysInAMonth(StrToInt(cbxYear.Items[cbxYear.ItemIndex]), cbxMonth.ItemIndex));
    sdF := '01';
    sm := inttostr(cbxMonth.ItemIndex);
    if Length(sm) = 1 then sm := '0' + sm;
    if Length(sdT) = 1 then sdT := '0' + sm;

    sFrom := format('%s-%s-%s', [cbxYear.Items[cbxYear.ItemIndex], sm, sdF]);
    sTo := format('%s-%s-%s', [cbxYear.Items[cbxYear.ItemIndex], sm, sdT]);

    sql := format('SELECT il.logTime, il.ItemSource, il.action, il.Reservation, il.RoomReservation, il.SplitNumber, il.InvoiceNumber, il.ItemId, il.Price, il.Number, ' +
           'il.Currency, il.CurrencyRate, rr.GroupAccount, it.Description AS ItemName, ' +
           'rr.Room, rr.rrArrival, rr.rrDeparture, r.Customer, r.Name, r.ContactName, r.InvRefrence AS BookingId, ' +
           'p.Name AS GuestName, p.Country, p.Nationality, to_bool(il.ItemId=co.RoomRentItem) AS isRoomRentItem, to_bool(il.ItemId=co.StayTaxItem) AS isStayTaxItem ' +
           'FROM invoicelines_history il ' +
           'LEFT JOIN items it ON it.Item=il.ItemId ' +
           'LEFT JOIN roomreservations rr ON rr.RoomReservation=il.RoomReservation ' +
           'LEFT JOIN reservations r ON r.Reservation=rr.Reservation ' +
           'LEFT JOIN persons p ON p.RoomReservation=rr.RoomReservation AND MainName=1 ' +
           'JOIN control co ' +
           'WHERE DATE(il.logtime) BETWEEN ''%s'' AND ''%s'' ' +
           'GROUP BY il.ItemSource, il.ItemId, il.action, il.logTime, ItemId, Price, Number, InvoiceNumber ' +
           'ORDER BY il.ItemSource, il.ItemId, il.action, il.logTime',
           [
             sFrom, sTo
           ]);

    rSet := CreateNewDataSet;
    hData.rSet_bySQL(rSet, sql, false);
    try
      if mTrxList.Active then
        mTrxList.Close;
      mTrxList.open;
      rSet.First;
      while NOT rSet.Eof do
      begin
        if ((rSet['InvoiceNumber'] <= 0)
            OR ((rSet['isRoomRentItem'] OR rSet['isStayTaxItem']) AND (rSet['action'] <> 'DELETE_RECORD'))
//           AND (rSet['action'] = 'DELETE_RECORD')
           AND (ABS(rSet['Price'] * rSet['Number']) > 0)
        )
        then begin
          mTrxList.Append;

          mTrxListReservation.Asinteger  := rSet['Reservation'];
          mTrxListRoomReservation.Asinteger:= rSet['RoomReservation'];
          mTrxListCustomer.AsString      := rSet['Customer'];
          mTrxListName.AsString          := rSet['Name'];
          mTrxListGuestName.AsString     := rSet['GuestName'];
          mTrxListNumber.AsFloat         := rSet['Number'];
          mTrxListGroupInvoice.AsBoolean := rSet['GroupAccount'];
          mTrxListItemId.AsString        := rSet['ItemId'];
          mTrxListItemName.AsString      := rSet['ItemName'];
          mTrxListInvoiceNumber.AsString := rSet['InvoiceNumber'];
          mTrxListSource.AsString        := rSet['ItemSource'];
          mTrxListPrice.AsFloat          := rSet['Price'];
          mTrxListTotal.AsFloat          := rSet['Price'] * rSet['Number'];
          mTrxListCountry.AsString       := rSet['Country'];
          mTrxListNationality.AsString   := rSet['Nationality'];
          if (rSet['InvoiceNumber'] > 0) AND
             (rSet['action'] = 'NEW_RECORD')  then
            mTrxListEVENT.AsString         := 'ADDED TO INVOICE' else
          if rSet['action'] = 'DELETE_RECORD' then
              mTrxListEVENT.AsString         := 'REMOVED ITEM'
          else if rSet['action'] = 'NEW_RECORD' then
              mTrxListEVENT.AsString         := 'ADDED ITEM'
          else if rSet['action'] = 'UPDATE_RECORD' then
              mTrxListEVENT.AsString         := 'UPDATED ITEM';
          mTrxListDate.AsDateTime        := rSet.fieldByName('logTime').AsDateTime;
          mTrxListTime.AsDateTime        := rSet.fieldByName('logTime').AsDateTime;
          mTrxListContactName.AsString   := rSet['ContactName'];
          mTrxListArrival.AsDateTime     := trunc(rSet.fieldByName('rrArrival').AsDateTime);
          mTrxListDeparture.AsDateTime   := trunc(rSet.fieldByName('rrDeparture').AsDateTime);
          mTrxListBookingId.AsString     := rSet['BookingId'];
          mTrxListRoom.AsString          := rSet['Room'];

          mTrxList.Post;
        end;

        rSet.Next;
      end;
    finally
      freeandNil(rSet);
    end;

    mTrxList.First;
  finally
    mTrxList.EnableControls;
    d.roomerMainDataSet.SetTimeZoneComparedToUTC('UTC');
    screen.Cursor := crDefault;
  end;
end;


procedure TfrmItemTransactionsReport.tvTrxListDblClick(Sender : TObject);
begin
  btnShowReservation.Click;
end;

procedure TfrmItemTransactionsReport.tvTrxListInvoiceNumberGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; var AText: string);
begin
  inherited;
  if Arecord.Values[tvTrxListInvoiceNumber.index] <= 0 then
    AText := ''
  else
    AText := IntToStr(Arecord.Values[tvTrxListInvoiceNumber.index]);
end;

procedure TfrmItemTransactionsReport.tvTrxListPriceGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmItemTransactionsReport.cbxYearCloseUp(Sender: TObject);
begin
  UpdateControls;
end;

procedure TfrmItemTransactionsReport.FormClose(Sender : TObject; var Action : TCloseAction);
begin
  if frmRptbViewer <> nil then
    freeandNil(frmRptbViewer);
end;

procedure TfrmItemTransactionsReport.FormCreate(Sender: TObject);
begin
  glb.fillListWithMonthsLong(cbxMonth.Items, 1);
  glb.fillListWithYears(cbxYear.Items, 1, False);
end;

procedure TfrmItemTransactionsReport.DoShow;
begin
  cbxMonth.ItemIndex := Month(Now);
  cbxYear.ItemIndex := cbxYear.Items.IndexOf(inttostr(Year(Now)));
  cbxYearCloseUp(cbxYear);
  inherited;
end;

procedure TfrmItemTransactionsReport.DoUpdateControls;
begin
  btnExcelS1.Enabled := NOT (mTrxList.Eof OR mTrxList.Bof);
  btnShowReservation.Enabled := NOT (mTrxList.Eof OR mTrxList.Bof);
  btnShowInvoice.Enabled := (NOT (mTrxList.Eof OR mTrxList.Bof) ) AND (mTrxListInvoiceNumber.AsInteger > 0);
  btnShowInvoice.Visible := btnShowInvoice.Enabled;
  btnRefresh.Enabled := (cbxYear.ItemIndex >= 0) AND (cbxMonth.ItemIndex >= 0);
end;

// -------------------------------------------------------------------------------
//
// Buttons
//
//
// --------------------------------------------------------------------------------

procedure TfrmItemTransactionsReport.btnShowInvoiceClick(Sender: TObject);
begin
  if mTrxList.RecordCount = 0 then
    exit;
  if (mTrxList.Eof OR mTrxList.Bof) then
    exit;

  if (mTrxListInvoiceNumber.AsInteger <= 0) AND
     (mTrxListGroupInvoice.AsBoolean) then
    EditInvoice(mTrxListReservation.AsInteger, 0, 0, 0, false)
  else
  if (mTrxListInvoiceNumber.AsInteger <= 0) AND
     (NOT mTrxListGroupInvoice.AsBoolean) then
    EditInvoice(mTrxListReservation.AsInteger, mTrxListRoomReservation.AsInteger, 0, 0, false)
  else
  if (mTrxListInvoiceNumber.AsInteger > 0) AND
     (NOT mTrxListGroupInvoice.AsBoolean) then
    ShowFinishedInvoices2(itPerRoomRes, '', mTrxListRoomReservation.AsInteger)
  else
  if (mTrxListInvoiceNumber.AsInteger > 0) AND
     (mTrxListGroupInvoice.AsBoolean) then
    ShowFinishedInvoices2(itPerReservation, '', mTrxListReservation.AsInteger);
end;

procedure TfrmItemTransactionsReport.btnShowReservationClick(Sender : TObject);
begin
  if mTrxList.RecordCount = 0 then
    exit;
  if (mTrxList.Eof OR mTrxList.Bof) then
    exit;

  EditReservation(mTrxListReservation.AsInteger, mTrxListRoomReservation.AsInteger);
end;

end.
