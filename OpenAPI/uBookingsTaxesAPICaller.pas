unit uBookingsTaxesAPICaller;

interface

uses
  uOpenApiCaller
  , uRoomerBookingDataModel_ModelObjects
  ;

type
  EBookingsTaxesAPICallerException = class(EOpenAPICallerException);

  /// <summary>
  ///  Implementation of bookings/.../taxes/ endpoints <br />
  ///  </summary>
  TBookingsTaxesTabAPICaller = class(TBaseOpenAPICaller)
  const
    cResourcesURI = 'bookings';
    cTaxesURI = '/taxes';
  private
  public
    function GetReservationTaxes(aReservation: integer; aResponse: TxsdRoomRentTaxReceiptList): boolean;
    function GetRoomReservationTaxes(aReservation: integer; aRoomreservation: integer; aResponse: TxsdRoomRentTaxReceiptList): boolean;
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


function TBookingsTaxesTabAPICaller.GetReservationTaxes(aReservation: integer; aResponse: TxsdRoomRentTaxReceiptList): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
begin
  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
  try
    try
      lURI := d.roomerMainDataSet.OpenApiUri + Format(cResourcesURI + '/%d' + cTaxesURI, [ aReservation]);
      Result := roomerClient.GetWithStatus(lURI, lResponse).StatusCode = 200;
    except
      Result := false;
    end;
  finally
    roomerclient.Free;
  end;

  if Result then
    aResponse.LoadFromXML(lResponse)
  else
    raise EBookingsTaxesAPICallerException.CreateFmt('Error during retrieval of taxes for reservation [%d]', [ aReservation]);
end;

function TBookingsTaxesTabAPICaller.GetRoomReservationTaxes(aReservation, aRoomreservation: integer;
  aResponse: TxsdRoomRentTaxReceiptList): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
begin
  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
  try
    try
      lURI := d.roomerMainDataSet.OpenApiUri + Format(cResourcesURI + '/%d/%d' + cTaxesURI, [ aReservation, aRoomReservation]);
      Result := roomerClient.GetWithStatus(lURI, lResponse).StatusCode = 200;
    except
      Result := false;
    end;
  finally
    roomerclient.Free;
  end;

  if Result then
    aResponse.LoadFromXML(lResponse)
  else
    raise EBookingsTaxesAPICallerException.CreateFmt('Error during retrieval of taxes for roomreservation [%d]', [ aROomReservation]);
end;

end.
