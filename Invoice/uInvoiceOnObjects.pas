unit uInvoiceOnObjects;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Grids, ExtCtrls, ComCtrls, StdCtrls, ImgList, Menus, Buttons, Data.DB,
  Data.Win.ADODB

    , uDateUtils, ActnList, System.Actions, Generics.Collections, variants,
  cmpRoomerDataSet

    , _glob, hData, ug, uUtils, kbmMemTable

    , uTaxCalc

    , AdvObj, BaseGrid, AdvGrid

    , sPanel, sEdit, sLabel, sGroupBox, sStatusBar, sButton, sSkinProvider,
  sPageControl

    , cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles,
  dxSkinsCore, dxSkinDarkSide, dxSkinDevExpressDarkStyle, dxSkinMcSkin,
  dxSkinOffice2013White, dxSkinsDefaultPainters, dxSkinscxPCPainter,
  cxCustomData, cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, cxDBData,
  cxMemo,
  cxButtonEdit, cxSpinEdit, cxCalc, cxContainer

    , frxExportMail, frxExportImage, frxExportRTF, frxExportHTML, frxClass,
  frxExportPDF, frxDesgn, frxDBSet

    , cxPropertiesStore, sCheckBox, cxTextEdit, cxMaskEdit, cxDropDownEdit,
  cxGridLevel, cxGridCustomTableView, cxGridTableView, cxGridDBTableView,
  cxClasses,
  cxGridCustomView, cxGrid

    , dxmdaset, dxSkinCaramel, dxSkinCoffee, dxSkinTheAsphaltWorld, dxSkinBlack,
  dxSkinBlue, dxSkinBlueprint, dxSkinDarkRoom,
  dxSkinDevExpressStyle, dxSkinFoggy, dxSkinGlassOceans, dxSkinHighContrast,
  dxSkiniMaginary, dxSkinLilian, dxSkinLiquidSky,
  dxSkinLondonLiquidSky, dxSkinMoneyTwins, dxSkinOffice2007Black,
  dxSkinOffice2007Blue, dxSkinOffice2007Green, dxSkinOffice2007Pink,
  dxSkinOffice2007Silver, dxSkinOffice2010Black, dxSkinOffice2010Blue,
  dxSkinOffice2010Silver, dxSkinPumpkin, dxSkinSeven,
  dxSkinSevenClassic, dxSkinSharp, dxSkinSharpPlus, dxSkinSilver,
  dxSkinSpringTime, dxSkinStardust, dxSkinSummer2008, dxSkinValentine,
  dxSkinVS2010, dxSkinWhiteprint, dxSkinXmas2008Blue, cxButtons, sComboBox,
  sSpeedButton, AdvUtil
  , uInvoiceEntities, Spring.Data.VirtualDataSet, Spring.Data.ObjectDataSet, uInvoiceContainer
  , uServicesRunningTabAPICaller
  , uRoomerHotelServicesCommunicationModel_RunningTabs, cxTL, cxTLdxBarBuiltInMenu, cxInplaceContainer, cxTLData, cxDBTL,
  cxCurrencyEdit, cxCheckBox
  ,uRoomerForm, dxPScxCommon, dxPScxGridLnk
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
    Panel1: TsPanel;
    clabCurrency: TsLabel;
    edtCurrency: TsEdit;
    rgrInvoiceType: TsRadioGroup;
    act: TActionList;
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
    Panel2: TsPanel;
    memExtraText: TMemo;
    Panel4: TsPanel;
    btnRoomToTemp: TsButton;
    btnAddItem: TsButton;
    btnItemToTmp: TsButton;
    btnRemoveItem: TsButton;
    btnMoveItem: TsButton;
    btnMoveRoom: TsButton;
    btnRemoveLodgingTax2: TsButton;
    btnReservationNotes: TsButton;
    sPanel1: TsPanel;
    btnExit: TcxButton;
    btnInvoice: TcxButton;
    btnProforma: TcxButton;
    labTmpStatus: TsLabel;
    sPanel2: TsPanel;
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
    tvPaymentsid: TcxGridDBColumn;
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
    sPanel5: TsPanel;
    sPanel4: TsPanel;
    pnlInvoiceIndex0: TsPanel;
    pnlInvoiceIndex1: TsPanel;
    pnlInvoiceIndex2: TsPanel;
    pnlInvoiceIndex3: TsPanel;
    pnlInvoiceIndex4: TsPanel;
    pnlInvoiceIndex5: TsPanel;
    pnlInvoiceIndex6: TsPanel;
    pnlInvoiceIndex7: TsPanel;
    pnlInvoiceIndex8: TsPanel;
    pnlInvoiceIndex9: TsPanel;
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
    shpInvoiceIndex0: TShape;
    shpInvoiceIndexRR0: TShape;
    shpInvoiceIndex9: TShape;
    shpInvoiceIndexRR9: TShape;
    shpInvoiceIndex1: TShape;
    shpInvoiceIndexRR1: TShape;
    shpInvoiceIndex2: TShape;
    shpInvoiceIndexRR2: TShape;
    shpInvoiceIndex3: TShape;
    shpInvoiceIndexRR3: TShape;
    shpInvoiceIndex4: TShape;
    shpInvoiceIndexRR4: TShape;
    shpInvoiceIndex5: TShape;
    shpInvoiceIndexRR5: TShape;
    shpInvoiceIndex6: TShape;
    shpInvoiceIndexRR6: TShape;
    shpInvoiceIndex7: TShape;
    shpInvoiceIndexRR7: TShape;
    shpInvoiceIndex8: TShape;
    shpInvoiceIndexRR8: TShape;
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
    cxDBTreeList1: TcxDBTreeList;
    cxDBTreeList1cxDBTreeListColumn7: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn1: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn2: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn3: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn4: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn5: TcxDBTreeListColumn;
    cxDBTreeList1cxDBTreeListColumn6: TcxDBTreeListColumn;
    dsInvoicelinesObjects: TDataSource;
  private
    FRunningTabOverView: TRunningTabsOverview;
    FReservation: integer;
    FRoomReservation: integer;
  protected
    procedure DoUpdateControls; override;
    procedure DoLoadData; override;
  public
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    property Reservation: integer read FReservation write FReservation;
    property RoomReservation: integer read FRoomReservation write FRoomReservation;
  end;

procedure EditInvoice(reservation, RoomReservation, SplitNumber, InvoiceIndex: integer;
  Arrival, Departure: TDate; bCredit: boolean; FromKredit: boolean = false);

implementation

uses
  Spring.Collections
  ;

{$R *.DFM}


procedure EditInvoice(reservation, RoomReservation, SplitNumber, InvoiceIndex: integer;
  Arrival, Departure: TDate; bCredit: boolean; FromKredit: boolean = false);
var
  _frmInvoice: TfrmInvoiceObjects;
begin
  _frmInvoice := TfrmInvoiceObjects.create(nil);
  try
    _frmInvoice.reservation := reservation;
    _frmInvoice.RoomReservation := RoomReservation;
//    _frmInvoice.FnewSplitNumber := SplitNumber;
//    _frmInvoice.FInvoiceIndex := InvoiceIndex;
//    _frmInvoice.FIsCredit := bCredit;
//    _frmInvoice.zNativeCurrency := ctrlGetString('NativeCurrency');
//    _frmInvoice.zFromKredit := FromKredit;

    _frmInvoice.ShowModal;
  finally
    FreeAndNil(_frmInvoice);
  end;
end;


{ TfrmInvoiceObjects }

constructor TfrmInvoiceObjects.Create(aOwner: TComponent);
begin
  inherited;
  FRunningTabOverView := TRunningTabsOverview.Create;
end;

destructor TfrmInvoiceObjects.Destroy;
begin
  odsPayments.Close;
  odsInvoicelines.Close;
  FRunningTabOverView.Free;
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
      lRunningTabAPI.GetRunningTabRoomRes(FRoomReservation, True, FRunningTabOverView);

      if Supports(FRunningTabOverView.RunningTabList.First.PaymentList, IObjectList, lList) then
        odsPayments.DataList := lList;

      if Supports(FRunningTabOverView.RunningTabList.First.ProductList, IObjectList, lList) then
        odsInvoicelines.DataList := lList;
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

end;

initialization


end.
