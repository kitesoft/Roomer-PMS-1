unit uRoomerHotelServicesCommunicationModel_RunningTabs;

interface

uses
   Classes
   , SysUtils
   , Spring.Collections.Lists
   , Spring.Collections
   , uRoomerSchema
   , XMLIntf
   , OXmlPDOM
   ;

type

  TRunningTabCustomer = class(TxsdBaseObject)
  private
    FName: string;
    FPersonId: integer;
    FAddress2: string;
    FZipcode: string;
    FCustomerCode: string;
    FAddress1: string;
    FCity: string;
    FCountryCode: string;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    procedure Clear; override;
  published
    property CustomerCode: string read FCustomerCode write FCustomerCode;
    property PersonId: integer read FPersonId write FPersonId;
    property Name: string read FName write FName;
    property Address1: string read FAddress1 write FAddress1;
    property Address2: string read FAddress2 write FAddress2;
    property Zipcode: string read FZipcode write FZipcode;
    property City: string read FCity write FCity;
    property CountryCode: string read FCountryCode write FCountryCode;
  end;

  TVATAmount = class(TxsdBaseObject)
  private
    FVATCode: string;
    FPercentage: double;
    FAmount: double;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    procedure Clear; override;
  published
    property VATCode: string read FVATCode write FVATCode;
    property Percentage: double read FPercentage write FPercentage;
    property Amount: double read FAmount write FAmount;
  end;

  TRunningTabProduct  = class(TxsdBaseObject)
    type
      TProducttype = (itUnknown, itRoomRent, itStayTax, itDiscount, itSale);
      TProductTypeHelper = record helper for TProductType
      public
        class function FromString(const Value: string): TProductType; static;
      end;

  private
    FIndex: integer;
    FPurchaseDate: TDateTime;
    FItemType: string;
    FQuantity: double;
    FDescription: string;
    FNettoPrice: double;
    FProductType: TProductType;
    FAccountKey: string;
    FGrossPrice: double;
    FVatAmount: TVatAmount;
    function GetTotalGrossAmount: double;
    function GetTotalNetAmount: double;
    function GetTotalVatAmount: double;
    function GetItemVatAmount: double;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear; override;
    property TotalNetAmount: double read GetTotalNetAmount;
    property TotalVatAmount: double read GetTotalVatAmount;
    property TotalGrossAmount: double read GetTotalGrossAmount;
  published
    property Index_: integer read FIndex write FIndex;
    property ProductType: TProductType read FProductType write FProductType;
    property ItemType: string read FItemType write FItemType;
    property AccountKey: string read FAccountKey write FAccountKey;

    property Description: string read FDescription write FDescription;
    property PurchaseDate: TDateTime read FPurchaseDate write FPurchaseDate;
    property Quantity: double read FQuantity write FQuantity;
    property NettoPrice: double read FNettoPrice write FNettoPrice;
    property GrossPrice: double read FGrossPrice write FGrossPrice;
    property ItemVatAmount: TVatAmount read FVatAmount write FVatAmount;
  end;
  TRunnningTabProductList = TObjectList<TRunningTabProduct>;


  TRunningTabPayment = class(TxsdBaseObject)
    type
      TPaymenttype = (itUnknown, itRoomRent, itStayTax, itDiscount, itSale);
      TPaymentTypeHelper = record helper for TPaymentType
      public
        class function FromString(const Value: string): TPaymentType; static;
      end;

  private
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear; override;
  published
  end;
  TRunnningTabPay,entList = TObjectList<TRunningTabPayment>;

  TRunningTab = class(TxsdBaseObject)
  type
    TRunningTabType = (ttUnknown, ttGroup, ttRoom);
      TRunningTabTypeHelper = record helper for TRunningTabType
      public
        class function FromString(const Value: string): TRunningTabType; static;
      end;
  private
    FTabType: TRunningTabType;
    FCurrencyRate: double;
    FDescription: string;
    FCurrency: string;
    FProductList: IList<TRunningTabProduct>;
    FRunningTabCustomer: TRunningTabCustomer;
    FTotalVatAmount: double;
    FTotalNetAmount: double;
    FTotalGrossAmount: double;
    FBalance: double;
    function GetRunningsTabProductList: TRunnningTabProductList;
    function GetRunningTabCustomer: TRunningTabCustomer;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear; override;
  published
    property TabType: TRunningTabType read FTabType write FTabType;
    property Description: string read FDescription write FDescription;
    property Currency: string read FCurrency write FCurrency;
    property CurrencyRate: double read FCurrencyRate write FCurrencyRate;
    property TotalNetAmount: double read FTotalNetAmount write FTotalNetAmount;
    property TotalVatAmount: double read FTotalVatAmount write FTotalVatAmount;
    property TotalGrossAmount: double read FTotalGrossAmount write FTotalGrossAmount;
    property Balance: double read FBalance write FBalance;

    property Customer: TRunningTabCustomer read GetRunningTabCustomer;
    property ProductList: TRunnningTabProductList read GetRunningsTabProductList;
  end;

  TRunningTabList = TObjectlist<TRunningTab>;

  TRunningTabsOverview = class(TxsdBaseObject)
  private
    FRoomreservationId: integer;
    FRoom: string;
    FReservationId: integer;
    FRunningTabList: IList<TRunningTab>;
    function GetRunningTabList: TRunningTabList;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear; override;
  published
    property Room: string read FRoom write FRoom;
    property ReservationId: integer read FReservationId write FReservationId;
    property RoomreservationId: integer read FRoomreservationId write FRoomreservationId;
    property RunningTabList: TRunningTabList read GetRunningTabList;
  end;

implementation

uses
  XMLUtils
  ;

const
  cNameSpaceURI = '';


{ TRunningTabCustomer }

procedure TRunningTabCustomer.Clear;
begin
  inherited;
  FName := '';
  FPersonId := 0;
  FAddress2 := '';
  FZipcode := '';
  FCustomerCode := '';
  FAddress1 := '';
  FCity := '';
  FCountryCode := '';
end;

procedure TRunningTabCustomer.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
begin
  inherited;

  if aNode.SelectNodesNS(cNameSpaceURI, 'name', lNodeList, 1) then
    FName := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'address1', lNodeList, 1) then
    FAddress1 := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'address2', lNodeList, 1) then
    FAddress2 := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'zip', lNodeList, 1) then
    FZipcode := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'country', lNodeList, 1) then
    FCOuntryCode := lNodeList.GetFirst.Text;

  FCustomerCode := aNode.Attributes['roomerCode'];
  FPersonId := StrToIntDef(aNode.Attributes['PID'], -1);
end;

{ TRunningTabProduct }

procedure TRunningTabProduct.Clear;
begin
  inherited;
  FIndex := -1;
  FPurchaseDate := 0;
  FItemType := '';
  FQuantity := 0;
  FDescription := '';
  FNettoPrice := 0;
  FProductType := itUnknown;
  FAccountKey := '';
  FGrossPrice := 0;
  FVatAmount.Clear;
end;

constructor TRunningTabProduct.Create;
begin
  FVatAmount := TVATAmount.Create;
end;

destructor TRunningTabProduct.Destroy;
begin
  FVatAmount.Free;
  inherited;
end;

function TRunningTabProduct.GetItemVatAmount: double;
begin
  Result := FGrossPrice
end;

function TRunningTabProduct.GetTotalGrossAmount: double;
begin
  Result := FQuantity * FGrossPrice;
end;

function TRunningTabProduct.GetTotalNetAmount: double;
begin
  Result := FQuantity * FNettoPrice;
end;

function TRunningTabProduct.GetTotalVatAmount: double;
begin
  Result := FQuantity * FVatAmount.FAmount;
end;

procedure TRunningTabProduct.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
begin
  inherited;

  if aNode.SelectNodesNS(cNameSpaceURI, 'text', lNodeList, 1) then
    FDescription := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'purchaseDate', lNodeList, 1) then
    FPurchaseDate := XMLToDate(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(cNameSpaceURI, 'numItems', lNodeList, 1) then
    FQuantity:=  XMLToFloat(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(cNameSpaceURI, 'itemNetPrice', lNodeList, 1) then
    FNettoPrice := XMLToFloat(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(cNameSpaceURI, 'itemGrossPrice', lNodeList, 1) then
    FGrossPrice := XMLToFloat(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(cNameSpaceURI, 'itemVatAmount', lNodeList, 1) then
    FVatAmount.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  FIndex := StrToIntDef(aNode.Attributes['index'], -1);
  FProductType:= TProductType.FromString( aNode.Attributes['type']);
  FItemType := aNode.Attributes['roomerId'];
  FAccountKey := aNode.Attributes['accountKey'];
end;

{ TRunningTabsOverview }

procedure TRunningTabsOverview.Clear;
begin
  inherited;
  FRoomreservationId := -1;
  FRoom := '';
  FReservationId := -1;
  FRunningTabList.Clear;
end;

constructor TRunningTabsOverview.Create;
begin
  inherited;
  FRunningTabList := TRunningTabList.Create;
end;

destructor TRunningTabsOverview.Destroy;
begin

  inherited;
end;

function TRunningTabsOverview.GetRunningTabList: TRunningTabList;
begin
  Result := FRunningTabList as TRunningTabList;
end;

procedure TRunningTabsOverview.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
  lTabNode: PXMLNode;
  lRunningTab: TRunningTab;
begin
  inherited;

  FRoom := aNode.Attributes['room'];
  FRoomReservationid := StrToIntDef( aNode.Attributes['roomReservationId'], 0);
  FReservationId := StrToIntDef(aNode.Attributes['reservationId'], 0);

  FRunningTabList.onChanged.Enabled := false;
  try
    if aNode.SelectNodesNS(cNameSpaceURI, 'runningTab', lNodeList) then
      for lTabNode in lnodeList do
      begin
        lRunningTab := TRunningTab.Create;
        lRunningTab.SetPropertiesFromXMLNode(lTabNode);
        FRunningTabList.Add(lRunningTab);
      end;
  finally
    FRunningTabList.OnChanged.Enabled := true;
  end;
end;

{ TVATAmount }

procedure TVATAmount.Clear;
begin
  inherited;
  FVATCode := '';
  FPercentage := 0;
  FAmount := 0;
end;

procedure TVATAmount.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
begin
  inherited;

  FVATCode := aNode.Attributes['roomerCode'];
  FPercentage:= XMLToFloat( aNode.Attributes['percentage']);
  FAmount := XMLToFloat(aNode.Text);
end;

{ TRunningTabProduct.TProductTypeHelper }

class function TRunningTabProduct.TProductTypeHelper.FromString(const Value: string): TProductType;
begin
  if Value.ToUpper.Equals('ROOMRENT') then
    result := itRoomRent
  else if Value.ToUpper.Equals('STAYTAX') then
    result := itStayTax
  else if Value.ToUpper.Equals('DISCOUNT') then
    result := itDiscount
  else if Value.ToUpper.Equals('Sale') then
    result := itSale
  else
    Result := itUnknown;
end;


{ TRunningTab }


procedure TRunningTab.Clear;
begin
  inherited;
  FTabType := ttUnknown;
  FCurrencyRate := 1.0;
  FCurrency := '';
  FTotalNetAmount := 0;
  FTotalVatAmount := 0;
  FTotalGrossAmount := 0;
  FBalance := 0;
  FRunningTabCustomer.Clear;
  FProductList.Clear;
end;

constructor TRunningTab.Create;
begin
  inherited;
  FRunningTabCustomer := TRunningTabCustomer.Create;
  FProductList := TRunnningTabProductList.Create;
end;

destructor TRunningTab.Destroy;
begin
  FRunningTabCustomer.Free;
  inherited;
end;

function TRunningTab.GetRunningsTabProductList: TRunnningTabProductList;
begin
  Result := FProductList as TRunnningTabProductList;
end;

function TRunningTab.GetRunningTabCustomer: TRunningTabCustomer;
begin
  Result := FRunningTabCustomer;
end;

procedure TRunningTab.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
  lProdNode: PXMLNode;
  lProduct: TRunningTabProduct;
begin
  inherited;

  FTabType := TRunningTabType.FromString(aNode.Attributes['tapType']);
  FDescription := aNode.Attributes['description'];
  FCurrency := aNode.Attributes['currency'];
  FCurrencyRate := XMLToFloat(aNode.Attributes['currencyRate']);
  FTotalNetAmount := XMLToFloat(aNode.Attributes['totalNetAmount']);
  FTotalVatAmount := XMLToFloat(aNode.Attributes['totalVatAmount']);
  FTotalGrossAmount := XMLToFloat(aNode.Attributes['totalGrossAmount']);
  FBalance := XMLToFloat(aNode.Attributes['balance']);

  if aNode.SelectNodesNS(cNameSpaceURI, 'customer', lNodeList, 1) then
    FRunningTabCustomer.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  FProductList.onChanged.Enabled := false;
  try
    if aNode.SelectNodesNS(cNameSpaceURI, 'products/product', lNodeList) then
      for lProdNode in lnodeList do
      begin
        lProduct := TRunningTabProduct.Create;
        lProduct.SetPropertiesFromXMLNode(lProdNode);
        FProductList.Add(lProduct);
      end;
  finally
    FProductList.OnChanged.Enabled := true;
  end;
end;

{ TRunningTab.TRunningTabTypeHelper }

class function TRunningTab.TRunningTabTypeHelper.FromString(const Value: string): TRunningTabType;
begin
  if (Value.ToUpper.Equals('ROOM')) then
    Result := ttRoom
  else if (Value.ToUpper.Equals('GROUP')) then
    Result := ttGroup
  else
    Result := ttUnknown;
end;

end.
