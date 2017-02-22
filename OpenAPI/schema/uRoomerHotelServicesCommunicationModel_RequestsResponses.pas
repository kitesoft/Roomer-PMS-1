unit uRoomerHotelServicesCommunicationModel_RequestsResponses;

interface

uses
   Classes
   , SysUtils
   //, Generics.Collections
   , Spring.Collections.Lists
   , Spring.Collections
   , uRoomerSchema
   , XMLIntf
   , OXmlPDOM
   ;

type

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
  {$M+}
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

    TCategoryList = TObjectList<TCategory>;
  private
    FCategories: IList<TCategory>;
    function GetCategories: TCategoryList;
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Clear; override;

    procedure AddCategoryNamesAsString(aString: TStrings);
  published
    property Categories: TCategoryList read GetCategories;
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

  {$M+}
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
    procedure Clear; override;
  published
    property ActionDateTime: TDateTime read FActionDateTime write FActionDateTime;
    property UserId: string read FUserId write FUserId;
    property Category: string read FCategory write FCategory;
    property Action: string read FAction write FAction;
    property Description: string read FDescription write FDescription;
    property DetailedDescription: string read FDetailedDescription write FDetailedDescription;
    property OldValue: string read FOldValue write FOldValue;
    property NewValue: string read FNewValue write FNewValue;
    property Code: string read FCode write FCode;
    property ActionAffectsDate: TDate read FActionAffectsDate write FActionAffectsDate;
    property Reservation: integer read FReservation write FReservation;
    property Roomreservation: integer read FRoomreservation write FRoomreservation;
    property id1: string read Fid1 write Fid1;
    property id2: string read Fid2 write Fid2;
    property id3: string read Fid3 write Fid3;
    property UserLocation: string read FUserLocation write FUserLocation;
    property MachineName: string read FMachineName write FMachineName;
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

  {$M+}
  TUserActivityLogFragment = class(TxsdBaseObject)
  private
    FLogEventList: IList<TUserActivityLogEventType>;
    function GetLogEventList: TUserActivityLogEventTypeList;
  public
    constructor Create;
    destructor Destroy; override;

    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); override;
    procedure Clear; override;
  published
    property LogEventList: TUserActivityLogEventTypeList read GetLogEventList;
  end;

implementation

uses
  XMLUtils
  ;

const
  cNameSpaceURI = 'http://www.promoir.nl/roomer/services/hotel/2017/01';

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
  FCategories := TCategoryList.Create;
end;

destructor TUserActivityCategoriesOverview.Destroy;
begin
  inherited;
end;

function TUserActivityCategoriesOverview.GetCategories: TCategoryList;
begin
  Result := FCategories as TCategoryList;
end;

procedure TUserActivityCategoriesOverview.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lCategoryNode: PXMLNode;
  lActionNode: PXMLNode;
  lCatNodes: IXMLNodeList;
  lActNodes: IXMLNodeList;
  lCat: TCategory;
const
  cCategories= 'Category';
  cActions= 'Action';
begin
  inherited;

  if aNode.SelectNodesNS(cNameSpaceURI, cCategories, lCatNodes) then
  for lCategoryNode in lCatNodes do
  begin
    lCat := TCategory.Create;
    lCat.Name := lCategoryNode.Attributes['name'];

    if lCategoryNode.SelectNodesNS(cNameSpaceURI, cActions, lActNodes) then
      for lActionNode in lActNodes do
        lCat.FActions.Add(lActionNode.Text);

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

procedure TUserActivityLogEventType.Clear;
begin
  FDescription := '';
  FDetailedDescription := '';
  FMachineName := '';
  FOldValue := '';
  FNewValue := '';
  FCode := '';
  FUserId := '';
  FCategory := '';
  FAction := '';
  FActionDateTime := 0;
  FActionAffectsDate := 0;
  FUserLocation := '';
  FReservation := 0;
  FRoomreservation := 0;
  Fid1 := '';
  Fid2 := '';
  Fid3 := '';
end;

procedure TUserActivityLogEventType.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lnodeList: IXMLNodeList;
begin
  inherited;

  if aNode.SelectNodesNS(cNameSpaceURI, 'description', lNodeList, 1) then
    FDescription := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'detailedDescription', lNodeList, 1) then
    FDetailedDescription := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'machineName', lNodeList, 1) then
    FMachineName := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'oldValue', lNodeList, 1) then
    FOldVAlue:= lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'newValue', lNodeList, 1) then
    FNewValue := lNodeList.GetFirst.Text;
  if aNode.SelectNodesNS(cNameSpaceURI, 'code', lNodeList, 1) then
    FCode := lNodeList.GetFirst.Text;

  FUserId := aNode.Attributes['userId'];
  FCategory := aNode.Attributes['category'];
  FAction := aNode.Attributes['action'];
  FActionDateTime := XMLTodateTime(aNode.Attributes['actionDateTime']);
  FActionAffectsDate := XMLToDate(aNode.Attributes['actionAffectsDate']);
  FUserLocation := aNode.Attributes['userLocation'];
  FReservation := StrToIntDef(aNode.Attributes['reservation'], 0);
  FRoomreservation := StrToIntDef(aNode.Attributes['roomReservation'], 0);
  Fid1 := aNode.Attributes['id1'];
  Fid2 := aNode.Attributes['id2'];
  Fid3 := aNode.Attributes['id3'];
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
  inherited;
end;


function TUserActivityLogFragment.GetLogEventList: TUserActivityLogEventTypeList;
begin
  Result := FLogEventList as TUserActivityLogEventTypeList;
end;

procedure TUserActivityLogFragment.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lEventNode: PXMLNode;
  lEventNodes: IXMLNodeList;
  lEvent: TUserActivityLogEventType;
const
  cFragment = '//UserActivityLogFragment/UserActivityLogEvent';
begin
  inherited;
  FLogEventList.OnChanged.Enabled := false;
  try
    if aNode.SelectNodesNS(cNameSpaceURI, cFragment, lEventNodes) then
    for lEventNode in lEventNodes do
    begin
      lEvent := TUserActivityLogEventType.Create;
      lEvent.SetPropertiesFromXMLNode(lEventNode);
      FLogEventList.Add(lEvent);
    end;
  finally
    FLogEventList.OnChanged.Enabled := true;
  end;
end;


end.