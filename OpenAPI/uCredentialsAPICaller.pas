unit uCredentialsAPICaller;

interface

uses
  uOpenApiCaller
  ;

type
  TCredentialsAPICaller = class(TBaseOpenAPICaller)
  const
    cResourcesURI = 'credentials/';
  private
  public
    /// <summary>
    ///   Implementation of creditials/{hotelId} endpoint to check if hotelid is in sync with AppKey of D.RoomerMainDataset
    /// </summary>
    function CheckHotelIdAndAppKey(const aHotelID: string): boolean;
  end;

implementation

{ TDayClosingTimesICaller }

uses
  uRoomerHttpClient
  , uD
  , uG
  , Classes
  , SysUtils
  ;

function TCredentialsAPICaller.CheckHotelIdAndAppKey(const aHotelID: string): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
begin
  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
  try
    lURI := d.roomerMainDataSet.OpenApiUri + cResourcesURI + d.roomerMainDataset.URLEncode(aHotelId);

    Result := roomerClient.GetWithStatus(lURI, lResponse) = 200;
    if Result then
      FLastErrorResponse := ''
    else
      FLastErrorResponse := lResponse;
  finally
    roomerClient.Free;
  end;
end;

end.
