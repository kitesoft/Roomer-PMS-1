unit uRoomerCanonicalDataModel_DataStructures;

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
   ;

type
{$REGION 'RoomRentTaxReceiptType XSD definition'}
  //	<complexType name="RoomRentTaxReceiptType">
  //		<annotation>
  //			<documentation>
  //				This type contains a receipt for tax calculations.
  //			</documentation>
  //		</annotation>
  //		<sequence>
  //			<element name="basePrice">
  //				<complexType>
  //					<attributeGroup ref="rmrbt:AmountGroup" />
  //				</complexType>
  //			</element>
  //			<element name="roomRentVat">
  //				<complexType>
  //					<attributeGroup ref="rmrbt:AmountGroup" />
  //				</complexType>
  //			</element>
  //			<element name="cityTax">
  //				<complexType>
  //					<attributeGroup ref="rmrbt:AmountGroup" />
  //				</complexType>
  //			</element>
  //			<element name="cityTaxVat" minOccurs="0">
  //				<complexType>
  //					<attributeGroup ref="rmrbt:AmountGroup" />
  //				</complexType>
  //			</element>
  //		</sequence>
  //		<attribute name="cityTaxIncludedInRoomPrice" type="boolean"
  //			use="required" />
  //		<attribute name="item" type="string" use="required" />
  //		<attribute name="description" type="string" />
  //		<attribute name="roomReservationId" type="integer" />
  //		<attribute name="stayDate" type="date" />
  //	</complexType>
{$ENDREGION}
  TxsdRoomRentTaxReceiptType = class(TxsdBaseObject)
  private const
    cNodeName = 'RoomRentTaxReceiptType';
    cNameSpaceURI = 'http://roomer.promoir.nl/datamodel/canonical/datastructures/2014/01/';
  private
    FBaseprice: TxsdAmountGroup;
    FRoomRentVat: TxsdAmountGroup;
    FCityTax: TxsdAmountGroup;
    FCityTaxVat: TxsdAmountGroup;
    FItem: string;
    FDescription: string;
    FRoomReservationId: integer;
    FStayDate: TDate;
    FCityTaxIncludedInRoomPrice: boolean;
    FQuantity: integer;
  public
    constructor Create;
    destructor Destroy; override;
    class function GetNameSpaceURI: string; override;
    class function GetNodeName: string; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property Item: string read FItem write FItem;
    property Description: string read FDescription write FDescription;
    property RoomReservationId: integer read FRoomReservationId write FRoomReservationId;
    property StayDate: TDate read FStayDate write FStayDate;
    property CityTaxIncludedInRoomPrice: boolean read FCityTaxIncludedInRoomPrice write FCityTaxIncludedInRoomPrice;
    property Baseprice: TxsdAmountGroup read FBaseprice write FBaseprice;
    property RoomRentVat: TxsdAmountGroup read FRoomRentVat write FRoomRentVat;
    property CityTax: TxsdAmountGroup read FCityTax write FCityTax;
    property CityTaxVat: TxsdAmountGroup read FCityTaxVat write FCityTaxVat;
    property Quantity: integer read FQuantity write FQuantity;
  end;

implementation

{ TxsdRoomRentTaxReceiptType }

uses
  XmlUtils
  , XSBuiltins
  ;

procedure TxsdRoomRentTaxReceiptType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;

end;

constructor TxsdRoomRentTaxReceiptType.Create;
begin
  FBaseprice := TxsdAmountGroup.Create;
  FRoomRentVat := TxsdAmountGroup.Create;
  FCityTax := TxsdAmountGroup.Create;
  FCityTaxVat := TxsdAmountGroup.Create;
end;

destructor TxsdRoomRentTaxReceiptType.Destroy;
begin
  FBaseprice.Free;
  FRoomRentVat.Free;
  FCityTax.Free;
  FCityTaxVat.Free;

  inherited;
end;

class function TxsdRoomRentTaxReceiptType.GetNameSpaceURI: string;
begin
  Result := cNameSpaceURI;
end;

class function TxsdRoomRentTaxReceiptType.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TxsdRoomRentTaxReceiptType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodeList: IXMLNodelist;
begin
  inherited;
  FDescription := aNode.Attributes['description'];
  FItem := aNode.Attributes['item'];
  FRoomReservationId := StrToIntDef(aNode.Attributes['roomReservationId'], 0);
  FCityTaxIncludedInRoomPrice := XMLToBool(aNode.Attributes['cityTaxIncludedInRoomPrice']);
  FQuantity := StrToIntDef(aNode.Attributes['quantity'], 1);

  with TXSDate.Create do
  try
    XSToNative(aNode.Attributes['stayDate']);
    FStayDate := AsDate;
  finally
    Free;
  end;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'basePrice', lNodeList, 1) then
    FBasePrice.SetPropertiesFromXMLNode(lNodeList.GetFirst);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'roomRentVat', lNodeList, 1) then
    FRoomRentVat.SetPropertiesFromXMLNode(lNodeList.GetFirst);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'cityTax', lNodeList, 1) then
    FCityTax.SetPropertiesFromXMLNode(lNodeList.GetFirst);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'cityTaxVat', lNodeList, 1) then
    FCityTaxVat.SetPropertiesFromXMLNode(lNodeList.GetFirst);

end;

end.
