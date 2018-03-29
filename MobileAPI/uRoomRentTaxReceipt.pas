unit uRoomRentTaxReceipt;

interface

uses
  Spring.Collections.Lists
  , Spring.Collections
  , uRoomerSchema
   , XMLIntf
   , OXmlPDOM, uAmount, uCurrencyConstants
  ;


type

//    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice>
//    <cityTaxItem>CTAX</item>
//    <description>Excl City Tax (5%) ROOMNIGHT</description>
//    <quantity>1</quantity>
//    <currencyCode>EUR</currencyCode>
//    <roomReservationId>203789</roomReservationId>
//    <stayDate>
//      <year>2018</year>
//      <month>MARCH</month>
//      <monthValue>3</monthValue>
//      <era>CE</era>
//      <dayOfMonth>23</dayOfMonth>
//      <dayOfWeek>FRIDAY</dayOfWeek>
//      <dayOfYear>82</dayOfYear>
//      <leapYear>false</leapYear>
//      <chronology>
//        <id>ISO</id>
//        <calendarType>iso8601</calendarType>
//      </chronology>
//    </stayDate>
//    <cityTaxPerNight>11.79</cityTaxPerNight>
//    <roomBasePricePerNight>235.85</roomBasePricePerNight>
//    <cityTaxPerNightExVat>11.79</cityTaxPerNightExVat>
//    <publishedRoomPricePerNight>250.00</publishedRoomPricePerNight>
//    <roomRentVat>14.15</roomRentVat>
//    <overallTotal>261.79</overallTotal>
//    <vatOnCityTax>0.00</vatOnCityTax>
  TRoomRentTaxReceipt = class(TxsdBaseObject)
  private
    FOverallTotal: TAmount;
    FCurrencyCode: TCurrencyCode;
    FRoomRentVAT: TAmount;
    FRoomBasePricePerNight: TAmount;
    FRoomReservation: integer;
    FPublishedRoomPricePerNight: TAmount;
    FQuantity: integer;
    FStayDate: TDate;
    FDescription: string;
    FCityTaxItem: string;
    FVATOnCityTax: TAmount;
    FCitytaxIncludedInRoomPrice: boolean;
    FCityTaxPerNight: TAmount;
    FCityTaxPerNightExVAT: TAmount;
  protected
    class function GetNodeName: string; override;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    destructor Destroy; override;
  published
    property RoomReservation: integer read FRoomReservation write FRoomReservation;
    property CitytaxItem: string read FCityTaxItem write FCityTaxItem;
    property Description: string read FDescription write FDescription;
    property CurrencyCode: TCurrencyCode read FCurrencyCode write FCurrencyCode;
    property StayDate: TDate read FStayDate write FStayDate;
    property CitytaxIncludedInRoomPrice: boolean read FCitytaxIncludedInRoomPrice write FCitytaxIncludedInRoomPrice;
    property Quantity: integer read FQuantity write FQuantity;
    property RoomBasePricePerNight: TAmount read FRoomBasePricePerNight write FRoomBasePricePerNight;
    property PublishedRoomPricePerNight: TAmount read FPublishedRoomPricePerNight write FPublishedRoomPricePerNight;
    property CityTaxPerNight: TAmount read FCityTaxPerNight write FCityTaxPerNight;
    property CityTaxPerNightExVAT: TAmount read FCityTaxPerNightExVAT write FCityTaxPerNightExVAT;
    property RoomRentVAT: TAmount read FRoomRentVAT write FRoomRentVAT;
    property OverallTotal: TAmount read FOverallTotal write FOverallTotal;
    property VATOnCityTax: TAmount read FVATOnCityTax write FVATOnCityTax;
  end;


  TRoomRentTaxReceipts = class(TxsdBaseObjectList<TRoomRentTaxReceipt>)
  public
    class function GetNodeName: string; override;
    class function GetChildNodeName: string; override;
  end;

  TRoomReservationTaxes = class(TxsdBaseObject)
  private
    FReceipts: IList<TRoomRentTaxReceipt>;
    function GetReceipts: TRoomRentTaxReceipts;
    function GetTaxForDate(aDate: TDate): TRoomRentTaxReceipt;
    function GetTotalCityTax: TAmount;
  protected
  public
    constructor Create;
    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    function Count: integer;
    property TaxForDate[aDate: TDate]: TRoomRentTaxReceipt read GetTaxForDate; default;
    property TotalCityTax: TAmount read GetTotalCityTax;
  end;




implementation

uses
  SysUtils
  , XMLUtils
  , uCurrencymanager
  ;

destructor TRoomRentTaxReceipt.Destroy;
begin

  inherited;
end;

class function TRoomRentTaxReceipt.GetNodeName: string;
begin
  result := 'item';
end;

procedure TRoomRentTaxReceipt.SetPropertiesFromXMLNode(const aNode: PXMLNode);
  function lclGetStayDate(const aStaydateNode: PXMLNode): TDate;
  var
    ldateNode: PXMLNode;
    y, m, d: integer;
  begin
    y := 1900;
    m := 1;
    d := 1;
    if aStaydateNode.FindChild('year', lDateNode) then y := StrToIntDef(lDateNode.Text, 0);
    if aStaydateNode.FindChild('monthValue', lDateNode) then m := StrToIntDef(lDateNode.Text, 0);
    if aStaydateNode.FindChild('dayOfMonth', lDateNode) then d := StrToIntDef(lDateNode.Text, 0);
    Result := EncodeDate(y, m, d);
  end;

var
  lNode: PXMLNode;
begin
  inherited;

  if aNode.FindChild('roomReservationId', lNode) then FRoomReservation := StrToIntDef(lNode.Text, 0);
  if aNode.FindChild('description', lNode) then FDescription := lNode.Text;
  if aNode.FindChild('cityTaxItem', lNode) then FCityTaxItem := lNode.Text;
  if aNode.FindChild('currencyCode', lNode) then FCurrencyCode := TCurrencyCode(lNode.Text);
  if aNode.FindChild('quantity', lNode) then FQuantity := StrToIntDef(lNode.Text, 0);
  if aNode.FindChild('stayDate', lNode) then FStayDate := lclGetStayDate(lNode);
  if aNode.FindChild('cityTaxIncludedInRoomPrice', lNode) then FCitytaxIncludedInRoomPrice := lNode.Text.Equals('true');
  if aNode.FindChild('roomBasePricePerNight', lNode) then FRoomBasePricePerNight := TAmount.Create(XMLToFloat(lNode.Text), fCurrencyCode);
  if aNode.FindChild('publishedRoomPricePerNight', lNode) then FPublishedRoomPricePerNight := TAmount.Create(XMLToFloat(lNode.Text), fCurrencyCode);
  if aNode.FindChild('roomRentVat', lNode) then FRoomRentVAT := TAmount.Create(XMLToFloat(lNode.Text), fCurrencyCode);
  if aNode.FindChild('cityTaxPerNight', lNode) then FCityTaxPerNight := TAmount.Create(XMLToFloat(lNode.Text), fCurrencyCode);
  if aNode.FindChild('cityTaxPerNightExVat', lNode) then FCityTaxPerNightExVAT := TAmount.Create(XMLToFloat(lNode.Text), fCurrencyCode);
  if aNode.FindChild('vatOnCityTax', lNode) then FVATOnCityTax := TAmount.Create(XMLToFloat(lNode.Text), fCurrencyCode);
  if aNode.FindChild('overallTotal', lNode) then FOverallTotal := TAmount.Create(XMLToFloat(lNode.Text), fCurrencyCode);

end;

{ TRoomRentTaxReceiptsList }


procedure TRoomReservationTaxes.Clear;
begin
  inherited;
  FReceipts.Clear;
end;

function TRoomReservationTaxes.Count: integer;
begin
  result := FReceipts.Count;
end;

constructor TRoomReservationTaxes.Create;
begin
  FReceipts := TRoomRentTaxReceipts.Create;
end;

function TRoomReservationTaxes.GetReceipts: TRoomRentTaxReceipts;
begin
  result := FReceipts as TRoomRentTaxReceipts;
end;

function TRoomReservationTaxes.GetTaxForDate(aDate: TDate): TRoomRentTaxReceipt;
var
  lPredicate: Spring.TPredicate<TRoomRentTaxReceipt>;
begin
  lPredicate :=  function(const aObject: TRoomRentTaxReceipt): boolean
                              begin
                                Result := aObject.StayDate = aDate;
                              end;

  result := GetReceipts.First(lPredicate);
end;

function TRoomReservationTaxes.GetTotalCityTax: TAmount;
var
  lTotal: TAmount;
begin
  lTotal := 0;
  GetReceipts.ForEach(procedure(const aReceipt: TRoomRentTaxReceipt)
                      begin
                        lTotal:= lTotal + aReceipt.CityTaxPerNight;
                      end);
  Result := lTotal;
end;

procedure TRoomReservationTaxes.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  if aNode.NodeName.Equals(GetReceipts.GetNodeName) then
    GetReceipts.SetPropertiesFromXMLNode(aNode);
end;

{ TRoomRentTaxReceipts }

class function TRoomRentTaxReceipts.GetChildNodeName: string;
begin
  result := 'item';
end;

class function TRoomRentTaxReceipts.GetNodeName: string;
begin
  Result := 'RoomRentTaxReceiptList';
end;

end.
