unit uRoomerHotelServicesCommunicationModel_RequestsResponses;

interface

uses
   Classes
   , SysUtils
   , Generics.Collections
   ;

type
  EXMLDocException = class(Exception);

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

  TUserActivityCategoriesOverview = class(TObject)
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
  public
    constructor Create;
    destructor Destroy; override;

    function LoadFromXML(const aXML: string): boolean;
    procedure Clear;

    procedure AddCategoryNamesAsString(aString: TStrings);
    property Categories: TObjectList<TCategory> read FCategories;
  end;

implementation

uses
  XMLUtils
  , MSXML2_TLB
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

function TUserActivityCategoriesOverview.LoadFromXML(const aXML: string): boolean;
var
  xmlDoc: IXMLDOMDocument2;
  node: IXMLDomNode;
  nodes_cat: IXMLDomNodeList;
  nodes_act: IXMLDomNodeList;
  lCat: TCategory;
  i, j: integer;
begin
  Clear;
  xmlDoc := CreateXmlDocument;
  xmlDoc.loadXML(aXML);
  if xmlDoc.parseError.errorCode <> 0 then
    raise EXMLDocException.Create('XML Load error:' + xmlDoc.parseError.reason);

  nodes_cat := xmlDoc.selectNodes('/UserActivityCategoriesOverview/Category');
  for i := 0 to nodes_cat.length - 1 do
  begin
    node := nodes_cat.item[i];
    lCat := TCategory.Create;
    lCat.Name := node.attributes.getNamedItem('name').Text;

    nodes_act := node.selectNodes('Action');
    for j := 0 to nodes_act.length - 1 do
      lCat.FActions.Add(nodes_act.item[j].attributes.getNamedItem('name').Text);

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

end.
