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
    cNodeName = 'InvoiceLineType';
  protected
    Findex_: integer;
    FCreatorId: string;
    FCreationType: TxsdCreationType;
    FRemarks: TList<string>;

    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;

  published
    property index_: integer read Findex_ write Findex_;
    property CreatorId: string read FCreatorId write FCreatorId;
    property CreationType: TxsdCreationType read FCreationType write FCreationType;
    property Remarks: TList<string> read FRemarks write FRemarks;

  end;

  TxsdInvoiceLineTypeList = class(TxsdBaseObjectList<TxsdInvoiceLineType>)
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

  TxsdGuestAddress = class(TxsdSimplifiedAddressType)
  private const
    cNodeName = 'GuestData';
  protected
    class function GetNameSpaceURI: string; override;
  end;

  TxsdGuestData = class(TxsdBaseObject)
  private const
    cNodeName = 'Address';
  private
    FName: string;
    FAddress: TxsdGuestAddress;
  protected
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property Name: string read FName write FName;
    property Address: TxsdGuestAddress read FAddress write FAddress;
  end;

  TxsdCurrencyConversionRateType = class(TxsdBaseObject)
  private
    FFrom: TxsdISO4217CurrencyCode;
    FDate: TDateTime;
    FFactor: double;
    FTo: TxsdISO4217CurrencyCode;
  published
    property From: TxsdISO4217CurrencyCode read FFrom write FFrom;
    property To_: TxsdISO4217CurrencyCode read FTo write FTo;
    property Factor: double read FFactor write FFactor;
    property Date: TDateTime read FDate write FDate;
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
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property InvoiceCurrency: TxsdISO4217CurrencyCode read FInvoiceCurrency write FInvoiceCurrency;
    property ConversionFromHotelCurrency: TxsdCurrencyConversionRateType read FConversionFromHotelCurrency write FConversionFromHotelCurrency;
  end;

{$REGION 'BillableEntryTpe xsd definition'}
  //	<complexType name="BillableEntryType">
  //		<sequence>
  //			<element name="unitPrice" type="rmrfmo:AmountType" minOccurs="0"/>
  //			<element name="convertedUnitPrice" type="rmrfmo:AmountType" minOccurs="0" />
  //			<element name="conversionRate" type="rmrfmo:CurrencyConversionRateType" minOccurs="0" />
  //			<element name="totalPrice" type="rmrfmo:AmountType" />
  //		</sequence>
  //		<attribute name="id" type="ID"/>
  //		<attribute name="description" type="string" use="optional" />
  //		<attribute name="productId" type="string" use="optional" />
  //		<attribute name="number" type="double" use="required" />
  //		<attribute name="purchaseDateTime" type="dateTime" use="required" />
  //	</complexType>
{$ENDREGION}

  TxsdBillableEntryType = class(TxsdBaseObject)
  published
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

  TxsdExtendedInvoiceType = class abstract(TxsdBaseObject)
  private const
    cNodeName = 'ExtendedInvoiceType';

  private
    FInvoiceLineTypeList: IList<TInvoiceLineType>;
    FCustomer: string;
    FCustomerRef: string;
    FGuestData: TxsdGuestData;
    FCurrencyData: TxsdCurrencyData;
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
    property Customer: string read FCustomer write FCustomer;
    property CustomerRef: string read FCustomerRef write FCustomerRef;
    property GuestData: TxsdGuestData read FGuestData write FGuestData;
    property CurrencyData: TxsdCurrencyData read FCurrencyData write FCurrencyData;
  end;

  TxsdInvoice = class(TxsdExtendedInvoiceType)
  private const
    cNodeName = 'Invoice';

  end;

implementation

uses
  TypInfo
  ;

{ TxsdExtendedInvoiceType }

function TxsdExtendedInvoiceType.GetInvoiceLineTypeList: TxsdInvoiceLineTypeList;
begin

end;

{ TxsdCurrencyData }

procedure TxsdCurrencyData.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  aNode.AddChild('InvoiceCurrency').Text := InvoiceCurrency.AsString;
  ConversionFromHotelCurrency.AddPropertiesToXMLNode(aNode.AddChild('ConversionFromHotelCurrency'));
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

class function TxsdGuestAddress.GetNameSpaceURI: string;
begin
  Result := cRmrfmoNameSpaceURI;
end;

function TxsdGuestAddress.GetNodeName: string;
begin
  Result := cNodeName;
end;

{ TxsdGuestData }

procedure TxsdGuestData.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  aNode.AddChild('Name').Text := FName;
  FAddress.AddPropertiesToXMLNode(aNode.AddChild(''));
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
  Result := GetEnumAsString(TypeInfo(TxsdCreationType), ord(Self));
end;

class function TxsdCreationTypeHelper.FromString(const aString: string): TxsdCreationType;
begin
  Result := TxsdCreationType(GetEnumValue(TypeInfo(TxsdCreationType), aString));
end;

{ TxsdInvoiceTypeTypeHelper }

function TxsdInvoiceTypeTypeHelper.AsString: String;
begin
  Result := GetEnumAsString(TypeInfo(TxsdInvoiceTypeType), ord(Self));
end;

class function TxsdInvoiceTypeTypeHelper.FromString(const aString: string): TxsdInvoiceTypeType;
begin
  Result := TxsdInvoiceTypeType( GetEnumValue(TypeInfo(TxsdInvoiceTypeType), aString));
end;

{ TxsdInvoiceStateTypeHelper }

function TxsdInvoiceStateTypeHelper.AsString: String;
begin
  Result := GetEnumAsString(TypeInfo(TxsdInvoiceStateType), ord(Self));
end;

class function TxsdInvoiceStateTypeHelper.FromString(const aString: string): TxsdInvoiceStateType;
begin
  Result := TxsdInvoiceStateType( GetEnumValue(TypeInfo(TxsdInvoiceStateType), aString));
end;

end.
