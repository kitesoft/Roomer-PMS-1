unit XmlUtils;

interface

uses
  System.Classes
  , SysUtils
  , XMLDoc
  , XMLIntf
  , xmldom
  , MSXML2_TLB
  , ActiveX
  ;

function CreateXmlDocument : IXMLDOMDocument2; overload;
function CreateXMLDocument( var Owner1: TComponent): TXMLDocument; overload;
function XPATHSelect( const FocusNode: IXMLNode; const sXPath: string): TArray<IXMLNode>;
function XPATHSelectFirst( const FocusNode: IXMLNode; const sXPath: string; var SelectedNode: IXMLNode): boolean;
function GetAttributeValue(Node: IXMLDomNode; AttribName, defaultValue: String): String;
function GetOptionalElementText(aNode: IXMLNode; const aElementName: string): string;

function XMLToFloat(const aStringValue: string; aDefault: extended = 0.00): extended;
function FloatToXML(aValue: double; aDecimals: integer = 0): string;
function XMLToDateTime(const aStringValue: string): TDateTime;
function XMLToDate(const aStringValue: string): TDate;
function DateToXML(aDate: TDate): string;
function XMLToBool(const aBoolValue: string; aDefault: boolean = false): boolean;
function BoolToXML(aValue: boolean): string;

var
  // Fixed predefined formatsettings to be used when formatting from or to XML strings
  XMLFormatSettings: TFormatSettings;

implementation

uses
  uFloatUtils
  , uStringUtils;

function GetAttributeValue(Node: IXMLDomNode; AttribName, defaultValue: String): String;
var
  i: Integer;
begin
  Result := defaultValue;
  for i := 0 to Node.Attributes.length - 1 do
    if Node.Attributes.item[i].nodeName = AttribName then
    begin
      Result := Node.Attributes.item[i].Text;
      Break;
    end;
end;

function GetOptionalElementText(aNode: IXMLNode; const aElementName: string): string;
var
  lNode: IXMLNOde;
begin
  Result := '';
  lNode := aNode.ChildNodes.FindNode(aElementName);
  if lNode <> nil then
    Result := lNode.Text;
end;


function CreateXmlDocument : IXMLDOMDocument2;
begin
  CoInitialize(nil);
  try
    try
      result := MSXML2_TLB.CoDOMDocument60.Create;
    except // Not registered? Try version 6...
      result := CoDOMDocument60.Create;
    end;
  finally
    CoUninitialize;
  end;
end;



function CreateXMLDocument( var Owner1: TComponent): TXMLDocument;
begin
  Owner1 := TComponent.Create( nil);
  result  := TXMLDocument.Create( Owner1);
  result.Options := [doNodeAutoCreate, doNodeAutoIndent, doAttrNull,
                     doAutoPrefix, doNamespaceDecl];
  result.DOMVendor := GetDOMVendor( 'MSXML');
end;

function XPATHSelect( const FocusNode: IXMLNode; const sXPath: string): TArray<IXMLNode>;
var
  DomNodeSelect: IDomNodeSelect;
  DOMNode      : IDomNode;
  DocAccess    : IXmlDocumentAccess;
  Doc          : TXmlDocument;
  DOMNodes     : IDOMNodeList;
  iDOMNode     : integer;
begin
  SetLength( result, 0);
  if assigned( FocusNode) and
     Supports( FocusNode.DOMNode, IDomNodeSelect, DomNodeSelect) then
      DOMNodes := DomNodeSelect.SelectNodes( sXPath);
  if not assigned( DOMNodes) then exit;
  SetLength( result, DOMNodes.Length);
  for iDOMNode := 0 to DOMNodes.Length - 1 do
    begin
      Doc := nil;
      DOMNode := DOMNodes.item[iDOMNode];
      if Supports( DOMNode, IXmlDocumentAccess, DocAccess) then
        Doc := DocAccess.DocumentObject;
      result[ iDOMNode] := TXmlNode.Create( DOMNode, nil, Doc) as IXMLNode;
    end
end;

function XPATHSelectFirst( const FocusNode: IXMLNode; const sXPath: string; var SelectedNode: IXMLNode): boolean;
var
  DomNodeSelect: IDomNodeSelect;
  DOMNode      : IDomNode;
  DocAccess    : IXmlDocumentAccess;
  Doc          : TXmlDocument;
begin
  SelectedNode := nil;
  Doc := nil;
  if assigned( FocusNode) and
     Supports( FocusNode.DOMNode, IDomNodeSelect, DomNodeSelect) then
    DOMNode := DomNodeSelect.selectNode( sXPath);
  if assigned( DOMNode) and
     Supports( DOMNode.OwnerDocument, IXmlDocumentAccess, DocAccess) then
    Doc := DocAccess.DocumentObject;
  if Assigned( DOMNode) then
    SelectedNode := TXmlNode.Create( DOMNode, nil, Doc);
  result := assigned( SelectedNode)
end;


function FloatToXML(aValue: double; aDecimals: integer = 0): string;
begin
  Result := FloatToStr(RoundDecimals(aValue, aDecimals), XMLFormatSettings);
end;

function XMLToFloat(const aStringValue: string; aDefault: extended = 0.00): extended;
begin
  Result := StrToFloatDef(aStringValue, aDefault, XMLFormatSettings);
end;

function XMLToDateTime(const aStringValue: string): TDateTime;
begin
  Result := StrToDateTimeDef(aStringValue, 0, XMLFormatSettings);
end;

function XMLToDate(const aStringValue: string): TDate;
begin
  Result := StrToDateDef(aStringValue, 0, XMLFormatSettings);
end;

function DateToXML(aDate: TDate): string;
begin
  Result := DateToStr(aDate, XMLFormatSettings);
end;

function XMLToBool(const aBoolValue: string; aDefault: boolean = false): boolean;
begin
  Result := aBoolValue.ToLower.Equals('true') or aBoolValue.Equals('1');
end;

function BoolToXML(aValue: boolean): string;
begin
  Result := BoolToString(aValue);
end;


procedure InitXMLFormatSettings;
begin
  with XMLFormatSettings do
  begin
    DecimalSeparator := '.';
    ThousandSeparator := ',';
    DateSeparator := '-';
    TimeSeparator := ':';
    ShortDateFormat := 'yyyy-mm-dd';
    ShortTimeFormat := 'HH:mm';
  end;
end;

initialization
  initXMLFormatSettings;
end.
