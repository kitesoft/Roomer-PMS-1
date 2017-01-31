unit uHotelServicesAPICaller;

interface

uses
  uOpenApiCaller
  , uRoomerHotelServicesCommunicationModel_RequestsResponses
  ;

type
  EUserActivityLogAPICallerException = class(EOpenAPICallerException);

  TUserActivityLogAPICaller = class(TBaseOpenAPICaller)
  const
    cResourcesURI = 'hotelservices/';
    cUserActivityLogsURI = 'useractivitylogs/';
    cGetAllCategoriesURI = 'categories';
  private
  public
    /// <summary>
    ///   Implementation of hotelservice/useractivitylogs/categories endpoint
    /// </summary>
    function GetAllCategoriesAndActionsForHotel(aCategoriesAndActions: TUserActivityCategoriesOverview): boolean;
  end;

implementation

uses
  uRoomerHttpClient
  , uD
  , Classes
  , SysUtils
  ;

function TUserActivityLogAPICaller.GetAllCategoriesAndActionsForHotel(aCategoriesAndActions: TUserActivityCategoriesOverview): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
  lStatus: integer;
begin
  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
  try
    lURI := d.roomerMainDataSet.OpenApiUri + cResourcesURI  + cUserActivityLogsURI + cGetAllCategoriesURI;
    lStatus := roomerClient.GetWithStatus(lURI, lResponse);
    Result := lStatus = 200;
    if Result then
      aCategoriesAndActions.LoadFromXML(lResponse)
    else
      EUserActivityLogAPICallerException.CreateFmt('Error %d retrieving Categories and Actions', [lStatus]);
  finally
    roomerClient.Free;
  end;
end;

end.
