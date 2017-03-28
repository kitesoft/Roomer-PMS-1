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
    cResourcesURI = '/bookings';
    cRunningTabsURI = '/runningTabs';
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
  lURI: string;
  Xml: string;
begin
  lURI := Format(cResourcesURI + '/%d/%d' + cRunningTabsURI + '/%d', [ aReservation, aRoomreservationID, aInvoiceIndex]);

  try
    Xml := d.roomerMainDataSet.downloadRoomerUrlAsString(lURI);
    aRunningTabResponse.LoadFromXML(Xml);
    Result := true;
  except
    on E: Exception do
      raise EBookingsRunningTabAPICallerException.CreateFmt('Error during retrieval of runningTab for roomreservation [%d]', [ aRoomReservationId]);
  end;

end;
end.
