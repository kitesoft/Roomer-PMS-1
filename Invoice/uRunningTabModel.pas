unit uRunningTabModel;

interface

uses
  uRoomerHotelServicesCommunicationModel_RunningTabs
   , Spring.Collections.Lists
   , Spring.Collections
  ;

type

  /// <summary>
  ///   Class adapting the runningtab result for use in the invoiceOnObjects form
  /// </summary>
  TRunningTabViewAdapter = class
  private
    FRunningTabsOverview: TRunningTabsOverview;
    function GetInvoicelinesList(aIndex: integer): IObjectList;
    function GetPaymentsList(aIndex: integer): IObjectList;

  public
    constructor Create;
    destructor Destroy; override;

    function TotalInvoiceLinesGrossAmount(aIndex: integer): double;
    function InvoiceIndexNotEmpty(aIndex: integer): boolean;

    property RunningTabsOverview: TRunningTabsOverview read FRunningTabsOverview;
    property InvoicelinesList[aIndex: integer]: IObjectList read GetInvoicelinesList;
    property PaymentsList[aIndex: integer]: IObjectList read GetPaymentsList;
  end;

implementation

uses
  Spring
  ;

{ TRunningTabModelAdapter }

constructor TRunningTabViewAdapter.Create;
begin
  FRunningTabsOverview := TRunningTabsOverview.Create;
end;

destructor TRunningTabViewAdapter.Destroy;
begin
  FRunningTabsOverview.Free;
  inherited;
end;

function TRunningTabViewAdapter.GetInvoicelinesList(aIndex: integer): IObjectList;
var
  Predicate: Spring.TPredicate<TRunningTabProduct>;
  Product: TRunningTabProduct;
  Enumerable: IEnumerable<TRunningTabProduct>;
begin
  Result := TCollections.CreateObjectList<TRunningTabProduct>(false) as IObjectList;

  Predicate := function(const aProduct: TRunningTabProduct): Boolean
               begin
                 Result :=  aProduct.InvoiceIndex = aIndex;
               end;

  if FRunningTabsOverview.RunningTabList.Count > 0 then
  begin
    Enumerable := FRunningTabsOverview.RunningTabList.First.ProductList.Where(Predicate);
    for Product in Enumerable do
      Result.Add(Product);
  end;
end;

function TRunningTabViewAdapter.GetPaymentsList(aIndex: integer): IObjectList;
var
  Predicate: Spring.TPredicate<TRunningTabPayment>;
  Payment: TRunningTabPayment;
  Enumerable: IEnumerable<TRunningTabPayment>;
begin
  Result := TCollections.CreateObjectList<TRunningTabPayment>(false) as IObjectList;

  Predicate := function(const aProduct: TRunningTabPayment): Boolean
               begin
                 Result :=  aProduct.InvoiceIndex = aIndex;
               end;

  if FRunningTabsOverview.RunningTabList.Count > 0 then
  begin
    Enumerable := FRunningTabsOverview.RunningTabList.First.PaymentList.Where(Predicate);
    for Payment in Enumerable do
      Result.Add(Payment);
  end;
end;

function TRunningTabViewAdapter.InvoiceIndexNotEmpty(aIndex: integer): boolean;
var
  Predicate: Spring.TPredicate<TRunningTabProduct>;
  Product: TRunningTabProduct;
  Enumerable: IEnumerable<TRunningTabProduct>;
begin

  Predicate := function(const aProduct: TRunningTabProduct): Boolean
               begin
                 Result :=  aProduct.InvoiceIndex = aIndex;
               end;

  Result := (FRunningTabsOverview.RunningTabList.Count > 0) and FRunningTabsOverview.RunningTabList.First.ProductList.Where(Predicate).Any;
end;

function TRunningTabViewAdapter.TotalInvoiceLinesGrossAmount(aIndex: integer): double;
var
  Predicate: Spring.TPredicate<TRunningTabProduct>;
  Product: TRunningTabProduct;
  Enumerable: IEnumerable<TRunningTabProduct>;
begin

  Predicate := function(const aProduct: TRunningTabProduct): Boolean
               begin
                 Result :=  aProduct.InvoiceIndex = aIndex;
               end;

  Enumerable := FRunningTabsOverview.RunningTabList.First.ProductList.Where(Predicate);

  Result := 0;
  for Product in Enumerable do
    Result := Result + Product.TotalGrossAmount;

end;

end.
