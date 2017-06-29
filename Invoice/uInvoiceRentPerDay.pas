unit uInvoiceRentPerDay;

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
  Generics.Collections,
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
  cxGrid,
  sCheckBox,
  sButton,
  sGroupBox,
  sEdit,
  sLabel,
  sPanel,
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
  uCurrencyHandlersMap;

type
  TCreditType = (ctManual, ctReference, ctErr);
  TInvoiceSaveType = (stProvisionally, stProforma, stDefinitive);

{$M+}
  TRoomInfoList = TObjectlist<TInvoiceRoomEntity>;

{$M+}

  /// <summary>
  /// Object attached to a gridline of the invoiceform, containing all Invoice related info shown in that gridline
  /// Notice that all amounts are in hotel-native currency
  // TODO: Merge this class with TInvoiceItemEntity
  /// </summary>
  /// <remarks>
  /// Example of influence of properties VisibleOnInvoice and TotalIsIncludedInParent:
  ///
  /// Room 1000,= 5% vat, Breakfast 30,= 10% vat
  ///
  /// |  Visible | Included | Room | Brkf | Room | Brkf | Room | Brkf | Room | Brkf |
  /// |          |          | Inv  | Inv  | Rev  | Rev  | VAT  | VAT  | VAT  | VAT  |
  /// |          |          |      |      |      |      | inv  | inv  | rev  | rev  |
  /// =============================================================================
  /// |    F     |    F     | 1030 |    0 | 1000 |   30 | 53   |   0  | 50   |   3  |
  /// |    F     |    T     | 1000 |    0 |  970 |   30 | 51,5 |   0  | 48,5 |   3  |
  /// |    T     |    T     |  970 |   30 |  970 |   30 | 48,5 |   3  | 48,5 |   3  |
  /// |    T     |    F     | 1000 |   30 | 1000 |   30 | 50   |   3  | 50   |   3  |
  ///
  /// </remarks>
  TInvoiceLine = class(TObject)
  strict private
    FInvoiceLineIndex: integer;
    FItem: string;
    FText: string;
    FNumber: Double; // -96
    FPrice: Double;
    FTotal: Double;
    FDate: TDate;
    FAuto: boolean;
    FReference: string;
    FSource: string;
    FIspackage: boolean;
    FNoGuests: integer;
    FConfirmDate: TDateTime;
    FConfirmAmount: Double;
    FitemIndex: integer;
    FrrAlias: integer;
    FAutoGen: string;
    FLineId: integer;
    FVisibleOnInvoice: boolean;
    FVATCode: string;
    FVATPercentage: Double;
    FParentInvoiceLine: TInvoiceLine;
    FChildInvoiceLines: TList<TInvoiceLine>;
    FROomEntity: TInvoiceRoomEntity;
    FInvoiceNumber: integer;
    FChanged: boolean;
    FCurrency: string;
    FTotalIsIncludedInParent: boolean;

  private
    function GetRevenueNativeCurrency: Double;
    function GetAmountOnInvoice: Double;
    function GetTotal: Double;
    function GetVatOnRevenueNativeCurrency: Double;
    procedure GetPurchaseDate(const Value: TDate);
    function GetItemKind: TItemKind;
    function GetVatOnInvoice: Double;
    procedure SetVATCode(const Value: string);
    function GetTotalNativeCurrency: Double;
    function GetPriceNativeCurrency: Double;
    function GetAmountOnInvoiceNativeCurrency: Double;
    function GetVatOnInvoiceNativeCurrency: Double;
    function GetPrice: Double;
    function GetPriceOnInvoice: Double;
    function GetPriceOnInvoiceNativeCurrency: Double;
    function GetTotalRevenue: Double;
    function GetRevenuePrice: Double;
    function GetParentReservation: integer;
    function GetParentRoomReservation: integer;
    procedure SetParentInvoiceLine(const Value: TinvoiceLine);

  public
    constructor Create(aIndex, _id: integer);
    destructor Destroy; override;
    /// <summary>
    /// Indicates whether or not the "VisibleOnInvoice" functionality is available for this line
    /// At this moment only line that are generated and linked to a roomrent item can be made invisible
    /// </summary>
    function CanBeHiddenFromInvoice: boolean;
    property TotalNativeCurrency: Double read GetTotalNativeCurrency;
    /// <summary>
    /// Revenue total in selected currency, including VAT for this item, calculated as Price * Number
    /// </summary>
    property Total: Double read GetTotal;
    /// <summary>
    /// Amount which will be visible on the invoice in selected currency.
    /// Dependent on the VisibleOnInvoice property and on ChildInvoiceLines which are not visible on the invoice
    /// See table in class documentation
    /// </summary>
    property AmountOnInvoice: Double read GetAmountOnInvoice;
    property AmountOnInvoiceNativeCurrency: Double read GetAmountOnInvoiceNativeCurrency;
    /// <summary>
    /// Price which will be visible on the invoice in selected currency. Calculated as AmountOnInvoice / Number
    /// </summary>
    property PriceOnInvoice: Double read GetPriceOnInvoice;
    property PriceOnInvoiceNativeCurrency: Double read GetPriceOnInvoiceNativeCurrency;

    property RevenuePrice: Double read GetRevenuePrice;
    /// <summary>
    /// Total administrative revenue for this item, in selected currency
    /// Consists of the Total minus the total of all not-visible childlines
    /// See table in class documentation
    /// </summary>
    property TotalRevenue: Double read GetTotalRevenue;
    /// <summary>
    /// Total administrative revenue for this item, in native currency
    /// Consists of the Total minus the total of all not-visible childlines
    /// See table in class documentation
    /// </summary>
    property RevenueNativeCurrency: Double read GetRevenueNativeCurrency;
    /// <summary>Order index of line in invoice</summary>
    property InvoiceLineIndex: integer read FInvoiceLineIndex write FInvoiceLineIndex;
    /// <summary>This invoicelines "belongs" to or a child of invoicelines with this InvoicelineIndex </summary>
    property Parent: TinvoiceLine read FParentInvoiceLine write SetParentInvoiceLine;
    /// <summary>
    /// List of TInvoiceLineItems that are derived from this line. If any of these child lines are not VisibleOnInvoice then
    /// their invoice-totals are added to the parent line
    /// </summary>
    property ChildInvoiceLines: TList<TInvoiceLine> read FChildInvoiceLines;
    property RoomEntity: TInvoiceRoomEntity read FROomEntity write FROomEntity;

    property ItemKind: TItemKind read GetItemKind;
    /// <summary>
    /// Calculated VAT based on revenue of this item, in native currency
    /// See table in class documentation
    /// </summary>
    property VATOnRevenueNativeCurrency: Double read GetVatOnRevenueNativeCurrency;
    /// <summary>
    /// Calculated VAT on the invoice for this item, in selected currency
    /// See table in class documentation
    /// </summary>
    property VATOnInvoice: Double read GetVatOnInvoice;
    /// <summary>
    /// Calculated VAT on the invoice for this item, in native currency
    /// See table in class documentation
    /// </summary>
    property VATOnInvoiceNativeCurrency: Double read GetVatOnInvoiceNativeCurrency;
    property PriceNativeCurrency: Double read GetPriceNativeCurrency;
    property Changed: boolean read FChanged write FChanged;
    property ParentReservation: integer read GetParentReservation;
    property ParentRoomReservation: integer read GetParentRoomReservation;
  published
    /// <summary>Id in invoicelines table of this invoiceline item, if <= 0 then this invoiceline instance does not have
    /// a record in the table invoicelines </summary>
    property LineId: integer read FLineId write FLineId;
    property InvoiceNumber: integer read FInvoiceNumber write FInvoiceNumber;
    property Item: string read FItem write FItem;
    property Text: string read FText write FText;

    /// <summary>
    /// Number of (or quantity) items for this invoiceline
    /// </summary>
    property Number: Double read FNumber write FNumber;
    /// <summary>
    /// Price per item in selected currency
    /// </summary>
    property Price: Double read GetPrice write FPrice;
    /// <summary>
    /// Selected currency for this invoiceline
    /// </summary>
    property Currency: string read FCurrency write FCurrency;
    property VATCode: string read FVATCode write SetVATCode;
    property VATPercentage: Double read FVATPercentage;
    property Reference: string read FReference write FReference;
    property Source: string read FSource write FSource;
    property isPackage: boolean read FIspackage write FIspackage;
    property noGuests: integer read FNoGuests write FNoGuests;
    property ConfirmDate: TDateTime read FConfirmDate write FConfirmDate;
    property ConfirmAmount: Double read FConfirmAmount write FConfirmAmount;
    property itemIndex: integer read FitemIndex write FitemIndex;
    property rrAlias: integer read FrrAlias write FrrAlias;
    property PurchaseDate: TDate read FDate write GetPurchaseDate;
    /// <summary>
    /// True if this line has not been retrieved from the invoicelines table but is generated based on i.e. roomsdate
    /// </summary>
    property IsGeneratedLine: boolean read FAuto write FAuto;
    property AutoGen: string read FAutoGen write FAutoGen;
    /// <summary>
    /// True if this line should be printed on the actual invoice. This setting influences the amounts on invoice, revenues and calculated VAT
    /// for this line and its parentline (if present)
    /// </summary>
    property VisibleOnInvoice: boolean read FVisibleOnInvoice write FVisibleOnInvoice;
    /// <summary>
    /// If true then the total amount of this invoicelineitem is originally included in its parent
    /// When this line is set VisibleOnInvoice then the amount of the parent will be decreased with the amount of this line
    /// </summary>
    property TotalIsIncludedInParent: boolean read FTotalIsIncludedInParent write FTotalIsIncludedInParent;
  end;

  TInvoiceLineList = class(TObjectlist<TInvoiceLine>)
  private
    function GetTotalOnInvoiceNativeCurrency: Double;
    function GetTotalVatOnInvoice: Double;
    function GetTotalCityTaxRevenues: Double;
    function GetIsChanged: boolean;
    function GetCityTaxUnitCount: Double;
  public
    procedure SetAllVisibleOnInvoiceTo(aVisible: boolean; aItemKindSet: TItemKindSet = [ikRoomRentDiscount, ikStayTax, ikBreakfast]);
    procedure SortOnInvoiceLineIndex;
    /// <summary>
    /// Calculate the total native amount including VAT
    /// </summary>
    property TotalOnInvoiceNativeCurrency: Double read GetTotalOnInvoiceNativeCurrency;
    /// <summary>
    /// Calculate the total sum of VAT in native currency
    /// </summary>
    property TotalVatOnInvoiceNativeCurrency: Double read GetTotalVatOnInvoice;
    property TotalCityTaxRevenues: Double read GetTotalCityTaxRevenues;
    property CityTaxUnitCount: Double read GetCityTaxUnitCount;
    property IsChanged: boolean read GetIsChanged;
  end;

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

  TfrmInvoiceRentPerDay = class(TForm)
    FriendlyStatusBar1: TsStatusBar;
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
    edtDisplayCurrency: TsEdit;
    actInvoiceActions: TActionList;
    actSaveAndExit: TAction;
    actPrintInvoice: TAction;
    actPrintProforma: TAction;
    actInvoiceProperties: TAction;
    actAddDownPayment: TAction;
    actInfo: TAction;
    actAddLine: TAction;
    actRemoveSelected: TAction;
    actMoveRoomToTemp: TAction;
    actMoveItemToTemp: TAction;
    actMoveItemToGroupInvoice: TAction;
    edtRate: TsEdit;
    clabRate: TsLabel;
    timCloseInvoice: TTimer;
    edtInvRefrence: TsLabel;
    clabRefrence: TsLabel;
    GuestName1: TMenuItem;
    Refrence1: TMenuItem;
    btnGetCurrency: TsButton;
    clabInvoice: TsLabel;
    edtRoomGuest: TsLabel;
    clabRoomGuest: TsLabel;
    StoreMain: TcxPropertiesStore;
    pnlTotalsAndPayments: TsPanel;
    memExtraText: TMemo;
    pnlLineButtons: TsPanel;
    pnlLinesGrid: TsPanel;
    agrLines: TAdvStringGrid;
    btnExit: TsButton;
    btnInvoice: TsButton;
    btnProforma: TsButton;
    labTmpStatus: TsLabel;
    sPanel2: TsPanel;
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
    clabForeignCurrency: TsLabel;
    edtForeignCurrency: TsEdit;
    grbInclutedTaxes: TsGroupBox;
    labLodgingTax: TsLabel;
    labLodgingTaxNights: TsLabel;
    labTaxNights: TsLabel;
    actAddPackage: TAction;
    actAddRoom: TAction;
    chkShowPackage: TsCheckBox;
    mPayments: TdxMemData;
    mPaymentsPayDate: TDateField;
    mPaymentsPayType: TWideStringField;
    mPaymentsAmount: TFloatField;
    mPaymentsDescription: TWideStringField;
    mPaymentsPayGroup: TWideStringField;
    mPaymentsMemo: TMemoField;
    mPaymentsconfirmDate: TDateTimeField;
    mPaymentsid: TIntegerField;
    mnuMoveItem: TPopupMenu;
    mnuMoveRoom: TPopupMenu;
    mnuItemToGroupInvoice: TMenuItem;
    mnuItemToRoomInvoice: TMenuItem;
    mnuMoveRoomRentFromRoomInvoiceToGroup: TMenuItem;
    mnuMoveRoomRentFromGroupToNormalRoomInvoice: TMenuItem;
    pnlLnes: TsPanel;
    pnlInvoiceIndices: TsPanel;
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
    mPaymentsInvoiceIndex: TIntegerField;
    lblResNr: TsLabel;
    edResNr: TsLabel;
    pnlRoomButtons: TsPanel;
    btnMoveRoom: TsButton;
    btnAddRoom: TsButton;
    pnlItemButtons: TsPanel;
    btnMoveItem: TsButton;
    btnAddItem: TsButton;
    pnlButtonRight: TsPanel;
    pnlPaymentButtons: TsPanel;
    btnAddDownPayment: TsButton;
    btnEditDownPayment: TsButton;
    btnDeleteDownpayment: TsButton;
    sPanel4: TsPanel;
    btnToggleLodgingTax: TsButton;
    btnSaveChanges: TsButton;
    gbxHeader: TsGroupBox;
    clabCustomer: TsLabel;
    clabPId: TsLabel;
    clabCountry: TsLabel;
    clabAddress: TsLabel;
    cLabName: TsLabel;
    rgrInvoiceType: TsRadioGroup;
    edtCustomer: TsEdit;
    edtPersonalId: TsEdit;
    edtName: TsEdit;
    edtAddress1: TsEdit;
    edtAddress2: TsEdit;
    edtAddress3: TsEdit;
    edtAddress4: TsEdit;
    btnClearAddresses: TsButton;
    btnGetCustomer: TsButton;
    mnuRoomToTemp: TMenuItem;
    mnuItemToTemp: TMenuItem;
    actToggleLodgingTax: TAction;
    actEditDownpayment: TAction;
    actDeleteDownPayment: TAction;
    btnRemoveSelected: TsButton;
    actMoveRoomToGroupInvoice: TAction;
    actMoveRoomToRoomInvoice: TAction;
    sPanel1: TsPanel;
    btnReservationNotes: TsButton;
    btnShowOnInvoice: TsButton;
    mnuShowOnInvoice: TPopupMenu;
    acShowAllCTax: TAction;
    acShowAlllBreakfasts: TAction;
    acShowAllDiscounts: TAction;
    acHideAllCTax: TAction;
    acHideAllBreakfasts: TAction;
    acHideAllDiscounts: TAction;
    C1: TMenuItem;
    B1: TMenuItem;
    D1: TMenuItem;
    mnuShowAllCTax: TMenuItem;
    mnuHideallCitytax: TMenuItem;
    mnuShowallincludedbreakfasts: TMenuItem;
    mnuHideallincludedbreakfasts: TMenuItem;
    mnuShowalldiscounts: TMenuItem;
    mnuHidealldiscounts: TMenuItem;
    procedure FormCreate(Sender: TObject);
    procedure agrLinesMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure edtCustomerDblClick(Sender: TObject);
    procedure agrLinesGetEditText(Sender: TObject; ACol, ARow: integer; var Value: string);
    procedure edtDisplayCurrencyDblClick(Sender: TObject);
    procedure agrLinesDrawCell(Sender: TObject; ACol, ARow: integer; Rect: TRect; State: TGridDrawState);
    procedure rgrInvoiceTypeClick(Sender: TObject);
    procedure actSaveAndExitExecute(Sender: TObject);
    procedure actPrintInvoiceExecute(Sender: TObject);
    procedure actPrintProformaExecute(Sender: TObject);
    procedure actAddDownPaymentExecute(Sender: TObject);
    procedure actInfoExecute(Sender: TObject);
    procedure actAddLineExecute(Sender: TObject);
    procedure actRemoveSelectedExecute(Sender: TObject);
    procedure actMoveRoomToTempExecute(Sender: TObject);
    procedure actMoveItemToTempExecute(Sender: TObject);
    procedure actMoveItemToGroupInvoiceExecute(Sender: TObject);
    procedure timCloseInvoiceTimer(Sender: TObject);
    procedure actToggleLodgingTaxClick(Sender: TObject);
    procedure btnClearAddressesClick(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure agrLinesGetCellColor(Sender: TObject; ARow, ACol: integer; AState: TGridDrawState; ABrush: TBrush;
      AFont: TFont);
    procedure edtCustomerChange(Sender: TObject);
    procedure actEditDownPaymentClick(Sender: TObject);
    procedure actDeleteDownpaymentClick(Sender: TObject);
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
    procedure N91Click(Sender: TObject);
    procedure shpInvoiceIndex0MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure shpInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
    procedure shpInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState; var Accept: boolean);
    procedure tvPaymentsMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure tvPaymentsCellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
      AButton: TMouseButton; AShift: TShiftState; var AHandled: boolean);
    procedure btnSaveChangesClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure CheckBoxClick(Sender: TObject; ACol, ARow: integer; State: boolean);
    procedure agrLinesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure S1Click(Sender: TObject);
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
  private
    { Private declarations }

    DeletedLines: TList<integer>;
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

    zbRoomRentinTemp: boolean;
    FInvoiceLinesList: TInvoiceLineList;

    // Global currency and Rate
    zCurrentCurrency: string;
    zCurrencyRate: Double;
    zNativeCurrency: string;

    zErr: boolean;

    tempInvoiceNo: integer;

    zStayTaxIncluded: boolean;

    zRefNum: integer;
    zbDoingReference: boolean;

    zCreditType: TCreditType;

    tempInvoiceItemList: TInvoiceItemEntityList;

    selectedRoomReservation: integer;

    zLocation: string;
    FInvoiceIndex: integer;

    FReservation: integer;
    FRoomReservation: integer;
    FHeaderChanged: boolean;
    FCurrencyhandlersMap: TCurrencyhandlersMap;
    FStayTaxEnabled: boolean;

    procedure LoadInvoice;
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
    function GetInvoiceLineCount: integer;

    /// <summary>
    /// Create a new TInvoiceLine object and add this to InvoiceLinesList collection
    /// </summary>
    function AddLine(LineId: integer; aParentInvoice: TInvoiceLine; sItem, sText: string; iNumber: Double; aPrice: Double;
      const aCurrency: string; const VATCode: string; PurchaseDate: TDate; bAuto: boolean; Refrence, Source: string;
      isPackage: boolean; noGuests: integer; ConfirmDate: TDateTime; ConfirmAmount: Double; rrAlias: integer;
      AutoGen: string; itemIndex: integer = 0; aVisibleOnInvoice: boolean = true): TInvoiceLine;

    /// <summary>
    /// Create a RoomInfo object with supplied parameters and attach to a new row in the grid<br/>
    /// A new TInvoiceLine object is also created for the roomrent and a new TInvoiceLine object is created
    /// for the supplied discount (if any). The Invoiceline objects are not attached to the grid.
    /// </summary>
    procedure AddRoom(const aRoom: String; aRoomPrice: Double; aCurrency: string; aFromDate: TDate; aToDate: TDate;
      aDayCount: integer; const aDescription: string; aGetGuestName: boolean; aRoomReservation: integer;
      aDiscountAmount: Double; aDiscountIsPercentage: boolean; const aDiscountText: string; const aGuestName: String;
      aNumGuests: integer; aNumChildren: integer; aIsPackage: boolean; aRRAlias: integer;
      aBeakfastIncluded: boolean);

    Procedure AddRoomTaxToLinesAndGrid(totalTax: Double; TaxUnits: Double; taxItem: string; aPurchaseDate: TDate;
      iAddAt: integer = 0; aParentInvoice: TInvoiceLine = nil; aIsIncludedInParent: boolean = false);
    procedure ClearInvoiceLines;
    function getDownPayments: Double;

    procedure DisplayMem(zrSet: TRoomerDataset);
    procedure DisplayGuestName(zrSet: TRoomerDataset);

    /// <summary>
    /// Display the info of TInvoiceLine object in the grid and attach it to the row<br/>
    /// </summary>
    function DisplayLine(aInvoiceLine: TInvoiceLine; ARow: integer): integer; overload;

    procedure UpdateGrid;

    procedure DisplayTotals(editCol: integer = -1; editRow: integer = -1; Value: Double = 0.00);
    /// <summary>
    /// Move Invoicelines for property RoomReservation from tmpinvoicelines table to invoicelines table
    /// </summary>
    procedure RestoreTMPInvoicelines;

    procedure SaveHeader(aInvoiceNumber: integer; aExecutionPlan: TRoomerExecutionPlan; const aInvoiceLocation: string = '');

    function SaveInvoice(aInvoiceNumber: integer; aSaveType: TInvoiceSaveType; const aInvoiceLocation: string = ''): boolean;

    procedure ExecuteCurrencyChange(const aOldCurrency: string; const aNewCurrency: string);
    procedure MarkOriginalInvoiceAsCredited(iInvoice: integer);

    function isSystemLine(row: integer): boolean;
    function GatherPayments(PayLines: TStringList): Double;
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
    procedure ItemToTemp(confirm: boolean);
    procedure NullifyGrid;

    Procedure InitInvoiceGrid;
    function GenerateInvoiceNumber: integer;
    procedure AddDeleteFromInvoiceToExecutionPlan(aExecutionPlan: TRoomerExecutionPlan);

    function LocateDate(recordSet: TRoomerDataset; field: String; Value: TDate): boolean;
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
    procedure SetInvoiceIndex(const Value: integer);
    function IfInvoiceChangedThenOptionallySave(Ask: boolean = True): boolean;
    procedure MoveItemToNewInvoiceIndex(rowIndex, toInvoiceIndex: integer);
    procedure MoveRoomToNewInvoiceIndex(toInvoiceIndex: integer);
    procedure UpdateInvoiceIndexTabs;
    function GetInvoiceIndexPanel(Index: integer): TsPanel;
    procedure SetInvoiceIndexPanelsToZero;
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
    procedure RemoveCurrentProformeInvoice(ProformaInvoiceNumber: integer);
    procedure DeleteLinesInList(ExecutionPlan: TRoomerExecutionPlan);
    procedure LoadRoomListForOtherReservations(reservation: integer);
    procedure ExternalRoomsClick(Sender: TObject);
    procedure FillExternalRoomsInMenu(mnuItem: TMenuItem);
    procedure FillAllRoomsInMenu(mnuItem: TMenuItem);
    procedure LoadRoomListForAllReservations;
    procedure TransferRoomToAnyRoomsClick(Sender: TObject);
    procedure TransferRoomToAnotherRoomReservationInvoice(FromRoomReservation, RoomReservation, RealRoomReservation,
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
    procedure SaveCompletePayments(aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan; aActivityLog: TStringList);
    procedure CopyPaymentsForProforma(aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
    procedure UpdateRoomReservationsCurrency(const aFromCurrency, aToCurrency: string);
    procedure RemoveTaxinvoiceLinesForRoomItem(aInvLine: TInvoiceLine);
    procedure UpdateTaxinvoiceLinesForAllRooms;
    procedure SaveInvoicelineVisibility(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
    function GetInvoiceLineVisibility(aReservation, aRoomReservation, aInvoiceIndex: integer; aPurchaseDate: TDate;
      const aItem: string; aDefault: boolean): boolean;
    procedure RemoveInvoicelineVisibilityRecord(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer;
      aExecPlan: TRoomerExecutionPlan);

    property InvoiceIndex: integer read FInvoiceIndex write SetInvoiceIndex;
    property AnyRowChecked: boolean read GetAnyRowSelected;
    property HeaderChanged: boolean read GetHeaderChanged;
    property StayTaxEnabled: boolean read FStayTaxEnabled;
  public
    { Public declarations }
    FnewSplitNumber: integer; // 0 = herbergjareikningur
    FIsCredit: boolean;
    zFromKredit: boolean;

    OriginalInvoiceStatus: Double;
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
    procedure UpdateCaptions;
    procedure WndProc(var message: TMessage); override;
    property reservation: integer read FReservation write FReservation;
    property RoomReservation: integer read FRoomReservation write FRoomReservation;
  published
    property lineCount: integer read GetInvoiceLineCount;
  end;

procedure EditInvoiceRentPerDay(reservation, RoomReservation, SplitNumber, InvoiceIndex: integer; bCredit: boolean;
  FromKredit: boolean = false);

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
  uFrmBackupInvoice,
  uRoomerDefinitions,
  uReservationStateDefinitions,
  uActivityLogs,
  UITypes,
  uFloatUtils,
  Math,
  uVatCalculator,
  uSQLUtils,
  ufrmRoomPrices,
  uInvoiceDefinitions,
  System.Generics.Defaults,
  uDateTimeHelper;

{$R *.DFM}

const
  // Objects in grid
  cInvoiceLineAttachColumn = 0;
  cPurchaseDateAsObjectColumn = 3;

  // Columns in grid
  col_Select = 0;
  col_VisibleOnInvoice = col_Select + 1;
  col_Item = col_VisibleOnInvoice + 1;
  col_Description = col_Item + 1;
  col_date = col_Description + 1;
  col_ItemCount = col_date + 1;
  col_ItemPrice = col_ItemCount + 1;
  col_TotalPrice = col_ItemPrice + 1;
  col_TotalOnInvoice = col_TotalPrice + 1;
  col_System = col_TotalOnInvoice + 1;
  col_Reference = col_System + 1;
  col_Source = col_Reference + 1;
  col_isPackage = col_Source + 1;
  col_NoGuests = col_isPackage + 1;
  col_confirmdate = col_NoGuests + 1;
  col_confirmAmount = col_confirmdate + 1;
  col_rrAlias = col_confirmAmount + 1;
  col_autogen = col_rrAlias + 1;

  // WM_StartUpLists = WM_User + 381;
  WM_REDRAW_LINE = WM_User + 290;

  REMOVE_CURRENT_PROFORMA_INVOICE: Array [0 .. 2] OF String = ('DELETE FROM invoicelines WHERE invoiceNumber=%d',
    'DELETE FROM invoiceheads WHERE invoiceNumber=%d', 'DELETE FROM payments WHERE invoiceNumber=%d');

  REMOVE_REDUNDANT_INVOICES: Array [0 .. 2] OF String = (
    // Credit invoices                          // Proforma invoices
    'DELETE FROM invoicelines WHERE (SplitNumber = 1 AND InvoiceNumber = -1) OR (InvoiceNumber > 1000000000)',
    'DELETE FROM invoiceheads WHERE (SplitNumber = 1 AND InvoiceNumber = -1) OR (InvoiceNumber > 1000000000)',
    'DELETE FROM payments WHERE InvoiceNumber > 1000000000');

procedure EditInvoiceRentPerDay(reservation, RoomReservation, SplitNumber, InvoiceIndex: integer; bCredit: boolean;
  FromKredit: boolean = false);
var
  _frmInvoice: TfrmInvoiceRentPerDay;
begin
  _frmInvoice := TfrmInvoiceRentPerDay.Create(nil);
  try
    _frmInvoice.reservation := reservation;
    _frmInvoice.RoomReservation := RoomReservation;
    _frmInvoice.FnewSplitNumber := SplitNumber;
    _frmInvoice.FInvoiceIndex := InvoiceIndex;
    _frmInvoice.FIsCredit := bCredit;
    _frmInvoice.zNativeCurrency := ctrlGetString('NativeCurrency');
    _frmInvoice.zFromKredit := FromKredit;

    _frmInvoice.ShowModal;
  finally
    FreeAndNil(_frmInvoice);
  end;
end;

procedure EmptyStringGrid(Grid: TAdvStringGrid);
var
  i, l: integer;
begin
  for l := 1 to Grid.RowCount - 1 do
  begin
    Grid.SetCheckBoxState(col_Select, l, false);
    Grid.RemoveCheckBox(col_Select, l);
    for i := 0 to Grid.ColCount - 1 do
    begin
      Grid.Cells[i, l] := '';
      Grid.CellProperties[i, l] := nil; // .Free;
      Grid.Objects[i, l] := nil;
    end;
  end;

  Grid.RowCount := 2;
  Grid.FixedRows := 1;
end;

procedure TfrmInvoiceRentPerDay.RemoveAllCheckboxes;
var
  i: integer;
begin
  for i := 0 to agrLines.RowCount - 1 do
  begin
    if agrLines.HasCheckBox(col_Select, i) then
      agrLines.RemoveCheckBox(col_Select, i);
  end;
end;

procedure TfrmInvoiceRentPerDay.DeleteRow(aGrid: TAdvStringGrid; iRow: integer);
begin
  if agrLines.HasCheckBox(col_Select, iRow) then
    agrLines.RemoveCheckBox(col_Select, iRow);
  agrLines.RemoveRows(iRow, 1);
end;

destructor TfrmInvoiceRentPerDay.Destroy;
begin
  FCurrencyhandlersMap.Free;
  inherited;
end;

// HJ
function TfrmInvoiceRentPerDay.isSystemLine(row: integer): boolean;
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

procedure TfrmInvoiceRentPerDay.AddDeleteFromInvoiceToExecutionPlan(aExecutionPlan: TRoomerExecutionPlan);
var
  s: string;
begin
  s := '';
  s := s + 'DELETE FROM invoiceheads ' + ''#10'';
  s := s + ' where Reservation = ' + inttostr(FReservation);
  s := s + '   and RoomReservation = ' + inttostr(FRoomReservation);
  s := s + '   and SplitNumber = ' + inttostr(FnewSplitNumber);
  s := s + '   and InvoiceNumber = -1';
  aExecutionPlan.AddExec(s);
end;

function TfrmInvoiceRentPerDay.IfInvoiceChangedThenOptionallySave(Ask: boolean = True): boolean;
var
  Res: integer;

begin
  result := True;

  if zErr then
  begin
    close;
    exit;
  end;

  if FnewSplitNumber <> cCreditInvoive then // 1
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

procedure TfrmInvoiceRentPerDay.btnExitClick(Sender: TObject);
begin
  if IsCashInvoice or IfInvoiceChangedThenOptionallySave then
    close;
end;

procedure TfrmInvoiceRentPerDay.btnClickDropDown(Sender: TObject);
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

procedure TfrmInvoiceRentPerDay.btnClearAddressesClick(Sender: TObject);
begin
  edtAddress1.Text := '';
  edtAddress2.Text := '';
  edtAddress3.Text := '';
  edtAddress4.Text := '';
  FHeaderChanged := True;
end;

procedure TfrmInvoiceRentPerDay.actToggleLodgingTaxClick(Sender: TObject);
begin
  FStaytaxEnabled := RV_ToggleUseStayTax(FReservation) and ctrlGetBoolean('useStayTax');
  LoadInvoice;
end;

procedure TfrmInvoiceRentPerDay.btnReservationNotesClick(Sender: TObject);
begin
  g.openresMemo(FReservation);
end;

procedure TfrmInvoiceRentPerDay.btnSaveChangesClick(Sender: TObject);
begin
  IfInvoiceChangedThenOptionallySave(false);
  UpdateInvoiceIndexTabs;
  LoadInvoice;
end;

procedure TfrmInvoiceRentPerDay.ClearRoomInfoObjects;
begin
  FRoomInfoList.Clear;
end;

{ TInvoiceLine }
function TInvoiceLine.CanBeHiddenFromInvoice: boolean;
begin
  result := (Item <> g.qRoomRentItem) and
              ((IsGeneratedLine and assigned(Parent))
              or
              (isPackage));
end;

constructor TInvoiceLine.Create(aIndex, _id: integer);
begin
  inherited Create;

  FInvoiceLineIndex := aIndex;
  FVisibleOnInvoice := True;
  FInvoiceNumber := -1;
  FLineId := _id;
  FItem := '';
  FText := '';
  FNumber := 0;
  FPrice := 0.00;
  FTotal := 0.00;
  FReference := '';
  FSource := '';
  FChildInvoiceLines := TList<TInvoiceLine>.Create;
  FCurrency := g.qNativeCurrency;
end;

destructor TInvoiceLine.Destroy;
begin
  FChildInvoiceLines.Free;
  inherited Destroy;
end;

function TInvoiceLine.GetAmountOnInvoice: Double;
begin
  result := GetAmountOnInvoiceNativeCurrency / GetRate(FCurrency);
end;

function TInvoiceLine.GetAmountOnInvoiceNativeCurrency: Double;
var
  lDerived: TInvoiceLine;
begin
  if FVisibleOnInvoice then
  begin
    result := TotalNativeCurrency;
    for lDerived in FChildInvoiceLines do
      if lDerived.VisibleOnInvoice and lDerived.TotalIsIncludedInParent then
        result := result - lDerived.TotalNativeCurrency
      else if not lDerived.VisibleOnInvoice and not lDerived.TotalIsIncludedInParent then
        result := result + lDerived.TotalNativeCurrency;
  end
  else
    result := 0;
end;

function TInvoiceLine.GetItemKind: TItemKind;
begin
  result := Item_GetKind(Item);
end;

function TInvoiceLine.GetParentReservation: integer;
begin
  if assigned(Parent) and assigned(Parent.RoomEntity) then
    Result := Parent.RoomEntity.Reservation
  else
    Result := -1;
end;

function TInvoiceLine.GetParentRoomReservation: integer;
begin
  if assigned(Parent) and assigned(Parent.RoomEntity) then
    Result := Parent.RoomEntity.RoomReservation
  else
    Result := -1;
end;

function TInvoiceLine.GetPrice: Double;
begin
  result := FPrice;
end;

function TInvoiceLine.GetPriceNativeCurrency: Double;
begin
  result := Price * GetRate(FCurrency);
end;

function TInvoiceLine.GetPriceOnInvoice: Double;
begin
  result := AmountOnInvoice / Number;
end;

function TInvoiceLine.GetPriceOnInvoiceNativeCurrency: Double;
begin
  result := AmountOnInvoiceNativeCurrency / Number;
end;

procedure TInvoiceLine.GetPurchaseDate(const Value: TDate);
begin
  FDate := Value
end;

function TInvoiceLine.GetRevenueNativeCurrency: Double;
var
  lInvLine: TInvoiceLine;
begin
  result := TotalNativeCurrency;
  for lInvLine in FChildInvoiceLines do
    if lInvLine.TotalIsIncludedInParent then
      result := result - lInvLine.TotalNativeCurrency;
end;

function TInvoiceLine.GetRevenuePrice: Double;
begin
  Result := TotalRevenue / Number;
end;

function TInvoiceLine.GetTotal: Double;
begin
  result := FNumber * FPrice;
end;

function TInvoiceLine.GetTotalNativeCurrency: Double;
begin
  result := Total * GetRate(FCurrency);
end;

function TInvoiceLine.GetTotalRevenue: Double;
var
  lInvLine: TInvoiceLine;
begin
  result := Total;
  for lInvLine in FChildInvoiceLines do
    if lInvLine.TotalIsIncludedInParent then
      result := result - lInvLine.Total;
end;

function TInvoiceLine.GetVatOnInvoice: Double;
begin
  result := GetVatOnInvoiceNativeCurrency / GetRate(FCurrency);
end;

function TInvoiceLine.GetVatOnInvoiceNativeCurrency: Double;
var
  lInvLine: TInvoiceLine;
begin
  result := 0;
  if VisibleOnInvoice then
  begin
    result := VATOnRevenueNativeCurrency;
    for lInvLine in ChildInvoiceLines do
      if not lInvLine.VisibleOnInvoice then
        result := result + lInvLine.VATOnRevenueNativeCurrency;
  end;
end;

function TInvoiceLine.GetVatOnRevenueNativeCurrency: Double;
begin
  result := _calcVat(TotalNativeCurrency, FVATPercentage);
end;

procedure TInvoiceLine.SetParentInvoiceLine(const Value: TinvoiceLine);
begin
  if FParentInvoiceLine <> nil then
    FParentInvoiceLine.ChildInvoiceLines.Remove(Self);

  if assigned(Value) then
      Value.ChildInvoiceLines.Add(self);

  FParentInvoiceLine := Value;
end;

procedure TInvoiceLine.SetVATCode(const Value: string);
begin
  FVATCode := Value;
  if FVATCode = '' then
    FVATPercentage := 0
  else
    FVATPercentage := d.VATPercentage(FVATCode);
end;

/// /////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////

const
  vWidth: integer = 9;
  vDec: integer = 2;

  eWidth: integer = 12;
  eDec: integer = 4;

procedure TfrmInvoiceRentPerDay.ClearInvoiceLines;
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

function TfrmInvoiceRentPerDay.AddLine(LineId: integer; aParentInvoice: TInvoiceLine; sItem, sText: string; iNumber: Double;
  aPrice: Double; const aCurrency: string; const VATCode: string; PurchaseDate: TDate; bAuto: boolean;
  Refrence, Source: string; isPackage: boolean; noGuests: integer; ConfirmDate: TDateTime; ConfirmAmount: Double;
  rrAlias: integer; AutoGen: string; itemIndex: integer = 0; aVisibleOnInvoice: boolean = true): TInvoiceLine;
var
  invoiceLine: TInvoiceLine;
  iLastIdx: integer;
  lPackageId: integer;
  lItemId: integer;
  lParent: TInvoiceLine;
begin
  if AutoGen = '' then
    AutoGen := _GetCurrentTick;

  iLastIdx := 0;

  if GetInvoiceLineCount > 0 then
  begin
    iLastIdx := FInvoiceLinesList[GetInvoiceLineCount - 1].InvoiceLineIndex;
  end;

  inc(iLastIdx);

  if trim(sItem) = '' then
    if copy(sText, 1, 5) = 'Tel: ' then
      sItem := trim(g.qPhoneUseItem);

  lParent := aParentInvoice;
  invoiceLine := TInvoiceLine.Create(iLastIdx, LineId);
  try
    invoiceLine.Item := sItem;
    invoiceLine.Text := sText;
    invoiceLine.Number := iNumber;
    invoiceLine.Price := aPrice;
    invoiceLine.IsGeneratedLine := bAuto;
    invoiceLine.PurchaseDate := PurchaseDate;
    invoiceLine.Reference := Refrence;
    invoiceLine.Source := Source;
    invoiceLine.isPackage := isPackage;
    invoiceLine.TotalIsIncludedInParent := false; // Even when included in rate, then the rate has ben corrected for this already
    invoiceLine.VisibleOnInvoice := aVisibleOnInvoice;

    if isPackage and not Source.IsEmpty then
    begin
      if glb.LocateSpecificRecordAndGetValue('packages', 'package', Source, 'id', lPackageId) and
         glb.LocateSpecificRecordAndGetValue('items', 'item', sItem, 'id', lItemId) then
      begin
        glb.PackageItems.First;
        while not glb.PackageItems.Eof do
          if (glb.PackageItems.FieldByName('packageid').asInteger = lPackageId) and
             (glb.PackageItems.FieldByName('itemid').asInteger = lItemId) then
          begin
            invoiceLine.VisibleOnInvoice := not glb.PackageItems.FieldByName('includedInRate').asBoolean;
            Break;
          end
          else
            glb.PackageItems.Next;
      end;
      // locate roomrent item that should be the parent, roomrent item of the same purchase date
      for lParent in FInvoiceLinesList do
        if (lParent.ItemKind = ikRoomRent) and lParent.isPackage and (lParent.PurchaseDate = invoiceLine.PurchaseDate) then
          Break;
    end;

    invoiceLine.noGuests := noGuests;
    invoiceLine.ConfirmDate := ConfirmDate;
    invoiceLine.ConfirmAmount := ConfirmAmount;
    invoiceLine.rrAlias := rrAlias;
    invoiceLine.itemIndex := itemIndex;
    invoiceLine.AutoGen := AutoGen;
    invoiceLine.Parent := lParent;
    invoiceLine.VATCode := VATCode;
    invoiceLine.Currency := aCurrency;

    // Check if visiblity overridden in invoicelines_visiblity table
    invoiceline.VisibleOnInvoice := GetInvoiceLineVisibility(invoiceline.ParentReservation, invoiceline.ParentRoomReservation,
                                                             FInvoiceIndex, invoiceline.PurchaseDate, invoiceline.Item,
                                                             invoiceline.VisibleOnInvoice);

    FInvoiceLinesList.Add(invoiceLine);

  except
    invoiceLine.Free;
    raise;
  end;
  result := invoiceLine;
end;

function TfrmInvoiceRentPerDay.GetInvoiceLineByRow(ARow: integer): TInvoiceLine;
begin
  result := agrLines.Objects[cInvoiceLineAttachColumn, ARow] as TInvoiceLine
end;

function TfrmInvoiceRentPerDay.GetInvoiceLineCount: integer;
begin
  result := FInvoiceLinesList.Count;
end;

procedure TfrmInvoiceRentPerDay.UpdateGrid;
var
  lInvoiceLine: TInvoiceLine;
  cnt: integer;
begin
  if not agrLines.IsUpdating then
  begin
    agrLines.BeginUpdate;
    Screen.Cursor := crHourGlass;
    try
      // agrLines.ClearRows(1, agrLines.RowCount);
      EmptyStringGrid(agrLines);
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

      chkChanged;
    finally
      agrLines.EndUpdate;
      Screen.Cursor := crDefault;
    end;
  end;
end;

procedure TfrmInvoiceRentPerDay.UpdateLine(ARow: integer);
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

procedure TfrmInvoiceRentPerDay.CheckAndAddLastRow;
begin
  if agrLines.RowCount <= FInvoiceLinesList.Count + 1 then
    agrLines.RowCount := FInvoiceLinesList.Count + 2;
end;

function TfrmInvoiceRentPerDay.DisplayLine(aInvoiceLine: TInvoiceLine; ARow: integer): integer;
var
  lValue: Double;
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
    agrLines.SetCheckBoxState(col_VisibleOnInvoice, ARow, aInvoiceLine.VisibleOnInvoice);
  end
  else if agrLines.HasCheckBox(col_VisibleOnInvoice, ARow) then
    agrLines.RemoveCheckBox(col_VisibleOnInvoice, ARow);

  agrLines.Cells[col_Description, ARow] := aInvoiceLine.Text;
  agrLines.Cells[col_ItemCount, ARow] := trim(_floattostr(aInvoiceLine.Number, vWidth, vDec));

  agrLines.Cells[col_ItemPrice, ARow] := FCurrencyhandlersMap.CurrencyHandler[aInvoiceLine.Currency]
    .FormattedValueWithCode(aInvoiceLine.RevenuePrice);

  agrLines.Cells[col_TotalPrice, ARow] := FCurrencyhandlersMap.CurrencyHandler[aInvoiceLine.Currency]
    .FormattedValueWithCode(aInvoiceLine.TotalRevenue);

  lValue := FCurrencyhandlersMap.ConvertAmount(aInvoiceLine.AmountOnInvoice, aInvoiceLine.Currency,
    edtDisplayCurrency.Text);
  if SameValue(lValue, 0.00, 0.01) then
    agrLines.Cells[col_TotalOnInvoice, ARow] := ''
  else
    agrLines.Cells[col_TotalOnInvoice, ARow] := FCurrencyhandlersMap.CurrencyHandler[edtDisplayCurrency.Text]
      .FormattedValueWithCode(lValue); // trim(_floattostr(lAmountOnInvoice * lDisplayCurrencyRate, vWidth, vDec));

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

  agrLines.Cells[col_rrAlias, ARow] := inttostr(aInvoiceLine.rrAlias);

  agrLines.Cells[col_autogen, ARow] := aInvoiceLine.AutoGen;

  agrLines.Objects[cInvoiceLineAttachColumn, ARow] := aInvoiceLine; // -- Auto !

  result := ARow;
end;

procedure TfrmInvoiceRentPerDay.DisplayTotals(editCol: integer = -1; editRow: integer = -1; Value: Double = 0.00);
var
  TotalDownPayments: Double;
  TotalBalance: Double;
  ttVAT: Double;
  nativeTotal: Double;
begin
  Screen.Cursor := crHourGlass;
  try
    nativeTotal := FInvoiceLinesList.TotalOnInvoiceNativeCurrency;
    ttVAT := FInvoiceLinesList.TotalVatOnInvoiceNativeCurrency;
    TotalDownPayments := getDownPayments;
    TotalBalance := nativeTotal - TotalDownPayments;

    with FCurrencyhandlersMap.CurrencyHandler[g.qNativeCurrency] do
    begin
      edtTotalWOVat.Text := FormattedValueWithCode(nativeTotal - ttVAT);
      edtVat.Text := FormattedValueWithCode(ttVAT);
      edtInvoiceTotal.Text := FormattedValueWithCode(nativeTotal);
      edtDownPayments.Text := FormattedValueWithCode(TotalDownPayments);
      edtBalance.Text := FormattedValueWithCode(TotalBalance);
      labLodgingTax.Caption := FormattedValueWithCode(FInvoiceLinesList.TotalCityTaxRevenues);
    end;

    if (edtDisplayCurrency.Text <> '') and (edtDisplayCurrency.Text <> zNativeCurrency) then
      with FCurrencyhandlersMap.CurrencyHandler[edtDisplayCurrency.Text] do
        edtForeignCurrency.Text := FormattedValueWithCode(ConvertFrom(nativeTotal, g.qNativeCurrency));

    labLodgingTaxNights.Caption := inttostr(trunc(FInvoiceLinesList.CityTaxUnitCount));
  finally
    Screen.Cursor := crDefault;
  end;
end;

procedure TfrmInvoiceRentPerDay.DisplayMem(zrSet: TRoomerDataset);
begin
  with zrSet do
  begin
    first;
    if not eof then
    begin
      memExtraText.Lines.Text := trim(FieldByName('ExtraText').asString);
    end;
  end;
end;

procedure TfrmInvoiceRentPerDay.DisplayGuestName(zrSet: TRoomerDataset);
begin
  if zrSet = nil then
  begin
    exit;
  end;
  if copy(edtRoomGuest.Caption, 1, 1) <> '-' then
  begin
    edtRoomGuest.Caption := GetMainGuestName(FReservation, FRoomReservation);
  end;
end;

procedure TfrmInvoiceRentPerDay.AddRoomTaxToLinesAndGrid(totalTax: Double; TaxUnits: Double; taxItem: String;
  aPurchaseDate: TDate; iAddAt: integer = 0; aParentInvoice: TInvoiceLine = nil; aIsIncludedInParent: boolean = false);
var
  ConfirmDate: TDateTime;
  ConfirmAmount: Double;
  unitPrice: Double;
  lItemInfo: TItemTypeInfo;
  lInvLine: TInvoiceLine;
begin
  if zFromKredit then
    exit;

  ConfirmDate := 2;
  ConfirmAmount := 0;

  if taxItem = '' then
    taxItem := g.qStayTaxItem;
  lItemInfo := d.Item_Get_ItemTypeInfo(taxItem);

  unitPrice := totalTax / TaxUnits;

  lInvLine := AddLine(0, aParentInvoice, taxItem, Item_GetDescription(taxItem), TaxUnits, unitPrice, g.qNativeCurrency,
    lItemInfo.VATCode, aPurchaseDate, True, '', '', false, 0, ConfirmDate, ConfirmAmount, -1, _GetCurrentTick, 0, not aIsIncludedInParent);

  lInvLine.TotalIsIncludedInParent := aIsIncludedInParent;
end;

procedure TfrmInvoiceRentPerDay.SetCurrentVisible;
begin
  if agrLines.RowCount > agrLines.VisibleRowCount then
  begin
    if (agrLines.row > agrLines.TopRow + agrLines.VisibleRowCount - 1) then
      agrLines.TopRow := agrLines.row - agrLines.VisibleRowCount + 1
    else if (agrLines.row < agrLines.TopRow) then
      agrLines.TopRow := agrLines.row;
  end;
end;

procedure TfrmInvoiceRentPerDay.CreateCashInvoice(customer: string);
var
  CustomerHolder: recCustomerHolderEX;
  s: string;
begin
  d.RemoveInvoiceCashInvoice;

  pnlHead.Color := $00FFDDDD; // $00EAFFEA
  pnlTotalsAndPayments.Color := $00FFDDDD; // $00EAFFEA

  rgrInvoiceType.itemIndex := 4;

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
  s := s + ', ' + _db(FnewSplitNumber);
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
  s := s + ', ' + _db(rgrInvoiceType.itemIndex);
  s := s + ', ' + _db(g.qUser);
  s := s + ', ' + _db(Date);
  s := s + ', ' + _db(zInvoiceDate);
  s := s + ', ' + _db(zConfirmDate);
  s := s + ', ' + _db(zPayDate);
  s := s + ', ' + _db(edtDisplayCurrency.Text);
  s := s + ', ' + _db(_StrToFloat(edtRate.Text));
  s := s + ', ' + _db(zLocation);

  s := s + ')' + #10;

  if not cmd_bySQL(s) then
  begin
  end;

  rgrInvoiceType.itemIndex := 4;
  edtCustomer.Text := CustomerHolder.customer;
  edtPersonalId.Text := CustomerHolder.PID;
  edtName.Text := CustomerHolder.CustomerName;
end;

procedure TfrmInvoiceRentPerDay.RestoreTMPInvoicelines;
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
          qry := qry + ', ' + _db(FnewSplitNumber);
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

Procedure TfrmInvoiceRentPerDay.InitInvoiceGrid;
var
  iWidth, i: integer;
begin
  EmptyStringGrid(agrLines);
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
    agrLines.ColWidths[col_Item] - agrLines.ColWidths[col_ItemCount] - agrLines.ColWidths[col_ItemPrice] -
    agrLines.ColWidths[col_TotalPrice] - agrLines.ColWidths[col_TotalOnInvoice] - agrLines.ColWidths[col_Source] - 5;

  if iWidth > 0 then
    agrLines.ColWidths[col_Description] := iWidth;

//  agrLines.HideColumn(col_date);
  agrLines.HideColumn(col_System);
  agrLines.HideColumn(col_Reference);
  agrLines.HideColumns(col_isPackage, col_autogen);

  for i := 0 to agrLines.ColCount - 1 do
    if agrLines.IsHiddenColumn(i) then
      agrLines.ColWidths[i] := 0;

  if not agrLines.HasCheckBox(0, col_Select) then
    agrLines.AddCheckBox(0, col_Select, false, false);

end;

procedure TfrmInvoiceRentPerDay.AddRoom(const aRoom: String; aRoomPrice: Double; aCurrency: string; aFromDate: TDate;
  aToDate: TDate; aDayCount: integer; const aDescription: string; aGetGuestName: boolean; aRoomReservation: integer;
  aDiscountAmount: Double; aDiscountIsPercentage: boolean; const aDiscountText: string; const aGuestName: String;
  aNumGuests: integer; aNumChildren: integer; aIsPackage: boolean; aRRAlias: integer;
  aBeakfastIncluded: boolean);
var
  lRmRntItem: string;
  lDiscountItem: string;

  lGuestName: string;
  lNumGuests: integer;
  lConfirmDate: TDateTime;
  lConfirmAmount: Double;

  lRRText: string;
  lText: string;
  lRoomInfo: TInvoiceRoomEntity;
  lInvoiceLine: TInvoiceLine;
  lItemInfo: TItemTypeInfo;
  lDescription: string;
begin

  lConfirmDate := 2;
  lConfirmAmount := 0;

  lRmRntItem := trim(g.qRoomRentItem);
  lItemInfo := d.Item_Get_ItemTypeInfo(lRmRntItem);

  lRRText := Item_GetDescription(lRmRntItem);
  lDescription := aDescription;
  if copy(lDescription, 1, 2) = '--' then
  begin
    lRRText := '';
    lDescription := copy(lDescription, 3, maxint);
  end;

  if copy(lDescription, 1, 2) = '&-' then
  begin
    lRRText := '';
    lDescription := copy(lDescription, 3, maxint);
  end;

  if copy(lDescription, 1, 2) = '&&' then
  begin
    aGetGuestName := True;
    lDescription := copy(lDescription, 3, maxint);
  end;

  lGuestName := aGuestName;
  lNumGuests := aNumGuests;

  if not aGetGuestName then
    if lRRText <> '' then
      lText := lRRText + ' (' + lDescription + ') '
    else
      lText := lDescription
  else
    lDescription := trim(lGuestName) + ' (' + lDescription + ') ';

  lRoomInfo := TInvoiceRoomEntity.Create;
  // -- Attach the Room information
  lRoomInfo.RoomReservation := aRoomReservation;
  lRoomInfo.reservation := FReservation;
  lRoomInfo.Name := lGuestName;
  lRoomInfo.Arrival := aFromDate;
  lRoomInfo.Departure := aToDate;
  lRoomInfo.Price := aRoomPrice;
  lRoomInfo.Discount := 0.00;
  lRoomInfo.Room := aRoom;
  lRoomInfo.NumGuests := lNumGuests;
  lRoomInfo.NumChildren := aNumChildren;
  lRoomInfo.BreakFastIncluded := aBeakfastIncluded;
  FRoomInfoList.Add(lRoomInfo);

  // add a TInvoiceline object for the RoomRent to InvoiceLineList
  lInvoiceLine := AddLine(0, nil, lRmRntItem, lDescription, aDayCount, aRoomPrice, aCurrency, lItemInfo.VATCode, aFromDate, True,
    '', '', aIsPackage, lNumGuests, lConfirmDate, lConfirmAmount, aRRAlias, _GetCurrentTick); // *77
  lInvoiceLine.RoomEntity := lRoomInfo;
  lRoomInfo.Vat := lInvoiceLine.VATOnInvoice;

  // Tax invoicelines
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
    lInvoiceLine := AddLine(0, lInvoiceLine, lDiscountItem, lDescription, aDayCount, -1 * aDiscountAmount, aCurrency,
            lItemInfo.VATCode, aFromDate, True, '', '', false, aNumGuests, lConfirmDate, lConfirmAmount, aRRAlias, _GetCurrentTick);
    lRoomInfo.Discount := aDiscountAmount * aDayCount;
  end;

  UpdateItemInvoiceLinesForTaxCalculations;
  UpdateGrid;
end;

procedure TfrmInvoiceRentPerDay.AddBreakfastInvoicelinesForRoomItem(aRoomEntity: TInvoiceRoomEntity; aParent: TInvoiceLine);
begin
  if aRoomEntity.BreakFastIncluded then
    AddIncludedBreakfastToLinesAndGrid(aRoomEntity.NumGuests * aRoomEntity.NumberOfNights, aRoomEntity.Arrival, 0, aParent);

end;

procedure TfrmInvoiceRentPerDay.RemoveTaxinvoiceLinesForRoomItem(aInvLine: TInvoiceLine);
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

procedure TfrmInvoiceRentPerDay.UpdateTaxinvoiceLinesForAllRooms;
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

procedure TfrmInvoiceRentPerDay.UpdateTaxinvoiceLinesForRoomItem(aInvLine: TInvoiceLine);
var
  lIsIncluded: boolean;
  lIsIncludedCust: boolean;
  lTaxResultInvoiceLines: TInvoiceTaxEntityList;
  lTotal: Double;
  lTotalNative: Double;
  tt, l: integer;
  lCalcOptions: TInvoiceCityTaxCalculationOptions;
begin
  if zFromKredit then
    exit;

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

          lTotalNative := FCurrencyhandlersMap.ConvertAmount(lTotal, aInvLine.Currency, g.qNativeCurrency);
          AddRoomTaxToLinesAndGrid(lTotalNative, trunc(lTaxResultInvoiceLines[l].NumItems), TaxTypes[tt],
            aInvLine.RoomEntity.Arrival, 0, aInvLine, lIsIncluded);
        end; // for l + if
    end; // for tt
  finally
    lTaxResultInvoiceLines.Free;
  end;

  UpdateGrid;
end;

procedure TfrmInvoiceRentPerDay.tvPaymentsCellDblClick(Sender: TcxCustomGridTableView;
  ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton; AShift: TShiftState; var AHandled: boolean);
begin
  actEditDownpayment.Execute;
end;

procedure TfrmInvoiceRentPerDay.tvPaymentsMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
  X, Y: integer);
begin
  if ssCtrl in Shift then
  begin
    grPayments.BeginDrag(True);
  end;
end;

function TfrmInvoiceRentPerDay.getDownPayments: Double;
var
  Total: Double;
begin
  Total := 0;

  if mPayments.RecordCount > 0 then
  begin
    mPayments.DisableControls;
    try
      mPayments.first;
      while not mPayments.eof do
      begin
        Total := Total + mPayments.FieldByName('Amount').AsFloat;
        mPayments.Next;
      end;
    finally
      mPayments.EnableControls;
    end;
  end;
  result := Total;
end;

procedure TfrmInvoiceRentPerDay.loadInvoiceToMemtable(var m: TKbmMemTable);
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

    ItemPrice := iMultiplier * zCurrencyRate * ItemPrice;
    TotalPrice := ItemCount * ItemPrice * iMultiplier;

    lInvRoom := TInvoiceRoomEntity.Create(lineItem, 1, 0, ItemCount, TotalPrice, 0, 0, false);
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
    m.FieldByName('SplitNumber').asinteger := FnewSplitNumber;
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
    m.FieldByName('CurrencyRate').AsFloat := zCurrencyRate;
    m.FieldByName('Currency').asString := edtDisplayCurrency.Text;
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

function TfrmInvoiceRentPerDay.GetInvoiceIndexPanel(Index: integer): TsPanel;
begin
  result := TsPanel(FindComponent('pnlInvoiceIndex' + inttostr(Index)));
end;

function TfrmInvoiceRentPerDay.GetInvoiceIndexItems(Index: integer): TShape;
begin
  result := TShape(FindComponent('shpInvoiceIndex' + inttostr(Index)));
end;

function TfrmInvoiceRentPerDay.GetInvoiceIndexItemsRR(Index: integer): TShape;
begin
  result := TShape(FindComponent('shpInvoiceIndexRR' + inttostr(Index)));
end;

procedure TfrmInvoiceRentPerDay.SetInvoiceIndexPanelsToZero;
var
  i: integer;
  pnl: TsPanel;
  shp1, shp2: TShape;
begin
  for i := 0 to 9 do
  begin
    pnl := GetInvoiceIndexPanel(i);
    shp1 := GetInvoiceIndexItems(i);
    shp2 := GetInvoiceIndexItemsRR(i);

    pnl.HelpContext := 0;
    pnl.Hint := '';

    shp1.HelpContext := 0;
    shp1.Hint := '';
    shp1.Visible := false;

    shp2.HelpContext := 0;
    shp2.Hint := '';
    shp2.Visible := false;
  end;
end;

procedure TfrmInvoiceRentPerDay.shpInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
begin
  pnlInvoiceIndex0DragDrop(TShape(Sender), Source, X, Y);
end;

procedure TfrmInvoiceRentPerDay.shpInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState;
  var Accept: boolean);
begin
  pnlInvoiceIndex0DragOver(TShape(Sender), Source, X, Y, State, Accept);
end;

procedure TfrmInvoiceRentPerDay.shpInvoiceIndex0MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
  X, Y: integer);
begin
  pnlInvoiceIndex0Click(TShape(Sender).Parent);
end;

function TfrmInvoiceRentPerDay.GetCalculatedNumberOfItems(ItemId: String; dDefault: Double): Double;
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

procedure TfrmInvoiceRentPerDay.LoadInvoice;
var
  rSet: TRoomerDataset;

  iLastRoomRes, idx: integer;
  iCurrentRow: integer;
  sText: string;

  GuestsInRoomRes: integer;

  PurchaseDate: TDateTime;
  Number: Double; // -96

  AYear, AMon, ADay: Word;

  // summur
  vTotal: Double;
  vTotalWOVat: Double;
  vVat: Double;

  s: string;

  tmp: string;

  itemNumber: integer;
  ItemId: string;
  LineId: integer;
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

  isGroupAccount: boolean;
  BrekFastIncluded: boolean;

  GuestNights: integer;

  _s: string;

  OrginalRef: integer;
  dPrice: Double;
  ciCustomerInfo: recCustomerHolderEX;
  ProcessOld: boolean;

  importRefrence: string;
  ImportSource: string;

  status: string;

  dTmp: Double;
  iTmp: integer;

  lRoomReservation: integer;
  Room: string;
  RoomType: string;
  NumberGuests: integer;
  RoomDescription: string;
  RoomTypeDescription: string;
  Arrival: TDate;
  Departure: TDate;
  ChildrenCount: integer;
  infantCount: integer;
  PriceCode: string;

  invoiceHeadData: recInvoiceHeadHolder;

  dayCount: integer;
  RateDate: TDateTime;

  i: integer;

  Rate: Double;
  Discount: Double;
  isPercentage: boolean;
  ShowDiscount: boolean;
  isPaid: boolean;
  DiscountAmount: Double;
  rentAmount: Double;
  NativeAmount: Double;
  reservation: integer;

  AverageRate: Double;
  RateCount: integer;
  UnpaidDays: integer;

  AverageDiscountPerc: Double;
  AverageDiscountAmount: Double;

  DiscountText: string;
  TotalDiscountAmount: Double;
  RoomRentPaidDays: Double;
  iTotalResDays: integer;

  TotalRate: Double;
  // ttDiscount: Double;

  GuestName: String;
  NumChildren: integer;

  lExecutionPlan: TRoomerExecutionPlan;
  Index: integer;

  iNumNights: integer;

  sql: string;
  package: string;

  showPackage: boolean;
  aRoom: string;
  tmpint: integer;
  isPackage: boolean;

  eSet, zrSet, reservationSet: TRoomerDataset;

  dNumber: Double;
  lRoomText: string;
  lRoomAdditionalText: string;
  allIsPercentage: boolean;

  function SplitValue(s: String; Index: integer): String;
  var
    slist, sEntry: TStringList;
    i: integer;
  begin
    result := '';
    slist := Split(s, ',');
    try
      for i := 0 to slist.Count - 1 do
        if slist[i] <> '' then
        begin
          sEntry := Split(slist[i], ';');
          try
            if (sEntry.Count = 2) and (sEntry[0] = inttostr(index)) then
            begin
              result := sEntry[1];
              exit;
            end;
          finally
            sEntry.Free;
          end;
        end;
    finally
      slist.Free;
    end;

  end;

  procedure SetInvoiceIndexColors(IndexList, Currency: String);
  var
    i: integer;
    s: String;
    Value: Double;
  begin
    IndexList := IndexList;
    for i := 0 to 9 do
    begin
      s := SplitValue(IndexList, i);
      if s <> '' then
      begin
        GetInvoiceIndexPanel(i).HelpContext := i + 1;
        Value := SQLToFloat(s);
        GetInvoiceIndexItems(i).Hint := Currency + ' ' + trim(_floattostr(Value, 12, 2));
      end;
    end;
  end;

  procedure AddRRColor(InvoiceIndex: integer; Total: Double; Currency: String);
  begin
    if round(Total) > 0 then
    begin
      GetInvoiceIndexItemsRR(InvoiceIndex).HelpContext := InvoiceIndex + 1;
      GetInvoiceIndexItemsRR(InvoiceIndex).Hint := Currency + ' ' + trim(_floattostr(Total, 12, 2))
    end;
  end;

  procedure SetInvoiceTypeIndex(Index: integer);
  begin
    rgrInvoiceType.OnClick := nil;
    try
      rgrInvoiceType.itemIndex := index;
    finally
      rgrInvoiceType.OnClick := rgrInvoiceTypeClick;
    end;
  end;

var
  list: TStringList;
  zRoomRSet: TRoomerDataset;
  sTemp: String;
  lCurrency: string;

label
  Again;
begin

  SetInvoiceIndexPanelsToZero;

  zrSet := CreateNewDataSet;
  zRoomRSet := CreateNewDataSet;
  zRoomRSet.CommandType := cmdText;

  Screen.Cursor := crHourGlass;
  mRoomRes.DisableControls;
  mRoomRates.DisableControls;
  agrLines.BeginUpdate;
  try
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
    zbRoomRentinTemp := false;

    edResNr.Caption := format('%d / %d', [FReservation, FRoomReservation]);

    if FnewSplitNumber = cCashInvoice then
    begin
      CreateCashInvoice(g.qRackCustomer);
      edtDisplayCurrency.Text := zNativeCurrency;
      zCurrentCurrency := edtDisplayCurrency.Text;
      zCurrencyRate := GetRate(zCurrentCurrency);
      edtRate.Text := floattostr(zCurrencyRate);
      InitInvoiceGrid;
      exit;
    end;

  Again:
    // Retrieve invoice header information
    sql := 'SELECT CONVERT((SELECT GROUP_CONCAT(DISTINCT CONCAT(il1.InvoiceIndex, '';'', (SELECT SUM(il2.Total) FROM invoicelines il2 WHERE il2.RoomReservation=ih.RoomReservation '
      + 'AND il2.Reservation=ih.Reservation AND il2.InvoiceNumber=-1 AND il1.InvoiceIndex=il2.InvoiceIndex)) ORDER BY InvoiceIndex) '
      + 'FROM invoicelines il1 WHERE il1.RoomReservation=ih.RoomReservation AND il1.Reservation=ih.Reservation AND il1.InvoiceNumber=-1) USING utf8) AS InvoiceIndexes, '
      + '(SELECT InvoiceIndex FROM roomreservations rr WHERE ' + IIF(FRoomReservation > 0,
      'rr.RoomReservation = ih.RoomReservation ', 'rr.Reservation=ih.Reservation ') + ' LIMIT 1) rrInvoiceIndex, ' +
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
      'IFNULL(ia.ihCurrency, ih.ihCurrency) AS ihCurrency, ' + 'ih.ihCurrencyRate, ' + 'ih.invRefrence, ' +
      'ih.TotalStayTax, ' + 'ih.TotalStayTaxNights, ' + 'ih.showPackage, ' + 'ih.staff, ' + 'ih.location, ' +
      'ih.externalInvoiceId ' + 'FROM invoiceheads ih ' + #10 +
      '     LEFT JOIN invoiceaddressees ia ON ia.invoiceNumber=ih.InvoiceNumber ' +
      '        AND ia.Reservation=ih.Reservation ' + '        AND ia.RoomReservation=ih.RoomReservation ' +
      '        AND ia.SplitNumber=ih.SplitNumber ' + '        AND ia.InvoiceIndex=%d ' + 'where ih.Reservation = %d '#10
      + '   and ih.RoomReservation = %d and ih.SplitNumber = %d '#10 +
      '   and ih.InvoiceNumber = -1 and ih.Finished = 0';
    if zrSet.active then
      zrSet.close;

    sql := format(sql, [InvoiceIndex, FReservation, FRoomReservation, FnewSplitNumber]);

    copytoclipboard(sql);

    hData.rSet_bySQL(zrSet, sql);

    zrSet.first;

    // If invoice header is found...
    if not zrSet.eof then
    begin
      SetInvoiceIndexColors(zrSet.FieldByName('InvoiceIndexes').asString, zrSet.FieldByName('ihCurrency').asString);
      AddRRColor(zrSet.FieldByName('rrInvoiceIndex').asinteger, zrSet.FieldByName('rrInvoiceTotal').AsFloat,
        zrSet.FieldByName('ihCurrency').asString);
      // S�kja Invoice sem er til
      zInvoiceNumber := zrSet.FieldByName('InvoiceNumber').asinteger;

      if FnewSplitNumber <> cCashInvoice then // ef ekki sta�grei�slureikningur
      begin
{$REGION 'Set Invoice type'}
        if zrSet.FieldByName('InvoiceType').asinteger <> 4 then // Free text
          GetInvoiceHeader(FReservation, FRoomReservation, zrSet); // To initialize with current data
        if zrSet.FieldByName('InvoiceType').asinteger = 4 then // Free text
        begin
          GetInvoiceHeader(FReservation, FRoomReservation, zrSet);
          SetInvoiceTypeIndex(4);
        end
        else if zrSet.FieldByName('InvoiceType').asinteger = 1 then
        // Reservation customer
        begin
          GetReservationHeader(FReservation, FRoomReservation);
          SetInvoiceTypeIndex(1);
        end
        else
        begin
          SetInvoiceTypeIndex(zrSet.FieldByName('InvoiceType').asinteger);
        end;

        if FnewSplitNumber = 1 then // Kreditinvoice
        begin
          GetInvoiceHeader(FReservation, FRoomReservation);
          SetInvoiceTypeIndex(3);
        end;

        FHeaderChanged := false;
        btnGetCustomer.Enabled := rgrInvoiceType.itemIndex <> 1;
        btnClearAddresses.Enabled := rgrInvoiceType.itemIndex <> 1;

{$ENDREGION}
      end;

      edtDisplayCurrency.Text := trim(zrSet.FieldByName('ihCurrency').asString);
      zCurrentCurrency := edtDisplayCurrency.Text;
      zCurrencyRate := GetRate(zCurrentCurrency);
      edtRate.Text := floattostr(zCurrencyRate);

    end
    else
    begin
      // Otherwise - create New invoice
      zInvoiceNumber := -1;
      zInvoiceDate := now;
      zConfirmDate := 2;
      zPayDate := trunc(now);

      if zrSet.active then
        zrSet.close;

      sql := 'SELECT r.*, rr.Currency ' + 'FROM reservations r ' +
        'JOIN roomreservations rr ON r.Reservation=rr.Reservation ' + 'WHERE r.Reservation = %d ';

      sql := format(sql, [FReservation]);

      hData.rSet_bySQL(zrSet, sql);

      zrSet.first;
      // INS-InvoiceHead
      // If there is no tmp invoice then create it
      // and goto label Again
      if not zrSet.eof then
      begin
        initInvoiceHeadHolderRec(invoiceHeadData);

        invoiceHeadData.reservation := FReservation;
        invoiceHeadData.RoomReservation := FRoomReservation;
        invoiceHeadData.SplitNumber := FnewSplitNumber;
        invoiceHeadData.InvoiceNumber := zInvoiceNumber;
        invoiceHeadData.InvoiceDate := _db(zInvoiceDate, false);
        invoiceHeadData.ihCurrency := zrSet.FieldByName('Currency').asString;
        invoiceHeadData.ihCurrencyRate := GetRate(zrSet.FieldByName('Currency').asString);

        invoiceHeadData.customer := zrSet.FieldByName('Customer').asString;
        invoiceHeadData.Name := zrSet.FieldByName('Name').asString;
        invoiceHeadData.Address1 := zrSet.FieldByName('Address1').asString;
        invoiceHeadData.Address2 := zrSet.FieldByName('Address2').asString;
        invoiceHeadData.Address3 := zrSet.FieldByName('Address3').asString;
        invoiceHeadData.Address4 := '';
        // ATH _db(zrSet.FieldByName('Address4').asString);
        invoiceHeadData.Country := zrSet.FieldByName('Country').asString;
        invoiceHeadData.Total := 0.00;
        invoiceHeadData.TotalWOVat := 0.00;
        invoiceHeadData.TotalVAT := 0.00;
        invoiceHeadData.TotalBreakFast := 0.00;
        invoiceHeadData.ExtraText := memExtraText.Lines.Text;
        invoiceHeadData.Finished := false;
        invoiceHeadData.InvoiceType := rgrInvoiceType.itemIndex;
        invoiceHeadData.CustPID := zrSet.FieldByName('CustPid').asString;
        invoiceHeadData.ihDate := Date;
        invoiceHeadData.ihInvoiceDate := zInvoiceDate;
        invoiceHeadData.ihConfirmDate := zConfirmDate;
        invoiceHeadData.ihPayDate := zPayDate;
        invoiceHeadData.ihStaff := g.qUser;
        hData.SP_INS_InvoiceHead(invoiceHeadData);
        goto Again;
      end
    end;

    DisplayMem(zrSet);
    DisplayGuestName(zrSet);

    sql := Select_Invoice_LoadInvoice3_WithInvoiceIndex(FRoomReservation, FReservation, FInvoiceIndex, edtCustomer.Text,
      false { zFakeGroup } );

    if FRoomReservation = 0 then // GroupInvoice
      sql := format(sql, [FReservation])
    else
      sql := format(sql, [FRoomReservation, FRoomReservation]);

    if zRoomRSet.active then
      zRoomRSet.close;

    copytoclipboard(sql);
    hData.rSet_bySQL(zRoomRSet, sql);

    iLastRoomRes := -1;
    RoomRentPaidDays := 0.00;

    zRoomRSet.first;
    lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
    try

      if not zRoomRSet.eof then
      begin

        zEmailAddress := '';
        list := TStringList.Create;
        try
          uUtils.SplitString(trim(zRoomRSet.FieldByName('ContactEmail').asString), list, ';');
          for i := 0 to list.Count - 1 do
            if list[i] <> '' then
            begin
              if zEmailAddress = '' then
                zEmailAddress := QuotedStr(list[i])
              else
                zEmailAddress := zEmailAddress + ';' + QuotedStr(list[i])
            end;
        finally
          FreeAndNil(list);
        end;

        if trim(zRoomRSet.FieldByName('GuestEmail').asString) <> '' then
        begin
          if zEmailAddress = '' then
          begin
            zEmailAddress := QuotedStr(trim(zRoomRSet.FieldByName('GuestEmail').asString))
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
        s := 'SELECT '#10;
        s := s + 'rd.ADate, '#10;
        s := s + 'rd.Room, '#10;
        s := s + 'rd.RoomReservation, '#10;
        s := s + 'rd.Reservation, '#10;
        s := s + 'rd.PriceCode, '#10;
        s := s + 'rd.RoomRate, '#10;
        s := s + 'rd.Currency, '#10;
        s := s + 'rd.Discount, '#10;
        s := s + 'rd.isPercentage, '#10;
        s := s + 'rd.showDiscount, '#10;
        s := s + 'rd.Paid '#10;
        s := s + ',IF(ISNULL((SELECT name FROM persons pe WHERE pe.MainName AND pe.roomreservation = rd.roomreservation LIMIT 1)), '#10;
        s := s + '   (SELECT name FROM persons pe WHERE pe.roomreservation = rd.roomreservation LIMIT 1), '#10;
        s := s + '   (SELECT name FROM persons pe WHERE pe.MainName AND pe.roomreservation = rd.roomreservation LIMIT 1)) AS guestName '#10;
        s := s + 'FROM roomsdate rd '#10;
        s := s + 'WHERE '#10;
        s := s + '(rd.roomreservation = %d) AND (rd.paid=0) AND rd.ResFlag NOT IN (''X'', ''C'') '#10;
        s := s + 'ORDER BY '#10;
        s := s + '  ADate '#10;
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
          AverageDiscountPerc := zRoomRSet.FieldByName('discount').AsFloat;

          mRoomRes.append;
          mRoomRes.FieldByName('RoomReservation').asinteger := lRoomReservation;
          mRoomRes.FieldByName('room').asString := Room;
          mRoomRes.FieldByName('RoomType').asString := RoomType;
          mRoomRes.FieldByName('Package').asString := package;
          mRoomRes.FieldByName('Guests').asinteger := NumberGuests;
          mRoomRes.FieldByName('AvragePrice').AsFloat := AverageRate;
          mRoomRes.FieldByName('RateCount').AsFloat := RateCount;
          mRoomRes.FieldByName('RoomDescription').asString := RoomDescription;
          mRoomRes.FieldByName('RoomTypeDescription').asString := RoomTypeDescription;
          mRoomRes.FieldByName('arrival').asdateTime := Arrival;
          mRoomRes.FieldByName('departure').asdateTime := Departure;
          mRoomRes.FieldByName('ChildrenCount').asinteger := ChildrenCount;
          mRoomRes.FieldByName('InfantCount').asinteger := infantCount;
          mRoomRes.FieldByName('PriceCode').asString := PriceCode;
          mRoomRes.FieldByName('AvrageDiscount').AsFloat := AverageDiscountPerc;
          mRoomRes.FieldByName('InvoiceIndex').asinteger := FInvoiceIndex;
          mRoomRes.FieldByName('GroupAccount').asBoolean := zRoomRSet['GroupAccount'];

          if package <> '' then
            if glb.LocateSpecificRecordAndGetValue('packages', 'Package', package, 'showItemsOnInvoice', showPackage)
            then
              chkShowPackage.checked := showPackage;

          dayCount := trunc(Departure) - trunc(Arrival);
          RateDate := Arrival;
          TotalDiscountAmount := 0;

          TotalRate := 0;
          UnpaidDays := 0;
          allIsPercentage := True;

          rSet := lExecutionPlan.Results[index];

          rSet.first;
          if NOT rSet.eof then
          begin
            GuestName := rSet.FieldByName('guestName').asString;
            if mRoomRes.State IN [dsEdit, dsInsert] then
            begin
              mRoomRes.FieldByName('Guests').asinteger := NumberGuests;
              mRoomRes.FieldByName('GuestName').asString := GuestName;
              mRoomRes.post;
            end;
            for i := 1 to dayCount do
            begin
              DiscountText := '';

              if LocateDate(rSet, 'ADate', RateDate) then
              begin
                reservation := rSet.FieldByName('Reservation').asinteger;
                Room := rSet.FieldByName('Room').asString;
                PriceCode := rSet.FieldByName('PriceCode').asString;
                RateDate := SQLToDate(rSet.FieldByName('ADate').asString);
                Rate := rSet.FieldByName('RoomRate').AsFloat; // in selected currency
                lCurrency := rSet.FieldByName('Currency').asString;
                Discount := rSet.FieldByName('Discount').AsFloat;
                isPercentage := rSet.FieldByName('isPercentage').asBoolean;
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
                try
                  CurrencyRate := GetRate(lCurrency);
                  // CurrencyRate := _StrToFloat(edtRate.Text);
                except
                  CurrencyRate := 1
                end;

                if CurrencyRate = 0 then
                  CurrencyRate := 1;

                NativeAmount := rentAmount * CurrencyRate;

                TotalDiscountAmount := TotalDiscountAmount + DiscountAmount;

                TotalRate := TotalRate + Rate;
                allIsPercentage := allIsPercentage and isPercentage;

                mRoomRates.append;
                mRoomRates.FieldByName('Reservation').asinteger := reservation;
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

                if package <> '' then
                begin
                  isPackage := True;
                  _s := Package_getRoomDescription(Package, Room, Arrival, Departure, GuestName);
                  if FRoomReservation = 0 then
                    _s := _s + ' Room :' + Room;

                end
                else
                begin
                  lRoomText := GetTranslatedText('shRoom');
                  _s := format(lRoomText + ' %s on %s', [Room, FormatDateTime('dd/mm', RateDate)])
                end;

                sText := _s;

                tmp := trim(zRoomRSet.FieldByName('rrDescription').asString);

                if copy(tmp, 1, 2) = '--' then
                  sText := '';
                sText := tmp + sText;

                if isPercentage then
                  DiscountText := DiscountText + '(' + floattostr(Discount) + '%)';

                AddRoom(Room, Rate, lCurrency, RateDate, RateDate + 1, 1, sText, (FRoomReservation = 0),
                  lRoomReservation, DiscountAmount, isPercentage, DiscountText, GuestName, NumberGuests, ChildrenCount,
                  isPackage, lRoomReservation, zRoomRSet.FieldByName('invBreakFast').asBoolean);

              end;

              RateDate := RateDate + 1;
            end;
          end;

          iTotalResDays := trunc(Departure) - trunc(Arrival);
          GuestsInRoomRes := NumberGuests; // ChildrenCount+infantCount
          GuestNights := GuestsInRoomRes * UnpaidDays;
          RoomRentPaidDays := iTotalResDays - UnpaidDays;

          inc(index);
          zRoomRSet.Next;
        end;
      end;
    finally
      lExecutionPlan.Free;
    end;

    lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
    try
      iCurrentRow := agrLines.RowCount;

      RestoreTMPInvoicelines;

      // -- Then the invoice lines...

      sql := 'SELECT il.* ' + ' FROM invoicelines il where Reservation = %d ' + '   and RoomReservation = %d ' +
        '   and SplitNumber = %d ' + '   and InvoiceNumber = -1 AND InvoiceIndex = %d';
      sql := format(sql, [FReservation, FRoomReservation, FnewSplitNumber, FInvoiceIndex]);
      lExecutionPlan.AddQuery(sql);

      sql := 'SELECT * FROM payments ' + ' where Reservation = %d ' + '   and RoomReservation = %d ' +
        '   and InvoiceNumber = -1 AND InvoiceIndex = %d';
      sql := format(sql, [FReservation, FRoomReservation, FInvoiceIndex]);
      lExecutionPlan.AddQuery(sql);

      sql := 'SELECT SUM(IF(xxx.RoomReservation>0 AND xxx.Reservation>0, xxx.NumberOfGuests * xxx.NumberOfDays, ' +
        ' (SELECT SUM((SELECT COUNT(id) FROM roomsdate WHERE RoomReservation = pe.RoomReservation AND NOT (ResFlag IN (''X'',''C'',''N'')))) AS GuestNights '
        + '   FROM persons pe ' + '   WHERE pe.Reservation=xxx.Reservation) ' + ')) AS NumberGuestNights, ' +
        'SUM(NumberOfDays) AS NumberOfDays, ' + 'SUM(NumberOfGuests) AS NumberOfGuests ' + 'FROM ( ' +
        'SELECT RoomReservation, Reservation, IF(il.RoomReservation>0 AND il.Reservation>0, (SELECT COUNT(ID) FROM roomsdate WHERE RoomReservation=il.RoomReservation AND NOT (ResFlag IN (''X'',''C'',''N'')) LIMIT 1), '
        + '          IF(il.Reservation>0, (SELECT COUNT(ID) FROM roomsdate WHERE Reservation=il.Reservation AND NOT (ResFlag IN (''X'',''C'',''N'')) LIMIT 1), '
        + '          0)) AS NumberOfDays, ' + ' ' +
        '       IF(il.RoomReservation>0 AND il.Reservation>0, (SELECT COUNT(ID) FROM persons WHERE RoomReservation=il.RoomReservation LIMIT 1), '
        + '          IF(il.Reservation>0, (SELECT COUNT(ID) FROM persons WHERE Reservation=il.Reservation LIMIT 1), 0)) AS NumberOfGuests '
        +

        'FROM roomreservations il ' + 'where (%d <= 0 AND Reservation=%d) OR (RoomReservation = %d) ' + ')xxx';
      sql := format(sql, [FRoomReservation, FReservation, FRoomReservation]);
      lExecutionPlan.AddQuery(sql);

      lExecutionPlan.Execute(ptQuery);

      eSet := lExecutionPlan.Results[0];
      reservationSet := lExecutionPlan.Results[2];

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

        AddLine(LineId, nil, ItemId, _s, dNumber, Price, g.qNativeCurrency, eSet.FieldByName('VATType').asString,
          SQLToDate(eSet.FieldByName('PurchaseDate').asString), false,
          trim(eSet.FieldByName('importRefrence').asString), trim(eSet.FieldByName('importSource').asString),
          eSet.FieldByName('isPackage').asBoolean, eSet.FieldByName('Persons').asinteger,
          eSet.FieldByName('ConfirmDate').asdateTime, eSet.FieldByName('ConfirmAmount').AsFloat, lRoomReservation,
          eSet.FieldByName('AutoGen').asString, eSet.FieldByName('ItemNumber').asinteger);

        eSet.Next;
      end;

      eSet := lExecutionPlan.Results[1];

      if (FReservation = 0) and (FRoomReservation = 0) then
      begin
        // what
      end
      else
      begin
        eSet.first;

        mPayments.close;
        mPayments.Open;

        while not eSet.eof do
        begin
          // **HJ
          mPayments.insert;
          mPayments.FieldByName('PayType').asString := eSet.FieldByName('PayType').asString;
          mPayments.FieldByName('PayDate').asdateTime := SQLToDateTime(eSet.FieldByName('PayDate').asString);
          mPayments.FieldByName('Amount').AsFloat := eSet.FieldByName('Amount').AsFloat;
          mPayments.FieldByName('Description').asString := eSet.FieldByName('Description').asString;
          mPayments.FieldByName('PayGroup').asString := '';
          mPayments.FieldByName('Memo').asString := eSet.FieldByName('Notes').asString;
          mPayments.FieldByName('confirmDate').asdateTime := eSet.FieldByName('Confirmdate').asdateTime;
          mPayments.FieldByName('Id').asinteger := eSet.FieldByName('ID').asinteger;

          if glb.Paytypesset.Locate('payType', eSet.FieldByName('PayType').asString, []) then
          begin
            mPayments.FieldByName('PayGroup').asString := glb.Paytypesset.FieldByName('payGroup').asString;
          end;
          mPayments.post;
          eSet.Next;
        end;
      end;

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

  finally
    zrSet.Free;
    zRoomRSet.Free;
    mRoomRes.EnableControls;
    mRoomRates.EnableControls;
    agrLines.EndUpdate;
    Screen.Cursor := crDefault;
    zFirsttime := True;
  end;

  UpdateItemInvoiceLinesForTaxCalculations;

  AddEmptyLine(false);

  UpdateGrid;
  SetCurrentVisible;

  UpdateInvoiceIndexTabs;

  UpdateControls;
end;

function TfrmInvoiceRentPerDay.LocateDate(recordSet: TRoomerDataset; field: String; Value: TDate): boolean;
begin
  result := false;
  recordSet.first;
  while NOT recordSet.eof do
  begin
    if recordSet[field] = _db(Value, false) then
    begin
      result := True;
      Break;
    end;
    recordSet.Next;
  end;
end;

function TfrmInvoiceRentPerDay.FindLastRoomRentLine: integer;
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

procedure TfrmInvoiceRentPerDay.UpdateItemInvoiceLinesForTaxCalculations;
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

  zCurrentCurrency := edtDisplayCurrency.Text;
  zCurrencyRate := GetRate(zCurrentCurrency);

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
        lInvRoom := TInvoiceRoomEntity.Create(Item, taxGuests, 0, taxNights, ItemPrice, 0, 0, false);
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

procedure TfrmInvoiceRentPerDay.calcAndAddAutoItems(reservation: integer; aAutoItems: TInvoiceAutoItemSet);
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

  zCurrentCurrency := edtDisplayCurrency.Text;
  zCurrencyRate := GetRate(zCurrentCurrency);

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
          lInvRoom := TInvoiceRoomEntity.Create(Item, taxGuests, taxChildren, taxNights, ItemPrice, 0, Discount,
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
            RoomInvoiceLines.Add(TInvoiceRoomEntity.Create(Item, taxGuests, taxChildren, taxNights, ItemPrice, itemVAT,
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

procedure TfrmInvoiceRentPerDay.CalcAndAddIncludedBreakFast(aRoominvoiceLinesList: TInvoiceRoomEntityList);
begin
  if glb.PMSSettings.InvoiceSettings.ShowIncludedBreakfastOnInvoice then
  begin
    AddIncludedBreakfastToLinesAndGrid(aRoominvoiceLinesList.IncludedBreakfastCount, FindLastRoomRentLine + 1);
    DisplayTotals;
  end;
end;

procedure TfrmInvoiceRentPerDay.AddIncludedBreakfastToLinesAndGrid(aIncludedBreakfastCount: integer;
  aPurchaseDate: TDate; iAddAt: integer = 0; aParent: TInvoiceLine = nil);
var
  lText: string;
  lInvoiceLine: TInvoiceLine;
  lItem: string;
  lItemInfo: TItemTypeInfo;
begin
  if zFromKredit or (aIncludedBreakfastCount = 0) then
    exit;

  lItem := g.qBreakFastItem;
  lText := Item_GetDescription(lItem) + ' (' + GetTranslatedText('shTx_ReservationProfile_Included') + ')';
  lItemInfo := d.Item_Get_ItemTypeInfo(lItem);
  lInvoiceLine := AddLine(0, aParent, lItem, lText, aIncludedBreakfastCount, Item_GetPrice(lItem),
    g.qNativeCurrency, lItemInfo.VATCode, aPurchaseDate, True, '', '', false, 0, 0, 0, -1, _GetCurrentTick, 0, False);

  lInvoiceLine.TotalIsIncludedInParent := True;

end;

function TfrmInvoiceRentPerDay.GetInvoiceLineVisibility(aReservation: integer; aRoomReservation:integer; aInvoiceIndex: integer;
                                                     aPurchaseDate: TDate; const aItem: string; aDefault: boolean): boolean;
var
  s: string;
  rSet: TRoomerDataset;
begin
  Result := aDefault;
  s := Format(select_GetInvoiceLineVisible, [_db(aReservation), _db(aRoomReservation), _db(aInvoiceIndex), _db(aPurchaseDate), _db(aItem)]);
  rSet := CreateNewDataSet;
  try
    if rSet_bySQL(rSet, s) then
      Result := rSet.FieldByName('visible').AsBoolean;
  finally
    rSet.Free;
  end;
end;

procedure TfrmInvoiceRentPerDay.GetTaxTypes(TaxResultInvoiceLines: TInvoiceTaxEntityList);
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

procedure TfrmInvoiceRentPerDay.UpdateControls(aRow: integer=0);
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

    actMoveRoomToTemp.Enabled := ((sCurrentItem = sRoomRentItem) OR (sCurrentItem = sDiscountItem)) OR
      (AnyRowChecked AND IsRoomSelected);
    btnMoveRoom.Enabled := actMoveRoomToTemp.Enabled;

    actMoveItemToTemp.Enabled := AnyRowChecked OR ((NOT isSystemLine(lRow)) AND (sCurrentItem <> ''));
    actMoveItemToGroupInvoice.Enabled := actMoveItemToTemp.Enabled OR AnyRowChecked;
    actRemoveSelected.Enabled := actMoveItemToTemp.Enabled OR AnyRowChecked;
    btnMoveItem.Enabled := actMoveItemToTemp.Enabled;
  end
  else
  begin
    actMoveItemToTemp.Enabled := AnyRowChecked;
    actMoveItemToGroupInvoice.Enabled := actMoveItemToTemp.Enabled;
    btnMoveRoom.Enabled := actMoveItemToTemp.Enabled AND IsRoomSelected;
    actRemoveSelected.Enabled := actMoveItemToTemp.Enabled;
    btnMoveItem.Enabled := actMoveItemToTemp.Enabled;
  end;

  if FStayTaxEnabled then
    actToggleLodgingTax.Caption := GetTranslatedText('shUI_InvoiceDisableLodgingTax')
  else
    actToggleLodgingTax.Caption := GetTranslatedText('shUI_InvoiceEnableLodgingTax');

  actToggleLodgingTax.Enabled := actMoveRoomToTemp.Enabled;
  btnReservationNotes.Enabled := actMoveRoomToTemp.Enabled;
end;

function TfrmInvoiceRentPerDay.GenerateInvoiceNumber: integer;
var
  iTemp: DWord;
begin
  iTemp := GetTickCount;
  if iTemp > 2100000000 then
    iTemp := 999999 + (iTemp - 2100000000)
  else if iTemp < 999999 then
    iTemp := 999999 + iTemp;
  result := iTemp;
end;

procedure TfrmInvoiceRentPerDay.DeleteLinesInList(ExecutionPlan: TRoomerExecutionPlan);
var
  i: integer;
begin
  for i IN DeletedLines do
  begin
    ExecutionPlan.AddExec('DELETE FROM invoicelines WHERE ID=' + inttostr(i));
  end;
end;

constructor TfrmInvoiceRentPerDay.Create(aOwner: TComponent);
begin
  DeletedLines := TList<integer>.Create;
  SelectableRooms := TRoomInfoList.Create(True);
  SelectableExternalRooms := TRoomInfoList.Create(True);
  TaxTypes := TStringList.Create;

  FInvoiceLinesList := TInvoiceLineList.Create;
  FRoomInfoList := TRoomInfoList.Create(True);
  tempInvoiceItemList := TInvoiceItemEntityList.Create(True);
  FCurrencyhandlersMap := TCurrencyhandlersMap.Create;

  inherited;

end;

procedure TfrmInvoiceRentPerDay.FormCreate(Sender: TObject);
begin
  zErr := false;
  zFirsttime := True;

  linesNumDays := 0;
  linesNumGuests := 0;
  NumberGuestNights := 0;

  FInvoiceIndex := 0;

  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);

  tempInvoiceNo := GenerateInvoiceNumber;
  zEmailAddress := '';

  zDoSave := True;

  zLocation := '';
  zOriginalInvoice := 0;

  FCellValueBeforeEdit := '';
  FCellDoubleBeforeEdit := 0.00;

  zbDoingReference := false;

  vDec := 2;

  zCurrencyRate := 1.00;

end;

procedure TfrmInvoiceRentPerDay.FormDestroy(Sender: TObject);
begin
  OnResize := nil;
  SelectableRooms.Free;
  SelectableExternalRooms.Free;
  RemoveInvalidKreditInvoice;

  ClearGrid;
  FInvoiceLinesList.Free;
  FRoomInfoList.Free;
  DeletedLines.Free;

  if mRoomRes.active then
    mRoomRes.close;
  if mRoomRates.active then
    mRoomRates.close;

  TaxTypes.Free;
  tempInvoiceItemList.Free;

  frmMain.btnRefresh.Click;
end;

procedure TfrmInvoiceRentPerDay.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    btnExit.Click;
end;

procedure TfrmInvoiceRentPerDay.FormResize(Sender: TObject);
begin
  agrLines.AutoFitColumns(false);
end;

procedure TfrmInvoiceRentPerDay.FormShow(Sender: TObject);
begin
  btnEditDownPayment.Visible := glb.PMSSettings.InvoiceSettings.AllowPaymentModification;
  btnDeleteDownpayment.Visible := glb.PMSSettings.InvoiceSettings.AllowPaymentModification;
  actRemoveSelected.Visible := glb.PMSSettings.InvoiceSettings.AllowDeletingItemsFromInvoice;
  actToggleLodgingTax.Visible := glb.PMSSettings.InvoiceSettings.AllowTogglingOfCityTaxes;

  LoadInvoice;
  UpdateCaptions;

  sPanel4.Visible := NOT(IsCashInvoice OR FIsCredit { or zFakeGroup } );
  Exit1.Enabled := True;
end;

procedure TfrmInvoiceRentPerDay.N91Click(Sender: TObject);
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

procedure TfrmInvoiceRentPerDay.ExternalRoomsClick(Sender: TObject);
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

procedure TfrmInvoiceRentPerDay.TransferRoomToAnyRoomsClick(Sender: TObject);
var
  omnu: TMenuItem;
  list: TList<String>;
  i, l, RealRoomReservation: integer;
begin
  //
  omnu := TMenuItem(Sender);

  list := GetSelectedRows;
  try
    for l := list.Count - 1 downto 0 do
    begin
      i := IndexOfAutoGen(list[l]);
      if i >= 0 then
      begin
        agrLines.row := i;
        RealRoomReservation := GetInvoiceLineByRow(i).RoomEntity.RoomReservation;
        TransferRoomToAnotherRoomReservationInvoice(FRoomReservation, SelectableExternalRooms[omnu.Tag].RoomReservation,
          RealRoomReservation, SelectableExternalRooms[omnu.Tag].reservation);
      end;
    end;
  finally
    list.Free;
  end;
end;

procedure TfrmInvoiceRentPerDay.TransferRoomToAnotherRoomReservationInvoice(FromRoomReservation, RoomReservation,
  RealRoomReservation, reservation: integer);
var
  sql: String;
begin
  if RealRoomReservation = RoomReservation then
    sql := format('UPDATE roomsdate rd SET PaidBy=0 WHERE RoomReservation=%d AND (ResFlag NOT IN (''X'',''C''))',
      [RealRoomReservation])
  else
    sql := format('UPDATE roomsdate rd SET PaidBy=%d WHERE RoomReservation=%d AND (ResFlag NOT IN (''X'',''C''))',
      [RoomReservation, FromRoomReservation]);
  copytoclipboard(sql);
  d.roomerMainDataSet.DoCommand(sql, false);
  LoadInvoice;
end;

procedure TfrmInvoiceRentPerDay.NullifyGrid;
begin
  agrLines.UnHideColumnsAll;
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
procedure TfrmInvoiceRentPerDay.AddEmptyLine(CheckChanged: boolean = True);
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
procedure TfrmInvoiceRentPerDay.AddAndInitNewRow;
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

procedure TfrmInvoiceRentPerDay.UpdateCaptions;
var
  invNo: integer;
begin
  Caption := GetTranslatedText('shUI_InvoiceCaption');

  labTmpStatus.Caption := inttostr(d.kbmInvoicelines.RecordCount);

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

  OriginalInvoiceStatus := GridFloatValueFromString(edtBalance.Text);
end;

procedure TfrmInvoiceRentPerDay.agrLinesMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
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

procedure TfrmInvoiceRentPerDay.agrLinesMouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState;
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
          if EditRoomRates(lROomResList, FInvoiceIndex, zCurrentCurrency, lGotoRoomRes) then
          begin
            SaveAnd(false);
            zFirsttime := false;
            LoadInvoice;
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

procedure TfrmInvoiceRentPerDay.agrLinesRowChanging(Sender: TObject; OldRow, NewRow: Integer; var Allow: Boolean);
begin
  UpdateControls(NewRow);
end;

procedure TfrmInvoiceRentPerDay.CheckOrUncheckAll(check: boolean);
var
  i: integer;
begin
  for i := 0 to agrLines.RowCount - 1 do
    if agrLines.HasCheckBox(col_Select, i) then
      agrLines.SetCheckBoxState(col_Select, i, check);
end;

procedure TfrmInvoiceRentPerDay.Exit1Click(Sender: TObject);
begin
  btnExit.Click;
end;

procedure TfrmInvoiceRentPerDay.RemoveInvalidKreditInvoice;
var
  i: integer;
begin
  for i := LOW(REMOVE_REDUNDANT_INVOICES) to HIGH(REMOVE_REDUNDANT_INVOICES) do
    d.roomerMainDataSet.DoCommand(REMOVE_REDUNDANT_INVOICES[i]);
end;

function TfrmInvoiceRentPerDay.CompletePayments(var aInvoiceDate: TDate; var aPayDate: TDate;
  var aLocation: string): boolean;
var
  lstLocations: TStringList;
  lOpenBalance: Double;
begin
  result := false;
  lstLocations := TStringList.Create;
  try

    if FRoomReservation = 0 then
      d.GetReservationLocations(FReservation, lstLocations)
    else
      d.GetRoomReservationLocations(FRoomReservation, lstLocations);

    lOpenBalance := FInvoiceLinesList.TotalOnInvoiceNativeCurrency - getDownPayments;
    if SelectPaymentTypes(lOpenBalance, edtCustomer.Text, ptInvoice, edtDisplayCurrency.Text,
      GetRate(edtDisplayCurrency.Text), FReservation, lstLocations, aInvoiceDate, aPayDate, aLocation) then
      with FCurrencyhandlersMap.CurrencyHandler[g.qNativeCurrency] do
        result := (RoundedValue(GatherPayments(stlPaySelections)) = RoundedValue(lOpenBalance));

  finally
    lstLocations.Free;
  end;
end;

procedure TfrmInvoiceRentPerDay.SaveHeader(aInvoiceNumber: integer; aExecutionPlan: TRoomerExecutionPlan; const aInvoiceLocation: string);
var
  iMultiplier: integer;
var
  s: string;
  showPackage: boolean;
begin
  showPackage := chkShowPackage.checked;

  iMultiplier := 1;

  if FIsCredit then
    iMultiplier := -1;

  s := format('INSERT INTO invoiceaddressees ' + '(InvoiceIndex, ' + 'Reservation, ' + 'RoomReservation, ' +
    'SplitNumber, ' + 'InvoiceNumber, ' + 'Customer, ' + 'Name, ' + 'Address1, ' + 'Address2, ' + 'Zip, ' + 'City, ' +
    'Country, ' + 'ExtraText, ' + 'custPID, ' + 'InvoiceType, ' + 'ihCurrency) ' + 'VALUES ' + '(%d, ' + '%d, ' + '%d, '
    + '%d, ' + '%d, ' + '%s, ' + '%s, ' + '%s, ' + '%s, ' + '%s, ' + '%s, ' + '%s, ' + '%s, ' + '%s, ' + '%d, ' +
    '%s) ', [InvoiceIndex, FReservation, FRoomReservation, FnewSplitNumber, aInvoiceNumber, _db(edtCustomer.Text),
    _db(edtName.Text), _db(edtAddress1.Text), _db(edtAddress2.Text), _db(edtAddress3.Text), _db(edtAddress4.Text),
    _db(zCountry), _db(memExtraText.Lines.Text), _db(edtPersonalId.Text), rgrInvoiceType.itemIndex,
    _db(edtDisplayCurrency.Text)]) +

    format('ON DUPLICATE KEY UPDATE ' + 'InvoiceNumber=%d, ' + 'Customer=%s, ' + 'Name=%s, ' + 'Address1=%s, ' +
    'Address2=%s, ' + 'Zip=%s, ' + 'City=%s, ' + 'Country=%s, ' + 'ExtraText=%s, ' + 'custPID=%s, ' + 'InvoiceType=%d, '
    + 'ihCurrency=%s', [aInvoiceNumber, _db(edtCustomer.Text), _db(edtName.Text), _db(edtAddress1.Text),
    _db(edtAddress2.Text), _db(edtAddress3.Text), _db(edtAddress4.Text), _db(zCountry), _db(memExtraText.Lines.Text),
    _db(edtPersonalId.Text), rgrInvoiceType.itemIndex, _db(edtDisplayCurrency.Text)]);

  aExecutionPlan.AddExec(s);
  copytoclipboard(s);

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
  s := s + ', ' + _db(FnewSplitNumber);
  s := s + ', ' + _db(aInvoiceNumber);
  s := s + ', ' + _db(zInvoiceDate, True);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Customer FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    FnewSplitNumber, InvoiceIndex, _db(edtCustomer.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Name FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    FnewSplitNumber, InvoiceIndex, _db(edtName.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT CustPid FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    FnewSplitNumber, InvoiceIndex, _db(edtPersonalId.Text)]);
  s := s + ', ' + _db(edtRoomGuest.Caption);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Address1 FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    FnewSplitNumber, InvoiceIndex, _db(edtAddress1.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Address2 FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    FnewSplitNumber, InvoiceIndex, _db(edtAddress2.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Zip FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    FnewSplitNumber, InvoiceIndex, _db(edtAddress3.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT City FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    FnewSplitNumber, InvoiceIndex, _db(edtAddress4.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Country FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' + '        AND ia.RoomReservation=%d ' + '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' + '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation,
    FnewSplitNumber, InvoiceIndex, _db(zCountry)]);
  s := s + ', ' + _CommaToDot(floattostr(iMultiplier * FInvoiceLinesList.TotalOnInvoiceNativeCurrency));
  s := s + ', ' + _CommaToDot(floattostr(iMultiplier * FInvoiceLinesList.TotalOnInvoiceNativeCurrency -
    FInvoiceLinesList.TotalVatOnInvoiceNativeCurrency));
  s := s + ', ' + _CommaToDot(floattostr(iMultiplier * FInvoiceLinesList.TotalVatOnInvoiceNativeCurrency));
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
  s := s + ', ' + _db(edtDisplayCurrency.Text);
  s := s + ', ' + _db(GetRate(edtDisplayCurrency.Text));
  s := s + ', ' + _db(showPackage);
  s := s + ', ' + _db(aInvoiceLocation);
  s := s + ', ' + _db(FInvoiceLinesList.TotalCityTaxRevenues);
  s := s + ', ' + _db(FInvoiceLinesList.CityTaxUnitCount);
  s := s + ')' + #10;

  copytoclipboard(s);
  aExecutionPlan.AddExec(s);
end;

function TfrmInvoiceRentPerDay.SaveInvoice(aInvoiceNumber: integer; aSaveType: TInvoiceSaveType; const aInvoiceLocation: string = ''): boolean;
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
          lstActivity.Add(CreateInvoiceActivityLog(g.qUser, FReservation, FRoomReservation, FnewSplitNumber, ADD_LINE,
            invoiceLine.Item, invoiceLine.Total, aInvoiceNumber, invoiceLine.Text));
      end;

      SaveHeader(aInvoiceNumber, lExecutionPlan, aInvoiceLocation);

      if (aSaveType = stDefinitive) then
      begin
        SaveCompletePayments(aInvoiceNumber, lExecutionPlan, lstActivity);
        SetInvoiceNumberOfPayments(aInvoiceNumber, lExecutionPlan);
      end
      else if (aSaveType = stProforma) then
        CopyPaymentsForProforma(aInvoiceNumber, lExecutionPlan);

      if not lExecutionPlan.Execute(ptExec, True, True) then
        raise Exception.Create(lExecutionPlan.ExecException);

      FHeaderChanged := false;
      for invoiceLine in FInvoiceLinesList do
        invoiceLine.Changed := false;

      if (aSaveType = stDefinitive) then
      begin

        if FIsCredit and (zCreditType = ctReference) then
        begin
          MarkOriginalInvoiceAsCredited(aInvoiceNumber);

          if (MessageDlg(GetTranslatedText('shTx_Invoice_OpenInvoiceAfterPrintCredit'), mtConfirmation, [mbYes, mbNo],
            0) = mrYes) then
            d.copyInvoiceToInvoiceLinesTmp(zRefNum, True);
        end;

        // zDoSave := false;
        // SaveAnd(false);                           //????????????

        try
          result := True;
          try
            SendInvoicesToFinancePacketThreaded(aInvoiceNumber);
          except
            on e: Exception do
            begin
              ShowMessage('Ekki t�kst ad senda reikning No. ' + inttostr(zInvoiceNumber) +
                ' til b�khaldskerfisins. Vinsamlega sendi� reikninginn handvirkt s��ar ');
              AddRoomerActivityLog(d.roomerMainDataSet.username, ERROR, e.message,
                format('Exception while sending invoice to booking keeping. Invoice %d, RoomReservation %d, Reservation %d -> %s',
                [aInvoiceNumber, FRoomReservation, FReservation, e.message]));
            end;
          end;
        finally
          lstActivity.Add(CreateInvoiceActivityLog(g.qUser, FReservation, FRoomReservation, FnewSplitNumber,
            PAY_AND_PRINT, inttostr(aInvoiceNumber), FInvoiceLinesList.TotalOnInvoiceNativeCurrency, 0,
            'Invoice added '));

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

      s := format(s, [FReservation, FRoomReservation, FnewSplitNumber, FInvoiceIndex]);

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

procedure TfrmInvoiceRentPerDay.SaveInvoicelineVisibility(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
var
  s: string;
  lResnr: integer;
  lRoomResNr: integer;
begin
  // Store set visiblity in invoicelines_visiblity
  // Notice that this only has to be done for generated lines and provisionally invoices as otherwise
  // the visiblity is stored in the invoicelines.VisibleOnInvoice field

  if not aInvoiceLine.CanBeHiddenFromInvoice then
    Exit;

  lresNr := aInvoiceLine.ParentReservation;
  lRoomResNr := aInvoiceLine.ParentRoomReservation;

  // fallback
  if lresNr = -1 then
    lResNr := FReservation;
  if lRoomResNr = -1 then
    lResNr := FRoomReservation;

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
  s := s + ' ,' + _db(aInvoiceLine.PurchaseDate)+#10;
  s := s + ' ,' + _db(aInvoiceLine.Item)+#10;
  s := s + ' ,' + _db(aInvoiceLine.VisibleOnInvoice)+#10;
  s := s + ') '#10;
  s := s + ' ON DUPLICATE KEY '#10;
  s := s + ' UPDATE visible = '+ _db(aInvoiceLine.VisibleOnInvoice)+#10;

  copyToClipboard(s);
  aExecPLan.AddExec(s);
end;

procedure TfrmInvoiceRentPerDay.RemoveInvoicelineVisibilityRecord(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
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
  s := s + ' and adate=' + _db(aInvoiceLine.PurchaseDate)+#10;
  s := s + ' and item=' + _db(aInvoiceLine.Item)+#10;

  copyToClipboard(s);
  aExecPLan.AddExec(s);
end;

procedure TfrmInvoiceRentPerDay.InsertOrUpdateInvoiceLine(aInvoiceLine: TInvoiceLine; aInvoiceNumber: integer;
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

  if aSaveType = stProvisionally then
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

  fItemTotal := aInvoiceLine.AmountOnInvoiceNativeCurrency;
  fItemTotalWOVat := fItemTotal - aInvoiceLine.VATOnInvoiceNativeCurrency;

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
    s := s + ', ' + _db(FnewSplitNumber);
    s := s + ', ' + _db(aInvoiceLine.InvoiceLineIndex);
    s := s + ', ' + _db(aInvoiceLine.PurchaseDate);
    s := s + ', ' + _db(aInvoiceNumber);
    s := s + ', ' + _db(aInvoiceLine.Item);
    s := s + ', ' + _db(aInvoiceLine.Number); // -96ath
    s := s + ', ' + _db(aInvoiceLine.Text);

    s := s + ', ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.PriceOnInvoiceNativeCurrency);

    s := s + ', ' + _db(lItemTypeInfo.VATCode);
    s := s + ', ' + _db(iCreditInvoiceMultiplier * fItemTotal);
    s := s + ', ' + _db(iCreditInvoiceMultiplier * fItemTotalWOVat);
    s := s + ', ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.VATOnInvoiceNativeCurrency);

    // If not storing provisionally, all records should set payment-currency = Currency of invoice
    if (aSaveType = stProvisionally) then
    begin
      s := s + ', ' + _db(GetRate(aInvoiceLine.Currency));
      s := s + ', ' + _db(aInvoiceLine.Currency);
    end
    else
    begin
      s := s + ', ' + _db(GetRate(edtDisplayCurrency.Text));
      s := s + ', ' + _db(edtDisplayCurrency.Text);
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
    s := s + ', ' + _db(aInvoiceLine.rrAlias);
    s := s + ', ' + _db(FInvoiceIndex);
    s := s + ', ' + _db(d.roomerMainDataSet.username);
    s := s + ', ' + _db(aInvoiceLine.VisibleOnInvoice);
    s := s + ', ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.RevenueNativeCurrency);

    s := s + ')' + #10;
  end
  else
  begin
    s := 'UPDATE invoicelines' + ' Set ItemNumber= ' + _db(aInvoiceLine.InvoiceLineIndex) + ' , InvoiceNumber= ' +
      _db(aInvoiceNumber) + ' , Description= ' + _db(aInvoiceLine.Text) + ' , Number= ' + _db(aInvoiceLine.Number) +
      ' , Price= ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.PriceNativeCurrency) + ' , Total= ' +
      _db(iCreditInvoiceMultiplier * fItemTotal) + ' , TotalWOVat= ' + _db(iCreditInvoiceMultiplier * fItemTotalWOVat) +
      ' , VAT= ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.VATOnInvoiceNativeCurrency);

    // If not storing provisionally, all records should set payment-currency = Currency of invoice
    if (aSaveType = stProvisionally) then
    begin
      s := s + ' , CurrencyRate= ' + _db(GetRate(aInvoiceLine.Currency));
      s := s + ' , Currency= ' + _db(aInvoiceLine.Currency);
    end
    else
    begin
      s := s + ' , CurrencyRate= ' + _db(GetRate(edtDisplayCurrency.Text));
      s := s + ' , Currency= ' + _db(edtDisplayCurrency.Text);
    end;

    s := s + ' , Persons= ' + _db(aInvoiceLine.noGuests) + ' , Nights= ' + _db(iNights) + ' , ilAccountKey= ' +
      _db(sAccountKey) + ' , InvoiceIndex= ' + _db(FInvoiceIndex) + ' , staffLastEdit= ' +
      _db(d.roomerMainDataSet.username) + ' , VisibleOnInvoice = ' + _db(aInvoiceLine.VisibleOnInvoice) +
      ' , Revenue = ' + _db(iCreditInvoiceMultiplier * aInvoiceLine.RevenueNativeCurrency) + ' WHERE id=' +
      _db(aInvoiceLine.LineId);
  end;
  aExecPlan.AddExec(s);
  copytoclipboard(s);

  if (aSaveType = stDefinitive) then
  begin
    if (aInvoiceLine.ItemKind = ikRoomRent) then
      MarkRoomRentAsPaid(aInvoiceLine, aInvoiceNumber, aExecPlan);
    RemoveInvoicelineVisibilityRecord(aInvoiceLine, aInvoiceNumber, aExecPlan);
  end;
end;

procedure TfrmInvoiceRentPerDay.MarkRoomRentAsPaid(aInvLine: TInvoiceLine; aInvoiceNumber: integer;
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

procedure TfrmInvoiceRentPerDay.SaveCompletePayments(aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan;
  aActivityLog: TStringList);
var
  lPaymentType: string;
  lPaymentValue: Double;
  lPaymentDesc: string;
  i: integer;
  lYear, lMonth, lDay: Word;
  s: string;
begin

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
    s := s + ', ' + inttostr(FnewSplitNumber);

    s := s + ', ' + _db(edtCustomer.Text);

    s := s + ', ' + _db(_GetCurrentTick);

    s := s + ', ' + inttostr(aInvoiceNumber);
    s := s + ', ' + _db(zInvoiceDate, True);

    s := s + ', ' + _db(lPaymentType);
    s := s + ', ' + _db(lPaymentValue);
    s := s + ', ' + _db(lPaymentDesc);
    s := s + ', ' + _db(GetRate(edtDisplayCurrency.Text));
    s := s + ', ' + _db(edtDisplayCurrency.Text);
    s := s + ', 0';

    s := s + ', ' + inttostr(lYear);
    s := s + ', ' + inttostr(lMonth);
    s := s + ', ' + inttostr(lDay);
    s := s + ', ' + _db(d.roomerMainDataSet.username);
    s := s + ', ' + _db(FInvoiceIndex);
    s := s + ')';

    aExecPlan.AddExec(s);

    aActivityLog.Add(CreateInvoiceActivityLog(g.qUser, FReservation, FRoomReservation, FnewSplitNumber, ADD_PAYMENT,
      lPaymentType, lPaymentValue, zInvoiceNumber, lPaymentDesc));

  end;

end;

procedure TfrmInvoiceRentPerDay.SetInvoiceNumberOfPayments(aInvoiceNumber: integer;
  lExecutionPlan: TRoomerExecutionPlan);
var
  s: string;
begin
  s := '';
  s := s + ' UPDATE payments '#10;
  s := s + '  SET '#10;
  s := s + ' invoicenumber = ' + _db(aInvoiceNumber) + ' '#10;
  s := s + ' WHERE (reservation = %d) and (Roomreservation = %d) and (Invoicenumber=-1) and (InvoiceIndex=%d) and (typeindex=1); ';
  s := format(s, [FReservation, FRoomReservation, FInvoiceIndex]);
  lExecutionPlan.AddExec(s);
end;

procedure TfrmInvoiceRentPerDay.edtCustomerChange(Sender: TObject);
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

procedure TfrmInvoiceRentPerDay.edtCustomerDblClick(Sender: TObject);
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
    FHeaderChanged := True;
    UpdateTaxinvoiceLinesForAllRooms;
  end;
end;

procedure TfrmInvoiceRentPerDay.edtPersonalIdChange(Sender: TObject);
begin
  FHeaderChanged := True;
end;

procedure TfrmInvoiceRentPerDay.agrLinesGetAlignment(Sender: TObject; ARow, ACol: integer; var HAlign: TAlignment;
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
      HAlign := taLeftJustify;
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

procedure TfrmInvoiceRentPerDay.agrLinesGetCellColor(Sender: TObject; ARow, ACol: integer; AState: TGridDrawState;
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

procedure TfrmInvoiceRentPerDay.agrLinesGetDisplText(Sender: TObject; ACol, ARow: integer; var Value: string);
begin
  if (ARow > 0) and assigned(GetInvoiceLineByRow(ARow)) then
    if Value = trim(_floattostr(0, vWidth, vDec)) then
      Value := ''
end;

procedure TfrmInvoiceRentPerDay.agrLinesGetEditText(Sender: TObject; ACol, ARow: integer; var Value: string);
var
  lInvLine: TInvoiceLine;
begin
  lInvLine := GetInvoiceLineByRow(ARow);
  if (ACol = col_ItemPrice) and assigned(lInvLine) then
    Value := FCurrencyhandlersMap.CurrencyHandler[lInvLine.Currency].FormattedValue(lInvLine.Price, false);
  FCellValueBeforeEdit := agrLines.Cells[ACol, ARow];
  FCellDoubleBeforeEdit := StrToFloatDef(FCellValueBeforeEdit, 0);
end;

procedure TfrmInvoiceRentPerDay.agrLinesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_RETURN then
  begin
    if agrLines.row < agrLines.RowCount - 1 then
      agrLines.row := agrLines.row + 1;
  end
end;

procedure TfrmInvoiceRentPerDay.itemLookup;
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
              lInvoiceLine.Changed := True;

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

procedure TfrmInvoiceRentPerDay.agrLinesCanEditCell(Sender: TObject; ARow, ACol: integer; var CanEdit: boolean);
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
    col_NoGuests, col_confirmdate, col_confirmAmount, col_TotalOnInvoice])) AND
    (TaxTypes.IndexOf(agrLines.Cells[col_Item, ARow]) < 0) // not a tax line
    AND not(isSystemLine(ARow) and (agrLines.Cells[col_Item, ARow] = g.qBreakFastItem)) // generated breakfast lines
    AND ((glb.GetNumberBaseOfItem(agrLines.Cells[col_Item, ARow]) = INB_USER_EDIT) OR
    (ACol IN [col_ItemPrice, col_Description]));

end;

function TfrmInvoiceRentPerDay.CheckExtraWithdrawalAllowed(aExtraAmount: Double): boolean;
begin
  result := True;
  if (FRoomReservation > 0) AND (NOT d.roomerMainDataSet.SystemIsRoomWithdrawalAllowed(FRoomReservation, aExtraAmount))
  then
  begin
    MessageDlg(GetTranslatedText('shUI_AmountOverAllowedWithdrawalLimit'), mtWarning, [mbOk], 0);
    result := false;
  end;
end;

procedure TfrmInvoiceRentPerDay.WndProc(var message: TMessage);
begin
  if Message.msg = WM_REDRAW_LINE then
  begin
    UpdateLine(Message.LParam);
    DisplayTotals;
  end
  else
    inherited WndProc(message);
end;

procedure TfrmInvoiceRentPerDay.agrLinesCellValidate(Sender: TObject; ACol, ARow: integer; var Value: string;
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

            lInvoiceLine.Price := lNewValue;
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

procedure TfrmInvoiceRentPerDay.CheckBoxClick(Sender: TObject; ACol, ARow: integer; State: boolean);
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
    lInvoiceLine.VisibleOnInvoice := check;
    lInvoiceLine.Changed := True;

    UpdateGrid;
  end;
end;

function TfrmInvoiceRentPerDay.GetAnyRowSelected: boolean;
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

procedure TfrmInvoiceRentPerDay.agrLinesColumnSize(Sender: TObject; ACol: integer; var Allow: boolean);
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

procedure TfrmInvoiceRentPerDay.agrLinesDblClickCell(Sender: TObject; ARow, ACol: integer);
begin
  if ACol <> col_Item then
    exit;
  if agrLines.Cells[ACol, ARow] <> '' then
    exit;
  itemLookup;
end;

function TfrmInvoiceRentPerDay.GatherPayments(PayLines: TStringList): Double;
var
  tt: Double;
  i: integer;
  pmCode: string;
  pmAmount: Double;
  sTmp: string;

begin
  tt := 0;

  for i := 0 to PayLines.Count - 1 do
  begin
    pmCode := trim(_strTokenAt(PayLines[i], '|', 0));
    sTmp := trim(_strTokenAt(PayLines[i], '|', 1));

    try
      pmAmount := _StrToFloat(sTmp);
    except
      pmAmount := 0;
    end;
    if (pmCode <> '') and (pmAmount <> 0) then
    begin
      tt := tt + pmAmount;
    end;
  end;
  result := tt;
end;

// -- The original Invoice contains a special field which links it to the
// subceeding credit invoice. This is for traceback puurposes.
procedure TfrmInvoiceRentPerDay.MarkOriginalInvoiceAsCredited(iInvoice: integer);
var
  s: string;
begin
  s := '';
  s := s + 'UPDATE invoiceheads ' + #10;
  s := s + ' Set ' + #10;
  s := s + '  CreditInvoice ' + ' = ' + _db(iInvoice) + #10;
  s := s + ' where InvoiceNumber = ' + _db(zRefNum);
  if not cmd_bySQL(s) then
  begin
    ShowMessage('MarkOriginalInvoiceAsCredited');
  end;
end;

procedure TfrmInvoiceRentPerDay.MoveRoomToGroupInvoice;
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
    d.UpdateGroupAccountone(FReservation, FRoomReservation, FRoomReservation, True);
    SaveInvoice(zInvoiceNumber, stProvisionally);
    LoadInvoice;
  end;
end;

procedure TfrmInvoiceRentPerDay.MoveRoomToNewInvoiceIndex(toInvoiceIndex: integer);
begin
  d.UpdateGroupAccountone(reservation, RoomReservation, RoomReservation, RoomReservation = 0, toInvoiceIndex);
  InvoiceIndex := FInvoiceIndex;
end;

function TfrmInvoiceRentPerDay.IsRoomSelected: boolean;
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

procedure TfrmInvoiceRentPerDay.MoveRoomToRoomInvoice;
begin
  if FRoomReservation > 0 then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_RoomInvoice'));
    exit;
  end;
  chkChanged;
  if selectedRoomReservation < 0 then
    exit;

  // if (MessageDlg('Move roomrent to Groupinvoice ' + chr(10) + 'and save other changes ?', mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
  if (MessageDlg(GetTranslatedText('shTx_Invoice_RoomrentToRoomAndSaveChanges'), mtConfirmation, [mbYes, mbNo], 0)
    = mrYes) then
  begin
    d.UpdateGroupAccountone(FReservation, selectedRoomReservation, selectedRoomReservation, false);
    SaveInvoice(zInvoiceNumber, stProvisionally);
    LoadInvoice;
  end;
end;

procedure TfrmInvoiceRentPerDay.edtDisplayCurrencyDblClick(Sender: TObject);
var
  theData: recCurrencyHolder;
  oldCurrency: string;
begin
  if not IfInvoiceChangedThenOptionallySave(True) then
    exit;

  oldCurrency := trim(edtDisplayCurrency.Text);
  theData.Currency := oldCurrency;
  if Currencies(actLookup, theData) and (theData.Currency <> '') then
    ExecuteCurrencyChange(oldCurrency, theData.Currency);
end;

procedure TfrmInvoiceRentPerDay.agrLinesDrawCell(Sender: TObject; ACol, ARow: integer; Rect: TRect;
  State: TGridDrawState);
var
  Bmp: TIcon;
  Item: string;
begin
  inherited;
  // --
  if not edtForeignCurrency.Visible then
    exit;
  if (ACol <> 5) then
    exit;

  Item := trim(TAdvStringGrid(Sender).Cells[col_Item, ARow]);
  if (trim(g.qRoomRentItem) <> Item) and (trim(g.qDiscountItem) <> Item) then
    exit;

  try
    Bmp := TIcon.Create;
    try
      GridImages.GetIcon(0, Bmp);
      TAdvStringGrid(Sender).canvas.Draw(Rect.left + 1, Rect.top + 1, Bmp);
    finally
      Bmp.Free;
    end;
  except
  end;
end;

procedure TfrmInvoiceRentPerDay.UpdateRoomReservationsCurrency(const aFromCurrency: string; const aToCurrency: string);
var
  lOldRate: Double;
  lNewRate: Double;
  lFactor: Double;
  lRoomres: integer;
  lDate: string;
  rSet: TRoomerDataset;
  s: string;
  lExecPlan: TRoomerExecutionPlan;
begin
  if (FRoomReservation = 0) and (FReservation = 0) then
    exit;

  if aFromCurrency.ToLower.Equals(aToCurrency.ToLower) then
    exit;

  lOldRate := GetRate(aFromCurrency);
  lNewRate := GetRate(aToCurrency);

  if lNewRate = 0 then
    lNewRate := 1;
  lFactor := lOldRate / lNewRate;

  d.roomerMainDataSet.SystemStartTransaction;
  try

    rSet := CreateNewDataSet;
    try
      lExecPlan := TRoomerExecutionPlan.Create(rSet);
      try

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
                d.RR_Upd_CurrencyRoomPrice(lRoomres, lDate, aToCurrency, lFactor);
              end;
              mRoomRates.Next;
            end;
            s := '';
            s := s + ' UPDATE roomreservations ' + chr(10);
            s := s + ' SET ' + chr(10);
            s := s + ' Currency=' + _db(aToCurrency) + ' ' + chr(10);
            s := s + ' WHERE (RoomReservation = ' + inttostr(lRoomres) + ') ' + chr(10);
            lExecPlan.AddExec(s);

            rSet.Next;
          end;

          s := '';
          s := s + ' UPDATE invoiceheads '#10;
          s := s + ' SET '#10;
          s := s + '  ihCurrency = ' + _db(aToCurrency) + #10;
          s := s + ' ,ihCurrencyRate = ' + _db(lNewRate) + #10;
          s := s + ' WHERE (Reservation = ' + _db(FReservation) + ') ' + chr(10);
          lExecPlan.AddExec(s);

        end
        else if (FRoomReservation > 0) then
        begin
          mRoomRates.first;
          while not mRoomRates.eof do
          begin
            lDate := _db(mRoomRates.FieldByName('rateDate').asdateTime, false);
            d.RR_Upd_CurrencyRoomPrice(FRoomReservation, lDate, aToCurrency, lFactor);
            mRoomRates.Next;
          end;
          s := '';
          s := s + ' UPDATE roomreservations ' + chr(10);
          s := s + ' SET ' + chr(10);
          s := s + ' Currency=' + _db(aToCurrency) + ' ' + chr(10);
          s := s + ' WHERE (RoomReservation = ' + inttostr(FRoomReservation) + ') ' + chr(10);
          lExecPlan.AddExec(s);

          s := '';
          s := s + ' UPDATE invoiceheads '#10;
          s := s + ' SET '#10;
          s := s + '  ihCurrency = ' + _db(aToCurrency) + #10;
          s := s + ' ,ihCurrencyRate = ' + _db(lNewRate) + #10;
          s := s + ' WHERE (RoomReservation = ' + _db(FRoomReservation) + ') ' + chr(10);
          lExecPlan.AddExec(s);

        end;

        lExecPlan.Execute(ptExec, false, false);

        d.roomerMainDataSet.SystemCommitTransaction;

      finally
        lExecPlan.Free;
      end;

    finally
      rSet.Free;
    end;
  except
    d.roomerMainDataSet.SystemRollbackTransaction;
    raise;
  end;
end;

procedure TfrmInvoiceRentPerDay.ExecuteCurrencyChange(const aOldCurrency: string; const aNewCurrency: string);
begin
  UpdateRoomReservationsCurrency(aOldCurrency, aNewCurrency);
  LoadInvoice;
  UpdateCaptions;
end;

procedure TfrmInvoiceRentPerDay.SetCustEdits;
begin
  edtCustomer.ReadOnly := rgrInvoiceType.itemIndex IN [0, 1, 2, 3, 4, 5];

  if rgrInvoiceType.itemIndex = 5 then
  begin
    edtCustomer.Text := ctrlGetString('RackCustomer');
  end;

  edtName.ReadOnly := rgrInvoiceType.itemIndex IN [0, 1, 2, 3];
  edtAddress1.ReadOnly := rgrInvoiceType.itemIndex IN [0, 1, 2, 3];
  edtAddress2.ReadOnly := rgrInvoiceType.itemIndex IN [0, 1, 2, 3];
  edtAddress3.ReadOnly := rgrInvoiceType.itemIndex IN [0, 1, 2, 3];
  edtAddress4.ReadOnly := rgrInvoiceType.itemIndex IN [0, 1, 2, 3];
end;

procedure TfrmInvoiceRentPerDay.SetInvoiceIndex(const Value: integer);
begin
  IfInvoiceChangedThenOptionallySave;
  FInvoiceIndex := Value;
  UpdateInvoiceIndexTabs;
  RemoveAllCheckboxes;
  LoadInvoice;
end;

procedure TfrmInvoiceRentPerDay.pnlInvoiceIndex0Click(Sender: TObject);
begin
  InvoiceIndex := TsPanel(Sender).Tag;
end;

function TfrmInvoiceRentPerDay.GetSelectedRows: TList<String>;
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

function TfrmInvoiceRentPerDay.GetSelectedRowNrs: TList<integer>;
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

function TfrmInvoiceRentPerDay.IndexOfAutoGen(AutoGen: String): integer;
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

procedure TfrmInvoiceRentPerDay.pnlInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
var
  list: TList<integer>;
  i, Res: integer;
  invoiceLine: TInvoiceLine;
begin
  Res := -1;
  if (Source = agrLines) then
  begin
    list := GetSelectedRowNrs;
    try
      for i := list.Count - 1 downto 0 do
      begin
        invoiceLine := GetInvoiceLineByRow(list[i]);
        agrLines.row := list[i];
        if invoiceLine.IsGeneratedLine AND (invoiceLine.ItemKind = ikRoomRent) then
          MoveRoomToNewInvoiceIndex(TsPanel(Sender).Tag)
        else if invoiceLine.IsGeneratedLine AND (invoiceLine.ItemKind = ikStayTax) then
        begin
          if Res <> mrAll then
            Res := MessageDlg(GetTranslatedText('shTx_Invoice_WarningWhenMovingCityTax'), mtWarning,
              [mbYes, mbNo, mbAll, mbCancel], 0);
          case Res of
            mrYes, mrAll:
              begin
                actToggleLodgingTax.Execute;
                MoveItemToNewInvoiceIndex(list[i], TsPanel(Sender).Tag);
              end;
            mrCancel:
              exit;
          end;
        end
        else
          MoveItemToNewInvoiceIndex(list[i], TsPanel(Sender).Tag);
      end;
    finally
      list.Free;
    end;
  end
  else
  begin
    MoveDownpaymentToInvoiceIndex(TsPanel(Sender).Tag);
  end;
end;

procedure TfrmInvoiceRentPerDay.pnlInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState;
  var Accept: boolean);
begin
  Accept := (Source = agrLines) OR (Source IS TcxDragControlObject);
end;

procedure TfrmInvoiceRentPerDay.actMoveRoomToGroupInvoiceExecute(Sender: TObject);
begin
  MoveRoomToGroupInvoice;
end;

procedure TfrmInvoiceRentPerDay.actMoveRoomToRoomInvoiceExecute(Sender: TObject);
begin
  MoveRoomToRoomInvoice;
end;

function TfrmInvoiceRentPerDay.GetCustomerHeader(Res: integer): boolean;
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
  if FnewSplitNumber = 2 then
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

function TfrmInvoiceRentPerDay.GetInvoiceHeader(Res, RoomRes: integer): boolean;
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

  if FnewSplitNumber = 2 then
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

function TfrmInvoiceRentPerDay.GetHeaderChanged: boolean;
begin
  result := FHeaderChanged;
end;

function TfrmInvoiceRentPerDay.GetInvoiceHeader(Res, RoomRes: integer; arSet: TRoomerDataset): boolean;
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

  if FnewSplitNumber = 2 then
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

function TfrmInvoiceRentPerDay.GetReservationHeader(Res, RoomRes: integer): boolean;
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

  if FnewSplitNumber = 2 then
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

function TfrmInvoiceRentPerDay.GetRowForInvoiceLine(aInvoiceLine: TInvoiceLine): integer;
begin
  for result := 0 to agrLines.RowCount - 1 do
    if GetInvoiceLineByRow(result) = aInvoiceLine then
      Break;
end;

function TfrmInvoiceRentPerDay.GetMainGuestHeader(Res, RoomRes: integer): boolean;
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
  if FnewSplitNumber = 2 then
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

function TfrmInvoiceRentPerDay.GetMainGuestName(Res, RoomRes: integer): string;
var
  Name: string;
  rSet: TRoomerDataset;
  s: string;
  sql: string;
begin
  result := '';
  if FReservation = -1 then
    exit;
  if FnewSplitNumber = 2 then
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

procedure TfrmInvoiceRentPerDay.rgrInvoiceTypeClick(Sender: TObject);
begin
  btnGetCustomer.Enabled := rgrInvoiceType.itemIndex <> 1;
  btnClearAddresses.Enabled := rgrInvoiceType.itemIndex <> 1;

  case rgrInvoiceType.itemIndex of
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
  FHeaderChanged := True;
  edtRoomGuest.Caption := GetMainGuestName(FReservation, FRoomReservation);
  chkChanged;
  SetCustEdits;
end;

procedure TfrmInvoiceRentPerDay.S1Click(Sender: TObject);
begin
  btnSaveChanges.Click;
end;

procedure TfrmInvoiceRentPerDay.SaveAnd(doExit: boolean);
begin
  if zDoSave then
  begin
    SaveInvoice(zInvoiceNumber, stProvisionally);
    chkChanged;
    if doExit then
      close;
  end;
end;

procedure TfrmInvoiceRentPerDay.actSaveAndExitExecute(Sender: TObject);
begin
  SaveAnd(True);
end;

procedure TfrmInvoiceRentPerDay.actPrintInvoiceExecute(Sender: TObject);
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
    close;
end;

function TfrmInvoiceRentPerDay.PayAndPrintFinalInvoice: boolean;
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
      ViewInvoice2(lNewInvoiceNumber, True, false, True, chkShowPackage.checked, zEmailAddress);
      d.roomerMainDataSet.SystempackagesCreateHeaderIfNotExists(FRoomReservation, FRoomReservation);
      result := True;
    end
    else
      IVH_RestoreID;
  except
    IVH_RestoreID;
  end;
end;

procedure TfrmInvoiceRentPerDay.actPrintProformaExecute(Sender: TObject);
begin
  PrintProforma;
end;

procedure TfrmInvoiceRentPerDay.actEditDownPaymentClick(Sender: TObject);
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
    rec.InvoiceBalance := _StrToFloat(edtBalance.Text) + _StrToFloat(edtDownPayments.Text);

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.Amount := mPayments.FieldByName('Amount').AsFloat;
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
            mPayments.FieldByName('Amount').AsFloat := rSet.FieldByName('Amount').AsFloat;
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

procedure TfrmInvoiceRentPerDay.MoveDownpaymentToInvoiceIndex(toInvoiceIndex: integer);
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
  rec.Amount := mPayments.FieldByName('Amount').AsFloat;
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
      mPayments.delete;
      AddInvoiceActivityLog(g.qUser, rec.reservation, rec.RoomReservation, 1
        // field typeindex 0 = invoice payment 1 = downpayment
        , DELETE_PAYMENT, rec.PaymentType, rec.Amount, zInvoiceNumber, rec.Description);
    end;

    DisplayTotals;
  end
  else
  begin
    ShowMessage('It is not allowed to Delete confirmed payments');
  end;
end;

procedure TfrmInvoiceRentPerDay.actDeleteDownpaymentClick(Sender: TObject);
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

  g.initRecDownPayment(rec);

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.Amount := mPayments.FieldByName('Amount').AsFloat;
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
    if MessageDlg('Delete payment ?'#10 + rec.Description + ' / Amount ' + _floattostr(rec.Amount, vWidth, vDec),
      mtConfirmation, [mbYes, mbNo, mbCancel], 0) = mrYes then
    begin
      mPayments.delete;
      s := '';
      s := s + ' DELETE FROM payments '#10;
      s := s + ' WHERE  Id = (' + _db(Id) + ') ' + #10;

      if cmd_bySQL(s) then
      begin
        AddInvoiceActivityLog(g.qUser, rec.reservation, rec.RoomReservation, 1
          // field typeindex 0 = invoice payment 1 = downpayment
          , DELETE_PAYMENT, rec.PaymentType, rec.Amount, zInvoiceNumber, rec.Description);
      end;

      DisplayTotals;
    end;
  end
  else
  begin
    ShowMessage('It is not allowed to Delete confirmed payments');
  end;
end;

procedure TfrmInvoiceRentPerDay.acHideAllBreakfastsExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(False, [ikBreakfast]);
  UpdateGrid;
end;

procedure TfrmInvoiceRentPerDay.acHideAllCTaxExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(FAlse, [ikStayTax]);
  UpdateGrid;
end;

procedure TfrmInvoiceRentPerDay.acHideAllDiscountsExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(False, [ikRoomRentDiscount]);
  UpdateGrid;
end;

procedure TfrmInvoiceRentPerDay.acShowAllCTaxExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(True, [ikStayTax]);
  UpdateGrid;
end;

procedure TfrmInvoiceRentPerDay.acShowAllDiscountsExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(True, [ikRoomRentDiscount]);
  UpdateGrid;
end;

procedure TfrmInvoiceRentPerDay.acShowAlllBreakfastsExecute(Sender: TObject);
begin
  FInvoiceLinesList.SetAllVisibleOnInvoiceTo(True, [ikBreakfast]);
  UpdateGrid;
end;

procedure TfrmInvoiceRentPerDay.actAddDownPaymentExecute(Sender: TObject);
var
  rec: recDownPayment;
  theData: recPaymentHolder;
  NewId: integer;

begin
  g.initRecDownPayment(rec);

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.Amount := 0;

  if (rec.reservation = 0) and (rec.RoomReservation = 0) then
  begin
    ShowMessage('You cannot add downpayment to a cash invoice');
    exit;
  end;

  if edtBalance.Text <> '' then
    rec.InvoiceBalance := FInvoiceLinesList.TotalOnInvoiceNativeCurrency - getDownPayments;

  if g.OpenDownPayment(actInsert, rec) then
  begin
    // insert payment

    initPaymentHolderRec(theData);

    theData.reservation := FReservation;
    theData.RoomReservation := FRoomReservation;
    theData.Person := FnewSplitNumber;
    theData.TypeIndex := ORD(ptDownPayment);
    theData.InvoiceNumber := zInvoiceNumber;
    theData.customer := edtCustomer.Text;
    theData.PayDate := _db(Date, false);
    theData.Amount := rec.Amount;
    theData.Description := rec.Description;
    theData.CurrencyRate := zCurrencyRate; // ATH
    theData.Currency := zCurrentCurrency;
    theData.ConfirmDate := 2; // _db('1900-01-01 00:00:00');
    theData.Notes := rec.Notes;
    theData.PayType := rec.PaymentType;
    theData.InvoiceIndex := InvoiceIndex;

    NewId := 0;
    if INS_Payment(theData, NewId) then
    begin
      mPayments.insert;
      mPayments.FieldByName('PayType').asString := rec.PaymentType;
      mPayments.FieldByName('PayDate').asdateTime := Date;
      mPayments.FieldByName('Amount').AsFloat := rec.Amount;
      mPayments.FieldByName('Description').asString := rec.Description;
      if glb.Paytypesset.Locate('payType', rec.PaymentType, []) then
      begin
        mPayments.FieldByName('PayGroup').asString := glb.Paytypesset.FieldByName('payGroup').asString;
      end;
      mPayments.FieldByName('Memo').asString := rec.Notes;
      mPayments.FieldByName('confirmDate').asdateTime := theData.ConfirmDate;
      mPayments.FieldByName('ID').asinteger := NewId;
      mPayments.FieldByName('InvoiceIndex').asinteger := InvoiceIndex;

      mPayments.post;
      DisplayTotals;
    end;
  end;

end;

procedure TfrmInvoiceRentPerDay.actInfoExecute(Sender: TObject);
begin
  if g.openresMemo(FReservation) then
  begin
  end;
end;

procedure TfrmInvoiceRentPerDay.actAddLineExecute(Sender: TObject);
begin
  agrLines.row := agrLines.RowCount - 1;
  itemLookup;
end;

procedure TfrmInvoiceRentPerDay.actAddRoomExecute(Sender: TObject);
begin
  agrLines.row := agrLines.RowCount - 1;
  AddARoom;;
end;

procedure TfrmInvoiceRentPerDay.AddARoom;
var
  lIntDate: integer;
  lDate: TDate;
  lRoomText: string;
  iPersons: integer;
  iRooms: integer;
  iNights: integer;
  dRoomPrice: Double;
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

      for lIntDate := trunc(now) to trunc(now) + iNights - 1 do
      begin
        lDate := lIntDate * 1.0;
        lRoomText := GetTranslatedText('shRoom') + format(' on %s', [FormatDateTime('dd/mm', TDateTime(lDate))]);
        AddRoom('', dRoomPrice, '', TDate(lDate), TDate(lDate) + 1, 1, lRoomText, false, -1, 0, false, '', edtName.Text,
          iPersons, 0, false, -1, false);
      end;
    end;
    UpdateGrid;
  end;
end;

procedure TfrmInvoiceRentPerDay.actRemoveSelectedExecute(Sender: TObject);
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

procedure TfrmInvoiceRentPerDay.actMoveRoomToTempExecute(Sender: TObject);
var
  CurrentRow: integer;
  sRoomRentItem: string;
  sDiscountItem: string;
  sCurrentItem: string;
  list: TList<String>;
  i, l: integer;
begin
  // if MessageDlg('Set room to temp ', mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
  if MessageDlg(GetTranslatedText('shTx_Invoice_SetTemp'), mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
  begin
    exit;
  end;

  list := GetSelectedRows;
  try
    for l := list.Count - 1 downto 0 do
    begin
      i := IndexOfAutoGen(list[l]);
      if i >= 0 then
      begin
        CurrentRow := i;

        sRoomRentItem := _trimlower(g.qRoomRentItem);
        sDiscountItem := _trimlower(g.qDiscountItem);
        sCurrentItem := _trimlower(agrLines.Cells[col_Item, CurrentRow]);

        agrLines.row := 1;
        agrLines.Col := 0;
        CurrentRow := 0;

        repeat
          inc(CurrentRow);
          sCurrentItem := _trimlower(agrLines.Cells[col_Item, CurrentRow]);

          if (sCurrentItem = sRoomRentItem) or (sCurrentItem = sDiscountItem) then
          begin
            DeleteRow(agrLines, CurrentRow);
            AddEmptyLine;
            chkChanged;
            CurrentRow := 0;
            agrLines.row := 1;
            zbRoomRentinTemp := True;
          end;
        until (CurrentRow = agrLines.RowCount - 1);
      end;
    end;
  finally
    list.Free;
  end;
  calcAndAddAutoItems(FReservation);
end;

procedure TfrmInvoiceRentPerDay.ItemToTemp(confirm: boolean);
var
  PurchaseDate: TDateTime;
  InvoiceNumber: integer;
  itemNumber: integer;
  ItemId: string; // (10)

  Number: Double; // -96

  Description: string; // (70)
  Price: Double;
  VATType: string; // (10)
  Total: Double;
  TotalWOVat: Double;
  Vat: Double;
  CurrencyRate: Double;
  Currency: string; // (5)
  Persons: integer;
  Nights: integer;
  importRefrence: string;
  ImportSource: string;

  // ***

  s: string;
  CurrentRow: integer;
  ItemTypeInfo: TItemTypeInfo;

  isPackage: boolean;

  lInvRoom: TInvoiceRoomEntity;
  lInvLine: TInvoiceLine;

begin
  isPackage := false;

  CurrentRow := agrLines.row;
  if isSystemLine(CurrentRow) then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_SaleNotSelected'));
    exit;
  end;

  PurchaseDate := integer(agrLines.Objects[cPurchaseDateAsObjectColumn, CurrentRow]);
  InvoiceNumber := zInvoiceNumber;
  itemNumber := CurrentRow;

  ItemId := trim(agrLines.Cells[col_Item, CurrentRow]);

  if ItemId = '' then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_EmptyInvoice'));
    exit;
  end;

  Description := trim(agrLines.Cells[col_Description, CurrentRow]); // (70)
  importRefrence := trim(agrLines.Cells[col_Reference, CurrentRow]);
  ImportSource := trim(agrLines.Cells[col_Source, CurrentRow]);

  // if MessageDlg('Take [' + itemId + '] from invoice ', mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
  if confirm AND (MessageDlg(format(GetTranslatedText('shTx_Invoice_TakeItemFromInvoice'), [ItemId]), mtConfirmation,
    [mbYes, mbNo], 0) <> mrYes) then
  begin
    exit;
  end;

  s := trim(agrLines.Cells[col_ItemCount, CurrentRow]);
  try
    Number := _StrToFloat(s); // -96
  except
    Number := 0.00;
  end;

  s := trim(agrLines.Cells[col_ItemPrice, CurrentRow]);
  Price := _StrToFloat(s); // Was StrToFloatDef()

  s := trim(agrLines.Cells[col_TotalPrice, CurrentRow]);
  Total := _StrToFloat(s); // Was StrToFloatDef()

  ItemTypeInfo := d.Item_Get_ItemTypeInfo(ItemId);
  VATType := ItemTypeInfo.VATCode;

  lInvRoom := TInvoiceRoomEntity.Create(agrLines.Cells[col_Item, CurrentRow], 1, 0,
    _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), Total, 0, 0, false);
  try
    Vat := GetVATForItem(agrLines.Cells[col_Item, CurrentRow], Total,
      _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), lInvRoom, tempInvoiceItemList, ItemTypeInfo,
      edtCustomer.Text);
  finally
    lInvRoom.Free;
  end;
  TotalWOVat := Total - Vat;

  Currency := edtDisplayCurrency.Text;
  CurrencyRate := GetRate(Currency);
  edtRate.Text := floattostr(CurrencyRate);

  Persons := 0;
  Nights := 0;
  lInvLine := GetInvoiceLineByRow(CurrentRow);
  if assigned(lInvLine.RoomEntity) then
  begin
    Persons := lInvLine.RoomEntity.NumGuests;
    Nights := lInvLine.RoomEntity.NumberOfNights;
  end;

  d.kbmInvoicelines.insert;
  d.kbmInvoicelines.FieldByName('Reservation').asinteger := FReservation;
  d.kbmInvoicelines.FieldByName('RoomReservation').asinteger := FRoomReservation;
  d.kbmInvoicelines.FieldByName('SplitNumber').asinteger := 0;
  d.kbmInvoicelines.FieldByName('ItemNumber').asinteger := itemNumber;
  d.kbmInvoicelines.FieldByName('PurchaseDate').asdateTime := PurchaseDate;
  d.kbmInvoicelines.FieldByName('InvoiceNumber').asinteger := InvoiceNumber;
  d.kbmInvoicelines.FieldByName('ItemId').asString := ItemId;
  d.kbmInvoicelines.FieldByName('Number').AsFloat := Number;
  d.kbmInvoicelines.FieldByName('Description').asString := Description;
  d.kbmInvoicelines.FieldByName('Price').AsFloat := Price;
  d.kbmInvoicelines.FieldByName('VATType').asString := VATType;
  d.kbmInvoicelines.FieldByName('Total').AsFloat := Total;
  d.kbmInvoicelines.FieldByName('TotalWOVat').AsFloat := TotalWOVat;
  d.kbmInvoicelines.FieldByName('VAT').AsFloat := Vat;
  d.kbmInvoicelines.FieldByName('CurrencyRate').AsFloat := CurrencyRate;
  d.kbmInvoicelines.FieldByName('Currency').asString := Currency;
  d.kbmInvoicelines.FieldByName('Persons').asinteger := Persons;
  d.kbmInvoicelines.FieldByName('Nights').asinteger := Nights;
  d.kbmInvoicelines.FieldByName('BreakfastPrice').AsFloat := 0.00;
  d.kbmInvoicelines.FieldByName('ImportSource').asString := ImportSource;
  d.kbmInvoicelines.FieldByName('importRefrence').asString := importRefrence;
  d.kbmInvoicelines.FieldByName('isPackage').asBoolean := isPackage;
  d.kbmInvoicelines.post;

  labTmpStatus.Caption := inttostr(d.kbmInvoicelines.RecordCount);

  if isSystemLine(agrLines.row) then
    // raise Exception.create('System item can not delete ');
    raise Exception.Create(GetTranslatedText('shTx_Invoice_CanNotDelete'));

  DeleteRow(agrLines, agrLines.row);
  AddEmptyLine;
  calcAndAddAutoItems(FReservation);
  chkChanged;
end;

procedure TfrmInvoiceRentPerDay.actMoveItemToTempExecute(Sender: TObject);
var
  list: TList<String>;
  i, l: integer;
begin
  list := GetSelectedRows;
  try
    for l := list.Count - 1 downto 0 do
    begin
      i := IndexOfAutoGen(list[l]);
      if i >= 0 then
      begin
        agrLines.row := i;
        ItemToTemp(l = list.Count - 1);
      end;
    end;
  finally
    list.Free;
  end;
end;

function TfrmInvoiceRentPerDay.RoomByRoomReservation(RoomReservation: integer): String;
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

procedure TfrmInvoiceRentPerDay.MoveItemToRoomInvoice(toRoomReservation, toReservation: integer; InvoiceIndex: integer);
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

  reservation := toReservation;
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
    _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), _StrToFloat(agrLines.Cells[col_ItemPrice, CurrentRow]), 0,
    0, false);
  try
    TotalVAT := GetVATForItem(agrLines.Cells[col_Item, CurrentRow], Total,
      _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), lInvRoom, tempInvoiceItemList, ItemTypeInfo,
      edtCustomer.Text); // BHG
  finally
    lInvRoom.Free;
  end;
  TotalWOVat := Total - TotalVAT;

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

  NextInvoiceLine := NumberOfInvoiceLines(reservation, toRoomReservation, 0) + 1;

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
    s := s + 'where Reservation = ' + _db(reservation);
    if RoomReservation > 0 then
      s := s + '  and RoomReservation = ' + _db(RoomReservation) + #10
    else
      s := s + '  and RoomReservation = 0 ' + #10;
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
    s := format(select_Invoice_actItemToRoomInvoiceExecute, [reservation, RoomReservation]);
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

  LoadInvoice;
end;

procedure TfrmInvoiceRentPerDay.MoveItemToNewInvoiceIndex(rowIndex, toInvoiceIndex: integer);
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

procedure TfrmInvoiceRentPerDay.actMoveItemToGroupInvoiceExecute(Sender: TObject);
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
          _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), CurrentRow, 0, 0, false);
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
  LoadInvoice;
end;

function TfrmInvoiceRentPerDay.CreateProformaID: integer;
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

procedure TfrmInvoiceRentPerDay.RemoveCurrentProformeInvoice(ProformaInvoiceNumber: integer);
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

procedure TfrmInvoiceRentPerDay.PrintProforma;
var
  showPackage: boolean;
begin
  showPackage := chkShowPackage.checked;

  PROFORMA_INVOICE_NUMBER := CreateProformaID;
  try
    SaveInvoice(PROFORMA_INVOICE_NUMBER, stProforma);
    ViewInvoice2(PROFORMA_INVOICE_NUMBER, True, false, false, showPackage, zEmailAddress);
  finally
    RemoveCurrentProformeInvoice(PROFORMA_INVOICE_NUMBER);
  end;
end;

procedure TfrmInvoiceRentPerDay.CopyPaymentsForProforma(aInvoiceNumber: integer; aExecPlan: TRoomerExecutionPlan);
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

  s := format(s, [aInvoiceNumber, FReservation, FRoomReservation, FInvoiceIndex]);
  aExecPlan.AddQuery(s);
end;

function TfrmInvoiceRentPerDay.IsCashInvoice: boolean;
begin
  result := ((FReservation + FRoomReservation) = 0);
end;

function TfrmInvoiceRentPerDay.chkChanged: boolean;
begin
  result := false;
  if IsCashInvoice then
    exit;

  result := FInvoiceLinesList.IsChanged or HeaderChanged or (DeletedLines.Count > 0);
  btnSaveChanges.Visible := result;
end;

procedure TfrmInvoiceRentPerDay.LoadRoomListForCurrentReservation(reservation: integer);
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

procedure TfrmInvoiceRentPerDay.LoadRoomListForOtherReservations(reservation: integer);
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

procedure TfrmInvoiceRentPerDay.LoadRoomListForAllReservations;
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

procedure TfrmInvoiceRentPerDay.FillRoomsInMenu(mnuItem: TMenuItem);
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
        subItem.OnClick := N91Click;
        Item.Add(subItem);
        subItem.Enabled := subItem.Tag >= 0;
      end;
    end;
  end;
end;

procedure TfrmInvoiceRentPerDay.FillExternalRoomsInMenu(mnuItem: TMenuItem);
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
      Item.Caption := TInvoiceRoomEntity(SelectableExternalRooms[i]).Room;
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

procedure TfrmInvoiceRentPerDay.FillAllRoomsInMenu(mnuItem: TMenuItem);
var
  i: integer;
  Item: TMenuItem;
begin
  LoadRoomListForAllReservations;
  mnuItem.Clear;
  for i := 0 to SelectableExternalRooms.Count - 1 do
  begin
    Item := TMenuItem.Create(nil);
    Item.Caption := TInvoiceRoomEntity(SelectableExternalRooms[i]).Room;
    Item.Tag := i;
    mnuItem.Add(Item);
    Item.OnClick := TransferRoomToAnyRoomsClick;
  end;
end;

procedure TfrmInvoiceRentPerDay.mnuMoveItemPopup(Sender: TObject);
begin
  FillRoomsInMenu(mnuItemToRoomInvoice);
  FillExternalRoomsInMenu(mnuMoveItemToAnyOtherRoomAndInvoiceIndex);
end;

procedure TfrmInvoiceRentPerDay.mnuMoveRoomPopup(Sender: TObject);
begin
  FillAllRoomsInMenu(mnuTransferRoomRentToDifferentRoom);
end;

procedure TfrmInvoiceRentPerDay.timCloseInvoiceTimer(Sender: TObject);
begin
  timCloseInvoice.Enabled := false;
  close;
end;

procedure TfrmInvoiceRentPerDay.UpdateInvoiceIndexTabs;
var
  i: integer;
  pnl: TsPanel;
  shp1, shp2: TShape;
begin
  for i := 0 to 9 do
  begin
    pnl := GetInvoiceIndexPanel(i);
    shp1 := GetInvoiceIndexItems(i);
    shp2 := GetInvoiceIndexItemsRR(i);
    if pnl.Tag = InvoiceIndex then
      pnl.Color := $00FFCFA8
    else
      pnl.Color := clWhite;

    pnl.Font.Color := clBlack;

    if pnl.HelpContext = 0 then
      shp1.Brush.Color := clWhite
    else
      shp1.Brush.Color := clRed; // $00C1FFFF;

    if shp2.HelpContext = 0 then
      shp2.Brush.Color := clWhite
    else
      shp2.Brush.Color := clBlue; // $00FFCFA8;

    shp2.Visible := shp2.Brush.Color <> clWhite;
    shp1.Visible := shp1.Brush.Color <> clWhite;
  end;
end;

procedure TfrmInvoiceRentPerDay.ClearGrid;
begin
  DeletedLines.Clear;
  ClearRoomInfoObjects;
  ClearInvoiceLines;
  NullifyGrid;
end;

{ TInvoiceLineList }

function TInvoiceLineList.GetCityTaxUnitCount: Double;
var
  lInvLine: TInvoiceLine;
begin
  result := 0;
  for lInvLine in self do
    if lInvLine.ItemKind = ikStayTax then
      result := result + lInvLine.Number;
end;

function TInvoiceLineList.GetIsChanged: boolean;
var
  lInvLine: TInvoiceLine;
begin
  result := false;
  for lInvLine in self do
    result := result or lInvLine.Changed;
end;

function TInvoiceLineList.GetTotalCityTaxRevenues: Double;
var
  lInvLine: TInvoiceLine;
begin
  result := 0.0;
  for lInvLine in self do
    if (lInvLine.ItemKind = ikStayTax) then
      result := result + lInvLine.TotalNativeCurrency;
end;

function TInvoiceLineList.GetTotalOnInvoiceNativeCurrency: Double;
var
  lInvLine: TInvoiceLine;
begin
  result := 0.0;
  for lInvLine in self do
    result := result + (lInvLine.AmountOnInvoice * GetRate(lInvLine.Currency));
end;

function TInvoiceLineList.GetTotalVatOnInvoice: Double;
var
  lInvLine: TInvoiceLine;
begin
  result := 0.0;
  for lInvLine in self do
    result := result + (lInvLine.VATOnInvoice * GetRate(lInvLine.Currency));
end;

procedure TInvoiceLineList.SetAllVisibleOnInvoiceTo(aVisible: boolean; aItemKindSet: TItemKindSet);
var
  lInvLine: TInvoiceLine;
begin
  for lInvLine in self do
    if linvLine.CanBeHiddenFromInvoice and (lInvLine.ItemKind in aItemKindSet) then
    begin
      linvLine.VisibleOnInvoice := aVisible;
      lInvLine.Changed := true
    end;
end;

procedure TInvoiceLineList.SortOnInvoiceLineIndex;
begin
  Sort(TComparer<TInvoiceLine>.Construct(
    function(const l, R: TInvoiceLine): integer
    begin
      result := l.InvoiceLineIndex - R.InvoiceLineIndex;
    end));
end;

end.
