unit uRunningTabInvoiceViewAdapter;

interface

uses
  RoomerBookingCommunicationModel_RequestsResponses
   , Spring.Collections.Lists
   , Spring.Collections
  ;

type
  /// <summary>
  ///   Class adapting the runningtab result for use in the invoiceOnObjects form
  /// </summary>
  TRunningTabInvoiceViewAdapter = class
  private
    FRunningTabsOverview: TxsdInvoiceResponse;
    function GetInvoicelinesList(aIndex: integer): IObjectList;
    function GetPaymentsList(aIndex: integer): IObjectList;

  public
    constructor Create;
    destructor Destroy; override;

    function TotalInvoiceLinesGrossAmount(aIndex: integer): double;
    function InvoiceIndexNotEmpty(aIndex: integer): boolean;

    property RunningTabsOverview: TxsdInvoiceResponse read FRunningTabsOverview;
    property InvoicelinesList[aIndex: integer]: IObjectList read GetInvoicelinesList;
    property PaymentsList[aIndex: integer]: IObjectList read GetPaymentsList;
  end;


implementation

uses
  SysUtils
  ;

{ TRunningTabInvoiceViewAdapter }

constructor TRunningTabInvoiceViewAdapter.Create;
begin
  FRunningTabsOverview := TxsdInvoiceResponse.Create;
end;

destructor TRunningTabInvoiceViewAdapter.Destroy;
begin
  FRunningTabsOverview.Free;
  inherited;
end;

function TRunningTabInvoiceViewAdapter.GetInvoicelinesList(aIndex: integer): IObjectList;
begin
  if not InvoiceIndexNotEmpty(aIndex) or not Supports(FRunningTabsOverview.Items[aIndex].LineItemList, IObjectList ,Result) then
    Result := nil;
end;

function TRunningTabInvoiceViewAdapter.GetPaymentsList(aIndex: integer): IObjectList;
begin

end;

function TRunningTabInvoiceViewAdapter.InvoiceIndexNotEmpty(aIndex: integer): boolean;
begin
  Result := (FRunningTabsOverview.Count >= aIndex) and (FRunningTabsOverview.Items[aIndex].LineItemList.Count > 0);
end;

function TRunningTabInvoiceViewAdapter.TotalInvoiceLinesGrossAmount(aIndex: integer): double;
begin

end;

end.
