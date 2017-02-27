{********************************************************************}
{                                                                    }
{ written by TMS Software                                            }
{            copyright © 2016                                        }
{            Email : info@tmssoftware.com                            }
{            Web : http://www.tmssoftware.com                        }
{                                                                    }
{ The source code is given as is. The author is not responsible      }
{ for any possible damage done due to the use of this code.          }
{ The complete source code remains property of the author and may    }
{ not be distributed, published, given or sold in any form as such.  }
{ No parts of the source code can be included in any other component }
{ or application without written authorization of the author.        }
{********************************************************************}

unit AdvChartToolBar;

{$I TMSDEFS.inc}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

interface

uses
  Classes, AdvChartGraphics, AdvChartCustomControl, Controls, Types, AdvChartBitmapSelector,
  AdvChartPopup, AdvChartTypes, AdvChartBitmapContainer, StdCtrls, AdvChartColorSelector,
  {%H-}AdvChartToolBarRes
  {$IFNDEF LCLLIB}
  ,UITypes, Generics.Collections, Generics.Defaults
  {$ENDIF}
  {$IFDEF FMXLIB}
  ,FMX.ListBox, FMX.Menus, FMX.Types, FMX.Edit
  {$ENDIF}
  {$IFDEF CMNLIB}
  ,Menus, ExtCtrls
  {$ENDIF}
  {$IFDEF LCLLIB}
  ,fgl
  {$ENDIF}
  ;

const
  MAJ_VER = 1; // Major version nr.
  MIN_VER = 0; // Minor version nr.
  REL_VER = 1; // Release nr.
  BLD_VER = 0; // Build nr.

  // version history
  // v1.0.0.0 : first release
  // v1.0.1.0 : New : DisabledBitmaps property

type
  TAdvChartCustomToolBar = class;
  TAdvChartCustomDockPanel = class;
  TAdvChartCustomToolBarSeparator = class;
  TAdvChartDefaultToolBarButton = class;
  TAdvChartToolBarButton = class;
  TAdvChartToolBarDropDownButton = class;
  TAdvChartToolBarFontNamePicker = class;
  TAdvChartToolBarFontSizePicker = class;
  TAdvChartToolBarColorPicker = class;
  TAdvChartToolBarBitmapPicker = class;

  TAdvChartToolBarButtonAppearance = class(TPersistent)
  private
    FOwner: TAdvChartDefaultToolBarButton;
    FHoverStroke: TAdvChartGraphicsStroke;
    FDownFill: TAdvChartGraphicsFill;
    FNormalFill: TAdvChartGraphicsFill;
    FDownStroke: TAdvChartGraphicsStroke;
    FDisabledFill: TAdvChartGraphicsFill;
    FNormalStroke: TAdvChartGraphicsStroke;
    FDisabledStroke: TAdvChartGraphicsStroke;
    FHoverFill: TAdvChartGraphicsFill;
    FCorners: TAdvChartGraphicsCorners;
    FRounding: Single;
    FTransparent: Boolean;
    FShowInnerStroke: Boolean;
    FInnerStroke: TAdvChartGraphicsStroke;
    FFlatStyle: Boolean;
    procedure SetDisabledFill(const Value: TAdvChartGraphicsFill);
    procedure SetDisabledStroke(const Value: TAdvChartGraphicsStroke);
    procedure SetDownFill(const Value: TAdvChartGraphicsFill);
    procedure SetDownStroke(const Value: TAdvChartGraphicsStroke);
    procedure SetHoverFill(const Value: TAdvChartGraphicsFill);
    procedure SetHoverStroke(const Value: TAdvChartGraphicsStroke);
    procedure SetNormalFill(const Value: TAdvChartGraphicsFill);
    procedure SetNormalStroke(const Value: TAdvChartGraphicsStroke);
    procedure SetCorners(const Value: TAdvChartGraphicsCorners); virtual;
    procedure SetRounding(const Value: Single); virtual;
    procedure SetInnerStroke(const Value: TAdvChartGraphicsStroke);
    procedure SetShowInnerStroke(const Value: Boolean);
    procedure SetTransparent(const Value: Boolean);
    function IsRoundingStored: Boolean;
    procedure SetFlatStyle(const Value: Boolean);
  protected
    procedure FillChanged(Sender: TObject);
    procedure StrokeChanged(Sender: TObject);
    procedure AppearanceChanged;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TAdvChartDefaultToolBarButton);
    destructor Destroy; override;
  published
    property Transparent: Boolean read FTransparent write SetTransparent default False;
    property ShowInnerStroke: Boolean read FShowInnerStroke write SetShowInnerStroke default True;
    property Rounding: Single read FRounding write SetRounding stored IsRoundingStored nodefault;
    property Corners: TAdvChartGraphicsCorners read FCorners write SetCorners default [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight];
    property InnerStroke: TAdvChartGraphicsStroke read FInnerStroke write SetInnerStroke;
    property NormalFill: TAdvChartGraphicsFill read FNormalFill write SetNormalFill;
    property NormalStroke: TAdvChartGraphicsStroke read FNormalStroke write SetNormalStroke;
    property HoverFill: TAdvChartGraphicsFill read FHoverFill write SetHoverFill;
    property HoverStroke: TAdvChartGraphicsStroke read FHoverStroke write SetHoverStroke;
    property DownFill: TAdvChartGraphicsFill read FDownFill write SetDownFill;
    property DownStroke: TAdvChartGraphicsStroke read FDownStroke write SetDownStroke;
    property DisabledFill: TAdvChartGraphicsFill read FDisabledFill write SetDisabledFill;
    property DisabledStroke: TAdvChartGraphicsStroke read FDisabledStroke write SetDisabledStroke;
    property FlatStyle: Boolean read FFlatStyle write SetFlatStyle default False;
  end;

  TAdvChartToolBarElementState = (esNormal, esLarge);

  TAdvChartCustomToolBarElement = class(TAdvChartCustomControl)
  private
    FOnUpdateToolBar: TNotifyEvent;
    FOnUpdateToolBarControl: TNotifyEvent;
    FCanCopy: Boolean;
    FState: TAdvChartToolBarElementState;
    FLastElement: Boolean;
    procedure SetState(const Value: TAdvChartToolBarElementState);
    procedure SetLastElement(const Value: Boolean);
  protected
    procedure UpdateState; virtual;
    procedure UpdateToolBar; virtual;
    procedure UpdateToolBarControl; virtual;
    {$IFDEF FMXLIB}
    procedure SetVisible(const Value: Boolean); override;
    procedure DoMatrixChanged(Sender: TObject); override;
    {$ENDIF}
    {$IFDEF CMNLIB}
    procedure VisibleChanging; override;
    {$ENDIF}
    procedure UpdateControlAfterResize; override;
    property OnUpdateToolBar: TNotifyEvent read FOnUpdateToolBar write FOnUpdateToolBar;
    property OnUpdateToolBarControl: TNotifyEvent read FOnUpdateToolBarControl write FOnUpdateToolBarControl;
    property State: TAdvChartToolBarElementState read FState write SetState default esNormal;
    property LastElement: Boolean read FLastElement write SetLastElement default False;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    property CanCopy: Boolean read FCanCopy write FCanCopy default True;
  end;

  TAdvChartDefaultToolBarButton = class(TAdvChartCustomToolBarElement, IAdvChartBitmapContainer)
  private
    FBitmapVisible: Boolean;
    FText: String;
    FPopup: TAdvChartPopup;
    FPopupPlacement: TAdvChartPopupPlacement;
    FDropDownHeight: Single;
    FDropDownWidth: Single;
    FDown, FHover, FPrevHover: Boolean;
    FAppearance: TAdvChartToolBarButtonAppearance;
    FBitmapContainer: TAdvChartBitmapContainer;
    FBitmaps: TAdvScaledBitmaps;
    FApplyName: Boolean;
    FDropDownControl: TControl;
    FFont: TAdvChartGraphicsFont;
    FOnBeforeDropDown: TNotifyEvent;
    FCloseOnSelection: Boolean;
    FDownState: Boolean;
    FTextVisible: Boolean;
    FOnCloseDropDown: TNotifyEvent;
    FOnDropDown: TNotifyEvent;
    FVerticalTextAlign: TAdvChartGraphicsTextAlign;
    FHorizontalTextAlign: TAdvChartGraphicsTextAlign;
    FWordWrapping: Boolean;
    FTrimming: TAdvChartGraphicsTextTrimming;
    FBitmapSize: Single;
    FStretchText: Boolean;
    FDisabledBitmaps: TAdvScaledBitmaps;
    FShowFocus: Boolean;
    procedure SetAppearance(const Value: TAdvChartToolBarButtonAppearance);
    procedure SetBitmapContainer(const Value: TAdvChartBitmapContainer);
    procedure SetBitmaps(const Value: TAdvScaledBitmaps);
    procedure SetText(const Value: String);
    procedure SetDropDownHeight(const Value: Single);
    procedure SetDropDownWidth(const Value: Single);
    procedure SetBitmapVisible(const Value: Boolean);
    procedure SetTextVisible(const Value: Boolean);
    procedure SetFont(const Value: TAdvChartGraphicsFont);
    procedure SetDropDownControl(const Value: TControl);
    procedure SetCloseOnSelection(const Value: Boolean);
    procedure SetDownState(const Value: Boolean);
    function IsDropDownHeightStored: Boolean;
    function IsDropDownWidthStored: Boolean;
    procedure SetHorizontalTextAlign(const Value: TAdvChartGraphicsTextAlign);
    procedure SetVerticalTextAlign(const Value: TAdvChartGraphicsTextAlign);
    procedure SetWordWrapping(const Value: Boolean);
    procedure SetTrimming(const Value: TAdvChartGraphicsTextTrimming);
    function IsBitmapSizeStored: Boolean;
    procedure SetBitmapSize(const Value: Single);
    procedure SetStretchText(const Value: Boolean);
    procedure SetDisabledBitmaps(const Value: TAdvScaledBitmaps);
    function GetBitmapContainer: TAdvChartBitmapContainer;
    procedure SetShowFocus(const Value: Boolean);
  protected
    function HasHint: Boolean; override;
    function GetHintString: String; override;
    function GetText: String; virtual;
    procedure ApplyStyle; override;
    procedure ResetToDefaultStyle; override;
    procedure SetAdaptToStyle(const Value: Boolean); override;
    procedure BitmapsChanged(Sender: TObject);
    procedure DoFontChanged(Sender: TObject);
    procedure PopupCloseUp(Sender: TObject);
    procedure DoPopup(Sender: TObject);
    procedure InitializePopup; virtual;
    procedure UpdateState; override;
    procedure AppearanceChanged; virtual;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetName(const Value: TComponentName); override;
    procedure HandleMouseDown(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Single); override;
    procedure HandleMouseMove(Shift: TShiftState; X, Y: Single); override;
    procedure HandleMouseUp(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Single); override;
    procedure HandleKeyUp(var Key: Word; Shift: TShiftState); override;
    procedure HandleKeyDown(var Key: Word; Shift: TShiftState); override;
    procedure HandleKeyPress(var Key: Char); override;
    procedure HandleMouseEnter; override;
    procedure HandleMouseLeave; override;
    procedure SelectFirstValue; virtual;
    procedure SelectValueWithCharacter({%H-}ACharacter: Char); virtual;
    procedure SelectLastValue; virtual;
    procedure SelectNextValue; virtual;
    procedure SelectPreviousValue; virtual;
    procedure DrawText(AGraphics: TAdvChartGraphics); virtual;
    procedure DrawBitmap(AGraphics: TAdvChartGraphics); virtual;
    function CanDropDown: Boolean; virtual;
    function CanChangeText: Boolean; virtual;
    function GetTextRect: TRectF; virtual;
    function GetDropDownRect: TRectF; virtual;
    function GetBitmapRect: TRectF; virtual;
    property Appearance: TAdvChartToolBarButtonAppearance read FAppearance write SetAppearance;
    property BitmapVisible: Boolean read FBitmapVisible write SetBitmapVisible default False;
    property Bitmaps: TAdvScaledBitmaps read FBitmaps write SetBitmaps;
    property DisabledBitmaps: TAdvScaledBitmaps read FDisabledBitmaps write SetDisabledBitmaps;
    property BitmapContainer: TAdvChartBitmapContainer read GetBitmapContainer write SetBitmapContainer;
    property BitmapSize: Single read FBitmapSize write SetBitmapSize stored IsBitmapSizeStored nodefault;
    property Text: String read GetText write SetText;
    property Trimming: TAdvChartGraphicsTextTrimming read FTrimming write SetTrimming default gttCharacter;
    property HorizontalTextAlign: TAdvChartGraphicsTextAlign read FHorizontalTextAlign write SetHorizontalTextAlign default gtaCenter;
    property VerticalTextAlign: TAdvChartGraphicsTextAlign read FVerticalTextAlign write SetVerticalTextAlign default gtaCenter;
    property Font: TAdvChartGraphicsFont read FFont write SetFont;
    property TextVisible: Boolean read FTextVisible write SetTextVisible default True;
    property StretchText: Boolean read FStretchText write SetStretchText default False;
    property WordWrapping: Boolean read FWordWrapping write SetWordWrapping default False;
    property DropDownHeight: Single read FDropDownHeight write SetDropDownHeight stored IsDropDownHeightStored nodefault;
    property DropDownWidth: Single read FDropDownWidth write SetDropDownWidth stored IsDropDownWidthStored nodefault;
    property DropDownControl: TControl read FDropDownControl write SetDropDownControl;
    property CloseOnSelection: Boolean read FCloseOnSelection write SetCloseOnSelection default True;
    property OnBeforeDropDown: TNotifyEvent read FOnBeforeDropDown write FOnBeforeDropDown;
    property OnDropDown: TNotifyEvent read FOnDropDown write FOnDropDown;
    property OnCloseDropDown: TNotifyEvent read FOnCloseDropDown write FOnCloseDropDown;
    property ApplyName: Boolean read FApplyName write FApplyName default True;
    property ShowFocus: Boolean read FShowFocus write SetShowFocus default False;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Draw(AGraphics: TAdvChartGraphics; ARect: TRectF); override;
    procedure DropDown; virtual;
    procedure CloseDropDown; virtual;
    function GetPopupControl: TAdvChartPopup;
    function GetBitmap: TAdvChartBitmap; virtual;
    property DownState: Boolean read FDownState write SetDownState;
    property PopupPlacement: TAdvChartPopupPlacement read FPopupPlacement write FPopupPlacement default ppBottom;
  end;

  TAdvChartToolBarButtonDropDownKind = (ddkNormal, ddkDropDown, ddkDropDownButton);
  TAdvChartToolBarButtonDropDownPosition = (ddpRight, ddpBottom);

  TAdvChartCustomToolBarButton = class(TAdvChartDefaultToolBarButton)
  private
    FDropDownButton: TAdvChartToolBarDropDownButton;
    FDropDownKind: TAdvChartToolBarButtonDropDownKind;
    FDropDownPosition: TAdvChartToolBarButtonDropDownPosition;
    FHidden: Boolean;
    FAutoOptionsMenuText: String;
    procedure SetDropDownKind(const Value: TAdvChartToolBarButtonDropDownKind);
    procedure SetDropDownPosition(
      const Value: TAdvChartToolBarButtonDropDownPosition);
    procedure SetHidden(const Value: Boolean);
  protected
    procedure SetAdaptToStyle(const Value: Boolean); override;
    procedure DoFontChanged(Sender: TObject);
    procedure AppearanceChanged; override;
    procedure UpdateDropDownButton; virtual;
    procedure HandleMouseDown(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Single); override;
    procedure DropDownButtonClick(Sender: TObject);
    function GetDropDownRect: TRectF; override;
    function GetTextRect: TRectF; override;
    function GetBitmapRect: TRectF; override;
    function CanDropDown: Boolean; override;
    property DropDownKind: TAdvChartToolBarButtonDropDownKind read FDropDownKind write SetDropDownKind default ddkNormal;
    property DropDownPosition: TAdvChartToolBarButtonDropDownPosition read FDropDownPosition write SetDropDownPosition default ddpRight;
    property AutoOptionsMenuText: String read FAutoOptionsMenuText write FAutoOptionsMenuText;
    property Hidden: Boolean read FHidden write SetHidden default False;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetDropDownButtonControl: TAdvChartToolBarDropDownButton;
  end;

  TAdvChartCustomToolBarSeparatorAppearance = class(TPersistent)
  private
    FOwner: TAdvChartCustomToolBarSeparator;
    FStroke: TAdvChartGraphicsStroke;
    procedure SetStroke(const Value: TAdvChartGraphicsStroke);
  protected
    procedure StrokeChanged(Sender: TObject);
    property Stroke: TAdvChartGraphicsStroke read FStroke write SetStroke;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TAdvChartCustomToolBarSeparator);
    destructor Destroy; override;
  end;

  TAdvChartToolBarSeparatorAppearance = class(TAdvChartCustomToolBarSeparatorAppearance)
  published
    property Stroke;
  end;

  TAdvChartCustomToolBarSeparator = class(TAdvChartCustomToolBarElement)
  private
    FAppearance: TAdvChartToolBarSeparatorAppearance;
    procedure SetAppearance(const Value: TAdvChartToolBarSeparatorAppearance);
  protected
    procedure UpdateState; override;
    property Appearance: TAdvChartToolBarSeparatorAppearance read FAppearance write SetAppearance;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Draw(AGraphics: TAdvChartGraphics; ARect: TRectF); override;
  end;

  TAdvChartToolBarDropDownButton = class(TAdvChartDefaultToolBarButton)
  protected
    function GetBitmapRect: TRectF; override;
  published
    property Font;
    property Text;
    property ShowFocus;
    property TextVisible;
    property StretchText;
    property WordWrapping;
    property HorizontalTextAlign;
    property VerticalTextAlign;
    property Trimming;
    property Bitmaps;
    property DisabledBitmaps;
    property BitmapVisible;
    property BitmapContainer;
    property State;
    property LastElement;
    property Appearance;
  end;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartToolBarButton = class(TAdvChartCustomToolBarButton)
  public
    property Hidden;
  published
    property Font;
    property AutoOptionsMenuText;
    property DropDownKind;
    property DropDownPosition;
    property DropDownHeight;
    property DropDownWidth;
    property DropDownControl;
    property OnBeforeDropDown;
    property OnDropDown;
    property OnCloseDropDown;
    property Text;
    property ShowFocus;
    property TextVisible;
    property StretchText;
    property HorizontalTextAlign;
    property VerticalTextAlign;
    property Trimming;
    property Bitmaps;
    property DisabledBitmaps;
    property BitmapVisible;
    property BitmapContainer;
    property BitmapSize;
    property State;
    property LastElement;
    property Appearance;
  end;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartToolBarSeparator = class(TAdvChartCustomToolBarSeparator)
  published
    property State;
    property LastElement;
    property Appearance;
  end;

  TAdvChartToolBarItemPickerItemSelected = procedure(Sender: TObject; AItemIndex: Integer) of object;

  TAdvChartToolBarCustomItemPicker = class(TAdvChartToolBarButton)
  private
    FEdit: TEdit;
    FTimer: TTimer;
    FItemIndex: Integer;
    FItems: TStringList;
    FKeyboardUsed: Boolean;
    FItemSelector: TListBox;
    FOnItemSelected: TAdvChartToolBarItemPickerItemSelected;
    FEditable: Boolean;
    FOnEditChange: TNotifyEvent;
    function GetSelectedItemIndex: Integer;
    procedure SetSelectedItemIndex(const Value: Integer);
    function GetSelectedItem: String;
    procedure SetSelectedItem(const Value: String);
    procedure SetItems(const Value: TStringList);
    procedure SetEditable(const Value: Boolean);
  protected
    function CanChangeText: Boolean; override;
    function GetText: String; override;
    procedure EnterTimerChanged(Sender: TObject);
    procedure EditChange(Sender: TObject);
    procedure HandleDialogKey(var Key: Word; Shift: TShiftState); override;
    procedure InitializePopup; override;
    procedure SelectValueWithString(AValue: string); virtual;
    procedure SelectValueWithCharacter(ACharacter: Char); override;
    procedure SelectFirstValue; override;
    procedure SelectLastValue; override;
    procedure SelectNextValue; override;
    procedure SelectPreviousValue; override;
    {$IFDEF FMXLIB}
    procedure ItemKeyUp(Sender: TObject; var Key: Word; var KeyChar: WideChar; Shift: TShiftState);
    procedure ItemKeyDown(Sender: TObject; var Key: Word; var KeyChar: WideChar; Shift: TShiftState);
    procedure ItemSelected(const Sender: TCustomListBox; const Item: TListBoxItem);
    {$ENDIF}
    {$IFDEF CMNLIB}
    procedure ItemKeyUp(Sender: TObject; var {%H-}Key: Word; {%H-}Shift: TShiftState);
    procedure ItemKeyDown(Sender: TObject; var {%H-}Key: Word; {%H-}Shift: TShiftState);
    procedure ItemSelected(Sender: TObject);
    {$ENDIF}
    procedure DoItemSelected; virtual;
    procedure DoEnter; override;
    property CloseOnSelection;
    property Items: TStringList read FItems write SetItems;
    property OnItemSelected: TAdvChartToolBarItemPickerItemSelected read FOnItemSelected write FOnItemSelected;
    property ListBox: TListBox read FItemSelector;
    property SelectedItemIndex: Integer read GetSelectedItemIndex write SetSelectedItemIndex default -1;
    property SelectedItem: String read GetSelectedItem write SetSelectedItem;
    property Editable: Boolean read FEditable write SetEditable default False;
    property OnEditChange: TNotifyEvent read FOnEditChange write FOnEditChange;
  public
    constructor Create(AOwner: TComponent); override;
    procedure Draw(AGraphics: TAdvChartGraphics; ARect: TRectF); override;
    destructor Destroy; override;
    procedure DropDown; override;
  end;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartToolBarItemPicker = class(TAdvChartToolBarCustomItemPicker)
  published
    property OnItemSelected;
    property SelectedItemIndex;
    property Items;
    property Editable;
    property OnEditChange;
  end;

  TAdvChartToolBarFontNamePickerFontNameSelected = procedure(Sender: TObject; AFontName: String) of object;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartToolBarFontNamePicker = class(TAdvChartToolBarCustomItemPicker)
  private
    FOnFontNameSelected: TAdvChartToolBarFontNamePickerFontNameSelected;
    function GetSelectedFontName: String;
    procedure SetSelectedFontName(const Value: String);
  protected
    procedure DoItemSelected; override;
  public
    constructor Create(AOwner: TComponent); override;
    property SelectedFontName: String read GetSelectedFontName write SetSelectedFontName;
    property SelectedItemIndex;
    property Items;
  published
    property OnFontNameSelected: TAdvChartToolBarFontNamePickerFontNameSelected read FOnFontNameSelected write FOnFontNameSelected;
    property CloseOnSelection;
    property Editable;
    property OnEditChange;
  end;

  TAdvChartToolBarFontSizePickerFontSizeSelected = procedure(Sender: TObject; AFontSize: Single) of object;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartToolBarFontSizePicker = class(TAdvChartToolBarCustomItemPicker)
  private
    FOnFontSizeSelected: TAdvChartToolBarFontSizePickerFontSizeSelected;
    function GetSelectedFontSize: Single;
    procedure SetSelectedFontSize(const Value: Single);
  protected
    procedure DoItemSelected; override;
  public
    constructor Create(AOwner: TComponent); override;
    property SelectedFontSize: Single read GetSelectedFontSize write SetSelectedFontSize;
    property SelectedItemIndex;
    property Items;
  published
    property OnFontSizeSelected: TAdvChartToolBarFontSizePickerFontSizeSelected read FOnFontSizeSelected write FOnFontSizeSelected;
    property CloseOnSelection;
    property Editable;
    property OnEditChange;
  end;

  TAdvChartToolBarColorPickerColorSelected = procedure(Sender: TObject; AColor: TAdvChartGraphicsColor) of object;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartToolBarColorPicker = class(TAdvChartToolBarButton)
  private
    FColorSelector: TAdvChartColorSelector;
    FOnColorSelected: TAdvChartToolBarColorPickerColorSelected;
    function GetSelectedColor: TAdvChartGraphicsColor;
    procedure SetSelectedColor(const Value: TAdvChartGraphicsColor);
    function GetSelectedItemIndex: Integer;
    procedure SetSelectedItemIndex(const Value: Integer);
    function GetItems: TAdvChartColorSelectorItems;
    procedure SetItems(const Value: TAdvChartColorSelectorItems);
  protected
    procedure SetAdaptToStyle(const Value: Boolean); override;
    procedure DrawColor(AColor: TAdvChartGraphicsColor; ARect: TRectF; AGraphics: TAdvChartGraphics);
    function CanChangeText: Boolean; override;
    procedure ColorSelected(Sender: TObject; AColor: TAdvChartGraphicsColor);
    procedure DoColorSelected(AColor: TAdvChartGraphicsColor); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    function BlockChange: Boolean;
    function ColorSelector: TAdvChartColorSelector;
    procedure Draw(AGraphics: TAdvChartGraphics; ARect: TRectF); override;
    procedure DrawSelectedColor(AGraphics: TAdvChartGraphics; {%H-}ARect: TRectF); virtual;
  published
    property OnColorSelected: TAdvChartToolBarColorPickerColorSelected read FOnColorSelected write FOnColorSelected;
    property SelectedColor: TAdvChartGraphicsColor read GetSelectedColor write SetSelectedColor default gcNull;
    property SelectedItemIndex: Integer read GetSelectedItemIndex write SetSelectedItemIndex;
    property Items: TAdvChartColorSelectorItems read GetItems write SetItems;
    property CloseOnSelection;
  end;

  TAdvChartToolBarBitmapPickerBitmapSelected = procedure(Sender: TObject; ABitmap: TAdvChartBitmap) of object;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartToolBarBitmapPicker = class(TAdvChartToolBarButton)
  private
    FBitmapSelector: TAdvChartBitmapSelector;
    FOnBitmapSelected: TAdvChartToolBarBitmapPickerBitmapSelected;
    function GetSelectedBitmap: TAdvChartBitmap;
    function GetSelectedItemIndex: Integer;
    procedure SetSelectedItemIndex(const Value: Integer);
    function GetItems: TAdvChartBitmapSelectorItems;
    procedure SetItems(const Value: TAdvChartBitmapSelectorItems);
  protected
    procedure SetAdaptToStyle(const Value: Boolean); override;
    function GetBitmapRect: TRectF; override;
    function CanChangeText: Boolean; override;
    procedure BitmapSelected(Sender: TObject; ABitmap: TAdvChartBitmap);
    procedure DoBitmapSelected(ABitmap: TAdvChartBitmap); virtual;
  public
    constructor Create(AOwner: TComponent); override;
    function BlockChange: Boolean;
    function BitmapSelector: TAdvChartBitmapSelector;
    property SelectedBitmap: TAdvChartBitmap read GetSelectedBitmap;
  published
    property OnBitmapSelected: TAdvChartToolBarBitmapPickerBitmapSelected read FOnBitmapSelected write FOnBitmapSelected;
    property SelectedItemIndex: Integer read GetSelectedItemIndex write SetSelectedItemIndex;
    property Items: TAdvChartBitmapSelectorItems read GetItems write SetItems;
    property CloseOnSelection;
  end;

  TAdvChartCustomToolBarAppearance = class(TPersistent)
  private
    FOwner: TAdvChartCustomToolBar;
    FFill: TAdvChartGraphicsFill;
    FStroke: TAdvChartGraphicsStroke;
    FVerticalSpacing: Single;
    FHorizontalSpacing: Single;
    FDragGripColor: TAdvChartGraphicsColor;
    FDragGrip: Boolean;
    FFlatStyle: Boolean;
    procedure SetFill(const Value: TAdvChartGraphicsFill);
    procedure SetStroke(const Value: TAdvChartGraphicsStroke);
    procedure SetHorizontalSpacing(const Value: Single);
    procedure SetVerticalSpacing(const Value: Single);
    procedure SetDragGrip(const Value: Boolean);
    procedure SetDragGripColor(const Value: TAdvChartGraphicsColor);
    function IsHorizontalSpacingStored: Boolean;
    function IsVerticalSpacingStored: Boolean;
    procedure SetFlatStyle(const Value: Boolean);
  protected
    procedure FillChanged(Sender: TObject);
    procedure StrokeChanged(Sender: TObject);
    property Fill: TAdvChartGraphicsFill read FFill write SetFill;
    property Stroke: TAdvChartGraphicsStroke read FStroke write SetStroke;
    property HorizontalSpacing: Single read FHorizontalSpacing write SetHorizontalSpacing stored IsHorizontalSpacingStored nodefault;
    property VerticalSpacing: Single read FVerticalSpacing write SetVerticalSpacing stored IsVerticalSpacingStored nodefault;
    property DragGrip: Boolean read FDragGrip write SetDragGrip default True;
    property DragGripColor: TAdvChartGraphicsColor read FDragGripColor write SetDragGripColor default gcLightgray;
    property FlatStyle: Boolean read FFlatStyle write SetFlatStyle default False;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TAdvChartCustomToolBar);
    destructor Destroy; override;
  end;

  TAdvChartToolBarAppearance = class(TAdvChartCustomToolBarAppearance)
  published
    property FlatStyle;
    property Fill;
    property Stroke;
    property HorizontalSpacing;
    property VerticalSpacing;
    property DragGrip;
    property DragGripColor;
  end;

  TAdvChartToolBarOptionMenuItem = class(TMenuItem)
  private
    FControl: TControl;
    FGlyphWidth: Single;
    FCalculate: Boolean;
  protected
    property Calculate: Boolean read FCalculate write FCalculate;
    property GlyphWidth: Single read FGlyphWidth write FGlyphWidth;
  public
    property Control: TControl read FControl write FControl;
  end;

  TAdvChartToolBarControl = class(TPersistent)
  private
    FControlIndex: Integer;
    FControl: TControl;
    FBitmap: TAdvChartBitmap;
  public
    constructor Create;
    destructor Destroy; override;
  end;

  TControlClass = class of TControl;

  TAdvChartToolBarCustomizeOptionsMenu = procedure(Sender: TObject; APopupMenu: TPopupMenu) of object;
  TAdvChartToolBarCustomizeOptionsMenuItem = procedure(Sender: TObject; AControl: TControl; AMenuItem: TMenuItem) of object;
  TAdvChartToolBarCanShowOptionsMenuItem = procedure(Sender: TObject; AControl: TControl; var ACanShowItem: Boolean) of object;
  TAdvChartToolBarOptionsMenuItemClick = procedure(Sender: TObject; AControl: TControl; AMenuItem: TMenuItem; var AExecuteDefaultAction: Boolean) of object;
  TAdvChartToolBarIsLastElement = procedure(Sender: TObject; AControl: TControl; var AIsLastElement: Boolean) of object;

  TAdvChartCustomToolBarOptionsMenu = class(TPersistent)
  private
    FOwner: TAdvChartCustomToolBar;
    FShowItemText: Boolean;
    FShowItemBitmap: Boolean;
    FShowButton: Boolean;
    FItemBitmapWidth: Single;
    FAutoItemBitmapWidth: Boolean;
    procedure SetShowButton(const Value: Boolean);
    procedure SetShowItemBitmap(const Value: Boolean);
    procedure SetShowItemText(const Value: Boolean);
    procedure SetAutoItemBitmapWidth(const Value: Boolean);
    procedure SetItemBitmapWidth(const Value: Single);
    function IsItemBitmapWidthStored: Boolean;
  protected
    property ShowButton: Boolean read FShowButton write SetShowButton default True;
    property ShowItemBitmap: Boolean read FShowItemBitmap write SetShowItemBitmap default True;
    property ShowItemText: Boolean read FShowItemText write SetShowItemText default True;
    property AutoItemBitmapWidth: Boolean read FAutoItemBitmapWidth write SetAutoItemBitmapWidth default True;
    property ItemBitmapWidth: Single read FItemBitmapWidth write SetItemBitmapWidth stored IsItemBitmapWidthStored nodefault;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TAdvChartCustomToolBar);
    destructor Destroy; override;
  end;

  TAdvChartToolBarOptionsMenu = class(TAdvChartCustomToolBarOptionsMenu)
  published
    property ShowButton;
    property ShowItemBitmap;
    property ShowItemText;
    property AutoItemBitmapWidth;
    property ItemBitmapWidth;
  end;

  TAdvChartToolBarControlObjectList = TObjectList<TAdvChartToolBarControl>;
  TAdvChartToolBarControlList = TList<TAdvChartToolBarControl>;
  TAdvControlList = TList<TControl>;
  TAdvChartToolBarDragGripMovingEvent = procedure(Sender: TObject; DeltaX: Double; DeltaY: Double) of object;

  TAdvChartCustomToolBar = class(TAdvChartCustomControl)
  private
    FInsideDrag, FDragGripMoving, FDragGripDown: Boolean;
    FDragGripDownPt: TPointF;
    FTotalOptionsMenuWidth: Single;
    {$IFNDEF LCLLIB}
    FCompareControls: IComparer<TControl>;
    FCompareHiddenControls: IComparer<TAdvChartToolBarControl>;
    {$ENDIF}
    FHiddenControls: TAdvChartToolBarControlObjectList;
    FBlockUpdate: Boolean;
    FAutoSize: Boolean;
    FAppearance: TAdvChartToolBarAppearance;
    FAutoAlign: Boolean;
    FOptionsMenuButton: TAdvChartToolBarDropDownButton;
    FAutoOptionsMenu: TPopupMenu;
    FOnOptionsMenuCustomize: TAdvChartToolBarCustomizeOptionsMenu;
    FOnOptionsMenuItemCustomize: TAdvChartToolBarCustomizeOptionsMenuItem;
    FOnOptionsMenuButtonClick: TNotifyEvent;
    FOptionsMenu: TAdvChartToolBarOptionsMenu;
    FCustomOptionsMenu: TPopupMenu;
    FOnOptionsMenuItemCanShow: TAdvChartToolBarCanShowOptionsMenuItem;
    FState: TAdvChartToolBarElementState;
    FOnOptionsMenuItemClick: TAdvChartToolBarOptionsMenuItemClick;
    FOnOptionsMenuItemApplyStyle: TAdvChartToolBarCustomizeOptionsMenuItem;
    FOnUpdateDockPanel: TNotifyEvent;
    FOnUpdateControls: TNotifyEvent;
    FOnIsLastElement: TAdvChartToolBarIsLastElement;
    FOnDragGripMoving: TAdvChartToolBarDragGripMovingEvent;
    FAutoMoveToolBar: Boolean;
    procedure SetAppearance(const Value: TAdvChartToolBarAppearance);
    procedure SetAS(const Value: Boolean);
    procedure SetAutoAlign(const Value: Boolean);
    procedure SetOptionsMenu(const Value: TAdvChartToolBarOptionsMenu);
    procedure SetState(const Value: TAdvChartToolBarElementState);
  protected
    function GetVersion: String; override;
    procedure SetAdaptToStyle(const Value: Boolean); override;
    procedure ApplyStyle; override;
    procedure ResetToDefaultStyle; override;
    property BlockUpdate: Boolean read FBlockUpdate write FBlockUpdate;
    property OnUpdateControls: TNotifyEvent read FOnUpdateControls write FOnUpdateControls;
    property OnUpdateDockPanel: TNotifyEvent read FOnUpdateDockPanel write FOnUpdateDockPanel;
    procedure HandleMouseDown(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Single); override;
    procedure HandleMouseMove(Shift: TShiftState; X, Y: Single); override;
    procedure HandleMouseUp(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Single); override;
    procedure UpdateDockPanel; virtual;
    procedure InsertToolBarControl(AControl: TControl; {%H-}AIndex: Integer);
    procedure DoDragGripMoving(ADeltaX, ADeltaY: Double); virtual;
    {$IFDEF FMXLIB}
    procedure SetVisible(const Value: Boolean); override;
    procedure DoMatrixChanged(Sender: TObject); override;
    {$ENDIF}
    {$IFDEF CMNLIB}
    procedure VisibleChanging; override;
    {$ENDIF}
    function GetDragGripRect(AInteraction: Boolean = False): TRectF;
    procedure DoCustomizeOptionsMenu; virtual;
    procedure DoCustomizeOptionsMenuItem(AControl: TControl; AMenuItem: TMenuItem); virtual;
    procedure DoCanShowOptionsMenuItem(AControl: TControl; var ACanShowItem: Boolean); virtual;
    function GetHiddenControl(AControl: TControl): TAdvChartToolBarControl;
    function GetHiddenControlCount(AControl: TControl): Integer;
    procedure UpdateToolBar(Sender: TObject);
    procedure DoIsLastElement(AControl: TControl; var ALastElement: Boolean);
    procedure UpdateToolBarControl(Sender: TObject);
    procedure OptionMenuItemClick(Sender: TObject);
    {$IFDEF FMXLIB}
    procedure OptionMenuItemApplyStyleLookup(Sender: TObject);
    {$ENDIF}
    procedure OptionsButtonClick(Sender: TObject);
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;

    {$IFDEF FMXLIB}
    procedure DoRealign; override;
    procedure DoAddObject(const AObject: TFmxObject); override;
    procedure DoInsertObject(Index: Integer; const AObject: TFmxObject); override;
    procedure DoRemoveObject(const AObject: TFmxObject); override;
    {$ENDIF}

    {$IFDEF CMNLIB}
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    {$ENDIF}
    procedure UpdateControlAfterResize; override;
    procedure UpdateControls; virtual;
    procedure HandleMouseLeave; override;
    procedure InitializeOptionsMenu; virtual;
    procedure DrawDragGrip(AGraphics: TAdvChartGraphics); virtual;
    procedure ShowOptionsMenu(X, Y: Single); virtual;
    property Version: String read GetVersion;
    property AutoSize: Boolean read FAutoSize write SetAS default True;
    property AutoAlign: Boolean read FAutoAlign write SetAutoAlign default True;
    property AutoMoveToolBar: Boolean read FAutoMoveToolBar write FAutoMoveToolBar default True;
    property Appearance: TAdvChartToolBarAppearance read FAppearance write SetAppearance;
    property OptionsMenu: TAdvChartToolBarOptionsMenu read FOptionsMenu write SetOptionsMenu;
    property OnOptionsMenuItemCanShow: TAdvChartToolBarCanShowOptionsMenuItem read FOnOptionsMenuItemCanShow write FOnOptionsMenuItemCanShow;
    property OnOptionsMenuCustomize: TAdvChartToolBarCustomizeOptionsMenu read FOnOptionsMenuCustomize write FOnOptionsMenuCustomize;
    property OnOptionsMenuItemCustomize: TAdvChartToolBarCustomizeOptionsMenuItem read FOnOptionsMenuItemCustomize write FOnOptionsMenuItemCustomize;
    property OnOptionsMenuItemApplyStyle: TAdvChartToolBarCustomizeOptionsMenuItem read FOnOptionsMenuItemApplyStyle write FOnOptionsMenuItemApplyStyle;
    property OnOptionsMenuButtonClick: TNotifyEvent read FOnOptionsMenuButtonClick write FOnOptionsMenuButtonClick;
    property OnOptionsMenuItemClick: TAdvChartToolBarOptionsMenuItemClick read FOnOptionsMenuItemClick write FOnOptionsMenuItemClick;
    property CustomOptionsMenu: TPopupMenu read FCustomOptionsMenu write FCustomOptionsMenu;
    property State: TAdvChartToolBarElementState read FState write SetState default esNormal;
    property OnIsLastElement: TAdvChartToolBarIsLastElement read FOnIsLastElement write FOnIsLastElement;
    property OnDragGripMoving: TAdvChartToolBarDragGripMovingEvent read FOnDragGripMoving write FOnDragGripMoving;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Draw(AGraphics: TAdvChartGraphics; ARect: TRectF); override;
    function DropDownActive: Boolean; virtual;
    procedure AddCustomControl(AControl: TControl; AIndex: Integer = -1); virtual;
    function AddCustomControlClass(AControlClass: TControlClass; AIndex: Integer = -1): TControl; virtual;
    function AddButton(AWidth: Single = -1; AHeight: Single = -1; AResource: String = ''; AResourceLarge: String = ''; AText: String = '';
      AIndex: Integer = -1): TAdvChartToolBarButton; overload; virtual;
    function AddSeparator(AIndex: Integer = -1): TAdvChartToolBarSeparator; virtual;
    function AddFontNamePicker(AIndex: Integer = -1): TAdvChartToolBarFontNamePicker; virtual;
    function AddFontSizePicker(AIndex: Integer = -1): TAdvChartToolBarFontSizePicker; virtual;
    function AddColorPicker(AIndex: Integer = -1): TAdvChartToolBarColorPicker; virtual;
    function AddItemPicker(AIndex: Integer = -1): TAdvChartToolBarItemPicker; virtual;
    function AddBitmapPicker(AIndex: Integer = -1): TAdvChartToolBarBitmapPicker; virtual;
    function GetOptionsMenuButtonControl: TAdvChartToolBarDropDownButton; virtual;
  end;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvChartToolBar = class(TAdvChartCustomToolBar)
  published
    property OnOptionsMenuButtonClick;
    property OnOptionsMenuItemCanShow;
    property OnOptionsMenuCustomize;
    property OnOptionsMenuItemCustomize;
    property OnOptionsMenuItemApplyStyle;
    property OnOptionsMenuItemClick;
    property OnIsLastElement;
    property OnDragGripMoving;
    //
    property Version;
    property AutoSize;
    property AutoAlign;
    property AutoMoveToolBar;
    property Appearance;
    property OptionsMenu;
    property CustomOptionsMenu;
    property State;
  end;

  TAdvChartCustomDockPanelAppearance = class(TPersistent)
  private
    FOwner: TAdvChartCustomDockPanel;
    FFill: TAdvChartGraphicsFill;
    FStroke: TAdvChartGraphicsStroke;
    FMargins: TAdvMargins;
    procedure SetFill(const Value: TAdvChartGraphicsFill);
    procedure SetStroke(const Value: TAdvChartGraphicsStroke);
    procedure SetMargins(const Value: TAdvMargins);
  protected
    procedure FillChanged(Sender: TObject);
    procedure StrokeChanged(Sender: TObject);
    procedure MarginsChanged(Sender: TObject);
    property Fill: TAdvChartGraphicsFill read FFill write SetFill;
    property Stroke: TAdvChartGraphicsStroke read FStroke write SetStroke;
    property Margins: TAdvMargins read FMargins write SetMargins;
  public
    constructor Create(AOwner: TAdvChartCustomDockPanel);
    destructor Destroy; override;
  end;

  TAdvDockPanelAppearance = class(TAdvChartCustomDockPanelAppearance)
  published
    property Fill;
    property Stroke;
  end;

  TAdvChartCustomDockPanel = class(TAdvChartCustomControl)
  private
    FBlockUpdate: Boolean;
    FAppearance: TAdvDockPanelAppearance;
    FAutoSize: Boolean;
    FAutoAlign: Boolean;
    FState: TAdvChartToolBarElementState;
    procedure SetAppearance(const Value: TAdvDockPanelAppearance);
    procedure SetAutoAlign(const Value: Boolean);
    procedure SetAS(const Value: Boolean);
    procedure SetState(const Value: TAdvChartToolBarElementState);
  protected
    function GetVersion: String; override;
    procedure SetAdaptToStyle(const Value: Boolean); override;
    procedure UpdateControls; virtual;
    procedure InitializeControls; virtual;
    procedure RearrangeControls; virtual;
    procedure UpdateDockPanel(Sender: TObject);
    procedure ApplyStyle; override;
    procedure ResetToDefaultStyle; override;

    {$IFDEF FMXLIB}
    procedure DoRealign; override;
    procedure DoAddObject(const AObject: TFmxObject); override;
    procedure DoInsertObject(Index: Integer; const AObject: TFmxObject); override;
    procedure DoRemoveObject(const AObject: TFmxObject); override;
    {$ENDIF}
    {$IFDEF CMNLIB}
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    {$ENDIF}

    property Version: String read GetVersion;
    property Appearance: TAdvDockPanelAppearance read FAppearance write SetAppearance;
    property AutoSize: Boolean read FAutoSize write SetAS default True;
    property AutoAlign: Boolean read FAutoAlign write SetAutoAlign default True;
    property State: TAdvChartToolBarElementState read FState write SetState default esNormal;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Draw(AGraphics: TAdvChartGraphics; ARect: TRectF); override;
    function AddToolBar({%H-}AIndex: Integer = -1): TAdvChartToolBar;
  end;

  {$IFNDEF LCLLIB}
  [ComponentPlatformsAttribute(TMSPlatforms)]
  {$ENDIF}
  TAdvDockPanel = class(TAdvChartCustomDockPanel)
  published
    property Version;
    property Appearance;
    property AutoSize;
    property AutoAlign;
    property State;
  end;

implementation

uses
  Math, SysUtils, AdvChartUtils, Graphics, StrUtils, AdvChartStyles;

function TAdvChartCustomToolBar.AddBitmapPicker(
  AIndex: Integer): TAdvChartToolBarBitmapPicker;
begin
  FBlockUpdate := True;
  Result := TAdvChartToolBarBitmapPicker.Create(Self);
  InsertToolBarControl(Result, AIndex);
  FBlockUpdate := False;
  UpdateControls;
end;

function TAdvChartCustomToolBar.AddButton(AWidth: Single = -1; AHeight: Single = -1;
  AResource: String = ''; AResourceLarge: String = ''; AText: String = ''; AIndex: Integer = -1): TAdvChartToolBarButton;
begin
  FBlockUpdate := True;
  Result := TAdvChartToolBarButton.Create(Self);
  Result.Text := AText;
  if AWidth <> -1 then
  begin
    {$IFDEF FMXLIB}
    Result.Width := AWidth;
    {$ENDIF}
    {$IFDEF CMNLIB}
    Result.Width := Round(AWidth);
    {$ENDIF}
  end;

  if AHeight <> -1 then
  begin
    {$IFDEF FMXLIB}
    Result.Height := AHeight;
    {$ENDIF}
    {$IFDEF CMNLIB}
    Result.Height := Round(AHeight);
    {$ENDIF}
  end;

  Result.Bitmaps.AddBitmapFromResource(AResource, 1.0);
  Result.Bitmaps.AddBitmapFromResource(AResourceLarge, 1.5);
  Result.DisabledBitmaps.AddBitmapFromResource(AResource, 1.0);
  Result.DisabledBitmaps.AddBitmapFromResource(AResourceLarge, 1.5);

  InsertToolBarControl(Result, AIndex);

  FBlockUpdate := False;
  UpdateControls;
end;

function TAdvChartCustomToolBar.AddColorPicker(
  AIndex: Integer): TAdvChartToolBarColorPicker;
begin
  FBlockUpdate := True;
  Result := TAdvChartToolBarColorPicker.Create(Self);
  InsertToolBarControl(Result, AIndex);
  FBlockUpdate := False;
  UpdateControls;
end;

procedure TAdvChartCustomToolBar.AddCustomControl(AControl: TControl; AIndex: Integer = -1);
begin
  FBlockUpdate := True;
  InsertToolBarControl(AControl, AIndex);
  FBlockUpdate := False;
  UpdateControls;
end;

function TAdvChartCustomToolBar.AddCustomControlClass(AControlClass: TControlClass;
  AIndex: Integer = -1): TControl;
begin
  FBlockUpdate := True;
  Result := AControlClass.Create(Self);
  InsertToolBarControl(Result, AIndex);
  FBlockUpdate := False;
  UpdateControls;
end;

function TAdvChartCustomToolBar.AddFontNamePicker(
  AIndex: Integer): TAdvChartToolBarFontNamePicker;
begin
  FBlockUpdate := True;
  Result := TAdvChartToolBarFontNamePicker.Create(Self);
  InsertToolBarControl(Result, AIndex);
  FBlockUpdate := False;
  UpdateControls;
end;

function TAdvChartCustomToolBar.AddFontSizePicker(
  AIndex: Integer): TAdvChartToolBarFontSizePicker;
begin
  FBlockUpdate := True;
  Result := TAdvChartToolBarFontSizePicker.Create(Self);
  InsertToolBarControl(Result, AIndex);
  FBlockUpdate := False;
  UpdateControls;
end;

function TAdvChartCustomToolBar.AddItemPicker(
  AIndex: Integer): TAdvChartToolBarItemPicker;
begin
  FBlockUpdate := True;
  Result := TAdvChartToolBarItemPicker.Create(Self);
  InsertToolBarControl(Result, AIndex);
  FBlockUpdate := False;
  UpdateControls;
end;

function TAdvChartCustomToolBar.AddSeparator(AIndex: Integer = -1): TAdvChartToolBarSeparator;
begin
  FBlockUpdate := True;
  Result := TAdvChartToolBarSeparator.Create(Self);
  InsertToolBarControl(Result, AIndex);
  FBlockUpdate := False;
  UpdateControls;
end;

procedure TAdvChartCustomToolBar.ApplyStyle;
var
  c: TAdvChartGraphicsColor;
begin
  inherited;
  c := gcNull;
  if TAdvChartStyles.GetStyleHeaderFillColor(c) then
  begin
    Appearance.Fill.Kind := gfkSolid;
    Appearance.Fill.Color := c;
  end;

  if TAdvChartStyles.GetStyleHeaderFillColorTo(c) then
  begin
    Appearance.Fill.Kind := gfkGradient;
    Appearance.Fill.ColorTo := c;
  end;
end;

procedure TAdvChartCustomToolBar.Assign(Source: TPersistent);
var
  c, cc: TControl;
  I: Integer;
begin
  inherited;
  if Source is TAdvChartCustomToolBar then
  begin
    FAutoSize := (Source as TAdvChartCustomToolBar).AutoSize;
    FAutoAlign := (Source as TAdvChartCustomToolBar).AutoAlign;
    FAutoMoveToolBar := (Source as TAdvChartCustomToolBar).AutoMoveToolBar;
    FAppearance.Assign((Source as TAdvChartCustomToolBar).Appearance);
    for I := 0 to (Source as TAdvChartCustomToolBar).ControlCount - 1 do
    begin
      cc := (Source as TAdvChartCustomToolBar).Controls[I];
      if ((cc is TAdvChartDefaultToolBarButton) and (cc as TAdvChartDefaultToolBarButton).CanCopy) or not ((cc is TAdvChartDefaultToolBarButton) and (cc is TControl)) then
      begin
        if cc is TAdvChartDefaultToolBarButton then
          (cc as TAdvChartDefaultToolBarButton).ApplyName := False;

        c := (TAdvChartUtils.Clone(cc) as TControl);
        if cc is TAdvChartDefaultToolBarButton then
          (cc as TAdvChartDefaultToolBarButton).ApplyName := True;

        AddCustomControl(c);
      end;
    end;
    Invalidate;
  end
  else
    inherited;
end;

constructor TAdvChartCustomToolBar.Create(AOwner: TComponent);
var
  c: TAdvChartGraphicsColor;
begin
  inherited;
  FHiddenControls := TAdvChartToolBarControlObjectList.Create;
  {$IFNDEF LCLLIB}
  FCompareControls := TDelegatedComparer<TControl>.Create(
    function(const Item1, Item2: TControl): Integer
    begin
      Result := CompareValue(Item1.Tag, Item2.Tag);
    end);
  FCompareHiddenControls := TDelegatedComparer<TAdvChartToolBarControl>.Create(
    function(const Item1, Item2: TAdvChartToolBarControl): Integer
    begin
      Result := CompareValue(Item1.FControlIndex, Item2.FControlIndex);
    end);
  {$ENDIF}
  FState := esNormal;
  FAppearance := TAdvChartToolBarAppearance.Create(Self);
  FOptionsMenu := TAdvChartToolBarOptionsMenu.Create(Self);
  FAutoSize := True;
  FAutoAlign := True;
  FAutoMoveToolBar := True;
  FOptionsMenuButton := TAdvChartToolBarDropDownButton.Create(Self);
  FOptionsMenuButton.Appearance.NormalFill.Kind := gfkSolid;
  c := gcLightgray;
  FOptionsMenuButton.Appearance.NormalFill.Color := c;
  FOptionsMenuButton.Appearance.ShowInnerStroke := False;
  FOptionsMenuButton.Appearance.Rounding := 0;

  FOptionsMenuButton.Appearance.HoverFill.Assign(FOptionsMenuButton.Appearance.NormalFill);
  FOptionsMenuButton.Appearance.DisabledFill.Assign(FOptionsMenuButton.Appearance.NormalFill);
  FOptionsMenuButton.Appearance.DownFill.Assign(FOptionsMenuButton.Appearance.NormalFill);

  FOptionsMenuButton.Appearance.HoverFill.Color := gcLightblue;
  FOptionsMenuButton.Appearance.DownFill.Color := gcLightsteelblue;
  FOptionsMenuButton.Appearance.DisabledFill.Color := gcGray;

  {$IFDEF VCLLIB}
  FOptionsMenuButton.AlignWithMargins := True;
  {$ENDIF}
  
  {$IFNDEF LCLLIB}
  FOptionsMenuButton.Margins.Top := 3;
  FOptionsMenuButton.Margins.Bottom := 3;
  FOptionsMenuButton.Margins.Right := 3;
  {$ENDIF}
  {$IFDEF LCLLIB}
  FOptionsMenuButton.BorderSpacing.Top := 3;
  FOptionsMenuButton.BorderSpacing.Bottom := 3;
  FOptionsMenuButton.BorderSpacing.Right := 3;
  {$ENDIF}

  FOptionsMenuButton.CanCopy := False;
  FAutoOptionsMenu := TPopupMenu.Create(Self);
  FOptionsMenuButton.OnClick := OptionsButtonClick;
  FOptionsMenuButton.Width := 17;
  FOptionsMenuButton.Text := '';
  FOptionsMenuButton.Stored := False;

  FOptionsMenuButton.Bitmaps.AddBitmapFromResource('ADVCHARTTOOLBAROPTIONSMENU', 1.0);
  FOptionsMenuButton.Bitmaps.AddBitmapFromResource('ADVCHARTTOOLBAROPTIONSMENULARGE', 1.5);
  FOptionsMenuButton.DisabledBitmaps.AddBitmapFromResource('ADVCHARTTOOLBAROPTIONSMENU', 1.0);
  FOptionsMenuButton.DisabledBitmaps.AddBitmapFromResource('ADVCHARTTOOLBAROPTIONSMENULARGE', 1.5);
end;

destructor TAdvChartCustomToolBar.Destroy;
begin
  FOptionsMenu.Free;
  FAppearance.Free;
  FHiddenControls.Free;
  inherited;
end;

procedure TAdvChartCustomToolBar.DoCanShowOptionsMenuItem(AControl: TControl;
  var ACanShowItem: Boolean);
begin
  if Assigned(OnOptionsMenuItemCanShow) then
    OnOptionsMenuItemCanShow(Self, AControl, ACanShowItem);
end;

procedure TAdvChartCustomToolBar.DoCustomizeOptionsMenu;
begin
  if Assigned(OnOptionsMenuCustomize) then
    OnOptionsMenuCustomize(Self, FAutoOptionsMenu);
end;

procedure TAdvChartCustomToolBar.DoCustomizeOptionsMenuItem(AControl: TControl; AMenuItem: TMenuItem);
begin
  if Assigned(OnOptionsMenuItemCustomize) then
    OnOptionsMenuItemCustomize(Self, AControl, AMenuItem);
end;

procedure TAdvChartCustomToolBar.DoDragGripMoving(ADeltaX, ADeltaY: Double);
begin
  if Assigned(OnDragGripMoving) then
    OnDragGripMoving(Self, ADeltaX, ADeltaY);
end;

procedure TAdvChartCustomToolBar.DoIsLastElement(AControl: TControl; var ALastElement: Boolean);
begin
  if Assigned(OnIsLastElement) then
    OnIsLastElement(Self, AControl, ALastElement);
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomToolBar.DoMatrixChanged(Sender: TObject);
begin
  inherited;
  UpdateDockPanel;
end;
{$ENDIF}

procedure TAdvChartCustomToolBar.HandleMouseLeave;
begin
  inherited;
  Cursor := crDefault;
  FInsideDrag := False;
end;

{$IFDEF CMNLIB}
procedure TAdvChartCustomToolBar.AlignControls(AControl: TControl; var Rect: TRect);
begin
  inherited;
  UpdateControls;
end;
{$ENDIF}

{$IFDEF FMXLIB}
procedure TAdvChartCustomToolBar.DoAddObject(const AObject: TFmxObject);
begin
  inherited;
  UpdateControls;
end;

procedure TAdvChartCustomToolBar.DoInsertObject(Index: Integer;
  const AObject: TFmxObject);
begin
  inherited;
  UpdateControls;
end;

procedure TAdvChartCustomToolBar.DoRealign;
begin
  inherited;
  UpdateControls;
end;

procedure TAdvChartCustomToolBar.DoRemoveObject(const AObject: TFmxObject);
begin
  inherited;
  UpdateControls;
end;
{$ENDIF}

procedure TAdvChartCustomToolBar.DrawDragGrip(AGraphics: TAdvChartGraphics);
var
  cnt: Integer;

  procedure DrawDots(ARect: TRectF);
  var
    i: integer;
    rdg: TRectF;
    sz: Integer;
  begin
    if State = esLarge then
      sz := 3
    else
      sz := 2;

    ARect.Left := ARect.Left;
    ARect.Top := ARect.Top;
    cnt := Round(ARect.Bottom) div (Round(sz) * 2);
    for i := 1 to cnt do
    begin
      rdg := RectF(ARect.Left + (ARect.Width - sz) / 2, ARect.Top + 1, ARect.Left + sz + (ARect.Width - sz) / 2, ARect.Top + 1 + sz);
      rdg := RectF(int(rdg.Left), int(rdg.Top), int(rdg.Right), int(rdg.Bottom));
      AGraphics.DrawRectangle(rdg);
      ARect.Top := ARect.Top + sz * 2;
    end;
  end;
var
  r: TRectF;
begin
  AGraphics.Fill.Color := Appearance.DragGripColor;
  AGraphics.Fill.Kind := gfkSolid;
  r := GetDragGripRect;
  DrawDots(r);
end;

function TAdvChartCustomToolBar.DropDownActive: Boolean;
var
  I: Integer;
  c: TControl;
begin
  Result := False;
  for I := 0 to ControlCount - 1 do
  begin
    c := Controls[I];
    if c is TAdvChartDefaultToolBarButton then
    begin
      Result := (c as TAdvChartDefaultToolBarButton).FPopup.IsOpen;
      if Result then
      begin
        Break;
      end;
    end;
  end;
end;

function TAdvChartCustomToolBar.GetDragGripRect(AInteraction: Boolean = False): TRectF;
var
  r: TRectF;
  f: Single;
begin
  r := LocalRect;
  f := 1;
  if State = esLarge then
    f := 1.75;

  if AInteraction then
    Result := RectF(r.Left, r.Top, r.Left + (8 * f), r.Bottom)
  else
    Result := RectF(r.Left + 3, r.Top + 3, r.Left + (6 * f), r.Bottom - 3);
end;

function TAdvChartCustomToolBar.GetHiddenControl(
  AControl: TControl): TAdvChartToolBarControl;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to FHiddenControls.Count - 1 do
  begin
    if FHiddenControls[I].FControl = AControl then
    begin
      Result := FHiddenControls[I];
      Break;
    end;
  end;              
end;

function TAdvChartCustomToolBar.GetHiddenControlCount(
  AControl: TControl): Integer;
var
  I: Integer;
  lst: TAdvChartToolBarControlList;
begin
  lst := TAdvChartToolBarControlList.Create;
  for I := 0 to FHiddenControls.Count - 1 do
    lst.Add(FHiddenControls[I]);

  {$IFNDEF LCLLIB}
  lst.Sort(FCompareHiddenControls);
  {$ENDIF}
  Result := 0;
  for I := 0 to lst.Count - 1 do
  begin
    if lst[I].FControl = AControl then
      Break
    else
      Inc(Result);
  end;
  lst.Free;
end;

function TAdvChartCustomToolBar.GetOptionsMenuButtonControl: TAdvChartToolBarDropDownButton;
begin
  Result := FOptionsMenuButton;
end;

function TAdvChartCustomToolBar.GetVersion: String;
begin
  Result := GetVersionNumber(MAJ_VER, MIN_VER, REL_VER, BLD_VER);
end;

procedure TAdvChartCustomToolBar.UpdateToolBar(Sender: TObject);
begin
  UpdateControls;
end;

procedure TAdvChartCustomToolBar.UpdateToolBarControl(Sender: TObject);
var
  tb: TAdvChartToolBarControl;
  bmp: TAdvChartBitmap;
  c: TControl;
  tc: TControl;
  tci: Integer;
begin
  if not Assigned(Sender) then
    Exit;

  FBlockUpdate := True;

  c := Sender as TControl;

  tb := GetHiddenControl(c);
  if Assigned(tb) then
  begin
    tc := tb.FControl;
    tci := Max(0, Min(ControlCount, tb.FControlIndex - GetHiddenControlCount(tc)));
    FHiddenControls.Remove(tb);
    InsertToolBarControl(tc, tci);
    tc.Visible := True;
  end
  else
  begin
    tb := TAdvChartToolBarControl.Create;
    tb.FControlIndex := c.Tag;
    tb.FControl := c;
    FBlockUpdate := True;
    bmp := c.MakeScreenshot;
    FBlockUpdate := False;
    tb.FBitmap.Assign(bmp);
    bmp.Free;
    FHiddenControls.Add(tb);
    c.Parent := nil;
    c.Visible := False;
  end;

  FBlockUpdate := False;
  UpdateControls;
end;

procedure TAdvChartCustomToolBar.InitializeOptionsMenu;
var
  mnu: TAdvChartToolBarOptionMenuItem;
  bmp: TAdvChartBitmap;
  I: Integer;
  c: TControl;
  lst: TAdvControlList;
  tb: TAdvChartToolBarControl;
  sh: Boolean;
  bmpw, bw, bh: Single;
  {$IFDEF FMXLIB}
  o: TFmxObject;
  {$ENDIF}
  maxh: Single;
begin
  lst := nil;
  try
    lst := TAdvControlList.Create;
    for I := 0 to ControlCount - 1 do
      lst.Add(Controls[I]);

    for I := 0 to FHiddenControls.Count - 1 do
      lst.Add(FHiddenControls[I].FControl);

    {$IFNDEF LCLLIB}
    lst.Sort(FCompareControls);
    {$ENDIF}

    {$IFDEF FMXLIB}
    FAutoOptionsMenu.Clear;
    {$ENDIF}
    {$IFDEF CMNLIB}
    FAutoOptionsMenu.Items.Clear;
    {$ENDIF}

    FTotalOptionsMenuWidth := 0;

    for I := 0 to lst.Count - 1 do
    begin
      c := lst[I];

      {$IFDEF FMXLIB}
      if Supports(c, IDesignerControl) then
        Continue;
      {$ENDIF}

      if not (c = FOptionsMenuButton) and not (c is TAdvChartCustomToolBarSeparator) then
      begin
        sh := True;
        DoCanShowOptionsMenuItem(c, sh);
        if sh then
        begin
          mnu := TAdvChartToolBarOptionMenuItem.Create(FAutoOptionsMenu);
          mnu.OnClick := OptionMenuItemClick;
          {$IFDEF FMXLIB}
          mnu.OnApplyStyleLookup := OptionMenuItemApplyStyleLookup;
          mnu.Calculate := True;
          mnu.ApplyStyleLookup;
          {$ENDIF}

          bmpw := 0;
          bw := 0;
          bh := 0;
          {$IFDEF FMXLIB}
          o := mnu.FindStyleResource('checkmark');
          if Assigned(o) and (o is TControl) then
            bmpw := (o as TControl).Width;
          {$ENDIF}

          maxh := 20;
          if OptionsMenu.ShowItemBitmap then
          begin
            tb := GetHiddenControl(c);
            if Assigned(tb) then
            begin
              bmp := tb.FBitmap;
              mnu.Bitmap.Assign(bmp);
              bw := bmp.Width;
              bh := bmp.Height;
            end
            else
            begin
              FBlockUpdate := True;
              bmp := c.MakeScreenshot;
              FBlockUpdate := False;
              mnu.Bitmap.Assign(bmp);
              bw := bmp.Width;
              bh := bmp.Height;
              bmp.Free;
            end;
          end;

          TAdvChartGraphics.GetAspectSize(bw, bh, bw, bh, bw, maxh, True, False, False);
          bmpw := bmpw + int(bw);

          if OptionsMenu.ShowItemText then
          begin
            if c is TAdvChartCustomToolBarButton then
              mnu.Caption := (c as TAdvChartCustomToolBarButton).AutoOptionsMenuText;

            if mnu.Caption = '' then
              mnu.Caption := c.Name;
          end;

          mnu.Control := c;
          mnu.Checked := Assigned(c.Parent);

          DoCustomizeOptionsMenuItem(c, mnu);

          {$IFDEF FMXLIB}
          FAutoOptionsMenu.AddObject(mnu);
          {$ENDIF}
          {$IFDEF CMNLIB}
          FAutoOptionsMenu.Items.Add(mnu);
          {$ENDIF}
          FTotalOptionsMenuWidth := Max(FTotalOptionsMenuWidth, bmpw);
        end;
      end;
    end;

    {$IFDEF FMXLIB}
    for I := 0 to FAutoOptionsMenu.ItemsCount - 1 do
    {$ENDIF}
    {$IFDEF CMNLIB}
    for I := 0 to FAutoOptionsMenu.Items.Count - 1 do
    {$ENDIF}
    begin
      if FAutoOptionsMenu.Items[I] is TAdvChartToolBarOptionMenuItem then
      begin
        mnu := (FAutoOptionsMenu.Items[I] as TAdvChartToolBarOptionMenuItem);
        {$IFDEF FMXLIB}
        mnu.NeedStyleLookup;
        mnu.Calculate := False;
        {$ENDIF}
        if OptionsMenu.AutoItemBitmapWidth then
          mnu.GlyphWidth := FTotalOptionsMenuWidth
        else
          mnu.GlyphWidth := OptionsMenu.ItemBitmapWidth;
      end;
    end;

  finally
    if Assigned(lst) then
      lst.Free;
  end;
end;

procedure TAdvChartCustomToolBar.InsertToolBarControl(AControl: TControl;
  AIndex: Integer);
begin
  {$IFDEF FMXLIB}
  if (AIndex >= 0) and (AIndex <= ControlCount - 1) then
    InsertObject(AIndex, AControl)
  else
    AddObject(AControl);
  {$ENDIF}
  {$IFDEF CMNLIB}
  AControl.Parent := Self;
  if AIndex > -1 then
    SetChildOrder(AControl, AIndex);
  {$ENDIF}
end;

procedure TAdvChartCustomToolBar.HandleMouseDown(Button: TAdvMouseButton;
  Shift: TShiftState; X, Y: Single);
begin
  inherited;
  if Appearance.DragGrip and not FDragGripMoving then
  begin
    FDragGripDown := PtInRectEx(GetDragGripRect(True), PointF(X, Y));
    FDragGripDownPt := PointF(X, Y);
  end;
end;

procedure TAdvChartCustomToolBar.HandleMouseMove(Shift: TShiftState; X, Y: Single);
var
  r: TRectF;
  absx, absy: Single;
begin
  inherited;
  if Appearance.DragGrip then
  begin
    if FDragGripDown then
    begin
      if not FDragGripMoving then
      begin
        CaptureEx;
        FDragGripMoving := True;
      end;

      if FDragGripMoving then
      begin
        absx := (FDragGripDownPt.X - X);
        absy := (FDragGripDownPt.Y - Y);
        if AutoMoveToolBar then
        begin
          {$IFDEF FMXLIB}
          Position.Point := PointF(Position.Point.X - absx, Position.Point.Y - absy);
          {$ENDIF}
          {$IFDEF CMNLIB}
          Left := Left - Round(absx);
          Top := Top - Round(absy);
          {$ENDIF}
        end;
        FDragGripDownPt := PointF(X + absx, Y + absy);
        DoDragGripMoving(absx, absy);
      end;
    end
    else
    begin
      r := GetDragGripRect(True);
      if PtInRectEx(r, PointF(X, Y)) then
      begin
        if not FInsideDrag then
        begin
          FInsideDrag := True;
          Cursor := crSize;
        end;
      end
      else if FInsideDrag then
      begin
        FInsideDrag := False;
        Cursor := crDefault;
      end;
    end;
  end;
end;

procedure TAdvChartCustomToolBar.HandleMouseUp(Button: TAdvMouseButton; Shift: TShiftState;
  X, Y: Single);
begin
  inherited;
  if FDragGripDown then
    ReleaseCaptureEx;

  FDragGripDown := False;
  FDragGripMoving := False;
end;

procedure TAdvChartCustomToolBar.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and (AComponent = FCustomOptionsMenu) then
    FCustomOptionsMenu := nil;
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomToolBar.OptionMenuItemApplyStyleLookup(Sender: TObject);
var
  c: TControl;
begin
  c := nil;
  if (Sender is TAdvChartToolBarOptionMenuItem) then
    c := (Sender as TAdvChartToolBarOptionMenuItem).FControl;

  if Assigned(OnOptionsMenuItemApplyStyle) and (Sender is TMenuItem) then
    OnOptionsMenuItemApplyStyle(Self, c, Sender as TMenuItem);
end;
{$ENDIF}

procedure TAdvChartCustomToolBar.OptionMenuItemClick(Sender: TObject);
var
  a: Boolean;
  c: TControl;
begin
  a := True;
  c := nil;
  if (Sender is TAdvChartToolBarOptionMenuItem) then
    c := (Sender as TAdvChartToolBarOptionMenuItem).FControl;

  if Assigned(OnOptionsMenuItemClick) and (Sender is TMenuItem) then
    OnOptionsMenuItemClick(Self, c, Sender as TMenuItem, a);

  if a then
    UpdateToolBarControl(c);
end;

procedure TAdvChartCustomToolBar.OptionsButtonClick(Sender: TObject);
var
  pt: TPointF;
begin
  if Assigned(OnOptionsMenuButtonClick) then
    OnOptionsMenuButtonClick(Self)
  else
  begin
    {$IFDEF FMXLIB}
    pt := FOptionsMenuButton.Position.Point;
    {$ENDIF}
    {$IFDEF CMNLIB}
    pt := PointF(FOptionsMenuButton.Left, FOptionsMenuButton.Top);
    {$ENDIF}
    pt := LocalToScreenEx(PointF(pt.X, pt.Y + FOptionsMenuButton.Height));
    ShowOptionsMenu(pt.X, pt.Y);
  end;
end;

procedure TAdvChartCustomToolBar.ResetToDefaultStyle;
begin
  inherited;
  Appearance.DragGripColor := gcLightgray;
  Appearance.Fill.Color := gcWhite;
  Appearance.Stroke.Color := gcGray;
  Appearance.Fill.Kind := gfkGradient;
  Appearance.Stroke.Kind := gskSolid;
  Appearance.Fill.Color := gcWhite;
  Appearance.Fill.ColorTo := MakeGraphicsColor(230, 230, 230);
end;

procedure TAdvChartCustomToolBar.Draw(AGraphics: TAdvChartGraphics; ARect: TRectF);
var
  r: TRectF;
begin
  inherited;
  AGraphics.Fill.Assign(Appearance.Fill);
  AGraphics.Stroke.Assign(Appearance.Stroke);

  if Appearance.FlatStyle then
    AGraphics.Fill.Kind := gfkSolid;

  r := LocalRect;

  AGraphics.DrawRectangle(r);

  if Appearance.DragGrip then
    DrawDragGrip(AGraphics);
end;

procedure TAdvChartCustomToolBar.UpdateControlAfterResize;
begin
  inherited;
  UpdateDockPanel;
end;

procedure TAdvChartCustomToolBar.SetAdaptToStyle(const Value: Boolean);
begin
  inherited;
  UpdateControls;
end;

procedure TAdvChartCustomToolBar.SetAppearance(
  const Value: TAdvChartToolBarAppearance);
begin
  FAppearance.Assign(Value);
end;

procedure TAdvChartCustomToolBar.SetOptionsMenu(
  const Value: TAdvChartToolBarOptionsMenu);
begin
  FOptionsMenu.Assign(Value);
end;

procedure TAdvChartCustomToolBar.SetState(const Value: TAdvChartToolBarElementState);
var
  I: Integer;
  c: TControl;
begin
  if FState <> Value then
  begin
    FState := Value;
    for I := 0 to ControlCount - 1 do
    begin
      c := Controls[I];
      if c is TAdvChartCustomToolBarElement then
        (c as TAdvChartCustomToolBarElement).State := FState;
    end;
  end;
end;

procedure TAdvChartCustomToolBar.SetAutoAlign(const Value: Boolean);
begin
  if FAutoAlign <> Value then
  begin
    FAutoAlign := Value;
    UpdateControls;
  end;
end;

procedure TAdvChartCustomToolBar.SetAS(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    UpdateControls;
  end;
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomToolBar.SetVisible(const Value: Boolean);
{$ENDIF}
{$IFDEF CMNLIB}
procedure TAdvChartCustomToolBar.VisibleChanging;
{$ENDIF}
begin
  inherited;
  UpdateDockPanel;
end;

procedure TAdvChartCustomToolBar.ShowOptionsMenu(X, Y: Single);
begin
  {$IFDEF FMXLIB}
  if not Assigned(CustomOptionsMenu) then
  begin
    InitializeOptionsMenu;
    DoCustomizeOptionsMenu;
    if FAutoOptionsMenu.ItemsCount > 0 then
      FAutoOptionsMenu.Popup(X, Y);
  end
  else
    CustomOptionsMenu.Popup(X, Y);
 {$ENDIF}
 {$IFDEF CMNLIB}
  if not Assigned(CustomOptionsMenu) then
  begin
    InitializeOptionsMenu;
    DoCustomizeOptionsMenu;
    if FAutoOptionsMenu.Items.Count > 0 then
      FAutoOptionsMenu.Popup(Round(X), Round(Y));
  end
  else
    CustomOptionsMenu.Popup(Round(X), Round(Y));
  {$ENDIF}
end;

procedure TAdvChartCustomToolBar.UpdateControls;
var
  I: Integer;
  c: TControl;
  idx: Integer;
  fu: Boolean;
  hc: TAdvChartToolBarControl;
  {$IFDEF FMXLIB}
  x, w, y, h, hs, hsm, vs, xs, ys: Single;
  mgr: TBounds;
  {$ENDIF}
  {$IFDEF CMNLIB}
  x, w, y, h, hs, hsm, vs, xs, ys: Integer;
  {$ENDIF}
  {$IFDEF LCLLIB}
  mgr: TControlBorderSpacing;
  {$ENDIF}
  {$IFDEF VCLLIB}
  mgr: TMargins;
  {$ENDIF}
  l: Boolean;
  ia: IAdvAdaptToStyle;
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  {$IFDEF FMXLIB}
  hs := Appearance.HorizontalSpacing;
  vs := Appearance.VerticalSpacing;
  {$ENDIF}
  {$IFDEF CMNLIB}
  hs := Round(Appearance.HorizontalSpacing);
  vs := Round(Appearance.VerticalSpacing);
  {$ENDIF}

  x := hs;
  if Appearance.DragGrip then
  begin
    {$IFDEF FMXLIB}
    x := x + GetDragGripRect.Right;
    {$ENDIF}
    {$IFDEF CMNLIB}
    x := x + Round(GetDragGripRect.Right);
    {$ENDIF}
    if hs = 0 then
      x := x + 3;
  end;

  y := vs;

  xs := x;
  ys := y;

  w := 0;
  h := 0;
  hsm := 30;

  idx := 0;

  fu := False;
  for I := 0 to ControlCount - 1 do
  begin
    c := Controls[I];
    {$IFDEF FMXLIB}
    if Supports(c, IDesignerControl) then
      Continue;
    {$ENDIF}

    hc := GetHiddenControl(c);
    fu := not Assigned(hc);
    if fu then
      Break;
  end;

  l := False;
  for I := 0 to ControlCount - 1 do
  begin
    c := Controls[I];
    {$IFDEF FMXLIB}
    if Supports(c, IDesignerControl) then
      Continue;
    {$ENDIF}

    if Supports(c, IAdvAdaptToStyle, ia) then
      ia.AdaptToStyle := AdaptToStyle;

    if l then
    begin
      x := xs;
      y := ys + h - vs;
    end;

    l := False;
    if c is TAdvChartCustomToolBarElement then
    begin
      l := (c as TAdvChartCustomToolBarElement).LastElement;
      (c as TAdvChartCustomToolBarElement).OnUpdateToolBar := UpdateToolBar;
      (c as TAdvChartCustomToolBarElement).OnUpdateToolBarControl := UpdateToolBarControl;
    end;

    DoIsLastElement(c, l);

    if not (c = FOptionsMenuButton) then
    begin
      if fu then
        c.Tag := idx;

      if c.Visible then
      begin
        {$IFDEF FMXLIB}
        if AutoAlign then
        begin
          c.Position.X := x + c.Margins.Left;
          c.Position.Y := y + c.Margins.Top;
        end;
        h := Max(h, c.Position.y + c.Height + vs + c.Margins.Bottom);
        x := Max(x, c.Position.x + c.Width + hs + c.Margins.Right);
        {$ENDIF}
        {$IFDEF VCLLIB}
        if c.AlignWithMargins then
        begin
          if AutoAlign then
          begin
            c.Left := x + c.Margins.Left;
            c.Top := y + c.Margins.Top;
          end;
          h := Max(h, c.Top + c.Height + vs + c.Margins.Bottom);
          x := Max(x, c.Left + c.Width + hs + c.Margins.Right);
        end
        else
        begin
          if AutoAlign then
          begin
            c.Left := x;
            c.Top := y;
          end;
          h := Max(h, c.Top + c.Height + vs);
          x := Max(x, c.Left + c.Width + hs);
        end;
        {$ENDIF}
        {$IFDEF LCLLIB}
        if AutoAlign then
        begin
          c.Left := x + c.BorderSpacing.Left;
          c.Top := y + c.BorderSpacing.Top;
        end;
        h := Max(h, c.Top + c.Height + vs + c.BorderSpacing.Bottom);
        x := Max(x, c.Left + c.Width + hs + c.BorderSpacing.Right);
        {$ENDIF}
        w := Max(w, x);
      end;
      inc(idx);
    end;
  end;

  if h = 0 then
    h := hsm;

  FOptionsMenuButton.Visible := OptionsMenu.ShowButton;
  if OptionsMenu.ShowButton then
    FOptionsMenuButton.Parent := Self
  else
    FOptionsMenuButton.Parent := nil;

  {$IFDEF FMXLIB}
  if FOptionsMenuButton.Visible then
  begin
    FOptionsMenuButton.Index := ControlCount;
    FOptionsMenuButton.Tag := ControlCount - 1;
    FOptionsMenuButton.Position.Y := FOptionsMenuButton.Margins.Top;
    mgr := FOptionsMenuButton.Margins;

    if AutoSize then
    begin
      FOptionsMenuButton.Position.X := w + mgr.Left;
      FOptionsMenuButton.Height := h - mgr.Bottom - mgr.Top;
    end
    else
    begin
      FOptionsMenuButton.Position.X := Width - FOptionsMenuButton.Width - mgr.Right;
      FOptionsMenuButton.Height := Height - mgr.Bottom - mgr.Top;
    end;
    w := w + FOptionsMenuButton.Width + mgr.Right + mgr.Left;
  end;

  if AutoSize then
  begin
    if Align = TAlignLayout.None then
      SetBounds(Position.X, Position.Y, w, h)
    else
      SetBounds(Position.X, Position.Y, Width, h)
  end;
  {$ENDIF}
  {$IFDEF CMNLIB}
  if FOptionsMenuButton.Visible then
  begin
    FOptionsMenuButton.Tag := ControlCount - 1;
    {$IFDEF LCLLIB}
    FOptionsMenuButton.Top := FOptionsMenuButton.BorderSpacing.Top;
    mgr := FOptionsMenuButton.BorderSpacing;
    {$ENDIF}
    {$IFDEF VCLLIB}
    FOptionsMenuButton.Top := FOptionsMenuButton.Margins.Top;
    mgr := FOptionsMenuButton.Margins;
    if not FOptionsMenuButton.AlignWithMargins then
    begin
      mgr.Left := 0;
      mgr.Top := 0;
      mgr.Right := 0;
      mgr.Bottom := 0;
    end;      
    {$ENDIF}

    if AutoSize then
    begin
      FOptionsMenuButton.Left := w + mgr.Left;
      FOptionsMenuButton.Height := h - mgr.Bottom - mgr.Top;
    end
    else
    begin
      FOptionsMenuButton.Left := Width - FOptionsMenuButton.Width - mgr.Right;
      FOptionsMenuButton.Height := Height - mgr.Bottom - mgr.Top;
    end;
    w := w + FOptionsMenuButton.Width + mgr.Right + mgr.Left;
  end;

  if AutoSize then
  begin
    if Align = alNone then
      SetBounds(Left, Top, w, h)
    else
      SetBounds(Left, Top, Width, h)
  end;
  {$ENDIF}

  if Assigned(OnUpdateControls) then
    OnUpdateControls(Self);

  FBlockUpdate := False;
end;

procedure TAdvChartCustomToolBar.UpdateDockPanel;
begin
  if Assigned(OnUpdateDockPanel) then
    OnUpdateDockPanel(Self);
end;

{ TAdvChartDefaultToolBarButton }

procedure TAdvChartDefaultToolBarButton.AppearanceChanged;
begin
  Invalidate;
end;

procedure TAdvChartDefaultToolBarButton.ApplyStyle;
var
  c: TAdvChartGraphicsColor;
begin
  inherited;
  c := gcNull;
  if TAdvChartStyles.GetStyleBackgroundFillColor(c) then
  begin
    Appearance.NormalFill.Color := c;
    Appearance.NormalFill.Kind := gfkSolid;
    Appearance.DisabledFill.Color := Blend(c, gcDarkgray, 20);
    Appearance.DisabledFill.Kind := gfkSolid;
    Appearance.InnerStroke.Color := Blend(Appearance.NormalFill.Color, Appearance.NormalStroke.Color, 75);
    Appearance.InnerStroke.Kind := gskSolid;
  end;

  c := gcNull;
  if TAdvChartStyles.GetStyleTextFontColor(c) then
    Font.Color := c;

  c := gcNull;
  if TAdvChartStyles.GetStyleBackgroundStrokeColor(c) then
  begin
    Appearance.NormalStroke.Color := c;
    Appearance.DownStroke.Color := c;
    Appearance.DisabledStroke.Color := c;
    Appearance.NormalStroke.Color := c;
    Appearance.DownStroke.Color := c;
    Appearance.DisabledStroke.Color := c;
    Appearance.HoverStroke.Color := c;
  end;

  c := gcNull;
  if TAdvChartStyles.GetStyleSelectionFillColor(c) then
  begin
    Appearance.HoverFill.Color := c;
    Appearance.HoverFill.Kind := gfkSolid;
    Appearance.DownFill.Color := Blend(c, Fill.Color, 20);
    Appearance.DownFill.Kind := gfkSolid;
  end;
end;

procedure TAdvChartDefaultToolBarButton.Assign(Source: TPersistent);
begin
  inherited;
  if Source is TAdvChartDefaultToolBarButton then
  begin
    FAppearance.Assign((Source as TAdvChartDefaultToolBarButton).Appearance);
    FBitmapContainer := (Source as TAdvChartDefaultToolBarButton).BitmapContainer;
    FBitmaps.Assign((Source as TAdvChartDefaultToolBarButton).Bitmaps);
    FDisabledBitmaps.Assign((Source as TAdvChartDefaultToolBarButton).DisabledBitmaps);
    FBitmapVisible := (Source as TAdvChartDefaultToolBarButton).BitmapVisible;
    FText := (Source as TAdvChartDefaultToolBarButton).Text;
    FTextVisible := (Source as TAdvChartDefaultToolBarButton).TextVisible;
    FDropDownHeight := (Source as TAdvChartDefaultToolBarButton).DropDownHeight;
    FDropDownWidth := (Source as TAdvChartDefaultToolBarButton).DropDownWidth;
    FWordWrapping := (Source as TAdvChartDefaultToolBarButton).WordWrapping;
    FHorizontalTextAlign := (Source as TAdvChartDefaultToolBarButton).HorizontalTextAlign;
    FVerticalTextAlign := (Source as TAdvChartDefaultToolBarButton).VerticalTextAlign;
    FTrimming := (Source as TAdvChartDefaultToolBarButton).Trimming;
    FFont.Assign((Source as TAdvChartDefaultToolBarButton).Font);
    FStretchText := (Source as TAdvChartDefaultToolBarButton).StretchText;
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.BitmapsChanged(Sender: TObject);
var
  bmp: TAdvChartBitmap;
begin
  bmp := TAdvChartGraphics.GetScaledBitmap(Bitmaps, 0, BitmapContainer);
  BitmapVisible := Assigned(bmp) and not IsBitmapEmpty(bmp);
end;

function TAdvChartDefaultToolBarButton.CanChangeText: Boolean;
begin
  Result := True;
end;

function TAdvChartDefaultToolBarButton.CanDropDown: Boolean;
begin
  Result := False;
end;

procedure TAdvChartDefaultToolBarButton.CloseDropDown;
begin
  if FPopup.IsOpen then
    FPopup.IsOpen := False;
end;

constructor TAdvChartDefaultToolBarButton.Create(AOwner: TComponent);
begin
  inherited;
  FFont := TAdvChartGraphicsFont.Create;
  FFont.OnChanged := DoFontChanged;

  FDownState := False;
  FApplyName := True;
  FCloseOnSelection := True;
  FBitmapSize := 24;
  FStretchText := False;

  FDropDownWidth := 135;
  FDropDownHeight := 135;
  FPopup := TAdvChartPopup.Create(Self);
  FPopup.PlacementControl := Self;
  FPopup.DragWithParent := True;
  FPopup.DropDownWidth := FDropDownWidth;
  FPopup.DropDownHeight := FDropDownHeight;
  FPopup.OnPopup := DoPopup;
  FPopupPlacement := ppBottom;

  FBitmaps := TAdvScaledBitmaps.Create(Self);
  FBitmaps.OnChange := BitmapsChanged;
  FDisabledBitmaps := TAdvScaledBitmaps.Create(Self);
  FDisabledBitmaps.OnChange := BitmapsChanged;
  FAppearance := TAdvChartToolBarButtonAppearance.Create(Self);

  FTextVisible := True;
  FBitmapVisible := False;
  FWordWrapping := False;
  FHorizontalTextAlign := gtaCenter;
  FVerticalTextAlign := gtaCenter;
  FTrimming := gttCharacter;

  Width := 100;
  Height := 24;
end;

procedure TAdvChartDefaultToolBarButton.SetDisabledBitmaps(const Value: TAdvScaledBitmaps);
begin
  FDisabledBitmaps.Assign(Value);
end;

procedure TAdvChartDefaultToolBarButton.SetDownState(const Value: Boolean);
begin
  FDownState := Value;
  Invalidate;
end;

procedure TAdvChartDefaultToolBarButton.SetDropDownControl(const Value: TControl);
begin
  FDropDownControl := Value;
  if Assigned(FDropDownControl) then
  begin
    if not (csDesigning in ComponentState) then
    begin
      if Assigned(FPopup) then
      begin
        FPopup.ContentControl := FDropDownControl;
        FPopup.FocusedControl := FDropDownControl;
      end;
    end
    else if (csDesigning in ComponentState) then
    begin
      DropDownHeight := FDropDownControl.Height;
      DropDownWidth := FDropDownControl.Width;
    end;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetDropDownHeight(const Value: Single);
begin
  FDropDownHeight := Value;
  if Assigned(FPopup) then
    FPopup.DropDownHeight := FDropDownHeight;
end;

procedure TAdvChartDefaultToolBarButton.SetDropDownWidth(const Value: Single);
begin
  FDropDownWidth := Value;
  if Assigned(FPopup) then
    FPopup.DropDownWidth := FDropDownWidth;
end;

procedure TAdvChartDefaultToolBarButton.SetFont(const Value: TAdvChartGraphicsFont);
begin
  FFont.Assign(Value);
end;

procedure TAdvChartDefaultToolBarButton.SetHorizontalTextAlign(
  const Value: TAdvChartGraphicsTextAlign);
begin
  if FHorizontalTextAlign <> Value then
  begin
    FHorizontalTextAlign := Value;
    Invalidate;
  end;
end;

procedure TAdvChartCustomToolBarButton.SetAdaptToStyle(const Value: Boolean);
begin
  inherited;
  if Assigned(FDropDownButton) then
    FDropDownButton.AdaptToStyle := AdaptToStyle;
end;

procedure TAdvChartCustomToolBarButton.SetDropDownKind(
  const Value: TAdvChartToolBarButtonDropDownKind);
begin
  if FDropDownKind <> Value then
  begin
    FDropDownKind := Value;
    if Assigned(FDropDownButton) then
    begin
      case DropDownKind of
        ddkNormal:
        begin
          FDropDownButton.Visible := False;
          FDropDownButton.Parent := nil;
          {$IFDEF FMXLIB}
          FDropDownButton.HitTest := True;
          {$ENDIF}
          FDropDownButton.Appearance.Transparent := False;
        end;
        ddkDropDown:
        begin
          FDropDownButton.Visible := True;
          FDropDownButton.Parent := Self;
          {$IFDEF FMXLIB}
          FDropDownButton.HitTest := False;
          {$ENDIF}
          FDropDownButton.Appearance.Transparent := True;
        end;
        ddkDropDownButton:
        begin
          FDropDownButton.Visible := True;
          FDropDownButton.Parent := Self;
          {$IFDEF FMXLIB}
          FDropDownButton.HitTest := True;
          {$ENDIF}
          FDropDownButton.Appearance.Transparent := False;
        end;
      end;
    end;
    Invalidate;
  end;
end;

procedure TAdvChartCustomToolBarButton.SetDropDownPosition(
  const Value: TAdvChartToolBarButtonDropDownPosition);
begin
  if FDropDownPosition <> Value then
  begin
    FDropDownPosition := Value;
    case Value of
      ddpRight:
      begin
        {$IFDEF FMXLIB}
        FDropDownButton.Align := TAlignLayout.Right;
        {$ENDIF}
        {$IFDEF CMNLIB}
        FDropDownButton.Align := alRight;
        {$ENDIF}
        FDropDownButton.Width := 17;
        FDropDownButton.Appearance.Corners := [gcTopRight, gcBottomRight];
      end;
      ddpBottom:
      begin
        {$IFDEF FMXLIB}
        FDropDownButton.Align := TAlignLayout.Bottom;
        {$ENDIF}
        {$IFDEF CMNLIB}
        FDropDownButton.Align := alBottom;
        {$ENDIF}
        FDropDownButton.Height := 10;
        FDropDownButton.Appearance.Corners := [gcBottomLeft, gcBottomRight];
      end;
    end;
  end;
end;

procedure TAdvChartCustomToolBarButton.SetHidden(const Value: Boolean);
begin
  if FHidden <> Value then
  begin
    FHidden := Value;
    UpdateToolBarControl;
  end;
end;

procedure TAdvChartCustomToolBarButton.UpdateDropDownButton;
begin
  FDropDownButton.Appearance.Rounding := Appearance.Rounding;
end;

destructor TAdvChartDefaultToolBarButton.Destroy;
begin
  FFont.Free;
  FPopup.Free;
  FBitmaps.Free;
  FDisabledBitmaps.Free;
  FAppearance.Free;
  inherited;
end;

procedure TAdvChartDefaultToolBarButton.DoPopup(Sender: TObject);
begin
  InitializePopup;
end;

procedure TAdvChartDefaultToolBarButton.HandleMouseEnter;
begin
  inherited;
end;

procedure TAdvChartDefaultToolBarButton.HandleMouseLeave;
begin
  inherited;
  FDown := False;
  FHover := False;
  FPrevHover := False;
  Invalidate;
end;

procedure TAdvChartCustomToolBarButton.DoFontChanged(Sender: TObject);
begin
  Invalidate;
end;

procedure TAdvChartCustomToolBarButton.AppearanceChanged;
begin
  inherited;
  UpdateDropDownButton;
end;

procedure TAdvChartCustomToolBarButton.Assign(Source: TPersistent);
begin
  inherited;
  if Source is TAdvChartCustomToolBarButton then
  begin
    FDropDownKind := (Source as TAdvChartCustomToolBarButton).DropDownKind;
    FDropDownPosition := (Source as TAdvChartCustomToolBarButton).DropDownPosition;
    FAutoOptionsMenuText := (Source as TAdvChartCustomToolBarButton).AutoOptionsMenuText;
    FHidden := (Source as TAdvChartCustomToolBarButton).Hidden;
    Invalidate;
  end;
end;

function TAdvChartCustomToolBarButton.CanDropDown: Boolean;
begin
  Result := DropDownKind <> ddkNormal;
end;

constructor TAdvChartCustomToolBarButton.Create(AOwner: TComponent);
begin
  inherited;
  FHidden := False;
  FDropDownPosition := ddpRight;
  FDropDownButton := TAdvChartToolBarDropDownButton.Create(Self);
  FDropDownButton.TabStop := False;
  FDropDownButton.Text := '';
  FDropDownButton.OnClick := DropDownButtonClick;
  FDropDownButton.Visible := False;
  FDropDownButton.Width := 17;
  FDropDownButton.Appearance.Corners := [gcTopRight, gcBottomRight];
  {$IFDEF FMXLIB}
  FDropDownButton.Align := TAlignLayout.Right;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FDropDownButton.Align := alRight;
  {$ENDIF}
  FDropDownButton.Stored := False;

  FDropDownButton.Bitmaps.AddBitmapFromResource('ADVCHARTTOOLBAREXPAND', 1.0);
  FDropDownButton.Bitmaps.AddBitmapFromResource('ADVCHARTTOOLBAREXPANDLARGE', 1.5);
  FDropDownButton.DisabledBitmaps.AddBitmapFromResource('ADVCHARTTOOLBAREXPAND', 1.0);
  FDropDownButton.DisabledBitmaps.AddBitmapFromResource('ADVCHARTTOOLBAREXPANDLARGE', 1.5);
end;

destructor TAdvChartCustomToolBarButton.Destroy;
begin
  FDropDownButton.Free;
  inherited;
end;

procedure TAdvChartCustomToolBarButton.DropDownButtonClick(Sender: TObject);
begin
  DropDown;
end;

procedure TAdvChartDefaultToolBarButton.DrawBitmap(AGraphics: TAdvChartGraphics);
var
  r: TRectF;
  bmpa: TBitmap;
  g: TAdvChartGraphics;
begin
  if not BitmapVisible then
    Exit;

  r := GetBitmapRect;

  if (Self is TAdvChartToolBarDropDownButton) and AdaptToStyle then
  begin
    bmpa := TBitmap.Create;
    bmpa.SetSize(7, 7);
    {$IFDEF CMNLIB}
    bmpa.TransparentMode := tmFixed;
    bmpa.Transparent := True;
    bmpa.TransparentColor := gcWhite;
    {$ENDIF}
    g := TAdvChartGraphics.Create(bmpa.Canvas);
    try
      g.BeginScene;
      {$IFDEF CMNLIB}
      g.Fill.Color := gcWhite;
      g.Fill.Kind := gfkSolid;
      g.Stroke.Kind := gskSolid;
      g.Stroke.Color := gcWhite;
      g.DrawRectangle(0, 0, bmpa.Width, bmpa.Height);
      {$ENDIF}
      g.Stroke.Kind := gskSolid;
      g.Stroke.Color := TAdvChartGraphics.DefaultSelectionFillColor;
      g.DrawLine(PointF(0, 1), PointF(6, 1), gcpmRightDown);
      g.DrawLine(PointF(0, 2), PointF(6, 2), gcpmRightDown);
      g.DrawLine(PointF(1, 3), PointF(5, 3), gcpmRightDown);
      g.DrawLine(PointF(2, 4), PointF(4, 4), gcpmRightDown);
      g.DrawLine(PointF(3, 5), PointF(3, 5), gcpmRightDown);
    finally
      g.EndScene;
      g.Free;
    end;

    try
      AGraphics.DrawBitmap(r, bmpa);
    finally
      bmpa.Free;
    end;
  end
  else
  begin
    AGraphics.BitmapContainer := BitmapContainer;
    if Enabled then
      AGraphics.DrawScaledBitmap(r, Bitmaps)
    else
      AGraphics.DrawScaledBitmap(r, DisabledBitmaps)
  end;
end;

procedure TAdvChartDefaultToolBarButton.DrawText(AGraphics: TAdvChartGraphics);
var
  tr: TRectF;
  st: TAdvChartGraphicsSaveState;
begin
  if not TextVisible or (Text = '') then
    Exit;

  tr := GetTextRect;
  st := AGraphics.SaveState;
  try
    AGraphics.ClipRect(tr);
    AGraphics.Font.Assign(Font);
    AGraphics.DrawText(tr, Text, WordWrapping, HorizontalTextAlign, VerticalTextAlign, Trimming);
  finally
    AGraphics.RestoreState(st);
  end;
end;

procedure TAdvChartDefaultToolBarButton.DropDown;
begin
  if not FPopup.IsOpen then
  begin
    if Assigned(OnBeforeDropDown) then
      OnBeforeDropDown(Self);

    FPopup.Placement := FPopupPlacement;
    FPopup.IsOpen := True;
    if Assigned(OnDropDown) then
      OnDropDown(Self);
  end
  else
    FPopup.IsOpen := False;
end;

procedure TAdvChartDefaultToolBarButton.DoFontChanged(Sender: TObject);
begin
  Invalidate;
end;

function TAdvChartCustomToolBarButton.GetBitmapRect: TRectF;
var
  r: TRectF;
  dr: TRectf;
begin
  r := LocalRect;
  Result := RectF(r.Left, r.Top, r.Left, r.Bottom);
  if BitmapVisible then
  begin
    if DropDownKind <> ddkNormal then
    begin
      dr := GetDropDownRect;
      case DropDownPosition of
        ddpRight: Result := RectF(Result.Left + 3, Result.Top + 3, Result.Left + BitmapSize, Result.Bottom - 3);
        ddpBottom: Result := RectF(Result.Left + 3, Result.Top + 3, Result.Left + BitmapSize, dr.Top - 3);
      end;
    end
    else if not TextVisible or (Text = '') then
      Result := RectF(r.Left + 3, r.Top + 3, r.Right - 3, r.Bottom - 3)
    else if TextVisible and not (Text = '') then
      Result := RectF(r.Left + 3, r.Top + 3, r.Left + BitmapSize, r.Bottom - 3);
  end;
end;

function TAdvChartCustomToolBarButton.GetDropDownButtonControl: TAdvChartToolBarDropDownButton;
begin
  Result := FDropDownButton;
end;

function TAdvChartCustomToolBarButton.GetDropDownRect: TRectF;
begin
  Result := inherited;
  if Assigned(FDropDownButton) and (DropDownKind <> ddkNormal) then
  begin
    {$IFDEF FMXLIB}
    Result := RectF(FDropDownButton.Position.X, FDropDownButton.Position.Y, FDropDownButton.Position.X + FDropDownButton.Width, FDropDownButton.Position.Y + FDropDownButton.Height);
    {$ENDIF}
    {$IFDEF CMNLIB}
    Result := RectF(FDropDownButton.Left, FDropDownButton.Top, FDropDownButton.Left + FDropDownButton.Width, FDropDownButton.Top + FDropDownButton.Height);
    {$ENDIF}
  end;
end;

function TAdvChartCustomToolBarButton.GetTextRect: TRectF;
var
  bmpr: TRectF;
  dr: TRectF;
  r: TRectF;
begin
  r := LocalRect;
  bmpr := GetBitmapRect;
  dr := GetDropDownRect;
  if DropDownKind <> ddkNormal then
  begin
    if not StretchText then
    begin
      case DropDownPosition of
        ddpRight: Result := RectF(bmpr.Right + 3, r.Top + 3, dr.Left - 3, r.Bottom - 3);
        ddpBottom: Result := RectF(bmpr.Right + 3, r.Top + 3, r.Right - 3, dr.Top - 3);
      end;
    end
    else
    begin
      case DropDownPosition of
        ddpRight: Result := RectF(r.Left + 3, r.Top + 3, dr.Left - 3, r.Bottom - 3);
        ddpBottom: Result := RectF(r.Left + 3, r.Top + 3, r.Right - 3, dr.Top - 3);
      end;
    end;
  end
  else
  begin
    if not StretchText then
      Result := RectF(bmpr.Right + 3, r.Top + 3, dr.Left - 3, r.Bottom - 3)
    else
      Result := RectF(r.Left + 3, r.Top + 3, dr.Left - 3, r.Bottom - 3);
  end;
end;

procedure TAdvChartCustomToolBarButton.HandleMouseDown(Button: TAdvMouseButton;
  Shift: TShiftState; X, Y: Single);
begin
  inherited;
  if DropDownKind = ddkDropDown then
    DropDown;
end;

function TAdvChartDefaultToolBarButton.GetBitmap: TAdvChartBitmap;
begin
  Result := TAdvChartGraphics.GetScaledBitmap(Bitmaps, 0, FBitmapContainer);
end;

function TAdvChartDefaultToolBarButton.GetBitmapContainer: TAdvChartBitmapContainer;
begin
  Result := FBitmapContainer;
end;

function TAdvChartDefaultToolBarButton.GetBitmapRect: TRectF;
var
  r: TRectF;
begin
  r := LocalRect;
  Result := RectF(r.Left, r.Top, r.Left, r.Bottom);
  if BitmapVisible then
    Result := RectF(Result.Left + 3, Result.Top + 3, Result.Left + BitmapSize, Result.Bottom - 3);
end;

function TAdvChartDefaultToolBarButton.GetDropDownRect: TRectF;
var
  r: TRectF;
begin
  r := LocalRect;
  Result := RectF(r.Right, r.Top, r.Right, r.Bottom);
end;

function TAdvChartDefaultToolBarButton.GetHintString: String;
begin
  Result := Hint;
end;

function TAdvChartDefaultToolBarButton.GetPopupControl: TAdvChartPopup;
begin
  Result := FPopup;
end;

function TAdvChartDefaultToolBarButton.GetText: String;
begin
  Result := FText;
end;

function TAdvChartDefaultToolBarButton.GetTextRect: TRectF;
var
  bmpr: TRectF;
  dr: TRectF;
  r: TRectF;
begin
  r := LocalRect;
  bmpr := GetBitmapRect;
  dr := GetDropDownRect;
  if not StretchText then
    Result := RectF(bmpr.Right + 3, r.Top + 3, dr.Left - 3, r.Bottom - 3)
  else
    Result := RectF(r.Left + 3, r.Top + 3, dr.Left - 3, r.Bottom - 3);
end;

procedure TAdvChartDefaultToolBarButton.InitializePopup;
begin

end;

function TAdvChartDefaultToolBarButton.IsBitmapSizeStored: Boolean;
begin
  Result := BitmapSize <> 32;
end;

function TAdvChartDefaultToolBarButton.IsDropDownHeightStored: Boolean;
begin
  Result := DropDownHeight <> 135;
end;

function TAdvChartDefaultToolBarButton.IsDropDownWidthStored: Boolean;
begin
  Result := DropDownWidth <> 135;
end;

procedure TAdvChartDefaultToolBarButton.HandleKeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited;
  case Key of
    KEY_HOME: SelectFirstValue;
    KEY_END: SelectLastValue;
    KEY_UP, KEY_LEFT:  SelectPreviousValue;
    KEY_DOWN, KEY_RIGHT: SelectNextValue;
    KEY_SPACE: Click;
  end;
end;

procedure TAdvChartDefaultToolBarButton.HandleKeyPress(var Key: Char);
begin
  inherited;
  if (Key >= #32) and not (Ord(Key) in [KEY_F2, KEY_RETURN, KEY_SPACE, KEY_ESCAPE, KEY_HOME, KEY_END, KEY_UP, KEY_LEFT, KEY_DOWN, KEY_RIGHT]) then
    SelectValueWithCharacter(Key);
end;

procedure TAdvChartDefaultToolBarButton.HandleKeyUp(var Key: Word; Shift: TShiftState);
begin
  inherited;
  if Shift <> [] then
    Exit;

  case Key of
    KEY_RETURN, KEY_F4:
    begin
      if CanDropDown then
        DropDown;
    end;
  end;
end;

procedure TAdvChartDefaultToolBarButton.HandleMouseDown(Button: TAdvMouseButton;
  Shift: TShiftState; X, Y: Single);
begin
  inherited;
  if CanFocus then
    SetFocus;

  FDown := True;
  Invalidate;
end;

procedure TAdvChartDefaultToolBarButton.HandleMouseMove(Shift: TShiftState; X,
  Y: Single);
begin
  inherited;
  FHover := True;
  if FPrevHover <> FHover then
    Invalidate;

  FPrevHover := FHover;
end;

procedure TAdvChartDefaultToolBarButton.HandleMouseUp(Button: TAdvMouseButton;
  Shift: TShiftState; X, Y: Single);
begin
  inherited;
  FDown := False;
  Invalidate;
end;

function TAdvChartDefaultToolBarButton.HasHint: Boolean;
begin
  Result := Hint <> '';
end;

procedure TAdvChartDefaultToolBarButton.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited;
  if (Operation = opRemove) and (AComponent = FBitmapContainer) then
    FBitmapContainer := nil;

  if (Operation = opRemove) and (AComponent = FDropDownControl) then
    FDropDownControl := nil;
end;

procedure TAdvChartDefaultToolBarButton.Draw(AGraphics: TAdvChartGraphics; ARect: TRectF);
var
  r: TRectF;
begin
  inherited;
  if not Appearance.Transparent then
  begin
    if Enabled then
    begin
      if FDown or FDownState then
      begin
        AGraphics.Fill.Assign(Appearance.DownFill);
        AGraphics.Stroke.Assign(Appearance.DownStroke);
      end
      else if FHover then
      begin
        AGraphics.Fill.Assign(Appearance.HoverFill);
        AGraphics.Stroke.Assign(Appearance.HoverStroke);
      end
      else
      begin
        AGraphics.Fill.Assign(Appearance.NormalFill);
        AGraphics.Stroke.Assign(Appearance.NormalStroke);
      end;
    end
    else
    begin
      AGraphics.Fill.Assign(Appearance.DisabledFill);
      AGraphics.Stroke.Assign(Appearance.DisabledStroke);
    end;

    r := LocalRect;

    if Appearance.FlatStyle then
    begin
      AGraphics.Fill.Kind := gfkSolid;
      AGraphics.DrawRectangle(r);
    end
    else
      AGraphics.DrawRoundRectangle(r, Appearance.Rounding, Appearance.Corners);

    if Appearance.ShowInnerStroke and not Appearance.FlatStyle then
    begin
      InflateRectEx(r, -1, -1);
      AGraphics.Stroke.Assign(Appearance.InnerStroke);
      AGraphics.Fill.Kind := gfkNone;
      AGraphics.DrawRoundRectangle(r, Appearance.Rounding, Appearance.Corners);
    end;
  end;

  DrawBitmap(AGraphics);
  DrawText(AGraphics);

  if ShowFocus and Focused then
  begin
    r := GetTextRect;
    AGraphics.DrawFocusRectangle(r);
  end;
end;

procedure TAdvChartDefaultToolBarButton.PopupCloseUp(Sender: TObject);
begin
  if Assigned(OnCloseDropDown) then
    OnCloseDropDown(Self);
end;

procedure TAdvChartDefaultToolBarButton.ResetToDefaultStyle;
begin
  inherited;
  Font.Color := gcBlack;
  Appearance.NormalFill.Color := gcWhite;
  Appearance.HoverFill.Color := gcWhite;
  Appearance.DownFill.Color := gcWhite;
  Appearance.DisabledFill.Color := gcWhite;
  Appearance.NormalStroke.Color := gcGray;
  Appearance.InnerStroke.Color := gcWhite;
  Appearance.HoverStroke.Color := gcGray;
  Appearance.DownStroke.Color := gcGray;
  Appearance.DisabledStroke.Color := gcGray;

  Appearance.NormalFill.Kind := gfkGradient;
  Appearance.HoverFill.Kind := gfkGradient;
  Appearance.DownFill.Kind := gfkGradient;
  Appearance.DisabledFill.Kind := gfkSolid;
  Appearance.NormalStroke.Kind := gskSolid;
  Appearance.InnerStroke.Kind := gskSolid;
  Appearance.HoverStroke.Kind := gskSolid;
  Appearance.DownStroke.Kind := gskSolid;
  Appearance.DisabledStroke.Kind := gskSolid;

  Appearance.NormalFill.Color := MakeGraphicsColor(249, 251, 252);
  Appearance.NormalFill.ColorTo := MakeGraphicsColor(230, 235, 235);
  Appearance.NormalFill.ColorMirror := MakeGraphicsColor(220, 220, 236);
  Appearance.NormalFill.ColorMirrorTo := MakeGraphicsColor(220, 225, 236);

  Appearance.HoverFill.Color := MakeGraphicsColor(229, 231, 232);
  Appearance.HoverFill.ColorTo := MakeGraphicsColor(210, 215, 215);
  Appearance.HoverFill.ColorMirror := MakeGraphicsColor(200, 200, 216);
  Appearance.HoverFill.ColorMirrorTo := MakeGraphicsColor(200, 205, 216);

  Appearance.DownFill.Color := MakeGraphicsColor(219, 221, 222);
  Appearance.DownFill.ColorTo := MakeGraphicsColor(200, 205, 205);
  Appearance.DownFill.ColorMirror := MakeGraphicsColor(190, 190, 206);
  Appearance.DownFill.ColorMirrorTo := MakeGraphicsColor(190, 195, 206);
end;

procedure TAdvChartDefaultToolBarButton.SelectFirstValue;
begin

end;

procedure TAdvChartDefaultToolBarButton.SelectLastValue;
begin

end;

procedure TAdvChartDefaultToolBarButton.SelectNextValue;
begin

end;

procedure TAdvChartDefaultToolBarButton.SelectPreviousValue;
begin

end;

procedure TAdvChartDefaultToolBarButton.SelectValueWithCharacter(
  ACharacter: Char);
begin

end;

procedure TAdvChartDefaultToolBarButton.SetAdaptToStyle(const Value: Boolean);
begin
  inherited;
  if Assigned(FPopup) then
    FPopup.AdaptToStyle := AdaptToStyle;
end;

procedure TAdvChartDefaultToolBarButton.SetAppearance(
  const Value: TAdvChartToolBarButtonAppearance);
begin
  FAppearance.Assign(Value);
end;

procedure TAdvChartDefaultToolBarButton.SetBitmaps(const Value: TAdvScaledBitmaps);
begin
  FBitmaps.Assign(Value);
end;

procedure TAdvChartDefaultToolBarButton.SetBitmapSize(const Value: Single);
begin
  if FBitmapSize <> Value then
  begin
    FBitmapSize := Value;
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetBitmapContainer(
  const Value: TAdvChartBitmapContainer);
begin
  FBitmapContainer := Value;
end;

procedure TAdvChartDefaultToolBarButton.SetBitmapVisible(const Value: Boolean);
begin
  FBitmapVisible := Value;
  Invalidate;
end;

procedure TAdvChartDefaultToolBarButton.SetCloseOnSelection(const Value: Boolean);
begin
  if FCloseOnSelection <> Value then
  begin
    FCloseOnSelection := Value;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetName(const Value: TComponentName);
var
  ChangeText: Boolean;
begin
  ChangeText := not (csLoading in ComponentState) and (Name = Text) and
    ((not Assigned(Owner)) or not (Owner is TComponent) or not (csLoading in TComponent(Owner).ComponentState));
  inherited SetName(Value);
  if ChangeText and ApplyName and CanChangeText then
    Text := ReplaceStr(Text, 'AdvChartToolBar', '');
end;

procedure TAdvChartDefaultToolBarButton.SetShowFocus(const Value: Boolean);
begin
  if FShowFocus <> Value then
  begin
    FShowFocus := Value;
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetStretchText(const Value: Boolean);
begin
  if FStretchText <> Value then
  begin
    FStretchText := Value;
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetText(const Value: String);
begin
  if FText <> Value then
  begin
    FText := Value;
    FTextVisible := Value <> '';
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetTextVisible(const Value: Boolean);
begin
  if FTextVisible <> Value then
  begin
    FTextVisible := Value;
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetTrimming(
  const Value: TAdvChartGraphicsTextTrimming);
begin
  if FTrimming <> Value then
  begin
    FTrimming := Value;
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetVerticalTextAlign(
  const Value: TAdvChartGraphicsTextAlign);
begin
  if FVerticalTextAlign <> Value then
  begin
    FVerticalTextAlign := Value;
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.SetWordWrapping(const Value: Boolean);
begin
  if FWordWrapping <> Value then
  begin
    FWordWrapping := Value;
    Invalidate;
  end;
end;

procedure TAdvChartDefaultToolBarButton.UpdateState;
var
  f: Single;
begin
  inherited;
  f := 1;
  case FState of
    esNormal: f := 0.8;
    esLarge: f := 1.25;
  end;

  if not (csLoading in ComponentState) then
  begin
    DropDownWidth := DropDownWidth * f;
    DropDownHeight := DropDownHeight * f;
    {$IFDEF FMXLIB}
    Font.Size := Font.Size * f;
    SetBounds(Position.X, Position.Y, int(Width * f), int(Height * f));
    {$ENDIF}
    {$IFDEF VCLLIB}
    Font.Size := Round(Font.Size * f);
    SetBounds(Left, Top, Round(Width * f), Round(Height * f));
    {$ENDIF}
  end;
end;

procedure TAdvChartToolBarButtonAppearance.SetCorners(const Value: TAdvChartGraphicsCorners);
begin
  if FCorners <> Value then
  begin
    FCorners := Value;
    AppearanceChanged;
    FOwner.Invalidate;
  end;
end;

procedure TAdvChartToolBarButtonAppearance.SetRounding(const Value: Single);
begin
  if FRounding <> Value then
  begin
    FRounding := Value;
    AppearanceChanged;
    FOwner.Invalidate;
  end;
end;

procedure TAdvChartToolBarButtonAppearance.StrokeChanged(Sender: TObject);
begin
  FOwner.Invalidate;
end;

{ TAdvChartCustomToolBarSeparator }

procedure TAdvChartCustomToolBarSeparator.Assign(Source: TPersistent);
begin
  inherited;
  if Source is TAdvChartCustomToolBarSeparator then
  begin
    FAppearance.Assign((Source as TAdvChartCustomToolBarSeparator).Appearance);
    Invalidate;
  end;
end;

constructor TAdvChartCustomToolBarSeparator.Create(AOwner: TComponent);
begin
  inherited;
  {$IFDEF FMXLIB}
  Width := 3;
  {$ENDIF}
  {$IFDEF CMNLIB}
  Width := 2;
  {$ENDIF}
  Height := 30;
  FAppearance := TAdvChartToolBarSeparatorAppearance.Create(Self);
end;

destructor TAdvChartCustomToolBarSeparator.Destroy;
begin
  FAppearance.Free;
  inherited;
end;

procedure TAdvChartCustomToolBarSeparator.Draw(AGraphics: TAdvChartGraphics; ARect: TRectF);
var
  cp: TPointF;
  r: TRectF;
begin
  inherited;
  r := LocalRect;
  {$IFDEF FMXLIB}
  cp := r.CenterPoint;
  {$ENDIF}
  {$IFDEF CMNLIB}
  cp := PointF(r.Left, r.Top);
  {$ENDIF}
  AGraphics.Stroke.Assign(Appearance.Stroke);
  AGraphics.DrawLine(PointF(cp.X, r.Top), PointF(cp.X, r.Bottom));
  AGraphics.Stroke.Color := gcWhite;
  AGraphics.DrawLine(PointF(cp.X + 1, r.Top), PointF(cp.X + 1, r.Bottom));
end;

procedure TAdvChartCustomToolBarSeparator.SetAppearance(
  const Value: TAdvChartToolBarSeparatorAppearance);
begin
  FAppearance.Assign(Value);
end;

procedure TAdvChartCustomToolBarSeparator.UpdateState;
var
  f: Single;
begin
  inherited;
  f := 1;
  case State of
    esNormal: f := 0.8;
    esLarge: f := 1.25;
  end;

  if not (csLoading in ComponentState) then
  begin
    {$IFDEF FMXLIB}
    SetBounds(Position.X, Position.Y, Width, int(Height * f));
    {$ENDIF}
    {$IFDEF CMNLIB}
    SetBounds(Left, Top, Width, Round(Height * f));
    {$ENDIF}
  end;
end;

{ TAdvChartToolBarButtonAppearance }

procedure TAdvChartToolBarButtonAppearance.AppearanceChanged;
begin
  FOwner.AppearanceChanged;
end;

procedure TAdvChartToolBarButtonAppearance.Assign(Source: TPersistent);
begin
  if Source is TAdvChartToolBarButtonAppearance then
  begin
    FNormalFill.Assign((Source as TAdvChartToolBarButtonAppearance).NormalFill);
    FDisabledFill.Assign((Source as TAdvChartToolBarButtonAppearance).DisabledFill);
    FHoverFill.Assign((Source as TAdvChartToolBarButtonAppearance).HoverFill);
    FDownFill.Assign((Source as TAdvChartToolBarButtonAppearance).DownFill);
    FNormalStroke.Assign((Source as TAdvChartToolBarButtonAppearance).NormalStroke);
    FDisabledStroke.Assign((Source as TAdvChartToolBarButtonAppearance).DisabledStroke);
    FHoverStroke.Assign((Source as TAdvChartToolBarButtonAppearance).HoverStroke);
    FDownStroke.Assign((Source as TAdvChartToolBarButtonAppearance).DownStroke);
    FRounding := (Source as TAdvChartToolBarButtonAppearance).Rounding;
    FCorners := (Source as TAdvChartToolBarButtonAppearance).Corners;
    FShowInnerStroke := (Source as TAdvChartToolBarButtonAppearance).ShowInnerStroke;
    FTransparent := (Source as TAdvChartToolBarButtonAppearance).Transparent;
    FFlatStyle := (Source as TAdvChartToolBarButtonAppearance).FlatStyle;
  end
  else
    inherited;
end;

constructor TAdvChartToolBarButtonAppearance.Create(AOwner: TAdvChartDefaultToolBarButton);
begin
  FOwner := AOwner;
  FCorners := [gcTopLeft, gcTopRight, gcBottomLeft, gcBottomRight];
  FRounding := 3;
  FTransparent := False;
  FShowInnerStroke := True;
  FFlatStyle := False;

  FNormalFill := TAdvChartGraphicsFill.Create(gfkGradient);
  FHoverFill := TAdvChartGraphicsFill.Create(gfkGradient);
  FDownFill := TAdvChartGraphicsFill.Create(gfkGradient);
  FDisabledFill := TAdvChartGraphicsFill.Create(gfkSolid);
  FNormalStroke := TAdvChartGraphicsStroke.Create(gskSolid, gcGray);
  FInnerStroke := TAdvChartGraphicsStroke.Create(gskSolid, gcWhite);
  FHoverStroke := TAdvChartGraphicsStroke.Create(gskSolid, gcGray);
  FDownStroke := TAdvChartGraphicsStroke.Create(gskSolid, gcGray);
  FDisabledStroke := TAdvChartGraphicsStroke.Create(gskSolid, gcGray);

  FNormalFill.OnChanged := FillChanged;
  FHoverFill.OnChanged := FillChanged;
  FDownFill.OnChanged := FillChanged;
  FDisabledFill.OnChanged := FillChanged;

  FInnerStroke.OnChanged := StrokeChanged;
  FNormalStroke.OnChanged := StrokeChanged;
  FHoverStroke.OnChanged := StrokeChanged;
  FDownStroke.OnChanged := StrokeChanged;
  FDisabledStroke.OnChanged := StrokeChanged;

  FNormalFill.Color := MakeGraphicsColor(249, 251, 252);
  FNormalFill.ColorTo := MakeGraphicsColor(230, 235, 235);
  FNormalFill.ColorMirror := MakeGraphicsColor(220, 220, 236);
  FNormalFill.ColorMirrorTo := MakeGraphicsColor(220, 225, 236);

  FHoverFill.Color := MakeGraphicsColor(229, 231, 232);
  FHoverFill.ColorTo := MakeGraphicsColor(210, 215, 215);
  FHoverFill.ColorMirror := MakeGraphicsColor(200, 200, 216);
  FHoverFill.ColorMirrorTo := MakeGraphicsColor(200, 205, 216);

  FDownFill.Color := MakeGraphicsColor(219, 221, 222);
  FDownFill.ColorTo := MakeGraphicsColor(200, 205, 205);
  FDownFill.ColorMirror := MakeGraphicsColor(190, 190, 206);
  FDownFill.ColorMirrorTo := MakeGraphicsColor(190, 195, 206);
end;

destructor TAdvChartToolBarButtonAppearance.Destroy;
begin
  FNormalFill.Free;
  FHoverFill.Free;
  FDownFill.Free;
  FDisabledFill.Free;

  FInnerStroke.Free;
  FNormalStroke.Free;
  FHoverStroke.Free;
  FDownStroke.Free;
  FDisabledStroke.Free;
  inherited;
end;

procedure TAdvChartToolBarButtonAppearance.FillChanged(Sender: TObject);
begin
  if Assigned(FOwner) then
    FOwner.Invalidate;
end;

function TAdvChartToolBarButtonAppearance.IsRoundingStored: Boolean;
begin
  Result := Rounding <> 3;
end;

procedure TAdvChartToolBarButtonAppearance.SetDisabledFill(const Value: TAdvChartGraphicsFill);
begin
  FDisabledFill.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetDisabledStroke(
  const Value: TAdvChartGraphicsStroke);
begin
  FDisabledStroke.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetDownFill(const Value: TAdvChartGraphicsFill);
begin
  FDownFill.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetDownStroke(
  const Value: TAdvChartGraphicsStroke);
begin
  FDownStroke.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetFlatStyle(const Value: Boolean);
var
  c: TControl;
  I: Integer;
begin
  if FFlatStyle <> Value then
  begin
    FFlatStyle := Value;
    if Assigned(FOwner) then
    begin
      for I := 0 to FOwner.ControlCount - 1 do
      begin
        c := FOwner.Controls[I];
        {$IFDEF FMXLIB}
        if Supports(c, IDesignerControl) then
          Continue;
        {$ENDIF}

        if c is TAdvChartDefaultToolBarButton then
          (c as TAdvChartDefaultToolBarButton).Appearance.FlatStyle := FlatStyle;

        if c is TAdvChartCustomToolBar then
          (c as TAdvChartCustomToolBar).Appearance.FlatStyle := FlatStyle;
      end;

      FOwner.Invalidate;
    end;
  end;
end;

procedure TAdvChartToolBarButtonAppearance.SetHoverFill(const Value: TAdvChartGraphicsFill);
begin
  FHoverFill.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetHoverStroke(
  const Value: TAdvChartGraphicsStroke);
begin
  FHoverStroke.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetInnerStroke(
  const Value: TAdvChartGraphicsStroke);
begin
  FInnerStroke.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetNormalFill(const Value: TAdvChartGraphicsFill);
begin
  FNormalFill.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetNormalStroke(
  const Value: TAdvChartGraphicsStroke);
begin
  FNormalStroke.Assign(Value);
end;

procedure TAdvChartToolBarButtonAppearance.SetShowInnerStroke(
  const Value: Boolean);
begin
  if FShowInnerStroke <> Value then
  begin
    FShowInnerStroke := Value;
    if Assigned(FOwner) then
      FOwner.Invalidate;
  end;
end;

procedure TAdvChartToolBarButtonAppearance.SetTransparent(
  const Value: Boolean);
begin
  if FTransparent <> Value then
  begin
    FTransparent := Value;
    if Assigned(FOwner) then
      FOwner.Invalidate;
  end;
end;

{ TAdvChartCustomToolBarAppearance }

procedure TAdvChartCustomToolBarAppearance.Assign(Source: TPersistent);
begin
  if Source is TAdvChartCustomToolBarAppearance then
  begin
    FFill.Assign((Source as TAdvChartCustomToolBarAppearance).Fill);
    FStroke.Assign((Source as TAdvChartCustomToolBarAppearance).Stroke);
    FHorizontalSpacing := (Source as TAdvChartCustomToolBarAppearance).HorizontalSpacing;
    FVerticalSpacing := (Source as TAdvChartCustomToolBarAppearance).VerticalSpacing;
    FDragGripColor := (Source as TAdvChartCustomToolBarAppearance).DragGripColor;
    FDragGrip := (Source as TAdvChartCustomToolBarAppearance).DragGrip;
    FFlatStyle := (Source as TAdvChartCustomToolBarAppearance).FlatStyle;
  end;
end;

constructor TAdvChartCustomToolBarAppearance.Create(AOwner: TAdvChartCustomToolBar);
begin
  FOwner := AOwner;
  FFlatStyle := False;
  FHorizontalSpacing := 3;
  FVerticalSpacing := 3;
  FDragGrip := True;
  FDragGripColor := gcLightgray;
  FFill := TAdvChartGraphicsFill.Create(gfkGradient);
  FStroke := TAdvChartGraphicsStroke.Create(gskSolid, gcGray);

  FFill.OnChanged := FillChanged;
  FStroke.OnChanged := StrokeChanged;

  FFill.Color := gcWhite;
  FFill.ColorTo := MakeGraphicsColor(230, 230, 230);
end;

destructor TAdvChartCustomToolBarAppearance.Destroy;
begin
  FFill.Free;
  FStroke.Free;
  inherited;
end;

procedure TAdvChartCustomToolBarAppearance.FillChanged(Sender: TObject);
begin
  FOwner.Invalidate;
end;

function TAdvChartCustomToolBarAppearance.IsHorizontalSpacingStored: Boolean;
begin
  Result := HorizontalSpacing <> 3;
end;

function TAdvChartCustomToolBarAppearance.IsVerticalSpacingStored: Boolean;
begin
  Result := VerticalSpacing <> 3;
end;

procedure TAdvChartCustomToolBarAppearance.SetDragGrip(const Value: Boolean);
begin
  if FDragGrip <> Value then
  begin
    FDragGrip := Value;
    FOwner.UpdateControls;
  end;
end;

procedure TAdvChartCustomToolBarAppearance.SetDragGripColor(
  const Value: TAdvChartGraphicsColor);
begin
  if FDragGripColor <> Value then
  begin
    FDragGripColor := Value;
    FOwner.Invalidate;
  end;
end;

procedure TAdvChartCustomToolBarAppearance.SetFill(const Value: TAdvChartGraphicsFill);
begin
  FFill.Assign(Value);
end;

procedure TAdvChartCustomToolBarAppearance.SetFlatStyle(const Value: Boolean);
var
  I: Integer;
  c: TControl;
begin
  if FFlatStyle <> Value then
  begin
    FFlatStyle := Value;
    if Assigned(FOwner) then
    begin
      for I := 0 to FOwner.ControlCount - 1 do
      begin
        c := FOwner.Controls[I];
        {$IFDEF FMXLIB}
        if Supports(c, IDesignerControl) then
          Continue;
        {$ENDIF}

        if c is TAdvChartDefaultToolBarButton then
          (c as TAdvChartDefaultToolBarButton).Appearance.FlatStyle := FlatStyle;

        if c is TAdvChartCustomToolBar then
          (c as TAdvChartCustomToolBar).Appearance.FlatStyle := FlatStyle;
      end;
      FOwner.Invalidate;
    end;
  end;
end;

procedure TAdvChartCustomToolBarAppearance.SetHorizontalSpacing(
  const Value: Single);
begin
  if FHorizontalSpacing <> Value then
  begin
    FHorizontalSpacing := Value;
    FOwner.UpdateControls;
  end;
end;

procedure TAdvChartCustomToolBarAppearance.SetStroke(const Value: TAdvChartGraphicsStroke);
begin
  FStroke.Assign(Value);
end;

procedure TAdvChartCustomToolBarAppearance.SetVerticalSpacing(
  const Value: Single);
begin
  if FVerticalSpacing <> Value then
  begin
    FVerticalSpacing := Value;
    FOwner.UpdateControls;
  end;
end;

procedure TAdvChartCustomToolBarAppearance.StrokeChanged(Sender: TObject);
begin
  FOwner.Invalidate;
end;

{ TAdvChartCustomToolBarSeparatorAppearance }

procedure TAdvChartCustomToolBarSeparatorAppearance.Assign(Source: TPersistent);
begin
  if Source is TAdvChartCustomToolBarSeparatorAppearance then
  begin
    Stroke.Assign((Source as TAdvChartCustomToolBarSeparatorAppearance).Stroke);
  end
  else
    inherited;
end;

constructor TAdvChartCustomToolBarSeparatorAppearance.Create(
  AOwner: TAdvChartCustomToolBarSeparator);
begin
  FOwner := AOwner;
  FStroke := TAdvChartGraphicsStroke.Create(gskSolid, gcGray);
  FStroke.OnChanged := StrokeChanged;
end;

destructor TAdvChartCustomToolBarSeparatorAppearance.Destroy;
begin
  FStroke.Free;
  inherited;
end;

procedure TAdvChartCustomToolBarSeparatorAppearance.SetStroke(
  const Value: TAdvChartGraphicsStroke);
begin
  FStroke.Assign(Value);
end;

procedure TAdvChartCustomToolBarSeparatorAppearance.StrokeChanged(
  Sender: TObject);
begin
  FOwner.Invalidate;
end;

{ TAdvChartCustomDockPanel }

function TAdvChartCustomDockPanel.AddToolBar(AIndex: Integer = -1): TAdvChartToolBar;
begin
  FBlockUpdate := True;
  Result := TAdvChartToolBar.Create(Self);
  {$IFDEF FMXLIB}
  if (AIndex >= 0) and (AIndex <= ControlCount - 1) then
    InsertObject(AIndex, Result)
  else
    AddObject(Result);
  {$ENDIF}
  {$IFDEF CMNLIB}
  Result.Parent := Self;
  {$ENDIF}

  FBlockUpdate := False;
  UpdateControls;
end;

procedure TAdvChartCustomDockPanel.ApplyStyle;
var
  c: TAdvChartGraphicsColor;
begin
  inherited;
  c := gcNull;
  if TAdvChartStyles.GetStyleHeaderFillColor(c) then
  begin
    Appearance.Fill.Kind := gfkSolid;
    Appearance.Fill.Color := c;
  end;

  if TAdvChartStyles.GetStyleHeaderFillColorTo(c) then
  begin
    Appearance.Fill.Kind := gfkGradient;
    Appearance.Fill.ColorTo := c;
  end;
end;

procedure TAdvChartCustomDockPanel.Assign(Source: TPersistent);
begin
  inherited;
  if Source is TAdvChartCustomDockPanel then
  begin
    Appearance.Assign((Source as TAdvChartCustomDockPanel).Appearance);
    AutoSize := (Source as TAdvChartCustomDockPanel).AutoSize;
    AutoAlign := (Source as TAdvChartCustomDockPanel).AutoAlign;
    State := (Source as TAdvChartCustomDockPanel).State;
  end
  else
    inherited;
end;

constructor TAdvChartCustomDockPanel.Create(AOwner: TComponent);
begin
  inherited;
  FState := esNormal;
  FAppearance := TAdvDockPanelAppearance.Create(Self);
  FAutoSize := True;
  FAutoAlign := True;
  {$IFDEF FMXLIB}
  Align := TAlignLayout.Top;
  {$ENDIF}
  {$IFDEF CMNLIB}
  Align := alTop;
  {$ENDIF}
  Height := 40;
end;

destructor TAdvChartCustomDockPanel.Destroy;
begin
  FAppearance.Free;
  inherited;
end;

{$IFDEF CMNLIB}
procedure TAdvChartCustomDockPanel.AlignControls(AControl: TControl; var Rect: TRect);
begin
  inherited;
  UpdateControls;
end;
{$ENDIF}

{$IFDEF FMXLIB}
procedure TAdvChartCustomDockPanel.DoAddObject(const AObject: TFmxObject);
begin
  inherited;
  UpdateControls;
end;

procedure TAdvChartCustomDockPanel.DoInsertObject(Index: Integer;
  const AObject: TFmxObject);
begin
  inherited;
  UpdateControls;
end;

procedure TAdvChartCustomDockPanel.DoRealign;
begin
  inherited;
  UpdateControls;
end;

procedure TAdvChartCustomDockPanel.DoRemoveObject(
  const AObject: TFmxObject);
begin
  inherited;
  UpdateControls;
end;
{$ENDIF}

function TAdvChartCustomDockPanel.GetVersion: String;
begin
  Result := GetVersionNumber(MAJ_VER, MIN_VER, REL_VER, BLD_VER);
end;

procedure TAdvChartCustomDockPanel.InitializeControls;
var
  I: Integer;
  c: TControl;
begin
  for I := 0 to ControlCount - 1 do
  begin
    c := Controls[I];
    {$IFDEF FMXLIB}
    if Supports(c, IDesignerControl) then
      Continue;
    {$ENDIF}

    if c is TAdvChartCustomToolBar then
      (c as TAdvChartCustomToolBar).OnUpdateDockPanel := UpdateDockPanel;

    if c.Visible then
    begin
      {$IFDEF FMXLIB}
      if c.Position.y < Appearance.Margins.Top then
        c.Position.y := Appearance.Margins.Top;
      if c.Position.x < Appearance.Margins.Left then
        c.Position.x := Appearance.Margins.Left
      else if c.Position.x + c.Width > Width - Appearance.Margins.Right then
        c.Position.x := Width - Appearance.Margins.Right - c.Width;
      {$ENDIF}
      {$IFDEF CMNLIB}
      if c.Top < Appearance.Margins.Top then
        c.Top := Round(Appearance.Margins.Top);
      if c.Left < Appearance.Margins.Left then
        c.Left := Round(Appearance.Margins.Left)
      else if c.Left + c.Width > Width - Appearance.Margins.Right then
        c.Left := Round(Width - Appearance.Margins.Right - c.Width);
      {$ENDIF}
    end;
  end;
end;

procedure TAdvChartCustomDockPanel.Draw(AGraphics: TAdvChartGraphics; ARect: TRectF);
var
  r: TRectF;
begin
  inherited;
  AGraphics.Fill.Assign(Appearance.Fill);
  AGraphics.Stroke.Assign(Appearance.Stroke);

  r := LocalRect;
  AGraphics.DrawRectangle(r);
end;

procedure TAdvChartCustomDockPanel.RearrangeControls;
var
  c, cl: TControl;
  cr, clr: TRectF;
  I, J: Integer;
begin
  for I := 0 to ControlCount - 1 do
  begin
    c := Controls[I];

    {$IFDEF FMXLIB}
    if Supports(c, IDesignerControl) then
      Continue;
    {$ENDIF}

    if not c.Visible then
      Continue;

    for J := 0 to ControlCount - 1 do
    begin
      cl := Controls[J];

      if (cl = c) or not cl.Visible then
        Continue;

      {$IFDEF FMXLIB}
      if Supports(cl, IDesignerControl) then
        Continue;
      {$ENDIF}

      {$IFDEF FMXLIB}
      cr := RectF(c.Position.X, c.Position.Y, c.Position.X + c.Width, c.Position.Y + c.Height);
      clr := RectF(cl.Position.X, cl.Position.Y, cl.Position.X + cl.Width, cl.Position.Y + cl.Height);

      if (clr.Left >= cr.Left - 3) and (clr.Left <= cr.Right + 3) then
      begin
        if (clr.Top < cr.CenterPoint.Y) and (clr.Top >= cr.Top - 3) then
        begin
          cl.Position.X := c.Position.X + c.Width + 3;
          cl.Position.Y := c.Position.Y;
        end
        else if (clr.Top >= cr.CenterPoint.Y) and (clr.Top <= cr.Bottom + 3) then
        begin
          cl.Position.Y := c.Position.Y + c.Height + 3;
          cl.Position.X := c.Position.X;
        end;
      end;
      {$ENDIF}

      {$IFDEF CMNLIB}
      cr := RectF(c.Left, c.Top, c.Left + c.Width, c.Top + c.Height);
      clr := RectF(cl.Left, cl.Top, cl.Left + cl.Width, cl.Top + cl.Height);

      if (clr.Left >= cr.Left - 3) and (clr.Left <= cr.Right + 3) then
      begin
        if (clr.Top < cr.CenterPoint.Y) and (clr.Top >= cr.Top - 3) then
        begin
          cl.Left := c.Left + c.Width + 3;
          cl.Top := c.Top;
        end
        else if (clr.Top >= cr.CenterPoint.Y) and (clr.Top <= cr.Bottom + 3) then
        begin
          cl.Top := c.Top + c.Height + 3;
          cl.Left := c.Left;
        end;
      end;
      {$ENDIF}
    end;
  end;
end;

procedure TAdvChartCustomDockPanel.ResetToDefaultStyle;
begin
  inherited;

end;

procedure TAdvChartCustomDockPanel.SetAdaptToStyle(const Value: Boolean);
begin
  inherited;
  UpdateControls;
end;

procedure TAdvChartCustomDockPanel.SetAppearance(
  const Value: TAdvDockPanelAppearance);
begin
  FAppearance.Assign(Value);
end;

procedure TAdvChartCustomDockPanel.SetAutoAlign(const Value: Boolean);
begin
  if FAutoAlign <> Value then
  begin
    FAutoAlign := Value;
    UpdateControls;
  end;
end;

procedure TAdvChartCustomDockPanel.SetAS(const Value: Boolean);
begin
  if FAutoSize <> Value then
  begin
    FAutoSize := Value;
    UpdateControls;
  end;
end;

procedure TAdvChartCustomDockPanel.SetState(
  const Value: TAdvChartToolBarElementState);
var
  I: Integer;
  c: TControl;
begin
  if FState <> Value then
  begin
    FState := Value;
    for I := 0 to ControlCount - 1 do
    begin
      c := Controls[I];
      if c is TAdvChartCustomToolBar then
        (c as TAdvChartCustomToolBar).State := FState;
    end;
  end;
end;

procedure TAdvChartCustomDockPanel.UpdateControls;
var
  I: Integer;
  {$IFDEF FMXLIB}
  h, hsm: Single;
  {$ENDIF}
  {$IFDEF CMNLIB}
  h, hsm: Integer;
  {$ENDIF}
  c: TControl;
  ia: IAdvAdaptToStyle;
begin
  if FBlockUpdate then
    Exit;

  FBlockUpdate := True;
  h := 0;
  hsm := 30;

  if AutoAlign then
  begin
    InitializeControls;
    RearrangeControls;
  end;

  if AutoSize then
  begin
    for I := 0 to ControlCount - 1 do
    begin
      c := Controls[I];
      {$IFDEF FMXLIB}
      if Supports(c, IDesignerControl) then
        Continue;

      if c.Visible then
        h := Max(h, c.Position.y + c.Height + Appearance.Margins.Bottom);
      {$ENDIF}

      if Supports(c, IAdvAdaptToStyle, ia) then
        ia.AdaptToStyle := AdaptToStyle;

      {$IFDEF CMNLIB}
      if c.Visible then
        h := Max(h, Round(c.Top + c.Height + Appearance.Margins.Bottom));
      {$ENDIF}
    end;

    if h = 0 then
      h := hsm;

    if csDesigning in ComponentState then
      h := h + 15;

    {$IFDEF FMXLIB}
    SetBounds(Position.X, Position.Y, Width, h);
    {$ENDIF}
    {$IFDEF CMNLIB}
    SetBounds(Left, Top, Width, h);
    {$ENDIF}
  end;

  FBlockUpdate := False;
end;

procedure TAdvChartCustomDockPanel.UpdateDockPanel(Sender: TObject);
begin
  UpdateControls;
end;

{ TAdvChartCustomDockPanelAppearance }

constructor TAdvChartCustomDockPanelAppearance.Create(AOwner: TAdvChartCustomDockPanel);
begin
  FOwner := AOwner;
  FFill := TAdvChartGraphicsFill.Create(gfkSolid, gcWhite);
  FStroke := TAdvChartGraphicsStroke.Create(gskSolid, gcGray);

  FFill.OnChanged := FillChanged;
  FStroke.OnChanged := StrokeChanged;
  FMargins := TAdvMargins.Create;
  FMargins.Left := 3;
  FMargins.Top := 3;
  FMargins.Bottom := 3;
  FMargins.Right := 3;
end;

destructor TAdvChartCustomDockPanelAppearance.Destroy;
begin
  FMargins.Free;
  FFill.Free;
  FStroke.Free;
  inherited;
end;

procedure TAdvChartCustomDockPanelAppearance.FillChanged(Sender: TObject);
begin
  FOwner.Invalidate;
end;

procedure TAdvChartCustomDockPanelAppearance.MarginsChanged(
  Sender: TObject);
begin
  FOwner.UpdateControls;
end;

procedure TAdvChartCustomDockPanelAppearance.SetFill(const Value: TAdvChartGraphicsFill);
begin
  FFill.Assign(Value);
end;

procedure TAdvChartCustomDockPanelAppearance.SetMargins(
  const Value: TAdvMargins);
begin
  FMargins.Assign(Value);
end;

procedure TAdvChartCustomDockPanelAppearance.SetStroke(const Value: TAdvChartGraphicsStroke);
begin
  FStroke.Assign(Value);
end;

procedure TAdvChartCustomDockPanelAppearance.StrokeChanged(Sender: TObject);
begin
  FOwner.Invalidate;
end;

{ TAdvChartCustomToolBarElement }

procedure TAdvChartCustomToolBarElement.UpdateToolBarControl;
begin
  if Assigned(OnUpdateToolBarControl) then
    OnUpdateToolBarControl(Self);
end;

procedure TAdvChartCustomToolBarElement.Assign(Source: TPersistent);
begin
  inherited;
  if Source is TAdvChartCustomToolBarElement then
  begin
    FState := (Source as TAdvChartCustomToolBarElement).State;
    FLastElement := (Source as TAdvChartCustomToolBarElement).LastElement;
    FCanCopy := (Source as TAdvChartCustomToolBarElement).CanCopy;
  end;
end;

constructor TAdvChartCustomToolBarElement.Create(AOwner: TComponent);
begin
  inherited;
  DisableBackground;
  {$IFDEF CMNLIB}
  ParentColor := True;
  {$IFDEF VCLLIB}
  ParentBackground := True;
  {$ENDIF}
  {$ENDIF}
  FLastElement := False;
  FCanCopy := True;
  FState := esNormal;
end;

destructor TAdvChartCustomToolBarElement.Destroy;
begin
  inherited;
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomToolBarElement.DoMatrixChanged(Sender: TObject);
begin
  inherited;
  UpdateToolBar;
end;
{$ENDIF}

procedure TAdvChartCustomToolBarElement.UpdateControlAfterResize;
begin
  inherited;
  UpdateToolBar;
end;

procedure TAdvChartCustomToolBarElement.SetLastElement(const Value: Boolean);
begin
  if FLastElement <> Value then
  begin
    FLastElement := Value;
    UpdateToolBar;
  end;
end;

procedure TAdvChartCustomToolBarElement.SetState(
  const Value: TAdvChartToolBarElementState);
begin
  if FState <> Value then
  begin
    FState := Value;
    UpdateState;
  end;
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomToolBarElement.SetVisible(const Value: Boolean);
{$ENDIF}
{$IFDEF CMNLIB}
procedure TAdvChartCustomToolBarElement.VisibleChanging;
{$ENDIF}
begin
  inherited;
  UpdateToolBar;
end;

procedure TAdvChartCustomToolBarElement.UpdateState;
begin

end;

procedure TAdvChartCustomToolBarElement.UpdateToolBar;
begin
  if Assigned(OnUpdateToolBar) then
    OnUpdateToolBar(Self);
end;

{ TAdvChartToolBarControl }

constructor TAdvChartToolBarControl.Create;
begin
  FBitmap := TAdvChartBitmap.Create;
end;

destructor TAdvChartToolBarControl.Destroy;
begin 
  FBitmap.Free;
  inherited;
end;

{ TAdvChartCustomToolBarOptionsMenu }

procedure TAdvChartCustomToolBarOptionsMenu.Assign(Source: TPersistent);
begin
  if Source is TAdvChartCustomToolBarOptionsMenu then
  begin
    FShowItemText := (Source as TAdvChartCustomToolBarOptionsMenu).ShowItemText;
    FShowItemBitmap := (Source as TAdvChartCustomToolBarOptionsMenu).ShowItemBitmap;
    FShowButton := (Source as TAdvChartCustomToolBarOptionsMenu).ShowButton;
    FAutoItemBitmapWidth := (Source as TAdvChartCustomToolBarOptionsMenu).AutoItemBitmapWidth;
    FItemBitmapWidth := (Source as TAdvChartCustomToolBarOptionsMenu).ItemBitmapWidth;
  end;
end;

constructor TAdvChartCustomToolBarOptionsMenu.Create(
  AOwner: TAdvChartCustomToolBar);
begin
  FOwner := AOwner;
  FShowItemText := True;
  FShowButton := True;
  FShowItemBitmap := True;
  FAutoItemBitmapWidth := True;
  FItemBitmapWidth := 50;
end;

destructor TAdvChartCustomToolBarOptionsMenu.Destroy;
begin

  inherited;
end;

function TAdvChartCustomToolBarOptionsMenu.IsItemBitmapWidthStored: Boolean;
begin
  Result := ItemBitmapWidth <> 50;
end;

procedure TAdvChartCustomToolBarOptionsMenu.SetAutoItemBitmapWidth(
  const Value: Boolean);
begin
  if FAutoItemBitmapWidth <> Value then
  begin
    FAutoItemBitmapWidth := Value;
  end;
end;

procedure TAdvChartCustomToolBarOptionsMenu.SetItemBitmapWidth(
  const Value: Single);
begin
  if FItemBitmapWidth <> Value then
  begin
    FItemBitmapWidth := Value;
  end;
end;

procedure TAdvChartCustomToolBarOptionsMenu.SetShowButton(const Value: Boolean);
begin
  if FShowButton <> Value then
  begin
    FShowButton := Value;
    FOwner.FOptionsMenuButton.Visible := FShowButton;
    if FShowButton then
      FOwner.FOptionsMenuButton.Parent := FOwner
    else
      FOwner.FOptionsMenuButton.Parent := nil;

    FOwner.UpdateControls;
  end;
end;

procedure TAdvChartCustomToolBarOptionsMenu.SetShowItemBitmap(
  const Value: Boolean);
begin
  if FShowItemBitmap <> Value then
  begin
    FShowItemBitmap := Value;
  end;
end;

procedure TAdvChartCustomToolBarOptionsMenu.SetShowItemText(const Value: Boolean);
begin
  if FShowItemText <> Value then
  begin
    FShowItemText := Value;
  end;
end;

{ TAdvChartToolBarFontNamePicker }

constructor TAdvChartToolBarFontNamePicker.Create(AOwner: TComponent);
begin
  inherited;
  AutoOptionsMenuText := 'Font Name';
  TAdvChartUtils.GetFonts(FItems);
  {$IFDEF LCLLIB}
  FItems.Insert(0, 'Default');
  {$ENDIF}
end;

procedure TAdvChartToolBarFontNamePicker.DoItemSelected;
begin
  inherited;
  if Assigned(OnFontNameSelected) then
    OnFontNameSelected(Self, SelectedFontName);
end;

function TAdvChartToolBarFontNamePicker.GetSelectedFontName: String;
begin
  Result := GetSelectedItem;
end;

procedure TAdvChartToolBarFontNamePicker.SetSelectedFontName(const Value: String);
begin
  SelectedItem := Value;
end;

{ TAdvChartToolBarFontNamePicker }

constructor TAdvChartToolBarFontSizePicker.Create(AOwner: TComponent);
begin
  inherited;
  AutoOptionsMenuText := 'Font Size';
  FItems.Add('8');
  FItems.Add('9');
  FItems.Add('10');
  FItems.Add('11');
  FItems.Add('12');
  FItems.Add('14');
  FItems.Add('16');
  FItems.Add('18');
  FItems.Add('20');
  FItems.Add('22');
  FItems.Add('24');
  FItems.Add('26');
  FItems.Add('28');
  FItems.Add('36');
  FItems.Add('48');
  FItems.Add('72');
end;

procedure TAdvChartToolBarFontSizePicker.DoItemSelected;
begin
  inherited;
  if Assigned(OnFontSizeSelected) then
    OnFontSizeSelected(Self, SelectedFontSize);
end;

function TAdvChartToolBarFontSizePicker.GetSelectedFontSize: Single;
var
  s: String;
begin
  Result := -1;
  s := GetSelectedItem;
  if s <> '' then
    Result := StrToFloat(GetSelectedItem)
end;

procedure TAdvChartToolBarFontSizePicker.SetSelectedFontSize(const Value: Single);
begin
  SelectedItem := FloatToStr(Value);
end;

{ TAdvChartToolBarColorPicker }

function TAdvChartToolBarColorPicker.BlockChange: Boolean;
begin
  Result := FColorSelector.BlockChange;
end;

function TAdvChartToolBarColorPicker.CanChangeText: Boolean;
begin
  Result := not (csLoading in ComponentState) and not (csDesigning in ComponentState);
end;

procedure TAdvChartToolBarColorPicker.ColorSelected(Sender: TObject;
  AColor: TAdvChartGraphicsColor);
begin
  if CloseOnSelection and not BlockChange then
    CloseDropDown;
  DoColorSelected(AColor);
  Invalidate;
end;

function TAdvChartToolBarColorPicker.ColorSelector: TAdvChartColorSelector;
begin
  Result := FColorSelector;
end;

constructor TAdvChartToolBarColorPicker.Create(AOwner: TComponent);
begin
  inherited;
  Width := 40;
  Height := 24;
  AutoOptionsMenuText := 'Color';
  FColorSelector := TAdvChartColorSelector.Create(Self);
  FColorSelector.Appearance.HorizontalSpacing := 2;
  FColorSelector.Appearance.VerticalSpacing := 2;
  FColorSelector.Mode := csmExtended;
  FColorSelector.Width := 175;
  FColorSelector.Height := 125;
  FColorSelector.Stored := False;
  FColorSelector.SelectedColor := gcBlack;
  FColorSelector.OnColorSelected := ColorSelected;

  DropDownControl := FColorSelector;
  DropDownWidth := FColorSelector.Width;
  DropDownHeight := FColorSelector.Height;
  DropDownKind := ddkDropDownButton;
end;

procedure TAdvChartToolBarColorPicker.DoColorSelected(AColor: TAdvChartGraphicsColor);
begin
  if Assigned(OnColorSelected) then
    OnColorSelected(Self, AColor);
end;

procedure TAdvChartToolBarColorPicker.DrawColor(AColor: TAdvChartGraphicsColor;
  ARect: TRectF; AGraphics: TAdvChartGraphics);
var
  r: TRectF;
  I, J: Integer;
  st: TAdvChartGraphicsSaveState;
begin
  R := ARect;
  R.Inflate(-3.5, -3.5);
  R.Offset(0.5, 0.5);
  st := AGraphics.SaveState;
  try
    AGraphics.ClipRect(R);
    AGraphics.Stroke.Kind := gskNone;
    AGraphics.Fill.Kind := gfkSolid;
    AGraphics.Stroke.Width := 1;
    AGraphics.Fill.Color := MakeGraphicsColor(255, 255, 255);
    AGraphics.DrawRectangle(R);
    AGraphics.Fill.Color := MakeGraphicsColor(211 , 211 , 211 );
    for I := 0 to Trunc(R.Width / 5) + 1 do
      for J := 0 to Trunc(R.Height / 5) + 1 do
        if Odd(I + J) then
          AGraphics.DrawRectangle(RectF(I * 5, J * 5, (I + 1) * 5, (J + 1) * 5), gcrmNone);

    AGraphics.Fill.Kind := gfkSolid;
    AGraphics.Fill.Color := AColor;
    AGraphics.Stroke.Color := gcBlack;
    AGraphics.Stroke.Kind := gskSolid;
    AGraphics.DrawRectangle(R);
  finally
    AGraphics.RestoreState(st);
  end;
end;

procedure TAdvChartToolBarColorPicker.DrawSelectedColor(
  AGraphics: TAdvChartGraphics; ARect: TRectF);
var
  R: TRectF;
  c: TAdvChartGraphicsColor;
  ct: TAdvChartToolBarDropDownButton;
begin
  ct := GetDropDownButtonControl;
  if Assigned(ct) then
  begin
    R := RectF(0, 0, Width - ct.Width, Height);
    c := SelectedColor;
    DrawColor(c, r, AGraphics);
  end;
end;

function TAdvChartToolBarColorPicker.GetItems: TAdvChartColorSelectorItems;
begin
  Result := FColorSelector.Items;
end;

function TAdvChartToolBarColorPicker.GetSelectedColor: TAdvChartGraphicsColor;
begin
  Result := FColorSelector.SelectedColor;
end;

function TAdvChartToolBarColorPicker.GetSelectedItemIndex: Integer;
begin
  Result := FColorSelector.SelectedItemIndex;
end;

procedure TAdvChartToolBarColorPicker.Draw(AGraphics: TAdvChartGraphics; ARect: TRectF);
begin
  inherited;
  DrawSelectedColor(AGraphics, ARect);
end;

procedure TAdvChartToolBarColorPicker.SetAdaptToStyle(const Value: Boolean);
begin
  inherited;
  if Assigned(FColorSelector) then
    FColorSelector.AdaptToStyle := AdaptToStyle;
end;

procedure TAdvChartToolBarColorPicker.SetItems(
  const Value: TAdvChartColorSelectorItems);
begin
  FColorSelector.Items.Assign(Value);
end;

procedure TAdvChartToolBarColorPicker.SetSelectedColor(const Value: TAdvChartGraphicsColor);
begin
  FColorSelector.SelectedColor := Value;
  Invalidate;
end;

procedure TAdvChartToolBarColorPicker.SetSelectedItemIndex(const Value: Integer);
begin
  FColorSelector.SelectedItemIndex := Value;
  Invalidate;
end;

{ TAdvChartToolBarBitmapPicker }

function TAdvChartToolBarBitmapPicker.BitmapSelector: TAdvChartBitmapSelector;
begin
  Result := FBitmapSelector;
end;

function TAdvChartToolBarBitmapPicker.BlockChange: Boolean;
begin
  Result := FBitmapSelector.BlockChange;
end;

procedure TAdvChartToolBarBitmapPicker.BitmapSelected(Sender: TObject;
  ABitmap: TAdvChartBitmap);
begin
  Bitmaps.Clear;
  DisabledBitmaps.Clear;
  Bitmaps.AddBitmap(ABitmap);
  DisabledBitmaps.AddBitmap(ABitmap);

  if CloseOnSelection and not BlockChange then
    CloseDropDown;
  DoBitmapSelected(ABitmap);
end;

function TAdvChartToolBarBitmapPicker.CanChangeText: Boolean;
begin
  Result := not (csLoading in ComponentState) and not (csDesigning in ComponentState);
end;

constructor TAdvChartToolBarBitmapPicker.Create(AOwner: TComponent);
begin
  inherited;
  Width := 40;
  Height := 24;
  AutoOptionsMenuText := 'Bitmap';
  FBitmapSelector := TAdvChartBitmapSelector.Create(Self);
  FBitmapSelector.Appearance.HorizontalSpacing := 2;
  FBitmapSelector.Appearance.VerticalSpacing := 2;
  FBitmapSelector.Stored := False;
  FBitmapSelector.OnBitmapSelected := BitmapSelected;

  DropDownControl := FBitmapSelector;
  DropDownWidth := FBitmapSelector.Width;
  DropDownHeight := FBitmapSelector.Height;
  DropDownKind := ddkDropDownButton;
end;

procedure TAdvChartToolBarBitmapPicker.DoBitmapSelected(ABitmap: TAdvChartBitmap);
begin
  if Assigned(OnBitmapSelected) then
    OnBitmapSelected(Self, ABitmap);
end;

function TAdvChartToolBarBitmapPicker.GetBitmapRect: TRectF;
var
  r: TRectF;
  dr: TRectf;
begin
  r := LocalRect;
  Result := RectF(r.Left, r.Top, r.Right, r.Bottom);
  if BitmapVisible then
  begin
    if DropDownKind <> ddkNormal then
    begin
      dr := GetDropDownRect;
      case DropDownPosition of
        ddpRight: Result := RectF(Result.Left + 3, Result.Top + 3, dr.Left - 3, Result.Bottom - 3);
        ddpBottom: Result := RectF(Result.Left + 3, Result.Top + 3, Result.Right - 3, dr.Top - 3);
      end;
    end
    else
      Result := RectF(Result.Left + 3, Result.Top + 3, Result.Right - 3, Result.Bottom - 3);
  end;
end;

function TAdvChartToolBarBitmapPicker.GetItems: TAdvChartBitmapSelectorItems;
begin
  Result := FBitmapSelector.Items;
end;

function TAdvChartToolBarBitmapPicker.GetSelectedBitmap: TAdvChartBitmap;
begin
  Result := FBitmapSelector.SelectedBitmap;
end;

function TAdvChartToolBarBitmapPicker.GetSelectedItemIndex: Integer;
begin
  Result := FBitmapSelector.SelectedItemIndex;
end;

procedure TAdvChartToolBarBitmapPicker.SetAdaptToStyle(const Value: Boolean);
begin
  inherited;
  if Assigned(FBitmapSelector) then
    FBitmapSelector.AdaptToStyle := AdaptToStyle;
end;

procedure TAdvChartToolBarBitmapPicker.SetItems(
  const Value: TAdvChartBitmapSelectorItems);
begin
  FBitmapSelector.Items.Assign(Value);
end;

procedure TAdvChartToolBarBitmapPicker.SetSelectedItemIndex(const Value: Integer);
begin
  FBitmapSelector.SelectedItemIndex := Value;
  Bitmaps.Clear;
  DisabledBitmaps.Clear;
  Bitmaps.AddBitmap(SelectedBitmap);
  DisabledBitmaps.AddBitmap(SelectedBitmap);
  Invalidate;
end;

{ TAdvChartToolBarDropDownButton }

function TAdvChartToolBarDropDownButton.GetBitmapRect: TRectF;
var
  r: TRectF;
begin
  r := LocalRect;
  Result := RectF(r.Left + 3, r.Top + 3, r.Right - 3, r.Bottom - 3);
end;

{ TAdvChartToolBarCustomItemPicker }

function TAdvChartToolBarCustomItemPicker.CanChangeText: Boolean;
begin
  Result := not (csLoading in ComponentState) and not (csDesigning in ComponentState);
end;

constructor TAdvChartToolBarCustomItemPicker.Create(AOwner: TComponent);
begin
  inherited;
  FTimer := TTimer.Create(Self);
  FTimer.Interval := 1;
  FTimer.OnTimer := EnterTimerChanged;
  FTimer.Enabled := False;

  FEdit := TEdit.Create(Self);
  FEdit.TabStop := True;
  {$IFDEF FMXLIB}
  FEdit.Align := TAlignLayout.Client;
  FEdit.Stored := False;
  FEdit.OnChangeTracking := EditChange;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FEdit.Align := alClient;
  FEdit.OnChange := EditChange;
  {$ENDIF}

  Width := 100;
  Height := 24;
  HorizontalTextAlign := gtaLeading;
  FItemIndex := -1;

  FItemSelector := TListBox.Create(Self);
  FItemSelector.Width := 200;
  FItemSelector.Height := 150;
  {$IFDEF LCLLIB}
  FItemSelector.ClickOnSelChange := False;
  {$ENDIF}
  {$IFDEF FMXLIB}
  FItemSelector.Align := TAlignLayout.Client;
  FItemSelector.OnItemClick := ItemSelected;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FItemSelector.Align := alClient;
  FItemSelector.OnClick := ItemSelected;
  {$ENDIF}

  FItemSelector.OnKeyUp := ItemKeyUp;
  FItemSelector.OnKeyDown := ItemKeyDown;

  DropDownControl := FItemSelector;
  DropDownKind := ddkDropDownButton;
  DropDownWidth := FItemSelector.Width;
  DropDownHeight := FItemSelector.Height;

  FItems := TStringList.Create;
end;

destructor TAdvChartToolBarCustomItemPicker.Destroy;
begin
  FTimer.Free;
  FItems.Free;
  inherited;
end;

procedure TAdvChartToolBarCustomItemPicker.DoEnter;
begin
  inherited;
  FTimer.Enabled := Editable;
end;

procedure TAdvChartToolBarCustomItemPicker.DoItemSelected;
begin
  if Assigned(FEdit) {$IFDEF CMNLIB} and FEdit.HandleAllocated{$ENDIF} then
  begin
    FEdit.Text := SelectedItem;
    FEdit.SelStart := Length(FEdit.Text);
  end;

  if Assigned(OnItemSelected) then
    OnItemSelected(Self, SelectedItemIndex);
end;

procedure TAdvChartToolBarCustomItemPicker.Draw(AGraphics: TAdvChartGraphics;
  ARect: TRectF);
begin
  if not Editable then
    inherited;
end;

procedure TAdvChartToolBarCustomItemPicker.DropDown;
begin
  inherited;
  if FPopup.IsOpen and Assigned(FItemSelector) then
  begin
    FItemSelector.ItemIndex := -1;
    FItemSelector.ItemIndex := SelectedItemIndex;
  end;
end;

procedure TAdvChartToolBarCustomItemPicker.EditChange(Sender: TObject);
begin
  SelectedItem := FEdit.Text;
  if Assigned(OnEditChange) then
    OnEditChange(Self);
end;

procedure TAdvChartToolBarCustomItemPicker.EnterTimerChanged(Sender: TObject);
begin
  FEdit.SetFocus;
  FTimer.Enabled := False;
end;

function TAdvChartToolBarCustomItemPicker.GetSelectedItem: String;
begin
  Result := '';
  if (FItemIndex >= 0) and (FItemIndex <= FItems.Count - 1) then
    Result := FItems[FItemIndex]
end;

function TAdvChartToolBarCustomItemPicker.GetSelectedItemIndex: Integer;
begin
  Result := FItemIndex;
end;

function TAdvChartToolBarCustomItemPicker.GetText: String;
begin
  if Editable then
    Result := FEdit.Text
  else
    Result := SelectedItem;
end;

procedure TAdvChartToolBarCustomItemPicker.HandleDialogKey(var Key: Word;
  Shift: TShiftState);
begin
  inherited;
  if Shift <> [] then
    Exit;

  if Editable and FEdit.Focused then
  begin
    case Key of
      KEY_F4:
      begin
        if not (ssAlt in Shift) then
          DropDown;
      end;
    end;
  end;
end;

procedure TAdvChartToolBarCustomItemPicker.InitializePopup;
begin
  {$IFDEF FMXLIB}
  FItemSelector.BeginUpdate;
  {$ENDIF}
  FItemSelector.Items.Clear;
  FItemSelector.Items.Assign(FItems);
  FItemSelector.ItemIndex := FItemIndex;
  {$IFDEF FMXLIB}
  FItemSelector.EndUpdate;
  {$ENDIF}
end;

{$IFDEF FMXLIB}
procedure TAdvChartToolBarCustomItemPicker.ItemKeyDown(Sender: TObject; var Key: Word; var KeyChar: Char; Shift: TShiftState);
{$ENDIF}
{$IFDEF CMNLIB}
procedure TAdvChartToolBarCustomItemPicker.ItemKeyDown(Sender: TObject; var Key: Word; Shift: TShiftState);
{$ENDIF}
begin
  FKeyboardUsed := True;
end;

{$IFDEF FMXLIB}
procedure TAdvChartToolBarCustomItemPicker.ItemKeyUp(Sender: TObject; var Key: Word; var KeyChar: Char; Shift: TShiftState);
{$ENDIF}
{$IFDEF CMNLIB}
procedure TAdvChartToolBarCustomItemPicker.ItemKeyUp(Sender: TObject; var Key: Word; Shift: TShiftState);
{$ENDIF}
begin
  if (Key = KEY_RETURN) or (Key = KEY_SPACE) then
  begin
    if CloseOnSelection then
      DropDown;

    FItemIndex := FItemSelector.ItemIndex;
    DoItemSelected;
    Invalidate;
  end;

  FKeyBoardUsed := False;
end;

{$IFDEF FMXLIB}
procedure TAdvChartToolBarCustomItemPicker.ItemSelected(const Sender: TCustomListBox; const Item: TListBoxItem);
{$ENDIF}
{$IFDEF CMNLIB}
procedure TAdvChartToolBarCustomItemPicker.ItemSelected(Sender: TObject);
{$ENDIF}
begin
  if FKeyBoardUsed then
    Exit;

  if CloseOnSelection then
    DropDown;

  FItemIndex := FItemSelector.ItemIndex;
  DoItemSelected;
  Invalidate;
end;

procedure TAdvChartToolBarCustomItemPicker.SelectFirstValue;
begin
  inherited;
  FItemIndex := 0;
  DoItemSelected;
  Invalidate;
end;

procedure TAdvChartToolBarCustomItemPicker.SelectLastValue;
begin
  inherited;
  FItemIndex := FItems.Count - 1;
  DoItemSelected;
  Invalidate;
end;

procedure TAdvChartToolBarCustomItemPicker.SelectNextValue;
begin
  inherited;
  if FItemIndex = -1 then
    FItemIndex := 0
  else
    FItemIndex := Min(FItems.Count - 1, FItemIndex + 1);

  DoItemSelected;
  Invalidate;
end;

procedure TAdvChartToolBarCustomItemPicker.SelectPreviousValue;
begin
  inherited;
  if FItemIndex = -1 then
    FItemIndex := 0
  else
    FItemIndex := Max(0, FItemIndex - 1);

  DoItemSelected;
  Invalidate;
end;

procedure TAdvChartToolBarCustomItemPicker.SelectValueWithCharacter(
  ACharacter: Char);
var
  I: Integer;
begin
  inherited;
  for I := 0 to Items.Count - 1 do
  begin
    if TAdvChartUtils.MatchStrEx(ACharacter + '*', Items[I], False) then
    begin
      FItemIndex := I;
      DoItemSelected;
      Invalidate;
      Break;
    end;
  end;
end;

procedure TAdvChartToolBarCustomItemPicker.SelectValueWithString(AValue: string);
var
  I: Integer;
begin
  inherited;
  for I := 0 to Items.Count - 1 do
  begin
    if TAdvChartUtils.MatchStrEx(AValue + '*', Items[I], False) then
    begin
      FItemIndex := I;
      DoItemSelected;
      Invalidate;
      Break;
    end;
  end;
end;

procedure TAdvChartToolBarCustomItemPicker.SetEditable(const Value: Boolean);
begin
  if FEditable <> Value then
  begin
    FEditable := Value;
    if Assigned(FEdit) then
    begin
      if FEditable then
      begin
        FEdit.Parent := Self;
      end
      else
        FEdit.Parent := nil;

      FEdit.Visible := FEditable;
    end;
    Invalidate;
  end;
end;

procedure TAdvChartToolBarCustomItemPicker.SetItems(const Value: TStringList);
begin
  FItems.Assign(Value);
end;

procedure TAdvChartToolBarCustomItemPicker.SetSelectedItem(const Value: String);
begin
  FItemIndex := FItems.IndexOf(Value);
  Invalidate;
end;

procedure TAdvChartToolBarCustomItemPicker.SetSelectedItemIndex(
  const Value: Integer);
begin
  FItemIndex := Value;
  Invalidate;
end;

initialization
  RegisterClass(TAdvChartToolBarButton);

end.
