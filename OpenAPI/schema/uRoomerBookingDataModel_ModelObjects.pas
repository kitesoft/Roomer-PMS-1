unit uRoomerBookingDataModel_ModelObjects;

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
   , uRoomerCanonicalDataModel_DataStructures
   ;
type

  TxsdRoomRentTaxReceiptTypeList = class(TxsdBaseObjectList<TxsdRoomRentTaxReceiptType>)
  private const
    cChildNameSpaceURI = 'http://roomer.promoir.nl/datamodel/booking/modelobjects/2014/01/';
    cChildNodeName = 'Receipt';
  public
    class function GetChildNodeName: string; override;
    class function GetChildNameSpaceURI: string; override;
  end;

{$REGION 'RoomRentTaxReceiptList XSD definition'}
  //	<element name="RoomRentTaxReceiptList">
  //		<complexType>
  //			<sequence>
  //            <element name="TotalCityTax">
  //                <complexType>
  //                    <attributeGroup ref="rmrbt:AmountGroup" />
  //                </complexType>
  //            </element>
  //            <element name="TotalCityTaxVat">
  //                <complexType>
  //                    <attributeGroup ref="rmrbt:AmountGroup" />
  //                </complexType>
  //            </element>
  //				<element name="Receipt" type="rmrds:RoomRentTaxReceiptType"
  //					minOccurs="0" maxOccurs="unbounded">
  //				</element>
  //			</sequence>
  //		</complexType>
  //	</element>
{$ENDREGION}
  TxsdRoomRentTaxReceiptList = class(TxsdBaseObject)
  private const
    cNodeName = 'RoomRentTaxReceiptList';
    cNameSpaceURI = 'http://roomer.promoir.nl/datamodel/booking/modelobjects/2014/01/';
    cChildNodeName = 'Receipt';
  private
    FTotalCityTax: TxsdAmountGroup;
    FTotalCityTaxvat: TxsdAmountGroup;
    FReceipts: IList<TxsdRoomRentTaxReceiptType>;
    function GetReceipts: TxsdRoomRentTaxReceiptTypeList;
  public
    constructor Create;
    destructor Destroy; override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property TotalCityTax: TxsdAmountGroup read FTotalCityTax write FTotalCityTax;
    property TotalCityTaxvat: TxsdAmountGroup read FTotalCityTaxvat write FTotalCityTaxvat;
    property Receipts: IList<TxsdRoomRentTaxReceiptType> read FReceipts;
  end;


implementation

{ TxsdRoomRentTaxReceiptList }

procedure TxsdRoomRentTaxReceiptList.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
end;

constructor TxsdRoomRentTaxReceiptList.Create;
begin
  FTotalCityTax := TxsdAmountGroup.Create;
  FTotalCityTaxvat := TxsdAmountGroup.Create;
  FReceipts := TxsdRoomRentTaxReceiptTypeList.Create;
end;

destructor TxsdRoomRentTaxReceiptList.Destroy;
begin
  FTotalCityTax.Free;
  FTotalCityTaxvat.Free;
  inherited;
end;

class function TxsdRoomRentTaxReceiptList.GetNameSpaceURI: string;
begin
  Result := cNameSpaceURI;
end;

class function TxsdRoomRentTaxReceiptList.GetNodeName: string;
begin
  Result := cNodeName;
end;

function TxsdRoomRentTaxReceiptList.GetReceipts: TxsdRoomRentTaxReceiptTypeList;
begin
  Result := FReceipts as TxsdRoomRentTaxReceiptTypeList;
end;

procedure TxsdRoomRentTaxReceiptList.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodeList: IXMLNodeList;
begin
  inherited;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'TotalCityTax', lNodeList, 1) then
    FTotalCityTax.SetPropertiesFromXMLNode(lNodeList.GetFirst);
  if aNode.SelectNodesNS(GetNameSpaceURI, 'TotalCityTaxVat', lNodeList, 1) then
    FTotalCityTaxvat.SetPropertiesFromXMLNode(lNodeList.GetFirst);

  GetReceipts.SetPropertiesFromXMLNode(aNode);

end;

{ TxsdRoomRentTaxReceiptTypeList }

class function TxsdRoomRentTaxReceiptTypeList.GetChildNameSpaceURI: string;
begin
  Result := cChildNameSpaceURI;
end;

class function TxsdRoomRentTaxReceiptTypeList.GetChildNodeName: string;
begin
  Result := cChildNodeName;
end;

end.
