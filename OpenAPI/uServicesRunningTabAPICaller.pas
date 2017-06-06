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
  type
    TRunningTabOption = (SplitOnInvoiceIndex);
    TRUnningTabOptions = set of TRunningTabOption;
  private
  public
    function GetRunningTabRoomRes(aRoomReservationId: integer; aRunningTabAOverview: TRunningTabsOverview; aOptions: TRunningTabOptions = []): boolean;
    /// <summary>
    ///   Process the provided runningTab parts and add new invoicelines or update existing invoicelines accordingly. The aRunningTab ojbect is
    ///  update with the new resulting data.
    /// </summary>
    function AddOrUpdateRunningTab(aRunningTabsOverview: TRunningTabsOverview; aOptions: TRUnningTabOptions = []): boolean;
    function DeleteRunningTabProductItem(aLineID: integer): boolean;
  end deprecated;

implementation

uses
  uRoomerHttpClient
  , uD
  , Classes
  , SysUtils
  , XmlUtils
  , uUtils
  ;

function TRunningTabAPICaller.AddOrUpdateRunningTab(aRunningTabsOverview: TRunningTabsOverview; aOptions: TRUnningTabOptions): boolean;
const
  cEndPoint = '/add';
var
  lURI: string;
  Xml: string;
  lParams: TRoomerHttpQueryparams;
begin
  lURI := cRunningTabURI  + cEndPoint;

  if (aOptions <> []) then
  begin
    lUri := lUri + '?';
    lParams := TRoomerHttpQueryparams.Create;
    try
      if (TRunningTabOption.SplitOnInvoiceIndex in aOptions) then
        lParams.Add('splitInvoice=true');

      lUri := lUri + lParams.AsURLText;
    finally
      lParams.Free;
    end;
  end;

  try
    Xml := d.roomerMainDataSet.PutData(lURI, aRunningTabsOverview.AsXMLDocument.XML);
    aRunningTabsOverview.LoadFromXML(Xml);
    Result := true;
  except
    on E: Exception do
      raise EServicesRunningTabAPICallerException.Create('Error during add or update of running tab');
  end;

end;

function TRunningTabAPICaller.DeleteRunningTabProductItem(aLineID: integer): boolean;
const
  cEndPoint = '/delete/item';
var
  lURI: string;
  Xml: string;
begin
  lURI := cRunningTabURI  + cEndPoint + '/' + IntToSTr(aLineId);

  try
    Xml := d.roomerMainDataSet.DeleteData(lURI);
    Result := true;
  except
    on E: Exception do
      raise EServicesRunningTabAPICallerException.CreateFmt('Error during deleting invoice item  [%d]', [ aLineID]);
  end;

end;

function TRunningTabAPICaller.GetRunningTabRoomRes(aRoomReservationId: integer; aRunningTabAOverview: TRunningTabsOverview;
                                                   aOptions: TRunningTabOptions ): boolean;
var
  lURI: string;
  Xml: string;
  lParams: TRoomerHttpQueryparams;
const
  cEndpoint = '/id';
begin
  lURI := cRunningTabURI  + cEndPoint + '/' + IntToSTr(aRoomReservationId);

  if (aOptions <> []) then
  begin
    lUri := lUri + '?';
    lParams := TRoomerHttpQueryparams.Create;
    try
      if (TRunningTabOption.SplitOnInvoiceIndex in aOptions) then
        lParams.Add('splitInvoice=true');

      lUri := lUri + lParams.AsURLText;
    finally
      lParams.Free;
    end;
  end;

  try
    Xml := d.roomerMainDataSet.downloadRoomerUrlAsString(lURI);
    aRunningTabAOverview.LoadFromXML(Xml);
    Result := true;
  except
    on E: Exception do
      raise EServicesRunningTabAPICallerException.CreateFmt('Error during retrieval of invoice for roomreservation [%d]', [ aRoomReservationId]);
  end;

end;
end.
