unit uAllotmentToRes;

interface

uses
  Winapi.Windows,
  Winapi.Messages,
  System.SysUtils,
  System.Variants,
  System.Classes,
  Vcl.Graphics,
  Vcl.Controls,
  Vcl.Forms,
  Vcl.Dialogs,
  Vcl.ExtCtrls,
  Vcl.ComCtrls,
  Vcl.Grids,
  Vcl.StdCtrls,
  Vcl.Buttons

    ,
  Data.DB

    ,
  AdvObj,
  BaseGrid,
  AdvGrid,
  ud,
  _glob,
  ug,
  kbmMemTable,
  cmpRoomerDataSet,
  cmpRoomerConnection,
  uUtils,
  objNewReservation,
  objRoomRates,
  hData,
  uRoomerLanguage,
  uAppGlobal

    ,
  sStatusBar,
  sPanel,
  sSplitter,
  sSpeedButton,
  sEdit,
  sPageControl,
  sLabel,
  sGroupBox

    ,
  cxGraphics,
  cxControls,
  cxLookAndFeels,
  cxLookAndFeelPainters,
  cxStyles,
  dxSkinsCore,
  dxSkinDarkSide,
  dxSkinDevExpressDarkStyle,
  dxSkinMcSkin,
  dxSkinOffice2013White,
  dxSkinsDefaultPainters,
  dxSkinscxPCPainter,
  cxCustomData,
  cxFilter,
  cxData,
  cxDataStorage,
  cxEdit,
  cxNavigator,
  cxDBData,
  cxButtonEdit,
  cxSpinEdit,
  cxTextEdit,
  cxCalc,
  cxGridLevel,
  cxGridCustomTableView,
  cxGridTableView,
  cxGridDBTableView,
  cxClasses,
  cxGridCustomView,
  cxGrid,
  sCheckBox,
  sButton,
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
  AdvUtil,
  cxCurrencyEdit;

type
  recColRow = record
    col: integer;
    row: integer;
  end;

TYPE

  TresCell = class
  private
    FrdID: integer;
    FRoomReservation: integer;
    FReservation: integer;
    FdtDate: Tdate;
    FRoom: string;
    FRoomType: string;
    FResFlag: string;
    FisNoRoom: boolean;
    FPriceCode: string;
    FRoomRate: double;
    FDiscount: double;
    FisPercentage: boolean;
    FshowDiscount: boolean;
    FPaid: boolean;
    FCurrency: string;
    FMainGuest: string;
    FnumGuests: integer;
    FnumChildren: integer;
    FnumInfants: integer;
    FRoomCount: integer;

  public
    constructor Create(rdID, RoomReservation, Reservation: integer; dtDate: Tdate; Room, RoomType, ResFlag: string;
      isNoRoom: boolean; PriceCode: string; RoomRate, Discount: double; isPercentage, showDiscount: boolean;
      Paid: boolean; Currency, MainGuest: string; numGuests, numChildren, numInfants, RoomCount: integer);
    property rdID: integer read FrdID write FrdID;
    property RoomReservation: integer read FRoomReservation write FRoomReservation;
    property Reservation: integer read FReservation write FReservation;
    property dtDate: Tdate read FdtDate write FdtDate;
    property Room: string read FRoom write FRoom;
    property RoomType: string read FRoomType write FRoomType;
    property ResFlag: string read FResFlag write FResFlag;
    property isNoRoom: boolean read FisNoRoom write FisNoRoom;
    property PriceCode: string read FPriceCode write FPriceCode;
    property RoomRate: double read FRoomRate write FRoomRate;
    property Discount: double read FDiscount write FDiscount;
    property isPercentage: boolean read FisPercentage write FisPercentage;
    property showDiscount: boolean read FshowDiscount write FshowDiscount;
    property Paid: boolean read FPaid write FPaid;
    property Currency: string read FCurrency write FCurrency;
    property MainGuest: string read FMainGuest write FMainGuest;
    property numGuests: integer read FnumGuests write FnumGuests;
    property numChildren: integer read FnumChildren write FnumChildren;
    property numInfants: integer read FnumInfants write FnumInfants;
    property RoomCount: integer read FRoomCount write FRoomCount;
  end;

TYPE

  RecRRInfoAlot = record
    rdID: integer;
    RoomReservation: integer;
    Reservation: integer;
    dtDate: Tdate;
    Room: string;
    RoomType: string;
    ResFlag: string;
    isNoRoom: boolean;
    PriceCode: string;
    RoomRate: double;
    Discount: double;
    isPercentage: boolean;
    showDiscount: boolean;
    Paid: boolean;
    Currency: string;
    MainGuest: string;
    numGuests: integer;
    numChildren: integer;
    numInfants: integer;
    RoomCount: integer;
  end;

type
  TfrmAllotmentToRes = class(TForm)
    sPanel2: TsPanel;
    panLeft: TsPanel;
    sSplitter1: TsSplitter;
    sPanel4: TsPanel;
    sPanel5: TsPanel;
    mRrInfo: TkbmMemTable;
    mRrInfoDS: TDataSource;
    mRooms: TkbmMemTable;
    sPanel1: TsPanel;
    sPanel7: TsPanel;
    sPanel8: TsPanel;
    mRoomsDS: TDataSource;
    timClose: TTimer;
    sGroupBox2: TsGroupBox;
    chkRoomCount: TsCheckBox;
    chkGuestName: TsCheckBox;
    chkPrice: TsCheckBox;
    chkNumGuests: TsCheckBox;
    kbmRoomRes: TkbmMemTable;
    mRoomResDS: TDataSource;
    kbmRoomRates: TkbmMemTable;
    kbmRoomRatesDS: TDataSource;
    mQuickResDS: TDataSource;
    mQuickRes: TkbmMemTable;
    sLabel2: TsLabel;
    btnHideShowAllotment: TsButton;
    sButton5: TsButton;
    sButton6: TsButton;
    sGroupBox3: TsGroupBox;
    cLabCountry: TsLabel;
    clabReservationName: TsLabel;
    labRefrence: TsLabel;
    labCountry: TsLabel;
    labReservationName: TsLabel;
    sLabel18: TsLabel;
    labResStatus: TsLabel;
    labPriceCode: TsLabel;
    clabRefrence: TsLabel;
    kbmrestRoomRes: TkbmMemTable;
    kbmrestRoomResDS: TDataSource;
    kbmRestRoomRatesDS: TDataSource;
    kbmRestRoomRates: TkbmMemTable;
    chkShowRoomdescription: TsCheckBox;
    chkFitColumns: TsCheckBox;
    chkIsGroupInvoice: TsCheckBox;
    sPanel3: TsPanel;
    sButton2: TsButton;
    sPanel6: TsPanel;
    sButton4: TsButton;
    sGroupBox1: TsGroupBox;
    clabFirstDate: TsLabel;
    clabLastDate: TsLabel;
    clabRoomCount: TsLabel;
    clabDayCount: TsLabel;
    labFirstDate: TsLabel;
    labLastDate: TsLabel;
    labDays: TsLabel;
    labRooms: TsLabel;
    sLabel1: TsLabel;
    labResRooms: TsLabel;
    labCurrency: TsLabel;
    sLabel3: TsLabel;
    clabCustomerName: TsLabel;
    labCustomerName: TsLabel;
    labCustomer: TsLabel;
    grRoomRes: TcxGrid;
    tvRoomRes: TcxGridDBTableView;
    tvRoomResRoom: TcxGridDBColumn;
    tvRoomResRoomDescription: TcxGridDBColumn;
    tvRoomResRoomType: TcxGridDBColumn;
    tvRoomResRoomTypeDescription: TcxGridDBColumn;
    tvRoomResArrival: TcxGridDBColumn;
    tvRoomResDeparture: TcxGridDBColumn;
    tvRoomResGuests: TcxGridDBColumn;
    tvRoomResChildrenCount: TcxGridDBColumn;
    tvRoomResinfantCount: TcxGridDBColumn;
    tvRoomResMainGuest: TcxGridDBColumn;
    tvRoomResAvragePrice: TcxGridDBColumn;
    tvRoomResRateCount: TcxGridDBColumn;
    tvRoomResRoomReservation: TcxGridDBColumn;
    tvRoomResAvrageDiscount: TcxGridDBColumn;
    tvRoomResisPercentage: TcxGridDBColumn;
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
    tvRoomRatesRentAmount: TcxGridDBColumn;
    tvRoomRatesNativeAmount: TcxGridDBColumn;
    lvRoomRes: TcxGridLevel;
    lvRoomRates: TcxGridLevel;
    grProvide: TAdvStringGrid;
    sGroupBox4: TsGroupBox;
    btnReCalc: TsButton;
    btnReclacAllPrices: TsButton;
    mRrInfordID: TIntegerField;
    mRrInfoRoomReservation: TIntegerField;
    mRrInfoReservation: TIntegerField;
    mRrInfodtDate: TDateTimeField;
    mRrInfoRoom: TStringField;
    mRrInfoRoomType: TStringField;
    mRrInfoResFlag: TStringField;
    mRrInfoisNoRoom: TBooleanField;
    mRrInfoPriceCode: TStringField;
    mRrInfoRoomRate: TFloatField;
    mRrInfoDiscount: TFloatField;
    mRrInfoisPercentage: TBooleanField;
    mRrInfoshowDiscount: TBooleanField;
    mRrInfoPaid: TBooleanField;
    mRrInfoCurrency: TStringField;
    mRrInfoMainGuest: TStringField;
    mRrInfonumChildren: TIntegerField;
    mRrInfonumInfants: TIntegerField;
    mRrInfonumGuests: TIntegerField;
    mRrInfoRoomDescription: TStringField;
    mRrInfoRoomtypeDescription: TStringField;
    mRrInfoRoomCount: TIntegerField;
    mRrInfoCol: TIntegerField;
    mRrInfoRow: TIntegerField;
    mRrInfoid: TAutoIncField;
    mRrInfoProcessed: TIntegerField;
    mRrInfoGroupAccount: TBooleanField;
    kbmRoomResRoomReservation: TIntegerField;
    kbmRoomResRoom: TStringField;
    kbmRoomResRoomType: TStringField;
    kbmRoomResGuests: TIntegerField;
    kbmRoomResAvragePrice: TFloatField;
    kbmRoomResRateCount: TIntegerField;
    kbmRoomResRoomDescription: TStringField;
    kbmRoomResRoomTypeDescription: TStringField;
    kbmRoomResArrival: TDateTimeField;
    kbmRoomResDeparture: TDateTimeField;
    kbmRoomResChildrenCount: TIntegerField;
    kbmRoomResinfantCount: TIntegerField;
    kbmRoomResPriceCode: TStringField;
    kbmRoomResAvrageDiscount: TFloatField;
    kbmRoomResisPercentage: TBooleanField;
    kbmRoomResMainGuest: TStringField;
    kbmRoomRatesReservation: TIntegerField;
    kbmRoomRatesRoomReservation: TIntegerField;
    kbmRoomRatesRoomNumber: TStringField;
    kbmRoomRatesRateDate: TDateTimeField;
    kbmRoomRatesPriceCode: TStringField;
    kbmRoomRatesRate: TFloatField;
    kbmRoomRatesDiscount: TFloatField;
    kbmRoomRatesisPercentage: TBooleanField;
    kbmRoomRatesShowDiscount: TBooleanField;
    kbmRoomRatesisPaid: TBooleanField;
    kbmRoomRatesDiscountAmount: TFloatField;
    kbmRoomRatesRentAmount: TFloatField;
    kbmRoomRatesNativeAmount: TFloatField;
    kbmrestRoomResRoomReservation: TIntegerField;
    kbmrestRoomResRoom: TStringField;
    kbmrestRoomResRoomType: TStringField;
    kbmrestRoomResGuests: TIntegerField;
    kbmrestRoomResAvragePrice: TFloatField;
    kbmrestRoomResRateCount: TIntegerField;
    kbmrestRoomResRoomDescription: TStringField;
    kbmrestRoomResRoomTypeDescription: TStringField;
    kbmrestRoomResArrival: TDateTimeField;
    kbmrestRoomResDeparture: TDateTimeField;
    kbmrestRoomResChildrenCount: TIntegerField;
    kbmrestRoomResinfantCount: TIntegerField;
    kbmrestRoomResPriceCode: TStringField;
    kbmrestRoomResAvrageDiscount: TFloatField;
    kbmrestRoomResisPercentage: TBooleanField;
    kbmrestRoomResMainGuest: TStringField;
    mRoomsRoom: TStringField;
    mRoomsRoomType: TStringField;
    mRoomsRoomDescription: TStringField;
    mRoomsotherInfo: TStringField;
    kbmRestRoomRatesReservation: TIntegerField;
    kbmRestRoomRatesRoomReservation: TIntegerField;
    kbmRestRoomRatesRoomNumber: TStringField;
    kbmRestRoomRatesRateDate: TDateTimeField;
    kbmRestRoomRatesPriceCode: TStringField;
    kbmRestRoomRatesRate: TFloatField;
    kbmRestRoomRatesDiscount: TFloatField;
    kbmRestRoomRatesisPercentage: TBooleanField;
    kbmRestRoomRatesShowDiscount: TBooleanField;
    kbmRestRoomRatesisPaid: TBooleanField;
    kbmRestRoomRatesDiscountAmount: TFloatField;
    kbmRestRoomRatesRentAmount: TFloatField;
    kbmRestRoomRatesNativeAmount: TFloatField;
    mQuickResRow: TIntegerField;
    mQuickResFirstCol: TIntegerField;
    mQuickResLastCol: TIntegerField;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure chkShowRoomdescriptionClick(Sender: TObject);
    procedure grProvideGetCellColor(Sender: TObject; ARow, ACol: integer; AState: TGridDrawState; ABrush: TBrush;
      AFont: TFont);
    procedure timCloseTimer(Sender: TObject);

    procedure sPanel7DblClick(Sender: TObject);
    procedure sButton4Click(Sender: TObject);
    function updateCellInfo(ACol, ARow: integer; newRR: integer): boolean;
    procedure chkFitColumnsClick(Sender: TObject);
    procedure btnHideShowAllotmentClick(Sender: TObject);
    procedure sButton5Click(Sender: TObject);
    procedure sButton2Click(Sender: TObject);
    procedure btnReCalcClick(Sender: TObject);
    procedure btnReclacAllPricesClick(Sender: TObject);
    procedure tvRoomResGetCurrencyProperties(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AProperties: TcxCustomEditProperties);
    procedure chkRoomCountClick(Sender: TObject);
    procedure chkNumGuestsClick(Sender: TObject);
    procedure chkPriceClick(Sender: TObject);
    procedure chkGuestNameClick(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
    procedure mRoomResDSDataChange(Sender: TObject; Field: TField);
    procedure grProvideSelectionChanged(Sender: TObject; ALeft, ATop, ARight, ABottom: Integer);
    procedure sPanel8DblClick(Sender: TObject);
    procedure tvRoomResRoomGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
      var AText: string);
    procedure grProvideDblClickCell(Sender: TObject; ARow, ACol: Integer);

  private
    { Private declarations }
    zFirstDate: Tdate;
    zNightCount: integer;

    zRoomCount: integer;

    zRows: integer;
    zCols: integer;
    zResFlag: string;

    zCountRoomTypes: integer;
    zShowRoomDescription: boolean;

    zReservationInfo: recReservationHolder;
    zAllotmentIsGroupInvoice: boolean;
    FShowDate: TDateTime;

    // Last number used as a fake (negative) roomreservation number
    FLastFakeRRNumber: integer;

    function GetNextFakeRRID: integer;
    procedure GetRrData(Reservation: integer);

    // Fill grid grProvide
    procedure FillgrProvideWithRooms;
    procedure SetDateHeads;
    procedure InitCell(c, r: integer);
    function SetCell(rrInfo: RecRRInfoAlot; col, row: integer; setText: boolean): recColRow;
    function DateToCol(aDate: Tdate): integer;
    function RoomAndDateToCell(Room, RoomType: string; aDate: Tdate): recColRow;
    function RoomAndTypeToRow(Room, RoomType: string): integer;

    function InitRRInfo: RecRRInfoAlot;
    function ColToDate(ACol: integer): TdateTime;

    function GetResStatus(ACol, ARow: integer; var status: string): boolean;
    procedure FillData;
    procedure InitAll;

    function isValidAllotment(Reservation: integer): boolean;
    function GetResInfo(ACol: integer = -1; ARow: integer = -1): RecRRInfoAlot;
    function AddRoomReservation(RoomReservation: integer): boolean;
    function Apply: boolean;
    function AddRestRoomReservation(FakeRoomReservation: integer): boolean;
    function RoomsInAllotment: integer;
    function CalcOnePrice(RoomReservation: integer; NewRate: double = 0): boolean;
    procedure ReclacAllPrices;
    procedure FreeGridObjects;
    function SetRoomResProcessed(ACol, ARow, newRR: integer): boolean;
    procedure NavigateToDate(aDate: TDate);
    procedure UpdateControls;
    procedure CreateRestAllotmentRoomreservations;
    procedure CreateRoomReservationFromSelectedAllotments;
    function HasAdjacentRoomReservation(aCol, aRow: integer; var aRoomreservation: integer): boolean;

  public
    { Public declarations }
    zReservation: integer;
    zRestCount: integer;
    oNewReservation: TNewReservation;
    oRestReservation: TNewReservation;
    property ShowDate: TDateTime read FShowDate write FShowDate;
  end;

  function OpenProvideAllotment(aAllotReservation: integer; var oNewReservation, oRestReservation: TNewReservation; var restCount: integer; aShowDate: TDateTime = 0): boolean;


implementation

{$R *.dfm}

uses
  uDImages,
  uMain,
  PrjConst,
  uRoomerDefinitions,
  uReservationStateDefinitions,
  Math,
  uSQLUtils,
  DateUtils
  , Generics.Collections
  ;

const
  cCountFixedRows = 2;
  cCountEmptyRows = 1;

  cCountFixedCols = 4;
  cCountEmptyCols = 0;

  cColRoom = 0;
  cColRoomType = 1;
  cColRoomDescription = 2;
  cColInfo = 3;

  // Value of MRrInfoProcessed for items that are not converted to roomreservations
  // Processed items have a fake, negative roomreservationr
  cUnProcessed = 0;

{ TfrmAllotmentToRes }

function OpenProvideAllotment(aAllotReservation: integer; var oNewReservation, oRestReservation: TNewReservation; var restCount: integer; aShowDate: TDateTime = 0): boolean;
var
  frm: TfrmAllotmentToRes;
begin
  result := false;
  frm := TfrmAllotmentToRes.Create(nil);
  try
    frm.zReservation := aAllotReservation;
    frm.zRestCount := restCount;
    frm.oNewReservation := oNewReservation;
    frm.oRestReservation := oRestReservation;
    frm.Showdate := aShowDate;
    if frm.ShowModal = mrOK then
    begin
      oNewReservation := frm.oNewReservation;
      oRestReservation := frm.oRestReservation;
      restCount := frm.zRestCount;
      result := true;
    end;
  finally
    frm.Free;
  end;
end;



function HexToTColor(sColor: string): TColor;
begin
  result := RGB(strToint('$' + copy(sColor, 1, 2)), strToint('$' + copy(sColor, 3, 2)),
    strToint('$' + copy(sColor, 5, 2)));
end;

constructor TresCell.Create(rdID, RoomReservation, Reservation: integer; dtDate: Tdate; Room, RoomType, ResFlag: string;
  isNoRoom: boolean; PriceCode: string; RoomRate, Discount: double; isPercentage, showDiscount: boolean; Paid: boolean;
  Currency, MainGuest: string; numGuests, numChildren, numInfants, RoomCount: integer);

begin
  inherited Create;
  FrdID := rdID;
  FRoomReservation := RoomReservation;
  FReservation := Reservation;
  FdtDate := dtDate;
  FRoom := Room;
  FRoomType := RoomType;
  FResFlag := ResFlag;
  FisNoRoom := isNoRoom;
  FPriceCode := PriceCode;
  FRoomRate := RoomRate;
  FDiscount := Discount;
  FisPercentage := isPercentage;
  FshowDiscount := showDiscount;
  FPaid := Paid;
  FCurrency := Currency;
  FMainGuest := MainGuest;
  FnumGuests := numGuests;
  FnumChildren := numChildren;
  FnumInfants := numInfants;
  FRoomCount := RoomCount;
end;

function TfrmAllotmentToRes.ColToDate(ACol: integer): TdateTime;
begin
  result := zFirstDate + (ACol - (cCountFixedCols));
end;

function TfrmAllotmentToRes.DateToCol(aDate: Tdate): integer;
begin
  result := (trunc(aDate) - trunc(zFirstDate)) + cCountFixedCols;
end;

function TfrmAllotmentToRes.RoomAndTypeToRow(Room, RoomType: string): integer;
var
  i: integer;
begin
  result := 0;
  for i := cCountFixedRows to grProvide.RowCount - (cCountFixedRows) do
  begin
    if Sametext(Room, grProvide.Cells[0, i]) and Sametext(RoomType, grProvide.Cells[1, i]) then
    begin
      result := i;
      break;
    end;
  end;
end;

procedure TfrmAllotmentToRes.sButton2Click(Sender: TObject);
var
  RoomReservation: integer;
begin
  if kbmRoomRes.RecordCount = 0 then
    exit;

  kbmRoomRes.DisableControls;
  mRrInfo.DisableControls;
  kbmRoomRates.DisableControls;
  try
    RoomReservation := kbmRoomResRoomReservation.Asinteger;
    try
      mRrInfo.First;
      while not mRrInfo.eof do
      begin
        if mRrInfoProcessed.Asinteger = RoomReservation then
        begin
          mRrInfo.Edit;
          mRrInfoProcessed.Asinteger := cUnProcessed;
          mRrInfo.Post;
        end;
        mRrInfo.Next;
      end;
    finally
      // mRRinfo.Filtered := false;
    end;
    kbmRoomRes.Delete;
    kbmRoomRates.Filter := '(Roomreservation=' + inttostr(RoomReservation) + ')';
    kbmRoomRates.Filtered := true;
    try
      kbmRoomRates.First;
      while not kbmRoomRates.eof do
      begin
        kbmRoomRates.Delete;
        kbmRoomRates.Next;
      end;
    finally
      kbmRoomRates.Filtered := false;
    end;
  finally
    kbmRoomRes.EnableControls;
    mRrInfo.EnableControls;
    kbmRoomRates.EnableControls;
  end;
  FillData;
  zRestCount := RoomsInAllotment;
end;

procedure TfrmAllotmentToRes.btnHideShowAllotmentClick(Sender: TObject);
begin
  panLeft.Visible := not panLeft.Visible;
  if panLeft.Visible then
  begin
    btnHideShowAllotment.Caption := 'Hide Allotment';
  end
  else
  begin
    btnHideShowAllotment.Caption := 'Show Allotment';
  end;
end;

procedure TfrmAllotmentToRes.sButton4Click(Sender: TObject);
begin
  CreateRoomReservationFromSelectedAllotments; //GetRooms;
  zRestCount := RoomsInAllotment;
end;

procedure TfrmAllotmentToRes.sButton5Click(Sender: TObject);
begin
  if kbmRoomRes.RecordCount > 0 then
  begin
    Apply;
    oNewReservation.ShowProfile := true;
  end
  else
    oNewReservation.ShowProfile := false;
end;

procedure TfrmAllotmentToRes.chkFitColumnsClick(Sender: TObject);
begin
  if (Sender as TsCheckBox).Checked then
  begin
    grProvide.AutoFitColumns(false);
  end
  else
  begin
    grProvide.AutoSizeColumns(false, 2);
  end;
end;

procedure TfrmAllotmentToRes.chkGuestNameClick(Sender: TObject);
begin
  FillData;
end;

procedure TfrmAllotmentToRes.chkNumGuestsClick(Sender: TObject);
begin
  FillData;
end;

procedure TfrmAllotmentToRes.chkPriceClick(Sender: TObject);
begin
  FillData;
end;

procedure TfrmAllotmentToRes.chkRoomCountClick(Sender: TObject);
begin
  FillData;
end;

function TfrmAllotmentToRes.isValidAllotment(Reservation: integer): boolean;
var
  s: string;
  sql: string;

  rset1, rset2, rset3: TRoomerDataset;
  ExecutionPlan: TRoomerExecutionPlan;
begin
  result := true;
  ExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    // **zxhj

    s := '';
    s := s + ' SELECT DISTINCT '#10;
    s := s + '    rd.resFlag '#10;
    s := s + ' FROM '#10;
    s := s + '   roomsdate rd '#10;
    s := s + ' WHERE '#10;
    s := s + '  (rd.Reservation = %d ) '#10;
    s := s + '   AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '; // **zxhj b�tt vi�

    sql := format(s, [Reservation]);
    // copyToClipBoard(sql);
    // Debugmessage(sql);
    ExecutionPlan.AddQuery(sql); // 0

    s := '';
    s := s + ' SELECT DISTINCT '#10;
    s := s + '    rd.resFlag '#10;
    s := s + ' FROM '#10;
    s := s + '   roomsdate rd '#10;
    s := s + ' WHERE '#10;
    s := s + '   (rd.resFlag not in (' + _db('A') + ',' + _db('P') + ',' + _db('X') + ',' + _db('O') + ',' + _db('L') +
      ')) '#10; // **zxhj breytti
    s := s + '   AND (rd.Reservation = %d ) '#10;
    s := s + ' LIMIT 1 '#10;

    sql := format(s, [Reservation]);
    // copyToClipBoard(sql);
    // Debugmessage(sql);
    ExecutionPlan.AddQuery(sql); // 0

    s := '';
    s := s + ' SELECT '#10;
    s := s + '   paid '#10;
    s := s + ' FROM '#10;
    s := s + '   roomsdate rd '#10;
    s := s + ' WHERE '#10;
    s := s + '   (paid=1) and (rd.Reservation = %d ) '#10;
    s := s + '   AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '; // **zxhj line added
    s := s + ' LIMIT 1 '#10;

    sql := format(s, [Reservation]);
    // copyToClipBoard(sql);
    // Debugmessage(sql);
    ExecutionPlan.AddQuery(sql); // 0

    screen.Cursor := crHourglass;
    try
      ExecutionPlan.Execute(ptQuery);

      zResFlag := '';
      rset1 := ExecutionPlan.Results[0];
      if rset1.RecordCount > 1 then
      begin
        result := false;
      end
      else
      begin
        zResFlag := rset1.FieldByName('ResFlag').AsString;
        labResStatus.Caption := zResFlag;
      end;

      rset2 := ExecutionPlan.Results[1];
      if rset2.RecordCount > 0 then
      begin
        result := false;
      end;

      rset3 := ExecutionPlan.Results[2];
      if rset3.RecordCount > 0 then
      begin
        result := false;
      end;

    finally
      screen.Cursor := crDefault;
    end;
  finally
    ExecutionPlan.Free;
  end;
end;

procedure TfrmAllotmentToRes.mRoomResDSDataChange(Sender: TObject; Field: TField);
begin
  UpdateControls;
end;

procedure TfrmAllotmentToRes.UpdateControls;
begin
  sButton5.Enabled := kbmRoomRes.Active and (kbmRoomRes.RecordCount > 0);
  sButton2.Enabled := sButton5.Enabled;
  sButton4.Enabled := grProvide.SelectedCellsCount > 0;
end;

function TfrmAllotmentToRes.RoomAndDateToCell(Room, RoomType: string; aDate: Tdate): recColRow;
begin
  result.col := DateToCol(aDate);
  result.row := RoomAndTypeToRow(Room, RoomType);
end;

procedure TfrmAllotmentToRes.InitCell(c, r: integer);
var
  rrInfo: RecRRInfoAlot;
begin
  if grProvide.Objects[c, r] <> nil then
  begin
    grProvide.Objects[c, r].Free;
    grProvide.Objects[c, r] := nil;
  end;
  grProvide.Cells[c, r] := '';
  rrInfo := InitRRInfo;

  grProvide.Objects[c, r] := TresCell.Create(rrInfo.rdID, rrInfo.RoomReservation, rrInfo.Reservation, rrInfo.dtDate,
    rrInfo.Room, rrInfo.RoomType, rrInfo.ResFlag, rrInfo.isNoRoom, rrInfo.PriceCode, rrInfo.RoomRate, rrInfo.Discount,
    rrInfo.isPercentage, rrInfo.showDiscount, rrInfo.Paid, rrInfo.Currency, rrInfo.MainGuest, rrInfo.numGuests,
    rrInfo.numChildren, rrInfo.numInfants, rrInfo.RoomCount);
end;

Function TfrmAllotmentToRes.InitRRInfo: RecRRInfoAlot;
begin
  result.rdID := -1;
  result.RoomReservation := 0;
  result.Reservation := 0;
  result.dtDate := 1;
  result.Room := '';
  result.RoomType := '';
  result.ResFlag := '';
  result.isNoRoom := false;
  result.PriceCode := '';
  result.RoomRate := 0.00;
  result.Discount := 0.00;
  result.isPercentage := false;
  result.showDiscount := false;
  result.Paid := false;
  result.Currency := '';
  result.MainGuest := '';
  result.numGuests := 0;
  result.numChildren := 0;
  result.numInfants := 0;
  result.RoomCount := 0;
end;

function TfrmAllotmentToRes.SetCell(rrInfo: RecRRInfoAlot; col, row: integer; setText: boolean): recColRow;
var
  rcRec: recColRow;
  s, ss: string;

  RoomCount: integer;

begin
  RoomCount := 0;
  rcRec := RoomAndDateToCell(rrInfo.Room, rrInfo.RoomType, rrInfo.dtDate);

  if col <> -1 then
    rcRec.col := col;
  if row <> -1 then
    rcRec.row := row;

  if grProvide.Objects[rcRec.col, rcRec.row] <> nil then
  begin
    RoomCount := GetResInfo(col, row).RoomCount;
    RoomCount := RoomCount + 1;
    grProvide.Objects[rcRec.col, rcRec.row].Free;
    grProvide.Objects[rcRec.col, rcRec.row] := nil;
  end;

  if RoomCount > 0 then
  begin
    if setText then
    begin
      s := '';
      if chkRoomCount.Checked then
        s := s + '[' + inttostr(RoomCount) + ']';
      if chkNumGuests.Checked then
        s := s + '[' + inttostr(rrInfo.numGuests) + ']';
      if chkGuestName.Checked then
        s := s + ' ' + rrInfo.MainGuest;
      if chkPrice.Checked then
      begin
        ss := '%';
        if rrInfo.isPercentage = false then
          ss := ' ' + rrInfo.Currency;
        s := s + ' ' + FloatTostr(rrInfo.RoomRate) + rrInfo.Currency + '-' + FloatTostr(rrInfo.Discount) + ss;
      end;
      grProvide.Cells[rcRec.col, rcRec.row] := s;
    end;
    grProvide.Objects[rcRec.col, rcRec.row] := TresCell.Create(rrInfo.rdID, rrInfo.RoomReservation, rrInfo.Reservation,
      rrInfo.dtDate, rrInfo.Room, rrInfo.RoomType, rrInfo.ResFlag, rrInfo.isNoRoom, rrInfo.PriceCode, rrInfo.RoomRate,
      rrInfo.Discount, rrInfo.isPercentage, rrInfo.showDiscount, rrInfo.Paid, rrInfo.Currency, rrInfo.MainGuest,
      rrInfo.numGuests, rrInfo.numChildren, rrInfo.numInfants, RoomCount);

  end
  else
  begin
    InitCell(col, row);
  end;
  result := rcRec;
end;

procedure TfrmAllotmentToRes.InitAll;
var
  i, ii: integer;
begin
  for i := cCountFixedCols to grProvide.ColCount - 1 do
    for ii := cCountFixedRows to grProvide.RowCount - 1 do
    begin
      InitCell(i, ii);
    end;
end;

procedure TfrmAllotmentToRes.FillData;
var
  rrInfo: RecRRInfoAlot;
  rcRec: recColRow;
  col, row: integer;
  processed: integer;
begin
  InitAll;

  mRrInfo.DisableControls;
  screen.Cursor := crHourglass;
  try
    mRrInfo.First;
    while not mRrInfo.eof do
    begin
      col := mRrInfoCol.Asinteger;
      row := mRrInfoRow.Asinteger;
      processed := mRrInfoProcessed.Asinteger;

      if processed = cUnProcessed then
      begin
        rrInfo := InitRRInfo;
        rrInfo.rdID := mRrInfordID.Asinteger;
        rrInfo.RoomReservation := mRrInfoRoomReservation.Asinteger;
        rrInfo.Reservation := mRrInfoReservation.Asinteger;
        rrInfo.dtDate := mRrInfodtDate.AsDateTime;
        rrInfo.Room := mRrInfoRoom.AsString;
        rrInfo.RoomType := mRrInfoRoomType.AsString;
        rrInfo.ResFlag := mRrInfoResFlag.AsString;
        rrInfo.isNoRoom := mRrInfoisNoRoom.AsBoolean;
        rrInfo.PriceCode := mRrInfoPriceCode.AsString;
        rrInfo.RoomRate := mRrInfoRoomRate.AsFloat;
        rrInfo.Discount := mRrInfoDiscount.AsFloat;
        rrInfo.isPercentage := mRrInfoisPercentage.AsBoolean;
        rrInfo.showDiscount := mRrInfoshowDiscount.AsBoolean;
        rrInfo.Paid := mRrInfoPaid.AsBoolean;
        rrInfo.Currency := mRrInfoCurrency.AsString;
        rrInfo.MainGuest := mRrInfoMainGuest.AsString;
        rrInfo.numGuests := mRrInfonumGuests.Asinteger;
        rrInfo.numChildren := mRrInfonumChildren.Asinteger;
        rrInfo.numInfants := mRrInfonumInfants.Asinteger;
        rrInfo.RoomCount := mRrInfoRoomCount.Asinteger;
        rcRec := SetCell(rrInfo, col, row, true);
      end;
      mRrInfo.Next;
    end;
  finally
    mRrInfo.EnableControls;
    screen.Cursor := crDefault;
  end;
end;

procedure TfrmAllotmentToRes.FormCreate(Sender: TObject);
begin
  RoomerLanguage.TranslateThisForm(self);
  glb.PerformAuthenticationAssertion(self);
  PlaceFormOnVisibleMonitor(self);
  // **
  zReservation := 0;
  zFirstDate := 2;
  zNightCount := 0;

  FLastFakeRRNumber := -1;
end;

procedure TfrmAllotmentToRes.FormDestroy(Sender: TObject);
begin
  FreeGridObjects;
  // **
end;

procedure TfrmAllotmentToRes.FormKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
begin
  if Key = VK_ESCAPE then
    Close;
end;

procedure TfrmAllotmentToRes.FreeGridObjects;
var
  r, c: integer;
begin
  for r := grProvide.FixedRows to grProvide.RowCount - 1 do
    for c := grProvide.FixedCols to grProvide.ColCount - 1 do
      if Assigned(grProvide.Objects[c, r]) then
        grProvide.Objects[c, r].Free;
end;

procedure TfrmAllotmentToRes.FormShow(Sender: TObject);
begin
  if isValidAllotment(zReservation) then
  begin
    zShowRoomDescription := chkShowRoomdescription.Checked;
    GetRrData(zReservation);
    zReservationInfo := SP_GET_Reservation(zReservation);
    NavigateToDate(ShowDate);
    UpdateControls;
  end
  else
  begin
    showmessage(GetTranslatedText('shTx_AllotmentToRes_InvalidAllotment'));
    timClose.Enabled := true;
  end;
end;

procedure TfrmAllotmentToRes.NavigateToDate(aDate: TDate);
var
  lOffset: integer;
begin
  lOffset := Trunc(aDate) - trunc(zFirstDate);
  if lOffset > 0 then
    grProvide.ScrollInView(cCountFixedCols + lOffSet, 0, spLeading);
  grProvide.Col := cCountFixedCols + lOffSet;
  grProvide.Row := 1;
end;

// -End Form Actions ---------------------------------------------------------

procedure TfrmAllotmentToRes.chkShowRoomdescriptionClick(Sender: TObject);
begin
  zShowRoomDescription := chkShowRoomdescription.Checked;
  FillgrProvideWithRooms;
end;

procedure TfrmAllotmentToRes.FillgrProvideWithRooms;
var
  Room: string;
  RoomType: string;
  RoomDescription: string;

  startRow: integer;
  RowIndex: integer;
  other: string;
begin
  mRooms.First;

  startRow := grProvide.FixedRows;
  RowIndex := startRow - 1;

  while not mRooms.eof do
  begin
    inc(RowIndex);

    Room := mRoomsRoom.AsString;
    RoomType := mRoomsRoomType.AsString;
    RoomDescription := mRoomsRoomDescription.AsString;
    other := mRoomsotherInfo.AsString;

    grProvide.Cells[cColRoom, RowIndex] := Room;
    grProvide.Cells[cColRoomType, RowIndex] := RoomType;
    grProvide.Cells[cColInfo, RowIndex] := other;
    if zShowRoomDescription then
    begin
      grProvide.Cells[cColRoomDescription, RowIndex] := RoomDescription;
    end
    else
    begin
      grProvide.Cells[cColRoomDescription, RowIndex] := '';
    end;
    mRooms.Next;
  end;

  grProvide.AutoSizeCol(0, 1);
  grProvide.AutoSizeCol(1, 1);
  grProvide.AutoSizeCol(2, 1);
  grProvide.ColWidths[3] := 1;
  grProvide.AutoSizeRows(true);
  grProvide.RowHeights[0] := grProvide.RowHeights[1];
end;

procedure TfrmAllotmentToRes.SetDateHeads;
var
  dayStartCol: integer;
  i: integer;
  aDate: Tdate;
  s: string;
begin
  dayStartCol := cCountFixedCols - 1;
  aDate := zFirstDate;
  for i := 1 to zNightCount + cCountFixedCols do
  begin
    dateTimeToString(s, g.qPeriodDateformat2, aDate);
    grProvide.Cells[i + dayStartCol, 1] := s;
    dateTimeToString(s, g.qPeriodDateformat1, aDate);
    grProvide.Cells[i + dayStartCol, 0] := s;
    aDate := aDate + 1;
  end;
end;

procedure TfrmAllotmentToRes.sPanel7DblClick(Sender: TObject);
begin
  sPanel4.width := width - 40;
end;

procedure TfrmAllotmentToRes.sPanel8DblClick(Sender: TObject);
begin
  sPanel4.Width := 40;
end;

procedure TfrmAllotmentToRes.timCloseTimer(Sender: TObject);
begin
  timClose.Enabled := false;
  close;
end;

procedure TfrmAllotmentToRes.tvRoomResGetCurrencyProperties(Sender: TcxCustomGridTableItem;
  ARecord: TcxCustomGridRecord; var AProperties: TcxCustomEditProperties);
begin
  d.getCurrencyProperties(g.qNativeCurrency);
end;

procedure TfrmAllotmentToRes.tvRoomResRoomGetDisplayText(Sender: TcxCustomGridTableItem; ARecord: TcxCustomGridRecord;
  var AText: string);
begin
  if aText.StartsWith('<') then
    aText := '';
end;

function TfrmAllotmentToRes.GetResStatus(ACol, ARow: integer; var status: string): boolean;
begin
  result := false;
  if grProvide.Objects[ACol, ARow] <> nil then
  begin
    status := (grProvide.Objects[ACol, ARow] as TresCell).ResFlag;
    status := Uppercase(status);
    result := true;
  end;
end;

procedure TfrmAllotmentToRes.grProvideDblClickCell(Sender: TObject; ARow, ACol: Integer);
begin
  sButton4.Click;
end;

procedure TfrmAllotmentToRes.grProvideGetCellColor(Sender: TObject; ARow, ACol: integer; AState: TGridDrawState;
  ABrush: TBrush; AFont: TFont);
var
  colDate: Tdate;
  weekDay: integer;
  status: string;
  BColor, FColor: TColor;

begin
  colDate := ColToDate(ACol);
  weekDay := dayOfWeek(colDate);
  ABrush.color := frmMain.sSkinManager1.GetActiveEditColor;
  AFont.color := frmMain.sSkinManager1.GetActiveEditFontColor;
  AFont.Style := [];

  if (ARow > cCountFixedRows - 1) and (ACol > cCountFixedCols - 1) then
  begin
    if weekDay = 1 then
    begin
      ABrush.color := HexToTColor('FFC2C2');
    end;

    if weekDay = 7 then
    begin
      ABrush.color := HexToTColor('FFDCDC');
    end;

    GetResStatus(ACol, ARow, status);
    if ResStatusToColor(status, BColor, FColor) then
    begin
      ABrush.color := BColor;
      AFont.color := FColor;
    end;

  end;
end;

procedure TfrmAllotmentToRes.grProvideSelectionChanged(Sender: TObject; ALeft, ATop, ARight, ABottom: Integer);
begin
  UpdateControls;
end;


function TfrmAllotmentToRes.HasAdjacentRoomReservation(aCol, aRow: integer; var aRoomreservation: integer): boolean;
var
  lDate: TDate;
begin
  // Determine if new roomres already exist with same room and roomtype directly adjacent to this date,
  // If so then use that roomreservation number
  lDate := ColToDate(aCol);

  kbmRoomres.IndexFieldNames := 'room;roomtype';
  kbmRoomRes.First;
  Result := false;
  while not kbmRoomRes.Eof do
  begin
    Result := (kbmRoomResRoom.AsString.StartsWith('<') or
          (kbmRoomResRoom.AsString = grProvide.Cells[cColRoom, aRow]))
          and (kbmRoomResRoomType.AsString = grProvide.Cells[cColRoomType, aRow])
          and ((kbmRoomResArrival.AsDateTime = lDate+1) or (kbmRoomResDeparture.AsDateTime = lDate));
    if Result then
    begin
      aRoomReservation := kbmRoomResRoomReservation.AsInteger;
      Break;
    end;
    kbmRoomRes.Next;
  end;

end;

procedure TfrmAllotmentToRes.CreateRoomReservationFromSelectedAllotments;
var
  r, c, i: integer;
  lNewRR: integer;
  lNewRRList: TList<integer>;
  lAdjRR: integer;
begin
  lNewRRList := TList<integer>.Create;
  grProvide.BeginUpdate;
  try
    if grProvide.SelectedCellsCount > 0 then
    begin
      for r := grProvide.FixedRows to grProvide.RowCount-1 do
      begin
        if grProvide.Cells[cColRoomType, r] = '' then
          Continue;

        lnewRR := GetNextFakeRRID; // RR_SetNewID;
        for c := grProvide.FixedCols to grProvide.ColCount -1 do
        begin
          if not grProvide.SelectedCells[c, r] or not Assigned(grProvide.Objects[c, r]) or not (grProvide.Objects[c, r] is TResCell)
            or ((grProvide.Objects[c, r] as TResCell).RoomCount = 0) then
          begin
            // SKip unselected cells and cells with no availability, always starts a new RR
            lnewRR := GetNextFakeRRID;
            Continue;
          end;

          if HasAdjacentRoomReservation(c, r, lAdjRR) then
          begin
            SetRoomResProcessed(c, r, lAdjRR);
            if not lNewRRList.Contains(lAdjRR) then
              lNewRRList.Add(lAdjRR);
          end
          else
          begin
            SetRoomResProcessed(c, r, lNewRR);
            if not lNewRRList.Contains(lNewRR) then
              lNewRRList.Add(lNewRR);
          end;

        end; // for c
      end;

      for i in lNewRRList do
        AddRoomReservation(i);

      FillData;
    end;

  finally
    grProvide.EndUpdate;
    lNewRRList.Free;
  end;
end;

procedure TfrmAllotmentToRes.CreateRestAllotmentRoomreservations;
var
  lCurRoom: string;
  lCurRoomType: string;
  lLastDate: TDate;
  lRRId: integer;
  lNewRRList: TList<integer>;
  i: integer;
begin

  mRrInfo.DisableControls;
  lNewRRList := TList<integer>.Create;
  try
    mRrInfo.IndexFieldNames := 'Room;Roomtype;Roomreservation;dtDate';

    lCurRoom := '';
    lCurRoomType := '';
    mRrInfo.First;
    lRRId := 0;

    lLastDate := 0;
    // Walk through all Allotment RR records that are not assigned to a new reservation and assign them a new
    // fake roomreservation number (in Processed field) as long as they are the same room and roomtype and have consecutive dates
    while not mRrInfo.Eof do
    begin
      if mRrInfoProcessed.AsInteger = cUnProcessed then
      begin
        if (lCurRoom <> mRrInfoRoom.asString) or (lCurRoomType <> mRrInfoRoomType.AsString) or
           (lLastDate + 1 <> mRrInfodtDate.AsDateTime) then
        begin
          if lRRId <> 0 then
            lNewRRList.add(lRRId);

          lRRId := GetNextFakeRRID; // RR_SetNewID;
          lCurRoom := mRrInfoRoom.asString;
          lCurRoomType := mRrInfoRoomType.asString;
        end;

        mRrInfo.Edit;
        mRrInfoProcessed.AsInteger := lRRId;
        mRrInfo.Post;
        lLastDate := mRrInfodtDate.AsDateTime;
      end;

      mRrInfo.Next;
    end;

    if lRRId <> 0 then
      lNewRRList.add(lRRId);

    for i in lNewRRList do
      AddRestRoomReservation(i);

  finally
    lNewRRList.Free;
    mRrInfo.EnableControls;
  end;

end;

function TfrmAllotmentToRes.AddRoomReservation(RoomReservation: integer): boolean;
var
  Room: string; // *
  RoomType: string; // *
  Guests: integer; //
  AvragePrice: double; //
  RateCount: integer; //
  RoomDescription: String;
  RoomTypeDescription: string;
  Arrival: Tdate; // *
  Departure: Tdate; // *
  ChildrenCount: integer; //
  InfantCount: integer; //
  PriceCode: String; // *
  AvrageDiscount: double; //
  isPercentage: boolean; // *
  MainGuest: string; // *

  ttPrice: double;
  ttDiscount: double;
  ttPriceCount: integer;
  ttNetPrice: double;
  AvrageNetPrice: double; //

  sFilter: string;
  tmpArrival: Tdate;
  tmpDeparture: Tdate;

  RoomRate: double;
  Discount: double;

  lstPrices: Tstringlist;

  DiscountAmount: double;
  RentAmount: double;
  NativeAmount: double;

  currencyRate: double;
  Currency: string;
  oSelectedRoomItem: TnewRoomReservationItem;

  procedure lclDeleteRoomResFromDataset(aRoomRes: integer; aRoomresField: TField);
  begin
    with aRoomresField.DataSet do
    begin
      First;
      while not eof do
      begin
        if (aRoomresField.Asinteger = aRoomRes) then
          Delete
        else
          Next;
      end;
    end;
  end;

begin

  result := false;

  lstPrices := Tstringlist.Create;
  try
    lstPrices.Sorted := true;
    lstPrices.Duplicates := dupIgnore;

    screen.Cursor := crHourglass;
    mRrInfo.DisableControls;
    kbmRoomRes.DisableControls;
    kbmRoomRates.DisableControls;
    try
      // If Roomres already exists, delete all prior info from roomres and roomrates
      lclDeleteRoomResFromDataset(RoomReservation, kbmRoomResRoomReservation);
      lclDeleteRoomResFromDataset(RoomReservation, kbmRoomRatesRoomReservation);

      sFilter := '(processed=' + inttostr(RoomReservation) + ')';

      mRrInfo.Filter := sFilter;
      mRrInfo.Filtered := true;
      mRrInfo.First;

      RoomDescription := mRrInfoRoomDescription.AsString;
      RoomTypeDescription := mRrInfoRoomDescription.AsString;
      MainGuest := mRrInfoMainGuest.AsString;
      isPercentage := mRrInfoisPercentage.AsBoolean;
      PriceCode := mRrInfoPriceCode.AsString;

      Guests := mRrInfonumGuests.Asinteger;
      ChildrenCount := mRrInfonumChildren.Asinteger;
      InfantCount := mRrInfonumInfants.Asinteger;

      RoomReservation := mRrInfoProcessed.Asinteger;
      Room := mRrInfoRoom.AsString;
      if Room = '' then
        Room := '<' + inttostr(RoomReservation) + '>';
      RoomType := mRrInfoRoomType.AsString;

      ttPrice := 0.00;
      ttDiscount := 0.00;
      ttPriceCount := 0;

      Currency := labCurrency.Caption;
      currencyRate := hData.GetRate(Currency);

      tmpDeparture := 0;
      tmpArrival := date + 10000;
      mRrInfo.First;
      while not mRrInfo.eof do
      begin
        RoomRate := mRrInfoRoomRate.AsFloat;
        Discount := mRrInfoDiscount.AsFloat;

        lstPrices.Add(FloatTostr(RoomRate));
        ttPriceCount := ttPriceCount + 1;
        ttPrice := ttPrice + RoomRate;
        ttDiscount := ttDiscount + Discount;

        tmpArrival := min(tmpArrival, mRrInfodtDate.AsDateTime);
        tmpDeparture := max(tmpDeparture, mRrInfodtDate.AsDateTime);

        mRrInfo.Next;
      end;

      Arrival := tmpArrival;
      Departure := tmpDeparture;

      AvrageDiscount := 0;
      if ttPriceCount <> 0 then
      begin
        AvrageDiscount := ttDiscount / ttPriceCount;
      end;

      RateCount := lstPrices.Count;
      Departure := Departure + 1;

      ttNetPrice := 0;
      mRrInfo.First;
      while not mRrInfo.eof do
      begin
        RoomRate := mRrInfoRoomRate.AsFloat;
        Discount := mRrInfoDiscount.AsFloat;
        isPercentage := mRrInfoisPercentage.AsBoolean;

        DiscountAmount := 0;

        if RoomRate <> 0 then
        begin
          if Discount <> 0 then
          begin
            if isPercentage then
            begin
              DiscountAmount := RoomRate * Discount / 100;
            end
            else
            begin
              DiscountAmount := Discount;
            end;
          end;
        end;
        RentAmount := RoomRate - DiscountAmount;
        if currencyRate = 0 then
          currencyRate := 1;
        NativeAmount := RentAmount * currencyRate;

        ttNetPrice := ttNetPrice + RentAmount;

        kbmRoomRates.append;
        kbmRoomRatesReservation.Asinteger := mRrInfoReservation.Asinteger;
        kbmRoomRatesRoomReservation.Asinteger := mRrInfoProcessed.Asinteger;
        kbmRoomRatesRoomNumber.AsString := mRrInfoRoom.AsString;
        kbmRoomRatesRateDate.AsDateTime := mRrInfodtDate.AsDateTime;
        kbmRoomRatesPriceCode.AsString := mRrInfoPriceCode.AsString;
        kbmRoomRatesRate.AsFloat := RoomRate;
        kbmRoomRatesDiscount.AsFloat := Discount;
        kbmRoomRatesisPercentage.AsBoolean := isPercentage;
        kbmRoomRatesShowDiscount.AsBoolean := mRrInfoshowDiscount.AsBoolean;
        kbmRoomRatesisPaid.AsBoolean := false;
        kbmRoomRatesDiscountAmount.AsFloat := DiscountAmount;
        kbmRoomRatesRentAmount.AsFloat := RentAmount;
        kbmRoomRatesNativeAmount.AsFloat := NativeAmount;
        kbmRoomRates.Post;
        mRrInfo.Next;
      end;

      AvrageNetPrice := 0;
      if ttPriceCount <> 0 then
      begin
        AvrageNetPrice := ttNetPrice / ttPriceCount;
      end;

      kbmRoomRes.append;
      kbmRoomResRoomReservation.Asinteger := RoomReservation;
      kbmRoomResRoom.AsString := Room;
      kbmRoomResRoomType.AsString := RoomType;
      kbmRoomResGuests.Asinteger := Guests;
      kbmRoomResAvragePrice.AsFloat := AvrageNetPrice;
      kbmRoomResRateCount.Asinteger := RateCount;
      kbmRoomResRoomDescription.AsString := RoomDescription;
      kbmRoomResRoomTypeDescription.AsString := RoomTypeDescription;
      kbmRoomResArrival.AsDateTime := Arrival;
      kbmRoomResDeparture.AsDateTime := Departure;
      kbmRoomResChildrenCount.Asinteger := ChildrenCount;
      kbmRoomResinfantCount.Asinteger := InfantCount;
      kbmRoomResPriceCode.AsString := PriceCode;
      kbmRoomResAvrageDiscount.AsFloat := AvrageDiscount;
      kbmRoomResisPercentage.AsBoolean := isPercentage;
      kbmRoomResMainGuest.AsString := MainGuest;
      kbmRoomRes.Post;

      oSelectedRoomItem := TnewRoomReservationItem.Create(RoomReservation, Room, RoomType, '', Arrival, Departure,
        Guests, AvrageNetPrice, AvrageDiscount, isPercentage, RateCount, ChildrenCount, InfantCount, PriceCode,
        MainGuest, '');
      oNewReservation.newRoomReservations.RoomItemsList.Add(oSelectedRoomItem);
      mRrInfo.Filtered := false;
    finally
      kbmRoomRes.EnableControls;
      kbmRoomRates.EnableControls;
      mRrInfo.EnableControls;
      screen.Cursor := crDefault;
    end;
  finally
    freeandnil(lstPrices);
  end;

end;

function TfrmAllotmentToRes.SetRoomResProcessed(ACol, ARow: integer; newRR: integer): boolean;
begin
  result := false;
  mRrInfo.SortFields := 'RoomRate;isPercentage;Discount';
  mRrInfo.sort([mtcoDescending]);
  if mRrInfo.Locate('processed;Row;col', VarArrayOf([cUnProcessed, ARow, ACol]), []) then
  begin
    mRrInfo.Edit;
    mRrInfoProcessed.Asinteger := newRR;
    mRrInfo.Post;
    mRrInfo.SortFields := 'RoomRate;isPercentage;Discount';
    mRrInfo.sort([]);
    result := true;
  end;
end;

function TfrmAllotmentToRes.updateCellInfo(ACol, ARow: integer; newRR: integer): boolean;
begin
  result := SetRoomResProcessed(ACol, ARow, newRR);
  if result then
  begin
    FillData;
    result := true;
  end;
end;

function TfrmAllotmentToRes.GetNextFakeRRID: integer;
begin
  dec(FLastFakeRRNumber);
  Result := FLastFakeRRNumber;
end;

function TfrmAllotmentToRes.GetResInfo(ACol: integer = -1; ARow: integer = -1): RecRRInfoAlot;
var
  resCell: TresCell;
begin
  if ACol = -1 then
    ACol := grProvide.col;
  if ARow = -1 then
    ARow := grProvide.row;

  resCell := TresCell(grProvide.Objects[ACol, ARow]);

  result.rdID := resCell.rdID;
  result.RoomReservation := resCell.RoomReservation;
  result.Reservation := resCell.Reservation;
  result.dtDate := resCell.dtDate;
  result.Room := resCell.Room;
  result.RoomType := resCell.RoomType;
  result.ResFlag := resCell.ResFlag;
  result.isNoRoom := resCell.isNoRoom;
  result.PriceCode := resCell.PriceCode;
  result.RoomRate := resCell.RoomRate;
  result.Discount := resCell.Discount;
  result.isPercentage := resCell.isPercentage;
  result.showDiscount := resCell.showDiscount;
  result.Paid := resCell.Paid;
  result.Currency := resCell.Currency;
  result.MainGuest := resCell.MainGuest;
  result.numGuests := resCell.numGuests;
  result.numChildren := resCell.numChildren;
  result.numInfants := resCell.numInfants;
  result.RoomCount := resCell.RoomCount;
end;

procedure TfrmAllotmentToRes.GetRrData(Reservation: integer);
var
  s: string;
  sql: string;

  rset0, rset1: TRoomerDataset;
  ExecutionPlan: TRoomerExecutionPlan;

  lastDate: Tdate;
  strTmp: string;
  row, col: integer;

  Room, RoomType: string;

begin
  ExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try

    s := '';
    s := s + ' SELECT '#10;
    s := s + '       cast(max(date(rd.Adate)) as DATE) as maxDate '#10;
    s := s + '     , cast(min(date(rd.Adate)) as DATE) as minDate '#10;
    s := s + '     , count(room) as RoomCount '#10;
    s := s + '  FROM '#10;
    s := s + '    roomsdate rd '#10;
    s := s + ' WHERE '#10;
    s := s + '   (rd.Reservation = %d) '#10;
    s := s + '   AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '; // **zxhj line added
    sql := format(s, [Reservation]);
    ExecutionPlan.AddQuery(sql); // 0

    s := '';
    s := s + ' SELECT '#10;
    s := s + '      rd.Id as rdID '#10;
    s := s + '    , rd.Reservation '#10;
    s := s + '    , rd.RoomReservation '#10;
    s := s + '    , date(rd.Adate) as dtDate '#10;
    s := s + '    , rd.Room '#10;
    s := s + '    , rd.RoomType '#10;
    s := s + '    , rd.resFlag '#10;
    s := s + '    , rd.isNoRoom '#10;
    s := s + '    , rd.PriceCode '#10;
    s := s + '    , rd.RoomRate '#10;
    s := s + '    , rd.Discount '#10;
    s := s + '    , rd.isPercentage '#10;
    s := s + '    , rd.showDiscount '#10;
    s := s + '    , rd.Paid '#10;
    s := s + '    , rd.Currency '#10;
    s := s + '    , rr.numGuests '#10;
    s := s + '    , rr.numChildren '#10;
    s := s + '    , rr.numInfants '#10;
    s := s + '    , rr.GroupAccount '#10;
    s := s + '    , (SELECT name FROM persons WHERE persons.roomreservation=rd.roomreservation LIMIT 1) AS MainGuest '#10;
    s := s + '    , (SELECT count(ID) FROM persons WHERE persons.roomreservation=rd.roomreservation) AS GuestCount '#10;
    s := s + '    , COALESCE(r.Description, "") as RoomDescription '#10;
    s := s + '    , COALESCE(rt.Description, "") AS RoomTypeDescription '#10;
    s := s + ' FROM '#10;
    s := s + '   roomsdate rd '#10;
    s := s + ' INNER JOIN '#10;
    s := s + '   roomreservations rr ON rd.roomreservation = rr.roomreservation ';
    s := s + ' LEFT OUTER JOIN '#10;
    s := s + '   rooms r ON r.room = rd.room';
    s := s + ' LEFT OUTER JOIN '#10;
    s := s + '   roomtypes rt ON rt.roomtype= r.roomtype';
    s := s + ' WHERE '#10;
    s := s + '   (rd.Reservation = %d) '#10;
    s := s + '   AND (ResFlag <> ' + _db(STATUS_DELETED) + ' ) '; // **zxhj line added

    s := s + ' ORDER BY '#10;
    s := s + '      Room ';
    s := s + '    , rd.ADate '#10;

    sql := format(s, [Reservation]);
    // copyToClipBoard(sql);
    // Debugmessage(sql);
    ExecutionPlan.AddQuery(sql); // 1

    screen.Cursor := crHourglass;
    mRrInfo.DisableControls;
    try
      ExecutionPlan.Execute(ptQuery);

      rset0 := ExecutionPlan.Results[0];
      lastDate := rset0.FieldByName('maxDate').AsDateTime;
      zFirstDate := rset0.FieldByName('minDate').AsDateTime;
      zRoomCount := rset0.FieldByName('RoomCount').Asinteger;
      zNightCount := trunc(lastDate) - trunc(zFirstDate);
      zNightCount := zNightCount + 1;

      labLastDate.Caption := dateTostr(lastDate);
      labFirstDate.Caption := dateTostr(zFirstDate);
      labDays.Caption := inttostr(zNightCount);
      labRooms.Caption := inttostr(zRoomCount);

      rset1 := ExecutionPlan.Results[1];

      if mRrInfo.active then
        mRrInfo.close;
      mRrInfo.Open;
      LoadKbmMemtableFromDataSetQuiet(mRrInfo, rset1, []);

      mRrInfo.SortFields := 'Room;RoomType';
      mRrInfo.sort([]);

      mRrInfo.First;

      while not mRrInfo.eof do
      begin
        Room := mRrInfoRoom.AsString;
        if copy(Room, 1, 1) = '<' then
        begin
          mRrInfo.Edit;
          mRrInfoisNoRoom.AsBoolean := true;
          mRrInfoRoom.AsString := '';
          mRrInfo.Post;
        end;
        mRrInfo.Next;
      end;

      mRrInfo.First;
      labResRooms.Caption := inttostr(rset1.RecordCount);
      labCurrency.Caption := mRrInfoCurrency.AsString;;
      chkIsGroupInvoice.Checked := mRrInfoGroupAccount.AsBoolean;
      zAllotmentIsGroupInvoice := mRrInfoGroupAccount.AsBoolean;

      labPriceCode.Caption := mRrInfoPriceCode.AsString;

      if mRooms.active then
        mRooms.close;
      mRooms.Open;
      strTmp := '';
      while not mRrInfo.eof do
      begin
        s := mRrInfoRoom.AsString + mRrInfoRoomType.AsString;
        if s <> strTmp then
        begin
          mRooms.append;
          mRoomsRoom.AsString := mRrInfoRoom.AsString;
          mRoomsRoomType.AsString := mRrInfoRoomType.AsString;
          if mRrInfoisNoRoom.AsBoolean then
            mRoomsRoomDescription.AsString := mRrInfoRoomtypeDescription.AsString
          else
            mRoomsRoomDescription.AsString := mRrInfoRoomDescription.AsString;
          mRooms.Post;
          strTmp := s;
        end;
        mRrInfo.Next;
      end;

      mRooms.SortFields := 'RoomType;room';
      mRooms.sort([]);
      zCountRoomTypes := mRooms.RecordCount;

      zRows := 0;
      zRows := zRows + cCountFixedRows;
      zRows := zRows + zCountRoomTypes;
      zRows := zRows + cCountEmptyRows;

      zCols := 0;
      zCols := zCols + cCountFixedCols;
      zCols := zCols + zNightCount;
      zCols := zCols + cCountEmptyCols;

      grProvide.ColCount := zCols;
      grProvide.RowCount := zRows;
      grProvide.FixedCols := cCountFixedCols;
      grProvide.FixedRows := cCountFixedRows;

      grProvide.FixedFont.color := frmMain.sSkinManager1.GetGlobalFontColor;
      grProvide.HighlightTextColor := frmMain.sSkinManager1.GetGlobalFontColor;
      grProvide.FixedColor := frmMain.sSkinManager1.GetGlobalColor;

      SetDateHeads;
      FillgrProvideWithRooms;
      mRrInfo.First;
      while not mRrInfo.eof do
      begin
        col := DateToCol(mRrInfodtDate.AsDateTime);
        Room := mRrInfoRoom.AsString;
        RoomType := mRrInfoRoomType.AsString;
        row := RoomAndTypeToRow(Room, RoomType);
        mRrInfo.Edit;
        mRrInfoRow.Asinteger := row;
        mRrInfoCol.Asinteger := col;
        mRrInfoProcessed.Asinteger := cUnprocessed;
        mRrInfo.Post;
        mRrInfo.Next;
      end;

      mRrInfo.SortFields := 'RoomRate;isPercentage;Discount';
      FillData;
    finally
      screen.Cursor := crDefault;
      mRrInfo.EnableControls;
    end;
  finally
    ExecutionPlan.Free;
  end;
end;

function TfrmAllotmentToRes.Apply: boolean;
var
  customer: string;
  oSelectedRoomItem: TnewRoomReservationItem;
  rateItem: TRateItem;

  Room: string;
  RoomType: string;
  Arrival: TdateTime;
  Departure: TdateTime;
  GuestCount: integer;
  RoomReservation: integer;
  AvragePrice: double;
  AvrageDiscount: double;
  isPercentage: boolean;
  RateCount: integer;
  ChildrenCount: integer;
  InfantCount: integer;
  PriceCode: string;

  rateRoomNumber: string;
  rateDate: Tdate;
  rate: double;
  ratePriceCode: string;
  rateDiscount: double;
  rateIsPercentage: boolean;
  rateShowDiscount: boolean;
  rateIsPaid: boolean;
  roomIndex: integer;
  mainGuestName: string;
begin

  result := true;
  CreateRestAllotmentRoomreservations;

  customer := zReservationInfo.customer;
  oNewReservation.HomeCustomer.customer := customer;

  oNewReservation.HomeCustomer.GuestName := ''; // edGuestName.text;
  oNewReservation.HomeCustomer.invRefrence := zReservationInfo.invRefrence; // edinvRefrence.Text;
  oNewReservation.HomeCustomer.Country := zReservationInfo.Country; // edCountry.text;
  oNewReservation.HomeCustomer.ReservationName := zReservationInfo.Name; // edReservationName.text;
  oNewReservation.HomeCustomer.RoomStatus := 'P';; // RoomstatusToInfo(cbxRoomStatus.ItemIndex);
  oNewReservation.HomeCustomer.MarketSegmentCode := zReservationInfo.MarketSegment; // edMarketSegmentCode.text;
  oNewReservation.HomeCustomer.Currency := labCurrency.Caption; // edCurrency.text;
  oNewReservation.HomeCustomer.PID := zReservationInfo.custPID; // edPID.text ;
  oNewReservation.HomeCustomer.CustomerName := zReservationInfo.Name;
  // .CustomerName          ;// edCustomerName.text ;
  oNewReservation.HomeCustomer.Address1 := zReservationInfo.Address1; // edAddress1.text ;
  oNewReservation.HomeCustomer.Address2 := zReservationInfo.Address2; // edAddress2.text ;
  oNewReservation.HomeCustomer.Address3 := zReservationInfo.Address3; // edAddress3.text ;
  oNewReservation.HomeCustomer.Tel1 := zReservationInfo.Tel1; // edTel1.text     ;
  oNewReservation.HomeCustomer.Tel2 := zReservationInfo.Tel2; // edTel2.text     ;
  oNewReservation.HomeCustomer.Fax := zReservationInfo.Fax; // edFax.text      ;
  oNewReservation.HomeCustomer.EmailAddress := zReservationInfo.CustomerEmail; // edEmailAddress.text ;
  oNewReservation.HomeCustomer.HomePage := zReservationInfo.CustomerWebSite; // edHomePage.text     ;
  oNewReservation.HomeCustomer.ContactPhone := zReservationInfo.ContactPhone; // edContactPhone.text ;
  oNewReservation.HomeCustomer.ContactPerson := zReservationInfo.ContactName; // edContactPerson.text;
  oNewReservation.HomeCustomer.ContactFax := zReservationInfo.ContactFax; // edContactFax.text   ;
  oNewReservation.HomeCustomer.ContactEmail := zReservationInfo.ContactEmail; // edContactEmail.text ;
  oNewReservation.HomeCustomer.ReservationPaymentInfo := zReservationInfo.PMInfo; // memReservationPaymentInfo.text;
  oNewReservation.HomeCustomer.ReservationGeneralInfo := zReservationInfo.Information;
  // memReservationGeneralInfo.text;

  // Below is depended on room not reservation
  oNewReservation.HomeCustomer.PcCode := labPriceCode.Caption; // edPcCode.text;
  oNewReservation.HomeCustomer.IsGroupInvoice := chkIsGroupInvoice.Checked; // chkIsGroupInvoice.checked;
  oNewReservation.HomeCustomer.ShowDiscountOnInvoice := false; // chkShowDiscountOnInvoice.Checked;
  oNewReservation.HomeCustomer.isRoomResDiscountPrec := true; // cbxIsRoomResDiscountPrec.ItemIndex=0;
  oNewReservation.HomeCustomer.RoomResDiscount := 0; // edRoomResDiscount.Value;

  kbmRoomRates.SortFields := 'RoomReservation;RateDate';;
  kbmRoomRates.sort([]);

  oNewReservation.newRoomReservations.RoomItemsList.Clear;
  roomIndex := 0;
  kbmRoomRes.First;

  while not kbmRoomRes.eof do
  begin
    Room := kbmRoomResRoom.AsString;
    RoomType := kbmRoomResRoomType.AsString;
    Arrival := kbmRoomResArrival.AsDateTime;
    Departure := kbmRoomResDeparture.AsDateTime;
    GuestCount := kbmRoomResGuests.Asinteger;
    RoomReservation := kbmRoomResRoomReservation.Asinteger;
    AvragePrice := kbmRoomResAvragePrice.AsFloat;
    AvrageDiscount := kbmRoomResAvrageDiscount.AsFloat;
    RateCount := kbmRoomResRateCount.Asinteger;
    ChildrenCount := kbmRoomResChildrenCount.Asinteger;
    InfantCount := kbmRoomResinfantCount.Asinteger;
    PriceCode := kbmRoomResPriceCode.AsString;
    isPercentage := kbmRoomResisPercentage.AsBoolean;
    mainGuestName := kbmRoomResMainGuest.AsString;

    oSelectedRoomItem := TnewRoomReservationItem.Create(RoomReservation, Room, RoomType, '', Arrival, Departure,
      GuestCount, AvragePrice, AvrageDiscount, isPercentage, RateCount, ChildrenCount, InfantCount, PriceCode,
      mainGuestName, '');
    oNewReservation.newRoomReservations.RoomItemsList.Add(oSelectedRoomItem);
    oNewReservation.newRoomReservations.RoomItemsList[roomIndex].oRates.SetCurrency(labCurrency.Caption);

    kbmRoomRates.Filter := '(Roomreservation=' + inttostr(RoomReservation) + ')';
    kbmRoomRates.Filtered := true;

    kbmRoomRates.First;
    while not kbmRoomRates.eof do
    begin
      rateRoomNumber := kbmRoomRatesRoomNumber.AsString;
      rateDate := kbmRoomRatesRateDate.AsDateTime;
      rate := kbmRoomRatesRate.AsFloat;
      ratePriceCode := kbmRoomRatesPriceCode.AsString;
      rateDiscount := kbmRoomRatesDiscount.AsFloat;
      rateIsPercentage := kbmRoomRatesisPercentage.AsBoolean;
      rateShowDiscount := kbmRoomRatesShowDiscount.AsBoolean;
      rateIsPaid := kbmRoomRatesisPaid.AsBoolean;
      rateItem := TRateItem.Create(rate, rateDate, rateDiscount, rateShowDiscount, rateIsPercentage, rateIsPaid,
        ratePriceCode, rateRoomNumber, -1, RoomReservation);
      oNewReservation.newRoomReservations.RoomItemsList[roomIndex].oRates.RateItemsList.Add(rateItem);
      kbmRoomRates.Next;
    end;
    inc(roomIndex);
    kbmRoomRes.Next;
  end;

  /// /////////////////////////////////////////////////////////////////
  ///
  ///
  /// ///////////////////////////////////////////////////////////////
  ///

  if zRestCount > 0 then
  begin
    oRestReservation.HomeCustomer.customer := customer;

    oRestReservation.HomeCustomer.GuestName := ''; // edGuestName.text;
    oRestReservation.HomeCustomer.invRefrence := zReservationInfo.invRefrence; // edinvRefrence.Text;
    oRestReservation.HomeCustomer.Country := zReservationInfo.Country; // edCountry.text;
    oRestReservation.HomeCustomer.ReservationName := zReservationInfo.Name; // edReservationName.text;
    oRestReservation.HomeCustomer.RoomStatus := zResFlag; // RoomstatusToInfo(cbxRoomStatus.ItemIndex);
    oRestReservation.HomeCustomer.MarketSegmentCode := zReservationInfo.MarketSegment; // edMarketSegmentCode.text;
    oRestReservation.HomeCustomer.Currency := labCurrency.Caption; // edCurrency.text;
    oRestReservation.HomeCustomer.PID := zReservationInfo.custPID; // edPID.text ;
    oRestReservation.HomeCustomer.CustomerName := zReservationInfo.Name;
    // .CustomerName          ;// edCustomerName.text ;
    oRestReservation.HomeCustomer.Address1 := zReservationInfo.Address1; // edAddress1.text ;
    oRestReservation.HomeCustomer.Address2 := zReservationInfo.Address2; // edAddress2.text ;
    oRestReservation.HomeCustomer.Address3 := zReservationInfo.Address3; // edAddress3.text ;
    oRestReservation.HomeCustomer.Tel1 := zReservationInfo.Tel1; // edTel1.text     ;
    oRestReservation.HomeCustomer.Tel2 := zReservationInfo.Tel2; // edTel2.text     ;
    oRestReservation.HomeCustomer.Fax := zReservationInfo.Fax; // edFax.text      ;
    oRestReservation.HomeCustomer.EmailAddress := zReservationInfo.CustomerEmail; // edEmailAddress.text ;
    oRestReservation.HomeCustomer.HomePage := zReservationInfo.CustomerWebSite; // edHomePage.text     ;
    oRestReservation.HomeCustomer.ContactPhone := zReservationInfo.ContactPhone; // edContactPhone.text ;
    oRestReservation.HomeCustomer.ContactPerson := zReservationInfo.ContactName; // edContactPerson.text;
    oRestReservation.HomeCustomer.ContactFax := zReservationInfo.ContactFax; // edContactFax.text   ;
    oRestReservation.HomeCustomer.ContactEmail := zReservationInfo.ContactEmail; // edContactEmail.text ;
    oRestReservation.HomeCustomer.ReservationPaymentInfo := zReservationInfo.PMInfo; // memReservationPaymentInfo.text;
    oRestReservation.HomeCustomer.ReservationGeneralInfo := zReservationInfo.Information;
    // memReservationGeneralInfo.text;

    // Below is depended on room not reservation
    oRestReservation.HomeCustomer.PcCode := labPriceCode.Caption; // edPcCode.text;
    oRestReservation.HomeCustomer.IsGroupInvoice := zAllotmentIsGroupInvoice; // chkIsGroupInvoice.checked;
    oRestReservation.HomeCustomer.ShowDiscountOnInvoice := false; // chkShowDiscountOnInvoice.Checked;
    oRestReservation.HomeCustomer.isRoomResDiscountPrec := true; // cbxIsRoomResDiscountPrec.ItemIndex=0;
    oRestReservation.HomeCustomer.RoomResDiscount := 0; // edRoomResDiscount.Value;

    kbmRestRoomRates.SortFields := 'RoomReservation;RateDate';;
    kbmRestRoomRates.sort([]);

    oRestReservation.newRoomReservations.RoomItemsList.Clear;
    roomIndex := 0;
    kbmrestRoomRes.First;

    while not kbmrestRoomRes.eof do
    begin
      Room := kbmrestRoomResRoom.AsString;
      RoomType := kbmrestRoomResRoomType.AsString;
      Arrival := kbmrestRoomResArrival.AsDateTime;
      Departure := kbmrestRoomResDeparture.AsDateTime;
      GuestCount := kbmrestRoomResGuests.Asinteger;
      RoomReservation := kbmrestRoomResRoomReservation.Asinteger;
      AvragePrice := kbmrestRoomResAvragePrice.AsFloat;
      AvrageDiscount := kbmrestRoomResAvrageDiscount.AsFloat;
      RateCount := kbmrestRoomResRateCount.Asinteger;
      ChildrenCount := kbmrestRoomResChildrenCount.Asinteger;
      InfantCount := kbmrestRoomResinfantCount.Asinteger;
      PriceCode := kbmrestRoomResPriceCode.AsString;
      isPercentage := kbmrestRoomResisPercentage.AsBoolean;
      mainGuestName := kbmrestRoomResMainGuest.AsString;

      oSelectedRoomItem := TnewRoomReservationItem.Create(RoomReservation, Room, RoomType, '', Arrival, Departure,
        GuestCount, AvragePrice, AvrageDiscount, isPercentage, RateCount, ChildrenCount, InfantCount, PriceCode,
        mainGuestName, '');
      oRestReservation.newRoomReservations.RoomItemsList.Add(oSelectedRoomItem);
      oRestReservation.newRoomReservations.RoomItemsList[roomIndex].oRates.SetCurrency(labCurrency.Caption);

      kbmRestRoomRates.Filter := '(Roomreservation=' + inttostr(RoomReservation) + ')';
      kbmRestRoomRates.Filtered := true;

      kbmRestRoomRates.First;
      while not kbmRestRoomRates.eof do
      begin
        rateRoomNumber := kbmRestRoomRatesRoomNumber.AsString;
        rateDate := kbmRestRoomRatesRateDate.AsDateTime;
        rate := kbmRestRoomRatesRate.AsFloat;
        ratePriceCode := kbmRestRoomRatesPriceCode.AsString;
        rateDiscount := kbmRestRoomRatesDiscount.AsFloat;
        rateIsPercentage := kbmRestRoomRatesisPercentage.AsBoolean;
        rateShowDiscount := kbmRestRoomRatesShowDiscount.AsBoolean;
        rateIsPaid := kbmRestRoomRatesisPaid.AsBoolean;
        rateItem := TRateItem.Create(rate, rateDate, rateDiscount, rateShowDiscount, rateIsPercentage, rateIsPaid,
          ratePriceCode, rateRoomNumber, -1, RoomReservation);
        oRestReservation.newRoomReservations.RoomItemsList[roomIndex].oRates.RateItemsList.Add(rateItem);
        kbmRestRoomRates.Next;
      end;
      inc(roomIndex);
      kbmrestRoomRes.Next;
    end;
  end;

end;

function TfrmAllotmentToRes.AddRestRoomReservation(FakeRoomReservation: integer): boolean;
var
  Room: string; // *
  RoomType: string; // *
  Guests: integer; //
  RateCount: integer; //
  RoomDescription: String;
  RoomTypeDescription: string;
  Arrival: Tdate; // *
  Departure: Tdate; // *
  ChildrenCount: integer; //
  InfantCount: integer; //
  PriceCode: String; // *
  AvrageDiscount: double; //
  isPercentage: boolean; // *
  MainGuest: string; // *

  ttPrice: double;
  ttDiscount: double;
  ttPriceCount: integer;
  ttNetPrice: double;
  AvrageNetPrice: double; //

  sFilter: string;
  tmpArrival: Tdate;
  tmpDeparture: Tdate;

  RoomRate: double;
  Discount: double;

  lstPrices: Tstringlist;

  DiscountAmount: double;
  RentAmount: double;
  NativeAmount: double;

  currencyRate: double;
  Currency: string;
  oSelectedRoomItem: TnewRoomReservationItem;
begin

  Assert(FakeRoomReservation <> 0, 'FakeRoomreservation = 0');
  result := false;

  lstPrices := Tstringlist.Create;
  try
    lstPrices.Sorted := true;
    lstPrices.Duplicates := dupIgnore;

    screen.Cursor := crHourglass;
    mRrInfo.DisableControls;
    kbmrestRoomRes.DisableControls;
    kbmRestRoomRates.DisableControls;
    try
      sFilter := '(processed=' + inttostr(FakeRoomReservation) + ')';

      mRrInfo.Filter := sFilter;
      mRrInfo.Filtered := true;
      mRrInfo.First;

      RoomDescription := mRrInfoRoomDescription.AsString;
      RoomTypeDescription := mRrInfoRoomtypeDescription.AsString;
      MainGuest := mRrInfoMainGuest.AsString;
      isPercentage := mRrInfoisPercentage.AsBoolean;
      PriceCode := mRrInfoPriceCode.AsString;

      Guests := mRrInfonumGuests.Asinteger;
      ChildrenCount := mRrInfonumChildren.Asinteger;
      InfantCount := mRrInfonumInfants.Asinteger;

//      FakeRoomReservation := mRrInfoProcessed.Asinteger;
      Room := mRrInfoRoom.AsString;
      if Room = '' then
        Room := '<' + inttostr(FakeRoomReservation) + '>';
      RoomType := mRrInfoRoomType.AsString;

      ttPrice := 0.00;
      ttDiscount := 0.00;
      ttPriceCount := 0;

      Currency := labCurrency.Caption;
      currencyRate := hData.GetRate(Currency);

      tmpDeparture := 0;
      Departure := tmpDeparture;
      tmpArrival := date + 10000;
      Arrival := tmpArrival;
      mRrInfo.First;
      while not mRrInfo.eof do
      begin
        RoomRate := mRrInfoRoomRate.AsFloat;
        Discount := mRrInfoDiscount.AsFloat;

        lstPrices.Add(FloatTostr(RoomRate));
        ttPriceCount := ttPriceCount + 1;
        ttPrice := ttPrice + RoomRate;
        ttDiscount := ttDiscount + Discount;

        if tmpArrival >= mRrInfodtDate.AsDateTime then
          Arrival := mRrInfodtDate.AsDateTime;
        if tmpDeparture <= mRrInfodtDate.AsDateTime then
          Departure := mRrInfodtDate.AsDateTime;

        tmpArrival := Arrival;
        tmpDeparture := Departure;

        mRrInfo.Next;
      end;

      AvrageDiscount := 0;
      if ttPriceCount <> 0 then
      begin
        AvrageDiscount := ttDiscount / ttPriceCount;
      end;

      RateCount := lstPrices.Count;
      Departure := Departure + 1;

      ttNetPrice := 0;
      mRrInfo.First;
      while not mRrInfo.eof do
      begin
        RoomRate := mRrInfoRoomRate.AsFloat;
        Discount := mRrInfoDiscount.AsFloat;
        isPercentage := mRrInfoisPercentage.AsBoolean;

        DiscountAmount := 0;

        if RoomRate <> 0 then
        begin
          if Discount <> 0 then
          begin
            if isPercentage then
            begin
              DiscountAmount := RoomRate * Discount / 100;
            end
            else
            begin
              DiscountAmount := Discount;
            end;
          end;
        end;
        RentAmount := RoomRate - DiscountAmount;
        if currencyRate = 0 then
          currencyRate := 1;
        NativeAmount := RentAmount * currencyRate;

        ttNetPrice := ttNetPrice + RentAmount;

        kbmRestRoomRates.append;
        kbmRestRoomRatesReservation.Asinteger := mRrInfoReservation.Asinteger;
        kbmRestRoomRatesRoomReservation.Asinteger := mRrInfoProcessed.Asinteger;
        kbmRestRoomRatesRoomNumber.AsString := mRrInfoRoom.AsString;
        kbmRestRoomRatesRateDate.AsDateTime := mRrInfodtDate.AsDateTime;
        kbmRestRoomRatesPriceCode.AsString := mRrInfoPriceCode.AsString;
        kbmRestRoomRatesRate.AsFloat := RoomRate;
        kbmRestRoomRatesDiscount.AsFloat := Discount;
        kbmRestRoomRatesisPercentage.AsBoolean := isPercentage;
        kbmRestRoomRatesShowDiscount.AsBoolean := mRrInfoshowDiscount.AsBoolean;
        kbmRestRoomRatesisPaid.AsBoolean := false;
        kbmRestRoomRatesDiscountAmount.AsFloat := DiscountAmount;
        kbmRestRoomRatesRentAmount.AsFloat := RentAmount;
        kbmRestRoomRatesNativeAmount.AsFloat := NativeAmount;
        kbmRestRoomRates.Post;
        mRrInfo.Next;
      end;

      AvrageNetPrice := 0;
      if ttPriceCount <> 0 then
      begin
        AvrageNetPrice := ttNetPrice / ttPriceCount;
      end;

      kbmrestRoomRes.append;
      kbmrestRoomResRoomReservation.Asinteger := FakeRoomReservation;
      kbmrestRoomResRoom.AsString := Room;
      kbmrestRoomResRoomType.AsString := RoomType;
      kbmrestRoomResGuests.Asinteger := Guests;
      kbmrestRoomResAvragePrice.AsFloat := AvrageNetPrice;
      kbmrestRoomResRateCount.Asinteger := RateCount;
      kbmrestRoomResRoomDescription.AsString := RoomDescription;
      kbmrestRoomResRoomTypeDescription.AsString := RoomTypeDescription;
      kbmrestRoomResArrival.AsDateTime := Arrival;
      kbmrestRoomResDeparture.AsDateTime := Departure;
      kbmrestRoomResChildrenCount.Asinteger := ChildrenCount;
      kbmrestRoomResinfantCount.Asinteger := InfantCount;
      kbmrestRoomResPriceCode.AsString := PriceCode;
      kbmrestRoomResAvrageDiscount.AsFloat := AvrageDiscount;
      kbmrestRoomResisPercentage.AsBoolean := isPercentage;
      kbmrestRoomResMainGuest.AsString := MainGuest;
      kbmrestRoomRes.Post;

      oSelectedRoomItem := TnewRoomReservationItem.Create(FakeRoomReservation, Room, RoomType, '', Arrival, Departure,
        Guests, AvrageNetPrice, AvrageDiscount, isPercentage, RateCount, ChildrenCount, InfantCount, PriceCode,
        MainGuest, '');
      oRestReservation.newRoomReservations.RoomItemsList.Add(oSelectedRoomItem);
      mRrInfo.Filtered := false;
    finally
      kbmrestRoomRes.EnableControls;
      kbmRestRoomRates.EnableControls;
      mRrInfo.EnableControls;
      screen.Cursor := crDefault;
    end;
  finally
    freeandnil(lstPrices);
  end;
end;

function TfrmAllotmentToRes.RoomsInAllotment: integer;
var
  iRow, iCol: integer;
  sCellContent: string;
  RoomCount: integer;
begin
  result := 0;
  for iRow := cCountFixedRows to grProvide.RowCount - 1 do
  begin
    for iCol := cCountFixedCols to grProvide.ColCount - 1 do
    begin
      sCellContent := trim(grProvide.Cells[iCol, iRow]);
      if sCellContent <> '' then
      begin
        RoomCount := 0;
        if grProvide.Objects[iCol, iRow] <> nil then
        begin
          RoomCount := (grProvide.Objects[iCol, iRow] as TresCell).RoomCount;
        end;
        result := result + RoomCount;
      end;
    end;
  end;
  labRooms.Caption := inttostr(result);
end;

function TfrmAllotmentToRes.CalcOnePrice(RoomReservation: integer; NewRate: double = 0): boolean;
var
  lstPrices: Tstringlist;
  // RoomReservation : integer;

  i, ii: integer;

  Room: string;
  RoomType: string;
  Guests: integer;
  AvragePrice: double;
  RateCount: integer;
  RoomDescription: string;
  RoomTypeDescription: string;
  Arrival: TdateTime;
  Departure: TdateTime;
  ChildrenCount: integer;
  InfantCount: integer;
  DiscountAmount: double;
  RentAmount: double;
  NativeAmount: double;

  priceID: integer;
  PriceCode: string;

  rateTotal: double;
  rateAvrage: double;

  discountTotal: double;
  discountAvrage: double;

  dayCount: integer;
  aDate: TdateTime;

  rateDate: TdateTime;
  rate: double;

  isPercentage: boolean;
  IsPaid: boolean;

  Currency: string;
  currencyRate: double;
  Discount: double;
  showDiscount: boolean;
  found: boolean;

begin
  IsPaid := false;
  lstPrices := Tstringlist.Create;
  try
    lstPrices.Sorted := true;
    lstPrices.Duplicates := dupIgnore;

    Currency := labCurrency.Caption;
    currencyRate := hData.GetRate(Currency);
    // discount      := edRoomResDiscount.Value;
    showDiscount := false;
    isPercentage := true;

    if kbmRoomRes.Locate('roomreservation', RoomReservation, []) then
    begin
      repeat
        found := kbmRoomRates.Locate('roomreservation', RoomReservation, []);
        if found then
        begin
          kbmRoomRates.Delete;
        end;
      until not found;

      i := oNewReservation.newRoomReservations.FindRoomFromRoomReservation(RoomReservation, 0);
      oNewReservation.newRoomReservations.RoomItemsList[i].oRates.RateItemsList.Clear;

      Room := kbmRoomResRoom.AsString;
      Arrival := kbmRoomResArrival.AsDateTime;
      Departure := kbmRoomResDeparture.AsDateTime;
      RoomType := kbmRoomResRoomType.AsString;
      RoomTypeDescription := kbmRoomResRoomTypeDescription.AsString;
      RoomDescription := kbmRoomResRoomDescription.AsString;
      Guests := kbmRoomResGuests.Asinteger;
      ChildrenCount := kbmRoomResChildrenCount.Asinteger;
      InfantCount := kbmRoomResinfantCount.Asinteger;
      Discount := kbmRoomResAvrageDiscount.AsFloat;

      PriceCode := trim(labPriceCode.Caption);
      priceID := hData.PriceCode_ID(PriceCode);

      dayCount := trunc(Departure) - trunc(Arrival);
      aDate := trunc(Arrival);
      rateTotal := 0;
      discountTotal := 0;
      lstPrices.Clear;
      for ii := 0 to dayCount - 1 do
      begin
        if (NewRate <> 0) then
        begin
          rate := NewRate;
          Discount := 0;
        end
        else
        begin
          rate := oNewReservation.newRoomReservations.RoomItemsList[i].oRates.GetDayRate(RoomType, Room, aDate, Guests,
            ChildrenCount, InfantCount, Currency, priceID, Discount, showDiscount, isPercentage, IsPaid, false

            );
        end;

        DiscountAmount := 0;
        if rate <> 0 then
        begin
          if Discount <> 0 then
          begin
            if isPercentage then
            begin
              DiscountAmount := rate * Discount / 100;
            end
            else
            begin
              DiscountAmount := Discount;
            end;
          end;
        end;
        RentAmount := rate - DiscountAmount;
        if currencyRate = 0 then
          currencyRate := 1;
        NativeAmount := RentAmount * currencyRate;

        kbmRoomRates.append;
        kbmRoomRatesReservation.Asinteger := -1;
        kbmRoomRatesRoomReservation.Asinteger := RoomReservation;
        kbmRoomRatesRoomNumber.AsString := Room;
        kbmRoomRatesRateDate.AsDateTime := aDate;
        kbmRoomRatesPriceCode.AsString := PriceCode;
        kbmRoomRatesRate.AsFloat := rate;
        kbmRoomRatesDiscount.AsFloat := Discount;
        kbmRoomRatesisPercentage.AsBoolean := isPercentage;
        kbmRoomRatesShowDiscount.AsBoolean := showDiscount;
        kbmRoomRatesisPaid.AsBoolean := IsPaid;
        kbmRoomRatesDiscountAmount.AsFloat := DiscountAmount;
        kbmRoomRatesRentAmount.AsFloat := RentAmount;
        kbmRoomRatesNativeAmount.AsFloat := NativeAmount;
        kbmRoomRates.Post;

        lstPrices.Add(FloatTostr(RentAmount));
        rateTotal := rateTotal + RentAmount;
        discountTotal := discountTotal + Discount;
        aDate := aDate + 1
      end;

      rateAvrage := 0;
      discountAvrage := 0;

      if dayCount <> 0 then
      begin
        rateAvrage := rateTotal / dayCount;
        discountAvrage := discountTotal / dayCount
      end;
      RateCount := lstPrices.Count;
      kbmRoomRes.Edit;
      kbmRoomResAvragePrice.AsFloat := rateAvrage;
      kbmRoomResRateCount.AsFloat := RateCount;
      kbmRoomResAvrageDiscount.AsFloat := discountAvrage;
      kbmRoomResisPercentage.AsBoolean := isPercentage;
      kbmRoomRes.Post;
    end;
  finally
    freeandnil(lstPrices);
  end;
end;

procedure TfrmAllotmentToRes.btnReCalcClick(Sender: TObject);
var
  RoomReservation: integer;
begin
  RoomReservation := kbmRoomResRoomReservation.Asinteger;
  CalcOnePrice(RoomReservation);
end;

procedure TfrmAllotmentToRes.btnReclacAllPricesClick(Sender: TObject);
begin
  ReclacAllPrices;
end;

procedure TfrmAllotmentToRes.ReclacAllPrices;
var
  RoomReservation: integer;
begin
  kbmRoomRes.First;
  while not kbmRoomRes.eof do
  begin
    RoomReservation := kbmRoomResRoomReservation.Asinteger;
    CalcOnePrice(RoomReservation);
    kbmRoomRes.Next;
  end;
end;

end.
