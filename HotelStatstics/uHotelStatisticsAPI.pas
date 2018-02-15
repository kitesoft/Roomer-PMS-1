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
  public
    /// <summary>
    ///   Implementation of /service/hotelstatistics mobile api endpoint, returning a THotelStatisticsList
    /// </summary>
    procedure GetHotelStatistics(aFromDate: TDateTime; aToDate: TDateTime; aStatistics: THotelStatisticsList);
  end;

implementation

uses
  uD
  , uDateUtils
   , XMLIntf
   , OXmlPDOM
  , uDateTimeHelper;

{ THotelStatisticsMobileAPICaller }

procedure THotelStatisticsMobileAPICaller.GetHotelStatistics(aFromDate, aToDate: TDateTime; aStatistics: THotelStatisticsList);
var
  lResponse: string;
begin
  Assert(assigned(aStatistics));
  try
    lResponse := d.roomerMainDataSet.downloadUrlAsString(d.roomerMainDataSet.RoomerUri + cStatisticsURI +
                  '/' + dateToSqlString(aFromDate) +
                  '/' + dateToSqlString(aToDate.AddDays(1)));

    aStatistics.LoadFromXML(lResponse);
  except
    aStatistics.Clear;
    raise;
  end;
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

end.
