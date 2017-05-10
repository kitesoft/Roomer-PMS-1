unit uBookingsRunningTabAPICaller;

interface

uses
  uOpenApiCaller
  , RoomerBookingCommunicationModel_RequestsResponses
  ;

type
  EBookingsRunningTabAPICallerException = class(EOpenAPICallerException);

  /// <summary>
  ///  Implementation of bookings/.../runningTab/ endpoints <br />
  ///  </summary>
  TBookingsRunningTabAPICaller = class(TBaseOpenAPICaller)
  const
    cResourcesURI = 'bookings';
    cRunningTabsURI = '/runningtabs';
  private
  public
    function GetRunningTabRoomRes(aReservation: integer; aRoomReservationId: integer; aInvoiceIndex: integer; aRunningTabResponse: TxsdInvoiceResponse): boolean;
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


function TBookingsRunningTabAPICaller.GetRunningTabRoomRes(aReservation: integer; aRoomReservationId: integer; aInvoiceIndex: integer;
                                                           aRunningTabResponse: TxsdInvoiceResponse): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
  lSep: string;
begin
  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
  try
    try
      lURI := d.roomerMainDataSet.OpenApiUri + Format(cResourcesURI + '/%d/%d' + cRunningTabsURI + '/%d', [ aReservation, aRoomreservationID, aInvoiceIndex]);
      Result := roomerClient.GetWithStatus(lURI, lResponse).StatusCode = 200;
    except
      Result := false;
    end;
  finally
    roomerclient.Free;
  end;

  if Result then
    aRunningTabResponse.LoadFromXML(lResponse)
  else
    raise EBookingsRunningTabAPICallerException.CreateFmt('Error during retrieval of runningTab for roomreservation [%d]', [ aRoomReservationId]);
end;

end.
