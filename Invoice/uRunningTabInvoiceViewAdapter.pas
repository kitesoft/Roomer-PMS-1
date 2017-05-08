unit uRunningTabInvoiceViewAdapter;

interface

uses
  Classes
  , RoomerBookingCommunicationModel_RequestsResponses
  , RoomerFinancialDataModel_ModelObjects
  , Spring.Collections.Lists
  , Spring.Collections
  ;

type

  TRunningTabInvoiceViewItem = class(TPersistent)
  private
    FLineType: TxsdInvoiceLineType;
    function GetDescription: string;
    function GetItemType: string;
    function GetIndex: integer;
    function GetId: string;
    function GetParent: string;
    function GetPurchaseDate: TDate;
    function GetQuantity: double;
    function GetNettoPrice: double;
    function GetTotalNetAmount: double;
  public
    constructor Create(aLineType: TxsdInvoiceLineType);
  published
    property ID: string read GetId;
    property Index_: integer read GetIndex;
    property Parent: string read GetParent;
    property ItemType: string read GetItemType;
    property Description: string read GetDescription;
    property PurchaseDate: TDate read GetPurchaseDate;
    property Quantity: double read GetQuantity;
    property NettoProce: double read GetNettoPrice;
    property TotalNetAmount: double read GetTotalNetAmount;
  end;

  TRunningTabInvoiceViewList = class(TObjectList<TRunningTabinvoiceViewItem>)
  private
    FLinesList: TxsdInvoiceLineTypeList;
    procedure Additems;
  public
    constructor Create(aLinesList: TxsdInvoiceLineTypeList); overload;
  end;

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
  if InvoiceIndexNotEmpty(aIndex) then
    Supports(TRunningTabInvoiceViewList.Create(FRunningTabsOverview.Items[aIndex].LineItemList), IObjectList, Result)
  else
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

{ TRunningTabInvoiceViewList }

constructor TRunningTabInvoiceViewList.Create(aLinesList: TxsdInvoiceLineTypeList);
begin
  Create;
  FLinesList := aLinesList;
  AddItems;
end;

procedure TRunningTabInvoiceViewList.Additems;
var
  lItem: TxsdInvoiceLineType;
begin
  for lItem in FLinesList do
  begin
    Add(TRunningTabInvoiceViewItem.Create(lItem));
  end;
end;


{ TRunningTabInvoiceViewItem }

constructor TRunningTabInvoiceViewItem.Create(aLinetype: TxsdInvoiceLineType);
begin
  FLineType := aLineType;
end;

function TRunningTabInvoiceViewItem.GetDescription: string;
begin
  if FLineType.Item is TxsdBillableEntryType then
    Result := TxsdBillableEntryType(FLineType.Item).Description
  else if FLineType.Item is TxsdTextEntryType then
    Result := TxsdTextEntryType(FLineType.Item).Text
  else
    Result := '';
end;

function TRunningTabInvoiceViewItem.GetId: string;
begin
  Result := FLineType.Item.ID;
end;

function TRunningTabInvoiceViewItem.GetIndex: integer;
begin
  Result := FLineType.index_;
end;

function TRunningTabInvoiceViewItem.GetItemType: string;
begin
  if FLineType.Item is TxsdBillableEntryType then
    Result := TxsdBillableEntryType(FLineType.Item).ProductID
  else
    Result := '';
end;

function TRunningTabInvoiceViewItem.GetNettoPrice: double;
begin

end;

function TRunningTabInvoiceViewItem.GetParent: string;
begin
  if FLineType.Item is TxsdDiscountBillableEntryType then
    Result := TxsdDiscountBillableEntryType(FLineType.Item).AppliesTo
  else
    Result := '-1' ;
end;

function TRunningTabInvoiceViewItem.GetPurchaseDate: TDate;
begin
  if FLineType.Item is TxsdBillableEntryType then
    result := TxsdBillableEntryType(FlineType.item).Purcha`seDateTime
  else
    Result := -1;
end;

function TRunningTabInvoiceViewItem.GetQuantity: double;
begin
  if FLineType.Item is TxsdBillableEntryType then
    result := TxsdBillableEntryType(FlineType.item).Number
  else
    Result := 0;
end;

function TRunningTabInvoiceViewItem.GetTotalNetAmount: double;
begin

end;

end.
