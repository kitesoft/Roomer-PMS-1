unit uDataBuilder;

interface

uses Generics.Collections,
     Classes,
     SysUtils,
     uSplitUtils,
     uDateUtils,
     strUtils,
     uStringUtils,
     cmpRoomerDataSet,
     Data.Win.ADODB,
     Vcl.Dialogs,
     Vcl.Graphics,
     Forms
     ;


type

  TPackageDeal = class
  public
    RefID : String;
    Package : String;
    Rate: Double;
    constructor Create(_RefId, _Package : String; _Rate : Double);
  end;

  TPersonInfo = class
    PersonId : Integer;
    Title,
    Name,
    Surname,
    Address1,
    Address2,
    Address3,
    Address4,
    Country,
    Tel1,
    Tel2,
    Fax,
    Email,
    GuestGender,
    GuestTitle,
    GuestSocialSecurityNumber,
    GuestPassportNumber,
    GuestNationality,
    GuestProfession,
    GuestCarLicense,
    GuestFax,
    GuestWebsite,
    GuestSkype,
    GuestLinkedIn,
    GuestTwitter,
    GuestFacebook,
    GuestTripAdvisor,
    GuestPrefRoom,
    GuestPrefRoomType,
    GuestSpecialRequests,
    GuestState,
    Information : String;

    GuestSpecialOffers,
    GuestNewsletter,
    CreateGuestProfile : Boolean;

    GuestDateOfBirth : TDate;

    ALREADY_INSERTED : Boolean;
  public
    constructor Create;
  end;

  TRoomInfo = class
    RoomReservation : Integer;
    Room : String;
    Price : Double;
    RoomType : String;
    Status : String;
    Breakfast : Boolean;
    GroupAccount : Boolean;
    Currency : String;

    Discount : Double;
    Percentage : Boolean;

    PriceType : String;


    Persons : TList<TPersonInfo>;
    Children : Integer;
    Infants : Integer;
  public
    Constructor Create;
  end;


  TResInfo = Class
      NewReservation : Boolean;
      Reservation : Integer;
      Arrival : TDateTime;
      Departure : TDateTime;
      Customer : String;
      Name : String;
      Address1 : String;
      Address2 : String;
      Address3 : String;
      Address4 : String;
      Country : String;
      Tel1 : String;
      Tel2 : String;
      Fax : String;
      Status : String;
      ReservationDate : String;
      Staff : String;
      Information : String;
      PMInfo : String;
      HiddenInfo : String;
      RoomRentPaid1 : Double;
      RoomRentPaid2 : Double;
      RoomRentPaid3 : Double;
      RoomRentPaymentInvoice : Integer;
      ContactName : String;
      ContactPhone : String;
      ContactPhone2 : String;
      ContactFax : String;
      ContactAddress1 : String;
      ContactAddress2 : String;
      ContactAddress3 : String;
      ContactAddress4 : String;
      ContactCountry : String;
      ContactEmail : String;
      inputsource : String;
      webconfirmed : String;
      arrivaltime : String;
      srcrequest : String;
      rvTmp : String;
      CustPID : String;
      invRefrence : String;
      marketSegment : String;
      CustomerEmail : String;
      CustomerWebsite : String;
      useStayTax : Boolean;
      channel : String;
      eventsProcessed : Boolean;
      alteredReservation : Boolean;
      externalIds : String;
      dtCreated : TDateTime;
      notificationRead : Boolean;

      persons : Integer;
      Agency : Integer;

      Package : String;

      ////
      RoomInfo : TList<TRoomInfo>;

  public
    constructor Create;

  End;

  TCustInfo = class
    Customer : String;
    Surname : String;
    Name : String;
    CustomerType : String;
    Address1 : String;
    Address2 : String;
    Address3 : String;
    Address4 : String;
    Country : String;
    Tel1 : String;
    Tel2 : String;
    Fax : String;
    DiscountPercent : Double;
    EmailAddress : String;
    ContactPerson : String;
    TravelAgency : Boolean;
    Currency : String;
    PID : String;
    dele : Char;
    pcID : Integer;
    Homepage : String;
    Active : Boolean;
    marketSegment : String;
    StayTaxInclute : Boolean;
    Notes : String;
    Title : String;
    DateOfBirth : TDateTime;
    Nationality : String;
  end;

var header : TStringlist;
    ResList : TList<TResInfo>;
    CustList : TList<TCustInfo>;
    Reservations_Mandatory : TStringList;
    Reservations_AllRoomerFields : TStringList;
    Customers_AllRoomerFields : TStringList;

    packageDeals : TList<TPackageDeal>;

    dsRoomerDataSet : TRoomerDataSet;

procedure PrepareCollect;

function CheckReservationOfLine(line : String) : String;
function NumRoomsOfLine(line : String) : Integer;
procedure CreateStandardReservationsLine(RoomerDataSet : TRoomerDataSet; line : String; _staff : String;
          var PersId : Integer; RoomResList : TList<Integer>;
          defaultCustomer, defaultCustomerPID : String;
          defaultChannel : String;
          SkipIfRoomNumberIsEmpty : Boolean);
procedure CreateStandardCustomerLine(line : String);

procedure start(line : String = ''; _RoomerDataSet : TRoomerDataSet = nil);
function getReservationsSqlList : TStrings;
function getCustomersSqlList : TStrings;

const ROOMER_FIELD_DELIMITER = '|~|';
implementation

uses uUtils, uFloatUtils, uRoomerDataConvertMain, System.Generics.Collections;

const CREATION_DATE='CreationDate';
      ROOM_NUMBER='RoomNumber';
      XROOM_TYPE='RoomType';
      USE_STAY_TAX='UseStayTax';
      XGUEST_FIRST_NAME='GuestFirstName';
      XGUEST_LAST_NAME='GuestLastName';
      XNUMBER_OF_GUESTS='Adults';
      NUMBER_OF_CHILDREN='Children';
      NUMBER_OF_INFANTS='Infants';
      CUSTOMER_NAME='CustomerName';
      CUSTOMER_TEL_NUMBER='CustomerTelNumber';
      CUSTOMER_MOBILE_NUMBER='CustomerMobileNumber';
      CUSTOMER_FAX_NUMBER='CustomerFaxNumber';
      CUSTOMER_ADDRESS_LINE_1='CustomerAddress1';
      CUSTOMER_ADDRESS_LINE_2='CustomerAddress2';
      CUSTOMER_ADDRESS_LINE_3='CustomerZip';
      CUSTOMER_ADDRESS_LINE_4='CustomerCity';
      CUSTOMER_COUNTRY='CustomerCountry';
      CUSTOMER_STATE='CustomerState';
      CUSTOMER_EMAIL='CustomerEmail';
      CUSTOMER_WEBSITE='CustomerWebsite';
      XARRIVAL_DATE='Arrival';
      XDEPARTURE_DATE='Departure';
      XROOM_RATE='AverageRate';
      BREAKFAST_INCLUDED='BreakfastIncluded';
      XCURRENCY='Currency';
      XCUSTOMER_ID='CustomerID';
      RESERVATION_ID='BookingId';
      CHANNEL_ID='ChannelId';
      XCONTACT_NAME='ContactName';
      CONTACT_ADDRESS_LINE_1='ContactAddress1';
      CONTACT_ADDRESS_LINE_2='ContactAddress2';
      CONTACT_ADDRESS_LINE_3='ContactZip';
      CONTACT_ADDRESS_LINE_4='ContactCity';
      CONTACT_COUNTRY='ContactCountry';
      CONTACT_STATE='ContactState';
      CONTACT_EMAIL='ContactEmail';
      CONTACT_TEL_NUMBER='ContactTelNumber';
      CONTACT_MOBILE_NUMBER='ContactMobileNumber';
      CONTACT_FAX_NUMBER='ContactFaxNumber';
      RESERVATION_STATUS='ReservationStatus';

      RESERVATION_PACKAGE='Package';

      NUMBER_OF_ROOMS='NumberOfRooms';
      GUEST_ADDRESS_LINE_1='GuestAddress1';
      GUEST_ADDRESS_LINE_2='GuestAddress2';
      GUEST_ADDRESS_LINE_3='GuestZip';
      GUEST_ADDRESS_LINE_4='GuestCity';
      GUEST_COUNTRY='GuestCountry';
      GUEST_STATE='GuestState';
      GUEST_EMAIL='GuestEmail';
      GUEST_TEL_NUMBER='GuestTelNumber';
      GUEST_MOBILE_NUMBER='GuestMobileNumber';
      GUEST_FAX_NUMBER='GuestFaxNumber';
      CreateGuestProfile='CreateGuestProfile';
      GuestGender='GuestGender';
      GuestTitle='GuestTitle';
      GuestDateOfBirth='GuestDateOfBirth';
      GuestSocialSecurityNumber='GuestSocialSecurityNumber';
      GuestPassportNumber='GuestPassportNumber';
      GuestNationality='GuestNationality';
      GuestProfession='GuestProfession';
      GuestCarLicense='GuestCarLicense';
      GuestFax='GuestFax';
      GuestWebsite='GuestWebsite';
      GuestSkype='GuestSkype';
      GuestLinkedIn='GuestLinkedIn';
      GuestTwitter='GuestTwitter';
      GuestFacebook='GuestFacebook';
      GuestTripAdvisor='GuestTripAdvisor';
      GuestPrefRoom='GuestPrefRoom';
      GuestPrefRoomType='GuestPrefRoomType';
      GuestSpecialOffers='GuestSpecialOffers';
      GuestNewsletter='GuestNewsletter';
      GuestSpecialRequests='GuestSpecialRequests';


      CREATE_CUSTOMER='CreateCustomer';


// ===================== Customer table

      CUST_CUSTOMER = 'Customer';
      CUST_SURNAME = 'Fullname';
      CUST_NAME = 'NOT-USED';
      CUST_CUSTOMER_TYPE = 'CustomerType';
      CUST_ADDRESS_1 = 'Address1';
      CUST_ADDRESS_2 = 'Address2';
      CUST_ADDRESS_3 = 'Zip';
      CUST_ADDRESS_4 = 'City';
      CUST_COUNTRY = 'Country';
      CUST_TEL_1 = 'Tel1';
      CUST_TEL_2 = 'Tel2';
      CUST_FAX = 'Fax';
      CUST_DISCOUNT_PERCENT = 'DiscountPercent';
      CUST_EMAIL = 'EmailAddress';
      CUST_CONTACT = 'ContactPerson';
      CUST_TRAVEL_AGENCY = 'TravelAgency';
      CUST_CURRENCY = 'Currency';
      CUST_PID = 'PID';
      CUST_PCID = 'PCID';
      CUST_HOME_PAGE = 'Homepage';
      CUST_MARKET_SEGMENT = 'marketSegment';
      CUST_STAY_TAX_INCLUDED = 'StayTaxIncluded';
      CUST_NOTES = 'CustomerNotes';
      CUST_TITLE = 'Title';
      CUST_DATE_OF_BIRTH = 'DateOfBirth';
      CUST_NATIONALITY = 'CustomerNationality';

var ReservationIds : TObjectDictionary<String,Integer>;
    rSetLastCustomer : TRoomerDataSet;
    lastCustomerId : String;

procedure PrepareCollect;
begin
  ReservationIds.Free;
  rSetLastCustomer.Free;
  ReservationIds := TObjectDictionary<String,Integer>.Create;
  rSetLastCustomer := nil;
  lastCustomerId := '';
end;

function FindPerson(Firstname, Lastname, Street, City : String) : TPersonInfo; forward;

procedure PrepareConstants;
begin

  Reservations_Mandatory.Add(XROOM_TYPE);
  Reservations_Mandatory.Add(XGUEST_FIRST_NAME);
//  Reservations_Mandatory.Add(XGUEST_LAST_NAME);
  Reservations_Mandatory.Add(XNUMBER_OF_GUESTS);
  Reservations_Mandatory.Add(XARRIVAL_DATE);
  Reservations_Mandatory.Add(XDEPARTURE_DATE);
  Reservations_Mandatory.Add(XROOM_RATE);
  Reservations_Mandatory.Add(XCURRENCY);
  Reservations_Mandatory.Add(XCUSTOMER_ID);
  Reservations_Mandatory.Add(XCONTACT_NAME);
  Reservations_Mandatory.Add(CreateGuestProfile);



  Reservations_AllRoomerFields.Clear;
  Reservations_AllRoomerFields.Add(CREATION_DATE);
  Reservations_AllRoomerFields.Add(ROOM_NUMBER);
  Reservations_AllRoomerFields.Add(XROOM_TYPE);
  Reservations_AllRoomerFields.Add(USE_STAY_TAX);
  Reservations_AllRoomerFields.Add(XGUEST_FIRST_NAME);
  Reservations_AllRoomerFields.Add(XGUEST_LAST_NAME);
  Reservations_AllRoomerFields.Add(XNUMBER_OF_GUESTS);
  Reservations_AllRoomerFields.Add(NUMBER_OF_CHILDREN);
  Reservations_AllRoomerFields.Add(NUMBER_OF_INFANTS);
  Reservations_AllRoomerFields.Add(CUSTOMER_NAME);
  Reservations_AllRoomerFields.Add(CUSTOMER_TEL_NUMBER);
  Reservations_AllRoomerFields.Add(CUSTOMER_MOBILE_NUMBER);
  Reservations_AllRoomerFields.Add(CUSTOMER_FAX_NUMBER);
  Reservations_AllRoomerFields.Add(CUSTOMER_ADDRESS_LINE_1);
  Reservations_AllRoomerFields.Add(CUSTOMER_ADDRESS_LINE_2);
  Reservations_AllRoomerFields.Add(CUSTOMER_ADDRESS_LINE_3);
  Reservations_AllRoomerFields.Add(CUSTOMER_ADDRESS_LINE_4);
  Reservations_AllRoomerFields.Add(CUSTOMER_COUNTRY);
  Reservations_AllRoomerFields.Add(CUSTOMER_STATE);
  Reservations_AllRoomerFields.Add(CUSTOMER_EMAIL);
  Reservations_AllRoomerFields.Add(CUSTOMER_WEBSITE);
  Reservations_AllRoomerFields.Add(XARRIVAL_DATE);
  Reservations_AllRoomerFields.Add(XDEPARTURE_DATE);
  Reservations_AllRoomerFields.Add(XROOM_RATE);
  Reservations_AllRoomerFields.Add(BREAKFAST_INCLUDED);
  Reservations_AllRoomerFields.Add(XCURRENCY);
  Reservations_AllRoomerFields.Add(XCUSTOMER_ID);
  Reservations_AllRoomerFields.Add(RESERVATION_ID);
  Reservations_AllRoomerFields.Add(CHANNEL_ID);
  Reservations_AllRoomerFields.Add(XCONTACT_NAME);
  Reservations_AllRoomerFields.Add(CONTACT_ADDRESS_LINE_1);
  Reservations_AllRoomerFields.Add(CONTACT_ADDRESS_LINE_2);
  Reservations_AllRoomerFields.Add(CONTACT_ADDRESS_LINE_3);
  Reservations_AllRoomerFields.Add(CONTACT_ADDRESS_LINE_4);
  Reservations_AllRoomerFields.Add(CONTACT_COUNTRY);
  Reservations_AllRoomerFields.Add(CONTACT_STATE);
  Reservations_AllRoomerFields.Add(CONTACT_EMAIL);
  Reservations_AllRoomerFields.Add(CONTACT_TEL_NUMBER);
  Reservations_AllRoomerFields.Add(CONTACT_MOBILE_NUMBER);
  Reservations_AllRoomerFields.Add(CONTACT_FAX_NUMBER);
  Reservations_AllRoomerFields.Add(GUEST_ADDRESS_LINE_1);
  Reservations_AllRoomerFields.Add(GUEST_ADDRESS_LINE_2);
  Reservations_AllRoomerFields.Add(GUEST_ADDRESS_LINE_3);
  Reservations_AllRoomerFields.Add(GUEST_ADDRESS_LINE_4);
  Reservations_AllRoomerFields.Add(GUEST_COUNTRY);
  Reservations_AllRoomerFields.Add(GUEST_STATE);
  Reservations_AllRoomerFields.Add(GUEST_EMAIL);
  Reservations_AllRoomerFields.Add(GUEST_TEL_NUMBER);
  Reservations_AllRoomerFields.Add(GUEST_MOBILE_NUMBER);
  Reservations_AllRoomerFields.Add(GUEST_FAX_NUMBER);
  Reservations_AllRoomerFields.Add(CREATE_CUSTOMER);

  Reservations_AllRoomerFields.Add(CreateGuestProfile);
  Reservations_AllRoomerFields.Add(GuestGender);
  Reservations_AllRoomerFields.Add(GuestTitle);
  Reservations_AllRoomerFields.Add(GuestDateOfBirth);
  Reservations_AllRoomerFields.Add(GuestSocialSecurityNumber);
  Reservations_AllRoomerFields.Add(GuestPassportNumber);
  Reservations_AllRoomerFields.Add(GuestNationality);
  Reservations_AllRoomerFields.Add(GuestProfession);
  Reservations_AllRoomerFields.Add(GuestCarLicense);
  Reservations_AllRoomerFields.Add(GuestFax);
  Reservations_AllRoomerFields.Add(GuestWebsite);
  Reservations_AllRoomerFields.Add(GuestSkype);
  Reservations_AllRoomerFields.Add(GuestLinkedIn);
  Reservations_AllRoomerFields.Add(GuestTwitter);
  Reservations_AllRoomerFields.Add(GuestFacebook);
  Reservations_AllRoomerFields.Add(GuestTripAdvisor);
  Reservations_AllRoomerFields.Add(GuestPrefRoom);
  Reservations_AllRoomerFields.Add(GuestPrefRoomType);
  Reservations_AllRoomerFields.Add(GuestSpecialOffers);
  Reservations_AllRoomerFields.Add(GuestNewsletter);
  Reservations_AllRoomerFields.Add(GuestSpecialRequests);



  Customers_AllRoomerFields.Clear;
  Customers_AllRoomerFields.Add(CUST_CUSTOMER);
  Customers_AllRoomerFields.Add(CUST_SURNAME);
  Customers_AllRoomerFields.Add(CUST_NAME);
  Customers_AllRoomerFields.Add(CUST_CUSTOMER_TYPE);
  Customers_AllRoomerFields.Add(CUST_ADDRESS_1);
  Customers_AllRoomerFields.Add(CUST_ADDRESS_2);
  Customers_AllRoomerFields.Add(CUST_ADDRESS_3);
  Customers_AllRoomerFields.Add(CUST_ADDRESS_4);
  Customers_AllRoomerFields.Add(CUST_COUNTRY);
  Customers_AllRoomerFields.Add(CUST_TEL_1);
  Customers_AllRoomerFields.Add(CUST_TEL_2);
  Customers_AllRoomerFields.Add(CUST_FAX);
  Customers_AllRoomerFields.Add(CUST_DISCOUNT_PERCENT);
  Customers_AllRoomerFields.Add(CUST_EMAIL);
  Customers_AllRoomerFields.Add(CUST_CONTACT);
  Customers_AllRoomerFields.Add(CUST_TRAVEL_AGENCY);
  Customers_AllRoomerFields.Add(CUST_CURRENCY);
  Customers_AllRoomerFields.Add(CUST_PID);
  Customers_AllRoomerFields.Add(CUST_PCID);
  Customers_AllRoomerFields.Add(CUST_HOME_PAGE);
  Customers_AllRoomerFields.Add(CUST_MARKET_SEGMENT);
  Customers_AllRoomerFields.Add(CUST_STAY_TAX_INCLUDED);
  Customers_AllRoomerFields.Add(CUST_NOTES);
end;

procedure start(line : String = ''; _RoomerDataSet : TRoomerDataSet = nil);
var container : TStrings;
    i: Integer;
begin
  ResList := TList<TResInfo>.Create;
  CustList := TList<TCustInfo>.Create;
  header := TStringlist.create;
  Reservations_AllRoomerFields := TStringList.Create;
  Reservations_Mandatory := TStringList.Create;
  Customers_AllRoomerFields := TStringList.Create;

  packageDeals := TList<TPackageDeal>.Create;

  dsRoomerDataSet := _RoomerDataSet;

  if line <> '' then
  begin
    container := SplitStringToTStrings(ROOMER_FIELD_DELIMITER, line);
    header.Clear;
    for i := 0 to container.Count - 1 do
      header.Add(LowerCase(container[i]));
  end;

  PrepareConstants;
end;

function RoomerQuotedString(s : String) : String;
begin
  if s = '' then
    s := ''''''
  else
  begin
    if copy(s, 1, 1) <> #39 then
       s := #39 + s;
    if copy(s, length(s), 1) <> #39 then
       s := s + #39;
  end;
  result := s;
end;

function _db(const aString : string)   : string; Overload;
begin
  result := StringReplace(aString, #39, '\' + #39, [rfReplaceAll]);
end;

function _db(const aBool : Boolean)   : string; Overload;
begin
  if aBool then
    result := '1'
  else
    result := '0';
end;

function _db(const aDate : TDateTime)   : string; Overload;
begin
  result := _db(DateToSqlString(aDate));
end;


function getCustomersSqlList : TStrings;
var s : String;
  i: Integer;
  Cust : TCustInfo;
begin
  result := TStringList.Create;
  for i := 0 to CustList.Count - 1 do
  begin
    Cust := CustList[i];
    with Cust do
    begin
    s := 'INSERT INTO customers ' +
         '(Customer, ' +
         'Surname, ' +
         'Name, ' +
         'CustomerType, ' +
         'Address1, ' +
         'Address2, ' +
         'Address3, ' +
         'Address4, ' +
         'Country, ' +
         'Tel1, ' +
         'Tel2, ' +
         'Fax, ' +
         'DiscountPercent, ' +
         'EmailAddress, ' +
         'ContactPerson, ' +
         'TravelAgency, ' +
         'Currency, ' +
         'PID, ' +
         'pcID, ' +
         'Homepage, ' +
         'Active, ' +
         'marketSegment, ' +
         'Notes, ' +
         'Title, ' +
//         'DateOfBirth, ' +
//         'Nationality, ' +
         'StayTaxIncluted) ' +
         'VALUES ' +
         '(''{Customer}'', ' +
         '''{Surname}'', ' +
         '''{Name}'', ' +
         '''{CustomerType}'', ' +
         '''{Address1}'', ' +
         '''{Address2}'', ' +
         '''{Address3}'', ' +
         '''{Address4}'', ' +
         '''{Country}'', ' +
         '''{Tel1}'', ' +
         '''{Tel2}'', ' +
         '''{Fax}'', ' +
         '''{DiscountPercent}'', ' +
         '''{EmailAddress}'', ' +
         '''{ContactPerson}'', ' +
         '''{TravelAgency}'', ' +
         '''{Currency}'', ' +
         '''{PID}'', ' +
         '''{pcID}'', ' +
         '''{Homepage}'', ' +
         '''{Active}'', ' +
         '''{marketSegment}'', ' +
         '''{Notes}'', ' +
         '''{Title}'', ' +
//         '''{DateOfBirth}'', ' +
//         '''{Nationality}'', ' +
         '''{StayTaxIncluted}''); ';
    s :=  ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
          ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
          ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
          ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(s, '{Customer}', Customer),
                '{Surname}', _db(Surname)),
                '{Name}', _db(Name)),
                '{CustomerType}', _db(CustomerType)),
                '{Address1}', _db(Address1)),
                '{Address2}', _db(Address2)),
                '{Address3}', _db(Address3)),
                '{Address4}', _db(Address4)),
                '{Country}', _db(Country)),
                '{Tel1}', _db(Tel1)),
                '{Tel2}', _db(Tel2)),
                '{Fax}', _db(Fax)),
                '{DiscountPercent}', FloatToDBString(DiscountPercent)),
                '{EmailAddress}', _db(EmailAddress)),
                '{ContactPerson}', _db(ContactPerson)),
                '{TravelAgency}', BoolToString_0_1(TravelAgency)),
                '{Currency}', Currency),
                '{PID}', PID),
                '{pcID}', inttostr(pcId)),
                '{Homepage}', _db(HomePage)),
                '{Active}', '1'),
                '{marketSegment}', _db(MarketSegment)),
                '{Notes}', _db(Notes + #13 + 'Roomer Imported: ' + uDateUtils.DateTimeToDBString(now))),
                '{Title}', _db(Title)),
                '{DateOfBirth}', _db(DateOfBirth)),
                '{Nationality}', _db(Nationality)),
                '{StayTaxIncluted}', BoolToString_0_1(StayTaxInclute))
          ;

    end;
//    if i = 0 then
//      ShowMessage(s);
    result.Add(s);
  end;
end;


function getReservationsSqlList : TStrings;
var s : String;
  i, rr, p, d: Integer;
  Res : TResInfo;
  RoomRes : TRoomInfo;
  Pers : TPersonInfo;
  aDate : TDateTime;
begin
  result := TStringList.Create;

  frmRoomerDataConvertMain.lbStatus.Caption := 'Generating SQL statements...'; frmRoomerDataConvertMain.lbStatus.Font.Color := clGreen; frmRoomerDataConvertMain.lbStatus.Update;
  frmRoomerDataConvertMain.prgWorking.Max := ResList.Count;
  frmRoomerDataConvertMain.prgWorking.Position := 0;

  for i := 0 to ResList.Count - 1 do
  begin
    Res := ResList[i];
    if Res.NewReservation then
    begin
      s := 'INSERT INTO reservations ' +
          '(Reservation, ' +
          'Arrival, ' +
          'Departure, ' +
          'Customer, ' +
          'Name, ' +
          'Address1, ' +
          'Address2, ' +
          'Address3, ' +
          'Address4, ' +
          'Country, ' +
          'Tel1, ' +
          'Tel2, ' +
          'Fax, ' +
          'Status, ' +
          'ReservationDate, ' +
          'Staff, ' +
          'Information, ' +
          'PMInfo, ' +
          'HiddenInfo, ' +
          'RoomRentPaid1, ' +
          'RoomRentPaid2, ' +
          'RoomRentPaid3, ' +
          'RoomRentPaymentInvoice, ' +
          'ContactName, ' +
          'ContactPhone, ' +
          'ContactPhone2, ' +
          'ContactFax, ' +
          'ContactAddress1, ' +
          'ContactAddress2, ' +
          'ContactAddress3, ' +
          'ContactAddress4, ' +
          'ContactCountry, ' +
          'ContactEmail, ' +
          'inputsource, ' +
          'webconfirmed, ' +
          'arrivaltime, ' +
          'srcrequest, ' +
          'rvTmp, ' +
          'CustPID, ' +
          'invRefrence, ' +
          'marketSegment, ' +
          'CustomerEmail, ' +
          'CustomerWebsite, ' +
          'useStayTax, ' +
          'channel, ' +
          'eventsProcessed, ' +
          'alteredReservation, ' +
          'externalIds, ' +
          'dtCreated, ' +
          'notificationRead) ' +

          'VALUES ' +
          '( ' +
          '''{Reservation}'', ' +
          '''{Arrival}'', ' +
          '''{Departure}'', ' +
          '''{Customer}'', ' +
          '''{Name}'', ' +
          '''{Address1}'', ' +
          '''{Address2}'', ' +
          '''{Address3}'', ' +
          '''{Address4}'', ' +
          '''{Country}'', ' +
          '''{Tel1}'', ' +
          '''{Tel2}'', ' +
          '''{Fax}'', ' +
          '''{Status}'', ' +
          '''{ReservationDate}'', ' +
          '''{Staff}'', ' +
          '''{Information}'', ' +
          '''{PMInfo}'', ' +
          '''{HiddenInfo}'', ' +
          '''{RoomRentPaid1}'', ' +
          '''{RoomRentPaid2}'', ' +
          '''{RoomRentPaid3}'', ' +
          '''{RoomRentPaymentInvoice}'', ' +
          '''{ContactName}'', ' +
          '''{ContactPhone}'', ' +
          '''{ContactPhone2}'', ' +
          '''{ContactFax}'', ' +
          '''{ContactAddress1}'', ' +
          '''{ContactAddress2}'', ' +
          '''{ContactAddress3}'', ' +
          '''{ContactAddress4}'', ' +
          '''{ContactCountry}'', ' +
          '''{ContactEmail}'', ' +
          '''{inputsource}'', ' +
          '''{webconfirmed}'', ' +
          '''{arrivaltime}'', ' +
          '''{srcrequest}'', ' +
          '''{rvTmp}'', ' +
          '''{CustPID}'', ' +
          '''{invRefrence}'', ' +
          '''{marketSegment}'', ' +
          '''{CustomerEmail}'', ' +
          '''{CustomerWebsite}'', ' +
          '''{useStayTax}'', ' +
          '{channel}, ' +
          '''{eventsProcessed}'', ' +
          '''{alteredReservation}'', ' +
          '''{externalIds}'', ' +
          '''{dtCreated}'', ' +
          '''{notificationRead}''' +
          ');';
        s := ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(
             ReplaceStr(s, '{Reservation}', inttostr(Res.Reservation)),
          '{Arrival}',  dateToSqlString(Res.Arrival)),
          '{Departure}', dateToSqlString(Res.Departure)),
          '{Customer}', Res.Customer),
          '{Name}', _db(Res.Name)),
          '{Address1}', _db(Res.Address1)),
          '{Address2}', _db(Res.Address2)),
          '{Address3}', _db(Res.Address3)),
          '{Address4}', _db(Res.Address4)),
          '{Country}', _db(Res.Country)),
          '{Tel1}', _db(Res.Tel1)),
          '{Tel2}', _db(Res.Tel2)),
          '{Fax}', _db(Res.Fax)),
          '{Status}', Res.Status),
          '{ReservationDate}', Res.ReservationDate),
          '{Staff}', Res.Staff),
          '{Information}', _db(Res.Information + #13 + 'Roomer Imported: ' + uDateUtils.DateTimeToDBString(now))),
          '{PMInfo}', _db(Res.PMInfo)),
          '{HiddenInfo}', _db(Res.HiddenInfo)),
          '{RoomRentPaid1}', '0'),
          '{RoomRentPaid2}', '0'),
          '{RoomRentPaid3}', '0'),
          '{RoomRentPaymentInvoice}', '-1'),
          '{ContactName}', _db(Res.ContactName)),
          '{ContactPhone}', Res.ContactPhone),
          '{ContactPhone2}', Res.ContactPhone2),
          '{ContactFax}', Res.ContactFax),
          '{ContactAddress1}', _db(Res.ContactAddress1)),
          '{ContactAddress2}', _db(Res.ContactAddress2)),
          '{ContactAddress3}', _db(Res.ContactAddress3)),
          '{ContactAddress4}', _db(Res.ContactAddress4)),
          '{ContactCountry}', _db(Res.ContactCountry)),
          '{ContactEmail}', _db(Res.ContactEmail)),
          '{inputsource}', 'I'),
          '{webconfirmed}', Res.webconfirmed),
          '{arrivaltime}', Res.arrivaltime),
          '{srcrequest}', Res.srcrequest),
          '{rvTmp}', Res.rvTmp),
          '{CustPID}', Res.CustPID),
          '{invRefrence}', Res.invRefrence),
          '{marketSegment}', Res.marketSegment),
          '{CustomerEmail}', Res.CustomerEmail),
          '{CustomerWebsite}', Res.CustomerWebsite),
          '{useStayTax}', BoolToString_0_1(Res.useStayTax)),
          '{channel}', '(SELECT ID FROM channels WHERE channelManagerId=''' + _db(Res.channel) + ''' LIMIT 1)' ),
          '{eventsProcessed}', BoolToString_0_1(Res.eventsProcessed)),
          '{alteredReservation}', BoolToString_0_1(Res.alteredReservation)),
          '{externalIds}', Res.externalIds),
          '{dtCreated}', DateTimeToDBString(Res.dtCreated)),
          '{notificationRead}', BoolToString_0_1(Res.notificationRead));

      result.Add(s);
    end;
    // RoomReservations



    for rr := 0 to Res.RoomInfo.Count - 1 do
    begin
      RoomRes := Res.RoomInfo[rr];

      s := 'INSERT INTO roomreservations ' +
           '(RoomReservation, ' +
           'Room, ' +
           'Reservation, ' +
           'Status, ' +
           'GroupAccount, ' +
           'invBreakfast, ' +
           'Currency, ' +
           'Discount, ' +
           'Percentage, ' +
           'PriceType, ' +
           'Arrival, ' +
           'Departure, ' +
           'RoomType, ' +
           'PMInfo, ' +
           'HiddenInfo, ' +
           'RoomRentPaymentInvoice, ' +
           'Hallres, ' +
           'rrTmp, ' +
           'rrDescription, ' +
           'rrIsNoRoom, ' +
           'rrDeparture, ' +
           'rrArrival, ' +
           'rrRoomTypeAlias, ' +
           'rrRoomAlias, ' +
           'useStayTax, ' +
           'useinNationalReport, ' +
           'numGuests, ' +
           'numChildren, ' +
           'numInfants, ' +
           'RateCount, ' +
           'dtCreated, ' +
           'checkoutEventProcessed) ' +
           'VALUES ' +
           '(''{RoomReservation}'', ' +
           '''{Room}'', ' +
           '''{Reservation}'', ' +
           '''{Status}'', ' +
           '''{GroupAccount}'', ' +
           '''{invBreakfast}'', ' +
           '''{Currency}'', ' +
           '''{Discount}'', ' +
           '''{Percentage}'', ' +
           '''{PriceType}'', ' +
           '''{Arrival}'', ' +
           '''{Departure}'', ' +
           '''{RoomType}'', ' +
           '''{PMInfo}'', ' +
           '''{HiddenInfo}'', ' +
           '''{RoomRentPaymentInvoice}'', ' +
           '''{Hallres}'', ' +
           '''{rrTmp}'', ' +
           '''{rrDescription}'', ' +
           '''{rrIsNoRoom}'', ' +
           '''{rrDeparture}'', ' +
           '''{rrArrival}'', ' +
           '''{rrRoomTypeAlias}'', ' +
           '''{rrRoomAlias}'', ' +
           '''{useStayTax}'', ' +
           '''{useinNationalReport}'', ' +
           '''{numGuests1}'', ' +
           '''{numChildren}'', ' +
           '''{numInfants}'', ' +
           '''{RateCount}'', ' +
           '''{dtCreated}'', ' +
           '''{checkoutEventProcessed}'');';

        s := ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(s, '{RoomReservation}', inttostr(RoomRes.RoomReservation)),
          '{Room}',  RoomRes.Room),
          '{Reservation}', inttostr(Res.Reservation)),
          '{Status}', RoomRes.Status),
          '{GroupAccount}', BoolToString_0_1(RoomRes.GroupAccount)),
          '{invBreakfast}', BoolToString_0_1(RoomRes.Breakfast)),
          '{Currency}', RoomRes.Currency),
          '{Discount}', FloatToDBString(RoomRes.Discount)),
          '{Percentage}', BoolToString_0_1(RoomRes.Percentage)),
          '{PriceType}', RoomRes.PriceType),
          '{Arrival}', dateToSqlString(Res.Arrival)),
          '{Departure}', dateToSqlString(Res.Departure)),
          '{RoomType}', RoomRes.RoomType),
          '{PMInfo}', ''),
          '{HiddenInfo}', ''),

          '{RoomRentPaymentInvoice}', '-1'),
          '{Hallres}', '0'),
          '{rrTmp}', ''),
          '{rrDescription}', ''),
          '{rrIsNoRoom}', BoolToString_0_1(RoomRes.Room[1]='<')),
          '{rrDeparture}', dateToSqlString(Res.Departure)),
          '{rrArrival}', dateToSqlString(Res.Arrival)),
          '{rrRoomTypeAlias}', RoomRes.RoomType),
          '{rrRoomAlias}', RoomRes.Room),
          '{useStayTax}', '1'),
          '{useinNationalReport}', '1'),
          '{numGuests1}', inttostr(RoomRes.Persons.Count)),
          '{numChildren}', inttostr(RoomRes.Children)),
          '{numInfants}', inttostr(RoomRes.Infants)),

          '{RateCount}', '1'),
          '{dtCreated}', DateTimeToDBString(Res.dtCreated)),
          '{checkoutEventProcessed}', '0');

      result.Add(s);

      if RoomRes.Persons.Count > 0 then
      begin
        Pers := RoomRes.Persons[0];
        if Pers.CreateGuestProfile then
        begin
          s := 'INSERT INTO personprofiles ' +
          '(MaleFemale, ' +
          'Title, ' +
          'FirstName, ' +
          'Lastname, ' +
          'Nationality, ' +
          'DateOfBirth, ' +
          'SocialSecurityNumber, ' +
          'PassportNumber, ' +
          'PassportExpiry, ' +
          'SpouseName, ' +
          'SpouseBirthdate, ' +
          'CarLicensePlate, ' +
          'ContactPerson, ' +
          'Profession, ' +
          'Room, ' +
          'RoomType, ' +
          'EmailSpecials, ' +
          'EmailNews, ' +
          'Preparation, ' +
          'InvoiceAddress, ' +
          'Address1, ' +
          'Address2, ' +
          'Zip, ' +
          'City, ' +
          'State, ' +
          'Country, ' +
          'TelLandLine, ' +
          'TelMobile, ' +
          'TelFax, ' +
          'Email, ' +
          'Website, ' +
          'Skype, ' +
          'Twitter, ' +
          'LinkedIn, ' +
          'FacebookLink, ' +
          'TripadvisorAccount, ' +
          'Information, ' +
          'FamilyInfo, ' +
          'CustomerCode, ' +
          'CompanyName, ' +
          'CompVATNumber, ' +
          'CompAddress1, ' +
          'CompAddress2, ' +
          'CompZip, ' +
          'CompCity, ' +
          'CompState, ' +
          'CompCountry, ' +
          'CompTel, ' +
          'CompFax, ' +
          'CompEmail) ' +
          'VALUES ' +
          '(''{MaleFemale}'', ' +
          '''{Title}'', ' +
          '''{FirstName}'', ' +
          '''{Lastname}'', ' +
          '''{Nationality}'', ' +
          '''{DateOfBirth}'', ' +
          '''{SocialSecurityNumber}'', ' +
          '''{PassportNumber}'', ' +
          '''{PassportExpiry}'', ' +
          '''{SpouseName}'', ' +
          '''{SpouseBirthdate}'', ' +
          '''{CarLicensePlate}'', ' +
          '''{ContactPerson}'', ' +
          '''{Profession}'', ' +
          '''{Room}'', ' +
          '''{RoomType}'', ' +
          '''{EmailSpecials}'', ' +
          '''{EmailNews}'', ' +
          '''{Preparation}'', ' +
          '''{InvoiceAddress}'', ' +
          '''{Address1}'', ' +
          '''{Address2}'', ' +
          '''{Zip}'', ' +
          '''{City}'', ' +
          '''{State}'', ' +
          '''{Country}'', ' +
          '''{TelLandLine}'', ' +
          '''{TelMobile}'', ' +
          '''{TelFax}'', ' +
          '''{Email}'', ' +
          '''{Website}'', ' +
          '''{Skype}'', ' +
          '''{Twitter}'', ' +
          '''{LinkedIn}'', ' +
          '''{FacebookLink}'', ' +
          '''{TripadvisorAccount}'', ' +
          '''{Information}'', ' +
          '''{FamilyInfo}'', ' +
          '''{CustomerCode}'', ' +
          '''{CompanyName}'', ' +
          '''{CompVATNumber}'', ' +
          '''{CompAddress1}'', ' +
          '''{CompAddress2}'', ' +
          '''{CompZip}'', ' +
          '''{CompCity}'', ' +
          '''{CompState}'', ' +
          '''{CompCountry}'', ' +
          '''{CompTel}'', ' +
          '''{CompFax}'', ' +
          '''{CompEmail}'');';


        s := ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(s, '{MaleFemale}', _db(Pers.GuestGender)),
            '{Title}', _db(Pers.Title)),
            '{FirstName}', _db(Pers.Name)),
            '{Lastname}', _db(Pers.Surname)),
            '{Nationality}', _db(Pers.GuestNationality)),
            '{DateOfBirth}', _db(Pers.GuestDateOfBirth)),
            '{SocialSecurityNumber}', _db(Pers.GuestSocialSecurityNumber)),
            '{PassportNumber}', _db(Pers.GuestPassportNumber)),
            '{PassportExpiry}', _db('1900-01-01')),
            '{SpouseName}', _db('')),
            '{SpouseBirthdate}', _db('1900-01-01')),
            '{CarLicensePlate}', _db(Pers.GuestCarLicense)),
            '{ContactPerson}', _db('')),
            '{Profession}', _db(Pers.GuestProfession)),
            '{Room}', _db(Pers.GuestPrefRoom)),
            '{RoomType}', _db(Pers.GuestPrefRoomType)),
            '{EmailSpecials}', _db(Pers.GuestSpecialOffers)),
            '{EmailNews}', _db(Pers.GuestNewsletter)),
            '{Preparation}', _db(Pers.GuestSpecialRequests)),
            '{InvoiceAddress}', _db('HOME')),
            '{Address1}', _db(Pers.Address1)),
            '{Address2}', _db(Pers.Address2)),
            '{Zip}', _db(Pers.Address3)),
            '{City}', _db(Pers.Address4)),
            '{State}', _db(Pers.GuestState)),
            '{Country}', _db(Pers.Country)),
            '{TelLandLine}', _db(Pers.Tel1)),
            '{TelMobile}', _db(Pers.Tel2)),
            '{TelFax}', _db(Pers.Fax)),
            '{Email}', _db(Pers.Email)),
            '{Website}', _db(Pers.GuestWebsite)),
            '{Skype}', _db(Pers.GuestSkype)),
            '{Twitter}', _db(Pers.GuestTwitter)),
            '{LinkedIn}', _db(Pers.GuestLinkedIn)),
            '{FacebookLink}', _db(Pers.GuestFacebook)),
            '{TripadvisorAccount}', _db(Pers.GuestTripadvisor)),
            '{Information}', _db(Pers.Information)),
            '{FamilyInfo}', _db('')),
            '{CustomerCode}', _db(Res.Customer)),
            '{CompanyName}', _db(Res.Name)),
            '{CompVATNumber}', _db('')),
            '{CompAddress1}', _db('')),
            '{CompAddress2}', _db('')),
            '{CompZip}', _db('')),
            '{CompCity}', _db('')),
            '{CompState}', _db('')),
            '{CompCountry}', _db('00')),
            '{CompTel}', _db('')),
            '{CompFax}', _db('')),
            '{CompEmail}', _db(''));
          result.Add(s);
        end;
      end;

      for p := 0 to RoomRes.Persons.Count - 1 do
      begin
        Pers := RoomRes.Persons[p];

        s := 'INSERT INTO persons ' +
             '(Person, ' +
             'RoomReservation, ' +
             'Reservation, ' +
             'title, ' +
             'Name, ' +
             'Surname, ' +
             'Address1, ' +
             'Address2, ' +
             'Address3, ' +
             'Address4, ' +
             'Country, ' +
             'Company, ' +
             'Tel1, ' +
             'Tel2, ' +
             'Fax, ' +
             'Email, ' +
             'GuestType, ' +
             'Information, ' +
             'PID, ' +
             'MainName, ' +
             'Customer, ' +

             'DateOfBirth, ' +
             'Nationality, ' +
             'SocialSecurityNumber, ' + // SSN
             'PersonalIdentificationId, ' + // Passport

             'peTmp, ' +
             'HallReservation, ' +
             'hgrID) ' +
             'VALUES ' +
             '(''{Person}'', ' +
             '''{RoomReservation}'', ' +
             '''{Reservation}'', ' +
             '''{title}'', ' +
             '''{Name}'', ' +
             '''{Surname}'', ' +
             '''{Address1}'', ' +
             '''{Address2}'', ' +
             '''{Address3}'', ' +
             '''{Address4}'', ' +
             '''{Country}'', ' +
             '''{Company}'', ' +
             '''{Tel1}'', ' +
             '''{Tel2}'', ' +
             '''{Fax}'', ' +
             '''{Email}'', ' +
             '''{GuestType}'', ' +
             '''{Information}'', ' +
             '''{PID}'', ' +
             '''{MainName}'', ' +
             '''{Customer}'', ' +
             '''{DateOfBirth}'', ' +
             '''{Nationality}'', ' +
             '''{SocialSecurityNumber}'', ' +
             '''{PersonalIdentificationId}'', ' +
             '''{peTmp}'', ' +
             '''{HallReservation}'', ' +
             '''{hgrID}'');';

        s := ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(s, '{Person}', inttostr(Pers.PersonId)),
             '{RoomReservation}', inttostr(RoomRes.RoomReservation)),
             '{Reservation}', inttostr(Res.Reservation)),
             '{title}', Pers.Title),
             '{Name}', _db(Pers.Name)),
             '{Surname}', _db(Pers.Surname)),
             '{Address1}', _db(Pers.Address1)),
             '{Address2}', _db(Pers.Address2)),
             '{Address3}', _db(Pers.Address3)),
             '{Address4}', _db(Pers.Address4)),
             '{Country}', _db(Pers.Country)),
             '{Company}', _db(Res.Customer)),
             '{Tel1}', _db(Pers.Tel1)),
             '{Tel2}', _db(Pers.Tel2)),
             '{Fax}', _db(Pers.Fax)),
             '{Email}', _db(Pers.Email)),
             '{GuestType}', ''),
             '{Information}', _db(Pers.Information)),
             '{PID}', inttostr(Pers.PersonId)),
             '{MainName}', BoolToString_0_1(p=0)),
             '{Customer}', Res.Customer),

             '{DateOfBirth}', _db(pers.GuestDateOfBirth)),
             '{Nationality}', _db(pers.GuestNationality)),
             '{SocialSecurityNumber}', _db(Pers.GuestSocialSecurityNumber)),
             '{PersonalIdentificationId}', _db(Pers.GuestPassportNumber)),


             '{peTmp}', ''),
             '{HallReservation}', '-1'),
             '{hgrID}', '-1');


        result.Add(s);
      end;


      for d := Trunc(Res.Arrival) to Trunc(Res.Departure) - 1 do
      begin
        aDate := d;

        s := 'INSERT INTO roomsdate ' +
             '(ADate, ' +
             'Room, ' +
             'RoomType, ' +
             'RoomReservation, ' +
             'Reservation, ' +
             'ResFlag, ' +
             'rdTmp, ' +
             'updated, ' +
             'isNoRoom, ' +
             'RoomRentBilled, ' +
             'RoomRentUnBilled, ' +
             'RoomDiscountBilled, ' +
             'RoomDiscountUnBilled, ' +
             'ItemsBilled, ' +
             'ItemsUnbilled, ' +
             'TaxesBilled, ' +
             'TaxesUnbilled, ' +
             'PriceCode, ' +
             'RoomRate, ' +
             'Currency, ' +
             'Discount, ' +
             'isPercentage, ' +
             'showDiscount, ' +
             'Paid, ' +
             'confirmAmount, ' +
             'confirmCurrencyRate, ' +
             'invoicenumber, ' +
             'confirmDiscount, ' +
             'confirmTax) ' +
             'VALUES ' +
             '(''{ADate}'', ' +
             '''{Room}'', ' +
             '''{RoomType}'', ' +
             '''{RoomReservation}'', ' +
             '''{Reservation}'', ' +
             '''{ResFlag}'', ' +
             '''{rdTmp}'', ' +
             '''{updated}'', ' +
             '''{isNoRoom}'', ' +
             '''{RoomRentBilled}'', ' +
             '''{RoomRentUnBilled}'', ' +
             '''{RoomDiscountBilled}'', ' +
             '''{RoomDiscountUnBilled}'', ' +
             '''{ItemsBilled}'', ' +
             '''{ItemsUnbilled}'', ' +
             '''{TaxesBilled}'', ' +
             '''{TaxesUnbilled}'', ' +
             '''{PriceCode}'', ' +
             '''{RoomRate}'', ' +
             '''{Currency}'', ' +
             '''{Discount}'', ' +
             '''{isPercentage}'', ' +
             '''{showDiscount}'', ' +
             '''{Paid}'', ' +
             '''{confirmAmount}'', ' +
             '''{confirmCurrencyRate}'', ' +
             '''{invoicenumber}'', ' +
             '''{confirmDiscount}'', ' +
             '''{confirmTax}''); ';

        s := ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(ReplaceStr(
             ReplaceStr(s, '{ADate}', dateToSqlString(d)),
             '{Room}', RoomRes.Room),
             '{RoomType}', RoomRes.RoomType),
             '{RoomReservation}', inttostr(RoomRes.RoomReservation)),
             '{Reservation}', inttostr(Res.Reservation)),
             '{ResFlag}', RoomRes.Status),
             '{rdTmp}', ''),
             '{updated}', '0'),
             '{isNoRoom}', BoolToString_0_1(RoomRes.Room[1]='<')),
             '{RoomRentBilled}', '0'),
             '{RoomRentUnBilled}', '0'),
             '{RoomDiscountBilled}', '0'),
             '{RoomDiscountUnBilled}', '0'),
             '{ItemsBilled}', '0'),
             '{ItemsUnbilled}', '0'),
             '{TaxesBilled}', '0'),
             '{TaxesUnbilled}', '0'),
             '{PriceCode}', 'RACK'),
             '{RoomRate}', FloatToDBString(RoomRes.Price)),
             '{Currency}', 'EUR'),
             '{Discount}', '0'),
             '{isPercentage}', '1'),
             '{showDiscount}', '1'),
             '{Paid}', '0'),
             '{confirmAmount}', '0'),
             '{confirmCurrencyRate}', '1'),
             '{invoicenumber}', '-1'),
             '{confirmDiscount}', '0'),
             '{confirmTax}', '0');

        result.Add(s);
      end;


    end;

    frmRoomerDataConvertMain.prgWorking.StepIt; frmRoomerDataConvertMain.prgWorking.Update;
    frmRoomerDataConvertMain.Breathe(i);

  end;
end;

function IsInHeader(list : TStringList; s : String) : Integer;
var
  i: Integer;
begin
  result := -1;
  for i := 0 to list.Count - 1 do
    if Lowercase(list[i]) = Lowercase(s) then
    begin
      result := i;
      break;
    end;
end;

function GetContainerValues(container : TStrings) : String;
var s : String;
begin
  Result := '';
  for s IN container do
    Result := Result + #13 + s;
end;

function valueOfName(valueName, defaultValue : String; container : TStrings) : String;
var i: Integer;
    nameLowercase : String;
begin
  try
    result := defaultValue;
    nameLowercase := Lowercase(valueName);
    i := isInHeader(header, nameLowercase);
    if i >= 0  then
    begin
      if i > container.Count - 1 then
        ShowMessage('Container index of "' + valueName + '" is wrong: ' + ' (' + inttostr(i) + ')' + #13#13 + GetContainerValues(container))
      else
        result := container[i];
    end else
      result := defaultValue;
  except
    on e: Exception do
      ShowMessage('Error in valueofName: ' + valueName + ' (' + inttostr(i) + ')' + #13#13 + #13#13 + e.Message);
  end;
end;

function getViaSql(sql : String) : TRoomerDataSet;
begin
  Assert(dsRoomerDataSet <> nil, 'RoomerDataSet is not allowed to be [nil]');
  result := dsRoomerDataSet.CreateNewDataset;

  result.CommandType := cmdText;
  result.CommandText := sql;
  result.open(false);

end;


function GetName(container : TStrings) : String;
var temp : String;
begin
  result := valueOfName(XGUEST_FIRST_NAME, '', container);
  temp := valueOfName(XGUEST_LAST_NAME, '', container);
  if result = '' then
    result := temp
  else
    if temp <> '' then
      result := result + ' ' + temp;
end;

function GetUnknownFields(container : TStrings) : String;
var i,
    index : Integer;
    fieldName, fieldValue : String;
begin
  result := '';
  try
  for i := 0 to header.Count - 1 do
  begin
    fieldName := header[i];
    if trim(fieldName) <> '' then
    begin
      index := IsInHeader(Reservations_AllRoomerFields,fieldName);
      if index < 0 then
      begin
        fieldValue := valueOfName(fieldName, '', container);
        if fieldValue <> '' then
        begin
          try result := result + fieldName + ': ' + fieldValue + #13#10; except end;
        end;
      end;
    end;
  end;
  except

  end;
end;

function FilterZeroAsEmpty(s : String) : String;
begin
  if trim(s) = '0' then
    result := ''
  else
    result := s;
end;

function AlreadyInList(sCusto : String) : Boolean;
var i : Integer;
begin
  result := False;
  for i := 0 to CustList.Count - 1 do
    if CustList[i].Customer = sCusto then
    begin
      result := True;
      Break;
    end;
end;

procedure CreateStandardCustomerLine(line : String);
var container : TStrings;
    i: Integer;
    Cust : TCustInfo;
begin
    container := SplitStringToTStrings(ROOMER_FIELD_DELIMITER, line);
    Cust := TCustInfo.Create;
    with Cust do
    begin
      Customer := valueOfName(CUST_CUSTOMER, '', container);

      if AlreadyInList(Customer) then exit;

      Surname := valueOfName(CUST_SURNAME, '', container);
      Name := valueOfName(CUST_NAME, '', container);
      CustomerType := valueOfName(CUST_CUSTOMER_TYPE, '', container);   // ---
      Address1 := valueOfName(CUST_ADDRESS_1, '', container);
      Address2 := valueOfName(CUST_ADDRESS_2, '', container);
      Address3 := valueOfName(CUST_ADDRESS_3, '', container);
      Address4 := valueOfName(CUST_ADDRESS_4, '', container);
      Country := COPY(valueOfName(CUST_COUNTRY, '', container), 1, 2);
      Tel1 := valueOfName(CUST_TEL_1, '', container);
      Tel2 := valueOfName(CUST_TEL_2, '', container);
      Fax := valueOfName(CUST_FAX, '', container);
      DiscountPercent := StrToFloatDef(valueOfName(CUST_DISCOUNT_PERCENT, '', container), 0);
      EmailAddress := valueOfName(CUST_EMAIL, '', container);
      ContactPerson := valueOfName(CUST_CONTACT, '', container);
      TravelAgency := LowerCase(valueOfName(CUST_TRAVEL_AGENCY, 'false', container))='true';
      Currency := valueOfName(CUST_CURRENCY, '', container);
      PcId := StrToIntDef(valueOfName(CUST_PCID, '', container), 0);    // ---
      PId := valueOfName(CUST_PID, '', container);                      // ---
      Homepage := valueOfName(CUST_HOME_PAGE, '', container);
      marketSegment := valueOfName(CUST_MARKET_SEGMENT, '', container); // ---
      StayTaxInclute := LowerCase(valueOfName(CUST_STAY_TAX_INCLUDED, 'false', container))='true';
      Notes := valueOfName(CUST_NOTES, '', container);
      Title := valueOfName(CUST_TITLE, '', container);
      DateOfBirth := SqlStringToDate(valueOfName(CUST_DATE_OF_BIRTH, '1900-01-01', container));
      Nationality := valueOfName(CUST_NATIONALITY, '00', container);
    end;

    CustList.Add(Cust);
end;

function CustInList(s : String) : Boolean;
var
  i: Integer;
begin
  result := False;
  for i := 0 to CustList.Count - 1 do
    if CustList[i].Customer = s then
    begin
      result := True;
      Break;
    end;
end;

procedure CreateReservationCustomerLine(line : String);
var container : TStrings;
    i: Integer;
    Cust : TCustInfo;
    temp : String;
    rSet : TRoomerDataSet;
begin
    container := SplitStringToTStrings(ROOMER_FIELD_DELIMITER, line);
    temp := valueOfName(XCUSTOMER_ID, '', container);
    if CustInList(temp) then
      exit;

    rSet := getViaSql(format('SELECT * FROM customers WHERE customer=''%s''', [temp]));
    try
      rSet.First;
      if rSet.Eof then
      begin
        Cust := TCustInfo.Create;
        with Cust do
        begin
          Customer := valueOfName(XCUSTOMER_ID, '', container);
          Surname := valueOfName(CUSTOMER_NAME, '', container);
          Name := ''; // valueOfName(CUST_NAME, '', container);
          CustomerType := valueOfName(CUST_CUSTOMER_TYPE, '', container);   // ---
          Address1 := valueOfName(CUSTOMER_ADDRESS_LINE_1, '', container);
          Address2 := valueOfName(CUSTOMER_ADDRESS_LINE_2, '', container);
          Address3 := valueOfName(CUSTOMER_ADDRESS_LINE_3, '', container);
          Address4 := valueOfName(CUSTOMER_ADDRESS_LINE_4, '', container);
          Country := COPY(valueOfName(CUSTOMER_COUNTRY, '', container), 1, 2);
          Tel1 := valueOfName(CUSTOMER_TEL_NUMBER, '', container);
          Tel2 := valueOfName(CUSTOMER_MOBILE_NUMBER, '', container);
          Fax := valueOfName(CUSTOMER_FAX_NUMBER, '', container);
          DiscountPercent := 0.00;
          EmailAddress := valueOfName(CUSTOMER_EMAIL, '', container);
          ContactPerson := valueOfName(XCONTACT_NAME, '', container);
          TravelAgency := false; // StrToIntDef(valueOfName(CUST_TRAVEL_AGENCY, '', container), 0) = 1;
          Currency := valueOfName(CURRENCY, '', container);
          PcId := StrToIntDef(valueOfName(XCUSTOMER_ID, '', container), 0);    // ---
          PId := valueOfName(XCUSTOMER_ID, '', container);                      // ---
          Homepage := valueOfName(CUST_HOME_PAGE, '', container);
          marketSegment := valueOfName(CUST_MARKET_SEGMENT, '', container); // ---
          StayTaxInclute := false; // StrToIntDef(valueOfName(CUST_STAY_TAX_INCLUDED, '', container), 0) = 1;
          Notes := valueOfName(CUST_NOTES, '', container);
          Title := valueOfName(CUST_TITLE, '', container);
          DateOfBirth := SqlStringToDate(valueOfName(CUST_TITLE, '1900-01-01', container));
          Nationality := valueOfName(CUST_NATIONALITY, '00', container);
        end;

        CustList.Add(Cust);
      end;
    finally
      FreeAndNil(rSet);
    end;
end;

function CheckReservationOfLine(line : String) : String;
var container : TStrings;
    i, idx : Integer;
    fieldValue : String;
begin
  result := '';
  container := SplitStringToTStrings(ROOMER_FIELD_DELIMITER, line);
  for i := 0 to Reservations_Mandatory.Count - 1 do
  begin
    idx := IsInHeader(header, Reservations_Mandatory[i]);
    if idx >= 0 then
    begin
      fieldValue := valueOfName(Reservations_Mandatory[i], '', container);
      if fieldValue = '' then
      begin
        if result = '' then
          result := Reservations_Mandatory[i]
        else
          result := result + ',' + Reservations_Mandatory[i];
      end;
    end else
    begin
      if result = '' then
        result := Reservations_Mandatory[i]
      else
        result := result + ',' + Reservations_Mandatory[i];
    end;
  end;
end;

function NumRoomsOfLine(line : String) : Integer;
var container : TStrings;
begin
  container := SplitStringToTStrings(ROOMER_FIELD_DELIMITER, line);
  result := StrToIntDef(valueOfName(NUMBER_OF_ROOMS, '1', container),1);
end;

procedure CreateStandardReservationsLine(RoomerDataSet : TRoomerDataSet; line : String; _staff : String;
          var PersId : Integer; RoomResList : TList<Integer>;
          defaultCustomer, defaultCustomerPID : String;
          defaultChannel : String;
          SkipIfRoomNumberIsEmpty : Boolean);

var container : TStrings;
    Res : TResInfo;
    i: Integer;
    Person : TPersonInfo;
    RoomRes : TRoomInfo;
    Temp : String;
    customerId,
    customerPID,
    custAddr1,
    custAddr2,
    custAddr3,
    custAddr4,
    custCountry,
    custTel1,
    custTel2,
    custFax,
    custEmail : String;

    iRoomCounter, numRooms, l: Integer;

    ResId, RoomResId : Integer;

    BookingId : String;
    oldId : Integer;

    _NewReservation : Boolean;
begin
    container := SplitStringToTStrings(ROOMER_FIELD_DELIMITER, line);
    try
      if SkipIfRoomNumberIsEmpty then
      begin
        temp := valueOfName(ROOM_NUMBER, '', container);
        if (temp = '') then
          exit;
      end;

      BookingId := valueOfName(RESERVATION_ID, '', container);
      if (BookingId <> '') AND ReservationIds.TryGetValue(BookingId, oldId) then
      begin
        ResId := oldId;
        _NewReservation := False;
      end else
      begin
        ResId := RoomerDataSet.SystemNewReservationId;
        _NewReservation := True;
      end;

      if (BookingId <> '') AND (NOT ReservationIds.TryGetValue(BookingId, oldId)) then
          ReservationIds.AddOrSetValue(BookingId, ResId);
      Res := TResInfo.Create;
      With Res do
      begin
        NewReservation := _NewReservation;
        Reservation := ResId;
        externalIds := BookingId;
        invRefrence := BookingId;
        Arrival := SqlStringToDate(valueOfName(XARRIVAL_DATE, dateToSqlString(trunc(now)), container));
        Departure := SqlStringToDate(valueOfName(XDEPARTURE_DATE, dateToSqlString(trunc(now)), container));

        temp := valueOfName(XCUSTOMER_ID, '', container);
        if temp = '' then
        begin
          temp := defaultCustomer;
        end;
        CustomerId := temp;

        if (NOT Assigned(rSetLastCustomer)) OR (CustomerId <> lastCustomerId) then
        begin
          rSetLastCustomer := getViaSql(format('SELECT * FROM customers WHERE customer=''%s''', [CustomerId]));
          lastCustomerId := CustomerId;
        end;

        rSetLastCustomer.First;
        if NOT rSetLastCustomer.Eof then
        begin
          Customer := CustomerId;
          CustomerPID := rSetLastCustomer['PID'];
          Name := rSetLastCustomer['Surname'];
          Address1 := rSetLastCustomer['Address1'];
          Address2 := rSetLastCustomer['Address2'];
          Address3 := rSetLastCustomer['Address3'];
          Address4 := rSetLastCustomer['Address4'];
          Country := rSetLastCustomer['Country'];
          Tel1 := rSetLastCustomer['Tel1'];
          Tel2 := rSetLastCustomer['Tel2'];
          Fax := rSetLastCustomer['Tel2'];
        end else
        begin
          Customer := CustomerId;
          CustomerPID := defaultCustomerPID;
          Temp := valueOfName(CUSTOMER_NAME, '', container);
          if Temp='' then
            Temp := getName(container);

          Name := Temp;
          Address1 := FilterZeroAsEmpty(valueOfName(CUSTOMER_ADDRESS_LINE_1, '', container));
          Address2 := FilterZeroAsEmpty(valueOfName(CUSTOMER_ADDRESS_LINE_2, '', container));
          Address3 := FilterZeroAsEmpty(valueOfName(CUSTOMER_ADDRESS_LINE_3, '', container));
          Address4 := FilterZeroAsEmpty(valueOfName(CUSTOMER_ADDRESS_LINE_4, '', container));
          Country := FilterZeroAsEmpty(valueOfName(CUSTOMER_COUNTRY, '', container));
          Tel1 := FilterZeroAsEmpty(valueOfName(CUSTOMER_TEL_NUMBER, '', container));
          Tel2 := FilterZeroAsEmpty(valueOfName(CUSTOMER_MOBILE_NUMBER, '', container));
          Fax := FilterZeroAsEmpty(valueOfName(CUSTOMER_MOBILE_NUMBER, '', container));
        end;
        Status := valueOfName(RESERVATION_STATUS, 'P', container);
        Status := IIF(Trim(Status)='', 'P', Status);
        ReservationDate := valueOfName(CREATION_DATE, dateToSqlString(trunc(now)), container);
        Staff := _staff;
        Information := GetUnknownFields(container); // container[5];
        PMInfo := '';
        HiddenInfo := '';
        RoomRentPaid1 := 0;
        RoomRentPaid2 := 0;
        RoomRentPaid3 := 0;
        RoomRentPaymentInvoice := -1;;

        temp := valueOfName(XCONTACT_NAME, '', container);
        if temp = '' then
          ContactName := getName(container)
        else
          ContactName := temp;

        ContactPhone := FilterZeroAsEmpty(valueOfName(CONTACT_TEL_NUMBER, '', container));
        ContactPhone2 := FilterZeroAsEmpty(valueOfName(CONTACT_MOBILE_NUMBER, '', container));
        ContactFax := FilterZeroAsEmpty(valueOfName(CONTACT_FAX_NUMBER, '', container));
        ContactAddress1 := FilterZeroAsEmpty(valueOfName(CONTACT_ADDRESS_LINE_1, '', container));
        ContactAddress2 := FilterZeroAsEmpty(valueOfName(CONTACT_ADDRESS_LINE_2, '', container));
        ContactAddress3 := FilterZeroAsEmpty(valueOfName(CONTACT_ADDRESS_LINE_3, '', container));
        ContactAddress4 := FilterZeroAsEmpty(valueOfName(CONTACT_ADDRESS_LINE_4, '', container));
        ContactCountry := FilterZeroAsEmpty(valueOfName(CONTACT_COUNTRY, '', container));
        ContactEmail := FilterZeroAsEmpty(valueOfName(CONTACT_EMAIL, '', container));
        inputsource := 'I';
        webconfirmed := '';
        arrivaltime := '12:00';
        srcrequest := '';
        rvTmp := '';

        temp := valueOfName(XCUSTOMER_ID, '', container);
        if temp = '' then
           temp := defaultCustomerPID;
        CustPID := temp;


        marketSegment := 'NULL';
        CustomerEmail := valueOfName(CUSTOMER_EMAIL, '', container);
        CustomerWebsite := valueOfName(CUSTOMER_WEBSITE, '', container);
        temp := LowerCase(valueOfName(USE_STAY_TAX, 'true', container));
        useStayTax := (temp = 'true') OR (temp = '');

        temp := valueOfName(CHANNEL_ID, defaultChannel, container);
        channel := temp;

        eventsProcessed := true;
        alteredReservation := false;
        dtCreated := SqlStringToDate(valueOfName(CREATION_DATE, dateToSqlString(now), container));
        notificationRead := true;

        persons := StrToIntDef(valueOfName(XNUMBER_OF_GUESTS, '1', container),1);


        numRooms := StrToIntDef(valueOfName(NUMBER_OF_ROOMS, '1', container),1);

        for iRoomCounter := 1 to numRooms do
        begin
          RoomResId := RoomResList[iRoomCounter - 1];// RoomerDataSet.SystemNewRoomReservationId;

         // RoomReservations
          RoomRes := TRoomInfo.Create;
          RoomInfo.Add(RoomRes);
          RoomInfo[iRoomCounter - 1].RoomReservation := RoomResId;
          RoomInfo[iRoomCounter - 1].Price := LocalizedFloatValue(valueOfName(XROOM_RATE, '0', container));

          RoomRes.Children := StrToIntDef(valueOfName(NUMBER_OF_CHILDREN, '0', container),0);
          RoomRes.Infants := StrToIntDef(valueOfName(NUMBER_OF_INFANTS, '0', container),0);

          Package := valueOfName(RESERVATION_PACKAGE, '', container);
          if (Package <> '') AND (invRefrence <> '') then
          begin
            PackageDeals.Add(TPackageDeal.Create(invRefrence, Package, RoomInfo[iRoomCounter - 1].Price));
          end;

          temp := valueOfName(ROOM_NUMBER, '', container);

          RoomInfo[iRoomCounter - 1].RoomType := valueOfName(XROOM_TYPE, '', container);
          RoomInfo[iRoomCounter - 1].Status := valueOfName(RESERVATION_STATUS, 'P', container);;
          RoomInfo[iRoomCounter - 1].Status := IIF(Trim(RoomInfo[iRoomCounter - 1].Status)='', 'P', Status);

          if (temp = '') OR (RoomInfo[iRoomCounter - 1].Status='C') then
            RoomInfo[iRoomCounter - 1].Room := format('<%d>', [RoomResId])
          else
            RoomInfo[iRoomCounter - 1].Room := temp;

          RoomInfo[iRoomCounter - 1].Breakfast := Lowercase(valueOfName(BREAKFAST_INCLUDED, 'true', container))='true';
          RoomInfo[iRoomCounter - 1].GroupAccount := false;

          RoomInfo[iRoomCounter - 1].Currency := valueOfName(XCURRENCY, 'EUR', container);
          RoomInfo[iRoomCounter - 1].Discount := 0.00;
          RoomInfo[iRoomCounter - 1].Percentage := true;

          RoomInfo[iRoomCounter - 1].PriceType := '';

         // Persons
          for i := 1 to persons do
          begin
            PersId := PersId + 1;

            Person := nil; // FindPerson(GetName(container), '',
                           // FilterZeroAsEmpty(valueOfName(GUEST_ADDRESS_LINE_1, '', container)),
                           // FilterZeroAsEmpty(valueOfName(GUEST_ADDRESS_LINE_4, '', container)));

            if NOT Assigned(Person) then
            begin
              Person := TPersonInfo.Create;
              Person.PersonId := PersId;
              Person.Title := '';
              Person.Name := GetName(container);
              Person.Surname := '';
              Person.Address1 := FilterZeroAsEmpty(valueOfName(GUEST_ADDRESS_LINE_1, '', container));
              Person.Address2 := FilterZeroAsEmpty(valueOfName(GUEST_ADDRESS_LINE_2, '', container));
              Person.Address3 := FilterZeroAsEmpty(valueOfName(GUEST_ADDRESS_LINE_3, '', container));
              Person.Address4 := FilterZeroAsEmpty(valueOfName(GUEST_ADDRESS_LINE_4, '', container));
              Person.Country := FilterZeroAsEmpty(valueOfName(GUEST_COUNTRY, '', container));
              Person.Tel1 := FilterZeroAsEmpty(valueOfName(GUEST_TEL_NUMBER, '', container));
              Person.Tel2 := FilterZeroAsEmpty(valueOfName(GUEST_MOBILE_NUMBER, '', container));
              Person.Fax := FilterZeroAsEmpty(valueOfName(GUEST_FAX_NUMBER, '', container));
              Person.Email := FilterZeroAsEmpty(valueOfName(GUEST_EMAIL, '', container));
              Person.Information := '';

              Person.GuestGender := FilterZeroAsEmpty(valueOfName(GuestGender, '', container));
              Person.GuestTitle := FilterZeroAsEmpty(valueOfName(GuestTitle, '', container));
              Person.GuestSocialSecurityNumber := FilterZeroAsEmpty(valueOfName(GuestSocialSecurityNumber, '', container));
              Person.GuestPassportNumber := FilterZeroAsEmpty(valueOfName(GuestPassportNumber, '', container));
              Person.GuestNationality := FilterZeroAsEmpty(valueOfName(GuestNationality, '00', container));
              Person.GuestProfession := FilterZeroAsEmpty(valueOfName(GuestProfession, '', container));
              Person.GuestCarLicense := FilterZeroAsEmpty(valueOfName(GuestCarLicense, '', container));
              Person.GuestFax := FilterZeroAsEmpty(valueOfName(GuestFax, '', container));
              Person.GuestWebsite := FilterZeroAsEmpty(valueOfName(GuestWebsite, '', container));
              Person.GuestSkype := FilterZeroAsEmpty(valueOfName(GuestSkype, '', container));
              Person.GuestLinkedIn := FilterZeroAsEmpty(valueOfName(GuestLinkedIn, '', container));
              Person.GuestTwitter := FilterZeroAsEmpty(valueOfName(GuestTwitter, '', container));
              Person.GuestFacebook := FilterZeroAsEmpty(valueOfName(GuestFacebook, '', container));
              Person.GuestTripAdvisor := FilterZeroAsEmpty(valueOfName(GuestTripAdvisor, '', container));
              Person.GuestPrefRoom := FilterZeroAsEmpty(valueOfName(GuestPrefRoom, '', container));
              Person.GuestPrefRoomType := FilterZeroAsEmpty(valueOfName(GuestPrefRoomType, '', container));
              Person.GuestSpecialRequests := FilterZeroAsEmpty(valueOfName(GuestSpecialRequests, '', container));
              Person.GuestState := FilterZeroAsEmpty(valueOfName(GUEST_STATE, '', container));

              Person.GuestSpecialOffers := FilterZeroAsEmpty(LowerCase(valueOfName(GuestSpecialOffers, '', container))) = 'true';
              Person.GuestNewsletter := FilterZeroAsEmpty(LowerCase(valueOfName(GuestNewsletter, '', container))) = 'true';
              Person.CreateGuestProfile := FilterZeroAsEmpty(LowerCase(valueOfName(CreateGuestProfile, '', container))) = 'true';

              Person.GuestDateOfBirth := SqlStringToDate(valueOfName(GuestDateOfBirth, '1900-01-01', container));

            end;

            RoomInfo[iRoomCounter - 1].Persons.Add(Person);
          end;

        end;

      end;

      if Lowercase(valueOfName(CREATE_CUSTOMER, 'false', container)) = 'true' then
      begin
        CreateReservationCustomerLine(line);
      end;


      ResList.Add(Res)

    finally
      container.Free;
    end;

end;


function FindPerson(Firstname, Lastname, Street, City : String) : TPersonInfo;
var iRes, iRoom, iPers : Integer;
    Pers : TPersonInfo;
begin
  result := nil;
  Firstname := Uppercase(Firstname);
  Lastname := Uppercase(Lastname);
  Street := Uppercase(Street);
  City := Uppercase(City);
  for iRes := 0 to ResList.Count - 1 do
    for iRoom := 0 to ResList[iRes].RoomInfo.Count - 1 do
      for iPers := 0 to ResList[iRes].RoomInfo[iRoom].Persons.Count - 1 do
      begin
        Pers := ResList[iRes].RoomInfo[iRoom].Persons[iPers];
        if (Uppercase(Pers.Name) = Firstname) AND
           (Uppercase(Pers.Surname) = Lastname) AND
           (Uppercase(Pers.Address1) = Street) AND
           (Uppercase(Pers.Address4) = City) then
        begin
          result := Pers;
          exit;
        end;

      end;
end;

{ TRoomInfo }

constructor TRoomInfo.Create;
begin
  Persons := TList<TPersonInfo>.Create;
end;

{ TResInfo }

constructor TResInfo.Create;
begin
  NewReservation := True;
  RoomInfo := TList<TRoomInfo>.Create;
end;

{ TPackageDeal }

constructor TPackageDeal.Create(_RefId, _Package: String; _Rate : Double);
begin
  RefId := _RefId;
  Package := _Package;
  Rate := _Rate;
end;


{ TPersonInfo }

constructor TPersonInfo.Create;
begin
  ALREADY_INSERTED := False;
end;


initialization
  ReservationIds := TObjectDictionary<String,Integer>.Create;
finalization
  ReservationIds.Free;


end.
