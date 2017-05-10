unit uInvoiceOnObjects;

interface

uses
  uRoomerForm, Types
  , cxGraphics, cxLookAndFeels, cxLookAndFeelPainters, Vcl.Menus, dxSkinsCore, dxSkinCaramel, dxSkinCoffee,
  dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, cxControls, cxStyles, dxSkinscxPCPainter, cxCustomData,
  cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, Data.DB, cxDBData, cxMemo, cxTL, cxCheckBox, cxMaskEdit, cxCalc,
  cxCurrencyEdit, cxTLdxBarBuiltInMenu, Spring.Data.VirtualDataSet, Spring.Data.ObjectDataSet, frxClass, frxDBSet,
  System.Classes, System.Actions, Vcl.ActnList, Vcl.ImgList, Vcl.Controls, cxInplaceContainer, cxDBTL, cxTLData,
  Vcl.ExtCtrls, cxGridLevel, cxGridCustomTableView, cxGridTableView, cxGridDBTableView, cxGridCustomView, cxGrid,
  Vcl.StdCtrls, sCheckBox, cxButtons, sButton, sGroupBox, sEdit, sLabel, sPanel, dxPScxCommon, dxPScxGridLnk, cxClasses,
  cxPropertiesStore, Vcl.ComCtrls, sStatusBar
  , uRunningTabInvoiceViewAdapter, sTabControl, RoomerFinancialDataModel_ModelObjects, Vcl.Grids, Vcl.DBGrids,
  cxCalendar, AdvTreeComboBox
  ;

type

  TfrmInvoiceObjects = class(TfrmBaseRoomerForm)
    MainMenu1: TMainMenu;
    File1: TMenuItem;
    ExitandSave1: TMenuItem;
    N1: TMenuItem;
    Exit1: TMenuItem;
    Items1: TMenuItem;
    Add1: TMenuItem;
    Delete1: TMenuItem;
    pnlMain: TsPanel;
    GridImages: TImageList;
    N2: TMenuItem;
    Removetemporarily1: TMenuItem;
    Invoice2: TMenuItem;
    Print2: TMenuItem;
    PrintProforma1: TMenuItem;
    N3: TMenuItem;
    Downpayment1: TMenuItem;
    RemoveRoomRenttemporarity1: TMenuItem;
    N4: TMenuItem;
    SendItemToGroupInvoice: TMenuItem;
    pnlHeader: TsPanel;
    clabCurrency: TsLabel;
    edtCurrency: TsEdit;
    rgrInvoiceType: TsRadioGroup;
    alInvoices: TActionList;
    actSaveAndExit: TAction;
    actPrintInvoice: TAction;
    actPrintProforma: TAction;
    actInvoiceProperties: TAction;
    actDownPayment: TAction;
    actInfo: TAction;
    actAddLine: TAction;
    actDelLine: TAction;
    actRRtoTemp: TAction;
    actItemToTemp: TAction;
    actItemToGroupInvoice: TAction;
    actCompressLines: TAction;
    edtRate: TsEdit;
    clabRate: TsLabel;
    edtInvRefrence: TsEdit;
    clabRefrence: TsLabel;
    GuestName1: TMenuItem;
    Refrence1: TMenuItem;
    btnGetCurrency: TsButton;
    btnGetRate: TsButton;
    clabInvoice: TsLabel;
    edtRoomGuest: TsEdit;
    clabRoomGuest: TsLabel;
    StoreMain: TcxPropertiesStore;
    edtCustomer: TsEdit;
    clabCustomer: TsLabel;
    clabPId: TsLabel;
    edtPersonalId: TsEdit;
    edtName: TsEdit;
    edtAddress1: TsEdit;
    edtAddress2: TsEdit;
    edtAddress3: TsEdit;
    edtAddress4: TsEdit;
    clabCountry: TsLabel;
    clabAddress: TsLabel;
    cLabName: TsLabel;
    btnClearAddresses: TsButton;
    pnlBottom: TsPanel;
    memExtraText: TMemo;
    pnlButtons: TsPanel;
    btnRoomToTemp: TsButton;
    btnAddItem: TsButton;
    btnItemToTmp: TsButton;
    btnRemoveItem: TsButton;
    btnMoveItem: TsButton;
    btnMoveRoom: TsButton;
    btnRemoveLodgingTax2: TsButton;
    btnReservationNotes: TsButton;
    pnlLines: TsPanel;
    btnExit: TcxButton;
    btnInvoice: TcxButton;
    btnProforma: TcxButton;
    labTmpStatus: TsLabel;
    pnlTotals: TsPanel;
    clabTotalwoVAT: TsLabel;
    clavVAT: TsLabel;
    clabInvoiceTotal: TsLabel;
    edtTotal: TsEdit;
    edtVat: TsEdit;
    edtInvoiceTotal: TsEdit;
    sPanel3: TsPanel;
    labPayments: TsLabel;
    tvPayments: TcxGridDBTableView;
    lvPayments: TcxGridLevel;
    grPayments: TcxGrid;
    tvPaymentsPayDate: TcxGridDBColumn;
    tvPaymentsPayType: TcxGridDBColumn;
    tvPaymentsAmount: TcxGridDBColumn;
    tvPaymentsDescription: TcxGridDBColumn;
    tvPaymentsPayGroup: TcxGridDBColumn;
    tvPaymentsMemo: TcxGridDBColumn;
    tvPaymentsconfirmDate: TcxGridDBColumn;
    clabDownpayments: TsLabel;
    edtDownPayments: TsEdit;
    clabBalance: TsLabel;
    edtBalance: TsEdit;
    rptDsLines: TfrxDBDataset;
    clabForeignCurrency: TsLabel;
    edtForeignCurrency: TsEdit;
    grbInclutedTaxes: TsGroupBox;
    labLodgingTaxISK: TsLabel;
    labLodgingTaxNights: TsLabel;
    labTaxNights: TsLabel;
    ClabLodgingTaxCurrency: TsLabel;
    actAddPackage: TAction;
    Action2: TAction;
    chkShowPackage: TsCheckBox;
    mnuMoveItem: TPopupMenu;
    mnuMoveRoom: TPopupMenu;
    T1: TMenuItem;
    mnuMoveItemToSpecifiedRoomAndInvoiceIndex: TMenuItem;
    mnuMoveRoomRentFromRoomInvoiceToGroup: TMenuItem;
    mnuMoveRoomRentFromGroupToNormalRoomInvoice: TMenuItem;
    btnGetCustomer: TsButton;
    pnlDetails: TsPanel;
    mnuInvoiceIndex: TPopupMenu;
    N01: TMenuItem;
    N11: TMenuItem;
    N31: TMenuItem;
    N41: TMenuItem;
    N51: TMenuItem;
    N61: TMenuItem;
    N71: TMenuItem;
    N81: TMenuItem;
    N91: TMenuItem;
    I1: TMenuItem;
    N5: TMenuItem;
    N12: TMenuItem;
    btnSaveChanges: TsButton;
    S1: TMenuItem;
    N6: TMenuItem;
    mnuMoveItemToAnyOtherRoomAndInvoiceIndex: TMenuItem;
    N7: TMenuItem;
    mnuTransferRoomRentToDifferentRoom: TMenuItem;
    pnlPaymentButtons: TsPanel;
    btnAddDownPayment: TsButton;
    btnEditDownPayment: TsButton;
    btnDeleteDownpayment: TsButton;
    pnlPayments: TsPanel;
    odsPayments: TObjectDataSet;
    dsPaymentObjects: TDataSource;
    odsInvoicelines: TObjectDataSet;
    dsInvoicelinesObjects: TDataSource;
    tsInvocieIndex: TsTabControl;
    odsInvoicelinesDescription: TStringField;
    odsInvoicelinesItemtype: TStringField;
    odsInvoicelinesIndex_: TIntegerField;
    odsInvoicelinesID: TStringField;
    odsInvoicelinesParent: TStringField;
    odsInvoicelinesPurchaseDate: TDateField;
    odsInvoicelinesQuantity: TFloatField;
    odsInvoicelinesPrice: TFloatField;
    odsInvoicelinesTotalNetAmount: TFloatField;
    tlInvoicelLines: TcxDBTreeList;
    cxDBTreeList1ID: TcxDBTreeListColumn;
    cxDBTreeList1Description: TcxDBTreeListColumn;
    cxDBTreeList1Itemtype: TcxDBTreeListColumn;
    cxDBTreeList1Index_: TcxDBTreeListColumn;
    cxDBTreeList1Parent: TcxDBTreeListColumn;
    cxDBTreeList1PurchaseDate: TcxDBTreeListColumn;
    cxDBTreeList1Quantity: TcxDBTreeListColumn;
    cxDBTreeList1NettoPrice: TcxDBTreeListColumn;
    cxDBTreeList1TotalNetAmount: TcxDBTreeListColumn;
    odsInvoicelinesTreeID: TIntegerField;
    odsInvoicelinesTreeParent: TIntegerField;
    procedure FormShow(Sender: TObject);
    procedure tvPaymentsPayGroupGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure tsInvocieIndexChange(Sender: TObject);
    procedure btnRemoveItemClick(Sender: TObject);
    procedure odsInvoicelinesBeforeDelete(DataSet: TDataSet);
    procedure actDelLineExecute(Sender: TObject);
    procedure tsInvocieIndexDragDrop(Sender, Source: TObject; X, Y: Integer);
    procedure tsInvocieIndexDockOver(Sender: TObject; Source: TDragDockObject; X, Y: Integer; State: TDragState;
      var Accept: Boolean);
    procedure actAddLineExecute(Sender: TObject);
    procedure odsInvoicelinesNewRecord(DataSet: TDataSet);
    procedure tlInvoiceLinesDataChanged(Sender: TObject);
    procedure cxDBTreeList1PurchaseDateGetDisplayText(Sender: TcxTreeListColumn; ANode: TcxTreeListNode;
      var Value: string);
  private
    FRunningTabModel: TRunningTabInvoiceViewAdapter;
    FReservation: integer;
    FRoomReservation: integer;
    FActiveInvoiceIndex: integer;
    procedure SetActiveInvoiceIndex(const Value: integer);
    procedure DeleteCurrentItem;
    function GetCurrentInvoiceLine: TRunningTabInvoiceViewItem;
    procedure LinkDataSets;
  protected
    procedure DoUpdateControls; override;
    procedure DoLoadData; override;
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    property Reservation: integer read FReservation write FReservation;
    property RoomReservation: integer read FRoomReservation write FRoomReservation;
    property ActiveInvoiceIndex: integer read FActiveInvoiceIndex write SetActiveInvoiceIndex;
  end;

implementation

uses
  Spring.Collections
  , uBookingsRunningTabAPICaller
  , SysUtils
  , uAppGlobal
  , Graphics
  , uUtils
  , Dialogs
  , PrjConst
  , DateUtils
  ;

{$R *.DFM}


{ TfrmInvoiceObjects }

procedure TfrmInvoiceObjects.actAddLineExecute(Sender: TObject);
begin
  inherited;
  odsInvoiceLines.Insert;
end;

procedure TfrmInvoiceObjects.actDelLineExecute(Sender: TObject);
begin
  inherited;
  odsInvoicelines.Delete;
end;

procedure TfrmInvoiceObjects.btnRemoveItemClick(Sender: TObject);
begin
  inherited;
  DeleteCurrentItem;
  RefreshData;
end;

function TfrmInvoiceObjects.GetCurrentInvoiceLine: TRunningTabInvoiceViewItem;
begin
  if odsInvoicelines.Active and (odsInvoicelines.RecordCount > 0) then
    Result := odsInvoicelines.GetCurrentModel<TRunningTabInvoiceViewItem>
  else
    Result := nil;
end;

procedure TfrmInvoiceObjects.odsInvoicelinesBeforeDelete(DataSet: TDataSet);
begin
  inherited;
  if MessageDlg(GetTranslatedText('shTx_Invoice_DeleteItem'), mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
    Abort;
end;

procedure TfrmInvoiceObjects.odsInvoicelinesNewRecord(DataSet: TDataSet);
begin
  inherited;

  with GetCurrentInvoiceLine do
  begin
//    PurchaseDate := Now;
//    ProductType := itSale;
//    InvoiceIndex := ActiveInvoiceIndex;
  end;

end;

procedure TfrmInvoiceObjects.DeleteCurrentItem();
//var
//  lRunningTabAPI: TRunningTabAPICaller;
begin
//
//  lRunningTabAPI := TRunningTabAPICaller.Create;
//  try
//    lRunningTabAPI.DeleteRunningTabProductItem(GetCurrentInvoiceLine.ID);
//  finally
//    lRunningTabAPI.Free;
//  end;
end;


constructor TfrmInvoiceObjects.Create(aOwner: TComponent);
begin
  inherited;
  FRunningTabModel := TRunningTabInvoiceViewAdapter.Create;
end;

procedure TfrmInvoiceObjects.cxDBTreeList1PurchaseDateGetDisplayText(Sender: TcxTreeListColumn; ANode: TcxTreeListNode;
  var Value: string);
begin
  inherited;
  if (aNode.Values[Sender.ItemIndex] <= DateOf(0)) then
    Value := '';
end;

destructor TfrmInvoiceObjects.Destroy;
begin
  odsPayments.Close;
  odsInvoicelines.Close;
  FRunningTabModel.Free;
  inherited;
end;

procedure TfrmInvoiceObjects.DoLoadData;
var
  lRunningTabAPI: TBookingsRunningTabAPICaller;
begin
  inherited;
  odsPayments.DisableControls;
  odsInvoicelines.DisableControls;
  try
    odsPayments.Close;
    odsInvoicelines.Close;
    lRunningTabApi := TBookingsRunningTabAPICaller.Create;
    try
      if lRunningTabAPI.GetRunningTabRoomRes(FReservation, FRoomReservation, 0, FRunningTabModel.RunningTabsOverview) then
        LinkDataSets;
    finally
      lRunningTabAPI.Free;
    end;

  finally
    odsPayments.Open;
    odsInvoicelines.Open;
    odsPayments.EnableControls;
    odsInvoicelines.EnableControls;
  end;
end;

procedure TfrmInvoiceObjects.LinkDataSets;
var
  lPaymentsList: IObjectList;
  lInvoiceList: IObjectList;
begin
  lPaymentsList := FRunningTabModel.PaymentsList[FActiveInvoiceIndex];
  lInvoiceList := FRunningTabModel.InvoicelinesList[FActiveInvoiceIndex];
  if lPaymentsList <> nil then
    odsPayments.DataList := lPaymentsList;
  if lInvoiceList <> nil then
    odsInvoicelines.DataList := lInvoiceList;
end;

procedure TfrmInvoiceObjects.DoUpdateControls;
begin
  inherited;

end;

procedure TfrmInvoiceObjects.FormShow(Sender: TObject);
begin
  inherited;
  RefreshData;
end;

procedure TfrmInvoiceObjects.SetActiveInvoiceIndex(const Value: integer);
begin
  FActiveInvoiceIndex := Value;
  LinkDataSets;
end;

procedure TfrmInvoiceObjects.tlInvoiceLinesDataChanged(Sender: TObject);
begin
  inherited;
//
end;

procedure TfrmInvoiceObjects.tsInvocieIndexChange(Sender: TObject);
begin
  inherited;
  ActiveInvoiceIndex := tsInvocieIndex.TabIndex;
end;

procedure TfrmInvoiceObjects.tsInvocieIndexDockOver(Sender: TObject; Source: TDragDockObject; X, Y: Integer;
  State: TDragState; var Accept: Boolean);
begin
  inherited;
 //
end;

procedure TfrmInvoiceObjects.tsInvocieIndexDragDrop(Sender, Source: TObject; X, Y: Integer);
begin
  inherited;
 //
end;

procedure TfrmInvoiceObjects.tvPaymentsPayGroupGetDisplayText(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
//var
//  lPayment: TRunningTabPayment;
begin
//  inherited;
//  lPayment := odsPayments.GetCurrentModel<TRunningTabPayment>;
//  if assigned(lPayment) and glb.Paytypesset.Locate('payType', lPayment.PaytypeCode, []) then
//    aText := glb.Paytypesset.FieldByName('payGroup').asString
//  else
//    aText := '';
//
end;

initialization


end.
