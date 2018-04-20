﻿unit uReservationProfile;

interface

uses
  VCL.Forms,
  WinAPI.Messages,
  System.Generics.Collections,
  variants,
  cxGraphics,
  cxControls,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  dxSkinsCore,
  dxSkinCaramel,
  dxSkinCoffee,
  dxSkinDarkSide,
  dxSkinTheAsphaltWorld,
  dxSkinsDefaultPainters,
  cxStyles,
  dxSkinscxPCPainter,
  cxCustomData,
  cxFilter,
  cxData,
  cxDataStorage,
  cxEdit,
  cxNavigator,
  cxDBData,
  cxCheckBox,
  cxButtonEdit,
  cxDropDownEdit,
  cxLabel,
  cxCurrencyEdit,
  cxTextEdit,
  cxTimeEdit,
  DragDrop,
  DropTarget,
  DropComboTarget,
  VCL.ExtCtrls,
  cxPropertiesStore,
  dxmdaset,
  cxGridLevel,
  cxGridCustomTableView,
  cxGridTableView,
  cxGridDBTableView,
  cxClasses,
  cxGridCustomView,
  cxGrid,
  cxSplitter,
  sMemo,
  sSplitter,
  sPageControl,
  sComboBox,
  sCheckBox,
  sEdit,
  VCL.Mask,
  sMaskEdit,
  sCustomComboEdit,
  sToolEdit,
  sButton,
  sLabel,
  sGroupBox,
  sPanel,
  Data.DB,
  VCL.Menus,
  VCL.StdCtrls,
  VCL.ComCtrls,
  VCL.Controls,
  System.Classes,
  System.Types,
  uAlertEditPanel,
  uAlerts,
  uDynamicRates
  , cxSpinEdit
  , uReservationStateDefinitions, System.Actions, Vcl.ActnList
  , uReservationStateChangeHandler, uFraCountryPanel, cxGridBandedTableView, cxGridDBBandedTableView
  , ucxGridPopupMenuActivator
  , uGridColumnFieldValuePropagator
  , uTokenHelpers, ToolPanels, RoomerExceptionHandling, Vcl.Buttons, sSpeedButton, sSpinEdit, uActivityLogs, kbmMemTable,
  uFraLookupPanel, uFraMarketSegmentPanel, uFraCustomerPanel, cxDBExtLookupComboBox, sCurrEdit, sCurrencyEdit
  ;

type

  EReservationReferenceSaveFailed = class(ERoomerUserException)
  end;

  TfrmReservationProfile = class(TForm)
    Panel2: TsPanel;
    PageControl2: TsPageControl;
    TabSheet3: TsTabSheet;
    Panel3: TsPanel;
    pnlContact: TsPanel;
    PageControl3: TsPageControl;
    TabSheet4: TsTabSheet;
    TabSheet5: TsTabSheet;
    Label19: TsLabel;
    edtKennitala: TsEdit;
    Label6: TsLabel;
    edtName: TsEdit;
    Label7: TsLabel;
    edtAddress1: TsEdit;
    edtAddress2: TsEdit;
    edtAddress3: TsEdit;
    edtInvRefrence: TsEdit;
    Label4: TsLabel;
    mainPage: TsPageControl;
    RoomsTab: TsTabSheet;
    GuestsTab: TsTabSheet;
    lvRooms: TcxGridLevel;
    grRooms: TcxGrid;
    mRooms: TdxMemData;
    mGuestRoomsDS: TDataSource;
    mRoomsReservation: TIntegerField;
    mRoomsRoomReservation: TIntegerField;
    mRoomsRoom: TWideStringField;
    mRoomsRoomType: TWideStringField;
    mRoomsArrival: TDateTimeField;
    mRoomsDeparture: TDateTimeField;
    mRoomsStatus: TWideStringField;
    mRoomsCurrency: TWideStringField;
    mRoomsisGroupAccount: TBooleanField;
    mRoomsisNoRoom: TBooleanField;
    mRoomsuseStayTax: TBooleanField;
    mRoomsRoomAlias: TWideStringField;
    mRoomsRoomTypeAlias: TWideStringField;
    tvRooms: TcxGridDBBandedTableView;
    tvRoomsRecId: TcxGridDBBandedColumn;
    tvRoomsReservation: TcxGridDBBandedColumn;
    tvRoomsRoomReservation: TcxGridDBBandedColumn;
    tvRoomsRoom: TcxGridDBBandedColumn;
    tvRoomsRoomType: TcxGridDBBandedColumn;
    tvRoomsArrival: TcxGridDBBandedColumn;
    tvRoomsDeparture: TcxGridDBBandedColumn;
    tvRoomsCurrency: TcxGridDBBandedColumn;
    tvRoomsisGroupAccount: TcxGridDBBandedColumn;
    tvRoomsisNoRoom: TcxGridDBBandedColumn;
    tvRoomsuseStayTax: TcxGridDBBandedColumn;
    tvRoomsRoomAlias: TcxGridDBBandedColumn;
    tvRoomsRoomTypeAlias: TcxGridDBBandedColumn;
    mnuFinishedInv: TPopupMenu;
    mnuThisRoom: TMenuItem;
    mnuThisreservation: TMenuItem;
    OpenthisRoom1: TMenuItem;
    OpenGroupInvoice1: TMenuItem;
    Panel9: TsPanel;
    btnShowPrices: TsButton;
    btnShowInvoice: TsButton;
    mRoomsdayCount: TIntegerField;
    tvRoomsdayCount: TcxGridDBBandedColumn;
    tvRoomsStatusText: TcxGridDBBandedColumn;
    mRoomsBreakFast: TWideStringField;
    mRoomsGuestCount: TIntegerField;
    mRoomsdefGuestCount: TIntegerField;
    tvRoomsGuestCount: TcxGridDBBandedColumn;
    tvRoomsdefGuestCount: TcxGridDBBandedColumn;
    mRoomsGuestName: TWideStringField;
    tvRoomsGuestName: TcxGridDBBandedColumn;
    tvRoomsbreakfastText: TcxGridDBBandedColumn;
    tvRoomsaccountTypeText: TcxGridDBBandedColumn;
    mRoomsunPaidRoomRent: TFloatField;
    mRoomsDiscountUnpaidRoomRent: TFloatField;
    mRoomsTotalUnpaidRoomRent: TFloatField;
    tvRoomsunPaidRoomRent: TcxGridDBBandedColumn;
    tvRoomsDiscountUnpaidRoomRent: TcxGridDBBandedColumn;
    tvRoomsTotalUnpaidRoomRent: TcxGridDBBandedColumn;
    mRoomsunpaidRentNights: TIntegerField;
    mRoomsunpaidRentPrice: TFloatField;
    tvRoomsunpaidRentNights: TcxGridDBBandedColumn;
    tvRoomsunpaidRentPrice: TcxGridDBBandedColumn;
    mRoomsunPaidItems: TFloatField;
    btnAddRoom: TsButton;
    btnRemoveRoom: TsButton;
    btnProvideRoom: TsButton;
    InvoicesTab: TsTabSheet;
    mGuests: TkbmMemTable;
    Panel10: TsPanel;
    btnGuestsRefresh: TsButton;
    Panel11: TsPanel;
    cxButton1: TsButton;
    mGuestsPerson: TIntegerField;
    mGuestsRoomReservation: TIntegerField;
    mGuestsReservation: TIntegerField;
    mGuestsGuestName: TWideStringField;
    mGuestsAddress1: TWideStringField;
    mGuestsAddress2: TWideStringField;
    mGuestsAddress3: TWideStringField;
    mGuestsAddress4: TWideStringField;
    mGuestsCountry: TWideStringField;
    mGuestsDS: TDataSource;
    mGuestRooms: TdxMemData;
    mGuestRoomsReservation: TIntegerField;
    mGuestRoomsRoomReservation: TIntegerField;
    mGuestRoomsisGroup: TBooleanField;
    mGuestRoomsinvBreakfast: TBooleanField;
    mGuestRoomsrrArrival: TDateTimeField;
    mGuestRoomsrrDeparture: TDateTimeField;
    mGuestRoomsRoom: TWideStringField;
    mGuestRoomsRoomDescription: TWideStringField;
    mGuestRoomsEquipments: TWideStringField;
    mGuestRoomsNoRoom: TBooleanField;
    mGuestRoomsRoomType: TWideStringField;
    mGuestRoomsRoomTypeDescription: TWideStringField;
    mGuestRoomsDefNumberGuests: TIntegerField;
    mGuestRoomsFloor: TIntegerField;
    mGuestRoomsLocation: TWideStringField;
    mGuestRoomsLocationDescription: TWideStringField;
    mRoomsDS: TDataSource;
    mGuestsPID: TWideStringField;
    mGuestRoomsMainGuest: TWideStringField;
    mGuestRoomsGuestCount: TIntegerField;
    btnExpand: TsButton;
    btnCollapse: TsButton;
    cxButton2: TsButton;
    mAllGuests: TdxMemData;
    mAllGuestsIntegerField1: TIntegerField;
    mAllGuestsIntegerField2: TIntegerField;
    mAllGuestsIsGroup: TBooleanField;
    mAllGuestsInvBreakfast: TBooleanField;
    mAllGuestsrrArrival: TDateTimeField;
    mAllGuestsDeparture: TDateTimeField;
    mAllGuestsRoom: TWideStringField;
    mAllGuestsRoomDescription: TWideStringField;
    mAllGuestsEquipments: TWideStringField;
    mAllGuestsNoRoom: TBooleanField;
    mAllGuestsRoomType: TWideStringField;
    mAllGuestsRoomTypeDescription: TWideStringField;
    mAllGuestsDefNumberGuests: TIntegerField;
    mAllGuestsFloor: TIntegerField;
    mAllGuestsLocation: TWideStringField;
    mAllGuestsLocationDescription: TWideStringField;
    mAllGuestsPerson: TIntegerField;
    mAllGuestsGuestName: TWideStringField;
    mAllGuestsAddress1: TWideStringField;
    mAllGuestsAddress2: TWideStringField;
    mAllGuestsAddress3: TWideStringField;
    mAllGuestsAddress4: TWideStringField;
    mAllGuestsCountry: TWideStringField;
    mAllGuestsPID: TWideStringField;
    mAllGuestsDS: TDataSource;
    mAllGuestsStatus: TWideStringField;
    mGuestRoomsStatus: TWideStringField;
    chkShowAllGuests: TsCheckBox;
    mInvoiceLines: TdxMemData;
    mInvoiceLinesInvoiceNumber: TIntegerField;
    mInvoiceLinesItem: TStringField;
    mInvoiceLinesDescription: TStringField;
    mInvoiceLinesPrice: TFloatField;
    mInvoiceLinesVatType: TStringField;
    mInvoiceLinesAmountWithTax: TFloatField;
    mInvoiceLinesAmountNoTax: TFloatField;
    mInvoiceLinesAmountTax: TFloatField;
    mInvoiceLinesCurrency: TStringField;
    mInvoiceLinesCurrencyRate: TFloatField;
    mInvoiceLinesImportRefrence: TStringField;
    mInvoiceLinesImportSource: TStringField;
    mInvoiceLinespurchaseDate: TDateField;
    mInvoiceHeads: TdxMemData;
    mInvoiceHeadsInvoiceNumber: TIntegerField;
    mInvoiceHeadsSplitNumber: TIntegerField;
    mInvoiceHeadsInvoiceDate: TDateField;
    mInvoiceHeadsdueDate: TDateField;
    mInvoiceHeadsReservation: TIntegerField;
    mInvoiceHeadsRoomReservation: TIntegerField;
    mInvoiceHeadsCustomer: TStringField;
    mInvoiceHeadsNameOnInvoice: TStringField;
    mInvoiceHeadsAddress1: TStringField;
    mInvoiceHeadsAddress2: TStringField;
    mInvoiceHeadsAddress3: TStringField;
    mInvoiceHeadsAmountWithTax: TFloatField;
    mInvoiceHeadsAmountNoTax: TFloatField;
    mInvoiceHeadsinvRefrence: TStringField;
    mInvoiceHeadsAmountTax: TFloatField;
    mInvoiceHeadsCreditInvoice: TIntegerField;
    mInvoiceHeadsOriginalInvoice: TIntegerField;
    mInvoiceHeadsRoomGuest: TStringField;
    mInvoiceHeadsPayTypes: TStringField;
    mInvoiceHeadsPayGroups: TStringField;
    mInvoiceHeadsPayTypeDescription: TStringField;
    mInvoiceHeadspayGroupDescription: TStringField;
    mInvoiceHeadsDS: TDataSource;
    mInvoiceLinesDS: TDataSource;
    Grid: TcxGrid;
    tvInvoiceHeads: TcxGridDBTableView;
    tvInvoiceHeadsRecId: TcxGridDBColumn;
    tvInvoiceHeadsInvoiceNumber: TcxGridDBColumn;
    tvInvoiceHeadsInvoiceDate: TcxGridDBColumn;
    tvInvoiceHeadsCustomer: TcxGridDBColumn;
    tvInvoiceHeadsNameOnInvoice: TcxGridDBColumn;
    tvInvoiceHeadsAmountWithTax: TcxGridDBColumn;
    tvInvoiceHeadsAmountNoTax: TcxGridDBColumn;
    tvInvoiceHeadsAmountTax: TcxGridDBColumn;
    tvInvoiceHeadsPayTypes: TcxGridDBColumn;
    tvInvoiceHeadsPayTypeDescription: TcxGridDBColumn;
    tvInvoiceHeadsPayGroups: TcxGridDBColumn;
    tvInvoiceHeadspayGroupDescription: TcxGridDBColumn;
    tvInvoiceHeadsAddress1: TcxGridDBColumn;
    tvInvoiceHeadsAddress2: TcxGridDBColumn;
    tvInvoiceHeadsAddress3: TcxGridDBColumn;
    tvInvoiceHeadsRoomGuest: TcxGridDBColumn;
    tvInvoiceHeadsinvRefrence: TcxGridDBColumn;
    tvInvoiceHeadsdueDate: TcxGridDBColumn;
    tvInvoiceHeadsCreditInvoice: TcxGridDBColumn;
    tvInvoiceHeadsOriginalInvoice: TcxGridDBColumn;
    tvInvoiceHeadsReservation: TcxGridDBColumn;
    tvInvoiceHeadsRoomReservation: TcxGridDBColumn;
    tvInvoiceHeadsSplitNumber: TcxGridDBColumn;
    tvInvoiceLines: TcxGridDBTableView;
    tvInvoiceLinesRecId: TcxGridDBColumn;
    tvInvoiceLinesInvoiceNumber: TcxGridDBColumn;
    tvInvoiceLinesItem: TcxGridDBColumn;
    tvInvoiceLinesDescription: TcxGridDBColumn;
    tvInvoiceLinesQuantity: TcxGridDBColumn;
    tvInvoiceLinesPrice: TcxGridDBColumn;
    tvInvoiceLinesAmountWithTax: TcxGridDBColumn;
    tvInvoiceLinesAmountNoTax: TcxGridDBColumn;
    tvInvoiceLinesAmountTax: TcxGridDBColumn;
    tvInvoiceLinesCurrency: TcxGridDBColumn;
    tvInvoiceLinesCurrencyRate: TcxGridDBColumn;
    tvInvoiceLinespurchaseDate: TcxGridDBColumn;
    tvInvoiceLinesImportRefrence: TcxGridDBColumn;
    tvInvoiceLinesImportSource: TcxGridDBColumn;
    tvInvoiceLinesVatType: TcxGridDBColumn;
    lvInvoiceHeads: TcxGridLevel;
    lvInvoiceLines: TcxGridLevel;
    btnInvoiceheadsExcel: TsButton;
    mInvoiceHeadsRoom: TStringField;
    tvInvoiceHeadsRoom: TcxGridDBColumn;
    StoreMain: TcxPropertiesStore;
    mRoomsPriceCode: TWideStringField;
    tvRoomsPriceCode: TcxGridDBBandedColumn;
    tvRoomsunPaidItems: TcxGridDBBandedColumn;
    timStart: TTimer;
    rgrinvoice: TcxGridDBBandedColumn;
    pnlDataWait: TsPanel;
    sLabel2: TsLabel;
    mRoomsRoomClass: TWideStringField;
    tvRoomsRoomClass: TcxGridDBBandedColumn;
    mRoomsRoomClassDescription: TWideStringField;
    tvRoomsRoomClassDescription: TcxGridDBBandedColumn;
    tvRoomsDocuments: TcxGridDBBandedColumn;
    cxButton5: TsButton;
    cxButton6: TsButton;
    mInvoiceLinesQuantity: TFloatField;
    gbxGuest: TsGroupBox;
    memPanel: TsPanel;
    sSplitter2: TsSplitter;
    sSplitter1: TsSplitter;
    GroupBox1: TsGroupBox;
    memInformation: TsMemo;
    GroupBox2: TsGroupBox;
    memPMInfo: TsMemo;
    gbxRoomInformation: TsGroupBox;
    memRoomNotes: TsMemo;
    btnRoomsRefresh: TsButton;
    gbxDates: TsGroupBox;
    cxButton3: TsButton;
    dtDeparture: TsDateEdit;
    dtArrival: TsDateEdit;
    Label2: TsLabel;
    Label3: TsLabel;
    gbxResProperties: TsGroupBox;
    cxSplitter1: TsSplitter;
    Panel1: TsPanel;
    sButton2: TsButton;
    sButton4: TsButton;
    mRoomsPackage: TWideStringField;
    tvRoomsPackage: TcxGridDBBandedColumn;
    memRequestFromChannel: TsMemo;
    edtFax: TsEdit;
    Label11: TsLabel;
    Label14: TsLabel;
    edtCustomerEmail: TsEdit;
    edtCustomerWebSite: TsEdit;
    Label15: TsLabel;
    mRoomsoutOfOrderBlocking: TBooleanField;
    sPanel1: TsPanel;
    mRoomsblockMove: TBooleanField;
    tvRoomsblockMove: TcxGridDBBandedColumn;
    mRoomsPersonsProfilesId: TIntegerField;
    rgrProfiles: TcxGridDBBandedColumn;
    sButton5: TsButton;
    btnGroups: TsButton;
    mRoomsManualChannelId: TIntegerField;
    mRoomsratePlanCode: TWideStringField;
    tvRoomsratePlanCode: TcxGridDBBandedColumn;
    sTabSheet2: TsTabSheet;
    pnlAlertHolder: TsPanel;
    timBlink: TTimer;
    DropComboTarget1: TDropComboTarget;
    __PriceViewer: TcxGridDBBandedColumn;
    pnlGuests: TsPanel;
    grGuests: TcxGrid;
    tvGuestRooms: TcxGridDBTableView;
    tvGuestRoomsRoomReservation: TcxGridDBColumn;
    tvGuestRoomsReservation: TcxGridDBColumn;
    tvGuestRoomsRoom: TcxGridDBColumn;
    tvGuestRoomsMainGuest: TcxGridDBColumn;
    tvGuestRoomsGuestCount: TcxGridDBColumn;
    tvGuestRoomsStatusText: TcxGridDBColumn;
    tvGuestRoomsRoomType: TcxGridDBColumn;
    tvGuestRoomsRoomTypeDescription: TcxGridDBColumn;
    tvGuestRoomsRoomDescription: TcxGridDBColumn;
    tvGuestRoomsEquipments: TcxGridDBColumn;
    tvGuestRoomsFloor: TcxGridDBColumn;
    tvGuestRoomsLocationDescription: TcxGridDBColumn;
    tvGuestRoomsNoRoom: TcxGridDBColumn;
    tvGuestRoomsRecId: TcxGridDBColumn;
    tvGuestRoomsisGroup: TcxGridDBColumn;
    tvGuestRoomsBreakfast: TcxGridDBColumn;
    tvGuestRoomsrrArrival: TcxGridDBColumn;
    tvGuestRoomsrrDeparture: TcxGridDBColumn;
    tvGuestRoomsDefNumberGuests: TcxGridDBColumn;
    tvGuestRoomsLocation: TcxGridDBColumn;
    tvGuestRoomsStatus: TcxGridDBColumn;
    tvGuests: TcxGridDBTableView;
    tvGuestsRecId: TcxGridDBColumn;
    tvGuestsPerson: TcxGridDBColumn;
    tvGuestsRoomReservation: TcxGridDBColumn;
    tvGuestsReservation: TcxGridDBColumn;
    tvGuestsGuestName: TcxGridDBColumn;
    tvGuestsCountry: TcxGridDBColumn;
    tvGuestsAddress1: TcxGridDBColumn;
    tvGuestsAddress2: TcxGridDBColumn;
    tvGuestsAddress3: TcxGridDBColumn;
    tvGuestsAddress4: TcxGridDBColumn;
    tvGuestsPID: TcxGridDBColumn;
    tvAllGuests: TcxGridDBTableView;
    tvAllGuestsRecId: TcxGridDBColumn;
    tvAllGuestsReservation: TcxGridDBColumn;
    tvAllGuestsRoomReservation: TcxGridDBColumn;
    tvAllGuestsRoom: TcxGridDBColumn;
    tvAllGuestsGuestName: TcxGridDBColumn;
    tvAllGuestsStatusText: TcxGridDBColumn;
    tvAllGuestsRoomType: TcxGridDBColumn;
    tvAllGuestsRoomTypeDescription: TcxGridDBColumn;
    tvAllGuestsRoomDescription: TcxGridDBColumn;
    tvAllGuestsEquipments: TcxGridDBColumn;
    tvAllGuestsFloor: TcxGridDBColumn;
    tvAllGuestsLocationDescription: TcxGridDBColumn;
    tvAllGuestsisGroup: TcxGridDBColumn;
    tvAllGuestsBreakfast: TcxGridDBColumn;
    tvAllGuestsrrArrival: TcxGridDBColumn;
    tvAllGuestsrrDeparture: TcxGridDBColumn;
    tvAllGuestsNoRoom: TcxGridDBColumn;
    tvAllGuestsDefNumberGuests: TcxGridDBColumn;
    tvAllGuestsLocation: TcxGridDBColumn;
    tvAllGuestsPerson: TcxGridDBColumn;
    tvAllGuestsPID: TcxGridDBColumn;
    tvAllGuestsAddress1: TcxGridDBColumn;
    tvAllGuestsAddress2: TcxGridDBColumn;
    tvAllGuestsAddress3: TcxGridDBColumn;
    tvAllGuestsAddress4: TcxGridDBColumn;
    tvAllGuestsCountry: TcxGridDBColumn;
    tvAllGuestsStatus: TcxGridDBColumn;
    lvGuestRooms: TcxGridLevel;
    lvGuests: TcxGridLevel;
    lvAllGuests: TcxGridLevel;
    gbxProfileAlert: TsGroupBox;
    lblSpecialRequests: TsLabel;
    lblNotes: TsLabel;
    edtSpecialRequests: TMemo;
    edtNotes: TMemo;
    mAllGuestsPersonsProfilesId: TIntegerField;
    gbxRoomAlert: TsGroupBox;
    edtRoom: TsEdit;
    edtRoomType: TsEdit;
    lblRoomType: TsLabel;
    lblRoom: TsLabel;
    mGuestsPersonsProfilesId: TIntegerField;
    mGuestRoomsPersonsProfilesId: TIntegerField;
    mRoomsExpectedTimeOfArrival: TWideStringField;
    mRoomsExpectedCheckoutTime: TWideStringField;
    tvRoomsPersonsProfilesId: TcxGridDBBandedColumn;
    tvRoomsManualChannelId: TcxGridDBBandedColumn;
    tvRoomsExpectedTimeOfArrival: TcxGridDBBandedColumn;
    tvRoomsExpectedCheckoutTime: TcxGridDBBandedColumn;
    cbxMarket: TsComboBox;
    mRoomsRateOrPackagePerDay: TFloatField;
    tvRoomsRateOrPackagePerDay: TcxGridDBBandedColumn;
    mRoomsblockMoveReason: TWideStringField;
    tvRoomsblockMoveReason: TcxGridDBBandedColumn;
    mExtras: TdxMemData;
    mExtrasRoomreservation: TIntegerField;
    mExtrasItemid: TIntegerField;
    mExtrasCount: TIntegerField;
    mExtrasFromdate: TDateTimeField;
    mExtrasPricePerItemPerDay: TFloatField;
    mExtrasToDate: TDateTimeField;
    mExtrasItem: TStringField;
    mExtrasDescription: TStringField;
    mExtrasTotalPrice: TFloatField;
    tvRoomsStockitemsPrice: TcxGridDBBandedColumn;
    tvRoomsStockItemsCount: TcxGridDBBandedColumn;
    mRoomschildrencount: TIntegerField;
    mRoomsinfantcount: TIntegerField;
    tvRoomschildrencount: TcxGridDBBandedColumn;
    tvRoomsinfantcount: TcxGridDBBandedColumn;
    pnlCustomer: TsPanel;
    Label9: TsLabel;
    pnlTopButtons : TsPanel;
    btnCheckIn: TsButton;
    btnExcel: TsButton;
    btnCheckOut: TsButton;
    btnDocuments: TsButton;
    lblMarket: TsLabel;
    tsContact: TsTabSheet;
    edtContactAddress1: TsEdit;
    edtContactAddress2: TsEdit;
    edtContactAddress3: TsEdit;
    edtContactAddress4: TsEdit;
    edtContactEmail: TsEdit;
    edtContactName: TsEdit;
    lblContactName: TsLabel;
    lblCOntactEmail: TsLabel;
    pnlTelephone: TsPanel;
    Label21: TsLabel;
    edtContactPhone: TsEdit;
    edtContactPhone2: TsEdit;
    sLabel3: TsLabel;
    sLabel6: TsLabel;
    sLabel7: TsLabel;
    pnlCustomerTelephone: TsPanel;
    sLabel1: TsLabel;
    edtTel1: TsEdit;
    edtTel2: TsEdit;
    sLabel9: TsLabel;
    edtGuestName: TsEdit;
    edtGuestAddress2: TsEdit;
    edtGuestAddress1: TsEdit;
    mAllGuestsMainName: TBooleanField;
    ppmCheckin: TPopupMenu;
    alReservation: TActionList;
    acCheckinReservation: TAction;
    acCheckinRoom: TAction;
    mnuCheckinReservation: TMenuItem;
    mnuCheckinRoom: TMenuItem;
    acCheckoutReservation: TAction;
    acCheckoutRoom: TAction;
    N1: TMenuItem;
    mnuChangeRoomStateTo: TMenuItem;
    ppmDocuments: TPopupMenu;
    acShowDocuments: TAction;
    acPasteIntoDocuments: TAction;
    ppmShowdocuments: TMenuItem;
    ppmPasteIntoDocuments: TMenuItem;
    acShowHiddenMemo: TAction;
    acPasteIntoHiddenMemo: TAction;
    btnHiddenMemo: TsButton;
    ppmHiddenMemo: TPopupMenu;
    ShowHiddenMemo1: TMenuItem;
    Clipboardtohiddenmemo1: TMenuItem;
    btnMainGuestSelectProfile: TsButton;
    btnMainGuestEditProfile: TsButton;
    sSplitter3: TsSplitter;
    mnuChangeResStateTo: TMenuItem;
    mnuGrid: TPopupMenu;
    R1: TMenuItem;
    G1: TMenuItem;
    P1: TMenuItem;
    J1: TMenuItem;
    R2: TMenuItem;
    I1: TMenuItem;
    G2: TMenuItem;
    R3: TMenuItem;
    N2: TMenuItem;
    gbxStatus: TsGroupBox;
    label25: TsLabel;
    label24: TsLabel;
    cbxBreakfastAllRooms: TsComboBox;
    cbxPaymentDetails: TsComboBox;
    gbxInfo: TsGroupBox;
    lblReservationNumber: TsLabel;
    edtReservationNumber: TsEdit;
    pnlAllGuestsNationality: TsPanel;
    btnChangeNationality: TsButton;
    btnChangeCountry: TsButton;
    mAllGuestsNationality: TWideStringField;
    pnlGuestZipCity: TsPanel;
    sLabel11: TsLabel;
    edtGuestAddress3: TsEdit;
    edtGuestAddress4: TsEdit;
    fraGuestNationality: TfraCountryPanel;
    fraGuestCountry: TfraCountryPanel;
    fraContactCountry: TfraCountryPanel;
    mAllGuestsemail: TWideStringField;
    lblGuestCountry: TsLabel;
    lblGuestNationality: TsLabel;
    lblContactCountry: TsLabel;
    acChangeRoomType: TAction;
    mRoomsAverageRoomRate: TFloatField;
    mRoomsInvoiceIndex: TIntegerField;
    sLabel4: TsLabel;
    edtBookingId: TsEdit;
    alRoomReservation: TActionList;
    acRemoveRoom: TAction;
    acGuestDetails: TAction;
    acProvideRoom: TAction;
    acJumpToRoom: TAction;
    acRoomDocuments: TAction;
    acPrices: TAction;
    acGroupGuestNames: TAction;
    acRefresh: TAction;
    acAddRoom: TAction;
    btnViewPayCard: TsButton;
    mnuRoomColumn: TPopupMenu;
    mnuCopyValueDown: TMenuItem;
    mnuCopyValueUp: TMenuItem;
    mnuCopyToAll: TMenuItem;
    acCopyValueDown: TAction;
    acCopyValueUp: TAction;
    acCopyValueAll: TAction;
    acManagePaycards: TAction;
    mRoomsPAYCARD_TOKEN_ID: TIntegerField;
    mGuestsMainName: TBooleanField;
    mGuestsID: TIntegerField;
    tvRoomsGuestlist: TcxGridDBBandedColumn;
    fraLookupMarketSegment: TfraLookupMarketSegment;
    Label8: TsLabel;
    fraCustomerPanel: TfraCustomerPanel;
    mRoomsinvBreakfast: TBooleanField;
    mGuestRoomsBreakfast: TWideStringField;
    mAllGuestsBreakfast: TWideStringField;
    mRoomsBreakfastPrice: TFloatField;
    tvRoomsBreakfastPrice: TcxGridDBBandedColumn;
    pnlBreakfastPrice: TsPanel;
    lblAllBreakfastPrice: TsLabel;
    edtAllBreakfastPrice: TsCurrencyEdit;
    lblAllBreakfastPriceCurrency: TsLabel;
    mRoomsBreakfastText: TWideStringField;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure cbxPaymentdetailsCloseUp(Sender: TObject);
    procedure memRoomNotesExit(Sender: TObject);
    procedure PageNotesChange(Sender: TObject);
    procedure btnRoomsRefreshClick(Sender: TObject);
    procedure tvRoomsCellDblClick(Sender: TcxCustomGridTableView;
      ACellViewInfo: TcxGridTableDataCellViewInfo; AButton: TMouseButton;
      AShift: TShiftState; var AHandled: Boolean);
    procedure tvRoomsTcxGridDBDataControllerTcxDataSummaryFooterSummaryItems9GetText
      (Sender: TcxDataSummaryItem; const AValue: Variant; AIsFooter: Boolean;
      var AText: string);
    procedure mRoomsAfterScroll(DataSet: TDataSet);
    procedure btnClipboardToHinndenMemoClick(Sender: TObject);
    procedure tvRoomsaccountTypeTextPropertiesChange(Sender: TObject);
    procedure tvRoomsStatusTextPropertiesChange(Sender: TObject);
    procedure btnAddRoomClick(Sender: TObject);
    procedure btnProvideRoomClick(Sender: TObject);
    procedure OpenthisRoom1Click(Sender: TObject);
    procedure OpenGroupInvoice1Click(Sender: TObject);
    procedure btnRemoveRoomClick(Sender: TObject);
    procedure btnShowPricesClick(Sender: TObject);
    procedure mnuThisRoomClick(Sender: TObject);
    procedure mnuThisreservationClick(Sender: TObject);
    procedure btnGuestsRefreshClick(Sender: TObject);
    procedure btnExpandClick(Sender: TObject);
    procedure btnCollapseClick(Sender: TObject);
    procedure cxButton2Click(Sender: TObject);
    procedure chkShowAllGuestsClick(Sender: TObject);
    procedure cxButton1Click(Sender: TObject);
    procedure btnInvoiceheadsExcelClick(Sender: TObject);
    procedure mAllGuestsAfterScroll(DataSet: TDataSet);
    procedure tvAllGuestsCanFocusRecord(Sender: TcxCustomGridTableView;
      ARecord: TcxCustomGridRecord; var AAllow: Boolean);
    procedure tvGuestRoomsCanFocusRecord(Sender: TcxCustomGridTableView;
      ARecord: TcxCustomGridRecord; var AAllow: Boolean);
    procedure tvGuestsCanFocusRecord(Sender: TcxCustomGridTableView;
      ARecord: TcxCustomGridRecord; var AAllow: Boolean);
    procedure tvRoomsInitEdit(Sender: TcxCustomGridTableView;
      AItem: TcxCustomGridTableItem; AEdit: TcxCustomEdit);
    procedure mainPageChange(Sender: TObject);
    procedure evtCustomerChangedAndValid(Sender: TObject);
    procedure tvRoomsDeparturePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure tvRoomsArrivalPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure tvRoomsdayCountPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure timStartTimer(Sender: TObject);
    procedure rgrinvoicePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure cxButton3Click(Sender: TObject);
    procedure FormResize(Sender: TObject);
    procedure tvRoomsDocumentsPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure acRoomDocumentsClick(Sender: TObject);
    procedure acJumpToRoomClick(Sender: TObject);
    procedure tvGetNativeCurrentProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvInvoiceHeadsAmountNoTaxGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvInvoiceHeadsAmountTaxGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure sButton4Click(Sender: TObject);
    procedure tvRoomsPackagePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure tvRoomsblockMovePropertiesChange(Sender: TObject);
    procedure tvRoomsPersonsProfilesIdPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure acGuestDetailsClick(Sender: TObject);
    procedure btnGroupsClick(Sender: TObject);
    procedure tvRoomsratePlanCodePropertiesCloseUp(Sender: TObject);
    procedure DropComboTarget1Drop(Sender: TObject; ShiftState: TShiftState; APoint: TPoint; var Effect: Integer);
    procedure timBlinkTimer(Sender: TObject);
    procedure btnPasteFileClick(Sender: TObject);
    procedure tvRoomsunpaidRentPricePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure DropComboTarget1GetDropEffect(Sender: TObject; ShiftState: TShiftState; APoint: TPoint;
      var Effect: Integer);
    procedure DropComboTarget1DragOver(Sender: TObject; ShiftState: TShiftState; APoint: TPoint; var Effect: Integer);
    procedure mGuestRoomsAfterScroll(DataSet: TDataSet);
    procedure mRoomsDSDataChange(Sender: TObject; Field: TField);
    procedure FormatTextToShortFormat(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure GetLocaltimeEditProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure cbxMarketCloseUp(Sender: TObject);
    procedure tvRoomsblockMoveGetCellHint(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord; ACellViewInfo: TcxGridTableDataCellViewInfo;
      const AMousePos: TPoint; var AHintText: TCaption; var AIsHintMultiLine: Boolean; var AHintTextRect: TRect);
    procedure tvRoomsStockItemsCountPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure mRoomsBeforePost(DataSet: TDataSet);
    procedure tvGetCurrencyProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure pnlTelephoneResize(Sender: TObject);
    procedure btnExcelClick(Sender: TObject);
    procedure acCheckinReservationExecute(Sender: TObject);
    procedure acCheckinRoomExecute(Sender: TObject);
    procedure acCheckoutRoomExecute(Sender: TObject);
    procedure acCheckoutReservationExecute(Sender: TObject);
    procedure acPasteIntoDocumentsExecute(Sender: TObject);
    procedure acShowDocumentsExecute(Sender: TObject);
    procedure acShowHiddenMemoExecute(Sender: TObject);
    procedure acPasteIntoHiddenMemoExecute(Sender: TObject);
    procedure btnMainGuestSelectProfileClick(Sender: TObject);
    procedure btnMainGuestEditProfileClick(Sender: TObject);
    procedure tvRoomsblockMoveReasonGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure mRoomsAfterPost(DataSet: TDataSet);
    procedure mRoomsCalcFields(DataSet: TDataSet);
    procedure mRoomsStatusGetText(Sender: TField; var Text: string; DisplayText: Boolean);
    procedure mRoomsisGroupAccountGetText(Sender: TField; var Text: string; DisplayText: Boolean);
    procedure tvRoomsStatusTextPropertiesDrawItem(AControl: TcxCustomComboBox; ACanvas: TcxCanvas; AIndex: Integer;
      const ARect: TRect; AState: TOwnerDrawState);
    procedure acChangeRoomTypeExecute(Sender: TObject);
    procedure acChangeRoomTypeUpdate(Sender: TObject);
    procedure btnChangeNationalitiesAllGuestsClick(Sender: TObject);
    procedure btnChangeCountryAllGuestsClick(Sender: TObject);
    procedure acRemoveRoomUpdate(Sender: TObject);
    procedure acRoomResActionUpdate(Sender: TObject);
    procedure acCopyValueDownExecute(Sender: TObject);
    procedure acCopyValueUpExecute(Sender: TObject);
    procedure acCopyValueAllExecute(Sender: TObject);
    procedure acManagePaycardsExecute(Sender: TObject);
    procedure btnManagePayCardsClick(Sender: TObject);
    procedure cbxStatusPanelExit(Sender: TObject);
    procedure tvRoomsEditing(Sender: TcxCustomGridTableView; AItem: TcxCustomGridTableItem; var AAllow: Boolean);
    procedure edtAllBreakfastPriceChange(Sender: TObject);
    procedure sButton2Click(Sender: TObject);
    procedure cbxBreakfastAllRoomsChange(Sender: TObject);
    procedure tvAllGuestsBreakfastGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure tvGuestRoomsBreakfastGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure tvRoomsbreakfastTextPropertiesCloseUp(Sender: TObject);
    procedure mRoomsBreakfastTextGetText(Sender: TField; var Text: string; DisplayText: Boolean);
  private
    { Private declarations }
    vStartName: string;
    FReservationState: TReservationState;
    FOutOfOrderBlocking: Boolean;
    DynamicRates: TDynamicRates;

    FrmAlertPanel: TFrmAlertPanel;
    AlertList: TAlertList;
    FValidating: Boolean;

    FReservationChangeStateHandler: TReservationStateChangeHandler;

    FOrigCaption: string;
    FgbxGuestOrigCaption: string;
    FOrigAcCheckinRoomCaption: string;
    FOrigAcCheckOutRoomCaption: string;
    FOrigmnuChangeRoomStateToCaption: string;
    FOrigmnuChangeResStateToCaption: string;
    FInitializingData: boolean;
    FCreatedBy: string;
    FCreatedOn: string;
    FColumnHeaderPopupActivator: TcxGridColumnHeaderPopupMenuActivator;
    FAllRoomsBreakfastChanged: Boolean;
    procedure Display;
    procedure Display_rGrid(gotoRoomReservation: longInt);
    procedure AddNewRoom;
    procedure MoveGuestToNewRoom2;
    procedure UpdateAllRoomsBreakfast;
    procedure UpdatePaymentDetails;

    Function MainGuestRoomsSQL(reservation: Integer): string;
    function getGuestData(gotoRoomReservation: Integer; aAllGuestsOnly: boolean = false): Boolean;

    Function guestsSQL(reservation: Integer): string;
    Function allGuestsSQL(reservation: Integer): string;

    Function InvoiceSQL(reservation: Integer): string;
    function getInvoiceData(gotoRoomReservation: Integer): Boolean;
    procedure doRRDateChange(startIn: Integer);
    procedure PlacePnlDataWait;

    procedure SetAllRoomsBreakfastItemindex;
    procedure SetPaymentDetailItemindex(sStatus: string);
    procedure SetOutOfOrderBlocking(const Value: Boolean);
    procedure SetProfileAlertVisibility;
    procedure UpdateMarket;
    procedure SetMarketItemIndex(const aMarket: string);
    procedure UpdateInfoLabels;
    procedure UpdateGuestDetails(gotoRoomReservation: integer);
    procedure UpdateStateActions;
    procedure ConstructOtherResStateMenu;
    procedure mnuOtherRoomStateChangeClick(Sender: TObject);
    procedure SelectMainGuestProfile;
    procedure ShowMainGuestProfile;
    procedure mnuOtherResStateChangeClick(Sender: TObject);
    procedure PropagateValue(aDirection: TPropagateDirection);
    function UpdateRoomBreakfasts: boolean;

    property OutOfOrderBlocking: Boolean read FOutOfOrderBlocking write SetOutOfOrderBlocking;
  public
    { Public declarations }
    tokens : TObjectList<TToken>;
    zGuestName: string;
    zGuestCount: Integer;

    zReservation: longInt;
    zRoomReservation: longInt;
    zInvoiceIndex: Integer;

    zInitDateFrom, zInitDateTo: TDate;

    zShowAllGuests: Boolean;

    zInt: Integer;
    constructor Create(aOwner: TCOmponent); override;
    destructor Destroy; override;
    procedure UpdateProfile;
  end;

var
  frmReservationProfile: TfrmReservationProfile;

function EditReservation(reservation, roomReservation: Integer): Boolean;

implementation

uses
  ADODB,
  UITypes,
  cxGridExportLink,
  Graphics,
  SysUtils,
  Windows,
  VCL.Dialogs,
  _GLOB,
  cmpRoomerDataSet,
  shellapi,
  uFrmResources,
  uUtils,
  uG,
  uD,
  uGuestProfile2,
  uProvideARoom2,
  uFinishedInvoices2,
  uResGuestList,
  uCountries,
  uCustomers2,
  uCustomertypes2,
  uSqlDefinitions,
  uAppGlobal,
  PrjConst,
  uPackages,
  uGuestProfiles,
  uGuestPortfolioEdit,
  uGuestCheckInForm,
  uDateUtils,
  uRoomerDefinitions,
  uGroupGuests,
  uAvailabilityPerDay,
  uResourceManagement,
  uViewDailyRates,
  uRoomTypes2,
  hData,
  uMain,
  uFrmNotepad,
  ufrmReservationExtras
  , uInvoiceContainer
  , uAccountTypeDefinitions, uBreakfastTypeDefinitions, uSQLUtils, ufrmRoomPrices
  , uDateTimeHelper
  , uResourceTypeDefinitions
  , uFrmPayCardView
  , uFrmTokenChargeHistory
  , ufrmInvoiceEdit, uInvoiceDefinitions, uMarketDefinitions, uRoomerCurrencymanager
  , uRoomerLanguage
, uAmount, uVCLUtils;

{$R *.DFM}


function EditReservation(reservation, roomReservation: longInt): Boolean;
begin
  // --
  result := false;
  Application.CreateForm(TfrmReservationProfile, frmReservationProfile);
  try
    frmReservationProfile.zReservation := reservation;
    frmReservationProfile.zRoomReservation := roomReservation;

    if frmReservationProfile.ShowModal = mrOK then
    begin
      try
        if d.isResCurrentlyCheckedIn(reservation) then
        begin
          g.updateCurrentGuestlist;
        end;
      except
      end;

      frmReservationProfile.UpdateProfile;

      if trim(frmReservationProfile.vStartName) <>
        trim(frmReservationProfile.edtName.text) then
      begin
        d.RV_Upd_Name(reservation, frmReservationProfile.edtName.text);
      end;

      frmMain.refreshGrid;
      result := true;
    end;
  finally
    frmReservationProfile.free;
  end;
end;

function strIsDiff(const s: string): Boolean;
var
  ch: Char;
  i: Integer;
begin
  result := false;
  if trim(s) = '' then
    exit;

  ch := s[1];
  for i := 1 to length(s) do
  begin
    if s[i] <> ch then
      result := true;
  end;
end;



// **********************************************************************
//
// Form procedures
//
// **********************************************************************

(* {FUTURE EXTENSION, SHOULD BE RUN IN SEPARATE THREAD OR DEVELOP A NEW ENDPOINT}
function TfrmReservationProfile.DetermineTotalBalance: double;
var
  lInvoice: TInvoice;
begin

  lInvoice := TInvoice.Create(ritGroup, -1, mRoomsReservation.AsInteger, mRoomsRoomReservation.AsInteger, 0, -1, '', false);
  try
    Result := lInvoice.Balance;
  finally
    lInvoice.Free;
  end;

  mRooms.DisableControls;
  try
    while not mRooms.Eof do
    begin
      lInvoice := TInvoice.Create(ritRoom, -1, mRoomsReservation.AsInteger, mRoomsRoomReservation.AsInteger, 0, -1, '', false);
      try
        Result := Result + lInvoice.Balance;
      finally
        lInvoice.Free;
      end;
      mRooms.Next;
    end;
  finally
    mROoms.EnableControls;
  end;
end;
*)

procedure TfrmReservationProfile.UpdateInfoLabels;
var
  lBuilder: TStringBuilder;
begin

  lBuilder := TStringBuilder.Create;
  try

    lBuilder.Append(FOrigCaption);
    if zReservation > 0 then
    begin
      lBuilder.AppendFormat('    -    %s: %d', [GetTranslatedText('shTx_FrmReservationprofile_ReservationNumber'), zReservation]);
      lBuilder.AppendFormat('/%d', [zRoomReservation]);

      lBuilder.AppendFormat('    -    %s: %s', [GetTranslatedText('shTx_FrmReservationprofile_Status'), FReservationChangeStateHandler.CurrentState.AsReadableString ]);

      lBuilder.AppendFormat('    -    %s: %s on %s', [GetTranslatedText('shTx_FrmReservationprofile_CreatedBy'), FCreatedBy, FCreatedOn]);

    end;
    Caption := lBuilder.ToString;

    edtReservationNumber.Text := Format('%d / %d', [zReservation, zRoomReservation]);
  finally
    lBuilder.Free;
  end;
end;

procedure TfrmReservationProfile.FormShow(Sender: TObject);
begin
  _restoreForm(self);
  enabled := false;

  TReservationState.AsStrings((tvRoomsStatusText.Properties AS TcxComboBoxProperties).Items, true);
  (tvRoomsStatusText.Properties AS TcxComboBoxProperties).DropDownRows := (tvRoomsStatusText.Properties AS TcxComboBoxProperties).Items.Count;

  TReservationMarketType.AsStrings(cbxMarket.Items);

  ConstructOtherResStateMenu;

  FOrigCaption := Caption;
  FgbxGuestOrigCaption := gbxGuest.Caption;
  FOrigAcCheckinRoomCaption := acCheckinRoom.Caption;
  FOrigAcCheckOutRoomCaption := acCheckoutRoom.Caption;
  FOrigmnuChangeRoomStateToCaption := mnuChangeRoomStateTo.Caption;
  FOrigmnuChangeResStateToCaption := mnuChangeResStateTo.Caption;

  FReservationChangeStateHandler := TReservationStateChangeHandler.Create(zReservation);

  PlacePnlDataWait;
  timStart.enabled := True;

  vStartName := frmReservationProfile.edtName.text;

  fraGuestNationality.AllowEdit := True;
  fraGuestNationality.OnChangedAndValid := btnChangeNationalitiesAllGuestsClick;
  fraGuestCountry.AllowEdit := True;
  fraGuestCountry.OnChangedAndValid := btnChangeCountryAllGuestsClick;
  fraContactCountry.AllowEdit := False;

  pnlAllGuestsNationality.Visible := glb.PMSSettings.ReservationProfileSettings.EditAllGuestsNationality;

  tvRoomsExpectedTimeOfArrival.OnHeaderClick := FColumnHeaderPopupActivator.OnCxColumnHeaderClick;
  tvRoomsExpectedCheckoutTime.OnHeaderClick := FColumnHeaderPopupActivator.OnCxColumnHeaderClick;

  fraCustomerPanel.OnChangedAndValid := evtCustomerChangedAndValid;
  fraCustomerPanel.btnLast.Visible := False;

  TBreakfastType.AsStrings((tvRoomsbreakfastText.Properties as TcxComboBoxProperties).Items);
  TBreakfastType.AsStrings((tvGuestRoomsBreakfast.Properties as TcxComboBoxProperties).Items);
  TBreakfastType.AsStrings((tvAllGuestsBreakfast.Properties as TcxComboBoxProperties).Items);
  TBreakfastType.AsStrings(cbxBreakfastAllRooms.Items);

  lblAllBreakfastPriceCurrency.Caption := RoomerCurrencyManager.DefaultCurrency;

  UpdateAllRoomsBreakfast;
  FAllRoomsBreakfastChanged := false;
end;

procedure TfrmReservationProfile.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);

  FrmAlertPanel := TFrmAlertPanel.Create(self);

  FOutOfOrderBlocking := false;
  mainPage.ActivePage := RoomsTab;
  zInt := 0;
  FReservationState := rsUnKnown;

  DynamicRates := TDynamicRates.Create;
  FReservationChangeStateHandler := nil;

  tokens := TObjectList<TToken>.Create;
end;

procedure TfrmReservationProfile.FormDestroy(Sender: TObject);
begin
  DynamicRates.free;
  tokens.Free;
  if assigned(AlertList) then
  begin
    AlertList.postChanges;
    AlertList.free;
  end;
  FReservationChangeStateHandler.Free;
end;

procedure TfrmReservationProfile.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    Close;
end;

procedure TfrmReservationProfile.FormResize(Sender: TObject);
begin
  PlacePnlDataWait;
end;

procedure TfrmReservationProfile.PlacePnlDataWait;
begin
  pnlDataWait.Left := (Width div 2) - (pnlDataWait.Width div 2);
  pnlDataWait.Top := (Height div 2) - (pnlDataWait.Height div 2);
end;

procedure TfrmReservationProfile.pnlTelephoneResize(Sender: TObject);
begin
  edtContactPhone.Width := (pnlTelephone.Width - edtContactPhone.left - 3) div 2;
  edtContactPhone2.Left := edtContactPhone.Left + edtContactPhone.Width + 3;
  edtContactPhone2.Width := edtContactPhone.Width;

  edtTel1.Width := (pnlCustomerTelephone.Width - edtTel1.Left - 3) div 2;
  edtTel2.Left := edtTel1.Left + edtTel1.Width + 3;
  edtTel2.Width := edtTel1.Width;
end;

// **********************************************************************************
//
//
// ***********************************************************************************

destructor TfrmReservationProfile.Destroy;
begin
  FColumnHeaderPopupActivator.Free;
  inherited;
end;

procedure TfrmReservationProfile.Display;
var
  ciCustomerInfo: recCustomerHolderEX;
  s: string;
  rSet: TRoomerDataSet;
  HiddenInfo: string;
  ChannelRequest: String;
begin
  pnlDataWait.Show;
  ActiveControl := grRooms;
  Application.ProcessMessages;

  mRooms.DisableControls;
  screen.Cursor := crHourGlass;
  rSet := CreateNewDataSet;
  try

    s := format(select_ReservationProfile_Display, [zReservation]);
    hData.rSet_bySQL(rSet, s);

    with rSet do
    begin
      First;
      if not Eof then
      begin
        edtInvRefrence.ReadOnly := glb.GetBooleanValueOfFieldFromId('channels', 'managedByChannelManager',
          fieldbyname('channel').asInteger);

        fraCustomerPanel.Code := trim(fieldbyname('Customer').asstring);
        // OPT?
        ciCustomerInfo := hData.Customer_GetHolder(fraCustomerPanel.Code);

        edtContactName.text := trim(fieldbyname('ContactName').asstring);
        edtContactEmail.text := trim(fieldbyname('ContactEmail').asstring);
        edtContactPhone.text := trim(fieldbyname('ContactPhone').asstring);
        edtContactPhone2.text := trim(fieldbyname('ContactPhone2').asstring);
        edtContactAddress1.text := trim(fieldbyname('ContactAddress1').asstring);
        edtContactAddress2.text := trim(fieldbyname('ContactAddress2').asstring);
        edtContactAddress3.text := trim(fieldbyname('ContactAddress3').asstring);
        edtContactAddress4.text := trim(fieldbyname('ContactAddress4').asstring);

        fraContactCountry.DisableEvents;
        try
          fraContactCountry.Code := trim(fieldbyname('ContactCountry').asstring);
        finally
          fraContactCountry.EnableEvents;
        end;

        edtName.text := trim(fieldbyname('Name').asstring);
        edtKennitala.text := trim(fieldbyname('CustPId').asstring);
        edtAddress1.text := trim(fieldbyname('Address1').asstring);
        edtAddress2.text := trim(fieldbyname('Address2').asstring);
        edtAddress3.text := trim(fieldbyname('Address3').asstring);
        edtCustomerEmail.text := trim(fieldbyname('CustomerEmail').asstring);
        edtCustomerWebSite.text := trim(fieldbyname('CustomerWebSite').asstring);

        edtTel1.text := trim(fieldbyname('Tel1').asstring);
        edtTel2.text := trim(fieldbyname('Tel2').asstring);
        edtFax.text := trim(fieldbyname('Fax').asstring);

        dtArrival.Date := fieldbyname('ArrivalDate').asDateTime;
        dtDeparture.Date := fieldbyname('DepartureDate').asDateTime;

        memInformation.Lines.text := trim(fieldbyname('Information').asstring);
        memPMInfo.Lines.text := trim(fieldbyname('PMInfo').asstring);

        fraLookupMarketSegment.Code := trim(fieldbyname('MarketSegment').asstring);

        edtInvRefrence.text := trim(fieldbyname('invRefrence').asstring);
        edtBookingId.Text := edtInvRefrence.text;
        OutOfOrderBlocking := fieldbyname('outOfOrderBlocking').AsBoolean;

        SetMarketItemIndex(fieldbyname('market').asString);

        FCreatedBy := fieldbyname('staff').asString;
        FCreatedOn := DateTimeToStr(rSet.fieldbyname('dtCreated').AsDateTime) + ' UTC';
      end;
    end;

    Display_rGrid(zRoomReservation);
    FAllRoomsBreakfastChanged := false;

    d.RR_GetMemoBothTextForRoom(zRoomReservation, HiddenInfo, ChannelRequest);
    gbxRoomInformation.caption := 'Notes for Room : ' + mRoomsRoom.asstring;
    memRoomNotes.Lines.text := HiddenInfo;
    memRequestFromChannel.Lines.text := ChannelRequest;

    zInitDateFrom := dtArrival.Date;
    zInitDateTo := dtDeparture.Date;

    UpdateInfoLabels;
    UpdateStateActions;
  finally
    FreeAndNil(rSet);
    mRooms.EnableControls;
    screen.Cursor := crDefault;
    pnlDataWait.Hide;
  end;
end;

procedure TfrmReservationProfile.SetMarketItemIndex(const aMarket: string);
begin
  cbxMarket.ItemIndex := TReservationMarketType.FromDBString(aMarket, mtUnknown).ToItemIndex;
end;

procedure TfrmReservationProfile.rgrinvoicePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  case AButtonIndex of
    0:
      begin
        try
          EditInvoice(zReservation, zRoomReservation, TInvoiceType.itDebitInvoice, 0, false);
        finally
          Display_rGrid(zRoomReservation);
        end;
      end;
    1:
      begin
        try
          EditInvoice(zReservation, 0, TInvoiceType.itDebitInvoice, 0, false);
        finally
          Display_rGrid(zRoomReservation);
        end;
      end;
  end;
end;

procedure TfrmReservationProfile.sButton2Click(Sender: TObject);
begin
  //UpdateAllRoomsBreakfast;
end;

procedure TfrmReservationProfile.sButton4Click(Sender: TObject);
var
  frm: TfrmResGuestList;
begin
  // guestlist
  frm := TfrmResGuestList.Create(nil);
  try
    frm.zReservation := zReservation;
    frm.ShowModal;
  finally
    frm.free;
  end;
end;

procedure TfrmReservationProfile.acGuestDetailsClick(Sender: TObject);
var
  rSet: TRoomerDataSet;
  lRoomres: integer;
begin
  lRoomRes := mRooms['RoomReservation'];
  if (NOT mRooms.Eof) AND OpenGuestCheckInForm(lRoomres, false) then
  begin
    rSet := CreateNewDataSet;
    try
      if hData.rSet_bySQL(rSet, 'SELECT Name FROM persons WHERE MainName=1 AND RoomReservation=' + inttostr(lRoomres)) then
      begin
        mRooms.Edit;
        mRooms['GuestName'] := rSet['Name'];
        mRooms.Post;
      end;
      getGuestData(lRoomres);
      UpdateGuestDetails(lRoomres);
    finally
      FreeAndNil(rSet);
    end;
  end;
end;

procedure TfrmReservationProfile.acRoomResActionUpdate(Sender: TObject);
begin
  TAction(Sender).Enabled := mRooms.Active and (mRooms.RecordCount > 0);
end;

procedure TfrmReservationProfile.btnGroupsClick(Sender: TObject);
begin
  if GroupGuests(zReservation, zRoomreservation) then
  begin
    Display_rGrid(zRoomReservation);
    getGuestData(zRoomreservation);
    UpdateGuestDetails(zRoomreservation);
  end;
end;


procedure TfrmReservationProfile.SetOutOfOrderBlocking(const Value: Boolean);
begin
  FOutOfOrderBlocking := Value;

  sPanel1.Visible := FOutOfOrderBlocking;
  pnlContact.Visible := NOT FOutOfOrderBlocking;
  pnlTopButtons.Visible := NOT FOutOfOrderBlocking;
  GuestsTab.TabVisible := NOT FOutOfOrderBlocking;
  sTabSheet2.TabVisible := NOT FOutOfOrderBlocking;
  InvoicesTab.TabVisible := NOT FOutOfOrderBlocking;
  Panel9.Visible := NOT FOutOfOrderBlocking;
  cxSplitter1.Visible := NOT FOutOfOrderBlocking;
  gbxGuest.Visible := NOT FOutOfOrderBlocking;
  GroupBox2.Visible := NOT FOutOfOrderBlocking;
  gbxRoomInformation.Visible := NOT FOutOfOrderBlocking;
  gbxResProperties.Visible := NOT FOutOfOrderBlocking;
  gbxStatus.Visible := NOT FOutOfOrderBlocking;

  if FOutOfOrderBlocking then
  begin
    Label2.caption := GetTranslatedText('shTx_FrmMakeReservationQuick_OutOfOrderStartDate');
    Label3.caption := GetTranslatedText('shTx_FrmMakeReservationQuick_OutOfOrderEndDate');
  end
  else
  begin
    RoomerLanguage.TranslateThisControl(self, Label2);
    RoomerLanguage.TranslateThisControl(self, Label3);
  end;

  tvRoomsPackage.Visible := NOT FOutOfOrderBlocking;
  tvRoomsGuestName.Visible := true;
  tvRoomsRoomClassDescription.Visible := NOT FOutOfOrderBlocking;
  tvRoomsGuestCount.Visible := NOT FOutOfOrderBlocking;
  tvRoomsCurrency.Visible := NOT FOutOfOrderBlocking;
  tvRoomsbreakfastText.Visible := NOT FOutOfOrderBlocking;
  tvRoomsBreakfastPrice.Visible := NOT FOutOfOrderBlocking;
  tvRoomsaccountTypeText.Visible := NOT FOutOfOrderBlocking;
  rgrinvoice.Visible := NOT FOutOfOrderBlocking;
  tvRoomsTotalUnpaidRoomRent.Visible := NOT FOutOfOrderBlocking;
  tvRoomsDiscountUnpaidRoomRent.Visible := NOT FOutOfOrderBlocking;
  tvRoomsunPaidRoomRent.Visible := NOT FOutOfOrderBlocking;
  tvRoomsunpaidRentNights.Visible := NOT FOutOfOrderBlocking;
  tvRoomsunpaidRentPrice.Visible := NOT FOutOfOrderBlocking;
  tvRoomsPriceCode.Visible := NOT FOutOfOrderBlocking;
  tvRoomsunPaidItems.Visible := NOT FOutOfOrderBlocking;

end;

procedure TfrmReservationProfile.UpdateProfile;
var
  rSet: TRoomerDataSet;
  s: string;
  Numdays: Integer;
begin
  Numdays := trunc(dtDeparture.Date) - trunc(dtArrival.Date);

  if Numdays < 1 then
  begin
    showmessage(GetTranslatedText('shTx_ReservationProfile_MustBeOver1Day'));
    exit;
  end;

  rSet := CreateNewDataSet;
  try
    rSet.PrimaryKeyField := 'Reservation';
    d.roomerMainDataSet.SystemStartTransaction;
    try

      rSet.CommandType := cmdText;

      s := format(select_ReservationProfile_UpdateProfile, [zReservation]);
      hData.rSet_bySQL(rSet, s);

      rSet.Edit;
      rSet.fieldbyname('Customer').asstring := fraCustomerPanel.Code;
      rSet.fieldbyname('Name').asstring := edtName.text;
      rSet.fieldbyname('CustPID').asstring := edtKennitala.text;
      rSet.fieldbyname('Address1').asstring := edtAddress1.text;
      rSet.fieldbyname('Address2').asstring := edtAddress2.text;
      rSet.fieldbyname('Address3').asstring := edtAddress3.text;
      rSet.fieldbyname('CustomerWebSite').asstring := edtCustomerWebSite.text;
      rSet.fieldbyname('CustomerEmail').asstring := edtCustomerEmail.text;
      rSet.fieldbyname('Country').asstring := fraContactCountry.Code;
      rSet.fieldbyname('MarketSegment').asstring := fraLookupMarketSegment.Code;
      rSet.fieldbyname('Tel1').asstring := edtTel1.text;
      rSet.fieldbyname('Fax').asstring := edtFax.text;
      rSet.fieldbyname('Tel2').asstring := edtTel2.text;
      rSet.fieldbyname('Arrival').asstring := _db(TDate(dtArrival.Date), false);
      rSet.fieldbyname('Departure').asstring := _db(TDate(dtDeparture.Date), false);
      rSet.fieldbyname('Information').asstring := memInformation.Lines.text;
      rSet.fieldbyname('PMInfo').asstring := memPMInfo.Lines.text;
      rSet.fieldbyname('ContactName').asstring := edtContactName.text;
      rSet.fieldbyname('ContactEmail').asstring := edtContactEmail.text;
      rSet.fieldbyname('ContactPhone').asstring := edtContactPhone.text;
      rSet.fieldbyname('ContactPhone2').asstring := edtContactPhone2.text;
      rSet.fieldbyname('ContactAddress1').asstring := edtContactAddress1.text;
      rSet.fieldbyname('ContactAddress2').asstring := edtContactAddress2.text;
      rSet.fieldbyname('ContactAddress3').asstring := edtContactAddress3.text;
      rSet.fieldbyname('ContactAddress4').asstring := edtContactAddress4.text;
      rSet.fieldbyname('ContactCountry').asstring := fraContactCountry.Code;
      rSet.fieldbyname('invRefrence').asstring := edtInvRefrence.text;
      rSet.Post;

      // Update invReference on open invoices
      s := '';
      s := s + 'update invoiceheads '#10;
      s := s + ' set invRefrence = '''' '#10;
      s := s + ' where invoicenumber = -1 and reservation = %d '#10;
      s := format(s, [zReservation]);

      if cmd_bySQL(s) then
        d.roomerMainDataSet.SystemCommitTransaction
      else
        raise EReservationReferenceSaveFailed.CreateFmt('Failed saving new reference [%s] for reservation [%d]', [edtInvRefrence.text, zReservation]);

    except
      d.roomerMainDataSet.SystemRollbackTransaction;
      raise;
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

// ***********************************************************************************
//
// Hidden Memo
//
// ************************************************************************************

procedure TfrmReservationProfile.btnChangeNationalitiesAllGuestsClick(Sender: TObject);
var
  s: string;
  fra: TfraCountryPanel;
  lMethod: integer;
  lPerson: integer;
  lAnswer: integer;
begin
  fra := fraGuestNationality;

  s := format(GetTranslatedText('shTx_ReservationProfile_ChangeNationalityConfirm'), [fra.Description]);
  lAnswer := MessageDlg(s, mtConfirmation, [mbYes, mbNo, mbAll], 0, mbYes);

  lPerson := 0;
  case lAnswer of
    mrYes:  begin
              lMethod := 1; // all persons in roomreservation
            end;
    mrNo:  begin // one person
              if Sender = btnChangeNationality then
                Exit; // No need to change mainguest when btn is used
              lMethod := 0;
              mAllGuests.Locate('RoomReservation;MainName', VarArrayOf([mRoomsReservation.AsInteger, True]), []);
              lPerson := mAllGuestsPerson.Asinteger
            end;
    mrAll:  begin
              lMethod := 2; // all persons in reservation
            end;
    else
      Exit;
  end;

  if not d.ChangeNationality(fra.Code, mRoomsReservation.Asinteger, mRoomsRoomReservation.Asinteger, lPerson, lMethod) then
    showmessage(GetTranslatedText('shTx_ReservationProfile_NationalityChangeFailed'))
  else
    getGuestData(mRoomsRoomReservation.Asinteger, True);
end;

procedure TfrmReservationProfile.btnChangeCountryAllGuestsClick(Sender: TObject);
var
  s: string;
  fra: TfraCountryPanel;
  lMethod: integer;
  lPerson: integer;
  lAnswer : integer;
begin
  fra := fraGuestCountry;

  s := format(GetTranslatedText('shTx_ReservationProfile_ChangeCountryConfirm'), [fra.Description]);
  lAnswer := MessageDlg(s, mtConfirmation, [mbYes, mbNo, mbAll], 0, mbYes);

  lPerson := 0;
  case lAnswer of
    mrYes:  begin
              lMethod := 1; // all persons in roomreservation
            end;
    mrNo:  begin // one person
              if Sender = btnChangeCountry then
                Exit; // No need to change mainguest when btn is used
              lMethod := 0;
              mAllGuests.Locate('RoomReservation;MainName', VarArrayOf([mRoomsRoomReservation.AsInteger, True]), []);
              lPerson := mAllGuestsPerson.Asinteger
            end;
    mrAll:  begin
              lMethod := 2; // all persons in reservation
            end;
    else
      Exit;
  end;

  if not d.ChangeCountry(fra.Code, mRoomsReservation.Asinteger, mRoomsRoomReservation.Asinteger, lPerson, lMethod) then
    showmessage(GetTranslatedText('shTx_ReservationProfile_CountryChangeFailed'))
  else
    getGuestData(mRoomsRoomReservation.Asinteger, True);

end;


procedure TfrmReservationProfile.btnClipboardToHinndenMemoClick(Sender: TObject);
var
  s: string;
  selection: string;
  id: Integer;
begin
  selection := ClipBoardText;
  if selection = '' then
    exit;
  s := GetTranslatedText('shTx_ReservationProfile_CopyHidden') + #10#10 + selection;
  if MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    id := d.hiddenInfo_Exists(zReservation, 1);
    d.hiddenInfo_Append(id, selection, zReservation);
  end;
end;

// ********************************************************************************************
//
// Edits Dbl-click to select
//
// ********************************************************************************************

procedure TfrmReservationProfile.edtAllBreakfastPriceChange(Sender: TObject);
begin
  FAllRoomsBreakfastChanged := true;
end;

procedure TfrmReservationProfile.evtCustomerChangedAndValid(Sender: TObject);
var
  CustomerHolderEX: recCustomerHolderEX;
begin
  CustomerHolderEX := hData.Customer_GetHolder(fraCustomerPanel.Code);
  edtName.text := InvoiceName(0, CustomerHolderEX.DisplayName, CustomerHolderEX.CustomerName);
  edtKennitala.text := CustomerHolderEX.PID;
  edtAddress1.text := CustomerHolderEX.Address1;
  edtAddress2.text := CustomerHolderEX.Address2;
  edtAddress3.text := CustomerHolderEX.Address3;
  edtTel1.text := CustomerHolderEX.Tel1;
  edtTel2.text := CustomerHolderEX.Tel2;
  edtFax.text := CustomerHolderEX.Fax;
  edtCustomerEmail.text := CustomerHolderEX.EmailAddress;
  edtCustomerWebSite.text := CustomerHolderEX.HomePage;
  edtContactName.text := CustomerHolderEX.ContactPerson;
  edtContactEmail.text := CustomerHolderEX.ContactEmail;
  edtContactPhone.text := CustomerHolderEX.ContactPhone;
end;

// **************************************************************************************
//
//
// **************************************************************************************

procedure TfrmReservationProfile.UpdateAllRoomsBreakfast;
var
  s: string;
  lNewBreakfastType: TBreakfastType;
begin
  if not FAllROomsBreakfastChanged then
    Exit;

  lNewBreakfastType := TBreakfastType.FromItemIndex(cbxBreakfastAllRooms.ItemIndex);
  pnlBreakfastPrice.Visible := (lNewBreakfastType = TBreakfastType.Excluded);
  if not pnlBreakfastPrice.Visible then
    edtAllBreakfastPrice.Value := 0;

  if cbxBreakfastAllRooms.ItemIndex = -1 then // Mixed
    Exit;

  s := Trim(GetTranslatedText('shTx_ReservationProfile_ChangeAllRooms')) + ' ';
  s := s + lNewBreakfastType.AsReadableString;

  if lNewBreakfastType = TBreakfastType.Excluded then
    s := s + Format(' (%s)', [TAmount(edtAllBreakfastPrice.Value).AsDisplayStringWithCode]);

  if MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    d.UpdateRoomResBreakfastState(zReservation, 0, TBreakfastType.FromItemIndex(cbxBreakfastAllRooms.ItemIndex), edtAllBreakfastPrice.Value);
    Display_rGrid(zRoomReservation);
  end
  else
  begin
    SetAllRoomsBreakfastItemindex;
  end;

  FAllROomsBreakfastChanged := False;

end;

function TfrmReservationProfile.UpdateRoomBreakfasts: boolean;
var
  bfState: TBreakfastType;
begin
  bfState := TBreakfastType.FromDBString(mRoomsBreakFast.AsString);
  if bfState <> TBreakfastType.Excluded then
    mRoomsBreakfastPrice.Clear;

  Result := d.UpdateRoomResBreakfastState(zReservation, mRoomsRoomReservation.AsInteger, bfState, mRoomsBreakfastPrice.AsFloat);
end;

procedure TfrmReservationProfile.UpdateMarket;
begin
  if cbxMarket.ItemIndex >= 0 then
    d.UpdateReservationMarket(zReservation, TReservationmarketType(cbxMarket.itemIndex));
end;

procedure TfrmReservationProfile.UpdatePaymentDetails;
var
  s: string;
  GroupAccount: Boolean;
begin
  if cbxPaymentdetails.ItemIndex = 0 then
  begin
    Display_rGrid(zRoomReservation);
    exit;
  end;

  GroupAccount := cbxPaymentdetails.ItemIndex = 2;

  s := GetTranslatedText('shTx_ReservationProfile_ChangeAllRooms');
  if GroupAccount then
    s := s + GetTranslatedText('shTx_ReservationProfile_GroupAccount')
  else
    s := s + GetTranslatedText('shTx_ReservationProfile_RoomAccount');

  if MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    d.UpdateGroupAccountAll(zReservation, 0, zRoomReservation, GroupAccount);
    Display_rGrid(zRoomReservation);
  end;

  UpdateInfoLabels;
end;

procedure TfrmReservationProfile.SetAllRoomsBreakfastItemindex;
var
  lBreakfastAllTheSame: boolean;
  lBreakfastPriceAllTheSame: boolean;
  lBreakFast: string;
  lBreakfastPrice: TAmount;
  bm: TBookmark;
begin
  lBreakfastAllTheSame := true;
  lBreakfastPriceAllTheSame := true;
  lBreakFast := '';
  lBreakfastPrice := -1;
  bm := mRooms.Bookmark;

  mRooms.DisableControls;
  try
    mRooms.First;
    while not mRooms.Eof do
    begin
      if lBreakfastAllTheSame then
      begin
        if lBreakfast = '' then
          lBreakfast := mRoomsBreakFast.AsString
        else
          lBreakfastAllTheSame := lBreakFast = mRoomsBreakFast.AsString;

        if lBreakfastPriceAllTheSame and (lBreakfast = TBreakfastType.Excluded.ToDBString) then
          if lBreakfastPrice < 0 then
            lBreakfastPrice := mRoomsBreakFastPrice.AsFloat
          else
            lBreakfastPriceAllTheSame := (lBreakfastPrice = mRoomsBreakFastPrice.AsFloat);
      end;
      mRooms.Next;
    end;
  finally
    mRooms.Bookmark := bm;
    mRooms.EnableControls;
  end;

  if lBreakfastAllTheSame then
  begin
    cbxBreakfastAllRooms.ItemIndex := TBreakfastType.fromDBString(lBreakFast).ToItemIndex;
    if lBreakfastPriceAllTheSame then
      edtAllBreakfastPrice.Value := lBreakfastPrice
    else
      edtAllBreakfastPrice.Value := 0;
  end
  else
  begin
    cbxBreakfastAllRooms.ItemIndex := -1;
    edtAllBreakfastPrice.Value := 0;
  end;

  cbxBreakfastAllRoomsChange(nil);

end;

procedure TfrmReservationProfile.SetPaymentDetailItemindex(sStatus: string);
var
  ch: Char;
begin
  if sStatus = '' then
  begin
    sStatus := d.isMixedPaymentdetails(zReservation);
  end;
  if strIsDiff(sStatus) then
  begin
    cbxPaymentdetails.ItemIndex := 0;
    exit;
  end;
  ch := sStatus[1];
  if ch = '0' then
    cbxPaymentdetails.ItemIndex := 1
  else
    cbxPaymentdetails.ItemIndex := 2;
  cbxPaymentdetails.Update;
  cbxPaymentdetails.Invalidate;
end;

procedure TfrmReservationProfile.cbxStatusPanelExit(Sender: TObject);
begin
  UpdateAllRoomsBreakfast;
end;

procedure TfrmReservationProfile.cbxBreakfastAllRoomsChange(Sender: TObject);
var
  lNewBreakfastType: TBreakfastType;
begin
  FAllRoomsBreakfastChanged := true;
  lNewBreakfastType := TBreakfastType.FromItemIndex(cbxBreakfastAllRooms.ItemIndex);
  pnlBreakfastPrice.Visible := (lNewBreakfastType = TBreakfastType.Excluded);
  if not pnlBreakfastPrice.Visible then
  begin
    edtAllBreakfastPrice.Value := 0;
  end;
end;

procedure TfrmReservationProfile.cbxMarketCloseUp(Sender: TObject);
begin
  UpdateMarket;
end;

procedure TfrmReservationProfile.cbxPaymentdetailsCloseUp(Sender: TObject);
begin
  UpdatePaymentDetails
end;

procedure TfrmReservationProfile.chkShowAllGuestsClick(Sender: TObject);
begin
  if chkShowAllGuests.checked then
  begin
    lvAllGuests.GridView.Focused := true;
    btnExpand.enabled := false;
    btnCollapse.enabled := false;
  end
  else
  begin
    lvGuestRooms.GridView.Focused := true;
    btnExpand.enabled := true;
    btnCollapse.enabled := true;
  end;
end;

procedure TfrmReservationProfile.cxButton2Click(Sender: TObject);
var
  sFilename: string;
  s: string;
begin
  datetimeTostring(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_Guests' + inttostr(zReservation);
  tvGuestRooms.BeginUpdate();
  tvGuestRooms.ViewData.Collapse(true);
  tvGuestRooms.EndUpdate;

  ExportGridToExcel(sFilename, grGuests, false, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil,
    sw_shownormal);
end;

procedure TfrmReservationProfile.cxButton3Click(Sender: TObject);
var
  arrival: TDate;
  departure: TDate;
//  s: string;

begin

  arrival := dtArrival.Date;
  departure := dtDeparture.Date;

  if g.openResDates(zReservation, 0, '', arrival, departure, 1) then
  begin
    dtArrival.Date := arrival;
    dtDeparture.Date := departure;
    Display_rGrid(0);
//    s := '';
//    s := s + 'UPDATE `reservations` '#10;
//    s := s + 'SET '#10;
//    s := s + '`Arrival` = %s, '#10;;
//    s := s + '`Departure` = %s '#10;
//    s := s + 'WHERE reservation = %d ';
//    s := format(s, [_db(arrival, true), _db(departure, true), zReservation]);
//    if not cmd_bySQL(s) then
//    begin
//    end;
  end;
  BringToFront;
end;

procedure TfrmReservationProfile.acRoomDocumentsClick(Sender: TObject);
begin
  tvRoomsDocumentsPropertiesButtonClick(Sender, 0);
end;

procedure TfrmReservationProfile.acJumpToRoomClick(Sender: TObject);
begin
  Hide;
  frmMain.GoToDateAndRoom(mRoomsArrival.AsDateTime, mRoomsRoomReservation.asInteger);
  Close;
end;


procedure TfrmReservationProfile.acManagePaycardsExecute(Sender: TObject);
begin
  ManagePaymentCards(zReservation, zRoomReservation);
end;

// ******************************************************************************
// Room Functions
// ******************************************************************************

procedure TfrmReservationProfile.acChangeRoomTypeExecute(Sender: TObject);
var
  s: String;
begin
  if copy(mRoomsRoom.asstring, 1, 1) = '<' then
  begin
    s := changeNoRoomRoomtypeReturnSelection(zReservation, zRoomReservation, trim(mRoomsRoomtype.asstring));
    if s <> '' then
    begin
      mRooms.Edit;
      try
        mRoomsRoomtype.asstring := s;
        mRooms.Post;
      except
        mRooms.Cancel;
        raise;
      end;
    end;
  end;
end;

procedure TfrmReservationProfile.acChangeRoomTypeUpdate(Sender: TObject);
begin
  acChangeRoomType.Visible := mRoomsRoom.asstring.StartsWith('<');
end;

procedure TfrmReservationProfile.acCheckinReservationExecute(Sender: TObject);
begin
  if FReservationChangeStateHandler.ChangeState(rsGuests) then
    Display;
end;

procedure TfrmReservationProfile.acCheckinRoomExecute(Sender: TObject);
var
  lResChanger: TRoomReservationStateChangeHandler;
begin

  lResChanger := FReservationChangeStateHandler.RoomStateChangeHandler[mRoomsRoomReservation.AsInteger];
  if lResChanger.ChangeState(rsGuests) then
    Display_rGrid(mRoomsRoomReservation.AsInteger);

end;

procedure TfrmReservationProfile.acCheckoutReservationExecute(Sender: TObject);
begin
  if FReservationChangeStateHandler.ChangeState(rsDeparted) then
    Display;
end;

procedure TfrmReservationProfile.acCheckoutRoomExecute(Sender: TObject);
var
  lResChanger: TRoomReservationStateChangeHandler;
begin
  lResChanger := FReservationChangeStateHandler.RoomStateChangeHandler[mRoomsRoomReservation.AsInteger];
  if lResChanger.ChangeState(rsDeparted) then
     Display_rGrid(mRoomsRoomReservation.AsInteger);
end;

procedure TfrmReservationProfile.PropagateValue(aDirection: TPropagateDirection);
var
  fp: TGridColumnFieldValuePropagator;
begin
  if mnuRoomColumn.tag >= 0 then
  begin
    fp := TGridColumnFieldValuePropagator.Create;
    try
      fp.Propagate(tvRooms.Columns[mnuRoomColumn.Tag], aDirection);
    finally
      fp.Free;
    end;
  end;
end;

procedure TfrmReservationProfile.acCopyValueAllExecute(Sender: TObject);
begin
  PropagateValue(pdAll);
end;

procedure TfrmReservationProfile.acCopyValueDownExecute(Sender: TObject);
begin
  PropagateValue(pdDown);
end;

procedure TfrmReservationProfile.acCopyValueUpExecute(Sender: TObject);
begin
  PropagateValue(pdUp);
end;

procedure TfrmReservationProfile.acPasteIntoDocumentsExecute(Sender: TObject);
begin
  if DropComboTarget1.CanPasteFromClipboard then
    DropComboTarget1.PasteFromClipboard;
end;

procedure TfrmReservationProfile.acPasteIntoHiddenMemoExecute(Sender: TObject);
var
  s: string;
  selection: string;
  id: Integer;
begin
  selection := ClipBoardText;
  if selection = '' then
    exit;
  s := GetTranslatedText('shTx_ReservationProfile_CopyHidden') + #10#10 + selection;
  if MessageDlg(s, mtConfirmation, [mbYes, mbNo], 0) = mrYes then
  begin
    id := d.hiddenInfo_Exists(zReservation, 1);
    d.hiddenInfo_Append(id, selection, zReservation);
  end;
end;

procedure TfrmReservationProfile.acRemoveRoomUpdate(Sender: TObject);
begin
  acRemoveRoom.Enabled := mRooms.Active and (mRooms.RecordCount > 1);
end;

procedure TfrmReservationProfile.acShowDocumentsExecute(Sender: TObject);
begin
  StaticResources('Reservation Resources', [TResourceType.rtBooking], TResourceAccessType.ratRestricted, inttostr(zReservation));
end;

procedure TfrmReservationProfile.acShowHiddenMemoExecute(Sender: TObject);
begin
  g.openHiddenInfo(zReservation, 1);
end;

procedure TfrmReservationProfile.AddNewRoom;
var
  Currency: string;
  RoomType: string;

  Customer: string;
  ReservationName: string;

  RoomNumber: string;
  arrival: TDate;
  departure: TDate;

  iReservation: Integer;
  iRoomreservation: Integer;

  numGuests: Integer;
  numInfants: Integer;
  numChildren: Integer;

  PriceCode: string;
  AverageRate: double;
  AvrageDiscount: double;
  rateCount: Integer;

  useInNationalReport: Boolean;

  isGroupInvoice: Boolean;
  BreakfastType: TBreakfastType;

  RoomPMInfo: string;
  RoomHiddenInfo: string;

  invoiceHeadData: recInvoiceHeadHolder;
  roomReservationData: recRoomReservationHolder;
  roomsDateData: recRoomsDateHolder;
  personData: recPersonHolder;

  guestName: string;
  iPerson: Integer;

  Address1: string;
  Address2: string;
  Address3: string;
  Address4: string;
  Country: string;

  temp: String;
  ii: Integer;

  dayCount: Integer;
  tmpDate: TDate;

  RoomReservationRentHolder: recRoomReservationRentHolder;

  oldRoomreservation: Integer;

  ExecutionPlan: TRoomerExecutionPlan;
  theData: recRoomTypeHolder;
  newRoomType: String;
  lExpectedTOA: string;
  lExpectedCOT: string;
  lCHildrenCOunt: integer;
  lInfantCount: integer;
begin
  // Add roomreservation as noroom

  initRoomTypeHolder(theData);

  theData.RoomType := mRooms['RoomType'];
  if openRoomTypes(actLookup, theData) then
    newRoomType := theData.RoomType
  else
    exit;

  if g.qWarnWhenOverbooking then
    if NOT IsAvailabilityThere('', newRoomType, mRooms['Arrival'], mRooms['Departure']) then
      exit;

  ExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    try
      ExecutionPlan.BeginTransaction;

      iReservation := zReservation;
      oldRoomreservation := zRoomReservation;
      iRoomreservation := RR_SetNewID();

      Customer := trim(fraCustomerPanel.Code );
      ReservationName := edtName.text;
      Address1 := edtAddress1.text;
      Address2 := edtAddress1.text;
      Address3 := edtAddress1.text;
      Address4 := edtAddress1.text;
      Country := fraContactCountry.Code;

      Currency := mRoomsCurrency.asstring;
      isGroupInvoice := mRoomsisGroupAccount.AsBoolean;
      BreakfastType := TBreakfastType.FromDBString(mRoomsBreakFast.AsString);
      guestName := mRoomsGuestName.asstring;

      arrival := mRoomsArrival.AsDateTime;
      departure := mRoomsDeparture.AsDateTime;
      lExpectedTOA := mRoomsExpectedTimeOfArrival.AsString;
      lExpectedCOT := mRoomsExpectedCheckoutTime.AsString;
      dayCount := trunc(departure) - trunc(arrival);
      lChildrenCount := mRoomschildrencount.AsInteger;
      lInfantCount := mRoomsinfantcount.AsInteger;

      RoomType := newRoomType;

      numGuests := theData.NumberGuests; // mRoomsGuestCount.asInteger;
      numChildren := 0;
      numInfants := 0;

      RoomReservationRentHolder := RR_GetAvrageRent(oldRoomreservation);

      PriceCode := RoomReservationRentHolder.PriceType;
      AverageRate := RoomReservationRentHolder.averageRate;
      AvrageDiscount := RoomReservationRentHolder.Discount;
      rateCount := 1;

      useInNationalReport := true;
      RoomNumber := '<' + inttostr(iRoomreservation) + '>';
      RoomPMInfo := '';
      RoomHiddenInfo := '';

      initRoomReservationHolderRec(roomReservationData);
      roomReservationData := SP_GET_RoomReservation(iRoomreservation);

      roomReservationData.roomReservation := iRoomreservation;
      roomReservationData.Room := RoomNumber;
      roomReservationData.reservation := iReservation;
      // new reservation  always start as a rsReservation
      roomReservationData.status := rsReservation.AsStatusChar;
      roomReservationData.GroupAccount := isGroupInvoice;
      roomReservationData.Breakfast := BreakfastType;
      roomReservationData.Currency := Currency;
      roomReservationData.PriceType := PriceCode;
      roomReservationData.arrival := arrival;
      roomReservationData.departure := departure;
      roomReservationData.RoomType := RoomType;
      roomReservationData.PMInfo := RoomPMInfo;
      roomReservationData.HiddenInfo := RoomHiddenInfo;
      roomReservationData.rrIsNoRoom := true;
      roomReservationData.rrRoomAlias := '';
      roomReservationData.rrRoomTypeAlias := RoomType;
      roomReservationData.Discount := AvrageDiscount;
      roomReservationData.useInNationalReport := useInNationalReport;
      roomReservationData.RoomRentPaid1 := 0.00;
      roomReservationData.RoomRentPaid2 := 0.00;
      roomReservationData.RoomRentPaid3 := 0.00;
      roomReservationData.numGuests := numGuests;
      roomReservationData.numInfants := numInfants;
      roomReservationData.numChildren := numChildren;
      roomReservationData.averageRate := AverageRate;
      roomReservationData.rateCount := rateCount;
      roomReservationData.Discount := AvrageDiscount;
      roomReservationData.RoomPrice1 := 0.00;
      roomReservationData.Price1From := _db(arrival, false);
      roomReservationData.Price1To := _db(departure, false);
      roomReservationData.RoomPrice2 := 0.00;
      roomReservationData.Price2From := _db(arrival, false);
      roomReservationData.Price2To := _db(arrival, false);
      roomReservationData.RoomPrice3 := 0.00;
      roomReservationData.Price3From := _db(arrival, false);
      roomReservationData.Price3To := _db(arrival, false);
      roomReservationData.Hallres := 0;
      roomReservationData.ExpectedTimeOfArrival := lExpectedTOA;
      roomReservationData.ExpectedCheckoutTime := lExpectedCOT;
      roomReservationData.numChildren := lCHildrenCOunt;
      roomReservationData.numInfants := lInfantCount;

      ExecutionPlan.AddExec(SQL_UPDATE_RoomReservation(roomReservationData));

      initInvoiceHeadHolderRec(invoiceHeadData);
      invoiceHeadData.reservation := iReservation;
      invoiceHeadData.roomReservation := iRoomreservation;
      invoiceHeadData.SplitNumber := 0;
      invoiceHeadData.InvoiceNumber := -1;
      invoiceHeadData.InvoiceDate := _db(TDate(now), false);
      invoiceHeadData.Customer := Customer;
      invoiceHeadData.name := ReservationName + ', ' + guestName;
      invoiceHeadData.Address1 := Address1;
      invoiceHeadData.Address2 := Address2;
      invoiceHeadData.Address3 := Address3;
      invoiceHeadData.Address4 := Address4;
      invoiceHeadData.Country := Country;
      invoiceHeadData.Total := 0.00;
      invoiceHeadData.TotalWOVAT := 0.00;
      invoiceHeadData.TotalVAT := 0.00;
      invoiceHeadData.TotalBreakFast := 0.00;
      invoiceHeadData.ExtraText := '';;
      invoiceHeadData.Finished := false;
      invoiceHeadData.CreditInvoice := -1;
      invoiceHeadData.OriginalInvoice := -1;
      invoiceHeadData.InvoiceType := 1;
      invoiceHeadData.ihTmp := '';
      invoiceHeadData.CustPID := edtKennitala.text;
      invoiceHeadData.RoomGuest := guestName;
      invoiceHeadData.ihDate := Date;
      invoiceHeadData.ihInvoiceDate := Date;
      invoiceHeadData.ihConfirmDate := _DBDateToDateTimeNoMs('1900-01-01 00:00:00');
      invoiceHeadData.ihPayDate := Date;
      invoiceHeadData.ihStaff := '';
      invoiceHeadData.ihCurrency := Currency;
      invoiceHeadData.ihCurrencyRate := 1.00;
      invoiceHeadData.ReportDate := '';
      invoiceHeadData.ReportTime := '';

      ExecutionPlan.AddExec(SQL_INS_InvoiceHead(invoiceHeadData));

      initRoomsDateHolderRec(roomsDateData);

      tmpDate := arrival;
      for ii := 1 to dayCount do
      begin
        roomsDateData := GET_RoomsDate(tmpDate, oldRoomreservation);
        roomsDateData.roomReservation := iRoomreservation;
        roomsDateData.Room := RoomNumber;
        roomsDateData.RoomType := RoomType;
        roomsDateData.isNoRoom := true;
        roomsDateData.Paid := false;

        ExecutionPlan.AddExec(SQL_INS_RoomsDate(roomsDateData));
        tmpDate := tmpDate + 1;
      end;

      iPerson := PE_SetNewID();

      initPersonHolder(personData);
      personData.Person := iPerson;
      personData.roomReservation := iRoomreservation;
      personData.reservation := iReservation;
      personData.name := guestName;
      personData.Surname := ReservationName;
      personData.Address1 := Address1;
      personData.Address2 := Address2;
      personData.Address3 := Address3;
      personData.Address4 := Address4;
      personData.Country := Country;
      personData.Company := Customer;
      personData.GuestType := RoomType;
      personData.Information := '';
      personData.PID := '';
      personData.MainName := true;
      personData.Customer := Customer;
      personData.peTmp := '';
      personData.hgrID := -1;
      personData.HallReservation := -1;

      ExecutionPlan.AddExec(SQL_INS_Person(personData));

      if numGuests > 1 then
      begin
        for ii := 2 to numGuests do
        begin
          iPerson := PE_SetNewID();

          personData.Person := iPerson;
          personData.name := 'RoomGuest';
          personData.MainName := false;
          // rest of the Guests
          ExecutionPlan.AddExec(SQL_INS_Person(personData));
        end;
      end;

      temp := format
        ('(AddNewRoom3) Add a room to reservation Reservation=%d, RoomReservation=%d, Room=%s, RoomType=%s, TO ArrDate=%s, DepDate=%s',
        [iReservation, iRoomreservation, RoomNumber, RoomType, DateToSqlString(arrival), DateToSqlString(departure)]);
      d.roomerMainDataSet.SystemChangeAvailability(RoomType, arrival, departure - 1, true, temp); // minnka frambo�

      if ExecutionPlan.Execute(ptExec, false, true) then
        ExecutionPlan.CommitTransaction
      else
        raise Exception.Create(ExecutionPlan.ExecException);

      FReservationChangeStateHandler.UpdateRoomResStateChangeHandlers;
      Display_rGrid(zRoomReservation);

    except
      on e: Exception do
      begin
        ExecutionPlan.RollbackTransaction;
        showmessage(format(GetTranslatedText('shTx_ReservationProfile_AddRoomError'), [e.message]));
      end;
    end;
  finally
    FreeAndNil(ExecutionPlan);
  end;

end;

procedure TfrmReservationProfile.MoveGuestToNewRoom2;
begin
  if ProvideARoom2(mRoomsRoomReservation.AsInteger) = mrOK then
  begin
    getGuestData(mRoomsRoomReservation.AsInteger);
    Display_rGrid(mRoomsRoomReservation.AsInteger);
  end;
end;

procedure TfrmReservationProfile.btnAddRoomClick(Sender: TObject);
begin
  AddNewRoom;
end;

procedure TfrmReservationProfile.btnRemoveRoomClick(Sender: TObject);
begin
  if FReservationChangeStateHandler.RoomStateChangeHandler[zRoomReservation].ChangeIsAllowed(rsRemoved, true) and g.OpenRemoveRoom(zRoomReservation) then
  begin
    FReservationChangeStateHandler.UpdateRoomResStateChangeHandlers;
    mRooms.delete;
    Display_rGrid(zRoomReservation);
  end;
end;

procedure TfrmReservationProfile.btnPasteFileClick(Sender: TObject);
begin
  if DropComboTarget1.CanPasteFromClipboard then
    DropComboTarget1.PasteFromClipboard;
end;

procedure TfrmReservationProfile.btnProvideRoomClick(Sender: TObject);
begin
  MoveGuestToNewRoom2;
end;

procedure TfrmReservationProfile.btnShowPricesClick(Sender: TObject);
var
  lRoomResList: TStringlist;
  lBookMark: TBooKmark;
begin
  lBookMark := mRooms.Bookmark;
  mROoms.DisableControls;
  lRoomresList := TStringlist.Create;
  try
    mRooms.First;
    while not mRooms.Eof do
    begin
      lRoomResList.Add(mRoomsRoomReservation.AsString);
      mRooms.next;
    end;
    EditRoomRates(lRoomResList, -1, mRoomsCurrency.AsString);
  finally
    lRoomresList.Free;
    Display_rGrid(zRoomReservation);
    mRooms.Bookmark := lBookMark;
    mROoms.EnableControls;
  end;
end;

procedure TfrmReservationProfile.btnRoomsRefreshClick(Sender: TObject);
begin
  Display_rGrid(zRoomReservation);
end;


// **************************************************************************
//
// ***************************************************************************

procedure TfrmReservationProfile.mnuThisreservationClick(Sender: TObject);
var
  iReservation: longInt;
begin
  iReservation := zReservation;
  ShowFinishedInvoices2(itPerReservation, '', iReservation);
  Display_rGrid(zRoomReservation);
end;

procedure TfrmReservationProfile.mnuThisRoomClick(Sender: TObject);
var
  iRoomreservation: longInt;
begin
  iRoomreservation := zRoomReservation;
  ShowFinishedInvoices2(itPerRoomRes, '', iRoomreservation);
  Display_rGrid(zRoomReservation);
end;

procedure TfrmReservationProfile.OpenthisRoom1Click(Sender: TObject);
begin
  try
    EditInvoice(zReservation, zRoomReservation, TInvoiceType.itDebitInvoice, zInvoiceIndex, false);
  finally
    Display_rGrid(zRoomReservation);
  end;

end;

procedure TfrmReservationProfile.OpenGroupInvoice1Click(Sender: TObject);
begin
  try
    EditInvoice(zReservation, 0, TInvoiceType.itDebitInvoice, 0, false);
  finally
    Display_rGrid(zRoomReservation);
  end;
end;


// ***************************************************************************
//
//
//
// ***************************************************************************

procedure TfrmReservationProfile.mRoomsAfterPost(DataSet: TDataSet);
begin
  UpdateInfoLabels;
  SetAllRoomsBreakfastItemindex;
end;

procedure TfrmReservationProfile.mRoomsAfterScroll(DataSet: TDataSet);
var
  HiddenInfo: string;
  ChannelRequest: String;
begin
  if mainPage.ActivePage = RoomsTab then
  begin
    if NOT DataSet.Eof then
    begin
      zGuestName := mRoomsGuestName.AsString;
      zRoomReservation := mRoomsRoomReservation.asInteger;
      zInvoiceIndex := mRoomsInvoiceIndex.asInteger;
      d.RR_GetMemoBothTextForRoom(zRoomReservation, HiddenInfo, ChannelRequest);
      gbxRoomInformation.caption := 'Notes for Room : ' + mRoomsRoom.asstring;
      memRoomNotes.Lines.text := HiddenInfo;
      memRequestFromChannel.Lines.text := ChannelRequest;
    end;
  end;
  if not Dataset.ControlsDisabled then
  begin
    UpdateGuestDetails(zRoomReservation);
    UpdateStateActions;
    UpdateInfoLabels;
  end;

end;


procedure TfrmReservationProfile.mRoomsBeforePost(DataSet: TDataSet);
begin
  if not FValidating then // prevent second call to validatie when posting record
  try
    FValidating := True;
    if mRoomsGuestName.OldValue <> mRoomsGuestName.AsString then
    begin
      d.RR_Upd_FirstGuestName(zRoomreservation, mRoomsGuestName.AsString);
      getGuestData(zRoomReservation);
    end;

    if (mRoomsBreakFast.OldValue <> mRoomsBreakFast.AsString) or
       (mRoomsBreakFastPrice.OldValue <> mRoomsBreakFastPrice.AsString) then
       if not UpdateRoomBreakfasts then
        Abort;


    if mRoomsExpectedTimeOfArrival.OldValue <> mRoomsExpectedTimeOfArrival.AsString then
      if not d.UpdateExpectedTimeOfArrival(zReservation, zRoomReservation, mRoomsExpectedTimeOfArrival.AsString.Trim) then
        Abort;

    if mRoomsExpectedCheckoutTime.OldValue <> mRoomsExpectedCheckoutTime.AsString then
      if not d.UpdateExpectedCheckoutTime(zReservation, zRoomReservation, mRoomsExpectedCheckoutTime.AsString.Trim) then
        Abort;

    if mRoomschildrencount.OldValue <> mRoomschildrencount.AsInteger then
      if not d.UpdateChildrenCount(zReservation, zRoomReservation, mRoomschildrencount.AsInteger) then
        Abort;

    if mRoomsinfantcount.OldValue <> mRoomsinfantcount.AsInteger then
      if not d.UpdateInfantCount(zReservation, zRoomReservation, mRoomsinfantcount.AsInteger) then
        Abort;

    if mRoomsGuestCount.OldValue <> mRoomsGuestCount.AsInteger then
    begin
      if (mRoomsGuestCount.OldValue < mRoomsGuestCount.AsInteger) or
         (MessageDlg(GetTranslatedText('shDecreaseRoomResGuestCount'), mtConfirmation, mbYesNo, 0) = mrYes) then
      begin
        d.RR_ChangeGuestCount(mRoomsRoomReservation.AsInteger, mGuests, mRoomsGuestCount.AsInteger);
        getGuestData(mRoomsRoomReservation.AsInteger);
      end
      else
        Abort
    end

  finally
    FValidating := False;
  end;
end;

procedure TfrmReservationProfile.mRoomsBreakfastTextGetText(Sender: TField; var Text: string; DisplayText: Boolean);
begin
  Text := TBreakfastType.FromDBString(mRoomsBreakfast.AsString).AsReadableString;
end;

procedure TfrmReservationProfile.mRoomsCalcFields(DataSet: TDataSet);
begin
   mRoomsunpaidRentPrice.AsFloat := mRoomsAverageRoomRate.AsFloat;
  mRoomsdayCount.asInteger := trunc(mRoomsDeparture.AsDateTime) - trunc( mRoomsArrival.ASDateTime);
  mRoomsdefGuestCount.AsInteger := glb.GET_RoomTypeNumberGuests_byRoomType(mRoomsRoomType.AsString);
end;

procedure TfrmReservationProfile.mRoomsDSDataChange(Sender: TObject; Field: TField);
begin
  // When fields are emptied the validation events are not fired!
  if (Field = mRoomsExpectedTimeOfArrival) and mRoomsExpectedTimeOfArrival.AsString.IsEmpty then
    d.UpdateExpectedTimeOfArrival(zReservation, zRoomReservation, '')
  else if (Field = mRoomsExpectedCheckoutTime) and mRoomsExpectedCheckoutTime.AsString.IsEmpty then
    d.UpdateExpectedCheckoutTime(zReservation, zRoomReservation, '');
end;

procedure TfrmReservationProfile.mRoomsisGroupAccountGetText(Sender: TField; var Text: string; DisplayText: Boolean);
begin
  Text := TAccountType.FromBool(Sender.AsBoolean).AsReadableString;
end;

procedure TfrmReservationProfile.mRoomsStatusGetText(Sender: TField; var Text: string; DisplayText: Boolean);
begin
  Text := TReservationState.FromResStatus(Sender.asString).AsReadableString;
end;


// ****************************************************************************
//
//
//
// *****************************************************************************

procedure TfrmReservationProfile.mainPageChange(Sender: TObject);
begin
  if mainPage.ActivePage = RoomsTab then
  begin
    Display_rGrid(zRoomReservation);
  end
  else if mainPage.ActivePage = GuestsTab then
  begin
    getGuestData(zRoomReservation);
  end
  else if mainPage.ActivePage = InvoicesTab then
  begin
    getInvoiceData(zRoomReservation);
  end;
end;

procedure TfrmReservationProfile.mAllGuestsAfterScroll(DataSet: TDataSet);
var
  HiddenInfo: string;
  ChannelRequest: String;
begin
  if not Dataset.ControlsDisabled then
  begin
    UpdateGuestDetails(mRoomsRoomReservation.AsInteger);

    if mainPage.ActivePage = GuestsTab then
    begin
      if lvAllGuests.GridView.Focused then
      begin
        zRoomReservation := DataSet.fieldbyname('Roomreservation').asInteger;
        d.RR_GetMemoBothTextForRoom(zRoomReservation, HiddenInfo, ChannelRequest);
        memRoomNotes.Lines.text := HiddenInfo;
        memRequestFromChannel.Lines.text := ChannelRequest;
      end;
    end
  end;
end;

procedure TfrmReservationProfile.SetProfileAlertVisibility;
begin
  gbxProfileAlert.Visible := TRIM(edtSpecialRequests.Text + edtNotes.Text +
                             edtRoom.Text + edtRoomType.Text) <> '';
  gbxRoomAlert.Visible := TRIM(edtRoom.Text + edtRoomType.Text) <> '';
  if gbxProfileAlert.Visible then
  begin
    lblSpecialRequests.Visible := (edtSpecialRequests.Text) <> '';
    edtSpecialRequests.Visible := (edtSpecialRequests.Text) <> '';

    lblNotes.Visible := (edtNotes.Text) <> '';
    edtNotes.Visible := (edtNotes.Text) <> '';

    lblRoom.Visible := (edtRoom.Text) <> '';
    edtRoom.Visible := (edtRoom.Text) <> '';

    lblRoomType.Visible := (edtRoomType.Text) <> '';
    edtRoomType.Visible := (edtRoomType.Text) <> '';
  end;
end;

procedure TfrmReservationProfile.memRoomNotesExit(Sender: TObject);
begin
  d.RR_Upd_MemoTexts(zRoomReservation, memRoomNotes.text);
end;

procedure TfrmReservationProfile.mGuestRoomsAfterScroll(DataSet: TDataSet);
begin
  if mainPage.ActivePage = GuestsTab then
  begin
    edtSpecialRequests.Text := '';
    edtNotes.Text := '';
    edtRoom.Text := '';
    edtRoomType.Text := '';
    if glb.LocateSpecificRecord('personprofiles', 'ID', DataSet.fieldbyname('PersonsProfilesId').asinteger) then
    begin
      edtSpecialRequests.Text := glb.PersonProfiles['Preparation'];
      edtNotes.Text := glb.PersonProfiles['Information'];
      edtRoom.Text := glb.PersonProfiles['Room'];
      edtRoomType.Text := glb.PersonProfiles['RoomType'];
    end;
    SetProfileAlertVisibility;
  end;
end;

// ********************************************************************************
//
//
//
// *********************************************************************************

procedure TfrmReservationProfile.Display_rGrid(gotoRoomReservation: longInt);
var
  rSet: TRoomerDataSet;
  RoomType: string;
  package: string;
  isGroupAccount: Boolean;
  Room: string;
  s: string;
  sPaymentdetails: string;
  sStatus: string;
  lSavedAfterScroll: TDataSetNotifyEvent;
  lSavedBeforePost: TDataSetNotifyEvent;

  procedure PopulateRatePlanCombo;
  begin
    with tvRoomsratePlanCode.Properties AS TcxComboBoxProperties do
    begin
      Items.BeginUpdate;
      try
        Items.Clear;
        Items.Add('');
        DynamicRates.GetAllRateCodes(Items);
      finally
        Items.EndUpdate;
      end;
    end;
  end;

  procedure InitDynamicRates;
  var
    arrival, departure: TDate;
    channelId: Integer;
    channelCode, chManCode: String;
  begin

    if mRooms.IsEmpty then
      Exit;

    arrival := now + 2000;
    departure := 0;

    mRooms.First;
    while NOT mRooms.Eof do
    begin
      if mRooms['Arrival'] < arrival then
        arrival := mRooms['Arrival'];
      if mRooms['Departure'] > departure then
        departure := mRooms['Departure'];
      mRooms.Next;
    end;

    mRooms.First;
    channelId := mRooms['ManualChannelId'];
    chManCode := channelManager_GetDefaultCode;
    if glb.LocateSpecificRecordAndGetValue('channels', 'id', channelId, 'channelManagerId', channelCode) then
    begin
      DynamicRates.Prepare(arrival, departure, channelCode, chManCode);
      PopulateRatePlanCombo;
    end;

  end;

begin
  rSet := nil;
  lSavedAfterScroll := mRooms.AfterScroll;
  lSavedBeforePost := mRooms.BeforePost;
  mRooms.DisableControls;
  try
    screen.Cursor := crHourGlass;
    mRooms.AfterScroll := nil;
    mRooms.BeforePost := nil;

    s :=     ' SELECT '#10;
    s := s + '      rr.Reservation '#10;
    s := s + '    , rr.RoomReservation '#10;
    s := s + '    , rr.Room '#10;
    s := s + '    , rr.RoomType '#10;
    s := s + '    , rr.package '#10;
    s := s + '    , RR_Arrival(rr.roomreservation, true) as Arrival'#10;
    s := s + '    , RR_Departure(rr.roomreservation, true) as Departure'#10;
    s := s + '    , ExpectedTimeOfArrival'#10;
    s := s + '    , ExpectedCheckoutTime'#10;
    s := s + '    , rr.Status '#10;
    s := s + '    , rr.Currency '#10;
    s := s + '    , invBreakfast as invBreakfast '#10;
    s := s + '    , breakfast '#10;
    s := s + '    , breakfastprice '#10;
    s := s + '    , GroupAccount as isGroupAccount '#10;
    s := s + '    , rrIsNoRoom as isNoRoom '#10;
    s := s + '    , (SELECT ' +
             '       (SUM(roomrate * cu.avalue) + ' +
             '       IF((rr.package = NULL OR rr.package = ''''), 0, ' +
             '       IFNULL((SELECT SUM(price * number) ' +
             '       FROM invoicelines il ' +
             '       WHERE il.roomreservation = rr.roomreservation ' +
             '       AND importsource = rr.package), ' +
             '       0))) / COUNT(rd.id) ' +
             '       FROM roomsdate rd ' +
             '       JOIN currencies cu ON cu.currency = rd.currency ' +
             '       WHERE rd.roomreservation = rr.roomreservation ' +
             '       AND resflag NOT IN (''X'' , ''C'')) AS RateOrPackagePerDay'#10;
    s := s + '    , rr.useStayTax '#10;
    s := s + '    , rr.ratePlanCode '#10;
    s := s + '    , rr.InvoiceIndex '#10;
    s := s + '    , rr.PAYCARD_TOKEN_ID '#10;
    s := s + '    , IF(ISNULL(ManualChannelId) OR ManualChannelId < 1, r.channel, ManualChannelId) AS ManualChannelId '#10;
    s := s + '    , RoomClass '#10;
    s := s + '    , blockMove '#10;
    s := s + '    , blockMoveReason '#10;
    s := s + '    , rrRoomAlias as RoomAlias '#10;
    s := s + '    , rrRoomTypeAlias as RoomTypeAlias '#10;
    s := s + '    , (SELECT AVG(RoomRate) FROM roomsdate WHERE (roomsdate.roomreservation=rr.roomreservation) AND (roomsdate.ResFlag NOT IN (''X'',''C''))) AS AverageRoomRate '#10;
    s := s + '    , (SELECT count(ID) FROM roomsdate WHERE (roomsdate.roomreservation=rr.roomreservation) AND roomsdate.Paid=0 AND (roomsdate.ResFlag NOT IN (''X'',''C''))) AS unPaidRentNights '#10;
    s := s + '    , IF(r.OutofOrderBlocking, r.name, (SELECT name FROM persons WHERE persons.roomreservation=rr.roomreservation ORDER BY MainName DESC LIMIT 1)) AS GuestName '#10;
    s := s + '    , numChildren as childrencount '#10;
    s := s + '    , numInfants as Infantcount '#10;
    s := s + '    , (SELECT PersonsProfilesId FROM persons WHERE persons.roomreservation=rr.roomreservation ORDER BY MainName DESC LIMIT 1) AS PersonsProfilesId '#10;
    s := s + '    , (SELECT count(ID) FROM persons WHERE persons.roomreservation=rr.roomreservation) AS GuestCount '#10;
    s := s + '    , (SELECT SUM(RoomRate) FROM roomsdate WHERE (roomsdate.roomreservation=rr.roomreservation) AND (roomsdate.paid=0) AND (roomsdate.ResFlag NOT IN (''X'',''C''))) AS unPaidRoomRent '#10;
    s := s + '    , (SELECT SUM(IF(isPercentage, RoomRate*Discount/100, Discount)) FROM roomsdate WHERE (roomsdate.roomreservation=rr.roomreservation) AND (roomsdate.paid=0) AND (roomsdate.ResFlag NOT IN (''X'',''C'')))  AS DiscountUnPaidRoomRent '#10;
    s := s + '    , ((SELECT SUM(RoomRate) FROM roomsdate WHERE (roomsdate.roomreservation=rr.roomreservation) AND (roomsdate.paid=0) and (roomsdate.ResFlag NOT IN (''X'',''C''))) '#10;
    s := s + '       - (SELECT SUM(IF(isPercentage, RoomRate*Discount/100, Discount)) FROM roomsdate WHERE (roomsdate.roomreservation=rr.roomreservation) AND (roomsdate.paid=0) AND (roomsdate.ResFlag NOT IN (''X'',''C'')))) AS TotalUnpaidRoomRent '#10;
    s := s + '    , (SELECT Description FROM roomtypegroups WHERE roomtypegroups.code=rr.roomclass) AS RoomClassDescription '#10;
    s := s + '    , rrs.StockitemsCount ';
    s := s + '    , rrs.StockitemsPrice ';
    s := s + ' FROM '#10;
    s := s + '   roomreservations rr '#10;
    s := s + '  JOIN reservations r on r.reservation=rr.reservation '#10;
    s := s + '  LEFT OUTER JOIN -- Add stockitem totalcount and total price per roomreservation '#10;
    s := s + '      (select '#10;
    s := s + '      	roomreservation as tmp_roomres, '#10;
    s := s + '      	sum(ifnull(rtmp.count, 0)) DIV 1 as StockitemsCount, -- forced into integer'#10;
    s := s + '      	sum(ifnull(rtmp.count * rtmp.price * rtmp.dayscount, 0)) as StockItemsPrice '#10;
    s := s + '      from '#10;
    s := s + '      	(select '#10;
    s := s + '      	    rrs2.Roomreservation, '#10;
    s := s + '            rrs2.stockitem, '#10;
    s := s + '      	    rrs2.Count, '#10;
    s := s + '            count(*) as dayscount, '#10;
    s := s + '      	    rrs2.price '#10;
    s := s + '      	  from roomreservationstockitems rrs2 '#10;
    s := s + '      	  group by rrs2.roomreservation, rrs2.StockItem, rrs2.count, rrs2.Price) rtmp '#10;
    s := s + '       group by tmp_roomres) rrs on rrs.tmp_roomres= rr.RoomReservation '#10;
    s := s + ' WHERE '#10;
    s := s + '   (rr.Reservation = %d) '#10;
    s := s + ' ORDER BY '#10;
    s := s + '  Room ';

    s := format(s, [zReservation]);
    copytoclipboard(s);
    rSet := CreateNewDataSet;
    hData.rSet_bySQL(rSet, s);

    mRooms.Close;
    mRooms.Open;

    CopyToClipboard(s);

    mRooms.LoadFromDataSet(rSet);
    InitDynamicRates;
    mRooms.First;

    sPaymentdetails := '';
    sStatus := '';

    while not mRooms.Eof do
    begin

      Room := mRoomsRoom.asstring;
      RoomType := mRoomsRoomType.asstring;
      package := mRoomsPackage.asstring;

      isGroupAccount := mRoomsisGroupAccount.AsBoolean;
      sPaymentdetails := sPaymentdetails + _GLOB._Bool2Str(isGroupAccount, 0);

      mRooms.Next;
    end;

    SetAllRoomsBreakfastItemindex;

    SetPaymentDetailItemindex(sPaymentdetails);
    if gotoRoomReservation <> 0 then
      mRooms.Locate('RoomReservation', gotoRoomReservation, [])
    else
      mROoms.First;
  finally
    mRooms.EnableControls;
    mRooms.AfterScroll := lSavedAfterScroll;
    mRooms.BeforePost := lSavedBeforePost;
    rSet.Free;
    screen.Cursor := crDefault;
  end;
  if assigned (mRooms.AfterScroll) then
    mRooms.AfterScroll(mRooms);
end;

procedure TfrmReservationProfile.UpdateGuestDetails(gotoRoomReservation: integer);
begin
  gbxGuest.Caption := FgbxGuestOrigCaption + ' ' + mRoomsRoom.AsString;

  if mAllGuests.Locate('RoomReservation;MainName', VarArrayOf([mRoomsRoomReservation.AsInteger, True]), []) then
  begin
    edtGuestName.Text := mAllGuestsGuestName.AsString;
    edtGuestAddress1.Text := mAllGuestsAddress1.AsString;
    edtGuestAddress2.Text := mAllGuestsAddress2.AsString;
    edtGuestAddress3.Text := mAllGuestsAddress3.AsString;
    edtGuestAddress4.Text := mAllGuestsAddress4.AsString;

    fraGuestCountry.DisableEvents;
    try
      fraGuestCountry.Code := mAllGuestsCountry.AsString;
    finally
      fraGuestCountry.EnableEvents;
    end;

    fraGuestNationality.DisableEvents;
    try
      fraGuestNationality.Code := mAllGuestsNationality.AsString;
    finally
      fraGuestNationality.EnableEvents;
    end;

  end
  else
  begin
    edtGuestName.Text := '';
    edtGuestAddress1.Text := '';
    edtGuestAddress2.Text := '';
    edtGuestAddress3.Text := '';
    edtGuestAddress4.Text := '';
    fraGuestCountry.Code := '';
    fraGuestNationality.Code := '';
  end
end;

procedure TfrmReservationProfile.tvRoomsaccountTypeTextPropertiesChange(Sender: TObject);
begin
  try
    mRoomsisGroupAccount.AsBoolean := (TcxComboBox(Sender).ItemIndex = 1);
    d.UpdateGroupAccountOne(zReservation, zRoomReservation, zRoomReservation, mRoomsisGroupAccount.Asboolean);
    mRooms.Post;
    SetPaymentDetailItemindex('');
  except
    mROoms.Cancel;
  end;

end;


procedure TfrmReservationProfile.tvRoomsInitEdit(Sender: TcxCustomGridTableView;
  AItem: TcxCustomGridTableItem; AEdit: TcxCustomEdit);
begin
  If AEdit is TcxComboBox then
    TcxComboBox(AEdit).Properties.UseMouseWheel := false;
end;

procedure TfrmReservationProfile.tvRoomsPackagePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
var
  theData: recPackageHolder;
  oldPackage: String;
  rSet: TRoomerDataSet;
  rate: double;

  rr, rrAlias: Integer;

  procedure RemovePackage(pack: String; rr, rrAlias: Integer; restorePrice: Boolean);
  begin
    mRooms.DisableControls;
    try
      mRooms.Edit;
      mRoomsPackage.asstring := '';
      mRooms.Post;
      d.roomerMainDataSet.SystempackagesRemove(pack, rr, rrAlias, restorePrice);
    finally
      mRooms.EnableControls;
    end;
  end;

begin
  initPackageHolder(theData);
  theData.package := mRoomsPackage.asstring;

  if AButtonIndex = 0 then
  begin

    oldPackage := theData.package;
    if (oldPackage <> '') AND
      (MessageDlg(GetTranslatedText('shTx_RoomResProfile_PackageAlreadyExists_Remove'), mtConfirmation,
      [mbYes, mbCancel], 0) = mrCancel) then
      exit;

    if openPackages(actLookup, theData) then
    begin
      if theData.package <> '' then
      begin
        rr := zRoomReservation;
        rrAlias := rr;
        if mRoomsisGroupAccount.AsBoolean = true then
          rr := 0;

        rate := mRoomsunpaidRentPrice.AsFloat;
        if oldPackage <> '' then
        begin

          RemovePackage(oldPackage, rr, rrAlias, true);

          rSet := CreateNewDataSet;
          try
            hData.rSet_bySQL(rSet, 'SELECT AVG(RoomRate) AS AverageRate FROM roomsdate rd WHERE (rd.ResFlag NOT IN (''X'',''C'')) AND rd.RoomReservation=' +
              inttostr(zRoomReservation));
            rSet.First;
            if not rSet.Eof then
              rate := rSet['AverageRate'];
          finally
            rSet.free;
          end;
        end;

        d.roomerMainDataSet.SystempackagesAdd(theData.package, rr, rrAlias, rate, mRooms['Currency']);
        mRooms.Edit;
        mRoomsPackage.asstring := theData.package;
        mRoomsunpaidRentPrice.AsFloat := rate;
        mRooms.Post;
      end;
    end;

  end
  else
  begin
    rr := zRoomReservation;
    rrAlias := rr;
    if mRoomsisGroupAccount.AsBoolean = true then
      rr := 0;

    if theData.package <> '' then
      RemovePackage(theData.package, rr, rrAlias, true);
  end;

  Display_rGrid(zRoomReservation);

end;

procedure TfrmReservationProfile.SelectMainGuestProfile;
var
  iGoto: Integer;
  s, s1, s2, s3: String;
begin
    iGoto := -1;
    if mRooms['PersonsProfilesId'] > 0 then
      iGoto := mRooms['PersonsProfilesId'];

    iGoto := GuestProfiles(actLookup, iGoto);
    if iGoto > 0 then
    begin
      mRooms.Edit;

      try
        mRooms['PersonsProfilesId'] := iGoto;

        glb.LocateSpecificRecordAndGetValue('personprofiles', 'ID', inttostr(iGoto), 'Firstname', s1);
        glb.LocateSpecificRecordAndGetValue('personprofiles', 'ID', inttostr(iGoto), 'Lastname', s2);
        s3 := trim(s1 + ' ' + s2);
        mRooms['guestname'] := s3;

        mRooms.Post;
      except
        mROoms.Cancel;
        raise;
      end;

      s := format('UPDATE persons pe, ' +
        'personprofiles pp ' +
        'SET PersonsProfilesId=pp.Id, ' +
        'pe.title = pp.title, ' +
        'pe.Name = TRIM(CONCAT(pp.FirstName, '' '', pp.LastName)), ' +
        'pe.Surname = pp.CompanyName, ' +
        'pe.Address1 = pp.Address1, ' +
        'pe.Address2 = pp.Address2, ' +
        'pe.Address3 = pp.Zip, ' +
        'pe.Address4 = pp.City, ' +
        'pe.Country = pp.Country, ' +
        'pe.Tel1 = pp.TelLandLine, ' +
        'pe.Tel2 = pp.TelMobile, ' +
        'pe.Fax = pp.TelFax, ' +
        'pe.Email = pp.Email, ' +
        'pe.Information = pp.Information, ' +
        'pe.Nationality = pp.Nationality, ' +
        'pe.Customer = pp.CustomerCode, ' +
        'pe.CompanyName = pp.CompanyName, ' +
        'pe.CompAddress1 = pp.CompAddress1, ' +
        'pe.CompAddress2 = pp.CompAddress2, ' +
        'pe.CompZip = pp.CompZip, ' +
        'pe.CompCity = pp.CompCity, ' +
        'pe.CompCountry = pp.CompCountry, ' +
        'pe.CompTel = pp.CompTel, ' +
        'pe.CompEmail = pp.CompEmail, ' +
        'pe.state = pp.state, ' +
        'pe.DateOfBirth = pp.DateOfBirth, ' +
        'pe.PersonalIdentificationId = pp.PassportNumber, ' +
        'pe.SocialSecurityNumber= pp.SocialSecurityNumber ' +
        'WHERE pp.Id=%d AND ' +
        'pe.MainName=1 AND pe.Reservation=%d AND pe.RoomReservation=%d',
        [
          iGoto,
          mRoomsReservation.asInteger,
          mRoomsRoomReservation.asInteger
        ]);
      d.roomerMainDataSet.DoCommand(s);
      getGuestData(iGoto, True);
    end;
end;

procedure TfrmReservationProfile.ShowMainGuestProfile;
var
  iGoto: Integer;
  s1, s2: string;
begin
  if mRooms['PersonsProfilesId'] = 0 then
    SelectMainGuestProfile
  else
  begin
    iGoto := mRooms['PersonsProfilesId'];

    if OpenGuestPortfolioEdit(glb.PersonProfiles, iGoto, false) then
    begin
      mRooms.Edit;
      try
        if iGoto > 0 then
        begin
          mRooms['PersonsProfilesId'] := iGoto;
          glb.LocateSpecificRecordAndGetValue('personprofiles', 'ID', inttostr(iGoto), 'Firstname', s1);
          glb.LocateSpecificRecordAndGetValue('personprofiles', 'ID', inttostr(iGoto), 'Lastname', s2);
          mRooms['guestname'] := trim(s1 + ' ' + s2);
        end
        else
          mRooms['PersonsProfilesId'] := 0;
        mRooms.Post;
        getGuestData(igoto, True);
      except
        mRooms.Cancel;
        raise;
      end;
    end;
  end;
end;

procedure TfrmReservationProfile.tvRoomsPersonsProfilesIdPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  case aButtonIndex of
    0: SelectMainGuestProfile;
    1: ShowMainGuestProfile;
  end;
  UpdateGuestDetails(0);
end;

procedure TfrmReservationProfile.tvRoomsratePlanCodePropertiesCloseUp(Sender: TObject);
var
  code: String;
begin
  if NOT mRooms.Eof then
  begin
    mRooms.DisableControls;
    try
      code := (tvRoomsratePlanCode.Properties AS TcxComboBoxProperties).Items[TcxComboBox(Sender).ItemIndex];
      DynamicRates.UpdateRoomReservation(mRooms['RoomReservation'], code, mRooms['RoomType'], mRooms['Arrival'], mRooms['Departure'], mRooms['Currency']);

      mRooms.Edit;
      mRoomsratePlanCode.AsString := code;
      //mRoomsAverageRoomRate.AsFloat := DynamicRates.AverageRateStay(mRoomsratePlanCode.AsString, mRoomsRoomType.AsString, mRoomsArrival.AsDateTime, mRoomsDeparture.AsDateTime);
      mRooms.Post;

      Display_rGrid(mRooms['RoomReservation']);

    finally
      mRooms.EnableControls;
    end;
  end;
end;

procedure TfrmReservationProfile.tvRoomsStatusTextPropertiesChange(Sender: TObject);
var
  lStateChanger: TRoomReservationStateChangeHandler;
  lNewState: TReservationState;
  cbx: TcxCombobox;
begin
  cbx := TcxComboBox(Sender);
  lNewState :=  TReservationState(cbx.Properties.Items.Objects[cbx.ItemIndex]);
  lStateChanger := FReservationChangeStateHandler.RoomStateChangeHandler[zRoomReservation];
  try
    if lNewState.IsUserSelectable and (lNewState <> lStateChanger.CurrentState) and lStateChanger.ChangeState(lNewState) then
    begin
      mRooms.DisableControls;
      try
        mRoomsStatus.AsString := lNewState.AsStatusChar;
        mRooms.Post
      finally
        mRooms.EnableControls;
      end;
    end
    else
      mRooms.Cancel;
  except
    mRooms.Cancel;
    raise;
  end;

end;

procedure TfrmReservationProfile.tvRoomsStatusTextPropertiesDrawItem(AControl: TcxCustomComboBox; ACanvas: TcxCanvas;
  AIndex: Integer; const ARect: TRect; AState: TOwnerDrawState);
var
  lState: TReservationState;
  lRoomStateChanger: TRoomReservationStateChangeHandler;
  ltext: string;
  lDisabled: boolean;
begin
  lDisabled := false;
  if aIndex = -1 then
    ltext := ''
  else
  begin
    lState := TReservationState(aControl.Properties.Items.Objects[aIndex]);
    lRoomStateChanger := FReservationChangeStateHandler.RoomStateChangeHandler[mRoomsRoomReservation.AsInteger];
    lText := aControl.Properties.Items[aIndex];
    lDisabled := not lRoomStateChanger.ChangeIsAllowed(lState);
  end;

  with aCanvas do
  begin
    if lDisabled and not (odComboBoxEdit in aState) then
      Font.Color := clMedGray
    else
      Font.Color := clWindowtext;

    FillRect(aRect);
    if (odComboBoxEdit in aState) then // drawing in edit box
      TextOut(aRect.Left, aRect.Top + 5, lText)
    else
      TextOut(aRect.Left, aRect.Top, lText)
  end;
end;

procedure TfrmReservationProfile.tvRoomsblockMoveGetCellHint(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  ACellViewInfo: TcxGridTableDataCellViewInfo; const AMousePos: TPoint; var AHintText: TCaption; var AIsHintMultiLine: Boolean; var AHintTextRect: TRect);
begin
  if aRecord.Values[tvRoomsblockMove.Index] = True then
    AHintText := aRecord.Values[tvRoomsblockMoveReason.Index]
  else
    AHintText := '';
  AIsHintMultiLine := True;
end;

procedure TfrmReservationProfile.tvRoomsStockItemsCountPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
var
  lCurrentRoomRes: recEditReservationExtrasHolder;
begin
  with lCurrentRoomRes do
  begin
    Reservation := mRoomsReservation.AsInteger;
    RoomReservation := mRoomsRoomReservation.AsInteger;
    Room := mRoomsRoom.asString;
    RoomType := mRoomsRoomType.AsString;
    Currency := mRoomsCurrency.AsString;
    CurrencyRate := hData.GetRate(Currency);
    guests := mRoomsGuestCount.AsInteger;
    childrenCount := mRoomschildrencount.AsInteger;
    infantCount := mRoomsinfantcount.AsInteger;
    ArrivalDate := mRoomsArrival.AsDateTime;
    DepartureDate := mRoomsDeparture.asDateTime;
  end;

  if editReservationExtras(lCurrentRoomRes, nil) then
    Display_rGrid(zRoomReservation);
end;

procedure TfrmReservationProfile.tvRoomsblockMovePropertiesChange(Sender: TObject);
var
  Value: Integer;
  iRoomRes: Integer;
  sTmp: string;
  lReason: string;
begin
  if mRoomsDS.State = dsBrowse then
    mRooms.Edit;

  lReason := mRoomsBlockMoveReason.AsString;
  mRoomsblockMove.AsBoolean := TcxCheckBox(Sender).Checked;
  Value := 0;
  try
    if mRoomsBlockMove.AsBoolean then
      if EditText2(GetTranslatedText('shTx_FrmReservationprofile_BlockMoveReasonCaption') + mRoomsRoom.AsString, lReason) then
      begin
        Value := 1;
        mRoomsBlockMoveReason.AsString := lReason;
      end
      else
      begin
        mRooms.Cancel;
        Exit;
      end;

    mRooms.Post;

  except
    mRooms.Cancel;
    raise;
  end;

  iRoomRes := mRoomsRoomReservation.asInteger;
  sTmp := format('UPDATE roomreservations SET blockMove=%d, blockMoveReason=%s WHERE RoomReservation=%d', [Value, _db(mRoomsBlockMoveReason.AsString), iRoomRes]);
  cmd_bySQL(sTmp);

end;

procedure TfrmReservationProfile.tvRoomsblockMoveReasonGetDisplayText(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  if aRecord.Values[tvRoomsblockMove.Index] = false then
    aText := '';
end;

procedure TfrmReservationProfile.tvRoomsbreakfastTextPropertiesCloseUp(Sender: TObject);
var
  lNewValue: string;
begin
  lNewValue := TBreakFastType.fromItemIndex(TcxCombobox(Sender).ItemIndex).toDBString;
  if not lNewValue.Equals(mRoomsBreakfast.AsString) then
  begin
    mRoomsBreakfast.AsString := lNewValue;
    mRooms.Post;
  end;
end;

procedure TfrmReservationProfile.tvRoomsCellDblClick
  (Sender: TcxCustomGridTableView; ACellViewInfo: TcxGridTableDataCellViewInfo;
  AButton: TMouseButton; AShift: TShiftState; var AHandled: Boolean);
var
  reservation: longInt;
  roomReservation: longInt;
  fieldName: string;
  s: string;
  theData: recPersonHolder;

begin
  roomReservation := mRoomsRoomReservation.asInteger;
  reservation := mRoomsReservation.asInteger;
  fieldName := _trimlower(ACellViewInfo.Item.caption);

  if (fieldName = 'guests') then
  begin
    //
    if mRoomsDS.State = dsEdit then
    begin
      mRooms.Post;
    end;

    s := mRoomsGuestname.asstring;
    initPersonHolder(theData);
    theData.reservation := reservation;
    theData.roomReservation := roomReservation;
    theData.name := s;

    if openGuestProfile(actNone, theData) then
    begin
    end;

    screen.Cursor := crHourGlass;
    mRooms.DisableControls;
    try
      mRooms.Edit;
      mRoomsGuestName.asstring :=  d.RR_GetFirstGuestName(roomReservation);
      mRoomsGuestCount.asInteger := d.RR_GetGuestCount(zRoomReservation);
      mRooms.Post;
      Display_rGrid(roomReservation);
    finally
      screen.Cursor := crDefault;
      mRooms.EnableControls;
    end;
  end;
end;

procedure TfrmReservationProfile.tvRoomsDocumentsPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  StaticResources('Room Resources', [TResourceType.rtRoomBooking], TResourceAccessType.ratRestricted, inttostr(mRooms['RoomReservation']));
end;

procedure TfrmReservationProfile.tvRoomsEditing(Sender: TcxCustomGridTableView; AItem: TcxCustomGridTableItem;
  var AAllow: Boolean);
begin
  if (aItem = tvRoomsBreakfastPrice) then
    aAllow := TBreakfastType.fromDBString(mRoomsBreakFast.AsString) = TBreakfastType.Excluded;
end;

procedure TfrmReservationProfile.doRRDateChange(startIn: Integer);
var
  arrival: TDate;
  departure: TDate;

  iNights: Integer;

  roomReservation: Integer;
  reservation: Integer;
  Room: string;
  RoomType: String;

  temp: String;
begin
  roomReservation := mRoomsRoomReservation.asInteger;
  reservation := mRoomsReservation.asInteger;
  Room := mRoomsRoom.asstring;
  RoomType := mRoomsRoomType.asstring;

  if mRoomsDS.State = dsEdit then
  begin
    mRooms.Post;
  end;

  arrival := mRoomsArrival.AsDateTime;
  departure := mRoomsDeparture.AsDateTime;

  temp := format
    ('(doRRDateChange 1) Availability made dirty for Reservation=%d, RoomReservation=%d, Room=%s, RoomType=%s, FOR ArrDate=%s, DepDate=%s',
    [reservation, roomReservation, Room, RoomType, DateToSqlString(arrival), DateToSqlString(departure)]);
  d.roomerMainDataSet.SystemMakeAvailabilityDirtyFromRoomReservation(roomReservation, temp);

  g.openResDates(reservation, roomReservation, Room, arrival, departure, startIn);

  iNights := trunc(departure) - trunc(arrival);

  mRooms.DisableControls;
  try
    mRooms.Edit;
    try
      mRoomsArrival.AsDateTime := arrival;
      mRoomsDeparture.AsDateTime := departure;
      mRoomsDayCount.asInteger := iNights;
      mRooms.Post;

//      if (lOrgNightCount <> mRoomsdayCount.AsInteger) and not mRoomsBreakFast.AsBoolean then
//        if (MessageDlg(GetTranslatedText('shTx_FrmReservationprofile_UpdateExclBreakfast'), mtConfirmation, mbYesNo, 0) = mrYes) then
//           d.INV_UpdateBreakfastGuests(zReservation, zRoomReservation, mRoomsGuestCount.AsInteger * mRoomsdayCount.AsInteger);

    except
      mRooms.Cancel;
      raise;
    end;

    FReservationChangeStateHandler.UpdateRoomResStateChangeHandlers;
    Display_rGrid(Roomreservation);

    temp := format
      ('(doRRDateChange 2) Availability made dirty for Reservation=%d, RoomReservation=%d, Room=%s, RoomType=%s, FOR ArrDate=%s, DepDate=%s',
      [reservation, roomReservation, Room, RoomType, DateToSqlString(arrival), DateToSqlString(departure)]);
    d.roomerMainDataSet.SystemMakeAvailabilityDirtyFromRoomReservation(roomReservation, temp);

  finally
    mRooms.EnableControls;
  end;

end;

procedure TfrmReservationProfile.DropComboTarget1DragOver(Sender: TObject; ShiftState: TShiftState; APoint: TPoint;
  var Effect: Integer);
begin
  Effect := DROPEFFECT_COPY;
end;

procedure TfrmReservationProfile.DropComboTarget1Drop(Sender: TObject; ShiftState: TShiftState; APoint: TPoint;
  var Effect: Integer);
begin
  Effect := DROPEFFECT_COPY;
  try
    if DropComboTargetDrop(format(BOOKING_STATIC_RESOURCES, [inttostr(zReservation)]), ACCESS_RESTRICTED,
      Sender AS TDropComboTarget, ShiftState, APoint, Effect) then
    begin
      timBlink.Tag := 0;
      timBlink.enabled := false;
      timBlink.Interval := 100;
      timBlink.enabled := true;
    end;
  except on E: Exception do
    ShowMessage('Error occured while saving file: ' + e.message);
  end;
end;

procedure TfrmReservationProfile.DropComboTarget1GetDropEffect(Sender: TObject; ShiftState: TShiftState; APoint: TPoint;
  var Effect: Integer);
begin
  Effect := DROPEFFECT_COPY;
end;

procedure TfrmReservationProfile.tvRoomsArrivalPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  doRRDateChange(1); // Arrival
end;

procedure TfrmReservationProfile.tvRoomsDeparturePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  doRRDateChange(2); // Departure
end;

procedure TfrmReservationProfile.FormatTextToShortFormat(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
var
  lTime: TDateTime;
begin
  //convert from string(5) HH:mm format into local shorttimeformat if possible
  if not aText.IsEmpty and TryStrToTime(aText, lTime) then
    DateTimeToString(aText, FormatSettings.ShortTimeFormat, StrTodateTime(aText));
end;

procedure TfrmReservationProfile.GetLocaltimeEditProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  TcxTimeEditProperties(aProperties).Use24HourFormat := not FormatSettings.ShortTimeFormat.Contains(Formatsettings.TimeAMString);
end;

procedure TfrmReservationProfile.tvRoomsdayCountPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  doRRDateChange(3); // Dates
  Display_rGrid(zRoomReservation);
end;

procedure TfrmReservationProfile.
  tvRoomsTcxGridDBDataControllerTcxDataSummaryFooterSummaryItems9GetText
  (Sender: TcxDataSummaryItem; const AValue: Variant; AIsFooter: Boolean;
  var AText: string);
var
  price: double;
  Nights: Integer;
  r: double;
begin
  Nights := 0;
  price := 0.00;
  if tvRooms.DataController.Summary.FooterSummaryValues[8] <> null then
  begin
    Nights := tvRooms.DataController.Summary.FooterSummaryValues[8];
  end;
  if tvRooms.DataController.Summary.FooterSummaryValues[6] <> null then
  begin
    price := tvRooms.DataController.Summary.FooterSummaryValues[6];
  end;

  r := 0.00;
  if Nights <> 0 then
  begin
    r := price / Nights;
  end;

  AText := RoomerCurrencyManager.DefaultCurrencyDefinition.FormattedValue(r) + ' ' + GetTranslatedText('shTx_FrmReservationprofile_PerNight');
end;

procedure TfrmReservationProfile.tvGetCurrencyProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  RoomerCurrencyManager[mRoomsCurrency.AsString].SetcxEditProperties(aProperties);
end;

procedure TfrmReservationProfile.tvRoomsunpaidRentPricePropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
begin
  if AButtonIndex = 0 then
  begin
    ShowRatesForRoomReservation(zRoomReservation);
  end;
end;


// ***************************************************************************
//
// Guests Grid
//
// ***************************************************************************

Function TfrmReservationProfile.MainGuestRoomsSQL(reservation: longInt): string;
begin
  result := format(select_ReservationProfile_guestRoomsSQL, [zReservation]);
end;

Function TfrmReservationProfile.guestsSQL(reservation: longInt): string;
begin
  result := format(select_ReservationProfile_guestsSQL, [zReservation]);
end;

function TfrmReservationProfile.allGuestsSQL(reservation: longInt): string;
begin
  result := format(select_ReservationProfile_allGuestsSQL, [zReservation]);
end;

Function TfrmReservationProfile.InvoiceSQL(reservation: longInt): string;
var
  Sql: string;
begin
  Sql :=
    '   SELECT ' +
    '     invoiceheads.Reservation ' +
    '   , invoiceheads.RoomReservation ' +
    '   , invoiceheads.SplitNumber ' +
    '   , invoiceheads.InvoiceNumber ' +
    '   , invoiceheads.Customer ' +
    '   , invoiceheads.Name As NameOnInvoice' +
    '   , invoiceheads.Address1 ' +
    '   , invoiceheads.Address2 ' +
    '   , invoiceheads.Address3 ' +
    '   , invoiceheads.Total as ihAmountWithTax ' +
    '   , invoiceheads.TotalWOVAT as ihAmountNoTax ' +
    '   , invoiceheads.TotalVAT as ihAmountTax ' +
    '   , invoiceheads.CreditInvoice ' +
    '   , invoiceheads.OriginalInvoice ' +
    '   , invoiceheads.RoomGuest ' +
    '   , invoiceheads.ihInvoiceDate as InvoiceDate' +
    '   , invoiceheads.ihPayDate as dueDate' +
    '   , invoiceheads.invRefrence ' +
    '   , invoicelines.PurchaseDate ' +
    '   , invoicelines.ItemID as Item' +
    '   , invoicelines.Number as Quantity' +
    '   , invoicelines.Description ' +
    '   , invoicelines.Price ' +
    '   , invoicelines.VATType ' +
    '   , invoicelines.Total AS ilAmountWithTax ' +
    '   , invoicelines.TotalWOVat AS ilAmountNoTax ' +
    '   , invoicelines.Vat as ilAmountTax' +
    '   , invoicelines.Currency ' +
    '   , invoicelines.CurrencyRate ' +
    '   , invoicelines.ImportRefrence ' +
    '   , invoicelines.ImportSource ' +
    ' FROM ' +
    '  invoicelines ' +
    '     INNER JOIN invoiceheads ON invoicelines.InvoiceNumber = invoiceheads.InvoiceNumber ' +
    ' WHERE ' +
    '  (invoiceheads.InvoiceNumber > 0) ' +
    ' AND (invoiceheads.Reservation =%d) ' + // zReservation
    ' ORDER BY ' +
    '  invoiceheads.InvoiceNumber ';

  result := format(Sql, [zReservation]);
end;

function TfrmReservationProfile.getGuestData(gotoRoomReservation: longInt; aAllGuestsOnly: boolean = false): Boolean;
var
  rSet: TRoomerDataSet;
  s: string;

begin
  rSet := CreateNewDataSet;
  if not aAllGuestsOnly then
  begin
    try
      rSet.CommandType := cmdText;

      mGuestRooms.DisableControls;
      screen.Cursor := crHourGlass;
      try
        s := MainGuestRoomsSQL(zReservation);
        hData.rSet_bySQL(rSet, s);

        if mGuestRooms.Active then
          mGuestRooms.Close;
        mGuestRooms.Open;

        mGuestRooms.LoadFromDataSet(rSet);

        mGuestRooms.Locate('RoomReservation', gotoRoomReservation, []);

     finally
       screen.Cursor := crDefault;
       mGuestRooms.EnableControls;
     end;
    finally
      FreeAndNil(rSet);
    end;

    rSet := CreateNewDataSet;
    try

      rSet.CommandType := cmdText;

      mGuests.DisableControls;
      screen.Cursor := crHourGlass;
      try
        if rSet.Active then
          rSet.Close;
        s := guestsSQL(zReservation);
        hData.rSet_bySQL(rSet, s);
        if mGuests.Active then
          mGuests.Close;
        mGuests.Open;

        mGuests.LoadFromDataSet(rSet, []);

      finally
        screen.Cursor := crDefault;
        mGuests.EnableControls;
      end;
    finally
      FreeAndNil(rSet);
    end;
  end;

  rSet := CreateNewDataSet;
  try

    rSet.CommandType := cmdText;

    mAllGuests.DisableControls;
    screen.Cursor := crHourGlass;
    try
      if rSet.Active then
        rSet.Close;
      s := allGuestsSQL(zReservation);
      hData.rSet_bySQL(rSet, s);

      mAllGuests.AfterScroll := nil;
      try
        if mAllGuests.Active then
          mAllGuests.Close;
        mAllGuests.Open;

        mAllGuests.LoadFromDataSet(rSet);

        mAllGuests.Locate('RoomReservation', gotoRoomReservation, []);
        result := true;
      finally
        mAllGuests.AfterScroll := mAllGuestsAfterScroll;
      end;
    finally
      screen.Cursor := crDefault;
      mAllGuests.EnableControls;
      mAllGuestsAfterScroll(mAllGuests);
    end;
  finally
    FreeAndNil(rSet);
  end;
end;

function TfrmReservationProfile.getInvoiceData(gotoRoomReservation: Integer): Boolean;
var
  rSet: TRoomerDataSet;
  s: string;
  InvoiceNumber: longInt;
  SplitNumber: Integer;
  InvoiceDate: TDate;
  dueDate: TDate;
  reservation: longInt;
  roomReservation: longInt;
  Customer: string;
  NameOnInvoice: string;
  Address1: string;
  Address2: string;
  Address3: string;
  ihAmountWithTax: double;
  ihAmountNoTax: double;
  ihAmountTax: double;
  CreditInvoice: Integer;
  OriginalInvoice: Integer;
  RoomGuest: string;
  invRefrence: string;

  Item: string;
  Quantity: double; // -96
  description: string;
  price: double;
  VATType: String;
  ilAmountWithTax: double;
  ilAmountNoTax: double;
  ilAmountTax: double;
  Currency: string;
  CurrencyRate: double;
  ImportRefrence: string;
  ImportSource: string;

  lastInvoiceNumber: longInt;

  PayTypes: string;
  payTypeDescription: string;
  PayGroups: string;
  PayGroupDescription: string;

begin
  result := false;
  rSet := CreateNewDataSet;
  try

    rSet.CommandType := cmdText;

    mInvoiceHeads.DisableControls;
    mInvoiceLines.DisableControls;
    screen.Cursor := crHourGlass;
    try
      s := InvoiceSQL(zReservation);
      hData.rSet_bySQL(rSet, s);

      mInvoiceHeads.Close;
      mInvoiceHeads.Open;

      mInvoiceLines.Close;
      mInvoiceLines.Open;

      lastInvoiceNumber := -1;

      rSet.First;
      while not rSet.Eof do
      begin
        InvoiceNumber := rSet.fieldbyname('InvoiceNumber').asInteger;

        if InvoiceNumber <> lastInvoiceNumber then
        begin
          lastInvoiceNumber := InvoiceNumber;

          SplitNumber := rSet.fieldbyname('SplitNumber').asInteger;
          InvoiceDate := rSet.fieldbyname('InvoiceDate').AsDateTime;
          dueDate := rSet.fieldbyname('dueDate').AsDateTime;
          reservation := rSet.fieldbyname('Reservation').asInteger;
          roomReservation := rSet.fieldbyname('RoomReservation').asInteger;
          Customer := rSet.fieldbyname('Customer').asstring;
          NameOnInvoice := rSet.fieldbyname('NameOnInvoice').asstring;
          Address1 := rSet.fieldbyname('Address1').asstring;
          Address2 := rSet.fieldbyname('Address2').asstring;
          Address3 := rSet.fieldbyname('Address3').asstring;
          ihAmountWithTax := rSet.fieldbyname('ihAmountWithTax').AsFloat;
          ihAmountNoTax := rSet.fieldbyname('ihAmountNoTax').AsFloat;
          ihAmountTax := rSet.fieldbyname('ihAmountTax').AsFloat;
          CreditInvoice := rSet.fieldbyname('CreditInvoice').asInteger;
          OriginalInvoice := rSet.fieldbyname('OriginalInvoice').asInteger;
          RoomGuest := rSet.fieldbyname('RoomGuest').asstring;
          invRefrence := rSet.fieldbyname('invRefrence').asstring;

          d.IH_getPaymentsTypes(InvoiceNumber, PayTypes, payTypeDescription,
            PayGroups, PayGroupDescription

            );

          mInvoiceHeads.Insert;
          mInvoiceHeads.fieldbyname('InvoiceNumber').asInteger := InvoiceNumber;
          mInvoiceHeads.fieldbyname('SplitNumber').asInteger := SplitNumber;
          mInvoiceHeads.fieldbyname('InvoiceDate').AsDateTime := InvoiceDate;
          mInvoiceHeads.fieldbyname('dueDate').AsDateTime := dueDate;
          mInvoiceHeads.fieldbyname('Reservation').asInteger := reservation;
          mInvoiceHeads.fieldbyname('RoomReservation').asInteger := roomReservation;
          mInvoiceHeads.fieldbyname('Customer').asstring := Customer;
          mInvoiceHeads.fieldbyname('NameOnInvoice').asstring := NameOnInvoice;
          mInvoiceHeads.fieldbyname('Address1').asstring := Address1;
          mInvoiceHeads.fieldbyname('Address2').asstring := Address2;
          mInvoiceHeads.fieldbyname('Address3').asstring := Address3;
          mInvoiceHeads.fieldbyname('AmountWithTax').AsFloat := ihAmountWithTax;
          mInvoiceHeads.fieldbyname('AmountNoTax').AsFloat := ihAmountNoTax;
          mInvoiceHeads.fieldbyname('AmountTax').AsFloat := ihAmountTax;
          mInvoiceHeads.fieldbyname('CreditInvoice').asInteger := CreditInvoice;
          mInvoiceHeads.fieldbyname('OriginalInvoice').asInteger := OriginalInvoice;
          mInvoiceHeads.fieldbyname('RoomGuest').asstring := RoomGuest;
          mInvoiceHeads.fieldbyname('invRefrence').asstring := invRefrence;
          mInvoiceHeads.fieldbyname('PayTypes').asstring := PayTypes;
          mInvoiceHeads.fieldbyname('PayTypeDescription').asstring := payTypeDescription;
          mInvoiceHeads.fieldbyname('payGroups').asstring := PayGroups;
          mInvoiceHeads.fieldbyname('payGroupDescription').asstring := PayGroupDescription;
          mInvoiceHeads.fieldbyname('room').asstring := RR_GetRoomNumber(roomReservation);
          mInvoiceHeads.Post;
        end;

        Item := rSet.fieldbyname('Item').asstring;
        Quantity := rSet.fieldbyname('Quantity').AsFloat; // -96
        description := rSet.fieldbyname('Description').asstring;
        price := rSet.fieldbyname('Price').AsFloat;
        VATType := rSet.fieldbyname('VATType').asstring;
        ilAmountWithTax := rSet.fieldbyname('ilAmountWithTax').AsFloat;
        ilAmountNoTax := rSet.fieldbyname('ilAmountNoTax').AsFloat;
        ilAmountTax := rSet.fieldbyname('ilAmountTax').AsFloat;
        Currency := rSet.fieldbyname('Currency').asstring;
        CurrencyRate := rSet.fieldbyname('CurrencyRate').AsFloat;
        ImportRefrence := rSet.fieldbyname('ImportRefrence').asstring;
        ImportSource := rSet.fieldbyname('ImportSource').asstring;

        mInvoiceLines.Insert;
        mInvoiceLines.fieldbyname('InvoiceNumber').asInteger := InvoiceNumber;
        mInvoiceLines.fieldbyname('Item').asstring := Item;
        mInvoiceLines.fieldbyname('Quantity').AsFloat := Quantity;
        mInvoiceLines.fieldbyname('Description').asstring := description;
        mInvoiceLines.fieldbyname('Price').AsFloat := price;
        mInvoiceLines.fieldbyname('VATType').asstring := VATType;
        mInvoiceLines.fieldbyname('AmountWithTax').AsFloat := ilAmountWithTax;
        mInvoiceLines.fieldbyname('AmountNoTax').AsFloat := ilAmountNoTax;
        mInvoiceLines.fieldbyname('AmountTax').AsFloat := ilAmountTax;
        mInvoiceLines.fieldbyname('Currency').asstring := Currency;
        mInvoiceLines.fieldbyname('CurrencyRate').AsFloat := CurrencyRate;
        mInvoiceLines.fieldbyname('ImportRefrence').asstring := ImportRefrence;
        mInvoiceLines.fieldbyname('ImportSource').asstring := ImportSource;
        mInvoiceLines.Post;
        rSet.Next
      end;
    finally
      screen.Cursor := crDefault;
      mInvoiceHeads.EnableControls;
      mInvoiceLines.EnableControls;
    end;
  finally
    FreeAndNil(rSet);
  end;

end;

procedure TfrmReservationProfile.btnGuestsRefreshClick(Sender: TObject);
begin
  getGuestData(zRoomReservation);
end;

procedure TfrmReservationProfile.btnExcelClick(Sender: TObject);
var
  sFilename: string;
  s: string;
begin
  datetimeTostring(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_Res' + inttostr(zReservation);
  ExportGridToExcel(sFilename, grRooms, false, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil,
    sw_shownormal);
end;

procedure TfrmReservationProfile.btnExpandClick(Sender: TObject);
begin
  tvGuestRooms.BeginUpdate();
  tvGuestRooms.ViewData.Expand(true);
  tvGuestRooms.EndUpdate;
end;

procedure TfrmReservationProfile.btnCollapseClick(Sender: TObject);
begin
  tvGuestRooms.BeginUpdate();
  tvGuestRooms.ViewData.Collapse(true);
  tvGuestRooms.EndUpdate;
end;

procedure TfrmReservationProfile.cxButton1Click(Sender: TObject);
begin
  getInvoiceData(zRoomReservation);
end;

procedure TfrmReservationProfile.btnInvoiceheadsExcelClick(Sender: TObject);
var
  sFilename: string;
  s: string;
begin
  tvInvoiceHeads.ViewData.Collapse(true);
  datetimeTostring(s, 'yyyymmddhhnn', now);
  sFilename := g.qProgramPath + s + '_ResInvoices';
  ExportGridToExcel(sFilename, Grid, false, true, true);
  ShellExecute(Handle, 'OPEN', PChar(sFilename + '.xls'), nil, nil,
    sw_shownormal);
end;

procedure TfrmReservationProfile.btnMainGuestEditProfileClick(Sender: TObject);
begin
  ShowMainGuestProfile;
  UpdateGuestDetails(mRoomsRoomReservation.AsInteger);
end;

procedure TfrmReservationProfile.btnMainGuestSelectProfileClick(Sender: TObject);
begin
  SelectMainGuestProfile;
  UpdateGuestDetails(mRoomsRoomReservation.AsInteger);
end;

procedure TfrmReservationProfile.btnManagePayCardsClick(Sender: TObject);
begin
  ManagePaymentCards(zReservation, -1);
  LoadAllTokens(zReservation, -1, tokens);
  mRoomsAfterScroll(mRooms);
end;

procedure TfrmReservationProfile.PageNotesChange(Sender: TObject);
var
  HiddenInfo: string;
  ChannelRequest: String;
begin
  d.RR_GetMemoBothTextForRoom(zRoomReservation, HiddenInfo, ChannelRequest);
  memRoomNotes.Lines.text := HiddenInfo;
  memRequestFromChannel.Lines.text := ChannelRequest;
end;

procedure TfrmReservationProfile.timBlinkTimer(Sender: TObject);
begin
  timBlink.enabled := false;
  timBlink.Tag := timBlink.Tag + 1;
  if timBlink.Tag < 7 then
  begin
    btnDocuments.SkinData.CustomColor := NOT(timBlink.Tag div 2 = timBlink.Tag / 2);
    if btnDocuments.SkinData.CustomColor then
    begin
      btnDocuments.SkinData.ColorTone := clRed;
      timBlink.Interval := 500;
    end
    else
    begin
      btnDocuments.SkinData.ColorTone := clNone;
      timBlink.Interval := 250;
    end;
    timBlink.enabled := true;
  end
  else
  begin
    btnDocuments.SkinData.ColorTone := clNone;
    btnDocuments.SkinData.CustomColor := false;
  end;
end;

procedure TfrmReservationProfile.timStartTimer(Sender: TObject);
var
  lSavedAfterScroll: TDatasetNotifyEvent;
  lSavedBeforePost: TDatasetNotifyEvent;
begin
  timStart.enabled := false;
  LoadAllTokens(zReservation, zRoomReservation, tokens);
  lSavedAfterScroll := mRooms.AfterScroll;
  lSavedBeforePost := mRooms.BeforePost;
  try
    FInitializingData := True;
    mRooms.AfterScroll := nil;
    mROoms.BeforePost := nil;
    Display;
    getGuestData(-1);
  finally
    FInitializingData := False;
    mRooms.AfterScroll := lSavedAfterScroll;
    mRooms.BeforePost := lSavedBeforePost;
    Enabled := true;
  end;

  if assigned(mRooms.AfterScroll) then
    mRooms.AfterScroll(mRooms);
  ShowAlertsForReservation(zReservation, 0, atOPEN_RESERVATION);
  AlertList := CreateAlertsForRoomReservation(zReservation, 0, atUNKNOWN);
  FrmAlertPanel.PlaceEditPanel(pnlAlertHolder, AlertList);
  if zRoomReservation = 0 then
    mRooms.First;
end;

procedure TfrmReservationProfile.tvAllGuestsBreakfastGetDisplayText(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  aText := TBreakfastType.FromDBString(aRecord.values[sender.Index]).AsReadableString;
end;

procedure TfrmReservationProfile.tvAllGuestsCanFocusRecord
  (Sender: TcxCustomGridTableView; ARecord: TcxCustomGridRecord;
  var AAllow: Boolean);
var
  AValue: Variant;
  rr: longInt;
  HiddenInfo: string;
  ChannelRequest: String;
begin
  AValue := ARecord.Values[0];
  rr := AValue;
  if zInt <> rr then
  begin
    if mAllGuests.Locate('roomReservation', rr, []) then
    begin
      zRoomReservation := mAllGuests.fieldbyname('Roomreservation').asInteger;
      d.RR_GetMemoBothTextForRoom(zRoomReservation, HiddenInfo, ChannelRequest);
      memRoomNotes.Lines.text := HiddenInfo;
      memRequestFromChannel.Lines.text := ChannelRequest;
    end;
  end;
  zInt := rr;
end;

procedure TfrmReservationProfile.tvGuestRoomsBreakfastGetDisplayText(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  aText := TBreakfastType.FromDBString(aRecord.values[sender.Index]).AsReadableString;
end;

procedure TfrmReservationProfile.tvGuestRoomsCanFocusRecord
  (Sender: TcxCustomGridTableView; ARecord: TcxCustomGridRecord;
  var AAllow: Boolean);
var
  AValue: Variant;
  rr: longInt;
  HiddenInfo: string;
  ChannelRequest: String;
begin
  AValue := ARecord.Values[0];
  rr := AValue;
  if rr <> zRoomReservation then
  begin
    zRoomReservation := rr;
    d.RR_GetMemoBothTextForRoom(zRoomReservation, HiddenInfo, ChannelRequest);
    memRoomNotes.Lines.text := HiddenInfo;
    memRequestFromChannel.Lines.text := ChannelRequest;
  end;
end;

procedure TfrmReservationProfile.tvGuestsCanFocusRecord(Sender: TcxCustomGridTableView; ARecord: TcxCustomGridRecord;
  var AAllow: Boolean);
var
  AValue: Variant;
  rr: longInt;
  HiddenInfo: string;
  ChannelRequest: String;
begin
  AValue := ARecord.Values[2];
  rr := AValue;
  if rr <> zRoomReservation then
  begin
    if mGuests.Locate('roomReservation', rr, []) then
    begin
      zRoomReservation := rr;
      d.RR_GetMemoBothTextForRoom(zRoomReservation, HiddenInfo, ChannelRequest);
      memRoomNotes.Lines.text := HiddenInfo;
      memRequestFromChannel.Lines.text := ChannelRequest;
    end;
  end;
end;

procedure TfrmReservationProfile.tvInvoiceHeadsAmountNoTaxGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmReservationProfile.tvInvoiceHeadsAmountTaxGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  AProperties := d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmReservationProfile.tvGetNativeCurrentProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord;
  var AProperties: TcxCustomEditProperties);
begin
  RoomerCurrencyManager.DefaultCurrencyDefinition.SetcxEditProperties(aProperties);
end;


{ TsCombobox }

procedure TfrmReservationProfile.UpdateStateActions;
var
  lRoomStateChanger: TRoomReservationStateChangeHandler;
  i: integer;
begin

  lRoomStateChanger := FReservationChangeStateHandler.RoomStateChangeHandler[mRoomsRoomReservation.AsInteger];

  acCheckOutRoom.Enabled := mRooms.Active and not mRooms.Eof and lRoomStateChanger.ChangeIsAllowed(rsDeparted);
  acCheckOutRoom.Caption := FOrigAcCheckoutRoomCaption + ' '+ mRoomsRoom.AsString;

  acCheckInRoom.Enabled := mRooms.Active and not mRooms.Eof and lRoomStateChanger.ChangeIsAllowed(rsGuests);
  acCheckInRoom.Caption := FOrigAcCheckInRoomCaption + ' '+ mRoomsRoom.AsString;

  if acCheckInROom.Enabled then
    btnCheckIn.Action := acCheckinRoom
  else
  begin
    btnCheckIn.Action := nil;
    btnCheckIn.OnCLick := nil;
    btnCheckin.Caption := GetTranslatedText('shTx_FrmReservationprofile_ChangeStatus');
    btnCheckin.Enabled := true;
  end;

  mnuChangeRoomStateTo.Caption := FOrigmnuChangeRoomStateToCaption + ' '+ mRoomsRoom.AsString;
  for i := 0 to mnuChangeRoomStateTo.Count-1 do
    mnuChangeRoomStateTo.Items[i].Enabled := lRoomStateChanger.ChangeIsAllowed(TReservationState(mnuChangeRoomStateTo.Items[i].tag));

  for i := 0 to mnuChangeResStateTo.Count-1 do
    mnuChangeResStateTo.Items[i].Enabled := FReservationChangeStateHandler.ChangeIsAllowed(TReservationState(mnuChangeResStateTo.Items[i].tag));

  acCheckinReservation.Enabled := mRooms.Active and not mRooms.Eof and FReservationChangeStateHandler.ChangeIsAllowed(rsGuests);
  acCheckOutReservation.Enabled := mRooms.Active and not mRooms.Eof and FReservationChangeStateHandler.ChangeIsAllowed(rsDeparted);

end;

procedure TfrmReservationProfile.mnuOtherRoomStateChangeClick(Sender: TObject);
var
  lMenu: TMenuItem;
  lRoomStateChanger: TRoomReservationStateChangeHandler;
begin
  lMenu := TMenuItem(Sender);
  lRoomStateChanger := FReservationChangeStateHandler.RoomStateChangeHandler[mRoomsRoomReservation.AsInteger];
  if lRoomStateChanger.ChangeState(TReservationState(lMenu.Tag)) then
    Display_rGrid(mRoomsRoomReservation.ASInteger);
end;

procedure TfrmReservationProfile.mnuOtherResStateChangeClick(Sender: TObject);
var
  lMenu: TMenuItem;
begin
  lMenu := TMenuItem(Sender);
  if FReservationChangeStateHandler.ChangeState(TReservationState(lMenu.Tag)) then
  begin
    Display_rGrid(mRoomsRoomReservation.ASInteger);
    if FReservationChangeStateHandler.CurrentState = rsCancelled then
      Close;
  end;
end;


procedure TfrmReservationProfile.ConstructOtherResStateMenu;

  procedure lclAddMenuitemsTo(aParentMenu: TMenuItem; aHandler: TNotifyEvent);
  var
    lState: TReservationState;
    lMenu: TMenuItem;
  begin
    aParentMenu.Clear;
    for lState := low(lState) to High(lState) do
      if lState.IsUserSelectable then
      begin
        lMenu := TMenuItem.Create(self);
        aParentMenu.Add(lMenu);
        lMenu.Caption := lState.AsReadableString;
        lMenu.Tag := ord(lState);
        lMenu.OnClick := aHandler;
      end;
  end;

begin
  lclAddMenuitemsto(mnuChangeRoomStateTo, mnuOtherRoomStateChangeClick);
  lclAddMenuitemsTo(mnuChangeResStateTo, mnuOtherResStateChangeClick);
end;

constructor TfrmReservationProfile.Create(aOwner: TCOmponent);
begin
  inherited;
  FColumnHeaderPopupActivator := TcxGridColumnHeaderPopupMenuActivator.Create(mnuRoomColumn);
end;

end.
