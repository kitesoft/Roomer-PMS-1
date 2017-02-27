{********************************************************************}
{                                                                    }
{           Developer Express Visual Component Library               }
{           Express Cross Platform Library classes                   }
{                                                                    }
{           Copyright (c) 2000-2014 Developer Express Inc.           }
{           ALL RIGHTS RESERVED                                      }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSCROSSPLATFORMLIBRARY AND ALL   }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM       }
{   ONLY.                                                            }
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

unit dxGalleryDesigner;

interface

uses
  DesignIntf, Variants,
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, ComCtrls, StdCtrls, ToolWin, ImgList, Menus, ActnList,
  dxCore, cxGraphics, cxClasses, cxDesignWindows, dxMessages, dxGallery;

const
  WM_DELETEDESIGNERNODE = WM_DX + 1;

type
  TfrmGalleryDesigner = class(TcxDesignFormEditor)
    ilButtons: TcxImageList;
    ppmGalleryItems: TPopupMenu;
    ppmiAdd: TMenuItem;
    ppmiDelete: TMenuItem;
    ppmDragDrop: TPopupMenu;
    ppmiCopy: TMenuItem;
    ppmiMove: TMenuItem;
    N1: TMenuItem;
    ppmiGroupVisible: TMenuItem;
    ppmiGroupHeaderVisible: TMenuItem;
    ilGroupState: TcxImageList;
    alMain: TActionList;
    actAddGroup: TAction;
    actRemove: TAction;
    actAddGroupItem: TAction;
    AddGroup1: TMenuItem;
    actMoveNodeUp: TAction;
    actMoveNodeDown: TAction;
    actGroupVisible: TAction;
    actGroupHeaderVisible: TAction;
    tvGalleryItems: TTreeView;
    ToolBar1: TToolBar;
    tbAddGroup: TToolButton;
    tbAddGroupItem: TToolButton;
    tbDelete: TToolButton;
    tbSeparator: TToolButton;
    tbMoveNodeUp: TToolButton;
    tbMoveNodeDown: TToolButton;
    actClose: TAction;
    ilHelper: TcxImageList;
    procedure FormShow(Sender: TObject);
    procedure tvGalleryItemsDragOver(Sender, Source: TObject; X,
      Y: Integer; State: TDragState; var Accept: Boolean);
    procedure tvGalleryItemsDragDrop(Sender, Source: TObject; X,
      Y: Integer);
    procedure tvGalleryItemsChange(Sender: TObject; Node: TTreeNode);
    procedure tvGalleryItemsEdited(Sender: TObject; Node: TTreeNode;
      var S: String);
    procedure ppmiCopyClick(Sender: TObject);
    procedure ppmiMoveClick(Sender: TObject);
    procedure ppmDragDropPopup(Sender: TObject);
    procedure ppmGalleryItemsPopup(Sender: TObject);
    procedure actAddGroupExecute(Sender: TObject);
    procedure actRemoveExecute(Sender: TObject);
    procedure actAddGroupItemExecute(Sender: TObject);
    procedure actMoveNodeUpExecute(Sender: TObject);
    procedure actMoveNodeDownExecute(Sender: TObject);
    procedure actGroupVisibleExecute(Sender: TObject);
    procedure actCloseExecute(Sender: TObject);
  private
    FDeletingNode: TTreeNode;
    FDragDropTargetNode: TTreeNode;
    FGalleryItemsWndProc: TWndMethod;
    FLockSelectionChangedCount: Integer;

    FGallery: IdxGallery;

    function CanModify: Boolean;
    procedure GalleryItemsMenuSetup(ANode: TTreeNode);
    procedure GroupPopupMenuInitialize(ANode: TTreeNode);
    procedure RefreshImages;

    procedure AddGroupNode;
    procedure AddGroupItemNode(ANode: TTreeNode);
    procedure MoveGroupNode(ANode: TTreeNode; MoveUp: Boolean);
    procedure MoveNodeDown(ANode: TTreeNode);
    procedure MoveNodeUp(ANode: TTreeNode);
    procedure MoveGroupItemNode(ANode: TTreeNode; MoveUp: Boolean);
    procedure RemoveNode(ANode: TTreeNode);
    procedure SetGroupNodeGlyph(ANode: TTreeNode);
    procedure UpdateGroupNode(ANode: TTreeNode);
    procedure UpdateGroupItemNode(ANode: TTreeNode);

    // dragdrop
    procedure DoDragDrop(ATargetNode: TTreeNode; DoCopy: Boolean = False);
    procedure GroupItemNodeDragDrop(ASourceNode, ATargetNode: TTreeNode; DoCopy: Boolean);
    procedure GroupNodeDragDrop(ASourceNode, ATargetNode: TTreeNode);

    function AddGalleryGroup(ANode: TTreeNode): TdxGalleryGroup;
    function AddGalleryGroupItem(ANode: TTreeNode; const ADescription: string): TdxGalleryItem;
    function GetGalleryGroup(ANode: TTreeNode): TdxGalleryGroup;
    function GetGalleryItem(ANode: TTreeNode): TdxGalleryItem;
    procedure SynchronizeTreeView;
    function RemoveCorrespondingObject(ANode: TTreeNode): Boolean;
    procedure SetGalleryGroupIndex(ANode: TTreeNode; AIndex: Integer);
    procedure UpdateItemCaption(ANode: TTreeNode; ACaption: string);

    procedure MoveItem(AItem: TdxGalleryItem; ATargetGroup: TdxGalleryGroup; AIndex: Integer);
    function CopyItem(AItem: TdxGalleryItem;
      ATargetGroup: TdxGalleryGroup; AIndex: Integer): TdxGalleryItem;

    // object inspector
    procedure SetDesignerModified;
    procedure SelectCorrespondingObject(ANode: TTreeNode);

    // TreeView wnd proc
    procedure GalleryItemsWndProc(var Message: TMessage);
    procedure RestoreTreeViewWndProc;
    procedure StoreTreeViewWndProc;
    function TreeViewWndProcHandler(ATreeView: TTreeView; var Message: TMessage): Boolean;

    procedure WMDeleteDesignNode(var Message: TMessage); message WM_DELETEDESIGNERNODE;
  protected
    procedure UpdateActions; override;
    procedure UpdateCaption; override;

    procedure SetComponent(AValue: TComponent); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    procedure DoItemDeleted(AItem: TPersistent); override;
    procedure DoItemsModified; override;

    procedure SelectionsChanged(const ASelection: TDesignerSelectionList); override;
  end;

procedure EditGallery(AGalleryOwner: TComponent);

implementation

{$R *.dfm}

uses Math, CommCtrl, cxControls;

const
  dxcGroupLevel = 0;
  dxcGroupItemLevel = 1;

procedure EditGallery(AGalleryOwner: TComponent);
begin
  ShowFormEditorClass(GetObjectDesigner(AGalleryOwner), AGalleryOwner, TfrmGalleryDesigner);
end;

{ TfrmGalleryDesigner }

constructor TfrmGalleryDesigner.Create(AOwner: TComponent);
begin
  inherited;
  StoreTreeViewWndProc;
  AOwner.FreeNotification(Self);
  RefreshImages;
end;

destructor TfrmGalleryDesigner.Destroy;
begin
  RestoreTreeViewWndProc;
  inherited;
end;

procedure TfrmGalleryDesigner.DoItemDeleted(AItem: TPersistent);
var
  I: Integer;
begin
  for I := 0 to tvGalleryItems.Items.Count - 1 do
    if AItem = tvGalleryItems.Items[I].Data then
    begin
      FDeletingNode := tvGalleryItems.Items[I];
      PostMessage(Self.Handle, WM_DELETEDESIGNERNODE, 0, 0);
    end;
end;

procedure TfrmGalleryDesigner.DoItemsModified;
var
  ANode: TTreeNode;
begin
  inherited DoItemsModified;
  ANode := tvGalleryItems.Selected;
  if (ANode = nil) or (ANode = FDeletingNode) then
    Exit;

  if ANode.Level = 0 then
    UpdateGroupNode(ANode)
  else
    UpdateGroupItemNode(ANode);
end;

procedure TfrmGalleryDesigner.SelectionsChanged(const ASelection: TDesignerSelectionList);
var
  I: Integer;
begin
  if FLockSelectionChangedCount > 0 then
    Exit;
  tvGalleryItems.Selected := nil;
  if ASelection.Count > 0 then
    for I := 0 to tvGalleryItems.Items.Count - 1 do
      if tvGalleryItems.Items[I].Data = ASelection.Items[0] then
        tvGalleryItems.Items[I].Selected := True;
end;

procedure TfrmGalleryDesigner.UpdateActions;
var
  ASelectedNode: TTreeNode;
begin
  inherited UpdateActions;
  ASelectedNode := tvGalleryItems.Selected;
  actAddGroup.Enabled := CanModify;
  actAddGroupItem.Enabled := (FGallery.Groups.Count > 0) and CanModify;
  actRemove.Enabled := (ASelectedNode <> nil) and CanModify;
  actMoveNodeUp.Enabled := (ASelectedNode <> nil) and
    ((ASelectedNode.Level = dxcGroupLevel) and (ASelectedNode.AbsoluteIndex > 0) or
    (ASelectedNode.Level = dxcGroupItemLevel) and (ASelectedNode.AbsoluteIndex > 1)) and
    CanModify;
  actMoveNodeDown.Enabled := (ASelectedNode <> nil) and
    not ((ASelectedNode.AbsoluteIndex = tvGalleryItems.Items.Count - 1) or
    (ASelectedNode.Level = 0) and (ASelectedNode.getNextSibling = nil)) and CanModify;
  actGroupVisible.Enabled := CanModify;
  actGroupHeaderVisible.Enabled := CanModify;
end;

procedure TfrmGalleryDesigner.UpdateCaption;
begin
  Caption := cxGetFullComponentName(Component) + ' - Designer';
end;

procedure TfrmGalleryDesigner.SetComponent(AValue: TComponent);
var
  AGalleryOwner: IdxGalleryOwner;
begin
  inherited;
  if AValue <> nil then
  begin
    if not Supports(AValue, IdxGallery, FGallery) then
      if Supports(AValue, IdxGalleryOwner, AGalleryOwner) then
        FGallery := AGalleryOwner.GetGallery
      else
        raise EdxException.Create('Gallery Designer fails: ' + AValue.ClassName);
  end
  else
    FGallery := nil;
end;

function TfrmGalleryDesigner.CanModify: Boolean;
begin
  Result := not Designer.IsSourceReadOnly;
end;

procedure TfrmGalleryDesigner.GalleryItemsMenuSetup(ANode: TTreeNode);
var
  I: Integer;
begin
  if ANode = nil then
    Exit;

  for I := 0 to ppmGalleryItems.Items.Count - 1 do
    ppmGalleryItems.Items[I].Visible := (ppmGalleryItems.Items[I].Tag = 0) or
     (ppmGalleryItems.Items[I].Tag = 1) and (ANode.Level = 0);

  if ANode.Level = 0 then
    GroupPopupMenuInitialize(ANode);
end;

procedure TfrmGalleryDesigner.GroupPopupMenuInitialize(ANode: TTreeNode);
begin
  actGroupVisible.Checked := GetGalleryGroup(ANode).Visible;
  actGroupHeaderVisible.Checked := GetGalleryGroup(ANode).ShowCaption;
end;

procedure TfrmGalleryDesigner.RefreshImages;
begin
  cxTransformImages(ilButtons, ilHelper, clWindow, False);
end;

procedure TfrmGalleryDesigner.AddGroupNode;
var
  AAddedNode: TTreeNode;
begin
  tvGalleryItems.Items.BeginUpdate;

  AAddedNode := tvGalleryItems.Items.Add(nil, 'New Group');
  AAddedNode.Data := AddGalleryGroup(AAddedNode);
  SetGroupNodeGlyph(AAddedNode);
  AAddedNode.Selected := True;

  tvGalleryItems.Items.EndUpdate;

  SetDesignerModified;
end;

procedure TfrmGalleryDesigner.AddGroupItemNode(ANode: TTreeNode);
const
  GroupItemCaption = 'New Item';
var
  AAddedNode: TTreeNode;
begin
  if tvGalleryItems.Items.Count = 0 then
    Exit;
  if ANode = nil then
    ANode := tvGalleryItems.Items[0];

  tvGalleryItems.Items.BeginUpdate;

  if ANode.Level = dxcGroupLevel then
    AAddedNode := tvGalleryItems.Items.AddChild(ANode, GroupItemCaption)
  else
    AAddedNode := tvGalleryItems.Items.Add(ANode, GroupItemCaption);
  AAddedNode.Data := AddGalleryGroupItem(AAddedNode, '');
  AAddedNode.Parent.Expand(False);
  AAddedNode.Selected := True;

  tvGalleryItems.Items.EndUpdate;

  SetDesignerModified;
end;

procedure TfrmGalleryDesigner.MoveGroupNode(ANode: TTreeNode; MoveUp: Boolean);
var
  AIndex: Integer;
begin
  AIndex := ANode.Index + IfThen(MoveUp, - 1, 1);
  if (AIndex >= 0) and (AIndex < FGallery.Groups.Count) then
    SetGalleryGroupIndex(ANode, AIndex);
  SetDesignerModified;
end;

procedure TfrmGalleryDesigner.MoveNodeDown(ANode: TTreeNode);
begin
  if ANode.Level = 0 then
    MoveGroupNode(ANode, False)
  else
    MoveGroupItemNode(ANode, False);
end;

procedure TfrmGalleryDesigner.MoveNodeUp(ANode: TTreeNode);
begin
  if ANode.Level = 0 then
    MoveGroupNode(ANode, True)
  else
    MoveGroupItemNode(ANode, True);
end;

procedure TfrmGalleryDesigner.MoveGroupItemNode(ANode: TTreeNode; MoveUp: Boolean);

type
  TdxGroupChanged = (gcNone, gcIncreased, gcDecreased);

  function CalculateNodePosition(AParentNode: TTreeNode; out ANodeIndex,
    AGroupIndex: Integer): TdxGroupChanged;
  begin
    ANodeIndex := ANode.Index + IfThen(MoveUp, -1, 1);
    AGroupIndex := GetGalleryGroup(AParentNode).Index;
    Result := gcNone;
    if ANodeIndex < 0 then
    begin
      Dec(AGroupIndex);
      Result := gcDecreased;
      ANodeIndex := -1;
    end
    else
      if ANodeIndex > ANode.Parent.Count - 1 then
      begin
        Inc(AGroupIndex);
        Result := gcIncreased;
        ANodeIndex := 0;
      end;
  end;

  function CreateNode(AParentNode: TTreeNode; ANodeIndex: Integer;
    AGroup: TdxGalleryGroup; AGroupChanged: TdxGroupChanged): TTreeNode;
  begin
    if (ANodeIndex = AGroup.Items.Count - 1) and
      not((AGroupChanged = gcIncreased) and (AParentNode.Count = 1)) or
      (AParentNode.Count = 0) then
    begin
      Result := tvGalleryItems.Items.AddChild(AParentNode, ANode.Text);
      AParentNode.Expand(False);
    end
    else
      Result := tvGalleryItems.Items.Insert(
        AParentNode.Item[ANodeIndex + IfThen(MoveUp or (AGroupChanged = gcIncreased),
          0, 1)], ANode.Text);
  end;

var
  ANodeIndex, AGroupIndex: Integer;
  AGroup: TdxGalleryGroup;
  AParentNode, ACreatedNode: TTreeNode;
  AGroupChanged: TdxGroupChanged;
begin
  Inc(FLockSelectionChangedCount);
  try
    AParentNode := ANode.Parent;
    AGroupChanged := CalculateNodePosition(AParentNode, ANodeIndex, AGroupIndex);
    case AGroupChanged of
      gcIncreased: AParentNode := AParentNode.getNextSibling;
      gcDecreased: AParentNode := AParentNode.getPrevSibling;
    end;

    if (AGroupIndex >= 0) and (AGroupIndex < FGallery.Groups.Count) then
    begin
      AGroup := FGallery.Groups[AGroupIndex];
      if ANodeIndex = -1 then
        ANodeIndex := AGroup.Items.Count - 1;

      tvGalleryItems.Items.BeginUpdate;
      try
        ACreatedNode := CreateNode(AParentNode, ANodeIndex, AGroup, AGroupChanged);
        MoveItem(GetGalleryItem(ANode), AGroup, ANodeIndex + IfThen((AGroupChanged = gcDecreased), 1, 0));
        ACreatedNode.Data := ANode.Data;
        ACreatedNode.Selected := True;
        ANode.Free;
      finally
        tvGalleryItems.Items.EndUpdate;
      end;
    end;
  finally
     Dec(FLockSelectionChangedCount);
  end;
  if AGroupChanged <> gcNone then
    SetDesignerModified;
end;

procedure TfrmGalleryDesigner.RemoveNode(ANode: TTreeNode);

  procedure SelectAnotherNode(ANode: TTreeNode);
  var
    AAnotherNode: TTreeNode;
  begin
    AAnotherNode := ANode.getPrevSibling;
    if AAnotherNode = nil then
    begin
      AAnotherNode := ANode.getNextSibling;
      if AAnotherNode = nil then
        AAnotherNode := ANode.Parent;
    end;
    if AAnotherNode <> nil then
      AAnotherNode.Selected := True;
  end;

begin
  if (ANode <> nil) and (ANode <> FDeletingNode) then
  begin
    SelectAnotherNode(ANode);
    RemoveCorrespondingObject(ANode);
    SetDesignerModified;
  end;
end;

procedure TfrmGalleryDesigner.SetGroupNodeGlyph(ANode: TTreeNode);
var
  AGroup: TdxGalleryGroup;
begin
  AGroup := GetGalleryGroup(ANode);
  ANode.StateIndex := 1;

  if AGroup.Visible then
    if not AGroup.ShowCaption then
      ANode.StateIndex := 3
    else
      ANode.StateIndex := 2;
end;

procedure TfrmGalleryDesigner.UpdateGroupNode(ANode: TTreeNode);
begin
  SetGroupNodeGlyph(ANode);
  ANode.Text := GetGalleryGroup(ANode).Caption;
end;

procedure TfrmGalleryDesigner.UpdateGroupItemNode(ANode: TTreeNode);
begin
  ANode.Text := GetGalleryItem(ANode).Caption;
end;

procedure TfrmGalleryDesigner.DoDragDrop(ATargetNode: TTreeNode;
  DoCopy: Boolean = False);
var
  ASourceNode: TTreeNode;
begin
  if ATargetNode <> nil then
  begin
    ASourceNode := tvGalleryItems.Selected;
    if ATargetNode <> ASourceNode then
    begin
      if ASourceNode.Level = dxcGroupItemLevel then
        GroupItemNodeDragDrop(ASourceNode, ATargetNode, DoCopy)
      else
        GroupNodeDragDrop(ASourceNode, ATargetNode);
    end;
  end;
end;

procedure TfrmGalleryDesigner.GroupItemNodeDragDrop(ASourceNode,
  ATargetNode: TTreeNode; DoCopy: Boolean);

  procedure ChangeGalleryItem(ACreatedNode: TTreeNode; AGroup: TdxGalleryGroup; AIndex: Integer;
    DoCopy: Boolean);
  begin
    if DoCopy then
      ACreatedNode.Data := CopyItem(
        GetGalleryItem(ASourceNode), AGroup, AIndex)
    else
    begin
      MoveItem(GetGalleryItem(ASourceNode), AGroup, AIndex);
      ACreatedNode.Data := ASourceNode.Data;
    end;
  end;

  function IsDragDropDown: Boolean;
  begin
    Result := (ATargetNode.Level = dxcGroupItemLevel) and
      ((ASourceNode.Parent.Index < ATargetNode.Parent.Index) or
      (ASourceNode.Parent.Index = ATargetNode.Parent.Index) and
      (ASourceNode.Index < ATargetNode.Index));
  end;

var
  ACreatedNode, ASibling: TTreeNode;
  AIndex: Integer;
  AGroup: TdxGalleryGroup;
begin
  tvGalleryItems.Items.BeginUpdate;
  try
    if ATargetNode.Level = dxcGroupItemLevel then
    begin
      AIndex := ATargetNode.Index;
      ASibling := nil;
      if IsDragDropDown then
      begin
        ASibling := ATargetNode.getNextSibling;
        if ASibling <> nil then
        begin
          ATargetNode := ASibling;
          Inc(AIndex);
        end;
      end;
      if IsDragDropDown and (ASibling = nil) then
        ACreatedNode := tvGalleryItems.Items.AddChild(ATargetNode.Parent, ASourceNode.Text)
      else
        ACreatedNode := tvGalleryItems.Items.Insert(ATargetNode, ASourceNode.Text);
      AGroup := GetGalleryGroup(ATargetNode.Parent);
    end
    else
    begin
      ACreatedNode := tvGalleryItems.Items.AddChild(ATargetNode, ASourceNode.Text);
      ATargetNode.Expand(False);
      AIndex := ATargetNode.Count - 1 -
        IfThen((ASourceNode.Parent = ATargetNode) and not DoCopy, 1, 0);
      AGroup := GetGalleryGroup(ATargetNode);
    end;
    ChangeGalleryItem(ACreatedNode, AGroup, AIndex, DoCopy);
    if not DoCopy then
      ASourceNode.Free;
  finally
    tvGalleryItems.Items.EndUpdate;
  end;

  SetDesignerModified;
  ACreatedNode.Selected := True;
end;

procedure TfrmGalleryDesigner.GroupNodeDragDrop(ASourceNode, ATargetNode: TTreeNode);
var
  ATargetNodeIndex: Integer;
begin
  ATargetNodeIndex := GetGalleryGroup(ATargetNode).Index;
  SetGalleryGroupIndex(ASourceNode, ATargetNodeIndex);
end;

function TfrmGalleryDesigner.AddGalleryGroup(ANode: TTreeNode): TdxGalleryGroup;
begin
  Result := FGallery.Groups.Add;
  Result.Caption := ANode.Text;
end;

function TfrmGalleryDesigner.AddGalleryGroupItem(ANode: TTreeNode;
  const ADescription: string): TdxGalleryItem;
begin
  Result := GetGalleryGroup(ANode.Parent).Items.Add;
  Result.Caption := ANode.Text;
  Result.Description := ADescription;
end;

function TfrmGalleryDesigner.GetGalleryGroup(ANode: TTreeNode): TdxGalleryGroup;
begin
  Result := TObject(ANode.Data) as TdxGalleryGroup;
end;

function TfrmGalleryDesigner.GetGalleryItem(ANode: TTreeNode): TdxGalleryItem;
begin
  Result := TObject(ANode.Data) as TdxGalleryItem;
end;

procedure TfrmGalleryDesigner.SynchronizeTreeView;

  procedure ReadGalleryGroupItems;
  var
    I, J: Integer;
    ANode: TTreeNode;
  begin
    tvGalleryItems.Items.Clear;
    for I := 0 to FGallery.Groups.Count - 1 do
    begin
      ANode := tvGalleryItems.Items.AddObject(nil,
        FGallery.Groups[I].Caption, FGallery.Groups[I]);
      SetGroupNodeGlyph(ANode);
      for J := 0 to FGallery.Groups[I].Items.Count - 1 do
        tvGalleryItems.Items.AddChildObject(ANode,
          FGallery.Groups[I].Items[J].Caption, FGallery.Groups[I].Items[J]);
    end;
  end;

begin
  tvGalleryItems.Items.BeginUpdate;
  try
    ReadGalleryGroupItems;
    tvGalleryItems.FullExpand;
  finally
    tvGalleryItems.Items.EndUpdate;
  end;
end;

function TfrmGalleryDesigner.RemoveCorrespondingObject(ANode: TTreeNode): Boolean;
begin
  Result := ANode.Data <> nil;
  if Result then
    TObject(ANode.Data).Free;
end;

procedure TfrmGalleryDesigner.SetGalleryGroupIndex(ANode: TTreeNode; AIndex: Integer);

  procedure SelectGroup(AIndex: Integer);
  var
    I: Integer;
  begin
    ANode := tvGalleryItems.Items[0];
    for I := 1 to AIndex do
      ANode := ANode.GetNextSibling;
    ANode.Selected := True;
  end;

begin
  GetGalleryGroup(ANode).Index := AIndex;

  SynchronizeTreeView;
  SelectGroup(AIndex);
end;

procedure TfrmGalleryDesigner.UpdateItemCaption(ANode: TTreeNode; ACaption: string);
begin
  if ANode.Level = dxcGroupLevel then
    GetGalleryGroup(ANode).Caption := ACaption
  else
    GetGalleryItem(ANode).Caption := ACaption;
end;

procedure TfrmGalleryDesigner.MoveItem(AItem: TdxGalleryItem;
  ATargetGroup: TdxGalleryGroup; AIndex: Integer);
begin
  AItem.Collection := ATargetGroup.Items;
  AItem.Index := AIndex;
end;

function TfrmGalleryDesigner.CopyItem(AItem: TdxGalleryItem;
  ATargetGroup: TdxGalleryGroup; AIndex: Integer): TdxGalleryItem;
begin
  Result := ATargetGroup.Items.Insert(AIndex) as TdxGalleryItem;
  Result.Assign(AItem);
end;

procedure TfrmGalleryDesigner.SetDesignerModified;
begin
  Designer.Modified;
end;

procedure TfrmGalleryDesigner.SelectCorrespondingObject(ANode: TTreeNode);
var
  ASelections: TList;
begin
  if ANode <> nil then
  begin
    ASelections := TList.Create;
    try
      if ANode.Level = dxcGroupLevel then
        ASelections.Add(GetGalleryGroup(ANode))
      else
        ASelections.Add(GetGalleryItem(ANode));
      SetSelectionList(ASelections);
    finally
      ASelections.Free;
    end;
  end;
end;

procedure TfrmGalleryDesigner.GalleryItemsWndProc(var Message: TMessage);
begin
  if not TreeViewWndProcHandler(tvGalleryItems, Message) then
    FGalleryItemsWndProc(Message);
end;

procedure TfrmGalleryDesigner.RestoreTreeViewWndProc;
begin
  if Assigned(FGalleryItemsWndProc) then
    tvGalleryItems.WindowProc := FGalleryItemsWndProc;
  FGalleryItemsWndProc := nil;
end;

procedure TfrmGalleryDesigner.StoreTreeViewWndProc;
begin
  FGalleryItemsWndProc := tvGalleryItems.WindowProc;
  tvGalleryItems.WindowProc := GalleryItemsWndProc;
end;

function TfrmGalleryDesigner.TreeViewWndProcHandler(
  ATreeView: TTreeView; var Message: TMessage): Boolean;

  procedure ShowContextMenu;
  var
    AHitTest: THitTests;
  begin
    AHitTest := ATreeView.GetHitTestInfoAt(Message.LParamLo, Message.LParamHi);
    if (htOnItem in AHitTest) then
      ATreeView.Perform(WM_CONTEXTMENU, ATreeView.Handle, dxPointToLParam(GetMouseCursorPos));
  end;

var
  ANode: TTreeNode;
  AShift: TShiftState;
begin
  Result := False;
  case Message.Msg of
    CN_NOTIFY:
      case TWMNotify(Message).NMHdr^.code of
        NM_RCLICK:
          begin
            ShowContextMenu;
            Message.Result := 1;
            Result := True;
          end;
      end;
    WM_KEYDOWN:
      if Message.WParam = VK_ESCAPE then
        CancelDrag;
    WM_RBUTTONDOWN:
      begin
        if ATreeView.Selected <> nil then
          ATreeView.Selected.EndEdit(False);
        ANode := ATreeView.GetNodeAt(Message.LParamLo, Message.LParamHi);
        if ANode <> nil then
        begin
          ANode.Focused := True;
          AShift := KeysToShiftState(Message.WParam);
          if not ANode.Selected then
          begin
            if [ssShift, ssCtrl] * AShift <> [] then
              AShift := [];
            BeginUpdate;
            try
              ATreeView.Select(ANode, AShift);
            finally
              CancelUpdate;
            end;
            SelectCorrespondingObject(ANode);
          end;
          Message.Result := 1;
          Result := True;
        end;
      end;
  end;
end;

procedure TfrmGalleryDesigner.WMDeleteDesignNode(var Message: TMessage);
begin
  if FDeletingNode <> nil then
  begin
    tvGalleryItems.Items.Delete(FDeletingNode);
    FDeletingNode := nil;
  end;
end;

procedure TfrmGalleryDesigner.FormShow(Sender: TObject);
begin
  SynchronizeTreeView;
  tvGalleryItems.ReadOnly := not CanModify;
end;

procedure TfrmGalleryDesigner.tvGalleryItemsDragOver(Sender,
  Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean);
var
  ASelectedNode, ATargetNode: TTreeNode;
begin
  ASelectedNode := tvGalleryItems.Selected;
  ATargetNode := tvGalleryItems.GetNodeAt(X, Y);
  Accept := (Sender = tvGalleryItems) and
    (ASelectedNode <> nil) and (ATargetNode <> nil) and
    ((ASelectedNode.Level = dxcGroupItemLevel) or
    (ATargetNode.Level = dxcGroupLevel)) and CanModify;
end;

procedure TfrmGalleryDesigner.tvGalleryItemsDragDrop(Sender,
  Source: TObject; X, Y: Integer);
begin
  FDragDropTargetNode := tvGalleryItems.GetNodeAt(X, Y);
  DoDragDrop(FDragDropTargetNode, (GetKeyState(VK_CONTROL) and $10000000) <> 0);
end;

procedure TfrmGalleryDesigner.tvGalleryItemsChange(Sender: TObject;
  Node: TTreeNode);
begin
  SelectCorrespondingObject(tvGalleryItems.Selected);
end;

procedure TfrmGalleryDesigner.tvGalleryItemsEdited(Sender: TObject;
  Node: TTreeNode; var S: String);
begin
  UpdateItemCaption(Node, S);
  SetDesignerModified;
end;

procedure TfrmGalleryDesigner.ppmiCopyClick(Sender: TObject);
begin
  DoDragDrop(FDragDropTargetNode, True);
end;

procedure TfrmGalleryDesigner.ppmiMoveClick(Sender: TObject);
begin
  DoDragDrop(FDragDropTargetNode);
end;

procedure TfrmGalleryDesigner.ppmDragDropPopup(Sender: TObject);
begin
  ppmiCopy.Enabled := (tvGalleryItems.Selected <> nil) and
    (tvGalleryItems.Selected.Level = dxcGroupItemLevel);
end;

procedure TfrmGalleryDesigner.ppmGalleryItemsPopup(Sender: TObject);
begin
  GalleryItemsMenuSetup(tvGalleryItems.Selected);
end;

procedure TfrmGalleryDesigner.actAddGroupExecute(Sender: TObject);
begin
  AddGroupNode;
end;

procedure TfrmGalleryDesigner.actRemoveExecute(Sender: TObject);
begin
  RemoveNode(tvGalleryItems.Selected);
end;

procedure TfrmGalleryDesigner.actAddGroupItemExecute(
  Sender: TObject);
begin
  AddGroupItemNode(tvGalleryItems.Selected);
end;

procedure TfrmGalleryDesigner.actMoveNodeUpExecute(Sender: TObject);
begin
  MoveNodeUp(tvGalleryItems.Selected);
end;

procedure TfrmGalleryDesigner.actMoveNodeDownExecute(
  Sender: TObject);
begin
  MoveNodeDown(tvGalleryItems.Selected);
end;

procedure TfrmGalleryDesigner.actGroupVisibleExecute(
  Sender: TObject);
var
  AGroup: TdxGalleryGroup;
begin
  AGroup := GetGalleryGroup(tvGalleryItems.Selected);
  AGroup.Visible := actGroupVisible.Checked;
  AGroup.ShowCaption := actGroupHeaderVisible.Checked;
  SetDesignerModified;
end;

procedure TfrmGalleryDesigner.actCloseExecute(Sender: TObject);
begin
  Close;
end;

end.

