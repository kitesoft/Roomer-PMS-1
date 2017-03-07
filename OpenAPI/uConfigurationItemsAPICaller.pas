unit uConfigurationItemsAPICaller;

interface

uses
  uOpenApiCaller
  , RoomerConfigurationItemsCommunicationModel_RequestsResponses
  , SysUtils
  ;

type
  EConfigurationItemsApiCallerException = class(Exception);

  TConfigurationItemsAPICaller = class(TBaseOpenAPICaller)
  private
    const
      cResourcesURI = 'configurationitems/';
      cChannelInventoryURI = 'channelinventory/';
  public
    /// <summary>
    ///   see https://promoir.atlassian.net/wiki/display/OAPI/Roomer+Channel+Inventory
    /// </summary>
    function GetChannelInventoryItems(aChannelInventoryOverview: TChannelInventoryOverview): boolean;
    function GetChannelInventoryItem(const aChannelCode: string; aChannelInventoryOverview: TChannelInventoryOverview): boolean;
  end;

implementation

{ TDayClosingTimesICaller }

uses
  uRoomerHttpClient
  , uD
  , Classes
  ;

function TConfigurationItemsAPICaller.GetChannelInventoryItems(aChannelInventoryOverview: TChannelInventoryOverview): boolean;
begin
  Result := GetChannelInventoryItem('', aChannelInventoryOverview);
end;

function TConfigurationItemsAPICaller.GetChannelInventoryItem(const aChannelCode: string; aChannelInventoryOverview: TChannelInventoryOverview): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
begin
  Result := false;
  roomerClient := d.roomerMainDataSet.CreateRoomerClient(True);
  try
    lURI := d.roomerMainDataSet.OpenApiUri + cResourcesURI + cChannelInventoryURI + aChannelCode;

    try
      Result := roomerClient.GetWithStatus(lURI, lResponse).StatusCode = 200;
      if Result then
        aChannelInventoryOverview.LoadFromXML(lResponse)
      else
        FLastErrorResponse := lResponse;

    except
      on E: Exception do
        raise EConfigurationItemsApiCallerException.Create('Error while retrieving CahnnelInventoryItems: ' + e.message);
    end;
  finally
    roomerClient.Free;
  end;
end;

end.
