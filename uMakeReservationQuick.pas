unit uMakeReservationQuick;

interface

uses
  Windows,
  Messages,
  system.SysUtils,
  system.Variants,
  system.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.Menus,
  Vcl.StdCtrls,
  Vcl.Buttons,
  Vcl.ExtCtrls,
  Vcl.Mask,
  Vcl.ComCtrls,
  hData,
  Data.DB,
  Data.Win.ADODB,
  objNewReservation,
  objHomeCustomer,
  cxPCdxBarPopupMenu,
  cxGraphics,
  cxControls,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  cxContainer,
  cxEdit,
  dxCore,
  cxDateUtils,
  cxStyles,
  cxCustomData,
  cxFilter,
  cxData,
  cxDataStorage,
  cxNavigator,
  cxDBData,
  cxTextEdit,
  cxButtonEdit,
  cxSpinEdit,
  cxCalc,
  dxmdaset,
  cxButtons,
  cxGridLevel,
  cxGridCustomTableView,
  cxGridTableView,
  cxGridDBTableView,
  cxClasses,
  cxGridCustomView,
  cxGrid,
  cxDropDownEdit,
  cxCalendar,
  cxCheckBox,
  cxMaskEdit,
  cxLabel,
  cxGroupBox,
  cxPC,
  cxGridBandedTableView,
  cxGridDBBandedTableView,
  cxPropertiesStore,
  cxLookupEdit,
  cxDBLookupEdit,
  cxDBLookupComboBox,
  cmpRoomerDataSet,
  cmpRoomerConnection,
  objRoomRates,
  kbmMemTable,
  uUtils,
  uAlerts,
  uAlertEditPanel,
  sPanel,
  sSkinProvider,
  sGroupBox,
  sLabel,
  sCheckBox,
  sButton,
  sPageControl,
  sEdit,
  sSpinEdit,
  sBevel,
  dxSkinsCore,
  dxSkinDarkSide,
  dxSkinDevExpressDarkStyle,
  dxSkinMcSkin,
  dxSkinOffice2013White,
  dxSkinsDefaultPainters,
  dxSkinscxPCPainter,
  sMemo,
  sMaskEdit,
  sCustomComboEdit,
  sTooledit,
  sComboBox,
  sSpeedButton,
  uDImages,
  Vcl.DBCtrls,
  dxSkinCaramel,
  dxSkinCoffee,
  dxSkinTheAsphaltWorld,
  dxSkinBlack,
  dxSkinBlue,
  dxSkinBlueprint,
  dxSkinDarkRoom,
  dxSkinDevExpressStyle,
  dxSkinFoggy,
  dxSkinGlassOceans,
  dxSkinHighContrast,
  dxSkiniMaginary,
  dxSkinLilian,
  dxSkinLiquidSky,
  dxSkinLondonLiquidSky,
  dxSkinMoneyTwins,
  dxSkinOffice2007Black,
  dxSkinOffice2007Blue,
  dxSkinOffice2007Green,
  dxSkinOffice2007Pink,
  dxSkinOffice2007Silver,
  dxSkinOffice2010Black,
  dxSkinOffice2010Blue,
  dxSkinOffice2010Silver,
  dxSkinPumpkin,
  dxSkinSeven,
  dxSkinSevenClassic,
  dxSkinSharp,
  dxSkinSharpPlus,
  dxSkinSilver,
  dxSkinSpringTime,
  dxSkinStardust,
  dxSkinSummer2008,
  dxSkinValentine,
  dxSkinVS2010,
  dxSkinWhiteprint,
  dxSkinXmas2008Blue,
  uRoomerFilterComboBox,
  system.Generics.Collections,
  uDynamicRates,
  sListView,
  sCurrencyEdit
  , RoomerCurrencyEdit
  , cxTimeEdit, AdvSplitter
  , cxDBLabel, Datasnap.DBClient
  , uFraCountryPanel
  , ufraCurrencyPanel
  , uFraMarketSegmentPanel
  , uRoomerCurrencyDefinition
  , uFraLookupPanel, sCurrEdit, cxCurrencyEdit
  , uFraPriceCodePanel
  , uFraCustomerPanel
    ;

TYPE
  recRoomRate = record
    Reservation: integer;
    RoomReservation: integer;
    RoomNumber: string;
    RateDate: integer;
    PriceCode: string;
    Rate: double;
    Discount: double;
    isPrecentage: boolean;
    ShowDiscount: boolean;
    isPaid: boolean;
    DiscountAmount: double;
    RentAmount: double;
    NativeAmount: double;
  end;

type
  TfrmMakeReservationQuick = class(TForm)
    mRoomResDS: TDataSource;
    mSelectTypes: TdxMemData;
    mSelectTypesRoomtype: TStringField;
    mSelectTypesRoomTypeDescription: TStringField;
    mSelectTypesDS: TDataSource;
    mSelectTypesSelected: TIntegerField;
    mSelectRooms: TdxMemData;
    mSelectRoomsRoom: TStringField;
    mSelectRoomsDS: TDataSource;
    panBottom: TsPanel;
    btnCancel: TsButton;
    btnNext: TsButton;
    btnPrevius: TsButton;
    btnFinish: TsButton;
    pnlNotes: TsPanel;
    panNotesPayment: TsPanel;
    Panel7: TsPanel;
    panNotesGeneral: TsPanel;
    Panel11: TsPanel;
    clabGeneralNotes: TsLabel;
    memReservationGeneralInfo: TsMemo;
    mRoomRatesDS: TDataSource;
    mSelectTypesNoRooms: TIntegerField;
    mDS: TDataSource;
    mOcc_: TdxMemData;
    mOcc_Roomtype: TStringField;
    mOcc_aDate: TDateTimeField;
    mOcc_isNoRoom: TBooleanField;
    mOcc_Status: TStringField;
    mOcc_RoomCount: TIntegerField;
    mOccDS: TDataSource;
    m_: TdxMemData;
    m_RoomType: TStringField;
    m_aDate: TDateTimeField;
    m_RoomTypeGroup: TStringField;
    m_MaxFree: TIntegerField;
    m_occTotal: TIntegerField;
    m_occDeparted: TIntegerField;
    m_occGuest: TIntegerField;
    m_occOrder: TIntegerField;
    m_occAllotment: TIntegerField;
    m_occWaitinglist: TIntegerField;
    m_occNoShow: TIntegerField;
    m_occBlocked: TIntegerField;
    m_nrTotal: TIntegerField;
    m_nrDeparted: TIntegerField;
    m_nrGuest: TIntegerField;
    m_nrOrder: TIntegerField;
    m_nrAllotment: TIntegerField;
    m_nrWaitingList: TIntegerField;
    m_nrNoShow: TIntegerField;
    m_nrBlocked: TIntegerField;
    m_FreeRooms: TIntegerField;
    m_Description: TStringField;
    mSelectRoomsRoomType: TStringField;
    mSelectRoomsDescription: TStringField;
    mSelectRoomsDetailedDescription: TMemoField;
    mSelectRoomsSqrMeters: TFloatField;
    mSelectRoomsBedSize: TStringField;
    mSelectRoomsEquipments: TStringField;
    mSelectRoomsBookable: TBooleanField;
    mSelectRoomsStatistics: TBooleanField;
    mSelectRoomsStatus: TStringField;
    mSelectRoomsOrderIndex: TIntegerField;
    mSelectRoomshidden: TBooleanField;
    mSelectRoomsLocation: TStringField;
    mSelectRoomsFloor: TIntegerField;
    mSelectRoomsID: TStringField;
    mSelectRoomsDorm: TStringField;
    mSelectRoomsuseInNationalReport: TBooleanField;
    mSelectRoomsActive: TBooleanField;
    mSelectRoomsLocationDescription: TStringField;
    mSelectRoomsRoomTypeDescription: TStringField;
    mSelectRoomsRoomTypeGroupDescription: TStringField;
    mSelectRoomsBath: TBooleanField;
    mSelectRoomsShower: TBooleanField;
    mSelectRoomsSafe: TBooleanField;
    mSelectRoomsTV: TBooleanField;
    mSelectRoomsVideo: TBooleanField;
    mSelectRoomsRadio: TBooleanField;
    mSelectRoomsCDPlayer: TBooleanField;
    mSelectRoomsTelephone: TBooleanField;
    mSelectRoomsPress: TBooleanField;
    mSelectRoomsCoffee: TBooleanField;
    mSelectRoomsKitchen: TBooleanField;
    mSelectRoomsMinibar: TBooleanField;
    mSelectRoomsFridge: TBooleanField;
    mSelectRoomsHairdryer: TBooleanField;
    mSelectRoomsInternetPlug: TBooleanField;
    mSelectRoomsFax: TBooleanField;
    mSelectRoomsNumberGuests: TIntegerField;
    mSelectRoomsRoomTypeGroup: TStringField;
    mSelectRoomsSelect: TBooleanField;
    mSelectRoomstmp: TStringField;
    mSelectTypesAvailable: TIntegerField;
    mSelectTypesTotalFree: TIntegerField;
    mSelectTypesRoomsSelected: TIntegerField;
    mSelectTypesPriorityRule: TStringField;
    StoreMain: TcxPropertiesStore;
    panRoomNotes: TsPanel;
    clabPaymentNotes: TsLabel;
    sPanel6: TsPanel;
    clabRoomNotes: TsLabel;
    btnClearLog: TsButton;
    sButton2: TsButton;
    sButton5: TsButton;
    sButton6: TsButton;
    sButton7: TsButton;
    mnuFinish: TPopupMenu;
    mnuFinishAndShow: TMenuItem;
    memReservationPaymentInfo: TsMemo;
    memRoomNotes: TDBMemo;
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
    mROomResPersonsProfilesID: TIntegerField;
    mRoomResroomNotes: TMemoField;

    mRoomRates: TdxMemData;
    mRoomRatesReservation: TIntegerField;
    mRoomRatesroomreservation: TIntegerField;
    mRoomRatesRoomNumber: TStringField;
    mRoomRatesRateDate: TDateField;
    mRoomRatesPriceCode: TStringField;
    mRoomRatesRate: TFloatField;
    mRoomRatesDiscount: TFloatField;
    mRoomRatesisPercentage: TBooleanField;
    mRoomRatesShowDiscount: TBooleanField;
    mRoomRatesisPaid: TBooleanField;
    mRoomRatesDiscountAmount: TFloatField;
    mRoomRatesRentAmount: TFloatField;
    mRoomRatesNativeAmount: TFloatField;
    mRoomRatesCurrency: TStringField;
    mRoomRatesCurrencyRate: TFloatField;
    mRoomResPackagePrice: TFloatField;
    mRoomResMainGuest: TWideStringfield;

    mRoomRatesTmp: TdxMemData;
    mRoomRatesTmpReservation: TIntegerField;
    mRoomRatesTmproomreservation: TIntegerField;
    mRoomRatesTmpRoomNumber: TStringField;
    mRoomRatesTmpRateDate: TDateField;
    mRoomRatesTmpPriceCode: TStringField;
    mRoomRatesTmpRate: TFloatField;
    mRoomRatesTmpDiscount: TFloatField;
    mRoomRatesTmpisPercentage: TBooleanField;
    mRoomRatesTmpShowDiscount: TBooleanField;
    mRoomRatesTmpisPaid: TBooleanField;
    mRoomRatesTmpDiscountAmount: TFloatField;
    mRoomRatesTmpRentAmount: TFloatField;
    mRoomRatesTmpNativeAmount: TFloatField;
    mRoomRatesTmpCurrency: TStringField;
    mRoomRatesTmpCurrencyRate: TFloatField;

    mRatesEdit: TdxMemData;
    mRatesEditReservation: TIntegerField;
    mRatesEditroomreservation: TIntegerField;
    mRatesEditRoomNumber: TStringField;
    mRatesEditRateDate: TDateField;
    mRatesEditPriceCode: TStringField;
    mRatesEditRate: TFloatField;
    mRatesEditDiscount: TFloatField;
    mRatesEditisPercentage: TBooleanField;
    mRatesEditShowDiscount: TBooleanField;
    mRatesEditisPaid: TBooleanField;
    mRatesEditDiscountAmount: TFloatField;
    mRatesEditRentAmount: TFloatField;
    mRatesEditNativeAmount: TFloatField;
    mRatesEditCurrency: TStringField;
    mRatesEditCurrencyRate: TFloatField;

    mRoomResRatePlanCode: TStringField;
    mRoomResManualChannelId: TIntegerField;
    cxStyleRepository1: TcxStyleRepository;
    cxStyle1: TcxStyle;
    cxStyle2: TcxStyle;
    cxStyle3: TcxStyle;
    mRoomResExpectedTimeOfArrival: TStringField;
    mRoomResExpectedCheckOutTime: TStringField;
    mRoomResStockItemsCount: TIntegerField;
    mRoomResStockitemsPrice: TFloatField;
    mExtras: TdxMemData;
    mExtrasRoomreservation: TIntegerField;
    mExtrasItemid: TIntegerField;
    mExtrasCount: TIntegerField;
    mExtrasPricePerItemPerDay: TFloatField;
    mExtrasFromdate: TDateTimeField;
    mExtrasToDate: TDateTimeField;
    mExtrasItem: TStringField;
    mExtrasDescription: TStringField;
    mExtrasTotalPrice: TFloatField;
    m_nrWaitingListNonOptional: TIntegerField;
    m_occWaitingListNonOptional: TIntegerField;
    pgcMain: TsPageControl;
    taReservation: TsTabSheet;
    panTop: TsPanel;
    Panel2: TsPanel;
    gbxGetCustomer: TsGroupBox;
    clabCustomer: TsLabel;
    lblPortfolio: TsLabel;
    gbxGetReservation: TsGroupBox;
    sLabel9: TsLabel;
    clabMarketSegmentCode: TsLabel;
    lblMarket: TsLabel;
    lblCountry: TsLabel;
    edInvRefrence: TsEdit;
    cbxMarket: TsComboBox;
    gbxDates: TsGroupBox;
    clabArrival: TsLabel;
    clabdeparture: TsLabel;
    clabNights: TsLabel;
    edNights: TsSpinEdit;
    gbxRate: TsGroupBox;
    clabCurrency: TsLabel;
    clabPcCode: TsLabel;
    pgcMoreInfo: TsPageControl;
    tabContactDetails: TsTabSheet;
    sPanel3: TsPanel;
    AdvSplitter1: TAdvSplitter;
    gbxContact: TsGroupBox;
    clabContactPerson: TsLabel;
    clabContactAddress: TsLabel;
    clabContactFax: TsLabel;
    clabContactEmail: TsLabel;
    lblContactZip: TsLabel;
    lblContactCity: TsLabel;
    lblNew: TsLabel;
    edContactAddress1: TsEdit;
    edContactAddress2: TsEdit;
    edContactAddress3: TsEdit;
    edContactAddress4: TsEdit;
    chkContactIsGuest: TsCheckBox;
    edContactFax: TsEdit;
    cbxAddToGuestProfiles: TsCheckBox;
    gbxProfileAlert: TsGroupBox;
    lblSpecialRequests: TsLabel;
    lblNotes: TsLabel;
    edtSpecialRequests: TMemo;
    edtNotes: TMemo;
    gbxRoomAlert: TsGroupBox;
    lblRoomType: TsLabel;
    lblRoom: TsLabel;
    edtRoom: TsEdit;
    edtRoomType: TsEdit;
    gbxCustomerAlert: TsGroupBox;
    memCustomerAlert: TMemo;
    tabCustomerDetails: TsTabSheet;
    clabTel2: TsLabel;
    sPanel1: TsPanel;
    clabPID: TsLabel;
    clabCustomerName: TsLabel;
    clabAddress1: TsLabel;
    clabWebSite: TsLabel;
    clabEmail: TsLabel;
    clabFax: TsLabel;
    clabTel1: TsLabel;
    edPID: TsEdit;
    edCustomerName: TsEdit;
    edAddress1: TsEdit;
    edAddress2: TsEdit;
    edAddress3: TsEdit;
    edTel1: TsEdit;
    edTel2: TsEdit;
    edFax: TsEdit;
    edEmailAddress: TsEdit;
    edHomePage: TsEdit;
    tabSelectType: TsTabSheet;
    panSelectTypesTop: TsPanel;
    gbxSelStatus: TsGroupBox;
    chkExcluteWaitingList: TsCheckBox;
    chkExcluteAllotment: TsCheckBox;
    chkExcluteOrder: TsCheckBox;
    chkExcluteNoShow: TsCheckBox;
    chkExcluteDeparted: TsCheckBox;
    chkExcluteBlocked: TsCheckBox;
    chkExcluteGuest: TsCheckBox;
    chkExcludeWaitingListNonOptional: TsCheckBox;
    sPanel7: TsPanel;
    sLabel1: TsLabel;
    cxButton1: TsButton;
    grSelectType: TcxGrid;
    tvSelectType: TcxGridDBTableView;
    tvSelectTypeRecId: TcxGridDBColumn;
    tvSelectTyperoomType: TcxGridDBColumn;
    tvSelectTypeRoomTypeDescription: TcxGridDBColumn;
    tvSelectTypeAvailable: TcxGridDBColumn;
    tvSelectTypeSelected: TcxGridDBColumn;
    tvSelectTypeTotalFree: TcxGridDBColumn;
    tvSelectTypeNoRooms: TcxGridDBColumn;
    tvSelectTypeRoomsSelected: TcxGridDBColumn;
    tvSelectTypePriorityRule: TcxGridDBColumn;
    lvSelectType: TcxGridLevel;
    sPanel4: TsPanel;
    tabSelectRooms: TsTabSheet;
    panSelectRoomsTop: TsPanel;
    sLabel2: TsLabel;
    labTotalSelected: TsLabel;
    sLabel3: TsLabel;
    labTotalRoomsSelected: TsLabel;
    sLabel5: TsLabel;
    sLabel6: TsLabel;
    btnAutoSelectRooms: TsButton;
    btnSetAllAsNoRoom: TsButton;
    cbxFilterSelectedTypes: TsCheckBox;
    grSelectRooms: TcxGrid;
    tvSelectRooms: TcxGridDBBandedTableView;
    tvSelectRoomsSelect: TcxGridDBBandedColumn;
    tvSelectRoomsRoom: TcxGridDBBandedColumn;
    tvSelectRoomsDescription: TcxGridDBBandedColumn;
    tvSelectRoomsRoomType: TcxGridDBBandedColumn;
    tvSelectRoomsRoomTypeDescription: TcxGridDBBandedColumn;
    tvSelectRoomsRoomTypeGroup: TcxGridDBBandedColumn;
    tvSelectRoomsRoomTypeGroupDescription: TcxGridDBBandedColumn;
    tvSelectRoomsStatus: TcxGridDBBandedColumn;
    tvSelectRoomsLocation: TcxGridDBBandedColumn;
    tvSelectRoomsLocationDescription: TcxGridDBBandedColumn;
    tvSelectRoomsFloor: TcxGridDBBandedColumn;
    tvSelectRoomsNumberGuests: TcxGridDBBandedColumn;
    tvSelectRoomsEquipments: TcxGridDBBandedColumn;
    tvSelectRoomsSqrMeters: TcxGridDBBandedColumn;
    tvSelectRoomsBedSize: TcxGridDBBandedColumn;
    tvSelectRoomsBath: TcxGridDBBandedColumn;
    tvSelectRoomsShower: TcxGridDBBandedColumn;
    tvSelectRoomsActive: TcxGridDBBandedColumn;
    tvSelectRoomsOrderIndex: TcxGridDBBandedColumn;
    tvSelectRoomsuseInNationalReport: TcxGridDBBandedColumn;
    tvSelectRoomsBookable: TcxGridDBBandedColumn;
    tvSelectRoomsStatistics: TcxGridDBBandedColumn;
    tvSelectRoomshidden: TcxGridDBBandedColumn;
    tvSelectRoomsRecId: TcxGridDBBandedColumn;
    tvSelectRoomsID: TcxGridDBBandedColumn;
    tvSelectRoomsDorm: TcxGridDBBandedColumn;
    tvSelectRoomsDetailedDescription: TcxGridDBBandedColumn;
    tvSelectRoomstmp: TcxGridDBBandedColumn;
    lvSelectRooms: TcxGridLevel;
    tabRoomRates: TsTabSheet;
    panTopRoomRates: TsPanel;
    gbxSelectedRoom: TsGroupBox;
    btdEditRoomRate: TsButton;
    sButton3: TsButton;
    sButton4: TsButton;
    gbxRefresh: TsGroupBox;
    btnRefresh: TsButton;
    sButton1: TsButton;
    sPanel5: TsPanel;
    lblChannels: TsLabel;
    cbxChannels: TsComboBox;
    chkAutoUpdateNullPrice: TsCheckBox;
    pgcExtraAndAlert: TsPageControl;
    sTabSheet1: TsTabSheet;
    sPanel2: TsPanel;
    lblExtraCurrency: TsLabel;
    Shape1: TShape;
    lblPerPerson: TsLabel;
    lblPrice: TsLabel;
    edtBreakfastPrice: TsCurrencyEdit;
    Alerts: TsTabSheet;
    grRoomRes: TcxGrid;
    tvRoomRes: TcxGridDBTableView;
    tvRoomResRoomReservation: TcxGridDBColumn;
    tvRoomResColumn1: TcxGridDBColumn;
    tvRoomResRoom: TcxGridDBColumn;
    tvRoomResRoomDescription: TcxGridDBColumn;
    tvRoomResRoomType: TcxGridDBColumn;
    tvRoomResRoomTypeDescription: TcxGridDBColumn;
    tvRoomResArrival: TcxGridDBColumn;
    tvRoomResExpectedTimeOfArrival: TcxGridDBColumn;
    tvRoomResDeparture: TcxGridDBColumn;
    tvRoomResexpectedCheckouttime: TcxGridDBColumn;
    tvRoomResGuests: TcxGridDBColumn;
    tvRoomResChildrenCount: TcxGridDBColumn;
    tvRoomResinfantCount: TcxGridDBColumn;
    tvRoomResMainGuest: TcxGridDBColumn;
    tvRoomResRatePlanCode: TcxGridDBColumn;
    tvRoomResAvragePrice: TcxGridDBColumn;
    __tvRoomResColumn2: TcxGridDBColumn;
    tvRoomResPackage: TcxGridDBColumn;
    tvRoomResPackagePrice: TcxGridDBColumn;
    tvRoomResRateCount: TcxGridDBColumn;
    tvRoomResStockItemsCount: TcxGridDBColumn;
    tvRoomResStockitemsPrice: TcxGridDBColumn;
    tvRoomResAvrageDiscount: TcxGridDBColumn;
    tvRoomResPriceCode: TcxGridDBColumn;
    tvRoomRates: TcxGridDBTableView;
    tvRoomRatesReservation: TcxGridDBColumn;
    tvRoomRatesRoomReservation: TcxGridDBColumn;
    tvRoomRatesRoomNumber: TcxGridDBColumn;
    tvRoomRatesRateDate: TcxGridDBColumn;
    tvRoomRatesPriceCode: TcxGridDBColumn;
    tvRoomRatesRate: TcxGridDBColumn;
    tvRoomRatesDiscount: TcxGridDBColumn;
    tvRoomRatesisPercentage: TcxGridDBColumn;
    tvRoomRatesShowDiscount: TcxGridDBColumn;
    tvRoomRatesisPaid: TcxGridDBColumn;
    tvRoomRatesDiscountAmount: TcxGridDBColumn;
    tvRoomRatesCurrency: TcxGridDBColumn;
    tvRoomRatesCurrencyRate: TcxGridDBColumn;
    tvRoomRatesRentAmount: TcxGridDBColumn;
    tvRoomRatesNativeAmount: TcxGridDBColumn;
    lvRoomRes: TcxGridLevel;
    lvRoomRates: TcxGridLevel;
    edContactPerson1: TcxComboBox;
    fraCurrencyPanel: TfraCurrencyPanel;
    pnlDiscount: TPanel;
    edRoomResDiscount: TsCurrencyEdit;
    cbxIsRoomResDiscountPrec: TsComboBox;
    clabDiscountPerc: TsLabel;
    pnlReservationStatus: TsPanel;
    cbxRoomStatus: TsComboBox;
    chkGroupInvoice: TsCheckBox;
    pnlGuest: TsPanel;
    edtPortfolio: TsEdit;
    btnPortfolioLookup: TsSpeedButton;
    btnPortfolio: TsSpeedButton;
    pnlArrival: TsPanel;
    dtArrival: TsDateEdit;
    __lblArrivalWeekday: TsLabel;
    pnlDeparture: TsPanel;
    __lblDepartureWeekday: TsLabel;
    dtDeparture: TsDateEdit;
    pnlPhones: TsPanel;
    edContactPhone: TsEdit;
    lblContactMobile: TsLabel;
    edContactMobile: TsEdit;
    clabContactPhone: TsLabel;
    pnlEmail: TsPanel;
    edContactEmail: TsEdit;
    chkSendConfirmation: TsCheckBox;
    fraLookupCountry: TfraCountryPanel;
    fraLookupMarketSegment: TfraLookupMarketSegment;
    fraPriceCodePanel: TfraPriceCodePanel;
    fraCustomerPanel: TfraCustomerPanel;
    pnlReservationBaseData: TsPanel;
    clabReservationType: TsLabel;
    edReservationName: TsEdit;
    clabReservationName: TsLabel;
    pnlReservationDetaildata: TsPanel;
    cbxBreakfast: TsComboBox;
    lblBreakfast: TsLabel;
    mRoomResRoomRate: TFloatField;
    mRoomResDiscount: TFloatField;
    mRoomResIsPercentage: TBooleanField;
    tvRoomResRoomRate: TcxGridDBColumn;
    tvRoomResDiscount: TcxGridDBColumn;
    tvRoomResIsPercentage: TcxGridDBColumn;
    procedure FormShow(Sender: TObject);
    procedure btnFinishClick(Sender: TObject);
    procedure btnNextClick(Sender: TObject);
    procedure btnPreviusClick(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure pgcMainChange(Sender: TObject);
    procedure btdEditRoomRateClick(Sender: TObject);
    procedure tvRoomResColumn1PropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
    procedure btnEditRateAllRoomsClick(Sender: TObject);
    procedure btnRefreshClick(Sender: TObject);
    procedure mSelectRoomsNewRecord(DataSet: TDataSet);
    procedure tvSelectRoomsRoomPropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
    procedure tvSelectTypeSelectedPropertiesEditValueChanged(Sender: TObject);
    procedure mSelectTypesCalcFields(DataSet: TDataSet);
    procedure tvSelectRoomsSelectPropertiesEditValueChanged(Sender: TObject);
    procedure btnAutoSelectRoomsClick(Sender: TObject);
    procedure tvRoomResAvragePricePropertiesEditValueChanged(Sender: TObject);
    procedure tvRoomResGuestsPropertiesEditValueChanged(Sender: TObject);
    procedure tvRoomResChildrenCountPropertiesEditValueChanged(Sender: TObject);
    procedure tvRoomResinfantCountPropertiesEditValueChanged(Sender: TObject);
    procedure dtDepartureExit(Sender: TObject);
    procedure dtArrivalExit(Sender: TObject);
    procedure edNightsChange(Sender: TObject);
    procedure btnSetAllAsNoRoomClick(Sender: TObject);
    procedure sButton1Click(Sender: TObject);
    procedure tvSelectTypeSelectedPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
      var Error: boolean);
    procedure tvSelectTypeNoRoomsPropertiesValidate(Sender: TObject; var DisplayValue: Variant; var ErrorText: TCaption;
      var Error: boolean);
    procedure sButton4Click(Sender: TObject);
    procedure sButton3Click(Sender: TObject);
    procedure btnClearLogClick(Sender: TObject);
    procedure sButton2Click(Sender: TObject);
    procedure sButton5Click(Sender: TObject);
    procedure sButton6Click(Sender: TObject);
    procedure sButton7Click(Sender: TObject);
    procedure dtArrivalCloseUp(Sender: TObject);
    procedure dtDepartureCloseUp(Sender: TObject);
    procedure dtArrivalChange(Sender: TObject);
    procedure dtDepartureChange(Sender: TObject);
    procedure evtCurrencyChangedAndValid(Sender: TObject);
    procedure mnuFinishAndShowClick(Sender: TObject);
    procedure tvRoomResPackagePropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
    procedure cbxRoomStatusChange(Sender: TObject);
    procedure edContactEmailChange(Sender: TObject);
    procedure btnPortfolioClick(Sender: TObject);
    procedure btnPortfolioLookupClick(Sender: TObject);
    procedure edContactPersonKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure tvRoomResMainGuestPropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
    procedure edContactPersonEnter(Sender: TObject);
    procedure edContactPersonExit(Sender: TObject);
    procedure cbxChannelsCloseUp(Sender: TObject);
    procedure tvRoomResRatePlanCodePropertiesCloseUp(Sender: TObject);
    procedure tvRoomResRatePlanCodePropertiesEditValueChanged(Sender: TObject);
    procedure tvSelectTypeNoRoomsPropertiesChange(Sender: TObject);
    procedure tvSelectTypeNoRoomsStylesGetContentStyle(Sender: TcxCustomGridTableView; ARecord: TcxCustomGridRecord;
      AItem: TcxCustomGridTableItem; var AStyle: TcxStyle);
    procedure __tvRoomResColumn2PropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure GetLocaTimeEditProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure FormatTextToShortFormat(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure tvRoomResStockItemsCountPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
    procedure mExtrasCalcFields(DataSet: TDataSet);
    procedure cbxFilterSelectedTypesClick(Sender: TObject);
    procedure mSelectRoomsFilterRecord(DataSet: TDataSet; var Accept: Boolean);
    procedure tvRoomResGetCurrencyProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvRoomRatesNativeAmountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure edContactPerson1PropertiesCloseUp(Sender: TObject);
    procedure cbxBreakfastChange(Sender: TObject);
    procedure edRoomResDiscountChange(Sender: TObject);
    procedure tvRoomResDiscountPropertiesEditValueChanged(Sender: TObject);
    procedure tvRoomResDiscountGetProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure tvRoomResIsPercentagePropertiesEditValueChanged(Sender: TObject);
    procedure pgcMainPageChanging(Sender: TObject; NewPage: TsTabSheet; var AllowChange: Boolean);
  private
    { Private declarations }
    zCustomerChanged: boolean;
    zIsFirstTime: boolean;

    FrmAlertPanel: TFrmAlertPanel;

    zRtInRoom: integer;
    zRtNoRoom: integer;
    zRtTotal: integer;

    zTotalSelected: integer; // 0
    zTotalRoomsSelected: integer; // 4
    zTotalAvailable: integer; // 3
    zTotalFree: integer; // 2
    zTotalNoRooms: integer; // 1

    zTotal: integer;

    zNights: integer;
    FOutOfOrderBlocking: boolean;

    FDynamicRates: TDynamicRates;

    FNewReservation: TNewReservation;
    FCurrentCurrency: TRoomerCurrencyDefinition;
    FPreviousGuestsList: TStringlist;

    procedure initCustomer;
    function RoomStatusFromInfo(statusText: string): integer;
    function RoomStatusToInfo(Index: integer): string;
    ///<summary> Create the roomlist in NewReservation object and set all properties from UI and local memtables </summary>
    function Apply: boolean;
    procedure addAvailableRoomTypes;
    procedure SetAllAsNoRoom(doNextPage: boolean = true);

    procedure ApplyRateToOther(RoomReservation: integer; RoomType: string);
    procedure ApplyNettoRateToNullPrice(NewRate: double; RoomReservation: integer; RoomType: string);

    procedure getSelectRooms;
    procedure InitSelectRooms;

    function CreateRoomRes_Quick: boolean;
    procedure CreateRoomRes_Normal;

    procedure EditRoomRateOneRoom(RoomRes: integer);
    procedure GetPrices;

    function doAutoSelect(RoomType: string; NumRooms: integer; PriorityRule: string): integer;
    procedure CalcOnePrice(RoomReservation: integer; NewRate: double = 0);

    procedure SetOutOfOrderBlocking(const Value: boolean);
    procedure FillQuickFind;
    procedure ShowChannels;
    procedure PopulateRatePlanCombo(clearAll : Boolean = True);
    function SetOnePrice(RoomReservation: Integer; rateId: String): boolean;
    procedure SetProfileAlertVisibility;
    procedure SetRoomFilterOnlySelectedTypes(aOnlySelected: boolean);
    procedure EmptyQuickFind;
    procedure ActivateNextButton;
    function OkToActivateNextButton: Boolean;
    procedure evtLookupOnChange(Sender: TObject);
    procedure evtCustomerChangedAndValid(Sender: TObject);
    procedure UpdateControls;
    /// <summary>
    ///   Recalculate the roomrate, discount (% or EUR) and Nettorate stored in roomres based on the
    ///  values in roomrates for this roomreservation
    /// </summary>
    procedure UpdateRatesInRoomRes(aRoomReservation: integer; aChannelID: integer = -1; const aRateID: string = '');
  protected
    const
      WM_LOADPREVIOUS_GUESTS = WM_User + 53;
    procedure WndProc(var message: TMessage); override;

    property OutOfOrderBlocking : Boolean read FOutOfOrderBlocking write SetOutOfOrderBlocking;


  public
    { Public declarations }
    property NewReservation: TNewReservation read FNewReservation write FNewReservation;
    constructor Create(aOwner: TComponent); override;
    destructor Destroy; override;
  end;

function ShowNewReservationForm(var aNewReservation: TNewReservation): boolean;

implementation

uses
  UITypes,
  ug,
  ud,
  uSqlDefinitions,
  _Glob,
  PrjConst,
  uMain,
  uCurrencies,
  ufrmPriceCodesGrid,
  uCountries,
  ueditRoomPrice,
  uCustomers2,
  uCustomerTypes2,
  objDayFreeRooms,
  uAppGlobal,
  uDayNotes,
  uPackages,
  uGuestProfiles,
  uRoomerDefinitions,
  uReservationStateDefinitions,
  uDateUtils,
  uAvailabilityPerDay,
  uViewDailyRates
 , ufrmReservationExtras
 , DateUtils
 , uSQLUtils
 , Math
 , uRoomerCurrencymanager
 , uAmount
 , uCurrencyConstants
 , uMarketDefinitions
 , uRoomerGridForm
  , uRoomerLanguage
 , uBreakfastTypeDefinitions;

{$R *.dfm}


const
  WM_SET_COMBO_TEXT = WM_User + 101;
  WM_SET_EMPTY_TEXT = WM_User + 102;


function ShowNewReservationForm(var aNewReservation: TNewReservation): boolean;
var
  frm: TfrmMakeReservationQuick;
begin
  frm := TfrmMakeReservationQuick.Create(nil);
  try
    frm.NewReservation := aNewReservation;
    Result := frm.ShowModal = mrOk;

    if Result then
    begin
      Screen.Cursor := crHourglass;
      try
        aNewReservation.CreateReservation(-1, True);
      finally
        Screen.Cursor := crDefault;
      end;
    end;

  finally
    frm.Free;
  end;
end;



function TfrmMakeReservationQuick.RoomStatusFromInfo(statusText: string): integer;
begin
  Result := 0;
  if statusText = 'P' then
    Result := 0;
  if statusText = 'G' then
    Result := 1;
  if statusText = 'A' then
    Result := 2;
  if statusText = 'O' then
    Result := 3;
  if statusText = 'N' then
    Result := 4;
  if statusText = 'D' then
    Result := 5;
  if statusText = 'B' then
    Result := 6;
  if statusText = 'L' then
    Result := 8;
end;

function TfrmMakeReservationQuick.RoomStatusToInfo(Index: integer): string;
begin
  Result := '';
  if Index = 0 then
    Result := 'P';
  if Index = 1 then
    Result := 'G';
  if Index = 2 then
    Result := 'A';
  if Index = 3 then
    Result := 'O';
  if Index = 4 then
    Result := 'N';
  if Index = 5 then
    Result := 'D';
  if Index = 6 then
    Result := 'B';
  if Index = 8 then
    Result := 'L';
  if Index = 7 then
    Result := 'B';
end;

procedure TfrmMakeReservationQuick.sButton3Click(Sender: TObject);
begin
  ApplyRateToOther(mRoomResroomreservation.AsInteger, '');
end;

procedure TfrmMakeReservationQuick.sButton4Click(Sender: TObject);
begin
  ApplyRateToOther(mRoomResroomreservation.AsInteger, mRoomResRoomType.AsString);
end;

procedure TfrmMakeReservationQuick.ApplyRateToOther(RoomReservation: integer; RoomType: string);
var
  RateDate: TDate;
  PriceCode: string;
  Rate: double;
  Discount: double;
  isPercentage: boolean;
  ShowDiscount: boolean;
  isPaid: boolean;
  DiscountAmount: double;
  RentAmount: double;
  NativeAmount: double;

  Arrival: TDateTime;
  Departure: TDateTime;
  room: string;

  found: boolean;
  currentRoomReservation: integer;
  ManualChannelId: integer;
  ratePlanCode: String;

begin
  Arrival := mRoomResArrival.AsDateTime;
  Departure := mRoomResDeparture.AsDateTime;
  ManualChannelId := mRoomResManualChannelId.AsInteger;
  ratePlanCode := mRoomResratePlanCode.AsString;

  if mRoomRatesTmp.active then
    mRoomRatesTmp.Close;
  mRoomRatesTmp.Open;
  mRoomRatesTmp.LoadFromDataSet(mRoomRates);

  mRoomRatesTmp.Filter := '(Roomreservation=' + inttostr(RoomReservation) + ')';
  mRoomRatesTmp.Filtered := true;

  // apply to same roomtype
  mRoomRates.DisableControls;
  mRoomRes.DisableControls;
  try
    mRoomRes.First;
    while not mRoomRes.eof do
    begin
      if RoomType <> '' then
      begin
        if (mRoomResRoomType.AsString <> RoomType) then
        begin
          mRoomRes.next;
          continue;
        end;
      end;
      if
        (mRoomResRoomReservation.AsInteger <> RoomReservation)
        AND (mRoomResArrival.AsDateTime = Arrival)
        AND (mRoomResDeparture.AsDateTime = Departure)
      then
      begin
        currentRoomReservation := mRoomResRoomReservation.AsInteger;
        repeat
          found := mRoomRates.Locate('roomreservation', currentRoomReservation, []);
          if found then
          begin
            mRoomRates.Delete;
          end;
        until not found;
        mRoomRatesTmp.First;
        while not mRoomRatesTmp.eof do
        begin
          RateDate := mRoomRatesTmpRateDate.AsDateTime;
          room := mRoomRatesTmpRoomNumber.AsString;
          PriceCode := mRoomRatesTmpPriceCode.AsString;
          Rate := mRoomRatesTmpRate.AsFloat;
          Discount := mRoomRatesTmpDiscount.AsFloat;
          isPercentage := mRoomRatesTmpisPercentage.AsBoolean;
          ShowDiscount := mRoomRatesTmpShowDiscount.AsBoolean;
          isPaid := mRoomRatesTmpisPaid.AsBoolean;
          DiscountAmount := mRoomRatesTmpDiscountAmount.AsFloat;
          RentAmount := mRoomRatesTmpRentAmount.AsFloat;
          NativeAmount := mRoomRatesTmpNativeAmount.AsFloat;

          mRoomRates.append;
          mRoomRatesReservation.AsInteger := -1;
          mRoomRatesRoomReservation.AsInteger := currentRoomReservation;
          mRoomRatesRoomNumber.AsString := room;
          mRoomRatesRateDate.AsDateTime := RateDate;
          mRoomRatesPriceCode.AsString := PriceCode;
          mRoomRatesRate.AsFloat := Rate;
          mRoomRatesDiscount.AsFloat := Discount;
          mRoomRatesisPercentage.AsBoolean := isPercentage;
          mRoomRatesShowDiscount.AsBoolean := ShowDiscount;
          mRoomRatesisPaid.AsBoolean := isPaid;
          mRoomRatesDiscountAmount.AsFloat := DiscountAmount;
          mRoomRatesRentAmount.AsFloat := RentAmount;
          mRoomRatesNativeAmount.AsFloat := NativeAmount;
          mRoomRatesCurrency.AsString := mRoomRatesTmpCurrency.AsString;
          mRoomRatesCurrencyRate.AsFloat := mRoomRatesTmpCurrencyRate.AsFloat;
          mRoomRates.post;

          mRoomRatesTmp.next;
        end;

        UpdateRatesInRoomRes(currentRoomReservation, ManualChannelId, ratePlanCode);

//        mRoomRes.edit;
//        mRoomResAvragePrice.AsFloat := AvragePrice;
//        mRoomResRateCount.AsInteger := RateCount;
//        mRoomResPriceCode.AsString := PriceCode;
//
//        mRoomResAvrageDiscount.AsFloat := AvrageDiscount;
//        mRoomResManualChannelId.AsInteger := ManualChannelId;
//        mRoomResratePlanCode.AsString := ratePlanCode;
//        mRoomRes.post;
      end;
      mRoomRes.next;
    end;
    mRoomRes.Locate('roomReservation', RoomReservation, []);
  finally
    mRoomRates.EnableControls;
    mRoomRes.EnableControls;
  end;
end;

procedure TfrmMakeReservationQuick.ApplyNettoRateToNullPrice(NewRate: double; RoomReservation: integer;
  RoomType: string);
var
  currentRoomReservation: integer;
begin
  mRoomRates.DisableControls;
  mRoomRes.DisableControls;
  try
    mRoomRes.First;
    while not mRoomRes.eof do
    begin
      if RoomType <> '' then
      begin
        if (mRoomResRoomType.AsString <> RoomType) then
        begin
          mRoomRes.next;
          continue;
        end;
      end;
      if
        (mRoomResRoomReservation.AsInteger <> RoomReservation)
      then
      begin
        currentRoomReservation := mRoomResRoomReservation.AsInteger;
        if mRoomResAvragePrice.AsFloat = 0 then
        begin
          CalcOnePrice(currentRoomReservation, NewRate);
        end;
      end;
      mRoomRes.next;
    end;
    mRoomRes.Locate('roomReservation', RoomReservation, []);
  finally
    mRoomRates.EnableControls;
    mRoomRes.EnableControls;
  end;
end;

procedure TfrmMakeReservationQuick.WndProc(var message: TMessage);
begin
  inherited;
  if message.Msg = WM_SET_EMPTY_TEXT then
  begin
    edContactAddress1.Text := '';
    edContactAddress2.Text := '';
    edContactAddress3.Text := '';
    edContactAddress4.Text := '';
    edContactPhone.Text := '';
    edContactMobile.Text := '';
    edContactFax.Text := '';
    edContactEmail.Text := '';

    cbxAddToGuestProfiles.Enabled := true;
    edtPortfolio.Tag := 0;
  end
  else if message.Msg = WM_SET_COMBO_TEXT then
  begin
    if message.WParam = 1 then
    begin
      if Assigned(glb.PreviousGuestsSet) then
      begin
        edContactPerson1.Text := glb.PreviousGuestsSet['Name'];
        edContactAddress1.Text := glb.PreviousGuestsSet['Address1'];
        edContactAddress2.Text := glb.PreviousGuestsSet['Address2'];
        edContactAddress3.Text := glb.PreviousGuestsSet['Address3'];
        edContactAddress4.Text := glb.PreviousGuestsSet['Address4'];
        edContactPhone.Text := glb.PreviousGuestsSet['Tel1'];
        edContactMobile.Text := glb.PreviousGuestsSet['Tel2'];
        edContactFax.Text := ''; // glb.PreviousGuestsSet['TelFax'];
        edContactEmail.Text := glb.PreviousGuestsSet['Email'];
      end;
    end
    else
    begin
      edContactPerson1.Text := Trim(glb.PersonProfiles['Firstname'] + ' ' + glb.PersonProfiles['Lastname']);
      edContactAddress1.Text := glb.PersonProfiles['Address1'];
      edContactAddress2.Text := glb.PersonProfiles['Address2'];
      edContactAddress3.Text := glb.PersonProfiles['Zip'];
      edContactAddress4.Text := glb.PersonProfiles['City'];
      edContactPhone.Text := glb.PersonProfiles['TelLandLine'];
      edContactMobile.Text := glb.PersonProfiles['TelMobile'];
      edContactFax.Text := glb.PersonProfiles['TelFax'];
      edContactEmail.Text := glb.PersonProfiles['Email'];

      edtSpecialRequests.Text := glb.PersonProfiles['Preparation'];
      edtNotes.Text := glb.PersonProfiles['Information'];
      edtRoom.Text := glb.PersonProfiles['Room'];
      edtRoomType.Text := glb.PersonProfiles['RoomType'];

      SetProfileAlertVisibility;
    end;
  end
  else if message.Msg = WM_LOADPREVIOUS_GUESTS then
  begin
    FillQuickFind;
  end;
end;

procedure TfrmMakeReservationQuick.__tvRoomResColumn2PropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
var
  _FrmViewDailyRates: TFrmViewDailyRates;
  ADate,
  Arrival,
  Departure: TDate;
  ii,
  Guests,
  dayCount, RoomReservation: integer;
  rateValue: double;
  Rate: TAmount;
  rateId: String;
  lRateCurrency: string;
begin
  if AButtonIndex = 0 then
  begin

    _FrmViewDailyRates := TFrmViewDailyRates.Create(nil);
    try
      RoomReservation := mRoomRes['RoomReservation'];
      if mRoomRes.Locate('roomreservation', RoomReservation, []) then
      begin

        Arrival := mRoomResarrival.AsDateTime;
        Departure := mRoomResdeparture.AsDateTime;
        dayCount := trunc(Departure) - trunc(Arrival);
        Guests := mRoomRes['Guests'];

        rateId := mRoomResRatePlanCode.AsString;

        _FrmViewDailyRates.Currency := FCurrentCurrency.CurrencyCode;
        _FrmViewDailyRates.Clear;
        for ii := 0 to dayCount - 1 do
        begin
          ADate := Arrival + ii;
          if mRoomRates.Locate('RateDate', ADate, []) then
          begin
            if FDynamicRates.active AND FDynamicRates.findRateByRateCode(trunc(Arrival) + ii, Guests, rateId, rateValue, lRateCurrency) then
              Rate := RoomerCurrencyManager.ConvertAmount(TAmount.Create(rateValue, lRateCurrency), FCurrentCurrency.CurrencyCode)
            else
              Rate := TAmount.Create(mRoomResAvragePrice.AsFloat, FCurrentCurrency.CurrencyCode);

            _FrmViewDailyRates.Add(CreateDateRate(trunc(Arrival) + ii, Rate, fraCustomerPanel.Code, dayCount, Guests));
          end;
        end;

        _FrmViewDailyRates.ShowModal;
      end;
    finally
      FreeAndNil(_FrmViewDailyRates);
    end;
  end;
end;

/// //////////////////////////////////////////////////////////////////////////////////////////////
// FORM
/// //////////////////////////////////////////////////////////////////////////////////////////////

procedure TfrmMakeReservationQuick.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);
  screen.Cursor := crHourGlass;
  try
    FDynamicRates := TDynamicRates.Create;
    zIsFirstTime := true;
    zRtInRoom := 0;
    zRtNoRoom := 0;
    zRtTotal := 0;

    taReservation.TabVisible := false;
    tabSelectType.TabVisible := false;
    tabSelectRooms.TabVisible := false;
    tabRoomRates.TabVisible := false;
    pgcMain.ActivePageIndex := 0;
  finally
    screen.Cursor := crDefault;
  end;

  fraCustomerPanel.OnChange := evtLookupOnChange;
  fraCustomerPanel.OnChangedAndValid := evtCustomerChangedAndValid;
  fraCurrencyPanel.OnChangedAndValid := evtCurrencyChangedAndValid;
  fraCurrencyPanel.OnChange := evtLookupOnChange;
  fraPriceCodePanel.OnChange := evtLookupOnChange;

  fraLookupCountry.OnChange := evtLookupOnChange;
  fraLookupMarketSegment.OnChange := evtLookupOnChange;

  pgcExtraAndAlert.ActivePageIndex := 0;

end;

procedure TfrmMakeReservationQuick.evtLookupOnChange(Sender: TObject);
begin
  ActivateNextButton;
end;

procedure TfrmMakeReservationQuick.EmptyQuickFind;
begin
  edContactPerson1.Text := '';
  edContactPerson1.Properties.LookupItems.BeginUpdate;
  try
//    for i := edContactPerson1.Properties.LookupItems.Count - 1 downto 0 do
//      edContactPerson1.Properties.LookupItems.Objects[i].Free;
    edContactPerson1.Properties.LookupItems.Clear;
  finally
    edContactPerson1.Properties.LookupItems.EndUpdate;
  end;
end;

procedure TfrmMakeReservationQuick.FillQuickFind;
var
  rSet: TRoomerDataSet;
  fldID: TField;
  fldName: TField;
  fldLastName: TField;
  fldCity: TFIeld;
  fldAddress1: TField;
  fldAddress4: TField;
  fldCountry: TFIeld;

  function getField(fld: TField): String;
  var
    s: String;
  begin
    s := fld.AsString;
    if s = '' then
      Result := ''
    else
      Result := ', ' + s;
  end;

var
  item: TRoomerFilterItem;
begin
  FPreviousGuestsList.Clear;

  rSet := glb.PersonProfiles;

  fldID := rSet.fieldByName('ID');
  fldName := rSet.FieldByName('FirstName');
  fldLastName := rSet.FieldByName('LastName');
  fldAddress1 := rSet.FieldByName('Address1');
  fldCountry := rSet.FieldByName('Country');
  fldCity := rSet.FieldByName('City');

  rSet.First;
  while NOT rSet.eof do
  begin
    item := TRoomerFilterItem.Create;
    item.Key := fldId.AsString;
    item.Line := Trim(fldName.AsString + ' ' + fldLastName.AsString) + getField(fldCity) + getField(fldCountry) + getField(fldAddress1);
    FPreviousGuestsList.AddObject(item.line, item);
    rSet.next;
  end;

  if Assigned(glb.PreviousGuestsSet) then
  begin
    rSet := glb.PreviousGuestsSet;
    fldID := rSet.fieldByName('ID');
    fldName := rSet.FieldByName('Name');
    fldAddress1 := rSet.FieldByName('Address1');
    fldAddress4 := rSet.FieldByName('Address4');
    fldCountry := rSet.FieldByName('Country');

    rSet.First;
    while NOT rSet.eof do
    begin
      item := TRoomerFilterItem.Create;
      item.Key := fldID.AsString;
      item.Line := fldName.AsString + getField(fldAddress4) + getField(fldCountry) + getField(fldAddress1);
      FPreviousGuestsList.AddObject(item.Line, item);
      rSet.next;
    end;
  end;

  edContactPerson1.Properties.LookupItems.BeginUpdate;
  try
    edContactPerson1.Properties.LookupItems.assign(FPreviousGuestsList);
    edContactPerson1.Properties.LookupItemsSorted := True;
  finally
    edContactPerson1.Properties.LookupItems.EndUpdate;
  end;
end;

procedure TfrmMakeReservationQuick.FormDestroy(Sender: TObject);
begin
  FDynamicRates.Free;
  EmptyQuickFind;
end;

procedure TfrmMakeReservationQuick.ShowChannels;
var
  res: TRoomerDataSet;
begin
  cbxChannels.Items.Clear;
  cbxChannels.Items.AddObject('<none>', nil);
  res := glb.ChannelsSet;
  res.First;
  while NOT res.eof do
  begin
    cbxChannels.Items.AddObject(res['name'], TObject(res.FieldByName('id').AsInteger));
    res.next;
  end;
  cbxChannels.ItemIndex := 0;
end;

procedure TfrmMakeReservationQuick.FormShow(Sender: TObject);
begin

  screen.Cursor := crHourGlass;
  try
    cbxIsRoomResDiscountPrec.ItemIndex := 0;

    TBreakFastType.AsStrings(cbxBreakfast.Items);
    TReservationMarketType.AsStrings(cbxMarket.Items);
    if ctrlGetBoolean('BreakfastInclDefault') then
      cbxBreakfast.ItemIndex := TBreakFastType.Included.ToItemIndex
    else
      cbxBreakfast.ItemIndex := TBreakFastType.None.ToItemIndex;

    lblExtraCurrency.Caption := g.qNativeCurrency;

    chkExcluteWaitingList.Checked := g.qExcluteWaitingList;
    chkExcluteAllotment.Checked := g.qExcluteAllotment;
    chkExcluteOrder.Checked := g.qExcluteOrder;
    chkExcluteDeparted.Checked := g.qExcluteDeparted;
    chkExcluteGuest.Checked := g.qExcluteGuest;
    chkExcluteBlocked.Checked := g.qExcluteBlocked;
    chkExcluteNoShow.Checked := g.qExcluteNoshow;

    ShowChannels;
    fraCustomerPanel.Code := FNewReservation.HomeCustomer.Customer;

    if FNewReservation.IsQuick then
    begin
      Caption := GetTranslatedText('shTx_QuickReservation_NewReservationQuick');
      dtArrival.date := FNewReservation.newRoomReservations.ReservationArrival;
      dtDeparture.date := FNewReservation.newRoomReservations.ReservationDeparture;
      gbxDates.Enabled := false;
      fraCustomerPanel.SetFocus;
    end
    else
    begin
      Caption := GetTranslatedText('shTx_QuickReservation_NewReservation');
      dtArrival.date := trunc(frmMain.resDateFrom); // trunc(now);
      dtDeparture.date := trunc(frmMain.resDateTo); // trunc(now+1);
      edNights.SetFocus;
    end;

    btnFinish.Enabled := false;
    edNights.Value := trunc(dtDeparture.date) - trunc(dtArrival.date);

    memRoomNotes.Enabled := false;
    clabRoomNotes.Visible := false;
    chkSendConfirmation.Enabled := false;
    cbxAddToGuestProfiles.Enabled := false;
    FrmAlertPanel := TFrmAlertPanel.Create(self);
    FrmAlertPanel.PlaceEditPanel(Alerts, FNewReservation.AlertList);
    gbxProfileAlert.Visible := False;

    edtBreakfastPrice.Value := Item_GetPrice(g.qBreakFastItem);
    UpdateControls;

  finally
    screen.Cursor := crDefault;
  end;

  PostMessage(Handle, WM_LOADPREVIOUS_GUESTS, 0, 0);

end;


///////////////////////////////////////////////////////////////////////////////////////////
//  RoomRes grid and table
///////////////////////////////////////////////////////////////////////////////////////////

procedure TfrmMakeReservationQuick.tvRoomResGetCurrencyProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  aProperties := FCurrentCurrency.GetcxEditPropertiesKeepEvents(aProperties);
end;

procedure TfrmMakeReservationQuick.tvRoomRatesNativeAmountGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  aProperties := RoomerCurrencyManager.DefaultCurrencyDefinition.GetcxEditPropertiesKeepEvents(AProperties);
end;

procedure TfrmMakeReservationQuick.tvRoomResAvragePricePropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: integer;
  RoomType: string;
  oldRate: double;
  NewNettoRate: double;
begin
  RoomReservation := mRoomResRoomReservation.AsInteger;
  oldRate := mRoomResavragePrice.AsFloat;
  RoomType := mRoomResRoomType.AsString;

  mRoomRes.post;
  NewNettoRate := mRoomResavragePrice.AsFloat;

  if oldRate <> NewNettoRate then
  begin
    CalcOnePrice(RoomReservation, NewNettoRate);
  end;

  if chkAutoUpdateNullPrice.Checked then
  begin
    ApplyNettoRateToNullPrice(NewNettoRate, RoomReservation, RoomType);
  end;
end;

procedure TfrmMakeReservationQuick.tvRoomResChildrenCountPropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: integer;
  oldValue: integer;
  newValue: integer;
begin
  oldValue := mRoomResChildrenCount.AsInteger;
  RoomReservation := mRoomResRoomReservation.AsInteger;
  mRoomRes.post;
  newValue := mRoomResChildrenCount.AsInteger;
  if newValue <> oldValue then
  begin
    CalcOnePrice(RoomReservation);
  end;
end;

procedure TfrmMakeReservationQuick.tvRoomResColumn1PropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
begin
  EditRoomRateOneRoom(mRoomResroomreservation.AsInteger);
end;

procedure TfrmMakeReservationQuick.tvRoomResDiscountGetProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
//  if not aRecord.Values[tvRoomRatesisPercentage.Index] then
//    aProperties := FCurrentCurrency.GetcxEditProperties;
end;

procedure TfrmMakeReservationQuick.tvRoomResDiscountPropertiesEditValueChanged(Sender: TObject);
begin
//
end;

procedure TfrmMakeReservationQuick.tvRoomResIsPercentagePropertiesEditValueChanged(Sender: TObject);
begin
//
end;


procedure TfrmMakeReservationQuick.FormatTextToShortFormat(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AText: string);
begin
  if not aText.IsEmpty then
    DateTimeToString(aText, FormatSettings.ShortTimeFormat, StrTodateTime(aText));
end;

procedure TfrmMakeReservationQuick.GetLocaTimeEditProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  TcxTimeEditProperties(aProperties).Use24HourFormat := not FormatSettings.ShortTimeFormat.Contains(Formatsettings.TimeAMString);
end;

procedure TfrmMakeReservationQuick.tvRoomResGuestsPropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: integer;
  oldValue: integer;
  newValue: integer;
begin
  oldValue := mRoomResguests.AsInteger;
  RoomReservation := mRoomResRoomReservation.AsInteger;
  mRoomRes.post;
  newValue := mRoomResguests.AsInteger;
  if newValue <> oldValue then
  begin
    CalcOnePrice(RoomReservation);
  end;
end;

procedure TfrmMakeReservationQuick.tvRoomResinfantCountPropertiesEditValueChanged(Sender: TObject);
var
  RoomReservation: integer;
  oldValue: integer;
  newValue: integer;
begin
  oldValue := mRoomResinfantCount.AsInteger;
  RoomReservation := mRoomResRoomReservation.AsInteger;
  mRoomRes.post;
  newValue := mRoomResInfantCount.AsInteger;
  if newValue <> oldValue then
  begin
    CalcOnePrice(RoomReservation);
  end;
end;

procedure TfrmMakeReservationQuick.tvRoomResMainGuestPropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
var
  iId: integer;
begin
  iId := GuestProfiles(actLookup, 0);
  if iId > 0 then
  begin
    if glb.LocateSpecificRecord('personprofiles', 'ID', inttostr(iId)) then
    begin
      mRoomRes.edit;
      mRoomRes['MainGuest'] := Trim(glb.PersonProfiles['FirstName'] + ' ' + glb.PersonProfiles['LastName']);
      mRoomResPersonsProfilesId.AsInteger := iId;
      mRoomRes.post;
    end;
  end;
end;

procedure TfrmMakeReservationQuick.tvRoomResPackagePropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
var
  theData: recPackageHolder;
  roomPrice: double;
  itemPrice: double;
  package: string;
  rr: integer;
  guestCount: integer;
  nightCount: integer;
begin
  roomPrice := 0;
  itemPrice := 0;
  rr := mRoomResroomreservation.AsInteger;
  initPackageHolder(theData);
  theData.package := mRoomResPackage.AsString;
  if openPackages(actLookup, theData) then
  begin
    package := theData.package;

    guestCount := mRoomResGuests.AsInteger;
    nightCount := trunc(mRoomResDeparture.AsDateTime) - trunc(mRoomResArrival.AsDateTime);

    if Trim(package) <> '' then
    begin
      Package_getRoomPrice(package, nightCount, guestCount, roomPrice, itemPrice);

      if roomPrice = 0 then
        RoomPrice := mRoomResAvragePrice.AsFloat;

      if RoomPrice > 0 then
      begin
        mRoomRes.edit;
        try
//          mRoomResAvragePrice.AsFloat := RoomPrice;
//          mRoomResAvrageDiscount.AsFloat := 0;
//          mRoomResRateCount.AsInteger := 1;
          mRoomResPackagePrice.AsFloat := itemPrice;
          mRoomResPackage.AsString := package;
          mRoomRes.post;
        except
          mRoomRes.Cancel;
          raise;
        end;

        mRoomRates.Filter := '(Roomreservation=' + inttostr(rr) + ')';
        mRoomRates.Filtered := true;

        mRoomRates.First;
        while not mRoomRates.eof do
        begin
          mRoomRates.edit;
          try
            mRoomRatesrate.AsFloat := RoomPrice;
            mRoomRatesdiscount.AsFloat := 0;
            mRoomRatesisPercentage.AsBoolean := true;
            mRoomRatesdiscountAmount.AsFloat := 0;
            mRoomRatesRentamount.AsFloat := RoomPrice;
            mRoomRatesNativeAmount.AsFloat := RoomPrice;
            mRoomRates.post;

          except
            mRoomRates.Cancel;
            raise;
          end;
          mRoomRates.next;
        end;
        mRoomRates.Filtered := false;
        UpdateRatesInRoomRes(rr);
      end;
    end;
  end;

end;

function TfrmMakeReservationQuick.SetOnePrice(RoomReservation: integer; rateId: String): boolean;
var

  ii: integer;

  Arrival: TDateTime;
  Departure: TDateTime;
  ADate: TDate;
  Rate: double;
  dayCount: integer;
  rateTotal: TAmount;
  rateAverage: TAmount;
  lChannelCurrencyCode: string;
  channelId: integer;
begin
  Result := false;
  mRoomRes.DisableControls;
  mRoomRates.DisableControls;
  try
    if mRoomRes.Locate('roomreservation', RoomReservation, []) then
    begin
      channelId := 0;
      if cbxChannels.ItemIndex > 0 then
        channelId := integer(cbxChannels.Items.Objects[cbxChannels.ItemIndex]);

      Arrival := mRoomResarrival.AsDateTime;
      Departure := mRoomResdeparture.AsDateTime;
      dayCount := trunc(Departure) - trunc(Arrival);
      rateTotal := TAmount.Create(0, FCurrentCurrency.CurrencyCode);

      for ii := 0 to dayCount - 1 do
      begin
        ADate := Arrival + ii;
        if mRoomRates.Locate('Roomreservation;RateDate', VarArrayOf([RoomReservation, ADate]), []) then
        begin
          if FDynamicRates.active AND
            FDynamicRates.findRateByRateCode(aDate, mRoomRes['Guests'], rateId, Rate, lChannelCurrencyCode) then
          begin
            // Rate acuired, convert to selected currency
            Rate := RoomerCurrencyManager.ConvertAmount(TAmount.Create(Rate, lChannelCurrencyCode), FCurrentCurrency.CurrencyCode);
            rateTotal := rateTotal + TAmount.Create(Rate, lChannelCurrencyCode);

            mRoomRates.edit;
            mRoomRatesRate.AsFloat := Rate;
            mRoomRates.post;
          end;
        end;
      end;

      rateAverage := rateTotal / dayCount;

//      mRoomRes.edit;
//      mRoomResAvragePrice.AsFloat := rateAverage;
//      mRoomResRateCount.AsFloat := 1;
//      mRoomResManualChannelId.AsInteger := channelId;
//      mRoomResratePlanCode.AsString := rateId;
//      mRoomRes.post;

      UpdateRatesInRoomRes(RoomReservation, channelId, rateId);

      Result := true;
    end;
  finally
    mRoomRes.EnableControls;
    mRoomRates.EnableControls;
  end;
end;

procedure TfrmMakeReservationQuick.tvRoomResRatePlanCodePropertiesCloseUp(Sender: TObject);
var
  lItems: TStrings;
begin
  if mRoomRes.Eof then
    Exit;

  lItems := (tvRoomResRatePlanCode.Properties AS TcxComboBoxProperties).Items;
  if (lItems.Count > 0) and  (TcxComboBox(Sender).ItemIndex > 0) then
      SetOnePrice(mRoomRes['RoomReservation'], lItems[TcxComboBox(Sender).ItemIndex]);
end;

procedure TfrmMakeReservationQuick.tvRoomResRatePlanCodePropertiesEditValueChanged(Sender: TObject);
begin
  if NOT mRoomRes.eof then
  begin
    mRoomRes.edit;
    TcxComboBox(Sender).ItemIndex := (tvRoomResRatePlanCode.Properties AS TcxComboBoxProperties)
      .Items.IndexOf(TcxComboBox(Sender).Text);
    if TcxComboBox(Sender).ItemIndex >= 0 then
      mRoomRes['ratePlanCode'] := (tvRoomResRatePlanCode.Properties AS TcxComboBoxProperties)
        .Items[TcxComboBox(Sender).ItemIndex];
    mRoomRes.post;
  end;
end;

procedure TfrmMakeReservationQuick.tvRoomResStockItemsCountPropertiesButtonClick(Sender: TObject; AButtonIndex: Integer);
var
  lCurrentRoomRes: recEditReservationExtrasHolder;
begin
  with lCurrentRoomRes do
  begin
    RoomReservation := mRoomResroomreservation.AsInteger;
    Room := mRoomResRoom.asString;
    RoomType := mRoomResRoomType.AsString;
    Currency := FCurrentCurrency.CurrencyCode;
    CurrencyRate := FCurrentCurrency.Rate;
    guests := mRoomResGuests.AsInteger;
    childrenCount := mRoomResChildrenCount.asInteger;
    infantCount := mRoomResinfantCount.AsInteger;
    ArrivalDate := mRoomResArrival.AsDateTime;
    DepartureDate := mRoomResDeparture.asDateTime;
  end;

  if editReservationExtras(lCurrentRoomRes, mExtras) then
  begin
    mExtras.Filter := format('roomreservation=%d', [mRoomResroomreservation.AsInteger]);
    mExtras.Filtered := true;
    try
      mRoomRes.Edit;
      try
        mRoomResStockItemsCount.AsInteger := 0;
        mRoomResStockitemsPrice.AsFloat := 0;
        mExtras.First;
        while not mExtras.Eof do
        begin
          if (mExtrasRoomreservation.AsInteger = mRoomResroomreservation.asInteger) then // filter doesnt seem to work :-(
          begin
            mRoomResStockItemsCount.AsInteger := mRoomResStockItemsCount.AsInteger + mExtrasCount.AsInteger;
            mRoomResStockitemsPrice.AsFloat := mRoomResStockitemsPrice.AsFloat + mExtrasTotalprice.AsFloat;
          end;
          mExtras.Next;
        end;
        mRoomRes.Post;
      except
        mRoomRes.Cancel;
        raise;
      end;
    finally
      mExtras.Filtered := False;
    end;
  end;
end;

/// ////////////////////////////////////////////////////////////////////////////////////////
// SelectRooms grid and table
/// ////////////////////////////////////////////////////////////////////////////////////////

procedure TfrmMakeReservationQuick.tvSelectRoomsRoomPropertiesButtonClick(Sender: TObject; AButtonIndex: integer);
begin
  if not mSelectRoomsSelect.AsBoolean then
    exit;

  mSelectRooms.edit;

  if mSelectRoomsRoom.AsString = '' then
    mSelectRoomsRoom.AsString := mSelectRoomstmp.AsString
  else
    mSelectRoomsRoom.AsString := '';
end;

procedure TfrmMakeReservationQuick.tvSelectRoomsSelectPropertiesEditValueChanged(Sender: TObject);
var
  RoomType: string;
  isSelected: boolean;
  aValue: integer;
begin
  mSelectRooms.post;
  RoomType := mSelectRoomsRoomType.AsString;
  isSelected := mSelectRoomsSelect.AsBoolean;

  if isSelected then
  begin
    aValue := 1;
  end
  else
  begin
    aValue := -1
  end;

  if mSelectTypes.Locate('Roomtype', RoomType, []) then
  begin
    mSelectTypes.edit;
    mSelectTypesRoomsSelected.AsInteger := mSelectTypesRoomsSelected.AsInteger + aValue;
    mSelectTypes.post;
  end;

  zTotalRoomsSelected := tvSelectType.DataController.Summary.FooterSummaryValues[4];
  labTotalRoomsSelected.Caption := inttostr(zTotalRoomsSelected);
end;

procedure TfrmMakeReservationQuick.tvSelectTypeNoRoomsPropertiesChange(Sender: TObject);
var
  total: integer;
  norooms: integer;
  TotalFree: integer;
begin
  norooms := mSelectTypesNorooms.AsInteger;
  TotalFree := mSelectTypestotalFree.AsInteger;
  total := TotalFree - norooms;
  sLabel1.Caption := inttostr(total);
end;

procedure TfrmMakeReservationQuick.tvSelectTypeNoRoomsPropertiesValidate(Sender: TObject; var DisplayValue: Variant;
  var ErrorText: TCaption; var Error: boolean);
begin
  if DisplayValue < 0 then
    DisplayValue := 0;
end;

procedure TfrmMakeReservationQuick.tvSelectTypeNoRoomsStylesGetContentStyle(Sender: TcxCustomGridTableView;
  ARecord: TcxCustomGridRecord;
  AItem: TcxCustomGridTableItem; var AStyle: TcxStyle);
var
  total: integer;
  norooms: integer;
  TotalFree: integer;
begin
  norooms := mSelectTypesNorooms.AsInteger;
  TotalFree := mSelectTypestotalFree.AsInteger;
  total := TotalFree - norooms;

  if total < 0 then
  begin
    AStyle := cxStyle1
  end
  else
  begin
    AStyle := cxStyle2
  end;

end;

procedure TfrmMakeReservationQuick.tvSelectTypeSelectedPropertiesEditValueChanged(Sender: TObject);
begin
  if tvSelectType.DataController.DataSource.State = dsEdit then
    mSelectTypes.post;
end;

procedure TfrmMakeReservationQuick.tvSelectTypeSelectedPropertiesValidate(Sender: TObject; var DisplayValue: Variant;
  var ErrorText: TCaption; var Error: boolean);
begin
  if DisplayValue < 0 then
    DisplayValue := 0;

  if DisplayValue > mSelectTypesAvailable.AsInteger then
  begin
    if mSelectTypesAvailable.AsInteger < 1 then
    begin
      DisplayValue := 0;
    end
    else
    begin
      DisplayValue := mSelectTypesAvailable.AsInteger;
    end;
  end;

end;

procedure TfrmMakeReservationQuick.UpdateControls;
begin
  edtBreakfastPrice.Enabled := TBreakfastType.FromItemIndex(cbxBreakfast.ItemIndex) = TBreakFastType.Excluded;
  if cbxIsRoomResDiscountPrec.ItemIndex = 0 then
    edRoomResDiscount.MaxValue := 100
  else
    edRoomResDiscount.MaxValue := 99999999;
end;

procedure TfrmMakeReservationQuick.initCustomer;
var
  Customer: string;
  oldCustomer: string;
  ChannelCode: String;
  i: integer;
begin
  Customer := fraCustomerPanel.Code;
  oldCustomer := FNewReservation.HomeCustomer.Customer;
  FNewReservation.HomeCustomer.Customer_update(Customer);

  fraLookupCountry.Code := FNewReservation.HomeCustomer.Country;
  edReservationName.Text := FNewReservation.HomeCustomer.CustomerName;

  cbxRoomStatus.ItemIndex := RoomStatusFromInfo(FNewReservation.HomeCustomer.RoomStatus);
  fraLookupMarketSegment.Code := FNewReservation.HomeCustomer.MarketSegmentCode;

  chkGroupInvoice.Checked := FNewReservation.HomeCustomer.IsGroupInvoice;

  fraCurrencyPanel.Code := FNewReservation.HomeCustomer.Currency;
  fraPriceCodePanel.Code := FNewReservation.HomeCustomer.PcCode;

  edRoomResDiscount.Value := trunc(FNewReservation.HomeCustomer.DiscountPerc);
  edPID.Text := FNewReservation.HomeCustomer.PID;
  edCustomerName.Text := FNewReservation.HomeCustomer.CustomerName;
  edAddress1.Text := FNewReservation.HomeCustomer.Address1;
  edAddress2.Text := FNewReservation.HomeCustomer.Address2;
  edAddress3.Text := FNewReservation.HomeCustomer.Address3;
  edTel1.Text := FNewReservation.HomeCustomer.Tel1;
  edTel2.Text := FNewReservation.HomeCustomer.Tel2;
  edFax.Text := FNewReservation.HomeCustomer.Fax;
  edEmailAddress.Text := FNewReservation.HomeCustomer.EmailAddress;
  edHomePage.Text := FNewReservation.HomeCustomer.HomePage;
  edContactPhone.Text := FNewReservation.HomeCustomer.ContactPhone;
  edContactMobile.Text := FNewReservation.HomeCustomer.ContactMobile;
  edContactPerson1.Text := ''; // oNewReservation.HomeCustomer.ContactPerson;
  edContactFax.Text := ''; // oNewReservation.HomeCustomer.ContactFax;
  edContactEmail.Text := ''; // oNewReservation.HomeCustomer.ContactEmail;
  zCustomerChanged := false;

  memCustomerAlert.lines.Clear;
  memCustomerAlert.Text := d.GetCustomerPreferences(Customer);

  if glb.LocateSpecificRecordAndGetValue('channels', 'id', FNewReservation.HomeCustomer.CustomerRatePlanId,
    'channelManagerId', ChannelCode) then
    for i := 1 to cbxChannels.Items.Count - 1 do
      if integer(cbxChannels.Items.Objects[i]) = FNewReservation.HomeCustomer.CustomerRatePlanId then
      begin
        cbxChannels.ItemIndex := i; // cbxChannels.Items.IndexOf(ChannelCode);
        cbxChannelsCloseUp(nil);
        Break;
      end;
end;

procedure TfrmMakeReservationQuick.btdEditRoomRateClick(Sender: TObject);
var
  RoomReservation: integer;
begin
  RoomReservation := mRoomResroomreservation.AsInteger;
  EditRoomRateOneRoom(RoomReservation);
end;

procedure TfrmMakeReservationQuick.EditRoomRateOneRoom(RoomRes: integer);
var
  theData: recEditRoomPriceHolder;

  Reservation: integer;
  RoomReservation: integer;
  RoomNumber: string;
  PriceCode: string;
  RateDate: TDate;
  Rate: double;
  Discount: double;
  ShowDiscount: boolean;
  isPaid: boolean;
  isPercentage: boolean;
  DiscountAmount: double;
  RentAmount: double;
  NativeAmount: double;
  ttAmount: double;
  lstPrices: TstringList;

  ttDiscountAmount: double;
  applyType: integer;

begin
  applyType := 0;

  if mRatesEdit.active then
    mRatesEdit.Close;
  lstPrices := TstringList.Create;
  try
    lstPrices.Sorted := true;
    lstPrices.Duplicates := dupIgnore;

    initEditRoomPriceHolder(theData);
    theData.isCreateRes := true;
    theData.Currency := FCurrentCurrency.CurrencyCode;
    theData.CurrencyRate := FCurrentCurrency.Rate;

    RoomReservation := mRoomResroomreservation.AsInteger;
    theData.RoomType := mRoomResRoomType.AsString;
    theData.Guests := mRoomResGuests.AsInteger;
    theData.childrenCount := mRoomReschildrenCount.AsInteger;
    theData.infantCount := mRoomResinfantCount.AsInteger;
    mRatesEdit.Open;

    mRoomRates.First;
    while not mRoomRates.eof do
    begin
      if mRoomRatesroomreservation.AsInteger = RoomReservation then
      begin
        mRatesEdit.append;
        mRatesEditReservation.AsInteger := mRoomRatesReservation.AsInteger;
        mRatesEditRoomReservation.AsInteger := mRoomRatesRoomReservation.AsInteger;
        mRatesEditRoomNumber.AsString := mRoomRatesRoomNumber.AsString;
        mRatesEditPriceCode.AsString := mRoomRatesPriceCode.AsString;
        mRatesEditRateDate.AsDateTime := mRoomRatesRateDate.AsDateTime;
        mRatesEditRate.AsFloat := mRoomRatesRate.AsFloat;
        mRatesEditDiscount.AsFloat := mRoomRatesDiscount.AsFloat;
        mRatesEditisPercentage.AsBoolean := mRoomRatesisPercentage.AsBoolean;
        mRatesEditShowDiscount.AsBoolean := mRoomRatesShowDiscount.AsBoolean;
        mRatesEditisPaid.AsBoolean := mRoomRatesisPaid.AsBoolean;
        mRatesEditDiscountAmount.AsFloat := mRoomRatesDiscountAmount.AsFloat;
        mRatesEditRentAmount.AsFloat := mRoomRatesRentAmount.AsFloat;
        mRatesEditNativeAmount.AsFloat := mRoomRatesNativeAmount.AsFloat;
        mRatesEditCurrency.AsString := mRoomRatesCurrency.AsString;
        mRatesEditCurrencyRate.AsFloat := mRoomRatesCurrencyRate.AsFloat;
        mRatesEdit.post;
      end;
      mRoomRates.next;
    end;

    mRatesEdit.First;

    theData.room := mRatesEditroomNumber.AsString;
    ttAmount := 0;
    ttDiscountAmount := 0;
    if editRoomPrice(actNone, theData, mRatesEdit, applyType) then
    begin
      mRatesEdit.First;
      while not mRatesEdit.eof do
      begin
        Reservation := mRatesEditReservation.AsInteger;
        RoomNumber := mRatesEditRoomNumber.AsString;
        PriceCode := mRatesEditPriceCode.AsString;
        Rate := mRatesEditRate.AsFloat;
        Discount := mRatesEditDiscount.AsFloat;
        isPercentage := mRatesEditisPercentage.AsBoolean;
        ShowDiscount := mRatesEditShowDiscount.AsBoolean;
        isPaid := mRatesEditisPaid.AsBoolean;
        DiscountAmount := mRatesEditDiscountAmount.AsFloat;
        RentAmount := mRatesEditRentAmount.AsFloat;
        NativeAmount := mRatesEditNativeAmount.AsFloat;

        RoomReservation := mRatesEditRoomReservation.AsInteger;
        RateDate := mRatesEditRateDate.AsDateTime;
        lstPrices.Add(floatTostr(RentAmount));
        ttAmount := ttAmount + RentAmount;
        ttDiscountAmount := ttDiscountAmount + DiscountAmount;

        if mRoomRates.Locate('RoomReservation;rateDate', VarArrayOf([RoomReservation, RateDate]), []) then
        begin
          mRoomRates.edit;
          mRoomRatesReservation.AsInteger := Reservation;
          mRoomRatesRoomReservation.AsInteger := RoomReservation;
          mRoomRatesRoomNumber.AsString := RoomNumber;
          mRoomRatesPriceCode.AsString := PriceCode;
          mRoomRatesRateDate.AsDateTime := RateDate;
          mRoomRatesRate.AsFloat := Rate;
          mRoomRatesDiscount.AsFloat := Discount;
          mRoomRatesisPercentage.AsBoolean := isPercentage;
          mRoomRatesShowDiscount.AsBoolean := ShowDiscount;
          mRoomRatesisPaid.AsBoolean := isPaid;
          mRoomRatesDiscountAmount.AsFloat := DiscountAmount;
          mRoomRatesRentAmount.AsFloat := RentAmount;
          mRoomRatesNativeAmount.AsFloat := NativeAmount;
          mRoomRates.post;

        end;
        mRatesEdit.next;
      end;

      UpdateRatesInRoomRes(RoomReservation);

//      if mRoomRes.Locate('RoomReservation', RoomReservation, []) then
//      begin
//        if AmountCount <> 0 then
//        begin
//          AvrageAmount := ttAmount / AmountCount;
//          AvrageDiscount := ttDiscountAmount / AmountCount;
//          RateCount := lstPrices.Count;
//          mRoomRes.edit;
//          mRoomResAvragePrice.AsFloat := AvrageAmount;
//          mRoomResRateCount.AsInteger := RateCount;
//          mRoomResPriceCode.AsString := PriceCode;
//          mRoomResAvrageDiscount.AsFloat := AvrageDiscount;
//          mRoomRes.post;
//        end;
//      end;
    end;
  finally
    if mRatesEdit.active then
      mRatesEdit.Close;
    FreeAndNil(lstPrices);
  end;

  if applyType = 2 then
    ApplyRateToOther(RoomReservation, theData.RoomType)
  else if applyType = 3 then
    ApplyRateToOther(RoomReservation, '');

end;

procedure TfrmMakeReservationQuick.InitSelectRooms;
begin
  zTotalRoomsSelected := 0;
  labTotalRoomsSelected.Caption := inttostr(zTotalRoomsSelected);
  getSelectRooms;
  mSelectTypes.First;
  while not mSelectTypes.eof do
  begin
    mSelectTypes.edit;
    mSelectTypesRoomsSelected.AsInteger := 0;
    mSelectTypes.post;
    mSelectTypes.next;
  end;

  mSelectTypes.First;
end;

procedure TfrmMakeReservationQuick.getSelectRooms;
var
  rSet: TRoomerDataSet;
  rSetOcc: TRoomerDataSet;
  s: string;
  dateFrom: TDate;
  dateTo: TDate;
  room: string;

begin
  if mSelectRooms.RecordCount > 0 then
    Exit;

  mSelectRooms.DisableControls;
  try
    dateFrom := dtArrival.date;
    dateTo := dtDeparture.date;

    if mSelectRooms.active then
      mSelectRooms.Close;
    mSelectRooms.Open;

    s := '';
    s := s + 'SELECT DISTINCT '#10;
    s := s + '    Room '#10;
    s := s + '  , isNoRoom '#10;
    s := s + 'FROM '#10;
    s := s + '  roomsdate '#10;
    s := s + 'WHERE '#10;
    s := s + '  (ADate >= ' + _db(dateFrom) + ') AND (ADate < ' + _db(dateTo) + ') AND (isNoRoom = 0) '#10;
    s := s + '   AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '; // **zxhj
    s := s + '   AND (ResFlag <> ' + _db(STATUS_CANCELED) + ' ) '; // **zxhj
    s := s + 'ORDER BY '#10;
    s := s + '  ROOM '#10;

    rSetOcc := createNewDataSet;
    try
      rSet_bySQL(rSetOcc, s);

      s := 'SELECT * FROM wroominfo ORDER BY room ';
      rSet := createNewDataSet;
      try
        rSet_bySQL(rSet, s);

        While not rSet.eof do
        begin
          room := rSet.FieldByName('room').AsString;
          if not rSetOcc.Locate('room', room, []) then
          begin
            mSelectRooms.append;
            mSelectRoomsRoom.AsString := rSet.FieldByName('Room').AsString;
            mSelectRoomstmp.AsString := rSet.FieldByName('Room').AsString;
            mSelectRoomsDescription.AsString := rSet.FieldByName('Description').AsString;
            mSelectRoomsDetailedDescription.AsString := rSet.FieldByName('DetailedDescription')
              .AsString;
            mSelectRoomsRoomType.AsString := rSet.FieldByName('RoomType').AsString;
            mSelectRoomsBath.AsBoolean := rSet.FieldByName('Bath').AsBoolean;
            mSelectRoomsShower.AsBoolean := rSet.FieldByName('Shower').AsBoolean;
            mSelectRoomsSafe.AsBoolean := rSet.FieldByName('Safe').AsBoolean;
            mSelectRoomsTV.AsBoolean := rSet.FieldByName('TV').AsBoolean;
            mSelectRoomsVideo.AsBoolean := rSet.FieldByName('Video').AsBoolean;
            mSelectRoomsRadio.AsBoolean := rSet.FieldByName('Radio').AsBoolean;
            mSelectRoomsCDPlayer.AsBoolean := rSet.FieldByName('CDPlayer').AsBoolean;
            mSelectRoomsTelephone.AsBoolean := rSet.FieldByName('Telephone').AsBoolean;
            mSelectRoomsPress.AsBoolean := rSet.FieldByName('Press').AsBoolean;
            mSelectRoomsCoffee.AsBoolean := rSet.FieldByName('Coffee').AsBoolean;
            mSelectRoomsKitchen.AsBoolean := rSet.FieldByName('Kitchen').AsBoolean;
            mSelectRoomsMinibar.AsBoolean := rSet.FieldByName('Minibar').AsBoolean;
            mSelectRoomsFridge.AsBoolean := rSet.FieldByName('Fridge').AsBoolean;
            mSelectRoomsHairdryer.AsBoolean := rSet.FieldByName('Hairdryer').AsBoolean;
            mSelectRoomsInternetPlug.AsBoolean := rSet.FieldByName('InternetPlug').AsBoolean;
            mSelectRoomsFax.AsBoolean := rSet.FieldByName('Fax').AsBoolean;
            mSelectRoomsSqrMeters.AsFloat := rSet.FieldByName('SqrMeters').asfloat;
            mSelectRoomsBedSize.AsBoolean := rSet.FieldByName('BedSize').AsBoolean;
            mSelectRoomsEquipments.AsString := rSet.FieldByName('Equipments').AsString;
            mSelectRoomsBookable.AsBoolean := rSet.FieldByName('Bookable').AsBoolean;
            mSelectRoomsStatistics.AsBoolean := rSet.FieldByName('Statistics').AsBoolean;
            mSelectRoomsStatus.AsString := rSet.FieldByName('Status').AsString;
            mSelectRoomsOrderIndex.AsInteger := rSet.FieldByName('OrderIndex').AsInteger;
            mSelectRoomshidden.AsBoolean := rSet.FieldByName('hidden').AsBoolean;
            mSelectRoomsLocation.AsString := rSet.FieldByName('Location').AsString;
            mSelectRoomsFloor.AsInteger := rSet.FieldByName('Floor').AsInteger;
            mSelectRoomsID.AsInteger := rSet.FieldByName('ID').AsInteger;
            mSelectRoomsDorm.AsString := rSet.FieldByName('Dorm').AsString;
            mSelectRoomsuseInNationalReport.AsBoolean := rSet.FieldByName('useInNationalReport').AsBoolean;
            mSelectRoomsActive.AsBoolean := rSet.FieldByName('Active').AsBoolean;
            mSelectRoomsLocationDescription.AsString := rSet.FieldByName('LocationDescription').AsString;
            mSelectRoomsRoomTypeDescription.AsString := rSet.FieldByName('RoomTypeDescription').AsString;
            mSelectRoomsNumberGuests.AsInteger := rSet.FieldByName('NumberGuests').AsInteger;
            mSelectRoomsRoomTypeGroup.AsString := rSet.FieldByName('RoomTypeGroup').AsString;
            mSelectRoomsRoomTypeGroupDescription.AsString := rSet.FieldByName('RoomTypeGroupDescription').AsString;
            mSelectRooms.post;
          end;
          rSet.next;
        end;
      finally
        FreeAndNil(rSet);
      end;
    finally
      FreeAndNil(rSetOcc);
    end;
    mSelectRooms.First;
    cbxFilterSelectedTypesClick(cbxFilterSelectedTypes); // update filter
  finally
    mSelectRooms.EnableControls;
  end;

end;

function TfrmMakeReservationQuick.doAutoSelect(RoomType: string; NumRooms: integer; PriorityRule: string): integer;
var
  lstPriority: TstringList;
  tmp: integer;

  aRoomtype: string;
  foundCount: integer;

begin
  Result := 0;
  if NumRooms = 0 then
    exit;

  foundCount := 0;
  lstPriority := TstringList.Create;
  try
    tmp := mSelectRoomsID.AsInteger;
    mSelectRooms.DisableControls;
    try
      mSelectRooms.First;
      while NOT mSelectRooms.eof do
      begin
        aRoomtype := mSelectRoomsRoomType.AsString;
        if Uppercase(aRoomtype) = Uppercase(RoomType) then
        begin
          if foundCount < NumRooms then
          begin
            mSelectRooms.edit;
            mSelectRoomsSelect.AsBoolean := true;
            mSelectRooms.post;

            mSelectTypes.edit;
            mSelectTypesRoomsSelected.AsInteger := mSelectTypesRoomsSelected.AsInteger + 1;
            mSelectTypes.post;

            inc(foundCount);
          end;
        end;
        mSelectRooms.next;
      end;
      mSelectRooms.Locate('ID', tmp, []);
    finally
      mSelectRooms.EnableControls;
    end;
  finally
    FreeAndNil(lstPriority);
  end;
  zTotalRoomsSelected := tvSelectType.DataController.Summary.FooterSummaryValues[4];
  labTotalRoomsSelected.Caption := inttostr(zTotalRoomsSelected);
end;

procedure TfrmMakeReservationQuick.dtDepartureCloseUp(Sender: TObject);
begin
  if dtDeparture.date <= dtArrival.date then
    dtDeparture.date := dtArrival.date + 1;
  if dtArrival.date >= dtDeparture.date then
    dtArrival.date := dtDeparture.date - 1;
  zNights := trunc(dtDeparture.date) - trunc(dtArrival.date);
  edNights.Value := zNights;
end;

procedure TfrmMakeReservationQuick.dtDepartureExit(Sender: TObject);
begin
  if dtDeparture.date <= dtArrival.date then
    dtDeparture.date := dtArrival.date + 1;
  if dtArrival.date >= dtDeparture.date then
    dtArrival.date := dtDeparture.date - 1;
  zNights := trunc(dtDeparture.date) - trunc(dtArrival.date);
  edNights.Value := zNights;
end;

procedure TfrmMakeReservationQuick.btnAutoSelectRoomsClick(Sender: TObject);
var
  RoomType: string;
  NumRooms: integer;
  PriorityRule: string;
begin
  InitSelectRooms;
  mSelectTypes.First;
  while not mSelectTypes.eof do
  begin
    RoomType := mSelectTypesRoomType.AsString;
    NumRooms := mSelectTypesSelected.AsInteger;
    PriorityRule := mSelectTypesPriorityRule.AsString;
    doAutoSelect(RoomType, NumRooms, PriorityRule);
    mSelectTypes.next;
  end;
end;

procedure TfrmMakeReservationQuick.btnEditRateAllRoomsClick(Sender: TObject);
begin
  Apply;
end;

procedure TfrmMakeReservationQuick.btnFinishClick(Sender: TObject);
begin
  Apply;
end;

function TfrmMakeReservationQuick.OkToActivateNextButton : Boolean;
begin
  result := False;
  if not OutOfOrderBlocking then
  begin
    if not fraCustomerPanel.IsValid then
      exit;
    if not fraLookupCountry.IsValid then
      exit;
    if not fraLookupMarketSegment.IsValid then
      exit;
    if not fraCurrencyPanel.IsValid then
      exit;
    if not fraPriceCodePanel.IsValid then
      exit;
  end;
  if pgcMain.ActivePageIndex = 3 then
    exit;

  result := True;
end;

procedure TfrmMakeReservationQuick.ActivateNextButton;
begin
  btnNext.Enabled := OkToActivateNextButton;
end;

procedure TfrmMakeReservationQuick.btnNextClick(Sender: TObject);
begin
  if NOT OkToActivateNextButton then exit;

  if pgcMain.ActivePageIndex = 0 then
  begin
    addAvailableRoomTypes;
    if FNewReservation.IsQuick then
    begin
      pgcMain.ActivePageIndex := 3;
    end
    else
    begin
      if OutOfOrderBlocking then
        pgcMain.ActivePageIndex := 2
      else
        pgcMain.ActivePageIndex := 1;
    end;
    pgcMainChange(self);
    exit;
  end;

  if pgcMain.ActivePageIndex = 1 then
  begin
    if FNewReservation.IsQuick then
    begin
      pgcMain.ActivePageIndex := 3;
    end
    else
    begin
      zTotalSelected := tvSelectType.DataController.Summary.FooterSummaryValues[0];
      zTotalRoomsSelected := tvSelectType.DataController.Summary.FooterSummaryValues[4]; // 4
      zTotalAvailable := tvSelectType.DataController.Summary.FooterSummaryValues[3]; // 3
      zTotalFree := tvSelectType.DataController.Summary.FooterSummaryValues[2]; // 2
      zTotalNoRooms := tvSelectType.DataController.Summary.FooterSummaryValues[1]; // 1

      zTotal := zTotalSelected + zTotalRoomsSelected + zTotalAvailable + zTotalFree + zTotalNoRooms;
      if ((zTotalSelected = 0) and (zTotalNoRooms > 0)) and (zTotal <> 0) then
      begin
        pgcMain.ActivePage := tabRoomRates;
      end
      else
      begin
        pgcMain.ActivePageIndex := 2;
      end;
    end;
    pgcMainChange(self);
    exit;
  end;

  if pgcMain.ActivePageIndex = 2 then
  begin
    if FNewReservation.IsQuick then
    begin
      pgcMain.ActivePageIndex := 3;
    end
    else
    begin
      pgcMain.ActivePageIndex := 3;
    end;
    pgcMainChange(self);
    exit;
  end;
end;

procedure TfrmMakeReservationQuick.btnPortfolioClick(Sender: TObject);
begin
  if edtPortfolio.Tag > 0 then
  begin
    edContactPerson1.Text := '';
    edContactAddress1.Text := '';
    edContactAddress2.Text := '';
    edContactAddress3.Text := '';
    edContactAddress4.Text := '';

    edContactPhone.Text := '';
    edContactMobile.Text := '';
    edContactFax.Text := '';
  end;
  edtPortfolio.Tag := 0;
  edtPortfolio.Text := '';
end;

procedure TfrmMakeReservationQuick.btnPreviusClick(Sender: TObject);
begin
  if pgcMain.ActivePageIndex = 0 then
    exit;

  if pgcMain.ActivePageIndex = 1 then
  begin
    pgcMain.ActivePageIndex := 0;
    pgcMainChange(self);
    exit;
  end;

  if pgcMain.ActivePageIndex = 2 then
  begin
    if FNewReservation.IsQuick then
    begin
      pgcMain.ActivePageIndex := 0;
    end
    else
    begin
      pgcMain.ActivePageIndex := 1;
    end;
    pgcMainChange(self);
    exit;
  end;

  if pgcMain.ActivePageIndex = 3 then
  begin
    if FNewReservation.IsQuick then
    begin
      pgcMain.ActivePageIndex := 0;
    end
    else
    begin
      pgcMain.ActivePageIndex := 2;
    end;
    pgcMainChange(self);
    exit;
  end;

end;

procedure TfrmMakeReservationQuick.btnRefreshClick(Sender: TObject);
begin
  GetPrices;
end;

procedure TfrmMakeReservationQuick.btnSetAllAsNoRoomClick(Sender: TObject);
begin
  SetAllAsNoRoom(true);
end;

procedure TfrmMakeReservationQuick.SetAllAsNoRoom(doNextPage: boolean = true);
var
  norooms: integer;
begin
  mSelectTypes.DisableControls;
  mSelectTypes.First;
  try
    while not mSelectTypes.eof do
    begin
      norooms := mSelectTypesselected.AsInteger + mSelectTypesnoRooms.AsInteger;
      mSelectTypes.edit;
      mSelectTypesnoRooms.AsInteger := norooms;
      mSelectTypesSelected.AsInteger := 0;
      mSelectTypes.post;
      mSelectTypes.next;
    end;
  finally
    mSelectTypes.EnableControls;
    screen.Cursor := crDefault;
  end;

  // if jist norooms
  zTotal := zTotalSelected + zTotalRoomsSelected + zTotalAvailable + zTotalFree + zTotalNoRooms;
  if ((zTotalSelected = 0) and (zTotalNoRooms > 0)) and (zTotal <> 0) then
    exit;

  mSelectRooms.DisableControls;
  mSelectRooms.First;
  try
    while not mSelectRooms.eof do
    begin
      mSelectRooms.edit;
      mSelectRoomsselect.AsBoolean := false;
      mSelectRooms.post;
      mSelectRooms.next;
    end;
  finally
    mSelectRooms.EnableControls;
    screen.Cursor := crDefault;
  end;
  if doNextPage then
  begin
    pgcMain.ActivePageIndex := 3;
    pgcMainChange(self);
  end;
end;

procedure TfrmMakeReservationQuick.SetOutOfOrderBlocking(const Value: boolean);
begin
  FOutOfOrderBlocking := Value;

  DisableAlign;
  try
    gbxContact.Visible := NOT FOutOfOrderBlocking;
    gbxRate.Visible := NOT FOutOfOrderBlocking;
    gbxCustomerAlert.Visible := NOT FOutOfOrderBlocking;
    gbxGetCustomer.Visible := NOT FOutOfOrderBlocking;

    pnlReservationDetaildata.Visible := NOT FOutOfOrderBlocking;
    chkGroupInvoice.Visible := NOT FOutOfOrderBlocking;

    panNotesPayment.Visible := NOT FOutOfOrderBlocking;
    panRoomNotes.Visible := NOT FOutOfOrderBlocking;
    panSelectRoomsTop.Visible := NOT FOutOfOrderBlocking;
    panTopRoomRates.Visible := NOT FOutOfOrderBlocking;

    tvRoomResGuests.Visible := NOT FOutOfOrderBlocking;
    tvRoomResChildrenCount.Visible := NOT FOutOfOrderBlocking;
    tvRoomResinfantCount.Visible := NOT FOutOfOrderBlocking;
    tvRoomResMainGuest.Visible := NOT FOutOfOrderBlocking;
    tvRoomResAvragePrice.Visible := NOT FOutOfOrderBlocking;
    tvRoomResPackage.Visible := NOT FOutOfOrderBlocking;
    tvRoomResPackagePrice.Visible := NOT FOutOfOrderBlocking;
    tvRoomResStockItemsCount.Visible := NOT FOutOfOrderBlocking;
    tvRoomResStockitemsPrice.Visible := NOT FOutOfOrderBlocking;
    tvRoomResAvrageDiscount.Visible := NOT FOutOfOrderBlocking;
    tvRoomResPriceCode.Visible := NOT FOutOfOrderBlocking;
    tvRoomResRatePlanCode.Visible := NOT FOutOfOrderBlocking;
    tvRoomResExpectedTimeOfArrival.Visible := NOT FOutOfOrderBlocking;
    tvRoomResexpectedCheckouttime.Visible := NOT FOutOfOrderBlocking;

    if FOutOfOrderBlocking then
    begin
      clabReservationName.Caption := GetTranslatedText('shTx_FrmMakeReservationQuick_OutOfOrderDescription');
      clabArrival.Caption := GetTranslatedText('shTx_FrmMakeReservationQuick_OutOfOrderStartDate');
      clabdeparture.Caption := GetTranslatedText('shTx_FrmMakeReservationQuick_OutOfOrderEndDate');
    end
    else
    begin
      RoomerLanguage.TranslateThisControl(self, clabReservationName);
      RoomerLanguage.TranslateThisControl(self, clabArrival);
      RoomerLanguage.TranslateThisControl(self, clabdeparture);
    end;

  finally
    EnableAlign;
  end;

end;

procedure TfrmMakeReservationQuick.btnPortfolioLookupClick(Sender: TObject);
var
  iId: integer;
begin
  iId := GuestProfiles(actLookup, edtPortfolio.Tag);
  if iId > 0 then
  begin
    if glb.LocateSpecificRecord('personprofiles', 'ID', inttostr(iId)) then
    begin
      edtPortfolio.Text := Trim(glb.PersonProfiles['FirstName'] + ' ' + glb.PersonProfiles['LastName']);
      edtPortfolio.Tag := iId;

      edContactPerson1.Text := edtPortfolio.Text;
      edContactAddress1.Text := glb.PersonProfiles['Address1'];
      edContactAddress2.Text := glb.PersonProfiles['Address2'];
      edContactAddress3.Text := glb.PersonProfiles['Zip'];
      edContactAddress4.Text := glb.PersonProfiles['City'];

      edContactPhone.Text := glb.PersonProfiles['TelLandLine'];
      edContactMobile.Text := glb.PersonProfiles['TelMobile'];
      edContactFax.Text := glb.PersonProfiles['TelFax'];
      edContactEmail.Text := glb.PersonProfiles['Email'];

      edtSpecialRequests.Text := glb.PersonProfiles['Preparation'];
      edtNotes.Text := glb.PersonProfiles['Information'];
      edtRoom.Text := glb.PersonProfiles['Room'];
      edtRoomType.Text := glb.PersonProfiles['RoomType'];

      if glb.PersonProfiles['Country'] <> '' then
        fraLookupCountry.Code := glb.PersonProfiles['Country']
      else
        fraLookupCountry.Code := FNewReservation.HomeCustomer.Country;
      SetProfileAlertVisibility;
    end;
  end;
end;

procedure TfrmMakeReservationQuick.SetProfileAlertVisibility;
begin
  gbxProfileAlert.Visible := TRIM(edtSpecialRequests.Text + edtNotes.Text +
                                  edtRoom.Text + edtRoomType.Text) <> '';
  gbxRoomAlert.Visible := TRIM(edtRoom.Text + edtRoomType.Text) <> '';
  if gbxProfileAlert.Visible then
  begin
    edtSpecialRequests.Font.Color := clRed;
    edtNotes.Font.Color := clRed;

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

procedure TfrmMakeReservationQuick.sButton1Click(Sender: TObject);
begin
  mRoomRes.DisableControls;
  mRoomRes.First;
  try
    while not mRoomRes.eof do
    begin
      mRoomRes.edit;
      mRoomResRoom.AsString := '<' + mRoomResroomReservation.AsString + '>';
      mRoomRes.post;
      mRoomRes.next;
    end;
  finally
    mRoomRes.EnableControls;
    screen.Cursor := crDefault;
  end;
end;

procedure TfrmMakeReservationQuick.cbxFilterSelectedTypesClick(Sender: TObject);
begin
  SetRoomFilterOnlySelectedTypes(TCheckbox(Sender).Checked);
end;


procedure TfrmMakeReservationQuick.SetRoomFilterOnlySelectedTypes(aOnlySelected: boolean);
begin
  mSelectRooms.Filtered := aOnlySelected;
end;


procedure TfrmMakeReservationQuick.mSelectRoomsFilterRecord(DataSet: TDataSet; var Accept: Boolean);
var
  bm: TBookmark;
begin
  if cbxFilterSelectedTypes.Checked then
  begin
    bm := mSelectTypes.Bookmark;
    try
      Accept := (zTotalSelected = 0) or (mSelectTypes.Locate('roomtype', mSelectRoomsRoomType.AsString, []) and (mSelectTypesSelected.AsInteger > 0));
    finally
      mSelectTypes.Bookmark := bm;
    end;
  end
  else
    Accept := True;
end;

procedure TfrmMakeReservationQuick.mSelectRoomsNewRecord(DataSet: TDataSet);
begin
  DataSet.FieldByName('Select').AsBoolean := false;
end;

procedure TfrmMakeReservationQuick.mSelectTypesCalcFields(DataSet: TDataSet);
begin
  DataSet.FieldByName('totalFree').AsInteger := DataSet.FieldByName('Available').AsInteger -
    DataSet.FieldByName('Selected').AsInteger
end;

procedure TfrmMakeReservationQuick.pgcMainChange(Sender: TObject);
begin
  if pgcMain.ActivePageIndex = 0 then
  begin

    btnCancel.Enabled := true;
    btnPrevius.Enabled := false;
    btnNext.Enabled := true;
    if FNewReservation.IsQuick then
    begin
      btnFinish.Enabled := true;
      memRoomNotes.Enabled := true;
      clabRoomNotes.Visible := true;
    end
    else
    begin
      btnFinish.Enabled := false;
      memRoomNotes.Enabled := false;
      clabRoomNotes.Visible := false;

    end;
  end
  else
    if pgcMain.ActivePageIndex = 1 then
  begin
    if not FNewReservation.IsQuick then
    begin
      zTotalSelected := 0; // 0
      zTotalRoomsSelected := 0; // 4
      zTotalAvailable := 0; // 3
      zTotalFree := 0; // 2
      zTotalNoRooms := 0; // 1

      zTotal := zTotalSelected + zTotalRoomsSelected + zTotalAvailable + zTotalFree + zTotalNoRooms;
      labTotalSelected.Caption := inttostr(zTotalSelected);
      labTotalRoomsSelected.Caption := inttostr(zTotalRoomsSelected);
    end;

    memRoomNotes.Enabled := false;
    clabRoomNotes.Visible := false;
    btnCancel.Enabled := true;
    btnPrevius.Enabled := true;
    btnNext.Enabled := true;
    if FNewReservation.IsQuick then
    begin
      btnFinish.Enabled := true;
      memRoomNotes.Enabled := true;
      clabRoomNotes.Visible := true;
    end
    else
    begin
      btnFinish.Enabled := false;
      memRoomNotes.Enabled := false;
      clabRoomNotes.Visible := false;
    end;
//    addAvailableRoomTypes;
  end
  else
  if pgcMain.ActivePageIndex = 2 then
  begin
    btnCancel.Enabled := true;
    btnPrevius.Enabled := true;
    btnNext.Enabled := true;

    zTotalSelected := tvSelectType.DataController.Summary.FooterSummaryValues[0];
    zTotalRoomsSelected := tvSelectType.DataController.Summary.FooterSummaryValues[4]; // 4
    zTotalAvailable := tvSelectType.DataController.Summary.FooterSummaryValues[3]; // 3
    zTotalFree := tvSelectType.DataController.Summary.FooterSummaryValues[2]; // 2
    zTotalNoRooms := tvSelectType.DataController.Summary.FooterSummaryValues[1]; // 1

    zTotal := zTotalSelected + zTotalRoomsSelected + zTotalAvailable + zTotalFree + zTotalNoRooms;
    labTotalSelected.Caption := inttostr(zTotalSelected);

    labTotalRoomsSelected.Caption := inttostr(zTotalRoomsSelected);

    if FNewReservation.IsQuick then
    begin
      btnFinish.Enabled := true;
      memRoomNotes.Enabled := true;
      clabRoomNotes.Visible := true;
    end
    else
    begin
      btnFinish.Enabled := false;
      memRoomNotes.Enabled := false;
      clabRoomNotes.Visible := false;
      getSelectRooms;
    end;

  end
  else
    if pgcMain.ActivePageIndex = 3 then
  begin
    if not FNewReservation.IsQuick then
    begin
      if ((zTotalSelected > 0) and (zTotalRoomsSelected = 0))
        OR ((zTotalSelected = 0) and (zTotalNoRooms > 0))
      then
      begin
        SetAllAsNoRoom(false);
      end;
    end;

    btnCancel.Enabled := true;
    btnPrevius.Enabled := true;
    btnNext.Enabled := false;
    if FNewReservation.IsQuick then
    begin
      btnFinish.Enabled := true;
      memRoomNotes.Enabled := true;
      clabRoomNotes.Visible := true;
    end
    else
    begin
      btnFinish.Enabled := false;
      memRoomNotes.Enabled := false;
      clabRoomNotes.Visible := false;
    end;
    if FNewReservation.IsQuick then
    begin
      if zIsFirstTime then
        if NOT CreateRoomRes_Quick then
        begin
          Close;
          exit;
        end;
    end
    else
    begin
      CreateRoomRes_Normal;
    end;
    GetPrices;
  end;
end;

procedure TfrmMakeReservationQuick.pgcMainPageChanging(Sender: TObject; NewPage: TsTabSheet; var AllowChange: Boolean);
begin
end;

// ##############################################################################################################
// ##############################################################################################################

procedure TfrmMakeReservationQuick.mExtrasCalcFields(DataSet: TDataSet);
begin
  mExtrasTotalprice.AsFloat := mExtrasPricePerItemPerDay.AsFloat * mExtrasCount.AsInteger * DaysBetween(mExtrasFromDate.AsDateTime, mExtrasToDate.AsDateTime);
end;

procedure TfrmMakeReservationQuick.mnuFinishAndShowClick(Sender: TObject);
begin
  Apply;
  FNewReservation.ShowProfile := true;

  Close;
  modalresult := mrok;
end;

procedure TfrmMakeReservationQuick.addAvailableRoomTypes;
var
  rSet: TRoomerDataSet;
  i: integer;
  s: string;

  RoomType: string;

  dateFrom: TDate;
  dateTo: TDate;
  ADate: TDate;
  Status: string;
  isNoRoom: boolean;
  RoomCount: integer;
  DateCount: integer;

  TotalNotFree: integer;

  bExcluteWaitingList: boolean;
  bExcluteWaitingListNonOptional: boolean;
  bExcluteAllotment: boolean;
  bExcluteOrder: boolean;
  bExcluteDeparted: boolean;
  bExcluteGuest: boolean;
  bExcluteBlocked: boolean;
  bExcluteNoshow: boolean;

  MaxFree: integer;
  MinAvailable: integer;
  OccTotal: integer;
  nrTotal: integer;

  tmpRoomType: string;
  tmpDescription: string;

begin
  mOcc_.DisableControls;
  try
    screen.Cursor := crHourGlass;
    try
      dateFrom := dtArrival.date;
      dateTo := dtDeparture.date;
      DateCount := trunc(dateTo) - trunc(dateFrom);

      if m_.active then
        m_.Close;
      m_.Open;

      s := '';
      s := s + 'SELECT rt.RoomType,rt.Description,  ';
      s := s + '(SELECT COUNT(Room) FROM rooms WHERE rooms.RoomType=rt.RoomType and rooms.active) AS NumRooms ';
      s := s + 'FROM roomtypes rt ';
      s := s + ' WHERE active ';
      s := s + 'ORDER BY rt.RoomType ';

      rSet := createNewDataSet;
      try
        rSet_bySQL(rSet, s);

        ADate := dateFrom;
        for i := 1 to DateCount do
        begin
          rSet.First;
          while not rSet.eof do
          begin
            m_.append;
            m_.FieldByName('RoomType').AsString := rSet.FieldByName('RoomType').AsString;
            m_.FieldByName('Description').AsString := rSet.FieldByName('Description').AsString;
            m_.FieldByName('MaxFree').AsInteger := rSet.FieldByName('NumRooms').AsInteger;
            m_.FieldByName('aDate').AsDateTime := ADate;
            m_.post;
            rSet.next;
          end;
          ADate := ADate + 1;
        end;
      finally
        FreeAndNil(rSet);
      end;

      s := '';
      s := s + 'SELECT ';
      s := s + '    ADate ';
      s := s + '  , RoomType ';
      s := s + '  , isNoRoom ';
      s := s + '  , ResFlag ';
      s := s + '  , COUNT(Room) AS RoomCount ';
      s := s + 'FROM ';
      s := s + '  roomsdate ';
      s := s + 'WHERE ';
      s := s + '  ((ADate >= ' + _db(dateFrom) + ') AND (ADate <= ' + _db(dateTo) + ')) ';
      s := s + '   AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '; // **zxhj line added
      s := s + '   AND (ResFlag <> ' + _db(STATUS_CANCELED) + ' ) '; // **zxhj line added

      s := s + 'GROUP BY ';
      s := s + '    ADate ';
      s := s + '  , RoomType ';
      s := s + '  , ResFlag ';
      s := s + '  , isNoRoom ';
      s := s + 'ORDER BY ';
      s := s + '  RoomType,ADate DESC';

      if mOcc_.active then
        mOcc_.Close;
      mOcc_.Open;

      rSet := createNewDataSet;
      try
        rSet_bySQL(rSet, s);
        rSet.First;
        while not rSet.eof do
        begin
          ADate := SQLToDateTime(rSet.FieldByName('aDate').AsString);
          RoomType := rSet.FieldByName('RoomType').AsString;
          Status := rSet.FieldByName('ResFlag').AsString;
          isNoRoom := rSet.FieldByName('isNoRoom').AsBoolean;
          RoomCount := rSet.FieldByName('RoomCount').AsInteger;

          mOcc_.append;
          mOcc_.FieldByName('RoomType').AsString := RoomType;
          mOcc_.FieldByName('Status').AsString := Status;
          mOcc_.FieldByName('aDate').AsDateTime := ADate;;
          mOcc_.FieldByName('isNoRoom').AsBoolean := isNoRoom;
          mOcc_.FieldByName('RoomCount').AsInteger := RoomCount;
          mOcc_.post;

          if m_.Locate('aDate;RoomType', VarArrayOf([ADate, RoomType]), []) then
          begin
            m_.edit;
            if isNoRoom then
            begin
              m_.FieldByName('nrTotal').AsInteger := m_.FieldByName('nrTotal').AsInteger + RoomCount;
              if Status = 'P' then
                m_.FieldByName('nrOrder').AsInteger := m_.FieldByName('nrOrder').AsInteger + RoomCount;
              if Status = 'L' then
                m_.FieldByName('nrWaitingListNonOptional').AsInteger := m_.FieldByName('nrWaitingListNonOptional').AsInteger + RoomCount;
              if Status = 'G' then
                m_.FieldByName('nrGuest').AsInteger := m_.FieldByName('nrGuest').AsInteger + RoomCount;
              if Status = 'D' then
                m_.FieldByName('nrDeparted').AsInteger := m_.FieldByName('nrDeparted').AsInteger + RoomCount;
              if Status = 'O' then
                m_.FieldByName('nrWaitingList').AsInteger := m_.FieldByName('nrWaitingList').AsInteger + RoomCount;
              if Status = 'A' then
                m_.FieldByName('nrAllotment').AsInteger := m_.FieldByName('nrAllotment').AsInteger + RoomCount;
              if Status = 'B' then
                m_.FieldByName('nrBlocked').AsInteger := m_.FieldByName('nrBlocked').AsInteger + RoomCount;
              if Status = 'N' then
                m_.FieldByName('nrNoShow').AsInteger := m_.FieldByName('nrNoShow').AsInteger + RoomCount;
            end
            else
            begin
              m_.FieldByName('occTotal').AsInteger := m_.FieldByName('occTotal').AsInteger + RoomCount;
              if Status = 'P' then
                m_.FieldByName('occOrder').AsInteger := m_.FieldByName('occOrder').AsInteger + RoomCount;
              if Status = 'L' then
                m_.FieldByName('occWaitingListNonOptional').AsInteger := m_.FieldByName('occWaitingListNonOptional').AsInteger + RoomCount;
              if Status = 'G' then
                m_.FieldByName('occGuest').AsInteger := m_.FieldByName('occGuest').AsInteger + RoomCount;
              if Status = 'D' then
                m_.FieldByName('occDeparted').AsInteger := m_.FieldByName('occDeparted').AsInteger + RoomCount;
              if Status = 'O' then
                m_.FieldByName('occWaitingList').AsInteger := m_.FieldByName('occWaitingList').AsInteger + RoomCount;
              if Status = 'A' then
                m_.FieldByName('occAllotment').AsInteger := m_.FieldByName('occAllotment').AsInteger + RoomCount;
              if Status = 'B' then
                m_.FieldByName('occBlocked').AsInteger := m_.FieldByName('occBlocked').AsInteger + RoomCount;
              if Status = 'N' then
                m_.FieldByName('occNoShow').AsInteger := m_.FieldByName('occNoShow').AsInteger + RoomCount;
            end;
            m_.post;
          end;
          rSet.next;
        end;
      finally
        FreeAndNil(rSet);
      end;
      mOcc_.First;

      bExcluteWaitingList := chkExcluteWaitingList.Checked;
      bExcluteWaitingListNonOptional := chkExcludeWaitingListNonOptional.Checked;
      bExcluteAllotment := chkExcluteAllotment.Checked;
      bExcluteOrder := chkExcluteOrder.Checked;
      bExcluteDeparted := chkExcluteDeparted.Checked;
      bExcluteGuest := chkExcluteGuest.Checked;
      bExcluteBlocked := chkExcluteBlocked.Checked;
      bExcluteNoshow := chkExcluteNoShow.Checked;

      m_.SortedField := 'RoomType';
      m_.First;
      while not m_.eof do
      begin
        MaxFree := m_.FieldByName('MaxFree').AsInteger;
        OccTotal := m_.FieldByName('occTotal').AsInteger;
        nrTotal := m_.FieldByName('nrTotal').AsInteger;
        TotalNotFree := MaxFree - OccTotal - nrTotal;
        if bExcluteWaitingList then
          TotalNotFree := TotalNotFree + m_.FieldByName('nrWaitingList').AsInteger;
        if bExcluteWaitingListNonOptional then
          TotalNotFree := TotalNotFree + m_.FieldByName('nrWaitingListNonOptional').AsInteger;
        if bExcluteAllotment then
          TotalNotFree := TotalNotFree + m_.FieldByName('nrAllotment').AsInteger;
        if bExcluteOrder then
          TotalNotFree := TotalNotFree + m_.FieldByName('nrOrder').AsInteger;
        if bExcluteDeparted then
          TotalNotFree := TotalNotFree + m_.FieldByName('nrDeparted').AsInteger;
        if bExcluteGuest then
          TotalNotFree := TotalNotFree + m_.FieldByName('nrGuest').AsInteger;
        if bExcluteBlocked then
          TotalNotFree := TotalNotFree + m_.FieldByName('nrBlocked').AsInteger;
        if bExcluteNoshow then
          TotalNotFree := TotalNotFree + m_.FieldByName('nrNoShow').AsInteger;

        m_.edit;
        m_.FieldByName('FreeRooms').AsInteger := TotalNotFree;
        m_.post;
        m_.next;
      end;
      m_.SortedField := 'RoomType';
      m_.First;

      if mSelectTypes.active then
        mSelectTypes.Close;
      mSelectTypes.Open;

      m_.SortedField := 'RoomType';
      m_.First;

      tmpRoomType := m_.FieldByName('RoomType').AsString;
      tmpDescription := m_.FieldByName('RoomType').AsString;
      MinAvailable := 1000;
      while not m_.eof do
      begin
        if tmpRoomType <> m_.FieldByName('RoomType').AsString then
        begin
          mSelectTypes.append;
          mSelectTypesRoomType.AsString := tmpRoomType;
          mSelectTypesRoomTypeDescription.AsString := tmpDescription;
          mSelectTypesAvailable.AsInteger := MinAvailable;
          mSelectTypesSelected.AsInteger := 0;
          mSelectTypesNoRooms.AsInteger := 0;
          mSelectTypes.post;
          tmpRoomType := m_.FieldByName('RoomType').AsString;
          tmpDescription := m_.FieldByName('Description').AsString;
          MinAvailable := 1000;
        end;
        if m_.FieldByName('FreeRooms').AsInteger <= MinAvailable then
          MinAvailable := m_.FieldByName('FreeRooms').AsInteger;
        m_.next;
        if m_.eof then
        begin
          mSelectTypes.append;
          mSelectTypesRoomType.AsString := m_.FieldByName('RoomType').AsString;
          mSelectTypesRoomTypeDescription.AsString := m_.FieldByName('Description').AsString;
          mSelectTypesAvailable.AsInteger := MinAvailable;
          mSelectTypesSelected.AsInteger := 0;
          mSelectTypesNoRooms.AsInteger := 0;
          mSelectTypes.post;
        end;
      end;

      // Add PriorityRule

      s := '';
      s := s + 'SELECT ';
      s := s + '  RoomType ';
      s := s + ' ,PriorityRule ';
      s := s + 'FROM roomtypes ';
      s := s + 'WHERE active ';

      rSet := createNewDataSet;
      try
        rSet_bySQL(rSet, s);
        rSet.First;
        while not rSet.eof do
        begin
          RoomType := rSet.FieldByName('RoomType').AsString;
          if mSelectTypes.Locate('RoomType', RoomType, []) then
          begin
            mSelectTypes.edit;
            mSelectTypesPriorityRule.AsString := rSet.FieldByName('PriorityRule').AsString;
            mSelectTypes.post;
          end;
          rSet.next;
        end;
      finally
        FreeAndNil(rSet);
      end;
    finally
      screen.Cursor := crDefault;
    end;

  finally
    mOcc_.EnableControls;
  end;

end;

constructor TfrmMakeReservationQuick.Create(aOwner: TComponent);
begin
  FPreviousGuestsList := TStringlist.Create;
  FPreviousGuestsList.OwnsObjects := true;
  FPreviousGuestsList.Duplicates := dupIgnore;
  FPreviousGuestsList.Sorted := true;
  inherited;
end;

procedure TfrmMakeReservationQuick.CreateRoomRes_Normal;
var
  oSelectedRoomItem: TnewRoomReservationItem;
  room: string;
  RoomType: string;
  NumberGuests: integer;
  Arrival: TDate;
  Departure: TDate;

  NumberNoRoom: integer;

  i: integer;

  RoomCount: integer;
  childrenCount: integer;
  infantCount: integer;

  RoomReservation: integer;

  RoomDescription: string;
  RoomTypeDescription: string;
  PriceCode: string;

  sID: string;
  lstIDs: TstringList;
begin
  RoomReservation := 0;
  FNewReservation.newRoomReservations.RoomItemsList.Clear;

  Arrival := dtArrival.date;
  Departure := dtDeparture.date;
  PriceCode := fraPriceCodePanel.Code;

  if not((zTotalSelected = 0) and (zTotalNoRooms > 0)) and (zTotal <> 0) then
  begin
    mSelectRooms.First;
    while not mSelectRooms.eof do
    begin
      if mSelectRoomsSelect.AsBoolean then
      begin
        room := mSelectRoomsroom.AsString;
        RoomType := mSelectRoomsRoomType.AsString;
        NumberGuests := mSelectRoomsNumberGuests.AsInteger;
        oSelectedRoomItem := TnewRoomReservationItem.Create(0, room, RoomType, '', Arrival, Departure, NumberGuests, 0, 0, 0, 0, 0, '', '', '');
        FNewReservation.newRoomReservations.RoomItemsList.Add(oSelectedRoomItem);
      end;
      mSelectRooms.next;
    end;
    mSelectRooms.First;
  end;


  mSelectTypes.First;
  while not mSelectTypes.eof do
  begin
    RoomType := mSelectTypesRoomType.AsString;
    NumberNoRoom := mSelectTypesNoRooms.AsInteger;
    if (NumberNoRoom > 0) then
    begin
      room := '';
      NumberGuests := glb.GET_RoomTypeNumberGuests_byRoomType(RoomType);
      for i := 1 to NumberNoRoom do
      begin
        oSelectedRoomItem := TnewRoomReservationItem.Create(0, room, RoomType, '', Arrival, Departure, NumberGuests, 0,
          0, 0, 0, 0, '', '', '');
        FNewReservation.newRoomReservations.RoomItemsList.Add(oSelectedRoomItem);
      end;
    end;
    mSelectTypes.next;
  end;
  mSelectTypes.First;

  mRoomRes.Close;
  mRoomRes.Open;
  mExtras.Close;
  mExtras.Open;

  RoomCount := FNewReservation.newRoomReservations.RoomCount;

  lstIDs := TstringList.Create;
  try
    sID := RR_GetIDs(RoomCount);
    _Glob._strTokenToStrings(sID, '|', lstIDs);

    for oSelectedRoomItem in FNewReservation.newRoomReservations.RoomItemsList do
    begin
      if oSelectedRoomItem.RoomReservation < 1 then
      begin
        RoomReservation := strToInt(lstIDs[0]); // RR_SetNewID();
        lstIds.Delete(0);
        oSelectedRoomItem.RoomReservation := RoomReservation;
      end;

      room := oSelectedRoomItem.RoomNumber;
      if room = '' then
        room := '<' + inttostr(RoomReservation) + '>';

      Arrival := oSelectedRoomItem.Arrival;
      Departure := oSelectedRoomItem.Departure;
      NumberGuests := oSelectedRoomItem.guestCount;
      childrenCount := oSelectedRoomItem.childrenCount;
      infantCount := oSelectedRoomItem.infantCount;
      RoomType := oSelectedRoomItem.RoomType;

      RoomDescription := '';
      RoomTypeDescription := '';

      if not(zTotalSelected = 0) and (zTotalNoRooms > 0) then
      begin
        if mSelectRooms.Locate('RoomType', RoomType, []) then
        begin
          RoomDescription := mSelectRoomsDescription.AsString;
          RoomTypeDescription := mSelectRoomsRoomTypeDescription.AsString;
        end;
      end;

      if (copy(room, 1, 1)) = '<' then
      begin
        // It is noroom
        // There is no roomdescription
        // .. Get the roomType Description
        RoomTypeDescription := glb.GetRoomTypeDescription(RoomType);
        if NumberGuests = 0 then
          NumberGuests := glb.GET_RoomTypeNumberGuests_byRoomType(RoomType);
      end;

      mRoomRes.Insert;
      try
        mRoomResRoomReservation.AsInteger := RoomReservation;
        mRoomResroom.AsString := room;
        mRoomResRoomType.AsString := RoomType;
        mRoomResGuests.AsInteger := NumberGuests;
        mRoomResRateCount.AsFloat := 0;

        mRoomResAvragePrice.AsFloat := 0;
        mRoomResAvrageDiscount.AsFloat := 0;

        mRoomResManualChannelId.AsInteger := 0;
        mRoomResratePlanCode.AsString := '';

        mRoomResRoomDescription.AsString := RoomDescription;
        mRoomResRoomTypeDescription.AsString := RoomTypeDescription;
        mRoomResarrival.AsDateTime := Arrival;
        mRoomResdeparture.AsDateTime := Departure;
        mRoomResChildrenCount.AsInteger := childrenCount;
        mRoomResInfantCount.AsInteger := infantCount;
        mRoomResPriceCode.AsString := PriceCode;
        mRoomResPersonsProfilesId.AsInteger := edtPortfolio.Tag;
        if chkContactIsGuest.Checked AND (Trim(edContactPerson1.Text) <> '') then
          mRoomResMainGuest.AsString := edContactPerson1.Text
        else if (Trim(edtPortfolio.Text) <> '') then
          mRoomResMainGuest.AsString := edtPortfolio.Text
        else
          mRoomResMainGuest.AsString := edReservationName.Text;
        mRoomRes.post;
      except
        mRoomRes.Cancel;
        raise;
      end;
    end; //for

  finally
    FreeAndNil(lstIDs);
  end;

  if mRoomRes.RecordCount > 0 then
  begin
    btnFinish.Enabled := true;
    memRoomNotes.Enabled := true;
    clabRoomNotes.Visible := true;

    mRoomRes.First;
  end;
end;

function TfrmMakeReservationQuick.CreateRoomRes_Quick: boolean;
var
  rSetRooms: TRoomerDataSet;
  i: integer;

  s: string;

  Arrival: TDateTime;
  Departure: TDateTime;

  RoomReservation: integer;
  room: string;
  RoomType: string;
  Guests: integer;

  RoomDescription: string;
  RoomTypeDescription: string;
  childrenCount: integer;
  infantCount: integer;
  RoomCount: integer;

  PriceCode: string;

  defaultGuests: integer;

  sID: string;
  lstIDs: TstringList;
  sRoomsInList: string;
  sRoomTypes: TStrings;
  sMessage: String;

  ExecutionPlan: TRoomerExecutionPlan;

  AvailabilityPerDay: TAvailabilityPerDay;

  lRoomReservation: TnewRoomReservationItem;

begin
  Result := true;
  RoomReservation := 0;
  PriceCode := fraPriceCodePanel.Code;

  if mRoomRes.active then
    mRoomRes.Close;
  mRoomRes.Open;
  mExtras.Open;
  RoomCount := FNewReservation.newRoomReservations.RoomCount;

  lstIDs := TstringList.Create;
  try

    sID := RR_GetIDs(RoomCount);
    _Glob._strTokenToStrings(sID, '|', lstIDs);

    sRoomsInList := '';

    for i := 0 to RoomCount - 1 do
    begin
      room := FNewReservation.newRoomReservations.RoomItemsList[i].RoomNumber;
      if room <> '' then
      begin
        sRoomsInList := sRoomsInList + _db(room) + ',';
      end;
    end;

    if sRoomsInList <> '' then
      Delete(sRoomsInList, length(sRoomsInList), 1);

    s := '';
    s := s + ' SELECT ' + #10;
    s := s + '     rooms.Room ' + #10;
    s := s + '   , rooms.Description AS RoomDescription ' + #10;
    s := s + '   , rooms.RoomType ' + #10;
    s := s + '   , roomtypes.NumberGuests ' + #10;
    s := s + '   , roomtypes.Description AS RoomTypeDescription ' + #10;
    s := s + ' FROM ' + #10;
    s := s + '   rooms ' + #10;
    s := s + '   LEFT OUTER JOIN roomtypes ON rooms.RoomType = roomtypes.RoomType ' + #10;
    s := s + ' WHERE ' + #10;
    s := s + '   (rooms.Room in (' + sRoomsInList + '))' + #10;

    ExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
    try
      ExecutionPlan.AddQuery(s);
      ExecutionPlan.Execute(ptQuery);
      rSetRooms := ExecutionPlan.Results[0];

      for i := 0 to FNewReservation.newRoomReservations.RoomItemsList.Count-1 do
      begin
        lRoomReservation := FNewReservation.newRoomReservations.RoomItemsList[i];
        if lRoomReservation.RoomReservation < 1 then
        begin
          RoomReservation := strToInt(lstIDs[i]); // RR_SetNewID();
          lRoomReservation.RoomReservation := RoomReservation;
        end;

        room := lRoomReservation.RoomNumber;
        if room = '' then
        begin
          room := '<' + inttostr(RoomReservation) + '>';
          RoomType := lRoomReservation.RoomType;
        end;

        Arrival := lRoomReservation.Arrival;
        Departure := lRoomReservation.Departure;
        childrenCount := lRoomReservation.childrenCount;
        infantCount := lRoomReservation.infantCount;

        if (copy(room, 1, 1)) <> '<' then
        begin
          rSetRooms.Locate('room', room, []);
          RoomDescription := rSetRooms.FieldByName('RoomDescription').AsString;
          RoomType := rSetRooms.FieldByName('RoomType').AsString;
          lRoomReservation.RoomType := RoomType;
          defaultGuests := rSetRooms.FieldByName('NumberGuests').AsInteger;
          RoomTypeDescription := rSetRooms.FieldByName('RoomTypeDescription').AsString;
        end
        else
        begin // It is noroom
          // There is no roomdescription
          // .. Get the roomType Description
          RoomTypeDescription := glb.GetRoomTypeDescription(RoomType);
          defaultGuests := glb.GET_RoomTypeNumberGuests_byRoomType(RoomType);
        end;

        Guests := defaultGuests;

        mRoomRes.append;
        try
          mRoomResRoomReservation.AsInteger := RoomReservation;
          mRoomResroom.AsString := room;
          mRoomResRoomType.AsString := RoomType;
          mRoomResGuests.AsInteger := Guests;
          mRoomResAvragePrice.AsFloat := 0;
          mRoomResRateCount.AsFloat := 0;
          mRoomResAvrageDiscount.AsFloat := 0;

          mRoomResManualChannelId.AsInteger := 0;
          mRoomResratePlanCode.AsString := '';

          mRoomResRoomDescription.AsString := RoomDescription;
          mRoomResRoomTypeDescription.AsString := RoomTypeDescription;
          mRoomResarrival.AsDateTime := Arrival;
          mRoomResdeparture.AsDateTime := Departure;
          mRoomResChildrenCount.AsInteger := childrenCount;
          mRoomResInfantCount.AsInteger := infantCount;
          mRoomResPriceCode.AsString := PriceCode;
          mRoomResPersonsProfilesId.AsInteger := edtPortfolio.Tag;

          if chkContactIsGuest.Checked AND (Trim(edContactPerson1.Text) <> '') then
            mRoomResMainGuest.AsString := edContactPerson1.Text
          else if (Trim(edtPortfolio.Text) <> '') then
            mRoomResMainGuest.AsString := edtPortfolio.Text
          else
            mRoomResMainGuest.AsString := edReservationName.Text;

          mRoomRes.post;

        except
          mRoomRes.Cancel;
          raise;
        end;
      end;
      zIsFirstTime := false;

      if g.qWarnWhenOverbooking then
      begin
        sMessage := '';

        //TODO Improve for roomreservations with different arrival and departure date. which is possible by
        // selecting cells from the period grid and starting quick reservation
        AvailabilityPerDay := TAvailabilityPerDay.Create(dtArrival.date, dtDeparture.date, FNewReservation);
        sRoomTypes := AvailabilityPerDay.Overbookings;
        try
          sMessage := sRoomTypes.Text;
        finally
          sRoomTypes.Free;
          AvailabilityPerDay.Free;
        end;
        if sMessage <> '' then
        begin
          s := GetTranslatedText('shTx_Various_WouldCreateOverbooking') +
            sMessage + #10#10 +
            GetTranslatedText('shTx_Various_AreYoySureYouWantToContinue');
          if MessageDlg(s, mtWarning, [mbYes, mbCancel], 0) <> mrYes then
            Result := false;
        end;
      end;

    finally
      FreeAndNil(ExecutionPlan);
    end;

  finally
    FreeAndNil(lstIDs);
  end;
end;

procedure TfrmMakeReservationQuick.PopulateRatePlanCombo(clearAll: boolean = true);
begin
  if clearAll then
  begin
    (tvRoomResRatePlanCode.Properties AS TcxComboBoxProperties).Items.Clear;
    (tvRoomResRatePlanCode.Properties AS TcxComboBoxProperties).Items.Add('');
  end;
  FDynamicRates.GetAllRateCodes((tvRoomResRatePlanCode.Properties AS TcxComboBoxProperties).Items);
end;

procedure TfrmMakeReservationQuick.GetPrices;
var
  lstPrices: TstringList;
  RoomReservation: integer;

  i, ii: integer;

  room: string;
  RoomType: string;
  Guests: integer;
  AvragePrice: double;
  RateCount: integer;
  RoomDescription: string;
  RoomTypeDescription: string;
  Arrival: TDateTime;
  Departure: TDateTime;
  childrenCount: integer;
  infantCount: integer;
  DiscountAmount: double;
  RentAmount: double;
  NativeAmount: double;

  priceID: integer;
  PriceCode: string;

  rateTotal: double;
  rateAvrage: double;

  dayCount: integer;
  ADate: TDateTime;
  dateFrom: TDate;
  dateTo: TDate;

  RateDate: TDate;
  Rate: double;

  isPercentage: boolean;
  isPaid: boolean;

  Currency: string;
  CurrencyRate: double;
  Discount: double;
  ShowDiscount: boolean;

  discountTotal: double;
  discountAvrage: double;

  rateSet: TRoomerDataSet;

  s: string;
  lstRoomTypes: TstringList;
  inStrRoomTypes: string;
  andRoomTypes: String;

  FirstArrival: TDate;
  LastDeparture: TDate;

  price1p: double;
  price2p: double;
  price3p: double;
  price4p: double;
  price5p: double;
  price6p: double;
  priceEp: double;
  PriceEc: double;
  PriceEi: double;

  function finalPrice(p1, p2, p3, p4, p5, p6, Ep, Ec, Ei: double; guestCount, ChildCount, infantCount: integer): double;
  var
    extraPersons: double;
  begin
    extraPersons := guestCount - 5;

    if p1 = 0 then
      p1 := Ep;
    if p2 = 0 then
      p2 := p1 + Ep;
    if p3 = 0 then
      p3 := p2 + Ep;
    if p4 = 0 then
      p4 := p3 + Ep;
    if p5 = 0 then
      p5 := p4 + Ep;
    if p6 = 0 then
      p6 := p5 + Ep;

    Result := 0;
    if guestCount = 1 then
      Result := p1;
    if guestCount = 2 then
      Result := p2;
    if guestCount = 3 then
      Result := p3;
    if guestCount = 4 then
      Result := p4;
    if guestCount = 5 then
      Result := p5;
    if guestCount = 6 then
      Result := p6;

    if guestCount > 6 then
      Result := p6 + (extraPersons * Ep);

    Result := Result + (Ec * ChildCount);
    Result := Result + (Ei * infantCount);
  end;

  function lclCalculatePrice(const aRoomType: string; aPriceID: integer; const aCurrCode: string; OnDate: TDate): double;
  begin
    Result := 0;

    rateset.IndexFieldNames := 'Roomtype;PriceCodeId;Currency';
    rateset.First;
    while not rateset.Eof do
        if (rateSet.FieldByName('roomtype').asString = aRoomtype) and
            (rateset.FieldByName('pricecodeid').asInteger = aPriceID) and
            (rateset.FieldByName('currency').asString = aCurrCode) and
            (trunc(rateset.FieldByName('datefrom').AsDateTime) <= onDate) and
            (trunc(rateset.FieldByName('dateto').AsDateTime) >= onDate) then
        begin
          result := finalPrice(
                rateSet.FieldByName('Rate1Person').asFloat
              , rateSet.FieldByName('Rate2Persons').AsFloat
              , rateSet.FieldByName('Rate3Persons').AsFloat
              , rateSet.FieldByName('Rate4Persons').AsFloat
              , rateSet.FieldByName('Rate5Persons').AsFloat
              , rateSet.FieldByName('Rate6Persons').AsFloat
              , rateSet.FieldByName('RateExtraPerson').AsFloat
              , rateSet.FieldByName('RateExtraChildren').AsFloat
              , rateSet.FieldByName('RateExtraInfant').AsFloat
              , Guests
              , childrenCount
              , infantCount);
          Break;
        end
        else
          rateset.Next;
  end;


var
  rateId: String;
  channelId: integer;
  lRateCurrency: string;
begin
  channelId := 0;
  if cbxChannels.ItemIndex > 0 then
    channelId := integer(cbxChannels.Items.Objects[cbxChannels.ItemIndex]);
  isPaid := false;
  mRoomRes.DisableControls;
  lstPrices := TstringList.Create;
  lstRoomTypes := TstringList.Create;

  rateSet := createNewDataSet;
  try

    lstRoomTypes.Sorted := true;
    lstRoomTypes.Duplicates := dupIgnore;

    mRoomRes.First;
    if not mRoomRes.eof then
    begin
      FirstArrival := mRoomResArrival.AsDateTime;
      LastDeparture := mRoomResdeparture.AsDateTime;
      while not mRoomRes.eof do
      begin
        if mRoomResArrival.AsDateTime < FirstArrival then
          FirstArrival := mRoomResArrival.AsDateTime;
        if mRoomResDeparture.AsDateTime > LastDeparture then
          LastDeparture := mRoomResDeparture.AsDateTime;
        RoomType := mRoomResRoomType.AsString;
        lstRoomTypes.Add(_db(RoomType));
        mRoomRes.next;
      end;
    end;

    s := '';
    s := s + 'SELECT '#10;
    s := s + '    roomrates.PriceCodeID AS PriceCodeID, '#10;
    s := s + '    c.Currency AS Currency, '#10;
    s := s + '    roomtypes.RoomType AS RoomType, '#10;
    s := s + '    rates.Rate1Person AS Rate1Person, '#10;
    s := s + '    rates.Rate2Persons AS Rate2Persons, '#10;
    s := s + '    rates.Rate3Persons AS Rate3Persons, '#10;
    s := s + '    rates.Rate4Persons AS Rate4Persons, '#10;
    s := s + '    rates.Rate5Persons AS Rate5Persons, '#10;
    s := s + '    rates.Rate6Persons AS Rate6Persons, '#10;
    s := s + '    rates.RateExtraPerson AS RateExtraPerson, '#10;
    s := s + '    rates.RateExtraChildren AS RateExtraChildren, '#10;
    s := s + '    rates.RateExtraInfant AS RateExtraInfant, '#10;
    s := s + '    roomrates.DateFrom AS DateFrom, '#10;
    s := s + '    roomrates.DateTo AS DateTo, '#10;
    s := s + '   DATEDIFF(DateTo,DateFrom) AS DateCount '#10;

    s := s + 'FROM predefineddates, '#10;
    s := s + '    (((((roomrates '#10;
    s := s + '    left join tblpricecodes ON roomrates.PriceCodeID = tblpricecodes.ID) '#10;
    s := s + '    left join rates ON roomrates.RateID = rates.ID) '#10;
    s := s + '    left join tblseasons ON roomrates.SeasonID = tblseasons.ID) '#10;
    s := s + '    left join roomtypes ON roomrates.RoomTypeID = roomtypes.ID) '#10;
    s := s + '    left join currencies c ON roomrates.CurrencyID = c.ID) '#10;
    s := s + 'WHERE '#10;
    s := s + '       predefineddates.date >= %s AND predefineddates.date <= %s '#10;
    s := s + '  AND  PriceCodeID = %d '#10;
    s := s + '  AND  c.Currency in (%s) '#10;
    s := s + '  %s '#10;
    s := s + '  AND  (DateFrom <= predefineddates.date AND DateTo >= predefineddates.date)'#10;
    s := s + 'ORDER by '#10;
    s := s + '  roomtypes.RoomType '#10;
    s := s + '  , PriceCodeID '#10;
    s := s + '  , currency '#10;
    s := s + '  , DateCount '#10;

    lstPrices.Sorted := true;
    lstPrices.Duplicates := dupIgnore;

    Discount := edRoomResDiscount.Value;
    ShowDiscount := true;
    isPercentage := cbxIsRoomResDiscountPrec.ItemIndex = 0;

    PriceCode := fraPriceCodePanel.Code;
    priceID := hData.PriceCode_ID(PriceCode);

    andRoomTypes := '';
    if lstRoomTypes.Count > 0 then
      andRoomTypes := format('AND  `RoomType` IN (%s) ', [lstRoomTypes.CommaText]);

    s := format(s, [_db(FirstArrival, true)
      , _db(LastDeparture, true)
      , priceID
      , _db(FCurrentCurrency.CurrencyCode) + ',' + _db(g.qNativeCurrency)
      , andRoomTypes
      ]);

    copytoclipboard(s);
    rSet_bySQL(rateSet, s);

    if mRoomRates.active then
      mRoomRates.Close;
    mRoomRates.Open;

    mRoomRes.First;
    while not mRoomRes.eof do
    begin
      RoomReservation := mRoomResroomReservation.AsInteger;

      i := FNewReservation.newRoomReservations.FindRoomFromRoomReservation(RoomReservation, 0);
      FNewReservation.newRoomReservations.RoomItemsList[i].Rates.RateItemsList.Clear;

      room := mRoomResroom.AsString;
      Arrival := mRoomResarrival.AsDateTime;
      Departure := mRoomResdeparture.AsDateTime;
      RoomType := mRoomResRoomType.AsString;
      RoomTypeDescription := mRoomResRoomTypeDescription.AsString;
      RoomDescription := mRoomResRoomDescription.AsString;
      Guests := mRoomResGuests.AsInteger;
      childrenCount := mRoomResChildrenCount.AsInteger;
      infantCount := mRoomResinfantCount.AsInteger;

      dayCount := trunc(Departure) - trunc(Arrival);

      ADate := trunc(Arrival);
      rateId := '';
      rateTotal := 0;
      discountTotal := 0;
      lstPrices.Clear;
      for ii := 0 to dayCount - 1 do
      begin
        if FDynamicRates.active AND
          FDynamicRates.findRateForRoomType(trunc(Arrival) + ii, RoomType, mRoomRes['Guests'], Rate, rateId, lRateCurrency) then
        begin
          // Rate acuired
          Rate := RoomerCurrencyManager.ConvertAmount(TAmount.Create(Rate, lRateCurrency), FCurrentCurrency.CurrencyCode);
        end
        else
        begin
          Rate := lclCalculatePrice(RoomType, priceId, FCurrentCurrency.CurrencyCode, trunc(Arrival) + ii);
          if Rate = 0 then
            Rate := lclCalculatePrice(RoomType, priceId, g.qNativeCurrency, trunc(Arrival) + ii) / FCurrentCurrency.Rate;
        end;

        if isPercentage then
          DiscountAmount := Rate * Discount / 100
        else
          DiscountAmount := Min(Rate, Discount);

        RentAmount := max(0, Rate - DiscountAmount);
        NativeAmount := RentAmount * FCurrentCurrency.Rate;

        mRoomRates.append;
        try
          mRoomRatesReservation.AsInteger := -1;
          mRoomRatesRoomReservation.AsInteger := RoomReservation;
          mRoomRatesRoomNumber.AsString := room;
          mRoomRatesRateDate.AsDateTime := Arrival + ii;
          mRoomRatesPriceCode.AsString := PriceCode;
          mRoomRatesRate.AsFloat := Rate;
          mRoomRatesDiscount.AsFloat := Discount;
          mRoomRatesisPercentage.AsBoolean := isPercentage;
          mRoomRatesShowDiscount.AsBoolean := ShowDiscount;
          mRoomRatesisPaid.AsBoolean := isPaid;
          mRoomRatesDiscountAmount.AsFloat := DiscountAmount;
          mRoomRatesRentAmount.AsFloat := RentAmount;
          mRoomRatesNativeAmount.AsFloat := NativeAmount;
          mRoomRatesCurrency.AsString := FCurrentCurrency.CurrencyCode;
          mRoomRatesCurrencyRate.AsFloat := FCurrentCurrency.Rate;
          mRoomRates.post;
        except
          mRoomRates.Cancel;
          raise;
        end;

        lstPrices.Add(floatTostr(RentAmount));
        rateTotal := rateTotal + RentAmount;
        discountTotal := discountTotal + Discount;
        ADate := ADate + 1
      end;

      UpdateRatesInRoomRes(Roomreservation, channelId, rateId);

//      rateAvrage := 0;
//      discountAvrage := 0;
//      if dayCount <> 0 then
//      begin
//        rateAvrage := rateTotal / dayCount;
//        discountAvrage := discountTotal / dayCount
//      end;
//      RateCount := lstPrices.Count;
//      mRoomRes.edit;
//      try
//        mRoomResAvragePrice.AsFloat := rateAvrage;
//        mRoomResRateCount.AsFloat := RateCount;
//        mRoomResRoomRate.AsFloat := Rate;
//
//        if mRoomResIsPercentage.AsBoolean then
//          mRoomResDiscount.AsFloat := discountAvrage / rateAvrage * 100
//        else
//          mRoomResDiscount.AsFloat := discountTotal;
//
//        mRoomResAvrageDiscount.AsFloat := discountAvrage;
//
//        mRoomResManualChannelId.AsInteger := channelId;
//        mRoomResratePlanCode.AsString := rateId;
//        mRoomRes.post;
//      except
//        mRoomRes.Cancel;
//        raise;
//      end;
      mRoomRes.next;
    end;
  finally
    FreeAndNil(rateSet);
    FreeAndNil(lstPrices);
    FreeAndNil(lstRoomTypes);
    mRoomRes.First;
    mRoomRes.EnableControls;
  end;
end;

procedure TfrmMakeReservationQuick.CalcOnePrice(RoomReservation: integer; NewRate: double = 0);
var
  lstPrices: TstringList;

  i, ii: integer;

  room: string;
  RoomType: string;
  Guests: integer;
  RoomDescription: string;
  RoomTypeDescription: string;
  Arrival: TDateTime;
  Departure: TDateTime;
  childrenCount: integer;
  infantCount: integer;
  DiscountAmount: double;
  RentAmount: double;
  NativeAmount: double;

  priceID: integer;
  PriceCode: string;

  rateTotal: double;
  rateAverage: double;

  discountTotal: double;
  discountAverage: double;

  dayCount: integer;
  ADate: TDateTime;

  RateDate: TDate;
  Rate: double;

  isPercentage: boolean;
  isPaid: boolean;

  Discount: double;
  ShowDiscount: boolean;
  found: boolean;

  rateId: String;
  channelId: integer;
  lRateCurrency: string;
begin
  channelId := 0;
  if cbxChannels.ItemIndex > 0 then
    channelId := integer(cbxChannels.Items.Objects[cbxChannels.ItemIndex]);
  isPaid := false;
  lstPrices := TstringList.Create;
  try
    lstPrices.Sorted := true;
    lstPrices.Duplicates := dupIgnore;

    ShowDiscount := true;
    isPercentage := cbxIsRoomResDiscountPrec.ItemIndex = 0;

    if mRoomRes.Locate('roomreservation', RoomReservation, []) then
    begin

      repeat
        found := mRoomRates.Locate('roomreservation', RoomReservation, []);
        if found then
        begin
          mRoomRates.Delete;
        end;
      until not found;

      i := FNewReservation.newRoomReservations.FindRoomFromRoomReservation(RoomReservation, 0);
      FNewReservation.newRoomReservations.RoomItemsList[i].Rates.RateItemsList.Clear;

      room := mRoomResroom.AsString;
      Arrival := mRoomResarrival.AsDateTime;
      Departure := mRoomResdeparture.AsDateTime;
      RoomType := mRoomResRoomType.AsString;
      RoomTypeDescription := mRoomResRoomTypeDescription.AsString;
      RoomDescription := mRoomResRoomDescription.AsString;
      Guests := mRoomResGuests.AsInteger;
      childrenCount := mRoomResChildrenCount.AsInteger;
      infantCount := mRoomResinfantCount.AsInteger;
      Discount := mRoomResavrageDiscount.AsFloat;

      PriceCode := fraPriceCodePanel.Code;
      priceID := hData.PriceCode_ID(PriceCode);

      dayCount := trunc(Departure) - trunc(Arrival);
      ADate := trunc(Arrival);
      rateId := '';
      rateTotal := 0;
      discountTotal := 0;
      lstPrices.Clear;
      for ii := 0 to dayCount - 1 do
      begin
        if (NewRate <> 0) then
        begin
          Rate := NewRate;
          Discount := 0;
        end
        else
        begin
          if FDynamicRates.active AND
            FDynamicRates.findRateForRoomType(trunc(Arrival) + ii, RoomType, mRoomRes['Guests'], Rate, rateId, lRateCurrency) then
          begin
            // Rate acuired
            Rate := RoomerCurrencyManager.ConvertAmount(Tamount.Create(Rate, lRateCurrency), FCurrentCurrency.CurrencyCode);
          end
          else
          begin
            Rate := FNewReservation.newRoomReservations.RoomItemsList[i].Rates.GetDayRate
              (RoomType
              , room
              , ADate
              , Guests
              , childrenCount
              , infantCount
              , FCurrentCurrency.CurrencyCode
              , priceID
              , Discount
              , ShowDiscount
              , isPercentage
              , isPaid
              , false

              );
          end;
        end;

        if isPercentage then
          DiscountAmount := Rate * Discount / 100
        else
          DiscountAmount := min(Rate, Discount);
        RentAmount := Rate - DiscountAmount;
        NativeAmount := RentAmount * FCurrentCurrency.Rate;

        mRoomRates.append;
        try
          mRoomRatesReservation.AsInteger := -1;
          mRoomRatesRoomReservation.AsInteger := RoomReservation;
          mRoomRatesRoomNumber.AsString := room;
          mRoomRatesRateDate.AsDateTime := ADate;
          mRoomRatesPriceCode.AsString := PriceCode;
          mRoomRatesRate.AsFloat := Rate;

          mRoomRatesDiscount.AsFloat := Discount;
          mRoomRatesisPercentage.AsBoolean := isPercentage;
          mRoomRatesShowDiscount.AsBoolean := ShowDiscount;
          mRoomRatesisPaid.AsBoolean := isPaid;
          mRoomRatesDiscountAmount.AsFloat := DiscountAmount;
          mRoomRatesRentAmount.AsFloat := RentAmount;
          mRoomRatesNativeAmount.AsFloat := NativeAmount;
          mRoomRatesCurrency.AsString := FCurrentCurrency.CurrencyCode;
          mRoomRatesCurrencyRate.AsFloat := FCurrentCurrency.rate;
          mRoomRates.post;
        except
          mRoomRates.Cancel;
          raise;
        end;

        lstPrices.Add(floatTostr(RentAmount));
        rateTotal := rateTotal + RentAmount;
        discountTotal := discountTotal + DiscountAmount;
        ADate := ADate + 1
      end;

      UpdateRatesInRoomRes(Roomreservation, channelid, rateId);

//      rateAverage := 0;
//      discountAverage := 0;
//
//      if dayCount <> 0 then
//      begin
//        rateAverage := rateTotal / dayCount;
//        discountAverage := discountTotal / dayCount
//      end;
//      RateCount := lstPrices.Count;
//      mRoomRes.edit;
//      try
//        mRoomResAvragePrice.AsFloat := rateAverage;
//        mRoomResRateCount.AsFloat := RateCount;
//        mRoomResAvrageDiscount.AsFloat := discountAverage;
//
//        if mRoomResIsPercentage.AsBoolean then
//          mRoomResDiscount.AsFloat := discountAverage / rateAverage * 100
//        else
//          mRoomResDiscount.AsFloat := discountTotal;
//
//        mRoomResManualChannelId.AsInteger := channelId;
//        mRoomResratePlanCode.AsString := rateId;
//        mRoomRes.post;
//      except
//        mRoomRes.Cancel;
//        raise;
//      end;
    end;
  finally
    FreeAndNil(lstPrices);
  end;
end;

function TfrmMakeReservationQuick.Apply: boolean;
var
  oSelectedRoomItem: TnewRoomReservationItem;
  room: string;
  RoomType: string;
  package: string;
  Arrival: TDateTime;
  Departure: TDateTime;
  guestCount: integer;
  RoomReservation: integer;
  AvragePrice: double;
  AvrageDiscount: double;
  RateCount: integer;
  childrenCount: integer;
  infantCount: integer;
  PriceCode: string;

  rateRoomNumber: string;
  RateDate: TDate;
  Rate: double;
  ratePriceCode: string;
  rateDiscount: double;
  rateIsPercentage: boolean;
  rateShowDiscount: boolean;
  rateIsPaid: boolean;
  rateItem: TRateItem;
  mainGuestName: string;
  RoomNotes: string;
  lReservationExtra: TReservationExtra;
begin
  Result := true;
  FNewReservation.SendConfirmationEmail := chkSendConfirmation.Enabled AND chkSendConfirmation.Checked;
  FNewReservation.HomeCustomer.Customer := fraCustomerPanel.Code;

  if chkContactIsGuest.Checked then
  begin
    if Trim(edContactPerson1.Text) = '' then
    begin
      FNewReservation.HomeCustomer.GuestName := GetTranslatedText('MainGuestConstant_Version_1');
    end
    else
    begin
      FNewReservation.HomeCustomer.GuestName := edContactPerson1.Text;
    end;
  end
  else
  begin
    FNewReservation.HomeCustomer.GuestName := GetTranslatedText('MainGuestConstant_Version_1');
  end;

  FNewReservation.HomeCustomer.invRefrence := edInvRefrence.Text;
  FNewReservation.HomeCustomer.Country := fraLookupCountry.Code;
  FNewReservation.HomeCustomer.ReservationName := edReservationName.Text;
  FNewReservation.HomeCustomer.RoomStatus := RoomStatusToInfo(cbxRoomStatus.ItemIndex);
  FNewReservation.HomeCustomer.MarketSegmentCode := fraLookupMarketSegment.Code;
  FNewReservation.HomeCustomer.IsGroupInvoice := chkGroupInvoice.Checked;
  FNewReservation.HomeCustomer.Currency := FCurrentCurrency.CurrencyCode;
  FNewReservation.HomeCustomer.PcCode := fraPriceCodePanel.Code;
  FNewReservation.HomeCustomer.PID := edPID.Text;
  FNewReservation.HomeCustomer.CustomerName := fraCustomerPanel.Description;
  FNewReservation.HomeCustomer.Address1 := edAddress1.Text;
  FNewReservation.HomeCustomer.Address2 := edAddress2.Text;
  FNewReservation.HomeCustomer.Address3 := edAddress3.Text;
  FNewReservation.HomeCustomer.Tel1 := edTel1.Text;
  FNewReservation.HomeCustomer.Tel2 := edTel2.Text;
  FNewReservation.HomeCustomer.Fax := edFax.Text;
  FNewReservation.HomeCustomer.EmailAddress := edEmailAddress.Text;
  FNewReservation.HomeCustomer.HomePage := edHomePage.Text;
  FNewReservation.HomeCustomer.ContactPhone := edContactPhone.Text;
  FNewReservation.HomeCustomer.ContactMobile := edContactMobile.Text;
  FNewReservation.HomeCustomer.ContactPerson := edContactPerson1.Text;
  FNewReservation.HomeCustomer.ContactAddress1 := edContactAddress1.Text;
  FNewReservation.HomeCustomer.ContactAddress2 := edContactAddress2.Text;
  FNewReservation.HomeCustomer.ContactAddress3 := edContactAddress3.Text;
  FNewReservation.HomeCustomer.ContactAddress4 := edContactAddress4.Text;
  // 0810-hj   FNewReservation.HomeCustomer.ContactCountry         := edContactCountry.text   ;
  FNewReservation.HomeCustomer.ContactCountry := fraLookupCountry.Code;
  FNewReservation.HomeCustomer.PersonProfileId := edtPortfolio.Tag;
  FNewReservation.HomeCustomer.CreatePersonProfileId := cbxAddToGuestProfiles.Checked;

  FNewReservation.HomeCustomer.ContactFax := edContactFax.Text;
  FNewReservation.HomeCustomer.ContactEmail := edContactEmail.Text;
  FNewReservation.HomeCustomer.ReservationPaymentInfo := memReservationPaymentInfo.Text;
  FNewReservation.HomeCustomer.ReservationGeneralInfo := memReservationGeneralInfo.Text;
  FNewReservation.HomeCustomer.ShowDiscountOnInvoice := true;
  FNewReservation.HomeCustomer.isRoomResDiscountPrec := cbxIsRoomResDiscountPrec.ItemIndex = 0;
  FNewReservation.HomeCustomer.RoomResDiscount := edRoomResDiscount.Value;
  FNewReservation.HomeCustomer.contactIsMainGuest := chkContactIsGuest.Checked;

  FNewReservation.OutOfOrderBlocking := OutOfOrderBlocking;
  FNewReservation.Market := TReservationMarketType(cbxMarket.itemindex);
  mRoomRates.SortedField := 'ratedate';

  memReservationGeneralInfo.Clear;

  FNewReservation.newRoomReservations.RoomItemsList.Clear;
  mRoomRes.First;

  while not mRoomRes.eof do
  begin
    room := mRoomResRoom.AsString;
    RoomType := mRoomResRoomType.AsString;
    Package := mRoomResPackage.AsString;
    Arrival := mRoomResArrival.AsDateTime;
    Departure := mRoomResDeparture.AsDateTime;
    guestCount := mRoomResGuests.AsInteger;
    RoomReservation := mRoomResRoomReservation.AsInteger;
    if NOT OutOfOrderBlocking then
    begin
      AvragePrice := glb.GetRateInclusive(-1, ctrlGetString('RoomRentItem'),
        mRoomResAvragePrice.AsFloat);
      AvrageDiscount := mRoomResAvrageDiscount.AsFloat;
    end
    else
    begin
      AvragePrice := 0.00;
      AvrageDiscount := 0.00;
    end;
    RateCount := mRoomResRateCount.AsInteger;
    childrenCount := mRoomResChildrenCount.AsInteger;
    infantCount := mRoomResinfantCount.AsInteger;
    PriceCode := mRoomResPriceCode.AsString;
    mainGuestName := mRoomResMainGuest.AsString;
    RoomNotes := mRoomResroomNotes.AsString;

    if Trim(mainGuestName) = '' then
    begin
      if chkContactIsGuest.Checked then
      begin
        mainGuestName := edContactPerson1.Text;
        if Trim(mainGuestName) = '' then
          mainGuestName := GetTranslatedText('MainGuestConstant_Version_1'); // MainGuestConstant_Version_1;;
      end
      else
      begin
        mainGuestName := GetTranslatedText('MainGuestConstant_Version_1'); // MainGuestConstant_Version_1;
      end;
    end;

    oSelectedRoomItem := TnewRoomReservationItem.Create(RoomReservation, room, RoomType, package, Arrival, Departure,
      guestCount, AvragePrice, AvrageDiscount, RateCount, childrenCount, infantCount, PriceCode,
      mainGuestName, RoomNotes);
    oSelectedRoomItem.ManualChannelId := mRoomResManualChannelId.AsInteger;
    oSelectedRoomItem.ratePlanCode := mRoomResratePlanCode.AsString;
    oSelectedRoomItem.ExpTOA := mRoomResExpectedTimeOfArrival.AsString;
    oSelectedRoomItem.ExpCOT := mRoomResExpectedCheckOutTime.AsString;
    oSelectedRoomItem.Rates.SetCurrency(FCurrentCurrency.CurrencyCode);
    FNewReservation.newRoomReservations.RoomItemsList.Add(oSelectedRoomItem);

    mRoomRates.First;
    while not mRoomRates.eof do
    begin
      // �etta er sk�tamixi�
      if mRoomRatesroomreservation.AsInteger = RoomReservation then
      begin
        rateRoomNumber := mRoomRatesRoomNumber.AsString;
        RateDate := mRoomRatesRateDate.AsDateTime;
        if NOT OutOfOrderBlocking then
        begin
          Rate := glb.GetRateInclusive(-1, ctrlGetString('RoomRentItem'), mRoomRatesrate.AsFloat);
          if mRoomRatesisPercentage.AsBoolean then
            rateDiscount := mRoomRatesDiscount.AsFloat
          else
            rateDiscount := glb.GetRateInclusive(-1, ctrlGetString('RoomRentItem'),
              mRoomRatesDiscount.AsFloat);
        end
        else
        begin
          Rate := 0.00;
          rateDiscount := 0.00;
        end;
        ratePriceCode := mRoomRatesPriceCode.AsString;
        rateIsPercentage := mRoomRatesisPercentage.AsBoolean;
        rateShowDiscount := mRoomRatesShowDiscount.AsBoolean;
        rateIsPaid := mRoomRatesisPaid.AsBoolean;
        rateItem := TRateItem.Create(Rate, RateDate, rateDiscount, rateShowDiscount, rateIsPercentage, rateIsPaid,
                                      ratePriceCode, rateRoomNumber, -1, RoomReservation);

        oSelectedRoomItem.Rates.RateItemsList.Add(rateItem);

        oSelectedRoomItem.Breakfast := TBreakfastType.FromItemIndex(cbxBreakfast.ItemIndex);
        oSelectedRoomItem.BreakfastCost := edtBreakfastPrice.Value;
      end;

      mRoomRates.next;
    end;


    // Add extras
    mExtras.First;
    while not mExtras.Eof do
    begin
      if (mExtrasRoomreservation.asInteger = RoomReservation) then
      begin
        lReservationExtra := TReservationExtra.Create(mExtrasItemid.AsInteger,
                                                      mExtrasItem.AsString,
                                                      mExtrasDescription.AsString,
                                                      mExtrasCount.AsInteger,
                                                      mExtrasPricePerItemPerDay.AsFloat,
                                                      iif(mExtrasFromdate.AsDateTime = Arrival, 0, mExtrasFromdate.AsDateTime),
                                                      iif(mExtrasTodate.AsDateTime = Departure, 0, mExtrasTodate.AsDateTime));
        oSelectedRoomItem.Extras.Add(lReservationExtra);
      end;
      mExtras.Next;
    end;


    mRoomRes.next;
  end;
end;

procedure TfrmMakeReservationQuick.btnClearLogClick(Sender: TObject);
begin
  copytoclipboard(frmdayNotes.memLog.Text);
  frmdayNotes.memLog.Clear;
  frmdayNotes.memLog.lines.Add('---' + Caption + '-----');
  frmdayNotes.memLog.lines.Add('');
end;

procedure TfrmMakeReservationQuick.sButton2Click(Sender: TObject);
begin
  frmdayNotes.FormatLog;
end;

procedure TfrmMakeReservationQuick.sButton5Click(Sender: TObject);
begin
  frmdayNotes.memLog.SelStart := 0;
end;

procedure TfrmMakeReservationQuick.sButton6Click(Sender: TObject);
begin
  frmdayNotes.memLog.Perform(EM_LINESCROLL, 0, 10)
end;

procedure TfrmMakeReservationQuick.sButton7Click(Sender: TObject);
begin
  frmdayNotes.memLog.Perform(EM_LINESCROLL, 0, -10)
end;

procedure TfrmMakeReservationQuick.cbxChannelsCloseUp(Sender: TObject);
var
  ChannelCode,
    chManCode: String;
  channelId: integer;
  FirstRound: boolean;
begin
  if cbxChannels.ItemIndex > 0 then
  begin
    channelId := integer(cbxChannels.Items.Objects[cbxChannels.ItemIndex]);
    chManCode := channelManager_GetDefaultCode;
    FirstRound := true;
    if glb.LocateSpecificRecordAndGetValue('channels', 'id', channelId, 'channelManagerId', ChannelCode) then
    begin
      FDynamicRates.Prepare(dtArrival.date, dtDeparture.date, ChannelCode, chManCode);
      PopulateRatePlanCombo(FirstRound);
    end;
  end;
  if Assigned(Sender) then
    GetPrices;
end;



// ******************************************************************************
// Page Reservation Edits
// ******************************************************************************

procedure TfrmMakeReservationQuick.dtArrivalChange(Sender: TObject);
var
  s: string;
begin
  datetimetostring(s, 'dddd', dtArrival.date);
  __lblArrivalWeekday.Caption := s;
end;

procedure TfrmMakeReservationQuick.dtArrivalCloseUp(Sender: TObject);
begin
  if dtDeparture.date <= dtArrival.date then
    dtDeparture.date := dtArrival.date + 1;
  if dtArrival.date >= dtDeparture.date then
    dtArrival.date := dtDeparture.date - 1;
  zNights := trunc(dtDeparture.date) - trunc(dtArrival.date);
  edNights.Value := zNights;
end;

procedure TfrmMakeReservationQuick.dtArrivalExit(Sender: TObject);
begin
  if dtDeparture.date <= dtArrival.date then
    dtDeparture.date := dtArrival.date + 1;
  if dtArrival.date >= dtDeparture.date then
    dtArrival.date := dtDeparture.date - 1;
  zNights := trunc(dtDeparture.date) - trunc(dtArrival.date);
  edNights.Value := zNights;
end;

/// ///////////

procedure TfrmMakeReservationQuick.dtDepartureChange(Sender: TObject);
var
  s: string;
begin
  datetimetostring(s, 'dddd', dtDeparture.date);
  __lblDepartureWeekday.Caption := s;
end;

procedure TfrmMakeReservationQuick.edNightsChange(Sender: TObject);
begin
  zNights := edNights.Value;
  dtDeparture.date := dtArrival.date + zNights;
end;

procedure TfrmMakeReservationQuick.edRoomResDiscountChange(Sender: TObject);
begin
  UpdateControls;
end;

destructor TfrmMakeReservationQuick.Destroy;
begin
  FPreviousGuestsList.Free;
  inherited;
end;

procedure TfrmMakeReservationQuick.edContactEmailChange(Sender: TObject);
begin
  chkSendConfirmation.Enabled := length(Trim(edContactEmail.Text)) > 4;
end;

procedure TfrmMakeReservationQuick.edContactPerson1PropertiesCloseUp(Sender: TObject);
var
  Key: String;
begin
  if edContactPerson1.Properties.LookupItems.IndexOf(edContactPerson1.Text) >= 0 then
  begin
    Key := TRoomerFilterItem(edContactPerson1.Properties.LookupItems.Objects[edContactPerson1.ItemIndex]).Key;
    // edContactPerson.FKeys[idx];
    if Assigned(glb.PreviousGuestsSet) AND glb.LocateSpecificRecord(glb.PreviousGuestsSet, 'ID', Key) then
    begin
      postMessage(handle, WM_SET_COMBO_TEXT, 1, 0);
    end
    else
      if glb.LocateSpecificRecord(glb.PersonProfiles, 'ID', Key) then
    begin
      if chkContactIsGuest.Checked then
      begin
        edtPortfolio.Text := Trim(glb.PersonProfiles['FirstName'] + ' ' + glb.PersonProfiles['LastName']);
        edtPortfolio.Tag := strToInt(Key);
      end;
      postMessage(handle, WM_SET_COMBO_TEXT, 2, 0);
    end;
  end;
end;

procedure TfrmMakeReservationQuick.edContactPersonEnter(Sender: TObject);
begin
  lblNew.Visible := edContactPerson1.Properties.LookupItems.Count > 0; // .active;
end;

procedure TfrmMakeReservationQuick.edContactPersonExit(Sender: TObject);
begin
  lblNew.Visible := false;
end;

procedure TfrmMakeReservationQuick.edContactPersonKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if (Key IN [vk_f2]) then
  begin
    if Assigned (edContactPerson1.Properties.OnCloseUp) then
    begin
      edContactPerson1.Properties.OnCloseUp := NIL;
      EmptyQuickFind;
      cbxAddToGuestProfiles.Enabled := true;
      lblNew.Visible := False;
    end else
    begin
      FillQuickFind;
      edContactPerson1.Properties.OnCloseUp := edContactPerson1PropertiesCloseUp;
      lblNew.Visible := edContactPerson1.Properties.LookupItems.Count > 0;
      edContactPerson1.SetFocus;
    end;
  end;
end;

procedure TfrmMakeReservationQuick.evtCustomerChangedAndValid(Sender: TObject);
begin
  initCustomer;
end;

procedure TfrmMakeReservationQuick.evtCurrencyChangedAndValid(Sender: TObject);
var
  Index: integer;
begin
  FCurrentCurrency := fraCurrencyPanel.CurrencyDefinition;
  edRoomResDiscount.CurrencyCode := FCurrentCurrency.CurrencyCode;

  index := cbxIsRoomResDiscountPrec.ItemIndex;
  cbxIsRoomResDiscountPrec.Items.Clear;
  cbxIsRoomResDiscountPrec.Items.Add('%');
  cbxIsRoomResDiscountPrec.Items.Add(FCurrentCurrency.CurrencyCode);
  cbxIsRoomResDiscountPrec.ItemIndex := index;

  if index = 0 then
    edRoomResDiscount.MaxValue := 100
  else
    edRoomResDiscount.MaxValue := 99999999;

  ActivateNextButton;
end;



/// ////////////////////////////
//

procedure TfrmMakeReservationQuick.cbxBreakfastChange(Sender: TObject);
begin
  UpdateControls;
end;

procedure TfrmMakeReservationQuick.cbxRoomStatusChange(Sender: TObject);
begin
  OutOfOrderBlocking := cbxRoomStatus.ItemIndex = 7;
end;


procedure TfrmMakeReservationQuick.UpdateRatesInRoomRes(aRoomReservation: integer; aChannelID: integer; const aRateID: string);
var
  lRateCount: integer;
  lRoomRateTotal: TAmount; // gross rate
  lRoomRentTotal: TAmount; // net rate
  lDiscountAmountTotal: TAmount;
  lAllIsSamePercentage: boolean;
  lSamePercentage: double;
  lPriceCode: string;
  lRoomRatesBm: TBookmark;
  lRoomResBm: TBookmark;
begin
  tvRoomRes.BeginUpdate;
  mRoomRes.DisableControls;
  mRoomRates.DisableControls;
  try
    lRoomRatesBm := mRoomRates.Bookmark;
    lRoomResBm := mRoomres.Bookmark;

    lAllIsSamePercentage := true;
    lSamePercentage := -1;
    lRateCount := 0;
    lRoomRateTotal := TAmount.Create(0, FCurrentCurrency.CurrencyCode);
    lRoomRentTotal := TAmount.Create(0, FCurrentCurrency.CurrencyCode);
    lDiscountAmountTotal := TAmount.Create(0, FCurrentCurrency.CurrencyCode);

    mRoomRates.First;
    if mRoomRates.Locate('Roomreservation', aRoomReservation, []) then
    begin
      lPriceCode := mRoomRatesPriceCode.AsString;
      while not mRoomRates.Eof and (mRoomRatesRoomreservation.AsInteger = aRoomReservation) do
      begin
        inc(lRateCount);

        if mRoomRatesisPercentage.AsBoolean then
          if lSamePercentage < 0 then
            lSamePercentage := mRoomRatesDiscount.AsFloat
          else
            lAllIsSamePercentage := lAllIsSamePercentage and SameValue(lSamePercentage, mRoomRatesDiscount.AsFloat)
        else
          lAllIsSamePercentage := false;

        lRoomRateTotal := lRoomRateTotal + TAmount.Create(mRoomRatesRate.AsFloat, mRoomRatesCurrency.AsString);
        lRoomRentTotal := lRoomRentTotal + TAmount.Create(mRoomRatesRentAmount.AsFloat, mRoomRatesCurrency.AsString);
        lDiscountAmountTotal := lDiscountAmountTotal + TAmount.Create(mRoomRatesDiscountAmount.AsFloat, mRoomRatesCurrency.AsString);

        mRoomRates.Next;
      end;

      if mRoomRes.Locate('Roomreservation', aRoomReservation, []) then
      begin
        mRoomRes.Edit;
        try
          mRoomResRateCount.AsInteger := lRateCount;

          mRoomResAvragePrice.AsFloat := lRoomRentTotal / lRateCount;
          mRoomResRoomRate.AsFloat := lRoomRateTotal / lRateCount;

          if (lAllIsSamePercentage and (lSamePercentage > 0)) then
          begin
            mRoomResIsPercentage.AsBoolean := true;
            mRoomResDiscount.AsFloat := lSamePercentage;
          end
          else
          begin
            mRoomResIsPercentage.AsBoolean := false;
            mRoomResDiscount.AsFloat := lDiscountAmountTotal / lRateCount;
          end;

          mRoomResAvrageDiscount.AsFloat := lDiscountAmountTotal / lRateCount;
          mRoomResPriceCode.AsString := lPriceCode;
          if aChannelid <> -1 then
            mRoomResManualChannelId.AsInteger := aChannelID;
          if not aRateid.IsEmpty then
            mRoomResratePlanCode.AsString := aRateID;
          mRoomRes.Post;
        except
          mRoomRes.Cancel;
          raise;
        end;

      end;
    end;

  finally
    mRoomRates.Bookmark := lRoomRatesBm;
    mRoomRes.Bookmark := lRoomResBm;
    mRoomRes.EnableControls;
    mRoomRates.EnableControls;
    tvRoomRes.EndUpdate;
  end;
end;

end.
