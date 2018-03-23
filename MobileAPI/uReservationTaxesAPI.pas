unit uReservationTaxesAPI;

interface
uses
    cmpRoomerDataset
  , SysUtils
  , uMobileAPI
  , Classes
  ;

type

  EReservationTaxesAPIException = class(EMobileAPICallerException);

  TReservationTaxesAPICaller = class(TBaseMobileAPICaller)
  private const
    cReservationTaxesURI = '/reservationtaxes';
  protected
    function getURI: string; override;
  public
    /// <summary>
    ///   Implementation of /service/hotelstatistics mobile api endpoint, returning a THotelStatisticsList
    /// </summary>
    procedure GetRoomResTotalTaxes(aRoomReservation: integer);
  end;


implementation

uses
  uD
  , uDateUtils
  , XMLIntf
  , OXmlPDOM
  , DateUtils
  , uDateTimeHelper
  , WinAPI.Windows
  ;

{ TReservationTaxesAPICaller }

procedure TReservationTaxesAPICaller.GetRoomResTotalTaxes(aRoomreservation: integer);
var
  lResponse: string;
const
  cRoomResTotalURI = '/roomtotal';
begin
  try
    lResponse := d.roomerMainDataSet.downloadRoomerUrlAsString(getURI + cRoomResTotalURI +
                      '/' + IntToStr(aRoomReservation));
  except
    on E: Exception do
    begin
      raise EReservationTaxesAPIException.CreateFmt('Error while retrieving taxes for roomreservation [%d]: [%s]', [aRoomReservation, E.Message]);
    end;
  end;
end;


function TReservationTaxesAPICaller.getURI: string;
begin
  Result := inherited + cReservationTaxesURI;
end;
{
<RoomRentTaxReceiptList xmlns="">
  <item>
    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice>
    <item>CTAX</item>
    <description>Excl City Tax (5%) ROOMNIGHT</description>
    <quantity>1</quantity>
    <currencyCode>EUR</currencyCode>
    <roomReservationId>203789</roomReservationId>
    <stayDate>
      <year>2018</year>
      <month>MARCH</month>
      <monthValue>3</monthValue>
      <era>CE</era>
      <dayOfMonth>23</dayOfMonth>
      <dayOfWeek>FRIDAY</dayOfWeek>
      <dayOfYear>82</dayOfYear>
      <leapYear>false</leapYear>
      <chronology>
        <id>ISO</id>
        <calendarType>iso8601</calendarType>
      </chronology>
    </stayDate>
    <cityTaxPerNight>11.79</cityTaxPerNight>
    <roomBasePricePerNight>235.85</roomBasePricePerNight>
    <cityTaxPerNightExVat>11.79</cityTaxPerNightExVat>
    <publishedRoomPricePerNight>250.00</publishedRoomPricePerNight>
    <roomRentVat>14.15</roomRentVat>
    <overallTotal>261.79</overallTotal>
    <vatOnCityTax>0.00</vatOnCityTax>
  </item>
  <item>
    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice>
    <item>CTAX</item>
    <description>Excl City Tax (5%) ROOMNIGHT</description>
    <quantity>1</quantity>
    <currencyCode>EUR</currencyCode>
    <roomReservationId>203789</roomReservationId>
    <stayDate>
      <year>2018</year>
      <month>MARCH</month>
      <monthValue>3</monthValue>
      <era>CE</era>
      <dayOfMonth>24</dayOfMonth>
      <dayOfWeek>SATURDAY</dayOfWeek>
      <dayOfYear>83</dayOfYear>
      <leapYear>false</leapYear>
      <chronology>
        <id>ISO</id>
        <calendarType>iso8601</calendarType>
      </chronology>
    </stayDate>
    <cityTaxPerNight>14.15</cityTaxPerNight>
    <roomBasePricePerNight>283.02</roomBasePricePerNight>
    <cityTaxPerNightExVat>14.15</cityTaxPerNightExVat>
    <publishedRoomPricePerNight>300.00</publishedRoomPricePerNight>
    <roomRentVat>16.98</roomRentVat>
    <overallTotal>314.15</overallTotal>
    <vatOnCityTax>0.00</vatOnCityTax>
  </item>
  <item>
    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice>
    <item>CTAX</item>
    <description>Excl City Tax (5%) ROOMNIGHT</description>
    <quantity>1</quantity>
    <currencyCode>EUR</currencyCode>
    <roomReservationId>203789</roomReservationId>
    <stayDate>
      <year>2018</year>
      <month>MARCH</month>
      <monthValue>3</monthValue>
      <era>CE</era>
      <dayOfMonth>25</dayOfMonth>
      <dayOfWeek>SUNDAY</dayOfWeek>
      <dayOfYear>84</dayOfYear>
      <leapYear>false</leapYear>
      <chronology>
        <id>ISO</id>
        <calendarType>iso8601</calendarType>
      </chronology>
    </stayDate>
    <cityTaxPerNight>14.62</cityTaxPerNight>
    <roomBasePricePerNight>292.45</roomBasePricePerNight>
    <cityTaxPerNightExVat>14.62</cityTaxPerNightExVat>
    <publishedRoomPricePerNight>310.00</publishedRoomPricePerNight>
    <roomRentVat>17.55</roomRentVat>
    <overallTotal>324.62</overallTotal>
    <vatOnCityTax>0.00</vatOnCityTax>
  </item>
  <item>
    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice>
    <item>CTAX</item>
    <description>Excl City Tax (5%) ROOMNIGHT</description>
    <quantity>1</quantity>
    <currencyCode>EUR</currencyCode>
    <roomReservationId>203789</roomReservationId>
    <stayDate>
      <year>2018</year>
      <month>MARCH</month>
      <monthValue>3</monthValue>
      <era>CE</era>
      <dayOfMonth>26</dayOfMonth>
      <dayOfWeek>MONDAY</dayOfWeek>
      <dayOfYear>85</dayOfYear>
      <leapYear>false</leapYear>
      <chronology>
        <id>ISO</id>
        <calendarType>iso8601</calendarType>
      </chronology>
    </stayDate>
    <cityTaxPerNight>15.10</cityTaxPerNight>
    <roomBasePricePerNight>301.89</roomBasePricePerNight>
    <cityTaxPerNightExVat>15.10</cityTaxPerNightExVat>
    <publishedRoomPricePerNight>320.00</publishedRoomPricePerNight>
    <roomRentVat>18.11</roomRentVat>
    <overallTotal>335.10</overallTotal>
    <vatOnCityTax>0.00</vatOnCityTax>
  </item>
  <item>
    <cityTaxIncludedInRoomPrice>false</cityTaxIncludedInRoomPrice>
    <item>CTAX</item>
    <description>Excl City Tax (5%) ROOMNIGHT</description>
    <quantity>1</quantity>
    <currencyCode>EUR</currencyCode>
    <roomReservationId>203789</roomReservationId>
    <stayDate>
      <year>2018</year>
      <month>MARCH</month>
      <monthValue>3</monthValue>
      <era>CE</era>
      <dayOfMonth>27</dayOfMonth>
      <dayOfWeek>TUESDAY</dayOfWeek>
      <dayOfYear>86</dayOfYear>
      <leapYear>false</leapYear>
      <chronology>
        <id>ISO</id>
        <calendarType>iso8601</calendarType>
      </chronology>
    </stayDate>
    <cityTaxPerNight>15.57</cityTaxPerNight>
    <roomBasePricePerNight>311.32</roomBasePricePerNight>
    <cityTaxPerNightExVat>15.57</cityTaxPerNightExVat>
    <publishedRoomPricePerNight>330.00</publishedRoomPricePerNight>
    <roomRentVat>18.68</roomRentVat>
    <overallTotal>345.57</overallTotal>
    <vatOnCityTax>0.00</vatOnCityTax>
  </item>
</RoomRentTaxReceiptList>
}
end.
