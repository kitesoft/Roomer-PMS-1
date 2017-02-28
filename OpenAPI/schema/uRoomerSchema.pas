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
    class function GetNodeName: string; virtual; abstract;
    class function GetNameSpaceURI: string; virtual;
  public
    procedure LoadFromXML(const aXML: string);
    function AsXMLDocument: IXMLDocument;
    procedure Clear; virtual; abstract;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); virtual;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); virtual;
  end;


  TxsdBaseObjectList<T: TxsdBaseObject, constructor> = class(TObjectList<T>)
  protected
  public
    class function GetNodeName: string; virtual; abstract;
    class function GetNameSpaceURI: string; virtual; abstract;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); virtual;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); virtual;
  end;


implementation


{ TxsdBaseObject }

procedure TxsdBaseObject.LoadFromXML(const aXML: string);
var
  xmlDoc: IXMLDocument;
  lNodeList: IXMLNodeList;
begin
  Clear;
  xmlDoc := TXMLDocument.Create;
  xmlDoc.LoadFromXML(aXML);
  if assigned(xmlDoc.parseError) then
    raise EXMLDocException.Create('XML Load error:' + xmlDoc.parseError.reason);

  if GetNodeName.IsEmpty or GetNameSpaceURI.IsEmpty then
    SetPropertiesFromXMLNode(xmldoc.DocumentElement)
  else
    if xmlDoc.DocumentElement.SelectNodesNS(GetNameSpaceURI, GetNodeName, lNodeList) then
      SetPropertiesFromXMLNode(lNodeList.GetFirst);
end;

procedure TxsdBaseObject.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  aNode.NodeName := GetNodeName;
end;

function TxsdBaseObject.AsXMLDocument: IXMLDocument;
begin
  Clear;
  Result := CreateXMLDoc;
  AddPropertiesToXMLNode(Result.AddChild(''));
end;

class function TxsdBaseObject.GetNameSpaceURI: string;
begin
  Result := '';
end;

procedure TxsdBaseObject.SetPropertiesFromXMLNode(const aNode: PXMLNode);
begin
  Clear;
end;

{ TxsdBaseObjectList<T> }

procedure TxsdBaseObjectList<T>.AddPropertiesToXMLNode(const aNode: PXMLNode);
var
  lItem: T;
begin
  aNode.NodeName := GetNodeName;
  for lItem in Self do
    lItem.AddPropertiesToXMLNode(aNode.AddChild(''));
end;

procedure TxsdBaseObjectList<T>.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lItem: T;
  lNodeList: IXMLNOdeList;
  lNode: PXMLNode;
begin
  onChanged.Enabled := false;
  try
    if aNode.SelectNodesNS(T.GetNameSpaceURI, T.GetNodeName, lNodeList) then
      for lNode in lNodeList do
      begin
        lItem := T.Create;
        lItem.SetPropertiesFromXMLNode(lNode);
        Add(lItem);
      end;
  finally
    OnChanged.Enabled := true;
  end;
end;

end.
