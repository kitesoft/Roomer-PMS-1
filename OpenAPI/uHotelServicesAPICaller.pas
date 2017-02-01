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
    ///	<summary>
    ///	  Implementation of hotelservice/useractivitylogs/categories endpoint  <br />
    ///  See <see href='https://promoir.atlassian.net/wiki/display/OAPI/User+Activity+Logs'>openAPI documentation</see>
    ///	</summary>
    function GetAllCategoriesAndActionsForHotel(aCategoriesAndActions: TUserActivityCategoriesOverview): boolean;
    function GetLogFragment(aDoneAfterDate: TDate; aDoneBeforeDate: TDate; aAffectAfterDate: TDate; aAffectBeforeDate: TDate;
                            aLogFragment: TUserActivityLogFragment): boolean;
  end;

implementation

uses
  uRoomerHttpClient
  , uD
  , Classes
  , SysUtils
  , XmlUtils;

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

function TUserActivityLogAPICaller.GetLogFragment(aDoneAfterDate, aDoneBeforeDate, aAffectAfterDate, aAffectBeforeDate: TDate;
                                                  aLogFragment: TUserActivityLogFragment): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
  lStatus: integer;
begin
  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
  try
    lURI := d.roomerMainDataSet.OpenApiUri + cResourcesURI  + cUserActivityLogsURI;
    if aDoneAfterDate > 0 then
      roomerClient.QueryParams.Add('doneAfterDate=' + DateToXML(aDoneAfterDate));
    if aDoneBeforeDate > 0 then
      roomerClient.QueryParams.Add('doneBeforeDate=' + DateToXML(aDoneBeforeDate));
    if aAffectAfterDate > 0 then
      roomerClient.QueryParams.Add('affectAfterDate='+ DateToXML(aAffectAfterDate));
    if aAffectBeforeDate > 0 then
      roomerClient.QueryParams.Add('affectBeforeDate='+ DateToXML(aAffectBeforeDate));

    lStatus := roomerClient.GetWithStatus(lURI, lResponse);
    Result := lStatus = 200;
    if Result then
      aLogFragment.LoadFromXML(lResponse)
    else
      EUserActivityLogAPICallerException.CreateFmt('Error %d retrieving UserActivityLogFragment', [lStatus]);
  finally
    roomerClient.Free;
  end;
end;
end.
