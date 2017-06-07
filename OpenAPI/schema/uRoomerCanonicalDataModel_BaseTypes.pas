unit uRoomerCanonicalDataModel_BaseTypes;

interface

uses
   Classes
   , SysUtils
   , Spring.Collections.Lists
   , Spring.Collections
   , uRoomerSchema
   , XMLIntf
   , OXmlPDOM
   , uRoomerCanonicalDataModel_SimpleTypes
   ;

const
  cRmrbtNameSpaceURI = 'http://roomer.promoir.nl/datamodel/canonical/basetypes/2014/01/';

type

{$SCOPEDENUMS ON}

{$REGION 'RemarksType xsd definition'}
  //	<complexType name="RemarksType">
  //		<annotation>
  //			<documentation>This complextype describes the list of remarks that is included in different domain types within
  //				Roomer.
  //			</documentation>
  //		</annotation>
  //		<sequence>
  //			<element name="remark" type="string" minOccurs="1" maxOccurs="unbounded" />
  //		</sequence>
  //	</complexType>
{$ENDREGION}
  TxsdRemarksType = class abstract(TxsdBaseObject)
  private const
    cChildNodeName = 'remark';
  private
    FRemarksList: TList<string>;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Clear; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;

  published
    property RemarksList: TList<string> read FRemarksList write FRemarksList;
  end;

{$REGION 'SimplifiedAddressType xsd definition'}
  //<complexType name="SimplifiedAddressType">
  //		<sequence>
  //			<element name="Address" type="string" />
  //			<element name="PostalCode" type="string" />
  //			<element name="Locality" type="string" />
  //			<element name="Region" type="string" minOccurs="0" />
  //			<element name="Country" type="rmrst:ISO31661alpha2CountryCode" minOccurs="0" />
  //		</sequence>
  //	</complexType>
{$ENDREGION}

  TxsdSimplifiedAddressType = class(TxsdBaseObject)
  private const
    cNodeName = 'Address';
  private
    FPostcalCode: string;
    FLocality: string;
    FCountry: TxsdISO31661alpha2CountryCode;
    FAddress: string;
    FRegion: string;
  public
    class function GetNameSpaceURI: string; override;
    class function GetNodeName: string; override;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property Address: string read FAddress write FAddress;
    property PostcalCode: string read FPostcalCode write FPostcalCode;
    property Locality: string read FLocality write FLocality;
    property Region: string read FRegion write FRegion;
    property Country: TxsdISO31661alpha2CountryCode read FCountry write FCountry;
  end;

{$REGION 'AmountGroup xsd Definition'}
  //	<attributeGroup name="AmountGroup">
  //		<annotation>
  //			<documentation>A grouping of the attributes that together express an amount of money.</documentation>
  //		</annotation>
  //		<attribute name="currency" type="rmrst:ISO4217CurrencyCode" use="required" />
  //		<attribute name="amount" type="decimal" use="required" />
  //	</attributeGroup>
{$ENDREGION}
  TxsdAmountGroup = class(TxsdBaseObject)
  private
    FCurrency: TxsdISO4217CurrencyCode;
    FAmount: double;
  public
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); override;
  published
    property Currency: TxsdISO4217CurrencyCode read FCurrency write FCurrency;
    property Amount: double read FAmount write FAmount;
  end;

implementation

{ TxsdSimplifiedAddressType }

uses uExceptionUtils, XmlUtils;

procedure TxsdSimplifiedAddressType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  aNode.AddChild('Address').Text := FAddress;
  aNode.AddChild('PostalCode').Text := FPostcalCode;
  aNode.AddChild('Locality').Text := FLocality;
  aNode.AddChild('Region').Text := FRegion;
  aNode.AddChild('Country').Text := FCountry.asString;
end;

class function TxsdSimplifiedAddressType.GetNameSpaceURI: string;
begin
  Result := cRmrbtNameSpaceURI;
end;

class function TxsdSimplifiedAddressType.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TxsdSimplifiedAddressType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lNodeList: IXMLNodeList;
begin
  inherited;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'Address', lNodeList, 1) then
    FAddress := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'PostalCode', lNodeList, 1) then
    FPostcalCode := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'Locality', lNodeList, 1) then
    FLocality := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'Region', lNodeList, 1) then
    FRegion := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(GetNameSpaceURI, 'Country', lNodeList, 1) then
    FCountry := TxsdISO31661alpha2CountryCode.FromString(lNodeList.GetFirst.Text);
end;

{ TxsdRemarksType }

procedure TxsdRemarksType.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdRemarksType.Clear;
begin
  FRemarksList.Clear;
end;

constructor TxsdRemarksType.Create;
begin
  FRemarksList := TList<string>.Create;
end;

destructor TxsdRemarksType.Destroy;
begin
  inherited;
  FRemarksList.Free;
end;

procedure TxsdRemarksType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lCHildNode: PXMLNode;
begin
  inherited;
  for lChildNode in aNode.ChildNodes do
    if lChildNode.NodeName.Equals(cChildNodeName) then
      FRemarksList.Add(lChildNode.Text);
end;

{ TxsdAmountGroup }

procedure TxsdAmountGroup.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  inherited;
  RaiseMethodNotImplementedException;
end;

procedure TxsdAmountGroup.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  FCurrency := TxsdISO4217CurrencyCode.FromString(aNOde.Attributes['currency']);
  FAmount := XMLToFloat(aNode.Attributes['amount']);
end;

end.
