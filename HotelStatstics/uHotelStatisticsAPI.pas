unit uHotelStatisticsAPI;

interface
uses
    cmpRoomerDataset
  , SysUtils
  , uHotelStatistics
  ;

type
  EMobileAPICallerException = class(Exception);

  TBaseMobileAPICaller = class abstract(TObject)
  const
    cBaseURI = '/services';
  protected
    FLastErrorResponse: string;
  public
    property LastErrorResponse: string read FLastErrorResponse;
  end;

  THotelStatisticsMobileAPICaller = class(TBaseMobileAPICaller)
  private const
    cStatisticsURI = '/hotelstatistics';
    procedure ParseStatisticsResponse(const aXML: string; aStatistics: THotelStatisticsList);
  public
    /// <summary>
    ///   Implementation of /service/hotelstatistics mobile api endpoint, returning a THotelStatisticsList
    /// </summary>
    procedure GetHotelStatistics(aFromDate: TDate; aToDate: TDate; aStatistics: THotelStatisticsList);
  end;

implementation

uses
  uD
  , uDateUtils
   , XMLIntf
   , OXmlPDOM
  ;

{ THotelStatisticsMobileAPICaller }

procedure THotelStatisticsMobileAPICaller.GetHotelStatistics(aFromDate, aToDate: TDate; aStatistics: THotelStatisticsList);
var
  lResponse: string;
begin
  Assert(assigned(aStatistics));
  lResponse := d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + cStatisticsURI +
                '/' + dateToSqlString(aFromDate) +
                '/' + dateToSqlString(aToDate));

  aStatistics.LoadFromXML(lResponse);
end;


//<ArrayList>
//   <item>
//      <date>
//         <year>2018</year>
//         <month>MARCH</month>
//         <monthValue>3</monthValue>
//         <era>CE</era>
//         <dayOfMonth>5</dayOfMonth>
//         <dayOfWeek>MONDAY</dayOfWeek>
//         <dayOfYear>64</dayOfYear>
//         <leapYear>false</leapYear>
//         <chronology>
//            <id>ISO</id>
//            <calendarType>iso8601</calendarType>
//         </chronology>
//      </date>
//      <statistics>
//         <statistics>
//            <name>ADR</name>
//            <value>0.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>REVPAR</name>
//            <value>0.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>IN_HOUSE</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>BAR</name>
//            <value>110.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>EXPECTED_DEPARTURES</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>ROOMS_SOLD</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>OCCUPANCY</name>
//            <value>0</value>
//            <unit>PERCENT</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>EXPECTED_ARRIVALS</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>LEFT_TO_SELL</name>
//            <value>29</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//      </statistics>
//   </item>
//   <item>
//      <date>
//         <year>2018</year>
//         <month>MARCH</month>
//         <monthValue>3</monthValue>
//         <era>CE</era>
//         <dayOfMonth>6</dayOfMonth>
//         <dayOfWeek>TUESDAY</dayOfWeek>
//         <dayOfYear>65</dayOfYear>
//         <leapYear>false</leapYear>
//         <chronology>
//            <id>ISO</id>
//            <calendarType>iso8601</calendarType>
//         </chronology>
//      </date>
//      <statistics>
//         <statistics>
//            <name>ADR</name>
//            <value>0.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>REVPAR</name>
//            <value>0.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>IN_HOUSE</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>BAR</name>
//            <value>110.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>EXPECTED_DEPARTURES</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>ROOMS_SOLD</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>OCCUPANCY</name>
//            <value>0</value>
//            <unit>PERCENT</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>EXPECTED_ARRIVALS</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>LEFT_TO_SELL</name>
//            <value>29</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//      </statistics>
//   </item>
//   <item>
//      <date>
//         <year>2018</year>
//         <month>MARCH</month>
//         <monthValue>3</monthValue>
//         <era>CE</era>
//         <dayOfMonth>7</dayOfMonth>
//         <dayOfWeek>WEDNESDAY</dayOfWeek>
//         <dayOfYear>66</dayOfYear>
//         <leapYear>false</leapYear>
//         <chronology>
//            <id>ISO</id>
//            <calendarType>iso8601</calendarType>
//         </chronology>
//      </date>
//      <statistics>
//         <statistics>
//            <name>ADR</name>
//            <value>0.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>REVPAR</name>
//            <value>0.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>IN_HOUSE</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>BAR</name>
//            <value>110.0</value>
//            <unit>NATIVE_CURRENCY</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>EXPECTED_DEPARTURES</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>ROOMS_SOLD</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>OCCUPANCY</name>
//            <value>0</value>
//            <unit>PERCENT</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>EXPECTED_ARRIVALS</name>
//            <value>0</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//         <statistics>
//            <name>LEFT_TO_SELL</name>
//            <value>29</value>
//            <unit>NO_DIMENSION</unit>
//            <description/>
//         </statistics>
//      </statistics>
//   </item>
//</ArrayList>

end.
