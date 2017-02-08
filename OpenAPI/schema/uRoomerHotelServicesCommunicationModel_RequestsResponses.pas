unit uRoomerHotelServicesCommunicationModel_RequestsResponses;

interface

uses
   Classes
   , SysUtils
   , Generics.Collections
   , XMLIntf
   , OXmlPDOM
   ;

type
  EXMLDocException = class(Exception);

  TxsdBaseObject = class(TObject)
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); virtual; abstract;
  public
    function LoadFromXML(const aXML: string): boolean;
    procedure Clear; virtual; abstract;
  end;

{$REGION 'UserActivityCategoriesOverview XSD definition'}
  //	<xsd:element name="UserActivityCategoriesOverview">
  //		<xsd:complexType>
  //			<xsd:sequence>
  //				<xsd:element name="Category" minOccurs="1" maxOccurs="unbounded">
  //					<xsd:complexType>
  //						<xsd:sequence>
  //							<xsd:element name="Action" minOccurs="1" maxOccurs="unbounded" type="xsd:string"/>
  //						</xsd:sequence>
  //						<xsd:attribute name="name" type="xsd:string" use="required"/>
  //					</xsd:complexType>
  //				</xsd:element>
  //			</xsd:sequence>
  //		</xsd:complexType>
  //	</xsd:element>
{$ENDREGION}

  TUserActivityCategoriesOverview = class(TxsdBaseObject)
  type

    TCategory = class
    private
        FName: string;
        FActions: TStringlist;
    public
      constructor Create;
      destructor Destroy; override;

      property Name: string read FName write FName;
      property Actions: TStringlist read FActions;
    end;

  private
    FCategories: TObjectList<TCategory>;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Clear; override;

    procedure AddCategoryNamesAsString(aString: TStrings);
    property Categories: TObjectList<TCategory> read FCategories;
  end;

{$REGION 'UserActivityLogEventType XSD definition'}
  //	<xsd:complexType name="UserActivityLogEventType">
  //		<xsd:sequence>
  //			<xsd:element name="description" minOccurs="0" type="xsd:string"/>
  //			<xsd:element name="detailedDescription" minOccurs="0" type="xsd:string"/>
  //			<xsd:element name="machineName" minOccurs="0" type="xsd:string"/>
  //			<xsd:element name="oldValue" minOccurs="0" type="xsd:string"/>
  //			<xsd:element name="newValue" minOccurs="0" type="xsd:string"/>
  //			<xsd:element name="code" minOccurs="0" type="xsd:string"/>
  //		</xsd:sequence>
  //		<xsd:attribute name="userId" type="xsd:string" use="required"/>
  //		<xsd:attribute name="category" type="xsd:string" use="optional"/>
  //		<xsd:attribute name="action" type="xsd:string" use="optional"/>
  //		<xsd:attribute name="actionDateTime" type="xsd:dateTime" use="optional"/>
  //		<xsd:attribute name="actionAffectsDate" type="xsd:date" use="optional"/>
  //		<xsd:attribute name="userLocation" type="xsd:string" use="optional"/>
  //		<xsd:attribute name="reservation" type="xsd:string" use="optional"/>
  //		<xsd:attribute name="roomReservation" type="xsd:string" use="optional"/>
  //		<xsd:attribute name="id1" type="xsd:string" use="optional"/>
  //		<xsd:attribute name="id2" type="xsd:string" use="optional"/>
  //		<xsd:attribute name="id3" type="xsd:string" use="optional"/>
  //	</xsd:complexType>
{$ENDREGION}

  TUserActivityLogEventType = class(TxsdBaseObject)
  private
    FDescription: string;
    FDetailedDescription: string;
    FMachineName: string;
    FOldValue: string;
    FNewValue: string;
    FCode: string;
    FUserId: string;
    FCategory: string;
    FAction: string;
    FActionDateTime: TDateTime;
    FActionAffectsDate: TDate;
    FUserLocation: string;
    FReservation: integer;
    FRoomreservation: integer;
    Fid1: string;
    Fid2: string;
    Fid3: string;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    property Description: string read FDescription write FDescription;
    property DetailedDescription: string read FDetailedDescription write FDetailedDescription;
    property MachineName: string read FMachineName write FMachineName;
    property OldValue: string read FOldValue write FOldValue;
    property NewValue: string read FNewValue write FNewValue;
    property Code: string read FCode write FCode;
    property UserId: string read FUserId write FUserId;
    property Category: string read FCategory write FCategory;
    property Action: string read FAction write FAction;
    property ActionDateTime: TDateTime read FActionDateTime write FActionDateTime;
    property ActionAffectsDate: TDate read FActionAffectsDate write FActionAffectsDate;
    property UserLocation: string read FUserLocation write FUserLocation;
    property Reservation: integer read FReservation write FReservation;
    property Roomreservation: integer read FRoomreservation write FRoomreservation;
    property id1: string read Fid1 write Fid1;
    property id2: string read Fid2 write Fid2;
    property id3: string read Fid3 write Fid3;

  end;

  TUserActivityLogEventTypeList = TObjectList<TUserActivityLogEventType>;

{$REGION 'UserActivityLogFragment XSD definition'}
  //  <xsd:element name="UserActivityLogFragment">
  //		<xsd:complexType>
  //			<xsd:sequence>
  //				<xsd:element name="UserActivityLogEvent" minOccurs="0" maxOccurs="unbounded" type="UserActivityLogEventType"/>
  //			</xsd:sequence>
  //		</xsd:complexType>
  //	</xsd:element>
{$ENDREGION}

  TUserActivityLogFragment = class(TxsdBaseObject)
  private
    FLogEventList: TUserActivityLogEventTypeList;
  public
    constructor Create;
    destructor Destroy; override;

    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure Clear; override;
    property LogEventList: TUserActivityLogEventTypeList read FLogEventList write FLogEventList;
  end;

implementation

uses
  XMLUtils
  ;

{ TUserActivityCategoriesOverview }

procedure TUserActivityCategoriesOverview.AddCategoryNamesAsString(aString: TStrings);
var
  lCat: TCategory;
begin
  for lCat in FCategories do
  begin
    aString.Add(lCat.Name);
  end;
end;

procedure TUserActivityCategoriesOverview.Clear;
begin
  inherited;
  FCategories.Clear;
end;

constructor TUserActivityCategoriesOverview.Create;
begin
  FCategories := TObjectList<TCategory>.Create;
end;

destructor TUserActivityCategoriesOverview.Destroy;
begin
  FCategories.Free;
  inherited;
end;

procedure TUserActivityCategoriesOverview.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  node: PXMLNode;
  actionNode: PXMLNode;
  nodes_cat: IXMLNodeList;
  nodes_act: IXMLNodeList;
  lCat: TCategory;
  i, j: integer;
const
  cCategories= 'Category';
  cActions= 'Action';
  cNameSpace = 'http://www.promoir.nl/roomer/services/hotel/2017/01';
begin
  inherited;
  if aNode.SelectNodesNS(cNameSpace, cCategories, nodes_cat) then
  for node in nodes_cat do
  begin
    lCat := TCategory.Create;
    lCat.Name := node.Attributes['name'];

    if node.SelectNodesNS(cNameSpace, cActions, nodes_act) then
      for actionNode in nodes_act do
        lCat.FActions.Add(actionNode.Text);

    FCategories.Add(lCat);
  end;
end;

{ TUserActivityCategoriesOverview.TCategory }

constructor TUserActivityCategoriesOverview.TCategory.Create;
begin
  FActions := TStringList.Create;
end;

destructor TUserActivityCategoriesOverview.TCategory.Destroy;
begin
  FActions.Free;
  inherited;
end;

{ TUserActivityLogEventType }

procedure TUserActivityLogEventType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  inherited;

//  FDescription := aNode.selectSingleNode('description').text;
//  FDetailedDescription := aNode.selectSingleNode('detaileddescription').text;
//  FMachineName := aNode.selectSingleNode('machinename').text;
//  FOldValue := aNode.selectSingleNode('oldvalue').text;
//  FNewValue := aNode.selectSingleNode('newvalue').text;
//  FCode := aNode.selectSingleNode('code').text;
//  FUserId := aNode.attributes.getNamedItem('UserId').text;
//  FCategory := aNode.attributes.getNamedItem('Category').text;
//  FAction := aNode.attributes.getNamedItem('Action').text;
//  FActionDateTime := XMLTodateTime(aNode.attributes.getNamedItem('actionDateTime').text);
//  FActionAffectsDate := XMLToDate(aNode.attributes.getNamedItem('actionAffectsDate').text);
//  FUserLocation := aNode.attributes.getNamedItem('Userlocation').text;
//  FReservation := StrToIntDef(aNode.attributes.getNamedItem('Reservation').text, 0);
//  FRoomreservation := StrToIntDef(aNode.attributes.getNamedItem('Roomreservation').text, 0);
//  Fid1 := aNode.attributes.getNamedItem('id1').text;
//  Fid2 := aNode.attributes.getNamedItem('id2').text;
//  Fid3 := aNode.attributes.getNamedItem('id3').text;
end;

{ TUserActivityLogFragment }

procedure TUserActivityLogFragment.Clear;
begin
  inherited;
  FLogEventList.Clear;
end;

constructor TUserActivityLogFragment.Create;
begin
  FLogEventList := TUserActivityLogEventTypeList.Create;
end;

destructor TUserActivityLogFragment.Destroy;
begin
  FLogEventList.Free;
  inherited;
end;


procedure TUserActivityLogFragment.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  node: PXMLNode;
  nodes_event: IXMLNodeList;
  lEvent: TUserActivityLogEventType;
  i, j: integer;
begin
  inherited;
//  nodes_event := aNode.selectNodes('/UserActivityLogEvent');
//  for i := 0 to nodes_event.length - 1 do
//  begin
//    node := nodes_event.item[i];
//    lEvent := TUserActivityLogEventType.Create;
//    lEvent.SetPropertiesFromXMLNode(node);
//    FLogEventList.Add(lEvent);
//  end;
end;

{ TxsdBaseObject }

function TxsdBaseObject.LoadFromXML(const aXML: string): boolean;
var
  xmlDoc: IXMLDocument;
begin
  Clear;
  xmlDoc := TXMLDocument.Create;
  xmlDoc.LoadFromXML(aXML);
  if assigned(xmlDoc.parseError) then
    raise EXMLDocException.Create('XML Load error:' + xmlDoc.parseError.reason);

  SetPropertiesFromXMLNode(xmlDoc.DocumentElement);
end;

end.
