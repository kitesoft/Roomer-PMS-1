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
  ERoomerSchemaException = class(Exception);

  TxsdBaseObject = class abstract (TPersistent)
  private
    FIsDirty: boolean;
  protected
    class function GetNodeName: string; virtual;
    class function GetNameSpaceURI: string; virtual;
    procedure SetIsDirty(Value: boolean);
    procedure AssignTo(Dest: TPersistent); override;
  public
    function Clone: TxsdBaseObject;
    procedure LoadFromXML(const aXML: string);
    function AsXMLDocument: IXMLDocument;
    procedure Assign(Source: TPersistent); override;
    procedure Clear; virtual;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); virtual;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); virtual;

    property IsDirty: boolean read FIsDirty;
  end;

  TxsdBaseObjectClass = class of TxsdBaseObject;


  TxsdBaseObjectList<T: TxsdBaseObject, constructor> = class abstract(TObjectList<T>)
  protected
  public
    class function GetNodeName: string; virtual;
    class function GetNameSpaceURI: string; virtual;
    class function GetChildNodeName: string; virtual;
    class function GetChildNameSpaceURI: string; virtual;
    procedure SetPropertiesFromXMLNode(const aNode: PXMLNode); virtual;
    procedure AddPropertiesToXMLNode(const aNode: PXMLNode); virtual;
    procedure LoadFromXML(const aXML: string);

    procedure CopyAllDirtyItemsInto(aObjectList: TxsdBaseObjectList<T>);
  end;


implementation

uses
  Spring.Collections.Base
  ;


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
    raise ERoomerSchemaException.Create('XML Load error:' + xmlDoc.parseError.reason);

  if GetNodeName.IsEmpty or GetNameSpaceURI.IsEmpty then
    SetPropertiesFromXMLNode(xmldoc.DocumentElement)
  else
    if xmlDoc.DocumentElement.SelectNodesNS(GetNameSpaceURI, '//' + GetNodeName, lNodeList) then
      SetPropertiesFromXMLNode(lNodeList.GetFirst);
end;

procedure TxsdBaseObject.AddPropertiesToXMLNode(const aNode: PXMLNode);
begin
  if aNode.NodeName.IsEmpty then
    aNode.NodeName := GetNodeName;
end;

procedure TxsdBaseObject.Assign(Source: TPersistent);
var
  lNode: PXMLNode;
  lXMLDoc:IXMLDocument;
begin
  if (Source.ClassType = ClassType) then
  begin
    lXMLDoc := CreateXMLDoc;
    lNode := lXMLDoc.DocumentElement.AddChild(GetNodeName);
    TxsdBaseObject(Source).AddPropertiesToXMLNode(lNode);
    SetPropertiesFromXMLNode(lNode);
  end
  else
    inherited;
end;

procedure TxsdBaseObject.AssignTo(Dest: TPersistent);
begin
  inherited;

end;

function TxsdBaseObject.AsXMLDocument: IXMLDocument;
begin
  Clear;
  Result := CreateXMLDoc;
  AddPropertiesToXMLNode(Result.AddChild(''));
end;

procedure TxsdBaseObject.Clear;
begin
  FIsDirty := false;
end;

function TxsdBaseObject.Clone: TxsdBaseObject;
begin
  Result := TxsdBaseObject(Self.ClassType.Create);
  Result.Assign(Self);
end;

class function TxsdBaseObject.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TxsdBaseObject.GetNodeName: string;
begin
  Result := '';
end;

procedure TxsdBaseObject.SetIsDirty(Value: boolean);
begin
  FIsDirty := Value;
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

procedure TxsdBaseObjectList<T>.CopyAllDirtyItemsInto(aObjectList: TxsdBaseObjectList<T>);
var
  lPredicate: Spring.TPredicate<T>;
  lEnumerable: IEnumerable<TxsdBaseObject>;
  lObject: T;
begin
  lPredicate :=  function(const aObject: T): boolean
                              begin
                                Result := aObject.IsDirty;
                              end;

  for lObject in Self.Where(lPredicate) do
    aObjectList.Add(lObject.Clone);

end;

class function TxsdBaseObjectList<T>.GetChildNameSpaceURI: string;
begin
  Result := T.GetNameSpaceURI;
end;

class function TxsdBaseObjectList<T>.GetChildNodeName: string;
begin
  Result := T.GetNodeName;
end;

class function TxsdBaseObjectList<T>.GetNameSpaceURI: string;
begin
  Result := '';
end;

class function TxsdBaseObjectList<T>.GetNodeName: string;
begin
  Result := '';
end;

procedure TxsdBaseObjectList<T>.LoadFromXML(const aXML: string);
var
  xmlDoc: IXMLDocument;
  lNodeList: IXMLNodeList;
begin
  Clear;
  xmlDoc := TXMLDocument.Create;
  xmlDoc.LoadFromXML(aXML);
  if assigned(xmlDoc.parseError) then
    raise ERoomerSchemaException.Create('XML Load error:' + xmlDoc.parseError.reason);

  SetPropertiesFromXMLNode(xmldoc.DocumentElement)
end;

procedure TxsdBaseObjectList<T>.SetPropertiesFromXMLNode(const aNode: PXMLNode);
var
  lItem: T;
  lNodeList: IXMLNOdeList;
  lNode: PXMLNode;
begin
  onChanged.Enabled := false;
  try
    Clear;
    if aNode.SelectNodesNS(GetChildNameSpaceURI, GetChildNodeName, lNodeList) then
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
