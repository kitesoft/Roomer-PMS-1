unit uInvoice;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Grids, ExtCtrls, ComCtrls, StdCtrls, ImgList, Menus, Buttons, Data.DB,
  Data.Win.ADODB

    , uDateUtils, ActnList, System.Actions, Generics.Collections, variants,
  cmpRoomerDataSet, cxGraphics, cxControls, cxLookAndFeels, cxLookAndFeelPainters, cxStyles, dxSkinsCore, dxSkinCaramel,
  dxSkinCoffee, dxSkinDarkSide, dxSkinTheAsphaltWorld, dxSkinsDefaultPainters, dxSkinscxPCPainter, cxCustomData,
  cxFilter, cxData, cxDataStorage, cxEdit, cxNavigator, cxDBData, cxMemo, AdvUtil, dxmdaset, frxClass, frxDBSet,
  cxPropertiesStore, sStatusBar, AdvObj, BaseGrid, AdvGrid, cxGridLevel, cxGridCustomTableView, cxGridTableView,
  cxGridDBTableView, cxClasses, cxGridCustomView, cxGrid, sCheckBox, sButton, sGroupBox, sEdit, sLabel, sPanel,

    _glob, hData, ug, uUtils, kbmMemTable

    , uTaxCalc
    , frxExportMail, frxExportImage, frxExportRTF, frxExportHTML

  , uInvoiceEntities, sScrollBox
    ;

type
  TCreditType = (ctManual, ctReference, ctErr);

{$M+}

  TRoomInfo = class(TInvoiceRoomEntity)
  end deprecated;

  TRoomInfoList = TObjectlist<TRoomInfo>;

{$M+}

  /// <summary>
  ///   Object attached to a gridline of the invoiceform, containing all Invoice related info shown in that gridline
  /// </summary>
  TInvoiceLine = class(TObject)
  private
    FInvoiceLineIndex: integer;

    FItem: string;
    FText: string;

    FNumber: Double; // -96
    FPrice: Double;
    FTotal: Double;
    FDate: TDate;
    FAuto: boolean;
    FRefrence: string;
    FSource: string;
    FIspackage: boolean;
    FNoGuests: integer;
    FConfirmDate: TDateTime;
    FConfirmAmount: Double;
    FitemIndex: integer;
    FrrAlias: integer;
    FAutoGen: string;
    FId: integer;

  public
    constructor create(aIndex, _id: integer);
    destructor Destroy; override;
  published
    property invoiceLine: integer read FInvoiceLineIndex write FInvoiceLineIndex;
    property Id: integer read FId write FId;
    property Item: string read FItem write FItem;
    property Text: string read FText write FText;
    property Number: Double read FNumber write FNumber; // -96
    property Price: Double read FPrice write FPrice;
    property Total: Double read FTotal write FTotal;
    property Refrence: string read FRefrence write FRefrence;
    property Source: string read FSource write FSource;
    property isPackage: boolean read FIspackage write FIspackage;
    property noGuests: integer read FNoGuests write FNoGuests;
    property confrimDate: TDateTime read FConfirmDate write FConfirmDate;
    property confrimAmount: Double read FConfirmAmount write FConfirmAmount;
    property itemIndex: integer read FitemIndex write FitemIndex;
    property rrAlias: integer read FrrAlias write FrrAlias;
    property AutoGen: string read FAutoGen write FAutoGen;

  end;

  /// <summary>
  ///   Used to indicate which automatically added items should be (re)generated
  /// </summary>
  TInvoiceAutoItem = (aiStayTax, aiIncludedBreakfast);
  TInvoiceAutoItemSet = set of TInvoiceAutoItem;

  // ------------------------------------------------------------------------------
  //
  // TfrmInvoice
  //
  // ------------------------------------------------------------------------------

  TfrmInvoice = class(TForm)
    FriendlyStatusBar1: TsStatusBar;
    MainMenu1: TMainMenu;
    File1: TMenuItem;
    ExitandSave1: TMenuItem;
    N1: TMenuItem;
    Exit1: TMenuItem;
    Items1: TMenuItem;
    Add1: TMenuItem;
    Delete1: TMenuItem;
    PANmAIN: TsPanel;
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
    timCloseInvoice: TTimer;
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
    lblChangedInvoiceActive: TsLabel;
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
    agrLines: TAdvStringGrid;
    btnExit: TsButton;
    btnInvoice: TsButton;
    btnProforma: TsButton;
    labTmpStatus: TsLabel;
    sPanel2: TsPanel;
    clabTotalwoVAT: TsLabel;
    clavVAT: TsLabel;
    clabInvoiceTotal: TsLabel;
    edtTotal: TsEdit;
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
    T1: TMenuItem;
    mnuMoveItemToSpecifiedRoomAndInvoiceIndex: TMenuItem;
    mnuMoveRoomRentFromRoomInvoiceToGroup: TMenuItem;
    mnuMoveRoomRentFromGroupToNormalRoomInvoice: TMenuItem;
    btnGetCustomer: TsButton;
    sPanel5: TsPanel;
    sPanel4: TsScrollBox;
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
    procedure FormCreate(Sender: TObject);
    procedure agrLinesMouseDown(Sender: TObject; Button: TMouseButton;
      Shift: TShiftState; X, Y: integer);
    procedure edtTotalChange(Sender: TObject);
    procedure edtCustomerDblClick(Sender: TObject);
    procedure agrLinesGetEditText(Sender: TObject; ACol, ARow: integer;
      var Value: string);
    procedure edtCurrencyDblClick(Sender: TObject);
    procedure agrLinesDrawCell(Sender: TObject; ACol, ARow: integer;
      Rect: TRect; State: TGridDrawState);
    procedure rgrInvoiceTypeClick(Sender: TObject);
    procedure actSaveAndExitExecute(Sender: TObject);
    procedure actPrintInvoiceExecute(Sender: TObject);
    procedure actPrintProformaExecute(Sender: TObject);
    procedure actDownPaymentExecute(Sender: TObject);
    procedure actInfoExecute(Sender: TObject);
    procedure actAddLineExecute(Sender: TObject);
    procedure actDelLineExecute(Sender: TObject);
    procedure actRRtoTempExecute(Sender: TObject);
    procedure actItemToTempExecute(Sender: TObject);
    procedure actItemToGroupInvoiceExecute(Sender: TObject);
    procedure timCloseInvoiceTimer(Sender: TObject);
    procedure btnRemoveLodgingTax2Click(Sender: TObject);
    procedure edtRateDblClick(Sender: TObject);
    procedure btnClearAddressesClick(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure agrLinesGetCellColor(Sender: TObject; ARow, ACol: integer;
      AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
    procedure sButton2Click(Sender: TObject);
    procedure edtCustomerChange(Sender: TObject);
    procedure btnEditDownPaymentClick(Sender: TObject);
    procedure btnDeleteDownpaymentClick(Sender: TObject);
    procedure agrLinesGetAlignment(Sender: TObject; ARow, ACol: integer;
      var HAlign: TAlignment; var VAlign: TVAlignment);
    procedure agrLinesColumnSize(Sender: TObject; ACol: integer;
      var Allow: boolean);
    procedure btnExitClick(Sender: TObject);
    procedure btnReservationNotesClick(Sender: TObject);
    procedure agrLinesCanEditCell(Sender: TObject; ARow, ACol: integer;
      var CanEdit: boolean);
    procedure FormDestroy(Sender: TObject);
    procedure agrLinesCellValidate(Sender: TObject; ACol, ARow: integer;
      var Value: string; var Valid: boolean);
    procedure agrLinesDblClickCell(Sender: TObject; ARow, ACol: integer);
    procedure T1Click(Sender: TObject);
    procedure mnuMoveRoomRentFromRoomInvoiceToGroupClick(Sender: TObject);
    procedure mnuMoveRoomRentFromGroupToNormalRoomInvoiceClick(Sender: TObject);
    procedure mnuMoveItemPopup(Sender: TObject);
    procedure mnuMoveRoomPopup(Sender: TObject);
    procedure agrLinesRowChanging(Sender: TObject; OldRow, NewRow: integer;
      var Allow: boolean);
    procedure pnlInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer;
      State: TDragState; var Accept: boolean);
    procedure pnlInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
    procedure pnlInvoiceIndex0Click(Sender: TObject);
    procedure N91Click(Sender: TObject);
    procedure shpInvoiceIndex0MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure shpInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
    procedure shpInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState; var Accept: boolean);
    procedure tvPaymentsMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
    procedure tvPaymentsCellDblClick(Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
      AButton: TMouseButton; AShift: TShiftState;
      var AHandled: boolean);
    procedure btnSaveChangesClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure agrLinesCheckBoxClick(Sender: TObject; ACol, ARow: integer; State: boolean);
    procedure agrLinesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure S1Click(Sender: TObject);
    procedure Exit1Click(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure pnlPaymentButtonsResize(Sender: TObject);
    procedure sPanel4DragOver(Sender, Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean);
  private
    { Private declarations }

    DeletedLines: TList<integer>;
    linesNumDays,
      linesNumGuests: integer;
    NumberGuestNights: integer;

    TaxTypes: TStringList;

    // Global to see if some changes

    zFirsttime: boolean;
    zApply: boolean;
    zInitString: string;
    zChkCount: integer;

    zEmailAddress: String;

    zDoSave: boolean;

    zCountry: string;

    FRoomInfoList: TRoomInfoList;
    SelectableRooms: TRoomInfoList;
    SelectableExternalRooms: TRoomInfoList;
    zInvoiceNumber: integer;
    zInvoiceDate: TDate;
    zConfirmDate: TDate;
    zPayDate: TDate;

    zCellValue: string;

    zbRoomRentinTemp: boolean;
    FInvoiceLinesList: TList<TInvoiceLine>;

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

    useStayTaxAlreadyFetched: boolean;
    useStayTaxOutcome: boolean;

    tempInvoiceItemList: TInvoiceItemEntityList;

    selectedRoomReservation: integer;

    zLocation: string;
    FInvoiceIndex: integer;

    FTotalRoomDiscount: Double;
    FReservation: integer;
    FRoomReservation: integer;

    procedure LoadInvoice;
    procedure loadInvoiceToMemtable(var m: TKbmMemTable);

    procedure setControls;

    /// <summary>
    ///   Based on the current items in the grid, calculate all automatic items (StayTax and included Breakfast) and
    ///  add object to Lines[] and rows to the grid
    /// </summary>
    procedure calcAndAddAutoItems(reservation: integer; aAutoItems: TInvoiceAutoItemSet = [aiStayTax, aiIncludedBreakFast]);
    procedure CalcAndAddStayTax(aReservation: integer; aRoominvoiceLinesList: TInvoiceRoomEntityList );
    procedure CalcAndAddIncludedBreakFast(aReservation: integer; aRoominvoiceLinesList: TInvoiceRoomEntityList);

    procedure ClearRoomInfoObjects;
    procedure SetCurrentVisible;
    function GetInvoiceLine(idx: integer): TInvoiceLine;
    function GetInvoiceLineCount: integer;

    /// <summary>
    /// Create a new TInvoiceLine object and add this to zListLines collection
    /// </summary>
    function AddLine(lineId: integer; sItem, sText: string; iNumber: Double;
      FPrice, FTotal: Double; PurchaseDate: TDate; bAuto: boolean;
      Refrence, Source: string; isPackage: boolean; noGuests: integer;
      confirmDate: TDateTime; confirmAmount: Double; rrAlias: integer;
      AutoGen: string; itemIndex: integer = 0): integer;

    /// <summary>
    /// Create a RoomInfo object with supplied parameters and attach to a new row in the grid<br/>
    /// A new TInvoiceLine object is also created for the roomrent and a new TInvoiceLine object is created
    /// for the supplied discount (if any). The Invoiceline objects are not attached to the grid.
    /// </summary>
    Function AddRoom(Room: String; fRoomPrice: Double; FromDate: TDate;
      ToDate: TDate; dayCount: integer; sText: string; bGetGuestName: boolean;
      RoomReservation: integer; DiscountAmount: Double;
      DiscountIsPercentage: boolean; DiscountText: string; GuestName: String;
      NumGuests: integer; NumChildren: integer; isPackage: boolean; rrAlias: integer; aBeakfastIncluded: boolean): integer;

    Procedure AddRoomTaxToLinesAndGrid(totalTax: Double; TaxUnits: Double;
      taxItem: String = ''; iAddAt: integer = 0);
    procedure RemoveStayTax;

    procedure ClearInvoiceLines;
    function getDownPayments: Double;

    procedure DisplayMem(zrSet: TRoomerDataset);
    procedure DisplayGuestName(zrSet: TRoomerDataset);

    /// <summary>
    /// Display the info of TInvoiceLine object attached to row <param>iRow</param> in the girdrow<br/>
    /// If gridrow <param>iRow</param> does not have a TInvoiceline object attached, the object with index <param>idx</param> will
    /// be used and attached to the gridrow.<br/>
    /// The rownumber is returned
    /// </summary>
    function DisplayLine(iRow, idx: integer): integer;

    procedure DisplayTotals(editCol: integer = -1; editRow: integer = -1; Value: Double = 0.00);
    /// <summary>
    /// Move Invoicelines for property RoomReservation from tmpinvoicelines table to invoicelines table
    /// </summary>
    procedure RestoreTMPInvoicelines;

    procedure SaveHeader(aExecutionPlan: TRoomerExecutionPlan; currencyChange : Boolean = False);

    function SaveInvoice(iInvoiceNumber: integer; currencyChange : Boolean = False): boolean;

    procedure CheckCurrencyChange(oldCurrency: string);
    procedure CheckRateChange;

    procedure CheckRoomRentItem(iRow: integer);

    procedure MarkOriginalInvoiceAsCredited(iInvoice: integer);

    function isSystemLine(row: integer): boolean;
    // Function  isRoomRentLine(row : integer) : boolean;
    function PayInvoiceAndPrint: boolean;
    function GatherPayments(PayLines: TStringList; var days: integer): Double;
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
    function SaveProforma(iInvoiceNumber: integer): boolean;
    procedure SaveProformaHeader(aExecPlan: TRoomerExecutionPlan);
    procedure SaveProformapayments(aExecPlan: TRoomerExecutionPlan);
    procedure SaveAnd(doExit: boolean; currencyChange : Boolean = False);
    procedure CreateCashInvoice(customer: string);

    function createAllStr: string;
    function chkChanged: boolean;
    procedure ItemToTemp(confirm: boolean);
    procedure NullifyGrid;

    Procedure InitInvoiceGrid;
    function GenerateInvoiceNumber: integer;
    procedure AddDeleteFromInvoiceToExecutionPlan(aExecutionPlan
      : TRoomerExecutionPlan);

    function LocateDate(recordSet: TRoomerDataset; field: String;
      Value: TDate): boolean;
    procedure GetTaxTypes(TaxResultInvoiceLines: TInvoiceTaxEntityList);
    function FindLastRoomRentLine: integer;
    procedure UpdateItemInvoiceLinesForTaxCalculations;
    function CheckIfWithdrawlAllowed_X(Editing: boolean; Value: String)
      : boolean;
    procedure FormatCurrentLine(ARow: integer);
    function CreateProformaID: integer;
    procedure MoveRoomToGroupInvoice;
    procedure MoveItemToRoomInvoice(toRoomReservation, toReservation: integer;
      InvoiceIndex: integer);
    procedure MoveRoomToRoomInvoice;
    procedure FillRoomsInMenu(mnuItem: TMenuItem);
    function RoomByRoomReservation(RoomReservation: integer): String;
    procedure LoadRoomListForCurrentReservation(reservation: integer);
    procedure DeleteRow(aGrid: TAdvStringGrid; iRow: integer);
    procedure ForceRowChange;
    procedure SetInvoiceIndex(const Value: integer);
    function IfInvoiceChangedThenOptionallySave(Ask: boolean = True): boolean;
    procedure MoveItemToNewInvoiceIndex(rowIndex, toInvoiceIndex: integer);
    procedure MoveRoomToNewInvoiceIndex(rowIndex, toInvoiceIndex: integer);
    procedure CorrectInvoiceIndexRectangles;
    function GetInvoiceIndexPanel(Index: integer): TsPanel;
    procedure SetInvoiceIndexPanelsToZero;
    function GetInvoiceIndexItems(Index: integer): TShape;
    function GetInvoiceIndexItemsRR(Index: integer): TShape;
    procedure MoveDownpaymentToInvoiceIndex(toInvoiceIndex: integer);
    function IsCashInvoice: boolean;
    function GetCalculatedNumberOfItems(ItemId: String; dDefault: Double): Double;
    procedure CheckCheckboxes;
    procedure CheckOrUncheckAll(check: boolean);
    function GetAnyRowChecked: boolean;
    function GetSelectedRows: TList<String>;
    function IndexOfAutoGen(AutoGen: String): integer;
    procedure RemoveAllCheckboxes;
    function IsRoomSelected: boolean;
    procedure RemoveCurrentProformeInvoice(ProformaInvoiceNumber: integer);
    procedure DeleteLinesInList(ExecutionPlan: TRoomerExecutionPlan);
    /// <summary>
    /// Return the TInvoiceLine object attached to gridrow <param>aRow</param>
    /// </summary>
    function CellInvoiceLine(ARow: integer): TInvoiceLine;
    function CellInvoiceLineId(line: integer): integer;
    function IsLineChanged(line, iMultiplier: integer): boolean;
    procedure LoadRoomListForOtherReservations(reservation: integer);
    procedure ExternalRoomsClick(Sender: TObject);
    procedure FillExternalRoomsInMenu(mnuItem: TMenuItem);
    procedure FillAllRoomsInMenu(mnuItem: TMenuItem);
    procedure LoadRoomListForAllReservations;
    procedure TransferRoomToAnyRoomsClick(Sender: TObject);
    procedure TransferRoomToAnotherRoomReservationInvoice(FromRoomReservation, RoomReservation, RealRoomReservation,
      reservation: integer);
    procedure AddIncludedBreakfastToLinesAndGrid(aIncludedBreakfastCount: integer; iAddAt: integer = 0);
    procedure RemoveAutoBreakfastItems;
    function ItemKindOnRow(aRow: Integer): TItemKind;

    property InvoiceIndex: integer read FInvoiceIndex write SetInvoiceIndex;
    property AnyRowChecked: boolean read GetAnyRowChecked;
  public
    { Public declarations }
    FnewSplitNumber: integer; // 0 = herbergjareikningur
    FIsCredit: boolean;
    zFromKredit: boolean;

    OriginalInvoiceStatus: Double;
    constructor Create(aOwner: TComponent); override;
    property Lines[idx: integer]: TInvoiceLine read GetInvoiceLine;
    procedure UpdateCaptions;
    procedure WndProc(var message: TMessage); override;
    property reservation: integer read FReservation write FReservation;
    property RoomReservation: integer read FRoomReservation write FRoomReservation;
  published
    property lineCount: integer read GetInvoiceLineCount;
  end;

var
  frmInvoice: TfrmInvoice;

procedure EditInvoice(reservation, RoomReservation, SplitNumber, InvoiceIndex: integer; bCredit: boolean; FromKredit: boolean = false);

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
  UITypes
  , uFloatUtils
  , Math
    , uVatCalculator, uSQLUtils, ufrmRoomPrices, uInvoiceDefinitions, uInvoiceRentPerDay, uPMSSettings;

{$R *.DFM}


var
  memUpdateDone: boolean;
  zOriginalInvoice: integer;

const
  cInvoiceLineAttachColumn = 0;
  cRoomInfoAttachColumn = 3;

  col_Select = 0;
  col_Item = col_Select + 1; // 1
  col_Description = col_Item + 1; // 2
  col_ItemCount = col_Description + 1; // 3
  col_ItemPrice = col_ItemCount + 1; // 4
  col_TotalPrice = col_ItemPrice + 1; // 5
  col_System = col_TotalPrice + 1; // 6 old 5
  col_date = col_System + 1; // 7
  col_Refrence = col_date + 1; // // 8 old 7
  col_Source = col_Refrence + 1; // 9
  col_isPackage = col_Source + 1; // //10 old 9
  col_NoGuests = col_isPackage + 1; // 11
  col_confirmdate = col_NoGuests + 1; // 12
  col_confirmAmount = col_confirmdate + 1; // 13
  col_Vat = col_confirmAmount + 1; // 14
  col_rrAlias = col_Vat + 1; // 15
  col_autogen = col_rrAlias + 1; // 16 old 15

  // WM_StartUpLists = WM_User + 381;
  WM_FORMAT_LINE = WM_User + 290;

  REMOVE_CURRENT_PROFORMA_INVOICE: Array [0 .. 2] OF String = (
    'DELETE FROM invoicelines WHERE invoiceNumber=%d',
    'DELETE FROM invoiceheads WHERE invoiceNumber=%d',
    'DELETE FROM payments WHERE invoiceNumber=%d'
    );

  REMOVE_REDUNDANT_INVOICES: Array [0 .. 2] OF String = (
    // Credit invoices                          // Proforma invoices
    'DELETE FROM invoicelines WHERE (SplitNumber = 1 AND InvoiceNumber = -1) OR (InvoiceNumber > 1000000000)',
    'DELETE FROM invoiceheads WHERE (SplitNumber = 1 AND InvoiceNumber = -1) OR (InvoiceNumber > 1000000000)',
    'DELETE FROM payments WHERE InvoiceNumber > 1000000000'
    );

procedure EditInvoice(reservation, RoomReservation, SplitNumber, InvoiceIndex: integer; bCredit: boolean; FromKredit: boolean = false);
var
  _frmInvoice: TfrmInvoice;
begin

  if (glb.PMSSettings.InvoiceSettings.RoomRentPerDayOninvoice = rpdAlways)  or
    (glb.PMSSettings.InvoiceSettings.RoomRentPerDayOninvoice = rpdAsk) and (MessageDlg(GetTranslatedText('shEditInvoice_RoomRentPerDay'), mtConfirmation, mbYesNo, 0) = mrYes) then
    EditInvoiceRentPerDay(Reservation, ROomReservation, SplitNumber, InvoiceIndex, bCredit, FromKredit)
  else
  begin
    _frmInvoice := TfrmInvoice.create(nil);
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
    end;
  end;

  Grid.RowCount := 2;
  Grid.FixedRows := 1;
end;

{ TRoomInfo }

procedure TfrmInvoice.ForceRowChange;
var
  Allow: boolean;
begin
  Allow := True;
  agrLinesRowChanging(agrLines, agrLines.row, agrLines.row, Allow);
end;

procedure TfrmInvoice.RemoveAllCheckboxes;
var
  i: integer;
begin
  for i := 0 to 400 do // agrLines.RowCount - 1 do
    try
      if agrLines.HasCheckBox(col_Select, i) then
        agrLines.RemoveCheckBox(col_Select, i);
    Except
    end;
end;

procedure TfrmInvoice.DeleteRow(aGrid: TAdvStringGrid; iRow: integer);
begin
  RemoveAllCheckboxes;
  agrLines.RemoveRows(iRow, 1);
  ForceRowChange;
end;

// HJ
function TfrmInvoice.isSystemLine(row: integer): boolean;
begin
  result := false;
  try
    result := agrLines.Objects[col_Item, row] = TObject(-2);
  except
  end;
end;

procedure TfrmInvoice.AddDeleteFromInvoiceToExecutionPlan(aExecutionPlan: TRoomerExecutionPlan);
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

function TfrmInvoice.IfInvoiceChangedThenOptionallySave(Ask: boolean = True): boolean;
var
  s: string;
  Res: integer;

begin
  result := false;

  if zErr then
  begin
    close;
    exit;
  end;

  if FnewSplitNumber <> cCreditInvoive then // 1
  begin
    s := createAllStr;
    if (NOT Ask) OR (s <> zInitString) then
    begin
      // if MessageDlg('Save invoice changes?', mtConfirmation, [mbYes, mbNo, mbCancel], 0) = mrYes then
      if Ask then
        Res := MessageDlg(GetTranslatedText('shTx_Invoice_SaveChanges'), mtConfirmation, [mbYes, mbNo, mbCancel], 0)
      else
        Res := mrYes;
      case Res of
        mrYes:
          begin
            if SaveInvoice(zInvoiceNumber) then
            begin
              zInitString := createAllStr;
              chkChanged;
              try
                d.insertActivityLogFromMemTable;
              except
              end;
              result := false;
            end;
          end;
        mrCancel:
          begin
            result := True;
            exit;
          end;
      end;
    end;
  end;
end;

procedure TfrmInvoice.btnExitClick(Sender: TObject);
begin
  if NOT IsCashInvoice then
    IfInvoiceChangedThenOptionallySave;
  close;
end;

procedure TfrmInvoice.btnClearAddressesClick(Sender: TObject);
begin
  edtAddress1.Text := '';
  edtAddress2.Text := '';
  edtAddress3.Text := '';
  edtAddress4.Text := '';
end;

procedure TfrmInvoice.btnRemoveLodgingTax2Click(Sender: TObject);
begin
  RemoveStayTax;
  RV_ToggleUseStayTax(FReservation);
  calcAndAddAutoItems(FReservation, [aiStayTax]); // 003
end;

procedure TfrmInvoice.btnReservationNotesClick(Sender: TObject);
begin
  g.openresMemo(FReservation);
end;

procedure TfrmInvoice.btnSaveChangesClick(Sender: TObject);
begin
  IfInvoiceChangedThenOptionallySave(false);
  CorrectInvoiceIndexRectangles;
  LoadInvoice;
end;

procedure TfrmInvoice.ClearRoomInfoObjects;
begin
  while FRoomInfoList.Count > 0 do
    FRoomInfoList.delete(0)
end;

{ TInvoiceLine }
constructor TInvoiceLine.create(aIndex, _id: integer);
begin
  inherited create;

  FInvoiceLineIndex := aIndex;

  FId := _id;
  FItem := '';
  FText := '';
  FNumber := 0;
  FPrice := 0.00;
  FTotal := 0.00;
  FRefrence := '';
  FSource := '';
end;

destructor TInvoiceLine.Destroy;
begin
  inherited Destroy;
end;

/// /////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////

const
  vWidth: integer = 9;
  vDec: integer = 2;

  eWidth: integer = 12;
  eDec: integer = 4;

procedure TfrmInvoice.ClearInvoiceLines;
var
  i: integer;
begin
  while FInvoiceLinesList.Count > 0 do
  begin
    try
      TInvoiceLine(FInvoiceLinesList[0]).free;
    except
    end;
    FInvoiceLinesList.delete(0);
  end;
  for i := 0 to agrLines.RowCount - 1 do
    if agrLines.HasCheckBox(col_Select, i) then
      agrLines.RemoveCheckBox(col_Select, i);
end;

function TfrmInvoice.AddLine(lineId: integer;
  sItem, sText: string; iNumber: Double; // -96
  FPrice, FTotal: Double; PurchaseDate: TDate; bAuto: boolean;
  Refrence, Source: string; isPackage: boolean; noGuests: integer;
  confirmDate: TDateTime; confirmAmount: Double; rrAlias: integer;
  AutoGen: string; itemIndex: integer = 0): integer;
var
  invoiceLine: TInvoiceLine;
  iLastIdx: integer;
begin
  if AutoGen = '' then
    AutoGen := _GetCurrentTick;

  iLastIdx := 0;

  if GetInvoiceLineCount > 0 then
  begin
    iLastIdx := FInvoiceLinesList[GetInvoiceLineCount - 1].FInvoiceLineIndex;
  end;

  inc(iLastIdx);

  if trim(sItem) = '' then
    if copy(sText, 1, 5) = 'Tel: ' then
      sItem := trim(g.qPhoneUseItem);

  invoiceLine := TInvoiceLine.create(iLastIdx, lineId);
  invoiceLine.FItem := sItem;
  invoiceLine.FText := sText;
  invoiceLine.FNumber := iNumber;
  invoiceLine.FPrice := FPrice;
  invoiceLine.FTotal := FTotal;
  invoiceLine.FAuto := bAuto;
  invoiceLine.FDate := PurchaseDate;
  invoiceLine.FRefrence := Refrence;
  invoiceLine.FSource := Source;
  invoiceLine.FIspackage := isPackage;
  invoiceLine.FNoGuests := noGuests;
  invoiceLine.FConfirmDate := confirmDate;
  invoiceLine.FConfirmAmount := confirmAmount;
  invoiceLine.FrrAlias := rrAlias;
  invoiceLine.itemIndex := itemIndex;
  invoiceLine.AutoGen := AutoGen;

  result := FInvoiceLinesList.add(invoiceLine);
end;

function TfrmInvoice.GetInvoiceLine(idx: integer): TInvoiceLine;
begin
  result := FInvoiceLinesList[idx];
end;

function TfrmInvoice.GetInvoiceLineCount: integer;
begin
  result := FInvoiceLinesList.Count;
end;

function TfrmInvoice.CellInvoiceLineId(line: integer): integer;
var
  invoiceLine: TInvoiceLine;
begin
  invoiceLine := CellInvoiceLine(line);
  if Assigned(invoiceLine) then
    result := invoiceLine.FId
  else
    result := 0;
end;

function TfrmInvoice.CellInvoiceLine(ARow: integer): TInvoiceLine;
begin
  result := nil;
  if Assigned(agrLines.Objects[cInvoiceLineAttachColumn, ARow]) and
    (agrLines.Objects[cInvoiceLineAttachColumn, ARow] IS TInvoiceLine) then
    result := TInvoiceLine(agrLines.Objects[cInvoiceLineAttachColumn, ARow]);
end;

function TfrmInvoice.DisplayLine(iRow, idx: integer): integer;
var
  invoiceLine: TInvoiceLine;
begin
  // Update the data in the grid with data from the TInvoiceline object linked to it on agrLines.Objects[cInvoiceLineAttachColumn, iRow]
  // If no oibject is attached to the gridcell then retrieve the object from Lines[idx]

  invoiceLine := CellInvoiceLine(iRow);
  if NOT Assigned(invoiceLine) then
    invoiceLine := Lines[idx];

  agrLines.Cells[col_Item, iRow] := invoiceLine.FItem;
  agrLines.Cells[col_Description, iRow] := invoiceLine.FText;
  agrLines.Cells[col_ItemCount, iRow] :=
    trim(_floattostr(invoiceLine.FNumber, vWidth, vDec));
  agrLines.Cells[col_ItemPrice, iRow] :=
    trim(_floattostr(invoiceLine.FPrice, vWidth, vDec));
  agrLines.Cells[col_TotalPrice, iRow] :=
    trim(_floattostr(invoiceLine.FTotal, vWidth, vDec));
  agrLines.Cells[col_System, iRow] := '';
  agrLines.Cells[col_Refrence, iRow] := invoiceLine.FRefrence;
  agrLines.Cells[col_Source, iRow] := invoiceLine.FSource;
  // **AA
  agrLines.Objects[col_Description, iRow] := TObject(trunc(invoiceLine.FDate));
  agrLines.Objects[col_ItemPrice, iRow] := invoiceLine;
  // -- PurchaseDate !
  if invoiceLine.FDate > 0 then
    agrLines.Cells[col_date, iRow] := datetostr(trunc(invoiceLine.FDate));

  agrLines.Cells[col_isPackage, iRow] := _bool2str(invoiceLine.FIspackage, 2);
  agrLines.Cells[col_NoGuests, iRow] := inttostr(invoiceLine.FNoGuests);

  agrLines.Cells[col_confirmdate, iRow] :=  _db(invoiceLine.FConfirmDate, false);
  agrLines.Cells[col_confirmAmount, iRow] := _db(invoiceLine.FConfirmAmount);

  if invoiceLine.FAuto then
    agrLines.Objects[col_Item, iRow] := TObject(-2) // -- Auto !
  else
    agrLines.Objects[col_Item, iRow] := TObject(invoiceLine.FInvoiceLineIndex);
  // -- From File
  agrLines.Cells[col_rrAlias, iRow] := inttostr(invoiceLine.FrrAlias);

  agrLines.Cells[col_autogen, iRow] := invoiceLine.FAutoGen;

  agrLines.Objects[cInvoiceLineAttachColumn, iRow] := invoiceLine; // -- Auto !

  result := iRow;
end;

procedure TfrmInvoice.DisplayTotals(editCol: integer = -1;
  editRow: integer = -1; Value: Double = 0.00);
var

  // dWork: Double;
  dVat: Double;

  i: integer;

  ItemTypeInfo: TItemTypeInfo;
  ItemId: string;

  sPaymentItem: string;
  sRoomRentItem: string;
  sDiscountItem: string;

  TotalDownPayments: Double;
  TotalBalance: Double;

  ttVAT: Double;

  itemAmount: Double;
  ttItemAmount: Double;
  ttItemVat: Double;

  taxAmount: Double;
  ttTaxAmount: Double;
  ttTaxVat: Double;

  rentAmount: Double;
  ttRentAmount: Double;
  ttRentNumber: Double;

  nativeRent: Double;
  nativeTotal: Double;

  nativeTaxAmount: Double;

  rentVat: Double;
  ItemKind: TItemKind;

  lInvRoom: TInvoiceRoomEntity;
begin
  Screen.Cursor := crHourglass;
  try
    sPaymentItem := _trimlower(g.qPaymentItem);
    sRoomRentItem := _trimlower(g.qRoomRentItem);
    sDiscountItem := _trimlower(g.qDiscountItem);

    ttItemAmount := 0.00;
    ttItemVat := 0.00;

    ttRentAmount := 0.00;
    ttRentNumber := 0.00;
    ttTaxAmount := 0.00;
    ttTaxVat := 0.00;

    rentVat := 0.00;
    nativeTaxAmount := 0.00;
    taxAmount := 0.00;

    // --
    for i := 1 to agrLines.RowCount - 1 do
    begin
      ItemId := _trimlower(agrLines.Cells[col_Item, i]);
      if trim(ItemId) <> '' then
      begin
        ItemKind := Item_GetKind(ItemId);

        if ItemId <> '' then
        begin
          // ef ekki grei�sla
          if sPaymentItem <> ItemId then
          begin
            if ((ItemKind <> ikRoomRent) and (ItemKind <> ikRoomRentDiscount) and (ItemKind <> ikStayTax)) then
            begin
              try
                if (editCol = col_ItemCount) AND (editRow = i) then
                  itemAmount := Value * _StrToFloat(agrLines.Cells[col_ItemPrice, i])
                else if (editCol = col_ItemPrice) AND (editRow = i) then
                  itemAmount := Value * _StrToFloat(agrLines.Cells[col_ItemCount, i])
                else
                  itemAmount := _StrToFloat(agrLines.Cells[col_TotalPrice, i]);
              except
                itemAmount := 0;
              end;

              ItemTypeInfo := d.Item_Get_ItemTypeInfo(ItemId,  agrLines.Cells[col_Source, i]);
              lInvRoom := TInvoiceRoomEntity.create(ItemId, 1, 0, _StrToFloat(agrLines.Cells[col_ItemCount, i]),
                taxAmount, 0, 0, false);
              try
                dVat := GetVATForItem(ItemId, itemAmount, _StrToFloat(agrLines.Cells[col_ItemCount, i]),
                  lInvRoom, tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);
              finally
                lInvRoom.free;
              end;
              agrLines.Cells[col_Vat, i] := trim(_floattostr(dVat, vWidth, 3));
              ttItemAmount := ttItemAmount + itemAmount;
              ttItemVat := ttItemVat + dVat;

//              if (LowerCase(agrLines.Cells[col_isPackage, i]) = 'yes') and (trim(agrLines.Cells[col_Source, i]) <> '') then
//              begin
//                if glb.LocateSpecificRecordAndGetValue('packages', 'package', trim(agrLines.Cells[col_Source, i]), 'id', lPackageId) and
//                   glb.LocateSpecificRecordAndGetValue('items', 'item', ItemId, 'id', lItemId) then
//                begin
//                  glb.PackageItems.First;
//                  while not glb.PackageItems.Eof do
//                    if (glb.PackageItems.FieldByName('packageid').asInteger = lPackageId) and
//                       (glb.PackageItems.FieldByName('itemid').asInteger = lItemId) then
//                    begin
//                      if glb.PackageItems.FieldByName('includedInRate').AsBoolean then
//                        ttRentAmount := ttRentAmount - ItemAmount;
//                      Break;
//                    end
//                    else
//                      glb.PackageItems.Next;
//                end;
//              end;


            end
            else if ((ItemKind = ikStayTax)) then
            begin
              ItemTypeInfo := d.Item_Get_ItemTypeInfo(ItemId, agrLines.Cells[col_Source, i]);
              try
                taxAmount := _StrToFloat(agrLines.Cells[col_TotalPrice, i]);
              except
                taxAmount := 0;
              end;
              ttTaxAmount := ttTaxAmount + taxAmount;
              nativeTaxAmount := (ttTaxAmount * zCurrencyRate);
              lInvRoom := TInvoiceRoomEntity.create(ItemId, 1, 0, _StrToFloat(agrLines.Cells[col_ItemCount, i]),
                taxAmount, 0, 0, false);
              try
                dVat := zCurrencyRate * GetVATForItem(ItemId, taxAmount, _StrToFloat(agrLines.Cells[col_ItemCount, i]),
                  lInvRoom, tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);
              finally
                lInvRoom.free;
              end;
              agrLines.Cells[col_Vat, i] := trim(_floattostr(dVat, vWidth, 3));
              ttTaxVat := ttTaxVat + dVat;
            end
            else
            begin
              try
                rentAmount := _StrToFloat(agrLines.Cells[col_TotalPrice, i]);
              except
                rentAmount := 0;
              end;
              ttRentAmount := ttRentAmount + rentAmount;
              ttRentNumber := ttRentNumber + _StrToFloat(agrLines.Cells[col_ItemCount, i]);
            end;
          end
        end;
      end;
    end;

    nativeRent := (ttRentAmount * zCurrencyRate);
    nativeTotal := nativeRent + ttItemAmount + nativeTaxAmount;

    if ABS(nativeRent) > 0.00 then
    begin
      ItemTypeInfo := d.Item_Get_ItemTypeInfo(trim(g.qRoomRentItem));
      lInvRoom := TInvoiceRoomEntity.create(g.qRoomRentItem, 1, 0, 1, nativeRent, 0, 0, false);
      try
        dVat := GetVATForItem(g.qRoomRentItem, nativeRent, ttRentNumber, // 1,
          lInvRoom, tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);
      finally
        lInvRoom.free;
      end;
      rentVat := dVat;
    end;

    ttVAT := roundDecimals(ttItemVat + rentVat + ttTaxVat,
      ctrlGetInteger('VATDecimals'));

    edtTotal.Text := trim(_floattostr((nativeTotal) - ttVAT, vWidth, vDec));
    edtVat.Text := trim(_floattostr(ttVAT, vWidth, vDec));

    edtInvoiceTotal.Text := trim(_floattostr(nativeTotal, vWidth, vDec));

    TotalDownPayments := getDownPayments;
    TotalBalance := nativeTotal - TotalDownPayments;

    edtDownPayments.Text := trim(_floattostr(TotalDownPayments, vWidth, vDec));
    edtBalance.Text := trim(_floattostr(TotalBalance, vWidth, vDec));

    if (edtCurrency.Text <> '') and (edtCurrency.Text <> zNativeCurrency) then
      edtForeignCurrency.Text :=
        _floattostr((nativeTotal) / GetRate(edtCurrency.Text), vWidth, vDec);

  finally
    Screen.Cursor := crDefault;
  end;
end;

procedure TfrmInvoice.DisplayMem(zrSet: TRoomerDataset);
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

procedure TfrmInvoice.DisplayGuestName(zrSet: TRoomerDataset);
begin
  if zrSet = nil then
  begin
    exit;
  end;
  if copy(edtRoomGuest.Text, 1, 1) <> '-' then
  begin
    edtRoomGuest.Text := GetMainGuestName(FReservation,
      FRoomReservation);
  end;
end;

procedure TfrmInvoice.AddRoomTaxToLinesAndGrid(totalTax: Double; TaxUnits: Double;
  taxItem: String = ''; iAddAt: integer = 0);
var
  Item: string;
  aText: string;

  confirmDate: TDateTime;
  confirmAmount: Double;
  unitPrice: Double;

  idx: integer;

begin
  if zFromKredit then
    exit;

  confirmDate := 2;
  confirmAmount := 0;

  if taxItem = '' then
    taxItem := g.qStayTaxItem;
  aText := Item_GetDescription(taxItem);
  Item := trim(taxItem);

  unitPrice := 0.00;
  if totalTax <> 0 then
  begin
    unitPrice := totalTax / TaxUnits;
  end;

  idx := AddLine(0, Item, aText, TaxUnits, unitPrice, totalTax, 0, True, '', '',
    false, 0, confirmDate, confirmAmount, -1, _GetCurrentTick); // 77ATH

  agrLines.InsertRows(iAddAt, 1);
  EmptyRow(agrLines, iAddAt);
  DisplayLine(iAddAt, idx);
end;

procedure TfrmInvoice.SetCurrentVisible;
begin
  if agrLines.RowCount > agrLines.VisibleRowCount then
  begin
    if (agrLines.row > agrLines.TopRow + agrLines.VisibleRowCount - 1) then
      agrLines.TopRow := agrLines.row - agrLines.VisibleRowCount + 1
    else if (agrLines.row < agrLines.TopRow) then
      agrLines.TopRow := agrLines.row;
  end;
end;

procedure TfrmInvoice.CreateCashInvoice(customer: string);
var
  CustomerHolder: recCustomerHolderEX;
  s: string;
begin
  d.RemoveInvoiceCashInvoice;

  Panel1.Color := $00FFDDDD; // $00EAFFEA
  Panel2.Color := $00FFDDDD; // $00EAFFEA

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
  s := s + ', ' + _db(edtCurrency.Text);
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

procedure TfrmInvoice.RestoreTMPInvoicelines;
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
  BreakfastPrice: double;

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

  confirmDate: TDateTime;
  confirmAmount: Double;

begin
  orderStr := ' Roomreservation,ItemNumber ';
  OrginalRef := 0;

  if d.InvoiceLinesTmp_exists(FRoomReservation) then
  begin
    rSet := TRoomerDataset.create(nil);
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
          BreakFastPrice := rSet.FieldByName('isPackage').asFloat;

          vTotal := vTotal + Total;
          vTotalWOVat := vTotalWOVat + TotalWOVat;
          vVat := vVat + Vat;

          importRefrence := rSet.FieldByName('importRefrence').asString;
          ImportSource := rSet.FieldByName('ImportSource').asString;

          confirmDate := rSet.FieldByName('ConfirmDate').asdateTime;
          confirmAmount := rSet.FieldByName('ConfirmAmount').AsFloat;

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
          qry := qry + ', ' + _db(confirmDate);
          qry := qry + ', ' + _db(confirmAmount);
          qry := qry + ', ' + _db(d.roomerMainDataSet.username);
          qry := qry + ', ' + _db(rSet.FieldByName('revenueCorrection').asFloat);
          qry := qry + ', ' + _db(rSet.FieldByName('revenueCorrectionVat').asFloat);

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

Procedure TfrmInvoice.InitInvoiceGrid;
var
  iWidth, i: integer;
begin
  EmptyStringGrid(agrLines);
  agrLines.ColCount := col_autogen + 1;
  agrLines.RowCount := 2;
  agrLines.Cells[col_Item, 0] := GetTranslatedText('shTxInvoice_Form_Header_Item');
  agrLines.Cells[col_Description, 0] := GetTranslatedText('shTxInvoice_Form_Header_Text');
  agrLines.Cells[col_ItemCount, 0] := GetTranslatedText('shTxInvoice_Form_Header_Number');
  agrLines.Cells[col_ItemPrice, 0] := GetTranslatedText('shTxInvoice_Form_Header_UnitPrice');
  agrLines.Cells[col_TotalPrice, 0] := GetTranslatedText('shTxInvoice_Form_Header_Total');
  agrLines.Cells[col_System, 0] := ' !';
  agrLines.Cells[col_Refrence, 0] := GetTranslatedText('shTxInvoice_Form_Header_Reference');
  agrLines.Cells[col_Source, 0] := GetTranslatedText('shTxInvoice_Form_Header_Source');
  agrLines.Cells[col_isPackage, 0] := GetTranslatedText('shTxInvoice_Form_Header_Package');
  agrLines.Cells[col_NoGuests, 0] := GetTranslatedText('shTxInvoice_Form_Header_Guests');
  agrLines.Cells[col_confirmdate, 0] := GetTranslatedText('shTxInvoice_Form_Header_Confirmdate');
  agrLines.Cells[col_confirmAmount, 0] := GetTranslatedText('shTxInvoice_Form_Header_ConfirmAmount');
  agrLines.Cells[col_Vat, 0] := GetTranslatedText('shTxInvoice_Form_Header_Vat');
  agrLines.Cells[col_rrAlias, 0] := GetTranslatedText('shTxInvoice_Form_Header_Alias');
  agrLines.Cells[col_autogen, 0] := 'ID';

  agrLines.AutoFitColumns(false);
  agrLines.ColWidths[col_Item] := 100;
  agrLines.ColWidths[col_ItemCount] := 100;
  agrLines.ColWidths[col_ItemPrice] := 100;
  agrLines.ColWidths[col_TotalPrice] := 100;
  agrLines.ColWidths[col_Source] := 60;
  agrLines.ColWidths[col_Select] := 30;
  iWidth := agrLines.ClientWidth -
    agrLines.ColWidths[col_Item] -
    agrLines.ColWidths[col_ItemCount] -
    agrLines.ColWidths[col_ItemPrice] -
    agrLines.ColWidths[col_TotalPrice] -
    agrLines.ColWidths[col_Source] -
    agrLines.ColWidths[col_Select] -
    5;

  if iWidth > 0 then
    agrLines.ColWidths[col_Description] := iWidth;

  agrLines.HideColumn(col_System);
  agrLines.HideColumn(col_Refrence);
  agrLines.HideColumns(col_isPackage, col_autogen);

  for i := 0 to agrLines.ColCount - 1 do
    if agrLines.IsHiddenColumn(i) then
      agrLines.ColWidths[i] := 0;

end;

function TfrmInvoice.AddRoom(Room: String; fRoomPrice: Double; FromDate: TDate;
  ToDate: TDate; dayCount: integer; sText: string; bGetGuestName: boolean;
  RoomReservation: integer; DiscountAmount: Double;
  DiscountIsPercentage: boolean; DiscountText: string; GuestName: String;
  NumGuests: integer; NumChildren: integer; isPackage: boolean; rrAlias: integer; aBeakfastIncluded: boolean): integer;
var
  i, idx, lRowNr: integer;

  RmRntItem: string;
  ItemTypeInfo: TItemTypeInfo;
  fWork: Double;
  DiscountItem: string;

  sGuestName: string;
  iNumGuests: integer;
  confirmDate: TDateTime;
  confirmAmount: Double;

  rrText: string;
  aText: string;
  lRoomInfo: TRoomInfo;

begin

  confirmDate := 2;
  confirmAmount := 0;

  RmRntItem := trim(g.qRoomRentItem);

  sText := trim(sText);
  rrText := Item_GetDescription(RmRntItem);

  if copy(sText, 1, 2) = '--' then
  begin
    rrText := '';
    sText := copy(sText, 3, maxint);
  end;

  if copy(sText, 1, 2) = '&-' then
  begin
    rrText := '';
    sText := copy(sText, 3, maxint);
  end;

  if copy(sText, 1, 2) = '&&' then
  begin
    bGetGuestName := True;
    sText := copy(sText, 3, maxint);
  end;

  sGuestName := GuestName;
  iNumGuests := NumGuests;

  if not bGetGuestName then
    if rrText <> '' then
      aText := rrText + ' (' + sText + ') '
    else
      aText := sText
  else
    sText := trim(sGuestName) + ' (' + sText + ') ';

  // add a TInvoiceline object for the RoomRent to InvoiceLineList
  idx := AddLine(0, RmRntItem, sText, dayCount, fRoomPrice, fRoomPrice * dayCount,
    0, True, '', '', isPackage, iNumGuests, confirmDate, confirmAmount, rrAlias,
    _GetCurrentTick); // *77

  // Add a row to the grid and display the new invoiceline
  lRowNr := agrLines.RowCount;
  if (agrLines.RowCount = 2) and (agrLines.Cells[col_Item, 1] = '') then
    dec(lRowNr);

  inc(lRowNr);
  agrLines.RowCount := lRowNr;

  i := DisplayLine(lRowNr - 1, idx);

  lRoomInfo := TRoomInfo.create;
  // -- Attach the Room information
  lRoomInfo.RoomReservation := RoomReservation;
  lRoomInfo.Reservation := FReservation;
  lRoomInfo.Name := sGuestName;
  lRoomInfo.Arrival:= FromDate;
  lRoomInfo.Departure := ToDate;
  lRoomInfo.Price := fRoomPrice;
  lRoomInfo.Discount := 0.00;
  lRoomInfo.Room := Room;
  lRoomInfo.NumGuests := iNumGuests;
  lRoomInfo.NumChildren := NumChildren;
  lRoominfo.BreakFastIncluded := aBeakfastIncluded;

  agrLines.Objects[cRoomInfoAttachColumn, i] := lRoomInfo;
  FRoomInfoList.add(lRoomInfo);

  // -- Discount

  if DiscountAmount <> 0 then
  begin
    DiscountItem := trim(g.qDiscountItem);
    ItemTypeInfo := d.Item_Get_ItemTypeInfo(DiscountItem);

    DiscountText := Item_GetDescription(DiscountItem) + ' ' + DiscountText;

    fWork := fRoomPrice;
    if DiscountIsPercentage then
      fWork := (fWork * DiscountAmount / 100) * -1
    else
      fWork := (DiscountAmount) * -1;

    /// Add an InvoiceLine object for the discount
    idx := AddLine(0, DiscountItem, DiscountText, dayCount, fWork,
      fWork * dayCount, 0, True, '', '', false, NumGuests, confirmDate,
      confirmAmount, rrAlias, _GetCurrentTick);

    lRoomInfo.Discount := fWork * dayCount;

    FTotalRoomDiscount := FTotalRoomDiscount + (fWork * dayCount);

    lRowNr := agrLines.RowCount;

    if (agrLines.RowCount = 2) and (agrLines.Cells[col_Item, 1] = '') then
    begin
      dec(lRowNr);
    end;

    inc(lRowNr);
    agrLines.RowCount := lRowNr;
    DisplayLine(lRowNr - 1, idx);
  end;

  UpdateItemInvoiceLinesForTaxCalculations;

  // -- Discount end...
  result := 0;
  DisplayTotals;
end;



procedure TfrmInvoice.sButton2Click(Sender: TObject);
begin
  btnExit.Enabled := True;
  btnInvoice.Enabled := True;
  btnProforma.Enabled := True;
end;

procedure TfrmInvoice.tvPaymentsCellDblClick(Sender: TcxCustomGridTableView;
  ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton;
  AShift: TShiftState; var AHandled: boolean);
begin
  btnEditDownPaymentClick(nil);
end;

procedure TfrmInvoice.tvPaymentsMouseDown(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
begin
  if ssCtrl in Shift then
  begin
    grPayments.BeginDrag(True);
  end;
end;

function TfrmInvoice.getDownPayments: Double;
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
        Total := Total + mPayments.FieldByName('Amount').asfloat;
        mPayments.Next;
      end;
    finally
      mPayments.EnableControls;
    end;
  end;
  result := Total;
end;

procedure TfrmInvoice.loadInvoiceToMemtable(var m: TKbmMemTable);
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
  lineVat: string;
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
    lineRefrence := trim(agrLines.Cells[col_Refrence, i]);
    lineSource := trim(agrLines.Cells[col_Source, i]);
    lineisPackage := trim(agrLines.Cells[col_isPackage, i]);
    lineNoGuests := trim(agrLines.Cells[col_NoGuests, i]);
    lineConfirmdate := trim(agrLines.Cells[col_confirmdate, i]);
    lineConfirmAmount := trim(agrLines.Cells[col_confirmAmount, i]);
    lineVat := trim(agrLines.Cells[col_Vat, i]);
    linerrAlias := trim(agrLines.Cells[col_rrAlias, i]);

    if (lineItem = '') or (isSystemLine(i) = false) then
    begin
      continue;
    end;

    bSystemLine := isSystemLine(i);

    try
      decodedate(integer(agrLines.Objects[col_Description, i]), AYear, AMon, ADay);
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
    if agrLines.Objects[cRoomInfoAttachColumn, i] <> nil then
    begin
      iNights := trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).Departure) -
        trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).Arrival);
    end;

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

    lInvRoom := TInvoiceRoomEntity.create(lineItem, 1, 0, ItemCount, TotalPrice, 0, 0, false);
    try
      fVat := GetVATForItem(lineItem, TotalPrice, ItemCount, lInvRoom,
        tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);
    finally
      lInvRoom.free;
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
    lDate := integer(agrLines.Objects[col_Description, i]);
    m.FieldByName('PurchaseDate').asString := _db(lDate);
    m.FieldByName('InvoiceNumber').asinteger := zInvoiceNumber;
    m.FieldByName('ItemId').asString := lineItem;
    m.FieldByName('Number').asfloat := ItemCount;
    m.FieldByName('Description').asString := lineDescription;
    m.FieldByName('Price').asfloat := ItemPrice;
    m.FieldByName('VATType').asString := ItemTypeInfo.VATCode;
    m.FieldByName('Total').asfloat := TotalPrice;
    m.FieldByName('TotalWOVat').asfloat := TotalPrice - fVat;
    // _CommaToDot(floattostr(iMultiplier * fItemTotalWOVat));
    m.FieldByName('VAT').asfloat := fVat;
    // _CommaToDot(floattostr(iMultiplier * fItemTotalVAT));
    m.FieldByName('CurrencyRate').asfloat := zCurrencyRate;
    m.FieldByName('Currency').asString := edtCurrency.Text;
    m.FieldByName('Persons').asinteger := iPersons;
    m.FieldByName('Nights').asinteger := iNights;
    m.FieldByName('BreakfastPrice').asfloat := 0.00;
    m.FieldByName('AutoGenerated').asBoolean := false;
    m.FieldByName('AYear').asinteger := AYear;
    m.FieldByName('AMon').asinteger := AMon;
    m.FieldByName('ADay').asinteger := ADay;
    m.FieldByName('ilAccountKey').asString := d.Item_Get_AccountKey(lineItem);
    m.FieldByName('importRefrence').asString := lineRefrence;
    m.FieldByName('importSource').asString := lineSource;
    m.FieldByName('isPackage').asBoolean := false;
    m.FieldByName('confirmDate').asdateTime := now;
    m.FieldByName('confirmAmount').asfloat := 0.00;
    m.FieldByName('RoomReservationAlias').asinteger := irrAlias;
    m.FieldByName('issystemLine').asBoolean := bSystemLine;
    m.post;
  end;
end;

function TfrmInvoice.GetInvoiceIndexPanel(Index: integer): TsPanel;
begin
  result := TsPanel(FindComponent('pnlInvoiceIndex' + inttostr(Index)));
end;

function TfrmInvoice.GetInvoiceIndexItems(Index: integer): TShape;
begin
  result := TShape(FindComponent('shpInvoiceIndex' + inttostr(Index)));
end;

function TfrmInvoice.GetInvoiceIndexItemsRR(Index: integer): TShape;
begin
  result := TShape(FindComponent('shpInvoiceIndexRR' + inttostr(Index)));
end;

procedure TfrmInvoice.SetInvoiceIndexPanelsToZero;
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

procedure TfrmInvoice.shpInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
begin
  pnlInvoiceIndex0DragDrop(TShape(Sender), Source, X, Y);
end;

procedure TfrmInvoice.shpInvoiceIndex0DragOver(Sender, Source: TObject; X, Y: integer; State: TDragState;
  var Accept: boolean);
begin
  pnlInvoiceIndex0DragOver(TShape(Sender), Source, X, Y, State, Accept);
end;

procedure TfrmInvoice.shpInvoiceIndex0MouseUp(Sender: TObject; Button: TMouseButton; Shift: TShiftState; X, Y: integer);
begin
  pnlInvoiceIndex0Click(TShape(Sender).Parent);
end;

procedure TfrmInvoice.sPanel4DragOver(Sender, Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean);
begin
  Accept := False;
  if Y < 15 then
    sPanel4.VertScrollBar.Position := sPanel4.VertScrollBar.Position - 8
  else if Y > sPanel4.Height  - 15 then
    sPanel4.VertScrollBar.Position := sPanel4.VertScrollBar.Position + 8;
end;

function TfrmInvoice.GetCalculatedNumberOfItems(ItemId: String; dDefault: Double): Double;
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

procedure TfrmInvoice.LoadInvoice;
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
  lineId: integer;
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

  AvrageDiscountPerc: Double;
  AverageDiscountAmount: Double;

  DiscountText: string;
  TotalDiscountAmount: Double;
  RoomRentPaidDays: Double;
  iTotalResDays: integer;

  TotalRate: Double;
//  ttDiscount: Double;

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
      sList.Free;
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
        GetInvoiceIndexItems(i).Hint := Currency + ' ' +
          trim(_floattostr(Value, 12, 2));
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

  procedure SetInvoiceTypeIndex(index : Integer);
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
  sTemp : String;

label
  Again;
begin
  DeletedLines.Clear;
  ClearRoomInfoObjects;
  ClearInvoiceLines;
  NullifyGrid;

  SetInvoiceIndexPanelsToZero;
  FTotalRoomDiscount := 0.00;

  zrSet := CreateNewDataSet;
  zRoomRSet := CreateNewDataSet;
  zRoomRSet.CommandType := cmdText;

  Screen.Cursor := crHourglass;
  mRoomRes.DisableControls;
  mRoomRates.DisableControls;
  try
    if mRoomRes.active then
      mRoomRes.close;
    mRoomRes.Open;
    if mRoomRates.active then
      mRoomRates.close;
    mRoomRates.Open;

    // -- First the Invoice headers...
    zInvoiceNumber := -1;
    zInvoiceDate := now;
    zPayDate := now;
    zConfirmDate := 2;
    zbRoomRentinTemp := false;

    if FnewSplitNumber = cCashInvoice then
    begin
      CreateCashInvoice(g.qRackCustomer);
      edtCurrency.Text := zNativeCurrency;
      zCurrentCurrency := edtCurrency.Text;
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
      + '(SELECT InvoiceIndex FROM roomreservations rr WHERE ' +
      IIF(FRoomReservation > 0, 'rr.RoomReservation = ih.RoomReservation ', 'rr.Reservation=ih.Reservation ') +
      ' LIMIT 1) rrInvoiceIndex, '
      + '(SELECT GroupAccount FROM roomreservations rr WHERE rr.RoomReservation=ih.RoomReservation) rrGroupAccount, '
      + '(SELECT SUM(RoomRate) FROM roomsdate rd WHERE (rd.RoomReservation=ih.RoomReservation '
      + 'OR rd.Reservation=ih.Reservation) AND rd.Paid=0 AND (NOT rd.ResFlag IN (''C'',''X'',''N'',''O''))) AS rrInvoiceTotal, '
      + 'ih.Reservation, ' +
      'ih.RoomReservation, ' +
      'ih.SplitNumber, ' +
      'ih.InvoiceNumber, ' +
      'ih.InvoiceDate, ' +
      'IFNULL(ia.Customer, ih.Customer) AS Customer, ' +
      'IFNULL(ia.Name, ih.Name) AS Name, ' +
      'IFNULL(ia.Address1, ih.Address1) AS Address1, ' +
      'IFNULL(ia.Address2, ih.Address2) AS Address2, ' +
      'IFNULL(ia.Zip, ih.Address3) AS Address3, ' +
      'IFNULL(ia.City, ih.Address4) AS Address4, ' +
      'IFNULL(ia.Country, ih.Country) AS Country, ' +
      'ih.Total, ' +
      'ih.TotalWOVAT, ' +
      'ih.TotalVAT, ' +
      'ih.TotalBreakFast, ' +
      'IFNULL(ia.ExtraText, ih.ExtraText) AS ExtraText, ' +
      'ih.Finished, ' +
      'ih.ReportDate, ' +
      'ih.ReportTime, ' +
      'ih.CreditInvoice, ' +
      'ih.OriginalInvoice, ' +
      'IFNULL(ia.InvoiceType, ih.InvoiceType) AS InvoiceType, ' +
      'ih.ihTmp, ' +
      'ih.ID, ' +
      'IFNULL(ia.CustPID, ih.CustPID) AS custPID, ' +
      'ih.RoomGuest, ' +
      'ih.ihDate, ' +
      'ih.ihStaff, ' +
      'ih.ihPayDate, ' +
      'ih.ihConfirmDate, ' +
      'ih.ihInvoiceDate, ' +
      'IFNULL(ia.ihCurrency, ih.ihCurrency) AS ihCurrency, ' +
      'ih.ihCurrencyRate, ' +
      'ih.invRefrence, ' +
      'ih.TotalStayTax, ' +
      'ih.TotalStayTaxNights, ' +
      'ih.showPackage, ' +
      'ih.staff, ' +
      'ih.location, ' +
      'ih.externalInvoiceId ' +
      'FROM invoiceheads ih '+ #10 +
      '     LEFT JOIN invoiceaddressees ia ON ia.invoiceNumber=ih.InvoiceNumber ' +
      '        AND ia.Reservation=ih.Reservation ' +
      '        AND ia.RoomReservation=ih.RoomReservation ' +
      '        AND ia.SplitNumber=ih.SplitNumber ' +
      '        AND ia.InvoiceIndex=%d ' +
      'where ih.Reservation = %d '#10 +
      '   and ih.RoomReservation = %d and ih.SplitNumber = %d '#10 +
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
      AddRRColor(zrSet.FieldByName('rrInvoiceIndex').asinteger, zrSet.FieldByName('rrInvoiceTotal').AsFloat, zrSet.FieldByName('ihCurrency').asString);
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

        btnGetCustomer.Enabled := rgrInvoiceType.itemIndex <> 1;
        btnClearAddresses.Enabled := rgrInvoiceType.itemIndex <> 1;

{$ENDREGION}
      end;

      edtCurrency.Text := trim(zrSet.FieldByName('ihCurrency').asString);
      zCurrentCurrency := edtCurrency.Text;
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

      sql := 'SELECT r.*, rr.Currency ' +
             'FROM reservations r ' +
             'JOIN roomreservations rr ON r.Reservation=rr.Reservation ' +
             'WHERE r.Reservation = %d ';

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
        invoiceHeadData.invoiceNumber := zInvoiceNumber;
        invoiceHeadData.InvoiceDate := _db(zInvoiceDate, false);
        invoiceHeadData.ihCurrency := zrSet.FieldByName('Currency').asString;
        invoiceHeadData.ihCurrencyRate := GetRate(zrSet.FieldByName('Currency').asString);

        invoiceHeadData.customer := zrSet.FieldByName('Customer').asString;
        invoiceHeadData.name := zrSet.FieldByName('Name').asString;
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
    InitInvoiceGrid;

    sql := Select_Invoice_LoadInvoice3_WithInvoiceIndex(FRoomReservation, FReservation, FInvoiceIndex, edtCustomer.Text, false{zFakeGroup});

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
        list := TStringList.create;
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
          RoomTypeDescription := zRoomRSet.FieldByName
            ('RoomTypeDescription').asString;
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
          mRoomRes.FieldByName('RoomTypeDescription').asString :=
            RoomTypeDescription;
          mRoomRes.FieldByName('arrival').asdateTime := Arrival;
          mRoomRes.FieldByName('departure').asdateTime := Departure;
          mRoomRes.FieldByName('ChildrenCount').asinteger := ChildrenCount;
          mRoomRes.FieldByName('InfantCount').asinteger := infantCount;
          mRoomRes.FieldByName('PriceCode').asString := PriceCode;
          mRoomRes.FieldByName('AvrageDiscount').asfloat := AvrageDiscountPerc;
          mRoomRes.FieldByName('InvoiceIndex').asinteger := FInvoiceIndex;
          mRoomRes.FieldByName('GroupAccount').asBoolean := zRoomRSet['GroupAccount'];

          if package <> '' then
            if glb.LocateSpecificRecordAndGetValue('packages', 'Package',
              package, 'showItemsOnInvoice', showPackage) then
              chkShowPackage.checked := showPackage;

          dayCount := trunc(Departure) - trunc(Arrival);
          RateDate := Arrival;
          TotalDiscountAmount := 0;

          TotalRate := 0;
          UnpaidDays := 0;
          allIsPercentage := true;

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
                Rate := rSet.FieldByName('RoomRate').AsFloat;
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
                  CurrencyRate := _StrToFloat(edtRate.Text);
                except
                  CurrencyRate := 1
                end;
                if CurrencyRate = 0 then
                  CurrencyRate := 1;
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
          GuestsInRoomRes := NumberGuests; // ChildrenCount+infantCount
          GuestNights := GuestsInRoomRes * UnpaidDays;
          RoomRentPaidDays := iTotalResDays - UnpaidDays;

          if UnpaidDays > 0 then
          begin
            AverageRate := TotalRate / UnpaidDays;
            AverageDiscountAmount := TotalDiscountAmount / UnpaidDays;
            if AverageRate <> 0.00 then
              AvrageDiscountPerc := AverageDiscountAmount / (AverageRate / 100)
            else
              AvrageDiscountPerc := 0.00;

            isPackage := false;
            if ABS(AverageRate) > 0 then
            begin
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
                if UnpaidDays = trunc(Departure) - trunc(Arrival) then
                  _s := format(lRoomtext + ' %s %s - %s', [Room, FormatDateTime('dd/mm', Arrival), FormatDateTime('dd/mm', Departure)])
                else
                  _s := format(lRoomtext + ' %s for %d nights', [Room, UnpaidDays]);
              end;

              sText := _s;

              tmp := trim(zRoomRSet.FieldByName('rrDescription').asString);

              if copy(tmp, 1, 2) = '--' then
                sText := '';
              sText := tmp + sText;

              if allIsPercentage then
                DiscountText := DiscountText + '(' + floattostr(RoundDecimals(AvrageDiscountPerc,2)) + '%)';

              AddRoom(Room, AverageRate, Arrival, Departure, UnpaidDays, sText, (FRoomReservation = 0), lRoomReservation,
                iif(AllIsPercentage, AvrageDiscountPerc, AverageDiscountAmount), AllisPercentage, DiscountText, GuestName, NumberGuests, ChildrenCount, isPackage,
                lRoomReservation, zRoomRSet.FieldByName('invBreakFast').AsBoolean );
            end;

            if (ABS(AverageRate) = 0) and (status <> 'B') then
            begin
              if package <> '' then
              begin
                isPackage := True;
                _s := Package_getRoomDescription(Package, Room, Arrival, Departure, GuestName);
                if FRoomReservation = 0 then
                  _s := _s + ' ' + lRoomText + ':' + Room;
              end
              else
                _s := format(lRoomtext + ' %s %s-%s', [Room, FormatDateTime('dd/mm', Arrival), FormatDateTime('dd/mm', Departure)]);

              sText := _s;

              tmp := trim(zRoomRSet.FieldByName('rrDescription').asString);

              if copy(tmp, 1, 2) = '--' then
                sText := '';
              sText := tmp + sText;

              AddRoom(Room, 0, Arrival, Departure, UnpaidDays, sText, (lRoomReservation = 0), lRoomReservation, 0, false, '', '',
                      NumberGuests, ChildrenCount, isPackage, lRoomReservation, zRoomRSet.FieldByName('invBreakFast').AsBoolean );
            end;
          end;
          inc(index);
          zRoomRSet.Next;
        end;
      end;
    finally
      lExecutionPlan.free;
    end;

    lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
    try
      iCurrentRow := agrLines.RowCount;

      RestoreTMPInvoicelines;

      // -- Then the invoice lines...

      sql := 'SELECT il.* ' +
        ' FROM invoicelines il where Reservation = %d ' +
        '   and RoomReservation = %d ' + '   and SplitNumber = %d ' +
        '   and InvoiceNumber = -1 AND InvoiceIndex = %d';
      sql := format(sql, [FReservation, FRoomReservation,
        FnewSplitNumber, FInvoiceIndex]);
      lExecutionPlan.AddQuery(sql);

      sql := 'SELECT * FROM payments ' + ' where Reservation = %d ' +
        '   and RoomReservation = %d ' +
        '   and InvoiceNumber = -1 AND InvoiceIndex = %d';
      sql := format(sql, [FReservation, FRoomReservation,
        FInvoiceIndex]);
      lExecutionPlan.AddQuery(sql);

      sql := 'SELECT SUM(IF(xxx.RoomReservation>0 AND xxx.Reservation>0, xxx.NumberOfGuests * xxx.NumberOfDays, ' +
        ' (SELECT SUM((SELECT COUNT(id) FROM roomsdate WHERE RoomReservation = pe.RoomReservation AND NOT (ResFlag IN (''X'',''C'',''N'')))) AS GuestNights '
        +
        '   FROM persons pe ' +
        '   WHERE pe.Reservation=xxx.Reservation) ' +
        ')) AS NumberGuestNights, ' +
        'SUM(NumberOfDays) AS NumberOfDays, ' +
        'SUM(NumberOfGuests) AS NumberOfGuests ' +
        'FROM ( ' +
        'SELECT RoomReservation, Reservation, IF(il.RoomReservation>0 AND il.Reservation>0, (SELECT COUNT(ID) FROM roomsdate WHERE RoomReservation=il.RoomReservation AND NOT (ResFlag IN (''X'',''C'',''N'')) LIMIT 1), '
        +
        '          IF(il.Reservation>0, (SELECT COUNT(ID) FROM roomsdate WHERE Reservation=il.Reservation AND NOT (ResFlag IN (''X'',''C'',''N'')) LIMIT 1), '
        +
        '          0)) AS NumberOfDays, ' +
        ' ' +
        '       IF(il.RoomReservation>0 AND il.Reservation>0, (SELECT COUNT(ID) FROM persons WHERE RoomReservation=il.RoomReservation LIMIT 1), '
        +
        '          IF(il.Reservation>0, (SELECT COUNT(ID) FROM persons WHERE Reservation=il.Reservation LIMIT 1), 0)) AS NumberOfGuests '
        +

        'FROM roomreservations il ' +
        'where (%d <= 0 AND Reservation=%d) OR (RoomReservation = %d) ' +
        ')xxx';
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
        lineId := eSet.FieldByName('Id').asinteger;

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
          _s := _s + Format(' %s %s', [lRoomAdditionalText, Room ]);

        dNumber := GetCalculatedNumberOfItems(ItemId, eSet.FieldByName('Number').AsFloat);

        idx := AddLine(lineId, ItemId, _s,
          dNumber, Price, // -96
          Price * dNumber, // -96
          SQLToDate(eSet.FieldByName('PurchaseDate').asString), false,
          trim(eSet.FieldByName('importRefrence').asString),
          trim(eSet.FieldByName('importSource').asString),
          eSet.FieldByName('isPackage').asBoolean,
          eSet.FieldByName('Persons').asinteger,
          eSet.FieldByName('ConfirmDate').asdateTime,
          eSet.FieldByName('ConfirmAmount').AsFloat,
          lRoomReservation, eSet.FieldByName('AutoGen').asString,
          eSet.FieldByName('ItemNumber').asinteger);
        if (agrLines.Cells[col_Item, agrLines.RowCount - 1] <> '') or (agrLines.Cells[col_Description, agrLines.RowCount - 1] <> '') then
          inc(iCurrentRow);
        agrLines.RowCount := iCurrentRow;
        DisplayLine(iCurrentRow - 1, idx);
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
          mPayments.FieldByName('Amount').asfloat := eSet.FieldByName('Amount').asfloat;
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

      inc(iCurrentRow);
      if (agrLines.RowCount > 2) or (trim(agrLines.Cells[col_Item, 1]) <> '')
      then
      begin
        agrLines.RowCount := iCurrentRow;
        calcAndAddAutoItems(FReservation); // 001
      end;

      agrLines.row := agrLines.RowCount - 1;

      SetCurrentVisible;

      agrLines.Objects[col_Description, agrLines.RowCount - 1] := TObject(trunc(now));
      // -- PurchaseDate !
      agrLines.Cells[col_date, agrLines.RowCount - 1] :=
        datetostr(trunc(now));

      if zFirsttime then // **15-10-16
      begin
        zFirsttime := false;
        loadInvoiceToMemtable(d.mInvoicelines_before);
      end;
    finally
      lExecutionPlan.free;
    end;

  finally
    zrSet.free;
    zRoomRSet.free;
    mRoomRes.EnableControls;
    mRoomRates.EnableControls;
    Screen.Cursor := crDefault;
    zFirsttime := True;
  end;

  UpdateItemInvoiceLinesForTaxCalculations;

  zInitString := createAllStr;
  AddEmptyLine(false);
  CorrectInvoiceIndexRectangles;

  setControls;
end;

function TfrmInvoice.LocateDate(recordSet: TRoomerDataset; field: String; Value: TDate): boolean;
begin
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

function TfrmInvoice.FindLastRoomRentLine: integer;
var
  i: integer;
begin
  result := 0;
  for i := 1 to agrLines.RowCount - 1 do
  begin
    if agrLines.Cells[col_Item, i] = g.qRoomRentItem then
      result := i
    else
      break;
  end;
end;

procedure TfrmInvoice.UpdateItemInvoiceLinesForTaxCalculations;
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

  zCurrentCurrency := edtCurrency.Text;
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
        lInvRoom := TInvoiceRoomEntity.create(Item, taxGuests, 0, taxNights, ItemPrice, 0, 0, false);
        try
          itemVAT := GetVATForItem(Item, ItemPrice, 1, lInvRoom, tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);  // BHG
        finally
          lInvRoom.free;
        end;
      end;

      tempInvoiceItemList.add(TInvoiceItemEntity.create(Item, taxNights, ItemPrice, itemVAT));
    end;
  end;
end;

procedure TfrmInvoice.calcAndAddAutoItems(reservation: integer; aAutoItems: TInvoiceAutoItemSet);
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

  RoomInfo: TRoomInfo;
  lBreakfastIncl: boolean;
  litemKind: TItemKind;

begin

  zCurrentCurrency := edtCurrency.Text;
  zCurrencyRate := GetRate(zCurrentCurrency);

  itemVAT := 0.00;

  ItemInvoiceLines := TInvoiceItemEntityList.create(True);
  RoomInvoiceLines := TInvoiceRoomEntityList.create(True);
  try
    for i := 1 to agrLines.RowCount - 1 do
    begin
      Item := _trimlower(agrLines.Cells[col_Item, i]);
      if trim(Item) <> '' then
      begin
        ItemTypeInfo := d.Item_Get_ItemTypeInfo(Item, agrLines.Cells[col_Source, i]);
        lItemKind := Item_GetKind(Item);

        taxGuests := StrToIntDef(trim(agrLines.Cells[col_NoGuests, i]), 0);
        taxNights := StrToFloatDef(trim(agrLines.Cells[col_ItemCount, i]), 0.00);

        if agrLines.Objects[cRoomInfoAttachColumn, i] IS TRoomInfo then
        begin
          RoomInfo := agrLines.Objects[cRoomInfoAttachColumn, i] AS TRoomInfo;
          taxChildren := RoomInfo.NumChildren;
          Discount := RoomInfo.Discount;
          lBreakfastIncl := Roominfo.BreakFastIncluded;
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
          ItemPrice := StrToFloatDef(agrLines.Cells[col_TotalPrice, i], 0.00) / taxNights; // use total price because itemprice is rounded

        lInvRoom := nil;
        if not SameValue(ItemPrice, 0) then
        begin
          lInvRoom := TInvoiceRoomEntity.create(Item, taxGuests, taxChildren, taxNights, ItemPrice, 0, Discount, lBreakfastIncl);
          lInvRoom.Vat := GetVATForItem(Item, ItemPrice, 1, lInvRoom, tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);

          if NOT(lItemKind IN [ikRoomRent, ikRoomRentDiscount]) then
            agrLines.Cells[col_Vat, i] := trim(_floattostr(itemVAT, vWidth, 3));
        end;

        if (lItemKind = ikRoomRent) then
          if assigned(lInvRoom) then
            RoomInvoiceLines.add(lInvRoom)
          else
            RoomInvoiceLines.add(TInvoiceRoomEntity.create(Item, taxGuests, taxChildren, taxNights, ItemPrice, itemVAT, Discount, lBreakfastIncl));

        ItemInvoiceLines.add(TInvoiceItemEntity.create(Item, taxNights, ItemPrice, itemVAT));
      end;
    end;

    if aiIncludedBreakFast in aAutoItems then
      CalcAndAddIncludedBreakFast(RoomReservation, RoomInvoiceLines);

    if aiStayTax in aAutoItems then
      CalcAndAddStayTax(RoomReservation, RoomInvoiceLines);


  finally
    RoomInvoiceLines.free;
    ItemInvoiceLines.free;
  end;
end;

procedure TfrmInvoice.CalcAndAddIncludedBreakFast(aReservation: integer; aRoominvoiceLinesList: TInvoiceRoomEntityList);
begin
  if glb.PMSSettings.InvoiceSettings.ShowIncludedBreakfastOnInvoice then
  begin
    AddIncludedBreakfastToLinesAndGrid(aRoomInvoiceLinesList.IncludedBreakfastCount, FindLastRoomRentLine + 1);
    DisplayTotals;
  end;
end;

procedure TfrmInvoice.AddIncludedBreakfastToLinesAndGrid(aIncludedBreakfastCount: integer; iAddAt: integer = 0);
var
  lText: string;
  idx: integer;
  lItem: string;
begin
  if zFromKredit then
    exit;

  RemoveAutoBreakFastItems;
  if aIncludedBreakFastCount > 0 then
  begin
    lItem := g.qBreakFastItem;
    lText := Item_GetDescription(lItem) + ' (' + GetTranslatedText('shTx_ReservationProfile_Included')  + ')';

    idx := AddLine(0, lItem, lText, aIncludedBreakfastCount, 0, 0, 0, True, '', '',  false, 0, 0, 0, -1, _GetCurrentTick); // 77ATH

    agrLines.InsertRows(iAddAt, 1);
    EmptyRow(agrLines, iAddAt);
    DisplayLine(iAddAt, idx);
  end;
end;

procedure TfrmInvoice.RemoveAutoBreakfastItems;
var
  i: integer;
  anyRemoved: boolean;
  lInvLine: TInvoiceLine;
  lBrItem: string;
begin
  anyRemoved := false;
  lBrItem := g.qBreakFastItem;
  for i := agrLines.RowCount - 1 downto 1 do
  begin
    if agrLines.Objects[cInvoiceLineAttachColumn, i] is TInvoiceLine then
    begin
      lInvLine := agrLines.Objects[cInvoiceLineAttachColumn, i] AS TInvoiceLine;
      if linvLine.FAuto and (linvLine.Item.Equals(lBritem)) then
      begin
        DeleteRow(agrLines, i);
        anyRemoved := True;
      end;
    end;
    if anyRemoved then
    begin
      AddEmptyLine;
      DisplayTotals;
      chkChanged;
    end;
  end;
end;

procedure TfrmInvoice.CalcAndAddStayTax(aReservation: integer; aRoominvoiceLinesList: TInvoiceRoomEntityList);
var
  lUseStayTax: boolean;
  lIsIncluded: boolean;
  lItemTypeInfo: TItemTypeInfo;
  lTaxResultInvoiceLines: TInvoiceTaxEntityList;
  lStayTaxUnitCount: integer;
  lTotalTaxIncluded: double;
  lTotalTaxExcluded: double;
  lTotal: double;
  lStayTaxUnitCountIncluded: integer;
  lStayTaxUnitCountExcluded: integer;
  tt, l: integer;
  lCalcOptions: TInvoiceCityTaxCalculationOptions;
begin
  if zFromKredit then
    exit;

  /// calc and add StayTax
  RemoveStayTax;

  labLodgingTaxISK.caption := '0';
  labLodgingTaxNights.caption := '0';

  lUseStayTax := ctrlGetBoolean('useStayTax') AND RV_useStayTax(reservation);
  useStayTaxOutcome := lUseStayTax;

  glb.LocateSpecificRecordAndGetValue('customers', 'Customer', edtCustomer.Text, 'StayTaxIncluted', lIsIncluded);

  lCalcOptions := [];
  if lIsIncluded then
    Include(lCalcOptions, tcoCustomerHasTaxIncluded);

  if lUseStayTax then
  begin
    lItemTypeInfo := d.Item_Get_ItemTypeInfo(trim(g.qRoomRentItem));
    lTaxResultInvoiceLines := GetTaxesForInvoice(aRoominvoiceLinesList, lItemTypeInfo, lCalcOptions);
  end
  else
    lTaxResultInvoiceLines := TInvoiceTaxEntityList.create(True);

  try

    lStayTaxUnitCount := 0;
    lTotalTaxIncluded := 0.00;
    lStayTaxUnitCountIncluded := 0;

    lIsIncluded := false;

    GetTaxTypes(lTaxResultInvoiceLines);
    for tt := 0 to TaxTypes.Count - 1 do
    begin
      lTotalTaxExcluded := 0;
      lStayTaxUnitCountExcluded := 0;

      for l := 0 to lTaxResultInvoiceLines.Count - 1 do
        if lTaxResultInvoiceLines[l].BookingItem = TaxTypes[tt] then
        begin
          lTotal := lTaxResultInvoiceLines[l].Total;

          lStayTaxUnitCount := lStayTaxUnitCount + trunc(lTaxResultInvoiceLines[l].NumItems);

          case lTaxResultInvoiceLines[l].IncludedInPrice of
            TIE_PER_CUSTOMER: glb.LocateSpecificRecordAndGetValue('customers', 'Customer', edtCustomer.Text, 'StayTaxIncluted', lIsIncluded);
            TIE_INCLUDED:     lIsIncluded := True;
            TIE_EXCLUDED:     lIsIncluded := false;
          end;

          if lIsIncluded then
          begin
            lTotalTaxIncluded := lTotalTaxIncluded + lTotal;
            lStayTaxUnitCountIncluded := lStayTaxUnitCountIncluded + trunc(lTaxResultInvoiceLines[l].NumItems);
          end
          else
          begin
            if NOT lTaxResultInvoiceLines[l].Percentage then
              lTotalTaxExcluded := lTotalTaxExcluded + _RoundN(lTotal / zCurrencyRate, 2)
            else
              lTotalTaxExcluded := lTotalTaxExcluded + lTotal;
            lStayTaxUnitCountExcluded := lStayTaxUnitCountExcluded + trunc(lTaxResultInvoiceLines[l].NumItems);
          end;
        end;

      if (lStayTaxUnitCountExcluded <> 0) then
        AddRoomTaxToLinesAndGrid(lTotalTaxExcluded, lStayTaxUnitCountExcluded, TaxTypes[tt], FindLastRoomRentLine + 1);

    end;
  finally
    lTaxResultInvoiceLines.free;
  end;

  grbInclutedTaxes.Visible := (lStayTaxUnitCountIncluded <> 0);

  labLodgingTaxISK.caption := _floattostr(lTotalTaxIncluded, vWidth, vDec);
  labLodgingTaxNights.caption := floattostr(lStayTaxUnitCount);

  DisplayTotals;
end;

procedure TfrmInvoice.GetTaxTypes(TaxResultInvoiceLines: TInvoiceTaxEntityList);
var
  i: integer;
  Item: String;
begin
  TaxTypes.Clear;
  for i := 0 to TaxResultInvoiceLines.Count - 1 do
  begin
    Item := TaxResultInvoiceLines[i].BookingItem;
    if TaxTypes.IndexOf(Item) < 0 then
      TaxTypes.add(Item);
  end;
end;

procedure TfrmInvoice.RemoveStayTax;
var
  i: integer;
  anyRemoved: boolean;
begin
  anyRemoved := false;
  for i := agrLines.RowCount - 1 downto 1 do
  begin
    if TaxTypes.IndexOf(agrLines.Cells[col_Item, i]) >= 0 then
    begin
      DeleteRow(agrLines, i);
      anyRemoved := True;
    end;
  end;
  if anyRemoved then
  begin
    AddEmptyLine;
    DisplayTotals;
    chkChanged;
  end;
end;

procedure TfrmInvoice.setControls;
begin
  btnRoomToTemp.Enabled := not((FReservation = 0) AND
    (FRoomReservation = 0));
  if (agrLines.Cells[col_Item, 1] = '') then
    btnRoomToTemp.Enabled := false;

  btnItemToTmp.Enabled := btnRoomToTemp.Enabled;
  btnRemoveLodgingTax2.Enabled := btnRoomToTemp.Enabled;
  btnReservationNotes.Enabled := btnRoomToTemp.Enabled;
  Removetemporarily1.Enabled := btnRoomToTemp.Enabled;
  RemoveRoomRenttemporarity1.Enabled := btnRoomToTemp.Enabled;
  SendItemToGroupInvoice.Enabled := btnRoomToTemp.Enabled;

end;

function TfrmInvoice.GenerateInvoiceNumber: integer;
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

procedure TfrmInvoice.DeleteLinesInList(ExecutionPlan: TRoomerExecutionPlan);
var
  i: integer;
begin
  for i IN DeletedLines do
  begin
    ExecutionPlan.AddExec('DELETE FROM invoicelines WHERE ID=' + inttostr(i));
  end;
  DeletedLines.Clear;
end;

constructor TfrmInvoice.Create(aOwner: TComponent);
begin
  DeletedLines := TList<integer>.create;
  SelectableRooms := TRoomInfoList.create(True);
  SelectableExternalRooms := TRoomInfoList.create(True);
  TaxTypes := TStringList.create;

  FInvoiceLinesList := TList<TInvoiceLine>.create;
  FRoomInfoList := TRoomInfoList.create(True);
  tempInvoiceItemList := TInvoiceItemEntityList.create(True);

  inherited;

end;

procedure TfrmInvoice.FormCreate(Sender: TObject);
begin
  zErr := false;
  zFirsttime := True;
  zApply := false;

  linesNumDays := 0;
  linesNumGuests := 0;
  NumberGuestNights := 0;

  FInvoiceIndex := 0;

  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);

  useStayTaxAlreadyFetched := false;
  useStayTaxOutcome := True;
  tempInvoiceNo := GenerateInvoiceNumber;
  zEmailAddress := '';

  zDoSave := True;

  zLocation := '';
  zOriginalInvoice := 0;

  zCellValue := '';

  zbDoingReference := false;

  vDec := 2;

  zCurrencyRate := 1.00;

end;

procedure TfrmInvoice.FormDestroy(Sender: TObject);
begin
  try
    OnResize := nil;
    SelectableRooms.free;
    SelectableExternalRooms.free;
    RemoveInvalidKreditInvoice;

    // --
    ClearRoomInfoObjects;
    ClearInvoiceLines;
    DeletedLines.Free;

    NullifyGrid;
    FInvoiceLinesList.free;
    FRoomInfoList.free;

    if mRoomRes.active then
      mRoomRes.close;
    if mRoomRates.active then
      mRoomRates.close;

    TaxTypes.free;
  except
  end;

  tempInvoiceItemList.free;

  frmMain.btnRefresh.Click;
end;

procedure TfrmInvoice.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    btnExit.Click;
end;

procedure TfrmInvoice.FormResize(Sender: TObject);
begin
  agrLines.AutoFitColumns(false);
end;

procedure TfrmInvoice.FormShow(Sender: TObject);
begin
  btnEditDownPayment.Visible := glb.PMSSettings.InvoiceSettings.AllowPaymentModification;
  btnDeleteDownpayment.Visible := glb.PMSSettings.InvoiceSettings.AllowPaymentModification;
  btnRemoveItem.Visible := glb.PMSSettings.InvoiceSettings.AllowDeletingItemsFromInvoice;
  btnRemoveLodgingTax2.Visible := glb.PMSSettings.InvoiceSettings.AllowTogglingOfCityTaxes;

  LoadInvoice;
  UpdateCaptions;

  sPanel4.Visible := NOT(IsCashInvoice OR FIsCredit {or zFakeGroup});
  Exit1.Enabled := True;
end;

procedure TfrmInvoice.N91Click(Sender: TObject);
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
        MoveItemToRoomInvoice(SelectableRooms[omnu.Tag].RoomReservation, SelectableRooms[omnu.Tag].Reservation,
          TMenuItem(Sender).Tag);
      end;
    end;
  finally
    list.free;
  end;
end;

procedure TfrmInvoice.ExternalRoomsClick(Sender: TObject);
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
        MoveItemToRoomInvoice(SelectableExternalRooms[omnu.Tag].RoomReservation, SelectableExternalRooms[omnu.Tag].Reservation, TMenuItem(Sender).Tag);
      end;
    end;
  finally
    list.free;
  end;
end;

procedure TfrmInvoice.TransferRoomToAnyRoomsClick(Sender: TObject);
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
        RealRoomReservation := TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).RoomReservation;
        TransferRoomToAnotherRoomReservationInvoice(FRoomReservation,
          SelectableExternalRooms[omnu.Tag].RoomReservation, RealRoomReservation,
          SelectableExternalRooms[omnu.Tag].Reservation);
      end;
    end;
  finally
    list.free;
  end;
end;

procedure TfrmInvoice.TransferRoomToAnotherRoomReservationInvoice(FromRoomReservation, RoomReservation,
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
  DeleteRow(agrLines, agrLines.row);
  AddEmptyLine;
  calcAndAddAutoItems(FReservation);
  zInitString := createAllStr;
  chkChanged;
end;

procedure TfrmInvoice.NullifyGrid;
var
  iCol, iRow: integer;
begin
  agrLines.UnHideColumnsAll;
  for iRow := 0 to agrLines.RowCount - 1 do
    for iCol := 0 to agrLines.ColCount - 1 do
      agrLines.Objects[iCol, iRow] := nil;
  agrLines.RowCount := 0;
  agrLines.ColCount := 0;
  agrLines.ClearAll;
end;

/// <summary>
/// If the last row is not empty, add an extra row to the grid. <br/>
/// Initialize the last row of the grid and make it the current row and visible.
///
/// </summary>
procedure TfrmInvoice.AddEmptyLine(CheckChanged: boolean = True);
begin
  AddAndInitNewRow;

  agrLines.row := agrLines.RowCount - 1;
  agrLines.Col := 0;
  SetCurrentVisible;
  if CheckChanged then
    chkChanged;
  ForceRowChange;
end;

/// <summary>
/// If the last row is not empty, add an extra row to the grid. <br/>
/// Initialize the last row of the grid with purchase date = now
/// </summary>
procedure TfrmInvoice.AddAndInitNewRow;
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

  agrLines.Objects[col_Description, agrLines.RowCount - 1] := TObject(trunc(now)); // -- PurchaseDate !
  agrLines.Cells[col_date, agrLines.RowCount - 1] := datetostr(trunc(now));
end;

procedure TfrmInvoice.UpdateCaptions;
var
  invNo: integer;
begin
  caption := GetTranslatedText('shUI_InvoiceCaption');

  labTmpStatus.caption := inttostr(d.kbmInvoicelines.RecordCount);
  ClabLodgingTaxCurrency.caption := g.qNativeCurrency;

  agrLines.Col := 0;
  agrLines.row := 1;

  // --
  if FIsCredit then
  begin
    clabInvoice.caption := GetTranslatedText('shUI_CreditInvoiceCaption');
    Panel1.Color := $00F5ECFF; // $00EAFFEA
    Panel2.Color := $00F5ECFF; // $00EAFFEA

    zCreditType := ctManual;;
    zRefNum := -1;
    invNo := 0;
    zRefNum := invNo;

    zCreditType := ctManual;
    zRefNum := -1;
    zOriginalInvoice := zRefNum;
  end;

  zInitString := createAllStr;

  if (agrLines.ColCount >= col_TotalPrice) then
  begin
    agrLines.ColWidths[col_ItemCount] := 100;
    agrLines.ColWidths[col_ItemPrice] := 100;
    agrLines.ColWidths[col_TotalPrice] := 100;
  end;

  OriginalInvoiceStatus := GridFloatValueFromString(edtBalance.Text);
end;

procedure TfrmInvoice.CheckRoomRentItem(iRow: integer);
var
  i: integer;
  iNights: integer;
  iPersons: integer;
  iRooms: integer;
  dRoomPrice: Double;
  ttRoomNights: Double; // -96
  ttPrice: Double;
  lRoomInfo: TRoomInfo;

begin
  i := iRow;

  if agrLines.Cells[col_Item, i] = g.qRoomRentItem then
  begin
    iPersons := 1;
    iRooms := 1;
    iNights := 1;
    dRoomPrice := 0;

    if g.AddAccommodation(iPersons, iRooms, iNights, dRoomPrice) then
    begin
      ttRoomNights := iNights * iRooms;
      ttPrice := ttRoomNights * dRoomPrice;

      if (iPersons > 0) and (iNights > 0) then
      begin
        agrLines.Cells[col_ItemCount, i] := _floattostr(ttRoomNights,
          vWidth, vDec);
        agrLines.Cells[col_ItemPrice, i] :=
          _floattostr(dRoomPrice, vWidth, vDec);
        agrLines.Cells[col_NoGuests, i] := inttostr(iPersons);

        if (agrLines.Objects[cRoomInfoAttachColumn, i] <> nil) and
          (agrLines.Objects[cRoomInfoAttachColumn, i] is TRoomInfo) then
        begin
          with TRoomInfo(agrLines.Objects[col_ItemCount, i]) do
          begin
            RoomReservation := -1;
            Reservation := -1;
            Name := edtName.Text;
            Arrival := now;
            Departure := now + iNights;
            Price := _StrToFloat(agrLines.Cells[col_ItemPrice, i]);
            NumGuests := iPersons;
          end;
        end
        else
        begin
          lRoomInfo := TRoomInfo.create;
          lRoomInfo.RoomReservation := -1;
          lRoomInfo.Reservation := -1;
          lRoomInfo.Name := edtName.Text;
          lRoomInfo.Arrival := now;
          lRoomInfo.Departure := now + iNights;
          lRoomInfo.Price := _StrToFloat(agrLines.Cells[col_ItemPrice, i]);
          lRoomInfo.NumGuests := iPersons;
          agrLines.Objects[cRoomInfoAttachColumn, i] := lRoomInfo;
          FRoomInfoList.add(lRoomInfo);
        end;

        agrLines.Cells[col_TotalPrice, i] := _floattostr(ttPrice, vWidth, vDec);
        calcAndAddAutoItems(FReservation); // 002
        chkChanged;
      end;
    end;
  end;

end;

procedure TfrmInvoice.agrLinesMouseDown(Sender: TObject; Button: TMouseButton;
  Shift: TShiftState; X, Y: integer);
var
  ACol: integer;
  ARow: integer;
  ItemId: string;
  lRoomreslist: TStringlist;
  lGotoRoomRes: integer;
begin

  agrLines.MouseToCell(X, Y, ACol, ARow);
  if ssCtrl in Shift then
  begin
    agrLines.row := ARow;
    agrLines.Col := ACol;
    if (ARow >= 0) AND (ARow < agrLines.RowCount) then
      agrLines.BeginDrag(True);
    exit;
  end;

  if (ACol < 0) OR (ACol >= agrLines.ColCount) OR (ARow < 0) OR
    (ARow >= agrLines.RowCount) then
    exit;

  if (ACol = col_Description) or (ACol = col_ItemCount) then
    exit;

  ItemId := agrLines.Cells[col_Item, ARow];
  if (ACol > 0) AND // Skip Checkbox column
    (((ItemId = g.qRoomRentItem) or (ItemId = g.qDiscountItem)) AND
    (isSystemLine(agrLines.row) = True)) then
  begin
      lGotoRoomRes := -1;
      lRoomreslist := TStringlist.Create;
      try
        if RoomReservation <> 0 then
          lRoomreslist.Add(intToStr(RoomReservation))
        else  // GroupInvoice, collect all roomres in this invoice
        begin
          mRoomres.DisableControls;
          try
            mRoomres.First;
            while not mRoomRes.Eof do
            begin
              lRoomResList.add(mRoomResroomreservation.AsString);
              mRoomRes.Next;

              if (agrLines.Objects[cRoomInfoAttachColumn, ARow] <> nil) and (agrLines.Objects[cRoomInfoAttachColumn, ARow] is TRoomInfo) then
                lGotoRoomRes := TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, ARow]).RoomReservation;
            end;
          finally
            mRoomRes.EnableControls;
          end;
        end;

        if lRoomResList.Count > 0 then
        begin
          if EditRoomRates(lRoomreslist, FInvoiceIndex, zCurrentCurrency, lGotoRoomRes) then
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
      lRoomResList.Free;
    end;
  end;

  TAdvStringGrid(Sender).MouseToCell(X, Y, ACol, ARow);
  if ARow > 0 then
  begin
    TAdvStringGrid(Sender).row := ARow;
    TAdvStringGrid(Sender).Col := ACol;
  end;
end;

procedure TfrmInvoice.CheckCheckboxes;
var
  i: integer;
begin
  for i := 0 to agrLines.RowCount - 1 do
    try
      if NOT agrLines.HasCheckBox(col_Select, i) then
        if agrLines.Cells[col_Item, i] <> '' then
          agrLines.AddCheckBox(col_Select, i, false, false);
    Except
    end;
end;

procedure TfrmInvoice.CheckOrUncheckAll(check: boolean);
var
  i: integer;
begin
  for i := 0 to agrLines.RowCount - 1 do
    if agrLines.HasCheckBox(col_Select, i) then
      agrLines.SetCheckBoxState(col_Select, i, check);
end;

procedure TfrmInvoice.agrLinesRowChanging(Sender: TObject;
  OldRow, NewRow: integer; var Allow: boolean);
var
  sCurrentItem, sRoomRentItem, sDiscountItem: String;
begin
  try
    if NewRow > 0 then
    begin
      sCurrentItem := _trimlower(agrLines.Cells[col_Item, NewRow]);
      sRoomRentItem := _trimlower(g.qRoomRentItem);
      sDiscountItem := _trimlower(g.qDiscountItem);

      btnRoomToTemp.Enabled := ((sCurrentItem = sRoomRentItem) OR (sCurrentItem = sDiscountItem)) OR
        (AnyRowChecked AND IsRoomSelected);
      btnItemToTmp.Enabled := AnyRowChecked OR ((NOT isSystemLine(NewRow)) AND (sCurrentItem <> ''));
      btnMoveItem.Enabled := btnItemToTmp.Enabled OR AnyRowChecked;
      btnMoveRoom.Enabled := btnRoomToTemp.Enabled;
      btnRemoveItem.Enabled := btnItemToTmp.Enabled OR AnyRowChecked;
    end
    else
    begin
      btnRoomToTemp.Enabled := AnyRowChecked;
      btnItemToTmp.Enabled := AnyRowChecked;
      btnMoveItem.Enabled := btnItemToTmp.Enabled;
      btnMoveRoom.Enabled := btnRoomToTemp.Enabled AND IsRoomSelected;
      btnRemoveItem.Enabled := btnItemToTmp.Enabled;
    end;
  except
    // Hide and problem that happens in this event.
    // There never should be exception here, but if
    // one happens then it should not stop the chain
    // of events from firing.
  end;
  CheckCheckboxes;
end;

procedure TfrmInvoice.edtTotalChange(Sender: TObject);
begin
  TEdit(Sender).OnChange := nil;
  try
    TEdit(Sender).Text := RightAligned(TEdit(Sender).Text, 12);
  finally
    TEdit(Sender).OnChange := edtTotalChange;
  end;
end;

procedure TfrmInvoice.Exit1Click(Sender: TObject);
begin
  btnExit.Click;
end;

procedure TfrmInvoice.RemoveInvalidKreditInvoice;
var
  i: integer;
begin
  for i := LOW(REMOVE_REDUNDANT_INVOICES) to HIGH(REMOVE_REDUNDANT_INVOICES) do
    d.roomerMainDataSet.DoCommand(REMOVE_REDUNDANT_INVOICES[i]);
end;

procedure TfrmInvoice.SaveHeader(aExecutionPlan: TRoomerExecutionPlan; currencyChange : Boolean = False);
var
  iMultiplier: integer;
var
  s: string;
  showPackage: boolean;
begin
  showPackage := chkShowPackage.checked;

  iMultiplier := 1;

  // Til �ess a� setja allar t�lur � m�nus
  if FIsCredit then
    iMultiplier := -1;

  s := format('INSERT INTO invoiceaddressees ' +
    '(InvoiceIndex, ' +
    'Reservation, ' +
    'RoomReservation, ' +
    'SplitNumber, ' +
    'InvoiceNumber, ' +
    'Customer, ' +
    'Name, ' +
    'Address1, ' +
    'Address2, ' +
    'Zip, ' +
    'City, ' +
    'Country, ' +
    'ExtraText, ' +
    'custPID, ' +
    'InvoiceType, ' +
    'ihCurrency) ' +
    'VALUES ' +
    '(%d, ' +
    '%d, ' +
    '%d, ' +
    '%d, ' +
    '%d, ' +
    '%s, ' +
    '%s, ' +
    '%s, ' +
    '%s, ' +
    '%s, ' +
    '%s, ' +
    '%s, ' +
    '%s, ' +
    '%s, ' +
    '%d, ' +
    '%s) ',
    [
    InvoiceIndex,
    FReservation,
    FRoomReservation,
    FnewSplitNumber,
    zInvoiceNumber,
    _db(edtCustomer.Text),
    _db(edtName.Text),
    _db(edtAddress1.Text),
    _db(edtAddress2.Text),
    _db(edtAddress3.Text),
    _db(edtAddress4.Text),
    _db(zCountry),
    _db(memExtraText.Lines.Text),
    _db(edtPersonalId.Text),
    rgrInvoiceType.itemIndex,
    _db(edtCurrency.Text)
    ]) +

    format('ON DUPLICATE KEY UPDATE ' +
    'InvoiceNumber=%d, ' +
    'Customer=%s, ' +
    'Name=%s, ' +
    'Address1=%s, ' +
    'Address2=%s, ' +
    'Zip=%s, ' +
    'City=%s, ' +
    'Country=%s, ' +
    'ExtraText=%s, ' +
    'custPID=%s, ' +
    'InvoiceType=%d, ' +
    'ihCurrency=%s',
    [
    zInvoiceNumber,
    _db(edtCustomer.Text),
    _db(edtName.Text),
    _db(edtAddress1.Text),
    _db(edtAddress2.Text),
    _db(edtAddress3.Text),
    _db(edtAddress4.Text),
    _db(zCountry),
    _db(memExtraText.Lines.Text),
    _db(edtPersonalId.Text),
    rgrInvoiceType.itemIndex,
    _db(edtCurrency.Text)
    ]);

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

  s := s + ')' + #10;
  s := s + 'Values' + #10;
  s := s + '(' + #10;
  s := s + '  ' + _db(FReservation);
  s := s + ', ' + _db(FRoomReservation);
  s := s + ', ' + _db(FnewSplitNumber);
  s := s + ', ' + _db(zInvoiceNumber);
  s := s + ', ' + _db(zInvoiceDate, True);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Customer FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' +
    '        AND ia.RoomReservation=%d ' +
    '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' +
    '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation, FnewSplitNumber, InvoiceIndex,
    _db(edtCustomer.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Name FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' +
    '        AND ia.RoomReservation=%d ' +
    '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' +
    '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation, FnewSplitNumber, InvoiceIndex,
    _db(edtName.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT CustPid FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' +
    '        AND ia.RoomReservation=%d ' +
    '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' +
    '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation, FnewSplitNumber, InvoiceIndex,
    _db(edtPersonalId.Text)]);
  s := s + ', ' + _db(edtRoomGuest.Text);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Address1 FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' +
    '        AND ia.RoomReservation=%d ' +
    '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' +
    '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation, FnewSplitNumber, InvoiceIndex,
    _db(edtAddress1.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Address2 FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' +
    '        AND ia.RoomReservation=%d ' +
    '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' +
    '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation, FnewSplitNumber, InvoiceIndex,
    _db(edtAddress2.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Zip FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' +
    '        AND ia.RoomReservation=%d ' +
    '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' +
    '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation, FnewSplitNumber, InvoiceIndex,
    _db(edtAddress3.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT City FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' +
    '        AND ia.RoomReservation=%d ' +
    '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' +
    '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation, FnewSplitNumber, InvoiceIndex,
    _db(edtAddress4.Text)]);
  s := s + ', ' + format('(SELECT IFNULL((SELECT Country FROM invoiceaddressees ia WHERE ia.invoiceNumber=%d ' +
    '        AND ia.Reservation=%d ' +
    '        AND ia.RoomReservation=%d ' +
    '        AND ia.SplitNumber=%d ' +
    '        AND ia.InvoiceIndex=%d ' +
    '       ), %s))', [zInvoiceNumber, FReservation, FRoomReservation, FnewSplitNumber, InvoiceIndex, _db(zCountry)]);
  s := s + ', ' + format('(SELECT %d * sum(total) from invoicelines where invoicenumber=%d and splitnumber=%d and invoiceindex=%d) ',
                          [iMultiplier, zInvoiceNumber, FNewSPlitNumber, InvoiceIndex]) ; //_CommaToDot(floattostr(iMultiplier * FTotal));
  s := s + ', ' + format('(SELECT %d * sum(totalWOVat) from invoicelines where invoicenumber=%d and splitnumber=%d and invoiceindex=%d) ',
                          [iMultiplier, zInvoiceNumber, FNewSPlitNumber, InvoiceIndex]) ; //_CommaToDot(floattostr(iMultiplier * FWOVat));
  s := s + ', ' + format('(SELECT %d * sum(vat) from invoicelines where invoicenumber=%d and splitnumber=%d and invoiceindex=%d) ',
                          [iMultiplier, zInvoiceNumber, FNewSPlitNumber, InvoiceIndex]) ; //_CommaToDot(floattostr(iMultiplier * FVAT));
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
  s := s + ', ' + _db(edtInvRefrence.Text);
  s := s + ', ' + _db(edtCurrency.Text);
  s := s + ', ' + _db(_StrToFloat(edtRate.Text));
  s := s + ', ' + _db(showPackage);
  s := s + ', ' + _db(zLocation);
  s := s + ')' + #10;

  copytoclipboard(s);
  aExecutionPlan.AddExec(s);
end;

function TfrmInvoice.IsLineChanged(line, iMultiplier: integer): boolean;
var
  invoiceLine: TInvoiceLine;
begin
  result := false;
  invoiceLine := CellInvoiceLine(line);
  if Assigned(invoiceLine) then
    result := (invoiceLine.Number <> _StrToFloat(agrLines.Cells[col_ItemCount, line])) OR
      (invoiceLine.Price <> iMultiplier * _StrToFloat(agrLines.Cells[col_ItemPrice, line])) OR
      (invoiceLine.Total <> iMultiplier * _StrToFloat(agrLines.Cells[col_TotalPrice, line])) OR
      (invoiceline.FText <> agrLines.Cells[col_Description, line]);
end;

function TfrmInvoice.SaveInvoice(iInvoiceNumber: integer; currencyChange : Boolean = False): boolean;
var
  rSet: TRoomerDataset;
  ItemTypeInfo: TItemTypeInfo;
  i: integer;

  fWork: Double;
  fVat: Double;

  fItems: Double;
  FTotal: Double;
  fTotalVAT: Double;
  fTotalWOVat: Double;

  fItemTotal: Double;
  fItemTotalVAT: Double;
  fItemTotalWOVat: Double;

  iCreditinvoiceMultiplier: integer;

  iPersons: integer;
  iNights: integer;

  AMon: Word;
  ADay: Word;
  AYear: Word;

  s: string;

  sysline: boolean;

  _CurrencyValueSell: Double;

  sAccountKey: string;
  sItemID: string;

  Refrence: string;
  Source: string;
  isPackage: boolean;
  sTmp: string;

  lExecutionPlan: TRoomerExecutionPlan;
  LineHolder: hData.recInvoiceLineHolder;

  confirmDate: TDateTime;
  confirmAmount: Double;

  ItemCount: Double; // -96

  sRRAlias: string;
  irrAlias: integer;

  aItem: string;
  AutoGen: string;

  ItemPrice: Double;
  lInvRoom: TInvoiceRoomEntity;

  invoiceLine: TInvoiceLine;
  lRevenueCorrection: double;
  lRevenueCorrectionVat: double;
  lDate: TDate;

begin

  _CurrencyValueSell := zCurrencyRate;

  result := True;

  lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    DeleteLinesInList(lExecutionPlan);

    s := '';
    s := s + 'DELETE FROM invoiceheads ' + #10;
    s := s + ' where Reservation = ' + inttostr(FReservation);
    s := s + '   and RoomReservation = ' + inttostr(FRoomReservation);
    s := s + '   and SplitNumber = ' + inttostr(FnewSplitNumber);
    s := s + '   and InvoiceNumber = -1' + #10;
    lExecutionPlan.AddExec(s);

    try
      // --
      iCreditinvoiceMultiplier := 1;

      if FIsCredit then
      begin
        iCreditinvoiceMultiplier := -1;
      end;

      fItems := 0.00;
      FTotal := 0.00;
      fTotalVAT := 0.00;
      fTotalWOVat := 0.00;

      for i := 1 to agrLines.RowCount - 1 do
      begin
        aItem := trim(agrLines.Cells[col_Item, i]);
        // -- is this an empty line ?

        if (trim(agrLines.Cells[col_Description, i]) = '') and (aItem = '') then
          continue;

        // Dont add automatically generated lines when invoice is not definitive
        if (isSystemLine(i)) and (iInvoiceNumber <= 0) {and (aItem <> g.qBreakFastItem)} then
        begin
          continue;
        end;

        iNights := 0;
        iPersons := 0;
        if agrLines.Cells[col_NoGuests, i] <> '' then
        begin
          iPersons := strToInt(agrLines.Cells[col_NoGuests, i])
        end;

        ItemTypeInfo := d.Item_Get_ItemTypeInfo(agrLines.Cells[col_Item, i], agrLines.Cells[col_Source, i]);

        // --
        // RoomRentItem

        if isSystemLine(i) or (ItemKindOnRow(i) in [ikRoomRent, ikRoomRentDiscount]) then
        begin
          // Setja dagsetningu � herbergisleigu
          // Dagsetning er � upphafi 0  31.12.1899
          // en er h�r sett � dagsetningu prentunnar
          agrLines.Cells[col_date, i] := datetostr(trunc(now));
          agrLines.Objects[col_Description, i] := TObject(trunc(now));

          try
            fItemTotal := _CurrencyValueSell * _StrToFloat(agrLines.Cells[col_TotalPrice, i]);
          except
            fItemTotal := 0;
          end;

          if agrLines.Objects[cRoomInfoAttachColumn, i] <> nil then
          begin
            iNights := trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).Departure) -
              trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).Arrival);
          end;

        end
        else
        begin
          try
            fItemTotal := _StrToFloat(agrLines.Cells[col_TotalPrice, i]);
          except
            fItemTotal := 0;
          end;
        end;

        Source := agrLines.Cells[col_Source, i];
        Refrence := agrLines.Cells[col_Refrence, i];

        sTmp := agrLines.Cells[col_confirmdate, i];
        if sTmp <> '' then
        begin
          confirmDate := _DBDateToDateTimeNoMs(sTmp);
        end
        else
          confirmDate := 2;

        confirmAmount := _StrToFloat(agrLines.Cells[col_confirmAmount, i]);

        sTmp := trim(agrLines.Cells[col_isPackage, i]);
        isPackage := (sTmp = 'Yes');

        // --
        lInvRoom := TInvoiceRoomEntity.create(agrLines.Cells[col_Item, i], 1, 0, _StrToFloat(agrLines.Cells[col_ItemCount, i]), fItemTotal, 0, 0, false);
        try
          fVat := GetVATForItem(agrLines.Cells[col_Item, i], fItemTotal,
                  _StrToFloat(agrLines.Cells[col_ItemCount, i]), lInvRoom, tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);
        finally
          lInvRoom.free;
        end;

        if NOT (ItemKindOnRow(i) in [ikRoomRent, ikRoomRentDiscount]) then
          agrLines.Cells[col_Vat, i] := trim(_floattostr(fVat, vWidth, 3));

        fItemTotalVAT := fVat;
        fItemTotalWOVat := fItemTotal - fItemTotalVAT;

        FTotal := FTotal + fItemTotal;
        fTotalVAT := fTotalVAT + fItemTotalVAT;
        fTotalWOVat := fTotalWOVat + fItemTotalWOVat;

        try
          decodedate(integer(agrLines.Objects[col_Description, i]), AYear, AMon, ADay);
        except
          decodedate(now, AYear, AMon, ADay);
        end;

        sTmp := agrLines.Cells[col_ItemCount, i];
        try
          ItemCount := _StrToFloat(sTmp);
        except
          ItemCount := 0;
        end;

        sRRAlias := trim(agrLines.Cells[col_rrAlias, i]);
        irrAlias := -1;
        try
          if sRRAlias <> '' then
            irrAlias := strToInt(sRRAlias);
        Except
        end;

        AutoGen := trim(agrLines.Cells[col_autogen, i]);
        if AutoGen = '' then
        begin
          AutoGen := _GetCurrentTick;
        end;

        sItemID := agrLines.Cells[col_Item, i];
        sAccountKey := d.Item_Get_AccountKey(sItemID);

        invoiceLine := CellInvoiceLine(i);
        if (NOT Assigned(invoiceLine)) OR (invoiceLine.FId < 1) then
        begin

          // SQL 116 INSERxT Invoicelines
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
          s := s + ', ' + 'revenueCorrection ' + #10;
          s := s + ', ' + 'revenueCorrectionVat ' + #10;
          s := s + ')' + #10;
          s := s + 'Values' + #10;
          s := s + '(' + #10;
          s := s + '  ' + inttostr(FReservation);
          s := s + ', ' + _db(AutoGen);
          s := s + ', ' + inttostr(FRoomReservation);
          s := s + ', ' + inttostr(FnewSplitNumber);
          s := s + ', ' + inttostr(i);
          lDate := integer(agrLines.Objects[col_Description, i]);
          s := s + ', ' + _db(lDate);
          s := s + ', ' + inttostr(iInvoiceNumber);
          s := s + ', ' + _db(sItemID);
          s := s + ', ' + _db(ItemCount); // -96ath
          s := s + ', ' + _db(agrLines.Cells[col_Description, i]);

          if isSystemLine(i) or (ItemKindOnRow(i) in [ikRoomRent, ikRoomRentDiscount]) then
            // -- Auto-Maintained lines are displayed in foreign currency...
            s := s + ', ' + _db(iCreditinvoiceMultiplier * _CurrencyValueSell * _StrToFloat(agrLines.Cells[col_ItemPrice, i]))
          else // -- ...The others are not...
            s := s + ', ' + _db(iCreditinvoiceMultiplier * _StrToFloat(agrLines.Cells[col_ItemPrice, i]));
          s := s + ', ' + _db(ItemTypeInfo.VATCode);
          s := s + ', ' + _db(iCreditInvoiceMultiplier * fItemTotal);
          s := s + ', ' + _db(iCreditinvoiceMultiplier * fItemTotalWOVat);
          s := s + ', ' + _db(iCreditinvoiceMultiplier * fItemTotalVAT);
          s := s + ', ' + _db(zCurrencyRate);
          s := s + ', ' + _db(edtCurrency.Text);
          s := s + ', ' + inttostr(iPersons);
          s := s + ', ' + inttostr(iNights);

          lRevenueCorrection := 0.00;
          lRevenueCorrectionVat := 0.00;
          if (ItemKindOnRow(i) = ikRoomRent) and TInvoiceRoomEntity(agrLines.Objects[cRoomInfoAttachColumn, i]).BreakfastIncluded then
          begin
            lRevenueCorrection := iCreditinvoiceMultiplier * -1 * d.Item_Get_Data(g.qBreakFastItem).Price * iPersons * iNights;
            lRevenueCorrectionVat := iCreditinvoiceMultiplier * -1 * TVatCalculator.CalcVATforItem(g.qBreakFastItem) * iPersons * iNights;
          end;

          if isSystemLine(i) and (ItemKindOnRow(i) = ikBreakfast) and TInvoiceRoomEntity(agrLines.Objects[cRoomInfoAttachColumn, i]).BreakfastIncluded then
          begin
            lRevenueCorrection := iCreditinvoiceMultiplier * d.Item_Get_Data(g.qBreakFastItem).Price * ItemCount;
            lRevenueCorrectionVat := iCreditinvoiceMultiplier *  TVatCalculator.CalcVATforItem(g.qBreakFastItem) * ItemCount;
          end;

          s := s + ', ' + _db(0);
          s := s + ', ' + _db(false);

          s := s + ', ' + inttostr(AYear);
          s := s + ', ' + inttostr(AMon);
          s := s + ', ' + inttostr(ADay);

          s := s + ', ' + _db(sAccountKey);
          s := s + ', ' + _db(Refrence);
          s := s + ', ' + _db(Source);
          s := s + ', ' + _db(isPackage);
          s := s + ', ' + _db(confirmDate);
          s := s + ', ' + _db(confirmAmount);
          s := s + ', ' + _db(irrAlias);
          s := s + ', ' + _db(FInvoiceIndex);
          s := s + ', ' + _db(d.roomerMainDataSet.username);
          s := s + ', ' + _db(lRevenueCorrection);
          s := s + ', ' + _db(lRevenueCorrectionVat);

          s := s + ')' + #10;
        end
        else
        begin
          if (NOT currencyChange) AND (NOT IsLineChanged(i, iCreditinvoiceMultiplier)) then
            continue;

          s := 'UPDATE invoicelines' +
            ' Set ItemNumber= ' + _db(i) +
            ' , InvoiceNumber= ' + _db(iInvoiceNumber) +
            ' , Description= ' + _db(agrLines.Cells[col_Description, i]) +
            ' , Number= ' + _db(ItemCount) +
            ' , Price= ' + _CommaToDot(floattostr(iCreditinvoiceMultiplier * _StrToFloat(agrLines.Cells[col_ItemPrice, i]))) +
            ' , Total= ' + _CommaToDot(floattostr(iCreditinvoiceMultiplier * _StrToFloat(agrLines.Cells[col_TotalPrice, i]))) +
            ' , TotalWOVat= ' + _CommaToDot(floattostr(iCreditinvoiceMultiplier * fItemTotalWOVat)) +
            ' , VAT= ' + _CommaToDot(floattostr(iCreditinvoiceMultiplier * fItemTotalVAT)) +
            ' , CurrencyRate= ' + _CommaToDot(floattostr(zCurrencyRate)) +
            ' , Currency= ' + _db(edtCurrency.Text) +
            ' , Persons= ' + inttostr(iPersons) +
            ' , Nights= ' + inttostr(iNights) +
            ' , ilAccountKey= ' + _db(sAccountKey) +
            ' , InvoiceIndex= ' + _db(FInvoiceIndex) +
            ' , staffLastEdit= ' + _db(d.roomerMainDataSet.username) +
            ' WHERE id=' + _db(invoiceLine.FId);
        end;

        lExecutionPlan.AddExec(s);

        copytoclipboard(s);
        // debugmessage(s);

      end;

      SaveHeader(lExecutionPlan, currencyChange);

      if NOT lExecutionPlan.Execute(ptExec, True) then
        raise Exception.create(lExecutionPlan.ExecException);

      zInitString := createAllStr;
      chkChanged;

    except
      on e: Exception do
      begin
        frmdayNotes.xDoLog('SaveInvoice 1000', e.message);
        // MessageDlg('Problem: Unable to save the invoice !' + #13#13 + 'While saving invoice The following Error came up:' + #13#13 +
        // e.message + #13#13 + 'Please write this message down or' + #13 + 'call support with this dialog open!', mtError, [mbOK], 0);
        MessageDlg
          (format(GetTranslatedText
          ('shTx_Invoice_UnableToSaveInvoiceMessage'), [e.message]), mtError,
          [mbOk], 0);
        result := false;
        raise;
      end;
    end;

  finally
    FreeAndNil(lExecutionPlan);
  end;

  if not zApply then
  begin
    if d.mInvoicelines_after.active then
      d.mInvoicelines_after.close;
    d.mInvoicelines_after.Open;

    rSet := CreateNewDataSet;
    try
      Screen.Cursor := crHourglass;
      try
        s := 'SELECT * FROM invoicelines' + ' where Reservation = %d ' +
          '   and RoomReservation = %d ' + '   and SplitNumber = %d ' +
          '   and InvoiceNumber = -1 AND InvoiceIndex=%d';

        s := format(s, [FReservation, FRoomReservation, FnewSplitNumber,
          FInvoiceIndex]);

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
  end;
  zApply := false;
  d.addInvoiceLinesTmp(agrLines.RowCount, FReservation);

  // NO REFRESH  frmMain.RefreshGrid;
end;

function TfrmInvoice.ItemKindOnRow(aRow: Integer): TItemKind;
begin
  Result := Item_GetKind(agrLines.Cells[col_Item, aRow]);
end;

procedure TfrmInvoice.edtCustomerChange(Sender: TObject);
var
  customer: string;

begin
  customer := trim(edtCustomer.Text);
  try
    if NOT glb.LocateSpecificRecordAndGetValue('customers', 'Customer',
      customer, 'StayTaxIncluted', zStayTaxIncluded) then
      zStayTaxIncluded := ctrlGetBoolean('StayTaxIncluted');
  except
    zStayTaxIncluded := ctrlGetBoolean('StayTaxIncluted');
  end;
end;

procedure TfrmInvoice.edtCustomerDblClick(Sender: TObject);
var
  CustomerHolder: recCustomerHolder;
  CustomerHolderEX: recCustomerHolderEX;

  tmp: boolean;
begin

  tmp := zStayTaxIncluded;
  CustomerHolder.customer := edtCustomer.Text;
  if openCustomers(actLookup, True, CustomerHolder) then
  begin
    edtCustomer.Text := CustomerHolder.customer;
    CustomerHolderEX := hData.Customer_GetHolder(CustomerHolder.customer);
    edtName.Text := InvoiceName(0, CustomerHolderEX.DisplayName,
      CustomerHolderEX.CustomerName);
    edtPersonalId.Text := CustomerHolderEX.PID;
    edtAddress1.Text := CustomerHolderEX.Address1;
    edtAddress2.Text := CustomerHolderEX.Address2;
    edtAddress3.Text := CustomerHolderEX.Address3;
    edtAddress4.Text := CustomerHolderEX.Address4;
    zCountry := CustomerHolderEX.Country;
    if zStayTaxIncluded <> tmp then
      calcAndAddAutoItems(FReservation);
  end;
end;

procedure TfrmInvoice.agrLinesGetAlignment(Sender: TObject; ARow, ACol: integer;
  var HAlign: TAlignment; var VAlign: TVAlignment);
begin
  case ACol of
    col_Item:
      HAlign := taLeftJustify; // -96
    col_Description:
      HAlign := taLeftJustify; // -96
    col_ItemCount:
      HAlign := taRightJustify; // -96
    col_ItemPrice:
      HAlign := taRightJustify; // -96
    col_TotalPrice:
      HAlign := taRightJustify; // -96
    col_System:
      HAlign := taLeftJustify; // -96
    col_date:
      HAlign := taLeftJustify; // -96
    col_Refrence:
      HAlign := taLeftJustify; // -96
    col_Source:
      HAlign := taLeftJustify; // -96
    col_isPackage:
      HAlign := taLeftJustify; // -96
    col_NoGuests:
      HAlign := taLeftJustify; // -96
    col_confirmdate:
      HAlign := taLeftJustify; // -96
    col_confirmAmount:
      HAlign := taRightJustify; // -96
  end;
end;

procedure TfrmInvoice.agrLinesGetCellColor(Sender: TObject; ARow, ACol: integer;
  AState: TGridDrawState; ABrush: TBrush; AFont: TFont);
begin
  if ARow = 0 then
  begin
    AFont.Color := frmMain.sSkinManager1.GetGlobalFontColor;
  end
  else if (gdSelected IN AState) OR (gdRowSelected IN AState) then
  begin
    ABrush.Color := frmMain.sSkinManager1.GetActiveEditFontColor;
    AFont.Color := frmMain.sSkinManager1.GetActiveEditColor;
  end
  else
  begin
    ABrush.Color := frmMain.sSkinManager1.GetActiveEditColor;
    AFont.Color := frmMain.sSkinManager1.GetActiveEditFontColor;
  end;
end;

procedure TfrmInvoice.agrLinesGetEditText(Sender: TObject; ACol, ARow: integer;
  var Value: string);
begin
  zCellValue := agrLines.Cells[ACol, ARow];
end;

procedure TfrmInvoice.agrLinesKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_RETURN then
  begin
    if agrLines.row < agrLines.RowCount - 1 then
      agrLines.row := agrLines.row + 1;
  end
end;

procedure TfrmInvoice.itemLookup;
var
  Currency: string;

  theData: TrecItemHolderList;
  rec: TrecItemHolder;

  VATCode, ItemType, Item: string;
  i, iStartRow: integer;
  bAdded: boolean;
begin
  iStartRow := -1;
  Currency := '';
  bAdded := false;
  Item := agrLines.Cells[col_Item, agrLines.row];

  theData := TrecItemHolderList.create(True);
  try
    rec := TrecItemHolder.create;
    rec.recHolder.Item := Item;
    theData.add(rec);
    if openMultipleItems(actLookup, True, theData, [TShowItemOption.HideStockItems {, TShowItemOption.HideSystemItems}]) AND (theData.Count > 0) then
    begin
      if theData[0].recHolder.Item <> Item then // New item
      begin
        for i := 0 to theData.Count - 1 do
        begin

          if glb.LocateSpecificRecordAndGetValue('items', 'Item', theData[i].recHolder.Item, 'Itemtype', ItemType) AND
            glb.LocateSpecificRecordAndGetValue('itemtypes', 'ItemType', ItemType, 'VATCode', VATCode) then
          begin
            if glb.LocateSpecificRecord('vatcodes', 'VATCode', VATCode) then
            begin
              if iStartRow = -1 then
                iStartRow := agrLines.row;


              agrLines.Cells[col_Item, agrLines.row] := theData[i].recHolder.Item;
              agrLines.Cells[col_Description, agrLines.row] := trim(theData[i].recHolder.Description);
              agrLines.Objects[col_Item, agrLines.row] := nil;
              agrLines.Cells[col_ItemCount, agrLines.row] := _floattostr(1, vWidth, vDec);
              agrLines.Cells[col_ItemPrice, agrLines.row] := _floattostr(theData[i].recHolder.Price, vWidth, vDec);
              agrLines.Cells[col_autogen, agrLines.row] := _GetCurrentTick;
              agrLines.Objects[col_Description, agrLines.row] := TObject(trunc(now)); // -- PurchaseDate !
              agrLines.Cells[col_date, agrLines.row] := datetostr(trunc(now));

              CheckroomRentItem(agrLines.row);

              if NOT CheckIfWithdrawlAllowed_X(false, floattostr(theData[i].recHolder.Price)) then
              begin
                agrLines.RemoveRows(agrLines.row, 1);
                AddAndInitNewRow;
                DisplayTotals;
                exit;
              end;

              chkChanged;
              AddAndInitNewRow;
              postMessage(handle, WM_FORMAT_LINE, 0, agrLines.row);
              agrLines.Col := agrLines.Col + 1;
              bAdded := True;
              agrLines.row := agrLines.row + 1;
            end
            else
            begin
              MessageDlg
                (format(GetTranslatedText
                ('shTx_uInvoice_ItemTypeWithIncorrectVAT'), [ItemType, VATCode]
                ), mtError, [mbOk], 0);
            end;
          end
          else
          begin
            MessageDlg
              (format(GetTranslatedText
              ('shTx_uInvoice_ItemWithIncorrectItemType'),
              [theData[i].recHolder.Item, ItemType]), mtError, [mbOk], 0);
          end;
        end;
      end;

      agrLines.Col := col_ItemCount;
    end;
  finally
    theData.free;
  end;
  if iStartRow <> -1 then
  begin
    agrLines.row := iStartRow;
  end
  else
    if bAdded then
    agrLines.row := agrLines.RowCount - 1;
  setControls;
  Application.ProcessMessages;
  agrLines.SetFocus;
end;

procedure TfrmInvoice.agrLinesCanEditCell(Sender: TObject; ARow, ACol: integer;
  var CanEdit: boolean);
begin
  CanEdit := (NOT(ACol IN [col_Item, col_TotalPrice, col_System, col_date,
                          col_Refrence, col_Source, col_isPackage, col_NoGuests, col_confirmdate,
                          col_confirmAmount]))
    AND (TaxTypes.IndexOf(agrLines.Cells[col_Item, ARow]) < 0)
    AND not (isSystemLine(aRow) and (agrLines.Cells[col_Item, ARow] = g.qBreakFastItem))
    AND ((glb.GetNumberBaseOfItem(agrLines.Cells[col_Item, ARow]) = INB_USER_EDIT) OR
        (ACol IN [col_ItemPrice, col_Description]));

end;

function TfrmInvoice.CheckIfWithdrawlAllowed_X(Editing: boolean;
  Value: String): boolean;
var
  currValue: Double;
  Amount: Double;
begin
  result := True;
  if FIsCredit then
    exit;

  Amount := GridFloatValueFromString(Value);

  if Editing then
  begin
    DisplayTotals(agrLines.Col, agrLines.row, Amount)
  end
  else
  begin
    DisplayTotals(col_ItemPrice, agrLines.row, Amount);
  end;

  currValue := GridFloatValueFromString(edtBalance.Text);

  if (FRoomReservation > 0) AND
    (NOT d.roomerMainDataSet.SystemIsRoomWithdrawalAllowed(FRoomReservation,
    currValue - OriginalInvoiceStatus)) then
  begin
    MessageDlg(GetTranslatedText('shUI_AmountOverAllowedWithdrawalLimit'),
      mtWarning, [mbOk], 0);
    result := false;
  end;
end;

procedure TfrmInvoice.FormatCurrentLine(ARow: integer);
begin
  agrLines.BeginUpdate;
  try
    agrLines.Cells[col_ItemPrice, ARow] :=
      _floattostr(GridCellfloatValue(agrLines, col_ItemPrice, ARow),
      vWidth, vDec);
    agrLines.Cells[col_ItemCount, ARow] :=
      _floattostr(GridCellfloatValue(agrLines, col_ItemCount, ARow), vWidth,
      vDec); // -96
    agrLines.Cells[col_TotalPrice, ARow] :=
      _floattostr(GridCellfloatValue(agrLines, col_ItemPrice, ARow) *
      GridCellfloatValue(agrLines, col_ItemCount, ARow), vWidth, vDec); // -96
  finally
    agrLines.EndUpdate;
  end;
end;

procedure TfrmInvoice.WndProc(var message: TMessage);
begin
  if Message.msg = WM_FORMAT_LINE then
  begin
    FormatCurrentLine(Message.LParam);
    DisplayTotals;
  end;
  inherited WndProc(message);
end;

procedure TfrmInvoice.agrLinesCellValidate(Sender: TObject; ACol, ARow: integer;
  var Value: string; var Valid: boolean);
var
  sItemName: string;
  dItemPrice: Double;

  sTmp: string;
  iTmp: integer;
begin
  Valid := True;
  agrLines.BeginUpdate;
  try
    case ACol of
      - 1:
        ; // Do nothing...
      col_Item:
        begin
          chkChanged;

          begin
            if agrLines.Cells[col_Item, ARow] = trim(g.qPaymentItem) then
            begin
              // MessageDlg('You are not allowed to use the System''s Payment code directly', mtError, [mbOK], 0);
              MessageDlg(GetTranslatedText('shTx_Invoice_NotAllowed'), mtError,
                [mbOk], 0);
              Valid := false;
              exit;
            end;

            iTmp := ARow;
            sTmp := agrLines.Cells[col_Item, ARow];
            sItemName := Item_GetDescription(sTmp);
            sItemName := trim(sItemName);
            dItemPrice := Item_GetPrice(agrLines.Cells[col_Item, ARow]);
            agrLines.Cells[col_ItemPrice, ARow] :=
              _floattostr(dItemPrice, vWidth, vDec);

            if NOT CheckIfWithdrawlAllowed_X(false, floattostr(dItemPrice)) then
            begin
              Valid := false;
              exit;
            end;

            if sItemName = '' then
            begin
              agrLines.Cells[col_Item, iTmp] := zCellValue;
              agrLines.Col := 0;
              agrLines.row := iTmp;
              exit;
            end;

            if GridCellfloatValue(agrLines, col_ItemCount, ARow) = 0 then
              agrLines.Cells[col_ItemCount, ARow] := _floattostr(1, vWidth, vDec);
            // -96

            agrLines.Cells[col_Description, agrLines.row] := sItemName;
            agrLines.Cells[agrLines.Col + 5, ARow] := '';
            CheckRoomRentItem(ARow);
            agrLines.row := ARow - 1;
            agrLines.Col := 2;
            AddEmptyLine;
            postMessage(handle, WM_FORMAT_LINE, 0, agrLines.row);
          end;
        end;
      col_Description:
        begin
          chkChanged;
        end;

      col_ItemCount:
        begin
          if agrLines.Cells[col_Item, ARow] = '' then
          begin
            agrLines.Cells[col_ItemCount, ARow] := '';
            agrLines.Cells[col_ItemPrice, ARow] := '';
            agrLines.Cells[col_TotalPrice, ARow] := '';
            agrLines.Cells[col_System, ARow] := '';
          end
          else
          begin
            chkChanged;

            if NOT CheckIfWithdrawlAllowed_X(True, Value) then
            begin
              Valid := false;
              exit;
            end;

            agrLines.Cells[col_System, ARow] := '';
            postMessage(handle, WM_FORMAT_LINE, 0, agrLines.row);
          end;
        end;
      col_ItemPrice:
        begin
          if agrLines.Cells[col_Item, ARow] = '' then
          begin
            agrLines.Cells[col_ItemCount, ARow] := '';
            agrLines.Cells[col_ItemPrice, ARow] := '';
            agrLines.Cells[col_TotalPrice, ARow] := '';
            agrLines.Cells[col_System, ARow] := '';
          end
          else
          begin
            chkChanged;

            if NOT CheckIfWithdrawlAllowed_X(True, Value) then
            begin
              Valid := false;
              exit;
            end;

            agrLines.Cells[col_System, ARow] := '';
            postMessage(handle, WM_FORMAT_LINE, 0, agrLines.row);
          end;
        end;
    end;
    if ACol in [col_Item, col_ItemCount, col_ItemPrice] then
    begin
      calcAndAddAutoItems(FReservation); // 003
    end;
  finally
    agrLines.EndUpdate;
  end;
end;

procedure TfrmInvoice.agrLinesCheckBoxClick(Sender: TObject; ACol, ARow: integer; State: boolean);
var
  check: boolean;
begin
  if ARow = 0 then
  begin
    agrLines.GetCheckBoxState(col_Select, ARow, check);
    CheckOrUncheckAll(check);
  end;

  agrLinesRowChanging(agrLines, agrLines.row, agrLines.row, check);
end;

function TfrmInvoice.GetAnyRowChecked: boolean;
var
  i: integer;
begin
  result := false;
  for i := 1 to agrLines.RowCount - 1 do
    if agrLines.HasCheckBox(col_Select, i) then
    begin
      agrLines.GetCheckBoxState(col_Select, i, result);
      if result then
        break;
    end;
end;

procedure TfrmInvoice.agrLinesColumnSize(Sender: TObject; ACol: integer;
  var Allow: boolean);
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
end;

procedure TfrmInvoice.agrLinesDblClickCell(Sender: TObject;
  ARow, ACol: integer);
begin
  if ACol <> col_Item then
    exit;
  if agrLines.Cells[ACol, ARow] <> '' then
    exit;
  itemLookup;
end;

function TfrmInvoice.GatherPayments(PayLines: TStringList;
  var days: integer): Double;
var
  tt: Double;
  i: integer;
  pmCode: string;
  pmAmount: Double;
  sTmp: string;
  iTmp: integer;

begin
  tt := 0;
  days := 0;
  iTmp := 0;

  for i := 0 to PayLines.Count - 1 do
  begin
    pmCode := trim(_strTokenAt(PayLines[i], '|', 0));
    sTmp := trim(_strTokenAt(PayLines[i], '|', 1));

    try
      { TODO -oHordur -cOther : Afhverju er �etta kommenta� �t }
      // ATHOLD payTypes      iTmp := d.GET_PaytypeDays_byPaytype(pmCode);
      if iTmp > days then
        days := iTmp;
    except
    end;

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

function TfrmInvoice.PayInvoiceAndPrint: boolean;
var
  ItemTypeInfo: TItemTypeInfo;

  mResult: TModalResult;
  TotalPayments: Double;
  iTmp: integer;
  okSavePayment: boolean;
  okSaveInvoice: boolean;
  pmStr: string;
  days: integer;

  NumOk: boolean;

  isNewInvoice: boolean;

  AllOk: boolean;

  s: string;
  i: integer;

  _CurrencyValueSell: Double;

  iMultiplier: integer;

  iPersons: integer;
  iNights: integer;

  AMon: Word;
  ADay: Word;
  AYear: Word;

  fItems: Double;
  FTotal: Double;
  fTotalVAT: Double;
  fTotalWOVat: Double;

  sItemID: string;
  sAccountKey: string;
  sDescription: string;

  sRefrence: string;
  sSource: string;

  ct: string;
  sTmp, sTmp2: string;

  PaymentDescription: string;
  PaymentType: TPaymentTypes;

  dTmp: Double;

  sLinePrice: string;
  dLinePrice: Double;

  sLineTotal: string;
  dLineTotal: Double;

  sLineVAT: String;
  dLineVAT: Double;

  sLineTotalWOVat: String;
  dLineTotalWOVat: Double;

  dTotalStayTax: Double;
  iTotalStayTaxNights: integer;

  isConnected: boolean;
  isPackage: boolean;

  RoomRentPaid: boolean;
  invRoomReservation: integer;

  doRestore: boolean;

  lExecutionPlan: TRoomerExecutionPlan;

  confirmDate: TDateTime;
  confirmAmount: Double;

  ItemCount: Double; // -96

//  remoteResult: String;

  theData: recPaymentHolder;

  dNumItems: Double;
  sRRAlias: string;
  irrAlias: integer;

  lstLocations: TStringList;
  lstActivity: TStringList;

  paymentValue: Double;
  paymentCode: string;
  paymentStr: string;

  lInvRoom: TInvoiceRoomEntity;

  invoiceLine: TInvoiceLine;
  lRevenueCorrection: double;
  lRevenueCorrectionVat: double;
  lDate: TDate;

Label
  TryAgain;
begin
  result := false;
  iTmp := zInvoiceNumber;
  isNewInvoice := iTmp = -1;

  days := 0;
  // --
  fItems := 0.00;
  FTotal := 0.00;
  fTotalVAT := 0.00;
  fTotalWOVat := 0.00;

  AllOk := True;

  zInvoiceDate := trunc(now);
  zPayDate := zInvoiceDate;
  zConfirmDate := 2;

  lstActivity := TStringList.create;
  lstLocations := TStringList.create;
  try

    if FRoomReservation = 0 then
    begin
      d.GetReservationLocations(FReservation, lstLocations);
    end
    else
    begin
      d.GetRoomReservationLocations(FRoomReservation, lstLocations);
    end;

    if agrLines.Cells[col_Item, 1] = '' then
      raise Exception.create('No items on invoice');

    if (zInvoiceNumber = -1) or (FnewSplitNumber = 1) then
    begin
      if not SelectPaymentTypes(_StrToFloat(edtBalance.Text), edtCustomer.Text,
        ptInvoice, edtCurrency.Text, _StrToFloat(edtRate.Text), FReservation,
        lstLocations, zInvoiceDate, zPayDate, zLocation) then
      begin
        exit;
      end;
      TotalPayments := GatherPayments(stlPaySelections, days);

      if round(TotalPayments) <> round(_StrToFloat(edtBalance.Text)) then
      begin
        // raise Exception.create('Payment need to total to the same amount as the total invoice');
        raise Exception.create
          (GetTranslatedText('shTx_Invoice_PaymentTotalInvoice'));
      end;

      zInvoiceNumber := IVH_SetNewID();

      if (zInvoiceNumber < 0) or (zInvoiceNumber > cMaxFinalInvoiceNr) then
        raise Exception.CreateFmt(GetTranslatedText('shTx_Invoice_invalidInvoiceNr'), [zInvoiceNumber]);

      okSavePayment := false;
      okSaveInvoice := false;
      AllOk := True;


      // **************************************************************************
      // Save invoice starts
      // **************************************************************************

      lExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
      lExecutionPlan.BeginTransaction;
      try
        _CurrencyValueSell := zCurrencyRate;

        AddDeleteFromInvoiceToExecutionPlan(lExecutionPlan);

        iMultiplier := 1; // til �ess a� setja � m�nus ef Kredit
        if FIsCredit then
        begin
          iMultiplier := -1;
        end;

        dTotalStayTax := 0.00;
        iTotalStayTaxNights := 0;

        try
          dTotalStayTax := _StrToFloat(labLodgingTaxISK.caption);
          dTotalStayTax := iMultiplier * dTotalStayTax;
        Except
        end;

        try
          iTotalStayTaxNights := strToInt(labLodgingTaxNights.caption);
          // ATH double value
          iTotalStayTaxNights := iMultiplier * iTotalStayTaxNights;
          if iTotalStayTaxNights <> 0 then
            labTaxNights.caption := 'Nights.';
        Except
        end;

        RoomRentPaid := false;

        for i := 1 to agrLines.RowCount - 1 do
        begin
          // -- is this an empty line ?
          sItemID := trim(agrLines.Cells[col_Item, i]);
          sDescription := trim(agrLines.Cells[col_Description, i]);
          sSource := trim(agrLines.Cells[col_Source, i]);
          sRefrence := trim(agrLines.Cells[col_Refrence, i]);

          sTmp := agrLines.Cells[col_confirmdate, i];
          if sTmp <> '' then
          begin
            confirmDate := _DBDateToDateTimeNoMs(sTmp);
          end
          else
            confirmDate := 2;

          confirmAmount := _StrToFloat(agrLines.Cells[col_confirmAmount, i]);

          isPackage := false;
          try
            sTmp2 := trim(agrLines.Cells[col_isPackage, i]);
            if sTmp2 = 'Yes' then
              isPackage := True;
          except
            // not raise
          end;

          // ef t�mt
          if (trim(sItemID) = '') and (sDescription = '') then
            continue;

          iNights := 0;
          iPersons := 0;

          if agrLines.Cells[col_NoGuests, i] <> '' then
          begin
            iPersons := strToInt(agrLines.Cells[col_NoGuests, i])
          end;

          ItemTypeInfo := d.Item_Get_ItemTypeInfo(sItemID, sSource);
          agrLines.Cells[col_date, i] := datetostr(trunc(now));
          agrLines.Objects[col_Description, i] := TObject(trunc(now));

          // RoomRentItem
          invRoomReservation := -1;
          if _trimlower(sItemID) = _trimlower(g.qRoomRentItem) then
          begin
            if agrLines.Objects[cRoomInfoAttachColumn, i] <> nil then
            begin
              invRoomReservation := TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).RoomReservation;
              iNights := trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).Departure) -
                trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).Arrival);
            end;
          end;

          // ver� � v�ru � v�rul�nu
          sLinePrice := agrLines.Cells[col_ItemPrice, i];
          dLinePrice := _StrToFloat(sLinePrice);

          // Heildaver� v�rul�nu
          sLineTotal := agrLines.Cells[col_TotalPrice, i];
          dLineTotal := _StrToFloat(sLineTotal);

          // Reikna VSK
          dNumItems := _StrToFloat(agrLines.Cells[col_ItemCount, i]);
          if (LowerCase(trim(g.qRoomRentItem))
            = LowerCase(agrLines.Cells[col_Item, i])) OR
            (LowerCase(trim(g.qDiscountItem))
            = LowerCase(agrLines.Cells[col_Item, i])) then
            dNumItems := 1.00;

          lInvRoom := TInvoiceRoomEntity.create(agrLines.Cells[col_Item, i], 1, 0,
            _StrToFloat(agrLines.Cells[col_ItemCount, i]), dLineTotal, 0, 0, false);
          try
            dLineVAT := GetVATForItem(agrLines.Cells[col_Item, i], dLineTotal, dNumItems, lInvRoom, tempInvoiceItemList, ItemTypeInfo,
              edtCustomer.Text); // BHG
          finally
            lInvRoom.free;
          end;

          if NOT(ItemKindOnRow(i) IN [ikRoomRent, ikRoomRentDiscount]) then
            agrLines.Cells[col_Vat, i] := trim(_floattostr(dLineVAT, vWidth, 3));


          // og �n VSK
          dLineTotalWOVat := dLineTotal - dLineVAT;

          // Ef kredit
          dLinePrice := {iMultiplier *} dLinePrice;
          dLineTotal := iMultiplier * dLineTotal;
          dLineVAT := iMultiplier * dLineVAT;
          dLineTotalWOVat := iMultiplier * dLineTotalWOVat;

          try
            ItemCount :=  iMultiplier * _StrToFloat(agrLines.Cells[col_ItemCount, i]); // -96
          Except
            ItemCount := 0;
          end;

          lRevenueCorrection := 0.0;
          lRevenueCorrectionVat := 0.0;

          // roomrent, ctax and roomrentdiscount
          if Item_isRoomRent(sItemID) then
          begin
            dLinePrice := _CurrencyValueSell * dLinePrice;
            dLineTotal := _CurrencyValueSell * dLineTotal;
            dLineVAT := _CurrencyValueSell * dLineVAT;
            dLineTotalWOVat := _CurrencyValueSell * dLineTotalWOVat;
            RoomRentPaid := True;
          end;

          if isSystemLine(i) and (ItemKindOnRow(i) = ikRoomRent) then
            if TInvoiceRoomEntity(agrLines.Objects[cRoomInfoAttachColumn, i]).BreakfastIncluded then
            begin
              lRevenueCorrection := -1 * d.Item_Get_Data(g.qBreakFastItem).Price * iPersons * iNights;
              lRevenueCorrectionVat := -1 * TVatCalculator.CalcVATforItem(g.qBreakFastItem) * iPersons * iNights;
            end;

          if isSystemLine(i) and (ItemKindOnRow(i) = ikBreakfast) then
          begin
            // Is Systemline so must be an included breakfast
            lRevenueCorrection := d.Item_Get_Data(g.qBreakFastItem).Price * ItemCount;
            lRevenueCorrectionVat := TVatCalculator.CalcVATforItem(g.qBreakFastItem) * ItemCount;
          end;

          // og aftur � texta
          sLinePrice := _CommaToDot(floattostr(dLinePrice));
          sLineTotal := _CommaToDot(floattostr(dLineTotal));
          sLineVAT := _CommaToDot(floattostr(dLineVAT));
          sLineTotalWOVat := _CommaToDot(floattostr(dLineTotalWOVat));

          // Samtals � reikning � ISK
          FTotal := FTotal + dLineTotal;
          fTotalVAT := fTotalVAT + dLineVAT;
          fTotalWOVat := fTotalWOVat + dLineTotalWOVat;

          sRRAlias := trim(agrLines.Cells[col_rrAlias, i]);

          irrAlias := -1;
          try
            if sRRAlias <> '' then
              irrAlias := strToInt(sRRAlias);
          Except
          end;

          try
            decodedate(integer(agrLines.Objects[col_Description, i]), AYear, AMon, ADay);
          except
            decodedate(now, AYear, AMon, ADay);
          end;

          sAccountKey := d.Item_Get_AccountKey(sItemID);

          invoiceLine := CellInvoiceLine(i);
          if (NOT Assigned(invoiceLine)) OR (invoiceLine.FId < 1) then
          begin
            // SQL 116 INSERxT Invoicelines
            s := '' + #10;
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
            s := s + ', ' + 'confirmDate ' + #10;
            s := s + ', ' + 'confirmAmount ' + #10;
            s := s + ', ' + 'IsPackage ' + #10;
            s := s + ', ' + 'RoomReservationAlias ' + #10;
            s := s + ', ' + 'InvoiceIndex ' + #10;
            s := s + ', ' + 'staffCreated ' + #10;
            s := s + ', ' + 'revenueCorrection' + #10;
            s := s + ', ' + 'revenueCorrectionVat' + #10;
            s := s + ')' + #10;
            s := s + 'Values' + #10;
            s := s + '(' + #10;
            s := s + '  ' + _db(FReservation); // Reservation
            s := s + ', ' + _db(_GetCurrentTick); // AutoGen
            s := s + ', ' + _db(FRoomReservation); // RoomReservation
            s := s + ', ' + _db(FnewSplitNumber); // SPlitNumber
            s := s + ', ' + _db(i); // ItemNumber

            lDate := integer(agrLines.Objects[col_Description, i]);
            s := s + ', ' + _db(lDate);
            s := s + ', ' + inttostr(zInvoiceNumber); // InvoiceNumber
            s := s + ', ' + _db(sItemID); // ItemID
            s := s + ', ' + _db(ItemCount);
            s := s + ', ' + _db(sDescription);
            s := s + ', ' + sLinePrice;
            s := s + ', ' + _db(ItemTypeInfo.VATCode);
            s := s + ', ' + sLineTotal;
            s := s + ', ' + sLineTotalWOVat;
            s := s + ', ' + sLineVAT;
            s := s + ', ' + _CommaToDot(floattostr(zCurrencyRate));
            s := s + ', ' + _db(edtCurrency.Text);
            s := s + ', ' + inttostr(iPersons);
            s := s + ', ' + inttostr(iNights);
            s := s + ', ' + _CommaToDot(floattostr(0.00));
            s := s + ', ' + _db(false);

            s := s + ', ' + inttostr(AYear);
            s := s + ', ' + inttostr(AMon);
            s := s + ', ' + inttostr(ADay);

            s := s + ', ' + _db(sAccountKey);
            s := s + ', ' + _db(sRefrence);
            s := s + ', ' + _db(sSource);
            s := s + ', ' + _db(confirmDate);
            s := s + ', ' + _db(confirmAmount);
            s := s + ', ' + _db(isPackage);
            s := s + ', ' + _db(irrAlias);
            s := s + ', ' + _db(FInvoiceIndex);
            s := s + ', ' + _db(d.roomerMainDataSet.username);
            s := s + ', ' + _db(lRevenueCorrection);
            s := s + ', ' + _db(lRevenueCorrectionVat);

            s := s + ')' + #10;
          end
          else
          begin
            s := 'UPDATE invoicelines' +
              ' Set ItemNumber= ' + _db(i) +
              ' , InvoiceNumber= ' + _db(zInvoiceNumber) +
              ' , Number= ' + _db(ItemCount) +
              ' , Price= ' + sLinePrice +
              ' , Total= ' + sLineTotal +
              ' , TotalWOVat= ' + sLineTotalWOVat +
              ' , VAT= ' + sLineVAT +
              ' , CurrencyRate= ' + _CommaToDot(floattostr(zCurrencyRate)) +
              ' , Currency= ' + _db(edtCurrency.Text) +
              ' , Persons= ' + inttostr(iPersons) +
              ' , Nights= ' + inttostr(iNights) +
              ' , ilAccountKey= ' + _db(sAccountKey) +
              ' , InvoiceIndex= ' + _db(FInvoiceIndex) +
              ' , staffLastEdit= ' + _db(d.roomerMainDataSet.username) +
              ' WHERE id=' + _db(invoiceLine.FId);
          end;

          // copytoclipboard(s);
          lExecutionPlan.AddExec(s);

          lstActivity.add(CreateInvoiceActivityLog(g.qUser, FReservation,
            FRoomReservation, FnewSplitNumber, ADD_LINE, sItemID, dLineTotal,
            zInvoiceNumber, sDescription));

          if RoomRentPaid then
            if invRoomReservation > 0 then
            begin
              // **
              s := '';
              s := s + 'UPDATE roomreservations ' + #10;
              s := s + 'SET' + #10;
              s := s + '   RoomRentPaid1 = ' + _db(dLineTotal) + ' '#10;
              s := s + '  ,RoomRentPaymentInvoice = ' +
                _db(zInvoiceNumber) + #10;
              s := s + 'WHERE RoomReservation = ' +
                _db(invRoomReservation) + #10;
              lExecutionPlan.AddExec(s);

              // update isPaid ef groupInvoice

              s := '';
              s := s + ' UPDATE `roomsdate` '#10;
              s := s + '  SET '#10;
              s := s + '    Paid = 1 '#10;
              s := s + '  , invoicenumber=' + _db(zInvoiceNumber) + ' '#10;
              s := s + ' WHERE '#10;
              s := s + ' (Roomreservation = ' + inttostr(invRoomReservation)
                + ') '#10;;
              s := s + ' AND (Paid = 0) '#10;
              s := s + '   AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '#10;
              // **zxhj b�tti vi�
              s := s + ' ORDER BY adate '#10; // **ssshj b�tti vi�
              s := s + ' LIMIT ' + _db(ItemCount) + ' '#10; // **ssshj b�tti vi�

              // copyToClipboard(s);
              lExecutionPlan.AddExec(s);
            end;
        end;


        // SaveHeader(fTotal, fTotalVat, fTotalWOVat );
        s := '' + #10;
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
        s := s + ', TotalStayTax ' + #10;
        s := s + ', TotalStayTaxNights ' + #10;
        s := s + ', ihCurrency ' + #10; // **98
        s := s + ', ihCurrencyrate ' + #10; // **98
        s := s + ', showPackage ' + #10; // **98
        s := s + ', Location ' + #10; // **98
        s := s + ', staff ' + #10; // **98

        s := s + ')' + #10;

        s := s + 'Values' + #10;
        s := s + '(' + #10;
        s := s + '  ' + inttostr(FReservation);
        s := s + ', ' + inttostr(FRoomReservation);
        s := s + ', ' + inttostr(FnewSplitNumber);

        s := s + ', ' + inttostr(zInvoiceNumber);

        s := s + ', ' + _db(zInvoiceDate, True);

        s := s + ', ' + _db(edtCustomer.Text);
        s := s + ', ' + _db(edtName.Text);
        s := s + ', ' + _db(edtPersonalId.Text);
        s := s + ', ' + _db(edtRoomGuest.Text);

        s := s + ', ' + _db(edtAddress1.Text);
        s := s + ', ' + _db(edtAddress2.Text);
        s := s + ', ' + _db(edtAddress3.Text);
        s := s + ', ' + _db(edtAddress4.Text);

        s := s + ', ' + _db(zCountry);

        s := s + ', ' + format('(SELECT %d * sum(total) from invoicelines where invoicenumber=%d and splitnumber=%d and invoiceindex=%d) ',
                                [iMultiplier, zInvoiceNumber, FNewSPlitNumber, InvoiceIndex]) ; //_CommaToDot(floattostr(iMultiplier * FTotal));
        s := s + ', ' + format('(SELECT %d * sum(totalWOVat) from invoicelines where invoicenumber=%d and splitnumber=%d and invoiceindex=%d) ',
                                [iMultiplier, zInvoiceNumber, FNewSPlitNumber, InvoiceIndex]) ; //_CommaToDot(floattostr(iMultiplier * FWOVat));
        s := s + ', ' + format('(SELECT %d * sum(vat) from invoicelines where invoicenumber=%d and splitnumber=%d and invoiceindex=%d) ',
                                [iMultiplier, zInvoiceNumber, FNewSPlitNumber, InvoiceIndex]) ; //_CommaToDot(floattostr(iMultiplier * FVAT));
        s := s + ', ' + _CommaToDot(floattostr(0.00));
        s := s + ', ' + _db(memExtraText.Lines.Text);
        s := s + ', ' + inttostr(zOriginalInvoice);
        s := s + ', ' + _db(false);
        s := s + ', ' + inttostr(rgrInvoiceType.itemIndex);
        s := s + ', ' + _db(g.qUser);
        s := s + ', ' + _db(Date, True);
        s := s + ', ' + _db(zInvoiceDate, True);
        s := s + ', ' + _db(zConfirmDate, True);
        s := s + ', ' + _db(zPayDate, True);
        s := s + ', ' + _db(edtInvRefrence.Text);

        s := s + ', ' + _CommaToDot(floattostr(dTotalStayTax));
        s := s + ', ' + inttostr(iTotalStayTaxNights);
        s := s + ', ' + _db(edtCurrency.Text);
        s := s + ', ' + _db(_StrToFloat(edtRate.Text));
        s := s + ', ' + _db(chkShowPackage.checked);
        s := s + ', ' + _db(zLocation);
        s := s + ', ' + _db(d.roomerMainDataSet.username);

        s := s + ')' + #10;

        // copytoclipboard(s);

        lExecutionPlan.AddExec(s);




        // ***************************
        //
        // INSERxT PAYMENTS
        //
        // ***************************

        // PaymentDescription := 'Payment Invoice ' + inttostr(zInvoiceNumber);
        PaymentType := ptInvoice;
        pmStr := '';

        for i := 0 to stlPaySelections.Count - 1 do
        begin
          PaymentDescription := _strTokenAt(stlPaySelections[i], '|', 2);
          decodedate(zInvoiceDate, AYear, AMon, ADay);
          // SQL 117 INSERxT Payments
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

          s := s + ', ' + _db(sSelectedCustomer);

          ct := _GetCurrentTick;
          s := s + ', ' + _db(ct);

          s := s + ', ' + inttostr(zInvoiceNumber);
          s := s + ', ' + _db(zInvoiceDate, True);
          sTmp := _strTokenAt(stlPaySelections[i], '|', 0);
          s := s + ', ' + _db(_strTokenAt(stlPaySelections[i], '|', 0));
          s := s + ', ' + _CommaToDot
            (trim(floattostr(iMultiplier *
            _StrToFloat(_strTokenAt(stlPaySelections[i], '|', 1)))));
          s := s + ', ' + _db(PaymentDescription + ' [' +
            _strTokenAt(stlPaySelections[i], '|', 0) + ']');
          s := s + ', ' + _CommaToDot(floattostr(zCurrencyRate));
          s := s + ', ' + _db(edtCurrency.Text);
          if PaymentType = ptInvoice then
            s := s + ', 0'
          else if PaymentType = ptDownPayment then
            s := s + ', 1';
          s := s + ', ' + inttostr(AYear);
          s := s + ', ' + inttostr(AMon);
          s := s + ', ' + inttostr(ADay);
          s := s + ', ' + _db(d.roomerMainDataSet.username);
          s := s + ', ' + _db(FInvoiceIndex);
          s := s + ')';

          lExecutionPlan.AddExec(s);

          paymentValue := iMultiplier * _StrToFloat(_strTokenAt(stlPaySelections[i], '|', 1));
          paymentCode := _strTokenAt(stlPaySelections[i], '|', 0);
          paymentStr := PaymentDescription + ' [' + _strTokenAt(stlPaySelections[i], '|', 0) + ']';

          lstActivity.add(CreateInvoiceActivityLog(g.qUser, FReservation,
            FRoomReservation, FnewSplitNumber, ADD_PAYMENT, paymentCode,
            paymentValue, zInvoiceNumber, paymentStr));

          AllOk := True;
        end;

        s := '';
        s := s + ' UPDATE `payments` '#10;
        s := s + '  SET '#10;
        s := s + ' `invoicenumber` = ' + _db(zInvoiceNumber) + ' '#10;
        s := s + ' WHERE (`reservation` = %d) and (`Roomreservation` = %d) and (Invoicenumber=-1) and (InvoiceIndex=%d) and (typeindex=1); ';
        s := format(s, [FReservation, FRoomReservation, FInvoiceIndex]);
        lExecutionPlan.AddExec(s);

        if lExecutionPlan.Execute(ptExec, false, false) then
        begin
          lExecutionPlan.CommitTransaction;
          // NO REFRESH        frmMain.btnRefresh.Click;
        end
        else
          raise Exception.create(lExecutionPlan.ExecException);

        result := True;

      except
        on e: Exception do
        begin
          zErr := True;
          frmdayNotes.xDoLog(GetTranslatedText('shTx_Invoice_CreatingInvoice'),
            e.message);
          lExecutionPlan.RollbackTransaction;
          if MessageDlg( GetTranslatedText('shTx_InvoiceUnableToSave'), mtError, [mbRetry, mbCancel], 0) = mrCancel then
            close;

          IVH_RestoreID();
          exit;
          // raise;
        end;
      end;

      //TODO: Move to finally section as this is not executed when Exit on line 5892 is reached
      FreeAndNil(lExecutionPlan);

      if AllOk then
      begin
        if (FIsCredit and (zCreditType = ctReference)) then
        begin
          MarkOriginalInvoiceAsCredited(zInvoiceNumber);
        end
      end;
    end;

    if AllOk then
    begin
      if NOT FIsCredit then
      begin
        if d.addInvoiceLinesTmp(1, FReservation) then
        begin
          d.qRes := FReservation;
          d.qRRes := FRoomReservation;
        end;
      end;

      doRestore := false;
      if (FIsCredit and (zCreditType = ctReference)) and
      // (MessageDlg('Open a new invoice with the original amounts'+#10+'when finished printing credit invoice ?', mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
        (MessageDlg(GetTranslatedText
        ('shTx_Invoice_OpenInvoiceAfterPrintCredit'), mtConfirmation,
        [mbYes, mbNo], 0) = mrYes) then
      begin
        d.copyInvoiceToInvoiceLinesTmp(zRefNum, True);
        doRestore := True;
      end;

      zDoSave := false;
      SaveAnd(false);                           //????????????
      try
        result := True;
        try
          SendInvoicesToFinancePacketThreaded(zInvoiceNumber);
//          remoteResult := d.roomerMainDataSet.SystemSendInvoiceToBookkeeping(zInvoiceNumber);
          ViewInvoice2(zInvoiceNumber, True, false, True, chkShowPackage.checked, zEmailAddress);

          d.roomerMainDataSet.SystempackagesCreateHeaderIfNotExists
            (FRoomReservation, FRoomReservation);

        finally
            lstActivity.add(CreateInvoiceActivityLog(g.qUser, FReservation,
              FRoomReservation, FnewSplitNumber, PAY_AND_PRINT,
              inttostr(zInvoiceNumber), FTotal, 0, 'Invoice added '));

          for i := 0 to lstActivity.Count - 1 do
          begin
            if lstActivity[i] <> '' then
              WriteInvoiceActivityLog(lstActivity[i]);
          end;
        end;

      except
        on e: Exception do
        begin
          ShowMessage('Ekki t�kst ad senda reikning No. ' +
            inttostr(zInvoiceNumber) +
            ' til b�khaldskerfisins. Vinsamlega sendi� reikninginn handvirkt s��ar ');
          AddRoomerActivityLog(d.roomerMainDataSet.username, ERROR, e.message,
            format('Exception while sending invoice to booking keeping. Invoice %d, RoomReservation %d, Reservation %d -> %s',
            [zInvoiceNumber, FRoomReservation, FReservation, e.message]));
        end;
      end;
    end
    else
    begin
      IVH_RestoreID();
      zDoSave := false;
      SaveAnd(false);
      result := True;
    end;
  finally
    FreeAndNil(lstLocations);
    FreeAndNil(lstActivity);
  end;
end;

// -- The original Invoice contains a special field which links it to the
// subceeding credit invoice. This is for traceback puurposes.
procedure TfrmInvoice.MarkOriginalInvoiceAsCredited(iInvoice: integer);
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

procedure TfrmInvoice.MoveRoomToGroupInvoice;
begin
  if FRoomReservation = 0 then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_GroupInvoice'));
    exit;
  end;

  // if (MessageDlg('Move roomrent to Groupinvoice ' + chr(10) + 'and save other changes ?', mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
  if (MessageDlg(GetTranslatedText
    ('shTx_Invoice_RoomrentToGroupAndSaveChanges'), mtConfirmation,
    [mbYes, mbNo], 0) = mrYes) then
  begin
    d.UpdateGroupAccountone(FReservation, FRoomReservation,
      FRoomReservation, True);
    SaveInvoice(zInvoiceNumber);
    LoadInvoice;
  end;
end;

procedure TfrmInvoice.MoveRoomToNewInvoiceIndex(rowIndex, toInvoiceIndex: integer);
begin
  // if (MessageDlg('Move roomrent to Groupinvoice ' + chr(10) + 'and save other changes ?', mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
  d.UpdateGroupAccountone(FReservation, FRoomReservation, FRoomReservation, FRoomReservation = 0, toInvoiceIndex);
  InvoiceIndex := FInvoiceIndex;
end;

function TfrmInvoice.IsRoomSelected: boolean;
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
          break;
        end;
      end;
end;

procedure TfrmInvoice.MoveRoomToRoomInvoice;
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
  if (MessageDlg(GetTranslatedText('shTx_Invoice_RoomrentToRoomAndSaveChanges'),
    mtConfirmation, [mbYes, mbNo], 0) = mrYes) then
  begin
    d.UpdateGroupAccountone(FReservation, selectedRoomReservation,
      selectedRoomReservation, false);
    SaveInvoice(zInvoiceNumber);
    LoadInvoice;
  end;
end;

procedure TfrmInvoice.edtCurrencyDblClick(Sender: TObject);
var
  s: string;
  theData: recCurrencyHolder;
  oldCurrency: string;
begin
  s := '';
  oldCurrency := trim(edtCurrency.Text);
  theData.Currency := oldCurrency;
  Currencies(actLookup, theData);
  if theData.Currency <> '' then
  begin
    s := theData.Currency;
  end;

  if (s <> '') and (s <> oldCurrency) then
  begin
    edtCurrency.Text := s;
    if edtCurrency.Text = zNativeCurrency then
    begin
      edtForeignCurrency.Text := '';
      edtForeignCurrency.Visible := false;
    end;
    zCurrentCurrency := s;
    CheckCurrencyChange(oldCurrency);
  end;
  chkChanged;
end;

procedure TfrmInvoice.agrLinesDrawCell(Sender: TObject; ACol, ARow: integer;
  Rect: TRect; State: TGridDrawState);
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
    Bmp := TIcon.create;
    try
      GridImages.GetIcon(0, Bmp);
      TAdvStringGrid(Sender).canvas.Draw(Rect.left + 1, Rect.top + 1, Bmp);
    finally
      Bmp.free;
    end;
  except
  end;
end;

procedure TfrmInvoice.CheckCurrencyChange(oldCurrency: string);
var
  oldRate, NewRate: Double;
  i: integer;

  sUnitPrice: string;
  fUnitPrice: Double;

  unitPrice: Double;
  TotalPrice: Double;

  convert: Double;

  unitCount: Double; // -96

  s: string;
  rSet: TRoomerDataset;
  aDate: string;

  RoomReservation: integer;

  Item: string;
begin

  if zCurrentCurrency <> oldCurrency then
  begin
    oldRate := GetRate(oldCurrency);
    NewRate := GetRate(zCurrentCurrency);

    if NewRate = 0 then
      NewRate := 1;
    zCurrencyRate := NewRate;
    edtRate.Text := floattostr(zCurrencyRate);
    convert := oldRate / NewRate;

    // Then update database;
    if (FRoomReservation = 0) and (FReservation > 0) then
    begin
      rSet := CreateNewDataSet;
      try
        s := '';
        s := format(select_Invoice_CheckCurrencyChange, [FReservation, FInvoiceIndex]);
        hData.rSet_bySQL(rSet, s);
        rSet.first;
        while not rSet.eof do
        begin
          RoomReservation := rSet.FieldByName('RoomReservation').asinteger;
          mRoomRates.first;
          while not mRoomRates.eof do
          begin
            if mRoomRates['Roomreservation'] = RoomReservation then
            begin
              aDate := _db(mRoomRates.FieldByName('rateDate')
                .asdateTime, false);
              d.RR_Upd_CurrencyRoomPrice(RoomReservation, aDate,
                zCurrentCurrency, convert);
            end;
            mRoomRates.Next;
          end;
          s := '';
          s := s + ' UPDATE roomreservations ' + chr(10);
          s := s + ' SET ' + chr(10);
          s := s + ' Currency=' + _db(zCurrentCurrency) + ' ' + chr(10);
          s := s + ' WHERE (RoomReservation = ' + inttostr(RoomReservation) +
            ') ' + chr(10);
          if not cmd_bySQL(s) then
          begin
          end;

          rSet.Next;
        end;
      finally
        FreeAndNil(rSet);
      end;
    end
    else if (FRoomReservation > 0) then
    begin
      mRoomRates.first;
      while not mRoomRates.eof do
      begin
        aDate := _db(mRoomRates.FieldByName('rateDate').asdateTime, false);
        d.RR_Upd_CurrencyRoomPrice(FRoomReservation, aDate,
          zCurrentCurrency, convert);
        s := '';
        s := s + ' UPDATE roomreservations ' + chr(10);
        s := s + ' SET ' + chr(10);
        s := s + ' Currency=' + _db(zCurrentCurrency) + ' ' + chr(10);
        s := s + ' WHERE (RoomReservation = ' + inttostr(FRoomReservation) +
          ') ' + chr(10);
        cmd_bySQL(s);
        mRoomRates.Next;
      end;
    end
    else if (FRoomReservation = 0) and (FReservation = 0) then
    begin
      exit;
    end;

    calcAndAddAutoItems(FReservation);

    for i := 1 to agrLines.RowCount - 1 do
    begin
      Item := agrLines.Cells[col_Item, i];
      if Item_isRoomRent(Item) then
      begin
        if NOT isSystemLine(i) then
        begin
          sUnitPrice := agrLines.Cells[col_ItemPrice, i];
          fUnitPrice := _StrToFloat(sUnitPrice);
          unitPrice := fUnitPrice * convert;

          try
            unitCount := _StrToFloat(agrLines.Cells[col_ItemCount, i])
          except
            unitCount := 1;
          end;

          TotalPrice := unitCount * unitPrice;
          agrLines.Cells[col_ItemPrice, i] :=
            _floattostr(unitPrice, vWidth, vDec);
          agrLines.Cells[col_TotalPrice, i] :=
            _floattostr(TotalPrice, vWidth, vDec);
        end;
      end;
    end;

    SaveAnd(false, true);
//    FormCreate(nil);
    LoadInvoice;
    UpdateCaptions;
  end;

end;

procedure TfrmInvoice.CheckRateChange;
var
  NewRate: Double;
  sRate: string;

begin
  sRate := edtRate.Text;

  try
    NewRate := _StrToFloat(edtRate.Text);
  except
    NewRate := 1;
    edtRate.Color := clRed;
  end;

  if NewRate = 0 then
    NewRate := 1;

  zCurrencyRate := NewRate;
  calcAndAddAutoItems(FReservation);
end;

procedure TfrmInvoice.SetCustEdits;
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

procedure TfrmInvoice.SetInvoiceIndex(const Value: integer);
begin
  IfInvoiceChangedThenOptionallySave;
  FInvoiceIndex := Value;
  CorrectInvoiceIndexRectangles;
  RemoveAllCheckboxes;
  LoadInvoice;
end;

procedure TfrmInvoice.pnlInvoiceIndex0Click(Sender: TObject);
begin
  InvoiceIndex := TsPanel(Sender).Tag;
end;

function TfrmInvoice.GetSelectedRows: TList<String>;
var
  i: integer;
  check: boolean;
begin
  result := TList<String>.create;
  if AnyRowChecked then
  begin
    for i := 1 to agrLines.RowCount - 1 do
      if agrLines.HasCheckBox(col_Select, i) then
      begin
        agrLines.GetCheckBoxState(col_Select, i, check);
        if check then
          result.add(agrLines.Cells[col_autogen, i]);
      end;
  end
  else
    if (agrLines.row > 0) AND (agrLines.row < agrLines.RowCount) then
    result.add(agrLines.Cells[col_autogen, agrLines.row]);

  RemoveAllCheckboxes;
end;

function TfrmInvoice.IndexOfAutoGen(AutoGen: String): integer;
var
  i: integer;
begin
  result := -1;
  for i := 1 to agrLines.RowCount - 1 do
    if agrLines.Cells[col_autogen, i] = AutoGen then
    begin
      result := i;
      break;
    end;
end;

procedure TfrmInvoice.pnlInvoiceIndex0DragDrop(Sender, Source: TObject; X, Y: integer);
var
  list: TList<String>;
  i, l, Res: integer;
  invoiceLine: TInvoiceLine;
begin
  Res := -1;
  if (Source = agrLines) then
  begin
    list := GetSelectedRows;
    try
      for l := list.Count - 1 downto 0 do
      begin
        i := IndexOfAutoGen(list[l]);
        if i >= 0 then
        begin
          agrLines.row := i;
          if isSystemLine(i) AND (trim(agrLines.Cells[col_Item, i]) = g.qRoomRentItem) then
          begin
            MoveRoomToNewInvoiceIndex(i, TsPanel(Sender).Tag);
          end
          else
            if isSystemLine(i) AND (trim(agrLines.Cells[col_Item, i]) = g.qStayTaxItem) then
          begin
            if Res <> mrAll then
              Res := MessageDlg(GetTranslatedText('shTx_Invoice_WarningWhenMovingCityTax'), mtWarning,
                [mbYes, mbNo, mbAll, mbCancel], 0);
            if Res IN [mrYes, mrAll] then
            begin
              invoiceLine := CellInvoiceLine(i);
              agrLines.Objects[col_Item, i] := TObject(invoiceLine.FInvoiceLineIndex);
              RV_ToggleUseStayTax(FReservation);
              MoveItemToNewInvoiceIndex(i, TsPanel(Sender).Tag);
            end
            else
              if Res = mrCancel then
              exit;
          end
          else
            MoveItemToNewInvoiceIndex(i, TsPanel(Sender).Tag);
        end;
      end;
    finally
      list.free;
    end;
    RemoveAllCheckboxes;
    CheckCheckboxes;
  end
  else
  begin
    MoveDownpaymentToInvoiceIndex(TsPanel(Sender).Tag);
  end;
end;

procedure TfrmInvoice.pnlInvoiceIndex0DragOver(Sender, Source: TObject;
  X, Y: integer; State: TDragState; var Accept: boolean);
begin
  Accept := (Source = agrLines) OR (Source IS TcxDragControlObject);
end;

procedure TfrmInvoice.pnlPaymentButtonsResize(Sender: TObject);
begin
  pnlPaymentButtons.Left := btnSaveChanges.Left + btnSaveChanges.Width - pnlPaymentButtons.Width;
end;

procedure TfrmInvoice.T1Click(Sender: TObject);
begin
  actItemToGroupInvoiceExecute(Sender);
end;

procedure TfrmInvoice.mnuMoveRoomRentFromRoomInvoiceToGroupClick(Sender: TObject);
begin
  MoveRoomToGroupInvoice;
end;

procedure TfrmInvoice.mnuMoveRoomRentFromGroupToNormalRoomInvoiceClick(Sender: TObject);
begin
  MoveRoomToRoomInvoice;
end;

function TfrmInvoice.GetCustomerHeader(Res: integer): boolean;
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

function TfrmInvoice.GetInvoiceHeader(Res, RoomRes: integer): boolean;
var
  invoiceNumber: integer;
  customer: string;
  name: string;
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

    invoiceNumber := -1;
    rSet.first;
    if rSet.RecordCount > 0 then
    begin
      invoiceNumber := rSet.FieldByName('InvoiceNumber').asinteger;
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
    if (invoiceNumber = -1) or (FIsCredit) then
    begin
      edtCustomer.Text := trim(customer);
      edtName.Text := trim(name);
      edtPersonalId.Text := trim(CustPID);
      edtAddress1.Text := trim(Address1);
      edtAddress2.Text := trim(Address2);
      edtAddress3.Text := trim(Address3);
      edtAddress4.Text := trim(Address4);
      edtInvRefrence.Text := trim(invRefrence);

      zCountry := trim(Country);
      result := True;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

function TfrmInvoice.GetInvoiceHeader(Res, RoomRes: integer; arSet: TRoomerDataset): boolean;
var
  invoiceNumber: integer;
  customer: string;
  name: string;
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

  invoiceNumber := -1;
  arSet.first;
  if NOT arSet.eof then
  begin
    invoiceNumber := arSet.FieldByName('InvoiceNumber').asinteger;
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
  if (invoiceNumber = -1) or (FIsCredit) then
  begin
    edtCustomer.Text := trim(customer);
    edtName.Text := trim(name);
    edtPersonalId.Text := trim(CustPID);
    edtAddress1.Text := trim(Address1);
    edtAddress2.Text := trim(Address2);
    edtAddress3.Text := trim(Address3);
    edtAddress4.Text := trim(Address4);
    edtInvRefrence.Text := trim(invRefrence);
    memExtraText.Lines.Text := trim(FreeText);

    zCountry := trim(Country);
    result := True;
  end;
end;

function TfrmInvoice.GetReservationHeader(Res, RoomRes: integer): boolean;
var
  customer: string;
  name: string;
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
    edtInvRefrence.Text := trim(invRefrence);
    zCountry := trim(Country);

    result := True;
  finally
    FreeAndNil(rSet);
  end;
end;

function TfrmInvoice.GetMainGuestHeader(Res, RoomRes: integer): boolean;
var
  name: string;
  Address1: string;
  Address2: string;
  Address3: string;
  Address4: string;
  Country: string;
  PID: string;

  rSet: TRoomerDataset;
  s: string;
  sql: string;
  Customer : String;

begin
  result := false;
  if FnewSplitNumber = 2 then
    exit;

  if FReservation = -1 then
    exit;

  rSet := CreateNewDataSet;
  try
//    sql := ' SELECT pe.Person, ' +
//    ' pe.RoomReservation, ' +
//    ' pe.Reservation, ' +
//    ' IFNULL(ia.Customer, co.RackCustomer) AS Customer,' +
//    ' IFNULL(ia.Name, pe.Name) AS Name,' +
//    ' IFNULL(ia.Address1, pe.Address1) AS Address1, ' +
//    ' IFNULL(ia.Address2, pe.Address2) AS Address2, ' +
//    ' IFNULL(ia.Zip, pe.Address3) AS Address3, ' +
//    ' IFNULL(ia.Country, pe.Address4) AS Address4, ' +
//    ' IFNULL(ia.Country, pe.Country) AS Country, ' +
//    ' pe.PID ' +
//    ' FROM persons pe ' +
//    '     LEFT JOIN invoiceaddressees ia ON ia.invoiceNumber=-1 ' +
//    '        AND ia.Reservation=pe.Reservation ' +
//    '        AND ia.RoomReservation=pe.RoomReservation ' +
//    '        AND ia.SplitNumber=0 ' +
//    '        AND ia.InvoiceIndex=%d, ' +
//    '     control co ' +
//    ' WHERE (pe.Reservation = %d) AND (pe.RoomReservation = %d) ';
//    s := format(sql, [InvoiceIndex, Res, RoomRes]);

    sql := ' SELECT pe.Person, ' +
    ' pe.RoomReservation, ' +
    ' pe.Reservation, ' +
    ' co.RackCustomer AS Customer,' +
    ' pe.Name,' +
    ' pe.Address1 Address1, ' +
    ' pe.Address2 AS Address2, ' +
    ' pe.Address3 Address3, ' +
    ' pe.Address4 Address4, ' +
    ' pe.Country Country, ' +
    ' pe.PID ' +
    ' FROM persons pe, ' +
    '     control co ' +
    ' WHERE (pe.Reservation = %d) AND (pe.RoomReservation = %d) ';
    s := format(sql, [Res, RoomRes]);
    CopyToClipboard(s);
    hData.rSet_bySQL(rSet, s);

    rSet.first;
    name := '';
    Address1 := '';
    Address2 := '';
    Address3 := '';
    Address4 := '';
    Country := '';
    Customer := ctrlGetString('RackCustomer');

    if not rSet.eof then
    begin
      name := rSet.FieldByName('Name').asString;
      Address1 := rSet.FieldByName('Address1').asString;
      Address2 := rSet.FieldByName('Address2').asString;
      Address3 := rSet.FieldByName('Address3').asString;
      Address4 := rSet.FieldByName('Address4').asString;
      Country := rSet.FieldByName('Country').asString;
      PID := rSet.FieldByName('PID').asString;
      Customer := rSet.FieldByName('Customer').asString;
    end;

    edtCustomer.Text := Customer;
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

function TfrmInvoice.GetMainGuestName(Res, RoomRes: integer): string;
var
  name: string;
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

procedure TfrmInvoice.rgrInvoiceTypeClick(Sender: TObject);
var
  s: string;
  sCustomer: string;

begin
  s := edtPersonalId.Text;
  sCustomer := edtCustomer.Text;

  btnGetCustomer.Enabled := rgrInvoiceType.itemIndex <> 1;
  btnClearAddresses.Enabled := rgrInvoiceType.itemIndex <> 1;

  memUpdateDone := false;
  chkChanged;

  SetCustEdits;

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

  edtRoomGuest.Text := GetMainGuestName(FReservation, FRoomReservation);

end;

procedure TfrmInvoice.S1Click(Sender: TObject);
begin
  btnSaveChanges.Click;
end;

procedure TfrmInvoice.SaveAnd(doExit: boolean; currencyChange : Boolean = False);
begin
  try
    if zDoSave then
    begin
      SaveInvoice(zInvoiceNumber, currencyChange);
      chkChanged;
      if doExit then
        close;
    end;
  except
  end;
end;

procedure TfrmInvoice.actSaveAndExitExecute(Sender: TObject);
begin
  SaveAnd(True);
end;
procedure TfrmInvoice.actPrintInvoiceExecute(Sender: TObject);
var
  ok: boolean;
begin
  ok := hData.CustomerExist(trim(edtCustomer.Text));

  if not ok then
  begin
    MessageDlg('Customer not found', mtError, [mbOk], 0);
    exit
  end;

  if PayInvoiceAndPrint then
    close;
end;

procedure TfrmInvoice.actPrintProformaExecute(Sender: TObject);
begin
  PrintProforma;
end;

procedure TfrmInvoice.btnEditDownPaymentClick(Sender: TObject);
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
    rec.InvoiceBalance := _StrToFloat(edtBalance.Text) +
      _StrToFloat(edtDownPayments.Text);

  rec.reservation := FReservation;
  rec.RoomReservation := FRoomReservation;
  rec.Invoice := zInvoiceNumber;
  rec.Amount := mPayments.FieldByName('Amount').asfloat;
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
      rSet := CreateNewDataSet;
      try
        mPayments.close;
        mPayments.Open;

        sql := 'SELECT * FROM payments ' + ' where Reservation = %d ' +
          '   and RoomReservation = %d ' +
          '   and InvoiceNumber = -1 AND InvoiceIndex=%d';
        s := format(sql, [FReservation, FRoomReservation, FInvoiceIndex]);
        if rSet_bySQL(rSet, s) then
        begin
          while not rSet.eof do
          begin
            mPayments.insert;
            mPayments.FieldByName('PayType').asString :=
              rSet.FieldByName('PayType').asString;
            mPayments.FieldByName('PayDate').asdateTime := SQLToDateTime(rSet.FieldByName('PayDate').asString);
            mPayments.FieldByName('Amount').asfloat :=
              rSet.FieldByName('Amount').asfloat;
            mPayments.FieldByName('Description').asString :=
              rSet.FieldByName('Description').asString;
            mPayments.FieldByName('PayGroup').asString := '';
            mPayments.FieldByName('Memo').asString :=
              rSet.FieldByName('Notes').asString;
            mPayments.FieldByName('confirmDate').asdateTime :=
              rSet.FieldByName('Confirmdate').asdateTime;
            mPayments.FieldByName('Id').asinteger := rSet.FieldByName('ID')
              .asinteger;
            if glb.Paytypesset.Locate('payType', rSet.FieldByName('PayType')
              .asString, []) then
            begin
              mPayments.FieldByName('PayGroup').asString :=
                glb.Paytypesset.FieldByName('payGroup').asString;
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

procedure TfrmInvoice.MoveDownpaymentToInvoiceIndex(toInvoiceIndex: integer);
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
  rec.Amount := mPayments.FieldByName('Amount').asfloat;
  rec.Quantity := 1;
  rec.Description := mPayments.FieldByName('Description').asString;
  rec.Notes := mPayments.FieldByName('Memo').asString;
  rec.PaymentType := mPayments.FieldByName('PayType').asString;
  rec.PayDate := mPayments.FieldByName('PayDate').asdateTime;
  rec.payGroup := mPayments.FieldByName('PayGroup').asString;
  rec.confirmDate := mPayments.FieldByName('Confirmdate').asdateTime;

  Id := mPayments.FieldByName('ID').asinteger;

  if (rec.confirmDate < 3) and (Id > 0) then
  begin
    s := ' UPDATE payments SET InvoiceIndex=' + inttostr(toInvoiceIndex) + ' '#10;
    s := s + ' WHERE  Id = (' + _db(Id) + ') ' + #10;

    if cmd_bySQL(s) then
    begin
      mPayments.delete;
      AddInvoiceActivityLog(g.qUser, rec.reservation, rec.RoomReservation, 1
        // field typeindex 0 = invoice payment 1 = downpayment
        , DELETE_PAYMENT, rec.PaymentType, rec.Amount, zInvoiceNumber,
        rec.Description);
    end;

    DisplayTotals;
  end
  else
  begin
    ShowMessage('It is not allowed to Delete confirmed payments');
  end;
end;

procedure TfrmInvoice.btnDeleteDownpaymentClick(Sender: TObject);
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
  rec.Amount := mPayments.FieldByName('Amount').asfloat;
  rec.Quantity := 1;
  rec.Description := mPayments.FieldByName('Description').asString;
  rec.Notes := mPayments.FieldByName('Memo').asString;
  rec.PaymentType := mPayments.FieldByName('PayType').asString;
  rec.PayDate := mPayments.FieldByName('PayDate').asdateTime;
  rec.payGroup := mPayments.FieldByName('PayGroup').asString;
  rec.confirmDate := mPayments.FieldByName('Confirmdate').asdateTime;

  Id := mPayments.FieldByName('ID').asinteger;

  if (rec.confirmDate < 3) and (Id > 0) then
  begin
    if MessageDlg('Delete payment ?'#10 + rec.Description + ' / Amount ' +
      _floattostr(rec.Amount, vWidth, vDec), mtConfirmation,
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
            , DELETE_PAYMENT, rec.PaymentType, rec.Amount, zInvoiceNumber,
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

procedure TfrmInvoice.actDownPaymentExecute(Sender: TObject);
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
    rec.InvoiceBalance := _StrToFloat(edtBalance.Text);

  if g.OpenDownPayment(actInsert, rec) then
  begin
    // insert payment

    initPaymentHolderRec(theData);

    theData.reservation := FReservation;
    theData.RoomReservation := FRoomReservation;
    theData.Person := FnewSplitNumber;
    theData.TypeIndex := ORD(ptDownPayment);
    theData.invoiceNumber := zInvoiceNumber;
    theData.customer := edtCustomer.Text;
    theData.PayDate := _db(Date, false);
    theData.Amount := rec.Amount;
    theData.Description := rec.Description;
    theData.CurrencyRate := zCurrencyRate; // ATH
    theData.Currency := zCurrentCurrency;
    theData.confirmDate := 2; // _db('1900-01-01 00:00:00');
    theData.Notes := rec.Notes;
    theData.PayType := rec.PaymentType;
    theData.InvoiceIndex := InvoiceIndex;

    NewId := 0;
    if INS_Payment(theData, NewId) then
    begin
      mPayments.insert;
      mPayments.FieldByName('PayType').asString := rec.PaymentType;
      mPayments.FieldByName('PayDate').asdateTime := Date;
      mPayments.FieldByName('Amount').asfloat := rec.Amount;
      mPayments.FieldByName('Description').asString := rec.Description;
      if glb.Paytypesset.Locate('payType', rec.PaymentType, []) then
      begin
        mPayments.FieldByName('PayGroup').asString :=
          glb.Paytypesset.FieldByName('payGroup').asString;
      end;
      mPayments.FieldByName('Memo').asString := rec.Notes;
      mPayments.FieldByName('confirmDate').asdateTime := theData.confirmDate;
      mPayments.FieldByName('ID').asinteger := NewId;
      mPayments.FieldByName('InvoiceIndex').asinteger := InvoiceIndex;

      mPayments.post;
      DisplayTotals;
    end;
  end;

end;

procedure TfrmInvoice.actInfoExecute(Sender: TObject);
begin
  if g.openresMemo(FReservation) then
  begin
  end;
end;

procedure TfrmInvoice.actAddLineExecute(Sender: TObject);
begin
  agrLines.row := agrLines.RowCount - 1;
  itemLookup;
end;

procedure TfrmInvoice.actDelLineExecute(Sender: TObject);
var
  list: TList<String>;
  i, l, Id: integer;
  s: String;
begin
  // if MessageDlg('Delete item ', mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  if AnyRowChecked then
    s := GetTranslatedText('shTx_Invoice_DeleteSelectedItems')
  else
    s := GetTranslatedText('shTx_Invoice_DeleteItem');
  if MessageDlg(s, mtConfirmation,
    [mbYes, mbNo], 0) = mrYes then
  begin
    list := GetSelectedRows;
    try
      for l := list.Count - 1 downto 0 do
      begin
        i := IndexOfAutoGen(list[l]);
        if i >= 0 then
        begin
          agrLines.row := i;
          Id := CellInvoiceLineId(i);
          if Id > 0 then
            DeletedLines.add(Id);
          DeleteRow(agrLines, agrLines.row);
          AddEmptyLine;
          chkChanged;
        end;
      end;
    finally
      list.free;
    end;
    calcAndAddAutoItems(FReservation);
    setControls;
  end;
end;

procedure TfrmInvoice.actRRtoTempExecute(Sender: TObject);
var
  CurrentRow: integer;
  sRoomRentItem: string;
  sDiscountItem: string;
  sCurrentItem: string;
  list: TList<String>;
  i, l: integer;
begin
  // if MessageDlg('Set room to temp ', mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
  if MessageDlg(GetTranslatedText('shTx_Invoice_SetTemp'), mtConfirmation,
    [mbYes, mbNo], 0) <> mrYes then
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
    list.free;
  end;
  calcAndAddAutoItems(FReservation);
  RemoveAllCheckboxes;
  CheckCheckboxes;
end;

procedure TfrmInvoice.ItemToTemp(confirm: boolean);
var
  PurchaseDate: TDateTime;
  invoiceNumber: integer;
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

begin
  isPackage := false;

  CurrentRow := agrLines.row;
  if isSystemLine(CurrentRow) then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_SaleNotSelected'));
    exit;
  end;

  PurchaseDate := integer(agrLines.Objects[col_Description, CurrentRow]);
  invoiceNumber := zInvoiceNumber;
  itemNumber := CurrentRow;

  ItemId := trim(agrLines.Cells[col_Item, CurrentRow]);

  if ItemId = '' then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_EmptyInvoice'));
    exit;
  end;

  Description := trim(agrLines.Cells[col_Description, CurrentRow]); // (70)
  importRefrence := trim(agrLines.Cells[col_Refrence, CurrentRow]);
  ImportSource := trim(agrLines.Cells[col_Source, CurrentRow]);

  // if MessageDlg('Take [' + itemId + '] from invoice ', mtConfirmation, [mbYes, mbNo], 0) <> mrYes then
  if confirm AND (MessageDlg(format(GetTranslatedText('shTx_Invoice_TakeItemFromInvoice'),
    [ItemId]), mtConfirmation, [mbYes, mbNo], 0) <> mrYes) then
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

  lInvRoom := TInvoiceRoomEntity.create(agrLines.Cells[col_Item, CurrentRow], 1, 0,
    _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), Total, 0, 0, false);
  try
    Vat := GetVATForItem(agrLines.Cells[col_Item, CurrentRow], Total,
      _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), lInvRoom,
      tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);
  finally
    lInvRoom.free;
  end;
  TotalWOVat := Total - Vat;

  Currency := edtCurrency.Text;
  CurrencyRate := GetRate(Currency);
  edtRate.Text := floattostr(CurrencyRate);

  Persons := 0;
  Nights := 0;
  if agrLines.Objects[cRoomInfoAttachColumn, CurrentRow] <> nil then
  begin
    Persons := TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, CurrentRow]).NumGuests;
    Nights := trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, CurrentRow]).Departure) -
      trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, CurrentRow]).Arrival);
  end;

  d.kbmInvoicelines.insert;
  d.kbmInvoicelines.FieldByName('Reservation').asinteger := FReservation;
  d.kbmInvoicelines.FieldByName('RoomReservation').asinteger :=
    FRoomReservation;
  d.kbmInvoicelines.FieldByName('SplitNumber').asinteger := 0;
  d.kbmInvoicelines.FieldByName('ItemNumber').asinteger := itemNumber;
  d.kbmInvoicelines.FieldByName('PurchaseDate').asdateTime := PurchaseDate;
  d.kbmInvoicelines.FieldByName('InvoiceNumber').asinteger := invoiceNumber;
  d.kbmInvoicelines.FieldByName('ItemId').asString := ItemId;
  d.kbmInvoicelines.FieldByName('Number').asfloat := Number;
  d.kbmInvoicelines.FieldByName('Description').asString := Description;
  d.kbmInvoicelines.FieldByName('Price').asfloat := Price;
  d.kbmInvoicelines.FieldByName('VATType').asString := VATType;
  d.kbmInvoicelines.FieldByName('Total').asfloat := Total;
  d.kbmInvoicelines.FieldByName('TotalWOVat').asfloat := TotalWOVat;
  d.kbmInvoicelines.FieldByName('VAT').asfloat := Vat;
  d.kbmInvoicelines.FieldByName('CurrencyRate').asfloat := CurrencyRate;
  d.kbmInvoicelines.FieldByName('Currency').asString := Currency;
  d.kbmInvoicelines.FieldByName('Persons').asinteger := Persons;
  d.kbmInvoicelines.FieldByName('Nights').asinteger := Nights;
  d.kbmInvoicelines.FieldByName('BreakfastPrice').asfloat := 0.00;
  d.kbmInvoicelines.FieldByName('ImportSource').asString := ImportSource;
  d.kbmInvoicelines.FieldByName('importRefrence').asString := importRefrence;
  d.kbmInvoicelines.FieldByName('isPackage').asBoolean := isPackage;
  d.kbmInvoicelines.post;

  labTmpStatus.caption := inttostr(d.kbmInvoicelines.RecordCount);

  if isSystemLine(agrLines.row) then
    // raise Exception.create('System item can not delete ');
    raise Exception.create(GetTranslatedText('shTx_Invoice_CanNotDelete'));

  DeleteRow(agrLines, agrLines.row);
  AddEmptyLine;
  calcAndAddAutoItems(FReservation);
  chkChanged;
end;

procedure TfrmInvoice.actItemToTempExecute(Sender: TObject);
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
    list.free;
  end;
end;

function TfrmInvoice.RoomByRoomReservation(RoomReservation: integer): String;
var
  i: integer;
begin
  result := ''; // inttostr(RoomReservation);
  for i := 0 to SelectableRooms.Count - 1 do
  begin
    if SelectableRooms[i].RoomReservation = RoomReservation then
    begin
      result := SelectableRooms[i].Room;
      break;
    end;
  end;
  if result = '' then
  begin
    for i := 0 to SelectableExternalRooms.Count - 1 do
    begin
      if SelectableExternalRooms[i].RoomReservation = RoomReservation then
      begin
        result := SelectableExternalRooms[i].Room;
        break;
      end;
    end;
  end;
  if result = '' then
    result := inttostr(RoomReservation);
end;

procedure TfrmInvoice.MoveItemToRoomInvoice(toRoomReservation, toReservation: integer;
  InvoiceIndex: integer);
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
    ShowMessage(format(GetTranslatedText('shTx_Invoice_ErrorInTotal'),
      [sTotal]));
    exit;
  end;

  ItemTypeInfo := d.Item_Get_ItemTypeInfo(ItemId, agrLines.Cells[col_Source, CurrentRow]);

  lInvRoom := TInvoiceRoomEntity.create(agrLines.Cells[col_Item, CurrentRow], 1, 0,
    _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), CurrentRow, 0, 0, false);
  try
    TotalVAT := GetVATForItem(agrLines.Cells[col_Item, CurrentRow], Total,
      _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), lInvRoom, tempInvoiceItemList,
      ItemTypeInfo, edtCustomer.Text); // BHG
  finally
    lInvRoom.free;
  end;
  TotalWOVat := Total - TotalVAT;

  s := '';
  s := s + format(GetTranslatedText('shTx_Invoice_MoveItemToRoomInvoice'),
    [ItemId, Description, RoomByRoomReservation(toRoomReservation)]);

  Btn := MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0);
  if Btn <> mrYes then
    exit;

  SaveAnd(false);

  lRoomAdditionalText := Format('(%s:', [GetTranslatedText('shRoom')]);
  if Description.Contains(lRoomAdditionalText) then
    Description := copy(Description, 1, pos(lRoomAdditionalText, Description) - 1);

  NextInvoiceLine := NumberOfInvoiceLines(reservation,
    toRoomReservation, 0) + 1;

  if agrLines.Objects[cInvoiceLineAttachColumn, agrLines.row] IS TInvoiceLine then
    InvoicelineId := TInvoiceLine(agrLines.Objects[cInvoiceLineAttachColumn, agrLines.row]).Id
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
    ShowMessage
      (format(GetTranslatedText('shTx_Invoice_FailedGroupInvoice'), [err]));
    exit;
  end;

  rSet := CreateNewDataSet;
  try
    s := format(select_Invoice_actItemToRoomInvoiceExecute,
      [reservation, RoomReservation]);
    hData.rSet_bySQL(rSet, s);
    rSet.first;
    if not rSet.eof then
    begin
      rSet.edit;
      rSet.FieldByName('Total').Value := Total + rSet.FieldByName('Total').asFloat;
      rSet.FieldByName('TotalWOVAT').Value := TotalWOVat + rSet.FieldByName('TotalWOVAT').AsFloat;
      rSet.FieldByName('TotalVAT').Value := TotalVAT + rSet.FieldByName('TotalVAT').AsFloat;
      rSet.post; // ID ADDED
    end;

  finally
    FreeAndNil(rSet);
  end;

  DeleteRow(agrLines, agrLines.row);
  AddEmptyLine;
  calcAndAddAutoItems(FReservation);
  chkChanged;
end;

procedure TfrmInvoice.MoveItemToNewInvoiceIndex(rowIndex, toInvoiceIndex: integer);
var
  reservation: integer;
  RoomReservation: integer;
  itemNumber: integer;
  ItemId: string; // (10)
  Description: string; // (70)
  lRoomAdditionalText: string;
  s: string;
  CurrentRow: integer;

  NextInvoiceLine: integer;
  RoomNumber: string;

  sTotal: string;

  UpdateOk: boolean;

  err: string;

  invoiceLine: TInvoiceLine;

begin
  err := '';

  if FInvoiceIndex = toInvoiceIndex then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_RoomInvoice'));
    exit;
  end;
  CurrentRow := rowIndex;
  if isSystemLine(CurrentRow) then
  begin
    exit;
  end;

  ItemId := trim(agrLines.Cells[col_Item, CurrentRow]);

  if ItemId = '' then
  begin
    ShowMessage(GetTranslatedText('shTx_Invoice_BlankLine'));
    exit;
  end;

  reservation := FReservation;
  RoomReservation := FRoomReservation;
  itemNumber := CurrentRow;
  RoomNumber := d.RR_GetRoomNr(RoomReservation); // SKODA
  Description := trim(agrLines.Cells[col_Description, CurrentRow]);
  sTotal := trim(agrLines.Cells[col_TotalPrice, CurrentRow]);

  SaveAnd(false);

  invoiceLine := CellInvoiceLine(rowIndex);

  lRoomAdditionalText := Format('(%s:', [GetTranslatedText('shRoom')]);
  if Description.Contains(lRoomAdditionalText) then
    Description := copy(Description, 1, pos(lRoomAdditionalText, Description) - 1);

  NextInvoiceLine := NumberOfInvoiceLines(reservation, RoomReservation, 0,
    toInvoiceIndex) + 1;
  s := '';
  s := s + ' UPDATE invoicelines ' + #10;
  s := s + ' Set ' + #10;
  s := s + '   Roomreservation = ' + _db(RoomReservation) + ' ' + #10;
  s := s + ' , itemNumber = ' + _db(NextInvoiceLine) + ' ' + #10;
  s := s + ' , Description = ' + _db(Description) + ' ' + #10;
  s := s + ' , InvoiceIndex = ' + _db(toInvoiceIndex) + ' ' + #10;
  s := s + ' , staffLastEdit = ' + _db(d.roomerMainDataSet.username) + ' ' + #10;
  if (NOT Assigned(invoiceLine)) OR (invoiceLine.FId < 1) then
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
    s := s + 'where ID = ' + _db(invoiceLine.FId);
  begin

  end;
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
    ShowMessage
      (format(GetTranslatedText('shTx_Invoice_FailedGroupInvoice'), [err]));
    exit;
  end;
  DeleteRow(agrLines, rowIndex);
  AddEmptyLine;
  chkChanged;
end;

procedure TfrmInvoice.actItemToGroupInvoiceExecute(Sender: TObject);
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
  reloadNeeded: boolean;
  InvoicelineId: integer;

begin
  err := '';
  UpdateOk := false;
  reloadNeeded := false;

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
          reloadNeeded := True;
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
          ShowMessage(format(GetTranslatedText('shTx_Invoice_ErrorInTotal'),
            [sTotal]));
          exit;
        end;

        ItemTypeInfo := d.Item_Get_ItemTypeInfo(ItemId, agrLines.Cells[col_Source, CurrentRow]);

        lInvRoom := TInvoiceRoomEntity.create(agrLines.Cells[col_Item, CurrentRow], 1, 0,
          _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), CurrentRow, 0, 0, false);
        try
          TotalVAT := GetVATForItem(agrLines.Cells[col_Item, CurrentRow], Total,
            _StrToFloat(agrLines.Cells[col_ItemCount, CurrentRow]), lInvRoom, tempInvoiceItemList,
            ItemTypeInfo, edtCustomer.Text); // BHG
        finally
          lInvRoom.free;
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

        Description := Description + Format(' (%s: %s)', [GetTranslatedText('shRoom'), RoomNumber]);
        if agrLines.Objects[cInvoiceLineAttachColumn, agrLines.row] IS TInvoiceLine then
          InvoicelineId := TInvoiceLine(agrLines.Objects[cInvoiceLineAttachColumn, agrLines.row]).Id
        else
          InvoicelineId := -1;
        NextInvoiceLine := NumberOfInvoiceLines(reservation, 0, 0) + 1 +
          RR_GetNumberGroupInvoices(reservation);
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
          ShowMessage
            (format(GetTranslatedText('shTx_Invoice_FailedGroupInvoice'), [err]));
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
    list.free;
  end;
  calcAndAddAutoItems(FReservation);
  chkChanged;
  if reloadNeeded then
    LoadInvoice;
end;

function TfrmInvoice.CreateProformaID: integer;
  function GetMinutesSinceMidnightAsString: String;
  begin
    result := ZerosInFront(inttostr(MinutesSinceMidnight), 4);
  end;

begin
  if (FReservation = 0) AND (FRoomReservation = 0) then
    result := GenerateProformaInvoiceNumber
  else if FRoomReservation > 0 then // 1,234,567,890
    result := strToInt(GetMinutesSinceMidnightAsString + '000000') +
      FRoomReservation
  else
    result := strToInt(GetMinutesSinceMidnightAsString + '000000') +
      FReservation;
  if result < cMaxFinalInvoiceNr then
    result := cMaxFinalInvoiceNr + 1 + result;
end;

procedure TfrmInvoice.RemoveCurrentProformeInvoice(ProformaInvoiceNumber: integer);
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

procedure TfrmInvoice.PrintProforma;
var
  showPackage: boolean;
begin
  showPackage := chkShowPackage.checked;

  PROFORMA_INVOICE_NUMBER := CreateProformaID;
  try
    if SaveProforma(PROFORMA_INVOICE_NUMBER) then
      ViewInvoice2(PROFORMA_INVOICE_NUMBER, True, false, false, showPackage, zEmailAddress);
  finally
    RemoveCurrentProformeInvoice(PROFORMA_INVOICE_NUMBER);
  end;
end;

function TfrmInvoice.SaveProforma(iInvoiceNumber: integer): boolean;
var
  ItemTypeInfo: TItemTypeInfo;
  i: integer;
  fWork, fVat,

    fItems, FTotal, fTotalVAT, fTotalWOVat,

    fItemTotal, fItemTotalVAT, fItemTotalWOVat: Double;

  iMultiplier: integer;

  iPersons, iNights: integer;

  AMon, ADay, AYear: Word;
  s: string;
  sTmp: string;

  ItemCount: Double;

  _CurrencyValueSell: Double;
  Refrence: string;
  Source: string;
  isPackage: boolean;

  LineHolder: hData.recInvoiceLineHolder;

  confirmDate: TDateTime;
  confirmAmount: Double;
  sItemID: string;
  sAccountKey: string;

  dNumItems: Double;

  sRRAlias: string;
  irrAlias: integer;

  lInvRoom: TInvoiceRoomEntity;
  lDate: TDate;
  lExecPlan: TRoomerExecutionPlan;

begin
  result := False;
  lExecPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    try
      _CurrencyValueSell := zCurrencyRate;

      iMultiplier := 1;

      fItems := 0.00;
      FTotal := 0.00;
      fTotalVAT := 0.00;
      fTotalWOVat := 0.00;

      for i := 1 to agrLines.RowCount - 1 do
      begin
        // -- is this an empty line ?
        if (trim(agrLines.Cells[col_Description, i]) = '') and
          (trim(agrLines.Cells[col_Item, i]) = '') then
          continue;

        iNights := 0;
        iPersons := 0;
        if agrLines.Cells[col_NoGuests, i] <> '' then
        begin
          iPersons := strToInt(agrLines.Cells[col_NoGuests, i])
        end;

        // -- is this an Automatically maintained line ?
        // og �ess vegna ekki vistu� � invoicelines
        if (isSystemLine(i)) and (iInvoiceNumber <= 0) then
          continue;

        ItemTypeInfo := d.Item_Get_ItemTypeInfo(agrLines.Cells[col_Item, i],
          agrLines.Cells[col_Source, i]);

        // --
        // RoomRentItem

        if (isSystemLine(i)) or
          (trim(g.qRoomRentItem) = agrLines.Cells[col_Item, i]) or
          (trim(g.qDiscountItem) = agrLines.Cells[col_Item, i]) then
        begin
          // Setja dagsetningu � herbergisleigu
          // Dagsetning er � upphafi 0  31.12.1899
          // en er h�r sett � dagsetningu prentunnar
          agrLines.Cells[col_date, i] := datetostr(trunc(now));
          agrLines.Objects[col_Description, i] := TObject(trunc(now));

          try
            fItemTotal := _CurrencyValueSell *
              _StrToFloat(agrLines.Cells[col_TotalPrice, i]);
          except
            fItemTotal := 0;
          end;

          if agrLines.Objects[cRoomInfoAttachColumn, i] <> nil then
          begin
            iNights := trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).Departure) -
              trunc(TRoomInfo(agrLines.Objects[cRoomInfoAttachColumn, i]).Arrival);
          end;
        end
        else
        begin
          try
            fItemTotal := _StrToFloat(agrLines.Cells[col_TotalPrice, i]);
          except
            fItemTotal := 0;
          end;
        end;

        Source := agrLines.Cells[col_Source, i];
        Refrence := agrLines.Cells[col_Refrence, i];

        sTmp := agrLines.Cells[col_confirmdate, i];
        if sTmp <> '' then
        begin
          confirmDate := _DBDateToDateTimeNoMs(sTmp);
        end
        else
          confirmDate := 2;

        confirmAmount := _StrToFloat(agrLines.Cells[col_confirmAmount, i]);

        isPackage := false;
        try
          sTmp := trim(agrLines.Cells[col_isPackage, i]);
          if sTmp = 'Yes' then
            isPackage := True;
        except
          // not raise
        end;

        // --
        dNumItems := _StrToFloat(agrLines.Cells[col_ItemCount, i]);
        if (LowerCase(trim(g.qRoomRentItem))
          = LowerCase(agrLines.Cells[col_Item, i])) OR
          (LowerCase(trim(g.qDiscountItem))
          = LowerCase(agrLines.Cells[col_Item, i])) then
          dNumItems := 1.00;

        lInvRoom := TInvoiceRoomEntity.create(agrLines.Cells[col_Item, i], 1, 0,
          _StrToFloat(agrLines.Cells[col_ItemCount, i]), fItemTotal, 0, 0, false);
        try
          fVat := GetVATForItem(agrLines.Cells[col_Item, i], fItemTotal,
            dNumItems, lInvRoom, tempInvoiceItemList, ItemTypeInfo, edtCustomer.Text);
        finally
          lInvRoom.free;
        end;
        if NOT(Item_GetKind(agrLines.Cells[col_Item, i]) IN [ikRoomRent,
          ikRoomRentDiscount]) then
          agrLines.Cells[col_Vat, i] := _floattostr(fVat, vWidth, 3);

        fItemTotalVAT := fVat;
        fItemTotalWOVat := fItemTotal - fItemTotalVAT;

        FTotal := FTotal + fItemTotal;
        fTotalVAT := fTotalVAT + fItemTotalVAT;
        fTotalWOVat := fTotalWOVat + fItemTotalWOVat;

        try
          decodedate(integer(agrLines.Objects[col_Description, i]), AYear, AMon, ADay);
        except
          decodedate(now, AYear, AMon, ADay);
        end;

        sTmp := agrLines.Cells[col_ItemCount, i];
        try
          ItemCount := _StrToFloat(sTmp);
        except
          ItemCount := 0;
        end;

        sRRAlias := trim(agrLines.Cells[col_rrAlias, i]);
        irrAlias := -1;
        try
          if sRRAlias <> '' then
            irrAlias := strToInt(sRRAlias);
        Except
        end;

        sItemID := agrLines.Cells[col_Item, i];
        sAccountKey := d.Item_Get_AccountKey(sItemID);

        // SQL 116 INSERxT Invoicelines
        // SQL 116 INSERxT Invoicelines
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
        s := s + ', ' + 'RoomReservationAlias' + #10;
        s := s + ')' + #10;
        s := s + 'Values' + #10;
        s := s + '(' + #10;
        s := s + '  ' + inttostr(FReservation);
        s := s + ', ' + _db(_GetCurrentTick);
        s := s + ', ' + inttostr(FRoomReservation);
        s := s + ', ' + inttostr(FnewSplitNumber);
        s := s + ', ' + inttostr(i);
        lDate := integer(agrLines.Objects[col_Description, i]);
        s := s + ', ' + _db(lDate);
        s := s + ', ' + inttostr(iInvoiceNumber);

        s := s + ', ' + _db(sItemID);
        s := s + ', ' + _db(ItemCount); // -96ath
        s := s + ', ' + _db(agrLines.Cells[col_Description, i]);

        if (isSystemLine(i)) or
          (trim(g.qRoomRentItem) = agrLines.Cells[col_Item, i]) or
          (trim(g.qDiscountItem) = agrLines.Cells[col_Item, i]) then
          // -- Auto-Maintained lines are displayed in foreign currency...
          s := s + ', ' + _CommaToDot
            (floattostr(iMultiplier * _CurrencyValueSell *
            _StrToFloat(agrLines.Cells[col_ItemPrice, i])))
        else // -- ...The others are not...
          s := s + ', ' + _CommaToDot
            (floattostr(iMultiplier * _StrToFloat(agrLines.Cells
            [col_ItemPrice, i])));

        s := s + ', ' + _db(ItemTypeInfo.VATCode);

        if (isSystemLine(i)) or
          (trim(g.qRoomRentItem) = agrLines.Cells[col_Item, i]) or
          (trim(g.qDiscountItem) = agrLines.Cells[col_Item, i]) then
          // -- Auto-Maintained lines are displayed in foreign currency...
          s := s + ', ' + _CommaToDot
            (floattostr(iMultiplier * _CurrencyValueSell *
            _StrToFloat(agrLines.Cells[col_TotalPrice, i])))
        else // -- ...The others are not...
          s := s + ', ' + _CommaToDot
            (floattostr(iMultiplier * _StrToFloat(agrLines.Cells
            [col_TotalPrice, i])));

        s := s + ', ' + _CommaToDot(floattostr(iMultiplier * fItemTotalWOVat));
        s := s + ', ' + _CommaToDot(floattostr(iMultiplier * fItemTotalVAT));
        s := s + ', ' + _CommaToDot(floattostr(zCurrencyRate));
        s := s + ', ' + _db(edtCurrency.Text);
        s := s + ', ' + inttostr(iPersons);
        s := s + ', ' + inttostr(iNights);
        s := s + ', ' + _CommaToDot(floattostr(0.00));
        s := s + ', ' + _db(false);

        s := s + ', ' + inttostr(AYear);
        s := s + ', ' + inttostr(AMon);
        s := s + ', ' + inttostr(ADay);

        s := s + ', ' + _db(sAccountKey);
        s := s + ', ' + _db(Refrence);
        s := s + ', ' + _db(Source);
        s := s + ', ' + _db(isPackage);
        s := s + ', ' + _db(confirmDate);
        s := s + ', ' + _db(confirmAmount);
        s := s + ', ' + _db(irrAlias);

        s := s + ')' + #10;

        lExecPlan.AddExec(s);
//        cmd_bySQL(s);

      end; { for each line }

      SaveProformaHeader(lExecPlan);
      SaveProformapayments(lExecPlan);

      result := lExecPlan.Execute(ptExec, True, True);
      if result then
        AddInvoiceActivityLog(g.qUser, FReservation, FRoomReservation, FnewSplitNumber, PRINT_PROFORMA, '', FTotal, iInvoiceNumber, 'Print Proforma');

    except
      on e: Exception do
      begin
        // MessageDlg('Problem: Unable to save the invoice !' + #13#13 + 'While saving invoice The following Error came up:' + #13#13 +
        // e.message + #13#13 + 'Please write this message down or' + #13 + 'call support with this dialog open!', mtError, [mbOK], 0);
        MessageDlg
          (format(GetTranslatedText('shTx_Invoice_UnableToSaveInvoiceMessage'),
          [e.message]), mtError, [mbOk], 0);
        raise;
      end;
    end;

  finally
    lExecPlan.Free;
  end

end;


procedure TfrmInvoice.SaveProformaHeader(aExecPlan: TRoomerExecutionPlan);
var
  iMultiplier: integer;
  s: string;
  totalStayTax: Double;
  totalStayTaxNights: Double;

begin
  iMultiplier := 1;

  // Til �ess a� setja allar t�lur � m�nus
  if FIsCredit then
    iMultiplier := -1;

  try
    totalStayTax := _StrToFloat(labLodgingTaxISK.caption);
    totalStayTax := iMultiplier * totalStayTax;
  Except
    totalStayTax := 0;
  end;

  try
    totalStayTaxNights := _StrToFloat(labLodgingTaxNights.caption);
    totalStayTaxNights := iMultiplier * totalStayTaxNights;
  except
    totalStayTaxNights := 0;
  end;

  // SQL 115 INSERxT InvoiceHeads
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
  s := s + ', invRefrence ' + #10;
  s := s + ', ihpaydate ' + #10;
  s := s + ', showpackage ' + #10;
  s := s + ', TotalStayTax ' + #10;
  s := s + ', TotalStayTaxNights ' + #10;
  s := s + ', Location ' + #10;

  s := s + ') ' + #10;
  s := s + 'Select ' + #10;
  s := s + '  ' + _db(FReservation);
  s := s + ', ' + _db(FRoomReservation);
  s := s + ', ' + _db(FnewSplitNumber);

  s := s + ', ' + _db(PROFORMA_INVOICE_NUMBER);
  s := s + ', ' + _db(zInvoiceDate, True);
  s := s + ', ' + _db(edtCustomer.Text);
  s := s + ', ' + _db(edtName.Text);
  s := s + ', ' + _db(edtPersonalId.Text);
  s := s + ', ' + _db(edtRoomGuest.Text);
  s := s + ', ' + _db(edtAddress1.Text);
  s := s + ', ' + _db(edtAddress2.Text);
  s := s + ', ' + _db(edtAddress3.Text);
  s := s + ', ' + _db(edtAddress4.Text);
  s := s + ', ' + _db(zCountry);
  s := s + ', (SELECT sum(total) from invoicelines where invoicenumber=' + _db(PROFORMA_INVOICE_NUMBER) + ') ';      //_db(FTotal);
  s := s + ', (SELECT sum(TotalWOVat) from invoicelines where invoicenumber=' + _db(PROFORMA_INVOICE_NUMBER) + ') '; //  _db(fWOVat);
  s := s + ', (SELECT sum(vat) from invoicelines where invoicenumber=' + _db(PROFORMA_INVOICE_NUMBER) + ') ' ;       //  _db(fVat);
  s := s + ', ' + _db(0.00);
  s := s + ', ' + _db(memExtraText.Lines.Text);
  s := s + ', ' + _db(zOriginalInvoice);
  s := s + ', ' + _db(false);
  s := s + ', ' + _db(rgrInvoiceType.itemIndex);
  s := s + ', ' + _db(edtInvRefrence.Text);
  s := s + ', ' + _db(now);
  s := s + ', ' + _db(chkShowPackage.checked);
  s := s + ', ' + _db(totalStayTax);
  s := s + ', ' + _db(totalStayTaxNights);
  s := s + ', ' + _db(zLocation);

  aExecplan.AddExec(s)
end;

procedure TfrmInvoice.SaveProformapayments(aExecPlan: TRoomerExecutionPlan);
var
  s: string;

  rSet: TRoomerDataset;

  sql: string;

begin
  rSet := CreateNewDataSet;
  try
    sql := 'SELECT * FROM payments ' + '  where Reservation = %d ' +
      '    and RoomReservation = %d ' +
      '    and InvoiceNumber = -1 AND InvoiceIndex=%d';
    s := format(sql, [FReservation, FRoomReservation, FInvoiceIndex]);
    hData.rSet_bySQL(rSet, s);

    rSet.first;
    while not rSet.eof do
    begin
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
      s := s + ', InvoiceIndex' + #10;
      s := s + ')' + #10;
      s := s + 'Values' + #10;
      s := s + '(' + #10;

      s := s + '  ' + _db(FReservation);
      s := s + ', ' + _db(FRoomReservation);
      s := s + ', ' + _db(rSet.FieldByName('person').asinteger);
      s := s + ', ' + _db(rSet.FieldByName('Customer').asString);
      s := s + ', ' + _db(rSet.FieldByName('AutoGen').asString);
      s := s + ', ' + _db(PROFORMA_INVOICE_NUMBER);
      s := s + ', ' + _db(rSet.FieldByName('paydate').asString);
      s := s + ', ' + _db(rSet.FieldByName('PayType').asString);
      s := s + ', ' + _db(rSet.FieldByName('Amount').AsFloat);
      s := s + ', ' + _db(rSet.FieldByName('Description').asString);
      s := s + ', ' + _db(rSet.FieldByName('Currencyrate').AsFloat);
      s := s + ', ' + _db(rSet.FieldByName('Currency').asString);
      s := s + ', ' + _db(rSet.FieldByName('TypeIndex').asinteger);
      s := s + ', ' + _db(rSet.FieldByName('AYear').asinteger);
      s := s + ', ' + _db(rSet.FieldByName('AMon').asinteger);
      s := s + ', ' + _db(rSet.FieldByName('ADay').asinteger);
      s := s + ', ' + _db(FInvoiceIndex);
      s := s + ')';

      aExecPlan.AddExec(s);
      rSet.Next;
    end;
  finally
    FreeAndNil(rSet)
  end;
end;

procedure TfrmInvoice.edtRateDblClick(Sender: TObject);
var
  Rate: Double;
  Currency: string;
begin
  Rate := zCurrencyRate;
  Currency := edtCurrency.Text;

  if g.OpenChangeRate(Rate, Currency) then
  begin
    zCurrencyRate := Rate;
    edtRate.Text := floattostr(Rate);
    CheckRateChange
  end;
  chkChanged;
end;

function TfrmInvoice.createAllStr: string;
var
  s: string;
  HeadText: string;
  GridText: string;
  SumText: string;
  CurrencyText: string;

  i: integer;
  ii: integer;

begin
  //
  s := '';
  s := s + edtCustomer.Text + ';';
  s := s + edtPersonalId.Text + ';';
  s := s + edtName.Text + ';';
  s := s + edtAddress1.Text + ';';
  s := s + edtAddress2.Text + ';';
  s := s + edtAddress3.Text + ';';
  s := s + edtAddress4.Text + ';';
  s := s + edtRoomGuest.Text + ';';
  s := s + inttostr(rgrInvoiceType.itemIndex) + ';';
  s := s + memExtraText.Text + ';';
  s := s + edtInvRefrence.Text + ';';
  s := s + booltostr(chkShowPackage.checked) + ';';

  HeadText := s;

  s := '';
  for i := 0 to agrLines.RowCount - 1 do
  begin
    for ii := 0 to agrLines.ColCount - 1 do
    begin
      s := s + agrLines.Cells[ii, i] + ';';
    end;
    s := s + chr(10);
  end;

  GridText := s;

  s := '';
  s := s + edtCurrency.Text + ';';
  s := s + edtRate.Text + ';';
  s := s + edtForeignCurrency.Text + ';';
  CurrencyText := s;

  s := '';
  s := s + edtTotal.Text + ';';
  s := s + edtVat.Text + ';';
  s := s + edtInvoiceTotal.Text + ';';
  SumText := s;

  result := HeadText + chr(10) + CurrencyText + chr(10) + SumText + chr(10)
    + GridText;
end;

function TfrmInvoice.IsCashInvoice: boolean;
begin
  result := ((FReservation + FRoomReservation) = 0);
end;

function TfrmInvoice.chkChanged: boolean;
var
  diff: boolean;
  s: string;
begin
  result := false;
  if IsCashInvoice then
    exit;

  s := createAllStr;

  diff := s <> zInitString;
  inc(zChkCount);

  lblChangedInvoiceActive.Visible := diff;
  btnSaveChanges.Visible := lblChangedInvoiceActive.Visible;
end;

procedure TfrmInvoice.LoadRoomListForCurrentReservation(reservation: integer);
var
  sql: String;
  rSet: TRoomerDataset;
  Room: TRoomInfo;
begin
  SelectableRooms.Clear;
  sql := format
    ('SELECT DISTINCT Room, RoomReservation, Reservation FROM roomsdate WHERE Reservation=%d AND ResFlag NOT IN (''X'')',
    [reservation]);
  rSet := CreateNewDataSet;
  try
    if hData.rSet_bySQL(rSet, sql, false) then
    begin
      rSet.first;
      while NOT rSet.eof do
      begin
        Room := TRoomInfo.create;
        Room.Room := rSet['Room'];
        Room.RoomReservation := rSet['RoomReservation'];
        Room.Reservation := rSet['Reservation'];
        SelectableRooms.add(Room);
        rSet.Next;
      end;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmInvoice.LoadRoomListForOtherReservations(reservation: integer);
var
  sql: String;
  rSet: TRoomerDataset;
  Room: TRoomInfo;
begin
  SelectableExternalRooms.Clear;
  sql := format
    ('SELECT DISTINCT rd.Room, rd.Reservation, rd.RoomReservation '#10 +
    ' FROM roomsdate rd '#10 +
    ' join rooms r on r.room=rd.room '#10 +
    ' WHERE ADate=''' + dateToSqlString(frmMain.dtDate.Date) + ''' AND Reservation != %d AND ResFlag IN (''P'',''G'')',
    [reservation]) + #10 +
    ' ORDER BY rd.room ';
  rSet := CreateNewDataSet;
  try
    if hData.rSet_bySQL(rSet, sql, false) then
    begin
      rSet.first;
      while NOT rSet.eof do
      begin
        Room := TRoomInfo.create;
        Room.Room := rSet['Room'];
        Room.RoomReservation := rSet['RoomReservation'];
        Room.Reservation := rSet['Reservation'];
        SelectableExternalRooms.add(Room);
        rSet.Next;
      end;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmInvoice.LoadRoomListForAllReservations;
var
  sql: String;
  rSet: TRoomerDataset;
  Room: TRoomInfo;
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
        Room := TRoomInfo.create;
        Room.Room := rSet['Room'];
        Room.RoomReservation := rSet['RoomReservation'];
        Room.Reservation := rSet['Reservation'];
        SelectableExternalRooms.add(Room);
        rSet.Next;
      end;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

procedure TfrmInvoice.FillRoomsInMenu(mnuItem: TMenuItem);
var
  i: integer;
  Item, subItem: TMenuItem;
  l: integer;
begin
  if (mnuItem = mnuMoveItemToSpecifiedRoomAndInvoiceIndex) OR (mnuItem = mnuMoveRoomRentFromGroupToNormalRoomInvoice)
  then
  begin
    LoadRoomListForCurrentReservation(FReservation);
    mnuItem.Clear;
    for i := 0 to SelectableRooms.Count - 1 do
    begin
      Item := TMenuItem.create(nil);
      Item.caption := SelectableRooms[i].Room;
      Item.Tag := i;
      mnuItem.add(Item);
      if (mnuItem = mnuMoveItemToSpecifiedRoomAndInvoiceIndex) then
      begin
        Item.Clear;
        for l := 0 to mnuInvoiceIndex.Items.Count - 1 do
        begin
          subItem := TMenuItem.create(nil);
          subItem.caption := mnuInvoiceIndex.Items[l].caption;
          subItem.Tag := mnuInvoiceIndex.Items[l].Tag;
          subItem.OnClick := N91Click;
          Item.add(subItem);
          subItem.Enabled := subItem.Tag >= 0;
        end;
      end
      else if mnuItem = mnuMoveRoomRentFromGroupToNormalRoomInvoice then
        Item.OnClick := mnuMoveRoomRentFromGroupToNormalRoomInvoiceClick;
    end;
  end;
end;

procedure TfrmInvoice.FillExternalRoomsInMenu(mnuItem: TMenuItem);
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
      Item := TMenuItem.create(nil);
      Item.caption := TRoomInfo(SelectableExternalRooms[i]).Room;
      Item.Tag := i;
      mnuItem.add(Item);
      if (mnuItem = mnuMoveItemToSpecifiedRoomAndInvoiceIndex) OR (mnuItem = mnuMoveItemToAnyOtherRoomAndInvoiceIndex)
      then
      begin
        Item.Clear;
        for l := 0 to mnuInvoiceIndex.Items.Count - 1 do
        begin
          subItem := TMenuItem.create(nil);
          subItem.caption := mnuInvoiceIndex.Items[l].caption;
          subItem.Tag := mnuInvoiceIndex.Items[l].Tag;
          subItem.OnClick := ExternalRoomsClick;
          Item.add(subItem);
          subItem.Enabled := subItem.Tag >= 0;
        end;
      end
      else if mnuItem = mnuMoveRoomRentFromGroupToNormalRoomInvoice then
        Item.OnClick := mnuMoveRoomRentFromGroupToNormalRoomInvoiceClick;
    end;
  end;
end;

procedure TfrmInvoice.FillAllRoomsInMenu(mnuItem: TMenuItem);
var
  i: integer;
  Item: TMenuItem;
begin
  LoadRoomListForAllReservations;
  mnuItem.Clear;
  for i := 0 to SelectableExternalRooms.Count - 1 do
  begin
    Item := TMenuItem.create(nil);
    Item.caption := TRoomInfo(SelectableExternalRooms[i]).Room;
    Item.Tag := i;
    mnuItem.add(Item);
    Item.OnClick := TransferRoomToAnyRoomsClick;
  end;
end;

procedure TfrmInvoice.mnuMoveItemPopup(Sender: TObject);
begin
  FillRoomsInMenu(mnuMoveItemToSpecifiedRoomAndInvoiceIndex);
  FillExternalRoomsInMenu(mnuMoveItemToAnyOtherRoomAndInvoiceIndex);
end;

procedure TfrmInvoice.mnuMoveRoomPopup(Sender: TObject);
begin
  FillAllRoomsInMenu(mnuTransferRoomRentToDifferentRoom);
end;

procedure TfrmInvoice.timCloseInvoiceTimer(Sender: TObject);
begin
  timCloseInvoice.Enabled := false;
  close;
end;

procedure TfrmInvoice.CorrectInvoiceIndexRectangles;
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

initialization


end.
