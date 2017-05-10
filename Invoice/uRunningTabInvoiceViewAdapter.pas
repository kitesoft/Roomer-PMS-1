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
    function GetTreeId: integer;
    function GetTreeParent: integer;
  protected
    FTreeID: integer;
    FTreeParent: integer;
    FLineType: TxsdInvoiceLineType;
    function GetDescription: string; virtual;
    function GetItemType: string; virtual;
    function GetIndex: integer; virtual;
    function GetId: string; virtual;
    function GetParent: string; virtual;
    function GetPurchaseDate: TDate; virtual;
    function GetQuantity: double; virtual;
    function GetNettoPrice: double; virtual;
    function GetTotalNetAmount: double; virtual;
  public
    constructor Create(aLineType: TxsdInvoiceLineType; aID, aParentID: integer);
  published
    property ID: string read GetId;
    property Index_: integer read GetIndex;
    property Parent: string read GetParent;
    property ItemType: string read GetItemType;
    property Description: string read GetDescription;
    property PurchaseDate: TDate read GetPurchaseDate;
    property Quantity: double read GetQuantity;
    property NettoPrice: double read GetNettoPrice;
    property TotalNetAmount: double read GetTotalNetAmount;

    property TreeID: integer read GetTreeId;
    property TreeParent: integer read GetTreeParent;
  end;

  TRunningTabDiscountItem = class(TRunningTabInvoiceViewItem)
  protected
    function GetNettoPrice: double; override;
    function GetTotalNetAmount: double; override;
  end;

  TRunningTabApplicableTaxItem = class(TRunningTabInvoiceViewItem)
  private
    FTax: TxsdApplicableTax;
  protected
    function GetId: string; override;
    function GetParent: string; override;
    function GetDescription: string; override;
    function GetNettoPrice: double; override;
    function GetTotalNetAmount: double; override;
    function GetItemType: string; override;
    function GetQuantity: double; override;
  public
    constructor Create(aLineType: TxsdInvoiceLineType; aTax: TxsdApplicableTax; aID, aParent: integer); reintroduce;
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
  lDiscountItem: TxsdDiscountBillableEntryType;
  lTax: TxsdApplicableTax;
  lParentID: integer;
  lViewItem: TRunningTabInvoiceViewItem;
  lPredicate: Spring.TPredicate<TxsdInvoiceLineType>;
  lDiscountPredicate: Spring.TPredicate<TxsdDiscountBillableEntryType>;
  lEnumerable: IEnumerable<TxsdInvoiceLineType>;
begin
  Clear;

  // Iterate through all items except discounts
  lPredicate :=  function(const aObject: TxsdInvoiceLineType): boolean
                  begin
                    Result := not (aObject.Item is TxsdDiscountBillableEntryType);
                  end;

  for litem in FLinesList.Where(lPredicate) do
  begin
    Add(TRunningTabInvoiceViewItem.Create(lItem, Count, -1));

    if (lItem.Item is TxsdExtendedBillableEntryType) and (TxsdExtendedBillableEntryType(lItem.Item).ApplicableTaxList.Count > 0) then
    begin
      lParentId := Count-1;
      for lTax in TxsdExtendedBillableEntryType(lItem.Item).ApplicableTaxList do
        Add(TRunningTabApplicableTaxItem.Create(lItem, lTax, Count, lParentId));
    end;
  end;


  lPredicate :=  function(const aObject: TxsdInvoiceLineType): boolean
                  begin
                    Result := (aObject.Item is TxsdDiscountBillableEntryType);
                  end;

  // Locate parent id by searching for AppliesTo key
  for lItem in FLinesList.Where(lPredicate) do
  begin
    lDiscountItem := TxsdDiscountBillableEntryType(lItem.Item);
    lParentId := Self.Where(function(const aObject: TRunningTabInvoiceViewItem): boolean
                                  begin
                                    Result := aObject.ID.Equals(lDiscountItem.AppliesTo);
                                  end).FirstOrDefault.TreeID;
    Add(TRunningTabDiscountItem.Create(lItem, Count, lParentId));
  end;
end;


{ TRunningTabInvoiceViewItem }

constructor TRunningTabInvoiceViewItem.Create(aLinetype: TxsdInvoiceLineType; aID, aParentID: integer);
begin
  FLineType := aLineType;
  FTreeId := aId;
  FTreeParent := aParentID;
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
  if FLineType.Item is TxsdBillableEntryType then
    Result := TxsdBillableEntryType(FLineType.Item).ConvertedUnitPrice.Amount
  else
    Result := 0;
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
    result := TxsdBillableEntryType(FlineType.item).PurchaseDateTime
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
  if FLineType.Item is TxsdExtendedBillableEntryType then
    Result := TxsdExtendedBillableEntryType(FLineType.Item).TotalConvertedPriceNet.Amount
  else
    Result := 0;

end;

function TRunningTabInvoiceViewItem.GetTreeId: integer;
begin
  Result := FTreeID;
end;

function TRunningTabInvoiceViewItem.GetTreeParent: integer;
begin
  Result := FTreeParent;
end;

{ TRunningTabApplicableTaxItem }

constructor TRunningTabApplicableTaxItem.Create(aLineType: TxsdInvoiceLineType; aTax: TxsdApplicableTax; aID, aParent: integer);
begin
  inherited Create(aLineType, aID, aParent);
  FTax := aTax;
end;

function TRunningTabApplicableTaxItem.GetDescription: string;
begin
  Result := FTax.Description;
end;

function TRunningTabApplicableTaxItem.GetId: string;
begin
  Result := '';
end;

function TRunningTabApplicableTaxItem.GetItemType: string;
begin
  Result := 'TAX';
end;

function TRunningTabApplicableTaxItem.GetNettoPrice: double;
begin
  Result := GetTotalNetAmount;
end;

function TRunningTabApplicableTaxItem.GetParent: string;
begin
  Result := FLineType.Item.ID;
end;

function TRunningTabApplicableTaxItem.GetQuantity: double;
begin
  Result := 1;
end;

function TRunningTabApplicableTaxItem.GetTotalNetAmount: double;
begin
  Result := FTax.Amount.Amount;
  if FLineType.Item is TxsdDiscountBillableEntryType then
      Result := Result * -1;
end;

{ TRunningTabDiscountItem }

function TRunningTabDiscountItem.GetNettoPrice: double;
begin
  Result := inherited * -1;
end;

function TRunningTabDiscountItem.GetTotalNetAmount: double;
begin
  Result := inherited * -1;

end;

end.
