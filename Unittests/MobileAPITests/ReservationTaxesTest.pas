unit ReservationTaxesTest;


interface

uses
  TestFramework
  , uRoomRentTaxReceipt
  , Spring.Collections
  ;

type

  TRoomRentTaxReceiptFromXMLTest = class(TTestCase)
  private
    FTaxes: TRoomReservationTaxes;
  public
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestSetupTearDown;
    procedure TestReadXML;
  end;


implementation

uses
  SysUtils
  , uCurrencyManager
  , uAmount
  ;

const
{$REGION 'XML contents'}
    cXML =
      '<RoomRentTaxReceiptList xmlns=""> '#10+
      '  <item> '#10+
      '    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice> '#10+
      '    <cityTaxItem>CTAX</cityTaxItem> '#10+
      '    <description>Excl City Tax (5%) ROOMNIGHT</description> '#10+
      '    <quantity>1</quantity> '#10+
      '    <currencyCode>EUR</currencyCode> '#10+
      '    <roomReservationId>203789</roomReservationId> '#10+
      '    <stayDate> '#10+
      '      <year>2018</year> '#10+
      '      <month>MARCH</month> '#10+
      '      <monthValue>3</monthValue> '#10+
      '      <era>CE</era> '#10+
      '      <dayOfMonth>23</dayOfMonth> '#10+
      '      <dayOfWeek>FRIDAY</dayOfWeek> '#10+
      '      <dayOfYear>82</dayOfYear> '#10+
      '      <leapYear>false</leapYear> '#10+
      '      <chronology> '#10+
      '        <id>ISO</id> '#10+
      '        <calendarType>iso8601</calendarType> '#10+
      '      </chronology> '#10+
      '    </stayDate> '#10+
      '    <cityTaxPerNight>11.79</cityTaxPerNight> '#10+
      '    <roomBasePricePerNight>235.85</roomBasePricePerNight> '#10+
      '    <cityTaxPerNightExVat>11.79</cityTaxPerNightExVat> '#10+
      '    <publishedRoomPricePerNight>250.00</publishedRoomPricePerNight> '#10+
      '    <roomRentVat>14.15</roomRentVat> '#10+
      '    <overallTotal>261.79</overallTotal> '#10+
      '    <vatOnCityTax>0.00</vatOnCityTax> '#10+
      '  </item> '#10+
      '  <item> '#10+
      '    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice> '#10+
      '    <cityTaxItem>CTAX</cityTaxItem> '#10+
      '    <description>Excl City Tax (5%) ROOMNIGHT</description> '#10+
      '    <quantity>1</quantity> '#10+
      '    <currencyCode>EUR</currencyCode> '#10+
      '    <roomReservationId>203789</roomReservationId> '#10+
      '    <stayDate> '#10+
      '      <year>2018</year> '#10+
      '      <month>MARCH</month> '#10+
      '      <monthValue>3</monthValue> '#10+
      '      <era>CE</era> '#10+
      '      <dayOfMonth>24</dayOfMonth> '#10+
      '      <dayOfWeek>SATURDAY</dayOfWeek> '#10+
      '      <dayOfYear>83</dayOfYear> '#10+
      '      <leapYear>false</leapYear> '#10+
      '      <chronology> '#10+
      '        <id>ISO</id> '#10+
      '        <calendarType>iso8601</calendarType> '#10+
      '      </chronology> '#10+
      '    </stayDate> '#10+
      '    <cityTaxPerNight>14.15</cityTaxPerNight> '#10+
      '    <roomBasePricePerNight>283.02</roomBasePricePerNight> '#10+
      '    <cityTaxPerNightExVat>14.15</cityTaxPerNightExVat> '#10+
      '    <publishedRoomPricePerNight>300.00</publishedRoomPricePerNight> '#10+
      '    <roomRentVat>16.98</roomRentVat> '#10+
      '    <overallTotal>314.15</overallTotal> '#10+
      '    <vatOnCityTax>0.00</vatOnCityTax> '#10+
      '  </item> '#10+
      '  <item> '#10+
      '    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice> '#10+
      '    <cityTaxItem>CTAX</cityTaxItem> '#10+
      '    <description>Excl City Tax (5%) ROOMNIGHT</description> '#10+
      '    <quantity>1</quantity> '#10+
      '    <currencyCode>EUR</currencyCode> '#10+
      '    <roomReservationId>203789</roomReservationId> '#10+
      '    <stayDate> '#10+
      '      <year>2018</year> '#10+
      '      <month>MARCH</month> '#10+
      '      <monthValue>3</monthValue> '#10+
      '      <era>CE</era> '#10+
      '      <dayOfMonth>25</dayOfMonth> '#10+
      '      <dayOfWeek>SUNDAY</dayOfWeek> '#10+
      '      <dayOfYear>84</dayOfYear> '#10+
      '      <leapYear>false</leapYear> '#10+
      '      <chronology> '#10+
      '        <id>ISO</id> '#10+
      '        <calendarType>iso8601</calendarType> '#10+
      '      </chronology> '#10+
      '    </stayDate> '#10+
      '    <cityTaxPerNight>14.62</cityTaxPerNight> '#10+
      '    <roomBasePricePerNight>292.45</roomBasePricePerNight> '#10+
      '    <cityTaxPerNightExVat>14.62</cityTaxPerNightExVat> '#10+
      '    <publishedRoomPricePerNight>310.00</publishedRoomPricePerNight> '#10+
      '    <roomRentVat>17.55</roomRentVat> '#10+
      '    <overallTotal>324.62</overallTotal> '#10+
      '    <vatOnCityTax>0.00</vatOnCityTax> '#10+
      '  </item> '#10+
      '  <item> '#10+
      '    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice> '#10+
      '    <cityTaxItem>CTAX</cityTaxItem> '#10+
      '    <description>Excl City Tax (5%) ROOMNIGHT</description> '#10+
      '    <quantity>1</quantity> '#10+
      '    <currencyCode>EUR</currencyCode> '#10+
      '    <roomReservationId>203789</roomReservationId> '#10+
      '    <stayDate> '#10+
      '      <year>2018</year> '#10+
      '      <month>MARCH</month> '#10+
      '      <monthValue>3</monthValue> '#10+
      '      <era>CE</era> '#10+
      '      <dayOfMonth>26</dayOfMonth> '#10+
      '      <dayOfWeek>MONDAY</dayOfWeek> '#10+
      '      <dayOfYear>85</dayOfYear> '#10+
      '      <leapYear>false</leapYear> '#10+
      '      <chronology> '#10+
      '        <id>ISO</id> '#10+
      '        <calendarType>iso8601</calendarType> '#10+
      '      </chronology> '#10+
      '    </stayDate> '#10+
      '    <cityTaxPerNight>15.10</cityTaxPerNight> '#10+
      '    <roomBasePricePerNight>301.89</roomBasePricePerNight> '#10+
      '    <cityTaxPerNightExVat>15.10</cityTaxPerNightExVat> '#10+
      '    <publishedRoomPricePerNight>320.00</publishedRoomPricePerNight> '#10+
      '    <roomRentVat>18.11</roomRentVat> '#10+
      '    <overallTotal>335.10</overallTotal> '#10+
      '    <vatOnCityTax>0.00</vatOnCityTax> '#10+
      '  </item> '#10+
      '  <item> '#10+
      '    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice> '#10+
      '    <cityTaxItem>CTAX</cityTaxItem> '#10+
      '    <description>Excl City Tax (5%) ROOMNIGHT</description> '#10+
      '    <quantity>1</quantity> '#10+
      '    <currencyCode>EUR</currencyCode> '#10+
      '    <roomReservationId>203789</roomReservationId> '#10+
      '    <stayDate> '#10+
      '      <year>2018</year> '#10+
      '      <month>MARCH</month> '#10+
      '      <monthValue>3</monthValue> '#10+
      '      <era>CE</era> '#10+
      '      <dayOfMonth>27</dayOfMonth> '#10+
      '      <dayOfWeek>TUESDAY</dayOfWeek> '#10+
      '      <dayOfYear>86</dayOfYear> '#10+
      '      <leapYear>false</leapYear> '#10+
      '      <chronology> '#10+
      '        <id>ISO</id> '#10+
      '        <calendarType>iso8601</calendarType> '#10+
      '      </chronology> '#10+
      '    </stayDate> '#10+
      '    <cityTaxPerNight>15.57</cityTaxPerNight> '#10+
      '    <roomBasePricePerNight>311.32</roomBasePricePerNight> '#10+
      '    <cityTaxPerNightExVat>15.57</cityTaxPerNightExVat> '#10+
      '    <publishedRoomPricePerNight>330.00</publishedRoomPricePerNight> '#10+
      '    <roomRentVat>18.68</roomRentVat> '#10+
      '    <overallTotal>345.57</overallTotal> '#10+
      '    <vatOnCityTax>0.00</vatOnCityTax> '#10+
      '  </item> '#10+
      '</RoomRentTaxReceiptList> '#10;
{$ENDREGION}

{ TAmountImplicitTests }

procedure TRoomRentTaxReceiptFromXMLTest.SetUp;
begin
  inherited;
  FTaxes := TRoomReservationTaxes.Create;
  Currencymanager.CreateDefinition('EUR');
  Currencymanager.DefaultCurrency := 'EUR';
end;

procedure TRoomRentTaxReceiptFromXMLTest.TearDown;
begin
  FTaxes.Free;
  inherited;
end;

procedure TRoomRentTaxReceiptFromXMLTest.TestSetupTearDown;
begin
  CheckTrue(True);
end;


procedure TRoomRentTaxReceiptFromXMLTest.TestReadXML;
var
  lreceipt: TRoomRentTaxReceipt;
begin
  FTaxes.LoadFromXML(cXML);
  CheckEquals(FTaxes.Count, 5);
  CheckTrue(Assigned(FTaxes[EncodeDate(2018, 3, 25)]), 'Receipt for 2018-03-25 not found');

  lReceipt := FTaxes[EncodeDate(2018, 3, 25)];
  CheckEquals(203789, lReceipt.RoomReservation, 'Wrong roomreservation');
  CheckTrue( TAmount.Create(14.62, 'EUR') = lReceipt.CityTaxPerNight, 'Wrong citytax per night pm 2018-03-25');

  lReceipt := FTaxes[EncodeDate(2018, 3, 27)];
  CheckTrue( TAmount.Create(345.57, 'EUR') = lReceipt.OverallTotal, 'Wrong overaltotal pm 2018-03-27');

  CheckTrue(FTaxes.TotalCityTax = TAmount.Create(71.23, 'EUR') , 'TotalCityTax not correct');
end;

initialization
  RegisterTest(TRoomRentTaxReceiptFromXMLTest.Suite);
end.
