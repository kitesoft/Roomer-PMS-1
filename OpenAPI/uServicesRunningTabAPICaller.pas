unit uServicesRunningTabAPICaller;

interface

uses
  uOpenApiCaller
  , uRoomerHotelServicesCommunicationModel_RunningTabs
  ;

type
  EServicesRunningTabAPICallerException = class(EOpenAPICallerException);

  /// <summary>
  ///  Implementation of services/runningTab/ endpoints <br />
  ///  See <see href='https://promoir.atlassian.net/wiki/display/OAPI/Retrieving+Invoices'>openAPI documentation</see>
  ///  </summary>
  TRunningTabAPICaller = class(TBaseOpenAPICaller)
  const
    cResourcesURI = '/services';
    cRunningTabURI = '/runningTab';
  private
  public
    function GetRunningTabRoomRes(aRoomReservationId: integer; aIncludeDetails: boolean; aRunningTabAOverview: TRunningTabsOverview): boolean;
  end;

implementation

uses
  uRoomerHttpClient
  , uD
  , Classes
  , SysUtils
  , XmlUtils
  , uUtils
  ;

function TRunningTabAPICaller.GetRunningTabRoomRes(aRoomReservationId: integer; aIncludeDetails: boolean;
                                                    aRunningTabAOverview: TRunningTabsOverview): boolean;
var
//  roomerClient: TRoomerHttpClient;
  lURI: string;
//  lResponse: string;
//  lStatus: integer;
  Xml: string;
const
  cEndpoint = '/id';
begin
//  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
//  try
    lURI := cRunningTabURI  + cEndPoint + '/' + IntToSTr(aRoomReservationId) + '?expanded' + iif(aIncludeDetails, 'true', 'false');

    try
      Xml := d.roomerMainDataSet.downloadRoomerUrlAsString(lURI);
      aRunningTabAOverview.LoadFromXML(Xml);
      Result := true;
    except
      on E: Exception do
        raise EServicesRunningTabAPICallerException.CreateFmt('Error during retrieval of invoice for roomreservation [%d]', [ aRoomReservationId]);
    end;

//    lStatus := roomerClient.GetWithStatus(lURI, lResponse);
//    Result := lStatus = 200;
//  finally
//    roomerClient.Free;
//  end;
end;
end.
