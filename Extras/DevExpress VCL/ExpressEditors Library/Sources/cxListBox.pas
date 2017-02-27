{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{       ExpressCommonLibrary                                         }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSCOMMONLIBRARY AND ALL          }
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

unit cxListBox;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Windows, Messages, dxCore, Math, Types,
  Classes, Controls, Forms, Menus, StdCtrls, SysUtils, Graphics, ImgList,
  cxClasses, cxControls, cxContainer, cxDataUtils, cxGraphics, cxLookAndFeels,
  cxScrollBar, cxLookAndFeelPainters, dxCustomHint, cxEdit;

type
  TcxListBox = class;

  { TcxInnerListBox }

  TcxInnerListBox = class(TcxCustomInnerListBox)
  private
    function GetContainer: TcxListBox;
    procedure SetContainer(Value: TcxListBox);
    procedure WMLButtonDown(var Message: TWMLButtonDown); message WM_LBUTTONDOWN;
  protected
    procedure Click; override;
    procedure CreateWindowHandle(const Params: TCreateParams); override;
    procedure DrawItem(Index: Integer; Rect: TRect; State: TOwnerDrawState); override;
    property Container: TcxListBox read GetContainer write SetContainer;
  public
    function ExecuteAction(Action: TBasicAction): Boolean; override;
    function UpdateAction(Action: TBasicAction): Boolean; override;
    function CanFocus: Boolean; override;
  end;

  TcxInnerListBoxClass = class of TcxInnerListBox;

  { TcxListBox }

  TcxListBoxDrawItemEvent = procedure(AControl: TcxListBox; ACanvas: TcxCanvas;
    AIndex: Integer; ARect: TRect; AState: TOwnerDrawState) of object;
  TcxListBoxMeasureItemEvent = procedure(AControl: TcxListBox; AIndex: Integer;
    var Height: Integer) of object;

  TcxListBox = class(TcxCustomEditContainer)
  private
    FInnerListBox: TcxInnerListBox;
    FIntegralHeight: Boolean;
    FIsExitProcessing: Boolean;
    FOnDrawItem: TcxListBoxDrawItemEvent;
    FOnMeasureItem: TcxListBoxMeasureItemEvent;
    procedure DoMeasureItem(Control: TWinControl; Index: Integer;
      var Height: Integer);
    function GetAutoComplete: Boolean;
    function GetAutoCompleteDelay: Cardinal;
    function GetColumns: Integer;
    function GetCount: Integer;
    function GetExtendedSelect: Boolean;
    function GetInnerListBox: TListBox;
    function GetItemHeight: Integer;
    function GetItemIndex: Integer;
    function GetItemObject: TObject;
    function GetItems: TStrings;
    function GetListStyle: TListBoxStyle;
    function GetMultiSelect: Boolean;
    function GetReadOnly: Boolean;
    function GetSelCount: Integer;
    function GetSelected(Index: Integer): Boolean;
    function GetSorted: Boolean;
    function GetTopIndex: Integer;
    procedure SetAutoComplete(Value: Boolean);
    procedure SetAutoCompleteDelay(Value: Cardinal);
    procedure SetColumns(Value: Integer);
    procedure SetExtendedSelect(Value: Boolean);
    procedure SetItemHeight(Value: Integer);
    procedure SetItemIndex(Value: Integer);
    procedure SetItemObject(Value: TObject);
    procedure SetItems(Value: TStrings);
    procedure SetListStyle(Value: TListBoxStyle);
    procedure SetMultiSelect(Value: Boolean);
    procedure SetOnMeasureItem(Value: TcxListBoxMeasureItemEvent);
    procedure SetReadOnly(Value: Boolean);
    procedure SetSelected(Index: Integer; Value: Boolean);
    procedure SetSorted(Value: Boolean);
    procedure SetTopIndex(Value: Integer);
    function GetOnData: TLBGetDataEvent;
    function GetOnDataFind: TLBFindDataEvent;
    function GetOnDataObject: TLBGetDataObjectEvent;
    procedure SetCount(Value: Integer);
    procedure SetOnData(Value: TLBGetDataEvent);
    procedure SetOnDataFind(Value: TLBFindDataEvent);
    procedure SetOnDataObject(Value: TLBGetDataObjectEvent);
    function GetScrollWidth: Integer;
    function GetTabWidth: Integer;
    procedure SetIntegralHeight(Value: Boolean);
    procedure SetScrollWidth(Value: Integer);
    procedure SetTabWidth(Value: Integer);
  protected
    FDataBinding: TcxCustomDataBinding;
    procedure DataChange; override;
    procedure DoExit; override;
    procedure FontChanged; override;
    function IsInternalControl(AControl: TControl): Boolean; override;
    function IsReadOnly: Boolean; override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
    procedure UpdateData; override;
    function CanResize(var NewWidth, NewHeight: Integer): Boolean; override;
    procedure DoSetSize; override;
    procedure WndProc(var Message: TMessage); override;
    function DrawItem(ACanvas: TcxCanvas; AIndex: Integer; const ARect: TRect;
      AState: TOwnerDrawState): Boolean; virtual;
    function GetDataBindingClass: TcxCustomDataBindingClass; virtual;
    function GetInnerListBoxClass: TcxInnerListBoxClass; virtual;
    procedure GetOptimalHeight(var ANewHeight: Integer);
    property DataBinding: TcxCustomDataBinding read FDataBinding;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function ExecuteAction(Action: TBasicAction): Boolean; override;
    function UpdateAction(Action: TBasicAction): Boolean; override;
    procedure AddItem(AItem: string; AObject: TObject);
    procedure Clear;
    procedure ClearSelection;
    procedure DeleteSelected;
    function ItemAtPos(const APos: TPoint; AExisting: Boolean): Integer;
    function ItemRect(Index: Integer): TRect;
    function ItemVisible(Index: Integer): Boolean;
    procedure SelectAll;
    procedure CopySelection(ADestination: TCustomListControl);
    procedure MoveSelection(ADestination: TCustomListControl);
    property Count: Integer read GetCount write SetCount;
    property InnerListBox: TListBox read GetInnerListBox;
    property ItemIndex: Integer read GetItemIndex write SetItemIndex;
    property ItemObject: TObject read GetItemObject write SetItemObject;
    property SelCount: Integer read GetSelCount;
    property Selected[Index: Integer]: Boolean read GetSelected write SetSelected;
    property TopIndex: Integer read GetTopIndex write SetTopIndex;
  published
    property Anchors;
    property AutoComplete: Boolean read GetAutoComplete write SetAutoComplete
      default True;
    property AutoCompleteDelay: Cardinal read GetAutoCompleteDelay
      write SetAutoCompleteDelay default cxDefaultAutoCompleteDelay;
    property BiDiMode;
    property Columns: Integer read GetColumns write SetColumns default 0;
    property Constraints;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property ExtendedSelect: Boolean read GetExtendedSelect
      write SetExtendedSelect default True;
    property ImeMode;
    property ImeName;
    property IntegralHeight: Boolean read FIntegralHeight
      write SetIntegralHeight default False;
    property ItemHeight: Integer read GetItemHeight write SetItemHeight;
    property Items: TStrings read GetItems write SetItems;
    property ListStyle: TListBoxStyle read GetListStyle write SetListStyle
      default lbStandard;
    property MultiSelect: Boolean read GetMultiSelect write SetMultiSelect
      default False;
    property ParentBiDiMode;
    property ParentColor default False;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ReadOnly: Boolean read GetReadOnly write SetReadOnly default False;
    property ScrollWidth: Integer read GetScrollWidth write SetScrollWidth
      default 0;
    property ShowHint;
    property Sorted: Boolean read GetSorted write SetSorted default False;
    property Style;
    property StyleDisabled;
    property StyleFocused;
    property StyleHot;
    property TabOrder;
    property TabStop;
    property TabWidth: Integer read GetTabWidth write SetTabWidth default 0;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnData: TLBGetDataEvent read GetOnData write SetOnData;
    property OnDataFind: TLBFindDataEvent read GetOnDataFind write SetOnDataFind;
    property OnDataObject: TLBGetDataObjectEvent read GetOnDataObject
      write SetOnDataObject;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnDrawItem: TcxListBoxDrawItemEvent read FOnDrawItem
      write FOnDrawItem;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMeasureItem: TcxListBoxMeasureItemEvent read FOnMeasureItem
      write SetOnMeasureItem;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnStartDock;
    property OnStartDrag;
  end;

  { TdxCustomListBoxItem }

  TdxCustomListBox = class;
  TdxCustomListBoxItems = class;

  TdxCustomListBoxItem = class(TObject)
  private
    FCaption: string;
    FData: TObject;
    FImageIndex: Integer;
    FHasSeparator: Boolean;
    FOwner: TdxCustomListBoxItems;
    function GetIndex: Integer;
    procedure SetCaption(const ACaption: string);
    procedure SetImageIndex(AValue: Integer);
    procedure SetHasSeparator(const Value: Boolean);
  protected
    procedure Changed;
  public
    constructor Create(AOwner: TdxCustomListBoxItems); virtual;
    //
    property Caption: string read FCaption write SetCaption;
    property Data: TObject read FData write FData;
    property HasSeparator: Boolean read FHasSeparator write SetHasSeparator;
    property ImageIndex: Integer read FImageIndex write SetImageIndex;
    property Index: Integer read GetIndex;
  end;

  { TdxCustomListBoxItems }

  TdxCustomListBoxItems = class(TcxObjectList)
  private
    FLockCount: Integer;
    FOwnerControl: TdxCustomListBox;
    FSorted: Boolean;
    function FindInSortedList(const ACaption: string): Integer;
    function GetItem(Index: Integer): TdxCustomListBoxItem;
    procedure SetSorted(AValue: Boolean);
  protected
    procedure Changed; virtual;
    procedure Notify(Ptr: Pointer; Action: TListNotification); override;

    property LockCount: Integer read FLockCount;
  public
    constructor Create(AOwnerControl: TdxCustomListBox); virtual;
    function Add(const ACaption: string; AImageIndex: Integer = -1;
      AData: TObject = nil; AHasSeparator: Boolean = False): TdxCustomListBoxItem;
    function AddObject(const ACaption: string; AData: TObject): TdxCustomListBoxItem;
    function AddSeparator: TdxCustomListBoxItem;
    procedure BeginUpdate;
    procedure CancelUpdate;
    procedure EndUpdate;
    function IndexOfCaption(const ACaption: string; ACaseSensitive: Boolean = True): Integer;
    function IndexOfObject(AObject: TObject): Integer;
    function Insert(AIndex: Integer; const ACaption: string;
      AImageIndex: Integer = -1; AData: TObject = nil;
      AHasSeparator: Boolean = False): TdxCustomListBoxItem;
    function IsValidIndex(AIndex: Integer): Boolean;
    procedure LoadFromStrings(AStrings: TStrings);
    //
    property Items[Index: Integer]: TdxCustomListBoxItem read GetItem; default;
    property Sorted: Boolean read FSorted write SetSorted;
  end;
  TdxCustomListBoxItemsClass = class of TdxCustomListBoxItems;

  { TdxCustomListBoxHintHelper }

  TdxCustomListBoxHintHelper = class(TcxControlHintHelper)
  private
    FOwnerControl: TdxCustomListBox;
  protected
    function GetOwnerControl: TcxControl; override;
    function PtInCaller(const P: TPoint): Boolean; override;
  public
    constructor Create(AOwnerControl: TdxCustomListBox); virtual;
  end;

  { TdxCustomListBox }

  TdxCustomListBox = class(TcxControl, IcxMouseTrackingCaller, IcxMouseTrackingCaller2)
  private
    FChangeLink: TChangeLink;
    FHintHelper: TdxCustomListBoxHintHelper;
    FHotIndex: Integer;
    FImages: TCustomImageList;
    FIncrementalSearch: Boolean;
    FItemHeight: Integer;
    FItemIndex: Integer;
    FItems: TdxCustomListBoxItems;
    FLoopedNavigation: Boolean;
    FSearchText: string;
    FStartIncrementalSearch: Cardinal;
    FTopIndex: Integer;
    function GetCount: Integer;
    function GetImagesAreaRect: TRect;
    function GetImagesAreaSize: Integer;
    function GetIsLocked: Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
    function GetItemsHeight(Index: Integer): Integer;
    function GetMaxTopIndex: Integer;
    function GetPageSize: Integer;
    function GetSorted: Boolean;
    function GetTopIndex: Integer;
    procedure DoImageListChanged(Sender: TObject);
    procedure SetHotIndex(AValue: Integer);
    procedure SetImages(AValue: TCustomImageList);
    procedure SetItemHeight(AValue: Integer);
    procedure SetItemIndex(AIndex: Integer);
    procedure SetSorted(AValue: Boolean);
    procedure SetTopIndex(AValue: Integer);
    // IcxMouseTrackingCaller
    function PtInCaller(const P: TPoint): Boolean;
    procedure IcxMouseTrackingCaller.MouseLeave = TrackingCallerMouseLeave;
    procedure IcxMouseTrackingCaller2.MouseLeave = TrackingCallerMouseLeave;
  protected
    procedure AdjustItemFont(AFont: TFont; AItem: TdxCustomListBoxItem; AState: TcxButtonState); virtual;
    procedure BoundsChanged; override;
    function CanProcessIncSearch(Key: Char): Boolean;
    function CanShowHint(AItemIndex: Integer; out AItemRect, AItemTextRect: TRect): Boolean; virtual;
    function CanStartIncSearch(Key: Char): Boolean;
    procedure CheckFocusedItemIndex; virtual;
    procedure CheckTopItemIndex; virtual;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure DoLayoutChanged; virtual;
    procedure EraseBackground(DC: HDC); override;
    function GetHasSeparator(Index: Integer): Boolean;
    function GetItemsClass: TdxCustomListBoxItemsClass; virtual;
    function HasBackground: Boolean; override;
    procedure InitScrollBarsParameters; override;
    procedure InvalidateItem(AIndex: Integer);
    procedure InvalidateItems(const AIndex1, AIndex2: Integer);
    function IsIncSearchChar(AChar: Char): Boolean; virtual;
    function IsStartIncSearchChar(AChar: Char): Boolean; virtual;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
    procedure MeasureItemHeight(AIndex: Integer; var AHeight: Integer); virtual;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseEnter(AControl: TControl); override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    function NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    function ProcessKeyPress(var Key: Char): Boolean; virtual;
    function ProcessNavigationKey(var Key: Word; Shift: TShiftState): Boolean; virtual;
    procedure Scroll(AScrollBarKind: TScrollBarKind;
      AScrollCode: TScrollCode; var AScrollPos: Integer); override;
    procedure TrackingCallerMouseLeave;
    procedure UpdateHintState;
    procedure UpdateHotState;

    function GetBackgroundColor: TColor;
    function GetImageOffsets: TRect; virtual;
    function GetImageSize: TSize; virtual;
    function GetItemImageRect(const AItemRect: TRect): TRect;
    procedure GetItemPartsRects(AIndex: Integer; const R: TRect; out AItemRect, ASeparatorRect: TRect);
    function GetItemRect(AItemIndex: Integer; const APrevItemRect: TRect): TRect;
    function GetItemState(AIndex: Integer): TcxButtonState; virtual;
    function GetItemTextRect(const AItemRect: TRect): TRect;
    function GetTextColor(AItem: TdxCustomListBoxItem; AState: TcxButtonState): TColor; virtual;
    function GetTextFlags: Integer; virtual;
    function GetTextOffsets: TRect; virtual;

    procedure DrawBackground; virtual;
    procedure DrawItem(const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState); virtual;
    procedure DrawItemBackground(const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState); virtual;
    procedure DrawItemImage(const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState); virtual;
    procedure DrawItemText(const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState); virtual;
    procedure DrawItemSeparator(const R: TRect); virtual;
    procedure Paint; override;

    //incremental search
    procedure ClearIncrementalSearch; virtual;
    function DoIncrementalSearch(var Key: Char): Boolean; virtual;
    function FocusNextItemWithText(const AText: string): Boolean;
    function FocusItemWithText(const AText: string; AStartIndex, AFinishIndex: Integer): Boolean;
    function GetValidIndex(AIndex: Integer): Integer;


    property HintHelper: TdxCustomListBoxHintHelper read FHintHelper;
    property HotIndex: Integer read FHotIndex write SetHotIndex;
    property ImageOffsets: TRect read GetImageOffsets;
    property ImagesAreaRect: TRect read GetImagesAreaRect;
    property ImagesAreaSize: Integer read GetImagesAreaSize;
    property ImageSize: TSize read GetImageSize;
    property IsLocked: Boolean read GetIsLocked;
    property ItemsHeight[Index: Integer]: Integer read GetItemsHeight;
    property MaxTopIndex: Integer read GetMaxTopIndex;
    property PageSize: Integer read GetPageSize;
    property SearchText: string read FSearchText write FSearchText;
    property TextOffsets: TRect read GetTextOffsets;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function Add(const ACaption: string; AImageIndex: Integer = -1): Integer;
    function AddItem(const ACaption: string; AObject: TObject; AImageIndex: Integer = -1): Integer;
    function CalculateContentSize(AMaxVisibleItemsCount: Integer): TSize; virtual;
    function CalculateItemHeight: Integer; virtual;

    procedure BeginUpdate;
    procedure Clear;
    procedure EndUpdate;
    function ItemAtPos(const APoint: TPoint; AExistOnly: Boolean = False): Integer; virtual;
    function ItemRect(AIndex: Integer): TRect;
    procedure LayoutChanged;
    procedure MakeVisible(AIndex: Integer);
    function Remove(AObject: TObject): Integer;

    property Count: Integer read GetCount;
    property Images: TCustomImageList read FImages write SetImages;
    property IncrementalSearch: Boolean read FIncrementalSearch write FIncrementalSearch;
    property ItemHeight: Integer read FItemHeight write SetItemHeight;
    property ItemIndex: Integer read FItemIndex write SetItemIndex;
    property Items: TdxCustomListBoxItems read FItems write FItems;
    property LoopedNavigation: Boolean read FLoopedNavigation write FLoopedNavigation;
    property TopIndex: Integer read GetTopIndex write SetTopIndex;
    property Sorted: Boolean read GetSorted write SetSorted;
    property Color;
    property Font;
    property LookAndFeel;
    property OnClick;
    property OnDblClick;
  end;

  { TdxCustomDropDownInnerListBox }

  TdxCustomDropDownListBoxCloseUpEvent = procedure (Sender: TObject; AClosedViaKeyboard: Boolean) of object;
  TdxCustomDropDownListBoxSelectedEvent = procedure (Sender: TObject;
    AItem: TdxCustomListBoxItem; ASelectedViaKeyboard: Boolean) of object;

  TdxCustomDropDownInnerListBox = class(TdxCustomListBox)
  private
    FDefaultItemIndex: Integer;
    FPrevMousePosition: TPoint;
    FOnSelectItem: TdxCustomDropDownListBoxSelectedEvent;
    procedure SetDefaultItemIndex(AValue: Integer);
  protected
    procedure AdjustItemFont(AFont: TFont; AItem: TdxCustomListBoxItem; AState: TcxButtonState); override;
    procedure DoLayoutChanged; override;
    procedure DoSelectItem(ASelectedViaKeyboard: Boolean); virtual;
    procedure DrawBackground; override;
    procedure DrawItemBackground(const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState); override;
    function GetBorderSize: Integer; override;
    function GetImageOffsets: TRect; override;
    function GetImageSize: TSize; override;
    function GetTextColor(AItem: TdxCustomListBoxItem; AState: TcxButtonState): TColor; override;
    function GetTextOffsets: TRect; override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    function ProcessNavigationKey(var Key: Word; Shift: TShiftState): Boolean; override;
  public
    constructor Create(AOwner: TComponent); override;
    //
    property DefaultItemIndex: Integer read FDefaultItemIndex write SetDefaultItemIndex default -1;
    property OnSelectItem: TdxCustomDropDownListBoxSelectedEvent read FOnSelectItem write FOnSelectItem;
  end;

  { TdxCustomDropDownListBox }

  TdxCustomDropDownListBox = class(TcxCustomPopupWindow)
  private
    FDisplayRowsCount: Cardinal;
    FInnerListBox: TdxCustomDropDownInnerListBox;
    FMaxWidth: Cardinal;
    FMinWidth: Cardinal;
    FOnCloseUp: TdxCustomDropDownListBoxCloseUpEvent;
    FOnSelect: TdxCustomDropDownListBoxSelectedEvent;
    procedure ItemSelected(Sender: TObject; AItem: TdxCustomListBoxItem; ASelectedViaKeyboard: Boolean);
    function GetCount: Integer;
    function GetImages: TCustomImageList;
    function GetItemHeight: Integer;
    function GetItemIndex: Integer;
    function GetItems: TdxCustomListBoxItems;
    procedure SetImages(const Value: TCustomImageList);
    procedure SetItemHeight(const Value: Integer);
    procedure SetItemIndex(const Value: Integer);
  protected
    FClosedViaKeyboard: Boolean;
    procedure AdjustClientRect(var Rect: TRect); override;
    function CalculatePosition: TPoint; override;
    procedure CalculateSize; override;
    function CreateInnerListBox: TdxCustomDropDownInnerListBox; virtual;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure DoCloseUp(AClosedViaKeyboard: Boolean); virtual;
    procedure DoHide; override;
    procedure DoSelectItem(AItem: TdxCustomListBoxItem; ASelectedViaKeyboard: Boolean); virtual;
    procedure InitInnerListBox; virtual;
    procedure InitPopup; override;
  public
    constructor Create(AOwnerControl: TWinControl); override;
    constructor CreateEx(AOwnerControl: TWinControl; AOwnerParent: TcxControl);
    destructor Destroy; override;
    procedure BeginUpdate;
    procedure EndUpdate;
    function IsShortCut(var Message: TWMKey): Boolean; override;
    procedure CloseUp(AClosedViaKeyboard: Boolean); reintroduce; virtual;
    procedure Popup; reintroduce; virtual;
    procedure PopupForBounds(const ABounds: TRect; AActivateKey: Char = #0);
    //
    property Count: Integer read GetCount;
    property DisplayRowsCount: Cardinal read FDisplayRowsCount write FDisplayRowsCount;
    property Images: TCustomImageList read GetImages write SetImages;
    property ItemHeight: Integer read GetItemHeight write SetItemHeight;
    property ItemIndex: Integer read GetItemIndex write SetItemIndex;
    property Items: TdxCustomListBoxItems read GetItems;
    property InnerListBox: TdxCustomDropDownInnerListBox read FInnerListBox;
    property MaxWidth: Cardinal read FMaxWidth write FMaxWidth;
    property MinWidth: Cardinal read FMinWidth write FMinWidth;
    property OnCloseUp: TdxCustomDropDownListBoxCloseUpEvent read FOnCloseUp write FOnCloseUp;
    property OnSelect: TdxCustomDropDownListBoxSelectedEvent read FOnSelect write FOnSelect;
  end;

implementation

uses
  Variants, cxGeometry, StrUtils;

function dxCustomListBoxItemsCompare(Item1, Item2: TdxCustomListBoxItem): Integer;
begin
  Result := CompareStr(Item1.Caption, Item2.Caption);
end;

{ TcxInnerListBox }

function TcxInnerListBox.ExecuteAction(Action: TBasicAction): Boolean;
begin
  Result := inherited ExecuteAction(Action) or
    Container.FDataBinding.ExecuteAction(Action);
end;

function TcxInnerListBox.UpdateAction(Action: TBasicAction): Boolean;
begin
  Result := inherited UpdateAction(Action) or
    Container.FDataBinding.UpdateAction(Action);
end;

function TcxInnerListBox.CanFocus: Boolean;
begin
  Result := Container.CanFocus;
end;

procedure TcxInnerListBox.Click;
begin
  if Container.DataBinding.SetEditMode then
    inherited Click;
end;

procedure TcxInnerListBox.CreateWindowHandle(const Params: TCreateParams);
begin
  inherited CreateWindowHandle(Params);
  SetExternalScrollBarsParameters;
end;

procedure TcxInnerListBox.DrawItem(Index: Integer; Rect: TRect;
  State: TOwnerDrawState);
begin
  if not Container.DrawItem(Canvas, Index, Rect, State) then
    inherited DrawItem(Index, Rect, State);
end;

function TcxInnerListBox.GetContainer: TcxListBox;
begin
  Result := TcxListBox(Owner);
end;

procedure TcxInnerListBox.SetContainer(Value: TcxListBox);
begin
  FContainer := Value;
end;

procedure TcxInnerListBox.WMLButtonDown(var Message: TWMLButtonDown);
begin
  if Container.DataBinding.SetEditMode then
    inherited
  else
  begin
    SetFocus;
    with Message do
      MouseDown(mbLeft, KeysToShiftState(Keys), XPos, YPos);
  end;
end;

{ TcxListBox }

constructor TcxListBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDataBinding := GetDataBindingClass.Create(Self, Self);
  with FDataBinding do
  begin
    OnDataChange := Self.DataChange;
    OnDataSetChange := Self.DataSetChange;
    OnUpdateData := Self.UpdateData;
  end;
  FInnerListBox := GetInnerListBoxClass.Create(Self);
  FInnerListBox.BorderStyle := bsNone;
  FInnerListBox.Parent := Self;
  FInnerListBox.Container := Self;
  InnerControl := FInnerListBox;
  FInnerListBox.LookAndFeel.MasterLookAndFeel := Style.LookAndFeel;
  Width := 121;
  Height := 97;
end;

destructor TcxListBox.Destroy;
begin
  FreeAndNil(FInnerListBox);
  FreeAndNil(FDataBinding);
  inherited Destroy;
end;

function TcxListBox.ExecuteAction(Action: TBasicAction): Boolean;
begin
  Result := inherited ExecuteAction(Action) or
    FDataBinding.ExecuteAction(Action);
end;

function TcxListBox.UpdateAction(Action: TBasicAction): Boolean;
begin
  Result := inherited UpdateAction(Action) or
    FDataBinding.UpdateAction(Action);
end;

procedure TcxListBox.AddItem(AItem: string; AObject: TObject);
begin
  FInnerListBox.AddItem(AItem, AObject);
end;

procedure TcxListBox.Clear;
begin
  FInnerListBox.Clear;
end;

procedure TcxListBox.ClearSelection;
begin
  FInnerListBox.Items.BeginUpdate;
  try
    FInnerListBox.ClearSelection;
  finally
    FInnerListBox.Items.EndUpdate;
  end;
end;

procedure TcxListBox.DeleteSelected;
begin
  FInnerListBox.Items.BeginUpdate;
  try
    FInnerListBox.DeleteSelected;
  finally
    FInnerListBox.Items.EndUpdate;
  end;
end;

function TcxListBox.ItemAtPos(const APos: TPoint; AExisting: Boolean): Integer;
begin
  with FInnerListBox do
    Result := ItemAtPos(Point(APos.X - Left, APos.Y - Top), AExisting);
end;

function TcxListBox.ItemRect(Index: Integer): TRect;
begin
  Result := FInnerListBox.ItemRect(Index);
  OffsetRect(Result, FInnerListBox.Left, FInnerListBox.Top);
end;

function TcxListBox.ItemVisible(Index: Integer): Boolean;
begin
  Result := FInnerListBox.ItemVisible(Index);
end;

procedure TcxListBox.SelectAll;
begin
  FInnerListBox.Items.BeginUpdate;
  try
    FInnerListBox.SelectAll;
  finally
    FInnerListBox.Items.EndUpdate;
  end;
end;

procedure TcxListBox.CopySelection(ADestination: TCustomListControl);
begin
  FInnerListBox.Items.BeginUpdate;
  try
    FInnerListBox.CopySelection(ADestination);
  finally
    FInnerListBox.Items.EndUpdate;
  end;
end;

procedure TcxListBox.MoveSelection(ADestination: TCustomListControl);
begin
  FInnerListBox.Items.BeginUpdate;
  try
    FInnerListBox.MoveSelection(ADestination);
  finally
    FInnerListBox.Items.EndUpdate;
  end;
end;

procedure TcxListBox.DataChange;
begin
  if DataBinding.IsDataSourceLive then
    ItemIndex := Items.IndexOf(VarToStr(DataBinding.GetStoredValue(evsText, Focused)))
  else
    ItemIndex := -1;
end;

procedure TcxListBox.DoExit;
begin
  if IsDestroying or FIsExitProcessing then
    Exit;
  FIsExitProcessing := True;
  try
    try
      DataBinding.UpdateDataSource;
    except
      SetFocus;
      raise;
    end;
    inherited DoExit;
  finally
    FIsExitProcessing := False;
  end;
end;

procedure TcxListBox.FontChanged;
begin
  inherited FontChanged;
  SetSize;
  cxRecreateControlWnd(InnerListBox);
end;

function TcxListBox.IsInternalControl(AControl: TControl): Boolean;
begin
  if FInnerListBox = nil then
    Result := True
  else
    Result := (AControl = FInnerListBox.HScrollBar) or (AControl = FInnerListBox.VScrollBar);
  Result := Result or inherited IsInternalControl(AControl);
end;

function TcxListBox.IsReadOnly: Boolean;
begin
  Result := DataBinding.IsControlReadOnly;
end;

procedure TcxListBox.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited KeyDown(Key, Shift);
  case Key of
    VK_PRIOR, VK_NEXT, VK_END, VK_HOME, VK_LEFT, VK_UP, VK_RIGHT, VK_DOWN:
      if not DataBinding.SetEditMode then
        Key := 0;
  end;
end;

procedure TcxListBox.KeyPress(var Key: Char);
begin
  inherited KeyPress(Key);
  if IsTextChar(Key) then
  begin
    if not DataBinding.SetEditMode then
      Key := #0;
  end
  else
    if Key = #27 then
      DataBinding.Reset;
end;

procedure TcxListBox.UpdateData;
begin
  if ItemIndex >= 0 then
    DataBinding.SetStoredValue(evsText, Items[ItemIndex])
  else
    DataBinding.SetStoredValue(evsText, '');
end;

function TcxListBox.CanResize(var NewWidth, NewHeight: Integer): Boolean;
begin
  Result := inherited CanResize(NewWidth, NewHeight);
  if not Result or not IntegralHeight or IsLoading then
    Exit;
  if Align in [alLeft, alRight, alClient] then
    Exit;
  GetOptimalHeight(NewHeight);
end;

procedure TcxListBox.DoSetSize;
var
  ANewHeight: Integer;
  APrevBoundsRect: TRect;
begin
  if IsLoading then
    Exit;
  APrevBoundsRect := FInnerListBox.BoundsRect;
  try
    if not IntegralHeight or (Align in [alLeft, alRight, alClient]) then
    begin
      inherited;
      Exit;
    end;
    ANewHeight := Height;
    GetOptimalHeight(ANewHeight);
    Height := ANewHeight;
    inherited;
  finally
    if not EqualRect(APrevBoundsRect, FInnerListBox.BoundsRect) and FInnerListBox.HandleAllocated then
      dxMessagesController.KillMessages(FInnerListBox.Handle, WM_MOUSEMOVE);
  end;
end;

procedure TcxListBox.WndProc(var Message: TMessage);
begin
  if FInnerListBox <> nil then
    case Message.Msg of
      LB_ADDSTRING..LB_MSGMAX:
        begin
          with TMessage(Message) do
            Result := SendMessage(FInnerListBox.Handle, Msg, WParam, LParam);
          Exit;
        end;
    end;
  inherited WndProc(Message);
  if (FInnerListBox <> nil) and (Message.Msg = WM_COMMAND) and (Message.WParamHi = LBN_SELCHANGE) then
    FInnerListBox.SetExternalScrollBarsParameters;
end;

function TcxListBox.DrawItem(ACanvas: TcxCanvas; AIndex: Integer;
  const ARect: TRect; AState: TOwnerDrawState): Boolean;
begin
  Result := Assigned(FOnDrawItem);
  if Result then
    FOnDrawItem(Self, ACanvas, AIndex, ARect, AState);
end;

function TcxListBox.GetDataBindingClass: TcxCustomDataBindingClass;
begin
  Result := TcxDataBinding;
end;

function TcxListBox.GetInnerListBoxClass: TcxInnerListBoxClass;
begin
  Result := TcxInnerListBox;
end;

procedure TcxListBox.GetOptimalHeight(var ANewHeight: Integer);

  function GetItemHeight(AIndex: Integer): Integer;
  begin
    case ListStyle of
      lbStandard, lbVirtual:
        Result := Canvas.FontHeight(Font);
      lbOwnerDrawFixed, lbVirtualOwnerDraw:
        Result := ItemHeight;
      lbOwnerDrawVariable:
        begin
          Result := ItemHeight;
          if (AIndex < Count) and Assigned(FInnerListBox.OnMeasureItem) then
            FInnerListBox.OnMeasureItem(Self, AIndex, Result);
        end;
    end;
  end;

var
  I: Integer;
  ABorderExtent: TRect;
  AItemHeight: Integer;
  AListClientSize, AListSize, AScrollBarSize: TSize;
  AScrollWidth: Integer;
  AVScrollBar: Boolean;
begin
  ABorderExtent := GetBorderExtent;
  AListClientSize.cy := ABorderExtent.Top + ABorderExtent.Bottom;
  AScrollBarSize := GetScrollBarSize;
  AScrollWidth := ScrollWidth;
  if AScrollWidth > 0 then
  Inc(AScrollWidth, 4);
  I := 0;
  repeat
    AItemHeight := GetItemHeight(I);
    AListClientSize.cy := AListClientSize.cy + AItemHeight;
    AListSize.cy := AListClientSize.cy;
    AListClientSize.cx := Width - (ABorderExtent.Left + ABorderExtent.Right);
    AVScrollBar := I + 1 < Count;
    if AVScrollBar then
      AListClientSize.cx := AListClientSize.cx - AScrollBarSize.cx;
    if AListClientSize.cx < AScrollWidth then
      AListSize.cy := AListSize.cy + AScrollBarSize.cy;
    if AListSize.cy = ANewHeight then
      Break;
    if AListSize.cy > ANewHeight then
    begin
      if I > 0 then
      begin
        AListClientSize.cy := AListClientSize.cy - AItemHeight;
        AListSize.cy := AListClientSize.cy;
        AListClientSize.cx := Width - (ABorderExtent.Left + ABorderExtent.Right);
        AVScrollBar := I < Count;
        if AVScrollBar then
          AListClientSize.cx := AListClientSize.cx - AScrollBarSize.cx;
        if AListClientSize.cx < AScrollWidth then
          AListSize.cy := AListSize.cy + AScrollBarSize.cy;
      end;
      Break;
    end;
    Inc(I);
  until False;
  ANewHeight := AListSize.cy;
end;

procedure TcxListBox.DoMeasureItem(Control: TWinControl; Index: Integer;
  var Height: Integer);
begin
  FOnMeasureItem(Self, Index, Height);
end;

function TcxListBox.GetAutoComplete: Boolean;
begin
  Result := FInnerListBox.AutoComplete;
end;

function TcxListBox.GetAutoCompleteDelay: Cardinal;
begin
  Result := FInnerListBox.AutoCompleteDelay;
end;

function TcxListBox.GetColumns: Integer;
begin
  Result := FInnerListBox.Columns;
end;

function TcxListBox.GetCount: Integer;
begin
  Result := FInnerListBox.Items.Count;
end;

function TcxListBox.GetExtendedSelect: Boolean;
begin
  Result := FInnerListBox.ExtendedSelect;
end;

function TcxListBox.GetInnerListBox: TListBox;
begin
  Result := FInnerListBox;
end;

function TcxListBox.GetItemHeight: Integer;
begin
  Result := FInnerListBox.ItemHeight;
end;

function TcxListBox.GetItemIndex: Integer;
begin
  Result := FInnerListBox.ItemIndex;
end;

function TcxListBox.GetItemObject: TObject;
begin
  if ItemIndex <> -1 then
    Result := Items.Objects[ItemIndex]
  else
    Result := nil;
end;

function TcxListBox.GetItems: TStrings;
begin
  Result := FInnerListBox.Items;
end;

function TcxListBox.GetListStyle: TListBoxStyle;
begin
  Result := FInnerListBox.Style;
end;

function TcxListBox.GetMultiSelect: Boolean;
begin
  Result := FInnerListBox.MultiSelect;
end;

function TcxListBox.GetReadOnly: Boolean;
begin
  Result := DataBinding.ReadOnly;
end;

function TcxListBox.GetSelCount: Integer;
begin
  Result := FInnerListBox.SelCount;
end;

function TcxListBox.GetSelected(Index: Integer): Boolean;
begin
  Result := FInnerListBox.Selected[Index];
end;

function TcxListBox.GetSorted: Boolean;
begin
  Result := FInnerListBox.Sorted;
end;

function TcxListBox.GetTopIndex: Integer;
begin
  Result := FInnerListBox.TopIndex;
end;

procedure TcxListBox.SetAutoComplete(Value: Boolean);
begin
  FInnerListBox.AutoComplete := Value;
end;

procedure TcxListBox.SetAutoCompleteDelay(Value: Cardinal);
begin
  FInnerListBox.AutoCompleteDelay := Value;
end;

procedure TcxListBox.SetColumns(Value: Integer);
begin
  FInnerListBox.Columns := Value;
  FInnerListBox.SetExternalScrollBarsParameters;
end;

procedure TcxListBox.SetExtendedSelect(Value: Boolean);
begin
  FInnerListBox.ExtendedSelect := Value;
end;

procedure TcxListBox.SetItemHeight(Value: Integer);
begin
  FInnerListBox.ItemHeight := Value;
end;

procedure TcxListBox.SetItemIndex(Value: Integer);
begin
  FInnerListBox.ItemIndex := Value;
end;

procedure TcxListBox.SetItemObject(Value: TObject);
begin
  ItemIndex := Items.IndexOfObject(Value);
end;

procedure TcxListBox.SetItems(Value: TStrings);
begin
  FInnerListBox.Items := Value;
  DataChange;
end;

procedure TcxListBox.SetListStyle(Value: TListBoxStyle);
begin
  FInnerListBox.Style := Value;
end;

procedure TcxListBox.SetMultiSelect(Value: Boolean);
begin
  FInnerListBox.MultiSelect := Value;
end;

procedure TcxListBox.SetOnMeasureItem(Value: TcxListBoxMeasureItemEvent);
begin
  FOnMeasureItem := Value;
  if Assigned(FOnMeasureItem) then
    FInnerListBox.OnMeasureItem := DoMeasureItem
  else
    FInnerListBox.OnMeasureItem := nil;
end;

procedure TcxListBox.SetReadOnly(Value: Boolean);
begin
  DataBinding.ReadOnly := Value;
end;

procedure TcxListBox.SetSelected(Index: Integer; Value: Boolean);
begin
  FInnerListBox.Selected[Index] := Value;
end;

procedure TcxListBox.SetSorted(Value: Boolean);
begin
  FInnerListBox.Sorted := Value;
end;

procedure TcxListBox.SetTopIndex(Value: Integer);
begin
  FInnerListBox.TopIndex := Value;
end;

function TcxListBox.GetOnData: TLBGetDataEvent;
begin
  Result := FInnerListBox.OnData;
end;

function TcxListBox.GetOnDataFind: TLBFindDataEvent;
begin
  Result := FInnerListBox.OnDataFind;
end;

function TcxListBox.GetOnDataObject: TLBGetDataObjectEvent;
begin
  Result := FInnerListBox.OnDataObject;
end;

procedure TcxListBox.SetCount(Value: Integer);
begin
  FInnerListBox.Count := Value;
end;

procedure TcxListBox.SetOnData(Value: TLBGetDataEvent);
begin
  FInnerListBox.OnData := Value;
end;

procedure TcxListBox.SetOnDataFind(Value: TLBFindDataEvent);
begin
  FInnerListBox.OnDataFind := Value;
end;

procedure TcxListBox.SetOnDataObject(Value: TLBGetDataObjectEvent);
begin
  FInnerListBox.OnDataObject := Value;
end;

function TcxListBox.GetScrollWidth: Integer;
begin
  Result := FInnerListBox.ScrollWidth;
end;

function TcxListBox.GetTabWidth: Integer;
begin
  Result := FInnerListBox.TabWidth;
end;

procedure TcxListBox.SetIntegralHeight(Value: Boolean);
begin
  if Value <> FIntegralHeight then
  begin
    FIntegralHeight := Value;
    SetSize;
  end;
end;

procedure TcxListBox.SetScrollWidth(Value: Integer);
begin
  FInnerListBox.ScrollWidth := Value;
end;

procedure TcxListBox.SetTabWidth(Value: Integer);
begin
  FInnerListBox.TabWidth := Value;
end;

{ TdxCustomListBoxItem }

constructor TdxCustomListBoxItem.Create(AOwner: TdxCustomListBoxItems);
begin
  inherited Create;
  FOwner := AOwner;
end;

procedure TdxCustomListBoxItem.Changed;
begin
  if FOwner <> nil then
    FOwner.Changed;
end;

function TdxCustomListBoxItem.GetIndex: Integer;
begin
  if FOwner <> nil then
    Result := FOwner.IndexOf(Self)
  else
    Result := -1;
end;

procedure TdxCustomListBoxItem.SetCaption(const ACaption: string);
begin
  if ACaption <> FCaption then
  begin
    FCaption := ACaption;
    Changed;
  end;
end;

procedure TdxCustomListBoxItem.SetHasSeparator(const Value: Boolean);
begin
  if FHasSeparator <> Value then
  begin
    FHasSeparator := Value;
    Changed;
  end;
end;

procedure TdxCustomListBoxItem.SetImageIndex(AValue: Integer);
begin
  if AValue <> FImageIndex then
  begin
    FImageIndex := AValue;
    Changed;
  end;
end;

{ TdxCustomListBoxItems }

constructor TdxCustomListBoxItems.Create(AOwnerControl: TdxCustomListBox);
begin
  inherited Create;
  FOwnerControl := AOwnerControl;
end;

function TdxCustomListBoxItems.Add(const ACaption: string;
  AImageIndex: Integer = -1; AData: TObject = nil; AHasSeparator: Boolean = False): TdxCustomListBoxItem;
var
  AIndex: Integer;
begin
  if Sorted then
    AIndex := FindInSortedList(ACaption)
  else
    AIndex := Count;
  Result := Insert(AIndex, ACaption, AImageIndex, AData, AHasSeparator);
end;

function TdxCustomListBoxItems.AddObject(const ACaption: string; AData: TObject): TdxCustomListBoxItem;
begin
  Result := Add(ACaption, -1, AData);
end;

function TdxCustomListBoxItems.AddSeparator: TdxCustomListBoxItem;
begin
  if Count > 0 then
  begin
    Result := Items[Count - 1];
    Result.HasSeparator := True;
  end
  else
    Result := nil;
end;

procedure TdxCustomListBoxItems.BeginUpdate;
begin
  Inc(FLockCount);
end;

procedure TdxCustomListBoxItems.CancelUpdate;
begin
  Dec(FLockCount);
end;

procedure TdxCustomListBoxItems.EndUpdate;
begin
  Dec(FLockCount);
  Changed;
end;

procedure TdxCustomListBoxItems.Changed;
begin
  FOwnerControl.LayoutChanged;
end;

function TdxCustomListBoxItems.FindInSortedList(const ACaption: string): Integer;
var
  ACompareResult: Integer;
  ALeft, ARight, I: Integer;
begin
  ALeft := 0;
  ARight := Count - 1;
  while ALeft <= ARight do
  begin
    I := (ALeft + ARight) div 2;
    ACompareResult := CompareStr(Items[I].Caption, ACaption);
    if ACompareResult < 0 then
      ALeft := I + 1
    else
      ARight := I - 1;
  end;
  Result := ALeft;
end;

function TdxCustomListBoxItems.IndexOfCaption(
  const ACaption: string; ACaseSensitive: Boolean = True): Integer;

  function Compare(const S1, S2: string): Boolean;
  begin
    if ACaseSensitive then
      Result := S1 = S2
    else
      Result := SameText(S1, S2)
  end;

var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Count - 1 do
    if Compare(Items[I].Caption, ACaption) then
    begin
      Result := I;
      Break;
    end;
end;

function TdxCustomListBoxItems.IndexOfObject(AObject: TObject): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Count - 1 do
    if Items[I].Data = AObject then
    begin
      Result := I;
      Break;
    end;
end;

function TdxCustomListBoxItems.Insert(AIndex: Integer; const ACaption: string;
  AImageIndex: Integer = -1; AData: TObject = nil; AHasSeparator: Boolean = False): TdxCustomListBoxItem;
begin
  Result := TdxCustomListBoxItem.Create(Self);
  Result.FCaption := ACaption;
  Result.FImageIndex := AImageIndex;
  Result.FData := AData;
  Result.FHasSeparator := AHasSeparator;
  inherited Insert(AIndex, Result);
end;

function TdxCustomListBoxItems.IsValidIndex(AIndex: Integer): Boolean;
begin
  Result := (AIndex >= 0) and (AIndex < Count);
end;

procedure TdxCustomListBoxItems.LoadFromStrings(AStrings: TStrings);
var
  I: Integer;
begin
  BeginUpdate;
  try
    Clear;
    for I := 0 to AStrings.Count - 1 do
      AddObject(AStrings[I], AStrings.Objects[I]);
  finally
    EndUpdate;
  end;
end;

procedure TdxCustomListBoxItems.Notify(Ptr: Pointer; Action: TListNotification);
begin
  inherited Notify(Ptr, Action);
  Changed;
end;

function TdxCustomListBoxItems.GetItem(Index: Integer): TdxCustomListBoxItem;
begin
  Result := TdxCustomListBoxItem(inherited Items[Index]);
end;

procedure TdxCustomListBoxItems.SetSorted(AValue: Boolean);
begin
  if AValue <> FSorted then
  begin
    FSorted := AValue;
    if Sorted then
      Sort(@dxCustomListBoxItemsCompare);
  end;
end;

{ TdxCustomListBox }

constructor TdxCustomListBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FItemHeight := 16;
  DoubleBuffered := not IsWinSeven;
  FItems := GetItemsClass.Create(Self);
  FChangeLink := TChangeLink.Create;
  FChangeLink.OnChange := DoImageListChanged;
  FHintHelper := TdxCustomListBoxHintHelper.Create(Self);
  BorderStyle := cxcbsDefault;
  ParentColor := False;
  Color := clWindow;
  Keys := [kArrows, kChars];
  IncrementalSearch := True;
end;

destructor TdxCustomListBox.Destroy;
begin
  BeginUpdate;
  Images := nil;
  EndMouseTracking(Self);
  FreeAndNil(FChangeLink);
  FreeAndNil(FHintHelper);
  FreeAndNil(FItems);
  inherited Destroy;
end;

function TdxCustomListBox.Add(const ACaption: string; AImageIndex: Integer = -1): Integer;
begin
  Result := AddItem(ACaption, nil, AImageIndex);
end;

function TdxCustomListBox.AddItem(const ACaption: string;
  AObject: TObject; AImageIndex: Integer = -1): Integer;
begin
  Result := FItems.Add(ACaption, AImageIndex, AObject).Index;
end;

procedure TdxCustomListBox.AdjustItemFont(
  AFont: TFont; AItem: TdxCustomListBoxItem; AState: TcxButtonState);
begin
  //nothing
end;

procedure TdxCustomListBox.BeginUpdate;
begin
  FItems.BeginUpdate;
end;

procedure TdxCustomListBox.Clear;
begin
  FItems.BeginUpdate;
  try
    FItems.Clear;
    FItemIndex := -1;
  finally
    FItems.EndUpdate;
  end;
end;

procedure TdxCustomListBox.EndUpdate;
begin
  FItems.EndUpdate;
end;

procedure TdxCustomListBox.BoundsChanged;
begin
  inherited BoundsChanged;
  LayoutChanged;
end;

function TdxCustomListBox.CanProcessIncSearch(Key: Char): Boolean;
begin
  Result := IncrementalSearch and (Count > 0) and IsIncSearchChar(Key);
end;

function TdxCustomListBox.CanShowHint(
  AItemIndex: Integer; out AItemRect, AItemTextRect: TRect): Boolean;
begin
  Result := False;
  if Items.IsValidIndex(AItemIndex) then
  begin
    cxScreenCanvas.Font := Font;
    AItemRect := ItemRect(AItemIndex);
    AItemTextRect := GetItemTextRect(AItemRect);
    Result := cxScreenCanvas.TextWidth(Items[AItemIndex].Caption) > cxRectWidth(AItemTextRect);
    cxScreenCanvas.Dormant;
  end;
end;

function TdxCustomListBox.CanStartIncSearch(Key: Char): Boolean;
begin
  Result := IncrementalSearch and (Count > 0) and IsStartIncSearchChar(Key);
end;

function TdxCustomListBox.CalculateContentSize(AMaxVisibleItemsCount: Integer): TSize;
var
  I: Integer;
begin
  Result := cxNullSize;
  cxScreenCanvas.Font := Font;
  cxScreenCanvas.Font.Style := cxScreenCanvas.Font.Style + [fsBold];
  for I := 0 to Items.Count - 1 do
    Result.cx := Max(Result.cx, cxScreenCanvas.TextWidth(Items[I].Caption));
  for I := 0 to Min(Items.Count, AMaxVisibleItemsCount) - 1 do
    Inc(Result.cy, ItemsHeight[I]);
  Inc(Result.cx, GetSystemMetrics(SM_CXVSCROLL) + cxMarginsWidth(TextOffsets) + ImagesAreaSize);
  cxScreenCanvas.Dormant;
  Inc(Result.cx, 2 * BorderSize);
  Inc(Result.cy, 2 * BorderSize);
end;

function TdxCustomListBox.CalculateItemHeight: Integer;
begin
  cxScreenCanvas.Font := Font;
  cxScreenCanvas.Font.Style := cxScreenCanvas.Font.Style + [fsBold];
  Result := Max(ImageSize.cy + cxMarginsHeight(ImageOffsets),
    cxMarginsHeight(TextOffsets) + cxTextHeight(cxScreenCanvas.Handle));
  cxScreenCanvas.Dormant;
end;

function TdxCustomListBox.GetHasSeparator(Index: Integer): Boolean;
begin
  Result := (Index + 1 < Items.Count) and Items[Index].HasSeparator;
end;

function TdxCustomListBox.GetItemsClass: TdxCustomListBoxItemsClass;
begin
  Result := TdxCustomListBoxItems;
end;

procedure TdxCustomListBox.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.WindowClass.style := Params.WindowClass.style and not (CS_VREDRAW or CS_HREDRAW);
end;

procedure TdxCustomListBox.DoLayoutChanged;
begin
  CheckTopItemIndex;
  CheckFocusedItemIndex;
  UpdateScrollBars;
  UpdateHotState;
end;

procedure TdxCustomListBox.CheckFocusedItemIndex;
begin
  if FItemIndex >= Items.Count then
    ItemIndex := Items.Count - 1;
end;

procedure TdxCustomListBox.CheckTopItemIndex;
begin
  FTopIndex := Max(Min(TopIndex, MaxTopIndex), 0);
  UpdateScrollBars;
end;

procedure TdxCustomListBox.DrawBackground;
begin
  LookAndFeelPainter.DrawBorder(Canvas, Bounds);
  Canvas.FillRect(ClientBounds, GetBackgroundColor);
end;

procedure TdxCustomListBox.DrawItem(
  const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState);
var
  AItemRect, ASeparatorRect: TRect;
begin
  GetItemPartsRects(AItem.Index, R, AItemRect, ASeparatorRect);
  DrawItemBackground(AItemRect, AItem, AState);
  DrawItemImage(GetItemImageRect(AItemRect), AItem, AState);
  DrawItemText(GetItemTextRect(AItemRect), AItem, AState);
  DrawItemSeparator(ASeparatorRect);
end;

procedure TdxCustomListBox.DrawItemBackground(
  const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState);
begin
  if AState = cxbsPressed then
    Canvas.FillRect(R, LookAndFeelPainter.DefaultSelectionColor);
end;

procedure TdxCustomListBox.DrawItemImage(
  const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState);
var
  AImageRect: TRect;
begin
  if IsImageAssigned(Images, AItem.ImageIndex) then
  begin
    AImageRect := cxRectCenter(R, ImageSize);
    cxDrawImage(Canvas.Handle, AImageRect, AImageRect, nil, Images, AItem.ImageIndex, idmNormal);
  end;
end;

procedure TdxCustomListBox.DrawItemText(
  const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState);
begin
  Canvas.Font := Font;
  Canvas.Font.Color := GetTextColor(AItem, AState);
  AdjustItemFont(Canvas.Font, AItem, AState);
  Canvas.DrawTexT(AItem.Caption, R, GetTextFlags, True, ra0);
end;

procedure TdxCustomListBox.DrawItemSeparator(const R: TRect);
begin
  if not cxRectIsEmpty(R) then
    LookAndFeelPainter.DrawDropDownListBoxSeparator(Canvas, R, ImagesAreaRect);
end;

procedure TdxCustomListBox.EraseBackground(DC: HDC);
begin
end;

function TdxCustomListBox.ItemAtPos(const APoint: TPoint; AExistOnly: Boolean = False): Integer;
var
  AItemRect, ASeparatorRect: TRect;
  I: Integer;
  R: TRect;
begin
  Result := -1;
  if PtInRect(ClientBounds, APoint) then
  begin
    R := cxRectSetHeight(ClientBounds, 0);
    for I := TopIndex to Items.Count - 1 do
    begin
      R := GetItemRect(I, R);
      GetItemPartsRects(I, R, AItemRect, ASeparatorRect);
      if PtInRect(AItemRect, APoint) then
      begin
        Result := I;
        Exit;
      end;
    end;
    if not AExistOnly then
      Result := Items.Count
  end;
end;

function TdxCustomListBox.ItemRect(AIndex: Integer): TRect;
var
  I: Integer;
begin
  Result := cxRectSetHeight(ClientBounds, 0);
  if AIndex >= TopIndex then
  begin
    for I := TopIndex to AIndex do
      Result := GetItemRect(I, Result);
  end;
end;

procedure TdxCustomListBox.LayoutChanged;
begin
  if not IsLocked then
  begin
    DoLayoutChanged;
    Invalidate;
  end;
end;

procedure TdxCustomListBox.MakeVisible(AIndex: Integer);
begin
  if AIndex < TopIndex then
    TopIndex := AIndex
  else
    if AIndex >= TopIndex + PageSize then
      TopIndex := AIndex - PageSize + 1;
end;

function TdxCustomListBox.HasBackground: Boolean;
begin
  Result := False;
end;

procedure TdxCustomListBox.InitScrollBarsParameters;
begin
  SetScrollBarInfo(sbVertical, 0, Items.Count - 1, 1, PageSize, TopIndex, True, True);
  SetScrollBarInfo(sbHorizontal, 0,  -1, 1, 1, 1, True, True);
end;

procedure TdxCustomListBox.InvalidateItem(AIndex: Integer);
begin
  if (AIndex >= TopIndex) and (AIndex <= TopIndex + PageSize) then
    InvalidateRect(ItemRect(AIndex), False);
end;

procedure TdxCustomListBox.InvalidateItems(const AIndex1, AIndex2: Integer);
begin
  if AIndex1 <> AIndex2 then
  begin
    InvalidateItem(AIndex1);
    InvalidateItem(AIndex2);
  end;
end;

function TdxCustomListBox.IsIncSearchChar(AChar: Char): Boolean;
begin
  Result := AChar >= ' ';
end;

function TdxCustomListBox.IsStartIncSearchChar(AChar: Char): Boolean;
begin
  Result := AChar > ' ';
end;

procedure TdxCustomListBox.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited KeyDown(Key, Shift);
  if ProcessNavigationKey(Key, Shift) then
  begin
    ClearIncrementalSearch;
    Key := 0;
  end;
end;

procedure TdxCustomListBox.KeyPress(var Key: Char);
begin
  inherited KeyPress(Key);
  if ProcessKeyPress(Key) then
    Key := #0;
end;

procedure TdxCustomListBox.MeasureItemHeight(AIndex: Integer; var AHeight: Integer);
begin
  if GetHasSeparator(AIndex) then
    Inc(AHeight, LookAndFeelPainter.DropDownListBoxSeparatorSize);
end;

procedure TdxCustomListBox.MouseDown(
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseDown(Button, Shift, X, Y);
  HintHelper.MouseDown;
  if (Button = mbLeft) and PtInRect(ClientBounds, Point(X, Y)) then
    ItemIndex := ItemAtPos(Point(X, Y), True);
  Click;
end;

procedure TdxCustomListBox.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseMove(Shift, X, Y);
  UpdateHotState;
end;

function TdxCustomListBox.NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := False;
end;

procedure TdxCustomListBox.MouseEnter(AControl: TControl);
begin
  inherited MouseEnter(AControl);
  UpdateHotState;
  BeginMouseTracking(Self, Bounds, Self);
end;

procedure TdxCustomListBox.MouseLeave(AControl: TControl);
begin
  inherited MouseLeave(AControl);
  UpdateHotState;
end;

procedure TdxCustomListBox.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = Images) then
    Images := nil;
end;

function TdxCustomListBox.ProcessKeyPress(var Key: Char): Boolean;
begin
  Result := CanProcessIncSearch(Key) and DoIncrementalSearch(Key);
end;

procedure TdxCustomListBox.DoImageListChanged(Sender: TObject);
begin
  if not IsLocked then
    Invalidate;
end;

procedure TdxCustomListBox.Paint;
var
  I: Integer;
  R: TRect;
begin
  DrawBackground;
  Canvas.Font := Font;
  Canvas.Brush.Style := bsClear;
  R := cxRectSetHeight(ClientBounds, 0);
  for I := TopIndex to Items.Count - 1 do
  begin
    R := GetItemRect(I, R);
    if Canvas.RectVisible(R) then
      DrawItem(R, Items[I], GetItemState(I));
    if R.Bottom >= ClientRect.Bottom then
      Break;
  end;
end;

procedure TdxCustomListBox.ClearIncrementalSearch;
begin
  FSearchText := '';
end;

function TdxCustomListBox.DoIncrementalSearch(var Key: Char): Boolean;
begin
  if GetTickCount - FStartIncrementalSearch > 1000 then
    ClearIncrementalSearch;
  FStartIncrementalSearch := GetTickCount;
  SearchText := SearchText + Key;
  Result := FocusNextItemWithText(SearchText);
end;

function TdxCustomListBox.FocusNextItemWithText(const AText: string): Boolean;
var
  AStartIndex: Integer;
begin
  if Count = 0 then
    Result := False
  else
  begin
    AStartIndex := ItemIndex + 1;
    Result := ((AStartIndex < Count) and FocusItemWithText(AText, AStartIndex, Count - 1)) or
      FocusItemWithText(AText, 0, AStartIndex - 1);
  end;
end;

function TdxCustomListBox.FocusItemWithText(const AText: string; AStartIndex, AFinishIndex: Integer): Boolean;
var
  I: Integer;
begin
  Result := False;
  if AStartIndex <= AFinishIndex then
  begin
    for I := AStartIndex to AFinishIndex do
      if AnsiStartsText(AText, Items[I].Caption) then
      begin
        ItemIndex := I;
        Result := True;
        Break;
      end;
  end
  else
  begin
    for I := AStartIndex downto AFinishIndex do
      if AnsiStartsText(AText, Items[I].Caption) then
      begin
        ItemIndex := I;
        Result := True;
        Break;
      end;
  end;
end;

function TdxCustomListBox.GetValidIndex(AIndex: Integer): Integer;
begin
  if AIndex < 0 then
    if LoopedNavigation then
      Result := Items.Count - 1
    else
      Result := 0
  else
    if AIndex >= Items.Count then
      if LoopedNavigation then
        Result := 0
      else
        Result := Items.Count - 1
    else
      Result := AIndex;
end;

function TdxCustomListBox.ProcessNavigationKey(var Key: Word; Shift: TShiftState): Boolean;
begin
  Result := True;
  case Key of
    VK_UP:
      ItemIndex := GetValidIndex(ItemIndex - 1);
    VK_DOWN:
      ItemIndex := GetValidIndex(ItemIndex + 1);
    VK_END:
      ItemIndex := Items.Count - 1;
    VK_HOME:
      ItemIndex := 0;
    VK_NEXT:
      if ssCtrl in Shift then
        ItemIndex := Items.Count - 1
      else
        ItemIndex := ItemIndex + PageSize;
    VK_PRIOR:
      if ssCtrl in Shift then
        ItemIndex := 0
      else
        ItemIndex := Max(0, ItemIndex - PageSize);
    else
      Result := False;
  end;
end;

function TdxCustomListBox.Remove(AObject: TObject): Integer;
begin
  Result := FItems.FreeAndRemove(AObject);
  LayoutChanged;
end;

procedure TdxCustomListBox.Scroll(AScrollBarKind: TScrollBarKind;
  AScrollCode: TScrollCode; var AScrollPos: Integer);
begin
  if IsLocked or (AScrollCode = scEndScroll) then
    Exit;
  if AScrollBarKind = sbVertical then
  begin
    case AScrollCode of
      scLineUp:
        Dec(FTopIndex);
      scLineDown:
        Inc(FTopIndex);
      scPageUp:
        Dec(FTopIndex, PageSize);
      scPageDown:
        Inc(FTopIndex, PageSize);
      scTop:
        FTopIndex := 0;
      scBottom:
        FTopIndex := Items.Count - PageSize;
      scTrack:
        FTopIndex := AScrollPos;
    end;
    LayoutChanged;
    AScrollPos := TopIndex;
    Update;
  end
  else
    inherited Scroll(AScrollBarKind, AScrollCode, AScrollPos);
end;

function TdxCustomListBox.PtInCaller(const P: TPoint): Boolean;
begin
  Result := PtInRect(ClientBounds, P);
end;

procedure TdxCustomListBox.TrackingCallerMouseLeave;
begin
  MouseLeave(nil)
end;

procedure TdxCustomListBox.UpdateHintState;
var
  AItemRect, AItemTextRect: TRect;
begin
  if ShowHint and CanShowHint(HotIndex, AItemRect, AItemTextRect) then
    HintHelper.ShowHint(AItemRect, AItemTextRect, Items[HotIndex].Caption, False, Items[HotIndex])
  else
    HintHelper.CancelHint;
end;

procedure TdxCustomListBox.UpdateHotState;
begin
  if HandleAllocated and Focused and (DragAndDropState = ddsNone) then
    HotIndex := ItemAtPos(ScreenToClient(GetMouseCursorPos), True)
  else
    HotIndex := -1;
end;

function TdxCustomListBox.GetBackgroundColor: TColor;
begin
  Result := LookAndFeelPainter.DefaultEditorBackgroundColor(not Enabled);
  if Result = clDefault then
    Result := clWindow;
end;

function TdxCustomListBox.GetCount: Integer;
begin
  Result := Items.Count;
end;

function TdxCustomListBox.GetImageOffsets: TRect;
begin
  Result := cxRect(2, 2, 2, 2);
end;

function TdxCustomListBox.GetImagesAreaRect: TRect;
begin
  Result := cxRectSetWidth(ClientBounds, ImagesAreaSize);
end;

function TdxCustomListBox.GetImagesAreaSize: Integer;
begin
  if Images <> nil then
    Result := Max(ImageSize.cx + cxMarginsWidth(ImageOffsets), ItemHeight)
  else
    Result := 0;
end;

function TdxCustomListBox.GetImageSize: TSize;
begin
  Result := dxGetImageSize(nil, Images, 0);
end;

function TdxCustomListBox.GetItemImageRect(const AItemRect: TRect): TRect;
begin
  with ImagesAreaRect do
    Result := Rect(Left, AItemRect.Top, Right, AItemRect.Bottom);
  Result := cxRectContent(Result, ImageOffsets);
end;

procedure TdxCustomListBox.GetItemPartsRects(AIndex: Integer; const R: TRect; out AItemRect, ASeparatorRect: TRect);
var
  ASeparatorSize: Integer;
begin
  if GetHasSeparator(AIndex) then
  begin
    ASeparatorSize := LookAndFeelPainter.DropDownListBoxSeparatorSize;
    AItemRect := cxRectSetHeight(R, cxRectHeight(R) - ASeparatorSize);
    ASeparatorRect := cxRectSetBottom(R, R.Bottom, ASeparatorSize);
  end
  else
  begin
    ASeparatorRect := cxNullRect;
    AItemRect := R;
  end;
end;

function TdxCustomListBox.GetItemRect(AItemIndex: Integer; const APrevItemRect: TRect): TRect;
begin
  Result := cxRectSetTop(APrevItemRect, APrevItemRect.Bottom, ItemsHeight[AItemIndex]);
end;

function TdxCustomListBox.GetItemTextRect(const AItemRect: TRect): TRect;
begin
  Result := AItemRect;
  Result.Left := ImagesAreaRect.Right;
  Result := cxRectContent(Result, TextOffsets);
end;

function TdxCustomListBox.GetItemState(AIndex: Integer): TcxButtonState;
begin
  if AIndex = ItemIndex then
    Result := cxbsPressed
  else
    if AIndex = HotIndex then
      Result := cxbsHot
    else
      Result := cxbsNormal;
end;

function TdxCustomListBox.GetItemsHeight(Index: Integer): Integer;
begin
  Result := ItemHeight;
  if Index < Items.Count then
    MeasureItemHeight(Index, Result);
end;

function TdxCustomListBox.GetIsLocked: Boolean;
begin
  Result := (FItems = nil) or (FItems.LockCount > 0);
end;

function TdxCustomListBox.GetMaxTopIndex: Integer;
var
  R: TRect;
begin
  Result := Items.Count - 1;
  R := ClientBounds;
  while Result >= 0 do
  begin
    Dec(R.Bottom, ItemsHeight[Result]);
    if R.Bottom >= R.Top then
      Dec(Result)
    else
      Break;
  end;
  Result := Min(Result + 1, Items.Count - 1);
end;

function TdxCustomListBox.GetTextColor(
  AItem: TdxCustomListBoxItem; AState: TcxButtonState): TColor;
begin
  if Font.Color <> clWindowText then
    Result := Font.Color
  else
    if AState = cxbsPressed then
      Result := LookAndFeelPainter.DefaultSelectionTextColor
    else
      Result := LookAndFeelPainter.DefaultEditorTextColor(AState = cxbsDisabled);
end;

function TdxCustomListBox.GetTextFlags: Integer;
begin
  Result := cxAlignLeft or cxAlignVCenter or cxSingleLine or cxShowEndEllipsis;
end;

function TdxCustomListBox.GetTextOffsets: TRect;
begin
  Result := cxRect(cxTextOffset, cxTextOffset, cxTextOffset, cxTextOffset);
end;

function TdxCustomListBox.GetPageSize: Integer;

  function GetBottomIndex: Integer;
  var
    R: TRect;
  begin
    Result := TopIndex;
    R := ClientBounds;
    while Result < Items.Count do
    begin
      Inc(R.Top, ItemsHeight[Result]);
      if R.Top > R.Bottom then Break;
      Inc(Result);
    end;
  end;

begin
  Result := Max(GetBottomIndex - TopIndex, 1);
end;

function TdxCustomListBox.GetSorted: Boolean;
begin
  Result := Items.Sorted;
end;

function TdxCustomListBox.GetTopIndex: Integer;
begin
  Result := FTopIndex;
  if Result >= Items.Count then
    Result := Items.Count - 1;
  if Result < 0 then
    Result := 0;
end;

procedure TdxCustomListBox.SetHotIndex(AValue: Integer);
begin
  if FHotIndex <> AValue then
  begin
    InvalidateItems(FHotIndex, AValue);
    FHotIndex := AValue;
    UpdateHintState;
  end;
end;

procedure TdxCustomListBox.SetImages(AValue: TCustomImageList);
begin
  cxSetImageList(AValue, FImages, FChangeLink, Self);
end;

procedure TdxCustomListBox.SetItemHeight(AValue: Integer);
begin
  AValue := Max(0, AValue);
  if FItemHeight <> AValue then
  begin
    FItemHeight := AValue;
    LayoutChanged;
  end;
end;

procedure TdxCustomListBox.SetItemIndex(AIndex: Integer);
begin
  if (AIndex >= Items.Count) and (Items.Count > 0) then
    AIndex := Items.Count - 1;
  if FItemIndex <> AIndex then
  begin
    InvalidateItems(AIndex, FItemIndex);
    FItemIndex := AIndex;
    if ItemIndex <> -1 then
      MakeVisible(ItemIndex);
    Click;
  end;
end;

procedure TdxCustomListBox.SetSorted(AValue: Boolean);
begin
  Items.Sorted := AValue;
end;

procedure TdxCustomListBox.SetTopIndex(AValue: Integer);
begin
  AValue := Max(0, AValue);
  if AValue <> FTopIndex then
  begin
    FTopIndex := AValue;
    LayoutChanged;
  end;
end;

{ TdxCustomListBoxHintHelper }

constructor TdxCustomListBoxHintHelper.Create(AOwnerControl: TdxCustomListBox);
begin
  inherited Create;
  FOwnerControl := AOwnerControl;
end;

function TdxCustomListBoxHintHelper.GetOwnerControl: TcxControl;
begin
  Result := FOwnerControl;
end;

function TdxCustomListBoxHintHelper.PtInCaller(const P: TPoint): Boolean;
begin
  Result := PtInRect(GetHintControl.Bounds, P);
end;

{ TdxCustomDropDownInnerListBox }

constructor TdxCustomDropDownInnerListBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDefaultItemIndex := -1;
end;

procedure TdxCustomDropDownInnerListBox.AdjustItemFont(
  AFont: TFont; AItem: TdxCustomListBoxItem; AState: TcxButtonState);
begin
  if (DefaultItemIndex > -1) and (DefaultItemIndex = AItem.Index) then
    AFont.Style := AFont.Style + [fsBold];
end;

procedure TdxCustomDropDownInnerListBox.DoLayoutChanged;
begin
  ItemHeight := CalculateItemHeight;
  inherited DoLayoutChanged;
end;

procedure TdxCustomDropDownInnerListBox.DoSelectItem(ASelectedViaKeyboard: Boolean);
begin
  if Items.IsValidIndex(ItemIndex) then
  begin
    if Assigned(OnSelectItem) then
      OnSelectItem(Self, Items[ItemIndex], ASelectedViaKeyboard);
  end;
end;

procedure TdxCustomDropDownInnerListBox.DrawBackground;
begin
  LookAndFeelPainter.DrawDropDownListBoxBackground(Canvas, ClientRect, BorderSize > 0);
  LookAndFeelPainter.DrawDropDownListBoxGutterBackground(Canvas, ImagesAreaRect);
end;

procedure TdxCustomDropDownInnerListBox.DrawItemBackground(
  const R: TRect; AItem: TdxCustomListBoxItem; AState: TcxButtonState);
begin
  if AState = cxbsPressed then
    LookAndFeelPainter.DrawDropDownListBoxSelection(Canvas, R, ImagesAreaRect);
end;

function TdxCustomDropDownInnerListBox.ProcessNavigationKey(var Key: Word; Shift: TShiftState): Boolean;
begin
  Result := True;
  case Key of
    VK_RETURN:
      DoSelectItem(True);
    else
      Result := inherited ProcessNavigationKey(Key, Shift);
  end;
end;

procedure TdxCustomDropDownInnerListBox.MouseLeave(AControl: TControl);
begin
  inherited MouseLeave(AControl);
  ItemIndex := -1;
end;

procedure TdxCustomDropDownInnerListBox.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseMove(Shift, X, Y);
  if not cxPointIsEqual(FPrevMousePosition, Point(X, Y)) then
  begin
    ItemIndex := HotIndex;
    FPrevMousePosition := Point(X, Y);
  end;
end;

procedure TdxCustomDropDownInnerListBox.MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  DoSelectItem(False);
end;

function TdxCustomDropDownInnerListBox.GetBorderSize: Integer;
begin
  if BorderStyle = cxcbsNone then
    Result := 0
  else
    Result := LookAndFeelPainter.DropDownListBoxBordersSize;
end;

function TdxCustomDropDownInnerListBox.GetImageOffsets: TRect;
begin
  Result := LookAndFeelPainter.DropDownListBoxItemImageOffsets;
end;

function TdxCustomDropDownInnerListBox.GetImageSize: TSize;
begin
  if Images <> nil then
    Result := cxSize(Images.Width, Images.Height)
  else
    Result := cxSize(16, 16);
end;

function TdxCustomDropDownInnerListBox.GetTextColor(
  AItem: TdxCustomListBoxItem; AState: TcxButtonState): TColor;
begin
  Result := Font.Color;
  if Result = clWindowText then
    Result := LookAndFeelPainter.DropDownListBoxItemTextColor(AState = cxbsPressed);
  if Result = clDefault then
    Result := clWindowText;
end;

function TdxCustomDropDownInnerListBox.GetTextOffsets: TRect;
begin
  Result := LookAndFeelPainter.DropDownListBoxItemTextOffsets;
end;

procedure TdxCustomDropDownInnerListBox.SetDefaultItemIndex(AValue: Integer);
begin
  if AValue <> FDefaultItemIndex then
  begin
    FDefaultItemIndex := AValue;
    LayoutChanged;
  end;
end;

{ TdxCustomDropDownListBox }

constructor TdxCustomDropDownListBox.Create(AOwnerControl: TWinControl);
begin
  inherited Create(AOwnerControl);
  Adjustable := True;
{$IFDEF DELPHI9}
  Position := poDesigned;
{$ENDIF}
  FDisplayRowsCount := 8;
  FInnerListBox := CreateInnerListBox;
  FInnerListBox.Parent := Self;
  FInnerListBox.Align := alClient;
  FInnerListBox.OnSelectItem := ItemSelected;
end;

constructor TdxCustomDropDownListBox.CreateEx(AOwnerControl: TWinControl;
  AOwnerParent: TcxControl);
var
  AIntf: IcxLookAndFeelContainer;
begin
  Create(AOwnerControl);
  OwnerParent := AOwnerParent;
  if Supports(AOwnerParent, IcxLookAndFeelContainer, AIntf) then
    InnerListBox.LookAndFeel.MasterLookAndFeel := AIntf.GetLookAndFeel;
end;

destructor TdxCustomDropDownListBox.Destroy;
begin
  FreeAndNil(FInnerListBox);
  inherited Destroy;
end;

procedure TdxCustomDropDownListBox.BeginUpdate;
begin
  InnerListBox.BeginUpdate;
end;

procedure TdxCustomDropDownListBox.EndUpdate;
begin
  InnerListBox.EndUpdate;
end;

function TdxCustomDropDownListBox.CreateInnerListBox: TdxCustomDropDownInnerListBox;
begin
  Result := TdxCustomDropDownInnerListBox.Create(nil);
end;

procedure TdxCustomDropDownListBox.AdjustClientRect(var Rect: TRect);
begin
  // nothing to do
end;

function TdxCustomDropDownListBox.CalculatePosition: TPoint;
begin
  if Count > 0 then
    Result := inherited CalculatePosition
  else
    Result := Point(cxInvisibleCoordinate, cxInvisibleCoordinate);
end;

procedure TdxCustomDropDownListBox.CalculateSize;
var
  ASize: TSize;
begin
  InnerListBox.LayoutChanged;
  ASize := InnerListBox.CalculateContentSize(DisplayRowsCount);
  if MaxWidth > 0 then
    ASize.cx := Min(ASize.cx, cxGetValueCurrentDPI(MaxWidth));
  ASize.cx := Max(ASize.cx, cxGetValueCurrentDPI(MinWidth));
  SetBounds(Left, Top, ASize.cx, ASize.cy);
end;

procedure TdxCustomDropDownListBox.CloseUp(AClosedViaKeyboard: Boolean);
begin
  FClosedViaKeyboard := AClosedViaKeyboard;
  inherited CloseUp;
end;

procedure TdxCustomDropDownListBox.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  if IsWinXPOrLater then
  begin
    Params.WindowClass.Style := Params.WindowClass.Style or CS_DROPSHADOW;
    Params.ExStyle := Params.ExStyle or WS_EX_TOPMOST;
  end;
end;

procedure TdxCustomDropDownListBox.DoCloseUp(AClosedViaKeyboard: Boolean);
begin
  if Assigned(OnCloseUp) then
    OnCloseUp(Self, AClosedViaKeyboard);
end;

procedure TdxCustomDropDownListBox.DoHide;
begin
  inherited DoHide;
  DoCloseUp(FClosedViaKeyboard);
end;

procedure TdxCustomDropDownListBox.DoSelectItem(
  AItem: TdxCustomListBoxItem; ASelectedViaKeyboard: Boolean);
begin
  if Assigned(OnSelect) then OnSelect(Self, AItem, ASelectedViaKeyboard);
end;

function TdxCustomDropDownListBox.GetCount: Integer;
begin
  Result := InnerListBox.Count;
end;

function TdxCustomDropDownListBox.GetImages: TCustomImageList;
begin
  Result := InnerListBox.Images;
end;

function TdxCustomDropDownListBox.GetItemHeight: Integer;
begin
  Result := InnerListBox.ItemHeight;
end;

function TdxCustomDropDownListBox.GetItemIndex: Integer;
begin
  Result := InnerListBox.ItemIndex;
end;

function TdxCustomDropDownListBox.GetItems: TdxCustomListBoxItems;
begin
  Result := InnerListBox.Items;
end;

procedure TdxCustomDropDownListBox.InitInnerListBox;
begin
  InnerListBox.ShowHint := ShowHint;
end;

procedure TdxCustomDropDownListBox.InitPopup;
begin
  inherited InitPopup;
  InitInnerListBox;
end;

procedure TdxCustomDropDownListBox.ItemSelected(Sender: TObject;
  AItem: TdxCustomListBoxItem; ASelectedViaKeyboard: Boolean);
var
  ALink: TcxObjectLink;
begin
  ALink := cxAddObjectLink(Self);
  try
    try
      DoSelectItem(AItem, ASelectedViaKeyboard);
    finally
      if ALink.Ref <> nil then
        CloseUp(ASelectedViaKeyboard);
    end;
  finally
    cxRemoveObjectLink(ALink);
  end;
end;

function TdxCustomDropDownListBox.IsShortCut(var Message: TWMKey): Boolean;
begin
  Result := inherited IsShortCut(Message);
  if Message.CharCode = VK_ESCAPE then
  begin
    Result := True;
    CloseUp(True);
  end;
end;

procedure TdxCustomDropDownListBox.Popup;
begin
  SetBounds(Left, Top, 0, 0);
  FClosedViaKeyboard := False;
  inherited Popup(FInnerListBox);
end;

procedure TdxCustomDropDownListBox.PopupForBounds(const ABounds: TRect; AActivateKey: Char = #0);
begin
  if InnerListBox.CanStartIncSearch(AActivateKey) then
  begin
    ItemIndex := -1;
    InnerListBox.DoIncrementalSearch(AActivateKey);
  end;
  OwnerBounds := ABounds;
  Popup;
end;

procedure TdxCustomDropDownListBox.SetImages(const Value: TCustomImageList);
begin
  InnerListBox.Images := Value;
end;

procedure TdxCustomDropDownListBox.SetItemHeight(const Value: Integer);
begin
  InnerListBox.ItemHeight := Value;
end;

procedure TdxCustomDropDownListBox.SetItemIndex(const Value: Integer);
begin
  InnerListBox.ItemIndex := Value;
end;

initialization
  RegisterClasses([TdxCustomListBox]);

finalization
  UnregisterClasses([TdxCustomListBox]);

end.
