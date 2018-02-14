unit HotelStatisticsTest;


interface

uses
  TestFramework
  , uHotelStatistics
  ;

type

  THotelStatsFromXMLTest = class(TTestCase)
  private
    FHotelStats: THotelStatisticsList;
  public
    procedure SetUp; override;
    procedure TearDown; override;
  published
    procedure TestSetupTearDown;
    procedure TestReadXML;
  end;


implementation

const
{$REGION 'XML contents'}
    cXML =
      '  <ArrayList>'#10+
      '   <item>'#10+
      '      <date>'#10+
      '         <year>2018</year>'#10+
      '         <month>MARCH</month>'#10+
      '         <monthValue>3</monthValue>'#10+
      '         <era>CE</era>'#10+
      '         <dayOfMonth>5</dayOfMonth>'#10+
      '         <dayOfWeek>MONDAY</dayOfWeek>'#10+
      '         <dayOfYear>64</dayOfYear>'#10+
      '         <leapYear>false</leapYear>'#10+
      '         <chronology>'#10+
      '            <id>ISO</id>'#10+
      '            <calendarType>iso8601</calendarType>'#10+
      '         </chronology>'#10+
      '      </date>'#10+
      '      <statistics>'#10+
      '         <statistics>'#10+
      '            <name>ADR</name>'#10+
      '            <value>0.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>REVPAR</name>'#10+
      '            <value>0.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>IN_HOUSE</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>BAR</name>'#10+
      '            <value>110.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>EXPECTED_DEPARTURES</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>ROOMS_SOLD</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>OCCUPANCY</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>PERCENT</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>EXPECTED_ARRIVALS</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>LEFT_TO_SELL</name>'#10+
      '            <value>29</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '      </statistics>'#10+
      '   </item>'#10+
      '   <item>'#10+
      '      <date>'#10+
      '         <year>2018</year>'#10+
      '         <month>MARCH</month>'#10+
      '         <monthValue>3</monthValue>'#10+
      '         <era>CE</era>'#10+
      '         <dayOfMonth>6</dayOfMonth>'#10+
      '         <dayOfWeek>TUESDAY</dayOfWeek>'#10+
      '         <dayOfYear>65</dayOfYear>'#10+
      '         <leapYear>false</leapYear>'#10+
      '         <chronology>'#10+
      '            <id>ISO</id>'#10+
      '            <calendarType>iso8601</calendarType>'#10+
      '         </chronology>'#10+
      '      </date>'#10+
      '      <statistics>'#10+
      '         <statistics>'#10+
      '            <name>ADR</name>'#10+
      '            <value>0.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>REVPAR</name>'#10+
      '            <value>0.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>IN_HOUSE</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>BAR</name>'#10+
      '            <value>110.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>EXPECTED_DEPARTURES</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>ROOMS_SOLD</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>OCCUPANCY</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>PERCENT</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>EXPECTED_ARRIVALS</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>LEFT_TO_SELL</name>'#10+
      '            <value>29</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '      </statistics>'#10+
      '   </item>'#10+
      '   <item>'#10+
      '      <date>'#10+
      '         <year>2018</year>'#10+
      '         <month>MARCH</month>'#10+
      '         <monthValue>3</monthValue>'#10+
      '         <era>CE</era>'#10+
      '         <dayOfMonth>7</dayOfMonth>'#10+
      '         <dayOfWeek>WEDNESDAY</dayOfWeek>'#10+
      '         <dayOfYear>66</dayOfYear>'#10+
      '         <leapYear>false</leapYear>'#10+
      '         <chronology>'#10+
      '            <id>ISO</id>'#10+
      '            <calendarType>iso8601</calendarType>'#10+
      '         </chronology>'#10+
      '      </date>'#10+
      '      <statistics>'#10+
      '         <statistics>'#10+
      '            <name>ADR</name>'#10+
      '            <value>0.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>REVPAR</name>'#10+
      '            <value>0.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>IN_HOUSE</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>BAR</name>'#10+
      '            <value>110.0</value>'#10+
      '            <unit>NATIVE_CURRENCY</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>EXPECTED_DEPARTURES</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>ROOMS_SOLD</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>OCCUPANCY</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>PERCENT</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>EXPECTED_ARRIVALS</name>'#10+
      '            <value>0</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '         <statistics>'#10+
      '            <name>LEFT_TO_SELL</name>'#10+
      '            <value>29</value>'#10+
      '            <unit>NO_DIMENSION</unit>'#10+
      '            <description/>'#10+
      '         </statistics>'#10+
      '      </statistics>'#10+
      '   </item>'#10+
      '</ArrayList>'#10;
  
{$ENDREGION}
{ TAmountImplicitTests }

procedure THotelStatsFromXMLTest.SetUp;
begin
  inherited;
  FHotelStats := THotelStatisticsList.Create;
end;

procedure THotelStatsFromXMLTest.TearDown;
begin
  inherited;
  FHotelStats.Free;
end;

procedure THotelStatsFromXMLTest.TestSetupTearDown;
begin
  CheckTrue(True);
end;


procedure THotelStatsFromXMLTest.TestReadXML;
begin
  FHotelStats.LoadFromXML(cXML);
  CheckEquals(FHotelStats.StatisticsPerDateList.Count, 3);
end;

initialization
  RegisterTest(THotelStatsFromXMLTest.Suite);
end.
