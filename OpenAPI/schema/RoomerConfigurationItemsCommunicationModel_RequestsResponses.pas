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

{$REGION 'ChannelInventoryItemType XSD definition'}
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
  TChannelInventoryItemType = class abstract(TxsdBaseObject)
  private const
    cNameSpaceURI = 'http://roomer.promoir.nl/datamodel/canonical/basetypes/2014/01/';
    cNodeName = 'ChannelInventoryitemType';
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

  TChannelInventory = class(TChannelInventoryItemType)
  private const
    cNameSpaceURI = 'http://www.promoir.nl/roomer/configuration/2015/12';
    cNodeName = 'ChannelInventory';
  protected
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  end;

  TChannelInventoryList = class(TxsdBaseObjectList<TChannelInventory>)
  protected
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
  TChannelInventoryOverview = class(TxsdBaseObject)
  const
    cNameSpaceURI = 'http://www.promoir.nl/roomer/configuration/2015/12';
    cNodeName = 'ChannelInventoryOverview';
  private
    FChannelInventoriesList: IList<TChannelInventory>;
    function GetChannelInventoriesList: TChannelInventoryList;
    function GetChannelByCode(const aCode: string): TChannelInventory;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    class function GetNodeName: string; override;
    class function GetNameSpaceURI: string; override;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Clear; override;
    function FindChannelByCode(const aCode: string; var aChannel: TChannelInventory): boolean;
    property ChannelByCode[const aCode: string]: TChannelInventory read GetChannelByCode;
  published
    property ChannelInventoriesList: TChannelInventoryList read GetChannelInventoriesList;
  end;

implementation

uses
  XMLUtils
  ;

{ TChannelInventoryOverview }

procedure TChannelInventoryOverview.Clear;
begin
  inherited;
  ChannelInventoriesList.Clear;
end;

constructor TChannelInventoryOverview.Create;
begin
  FChannelInventoriesList :=  TChannelInventoryList.Create;
end;

destructor TChannelInventoryOverview.Destroy;
begin

  inherited;
end;

function TChannelInventoryOverview.FindChannelByCode(const aCode: string; var aChannel: TChannelInventory): boolean;
var
  lChannel: TChannelInventory;
begin
  Result := False;
  for lChannel in ChannelInventoriesList do
    if lChannel.FChannelCode.Equals(aCode) then
    begin
      result := true;
      aChannel := lChannel;
    end;
end;

function TChannelInventoryOverview.GetChannelByCode(const aCode: string): TChannelInventory;
begin
  if not FindChannelByCode(aCode, Result) then
    raise Exception.Create('Channel not found in inventory.');
end;

function TChannelInventoryOverview.GetChannelInventoriesList: TChannelInventoryList;
begin
  Result := FChannelInventoriesList as TChannelInventoryList;
end;

class function TChannelInventoryOverview.GetNameSpaceURI: string;
begin
  Result := cNameSpaceURI;
end;

class function TChannelInventoryOverview.GetNodeName: string;
begin
  Result := cNodeName;
end;

procedure TChannelInventoryOverview.SetPropertiesFromXMLNode(const aNode: PXMLNode);
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

{ TChannelInventory }

class function TChannelInventory.GetNameSpaceURI: string;
begin
  Result := cNameSpaceURI;
end;

class function TChannelInventory.GetNodeName: string;
begin
  Result := cNodeName;
end;

end.
