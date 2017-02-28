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
  , uRoomerHotelServicesCommunicationModel_RunningTabs, uRunningTabModel, sTabControl
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
    tlInvoiceLines: TcxDBTreeList;
    cxDBTreeList1cxDBTreeListColumn7: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn1: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn2: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn3: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn4: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn5: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn6: TcxDBTreeListColumn;
    dsInvoicelinesObjects: TDataSource;
    tsInvocieIndex: TsTabControl;
    procedure FormShow(Sender: TObject);
    procedure tvPaymentsPayGroupGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure tsInvocieIndexChange(Sender: TObject);
    procedure btnRemoveItemClick(Sender: TObject);
    procedure odsInvoicelinesBeforeDelete(DataSet: TDataSet);
    procedure actDelLineUpdate(Sender: TObject);
    procedure actDelLineExecute(Sender: TObject);
    procedure tlInvoiceLinesStartDrag(Sender: TObject; var DragObject: TDragObject);
    procedure tsInvocieIndexDragDrop(Sender, Source: TObject; X, Y: Integer);
    procedure tsInvocieIndexDockOver(Sender: TObject; Source: TDragDockObject; X, Y: Integer; State: TDragState;
      var Accept: Boolean);
  private
    FRunningTabModel: TRunningTabViewAdapter;
    FReservation: integer;
    FRoomReservation: integer;
    FActiveInvoiceIndex: integer;
    procedure SetActiveInvoiceIndex(const Value: integer);
    procedure DeleteCurrentItem;
    function GetCurrentInvoiceLine: TRunningTabProduct;
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
  , uServicesRunningTabAPICaller
  , SysUtils
  , uAppGlobal
  , Graphics
  , uUtils
  , Dialogs
  , PrjConst
  ;

{$R *.DFM}


{ TfrmInvoiceObjects }

procedure TfrmInvoiceObjects.actDelLineExecute(Sender: TObject);
begin
  inherited;
  odsInvoicelines.Delete;
end;

procedure TfrmInvoiceObjects.actDelLineUpdate(Sender: TObject);
var
  lInvLine: TRunningTabProduct;
begin
  inherited;
  lInvLine := GetCurrentInvoiceLine;
  actDelLine.Enabled := Assigned(lInvLine) and (lInvLine.ProductType = itSale);
end;

procedure TfrmInvoiceObjects.btnRemoveItemClick(Sender: TObject);
begin
  inherited;
  DeleteCurrentItem;
  RefreshData;
end;

function TfrmInvoiceObjects.GetCurrentInvoiceLine: TRunningTabProduct;
begin
  if odsInvoicelines.Active and (odsInvoicelines.RecordCount > 0) then
    Result := odsInvoicelines.GetCurrentModel<TRunningTabProduct>
  else
    Result := nil;
end;

procedure TfrmInvoiceObjects.odsInvoicelinesBeforeDelete(DataSet: TDataSet);
begin
  inherited;
  if MessageDlg(GetTranslatedText('shTx_Invoice_DeleteItem'), mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
    Abort;
end;

procedure TfrmInvoiceObjects.DeleteCurrentItem();
var
  lRunningTabAPI: TRunningTabAPICaller;
begin

  lRunningTabAPI := TRunningTabAPICaller.Create;
  try
    lRunningTabAPI.DeleteRunningTabProductItem(GetCurrentInvoiceLine.ID);
  finally
    lRunningTabAPI.Free;
  end;
end;


constructor TfrmInvoiceObjects.Create(aOwner: TComponent);
begin
  inherited;
  FRunningTabModel := TRunningTabViewAdapter.Create;
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
  lRunningTabAPI: TRunningTabAPICaller;
  lList: IObjectList;
begin
  inherited;

  odsPayments.DisableControls;
  odsInvoicelines.DisableControls;
  try
    odsPayments.Close;
    odsInvoicelines.Close;
    lRunningTabApi := TRunningTabAPICaller.Create;
    try
      lRunningTabAPI.GetRunningTabRoomRes(FRoomReservation, FRunningTabModel.RunningTabsOverview, [TRunningTabAPICaller.TRunningTabOption.SplitOnInvoiceIndex]);

      UpdateControls;
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

procedure TfrmInvoiceObjects.DoUpdateControls;
begin
  inherited;

  odsPayments.DataList := FRunningTabModel.PaymentsList[FActiveInvoiceIndex];
  odsInvoicelines.DataList := FRunningTabModel.InvoicelinesList[FActiveInvoiceIndex];
end;

procedure TfrmInvoiceObjects.FormShow(Sender: TObject);
begin
  inherited;
  RefreshData;
end;

procedure TfrmInvoiceObjects.SetActiveInvoiceIndex(const Value: integer);
begin
  FActiveInvoiceIndex := Value;
  UpdateControls;
end;

procedure TfrmInvoiceObjects.tlInvoiceLinesStartDrag(Sender: TObject; var DragObject: TDragObject);
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
var
  lPayment: TRunningTabPayment;
begin
  inherited;
  lPayment := odsPayments.GetCurrentModel<TRunningTabPayment>;
  if assigned(lPayment) and glb.Paytypesset.Locate('payType', lPayment.PaytypeCode, []) then
    aText := glb.Paytypesset.FieldByName('payGroup').asString
  else
    aText := '';

end;

initialization


end.
