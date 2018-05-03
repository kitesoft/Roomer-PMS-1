﻿unit objNewReservation;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Contnrs, Dialogs, NativeXML
  , ADODB
  , Data.DB
  , cmpRoomerDataSet
  , cmpRoomerConnection
  , uRoomerThreadedRequest
  , uPriceOBJ
  , objHomeCustomer
  , objRoomRates
  , Generics.Collections
  , PrjConst
  , ustringUtils
  , ug
  , uAlerts
  , uRoomerDefinitions
  , RoomerExceptionHandling
  , uMarketDefinitions
  , uBreakfastTypeDefinitions, uAmount
  ;

TYPE
  EReservationCreationException = class(ERoomerException);
  EReservationIDNotFoundException = class(ERoomerException);

  TResMedhod = (rmNormal, rmDateRoom, rmDate, rmRoom, rmBlocked,rmAllotment,rmImport);

TYPE
  TnewRoomReservationItem = class; // forward
  TReservationExtra = class(TObject)
  private
    FRoomReservationItem: TnewRoomReservationItem;
    FItemID: integer;
    FItem: string;
    FCount: integer;
    FPrice: double;
    FFromDate: TDate;
    FToDate: TDate;
    FDescription: string;
    FID: integer;
    function GetPricePerDay: double;
    function GetTotalPrice: double;
    function GetFromDate: TDate;
    function GetToDate: TDate;
  protected
    procedure SetNewDepartureDate(aNewDepartureDate: TDate);
    procedure SetNewArrivalDate(aNewArrivalDate: TDate);
    procedure AddInvoiceInsert(aExecPlan: TRoomerExecutionPlan);
  public
    constructor Create(aitemID: integer; const aItem: string; const aDesc: string;
                                        aCount: integer; aPrice: double; aFromdate, aToDate: TDate);
    /// <summary> Post reservationExtra to server </summary>
    procedure Post(aUseTransaction: boolean=true);

    function IsAvailable: boolean;

    /// <summary> Calculate the total price of this item.</summary>
    property TotalPrice: double read GetTotalPrice;
    /// <summary> Calculate the total price of this item per day</summary>
    property PricePerDay: double read GetPricePerDay;

    property RoomReservationItem: TnewRoomReservationItem read FRoomReservationItem write FRoomReservationItem;
    property ID: integer read FID write FID;
    property ItemID: integer read FItemID write FItemID;
    property Item: string read FItem write FItem;
    property Description: string read FDescription write FDescription;
    property Count: integer read FCount write FCount;
    property PricePerItemPerDay: double read FPrice write FPrice;
    /// <summary> Startdate of use of this item, if not set (<=0) arrivaldate of roomreservation is assumed </summary>
    property FromDate: TDate read GetFromDate write FFromDate;
    /// <summary> Enddate of use of this item, if not set (<=0) Departuredate of roomreservation is assumed </summary>
    property ToDate: TDate read GetToDate write FToDate;
  end;

  TReservationExtrasList = class(TObjectList<TReservationExtra>)
  private
    FReservationitem: TnewRoomReservationItem;
  protected
    procedure Notify(const Item: TReservationExtra; Action: TCollectionNotification); override;
  public
    constructor Create(aReservationItem: TnewRoomreservationItem); overload;
    function TotalPrice: double;
    /// <summary>Check if ToDate of all extras is not later then new departure date. If so correct this </summary>
    procedure CorrectForNewDepartureDate(aNewDepartureDate: TDate);
    /// <summary>Check if ToDate of all extras is not later then new departure date. If so correct this </summary>
    procedure CorrectForNewArrivalDate(aNewArrivalDate: TDate);

    /// <summary> Add reservationextras from the provided dataset </summary>
    procedure LoadFromDataset(aDataset: TDataset);
    /// <summary> Post all ReservationExtras to server
    procedure Post(aUseTransaction: boolean=true);
    procedure DeleteAllFromDatabase;
    function IsAvailable(aUnavailableList: TStringlist): boolean;
  end;

  TnewRoomReservationItem = class
  private
    FRoomReservation: integer;
    FRoomNumber: string;
    FRoomType: string;
    FPackage : string;
    FArrival: TDate;
    FDeparture: TDate;
    FGuestCount: integer;
    FAvragePrice: Double;
    FAvrageDiscount : Double;
    FRateCount: integer;
    FChildrenCount: integer;
    FInfantCount: integer;
    FPriceCode : string;
    FMainGuestName : string;
    FNotes         : string;
    FRates: TRates;
    FBreakfast: TBreakfastType;
    FBreakfastCost: TAmount;
    FExtraBedCost: Double;
    FExtraBedIncluded: Boolean;
    FExtraBed: Boolean;
    FExtraBedCostGroupAccount: Boolean;
    FManualChannelId: Integer;
    FratePlanCode: String;
    FExpCOT: string;
    FExpTOA: string;
    FExtras: TReservationExtraslist;
    FReservation: integer;

    function getRoomReservation: integer;
    function getRoomNumber: string;
    function getRoomType: string;
    function getPackage: string;
    function getPriceCode: string;
    function getArrival: TDate;
    function getDeparture: TDate;
    function getGuestCount: integer;
    function getAvragePrice: Double;
    function getAvrageDiscount: Double;
    function getRateCount: integer;
    function getChildrenCount: integer;
    function getInfantCount: integer;
    function getMainGuestName: string;
    function getNotes: string;


    procedure SetRoomreservation(Value: integer);
    procedure SetRoomNumber(Value: string);
    procedure SetRoomType(Value: string);
    procedure SetPackage(Value: string);
    procedure SetPriceCode(Value: string);
    procedure SetArrival(Value: TDate);
    procedure SetDeparture(Value: TDate);
    procedure SetGuestCount(Value: integer);
    procedure SetAvragePrice(Value: Double);
    procedure SetAvrageDiscount(Value: Double);
    procedure setRateCount(Value: integer);
    procedure setChildrenCount(Value: integer);
    procedure setInfantCount(Value: integer);
    procedure SetMainGuestName(Value: string);
    procedure SetNotes(Value: string);

    procedure SetExpCOT(const Value: string);
    procedure SetExpTOA(const Value: string);
    // **
  public
    constructor Create(aRoomReservation: integer;
                       aRoomNumber: string;
                       aRoomType: string;
                       aPackage : string;
                       aArrival: TDate;
                       aDeparture: TDate;
                       aGuestCount: integer;
                       aAvragePrice: Double;
                       aAvrageDiscount: Double;
                       aRateCount: integer;
                       aChildrenCount: integer;
                       aInfantCount: integer;
                       aPriceCode : string;
                       aMainGuestName : string;
                       notes : string
                       ); overload;
    constructor Create(const aRoomNumber: string; aArrival: TDate; aDeparture: TDate); overload;

    destructor Destroy; override;
    property Reservation: integer read FReservation write FReservation;

    /// <summary>
    ///   Must be unique. If negative then it represent a temporary roomreservation number, not yet created in the database
    ///  If positive then this is an actual roomreservation number already defined in the database
    /// </summary>
    property RoomReservation: integer   read getRoomReservation write SetRoomreservation    ;
    property RoomNumber     : string    read getRoomNumber      write SetRoomNumber         ;
    property RoomType       : string    read getRoomType        write SetRoomType           ;
    property Package        : string    read getPackage         write SetPackage            ;
    property PriceCode      : string    read getPriceCode       write SetPriceCode          ;
    property Arrival        : TDate     read getArrival         write SetArrival            ;
    property Departure      : TDate     read getDeparture       write SetDeparture          ;

    property GuestCount     : integer   read getGuestCount      write SetGuestCount         ;
    property AvragePrice    : Double    read getAvragePrice     write SetAvragePrice        ;
    property AvrageDiscount : Double    read getAvrageDiscount  write SetAvrageDiscount     ;
    property RateCount      : integer   read getRateCount       write setRateCount          ;
    property ChildrenCount  : integer   read getChildrenCount   write setChildrenCount      ;
    property InfantCount    : integer   read getInfantCount     write setInfantCount        ;
    property MainGuestName  : string    read getMainGuestName   write SetMainGuestName      ;
    property Notes          : string    read getNotes           write SetNotes              ;

    property Breakfast  : TBreakfastType read FBreakfast   write FBreakfast;
    property BreakfastCost  : TAmount read FBreakfastCost   write FBreakfastCost      ;
    property ExtraBed  : Boolean    read FExtraBed   write FExtraBed      ;
    property ExtraBedIncluded  : Boolean    read FExtraBedIncluded   write FExtraBedIncluded      ;
    property ExtraBedCost  : Double    read FExtraBedCost   write FExtraBedCost      ;
    property ExtraBedCostGroupAccount  : Boolean    read FExtraBedCostGroupAccount   write FExtraBedCostGroupAccount      ;

    property Rates         : TRates    read FRates             write FRates                ;

    property ManualChannelId  : Integer read FManualChannelId   write FManualChannelId      ;
    property ratePlanCode  : String     read FratePlanCode      write FratePlanCode         ;
    property ExpTOA: string             read FExpTOA            write SetExpTOA             ;
    property ExpCOT: string             read FExpCOT            write SetExpCOT             ;

    property Extras: TReservationExtraslist read FExtras;

  end;

  /// ///////////////////////////////////////////////////////////////////////////
  // TSelectedRoomItem
  //
  /// ///////////////////////////////////////////////////////////////////////////

  TnewRoomReservationItemsList = class(TObjectList<TnewRoomReservationItem>)
  public
    /// <summary>
    ///   Returns the lowest (negative) used roomreservationnumber - 1, which can be used as a
    ///  temporary roomreservationnumber for newRoomReservationItem
    /// </summary>
    function GetNewTempRoomResNumber: integer;
  end;


  /// ///////////////////////////////////////////////////////////////////////////////////
  /// TSelectedRooms
  ///
  /// //////////////////////////////////////////////////////////////////////////////////

  TnewRoomReservation = class
  private
    FXmlFileName: string;

    FRoomCount: integer;
    FRoomList: TnewRoomReservationItemsList;  {each room in reservation}

    FHotelcode: string;

    function getRoomCount: integer;
  protected
    FReservation: integer;
  public
    constructor Create(aHotelCode: string);
    destructor Destroy; override;

    function getReservationArrival: TDate;
    function getReservationDeparture: TDate;

    function TotalGuests: Integer;
    function TotalPersons: integer;

    property XmlFileName: string read FXmlFileName write FXmlFileName;
    property Hotelcode: string read FHotelcode write FHotelcode;

    function FindRoomFromRoomNumber(RoomNumber: string; StartAt: integer;  caseSensitive: Boolean = false): integer;
    function FindRoomFromRoomReservation(RoomReservation: integer; StartAt: integer): integer;


    property RoomItemsList: TnewRoomReservationItemsList read FRoomList;
    property RoomCount: integer read getRoomCount;

    property ReservationArrival: TDate read getReservationArrival;
    property ReservationDeparture: TDate read getReservationDeparture;
  end;

  /// ////////////////////////////////////////////////////////////////////////////////////////////
  //
  //
  /// ////////////////////////////////////////////////////////////////////////////////////////////

  TNewReservation = class
  private
    FHotelcode: string;
    FnewRoomReservations: TnewRoomReservation;  // i.e roomreservation
    FHomeCustomer: THomeCustomer;
    FShowProfile: Boolean;
    FresMedhod: TResMedhod;
    FIsQuick: Boolean;

    // Values not available until after create
    FPriceFound: Boolean;

    // Hdata parameters
    FConnection: TRoomerConnection;
    FLoglevel: integer;
    FLogPath: string;

    // New 2013-01-14
    FStaff: string;
    FOutOfOrderBlocking: Boolean;
    FSendConfirmationEmail: Boolean;
    FAlertList: TAlertList;
    FMarket: TReservationMarketType;
    FCOnfirmationEmailSent: boolean;
    procedure RemoveRemnants(ResId: Integer);
//    procedure DeleteReservation(aReservation: integer);
  protected
    FReservationId: integer;
  public
//    constructor Create(aHotelCode, Staff: string);  overload;
    constructor Create(const aHotelCode, Staff: string;  const contactAddress1: string = '';
                                                         const contactAddress2: string = '';
                                                         const contactAddress3: string = '';
                                                         const contactAddress4: string = '');

    destructor Destroy; override;

    Function CreateReservation(DeleteResNr : integer=-1; Transactional : Boolean = true) : Boolean;
    procedure SendConfirmationEmailIfNeeded;

    property Hotelcode: string read FHotelcode write FHotelcode;

    property newRoomReservations: TnewRoomReservation read FnewRoomReservations
      write FnewRoomReservations;
    property HomeCustomer: THomeCustomer read FHomeCustomer write FHomeCustomer;

    property ShowProfile: Boolean read FShowProfile write FShowProfile;
    property resMedhod: TResMedhod read FresMedhod write FresMedhod;
    property IsQuick: Boolean read FIsQuick write FIsQuick;

    // ReservationId of newly created reservation, Values not available until after create
    property ReservationId: integer read FReservationId write FReservationId;
    property PriceFound: Boolean read FPriceFound write FPriceFound;

    // Hdata parameters
    property Connection: TRoomerConnection read FConnection write FConnection;
    property loglevel: integer read FLoglevel write FLoglevel;
    property logpath: string read FLogPath write FLogPath;

    property Staff: string read FStaff write FStaff;
    property OutOfOrderBlocking: Boolean read FOutOfOrderBlocking write FOutOfOrderBlocking;
    property SendConfirmationEmail: Boolean read FSendConfirmationEmail write FSendConfirmationEmail;
    property ConfirmationEmailSent: boolean read FCOnfirmationEmailSent;

    property AlertList : TAlertList read FAlertList write FAlertList;

    property Market: TReservationMarketType read FMarket write FMarket;

  end;

implementation

uses
  _glob,
  hData,
  ud,
  uAppGlobal,
  uGuestPortfolioEdit,
  uActivityLogs
  , uFrmBusyMessage
  , uUtils
  , DateUtils
  , uDateUtils
  , Math
  , uSQLUtils, uReservationEmailingDialog, uRoomerIDList
  , uInvoiceDefinitions;

const
  cSTOCKITEM_IMPORTREFERENCE = 'STOCKITEM';

/// ///////////////////////////////////////////////////////////////////////////
// TSelectedRoomItem
/// ///////////////////////////////////////////////////////////////////////////

constructor TnewRoomReservationItem.Create(aRoomReservation: integer;
                                     aRoomNumber: string;
                                     aRoomType: string;
                                     aPackage: string;
                                     aArrival: TDate;
                                     aDeparture: TDate;
                                     aGuestCount: integer;
                                     aAvragePrice: Double;
                                     aAvrageDiscount: Double;
                                     aRateCount: integer;
                                     aChildrenCount: integer;
                                     aInfantCount: integer;
                                     aPriceCode : string;
                                     aMainGuestName : string;
                                     notes : string
                                     );
begin
  inherited Create;
  FExtras := TReservationExtrasList.Create(self);

  setRoomreservation(aRoomReservation);
  setRoomNumber(aRoomNumber);
  setRoomType(aRoomType);
  setPackage(aPackage);
  setArrival(aArrival);
  setDeparture(aDeparture);
  setGuestCount(aGuestCount);
  setAvragePrice(aAvragePrice);
  setAvrageDiscount(aAvrageDiscount);
  setRateCount(aRateCount);
  setChildrenCount(aChildrenCount);
  setInfantCount(aInfantCount);
  setPriceCode(aPriceCode);
  setMainGuestName(aMainGuestName);
  setNotes(notes);
  FRates := TRates.Create('');

  FBreakfast := TBreakfastType.None;
  FBreakfastCost := 0.00;
  FExtraBed := False;
  FExtraBedIncluded := False;
  FExtraBedCost := 0.00;

end;

constructor TnewRoomReservationItem.Create(const aRoomNumber: string; aArrival, aDeparture: TDate);
begin
  Create(0, aRoomNumber, '', '', aArrival, aDeparture, 0, 0, 0, 0, 0, 0, '', '', '');
end;

destructor TnewRoomReservationItem.Destroy;
begin
  FRates.Free;
  FExtras.Free;
  inherited;
end;

function TnewRoomReservationItem.getRateCount: integer;
begin
  result := FRateCount;
end;

function TnewRoomReservationItem.getRoomNumber: string;
begin
  result := FRoomNumber
end;

function TnewRoomReservationItem.getRoomReservation: integer;
begin
  result := FRoomReservation;
end;

function TnewRoomReservationItem.getRoomType: string;
begin
  result := FRoomType;
end;

function TnewRoomReservationItem.getPackage: string;
begin
  result := FPackage;
end;

function TnewRoomReservationItem.getPriceCode: string;
begin
  result := FPriceCode;
end;

function TnewRoomReservationItem.getMainGuestName: string;
begin
  result := copy(FMainGuestName,1,100);
end;

function TnewRoomReservationItem.getNotes: string;
begin
  result := FNotes;
end;


function TnewRoomReservationItem.getArrival: TDate;
begin
  result := FArrival
end;

function TnewRoomReservationItem.getAvragePrice: Double;
begin
  result := FAvragePrice;
end;

function TnewRoomReservationItem.getAvrageDiscount: Double;
begin
  result := FAvrageDiscount;
end;


function TnewRoomReservationItem.getChildrenCount: integer;
begin
  result := FChildrenCount;
end;

function TnewRoomReservationItem.getDeparture: TDate;
begin
  result := FDeparture
end;

function TnewRoomReservationItem.getGuestCount: integer;
begin
  result := FGuestCount;
end;

function TnewRoomReservationItem.getInfantCount: integer;
begin
  result := FInfantCount;
end;

procedure TnewRoomReservationItem.SetGuestCount(Value: integer);
begin
  FGuestCount := Value
end;

procedure TnewRoomReservationItem.setInfantCount(Value: integer);
begin
  FInfantCount := Value;
end;

procedure TnewRoomReservationItem.setRateCount(Value: integer);
begin
  FRateCount := Value;
end;

procedure TnewRoomReservationItem.SetRoomNumber(Value: string);
begin
  FRoomNumber := Value
end;

procedure TnewRoomReservationItem.SetRoomreservation(Value: integer);
begin
  FRoomReservation := Value;
end;

procedure TnewRoomReservationItem.SetRoomType(Value: string);
begin
  FRoomType := Value;
end;

procedure TnewRoomReservationItem.SetPackage(Value: string);
begin
  FPackage := Value;
end;

procedure TnewRoomReservationItem.SetPriceCode(Value: string);
begin
  FPriceCode := Value;
end;

procedure TnewRoomReservationItem.SetMainGuestName(Value: string);
begin
  FMainGuestName := Value;
end;

procedure TnewRoomReservationItem.SetNotes(Value: string);
begin
  FNotes := Value;
end;


procedure TnewRoomReservationItem.SetArrival(Value: TDate);
begin
  FArrival := Value;
  FExtras.CorrectForNewArrivalDate(FArrival);
end;

procedure TnewRoomReservationItem.SetAvragePrice(Value: Double);
begin
  FAvragePrice := Value;
end;

procedure TnewRoomReservationItem.SetAvrageDiscount(Value: Double);
begin
  FAvrageDiscount := Value;
end;

procedure TnewRoomReservationItem.setChildrenCount(Value: integer);
begin
  FChildrenCount := value;
end;

procedure TnewRoomReservationItem.SetDeparture(Value: TDate);
begin
  FDeparture := Value;
  FExtras.CorrectForNewDepartureDate(FArrival);
end;

procedure TnewRoomReservationItem.SetExpCOT(const Value: string);
begin
  FExpCOT := Value;
end;

procedure TnewRoomReservationItem.SetExpTOA(const Value: string);
begin
  FExpTOA := Value;
end;

/// ///////////////////////////////////////////////////////////////////
{ TSelectedRooms }
/// ///////////////////////////////////////////////////////////////////

constructor TnewRoomReservation.Create(aHotelCode: string);
begin
  inherited Create;
  FRoomList := TnewRoomReservationItemsList.Create(True);
  FHotelcode := aHotelCode;
  FRoomCount := 0;
end;

destructor TnewRoomReservation.Destroy;
begin
  FRoomList.Free;
  inherited;
end;

function TnewRoomReservation.getReservationArrival: TDate;
var
  i: integer;
  tmpDate: TDate;
begin
  tmpDate := 0;
  for i := 0 to FRoomList.Count - 1 do
  begin
    if i = 0 then
    begin
      tmpDate := FRoomList[i].FArrival;
    end;

    if FRoomList[i].FArrival < tmpDate then
      tmpDate := FRoomList[i].FArrival;
  end;

  result := tmpDate;
end;

function TnewRoomReservation.getReservationDeparture: TDate;
var
  i: integer;
  tmpDate: TDate;
begin
  tmpDate := 0;
  for i := 0 to FRoomList.Count - 1 do
  begin
    if i = 0 then
    begin
      tmpDate := FRoomList[i].FDeparture;
    end;

    if FRoomList[i].FArrival > tmpDate then
      tmpDate := FRoomList[i].FDeparture;
  end;

  result := tmpDate;
end;


function TnewRoomReservation.FindRoomFromRoomNumber(RoomNumber: string;
  StartAt: integer; caseSensitive: Boolean): integer;
var
  i: integer;
  Room: string;
begin
  result := -1;
  if StartAt > FRoomList.Count - 1 then
    exit;

  if not caseSensitive then
  begin
    RoomNumber := ansiLowercase(RoomNumber);
  end;

  for i := StartAt to FRoomList.Count - 1 do
  begin
    Room := FRoomList[i].FRoomNumber;

    if not caseSensitive then
    begin
      Room := ansiLowercase(Room);
    end;

    if RoomNumber = Room then
    begin
      result := i;
      Break;
    end;
  end;
end;


function TnewRoomReservation.FindRoomFromRoomReservation(RoomReservation: integer; StartAt: integer): integer;
var
  i: integer;
  RoomRes : integer;
begin
  result := -1;
  if StartAt > FRoomList.Count - 1 then
    exit;

  for i := StartAt to FRoomList.Count - 1 do
  begin
    RoomRes := FRoomList[i].FRoomReservation;
    if Roomreservation = RoomRes then
    begin
      result := i;
      Break;
    end;
  end;
end;


function TnewRoomReservation.getRoomCount: integer;
begin
  // Testa
  result := FRoomList.Count;
end;

function TnewRoomReservation.TotalGuests: Integer;
var
  lRoomRes: TnewRoomReservationItem;
begin
  Result := 0;
  for lRoomres in RoomItemsList do
    Result := Result + lRoomRes.GuestCount;
end;

function TnewRoomReservation.TotalPersons: integer;
var
  lRoomRes: TnewRoomReservationItem;
begin
  Result := 0;
  for lRoomres in RoomItemsList do
    Result := Result + lRoomRes.GuestCount + lRoomRes.ChildrenCount + lRoomRes.InfantCount;
end;

/// /////////////////////////////////////////////////////////////////////////////
//
//
/// /////////////////////////////////////////////////////////////////////////////

{ TNewReservation }


constructor TNewReservation.Create(const aHotelCode, Staff: string;
                                                      const contactAddress1: string = '';
                                                      const contactAddress2: string = '';
                                                      const contactAddress3: string = '';
                                                      const contactAddress4: string = '');
begin
  FHotelcode := Hotelcode;
  FnewRoomReservations := TnewRoomReservation.Create(aHotelCode);

  if contactAddress1.IsEmpty then
    FHomeCustomer := THomeCustomer.Create(aHotelCode, hData.ctrlGetString('RackCustomer'))
  else
    FHomeCustomer := THomeCustomer.Create(aHotelCode, '',contactAddress1,contactAddress2,contactaddress3,contactAddress4);
  FReservationId := -1; //hData.RV_SetNewID();

  FShowProfile := false;
  FresMedhod := rmNormal;
  FIsQuick := true;
  FStaff := Staff;

  FConnection := Connection;
  FLoglevel := loglevel;
  FLogPath := logpath;
  FPriceFound := true;

  FAlertList := TAlertList.Create(0, 0, atUNKNOWN);

end;


destructor TNewReservation.Destroy;
begin
  FAlertList.Free;
  FHomeCustomer.Free;
  FNewRoomReservations.Free;
  inherited;
end;


const UPDATE_QUERY = 'INSERT INTO home100.DOORCODE_MESSAGE_SCHEDULE('
        + 'HOTEL_ID, '
        + 'BOOKING_ID, '
        + 'ROOM_RES_ID, '
        + 'FIRST_NAME, '
        + 'LAST_NAME, '
        + 'PHONENUMBER, '
        + 'EMAIL, '
        + 'HOTEL_EMAIL, '
        + 'HOTEL_ERR_EMAIL, '
        + 'DOORID, '
        + 'ARRIVAL_DATE, '
        + 'DEPARTURE_DATE, '
        + 'TIMEZONE, NAME_FOR_MAIL, '
        + 'GENDER_FOR_MAIL'
        + ') '
        + 'VALUES ('
        + ''':hotelId'', '
        + ''':bookingId'', '
        + ''':roomResId'', '
        + ''':firstName'', '
        + ''':lastName'', '
        + ''':phone'', '
        + ''':email'', '
        + ''':hotelEmail'', '
        + ''':hotelErrEmail'', '
        + ''':doorId'', '
        + ''':arrDate'', '
        + ''':depDate'', '
        + ''':tz'', '
        + ''':mailName'', '
        + ''':mailGender'''
        + ')';


procedure TNewReservation.RemoveRemnants(ResId : Integer);
var
  s, s1 : String;
  lPostThreadedData : TPutOrPostDataThreaded;


begin
  frmBusyMessage.ChangeMessage(GetTranslatedText('shTx_Removing_Allotment_Traces'));
  lPostThreadedData := TPutOrPostDataThreaded.Create;
  try
    s := format('resapi/booking/remove/reservation2/%d', [ResId]);
    s1 := format('transactional=%s&reason=%s&request=%s&information=%s&canceltype=%d&makecopy=%s',
                    [BoolToString(False), 'Removing remnants after creating new reservation from allotment', '', '', 0, BoolToString(False)]);
    lPostThreadedData.Post(s, s1, nil);
  finally
    lPostThreadedData.Free;
  end;
end;

procedure TNewReservation.SendConfirmationEmailIfNeeded;
begin
  if SendConfirmationEmail then
    FCOnfirmationEmailSent := SendNewReservationConfirmation(ReservationId);
end;

Function TNewReservation.CreateReservation(DeleteResNr : integer=-1; Transactional : Boolean = true): Boolean;
var
  rSet : TRoomerDataSet;

//  iRoomReservation: integer;
  iLastPerson: integer;

  Customer: string;

  sArrival: string;
  sDeparture: string;
  Arrival: TDate;
  Departure: TDate;

  iDayCount: integer;
  sDate: string;
  lDate: TDate;

  RoomNumber: string;
  isNoRoom: Boolean;
  RoomType: string;
  Package : string;

  sDates: string;

  ReservationArrival: TDate;
  ReservationDeparture: TDate;
  reservationName: string;
  guestName: string;

  Address1: string;
  Address2: string;
  Address3: string;
  Address4: string;
  Country: string;
  Tel1: string;
  Tel2: string;
  Fax: string;

  CustomerEmail: string;
  CustomerWebSite: string;

  ContactName   : string;
  ContactPhone  : string;
  ContactPhone2 : string;
  ContactFax    : string;
  ContactEmail  : string;
  ContactAddress1 : string;
  ContactAddress2 : string;
  ContactAddress3 : string;
  ContactAddress4 : string;
  ContactCountry : string;

  CustPID: string;

  reservationDate: TDate;
  Staff: String;

  ReservationPaymentInfo: string;
  ReservationGeneralInfo: string;
  HiddenInfo: string;

  MarketSegment: string;

  Currency: string;

  lBreakfast: TBreakfastType;
  isGroupInvoice: Boolean;
  RoomStatus: string;

  PriceCode: string;
  MainGuestName : string;

  numGuests    ,
  numChildren ,
  numInfants   : integer;

  Discount: Double;

  RoomPMInfo: string;
  RoomHiddenInfo: string;

  GuestCompany: string;
  GuestType: string;
  GuestInformation: string;
  GuestPID: string;

  // Data Holders
  reservationData    : recReservationHolder;
  invoiceHeadData    : recInvoiceHeadHolder;
  roomReservationData: recRoomReservationHolder;
  roomsDateData      : recRoomsDateHolder;
  personData         : recPersonHolder;
  invoicelineData    : recInvoiceLineHolder;

  // priceNotFound : boolean;

  DayCount: integer;
  Processed: integer;
  FirstDate: TDate;
  LastDate: TDate;

  useStayTax: Boolean;
  useInNationalReport: Boolean;
  channel: integer;
  invRefrence : String;

  ExecutionPlan : TRoomerExecutionPlan;

  contactIsMainGuest : boolean;
  lstReservationActivity : TStringlist;
  lstInvoiceActivity : TStringlist;
  ExpTOA: string;
  ExpCOT: string;
  newRoomReservationItem: TnewRoomReservationItem;
  lRevenue: Double;
  lNewRoomRes: TnewRoomReservationItem;

  procedure init;
  begin
    Currency := FHomeCustomer.Currency;
    Customer := FHomeCustomer.Customer;

    guestName := FHomeCustomer.guestName;
    invRefrence := FHomeCustomer.invRefrence;

    reservationName := FHomeCustomer.reservationName;

    Address1 := FHomeCustomer.Address1;
    Address2 := FHomeCustomer.Address2;
    Address3 := FHomeCustomer.Address3;
    Address4 := FHomeCustomer.Address4;
    Country := FHomeCustomer.Country;

    Tel1 := FHomeCustomer.Tel1;
    Tel2 := FHomeCustomer.Tel2;
    Fax := FHomeCustomer.Fax;

    CustomerEmail := FHomeCustomer.EmailAddress;
    CustomerWebSite := FHomeCustomer.HomePage;

    ContactName   := copy(FHomeCustomer.ContactPerson,1,100);
    ContactPhone  := copy(FHomeCustomer.ContactPhone,1,30);
    ContactPhone2 := copy(FHomeCustomer.ContactMobile,1,30);
    ContactFax    := copy(FHomeCustomer.ContactFax,1,30);
    ContactEmail  := copy(FHomeCustomer.ContactEmail,1,50);
    CustPID       := copy(FHomeCustomer.PID,1,15);
    MarketSegment := copy(FHomeCustomer.MarketSegmentCode,1,5);


    contactAddress1 := copy(FHomeCustomer.contactAddress1,1,100);
    contactAddress2 := copy(FHomeCustomer.contactAddress2,1,100);
    contactAddress3 := copy(FHomeCustomer.contactAddress3,1,100);
    contactAddress4 := copy(FHomeCustomer.contactAddress4,1,100);

    contactCountry := copy(FHomeCustomer.contactCountry,1,2);

    reservationDate := Date;

    ReservationPaymentInfo := FHomeCustomer.ReservationPaymentInfo;
    ReservationGeneralInfo := FHomeCustomer.ReservationGeneralInfo;
    HiddenInfo := '';
    ContactIsMainGuest := FhomeCustomer.contactIsMainGuest;

    if hData.ctrlGetBoolean('BreakfastInclDefault') then
      lBreakFast := TBreakfastType.Included;

    isGroupInvoice := FHomeCustomer.isGroupInvoice;
    RoomStatus := FHomeCustomer.RoomStatus;

    useStayTax := true;
    useInNationalReport := true;
    channel := channels_getDefault();
  end;

  procedure InsertNewReservation;
  begin
    hData.initReservationHolderRec(reservationData, staff);

    reservationData.Reservation := FReservationId;
    Arrival          := FnewRoomReservations.FRoomList[0].FArrival;
    Departure        := FnewRoomReservations.FRoomList[0].FDeparture;;

    reservationData.Arrival   := Arrival;
    reservationData.Departure := Departure;

    reservationData.Customer := Customer;
    reservationData.name     := copy(reservationName,1,100);
    reservationData.Address1 := Address1;
    reservationData.Address2 := Address2;
    reservationData.Address3 := Address3;
    reservationData.Address4 := Address4;
    reservationData.Country  := Country;
    reservationData.Tel1          := Tel1;
    reservationData.Tel2          := Tel2;
    reservationData.Fax           := Fax;
    reservationData.CustomerEmail := CustomerEmail;
    reservationData.CustomerWebSite := CustomerWebSite;
    reservationData.status := RoomStatus;
    reservationData.reservationDate := _db(reservationDate, false);
    reservationData.Staff := FStaff;;
    reservationData.Information := ReservationGeneralInfo;
    reservationData.PMInfo := ReservationPaymentInfo;
    reservationData.HiddenInfo := HiddenInfo;
    reservationData.RoomRentPaid1 := 0.00;
    reservationData.RoomRentPaid2 := 0.00;
    reservationData.RoomRentPaid3 := 0.00;
    reservationData.RoomRentPaymentInvoice := -1;
    reservationData.ContactName     := ContactName;
    reservationData.ContactPhone    := ContactPhone;
    reservationData.ContactPhone2   := ContactPhone2;
    reservationData.ContactFax      := ContactFax;
    reservationData.ContactEmail    := ContactEmail;
    reservationData.ContactAddress1 := ContactAddress1;
    reservationData.ContactAddress2 := ContactAddress2;
    reservationData.ContactAddress3 := ContactAddress3;
    reservationData.ContactAddress4 := ContactAddress4;
    reservationData.ContactIsmainGuest := ContactIsMainGuest;
    reservationData.ContactCountry  := ContactCountry;
    reservationData.CustPID          := CustPID;
    reservationData.MarketSegment    := MarketSegment;
    reservationData.useStayTax       := useStayTax;
    reservationData.channel          := channel;
    reservationData.invRefrence      := invRefrence;
    reservationData.OutOfOrderBlocking  := OutOfOrderBlocking;

    reservationData.Market           := Market;

    ExecutionPlan.AddExec(SQL_UPDATE_NEW_Reservation(reservationData));
    //***Log reservation
    lstReservationActivity.add(CreateReservationActivityLog(g.quser
                                                 ,FReservationId
                                                 ,-1 //Roomreservation
                                                 ,NEW_RESERVATION
                                                 ,'' //old value
                                                 ,reservationData.name //New vlaue
                                                 ,'Refr :'+reservationData.invRefrence //Moreinfo
                                   ));




//    if not hData.SP_INS_Reservation(reservationData, Connection, loglevel,
//      logpath) then
//    begin
//      // **
//    end;
  end;

  procedure InsertNewReservationInvoiceHead;
  begin
    initInvoiceHeadHolderRec(invoiceHeadData);
    invoiceHeadData.Reservation := ReservationId;
    invoiceHeadData.RoomReservation := 0;
    invoiceHeadData.SplitNumber := 0;
    invoiceHeadData.InvoiceNumber := -1;
    invoiceHeadData.InvoiceDate := _db(reservationDate, false);
    invoiceHeadData.Customer := Customer;
    invoiceHeadData.name := copy(reservationName + ', ' + guestName,1,100);
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
    invoiceHeadData.InvoiceType := glb.PMSSettings.InvoiceSettings.DefaultInvoiceAddressType.ToItemIndex;
    invoiceHeadData.ihTmp := '';
    invoiceHeadData.CustPID := CustPID;
    invoiceHeadData.RoomGuest := guestName;
    invoiceHeadData.ihDate := reservationDate;
    invoiceHeadData.ihInvoiceDate := reservationDate;
    invoiceHeadData.ihConfirmDate := 2;
    invoiceHeadData.ihPayDate := reservationDate;
    invoiceHeadData.ihStaff := FStaff;
    invoiceHeadData.ihCurrency := Currency;
    invoiceHeadData.ihCurrencyRate := 1.00;
    invoiceHeadData.ReportDate := '';
    invoiceHeadData.ReportTime := '';
    invoiceHeadData.AggregateCityTax := glb.PMSSettings.InvoiceSettings.AggregateCityTax;

    ExecutionPlan.AddExec(SQL_INS_InvoiceHead(invoiceHeadData));

  end;

var
  s: string;
  ii: integer;
  i: integer;
  line: string;

  tmpDate1, tmpDate2: TDate;
  li: longInt;

  PriceID       : integer;
  RateIndex     : integer;

  averageRate : double;
  avrageDiscount : double;
  rateCount  : integer;

  newID : integer;
  isPercentage : boolean;

  isFinished : Boolean;
  CheckCount : integer;

  TotalGuests : integer;

  lstRRIDs  : TIDList;
  lstGuestIDs   : TIDlist;

  roomnotes : string;
  packageID : integer;

  Item       : string;
  Price        : double;
  numItems     : double;
  Total        : double;
  TotalWOVAT   : double;
  Vat          : double;

  fTmp            : double;
  aYear,aMon,aDay : word;
  iTmp            : integer;
  itemDescription,
  packageDescription : string;
  numItemsMethod : integer;

  rr,rralias : integer;

  rNewSet : TRoomerDataset;
  iProfileId : Integer;

  CurrencyRate : Double;
  ItemInfo: recItemPlusHolder;
  stlRoomsDateData : TStrings;
  doRemoveRemnants : Boolean;
  retries: integer;
begin
  Result := False;
  doRemoveRemnants := False;
  FReservationId := -1;
  CheckCount   := 0;
  Discount     := 0;
  retries      := 0;
  isFinished         := True;
//  iRoomReservation := -1;

  lstInvoiceActivity := TStringList.Create;
  lstReservationActivity := TStringList.Create;

  lstGuestIDs := TIDList.Create;
  lstRRIDs := TIDlist.Create;
  stlRoomsDateData := TStringList.Create;
  ExecutionPlan := d.roomerMainDataSet.CreateExecutionPlan;
  try
    repeat
      try
        if Transactional then
          ExecutionPlan.BeginTransaction;

        TotalGuests := FnewRoomReservations.TotalGuests;

        lstGuestIDs.FillFromString(persons_GetIDs(TotalGuests));

        FReservationId := hData.RV_SetNewID();

        doRemoveRemnants := (DeleteResNr > 0);

        init;
        InsertNewReservation;
        InsertNewReservationInvoiceHead;

        lstRRIDs.FillFromString(RR_GetIDs(FnewRoomReservations.RoomCount));

        for lNewRoomRes in FnewRoomReservations.RoomItemsList do
        begin
          if lNewRoomRes.RoomReservation < 1 then
            lNewRoomRes.RoomReservation := lstRRIDs.ExtractNext;

          lNewRoomRes.Reservation     := FReservationId;

          RoomNumber       := lNewRoomRes.RoomNumber;

          if (RoomNumber <> '') AND (copy(RoomNumber,1,1) <> '<') then  glb.LocateRoom(RoomNumber);

          Arrival          := lNewRoomRes.Arrival;
          Departure        := lNewRoomRes.Departure;;

          RoomType         := lNewRoomRes.RoomType;
          Package          := lNewRoomRes.Package;

//          iRoomReservation := lNewRoomRes.FRoomReservation;

          numGuests        := lNewRoomRes.GuestCount;
          numChildren      := lNewRoomRes.ChildrenCount;
          numInfants       := lNewRoomRes.InfantCount;

          PriceCode     := lNewRoomRes.PriceCode;
          MainGuestName := lNewRoomRes.MainGuestName;

          averageRate     := lNewRoomRes.AvragePrice;
          AvrageDiscount := lNewRoomRes.AvrageDiscount;
          rateCount      := lNewRoomRes.RateCount;

          roomNotes := lNewRoomRes.Notes;

          ExpTOA := lNewRoomRes.ExpTOA;
          ExpCOT := lNewRoomRes.ExpCOT;


          if roomType = '' then
          begin
            RoomType := glb.RoomsSet['RoomType'];//GET_RoomsType_byRoom(RoomNumber);
          end;

          useInNationalReport := true;
          isNoRoom := false;

          if (RoomNumber = '') or (RoomNumber.StartsWith('<')) then // Roomres could have been changed
          begin
            RoomNumber := '<' + inttostr(lNewRoomRes.RoomReservation) + '>';
            isNoRoom := true;
          end else
          begin
            useInNationalReport := glb.RoomsSet.FieldByName('useInNationalReport').AsBoolean;//GET_useInNationalReport_byRoom(RoomNumber);
          end;

          if RoomStatus <> 'B' then
          begin
            if numGuests = 0 then
            begin
              if isNoRoom then
              begin
                numGuests :=  glb.GET_RoomTypeNumberGuests_byRoomType(RoomType);
              end else
              begin
                numGuests := hData.GET_NumberOfGuestsbyRoom(RoomNumber);
              end
            end;
            if numGuests = 0 then numGuests := 2;
          end;


          RoomPMInfo := '';
          RoomHiddenInfo := roomNotes;

          initRoomReservationHolderRec(roomReservationData);

          roomReservationData.ManualChannelId := lNewRoomRes.ManualChannelId;
          roomReservationData.ratePlanCode    := lNewRoomRes.ratePlanCode;
          roomReservationData.RoomReservation := lNewRoomRes.RoomReservation;
          roomReservationData.Room            := RoomNumber;
          roomReservationData.Reservation     := ReservationId;
          roomReservationData.status          := RoomStatus;
          roomReservationData.GroupAccount    := isGroupInvoice;

          roomReservationData.Breakfast       :=  lNewRoomRes.Breakfast;
          roomReservationData.BreakfastPrice  := lNewROomRes.BreakfastCost;

          roomReservationData.Currency        := Currency;
          roomReservationData.Discount        := Discount;
          roomReservationData.PriceType       := PriceCode;
          roomReservationData.Arrival         := Arrival;
          roomReservationData.Departure       := Departure;
          roomReservationData.RoomType        := RoomType;
          roomReservationData.Package         := package;
          roomReservationData.PMInfo          := RoomPMInfo;
          roomReservationData.HiddenInfo      := RoomHiddenInfo;
          roomReservationData.RoomRentPaymentInvoice := -1;
          roomReservationData.rrDescription       := '';;
          roomReservationData.rrIsNoRoom          := isNoRoom;
          roomReservationData.rrRoomAlias         := RoomNumber;
          roomReservationData.rrRoomTypeAlias     := RoomType;
          roomReservationData.useStayTax          := useStayTax;
          roomReservationData.useInNationalReport := useInNationalReport;

          roomReservationData.RoomRentPaid1   := 0.00;
          roomReservationData.RoomRentPaid2   := 0.00;
          roomReservationData.RoomRentPaid3   := 0.00;


          roomReservationData.numGuests   := numGuests;
          roomReservationData.numInfants  := numInfants;
          roomReservationData.numChildren := numChildren;

          roomReservationData.averageRate  := averageRate;
          roomReservationData.rateCount   := rateCount;

          roomReservationData.Discount    := avrageDiscount;

          roomReservationData.RoomPrice1      := 0.00;
          roomReservationData.Price1From      := _db(Arrival, false);
          roomReservationData.Price1To        := _db(Departure, false);
          roomReservationData.RoomPrice2      := 0.00;
          roomReservationData.Price2From      := _db(Arrival, false);
          roomReservationData.Price2To        := _db(Arrival, false);
          roomReservationData.RoomPrice3      := 0.00;
          roomReservationData.Price3From      := _db(Arrival, false);
          roomReservationData.Price3To        := _db(Arrival, false);
          roomReservationData.Hallres         := 0;

          roomReservationData.ExpectedTimeOfArrival := ExpTOA;
          roomReservationData.ExpectedCheckoutTime := ExpCOT;

          ExecutionPlan.AddExec(SQL_UPDATE_RoomReservation(roomReservationData));

    //***Log roomreservation
           lstReservationActivity.add(CreateReservationActivityLog(g.quser
                                                 ,FReservationId
                                                 ,roomReservationData.RoomReservation
                                                 ,NEW_ROOMRESERVATION
                                                 ,'' //old value
                                                 ,roomReservationData.Room //New vlaue
                                                 ,'Roomtype :'+roomReservationData.Roomtype+' Status :'+roomReservationData.Status //Moreinfo
                                   ));

          invoiceHeadData.RoomReservation := lNewRoomRes.RoomReservation;
          ExecutionPlan.AddExec(SQL_INS_InvoiceHead(invoiceHeadData));

          // Now Create RoomsDates  for this room
          stlRoomsDateData.Clear;
          initRoomsDateHolderRec(roomsDateData);
          roomsDateData.Room                 := RoomNumber;
          roomsDateData.RoomType             := RoomType;
          roomsDateData.RoomReservation      := lNewRoomRes.RoomReservation;
          roomsDateData.Reservation          := FReservationId;
          roomsDateData.ResFlag              := RoomStatus;
          roomsDateData.isNoRoom             := false;  {set value}
          roomsDateData.RoomRentBilled       := 0;
          roomsDateData.RoomDiscountBilled   := 0;
          roomsDateData.ItemsBilled          := 0;
          roomsDateData.ItemsUnbilled        := 0;
          roomsDateData.TaxesBilled          := 0;
          roomsDateData.Paid                 := false;
          roomsDateData.Currency             := lNewRoomRes.FRates.getCurrency;   // 'ISK';  {set value}
          roomsDateData.PriceCode            := PriceCode;

          if copy(RoomNumber, 1, 1) = '<' then
            roomsDateData.isNoRoom := true;

          iDayCount := trunc(Departure) - trunc(Arrival);
          for ii := trunc(Arrival) to trunc(Arrival) + iDayCount - 1 do
          begin
            lDate := ii;
            sDate := _db(lDate, false);
            roomsDateData.ADate := sDate;
            RateIndex := lNewRoomRes.FRates.FindRateByDate(ii, 0);

            roomsDateData.isPercentage         := lNewRoomRes.FRates.RateItemsList[RateIndex].GetIsPercentage;   {set value}                                         ;
            roomsDateData.showDiscount         := lNewRoomRes.FRates.RateItemsList[RateIndex].GetShowDiscount;
            roomsDateData.RoomRate             := lNewRoomRes.FRates.RateItemsList[RateIndex].getRate ; {set value}
            roomsDateData.Discount             := lNewRoomRes.FRates.RateItemsList[RateIndex].getDiscount;
            roomsDateData.PriceCode            := lNewRoomRes.FRates.RateItemsList[RateIndex].GetPriceCode;
            roomsDateData.TaxesUnbilled        := 0; {set value}
            roomsDateData.RoomRentUnBilled     := 0; //lNewRoomRes.FRates.RateItemsList[RateIndex].getRate;  //10000;  {set value}
            roomsDateData.RoomDiscountUnBilled := 0;

            stlRoomsDateData.Add(SQL_INS_RoomsDate_Multiple(roomsDateData));
//            ExecutionPlan.AddExec(SQL_INS_RoomsDate(roomsDateData));
          end;

          s := SQL_INS_RoomsDate_1stPart + JoinStringsNoQuote(stlRoomsDateData, ',');
          CopyToClipboard(s);
          ExecutionPlan.AddExec(s);

          if RoomStatus = 'B' then
          begin
            numGuests := 1;
          end;

          if lstGuestIDs.IsEmpty then // correct for erroneous initial count of guest in rare circumstances
            iLastperson := PE_SetNewID()
          else
            iLastPerson := lstGuestIDs.ExtractNext;

          GuestCompany := Customer;
          GuestType := RoomType;
          GuestInformation := '';
          GuestPID := '';


          initPersonHolderFromProfileID(personData, FHomeCustomer.PersonProfileId);
          personData.Person := iLastPerson;
          personData.RoomReservation := lNewRoomRes.RoomReservation;
          personData.Reservation := FReservationId;
          personData.name        := copy(MainGuestName,1,100);
          personData.Surname     := copy(reservationName,1,100);

          personData.CompanyName := FHomeCustomer.reservationName;
          personData.CompAddress1 := Address1;
          personData.CompAddress2 := Address2;
          personData.CompZip := Address3;
          personData.CompCity := Address4;
          personData.CompCountry := Country;
          personData.CompTel := FHomeCustomer.Tel1;
          personData.CompEmail := FHomeCustomer.EmailAddress;

          personData.Address1 := ContactAddress1;
          personData.Address2 := ContactAddress2;
          personData.Address3 := ContactAddress3;
          personData.Address4 := ContactAddress4;
          if not Country.IsEmpty then
          begin
            if personData.Country.Equals(personData.Nationality) then
              personData.Nationality := Country;
            personData.Country := Country;
          end;

          personData.Tel1 := ContactPhone;
          personData.Tel2 := ContactPhone2;
          personData.Email := ContactEmail;

          personData.Company := GuestCompany;
          personData.GuestType := GuestType;
          personData.Information := GuestInformation;
          personData.PID := GuestPID;
          personData.MainName := true;
          personData.Customer := Customer;
          personData.peTmp := '';
          personData.hgrID := -1;
          personData.HallReservation := -1;

          // FirstGuest
          ExecutionPlan.AddExec(SQL_INS_Person(personData));
             lstReservationActivity.add(CreateReservationActivityLog(g.quser
                                                   ,FReservationId
                                                   ,roomReservationData.RoomReservation
                                                   ,CHANGE_NUMBER_OF_GUESTS
                                                   ,'0' //old value
                                                   ,'1' //New vlaue
                                                   ,'Add Main Guest :'+personData.name //Moreinfo
                                     ));


          if numGuests > 1 then
          begin
            for ii := 2 to numGuests do
            begin
              if lstGuestIDs.IsEmpty then // correct for erroneous initial count of guest in rare circumstances
                iLastperson := PE_SetNewID()
              else
                iLastPerson := lstGuestIDs.ExtractNext;
              personData.Person := iLastPerson;
              personData.name := 'RoomGuest';
              personData.MainName := false;
              personData.PersonsProfilesId := 0;

              // rest of the Guests
              ExecutionPlan.AddExec(SQL_INS_Person(personData));
                lstreservationActivity.add(CreateReservationActivityLog(g.quser
                                                       ,FReservationId
                                                       ,roomReservationData.RoomReservation
                                                       ,CHANGE_NUMBER_OF_GUESTS
                                                       ,inttostr(ii-1) //old value
                                                       ,inttostr(ii) //New vlaue
                                                       ,'Add Guest :'+personData.name //Moreinfo
                                         ));

            end;
          end;

          if lNewRoomRes.FExtraBed AND (NOT lNewRoomRes.FExtraBedIncluded) then
          begin
            glb.LocateSpecificRecordAndGetValue('currencies', 'Currency', Currency, 'AValue', CurrencyRate);

            initInvoiceLineHolderRec(InvoicelineData);
            Item := g.qRoomRentItem;
            itemDescription := GetTranslatedText('shTxExtraBedInvoiceText');

            ItemInfo := d.Item_Get_Data(Item);
            Price        := lNewRoomRes.FExtraBedCost;
            numItems     := 1.00; // numGuests.;
            Total        := price*numItems;
            lRevenue     := Total;
            fTmp           := Total / (1 + (ItemInfo.VATPercentage / 100));
            Vat            := Total - ftmp;
            TotalWOVat     := Total - VAT;

            decodedate(now, AYear, AMon, ADay);
            invoiceLineData.ItemID          := Item;
            invoiceLineData.AutoGen         := _GetCurrentTick;
            invoiceLineData.Reservation     := FReservationId;
            if lNewRoomRes.FExtraBedCostGroupAccount then
              invoiceLineData.RoomReservation := 0
            else
              invoiceLineData.RoomReservation := lNewRoomRes.RoomReservation;
            invoiceLineData.PurchaseDate    := date;
            invoiceLineData.InvoiceNumber   := -1;
            invoiceLineData.Description     := itemDescription;
            invoiceLineData.Price           := Price;
            invoiceLineData.Number          := numItems;
            invoiceLineData.VATType         := ItemInfo.VATCode;
            invoiceLineData.Total           := Total;
            invoiceLineData.TotalWOVAT      := totalWOVat;
            invoiceLineData.Vat             := VAT;
            invoiceLineData.CurrencyRate    := CurrencyRate;
            invoiceLineData.Currency        := Currency;
            invoiceLineData.ReportDate      := now;
            invoiceLineData.ReportTime      := '00:00';
            invoiceLineData.Persons         := 0;
            invoiceLineData.Nights          := 0;
            invoiceLineData.BreakfastPrice  := 0.00;
            invoiceLineData.AYear           := aYear;
            invoiceLineData.AMon            := aMon;
            invoiceLineData.ADay            := aDay;
            invoiceLineData.ItemCurrency     := Currency;
            invoiceLineData.ItemCurrencyRate := CurrencyRate;
            invoiceLineData.Discount           := 0.00;
            invoiceLineData.Discount_isPrecent := true;
            invoiceLineData.ImportRefrence     := '';
            invoiceLineData.ImportSource       := '';
            invoiceLineData.Ispackage          := false;
            invoiceLineData.InvoiceIndex       := 0;
            invoiceLineData.Revenue            := lRevenue;
            invoicelineData.VisibleOnInvoice   := True;
            invoicelineData.ilAccountKey      := ItemInfo.AccountKey;
            ExecutionPlan.AddExec(SQL_INS_InvoiceLine(invoiceLineData));
            //***Add invoice log here
               lstInvoiceActivity.add(CreateInvoiceActivityLog(g.quser
                                     ,invoiceLineData.Reservation
                                     ,invoiceLineData.RoomReservation
                                     ,invoiceLineData.SplitNumber
                                     ,ADD_LINE
                                     ,invoiceLineData.ItemID
                                     ,invoiceLineData.Total
                                     ,-1
                                     ,invoiceLineData.Description));

          end;
        end; // for 0 to roomcount

        // Remove previously allocated but unused roomreservation records
        if lstRRIDs.Count > 0 then
        begin
          s :=     ' DELETE FROM ROOMRESERVATION '#10;
          s := s + ' WHERE ROOMRESERVATION IN %s and RESERVATION=0';

          ExecutionPlan.AddExec(Format(s, [_db('(' + lstRRIDs.CommaText) + ')']));
        end;

        if not ExecutionPlan.Execute(ptExec, False, False) then // not Transactional, not Transactional) then
          raise EReservationCreationException.Create(ExecutionPlan.ExecException); // Exception will end trying to create reservation

        if not RV_Exists(FReservationId) then
          raise EReservationIDNotFoundException.CreateFmt('ReservationId %d not found after creation of reservation', [FReservationId]); // Other cause of failure .. will try again

        FAlertList.Reservation := FReservationId;
        FAlertList.postChanges;

{$Optimization Off}
        d.roomerMainDataSet.SystemAddToDoorCodeSchedules(FReservationId);
{$Optimization On}

        for lNewRoomRes in FnewRoomReservations.RoomItemsList do
        begin
          if lNewRoomRes.Package <> '' then
          begin
            rr :=  lNewRoomRes.RoomReservation;
            rrAlias := rr;
            if isGroupInvoice then
              rr  := 0;

            d.roomerMainDataSet.SystempackagesAdd(lNewRoomRes.Package, rr, rrAlias, lNewRoomRes.AvragePrice, lNewRoomRes.Rates.getCurrency);
          end;

          lNewRoomRes.Extras.Post(False); // not Transactional);

        end;

        if FHomeCustomer.CreatePersonProfileId then
        begin
          if FnewRoomReservations.RoomCount > 0 then
          begin
            rNewSet := CreateNewDataset;
            try
              if hData.rSet_bySQL(rNewSet, format('SELECT Person FROM persons WHERE MainName=1 AND RoomReservation=%d', [FnewRoomReservations.RoomItemsList[0].RoomReservation])) then
              begin
                rNewSet.First;
                iProfileId := CreateNewGuest(glb.PersonProfiles, rNewSet['Person']);
                if iProfileId > 0 then
                  cmd_bySQL(format('UPDATE persons SET PersonsProfilesId=%d WHERE MainName=1 AND Reservation=%d', [iProfileId, FReservationId]));
              end;
            finally
              rNewSet.Free;
            end;
          end;
        end;

        if Transactional then
          ExecutionPlan.CommitTransaction;

        isFinished := true;
        result := true;
      except
        on e: Exception do
        begin
          if Transactional then
            ExecutionPlan.RollbackTransaction;

          // Notice that we cannot retry if not within a transaction because we cannot rollback the (partially) succeeded statements
          if (e is EReservationIDNotFoundException) and (retries < 3) and Transactional then
          begin
            inc(retries);
            isFinished := false;
          end
          else //  e is EReservationCreationException or too many retries ot not within a transaction
          begin
            showMessage('Error creating reservation for ' + MainGuestName + ' on ' + dateToStr(Arrival) + #10 + e.message);
            isFinished := True;
            result := false;
          end
        end;
      end;
    until isFinished;

    if result then
    begin
      //Write logs
      for i := 0 to lstReservationActivity.Count-1 do
      begin
        if LstReservationActivity[i] <> '' then
          WriteReservationActivityLog(LstReservationActivity[i]);
      end;

      for i := 0 to lstInvoiceActivity.Count-1 do
      begin
        if LstInvoiceActivity[i] <> '' then
          WriteInvoiceActivityLog(LstInvoiceActivity[i]);
      end;

      SendConfirmationEmailIfNeeded;
    end;

    if doRemoveRemnants then
    begin
      RemoveRemnants(DeleteResNr);
      lstReservationActivity.add(CreateReservationActivityLog(g.quser
                                 ,DeleteResNr
                                 ,0
                                 ,DELETE_RESERVATION
                                 ,'' //old value
                                 ,''
                                 ,Format('Deleting remnants of reservation %d after creating new reservation %d', [DeleteResNr,FReservationId])
                               ));
    end;

  finally
    freeandNil(ExecutionPlan);
    freeandNil(lstGuestIDs);
    freeandNil(lstRRIDs);
    freeAndNil(stlRoomsDateData);
    freeandNil(lstReservationActivity);
    freeandNil(lstInvoiceActivity);
  end;
end;


{ TReservationExtra }

constructor TReservationExtra.Create(aitemID: integer; const aItem: string; const aDesc: string;
                                      aCount: integer; aPrice: double; aFromdate, aToDate: TDate);
begin
  inherited Create;
  FItemID := aitemID;
  FItem := aItem;
  FDescription := aDesc;
  FCount := aCount;
  FPrice := aPrice;
  FFromDate := aFromdate;
  FToDate := aToDate;
end;

function TReservationExtra.GetFromDate: TDate;
begin
  if FFromDate > 0 then
    Result := max(FFromDate, FRoomReservationItem.Arrival)
  else
    Result := FRoomReservationItem.Arrival;
end;

function TReservationExtra.GetPricePerDay: double;
begin
  Result := FCount * PricePerItemPerDay;
end;

function TReservationExtra.GetToDate: TDate;
begin
  if FToDate > 0 then
    Result := min(FToDate, FRoomReservationItem.Departure)
  else
    Result := FRoomReservationItem.Departure
end;

function TReservationExtra.GetTotalPrice: double;
begin
  Result := GetpricePerDay * DaySpan(ToDate, FromDate);
end;

function TReservationExtra.IsAvailable: boolean;
const
  // determine lowest stock in reservation period for this extra ignoring usage from own roomreservation
  cSQL =
         ' select '#10 +
         '   i.itemid, '#10 +
         '   rrs.usedate, '#10 +
         '     i.totalstock - coalesce(sum(rrs.count), 0) as available '#10 +
         '   from stockitems i '#10 +
         '   left outer join roomreservationstockitems rrs on i.itemid=rrs.stockitem '#10 +
         '                    and rrs.usedate >= ''%s''  and rrs.usedate < ''%s'' '#10 +
         '                    and rrs.roomreservation <> %d '#10 +
         '   where i.itemid = %d '#10 +
         '   group by i.itemID, rrs.usedate '#10 +
         '   order by available asc limit 1 ';
var
  rSet: TRoomerDataSet;
begin
  rSet := CreateNewDataset;
  try
    if rset_BySQL(rSet, Format(cSQL, [DateTOSQLString(fromDate), dateToSQLString(ToDate), FRoomReservationitem.FRoomReservation, ItemID])) then
    begin
      rSet.First;
      Result := rSet['available'] >= Count;
    end
    else
      Result := false;
  finally
    rSet.Free;
  end;

end;

procedure TReservationExtra.Post(aUseTransaction: boolean);
const
  cSQL = 'INSERT into roomreservationstockitems (' +
         ' reservation, ' +
         ' roomreservation, ' +
         ' stockitem, ' +
         ' description,  '+
         ' usedate, ' +
         ' count, ' +
         ' currency, ' +
         ' price, ' +
         ' salesdate ' +
         ') VALUES (  ' +
         ' %s, ' +
         ' %s, ' +
         ' %s, ' +
         ' %s, ' +
         ' %s, ' +
         ' %s, ' +
         ' %s, ' +
         ' %s, ' +
         ' %s' +
         ')  ';

var
  lExecPlan: TRoomerExecutionPlan;
  dt: TDate;
begin
  lExecPlan := d.roomerMainDataSet.CreateExecutionPlan;

  try
    dt := FromDate;
    while dt < ToDate do
    begin


      lExecPlan.AddExec(format(cSQL, [ _db(FRoomReservationItem.Reservation),
                               _db(FRoomReservationItem.RoomReservation),
                               _db(ItemID),
                               _db(Description),
                               _db(dt),
                               _db(Count),
                               _db(g.qNativeCurrency),
                               _db(PricePerItemPerDay),
                               _db(now())
                           ]));

      dt := dt + 1;
    end;
    AddInvoiceInsert(lExecPlan);
    lExecPlan.Execute(ptExec, aUseTransaction, aUseTransAction);
  finally
    lExecPlan.Free;
  end;
end;

procedure TReservationExtra.AddInvoiceInsert(aExecPlan: TRoomerExecutionPlan);
var
  invoiceLineData: recInvoiceLineHolder;
  lTotal: double;
  lTypeInfo: TItemTypeInfo;
  lVat: double;
  lTotalWOVat: double;
  lYear, lMon, lDay: Word;
begin
    initInvoiceLineHolderRec(InvoicelineData);
    lTypeInfo := d.Item_Get_ItemTypeInfo(Item);
    lTotal        := TotalPrice;

    lVat            := lTotal - (lTotal / (1 + (lTypeInfo.VATPercentage / 100)));
    lTotalWOVat     := lTotal - lVat;

    decodedate(now, lYear, lMon, lDay);
    invoiceLineData.ItemID          := Item;
    invoiceLineData.AutoGen         := _GetCurrentTick;
    invoiceLineData.Reservation     := FRoomReservationItem.Reservation;
    invoiceLineData.RoomReservation := FRoomReservationItem.FRoomReservation;
    invoiceLineData.RoomReservationAlias := FRoomReservationItem.FRoomReservation;
    invoiceLineData.PurchaseDate    := FromDate;
    invoiceLineData.InvoiceNumber   := -1;
    invoiceLineData.Description     := Description;
    invoiceLineData.Price           := PricePerItemPerDay;
    invoiceLineData.Number          := Count * DaysBetween(FromDate, ToDate);
    invoiceLineData.VATType         := lTypeInfo.VATCode;
    invoiceLineData.Total           := lTotal;
    invoiceLineData.TotalWOVAT      := lTotalWOVat;
    invoiceLineData.Vat             := lVat;
    invoiceLineData.CurrencyRate    := 1;
    invoiceLineData.Currency        := g.qNativeCurrency;
    invoiceLineData.ReportDate      := now;
    invoiceLineData.ReportTime      := '00:00';
    invoiceLineData.Persons         := 0;
    invoiceLineData.Nights          := 0;
    invoiceLineData.BreakfastPrice  := 0.00;
    invoiceLineData.AYear           := lYear;
    invoiceLineData.AMon            := lMon;
    invoiceLineData.ADay            := lDay;
    invoiceLineData.ItemCurrency     := g.qNativeCurrency;
    invoiceLineData.ItemCurrencyRate := 1.00;
    invoiceLineData.Discount           := 0.00;
    invoiceLineData.Discount_isPrecent := true;
    invoiceLineData.ImportRefrence     := cSTOCKITEM_IMPORTREFERENCE;
    invoiceLineData.ImportSource       := '';
    invoiceLineData.Ispackage          := false;
    invoiceLineData.InvoiceIndex          := 0;
    invoiceLineData.revenue            := lTotal;
    invoiceLineData.VisibleOnInvoice   := true;
    aExecPlan.AddExec(SQL_INS_InvoiceLine(invoiceLineData));
end;

procedure TReservationExtra.SetNewArrivalDate(aNewArrivalDate: TDate);
begin
  if (aNewArrivalDate = FRoomReservationItem.Arrival) then
    FFromDate := 0
  else
    FFromDate := Max(FFromDate, aNewArrivalDate);
end;

procedure TReservationExtra.SetNewDepartureDate(aNewDepartureDate: TDate);
begin
  if (aNewDepartureDate = FRoomReservationItem.Departure) then
    FToDate := 0
  else
    FToDate := Min(FTodate, aNewDepartureDate);
end;

{ TReservationExtrasList }

procedure TReservationExtrasList.CorrectForNewArrivalDate(aNewArrivalDate: TDate);
var
  lExtra: TReservationExtra;
begin
  for lExtra in Self do
    lExtra.SetNewArrivalDate(aNewArrivalDate);
end;

procedure TReservationExtrasList.CorrectForNewDepartureDate(aNewDepartureDate: TDate);
var
  lExtra: TReservationExtra;
begin
  for lExtra in Self do
    lExtra.SetNewDepartureDate(aNewDepartureDate);
end;

constructor TReservationExtrasList.Create(aReservationItem: TnewRoomreservationItem);
begin
  Create;
  FReservationitem := aReservationItem;
end;

procedure TReservationExtrasList.DeleteAllFromDatabase;
var cmdList : TList<String>;
begin
  cmdList := TList<String>.Create;
  try
    cmdList.Add( Format('DELETE from roomreservationstockitems WHERE roomreservation=%d', [FReservationitem.RoomReservation]));
    cmdList.Add( Format('DELETE from invoicelines WHERE invoicenumber=-1 and roomreservation=%d and importrefrence=''%s'' ', [FReservationitem.RoomReservation, cSTOCKITEM_IMPORTREFERENCE]));
    d.roomerMainDataSet.SystemFreeExecuteMultiple(cmdList);
  finally
    cmdList.Free;
  end;
end;

function TReservationExtrasList.IsAvailable(aUnavailableList: TStringlist): boolean;
var
  lExtra: TReservationExtra;
begin
  Result := True;
  for lExtra in Self do
  begin
    if not lExtra.IsAvailable then
    begin
      Result := false;
      if assigned(aUnavailableList) then
        aUnavailableList.Add(lExtra.Item);
    end;
  end;
end;

procedure TReservationExtrasList.LoadFromDataset(aDataset: TDataset);
var
  lExtra: TReservationExtra;
  bm: TBookmark;
begin
  Clear;
  aDataset.DisableControls;
  try
    bm := aDataset.Bookmark;
    aDataset.First;
    while not aDataset.Eof do
    begin
      lExtra := TReservationExtra.create(aDataset.FieldByName('itemid').asInteger,
                                         aDataset.FieldByName('item').asString,
                                         aDataset.FieldByName('description').asString,
                                         aDataset.FieldByName('count').AsInteger,
                                         aDataset.FieldByName('priceperitemperday').AsFloat,
                                         aDataset.FieldByName('FromDate').asDateTime,
                                         aDataset.FieldByName('todate').asDateTime);

      Add(lExtra);
      aDataset.Next;
    end;
  finally
    aDataset.Bookmark := bm;
    aDataset.EnableControls;
  end;
end;

procedure TReservationExtrasList.Notify(const Item: TReservationExtra; Action: TCollectionNotification);
begin
  inherited;
  if (Action = TCollectionNotification.cnAdded) then
    Item.RoomReservationItem := FReservationitem;
end;

procedure TReservationExtrasList.Post(aUseTransaction: boolean);
var
  lResExtra: TReservationExtra;
begin
  if aUseTransaction then
    d.roomerMainDataSet.SystemStartTransaction;
  try
    for lResExtra in Self do
      lResExtra.Post(not aUseTransaction);

      if aUseTransAction then
        d.roomerMainDataSet.SystemCommitTransaction;
  except
    d.roomerMainDataSet.SystemRollbackTransaction;
    raise
  end;
end;

function TReservationExtrasList.TotalPrice: double;
var
  lExtra: TReservationExtra;
begin
  Result := 0;
  for lExtra in Self do
    Result := Result + lExtra.TotalPrice;
end;

{ TnewRoomReservationItemsList }

function TnewRoomReservationItemsList.GetNewTempRoomResNumber: integer;
var
  lItem: TnewRoomReservationItem;
begin
  Result := -1;
  for lItem in Self do
    Result := Min(Result, lItem.RoomReservation - 1);
end;

end.
