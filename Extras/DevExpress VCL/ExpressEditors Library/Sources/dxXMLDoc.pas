
{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{       ExpressEditors                                               }
{                                                                    }
{       Copyright (c) 1998-2014 Developer Express Inc.               }
{       ALL RIGHTS RESERVED                                          }
{                                                                    }
{   The entire contents of this file is protected by U.S. and        }
{   International Copyright Laws. Unauthorized reproduction,         }
{   reverse-engineering, and distribution of all or any portion of   }
{   the code contained in this file is strictly prohibited and may   }
{   result in severe civil and criminal penalties and will be        }
{   prosecuted to the maximum extent possible under the law.         }
{                                                                    }
{   RESTRICTIONS                                                     }
{                                                                    }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES            }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE     }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS    }
{   LICENSED TO DISTRIBUTE THE EXPRESSEDITORS AND ALL                }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY. }
{                                                                    }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED       }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE         }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE        }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT   }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                       }
{                                                                    }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON        }
{   ADDITIONAL RESTRICTIONS.                                         }
{                                                                    }
{********************************************************************}

unit dxXMLDoc;

{$I cxVer.inc}

interface

uses
  Classes, dxCore, dxCoreClasses, cxClasses, cxControls, SysUtils, dxCustomTree,
  Windows, StrUtils {$IFDEF DELPHI12}, AnsiStrings {$ENDIF};

type
  TdxXMLNode = class;
  TdxXMLNodeAttribute = class;
  TdxXMLNodeAttributes = class;
  TdxXMLDocument = class;

  TdxXMLString = type AnsiString;
  TdxXMLValueType = {$IFDEF DELPHI12} UnicodeString {$ELSE} WideString {$ENDIF};


  { TdxXMLNodeAttribute }

  TdxXMLNodeAttribute = class(TcxDoublyLinkedObject)
  private
    FName: TdxXMLString;
    FValue: TdxXMLString;
  public
    function GetDataSize: Integer;
    function ToAnsiString: TdxXMLString;

    property Name: TdxXMLString read FName write FName;
    property Value: TdxXMLString read FValue write FValue;
  end;

  { TdxXMLNodeAttributes }

  TdxXMLNodeAttributes  = class(TcxDoublyLinkedObjectList)
  private
    FCount: Integer;
    FFirst: TdxXMLNodeAttribute;
    FNode: TdxXMLNode;
    function GetLast: TdxXMLNodeAttribute;
  protected
    function CreateLinkedObject: TcxDoublyLinkedObject; override;
    function GetAsText: TdxXMLString;
  public
    function Add: TcxDoublyLinkedObject; overload; override;
    function Add(const AttrName, AValue: TdxXMLString): TdxXMLNodeAttribute; reintroduce; overload;
    function Add(const AttrName: TdxXMLString; const AValue: TdxXMLValueType): TdxXMLNodeAttribute; reintroduce; overload;
    procedure Remove(var ALinkedObject: TcxDoublyLinkedObject); override;

    property Count: Integer read FCount;
    property First: TdxXMLNodeAttribute read FFirst;
    property Last: TdxXMLNodeAttribute read GetLast;
    property Node: TdxXMLNode read FNode;
  end;

  { TdxXMLNode }

  TdxXMLNode = class(TdxTreeCustomNode)
  private
    FAttributes: TdxXMLNodeAttributes;
    FAttributesAsText: TdxXMLString;
    FName: TdxXMLString;
    FNamespaceURI: TdxXMLString;
    FText: TdxXMLString;
    function GetAttributesAsText: TdxXMLString;
    function GetDocument: TdxXMLDocument;
    procedure SetText(const AValue: TdxXMLString);
  protected
    procedure CheckEncodedText(var AText: TdxXMLString); virtual;
    function GetAttributesSize: Integer; virtual;
    function GetChildrenSize: Integer; virtual;
    function GetDataSize: Integer; virtual;
    function HasData: Boolean;
    procedure ReadData(AStream: TStream); override;
    procedure WriteAttributes(AStream: TStream); virtual;
    procedure WriteChildren(AStream: TStream); virtual;
    procedure WriteData(AStream: TStream); override;
    procedure WriteString(AStream: TStream; const AString: TdxXMLString);
  public
    constructor Create(AOwner: IdxTreeOwner); override;
    destructor Destroy; override;
    function AddChild(const ATagName: TdxXMLString): TdxXMLNode; overload;
    function AddChild(const ATagName, ANamespaceURI: TdxXMLString): TdxXMLNode; overload;
    procedure AddAttribute(const AttrName: TdxXMLString; const AValue: Widestring);
    procedure SetAttribute(const AttrName: TdxXMLString; const AValue: Variant); 

    property Attributes: TdxXMLNodeAttributes read FAttributes;
    property AttributesAsText: TdxXMLString read GetAttributesAsText;  
    property Document: TdxXMLDocument read GetDocument; 
    property Name: TdxXMLString read FName; // tag name
    property NamespaceURI: TdxXMLString read FNamespaceURI;
    property Text: TdxXMLString read FText write SetText;
  end;

  { TdxXMLRootNode }

  TdxXMLRootNode = class(TdxXMLNode)
  protected
    function GetDataSize: Integer; override;
    function GetHeaderText: TdxXMLString;
    procedure WriteData(AStream: TStream); override;
  end;

  { TdxXMLDocument }

  TdxXMLDocument = class(TcxInterfacedPersistent, IdxTreeOwner)
  private
    FEncoding: TdxXMLString;
    FRoot: TdxXMLNode;
    FStandAlone: TdxXMLString;
    FVersion: TdxXMLString;
    function IdxTreeOwner.GetOwner = GetNodesOwner;
  protected
    procedure BeforeDelete(ASender: TdxTreeCustomNode);
    procedure BeginUpdate;
    function CanCollapse(ASender: TdxTreeCustomNode): Boolean;
    function CanExpand(ASender: TdxTreeCustomNode): Boolean;
    procedure Collapsed(ASender: TdxTreeCustomNode);
    procedure DeleteNode(ASender: TdxTreeCustomNode);
    procedure EndUpdate;
    procedure Expanded(ASender: TdxTreeCustomNode);
    function GetNodeClass(ARelativeNode: TdxTreeCustomNode): TdxTreeCustomNodeClass; virtual; 
    function GetNodesOwner: TPersistent;  
    procedure LoadChildren(ASender: TdxTreeCustomNode);
    procedure TreeNotification(ASender: TdxTreeCustomNode; ANotification: TdxTreeNodeNotifications);
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    function AddChild(const ATagName: TdxXMLString): TdxXMLNode; overload;
    function AddChild(const ATagName, ANamespaceURI: TdxXMLString): TdxXMLNode; overload;

    procedure SaveToFile(const AFileName: TFileName);
    procedure SaveToStream(AStream: TStream);

    property Encoding: TdxXMLString read FEncoding write FEncoding;
    property Root: TdxXMLNode read FRoot;
    property Standalone: TdxXMLString read FStandAlone write FStandAlone;
    property Version: TdxXMLString read FVersion write FVersion;
  end;

function dxXMLCheckValueText(const AValue: AnsiString): AnsiString;

implementation

const
  XMLServiceCharMap: array [0..3, 0..1] of AnsiString = (
    ('&', '&amp;'),
    ('"', '&quot;'),
    ('<', '&lt;'),
    ('>', '&gt;'));

function dxXMLCheckValueText(const AValue: AnsiString): AnsiString;
var
  I: Integer;
  ACode: Byte;
begin
  Result := AValue;
  for I := 0 to 3 do
    Result := StringReplace(Result, XMLServiceCharMap[I, 0], XMLServiceCharMap[I, 1], [rfReplaceAll]);
  I := 1;
  while I <= Length(Result) do
  begin
    ACode := Byte(Result[I]);
    if (ACode > $1F) or (ACode = 9) or (ACode = 10) or (ACode = 13) then
      Inc(I)
    else
    begin
      Delete(Result, I, 1);
      Insert('_x' + dxStringToAnsiString(IntToHex(ACode, 4)) + '_', Result, I);
      Inc(I, 7);
    end;
  end;
  Result := StringReplace(Result, AnsiString('_x000D__x000A_'), AnsiString('_x000D_'#13#10), [rfReplaceAll, rfIgnoreCase]);
end;

{ TdxXMLNodeAttribute }

function TdxXMLNodeAttribute.GetDataSize: Integer;
begin
  Result := Length(Name) + Length(Value) + 4;
end;

function TdxXMLNodeAttribute.ToAnsiString: TdxXMLString;
begin
  Result := ' ' + Name + '="' + Value + '"';
end;


{ TdxXMLNodeAttributes }

function TdxXMLNodeAttributes.Add: TcxDoublyLinkedObject;
begin
  Result := inherited Add;
  Inc(FCount);
  if FFirst = nil then
    FFirst := TdxXMLNodeAttribute(Result);
end;

function TdxXMLNodeAttributes.Add(
  const AttrName, AValue: TdxXMLString): TdxXMLNodeAttribute;
begin
  Result := TdxXMLNodeAttribute(Add);
  Result.Value := AValue;
  Result.Name := AttrName;
end;

function TdxXMLNodeAttributes.Add(const AttrName: TdxXMLString;
  const AValue: TdxXMLValueType): TdxXMLNodeAttribute;
begin
  Result := Add(AttrName, dxWideStringToAnsiString(AValue, CP_UTF8));
end;

procedure TdxXMLNodeAttributes.Remove(var ALinkedObject: TcxDoublyLinkedObject);
begin
  inherited Remove(ALinkedObject);
  Dec(FCount);
end;

function TdxXMLNodeAttributes.CreateLinkedObject: TcxDoublyLinkedObject;
begin
  Result := TdxXMLNodeAttribute.Create;
end;

function TdxXMLNodeAttributes.GetAsText: TdxXMLString;
var
  Attribute: TdxXMLNodeAttribute;
begin
  Result := '';
  if Count = 0 then Exit; 
  Attribute := First;
  while Attribute <> nil do
  begin
    Result := Result + Attribute.ToAnsiString;
    Attribute := TdxXMLNodeAttribute(Attribute.Next);
  end;
  FCount := 0;
  FFirst := nil;
  Clear;
end;

function TdxXMLNodeAttributes.GetLast: TdxXMLNodeAttribute;
begin
  Result := TdxXMLNodeAttribute(inherited Last);
end;

{ TdxXMLNode }

constructor TdxXMLNode.Create(AOwner: IdxTreeOwner);
begin
  inherited Create(AOwner);
  FAttributes := TdxXMLNodeAttributes.Create;
  FAttributes.FNode := Self; 
end;

destructor TdxXMLNode.Destroy;
begin
  FreeAndNil(FAttributes);
  inherited Destroy;
end;

function TdxXMLNode.AddChild(const ATagName: TdxXMLString): TdxXMLNode;
begin
  Result := inherited AddChild as TdxXMLNode;
  Result.FName := ATagName;
end;

function TdxXMLNode.AddChild(const ATagName, ANamespaceURI: TdxXMLString): TdxXMLNode;
begin
  Result := AddChild(ATagName);
  Result.FNamespaceURI := ANamespaceURI;
end;

procedure TdxXMLNode.AddAttribute(const AttrName: TdxXMLString; const AValue: Widestring);
begin
  FAttributesAsText := ' ' + AttrName + '="' + dxWideStringToAnsiString(AValue, CP_UTF8) + '"';
end;

procedure TdxXMLNode.SetAttribute(const AttrName: TdxXMLString; const AValue: Variant);
begin
  Attributes.Add(AttrName, dxVariantToWideString(AValue));
end;

procedure TdxXMLNode.CheckEncodedText(var AText: TdxXMLString);
begin
end;

function TdxXMLNode.GetAttributesSize: Integer;
begin
  Result := Length(AttributesAsText) + Byte(not HasData) + 1;  // for '>' or '/>'
end;

function TdxXMLNode.GetChildrenSize: Integer;
var
  ANode: TdxXMLNode;
begin
  Result := 0;
  ANode := First as TdxXMLNode;
  while ANode <> nil do
  begin
    Inc(Result, ANode.GetDataSize);
    ANode := TdxXMLNode(ANode.Next);
  end;
end;

function TdxXMLNode.GetDataSize: Integer;
begin
  Result := GetChildrenSize;
  if (Result = 0) and (Attributes.Count = 0) and HasData then
  begin
    Result := Length(FName) * 2 + 5 + Length(dxCRLF) + Length(FText);       
    Exit;
  end;
  Inc(Result, Length(FName) + 1 + Length(dxCRLF));  // '<', 'CR', 'LF' tags
  if HasData then
    Inc(Result, Length(FName) + 3 + Length(dxCRLF)); // '<', '/>', 'CR', 'LF' tags
  if Length(FText) > 0 then
    Inc(Result, Length(FText) + Length(dxCRLF));
  Inc(Result, GetAttributesSize);
end;

function TdxXMLNode.HasData: Boolean;
begin
  Result := (First <> nil) or (Length(Text) > 0);
end;

procedure TdxXMLNode.ReadData(AStream: TStream);
begin
  //nothing to do
end;

procedure TdxXMLNode.WriteAttributes(AStream: TStream);
const
  EndTag: array[Boolean] of TdxXMLString = ('/>' + dxCRLF, '>' + dxCRLF);
begin
  WriteString(AStream, AttributesAsText + EndTag[HasData]);
end;

procedure TdxXMLNode.WriteChildren(AStream: TStream);
var
  ANode: TdxXMLNode;
begin
  ANode := First as TdxXMLNode;
  while ANode <> nil do
  begin
    ANode.WriteData(AStream);
    ANode := TdxXMLNode(ANode.Next);
  end;
end;

procedure TdxXMLNode.WriteData(AStream: TStream);
begin
  if (First = nil) and (Attributes.Count = 0) and HasData then
  begin
    WriteString(AStream, '<' + Name + '>' + FText + '</' + Name + '>' + dxCRLF);
    Exit;
  end;
  WriteString(AStream, '<' + Name);
  WriteAttributes(AStream);
  WriteChildren(AStream);
  if HasData then
  begin
    if Length(FText) > 0 then
      WriteString(AStream, FText + dxCRLF);
    WriteString(AStream, '</' + Name + '>' + dxCRLF);
  end;
end;

procedure TdxXMLNode.WriteString(AStream: TStream; const AString: TdxXMLString);
begin

  if Length(AString) > 0 then
    AStream.WriteBuffer(AString[1], Length(AString));
end;

function TdxXMLNode.GetAttributesAsText: TdxXMLString;
begin
  FAttributesAsText := FAttributesAsText + Attributes.GetAsText;
  Result := FAttributesAsText;
end;

function TdxXMLNode.GetDocument: TdxXMLDocument;
begin
  Result := TdxXMLDocument(FOwner.GetOwner);
end;

procedure TdxXMLNode.SetText(const AValue: TdxXMLString);
begin
  FText := dxXMLCheckValueText(AValue);
  CheckEncodedText(FText);
end;

{ TdxXMLRootNode }

function TdxXMLRootNode.GetDataSize: Integer;
begin
  Result := GetChildrenSize + Length(GetHeaderText);
end;

function TdxXMLRootNode.GetHeaderText: TdxXMLString;
begin
  Result := '';
  if (Length(Document.Version) > 0) or (Length(Document.Encoding) > 0) or (Length(Document.StandAlone) > 0) then
  begin
    Result := '<?xml';
    if Length(Document.Version) > 0 then
      Result := Result + ' version="' + Document.Version + '"';
    if Length(Document.Encoding) > 0 then
      Result := Result + ' encoding="' + Document.Encoding + '"';
    if Length(Document.Standalone) > 0 then
      Result := Result + ' standalone="' + Document.Standalone + '"';
    Result := Result + '?>' + dxCRLF;
  end;
end;

procedure TdxXMLRootNode.WriteData(AStream: TStream);
begin
  WriteString(AStream, GetHeaderText);
  WriteChildren(AStream);
end;

{ TdxXMLDocument }

constructor TdxXMLDocument.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FRoot := TdxXMLRootNode.Create(Self);
end;

destructor TdxXMLDocument.Destroy; 
begin
  FreeAndNil(FRoot);
  inherited Destroy; 
end;

function TdxXMLDocument.AddChild(const ATagName: TdxXMLString): TdxXMLNode;
begin
  Result := AddChild(ATagName, '');
end;

function TdxXMLDocument.AddChild(const ATagName, ANamespaceURI: TdxXMLString): TdxXMLNode;
begin
  Result := Root.AddChild(ATagName, ANamespaceURI);
end;

procedure TdxXMLDocument.SaveToFile(const AFileName: TFileName);
var
  AStream: TFileStream;
begin
  AStream := TFileStream.Create(AFileName, fmCreate);
  try
    SaveToStream(AStream);
  finally
    AStream.Free;
  end;
end;

procedure TdxXMLDocument.SaveToStream(AStream: TStream);
var
  I: Integer;
begin
  I := AStream.Position;
  AStream.Size := I + Root.GetDataSize;
  AStream.Position := I;
  Root.WriteData(AStream);
end;

procedure TdxXMLDocument.BeforeDelete(ASender: TdxTreeCustomNode);
begin
end;

procedure TdxXMLDocument.BeginUpdate;
begin
end;

function TdxXMLDocument.CanCollapse(ASender: TdxTreeCustomNode): Boolean;
begin
  Result := True;
end;

function TdxXMLDocument.CanExpand(ASender: TdxTreeCustomNode): Boolean;
begin
  Result := True;
end;

procedure TdxXMLDocument.Collapsed(ASender: TdxTreeCustomNode);
begin
end;

procedure TdxXMLDocument.DeleteNode(ASender: TdxTreeCustomNode);
begin
end;

procedure TdxXMLDocument.EndUpdate;
begin
end;

procedure TdxXMLDocument.Expanded(ASender: TdxTreeCustomNode);
begin
end;

function TdxXMLDocument.GetNodesOwner: TPersistent;
begin
  Result := Self;
end;

procedure TdxXMLDocument.LoadChildren(ASender: TdxTreeCustomNode);
begin
end; 

function TdxXMLDocument.GetNodeClass(
  ARelativeNode: TdxTreeCustomNode): TdxTreeCustomNodeClass;
begin
  Result := TdxXMLNode;
end;

procedure TdxXMLDocument.TreeNotification(ASender: TdxTreeCustomNode; ANotification: TdxTreeNodeNotifications);
begin
end;

end.
