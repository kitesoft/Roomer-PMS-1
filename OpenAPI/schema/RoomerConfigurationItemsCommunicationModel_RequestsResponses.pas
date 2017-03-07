unit RoomerConfigurationItemsCommunicationModel_RequestsResponses;

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

{$REGION 'ChannelInventoryType XSD definition'}
//  <complexType name="TChannelInventoryItemType">
//  		<annotation>
//  			<documentation>This complex type gives the general structure of a channel inventory item (i.e. a channel supported by
//  				Roomer).</documentation>
//  		</annotation>
//  		<attribute name="channelCode" type="rmrst:ChannelCodeType" use="required" />
//  		<attribute name="channelLongCode" type="string" use="optional" />
//  		<attribute name="channelName" type="string" use="required" />
//  		<attribute name="canBeDirectConnectChannel" type="boolean" use="required"/>
//  	</complexType>
{$ENDREGION}

  {$M+}
  TChannelInventoryItemType = class(TxsdBaseObject)
  const
    cNameSpaceURI = 'http://roomer.promoir.nl/datamodel/canonical/basetypes/2014/01/';
    cNodeName = 'TChannelInventoryItemType';
  private
    FChannelLongCode: string;
    FChannelCode: string;
    FChannelName: String;
    FCanBeDirectConnectChannel: boolean;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  public
    procedure Clear; override;

  published
    property ChannelCode: string read FChannelCode write FChannelCode;
    property ChannelLongCode: string read FChannelLongCode write FChannelLongCode;
    property ChannelName: String read FChannelName write FChannelName;
    property CanBeDirectConnectChannel: boolean read FCanBeDirectConnectChannel write FCanBeDirectConnectChannel;
  end;

  TChannelInventoryItemTypeList = class(TxsdBaseObjectList<TChannelInventoryItemType>)
  protected
    class function GetNodeName: string; virtual; abstract;
    class function GetNameSpaceURI: string; virtual; abstract;
  end;


{$REGION 'ChannelInventoryOverview XSD definition'}
//	<element name="ChannelInventoryOverview">
//		<complexType>
//			<sequence>
//				<element name="ChannelInventory" type="rmrbt:TChannelInventoryItemType" minOccurs="0" maxOccurs="unbounded"/>
//			</sequence>
//		</complexType>
//	</element>
{$ENDREGION}

  {$M+}
  TUserActivityCategoriesOverview = class(TxsdBaseObject)
  const
    cNameSpaceURI = 'http://www.promoir.nl/roomer/configuration/2015/12';
    cNodeName = 'ChannelInventoryOverview';
  private
    FChannelInventoriesList: IList<TChannelInventoryItemType>;
    function GetChannelInventoriesList: TChannelInventoryItemTypeList;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Clear; override;

  published
    property ChannelInventoriesList: TChannelInventoryItemTypeList read GetChannelInventoriesList;
  end;

implementation

uses
  XMLUtils
  ;

{ TUserActivityCategoriesOverview }

procedure TUserActivityCategoriesOverview.Clear;
begin
  inherited;
  ChannelInventoriesList.Clear;
end;

constructor TUserActivityCategoriesOverview.Create;
begin
  FChannelInventoriesList :=  TChannelInventoryItemTypeList.Create;
end;

destructor TUserActivityCategoriesOverview.Destroy;
begin

  inherited;
end;

function TUserActivityCategoriesOverview.GetChannelInventoriesList: TChannelInventoryItemTypeList;
begin
  Result := FChannelInventoriesList as TChannelInventoryItemTypeList;
end;

class function TUserActivityCategoriesOverview.GetNameSpaceURI: string;
begin
  Result := cNameSpaceURI;
end;

class function TUserActivityCategoriesOverview.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TUserActivityCategoriesOverview.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  ChannelInventoriesList.SetPropertiesFromXMLNode(aNode);
end;

{ TChannelInventoryItemType }

procedure TChannelInventoryItemType.Clear;
begin
  inherited;
  FChannelLongCode := '';
  FChannelCode := '';
  FChannelName := '';
  FCanBeDirectConnectChannel := false;
end;

class function TChannelInventoryItemType.GetNameSpaceURI: string;
begin
  Result := cNameSpaceURI;
end;

class function TChannelInventoryItemType.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TChannelInventoryItemType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;
  FChannelLongCode := aNode.Attributes['channelLongCode'];
  FChannelCode := aNode.Attributes['channelCode'];
  FChannelName := aNode.Attributes['channelName'];
  FCanBeDirectConnectChannel := XMLToBool(aNode.Attributes['canBeDirectConnectChannel']);
end;

end.
