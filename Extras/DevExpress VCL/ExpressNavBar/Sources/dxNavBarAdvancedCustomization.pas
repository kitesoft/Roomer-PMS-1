{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       ExpressNavBar                                               }
{                                                                   }
{       Copyright (c) 2002-2014 Developer Express Inc.              }
{       ALL RIGHTS RESERVED                                         }
{                                                                   }
{   The entire contents of this file is protected by U.S. and       }
{   International Copyright Laws. Unauthorized reproduction,        }
{   reverse-engineering, and distribution of all or any portion of  }
{   the code contained in this file is strictly prohibited and may  }
{   result in severe civil and criminal penalties and will be       }
{   prosecuted to the maximum extent possible under the law.        }
{                                                                   }
{   RESTRICTIONS                                                    }
{                                                                   }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES           }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE    }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS   }
{   LICENSED TO DISTRIBUTE THE EXPRESSNAVBAR AND ALL ACCOMPANYING   }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.             }
{                                                                   }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED      }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE        }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE       }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT  }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                      }
{                                                                   }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON       }
{   ADDITIONAL RESTRICTIONS.                                        }
{                                                                   }
{*******************************************************************}

unit dxNavBarAdvancedCustomization;

{$I cxVer.inc}

interface

uses
  Types, Windows, SysUtils, Classes, Controls, dxNavBar, cxControls, cxListBox,
  cxGraphics, cxLookAndFeels, cxLookAndFeelPainters, cxContainer, cxEdit,
  ComCtrls, cxTreeView, cxGroupBox, cxSplitter, dxNavBarCollns, ImgList,
  ActnList, Menus, StdCtrls, cxButtons, Messages;

type
  TdxNavBarAdvancedCustomizationForm = class(TdxNavBarCustomCustomizationForm)
    cxGroupBox1: TcxGroupBox;
    gbGroups: TcxGroupBox;
    gbItems: TcxGroupBox;
    cxSplitter1: TcxSplitter;
    tvGroups: TcxTreeView;
    tvItems: TcxTreeView;
    ilItems: TcxImageList;
    alMain: TActionList;
    acAddGroup: TAction;
    acDelete: TAction;
    acExpandAll: TAction;
    acCollapseAll: TAction;
    ilActions: TcxImageList;
    pmMain: TPopupMenu;
    acAddGroup1: TMenuItem;
    acDelete1: TMenuItem;
    acExpandAll1: TMenuItem;
    acCollapseAll1: TMenuItem;
    N1: TMenuItem;
    gbToolBar: TcxGroupBox;
    gbGroupsIndent: TcxGroupBox;
    gbItemsIndent: TcxGroupBox;
    btnExpandAll: TcxButton;
    btnCollapseAll: TcxButton;
    btnAddGroup: TcxButton;
    btnDelete: TcxButton;
    procedure tvStartDrag(Sender: TObject;
      var DragObject: TDragObject);
    procedure tvEndDrag(Sender, Target: TObject; X, Y: Integer);
    procedure tvDragOver(Sender, Source: TObject; X, Y: Integer;
      State: TDragState; var Accept: Boolean);
    procedure tvGroupsEditing(Sender: TObject; Node: TTreeNode;
      var AllowEdit: Boolean);
    procedure tvEdited(Sender: TObject; Node: TTreeNode;
      var S: String);
    procedure tvGetImageIndex(Sender: TObject; Node: TTreeNode);
    procedure acExpandAllExecute(Sender: TObject);
    procedure acCollapseAllExecute(Sender: TObject);
    procedure acDeleteExecute(Sender: TObject);
    procedure tvGroupsChange(Sender: TObject; Node: TTreeNode);
    procedure acAddGroupExecute(Sender: TObject);
    procedure FormShortCut(var Msg: TWMKey; var Handled: Boolean);
  private
    function CanDropItem(ANode: TTreeNode): Boolean;
    procedure PopulateGroups;
    procedure PopulateItems;
    procedure TreeViewWndProcHandler(ATreeView: TTreeView; var Message: TMessage; var ADone: Boolean);
    procedure UpdateButtonsState;
  protected
    procedure DoCreateControls; override;
    procedure DoRefreshItems; override;
    procedure Localize; override;

    function CanProcessDropItem(Target: TObject; X, Y: Integer): Boolean; override;
    procedure DoProcessDropItem(Target: TObject; X, Y: Integer); override;
  public
    constructor Create(AOwner: TComponent); override;
  end;

implementation

{$R *.dfm}

uses
  Forms, Graphics, cxClasses, dxNavBarConsts;

const
  dxNavBarCustomizationMinHeight = 350;
  dxNavBarCustomizationMinWidth  = 300;

type
  TdxNavBarCustomItemAccess = class(TdxNavBarCustomItem);

{ TdxNavBarCustomizationForm }

constructor TdxNavBarAdvancedCustomizationForm.Create(AOwner: TComponent);
begin
  inherited;

  Constraints.MinWidth := dxNavBarCustomizationMinWidth;
  Constraints.MinHeight := dxNavBarCustomizationMinHeight;

  tvGroups.OnInnerTreeViewWndProc := TreeViewWndProcHandler;
  tvItems.OnInnerTreeViewWndProc := TreeViewWndProcHandler;
end;

procedure TdxNavBarAdvancedCustomizationForm.DoCreateControls;
begin
  inherited;
  if not IsXPManifestEnabled then
    cxTransformImages(ilItems, clWindow);
  PopulateItems;
end;

procedure TdxNavBarAdvancedCustomizationForm.DoRefreshItems;
begin
  inherited;
  PopulateGroups;
  UpdateButtonsState;
end;

procedure TdxNavBarAdvancedCustomizationForm.Localize;
begin
  Caption := cxGetResourceString(@sdxNavBarCustomizationCaption);
  gbGroups.Caption := cxGetResourceString(@sdxNavBarNewGroupsCaption);
  gbItems.Caption := cxGetResourceString(@sdxNavBarNewItemsCaption);
  acAddGroup.Caption := cxGetResourceString(@sdxNavBarAddGroup);
  acAddGroup.Hint := StripHotKey(acAddGroup.Caption);
  acDelete.Caption := cxGetResourceString(@sdxNavBarDelete);
  acDelete.Hint := StripHotKey(acDelete.Caption);
  acExpandAll.Caption := cxGetResourceString(@sdxNavBarExpandAll);
  acExpandAll.Hint := StripHotKey(acExpandAll.Caption);
  acCollapseAll.Caption := cxGetResourceString(@sdxNavBarCollapseAll);
  acCollapseAll.Hint := StripHotKey(acCollapseAll.Caption);
end;

function TdxNavBarAdvancedCustomizationForm.CanProcessDropItem(Target: TObject; X, Y: Integer): Boolean;
begin
  Result := (Target = tvItems.InnerTreeView) or (Target = tvGroups.InnerTreeView);
end;

procedure TdxNavBarAdvancedCustomizationForm.DoProcessDropItem(Target: TObject; X, Y: Integer);
var
  ANode: TTreeNode;
  AGroup: TdxNavBarGroup;
  AIndex: Integer;
begin
  inherited;
  BeginUpdate;
  try
    if Target = tvItems.InnerTreeView then
    begin
      if dxNavBarDragObject.SourceLink <> nil then
        dxNavBarDragObject.SourceLink.Group.RemoveLink(dxNavBarDragObject.SourceLink.Index);
    end
    else
    begin
      ANode := tvGroups.GetNodeAt(X, Y);
      if TObject(ANode.Data) is TdxNavBarItemLink then
        with TdxNavBarItemLink(ANode.Data) do
        begin
          AGroup := Group;
          AIndex := Index;
        end
      else
      begin
        AGroup := TdxNavBarGroup(ANode.Data);
        AIndex := AGroup.LinkCount;
      end;
      if dxNavBarDragObject.SourceGroup <> nil then
        dxNavBarDragObject.SourceGroup.Index := AGroup.Index
      else
        if dxNavBarDragObject.SourceItem <> nil then
          CreateLink(dxNavBarDragObject.SourceItem, AGroup, AIndex)
        else
          if dxNavBarDragObject.SourceLink <> nil then
            MoveLink(dxNavBarDragObject.SourceLink, AGroup, AIndex);
    end;
  finally
    EndUpdate;
  end;
end;

function TdxNavBarAdvancedCustomizationForm.CanDropItem(ANode: TTreeNode): Boolean;
begin
  Result := (ANode.Data <> dxNavBarDragObject.SourceGroup) and
    (ANode.Data <> dxNavBarDragObject.SourceLink);
  if Result and (dxNavBarDragObject.SourceGroup <> nil) then
    Result := TObject(ANode.Data) is TdxNavBarGroup;
end;

procedure TdxNavBarAdvancedCustomizationForm.PopulateGroups;
var
  I: Integer;
  J: Integer;
  ANode: TTreeNode;
  ALink: TdxNavBarItemLink;
  AExpandedList: TList;
  ASelectedItem: TObject;
begin
  AExpandedList := TList.Create;
  try
    for I := 0 to tvGroups.Items.Count - 1 do
      if tvGroups.Items[I].Expanded then
        AExpandedList.Add(tvGroups.Items[I].Data);
    tvGroups.Items.BeginUpdate;
    try
      if tvGroups.Selected <> nil then
        ASelectedItem := TObject(tvGroups.Selected.Data)
      else
        ASelectedItem := nil;
      tvGroups.Items.Clear;
      for I := 0 to NavBar.Groups.Count - 1 do
      begin
        ANode := tvGroups.Items.AddObject(nil, NavBar.Groups[I].Caption, NavBar.Groups[I]);
        ANode.Selected := ANode.Data = ASelectedItem;
        for J := 0 to NavBar.Groups[I].LinkCount - 1 do
        begin
          ALink := NavBar.Groups[I].Links[J];
          if ALink.Item <> nil then
            tvGroups.Items.AddChildObject(ANode, ALink.Item.Caption, ALink).Selected := ALink = ASelectedItem;
        end;
        if AExpandedList.IndexOf(NavBar.Groups[I]) <> -1 then
          ANode.Expand(False);
      end;
    finally
      tvGroups.Items.EndUpdate;
    end;
  finally
    AExpandedList.Free;
  end;
end;

procedure TdxNavBarAdvancedCustomizationForm.PopulateItems;
var
  I: Integer;
begin
  tvItems.Items.BeginUpdate;
  try
    tvItems.Items.Clear;
    for I := 0 to NavBar.Items.Count - 1 do
      tvItems.Items.AddObject(nil, NavBar.Items[I].Caption, NavBar.Items[I]);
  finally
    tvItems.Items.EndUpdate;
  end;
end;

procedure TdxNavBarAdvancedCustomizationForm.TreeViewWndProcHandler(ATreeView: TTreeView;
  var Message: TMessage; var ADone: Boolean);
begin
  ADone := CustomizationTreeViewWndProcHandler(ATreeView, Message);
end;

procedure TdxNavBarAdvancedCustomizationForm.UpdateButtonsState;
begin
  acDelete.Enabled := tvGroups.Selected <> nil;
end;

procedure TdxNavBarAdvancedCustomizationForm.tvStartDrag(Sender: TObject;
  var DragObject: TDragObject);
var
  ATreeView: TcxTreeView;
  ASelected: TObject;
begin
  ATreeView := Sender as TcxTreeView;
  if (ATreeView.Selected <> nil) then
  begin
    ASelected := TObject(ATreeView.Selected.Data);
    if ASelected is TdxNavBarItem then
      dxNavBarDragObject := TdxNavBarDragObject.Create(NavBar, DragObject, nil, nil,
        TdxNavBarItem(ASelected))
    else
      if ASelected is TdxNavBarGroup then
        dxNavBarDragObject := TdxNavBarDragObject.Create(NavBar, DragObject,
          TdxNavBarGroup(ASelected), nil, nil)
      else
        dxNavBarDragObject := TdxNavBarDragObject.Create(NavBar, DragObject, nil,
          TdxNavBarItemLink(ASelected), nil);
  end;
end;

procedure TdxNavBarAdvancedCustomizationForm.tvEndDrag(Sender,
  Target: TObject; X, Y: Integer);
begin
  ProcessDropItem(Target, X, Y);
  FreeAndNil(dxNavBarDragObject);
end;

procedure TdxNavBarAdvancedCustomizationForm.tvDragOver(Sender,
  Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean);
var
  ANode: TTreeNode;
begin
  Accept := (dxNavBarDragObject <> nil);
  if Accept then
  begin
    if Sender = tvItems then
      Accept := (dxNavBarDragObject.SourceGroup = nil) and (dxNavBarDragObject.SourceItem = nil)
    else
    begin
      ANode := TcxTreeView(Sender).GetNodeAt(X, Y);
      Accept := (ANode <> nil) and CanDropItem(ANode);
    end;
  end;
end;

procedure TdxNavBarAdvancedCustomizationForm.tvGroupsEditing(Sender: TObject;
  Node: TTreeNode; var AllowEdit: Boolean);
begin
  AllowEdit := not (TObject(Node.Data) is TdxNavBarItemLink);
end;

procedure TdxNavBarAdvancedCustomizationForm.tvEdited(Sender: TObject;
  Node: TTreeNode; var S: String);
begin
  BeginUpdate;
  try
    TdxNavBarCustomItemAccess(Node.Data).Caption := S;
  finally
    CancelUpdate;
    if Sender = tvItems.InnerTreeView then
      PopulateGroups;
  end;
end;

procedure TdxNavBarAdvancedCustomizationForm.tvGetImageIndex(Sender: TObject;
  Node: TTreeNode);
var
  AItem: TObject;
begin
  AItem := TObject(Node.Data);
  if AItem is TdxNavBarGroup then
    Node.ImageIndex := 0
  else
    if AItem is TdxNavBarItem then
      Node.ImageIndex := 1
    else
      if AItem is TdxNavBarItemLink then
        Node.ImageIndex := 2;
  Node.SelectedIndex := Node.ImageIndex;
end;

procedure TdxNavBarAdvancedCustomizationForm.acExpandAllExecute(Sender: TObject);
begin
  tvGroups.FullExpand;
end;

procedure TdxNavBarAdvancedCustomizationForm.acCollapseAllExecute(Sender: TObject);
begin
  tvGroups.FullCollapse;
end;

procedure TdxNavBarAdvancedCustomizationForm.acDeleteExecute(Sender: TObject);
var
  AItem: TObject;
  ANode: TTreeNode;
begin  
  if tvGroups.Focused and not tvGroups.IsEditing then
  begin
    AItem := TObject(tvGroups.Selected.Data);
    ANode := tvGroups.FindNextToSelect;
    if ANode <> nil then
      ANode.Selected := True;
    AItem.Free;
  end;
end;

procedure TdxNavBarAdvancedCustomizationForm.tvGroupsChange(Sender: TObject;
  Node: TTreeNode);
begin
  UpdateButtonsState;
end;

procedure TdxNavBarAdvancedCustomizationForm.acAddGroupExecute(Sender: TObject);
begin
  NavBar.Groups.Add.Caption := cxGetResourceString(@sdxNavBarNewGroupCaption);
end;

procedure TdxNavBarAdvancedCustomizationForm.FormShortCut(var Msg: TWMKey;
  var Handled: Boolean);
begin
  Handled := tvGroups.Focused and not tvGroups.IsEditing and (Msg.CharCode in [VK_DELETE, VK_INSERT]);
  if Handled then
    case Msg.CharCode of
      VK_DELETE: acDeleteExecute(nil);
      VK_INSERT: acAddGroupExecute(nil);
    end;
end;

initialization
  dxNavBarRegisterCustomizationFormClass(TdxNavBarAdvancedCustomizationForm);

finalization
  dxNavBarUnregisterCustomizationFormClass(TdxNavBarAdvancedCustomizationForm);

end.
