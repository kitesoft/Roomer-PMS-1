unit uHotelStatisticsAPI;

interface
uses
    cmpRoomerDataset
  , SysUtils
  , uMobileAPI
  , uHotelStatistics
  , Classes
  , uReservationStateDefinitions
  ;

type

  EHotelStatisticsAPIException = class(EMobileAPICallerException);

  THotelStatisticsMobileAPICaller = class(TBaseMobileAPICaller)
  private const
    cStatisticsURI = '/hotelstatistics';
  protected
    function getURI: string; override;
  public
    /// <summary>
    ///   Implementation of /service/hotelstatistics mobile api endpoint, returning a THotelStatisticsList
    /// </summary>
    procedure GetHotelStatistics(aFromDate: TDateTime; aToDate: TDateTime; aStatistics: THotelStatisticsList);
    procedure GetRoomRentStatistics(aFromDate: TDateTime; aToDate: TDateTime; aExcludedStates: TReservationStateSet; aStatistics: THotelStatisticsList);
  end;


  THotelStatisticsNotifyEvent = procedure(aStatistics: THotelStatisticsList) of object;
  THotelStatisticsMobileAPICallerThreaded = class(THotelStatisticsMobileAPICaller)
  public
    /// <summary>
    ///   Calls GetHotelStatistics in an anonymous thread, on return the aOnCompletionHandler is called in the mainthread with
    ///   the resulting THotelStatisticsList.
    ///   Note that the provided List will be destroyed after returning from the call to aOnCompletionHandler
    /// </summary>
    class procedure GetHotelStatistics(aFromDate: TDateTime; aToDate: TDateTime; aOnCompletionHandler: THotelStatisticsNotifyEvent);
    class procedure GetRoomRentStatistics(aFromDate: TDateTime; aToDate: TDateTime; aExcludedStates: TReservationStateSet; aOnCompletionHandler: THotelStatisticsNotifyEvent);
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

{ THotelStatisticsMobileAPICaller }

procedure THotelStatisticsMobileAPICaller.GetHotelStatistics(aFromDate, aToDate: TDateTime; aStatistics: THotelStatisticsList);
var
  lResponse: string;
begin
  Assert(assigned(aStatistics));
  try
    lResponse := d.roomerMainDataSet.downloadRoomerUrlAsString(getURI +
                      '/' + dateToSqlString(aFromDate) + '/' + dateToSqlString(aToDate.AddDays(1)));

    aStatistics.LoadFromXML(lResponse);
  except
    on E: Exception do
    begin
      aStatistics.Clear;
      raise EHotelStatisticsAPIException.CreateFmt('Error while retrieving hotelstatistics [%s]', [E.Message]);
    end;
  end;
end;


procedure THotelStatisticsMobileAPICaller.GetRoomRentStatistics(aFromDate, aToDate: TDateTime;
  aExcludedStates: TReservationStateSet; aStatistics: THotelStatisticsList);
var
  lResponse: string;
  lURI: string;
const
  cRoomRentStatsURI = '/roomrent';
begin
  Assert(assigned(aStatistics));
  try
    lURI := getURI + cRoomRentStatsURI + '/' + dateToSqlString(aFromDate) + '/' + dateToSqlString(aToDate.AddDays(1));
    if aExcludedStates <> [] then
      lURI := lURI + '?excludedStates=' + aExcludedStates.asChars;

    lResponse := d.roomerMainDataSet.downloadRoomerUrlAsString(lURI);

    aStatistics.LoadFromXML(lResponse);
  except
    on E: Exception do
    begin
      aStatistics.Clear;
      raise EHotelStatisticsAPIException.CreateFmt('Error while retrieving roomrentstatistics [%s]', [E.Message]);
    end;
  end;
end;

function THotelStatisticsMobileAPICaller.getURI: string;
begin
  Result := inherited + cStatisticsURI;
end;

{ THotelStatisticsMobileAPICallerThreaded }

class procedure THotelStatisticsMobileAPICallerThreaded.GetHotelStatistics(aFromDate, aToDate: TDateTime; aOnCompletionHandler: THotelStatisticsNotifyEvent);
begin
  TThread.CreateAnonymousThread(
    procedure ()
    var
      lAPI: THotelStatisticsMobileAPICaller;
      lStatistics: THotelStatisticsList;
    begin
      lStatistics := nil;
      lAPI := THotelStatisticsMobileAPICaller.Create;
      try
        lStatistics := THotelStatisticsList.Create;
        try
          lAPI.GetHotelStatistics(aFromDate, aToDate, lStatistics);
        except
          lStatistics.Clear;
        end;
        if assigned(aOnCompletionHandler) then
        begin
          TTHread.Synchronize(TThread.CurrentThread,
            procedure()
            begin
              aOnCompletionHandler(lStatistics);
            end
            );
        end;
      finally
        lAPI.Free;
        lStatistics.Free;
      end;
    end
  ).Start;
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



class procedure THotelStatisticsMobileAPICallerThreaded.GetRoomRentStatistics(aFromDate, aToDate: TDateTime;
  aExcludedStates: TReservationStateSet; aOnCompletionHandler: THotelStatisticsNotifyEvent);
begin
  TThread.CreateAnonymousThread(
    procedure ()
    var
      lAPI: THotelStatisticsMobileAPICaller;
      lStatistics: THotelStatisticsList;
    begin
      lStatistics := nil;
      lAPI := THotelStatisticsMobileAPICaller.Create;
      try
        lStatistics := THotelStatisticsList.Create;
        try
          lAPI.GetRoomRentStatistics(aFromDate, aToDate, aExcludedStates, lStatistics);
        except
          lStatistics.Clear;
        end;
        if assigned(aOnCompletionHandler) then
        begin
          TTHread.Synchronize(TThread.CurrentThread,
            procedure()
            begin
              aOnCompletionHandler(lStatistics);
            end
            );
        end;
      finally
        lAPI.Free;
        lStatistics.Free;
      end;
    end
  ).Start;
end;

end.
