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
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
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
//
  TVATAmount = class(TxsdBaseObject)
  private
    FVATCode: string;
    FPercentage: double;
    FAmount: double;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  public
    procedure Clear; override;
  published
    property VATCode: string read FVATCode write FVATCode;
    property Percentage: double read FPercentage write FPercentage;
    property Amount: double read FAmount write FAmount;
  end;
//
  TRunningTabProduct  = class(TxsdBaseObject)
    type
      TProducttype = (itUnknown, itRoomRent, itStayTax, itDiscount, itSale);
      TProductTypeHelper = record helper for TProductType
      public
        class function FromString(const Value: string): TProductType; static;
        function asString: string;
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
    FParent: integer;
    FRoom: string;
    FSource: string;
    FInvoiceIndex: integer;
    FGuestName: string;
    FID: integer;
    function GetTotalGrossAmount: double;
    function GetTotalNetAmount: double;
    function GetTotalVatAmount: double;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear; override;
    property TotalVatAmount: double read GetTotalVatAmount;
    property TotalGrossAmount: double read GetTotalGrossAmount;
    property ID: integer read FID write FID;
  published
    property Parent: integer read FParent write FParent;
    property Index_: integer read FIndex write FIndex;
    property ProductType: TProductType read FProductType write FProductType;
    property Item: string read FItemType write FItemType;
    property AccountKey: string read FAccountKey write FAccountKey;

    property Description: string read FDescription write FDescription;
    property PurchaseDate: TDateTime read FPurchaseDate write FPurchaseDate;
    property InvoiceIndex: integer read FInvoiceIndex write FInvoiceIndex;
    property Room: string read FRoom write FRoom;
    property Source: string read FSource write FSource;
    property GuestName: string read FGuestName write FGuestName;


    property Quantity: double read FQuantity write FQuantity;
    property NettoPrice: double read FNettoPrice write FNettoPrice;
    property GrossPrice: double read FGrossPrice write FGrossPrice;
    property ItemVatAmount: TVatAmount read FVatAmount write FVatAmount;

    property TotalNetAmount: double read GetTotalNetAmount;
  end;

  TRunnningTabProductList = class(TxsdBaseObjectList<TRunningTabProduct>)
  protected
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  end;


  TRunningTabPayment = class(TxsdBaseObject)
    type
      TInvoicePaymenttype = (iptDownPayment, iptInvoicePayment);

  private
    FCurrencyCode: String;
    FAutoGen: String;
    FNotes: String;
    FCUrrencyRate: Double;
    FPaymentType: Integer;
    FPersonId: Integer;
    FInvoicePaymentType: TInvoicePaymenttype;
    FAmount: Double;
    FDescription: String;
    FStaff: String;
    FPayDate: TDate;
    FAccountKey: String;
    FID: Integer;
    FPayTypeCode: string;
    FInvoiceIndex: integer;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  public
    procedure Clear; override;
  published
    property InvoicePaymentType: TInvoicePaymenttype read FInvoicePaymentType write FInvoicePaymentType;
    property AutoGen: String read FAutoGen write FAutoGen;
    property ID: Integer read Fid write FID;
    property PaymentType: Integer read FPaymentType write FPaymentType;
    property PayTypeCode: string read FPayTypeCode write FPayTypeCode;
    property PersonId: Integer read FPersonId write FPersonId;
    property PayDate: TDate read FPayDate write FPayDate;
    property AccountKey: String read FAccountKey write FAccountKey;
    property Amount: Double read FAmount write FAmount;
    property Description: String read FDescription write FDescription;
    property Notes: String read FNotes write FNotes;
    property Staff: String read FStaff write FStaff;
    property CurrencyCode: String read FCurrencyCode write FCurrencyCode;
    property CurrencyRate: Double read FCUrrencyRate write FCurrencyRate;
    property InvoiceIndex: integer read FInvoiceIndex write FInvoiceIndex;
  end;

  TRunningTabPaymentList = class(TxsdBaseObjectList<TRunningTabPayment>)
  protected
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  end;

  TRunningTab = class(TxsdBaseObject)
  type
    TRunningTabType = (ttUnknown, ttGroup, ttRoom);
      TRunningTabTypeHelper = record helper for TRunningTabType
      public
        class function FromString(const Value: string): TRunningTabType; static;
        function AsString: string;
      end;
  private
    FTabType: TRunningTabType;
    FCurrencyRate: double;
    FDescription: string;
    FCurrency: string;
    FProductList: IList<TRunningTabProduct>;
    FPaymentList: IList<TRunningTabPayment>;
    FRunningTabCustomer: TRunningTabCustomer;
    FTotalVatAmount: double;
    FTotalNetAmount: double;
    FTotalGrossAmount: double;
    FBalance: double;
    function GetRunningTabProductList: TRunnningTabProductList;
    function GetRunningTabCustomer: TRunningTabCustomer;
    function GetRunningTabPaymentList: TRunningTabPaymentList;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
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
    property ProductList: TRunnningTabProductList read GetRunningTabProductList;
    property PaymentList: TRunningTabPaymentList read GetRunningTabPaymentList;
  end;

  TRunningTabList = class(TxsdBaseObjectList<TRunningTab>)
  protected
    class function GetNodeName: string; override;
  end;


  TRunningTabsOverview = class(TxsdBaseObject)
  private
    FRoomreservationId: integer;
    FRoom: string;
    FReservationId: integer;
    FRunningTabList: IList<TRunningTab>;
    function GetRunningTabList: TRunningTabList;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
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
  GetNameSpaceURI = '';


{ TRunningTabCustomer }

procedure TRunningTabCustomer.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;

  aNode.Attributes['roomerCode'] := CustomerCode;
  aNode.Attributes['PID'] := IntToStr(PersonId);
  aNode.AddChild('name').Text := Name;
  aNode.AddChild('address1').Text := Address1;
  aNode.AddChild('address2').Text := Address2;
  aNode.AddChild('zip').Text := Zipcode;
  aNode.AddChild('country').Text := CountryCode;

end;

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

class function TRunningTabCustomer.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TRunningTabCustomer.GetNodeName: string;
begin
  Result := 'customer';
end;

procedure TRunningTabCustomer.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
begin
  inherited;

  if aNode.SelectNodesNS(GetNameSpaceURI, 'name', lNodeList, 1) then
    FName := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'address1', lNodeList, 1) then
    FAddress1 := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'address2', lNodeList, 1) then
    FAddress2 := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'zip', lNodeList, 1) then
    FZipcode := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'country', lNodeList, 1) then
    FCOuntryCode := lNodeList.GetFirst.Text;

  FCustomerCode := aNode.Attributes['roomerCode'];
  FPersonId := StrToIntDef(aNode.Attributes['PID'], -1);
end;

{ TRunningTabProduct }

procedure TRunningTabProduct.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;


  aNode.Attributes['index'] := IntToStr(Index_);
  aNode.Attributes['type'] := ProductType.AsString;
  aNode.Attributes['roomerId'] := Item;
  aNode.Attributes['accountKey'] := AccountKey;
  aNode.Attributes['invoiceIndex'] := IntToStr(InvoiceIndex);
  aNode.Attributes['room'] := Room;
  aNode.Attributes['source'] := Source;
  aNode.Attributes['guestName'] := GuestName;

  aNode.AddChild('text1').Text := Description;
  aNode.AddChild('purchaseDate').Text := DateToXML(PurchaseDate);
  aNode.AddChild('numItems').Text := FloatToXML(Quantity);
  aNode.AddChild('itemNetPrice').Text := FloatToXML(NettoPrice);
  aNode.AddChild('itemGrossPrice').Text := FLoatToXML(GrossPrice);
  ItemVatAmount.AddPropertiesToXMLNode(aNode.AddChild(''));
end;

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
  FParent := -1;
  FRoom := '';
  FSource:= '';
  FInvoiceIndex := 0;
  FGuestName := '';
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

class function TRunningTabProduct.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TRunningTabProduct.GetNodeName: string;
begin
  Result := 'product';
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

  if aNode.SelectNodesNS(GetNameSpaceURI, 'text1', lNodeList, 1) then
    FDescription := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'purchaseDate', lNodeList, 1) then
    FPurchaseDate := XMLToDate(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'numItems', lNodeList, 1) then
    FQuantity:=  XMLToFloat(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'itemNetPrice', lNodeList, 1) then
    FNettoPrice := XMLToFloat(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'itemGrossPrice', lNodeList, 1) then
    FGrossPrice := XMLToFloat(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'itemVatAmount', lNodeList, 1) then
    FVatAmount.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  FID := StrTointDef(aNode.Attributes['id'], -1);
  FIndex := StrToIntDef(aNode.Attributes['index'], -1);
  FProductType:= TProductType.FromString( aNode.Attributes['type']);
  FItemType := aNode.Attributes['roomerId'];
  FAccountKey := aNode.Attributes['accountKey'];
  FInvoiceIndex := StrToIntDef(aNode.Attributes['invoiceIndex'], -1);
  FRoom := aNode.Attributes['room'];
  FSource := aNode.Attributes['source'];
  FGuestName := aNode.Attributes['guestName'];
end;

{ TRunningTabsOverview }

procedure TRunningTabsOverview.AddPropertiesToXMLNode(const aNode: PXMLNode);
var
  lRunTab: TRunningTab;
begin
  inherited;
  aNode.NodeName := 'runningTabs';

  aNode.Attributes['room'] := FRoom;
  aNode.Attributes['roomReservationdId'] := IntToStr(FRoomreservationId);
  aNode.Attributes['reservationdId'] := IntToStr(FReservationId);
  for lRunTab in FRunningTabList do
    lRunTab.AddPropertiesToXMLNode(aNode.AddChild(''));
end;

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
  FRunningTabList := TRunningTabList.Create;
end;

destructor TRunningTabsOverview.Destroy;
begin

  inherited;
end;

class function TRunningTabsOverview.GetNodeName: string;
begin
  Result := '';
end;

function TRunningTabsOverview.GetRunningTabList: TRunningTabList;
begin
  Result := FRunningTabList as TRunningTabList;
end;

procedure TRunningTabsOverview.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;

  FRoom := aNode.Attributes['room'];
  FRoomReservationid := StrToIntDef( aNode.Attributes['roomReservationId'], 0);
  FReservationId := StrToIntDef(aNode.Attributes['reservationId'], 0);

  RunningTabList.SetPropertiesFromXMLNode(aNode);
end;

{ TVATAmount }

procedure TVATAmount.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  aNode.Attributes['roomerCode'] := Vatcode;
  aNode.Attributes['percentage'] := FloatToXML(Percentage);
  aNode.Text := FloatToXML(Amount);
end;

procedure TVATAmount.Clear;
begin
  inherited;
  FVATCode := '';
  FPercentage := 0;
  FAmount := 0;
end;

class function TVATAmount.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TVATAmount.GetNodeName: string;
begin
  Result := 'itemVatAmount';
end;

procedure TVATAmount.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;

  FVATCode := aNode.Attributes['roomerCode'];
  FPercentage:= XMLToFloat( aNode.Attributes['percentage']);
  FAmount := XMLToFloat(aNode.Text);
end;

{ TRunningTabProduct.TProductTypeHelper }

function TRunningTabProduct.TProductTypeHelper.asString: string;
begin
  case Self of
    itRoomRent: Result := 'ROOMRENT';
    itStayTax:  Result := 'STAYTAX';
    itDiscount: Result := 'DISCOUNT';
    itSale:     Result := 'SALE';
  else
    Result := 'UNKNOWN';
  end;
end;

class function TRunningTabProduct.TProductTypeHelper.FromString(const Value: string): TProductType;
begin
  if Value.ToUpper.Equals('ROOMRENT') then
    result := itRoomRent
  else if Value.ToUpper.Equals('STAYTAX') then
    result := itStayTax
  else if Value.ToUpper.Equals('DISCOUNT') then
    result := itDiscount
  else if Value.ToUpper.Equals('SALE') then
    result := itSale
  else
    Result := itUnknown;
end;


{ TRunningTab }


procedure TRunningTab.AddPropertiesToXMLNode(const aNode: PXMLNode);
var
  lProd: TRunningTabProduct;
  lPay: TRunningTabPayment;
begin
  inherited;

  aNode.Attributes['tabType'] := TabType.AsString;
  aNode.Attributes['description'] := Description;
  aNode.Attributes['currency'] := Currency;
  aNode.Attributes['currenyRate'] := FloatToXML(CurrencyRate);
  aNode.Attributes['totalNetAmount'] := FloatToXML(TotalNetAmount);
  aNode.Attributes['totalVatAmount'] := FloatToXML(TotalVatAmount);
  aNode.Attributes['totalGrossAmount'] := FloatToXML(TotalGrossAmount);
  aNode.Attributes['balance'] := FloatToXML(Balance);

  FRunningTabCustomer.AddPropertiesToXMLNode(aNode.AddChild(''));

  for lProd in FProductList do
    lProd.AddPropertiesToXMLNode(aNode.AddChild(''));

  for lPay in FPaymentList do
    lPay.AddPropertiesToXMLNode(aNode.AddChild(''));

end;

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
  FPaymentList := TRunningTabPaymentList.Create;
end;

destructor TRunningTab.Destroy;
begin
  FRunningTabCustomer.Free;
  inherited;
end;

function TRunningTab.GetRunningTabPaymentList: TRunningTabPaymentList;
begin
  Result := FPaymentList as TRunningTabPaymentList;
end;

function TRunningTab.GetRunningTabProductList: TRunnningTabProductList;
begin
  Result := FProductList as TRunnningTabProductList;
end;

class function TRunningTab.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TRunningTab.GetNodeName: string;
begin
  Result := 'runningTab';
end;

function TRunningTab.GetRunningTabCustomer: TRunningTabCustomer;
begin
  Result := FRunningTabCustomer;
end;

procedure TRunningTab.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
begin
  inherited;

  FTabType := TRunningTabType.FromString(aNode.Attributes['tabType']);
  FDescription := aNode.Attributes['description'];
  FCurrency := aNode.Attributes['currency'];
  FCurrencyRate := XMLToFloat(aNode.Attributes['currencyRate']);
  FTotalNetAmount := XMLToFloat(aNode.Attributes['totalNetAmount']);
  FTotalVatAmount := XMLToFloat(aNode.Attributes['totalVatAmount']);
  FTotalGrossAmount := XMLToFloat(aNode.Attributes['totalGrossAmount']);
  FBalance := XMLToFloat(aNode.Attributes['balance']);

  if aNode.SelectNodesNS(FRunningTabCustomer.GetNameSpaceURI, FRunningTabCustomer.GetNodeName, lNodeList, 1) then
    FRunningTabCustomer.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(ProductList.GetNameSpaceURI, ProductList.GetNodeName, lNodeList, 1) then
    ProductList.SetPropertiesFromXMLNode(lNodeList.GetFirst());

  if aNode.SelectNodesNS(PaymentList.GetNameSpaceURI, PaymentList.GetNodeName, lNodeList, 1) then
    PaymentList.SetPropertiesFromXMLNode(lNodeList.GetFirst());
end;

{ TRunningTab.TRunningTabTypeHelper }

function TRunningTab.TRunningTabTypeHelper.AsString: string;
begin
  case Self of
    ttRoom: Result := 'ROOM';
    ttGroup: Result := 'GROUP';
  else
    Result := 'UNKNONW';
  end;
end;

class function TRunningTab.TRunningTabTypeHelper.FromString(const Value: string): TRunningTabType;
begin
  if (Value.ToUpper.Equals('ROOM')) then
    Result := ttRoom
  else if (Value.ToUpper.Equals('GROUP')) then
    Result := ttGroup
  else
    Result := ttUnknown;
end;

{ TRunningTabPayment }

procedure TRunningTabPayment.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
//  aNOde.Attributes[''] := InvoicePaymentType := iptInvoicePayment;
  aNode.Attributes['id'] := IntToStr(ID);
  aNode.Attributes['paymentType'] := IntToStr(PaymentType);
  aNode.Attributes['roomerCode'] := PayTypeCode;
  aNode.Attributes['accountKey'] := AccountKey;
  aNode.Attributes['currency'] := CurrencyCode;
  aNode.Attributes['currencyRate'] := FloatToXML(CurrencyRate);

  aNode.AddChild('description').Text := Description;
  aNode.AddChild('notes').Text := Notes;
  aNode.AddChild('paymentDate').Text := DateToXML(PayDate);
  aNode.AddChild('amount').Text := FloatToXML(Amount);

end;

procedure TRunningTabPayment.Clear;
begin
  inherited;
  FCurrencyCode := '';
  FAutoGen := '';
  FNotes := '';
  FCUrrencyRate := 1;
  FPaymentType := 0;
  FPayTypeCode := '';
  FPersonId := 0;
  FInvoicePaymentType := iptInvoicePayment;
  FAmount := 0;
  FDescription := '';
  FStaff := '';
  FPayDate := 0;
  FAccountKey := '';
  FID := -1;
end;

class function TRunningTabPayment.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TRunningTabPayment.GetNodeName: string;
begin
  Result := 'payment';
end;

procedure TRunningTabPayment.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
begin
  inherited;

  InvoicePaymentType := iptInvoicePayment;
  ID := StrToIntdef(aNode.Attributes['id'], -1);
  PaymentType := StrToIntdef(aNode.Attributes['paymentType'], -1);
  PayTypeCode := aNode.Attributes['roomerCode'];
  AccountKey := aNode.Attributes['accountKey'];
  CurrencyCode := aNode.Attributes['currency'];
  CurrencyRate := XMLToFloat(aNode.Attributes['currencyRate'], 1.00);
  FInvoiceIndex := StrToIntDef(aNode.Attributes['invoiceIndex'], -1);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'description', lNodeList, 1) then
    FDescription:=  lNodeList.GetFirst.Text;

  if aNode.SelectNodesNS(GetNameSpaceURI, 'notes', lNodeList, 1) then
    FNotes :=  lNodeList.GetFirst.Text;

  if aNode.SelectNodesNS(GetNameSpaceURI, 'paymentDate', lNodeList, 1) then
    FPayDate :=  XMLToDate(lNodeList.GetFirst.Text);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'amount', lNodeList, 1) then
    FAmount := XMLToFloat(lNodeList.GetFirst.Text, 0.00);
end;

{ TRunningTabPaymentList }

class function TRunningTabPaymentList.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TRunningTabPaymentList.GetNodeName: string;
begin
  Result := 'payments';
end;

{ TRunnningTabProductList }

class function TRunnningTabProductList.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TRunnningTabProductList.GetNodeName: string;
begin
  Result := 'products';
end;

{ TRunningTabList }

class function TRunningTabList.GetNodeName: string;
begin
  Result := 'runningTabs';
end;

end.
