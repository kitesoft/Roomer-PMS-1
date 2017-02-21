unit uRoomerSchema;

interface

uses
   Classes
   , SysUtils
   , Spring.Collections.Lists
   , Spring.Collections
   , XMLIntf
   , OXmlPDOM
   ;

type
  EXMLDocException = class(Exception);

  TxsdBaseObject = class(TObject)
  protected
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); virtual;
  public
    procedure LoadFromXML(const aXML: string);
    procedure Clear; virtual; abstract;
  end;

implementation


{ TxsdBaseObject }

procedure TxsdBaseObject.LoadFromXML(const aXML: string);
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

procedure TxsdBaseObject.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  Clear;
end;

end.
