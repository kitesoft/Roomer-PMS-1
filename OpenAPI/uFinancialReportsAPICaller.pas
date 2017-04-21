unit uFinancialReportsAPICaller;


interface

uses
  uOpenApiCaller
  , cmpRoomerDataset
  ;

type
  TFinancialReportsAPICaller = class(TBaseOpenAPICaller)
  const
    cResourcesURI = 'financials/reports/';
    cPaymentsURI = 'payments/';
    cRevenuesURI = 'revenues/';
    cRoomrentURI = 'roomrent/';
  private
  public
    function GetPaymentsReportAsDataset(aRSet: TRoomerDataset; aDateFrom: TDateTime = -1; aDateTo: TDatetime= -1; aIncludeDetails: boolean=false): boolean;
    function GetRevenuesReportAsDataset(aRSet: TRoomerDataset; aDateFrom: TDateTime = -1; aDateTo: TDatetime= -1; aIncludeDetails: boolean=false): boolean;
    function GetRoomrentReportAsDataset(aRSet: TRoomerDataset; aDateFrom: TDateTime = -1; aDateTo: TDatetime= -1; aIncludeDetails: boolean=false): boolean;
  end;

implementation

{ TDayClosingTimesICaller }

uses
  uDateTimeHelper
  , uRoomerHttpClient
  , uDateUtils
  , uD
  , Classes
  , SysUtils
  , uUtils;


function TFinancialReportsAPICaller.GetPaymentsReportAsDataset(aRSet: TRoomerDataset; aDateFrom: TDateTime = -1; aDateTo: TDatetime= -1; aIncludeDetails: boolean=false): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;

begin
  roomerClient := aRSet.CreateRoomerClient(True);
  try
    roomerClient.RequestHeader.Accept := cAccMicrosoftDataset;

    lURI := aRset.OpenApiUri + cResourcesURI + cPaymentsURI;

    if aDateFrom = -1 then
      aDateFrom := TDateTime.Today;

    roomerClient.QueryParams.Add('dateFrom=' + dateToSqlString(aDateFrom));
    if aDateTo <> -1 then
      roomerClient.QueryParams.Add('dateTo=' + dateToSqlString(aDateTo));
    if aIncludeDetails then
      roomerClient.QueryParams.Add('includeDetails=true');

    Result := roomerClient.GetWithStatus(lURI, lResponse).StatusCode = 200;
    if Result then
    begin
      FLastErrorResponse := '';
      aRSet.OpenDataset(lResponse);
    end
    else
      FLastErrorResponse := lResponse;
  finally
    roomerClient.Free;
  end;
end;

function TFinancialReportsAPICaller.GetRevenuesReportAsDataset(aRSet: TRoomerDataset; aDateFrom: TDateTime = -1; aDateTo: TDatetime= -1; aIncludeDetails: boolean=false): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
begin
  roomerClient := aRSet.CreateRoomerClient(True);
  try
    roomerClient.RequestHeader.Accept := cAccMicrosoftDataset;

    lURI := aRset.OpenApiUri + cResourcesURI + cRevenuesURI;

    if aDateFrom = -1 then
      aDateFrom := TDateTime.Today;

    roomerClient.QueryParams.Add('dateFrom=' + dateToSqlString(aDateFrom));
    if aDateTo <> -1 then
      roomerClient.QueryParams.Add('dateTo=' + dateToSqlString(aDateTo));
    if aIncludeDetails then
      roomerClient.QueryParams.Add('includeDetails=true');

    Result := roomerClient.GetWithStatus(lURI, lResponse).StatusCode = 200;
    if Result then
    begin
      FLastErrorResponse := '';
      aRSet.OpenDataset(lResponse);
    end
    else
      FLastErrorResponse := lResponse;
  finally
    roomerClient.Free;
  end;
end;

function TFinancialReportsAPICaller.GetRoomrentReportAsDataset(aRSet: TRoomerDataset; aDateFrom: TDateTime = -1; aDateTo: TDatetime= -1; aIncludeDetails: boolean=false): boolean;
var
  roomerClient: TRoomerHttpClient;
  lURI: string;
  lResponse: string;
begin
  roomerClient := aRSet.CreateRoomerClient(True);
  try
    roomerClient.RequestHeader.Accept := cAccMicrosoftDataset;

    lURI := aRset.OpenApiUri + cResourcesURI + cRoomrentURI;

    if aDateFrom = -1 then
      aDateFrom := TDateTime.Today;

    roomerClient.QueryParams.Add('dateFrom=' + dateToSqlString(aDateFrom));
    if aDateTo <> -1 then
      roomerClient.QueryParams.Add('dateTo=' + dateToSqlString(aDateTo));
    if aIncludeDetails then
      roomerClient.QueryParams.Add('includeDetails=true');

    Result := roomerClient.GetWithStatus(lURI, lResponse).StatusCode = 200;
    if Result then
    begin
      FLastErrorResponse := '';
      aRSet.OpenDataset(lResponse);
    end
    else
      FLastErrorResponse := lResponse;
  finally
    roomerClient.Free;
  end;end;

end.
