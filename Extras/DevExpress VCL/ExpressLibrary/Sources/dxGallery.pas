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

unit dxGallery;

{$I cxVer.inc}

interface

uses
  Classes, Graphics, SysUtils, ImgList, 
  dxCoreClasses, dxCore, cxClasses, cxGraphics;

type
  TdxGalleryItem = class;
  TdxGalleryItemClass = class of TdxGalleryItem;
  TdxGalleryItems = class;
  TdxGalleryItemsClass = class of TdxGalleryItems;
  TdxGalleryGroup = class;
  TdxGalleryGroupClass = class of TdxGalleryGroup;
  TdxGalleryGroups = class;
  TdxGalleryGroupsClass = class of TdxGalleryGroups;

  TdxGalleryItemEvent = procedure(Sender: TObject; AItem: TdxGalleryItem) of object;
  TdxGalleryItemCheckMode = (icmNone, icmSingleCheck, icmSingleRadio, icmMultiple{,
    icmSingleCheckInGroup, icmSingleRadioInGroup, icmMultipleInGroup});
  TdxGalleryChangeType = (gctLight, gctHard);
  TdxGalleryChangeEvent = procedure(Sender: TObject; AChangeType: TdxGalleryChangeType) of object;

  { IdxGallery }

  IdxGallery = interface
  ['{418FD781-56A7-4EA6-8720-1D0D479EBC2E}']
    function GetItemCheckMode: TdxGalleryItemCheckMode;
    procedure SetItemCheckMode(AValue: TdxGalleryItemCheckMode);
    function GetGroups: TdxGalleryGroups;
    procedure SetGroups(AValue: TdxGalleryGroups);
    function GetOnItemClick: TdxGalleryItemEvent;
    procedure SetOnItemClick(AValue: TdxGalleryItemEvent);

    function GetInstance: TObject;
    function GetParentComponent: TComponent;

    // Check operations
    procedure ClickItem(AItem: TdxGalleryItem);
    function GetCheckedItem: TdxGalleryItem;
    procedure GetCheckedItems(AList: TList);
    procedure UncheckAll;

    property ItemCheckMode: TdxGalleryItemCheckMode read GetItemCheckMode write SetItemCheckMode;
    property Groups: TdxGalleryGroups read GetGroups write SetGroups;
    property OnItemClick: TdxGalleryItemEvent read GetOnItemClick write SetOnItemClick;
  end;

  { IdxGalleryOwner }

  IdxGalleryOwner = interface
  ['{9E2F64DD-D370-4B24-8FF3-7E4FE08A15F1}']
    function GetGallery: IdxGallery;
  end;

  { TdxGalleryItem }

  TdxGalleryItem = class(TcxComponentCollectionItem)
  private
    FCaption: string;
    FChecked: Boolean;
    FDescription: string;
    FEnabled: Boolean;
    FGlyph: TBitmap;
    FHint: string;
    FImageIndex: TcxImageIndex;

    procedure GlyphChangeHandler(Sender: TObject);

    procedure SetCaption(const AValue: string);
    procedure SetChecked(AValue: Boolean);
    procedure SetDescription(const AValue: string);
    procedure SetEnabled(AValue: Boolean);
    procedure SetGlyph(AValue: TBitmap);
    procedure SetImageIndex(Value: TcxImageIndex);
  protected
    function GetCollectionFromParent(AParent: TComponent): TcxComponentCollection; override;
    function GetGallery: IdxGallery; virtual;
    function GetGroup: TdxGalleryGroup;

    property Gallery: IdxGallery read GetGallery;
    property Group: TdxGalleryGroup read GetGroup;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    procedure Assign(Source: TPersistent); override;

    property Caption: string read FCaption write SetCaption;
    property Checked: Boolean read FChecked write SetChecked default False;
    property Description: string read FDescription write SetDescription;
    property Enabled: Boolean read FEnabled write SetEnabled default True;
    property Glyph: TBitmap read FGlyph write SetGlyph;
    property Hint: string read FHint write FHint;
    property ImageIndex: TcxImageIndex read FImageIndex write SetImageIndex default -1;
  end;

  { TdxGalleryItems }

  TdxGalleryItems = class(TcxComponentCollection)
  private
    function GetItem(AIndex: Integer): TdxGalleryItem;
    procedure SetItem(AIndex: Integer; AValue: TdxGalleryItem);
  protected
    function GetItemPrefixName: string; override;
  public
    function Add: TdxGalleryItem;
    property Items[AIndex: Integer]: TdxGalleryItem read GetItem write SetItem; default;
  end;

  { TdxGalleryGroupHeader }

  TdxGalleryGroupHeader = class(TcxOwnedPersistent)
  private
    FAlignment: TAlignment;
    FCaption: string;
    FVisible: Boolean;

    FOnChange: TNotifyEvent;

    procedure SetAlignment(AValue: TAlignment);
    procedure SetCaption(const AValue: string);
    procedure SetVisible(AValue: Boolean);
  protected
    procedure DoAssign(Source: TPersistent); override;
    procedure Changed;

    property Alignment: TAlignment read FAlignment write SetAlignment;
    property Caption: string read FCaption write SetCaption;
    property Visible: Boolean read FVisible write SetVisible;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  public
    constructor Create(AOwner: TPersistent); override;
  end;

  { TdxCustomGalleryGroup }

  TdxGalleryGroup = class(TcxComponentCollectionItem)
  private
    FHeader: TdxGalleryGroupHeader;
    FItems: TdxGalleryItems;
    FVisible: Boolean;

    function GetCaption: string;
    function GetItemCount: Integer;
    function GetShowCaption: Boolean;
    procedure SetCaption(const AValue: string);
    procedure SetItems(AValue: TdxGalleryItems);
    procedure SetShowCaption(AValue: Boolean);
    procedure SetVisible(AValue: Boolean);

    procedure ItemsChangeHandler(Sender: TObject; AItem: TcxComponentCollectionItem; AAction: TcxComponentCollectionNotification);
    procedure HeaderChangeHandler(ASender: TObject);
  protected
    function GetCollectionFromParent(AParent: TComponent): TcxComponentCollection; override;
    function GetGallery: IdxGallery; virtual;
    function GetGalleryItemClass: TdxGalleryItemClass; virtual;
    function GetGalleryItemsClass: TdxGalleryItemsClass; virtual;

    property Gallery: IdxGallery read GetGallery;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    procedure Assign(Source: TPersistent); override;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;

    property Caption: string read GetCaption write SetCaption;
    property ShowCaption: Boolean read GetShowCaption write SetShowCaption;
    property Visible: Boolean read FVisible write SetVisible;
    property Items: TdxGalleryItems read FItems write SetItems;
    property ItemCount: Integer read GetItemCount;
  end;

  { TdxGalleryGroups }

  TdxGalleryGroups = class(TcxComponentCollection)
  private
    function GetGroup(AIndex: Integer): TdxGalleryGroup;
    procedure SetGroup(AIndex: Integer; AValue: TdxGalleryGroup);
  protected
    function GetItemPrefixName: string; override;
  public
    function Add: TdxGalleryGroup;
    function FindByCaption(const ACaption: string; out AGroup: TdxGalleryGroup): Boolean;
    //
    property Groups[AIndex: Integer]: TdxGalleryGroup read GetGroup write SetGroup; default;
  end;

  { TdxCustomGallery }

  TdxCustomGallery = class(TcxOwnedInterfacedPersistent, IdxGallery)
  private
    FGroups: TdxGalleryGroups;
    FOnChange: TdxGalleryChangeEvent;
    FOnItemClick: TdxGalleryItemEvent;
    FItemCheckMode: TdxGalleryItemCheckMode;

    function GetItemCheckMode: TdxGalleryItemCheckMode;
    procedure SetItemCheckMode(AValue: TdxGalleryItemCheckMode);
    function GetGroups: TdxGalleryGroups;
    procedure SetGroups(AValue: TdxGalleryGroups);
    function GetOnChange: TdxGalleryChangeEvent;
    procedure SetOnChange(AValue: TdxGalleryChangeEvent);
    function GetOnItemClick: TdxGalleryItemEvent;
    procedure SetOnItemClick(AValue: TdxGalleryItemEvent);

    procedure GroupsChangeHandler(Sender: TObject; AItem: TcxComponentCollectionItem; AAction: TcxComponentCollectionNotification);
  protected
    function GetGroupClass: TdxGalleryGroupClass; virtual;
    function GetGroupsClass: TdxGalleryGroupsClass; virtual;

    procedure CheckItem(AItem: TdxGalleryItem; AValue: Boolean);
    procedure Changed(AType: TdxGalleryChangeType);
    procedure DoClickItem(AItem: TdxGalleryItem);

    function GetInstance: TObject;
    function GetParentComponent: TComponent;

    property OnChange: TdxGalleryChangeEvent read GetOnChange write SetOnChange;
    property OnItemClick: TdxGalleryItemEvent read GetOnItemClick write SetOnItemClick;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;

    procedure GetChildren(Proc: TGetChildProc; Root: TComponent);

    procedure ClickItem(AItem: TdxGalleryItem);
    procedure GetAllItems(AList: TList);
    function GetCheckedItem: TdxGalleryItem;
    function GetFirstItem: TdxGalleryItem;
    procedure GetCheckedItems(AList: TList);
    procedure UncheckAll;

    function FindItemByTag(ATag: TdxNativeInt): TdxGalleryItem;

    property ItemCheckMode: TdxGalleryItemCheckMode read GetItemCheckMode write SetItemCheckMode default icmNone;
    property Groups: TdxGalleryGroups read GetGroups write SetGroups;
  end;

  TdxGallery = class(TdxCustomGallery);

implementation

uses
  StrUtils, Controls;

{ TdxGalleryItem }

constructor TdxGalleryItem.Create(AOwner: TComponent);
begin
  inherited;
  FGlyph := TBitmap.Create;
  FGlyph.OnChange := GlyphChangeHandler;
  FEnabled := True;
  FImageIndex := -1;
end;

destructor TdxGalleryItem.Destroy;
begin
  FreeAndNil(FGlyph);
  inherited;
end;

procedure TdxGalleryItem.Assign(Source: TPersistent);
begin
  if Source is TdxGalleryItem then
  begin
    Caption := TdxGalleryItem(Source).Caption;
    Description := TdxGalleryItem(Source).Description;
    Glyph := TdxGalleryItem(Source).Glyph;
  end
  else
    inherited;
end;

function TdxGalleryItem.GetCollectionFromParent(AParent: TComponent): TcxComponentCollection;
begin
  Result := (AParent as TdxGalleryGroup).Items;
end;

function TdxGalleryItem.GetGallery: IdxGallery;
begin
  Result := ((Collection as TdxGalleryItems).GetOwner as TdxGalleryGroup).Gallery;
end;

function TdxGalleryItem.GetGroup: TdxGalleryGroup;
begin
  Result := GetParentComponent as TdxGalleryGroup;
end;

procedure TdxGalleryItem.GlyphChangeHandler(Sender: TObject);
begin
  Changed(True);
end;

procedure TdxGalleryItem.SetCaption(const AValue: string);
begin
  if FCaption <> AValue then
  begin
    FCaption := AValue;
    Changed(True);
  end;
end;

procedure TdxGalleryItem.SetChecked(AValue: Boolean);
begin
  if FChecked <> AValue then
    Gallery.ClickItem(Self);
end;

procedure TdxGalleryItem.SetDescription(const AValue: string);
begin
  if FDescription <> AValue then
  begin
    FDescription := AValue;
    Changed(True);
  end;
end;

procedure TdxGalleryItem.SetEnabled(AValue: Boolean);
begin
  if FEnabled <> AValue then
  begin
    FEnabled := AValue;
    Changed(False);
  end;
end;

procedure TdxGalleryItem.SetGlyph(AValue: TBitmap);
begin
  FGlyph.Assign(AValue);
  Changed(True);
end;

procedure TdxGalleryItem.SetImageIndex(Value: TcxImageIndex);
begin
  if FImageIndex <> Value then
  begin
    FImageIndex := Value;
    Changed(False);
  end;
end;

{ TdxGalleryItems }

function TdxGalleryItems.Add: TdxGalleryItem;
begin
  Result := inherited Add as TdxGalleryItem;
end;

function TdxGalleryItems.GetItemPrefixName: string;
begin
  Result := LeftStr(ItemClass.ClassName, Length(ItemClass.ClassName) - Length('Item'));
end;

function TdxGalleryItems.GetItem(AIndex: Integer): TdxGalleryItem;
begin
  Result := inherited Items[AIndex] as TdxGalleryItem;
end;

procedure TdxGalleryItems.SetItem(AIndex: Integer; AValue: TdxGalleryItem);
begin
  inherited Items[AIndex] := AValue;
end;

{ TdxCustomGalleryGroupHeader }

constructor TdxGalleryGroupHeader.Create(AOwner: TPersistent);
begin
  inherited;
  FVisible := True;
end;

procedure TdxGalleryGroupHeader.DoAssign(Source: TPersistent);
begin
  Caption := TdxGalleryGroupHeader(Source).Caption;
end;

procedure TdxGalleryGroupHeader.Changed;
begin
  dxCallNotify(OnChange, Self);
end;

procedure TdxGalleryGroupHeader.SetAlignment(AValue: TAlignment);
begin
  if FAlignment <> AValue then
  begin
    FAlignment := AValue;
    Changed;
  end;
end;

procedure TdxGalleryGroupHeader.SetCaption(const AValue: string);
begin
  if FCaption <> AValue then
  begin
    FCaption := AValue;
    Changed;
  end;
end;

procedure TdxGalleryGroupHeader.SetVisible(AValue: Boolean);
begin
  if FVisible <> AValue then
  begin
    FVisible := AValue;
    Changed;
  end;
end;

{ TdxGalleryGroup }

constructor TdxGalleryGroup.Create(AOwner: TComponent);
begin
  inherited;

  FHeader := TdxGalleryGroupHeader.Create(Self);
  FHeader.OnChange := HeaderChangeHandler;
  FItems := GetGalleryItemsClass.Create(Self, GetGalleryItemClass);
  FItems.OnChange := ItemsChangeHandler;

  FVisible := True;
end;

destructor TdxGalleryGroup.Destroy;
begin
  FreeAndNil(FItems);
  FreeAndNil(FHeader);
  inherited;
end;

procedure TdxGalleryGroup.Assign(Source: TPersistent);
begin
end;

procedure TdxGalleryGroup.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
begin
  for I := 0 to Items.Count - 1 do
    if Items[I].Owner = Root then Proc(Items[I]);
end;

function TdxGalleryGroup.GetCollectionFromParent(AParent: TComponent): TcxComponentCollection;
var
  AGallery: IdxGallery;
  AGalleryOwner: IdxGalleryOwner;
begin
  if Supports(AParent, IdxGallery, AGallery) then
    Result := AGallery.Groups
  else
    if Supports(AParent, IdxGalleryOwner, AGalleryOwner) then
      Result := AGalleryOwner.GetGallery.Groups
    else
      Result := nil;
end;

function TdxGalleryGroup.GetGallery: IdxGallery;
var
  AGalleryOwner: IdxGalleryOwner;
begin
  if not Supports(GetParentComponent, IdxGallery, Result) then
  begin
    if Supports(GetParentComponent, IdxGalleryOwner, AGalleryOwner) then
      Result := AGalleryOwner.GetGallery
    else
      Result := nil;
  end;
end;

function TdxGalleryGroup.GetGalleryItemClass: TdxGalleryItemClass;
begin
  Result := TdxGalleryItem;
end;

function TdxGalleryGroup.GetGalleryItemsClass: TdxGalleryItemsClass;
begin
  Result := TdxGalleryItems;
end;

function TdxGalleryGroup.GetCaption: string;
begin
  Result := FHeader.Caption;
end;

function TdxGalleryGroup.GetItemCount: Integer;
begin
  Result := Items.Count; 
end;

function TdxGalleryGroup.GetShowCaption: Boolean;
begin
  Result := FHeader.Visible;
end;

procedure TdxGalleryGroup.SetCaption(const AValue: string);
begin
  FHeader.Caption := AValue;
end;

procedure TdxGalleryGroup.SetItems(AValue: TdxGalleryItems);
begin
  Items.Assign(AValue);
end;

procedure TdxGalleryGroup.SetShowCaption(AValue: Boolean);
begin
  FHeader.Visible := AValue;
end;

procedure TdxGalleryGroup.SetVisible(AValue: Boolean);
begin
  if FVisible <> AValue then
  begin
    FVisible := AValue;
    Changed(True);
  end;
end;

procedure TdxGalleryGroup.ItemsChangeHandler(Sender: TObject; AItem: TcxComponentCollectionItem; AAction: TcxComponentCollectionNotification);
begin
  Changed(True);
end;

procedure TdxGalleryGroup.HeaderChangeHandler(ASender: TObject);
begin
  Changed(True);
end;

{ TdxCustomGalleryGroups }

function TdxGalleryGroups.Add: TdxGalleryGroup;
begin
  Result := inherited Add as TdxGalleryGroup;
end;

function TdxGalleryGroups.GetItemPrefixName: string;
begin
  Result := LeftStr(ItemClass.ClassName, Length(ItemClass.ClassName) - Length('Group'));
end;

function TdxGalleryGroups.FindByCaption(
  const ACaption: string; out AGroup: TdxGalleryGroup): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count - 1 do
  begin
    Result := SameText(Groups[I].Caption, ACaption);
    if Result then
    begin
      AGroup := Groups[I];
      Break;
    end;
  end;
end;

function TdxGalleryGroups.GetGroup(AIndex: Integer): TdxGalleryGroup;
begin
  Result := inherited Items[AIndex] as TdxGalleryGroup;
end;

procedure TdxGalleryGroups.SetGroup(AIndex: Integer; AValue: TdxGalleryGroup);
begin
  inherited Items[AIndex] := AValue;
end;

{ TdxCustomGallery }

constructor TdxCustomGallery.Create(AOwner: TPersistent);
begin
  inherited;
  FGroups := GetGroupsClass.Create(GetParentComponent, GetGroupClass);
  FGroups.OnChange := GroupsChangeHandler;
end;

destructor TdxCustomGallery.Destroy;
begin
  FreeAndNil(FGroups);
  inherited;
end;

procedure TdxCustomGallery.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
begin
  for I := 0 to Groups.Count - 1 do
    if Groups[I].Owner = Root then Proc(Groups[I]);
end;

function TdxCustomGallery.GetGroupClass: TdxGalleryGroupClass;
begin
  Result := TdxGalleryGroup;
end;

function TdxCustomGallery.GetGroupsClass: TdxGalleryGroupsClass;
begin
  Result := TdxGalleryGroups;
end;

procedure TdxCustomGallery.CheckItem(AItem: TdxGalleryItem; AValue: Boolean);
begin
  if (AItem <> nil) and (AItem.Checked <> AValue) then
  begin
    AItem.FChecked := AValue;
    Changed(gctLight);
  end;
end;

procedure TdxCustomGallery.Changed(AType: TdxGalleryChangeType);
begin
  if Assigned(OnChange) then
    FOnChange(Self, AType);
end;

procedure TdxCustomGallery.DoClickItem(AItem: TdxGalleryItem);
begin
  if Assigned(OnItemClick) then
    FOnItemClick(Self, AItem);
end;

function TdxCustomGallery.GetInstance: TObject;
begin
  Result := Self;
end;

function TdxCustomGallery.GetParentComponent: TComponent;
begin
  Result := Owner as TComponent;
end;

procedure TdxCustomGallery.ClickItem(AItem: TdxGalleryItem);
var
  ACheckedItem: TdxGalleryItem;
begin
  if (AItem <> nil) and AItem.Enabled then
  begin
    ACheckedItem := GetCheckedItem;
    case ItemCheckMode of
      icmNone: ;
      icmSingleCheck:
        begin
          CheckItem(ACheckedItem, False);
          if ACheckedItem <> AItem then
            CheckItem(AItem, True);
        end;
      icmSingleRadio:
        begin
          CheckItem(ACheckedItem, False);
          CheckItem(AItem, True);
        end;
      icmMultiple:
        CheckItem(AItem, not AItem.FChecked);
    end;

    DoClickItem(AItem);
  end;
end;

procedure TdxCustomGallery.GetAllItems(AList: TList);
var
  I, J: Integer;
begin
  for I := 0 to Groups.Count - 1 do
    for J := 0 to Groups[I].Items.Count - 1 do
      AList.Add(Groups[I].Items[J]);
end;

function TdxCustomGallery.GetCheckedItem: TdxGalleryItem;
var
  AList: TList;
begin
  AList := TList.Create;
  try
    GetCheckedItems(AList);
    if AList.Count > 0 then
      Result := TdxGalleryItem(AList[0])
    else
      Result := nil;
  finally
    AList.Free;
  end;
end;

function TdxCustomGallery.GetFirstItem: TdxGalleryItem;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Groups.Count - 1 do
    if Groups[I].Items.Count > 0 then
    begin
      Result := Groups[I].Items[0];
      Break;
    end;
end;

procedure TdxCustomGallery.GetCheckedItems(AList: TList);
var
  I, J: Integer;
begin
  for I := 0 to Groups.Count - 1 do
    for J := 0 to Groups[I].Items.Count - 1 do
      if Groups[I].Items[J].Checked then
        AList.Add(Groups[I].Items[J]);
end;

procedure TdxCustomGallery.UncheckAll;
var
  I: Integer;
  AList: TList;
begin
  AList := TList.Create;
  try
    GetCheckedItems(AList);
    for I := 0 to AList.Count - 1 do
      CheckItem(TdxGalleryItem(AList[I]), False)
  finally
    AList.Free;
  end;
end;

function TdxCustomGallery.FindItemByTag(ATag: TdxNativeInt): TdxGalleryItem;
var
  I, J: Integer;
begin
  Result := nil;
  for I := 0 to Groups.Count - 1 do
    for J := 0 to Groups[I].Items.Count - 1 do
      if Groups[I].Items[J].Tag = ATag then
      begin
        Result := Groups[I].Items[J];
        Break;
      end;
end;

function TdxCustomGallery.GetItemCheckMode: TdxGalleryItemCheckMode;
begin
  Result := FItemCheckMode;
end;

procedure TdxCustomGallery.SetItemCheckMode(AValue: TdxGalleryItemCheckMode);
begin
  if FItemCheckMode <> AValue then
  begin
    FItemCheckMode := AValue;
    UncheckAll;
  end;
end;

function TdxCustomGallery.GetGroups: TdxGalleryGroups;
begin
  Result := FGroups;
end;

procedure TdxCustomGallery.SetGroups(AValue: TdxGalleryGroups);
begin
  FGroups.Assign(AValue);
end;

function TdxCustomGallery.GetOnChange: TdxGalleryChangeEvent;
begin
  Result := FOnchange;
end;

procedure TdxCustomGallery.SetOnChange(AValue: TdxGalleryChangeEvent);
begin
  FOnchange := AValue;
end;

function TdxCustomGallery.GetOnItemClick: TdxGalleryItemEvent;
begin
  Result := FOnItemClick;
end;

procedure TdxCustomGallery.SetOnItemClick(AValue: TdxGalleryItemEvent);
begin
  FOnItemClick := AValue;
end;

procedure TdxCustomGallery.GroupsChangeHandler(Sender: TObject; AItem: TcxComponentCollectionItem; AAction: TcxComponentCollectionNotification);
begin
  Changed(gctHard);
end;

initialization
  StartClassGroup(TControl);
  ActivateClassGroup(TControl);  
  GroupDescendentsWith(TdxGalleryItem, TControl);
  GroupDescendentsWith(TdxGalleryGroup, TControl);
end.
