{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       ExpressBars components                                      }
{                                                                   }
{       Copyright (c) 1998-2014 Developer Express Inc.              }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSBARS AND ALL ACCOMPANYING VCL }
{   CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.                 }
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

unit dxRibbonBackstageViewGalleryControl;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Types, Windows, Messages, Classes, Graphics, Controls, Forms, cxClasses, cxGraphics, dxGallery, dxGalleryControl,
  cxControls, cxLookAndFeelPainters, dxRibbon, dxRibbonSkins, dxBar, dxBarStrs;

type      
  TdxCustomRibbonBackstageViewGalleryControl = class;
  TdxRibbonBackstageViewGalleryControlController = class;
  TdxRibbonBackstageViewGalleryControlOptionsView = class;
  TdxRibbonBackstageViewGalleryControlOptionsViewItem = class;
  TdxRibbonBackstageViewGalleryControlPainter = class;
  TdxRibbonBackstageViewGalleryControlViewInfo = class;
  TdxRibbonBackstageViewGalleryGroupViewInfo = class;
  TdxRibbonBackstageViewGalleryItemViewInfo = class;

  TdxRibbonBackstageViewGalleryItemPinMode = (bgipmNone, bgipmTag, bgipmButton);

  { TdxRibbonBackstageViewGalleryItem }

  TdxRibbonBackstageViewGalleryItem = class(TdxGalleryControlItem)
  private
    FAllowChangePinnedState: Boolean;
    FPinned: Boolean;
    function GetViewInfo: TdxRibbonBackstageViewGalleryItemViewInfo;
    procedure SetAllowChangePinnedState(AValue: Boolean);
    procedure SetPinned(AValue: Boolean);
  protected
    function CreateViewInfo: TdxGalleryItemViewInfo; override;
    //
    property ViewInfo: TdxRibbonBackstageViewGalleryItemViewInfo read GetViewInfo;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Assign(Source: TPersistent); override;
  published
    property AllowChangePinnedState: Boolean read FAllowChangePinnedState write SetAllowChangePinnedState default True;
    property Pinned: Boolean read FPinned write SetPinned default False;
  end;

  { TdxRibbonBackstageViewGalleryItemViewInfo }

  TdxRibbonBackstageViewGalleryItemViewInfo = class(TdxGalleryItemViewInfo)
  private
    function GetController: TdxRibbonBackstageViewGalleryControlController; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetControlViewInfo: TdxRibbonBackstageViewGalleryControlViewInfo; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetItem: TdxRibbonBackstageViewGalleryItem; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetPainter: TdxRibbonBackstageViewGalleryControlPainter; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetPartCount: Integer;
    function GetParts(Index: Integer): TRect;
    function GetPinSize: TSize;
  protected
    FParts: array of TRect;
    procedure CalculateGlyphArea(const AGlyphSize: TSize); override;
    procedure CalculateTextAreaContent(const ABounds: TRect); override;
    procedure CheckTextAreaSize; virtual;
    function GetPartState(Index: Integer): TdxGalleryItemViewState;
    function GetPinMode: TdxRibbonBackstageViewGalleryItemPinMode; virtual;
    function GetTextAreaSize: TSize; override;
  public
    procedure Calculate(AType: TdxChangeType; const ABounds: TRect); override;
    procedure CalculateTextAreaSizeLimitedByRowCount(ACanvas: TcxCanvas; ARowCount: Integer); override;
    procedure CalculateTextAreaSizeLimitedByWidth(ACanvas: TcxCanvas; AMaxWidth: Integer); override;
    function GetPartAtPos(const P: TPoint): Integer;
    function GetPartHint(APartIndex: Integer): string; virtual;
    //
    property Controller: TdxRibbonBackstageViewGalleryControlController read GetController;
    property ControlViewInfo: TdxRibbonBackstageViewGalleryControlViewInfo read GetControlViewInfo;
    property Item: TdxRibbonBackstageViewGalleryItem read GetItem;
    property Painter: TdxRibbonBackstageViewGalleryControlPainter read GetPainter;
    property PartCount: Integer read GetPartCount;
    property Parts[Index: Integer]: TRect read GetParts;
    property PartState[Index: Integer]: TdxGalleryItemViewState read GetPartState;
    property PinMode: TdxRibbonBackstageViewGalleryItemPinMode read GetPinMode;
    property PinSize: TSize read GetPinSize;
  end;

  { TdxRibbonBackstageViewGalleryItems }

  TdxRibbonBackstageViewGalleryItems = class(TdxGalleryControlItems)
  private
    function GetItem(AIndex: Integer): TdxRibbonBackstageViewGalleryItem;
    procedure SetItem(AIndex: Integer; AValue: TdxRibbonBackstageViewGalleryItem);
  protected
    function GetPinnedItemsCount: Integer;
  public
    function Add: TdxRibbonBackstageViewGalleryItem;
    function GetItemAtPos(const P: TPoint): TdxRibbonBackstageViewGalleryItem;

    property Items[AIndex: Integer]: TdxRibbonBackstageViewGalleryItem read GetItem write SetItem; default;
  end;

  { TdxRibbonBackstageViewGalleryGroup }

  TdxRibbonBackstageViewGalleryGroup = class(TdxGalleryControlGroup)
  private
    function GetItems: TdxRibbonBackstageViewGalleryItems; {$IFDEF DELPHI9}inline;{$ENDIF}
  protected
    function CreateViewInfo: TdxGalleryGroupViewInfo; override;
    function GetGalleryItemClass: TdxGalleryItemClass; override;
    function GetGalleryItemsClass: TdxGalleryItemsClass; override;
  public
    property Items: TdxRibbonBackstageViewGalleryItems read GetItems;
  end;

  { TdxRibbonBackstageViewGalleryGroupViewInfo }

  TdxRibbonBackstageViewGalleryGroupViewInfo = class(TdxGalleryGroupViewInfo)
  private
    function GetGroup: TdxRibbonBackstageViewGalleryGroup; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetOptionsView: TdxRibbonBackstageViewGalleryControlOptionsView; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetPainter: TdxRibbonBackstageViewGalleryControlPainter; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetSeparatePinnedItems: Boolean;
  protected
    FSeparatorRect: TRect;
    procedure CalculateItems(AType: TdxChangeType); override;
    procedure CalculatePinnableItemsPlace(AItemRect: TRect; AType: TdxChangeType); virtual;
    procedure DrawContent(ACanvas: TcxCanvas); override;
    procedure DrawSeparator(ACanvas: TcxCanvas); virtual;
  public
    procedure Calculate(AType: TdxChangeType; const ABounds: TRect); override;
    function GetMaxColumnCount: Integer; override;
    //
    property Group: TdxRibbonBackstageViewGalleryGroup read GetGroup;
    property OptionsView: TdxRibbonBackstageViewGalleryControlOptionsView read GetOptionsView;
    property Painter: TdxRibbonBackstageViewGalleryControlPainter read GetPainter;
    property SeparatePinnedItems: Boolean read GetSeparatePinnedItems;
    property SeparatorRect: TRect read FSeparatorRect;
  end;

  { TdxRibbonbackstageViewGalleryGroups }

  TdxRibbonbackstageViewGalleryGroups = class(TdxGalleryControlGroups)
  private
    function GetGroup(AIndex: Integer): TdxRibbonBackstageViewGalleryGroup;
    procedure SetGroup(AIndex: Integer; AValue: TdxRibbonBackstageViewGalleryGroup);
  public
    function Add: TdxRibbonBackstageViewGalleryGroup;
    function FindByCaption(const ACaption: string; out AGroup: TdxRibbonBackstageViewGalleryGroup): Boolean;
    function GetItemAtPos(const P: TPoint): TdxRibbonBackstageViewGalleryItem;

    property Groups[AIndex: Integer]: TdxRibbonBackstageViewGalleryGroup read GetGroup write SetGroup; default;
  end;

  { TdxRibbonBackstageViewGallery }

  TdxRibbonBackstageViewGallery = class(TdxGalleryControlStructure)
  private
    function GetGroups: TdxRibbonbackstageViewGalleryGroups;
  protected
    function GetGroupClass: TdxGalleryGroupClass; override;
    function GetGroupsClass: TdxGalleryGroupsClass; override;
  public
    property Groups: TdxRibbonbackstageViewGalleryGroups read GetGroups;
  end;

  { TdxRibbonBackstageViewGalleryControlViewInfo }

  TdxRibbonBackstageViewGalleryControlViewInfo = class(TdxGalleryControlViewInfo)
  private
    function GetOptionsViewItem: TdxRibbonBackstageViewGalleryControlOptionsViewItem; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetPainter: TdxRibbonBackstageViewGalleryControlPainter; {$IFDEF DELPHI9}inline;{$ENDIF}
    function GetPinMode: TdxRibbonBackstageViewGalleryItemPinMode;
  protected
    function DoCalculateItemSize: TSize; override;
    function GetTextAreaMaxWidth(const AImageSize: TSize): Integer; override;
  public
    property OptionsViewItem: TdxRibbonBackstageViewGalleryControlOptionsViewItem read GetOptionsViewItem;
    property Painter: TdxRibbonBackstageViewGalleryControlPainter read GetPainter;
    property PinMode: TdxRibbonBackstageViewGalleryItemPinMode read GetPinMode;
  end;

  { TdxRibbonBackstageViewGalleryControlController }

  TdxRibbonBackstageViewGalleryControlController = class(TdxGalleryControlController)
  private
    FKeyPressedCode: Integer;
    FKeySelectedItemPartIndex: Integer;
    FMouseHoveredItemPartIndex: Integer;
    procedure CheckPartIndex(var APartIndex: Integer; AItem: TdxRibbonBackstageViewGalleryItem);
    function GetKeySelectedItem: TdxRibbonBackstageViewGalleryItem;
    function GetMouseHoveredItem: TdxRibbonBackstageViewGalleryItem;
    function GetOwnerControl: TdxCustomRibbonBackstageViewGalleryControl;
    function GetPinMode: TdxRibbonBackstageViewGalleryItemPinMode;
    procedure SetKeySelectedItem(AValue: TdxRibbonBackstageViewGalleryItem);
    procedure SetKeySelectedItemPartIndex(AValue: Integer);
    procedure SetMouseHoveredItem(AValue: TdxRibbonBackstageViewGalleryItem);
    procedure SetMouseHoveredItemPartIndex(AValue: Integer);
  protected
    procedure ProcessItemClick(AItem: TdxGalleryControlItem; X, Y: Integer); override;
    procedure ProcessItemPartClick(AItem: TdxRibbonBackstageViewGalleryItem; APartIndex: Integer); virtual;
    procedure ProcessNavigationKey(AKey: Word; AShift: TShiftState); virtual;
    procedure UpdateMouseHoveredItem(const P: TPoint); override;
  public
    procedure KeyDown(AKey: Word; AShift: TShiftState); override;
    procedure KeyUp(AKey: Word; AShift: TShiftState); override;

    property KeyPressedCode: Integer read FKeyPressedCode write FKeyPressedCode;
    property KeySelectedItem: TdxRibbonBackstageViewGalleryItem read GetKeySelectedItem write SetKeySelectedItem;
    property KeySelectedItemPartIndex: Integer read FKeySelectedItemPartIndex write SetKeySelectedItemPartIndex;
    property MouseHoveredItem: TdxRibbonBackstageViewGalleryItem read GetMouseHoveredItem write SetMouseHoveredItem;
    property MouseHoveredItemPartIndex: Integer read FMouseHoveredItemPartIndex write SetMouseHoveredItemPartIndex;
    property Owner: TdxCustomRibbonBackstageViewGalleryControl read GetOwnerControl;
    property PinMode: TdxRibbonBackstageViewGalleryItemPinMode read GetPinMode;
  end;

  { TdxRibbonBackstageViewGalleryControlPainter }

  TdxRibbonBackstageViewGalleryControlPainter = class(TdxGalleryControlPainter)
  private
    function GetPartState(const AState: TdxGalleryItemViewState): Integer;
    function GetSkin: IdxSkin;
  protected
    function DrawItemSelectionFirst: Boolean; override;
    function GetGroupCaptionTextColor: TColor; override;
    function GetItemCaptionTextColor(const AState: TdxGalleryItemViewState): TColor; override;
    function GetItemDescriptionTextColor(const AState: TdxGalleryItemViewState): TColor; override;
  public
    procedure DrawBackground(ACanvas: TcxCanvas; const ABounds: TRect); override;
    procedure DrawBorder(ACanvas: TcxCanvas; const ABounds: TRect); virtual;
    function GetBorderSize: Integer; virtual;
    // Group
    procedure DrawGroupHeader(ACanvas: TcxCanvas; const AViewInfo: TdxGalleryGroupViewInfo); override;
    function GetGroupHeaderContentOffsets: TRect; override;
    // Item
    procedure DrawItem(ACanvas: TcxCanvas; AViewInfo: TdxGalleryItemViewInfo); override;
    procedure DrawItemPin(ACanvas: TcxCanvas; AViewInfo: TdxRibbonBackstageViewGalleryItemViewInfo); virtual;
    procedure DrawItemSelection(ACanvas: TcxCanvas; AViewInfo: TdxGalleryItemViewInfo); override;
    // Pin
    function GetPinButtonSize: TSize; virtual;
    function GetPinTagSize: TSize; virtual;

    // Pinned Items Separator
    procedure DrawPinnedItemSeparator(ACanvas: TcxCanvas; const R: TRect); virtual;
    function GetPinnedItemSeparatorHeight: Integer; virtual;

    property Skin: IdxSkin read GetSkin;
  end;

  { TdxRibbonBackstageViewGalleryControlOptionsBehavior }

  TdxRibbonBackstageViewGalleryControlOptionsBehavior = class(TdxGalleryControlOptionsBehavior);

  { TdxRibbonBackstageViewGalleryControlOptionsViewItem }

  TdxRibbonBackstageViewGalleryControlOptionsViewItem = class(TdxGalleryControlOptionsItem)
  private
    FPinMode: TdxRibbonBackstageViewGalleryItemPinMode;
    procedure SetPinMode(AValue: TdxRibbonBackstageViewGalleryItemPinMode);
  protected
    procedure DoAssign(Source: TPersistent); override;
  published
    property PinMode: TdxRibbonBackstageViewGalleryItemPinMode read FPinMode write SetPinMode default bgipmNone;
  end;

  { TdxRibbonBackstageViewGalleryControlOptionsViewGroup }

  TdxRibbonBackstageViewGalleryControlOptionsViewGroup = class(TdxGalleryControlCustomOptions)
  private
    FPinnedItemSeparator: Boolean;
    procedure SetPinnedItemSeparator(AValue: Boolean);
  protected
    procedure DoAssign(Source: TPersistent); override;
  public
    constructor Create(AOwner: TdxCustomGalleryControl); override;
  published
    property PinnedItemSeparator: Boolean read FPinnedItemSeparator write SetPinnedItemSeparator default True;
  end;

  { TdxRibbonBackstageViewGalleryControlOptionsView }

  TdxRibbonBackstageViewGalleryControlOptionsView = class(TdxGalleryControlOptionsView)
  private
    FGroup: TdxRibbonBackstageViewGalleryControlOptionsViewGroup;
    function GetItem: TdxRibbonBackstageViewGalleryControlOptionsViewItem;
    procedure SetGroup(AValue: TdxRibbonBackstageViewGalleryControlOptionsViewGroup);
    procedure SetItem(AValue: TdxRibbonBackstageViewGalleryControlOptionsViewItem);
  protected
    function CreateGroup: TdxRibbonBackstageViewGalleryControlOptionsViewGroup; virtual;
    function CreateItem: TdxGalleryControlOptionsItem; override;
    procedure DoAssign(Source: TPersistent); override;
  public
    constructor Create(AOwner: TdxCustomGalleryControl); override;
    destructor Destroy; override;
  published
    property Group: TdxRibbonBackstageViewGalleryControlOptionsViewGroup read FGroup write SetGroup;
    property Item: TdxRibbonBackstageViewGalleryControlOptionsViewItem read GetItem write SetItem;
  end;

  { TdxRibbonBackstageViewGalleryControlSizeGrip }

  TdxRibbonBackstageViewGalleryControlSizeGrip = class(TdxRibbonSizeGrip)
  protected
    function GetRibbon: TdxCustomRibbon; override;
  end;

  { TdxRibbonBackstageViewGalleryControlScrollBar }

  TdxRibbonBackstageViewGalleryControlScrollBar = class(TdxRibbonScrollBar)
  protected
    function GetRibbon: TdxCustomRibbon; override;
  end;

  { TdxCustomRibbonBackstageViewGalleryControl }

  TdxRibbonBackstageViewGalleryControlItemEvent = procedure(Sender: TObject; AItem: TdxRibbonBackstageViewGalleryItem) of object;

  TdxCustomRibbonBackstageViewGalleryControl = class(TdxCustomGalleryControl)
  private
    FRibbon: TdxCustomRibbon;
    FOnItemClick: TdxRibbonBackstageViewGalleryControlItemEvent;

    procedure ColorSchemeChangeHandler(Sender: TObject; const AEventArgs);
    function GetController: TdxRibbonBackstageViewGalleryControlController;
    function GetGallery: TdxRibbonBackstageViewGallery;
    function GetOptionsBehavior: TdxRibbonBackstageViewGalleryControlOptionsBehavior;
    function GetOptionsView: TdxRibbonBackstageViewGalleryControlOptionsView;
    function GetPainter: TdxRibbonBackstageViewGalleryControlPainter;
    function GetViewInfo: TdxRibbonBackstageViewGalleryControlViewInfo;
    procedure SetGallery(AValue: TdxRibbonBackstageViewGallery);
    procedure SetOptionsBehavior(AValue: TdxRibbonBackstageViewGalleryControlOptionsBehavior);
    procedure SetOptionsView(AValue: TdxRibbonBackstageViewGalleryControlOptionsView);
    procedure SetRibbon(AValue: TdxCustomRibbon);
    // Messages
    procedure CMHintShow(var Message: TCMHintShow); message CM_HINTSHOW;
  protected
    function CreateController: TdxGalleryControlController; override;
    function CreateGallery: TdxGalleryControlStructure; override;
    function CreateOptionsBehavior: TdxGalleryControlOptionsBehavior; override;
    function CreateOptionsView: TdxGalleryControlOptionsView; override;
    function CreatePainter: TdxGalleryControlPainter; override;
    function CreateViewInfo: TdxGalleryControlViewInfo; override;
    //
    procedure DoClickItem(AItem: TdxGalleryItem); override;
    procedure DrawBorder(ACanvas: TcxCanvas); override;
    function GetBorderSize: Integer; override;
    function GetScrollBarClass(AKind: TScrollBarKind): TcxControlScrollBarClass; override;
    function GetSizeGripClass: TcxSizeGripClass; override;
    procedure Notification(AComponent: TComponent; AOperation: TOperation); override;
    //
    property Controller: TdxRibbonBackstageViewGalleryControlController read GetController;
    property Gallery: TdxRibbonBackstageViewGallery read GetGallery write SetGallery;
    property OptionsBehavior: TdxRibbonBackstageViewGalleryControlOptionsBehavior read GetOptionsBehavior write SetOptionsBehavior;
    property OptionsView: TdxRibbonBackstageViewGalleryControlOptionsView read GetOptionsView write SetOptionsView;
    property Painter: TdxRibbonBackstageViewGalleryControlPainter read GetPainter;
    property Ribbon: TdxCustomRibbon read FRibbon write SetRibbon;
    property ViewInfo: TdxRibbonBackstageViewGalleryControlViewInfo read GetViewInfo;
    //
    property OnItemClick: TdxRibbonBackstageViewGalleryControlItemEvent read FOnItemClick write FOnItemClick;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;

  { TdxRibbonBackstageViewGalleryControl }

  TdxRibbonBackstageViewGalleryControl = class(TdxCustomRibbonBackstageViewGalleryControl)
  published
    property Align;
    property Anchors;
    property Enabled;
    property Font;
    property PopupMenu;
    property Visible;

    property AutoSizeMode default asNone;
    property BorderStyle default cxcbsDefault;
    property Gallery;
    property Images;
    property OptionsBehavior;
    property OptionsView;
    property Ribbon;

    property OnClick;
    property OnDblClick;
    property OnContextPopup;
    property OnItemClick;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
  end;

implementation

uses
  Math, SysUtils, cxGeometry, dxBarSkinConsts, cxDrawTextUtils, cxLookAndFeels;

const
  bvgipItem = 0;
  bvgipPin = 1;

{ TdxRibbonBackstageViewGalleryItem }

constructor TdxRibbonBackstageViewGalleryItem.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FAllowChangePinnedState := True;
end;

procedure TdxRibbonBackstageViewGalleryItem.Assign(Source: TPersistent);
begin
  inherited Assign(Source);
  if Source is TdxRibbonBackstageViewGalleryItem then
  begin
    AllowChangePinnedState := TdxRibbonBackstageViewGalleryItem(Source).AllowChangePinnedState;
    Pinned := TdxRibbonBackstageViewGalleryItem(Source).Pinned;
  end;
end;

function TdxRibbonBackstageViewGalleryItem.CreateViewInfo: TdxGalleryItemViewInfo;
begin
  Result := TdxRibbonBackstageViewGalleryItemViewInfo.Create(Self);
end;

function TdxRibbonBackstageViewGalleryItem.GetViewInfo: TdxRibbonBackstageViewGalleryItemViewInfo;
begin
  Result := inherited ViewInfo as TdxRibbonBackstageViewGalleryItemViewInfo;
end;

procedure TdxRibbonBackstageViewGalleryItem.SetAllowChangePinnedState(AValue: Boolean);
begin
  if FAllowChangePinnedState <> AValue then
  begin
    FAllowChangePinnedState := AValue;
    Changed(False);
  end;
end;

procedure TdxRibbonBackstageViewGalleryItem.SetPinned(AValue: Boolean);
begin
  if FPinned <> AValue then
  begin
    FPinned := AValue;
    Changed(True);
  end;
end;

{ TdxRibbonBackstageViewGalleryItemViewInfo }

procedure TdxRibbonBackstageViewGalleryItemViewInfo.Calculate(AType: TdxChangeType; const ABounds: TRect);
begin
  case PinMode of
    bgipmTag:
      begin
        SetLength(FParts, 2);
        FParts[bvgipItem] := ABounds;
        FParts[bvgipPin] := cxNullRect;
      end;

    bgipmButton:
      begin
        SetLength(FParts, 2);
        FParts[bvgipItem] := cxRectSetWidth(ABounds, cxRectWidth(ABounds) - PinSize.cx);
        FParts[bvgipPin] := cxRectSetRight(ABounds, ABounds.Right, PinSize.cx);
      end;

  else
    begin
      SetLength(FParts, 1);
      FParts[bvgipItem] := ABounds;
    end;
  end;
  inherited Calculate(AType, Parts[bvgipItem]);
  FBounds := ABounds;
end;

procedure TdxRibbonBackstageViewGalleryItemViewInfo.CalculateTextAreaSizeLimitedByRowCount(ACanvas: TcxCanvas; ARowCount: Integer);
begin
  inherited CalculateTextAreaSizeLimitedByRowCount(ACanvas, ARowCount);
  CheckTextAreaSize;
end;

procedure TdxRibbonBackstageViewGalleryItemViewInfo.CalculateTextAreaSizeLimitedByWidth(ACanvas: TcxCanvas; AMaxWidth: Integer);
begin
  if PinMode = bgipmTag then
    Dec(AMaxWidth, PinSize.cx);
  inherited CalculateTextAreaSizeLimitedByWidth(ACanvas, AMaxWidth);
  CheckTextAreaSize;
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetPartAtPos(const P: TPoint): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to PartCount - 1 do
  begin
    if cxRectPtIn(Parts[I], P) then
      Result := I;
  end;
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetPartHint(APartIndex: Integer): string;
begin
  if APartIndex <> bvgipPin then
    Result := Item.Hint
  else
    if Item.Pinned then
      Result := cxGetResourceString(@dxSBAR_UNPIN)
    else
      Result := cxGetResourceString(@dxSBAR_PIN);
end;

procedure TdxRibbonBackstageViewGalleryItemViewInfo.CalculateGlyphArea(const AGlyphSize: TSize);
begin
  if (PinMode = bgipmTag) and (OptionsItemText.Position = posNone) then
  begin
    FParts[bvgipPin] := cxRectSetRight(ContentBounds, ContentBounds.Right, PinSize.cx);
    FParts[bvgipPin] := cxRectCenterVertically(Parts[bvgipPin], PinSize.cy);
    FContentBounds.Right := Parts[bvgipPin].Left;
  end;
  inherited CalculateGlyphArea(AGlyphSize);
end;

procedure TdxRibbonBackstageViewGalleryItemViewInfo.CalculateTextAreaContent(const ABounds: TRect);
var
  ARect: TRect;
begin
  ARect := ABounds;
  if (PinMode = bgipmTag) and (OptionsItemText.Position <> posNone) then
  begin
    FParts[bvgipPin] := cxRectSetRight(ARect, ARect.Right, PinSize.cx);
    if OptionsItemText.Position in [posTop, posBottom] then
      FParts[bvgipPin] := cxRectSetHeight(Parts[bvgipPin], PinSize.cy)
    else
      FParts[bvgipPin] := cxRectCenterVertically(Parts[bvgipPin], PinSize.cy);

    ARect.Right := Parts[bvgipPin].Left;
  end;
  inherited CalculateTextAreaContent(ARect);
end;

procedure TdxRibbonBackstageViewGalleryItemViewInfo.CheckTextAreaSize;
var
  ADelta: Integer;
begin
  if PinMode = bgipmTag then
  begin
    ADelta := PinSize.cy - TextAreaSize.cy;
    if ADelta > 0 then
    begin
      if DescriptionSize.cy > 0 then
        Inc(FDescriptionSize.cy, ADelta)
      else
        Inc(FCaptionSize.cy, ADelta);
    end;
  end;
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetPartState(Index: Integer): TdxGalleryItemViewState;
begin
  Result := FState;
  Result.Hover := Result.Hover and (Index = Controller.MouseHoveredItemPartIndex);
  Result.Focused := Result.Focused and (Index = Controller.KeySelectedItemPartIndex);
  Result.Pressed := Result.Pressed and (
    Controller.KeyPressed and (Index = Controller.KeySelectedItemPartIndex) or
    Controller.MousePressed and (Index = Controller.MouseHoveredItemPartIndex));
  if Index = bvgipPin then
    Result.Checked := Item.Pinned;
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetPinMode: TdxRibbonBackstageViewGalleryItemPinMode;
begin
  if Item.AllowChangePinnedState then
    Result := ControlViewInfo.PinMode
  else
    Result := bgipmNone;
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetTextAreaSize: TSize;
begin
  Result := inherited GetTextAreaSize;
  if PinMode = bgipmTag then
    Inc(Result.cx, PinSize.cx + cxTextOffset);
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetController: TdxRibbonBackstageViewGalleryControlController;
begin
  Result := TdxCustomRibbonBackstageViewGalleryControl(GalleryControl).Controller; 
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetControlViewInfo: TdxRibbonBackstageViewGalleryControlViewInfo;
begin
  Result := TdxCustomRibbonBackstageViewGalleryControl(GalleryControl).ViewInfo;
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetItem: TdxRibbonBackstageViewGalleryItem;
begin
  Result :=  inherited Item as TdxRibbonBackstageViewGalleryItem;
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetPainter: TdxRibbonBackstageViewGalleryControlPainter;
begin
  Result := inherited Painter as TdxRibbonBackstageViewGalleryControlPainter;
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetPartCount: Integer;
begin
  Result := Length(FParts);
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetParts(Index: Integer): TRect;
begin
  Result := FParts[Index]; 
end;

function TdxRibbonBackstageViewGalleryItemViewInfo.GetPinSize: TSize;
begin
  if PinMode = bgipmTag then
    Result := Painter.GetPinTagSize
  else
    Result := Painter.GetPinButtonSize;
end;

{ TdxRibbonBackstageViewGalleryItems }

function TdxRibbonBackstageViewGalleryItems.Add: TdxRibbonBackstageViewGalleryItem;
begin
  Result := inherited Add as TdxRibbonBackstageViewGalleryItem;
end;

function TdxRibbonBackstageViewGalleryItems.GetItemAtPos(const P: TPoint): TdxRibbonBackstageViewGalleryItem;
begin
  Result := inherited GetItemAtPos(P) as TdxRibbonBackstageViewGalleryItem;
end;

function TdxRibbonBackstageViewGalleryItems.GetPinnedItemsCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to Count - 1 do
  begin
    if Items[I].Pinned then
      Inc(Result);
  end;
end;

function TdxRibbonBackstageViewGalleryItems.GetItem(AIndex: Integer): TdxRibbonBackstageViewGalleryItem;
begin
  Result := inherited Items[AIndex] as TdxRibbonBackstageViewGalleryItem;
end;

procedure TdxRibbonBackstageViewGalleryItems.SetItem(AIndex: Integer; AValue: TdxRibbonBackstageViewGalleryItem);
begin
  inherited SetItem(AIndex, AValue);
end;

{ TdxRibbonBackstageViewGalleryGroup }

function TdxRibbonBackstageViewGalleryGroup.CreateViewInfo: TdxGalleryGroupViewInfo;
begin
  Result := TdxRibbonBackstageViewGalleryGroupViewInfo.Create(Self);
end;

function TdxRibbonBackstageViewGalleryGroup.GetGalleryItemClass: TdxGalleryItemClass;
begin
  Result := TdxRibbonBackstageViewGalleryItem;
end;

function TdxRibbonBackstageViewGalleryGroup.GetGalleryItemsClass: TdxGalleryItemsClass;
begin
  Result := TdxRibbonBackstageViewGalleryItems;
end;

function TdxRibbonBackstageViewGalleryGroup.GetItems: TdxRibbonBackstageViewGalleryItems;
begin
  Result := inherited Items as TdxRibbonBackstageViewGalleryItems;
end;

{ TdxRibbonBackstageViewGalleryGroupViewInfo }

procedure TdxRibbonBackstageViewGalleryGroupViewInfo.Calculate(AType: TdxChangeType; const ABounds: TRect);
begin
  FSeparatorRect := cxNullRect;
  inherited Calculate(AType, ABounds);
end;

function TdxRibbonBackstageViewGalleryGroupViewInfo.GetMaxColumnCount: Integer;
var
  APinnedItemsCount: Integer;
begin
  if SeparatePinnedItems then
  begin
    APinnedItemsCount := Group.Items.GetPinnedItemsCount;
    Result := Max(APinnedItemsCount, Group.ItemCount - APinnedItemsCount);
  end
  else
    Result := inherited GetMaxColumnCount;
end;

procedure TdxRibbonBackstageViewGalleryGroupViewInfo.CalculateItems(AType: TdxChangeType);
begin
  if OptionsView.Item.PinMode <> bgipmNone then
    CalculatePinnableItemsPlace(ItemsRect, AType)
  else
    inherited CalculateItems(AType);
end;

procedure TdxRibbonBackstageViewGalleryGroupViewInfo.CalculatePinnableItemsPlace(AItemRect: TRect; AType: TdxChangeType);

  function HasSeparator: Boolean;
  begin
    Result := InRange(Group.Items.GetPinnedItemsCount, 1, Group.ItemCount - 1);
  end;

  procedure PlaceItems(APinState: Boolean; const R: TRect; var ACellIndex: Integer; var ALastItem: TdxRibbonBackstageViewGalleryItem);
  var
    AItem: TdxRibbonBackstageViewGalleryItem;
    I: Integer;
  begin
    ALastItem := nil;
    for I := 0 to Group.ItemCount - 1 do
    begin
      AItem := Group.Items[I];
      if AItem.Pinned = APinState then
      begin
        PlaceItem(AItem, AType, R, ACellIndex);
        ALastItem := AItem;
        Inc(ACellIndex);
      end;
    end;
  end;

var
  ACellIndex: Integer;
  ALastItem: TdxRibbonBackstageViewGalleryItem;
begin
  ALastItem := nil;
  ACellIndex := 0;

  PlaceItems(True, AItemRect, ACellIndex, ALastItem);
  if SeparatePinnedItems and HasSeparator then
  begin
    if ACellIndex mod ColumnCount <> 0 then
      Inc(ACellIndex, ColumnCount - ACellIndex mod ColumnCount);
    FSeparatorRect := cxRectSetTop(AItemRect,
      ALastItem.ViewInfo.Bounds.Bottom + ContentOffsetGroups.Bottom,
      Painter.GetPinnedItemSeparatorHeight);
    Inc(AItemRect.Top, cxRectHeight(SeparatorRect) + cxMarginsHeight(ContentOffsetGroups));
  end;
  PlaceItems(False, AItemRect, ACellIndex, ALastItem);

  if ALastItem <> nil then
  begin
    FItemsRect.Bottom := ALastItem.ViewInfo.Bounds.Bottom;
    FRowCount := ALastItem.ViewInfo.CellPositionInGroup.Y + 1;
  end;
end;

procedure TdxRibbonBackstageViewGalleryGroupViewInfo.DrawContent(ACanvas: TcxCanvas);
begin
  inherited DrawContent(ACanvas);
  DrawSeparator(ACanvas);
end;

procedure TdxRibbonBackstageViewGalleryGroupViewInfo.DrawSeparator(ACanvas: TcxCanvas);
begin
  if not cxRectIsEmpty(SeparatorRect) then
    Painter.DrawPinnedItemSeparator(ACanvas, SeparatorRect);
end;

function TdxRibbonBackstageViewGalleryGroupViewInfo.GetGroup: TdxRibbonBackstageViewGalleryGroup;
begin
  Result := inherited Group as TdxRibbonBackstageViewGalleryGroup;
end;

function TdxRibbonBackstageViewGalleryGroupViewInfo.GetOptionsView: TdxRibbonBackstageViewGalleryControlOptionsView;
begin
  Result := inherited OptionsView as TdxRibbonBackstageViewGalleryControlOptionsView;
end;

function TdxRibbonBackstageViewGalleryGroupViewInfo.GetPainter: TdxRibbonBackstageViewGalleryControlPainter;
begin
  Result := inherited Painter as TdxRibbonBackstageViewGalleryControlPainter;
end;

function TdxRibbonBackstageViewGalleryGroupViewInfo.GetSeparatePinnedItems: Boolean;
begin
  Result := TdxRibbonBackstageViewGalleryControlOptionsView(OptionsView).Group.PinnedItemSeparator;
end;

{ TdxRibbonbackstageViewGalleryGroups }

function TdxRibbonbackstageViewGalleryGroups.Add: TdxRibbonBackstageViewGalleryGroup;
begin
  Result := inherited Add as TdxRibbonBackstageViewGalleryGroup;
end;

function TdxRibbonbackstageViewGalleryGroups.FindByCaption(
  const ACaption: string; out AGroup: TdxRibbonBackstageViewGalleryGroup): Boolean;
begin
  Result := inherited FindByCaption(ACaption, TdxGalleryControlGroup(AGroup));
end;

function TdxRibbonbackstageViewGalleryGroups.GetGroup(AIndex: Integer): TdxRibbonBackstageViewGalleryGroup;
begin
  Result := inherited Groups[AIndex] as TdxRibbonBackstageViewGalleryGroup;
end;

function TdxRibbonbackstageViewGalleryGroups.GetItemAtPos(const P: TPoint): TdxRibbonBackstageViewGalleryItem;
begin
  Result := inherited GetItemAtPos(P) as TdxRibbonBackstageViewGalleryItem;
end;

procedure TdxRibbonbackstageViewGalleryGroups.SetGroup(AIndex: Integer; AValue: TdxRibbonBackstageViewGalleryGroup);
begin
  inherited Groups[AIndex] := AValue;
end;

{ TdxRibbonBackstageViewGallery }

function TdxRibbonBackstageViewGallery.GetGroupClass: TdxGalleryGroupClass;
begin
  Result := TdxRibbonBackstageViewGalleryGroup;
end;

function TdxRibbonBackstageViewGallery.GetGroupsClass: TdxGalleryGroupsClass;
begin
  Result := TdxRibbonBackstageViewGalleryGroups;
end;

function TdxRibbonBackstageViewGallery.GetGroups: TdxRibbonbackstageViewGalleryGroups;
begin
  Result := inherited Groups as TdxRibbonBackstageViewGalleryGroups;
end;

{ TdxRibbonBackstageViewGalleryControlViewInfo }

function TdxRibbonBackstageViewGalleryControlViewInfo.DoCalculateItemSize: TSize;
begin
  Result := inherited DoCalculateItemSize;
  case PinMode of
    bgipmButton:
      Inc(Result.cx, Painter.GetPinButtonSize.cx);
    bgipmTag:
      if OptionsItemText.Position = posNone then
        Inc(Result.cx, Painter.GetPinTagSize.cx);
  end;
end;

function TdxRibbonBackstageViewGalleryControlViewInfo.GetTextAreaMaxWidth(const AImageSize: TSize): Integer;
begin
  Result := inherited GetTextAreaMaxWidth(AImageSize);
  if (PinMode = bgipmTag) and (OptionsItemText.Position <> posNone) then
    Inc(Result, Painter.GetPinTagSize.cx);
end;

function TdxRibbonBackstageViewGalleryControlViewInfo.GetOptionsViewItem: TdxRibbonBackstageViewGalleryControlOptionsViewItem;
begin
  Result := inherited OptionsView.Item as TdxRibbonBackstageViewGalleryControlOptionsViewItem;
end;

function TdxRibbonBackstageViewGalleryControlViewInfo.GetPainter: TdxRibbonBackstageViewGalleryControlPainter;
begin
  Result := inherited Painter as TdxRibbonBackstageViewGalleryControlPainter;
end;

function TdxRibbonBackstageViewGalleryControlViewInfo.GetPinMode: TdxRibbonBackstageViewGalleryItemPinMode;
begin
  Result := OptionsViewItem.PinMode;
end;

{ TdxRibbonBackstageViewGalleryControlController }

procedure TdxRibbonBackstageViewGalleryControlController.KeyDown(AKey: Word; AShift: TShiftState);
begin
  case AKey of
    VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN:
      if PinMode = bgipmButton then
        ProcessNavigationKey(AKey, AShift)
      else
        inherited KeyDown(AKey, AShift);

    VK_SPACE, VK_RETURN:
      if not KeyPressed then
      begin
        KeyPressedCode := AKey;
        KeyPressed := True;
      end;
  end;
end;

procedure TdxRibbonBackstageViewGalleryControlController.KeyUp(AKey: Word; AShift: TShiftState);
begin
  case AKey of
    VK_SPACE, VK_RETURN:
      if KeyPressedCode = AKey then
      begin
        KeyPressedCode := 0;
        KeyPressed := False;
        ProcessItemPartClick(KeySelectedItem, KeySelectedItemPartIndex);
      end;
  end;
end;

procedure TdxRibbonBackstageViewGalleryControlController.ProcessItemClick(AItem: TdxGalleryControlItem; X, Y: Integer);
var
  ABackstageViewGalleryItem: TdxRibbonBackstageViewGalleryItem;
begin
  if AItem <> nil then
  begin
    ABackstageViewGalleryItem := TdxRibbonBackstageViewGalleryItem(AItem);
    ProcessItemPartClick(ABackstageViewGalleryItem, ABackstageViewGalleryItem.ViewInfo.GetPartAtPos(Point(X, Y)));
  end;
end;

procedure TdxRibbonBackstageViewGalleryControlController.ProcessItemPartClick(
  AItem: TdxRibbonBackstageViewGalleryItem; APartIndex: Integer);
begin
  case APartIndex of
    bvgipPin:
      AItem.Pinned := not AItem.Pinned;
    bvgipItem:
      Gallery.ClickItem(AItem);
  end;
end;

procedure TdxRibbonBackstageViewGalleryControlController.ProcessNavigationKey(AKey: Word; AShift: TShiftState);

  function TrySelectItem(AItem: TdxRibbonBackstageViewGalleryItem; APartIndex: Integer): Boolean;
  begin
    Result := (AItem <> nil) and (APartIndex >= 0) and (APartIndex < AItem.ViewInfo.PartCount);
    if Result then
    begin
      KeySelectedItem := AItem;
      KeySelectedItemPartIndex := APartIndex;
    end;
  end;

var
  AItem: TdxRibbonBackstageViewGalleryItem;
  AItemPos, ANextItemPos: TPoint;
begin
  AItem := GetStartItemForKeyboardNavigation as TdxRibbonBackstageViewGalleryItem;
  AItemPos := GetItemPosition(AItem);
  case AKey of
    VK_RIGHT, VK_DOWN:
      if not TrySelectItem(AItem, KeySelectedItemPartIndex + 1) then
      begin
        ANextItemPos := AItemPos;
        GetNextItem(ANextItemPos, IfThen(AKey = VK_RIGHT, 1), IfThen(AKey = VK_DOWN, 1));
        if not cxPointIsEqual(ANextItemPos, AItemPos) then
          TrySelectItem(TdxRibbonBackstageViewGalleryItem(NavigationMatrix.Values[ANextItemPos.X, ANextItemPos.Y]), 0);
      end;

    VK_LEFT, VK_UP:
      if not TrySelectItem(AItem, KeySelectedItemPartIndex - 1) then
      begin
        ANextItemPos := AItemPos;
        GetNextItem(ANextItemPos, IfThen(AKey = VK_LEFT, -1), IfThen(AKey = VK_UP, -1));
        if not cxPointIsEqual(ANextItemPos, AItemPos) then
        begin
          AItem := TdxRibbonBackstageViewGalleryItem(NavigationMatrix.Values[ANextItemPos.X, ANextItemPos.Y]);
          if AItem <> nil then
            TrySelectItem(AItem, AItem.ViewInfo.PartCount - 1);
        end;
      end;
  end;
end;

procedure TdxRibbonBackstageViewGalleryControlController.UpdateMouseHoveredItem(const P: TPoint);
begin
  inherited UpdateMouseHoveredItem(P);
  if MouseHoveredItem <> nil then
    MouseHoveredItemPartIndex := MouseHoveredItem.ViewInfo.GetPartAtPos(P);
end;

procedure TdxRibbonBackstageViewGalleryControlController.CheckPartIndex(
  var APartIndex: Integer; AItem: TdxRibbonBackstageViewGalleryItem);
begin
  if AItem <> nil then  
    APartIndex := Max(-1, Min(APartIndex, AItem.ViewInfo.PartCount - 1))
  else
    APartIndex := -1;
end;

function TdxRibbonBackstageViewGalleryControlController.GetKeySelectedItem: TdxRibbonBackstageViewGalleryItem;
begin
  Result := inherited KeySelectedItem as TdxRibbonBackstageViewGalleryItem;
end;

function TdxRibbonBackstageViewGalleryControlController.GetMouseHoveredItem: TdxRibbonBackstageViewGalleryItem;
begin
  Result := inherited MouseHoveredItem as TdxRibbonBackstageViewGalleryItem; 
end;

function TdxRibbonBackstageViewGalleryControlController.GetOwnerControl: TdxCustomRibbonBackstageViewGalleryControl;
begin
  Result := inherited Owner as TdxCustomRibbonBackstageViewGalleryControl;
end;

function TdxRibbonBackstageViewGalleryControlController.GetPinMode: TdxRibbonBackstageViewGalleryItemPinMode;
begin
  Result := Owner.OptionsView.Item.PinMode;
end;

procedure TdxRibbonBackstageViewGalleryControlController.SetKeySelectedItem(AValue: TdxRibbonBackstageViewGalleryItem);
begin
  inherited KeySelectedItem := AValue;
end;

procedure TdxRibbonBackstageViewGalleryControlController.SetKeySelectedItemPartIndex(AValue: Integer);
begin
  CheckPartIndex(AValue, KeySelectedItem);
  if FKeySelectedItemPartIndex <> AValue then
  begin  
    FKeySelectedItemPartIndex := AValue;
    InvalidateItem(KeySelectedItem);    
  end;
end;

procedure TdxRibbonBackstageViewGalleryControlController.SetMouseHoveredItem(AValue: TdxRibbonBackstageViewGalleryItem);
begin
  inherited MouseHoveredItem := AValue;
end;

procedure TdxRibbonBackstageViewGalleryControlController.SetMouseHoveredItemPartIndex(AValue: Integer);
begin
  CheckPartIndex(AValue, MouseHoveredItem);
  if FMouseHoveredItemPartIndex <> AValue then
  begin
    FMouseHoveredItemPartIndex := AValue;
    InvalidateItem(MouseHoveredItem);
  end;
end;

{ TdxRibbonBackstageViewGalleryControlPainter }

procedure TdxRibbonBackstageViewGalleryControlPainter.DrawBackground(ACanvas: TcxCanvas; const ABounds: TRect);
begin
  if Skin <> nil then
    Skin.DrawBackground(ACanvas.Handle, ABounds, DXBAR_BACKSTAGEVIEW_GALLERYCONTROL)
  else
    inherited DrawBackground(ACanvas, ABounds);
end;

procedure TdxRibbonBackstageViewGalleryControlPainter.DrawBorder(ACanvas: TcxCanvas; const ABounds: TRect);
begin
  if Skin <> nil then
    ACanvas.FrameRect(ABounds, Skin.GetPartColor(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_BORDER))
  else
    LookAndFeelPainter.DrawBorder(ACanvas, ABounds);
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetBorderSize: Integer;
begin
  if Skin <> nil then
    Result := Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_BORDER)
  else
    Result := LookAndFeelPainter.BorderSize;
end;

procedure TdxRibbonBackstageViewGalleryControlPainter.DrawGroupHeader(ACanvas: TcxCanvas; const AViewInfo: TdxGalleryGroupViewInfo);
begin
  if Skin <> nil then
  begin
    Skin.DrawBackground(ACanvas.Handle, AViewInfo.CaptionRect, DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_GROUPHEADER);
    DrawGroupHeaderText(ACanvas, AViewInfo);
  end
  else
    inherited DrawGroupHeader(ACanvas, AViewInfo);
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetGroupHeaderContentOffsets: TRect;
begin
  if Skin <> nil then
    Result := Skin.GetContentOffsets(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_GROUPHEADER)
  else
    Result := inherited GetGroupHeaderContentOffsets;
end;

procedure TdxRibbonBackstageViewGalleryControlPainter.DrawItem(ACanvas: TcxCanvas; AViewInfo: TdxGalleryItemViewInfo);
var
  AItemViewInfo: TdxRibbonBackstageViewGalleryItemViewInfo;
begin
  inherited DrawItem(ACanvas, AViewInfo);
  AItemViewInfo := TdxRibbonBackstageViewGalleryItemViewInfo(AViewInfo);
  if AItemViewInfo.PinMode <> bgipmNone then
    DrawItemPin(ACanvas, AItemViewInfo);
end;

procedure TdxRibbonBackstageViewGalleryControlPainter.DrawItemPin(
  ACanvas: TcxCanvas; AViewInfo: TdxRibbonBackstageViewGalleryItemViewInfo);
const
  PinPartMap: array[Boolean] of Integer = (
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINBUTTONGLYPH, DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINTAG
  );
var
  AState: TdxGalleryItemViewState;
begin
  AState := AViewInfo.PartState[bvgipPin];
  if Skin <> nil then
  begin
    AState.Pressed := False;
    Skin.DrawBackground(ACanvas.Handle, AViewInfo.Parts[bvgipPin],
      PinPartMap[AViewInfo.PinMode = bgipmTag], GetPartState(AState));
  end
  else
  begin
    ACanvas.SaveClipRegion;
    try
      ACanvas.IntersectClipRect(AViewInfo.Parts[bvgipPin]);
      LookAndFeelPainter.DrawPin(ACanvas, cxRectCenter(AViewInfo.Parts[bvgipPin], 13, 13),
        LookAndFeelPainter.GetGalleryItemCaptionTextColor(AState), AState.Checked);
    finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

procedure TdxRibbonBackstageViewGalleryControlPainter.DrawItemSelection(ACanvas: TcxCanvas; AViewInfo: TdxGalleryItemViewInfo);

  procedure DrawPartSelection(ACanvas: TcxCanvas; const R: TRect; const AState: TdxGalleryItemViewState; APartId: Integer);
  begin
    if Skin <> nil then
      Skin.DrawBackground(ACanvas.Handle, R, APartId, GetPartState(AState))
    else
      LookAndFeelPainter.DrawGalleryItemSelection(ACanvas, R, AState);
  end;

var
  AItemViewInfo: TdxRibbonBackstageViewGalleryItemViewInfo;
begin
  AItemViewInfo := TdxRibbonBackstageViewGalleryItemViewInfo(AViewInfo);
  if AItemViewInfo.PinMode = bgipmButton then
  begin
    DrawPartSelection(ACanvas, AItemViewInfo.Parts[bvgipItem],
      AItemViewInfo.PartState[bvgipItem], DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEM);
    DrawPartSelection(ACanvas, AItemViewInfo.Parts[bvgipPin],
      AItemViewInfo.PartState[bvgipPin], DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINBUTTON);
  end
  else
    DrawPartSelection(ACanvas, AItemViewInfo.Bounds, AItemViewInfo.State, DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEM);
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetPinButtonSize: TSize;
var
  AValue: Integer;
begin
  if Skin <> nil then
    AValue := Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINBUTTON)
  else
    AValue := 30;

  Result := cxSize(AValue, AValue);
  dxAdjustToTouchableSize(Result);
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetPinTagSize: TSize;
var
  AValue: Integer;
begin
  if Skin <> nil then
    AValue := Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINTAG)
  else
    AValue := 13;

  Result := cxSize(AValue, AValue);
  dxAdjustToTouchableSize(Result);
end;

procedure TdxRibbonBackstageViewGalleryControlPainter.DrawPinnedItemSeparator(ACanvas: TcxCanvas; const R: TRect);
begin
  if Skin <> nil then
    Skin.DrawBackground(ACanvas.Handle, R, DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_SEPARATOR)
  else
    LookAndFeelPainter.DrawBevelShape(ACanvas, R, dxbsLineCenteredVert, dxbsLowered);
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetPinnedItemSeparatorHeight: Integer;
begin
  if Skin <> nil then
    Result := Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_SEPARATOR)
  else
    Result := LookAndFeelPainter.GetBevelMinimalShapeSize(dxbsLineCenteredVert).cy;
end;

function TdxRibbonBackstageViewGalleryControlPainter.DrawItemSelectionFirst: Boolean;
begin
  Result := (Skin <> nil) or inherited DrawItemSelectionFirst;
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetGroupCaptionTextColor: TColor;
begin
  if Skin <> nil then
    Result := Skin.GetPartColor(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_GROUPHEADER_TEXTCOLOR)
  else
    Result := inherited GetGroupCaptionTextColor;
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetItemCaptionTextColor(const AState: TdxGalleryItemViewState): TColor;
begin
  if Skin <> nil then
    Result := Skin.GetPartColor(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMCAPTIONTEXTCOLOR, GetPartState(AState))
  else
    Result := inherited GetItemCaptionTextColor(AState);
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetItemDescriptionTextColor(const AState: TdxGalleryItemViewState): TColor;
begin
  if Skin <> nil then
    Result := Skin.GetPartColor(DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMDESCRIPTIONTEXTCOLOR, GetPartState(AState))
  else
    Result := inherited GetItemDescriptionTextColor(AState);
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetPartState(const AState: TdxGalleryItemViewState): Integer;
begin
  if not AState.Enabled then
    Result := DXBAR_DISABLED
  else
    if AState.Pressed then
      Result := DXBAR_PRESSED
    else
      if AState.Hover or AState.Focused then
        Result := IfThen(AState.Checked, DXBAR_HOTCHECK, DXBAR_HOT)
      else
        Result := IfThen(AState.Checked, DXBAR_CHECKED, DXBAR_NORMAL);
end;

function TdxRibbonBackstageViewGalleryControlPainter.GetSkin: IdxSkin;
begin
  if not Supports(TdxCustomRibbonBackstageViewGalleryControl(Owner).Ribbon, IdxSkin, Result) then
    Result := nil;
end;

{ TdxRibbonBackstageViewGalleryControlOptionsViewItem }

procedure TdxRibbonBackstageViewGalleryControlOptionsViewItem.DoAssign(Source: TPersistent);
begin
  inherited Assign(Source);
  if Source is TdxRibbonBackstageViewGalleryControlOptionsViewItem then
    PinMode := TdxRibbonBackstageViewGalleryControlOptionsViewItem(Source).PinMode;
end;

procedure TdxRibbonBackstageViewGalleryControlOptionsViewItem.SetPinMode(AValue: TdxRibbonBackstageViewGalleryItemPinMode);
begin
  if AValue <> PinMode then
  begin
    FPinMode := AValue;
    Changed;
  end;
end;

{ TdxRibbonBackstageViewGalleryControlOptionsViewGroup }

constructor TdxRibbonBackstageViewGalleryControlOptionsViewGroup.Create(AOwner: TdxCustomGalleryControl);
begin
  inherited Create(AOwner);
  FPinnedItemSeparator := True;
end;

procedure TdxRibbonBackstageViewGalleryControlOptionsViewGroup.DoAssign(Source: TPersistent);
begin
  inherited DoAssign(Source);
  if Source is TdxRibbonBackstageViewGalleryControlOptionsViewGroup then
    PinnedItemSeparator := TdxRibbonBackstageViewGalleryControlOptionsViewGroup(Source).PinnedItemSeparator;
end;

procedure TdxRibbonBackstageViewGalleryControlOptionsViewGroup.SetPinnedItemSeparator(AValue: Boolean);
begin
  if FPinnedItemSeparator <> AValue then
  begin
    FPinnedItemSeparator := AValue;
    Changed;
  end;
end;

{ TdxRibbonBackstageViewGalleryControlOptionsView }

constructor TdxRibbonBackstageViewGalleryControlOptionsView.Create(AOwner: TdxCustomGalleryControl);
begin
  inherited Create(AOwner);
  FGroup := CreateGroup;
end;

destructor TdxRibbonBackstageViewGalleryControlOptionsView.Destroy;
begin
  FreeAndNil(FGroup);
  inherited Destroy;
end;

function TdxRibbonBackstageViewGalleryControlOptionsView.CreateGroup: TdxRibbonBackstageViewGalleryControlOptionsViewGroup;
begin
  Result := TdxRibbonBackstageViewGalleryControlOptionsViewGroup.Create(Owner);
end;

function TdxRibbonBackstageViewGalleryControlOptionsView.CreateItem: TdxGalleryControlOptionsItem;
begin
  Result := TdxRibbonBackstageViewGalleryControlOptionsViewItem.Create(Owner);
end;

procedure TdxRibbonBackstageViewGalleryControlOptionsView.DoAssign(Source: TPersistent);
begin
  inherited DoAssign(Source);
  if Source is TdxRibbonBackstageViewGalleryControlOptionsView then
    Group := TdxRibbonBackstageViewGalleryControlOptionsView(Source).Group;
end;

function TdxRibbonBackstageViewGalleryControlOptionsView.GetItem: TdxRibbonBackstageViewGalleryControlOptionsViewItem;
begin
  Result := inherited Item as TdxRibbonBackstageViewGalleryControlOptionsViewItem;
end;

procedure TdxRibbonBackstageViewGalleryControlOptionsView.SetGroup(AValue: TdxRibbonBackstageViewGalleryControlOptionsViewGroup);
begin
  FGroup.Assign(AValue);
end;

procedure TdxRibbonBackstageViewGalleryControlOptionsView.SetItem(AValue: TdxRibbonBackstageViewGalleryControlOptionsViewItem);
begin
  inherited Item := AValue;
end;

{ TdxRibbonBackstageViewGalleryControlSizeGrip }

function TdxRibbonBackstageViewGalleryControlSizeGrip.GetRibbon: TdxCustomRibbon;
begin
  if Parent is TdxCustomRibbonBackstageViewGalleryControl then
    Result := TdxCustomRibbonBackstageViewGalleryControl(Parent).Ribbon
  else
    Result := nil;
end;

{ TdxRibbonBackstageViewGalleryControlScrollBar }

function TdxRibbonBackstageViewGalleryControlScrollBar.GetRibbon: TdxCustomRibbon;
begin
  if Parent is TdxCustomRibbonBackstageViewGalleryControl then
    Result := TdxCustomRibbonBackstageViewGalleryControl(Parent).Ribbon
  else
    Result := nil;
end;

{ TdxCustomRibbonBackstageViewGalleryControl }

constructor TdxCustomRibbonBackstageViewGalleryControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  if IsDesigning then
    Ribbon := FindRibbonForComponent(Self);
end;

destructor TdxCustomRibbonBackstageViewGalleryControl.Destroy;
begin
  Ribbon := nil;
  inherited Destroy;
end;

function TdxCustomRibbonBackstageViewGalleryControl.CreateController: TdxGalleryControlController;
begin
  Result := TdxRibbonBackstageViewGalleryControlController.Create(Self);
end;

function TdxCustomRibbonBackstageViewGalleryControl.CreateGallery: TdxGalleryControlStructure;
begin
  Result := TdxRibbonBackstageViewGallery.Create(Self);
end;

function TdxCustomRibbonBackstageViewGalleryControl.CreateOptionsBehavior: TdxGalleryControlOptionsBehavior;
begin
  Result := TdxRibbonBackstageViewGalleryControlOptionsBehavior.Create(Self);
end;

function TdxCustomRibbonBackstageViewGalleryControl.CreateOptionsView: TdxGalleryControlOptionsView;
begin
  Result := TdxRibbonBackstageViewGalleryControlOptionsView.Create(Self);
end;

function TdxCustomRibbonBackstageViewGalleryControl.CreatePainter: TdxGalleryControlPainter;
begin
  Result := TdxRibbonBackstageViewGalleryControlPainter.Create(Self);
end;

function TdxCustomRibbonBackstageViewGalleryControl.CreateViewInfo: TdxGalleryControlViewInfo;
begin
  Result := TdxRibbonBackstageViewGalleryControlViewInfo.Create(Self);
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.DoClickItem(AItem: TdxGalleryItem);
begin
  inherited DoClickItem(AItem);
  if Assigned(OnItemClick) then
    OnItemClick(Self, AItem as TdxRibbonBackstageViewGalleryItem);
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.DrawBorder(ACanvas: TcxCanvas);
begin
  Painter.DrawBorder(ACanvas, Bounds);
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetBorderSize: Integer;
begin
  if BorderStyle = cxcbsDefault then
    Result := Painter.GetBorderSize
  else
    Result := 0;
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.Notification(AComponent: TComponent; AOperation: TOperation);
begin
  inherited Notification(AComponent, AOperation);
  if AOperation = opRemove then
  begin
    if AComponent = Ribbon then
      Ribbon := nil;
  end;
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.ColorSchemeChangeHandler(Sender: TObject; const AEventArgs);
begin
  LayoutChanged;
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetController: TdxRibbonBackstageViewGalleryControlController;
begin
  Result := inherited Controller as TdxRibbonBackstageViewGalleryControlController;
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetGallery: TdxRibbonBackstageViewGallery;
begin
  Result := inherited Gallery as TdxRibbonBackstageViewGallery;
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetOptionsBehavior: TdxRibbonBackstageViewGalleryControlOptionsBehavior;
begin
  Result := inherited OptionsBehavior as TdxRibbonBackstageViewGalleryControlOptionsBehavior;
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetOptionsView: TdxRibbonBackstageViewGalleryControlOptionsView;
begin
  Result := inherited OptionsView as TdxRibbonBackstageViewGalleryControlOptionsView;
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetPainter: TdxRibbonBackstageViewGalleryControlPainter;
begin
  Result := inherited Painter as TdxRibbonBackstageViewGalleryControlPainter;
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetScrollBarClass(AKind: TScrollBarKind): TcxControlScrollBarClass;
begin
  Result := TdxRibbonBackstageViewGalleryControlScrollBar;
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetSizeGripClass: TcxSizeGripClass;
begin
  Result := TdxRibbonBackstageViewGalleryControlSizeGrip;
end;

function TdxCustomRibbonBackstageViewGalleryControl.GetViewInfo: TdxRibbonBackstageViewGalleryControlViewInfo;
begin
  Result := inherited ViewInfo as TdxRibbonBackstageViewGalleryControlViewInfo;
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.SetGallery(AValue: TdxRibbonBackstageViewGallery);
begin
  inherited Gallery := AValue;
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.SetOptionsBehavior(AValue: TdxRibbonBackstageViewGalleryControlOptionsBehavior);
begin
  inherited OptionsBehavior := AValue;
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.SetOptionsView(AValue: TdxRibbonBackstageViewGalleryControlOptionsView);
begin
  inherited OptionsView := AValue;
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.SetRibbon(AValue: TdxCustomRibbon);
begin
  if FRibbon <> AValue then
  begin
    if FRibbon <> nil then
    begin
      if FRibbon.ColorSchemeHandlers <> nil then
        FRibbon.ColorSchemeHandlers.Remove(ColorSchemeChangeHandler);
      FRibbon.RemoveFreeNotification(Self);
      FRibbon := nil;
    end;
    if AValue <> nil then
    begin
      FRibbon := AValue;
      FRibbon.FreeNotification(Self);
      FRibbon.ColorSchemeHandlers.Add(ColorSchemeChangeHandler);
    end;
    LayoutChanged;
  end;
end;

procedure TdxCustomRibbonBackstageViewGalleryControl.CMHintShow(var Message: TCMHintShow);
var
  AItem: TdxRibbonBackstageViewGalleryItem;
begin
  if ItemShowHint then
  begin
    AItem := Gallery.Groups.GetItemAtPos(Message.HintInfo.CursorPos);
    if (AItem <> nil) and AItem.Enabled then
    begin
      Message.HintInfo.CursorRect := AItem.ViewInfo.Bounds;
      Message.HintInfo.HintStr := AItem.ViewInfo.GetPartHint(AItem.ViewInfo.GetPartAtPos(Message.HintInfo.CursorPos));
      Message.Result := 0;
    end;
  end;
end;

initialization
  RegisterClasses([TdxRibbonBackstageViewGalleryGroup, TdxRibbonBackstageViewGalleryItem]);
end.
