unit fLibraryBrowser;

interface

{$I AScript.Inc}

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics,
  Controls, Forms, Dialogs, ComCtrls,
  atScript, IDEMain, StdCtrls, ImgList, Menus;

type
  TAcceptLibraryEvent = procedure(Sender: TObject; const LibName: string; var Accept: boolean) of object;
  TAcceptClassEvent = procedure(Sender: TObject; AClass: TatClass; var Accept: boolean) of object;
  TAcceptMethodEvent = procedure(Sender: TObject; AMethod: TatMethod; var Accept: boolean) of object;
  TAcceptPropertyEvent = procedure(Sender: TObject; AProp: TatProperty; var Accept: boolean) of object;

  TfmLibraryBrowser = class(TForm)
    TreeView1: TTreeView;
    ImageList1: TImageList;
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure TreeView1Editing(Sender: TObject; Node: TTreeNode; var AllowEdit: Boolean);
  private
    FEngine: TIDEEngine;
    FTree: TTreeView;
    FRefactor: TatScriptRefactor;
    FMembersData: TObject;
    FCategoryData: TObject;
    FLibraryData: TObject;
    FGroupByLibraries: boolean;
    FOnAcceptProperty: TAcceptPropertyEvent;
    FOnAcceptMethod: TAcceptMethodEvent;
    FOnAcceptClass: TAcceptClassEvent;
    FOnAcceptLibrary: TAcceptLibraryEvent;
    procedure RemoveEmptyNodes(ObjectType: TObject);
    procedure DefineImage(ANode: TTreeNode; Index: integer);
    function AcceptLibrary(const LibName: string): boolean;
    function AcceptClass(AClass: TatClass): boolean;
    function AcceptProperty(AProp: TatProperty): boolean;
    function AcceptMethod(AMethod: TatMethod): boolean;
    procedure AddCategoryNodes(ParentNode: TTreeNode);
    function FindSiblingByName(Node: TTreeNode; const AName: string): TTreeNode;
    function GetLibSubNode(LibName, SubNodeName: string): TTreeNode;
    function ClassesNode(const LibName: string): TTreeNode;
    function FunctionsNode(const LibName: string): TTreeNode;
    function VariablesNode(const LibName: string): TTreeNode;
    function ConstantsNode(const LibName: string): TTreeNode;
    function GetNodeName(Node: TTreeNode): string;
    procedure CompareNode(Sender: TObject; Node1, Node2: TTreeNode;
      Data: Integer; var Compare: Integer);
    procedure BuildTree;
    procedure AddMethods(AClass: TatClass; ParentNode: TTreeNode);
    procedure AddProperties(AClass: TatClass; ParentNode: TTreeNode);
    procedure AddClass(AClass: TatClass; const LibName: string);
    procedure AddMethod(AMethod: TatMethod; ParentNode: TTreeNode);
    procedure AddDefaultClass(AClass: TatClass);
    procedure SetEngine(const Value: TIDEEngine);
    function Scripter: TatCustomScripter;
  protected
    procedure CreateParams(var Params: TCreateParams); override;
  public
    procedure RefreshTree;
    property OnAcceptClass: TAcceptClassEvent read FOnAcceptClass write FOnAcceptClass;
    property OnAcceptMethod: TAcceptMethodEvent read FOnAcceptMethod write FOnAcceptMethod;
    property OnAcceptProperty: TAcceptPropertyEvent read FOnAcceptProperty write FOnAcceptProperty;
    property OnAcceptLibrary: TAcceptLibraryEvent read FOnAcceptLibrary write FOnAcceptLibrary;
    property Engine: TIDEEngine read FEngine write SetEngine;
  end;

var
  fmLibraryBrowser: TfmLibraryBrowser;

implementation

uses
  Languages.Pascal;

{$R *.dfm}

const
  FolderImageIndex = 0;
  LibraryImageIndex = 1;
  ClassImageIndex = 2;
  ProcedureImageIndex = 3;
  ClassProcedureImageIndex = 4;
  FunctionImageIndex = 5;
  ClassFunctionImageIndex = 6;
  PropertyImageIndex = 7;
  ClassPropertyImageIndex = 8;
  VariableImageIndex = 9;
  ConstantImageIndex = 10;

procedure TfmLibraryBrowser.AddClass(AClass: TatClass; const LibName: string);
var
  Ancestor: string;
  MethodsNode: TTreeNode;
  PropsNode: TTreeNode;
  ClassNode: TTreeNode;
begin
  if not (AcceptClass(AClass) and AcceptLibrary(LibName)) then Exit;

  // Create class node
  ClassNode := FTree.Items.AddChildObject(ClassesNode(LibName), AClass.Name, AClass);
  DefineImage(ClassNode, ClassImageIndex);

  // create subnodes
  MethodsNode := FTree.Items.AddChildObject(ClassNode, 'Methods', FMembersData);
  DefineImage(MethodsNode, FolderImageIndex);
  PropsNode := FTree.Items.AddChildObject(ClassNode, 'Properties', FMembersData);
  DefineImage(PropsNode, FolderImageIndex);

  // Set class node text
  Ancestor := AClass.AncestorName;
  if Ancestor = '' then
    Ancestor := 'TObject';
  ClassNode.Text := Format('%s(%s)', [AClass.Name, Ancestor]);

  // add methods
  AddMethods(AClass, MethodsNode);

  // add properties
  AddProperties(AClass, PropsNode);
end;

procedure TfmLibraryBrowser.AddDefaultClass(AClass: TatClass);
var
  I: integer;
  PropNode: TTreeNode;
  PropCaption: string;
  AProp: TatProperty;
  Args: string;
begin
  // each method in a default class is a procedure and might have been registered
  // by different libraries
  for I := 0 to AClass.Methods.Count - 1 do
    if AcceptLibrary(AClass.Methods[I].LibContext) then
      AddMethod(AClass.Methods[I], FunctionsNode(AClass.Methods[I].LibContext));

  for I := 0 to AClass.Properties.Count - 1 do
  begin
    AProp := AClass.Properties[I];
    Args := FRefactor.BuildPropertyArgs(AProp);

    if AProp.Writeable then
    begin
      if AcceptProperty(AProp) and (AcceptLibrary(AProp.LibContext)) then
      begin
        PropCaption := AProp.Name;
        PropNode := FTree.Items.AddChildObject(VariablesNode(AProp.LibContext), PropCaption, AProp);
        DefineImage(PropNode, VariableImageIndex);
      end;
    end
    else
    begin
      if VarIsEmpty(AProp.Value) or VarIsNull(AProp.Value) then
      begin
        if AcceptProperty(AProp) and AcceptLibrary(AProp.LibContext) then
        begin
          PropCaption := Format('function %s', [AProp.Name]);
          PropNode := FTree.Items.AddChildObject(FunctionsNode(AProp.LibContext), PropCaption, AProp);
          DefineImage(PropNode, FunctionImageIndex);
        end;
      end
      else
      begin
        if AcceptProperty(AProp) and AcceptLibrary(AProp.LibContext) then
        begin
          PropCaption := Format('%s = %s', [AProp.Name, VarContent(AProp.Value)]);
          PropNode := FTree.Items.AddChildObject(ConstantsNode(AProp.LibContext), PropCaption, AProp);
          DefineImage(PropNode, ConstantImageIndex);
        end;
      end;
    end;
  end;
end;

procedure TfmLibraryBrowser.AddMethods(AClass: TatClass; ParentNode: TTreeNode);
var
  I: integer;
begin
  for I := 0 to AClass.Methods.Count - 1 do
    AddMethod(AClass.Methods[I], ParentNode);
end;

procedure TfmLibraryBrowser.AddMethod(AMethod: TatMethod; ParentNode: TTreeNode);
var
  MethodNode: TTreeNode;
  MethodCaption: string;
begin
  if not AcceptMethod(AMethod) then Exit;

  MethodCaption := FRefactor.BuildMethodArgs(AMethod);
  if MethodCaption = '' then
    MethodCaption := AMethod.Name
  else
    MethodCaption := Format('%s(%s)', [AMethod.Name, MethodCaption]);

//  if AMethod.IsClassMethod then
//    MethodCaption := 'class ' + MethodCaption;

  MethodNode := FTree.Items.AddChildObject(ParentNode, MethodCaption, AMethod);
  if AMethod.ResultDataType <> tkNone then
  begin
    if AMethod.IsClassMethod then
      DefineImage(MethodNode, ClassFunctionImageIndex)
    else
      DefineImage(MethodNode, FunctionImageIndex);
  end
  else
  begin
    if AMethod.IsClassMethod then
      DefineImage(MethodNode, ClassProcedureImageIndex)
    else
      DefineImage(MethodNode, ProcedureImageIndex);
  end;
end;

procedure TfmLibraryBrowser.AddProperties(AClass: TatClass; ParentNode: TTreeNode);
var
  I: integer;
  PropNode: TTreeNode;
  PropCaption: string;
  AProp: TatProperty;
begin
  for I := 0 to AClass.Properties.Count - 1 do
  begin
    AProp := AClass.Properties[I];
    if AcceptProperty(AProp) then
    begin
      PropCaption := FRefactor.BuildPropertyArgs(AProp);
      if PropCaption = '' then
        PropCaption := AProp.Name
      else
        PropCaption := Format('%s[%s]', [AProp.Name, PropCaption]);
      PropNode := FTree.Items.AddChildObject(ParentNode, PropCaption, AProp);
      DefineImage(PropNode, PropertyImageIndex);
    end;
  end;
end;

function TfmLibraryBrowser.FindSiblingByName(Node: TTreeNode;
  const AName: string): TTreeNode;
begin
  Result := Node;
  while Result <> nil do
  begin
    if SameText(Result.Text, AName) then
      Exit;
    Result := Result.getNextSibling;
  end;
end;

function TfmLibraryBrowser.AcceptClass(AClass: TatClass): boolean;
begin
  Result := true;

  // remove some unused, internal classes. Let's use some verbose code
  // here to make it easier to read code, instead of a complex boolean expression
  if AClass.ClassRef = TObject then
    Result := false
  else
  if AClass.ClassRef.InheritsFrom(TatInternalObject) then
    Result := false
  else
  if AClass.ClassRef.InheritsFrom(TatScripterLibrary) then
    Result := false
  else
  if (AClass.ClassRef = TScriptBaseObject) or (AClass.ClassRef = Scripter.ScriptBaseObjectClass) then
    Result := false
  else
  if (AClass.ClassRef = Scripter.ScriptFormClass) then
    Result := false;

  // Call event
  if Assigned(FOnAcceptClass) then
    FOnAcceptClass(Self, AClass, Result);
end;

function TfmLibraryBrowser.AcceptLibrary(const LibName: string): boolean;
begin
  Result := true;

  if Assigned(FOnAcceptLibrary) then
    FOnAcceptLibrary(Self, LibName, Result);
end;

function TfmLibraryBrowser.AcceptMethod(AMethod: TatMethod): boolean;
begin
  Result := true;

  // remove internal methods or methods that are not good to display on library browser
  // Let's use some verbose code here to make it easier to read code,
  // instead of a complex boolean expression
  if (AMethod.IsClassMethod) and (AMethod.ArgCount = 0) and SameText(AMethod.Name, 'Create') then
    Result := false
  else
  if (AMethod.ArgCount = 0) and SameText(AMethod.Name, 'Free') then
    Result := false
  else
  if (AMethod.ArgCount = 0) and SameText(AMethod.Name, 'Destroy') then
    Result := false
  else
  if (AMethod.ResultClass <> nil) and (AMethod.ResultClass.InheritsFrom(TatScripterLibrary)) then
    Result := false;

  // Call event
  if Assigned(FOnAcceptMethod) then
    FOnAcceptMethod(Self, AMethod, Result);
end;

function TfmLibraryBrowser.AcceptProperty(AProp: TatProperty): boolean;
begin
  Result := true;
end;

procedure TfmLibraryBrowser.AddCategoryNodes(ParentNode: TTreeNode);
var
  Node: TTreeNode;
begin
  Node := FTree.Items.AddChildObject(ParentNode, 'Classes', FCategoryData);
  DefineImage(Node, FolderImageIndex);

  Node := FTree.Items.AddChildObject(ParentNode, 'Functions', FCategoryData);
  DefineImage(Node, FolderImageIndex);

  Node := FTree.Items.AddChildObject(ParentNode, 'Variables', FCategoryData);
  DefineImage(Node, FolderImageIndex);

  Node := FTree.Items.AddChildObject(ParentNode, 'Constants', FCategoryData);
  DefineImage(Node, FolderImageIndex);
end;

procedure TfmLibraryBrowser.BuildTree;
var
  I: integer;
  atClass: TatClass;
begin
  FTree.Items.BeginUpdate;
  try
    // clear
    FTree.Items.Clear;
    if Scripter = nil then Exit;

    // add classes
    for I := 0 to Scripter.Classes.Count - 1 do
    begin
      atClass := Scripter.Classes[I];
      if atClass.IsDefaultInstance then
        AddDefaultClass(atClass)
      else
        AddClass(atClass, atClass.LibContext);
    end;

    // remove empty categories
    RemoveEmptyNodes(FMembersData);
    RemoveEmptyNodes(FCategoryData);
    RemoveEmptyNodes(FLibraryData);

    // sort
    FTree.OnCompare := CompareNode;
    FTree.AlphaSort;
  finally
    FTree.Items.EndUpdate;
  end;
end;

function TfmLibraryBrowser.ClassesNode(const LibName: string): TTreeNode;
begin
  Result := GetLibSubNode(LibName, 'Classes');
end;

procedure TfmLibraryBrowser.CompareNode(Sender: TObject; Node1, Node2: TTreeNode;
  Data: Integer; var Compare: Integer);
var
  Name1, Name2: string;
begin
  Name1 := GetNodeName(Node1);
  Name2 := GetNodeName(Node2);
  if (Name1 = '') or (Name2 = '') then
    Compare := 0
  else
  begin
    Compare := CompareText(Name1, Name2);
  end;
end;

function TfmLibraryBrowser.ConstantsNode(const LibName: string): TTreeNode;
begin
  Result := GetLibSubNode(LibName, 'Constants');
end;

procedure TfmLibraryBrowser.DefineImage(ANode: TTreeNode; Index: integer);
begin
  ANode.ImageIndex := Index;
  ANode.SelectedIndex := Index;
  ANode.StateIndex := Index;
end;

procedure TfmLibraryBrowser.FormCreate(Sender: TObject);
begin
  FTree := TreeView1;
  FCategoryData := TObject.Create;
  FLibraryData := TObject.Create;
  FMembersData := TObject.Create;
  FRefactor := TatPascalRefactor.Create(nil);
end;

procedure TfmLibraryBrowser.FormDestroy(Sender: TObject);
begin
  FRefactor.Free;
  FCategoryData.Free;
  FMembersData.Free;
  FLibraryData.Free;
end;

function TfmLibraryBrowser.FunctionsNode(const LibName: string): TTreeNode;
begin
  Result := GetLibSubNode(LibName, 'Functions');
end;

function TfmLibraryBrowser.GetLibSubNode(LibName, SubNodeName: string): TTreeNode;
var
  LibNode: TTreeNode;
  FirstChildNode: TTreeNode;
begin
  if FGroupByLibraries then
  begin
    if LibName = '' then
      LibName := 'Default';

    // Find library node
    LibNode := FindSiblingByName(FTree.Items.GetFirstNode, LibName);
    if LibNode = nil then
    begin
      LibNode := FTree.Items.AddChildObject(nil, LibName, FLibraryData);
      DefineImage(LibNode, LibraryImageIndex);
      AddCategoryNodes(LibNode);
    end;
    FirstChildNode := LibNode.getFirstChild;
  end else
  begin
    FirstChildNode := FTree.Items.GetFirstNode;
    if FirstChildNode = nil then
    begin
      AddCategoryNodes(nil);
      FirstChildNode := FTree.Items.GetFirstNode;
    end;
  end;

  Result := FindSiblingByName(FirstChildNode, SubNodeName);
end;

function TfmLibraryBrowser.GetNodeName(Node: TTreeNode): string;
var
  Obj: TObject;
begin
  Obj := TObject(Node.Data);
  if Obj = nil then
    Result := ''
  else
  if Obj is TatClass then
    Result := TatClass(Obj).Name
  else
  if Obj is TatProperty then
    Result := TatProperty(Obj).Name
  else
  if Obj is TatMethod then
    Result := TatMethod(Obj).Name
  else
  if Obj = FLibraryData then
    Result := Node.Text
  else
    Result := '';
end;

procedure TfmLibraryBrowser.RefreshTree;
begin
  BuildTree;
end;

procedure TfmLibraryBrowser.RemoveEmptyNodes(ObjectType: TObject);
var
  Node, NextNode: TTreeNode;
begin
  Node := FTree.Items.GetFirstNode;
  while Node <> nil do
  begin
    if (Node.Data = ObjectType) then
    begin
      NextNode := Node.getNextSibling;
      if (NextNode = nil) and (Node.Parent <> nil) then
        NextNode := Node.Parent.getNextSibling;

      if not Node.HasChildren then
        Node.Delete;

      Node := NextNode;
    end
    else
      Node := Node.GetNext;
  end;
end;

function TfmLibraryBrowser.Scripter: TatCustomScripter;
begin
  if Engine <> nil then
    Result := Engine.Scripter
  else
    Result := nil;
end;

procedure TfmLibraryBrowser.SetEngine(const Value: TIDEEngine);
begin
  FEngine := Value;
end;

procedure TfmLibraryBrowser.TreeView1Editing(Sender: TObject; Node: TTreeNode;
  var AllowEdit: Boolean);
begin
  AllowEdit := false;
end;

function TfmLibraryBrowser.VariablesNode(const LibName: string): TTreeNode;
begin
  Result := GetLibSubNode(LibName, 'Variables');
end;

procedure TfmLibraryBrowser.CreateParams(var Params: TCreateParams);
begin
  inherited;
  Params.WndParent := 0; // allows real stay on top. If not used, the window will be hidden by the IDE main window
end;

end.
