unit ufrmInvoiceEdit;

interface

uses
  Windows,
  Messages,
  SysUtils,
  Classes,
  Graphics,
  Controls,
  Forms,
  Dialogs,
  Grids,
  ExtCtrls,
  ComCtrls,
  StdCtrls,
  ImgList,
  Menus,
  Buttons,
  Data.DB,
  Data.Win.ADODB,
  uDateUtils,
  ActnList,
  System.Actions,
  variants,
  cmpRoomerDataSet,
  cxGraphics,
  cxControls,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  cxStyles,
  dxSkinsCore,
  dxSkinCaramel,
  dxSkinCoffee,
  dxSkinDarkSide,
  dxSkinTheAsphaltWorld,
  dxSkinsDefaultPainters,
  dxSkinscxPCPainter,
  cxCustomData,
  cxFilter,
  cxData,
  cxDataStorage,
  cxEdit,
  cxNavigator,
  cxDBData,
  cxMemo,
  AdvUtil,
  dxmdaset,
  frxClass,
  frxDBSet,
  cxPropertiesStore,
  sStatusBar,
  AdvObj,
  BaseGrid,
  AdvGrid,
  cxGridLevel,
  cxGridCustomTableView,
  cxGridTableView,
  cxGridDBTableView,
  cxClasses,
  cxGridCustomView,
  cxGrid, sScrollBox, sGroupBox, sButton, sEdit, sLabel, sPanel,
  _glob,
  hData,
  ug,
  uUtils,
  kbmMemTable,
  uTaxCalc,
  frxExportMail,
  frxExportImage,
  frxExportRTF,
  frxExportHTML,
  uInvoiceEntities,
  uInvoiceObjects
  , uInvoiceDefinitions, uRoomerBookingDataModel_ModelObjects
  , Spring.Collections.Lists
  , Spring.Collections, cxCheckBox, cxCurrencyEdit, sSplitter, uRoomerForm, dxPScxCommon, dxPScxGridLnk
  , RoomerExceptionHandling, ufraCurrencyPanel
  , uAmount
  ;

type
  TCreditType = (ctManual, ctReference, ctErr);
  TInvoiceSaveType = (stProvisionally, stProforma, stDefinitive);

  // Type of invoice, used to be called SplitNumber (and still is int he db)
  TInvoiceType = (itDebitInvoice = 0, itCreditInvoice = 1, itCashInvoice = 2);


  EInvocieException = class(ERoomerUserException);
{$M+}
  TRoomInfoList = TObjectlist<TInvoiceRoomEntity>;

  /// <summary>
  /// Used to indicate which automatically added items should be (re)generated
  /// </summary>
  TInvoiceAutoItem = (aiStayTax, aiIncludedBreakfast);
  TInvoiceAutoItemSet = set of TInvoiceAutoItem;

  // ------------------------------------------------------------------------------
  //
  // TfrmInvoice
  //
  // ------------------------------------------------------------------------------

  TfrmInvoiceEdit = class(TfrmBaseRoomerForm)
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
    pnlHead: TsPanel;
    clabCurrency: TsLabel;
    actInvoiceActions: TActionList;
    actSaveAndExit: TAction;
    actPrintInvoice: TAction;
    actPrintProforma: TAction;
    actInvoiceProperties: TAction;
    actAddDownPayment: TAction;
    actInfo: TAction;
    actAddLine: TAction;
    actRemoveSelected: TAction;
    actMoveItemToGroupInvoice: TAction;
    timCloseInvoice: TTimer;
    edtInvRefrence: TsLabel;
    clabRefrence: TsLabel;
    GuestName1: TMenuItem;
    Refrence1: TMenuItem;
    clabInvoice: TsLabel;
    edtRoomGuest: TsLabel;
    clabRoomGuest: TsLabel;
    pnlTotalsAndPayments: TsPanel;
    memExtraText: TMemo;
    pnlLineButtons: TsPanel;
    pnlLinesGrid: TsPanel;
    agrLines: TAdvStringGrid;
    btnExit: TsButton;
    btnInvoice: TsButton;
    btnProforma: TsButton;
    pnlTotals: TsPanel;
    clabTotalwoVAT: TsLabel;
    clavVAT: TsLabel;
    clabInvoiceTotal: TsLabel;
    edtTotalWOVat: TsEdit;
    edtVat: TsEdit;
    edtInvoiceTotal: TsEdit;
    PaymentsDS: TDataSource;
    sPanel3: TsPanel;
    labPayments: TsLabel;
    tvPayments: TcxGridDBTableView;
    lvPayments: TcxGridLevel;
    grPayments: TcxGrid;
    tvPaymentsPayDate: TcxGridDBColumn;
    tvPaymentsPayType: TcxGridDBColumn;
    tvPaymentNativeAmount: TcxGridDBColumn;
    tvPaymentsDescription: TcxGridDBColumn;
    tvPaymentsPayGroup: TcxGridDBColumn;
    tvPaymentsMemo: TcxGridDBColumn;
    tvPaymentsconfirmDate: TcxGridDBColumn;
    tvPaymentsid: TcxGridDBColumn;
    tvPaymentsRecId: TcxGridDBColumn;
    tvPaymentsInvoiceIndex: TcxGridDBColumn;
    tvPaymentsPaycardTraceIndex: TcxGridDBColumn;
    tvPaymentsCCCharged: TcxGridDBColumn;
    tvPaymentsCurrency: TcxGridDBColumn;
    tvPaymentsCurrencyAmount: TcxGridDBColumn;
    clabDownpayments: TsLabel;
    edtDownPayments: TsEdit;
    clabBalance: TsLabel;
    edtBalance: TsEdit;
    grbInclutedTaxes: TsGroupBox;
    labLodgingTax: TsLabel;
    labLodgingTaxNights: TsLabel;
    labTaxNights: TsLabel;
    actAddPackage: TAction;
    actAddRoom: TAction;
    mPayments: TdxMemData;
    mPaymentsPayDate: TDateField;
    mPaymentsPayType: TWideStringField;
    mPaymentsNativeAmount: TFloatField;
    mPaymentsDescription: TWideStringField;
    mPaymentsPayGroup: TWideStringField;
    mPaymentsMemo: TMemoField;
    mPaymentsconfirmDate: TDateTimeField;
    mPaymentsid: TIntegerField;
    mPaymentsInvoiceIndex: TIntegerField;
    mPaymentsPaycardTraceIndex: TIntegerField;
    mPaymentsChargedOnCC: TBooleanField;
    mPaymentsCurrency: TWideStringField;
    mPaymentsCurrencyAmount: TFloatField;
    mnuMoveRoom: TPopupMenu;
    mnuItemToGroupInvoice: TMenuItem;
    mnuItemToRoomInvoice: TMenuItem;
    mnuMoveRoomRentFromRoomInvoiceToGroup: TMenuItem;
    mnuMoveRoomRentFromGroupToNormalRoomInvoice: TMenuItem;
    pnlLnes: TsPanel;
    pnlInvoiceIndices: TsScrollBox;
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
    S1: TMenuItem;
    N6: TMenuItem;
    mnuMoveItemToAnyOtherRoomAndInvoiceIndex: TMenuItem;
    N7: TMenuItem;
    mnuTransferRoomRentToDifferentRoom: TMenuItem;
    mRoomRes: TdxMemData;
    mRoomResReservation: TIntegerField;
    mRoomResroomreservation: TIntegerField;
    mRoomResRoom: TStringField;
    mRoomResRoomType: TStringField;
    mRoomResGuests: TIntegerField;
    mRoomResAvragePrice: TFloatField;
    mRoomResRateCount: TIntegerField;
    mRoomResRoomDescription: TStringField;
    mRoomResRoomTypeDescription: TStringField;
    mRoomResArrival: TDateTimeField;
    mRoomResDeparture: TDateTimeField;
    mRoomResChildrenCount: TIntegerField;
    mRoomResinfantCount: TIntegerField;
    mRoomResPriceCode: TStringField;
    mRoomResAvrageDiscount: TFloatField;
    mRoomResPackage: TWideStringField;
    mRoomResInvoiceIndex: TIntegerField;
    mRoomResGroupAccount: TBooleanField;
    mRoomResGuestName: TWideStringField;
    mRoomRates: TdxMemData;
    mRoomRatesReservation: TIntegerField;
    mRoomRatesroomreservation: TIntegerField;
    mRoomRatesRoomNumber: TStringField;
    mRoomRatesRateDate: TDateTimeField;
    mRoomRatesPriceCode: TStringField;
    mRoomRatesRate: TFloatField;
    mRoomRatesDiscount: TFloatField;
    mRoomRatesisPercentage: TBooleanField;
    mRoomRatesShowDiscount: TBooleanField;
    mRoomRatesisPaid: TBooleanField;
    mRoomRatesDiscountAmount: TFloatField;
    mRoomRatesRentAmount: TFloatField;
    mRoomRatesNativeAmount: TFloatField;
    mRoomRatesGuestName: TWideStringField;
    lblResNr: TsLabel;
    edResNr: TsLabel;
    btnSaveChanges: TsButton;
    gbxHeader: TsGroupBox;
    clabCustomer: TsLabel;
    clabPId: TsLabel;
    clabCountry: TsLabel;
    clabAddress: TsLabel;
    cLabName: TsLabel;
    rgrInvoiceAddressType: TsRadioGroup;
    edtCustomer: TsEdit;
    edtPersonalId: TsEdit;
    edtName: TsEdit;
    edtAddress1: TsEdit;
    edtAddress2: TsEdit;
    edtAddress3: TsEdit;
    edtAddress4: TsEdit;
    btnClearAddresses: TsButton;
    btnGetCustomer: TsButton;
    actToggleLodgingTax: TAction;
    actMoveRoomToGroupInvoice: TAction;
    actMoveRoomToRoomInvoice: TAction;
    mnuShowOnInvoice: TPopupMenu;
    acShowAllCTax: TAction;
    acShowAlllBreakfasts: TAction;
    acShowAllDiscounts: TAction;
    acHideAllCTax: TAction;
    acHideAllBreakfasts: TAction;
    acHideAllDiscounts: TAction;
    mnuCityTax: TMenuItem;
    mnuBreakfast: TMenuItem;
    mnuDiscounts: TMenuItem;
    mnuShowAllCTax: TMenuItem;
    mnuHideallCitytax: TMenuItem;
    mnuShowallincludedbreakfasts: TMenuItem;
    mnuHideallincludedbreakfasts: TMenuItem;
    mnuShowalldiscounts: TMenuItem;
    mnuHidealldiscounts: TMenuItem;
    acShowpackageItems: TAction;
    acHidePackageItems: TAction;
    mnuPackages: TMenuItem;
    mnuShowPackageItems: TMenuItem;
    mnuHidePackageItems: TMenuItem;
    mnuMoveRoomToInvoiceIndex: TMenuItem;
    actRevertDownpayment: TAction;
    btnAddRoom: TsButton;
    btnMoveRoom: TsButton;
    btnAddItem: TsButton;
    btnMoveItem: TsButton;
    btnRemoveSelected: TsButton;
    btnToggleLodgingTax: TsButton;
    btnReservationNotes: TsButton;
    btnShowOnInvoice: TsButton;
    pnlPayments: TsPanel;
    pnlPaymentButtons: TsPanel;
    btnAddDownPayment: TsButton;
    btnRevertDownpayment: TsButton;
    btnEditDownpayment: TsButton;
    actEditDownPayment: TAction;
    actDeleteDownPayment: TAction;
    btnDeleteDownpayment: TsButton;
    splExtraInfo: TsSplitter;
    actSave: TAction;
    fraInvoiceCurrency: TfraCurrencyPanel;
    pnlTotalsInCurrency: TsPanel;
    lbTotalInCurrency: TsLabel;
    edtTotalInCurrency: TsEdit;
    edtBalanceInCurrency: TsEdit;
    lbBalanceInCurrency: TsLabel;
    procedure FormCreate(Sender: TObject);
    procedure agrLinesMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure edtCustomerDblClick(Sender: TObject);
    procedure agrLinesGetEditText(Sender: TObject; ACol, ARow: integer; var Value: string);
    procedure evtCurrencyChangedAndValid(Sender: TObject);
    procedure agrLinesDrawCell(Sender: TObject; ACol, ARow: integer; Rect: TRect; State: TGridDrawState);
    procedure rgrInvoiceAddressTypeClick(Sender: TObject);
    procedure actSaveAndExitExecute(Sender: TObject);
    procedure actPrintInvoiceExecute(Sender: TObject);
    procedure actPrintProformaExecute(Sender: TObject);
    procedure actAddDownPaymentExecute(Sender: TObject);
    procedure actInfoExecute(Sender: TObject);
    procedure actAddLineExecute(Sender: TObject);
    procedure actRemoveSelectedExecute(Sender: TObject);
    procedure actMoveItemToGroupInvoiceExecute(Sender: TObject);
    procedure timCloseInvoiceTimer(Sender: TObject);
    procedure actToggleLodgingTaxClick(Sender: TObject);
    procedure btnClearAddressesClick(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure agrLinesGetCellColor(Sender: TObject; ARow, ACol: integer; AState: TGridDrawState; ABrush: TBrush;
      AFont: TFont);
    procedure edtCustomerChange(Sender: TObject);
    procedure actEditDownPaymentClick(Sender: TObject);
    procedure agrLinesGetAlignment(Sender: TObject; ARow, ACol: integer; var HAlign: TAlignment;
      var VAlign: TVAlignment);
    procedure agrLinesColumnSize(Sender: TObject; ACol: integer; var Allow: boolean);
    procedure btnExitClick(Sender: TObject);
    procedure btnReservationNotesClick(Sender: TObject);
    procedure agrLinesCanEditCell(Sender: TObject; ARow, ACol: integer; var CanEdit: boolean);
    procedure FormDestroy(Sender: TObject);
    procedure agrLinesCellValidate(Sender: TObject; ACol, ARow: integer; var Value: string; var Valid: boolean);
    procedure agrLinesDblClickCell(Sender: TObject; ARow, ACol: integer);
    procedure actMoveRoomToGroupInvoiceExecute(Sender: TObject);
    procedure actMoveRoomToRoomInvoiceExecute(Sender: TObject);
    procedure mnuMoveItemPopup(Sender: TObject);
    procedure mnuMoveRoomPopup(Sender: TObject);
    procedure pnlInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState; var Accept: boolean);
    procedure pnlInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
    procedure pnlInvoiceIndex0Click(Sender: TObject);
    procedure MoveSelectedLinesToRoomInvoiceIndex(Sender: TObject);
    procedure shpInvoiceIndex0MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure shpInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
    procedure shpInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState; var Accept: boolean);
    procedure tvPaymentsMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure btnSaveChangesClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure CheckBoxClick(Sender: TObject; ACol, ARow: integer; State: boolean);
    procedure agrLinesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure Exit1Click(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure agrLinesGetDisplText(Sender: TObject; ACol, ARow: integer; var Value: string);
    procedure actAddRoomExecute(Sender: TObject);
    procedure agrLinesMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure edtPersonalIdChange(Sender: TObject);
    procedure btnClickDropDown(Sender: TObject);
    procedure agrLinesRowChanging(Sender: TObject; OldRow, NewRow: Integer; var Allow: Boolean);
    procedure acShowAllCTaxExecute(Sender: TObject);
    procedure acShowAlllBreakfastsExecute(Sender: TObject);
    procedure acShowAllDiscountsExecute(Sender: TObject);
    procedure acHideAllCTaxExecute(Sender: TObject);
    procedure acHideAllBreakfastsExecute(Sender: TObject);
    procedure acHideAllDiscountsExecute(Sender: TObject);
    procedure acHidePackageItemsExecute(Sender: TObject);
    procedure acShowpackageItemsExecute(Sender: TObject);
    procedure pnlInvoiceIndicesDragOver(Sender, Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean);
    procedure mnuMoveRoomToInvoiceIndexClick(Sender: TObject);
    procedure actRevertDownpaymentExecute(Sender: TObject);
    procedure mPaymentsCalcFields(DataSet: TDataSet);
    procedure actDeleteDownPaymentExecute(Sender: TObject);
    procedure actEditDownPaymentExecute(Sender: TObject);
    procedure tvPaymentNativeAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvPaymentsCurrencyAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure memExtraTextChange(Sender: TObject);
    procedure actInvoiceActionsUpdate(Action: TBasicAction; var Handled: Boolean);
  private
    { Private declarations }

    DeletedLines: IList<integer>;
    linesNumDays, linesNumGuests: integer;
    NumberGuestNights: integer;

    TaxTypes: TStringList;

    // Global to see if some changes

    zFirsttime: boolean;

    zEmailAddress: String;

    zDoSave: boolean;

    zCountry: string;

    FRoomInfoList: TRoomInfoList;
    SelectableRooms: TRoomInfoList;
    SelectableExternalRooms: TRoomInfoList;
    zInvoiceNumber: integer;
    zOriginalInvoice: integer;
    zInvoiceDate: TDate;
    zConfirmDate: TDate;
    zPayDate: TDate;

    FCellValueBeforeEdit: string;
    FCellDoubleBeforeEdit: Double;

    FInvoiceLinesList: TInvoiceLineList;

    zStayTaxIncluded: boolean;

    zRefNum: integer;

    zCreditType: TCreditType;

    tempInvoiceItemList: TInvoiceItemEntityList;

    zLocation: string;
    FInvoiceIndex: TInvoiceIndex;

    FReservation: integer;
    FRoomReservation: integer;
    FHeaderChanged: boolean;
    FStayTaxEnabled: boolean;
    FInvoiceIndexTotals: TInvoiceIndexTotalList;

    FTaxAPIResponse : TxsdRoomRentTaxReceiptList;
    FInvoiceCurrencyCode: string;
    FShowRentPerDay: boolean;
    FInvoiceType: TInvoiceType;
    FIsCredit: boolean;

    procedure loadInvoiceToMemtable(var m: TKbmMemTable);

    procedure UpdateControls(aRow: integer=0);

    /// <summary>
    /// Based on the current items in the grid, calculate all automatic items (StayTax and included Breakfast) and
    /// add object to Lines[] and rows to the grid
    /// </summary>
    procedure calcAndAddAutoItems(reservation: integer;
      aAutoItems: TInvoiceAutoItemSet = [aiStayTax, aiIncludedBreakfast]); deprecated;
    procedure CalcAndAddIncludedBreakFast(aRoominvoiceLinesList: TInvoiceRoomEntityList); deprecated;

    procedure ClearRoomInfoObjects;
    procedure SetCurrentVisible;
    function GetInvoiceLineByRow(ARow: integer): TInvoiceLine;
    function GetRowForInvoiceLine(aInvoiceLine: TInvoiceLine): integer;

    /// <summary>
    /// Create a new TInvoiceLine object and add this to InvoiceLinesList collection
    /// </summary>
    function AddLine(LineId: integer; aParentInvoice: TInvoiceLine; sItem, sText: string; iNumber: Double; aPrice: Double;
      const aCurrency: string; const VATCode: string; PurchaseDate: TDate; aIsGenerated: boolean; Refrence, Source: string;
      isPackage: boolean; noGuests: integer; ConfirmDate: TDateTime; ConfirmAmount: Double; rrAlias: integer;
      AutoGen: string; itemIndex: integer = 0; aVisibleOnInvoice: boolean = true): TInvoiceLine;

    /// <summary>
    /// Create a RoomInfo object with supplied parameters and attach to a new row in the grid<br/>
    /// A new TInvoiceLine object is also created for the roomrent and a new TInvoiceLine object is created
    /// for the supplied discount (if any). The Invoiceline objects are not attached to the grid.
    /// </summary>
    procedure AddRoom(const aRoom: String; aRoomPrice: Double; aCurrency: string; aFromDate: TDate; aToDate: TDate;
      aDayCount: integer; const aDescription: string; aRoomReservation: integer;
      aDiscountAmount: Double; aDiscountIsPercentage: boolean; const aDiscountText: string; const aGuestName: String;
      aNumGuests: integer; aNumChildren: integer; const aPackageName: string; aRRAlias: integer;
      aBeakfastIncluded: boolean; aIsGenerated: boolean);

    Procedure AddRoomTaxToInvoiceLines(totalTax: Double; TaxUnits: Double; taxItem: string; aPurchaseDate: TDate;
      iAddAt: integer = 0; aParentInvoice: TInvoiceLine = nil; aIsIncludedInParent: boolean = false);
    procedure ClearInvoiceLines;
    function getTotalDownPayments: TAmount;

    procedure DisplayGuestName;

    /// <summary>
    /// Display the info of TInvoiceLine object in the grid and attach it to the row<br/>
    /// </summary>
    function DisplayLine(aInvoiceLine: TInvoiceLine; ARow: integer): integer; overload;

    procedure UpdateGrid;

    procedure DisplayTotals;
    /// <summary>
    /// Move Invoicelines for property RoomReservation from tmpinvoicelines table to invoicelines table
    /// </summary>
    procedure RestoreTMPInvoicelines;

    procedure AddSaveHeaderToExecPlan(aInvoiceNumber: integer; aExecutionPlan: TRoomerExecutionPlan; const aInvoiceLocation: string = '');

    function SaveInvoice(aInvoiceNumber: integer; aSaveType: TInvoiceSaveType; const aInvoiceLocation: string = ''): boolean;

    procedure ExecuteCurrencyChange(const aOldCurrency: string; const aNewCurrency: string);
    procedure MarkOriginalInvoiceAsCredited(iInvoice: integer);

    function isSystemLine(row: integer): boolean;
    procedure SetCustEdits;
    function GetInvoiceHeader(Res, RoomRes: integer): boolean; overload;
    function GetInvoiceHeader(Res, RoomRes: integer; arSet: TRoomerDataset): boolean; overload;
    function GetReservationHeader(Res, RoomRes: integer): boolean;
    function GetMainGuestHeader(Res, RoomRes: integer): boolean;
    function GetCustomerHeader(Res: integer): boolean;
    function GetMainGuestName(Res, RoomRes: integer): string;
    procedure RemoveInvalidKreditInvoice;
    procedure itemLookup;
    procedure AddEmptyLine(CheckChanged: boolean = True);
    procedure AddAndInitNewRow;

    procedure PrintProforma;
    procedure SaveAnd(doExit: boolean);
    procedure CreateCashInvoice(customer: string);

    function chkChanged: boolean;
    procedure NullifyGrid;

    Procedure InitInvoiceGrid;
    procedure AddDeleteFromInvoiceToExecutionPlan(aExecutionPlan: TRoomerExecutionPlan);

    procedure GetTaxTypes(TaxResultInvoiceLines: TInvoiceTaxEntityList);
    function FindLastRoomRentLine: integer;
    procedure UpdateItemInvoiceLinesForTaxCalculations;
    function CreateProformaID: integer;
    procedure MoveRoomToGroupInvoice;
    procedure MoveItemToRoomInvoice(toRoomReservation, toReservation: integer; InvoiceIndex: integer);
    procedure MoveRoomToRoomInvoice;
    procedure FillRoomsInMenu(mnuItem: TMenuItem);
    function RoomByRoomReservation(RoomReservation: integer): String;
    procedure LoadRoomListForCurrentReservation(reservation: integer);
    procedure DeleteRow(aGrid: TAdvStringGrid; iRow: integer);
    procedure SetInvoiceIndex(const Value: TInvoiceIndex);
    function IfInvoiceChangedThenOptionallySave(Ask: boolean = True): boolean;
    procedure MoveItemToNewInvoiceIndex(rowIndex, toInvoiceIndex: integer);
    procedure UpdateInvoiceIndexTabs;
    function GetInvoiceIndexPanel(Index: integer): TsPanel;
    function GetInvoiceIndexItems(Index: integer): TShape;
    function GetInvoiceIndexItemsRR(Index: integer): TShape;
    procedure MoveDownpaymentToInvoiceIndex(toInvoiceIndex: integer);
    function IsCashInvoice: boolean;
    function GetCalculatedNumberOfItems(ItemId: String; dDefault: Double): Double;
    procedure CheckOrUncheckAll(check: boolean);
    function GetAnyRowSelected: boolean;
    function GetSelectedRows: TList<String>;
    function GetSelectedRowNrs: TList<integer>;
    function IndexOfAutoGen(AutoGen: String): integer;
    procedure RemoveAllCheckboxes;
    function IsRoomSelected: boolean;
    procedure RemoveProformaInvoice(ProformaInvoiceNumber: integer);
    procedure DeleteLinesInList(ExecutionPlan: TRoomerExecutionPlan);
    procedure LoadRoomListForOtherReservations(reservation: integer);
    procedure ExternalRoomsClick(Sender: TObject);
    procedure FillExternalRoomsInMenu(mnuItem: TMenuItem);
    procedure FillAllRoomsInMenu(mnuItem: TMenuItem);
    procedure LoadRoomListForAllReservations;
    procedure TransferRoomToAnyRoomsClick(Sender: TObject);
    procedure UpdatePaidByOfRoomsdate(FromRoomReservation, RoomReservation, RealRoomReservation,
      reservation: integer);
    procedure AddIncludedBreakfastToLinesAndGrid(aIncludedBreakfastCount: integer; aPurchaseDate: TDate;
      iAddAt: integer = 0; aParent: TInvoiceLine = nil);
    procedure ClearGrid;
    procedure UpdateTaxinvoiceLinesForRoomItem(aInvLine: TInvoiceLine);
    procedure AddBreakfastInvoicelinesForRoomItem(aRoomEntity: TInvoiceRoomEntity; aParent: TInvoiceLine);
    procedure UpdateLine(ARow: integer);
    function CheckExtraWithdrawalAllowed(aExtraAmount: Double): boolean;
    procedure CheckAndAddLastRow;
    procedure InsertOrUpdateInvoiceLine(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer;
      aExecPlan: TRoomerExecutionPlan; aSaveType: TInvoiceSaveType);
    procedure AddARoom;
    function GetHeaderChanged: boolean;
    /// <summary>
    /// Use InvoicePayments form to register payments of open balance.
    /// Return true is the open balance has been completely paid
    /// </summary>
    function CompletePayments(var aInvoiceDate: TDate; var aPayDate: TDate; var aLocation: string): boolean;
    function PayAndPrintFinalInvoice: boolean;
    procedure MarkRoomRentAsPaid(aInvLine: TInvoiceLine; aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
    procedure SetInvoiceNumberOfPayments(aInvoiceNumber: integer; lExecutionPlan: TRoomerExecutionPlan);
    procedure SaveCompletePayments();
    procedure CopyPaymentsForProforma(aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
    procedure UpdateRoomReservationsCurrency(const aFromCurrency, aToCurrency: string);
    procedure RemoveTaxinvoiceLinesForRoomItem(aInvLine: TInvoiceLine);
    procedure UpdateTaxinvoiceLinesForAllRooms;
    procedure SaveInvoicelineVisibility(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
    function GetInvoiceLineVisibility(aReservation, aRoomReservation, aInvoiceIndex: integer; aPurchaseDate: TDate;
      const aItem: string; aDefault: boolean): boolean;
    procedure RemoveInvoicelineVisibilityRecord(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer;
      aExecPlan: TRoomerExecutionPlan);
    procedure MoveSelectedLinesToInvoiceIndex(aNewIndex: integer);
    procedure UpdateTaxinvoiceLinesForRoomItemUsingBackend(aInvLine: TInvoiceLine);
    procedure RetrieveTaxesforRoomReservation(aReservation, aRoomreservation: integer);
    procedure LoadPayments;
    procedure SetHeaderChanged(const Value: boolean);
    procedure SetInvoiceCurrencyCode(const Value: string);

    function InvoiceCurrencyRate: double;
    function LocateDate(recordSet: TRoomerDataset; field: String; Value: TDate): boolean;
    function FormatRoomDescription(const aRoomNumber: string; const aRoomResDescription: String; aArrival: TDate; aDeparture: TDate; aDayCount: integer;
                                   const aPackagename: string; aAddGuestName: boolean; const aGuestName: string): string;
    function DirectInvoiceLinesExist: boolean;

    property InvoiceIndex: TInvoiceIndex read FInvoiceIndex write SetInvoiceIndex;

    property AnyRowChecked: boolean read GetAnyRowSelected;
    property HeaderChanged: boolean read GetHeaderChanged write SetHeaderChanged;
    procedure GenerateRoomRentLinesPerDay;
    procedure GenerateRoomRentLinesPerRoom;
    procedure UpdateCaptions;
  protected
    procedure DoLoadData; override;
  public
    { Public declarations }

    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    procedure WndProc(var message: TMessage); override;
    property Reservation: integer read FReservation write FReservation;
    property RoomReservation: integer read FRoomReservation write FRoomReservation;
    /// <summary>
    ///   Currency to display amounts on invoice. note that setting this property does not
    ///  alter the currencysettings of the invoice or roomreservation in the database
    /// </summary>
    property InvoiceCurrencyCode: string read FInvoiceCurrencyCode write SetInvoiceCurrencyCode;
    property ShowRentPerDay: boolean read FShowRentPerDay write FShowRentPerDay;
  end;

procedure EditInvoice(reservation, RoomReservation, InvoiceType, InvoiceIndex: integer; bCredit: boolean);

implementation

uses
  dbTables,
  uMain,
  uFileDependencyManager,
  uCreditPrompt,
  uFinishedInvoices2,
  uD,
  ueditRoomPrice,
  uDayNotes,
  uInvoicePayment,
  uCurrencies,
  uSqlDefinitions,
  uCustomers2,
  uitems2,
  uAppGlobal,
  uRoomerLanguage,
  uAssignPayment,
  PrjConst,
  uStringUtils,
  uDImages,
  uFrmHandleBookKeepingException,
  uRoomerDefinitions,
  uReservationStateDefinitions,
  uActivityLogs,
  UITypes,
  uFloatUtils,
  Math,
  uVatCalculator,
  uSQLUtils,
  ufrmRoomPrices,
  System.Generics.Defaults,
  uDateTimeHelper,
  Types,
  uFinanceConnectService
  , uBookingsTaxesAPICaller
  , uRoomerCanonicalDataModel_DataStructures, uRoomerCanonicalDataModel_SimpleTypes
  , uFrmChargePayCard, uPMSSettings, uCurrencyConstants, uRoomerCurrencymanager;

{$R *.DFM}

const
  // Objects in grid
  cInvoiceLineAttachColumn = 0;
  cPurchaseDateAsObjectColumn = 3;

  // Visible Columns in grid
  col_Select = 0;
  col_VisibleOnInvoice = col_Select + 1;
  col_Item = col_VisibleOnInvoice + 1;
  col_Description = col_Item + 1;
  col_date = col_Description + 1;
  col_ItemCount = col_date + 1;
  col_ItemPrice = col_ItemCount + 1;
  col_TotalPrice = col_ItemPrice + 1;
  col_TotalOnInvoice = col_TotalPrice + 1;
  col_Source = col_TotalOnInvoice + 1;

  // inVisible Columns in grid
  col_System = col_source + 1;
  col_Reference = col_System + 1;
  col_isPackage = col_Reference + 1;
  col_NoGuests = col_isPackage + 1;
  col_confirmdate = col_NoGuests + 1;
  col_confirmAmount = col_confirmdate + 1;
  col_rrAlias = col_confirmAmount + 1;
  col_autogen = col_rrAlias + 1;

  // WM_StartUpLists = WM_User + 381;
  WM_REDRAW_LINE = WM_User + 290;

  REMOVE_CURRENT_PROFORMA_INVOICE: Array [0 .. 3] OF String = (
    'DELETE FROM invoicelines WHERE invoiceNumber=%d',
    'DELETE FROM invoiceheads WHERE invoiceNumber=%d',
    'DELETE FROM payments WHERE invoiceNumber=%d',
    'DELETE FROM invoiceaddressees WHERE invoiceNumber=%d');

  REMOVE_REDUNDANT_INVOICES: Array [0 .. 3] OF String = (
    // Credit invoices                          // Proforma invoices
    'DELETE FROM invoicelines WHERE (SplitNumber = 1 AND InvoiceNumber = -1) OR (InvoiceNumber > 1000000000)',
    'DELETE FROM invoiceheads WHERE (SplitNumber = 1 AND InvoiceNumber = -1) OR (InvoiceNumber > 1000000000)',
    'DELETE FROM invoiceaddressees WHERE (SplitNumber = 1 AND InvoiceNumber = -1) OR (InvoiceNumber > 1000000000)',
    'DELETE FROM payments WHERE InvoiceNumber > 1000000000');

procedure EditInvoice(reservation, RoomReservation, InvoiceType, InvoiceIndex: integer; bCredit: boolean);
var
  _frmInvoice: TfrmInvoiceEdit;
  lRentPerDay: boolean;
  lAnswer: word;
begin
  lRentPerDay := false;

  if TInvoiceType(InvoiceType) = itDebitInvoice then
    case glb.PMSSettings.InvoiceSettings.RoomRentPerDayOninvoice of
      rpdAlways:  lRentPerDay := true;
      rpdNever:   lRentPerDay := False;
      rpdAsk:     begin
                    lAnswer := MessageDlg(GetTranslatedText('shEditInvoice_RoomRentPerDay'), mtConfirmation, mbYesNoCancel, 0);
                    case lAnswer of
                      mrYes:     lRentPerDay := true;
                      mrNo:      lRentPerDay := False;
                      mrCancel:  Exit;
                    end;
                  end;
    end;

  _frmInvoice := TfrmInvoiceEdit.Create(nil);
  try
    _frmInvoice.reservation := reservation;
    _frmInvoice.RoomReservation := RoomReservation;
    _frmInvoice.FInvoiceType := TInvoiceType(InvoiceType);
    _frmInvoice.FInvoiceIndex := InvoiceIndex;
    _frmInvoice.FIsCredit := bCredit;
    _frmInvoice.ShowRentPerDay := lRentPerDay;

    _frmInvoice.ShowModal;
  finally
    FreeAndNil(_frmInvoice);
  end;
end;

function TfrmInvoiceEdit.DirectInvoiceLinesExist: boolean;
var
  sql: string;
  rSet: TRoomerDataSet;
begin
  sql := '';
  sql := sql + 'SELECT ';
  sql := sql + ' (SELECT count(*) from invoicelines ';
  sql := sql + '  where roomreservation=0 and reservation=0 and invoicenumber=-1 and splitnumber=%d) as ilCount,';
  sql := sql + ' (SELECT count(*) from payments ';
  sql := sql + '  where roomreservation=0 and reservation=0 and invoicenumber=-1 and person=%d) as payCount';
  sql := Format(sql, [ord(FInvoiceType), ord(FInvoiceType)]);
  Result := false;
  rSet := CreateNewDataSet;
  try
    if hData.rSet_bySQL(rSet, sql) then
      Result := rSet.fieldByName('ilCount').AsInteger + rSet.fieldByName('payCount').AsInteger > 0;
  finally
    rSet.Free;
  end;

end;

procedure TfrmInvoiceEdit.RemoveAllCheckboxes;
var
  i: integer;
begin
  for i := 0 to agrLines.RowCount - 1 do
  begin
    agrLines.RemoveCheckBox(col_Select, i);
    agrLines.RemoveCheckBox(col_VisibleOnInvoice, i);
  end;
end;

procedure TfrmInvoiceEdit.DeleteRow(aGrid: TAdvStringGrid; iRow: integer);
begin
  if agrLines.HasCheckBox(col_Select, iRow) then
    agrLines.RemoveCheckBox(col_Select, iRow);
  agrLines.RemoveRows(iRow, 1);
end;

destructor TfrmInvoiceEdit.Destroy;
begin
  FInvoiceIndexTotals.Free;
  FTaxAPIResponse.Free;
  inherited;
end;

// HJ
function TfrmInvoiceEdit.isSystemLine(row: integer): boolean;
var
  lInvLine: TInvoiceLine;
begin
  result := false;
  try
    lInvLine := GetInvoiceLineByRow(row);
    result := assigned(lInvLine) and lInvLine.IsGeneratedLine;
    // result := agrLines.Objects[col_Item, row] = TObject(-2);
  except
  end;
end;

procedure TfrmInvoiceEdit.AddDeleteFromInvoiceToExecutionPlan(aExecutionPlan: TRoomerExecutionPlan);
var
  s: string;
begin
  s := '';
  s := s + 'DELETE FROM invoiceheads ' + ''#10'';
  s := s + ' where Reservation = ' + inttostr(FReservation);
  s := s + '   and RoomReservation = ' + inttostr(FRoomReservation);
  s := s + '   and SplitNumber = ' + _db(ord(FInvoiceType));
  s := s + '   and InvoiceNumber = -1';
  aExecutionPlan.AddExec(s);
end;

function TfrmInvoiceEdit.IfInvoiceChangedThenOptionallySave(Ask: boolean = True): boolean;
var
  Res: integer;

begin
  result := True;

  if FInvoiceType <> itCreditInvoice then
  begin
    if chkChanged then
    begin
      if Ask then
        Res := MessageDlg(GetTranslatedText('shTx_Invoice_SaveChanges'), mtConfirmation, [mbYes, mbNo, mbCancel], 0)
      else
        Res := mrYes;
      case Res of
        mrYes:
          begin
            if SaveInvoice(zInvoiceNumber, stProvisionally) then
            begin
              d.insertActivityLogFromMemTable;
              result := True;
            end;
          end;
        mrNo:
          result := True;
        mrCancel:
          result := false;
      end;
    end;
  end;
end;

procedure TfrmInvoiceEdit.btnExitClick(Sender: TObject);
begin
  if IsCashInvoice then
  begin
    if MessageDlg(GetTranslatedText('shTx_Invoice_WarningCloseCashInvoice'), mtConfirmation, mbOKCancel, 0) = mrOK then
    begin
      d.RemoveDirectInvoiceRemnants(ord(FInvoiceType));
      Close;
    end;

  end
  else if IfInvoiceChangedThenOptionallySave then
    close;
end;

procedure TfrmInvoiceEdit.btnClickDropDown(Sender: TObject);
var
  btn: TsButton;
  pt: TPoint;
begin
  btn := (Sender as TsButton);
  if assigned(btn.DropDownMenu) then
  begin
    pt := btn.ClientToScreen(Point(0, btn.ClientHeight));
    btn.DropDownMenu.Popup(pt.X, pt.Y);
  end;

end;

procedure TfrmInvoiceEdit.btnClearAddressesClick(Sender: TObject);
begin
  edtAddress1.Text := '';
  edtAddress2.Text := '';
  edtAddress3.Text := '';
  edtAddress4.Text := '';
  HeaderChanged := True;
end;

procedure TfrmInvoiceEdit.actToggleLodgingTaxClick(Sender: TObject);
begin
  FStaytaxEnabled := RV_ToggleUseStayTax(FReservation) and ctrlGetBoolean('useStayTax');
  RefreshData;
end;

procedure TfrmInvoiceEdit.btnReservationNotesClick(Sender: TObject);
begin
  g.openresMemo(FReservation);
end;

procedure TfrmInvoiceEdit.btnSaveChangesClick(Sender: TObject);
begin
  IfInvoiceChangedThenOptionallySave(false);
  UpdateInvoiceIndexTabs;
  RefreshData;
end;

procedure TfrmInvoiceEdit.ClearRoomInfoObjects;
begin
  FRoomInfoList.Clear;
end;


/// /////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////

const
  vWidth: integer = 9;
  vDec: integer = 2;

procedure TfrmInvoiceEdit.ClearInvoiceLines;
var
  i: integer;
begin
  for i := 0 to agrLines.RowCount - 1 do
  begin
    if agrLines.HasCheckBox(col_Select, i) then
      agrLines.RemoveCheckBox(col_Select, i);
    if agrLines.HasCheckBox(col_VisibleOnInvoice, i) then
      agrLines.RemoveCheckBox(col_VisibleOnInvoice, i);
    if assigned(agrLines.Objects[cInvoiceLineAttachColumn, i]) then
      agrLines.Objects[cInvoiceLineAttachColumn, i] := nil;
  end;

  FInvoiceLinesList.Clear;
end;

function TfrmInvoiceEdit.AddLine(LineId: integer; aParentInvoice: TInvoiceLine; sItem, sText: string; iNumber: Double;
  aPrice: Double; const aCurrency: string; const VATCode: string; PurchaseDate: TDate; aIsGenerated: boolean;
  Refrence, Source: string; isPackage: boolean; noGuests: integer; ConfirmDate: TDateTime; ConfirmAmount: Double;
  rrAlias: integer; AutoGen: string; itemIndex: integer = 0; aVisibleOnInvoice: boolean = true): TInvoiceLine;
var
  invoiceLine: TInvoiceLine;
  lParent: TInvoiceLine;
begin
  if AutoGen = '' then
    AutoGen := _GetCurrentTick;

  if trim(sItem) = '' then
    if copy(sText, 1, 5) = 'Tel: ' then
      sItem := trim(g.qPhoneUseItem);

  lParent := aParentInvoice;
  invoiceLine := nil;
  try
    if isPackage then
      invoiceLine := FInvoiceLinesList.AddPackageInvoiceLine(lineId, lParent, rrAlias)
    else
      invoiceLine := FInvoiceLinesList.AddInvoiceLine(lineId, lParent);

    invoiceLine.Item := sItem;
    invoiceLine.Text := sText;
    invoiceLine.Number := iNumber;
    invoiceLine.Price := TAmount.Create(aPrice, aCurrency);
    invoiceLine.IsGeneratedLine := aIsGenerated;
    invoiceLine.PurchaseDate := PurchaseDate;
    invoiceLine.Reference := Refrence;
    invoiceLine.Source := Source;
    invoiceLine.IsTotalIncludedInParent := false;
    invoiceLine.IsVisibleOnInvoice := aVisibleOnInvoice;

    invoiceLine.noGuests := noGuests;
    invoiceLine.ConfirmDate := ConfirmDate;
    invoiceLine.ConfirmAmount := ConfirmAmount;
    invoiceLine.Roomreservation := rrAlias;
    invoiceLine.itemIndex := itemIndex;
    invoiceLine.AutoGen := AutoGen;
    invoiceLine.VATCode := VATCode;
    invoiceLine.Currency := aCurrency;

    // Check if visiblity overridden in invoicelines_visiblity table
    if invoiceLine.CanBeHiddenFromInvoice then
      invoiceline.IsVisibleOnInvoice := GetInvoiceLineVisibility(invoiceline.ParentReservation, invoiceline.ParentRoomReservation,
                                                               FInvoiceIndex, invoiceline.PurchaseDate, invoiceline.Item,
                                                               invoiceline.IsVisibleOnInvoice);

  except
    if assigned(invoiceline) then
      FInvoiceLinesList.Remove(InvoiceLine);
    raise;
  end;
  result := invoiceLine;
end;

function TfrmInvoiceEdit.GetInvoiceLineByRow(ARow: integer): TInvoiceLine;
begin
  result := agrLines.Objects[cInvoiceLineAttachColumn, ARow] as TInvoiceLine
end;

procedure TfrmInvoiceEdit.UpdateGrid;
var
  lInvoiceLine: TInvoiceLine;
  cnt: integer;
begin
  if not agrLines.IsUpdating then
  begin
    agrLines.BeginUpdate;
    Screen.Cursor := crHourGlass;
    try
      InitInvoiceGrid;
      agrLines.RowCount := FInvoiceLinesList.Count + 1;

      cnt := 1;
      FInvoiceLinesList.SortOnInvoiceLineIndex;
      for lInvoiceLine in FInvoiceLinesList do
      begin
        DisplayLine(lInvoiceLine, cnt);
        inc(cnt);
      end;

      DisplayTotals;
      AddAndInitNewRow;
      UpdateInvoiceIndexTabs;

      chkChanged;
    finally
      agrLines.EndUpdate;
      Screen.Cursor := crDefault;
    end;
  end;
end;

procedure TfrmInvoiceEdit.UpdateLine(ARow: integer);
var
  lInvoice: TInvoiceLine;
  lRow: integer;
begin
  lInvoice := GetInvoiceLineByRow(ARow);
  lRow := ARow;
  while assigned(lInvoice) do
  begin
    DisplayLine(lInvoice, lRow);
    lInvoice := lInvoice.Parent;
    if assigned(lInvoice) then
      lRow := GetRowForInvoiceLine(lInvoice);
  end;
  CheckAndAddLastRow;
end;

procedure TfrmInvoiceEdit.CheckAndAddLastRow;
begin
  if agrLines.RowCount <= FInvoiceLinesList.Count + 1 then
    agrLines.RowCount := FInvoiceLinesList.Count + 2;
end;

function TfrmInvoiceEdit.DisplayLine(aInvoiceLine: TInvoiceLine; ARow: integer): integer;
var
  lValue: TAmount;
begin
  agrLines.Cells[col_Item, ARow] := aInvoiceLine.Item;

  // Add Select checkbox
  if not aInvoiceLine.CanBeHiddenFromInvoice then
  begin
    if NOT agrLines.HasCheckBox(col_Select, ARow) and (agrLines.Cells[col_Item, ARow] <> '') then
      agrLines.AddCheckBox(col_Select, ARow, false, false);
  end
  else if agrLines.HasCheckBox(col_Select, ARow) then
    agrLines.RemoveCheckBox(col_Select, ARow);

  // Add hide checkbox
  if aInvoiceLine.CanBeHiddenFromInvoice then
  begin
    if NOT agrLines.HasCheckBox(col_VisibleOnInvoice, ARow) then
      agrLines.AddCheckBox(col_VisibleOnInvoice, ARow, false, false);
    agrLines.SetCheckBoxState(col_VisibleOnInvoice, ARow, aInvoiceLine.IsVisibleOnInvoice);
  end
  else if agrLines.HasCheckBox(col_VisibleOnInvoice, ARow) then
    agrLines.RemoveCheckBox(col_VisibleOnInvoice, ARow);

  agrLines.Cells[col_Description, ARow] := aInvoiceLine.Text;
  agrLines.Cells[col_ItemCount, ARow] := trim(_floattostr(aInvoiceLine.Number, vWidth, vDec));

  agrLines.Cells[col_ItemPrice, ARow] := aInvoiceLine.RevenuePrice.AsDisplayStringWithCode;

  agrLines.Cells[col_TotalPrice, ARow] := aInvoiceLine.TotalRevenue.AsDisplayStringWithCode;

  lValue := aInvoiceLine.AmountOnInvoice;
  if lValue = 0 then
    agrLines.Cells[col_TotalOnInvoice, ARow] := ''
  else
    agrLines.Cells[col_TotalOnInvoice, ARow] := lValue.ToCurrency(FInvoiceCurrencyCode).AsDisplayStringWithCode;

  agrLines.Cells[col_System, ARow] := '';
  agrLines.Cells[col_Reference, ARow] := aInvoiceLine.Reference;
  agrLines.Cells[col_Source, ARow] := aInvoiceLine.Source;
  agrLines.Objects[cPurchaseDateAsObjectColumn, ARow] := TObject(trunc(aInvoiceLine.PurchaseDate));
  agrLines.Objects[col_ItemPrice, ARow] := aInvoiceLine;
  // -- PurchaseDate !
  if aInvoiceLine.PurchaseDate > 0 then
    agrLines.Cells[col_date, ARow] := datetostr(trunc(aInvoiceLine.PurchaseDate));

  agrLines.Cells[col_isPackage, ARow] := _bool2str(aInvoiceLine.isPackage, 2);
  agrLines.Cells[col_NoGuests, ARow] := inttostr(aInvoiceLine.noGuests);

  agrLines.Cells[col_confirmdate, ARow] := _db(aInvoiceLine.ConfirmDate, false);
  agrLines.Cells[col_confirmAmount, ARow] := _db(aInvoiceLine.ConfirmAmount);

  agrLines.Cells[col_rrAlias, ARow] := inttostr(aInvoiceLine.Roomreservation);

  agrLines.Cells[col_autogen, ARow] := aInvoiceLine.AutoGen;

  agrLines.Objects[cInvoiceLineAttachColumn, ARow] := aInvoiceLine; // -- Auto !

  result := ARow;
end;

procedure TfrmInvoiceEdit.DisplayTotals;
var
  TotalDownPayments: TAmount;
  TotalBalance: TAmount;
  ttVAT: TAmount;
  nativeTotal: TAmount;
begin
  Screen.Cursor := crHourGlass;
  try
    nativeTotal := FInvoiceLinesList.TotalOnInvoice.ToNative;
    ttVAT := FInvoiceLinesList.TotalVatOnInvoice.ToNative;
    TotalDownPayments := getTotalDownPayments;
    TotalBalance := nativeTotal - TotalDownPayments;

    edtTotalWOVat.Text := (nativeTotal - ttVAT).AsDisplayStringWithCode;
    edtVat.Text := ttVAT.AsDisplayStringWithCode;
    edtInvoiceTotal.Text := nativeTotal.AsDisplayStringWithCode;
    edtDownPayments.Text := TotalDownPayments.AsDisplayStringWithCode;
    edtBalance.Text := TotalBalance.AsDisplayStringWithCode;
    labLodgingTax.Caption := FInvoiceLinesList.TotalCityTaxRevenues.ToCurrency(RoomerCurrencyManager.DefaultCurrency).AsDisplayStringWithCode;
    labLodgingTaxNights.Caption := inttostr(trunc(FInvoiceLinesList.CityTaxUnitCount));

    if (InvoiceCurrencyCode <> '') and (InvoiceCurrencyCode <> RoomerCurrencyManager.DefaultCurrency) then
    begin
      edtTotalInCurrency.Text := nativeTotal.ToCurrency(InvoiceCurrencyCode).AsDisplayStringWithCode;
      edtBalanceInCurrency.Text := TotalBalance.ToCurrency(InvoiceCurrencyCode).AsDisplayStringWithCode;
    end;

  finally
    Screen.Cursor := crDefault;
  end;
end;

procedure TfrmInvoiceEdit.DisplayGuestName;
begin
  if copy(edtRoomGuest.Caption, 1, 1) <> '-' then
  begin
    edtRoomGuest.Caption := GetMainGuestName(FReservation, FRoomReservation);
  end;
end;

procedure TfrmInvoiceEdit.AddRoomTaxToInvoiceLines(totalTax: Double; TaxUnits: Double; taxItem: String;
  aPurchaseDate: TDate; iAddAt: integer = 0; aParentInvoice: TInvoiceLine = nil; aIsIncludedInParent: boolean = false);
var
  ConfirmDate: TDateTime;
  ConfirmAmount: Double;
  unitPrice: Double;
  lItemInfo: TItemTypeInfo;
  lInvLine: TInvoiceLine;
begin
  ConfirmDate := 2;
  ConfirmAmount := 0;

  if taxItem = '' then
    taxItem := g.qStayTaxItem;
  lItemInfo := d.Item_Get_ItemTypeInfo(taxItem);

  unitPrice := totalTax / TaxUnits;

  lInvLine := AddLine(0, aParentInvoice, taxItem, Item_GetDescription(taxItem), TaxUnits, unitPrice, g.qNativeCurrency,
    lItemInfo.VATCode, aPurchaseDate, aParentInvoice.IsGeneratedLine, '', '', false, 0, ConfirmDate, ConfirmAmount, -1, _GetCurrentTick, 0, not aIsIncludedInParent);

  lInvLine.IsTotalIncludedInParent := aIsIncludedInParent;
end;

procedure TfrmInvoiceEdit.SetCurrentVisible;
begin
  if agrLines.RowCount > agrLines.VisibleRowCount then
  begin
    if (agrLines.row > agrLines.TopRow + agrLines.VisibleRowCount - 1) then
      agrLines.TopRow := agrLines.row - agrLines.VisibleRowCount + 1
    else if (agrLines.row < agrLines.TopRow) then
      agrLines.TopRow := agrLines.row;
  end;
end;

procedure TfrmInvoiceEdit.CreateCashInvoice(customer: string);
var
  CustomerHolder: recCustomerHolderEX;
  s: string;
begin
  d.RemoveDirectInvoiceRemnants(ord(FInvoiceType));

  pnlHead.Color := $00FFDDDD; // $00EAFFEA
  pnlTotalsAndPayments.Color := $00FFDDDD; // $00EAFFEA

  rgrInvoiceAddressType.itemIndex := 4;

  CustomerHolder := hData.Customer_GetHolder(g.qRackCustomer);

  // SQL 108 xINSERT InvoiceHeads
  // INS-InvoiceHeads
  s := '';
  s := s + 'INSERT into invoiceheads ' + #10;
  s := s + '(' + #10;
  s := s + '  Reservation ' + #10;
  s := s + ', RoomReservation ' + #10;
  s := s + ', SplitNumber ' + #10;

  s := s + ', InvoiceNumber ' + #10;
  s := s + ', InvoiceDate ' + #10;

  s := s + ', Customer ' + #10;
  s := s + ', Name ' + #10;

  s := s + ', CustPId ' + #10;
  s := s + ', Address1 ' + #10;
  s := s + ', Address2 ' + #10;
  s := s + ', Address3 ' + #10;
  s := s + ', Address4 ' + #10;
  s := s + ', Country ' + #10;
  s := s + ', Total ' + #10;;
  s := s + ', TotalWOVat ' + #10;;
  s := s + ', TotalVat ' + #10;;
  s := s + ', TotalBreakfast ' + #10;
  s := s + ', ExtraText ' + #10;
  s := s + ', Finished ' + #10;
  s := s + ', InvoiceType ' + #10;
  s := s + ', ihStaff ' + #10;
  s := s + ', ihDate ' + #10;
  s := s + ', ihInvoiceDate ' + #10;
  s := s + ', ihConfirmDate ' + #10;
  s := s + ', ihPayDate ' + #10;
  s := s + ', ihCurrency ' + #10; // **98
  s := s + ', ihCurrencyrate ' + #10; // **98
  s := s + ', Location ' + #10; // **98
  s := s + ')' + #10;

  s := s + 'Values' + #10;
  s := s + '(' + #10;
  s := s + '  ' + _db(FReservation);
  s := s + ', ' + _db(FRoomReservation);
  s := s + ', ' + _db(ord(FInvoiceType));
  s := s + ', ' + _db(zInvoiceNumber);
  s := s + ', ' + _db(zInvoiceDate);

  s := s + ', ' + _db(CustomerHolder.customer);
  s := s + ', ' + _db(CustomerHolder.DisplayName);
  s := s + ', ' + _db(CustomerHolder.PID);
  s := s + ', ' + _db('');
  s := s + ', ' + _db('');
  s := s + ', ' + _db('');
  s := s + ', ' + _db('');
  s := s + ', ' + _db(ctrlGetString('country'));
  s := s + ', ' + _db(0);
  s := s + ', ' + _db(0);
  s := s + ', ' + _db(0);
  s := s + ', ' + _db(0);
  s := s + ', ' + _db(memExtraText.Lines.Text);
  s := s + ', ' + _db(false);
  s := s + ', ' + _db(rgrInvoiceAddressType.itemIndex);
  s := s + ', ' + _db(g.qUser);
  s := s + ', ' + _db(Date);
  s := s + ', ' + _db(zInvoiceDate);
  s := s + ', ' + _db(zConfirmDate);
  s := s + ', ' + _db(zPayDate);
  s := s + ', ' + _db(InvoiceCurrencyCode);
  s := s + ', ' + _db(InvoiceCurrencyRate);
  s := s + ', ' + _db(zLocation);

  s := s + ')' + #10;

  if not cmd_bySQL(s) then
  begin
  end;

  rgrInvoiceAddressType.itemIndex := 4;
  edtCustomer.Text := CustomerHolder.customer;
  edtPersonalId.Text := CustomerHolder.PID;
  edtName.Text := CustomerHolder.CustomerName;
end;

procedure TfrmInvoiceEdit.RestoreTMPInvoicelines;
var
  rSet: TRoomerDataset;
  qry: string;
  itemNumber: integer;
  ItemId: string;
  Description: string;
  Price: Double;
  VATType: string;
  Total: Double;
  TotalWOVat: Double;
  Vat: Double;
  CurrencyRate: Double;
  Currency: string;
  Persons: integer;
  Nights: integer;
  BreakfastPrice: Double;

  importRefrence: string;
  ImportSource: string;

  tmpData: string;

  vTotal: Double;
  vTotalWOVat: Double;
  vVat: Double;

  Number: Double; // -96
  OrginalRef: integer;

  PurchaseDate: TDateTime;

  AYear, AMon, ADay: Word;
  isPackage: boolean;
  s: string;
  orderStr: string;

  ConfirmDate: TDateTime;
  ConfirmAmount: Double;

begin
  orderStr := ' Roomreservation,ItemNumber ';
  OrginalRef := 0;

  if d.InvoiceLinesTmp_exists(FRoomReservation) then
  begin
    rSet := TRoomerDataset.Create(nil);
    try

      // TODO: Replace with a single statement: INSERT INTO invocielines SELECT FROM invoicelinesTmp ...

      s := select_qryGetInvoiceLinesTmp(FRoomReservation);
      s := format(s, [FRoomReservation, orderStr]);
      if hData.rSet_bySQL(rSet, s) then
      begin
        vTotal := 0;
        vTotalWOVat := 0;
        vVat := 0;

        while not rSet.eof do
        begin
          CurrencyRate := rSet.FieldByName('CurrencyRate').AsFloat;
          Currency := rSet.FieldByName('Currency').asString;
          ItemId := rSet.FieldByName('ItemId').asString;
          Price := rSet.FieldByName('Price').AsFloat;
          Total := rSet.FieldByName('Total').AsFloat;
          TotalWOVat := rSet.FieldByName('TotalWOVat').AsFloat;
          Vat := rSet.FieldByName('Vat').AsFloat;
          Number := rSet.FieldByName('Number').AsFloat;
          VATType := rSet.FieldByName('VATType').asString;
          OrginalRef := rSet.FieldByName('InvoiceNumber').asinteger;
          PurchaseDate := rSet.FieldByName('PurchaseDate').asdateTime;
          itemNumber := rSet.FieldByName('itemNumber').asinteger;
          Description := rSet.FieldByName('Description').asString;
          Persons := rSet.FieldByName('Persons').asinteger;
          Nights := rSet.FieldByName('Nights').asinteger;
          isPackage := rSet.FieldByName('isPackage').asBoolean;
          BreakfastPrice := rSet.FieldByName('isPackage').AsFloat;

          vTotal := vTotal + Total;
          vTotalWOVat := vTotalWOVat + TotalWOVat;
          vVat := vVat + Vat;

          importRefrence := rSet.FieldByName('importRefrence').asString;
          ImportSource := rSet.FieldByName('ImportSource').asString;

          ConfirmDate := rSet.FieldByName('ConfirmDate').asdateTime;
          ConfirmAmount := rSet.FieldByName('ConfirmAmount').AsFloat;

          tmpData := rSet.FieldByName('tmpData').asString;

          try
            decodedate(PurchaseDate, AYear, AMon, ADay);
          except
            decodedate(now, AYear, AMon, ADay);
          end;

          // SQL 107 INSERxT InvoiveLines
          qry := '' + #10;
          qry := qry + 'INSERT into invoicelines' + #10;
          qry := qry + '(' + #10;
          qry := qry + '  Reservation ' + #10;
          qry := qry + ', AutoGen ' + #10;
          qry := qry + ', RoomReservation ' + #10;
          qry := qry + ', SplitNumber ' + #10;
          qry := qry + ', ItemNumber ' + #10;
          qry := qry + ', PurchaseDate ' + #10;
          qry := qry + ', InvoiceNumber ' + #10;
          qry := qry + ', ItemId ' + #10;
          qry := qry + ', Number ' + #10;
          qry := qry + ', Description ' + #10;
          qry := qry + ', Price ' + #10;
          qry := qry + ', VATType ' + #10;
          qry := qry + ', Total ' + #10;
          qry := qry + ', TotalWOVat ' + #10;
          qry := qry + ', VAT ' + #10;
          qry := qry + ', CurrencyRate ' + #10;
          qry := qry + ', Currency ' + #10;
          qry := qry + ', Persons ' + #10;
          qry := qry + ', Nights ' + #10;
          qry := qry + ', BreakfastPrice ' + #10;
          qry := qry + ', AutoGenerated ' + #10;

          qry := qry + ', AYear ' + #10;
          qry := qry + ', AMon ' + #10;
          qry := qry + ', ADay ' + #10;

          qry := qry + ', importRefrence ' + #10;
          qry := qry + ', ImportSource ' + #10;
          qry := qry + ', isPackage ' + #10;
          qry := qry + ', confirmdate ' + #10;
          qry := qry + ', confirmAmount ' + #10;
          qry := qry + ', staffCreated ' + #10;
          qry := qry + ', revenueCorrection' + #10;
          qry := qry + ', revenueCorrectionVat' + #10;

          qry := qry + ')' + #10;
          qry := qry + 'Values' + #10;

          qry := qry + '(' + #10;
          qry := qry + '  ' + _db(FReservation);
          qry := qry + ', ' + _db(_GetCurrentTick);
          qry := qry + ', ' + _db(FRoomReservation);
          qry := qry + ', ' + _db(ord(FInvoiceType));
          qry := qry + ', ' + _db(itemNumber);
          qry := qry + ', ' + _db(PurchaseDate, True);
          qry := qry + ', ' + _db(zInvoiceNumber);
          qry := qry + ', ' + _db(ItemId);
          qry := qry + ', ' + _db(Number);
          qry := qry + ', ' + _db(Description);
          qry := qry + ', ' + _db(Price);
          qry := qry + ', ' + _db(VATType);
          qry := qry + ', ' + _db(Total);
          qry := qry + ', ' + _db(TotalWOVat);
          qry := qry + ', ' + _db(Vat);
          qry := qry + ', ' + _db(CurrencyRate);
          qry := qry + ', ' + _db(Currency);
          qry := qry + ', ' + _db(Persons);
          qry := qry + ', ' + _db(Nights);
          qry := qry + ', ' + _db(BreakfastPrice);
          qry := qry + ', ' + _db(false);

          qry := qry + ', ' + _db(AYear);
          qry := qry + ', ' + _db(AMon);
          qry := qry + ', ' + _db(ADay);
          qry := qry + ', ' + _db(importRefrence);
          qry := qry + ', ' + _db(ImportSource);
          qry := qry + ', ' + _db(isPackage);
          qry := qry + ', ' + _db(ConfirmDate);
          qry := qry + ', ' + _db(ConfirmAmount);
          qry := qry + ', ' + _db(d.roomerMainDataSet.username);
          qry := qry + ', ' + _db(rSet.FieldByName('revenueCorrection').AsFloat);
          qry := qry + ', ' + _db(rSet.FieldByName('revenueCorrectionVat').AsFloat);

          qry := qry + ')' + #10;

          if not cmd_bySQL(qry) then
          begin
          end;

          rSet.Next;
        end;
        d.del_InvoiceLinesTmp(FRoomReservation);

        if OrginalRef > 0 then
          zOriginalInvoice := OrginalRef;
      end;
    finally
      FreeAndNil(rSet);
    end;
  end;
end;

Procedure TfrmInvoiceEdit.InitInvoiceGrid;
var
  lTopRow: TGridRect;
begin
  agrLines.BeginUpdate;
  try
    lTopRow.Left := 0;
    lTopRow.Top := 0;
    lTopRow.Right := col_select;
    lTopRow.Bottom := 0;

    agrLines.ClearAll;
    agrLines.ColCount := col_autogen + 1;
    agrLines.RowHeights[0] := 40;
    agrLines.RowCount := 2;
    agrLines.Cells[col_Item, 0] := GetTranslatedText('shTxInvoice_Form_Header_Item');
    agrLines.Cells[col_VisibleOnInvoice, 0] := GetTranslatedText('shTxInvoice_Form_Header_VisibleOnInvoice');
    agrLines.Cells[col_Description, 0] := GetTranslatedText('shTxInvoice_Form_Header_Text');
    agrLines.Cells[col_Date, 0] := GetTranslatedText('shTxInvoice_Form_Header_Date');
    agrLines.Cells[col_ItemCount, 0] := GetTranslatedText('shTxInvoice_Form_Header_Number');
    agrLines.Cells[col_ItemPrice, 0] := GetTranslatedText('shTxInvoice_Form_Header_UnitPrice');
    agrLines.Cells[col_TotalPrice, 0] := GetTranslatedText('shTxInvoice_Form_Header_Total');
    agrLines.Cells[col_TotalOnInvoice, 0] := GetTranslatedText('shTxInvoice_Form_Header_TotalOnInvoice');
    agrLines.Cells[col_System, 0] := ' !';
    agrLines.Cells[col_Reference, 0] := GetTranslatedText('shTxInvoice_Form_Header_Reference');
    agrLines.Cells[col_Source, 0] := GetTranslatedText('shTxInvoice_Form_Header_Source');
    agrLines.Cells[col_isPackage, 0] := GetTranslatedText('shTxInvoice_Form_Header_Package');
    agrLines.Cells[col_NoGuests, 0] := GetTranslatedText('shTxInvoice_Form_Header_Guests');
    agrLines.Cells[col_confirmdate, 0] := GetTranslatedText('shTxInvoice_Form_Header_Confirmdate');
    agrLines.Cells[col_confirmAmount, 0] := GetTranslatedText('shTxInvoice_Form_Header_ConfirmAmount');
    agrLines.Cells[col_rrAlias, 0] := GetTranslatedText('shTxInvoice_Form_Header_Alias');
    agrLines.Cells[col_autogen, 0] := 'ID';

    if not agrLines.HasCheckBox(0, col_Select) then
      agrLines.AddCheckBox(0, col_Select, false, false);

    agrLines.SetFontStyle( lTopRow, fsBold, true);
    FormResize(nil);
  finally
    agrLines.EndUpdate;
  end;
end;

function TfrmInvoiceEdit.FormatRoomDescription(const aRoomNumber: string; const aRoomResDescription: String; aArrival: TDate; aDeparture: TDate; aDayCount: integer;
                                                     const aPackagename: string; aAddGuestName: boolean; const aGuestName: string): string;
var
  lRoom: string;
  lPrefix: string;
begin

  lPrefix := '';

  if aRoomResDescription.StartsWith('--') or aRoomResDescription.StartsWith('&&') then
  begin
    Result := aRoomResDescription.TrimStart(['-', '&']);
  end

  else if aRoomResDescription.StartsWith('&-') then
  begin
    Result := aRoomResDescription.TrimStart(['-', '&']);
    lPrefix := aGuestName;
  end

  else
  begin
    if aAddGuestName then
      lPrefix := aGuestName;
    lRoom := GetTranslatedText('shRoom');

    if (not aPackageName.IsEmpty) then
    begin
      Result := Package_getRoomDescription(aPackagename, aRoomNumber, aArrival, aDeparture, aGuestName);
      if FRoomReservation = 0 then
        Result := Format('%s %s: %s', [Result, lRoom, aRoomNumber]);
    end

    else
    begin
      if aDayCount = 1 then
        Result := format('%s %s %s', [lRoom, aRoomNumber, DateToDayMonthString(aArrival)])
      else if aDayCount = trunc(aDeparture) - trunc(aArrival) then
        Result := format('%s %s %s - %s', [lRoom, aRoomNumber, DateToDayMonthString(aArrival), DateToDayMonthString(aDeparture)])
      else
        Result := format('%s %s, %d %s', [lRoom, aRoomNumber, aDayCount, GetTranslatedText('shTx_Invoice_Nights')]);
    end;

    Result := (aRoomResDescription.Trim + ' ' + Result).Trim;
  end;

  if not lPrefix.IsEmpty then
    result := Format('%s (%s)', [lPrefix, Result]);
end;

procedure TfrmInvoiceEdit.AddRoom(const aRoom: String; aRoomPrice: Double; aCurrency: string; aFromDate: TDate;
  aToDate: TDate; aDayCount: integer; const aDescription: string; aRoomReservation: integer;
  aDiscountAmount: Double; aDiscountIsPercentage: boolean; const aDiscountText: string; const aGuestName: String;
  aNumGuests: integer; aNumChildren: integer; const aPackageName: string; aRRAlias: integer;
  aBeakfastIncluded: boolean; aIsGenerated: boolean);
var
  lRmRntItem: string;
  lDiscountItem: string;

  lGuestName: string;
  lConfirmDate: TDateTime;
  lConfirmAmount: Double;

//  lRRText: string;
//  lText: string;
  lRoomInfo: TInvoiceRoomEntity;
  lInvoiceLine: TInvoiceLine;
  lItemInfo: TItemTypeInfo;
  lDescription: string;
begin

  lConfirmDate := 2;
  lConfirmAmount := 0;

  lRmRntItem := trim(g.qRoomRentItem);
  lItemInfo := d.Item_Get_ItemTypeInfo(lRmRntItem);


  lDescription := FormatRoomDescription(aRoom, aDescription, aFromDate, aToDate, aDayCount, aPackageName, (FRoomReservation = 0), aGuestName);

  lRoomInfo := TInvoiceRoomEntity.Create;
  // -- Attach the Room information
  lRoomInfo.RoomReservation := aRoomReservation;
  lRoomInfo.reservation := FReservation;
  lRoomInfo.Name := lGuestName;
  lRoomInfo.Arrival := aFromDate;
  lRoomInfo.Departure := aToDate;
  lRoomInfo.Price := aRoomPrice;
  lROomInfo.Currency := aCurrency;
  lRoomInfo.CurrencyRate := RoomerCurrencyManager.CurrencyDefinition[aCurrency].Rate;
  lRoomInfo.Discount := 0.00;
  lRoomInfo.Room := aRoom;
  lRoomInfo.NumGuests := aNumGuests;
  lRoomInfo.NumChildren := aNumChildren;
  lRoomInfo.BreakFastIncluded := aBeakfastIncluded;
  FRoomInfoList.Add(lRoomInfo);

  // add a TInvoiceline object for the RoomRent to InvoiceLineList
  lInvoiceLine := AddLine(0, nil, lRmRntItem, lDescription, aDayCount, aRoomPrice, aCurrency, lItemInfo.VATCode, aFromDate, aIsGenerated,
    '', '', not aPackageName.IsEmpty, aNumGuests, lConfirmDate, lConfirmAmount, aRRAlias, _GetCurrentTick); // *77
  lInvoiceLine.RoomEntity := lRoomInfo;
  lRoomInfo.Vat := lInvoiceLine.VATOnInvoice;

  // Only add included stuff if a regular room is added and not a manually added one
  if aIsGenerated then
  begin
//    with glb.PMSSettings.BetaFunctionality do
//      if BetaFunctionsAvailable and UseNewTaxcalcMethod then
//        UpdateTaxinvoiceLinesForRoomItemUsingBackend(lInvoiceLine)
//      else
        UpdateTaxinvoiceLinesForRoomItem(lInvoiceLine);

    // Included Breakfast invoicelines
    AddBreakfastInvoicelinesForRoomItem(lRoomInfo, lInvoiceLine);

    // -- Discount
    if aDiscountAmount <> 0 then
    begin
      lDiscountItem := trim(g.qDiscountItem);
      lItemInfo := d.Item_Get_ItemTypeInfo(lDiscountItem);

      lDescription := Item_GetDescription(lDiscountItem) + ' ' + aDiscountText;

      /// Add an InvoiceLine object for the discount
      AddLine(0, lInvoiceLine, lDiscountItem, lDescription, aDayCount, -1 * aDiscountAmount, aCurrency,
              lItemInfo.VATCode, aFromDate, True, '', '', false, aNumGuests, lConfirmDate, lConfirmAmount, aRRAlias, _GetCurrentTick);
      lRoomInfo.Discount := aDiscountAmount * aDayCount;
    end;
  end;

  UpdateItemInvoiceLinesForTaxCalculations;
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.AddBreakfastInvoicelinesForRoomItem(aRoomEntity: TInvoiceRoomEntity; aParent: TInvoiceLine);
begin
  if aRoomEntity.BreakFastIncluded then
    AddIncludedBreakfastToLinesAndGrid(aRoomEntity.NumGuests * aRoomEntity.NumberOfNights, aRoomEntity.Arrival, 0, aParent);

end;

procedure TfrmInvoiceEdit.RemoveTaxinvoiceLinesForRoomItem(aInvLine: TInvoiceLine);
var
  i: integer;
  lChildLine: TInvoiceLine;
begin
  for i := aInvLine.ChildInvoiceLines.Count - 1 downto 0 do
  begin
    lChildLine := aInvLine.ChildInvoiceLines[i];
    if lChildLine.ItemKind = ikStayTax then
    begin
      aInvLine.ChildInvoiceLines.Remove(lChildLine);
      FInvoiceLinesList.Remove(lChildLine);
    end;
  end;
end;

procedure TfrmInvoiceEdit.UpdateTaxinvoiceLinesForAllRooms;
var
  lInvLine: TInvoiceLine;
begin
  agrLines.BeginUpdate;
  try
    for lInvLine in FInvoiceLinesList do
      if assigned(lInvLine.RoomEntity) then
        UpdateTaxinvoiceLinesForRoomItem(lInvLine);
  finally
    agrLines.EndUpdate;
  end;
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.UpdateTaxinvoiceLinesForRoomItem(aInvLine: TInvoiceLine);
var
  lIsIncluded: boolean;
  lIsIncludedCust: boolean;
  lTaxResultInvoiceLines: TInvoiceTaxEntityList;
  lTotal: TAmount;
  tt, l: integer;
  lCalcOptions: TInvoiceCityTaxCalculationOptions;
begin
  RemoveTaxinvoiceLinesForRoomItem(aInvLine);

  FStayTaxEnabled := ctrlGetBoolean('useStayTax') AND RV_useStayTax(FReservation);
  if not FStayTaxEnabled then
    exit;

  glb.LocateSpecificRecordAndGetValue('customers', 'Customer', edtCustomer.Text, 'StayTaxIncluted', lIsIncludedCust);

  lCalcOptions := [tcoCalcTaxPerNight];
  if lIsIncludedCust then
    Include(lCalcOptions, tcoCustomerHasTaxIncluded);

  lTaxResultInvoiceLines := MakeTaxListforRoomEntity(aInvLine.RoomEntity, d.Item_Get_ItemTypeInfo(trim(g.qRoomRentItem)), lCalcOptions);
  try
    lIsIncluded := false;

    GetTaxTypes(lTaxResultInvoiceLines);
    for tt := 0 to TaxTypes.Count - 1 do
    begin

      for l := 0 to lTaxResultInvoiceLines.Count - 1 do
        if lTaxResultInvoiceLines[l].BookingItem = TaxTypes[tt] then
        begin
          lTotal := lTaxResultInvoiceLines[l].Total;

          case lTaxResultInvoiceLines[l].IncludedInPrice of
            TIE_PER_CUSTOMER:
              lIsIncluded := lIsIncludedCust;
            TIE_INCLUDED:
              lIsIncluded := True;
            TIE_EXCLUDED:
              lIsIncluded := false;
          end;

          AddRoomTaxToInvoiceLines(lTotal.ToNative, trunc(lTaxResultInvoiceLines[l].NumItems), TaxTypes[tt],
            aInvLine.RoomEntity.Arrival, 0, aInvLine, lIsIncluded);
        end; // for l + if
    end; // for tt
  finally
    lTaxResultInvoiceLines.Free;
  end;
end;

procedure TfrmInvoiceEdit.UpdateTaxinvoiceLinesForRoomItemUsingBackend(aInvLine: TInvoiceLine);
var
  iList: IList<TxsdRoomRentTaxReceiptType>;
  lObject: TxsdRoomRentTaxReceiptType;
begin

  RemoveTaxinvoiceLinesForRoomItem(aInvLine);

  FStayTaxEnabled := ctrlGetBoolean('useStayTax') AND RV_useStayTax(FReservation);
  if not FStayTaxEnabled then
    exit;

  if not Supports(FTaxAPIResponse.Receipts, IObjectList, iList) then
    exit;

  for lObject in iList.Where(
        function(const aObject: TxsdRoomRentTaxReceiptType): boolean
                                  begin
                                    Result := (aObject.RoomReservationId = aInvLine.Roomreservation)
                                              and (aObject.StayDate = aInvLine.PurchaseDate);
                                  end
  ) do
    AddRoomTaxToInvoiceLines(
          TAmount.Create(lObject.CityTax.Amount, lObject.CityTax.Currency.AsString).ToNative.Value,
          lObject.Quantity, //trunc(lTaxResultInvoiceLines[l].NumItems),
          lObject.Item, // TaxTypes[tt],
          aInvLine.RoomEntity.Arrival,
          0,
          aInvLine,
          lObject.CityTaxIncludedInRoomPrice //  lIsIncluded
    );
end;

procedure TfrmInvoiceEdit.tvPaymentNativeAmountGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  aProperties := RoomerCurrencyManager.DefaultCurrencyDefinition.GetcxEditProperties();
end;

procedure TfrmInvoiceEdit.tvPaymentsCurrencyAmountGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  aProperties := RoomerCurrencyManager[mPaymentsCurrency.AsString].GetcxEditProperties();
end;

procedure TfrmInvoiceEdit.tvPaymentsMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
  X, Y: integer);
begin
  if ssCtrl in Shift then
  begin
    grPayments.BeginDrag(True);
  end;
end;

function TfrmInvoiceEdit.getTotalDownPayments: TAmount;
begin
  Result := 0;

  if mPayments.RecordCount > 0 then
  begin
    mPayments.DisableControls;
    try
      mPayments.first;
      while not mPayments.eof do
      begin
        Result := Result + mPaymentsNativeAmount.AsFloat; // in native currency
        mPayments.Next;
      end;
    finally
      mPayments.EnableControls;
    end;
  end;
  // Items in a credit invoice as specified positive, but payments are save as negative ...............
  result := IIF(FIsCredit, -1, 1) * Result;
end;

procedure TfrmInvoiceEdit.loadInvoiceToMemtable(var m: TKbmMemTable);
var
  i: integer;
  lineItem: string;
  lineDescription: string;
  lineItemCount: string;
  lineItemPrice: string;
  lineTotalPrice: string;
  lineSystem: string;
  lineDate: string;
  lineRefrence: string;
  lineSource: string;
  lineisPackage: string;
  lineNoGuests: string;
  lineConfirmdate: string;
  lineConfirmAmount: string;
  linerrAlias: string;

  ItemCount: Double;
  ItemPrice: Double;
  TotalPrice: Double;
  sTmp: string;

  ItemTypeInfo: TItemTypeInfo;
  iMultiplier: integer;
  iNights: integer;
  irrAlias: integer;
  fVat: Double;
  iPersons: integer;

  AYear, AMon, ADay: Word;
  bSystemLine: boolean;

  lInvRoom: TInvoiceRoomEntity;
  lInvLine: TInvoiceLine;
  lDate: TDate;

begin
  for i := 1 to agrLines.RowCount - 1 do
  begin
    lineItem := trim(agrLines.Cells[col_Item, i]);
    lineDescription := trim(agrLines.Cells[col_Description, i]);
    lineItemCount := trim(agrLines.Cells[col_ItemCount, i]);
    lineItemPrice := trim(agrLines.Cells[col_ItemPrice, i]);
    lineTotalPrice := trim(agrLines.Cells[col_TotalPrice, i]);
    lineSystem := trim(agrLines.Cells[col_System, i]);
    lineDate := trim(agrLines.Cells[col_date, i]);
    lineRefrence := trim(agrLines.Cells[col_Reference, i]);
    lineSource := trim(agrLines.Cells[col_Source, i]);
    lineisPackage := trim(agrLines.Cells[col_isPackage, i]);
    lineNoGuests := trim(agrLines.Cells[col_NoGuests, i]);
    lineConfirmdate := trim(agrLines.Cells[col_confirmdate, i]);
    lineConfirmAmount := trim(agrLines.Cells[col_confirmAmount, i]);
    // lineVat := trim(agrLines.Cells[col_Vat, i]);
    linerrAlias := trim(agrLines.Cells[col_rrAlias, i]);

    if (lineItem = '') or (isSystemLine(i) = false) then
    begin
      continue;
    end;

    bSystemLine := isSystemLine(i);

    try
      decodedate(integer(agrLines.Objects[cPurchaseDateAsObjectColumn, i]), AYear, AMon, ADay);
    except
      decodedate(now, AYear, AMon, ADay);
    end;

    iMultiplier := 1;

    if FIsCredit then
    begin
      iMultiplier := -1;
    end;

    ItemTypeInfo := d.Item_Get_ItemTypeInfo(lineItem);

    iNights := 0;
    lInvLine := GetInvoiceLineByRow(i);
    if assigned(lInvLine.RoomEntity) then
      iNights := lInvLine.RoomEntity.NumberOfNights;

    iPersons := 0;
    if lineNoGuests <> '' then
    begin
      iPersons := strToInt(lineNoGuests)
    end;

    sTmp := lineItemCount;
    try
      ItemCount := _StrToFloat(sTmp);
    except
      ItemCount := 0;
    end;

    sTmp := lineItemPrice;
    try
      ItemPrice := _StrToFloat(sTmp);
    except
      ItemPrice := 0;
    end;

    ItemPrice := iMultiplier * InvoiceCurrencyRate * ItemPrice;
    TotalPrice := ItemCount * ItemPrice * iMultiplier;

    lInvRoom := TInvoiceRoomEntity.Create(lineItem, 1, 0, ItemCount, TotalPrice, g.qNativeCurrency, 1.0, 0, 0, false);
    try
      fVat := GetVATForItem(lineItem, TotalPrice, ItemCount, lInvRoom, tempInvoiceItemList, ItemTypeInfo,
        edtCustomer.Text);
    finally
      lInvRoom.Free;
    end;

    irrAlias := -1;
    try
      if linerrAlias <> '' then
        irrAlias := strToInt(linerrAlias);
    Except
    end;

    // asi lason
    // johann te
    // lee child

    m.insert;
    m.FieldByName('Reservation').asinteger := FReservation;
    m.FieldByName('AutoGen').asString := _GetCurrentTick2;
    m.FieldByName('RoomReservation').asinteger := FRoomReservation;
    m.FieldByName('SplitNumber').asinteger := ord(FInvoiceType);
    m.FieldByName('ItemNumber').asinteger := i;
    lDate := integer(agrLines.Objects[cPurchaseDateAsObjectColumn, i]);
    m.FieldByName('PurchaseDate').asString := _db(lDate);
    m.FieldByName('InvoiceNumber').asinteger := zInvoiceNumber;
    m.FieldByName('ItemId').asString := lineItem;
    m.FieldByName('Number').AsFloat := ItemCount;
    m.FieldByName('Description').asString := lineDescription;
    m.FieldByName('Price').AsFloat := ItemPrice;
    m.FieldByName('VATType').asString := ItemTypeInfo.VATCode;
    m.FieldByName('Total').AsFloat := TotalPrice;
    m.FieldByName('TotalWOVat').AsFloat := TotalPrice - fVat;
    // _CommaToDot(floattostr(iMultiplier * fItemTotalWOVat));
    m.FieldByName('VAT').AsFloat := fVat;
    // _CommaToDot(floattostr(iMultiplier * fItemTotalVAT));
    m.FieldByName('CurrencyRate').AsFloat := InvoiceCurrencyRate;
    m.FieldByName('Currency').asString := InvoiceCurrencyCode;
    m.FieldByName('Persons').asinteger := iPersons;
    m.FieldByName('Nights').asinteger := iNights;
    m.FieldByName('BreakfastPrice').AsFloat := 0.00;
    m.FieldByName('AutoGenerated').asBoolean := false;
    m.FieldByName('AYear').asinteger := AYear;
    m.FieldByName('AMon').asinteger := AMon;
    m.FieldByName('ADay').asinteger := ADay;
    m.FieldByName('ilAccountKey').asString := d.Item_Get_AccountKey(lineItem);
    m.FieldByName('importRefrence').asString := lineRefrence;
    m.FieldByName('importSource').asString := lineSource;
    m.FieldByName('isPackage').asBoolean := false;
    m.FieldByName('confirmDate').asdateTime := now;
    m.FieldByName('confirmAmount').AsFloat := 0.00;
    m.FieldByName('RoomReservationAlias').asinteger := irrAlias;
    m.FieldByName('issystemLine').asBoolean := bSystemLine;
    m.post;
  end;
end;

function TfrmInvoiceEdit.GetInvoiceIndexPanel(Index: integer): TsPanel;
begin
  result := TsPanel(FindComponent('pnlInvoiceIndex' + inttostr(Index)));
end;

function TfrmInvoiceEdit.GetInvoiceIndexItems(Index: integer): TShape;
begin
  result := TShape(FindComponent('shpInvoiceIndex' + inttostr(Index)));
end;

function TfrmInvoiceEdit.GetInvoiceIndexItemsRR(Index: integer): TShape;
begin
  result := TShape(FindComponent('shpInvoiceIndexRR' + inttostr(Index)));
end;

procedure TfrmInvoiceEdit.shpInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
begin
  pnlInvoiceIndex0DragDrop(TShape(Sender), Source, X, Y);
end;

procedure TfrmInvoiceEdit.shpInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState;
  var Accept: boolean);
begin
  pnlInvoiceIndex0DragOver(TShape(Sender), Source, X, Y, State, Accept);
end;

procedure TfrmInvoiceEdit.pnlInvoiceIndicesDragOver(Sender, Source: TObject; X, Y: Integer; State: TDragState;
  var Accept: Boolean);
begin
  Accept := False;
  if Y < 15 then
    pnlInvoiceIndices.VertScrollBar.Position := pnlInvoiceIndices.VertScrollBar.Position - 8
  else if Y > pnlInvoiceIndices.Height  - 15 then
    pnlInvoiceIndices.VertScrollBar.Position := pnlInvoiceIndices.VertScrollBar.Position + 8;
end;

procedure TfrmInvoiceEdit.shpInvoiceIndex0MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
  X, Y: integer);
begin
  pnlInvoiceIndex0Click(TShape(Sender).Parent);
end;

function TfrmInvoiceEdit.GetCalculatedNumberOfItems(ItemId: String; dDefault: Double): Double;
begin
  case glb.GetNumberBaseOfItem(ItemId) of
    INB_USER_EDIT:
      result := dDefault;
    INB_ROOM_NIGHT:
      result := linesNumDays;
    INB_GUEST_NIGHT:
      result := NumberGuestNights;
    INB_GUEST:
      result := linesNumGuests;
    INB_ROOM:
      result := 1.0;
    INB_BOOKING:
      result := 1.0;
  else
    result := dDefault;
  end;
end;

procedure TfrmInvoiceEdit.UpdateInvoiceIndexTabs;
var
  i: integer;
  pnl: TPanel;
  lInvLinesIndicator, lRoomRentIndicator: TShape;
begin

  FInvoiceIndexTotals.UpdateIndexTotals(FReservation, FRoomReservation);

  for i := 0 to 9 do
  begin
    pnl := GetInvoiceIndexPanel(i);
    lInvLinesIndicator := GetInvoiceIndexItems(i);
    lRoomRentIndicator := GetInvoiceIndexItemsRR(i);

    lInvLinesIndicator.Hint := '';
    lInvLinesIndicator.Brush.Color := clWhite;

    if FInvoiceIndexTotals.HasInvoiceLines[i] then
    begin
      lInvLinesIndicator.Hint := RoomerCurrencyManager[InvoiceCurrencyCode].FormattedValueWithCode(FInvoiceIndexTotals.TotalInvoiceLinesOnIndex[i]);
      lInvLinesIndicator.Brush.Color := clRed; // $00C1FFFF;
    end;
    lInvLinesIndicator.Visible := FInvoiceIndexTotals.HasInvoiceLines[i];

    lRoomRentIndicator.Hint := '';
    lRoomRentIndicator.Brush.Color := clWhite;
    if FInvoiceIndexTotals.HasRoomRentItems[i] then
    begin
      lRoomRentIndicator.Hint := RoomerCurrencyManager[InvoiceCurrencyCode].FormattedValueWithCode(FInvoiceIndexTotals.TotalRoomRentOnIndex[i]);
      lRoomRentIndicator.Brush.Color := clBlue; // $00FFCFA8;
    end;
    lRoomRentIndicator.Visible := FInvoiceIndexTotals.HasRoomRentItems[i];

    if pnl.Tag = InvoiceIndex then
      pnl.Color := $00FFCFA8
    else
      pnl.Color := clWhite;

    pnl.Font.Color := clBlack;

  end;
end;

procedure TfrmInvoiceEdit.RetrieveTaxesforRoomReservation(aReservation, aRoomreservation: integer);
var
  lCaller: TBookingsTaxesTabAPICaller;
begin

  lCaller := TBookingsTaxesTabAPICaller.Create;
  try
    if not lCaller.GetRoomReservationTaxes(aReservation, aRoomreservation, FTaxApiResponse) then
      FTaxAPIResponse.Clear;
  finally
    lCaller.Free;
  end;

end;

procedure TfrmInvoiceEdit.DoLoadData;
var
  ItemId: string;
  LineId: integer;
  Price: Double;
  CurrencyRate: Double;
  _s: string;

  lRoomReservation: integer;
  Room: string;
  invoiceHeadData: recInvoiceHeadHolder;

  lExecutionPlan: TRoomerExecutionPlan;

  sql: string;
  package: string;

  eSet, lInvoiceHeadSet, reservationSet: TRoomerDataset;

  dNumber: Double;
  lRoomAdditionalText: string;

  procedure SetInvoiceAddressTypeIndex(Index: integer);
  begin
    rgrInvoiceAddressType.OnClick := nil;
    try
      rgrInvoiceAddressType.itemIndex := index;
    finally
      rgrInvoiceAddressType.OnClick := rgrInvoiceAddressTypeClick;
    end;
  end;

label
  Again;

begin

  inherited;
  lInvoiceHeadSet := CreateNewDataSet;

  mRoomRes.DisableControls;
  mRoomRates.DisableControls;
  agrLines.BeginUpdate;
  try
    Screen.Cursor := crHourGlass;
    if mRoomRes.active then
      mRoomRes.close;
    mRoomRes.Open;
    if mRoomRates.active then
      mRoomRates.close;
    mRoomRates.Open;

    ClearInvoiceLines;
    ClearRoomInfoObjects;
    InitInvoiceGrid;

    // -- First the Invoice headers...
    zInvoiceNumber := -1;
    zInvoiceDate := now;
    zPayDate := now;
    zConfirmDate := 2;

    if IsCashInvoice then // FnewSplitNumber = cCashInvoice then
    begin
      CreateCashInvoice(g.qRackCustomer);
      InvoiceCurrencyCode := g.qNativeCurrency;
      exit;
    end;

    edResNr.Caption := format('%d / %d', [FReservation, FRoomReservation]);


  Again:
    // Retrieve invoice header information
    sql := 'SELECT ' +
      '(SELECT GroupAccount FROM roomreservations rr WHERE rr.RoomReservation=ih.RoomReservation) rrGroupAccount, ' +
      '(SELECT SUM(RoomRate) FROM roomsdate rd WHERE (rd.RoomReservation=ih.RoomReservation ' +
      'OR rd.Reservation=ih.Reservation) AND rd.Paid=0 AND (NOT rd.ResFlag IN (''C'',''X'',''N'',''O''))) AS rrInvoiceTotal, '
      + 'ih.Reservation, ' + 'ih.RoomReservation, ' + 'ih.SplitNumber, ' + 'ih.InvoiceNumber, ' + 'ih.InvoiceDate, ' +
      'IFNULL(ia.Customer, ih.Customer) AS Customer, ' + 'IFNULL(ia.Name, ih.Name) AS Name, ' +
      'IFNULL(ia.Address1, ih.Address1) AS Address1, ' + 'IFNULL(ia.Address2, ih.Address2) AS Address2, ' +
      'IFNULL(ia.Zip, ih.Address3) AS Address3, ' + 'IFNULL(ia.City, ih.Address4) AS Address4, ' +
      'IFNULL(ia.Country, ih.Country) AS Country, ' + 'ih.Total, ' + 'ih.TotalWOVAT, ' + 'ih.TotalVAT, ' +
      'ih.TotalBreakFast, ' + 'IFNULL(ia.ExtraText, ih.ExtraText) AS ExtraText, ' + 'ih.Finished, ' + 'ih.ReportDate, '
      + 'ih.ReportTime, ' + 'ih.CreditInvoice, ' + 'ih.OriginalInvoice, ' +
      'IFNULL(ia.InvoiceType, ih.InvoiceType) AS InvoiceType, ' + 'ih.ihTmp, ' + 'ih.ID, ' +
      'IFNULL(ia.CustPID, ih.CustPID) AS custPID, ' + 'ih.RoomGuest, ' + 'ih.ihDate, ' + 'ih.ihStaff, ' +
      'ih.ihPayDate, ' + 'ih.ihConfirmDate, ' + 'ih.ihInvoiceDate, ' +
      'COALESCE(ia.ihcurrency, ih.ihcurrency) as ihCurrency, ' +           // See Note on end of unit!
      'ih.invRefrence, ' +
      'ih.TotalStayTax, ' + 'ih.TotalStayTaxNights, ' + 'ih.showPackage, ' + 'ih.staff, ' + 'ih.location, ' +
      'ih.externalInvoiceId ' +
      'FROM invoiceheads ih ' + #10 +
      '     LEFT JOIN invoiceaddressees ia ON ia.invoiceNumber=ih.InvoiceNumber ' +
      '        AND ia.Reservation=ih.Reservation ' + '        AND ia.RoomReservation=ih.RoomReservation ' +
      '        AND ia.SplitNumber=ih.SplitNumber ' + '        AND ia.InvoiceIndex=%d ' + 'where ih.Reservation = %d '#10
      + '   and ih.RoomReservation = %d and ih.SplitNumber = %d '#10 +
      '   and ih.InvoiceNumber = -1 and ih.Finished = 0';
    if lInvoiceHeadSet.active then
      lInvoiceHeadSet.close;

    sql := format(sql, [InvoiceIndex, FReservation, FRoomReservation, ord(FInvoiceType)]);

    copytoclipboard(sql);

    hData.rSet_bySQL(lInvoiceHeadSet, sql);

    lInvoiceHeadSet.first;

    // If invoice header is found...
    if not lInvoiceHeadSet.eof then
    begin

      zInvoiceNumber := lInvoiceHeadSet.FieldByName('InvoiceNumber').asinteger;

      GetInvoiceHeader(FReservation, FRoomReservation, lInvoiceHeadSet); // To initialize with current data
      SetInvoiceAddressTypeIndex(lInvoiceHeadSet.FieldByName('InvoiceType').asinteger);

      if lInvoiceHeadSet.FieldByName('InvoiceType').asinteger = 1 then   // Reservation customer
        GetReservationHeader(FReservation, FRoomReservation);

      if FInvoiceType = itCreditInvoice then // Kreditinvoice
      begin
        GetInvoiceHeader(FReservation, FRoomReservation);
        SetInvoiceAddressTypeIndex(3);
      end;

      HeaderChanged := false;
      btnGetCustomer.Enabled := rgrInvoiceAddressType.itemIndex <> 1;
      btnClearAddresses.Enabled := rgrInvoiceAddressType.itemIndex <> 1;

      InvoiceCurrencyCode := trim(lInvoiceHeadSet.FieldByName('ihCurrency').asString);
      memExtraText.Lines.Text := trim(lInvoiceHeadSet.FieldByName('ExtraText').asString);

    end
    else
    begin
      // Otherwise - create New invoiceheader
      zInvoiceNumber := -1;
      zInvoiceDate := now;
      zConfirmDate := 2;
      zPayDate := trunc(now);

      if lInvoiceHeadSet.active then
        lInvoiceHeadSet.close;

      sql := 'SELECT r.*, rr.Currency '#10 +
             ' FROM reservations r '#10 +
             ' JOIN roomreservations rr ON r.Reservation=rr.Reservation '#10 +
             ' JOIN roomsdate rd on rr.roomreservation=rd.roomreservation and rd.resflag not in (''X'', ''C'') '#10 +
             ' WHERE r.Reservation = %d '#10 +
             ' AND ((%d=0) OR (rr.roomreservation = %d))';

      sql := format(sql, [FReservation, FRoomreservation, FRoomreservation]);

      hData.rSet_bySQL(lInvoiceHeadSet, sql);

      lInvoiceHeadSet.first;
      // INS-InvoiceHead
      // If there is no invoiceheader then create it
      // and goto label Again
      if not lInvoiceHeadSet.eof then
      begin
        initInvoiceHeadHolderRec(invoiceHeadData);

        invoiceHeadData.reservation := FReservation;
        invoiceHeadData.RoomReservation := FRoomReservation;
        invoiceHeadData.SplitNumber := ord(FInvoiceType);
        invoiceHeadData.InvoiceNumber := zInvoiceNumber;
        invoiceHeadData.InvoiceDate := _db(zInvoiceDate, false);
        invoiceHeadData.ihCurrency := lInvoiceHeadSet.FieldByName('Currency').asString;
        invoiceHeadData.ihCurrencyRate := GetRate(lInvoiceHeadSet.FieldByName('Currency').asString);

        invoiceHeadData.customer := lInvoiceHeadSet.FieldByName('Customer').asString;
        invoiceHeadData.Name := lInvoiceHeadSet.FieldByName('Name').asString;
        invoiceHeadData.Address1 := lInvoiceHeadSet.FieldByName('Address1').asString;
        invoiceHeadData.Address2 := lInvoiceHeadSet.FieldByName('Address2').asString;
        invoiceHeadData.Address3 := lInvoiceHeadSet.FieldByName('Address3').asString;
        invoiceHeadData.Address4 := '';
        // ATH _db(zrSet.FieldByName('Address4').asString);
        invoiceHeadData.Country := lInvoiceHeadSet.FieldByName('Country').asString;
        invoiceHeadData.Total := 0.00;
        invoiceHeadData.TotalWOVat := 0.00;
        invoiceHeadData.TotalVAT := 0.00;
        invoiceHeadData.TotalBreakFast := 0.00;
        invoiceHeadData.ExtraText := memExtraText.Lines.Text;
        invoiceHeadData.Finished := false;
        invoiceHeadData.InvoiceType := rgrInvoiceAddressType.itemIndex;
        invoiceHeadData.CustPID := lInvoiceHeadSet.FieldByName('CustPid').asString;
        invoiceHeadData.ihDate := Date;
        invoiceHeadData.ihInvoiceDate := zInvoiceDate;
        invoiceHeadData.ihConfirmDate := zConfirmDate;
        invoiceHeadData.ihPayDate := zPayDate;
        invoiceHeadData.ihStaff := g.qUser;
        hData.SP_INS_InvoiceHead(invoiceHeadData);
        goto Again;
      end
    end;

    DisplayGuestName;

//    RetrieveTaxesforRoomReservation(FReservation, FRoomreservation);

    if ShowRentPerDay then
      GenerateRoomRentLinesPerDay
    else
      GenerateRoomRentLinesPerRoom;

    lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
    try
      RestoreTMPInvoicelines;

      // -- Then the invoice lines..., excluding left over package lines from cancelled rooms
      sql := 'SELECT il.*, '#10 +
        ' (select resflag from roomsdate rd where rd.roomreservation=il.roomreservationalias limit 1) as resflag '#10 +
        ' FROM invoicelines il '#10 +
        ' where Reservation = %d '#10 +
        '   and RoomReservation = %d '#10 +
        '   and SplitNumber = %d '#10 +
        '   and InvoiceNumber = -1 AND InvoiceIndex = %d'#10 +
        ' having not il.isPackage or coalesce(resflag, '''') not in (''X'', ''C'') ';
      sql := format(sql, [FReservation, FRoomReservation, ord(FInvoiceType), FInvoiceIndex]);
      lExecutionPlan.AddQuery(sql);

      sql := 'SELECT ' +
        ' SUM(IF(xxx.RoomReservation>0 AND xxx.Reservation>0, xxx.NumberOfGuests * xxx.NumberOfDays, ' +
        ' (SELECT SUM((SELECT COUNT(id) FROM roomsdate WHERE RoomReservation = pe.RoomReservation AND NOT (ResFlag IN (''X'',''C'',''N'')))) AS GuestNights ' +
         '   FROM persons pe ' + '   WHERE pe.Reservation=xxx.Reservation) ' + ')) AS NumberGuestNights, ' +
        'SUM(NumberOfDays) AS NumberOfDays, ' + 'SUM(NumberOfGuests) AS NumberOfGuests ' + 'FROM ( ' +
        'SELECT RoomReservation, Reservation, IF(il.RoomReservation>0 AND il.Reservation>0, (SELECT COUNT(ID) FROM roomsdate WHERE RoomReservation=il.RoomReservation AND NOT (ResFlag IN (''X'',''C'',''N'')) LIMIT 1), ' +
         '          IF(il.Reservation>0, (SELECT COUNT(ID) FROM roomsdate WHERE Reservation=il.Reservation AND NOT (ResFlag IN (''X'',''C'',''N'')) LIMIT 1), ' +
         '          0)) AS NumberOfDays, ' + ' ' +
        '       IF(il.RoomReservation>0 AND il.Reservation>0, (SELECT COUNT(ID) FROM persons WHERE RoomReservation=il.RoomReservation LIMIT 1), ' +
         '          IF(il.Reservation>0, (SELECT COUNT(ID) FROM persons WHERE Reservation=il.Reservation LIMIT 1), 0)) AS NumberOfGuests ' +
         ' FROM roomreservations il ' +
        ' where (%d <= 0 AND Reservation=%d) OR (RoomReservation = %d) ' + ') xxx';
      sql := format(sql, [FRoomReservation, FReservation, FRoomReservation]);
      lExecutionPlan.AddQuery(sql);

      lExecutionPlan.Execute(ptQuery);

      eSet := lExecutionPlan.Results[0];
      reservationSet := lExecutionPlan.Results[1];

      if zFirsttime then // **15-10-16
      begin
        if d.mInvoicelines_before.active then
          d.mInvoicelines_before.close;
        d.mInvoicelines_before.Open;

        if d.mInvoicelines_after.active then
          d.mInvoicelines_after.close;
        d.mInvoicelines_after.Open;

        d.mInvoicelines_before.LoadFromDataSet(eSet, []);
      end;

      eSet.first;
      reservationSet.first;
      if NOT reservationSet.eof then
      begin
        linesNumDays := reservationSet['NumberOfDays'];
        linesNumGuests := reservationSet['NumberOfGuests'];
        NumberGuestNights := reservationSet['NumberGuestNights'];
      end;
      while not eSet.eof do
      begin
        ItemId := trim(eSet.FieldByName('ItemId').asString);
        LineId := eSet.FieldByName('Id').asinteger;

        CurrencyRate := eSet.FieldByName('CurrencyRate').AsFloat;
        Price := eSet.FieldByName('Price').AsFloat;

        if Item_isRoomRent(ItemId) then
        begin
          if CurrencyRate <> 0 then
          begin
            Price := Price / CurrencyRate
          end;
        end;
        Room := '';
        lRoomReservation := eSet.FieldByName('roomreservationAlias').asinteger;
        if mRoomRes.Locate('roomreservation', lRoomReservation, []) then
        begin
          Room := mRoomRes.FieldByName('room').asString;
        end;
        _s := trim(eSet.FieldByName('Description').asString);

        lRoomAdditionalText := GetTranslatedText('shRoom') + ':';
        if (eSet.FieldByName('isPackage').asBoolean) and not _s.Contains(lRoomAdditionalText) then
          _s := _s + format(' %s %s', [lRoomAdditionalText, Room]);

        dNumber := GetCalculatedNumberOfItems(ItemId, eSet.FieldByName('Number').AsFloat);
        package := trim(eSet.FieldByName('importSource').asString);

        AddLine(LineId, nil, ItemId, _s, dNumber, Price, g.qNativeCurrency, eSet.FieldByName('VATType').asString,
          SQLToDate(eSet.FieldByName('PurchaseDate').asString), false,
          trim(eSet.FieldByName('importRefrence').asString), package,
          eSet.FieldByName('isPackage').asBoolean, eSet.FieldByName('Persons').asinteger,
          eSet.FieldByName('ConfirmDate').asdateTime, eSet.FieldByName('ConfirmAmount').AsFloat, lRoomReservation,
          eSet.FieldByName('AutoGen').asString, eSet.FieldByName('ItemNumber').asinteger, eSet.FieldByName('visibleoninvoice').asBoolean );

        eSet.Next;
      end;

      if (FReservation = 0) and (FRoomReservation = 0) then
      begin
        // what
      end
      else
        LoadPayments;

      agrLines.Objects[cPurchaseDateAsObjectColumn, agrLines.RowCount - 1] := TObject(trunc(now));
      // -- PurchaseDate !
      agrLines.Cells[col_date, agrLines.RowCount - 1] := datetostr(trunc(now));

      if zFirsttime then // **15-10-16
      begin
        zFirsttime := false;
        loadInvoiceToMemtable(d.mInvoicelines_before);
      end;
    finally
      lExecutionPlan.Free;
    end;

    UpdateItemInvoiceLinesForTaxCalculations;
    FInvoiceLinesList.ResetChanged;

    AddEmptyLine(false);

  finally
    lInvoiceHeadSet.Free;
    mRoomRes.EnableControls;
    mRoomRates.EnableControls;
    agrLines.EndUpdate;
    Screen.Cursor := crDefault;
    zFirsttime := True;
  end;

  UpdateGrid;
  SetCurrentVisible;
  UpdateControls;
end;

procedure TfrmInvoiceEdit.LoadPayments;
var
  sql: string;
  eSet: TRoomerDataSet;
  id: integer;
begin
  eSet := CreateNewDataSet;
  mPayments.DisableControls;
  try
    id := mPaymentsid.AsInteger;
    mPayments.close;
    mPayments.Open;

    sql := 'SELECT * FROM payments ' + ' where Reservation = %d ' + '   and RoomReservation = %d ' +
      '   and InvoiceNumber = -1 AND InvoiceIndex = %d and person = %d';
    sql := format(sql, [FReservation, FRoomReservation, FInvoiceIndex, ord(FInvoiceType)]);

    hData.rSet_bySQL(eSet, sql);

    eSet.first;
    while not eSet.eof do
    begin
      mPayments.insert;
      mPaymentsPayType.asString := eSet.FieldByName('PayType').asString;
      mPaymentsPayDate.asdateTime := SQLToDateTime(eSet.FieldByName('PayDate').asString);
      mPaymentsCurrency.AsString := eSet.FieldByName('Currency').AsString;
      mPaymentsNativeAmount.AsFloat := eSet.FieldByName('Amount').AsFloat;
      mPaymentsDescription.asString := eSet.FieldByName('Description').asString;
      mPaymentsPayGroup.asString := '';
      mPaymentsMemo.asString := eSet.FieldByName('Notes').asString;
      mPaymentsconfirmDate.asdateTime := eSet.FieldByName('Confirmdate').asdateTime;
      mPaymentsId.asinteger := eSet.FieldByName('ID').asinteger;
      mPaymentsPaycardTraceIndex.AsInteger := eSet.FieldByName('Paycard_Trace_index').AsInteger;

      if glb.Paytypesset.Locate('payType', eSet.FieldByName('PayType').asString, []) then
        mPaymentsPayGroup.asString := glb.Paytypesset.FieldByName('payGroup').asString;

      mPayments.post;
      eSet.Next;
    end;

    mPayments.Locate('id', id, []);
  finally
    mPayments.EnableControls;
    eSet.Free;
  end;
end;

function TfrmInvoiceEdit.FindLastRoomRentLine: integer;
var
  i: integer;
begin
  result := 0;
  for i := 1 to agrLines.RowCount - 1 do
  begin
    if agrLines.Cells[col_Item, i] = g.qRoomRentItem then
      result := i
    else
      Break;
  end;
end;

procedure TfrmInvoiceEdit.UpdateItemInvoiceLinesForTaxCalculations;
var
  taxNights: Double;
  taxGuests: integer;
  //
  i: integer;
  ItemPrice: Double;
  //
  Item: string;
  //
  itemVAT: Double;
  ItemTypeInfo: TItemTypeInfo;
  lInvRoom: TInvoiceRoomEntity;
begin

  tempInvoiceItemList.Clear;

  for i := 1 to agrLines.RowCount - 1 do
  begin
    Item := _trimlower(agrLines.Cells[col_Item, i]);
    if trim(Item) <> '' then
    begin
      ItemTypeInfo := d.Item_Get_ItemTypeInfo(Item, agrLines.Cells[col_Source, i]);

      taxGuests := StrToIntDef(trim(agrLines.Cells[col_NoGuests, i]), 0);
      taxNights := StrToIntDef(trim(agrLines.Cells[col_ItemCount, i]), 0);
      ItemPrice := StrToFloatDef(trim(agrLines.Cells[col_ItemPrice, i]), 0.00);

      itemVAT := 0.00;
      if ItemPrice <> 0 then
      begin
        lInvRoom := TInvoiceRoomEntity.Create(Item, taxGuests, 0, taxNights, ItemPrice, InvoiceCurrencyCode, InvoiceCurrencyRate, 0, 0, false);
        try
          itemVAT := GetVATForItem(Item, ItemPrice, 1, lInvRoom, tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);
          // BHG
        finally
          lInvRoom.Free;
        end;
      end;

      tempInvoiceItemList.Add(TInvoiceItemEntity.Create(Item, taxNights, ItemPrice, itemVAT));
    end;
  end;
end;

procedure TfrmInvoiceEdit.calcAndAddAutoItems(reservation: integer; aAutoItems: TInvoiceAutoItemSet);
var
  taxNights: Double;
  taxGuests: integer;
  taxChildren: integer;
  Discount: Double;

  i: integer;
  ItemPrice: Double;
  //
  Item: string;
  //
  RoomInvoiceLines: TInvoiceRoomEntityList;
  ItemInvoiceLines: TInvoiceItemEntityList;

  itemVAT: Double;
  ItemTypeInfo: TItemTypeInfo;

  lInvRoom: TInvoiceRoomEntity;

  lBreakfastIncl: boolean;
  litemKind: TItemKind;
  lInvLine: TInvoiceLine;

begin

  itemVAT := 0.00;

  ItemInvoiceLines := TInvoiceItemEntityList.Create(True);
  RoomInvoiceLines := TInvoiceRoomEntityList.Create(True);
  try
    for i := 1 to agrLines.RowCount - 1 do
    begin
      Item := _trimlower(agrLines.Cells[col_Item, i]);
      if trim(Item) <> '' then
      begin
        ItemTypeInfo := d.Item_Get_ItemTypeInfo(Item, agrLines.Cells[col_Source, i]);
        litemKind := Item_GetKind(Item);

        taxGuests := StrToIntDef(trim(agrLines.Cells[col_NoGuests, i]), 0);
        taxNights := StrToFloatDef(trim(agrLines.Cells[col_ItemCount, i]), 0.00);

        lInvLine := GetInvoiceLineByRow(i);

        if assigned(lInvLine.RoomEntity) then
        begin
          taxChildren := lInvLine.RoomEntity.NumChildren;
          Discount := lInvLine.RoomEntity.Discount;
          lBreakfastIncl := lInvLine.RoomEntity.BreakFastIncluded;
        end
        else
        begin
          taxChildren := 0;
          Discount := 0;
          lBreakfastIncl := false;
        end;

        if SameValue(taxNights, 0) then
          ItemPrice := 0.00
        else
          ItemPrice := StrToFloatDef(agrLines.Cells[col_TotalPrice, i], 0.00) / taxNights;
        // use total price because itemprice is rounded

        lInvRoom := nil;
        if not SameValue(ItemPrice, 0) then
        begin
          lInvRoom := TInvoiceRoomEntity.Create(Item, taxGuests, taxChildren, taxNights, ItemPrice, InvoiceCurrencyCode, InvoiceCurrencyRate, 0, Discount,
            lBreakfastIncl);
          lInvRoom.Vat := GetVATForItem(Item, ItemPrice, 1, lInvRoom, tempInvoiceItemList, ItemTypeInfo,
            edtCustomer.Text);

          // if NOT(lItemKind IN [ikRoomRent, ikRoomRentDiscount]) then
          // agrLines.Cells[col_Vat, i] := trim(_floattostr(itemVAT, vWidth, 3));
        end;

        if (litemKind = ikRoomRent) then
          if assigned(lInvRoom) then
            RoomInvoiceLines.Add(lInvRoom)
          else
            RoomInvoiceLines.Add(TInvoiceRoomEntity.Create(Item, taxGuests, taxChildren, taxNights, ItemPrice, InvoiceCurrencyCode, InvoiceCurrencyRate, itemVAT,
              Discount, lBreakfastIncl));

        ItemInvoiceLines.Add(TInvoiceItemEntity.Create(Item, taxNights, ItemPrice, itemVAT));
      end;
    end;

    if aiIncludedBreakfast in aAutoItems then
      CalcAndAddIncludedBreakFast(RoomInvoiceLines);

    if aiStayTax in aAutoItems then
      UpdateTaxinvoiceLinesForAllRooms;

  finally
    RoomInvoiceLines.Free;
    ItemInvoiceLines.Free;
  end;
end;

procedure TfrmInvoiceEdit.CalcAndAddIncludedBreakFast(aRoominvoiceLinesList: TInvoiceRoomEntityList);
begin
  if glb.PMSSettings.InvoiceSettings.ShowIncludedBreakfastOnInvoice then
  begin
    AddIncludedBreakfastToLinesAndGrid(aRoominvoiceLinesList.IncludedBreakfastCount, FindLastRoomRentLine + 1);
    DisplayTotals;
  end;
end;

procedure TfrmInvoiceEdit.AddIncludedBreakfastToLinesAndGrid(aIncludedBreakfastCount: integer;
  aPurchaseDate: TDate; iAddAt: integer = 0; aParent: TInvoiceLine = nil);
var
  lText: string;
  lInvoiceLine: TInvoiceLine;
  lItem: string;
  lItemInfo: TItemTypeInfo;
begin
  if (aIncludedBreakfastCount = 0) then
    exit;

  lItem := g.qBreakFastItem;
  lText := Item_GetDescription(lItem) + ' (' + GetTranslatedText('shTx_ReservationProfile_Included') + ')';
  lItemInfo := d.Item_Get_ItemTypeInfo(lItem);
  lInvoiceLine := AddLine(0, aParent, lItem, lText, aIncludedBreakfastCount, Item_GetPrice(lItem),
    g.qNativeCurrency, lItemInfo.VATCode, aPurchaseDate, True, '', '', false, 0, 0, 0, -1, _GetCurrentTick, 0, False);

  lInvoiceLine.IsTotalIncludedInParent := True;

end;

function TfrmInvoiceEdit.GetInvoiceLineVisibility(aReservation: integer; aRoomReservation:integer; aInvoiceIndex: integer;
                                                     aPurchaseDate: TDate; const aItem: string; aDefault: boolean): boolean;
var
  s: string;
  rSet: TRoomerDataset;
begin
  Result := aDefault;
  if ShowRentPerDay then
    s := Format(select_GetInvoiceLineVisible_OnDate, [_db(aReservation), _db(aRoomReservation), _db(aInvoiceIndex), _db(aPurchaseDate), _db(aItem)])
  else
    s := Format(select_GetInvoiceLineVisible_NoDate, [_db(aReservation), _db(aRoomReservation), _db(aInvoiceIndex), _db(aItem)]);

  rSet := CreateNewDataSet;
  try
    if rSet_bySQL(rSet, s) then
      Result := rSet.FieldByName('visible').AsBoolean;
  finally
    rSet.Free;
  end;
end;

procedure TfrmInvoiceEdit.GetTaxTypes(TaxResultInvoiceLines: TInvoiceTaxEntityList);
var
  i: integer;
  Item: String;
begin
  TaxTypes.Clear;
  for i := 0 to TaxResultInvoiceLines.Count - 1 do
  begin
    Item := TaxResultInvoiceLines[i].BookingItem;
    if TaxTypes.IndexOf(Item) < 0 then
      TaxTypes.Add(Item);
  end;
end;

procedure TfrmInvoiceEdit.UpdateControls(aRow: integer=0);
var
  lRow:integer;
  sCurrentItem, sRoomRentItem, sDiscountItem: String;
begin
  lRow := aRow;
  if lRow = 0 then
    lRow := agrLines.Row;

  if (lRow > 0) then
  begin
    sCurrentItem := _trimlower(agrLines.Cells[col_Item, lRow ]);
    sRoomRentItem := _trimlower(g.qRoomRentItem);
    sDiscountItem := _trimlower(g.qDiscountItem);

    actSaveAndExit.Enabled := not IsCashInvoice;
    actSave.Enabled := not IsCashInvoice;
    btnReservationNotes.Enabled := not IsCashInvoice;

    btnMoveRoom.Enabled := (not IsCashInvoice) and ((sCurrentItem = sRoomRentItem) OR (sCurrentItem = sDiscountItem)) OR (AnyRowChecked AND IsRoomSelected);

    actMoveItemToGroupInvoice.Enabled := (not IsCashInvoice) and (AnyRowChecked OR ((NOT isSystemLine(lRow)) AND (sCurrentItem <> '')));
    actRemoveSelected.Enabled := AnyRowChecked OR ((NOT isSystemLine(lRow)) AND (sCurrentItem <> ''));
    btnMoveItem.Enabled := (not IsCashInvoice) and (AnyRowChecked OR ((NOT isSystemLine(lRow)) AND (sCurrentItem <> '')));
  end
  else
  begin
    actMoveItemToGroupInvoice.Enabled := (not IsCashInvoice) and AnyRowChecked;
    btnMoveRoom.Enabled := (not IsCashInvoice) and AnyRowChecked AND IsRoomSelected;
    actRemoveSelected.Enabled := AnyRowChecked;
    btnMoveItem.Enabled := (not IsCashInvoice) and AnyRowChecked;
  end;

  if FStayTaxEnabled then
    actToggleLodgingTax.Caption := GetTranslatedText('shUI_InvoiceDisableLodgingTax')
  else
    actToggleLodgingTax.Caption := GetTranslatedText('shUI_InvoiceEnableLodgingTax');

  pnlTotalsInCurrency.Visible := InvoiceCurrencyCode <> g.qNativeCurrency;

end;

procedure TfrmInvoiceEdit.DeleteLinesInList(ExecutionPlan: TRoomerExecutionPlan);
var
  i: integer;
begin
  for i IN DeletedLines do
  begin
    ExecutionPlan.AddExec('DELETE FROM invoicelines WHERE ID=' + inttostr(i));
  end;
end;

constructor TfrmInvoiceEdit.Create(aOwner: TComponent);
begin
  DeletedLines := TList<integer>.Create;
  SelectableRooms := TRoomInfoList.Create(True);
  SelectableExternalRooms := TRoomInfoList.Create(True);
  TaxTypes := TStringList.Create;

  FInvoiceLinesList := TInvoiceLineList.Create;
  FRoomInfoList := TRoomInfoList.Create(True);
  tempInvoiceItemList := TInvoiceItemEntityList.Create(True);
  FInvoiceIndexTotals := TInvoiceIndexTotalList.Create;
  FTaxAPIResponse := TxsdRoomRentTaxReceiptList.Create;
  inherited;
end;

procedure TfrmInvoiceEdit.FormCreate(Sender: TObject);
begin
  zFirsttime := True;

  linesNumDays := 0;
  linesNumGuests := 0;
  NumberGuestNights := 0;

  FInvoiceIndex := 0;

  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);

  zEmailAddress := '';

  zDoSave := True;

  zLocation := '';
  zOriginalInvoice := 0;

  FCellValueBeforeEdit := '';
  FCellDoubleBeforeEdit := 0.00;
end;

procedure TfrmInvoiceEdit.FormDestroy(Sender: TObject);
begin
  OnResize := nil;
  SelectableRooms.Free;
  SelectableExternalRooms.Free;
  RemoveInvalidKreditInvoice;

  ClearGrid;
  FInvoiceLinesList.Free;
  FRoomInfoList.Free;
//  DeletedLines.Free;

  if mRoomRes.active then
    mRoomRes.close;
  if mRoomRates.active then
    mRoomRates.close;

  TaxTypes.Free;
  tempInvoiceItemList.Free;

  frmMain.btnRefresh.Click;
end;

procedure TfrmInvoiceEdit.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    btnExit.Click;
end;

procedure TfrmInvoiceEdit.FormResize(Sender: TObject);
var
  i: integer;
  iWidth: integer;
begin
  agrLines.AutoFitColumns(false);
  agrLines.ColWidths[col_Select] := 30;
  agrLines.ColWidths[col_VisibleOnInvoice] := 80;
  agrLines.ColWidths[col_Item] := 100;
  agrLines.ColWidths[col_Date] := 100;
  agrLines.ColWidths[col_ItemCount] := 80;
  agrLines.ColWidths[col_ItemPrice] := 80;
  agrLines.ColWidths[col_TotalPrice] := 100;
  agrLines.ColWidths[col_TotalOnInvoice] := 100;
  agrLines.ColWidths[col_Source] := 60;
  iWidth := agrLines.ClientWidth - agrLines.ColWidths[col_Select] - agrLines.ColWidths[col_VisibleOnInvoice] -
    agrLines.ColWidths[col_Item] - agrLines.ColWidths[col_Date] - agrLines.ColWidths[col_ItemCount] - agrLines.ColWidths[col_ItemPrice] -
    agrLines.ColWidths[col_TotalPrice] - agrLines.ColWidths[col_TotalOnInvoice] - agrLines.ColWidths[col_Source] - 5;

  if iWidth > 0 then
    agrLines.ColWidths[col_Description] := iWidth;

//  agrLines.HideColumn(col_date);
  agrLines.HideColumn(col_System);
  agrLines.HideColumn(col_Reference);
  agrLines.HideColumns(col_isPackage, col_autogen);

  for i := 0 to agrLines.ColCount - 1 do
    if agrLines.IsHiddenColumn(i) then
      agrLines.ColWidths[i] := -1;

end;

procedure TfrmInvoiceEdit.FormShow(Sender: TObject);
begin

  if (TInvoiceType(FInvoiceType) = itCashInvoice) and DirectInvoiceLinesExist then
    if MessageDlg(GetTranslatedText('shEditInvoice_CashInvoiceExists'), mtWarning, mbOKCancel, 0) = mrOk then
      d.RemoveDirectInvoiceRemnants(ord(FinvoiceType))
    else
      btnExit.Click;

  actRemoveSelected.Visible := glb.PMSSettings.InvoiceSettings.AllowDeletingItemsFromInvoice;
  actToggleLodgingTax.Visible := glb.PMSSettings.InvoiceSettings.AllowTogglingOfCityTaxes;
  actDeleteDownPayment.Visible := glb.PMSSettings.InvoiceSettings.AllowPaymentModification;
  actEditDownPayment.Visible := glb.PMSSettings.InvoiceSettings.AllowPaymentModification;

  fraInvoiceCurrency.OnCurrencyChangeAndValid := evtCurrencyChangedAndValid;
  fraInvoiceCurrency.Enabled := not IsCashInvoice;

  RefreshData;
  UpdateCaptions;
  UpdateControls;

  Exit1.Enabled := True;
end;

procedure TfrmInvoiceEdit.MoveSelectedLinesToRoomInvoiceIndex(Sender: TObject);
var
  omnu: TMenuItem;
  list: TList<String>;
  i, l: integer;
begin
  //
  omnu := TMenuItem(Sender).Parent;

  list := GetSelectedRows;
  try
    for l := list.Count - 1 downto 0 do
    begin
      i := IndexOfAutoGen(list[l]);
      if i >= 0 then
      begin
        agrLines.row := i;
        MoveItemToRoomInvoice(SelectableRooms[omnu.Tag].RoomReservation, SelectableRooms[omnu.Tag].reservation,
          TMenuItem(Sender).Tag);
      end;
    end;
  finally
    list.Free;
  end;
end;

procedure TfrmInvoiceEdit.mPaymentsCalcFields(DataSet: TDataSet);
begin
  mPaymentsChargedOnCC.AsBoolean := mPaymentsPaycardTraceIndex.AsInteger > 0;
  if not mPaymentsCurrency.IsNull then
    mPaymentsCurrencyAmount.AsFloat := RoomerCurrencyManager.ConvertAmount(mPaymentsNativeAmount.AsFloat, mPaymentsCurrency.AsString);
end;

procedure TfrmInvoiceEdit.ExternalRoomsClick(Sender: TObject);
var
  omnu: TMenuItem;
  list: TList<String>;
  i, l: integer;
begin
  //
  omnu := TMenuItem(Sender).Parent;

  list := GetSelectedRows;
  try
    for l := list.Count - 1 downto 0 do
    begin
      i := IndexOfAutoGen(list[l]);
      if i >= 0 then
      begin
        agrLines.row := i;
        MoveItemToRoomInvoice(SelectableExternalRooms[omnu.Tag].RoomReservation,
          SelectableExternalRooms[omnu.Tag].reservation, TMenuItem(Sender).Tag);
      end;
    end;
  finally
    list.Free;
  end;
end;

procedure TfrmInvoiceEdit.TransferRoomToAnyRoomsClick(Sender: TObject);
var
  omnu: TMenuItem;
  list: TList<String>;
  i, l, RealRoomReservation: integer;

begin
  //
  omnu := TMenuItem(Sender);

  if (MessageDlg(Format(GetTranslatedText('shTx_Invoice_TransferRoomToRoom'), [SelectableExternalRooms[omnu.Tag].Room]),
                  mtConfirmation, [mbYes, mbNo], 0) <> mrYes) then
    Exit;

  list := GetSelectedRows;
  try
    if list.count > 0 then
    begin
      for l := list.Count - 1 downto 0 do
      begin
        i := IndexOfAutoGen(list[l]);
        if i >= 0 then
        begin
          RealRoomReservation := GetInvoiceLineByRow(i).RoomEntity.RoomReservation;
          if d.UpdateGroupAccountone(FReservation, RealRoomReservation, RealRoomReservation, false) then
            UpdatePaidByOfRoomsdate(FRoomReservation, SelectableExternalRooms[omnu.Tag].RoomReservation,
              RealRoomReservation, SelectableExternalRooms[omnu.Tag].reservation);
        end;
      end;
      Refreshdata;
    end;
  finally
    list.Free;
  end;
end;

procedure TfrmInvoiceEdit.UpdatePaidByOfRoomsdate(FromRoomReservation, RoomReservation,
  RealRoomReservation, reservation: integer);
var
  sql: String;
begin
  if RealRoomReservation = RoomReservation then
    sql := format('UPDATE roomsdate rd SET PaidBy=0 WHERE RoomReservation=%d AND (ResFlag NOT IN (''X'',''C''))',
      [RealRoomReservation])
  else
    sql := format('UPDATE roomsdate rd SET PaidBy=%d WHERE RoomReservation=%d AND (ResFlag NOT IN (''X'',''C''))',
      [RoomReservation, RealRoomReservation]);
  copytoclipboard(sql);
  d.roomerMainDataSet.DoCommand(sql, false);
  RefreshData;
end;

procedure TfrmInvoiceEdit.NullifyGrid;
begin
//  agrLines.UnHideColumnsAll;
  RemoveAllCheckboxes;
  agrLines.RemoveRows(0, agrLines.RowCount);
  agrLines.RowCount := 0;
  agrLines.ColCount := 0;
  agrLines.ClearAll;
end;

/// <summary>
/// If the last row is not empty, add an extra row to the grid. <br/>
/// Initialize the last row of the grid and make it the current row and visible.
///
/// </summary>
procedure TfrmInvoiceEdit.AddEmptyLine(CheckChanged: boolean = True);
begin
  AddAndInitNewRow;

  agrLines.row := agrLines.RowCount - 1;
  agrLines.Col := 0;
  SetCurrentVisible;
  if CheckChanged then
    chkChanged;
end;

/// <summary>
/// If the last row is not empty, add an extra row to the grid. <br/>
/// Initialize the last row of the grid with purchase date = now
/// </summary>
procedure TfrmInvoiceEdit.AddAndInitNewRow;
var
  i: integer;
begin
  if (agrLines.Cells[col_Item, agrLines.RowCount - 1] <> '') then
    agrLines.RowCount := agrLines.RowCount + 1;

  for i := col_Select to col_autogen do
  begin
    agrLines.Objects[i, agrLines.RowCount - 1] := nil;
    agrLines.Cells[i, agrLines.RowCount - 1] := '';
  end;

  agrLines.Objects[cPurchaseDateAsObjectColumn, agrLines.RowCount - 1] := TObject(trunc(now)); // -- PurchaseDate !
//  agrLines.Cells[col_date, agrLines.RowCount - 1] := datetostr(trunc(now));
end;

procedure TfrmInvoiceEdit.UpdateCaptions;
var
  invNo: integer;
begin
  Caption := GetTranslatedText('shUI_InvoiceCaption');

  edResNr.Caption := format('%d / %s', [FReservation, iif(FRoomReservation > 0, IntToStr(FRoomReservation), GetTranslatedText('shUI_OnGroupInvoice'))]);

  agrLines.Col := 0;
  agrLines.row := 1;

  // --
  if FIsCredit then
  begin
    clabInvoice.Caption := GetTranslatedText('shUI_CreditInvoiceCaption');
    pnlHead.Color := $00F5ECFF; // $00EAFFEA
    pnlTotalsAndPayments.Color := $00F5ECFF; // $00EAFFEA

    zCreditType := ctManual;;
    zRefNum := -1;
    invNo := 0;
    zRefNum := invNo;

    zCreditType := ctManual;
    zRefNum := -1;
    zOriginalInvoice := zRefNum;
  end;

  if (agrLines.ColCount >= col_TotalPrice) then
  begin
    agrLines.ColWidths[col_ItemCount] := 100;
    agrLines.ColWidths[col_ItemPrice] := 100;
    agrLines.ColWidths[col_TotalPrice] := 100;
  end;

end;

procedure TfrmInvoiceEdit.agrLinesMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
  X, Y: integer);
var
  ACol: integer;
  ARow: integer;
begin
  // Start dragging when Ctrl is pressed
  // or start edit room prices if on a roomrent or discount item

  agrLines.MouseToCell(X, Y, ACol, ARow);
  if ssCtrl in Shift then
  begin
    agrLines.row := ARow;
    agrLines.Col := ACol;
    if (ARow >= 0) AND (ARow < agrLines.RowCount) then
      agrLines.BeginDrag(True);
  end;
end;

procedure TfrmInvoiceEdit.agrLinesMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
  X, Y: integer);
var
  lCol: integer;
  lRow: integer;
  lInvLine: TInvoiceLine;
  lROomResList: TStringList;
  lGotoRoomRes: integer;
begin
  agrLines.MouseToCell(X, Y, lCol, lRow);
  if Shift = [] then
  begin

    if (lCol < 0) OR (lCol >= agrLines.ColCount) OR (lRow < 0) OR (lRow >= agrLines.RowCount) then
      exit;

    lInvLine := GetInvoiceLineByRow(lRow);
    if not assigned(lInvLine) then
      exit;

    if lInvLine.IsGeneratedLine and (lCol = col_Item) and (lInvLine.ItemKind in [ikRoomRent, ikRoomRentDiscount]) then
    begin
      lGotoRoomRes := -1;
      lROomResList := TStringList.Create;
      try
        if RoomReservation <> 0 then
          lROomResList.Add(inttostr(RoomReservation))
        else // GroupInvoice, collect all roomres in this invoice
        begin
          mRoomRes.DisableControls;
          try
            mRoomRes.first;
            while not mRoomRes.eof do
            begin
              lROomResList.Add(mRoomResroomreservation.asString);
              mRoomRes.Next;
            end;
          finally
            mRoomRes.EnableControls;
          end;
        end;

        if lROomResList.Count > 0 then
        begin
          if assigned(lInvLine.RoomEntity) then
            lGotoRoomRes := lInvLine.RoomEntity.RoomReservation;
          if EditRoomRates(lROomResList, FInvoiceIndex, InvoiceCurrencyCode, lGotoRoomRes) then
          begin
            SaveAnd(false);
            zFirsttime := false;
            RefreshData;
            loadInvoiceToMemtable(d.mInvoicelines_after);
            UpdateCaptions;
          end;
        end;
        exit;
      finally
        lROomResList.Free;
      end;
    end;
  end;
  TAdvStringGrid(Sender).MouseToCell(X, Y, lCol, lRow);
  if lRow > 0 then
  begin
    TAdvStringGrid(Sender).row := lRow;
    TAdvStringGrid(Sender).Col := lCol;
  end;
end;

procedure TfrmInvoiceEdit.agrLinesRowChanging(Sender: TObject; OldRow, NewRow: Integer; var Allow: Boolean);
begin
  UpdateControls(NewRow);
end;

procedure TfrmInvoiceEdit.CheckOrUncheckAll(check: boolean);
var
  i: integer;
begin
  for i := 0 to agrLines.RowCount - 1 do
    if agrLines.HasCheckBox(col_Select, i) then
      agrLines.SetCheckBoxState(col_Select, i, check);
end;

procedure TfrmInvoiceEdit.Exit1Click(Sender: TObject);
begin
  btnExit.Click;
end;

procedure TfrmInvoiceEdit.RemoveInvalidKreditInvoice;
var
  i: integer;
begin
  for i := LOW(REMOVE_REDUNDANT_INVOICES) to HIGH(REMOVE_REDUNDANT_INVOICES) do
    d.roomerMainDataSet.DoCommand(REMOVE_REDUNDANT_INVOICES[i]);
end;

function TfrmInvoiceEdit.CompletePayments(var aInvoiceDate: TDate; var aPayDate: TDate; var aLocation: string): boolean;
var
  lstLocations: TStringList;
  lOpenBalance: TAmount;
begin
  result := false;
  lstLocations := TStringList.Create;
  try

    if FRoomReservation = 0 then
      d.GetReservationLocations(FReservation, lstLocations)
    else
      d.GetRoomReservationLocations(FRoomReservation, lstLocations);

    LoadPayments; // Make sure you have all records, catches problems with mutliple cash invoices being created at once
    lOpenBalance := FInvoiceLinesList.TotalOnInvoice.ToNative - getTotalDownPayments;
    if SelectPaymentTypes(lOpenBalance.Value, edtCustomer.Text, ptInvoice, InvoiceCurrencyCode,
      InvoiceCurrencyRate, FReservation, FRoomreservation, lstLocations, aInvoiceDate, aPayDate, aLocation) then
    begin
      SaveCompletePayments();
      LoadPayments;
      DisplayTotals();
      Result := FInvoiceLinesList.TotalOnInvoice.ToNative = getTotalDownPayments;

      if not Result then
      begin
        // raise Exception.create('Payment need to total to the same amount as the total invoice');
        raise Exception.create
          (GetTranslatedText('shTx_Invoice_PaymentTotalInvoice'));
      end;

    end;

  finally
    lstLocations.Free;
  end;
end;

procedure TfrmInvoiceEdit.AddSaveHeaderToExecPlan(aInvoiceNumber: integer; aExecutionPlan: TRoomerExecutionPlan; const aInvoiceLocation: string);
var
  iMultiplier: integer;
var
  s: string;
  showPackageItems: boolean;
begin
  showPackageItems := False; //chkShowPackageItems.checked;

  iMultiplier := 1;

  if FIsCredit then
    iMultiplier := -1;

  s := format('INSERT INTO invoiceaddressees '#10 +
    '( '#10 +
      'InvoiceIndex, '#10 +
      'Reservation, '#10 +
      'RoomReservation, '#10 +
      'SplitNumber, '#10 +
      'InvoiceNumber, '#10 +
      'Customer, '#10 +
      'Name, '#10 +
      'Address1, '#10 +
      'Address2, '#10 +
      'Zip, '#10 +
      'City, '#10 +
      'Country, '#10 +
      'ExtraText, '#10 +
      'custPID, '#10 +
      'InvoiceType, '#10 +
      'ihCurrency '#10 +         // See Note on end of unit!
  ' )'#10 +
  ' VALUES ( '#10+
      '%d, '#10 +
      '%d, '#10 +
      '%d, '#10 +
      '%d, '#10 +
      '%d, '#10 +
      '%s, '#10 +
      '%s, '#10 +
      '%s, '#10 +
      '%s, '#10 +
      '%s, '#10 +
      '%s, '#10 +
      '%s, '#10 +
      '%s, '#10 +
      '%s, '#10 +
      '%d, '#10 +
      '%s  '#10 +
      ') '#10,
  [ InvoiceIndex,
    FReservation,
    FRoomReservation,
    ord(FInvoiceType),
    aInvoiceNumber,
    _db(edtCustomer.Text),
    _db(edtName.Text),
    _db(edtAddress1.Text),
    _db(edtAddress2.Text),
    _db(edtAddress3.Text),
    _db(edtAddress4.Text),
    _db(zCountry),
    _db(memExtraText.Lines.Text),
    _db(edtPersonalId.Text),
    rgrInvoiceAddressType.itemIndex,
    _db(InvoiceCurrencyCode)
  ]);

  s := s + format(
    'ON DUPLICATE KEY UPDATE '#10 +
    'InvoiceNumber=%d, '#10 +
    'Customer=%s, '#10 +
    'Name=%s, '#10 +
    'Address1=%s, '#10 +
    'Address2=%s, '#10 +
    'Zip=%s, '#10 +
    'City=%s, '#10 +
    'Country=%s, '#10 +
    'ExtraText=%s, '#10 +
    'custPID=%s, '#10 +
    'InvoiceType=%d, '#10 +
    'ihCurrency=%s '
    , [aInvoiceNumber,
      _db(edtCustomer.Text),
      _db(edtName.Text),
      _db(edtAddress1.Text),
      _db(edtAddress2.Text),
      _db(edtAddress3.Text),
      _db(edtAddress4.Text),
      _db(zCountry),
      _db(memExtraText.Lines.Text),
      _db(edtPersonalId.Text),
      rgrInvoiceAddressType.itemIndex,
      _db(InvoiceCurrencyCode)
    ]);

  copytoclipboard(s);
  aExecutionPlan.AddExec(s);

  // --
  // SQL 115 INSERxT InvoiceHeads
  // INS-InvoiceHeads
  s := '';
  s := s + 'INSERT into invoiceheads ' + #10;
  s := s + '(' + #10;
  s := s + '  Reservation ' + #10;
  s := s + ', RoomReservation ' + #10;
  s := s + ', SplitNumber ' + #10;

  s := s + ', InvoiceNumber ' + #10;
  s := s + ', InvoiceDate ' + #10;

  s := s + ', Customer ' + #10;
  s := s + ', Name ' + #10;
  s := s + ', CustPid ' + #10;
  s := s + ', RoomGuest ' + #10;

  s := s + ', Address1 ' + #10;
  s := s + ', Address2 ' + #10;
  s := s + ', Address3 ' + #10;
  s := s + ', Address4 ' + #10;
  s := s + ', Country ' + #10;
  s := s + ', Total ' + #10;
  s := s + ', TotalWOVat ' + #10;
  s := s + ', TotalVat ' + #10;
  s := s + ', TotalBreakfast ' + #10;
  s := s + ', ExtraText ' + #10;
  s := s + ', OriginalInvoice ' + #10;
  s := s + ', Finished ' + #10;
  s := s + ', InvoiceType ' + #10;
  s := s + ', ihStaff ' + #10;
  s := s + ', ihDate ' + #10;
  s := s + ', ihInvoiceDate ' + #10;
  s := s + ', ihConfirmDate ' + #10;
  s := s + ', ihPayDate ' + #10;
  s := s + ', invRefrence ' + #10;
  s := s + ', ihCurrency ' + #10; // **98
  s := s + ', ihCurrencyrate ' + #10; // **98
  s := s + ', showPackage ' + #10; // *99+
  s := s + ', Location ' + #10; // *99+
  s := s + ', TotalStayTax ' + #10; // *99+
  s := s + ', TotalStayTaxNights ' + #10; // *99+

  s := s + ')' + #10;
  s := s + 'Values' + #10;
  s := s + '(' + #10;
  s := s + '  ' + _db(FReservation);
  s := s + ', ' + _db(FRoomReservation);
  s := s + ', ' + _db(ord(FInvoiceType));
  s := s + ', ' + _db(aInvoiceNumber);
  s := s + ', ' + _db(zInvoiceDate, True);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Customer FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    ord(FInvoiceType), InvoiceIndex, _db(edtCustomer.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Name FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    ord(FInvoiceType), InvoiceIndex, _db(edtName.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT CustPid FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    ord(FInvoiceType), InvoiceIndex, _db(edtPersonalId.Text)]);
  s := s + ', ' + _db(edtRoomGuest.Caption);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Address1 FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    ord(FInvoiceType), InvoiceIndex, _db(edtAddress1.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Address2 FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    ord(FInvoiceType), InvoiceIndex, _db(edtAddress2.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Zip FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    ord(FInvoiceType), InvoiceIndex, _db(edtAddress3.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT City FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    ord(FInvoiceType), InvoiceIndex, _db(edtAddress4.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Country FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    ord(FInvoiceType), InvoiceIndex, _db(zCountry)]);
  s := s + ', ' + _CommaToDot(floattostr(iMultiplier * FInvoiceLinesList.TotalOnInvoice.ToNative));
  s := s + ', ' + _CommaToDot(floattostr(iMultiplier * FInvoiceLinesList.TotalOnInvoice.ToNative -
    FInvoiceLinesList.TotalVatOnInvoice.ToNative));
  s := s + ', ' + _CommaToDot(floattostr(iMultiplier * FInvoiceLinesList.TotalVatOnInvoice.ToNative));
  s := s + ', ' + _CommaToDot(floattostr(0.00));
  s := s + ', ' + _db('');
  s := s + ', ' + inttostr(zOriginalInvoice);
  s := s + ', ' + _db(false);
  s := s + ', ' + inttostr(1);
  s := s + ', ' + _db(g.qUser);
  s := s + ', ' + _db(Date, True);
  s := s + ', ' + _db(zInvoiceDate, True);
  s := s + ', ' + _db(zConfirmDate, True);
  s := s + ', ' + _db(zPayDate, True);
  s := s + ', ' + _db(edtInvRefrence.Caption);
  s := s + ', ' + _db(InvoiceCurrencyCode);
  s := s + ', ' + _db(InvoiceCurrencyRate);
  s := s + ', ' + _db(showPackageItems);
  s := s + ', ' + _db(aInvoiceLocation);
  s := s + ', ' + _db(FInvoiceLinesList.TotalCityTaxRevenues);
  s := s + ', ' + _db(FInvoiceLinesList.CityTaxUnitCount);
  s := s + ')' + #10;

  copytoclipboard(s);
  aExecutionPlan.AddExec(s);
end;

function TfrmInvoiceEdit.SaveInvoice(aInvoiceNumber: integer; aSaveType: TInvoiceSaveType; const aInvoiceLocation: string = ''): boolean;
var
  rSet: TRoomerDataset;
  s: string;
  lExecutionPlan: TRoomerExecutionPlan;
  invoiceLine: TInvoiceLine;
  lstActivity: TStringList;

begin

  result := True;

  lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  lstActivity := TStringList.Create;
  try
    if (aSaveType <> stProforma) then
    begin
      DeleteLinesInList(lExecutionPlan);
      AddDeleteFromInvoiceToExecutionPlan(lExecutionPlan);
    end;

    try
      for invoiceLine in FInvoiceLinesList do
      begin
        InsertOrUpdateInvoiceLine(invoiceLine, aInvoiceNumber, lExecutionPlan, aSaveType);
        if aSaveType <> stProforma then
          lstActivity.Add(CreateInvoiceActivityLog(g.qUser, FReservation, FRoomReservation, ord(FInvoiceType), ADD_LINE,
            invoiceLine.Item, invoiceLine.Total, aInvoiceNumber, invoiceLine.Text));
      end;

      AddSaveHeaderToExecPlan(aInvoiceNumber, lExecutionPlan, aInvoiceLocation);

      if (aSaveType = stDefinitive) then
        SetInvoiceNumberOfPayments(aInvoiceNumber, lExecutionPlan)

      else if (aSaveType = stProforma) then
        CopyPaymentsForProforma(aInvoiceNumber, lExecutionPlan);

      if not lExecutionPlan.Execute(ptExec, True, True) then
        raise Exception.Create(lExecutionPlan.ExecException);

      HeaderChanged := false;
      FInvoiceLinesList.ResetChanged;

      if (aSaveType = stDefinitive) then
      begin

        if FIsCredit and (zCreditType = ctReference) then
        begin
          MarkOriginalInvoiceAsCredited(aInvoiceNumber);

          if (MessageDlg(GetTranslatedText('shTx_Invoice_OpenInvoiceAfterPrintCredit'), mtConfirmation, [mbYes, mbNo],
            0) = mrYes) then
            d.copyInvoiceToInvoiceLinesTmp(zRefNum, True);
        end;

        try
          result := True;
          try
            SendInvoicesToFinancePacketThreaded(aInvoiceNumber);
            SendInvoiceToActiveFinanceConnector(aInvoiceNumber);
          except
            on e: Exception do
            begin
              ShowMessage('Ekki tókst ad senda reikning No. ' + inttostr(zInvoiceNumber) +
                ' til bókhaldskerfisins. Vinsamlega sendið reikninginn handvirkt síðar ');
              AddRoomerActivityLog(d.roomerMainDataSet.username, ERROR, e.message,
                format('Exception while sending invoice to booking keeping. Invoice %d, RoomReservation %d, Reservation %d -> %s',
                [aInvoiceNumber, FRoomReservation, FReservation, e.message]));
            end;
          end;
        finally
          for s in lstActivity do
            if s <> '' then
              WriteInvoiceActivityLog(s);
        end;
      end;

      DeletedLines.Clear;
      chkChanged;

    except
      on e: Exception do
      begin
        frmdayNotes.xDoLog('SaveInvoice failed', e.message);
        MessageDlg(format(GetTranslatedText('shTx_Invoice_UnableToSaveInvoiceMessage'), [e.message]), mtError,
          [mbOk], 0);
        result := false;
        raise;
      end;
    end;

  finally
    FreeAndNil(lExecutionPlan);
    lstActivity.Free;
  end;

  if d.mInvoicelines_after.active then
    d.mInvoicelines_after.close;
  d.mInvoicelines_after.Open;

  rSet := CreateNewDataSet;
  try
    Screen.Cursor := crHourGlass;
    try
      s := 'SELECT * FROM invoicelines' + ' where Reservation = %d ' + '   and RoomReservation = %d ' +
        '   and SplitNumber = %d ' + '   and InvoiceNumber = -1 AND InvoiceIndex=%d';

      s := format(s, [FReservation, FRoomReservation, ord(FInvoiceType), FInvoiceIndex]);

      hData.rSet_bySQL(rSet, s);
      if not rSet.eof then
      begin
        d.mInvoicelines_after.LoadFromDataSet(rSet, []);
      end;

    finally
      Screen.Cursor := crDefault;
    end;
  finally
    FreeAndNil(rSet);
  end;
  loadInvoiceToMemtable(d.mInvoicelines_after);
  d.addInvoiceLinesTmp(agrLines.RowCount, FReservation);
end;

procedure TfrmInvoiceEdit.SaveInvoicelineVisibility(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
var
  s: string;
  lResnr: integer;
  lRoomResNr: integer;
begin
  // Store set visiblity in invoicelines_visiblity
  // Notice that this only has to be done for generated lines and provisionally invoices as otherwise
  // the visiblity is stored in the invoicelines.VisibleOnInvoice field

  // When ShowRentPerDay os true then the setting will be stored per separate day, otherwise
  // the setting will be for the whole roomreservation, leaving the date field null
  if not aInvoiceLine.CanBeHiddenFromInvoice then
    Exit;

  lresNr := aInvoiceLine.ParentReservation;
  lRoomResNr := aInvoiceLine.ParentRoomReservation;

  // fallback
  if lresNr = -1 then
    lResNr := FReservation;
  if lRoomResNr = -1 then
    lRoomResNr := FRoomReservation;

  // construct SQL
  s := '';
  s := s + 'INSERT into invoicelines_visibility '#10;
  s := s + ' ('#10;
  s := s + '  reservation '#10;
  s := s + ' ,roomreservation '#10;
  s := s + ' ,invoiceindex '#10;
  s := s + ' ,adate '#10;
  s := s + ' ,item '#10;
  s := s + ' ,visible '#10;
  s := s + ' '#10;
  s := s + ' ) VALUES ('#10;
  s := s + '  ' +_db(lResNr) + #10;
  s := s + ' ,' + _db(lRoomResNr) + #10;
  s := s + ' ,' + _db(FInvoiceIndex)+#10;
  s := s + ' ,' + iif( ShowRentPerDay, _db(aInvoiceLine.PurchaseDate), 'NULL')+#10;
  s := s + ' ,' + _db(aInvoiceLine.Item)+#10;
  s := s + ' ,' + _db(aInvoiceLine.IsVisibleOnInvoice)+#10;
  s := s + ') '#10;
  s := s + ' ON DUPLICATE KEY '#10;
  s := s + ' UPDATE visible = '+ _db(aInvoiceLine.IsVisibleOnInvoice)+#10;

  copyToClipboard(s);
  aExecPLan.AddExec(s);
end;

procedure TfrmInvoiceEdit.RemoveInvoicelineVisibilityRecord(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
var
  s: string;
begin
  if not aInvoiceLine.CanBeHiddenFromInvoice then
    Exit;

  // TODO: Only store when setting is different then the default

  // construct SQL
  s := '';
  s := s + 'DELETE from invoicelines_visibility '#10;
  s := s + ' WHERE '#10;
  s := s + ' reservation = ' +_db(aInvoiceLine.ParentReservation) + #10;
  s := s + ' and roomreservation=' + _db(aInvoiceLine.ParentRoomReservation) + #10;
  s := s + ' and invoiceindex=' + _db(FInvoiceIndex)+#10;
  if ShowRentPerDay then
    s := s + ' and adate=' + _db(aInvoiceLine.PurchaseDate)+#10;
  s := s + ' and item=' + _db(aInvoiceLine.Item)+#10;

  copyToClipboard(s);
  aExecPLan.AddExec(s);
end;

procedure TfrmInvoiceEdit.InsertOrUpdateInvoiceLine(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer;
  aExecPlan: TRoomerExecutionPlan; aSaveType: TInvoiceSaveType);
var
  lItemTypeInfo: TItemTypeInfo;
  fItemTotal: Double;
  fItemTotalWOVat: Double;
  iNights: integer;
  AYear, aMonth, ADay: Word;
  sAccountKey: string;
  s: string;
  iCreditInvoiceMultiplier: integer;
begin
  if (aInvoiceLine.Item = '') and (aInvoiceLine.Text = '') then
    exit;

  // Already actual invoiceline record, visibility is stored there
  if (aSaveType = stProvisionally) and (aInvoiceLine.LineId <= 0) then
    SaveInvoicelineVisibility(aInvoiceLine, aInvoiceNumber, aExecPlan);

  // Dont add automatically generated lines when invoice is not definitive
  if (aInvoiceLine.IsGeneratedLine) and (aInvoiceNumber <= 0) then
    exit;

  iCreditInvoiceMultiplier := 1;
  if FIsCredit then
    iCreditInvoiceMultiplier := -1;

  lItemTypeInfo := d.Item_Get_ItemTypeInfo(aInvoiceLine.Item, aInvoiceLine.Source);

  iNights := 0;
  // RoomRentItem
  if aInvoiceLine.IsGeneratedLine or (aInvoiceLine.ItemKind in [ikRoomRent, ikRoomRentDiscount]) then
  begin
    aInvoiceLine.PurchaseDate := now();
    if aInvoiceLine.RoomEntity <> nil then
      iNights := aInvoiceLine.RoomEntity.NumberOfNights;
  end;

  fItemTotal := aInvoiceLine.AmountOnInvoice.ToNative;
  fItemTotalWOVat := fItemTotal - aInvoiceLine.VATOnInvoice.ToNative;

  decodedate(aInvoiceLine.PurchaseDate, AYear, aMonth, ADay);

  sAccountKey := d.Item_Get_AccountKey(aInvoiceLine.Item);

  // force new invoicelines records when creating a proforma
  if (aInvoiceLine.LineId < 1) or (aSaveType = stProforma) then
  begin

    s := '';
    s := s + 'INSERT into invoicelines' + #10;
    s := s + '(' + #10;
    s := s + '  ' + 'Reservation ' + #10;
    s := s + ', ' + 'AutoGen ' + #10;
    s := s + ', ' + 'RoomReservation ' + #10;
    s := s + ', ' + 'SplitNumber ' + #10;
    s := s + ', ' + 'ItemNumber ' + #10;
    s := s + ', ' + 'PurchaseDate ' + #10;
    s := s + ', ' + 'InvoiceNumber ' + #10;
    s := s + ', ' + 'ItemId ' + #10;
    s := s + ', ' + 'Number ' + #10;
    s := s + ', ' + 'Description ' + #10;
    s := s + ', ' + 'Price ' + #10;
    s := s + ', ' + 'VATType ' + #10;
    s := s + ', ' + 'Total ' + #10;
    s := s + ', ' + 'TotalWOVat ' + #10;
    s := s + ', ' + 'VAT ' + #10;
    s := s + ', ' + 'CurrencyRate ' + #10;
    s := s + ', ' + 'Currency ' + #10;
    s := s + ', ' + 'Persons ' + #10;
    s := s + ', ' + 'Nights ' + #10;
    s := s + ', ' + 'BreakfastPrice ' + #10;
    s := s + ', ' + 'AutoGenerated ' + #10;
    s := s + ', ' + 'AYear ' + #10;
    s := s + ', ' + 'AMon ' + #10;
    s := s + ', ' + 'ADay ' + #10;
    s := s + ', ' + 'ilAccountKey ' + #10;
    s := s + ', ' + 'importRefrence ' + #10;
    s := s + ', ' + 'importSource ' + #10;
    s := s + ', ' + 'isPackage ' + #10;
    s := s + ', ' + 'confirmDate ' + #10;
    s := s + ', ' + 'confirmAmount ' + #10;
    s := s + ', ' + 'RoomReservationAlias ' + #10;
    s := s + ', ' + 'InvoiceIndex ' + #10;
    s := s + ', ' + 'staffCreated ' + #10;
    s := s + ', ' + 'VisibleOnInvoice ' + #10;
    s := s + ', ' + 'Revenue' + #10;
    s := s + ')' + #10;
    s := s + 'Values' + #10;
    s := s + '(' + #10;
    s := s + '  ' + _db(FReservation);
    s := s + ', ' + _db(aInvoiceLine.AutoGen);
    s := s + ', ' + _db(FRoomReservation);
    s := s + ', ' + _db(ord(FInvoiceType));
    s := s + ', ' + _db(aInvoiceLine.InvoiceLineIndex);
    s := s + ', ' + _db(aInvoiceLine.PurchaseDate);
    s := s + ', ' + _db(aInvoiceNumber);
    s := s + ', ' + _db(aInvoiceLine.Item);
    s := s + ', ' + _db(aInvoiceLine.Number); // -96ath
    s := s + ', ' + _db(aInvoiceLine.Text);

    s := s + ', ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.PriceOnInvoice.ToNative);

    s := s + ', ' + _db(lItemTypeInfo.VATCode);
    s := s + ', ' + _db(iCreditInvoiceMultiplier * fItemTotal);
    s := s + ', ' + _db(iCreditInvoiceMultiplier * fItemTotalWOVat);
    s := s + ', ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.VATOnInvoice.ToNative);

    // If not storing provisionally, all records should set payment-currency = Currency of invoice
    if (aSaveType = stProvisionally) then
    begin
      s := s + ', ' + _db(GetRate(aInvoiceLine.Currency));
      s := s + ', ' + _db(aInvoiceLine.Currency);
    end
    else
    begin
      s := s + ', ' + _db(InvoiceCurrencyRate);
      s := s + ', ' + _db(InvoiceCurrencyCode);
    end;
    s := s + ', ' + _db(aInvoiceLine.noGuests);
    s := s + ', ' + _db(iNights);

    s := s + ', ' + _db(0);
    s := s + ', ' + _db(false);

    s := s + ', ' + _db(AYear);
    s := s + ', ' + _db(aMonth);
    s := s + ', ' + _db(ADay);

    s := s + ', ' + _db(sAccountKey);
    s := s + ', ' + _db(aInvoiceLine.Reference);
    s := s + ', ' + _db(aInvoiceLine.Source);
    s := s + ', ' + _db(aInvoiceLine.isPackage);
    s := s + ', ' + _db(aInvoiceLine.ConfirmDate);
    s := s + ', ' + _db(aInvoiceLine.ConfirmAmount);
    s := s + ', ' + _db(aInvoiceLine.Roomreservation);
    s := s + ', ' + _db(FInvoiceIndex);
    s := s + ', ' + _db(d.roomerMainDataSet.username);
    s := s + ', ' + _db(aInvoiceLine.IsVisibleOnInvoice);
    s := s + ', ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.TotalRevenue.ToNative);

    s := s + ')' + #10;
  end
  else
  begin
    s := 'UPDATE invoicelines' + ' Set ItemNumber= ' + _db(aInvoiceLine.InvoiceLineIndex) + ' , InvoiceNumber= ' +
      _db(aInvoiceNumber) + ' , Description= ' + _db(aInvoiceLine.Text) + ' , Number= ' + _db(aInvoiceLine.Number) +
      ' , Price= ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.Price.ToNative) + ' , Total= ' +
      _db(iCreditInvoiceMultiplier * fItemTotal) + ' , TotalWOVat= ' + _db(iCreditInvoiceMultiplier * fItemTotalWOVat) +
      ' , VAT= ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.VATOnInvoice.ToNative);

    // If not storing provisionally, all records should set payment-currency = Currency of invoice
    if (aSaveType = stProvisionally) then
    begin
      s := s + ' , CurrencyRate= ' + _db(GetRate(aInvoiceLine.Currency));
      s := s + ' , Currency= ' + _db(aInvoiceLine.Currency);
    end
    else
    begin
      s := s + ' , CurrencyRate= ' + _db(InvoiceCurrencyRate);
      s := s + ' , Currency= ' + _db(InvoiceCurrencyCode);
    end;

    s := s + ' , Persons= ' + _db(aInvoiceLine.noGuests) + ' , Nights= ' + _db(iNights) + ' , ilAccountKey= ' +
      _db(sAccountKey) + ' , InvoiceIndex= ' + _db(FInvoiceIndex) + ' , staffLastEdit= ' +
      _db(d.roomerMainDataSet.username) + ' , VisibleOnInvoice = ' + _db(aInvoiceLine.IsVisibleOnInvoice) +
      ' , Revenue = ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.TotalRevenue.ToNative) + ' WHERE id=' +
      _db(aInvoiceLine.LineId);
  end;
  aExecPlan.AddExec(s);
  copytoclipboard(s);

  if (aSaveType = stDefinitive) then
  begin
    if aInvoiceLine.IsGeneratedLine and (aInvoiceLine.ItemKind = ikRoomRent) then
      MarkRoomRentAsPaid(aInvoiceLine, aInvoiceNumber, aExecPlan);
    RemoveInvoicelineVisibilityRecord(aInvoiceLine, aInvoiceNumber, aExecPlan);
  end;
end;

function TfrmInvoiceEdit.InvoiceCurrencyRate: double;
begin
  if fraInvoiceCurrency.IsValid then
    result := fraInvoiceCurrency.CurrencyRate
  else
    result := 1.0;
end;

procedure TfrmInvoiceEdit.MarkRoomRentAsPaid(aInvLine: TInvoiceLine; aInvoiceNumber: integer;
  aExecPlan: TRoomerExecutionPlan);
var
  s: string;
begin
  s := s + 'UPDATE roomreservations ' + #10;
  s := s + 'SET' + #10;
  s := s + '   RoomRentPaid1 = ' + _db(aInvLine.AmountOnInvoice) + ' '#10;
  s := s + '  ,RoomRentPaymentInvoice = ' + _db(aInvoiceNumber) + #10;
  s := s + 'WHERE RoomReservation = ' + _db(aInvLine.RoomEntity.RoomReservation) + #10;
  aExecPlan.AddExec(s);

  s := '';
  s := s + ' UPDATE `roomsdate` '#10;
  s := s + '  SET '#10;
  s := s + '    Paid = 1 '#10;
  s := s + '  , invoicenumber=' + _db(aInvoiceNumber) + ' '#10;
  s := s + ' WHERE '#10;
  s := s + '    (Roomreservation = ' + _db(aInvLine.RoomEntity.RoomReservation) + #10;
  s := s + '    AND (Paid = 0) '#10;
  s := s + '    AND (ResFlag not in (' + _db(STATUS_DELETED) + ', ' + _db(STATUS_CANCELLED) + '))) '#10;
  aExecPlan.AddExec(s);

end;

procedure TfrmInvoiceEdit.SaveCompletePayments();
var
  lPaymentType: string;
  lPaymentValue: Double;
  lPaymentDesc: string;
  i: integer;
  lYear, lMonth, lDay: Word;
  s: string;
  lExecPlan: TRoomerExecutionPlan;
begin

  lExecPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    for i := 0 to stlPaySelections.Count - 1 do
    begin

      lPaymentType := _strTokenAt(stlPaySelections[i], '|', 0);
      lPaymentValue := IIF(FIsCredit, -1, 1) * _StrToFloat(_strTokenAt(stlPaySelections[i], '|', 1));
      lPaymentDesc := _strTokenAt(stlPaySelections[i], '|', 2) + ' [' + lPaymentType + ']';

      decodedate(zInvoiceDate, lYear, lMonth, lDay);

      s := '';
      s := s + 'INSERT INTO payments' + #10;
      s := s + '(' + #10;
      s := s + '  Reservation' + '' + #10;
      s := s + ', RoomReservation' + #10;
      s := s + ', Person' + #10;

      s := s + ', Customer' + #10;
      s := s + ', AutoGen' + #10;
      s := s + ', InvoiceNumber' + #10;
      s := s + ', PayDate' + #10;

      s := s + ', PayType' + #10;
      s := s + ', Amount' + #10;
      s := s + ', Description' + #10;

      s := s + ', CurrencyRate' + #10;
      s := s + ', Currency' + #10;

      s := s + ', TypeIndex' + #10;

      s := s + ', AYear' + #10;
      s := s + ', AMon' + #10;
      s := s + ', ADay' + #10;
      s := s + ', staff' + #10;
      s := s + ', InvoiceIndex' + #10;

      s := s + ')' + #10;
      s := s + 'Values' + #10;
      s := s + '(' + #10;

      s := s + '  ' + inttostr(FReservation);
      s := s + ', ' + inttostr(FRoomReservation);
      s := s + ', ' + _db(ord(FInvoiceType));

      s := s + ', ' + _db(edtCustomer.Text);

      s := s + ', ' + _db(_GetCurrentTick);

      s := s + ', ' + inttostr(-1);
      s := s + ', ' + _db(zInvoiceDate, True);

    s := s + ', ' + _db(lPaymentType);
    s := s + ', ' + _db(lPaymentValue);
    s := s + ', ' + _db(lPaymentDesc);
    s := s + ', ' + _db(InvoiceCurrencyRate);
    s := s + ', ' + _db(InvoiceCurrencyCode);
    s := s + ', 0';

      s := s + ', ' + inttostr(lYear);
      s := s + ', ' + inttostr(lMonth);
      s := s + ', ' + inttostr(lDay);
      s := s + ', ' + _db(d.roomerMainDataSet.username);
      s := s + ', ' + _db(FInvoiceIndex);
      s := s + ')';

      lExecPlan.AddExec(s);

    end;

    lExecPlan.Execute(ptExec,True, True);

  finally
    lExecplan.Free;
  end;

end;

procedure TfrmInvoiceEdit.SetInvoiceNumberOfPayments(aInvoiceNumber: integer;
  lExecutionPlan: TRoomerExecutionPlan);
var
  s: string;
begin
  s := '';
  s := s + ' UPDATE payments '#10;
  s := s + '  SET '#10;
  s := s + ' invoicenumber = ' + _db(aInvoiceNumber) + ' '#10;
  s := s + ' WHERE (reservation = %d) and (Roomreservation = %d) and (Invoicenumber=-1) and (InvoiceIndex=%d); ';
  s := format(s, [FReservation, FRoomReservation, FInvoiceIndex]);
  lExecutionPlan.AddExec(s);
end;

procedure TfrmInvoiceEdit.edtCustomerChange(Sender: TObject);
var
  customer: string;

begin
  customer := trim(edtCustomer.Text);
  try
    if NOT glb.LocateSpecificRecordAndGetValue('customers', 'Customer', customer, 'StayTaxIncluted', zStayTaxIncluded)
    then
      zStayTaxIncluded := ctrlGetBoolean('StayTaxIncluted');
  except
    zStayTaxIncluded := ctrlGetBoolean('StayTaxIncluted');
  end;
end;

procedure TfrmInvoiceEdit.edtCustomerDblClick(Sender: TObject);
var
  CustomerHolder: recCustomerHolder;
  CustomerHolderEX: recCustomerHolderEX;
begin
  CustomerHolder.customer := edtCustomer.Text;
  if openCustomers(actLookup, True, CustomerHolder) then
  begin
    edtCustomer.Text := CustomerHolder.customer;
    CustomerHolderEX := hData.Customer_GetHolder(CustomerHolder.customer);
    edtName.Text := InvoiceName(0, CustomerHolderEX.DisplayName, CustomerHolderEX.CustomerName);
    edtPersonalId.Text := CustomerHolderEX.PID;
    edtAddress1.Text := CustomerHolderEX.Address1;
    edtAddress2.Text := CustomerHolderEX.Address2;
    edtAddress3.Text := CustomerHolderEX.Address3;
    edtAddress4.Text := CustomerHolderEX.Address4;
    zCountry := CustomerHolderEX.Country;
    HeaderChanged := True;
    UpdateTaxinvoiceLinesForAllRooms;
  end;
end;

procedure TfrmInvoiceEdit.edtPersonalIdChange(Sender: TObject);
begin
  HeaderChanged := True;
end;

procedure TfrmInvoiceEdit.agrLinesGetAlignment(Sender: TObject; ARow, ACol: integer; var HAlign: TAlignment;
  var VAlign: TVAlignment);
begin
  case ACol of
    col_Item:
      HAlign := taLeftJustify;
    col_Description:
      HAlign := taLeftJustify;
    col_ItemCount:
      HAlign := taRightJustify;
    col_ItemPrice:
      HAlign := taRightJustify;
    col_TotalPrice:
      HAlign := taRightJustify;
    col_System:
      HAlign := taLeftJustify;
    col_date:
      HAlign := taLeftJustify;
    col_Reference:
      HAlign := taLeftJustify;
    col_Source:
      HAlign := taCenter;
    col_isPackage:
      HAlign := taLeftJustify;
    col_NoGuests:
      HAlign := taLeftJustify;
    col_confirmdate:
      HAlign := taLeftJustify;
    col_confirmAmount:
      HAlign := taRightJustify;
    col_VisibleOnInvoice:
      HAlign := taCenter;
    col_TotalOnInvoice:
      HAlign := taRightJustify;
  end;
end;

procedure TfrmInvoiceEdit.agrLinesGetCellColor(Sender: TObject; ARow, ACol: integer; AState: TGridDrawState;
  ABrush: TBrush; AFont: TFont);
begin
  if ARow = 0 then
    AFont.Color := frmMain.sSkinManager1.GetGlobalFontColor
  else if (gdSelected IN AState) OR (gdRowSelected IN AState) then
  begin
    ABrush.Color := frmMain.sSkinManager1.GetActiveEditFontColor; // reversed!
    AFont.Color := frmMain.sSkinManager1.GetActiveEditColor;
  end
  else
  begin
    ABrush.Color := frmMain.sSkinManager1.GetActiveEditColor;
    AFont.Color := frmMain.sSkinManager1.GetActiveEditFontColor;
  end;

end;

procedure TfrmInvoiceEdit.agrLinesGetDisplText(Sender: TObject; ACol, ARow: integer; var Value: string);
begin
  if (ARow > 0) and assigned(GetInvoiceLineByRow(ARow)) then
    if Value = trim(_floattostr(0, vWidth, vDec)) then
      Value := ''
end;

procedure TfrmInvoiceEdit.agrLinesGetEditText(Sender: TObject; ACol, ARow: integer; var Value: string);
var
  lInvLine: TInvoiceLine;
begin
  lInvLine := GetInvoiceLineByRow(ARow);
  if (ACol = col_ItemPrice) and assigned(lInvLine) then
    Value := RoomerCurrencyManager[lInvLine.Currency].FormattedValue(lInvLine.Price, false);
  FCellValueBeforeEdit := agrLines.Cells[ACol, ARow];
  FCellDoubleBeforeEdit := StrToFloatDef(FCellValueBeforeEdit, 0);
end;

procedure TfrmInvoiceEdit.agrLinesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_RETURN then
  begin
    if agrLines.row < agrLines.RowCount - 1 then
      agrLines.row := agrLines.row + 1;
  end
end;

procedure TfrmInvoiceEdit.itemLookup;
var
  Currency: string;

  theData: TrecItemHolderList;
  rec: TrecItemHolder;

  VATCode, ItemType, lOrigItem: string;
  i, lJumpToRow: integer;
  lInvoiceLine: TInvoiceLine;
begin
  lJumpToRow := -1;
  Currency := '';

  lInvoiceLine := GetInvoiceLineByRow(agrLines.row);
  if assigned(lInvoiceLine) then
    lOrigItem := lInvoiceLine.Item
  else
    lOrigItem := '';

  theData := TrecItemHolderList.Create(True);
  try
    rec := TrecItemHolder.Create;
    rec.recHolder.Item := lOrigItem;
    theData.Add(rec);
    if openMultipleItems(actLookup, True, theData, [TShowItemOption.HideStockItems, TShowItemOption.HideSystemItems])
      AND (theData.Count > 0) then
    begin
      if theData[0].recHolder.Item <> lOrigItem then // New item
      begin
        for i := 0 to theData.Count - 1 do
        begin
          if glb.LocateSpecificRecordAndGetValue('items', 'Item', theData[i].recHolder.Item, 'Itemtype', ItemType) AND
            glb.LocateSpecificRecordAndGetValue('itemtypes', 'ItemType', ItemType, 'VATCode', VATCode) and
            glb.LocateSpecificRecord('vatcodes', 'VATCode', VATCode) then
            with theData[i].recHolder do
            begin
              if NOT CheckExtraWithdrawalAllowed(Price) then
                exit;

              lInvoiceLine := AddLine(0, nil, Item, Description, 1, Price, g.qNativeCurrency, VATCode, now(), false, '',
                '', false, 0, 0, 0, 0, '');

              if lJumpToRow = -1 then
                lJumpToRow := lInvoiceLine.InvoiceLineIndex;
            end // if .. with
          else
          begin
            MessageDlg(format(GetTranslatedText('shTx_uInvoice_ItemTypeWithIncorrectVAT'), [ItemType, VATCode]),
              mtError, [mbOk], 0);
          end;
        end; // for

        UpdateGrid;
      end;

      agrLines.Col := col_ItemCount;
    end;
  finally
    theData.Free;
  end;
  if lJumpToRow <> -1 then
    agrLines.row := lJumpToRow;
  UpdateControls;
  Application.ProcessMessages;
  agrLines.SetFocus;
end;

procedure TfrmInvoiceEdit.agrLinesCanEditCell(Sender: TObject; ARow, ACol: integer; var CanEdit: boolean);
var
  lInvoiceLine: TInvoiceLine;
begin
  lInvoiceLine := GetInvoiceLineByRow(ARow);
  if assigned(lInvoiceLine) then
  begin
    if (ACol = col_VisibleOnInvoice) and agrLines.HasCheckBox(ACol, ARow) and lInvoiceLine.CanBeHiddenFromInvoice then
    begin
      CanEdit := True;
      exit;
    end;

    if (lInvoiceLine.ItemKind = ikRoomRent) and (aCol in [col_Select]) then
    begin
      CanEdit := True;
      exit;
    end;

    if lInvoiceLine.IsGeneratedLine and not(ACol in [col_Description]) then
    begin
      CanEdit := false;
      exit;
    end;
  end;

  if (agrLines.Cells[col_Item, ARow] = '') and not(ACol in [col_Description]) then
  begin
    CanEdit := false;
    exit;
  end;

  CanEdit := (NOT(ACol IN [col_Item, col_TotalPrice, col_System, col_date, col_Reference, col_Source, col_isPackage,
                            col_NoGuests, col_confirmdate, col_confirmAmount, col_TotalOnInvoice]))
          AND ((TaxTypes.IndexOf(agrLines.Cells[col_Item, ARow]) < 0) OR (NOT isSystemLine(ARow)))  // not a GENERATED tax line
    AND not(isSystemLine(ARow) and (agrLines.Cells[col_Item, ARow] = g.qBreakFastItem)) // generated breakfast lines
    AND ((glb.GetNumberBaseOfItem(agrLines.Cells[col_Item, ARow]) = INB_USER_EDIT) OR
    (ACol IN [col_ItemPrice, col_Description]));

end;

function TfrmInvoiceEdit.CheckExtraWithdrawalAllowed(aExtraAmount: Double): boolean;
begin
  result := True;
  if (FRoomReservation > 0) AND (NOT d.roomerMainDataSet.SystemIsRoomWithdrawalAllowed(FRoomReservation, aExtraAmount))
  then
  begin
    MessageDlg(GetTranslatedText('shUI_AmountOverAllowedWithdrawalLimit'), mtWarning, [mbOk], 0);
    result := false;
  end;
end;

procedure TfrmInvoiceEdit.WndProc(var message: TMessage);
begin
  if Message.msg = WM_REDRAW_LINE then
  begin
    UpdateLine(Message.LParam);
    DisplayTotals;
  end
  else
    inherited WndProc(message);
end;

function TfrmInvoiceEdit.LocateDate(recordSet: TRoomerDataset; field: String; Value: TDate): boolean;
begin
  // work around for Multiple Step errors in ADODataset when using normal locate()
  result := false;
  recordSet.first;
  while NOT recordSet.eof do
  begin
    if recordSet[field] = _db(Value, false) then
    begin
      result := True;
      break;
    end;
    recordSet.Next;
  end;
end;

procedure TfrmInvoiceEdit.GenerateRoomRentLinesPerRoom();
var
  NativeAmount: Double;
  Arrival: TDate;
  infantCount: Integer;
  Rate: Double;
  AvrageDiscountPerc: Double;
  isPackage: Boolean;
  TotalRate: Double;
  DiscountAmount: Double;
  Room: string;
  allIsPercentage: Boolean;
  isPaid: Boolean;
  showPackage: Boolean;
  lRoomRateCurrency: string;
  GuestsInRoomRes: Integer;
  lRoomReservation: Integer;
  rSet: TRoomerDataSet;
  UnpaidDays: Integer;
  AverageRate: Double;
  RoomDescription: string;
  lExecutionPlan: TRoomerExecutionPlan;
  s: string;
  isGroupAccount: Boolean;
  sText:
  string; iLastRoomRes:
  Integer; package:
  string; isPercentage:
  Boolean; sql:
  string; ChildrenCount:
  Integer; list:
  TStringList; dayCount:
  Integer; DiscountText:
  string; reservation:
  Integer; ShowDiscount:
  Boolean; RoomTypeDescription:
  string; i: Integer;
  RateCount: Integer;
  GuestName: string;
  CurrencyRate: Double;
  tmp: string;
  Discount: Double;
  AverageDiscountAmount: Double;
  GuestNights: Integer;
  rentAmount: Double;
  lRoomText: string;
  RoomRentPaidDays: Double;
  Index: Integer;
  PriceCode: string;
  RoomType: string;
  RateDate: TDateTime;
  zRoomRSet: TRoomerDataSet;
  status: string;
  _s: string;
  iTotalResDays: Integer;
  NumberGuests: Integer;
  TotalDiscountAmount: Double;
  Departure: TDate;
  Local_i: Integer;
  Local_i1: Integer;

begin

  zRoomRSet := CreateNewDataSet;
  lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    sql := Select_Invoice_LoadInvoice3_WithInvoiceIndex(FRoomReservation, FReservation, FInvoiceIndex, edtCustomer.Text, false);
    if FRoomReservation = 0 then
      // GroupInvoice
      sql := format(sql, [FReservation])
    else
      sql := format(sql, [FRoomReservation, FRoomReservation]);
    if zRoomRSet.active then
      zRoomRSet.close;
    copytoclipboard(sql);
    hData.rSet_bySQL(zRoomRSet, sql);
    iLastRoomRes := -1;
    RoomRentPaidDays := 0;
    zRoomRSet.first;

    if not zRoomRSet.eof then
    begin
      zEmailAddress := '';
      list := TStringList.create;
      try
        uUtils.SplitString(trim(zRoomRSet.FieldByName('ContactEmail').asString), list, ';');
        for Local_i := 0 to list.Count - 1 do
          if list[Local_i] <> '' then
          begin
            if zEmailAddress = '' then
              zEmailAddress := QuotedStr(list[Local_i])
            else
              zEmailAddress := zEmailAddress + ';' + QuotedStr(list[Local_i]);
          end;
      finally
        FreeAndNil(list);
      end;
      if trim(zRoomRSet.FieldByName('GuestEmail').asString) <> '' then
      begin
        if zEmailAddress = '' then
        begin
          zEmailAddress := QuotedStr(trim(zRoomRSet.FieldByName('GuestEmail').asString));
        end
        else
        begin
          zEmailAddress := zEmailAddress + ';' + QuotedStr(trim(zRoomRSet.FieldByName('GuestEmail').asString));
        end;
      end;
    end;
    // **
    while not zRoomRSet.eof do
    begin
      lRoomReservation := zRoomRSet.FieldByName('Roomreservation').asinteger;
      s := 'SELECT '#10'';
      s := s + 'rd.ADate, '#10'';
      s := s + 'rd.Room, '#10'';
      s := s + 'rd.RoomReservation, '#10'';
      s := s + 'rd.Reservation, '#10'';
      s := s + 'rd.PriceCode, '#10'';
      s := s + 'rd.RoomRate, '#10'';
      s := s + 'rd.Currency, '#10'';
      s := s + 'rd.Discount, '#10'';
      s := s + 'rd.isPercentage, '#10'';
      s := s + 'rd.showDiscount, '#10'';
      s := s + 'rd.Paid '#10'';
      s := s + ',IF(ISNULL((SELECT name FROM persons pe WHERE pe.MainName AND pe.roomreservation = rd.roomreservation LIMIT 1)), '#10'';
      s := s + '   (SELECT name FROM persons pe WHERE pe.roomreservation = rd.roomreservation LIMIT 1), '#10'';
      s := s + '   (SELECT name FROM persons pe WHERE pe.MainName AND pe.roomreservation = rd.roomreservation LIMIT 1)) AS guestName '#10'';
      s := s + 'FROM roomsdate rd '#10'';
      s := s + 'WHERE '#10'';
      s := s + '(rd.roomreservation = %d) AND (rd.paid=0) AND rd.ResFlag NOT IN (''X'', ''C'') '#10'';
      s := s + 'ORDER BY '#10'';
      s := s + '  ADate '#10'';
      s := format(s, [lRoomReservation]);
      copytoclipboard(s);

      lExecutionPlan.AddQuery(s);

      zRoomRSet.Next;
    end;

    if lExecutionPlan.Execute(ptQuery) then
    begin
      zRoomRSet.first;
      index := 0;
      while not zRoomRSet.eof do
      begin
        lRoomReservation := zRoomRSet.FieldByName('Roomreservation').asinteger;
        isGroupAccount := zRoomRSet['GroupAccount'];
        status := zRoomRSet.FieldByName('status').asString;
        Room := zRoomRSet.FieldByName('room').asString;
        RoomType := zRoomRSet.FieldByName('RoomType').asString;
        package := zRoomRSet.FieldByName('package').asString;
        NumberGuests := zRoomRSet.FieldByName('numGuests').asinteger;
        RoomDescription := zRoomRSet.FieldByName('RoomDescription').asString;
        RoomTypeDescription := zRoomRSet.FieldByName('RoomTypeDescription').asString;
        Arrival := zRoomRSet.FieldByName('rrArrival').asdateTime;
        Departure := zRoomRSet.FieldByName('rrDeparture').asdateTime;
        ChildrenCount := zRoomRSet.FieldByName('numChildren').asinteger;
        infantCount := zRoomRSet.FieldByName('numInfants').asinteger;
        PriceCode := zRoomRSet.FieldByName('PriceType').asString;
        AverageRate := zRoomRSet.FieldByName('AverageRate').AsFloat;
        RateCount := zRoomRSet.FieldByName('rateCount').asinteger;
        AvrageDiscountPerc := zRoomRSet.FieldByName('discount').AsFloat;
        mRoomRes.append;
        mRoomRes.FieldByName('RoomReservation').asinteger := lRoomReservation;
        mRoomRes.FieldByName('room').asString := Room;
        mRoomRes.FieldByName('RoomType').asString := RoomType;
        mRoomRes.FieldByName('Package').asString := package;
        mRoomRes.FieldByName('Guests').asinteger := NumberGuests;
        mRoomRes.FieldByName('AvragePrice').asfloat := AverageRate;
        mRoomRes.FieldByName('RateCount').asfloat := RateCount;
        mRoomRes.FieldByName('RoomDescription').asString := RoomDescription;
        mRoomRes.FieldByName('RoomTypeDescription').asString := RoomTypeDescription;
        mRoomRes.FieldByName('arrival').asdateTime := Arrival;
        mRoomRes.FieldByName('departure').asdateTime := Departure;
        mRoomRes.FieldByName('ChildrenCount').asinteger := ChildrenCount;
        mRoomRes.FieldByName('InfantCount').asinteger := infantCount;
        mRoomRes.FieldByName('PriceCode').asString := PriceCode;
        mRoomRes.FieldByName('AvrageDiscount').asfloat := AvrageDiscountPerc;
        mRoomRes.FieldByName('InvoiceIndex').asinteger := FInvoiceIndex;
        mRoomRes.FieldByName('GroupAccount').asBoolean := zRoomRSet['GroupAccount'];

        dayCount := trunc(Departure) - trunc(Arrival);
        RateDate := Arrival;
        TotalDiscountAmount := 0;
        TotalRate := 0;
        UnpaidDays := 0;
        allIsPercentage := true;

        rSet := lExecutionPlan.Results[index];
        rSet.first;
        if not rSet.eof then
        begin
          GuestName := rSet.FieldByName('guestName').asString;
          if mRoomRes.State in [dsEdit, dsInsert] then
          begin
            mRoomRes.FieldByName('Guests').asinteger := NumberGuests;
            mRoomRes.FieldByName('GuestName').asString := GuestName;
            mRoomRes.post;
          end;
          for Local_i1 := 1 to dayCount do
          begin
            DiscountText := '';
            if LocateDate( rSet, 'aDate', RateDate) then
            begin
              reservation := rSet.FieldByName('Reservation').asinteger;
              Room := rSet.FieldByName('Room').asString;
              PriceCode := rSet.FieldByName('PriceCode').asString;
              Rate := rSet.FieldByName('RoomRate').AsFloat;
              Discount := rSet.FieldByName('Discount').AsFloat;
              isPercentage := rSet.FieldByName('isPercentage').asBoolean;

              // This is normally not needed, but in exceptional cases (i.e. with a new header with a different currency)
              // it will correct the shown rates
              lRoomRateCurrency := rSet.FieldByName('Currency').AsString;
              if (lRoomRateCurrency <> InvoiceCurrencyCode) then
              begin
                Rate := Rate * GetRate(lRoomRateCurrency) / InvoiceCurrencyRate;
                if not IsPercentage then
                  Discount := Discount * GetRate(lRoomRateCurrency) / invoiceCurrencyRate;
              end;

              ShowDiscount := rSet.FieldByName('ShowDiscount').asBoolean;
              isPaid := rSet.FieldByName('Paid').asBoolean;
              if not isPaid then
              begin
                UnpaidDays := UnpaidDays + 1;
              end;

              if isPercentage then
                DiscountAmount := Rate * Discount / 100
              else
                DiscountAmount := Discount;

              rentAmount := Rate - DiscountAmount;
              NativeAmount := rentAmount * CurrencyRate;
              TotalDiscountAmount := TotalDiscountAmount + DiscountAmount;
              TotalRate := TotalRate + Rate;
              allIsPercentage := allIsPercentage and IsPercentage;

              mRoomRates.append;
              mRoomRates.FieldByName('Reservation').asinteger := reservation;
              mRoomRates.FieldByName('RoomReservation').asinteger := lRoomReservation;
              mRoomRates.FieldByName('RoomNumber').asString := Room;
              mRoomRates.FieldByName('PriceCode').asString := PriceCode;
              mRoomRates.FieldByName('RateDate').asdateTime := RateDate;
              mRoomRates.FieldByName('Rate').asfloat := Rate;
              mRoomRates.FieldByName('Discount').asfloat := Discount;
              mRoomRates.FieldByName('isPercentage').asBoolean := isPercentage;
              mRoomRates.FieldByName('ShowDiscount').asBoolean := ShowDiscount;
              mRoomRates.FieldByName('isPaid').asBoolean := isPaid;
              mRoomRates.FieldByName('DiscountAmount').asfloat := DiscountAmount;
              mRoomRates.FieldByName('RentAmount').asfloat := rentAmount;
              mRoomRates.FieldByName('NativeAmount').asfloat := NativeAmount;
              mRoomRates.post;
            end;
            RateDate := RateDate + 1;
          end;
        end;
        iTotalResDays := trunc(Departure) - trunc(Arrival);
        GuestsInRoomRes := NumberGuests;
        // ChildrenCount+infantCount
        GuestNights := GuestsInRoomRes * UnpaidDays;
        RoomRentPaidDays := iTotalResDays - UnpaidDays;
        if UnpaidDays > 0 then
        begin
          AverageRate := TotalRate / UnpaidDays;
          AverageDiscountAmount := TotalDiscountAmount / UnpaidDays;

          if AverageRate <> 0 then
            AvrageDiscountPerc := AverageDiscountAmount / (AverageRate / 100)
          else
            AvrageDiscountPerc := 0;

          isPackage := not package.IsEmpty;

//          if ABS(AverageRate) > 0 then
//          begin
//
            if allIsPercentage and (AvrageDiscountPerc <> 0) then
              DiscountText := DiscountText + '(' + floattostr(RoundDecimals(AvrageDiscountPerc, 2)) + '%)';

            AddRoom(Room, AverageRate, InvoiceCurrencyCode, Arrival, Departure, UnpaidDays, zRoomRSet.FieldByName('rrDescription').asString,
                    lRoomReservation,
                    iif(AllIsPercentage, AvrageDiscountPerc, AverageDiscountAmount), AllisPercentage, DiscountText,
                    GuestName, NumberGuests, ChildrenCount, Package, lRoomReservation, zRoomRSet.FieldByName('invBreakFast').AsBoolean, true);

//          end

//??? What is this about?
//          else if (ABS(AverageRate) = 0) and (status <> 'B') then
//          begin
//            if package <> '' then
//            begin
//              _s := Package_getRoomDescription(Package, Room, Arrival, Departure, GuestName);
//              if FRoomReservation = 0 then
//                _s := _s + ' ' + lRoomText + ':' + Room;
//            end
//            else
//              _s := format(lRoomtext + ' %s %s-%s', [Room, FormatDateTime('dd/mm', Arrival), FormatDateTime('dd/mm', Departure)]);
//            sText := _s;
//            tmp := trim(zRoomRSet.FieldByName('rrDescription').asString);
//            if copy(tmp, 1, 2) = '--' then
//              sText := '';
//            sText := tmp + sText;
//            AddRoom(Room, 0, InvoiceCurrency, Arrival, Departure, UnpaidDays, sText, (lRoomReservation = 0), lRoomReservation, 0, false, '', '', NumberGuests, ChildrenCount, package, lRoomReservation, zRoomRSet.FieldByName('invBreakFast').AsBoolean);
//          end;
        end;
        inc(index);
        zRoomRSet.Next;
      end;
    end;
  finally
    lExecutionPlan.free;
    zRoomRSet.Free;
  end;


end;

procedure TfrmInvoiceEdit.GenerateRoomRentLinesPerDay();
var
  lCurrency: string;
//  lRoomText: string;
  RateCount: Integer;
//  isPackage: Boolean;
  status: string;
  isPaid: Boolean;
  ShowDiscount: Boolean;
  Discount: Double;
//  tmp: string;
//  sText: string;
  isGroupAccount: Boolean;
  infantCount: Integer;
  lRoomsDateSet: TRoomerDataSet;
  list: TStringList;
  Room: string;
  RoomTypeDescription: string;
  RateDate: TDateTime;
  DiscountAmount: Double;
  RoomType: string;
  ChildrenCount: Integer;
  isPercentage: Boolean;
//  lBreakFastIncluded: Boolean;
  RoomDescription: string;
  CurrencyRate: Double;
  package: string;
//  i: Integer;
  lRoomReservation: Integer;
  PriceCode: string;
  AverageDiscountPerc: Double;
  Rate: Double;
  GuestName: string;
  AverageRate: Double;
  Arrival: TDate;
  iLastRoomRes: Integer;
  Departure: TDate;
  sql: string;
  NativeAmount: Double;
  NumberGuests: Integer;
  DiscountText: string;
  rentAmount: Double;
  Local_i: Integer;
begin
  sql := Select_Invoice_GenerateInvoiceLinesRoomRentPerDay(FRoomReservation, FReservation, FInvoiceIndex, edtCustomer.Text);

  lRoomsDateSet := CreateNewDataSet;
  try
    lRoomsDateSet.CommandType := cmdText;

    copytoclipboard(sql);
    hData.rSet_bySQL(lRoomsDateSet, sql);

    iLastRoomRes := -1;
    lRoomsDateSet.first;
    if not lRoomsDateSet.eof then
    begin
      zEmailAddress := '';
      list := TStringList.Create;
      try
        uUtils.SplitString(trim(lRoomsDateSet.FieldByName('ContactEmail').asString), list, ';');
        for Local_i := 0 to list.Count - 1 do
          if list[Local_i] <> '' then
          begin
            if zEmailAddress = '' then
              zEmailAddress := QuotedStr(list[Local_i])
            else
              zEmailAddress := zEmailAddress + ';' + QuotedStr(list[Local_i]);
          end;
      finally
        FreeAndNil(list);
      end;
      if trim(lRoomsDateSet.FieldByName('GuestEmail').asString) <> '' then
      begin
        if zEmailAddress = '' then
        begin
          zEmailAddress := QuotedStr(trim(lRoomsDateSet.FieldByName('GuestEmail').asString));
        end
        else
        begin
          zEmailAddress := zEmailAddress + ';' + QuotedStr(trim(lRoomsDateSet.FieldByName('GuestEmail').asString));
        end;
      end;
    end;

    lRoomsDateSet.first;
    while not lRoomsDateSet.eof do
    begin
      lRoomReservation := lRoomsDateSet.FieldByName('Roomreservation').asinteger;
      isGroupAccount := lRoomsDateSet['GroupAccount'];
      status := lRoomsDateSet.FieldByName('status').asString;
      Room := lRoomsDateSet.FieldByName('room').asString;
      RoomType := lRoomsDateSet.FieldByName('RoomType').asString;
      package := lRoomsDateSet.FieldByName('package').asString;
      NumberGuests := lRoomsDateSet.FieldByName('numGuests').asinteger;
      RoomDescription := lRoomsDateSet.FieldByName('RoomDescription').asString;
      RoomTypeDescription := lRoomsDateSet.FieldByName('RoomTypeDescription').asString;
      Arrival := lRoomsDateSet.FieldByName('rrArrival').asdateTime;
      Departure := lRoomsDateSet.FieldByName('rrDeparture').asdateTime;
      ChildrenCount := lRoomsDateSet.FieldByName('numChildren').asinteger;
      infantCount := lRoomsDateSet.FieldByName('numInfants').asinteger;
      PriceCode := lRoomsDateSet.FieldByName('PriceType').asString;
      AverageRate := lRoomsDateSet.FieldByName('AverageRate').AsFloat;
      RateCount := lRoomsDateSet.FieldByName('rateCount').asinteger;
      AverageDiscountPerc := lRoomsDateSet.FieldByName('discount').AsFloat;
      if iLastRoomRes <> lRoomReservation then
      begin
        mRoomRes.append;
        mRoomResroomreservation.asinteger := lRoomReservation;
        mRoomResRoom.asString := Room;
        mRoomResRoomType.asString := RoomType;
        mRoomResPackage.asString := package;
        mRoomResGuests.asinteger := NumberGuests;
        mRoomResAvragePrice.AsFloat := AverageRate;
        mRoomResRateCount.AsFloat := RateCount;
        mRoomResRoomDescription.asString := RoomDescription;
        mRoomResRoomTypeDescription.asString := RoomTypeDescription;
        mRoomResArrival.asdateTime := Arrival;
        mRoomResDeparture.asdateTime := Departure;
        mRoomResChildrenCount.asinteger := ChildrenCount;
        mRoomResinfantCount.asinteger := infantCount;
        mRoomResPriceCode.asString := PriceCode;
        mRoomResAvrageDiscount.AsFloat := AverageDiscountPerc;
        mRoomResInvoiceIndex.asinteger := FInvoiceIndex;
        mRoomResGroupAccount.asBoolean := IsGroupAccount;
        GuestName := lRoomsDateSet.FieldByName('guestName').asString;
        mRoomResGuests.asinteger := NumberGuests;
        mRoomResGuestName.asString := GuestName;
        mRoomRes.post;
        iLastRoomRes := lRoomReservation;
      end;

      PriceCode := lRoomsDateSet.FieldByName('PriceCode').asString;
      RateDate := SQLToDate(lRoomsDateSet.FieldByName('ADate').asString);
      Rate := lRoomsDateSet.FieldByName('RoomRate').AsFloat;
      // in selected currency
      lCurrency := lRoomsDateSet.FieldByName('Currency').asString;
      Discount := lRoomsDateSet.FieldByName('Discount').AsFloat;
      isPercentage := lRoomsDateSet.FieldByName('isPercentage').asBoolean;
      ShowDiscount := lRoomsDateSet.FieldByName('ShowDiscount').asBoolean;
      isPaid := lRoomsDateSet.FieldByName('Paid').asBoolean;

      if isPercentage then
        DiscountAmount := Rate * Discount / 100
      else
        DiscountAmount := Discount;

      rentAmount := Rate - DiscountAmount;

      try
        CurrencyRate := GetRate(lCurrency);
      except
        CurrencyRate := 1;
      end;

      if CurrencyRate = 0 then
        CurrencyRate := 1;

      NativeAmount := rentAmount * CurrencyRate;
      mRoomRates.append;
      mRoomRates.FieldByName('Reservation').asinteger := FReservation;
      mRoomRates.FieldByName('RoomReservation').asinteger := lRoomReservation;
      mRoomRates.FieldByName('RoomNumber').asString := Room;
      mRoomRates.FieldByName('PriceCode').asString := PriceCode;
      mRoomRates.FieldByName('RateDate').asdateTime := RateDate;
      mRoomRates.FieldByName('Rate').AsFloat := Rate;
      mRoomRates.FieldByName('Discount').AsFloat := Discount;
      mRoomRates.FieldByName('isPercentage').asBoolean := isPercentage;
      mRoomRates.FieldByName('ShowDiscount').asBoolean := ShowDiscount;
      mRoomRates.FieldByName('isPaid').asBoolean := isPaid;
      mRoomRates.FieldByName('DiscountAmount').AsFloat := DiscountAmount;
      mRoomRates.FieldByName('RentAmount').AsFloat := rentAmount;
      mRoomRates.FieldByName('NativeAmount').AsFloat := NativeAmount;
      mRoomRates.post;

//      isPackage := not package.IsEmpty;
//      if package <> '' then
//      begin
//        isPackage := True;
//        lRoomtext := Package_getRoomDescription(Package, Room, RateDate, RateDate, GuestName);
//        if FRoomReservation = 0 then
//          lRoomtext := lRoomtext + ' ' + GetTranslatedText('shRoom') + ': ' + Room;
//      end
//      else
//        lRoomText := format(GetTranslatedText('shRoom') + ' %s on %s', [Room, FormatDateTime('dd/mm', RateDate)]);
//
//      tmp := trim(lRoomsDateSet.FieldByName('rrDescription').asString);
//
//      if copy(tmp, 1, 2) = '--' then
//        lRoomText := '';
//
//      lRoomText := tmp + ' ' + lRoomText;

      if isPercentage then
        DiscountText := DiscountText + '(' + floattostr(Discount) + '%)';

      AddRoom(Room, Rate, lCurrency, RateDate, RateDate + 1, 1, lRoomsDateSet.FieldByName('rrDescription').asString,
              lRoomReservation,
              DiscountAmount, isPercentage, DiscountText, GuestName, NumberGuests, ChildrenCount, package,
              lRoomReservation, lRoomsDateSet.FieldByName('invBreakFast').asBoolean, true);

      lRoomsDateSet.Next;
    end; // while not roomdateSet.eof()
  finally
    lRoomsDateSet.Free;
  end;
end;

procedure TfrmInvoiceEdit.agrLinesCellValidate(Sender: TObject; ACol, ARow: integer; var Value: string;
  var Valid: boolean);
var
  dItemPrice: Double;
  lItemType: TItemTypeInfo;
  lItem: string;
  lInvoiceLine: TInvoiceLine;
  lAmountMutation: Double;
  lNewValue: Double;
begin
  Valid := True;
  agrLines.BeginUpdate;
  try
    try
      lInvoiceLine := GetInvoiceLineByRow(ARow);
      if not assigned(lInvoiceLine) then
      begin
        lInvoiceLine := AddLine(0, nil, '', '', 1, 0, g.qNativeCurrency, '', now(), false, '', '', false, 0, 0, 0, 0, '');
        agrLines.Objects[cInvoiceLineAttachColumn, ARow] := lInvoiceLine;
      end;

      lNewValue := StrToFloatDef(Value, FCellDoubleBeforeEdit);

      case ACol of
        col_Item:
          begin
            // Can only be changed via button AddItem so this is a new invoice line!
            chkChanged;

            begin
              lItem := agrLines.Cells[col_Item, ARow];

              if lItem = trim(g.qPaymentItem) then
              begin
                // MessageDlg('You are not allowed to use the System''s Payment code directly', mtError, [mbOK], 0);
                MessageDlg(GetTranslatedText('shTx_Invoice_NotAllowed'), mtError, [mbOk], 0);
                Valid := false;
                exit;
              end;

              dItemPrice := Item_GetPrice(lItem);
              if NOT CheckExtraWithdrawalAllowed(dItemPrice) then
              begin
                Valid := false;
                exit;
              end;

              lItemType := d.Item_Get_ItemTypeInfo(lItem);
              with lInvoiceLine do
              begin
                Item := lItem;
                Text := Item_GetDescription(lItem);
                Number := 1;
                Price := dItemPrice;
                VATCode := lItemType.VATCode;
                PurchaseDate := now();
                Changed := True;
              end;

            end;
          end;

        col_Description:
          begin
            chkChanged;
            Valid := Value <> '';
            if Valid then
            begin
              lInvoiceLine.Text := Value;
              lInvoiceLine.Changed := True;
            end;
          end;

        col_ItemCount:
          begin

            chkChanged;
            lAmountMutation := (FCellDoubleBeforeEdit - lNewValue) * lInvoiceLine.Price;

            if NOT CheckExtraWithdrawalAllowed(lAmountMutation) then
            begin
              Valid := false;
              exit;
            end;

            lInvoiceLine.Number := lNewValue;
            lInvoiceLine.Changed := True;
            agrLines.Cells[col_System, ARow] := '';
          end;

        col_ItemPrice:
          begin
            chkChanged;

            lAmountMutation := (FCellDoubleBeforeEdit - lNewValue) * lInvoiceLine.Number;

            if NOT CheckExtraWithdrawalAllowed(lAmountMutation) then
            begin
              Valid := false;
              exit;
            end;

            lInvoiceLine.Price := TAmount.Create(lNewValue, lInvoiceLine.Currency);
            lInvoiceLine.Changed := True;
            agrLines.Cells[col_System, ARow] := '';
          end;
      end;
    except
      Valid := false;
    end;
  finally
    PostMessage(handle, WM_REDRAW_LINE, 0, agrLines.row);
    agrLines.EndUpdate;
  end;
end;

procedure TfrmInvoiceEdit.CheckBoxClick(Sender: TObject; ACol, ARow: integer; State: boolean);
var
  check: boolean;
  lInvoiceLine: TInvoiceLine;
begin
  if (ARow = 0) and (ACol = col_Select) then
  begin
    agrLines.GetCheckBoxState(col_Select, ARow, check);
    CheckOrUncheckAll(check);
  end
  else if (ARow > 0) and (ACol = col_VisibleOnInvoice) then
  begin
    agrLines.GetCheckBoxState(col_VisibleOnInvoice, ARow, check);
    lInvoiceLine := GetInvoiceLineByRow(ARow);
    lInvoiceLine.IsVisibleOnInvoice := check;
    lInvoiceLine.Changed := True;

    UpdateGrid;
  end;
  UpdateControls;
end;

function TfrmInvoiceEdit.GetAnyRowSelected: boolean;
var
  i: integer;
begin
  result := false;
  for i := 1 to agrLines.RowCount - 1 do
    if agrLines.HasCheckBox(col_Select, i) then
    begin
      agrLines.GetCheckBoxState(col_Select, i, result);
      if result then
        Break;
    end;
end;

procedure TfrmInvoiceEdit.agrLinesColumnSize(Sender: TObject; ACol: integer; var Allow: boolean);
begin

  if ACol = col_ItemCount then
  begin
    if agrLines.ColWidths[col_ItemCount] < 100 then
      agrLines.ColWidths[col_ItemCount] := 100; // -96
  end;

  if ACol = col_ItemPrice then
  begin
    if agrLines.ColWidths[col_ItemPrice] < 100 then
      agrLines.ColWidths[col_ItemPrice] := 100; // -96
  end;

  if ACol = col_TotalPrice then
  begin
    if agrLines.ColWidths[col_TotalPrice] < 100 then
      agrLines.ColWidths[col_TotalPrice] := 100; // -96
  end;

  if ACol = col_TotalOnInvoice then
  begin
    if agrLines.ColWidths[col_TotalOnInvoice] < 100 then
      agrLines.ColWidths[col_TotalOnInvoice] := 100; // -96
  end;
end;

procedure TfrmInvoiceEdit.agrLinesDblClickCell(Sender: TObject; ARow, ACol: integer);
begin
  if ACol <> col_Item then
    exit;
  if agrLines.Cells[ACol, ARow] <> '' then
    exit;
  itemLookup;
end;

// -- The original Invoice contains a special field which links it to the
// subceeding credit invoice. This is for traceback purposes.
procedure TfrmInvoiceEdit.MarkOriginalInvoiceAsCredited(iInvoice: integer);
var
  s: string;
begin
  s := '';
  s := s + 'UPDATE invoiceheads ' + #10;
  s := s + ' Set ' + #10;
  s := s + '  CreditInvoice ' + ' = ' + _db(iInvoice) + #10;
  s := s + ' where InvoiceNumber = ' + _db(zRefNum);
  if not cmd_bySQL(s) then
    raise EInvocieException.CreateFmt('Marking invoice [%d] as credited failed', [zRefNum]);
end;

procedure TfrmInvoiceEdit.MoveRoomToGroupInvoice;
begin
  if FRoomReservation = 0 then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_GroupInvoice'));
    exit;
  end;

  // if (MessageDlg('Move roomrent to Groupinvoice ' + chr(10) + 'and save other changes ?', mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
  if (MessageDlg(GetTranslatedText('shTx_Invoice_RoomrentToGroupAndSaveChanges'), mtConfirmation, [mbYes, mbNo], 0)
    = mrYes) then
  begin
    SaveInvoice(zInvoiceNumber, stProvisionally);
    if d.UpdateGroupAccountone(FReservation, FRoomReservation, FRoomReservation, True) then
    Refreshdata;
  end;
end;

function TfrmInvoiceEdit.IsRoomSelected: boolean;
var
  i: integer;
  check: boolean;
begin
  result := false;
  for i := 1 to agrLines.RowCount - 1 do
    if isSystemLine(i) then
      if agrLines.HasCheckBox(col_Select, i) then
      begin
        agrLines.GetCheckBoxState(col_Select, i, check);
        if check then
        begin
          result := True;
          Break;
        end;
      end;
end;

procedure TfrmInvoiceEdit.MoveRoomToRoomInvoice;
var
  i: integer;
  list: TList<integer>;
  invoiceline: TinvoiceLine;
begin
  if IsCashInvoice then
    Exit;

  if (FRoomReservation > 0) then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_RoomInvoice'));
    exit;
  end;

  chkChanged;

  // if (MessageDlg('Move roomrent to Groupinvoice ' + chr(10) + 'and save other changes ?', mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
  if (MessageDlg(GetTranslatedText('shTx_Invoice_RoomrentToRoomAndSaveChanges'), mtConfirmation, [mbYes, mbNo], 0)
    = mrYes) then
  begin
    SaveInvoice(zInvoiceNumber, stProvisionally);
    list := GetSelectedRowNrs;
    try
      for i := list.Count - 1 downto 0 do
      begin
        invoiceLine := GetInvoiceLineByRow(list[i]);
        if invoiceLine.IsGeneratedLine AND (invoiceLine.ItemKind = ikRoomRent) then
        begin
          d.UpdateGroupAccountone(invoiceline.RoomEntity.Reservation, invoiceline.RoomEntity.RoomReservation, invoiceline.RoomEntity.RoomReservation, false);
        end
      end;
      SaveInvoice(zInvoiceNumber, stProvisionally);
      RefreshData;
    finally
      list.Free;
    end;
  end;
end;

procedure TfrmInvoiceEdit.evtCurrencyChangedAndValid(Sender: TObject);
var
  oldCurrency: string;
begin
  if not IfInvoiceChangedThenOptionallySave(True) then
  begin
    // not saved, revert currency change in frame
    InvoiceCurrencyCode := FInvoiceCurrencyCode;
    exit;
  end;

  oldCurrency := InvoiceCurrencyCode;
  InvoiceCurrencyCode := fraInvoiceCurrency.CurrencyCode;
  if oldCurrency <> InvoiceCurrencyCode then
    ExecuteCurrencyChange(oldCurrency, InvoiceCurrencyCode);
end;

procedure TfrmInvoiceEdit.agrLinesDrawCell(Sender: TObject; ACol, ARow: integer; Rect: TRect;
  State: TGridDrawState);
//var
//  Bmp: TIcon;
//  Item: string;
begin
  inherited;

  // Show sun-icon with roomrent and discount items when foreign curency selected
  // Not needed anymore?

  // --
//  if not edtForeignCurrency.Visible then
//    exit;
//  if (ACol <> 5) then
//    exit;
//
//  Item := trim(TAdvStringGrid(Sender).Cells[col_Item, ARow]);
//  if (trim(g.qRoomRentItem) <> Item) and (trim(g.qDiscountItem) <> Item) then
//    exit;
//
//  try
//    Bmp := TIcon.Create;
//    try
//      GridImages.GetIcon(0, Bmp);
//      TAdvStringGrid(Sender).canvas.Draw(Rect.left + 1, Rect.top + 1, Bmp);
//    finally
//      Bmp.Free;
//    end;
//  except
//  end;
end;

procedure TfrmInvoiceEdit.UpdateRoomReservationsCurrency(const aFromCurrency: string; const aToCurrency: string);
var
  lRoomres: integer;
  lDate: string;
  rSet: TRoomerDataset;
  s: string;
  lExecPlan: TRoomerExecutionPlan;
  lRoomResList: IList<Integer>;
begin
  if (FRoomReservation = 0) and (FReservation = 0) then
    exit;

  if aFromCurrency.ToLower.Equals(aToCurrency.ToLower) then
    exit;

  rSet := CreateNewDataSet;
  try
    lRoomResList := TList<Integer>.Create;
    lExecPlan := TRoomerExecutionPlan.Create(rSet);
    try
      d.roomerMainDataSet.SystemStartTransaction;
      try

        AddSaveHeaderToExecPlan(-1, lExecplan);

        if (FRoomReservation = 0) and (FReservation > 0) then
        begin
          s := format(select_Invoice_CheckCurrencyChange, [FReservation, FInvoiceIndex]);
          hData.rSet_bySQL(rSet, s);
          rSet.first;
          while not rSet.eof do
          begin
            lRoomres := rSet.FieldByName('RoomReservation').asinteger;
            mRoomRates.first;
            while not mRoomRates.eof do
            begin
              if mRoomRates['Roomreservation'] = lRoomres then
              begin
                lDate := _db(mRoomRates.FieldByName('rateDate').asdateTime, false);
                if d.RR_Upd_CurrencyRoomPrice(lRoomres, lDate, aToCurrency) and not lRoomResList.Contains(lRoomRes) then
                  lRoomResList.Add(lRoomRes);
              end;
              mRoomRates.Next;
            end;
            rSet.Next;
          end;

        end
        else if (FRoomReservation > 0) then
        begin
          //TODO: Rewrite so SQL statements are added to ExecPlan
          mRoomRates.first;
          while not mRoomRates.eof do
          begin
            lRooMres := mRoomRatesRoomReservation.AsInteger;
            lDate := _db(mRoomRates.FieldByName('rateDate').asdateTime, false);
            d.RR_Upd_CurrencyRoomPrice(lRoomres, lDate, aToCurrency);
            if not lRoomResList.Contains(lRoomRes) then
              lRoomResList.Add(lRoomRes);
            mRoomRates.Next;
          end;
        end;

        for lRoomRes in lRoomresList do
        begin
          s := '';
          s := s + ' UPDATE roomreservations ' + chr(10);
          s := s + ' SET ' + chr(10);
          s := s + ' Currency=' + _db(aToCurrency) + ' ' + chr(10);
          s := s + ' WHERE (RoomReservation = ' + inttostr(lRoomRes) + ') ' + chr(10);
          lExecPlan.AddExec(s);
        end;

        lExecPlan.Execute(ptExec, false, false);
        d.roomerMainDataSet.SystemCommitTransaction;
      except
        d.roomerMainDataSet.SystemRollbackTransaction;
        raise;
      end;
    finally
      lExecPlan.Free;
    end;

  finally
    rSet.Free;
  end;
end;

procedure TfrmInvoiceEdit.ExecuteCurrencyChange(const aOldCurrency: string; const aNewCurrency: string);
begin
  UpdateRoomReservationsCurrency(aOldCurrency, aNewCurrency);
  Refreshdata;
end;

procedure TfrmInvoiceEdit.SetCustEdits;
begin
  edtCustomer.ReadOnly := rgrInvoiceAddressType.itemIndex IN [0, 1, 2, 3, 4, 5];

  if rgrInvoiceAddressType.itemIndex = 5 then
  begin
    edtCustomer.Text := ctrlGetString('RackCustomer');
  end;

  edtName.ReadOnly := rgrInvoiceAddressType.itemIndex IN [0, 1, 2, 3];
  edtAddress1.ReadOnly := rgrInvoiceAddressType.itemIndex IN [0, 1, 2, 3];
  edtAddress2.ReadOnly := rgrInvoiceAddressType.itemIndex IN [0, 1, 2, 3];
  edtAddress3.ReadOnly := rgrInvoiceAddressType.itemIndex IN [0, 1, 2, 3];
  edtAddress4.ReadOnly := rgrInvoiceAddressType.itemIndex IN [0, 1, 2, 3];
end;

procedure TfrmInvoiceEdit.SetHeaderChanged(const Value: boolean);
begin
  if (FHeaderChanged <> Value) then
  begin
    FHeaderChanged := value;
    chkChanged;
  end;
end;

procedure TfrmInvoiceEdit.SetInvoiceCurrencyCode(const Value: string);
begin
  FInvoiceCurrencyCode := Value;
  fraInvoiceCurrency.DisableEvents;
  try
    fraInvoiceCurrency.CurrencyCode := Value;
  finally
    fraInvoiceCurrency.EnableEvents;
  end;
end;

procedure TfrmInvoiceEdit.SetInvoiceIndex(const Value: TInvoiceIndex);
begin
  IfInvoiceChangedThenOptionallySave;
  FInvoiceIndex := Value;
  RemoveAllCheckboxes;
  RefreshData;
end;

procedure TfrmInvoiceEdit.pnlInvoiceIndex0Click(Sender: TObject);
begin
  InvoiceIndex := TsPanel(Sender).Tag;
end;

function TfrmInvoiceEdit.GetSelectedRows: TList<String>;
var
  i: integer;
  check: boolean;
begin
  result := TList<String>.Create;
  if AnyRowChecked then
  begin
    for i := 1 to agrLines.RowCount - 1 do
      if agrLines.HasCheckBox(col_Select, i) then
      begin
        agrLines.GetCheckBoxState(col_Select, i, check);
        if check then
          result.Add(agrLines.Cells[col_autogen, i]);
      end;
  end
  else if (agrLines.row > 0) AND (agrLines.row < agrLines.RowCount) then
    result.Add(agrLines.Cells[col_autogen, agrLines.row]);

  RemoveAllCheckboxes;
end;

function TfrmInvoiceEdit.GetSelectedRowNrs: TList<integer>;
var
  i: integer;
  check: boolean;
begin
  result := TList<integer>.Create;
  if AnyRowChecked then
  begin
    for i := 1 to agrLines.RowCount - 1 do
      if agrLines.HasCheckBox(col_Select, i) then
      begin
        agrLines.GetCheckBoxState(col_Select, i, check);
        if check then
          result.Add(i);
      end;
  end
  else if (agrLines.row > 0) AND (agrLines.row < agrLines.RowCount) then
    result.Add(agrLines.row);

end;

function TfrmInvoiceEdit.IndexOfAutoGen(AutoGen: String): integer;
var
  i: integer;
begin
  result := -1;
  for i := 1 to agrLines.RowCount - 1 do
    if agrLines.Cells[col_autogen, i] = AutoGen then
    begin
      result := i;
      Break;
    end;
end;

procedure TfrmInvoiceEdit.MoveSelectedLinesToInvoiceIndex(aNewIndex: integer);
var
  list: TList<integer>;
  i, Res: integer;
  invoiceLine: TInvoiceLine;
begin

  if (aNewIndex < 0) or (aNewIndex > 9) then
    Exit;

  list := GetSelectedRowNrs;
  try
    Res := -1;
    for i := list.Count - 1 downto 0 do
    begin
      invoiceLine := GetInvoiceLineByRow(list[i]);
      agrLines.row := list[i];
      if invoiceLine.IsGeneratedLine AND (invoiceLine.ItemKind = ikRoomRent) then
      begin
        invoiceline.MoveToInvoiceIndex(aNewIndex);
        // Also Moves generated childlines to new invoiceindex
        FInvoiceLinesList.Remove(invoiceLine);
      end
      else if invoiceLine.IsGeneratedLine AND (invoiceLine.ItemKind = ikStayTax) then
      begin
        if Res <> mrAll then
          Res := MessageDlg(GetTranslatedText('shTx_Invoice_WarningWhenMovingCityTax'), mtWarning,
            [mbYes, mbNo, mbAll, mbCancel], 0);
        case Res of
          mrYes, mrAll:
            begin
              actToggleLodgingTax.Execute;
              MoveItemToNewInvoiceIndex(List[i], aNewIndex);
            end;
          mrCancel:
            exit;
        end;
      end
      else
        MoveItemToNewInvoiceIndex(List[i], aNewIndex);
        //invoiceline.MoveToInvoiceIndex(TsPanel(Sender).Tag);
    end;
  finally
    list.Free;
  end;

end;

procedure TfrmInvoiceEdit.pnlInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
var
  lMoveToIndex: integer;
begin
  lMoveToIndex := TPanel(Sender).Tag;
  if lMoveToIndex = FInvoiceIndex then
    Exit;

  SaveAnd(False);

  if (Source = agrLines) then
  begin
    MoveSelectedLinesToInvoiceIndex(lMoveToIndex);
    UpdateGrid;
  end
  else if (Source is TcxDragControlObject) and (TcxDragControlObject(Source).control = grPayments) then
  begin
    MoveDownpaymentToInvoiceIndex(lMoveToIndex);
    LoadPayments;
  end;
end;

procedure TfrmInvoiceEdit.pnlInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState;
  var Accept: boolean);
begin
  Accept := (Source = agrLines) OR (Source IS TcxDragControlObject);
end;

procedure TfrmInvoiceEdit.actMoveRoomToGroupInvoiceExecute(Sender: TObject);
begin
  MoveRoomToGroupInvoice;
end;


procedure TfrmInvoiceEdit.actMoveRoomToRoomInvoiceExecute(Sender: TObject);
begin
  MoveRoomToRoomInvoice;
end;

function TfrmInvoiceEdit.GetCustomerHeader(Res: integer): boolean;
var
  customer: string;
  aname: string;
  Address1: string;
  Address2: string;
  Address3: string;
  Address4: string;
  Country: string;
  PID: string;

begin
  // Ekki fyrir sta�grei�slureikninga
  result := false;
  if FInvoiceType = itCashInvoice then
    exit;
  if FReservation = -1 then
    exit;

  customer := edtCustomer.Text;
  if glb.LocateSpecificRecord('customers', 'Customer', customer) then
    with glb.CustomersSet do
    begin
      aname := FieldByName('SurName').asString;
      Address1 := FieldByName('Address1').asString;
      Address2 := FieldByName('Address2').asString;
      Address3 := FieldByName('Address3').asString;
      Address4 := FieldByName('Address4').asString;
      Country := FieldByName('Country').asString;
      PID := FieldByName('PID').asString;

      edtCustomer.Text := trim(customer);
      edtName.Text := trim(aname);
      edtPersonalId.Text := trim(PID);
      edtAddress1.Text := trim(Address1);
      edtAddress2.Text := trim(Address2);
      edtAddress3.Text := trim(Address3);
      edtAddress4.Text := trim(Address4);
      zCountry := trim(Country);
      result := True;
    end;
end;

function TfrmInvoiceEdit.GetInvoiceHeader(Res, RoomRes: integer): boolean;
var
  InvoiceNumber: integer;
  customer: string;
  Name: string;
  Address1: string;
  Address2: string;
  Address3: string;
  Address4: string;
  Country: string;
  CustPID: string;
  invRefrence: string;

  rSet: TRoomerDataset;
  s: string;
  sTmp: string;

begin
  result := false;

  if FInvoiceType = itCashInvoice then
    exit;

  result := false;
  if FReservation = -1 then
    exit;

  rSet := CreateNewDataSet;
  try
    s := format(select_Invoice_GetInvoiceHeader, [Res, RoomRes]);
    hData.rSet_bySQL(rSet, s);

    InvoiceNumber := -1;
    rSet.first;
    if rSet.RecordCount > 0 then
    begin
      InvoiceNumber := rSet.FieldByName('InvoiceNumber').asinteger;
      customer := rSet.FieldByName('Customer').asString;
      name := rSet.FieldByName('Name').asString;
      Address1 := rSet.FieldByName('Address1').asString;
      Address2 := rSet.FieldByName('Address2').asString;
      Address3 := rSet.FieldByName('Address3').asString;
      Address4 := rSet.FieldByName('Address4').asString;
      Country := rSet.FieldByName('Country').asString;
      CustPID := rSet.FieldByName('custPID').asString;
      invRefrence := rSet.FieldByName('invRefrence').asString;
    end;

    sTmp := d.IH_GetRefrence(-1, Res, RoomRes);

    if sTmp <> '' then
    begin
      invRefrence := sTmp;
    end;

    // �.e ekki fr�gengin reikningur
    if (InvoiceNumber = -1) or (FIsCredit) then
    begin
      edtCustomer.Text := trim(customer);
      edtName.Text := trim(name);
      edtPersonalId.Text := trim(CustPID);
      edtAddress1.Text := trim(Address1);
      edtAddress2.Text := trim(Address2);
      edtAddress3.Text := trim(Address3);
      edtAddress4.Text := trim(Address4);
      edtInvRefrence.Caption := trim(invRefrence);

      zCountry := trim(Country);
      result := True;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

function TfrmInvoiceEdit.GetHeaderChanged: boolean;
begin
  result := FHeaderChanged;
end;

function TfrmInvoiceEdit.GetInvoiceHeader(Res, RoomRes: integer; arSet: TRoomerDataset): boolean;
var
  InvoiceNumber: integer;
  customer: string;
  Name: string;
  Address1: string;
  Address2: string;
  Address3: string;
  Address4: string;
  Country: string;
  CustPID: string;
  invRefrence: string;
  FreeText: String;

  sTmp: string;

begin
  result := false;

  if FInvoiceType = itCashInvoice then
    exit;

  result := false;
  if FReservation = -1 then
    exit;

  InvoiceNumber := -1;
  arSet.first;
  if NOT arSet.eof then
  begin
    InvoiceNumber := arSet.FieldByName('InvoiceNumber').asinteger;
    customer := arSet.FieldByName('Customer').asString;
    name := arSet.FieldByName('Name').asString;
    Address1 := arSet.FieldByName('Address1').asString;
    Address2 := arSet.FieldByName('Address2').asString;
    Address3 := arSet.FieldByName('Address3').asString;
    Address4 := arSet.FieldByName('Address4').asString;
    Country := arSet.FieldByName('Country').asString;
    CustPID := arSet.FieldByName('custPID').asString;
    invRefrence := arSet.FieldByName('invRefrence').asString;
    FreeText := arSet.FieldByName('ExtraText').asString;
  end;

  sTmp := d.IH_GetRefrence(-1, Res, RoomRes);

  if sTmp <> '' then
  begin
    invRefrence := sTmp;
  end;

  // �.e ekki fr�gengin reikningur
  if (InvoiceNumber = -1) or (FIsCredit) then
  begin
    edtCustomer.Text := trim(customer);
    edtName.Text := trim(name);
    edtPersonalId.Text := trim(CustPID);
    edtAddress1.Text := trim(Address1);
    edtAddress2.Text := trim(Address2);
    edtAddress3.Text := trim(Address3);
    edtAddress4.Text := trim(Address4);
    edtInvRefrence.Caption := trim(invRefrence);
    memExtraText.Lines.Text := trim(FreeText);

    zCountry := trim(Country);
    result := True;
  end;
end;

function TfrmInvoiceEdit.GetReservationHeader(Res, RoomRes: integer): boolean;
var
  customer: string;
  Name: string;
  Address1: string;
  Address2: string;
  Address3: string;
  Address4: string;
  Country: string;
  CustPID: string;
  invRefrence: string;

  rSet: TRoomerDataset;
  s: string;
  sTmp: string;

begin
  result := false;

  if FInvoiceType = itCashInvoice then
    exit;

  if FReservation = -1 then
    exit;

  rSet := CreateNewDataSet;

  try
    s := format(select_Invoice_GetReservationHeader, [Res]);
    hData.rSet_bySQL(rSet, s);
    rSet.first;

    if not rSet.eof then
    begin
      customer := rSet.FieldByName('Customer').asString;
      name := rSet.FieldByName('Name').asString;
      Address1 := rSet.FieldByName('Address1').asString;
      Address2 := rSet.FieldByName('Address2').asString;
      Address3 := rSet.FieldByName('Address3').asString;
      Address4 := rSet.FieldByName('Address4').asString;
      Country := rSet.FieldByName('Country').asString;
      CustPID := rSet.FieldByName('custPID').asString;
      invRefrence := rSet.FieldByName('invRefrence').asString;
    end;

    sTmp := d.IH_GetRefrence(-1, Res, RoomRes);

    if sTmp <> '' then
    begin
      invRefrence := sTmp;
    end;

    edtCustomer.Text := trim(customer);
    edtName.Text := trim(name);
    edtPersonalId.Text := trim(CustPID);
    edtAddress1.Text := trim(Address1);
    edtAddress2.Text := trim(Address2);
    edtAddress3.Text := trim(Address3);
    edtAddress4.Text := trim(Address4);
    edtInvRefrence.Caption := trim(invRefrence);
    zCountry := trim(Country);

    result := True;
  finally
    FreeAndNil(rSet);
  end;
end;

function TfrmInvoiceEdit.GetRowForInvoiceLine(aInvoiceLine: TInvoiceLine): integer;
begin
  for result := 0 to agrLines.RowCount - 1 do
    if GetInvoiceLineByRow(result) = aInvoiceLine then
      Break;
end;

function TfrmInvoiceEdit.GetMainGuestHeader(Res, RoomRes: integer): boolean;
var
  Name: string;
  Address1: string;
  Address2: string;
  Address3: string;
  Address4: string;
  Country: string;
  PID: string;

  rSet: TRoomerDataset;
  s: string;
  sql: string;
  customer: String;

begin
  result := false;
  if FInvoiceType = itCashInvoice then
    exit;

  if FReservation = -1 then
    exit;

  rSet := CreateNewDataSet;
  try
    sql := ' SELECT pe.Person, ' + ' pe.RoomReservation, ' + ' pe.Reservation, ' + ' co.RackCustomer AS Customer,' +
      ' pe.Name,' + ' pe.Address1 Address1, ' + ' pe.Address2 AS Address2, ' + ' pe.Address3 Address3, ' +
      ' pe.Address4 Address4, ' + ' pe.Country Country, ' + ' pe.PID ' + ' FROM persons pe, ' + '     control co ' +
      ' WHERE (pe.Reservation = %d) AND (pe.RoomReservation = %d) ';
    s := format(sql, [Res, RoomRes]);
    copytoclipboard(s);
    hData.rSet_bySQL(rSet, s);

    rSet.first;
    name := '';
    Address1 := '';
    Address2 := '';
    Address3 := '';
    Address4 := '';
    Country := '';
    customer := ctrlGetString('RackCustomer');

    if not rSet.eof then
    begin
      name := rSet.FieldByName('Name').asString;
      Address1 := rSet.FieldByName('Address1').asString;
      Address2 := rSet.FieldByName('Address2').asString;
      Address3 := rSet.FieldByName('Address3').asString;
      Address4 := rSet.FieldByName('Address4').asString;
      Country := rSet.FieldByName('Country').asString;
      PID := rSet.FieldByName('PID').asString;
      customer := rSet.FieldByName('Customer').asString;
    end;

    edtCustomer.Text := customer;
    edtName.Text := trim(name);
    edtPersonalId.Text := trim(PID);
    edtAddress1.Text := trim(Address1);
    edtAddress2.Text := trim(Address2);
    edtAddress3.Text := trim(Address3);
    edtAddress4.Text := trim(Address4);
    zCountry := trim(Country);
    result := True;
  finally
    FreeAndNil(rSet);
  end;
end;

function TfrmInvoiceEdit.GetMainGuestName(Res, RoomRes: integer): string;
var
  Name: string;
  rSet: TRoomerDataset;
  s: string;
  sql: string;
begin
  result := '';
  if FReservation = -1 then
    exit;
  if FInvoiceType = itCashInvoice then
    exit;

  rSet := CreateNewDataSet;
  try
    sql := ' SELECT ' + '    Name ' + ' FROM ' + '   persons ' + ' WHERE ' +
      '   (Reservation = %d) AND (RoomReservation = %d) ';
    s := format(sql, [Res, RoomRes]);
    hData.rSet_bySQL(rSet, s);
    rSet.first;
    if NOT rSet.eof then
    begin
      name := rSet.FieldByName('Name').asString;
      result := trim(name);
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmInvoiceEdit.rgrInvoiceAddressTypeClick(Sender: TObject);
begin
  btnGetCustomer.Enabled := rgrInvoiceAddressType.itemIndex <> 1;
  btnClearAddresses.Enabled := rgrInvoiceAddressType.itemIndex <> 1;

  case rgrInvoiceAddressType.itemIndex of
    0:
      begin
        GetCustomerHeader(FReservation);
      end;
    1:
      begin
        GetReservationHeader(FReservation, FRoomReservation);
      end;
    2:
      begin
        GetMainGuestHeader(FReservation, FRoomReservation);
      end;
    3:
      begin
        GetInvoiceHeader(FReservation, FRoomReservation);
      end;
    4:
      begin
      end;
    5:
      begin
        edtCustomer.Text := ctrlGetString('RackCustomer');
        edtPersonalId.Text := '';
        edtName.Text := 'Invoice';
        edtAddress1.Text := '';
        edtAddress2.Text := '';
        edtAddress3.Text := '';
        edtAddress4.Text := '';
      end;

  end;
  edtRoomGuest.Caption := GetMainGuestName(FReservation, FRoomReservation);
  HeaderChanged := True;
  SetCustEdits;
end;

procedure TfrmInvoiceEdit.SaveAnd(doExit: boolean);
begin
  if zDoSave then
  begin
    if not IsCashInvoice then
      SaveInvoice(zInvoiceNumber, stProvisionally);
    chkChanged;
    if doExit then
      close;
  end;
end;

procedure TfrmInvoiceEdit.actSaveAndExitExecute(Sender: TObject);
begin
  SaveAnd(True);
end;

procedure TfrmInvoiceEdit.actPrintInvoiceExecute(Sender: TObject);
var
  ok: boolean;
begin
  ok := hData.CustomerExist(trim(edtCustomer.Text));

  if not ok then
  begin
    MessageDlg('Customer not found', mtError, [mbOk], 0);
    exit
  end;

  if PayAndPrintFinalInvoice then
    close
  else
  begin
    LoadPayments;
    DisplayTotals;
  end;
end;

function TfrmInvoiceEdit.PayAndPrintFinalInvoice: boolean;
var
  lNewInvoiceNumber: integer;
  lInvoiceLocation: string;
begin
  result := false;
  if not CompletePayments(zInvoiceDate, zPayDate, lInvoiceLocation) then
    exit;

  lNewInvoiceNumber := IVH_SetNewID();
  try
    if SaveInvoice(lNewInvoiceNumber, stDefinitive, lInvoiceLocation) then
    begin
      AddInvoiceActivityLog(g.qUser, FReservation, FRoomReservation, ord(FInvoiceType), PAY_AND_PRINT, inttostr(lNewInvoiceNumber),
                            FInvoiceLinesList.TotalOnInvoice.ToNative, 0,
                            Format('Final invoice [%d] created for roomreservation [%d/%d]', [lNewInvoiceNumber, FReservation, FRoomReservation]));
      ViewInvoice2(lNewInvoiceNumber, True, false, True, false, {chkShowPackageItems.checked,} zEmailAddress);
      d.roomerMainDataSet.SystempackagesCreateHeaderIfNotExists(FRoomReservation, FRoomReservation);
      result := True;
    end
    else
      IVH_RestoreID;
  except
    IVH_RestoreID;
  end;
end;

procedure TfrmInvoiceEdit.actPrintProformaExecute(Sender: TObject);
begin
  PrintProforma;
end;

procedure TfrmInvoiceEdit.actEditDownPaymentClick(Sender: TObject);
var
  rSet: TRoomerDataset;
  rec: recDownPayment;
  s: string;
  Id: integer;
  sql: string;
begin
  // **
  if mPayments.RecordCount = 0 then
  begin
    exit;
  end;

  g.initRecDownPayment(rec);

  if edtBalance.Text <> '' then
    rec.InvoiceBalanceInCurrency := _StrToFloat(edtBalance.Text) + _StrToFloat(edtDownPayments.Text);

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.AmountInCurrency := mPaymentsNativeAmount.AsFloat;
  rec.Quantity := 1;
  rec.Description := mPayments.FieldByName('Description').asString;
  rec.Notes := mPayments.FieldByName('Memo').asString;
  rec.PaymentType := mPayments.FieldByName('PayType').asString;
  rec.PayDate := mPayments.FieldByName('PayDate').asdateTime;
  rec.payGroup := mPayments.FieldByName('PayGroup').asString;
  rec.ConfirmDate := mPayments.FieldByName('Confirmdate').asdateTime;

  Id := mPayments.FieldByName('ID').asinteger;

  if rec.ConfirmDate < 3 then
  begin
    if OpenAssignPayment(Id) then
    begin
      rSet := CreateNewDataSet;
      try
        mPayments.close;
        mPayments.Open;

        sql := 'SELECT * FROM payments ' + ' where Reservation = %d ' + '   and RoomReservation = %d ' +
          '   and InvoiceNumber = -1 AND InvoiceIndex=%d';
        s := format(sql, [FReservation, FRoomReservation, FInvoiceIndex]);
        if rSet_bySQL(rSet, s) then
        begin
          while not rSet.eof do
          begin
            mPayments.insert;
            mPayments.FieldByName('PayType').asString := rSet.FieldByName('PayType').asString;
            mPayments.FieldByName('PayDate').asdateTime := SQLToDateTime(rSet.FieldByName('PayDate').asString);
            mPayments.FieldByName('NativeAmount').AsFloat := rSet.FieldByName('Amount').AsFloat;
            mPayments.FieldByName('Currency').AsFloat := rSet.FieldByName('currency').AsFloat;
            mPayments.FieldByName('Description').asString := rSet.FieldByName('Description').asString;
            mPayments.FieldByName('PayGroup').asString := '';
            mPayments.FieldByName('Memo').asString := rSet.FieldByName('Notes').asString;
            mPayments.FieldByName('confirmDate').asdateTime := rSet.FieldByName('Confirmdate').asdateTime;
            mPayments.FieldByName('Id').asinteger := rSet.FieldByName('ID').asinteger;
            if glb.Paytypesset.Locate('payType', rSet.FieldByName('PayType').asString, []) then
            begin
              mPayments.FieldByName('PayGroup').asString := glb.Paytypesset.FieldByName('payGroup').asString;
            end;
            mPayments.post;
            rSet.Next;
          end;
        end;
      finally
        FreeAndNil(rSet);
      end;
      mPayments.Locate('id', Id, []);
      DisplayTotals;
    end;
  end
  else
  begin
    ShowMessage('It is not allowed to change confirmed payments');
  end;
end;

procedure TfrmInvoiceEdit.actEditDownPaymentExecute(Sender: TObject);
var
  rec: recDownPayment;
  Id: integer;
begin
  // **
  if mPayments.RecordCount = 0 then
  begin
    exit;
  end;

  if mPaymentsPaycardTraceIndex.AsInteger > 0 then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_CannotEditDeletePCITokenPayment'));
    exit;
  end;

  g.initRecDownPayment(rec);

  if edtBalance.Text <> '' then
    rec.InvoiceBalanceInCurrency := _StrToFloat(edtBalance.Text) +
      _StrToFloat(edtDownPayments.Text);

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.AmountInCurrency := mPaymentsNativeAmount.asfloat;
  rec.Quantity := 1;
  rec.Description := mPayments.FieldByName('Description').asString;
  rec.Notes := mPayments.FieldByName('Memo').asString;
  rec.PaymentType := mPayments.FieldByName('PayType').asString;
  rec.PayDate := mPayments.FieldByName('PayDate').asdateTime;
  rec.payGroup := mPayments.FieldByName('PayGroup').asString;
  rec.confirmDate := mPayments.FieldByName('Confirmdate').asdateTime;

  Id := mPayments.FieldByName('ID').asinteger;

  if rec.confirmDate < 3 then
  begin
    if OpenAssignPayment(Id) then
    begin
      AddInvoiceActivityLog(g.qUser, rec.reservation, rec.RoomReservation, 1
        , CHANGE_PAYMENT, rec.PaymentType, rec.AmountInCurrency, zInvoiceNumber, rec.Description);

      LoadPayments;
      DisplayTotals;
    end;
  end
  else
  begin
    ShowMessage('It is not allowed to change confirmed payments');
  end;
end;

procedure TfrmInvoiceEdit.MoveDownpaymentToInvoiceIndex(toInvoiceIndex: integer);
var
  rec: recDownPayment;
  Id: integer;
  s: string;
begin
  // **
  if mPayments.RecordCount = 0 then
  begin
    exit;
  end;

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.AmountInCurrency := mPaymentsNativeAmount.AsFloat;
  rec.Quantity := 1;
  rec.Description := mPayments.FieldByName('Description').asString;
  rec.Notes := mPayments.FieldByName('Memo').asString;
  rec.PaymentType := mPayments.FieldByName('PayType').asString;
  rec.PayDate := mPayments.FieldByName('PayDate').asdateTime;
  rec.payGroup := mPayments.FieldByName('PayGroup').asString;
  rec.ConfirmDate := mPayments.FieldByName('Confirmdate').asdateTime;

  Id := mPayments.FieldByName('ID').asinteger;

  if (rec.ConfirmDate < 3) and (Id > 0) then
  begin
    s := ' UPDATE payments SET InvoiceIndex=' + inttostr(toInvoiceIndex) + ' '#10;
    s := s + ' WHERE  Id = (' + _db(Id) + ') ' + #10;

    if cmd_bySQL(s) then
    begin
      AddInvoiceActivityLog(g.qUser, rec.reservation, rec.RoomReservation, FInvoiceIndex
        // field typeindex 0 = invoice payment 1 = downpayment
        , DELETE_PAYMENT, rec.PaymentType, rec.AmountInCurrency, zInvoiceNumber, rec.Description);
      AddInvoiceActivityLog(g.qUser, rec.reservation, rec.RoomReservation, toInvoiceIndex
        // field typeindex 0 = invoice payment 1 = downpayment
        , ADD_PAYMENT, rec.PaymentType, rec.AmountInCurrency, zInvoiceNumber, rec.Description);

      LoadPayments;
      DisplayTotals;
    end;
  end
  else
  begin
    ShowMessage('It is not allowed to Delete confirmed payments');
  end;
end;

procedure TfrmInvoiceEdit.acHideAllBreakfastsExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(False, [ikBreakfast]);
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.acHideAllCTaxExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(FAlse, [ikStayTax]);
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.acHideAllDiscountsExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(False, [ikRoomRentDiscount]);
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.acHidePackageItemsExecute(Sender: TObject);
begin
  FInvoiceLinesList.ShowPackageItemsOnInvoice := False;
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.acShowAllCTaxExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(True, [ikStayTax]);
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.acShowAllDiscountsExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(True, [ikRoomRentDiscount]);
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.acShowAlllBreakfastsExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(True, [ikBreakfast]);
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.acShowpackageItemsExecute(Sender: TObject);
begin
  FInvoiceLinesList.ShowPackageItemsOnInvoice := True;
  UpdateGrid;
end;

procedure TfrmInvoiceEdit.actAddDownPaymentExecute(Sender: TObject);
var
  rec: recDownPayment;
  theData: recPaymentHolder;
  NewId: integer;

begin
  g.initRecDownPayment(rec);

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.Currency := InvoiceCurrencyCode;
  rec.AmountInCurrency := 0;

  if (rec.reservation = 0) and (rec.RoomReservation = 0) then
  begin
    ShowMessage('You cannot add downpayment to a cash invoice');
    exit;
  end;

  if edtBalance.Text <> '' then
    rec.InvoiceBalanceInCurrency := RoomerCurrencyManager.ConvertAmount(FInvoiceLinesList.TotalOnInvoice.ToNative - getTotalDownPayments, InvoiceCurrencyCode);

  if g.OpenDownPayment(actInsert, rec) then
  begin
    // insert payment

    initPaymentHolderRec(theData);

    theData.reservation := FReservation;
    theData.RoomReservation := FRoomReservation;
    theData.Person := ord(FInvoiceType);
    theData.TypeIndex := ORD(ptDownPayment);
    theData.InvoiceNumber := zInvoiceNumber;
    theData.customer := edtCustomer.Text;
    theData.PayDate := _db(Date, false);
    theData.NativeAmount := TAmount.Create(rec.AmountInCurrency, InvoiceCurrencyCode).ToNative;
    theData.Description := rec.Description;
    theData.CurrencyRate := InvoiceCurrencyRate;
    theData.Currency := InvoiceCurrencyCode;
    theData.ConfirmDate := 2; // _db('1900-01-01 00:00:00');
    theData.Notes := rec.Notes;
    theData.PayType := rec.PaymentType;
    theData.InvoiceIndex := InvoiceIndex;

    NewId := 0;
    INS_Payment(theData, NewId);
  end;

  // CC charges are updated in backend, so udpate always needed
  LoadPayments;
  DisplayTotals;

end;

procedure TfrmInvoiceEdit.actInfoExecute(Sender: TObject);
begin
  g.openresMemo(FReservation);
end;

procedure TfrmInvoiceEdit.actInvoiceActionsUpdate(Action: TBasicAction; var Handled: Boolean);
begin
  Handled := true;
  actRevertDownpayment.Enabled := not mPayments.IsEmpty;
  actDeleteDownPayment.Enabled := (mPayments.RecordCount > 0) and (mPaymentsPaycardTraceIndex.AsInteger <= 0);
  actEditDownPayment.Enabled := (mPayments.RecordCount > 0) and (mPaymentsPaycardTraceIndex.AsInteger <= 0);
end;

procedure TfrmInvoiceEdit.actAddLineExecute(Sender: TObject);
begin
  agrLines.row := agrLines.RowCount - 1;
  itemLookup;
end;

procedure TfrmInvoiceEdit.actAddRoomExecute(Sender: TObject);
begin
  agrLines.row := agrLines.RowCount - 1;
  AddARoom;;
end;

procedure TfrmInvoiceEdit.actDeleteDownPaymentExecute(Sender: TObject);
var
  rec: recDownPayment;
  Id: integer;
  s: string;
begin
  // **
  if mPayments.RecordCount = 0 then
    exit;

  g.initRecDownPayment(rec);

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.AmountInCurrency := mPaymentsNativeAmount.asfloat;
  rec.Quantity := 1;
  rec.Description := mPayments.FieldByName('Description').asString;
  rec.Notes := mPayments.FieldByName('Memo').asString;
  rec.PaymentType := mPayments.FieldByName('PayType').asString;
  rec.PayDate := mPayments.FieldByName('PayDate').asdateTime;
  rec.payGroup := mPayments.FieldByName('PayGroup').asString;
  rec.confirmDate := mPayments.FieldByName('Confirmdate').asdateTime;

  Id := mPayments.FieldByName('ID').asinteger;

  if mPaymentsPaycardTraceIndex.AsInteger > 0 then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_CannotEditDeletePCITokenPayment'));
    exit;
  end;

  if (rec.confirmDate < 3) and (Id > 0) then
  begin
    if MessageDlg('Delete payment ?'#10 + rec.Description + ' / Amount ' +
      _floattostr(rec.AmountInCurrency, vWidth, vDec), mtConfirmation,
      [mbYes, mbNo, mbCancel], 0) = mrYes then
    begin
      mPayments.delete;
      s := '';
      s := s + ' DELETE FROM payments '#10;
      s := s + ' WHERE  Id = (' + _db(Id) + ') ' + #10;

      if cmd_bySQL(s) then
      begin
        AddInvoiceActivityLog(g.qUser, rec.reservation, rec.RoomReservation, 1
            // field typeindex 0 = invoice payment 1 = downpayment
            , DELETE_PAYMENT, rec.PaymentType, rec.AmountInCurrency, zInvoiceNumber,
            rec.Description);
      end;

      DisplayTotals;
    end;
  end
  else
  begin
    ShowMessage('It is not allowed to Delete confirmed payments');
  end;
end;

procedure TfrmInvoiceEdit.AddARoom;
var
  lIntDate: integer;
  lDate: TDate;
  iPersons: integer;
  iRooms: integer;
  iNights: integer;
  dRoomPrice: Double;
  iRoomCount: integer;
  lRoomText: string;
begin
  iPersons := 1;
  iRooms := 1;
  iNights := 1;
  dRoomPrice := 0;

  if g.AddAccommodation(iPersons, iRooms, iNights, dRoomPrice) then
  begin
    if (iPersons > 0) and (iNights > 0) then
    begin
      if NOT CheckExtraWithdrawalAllowed(iNights * dRoomPrice) then
        exit;

      if ShowRentPerDay then
        for lIntDate := trunc(now) to trunc(now) + iNights - 1 do
        begin
        lDate := lIntDate * 1.0;
        lRoomText := GetTranslatedText('shRoom') + format(' on %s', [FormatDateTime('dd/mm', TDateTime(lDate))]);
        for iRoomCount := 0 to iRooms -1 do
          AddRoom('', dRoomPrice, g.qNativeCurrency, TDate(lDate), TDate(lDate) + 1, 1, '',  -1, 0, false, '', edtName.Text,
            iPersons, 0, '', -1, false, false);
        end
      else
        for iRoomCount := 0 to iRooms -1 do
          AddRoom('', dRoomPrice, g.qNativeCurrency, trunc(now), trunc(now) + iNights, 1, '', -1, 0, false, '', edtName.Text,
            iPersons, 0, '', -1, false, false);
    end;
    UpdateGrid;
  end;
end;

procedure TfrmInvoiceEdit.actRemoveSelectedExecute(Sender: TObject);
var
  list: TList<integer>;
  s: String;
  lInvLine: TInvoiceLine;
  lChildLine: TInvoiceLine;
  l: integer;
begin
  if AnyRowChecked then
    s := GetTranslatedText('shTx_Invoice_DeleteSelectedItems')
  else
    s := GetTranslatedText('shTx_Invoice_DeleteItem');
  if MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    list := GetSelectedRowNrs;
    try
      for l := list.Count - 1 downto 0 do
      begin
        lInvLine := GetInvoiceLineByRow(list[l]);

        if lInvLine.LineId > 0 then
          DeletedLines.Add(lInvLine.LineId);

        for lChildLine in lInvLine.ChildInvoiceLines do
        begin
          if lChildLine.LineId > 0 then
            DeletedLines.Add(lChildLine.LineId);
          FInvoiceLinesList.Remove(lChildLine);
        end;

        FInvoiceLinesList.Remove(lInvLine);
      end;
      UpdateGrid;
    finally
      list.Free;
    end;
  end;
end;

procedure TfrmInvoiceEdit.actRevertDownpaymentExecute(Sender: TObject);
var
  s: string;
  msg: string;
begin

  if mPayments.RecordCount = 0 then
    Exit;

  if (mPaymentsid.AsInteger > 0) then
  begin
    if mPaymentsChargedOnCC.AsBoolean then
    begin
      // Start creditcard refund
      RefundChargeFromChargeId(FReservation, FRoomReservation, mPaymentsPaycardTraceIndex.AsInteger);
    end
    else
    begin
      msg := Format(GetTranslatedtext('shTxInvoicePayments_RevertPayment'), [mPaymentsDescription.AsString, _floattostr(mPaymentsCurrencyAmount.AsFloat, vWidth, vDec), mPaymentsCurrency.AsString]);
      if MessageDlg(msg, mtConfirmation, [mbOK, mbCancel], 0) = mrOK then
      begin
        s := s + ' insert into payments ( '#10;
        s := s + '     Reservation, '#10;
        s := s + '     RoomReservation, '#10;
        s := s + '     Person, '#10;
        s := s + '     AutoGen, '#10;
        s := s + '     TypeIndex, '#10;
        s := s + '     InvoiceNumber, '#10;
        s := s + '     PayDate, '#10;
        s := s + '     Customer, '#10;
        s := s + '     PayType, '#10;
        s := s + '     Amount, '#10;
        s := s + '     Description, '#10;
        s := s + '     CurrencyRate, '#10;
        s := s + '     Currency, '#10;
        s := s + '     Ayear, '#10;
        s := s + '     Amon, '#10;
        s := s + '     Aday, '#10;
        s := s + '     Notes, '#10;
        s := s + '     staff, '#10;
        s := s + '     InvoiceIndex, '#10;
        s := s + '     Source, '#10;
        s := s + '     SourceUserId, '#10;
        s := s + '     SourceUserFullname, '#10;
        s := s + '     PAYCARD_TRACE_INDEX) '#10;
        s := s + ' select '#10;
        s := s + '     Reservation, '#10;
        s := s + '     RoomReservation, '#10;
        s := s + '     Person, '#10;
        s := s + '     ' + _db(_GetCurrentTick) + ', '#10;
        s := s + '     TypeIndex, '#10;
        s := s + '     InvoiceNumber, '#10;
        s := s + '     CURRENT_DATE as PayDate, '#10;
        s := s + '     Customer, '#10;
        s := s + '     PayType, '#10;
        s := s + '     Amount * -1, '#10;
        s := s + '     CONCAT(Description, ' + _db(GetTranslatedtext('shTxInvoicePayments_Reverted')) +'), '#10;
        s := s + '     CurrencyRate, '#10;
        s := s + '     Currency, '#10;
        s := s + '     Ayear, '#10;
        s := s + '     Amon, '#10;
        s := s + '     Aday, '#10;
        s := s + '     Notes, '#10;
        s := s + '     ' + _db(d.roomerMainDataSet.username) + ','#10;
        s := s + '     InvoiceIndex, '#10;
        s := s + '     Source, '#10;
        s := s + '     SourceUserId, '#10;
        s := s + '     SourceUserFullname, '#10;
        s := s + '     PAYCARD_TRACE_INDEX '#10;
        s := s + ' FROM payments '#10;
        s := s + ' WHERE  Id = (' + _db(mPaymentsId.AsInteger) + ') ' + #10;

        if cmd_bySQL(s) then
          AddInvoiceActivityLog(g.qUser, FReservation, FRoomReservation, FInvoiceIndex
            , ADD_PAYMENT, mPaymentsPayType.AsString, mPaymentsNativeAmount.AsFloat * -1, -1, mPaymentsDescription.ASString);
      end;
    end;

    LoadPayments;
    DisplayTotals;

  end;
end;

function TfrmInvoiceEdit.RoomByRoomReservation(RoomReservation: integer): String;
var
  i: integer;
begin
  result := ''; // inttostr(RoomReservation);
  for i := 0 to SelectableRooms.Count - 1 do
  begin
    if SelectableRooms[i].RoomReservation = RoomReservation then
    begin
      result := SelectableRooms[i].Room;
      Break;
    end;
  end;
  if result = '' then
  begin
    for i := 0 to SelectableExternalRooms.Count - 1 do
    begin
      if SelectableExternalRooms[i].RoomReservation = RoomReservation then
      begin
        result := SelectableExternalRooms[i].Room;
        Break;
      end;
    end;
  end;
  if result = '' then
    result := inttostr(RoomReservation);
end;

procedure TfrmInvoiceEdit.MoveItemToRoomInvoice(toRoomReservation, toReservation: integer; InvoiceIndex: integer);
var
  itemNumber: integer;
  ItemId: string; // (10)
  Description: string; // (70)
  s: string;
  CurrentRow: integer;
  NextInvoiceLine: integer;
  Btn: Word;
  UpdateOk: boolean;
  err: string;
  InvoicelineId: integer;
  lRoomAdditionalText: string;
begin
  err := '';
  chkChanged;

  CurrentRow := agrLines.row;
  if isSystemLine(CurrentRow) then
    exit;

  ItemId := trim(agrLines.Cells[col_Item, CurrentRow]);

  if ItemId = '' then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_BlankLine'));
    exit;
  end;

  itemNumber := CurrentRow;
  Description := trim(agrLines.Cells[col_Description, CurrentRow]);

  s := '';
  s := s + format(GetTranslatedText('shTx_Invoice_MoveItemToRoomInvoice'),
    [ItemId, Description, RoomByRoomReservation(toRoomReservation)]);

  Btn := MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0);
  if Btn <> mrYes then
    exit;

  SaveAnd(false);

  lRoomAdditionalText := format('(%s:', [GetTranslatedText('shRoom')]);
  if Description.Contains(lRoomAdditionalText) then
    Description := copy(Description, 1, pos(lRoomAdditionalText, Description) - 1);

  NextInvoiceLine  := NumberOfInvoiceLines(reservation, toRoomReservation, 0) + 1;

  if agrLines.Objects[cInvoiceLineAttachColumn, agrLines.row] IS TInvoiceLine then
    InvoicelineId := TInvoiceLine(agrLines.Objects[cInvoiceLineAttachColumn, agrLines.row]).LineId
  else
    InvoicelineId := -1;
  s := '';
  s := s + ' UPDATE invoicelines ' + #10;
  s := s + ' Set ' + #10;
  s := s + '   Roomreservation = ' + _db(toRoomReservation) + ' ' + #10;
  s := s + ', Reservation = ' + _db(toReservation) + ' ' + #10;
  s := s + ', itemNumber = ' + _db(NextInvoiceLine) + ' ' + #10;
  s := s + ', Description = ' + _db(Description) + ' ' + #10;
  s := s + ', InvoiceIndex = ' + _db(InvoiceIndex) + ' ' + #10;
  s := s + ', staffLastEdit= ' + _db(d.roomerMainDataSet.username) + ' ' + #10;
  if InvoicelineId = -1 then
  begin
    s := s + 'where Reservation = ' + _db(toReservation);
    s := s + '  and RoomReservation = ' + _db(FRoomReservation) + #10;
    s := s + '   and Splitnumber = 0 ' + #10;
    s := s + '   and itemNumber = ' + _db(itemNumber);
  end
  else
    s := s + 'where id = ' + _db(InvoicelineId);
  try
    UpdateOk := cmd_bySQL(s);
  except
    on e: Exception do
    begin
      err := e.message;
      UpdateOk := false;
    end;
  end;

  if not UpdateOk then
  begin
    ShowMessage(format(GetTranslatedText('shTx_Invoice_FailedGroupInvoice'), [err]));
    exit;
  end;

  Refreshdata;
end;

procedure TfrmInvoiceEdit.MoveItemToNewInvoiceIndex(rowIndex, toInvoiceIndex: integer);
var
  reservation: integer;
  RoomReservation: integer;
  itemNumber: integer;
  ItemId: string; // (10)
  Description: string; // (70)
  lRoomAdditionalText: string;
  s: string;
  NextInvoiceLine: integer;
  RoomNumber: string;

  err: string;

  invoiceLine: TInvoiceLine;

begin
  err := '';

  if FInvoiceIndex = toInvoiceIndex then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_RoomInvoice'));
    exit;
  end;

  invoiceLine := GetInvoiceLineByRow(rowIndex);
  if not assigned(invoiceLine) then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_BlankLine'));
    exit;
  end;

  if invoiceLine.IsGeneratedLine then
    exit;

  ItemId := invoiceLine.Item; // trim(agrLines.Cells[col_Item, CurrentRow]);

  reservation := FReservation;
  RoomReservation := FRoomReservation;
  itemNumber := rowIndex;
  RoomNumber := d.RR_GetRoomNr(RoomReservation); // SKODA
  Description := invoiceLine.Text; // trim(agrLines.Cells[col_Description, CurrentRow]);

  SaveAnd(false);

  lRoomAdditionalText := format('(%s:', [GetTranslatedText('shRoom')]);
  if Description.Contains(lRoomAdditionalText) then
    Description := copy(Description, 1, pos(lRoomAdditionalText, Description) - 1);

  NextInvoiceLine := NumberOfInvoiceLines(reservation, RoomReservation, 0, toInvoiceIndex) + 1;
  s := '';
  s := s + ' UPDATE invoicelines ' + #10;
  s := s + ' Set ' + #10;
  s := s + '   Roomreservation = ' + _db(RoomReservation) + ' ' + #10;
  s := s + ' , itemNumber = ' + _db(NextInvoiceLine) + ' ' + #10;
  s := s + ' , Description = ' + _db(Description) + ' ' + #10;
  s := s + ' , InvoiceIndex = ' + _db(toInvoiceIndex) + ' ' + #10;
  s := s + ' , staffLastEdit = ' + _db(d.roomerMainDataSet.username) + ' ' + #10;
  if (NOT assigned(invoiceLine)) OR (invoiceLine.LineId < 1) then
  begin
    s := s + 'where Reservation = ' + _db(reservation);
    if RoomReservation > 0 then
      s := s + '  and RoomReservation = ' + _db(RoomReservation) + #10
    else
      s := s + '  and RoomReservation = 0 ' + #10;
    s := s + '   and Splitnumber = 0 ' + #10;
    s := s + '   and itemNumber = ' + _db(itemNumber);
    s := s + '   and InvoiceIndex = ' + _db(FInvoiceIndex);
  end
  else
    s := s + 'where ID = ' + _db(invoiceLine.LineId);

  try
    cmd_bySQL(s);
    FInvoiceLinesList.Remove(invoiceLine);
    UpdateGrid;
  except
    on e: Exception do
      ShowMessage(format(GetTranslatedText('shTx_Invoice_FailedGroupInvoice'), [e.message]));
  end;
end;

procedure TfrmInvoiceEdit.actMoveItemToGroupInvoiceExecute(Sender: TObject);
var
  reservation: integer;
  RoomReservation: integer;
  itemNumber: integer;
  ItemId: string; // (10)

  Description: string; // (70)

  s: string;
  CurrentRow: integer;

  NextInvoiceLine: integer;
  RoomNumber: string;

  Btn: Word;

  rSet: TRoomerDataset;

  ItemTypeInfo: TItemTypeInfo;

  Total: Double;
  TotalWOVat: Double;
  TotalVAT: Double;
  sTotal: string;

  UpdateOk: boolean;

  err: string;

  lInvRoom: TInvoiceRoomEntity;

  list: TList<String>;
  i, l: integer;
  InvoicelineId: integer;

begin
  err := '';
  UpdateOk := false;

  Total := 0;

  if FRoomReservation = 0 then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_GroupInvoice'));
    exit;
  end;
  chkChanged;

  list := GetSelectedRows;
  try
    for l := list.Count - 1 downto 0 do
    begin
      i := IndexOfAutoGen(list[l]);
      if i >= 0 then
      begin
        agrLines.row := i;

        CurrentRow := agrLines.row;
        if isSystemLine(CurrentRow) then
        begin
          d.UpdateGroupAccountone(FReservation, FRoomReservation, FRoomReservation, True);
          continue;
        end;

        ItemId := trim(agrLines.Cells[col_Item, CurrentRow]);

        if ItemId = '' then
        begin
          continue;
        end;

        reservation := FReservation;
        RoomReservation := FRoomReservation;
        itemNumber := CurrentRow;
        RoomNumber := d.RR_GetRoomNr(RoomReservation);
        Description := trim(agrLines.Cells[col_Description, CurrentRow]);
        sTotal := trim(agrLines.Cells[col_TotalPrice, CurrentRow]);

        try
          Total := _StrToFloat(sTotal);
        except
          ShowMessage(format(GetTranslatedText('shTx_Invoice_ErrorInTotal'), [sTotal]));
          exit;
        end;

        ItemTypeInfo := d.Item_Get_ItemTypeInfo(ItemId, agrLines.Cells[col_Source, CurrentRow]);

        lInvRoom := TInvoiceRoomEntity.Create(agrLines.Cells[col_Item, CurrentRow], 1, 0,
          _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), CurrentRow, InvoiceCurrencyCode, InvoiceCurrencyRate, 0, 0, false);
        try
          TotalVAT := GetVATForItem(agrLines.Cells[col_Item, CurrentRow], Total,
            _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), lInvRoom, tempInvoiceItemList, ItemTypeInfo,
            edtCustomer.Text); // BHG
        finally
          lInvRoom.Free;
        end;
        TotalWOVat := Total - TotalVAT;

        if l = list.Count - 1 then
        begin
          s := GetTranslatedText('shTx_Invoice_MoveSelectedItemsToGroupInvoice');

          Btn := MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0);
          if Btn <> mrYes then
            exit;

          SaveAnd(false);
        end;

        Description := Description + format(' (%s: %s)', [GetTranslatedText('shRoom'), RoomNumber]);
        if agrLines.Objects[cInvoiceLineAttachColumn, agrLines.row] IS TInvoiceLine then
          InvoicelineId := TInvoiceLine(agrLines.Objects[cInvoiceLineAttachColumn, agrLines.row]).LineId
        else
          InvoicelineId := -1;
        NextInvoiceLine := NumberOfInvoiceLines(reservation, 0, 0) + 1 + RR_GetNumberGroupInvoices(reservation);
        s := '';
        s := s + ' UPDATE invoicelines ' + #10;
        s := s + ' Set ' + #10;
        s := s + '   Roomreservation = 0 ' + #10;
        s := s + ' , itemNumber = ' + _db(NextInvoiceLine) + ' ' + #10;
        s := s + ' , Description = ' + _db(Description) + ' ' + #10;
        s := s + ' , staffLastEdit = ' + _db(d.roomerMainDataSet.username) + ' ' + #10;
        if InvoicelineId = -1 then
        begin
          s := s + 'where Reservation = ' + _db(reservation);
          s := s + '  and RoomReservation = ' + _db(RoomReservation);
          s := s + '   and Splitnumber = 0 ' + #10;
          s := s + '   and itemNumber = ' + _db(itemNumber);
        end
        else
          s := s + 'where id = ' + _db(InvoicelineId);

        try
          UpdateOk := cmd_bySQL(s);
        except
          on e: Exception do
          begin
            err := e.message;
            UpdateOk := false;
          end;
        end;

        if not UpdateOk then
        begin
          ShowMessage(format(GetTranslatedText('shTx_Invoice_FailedGroupInvoice'), [err]));
          exit;
        end;

        rSet := CreateNewDataSet;
        try
          s := format(select_Invoice_actItemToGroupInvoiceExecute, [reservation]);
          hData.rSet_bySQL(rSet, s);
          rSet.first;
          if not rSet.eof then
          begin
            rSet.edit;
            rSet.FieldByName('Total').Value := Total + rSet.FieldByName('Total').AsFloat;
            rSet.FieldByName('TotalWOVAT').Value := TotalWOVat + rSet.FieldByName('TotalWOVAT').AsFloat;
            rSet.FieldByName('TotalVAT').Value := TotalVAT + rSet.FieldByName('TotalVAT').AsFloat;
            rSet.post; // ID ADDED
          end;

        finally
          FreeAndNil(rSet);
        end;

        DeleteRow(agrLines, agrLines.row);
        AddEmptyLine;
      end;
    end;
  finally
    list.Free;
  end;
  RefreshData;
end;

function TfrmInvoiceEdit.CreateProformaID: integer;
  function GetMinutesSinceMidnightAsString: String;
  begin
    result := ZerosInFront(inttostr(MinutesSinceMidnight), 4);
  end;

begin
  if (FReservation = 0) AND (FRoomReservation = 0) then
    result := GenerateProformaInvoiceNumber
  else if FRoomReservation > 0 then // 1,234,567,890
    result := strToInt(GetMinutesSinceMidnightAsString + '000000') + FRoomReservation
  else
    result := strToInt(GetMinutesSinceMidnightAsString + '000000') + FReservation;
  if result < cMaxFinalInvoiceNr then
    result := cMaxFinalInvoiceNr + 1 + result;
end;

procedure TfrmInvoiceEdit.RemoveProformaInvoice(ProformaInvoiceNumber: integer);
var
  sql: String;
  i: integer;
begin
  for i := LOW(REMOVE_CURRENT_PROFORMA_INVOICE) to HIGH(REMOVE_CURRENT_PROFORMA_INVOICE) do
  begin
    sql := format(REMOVE_CURRENT_PROFORMA_INVOICE[i], [ProformaInvoiceNumber]);
    d.roomerMainDataSet.DoCommand(sql);
  end;
end;

procedure TfrmInvoiceEdit.PrintProforma;
begin
  PROFORMA_INVOICE_NUMBER := CreateProformaID;
  try
    if SaveInvoice(PROFORMA_INVOICE_NUMBER, stProforma) then
    begin
      AddInvoiceActivityLog(g.qUser, FReservation, FRoomReservation, ord(FInvoiceType), PRINT_PROFORMA, '',
                            FInvoiceLinesList.TotalOnInvoice.ToNative, PROFORMA_INVOICE_NUMBER,
                            Format('Printing Proforma invoice [%d] for roomreservation [%d/%d]', [PROFORMA_INVOICE_NUMBER, FReservation, FRoomReservation]));
      ViewInvoice2(PROFORMA_INVOICE_NUMBER, True, false, false, false, zEmailAddress);
    end;
  finally
    RemoveProformaInvoice(PROFORMA_INVOICE_NUMBER);
  end;
end;

procedure TfrmInvoiceEdit.CopyPaymentsForProforma(aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
var
  s: string;
begin
  s := '';

  s := s + 'insert into payments ( '#10;
  s := s + '     Reservation, '#10;
  s := s + '     RoomReservation, '#10;
  s := s + '     Person, '#10;
  s := s + '     Customer, '#10;
  s := s + '     AutoGen, '#10;
  s := s + '     InvoiceNumber, '#10;
  s := s + '     PayDate, '#10;
  s := s + '     PayType, '#10;
  s := s + '     Amount, '#10;
  s := s + '     Description, '#10;
  s := s + '     CurrencyRate, '#10;
  s := s + '     Currency, '#10;
  s := s + '     TypeIndex, '#10;
  s := s + '     AYear, '#10;
  s := s + '     AMon, '#10;
  s := s + '     ADay, '#10;
  s := s + '     InvoiceIndex, '#10;
  s := s + '     Notes, '#10;
  s := s + '     dtCreated, '#10;
  s := s + '     staff, '#10;
  s := s + '    Source, '#10;
  s := s + '    SourceUserId, '#10;
  s := s + '    SourceUserFullname '#10;
  s := s + '     ) '#10;
  s := s + 'select '#10;
  s := s + '    Reservation, '#10;
  s := s + '    RoomReservation, '#10;
  s := s + '    Person, '#10;
  s := s + '    Customer, '#10;
  s := s + '    Autogen, '#10;
  s := s + '    %d, '#10;
  s := s + '    Paydate, '#10;
  s := s + '    Paytype, '#10;
  s := s + '    Amount, '#10;
  s := s + '    Description, '#10;
  s := s + '    CurrencyRate, '#10;
  s := s + '    Currency, '#10;
  s := s + '    TypeIndex, '#10;
  s := s + '    aYear, '#10;
  s := s + '    aMon, '#10;
  s := s + '    aDay, '#10;
  s := s + '    InvoiceIndex, '#10;
  s := s + '    Notes, '#10;
  s := s + '    dtCreated, '#10;
  s := s + '    staff, '#10;
  s := s + '    Source, '#10;
  s := s + '    SourceUserId, '#10;
  s := s + '    SourceUserFullname '#10;
  s := s + 'from payments '#10;
  s := s + 'where '#10;
  s := s + '    Reservation=%d '#10;
  s := s + '    AND ROomReservation=%d '#10;
  s := s + '    AND Invoicenumber=-1 '#10;
  s := s + '    AND InvoiceIndex=%d '#10;
  s := s + '    AND person=%d '#10;

  s := format(s, [aInvoiceNumber, FReservation, FRoomReservation, FInvoiceIndex, ord(FInvoiceType)]);
  aExecPlan.AddExec(s);
end;

function TfrmInvoiceEdit.IsCashInvoice: boolean;
begin
  result := ((FReservation + FRoomReservation) = 0)
end;

function TfrmInvoiceEdit.chkChanged: boolean;
begin
  result := (not IsCashInvoice) and (FInvoiceLinesList.IsChanged or HeaderChanged or (DeletedLines.Count > 0));
  btnSaveChanges.Visible := result;
  actSave.Enabled := Result;
end;

procedure TfrmInvoiceEdit.LoadRoomListForCurrentReservation(reservation: integer);
var
  sql: String;
  rSet: TRoomerDataset;
  Room: TInvoiceRoomEntity;
begin
  SelectableRooms.Clear;
  sql := format
    ('SELECT DISTINCT Room, RoomReservation, Reservation FROM roomsdate WHERE Reservation=%d AND ResFlag NOT IN (''X'', ''C'')',
    [reservation]);
  rSet := CreateNewDataSet;
  try
    if hData.rSet_bySQL(rSet, sql, false) then
    begin
      rSet.first;
      while NOT rSet.eof do
      begin
        Room := TInvoiceRoomEntity.Create;
        Room.Room := rSet['Room'];
        Room.RoomReservation := rSet['RoomReservation'];
        Room.reservation := rSet['Reservation'];
        SelectableRooms.Add(Room);
        rSet.Next;
      end;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmInvoiceEdit.LoadRoomListForOtherReservations(reservation: integer);
var
  sql: String;
  rSet: TRoomerDataset;
  Room: TInvoiceRoomEntity;
begin
  SelectableExternalRooms.Clear;
  sql := format('SELECT DISTINCT rd.Room, rd.Reservation, rd.RoomReservation '#10 + ' FROM roomsdate rd '#10 +
    ' join rooms r on r.room=rd.room '#10 + ' WHERE ADate=''' + dateToSqlString(frmMain.dtDate.Date) +
    ''' AND Reservation != %d AND ResFlag IN (''P'',''G'')', [reservation]) + #10 + ' ORDER BY rd.room ';
  rSet := CreateNewDataSet;
  try
    if hData.rSet_bySQL(rSet, sql, false) then
    begin
      rSet.first;
      while NOT rSet.eof do
      begin
        Room := TInvoiceRoomEntity.Create;
        Room.Room := rSet['Room'];
        Room.RoomReservation := rSet['RoomReservation'];
        Room.reservation := rSet['Reservation'];
        SelectableExternalRooms.Add(Room);
        rSet.Next;
      end;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmInvoiceEdit.LoadRoomListForAllReservations;
var
  sql: String;
  rSet: TRoomerDataset;
  Room: TInvoiceRoomEntity;
begin
  SelectableExternalRooms.Clear;
  sql := 'SELECT DISTINCT Room, Reservation, RoomReservation FROM roomsdate WHERE ADate=''' +
    dateToSqlString(frmMain.dtDate.Date) + ''' AND ResFlag IN (''P'',''G'')';
  rSet := CreateNewDataSet;
  try
    if hData.rSet_bySQL(rSet, sql, false) then
    begin
      rSet.first;
      while NOT rSet.eof do
      begin
        Room := TInvoiceRoomEntity.Create;
        Room.Room := rSet['Room'];
        Room.RoomReservation := rSet['RoomReservation'];
        Room.reservation := rSet['Reservation'];
        SelectableExternalRooms.Add(Room);
        rSet.Next;
      end;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmInvoiceEdit.FillRoomsInMenu(mnuItem: TMenuItem);
var
  i: integer;
  Item, subItem: TMenuItem;
  l: integer;
begin
  if (mnuItem = mnuItemToRoomInvoice) then
  begin
    LoadRoomListForCurrentReservation(FReservation);
    mnuItem.Clear;
    for i := 0 to SelectableRooms.Count - 1 do
    begin
      Item := TMenuItem.Create(nil);
      Item.Caption := SelectableRooms[i].Room;
      Item.Tag := i;
      mnuItem.Add(Item);

      Item.Clear;
      for l := 0 to mnuInvoiceIndex.Items.Count - 1 do
      begin
        subItem := TMenuItem.Create(nil);
        subItem.Caption := mnuInvoiceIndex.Items[l].Caption;
        subItem.Tag := mnuInvoiceIndex.Items[l].Tag;
        subItem.OnClick := MoveSelectedLinesToRoomInvoiceIndex;
        Item.Add(subItem);
        subItem.Enabled := subItem.Tag >= 0;
      end;
    end;
  end;
end;

procedure TfrmInvoiceEdit.FillExternalRoomsInMenu(mnuItem: TMenuItem);
var
  i: integer;
  Item, subItem: TMenuItem;
  l: integer;
begin
  if (mnuItem = mnuMoveItemToAnyOtherRoomAndInvoiceIndex) then
  begin
    LoadRoomListForOtherReservations(FReservation);
    mnuItem.Clear;
    for i := 0 to SelectableExternalRooms.Count - 1 do
    begin
      Item := TMenuItem.Create(nil);
      Item.Caption := SelectableExternalRooms[i].Room;
      Item.Tag := i;
      mnuItem.Add(Item);

      Item.Clear;
      for l := 0 to mnuInvoiceIndex.Items.Count - 1 do
      begin
        subItem := TMenuItem.Create(nil);
        subItem.Caption := mnuInvoiceIndex.Items[l].Caption;
        subItem.Tag := mnuInvoiceIndex.Items[l].Tag;
        subItem.OnClick := ExternalRoomsClick;
        Item.Add(subItem);
        subItem.Enabled := subItem.Tag >= 0;
      end;
    end;
  end;
end;

procedure TfrmInvoiceEdit.FillAllRoomsInMenu(mnuItem: TMenuItem);
var
  i: integer;
  Item: TMenuItem;
begin
  LoadRoomListForAllReservations;
  mnuItem.Clear;
  for i := 0 to SelectableExternalRooms.Count - 1 do
  begin
    Item := TMenuItem.Create(nil);
    Item.Caption := SelectableExternalRooms[i].Room;
    Item.Tag := i;
    mnuItem.Add(Item);
    Item.OnClick := TransferRoomToAnyRoomsClick;
  end;
end;

procedure TfrmInvoiceEdit.memExtraTextChange(Sender: TObject);
begin
  HeaderChanged := True;
end;

procedure TfrmInvoiceEdit.mnuMoveItemPopup(Sender: TObject);
begin
  FillRoomsInMenu(mnuItemToRoomInvoice);
  FillExternalRoomsInMenu(mnuMoveItemToAnyOtherRoomAndInvoiceIndex);

  actMoveItemToGroupInvoice.Enabled := (FRoomReservation > 0);
end;

procedure TfrmInvoiceEdit.mnuMoveRoomPopup(Sender: TObject);
var
  l: integer;
  subItem: TMenuItem;
begin
  FillAllRoomsInMenu(mnuTransferRoomRentToDifferentRoom);
  actMoveRoomToGroupInvoice.Visible := (FRoomReservation > 0);
  actMoveRoomToRoomInvoice.Visible :=  (FRoomReservation = 0);

  mnuMoveRoomToInvoiceIndex.Clear;
  for l := 0 to mnuInvoiceIndex.Items.Count - 1 do
  begin
    subItem := TMenuItem.Create(nil);
    subItem.Caption := mnuInvoiceIndex.Items[l].Caption;
    subItem.Tag := mnuInvoiceIndex.Items[l].Tag;
    subItem.OnClick := mnuMoveRoomToInvoiceIndexClick;
    mnuMoveRoomToInvoiceIndex.Add(subItem);
    subItem.Enabled := subItem.Tag >= 0;
  end;
end;

procedure TfrmInvoiceEdit.mnuMoveRoomToInvoiceIndexClick(Sender: TObject);
var
  mnu: TMenuItem;
begin
  mnu := TMenuItem(Sender);
  if (mnu.Tag <> FInvoiceIndex) then
  begin
    MoveSelectedLinesToInvoiceIndex(mnu.Tag);
    UpdateGrid;
  end;
end;

procedure TfrmInvoiceEdit.timCloseInvoiceTimer(Sender: TObject);
begin
  timCloseInvoice.Enabled := false;
  close;
end;

procedure TfrmInvoiceEdit.ClearGrid;
begin
  DeletedLines.Clear;
  ClearRoomInfoObjects;
  ClearInvoiceLines;
  NullifyGrid;
end;


//**********************************************************************************************************
// NOTE on use of Currency in invoiceaddressees table
//
// Currency of the invoice per invoiceindex is historically stored in the invoiceaddressees table
// because invoicehead does not have a invoiceindex field
//
// TODO: Redesign invoicehead to contain header information PER INVOICEINDEX and include currency and rate and ....
//
//**********************************************************************************************************


end.
