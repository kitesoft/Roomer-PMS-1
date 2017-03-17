unit RoomerFinancialDataModel_ModelObjects;

interface

uses
   Classes
   , SysUtils
   , Spring.Collections.Lists
   , Spring.Collections
   , uRoomerSchema
   , XMLIntf
   , OXmlPDOM
   , uRoomerCanonicalDataModel_BaseTypes
   , uRoomerCanonicalDataModel_SimpleTypes
   ;

const
  cRmrfmoNameSpaceURI = 'http://roomer.promoir.nl/datamodel/financial/modelobjects/2014/01/';

type

{$SCOPEDENUMS ON}

{$REGION 'CreationTypeType XSD Definition'}
  //<simpleType name="CreationTypeType">
  //		<restriction base="string">
  //			<enumeration value="EXTERNAL_SYSTEM"/>
  //			<enumeration value="MANUAL"/>
  //			<enumeration value="PACKAGE"/>
  //			<enumeration value="ROOMER_SYSTEM"/>
  //		</restriction>
  //	</simpleType>
{$ENDREGION}
  TxsdCreationType = (EXTERNAL_SYSTEM, MANUAL, PACKAGE, ROOMER_SYSTEM);
  TxsdCreationTypeHelper = record helper for TxsdCreationType
    class function FromString(const aString: string): TxsdCreationType; static;
    function AsString: String;
  end;

  TxsdAmountType = class(TxsdAmountGroup)
  private const
    cNodeName = 'AmountType';
  protected
    class function GetNameSpaceURI: string; override;
    class function GetNodeName: string; override;
  end;

{$REGION 'TaxType xsd definition'}
  //  	<complexType name="TaxType">
  //		<attribute name="description" type="string" use="required"/>
  //		<attributeGroup ref="rmrbt:AmountGroup"/>
  //	</complexType>
{$ENDREGION}
  TxsdTaxType = class(TxsdBaseObject)
  private
    FDescription: string;
    FAmount: TxsdAmountGroup;
  published
    property Description: string read FDescription write FDescription;
    property Amount: TxsdAmountGroup read FAmount write FAmount;
  end;


{$REGION 'CurrencyConversionRateType xsd definition'}
  //	<complexType name="CurrencyConversionRateType">
  //		<attribute name="from" type="rmrst:ISO4217CurrencyCode" use="required" />
  //		<attribute name="to" type="rmrst:ISO4217CurrencyCode" use="required" />
  //		<attribute name="factor" type="rmrfmo:ConversionFactorType" use="required" />
  //		<attribute name="date" type="dateTime" use="required" />
  //	</complexType>
{$ENDREGION}
  TxsdCurrencyConversionRateType = class abstract(TxsdBaseObject)
  private
    FFrom: TxsdISO4217CurrencyCode;
    FDate: TDateTime;
    FFactor: double;
    FTo: TxsdISO4217CurrencyCode;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property From: TxsdISO4217CurrencyCode read FFrom write FFrom;
    property To_: TxsdISO4217CurrencyCode read FTo write FTo;
    property Factor: double read FFactor write FFactor;
    property Date: TDateTime read FDate write FDate;
  end;


  TxsdInvoiceLineEntryType = class abstract(TxsdBaseObject)
  public
    class function CreateInvoiceLineEntryType(aNode: PXMLNode): TxsdInvoiceLineEntryType;
  end;


  TxsdInvoiceLineEntryTypeClass = class of TxsdInvoiceLineEntryType;

{$REGION 'PaymentType XSD definition'}
//	<complexType name="PaymentType">
//		<attribute name="id" type="ID"/>
//		<attribute name="paymentReference" type="string" use="required" />
//		<attribute name="paymentMethod" type="string" use="required" />
//		<attribute name="date" type="dateTime" use="required" />
//		<attributeGroup ref="rmrbt:AmountGroup" />
//	</complexType>
{$ENDREGION}
  TxsdPaymentType = class(TxsdInvoiceLineEntryType)
  private
    FID: string;
    FPaymentReference: string;
    FPaymentMethod: string;
    FDate: TDateTime;
    FAmount: TxsdAmountGroup;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property ID: string read FID write FID;
    property PaymentReference: string read FPaymentReference write FPaymentReference;
    property PaymentMethod: string read FPaymentMethod write FPaymentMethod;
    property Date: TDateTime read FDate write FDate;
    property Amount: TxsdAmountGroup read FAmount write FAmount;
  end;

{$REGION 'TextEntryType XSD definition'}
//	<complexType name="TextEntryType">
//		<attribute name="id" type="ID"/>
//		<attribute name="text" type="string" use="required"/>
//		<attribute name="date" type="date" use="required"/>
//	</complexType>
{$ENDREGION}
  TxsdTextEntryType = class(TxsdInvoiceLineEntryType)
  private
    FID: string;
    FText: string;
    FDate: TDate;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property ID: string read FID write FID;
    property Text: string read FText write FText;
    property Date: TDate read FDate write FDate;
  end;


{$REGION 'BillableEntryType XSD definition'}
//  	<complexType name="BillableEntryType">
//  		<sequence>
//  			<element name="unitPrice" type="rmrfmo:AmountType" minOccurs="0"/>
//  			<element name="convertedUnitPrice" type="rmrfmo:AmountType" minOccurs="0" />
//  			<element name="conversionRate" type="rmrfmo:CurrencyConversionRateType" minOccurs="0" />
//  			<element name="totalPrice" type="rmrfmo:AmountType" />
//  		</sequence>
//  		<attribute name="id" type="ID"/>
//  		<attribute name="description" type="string" use="optional" />
//  		<attribute name="productId" type="string" use="optional" />
//  		<attribute name="number" type="double" use="required" />
//  		<attribute name="purchaseDateTime" type="dateTime" use="required" />
//  	</complexType>
{$ENDREGION}
  TxsdBillableEntryType = class abstract(TxsdInvoiceLineEntryType)
  private
    FID: string;
    FDescription: string;
    FProductID: string;
    FNumber: double;
    FPurchaseDateTime: TDateTime;
    FUnitPrice: TxsdAmountType;
    FConvertedUnitPrice: TxsdAmountType;
    FTotalPrice: TxsdAmountType;
    FConversionRate: TxsdCurrencyConversionRateType;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property ID: string read FID write FID;
    property Description: string read FDescription write FDescription;
    property ProductID: string read FProductID write FProductID;
    property Number: double read FNumber write FNumber;
    property PurchaseDateTime: TDateTime read FPurchaseDateTime write FPurchaseDateTime;
    property UnitPrice: TxsdAmountType read FUnitPrice write FUnitPrice;
    property ConvertedUnitPrice: TxsdAmountType read FConvertedUnitPrice write FConvertedUnitPrice;
    property ConversionRate: TxsdCurrencyConversionRateType read FConversionRate write FConversionRate;
    property TotalPrice: TxsdAmountType read FTotalPrice write FTotalPrice;
  end;

{$REGION 'BillableEntryStatus XSD definition'}
  //	<simpleType name="BillableEntryStatus">
  //		<restriction base="string">
  //			<enumeration value="PAID"/>
  //			<enumeration value="UNPAID"/>
  //		</restriction>
  //	</simpleType>
{$ENDREGION}
  TxsdBillableEntryStatus = (PAID, UNPAID);
  TxsdBillableEntryStatusHelper = record helper for TxsdBillableEntryStatus
    class function FromString(const aString: string): TxsdBillableEntryStatus; static;
    function AsString: String;
  end;

{$REGION 'DiscountBillableEntryType XSD Definition'}
  //	<complexType name="DiscountBillableEntryType">
  //		<complexContent>
  //			<extension base="rmrfmo:ExtendedBillableEntryType">
  //				<attribute name="appliesTo" type="string">
  //					<annotation>
  //						<documentation>A reference to the ID attribute of the BillableEntry to which this discount is being applied (if there is one; otherwise this is a general discount for the entire invoice).</documentation>
  //					</annotation>
  //				</attribute>
  //			</extension>
  //		</complexContent>
  //	</complexType>

{$ENDREGION}
  TxsdDiscountBillableEntryType = class(TxsdBillableEntryType)
  private
    FAppliesTo: string;
  public
    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property AppliesTo: string read FAppliesTo write FAppliesTo;
  end;

  TxsdAmount = TxsdAmountGroup;

{$REGION 'ExtendedBillableEntryType xsd definition'}
  //	<complexType name="ExtendedBillableEntryType">
  //		<complexContent>
  //			<extension base="rmrfmo:BillableEntryType">
  //				<sequence>
  //					<element name="PaymentUnitPrice" type="rmrfmo:AmountType" minOccurs="0">
  //						<annotation>
  //							<documentation>The price per unit in the currency in which the guest wants to be charged.</documentation>
  //						</annotation>
  //					</element>
  //					<element name="PaymentConversionRate" type="rmrfmo:CurrencyConversionRateType" minOccurs="0"/>
  //					<element name="TotalPriceGross" type="rmrfmo:AmountType" minOccurs="0">
  //						<annotation>
  //							<documentation>The total price excluding taxes.</documentation>
  //						</annotation>
  //					</element>
  //					<element name="TotalConvertedPriceGross" type="rmrfmo:AmountType" minOccurs="0"/>
  //					<element name="TotalConvertedPriceNet" type="rmrfmo:AmountType" minOccurs="0"/>
  //					<element name="TotalPaymentPriceGross" type="rmrfmo:AmountType" minOccurs="0"/>
  //					<element name="TotalPaymentPriceNet" type="rmrfmo:AmountType" minOccurs="0"/>
  //					<element name="ApplicableTax" type="rmrfmo:TaxType" minOccurs="0" maxOccurs="unbounded"/>
  //				</sequence>
  //				<attribute name="status" type="rmrfmo:BillableEntryStatus" use="required"/>
  //				<attribute name="applicationDate" type="date" use="required">
  //					<annotation>
  //						<documentation>This is the date to which the billable entry applies. For example, this date might indicate that this entry is the room rent for March 12, 2015.</documentation>
  //					</annotation>
  //				</attribute>
  //				<attribute name="paymentDateTime" type="dateTime"/>
  //			</extension>
  //		</complexContent>
  //	</complexType>

{$ENDREGION}
  TxsdExtendedBillableEntryType = class(TxsdBillableEntryType)
  private const
    cNodeName = 'SalesItem';
  private
    FPaymentUnitPrice: TxsdAmountType;
    FPaymentConversionRate: TxsdCurrencyConversionRateType;
    FTotalPriceGross: TxsdAmountType;
    FTotalConvertedPriceGross: TxsdAmountType;
    FTotalConvertedPriceNet: TxsdAmountType;
    FApplicableTax: TxsdTaxType;
    FStatus: TxsdBillableEntryStatus;
    FApplicationDate: TDate;
    FPaymentDateTime: TDateTime;
    FTotalPaymentPriceNet: TxsdAmount;
    FTotalPaymentPriceGross: TxsdAmount;
  protected
    class function GetNameSpaceURI: string; override;
    class function GetNodeName: string; override;
  public
    constructor Create; override;
    destructor Destroy; override;
    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property PaymentUnitPrice: TxsdAmountType read FPaymentUnitPrice write FPaymentUnitPrice;
    property PaymentConversionRate: TxsdCurrencyConversionRateType read FPaymentConversionRate write FPaymentConversionRate;
    property TotalPriceGross: TxsdAmountType read FTotalPriceGross write FTotalPriceGross;
    property TotalConvertedPriceGross: TxsdAmountType read FTotalConvertedPriceGross write FTotalConvertedPriceGross;
    property TotalConvertedPriceNet: TxsdAmountType read FTotalConvertedPriceNet write FTotalConvertedPriceNet;
    property TotalPaymentPriceGross: TxsdAmount read FTotalPaymentPriceGross write FTotalPaymentPriceGross;
    property TotalPaymentPriceNet: TxsdAmount read FTotalPaymentPriceNet write FTotalPaymentPriceNet;
    property ApplicableTax: TxsdTaxType read FApplicableTax write FApplicableTax;
    property Status: TxsdBillableEntryStatus read FStatus write FStatus;
    property ApplicationDate: TDate read FApplicationDate write FApplicationDate;
    property PaymentDateTime: TDateTime read FPaymentDateTime write FPaymentDateTime;
  end;

  TxsdCurrencyData = class(TxsdBaseObject)
  private const
    cNodeName = 'CurrencyData';
  private
    FInvoiceCurrency: TxsdISO4217CurrencyCode;
    FConversionFromHotelCurrency: TxsdCurrencyConversionRateType;
  protected
    class function GetNameSpaceURI: string; override;
    class function GetNodeName: string; override;
  public
    constructor Create;
    destructor Destroy; override;

    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property InvoiceCurrency: TxsdISO4217CurrencyCode read FInvoiceCurrency write FInvoiceCurrency;
    property ConversionFromHotelCurrency: TxsdCurrencyConversionRateType read FConversionFromHotelCurrency write FConversionFromHotelCurrency;
  end;


{$REGION 'InvoiceLineType XSD definition'}
//<complexType name="InvoiceLineType">
//		<sequence>
//			<choice>
//				<element name="SalesItem" type="rmrfmo:ExtendedBillableEntryType"/>
//				<element name="DiscountItem" type="rmrfmo:DiscountBillableEntryType"/>
//				<element name="PaymentItem" type="rmrfmo:PaymentType"/>
//				<element name="TextItem" type="rmrfmo:TextEntryType"/>
//			</choice>
//			<element name="Remarks" type="rmrbt:RemarksType" minOccurs="0"/>
//		</sequence>
//		<attribute name="index" type="integer" use="required"/>
//		<attribute name="creatorId" type="string" use="required"/>
//		<attribute name="creationType" type="rmrfmo:CreationTypeType" use="required"/>
//	</complexType>
{$ENDREGION}
  TxsdInvoiceLineType = class(TxsdBaseObject)
  private const
    cNodeName = 'LineItem';
  private
    Findex_: integer;
    FCreatorId: string;
    FCreationType: TxsdCreationType;
    FRemarks: TxsdRemarksType;
    FItem: TxsdInvoiceLineEntryType;

  protected
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;

  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property index_: integer read Findex_ write Findex_;
    property CreatorId: string read FCreatorId write FCreatorId;
    property CreationType: TxsdCreationType read FCreationType write FCreationType;
    property Remarks: TxsdRemarksType read FRemarks write FRemarks;
    property Item: TxsdInvoiceLineEntryType read FItem write FItem;

  end;

  TxsdInvoiceLineTypeList = class(TxsdBaseObjectList<TxsdInvoiceLineType>)
  end;

{$REGION 'CustomerData xsd definition'}
  //			<element name="CustomerData" minOccurs="0">
  //				<complexType>
  //					<attribute name="customer" type="string"/>
  //					<attribute name="customerReference" type="string"/>
  //				</complexType>
  //			</element>
{$ENDREGION}
  TxsdCustomerData = class(TxsdBaseObject)
  private const
    cNodeName = 'CustomerData';
  private
    FCustomerReference: string;
    FCustomer: string;
  protected
    class function GetNameSpaceURI: string; override;
    class function GetNodeName: string; override;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property Customer: string read FCustomer write FCustomer;
    property CustomerReference: string read FcustomerReference write FcustomerReference ;
  end;

  TxsdGuestAddress = class(TxsdSimplifiedAddressType)
  private const
    cNodeName = 'GuestData';
  protected
    class function GetNameSpaceURI: string; override;
    class function GetNodeName: string; override;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  end;

  TxsdGuestData = class(TxsdBaseObject)
  private const
    cNodeName = 'GuestData';
  private
    FName: string;
    FAddress: TxsdGuestAddress;
  protected
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property Name: string read FName write FName;
    property Address: TxsdGuestAddress read FAddress write FAddress;
  end;


{$REGION 'InvoiceTypeType xsd Definition'}
  //	<simpleType name="InvoiceTypeType">
  //		<restriction base="string">
  //			<enumeration value="CREDIT"/>
  //			<enumeration value="DEBIT"/>
  //		</restriction>
  //	</simpleType>
{$ENDREGION}
  TxsdInvoiceTypeType = (CREDIT, DEBET);
  TxsdInvoiceTypeTypeHelper = record helper for TxsdInvoiceTypeType
    class function FromString(const aString: string): TxsdInvoiceTypeType; static;
    function AsString: String;
  end;

{$REGION 'InvoiceStateType xsd Definition'}
  //	<simpleType name="InvoiceStateType">
  //		<restriction base="string">
  //			<enumeration value="CLOSED"/>
  //			<enumeration value="OPEN"/>
  //		</restriction>
  //	</simpleType>
{$ENDREGION}
  TxsdInvoiceStateType = (CLOSED, OPEN);
  TxsdInvoiceStateTypeHelper = record helper for TxsdInvoiceStateType
    class function FromString(const aString: string): TxsdInvoiceStateType; static;
    function AsString: String;
  end;

{$REGION 'ExtendedInvoiceType XSD definition'}
//	<complexType name="ExtendedInvoiceType">
//		<sequence>
//			<element name="LineItem" type="rmrfmo:InvoiceLineType" maxOccurs="unbounded" minOccurs="0"/>
//			<element name="CustomerData" minOccurs="0">
//				<complexType>
//					<attribute name="customer" type="string"/>
//					<attribute name="customerReference" type="string"/>
//				</complexType>
//			</element>
//			<element name="GuestData">
//				<complexType>
//					<sequence>
//						<element name="Name" type="string"/>
//						<element name="Address" type="rmrbt:SimplifiedAddressType"/>
//					</sequence>
//				</complexType>
//			</element>
//			<element name="CurrencyData" minOccurs="0">
//				<complexType>
//					<sequence>
//						<element name="InvoiceCurrency" type="rmrst:ISO4217CurrencyCode"/>
//						<element name="ConversionFromHotelCurrency" type="rmrfmo:CurrencyConversionRateType"/>
//					</sequence>
//				</complexType>
//			</element>
//		</sequence>
//		<attribute name="id" type="ID" use="required"/>
//		<attribute name="reservation" type="string" use="required"/>
//		<attribute name="roomReservation" type="string" use="optional"/>
//		<attribute name="index" type="integer" use="required"/>
//		<attribute name="number" type="string" use="optional"/>
//		<attribute name="type" type="rmrfmo:InvoiceTypeType" use="required"/>
//		<attribute name="state" type="rmrfmo:InvoiceStateType" use="required"/>
//		<attribute name="originalInvoice" type="string" use="optional">
//			<annotation>
//				<documentation>In case this is a credit invoice, this attribute refers to the invoice being credited.</documentation>
//			</annotation>
//		</attribute>
//		<attribute name="date" type="date"/>
//		<attribute name="printDateTime" type="dateTime"/>
//		<attribute name="printedBy" id="string"/>
//	</complexType>
{$ENDREGION}
  TxsdExtendedInvoiceType = class abstract(TxsdBaseObject)
  private const
    cNodeName = 'ExtendedInvoiceType';
  protected
    class function GetNameSpaceURI: string; override;
    class function GetNodeName: string; override;
  private
    FInvoiceLineTypeList: IList<TxsdInvoiceLineType>;
    FGuestData: TxsdGuestData;
    FCurrencyData: TxsdCurrencyData;
    FCustomerData: TxsdCustomerData;
    FID: string;
    FReservation: string;
    FRoomReservation: string;
    FIndex_: integer;
    FNumber: string;
    FType: TxsdInvoiceTypeType;
    FState: TxsdInvoiceStateType;
    FOriginalInvoice: string;
    FDate: TDate;
    FPrintDateTime: TDateTime;
    FPrintedBy: string;
    function GetInvoiceLineTypeList: TxsdInvoiceLineTypeList;
  public
    constructor Create;
    destructor Destroy; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property ID: string read FID write FID;
    property Reservation: string read FReservation write FReservation;
    property RoomReservation: string read FRoomReservation write FRoomReservation;
    property Index_: integer read FIndex_ write FIndex_;
    property Number: string read FNumber write FNumber;
    property Type_: TxsdInvoiceTypeType read FType write FType;
    property State: TxsdInvoiceStateType read FState write FState;
    property OriginalInvoice: string read FOriginalInvoice write FOriginalInvoice;
    property Date: TDate read FDate write FDate;
    property PrintDateTime: TDateTime read FPrintDateTime write FPrintDateTime;
    property PrintedBy: string read FPrintedBy write FPrintedBy;

    property LineItemList: TxsdInvoiceLineTypeList read GetInvoiceLineTypeList;
    property CustomerData: TxsdCustomerData read FCustomerData write FCustomerData;
    property GuestData: TxsdGuestData read FGuestData write FGuestData;
    property CurrencyData: TxsdCurrencyData read FCurrencyData write FCurrencyData;
  end;

implementation

uses
  TypInfo
  , XmlUtils, uExceptionUtils;

{ TxsdExtendedInvoiceType }

procedure TxsdExtendedInvoiceType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  RaiseMethodNotImplementedException;
end;

constructor TxsdExtendedInvoiceType.Create;
begin
  FInvoiceLineTypeList := TxsdInvoiceLineTypeList.Create;
  FGuestData := TxsdGuestData.Create;
  FCurrencyData :=TxsdCurrencyData.Create;
  FCustomerData := TxsdCustomerData.Create;
end;

destructor TxsdExtendedInvoiceType.Destroy;
begin
  inherited;
  FGuestData.Free;
  FCurrencyData.Free;
  FCustomerData.Free;
end;

function TxsdExtendedInvoiceType.GetInvoiceLineTypeList: TxsdInvoiceLineTypeList;
begin
  Result := FInvoiceLineTypeList as TxsdInvoiceLineTypeList;
end;

class function TxsdExtendedInvoiceType.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI;
end;

class function TxsdExtendedInvoiceType.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TxsdExtendedInvoiceType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodes: IXMLNodeList;
begin
  inherited;
  FID := aNode.Attributes['id'];
  FReservation := aNode.Attributes['reservation'];
  FRoomReservation := aNode.Attributes['roomReservation'];
  FIndex_ := StrToIntDef( aNode.Attributes['index'], 0);
  FNumber := aNode.Attributes['number'];
  Type_ := TxsdInvoiceTypeType.FromString(aNode.Attributes['type']);
  State := TxsdInvoiceStateType.FromString(aNode.Attributes['state']);
  FOriginalInvoice := anode.Attributes['originalInvoice'];
  FDate := XMLToDate(aNode.Attributes['date']);
  FPrintDateTime := XMLToDateTime(aNode.Attributes['printDateTime']);
  FPrintedBy := aNode.Attributes['printedBy'];

  if aNode.SelectNodesNS(FCustomerData.GetNameSpaceURI, FCustomerData.GetNodeName, lNodes) then
    FCustomerData.SetPropertiesFromXMLNode(lNodes.GetFirst);

  if aNode.SelectNodesNS(FGuestData.GetNameSpaceURI, FGuestData.GetNodeName, lNodes) then
    FGuestData.SetPropertiesFromXMLNode(lNodes.GetFirst);

  if aNode.SelectNodesNS(FCurrencyData.GetNameSpaceURI, FCurrencyData.GetNodeName, lNodes) then
    FCurrencyData.SetPropertiesFromXMLNode(lNodes.GetFirst);

  LineItemList.SetPropertiesFromXMLNode(aNode);
end;

{ TxsdCurrencyData }

procedure TxsdCurrencyData.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  aNode.AddChild('InvoiceCurrency').Text := InvoiceCurrency.AsString;
  ConversionFromHotelCurrency.AddPropertiesToXMLNode(aNode.AddChild('ConversionFromHotelCurrency'));
end;

constructor TxsdCurrencyData.Create;
begin
  FConversionFromHotelCurrency := TxsdCurrencyConversionRateType.Create;
end;

destructor TxsdCurrencyData.Destroy;
begin
  inherited;
  FConversionFromHotelCurrency.Free;
end;

class function TxsdCurrencyData.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI;
end;

class function TxsdCurrencyData.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TxsdCurrencyData.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodeList: IXMLNodeList;
begin
  inherited;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'InvoiceCurrency', lNodeList, 1) then
    InvoiceCurrency := TxsdISO4217CurrencyCode.FromString(lNodeList.GetFirst.Text);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'ConversionFromHotelCurrency', lNodeList, 1) then
    ConversionFromHotelCurrency.SetPropertiesFromXMLNode(lNodeList.GetFirst);
end;

{ TxsdGuestAddress }

procedure TxsdGuestAddress.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

class function TxsdGuestAddress.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI;
end;

class function TxsdGuestAddress.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TxsdGuestAddress.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

{ TxsdGuestData }

procedure TxsdGuestData.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  aNode.AddChild('Name').Text := FName;
  FAddress.AddPropertiesToXMLNode(aNode.AddChild(''));
end;

procedure TxsdGuestData.Clear;
begin
  inherited;
  FAddress.Clear;
end;

constructor TxsdGuestData.Create;
begin
  FAddress := TxsdGuestAddress.Create;
end;

destructor TxsdGuestData.Destroy;
begin
  inherited;
  FAddress.Free;
end;

class function TxsdGuestData.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI;
end;

class function TxsdGuestData.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TxsdGuestData.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodeList: IXMLNodeList;
begin
  inherited;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'Name', lNodeList, 1) then
    FName := lnodeList.GetFirst.Text;

  if aNode.SelectNodesNS(GetNameSpaceURI, FAddress.GetNodeName, lNodeList, 1) then
    FAddress.SetPropertiesFromXMLNode(lnodeList.GetFirst);

end;

{ TxsdCreationTypeHelper }

function TxsdCreationTypeHelper.AsString: String;
begin
  Result := GetEnumName(TypeInfo(TxsdCreationType), ord(Self));
end;

class function TxsdCreationTypeHelper.FromString(const aString: string): TxsdCreationType;
begin
  Result := TxsdCreationType(GetEnumValue(TypeInfo(TxsdCreationType), aString));
end;

{ TxsdInvoiceTypeTypeHelper }

function TxsdInvoiceTypeTypeHelper.AsString: String;
begin
  Result := GetEnumName(TypeInfo(TxsdInvoiceTypeType), ord(Self));
end;

class function TxsdInvoiceTypeTypeHelper.FromString(const aString: string): TxsdInvoiceTypeType;
begin
  Result := TxsdInvoiceTypeType( GetEnumValue(TypeInfo(TxsdInvoiceTypeType), aString));
end;

{ TxsdInvoiceStateTypeHelper }

function TxsdInvoiceStateTypeHelper.AsString: String;
begin
  Result := GetEnumName(TypeInfo(TxsdInvoiceStateType), ord(Self));
end;

class function TxsdInvoiceStateTypeHelper.FromString(const aString: string): TxsdInvoiceStateType;
begin
  Result := TxsdInvoiceStateType( GetEnumValue(TypeInfo(TxsdInvoiceStateType), aString));
end;

{ TxsdInvoiceLineType }

procedure TxsdInvoiceLineType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdInvoiceLineType.Clear;
begin
  inherited;
  Findex_ := -1;
  FCreatorId := '';
  FRemarks.Clear;
  FreeAndNil(FItem);
end;

constructor TxsdInvoiceLineType.Create;
begin
  FRemarks := TxsdRemarksType.Create;
  FItem := TxsdInvoiceLineEntryType.Create;
end;

destructor TxsdInvoiceLineType.Destroy;
begin
  inherited;
  FRemarks.Free;
  FItem.Free;
end;

class function TxsdInvoiceLineType.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI;
end;

class function TxsdInvoiceLineType.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TxsdInvoiceLineType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodes: IXMLNodeList;
begin
  inherited;
  Findex_ := StrToIntDef(aNode.Attributes['index'], -1);
  FCreatorId := aNode.Attributes['creatorId'];
  FCreationType := TxsdCreationType.FromString(aNode.Attributes['creationType']);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'Remarks', lNodes) then
    FRemarks.SetPropertiesFromXMLNode(lNodes.GetFirst);

  FItem := TxsdInvoiceLineEntryType.CreateInvoiceLineEntryType(aNode)
end;

{ TxsdAmountType }

class function TxsdAmountType.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI
end;

class function TxsdAmountType.GetNodeName: string;
begin
  Result := cNodeName;
end;

{ TxsdBillableEntryStatusHelper }

function TxsdBillableEntryStatusHelper.AsString: String;
begin
  Result := GetEnumName(TypeInfo(TxsdBillableEntryStatus), ord(Self));
end;

class function TxsdBillableEntryStatusHelper.FromString(const aString: string): TxsdBillableEntryStatus;
begin
  Result := TxsdBillableEntryStatus( GetEnumValue(TypeInfo(TxsdBillableEntryStatus), aString));
end;


{ TxsdCustomerData }

procedure TxsdCustomerData.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;

end;

class function TxsdCustomerData.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI
end;

class function TxsdCustomerData.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TxsdCustomerData.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  FCustomer := aNode.Attributes['customer'];
  FCustomerReference := aNode.Attributes['customerReference'];
end;

{ TxsdCurrencyConversionRateType }

procedure TxsdCurrencyConversionRateType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdCurrencyConversionRateType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  FFrom := TxsdISO4217CurrencyCode.FromString(aNode.Attributes['from']);
  FTo := TxsdISO4217CurrencyCode.FromString(aNode.Attributes['to']);
  FFactor := XMLToFloat(aNode.Attributes['factor'], 1.0);
  FDate := XMLToDateTime(aNode.Attributes['from']);
end;

{ TxsdInvoiceLineEntryType }

class function TxsdInvoiceLineEntryType.CreateInvoiceLineEntryType(aNode: PXMLNode): TxsdInvoiceLineEntryType;
var
  lClass: TxsdInvoiceLineEntryTypeClass;
  lNodes: IXMLNodeList;
begin
  if aNode.SelectNodesNS(TxsdExtendedBillableEntryType.GetNameSpaceURI, TxsdExtendedBillableEntryType.GetnodeName, lNodes ) then
    Result := TxsdExtendedBillableEntryType.Create
  else if aNode.SelectNodesNS(TxsdDiscountBillableEntryType.GetNameSpaceURI, TxsdDiscountBillableEntryType.GetNodeName, lNodes ) then
    Result := TxsdDiscountBillableEntryType.Create
  else if aNode.SelectNodesNS(txsdPaymentType.GetNameSpaceURI, txsdPaymentType.GetNodeName, lNodes ) then
    Result := TxsdPaymentType.Create
  else if aNode.SelectNodesNS(TxsdTextEntryType.GetNameSpaceURI, TxsdTextEntryType.GetNodeName, lNodes ) then
    Result := TxsdTextEntryType.Create
  else
    raise ERoomerSchemaException.CreateFmt('Unkown TxsdInvoiceLineEntryType: [%s]', [ aNode.NodeName]);

  Result.SetPropertiesFromXMLNode(lNodes.GetFirst);
end;

{ TxsdExtendedBillableEntryType }

procedure TxsdExtendedBillableEntryType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdExtendedBillableEntryType.Clear;
begin
  inherited;
  FPaymentUnitPrice.Clear;
  FPaymentConversionRate.Clear;
  FTotalPriceGross.Clear;
  FTotalConvertedPriceGross.Clear;
  FTotalConvertedPriceNet.Clear;
  FApplicableTax.Clear;
  FApplicationDate := 0;
  FPaymentDateTime := 0;
  FTotalPaymentPriceNet.Clear;
  FTotalPaymentPriceGross.Clear;
end;

constructor TxsdExtendedBillableEntryType.Create;
begin
  inherited;
  FPaymentUnitPrice := TxsdAmountType.Create;;
  FPaymentConversionRate := TxsdCurrencyConversionRateType.Create;;
  FTotalPriceGross := TxsdAmountType.Create;;
  FTotalConvertedPriceGross := TxsdAmountType.Create;;
  FTotalConvertedPriceNet := TxsdAmountType.Create;;
  FApplicableTax := TxsdTaxType.Create;;
  FTotalPaymentPriceNet := TxsdAmountType .Create;;
  FTotalPaymentPriceGross := TxsdAmountType .Create;;
end;

destructor TxsdExtendedBillableEntryType.Destroy;
begin
  inherited;
  FPaymentUnitPrice.Free;
  FPaymentConversionRate.Free;
  FTotalPriceGross.Free;
  FTotalConvertedPriceGross.Free;
  FTotalConvertedPriceNet.Free;
  FApplicableTax.Free;
  FTotalPaymentPriceNet.Free;
  FTotalPaymentPriceGross.Free;
end;

class function TxsdExtendedBillableEntryType.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI;
end;

class function TxsdExtendedBillableEntryType.GetNodeName: string;
begin
  result := cNodeName;
end;

procedure TxsdExtendedBillableEntryType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodeList: IXMLNodeList;
begin
  inherited;
  FStatus := TxsdBillableEntryStatus.FromString(aNode.Attributes['status']);
  FApplicationDate := XMLToDateTime(aNode.Attributes['applicationDate']);
  FPaymentDateTime := XMLToDateTime(aNode.Attributes['paymentDateTime']);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'PaymentUnitPrice', lNodeList, 1) then
    FPaymentUnitPrice.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'PaymentConversionRate', lNodeList, 1) then
    FPaymentConversionRate.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'TotalPriceGross', lNodeList, 1) then
    FTotalPriceGross.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'TotalConvertedPriceGross', lNodeList, 1) then
    FTotalConvertedPriceGross.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'TotalConvertedPriceNet', lNodeList, 1) then
    FTotalConvertedPriceNet.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'TotalPaymentPriceNet', lNodeList, 1) then
    FTotalPaymentPriceNet.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'TotalPaymentPriceGross', lNodeList, 1) then
    FTotalPaymentPriceGross.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'ApplicableTax', lNodeList, 1) then
    FApplicableTax.SetPropertiesFromXMLNode(lNodeList.GetFirst);

end;

{ TxsdBillableEntryType }

procedure TxsdBillableEntryType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdBillableEntryType.Clear;
begin
  inherited;
  FID := '';
  FDescription := '';
  FProductID := '';
  FNumber := 1.0;
  FPurchaseDateTime := 0;
  FUnitPrice.Clear;
  FConvertedUnitPrice.Clear;
  FTotalPrice.Clear;
  FConversionRate.Clear;
end;

constructor TxsdBillableEntryType.Create;
begin
  FUnitPrice := TxsdAmountType.Create;
  FConvertedUnitPrice := TxsdAmountType.Create;
  FTotalPrice := TxsdAmountType.Create;
  FConversionRate := TxsdCurrencyConversionRateType.Create;
end;

destructor TxsdBillableEntryType.Destroy;
begin
  inherited;
  FUnitPrice.Free;
  FConvertedUnitPrice.Free;
  FTotalPrice.Free;
  FConversionRate.Free;
end;

procedure TxsdBillableEntryType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodeList: IXMLNodeList;
begin
  inherited;
  FId := aNode.Attributes['id'];
  FDescription := aNode.Attributes['description'];
  FProductID := aNode.Attributes['productId'];
  FNumber := XMLToFloat(aNode.Attributes['number']);
  FPurchaseDateTime := XMLToDateTime(aNode.Attributes['purchaseDateTime']);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'unitPrice', lNodeList, 1) then
    FUnitPrice.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'convertedUnitPrice', lNodeList, 1) then
    FConvertedUnitPrice.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'totalPrice', lNodeList, 1) then
    FTotalPrice.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  if aNode.SelectNodesNS(GetNameSpaceURI, 'conversionRate', lNodeList, 1) then
    FConversionRate.SetPropertiesFromXMLNode(lNodeList.GetFirst);
end;

{ TxsdDiscountBillableEntryType }

procedure TxsdDiscountBillableEntryType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdDiscountBillableEntryType.Clear;
begin
  inherited;
  FAppliesTo := '';
end;

procedure TxsdDiscountBillableEntryType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  FAppliesTo := aNode.Attributes['appliesTo'];
end;

{ TxsdTextEntryType }

procedure TxsdTextEntryType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdTextEntryType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  FID := aNode.Attributes['id'];
  FText := aNode.Attributes['text'];
  FDate := XMLToDate(aNode.Attributes['date']);
end;

{ TxsdPaymentType }

procedure TxsdPaymentType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdPaymentType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  FID := aNode.Attributes['íd'];
  FPaymentReference := aNode.Attributes['paymentReference'];
  FPaymentMethod := aNode.Attributes['paymentMethod'];
  FDate := XMLToDateTime(aNode.Attributes['date']);

  FAmount.SetPropertiesFromXMLNode(aNode);
end;

end.
