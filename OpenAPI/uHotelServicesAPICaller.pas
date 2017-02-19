unit uHotelServicesAPICaller;

interface

uses
  uOpenApiCaller
  , uRoomerHotelServicesCommunicationModel_RequestsResponses
  ;

type
  EUserActivityLogAPICallerException = class(EOpenAPICallerException);

  /// <summary>
  ///  Implementation of hotelservice/useractivitylogs/ endpoints <br />
  ///  See <see href='https://promoir.atlassian.net/wiki/display/OAPI/User+Activity+Logs'>openAPI documentation</see>
  ///  </summary>
  TUserActivityLogAPICaller = class(TBaseOpenAPICaller)
  const
    cResourcesURI = '/hotelservices';
    cUserActivityLogsURI = '/useractivitylogs';
    cGetAllCategoriesURI = '/categories';
  private
  public
    type
      TAPICallParameters = record
        DoneAfterDate: TDate;
        DoneBeforeDate: TDate;
        AffectAfterDate: TDate;
        AffectBeforeDate: TDate;
        Category: string;
        Action: string;
        Reservation: integer;
        RoomReservation: integer;
      end;

    ///	<summary>
    ///	  Implementation of hotelservice/useractivitylogs/categories endpoint  <br />
    ///  retrieving all used categories an actions
    ///	</summary>
    function GetAllCategoriesAndActionsForHotel(aCategoriesAndActions: TUserActivityCategoriesOverview): boolean;
    ///	<summary>
    ///	  Implementation of hotelservice/useractivitylogs[/{categories}[/{action}]] endpoint  <br />
    ///	</summary>
    function GetLogFragment(const aParams: TAPICallParameters; aLogFragment: TUserActivityLogFragment): boolean; overload;
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

function TUserActivityLogAPICaller.GetLogFragment(const aParams: TAPICallParameters; aLogFragment: TUserActivityLogFragment): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
  lStatus: integer;
begin
  Assert(Assigned(aLogFragment), 'No LogFragment object provided');

  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
  try
    lURI := d.roomerMainDataSet.OpenApiUri + cResourcesURI  + cUserActivityLogsURI;

    if not aParams.Category.IsEmpty then
    begin
      lUri := lUri + '/' + d.RoomerMainDataset.UrlEncode(aParams.Category);
      if not aParams.Action.IsEmpty then
        lUri := lUri + '/' + d.roomerMainDataSet.UrlEncode(aParams.Action);
    end;

    if aParams.DoneAfterDate > 0 then
      roomerClient.QueryParams.Add('doneAfterDate=' + DateToXML(aParams.DoneAfterDate));
    if aParams.DoneBeforeDate > 0 then
      roomerClient.QueryParams.Add('doneBeforeDate=' + DateToXML(aParams.DoneBeforeDate));
    if aParams.AffectAfterDate > 0 then
      roomerClient.QueryParams.Add('affectAfterDate='+ DateToXML(aParams.AffectAfterDate));
    if aParams.AffectBeforeDate > 0 then
      roomerClient.QueryParams.Add('affectBeforeDate='+ DateToXML(aParams.AffectBeforeDate));
    if aParams.Reservation > 0 then
      roomerClient.QueryParams.Add(Format('reservationId=%d', [aParams.Reservation]));
    if aParams.RoomReservation > 0 then
      roomerClient.QueryParams.Add(Format('roomReservationId=%d', [aParams.RoomReservation]));

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
