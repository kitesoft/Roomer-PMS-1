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

unit dxRibbon;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Windows, Forms, Messages, Classes, SysUtils, Graphics, Controls, ExtCtrls, ImgList, IniFiles, Contnrs,
  dxCore, dxCoreClasses, dxMessages, cxClasses, cxGraphics, dxTouch, cxControls, dxBar, cxContainer, cxLookAndFeels,
  dxScreenTip, dxBarSkin, dxFading, cxAccessibility, dxBarAccessibility, cxLookAndFeelPainters, dxRibbonSkins,
  dxRibbonForm, dxRibbonFormCaptionHelper, dxBarApplicationMenu, dxShadowWindow, cxScrollBar;

const
  dxRibbonHintOffset                  = 20;
  dxRibbonFormCaptionMinWidth         = 50;
  dxRibbonFormContextsMinWidth        = 8;
  dxRibbonFormCaptionTextSpace        = 4;
  dxRibbonTabIndent                   = 17;
  dxRibbonTabMinWidth                 = 28;
  dxRibbonTabTextOffset               = 5;
  dxRibbonOptimalTabSpace             = dxRibbonTabTextOffset * 2 + dxRibbonTabIndent;
  dxRibbonTabSeparatorVisibilityLimit = dxRibbonTabMinWidth div 2;
  dxRibbonOwnerMinimalWidth: Integer  = 300;
  dxRibbonOwnerMinimalHeight: Integer = 250;
  dxRibbonScrollDelay                 = 400;
  dxRibbonScrollInterval              = 20;
  dxRibbonTabGroupsPopupWindowShowAnimationTime: Integer = 230;
  dxRibbonTabGroupsPopupWindowHideAnimationTime: Integer = 100;

  dxRibbonGroupRowCount = 3;

type
  TdxRibbonMergeOption = (rmoCanCreateNewTab, rmoCanCreateNewGroup, rmoCanCreateQATToolbar);
  TdxRibbonMergeOptions = set of TdxRibbonMergeOption;

  TdxRibbonPopupMenuItem = (rpmiItems, rpmiMoreCommands, rpmiQATPosition, rpmiQATAddRemoveItem, rpmiMinimizeRibbon);
  TdxRibbonPopupMenuItems = set of TdxRibbonPopupMenuItem;

const
  dxRibbonDefaultMergeOptions = [rmoCanCreateNewTab, rmoCanCreateNewGroup, rmoCanCreateQATToolbar];
  dxRibbonDefaultPopupMenuItems = [rpmiItems, rpmiMoreCommands, rpmiQATPosition, rpmiQATAddRemoveItem, rpmiMinimizeRibbon];

type
  TdxBarApplicationMenu = class;
  TdxCustomRibbon = class;
  TdxRibbonApplicationButton = class;
  TdxRibbonGroupBarControl = class;
  TdxRibbonGroupBarControlViewInfo = class;
  TdxRibbonGroupsDockControl = class;
  TdxRibbonGroupsDockControlSite = class;
  TdxRibbonGroupsDockControlSiteViewInfo = class;
  TdxRibbonGroupsDockControlViewInfo = class;
  TdxRibbonGroupsDockControlViewInfoClass = class of TdxRibbonGroupsDockControlViewInfo;
  TdxRibbonHelpButton = class;
  TdxRibbonQuickAccessBarControlViewInfo = class;
  TdxRibbonQuickAccessDockControl = class;
  TdxRibbonQuickAccessGroupButton = class;
  TdxRibbonQuickAccessToolbar = class;
  TdxRibbonTab = class;
  TdxRibbonCollapsedGroupPopupBarControl = class;
  TdxRibbonTabGroup = class;
  TdxRibbonTabPainterClass = class of TdxRibbonTabPainter;
  TdxRibbonTabViewInfo = class;
  TdxRibbonViewInfo = class;
  TdxRibbonContext = class;
  TdxRibbonContexts = class;
  TdxRibbonController = class;
  TdxRibbonContextsViewInfo = class;
  TdxRibbonCustomButtonViewInfo = class;
  TdxRibbonButtonsContainerViewInfo = class;

  TdxRibbonApplicationMenuDisplayMode = (amdmPopup, amdmFrame, amdmFrameFullScreen);
  TdxRibbonMergeKind = (rmkMerge, rmkAdd, rmkNone);

  TdxRibbonScrollButton = (rsbLeft, rsbRight);
  TdxRibbonScrollButtons = set of TdxRibbonScrollButton;

  { IdxRibbonApplicationMenu }

  IdxRibbonApplicationMenu = interface
  ['{DF34053B-F30D-4FC6-94D5-5863620E8F28}']
    function CanShowPopup(ARibbon: TdxCustomRibbon): Boolean;
    function ClosePopup: Boolean;
    function GetDisplayMode: TdxRibbonApplicationMenuDisplayMode;
    function GetOrigin(AIsClientArea: Boolean): TPoint;
    function GetRootAccessibilityHelper: IdxBarAccessibilityHelper;
    procedure GetTabOrderList(List: TList);
    function Popup(ARibbon: TdxCustomRibbon; var AClosedByEscape: Boolean): Boolean;
    procedure RibbonFormResized;
    procedure SelectAppMenuFirstItemControl;
    procedure ShowKeyTips;
    procedure UpdateNonClientArea;
  end;

  { IdxRibbonListener }

  IdxRibbonListener = interface
  ['{E3CD1F8D-4F7F-4448-A877-28726BDDD97F}']
    procedure AfterBarManagerChange;
    procedure BeforeBarManagerChange;
  end;

  { IdxRibbonMouseWheelReceiver }

  IdxRibbonMouseWheelReceiver = interface
  ['{A5D2167B-0343-4525-915F-D41B49832045}']
    function CanProcessMouseWheel: Boolean;
    function DoMouseWheel(Shift: TShiftState; WheelDelta: Integer; MousePos: TPoint): Boolean;
  end;

  { IdxRibbonToolbarContainer }

  IdxRibbonToolbarContainer = interface
  ['{4C6EF60C-C784-44B7-A40E-382ADDB36F61}']
    function GetRibbon: TdxCustomRibbon;
    function GetToolbar: TdxBar;
    procedure SetToolbar(AValue: TdxBar);
    //
    property Ribbon: TdxCustomRibbon read GetRibbon;
    property Toolbar: TdxBar read GetToolbar write SetToolbar;
  end;

  { IdxRibbonFormNonClientDraw }

  IdxRibbonFormNonClientDraw = interface
  ['{0A28260B-C352-4704-A88B-44DD8461955C}']
    procedure Add(AObject: TObject);
    procedure Remove(AObject: TObject);
  end;

  { IdxRibbonFormStatusBar }

  IdxRibbonFormStatusBar = interface
  ['{E6AA56DF-B87A-4D98-98CF-B41BA751594D}']
    function GetActive(AForm: TCustomForm): Boolean;
    function GetControl: TWinControl;
    function GetHeight: Integer;
    function GetIsRaised(ALeft: Boolean): Boolean;
  end;

  { TdxRibbonCustomMergeData }

  TdxRibbonCustomMergeData = class(TdxBarCustomMergeData)
  private
    FChildren: TcxComponentList;
    procedure ListChangeHandler(Sender: TObject; AComponent: TComponent; AAction: TListNotification);
  protected
    procedure FreeNotification(Sender: TComponent); override;
  public
    constructor Create; override;
    destructor Destroy; override;
    //
    property Children: TcxComponentList read FChildren;
  end;

  { TdxCustomDesignSelectionHelper }

  TdxCustomDesignSelectionHelper = class(TInterfacedObject, IdxBarSelectableItem)
  private
    FComponent: TComponent;
    FOwner: TPersistent;
    FParent: TPersistent;
  protected
    //IdxBarSelectableItem
    function CanDelete(ADestruction: Boolean = False): Boolean;
    procedure DeleteSelection(var AReference: IdxBarSelectableItem; ADestruction: Boolean);
    procedure ExecuteCustomizationAction(ABasicAction: TdxBarCustomizationAction);
    function GetBarManager: TdxBarManager; virtual;
    function GetInstance: TPersistent;
    procedure GetMasterObjects(AList: TdxObjectList);
    function GetNextSelectableItem: IdxBarSelectableItem;
    function GetSelectableParent: TPersistent;
    function GetSelectionStatus: TdxBarSelectionStatus;
    function GetSupportedActions: TdxBarCustomizationActions;
    procedure Invalidate; virtual;
    function IsComplex: Boolean;
    function IsComponentSelected: Boolean;
    procedure SelectComponent(ASelectionOperation: TdxBarSelectionOperation = soExclusive);
    function SelectParentComponent: Boolean;
    procedure SelectionChanged;
    //
    property BarManager: TdxBarManager read GetBarManager;
    property Component: TComponent read FComponent;
    property Owner: TPersistent read FOwner;
    property Parent: TPersistent read FParent;
  public
    constructor Create(AComponent: TComponent; AOwner, AParent: TPersistent);
  end;

  { TdxDesignSelectionHelper }

  TdxDesignSelectionHelper = class(TdxCustomDesignSelectionHelper)
  protected
    function GetBarManager: TdxBarManager; override;
    function GetRibbon: TdxCustomRibbon;
    procedure Invalidate; override;
    //
    property Ribbon: TdxCustomRibbon read GetRibbon;
  end;

  { TdxRibbonTabPainter }

  TdxRibbonTabPainter = class(TObject)
  private
    FRibbon: TdxCustomRibbon;
    function GetColorScheme: TdxCustomRibbonSkin;
  protected
    procedure DrawBackground(ACanvas: TcxCanvas; const ABounds: TRect; AState: TdxRibbonTabState); virtual;
    procedure DrawContextTabBackground(ACanvas: TcxCanvas; AColor: TColor;
      const ABounds: TRect; AState: TdxRibbonTabState); virtual;
    procedure DrawContextTabSeparator(ACanvas: TcxCanvas; const ABounds: TRect; ABeginGroup: Boolean); virtual;
    procedure DrawTabSeparator(ACanvas: TcxCanvas; const ABounds: TRect; Alpha: Byte); virtual;
    procedure DrawText(ACanvas: TcxCanvas; const ABounds: TRect;
      const AText: string; AHasSeparator, AIsPaintOnGlass: Boolean); virtual;
  public
    constructor Create(ARibbon: TdxCustomRibbon);
    //
    property ColorScheme: TdxCustomRibbonSkin read GetColorScheme;
    property Ribbon: TdxCustomRibbon read FRibbon;
  end;

  { TdxRibbonPainter }

  TdxRibbonPainter = class(TObject)
  private
    FRibbon: TdxCustomRibbon;
    function GetColorScheme: TdxCustomRibbonSkin;
    function GetColorSchemeAccent: TdxRibbonColorSchemeAccent;
    function GetFormIconHandle: HICON;
    function GetIsFormZoomed: Boolean;
    function GetViewInfo: TdxRibbonViewInfo;
  protected
    procedure DrawEmptyRibbon(ACanvas: TcxCanvas);
  public
    constructor Create(ARibbon: TdxCustomRibbon); virtual;
    procedure AdjustContextFont(AFont: TFont; AContextColor: TColor);

    function GetGroupCaptionBottomOffset: Integer; virtual;
    function GetRibbonFormInfo(const AData: TdxRibbonFormData): TdxRibbonFormInfo;

    //non-client routines
    procedure DrawRibbonFormCaption(ACanvas: TcxCanvas; const ABounds: TRect;
      const AData: TdxRibbonFormData); virtual;
    procedure DrawRibbonFormCaptionFrameArea(ACanvas: TcxCanvas;
      R: TRect; const AData: TdxRibbonFormData); virtual;
    procedure DrawRibbonFormBorderIcon(ACanvas: TcxCanvas; const ABounds: TRect;
      AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState); virtual;
    procedure DrawRibbonFormBorders(ACanvas: TcxCanvas;
      const ABordersWidth: TRect; const AData: TdxRibbonFormData); virtual;
    //client routines
    procedure DrawApplicationButton(ACanvas: TcxCanvas; const ABounds: TRect; AState: TdxRibbonApplicationButtonState); virtual;
    procedure DrawApplicationButtonGlyph(ACanvas: TcxCanvas; const ABounds: TRect; AGlyph: TBitmap); virtual;
    procedure DrawBackground(ACanvas: TcxCanvas; const ABounds: TRect); virtual;
    procedure DrawContextBackground(ACanvas: TcxCanvas; const ABounds: TRect; AColor: TColor); virtual;
    procedure DrawContextBackgroundGlass(ACanvas: TcxCanvas; const ABounds: TRect; AColor: TColor); virtual;
    procedure DrawContextGroupsArea(ACanvas: TcxCanvas; const ABounds: TRect; AIsQATAtBottom, AIsInPopup: Boolean); virtual;
    procedure DrawFormDefaultIcon(ACanvas: TcxCanvas; const ABounds: TRect);
    procedure DrawGlyph(ACanvas: TcxCanvas; AGlyph: TBitmap; const ABounds: TRect); virtual;
    procedure DrawGlowingText(DC: HDC; const AText: string;
      AFont: TFont; const ABounds: TRect; AColor: TColor; AFlags: DWORD; ATransparent: Boolean = False);
    procedure DrawGroupsArea(ACanvas: TcxCanvas; const ABounds: TRect;
      AIsAllowContextPaint: Boolean = True; AIsInPopup: Boolean = False); virtual;
    procedure DrawGroupsScrollButton(ACanvas: TcxCanvas; const ABounds: TRect; ALeft: Boolean; AState: TcxButtonState); virtual;
    procedure DrawGroupsScrollButtonArrow(ACanvas: TcxCanvas; const ABounds: TRect; ALeft: Boolean); virtual;
    procedure DrawRibbonFormCaptionText(ACanvas: TcxCanvas; const ABounds: TRect;
      const ADocumentName, ACaption: string; const AData: TdxRibbonFormData); virtual;
    procedure DrawRibbonGlassFormCaptionText(ACanvas: TcxCanvas; const ABounds: TRect;
      const ADocumentName, ACaption: string; AIsActive: Boolean); virtual;
    procedure DrawRibbonTopFrameAreaSeparator(ACanvas: TcxCanvas); virtual;
    procedure DrawQuickAccessToolbar(ACanvas: TcxCanvas; const ABounds: TRect; AIsActive: Boolean); virtual;
    procedure DrawTabAreaBackground(ACanvas: TcxCanvas; const ABounds: TRect); virtual;
    procedure DrawTabScrollButton(ACanvas: TcxCanvas; const ABounds: TRect;
      ALeft: Boolean; AState: TcxButtonState); virtual;
    procedure DrawTabScrollButtonGlyph(ACanvas: TcxCanvas;
      const ABounds: TRect; ALeft: Boolean); virtual;
    procedure DrawHelpButton(ACanvas: TcxCanvas; const ABounds: TRect; AState: TcxButtonState); virtual;
    procedure DrawHelpButtonGlyph(ACanvas: TcxCanvas; AGlyph: TBitmap; const ABounds: TRect; AState: TcxButtonState); virtual;
    procedure DrawMDIButton(ACanvas: TcxCanvas; const ABounds: TRect;
      AButton: TdxBarMDIButton; AState: TcxButtonState); virtual;
    procedure DrawMDIButtonGlyph(ACanvas: TcxCanvas; const ABounds: TRect;
      AButton: TdxBarMDIButton; AState: TcxButtonState); virtual;
    procedure DrawMinimizeButton(ACanvas: TcxCanvas;
      const ABounds: TRect; AState: TcxButtonState; AMinimized: Boolean);
    procedure DrawMinimizeButtonGlyph(ACanvas: TcxCanvas; const R: TRect;
      AState: TcxButtonState; AGlyph: TdxRibbonMinimizeButtonGlyph);

    property ColorScheme: TdxCustomRibbonSkin read GetColorScheme;
    property ColorSchemeAccent: TdxRibbonColorSchemeAccent read GetColorSchemeAccent;
    property IsFormZoomed: Boolean read GetIsFormZoomed;
    property Ribbon: TdxCustomRibbon read FRibbon;
    property ViewInfo: TdxRibbonViewInfo read GetViewInfo;
  end;

  { TdxRibbonHitInfo }

  TdxRibbonHitTest = (rhtNone, rhtTab, rhtApplicationMenu, rhtContext, rhtTabScrollLeft, rhtTabScrollRight,
    rhtGroupScrollLeft, rhtGroupScrollRight, rhtHelpButton, rhtCustomButton, rhtFormButton); //keep order

  TdxRibbonHitInfo = class
  private
    FOwner: TdxRibbonViewInfo;
    FHitTest: TdxRibbonHitTest;
    FHitObject: TObject;
    FHitPoint: TPoint;
    function GetHitObjectAsButton: TdxRibbonCustomButtonViewInfo;
    function GetHitObjectAsContext: TdxRibbonContext;
    function GetHitObjectAsTab: TdxRibbonTab;
  public
    constructor Create(AOwner: TdxRibbonViewInfo); virtual;
    procedure Calculate(const P: TPoint); virtual;
    function Compare(const AHitTest: TdxRibbonHitInfo): Boolean;
    procedure Reset; virtual;
    //
    property HitObject: TObject read FHitObject write FHitObject;
    property HitObjectAsButton: TdxRibbonCustomButtonViewInfo read GetHitObjectAsButton;
    property HitObjectAsContext: TdxRibbonContext read GetHitObjectAsContext;
    property HitObjectAsTab: TdxRibbonTab read GetHitObjectAsTab;
    property HitPoint: TPoint read FHitPoint write Calculate;
    property HitTest: TdxRibbonHitTest read FHitTest write FHitTest;
    property Owner: TdxRibbonViewInfo read FOwner;
  end;

  { TdxRibbonCustomViewInfo }

  TdxRibbonCustomViewInfo = class(TcxIUnknownObject)
  private
    FOwner: TdxRibbonViewInfo;
    function GetRibbon: TdxCustomRibbon;
  protected
    FBounds: TRect;
  public
    constructor Create(AOwner: TdxRibbonViewInfo); virtual;
    procedure Calculate(const ABounds: TRect); virtual;
    procedure Draw(ACanvas: TcxCanvas); virtual; abstract;
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; virtual;
    procedure Invalidate;
    procedure InvalidateRect(const R: TRect); virtual;
    //
    property Bounds: TRect read FBounds;
    property Owner: TdxRibbonViewInfo read FOwner;
    property Ribbon: TdxCustomRibbon read GetRibbon;
  end;

  { TdxRibbonCustomContainerViewInfo }

  TdxRibbonCustomContainerViewInfo = class(TdxRibbonCustomViewInfo)
  private
    FCells: TcxObjectList;
    function GetCount: Integer;
    function GetItem(Index: Integer): TObject;
  public
    constructor Create(AOwner: TdxRibbonViewInfo); override;
    destructor Destroy; override;
    function AddItem(AObject: TObject): Integer;
    procedure Clear;
    //
    property Count: Integer read GetCount;
    property Items[Index: Integer]: TObject read GetItem; default;
  end;

  { TdxRibbonCustomButtonAccessibilityHelper }

  TdxRibbonCustomButtonAccessibilityHelper = class(TdxBarAccessibilityHelper)
  private
    FButtonViewInfo: TdxRibbonCustomButtonViewInfo;
    function GetRibbon: TdxCustomRibbon;
  protected
    // IdxBarAccessibilityHelper
    function GetBarManager: TdxBarManager; override;
    function GetNextAccessibleObject(
      ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper; override;
    function HandleNavigationKey(var AKey: Word): Boolean; override;
    function IsNavigationKey(AKey: Word): Boolean; override;
    procedure Select(ASetFocus: Boolean); override;
    procedure Unselect(ANextSelectedObject: IdxBarAccessibilityHelper); override;

    function GetOwnerObjectWindow: HWND; override;
    function GetParent: TcxAccessibilityHelper; override;
    function GetSelectable: Boolean; override;
    function GetState(AChildID: TcxAccessibleSimpleChildElementID): Integer; override;

    function GetAssignedKeyTip: string; override;
    function GetDefaultKeyTip: string; override;
    procedure GetKeyTipData(AKeyTipsData: TList); override;

    property ButtonViewInfo: TdxRibbonCustomButtonViewInfo read FButtonViewInfo;
    property Ribbon: TdxCustomRibbon read GetRibbon;
  public
    constructor CreateEx(AButtonViewInfo: TdxRibbonCustomButtonViewInfo); virtual;
    function GetScreenBounds(AChildID: TcxAccessibleSimpleChildElementID): TRect; override;
  end;

  { TdxRibbonCustomButtonViewInfo }

  TdxRibbonCustomButtonViewInfo = class(TcxIUnknownObject, IdxFadingObject, IdxFadingObjectFadingOptions)
  private
    FAccessibilityHelper: IdxBarAccessibilityHelper;
    FBounds: TRect;
    FOwner: TdxRibbonCustomContainerViewInfo;
    FState: TcxButtonState;
    function GetAccessibilityHelper: IdxBarAccessibilityHelper;
    function GetPainter: TdxRibbonPainter;
    function GetRibbon: TdxCustomRibbon;
    function GetState: TcxButtonState;
    function GetViewInfo: TdxRibbonViewInfo;
    procedure SetState(AValue: TcxButtonState);
  protected
    function CreateAccessibilityHelper: TdxRibbonCustomButtonAccessibilityHelper; virtual;
    function GetHint: string; virtual;
    function GetIsEnabled: Boolean; virtual;
    procedure CalculateState; virtual;
    procedure DrawButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); virtual;
    procedure DrawButtonGlyph(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); virtual;
    // IdxFadingObject
    function CanFade: Boolean;
    procedure DrawFadeImage;
    procedure GetFadingImages(out AFadeOutImage, AFadeInImage: TcxBitmap);
    // IdxFadingObjectFadingOptions
    function GetFadingOptions: TdxFadingOptions;
  public
    constructor Create(AOwner: TdxRibbonCustomContainerViewInfo); virtual;
    destructor Destroy; override;
    procedure Click; virtual;
    procedure Draw(ACanvas: TcxCanvas); virtual;
    procedure Invalidate;
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; virtual;
    //
    property AccessibilityHelper: IdxBarAccessibilityHelper read GetAccessibilityHelper;
    property Bounds: TRect read FBounds write FBounds;
    property Enabled: Boolean read GetIsEnabled;
    property Hint: string read GetHint;
    property Owner: TdxRibbonCustomContainerViewInfo read FOwner;
    property Painter: TdxRibbonPainter read GetPainter;
    property Ribbon: TdxCustomRibbon read GetRibbon;
    property State: TcxButtonState read GetState write SetState;
    property ViewInfo: TdxRibbonViewInfo read GetViewInfo;
  end;

  { TdxRibbonCustomScrollButtonViewInfo }

  TdxRibbonCustomScrollButtonViewInfo = class(TdxRibbonCustomButtonViewInfo)
  protected
    FScrollButton: TdxRibbonScrollButton;
  end;

  { TdxRibbonTabViewInfo }

  TdxRibbonTabViewInfoClass = class of TdxRibbonTabViewInfo;

  TdxRibbonTabViewInfo = class(TObject)
  private
    FPainter: TdxRibbonTabPainter;
    FTab: TdxRibbonTab;
    function GetCanvas: TcxCanvas;
    function GetContextTabSeparatorWidth: Integer;
    function GetFont: TFont;
    function GetIsPaintOnGlass: Boolean;
    function GetIsTabActive: Boolean;
    function GetRibbon: TdxCustomRibbon;
  protected
    FCanHasSeparator: Boolean;
    FContextBegin: Boolean;
    FContextEnd: Boolean;
    FMinWidth: Integer;
    FOptimalWidth: Integer;
    FSeparatorAlphaValue: Integer;
    FSeparatorBounds: TRect;
    FTextBounds: TRect;
    FTextWidth: Integer;
    FWidth: Integer;
    procedure CalculateWidths(AViewInfo: TdxRibbonViewInfo); virtual;
    procedure DrawBackground(ACanvas: TcxCanvas; const R: TRect; AState: TdxRibbonTabState);
    function GetTextBounds: TRect; virtual;
    function GetSeparatorBounds: TRect; virtual;
    function GetState: TdxRibbonTabState; virtual;
    function GetPainterClass: TdxRibbonTabPainterClass; virtual;
    function IsSelected: Boolean;
    function PrepareFadeImage(ADrawHot: Boolean): TcxBitmap;

    property Canvas: TcxCanvas read GetCanvas;
    property ContextTabSeparatorWidth: Integer read GetContextTabSeparatorWidth;
    property IsPaintOnGlass: Boolean read GetIsPaintOnGlass;
    property IsTabActive: Boolean read GetIsTabActive;
    property Painter: TdxRibbonTabPainter read FPainter;
    property Ribbon: TdxCustomRibbon read GetRibbon;
    property Width: Integer read FWidth;
  public
    Bounds: TRect;
    constructor Create(ATab: TdxRibbonTab); virtual;
    destructor Destroy; override;
    procedure Calculate(const ABounds: TRect; ASeparatorAlpha: Byte); virtual;
    function HasSeparator: Boolean;
    procedure Paint(ACanvas: TcxCanvas);

    property ContextBegin: Boolean read FContextBegin write FContextBegin;
    property ContextEnd: Boolean read FContextEnd write FContextEnd;
    property Font: TFont read GetFont;
    property MinWidth: Integer read FMinWidth;
    property OptimalWidth: Integer read FOptimalWidth;
    property SeparatorAlphaValue: Integer read FSeparatorAlphaValue;
    property SeparatorBounds: TRect read FSeparatorBounds;
    property State: TdxRibbonTabState read GetState;
    property Tab: TdxRibbonTab read FTab;
    property TextBounds: TRect read FTextBounds;
    property TextWidth: Integer read FTextWidth;
  end;

  { TdxRibbonTabsScrollButtonViewInfo }

  TdxRibbonTabsScrollButtonViewInfo = class(TdxRibbonCustomScrollButtonViewInfo)
  protected
    procedure DrawButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    procedure DrawButtonGlyph(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
  public
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; override;
  end;

  { TdxRibbonTabsViewInfo }

  TdxRibbonTabsViewInfo = class(TdxRibbonCustomContainerViewInfo)
  private
    FBitmap: TcxBitmap32;
    FHasButtonOnRight: Boolean;
    FNeedShowHint: Boolean;
    FScrollButtonLeft: TdxRibbonTabsScrollButtonViewInfo;
    FScrollButtonRight: TdxRibbonTabsScrollButtonViewInfo;
    FScrollButtons: TdxRibbonScrollButtons;
    FScrollPosition: Integer;
    FScrollWidth: Integer;
    FSeparatorAlpha: Byte;
    FTotalMinimalWidth: Integer;
    FTotalOptimalWidth: Integer;
    procedure CalculateScrollButtons;
    procedure CheckScrollPosition(var Value: Integer);
    function GetController: TdxRibbonController;
    function GetLongestTabWidth: Integer;
    function GetPainter: TdxRibbonPainter;
    function GetRealMinItemWidth(Index: Integer): Integer;
    function GetScrollWidth: Integer;
    function GetTabViewInfo(Index: Integer): TdxRibbonTabViewInfo;
    procedure RemoveScrolling;
    procedure SetScrollPosition(Value: Integer);
  protected
    procedure BalancedReduce(ATotalDelta: Integer);
    procedure CalculateComplexTabLayout; virtual;
    procedure CalculateSimpleTabLayout; virtual;
    procedure CalculateScrollingTabLayout; virtual;
    procedure CreateContextualTabsViewInfoCells; virtual;
    procedure CreateTabsViewInfoCells; virtual;
    procedure SimpleReduce(ATotalDelta: Integer);

    property Controller: TdxRibbonController read GetController;
  public
    constructor Create(AOwner: TdxRibbonViewInfo); override;
    destructor Destroy; override;
    procedure Calculate(const ABounds: TRect); override;
    procedure Draw(ACanvas: TcxCanvas); override;
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; override;
    function GetRealBounds: TRect;
    function Last: TdxRibbonTabViewInfo;
    procedure MakeTabVisible(ATab: TdxRibbonTab);
    procedure RecreateViewInfoCells;
    procedure UpdateButtonsStates;
    procedure UpdateDockControls;

    property Bitmap: TcxBitmap32 read FBitmap;
    property Items[Index: Integer]: TdxRibbonTabViewInfo read GetTabViewInfo; default;
    property NeedShowHint: Boolean read FNeedShowHint;
    property Painter: TdxRibbonPainter read GetPainter;
    property ScrollButtons: TdxRibbonScrollButtons read FScrollButtons;
    property ScrollPosition: Integer read FScrollPosition write SetScrollPosition;
  end;

  { TdxRibbonHelpButtonViewInfo }

  TdxRibbonHelpButtonViewInfo = class(TdxRibbonCustomButtonViewInfo)
  private
    function GetHelpButton: TdxRibbonHelpButton;
    function GetGlyphBounds: TRect;
  protected
    function GetIsEnabled: Boolean; override;
    procedure DrawButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    procedure DrawButtonGlyph(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
  public
    procedure Click; override;
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; override;

    property HelpButton: TdxRibbonHelpButton read GetHelpButton;
    property GlyphBounds: TRect read GetGlyphBounds;
  end;

  { TdxRibbonMinimizeButtonViewInfo }

  TdxRibbonMinimizeButtonViewInfo = class(TdxRibbonCustomButtonViewInfo)
  private
    function GetRibbon: TdxCustomRibbon;
    function GetState: TdxRibbonMinimizeButtonGlyph;
  protected
    procedure DrawButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    procedure DrawButtonGlyph(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    function GetHint: string; override;
  public
    procedure Click; override;
    //
    property Ribbon: TdxCustomRibbon read GetRibbon;
    property State: TdxRibbonMinimizeButtonGlyph read GetState;
  end;

  { TdxRibbonMDIButtonViewInfo }

  TdxRibbonMDIButtonViewInfo = class(TdxRibbonCustomButtonViewInfo)
  protected
    FButtonType: TdxBarMDIButton;
    function GetHint: string; override;
    function GetIsEnabled: Boolean; override;
    procedure DrawButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    procedure DrawButtonGlyph(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
  public
    procedure Click; override;
    //
    property ButtonType: TdxBarMDIButton read FButtonType;
  end;

  { TdxRibbonButtonsContainerViewInfo }

  TdxRibbonButtonsContainerViewInfo = class(TdxRibbonCustomContainerViewInfo)
  private
    function GetItem(Index: Integer): TdxRibbonCustomButtonViewInfo;
    function GetSelectedButton: TdxRibbonCustomButtonViewInfo;
  protected
    procedure CalculateButtonsBounds(const ABounds: TRect); virtual; abstract;
    procedure CalculateButtonsStates;
    procedure RecreateButtonsViewInfo; virtual;
  public
    procedure Calculate(const ABounds: TRect); override;
    procedure Draw(ACanvas: TcxCanvas); override;
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; override;
    //
    property SelectedButton: TdxRibbonCustomButtonViewInfo read GetSelectedButton;
    property Items[Index: Integer]: TdxRibbonCustomButtonViewInfo read GetItem; default;
  end;

  { TdxRibbonTabsAreaButtonsViewInfo }

  TdxRibbonTabsAreaButtonsViewInfo = class(TdxRibbonButtonsContainerViewInfo)
  protected
    procedure CalculateButtonsBounds(const ABounds: TRect); override;
    procedure RecreateButtonsViewInfo; override;
  public
    procedure Draw(ACanvas: TcxCanvas); override;
  end;

  { TdxRibbonContextViewInfo }

  TdxRibbonContextViewInfo = class(TObject)
  private
    FContext: TdxRibbonContext;
    FOwner: TdxRibbonContextsViewInfo;
    FText: string;
    function CalculateTextBounds(DC: HDC; AIndent: Integer): TRect;
    function GetCanvas: TcxCanvas;
    function GetFont: TFont;
    function GetFontShadowColor: TColor;
    function GetPainter: TdxRibbonPainter;
    function GetRibbonStyle: TdxRibbonStyle;
    function IsPaintOnGlass: Boolean;
    procedure InternalDrawText(ACanvas: TcxCanvas; const R: TRect; ATextColor: TColor; AHasGlowing: Boolean);
  protected
    FNeedShowHint: Boolean;
    FTextBounds: TRect;
    FTextWidth: Integer;
    procedure DrawBackground(ACanvas: TcxCanvas);
    procedure DrawText(ACanvas: TcxCanvas);
    function GetFullTextWidth: Integer;
    function GetTextBounds: TRect;

    property Canvas: TcxCanvas read GetCanvas;
    property Owner: TdxRibbonContextsViewInfo read FOwner;
    property Painter: TdxRibbonPainter read GetPainter;
    property RibbonStyle: TdxRibbonStyle read GetRibbonStyle;
  public
    Bounds: TRect;
    constructor Create(AOwner: TdxRibbonContextsViewInfo); virtual;
    procedure Calculate(const ABounds: TRect; AContext: TdxRibbonContext); virtual;
    procedure Paint(ACanvas: TcxCanvas);

    property Context: TdxRibbonContext read FContext;
    property Font: TFont read GetFont;
    property FontShadowColor: TColor read GetFontShadowColor;
    property NeedShowHint: Boolean read FNeedShowHint;
    property Text: string read FText;
    property TextBounds: TRect read FTextBounds;
  end;

  { TdxRibbonContextsViewInfo }

  TdxRibbonContextsViewInfo = class(TdxRibbonCustomContainerViewInfo)
  private
    function GetContextTabViewInfo(Index: Integer): TdxRibbonContextViewInfo;
  public
    procedure Calculate(const ABounds: TRect); override;
    procedure Draw(ACanvas: TcxCanvas); override;
    function GetContextViewInfo(AContext: TdxRibbonContext): TdxRibbonContextViewInfo;
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; override;
    function NeedShowHint(AContext: TdxRibbonContext): Boolean;
    //
    property Items[Index: Integer]: TdxRibbonContextViewInfo read GetContextTabViewInfo; default;
  end;

  { TdxRibbonApplicationButtonViewInfo }

  TdxRibbonApplicationButtonViewInfo = class(TdxRibbonCustomViewInfo, IdxFadingObject, IdxFadingObjectFadingOptions)
  private
    FIsHot: Boolean;
    FIsPressed: Boolean;
    function CanShowApplicationButtonText: Boolean;
    function GetApplicationButton: TdxRibbonApplicationButton;
    function GetClientBounds: TRect;
    function GetClientOffsets: TRect;
    function GetFont: TFont;
    function GetGlyphBounds: TRect;
    function GetGlyphOffsets: TRect;
    function GetIsPaintOnGlass: Boolean;
    function GetIsPlacedOnTabsArea: Boolean;
    function GetPainter: TdxRibbonPainter;
    function GetState: TdxRibbonApplicationButtonState;
    procedure SetIsHot(AValue: Boolean);
    procedure SetIsPressed(AValue: Boolean);
  protected
    function CalculateContentSize: TSize; virtual;
    procedure DrawBackground(ACanvas: TcxCanvas); virtual;
    procedure DrawContent(ACanvas: TcxCanvas); virtual;
    procedure DrawGlyph(ACanvas: TcxCanvas); virtual;
    procedure DrawText(ACanvas: TcxCanvas); virtual;
    // IdxFadingObject
    function CanFade: Boolean;
    procedure GetFadingImages(out AFadeOutImage, AFadeInImage: TcxBitmap);
    procedure IdxFadingObject.DrawFadeImage = Invalidate;
    // IdxFadingObjectFadingOptions
    function GetFadingOptions: TdxFadingOptions;

    property IsHot: Boolean read FIsHot write SetIsHot;
    property IsPressed: Boolean read FIsPressed write SetIsPressed;
    property Painter: TdxRibbonPainter read GetPainter;
  public
    destructor Destroy; override;
    procedure Calculate; reintroduce; virtual;
    procedure Draw(ACanvas: TcxCanvas); override;
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; override;
    function IsVisible(AIgnoreHidden: Boolean = False): Boolean;
    procedure InvalidateRect(const R: TRect); override;
    //
    property ApplicationButton: TdxRibbonApplicationButton read GetApplicationButton;
    property Bounds: TRect read FBounds;
    property ClientBounds: TRect read GetClientBounds;
    property ClientOffsets: TRect read GetClientOffsets;
    property Font: TFont read GetFont;
    property GlyphBounds: TRect read GetGlyphBounds;
    property GlyphOffsets: TRect read GetGlyphOffsets;
    property IsPaintOnGlass: Boolean read GetIsPaintOnGlass;
    property IsPlacedOnTabsArea: Boolean read GetIsPlacedOnTabsArea;
    property State: TdxRibbonApplicationButtonState read GetState;
  end;

  { TdxRibbonViewInfo }

  TdxRibbonViewInfo = class(TObject)
  private
    FApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo;
    FBounds: TRect;
    FContextsViewInfo: TdxRibbonContextsViewInfo;
    FDrawEmptyRibbon: Boolean;
    FFont: TFont;
    FFormCaptionBounds: TRect;
    FFormCaptionTheLeftOfContext: Boolean;
    FGroupsDockControlSiteBounds: TRect;
    FHidden: Boolean;
    FQATBarControlSize: TSize;
    FQuickAccessToolbarBounds: TRect;
    FRibbon: TdxCustomRibbon;
    FSupportNonClientDrawing: Boolean;
    FTabGroupsDockControlBounds: TRect;
    FTabsAreaButtonsViewInfo: TdxRibbonTabsAreaButtonsViewInfo;
    FTabsViewInfo: TdxRibbonTabsViewInfo;
    FUseGlass: Boolean;
    function GetCanvas: TcxCanvas;
    function GetColorScheme: TdxCustomRibbonSkin;
    function GetGroupsDockControlSiteViewInfo: TdxRibbonGroupsDockControlSiteViewInfo;
    function GetHasActiveContextTab: Boolean;
    function GetIsFormCaptionActive: Boolean;
    function GetIsTabsOnGlass: Boolean;
    function GetPainter: TdxRibbonPainter; {$IFDEF DELPHI9} inline; {$ENDIF}
    function GetQATDockControl: TdxRibbonQuickAccessDockControl;
    function GetQuickAccessToolbar: TdxRibbonQuickAccessToolbar;
    function GetScrollButtonWidth: Integer;
    function GetStyle: TdxRibbonStyle;
    function GetTabsVerticalOffset: Integer;
    procedure UpdateGroupsDockControlSite;
  protected
    procedure CalculateContexts; virtual;
    procedure CalculateQuickAccessToolbar; virtual;
    procedure CalculateRibbonFormCaption; virtual;
    procedure CalculateTabGroups; virtual;
    procedure CalculateTabs; virtual;
    procedure CalculateTabsAreaButtons; virtual;
    function GetBounds: TRect; virtual;
    function GetNonClientAreaHeight: Integer; virtual;
    function GetNonClientAreaObjectsRegion: HRGN; virtual;
    function GetRibbonHeight: Integer; virtual;
    //form caption
    function GetCaption: string; virtual;
    function GetDocumentName: string; virtual;
    function GetRibbonFormCaptionClientBounds: TRect; virtual;
    function GetRibbonFormCaptionTextBounds: TRect; virtual;
    function GetRibbonFormCaptionTextBoundsWithContext(
      const ABounds, ACenterRect: TRect; ATextWidth: Integer): TRect; virtual;
    //QuickAccessToolbar
    function GetQATAvailWidth: Integer;
    function GetQATBarControlSize: TSize; virtual;
    function GetQATBounds: TRect; virtual;
    function GetQATHeight: Integer; virtual;
    function GetQATLeft: Integer; virtual;
    function GetQATOverrideWidth(AIgnoreHidden: Boolean = False): Integer;
    function GetQATTop: Integer; virtual;
    function GetQATWidth: Integer; virtual;
    function GetQATDockControlBounds: TRect; virtual;
    function GetQATDockControlOffset(AIgnoreHidden: Boolean = False): TRect; virtual;
    //TabGroups
    function GetGroupsDockControlSiteBounds: TRect; virtual;
    function GetTabGroupsContentOffset: TRect; virtual;
    function GetTabGroupsDockControlBounds: TRect; virtual;
    function GetTabGroupsDockControlOffset: TRect; virtual;
    function GetTabGroupsHeight(AIgnoreHidden: Boolean = False): Integer; virtual;
    //Tabs
    function GetTabsAreaBounds: TRect; virtual;
    function GetTabsBounds: TRect; virtual;
    function GetTabsHeight: Integer; virtual;
    function GetTabContentOffsets: TRect; virtual;
    function GetTabViewInfoClass: TdxRibbonTabViewInfoClass; virtual;
    //MDI support
    function HasMDIButtons: Boolean;
    function IsMDIButtonEnabled(AButton: TdxBarMDIButton; AState: Integer): Boolean;

    function CanShowBarControls(AIgnoreHidden: Boolean = False): Boolean;
    function GetContextCaptionWidth(const ACaption: string): Integer;
    procedure DrawRibbonBackground(ACanvas: TcxCanvas);
    function IsNeedDrawBottomLine: Boolean;
    function IsNeedHideControl: Boolean;
    function IsQATAtBottom: Boolean;
    procedure UpdateButtonsStates;
    procedure UpdateNonClientParams;
    procedure UpdateQATDockControl;

    property Canvas: TcxCanvas read GetCanvas;
    property ColorScheme: TdxCustomRibbonSkin read GetColorScheme;
    property DrawEmptyRibbon: Boolean read FDrawEmptyRibbon;
    property IsTabsOnGlass: Boolean read GetIsTabsOnGlass;
    property QATDockControl: TdxRibbonQuickAccessDockControl read GetQATDockControl;
    property QuickAccessToolbar: TdxRibbonQuickAccessToolbar read GetQuickAccessToolbar;
    property ScrollButtonWidth: Integer read GetScrollButtonWidth;
    property Style: TdxRibbonStyle read GetStyle;
    property TabsHeight: Integer read GetTabsHeight;
    property UseGlass: Boolean read FUseGlass;
  public
    constructor Create(ARibbon: TdxCustomRibbon); virtual;
    destructor Destroy; override;
    procedure Calculate; virtual;
    procedure CalculateHitInfo(AHitTest: TdxRibbonHitInfo); virtual;
    function AdjustCaptionFontSize(ASize: Integer): Integer;
    function CanDrawFormDefaultIcon(const AData: TdxRibbonFormData): Boolean;
    function GetDocumentNameTextColor(AIsActive: Boolean): TColor; virtual;
    function GetFormCaptionFont(AIsActive: Boolean): TFont; virtual;
    function GetFormCaptionText: TCaption;
    function GetTabAtPos(X, Y: Integer): TdxRibbonTab;

    function IsApplicationButtonNearQAT(AIgnoreHidden: Boolean = False): Boolean;
    function IsContextsVisible: Boolean;
    function IsQATAtNonClientArea(AIgnoreHidden: Boolean = False): Boolean;
    function IsQATOnGlass: Boolean;
    function IsQATVisible(AIgnoreHidden: Boolean = False): Boolean;
    function IsTabGroupsVisible(AIgnoreHidden: Boolean = False): Boolean;
    function IsTabsVisible(AIgnoreHidden: Boolean = False): Boolean;
    procedure Paint(ACanvas: TcxCanvas);

    property ApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo read FApplicationButtonViewInfo;
    property Bounds: TRect read FBounds;
    property Caption: string read GetCaption;
    property DocumentName: string read GetDocumentName;
    property FormCaptionBounds: TRect read FFormCaptionBounds;
    property Hidden: Boolean read FHidden;
    property TabsAreaBounds: TRect read GetTabsAreaBounds;
    property TabsBounds: TRect read GetTabsBounds;

    property HasActiveContextTab: Boolean read GetHasActiveContextTab;
    property IsFormCaptionActive: Boolean read GetIsFormCaptionActive;
    property Painter: TdxRibbonPainter read GetPainter;
    property QuickAccessToolbarBounds: TRect read FQuickAccessToolbarBounds;
    property Ribbon: TdxCustomRibbon read FRibbon;
    property SupportNonClientDrawing: Boolean read FSupportNonClientDrawing;

    property GroupsDockControlSiteBounds: TRect read FGroupsDockControlSiteBounds;
    property TabGroupsDockControlBounds: TRect read FTabGroupsDockControlBounds;

    property ContextsViewInfo: TdxRibbonContextsViewInfo read FContextsViewInfo;
    property GroupsDockControlSiteViewInfo: TdxRibbonGroupsDockControlSiteViewInfo read GetGroupsDockControlSiteViewInfo;
    property TabsAreaButtonsViewInfo: TdxRibbonTabsAreaButtonsViewInfo read FTabsAreaButtonsViewInfo;
    property TabsViewInfo: TdxRibbonTabsViewInfo read FTabsViewInfo;
  end;

  { TdxRibbonBarPainter }

  TdxRibbonBarPainter = class(TdxBarSkinnedPainter)
  private
    FCollapsedGroupElementSizeDenominator: Integer;
    FCollapsedGroupElementSizeNumerator: Integer;
    FDrawParams: TdxBarButtonLikeControlDrawParams;
    FRibbon: TdxCustomRibbon;
    function GetCollapsedGroupGlyph(ABarControl: TdxBarControl): TBitmap;
    function GetCollapsedGroupGlyphBackgroundSize(ABarControl: TdxBarControl): TSize;
    function GetCollapsedGroupGlyphSize(ABarControl: TdxBarControl): TSize;
    function GetGroupState(ABarControl: TdxBarControl): Integer;
    function InternalGetGroupCaptionHeight(ATextHeight: Integer): Integer;
  protected
    procedure CalculateDrawParams;
    procedure DrawCollapsedToolbarBackgroundPart(ABarControl: TdxRibbonGroupBarControl;
      ACanvas: TcxCanvas; AGroupState: Integer);
    procedure DrawCollapsedToolbarContentPart(ABarControl: TdxRibbonGroupBarControl;
      ACanvas: TcxCanvas; AGroupState: Integer);
    procedure DrawToolbarContentPart(ABarControl: TdxBarControl; ACanvas: TcxCanvas); override;
    procedure DrawToolbarNonContentPart(ABarControl: TdxBarControl; DC: HDC); override;
    function GetButtonPartState(const ADrawParams: TdxBarButtonLikeControlDrawParams; AControlPart: Integer): Integer; override;
    function GetCollapsedGroupCaptionRect(const AGroupRect: TRect): TRect; virtual;
    function GetCollapsedGroupWidth(ABarControl: TdxRibbonGroupBarControl): Integer; virtual;
    function GetGroupCaptionHeight(ACaptionFont: TFont): Integer; virtual;
    function GetGroupMinWidth(ABarControl: TdxRibbonGroupBarControl): Integer; virtual;
    //
    property DrawParams: TdxBarButtonLikeControlDrawParams read FDrawParams;
  public
    constructor Create(AData: TdxNativeUInt); override;
    destructor Destroy; override;
    procedure BarDrawBackground(ABarControl: TdxBarControl; ADC: HDC;
      const ADestRect: TRect; const ASourceRect: TRect; ABrush: HBRUSH; AColor: TColor); override;
    function BarMarkRect(ABarControl: TdxBarControl): TRect; override;
    function BarMarkItemRect(ABarControl: TdxBarControl): TRect; override;
    function GetGroupRowHeight(AIconSize: Integer; AGroupFont: TFont): Integer; virtual;
    function DropDownGalleryGetSizingBandHeight(AIconSize: Integer; AGroupFont: TFont): Integer; override;
    function GetToolbarContentOffsets(ABar: TdxBar; ADockingStyle: TdxBarDockingStyle; AHasSizeGrip: Boolean): TRect; override;
    function SubMenuControlBeginGroupSize: Integer; override;
    function SubMenuGetSeparatorSize: Integer; override;
    //
    property Ribbon: TdxCustomRibbon read FRibbon;
  end;

  { TdxCustomRibbonDockControl }

  TdxCustomRibbonDockControl = class(TdxBarDockControl)
  private
    procedure CMVisibleChanged(var Message: TMessage); message CM_VISIBLECHANGED;
    procedure WMLButtonDblClk(var Message: TWMLButtonDblClk); message WM_LBUTTONDBLCLK;
  protected
    procedure AdjustSize; override;
    function AllowUndockWhenLoadFromIni: Boolean; override;
    procedure FillBackground(DC: HDC; const ADestR, ASourceR: TRect; ABrush: HBRUSH; AColor: TColor); override;
    function GetSunkenBorder: Boolean; override;
    function IsDrawDesignBorder: Boolean; override;
    function IsTransparent: Boolean; override;
    procedure VisibleChanged; virtual;
  public
    procedure UpdateColorScheme; virtual;
  end;

  { IdxRibbonGroupViewInfo }

  TdxRibbonGroupOffsetsInfo = record
    ButtonGroupOffset: Integer;
    ContentLeftOffset: Integer;
    ContentRightOffset: Integer;
  end;

  IdxRibbonGroupViewInfo = interface
  ['{A2CAD367-1836-4FA7-8730-8E7531463C8C}']
    procedure AddSeparator(const Value: TdxBarItemSeparatorInfo);
    procedure DeleteSeparators;
    function GetContentSize: TSize;
    function GetItemControlCount: Integer;
    function GetItemControlViewInfo(AIndex: Integer): IdxBarItemControlViewInfo;
    function GetMinContentWidth: Integer;
    function GetOffsetsInfo: TdxRibbonGroupOffsetsInfo;
    function GetSeparatorCount: Integer;
    function GetSeparatorInfo(AIndex: Integer): TdxBarItemSeparatorInfo;
    procedure SetContentSize(const Value: TSize);
    procedure SetSeparatorInfo(AIndex: Integer;
      const Value: TdxBarItemSeparatorInfo);
  end;

  { IdxRibbonGroupLayoutCalculator }

  IdxRibbonGroupLayoutCalculator = interface
  ['{894AC146-F69A-4ED2-9293-AA54AAAE1189}']
    procedure CalcInit(AGroupViewInfo: IdxRibbonGroupViewInfo);
    procedure CalcLayout(AGroupViewInfo: IdxRibbonGroupViewInfo);
    function CollapseMultiColumnItemControls(
      AGroupViewInfo: IdxRibbonGroupViewInfo): Boolean;
    function DecreaseMultiColumnItemControlsColumnCount(
      AGroupViewInfo: IdxRibbonGroupViewInfo): Boolean;
    function Reduce(AGroupViewInfo: IdxRibbonGroupViewInfo;
      AUpToViewLevel: TdxBarItemRealViewLevel): Boolean;
    procedure ReduceInit(AGroupViewInfo: IdxRibbonGroupViewInfo);
  end;

  { TdxRibbonGroupsDockControl }

  TdxRibbonGroupsDockControl = class(TdxCustomRibbonDockControl)
  private
    FTab: TdxRibbonTab;
    procedure DesignMenuClick(Sender: TObject);
    function GetRibbon: TdxCustomRibbon;
    function GetSiteViewInfo: TdxRibbonGroupsDockControlSiteViewInfo;
    procedure InitDesignMenu(AItemLinks: TdxBarItemLinks);
    procedure ShowDesignMenu;
    procedure WMGestureNotify(var Message: TWMGestureNotify); message WM_GESTURENOTIFY;
  protected
    FViewInfo: TdxRibbonGroupsDockControlViewInfo;
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    procedure CalcRowToolbarPositions(ARowIndex: Integer; AClientSize: Integer); override;
    procedure DblClick; override;
    procedure FillBackground(DC: HDC; const ADestR, ASourceR: TRect; ABrush: HBRUSH; AColor: TColor); override;
    procedure FullInvalidate;
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; override;
    function GetDockedBarControlClass: TdxBarControlClass; override;
    function GetPainter: TdxBarPainter; override;
    function GetViewInfoClass: TdxRibbonGroupsDockControlViewInfoClass; virtual;
    function IsMultiRow: Boolean; override;
    procedure MakeRectFullyVisible(const R: TRect); virtual;
    procedure Paint; override;
    procedure SetSize; override;
    procedure ShowCustomizePopup; override;
    procedure UpdateGroupPositions;
    procedure VisibleChanged; override;

    property Ribbon: TdxCustomRibbon read GetRibbon;
    property SiteViewInfo: TdxRibbonGroupsDockControlSiteViewInfo read GetSiteViewInfo;
    property ViewInfo: TdxRibbonGroupsDockControlViewInfo read FViewInfo;
  public
    constructor Create(ATab: TdxRibbonTab); reintroduce; virtual;
    destructor Destroy; override;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;

    property Tab: TdxRibbonTab read FTab;
  end;

  TdxRibbonGroupsReduceStage = (rgrsMultiColumnItemControlsColumnCount,
    rgrsMultiColumnItemControlsCollapsing, rgrsItemControlsViewLevel,
    rgrsGroupsCollapsing);

  { TdxRibbonGroupsDockControlViewInfo }

  TdxRibbonGroupsDockControlViewInfo = class
  private
    FScrollButtons: TdxRibbonScrollButtons;
    FScrollPosition: Integer;
    procedure CheckGroupsCollapsedStates;
    function GetFirstGroupPosition: Integer;
    function GetGroupCount: Integer;
    function GetGroupViewInfo(AIndex: Integer): TdxRibbonGroupBarControlViewInfo;
    function IsValidToolbar(AToolbar: TdxBar): Boolean;
    function TotalGroupsWidth: Integer;
    function TryPlaceGroups(AMaxContentWidth: Integer): Boolean;
  protected
    FDockControl: TdxRibbonGroupsDockControl;
    procedure CalculateGroupsScrollInfo(AMaxContentWidth: Integer); virtual;
    procedure InternalScrollGroups(ADelta: Integer; AMaxContentWidth: Integer); virtual;
  public
    constructor Create(ADockControl: TdxRibbonGroupsDockControl); virtual;
    procedure Calculate(const ABoundsRect: TRect); virtual;
    procedure ResetScrollInfo;
    procedure ScrollGroups(AScrollLeft: Boolean; AMaxContentWidth: Integer); virtual;

    property DockControl: TdxRibbonGroupsDockControl read FDockControl;
    property FirstGroupPosition: Integer read GetFirstGroupPosition;
    property GroupCount: Integer read GetGroupCount;
    property GroupViewInfos[AIndex: Integer]: TdxRibbonGroupBarControlViewInfo read GetGroupViewInfo;
    property ScrollButtons: TdxRibbonScrollButtons read FScrollButtons;
  end;

  { TdxRibbonTabGroupsPopupWindow }

  TdxRibbonTabGroupsPopupWindow = class(TcxCustomPopupWindow)
  private
    FAllowShowHideAnimation: Boolean;
    FRibbon: TdxCustomRibbon;
    FShadow: TdxBarShadow;
    FSwitchingBetweenTabs: Boolean;
    function CanShowShadow: Boolean;
    function GetBounds: TRect;
    function GetGroupsDockControlSite: TdxRibbonGroupsDockControlSite;
    // Messages
    procedure WMNCPaint(var Message: TMessage); message WM_NCPAINT;
    procedure WMShowWindow(var Message: TWMShowWindow); message WM_SHOWWINDOW;
    procedure WMSize(var Message: TWMSize); message WM_SIZE;
  protected
    function CalculatePosition: TPoint; override;
    procedure CalculateSize; override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure Deactivate; override;
    procedure DoClosed; override;
    procedure DoShowed; override;
    procedure DoShowing; override;
    procedure HandleNavigationKey(AKey: Word);
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
    function NeedIgnoreMouseMessageAfterCloseUp(AWnd: THandle; AMsg: Cardinal;
      AShift: TShiftState; const APos: TPoint): Boolean; override;
    procedure SetGroupsDockControlSite;
  public
    constructor Create(ARibbon: TdxCustomRibbon); reintroduce; virtual;
    destructor Destroy; override;
    //
    property AllowShowHideAnimation: Boolean read FAllowShowHideAnimation write FAllowShowHideAnimation;
    property GroupsDockControlSite: TdxRibbonGroupsDockControlSite read GetGroupsDockControlSite;
    property Ribbon: TdxCustomRibbon read FRibbon;
  end;

  { TdxRibbonCustomBarControl }

  TdxRibbonCustomBarControl = class(TdxBarPopupControl)
  private
    function GetQuickAccessToolbar: TdxRibbonQuickAccessToolbar;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
  protected
    function AllowSelectionFrame: Boolean; override;
    function AllowFade: Boolean; override;
    procedure InitializeForDock(ABar: TdxBar); override;

    function AllowQuickCustomizing: Boolean; override;
    function CanAlignControl(AControl: TdxBarItemControl): Boolean; override;
    function CanMoving: Boolean; override;
    procedure DrawBarParentBackground(ACanvas: TcxCanvas); virtual;
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; override;
    function GetBehaviorOptions: TdxBarBehaviorOptions; override;
    function GetEditFont: TFont; override;
    function GetFont: TFont; override;
    function GetFullItemRect(Item: TdxBarItemControl): TRect; override;
    function GetIsMainMenu: Boolean; override;
    function GetMultiLine: Boolean; override;
    function GetRibbon: TdxCustomRibbon; virtual; abstract;
    function MarkExists: Boolean; override;
    function NotHandleMouseMove(ACheckLastMousePos: Boolean = True): Boolean; override;
    function RealMDIButtonsOnBar: Boolean; override;
    //
    function ClickAtHeader: Boolean; virtual;
    procedure DoPopupMenuClick(Sender: TObject); virtual;
    function GetPopupMenuItems: TdxRibbonPopupMenuItems; virtual;
    procedure InitCustomizationPopup(AItemLinks: TdxBarItemLinks); override;
    procedure PopupMenuClick(Sender: TObject);
    procedure ShowPopup(AItem: TdxBarItemControl); override;
    //
    property QuickAccessToolbar: TdxRibbonQuickAccessToolbar read GetQuickAccessToolbar;
  public
    property Ribbon: TdxCustomRibbon read GetRibbon;
  end;

  { TdxRibbonQuickAccessBarControl }

  TdxRibbonQuickAccessBarControl = class(TdxRibbonCustomBarControl)
  private
    FBitmap: TcxBitmap32;
    FDefaultGlyph: TBitmap;
    FIsWindowCreation: Boolean;
    function GetSeparatorWidth(AItemControl: TdxBarItemControl): Integer;
    function GetViewInfo: TdxRibbonQuickAccessBarControlViewInfo;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
  protected
    procedure InitializeForDock(ABar: TdxBar); override;

    function AllItemsVisible: Boolean;
    procedure CalcControlsPositions; override;
    function CanHideAllItemsInSingleLine: Boolean; override;
    procedure CreateWnd; override;
    procedure DoPaintItem(AControl: TdxBarItemControl; ACanvas: TcxCanvas; const AItemRect: TRect); override;
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; override;
    function GetClientOffset: TRect; virtual;
    function GetDefaultItemGlyph: TBitmap; override;
    function GetItemControlDefaultViewLevel(
      AItemControl: TdxBarItemControl): TdxBarItemViewLevel; override;
    function GetMarkAccessibilityHelperClass: TdxBarAccessibilityHelperClass; override;
    function GetMarkSize: Integer; override;
    function GetMinHeight(AStyle: TdxBarDockingStyle): Integer; override;
    function GetMinWidth(AStyle: TdxBarDockingStyle): Integer; override;
    function GetPopupMenuItems: TdxRibbonPopupMenuItems; override;
    function GetQuickControlClass: TdxBarPopupControlClass; override;
    function GetRibbon: TdxCustomRibbon; override;
    function GetSize(AMaxWidth: Integer): TSize;
    function GetSizeForWidth(AStyle: TdxBarDockingStyle; AWidth: Integer): TSize; override;
    function GetViewInfoClass: TCustomdxBarControlViewInfoClass; override;

    function AllowQuickCustomizing: Boolean; override;
    procedure InitQuickCustomizeItemLinks(AQuickControl: TdxBarPopupControl); override;
    procedure InitAddRemoveSubItemPopup(AItemLinks: TdxBarItemLinks); override;

    procedure InitCustomizationPopup(AItemLinks: TdxBarItemLinks); override;
    function MarkExists: Boolean; override;
    procedure RemoveItemFromQAT;
    procedure ShowPopup(AItem: TdxBarItemControl); override;
    procedure UpdateDefaultGlyph(AGlyph: TBitmap); virtual;
    procedure UpdateDoubleBuffered; override;

    property ViewInfo: TdxRibbonQuickAccessBarControlViewInfo read GetViewInfo;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function IsOnGlass: Boolean; override;
  end;

  { TdxRibbonQuickAccessBarControlViewInfo }

  TdxRibbonQuickAccessBarControlViewInfo = class(TdxBarControlViewInfo)
  protected
    function CanShowSeparators: Boolean; override;
    function IsLastVisibleItemControl(AItemControl: TdxBarItemControl): Boolean; override;
  end;

  { TdxRibbonQuickAccessItemControlPainter }

  TdxRibbonQuickAccessPainter = class(TdxRibbonBarPainter)
  protected
    procedure BarDrawMarkBackground(ABarControl: TdxBarControl; DC: HDC; ItemRect: TRect; AToolbarBrush: HBRUSH); override;
    procedure DrawGroupButtonControl(ADrawParams: TdxBarButtonLikeControlDrawParams; const ARect: TRect); virtual;
    procedure DrawToolbarContentPart(ABarControl: TdxBarControl; ACanvas: TcxCanvas); override;
    function MarkButtonWidth: Integer; virtual;
  public
    function BarMarkRect(ABarControl: TdxBarControl): TRect; override;
    function BarMarkItemRect(ABarControl: TdxBarControl): TRect; override;
    procedure ComboControlDrawArrowButton(const ADrawParams: TdxBarEditLikeControlDrawParams; ARect: TRect; AInClientArea: Boolean); override;
    function GetToolbarContentOffsets(ABar: TdxBar; ADockingStyle: TdxBarDockingStyle; AHasSizeGrip: Boolean): TRect; override;
    function MarkButtonOffset: Integer; virtual;
    function MarkSizeX(ABarControl: TdxBarControl): Integer; override;
  end;

  { TdxRibbonQuickAccessDockControl }

  TdxRibbonQuickAccessDockControl = class(TdxCustomRibbonDockControl)
  private
    FPainter: TdxRibbonQuickAccessPainter;
    FRibbon: TdxCustomRibbon;
  protected
    procedure CalcLayout; override;
    function GetDockedBarControlClass: TdxBarControlClass; override;
    function GetPainter: TdxBarPainter; override;
    procedure ShowCustomizePopup; override;
    procedure VisibleChanged; override;
  public
    constructor Create(AOwner: TdxCustomRibbon); reintroduce; virtual;
    destructor Destroy; override;
    property Ribbon: TdxCustomRibbon read FRibbon;
  end;

  { TdxRibbonQuickAccessBarControlDesignHelper }

  TdxRibbonQuickAccessBarControlDesignHelper = class(TCustomdxBarControlDesignHelper)
  public
    class procedure GetEditors(AEditors: TList); override;
    class function GetForbiddenActions: TdxBarCustomizationActions; override;
  end;

  { TdxRibbonQuickAccessPopupBarControl }

  TdxRibbonQuickAccessPopupBarControl = class(TdxRibbonQuickAccessBarControl)
  private
    FPainter: TdxBarPainter;
    function GetQuickAccessBarControl: TdxRibbonQuickAccessBarControl;
    function GetMarkLink: TdxBarItemLink;
    function GetMarkSubItem: TCustomdxBarSubItem;
  protected
    procedure InitializeForDock(ABar: TdxBar); override;

    function GetClientOffset: TRect; override;
    function GetPainter: TdxBarPainter; override;
    function GetRibbon: TdxCustomRibbon; override;
    function GetPopupSize: TSize; override;
    function HasShadow: Boolean; override;
    function IsPopup: Boolean; override;
    property QuickAccessBarControl: TdxRibbonQuickAccessBarControl
      read GetQuickAccessBarControl;
  public
    destructor Destroy; override;
    procedure CloseUp; override;
    procedure Popup(const AOwnerRect: TRect); override;
  end;

  { TdxRibbonQuickAccessPopupItemControlPainter }

  TdxRibbonQuickAccessPopupPainter = class(TdxRibbonQuickAccessPainter)
  protected
    procedure DrawQuickAccessPopupSubItem(DC: HDC; const ARect: TRect; AState: Integer); virtual;
    procedure DrawToolbarContentPart(ABarControl: TdxBarControl; ACanvas: TcxCanvas); override;
  public
    function MarkButtonOffset: Integer; override;
    function MarkSizeX(ABarControl: TdxBarControl): Integer; override;
  end;

  { TdxRibbonQuickAccessPopupSubItem }

  TdxRibbonQuickAccessPopupSubItem = class(TdxBarSubItem)
  protected
    function CreateBarControl: TCustomdxBarControl; override;
  end;

  { TdxRibbonQuickAccessPopupSubMenuControl }

  TdxRibbonQuickAccessPopupSubMenuControl = class(TdxBarSubMenuControl)
  protected
    procedure ShowPopup(AItem: TdxBarItemControl); override;
  end;

  { TdxRibbonQuickAccessPopupSubItemControl }

  TdxRibbonQuickAccessPopupSubItemControl = class(TdxBarSubItemControl)
  protected
    procedure DoCloseUp(AHadSubMenuControl: Boolean); override;
    procedure DoPaint(ARect: TRect; PaintType: TdxBarPaintType); override;
    function GetDefaultWidth: Integer; override;
  end;

  { TdxRibbonQuickAccessPopupSubItemButton }

  TdxRibbonQuickAccessPopupSubItemButton = class(TdxBarButton)
  public
    procedure DoClick; override;
  end;

  { TdxRibbonQuickAccessPopupSubItemButtonControl }

  TdxRibbonQuickAccessPopupSubItemButtonControl = class(TdxBarButtonControl)
  end;

  { TdxRibbonGroupBarControl }

  TdxRibbonGroupBarControl = class(TdxRibbonCustomBarControl, IdxFadingObject, IdxFadingObjectFadingOptions)
  private
    FGroup: TdxRibbonTabGroup;
    FRibbon: TdxCustomRibbon;
    procedure DesignMenuClick(Sender: TObject);
    procedure DrawCaptionButtons(ACanvas: TcxCanvas);
    procedure DrawSelectedFrame(DC: HDC; const R: TRect);
    function GetCollapsed: Boolean;
    function GetGroupCaptionRect: TRect;
    function GetGroupDesignRect: TRect;
    function GetIsComponentSelected: Boolean;
    function GetIsDesignObjectsOnClientArea: Boolean;
    function GetViewInfo: TdxRibbonGroupBarControlViewInfo;
    procedure InitDesignMenu(AItemLinks: TdxBarItemLinks);
    procedure PaintDesignObjects(ACanvas: TcxCanvas);
    procedure PaintGroupBackground(ACanvas: TcxCanvas);
    procedure PaintGroupCaptionText(ACanvas: TcxCanvas);
    procedure ShowGroupDesignMenu;
    procedure WMGestureNotify(var Message: TWMGestureNotify); message WM_GESTURENOTIFY;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
  {$IFNDEF DELPHI14}
    procedure WMTabletQuerySystemGestureStatus(var Message: TMessage); message WM_TABLET_QUERYSYSTEMGESTURESTATUS;
  {$ENDIF}
  protected
    procedure InitializeForDock(ABar: TdxBar); override;

    //IdxFadingObject
    function IdxFadingObject.CanFade = FadingCanFade;
    procedure IdxFadingObject.DrawFadeImage = FadingDrawFadeImage;
    procedure IdxFadingObject.GetFadingImages = FadingGetFadingImages;

    //IdxFadingObjectFadingOptions
    function GetFadingOptions: TdxFadingOptions;

    function FadingCanFade: Boolean;
    procedure FadingDrawFadeImage;
    procedure FadingGetFadingImages(out AFadeOutImage, AFadeInImage: TcxBitmap);

    //methods
    procedure AdjustHintWindowPosition(var APos: TPoint; const ABoundsRect: TRect; AHeight: Integer); override;
    procedure CalcLayout; override;
    function CanProcessShortCut: Boolean; override;
    procedure CaptionChanged; override;
    procedure DoHideAll(AReason: TdxBarCloseUpReason); override;
    procedure DoNCPaint(DC: HDC); override;
    procedure DoOpaqueNCPaint(DC: HDC);
    procedure DoPaint; override;
    procedure DoTransparentNCPaint(DC: HDC);
    procedure DrawBarParentBackground(ACanvas: TcxCanvas); override;
    procedure DrawContentBackground; override;
    procedure DrawGroupsArea(ACanvas: TcxCanvas; const ABounds: TRect);
    function IsAllowContextPaint: Boolean; virtual;

    procedure DoBarMouseDown(Button: TMouseButton; Shift: TShiftState;
      const APoint: TPoint; AItemControl: TdxBarItemControl; APointInClientRect: Boolean); override;

    function ClickAtHeader: Boolean; override;
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; override;
    function GetCaption: TCaption; override;
    function GetMarkDrawState: TdxBarMarkState; override;
    function GetMoreButtonsHint: string; override;
    function GetQuickControlClass: TdxBarPopupControlClass; override;
    function GetRibbon: TdxCustomRibbon; override;
    function GetViewInfoClass: TCustomdxBarControlViewInfoClass; override;
    procedure GlyphChanged; override;
    function HasCaptionButtons: Boolean; override;
    procedure InitQuickControl(AQuickControl: TdxBarPopupControl); override;
    procedure MakeItemControlFullyVisible(AItemControl: TdxBarItemControl); override;
    function MarkExists: Boolean; override;
    procedure ViewStateChanged(APrevValue: TdxBarViewState); override;
    procedure UpdateCaptionButton(ACaptionButton: TdxBarCaptionButton); override;
    procedure WindowPosChanged(var Message: TWMWindowPosMsg); override;

    property GroupCaptionRect: TRect read GetGroupCaptionRect;
    property GroupDesignRect: TRect read GetGroupDesignRect;
    property IsComponentSelected: Boolean read GetIsComponentSelected;
    property IsDesignObjectsOnClientArea: Boolean read GetIsDesignObjectsOnClientArea;
    property ViewInfo: TdxRibbonGroupBarControlViewInfo read GetViewInfo;
  public
    destructor Destroy; override;
    procedure CloseUp; override;
    //
    property Collapsed: Boolean read GetCollapsed;
    property Group: TdxRibbonTabGroup read FGroup;
  end;

  TdxRibbonGroupKeyTipsBaseLinePositions = record
    BottomKeyTipsBaseLinePosition: Integer;
    Calculated: Boolean;
    RowKeyTipsBaseLinePositions: array of Integer;
  end;

  { TdxRibbonGroupBarControlViewInfo }

  TdxRibbonGroupBarControlViewInfo = class(TCustomdxBarControlViewInfo)
  private
    FCollapsed: Boolean;
    FContentSize: TSize;
    FGroupRowHeight: Integer;
    FKeyTipsBaseLinePositions: TdxRibbonGroupKeyTipsBaseLinePositions;
    FLayoutCalculator: IdxRibbonGroupLayoutCalculator;
    FNonContentAreaSize: TSize;
    FPrevCollapsedState: Boolean;
    function CreateCalculateHelper: IdxRibbonGroupViewInfo;
    function GetBarControl: TdxRibbonGroupBarControl;
    function GetBottomKeyTipsBaseLinePosition: Integer;
    function GetRibbon: TdxCustomRibbon;
    function GetRowKeyTipsBaseLinePosition(ARowIndex: Integer): Integer;
    function GetSize: TSize;
  protected
    procedure CalculateKeyTipsBaseLinePositions;
    function CreateLayoutCalculator: IdxRibbonGroupLayoutCalculator; virtual;
    procedure DoCalculateKeyTipsBaseLinePositions; virtual;
    function GetNonContentAreaSize: TSize; virtual;
    procedure RecreateItemControlViewInfos;
    procedure UpdateItemRects;
    //
    property ContentSize: TSize read FContentSize write FContentSize;
    property LayoutCalculator: IdxRibbonGroupLayoutCalculator read FLayoutCalculator;
  public
    procedure AfterCalculate; virtual;
    procedure BeforeCalculate(ACollapsed: Boolean); virtual;
    procedure Calculate; override;
    procedure CheckGroupCollapsedStates;
    function Reduce(AStage: TdxRibbonGroupsReduceStage; AUpToViewLevel: TdxBarItemRealViewLevel): Boolean;
    procedure ReduceInit;
    //
    property BarControl: TdxRibbonGroupBarControl read GetBarControl;
    property Collapsed: Boolean read FCollapsed write FCollapsed;
    property Size: TSize read GetSize;
    property BottomKeyTipsBaseLinePosition: Integer read GetBottomKeyTipsBaseLinePosition;
    property Ribbon: TdxCustomRibbon read GetRibbon;
    property RowKeyTipsBaseLinePositions[ARowIndex: Integer]: Integer read GetRowKeyTipsBaseLinePosition;
  end;

  { TdxRibbonGroupBarControlDesignHelper }

  TdxRibbonGroupBarControlDesignHelper = class(TCustomdxBarControlDesignHelper)
  public
    class function CanDynamicallyChangeViewLevels: Boolean; override;
    class function GetForbiddenActions: TdxBarCustomizationActions; override;
  end;

  { TdxRibbonCollapsedGroupPopupBarControl }

  TdxRibbonCollapsedGroupPopupBarControl = class(TdxRibbonGroupBarControl)
  private
    FAllowNCPaint: Boolean;
  protected
    function AllowNCPaint: Boolean; override;
    procedure DoBarMouseRightButtonDown(Shift: TShiftState; const APoint: TPoint;
      AItemControl, APrevSelectedControl: TdxBarItemControl; APointInClientRect: Boolean); override;
    function GetCaption: TCaption; override;
    function GetPainter: TdxBarPainter; override;
    function GetPopupSize: TSize; override;
    function GetSizeForWidth(AStyle: TdxBarDockingStyle; AWidth: Integer): TSize; override;
    function IgnoreClickAreaWhenHidePopup: TRect; override;
    procedure InitializeForPopup(AParentBarControl: TdxBarControl; ABar: TdxBar); override;
    function IsPopup: Boolean; override;
    function NeedHideOnNCMouseClick: Boolean; override;
  public
    destructor Destroy; override;
    procedure Hide; override;
    procedure Popup(const AOwnerRect: TRect); override;
  end;

  { TdxRibbonTabGroup }

  TdxRibbonTabGroupClass = class of TdxRibbonTabGroup;

  TdxRibbonTabGroupAssignedValue = (rtgavCaption);
  TdxRibbonTabGroupAssignedValues = set of TdxRibbonTabGroupAssignedValue;
  TdxRibbonTabGroupRestriction = (rtgrNone, rtgrNoExpand, rtgrNoCollapse);

  TdxRibbonTabGroup = class(TcxInterfacedCollectionItem,
    IdxBarSelectableItem, IdxRibbonToolbarContainer)
  private
    FAssignedValues: TdxRibbonTabGroupAssignedValues;
    FCaption: string;
    FDesignSelectionHelper: IdxBarSelectableItem;
    FLoadedToolbarName: string;
    FMergeKind: TdxRibbonMergeKind;
    FMergeOrder: Integer;
    FRestriction: TdxRibbonTabGroupRestriction;
    FToolbar: TdxBar;
    procedure CheckUndockToolbar;
    function GetAnotherTabWithOurToolbar(out ATab: TdxRibbonTab): Boolean;
    function GetCanCollapse: Boolean;
    function GetCaption: string;
    function GetIsCaptionAssigned: Boolean;
    function GetIsToolBarShared: Boolean;
    function GetRibbon: TdxCustomRibbon;
    function GetTab: TdxRibbonTab;
    function GetToolbar: TdxBar;
    function GetVisible: Boolean;
    procedure ReadCaption(AReader: TReader);
    procedure ReadToolbarName(AReader: TReader);
    procedure SetAssignedValues(const AValue: TdxRibbonTabGroupAssignedValues);
    procedure SetCanCollapse(Value: Boolean);
    procedure SetCaption(const AValue: string);
    procedure SetMergeOrder(const Value: Integer);
    procedure SetRestriction(AValue: TdxRibbonTabGroupRestriction);
    procedure SetToolbar(Value: TdxBar);
    procedure ValidateToolbar(Value: TdxBar);
    procedure WriteCaption(AWriter: TWriter);
    procedure WriteToolbarName(AWriter: TWriter);
  protected
    procedure DefineProperties(Filer: TFiler); override;
    procedure DockToolbar(AToolbar: TdxBar); virtual;
    function IsToolbarAcceptable(AToolbar: TdxBar): Boolean;
    procedure UpdateBarManager(ABarManager: TdxBarManager);
    procedure UpdateToolbarValue;

    property DesignSelectionHelper: IdxBarSelectableItem read FDesignSelectionHelper implements IdxBarSelectableItem;
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;

    function IsMergeAllowed: Boolean; virtual;
    function IsMerged: Boolean; virtual;
    procedure Merge(AGroup: TdxRibbonTabGroup;
      AMergeOptions: TdxRibbonMergeOptions = dxRibbonDefaultMergeOptions); virtual;
    procedure Unmerge(AGroup: TdxRibbonTabGroup = nil); virtual;

    property IsToolBarShared: Boolean read GetIsToolBarShared;
    property Ribbon: TdxCustomRibbon read GetRibbon;
    property Tab: TdxRibbonTab read GetTab;
    property Visible: Boolean read GetVisible;
  published
    property AssignedValues: TdxRibbonTabGroupAssignedValues read FAssignedValues write SetAssignedValues stored False;
    property Caption: string read GetCaption write SetCaption stored GetIsCaptionAssigned;
    property MergeKind: TdxRibbonMergeKind read FMergeKind write FMergeKind default rmkMerge;
    property MergeOrder: Integer read FMergeOrder write SetMergeOrder default 0;
    property Restriction: TdxRibbonTabGroupRestriction read FRestriction write SetRestriction default rtgrNone;
    property ToolBar: TdxBar read GetToolbar write SetToolbar stored False;

    property CanCollapse: Boolean read GetCanCollapse write SetCanCollapse default True; //Obsolete
  end;

  { TdxRibbonTabGroups }

  TdxRibbonTabGroups = class(TCollection)
  private
    FTab: TdxRibbonTab;
    function GetItem(Index: Integer): TdxRibbonTabGroup;
    procedure SetItem(Index: Integer; const Value: TdxRibbonTabGroup);
  protected
    function GetOwner: TPersistent; override;
    procedure FreeNotification(AComponent: TComponent);
    procedure Notify(Item: TCollectionItem; Action: TCollectionNotification); override;
    procedure Unmerge(AGroup: TdxRibbonTabGroup = nil);
    procedure Update(Item: TCollectionItem); override;
    procedure UpdateGroupToolbarValues;
  public
    constructor Create(ATab: TdxRibbonTab);
    function Add: TdxRibbonTabGroup;
    function ContainsToolBar(AToolBar: TdxBar): Boolean;
    function Find(const ACaption: string; out AGroup: TdxRibbonTabGroup): Boolean;
    function IndexOf(AGroup: TdxRibbonTabGroup): Integer;
    function Insert(AIndex: Integer): TdxRibbonTabGroup;
    //
    property Items[Index: Integer]: TdxRibbonTabGroup read GetItem write SetItem; default;
    property Tab: TdxRibbonTab read FTab;
  end;

  { TdxRibbonQuickAccessToolbar }

  TdxQuickAccessToolbarPosition = (qtpAboveRibbon, qtpBelowRibbon);

  TdxRibbonQuickAccessToolbar = class(TInterfacedPersistent, IdxRibbonToolbarContainer)
  private
    FDockControl: TdxRibbonQuickAccessDockControl;
    FPosition: TdxQuickAccessToolbarPosition;
    FRibbon: TdxCustomRibbon;
    FToolbar: TdxBar;
    FVisible: Boolean;
    function GetRealVisible: Boolean;
    procedure CheckUndockGroupToolbar(AValue: TdxBar);
    procedure SetPosition(AValue: TdxQuickAccessToolbarPosition);
    procedure SetVisible(AValue: Boolean);
  protected
    procedure BarManagerLoadIni(const AEventData: TdxBarIniFileEventData);
    procedure BarManagerSaveIni(const AEventData: TdxBarIniFileEventData);
    function Contains(AItemLink: TdxBarItemLink): Boolean;

    function CreateDockControl: TdxRibbonQuickAccessDockControl; virtual;
    function GetMenuItemsForMark: TdxRibbonPopupMenuItems; virtual;
    procedure UpdateColorScheme; virtual;
    procedure UpdateGroupButton(AForToolbar: TdxBar; ABeforeUndock: Boolean);
    procedure UpdateMenuItems(AItems: TdxBarItemLinks);
    procedure UpdateRibbon;

    // IdxRibbonToolbarContainer
    function GetRibbon: TdxCustomRibbon;
    function GetToolbar: TdxBar;
    procedure SetToolbar(AValue: TdxBar);

    property DockControl: TdxRibbonQuickAccessDockControl read FDockControl;
    property RealVisible: Boolean read GetRealVisible;
  public
    constructor Create(ARibbon: TdxCustomRibbon); virtual;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function AddGroupButton(AToolbar: TdxBar): TdxRibbonQuickAccessGroupButton;
    function HasGroupButtonForToolbar(AToolbar: TdxBar): Boolean;

    function IsMerged: Boolean; virtual;
    procedure Merge(AQuickAccessToolbar: TdxRibbonQuickAccessToolbar;
      AMergeOptions: TdxRibbonMergeOptions = dxRibbonDefaultMergeOptions); virtual;
    procedure Unmerge(AQuickAccessToolbar: TdxRibbonQuickAccessToolbar = nil); virtual;

    property Ribbon: TdxCustomRibbon read GetRibbon;
  published
    property Position: TdxQuickAccessToolbarPosition read FPosition write SetPosition default qtpAboveRibbon;
    property Toolbar: TdxBar read GetToolbar write SetToolbar;
    property Visible: Boolean read FVisible write SetVisible default True;
  end;

  { TdxRibbonCustomButtonPersistent }

  TdxRibbonCustomButtonPersistent = class(TPersistent)
  private
    FGlyph: TBitmap;
    FRibbon: TdxCustomRibbon;
    FScreenTip: TdxScreenTip;
    FStretchGlyph: Boolean;

    procedure GlyphChanged(Sender: TObject);
    procedure SetGlyph(Value: TBitmap);
    procedure SetScreenTip(const Value: TdxScreenTip);
    procedure SetStretchGlyph(const Value: Boolean);
  protected
    procedure Update;
  public
    constructor Create(ARibbon: TdxCustomRibbon); virtual;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;

    property Ribbon: TdxCustomRibbon read FRibbon;
  published
    property Glyph: TBitmap read FGlyph write SetGlyph;
    property ScreenTip: TdxScreenTip read FScreenTip write SetScreenTip;
    property StretchGlyph: Boolean read FStretchGlyph write SetStretchGlyph default True;
  end;

  { TdxRibbonHelpButton }

  TdxRibbonHelpButton = class(TdxRibbonCustomButtonPersistent);

  { TdxRibbonApplicationButton }

  TdxRibbonApplicationButton = class(TdxRibbonCustomButtonPersistent)
  private
    FIAccessibilityHelper: IdxBarAccessibilityHelper;
    FIMenu: IdxRibbonApplicationMenu;
    FKeyTip: string;
    FMenu: TComponent;
    FText: string;
    FVisible: Boolean;
    function GetIAccessibilityHelper: IdxBarAccessibilityHelper;
    procedure SetMenu(const Value: TComponent);
    procedure SetText(const Value: string);
    procedure SetVisible(const Value: Boolean);
  protected
    function CanShowPopup: Boolean;
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; virtual;
    function Popup(var AClosedByEscape: Boolean): Boolean;
    procedure ClosePopup;
    procedure Notification(AComponent: TComponent; Operation: TOperation);

    property IAccessibilityHelper: IdxBarAccessibilityHelper read GetIAccessibilityHelper;
    property IMenu: IdxRibbonApplicationMenu read FIMenu;
  public
    constructor Create(ARibbon: TdxCustomRibbon); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    property KeyTip: string read FKeyTip write FKeyTip;
    property Menu: TComponent read FMenu write SetMenu;
    property Text: string read FText write SetText;
    property Visible: Boolean read FVisible write SetVisible default True;
  end;

  { TdxRibbonContext }

  TdxRibbonContext = class(TCollectionItem)
  private
    FCaption: string;
    FColor: TColor;
    FMergeOrder: Integer;
    FVisible: Boolean;
    function GetCollection: TdxRibbonContexts;
    function GetMergedWithContext: TdxRibbonContext;
    function GetRibbon: TdxCustomRibbon;
    function GetTab(Index: Integer): TdxRibbonTab;
    function GetTabCount: Integer;
    procedure SetCaption(const AValue: string);
    procedure SetColor(AValue: TColor);
    procedure SetMergeOrder(const AValue: Integer);
    procedure SetVisible(AValue: Boolean);
  protected
    FCreatedByMerging: Boolean;
    FCreatedByMergingWith: TdxRibbonContext;
    function GetDisplayName: string; override;
    procedure ColorChanged;
    procedure UpdateMergeTargetVisibility;
    procedure VisibleChanged;

    property Collection: TdxRibbonContexts read GetCollection;
    property MergedWithContext: TdxRibbonContext read GetMergedWithContext;
    property Ribbon: TdxCustomRibbon read GetRibbon;
  public
    constructor Create(Collection: TCollection); override;
    procedure Assign(Source: TPersistent); override;
    procedure Activate(AActivateFirstTab: Boolean = True);

    property TabCount: Integer read GetTabCount;
    property Tabs[Index: Integer]: TdxRibbonTab read GetTab;
  published
    property Caption: string read FCaption write SetCaption;
    property Color: TColor read FColor write SetColor default clWhite;
    property MergeOrder: Integer read FMergeOrder write SetMergeOrder default 0;
    property Visible: Boolean read FVisible write SetVisible default False;
  end;

  { TdxRibbonContexts }

  TdxRibbonContexts = class(TCollection)
  private
    FRibbon: TdxCustomRibbon;
    function GetActiveContext: TdxRibbonContext;
    function GetItem(Index: Integer): TdxRibbonContext;
    procedure SetItem(Index: Integer; const Value: TdxRibbonContext);
  protected
    function GetItemFromIndex(AIndex: Integer): TdxRibbonContext;
    procedure Notify(Item: TCollectionItem; Action: TCollectionNotification); override;
    procedure Update(Item: TCollectionItem); override;
  public
    constructor Create(ARibbon: TdxCustomRibbon); reintroduce; virtual;
    function Add: TdxRibbonContext;
    function Find(const ACaption: string): TdxRibbonContext;
    function IndexOf(AContext: TdxRibbonContext): Integer;
    function Insert(AIndex: Integer): TdxRibbonContext;

    property ActiveContext: TdxRibbonContext read GetActiveContext;
    property Items[Index: Integer]: TdxRibbonContext read GetItem write SetItem; default;
    property Ribbon: TdxCustomRibbon read FRibbon;
  end;

  { TdxRibbonTabMergeData }

  TdxRibbonTabMergeData = class(TdxRibbonCustomMergeData)
  public
    MergedWith: TdxRibbonTab;
  end;

  { TdxRibbonTab }

  TdxRibbonTabClass = class of TdxRibbonTab;

  TdxRibbonTab = class(
    TcxComponentCollectionItem,
    IdxBarSelectableItem,
    IdxFadingObject,
    IdxFadingObjectFadingOptions
  )
  private
    FCaption: string;
    FContext: TdxRibbonContext;
    FContextIndex: Integer;
    FDesignSelectionHelper: IdxBarSelectableItem;
    FDockControl: TdxRibbonGroupsDockControl;
    FGroups: TdxRibbonTabGroups;
    FIAccessibilityHelper: IdxBarAccessibilityHelper;
    FKeyTip: string;
    FLastIndex: Integer;
    FLoadedIndex: Integer;
    FLocked: Boolean;
    FMergeData: TdxRibbonTabMergeData;
    FMergeKind: TdxRibbonMergeKind;
    FMergeOrder: Integer;
    FRibbon: TdxCustomRibbon;
    FSaveContextIndex: Integer;
    FVisible: Boolean;
    function GetActive: Boolean;
    function GetFocused: Boolean;
    function GetHighlighted: Boolean;
    function GetIAccessibilityHelper: IdxBarAccessibilityHelper;
    function GetIsDestroying: Boolean;
    function GetViewInfo: TdxRibbonTabViewInfo;
    function GetVisibleIndex: Integer;
    procedure SetActive(Value: Boolean);
    procedure SetCaption(const Value: string);
    procedure SetContext(AValue: TdxRibbonContext);
    procedure SetGroups(const Value: TdxRibbonTabGroups);
    procedure SetHighlighted(Value: Boolean);
    procedure SetMergeOrder(const AValue: Integer);
    procedure SetRibbon(Value: TdxCustomRibbon);
    procedure SetVisible(Value: Boolean);
    procedure ReadContextIndex(Reader: TReader);
    procedure ReadIndex(Reader: TReader);
    procedure WriteContextIndex(Writer: TWriter);
    procedure WriteIndex(Writer: TWriter);
  protected
    // IdxFadingObject
    procedure IdxFadingObject.DrawFadeImage = FadingDrawFadeImage;
    procedure IdxFadingObject.GetFadingImages = FadingGetFadingImages;
    function CanFade: Boolean;
    procedure FadingDrawFadeImage;
    procedure FadingGetFadingImages(out AFadeOutImage, AFadeInImage: TcxBitmap);
    // IdxFadingObjectFadingOptions
    function GetFadingOptions: TdxFadingOptions;
    // Merging
    function InternalUnmerge(ATab: TdxRibbonTab): Boolean; virtual;
    procedure UnmergeBeforeDestroy;
    //inherited
    procedure DefineProperties(Filer: TFiler); override;
    function GetCollectionFromParent(AParent: TComponent): TcxComponentCollection; override;
    function GetDisplayName: string; override;
    procedure Loaded; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetName(const Value: TComponentName); override;
    //methods
    procedure Activate; virtual;
    procedure AssignCommonProperties(ASource: TdxRibbonTab); virtual;
    procedure CheckGroupToolbarsDockControl;
    procedure Deactivate; virtual;
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; virtual;
    function GetDockControlBounds: TRect; virtual;
    function GetGroupClass: TdxRibbonTabGroupClass; virtual;
    function IsVisible: Boolean;
    procedure RestoreContext;
    procedure RestoreIndex;
    procedure SaveContext;
    procedure ScrollDockControlGroups(AScrollLeft, AOnTimer: Boolean);
    procedure UpdateBarManager(ABarManager: TdxBarManager);
    procedure UpdateColorScheme; virtual;
    procedure UpdateContextIndex;
    procedure UpdateDockControl;
    procedure UpdateDockControlBounds;
    procedure UpdateGroupsFont;

    property DesignSelectionHelper: IdxBarSelectableItem read FDesignSelectionHelper implements IdxBarSelectableItem;
    property Focused: Boolean read GetFocused;
    property Highlighted: Boolean read GetHighlighted write SetHighlighted;
    property IsDestroying: Boolean read GetIsDestroying;
    property LastIndex: Integer read FLastIndex;
    property LoadedIndex: Integer read FLoadedIndex;
    property Locked: Boolean read FLocked;
    property MergeData: TdxRibbonTabMergeData read FMergeData;
    property ViewInfo: TdxRibbonTabViewInfo read GetViewInfo;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure AddToolBar(AToolBar: TdxBar);
    procedure Invalidate;
    procedure MakeVisible;

    function IsMergeAllowed: Boolean; virtual;
    function IsMerged: Boolean; virtual;
    procedure Merge(ATab: TdxRibbonTab; AMergeOptions: TdxRibbonMergeOptions = dxRibbonDefaultMergeOptions); virtual;
    procedure Unmerge(ATab: TdxRibbonTab = nil); virtual;

    property DockControl: TdxRibbonGroupsDockControl read FDockControl;
    property IAccessibilityHelper: IdxBarAccessibilityHelper read GetIAccessibilityHelper;
    property Ribbon: TdxCustomRibbon read FRibbon write SetRibbon;
  published
    property Active: Boolean read GetActive write SetActive default False;
    property Caption: string read FCaption write SetCaption;
    property Context: TdxRibbonContext read FContext write SetContext stored False;
    property Groups: TdxRibbonTabGroups read FGroups write SetGroups;
    property KeyTip: string read FKeyTip write FKeyTip;
    property MergeKind: TdxRibbonMergeKind read FMergeKind write FMergeKind default rmkMerge;
    property MergeOrder: Integer read FMergeOrder write SetMergeOrder default 0;
    property Visible: Boolean read FVisible write SetVisible default True;
    property VisibleIndex: Integer read GetVisibleIndex;
  end;

  { TdxRibbonTabCollection }

  TdxRibbonTabCollection = class(TcxComponentCollection)
  private
    FOwner: TdxCustomRibbon;
    // Accessibility
    FIAccessibilityHelper: IdxBarAccessibilityHelper;
    function GetIAccessibilityHelper: IdxBarAccessibilityHelper;
    function GetItem(Index: Integer): TdxRibbonTab;
    procedure SetItem(Index: Integer; const Value: TdxRibbonTab);
  protected
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; virtual;
    function FindByLoadedIndex(AIndex: Integer): TdxRibbonTab;
    procedure InternalUnmerge(ATab: TdxRibbonTab = nil);
    procedure Notify(AItem: TcxComponentCollectionItem;
      AAction: TcxComponentCollectionNotification); override;
    procedure RemoveContext(AContext: TdxRibbonContext);
    procedure RestoreContexts;
    procedure RestoreOrder;
    procedure SaveContexts;
    procedure SetItemName(AItem: TcxComponentCollectionItem); override;
    procedure Update(AItem: TcxComponentCollectionItem;
      AAction: TcxComponentCollectionNotification); override;
    procedure UpdateBarManager(ABarManager: TdxBarManager);
    procedure UpdateContexts;

    property IAccessibilityHelper: IdxBarAccessibilityHelper read GetIAccessibilityHelper;
    property Owner: TdxCustomRibbon read FOwner;
  public
    constructor Create(AOwner: TdxCustomRibbon); reintroduce;
    destructor Destroy; override;
    function Add: TdxRibbonTab;
    function ContainsToolBar(AToolBar: TdxBar): Boolean;
    function Find(const ACaption: string): TdxRibbonTab;
    function Insert(AIndex: Integer): TdxRibbonTab;
    function IsMerged: Boolean;
    //
    property Items[Index: Integer]: TdxRibbonTab read GetItem write SetItem; default;
  end;

  { TdxRibbonFonts }

  TdxRibbonAssignedFont = (afTabHeader, afGroup, afGroupHeader, afApplicationButton);
  TdxRibbonAssignedFonts = set of TdxRibbonAssignedFont;

  TdxRibbonFonts = class(TPersistent)
  private
    FAssignedFonts: TdxRibbonAssignedFonts;
    FCaptionFont: TFont;
    FDocumentNameColor: TColor;
    FFonts: array[TdxRibbonAssignedFont] of TFont;
    FInternalCaptionFont: TFont;
    FInternalFonts: array[TdxRibbonAssignedFont] of TFont;
    FLocked: Boolean;
    FRibbon: TdxCustomRibbon;
    procedure FontChanged(Sender: TObject);
    function GetDefaultCaptionTextColor(AIsActive: Boolean): TColor;
    function GetFont(const Index: Integer): TFont;
    function GetInternalFont(AIndex: TdxRibbonAssignedFont): TFont;
    function IsFontStored(const Index: Integer): Boolean;
    procedure SetAssignedFonts(const Value: TdxRibbonAssignedFonts);
    procedure SetDocumentNameColor(const Value: TColor);
    procedure SetFont(const Index: Integer; const Value: TFont);
    procedure UpdateGroupsFont;
  protected
    function GetPartColor(APart: Integer; AState: Integer = 0): TColor;
    procedure Invalidate;
    procedure UpdateFonts;

    property Locked: Boolean read FLocked;
  public
    constructor Create(AOwner: TdxCustomRibbon); virtual;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;

    function GetApplicationButtonFont(AState: TdxRibbonApplicationButtonState): TFont; virtual;
    function GetContextFont(AContextColor: TColor = clDefault): TFont; virtual;
    function GetFormCaptionFont(AIsActive: Boolean): TFont; virtual;
    function GetGroupFont: TFont; virtual;
    function GetGroupHeaderFont: TFont; virtual;
    function GetTabHeaderFont(AState: Integer; AContext: TdxRibbonContext): TFont;

    property Ribbon: TdxCustomRibbon read FRibbon;
  published
    property ApplicationButton: TFont index Ord(afApplicationButton) read GetFont write SetFont stored IsFontStored;
    property AssignedFonts: TdxRibbonAssignedFonts read FAssignedFonts write SetAssignedFonts default [];
    property DocumentNameColor: TColor read FDocumentNameColor write SetDocumentNameColor default clDefault;
    property Group: TFont index Ord(afGroup) read GetFont write SetFont stored IsFontStored;
    property GroupHeader: TFont index Ord(afGroupHeader) read GetFont write SetFont stored IsFontStored;
    property TabHeader: TFont index Ord(afTabHeader) read GetFont write SetFont stored IsFontStored;
  end;

  { TdxRibbonHolderComponent }

  TdxRibbonHolderComponent = class(TcxComponentHolder)
  private
    procedure CheckAssignRibbon(AOwner: TComponent);
    function GetRibbon: TdxCustomRibbon;
    procedure SetRibbon(Value: TdxCustomRibbon);
  public
    constructor Create(AOwner: TComponent);

    property Ribbon: TdxCustomRibbon read GetRibbon write SetRibbon;
  end;

  { TdxRibbonCustomPopupComponent }

  TdxRibbonCustomPopupComponent = class(TdxBarCustomPopupComponent)
  private
    FRibbonHolder: TdxRibbonHolderComponent;

    function GetRibbon: TdxCustomRibbon;
    procedure SetRibbon(const Value: TdxCustomRibbon);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    property Ribbon: TdxCustomRibbon read GetRibbon write SetRibbon;
  end;

  { TdxRibbonPopupMenu }

  TdxRibbonCustomPopupMenu = class(TdxBarCustomPopupMenu)
  private
    FRibbonHolder: TdxRibbonHolderComponent;
    procedure SetRibbon(Value: TdxCustomRibbon);
    function GetRibbon: TdxCustomRibbon;
  protected
    function CreateBarControl: TCustomdxBarControl; override;
    function GetControlClass: TCustomdxBarControlClass; override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    property Ribbon: TdxCustomRibbon read GetRibbon write SetRibbon;
  end;

  { TdxRibbonPopupMenu }

  TdxRibbonPopupMenu = class(TdxRibbonCustomPopupMenu)
  published
    property BarManager;
    property BarSize;
    property Font;
    property ItemLinks;
    property ItemOptions;
    property PopupAlignment;
    property Ribbon;
    property UseOwnFont;
    property UseRecentItems;
    property OnCloseUp;
    property OnPaintBar;
    property OnPopup;
  end;

  { TdxRibbonPopupMenuControl }

  TdxRibbonPopupMenuControl = class(TdxBarSubMenuControl)
  protected
    function GetBehaviorOptions: TdxBarBehaviorOptions; override;
  end;

  { TdxBarApplicationMenu }

  TdxBarApplicationMenu = class(TdxBarCustomApplicationMenu, IdxRibbonApplicationMenu)
  private
    FClosedByEscape: Boolean;
    FRibbonPainter: TdxBarPainter;
  protected
    procedure DoCloseUp; override;
    procedure DoPopup; override;
    function GetControlClass: TCustomdxBarControlClass; override;
    // IdxRibbonApplicationMenu
    function ApplicationMenuPopup(ARibbon: TdxCustomRibbon; var AClosedByEscape: Boolean): Boolean;
    function CanShowPopup(ARibbon: TdxCustomRibbon): Boolean;
    function ClosePopup: Boolean;
    function GetDisplayMode: TdxRibbonApplicationMenuDisplayMode;
    function GetOrigin(AIsClientArea: Boolean): TPoint;
    procedure GetTabOrderList(List: TList);
    function GetRootAccessibilityHelper: IdxBarAccessibilityHelper;
    function IdxRibbonApplicationMenu.Popup = ApplicationMenuPopup;
    procedure RibbonFormResized;
    procedure SelectAppMenuFirstItemControl;
    procedure ShowKeyTips;
    procedure UpdateColorScheme;
    procedure UpdateNonClientArea;
  public
    procedure Popup(X, Y: Integer); override;
  published
    property BackgroundBitmap;
    property BarManager;
    property BarSize;
    property Buttons;
    property ExtraPane;
    property ExtraPaneEvents;
    property Font;
    property ItemLinks;
    property ItemOptions;
    property UseOwnFont;

    property OnCloseUp;
    property OnPaintBar;
    property OnPopup;

    // obsolete
    property ExtraPaneWidthRatio stored False;
    property ExtraPaneSize stored False;
    property ExtraPaneItems stored False;
    property ExtraPaneHeader stored False;
    property OnExtraPaneItemClick stored False;
  end;

  { TdxRibbonApplicationMenuControl }

  TdxRibbonApplicationMenuControl = class(TdxBarApplicationMenuControl)
  private
    function GetRibbon: TdxCustomRibbon;
    procedure DoPopupMenuClick(Sender: TObject);
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
  protected
    function GetBehaviorOptions: TdxBarBehaviorOptions; override;
    procedure InitCustomizationPopup(AItemLinks: TdxBarItemLinks); override;

    function GetPopupMenuItems: TdxRibbonPopupMenuItems;
    procedure PopupMenuClick(Sender: TObject);
    property Ribbon: TdxCustomRibbon read GetRibbon;
  end;

  { TdxRibbonController }

  TdxRibbonController = class(TcxIUnknownObject, IdxBarHintKeeper)
  private
    FHintInfo: TdxRibbonHitInfo;
    FHitInfo: TdxRibbonHitInfo;
    FHotButton: TdxRibbonCustomButtonViewInfo;
    FHotObject: TdxRibbonHitTest;
    FPressedButton: TdxRibbonCustomButtonViewInfo;
    FPressedContext: TdxRibbonContext;
    FPressedObject: TdxRibbonHitTest;
    FRibbon: TdxCustomRibbon;
    FScrollKind: TdxRibbonHitTest;
    FScrollTimer: TcxTimer;
    FSkipDblClick: Boolean;
    procedure CancelScroll;
    function CanProcessDesignTime: Boolean;
    procedure CreateTimer;
    function GetApplicationButton: TdxRibbonApplicationButton;
    function GetApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo;
    function GetApplicationMenuState: TdxRibbonApplicationMenuState;
    function GetViewInfo: TdxRibbonViewInfo;
    procedure ScrollTimerHandler(Sender: TObject);
    procedure SetHintInfo(const Value: TdxRibbonHitInfo);
    procedure SetHotButton(AValue: TdxRibbonCustomButtonViewInfo);
    procedure SetPressedButton(AValue: TdxRibbonCustomButtonViewInfo);
    procedure SetPressedObject(const Value: TdxRibbonHitTest);
  protected
    // IdxBarHintKeeper
    function DoHint(var ANeedDeactivate: Boolean; out AHintText: string; out AShortCut: string): Boolean;
    function CreateHintViewInfo(const AHintText, AShortCut: string): TdxBarCustomHintViewInfo;
    function GetEnabled: Boolean;
    function GetHintPosition(const ACursorPos: TPoint; AHeight: Integer): TPoint;

    procedure CancelHint;
    procedure CancelMode; virtual;
    function CanSwitchMinimizedOnDblClick: Boolean; virtual;
    function CloseApplicationMenu: Boolean;
    procedure DesignTabMenuClick(Sender: TObject);
    procedure DoScroll(AOnTimer: Boolean);
    procedure HideHint; virtual;
    procedure InitTabDesignMenu(AItemLinks: TdxBarItemLinks); virtual;
    function IsApplicationMenuDropped: Boolean;
    function IsNeedShowHint(AObject: TdxRibbonHitTest): Boolean; virtual;
    function IsOwnerForHintObject(AObject: TdxRibbonHitTest): Boolean; virtual;
    procedure KeyDown(var Key: Word; Shift: TShiftState); virtual;
    procedure KeyPress(var Key: Char); virtual;
    procedure KeyUp(var Key: Word; Shift: TShiftState); virtual;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); virtual;
    procedure MouseLeave; virtual;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); virtual;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); virtual;
    function MouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean; virtual;
    function MouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean; virtual;
    function NotHandleMouseMove(P: TPoint): Boolean; virtual;
    function ProcessApplicationButtonMouseDown(Button: TMouseButton; AShift: TShiftState): Boolean;
    procedure ProcessContextsOnMouseDown(AIsDoubleClick: Boolean);
    procedure ProcessTabClick(ATab: TdxRibbonTab; Button: TMouseButton; Shift: TShiftState);
    procedure ProcessTabOnMouseDown(AButton: TMouseButton; AShift: TShiftState);
    procedure ScrollGroups(AScrollLeft, AOnTimer: Boolean);
    procedure ScrollTabs(AScrollLeft, AOnTimer: Boolean);
    procedure ShowTabDesignMenu; virtual;
    procedure StartScroll(AScrollKind: TdxRibbonHitTest);
    procedure UpdateButtonsStates; virtual;

    property HintInfo: TdxRibbonHitInfo read FHintInfo write SetHintInfo;
    property HitInfo: TdxRibbonHitInfo read FHitInfo;
    property HotObject: TdxRibbonHitTest read FHotObject write FHotObject;
    property PressedObject: TdxRibbonHitTest read FPressedObject write SetPressedObject;
  public
    constructor Create(ARibbon: TdxCustomRibbon); virtual;
    destructor Destroy; override;
    function NextTab(ATab: TdxRibbonTab): TdxRibbonTab;
    function PrevTab(ATab: TdxRibbonTab): TdxRibbonTab;

    property ApplicationButton: TdxRibbonApplicationButton read GetApplicationButton;
    property ApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo read GetApplicationButtonViewInfo;
    property ApplicationMenuState: TdxRibbonApplicationMenuState read GetApplicationMenuState;
    property HotButton: TdxRibbonCustomButtonViewInfo read FHotButton write SetHotButton;
    property PressedButton: TdxRibbonCustomButtonViewInfo read FPressedButton write SetPressedButton;
    property Ribbon: TdxCustomRibbon read FRibbon;
    property ScrollKind: TdxRibbonHitTest read FScrollKind;
    property ViewInfo: TdxRibbonViewInfo read GetViewInfo;
  end;

  { TdxRibbonGroupsDockControlScrollButtonViewInfo }

  TdxRibbonGroupsDockControlScrollButtonViewInfo = class(TdxRibbonCustomScrollButtonViewInfo)
  protected
    procedure DrawButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    procedure DrawButtonGlyph(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
  public
    procedure Draw(ACanvas: TcxCanvas); override;
    function GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean; override;
  end;

  { TdxRibbonGroupsDockControlSiteViewInfo }

  TdxRibbonGroupsDockControlSiteViewInfo = class(TdxRibbonButtonsContainerViewInfo)
  private
    FMinimizeRibbonButton: TdxRibbonMinimizeButtonViewInfo;
    FSite: TdxRibbonGroupsDockControlSite;
    FTabGroupsScrollButtonLeft: TdxRibbonGroupsDockControlScrollButtonViewInfo;
    FTabGroupsScrollButtonRight: TdxRibbonGroupsDockControlScrollButtonViewInfo;
    FTabGroupsScrollButtons: TdxRibbonScrollButtons;
    function GetRibbonActiveTab: TdxRibbonTab;
    function GetRibbonViewInfo: TdxRibbonViewInfo;
  protected
    procedure CalculateButtonsBounds(const ABounds: TRect); override;
    procedure DrawRibbonParts(ACanvas: TcxCanvas);
  public
    constructor Create(ASite: TdxRibbonGroupsDockControlSite); reintroduce; virtual;
    procedure Calculate(const ABounds: TRect); override;
    procedure Draw(ACanvas: TcxCanvas); override;
    procedure InvalidateRect(const R: TRect); override;
    function GetMinimizeRibbonButtonSize: TSize; virtual;
    //
    property RibbonActiveTab: TdxRibbonTab read GetRibbonActiveTab;
    property RibbonViewInfo: TdxRibbonViewInfo read GetRibbonViewInfo;
    property TabGroupsScrollButtons: TdxRibbonScrollButtons read FTabGroupsScrollButtons;
    property TabGroupsScrollButtonLeft: TdxRibbonGroupsDockControlScrollButtonViewInfo read FTabGroupsScrollButtonLeft;
    property TabGroupsScrollButtonRight: TdxRibbonGroupsDockControlScrollButtonViewInfo read FTabGroupsScrollButtonRight;
  end;

  { TdxRibbonGroupsDockControlSite }

  TdxRibbonGroupsDockControlSite = class(TcxControl)
  private
    FRibbon: TdxCustomRibbon;
    FViewInfo: TdxRibbonGroupsDockControlSiteViewInfo;
    function GetDockControl: TdxRibbonGroupsDockControl;
  protected
    // IdxGestureClient
    function AllowPan(AScrollKind: TScrollBarKind): Boolean; override;
    procedure BeginGestureScroll(APos: TPoint); override;
    procedure GestureScroll(ADeltaX, ADeltaY: Integer); override;
    function IsPanArea(const APoint: TPoint): Boolean; override;
    function NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean; override;
    // IdxGestureOwner
    function IsGestureTarget(AWnd: THandle): Boolean; override;

    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure DoCancelMode; override;
    function DoMouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean; override;
    function DoMouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean; override;
    function MayFocus: Boolean; override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    function NeedsScrollBars: Boolean; override;
    procedure Paint; override;
    procedure SetRedraw(ARedraw: Boolean);

    property Ribbon: TdxCustomRibbon read FRibbon;
    property DockControl: TdxRibbonGroupsDockControl read GetDockControl;
    property ViewInfo: TdxRibbonGroupsDockControlSiteViewInfo read FViewInfo;
  public
    constructor Create(ARibbon: TdxCustomRibbon); reintroduce;
    destructor Destroy; override;
    function CanFocus: Boolean; override;
  end;

  { TdxRibbonFadingOptions }

  TdxRibbonOptionsFading = class(TPersistent)
  private
    FApplicationButton: TdxFadingOptions;
    FTabs: TdxFadingOptions;
    FTabGroups: TdxFadingOptions;
    FBarItems: TdxFadingOptions;

    procedure SetApplicationButton(AValue: TdxFadingOptions);
    procedure SetBarItems(AValue: TdxFadingOptions);
    procedure SetTabGroups(AValue: TdxFadingOptions);
    procedure SetTabs(AValue: TdxFadingOptions);
  public
    constructor Create; virtual;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    property ApplicationButton: TdxFadingOptions read FApplicationButton write SetApplicationButton;
    property BarItems: TdxFadingOptions read FBarItems write SetBarItems;
    property TabGroups: TdxFadingOptions read FTabGroups write SetTabGroups;
    property Tabs: TdxFadingOptions read FTabs write SetTabs;
  end;

  { TdxRibbonMergeData }

  TdxRibbonMergeData = class(TdxRibbonCustomMergeData)
  public
    ActiveTabBeforeMerging: TdxRibbonTab;
    MergedWith: TdxCustomRibbon;
  end;

  { TdxRibbonTouchModeHelper }

  TdxRibbonTouchModeHelper = class
  private
    FRibbon: TdxCustomRibbon;
  public
    constructor Create(ARibbon: TdxCustomRibbon);
    procedure AdjustFormBorderIconSize(AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean; var ASize: TSize); virtual;
    procedure AdjustFormCaptionHeight(var AValue: Integer); virtual;
    procedure AdjustMargins(var AMargins: TRect; AMaxTargetValue: Integer); virtual;
    procedure AdjustPartOffsets(APart: Integer; var AValue: TRect); virtual;
    procedure AdjustPartSize(APart: Integer; var AValue: Integer); virtual;
    function IsEnabled: Boolean;
    //
    property Ribbon: TdxCustomRibbon read FRibbon;
  end;

  { TdxCustomRibbon }

  TdxRibbonEvent = procedure(Sender: TdxCustomRibbon) of object;
  TdxRibbonApplicationMenuClickEvent = procedure (Sender: TdxCustomRibbon;
    var AHandled: Boolean) of object;
  TdxRibbonTabChangingEvent = procedure(Sender: TdxCustomRibbon;
    ANewTab: TdxRibbonTab; var Allow: Boolean) of object;
  TdxRibbonTabGroupNotifyEvent = procedure(Sender: TdxCustomRibbon;
    ATab: TdxRibbonTab; AGroup: TdxRibbonTabGroup) of object;
  TdxRibbonHideMinimizedByClickEvent = procedure(Sender: TdxCustomRibbon;
    AWnd: HWND; AShift: TShiftState; const APos: TPoint;
    var AAllowProcessing: Boolean) of object;

  TdxRibbonInternalState = (risCreating, risAppMenuActive);
  TdxRibbonInternalStates = set of TdxRibbonInternalState;

  TdxCustomRibbon = class(TcxControl,
    IdxSkin,
    IdxRibbonFormClient,
    IdxRibbonFormNonClientPart,
    IdxRibbonFormNonClientHelper,
    IdxRibbonFormNonClientDraw,
    IdxRibbonMouseWheelReceiver,
    IdxFormKeyPreviewListener,
    IdxBarManagerMergeOperationHandler,
    IdxBarAccessibleObject)
  private
    FActiveTab: TdxRibbonTab;
    FApplicationButton: TdxRibbonApplicationButton;
    FBarManager: TdxBarManager;
    FColorScheme: TdxCustomRibbonSkin;
    FColorSchemeAccent: TdxRibbonColorSchemeAccent;
    FColorSchemeHandlers: TcxEventHandlerCollection;
    FContexts: TdxRibbonContexts;
    FController: TdxRibbonController;
    FDocumentName: TCaption;
    FEnableTabAero: Boolean;
    FFading: Boolean;
    FFonts: TdxRibbonFonts;
    FFormCaptionHelper: TdxRibbonFormCaptionHelper;
    FGroupsDockControlSite: TdxRibbonGroupsDockControlSite;
    FGroupsPainter: TdxRibbonBarPainter;
    FHelpButton: TdxRibbonHelpButton;
    FHighlightedTab: TdxRibbonTab;
    FHorizontalNavigationList: TInterfaceList;
    FInternalItems: TComponentList;
    FInternalState: TdxRibbonInternalStates;
    FListeners: TInterfaceList;
    FLoadedActiveTab: TdxRibbonTab;
    FLoadedHeight: Integer;
    FLockCount: Integer;
    FLockedCancelHint: Boolean;
    FLockModified: Boolean;
    FMergeData: TdxRibbonMergeData;
    FMinimizeOnTabDblClick: Boolean;
    FOptionsFading: TdxRibbonOptionsFading;
    FPainter: TdxRibbonPainter;
    FPopupMenuItems: TdxRibbonPopupMenuItems;
    FQuickAccessToolbar: TdxRibbonQuickAccessToolbar;
    FRibbonFormNonClientParts: TObjectList;
    FShowTabGroups: Boolean;
    FShowTabHeaders: Boolean;
    FSupportNonClientDrawing: Boolean;
    FTabGroupsPopupWindow: TdxRibbonTabGroupsPopupWindow;
    FTabs: TdxRibbonTabCollection;
    FTabsLoaded: Boolean;
    FTouchModeHelper: TdxRibbonTouchModeHelper;
    FViewInfo: TdxRibbonViewInfo;
    // Accessibility
    FIAccessibilityHelper: IdxBarAccessibilityHelper;
    FAffiliatedBarControlsForAccessibility: TComponentList; 

    FOnApplicationMenuClick: TdxRibbonApplicationMenuClickEvent;
    FOnHelpButtonClick: TdxRibbonEvent;
    FOnHideMinimizedByClick: TdxRibbonHideMinimizedByClickEvent;
    FOnMinimizedChanged: TdxRibbonEvent;
    FOnMoreCommandsExecute: TdxRibbonEvent;
    FOnTabChanged: TdxRibbonEvent;
    FOnTabChanging: TdxRibbonTabChangingEvent;
    FOnTabGroupCollapsed: TdxRibbonTabGroupNotifyEvent;
    FOnTabGroupExpanded: TdxRibbonTabGroupNotifyEvent;

    procedure CheckDrawRibbonFormStatusBarBorders(ACanvas: TcxCanvas;
      const AData: TdxRibbonFormData; const ABordersWidth: TRect);
    procedure DrawApplicationMenuHeader(ADC: THandle; AIsClientArea: Boolean);
    function GetActiveTab: TdxRibbonTab;
    function GetApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo;
    function GetApplicationMenuState: TdxRibbonApplicationMenuState;
    function GetColorSchemeName: string;
    function GetHelpButtonScreenTip: TdxScreenTip;
    function GetHidden: Boolean;
    function GetIniSection(const ADelimiter: string; const ASection: string): string;
    function GetIsPopupGroupsMode: Boolean;
    function GetNextActiveTab(ATab: TdxRibbonTab): TdxRibbonTab;
    function GetRibbonForm: TdxCustomRibbonForm;
    function GetStyle: TdxRibbonStyle;
    function GetTabCount: Integer;
    function GetVisibleTab(Index: Integer): TdxRibbonTab;
    function GetVisibleTabCount: Integer;
    procedure InitCustomizePopupMenu(AItemLinks: TdxBarItemLinks);
    procedure InitColorScheme;
    function IsOnRibbonMDIForm: Boolean;
    procedure InternalCloseTabGroupsPopupWindow(AAllowAnimation: Boolean = True);
    procedure RibbonFormInvalidate;
    procedure SetActiveTab(Value: TdxRibbonTab);
    procedure SetOptionsFading(AValue: TdxRibbonOptionsFading);
    procedure SetApplicationButton(AValue: TdxRibbonApplicationButton);
    procedure SetBarManager(Value: TdxBarManager);
    procedure SetColorScheme(Value: TdxCustomRibbonSkin);
    procedure SetColorSchemeAccent(AValue: TdxRibbonColorSchemeAccent);
    procedure SetColorSchemeName(const Value: string);
    procedure SetDocumentName(const Value: TCaption);
    procedure SetEnableTabAero(AValue: Boolean);
    procedure SetFading(const Value: Boolean);
    procedure SetFonts(const Value: TdxRibbonFonts);
    procedure SetHelpButton(const Value: TdxRibbonHelpButton);
    procedure SetHelpButtonScreenTip(const Value: TdxScreenTip);
    procedure SetHighlightedTab(const Value: TdxRibbonTab);
    procedure SetPopupMenuItems(const Value: TdxRibbonPopupMenuItems);
    procedure SetQuickAccessToolbar(const Value: TdxRibbonQuickAccessToolbar);
    procedure SetShowTabGroups(const Value: Boolean);
    procedure SetShowTabHeaders(const Value: Boolean);
    procedure SetStyle(AValue: TdxRibbonStyle);
    procedure SetSupportNonClientDrawing(const Value: Boolean);
    procedure SetTabs(Value: TdxRibbonTabCollection);
    procedure UpdateColorSchemeListeners;
    procedure UpdateNonClientDrawing;

    procedure CMSelectAppMenuFirstItemControl(var Message: TMessage); message DXM_BAR_SELECTAPPMENUFIRSTITEMCONTROL;
    procedure CMShowKeyTips(var Message: TMessage); message DXM_BAR_SHOWKEYTIPS;
    procedure DXMShowApplicationMenu(var Message: TMessage); message DXM_RIBBON_SHOWAPPLICATIONMENU;
    procedure WMGetObject(var Message: TMessage); message WM_GETOBJECT;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;

    procedure BarManagerAfterChange;
    procedure BarManagerBeforeChange;
    procedure BarManagerLoadIni(Sender: TObject; const AEventArgs);
    procedure BarManagerSaveIni(Sender: TObject; const AEventArgs);

    procedure MDIStateChanged(Sender: TObject; const AEventArgs);
    procedure SystemFontChanged(Sender: TObject; const AEventArgs);
    procedure UpdateColorScheme;
    procedure SetContexts(const Value: TdxRibbonContexts);

    // Accessibility
    function GetIAccessibilityHelper: IdxBarAccessibilityHelper;
    function GetQATIAccessibilityHelper: IdxBarAccessibilityHelper;
    function GetTabsIAccessibilityHelper: IdxBarAccessibilityHelper;
  protected
    function CalculateFormCaptionHeight(AIsQATAtNonClientArea: Boolean): Integer; virtual;
    // IdxGestureClient
    function AllowPan(AScrollKind: TScrollBarKind): Boolean; override;
    procedure GestureScroll(ADeltaX, ADeltaY: Integer); override;
    function IsPanArea(const APoint: TPoint): Boolean; override;
    function NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean; override;
    // IdxRibbonFormNonClientHelper
    procedure AdjustRibbonFormBorderIconSize(AIcon: TdxRibbonBorderDrawIcon;
      AIsToolWindow: Boolean; var ASize: TSize); virtual;
    procedure DrawRibbonFormBackground(DC: HDC; const ARect: TRect);
    procedure DrawRibbonFormCaption(ACanvas: TcxCanvas; const ABounds: TRect;
      const ACaption: string; const AData: TdxRibbonFormData);
    procedure DrawRibbonFormBorderIcon(ACanvas: TcxCanvas; const ABounds: TRect;
      AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState);
    procedure DrawRibbonFormBorders(ACanvas: TcxCanvas;
      const AData: TdxRibbonFormData; const ABordersWidth: TRect);
    procedure GetApplicationMenuTabOrderList(List: TList);
    function GetBarManager: TdxBarManager;
    function GetBarPainter: TdxBarPainter;
    function GetRibbonFormCaptionAreaExtention: Integer; virtual;
    function GetRibbonFormCaptionHeight: Integer; virtual;
    function GetRibbonFormCaptionHeightForHiddenRibbon: Integer; virtual;
    function GetRibbonFormColor: TColor;
    function GetRibbonFormExtendedCaptionAreaRegion: HRGN; virtual;
    function GetRibbonLoadedHeight: Integer;
    function GetRibbonNonClientAreaObjectsRegion: HRGN;
    function GetRibbonQATNonClientAreaBounds: TRect;
    function GetRibbonStyle: TdxRibbonStyle;
    function GetStatusBarInterface: IUnknown;
    function GetTaskbarCaption: TCaption; virtual;
    function GetValidPopupMenuItems: TdxRibbonPopupMenuItems; virtual;
    function GetWindowBordersWidth: TRect;
    function HasExternalRibbonFormShadow: Boolean;
    function HasHelpButton: Boolean;
    function HasStatusBar: Boolean;
    procedure UpdateNonClientArea; virtual;
    function UseRoundedWindowCorners: Boolean;
    // IdxRibbonFormClient
    procedure RibbonFormCaptionChanged; virtual;
    procedure RibbonFormResized; virtual;
    //IdxSkin
    procedure IdxSkin.DrawBackground = SkinDrawBackground;
    procedure IdxSkin.DrawBackgroundEx = SkinDrawBackgroundEx;
    procedure IdxSkin.DrawCaption = SkinDrawCaption;
    function IdxSkin.GetIsAlphaUsed = SkinGetIsAlphaUsed;
    function IdxSkin.GetCaptionRect = SkinGetCaptionRect;
    function IdxSkin.GetContentOffsets = SkinGetContentOffsets;
    function IdxSkin.GetName = SkinGetName;
    function IdxSkin.GetPartColor = SkinGetPartColor;
    function IdxSkin.GetPartSize = SkinGetPartSize;
    procedure DrawTabGroupBackground(DC: HDC; const ARect: TRect; AState: Integer; AIsInPopup: Boolean);
    function GetBarItemControlFadingOptions: TdxFadingOptions;
    function GetGroupCaptionHeight: Integer;
    function GetGroupContentHeight: Integer;
    function GetGroupHeight: Integer;
    function GetGroupRowHeight: Integer;
    //
    procedure SkinDrawBackground(DC: HDC; const ARect: TRect; APart, AState: Integer);
    procedure SkinDrawBackgroundEx(DC: HDC; const ARect: TRect;
      const AContentRect: TRect; APart: Integer; AState: Integer = 0);
    procedure SkinDrawCaption(DC: HDC; const ACaption: string; const ARect: TRect;
      APart, AState: Integer);
    function SkinGetCaptionRect(const ARect: TRect; APart: Integer): TRect;
    function SkinGetContentOffsets(APart: Integer): TRect;
    function SkinGetIsAlphaUsed(APart: Integer): Boolean;
    function SkinGetName: string;
    function SkinGetPartColor(APart: Integer; AState: Integer = 0): TColor;
    function SkinGetPartSize(APart: Integer): Integer;
    // IdxRibbonMouseWheelReceiver
    function CanProcessMouseWheel: Boolean;
    //IdxFormKeyPreviewListener
    procedure FormKeyDown(var Key: Word; Shift: TShiftState);
    //IdxBarAccessibleObject
    function GetAccessibilityHelper: IdxBarAccessibilityHelper;
    // IdxBarManagerMergeOperationHandler
    procedure ProcessMergeOperation(ABarManager: TdxBarManager;
      AOperation: TdxBarMergeOperation; var AHandled: Boolean);
    //IdxRibbonFormNonClientDraw
    procedure IdxRibbonFormNonClientDraw.Add = RibbonFormNonClientDrawAdd;
    procedure IdxRibbonFormNonClientDraw.Remove = RibbonFormNonClientDrawRemove;
    procedure RibbonFormNonClientDrawAdd(AObject: TObject);
    procedure RibbonFormNonClientDrawRemove(AObject: TObject);

    procedure AfterApplicationMenuPopup;
    procedure BeforeApplicationMenuPopup;
    procedure BoundsChanged; override;
    function CanResize(var NewWidth, NewHeight: Integer): Boolean; override;
    function CanScrollTabs: Boolean;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWindowHandle(const Params: TCreateParams); override;
    procedure DoCancelMode; override;
    procedure DoMinimizeChanged; virtual;
    procedure LookAndFeelChanged(Sender: TcxLookAndFeel;
      AChangedValues: TcxLookAndFeelValues); override;
    procedure DoContextPopup(MousePos: TPoint; var Handled: Boolean); override;
    function DoMouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean; override;
    function DoMouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean; override;
    procedure FontChanged; override;
  {$IFNDEF DELPHI12}
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
  {$ENDIF}
    function GetDesignHitTest(X, Y: Integer; Shift: TShiftState): Boolean; override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
    procedure KeyUp(var Key: Word; Shift: TShiftState); override;
    procedure Loaded; override;
    function MayFocus: Boolean; override;
    procedure Modified; override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    function NeedsScrollBars: Boolean; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure Paint; override;
    procedure ReadState(Reader: TReader); override;
    procedure SetName(const Value: TComponentName); override;
    procedure SetParent(AParent: TWinControl); override;
    procedure VisibleChanged; override;
    procedure Updating; override;
    procedure Updated; override;

    // Merging
    function CreateContextAsByMerging(ASourceContext: TdxRibbonContext): TdxRibbonContext; virtual;
    function CreateTabAsByMerging(ASourceTab: TdxRibbonTab): TdxRibbonTab; virtual;
    function CreateToolbarAsByMerging: TdxBar; virtual;
    procedure UnmergeBeforeDestroy; virtual;

    function AddGroupButtonToQAT(ABar: TdxBar): TdxRibbonQuickAccessGroupButton;
    procedure CancelUpdate;
    function CanFade: Boolean;
    function CanPaint: Boolean;
    function CreateApplicationButton: TdxRibbonApplicationButton; virtual;
    function CreateController: TdxRibbonController; virtual;
    function CreateFormCaptionHelper: TdxRibbonFormCaptionHelper; virtual;
    function CreateGroupsPainter: TdxRibbonBarPainter; virtual;
    function CreateHelpButton: TdxRibbonHelpButton; virtual;
    function CreatePainter: TdxRibbonPainter; virtual;
    function CreateQuickAccessToolbar: TdxRibbonQuickAccessToolbar; virtual;
    function CreateTouchModeHelper: TdxRibbonTouchModeHelper; virtual;
    function CreateViewInfo: TdxRibbonViewInfo; virtual;
    procedure DesignAddTabGroup(ATab: TdxRibbonTab; ANewToolbar: Boolean);
    function DoApplicationMenuClick: Boolean;
    procedure DoHelpButtonClick; virtual;
    function DoHideMinimizedByClick(AWnd: HWND; AShift: TShiftState; const APos: TPoint): Boolean; virtual;
    function DoTabChanging(ANewTab: TdxRibbonTab): Boolean; virtual;
    procedure DoMoreCommandsExecute; virtual;
    procedure DoTabChanged; virtual;
    procedure DoTabGroupCollapsed(ATab: TdxRibbonTab; AGroup: TdxRibbonTabGroup); virtual;
    procedure DoTabGroupExpanded(ATab: TdxRibbonTab; AGroup: TdxRibbonTabGroup); virtual;

    function GetBar(ACustomizingBarControl: TCustomdxBarControl): TdxBar;
    function GetNextHorizontalAccessibleObject(ACurrentObject: IdxBarAccessibilityHelper;
      ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;
    function GetTabClass: TdxRibbonTabClass; virtual;
    function IsAutoHidden: Boolean;
    function IsAutoHideModeActive: Boolean;
    function IsBarManagerValid: Boolean;
    function IsHelpButtonPlacedOnTabsArea: Boolean;
    function IsLocked: Boolean;
    function IsQuickAccessToolbarValid: Boolean;
    procedure InitializeRibbonForm;
    procedure PopulatePopupMenuItems(ALinks: TdxBarItemLinks;
      AItems: TdxRibbonPopupMenuItems; AOnClick: TNotifyEvent);
    procedure PopupMenuItemClick(Sender: TObject);
    procedure UpdateFormActionControl(ASetControl: Boolean);
    procedure SetRedraw(ARedraw: Boolean);
    procedure ShowCustomizePopup; virtual;
    procedure UpdateActiveTab;
    procedure UpdateControlsVisibility;
    procedure UpdateHorizontalNavigationList;
    procedure UpdateHeight; virtual;
    procedure UpdateHiddenActiveTabDockControl;

    procedure AddTab(ATab: TdxRibbonTab);
    procedure RemoveTab(ATab: TdxRibbonTab);
    procedure SetNextActiveTab(ATab: TdxRibbonTab);

    procedure Changed;
    procedure FullInvalidate;
    procedure RecalculateBars;

    // Accessibility
    procedure AddAffiliatedBarControlForAccessibility(ABarControl: TCustomdxBarControl);
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; virtual;
    property QATIAccessibilityHelper: IdxBarAccessibilityHelper read GetQATIAccessibilityHelper;
    property TabsIAccessibilityHelper: IdxBarAccessibilityHelper read GetTabsIAccessibilityHelper;

    property ApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo read GetApplicationButtonViewInfo;
    property FormCaptionHelper: TdxRibbonFormCaptionHelper read FFormCaptionHelper;
    property GroupsPainter: TdxRibbonBarPainter read FGroupsPainter;
    property HighlightedTab: TdxRibbonTab read FHighlightedTab write SetHighlightedTab;
    property HorizontalNavigationList: TInterfaceList read FHorizontalNavigationList;
    property LockedCancelHint: Boolean read FLockedCancelHint write FLockedCancelHint;
    property RibbonFormNonClientParts: TObjectList read FRibbonFormNonClientParts;
    property TabGroupsPopupWindow: TdxRibbonTabGroupsPopupWindow read FTabGroupsPopupWindow;

    property ApplicationMenuState: TdxRibbonApplicationMenuState read GetApplicationMenuState;
    property Controller: TdxRibbonController read FController;
    property Fading: Boolean read FFading write SetFading default False;
    property GroupsDockControlSite: TdxRibbonGroupsDockControlSite read FGroupsDockControlSite;
    property InternalState: TdxRibbonInternalStates read FInternalState;
    property MergeData: TdxRibbonMergeData read FMergeData;
    property Painter: TdxRibbonPainter read FPainter;
    property RibbonForm: TdxCustomRibbonForm read GetRibbonForm;
    property TouchModeHelper: TdxRibbonTouchModeHelper read FTouchModeHelper;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure AfterConstruction; override;
    procedure BeforeDestruction; override;
    function ApplicationMenuPopup: Boolean;
    function AreGroupsVisible: Boolean;
    procedure BeginUpdate;
    function CanFocus: Boolean; override;
    procedure CheckHide;
    function ContainsToolBar(AToolBar: TdxBar): Boolean;
    procedure EndUpdate;
  {$IFDEF DELPHI12}
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
  {$ENDIF}
    function GetTabAtPos(X, Y: Integer): TdxRibbonTab;

    procedure CloseTabGroupsPopupWindow;
    procedure ShowTabGroupsPopupWindow;

    procedure AddListener(AListener: IdxRibbonListener);
    procedure RemoveListener(AListener: IdxRibbonListener);

    function IsMerged: Boolean; virtual;
    procedure Merge(ARibbon: TdxCustomRibbon; AMergeOptions: TdxRibbonMergeOptions = dxRibbonDefaultMergeOptions); virtual;
    procedure Unmerge(ARibbon: TdxCustomRibbon = nil); virtual;

    property ActiveTab: TdxRibbonTab read GetActiveTab write SetActiveTab;
    property ApplicationButton: TdxRibbonApplicationButton read FApplicationButton write SetApplicationButton;
    property BarManager: TdxBarManager read FBarManager write SetBarManager;
    property ColorScheme: TdxCustomRibbonSkin read FColorScheme write SetColorScheme;
    property ColorSchemeAccent: TdxRibbonColorSchemeAccent read FColorSchemeAccent write SetColorSchemeAccent default rcsaYellow;
    property ColorSchemeHandlers: TcxEventHandlerCollection read FColorSchemeHandlers;
    property ColorSchemeName: string read GetColorSchemeName write SetColorSchemeName stored True;
    property DocumentName: TCaption read FDocumentName write SetDocumentName;
    property EnableTabAero: Boolean read FEnableTabAero write SetEnableTabAero default True;
    property Fonts: TdxRibbonFonts read FFonts write SetFonts;
    property HelpButton: TdxRibbonHelpButton read FHelpButton write SetHelpButton;
    property Hidden: Boolean read GetHidden;
    property IAccessibilityHelper: IdxBarAccessibilityHelper read GetIAccessibilityHelper;
    property IsPopupGroupsMode: Boolean read GetIsPopupGroupsMode;
    property LockCount: Integer read FLockCount;
    property MinimizeOnTabDblClick: Boolean read FMinimizeOnTabDblClick write FMinimizeOnTabDblClick default True;
    property OptionsFading: TdxRibbonOptionsFading read FOptionsFading write SetOptionsFading;
    property QuickAccessToolbar: TdxRibbonQuickAccessToolbar read FQuickAccessToolbar write SetQuickAccessToolbar;
    property PopupMenuItems: TdxRibbonPopupMenuItems read FPopupMenuItems write SetPopupMenuItems default dxRibbonDefaultPopupMenuItems;
    property Contexts: TdxRibbonContexts read FContexts write SetContexts;
    property ShowTabGroups: Boolean read FShowTabGroups write SetShowTabGroups default True;
    property ShowTabHeaders: Boolean read FShowTabHeaders write SetShowTabHeaders default True;
    property Style: TdxRibbonStyle read GetStyle write SetStyle default rs2007;
    property SupportNonClientDrawing: Boolean read FSupportNonClientDrawing write SetSupportNonClientDrawing default False;
    property TabCount: Integer read GetTabCount;
    property Tabs: TdxRibbonTabCollection read FTabs write SetTabs;
    property ViewInfo: TdxRibbonViewInfo read FViewInfo;
    property VisibleTabCount: Integer read GetVisibleTabCount;
    property VisibleTabs[Index: Integer]: TdxRibbonTab read GetVisibleTab;

    //obsolete HelpButtonOptions
    property HelpButtonScreenTip: TdxScreenTip read GetHelpButtonScreenTip write SetHelpButtonScreenTip;

    property OnApplicationMenuClick: TdxRibbonApplicationMenuClickEvent read FOnApplicationMenuClick write FOnApplicationMenuClick;
    property OnHelpButtonClick: TdxRibbonEvent read FOnHelpButtonClick write FOnHelpButtonClick;
    property OnHideMinimizedByClick: TdxRibbonHideMinimizedByClickEvent read FOnHideMinimizedByClick write FOnHideMinimizedByClick;
    property OnMinimizedChanged: TdxRibbonEvent read FOnMinimizedChanged write FOnMinimizedChanged;
    property OnMoreCommandsExecute: TdxRibbonEvent read FOnMoreCommandsExecute write FOnMoreCommandsExecute;
    property OnTabChanged: TdxRibbonEvent read FOnTabChanged write FOnTabChanged;
    property OnTabChanging: TdxRibbonTabChangingEvent read FOnTabChanging write FOnTabChanging;
    property OnTabGroupCollapsed: TdxRibbonTabGroupNotifyEvent read FOnTabGroupCollapsed write FOnTabGroupCollapsed;
    property OnTabGroupExpanded: TdxRibbonTabGroupNotifyEvent read FOnTabGroupExpanded write FOnTabGroupExpanded;
  end;

  { TdxRibbon }

  TdxRibbon = class(TdxCustomRibbon)
  published
    //obsolete
    property HelpButtonScreenTip;

    property OptionsFading;
    property ApplicationButton;
    property BarManager;
    property Style; 
    property ColorSchemeAccent;
    property ColorSchemeName;
    property DocumentName;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property EnableTabAero;
    property Fonts;
    property HelpButton;
    property MinimizeOnTabDblClick;
    property PopupMenuItems;
    property QuickAccessToolbar;
    property ShowTabGroups;
    property ShowTabHeaders;
    property SupportNonClientDrawing;
    property Contexts;
    property Tabs;
    property TabOrder;
    property TabStop;

    property OnApplicationMenuClick;
    property OnHelpButtonClick;
    property OnHideMinimizedByClick;
    property OnMinimizedChanged;
    property OnMoreCommandsExecute;
    property OnTabChanged;
    property OnTabChanging;
    property OnTabGroupCollapsed;
    property OnTabGroupExpanded;

    property OnClick;
  {$IFDEF DELPHI5}
    property OnContextPopup;
  {$ENDIF}
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseEnter;
    property OnMouseLeave;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseWheel;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnResize;
    property OnStartDock;
    property OnStartDrag;
  end;

  { TdxRibbonQuickAccessToolbarHelper }

  TdxRibbonQuickAccessToolbarHelper = class(TObject)
  public
    class function HasGroupButtonForToolbar(AQATLinks: TdxBarItemLinks; AToolbar: TdxBar): Boolean;
    class function IsToolbarDockedInRibbon(ARibbon: TdxCustomRibbon; AToolbar: TdxBar): Boolean;
  end;

  { TdxRibbonQuickAccessGroupButton }

  TdxRibbonQuickAccessGroupButton = class(TdxBarItem)
  private
    FToolbar: TdxBar;
    function GetActualToolbar: TdxBar;
    procedure SetToolbar(Value: TdxBar);
  protected
    function CanBePlacedOn(AParentKind: TdxBarItemControlParentKind;
      AToolbar: TdxBar; out AErrorText: string): Boolean; override;
    function GetCaption: string; override;
    function HasGroupButtonForToolbar(AParentBar, AToolbar: TdxBar): Boolean;
    function IsCaptionStored: Boolean; override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetCaption(const Value: string); override;
    //
    property ActualToolbar: TdxBar read GetActualToolbar;
  public
    function IsToolbarAcceptable(AToolbar: TdxBar): Boolean;
  published
    property Toolbar: TdxBar read FToolbar write SetToolbar;
  end;

  { TdxRibbonQuickAccessGroupButtonControl }

  TdxRibbonQuickAccessGroupButtonControl = class(TdxBarButtonLikeControl)
  private
    FPopupBarControl: TdxBarPopupControl;
    function GetItem: TdxRibbonQuickAccessGroupButton;
  protected
    procedure CalcDrawParams(AFull: Boolean = True); override;
    function CanActivate: Boolean; override;
    function CanDestroyOnClick: Boolean; override;
    procedure ClosePopup;
    procedure ControlClick(AByMouse: Boolean; AKey: Char = #0); override;
    procedure DoCloseUp(AHadSubMenuControl: Boolean); override;
    procedure DoDropDown(AByMouse: Boolean); override;
    procedure DoPaint(ARect: TRect; PaintType: TdxBarPaintType); override;
    procedure DropDown(AByMouse: Boolean); override;
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; override;
    function GetCurrentImage(AViewSize: TdxBarItemControlViewSize; ASelected: Boolean;
      out ACurrentGlyph: TBitmap; out ACurrentImages: TCustomImageList; out ACurrentImageIndex: Integer): Boolean; override;
    function GetHint: string; override;
    function GetViewStructure: TdxBarItemControlViewStructure; override;
    function IsDropDown: Boolean; override;
  public
    destructor Destroy; override;
    function IsDroppedDown: Boolean; override;
    property Item: TdxRibbonQuickAccessGroupButton read GetItem;
  end;

  { TdxRibbonQuickAccessGroupButtonPopupBarControl }

  TdxRibbonQuickAccessGroupButtonPopupBarControl = class(TdxRibbonCollapsedGroupPopupBarControl)
  private
    FGroupButtonControl: TdxRibbonQuickAccessGroupButtonControl;
    FIsActiveChangeLocked: Boolean;
  protected
    function CanActiveChange: Boolean; override;
    procedure CreateWnd; override;
    procedure DestroyWnd; override;
    procedure FocusItemControl(AItemControl: TdxBarItemControl); override;
    function GetBehaviorOptions: TdxBarBehaviorOptions; override;
    function IsAllowContextPaint: Boolean; override;
  public
    constructor CreateForPopup(AGroupButtonControl: TdxRibbonQuickAccessGroupButtonControl); reintroduce; virtual;
    procedure CloseUp; override;
    procedure HideAllByEscape; override;
  end;

  { TdxAddGroupButtonEditor }

  TdxAddGroupButtonEditor = class(TdxAddSubItemEditor)
  protected
    class function GetAddedItemClass(const AAddedItemName: string): TdxBarItemClass; override;
    class function GetPopupItemCaption: string; override;
  end;

  { TdxRibbonAccessibilityHelper }

  TdxRibbonAccessibilityHelper = class(TdxBarAccessibilityHelper)
  private
    FAccessibilityChilds: TList;
    FKeyTipWindowsManager: IdxBarKeyTipWindowsManager;
    function GetRibbon: TdxCustomRibbon;
    function GetTabsAreaButtonsViewInfo: TdxRibbonButtonsContainerViewInfo;
  protected
    // IdxBarAccessibilityHelper
    function AreKeyTipsSupported(out AKeyTipWindowsManager: IdxBarKeyTipWindowsManager): Boolean; override;
    function GetBarManager: TdxBarManager; override;
    function GetDefaultAccessibleObject: IdxBarAccessibilityHelper; override;

    function GetChild(AIndex: Integer): TcxAccessibilityHelper; override;
    function GetChildCount: Integer; override;
    function GetChildIndex(AChild: TcxAccessibilityHelper): Integer; override;
    function GetOwnerObjectWindow: HWND; override;
    function GetState(AChildID: TcxAccessibleSimpleChildElementID): Integer; override;

    function LogicalNavigationGetChild(AIndex: Integer): TdxBarAccessibilityHelper; override;
    function LogicalNavigationGetChildIndex(AChild: TdxBarAccessibilityHelper): Integer; override;

    property Ribbon: TdxCustomRibbon read GetRibbon;
    property TabsAreaButtonsViewInfo: TdxRibbonButtonsContainerViewInfo read GetTabsAreaButtonsViewInfo;
  public
    constructor Create(AOwnerObject: TObject); override;
    destructor Destroy; override;

    function GetScreenBounds(AChildID: TcxAccessibleSimpleChildElementID): TRect; override;
  end;

  { TdxRibbonTabCollectionAccessibilityHelper }

  TdxRibbonTabCollectionAccessibilityHelper = class(TdxBarAccessibilityHelper)
  private
    function GetTabCollection: TdxRibbonTabCollection;
  protected
    // IdxBarAccessibilityHelper
    function GetBarManager: TdxBarManager; override;
    function GetDefaultAccessibleObject: IdxBarAccessibilityHelper; override;

    function GetChild(AIndex: Integer): TcxAccessibilityHelper; override;
    function GetChildCount: Integer; override;
    function GetChildIndex(AChild: TcxAccessibilityHelper): Integer; override;
    function GetOwnerObjectWindow: HWND; override;
    function GetParent: TcxAccessibilityHelper; override;
    function GetState(AChildID: TcxAccessibleSimpleChildElementID): Integer; override;

//    function ChildIsSimpleElement(AIndex: Integer): Boolean; override;
//    function GetChildIndex(AChild: TcxAccessibilityHelper): Integer; override;
//    function GetName(AChildID: TcxAccessibleSimpleChildElementID): string; override;
//    function GetRole(AChildID: TcxAccessibleSimpleChildElementID): Integer; override;
//    function GetSupportedProperties(AChildID: TcxAccessibleSimpleChildElementID): TcxAccessibleObjectProperties; override;

    function LogicalNavigationGetChild(AIndex: Integer): TdxBarAccessibilityHelper; override;
    function LogicalNavigationGetChildCount: Integer; override;
    function LogicalNavigationGetChildIndex(AChild: TdxBarAccessibilityHelper): Integer; override;

    property TabCollection: TdxRibbonTabCollection read GetTabCollection;
  public
    function GetScreenBounds(AChildID: TcxAccessibleSimpleChildElementID): TRect; override;
  end;

  { TdxRibbonTabAccessibilityHelper }

  TdxRibbonTabAccessibilityHelper = class(TdxBarAccessibilityHelper)
  private
    function GetRibbon: TdxCustomRibbon;
    function GetTab: TdxRibbonTab;
  protected
    // IdxBarAccessibilityHelper
    function GetBarManager: TdxBarManager; override;
    function GetNextAccessibleObject(
      ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper; override;
    function HandleNavigationKey(var AKey: Word): Boolean; override;
    function IsNavigationKey(AKey: Word): Boolean; override;
    function LogicalNavigationGetNextAccessibleObject(
      AShift: TShiftState): IdxBarAccessibilityHelper; override;
    procedure Select(ASetFocus: Boolean); override;
    procedure Unselect(ANextSelectedObject: IdxBarAccessibilityHelper); override;

    function GetChild(AIndex: Integer): TcxAccessibilityHelper; override;
    function GetChildCount: Integer; override;
    function GetChildIndex(AChild: TcxAccessibilityHelper): Integer; override;
    function GetOwnerObjectWindow: HWND; override;
    function GetParent: TcxAccessibilityHelper; override;
    function GetSelectable: Boolean; override;
    function GetState(AChildID: TcxAccessibleSimpleChildElementID): Integer; override;

    function GetAssignedKeyTip: string; override;
    function GetDefaultKeyTip: string; override;
    procedure GetKeyTipInfo(out AKeyTipInfo: TdxBarKeyTipInfo); override;
    procedure KeyTipHandler(Sender: TObject); override;
    procedure KeyTipsEscapeHandler; override;

    property Ribbon: TdxCustomRibbon read GetRibbon;
    property Tab: TdxRibbonTab read GetTab;
  public
    procedure CloseUpHandler(AReason: TdxBarCloseUpReason);
    function GetScreenBounds(AChildID: TcxAccessibleSimpleChildElementID): TRect; override;
  end;

  { TdxRibbonApplicationButtonAccessibilityHelper }

  TdxRibbonApplicationButtonAccessibilityHelper = class(TdxBarAccessibilityHelper)
  private
    function GetApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo;
    function GetRibbon: TdxCustomRibbon;
    procedure ShowApplicationMenu(APostMessage: UINT);
  protected
    // IdxBarAccessibilityHelper
    function GetBarManager: TdxBarManager; override;
    function GetNextAccessibleObject(
      ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper; override;
    function HandleNavigationKey(var AKey: Word): Boolean; override;
    function IsNavigationKey(AKey: Word): Boolean; override;
    procedure Select(ASetFocus: Boolean); override;
    procedure Unselect(ANextSelectedObject: IdxBarAccessibilityHelper); override;

    function GetOwnerObjectWindow: HWND; override;
    function GetParent: TcxAccessibilityHelper; override;
    function GetSelectable: Boolean; override;
    function GetState(AChildID: TcxAccessibleSimpleChildElementID): Integer; override;

    function GetAssignedKeyTip: string; override;
    function GetDefaultKeyTip: string; override;
    procedure GetKeyTipInfo(out AKeyTipInfo: TdxBarKeyTipInfo); override;
    procedure KeyTipHandler(Sender: TObject); override;

    property ApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo read GetApplicationButtonViewInfo;
    property Ribbon: TdxCustomRibbon read GetRibbon;
  public
    function GetScreenBounds(AChildID: TcxAccessibleSimpleChildElementID): TRect; override;
  end;

  { TdxRibbonGroupsDockControlAccessibilityHelper }

  TdxRibbonGroupsDockControlAccessibilityHelper = class(TdxDockControlAccessibilityHelper)
  private
    function GetDockControl: TdxRibbonGroupsDockControl;
  protected
    function GetChild(AIndex: Integer): TcxAccessibilityHelper; override;
    function GetChildCount: Integer; override;
    function GetChildIndex(AChild: TcxAccessibilityHelper): Integer; override;
    function GetParent: TcxAccessibilityHelper; override;
    function GetState(AChildID: TcxAccessibleSimpleChildElementID): Integer; override;

    function GetParentForKeyTip: TdxBarAccessibilityHelper; override;

    property DockControl: TdxRibbonGroupsDockControl read GetDockControl;
  end;

  { TdxRibbonBarControlAccessibilityHelper }

  TdxRibbonBarControlAccessibilityHelper = class(TdxBarControlAccessibilityHelper)
  protected
    function LogicalNavigationGetNextChild(AChildIndex: Integer;
      AShift: TShiftState): TdxBarAccessibilityHelper; override;
  end;

  { TdxRibbonQuickAccessBarControlAccessibilityHelper }

  TdxRibbonQuickAccessBarControlAccessibilityHelper = class(TdxRibbonBarControlAccessibilityHelper)
  private
    function GetBarControl: TdxRibbonQuickAccessBarControl;
  protected
    function GetChild(AIndex: Integer): TcxAccessibilityHelper; override;
    function GetChildCount: Integer; override;
    function GetChildIndex(AChild: TcxAccessibilityHelper): Integer; override;
    function GetParent: TcxAccessibilityHelper; override;

    procedure DoGetKeyTipsData(AKeyTipsData: TList); override;
    procedure InitializeItemKeyTipPosition(AItemLinkHelper: TdxBarItemLinkAccessibilityHelper;
      var AKeyTipInfo: TdxBarKeyTipInfo); override;
    function GetNextAccessibleObject(AItemLinkHelper: TdxBarItemLinkAccessibilityHelper;
      ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper; override;
    function GetParentForKeyTip: TdxBarAccessibilityHelper; override;
    function IsKeyTipContainer: Boolean; override;
    procedure KeyTipsEscapeHandler; override;

    property BarControl: TdxRibbonQuickAccessBarControl read GetBarControl;
  end;

  { TdxRibbonQuickAccessBarControlMarkAccessibilityHelper }

  TdxRibbonQuickAccessBarControlMarkAccessibilityHelper = class(TdxBarControlMarkAccessibilityHelper)
  private
    function GetBarControl: TdxRibbonQuickAccessBarControl;
  protected
    // IdxBarAccessibilityHelper
    function HandleNavigationKey(var AKey: Word): Boolean; override;
    procedure GetKeyTipInfo(out AKeyTipInfo: TdxBarKeyTipInfo); override;
    function GetKeyTip: string; override;
    procedure KeyTipHandler(Sender: TObject); override;

    property BarControl: TdxRibbonQuickAccessBarControl read GetBarControl;
  end;

  { TdxRibbonGroupBarControlAccessibilityHelper }

  TdxRibbonGroupBarControlAccessibilityHelper = class(TdxRibbonBarControlAccessibilityHelper)
  private
    function GetBarControl: TdxRibbonGroupBarControl;
    procedure ShowPopupBarControl;
  protected
    // IdxBarAccessibilityHelper
    function GetNextAccessibleObject(
      ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper; override;
    function HandleNavigationKey(var AKey: Word): Boolean; override;
    function IsNavigationKey(AKey: Word): Boolean; override;
    procedure Select(ASetFocus: Boolean); override;
    procedure Unselect(ANextSelectedObject: IdxBarAccessibilityHelper); override;

    function GetSelectable: Boolean; override;

    function Expand: TCustomdxBarControlAccessibilityHelper; override;
    procedure GetCaptionButtonKeyTipPosition(ACaptionButton: TdxBarCaptionButton;
      out ABasePointY: Integer; out AVertAlign: TcxAlignmentVert); override;
    procedure InitializeItemKeyTipPosition(AItemLinkHelper: TdxBarItemLinkAccessibilityHelper;
      var AKeyTipInfo: TdxBarKeyTipInfo); override;

    function GetAssignedKeyTip: string; override;
    function GetDefaultKeyTip: string; override;
    procedure GetKeyTipInfo(out AKeyTipInfo: TdxBarKeyTipInfo); override;
    procedure GetKeyTipData(AKeyTipsData: TList); override;

    function GetNextAccessibleObject(AItemLinkHelper: TdxBarItemLinkAccessibilityHelper;
      ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper; override;
    function GetParentForKeyTip: TdxBarAccessibilityHelper; override;
    function IsCollapsed: Boolean; override;
    function IsKeyTipContainer: Boolean; override;
    procedure KeyTipHandler(Sender: TObject); override;
    procedure KeyTipsEscapeHandler; override;

    property BarControl: TdxRibbonGroupBarControl read GetBarControl;
  public
    procedure CloseUpHandler(AReason: TdxBarCloseUpReason);
  end;

  { TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper }

  TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper = class(TdxBarButtonLikeControlAccessibilityHelper)
  protected
    function IsDropDownControl: Boolean; override;
    function ShowDropDownWindow: Boolean; override;
  end;

  { TdxRibbonKeyTipWindow }

  TdxRibbonKeyTipWindow = class(TCustomControl)
  private
    FColorScheme: TdxCustomRibbonSkin;
    procedure CMEnabledChanged(var Message: TMessage); message CM_ENABLEDCHANGED;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
  protected
    function CalcBoundsRect: TRect;
    procedure CreateParams(var Params: TCreateParams); override;
    procedure CreateWindowHandle(const Params: TCreateParams); override;
    procedure Paint; override;
    procedure UpdateBounds;
  public
    constructor Create(AColorScheme: TdxCustomRibbonSkin); reintroduce; virtual;
    procedure ShowKeyTip;
    property Caption;
    property Enabled;
  end;

  { TdxRibbonCustomKeyTipWindows }

  TdxRibbonCustomKeyTipWindows = class(TInterfacedObject, IdxBarKeyTipWindowsManager)
  private
    FRibbon: TdxCustomRibbon;
    FWindowList: TcxObjectList;
    function GetColorScheme: TdxCustomRibbonSkin;
    function GetCount: Integer;
  protected
    // IdxBarKeyTipWindowsManager
    procedure Add(const ACaption: string; const ABasePoint: TPoint;
      AHorzAlign: TAlignment; AVertAlign: TcxAlignmentVert; AEnabled: Boolean;
      out AWindow: TObject);
    procedure Initialize; virtual;
    procedure Delete(AWindow: TObject);
    procedure Show;

    property ColorScheme: TdxCustomRibbonSkin read GetColorScheme;
    property Count: Integer read GetCount;
  public
    constructor Create(ARibbon: TdxCustomRibbon); reintroduce;
    destructor Destroy; override;
  end;

  { TdxRibbonKeyTipWindows }

  TdxRibbonKeyTipWindows = class(TdxRibbonCustomKeyTipWindows)
  protected
    procedure Initialize; override;
  end;

  { TdxRibbonScrollBar }

  TdxRibbonScrollBar = class(TcxControlScrollBar)
  protected
    function GetHelperClass: TcxScrollBarHelperClass; override;
    function GetRibbon: TdxCustomRibbon; virtual;
  public
    property Ribbon: TdxCustomRibbon read GetRibbon;
  end;

  { TdxRibbonScrollBarHelper }

  TdxRibbonScrollBarHelper = class(TcxControlScrollBarHelper)
  protected
    function GetPainterClass: TcxScrollBarPainterClass; override;
  end;

  { TdxRibbonScrollBarPainter }

  TdxRibbonScrollBarPainter = class(TcxScrollBarPainter)
  private
    function GetScrollBar: TdxRibbonScrollBar;
    function GetSkin: IdxSkin;
  protected
    procedure DoDrawScrollBarPart(ACanvas: TcxCanvas; const R: TRect; APart: TcxScrollBarPart; AState: TcxButtonState); override;
    procedure DrawScrollBarBackground(ACanvas: TcxCanvas; const R: TRect); override;
  public
    property ScrollBar: TdxRibbonScrollBar read GetScrollBar;
    property Skin: IdxSkin read GetSkin;
  end;

  { TdxRibbonSizeGrip }

  TdxRibbonSizeGrip = class(TcxSizeGrip)
  protected
    procedure Draw(ACanvas: TCanvas); override;
    function GetRibbon: TdxCustomRibbon; virtual;
  public
    property Ribbon: TdxCustomRibbon read GetRibbon;
  end;

procedure RibbonCheckCreateComponent(var AOwner: TComponent; AClass: TClass);
procedure RibbonDockToolBar(AToolBar: TdxBar; ADockControl: TdxBarDockControl);
procedure RibbonUndockToolBar(AToolBar: TdxBar);
function FindRibbonForComponent(AComponent: TComponent): TdxCustomRibbon;

implementation

uses
  Types, dxOffice11, CommCtrl, cxGeometry, dxBarStrs, dxBarSkinConsts,
  dxRibbonGroupLayoutCalculator, Math, cxDrawTextUtils, cxDWMApi, dxUxTheme,
  dxThemeConsts, dxGDIPlusAPI, dxHooks;

const
  dxRibbonTabSeparatorWidth = 1;
  dxRibbonTabsRightSpace    = 6;
  dxRibbonTabsLeftSpace     = 8;

  dxRibbonCollapsedGroupGlyphBackgroundOffsets: TRect = (Left: 3; Top: 3; Right: 3; Bottom: 4);
  dxRibbonEmptyHeight = 24;
  dxRibbonGroupCaptionHeightCorrection = 1;
  dxRibbonGroupContentLeftOffset = 2;
  dxRibbonGroupContentRightOffset = 2;
  dxRibbonGroupRowHeightCorrection = 3;
  dxRibbonGroupSelectionFrameSize = 2;

  dxRibbonGroupsScrollDelta = 10;
  dxCaptionGlowRadius       = 10;
  dxExtraContextGap         = 2;

  dxRibbonBarBehaviorOptions: TdxBarBehaviorOptions = [bboAllowShowHints, bboClickItemsBySpaceKey,
    bboMouseCantUnselectNavigationItem, bboUnmoved, bboItemCustomizePopup, bboSubMenuCaptureMouse,
    bboCanShowPopupMenuOnMouseClick];

type
  PMouseHookStructEx = ^TMouseHookStructEx;
  TMouseHookStructEx = record
    pt: TPoint;
    hwnd: HWND;
    wHitTestCode: UINT;
    dwExtraInfo: TdxNativeUInt;
    mouseData: DWORD;
  end;

  TCustomdxBarControlAccess = class(TCustomdxBarControl);
  TdxBarAccess = class(TdxBar);
  TdxBarAccessibilityHelperAccess = class(TdxBarAccessibilityHelper);
  TdxBarCaptionButtonAccessibilityHelperAccess = class(TdxBarCaptionButtonAccessibilityHelper);
  TdxBarControlAccess = class(TdxBarControl);
  TdxBarItemControlAccess = class(TdxBarItemControl);
  TdxBarItemControlAccessibilityHelperAccess = class(TdxBarItemControlAccessibilityHelper);
  TdxBarItemLinkAccess = class(TdxBarItemLink);
  TdxBarItemLinksAccess = class(TdxBarItemLinks);
  TdxBarManagerAccess = class(TdxBarManager);
  TdxBarSubMenuControlAccess = class(TdxBarSubMenuControl);
  TdxCustomRibbonSkinAccess = class(TdxCustomRibbonSkin);

const
  sdxErrorToolbarUsedAsQAT = 'This toolbar is already used as the QuickAccessToolbar';
  sdxErrorToolbarUsedInAnotherGroupInThisTab = 'At least one group in this tab already contains this toolbar';

type

  { TdxRibbonGroupBarControlViewInfoHelper }

  TdxRibbonGroupBarControlViewInfoHelper = class(TInterfacedObject, IdxRibbonGroupViewInfo)
  private
    FViewInfo: TdxRibbonGroupBarControlViewInfo;
    // IdxRibbonGroupViewInfo
    procedure AddSeparator(const Value: TdxBarItemSeparatorInfo);
    procedure DeleteSeparators;
    function GetContentSize: TSize;
    function GetItemControlCount: Integer;
    function GetItemControlViewInfo(AIndex: Integer): IdxBarItemControlViewInfo;
    function GetMinContentWidth: Integer;
    function GetOffsetsInfo: TdxRibbonGroupOffsetsInfo;
    function GetSeparatorCount: Integer;
    function GetSeparatorInfo(AIndex: Integer): TdxBarItemSeparatorInfo;
    procedure SetContentSize(const Value: TSize);
    procedure SetSeparatorInfo(AIndex: Integer; const Value: TdxBarItemSeparatorInfo);
  protected
    property ViewInfo: TdxRibbonGroupBarControlViewInfo read FViewInfo;
  public
    constructor Create(AViewInfo: TdxRibbonGroupBarControlViewInfo);
  end;

  { TdxRibbonMergeHelper }

  TdxRibbonMergeHelper = class(TObject)
  public
    class function IsMergedWith(ATestToolbar, ATargetToolbar: TdxBar): Boolean;
    class procedure MergeToolbarContainers(ATargetContainer: TObject;
      ASourceContainer: TObject; ACanCreateNewToolbar: Boolean);
    class procedure UnmergeToolbarContainers(ATargetContainer, ASourceContainer: TObject);
  end;

var
  FIsMouseHookInstalled: Boolean;
  FRibbonList: TList;

function dxRibbonList: TList;
begin
  Result := FRibbonList;
end;

function dxRibbonGetGroupCaption(ABar: TdxBar): string;
begin
  if ABar.Control is TdxRibbonGroupBarControl then
    Result := TdxRibbonGroupBarControl(ABar.Control).Group.Caption
  else
    Result := ABar.Caption;
end;

procedure dxFillRectOpaque(DC: HDC; const ABounds: TRect; AColor: TColor;
  const AText: string = ''; ATextColor: TColor = clBlack);
var
  B: TcxBitmap32;
begin
  if cxRectIsEmpty(ABounds) then Exit;
  B := TcxBitmap32.CreateSize(ABounds);
  try
    B.cxCanvas.FillRect(B.ClientRect, AColor);
    if Length(AText) > 0 then
    begin
      B.cxCanvas.Brush.Style := bsClear;
      B.cxCanvas.Font.Color := ATextColor;
      B.cxCanvas.DrawTexT(AText, B.ClientRect, cxAlignCenter or cxSingleLine);
      B.cxCanvas.Brush.Style := bsSolid;
    end;
    B.MakeOpaque;
    cxBitBlt(DC, B.cxCanvas.Handle, ABounds, cxNullPoint, SRCCOPY);
  finally
    B.Free;
  end;
end;

function HasComponentOnForm(AForm: TCustomForm; AClass: TClass): Boolean;
begin
  Result := cxFindComponent(AForm, AClass) <> nil;
end;

function CloseActiveRibbonApplicationMenus: Boolean;
var
  ARibbon: TdxCustomRibbon;
  I: Integer;
begin
  Result := False;
  for I := 0 to dxRibbonList.Count - 1 do
  begin
    ARibbon := TdxCustomRibbon(dxRibbonList[I]);
    if ARibbon.Controller.CloseApplicationMenu then
      Result := True;
  end;
end;

procedure RibbonCheckCreateComponent(var AOwner: TComponent; AClass: TClass);
begin
  if not CheckGdiPlus then
    raise EdxException.CreateFmt(cxGetResourceString(@dxSBAR_GDIPLUSNEEDED), [AClass.ClassName]);
  if (AOwner = nil) and (Application.MainForm <> nil) then
    AOwner := Application.MainForm;
  if not (AOwner is TCustomForm) then
    raise EdxException.CreateFmt(cxGetResourceString(@dxSBAR_RIBBONBADOWNER), [AClass.ClassName]);
  if HasComponentOnForm(TCustomForm(AOwner), AClass) then
    raise EdxException.CreateFmt(cxGetResourceString(@dxSBAR_RIBBONMORETHANONE), [AClass.ClassName]);
end;

function FindMouseWheelReceiver(AWnd: HWND; out AReceiver: IdxRibbonMouseWheelReceiver): Boolean;
var
  AControl: TWinControl;
begin
  AReceiver := nil;
  while AWnd <> 0 do
  begin
    AControl := FindControl(AWnd);
    if Supports(AControl, IdxRibbonMouseWheelReceiver, AReceiver) then
      Break;
    if not IsChildClassWindow(AWnd) then
      Break;
    AWnd := GetParent(AWnd);
  end;
  Result := Assigned(AReceiver);
end;

procedure dxRibbonMouseHook(ACode: Integer; wParam: WPARAM; lParam: LPARAM; var AHookResult: LRESULT);
var
  AMHS: PMouseHookStructEx;
  AReceiver: IdxRibbonMouseWheelReceiver;
begin
  if (ACode < 0) or (wParam <> WM_MOUSEWHEEL) or not Mouse.WheelPresent then
    Exit;

  AMHS := PMouseHookStructEx(lParam);
  case BarGetMouseWheelReceiver of
    mwrActiveBarControl:
      begin
        SendMessage(ActiveBarControl.Handle, WM_MOUSEWHEEL,
          MakeWParam(ShiftStateToKeys(KeyboardStateToShiftState), HiWord(AMHS.mouseData)),
          MakeLParam(AMHS.pt.X, AMHS.pt.Y));
        AHookResult := 1;
      end;

    mwrWindow:
      if FindMouseWheelReceiver(WindowFromPoint(AMHS.pt), AReceiver) and AReceiver.CanProcessMouseWheel then
      begin
        if AReceiver.DoMouseWheel(KeyboardStateToShiftState, ShortInt(HiWord(AMHS.mouseData)), cxInvalidPoint) then
          AHookResult := 1;
      end
  end;
end;

procedure DrawRect(DC: HDC; const R: TRect; AColor: TColor; AExclude: Boolean);
begin
  FillRectByColor(DC, R, AColor);
  if AExclude then
    ExcludeClipRect(DC, R.Left, R.Top, R.Right, R.Bottom);
end;

function GetMonitorWorkArea(AWnd: HWND): TRect;
var
  AMonitor: TMonitor;
begin
  if AWnd = 0 then
    AMonitor := Screen.MonitorFromPoint(GetMouseCursorPos)
  else
    AMonitor := Screen.MonitorFromWindow(AWnd);
  if Assigned(AMonitor) then
    Result := AMonitor.WorkareaRect
  else
    with Screen do
      Result := cxRectBounds(DesktopLeft, DesktopTop, DesktopWidth, DesktopHeight);
end;

procedure SelectFirstSelectableAccessibleObject(AParentObject: TdxBarAccessibilityHelper);
begin
  BarNavigationController.ChangeSelectedObject(False, AParentObject.GetFirstSelectableObject);
end;

//routines
procedure RibbonDockToolBar(AToolBar: TdxBar; ADockControl: TdxBarDockControl);
var
  APrevVisible: Boolean;
begin
  if (AToolBar = nil) or (AToolBar.DockControl = ADockControl) then Exit;
  APrevVisible := AToolBar.Visible;
  if not (csLoading in AToolBar.ComponentState) then
    AToolBar.Visible := False;
  try
    AToolBar.DockControl := ADockControl;
  finally
    if not (csLoading in AToolBar.ComponentState) then
      AToolBar.Visible := APrevVisible;
  end;
end;

procedure RibbonUndockToolBar(AToolBar: TdxBar);
var
  APrevVisible: Boolean;
begin
  if (AToolbar = nil) or (csDestroying in AToolbar.ComponentState) then Exit;
  APrevVisible := AToolbar.Visible;
  AToolbar.Visible := False;
  AToolbar.DockControl := nil;
  AToolbar.DockedDockControl := nil;
  AToolbar.DockedDockingStyle := dsNone;
  AToolbar.DockingStyle := dsNone;
  AToolbar.Visible := APrevVisible;
end;

function FindRibbonForComponent(AComponent: TComponent): TdxCustomRibbon;

  function GetOwnerForm(AComponent: TComponent): TCustomForm;
  begin
    Result := nil;
    while (AComponent <> nil) and (Result = nil) do
    begin
      if AComponent is TCustomForm then
        Result := TCustomForm(AComponent);
      AComponent := AComponent.Owner;
    end;
  end;

var
  AForm: TCustomForm;
begin
  AForm := GetOwnerForm(AComponent);
  if AForm <> nil then
    Result := TdxCustomRibbon(cxFindComponent(AForm, TdxCustomRibbon))
  else
    Result := nil;
end;

function FindRibbonForWindow(AWnd: HWND): TdxCustomRibbon;
var
  AForm: TCustomForm;
begin
  AForm := dxBarGetControlForm(dxFindVCLControl(AWND), fkMainOrMDIChild);
  if AForm <> nil then
    Result := TdxCustomRibbon(cxFindComponent(AForm, TdxCustomRibbon))
  else
    Result := nil;
end;
            
function GetRootRibbonAccessibilityHelper(AParentWnd: HWND): IdxBarAccessibilityHelper;
var
  ARibbon: TdxCustomRibbon;
begin
  Result := nil;
  ARibbon := FindRibbonForWindow(AParentWnd);
  if (ARibbon <> nil) and ARibbon.Visible and
    (not ARibbon.Hidden or ARibbon.IsAutoHidden) and
    (ARibbon.ShowTabHeaders or ARibbon.ShowTabGroups) then
  begin
    if ARibbon.Controller.IsApplicationMenuDropped then
      Result := ARibbon.ApplicationButton.IMenu.GetRootAccessibilityHelper;
    if Result = nil then
      Result := ARibbon.IAccessibilityHelper;
  end;
end;

procedure RaiseMergingError(AResString: Pointer); overload;
begin
  raise EdxException.Create(cxGetResourceString(AResString));
end;

procedure RaiseMergingError(AResString: Pointer; ATargetComponent, ASourceComponent: TComponent); overload;
begin
  raise EdxException.Create(Format(cxGetResourceString(AResString),
    [cxGetFullComponentName(ATargetComponent), cxGetFullComponentName(ASourceComponent)]));
end;

{ TdxRibbonMergeHelper }

class function TdxRibbonMergeHelper.IsMergedWith(ATestToolbar, ATargetToolbar: TdxBar): Boolean;
begin
  Result := (ATestToolbar <> nil) and (ATargetToolbar <> nil) and
    (TdxBarAccess(ATestToolbar).MergeData.MergedWith <> nil) and
    (TdxBarAccess(ATestToolbar).MergeData.MergedWith = ATargetToolbar);
end;

class procedure TdxRibbonMergeHelper.MergeToolbarContainers(
  ATargetContainer, ASourceContainer: TObject; ACanCreateNewToolbar: Boolean);
var
  ASourceToolbar: IdxRibbonToolbarContainer;
  ATargetToolbar: IdxRibbonToolbarContainer;
begin
  if (ATargetContainer = ASourceContainer) or
    not Supports(ATargetContainer, IdxRibbonToolbarContainer, ATargetToolbar) or
    not Supports(ASourceContainer, IdxRibbonToolbarContainer, ASourceToolbar)
  then
    RaiseMergingError(@dxSBAR_CANTMERGETOOLBAR);

  if not (ASourceToolbar.Ribbon.IsBarManagerValid and ATargetToolbar.Ribbon.IsBarManagerValid) then
    RaiseMergingError(@dxSBAR_RIBBONCANTMERGEWITHOUTBARMANAGER);

  if (ATargetToolbar.Toolbar = nil) and ACanCreateNewToolbar then
  begin
    ATargetToolbar.Toolbar := ATargetToolbar.Ribbon.CreateToolbarAsByMerging;
    ATargetToolbar.Toolbar.Caption := ASourceToolbar.Toolbar.Caption;
    ATargetToolbar.Toolbar.Visible := True;
  end;
  if ATargetToolbar.Toolbar <> nil then
    ATargetToolbar.Toolbar.Merge(ASourceToolbar.Toolbar);
end;

class procedure TdxRibbonMergeHelper.UnmergeToolbarContainers(
  ATargetContainer, ASourceContainer: TObject);

  function GetToolbar(AContainer: TObject): TdxBar;
  var
    AContainerIntf: IdxRibbonToolbarContainer;
  begin
    if Supports(AContainer, IdxRibbonToolbarContainer, AContainerIntf) then
      Result := AContainerIntf.Toolbar
    else
      Result := nil;
  end;

var
  ATargetToolbar: TdxBar;
begin
  ATargetToolbar := GetToolbar(ATargetContainer);
  if ATargetToolbar <> nil then
    ATargetToolbar.Unmerge(GetToolbar(ASourceContainer));
end;

{ TdxRibbonGroupBarControlViewInfoHelper }

constructor TdxRibbonGroupBarControlViewInfoHelper.Create(
  AViewInfo: TdxRibbonGroupBarControlViewInfo);
begin
  inherited Create;
  FViewInfo := AViewInfo;
end;

// IdxRibbonGroupViewInfo
procedure TdxRibbonGroupBarControlViewInfoHelper.AddSeparator(
  const Value: TdxBarItemSeparatorInfo);
begin
  ViewInfo.AddSeparatorInfo(Value.Bounds, Value.Kind, nil);
end;

procedure TdxRibbonGroupBarControlViewInfoHelper.DeleteSeparators;
begin
  ViewInfo.RemoveSeparatorInfos;
end;

function TdxRibbonGroupBarControlViewInfoHelper.GetContentSize: TSize;
begin
  Result := ViewInfo.ContentSize;
end;

function TdxRibbonGroupBarControlViewInfoHelper.GetItemControlCount: Integer;
begin
  Result := ViewInfo.ItemControlCount;
end;

function TdxRibbonGroupBarControlViewInfoHelper.GetItemControlViewInfo(
  AIndex: Integer): IdxBarItemControlViewInfo;
begin
  Result := ViewInfo.ItemControlViewInfos[AIndex];
end;

function TdxRibbonGroupBarControlViewInfoHelper.GetMinContentWidth: Integer;
var
  ABarControl: TdxRibbonGroupBarControl;
begin
  ABarControl := ViewInfo.BarControl;
  Result := ABarControl.Ribbon.GroupsPainter.GetGroupMinWidth(ABarControl);
end;

function TdxRibbonGroupBarControlViewInfoHelper.GetOffsetsInfo: TdxRibbonGroupOffsetsInfo;
begin
  Result.ButtonGroupOffset := ViewInfo.BarControl.Ribbon.SkinGetPartSize(DXBAR_BUTTONGROUP);
  Result.ContentLeftOffset := dxRibbonGroupContentLeftOffset;
  Result.ContentRightOffset := dxRibbonGroupContentRightOffset;
end;

function TdxRibbonGroupBarControlViewInfoHelper.GetSeparatorCount: Integer;
begin
  Result := ViewInfo.SeparatorCount;
end;

function TdxRibbonGroupBarControlViewInfoHelper.GetSeparatorInfo(
  AIndex: Integer): TdxBarItemSeparatorInfo;
begin
  Result := ViewInfo.SeparatorInfos[AIndex];
end;

procedure TdxRibbonGroupBarControlViewInfoHelper.SetContentSize(
  const Value: TSize);
begin
  ViewInfo.ContentSize := Value;
end;

procedure TdxRibbonGroupBarControlViewInfoHelper.SetSeparatorInfo(
  AIndex: Integer; const Value: TdxBarItemSeparatorInfo);
begin
  ViewInfo.SeparatorInfos[AIndex] := Value;
end;

{ TdxRibbonCustomMergeData }

constructor TdxRibbonCustomMergeData.Create;
begin
  inherited Create;
  FChildren := TcxComponentList.Create(False);
  FChildren.OnNotify := ListChangeHandler;
end;

destructor TdxRibbonCustomMergeData.Destroy;
begin
  FreeAndNil(FChildren);
  inherited Destroy;
end;

procedure TdxRibbonCustomMergeData.FreeNotification(Sender: TComponent);
begin
  Children.Remove(Sender);
end;

procedure TdxRibbonCustomMergeData.ListChangeHandler(
  Sender: TObject; AComponent: TComponent; AAction: TListNotification);
begin
  case AAction of
    lnAdded:
      FreeNotificator.AddSender(AComponent);
    lnExtracted, lnDeleted:
      FreeNotificator.RemoveSender(AComponent);
  end;
end;

{ TdxCustomDesignSelectionHelper }

constructor TdxCustomDesignSelectionHelper.Create(
  AComponent: TComponent; AOwner, AParent: TPersistent);
begin
  inherited Create;
  FComponent := AComponent;
  FParent := AParent;
  FOwner := AOwner;
end;

//IdxBarSelectableItem
function TdxCustomDesignSelectionHelper.CanDelete(ADestruction: Boolean): Boolean;
begin
  if (Owner is TComponent) and (BarManager <> nil) then
    Result := IdxBarDesigner(BarManager).CanDeleteComponent(TComponent(Owner))
  else
    Result := True;
end;

procedure TdxCustomDesignSelectionHelper.DeleteSelection(
  var AReference: IdxBarSelectableItem; ADestruction: Boolean);
begin
  if CanDelete(ADestruction) then
  begin
    AReference := nil;
    Owner.Free;
  end;
end;

procedure TdxCustomDesignSelectionHelper.ExecuteCustomizationAction(ABasicAction: TdxBarCustomizationAction);
begin
// do nothing;
end;

function TdxCustomDesignSelectionHelper.GetBarManager: TdxBarManager;
begin
  Result := nil;
end;

function TdxCustomDesignSelectionHelper.GetInstance: TPersistent;
begin
  Result := Owner;
end;

procedure TdxCustomDesignSelectionHelper.GetMasterObjects(AList: TdxObjectList);
begin
  AList.Add(Parent);
end;

function TdxCustomDesignSelectionHelper.GetNextSelectableItem: IdxBarSelectableItem;
begin
  Result := nil;
end;

function TdxCustomDesignSelectionHelper.GetSelectableParent: TPersistent;
begin
  Result := Parent;
end;

function TdxCustomDesignSelectionHelper.GetSelectionStatus: TdxBarSelectionStatus;
begin
  if BarManager <> nil then
    Result := (BarManager as IdxBarDesigner).GetSelectionStatus(Owner)
  else
    Result := ssUnselected;
end;

function TdxCustomDesignSelectionHelper.GetSupportedActions: TdxBarCustomizationActions;
begin
  Result := [];
end;

procedure TdxCustomDesignSelectionHelper.Invalidate;
begin
end;

function TdxCustomDesignSelectionHelper.IsComplex: Boolean;
begin
  Result := False;
end;

function TdxCustomDesignSelectionHelper.IsComponentSelected: Boolean;
begin
  Result := (BarManager <> nil) and (BarManager as IdxBarDesigner).IsComponentSelected(Owner);
end;

procedure TdxCustomDesignSelectionHelper.SelectComponent(ASelectionOperation: TdxBarSelectionOperation);
begin
  if BarManager <> nil then
    (BarManager as IdxBarDesigner).SelectComponent(Owner, ASelectionOperation);
end;

procedure TdxCustomDesignSelectionHelper.SelectionChanged;
begin
  Invalidate;
end;

function TdxCustomDesignSelectionHelper.SelectParentComponent: Boolean;
begin
  Result := True;
  if BarManager <> nil then
    (BarManager as IdxBarDesigner).SelectComponent(GetSelectableParent);
end;

{ TdxDesignSelectionHelper }

function TdxDesignSelectionHelper.GetBarManager: TdxBarManager;
begin
  Result := Ribbon.BarManager;
end;

function TdxDesignSelectionHelper.GetRibbon: TdxCustomRibbon;
begin
  Result := TdxCustomRibbon(Component);
end;

procedure TdxDesignSelectionHelper.Invalidate;
begin
  Ribbon.FullInvalidate;
end;

{ TdxRibbonTabPainter }

constructor TdxRibbonTabPainter.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create;
  FRibbon := ARibbon;
end;

procedure TdxRibbonTabPainter.DrawBackground(ACanvas: TcxCanvas;
  const ABounds: TRect; AState: TdxRibbonTabState);
begin
  ColorScheme.DrawTab(ACanvas.Handle, ABounds, AState, Ribbon.ColorSchemeAccent);
end;

procedure TdxRibbonTabPainter.DrawContextTabBackground(ACanvas: TcxCanvas;
  AColor: TColor; const ABounds: TRect; AState: TdxRibbonTabState);
begin
  ColorScheme.DrawContextTabBackground(ACanvas.Handle,
    ABounds, AState, AColor, Ribbon.ColorSchemeAccent);
end;

procedure TdxRibbonTabPainter.DrawContextTabSeparator(
  ACanvas: TcxCanvas; const ABounds: TRect; ABeginGroup: Boolean);
begin
  ColorScheme.DrawContextTabSeparator(ACanvas.Handle, ABounds, ABeginGroup);
end;

procedure TdxRibbonTabPainter.DrawTabSeparator(
  ACanvas: TcxCanvas; const ABounds: TRect; Alpha: Byte);
begin
  ColorScheme.DrawTabSeparator(ACanvas.Handle, ABounds, Alpha);
end;

procedure TdxRibbonTabPainter.DrawText(ACanvas: TcxCanvas; 
   const ABounds: TRect;  const AText: string; AHasSeparator, AIsPaintOnGlass: Boolean);
const
  CustomFlags: array[Boolean] of Integer =
   (cxAlignVCenter or cxSingleLine or cxAlignHCenter,
    cxAlignVCenter or cxSingleLine or cxAlignLeft);
  GlassFlags: array[Boolean] of Integer =
   (DT_VCENTER or DT_SINGLELINE or DT_CENTER,
    DT_VCENTER or DT_SINGLELINE or DT_LEFT);
begin
  if AIsPaintOnGlass then
    dxDrawTextOnGlass(ACanvas.Handle, AText, ACanvas.Font, ABounds,
      ACanvas.Font.Color, DT_NOPREFIX or GlassFlags[AHasSeparator], 0, True)
  else
  begin
    ACanvas.Brush.Style := bsClear;
    ACanvas.DrawText(AText, ABounds, CustomFlags[AHasSeparator]);
    ACanvas.Brush.Style := bsSolid;
  end;
end;

function TdxRibbonTabPainter.GetColorScheme: TdxCustomRibbonSkin;
begin
  Result := Ribbon.ColorScheme;
end;

{ TdxRibbonPainter }

constructor TdxRibbonPainter.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create;
  FRibbon := ARibbon;
end;

procedure TdxRibbonPainter.AdjustContextFont(AFont: TFont; AContextColor: TColor);
begin
  ColorScheme.AdjustContextFont(AFont, Ribbon.ViewInfo.UseGlass, AContextColor, ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawApplicationButton(
  ACanvas: TcxCanvas; const ABounds: TRect; AState: TdxRibbonApplicationButtonState);
begin
  if not IsRectEmpty(ABounds) then
    ColorScheme.DrawApplicationButton(ACanvas.Handle, ABounds, AState, ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawApplicationButtonGlyph(
  ACanvas: TcxCanvas; const ABounds: TRect; AGlyph: TBitmap);
begin
  if (AGlyph = nil) or AGlyph.Empty then
    DrawFormDefaultIcon(ACanvas, ABounds)
  else
    DrawGlyph(ACanvas, AGlyph, ABounds);
end;

procedure TdxRibbonPainter.DrawFormDefaultIcon(ACanvas: TcxCanvas; const ABounds: TRect);
var
  AIcon: HICON;
  AImageList: TImageList;
begin
  AIcon := GetFormIconHandle;
  if (AIcon <> 0) and not cxRectIsEmpty(ABounds) then
  begin
    if ViewInfo.UseGlass then
    begin
      AImageList := TImageList.CreateSize(cxRectWidth(ABounds), cxRectHeight(ABounds));
      try
        ImageList_AddIcon(AImageList.Handle, AIcon);
        cxDrawImage(ACanvas.Handle, ABounds, ABounds, nil, AImageList, 0, idmNormal);
      finally
        AImageList.Free;
      end;
    end
    else
      DrawIconEx(ACanvas.Handle, ABounds.Left, ABounds.Top,
        AIcon, cxRectWidth(ABounds), cxRectHeight(ABounds), 0, 0, DI_NORMAL);
  end;
end;

procedure TdxRibbonPainter.DrawBackground(ACanvas: TcxCanvas; const ABounds: TRect);
var
  R: TRect;
begin
  R := ABounds;
  if ViewInfo.IsQATVisible and not (ViewInfo.IsQATAtBottom or ViewInfo.SupportNonClientDrawing) then
  begin
    R.Bottom := ViewInfo.QuickAccessToolbarBounds.Bottom;
    ColorScheme.DrawRibbonClientTopArea(ACanvas.Handle, R);
    R := ABounds;
    R.Top := ViewInfo.QuickAccessToolbarBounds.Bottom;
  end;
  ColorScheme.DrawRibbonBackground(ACanvas.Handle, R);
end;

procedure TdxRibbonPainter.DrawContextBackground(
  ACanvas: TcxCanvas; const ABounds: TRect; AColor: TColor);
begin
  ColorScheme.DrawContextBackground(ACanvas.Handle, ABounds, AColor);
end;

procedure TdxRibbonPainter.DrawContextBackgroundGlass(
  ACanvas: TcxCanvas; const ABounds: TRect; AColor: TColor);
begin
  ColorScheme.DrawContextBackgroundGlass(ACanvas.Handle, ABounds, AColor);
end;

procedure TdxRibbonPainter.DrawContextGroupsArea(
  ACanvas: TcxCanvas; const ABounds: TRect; AIsQATAtBottom, AIsInPopup: Boolean);
var
  B: TcxBitmap;
begin
  B := TcxBitmap.CreateSize(ABounds, pf32bit);
  try
    B.cxCanvas.FillRect(B.ClientRect, Ribbon.ActiveTab.Context.Color);
    ColorScheme.DrawContextTabGroupsArea(B.cxCanvas.Handle, B.ClientRect,
      Ribbon.ActiveTab.Context.Color, AIsQATAtBottom, AIsInPopup);
    cxBitBlt(ACanvas.Handle, B.cxCanvas.Handle, ABounds, cxNullPoint, SRCCOPY);
  finally
    B.Free;
  end;
end;

procedure TdxRibbonPainter.DrawGlowingText(DC: HDC; const AText: string;
  AFont: TFont; const ABounds: TRect; AColor: TColor; AFlags: DWORD;
  ATransparent: Boolean = False);
begin
  dxDrawTextOnGlass(DC, AText, AFont, ABounds,
    AColor, AFlags, dxCaptionGlowRadius, ATransparent);
end;

procedure TdxRibbonPainter.DrawGlyph(ACanvas: TcxCanvas; AGlyph: TBitmap; const ABounds: TRect);
var
  APrevBrushStyle: TBrushStyle;
begin
  if AGlyph.PixelFormat = pf32bit then
    cxAlphaBlend(ACanvas.Handle, AGlyph, ABounds, cxRect(0, 0, AGlyph.Width, AGlyph.Height), True)
  else
  begin
    APrevBrushStyle := ACanvas.Brush.Style;
    ACanvas.Brush.Style := bsClear;
    ACanvas.Canvas.BrushCopy(ABounds, AGlyph,
      cxRect(0, 0, AGlyph.Width, AGlyph.Height), AGlyph.TransparentColor);
    ACanvas.Brush.Style := APrevBrushStyle;
  end;
end;

procedure TdxRibbonPainter.DrawGroupsArea(ACanvas: TcxCanvas;
  const ABounds: TRect; AIsAllowContextPaint: Boolean = True;
  AIsInPopup: Boolean = False);
var
  AIsQATAtBottom: Boolean;
begin
  AIsQATAtBottom := ViewInfo.IsQATVisible and ViewInfo.IsQATAtBottom;
  if AIsAllowContextPaint and ViewInfo.HasActiveContextTab then
    DrawContextGroupsArea(ACanvas, ABounds, AIsQATAtBottom, AIsInPopup)
  else
    ColorScheme.DrawTabGroupsArea(ACanvas.Handle, ABounds, AIsQATAtBottom, AIsInPopup);
end;

procedure TdxRibbonPainter.DrawGroupsScrollButton(ACanvas: TcxCanvas;
  const ABounds: TRect; ALeft: Boolean; AState: TcxButtonState);
const
  StateMap: array[TcxButtonState] of Integer = (
    DXBAR_NORMAL, DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED, DXBAR_NORMAL
  );
begin
  ColorScheme.DrawGroupScrollButton(ACanvas.Handle, ABounds, ALeft, StateMap[AState], ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawGroupsScrollButtonArrow(ACanvas: TcxCanvas;
  const ABounds: TRect; ALeft: Boolean);
const
  ArrowDirection: array[Boolean] of TcxArrowDirection = (adRight, adLeft);
begin
  if ColorScheme.NeedDrawGroupScrollArrow then
    cxLookAndFeelPaintersManager.GetPainter(lfsStandard).DrawArrow(ACanvas,
      cxRectInflate(ABounds, -2, 0, -2, -2), ArrowDirection[ALeft], clBlack);
end;

procedure TdxRibbonPainter.DrawQuickAccessToolbar(
  ACanvas: TcxCanvas; const ABounds: TRect; AIsActive: Boolean);
begin
  if not ViewInfo.IsQATAtNonClientArea then
  begin
    ACanvas.SaveClipRegion;
    try
      ACanvas.IntersectClipRect(ABounds);
      DrawBackground(ACanvas, ViewInfo.Bounds);
    finally
      ACanvas.RestoreClipRegion;
    end;
  end;
  ColorScheme.DrawQuickAccessToolbar(ACanvas.Handle, ABounds,
    ViewInfo.IsQATAtBottom, ViewInfo.SupportNonClientDrawing,
    ViewInfo.IsApplicationButtonNearQAT, AIsActive, not ViewInfo.UseGlass);
end;

procedure TdxRibbonPainter.DrawTabAreaBackground(ACanvas: TcxCanvas; const ABounds: TRect);
var
  R: TRect;
begin
  if not IsRectEmpty(ABounds) then
  begin
    ColorScheme.DrawTabAreaBackground(ACanvas.Handle, ABounds,
      ViewInfo.IsFormCaptionActive or not ViewInfo.SupportNonClientDrawing,
      ViewInfo.IsTabsOnGlass, Ribbon.ApplicationMenuState);
    ACanvas.SaveClipRegion;
    try
      R := ABounds;
      Dec(R.Top, Ribbon.GetRibbonFormCaptionHeight);
      ACanvas.SetClipRegion(TcxRegion.Create(ABounds), roSet);
      ColorScheme.DrawRibbonTopFrameArea(ACanvas.Handle, R, ViewInfo.IsTabsOnGlass);
    finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

procedure TdxRibbonPainter.DrawTabScrollButton(ACanvas: TcxCanvas;
  const ABounds: TRect; ALeft: Boolean; AState: TcxButtonState);
const
  StateMap: array[TcxButtonState] of Integer = (
    DXBAR_NORMAL, DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED, DXBAR_NORMAL
  );
begin
  ColorScheme.DrawTabScrollButton(ACanvas.Handle,
    ABounds, ALeft, StateMap[AState], ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawTabScrollButtonGlyph(ACanvas: TcxCanvas;
  const ABounds: TRect; ALeft: Boolean);
const
  ArrowDirection: array[Boolean] of TcxArrowDirection = (adRight, adLeft);
begin
  cxLookAndFeelPaintersManager.GetPainter(lfsStandard).DrawArrow(ACanvas,
    cxRectInflate(ABounds, -2, 0, -2, -4), ArrowDirection[ALeft], clBlack);
end;

procedure TdxRibbonPainter.DrawHelpButton(
  ACanvas: TcxCanvas; const ABounds: TRect; AState: TcxButtonState);
begin
  ColorScheme.DrawHelpButton(ACanvas.Handle, ABounds, AState, ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawHelpButtonGlyph(ACanvas: TcxCanvas;
  AGlyph: TBitmap; const ABounds: TRect; AState: TcxButtonState);
begin
  if (AGlyph = nil) or AGlyph.Empty then
    ColorScheme.DrawHelpButtonGlyph(ACanvas.Handle, ABounds)
  else
    DrawGlyph(ACanvas, AGlyph, ABounds);
end;

procedure TdxRibbonPainter.DrawMDIButton(ACanvas: TcxCanvas;
  const ABounds: TRect; AButton: TdxBarMDIButton; AState: TcxButtonState);
begin
  ColorScheme.DrawMDIButton(ACanvas.Handle, ABounds, AButton, AState, ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawMDIButtonGlyph(ACanvas: TcxCanvas;
  const ABounds: TRect; AButton: TdxBarMDIButton; AState: TcxButtonState);
begin
  ColorScheme.DrawMDIButtonGlyph(ACanvas.Handle, ABounds, AButton, AState);
end;

procedure TdxRibbonPainter.DrawMinimizeButton(ACanvas: TcxCanvas;
  const ABounds: TRect; AState: TcxButtonState; AMinimized: Boolean);
begin
  ColorScheme.DrawMinimizeRibbonButton(
    ACanvas.Handle, ABounds, AState, AMinimized, ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawMinimizeButtonGlyph(ACanvas: TcxCanvas;
  const R: TRect; AState: TcxButtonState; AGlyph: TdxRibbonMinimizeButtonGlyph);
begin
  ColorScheme.DrawMinimizeRibbonButtonGlyph(
    ACanvas.Handle, R, AState, AGlyph, ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawRibbonFormCaptionText(ACanvas: TcxCanvas;
  const ABounds: TRect; const ADocumentName, ACaption: string; const AData: TdxRibbonFormData);
var
  R: TRect;
begin
  if cxRectIsEmpty(ABounds) then Exit;
  ACanvas.Font := ViewInfo.GetFormCaptionFont(AData.Active);
  R := ABounds;
  if UseAeroNCPaint(AData) then
    DrawRibbonGlassFormCaptionText(ACanvas, ABounds, ADocumentName, ACaption, True)
  else
    cxTextOut(ACanvas.Handle, ADocumentName + ACaption, R,
      CXTO_PREVENT_LEFT_EXCEED or CXTO_CENTER_HORIZONTALLY or
      CXTO_CENTER_VERTICALLY or CXTO_SINGLELINE or CXTO_END_ELLIPSIS,
      0, Length(ADocumentName), nil, clNone, ViewInfo.GetDocumentNameTextColor(AData.Active));
end;

procedure TdxRibbonPainter.DrawRibbonGlassFormCaptionText(ACanvas: TcxCanvas;
  const ABounds: TRect; const ADocumentName, ACaption: string; AIsActive: Boolean);
var
  R: TRect;
  S: string;
  ANeedClipping: Boolean;
begin
  if IsFormZoomed and not IsWinSevenOrLater then
  begin
    ACanvas.Brush.Style := bsClear;
    ACanvas.Font.Color := clWhite;
    ACanvas.DrawTexT(ADocumentName + ACaption, ABounds, cxAlignLeft or
      cxAlignVCenter or cxSingleLine or cxShowEndEllipsis);
    ACanvas.Brush.Style := bsSolid;
  end
  else
  begin
    R := ABounds;
    S := cxGetStringAdjustedToWidth(ACanvas.Handle, ACanvas.Font.Handle,
      ADocumentName + ACaption, cxRectWidth(R) - 2 * dxCaptionGlowRadius);
    R.Right := R.Left + cxTextWidth(ACanvas.Font, S) + 2 * dxCaptionGlowRadius;
    ANeedClipping := ABounds.Right < R.Right;
    if ANeedClipping then
    begin
      ACanvas.SaveClipRegion;
      ACanvas.IntersectClipRect(ABounds);
    end;
    DrawGlowingText(ACanvas.Handle, S, ACanvas.Font, R, ACanvas.Font.Color,
      DT_CENTER or DT_SINGLELINE or DT_END_ELLIPSIS or DT_VCENTER or DT_NOPREFIX, True);
    if ANeedClipping then
      ACanvas.RestoreClipRegion;
  end;
end;

procedure TdxRibbonPainter.DrawRibbonFormCaption(
  ACanvas: TcxCanvas; const ABounds: TRect; const AData: TdxRibbonFormData);
begin
  if not UseAeroNCPaint(AData) then
    ColorScheme.DrawFormCaption(ACanvas.Handle, ABounds, GetRibbonFormInfo(AData));
  if not Ribbon.Hidden and (AData.State <> wsMinimized) and (Ribbon.ApplicationMenuState <> ramsShownAsFullScreenFrame) then
  begin
    if Ribbon.ShowTabHeaders then
      DrawRibbonFormCaptionFrameArea(ACanvas, ABounds, AData);
    if ViewInfo.IsQATAtNonClientArea then
      DrawQuickAccessToolbar(ACanvas, ViewInfo.QuickAccessToolbarBounds, AData.Active);
    ViewInfo.ApplicationButtonViewInfo.Draw(ACanvas);
    if ViewInfo.IsContextsVisible then
      ViewInfo.ContextsViewInfo.Draw(ACanvas);
  end;
  if ViewInfo.CanDrawFormDefaultIcon(AData) then
    DrawFormDefaultIcon(ACanvas, Ribbon.FormCaptionHelper.SysMenuIconBounds);
  DrawRibbonFormCaptionText(ACanvas, ViewInfo.FormCaptionBounds, ViewInfo.DocumentName, ViewInfo.Caption, AData);
end;

procedure TdxRibbonPainter.DrawRibbonFormCaptionFrameArea(
  ACanvas: TcxCanvas; R: TRect; const AData: TdxRibbonFormData);
var
  ABorderWidths: TRect;
begin
  ACanvas.SaveClipRegion;
  try
    ABorderWidths := Ribbon.GetWindowBordersWidth;
    ACanvas.SetClipRegion(TcxRegion.Create(R), roSet);
    Dec(R.Right, ABorderWidths.Right);
    Inc(R.Left, ABorderWidths.Left);
    Inc(R.Bottom, ViewInfo.TabsHeight);
    ColorScheme.DrawRibbonTopFrameArea(ACanvas.Handle, R, ViewInfo.IsTabsOnGlass);
  finally
    ACanvas.RestoreClipRegion;
  end;
end;

procedure TdxRibbonPainter.DrawRibbonTopFrameAreaSeparator(ACanvas: TcxCanvas);
var
  R: TRect;
begin
  R := ViewInfo.TabsAreaBounds;
  R.Top := R.Bottom - 1;
  R.Bottom := R.Top + 2;
  ColorScheme.DrawRibbonTopFrameAreaSeparator(ACanvas.Handle, R);
  ACanvas.ExcludeClipRect(cxRectSetHeight(R, 1));
end;

procedure TdxRibbonPainter.DrawRibbonFormBorderIcon(ACanvas: TcxCanvas;
  const ABounds: TRect; AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState);
begin
  ColorScheme.DrawFormBorderIcon(ACanvas.Handle, ABounds, AIcon, AState, ColorSchemeAccent);
end;

procedure TdxRibbonPainter.DrawRibbonFormBorders(ACanvas: TcxCanvas;
  const ABordersWidth: TRect; const AData: TdxRibbonFormData);
begin
  ColorScheme.DrawFormBorders(ACanvas.Handle, ABordersWidth, GetRibbonFormInfo(AData));
end;

procedure TdxRibbonPainter.DrawEmptyRibbon(ACanvas: TcxCanvas);
var
  ABrush: HBRUSH;
  APrevBkColor: TColor;
begin
  APrevBkColor := GetBkColor(ACanvas.Handle);
  SetBkColor(ACanvas.Handle, clSilver);
  ABrush := CreateHatchBrush(HS_BDIAGONAL, clBlack);
  FillRect(ACanvas.Handle, ViewInfo.Bounds, ABrush);
  DeleteObject(ABrush);
  SetBkColor(ACanvas.Handle, APrevBkColor);
end;

function TdxRibbonPainter.GetFormIconHandle: HICON;
var
  F: TCustomForm;
begin
  F := GetParentForm(Ribbon);
  if F is TForm then
    Result := TForm(F).Icon.Handle
  else
    Result := 0;
  if Result = 0 then
    Result := Application.Icon.Handle;
end;

function TdxRibbonPainter.GetGroupCaptionBottomOffset: Integer;
begin
  Result := Ribbon.SkinGetPartSize(rspTabGroupBottomOffset);
end;

function TdxRibbonPainter.GetIsFormZoomed: Boolean;
var
  F: TCustomForm;
begin
  F := Ribbon.RibbonForm;
  Result := (F <> nil) and F.HandleAllocated and IsZoomed(F.Handle);
end;

function TdxRibbonPainter.GetRibbonFormInfo(const AData: TdxRibbonFormData): TdxRibbonFormInfo;
begin
  ZeroMemory(@Result, SizeOf(Result));
  Result.FormData := AData;
  Result.ColorSchemeAccent := ColorSchemeAccent;
  Result.ApplicationMenuState := Ribbon.ApplicationMenuState;
  Result.IsRibbonHidden := Ribbon.Hidden;
  Result.HasStatusBar := Ribbon.HasStatusBar;
  Result.CaptionHeight := Ribbon.GetRibbonFormCaptionHeight;
  Result.CaptionAreaExtention := Ribbon.GetRibbonFormCaptionAreaExtention;
  Result.TabsHeight := ViewInfo.TabsHeight;
  Result.RibbonHeight := Ribbon.Height;
end;

function TdxRibbonPainter.GetColorScheme: TdxCustomRibbonSkin;
begin
  Result := Ribbon.ColorScheme;
end;

function TdxRibbonPainter.GetColorSchemeAccent: TdxRibbonColorSchemeAccent;
begin
  Result := Ribbon.ColorSchemeAccent;
end;

function TdxRibbonPainter.GetViewInfo: TdxRibbonViewInfo;
begin
  Result := Ribbon.ViewInfo;
end;

{ TdxRibbonHitInfo }

constructor TdxRibbonHitInfo.Create(AOwner: TdxRibbonViewInfo);
begin
  inherited Create;
  FOwner := AOwner;
end;

function TdxRibbonHitInfo.GetHitObjectAsButton: TdxRibbonCustomButtonViewInfo;
begin
  if HitObject is TdxRibbonCustomButtonViewInfo then
    Result := TdxRibbonCustomButtonViewInfo(HitObject)
  else
    Result := nil;
end;

function TdxRibbonHitInfo.GetHitObjectAsContext: TdxRibbonContext;
begin
  if HitObject is TdxRibbonContext then
    Result := TdxRibbonContext(HitObject)
  else
    Result := nil;
end;

function TdxRibbonHitInfo.GetHitObjectAsTab: TdxRibbonTab;
begin
  if HitObject is TdxRibbonTab then
    Result := TdxRibbonTab(HitObject)
  else
    Result := nil;
end;

procedure TdxRibbonHitInfo.Calculate(const P: TPoint);
begin
  Reset;
  FHitPoint := P;
  Owner.CalculateHitInfo(Self);
end;

function TdxRibbonHitInfo.Compare(const AHitTest: TdxRibbonHitInfo): Boolean;
begin
  Result := (HitTest = AHitTest.HitTest) and (HitObject = AHitTest.HitObject);
end;

procedure TdxRibbonHitInfo.Reset;
begin
  FHitTest := rhtNone;
  FHitObject := nil;
  FHitPoint := cxInvalidPoint;
end;

{ TdxRibbonCustomViewInfo }

constructor TdxRibbonCustomViewInfo.Create(AOwner: TdxRibbonViewInfo);
begin
  inherited Create;
  FOwner := AOwner;
end;

procedure TdxRibbonCustomViewInfo.Calculate(const ABounds: TRect);
begin
  FBounds := ABounds;
end;

procedure TdxRibbonCustomViewInfo.Invalidate;
begin
  InvalidateRect(Bounds);
end;

procedure TdxRibbonCustomViewInfo.InvalidateRect(const R: TRect);
begin
  if not Ribbon.IsDestroying then
    Ribbon.InvalidateRect(R, False);
end;

function TdxRibbonCustomViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
begin
  Result := False;
end;

function TdxRibbonCustomViewInfo.GetRibbon: TdxCustomRibbon;
begin
  Result := Owner.Ribbon;
end;

{ TdxRibbonCustomContainerViewInfo }

constructor TdxRibbonCustomContainerViewInfo.Create(AOwner: TdxRibbonViewInfo);
begin
  inherited Create(AOwner);
  FCells := TcxObjectList.Create;
end;

destructor TdxRibbonCustomContainerViewInfo.Destroy;
begin
  FreeAndNil(FCells);
  inherited Destroy;
end;

function TdxRibbonCustomContainerViewInfo.AddItem(AObject: TObject): Integer;
begin
  Result := FCells.Add(AObject);
end;

procedure TdxRibbonCustomContainerViewInfo.Clear;
begin
  FCells.Clear;
end;

function TdxRibbonCustomContainerViewInfo.GetCount: Integer;
begin
  Result := FCells.Count;
end;

function TdxRibbonCustomContainerViewInfo.GetItem(Index: Integer): TObject;
begin
  Result := FCells[Index];
end;

{ TdxRibbonCustomButtonAccessibilityHelper }

constructor TdxRibbonCustomButtonAccessibilityHelper.CreateEx(
  AButtonViewInfo: TdxRibbonCustomButtonViewInfo);
begin
  Create(AButtonViewInfo.Ribbon);
  FButtonViewInfo := AButtonViewInfo;
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetBarManager: TdxBarManager;
begin
  Result := Ribbon.BarManager;
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetNextAccessibleObject(
  ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;
begin
  Result := nil;
  case ADirection of
    andLeft, andRight:
      Result := Ribbon.GetNextHorizontalAccessibleObject(Self, ADirection);
    andUp:
      Result := Self;
  end;
  if Result = nil then
    Result := inherited GetNextAccessibleObject(ADirection);
end;

function TdxRibbonCustomButtonAccessibilityHelper.HandleNavigationKey(var AKey: Word): Boolean;
begin
  Result := inherited HandleNavigationKey(AKey);
  if not Result then
  begin
    Result := AKey in [VK_SPACE, VK_RETURN];
    if Result then
    begin
      Unselect(nil);
      ButtonViewInfo.Click;
    end;
  end;
end;

function TdxRibbonCustomButtonAccessibilityHelper.IsNavigationKey(AKey: Word): Boolean;
begin
  Result := inherited IsNavigationKey(AKey) or (AKey in [VK_ESCAPE, VK_SPACE, VK_RETURN]);
end;

procedure TdxRibbonCustomButtonAccessibilityHelper.Select(ASetFocus: Boolean);
begin
  inherited Select(ASetFocus);
  ButtonViewInfo.Invalidate;
end;

procedure TdxRibbonCustomButtonAccessibilityHelper.Unselect(
  ANextSelectedObject: IdxBarAccessibilityHelper);
begin
  inherited Unselect(ANextSelectedObject);
  ButtonViewInfo.Invalidate;
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetAssignedKeyTip: string;
begin
  Result := '';
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetDefaultKeyTip: string;
begin
  Result := '';
end;

procedure TdxRibbonCustomButtonAccessibilityHelper.GetKeyTipData(AKeyTipsData: TList);
begin
  //nothing
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetOwnerObjectWindow: HWND;
begin
  Result := Parent.OwnerObjectWindow;
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetParent: TcxAccessibilityHelper;
begin
  Result := Ribbon.IAccessibilityHelper.GetHelper;
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetScreenBounds(
  AChildID: TcxAccessibleSimpleChildElementID): TRect;
begin
  if Visible then
  begin
    Result := ButtonViewInfo.Bounds;
    Result := cxRectOffset(Result, Ribbon.ClientToScreen(Result.TopLeft));
  end
  else
    Result := cxEmptyRect;
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetSelectable: Boolean;
begin
  Result := Visible;
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetState(
  AChildID: TcxAccessibleSimpleChildElementID): Integer;
begin
  Result := Parent.States[cxAccessibleObjectSelfID];
end;

function TdxRibbonCustomButtonAccessibilityHelper.GetRibbon: TdxCustomRibbon;
begin
  Result := TdxCustomRibbon(FOwnerObject);
end;

{ TdxRibbonCustomButtonViewInfo }

constructor TdxRibbonCustomButtonViewInfo.Create(AOwner: TdxRibbonCustomContainerViewInfo);
begin
  inherited Create;
  FState := cxbsNormal;
  FOwner := AOwner;
end;

destructor TdxRibbonCustomButtonViewInfo.Destroy;
begin
  dxFader.Remove(Self);
  BarAccessibilityHelperOwnerObjectDestroyed(FAccessibilityHelper);
  inherited Destroy;
end;

function TdxRibbonCustomButtonViewInfo.CanFade: Boolean;
begin
  Result := Assigned(Ribbon) and Ribbon.CanFade;
end;

procedure TdxRibbonCustomButtonViewInfo.CalculateState;
begin
  if not Enabled then
    State := cxbsDisabled
  else
    if Ribbon.Controller.PressedButton = Self then
      State := cxbsPressed
    else
      if Ribbon.Controller.HotButton = Self then
        State := cxbsHot
      else
        State := cxbsNormal;
end;

procedure TdxRibbonCustomButtonViewInfo.Click;
begin
end;

function TdxRibbonCustomButtonViewInfo.CreateAccessibilityHelper: TdxRibbonCustomButtonAccessibilityHelper;
begin
  Result := TdxRibbonCustomButtonAccessibilityHelper.CreateEx(Self);
end;

function TdxRibbonCustomButtonViewInfo.GetIsEnabled: Boolean;
begin
  Result := Ribbon.ApplicationMenuState <= ramsShownAsMenu;
end;

procedure TdxRibbonCustomButtonViewInfo.Draw(ACanvas: TcxCanvas);
begin
  if not cxRectIsEmpty(Bounds) and ACanvas.RectVisible(Bounds) then
  begin
    if not dxFader.DrawFadeImage(Self, ACanvas.Handle, Bounds) then
      DrawButton(ACanvas, Bounds, State);
    DrawButtonGlyph(ACanvas, Bounds, State);
  end;
end;

procedure TdxRibbonCustomButtonViewInfo.DrawButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
end;

procedure TdxRibbonCustomButtonViewInfo.DrawButtonGlyph(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
end;

procedure TdxRibbonCustomButtonViewInfo.DrawFadeImage;
begin
  Invalidate;
end;

procedure TdxRibbonCustomButtonViewInfo.Invalidate;
begin
  Owner.InvalidateRect(Bounds);
end;

function TdxRibbonCustomButtonViewInfo.GetAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  if FAccessibilityHelper = nil then
    FAccessibilityHelper := CreateAccessibilityHelper;
  Result := FAccessibilityHelper;
end;

function TdxRibbonCustomButtonViewInfo.GetFadingOptions: TdxFadingOptions;
begin
  Result := Ribbon.OptionsFading.BarItems;
end;

procedure TdxRibbonCustomButtonViewInfo.GetFadingImages(
  out AFadeOutImage, AFadeInImage: TcxBitmap);
begin
  AFadeInImage := TcxBitmap32.CreateSize(Bounds, True);
  AFadeOutImage := TcxBitmap32.CreateSize(Bounds, True);
  DrawButton(AFadeInImage.cxCanvas, AFadeInImage.ClientRect, cxbsHot);
  DrawButton(AFadeOutImage.cxCanvas, AFadeOutImage.ClientRect, cxbsNormal);
end;

function TdxRibbonCustomButtonViewInfo.GetHint: string;
begin
  Result := '';
end;

function TdxRibbonCustomButtonViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
begin
  Result := cxRectPtIn(Bounds, AHitInfo.HitPoint);
  if Result then
  begin
    AHitInfo.HitTest := rhtCustomButton;
    AHitInfo.HitObject := Self;
  end;
end;

function TdxRibbonCustomButtonViewInfo.GetPainter: TdxRibbonPainter;
begin
  Result := ViewInfo.Painter;
end;

function TdxRibbonCustomButtonViewInfo.GetRibbon: TdxCustomRibbon;
begin
  Result := ViewInfo.Ribbon;
end;

function TdxRibbonCustomButtonViewInfo.GetState: TcxButtonState;
begin
  Result := FState;
  if (Result = cxbsNormal) and AccessibilityHelper.IsSelected then
    Result := cxbsHot;
end;

function TdxRibbonCustomButtonViewInfo.GetViewInfo: TdxRibbonViewInfo;
begin
  Result := Owner.Owner;
end;

procedure TdxRibbonCustomButtonViewInfo.SetState(AValue: TcxButtonState);
begin
  if AValue <> State then
  begin
    if CanFade then
    begin
      if AValue = cxbsHot then
        dxFader.FadeIn(Self);
      if AValue = cxbsNormal then
        dxFader.FadeOut(Self);
    end;
    FState := AValue;
    Invalidate;
  end;
end;

{ TdxRibbonTabViewInfo }

constructor TdxRibbonTabViewInfo.Create(ATab: TdxRibbonTab);
begin
  inherited Create;
  FTab := ATab;
  FPainter := GetPainterClass.Create(Ribbon);
end;

destructor TdxRibbonTabViewInfo.Destroy;
begin
  FreeAndNil(FPainter);
  inherited Destroy;
end;

procedure TdxRibbonTabViewInfo.Calculate(const ABounds: TRect; ASeparatorAlpha: Byte);
begin
  Bounds := ABounds;
  FSeparatorAlphaValue := ASeparatorAlpha;
  if HasSeparator then
    FSeparatorBounds := GetSeparatorBounds
  else
    FSeparatorBounds := cxEmptyRect;

  FTextBounds := GetTextBounds;
end;

function TdxRibbonTabViewInfo.HasSeparator: Boolean;
begin
  Result := FCanHasSeparator and (FSeparatorAlphaValue > 0);
end;

procedure TdxRibbonTabViewInfo.Paint(ACanvas: TcxCanvas);
begin
  if not dxFader.DrawFadeImage(Tab, ACanvas.Handle, Bounds) then
    DrawBackground(ACanvas, Bounds, State);

  ACanvas.Font := Font;
  Painter.DrawText(ACanvas, TextBounds, Tab.Caption, SeparatorAlphaValue = 255, IsPaintOnGlass);
  if HasSeparator then
    Painter.DrawTabSeparator(ACanvas, SeparatorBounds, SeparatorAlphaValue);
  if ContextBegin then
    Painter.DrawContextTabSeparator(ACanvas, cxRectSetWidth(Bounds, ContextTabSeparatorWidth), True);
  if ContextEnd then
    Painter.DrawContextTabSeparator(ACanvas, cxRectSetRight(Bounds, Bounds.Right, ContextTabSeparatorWidth), False);
  if Tab.DesignSelectionHelper.IsComponentSelected then
    ACanvas.DrawDesignSelection(cxRectInflate(Bounds, -2, -2));
end;

procedure TdxRibbonTabViewInfo.DrawBackground(
  ACanvas: TcxCanvas; const R: TRect; AState: TdxRibbonTabState);
begin
  if Tab.Context = nil then
    Painter.DrawBackground(ACanvas, R, AState)
  else
    Painter.DrawContextTabBackground(ACanvas, Tab.Context.Color, R, AState);
end;

procedure TdxRibbonTabViewInfo.CalculateWidths(AViewInfo: TdxRibbonViewInfo);
begin
  Canvas.Font := Ribbon.Fonts.TabHeader;
  FTextWidth := Canvas.TextWidth(Tab.Caption);
  FOptimalWidth := FTextWidth + dxRibbonOptimalTabSpace;
  if ContextBegin then
  begin
    Inc(FOptimalWidth, dxExtraContextGap);
    if ContextEnd then
      FOptimalWidth := Max(OptimalWidth,
        AViewInfo.GetContextCaptionWidth(Tab.Context.Caption) + dxExtraContextGap);
  end;
  FMinWidth := Max(Canvas.TextWidth(Copy(Tab.Caption, 1, 3)) + dxRibbonTabTextOffset * 2,
    dxRibbonOptimalTabSpace);
end;

function TdxRibbonTabViewInfo.GetContextTabSeparatorWidth: Integer;
begin
  Result := Ribbon.SkinGetPartSize(rspContextTabSeparatorBegin);
end;

function TdxRibbonTabViewInfo.GetIsTabActive: Boolean;
begin
  Result := Tab.Active and Ribbon.AreGroupsVisible and (Ribbon.ApplicationMenuState <= ramsShownAsMenu);
end;

function TdxRibbonTabViewInfo.GetPainterClass: TdxRibbonTabPainterClass;
begin
  Result := TdxRibbonTabPainter;
end;

function TdxRibbonTabViewInfo.GetTextBounds: TRect;
begin
  Result := cxRectContent(Bounds, Ribbon.ViewInfo.GetTabContentOffsets);
end;

function TdxRibbonTabViewInfo.GetSeparatorBounds: TRect;
begin
  Result := cxRect(Bounds.Right - dxRibbonTabSeparatorWidth, Bounds.Top, Bounds.Right, Bounds.Bottom - 1);
end;

function TdxRibbonTabViewInfo.GetState: TdxRibbonTabState;
const
  ActiveHotMap: array[Boolean] of TdxRibbonTabState = (rtsActive, rtsActiveHot);
  FocusMap: array[Boolean] of TdxRibbonTabState = (rtsHot, rtsFocused);
  HotMap: array[Boolean] of TdxRibbonTabState = (rtsNormal, rtsHot);
begin
  if Tab.Focused then
    Result := FocusMap[Ribbon.AreGroupsVisible]
  else
    if not (Tab.Highlighted or Tab.Active) then
      Result := rtsNormal
    else
      if IsTabActive then
        Result := ActiveHotMap[Tab.Highlighted and not Ribbon.IsPopupGroupsMode]
      else
        Result := HotMap[Tab.Highlighted];
end;

function TdxRibbonTabViewInfo.IsSelected: Boolean;
begin
  Result := Tab.DesignSelectionHelper.IsComponentSelected;
end;

function TdxRibbonTabViewInfo.PrepareFadeImage(ADrawHot: Boolean): TcxBitmap;

  function GetFadeImageState: TdxRibbonTabState;
  const
    ActiveStatesMap: array[Boolean] of TdxRibbonTabState = (rtsActive, rtsActiveHot);
    StatesMap: array[Boolean] of TdxRibbonTabState = (rtsNormal, rtsHot);
  begin
    if State = rtsFocused then
      Result := State
    else
      if IsTabActive then
        Result := ActiveStatesMap[ADrawHot and not Ribbon.IsPopupGroupsMode]
      else
        Result := StatesMap[ADrawHot];
  end;

begin
  Result := TcxBitmap32.CreateSize(Bounds, True);
  Result.Canvas.Font := Font;
  DrawBackground(Result.cxCanvas, Result.ClientRect, GetFadeImageState);
end;

function TdxRibbonTabViewInfo.GetCanvas: TcxCanvas;
begin
  Result := Ribbon.Canvas;
end;

function TdxRibbonTabViewInfo.GetFont: TFont;

  function GetTabState: Integer;
  begin
    //(rtsNormal, rtsHot, rtsActive, rtsActiveHot, rtsFocused);
    if IsTabActive then
      Result := DXBAR_ACTIVE
    else
      if State = rtsNormal then
        Result := DXBAR_NORMAL
      else
        Result := DXBAR_HOT;
  end;

begin
  Result := Ribbon.Fonts.GetTabHeaderFont(GetTabState, Tab.Context);
end;

function TdxRibbonTabViewInfo.GetIsPaintOnGlass: Boolean;
begin
  Result := Ribbon.ViewInfo.IsTabsOnGlass;
end;

function TdxRibbonTabViewInfo.GetRibbon: TdxCustomRibbon;
begin
  Result := Tab.Ribbon;
end;

{ TdxRibbonTabsScrollButtonViewInfo }

procedure TdxRibbonTabsScrollButtonViewInfo.DrawButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawTabScrollButton(ACanvas, R, FScrollButton = rsbLeft, AState);
end;

procedure TdxRibbonTabsScrollButtonViewInfo.DrawButtonGlyph(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawTabScrollButtonGlyph(ACanvas, R, FScrollButton = rsbLeft);
end;

function TdxRibbonTabsScrollButtonViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
const
  HitTestMap: array[TdxRibbonScrollButton] of TdxRibbonHitTest = (rhtTabScrollLeft, rhtTabScrollRight);
begin
  Result := inherited GetHitInfo(AHitInfo);
  if Result then
    AHitInfo.HitTest := HitTestMap[FScrollButton];
end;

{ TdxRibbonTabsViewInfo }

constructor TdxRibbonTabsViewInfo.Create(AOwner: TdxRibbonViewInfo);

  function CreateButton(AScrollButton: TdxRibbonScrollButton): TdxRibbonTabsScrollButtonViewInfo;
  begin
    Result := TdxRibbonTabsScrollButtonViewInfo.Create(Self);
    Result.FScrollButton := AScrollButton;
  end;

begin
  inherited Create(AOwner);
  FBitmap := TcxBitmap32.Create;
  FScrollButtonLeft := CreateButton(rsbLeft);
  FScrollButtonRight := CreateButton(rsbRight);
end;

destructor TdxRibbonTabsViewInfo.Destroy;
begin
  FreeAndNil(FScrollButtonRight);
  FreeAndNil(FScrollButtonLeft);
  FreeAndNil(FBitmap);
  inherited Destroy;
end;

procedure TdxRibbonTabsViewInfo.BalancedReduce(ATotalDelta: Integer);
var
  I: Integer;
  ALimit: Integer;
  AHasReduce: Boolean;
begin
  FSeparatorAlpha := 255;
  ALimit := GetLongestTabWidth - 1;
  repeat
    AHasReduce := False;
    for I := 0 to Count - 1 do
      with Items[I] do
        if (Width > ALimit) and (Width > GetRealMinItemWidth(I)) then
        begin
          AHasReduce := True;
          Dec(FWidth);
          Dec(ATotalDelta);
          if ATotalDelta = 0 then
            Break;
        end;
    Dec(ALimit);
  until (ATotalDelta = 0) or not AHasReduce;
  FNeedShowHint := AHasReduce;
end;

procedure TdxRibbonTabsViewInfo.Calculate(const ABounds: TRect);
var
  I, AHigh, AWidth: Integer;
begin
  inherited Calculate(ABounds);
  FNeedShowHint := False;
  FScrollButtons := [];
  FSeparatorAlpha := 0;
  AWidth := ABounds.Right - ABounds.Left;
  FTotalMinimalWidth := 0;
  FTotalOptimalWidth := 0;
  FHasButtonOnRight := Owner.TabsAreaButtonsViewInfo.Count > 0;
  AHigh := Count - 1;
  for I := 0 to AHigh do
    with Items[I] do
    begin
      CalculateWidths(Owner);
      Inc(FTotalOptimalWidth, OptimalWidth);
      Inc(FTotalMinimalWidth, MinWidth);
      FCanHasSeparator := (I < AHigh) or FHasButtonOnRight;
    end;

  if FTotalOptimalWidth <= AWidth then
    CalculateSimpleTabLayout
  else
    if FTotalMinimalWidth <= AWidth then
      CalculateComplexTabLayout
    else
      CalculateScrollingTabLayout;

  CalculateScrollButtons;
  FBitmap.SetSize(cxRectWidth(Bounds), cxRectHeight(Bounds));
end;

procedure TdxRibbonTabsViewInfo.CalculateComplexTabLayout;
var
  I, ADelta, ASimpleReduceWidth: Integer;
  R: TRect;
begin
  RemoveScrolling;
  R := Bounds;
  ADelta := FTotalOptimalWidth - (R.Right - R.Left);
  ASimpleReduceWidth := dxRibbonTabIndent * Count;
  if ADelta <= ASimpleReduceWidth then
    SimpleReduce(ADelta)
  else
  begin
    Dec(ADelta, ASimpleReduceWidth);
    BalancedReduce(ADelta);
  end;
  for I := 0 to Count - 1 do
    with Items[I] do
    begin
      R.Right := R.Left + FWidth;
      Calculate(R, FSeparatorAlpha);
      R.Left := R.Right;
    end;
end;

procedure TdxRibbonTabsViewInfo.CalculateScrollingTabLayout;
var
  I: Integer;
  R: TRect;
begin
  R := Bounds;
  FSeparatorAlpha := 255;
  FScrollWidth := GetScrollWidth;
  CheckScrollPosition(FScrollPosition);
  Dec(R.Left, FScrollPosition);
  for I := 0 to Count - 1 do
  begin
    R.Right := R.Left + GetRealMinItemWidth(I);
    Items[I].Calculate(R, FSeparatorAlpha);
    R.Left := R.Right;
  end;

  if FScrollPosition = 0 then
    FScrollButtons := [rsbRight]
  else
    if FScrollPosition = FScrollWidth then
      FScrollButtons := [rsbLeft]
    else
      FScrollButtons := [rsbLeft, rsbRight];

  FNeedShowHint := True;
end;

procedure TdxRibbonTabsViewInfo.CalculateScrollButtons;
var
  AButtonWidth: Integer;
begin
  AButtonWidth := Owner.ScrollButtonWidth;
  FScrollButtonLeft.Bounds := cxRectSetWidth(Bounds, IfThen(rsbLeft in ScrollButtons, AButtonWidth));
  FScrollButtonRight.Bounds := cxRectSetRight(Bounds, Bounds.Right, IfThen(rsbRight in ScrollButtons, AButtonWidth));
end;

procedure TdxRibbonTabsViewInfo.CalculateSimpleTabLayout;
var
  I, AHight: Integer;
  R: TRect;
begin
  RemoveScrolling;
  R := Bounds;
  AHight := Count - 1;
  for I := 0 to AHight do
    with Items[I] do
    begin
      R.Right := R.Left + OptimalWidth;
      if ContextBegin then
        Inc(R.Left, dxExtraContextGap);
      Calculate(R, 0);
      R.Left := R.Right;
    end;
end;

procedure TdxRibbonTabsViewInfo.CheckScrollPosition(var Value: Integer);
begin
  Value := Min(Max(0, Value), FScrollWidth);
end;

procedure TdxRibbonTabsViewInfo.CreateContextualTabsViewInfoCells;
var
  AContext: TdxRibbonContext;
  AContextBegin: Boolean;
  ATab: TdxRibbonTab;
  ATabViewInfo: TdxRibbonTabViewInfo;
  I, J: Integer;
begin
  for I := 0 to Owner.Ribbon.Contexts.Count - 1 do
  begin
    AContext := Owner.Ribbon.Contexts[I];
    if not AContext.Visible then
      Continue;
    AContextBegin := True;
    ATabViewInfo := nil;
    for J := 0 to Owner.Ribbon.TabCount - 1 do
    begin
      ATab := Owner.Ribbon.Tabs[J];
      if ATab.Visible and (ATab.Context = AContext) then
      begin
        ATabViewInfo := Owner.GetTabViewInfoClass.Create(ATab);
        if AContextBegin then
        begin
          ATabViewInfo.ContextBegin := True;
          AContextBegin := False;
        end;
        AddItem(ATabViewInfo);
      end;
    end;
    if Assigned(ATabViewInfo) then
      ATabViewInfo.ContextEnd := True;
  end;
end;

procedure TdxRibbonTabsViewInfo.CreateTabsViewInfoCells;
var
  ATab: TdxRibbonTab;
  I: Integer;
begin
  for I := 0 to Owner.Ribbon.TabCount - 1 do
  begin
    ATab := Owner.Ribbon.Tabs[I];
    if ATab.Visible and (ATab.Context = nil) then
      AddItem(Owner.GetTabViewInfoClass.Create(ATab));
  end;
end;

procedure TdxRibbonTabsViewInfo.Draw(ACanvas: TcxCanvas);
var
  I: Integer;
begin
  Bitmap.cxCanvas.WindowOrg := Bounds.TopLeft;
  cxBitBlt(Bitmap.Canvas.Handle, ACanvas.Handle, Bounds, Bounds.TopLeft, SRCCOPY);
  for I := 0 to Count - 1 do
    Items[I].Paint(Bitmap.cxCanvas);
  FScrollButtonRight.Draw(Bitmap.cxCanvas);
  FScrollButtonLeft.Draw(Bitmap.cxCanvas);
  cxBitBlt(ACanvas.Handle, Bitmap.Canvas.Handle, Bounds, Bounds.TopLeft, SRCCOPY);
end;

function TdxRibbonTabsViewInfo.Last: TdxRibbonTabViewInfo;
begin
  Result := TdxRibbonTabViewInfo(FCells.Last);
end;

procedure TdxRibbonTabsViewInfo.MakeTabVisible(ATab: TdxRibbonTab);
var
  P, I: Integer;
  R: TRect;
begin
  if ScrollButtons = [] then Exit;
  for I := 0 to Count - 1 do
    if Items[I].Tab = ATab then
    begin
      R := Items[I].Bounds;
      P := ScrollPosition;
      if R.Left < Bounds.Left then
      begin
        Dec(P, Bounds.Left - R.Left);
        if I > 0 then
          Dec(P, Owner.ScrollButtonWidth);
      end
      else if R.Right > Bounds.Right then
      begin
        Inc(P, R.Right - Bounds.Right);
        if I < Count - 1 then
          Inc(P, Owner.ScrollButtonWidth);
      end;
      SetScrollPosition(P);
      Break;
    end;
end;

procedure TdxRibbonTabsViewInfo.RecreateViewInfoCells;
begin
  Clear;
  CreateTabsViewInfoCells;
  CreateContextualTabsViewInfoCells;
end;

procedure TdxRibbonTabsViewInfo.RemoveScrolling;
begin
  FScrollPosition := 0;
  FScrollButtons := [];
  CalculateScrollButtons;
end;

procedure TdxRibbonTabsViewInfo.SimpleReduce(ATotalDelta: Integer);
var
  I, ADelta, ARemainder: Integer;
begin
  FSeparatorAlpha := MulDiv(ATotalDelta, 255,
    Count * (dxRibbonOptimalTabSpace - dxRibbonTabTextOffset * 2));
  ADelta := ATotalDelta div Count;
  ARemainder := ATotalDelta - (Count * ADelta);
  for I := Count - 1 downto 0 do
    with Items[I] do
    begin
      FWidth := OptimalWidth - ADelta;
      if Count - I <= ARemainder then
        Dec(FWidth);
    end;
end;

procedure TdxRibbonTabsViewInfo.UpdateButtonsStates;
begin
  FScrollButtonLeft.CalculateState;
  FScrollButtonRight.CalculateState;
end;

procedure TdxRibbonTabsViewInfo.UpdateDockControls;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].Tab.UpdateDockControl;
end;

function TdxRibbonTabsViewInfo.GetController: TdxRibbonController;
begin
  Result := Ribbon.Controller;
end;

function TdxRibbonTabsViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
var
  I: Integer;
begin
  Result := FScrollButtonLeft.GetHitInfo(AHitInfo) or FScrollButtonRight.GetHitInfo(AHitInfo);
  if not Result and cxRectPtIn(GetRealBounds, AHitInfo.HitPoint) then
    for I := 0 to Count - 1 do
    begin
      Result := cxRectPtIn(Items[I].Bounds, AHitInfo.HitPoint);
      if Result then
      begin
        AHitInfo.HitTest := rhtTab;
        AHitInfo.HitObject := Items[I].Tab;
        Break;
      end;
    end;
end;

function TdxRibbonTabsViewInfo.GetLongestTabWidth: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to Count - 1 do
    with Items[I] do
    begin
      FWidth := TextWidth + dxRibbonTabTextOffset * 2;
      Result := Max(Result, Width);
    end;
end;

function TdxRibbonTabsViewInfo.GetPainter: TdxRibbonPainter;
begin
  Result := Owner.Painter;
end;

function TdxRibbonTabsViewInfo.GetRealBounds: TRect;
begin
  Result := Bounds;
  Result.Left := FScrollButtonLeft.Bounds.Right;
  Result.Right := FScrollButtonRight.Bounds.Left;
end;

function TdxRibbonTabsViewInfo.GetRealMinItemWidth(Index: Integer): Integer;
begin
  Result := GetTabViewInfo(Index).MinWidth;
  if Index < Count - 1 then
    Inc(Result, dxRibbonTabSeparatorWidth);
end;

function TdxRibbonTabsViewInfo.GetScrollWidth: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to Count - 1 do
    Inc(Result, GetRealMinItemWidth(I));
  Dec(Result, Bounds.Right - Bounds.Left);
end;

function TdxRibbonTabsViewInfo.GetTabViewInfo(
  Index: Integer): TdxRibbonTabViewInfo;
begin
  Result := TdxRibbonTabViewInfo(inherited Items[Index]);
end;

procedure TdxRibbonTabsViewInfo.SetScrollPosition(Value: Integer);
begin
  CheckScrollPosition(Value);
  if FScrollPosition <> Value then
  begin
    FScrollPosition := Value;
    Owner.Ribbon.Changed;
  end;
end;

{ TdxRibbonHelpButtonViewInfo }

procedure TdxRibbonHelpButtonViewInfo.Click;
begin
  Ribbon.DoHelpButtonClick;
end;

procedure TdxRibbonHelpButtonViewInfo.DrawButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawHelpButton(ACanvas, R, AState);
end;

procedure TdxRibbonHelpButtonViewInfo.DrawButtonGlyph(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawHelpButtonGlyph(ACanvas, HelpButton.Glyph, GlyphBounds, AState);
end;

function TdxRibbonHelpButtonViewInfo.GetHelpButton: TdxRibbonHelpButton;
begin
  Result := Ribbon.HelpButton;
end;

function TdxRibbonHelpButtonViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
begin
  Result := inherited GetHitInfo(AHitInfo);
  if Result then
    AHitInfo.HitTest := rhtHelpButton;
end;

function TdxRibbonHelpButtonViewInfo.GetGlyphBounds: TRect;
var
  AIconSize: TSize;
begin
  if (HelpButton.Glyph = nil) or HelpButton.Glyph.Empty then
    AIconSize := cxSize(GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON))
  else
    AIconSize := cxSize(HelpButton.Glyph.Width, HelpButton.Glyph.Height);

  Result := Bounds;
  if HelpButton.StretchGlyph then
    AIconSize := cxSize(cxRectProportionalStretch(Result, AIconSize.cx, AIconSize.cy));
  Result := cxRectCenter(Result, AIconSize);
end;

function TdxRibbonHelpButtonViewInfo.GetIsEnabled: Boolean;
begin
  Result := True;
end;

{ TdxRibbonMinimizeButtonViewInfo }

procedure TdxRibbonMinimizeButtonViewInfo.Click;
begin
  if Enabled then
    Ribbon.ShowTabGroups := not Ribbon.ShowTabGroups;
end;

procedure TdxRibbonMinimizeButtonViewInfo.DrawButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawMinimizeButton(ACanvas, R, AState, not Ribbon.ShowTabGroups);
end;

procedure TdxRibbonMinimizeButtonViewInfo.DrawButtonGlyph(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawMinimizeButtonGlyph(ACanvas, R, AState, State);
end;

function TdxRibbonMinimizeButtonViewInfo.GetHint: string;
begin
  case State of
    rmbRestore:
      Result := cxGetResourceString(@dxSBAR_RIBBON_RESTORERIBBON);
    rmbPin:
      Result := cxGetResourceString(@dxSBAR_RIBBON_PINRIBBON);
  else
    Result := cxGetResourceString(@dxSBAR_RIBBON_MINIMIZERIBBON);
  end;
end;

function TdxRibbonMinimizeButtonViewInfo.GetRibbon: TdxCustomRibbon;
begin
  Result := Owner.Owner.Ribbon;
end;

function TdxRibbonMinimizeButtonViewInfo.GetState: TdxRibbonMinimizeButtonGlyph;
begin
  if Ribbon.ShowTabGroups then
    Result := rmbMinimize
  else
    if Ribbon.IsPopupGroupsMode then
      Result := rmbPin
    else
      Result := rmbRestore;
end;

{ TdxRibbonMDIButtonViewInfo }

procedure TdxRibbonMDIButtonViewInfo.DrawButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawMDIButton(ACanvas, R, ButtonType, AState);
end;

procedure TdxRibbonMDIButtonViewInfo.DrawButtonGlyph(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawMDIButtonGlyph(ACanvas, R, ButtonType, AState);
end;

procedure TdxRibbonMDIButtonViewInfo.Click;
begin
  if Ribbon.IsBarManagerValid and Enabled then
    Ribbon.BarManager.DoMDIButtonCommand(ButtonType);
end;

function TdxRibbonMDIButtonViewInfo.GetHint: string;
begin
  case FButtonType of
    mdibMinimize:
      Result := cxGetResourceString(@dxSBAR_MDIMINIMIZE);
    mdibRestore:
      Result := cxGetResourceString(@dxSBAR_MDIRESTORE);
    else // mdibClose:
      Result := cxGetResourceString(@dxSBAR_MDICLOSE);
  end;
end;

function TdxRibbonMDIButtonViewInfo.GetIsEnabled: Boolean;
begin
  Result := inherited GetIsEnabled and ViewInfo.IsMDIButtonEnabled(ButtonType, 0);
end;

{ TdxRibbonButtonsContainerViewInfo }

procedure TdxRibbonButtonsContainerViewInfo.Calculate(const ABounds: TRect);
begin
  RecreateButtonsViewInfo;
  FBounds := ABounds;
  CalculateButtonsBounds(FBounds);
  CalculateButtonsStates;
end;

procedure TdxRibbonButtonsContainerViewInfo.CalculateButtonsStates;
var
  I: Integer;
begin
  for I := Count - 1 downto 0 do
    Items[I].CalculateState;
end;

procedure TdxRibbonButtonsContainerViewInfo.Draw(ACanvas: TcxCanvas);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].Draw(ACanvas);
end;

function TdxRibbonButtonsContainerViewInfo.GetItem(Index: Integer): TdxRibbonCustomButtonViewInfo;
begin
  Result := TdxRibbonCustomButtonViewInfo(inherited Items[Index]);
end;

function TdxRibbonButtonsContainerViewInfo.GetSelectedButton: TdxRibbonCustomButtonViewInfo;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if Items[I].AccessibilityHelper.IsSelected then
    begin
      Result := Items[I];
      Break;
    end;
end;

procedure TdxRibbonButtonsContainerViewInfo.RecreateButtonsViewInfo;
begin
end;

function TdxRibbonButtonsContainerViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count - 1 do
  begin
    Result := Items[I].GetHitInfo(AHitInfo);
    if Result then Break;
  end;
end;

{ TdxRibbonTabsAreaButtonsViewInfo }

procedure TdxRibbonTabsAreaButtonsViewInfo.CalculateButtonsBounds(const ABounds: TRect);
var
  I: Integer;
  R: TRect;
begin
  R := ABounds;
  R := cxRectSetRight(R, R.Right, 0);
  R := cxRectSetRight(R, R.Left, cxRectHeight(R));
  for I := Count - 1 downto 0 do
  begin
    Items[I].Bounds := R;
    if I > 0 then
      OffsetRect(R, -cxRectWidth(R), 0);
  end;
  FBounds := cxRectSetRight(ABounds, ABounds.Right, ABounds.Right - R.Left);
end;

procedure TdxRibbonTabsAreaButtonsViewInfo.Draw(ACanvas: TcxCanvas);
var
  ABitmap: TcxBitmap32;
begin
  if Owner.IsTabsOnGlass then
  begin
    ABitmap := TcxBitmap32.CreateSize(Bounds, True);
    try
      cxBitBlt(ABitmap.cxCanvas.Handle, ACanvas.Handle, ABitmap.ClientRect, Bounds.TopLeft, SRCCOPY);
      ABitmap.cxCanvas.WindowOrg := Bounds.TopLeft;
      inherited Draw(ABitmap.cxCanvas);
      ABitmap.cxCanvas.WindowOrg := cxNullPoint;
      cxBitBlt(ACanvas.Handle, ABitmap.cxCanvas.Handle, Bounds, cxNullPoint, SRCCOPY);
    finally
      ABitmap.Free;
    end;
  end
  else
    inherited Draw(ACanvas);
end;

procedure TdxRibbonTabsAreaButtonsViewInfo.RecreateButtonsViewInfo;
var
  AButton: TdxBarMDIButton;
  AButtonViewInfo: TdxRibbonMDIButtonViewInfo;
begin
  Clear;
  if Owner.Style = rs2010 then
    AddItem(TdxRibbonMinimizeButtonViewInfo.Create(Self));
  if Ribbon.IsHelpButtonPlacedOnTabsArea then
    AddItem(TdxRibbonHelpButtonViewInfo.Create(Self));
  if Owner.HasMDIButtons then
  begin
    for AButton := Low(AButton) to High(AButton) do
    begin
      AButtonViewInfo := TdxRibbonMDIButtonViewInfo.Create(Self);
      AButtonViewInfo.FButtonType := AButton;
      AddItem(AButtonViewInfo);
    end;
  end;
end;

{ TdxRibbonContextViewInfo }

constructor TdxRibbonContextViewInfo.Create(AOwner: TdxRibbonContextsViewInfo);
begin
  inherited Create;
  FOwner := AOwner;
end;

procedure TdxRibbonContextViewInfo.Calculate(const ABounds: TRect; AContext: TdxRibbonContext);
begin
  FNeedShowHint := False;
  FContext := AContext;
  Bounds := ABounds;
  FTextBounds := GetTextBounds;
end;

function TdxRibbonContextViewInfo.CalculateTextBounds(DC: HDC; AIndent: Integer): TRect;
var
  ATextSize: TSize;
begin
  Result := Bounds;
  FText := cxGetStringAdjustedToWidth(DC, 0, Context.Caption, cxRectWidth(Bounds) - 2 * AIndent);
  ATextSize := Canvas.TextExtent(FText);
  if RibbonStyle >= rs2010 then
  begin
    Result.Right := Bounds.Right;
    Result.Top := Result.Bottom - ATextSize.cy - 13;
  end
  else
  begin
    Result.Right := Result.Left + ATextSize.cx + 2 * AIndent;
    Result.Top := Result.Bottom - ATextSize.cy - dxRibbonTabsLeftSpace;
  end;
end;

procedure TdxRibbonContextViewInfo.DrawBackground(ACanvas: TcxCanvas);
begin
  if IsPaintOnGlass then
    Painter.DrawContextBackgroundGlass(ACanvas, Bounds, Context.Color)
  else
    Painter.DrawContextBackground(ACanvas, Bounds, Context.Color);
end;

procedure TdxRibbonContextViewInfo.DrawText(ACanvas: TcxCanvas);
var
  ANeedClipping: Boolean;
begin
  ANeedClipping := TextBounds.Right > Bounds.Right;
  if ANeedClipping then
  begin
    ACanvas.SaveClipRegion;
    ACanvas.IntersectClipRect(Bounds);
  end;

  ACanvas.Font := Font;
  ACanvas.Brush.Style := bsClear;
  InternalDrawText(ACanvas, cxRectOffset(TextBounds, 1, 1), FontShadowColor, True);
  InternalDrawText(ACanvas, TextBounds, Font.Color, FontShadowColor = clNone);
  ACanvas.Brush.Style := bsSolid;

  if ANeedClipping then
    ACanvas.RestoreClipRegion;
end;

procedure TdxRibbonContextViewInfo.InternalDrawText(
  ACanvas: TcxCanvas; const R: TRect; ATextColor: TColor; AHasGlowing: Boolean);
begin
  if ATextColor <> clNone then
  begin
    if IsPaintOnGlass then
    begin
      dxDrawTextOnGlass(ACanvas.Handle, Text, Font, R, ATextColor,
        DT_CENTER or DT_SINGLELINE or DT_END_ELLIPSIS or DT_VCENTER or DT_NOPREFIX,
        IfThen(AHasGlowing, dxCaptionGlowRadius), True);
    end
    else
    begin
      ACanvas.Font.Color := ATextColor;
      ACanvas.DrawText(Text, R, cxAlignHCenter or cxShowEndEllipsis or cxAlignVCenter or cxSingleLine);
    end;
  end;
end;

function TdxRibbonContextViewInfo.GetFullTextWidth: Integer;
begin
  Result := Owner.Owner.GetContextCaptionWidth(Context.Caption);
end;

function TdxRibbonContextViewInfo.GetTextBounds: TRect;
begin
  Result := Bounds;
  if Owner.Owner.SupportNonClientDrawing then
  begin
    Canvas.Font := Font;
    Result := CalculateTextBounds(Canvas.Handle,
      IfThen(IsPaintOnGlass, dxCaptionGlowRadius, dxRibbonTabsLeftSpace));
    FNeedShowHint := cxRectWidth(Bounds) < GetFullTextWidth;
  end;
end;

procedure TdxRibbonContextViewInfo.Paint(ACanvas: TcxCanvas);
begin
  DrawBackground(ACanvas);
  DrawText(ACanvas);
end;

function TdxRibbonContextViewInfo.GetCanvas: TcxCanvas;
begin
  Result := Owner.Owner.Canvas;
end;

function TdxRibbonContextViewInfo.GetFont: TFont;
begin
  Result := Owner.Ribbon.Fonts.GetContextFont(Context.Color);
end;

function TdxRibbonContextViewInfo.GetFontShadowColor: TColor;
const
  PartsMap: array[Boolean] of Integer = (rspContextTextShadow, rspContextTextOnGlassShadow);
begin
  Result := Owner.Owner.ColorScheme.GetPartColor(PartsMap[IsPaintOnGlass]);
end;

function TdxRibbonContextViewInfo.GetPainter: TdxRibbonPainter;
begin
  Result := Owner.Owner.Painter;
end;

function TdxRibbonContextViewInfo.GetRibbonStyle: TdxRibbonStyle;
begin
  Result := Owner.Owner.Style;
end;

function TdxRibbonContextViewInfo.IsPaintOnGlass: Boolean;
begin
  Result := Owner.Owner.UseGlass;
end;

{ TdxRibbonContextsViewInfo }

procedure TdxRibbonContextsViewInfo.Calculate(const ABounds: TRect);
var
  R: TRect;
  I: Integer;
  AContextViewInfo: TdxRibbonContextViewInfo;
begin
  R := ABounds;
  if not Owner.UseGlass then
    OffsetRect(R, 0, -1);

  for I := 0 to Owner.TabsViewInfo.Count - 1 do
  begin
    if Owner.TabsViewInfo[I].ContextBegin then
      R.Left := Owner.TabsViewInfo[I].Bounds.Left;
    if R.Left >= ABounds.Right then
      Break;
    if Owner.TabsViewInfo[I].ContextEnd then
    begin
      R.Right := Min(Owner.TabsViewInfo[I].Bounds.Right, ABounds.Right);
      if R.Right - R.Left > dxRibbonFormContextsMinWidth then
      begin
        AContextViewInfo := TdxRibbonContextViewInfo.Create(Self);
        AContextViewInfo.Calculate(R, Owner.TabsViewInfo[I].Tab.Context);
        if AddItem(AContextViewInfo) = 0 then
          FBounds.Left := R.Left;
        FBounds.Right := R.Right;
      end
      else
        Break;
    end;
  end;

  if Count > 0 then
  begin
    FBounds.Top := ABounds.Top;
    FBounds.Bottom := ABounds.Bottom;
  end
  else
  begin
    Clear;
    FBounds := cxNullRect;
  end;
end;

function TdxRibbonContextsViewInfo.GetContextTabViewInfo(
  Index: Integer): TdxRibbonContextViewInfo;
begin
  Result := TdxRibbonContextViewInfo(inherited Items[Index]);
end;

function TdxRibbonContextsViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count - 1 do
    if cxRectPtIn(Items[I].Bounds, AHitInfo.HitPoint) then
    begin
      AHitInfo.HitTest := rhtContext;
      AHitInfo.HitObject := Items[I].Context;
      Result := True;
      Break;
    end;
end;

function TdxRibbonContextsViewInfo.GetContextViewInfo(
  AContext: TdxRibbonContext): TdxRibbonContextViewInfo;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if Items[I].Context = AContext then
    begin
      Result := Items[I];
      Break;
    end;
end;

function TdxRibbonContextsViewInfo.NeedShowHint(AContext: TdxRibbonContext): Boolean;
var
  AItem: TdxRibbonContextViewInfo;
begin
  AItem := GetContextViewInfo(AContext);
  Result := (AItem <> nil) and AItem.NeedShowHint;
end;

procedure TdxRibbonContextsViewInfo.Draw(ACanvas: TcxCanvas);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].Paint(ACanvas);
end;

{ TdxRibbonApplicationButtonViewInfo }

destructor TdxRibbonApplicationButtonViewInfo.Destroy;
begin
  dxFader.Remove(Self);
  inherited Destroy;
end;

procedure TdxRibbonApplicationButtonViewInfo.Calculate;
begin
  if IsVisible then
  begin
    FBounds := cxRect(CalculateContentSize);
    Inc(FBounds.Right, cxMarginsWidth(ClientOffsets));
    Inc(FBounds.Bottom, cxMarginsHeight(ClientOffsets));
    if IsPlacedOnTabsArea then
      FBounds := cxRectSetWidth(Owner.TabsAreaBounds, cxRectWidth(Bounds));
  end
  else
    FBounds := cxNullRect;
end;

function TdxRibbonApplicationButtonViewInfo.CalculateContentSize: TSize;
begin
  Result := cxGetValueCurrentDPI(Ribbon.ColorScheme.GetApplicationMenuGlyphSize);
  if CanShowApplicationButtonText then
    Result.cx := Max(Result.cx, cxTextWidth(Font, ApplicationButton.Text) + cxMarginsWidth(GlyphOffsets));
  dxAdjustToTouchableSize(Result.cx);
end;

function TdxRibbonApplicationButtonViewInfo.CanFade: Boolean;
begin
  Result := Ribbon.CanFade and IsVisible and not
    (IsPressed or Ribbon.Controller.IsApplicationMenuDropped);
end;

function TdxRibbonApplicationButtonViewInfo.CanShowApplicationButtonText: Boolean;
begin
  Result := (Ribbon.Style >= rs2010) and (ApplicationButton.Text <> '');
end;

function TdxRibbonApplicationButtonViewInfo.GetFadingOptions: TdxFadingOptions;
begin
  Result := Ribbon.OptionsFading.ApplicationButton;
end;

procedure TdxRibbonApplicationButtonViewInfo.GetFadingImages(
  out AFadeOutImage, AFadeInImage: TcxBitmap);
begin
  AFadeInImage := TcxBitmap32.CreateSize(ClientBounds, True);
  AFadeOutImage := TcxBitmap32.CreateSize(ClientBounds, True);
  Painter.DrawApplicationButton(AFadeInImage.cxCanvas, AFadeInImage.ClientRect, rabsHot);
  Painter.DrawApplicationButton(AFadeOutImage.cxCanvas, AFadeOutImage.ClientRect, rabsNormal);
end;

procedure TdxRibbonApplicationButtonViewInfo.DrawBackground(ACanvas: TcxCanvas);
begin
  if not dxFader.DrawFadeImage(Self, ACanvas.Handle, ClientBounds) then
    Painter.DrawApplicationButton(ACanvas, ClientBounds, State);
end;

procedure TdxRibbonApplicationButtonViewInfo.DrawContent(ACanvas: TcxCanvas);
begin
  if CanShowApplicationButtonText then
    DrawText(ACanvas)
  else
    DrawGlyph(ACanvas)
end;

procedure TdxRibbonApplicationButtonViewInfo.DrawGlyph(ACanvas: TcxCanvas);
begin
  Painter.DrawApplicationButtonGlyph(ACanvas, GlyphBounds, ApplicationButton.Glyph);
end;

procedure TdxRibbonApplicationButtonViewInfo.DrawText(ACanvas: TcxCanvas);
begin
  if IsPaintOnGlass then
    dxDrawTextOnGlass(ACanvas.Handle, ApplicationButton.Text, Font,
      ClientBounds, Font.Color, DT_CENTER or DT_VCENTER or DT_SINGLELINE, 0, True)
  else
  begin
    ACanvas.Font := Font;
    ACanvas.Brush.Style := bsClear;
    ACanvas.DrawTexT(ApplicationButton.Text,
      ClientBounds, taCenter, vaCenter, False, False);
    ACanvas.Brush.Style := bsSolid;
  end;
end;

procedure TdxRibbonApplicationButtonViewInfo.InvalidateRect(const R: TRect);
begin
  if IsVisible and not Ribbon.IsDestroying then
  begin
    inherited InvalidateRect(R);
    if IsPlacedOnTabsArea then
      Ribbon.GroupsDockControlSite.Invalidate;
  end;
end;

function TdxRibbonApplicationButtonViewInfo.IsVisible(AIgnoreHidden: Boolean = False): Boolean;
begin
  Result := (not Ribbon.Hidden or AIgnoreHidden) and ApplicationButton.Visible and
    Ribbon.ViewInfo.IsTabsVisible(AIgnoreHidden) and (Ribbon.ViewInfo.SupportNonClientDrawing or
   (Ribbon.ViewInfo.IsQATVisible(AIgnoreHidden) and not Ribbon.ViewInfo.IsQATAtBottom));
end;

procedure TdxRibbonApplicationButtonViewInfo.Draw(ACanvas: TcxCanvas);
var
  B: TcxBitmap32;
begin
  if ACanvas.RectVisible(Bounds) then
  begin
    if IsPaintOnGlass then
    begin
      B := TcxBitmap32.CreateSize(Bounds, True);
      try
        cxBitBlt(B.Canvas.Handle, ACanvas.Handle, B.ClientRect, Bounds.TopLeft, SRCCOPY);
        B.cxCanvas.WindowOrg := Bounds.TopLeft;
        DrawBackground(B.cxCanvas);
        DrawContent(B.cxCanvas);
        B.cxCanvas.WindowOrg := cxNullPoint;
        cxBitBlt(ACanvas.Handle, B.Canvas.Handle, Bounds, cxNullPoint, SRCCOPY);
      finally
        B.Free;
      end;
    end
    else
    begin
      DrawBackground(ACanvas);
      DrawContent(ACanvas);
    end;
  end;
end;

function TdxRibbonApplicationButtonViewInfo.GetIsPaintOnGlass: Boolean;
begin
  Result := Ribbon.ViewInfo.IsTabsOnGlass;
end;

function TdxRibbonApplicationButtonViewInfo.GetIsPlacedOnTabsArea: Boolean;
begin
  Result := Ribbon.Style >= rs2010;
end;

function TdxRibbonApplicationButtonViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
begin
  Result := IsVisible and cxRectPtIn(ClientBounds, AHitInfo.HitPoint);
  if Result then
    AHitInfo.HitTest := rhtApplicationMenu;
end;

function TdxRibbonApplicationButtonViewInfo.GetApplicationButton: TdxRibbonApplicationButton;
begin
  Result := Ribbon.ApplicationButton;
end;

function TdxRibbonApplicationButtonViewInfo.GetClientBounds: TRect;
begin
  Result := cxRectContent(Bounds, ClientOffsets);
end;

function TdxRibbonApplicationButtonViewInfo.GetClientOffsets: TRect;
begin
  Result := Ribbon.SkinGetContentOffsets(DXBAR_APPLICATIONBUTTON);
end;

function TdxRibbonApplicationButtonViewInfo.GetFont: TFont;
begin
  Result := Ribbon.Fonts.GetApplicationButtonFont(State);
end;

function TdxRibbonApplicationButtonViewInfo.GetGlyphBounds: TRect;
var
  AIconSize: TSize;
begin
  if (ApplicationButton.Glyph = nil) or ApplicationButton.Glyph.Empty then
    AIconSize := cxSize(GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON))
  else
    AIconSize := cxSize(ApplicationButton.Glyph.Width, ApplicationButton.Glyph.Height);

  Result := cxRectContent(ClientBounds, GlyphOffsets);
  if ApplicationButton.StretchGlyph then
    AIconSize := cxSize(cxRectProportionalStretch(Result, AIconSize));
  Result := cxRectCenter(Result, AIconSize);
end;

function TdxRibbonApplicationButtonViewInfo.GetGlyphOffsets: TRect;
begin
  Result := Ribbon.SkinGetContentOffsets(DXBAR_APPLICATIONBUTTONICONOFFSET);
end;

function TdxRibbonApplicationButtonViewInfo.GetPainter: TdxRibbonPainter;
begin
  Result := Ribbon.Painter;
end;

function TdxRibbonApplicationButtonViewInfo.GetState: TdxRibbonApplicationButtonState;
begin
  if ApplicationButton.IAccessibilityHelper.IsSelected then
    Result := rabsHot
  else
    if IsPressed or Ribbon.Controller.IsApplicationMenuDropped then
      Result := rabsPressed
    else
      if IsHot then
        Result := rabsHot
      else
        Result := rabsNormal;
end;

procedure TdxRibbonApplicationButtonViewInfo.SetIsHot(AValue: Boolean);
begin
  if AValue <> FIsHot then
  begin
    if CanFade then
    begin
      if AValue then
        dxFader.FadeIn(Self)
      else
        dxFader.FadeOut(Self);
    end;
    FIsHot := AValue;
    Invalidate;
  end;
end;

procedure TdxRibbonApplicationButtonViewInfo.SetIsPressed(AValue: Boolean);
begin
  if AValue <> FIsPressed then
  begin
    FIsPressed := AValue;
    Invalidate;
  end;
end;

{ TdxRibbonViewInfo }

constructor TdxRibbonViewInfo.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create;
  FRibbon := ARibbon;
  FFont := TFont.Create;
  FContextsViewInfo := TdxRibbonContextsViewInfo.Create(Self);
  FTabsViewInfo := TdxRibbonTabsViewInfo.Create(Self);
  FApplicationButtonViewInfo := TdxRibbonApplicationButtonViewInfo.Create(Self);
  FTabsAreaButtonsViewInfo := TdxRibbonTabsAreaButtonsViewInfo.Create(Self);
end;

destructor TdxRibbonViewInfo.Destroy;
begin
  FreeAndNil(FTabsViewInfo);
  FreeAndNil(FTabsAreaButtonsViewInfo);
  FreeAndNil(FApplicationButtonViewInfo);
  FreeAndNil(FContextsViewInfo);
  FreeAndNil(FFont);
  inherited Destroy;
end;

procedure TdxRibbonViewInfo.Calculate;
begin
  FBounds := GetBounds;
  UpdateNonClientParams;
  Ribbon.Fonts.UpdateFonts;
  ApplicationButtonViewInfo.Calculate;
  if Hidden <> IsNeedHideControl then
  begin
    FHidden := IsNeedHideControl;
    if Hidden and Ribbon.IsAutoHidden then
      Ribbon.ShowTabGroups := True;
    Calculate;
    if Hidden then
    begin
      Ribbon.UpdateHiddenActiveTabDockControl;
      Ribbon.RibbonFormInvalidate;
    end;
  end
  else
  begin
    Ribbon.DisableAlign;
    try
      TabsViewInfo.RecreateViewInfoCells;
      CalculateTabGroups;
      CalculateTabsAreaButtons;
      CalculateTabs;
      CalculateContexts;
      CalculateRibbonFormCaption;
      CalculateQuickAccessToolbar;
      Ribbon.UpdateHeight;
    finally
      Ribbon.EnableAlign;
    end;
  end;
  Ribbon.UpdateHorizontalNavigationList;
end;

procedure TdxRibbonViewInfo.CalculateHitInfo(AHitTest: TdxRibbonHitInfo);
var
  APrevPoint: TPoint;
begin
  if TabsViewInfo.GetHitInfo(AHitTest) then Exit;
  if TabsAreaButtonsViewInfo.GetHitInfo(AHitTest) then Exit;
  if ContextsViewInfo.GetHitInfo(AHitTest) then Exit;
  if ApplicationButtonViewInfo.GetHitInfo(AHitTest) then Exit;

  APrevPoint := AHitTest.FHitPoint;
  try
    AHitTest.FHitPoint := dxMapWindowPoint(Ribbon.Handle,
      GroupsDockControlSiteViewInfo.FSite.Handle, AHitTest.FHitPoint);
    GroupsDockControlSiteViewInfo.GetHitInfo(AHitTest);
  finally
    AHitTest.FHitPoint := APrevPoint;
  end;
end;

function TdxRibbonViewInfo.AdjustCaptionFontSize(ASize: Integer): Integer;
begin
  Result := ColorScheme.AdjustCaptionFontSize(ASize, UseGlass);
end;

function TdxRibbonViewInfo.GetDocumentNameTextColor(AIsActive: Boolean): TColor;
begin
  Result := Ribbon.Fonts.DocumentNameColor;
  if Result = clDefault then
    Result := Ribbon.SkinGetPartColor(rspDocumentNameText, Ord(not AIsActive));
end;

function TdxRibbonViewInfo.GetFormCaptionFont(AIsActive: Boolean): TFont;
begin
  Result := Ribbon.Fonts.GetFormCaptionFont(AIsActive);
end;

function TdxRibbonViewInfo.GetFormCaptionText: TCaption;
begin
  Result := DocumentName + Caption;
end;

function TdxRibbonViewInfo.GetTabAtPos(X, Y: Integer): TdxRibbonTab;
var
  I: Integer;
begin
  for I := 0 to TabsViewInfo.Count - 1 do
    if cxRectPtIn(TabsViewInfo[I].Bounds, X, Y) then
    begin
      Result := TabsViewInfo[I].Tab;
      Exit;
    end;
  Result := nil;
end;

procedure TdxRibbonViewInfo.Paint(ACanvas: TcxCanvas);
begin
  if DrawEmptyRibbon then
    Painter.DrawEmptyRibbon(ACanvas)
  else
  begin
    DrawRibbonBackground(ACanvas);
    TabsAreaButtonsViewInfo.Draw(ACanvas);
    if IsNeedDrawBottomLine then
      Painter.DrawRibbonTopFrameAreaSeparator(ACanvas);
    if IsQATVisible and not IsQATAtNonClientArea then
      Painter.DrawQuickAccessToolbar(ACanvas, QuickAccessToolbarBounds, True);
    if IsTabsVisible and (TabsViewInfo.Count > 0) then
      TabsViewInfo.Draw(ACanvas);
    if IsTabGroupsVisible then
      Painter.DrawGroupsArea(ACanvas, GroupsDockControlSiteBounds);
    ApplicationButtonViewInfo.Draw(ACanvas);
  end;
end;

procedure TdxRibbonViewInfo.UpdateNonClientParams;
var
  AForm: TdxCustomRibbonForm;
begin
  AForm := Ribbon.RibbonForm;
  FSupportNonClientDrawing := Ribbon.SupportNonClientDrawing and (AForm <> nil) and Ribbon.Visible;
  FUseGlass := FSupportNonClientDrawing and AForm.IsUseAeroNCPaint;
end;

procedure TdxRibbonViewInfo.UpdateQATDockControl;
begin
  if not (Ribbon.IsLoading or Ribbon.IsBarManagerValid and TdxBarManagerAccess(Ribbon.BarManager).IsUpdateLocked) then
  begin
    QATDockControl.HandleNeeded;
    QATDockControl.Visible := IsQATVisible;
    if QATDockControl.Visible then
      QATDockControl.BoundsRect := GetQATDockControlBounds
    else
      QATDockControl.UpdateBoundsRect(GetQATDockControlBounds);
  end;
end;

function TdxRibbonViewInfo.GetBounds: TRect;
var
  AForm: TCustomForm;
begin
  AForm := GetParentForm(Ribbon {$IFDEF DELPHI8}, False{$ENDIF});
  if AForm is TForm then
  begin
    if AForm.HandleAllocated and (AForm.WindowState = wsMinimized) and
      (GetWindowLong(AForm.Handle, GWL_STYLE) and WS_CHILD = WS_CHILD)
    then
      Result := cxRectSetNullOrigin(cxGetWindowRect(AForm.Handle))
    else
      Result := AForm.ClientRect;

    Result.Bottom := Ribbon.ClientBounds.Bottom;
  end
  else
    Result := Ribbon.ClientBounds;
end;

function TdxRibbonViewInfo.GetRibbonHeight: Integer;
begin
  if IsQATVisible and IsQATAtBottom then
    Result := GetQATBounds.Bottom
  else
  begin
    if IsTabGroupsVisible and not Ribbon.IsPopupGroupsMode then
      Result := GetGroupsDockControlSiteBounds.Bottom
    else
    begin
      Result := GetTabsVerticalOffset + TabsHeight;
      if IsNeedDrawBottomLine and (TabsHeight > 0) then
        Inc(Result);
    end;
  end;
  FDrawEmptyRibbon := (Result < 8) and Ribbon.IsDesigning;
  if FDrawEmptyRibbon then
    Result := dxRibbonEmptyHeight
end;

procedure TdxRibbonViewInfo.CalculateContexts;
var
  R: TRect;
begin
  ContextsViewInfo.Clear;
  if SupportNonClientDrawing and IsTabsVisible and (TabsViewInfo.Count > 0) then
  begin
    R := GetRibbonFormCaptionClientBounds;
    Dec(R.Right, dxRibbonTabTextOffset);
    ContextsViewInfo.Calculate(R);
  end;
end;

procedure TdxRibbonViewInfo.CalculateQuickAccessToolbar;
begin
  FQuickAccessToolbarBounds := cxEmptyRect;
  if IsQATVisible then
  begin
    FQATBarControlSize := GetQATBarControlSize;
    FQuickAccessToolbarBounds := GetQATBounds;
    if QuickAccessToolbar.Toolbar.Control <> nil then
      QuickAccessToolbar.Toolbar.Control.Enabled := Ribbon.ApplicationMenuState <= ramsShownAsMenu;
  end;
  UpdateQATDockControl;
end;

procedure TdxRibbonViewInfo.CalculateRibbonFormCaption;
begin
  if SupportNonClientDrawing then
    Ribbon.FormCaptionHelper.Calculate;
  FFormCaptionTheLeftOfContext := False; //reset
  if SupportNonClientDrawing then
    FFormCaptionBounds := GetRibbonFormCaptionTextBounds
  else
    FFormCaptionBounds := cxEmptyRect;
end;

procedure TdxRibbonViewInfo.CalculateTabGroups;
begin
  if IsTabGroupsVisible and not Ribbon.IsPopupGroupsMode then
  begin
    FGroupsDockControlSiteBounds := GetGroupsDockControlSiteBounds;
    FTabGroupsDockControlBounds := GetTabGroupsDockControlBounds;
  end
  else
  begin
    FGroupsDockControlSiteBounds := cxEmptyRect;
    FTabGroupsDockControlBounds := cxEmptyRect;
  end;
  if not Ribbon.IsPopupGroupsMode then
  begin
    UpdateGroupsDockControlSite;
    if IsTabGroupsVisible then
      TabsViewInfo.UpdateDockControls;
  end;
end;

procedure TdxRibbonViewInfo.CalculateTabs;
begin
  if IsTabsVisible and (TabsViewInfo.Count > 0) then
    TabsViewInfo.Calculate(GetTabsBounds);
end;

procedure TdxRibbonViewInfo.CalculateTabsAreaButtons;
var
  R: TRect;
begin
  R := Bounds;
  R.Bottom := R.Top + TabsHeight - 2;
  OffsetRect(R, 0, GetTabsVerticalOffset);
  TabsAreaButtonsViewInfo.Calculate(R);
end;

function TdxRibbonViewInfo.CanDrawFormDefaultIcon(const AData: TdxRibbonFormData): Boolean;
begin
  if Ribbon.Hidden then
    Result := not Ribbon.IsAutoHidden
  else
    Result := (AData.State = wsMinimized) or not ApplicationButtonViewInfo.IsVisible or
      ApplicationButtonViewInfo.IsPlacedOnTabsArea;
end;

function TdxRibbonViewInfo.CanShowBarControls(AIgnoreHidden: Boolean = False): Boolean;
begin
  Result := Ribbon.IsBarManagerValid and (not Ribbon.Hidden or AIgnoreHidden);
end;

function TdxRibbonViewInfo.GetNonClientAreaHeight: Integer;
begin
  if SupportNonClientDrawing then
    Result := Ribbon.GetRibbonFormCaptionHeight
  else
    Result := 0;
end;

function TdxRibbonViewInfo.GetNonClientAreaObjectsRegion: HRGN;
begin
  Result := 0;
  if ApplicationButtonViewInfo.IsVisible then
    dxCombineRectRegion(Result, ApplicationButtonViewInfo.Bounds, RGN_OR);
  if ContextsViewInfo.Count > 0 then
    dxCombineRectRegion(Result, ContextsViewInfo.Bounds, RGN_OR);
end;

function TdxRibbonViewInfo.GetCaption: string;
begin
  if Ribbon.RibbonForm <> nil then
  begin
    Result := Ribbon.RibbonForm.Caption;
    if DocumentName <> '' then
      Result := ' - ' + Result;
  end
  else
    Result := '';
end;

function TdxRibbonViewInfo.GetDocumentName: string;
begin
  Result := Ribbon.DocumentName;
end;

function TdxRibbonViewInfo.GetRibbonFormCaptionClientBounds: TRect;
begin
  Result := Ribbon.FormCaptionHelper.TextBounds;
  if not Ribbon.Hidden then
  begin
    Result.Bottom := GetNonClientAreaHeight;
    if IsQATAtNonClientArea then
      Result.Left := GetQATBounds.Right + ColorScheme.GetQuickAccessToolbarRightIndent(IsApplicationButtonNearQAT)
    else
      if ApplicationButtonViewInfo.IsVisible and not ApplicationButtonViewInfo.IsPlacedOnTabsArea then
        Result.Left := ApplicationButtonViewInfo.Bounds.Right;
  end;
end;

function TdxRibbonViewInfo.GetRibbonFormCaptionTextBounds: TRect;
var
  ATextWidth, W: Integer;
  ACenterRect: TRect;
begin
  Result := GetRibbonFormCaptionClientBounds;
  ATextWidth := cxTextWidth(GetFormCaptionFont(True), GetFormCaptionText);
  if UseGlass then
    Inc(ATextWidth, 2 * dxCaptionGlowRadius) // add a glow radius around text
  else
    InflateRect(Result, -dxRibbonFormCaptionTextSpace, 0);
  ACenterRect := cxRect(Bounds.Left, Result.Top, Bounds.Right, Result.Bottom);
  if not UseGlass then
    InflateRect(ACenterRect, -dxRibbonFormCaptionTextSpace, 0);
  W := cxRectWidth(ACenterRect) - ATextWidth;
  Inc(ACenterRect.Left, W div 2);
  Dec(ACenterRect.Right, W div 2 - 1);
  if ContextsViewInfo.Count > 0 then
    Result := GetRibbonFormCaptionTextBoundsWithContext(Result, ACenterRect, ATextWidth)
  else
    if (W >= 0) and cxRectContain(Result, ACenterRect) then
      Result := ACenterRect;
end;

function TdxRibbonViewInfo.GetRibbonFormCaptionTextBoundsWithContext(
  const ABounds, ACenterRect: TRect; ATextWidth: Integer): TRect;
var
  ALeftWidth, ARightWidth: Integer;
  ALeftRect, ARightRect: TRect;
begin
  //try center
  ALeftRect := cxRect(ABounds.Left, ABounds.Top, ContextsViewInfo.Bounds.Left, ABounds.Bottom);
  if not UseGlass then
    Dec(ALeftRect.Right, dxRibbonFormCaptionTextSpace);
  if cxRectContain(ALeftRect, ACenterRect) then
  begin
    Result := ACenterRect;
    Exit;
  end;
  ARightRect := cxRect(ContextsViewInfo.Bounds.Right, ABounds.Top, ABounds.Right, ABounds.Bottom);
  if not UseGlass then
    Inc(ARightRect.Left, dxRibbonFormCaptionTextSpace);
  if cxRectContain(ARightRect, ACenterRect) then
  begin
    Result := ACenterRect;
    Exit;
  end;
  //select the best
  ALeftWidth := ALeftRect.Right - ALeftRect.Left;
  ARightWidth := ARightRect.Right - ARightRect.Left;
  if ALeftWidth >= ATextWidth then
  begin
    FFormCaptionTheLeftOfContext := True;
    Result := cxRectCenterHorizontally(ALeftRect, ATextWidth);
  end
  else if ARightWidth >= ATextWidth then
    Result := ARightRect
  else if ALeftWidth > ARightWidth then
  begin
    FFormCaptionTheLeftOfContext := True;
    Result := ALeftRect;
  end
  else
    Result := ARightRect;
end;

function TdxRibbonViewInfo.GetQATAvailWidth: Integer;
var
  R: TRect;
  ALeft, ARight, ARightIndent: Integer;
begin
  ALeft := 0;
  ARight := Bounds.Right;
  if not IsQATAtBottom then
  begin
    if IsApplicationButtonNearQAT then
      ALeft := ApplicationButtonViewInfo.Bounds.Right - GetQATOverrideWidth;
    if SupportNonClientDrawing then
    begin
      R := Ribbon.FormCaptionHelper.TextBounds;
      if UseGlass then
        ARightIndent := 0
      else
        ARightIndent := ColorScheme.GetQuickAccessToolbarRightIndent(IsApplicationButtonNearQAT);
      Inc(R.Left, ARightIndent);
      if UseGlass then
        Dec(R.Right, 2 * dxCaptionGlowRadius);
      ALeft := Max(R.Left, ALeft);
      ARight := R.Right - dxRibbonFormCaptionMinWidth;
      if IsContextsVisible then
      begin
        R := ContextsViewInfo.Bounds;
        if FFormCaptionTheLeftOfContext then
          Dec(R.Left, dxRibbonFormCaptionMinWidth);
        ARight := Min(ARight, R.Left);
        Dec(ARight, ARightIndent);
      end;
    end;
  end;
  Result := Max(ARight - ALeft, 0);
end;

function TdxRibbonViewInfo.GetQATBarControlSize: TSize;
var
  AControl: TdxBarControl;
begin
  Result := cxNullSize;
  if IsQATVisible and (Ribbon.ApplicationMenuState <> ramsShownAsFullScreenFrame) then
  begin
    AControl := QuickAccessToolbar.Toolbar.Control;
    if AControl is TdxRibbonQuickAccessBarControl then
    begin
      Result := TdxRibbonQuickAccessBarControl(AControl).GetSize(
        GetQATAvailWidth - cxMarginsWidth(GetQATDockControlOffset));
    end;
  end;
end;

function TdxRibbonViewInfo.GetQATBounds: TRect;
begin
  Result := cxRectBounds(GetQATLeft, GetQATTop, GetQATWidth, GetQATHeight);
end;

function TdxRibbonViewInfo.GetQATHeight: Integer;
begin
  if IsQATVisible then
    Result := FQATBarControlSize.cy + cxMarginsHeight(GetQATDockControlOffset)
  else
    Result := 0;
end;

function TdxRibbonViewInfo.GetQATLeft: Integer;
var
  AHasApplicationButton: Boolean;
begin
  Result := Bounds.Left;
  if not IsQATAtBottom then
  begin
    Inc(Result, 2);
    AHasApplicationButton := IsApplicationButtonNearQAT;
    if AHasApplicationButton then
      Result := ApplicationButtonViewInfo.Bounds.Right - GetQATOverrideWidth
    else
      if SupportNonClientDrawing then
        Result := Ribbon.FormCaptionHelper.TextBounds.Left + 4;
    Inc(Result, ColorScheme.GetQuickAccessToolbarLeftIndent(AHasApplicationButton, UseGlass));
  end;
end;

function TdxRibbonViewInfo.GetQATOverrideWidth(AIgnoreHidden: Boolean = False): Integer;
begin
  Result := ColorScheme.GetQuickAccessToolbarOverrideWidth(IsApplicationButtonNearQAT(AIgnoreHidden), UseGlass);
end;

function TdxRibbonViewInfo.GetQATTop: Integer;
begin
  Result := 0;
  if IsQATAtBottom then
  begin
    Result := GetNonClientAreaHeight;
    if IsTabsVisible then
      Inc(Result, TabsHeight - 1);
    if IsTabGroupsVisible and not Ribbon.IsPopupGroupsMode then
      Inc(Result, GetTabGroupsHeight);
  end;
end;

function TdxRibbonViewInfo.GetQATWidth: Integer;
begin
  if IsQATVisible then
  begin
    if IsQATAtBottom then
      Result := Bounds.Right
    else
      Result := FQATBarControlSize.cx + cxMarginsWidth(GetQATDockControlOffset);
  end
  else
    Result := 0;
end;

function TdxRibbonViewInfo.GetQATDockControlBounds: TRect;
begin
  Result := cxRectContent(QuickAccessToolbarBounds, GetQATDockControlOffset);
  Result := cxRectSetWidth(Result, FQATBarControlSize.cx);
end;

function TdxRibbonViewInfo.GetQATDockControlOffset(AIgnoreHidden: Boolean = False): TRect;
var
  H: Integer;
begin
  if IsQATAtBottom then
    Result := Ribbon.SkinGetContentOffsets(DXBAR_QUICKACCESSTOOLBAR)
  else
  begin
    Result := cxRect(GetQATOverrideWidth(AIgnoreHidden) + 1, 0, 0, 0);
    if (FQATBarControlSize.cx <> 0) and (Ribbon.GetValidPopupMenuItems = []) then
    begin
      Inc(Result.Right, ((FQATBarControlSize.cy + 2) div 2) or 1);
      Inc(Result.Right, 12);
    end;
    if SupportNonClientDrawing then
    begin
      H := GetNonClientAreaHeight - FQATBarControlSize.cy;
      Result.Bottom := H div 2;
      Result.Top := H - Result.Bottom;
    end
    else
    begin
      Result.Top := 4;
      Result.Bottom := 5;
    end;
  end;
end;

function TdxRibbonViewInfo.GetGroupsDockControlSiteBounds: TRect;
begin
  Result := Bounds;
  Inc(Result.Top, GetTabsVerticalOffset);
  Inc(Result.Top, GetTabsHeight);
  if IsTabsVisible then
    Dec(Result.Top, Ribbon.SkinGetPartSize(DXBAR_TABSGROUPSOVERLAPHEIGHT));
  Result.Bottom := Result.Top + GetTabGroupsHeight;
end;

function TdxRibbonViewInfo.GetTabGroupsContentOffset: TRect;
const
  Parts: array[Boolean] of Integer = (DXBAR_RIBBONTABGROUP, DXBAR_RIBBONCONTEXTTABGROUP);
begin
  Result := Ribbon.SkinGetContentOffsets(Parts[HasActiveContextTab]);
end;

function TdxRibbonViewInfo.GetTabGroupsDockControlBounds: TRect;
begin
  Result := cxRectSetNullOrigin(GetGroupsDockControlSiteBounds);
  Result := cxRectContent(Result, GetTabGroupsDockControlOffset);
end;

function TdxRibbonViewInfo.GetTabGroupsDockControlOffset: TRect;
begin
  Result := GetTabGroupsContentOffset;
  if Ribbon.Style = rs2013 then
    Inc(Result.Right, GroupsDockControlSiteViewInfo.GetMinimizeRibbonButtonSize.cx + 2);
end;

function TdxRibbonViewInfo.GetTabsAreaBounds: TRect;
begin
  Result := cxRectSetHeight(Bounds, TabsHeight);
  OffsetRect(Result, 0, GetTabsVerticalOffset);
end;

function TdxRibbonViewInfo.GetTabsBounds: TRect;
begin
  Result := TabsAreaBounds;
  Result.Left := Max(ApplicationButtonViewInfo.Bounds.Right, dxRibbonTabsLeftSpace);
  if TabsAreaButtonsViewInfo.Count > 0 then
    Result.Right := TabsAreaButtonsViewInfo.Bounds.Left - 1
  else
    Dec(Result.Right, dxRibbonTabsRightSpace);
end;

function TdxRibbonViewInfo.GetTabsHeight: Integer;
begin
  if IsTabsVisible then
  begin
    Result := cxTextHeight(Ribbon.Fonts.TabHeader);
    if ApplicationButtonViewInfo.IsPlacedOnTabsArea then
    begin
      if ApplicationButtonViewInfo.CanShowApplicationButtonText then
        Result := Max(Result, cxTextHeight(ApplicationButtonViewInfo.Font));
    end;
    Inc(Result, cxMarginsHeight(GetTabContentOffsets));
  end
  else
    Result := 0;
end;

function TdxRibbonViewInfo.GetTabContentOffsets: TRect;
begin
  Result := cxRect(dxRibbonTabTextOffset, 7, dxRibbonTabTextOffset, 4);
  Ribbon.TouchModeHelper.AdjustMargins(Result, 9);
end;

function TdxRibbonViewInfo.GetTabGroupsHeight(AIgnoreHidden: Boolean = False): Integer;
begin
  if IsTabGroupsVisible or AIgnoreHidden then
    Result := Ribbon.GetGroupHeight + cxMarginsHeight(GetTabGroupsDockControlOffset)
  else
    Result := 0;
end;

function TdxRibbonViewInfo.GetTabViewInfoClass: TdxRibbonTabViewInfoClass;
begin
  Result := TdxRibbonTabViewInfo;
end;

function TdxRibbonViewInfo.HasMDIButtons: Boolean;
begin
  if not Ribbon.Hidden and IsTabsVisible and Ribbon.IsBarManagerValid then
    Result := Ribbon.BarManager.IsMDIMaximized and (GetSystemMenu(Ribbon.BarManager.ActiveMDIChild, False) <> 0)
  else
    Result := False;
end;

function TdxRibbonViewInfo.IsMDIButtonEnabled(AButton: TdxBarMDIButton; AState: Integer): Boolean;
begin
  Result := ((AButton = mdibRestore) or
     (GetMenuState(GetSystemMenu(Ribbon.BarManager.ActiveMDIChild, False),
      MDIButtonCommands[AButton], MF_BYCOMMAND) and AState = 0));
end;

function TdxRibbonViewInfo.IsApplicationButtonNearQAT(AIgnoreHidden: Boolean = False): Boolean;
begin
  Result := ApplicationButtonViewInfo.IsVisible(AIgnoreHidden) and (Style = rs2007);
end;

function TdxRibbonViewInfo.IsContextsVisible: Boolean;
begin
  Result := IsTabsVisible and (TabsViewInfo.Count > 0) and (ContextsViewInfo.Count > 0);
end;

function TdxRibbonViewInfo.IsQATAtNonClientArea(AIgnoreHidden: Boolean = False): Boolean;
begin
  Result := SupportNonClientDrawing and not IsQATAtBottom and IsQATVisible(AIgnoreHidden);
end;

function TdxRibbonViewInfo.IsQATOnGlass: Boolean;
begin
  Result := UseGlass and IsQATAtNonClientArea;
end;

function TdxRibbonViewInfo.IsQATVisible(AIgnoreHidden: Boolean = False): Boolean;
begin
  Result := CanShowBarControls(AIgnoreHidden) and QuickAccessToolbar.Visible and
    (QuickAccessToolbar.Toolbar <> nil) and QuickAccessToolbar.Toolbar.Visible;
end;

function TdxRibbonViewInfo.IsTabGroupsVisible(AIgnoreHidden: Boolean = False): Boolean;
begin
  Result := CanShowBarControls(AIgnoreHidden) and
    (Ribbon.ShowTabGroups or Ribbon.IsPopupGroupsMode) and (TabsViewInfo.Count > 0);
end;

function TdxRibbonViewInfo.IsTabsVisible(AIgnoreHidden: Boolean = False): Boolean;
begin
  Result := (not Ribbon.Hidden or AIgnoreHidden) and Ribbon.ShowTabHeaders;
end;

function TdxRibbonViewInfo.GetContextCaptionWidth(const ACaption: string): Integer;
begin
  Result := 0;
  if SupportNonClientDrawing then
  begin
    Canvas.Font := Ribbon.Fonts.GetContextFont;
    Result := Canvas.TextWidth(ACaption);
    if UseGlass then
      Inc(Result, 2 * dxCaptionGlowRadius)
    else
      Inc(Result, 2 * dxRibbonTabsLeftSpace);
  end;
end;

procedure TdxRibbonViewInfo.DrawRibbonBackground(ACanvas: TcxCanvas);
var
  R: TRect;
begin
  R := Bounds;
  if SupportNonClientDrawing then
    R.Top := GetRibbonFormCaptionClientBounds.Bottom;
  ACanvas.SaveClipRegion;
  try
    ACanvas.IntersectClipRect(R);
    Painter.DrawTabAreaBackground(ACanvas, TabsAreaBounds);
    ACanvas.ExcludeClipRect(TabsAreaBounds);
    Painter.DrawBackground(ACanvas, Bounds);
  finally
    ACanvas.RestoreClipRegion;
  end;
end;

function TdxRibbonViewInfo.IsNeedDrawBottomLine: Boolean;
begin
  Result := IsTabsVisible and not (IsQATVisible and IsQATAtBottom) and
    (not IsTabGroupsVisible or Ribbon.IsPopupGroupsMode) and not IsTabsOnGlass;
end;

function TdxRibbonViewInfo.IsNeedHideControl: Boolean;
var
  AForm: TCustomForm;
begin
  Result := False;
  if not Ribbon.IsDesigning then
  begin
    AForm := GetParentForm(Ribbon);
    Result := (AForm <> nil) and ((IsIconic(AForm.Handle) and IsShowMinimizedOnDesktop(AForm.Handle)) or
      (AForm.Width < dxRibbonOwnerMinimalWidth) or (AForm.Height < dxRibbonOwnerMinimalHeight)) or Ribbon.IsAutoHidden;
  end;
end;

function TdxRibbonViewInfo.IsQATAtBottom: Boolean;
begin
  Result := QuickAccessToolbar.Position = qtpBelowRibbon;
end;

function TdxRibbonViewInfo.GetCanvas: TcxCanvas;
begin
  Result := Ribbon.Canvas;
end;

function TdxRibbonViewInfo.GetColorScheme: TdxCustomRibbonSkin;
begin
  Result := Ribbon.ColorScheme;
end;

function TdxRibbonViewInfo.GetGroupsDockControlSiteViewInfo: TdxRibbonGroupsDockControlSiteViewInfo;
begin
  Result := Ribbon.GroupsDockControlSite.ViewInfo;
end;

function TdxRibbonViewInfo.GetHasActiveContextTab: Boolean;
begin
  Result := (Ribbon.ActiveTab <> nil) and (Ribbon.ActiveTab.Context <> nil);
end;

function TdxRibbonViewInfo.GetIsFormCaptionActive: Boolean;
begin
  Result := SupportNonClientDrawing and Ribbon.RibbonForm.IsActive;
end;

function TdxRibbonViewInfo.GetIsTabsOnGlass: Boolean;
begin
  Result := Ribbon.EnableTabAero and UseGlass and ColorScheme.ExtendCaptionAreaOnTabs;
end;

function TdxRibbonViewInfo.GetPainter: TdxRibbonPainter;
begin
  Result := Ribbon.Painter;
end;

function TdxRibbonViewInfo.GetQATDockControl: TdxRibbonQuickAccessDockControl;
begin
  Result := QuickAccessToolbar.DockControl;
end;

function TdxRibbonViewInfo.GetQuickAccessToolbar: TdxRibbonQuickAccessToolbar;
begin
  Result := Ribbon.QuickAccessToolbar;
end;

function TdxRibbonViewInfo.GetScrollButtonWidth: Integer;
var
  AFont: TFont;
begin
  AFont := Ribbon.Fonts.TabHeader;
  Result := (Abs(AFont.Height) * 2 + 2) div 2 + 1;
end;

function TdxRibbonViewInfo.GetStyle: TdxRibbonStyle;
begin
  Result := Ribbon.Style;
end;

function TdxRibbonViewInfo.GetTabsVerticalOffset: Integer;
begin
  if SupportNonClientDrawing then
    Result := GetNonClientAreaHeight
  else
    if IsQATVisible and (QuickAccessToolbar.Position = qtpAboveRibbon) then
      Result := GetQATBounds.Bottom
    else
      Result := 0;
end;

procedure TdxRibbonViewInfo.UpdateButtonsStates;
begin
  GroupsDockControlSiteViewInfo.CalculateButtonsStates;
  TabsAreaButtonsViewInfo.CalculateButtonsStates;
  TabsViewInfo.UpdateButtonsStates;
end;

procedure TdxRibbonViewInfo.UpdateGroupsDockControlSite;
begin
  Ribbon.GroupsDockControlSite.BoundsRect := GroupsDockControlSiteBounds;
end;

{ TdxRibbonBarPainter }

constructor TdxRibbonBarPainter.Create(AData: TdxNativeUInt);
begin
  inherited Create(AData);
  FRibbon := TdxCustomRibbon(AData);
  FDrawParams := TdxBarButtonLikeControlDrawParams.Create(nil);
end;

destructor TdxRibbonBarPainter.Destroy;
begin
  FreeAndNil(FDrawParams);
  inherited Destroy;
end;

procedure TdxRibbonBarPainter.BarDrawBackground(ABarControl: TdxBarControl;
  ADC: HDC; const ADestRect: TRect; const ASourceRect: TRect; ABrush: HBRUSH;
  AColor: TColor);
begin
  cxPaintCanvas.BeginPaint(ADC);
  try
    cxPaintCanvas.SetClipRegion(TcxRegion.Create(ADestRect), roIntersect);
    (ABarControl as TdxRibbonCustomBarControl).DrawBarParentBackground(cxPaintCanvas);
    DrawToolbarContentPart(ABarControl, cxPaintCanvas);
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

function TdxRibbonBarPainter.BarMarkRect(
  ABarControl: TdxBarControl): TRect;
begin
  Result := ABarControl.ClientRect;
end;

function TdxRibbonBarPainter.BarMarkItemRect(
  ABarControl: TdxBarControl): TRect;
begin
  Result := ABarControl.ClientRect;
end;

procedure TdxRibbonBarPainter.CalculateDrawParams;
const
  DefaultFontHeight = 13;
begin
  FCollapsedGroupElementSizeNumerator := GetSmallIconSize +
    cxMarginsHeight(Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBARGLYPHBACKGROUND)) +
    cxMarginsHeight(dxRibbonCollapsedGroupGlyphBackgroundOffsets);
  FCollapsedGroupElementSizeDenominator := Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBAR).Top +
    GetButtonHeight(GetSmallIconSize, DefaultFontHeight + dxRibbonGroupRowHeightCorrection) * dxRibbonGroupRowCount +
    InternalGetGroupCaptionHeight(DefaultFontHeight) + (Ribbon.Painter.GetGroupCaptionBottomOffset + 1) -
    cxMarginsHeight(Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBAR));
end;

function TdxRibbonBarPainter.GetGroupRowHeight(AIconSize: Integer; AGroupFont: TFont): Integer;
begin
  Result := GetButtonHeight(AIconSize, cxTextHeight(AGroupFont) + dxRibbonGroupRowHeightCorrection);
end;

function TdxRibbonBarPainter.GetToolbarContentOffsets(ABar: TdxBar;
  ADockingStyle: TdxBarDockingStyle; AHasSizeGrip: Boolean): TRect;
begin
  if (ABar.Control is TdxRibbonGroupBarControl) and TdxRibbonGroupBarControl(ABar.Control).Collapsed then
    Result := cxEmptyRect
  else
    Result := inherited GetToolbarContentOffsets(ABar, ADockingStyle, AHasSizeGrip);
end;

function TdxRibbonBarPainter.SubMenuControlBeginGroupSize: Integer;
begin
  Result := Ribbon.ColorScheme.GetMenuSeparatorSize;
end;

function TdxRibbonBarPainter.SubMenuGetSeparatorSize: Integer;
begin
  Result := Ribbon.ColorScheme.GetMenuSeparatorSize;
end;

procedure TdxRibbonBarPainter.DrawCollapsedToolbarBackgroundPart(
  ABarControl: TdxRibbonGroupBarControl; ACanvas: TcxCanvas; AGroupState: Integer);
begin
  if not dxFader.DrawFadeImage(ABarControl, ACanvas.Handle, ABarControl.ClientRect) then
    Skin.DrawBackground(ACanvas.Handle, ABarControl.ClientRect, DXBAR_COLLAPSEDTOOLBAR, AGroupState);
end;

procedure TdxRibbonBarPainter.DrawCollapsedToolbarContentPart(
  ABarControl: TdxRibbonGroupBarControl; ACanvas: TcxCanvas; AGroupState: Integer);

  procedure InitDrawParams(AState: Integer);
  begin
    case AState of
      DXBAR_NORMAL:
        DrawParams.HotPartIndex := icpNone;
      DXBAR_HOT:
        DrawParams.HotPartIndex := icpControl;
      DXBAR_PRESSED:
        begin
          DrawParams.HotPartIndex := icpControl;
          DrawParams.IsPressed := True;
        end;
    end;
    DrawParams.Canvas := ACanvas;
    DrawParams.Caption := (ABarControl as TdxRibbonGroupBarControl).GetCaption;
    DrawParams.IsDropDown := True;
    DrawParams.ViewSize := cvsLarge;
    DrawParams.Enabled := True;
    DrawParams.CanSelect := True;
  end;

var
  ACaptionRect, R: TRect;
  AGroupGlyphBackgroundSize, AGroupGlyphSize: TSize;
begin
  ACaptionRect := GetCollapsedGroupCaptionRect(ABarControl.ClientRect);

  InitDrawParams(AGroupState);
  ButtonLikeControlDoDrawCaption(DrawParams, ACaptionRect, DT_CENTER);

  R := cxRectContent(ABarControl.ClientRect, Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBAR));
  R.Bottom := ACaptionRect.Top;
  AGroupGlyphBackgroundSize := GetCollapsedGroupGlyphBackgroundSize(ABarControl);
  Inc(R.Left, (cxRectWidth(R) - AGroupGlyphBackgroundSize.cx) div 2);
  R.Right := R.Left + AGroupGlyphBackgroundSize.cx;
  R := cxRectContent(R, Rect(0, dxRibbonCollapsedGroupGlyphBackgroundOffsets.Top, 0, dxRibbonCollapsedGroupGlyphBackgroundOffsets.Bottom));
  Inc(R.Top, (cxRectHeight(R) - AGroupGlyphBackgroundSize.cy) div 2);
  R.Bottom := R.Top + AGroupGlyphBackgroundSize.cy;
  Skin.DrawBackground(ACanvas.Handle, R, DXBAR_COLLAPSEDTOOLBARGLYPHBACKGROUND, AGroupState);

  if GetCollapsedGroupGlyph(ABarControl) <> nil then
  begin
    with Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBARGLYPHBACKGROUND) do
    begin
      Inc(R.Top, Top);
      Dec(R.Bottom, Bottom);
    end;
    AGroupGlyphSize := GetCollapsedGroupGlyphSize(ABarControl);
    Inc(R.Top, (cxRectHeight(R) - AGroupGlyphSize.cy) div 2);
    R.Bottom := R.Top + AGroupGlyphSize.cy;
    Inc(R.Left, (cxRectWidth(R) - AGroupGlyphSize.cx) div 2);
    R.Right := R.Left + AGroupGlyphSize.cx;
    TransparentDraw(ACanvas.Handle, R, GetCollapsedGroupGlyph(ABarControl));
  end;
end;

procedure TdxRibbonBarPainter.DrawToolbarContentPart(ABarControl: TdxBarControl; ACanvas: TcxCanvas);

  function DrawFadeBackground(AGroupBarControl: TdxRibbonGroupBarControl): Boolean;
  var
    APrevWindowOrg: TPoint;
  begin
    with AGroupBarControl.NCOffset do
      OffsetWindowOrgEx(ACanvas.Handle, X, Y, APrevWindowOrg);
    try
      Result := dxFader.DrawFadeImage(AGroupBarControl, ACanvas.Handle, AGroupBarControl.NCRect);
    finally
      SetWindowOrgEx(ACanvas.Handle, APrevWindowOrg.X, APrevWindowOrg.Y, nil);
    end;
  end;

var
  AGroupBarControl: TdxRibbonGroupBarControl;
  AGroupState: Integer;
begin
  AGroupBarControl := ABarControl as TdxRibbonGroupBarControl;
  if AGroupBarControl.Collapsed then
  begin
    AGroupState := GetGroupState(ABarControl);
    DrawCollapsedToolbarBackgroundPart(AGroupBarControl, ACanvas, AGroupState);
    DrawCollapsedToolbarContentPart(AGroupBarControl, ACanvas, AGroupState);
  end
  else
    if not DrawFadeBackground(AGroupBarControl) then
      inherited DrawToolbarContentPart(ABarControl, ACanvas);
end;

procedure TdxRibbonBarPainter.DrawToolbarNonContentPart(ABarControl: TdxBarControl; DC: HDC);
begin
  Skin.DrawBackground(DC, TdxBarControlAccess(ABarControl).NCRect,
    GetToolbarSkinPart(ABarControl), GetBarControlState(ABarControl));
end;

function TdxRibbonBarPainter.GetCollapsedGroupWidth(ABarControl: TdxRibbonGroupBarControl): Integer;

  procedure InitDrawParams;
  begin
    cxScreenCanvas.Font := ABarControl.Font;
    DrawParams.Canvas := cxScreenCanvas;
    DrawParams.Caption := ABarControl.GetCaption;
    DrawParams.ViewSize := cvsLarge;
    DrawParams.IsDropDown := True;
  end;

var
  R: TRect;
begin
  InitDrawParams;
  Result := GetControlCaptionRect(DrawParams).Right;
  cxScreenCanvas.Dormant;

  R := Rect(0, 0, 100, 100);
  with GetCollapsedGroupCaptionRect(R) do
    Inc(Result, (Left - R.Left) + (R.Right - Right));
  Result := Max(Result, GetCollapsedGroupGlyphBackgroundSize(ABarControl).cx +
    cxMarginsWidth(dxRibbonCollapsedGroupGlyphBackgroundOffsets) +
    cxMarginsWidth(Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBAR)));
end;

function TdxRibbonBarPainter.GetGroupCaptionHeight(ACaptionFont: TFont): Integer;
var
  ACanvas: TcxScreenCanvas;
begin
  ACanvas := TcxScreenCanvas.Create;
  try
    ACanvas.Font := ACaptionFont;
    if ACanvas.Font.Size < 8 then
      ACanvas.Font.Size := 8;
    Result := InternalGetGroupCaptionHeight(cxTextHeight(ACanvas.Handle));
  finally
    ACanvas.Free;
  end;
end;

function TdxRibbonBarPainter.DropDownGalleryGetSizingBandHeight(AIconSize: Integer;
  AGroupFont: TFont): Integer;
begin
   Result := GetGroupRowHeight(AIconSize, AGroupFont);
end;

function TdxRibbonBarPainter.GetButtonPartState(
  const ADrawParams: TdxBarButtonLikeControlDrawParams; AControlPart: Integer): Integer;

  function GetCustomButtonPartState: Integer;
  begin
    if ADrawParams.IsPressed then
      Result := DXBAR_PRESSED
    else
      if ADrawParams.Downed then
      begin
        if ADrawParams.DroppedDown then
          Result := DXBAR_ACTIVE
        else
          if (ADrawParams.HotPartIndex = AControlPart) or
            ADrawParams.SelectedByKey and not ADrawParams.IsDropDown
          then
            Result := DXBAR_HOTCHECK
          else
            Result := DXBAR_CHECKED
      end
      else
        if ADrawParams.DroppedDown then
          Result := DXBAR_DROPPEDDOWN
        else
          Result := GetPartState(ADrawParams, AControlPart)
  end;

  function GetDropButtonPartState: Integer;
  begin
    if ADrawParams.DroppedDown then
      Result := DXBAR_DROPPEDDOWN
    else
      if ADrawParams.Downed and not ADrawParams.SelectedByKey and
        (ADrawParams.HotPartIndex <> AControlPart)
      then
        Result := DXBAR_CHECKED
      else
        Result := GetPartState(ADrawParams, AControlPart);
  end;

begin
  if (Ribbon.Style = rs2007) or ADrawParams.IsCustomizing then
    Result := inherited GetButtonPartState(ADrawParams, AControlPart)
  else
    case AControlPart of
      bcpButton:
        Result := GetCustomButtonPartState;
      bcpDropButton:
        Result := GetDropButtonPartState
      else
        Result := DXBAR_NORMAL;
    end;
end;

function TdxRibbonBarPainter.GetCollapsedGroupCaptionRect(const AGroupRect: TRect): TRect;
begin
  Result := cxRectContent(AGroupRect, Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBAR));
  InflateRect(Result, -1, 0);
  Inc(Result.Top, cxRectHeight(Result) * FCollapsedGroupElementSizeNumerator div FCollapsedGroupElementSizeDenominator);
end;

function TdxRibbonBarPainter.GetGroupMinWidth(ABarControl: TdxRibbonGroupBarControl): Integer;
var
  ACanvas: TcxScreenCanvas;
begin
  ACanvas := TcxScreenCanvas.Create;
  try
    ACanvas.Font := ABarControl.Ribbon.Fonts.GetGroupHeaderFont;
    Result := ACanvas.TextWidth(ABarControl.GetCaption) + 2 * cxTextSpace;
    if ABarControl.CaptionButtons.Count > 0 then
      Inc(Result, cxRectWidth(ABarControl.CaptionButtons.Rect) +
        Skin.GetContentOffsets(GetToolbarSkinPart(ABarControl)).Right);
  finally
    ACanvas.Free;
  end;
end;

function TdxRibbonBarPainter.GetCollapsedGroupGlyph(ABarControl: TdxBarControl): TBitmap;
begin
  Result := ABarControl.Bar.Glyph;
  if (Result <> nil) and Result.Empty then
    Result := nil;
end;

function TdxRibbonBarPainter.GetCollapsedGroupGlyphBackgroundSize(
  ABarControl: TdxBarControl): TSize;
var
  AGroupContentHeight: Integer;
begin
  AGroupContentHeight := ABarControl.Height -
    cxMarginsWidth(Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBAR));
  with Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBARGLYPHBACKGROUND) do
    Result.cy := (Top + GetSmallIconSize + Bottom) * AGroupContentHeight div FCollapsedGroupElementSizeDenominator;
  Result.cx := Result.cy;
end;

function TdxRibbonBarPainter.GetCollapsedGroupGlyphSize(ABarControl: TdxBarControl): TSize;
var
  AGlyphSize: TSize;
  AGroupGlyph: TBitmap;
//  AMaxGlyphHeight: Integer;
//  R: TRect;
begin
  AGroupGlyph := GetCollapsedGroupGlyph(ABarControl);
  if AGroupGlyph <> nil then
    AGlyphSize := cxSize(AGroupGlyph.Width, AGroupGlyph.Height)
  else
    AGlyphSize := cxSize(GetSmallIconSize, GetSmallIconSize);
//  R := ABarControl.ClientRect;
//  ExtendRect(R, Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBAR));
//  R.Bottom := GetGroupCaptionRect(ABarControl.ClientRect).Top;
//  with Skin.GetContentOffsets(DXBAR_COLLAPSEDTOOLBARGLYPHBACKGROUND) do
//    AMaxGlyphHeight := cxRectHeight(R) - (Top + Bottom) - (dxRibbonCollapsedGroupGlyphBackgroundOffsets.Top + dxRibbonCollapsedGroupGlyphBackgroundOffsets.Bottom);
//  Result.cy := AGlyphSize.cy;
//  if Result.cy > AMaxGlyphHeight then
//    Result.cy := AMaxGlyphHeight;
//  Result.cx := MulDiv(AGlyphSize.cx, Result.cy, AGlyphSize.cy);

  if (AGlyphSize.cx <= GetSmallIconSize) and (AGlyphSize.cy <= GetSmallIconSize) then
    Result := AGlyphSize
  else
    if AGlyphSize.cx > AGlyphSize.cy then
    begin
      Result.cx := GetSmallIconSize;
      Result.cy := AGlyphSize.cy * GetSmallIconSize div AGlyphSize.cx;
    end
    else
    begin
      Result.cy := GetSmallIconSize;
      Result.cx := AGlyphSize.cx * GetSmallIconSize div AGlyphSize.cy;
    end;
end;

function TdxRibbonBarPainter.GetGroupState(ABarControl: TdxBarControl): Integer;
const
  GroupStates: array[TdxBarMarkState] of Integer = (DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED);
begin
  if ABarControl.IAccessibilityHelper.IsSelected then
    Result := DXBAR_ACTIVE
  else
    Result := GroupStates[(ABarControl as TdxRibbonGroupBarControl).MarkDrawState];
end;

function TdxRibbonBarPainter.InternalGetGroupCaptionHeight(
  ATextHeight: Integer): Integer;
begin
  Result := ATextHeight + dxRibbonGroupCaptionHeightCorrection;
end;

{ TdxCustomRibbonDockControl }

procedure TdxCustomRibbonDockControl.UpdateColorScheme;
begin
  RepaintBarControls;
  Invalidate;
end;

procedure TdxCustomRibbonDockControl.AdjustSize;
begin
end;

function TdxCustomRibbonDockControl.AllowUndockWhenLoadFromIni: Boolean;
begin
  Result := False;
end;

procedure TdxCustomRibbonDockControl.FillBackground(DC: HDC;
  const ADestR, ASourceR: TRect; ABrush: HBRUSH; AColor: TColor);
begin
end;

function TdxCustomRibbonDockControl.GetSunkenBorder: Boolean;
begin
  Result := False;
end;

function TdxCustomRibbonDockControl.IsDrawDesignBorder: Boolean;
begin
  Result := False;
end;

function TdxCustomRibbonDockControl.IsTransparent: Boolean;
begin
  Result := False;
end;

procedure TdxCustomRibbonDockControl.VisibleChanged;
begin
end;

procedure TdxCustomRibbonDockControl.CMVisibleChanged(var Message: TMessage);
begin
  if HandleAllocated and not Visible then
    ShowWindow(Handle, SW_HIDE); // SC's bugs ID CB41787, CB47149
  VisibleChanged;
  inherited;
end;

procedure TdxCustomRibbonDockControl.WMLButtonDblClk(var Message: TWMLButtonDblClk);
begin
  if BarManager <> nil then
  begin
    if BarManager.Designing then
      inherited
    else
      Message.Result := 0;
  end;
end;

{ TdxRibbonGroupsDockControl }

constructor TdxRibbonGroupsDockControl.Create(ATab: TdxRibbonTab);
begin
  inherited Create(nil);
  AllowDocking := False;
  FTab := ATab;
  FViewInfo := GetViewInfoClass.Create(Self);
end;

destructor TdxRibbonGroupsDockControl.Destroy;
begin
  FreeAndNil(FViewInfo);
  inherited Destroy;
end;

procedure TdxRibbonGroupsDockControl.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
var
  R: TRect;
begin
  if (Ribbon <> nil) and not Ribbon.IsLocked then
  begin
    SiteViewInfo.Calculate(GetControlRect(Ribbon.GroupsDockControlSite));
    R := Tab.GetDockControlBounds;
    Dec(AWidth, Max(0, SiteViewInfo.TabGroupsScrollButtonLeft.Bounds.Right - R.Left));
    Dec(AWidth, Max(0, R.Right - SiteViewInfo.TabGroupsScrollButtonRight.Bounds.Left));
    Inc(ALeft, Max(0, SiteViewInfo.TabGroupsScrollButtonLeft.Bounds.Right - R.Left));
    inherited SetBounds(ALeft, ATop, AWidth, AHeight);
    UpdateGroupPositions;
    SiteViewInfo.Invalidate;
  end
  else
    inherited SetBounds(ALeft, ATop, AWidth, AHeight);
end;

procedure TdxRibbonGroupsDockControl.AlignControls(AControl: TControl;
  var Rect: TRect);
begin
  if HandleAllocated and IsWindowVisible(Handle) then
    RedrawWindow(Handle, nil, 0, RDW_FRAME or RDW_INVALIDATE or RDW_ALLCHILDREN);
end;

procedure TdxRibbonGroupsDockControl.CalcRowToolbarPositions(ARowIndex: Integer;
  AClientSize: Integer);
begin
  if Visible then
    Tab.UpdateDockControl;
end;

procedure TdxRibbonGroupsDockControl.DblClick;
begin
end;

procedure TdxRibbonGroupsDockControl.FillBackground(DC: HDC;
  const ADestR, ASourceR: TRect; ABrush: HBRUSH; AColor: TColor);
var
  AViewInfo: TdxRibbonViewInfo;
begin
  cxPaintCanvas.BeginPaint(DC);
  try
    AViewInfo := Ribbon.ViewInfo;
    with AViewInfo.GroupsDockControlSiteBounds do
      cxPaintCanvas.WindowOrg := cxPointOffset(cxPaintCanvas.WindowOrg, Left + Self.Left, Top + Self.Top);
    AViewInfo.Painter.DrawGroupsArea(cxPaintCanvas, AViewInfo.GetGroupsDockControlSiteBounds);
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

procedure TdxRibbonGroupsDockControl.FullInvalidate;
begin
  WinControlFullInvalidate(Self, True);
end;

function TdxRibbonGroupsDockControl.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonGroupsDockControlAccessibilityHelper;
end;

function TdxRibbonGroupsDockControl.GetDockedBarControlClass: TdxBarControlClass;
begin
  Result := TdxRibbonGroupBarControl;
end;

function TdxRibbonGroupsDockControl.GetPainter: TdxBarPainter;
begin
  if Ribbon <> nil then
    Result := Ribbon.GroupsPainter
  else
    Result := inherited GetPainter;
end;

function TdxRibbonGroupsDockControl.GetViewInfoClass: TdxRibbonGroupsDockControlViewInfoClass;
begin
  Result := TdxRibbonGroupsDockControlViewInfo;
end;

function TdxRibbonGroupsDockControl.IsMultiRow: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonGroupsDockControl.MakeRectFullyVisible(const R: TRect);
var
  ANewLeft: Integer;
begin
  if (R.Left < 0) or (R.Right > ClientWidth) then
  begin
    if (cxRectWidth(R) > ClientWidth) or (R.Left < 0) then
      ANewLeft := 0
    else
      ANewLeft := ClientWidth - cxRectWidth(R);
    if ANewLeft <> R.Left then
      ViewInfo.InternalScrollGroups(ANewLeft - R.Left, cxRectWidth(Ribbon.ViewInfo.GetTabGroupsDockControlBounds));
  end;
end;

procedure TdxRibbonGroupsDockControl.Paint;
var
  AViewInfo: TdxRibbonViewInfo;
  R: TRect;
begin
  cxPaintCanvas.BeginPaint(Canvas);
  try
    AViewInfo := Ribbon.ViewInfo;
    R := AViewInfo.GetGroupsDockControlSiteBounds;
    cxPaintCanvas.WindowOrg := cxPointOffset(cxPaintCanvas.WindowOrg, R.Left + Left, R.Top + Top);
    AViewInfo.Painter.DrawGroupsArea(cxPaintCanvas, R);
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

procedure TdxRibbonGroupsDockControl.SetSize;
begin
end;

procedure TdxRibbonGroupsDockControl.ShowCustomizePopup;
begin
  if Ribbon.IsDesigning then
    ShowDesignMenu;
end;

procedure TdxRibbonGroupsDockControl.UpdateGroupPositions;
var
  AToolbar: TdxRibbonGroupBarControl;
  I, X: Integer;
  R: TRect;
  WP: Cardinal;
begin
  WP := BeginDeferWindowPos(ViewInfo.GroupCount);
  try
    X := ViewInfo.FirstGroupPosition;
    for I := 0 to ViewInfo.GroupCount - 1 do
    begin
      AToolbar := ViewInfo.GroupViewInfos[I].BarControl;
      with AToolbar.ViewInfo.GetSize do
        R := Rect(X, 0, X + cx, cy);
      if (AToolbar.Left <> R.Left) or (AToolbar.Top <> R.Top) or
        (AToolbar.Width <> cxRectWidth(R)) or (AToolbar.Height <> cxRectHeight(R)) then
      begin
        if AToolbar.HandleAllocated then
          DeferWindowPos(WP, AToolbar.Handle, 0, R.Left, R.Top, cxRectWidth(R), cxRectHeight(R),
            SWP_DRAWFRAME or SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_NOZORDER)
        else
          AToolbar.SetBounds(R.Left, R.Top, cxRectWidth(R), cxRectHeight(R));
      end;
      X := R.Right + Painter.GetToolbarsOffsetForAutoAlign;
    end;
  finally
    EndDeferWindowPos(WP);
  end;
end;

procedure TdxRibbonGroupsDockControl.VisibleChanged;
begin
  if HandleAllocated and Visible then
  begin
    Tab.UpdateDockControl;
    RepaintBarControls;
  end;
end;

procedure TdxRibbonGroupsDockControl.DesignMenuClick(Sender: TObject);
begin
  case TdxBarButton(Sender).Tag of
    0: Ribbon.Tabs.Add.DesignSelectionHelper.SelectComponent;
    1: Ribbon.DesignAddTabGroup(Tab, False);
    2: Ribbon.DesignAddTabGroup(Tab, True);
  end;
end;

function TdxRibbonGroupsDockControl.GetRibbon: TdxCustomRibbon;
begin
  Result := Tab.Ribbon;
end;

function TdxRibbonGroupsDockControl.GetSiteViewInfo: TdxRibbonGroupsDockControlSiteViewInfo;
begin
  Result := Ribbon.GroupsDockControlSite.ViewInfo;
end;

procedure TdxRibbonGroupsDockControl.InitDesignMenu(AItemLinks: TdxBarItemLinks);
begin
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONADDTAB), DesignMenuClick, 0);
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONADDEMPTYGROUP), DesignMenuClick, 1, True);
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONADDGROUPWITHTOOLBAR), DesignMenuClick, 2);
end;

procedure TdxRibbonGroupsDockControl.ShowDesignMenu;
begin
  BarDesignController.ShowCustomCustomizePopup(BarManager, InitDesignMenu, Painter);
end;

procedure TdxRibbonGroupsDockControl.WMGestureNotify(var Message: TWMGestureNotify);
begin
  Message.Result := DefWindowProc(Handle, Message.Msg, Message.Unused, LPARAM(Message.NotifyStruct));
end;

{ TdxRibbonGroupsDockControlViewInfo }

constructor TdxRibbonGroupsDockControlViewInfo.Create(
  ADockControl: TdxRibbonGroupsDockControl);
begin
  inherited Create;
  FDockControl := ADockControl;
  FScrollButtons := [];
end;

procedure TdxRibbonGroupsDockControlViewInfo.Calculate(const ABoundsRect: TRect);

  function AllGroupsFitIn: Boolean;
  begin
    Result := TryPlaceGroups(cxRectWidth(ABoundsRect));
  end;

  procedure AfterCalculate;
  var
    I: Integer;
  begin
    for I := 0 to GroupCount - 1 do
      GroupViewInfos[I].AfterCalculate;
  end;

  procedure BeforeCalculate;
  var
    I: Integer;
  begin
    for I := 0 to GroupCount - 1 do
      GroupViewInfos[I].BeforeCalculate(GroupViewInfos[I].BarControl.Group.Restriction = rtgrNoExpand);
  end;

  procedure CalculateGroups;
  var
    I: Integer;
  begin
    for I := 0 to GroupCount - 1 do
      GroupViewInfos[I].Calculate;
  end;

  procedure ReduceGroupsInit;
  var
    I: Integer;
  begin
    for I := 0 to GroupCount - 1 do
      GroupViewInfos[I].ReduceInit;
  end;

  function ReduceGroups(AStage: TdxRibbonGroupsReduceStage; AUpToViewLevel: TdxBarItemRealViewLevel): Boolean;
  var
    I: Integer;
  begin
    I := GroupCount - 1;
    repeat
      if not GroupViewInfos[I].Reduce(AStage, AUpToViewLevel) then
        Dec(I);
      Result := AllGroupsFitIn
    until Result or (I < 0);
  end;

var
  AGroupsReduceStage: TdxRibbonGroupsReduceStage;
  AUpToViewLevel: TdxBarItemRealViewLevel;
begin
  BeforeCalculate;
  try
    CalculateGroups;
    if not AllGroupsFitIn then
    begin
      ReduceGroupsInit;
      for AGroupsReduceStage := Low(TdxRibbonGroupsReduceStage) to High(TdxRibbonGroupsReduceStage) do
      begin
        if AGroupsReduceStage = rgrsItemControlsViewLevel then
        begin
          for AUpToViewLevel := Succ(Low(TdxBarItemRealViewLevel)) to High(TdxBarItemRealViewLevel) do
            if ReduceGroups(AGroupsReduceStage, AUpToViewLevel) then
              Break;
        end
        else
          if ReduceGroups(AGroupsReduceStage, ivlLargeIconWithText) then
            Break;
        if AllGroupsFitIn then
          Break;
      end;
    end;
  finally
    AfterCalculate;
  end;
  CalculateGroupsScrollInfo(cxRectWidth(ABoundsRect));
  CheckGroupsCollapsedStates;
end;

procedure TdxRibbonGroupsDockControlViewInfo.ResetScrollInfo;
begin
  FScrollPosition := 0;
  FScrollButtons := [];
end;

procedure TdxRibbonGroupsDockControlViewInfo.ScrollGroups(AScrollLeft: Boolean;
  AMaxContentWidth: Integer);
begin
  if AScrollLeft then
    InternalScrollGroups(-dxRibbonGroupsScrollDelta, AMaxContentWidth)
  else
    InternalScrollGroups(dxRibbonGroupsScrollDelta, AMaxContentWidth);
end;

procedure TdxRibbonGroupsDockControlViewInfo.CalculateGroupsScrollInfo(
  AMaxContentWidth: Integer);
var
  ATotalGroupsWidth: Integer;
begin
  ATotalGroupsWidth := TotalGroupsWidth;
  if ATotalGroupsWidth <= AMaxContentWidth then
  begin
    FScrollButtons := [];
    FScrollPosition := 0;
  end
  else
  begin
    if FScrollButtons = [] then
      FScrollButtons := [rsbRight]
    else
      if FScrollButtons = [rsbLeft] then
        FScrollPosition := AMaxContentWidth - ATotalGroupsWidth
      else
        if FScrollButtons = [rsbLeft, rsbRight] then
        begin
          if FScrollPosition + ATotalGroupsWidth <= AMaxContentWidth then
          begin
            FScrollButtons := [rsbLeft];
            FScrollPosition := AMaxContentWidth - ATotalGroupsWidth;
          end;
        end;
  end;
end;

procedure TdxRibbonGroupsDockControlViewInfo.InternalScrollGroups(
  ADelta: Integer; AMaxContentWidth: Integer);

  procedure CheckScrollPosition;
  begin
    if FScrollPosition > 0 then
      FScrollPosition := 0
    else
      FScrollPosition := Max(FScrollPosition, AMaxContentWidth - TotalGroupsWidth);
  end;

begin
  Inc(FScrollPosition, ADelta);
  CheckScrollPosition;
  FScrollButtons := [];
  if FScrollPosition < 0 then
    Include(FScrollButtons, rsbLeft);
  if FScrollPosition + TotalGroupsWidth > AMaxContentWidth then
    Include(FScrollButtons, rsbRight);
  DockControl.Tab.UpdateDockControlBounds;
end;

procedure TdxRibbonGroupsDockControlViewInfo.CheckGroupsCollapsedStates;
var
  I: Integer;
begin
  for I := 0 to GroupCount - 1 do
    GroupViewInfos[I].CheckGroupCollapsedStates;
end;

function TdxRibbonGroupsDockControlViewInfo.GetFirstGroupPosition: Integer;
begin
  Result := FScrollPosition;
  if rsbLeft in ScrollButtons then
    Dec(Result, DockControl.Left - DockControl.Ribbon.ViewInfo.GetTabGroupsDockControlOffset.Left);
end;

function TdxRibbonGroupsDockControlViewInfo.GetGroupCount: Integer;
var
  AToolbar: TdxBar;
  I: Integer;
begin
  Result := 0;
  for I := 0 to DockControl.Tab.Groups.Count - 1 do
  begin
    AToolbar := DockControl.Tab.Groups[I].ToolBar;
    if IsValidToolbar(AToolbar) then
      Inc(Result);
  end;
end;

function TdxRibbonGroupsDockControlViewInfo.GetGroupViewInfo(
  AIndex: Integer): TdxRibbonGroupBarControlViewInfo;
var
  AToolbar: TdxBar;
  I: Integer;
begin
  Result := nil;
  for I := 0 to DockControl.Tab.Groups.Count - 1 do
  begin
    AToolbar := DockControl.Tab.Groups[I].ToolBar;
    if IsValidToolbar(AToolbar) then
      if AIndex = 0 then
      begin
        Result := (AToolBar.Control as TdxRibbonGroupBarControl).ViewInfo;
        Break;
      end
      else
        Dec(AIndex);
  end;
end;

function TdxRibbonGroupsDockControlViewInfo.IsValidToolbar(AToolbar: TdxBar): Boolean;
begin
  Result := (AToolbar <> nil) and (AToolbar.Control <> nil) and (AToolbar.Control.DockControl = DockControl);
end;

function TdxRibbonGroupsDockControlViewInfo.TotalGroupsWidth: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to GroupCount - 1 do
    Inc(Result, GroupViewInfos[I].GetSize.cx);
  if GroupCount > 1 then
    Inc(Result, DockControl.Painter.GetToolbarsOffsetForAutoAlign * (GroupCount - 1));
end;

function TdxRibbonGroupsDockControlViewInfo.TryPlaceGroups(
  AMaxContentWidth: Integer): Boolean;
var
  AGroupWidth, I, X: Integer;
begin
  Result := True;
  X := 0;
  for I := 0 to GroupCount - 1 do
  begin
    AGroupWidth := GroupViewInfos[I].GetSize.cx;
    Result := X + AGroupWidth <= AMaxContentWidth;
    if not Result then
      Break;
    Inc(X, AGroupWidth + DockControl.Painter.GetToolbarsOffsetForAutoAlign);
  end;
end;

{ TdxRibbonTabGroupsPopupWindow }

constructor TdxRibbonTabGroupsPopupWindow.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create(ARibbon);
  FRibbon := ARibbon;
  FShadow := TdxBarShadow.Create(Self);
  ModalMode := False;
end;

destructor TdxRibbonTabGroupsPopupWindow.Destroy;
begin
  FreeAndNil(FShadow);
  inherited Destroy;
end;

function TdxRibbonTabGroupsPopupWindow.CalculatePosition: TPoint;
begin
  Result := GetBounds.TopLeft;
end;

procedure TdxRibbonTabGroupsPopupWindow.CalculateSize;
var
  R: TRect;
begin
  R := GetBounds;
  SetBounds(Left, Top, cxRectWidth(R), cxRectHeight(R));
end;

function TdxRibbonTabGroupsPopupWindow.CanShowShadow: Boolean;
begin
  Result := (Ribbon.Style < rs2013) and dxCanUseShadows;
end;

procedure TdxRibbonTabGroupsPopupWindow.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.WindowClass.Style := Params.WindowClass.Style or CS_SAVEBITS;
end;

procedure TdxRibbonTabGroupsPopupWindow.Deactivate;
begin
  if (ActiveBarControl = nil) or not (bsHideAll in TCustomdxBarControlAccess(ActiveBarControl).FState) then
    inherited Deactivate;
end;

procedure TdxRibbonTabGroupsPopupWindow.DoClosed;
begin
  Ribbon.UpdateFormActionControl(False);
  inherited DoClosed;
  FShadow.Visible := False;
  GroupsDockControlSite.BoundsRect := cxEmptyRect;
  GroupsDockControlSite.Parent := Ribbon;
  Ribbon.Invalidate;
end;

procedure TdxRibbonTabGroupsPopupWindow.DoShowed;
begin
  inherited DoShowed;
  FSwitchingBetweenTabs := False;
  if CanShowShadow then
  begin
    FShadow.SetOwnerBounds(cxEmptyRect, BoundsRect);
    FShadow.Visible := True;
  end;
end;

procedure TdxRibbonTabGroupsPopupWindow.DoShowing;
begin
  Ribbon.UpdateFormActionControl(True);
  inherited DoShowing;
  SetGroupsDockControlSite;
end;

procedure TdxRibbonTabGroupsPopupWindow.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited KeyDown(Key, Shift);
  HandleNavigationKey(Key);
end;

procedure TdxRibbonTabGroupsPopupWindow.KeyPress(var Key: Char);
begin
  inherited KeyPress(Key);
  if Word(Key) = VK_ESCAPE then
    CloseUp
  else
    HandleNavigationKey(Word(Key));
end;

function TdxRibbonTabGroupsPopupWindow.NeedIgnoreMouseMessageAfterCloseUp(
  AWnd: THandle; AMsg: Cardinal; AShift: TShiftState; const APos: TPoint): Boolean;
var
  AForm: TCustomForm;
  AHitInfo: TdxRibbonHitInfo;
begin
  Result := False;
  if AWnd = Ribbon.Handle then
  begin
    if (AMsg = WM_LBUTTONDOWN) and not (ssDouble in AShift) then
    begin
      AHitInfo := TdxRibbonHitInfo.Create(Ribbon.ViewInfo);
      try
        AHitInfo.Calculate(Ribbon.ScreenToClient(APos));
        Result := AHitInfo.HitTest = rhtTab;
        if Result then
          FSwitchingBetweenTabs := AHitInfo.HitObjectAsTab <> Ribbon.ActiveTab;
      finally
        AHitInfo.Free;
      end;
    end;
  end
  else
  begin
    AForm := GetParentForm(Ribbon);
    if (AForm.Handle <> AWnd) and not dxHasAsParent(AWnd, Ribbon.Handle) then
      Result := not Ribbon.DoHideMinimizedByClick(AWnd, AShift, APos)
    else
      Result := False;
  end;
end;

procedure TdxRibbonTabGroupsPopupWindow.HandleNavigationKey(AKey: Word);
begin
  if BarNavigationController.IsNavigationKey(AKey) then
  begin
    BarNavigationController.SetKeyTipsShowingState(nil, '');
    SelectFirstSelectableAccessibleObject(GroupsDockControlSite.DockControl.IAccessibilityHelper.GetBarHelper);
  end;
end;

procedure TdxRibbonTabGroupsPopupWindow.SetGroupsDockControlSite;
var
  R: TRect;
begin
  if Ribbon.ActiveTab <> nil then
  begin
    GroupsDockControlSite.Parent := Self;
    GroupsDockControlSite.BoundsRect := GetControlRect(Self);
    R := cxRectContent(GroupsDockControlSite.BoundsRect, Ribbon.ViewInfo.GetTabGroupsDockControlOffset);
    GroupsDockControlSite.DockControl.ViewInfo.ResetScrollInfo;
    GroupsDockControlSite.DockControl.HandleNeeded;
    GroupsDockControlSite.DockControl.ViewInfo.Calculate(R);
    GroupsDockControlSite.DockControl.BoundsRect := R;
    GroupsDockControlSite.DockControl.Visible := True;
  end;
end;

function TdxRibbonTabGroupsPopupWindow.GetBounds: TRect;
var
  AMonitorRect, ARibbonRect, ATabsRect: TRect;
  ATabGroupsHeight: Integer;
begin
  ARibbonRect := dxMapWindowRect(Ribbon.Handle, 0, Ribbon.ClientRect);
  ATabsRect := dxMapWindowRect(Ribbon.Handle, 0, Ribbon.ViewInfo.TabsViewInfo.Bounds);
  Result := cxRect(ARibbonRect.Left, ATabsRect.Top - 1, ARibbonRect.Right, ATabsRect.Bottom);
  Dec(Result.Bottom, Ribbon.SkinGetPartSize(DXBAR_TABSGROUPSOVERLAPHEIGHT));
  ATabGroupsHeight := Ribbon.ViewInfo.GetTabGroupsHeight(True);
  AMonitorRect := GetMonitorWorkArea(0);
  cxRectIntersect(Result, Result, AMonitorRect);
  if (Result.Bottom + ATabGroupsHeight > AMonitorRect.Bottom) and (Ribbon.Style <> rs2013) then
    Result := cxRect(Result.Left, Result.Top - ATabGroupsHeight, Result.Right, Result.Top)
  else
    Result := cxRect(Result.Left, Result.Bottom, Result.Right, Result.Bottom + ATabGroupsHeight);
end;

function TdxRibbonTabGroupsPopupWindow.GetGroupsDockControlSite: TdxRibbonGroupsDockControlSite;
begin
  Result := Ribbon.GroupsDockControlSite;
end;

procedure TdxRibbonTabGroupsPopupWindow.WMNCPaint(var Message: TMessage);
var
  DC: HDC;
  AFlags: Integer;
  ARgn: HRGN;
begin
  AFlags := DCX_CACHE or DCX_CLIPSIBLINGS or DCX_WINDOW or DCX_VALIDATE;
  if Message.WParam <> 1 then
  begin
    ARgn := CreateRectRgnIndirect(cxEmptyRect);
    CombineRgn(ARgn, Message.WParam, 0, RGN_COPY);
    AFlags := AFlags or DCX_INTERSECTRGN;
  end
  else
    ARgn := 0;

  DC := GetDCEx(Handle, ARgn, AFlags);
  try
    Ribbon.ColorScheme.DrawTabGroupsArea(DC, ClientRect, False, False);
  finally
    ReleaseDC(Handle, DC);
  end;
end;

procedure TdxRibbonTabGroupsPopupWindow.WMShowWindow(var Message: TWMShowWindow);
const
  FlagsMap: array[Boolean] of Integer =
    (AW_SLIDE or AW_VER_NEGATIVE or AW_HIDE, AW_SLIDE or AW_VER_POSITIVE);
var
  AAnimationTime: Integer;
begin
  if AllowShowHideAnimation and not FSwitchingBetweenTabs and Assigned(AnimateWindowProc) then
  begin
    if Message.Show then
      AAnimationTime := dxRibbonTabGroupsPopupWindowShowAnimationTime
    else
      AAnimationTime := dxRibbonTabGroupsPopupWindowHideAnimationTime;

    AnimateWindowProc(Handle, Max(AAnimationTime, 1), FlagsMap[Message.Show]);
  end;
  inherited;
end;

procedure TdxRibbonTabGroupsPopupWindow.WMSize(var Message: TWMSize);
begin
  inherited;
  if Ribbon.UseRoundedWindowCorners then
    SetWindowRgn(Handle, CreateRoundRectRgn(0, 0, Message.Width + 1, Message.Height + 1, 4, 4), True);
end;

{ TdxRibbonCustomBarControl }

function TdxRibbonCustomBarControl.AllowSelectionFrame: Boolean;
begin
  Result := True;
end;

function TdxRibbonCustomBarControl.AllowFade: Boolean;
begin
  Result := Ribbon.CanFade;
end;

procedure TdxRibbonCustomBarControl.InitializeForDock(ABar: TdxBar);
begin
  inherited;
  if not (csDesigning in ComponentState) then
    ControlStyle := ControlStyle - [csDoubleClicks];
end;

function TdxRibbonCustomBarControl.AllowQuickCustomizing: Boolean;
begin
  Result := False;
end;

function TdxRibbonCustomBarControl.CanAlignControl(AControl: TdxBarItemControl): Boolean;
begin
  Result := True;
end;

function TdxRibbonCustomBarControl.CanMoving: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonCustomBarControl.DrawBarParentBackground(ACanvas: TcxCanvas);
begin
end;

function TdxRibbonCustomBarControl.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonBarControlAccessibilityHelper;
end;

function TdxRibbonCustomBarControl.GetBehaviorOptions: TdxBarBehaviorOptions;
begin
  Result := dxRibbonBarBehaviorOptions;
end;

function TdxRibbonCustomBarControl.GetEditFont: TFont;
begin
  if Ribbon = nil then
    Result := inherited GetEditFont
  else
    Result := Ribbon.Fonts.GetGroupFont;
end;

function TdxRibbonCustomBarControl.GetFont: TFont;
begin
  if Ribbon = nil then
    Result := inherited GetFont
  else
    Result := Ribbon.Fonts.GetGroupFont;
end;

function TdxRibbonCustomBarControl.GetFullItemRect(Item: TdxBarItemControl): TRect;
begin
  Result := GetItemRect(Item);
end;

function TdxRibbonCustomBarControl.GetIsMainMenu: Boolean;
begin
  Result := False;
end;

function TdxRibbonCustomBarControl.GetMultiLine: Boolean;
begin
  Result := False;
end;

{
function TdxRibbonCustomBarControl.HasCloseButton: Boolean;
begin
  Result := False;
end;
}

function TdxRibbonCustomBarControl.MarkExists: Boolean;
begin
  Result := False;
end;

function TdxRibbonCustomBarControl.NotHandleMouseMove(
  ACheckLastMousePos: Boolean = True): Boolean;
begin
  Result := inherited NotHandleMouseMove(ACheckLastMousePos) or dxBarHasPopupWindowAbove(Self, True);
end;

function TdxRibbonCustomBarControl.RealMDIButtonsOnBar: Boolean;
begin
  Result := False;
end;

function TdxRibbonCustomBarControl.ClickAtHeader: Boolean;
var
  R: TRect;
begin
  R := WindowRect;
  R.Top := R.Bottom - (Height - ClientBounds.Bottom);
  Result := cxRectPtIn(R, GetMouseCursorPos);
end;

procedure TdxRibbonCustomBarControl.DoPopupMenuClick(Sender: TObject);
begin
  Ribbon.PopupMenuItemClick(Sender);
end;

function TdxRibbonCustomBarControl.GetPopupMenuItems: TdxRibbonPopupMenuItems;
begin
  Result := Ribbon.GetValidPopupMenuItems - [rpmiItems];
end;

procedure TdxRibbonCustomBarControl.InitCustomizationPopup(AItemLinks: TdxBarItemLinks);
begin
  Ribbon.PopulatePopupMenuItems(AItemLinks, GetPopupMenuItems, PopupMenuClick);
end;

procedure TdxRibbonCustomBarControl.PopupMenuClick(Sender: TObject);
var
  ALinkSelf: TcxObjectLink;
begin
  ALinkSelf := cxAddObjectLink(Self);
  try
    DoPopupMenuClick(Sender);
    if ALinkSelf.Ref <> nil then
      HideAll;
  finally
    cxRemoveObjectLink(ALinkSelf);
  end;
end;

procedure TdxRibbonCustomBarControl.ShowPopup(AItem: TdxBarItemControl);
var
  AItemLink: TdxBarItemLink;
begin
  if not BarManager.IsCustomizing then
  begin
    if AItem <> nil then
      AItemLink := AItem.ItemLink
    else
      AItemLink := nil;
    if (AItemLink <> nil) or ClickAtHeader then
      BarDesignController.ShowCustomCustomizePopup(BarManager, InitCustomizationPopup, Painter, Self, AItemLink);
  end
  else
    inherited;
end;

function TdxRibbonCustomBarControl.GetQuickAccessToolbar: TdxRibbonQuickAccessToolbar;
begin
  if Ribbon <> nil then
    Result := Ribbon.QuickAccessToolbar
  else
    Result := nil;
end;

procedure TdxRibbonCustomBarControl.WMNCHitTest(var Message: TWMNCHitTest);
var
  R: TRect;
begin
  R := cxRectOffset(ClientRect, ClientToScreen(cxNullPoint));
  inherited;
  if cxRectPtIn(R, SmallPointToPoint(Message.Pos)) then
  begin
    if HitTest = HTCAPTION then
      HitTest := HTCLIENT;
  end
  else
  begin
    Message.Result := HTCLIENT;
    HitTest := HTCLIENT;
  end;
end;

{ TdxRibbonQuickAccessBarControl }

constructor TdxRibbonQuickAccessBarControl.Create(AOwner: TComponent);
begin
  inherited;
  FDefaultGlyph := cxCreateBitmap(16, 16, pf32bit);
  FBitmap := TcxBitmap32.Create;
end;

destructor TdxRibbonQuickAccessBarControl.Destroy;
begin
  if DockControl <> nil then
    DockControl.Visible := False;
  FreeAndNil(FBitmap);
  FreeAndNil(FDefaultGlyph);
  inherited Destroy;
end;

function TdxRibbonQuickAccessBarControl.IsOnGlass: Boolean;
begin
  Result := Ribbon.ViewInfo.IsQATOnGlass;
end;

procedure TdxRibbonQuickAccessBarControl.InitializeForDock(ABar: TdxBar);
begin
  inherited;
  if ABar.DockControl <> nil then
    ABar.DockControl.Visible := True;
end;

function TdxRibbonQuickAccessBarControl.AllItemsVisible: Boolean;
var
  AItemLink: TdxBarItemLink;
  I: Integer;
begin
  Result := True;
  for I := 0 to ItemLinks.CanVisibleItemCount - 1 do
  begin
    AItemLink := ItemLinks.CanVisibleItems[I];
    if (AItemLink.VisibleIndex = -1) or
      (AItemLink.Control <> nil) and IsRectEmpty(AItemLink.ItemRect) then
    begin
      Result := False;
      Break;
    end;
  end;
end;

procedure TdxRibbonQuickAccessBarControl.CalcControlsPositions;

  procedure CalcItemControlsRealPositionInButtonGroup;
  var
    AItemControlViewInfos: TList;
    AItemLink: TdxBarItemLink;
    I: Integer;
  begin
    if not ViewInfo.CanShowButtonGroups then
      Exit;

    for I := 0 to ItemLinks.VisibleItemCount - 1 do
    begin
      AItemLink := ItemLinks.VisibleItems[I];
      if AItemLink.Control = nil then
        AItemLink.CreateControl;
    end;

    AItemControlViewInfos := TList.Create;
    try
      for I := 0 to ItemLinks.VisibleItemCount - 1 do
        AItemControlViewInfos.Add(Pointer(IdxBarItemControlViewInfo(ItemLinks.VisibleItems[I].Control.ViewInfo)));
      dxRibbonGroupLayoutCalculator.CalcItemControlsRealPositionInButtonGroup(AItemControlViewInfos);
    finally
      AItemControlViewInfos.Free;
    end;
  end;

var
  AItemControlWidth, ASeparatorWidth, I, X: Integer;
  AItemLink: TdxBarItemLink;
  R: TRect;
begin
  TdxBarItemLinksAccess(ItemLinks).BeginCalcItemRects;
  try
    R := GetClientOffset;
    TdxBarItemLinksAccess(ItemLinks).EmptyItemRects;
    X := R.Left;
    Truncated := False;
    AItemLink := nil;
    CalcItemControlsRealPositionInButtonGroup;
    for I := 0 to ItemLinks.VisibleItemCount - 1 do
    begin
      AItemLink := ItemLinks.VisibleItems[I];
      if AItemLink.Control = nil then
        AItemLink.CreateControl;
      TdxBarItemControlAccess(AItemLink.Control).LastInRow := False;
      AItemControlWidth := TdxBarItemControlAccess(AItemLink.Control).Width;
      ASeparatorWidth := GetSeparatorWidth(AItemLink.Control);
      Truncated := X + ASeparatorWidth + AItemControlWidth > ClientWidth - GetMarkSize;
      if Truncated then
      begin
        if I > 0 then
          AItemLink := ItemLinks.VisibleItems[I - 1];
        Break;
      end;
      Inc(X, ASeparatorWidth);
      AItemLink.ItemRect := Rect(X, R.Top, X + AItemControlWidth, ClientHeight - R.Bottom);
      TdxBarItemLinkAccess(AItemLink).RowHeight := ClientHeight;
      Inc(X, AItemControlWidth);
    end;
    if AItemLink <> nil then
      TdxBarItemControlAccess(AItemLink.Control).LastInRow := True;
  finally
    TdxBarItemLinksAccess(ItemLinks).EndCalcItemRects;
  end;
end;

function TdxRibbonQuickAccessBarControl.CanHideAllItemsInSingleLine: Boolean;
begin
  Result := True;
end;

procedure TdxRibbonQuickAccessBarControl.CreateWnd;
begin
  FIsWindowCreation := True;
  try
    inherited CreateWnd;
  finally
    FIsWindowCreation := False;
  end;
  UpdateDefaultGlyph(FDefaultGlyph);
end;

procedure TdxRibbonQuickAccessBarControl.DoPaintItem(AControl: TdxBarItemControl; ACanvas: TcxCanvas; const AItemRect: TRect);
begin
  ACanvas.SaveClipRegion;
  try
    ACanvas.SetClipRegion(TcxRegion.Create(AControl.ViewInfo.Bounds), roSet);
    if NeedBufferedOnGlass(AControl) then
    begin
      FBitmap.SetSize(AItemRect);
      FBitmap.Clear;
      FBitmap.cxCanvas.WindowOrg := AItemRect.TopLeft;
      AControl.Paint(FBitmap.cxCanvas, AItemRect, GetPaintType);
      FBitmap.MakeOpaque;
      FBitmap.cxCanvas.WindowOrg := cxNullPoint;
      cxBitBlt(ACanvas.Handle, FBitmap.cxCanvas.Handle, AItemRect, cxNullPoint, SRCCOPY);
    end
    else
      AControl.Paint(ACanvas, AItemRect, GetPaintType);
  finally
    ACanvas.RestoreClipRegion;
  end;
  DrawSelectedItem(ACanvas.Handle, AControl, AItemRect);
end;

function TdxRibbonQuickAccessBarControl.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonQuickAccessBarControlAccessibilityHelper;
end;

function TdxRibbonQuickAccessBarControl.GetClientOffset: TRect;
begin
  Result := cxEmptyRect;
end;

function TdxRibbonQuickAccessBarControl.GetDefaultItemGlyph: TBitmap;
begin
  Result := FDefaultGlyph;
end;

function TdxRibbonQuickAccessBarControl.GetItemControlDefaultViewLevel(
  AItemControl: TdxBarItemControl): TdxBarItemViewLevel;
begin
  Result := AItemControl.ViewInfo.MinPossibleViewLevel;
end;

function TdxRibbonQuickAccessBarControl.GetMarkAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonQuickAccessBarControlMarkAccessibilityHelper;
end;

function TdxRibbonQuickAccessBarControl.GetMarkSize: Integer;
begin
  if MarkExists then
    Result := Painter.MarkSizeX(Self)
  else
    Result := 0;
end;

function TdxRibbonQuickAccessBarControl.GetMinHeight(AStyle: TdxBarDockingStyle): Integer;
begin
  if Visible then
    Result := Max(inherited GetMinHeight(AStyle), Ribbon.GetGroupRowHeight)
  else
    Result := Ribbon.GetGroupRowHeight;
end;

function TdxRibbonQuickAccessBarControl.GetMinWidth(AStyle: TdxBarDockingStyle): Integer;
begin
  Result := 0;
end;

function TdxRibbonQuickAccessBarControl.GetPopupMenuItems: TdxRibbonPopupMenuItems;
begin
  Result := inherited GetPopupMenuItems;
  if BarDesignController.CustomizingItemLink = nil then
    Exclude(Result, rpmiQATAddRemoveItem);
end;

function TdxRibbonQuickAccessBarControl.GetQuickControlClass: TdxBarPopupControlClass;
begin
  Result := TdxRibbonQuickAccessPopupBarControl;
end;

function TdxRibbonQuickAccessBarControl.GetRibbon: TdxCustomRibbon;
begin
  if DockControl <> nil then
    Result := (DockControl as TdxRibbonQuickAccessDockControl).Ribbon
  else
    Result := nil;
end;

function TdxRibbonQuickAccessBarControl.GetSize(AMaxWidth: Integer): TSize;
var
  AItem: TdxBarItemLink;
  AItemControl: TdxBarItemControlAccess;
  AItemControlHeight, AItemControlWidth, ASeparatorWidth, I: Integer;
begin
  if not CanAllocateHandle(Self) and not IsPopup or FIsWindowCreation then
  begin
    Result := cxSize(0, 0);
    Exit;
  end;
  HandleNeeded;

  Result := cxSize(GetMarkSize, GetMinHeight(dsTop));
  for I := 0 to ItemLinks.CanVisibleItemCount - 1 do
  begin
    AItem := ItemLinks.CanVisibleItems[I];
    if AItem.Control = nil then
      AItem.CreateControl;
    AItemControl := TdxBarItemControlAccess(AItem.Control);
    AItemControlWidth := AItemControl.Width;
    ASeparatorWidth := GetSeparatorWidth(AItemControl);
    if Result.cx + ASeparatorWidth + AItemControlWidth > AMaxWidth then
      Break;
    Inc(Result.cx, ASeparatorWidth + AItemControlWidth);
    AItemControlHeight := AItemControl.Height;
    if AItemControlHeight > Result.cy then
      Result.cy := AItemControlHeight;
  end;
  if MarkExists and (Result.cx = GetMarkSize) then
    Dec(Result.cx, TdxRibbonQuickAccessPainter(Painter).MarkButtonOffset);
  with GetClientOffset do
  begin
    Inc(Result.cx, Left + Right);
    Inc(Result.cy, Top + Bottom);
  end;
end;

function TdxRibbonQuickAccessBarControl.GetSizeForWidth(
  AStyle: TdxBarDockingStyle; AWidth: Integer): TSize;
begin
  Result := GetSize(AWidth);
end;

function TdxRibbonQuickAccessBarControl.GetViewInfoClass: TCustomdxBarControlViewInfoClass;
begin
  Result := TdxRibbonQuickAccessBarControlViewInfo;
end;

function TdxRibbonQuickAccessBarControl.AllowQuickCustomizing: Boolean;
begin
  Result := True;
end;

procedure TdxRibbonQuickAccessBarControl.InitQuickCustomizeItemLinks(AQuickControl: TdxBarPopupControl);
var
  ASubItem: TdxRibbonQuickAccessPopupSubItem;
begin
  InternalItems.Clear;
  if Ribbon.GetValidPopupMenuItems <> [] then
  begin
    ASubItem := TdxRibbonQuickAccessPopupSubItem(AQuickControl.ItemLinks.AddItem(TdxRibbonQuickAccessPopupSubItem).Item);
    BarDesignController.AddInternalItem(ASubItem, InternalItems);
    ASubItem.OnPopup := HandleQuickAccessSubItemPopup;
  end;
end;

procedure TdxRibbonQuickAccessBarControl.InitAddRemoveSubItemPopup(AItemLinks: TdxBarItemLinks);
var
  I: Integer;
  AItemLink: TdxBarItemLink;
  ASubItemButton: TdxRibbonQuickAccessPopupSubItemButton;
  ASeparator: TdxBarItem;
begin
  if ItemLinks.AvailableItemCount > 0 then
  begin
    ASeparator := AItemLinks.AddItem(TdxBarSeparator).Item;
    ASeparator.Caption := cxGetResourceString(@dxSBAR_CUSTOMIZEQAT);
    BarDesignController.AddInternalItem(ASeparator, InternalItems);

    for I := 0 to ItemLinks.AvailableItemCount - 1 do
    begin
      AItemLink := ItemLinks.AvailableItems[I];
      ASubItemButton := TdxRibbonQuickAccessPopupSubItemButton(AItemLinks.AddItem(TdxRibbonQuickAccessPopupSubItemButton).Item);
      ASubItemButton.Tag := TdxNativeInt(AItemLink);
      ASubItemButton.ButtonStyle := bsChecked;
      ASubItemButton.Down := AItemLink.Visible;
      BarDesignController.AddInternalItem(ASubItemButton, InternalItems);
      ASubItemButton.Caption := AItemLink.Caption;
      if AItemLink.Visible then
        ASubItemButton.Hint := RemoveAccelChars(cxGetResourceString(@dxSBAR_REMOVEFROMQAT))
      else
        ASubItemButton.Hint := RemoveAccelChars(cxGetResourceString(@dxSBAR_ADDTOQAT));
    end;
  end;
  QuickAccessToolbar.UpdateMenuItems(AItemLinks);
end;

procedure TdxRibbonQuickAccessBarControl.InitCustomizationPopup(AItemLinks: TdxBarItemLinks);
begin
  Ribbon.PopulatePopupMenuItems(AItemLinks, GetPopupMenuItems, PopupMenuClick);
end;

function TdxRibbonQuickAccessBarControl.MarkExists: Boolean;
begin
  Result := Truncated or (Ribbon.GetValidPopupMenuItems <> []);
end;

procedure TdxRibbonQuickAccessBarControl.RemoveItemFromQAT;
begin
  if BarDesignController.CustomizingItemLink.Item is TdxRibbonQuickAccessGroupButton then
    BarDesignController.DeleteCustomizingItem
  else
  begin
    if BarDesignController.CustomizingItemLink.OriginalItemLink <> nil then
      BarDesignController.CustomizingItemLink.OriginalItemLink.Free
    else
      BarDesignController.DeleteCustomizingItemLink;
  end;
end;

procedure TdxRibbonQuickAccessBarControl.ShowPopup(AItem: TdxBarItemControl);
var
  AItemLink: TdxBarItemLink;
begin
  if not BarManager.IsCustomizing then
  begin
    if AItem <> nil then
      AItemLink := AItem.ItemLink
    else
      AItemLink := nil;
    BarDesignController.ShowCustomCustomizePopup(BarManager, InitCustomizationPopup, Ribbon.GroupsPainter, Self, AItemLink);
  end
  else
    inherited;
end;

procedure TdxRibbonQuickAccessBarControl.UpdateDefaultGlyph(AGlyph: TBitmap);
var
  AGlyphSize: Integer;
  R: TRect;
begin
  if Ribbon = nil then Exit;
  AGlyphSize := TdxRibbonBarPainter(Painter).GetSmallIconSize;
  AGlyph.Width := AGlyphSize;
  AGlyph.Height := AGlyphSize;
  R := cxRect(0, 0, AGlyphSize, AGlyphSize);
  FillRectByColor(AGlyph.Canvas.Handle, R, 0);
  Ribbon.ColorScheme.DrawQuickAccessToolbarDefaultGlyph(AGlyph.Canvas.Handle, R);
end;

procedure TdxRibbonQuickAccessBarControl.UpdateDoubleBuffered;
begin
  DoubleBuffered := True;
end;

function TdxRibbonQuickAccessBarControl.GetSeparatorWidth(
  AItemControl: TdxBarItemControl): Integer;
begin
  if AItemControl.ItemLink.BeginGroup and ViewInfo.CanShowSeparators then
    Result := BeginGroupSize
  else
    Result := 0;
end;

function TdxRibbonQuickAccessBarControl.GetViewInfo: TdxRibbonQuickAccessBarControlViewInfo;
begin
  Result := TdxRibbonQuickAccessBarControlViewInfo(FViewInfo);
end;

procedure TdxRibbonQuickAccessBarControl.WMPaint(var Message: TWMPaint);
begin
  if (Ribbon <> nil) and Ribbon.IsDestroying then
  begin
    Message.Result := 0;
    Exit;
  end;
  if not FDoubleBuffered or (Message.DC <> 0) then
  begin
    if not (csCustomPaint in ControlState) and (ControlCount = 0) then
      inherited
    else
      PaintHandler(Message);
  end
  else
  begin
    if (Ribbon <> nil) and Ribbon.ViewInfo.UseGlass then
      dxPaintWindowOnGlass(Handle, True)
    else
      dxBufferedPaintControl(Self);
  end;
end;

{ TdxRibbonQuickAccessBarControlViewInfo }

function TdxRibbonQuickAccessBarControlViewInfo.CanShowSeparators: Boolean;
begin
  Result := False;
end;

function TdxRibbonQuickAccessBarControlViewInfo.IsLastVisibleItemControl(
  AItemControl: TdxBarItemControl): Boolean;
begin
  Result := TdxBarItemControlAccess(AItemControl).LastInRow;
end;

{ TdxRibbonQuickAccessItemControlPainter }

function TdxRibbonQuickAccessPainter.BarMarkRect(ABarControl: TdxBarControl): TRect;
begin
  Result := BarMarkItemRect(ABarControl);
end;

function TdxRibbonQuickAccessPainter.BarMarkItemRect(ABarControl: TdxBarControl): TRect;
begin
  Result := ABarControl.ClientRect;
  Result.Left := Result.Right - (MarkSizeX(ABarControl) - MarkButtonOffset);
end;

procedure TdxRibbonQuickAccessPainter.BarDrawMarkBackground(
  ABarControl: TdxBarControl; DC: HDC; ItemRect: TRect; AToolbarBrush: HBRUSH);
const
  States: array[TdxBarMarkState] of Integer =
    (DXBAR_NORMAL, DXBAR_ACTIVE, DXBAR_PRESSED);
var
  AState: Integer;
begin
  AState := States[TdxRibbonQuickAccessBarControl(ABarControl).MarkDrawState];
  if AState <> DXBAR_NORMAL then
    Skin.DrawBackground(DC, ItemRect, DXBAR_SMALLBUTTON, AState);
end;

procedure TdxRibbonQuickAccessPainter.ComboControlDrawArrowButton(
  const ADrawParams: TdxBarEditLikeControlDrawParams; ARect: TRect;
  AInClientArea: Boolean);
var
  ABitmap: TcxBitmap32;
  ASaveCanvas: TcxCanvas;
begin
  if AInClientArea or not ADrawParams.BarEditControl.OnGlass then
    inherited
  else
  begin
    ABitmap := TcxBitmap32.CreateSize(ARect, True);
    try
      ABitmap.cxCanvas.WindowOrg := ARect.TopLeft;
      ASaveCanvas := ADrawParams.Canvas;
      ADrawParams.Canvas := ABitmap.cxCanvas;
      inherited;
      ADrawParams.Canvas := ASaveCanvas;
      ABitmap.MakeOpaque;
      ABitmap.cxCanvas.WindowOrg := cxNullPoint;
      cxBitBlt(ADrawParams.Canvas.Handle, ABitmap.cxCanvas.Handle, ARect, cxNullPoint, SRCCOPY);
    finally
      ABitmap.Free;
    end;
  end
end;

procedure TdxRibbonQuickAccessPainter.DrawGroupButtonControl(
  ADrawParams: TdxBarButtonLikeControlDrawParams; const ARect: TRect);
var
  R: TRect;
begin
  Skin.DrawBackground(ADrawParams.Canvas.Handle, ARect,
    DXBAR_QUICKACCESSGROUPBUTTON, GetButtonPartState(ADrawParams, bcpButton));
  R := cxRectContent(ARect, Skin.GetContentOffsets(DXBAR_QUICKACCESSGROUPBUTTON));
  with ADrawParams do
    DrawGlyph(BarItemControl, Canvas.Handle, R, R, ptHorz, False, False, False,
      False, False, True, False, False);
end;

procedure TdxRibbonQuickAccessPainter.DrawToolbarContentPart(
  ABarControl: TdxBarControl; ACanvas: TcxCanvas);
var
  AViewInfo: TdxRibbonViewInfo;
begin
  AViewInfo := Ribbon.ViewInfo;
  ACanvas.SaveDC;
  try
    if AViewInfo.UseGlass and AViewInfo.IsQATAtNonClientArea then
      FillRect(ACanvas.Handle, ABarControl.ClientRect, GetStockObject(BLACK_BRUSH));
    ACanvas.WindowOrg := dxMapWindowPoint(ABarControl.Handle, Ribbon.Handle, ACanvas.WindowOrg);
    if AViewInfo.IsQATAtNonClientArea and Assigned(Ribbon.FormCaptionHelper) then
      Ribbon.FormCaptionHelper.UpdateCaptionArea(ACanvas)
    else
    begin
      AViewInfo.Painter.DrawQuickAccessToolbar(ACanvas,
        AViewInfo.QuickAccessToolbarBounds, True);
    end;
  finally
    ACanvas.RestoreDC;
  end;
end;

function TdxRibbonQuickAccessPainter.MarkButtonWidth: Integer;
begin
  Result := ((Ribbon.GetGroupRowHeight + 2) div 2) or 1;
  dxAdjustToTouchableSize(Result);
end;

function TdxRibbonQuickAccessPainter.GetToolbarContentOffsets(
  ABar: TdxBar; ADockingStyle: TdxBarDockingStyle; AHasSizeGrip: Boolean): TRect;
begin
  Result := cxEmptyRect;
end;

function TdxRibbonQuickAccessPainter.MarkButtonOffset: Integer;
begin
  Result := Ribbon.ColorScheme.GetQuickAccessToolbarMarkButtonOffset(
    Ribbon.ApplicationButtonViewInfo.IsVisible,
    Ribbon.QuickAccessToolbar.Position = qtpBelowRibbon);
end;

function TdxRibbonQuickAccessPainter.MarkSizeX(ABarControl: TdxBarControl): Integer;
begin
  Result := MarkButtonWidth + MarkButtonOffset;
end;

{ TdxRibbonQuickAccessDockControl }

constructor TdxRibbonQuickAccessDockControl.Create(AOwner: TdxCustomRibbon);
begin
  inherited Create(nil);
  FRibbon := AOwner;
  FPainter := TdxRibbonQuickAccessPainter.Create(TdxNativeUInt(Ribbon));
  Parent := AOwner;
  AllowDocking := False;
  Align := dalNone;
end;

destructor TdxRibbonQuickAccessDockControl.Destroy;
begin
  FPainter.Free;
  inherited Destroy;
end;

procedure TdxRibbonQuickAccessDockControl.CalcLayout;
begin
  Ribbon.Changed;
  inherited CalcLayout;
end;

function TdxRibbonQuickAccessDockControl.GetDockedBarControlClass: TdxBarControlClass;
begin
  Result := TdxRibbonQuickAccessBarControl;
end;

function TdxRibbonQuickAccessDockControl.GetPainter: TdxBarPainter;
begin
  Result := FPainter;
end;

procedure TdxRibbonQuickAccessDockControl.ShowCustomizePopup;
begin
  // do nothing
end;

procedure TdxRibbonQuickAccessDockControl.VisibleChanged;
begin
  with Ribbon do
  begin
    if not IsDestroying and IsBarManagerValid then
      Changed;
  end;
end;

{ TdxRibbonQuickAccessBarControlDesignHelper }

class procedure TdxRibbonQuickAccessBarControlDesignHelper.GetEditors(AEditors: TList);
begin
  inherited GetEditors(AEditors);
  AEditors.Add(TdxAddGroupButtonEditor);
end;

class function TdxRibbonQuickAccessBarControlDesignHelper.GetForbiddenActions: TdxBarCustomizationActions;
begin
  Result := inherited GetForbiddenActions + [caChangeBeginGroup];
end;

{ TdxRibbonQuickAccessPopupBarControl }

destructor TdxRibbonQuickAccessPopupBarControl.Destroy;
begin
  FreeAndNil(FPainter);
  IsActive := False;
  inherited Destroy;
end;

procedure TdxRibbonQuickAccessPopupBarControl.CloseUp;
var
  AAccessibilityHelper: TdxBarControlMarkAccessibilityHelper;
  AReason: TdxBarCloseUpReason;
begin
  AAccessibilityHelper := TdxBarControlMarkAccessibilityHelper(QuickAccessBarControl.MarkIAccessibilityHelper.GetHelper);
  AReason := CloseUpReason;
  inherited CloseUp;
  AAccessibilityHelper.CloseUpHandler(AReason);
end;

procedure TdxRibbonQuickAccessPopupBarControl.Popup(const AOwnerRect: TRect);
var
  R: TRect;
begin
  inherited Popup(AOwnerRect);
  if QuickAccessBarControl.AllItemsVisible then
  begin
    SetWindowRgn(Handle, CreateRectRgnIndirect(cxEmptyRect), True);

    R := TdxBarAccessibilityHelperAccess(QuickAccessBarControl.MarkIAccessibilityHelper.GetHelper).GetScreenBounds(cxAccessibleObjectSelfID);
    R.TopLeft := ScreenToClient(R.TopLeft);
    R.BottomRight := ScreenToClient(R.BottomRight);
    GetMarkLink.ItemRect := R;

    GetMarkSubItem.DropDown(not BarNavigationController.NavigationMode);
  end;
end;

procedure TdxRibbonQuickAccessPopupBarControl.InitializeForDock(ABar: TdxBar);
begin
  inherited;
  FPainter := TdxRibbonQuickAccessPopupPainter.Create(TdxNativeUInt(Ribbon));
  DoubleBuffered := True;
end;

function TdxRibbonQuickAccessPopupBarControl.GetClientOffset: TRect;
begin
  Result := cxRect(3, 3, 3, 3);
end;

function TdxRibbonQuickAccessPopupBarControl.GetPainter: TdxBarPainter;
begin
  Result := FPainter;
end;

function TdxRibbonQuickAccessPopupBarControl.GetRibbon: TdxCustomRibbon;
begin
  Result := QuickAccessBarControl.Ribbon;
end;

function TdxRibbonQuickAccessPopupBarControl.GetPopupSize: TSize;
begin
  Result := GetSize(MaxInt);
end;

function TdxRibbonQuickAccessPopupBarControl.HasShadow: Boolean;
begin
  Result := not QuickAccessBarControl.AllItemsVisible;
end;

function TdxRibbonQuickAccessPopupBarControl.IsPopup: Boolean;
begin
  Result := True;
end;

function TdxRibbonQuickAccessPopupBarControl.GetQuickAccessBarControl: TdxRibbonQuickAccessBarControl;
begin
  if ParentBar <> nil then
    Result := TdxRibbonQuickAccessBarControl(ParentBar)
  else
    Result := TdxRibbonQuickAccessBarControl(Bar.Control);
end;

function TdxRibbonQuickAccessPopupBarControl.GetMarkLink: TdxBarItemLink;
begin
  Result := ItemLinks[ItemLinks.Count - 1];
end;

function TdxRibbonQuickAccessPopupBarControl.GetMarkSubItem: TCustomdxBarSubItem;
begin
  Result := TCustomdxBarSubItem(GetMarkLink.Item);
end;

{ TdxRibbonQuickAccessPopupPainter }

function TdxRibbonQuickAccessPopupPainter.MarkButtonOffset: Integer;
begin
  Result := 0;
end;

function TdxRibbonQuickAccessPopupPainter.MarkSizeX(ABarControl: TdxBarControl): Integer;
begin
  Result := 0;
end;

procedure TdxRibbonQuickAccessPopupPainter.DrawQuickAccessPopupSubItem(
  DC: HDC; const ARect: TRect; AState: Integer);
begin
  if AState <> DXBAR_NORMAL then
    Skin.DrawBackground(DC, ARect, DXBAR_SMALLBUTTON, AState);
  if AState = DXBAR_ACTIVE then
    AState := DXBAR_HOT;
  Skin.DrawBackground(DC, ARect, DXBAR_MARKARROW, AState);
end;

procedure TdxRibbonQuickAccessPopupPainter.DrawToolbarContentPart(
  ABarControl: TdxBarControl; ACanvas: TcxCanvas);
begin
  Ribbon.ColorScheme.DrawQuickAccessToolbarPopup(ACanvas.Handle,
    ABarControl.ClientRect);
end;

{ TdxRibbonQuickAccessPopupSubItem }

function TdxRibbonQuickAccessPopupSubItem.CreateBarControl: TCustomdxBarControl;
begin
  Result := TdxRibbonQuickAccessPopupSubMenuControl.Create(BarManager);
end;

{ TdxRibbonQuickAccessPopupSubMenuControl }

procedure TdxRibbonQuickAccessPopupSubMenuControl.ShowPopup(AItem: TdxBarItemControl);
begin
// do nothing
end;

{ TdxRibbonQuickAccessPopupSubItemControl }

procedure TdxRibbonQuickAccessPopupSubItemControl.DoCloseUp(AHadSubMenuControl: Boolean);
var
  ACloseUpReason: TdxBarCloseUpReason;
  AQATBarControl: TdxRibbonQuickAccessBarControl;
begin
  if AHadSubMenuControl then
  begin
    ACloseUpReason := TdxBarSubMenuControlAccess(Item.ItemLinks.BarControl).CloseUpReason;
    inherited;
    AQATBarControl := TdxRibbonQuickAccessPopupBarControl(Parent).QuickAccessBarControl;
    if ACloseUpReason = bcrEscape then
    begin
      if AQATBarControl.AllItemsVisible then
      begin
        AQATBarControl.MarkState := msNone;
        if BarNavigationController.NavigationMode then
          AQATBarControl.MarkIAccessibilityHelper.Select(False);
      end;
    end
    else
      if (BarNavigationController.AssignedSelectedObject <> nil) and
        (BarNavigationController.AssignedSelectedObject.GetHelper = AQATBarControl.MarkIAccessibilityHelper.GetHelper) then
          AQATBarControl.MarkIAccessibilityHelper.Unselect(nil);
  end
  else
    inherited;
end;

procedure TdxRibbonQuickAccessPopupSubItemControl.DoPaint(ARect: TRect; PaintType: TdxBarPaintType);

  function GetState: Integer;
  begin
    if DrawParams.DroppedDown then
      Result := DXBAR_PRESSED
    else
      if DrawSelected then
        Result := DXBAR_ACTIVE
      else
        Result := DXBAR_NORMAL;
  end;

begin
  TdxRibbonQuickAccessPopupPainter(Painter).DrawQuickAccessPopupSubItem(Canvas.Handle, ARect, GetState);
end;

function TdxRibbonQuickAccessPopupSubItemControl.GetDefaultWidth: Integer;
begin
  Result := TdxRibbonQuickAccessPopupPainter(Painter).MarkButtonWidth;
end;

{ TdxRibbonQuickAccessPopupSubItemButton }

procedure TdxRibbonQuickAccessPopupSubItemButton.DoClick;
begin
  TdxBarItemLink(Tag).Visible := Down;
end;

{ TdxRibbonGroupBarControl }

destructor TdxRibbonGroupBarControl.Destroy;
begin
  dxFader.Remove(Self);
  inherited Destroy;
end;

procedure TdxRibbonGroupBarControl.CloseUp;
var
  AAccessibilityHelper: TdxRibbonGroupBarControlAccessibilityHelper;
  AReason: TdxBarCloseUpReason;
begin
  if dxBarGetParentPopupWindow(Self, False) <> nil then
  begin
    TdxRibbonTabAccessibilityHelper(Group.Tab.IAccessibilityHelper.GetHelper).CloseUpHandler(CloseUpReason);
    TdxRibbonTabGroupsPopupWindow(DockControl.Parent.Parent).CloseUp;
  end
  else
  begin
    AAccessibilityHelper := TdxRibbonGroupBarControlAccessibilityHelper(ParentBar.IAccessibilityHelper.GetHelper);
    AReason := CloseUpReason;
    inherited CloseUp;
    AAccessibilityHelper.CloseUpHandler(AReason);
  end;
end;

procedure TdxRibbonGroupBarControl.InitializeForDock(ABar: TdxBar);

  function GetGroup: TdxRibbonTabGroup;
  var
    ATab: TdxRibbonTab;
    I: Integer;
  begin
    Result := nil;
    ATab := TdxRibbonGroupsDockControl(Bar.DockControl).Tab;
    for I := 0 to ATab.Groups.Count - 1 do
      if ATab.Groups[I].ToolBar = ABar then
      begin
        Result := ATab.Groups[I];
        Break;
      end;
  end;

begin
  inherited;
  FGroup := GetGroup;
  FRibbon := FGroup.Tab.Ribbon;
end;

function TdxRibbonGroupBarControl.FadingCanFade: Boolean;
begin
  Result := HandleAllocated and not (csDestroying in ComponentState) and Ribbon.CanFade;
end;

procedure TdxRibbonGroupBarControl.FadingDrawFadeImage;
begin
  if HandleAllocated then
    RedrawWindow(Handle, nil, 0, RDW_INVALIDATE or RDW_FRAME);
end;

procedure TdxRibbonGroupBarControl.FadingGetFadingImages(
  out AFadeOutImage, AFadeInImage: TcxBitmap);

  function GetGroupViewOrg: TPoint;
  var
    R: TRect;
  begin
    R := WindowRect;
    Dec(R.Left, ClientOrigin.X);
    Dec(R.Top, ClientOrigin.Y);
    Result := R.TopLeft;
  end;

  procedure Draw(ACanvas: TcxCanvas; AState: TdxBarViewState);
  const
    CollapsedStateMap: array[TdxBarViewState] of Integer =
      (DXBAR_NORMAL, DXBAR_HOT);
  var
    APrevViewState: TdxBarViewState;
  begin
    APrevViewState := FViewState;
    try
      FViewState := AState;
      PaintGroupBackground(ACanvas);
      ACanvas.WindowOrg := GetGroupViewOrg;
      ACanvas.SaveClipRegion;
      try
        ACanvas.SetClipRegion(TcxRegion.Create(ClientRect), roSet);
        if Collapsed then
          Ribbon.GroupsPainter.DrawCollapsedToolbarBackgroundPart(Self,
            ACanvas, CollapsedStateMap[AState])
        else
          Ribbon.GroupsPainter.DrawToolbarContentPart(Self, ACanvas);
      finally
        ACanvas.RestoreClipRegion;
        ACanvas.WindowOrg := cxNullPoint;
      end;
    finally
      FViewState := APrevViewState;
    end;
  end;

begin
  AFadeInImage := TcxBitmap32.CreateSize(BoundsRect, True);
  AFadeOutImage := TcxBitmap32.CreateSize(BoundsRect, True);
  Draw(AFadeInImage.cxCanvas, bvsHot);
  Draw(AFadeOutImage.cxCanvas, bvsNormal);
end;

procedure TdxRibbonGroupBarControl.AdjustHintWindowPosition(var APos: TPoint;
  const ABoundsRect: TRect; AHeight: Integer);
const
  HintIndent = 2;
begin
  APos.X := ABoundsRect.Left;
  APos.Y := Ribbon.ClientToScreen(cxPoint(0, Ribbon.Height)).Y;
  APos.Y := Max(APos.Y, ClientToScreen(cxPoint(0, Height + HintIndent)).Y);
  if GetDesktopWorkArea(APos).Bottom - APos.Y < AHeight then
  begin
    APos.Y := Ribbon.ClientToScreen(cxNullPoint).Y - AHeight - HintIndent;
    APos.Y := Min(APos.Y, ClientToScreen(cxNullPoint).Y - AHeight - 2 * HintIndent);
  end;
end;

procedure TdxRibbonGroupBarControl.CalcLayout;
begin
  if Ribbon.CanFade then
    dxFader.Clear;
end;

function TdxRibbonGroupBarControl.CanProcessShortCut: Boolean;
begin
  Result := True;
end;

procedure TdxRibbonGroupBarControl.CaptionChanged;
begin
  inherited CaptionChanged;
  RebuildBar;
end;

procedure TdxRibbonGroupBarControl.DoHideAll(AReason: TdxBarCloseUpReason);
var
  ALinkSelf: TcxObjectLink;
begin
  ALinkSelf := cxAddObjectLink(Self);
  try
    inherited;
    if (ALinkSelf.Ref <> nil) and (dxBarGetParentPopupWindow(Self, True) <> nil) then
      CloseUp;
  finally
    cxRemoveObjectLink(ALinkSelf);
  end;
end;

procedure TdxRibbonGroupBarControl.DoNCPaint(DC: HDC);
begin
  DoTransparentNCPaint(DC)
end;

procedure TdxRibbonGroupBarControl.DoOpaqueNCPaint(DC: HDC);
begin
  if not cxRectIsEqual(NCRect, ClientRect) then
  begin
    cxPaintCanvas.BeginPaint(DC);
    try
      PaintDesignObjects(cxPaintCanvas);
      if not Collapsed then
      begin
        PaintGroupBackground(cxPaintCanvas);
        PaintGroupCaptionText(cxPaintCanvas);
        DrawCaptionButtons(cxPaintCanvas);
      end;
    finally
      cxPaintCanvas.EndPaint;
    end;
  end;
end;

procedure TdxRibbonGroupBarControl.DoTransparentNCPaint(DC: HDC);
var
  P: TPoint;
  R, BR: TRect;
  AIndex: Integer;
  B: TcxBitmap32;
begin
  B := TcxBitmap32.CreateSize(WindowRect, True);
  try
    AIndex := SaveDC(DC);
    R := ClientRect;
    BR := Painter.GetToolbarContentOffsets(Bar, dsNone, False);
    OffsetRect(R, BR.Left, BR.Top);
    ExcludeClipRect(DC, R.Left, R.Top, R.Right, R.Bottom);
    if IsPopup then
    begin
      R := NCRect;
      DrawGroupsArea(B.cxCanvas, R);
    end
    else
    begin
      P := dxMapWindowPoint(Handle, Ribbon.FGroupsDockControlSite.Handle, cxNullPoint);
      R := cxGetWindowRect(Ribbon.FGroupsDockControlSite);
      OffsetRect(R, -R.Left, -R.Top);
      Dec(P.X, BR.Left);
      Dec(P.Y, BR.Top);
      SetWindowOrgEx(B.Canvas.Handle, P.X, P.Y, nil);
      DrawGroupsArea(B.cxCanvas, R);
      SetWindowOrgEx(B.Canvas.Handle, 0, 0, nil);
      R := NCRect;
    end;
    DoOpaqueNCPaint(B.Canvas.Handle);
    cxBitBlt(DC, B.Canvas.Handle, R, cxNullPoint, SRCCOPY);
    RestoreDC(DC, AIndex);
  finally
    B.Free;
  end;
end;

procedure TdxRibbonGroupBarControl.DrawBarParentBackground(ACanvas: TcxCanvas);
var
  APoint: TPoint;
  ARect, AOffsets: TRect;
  AHandle: HWND;
begin
  ACanvas.SaveState;
  if IsPopup then
  begin
    ARect := WindowRect;
    OffsetRect(ARect, -ARect.Left, -ARect.Top);
    AOffsets := Painter.GetToolbarContentOffsets(Bar, dsNone, False);
    OffsetRect(ARect, -AOffsets.Left, -AOffsets.Top);
  end
  else
  begin
    AHandle := Ribbon.FGroupsDockControlSite.Handle;
    APoint := dxMapWindowPoint(Handle, AHandle, cxNullPoint);
    Windows.GetClientRect(AHandle, ARect);
    OffsetRect(ARect, -APoint.X, -APoint.Y);
  end;
  DrawGroupsArea(ACanvas, ARect);
  ACanvas.RestoreState;
end;

procedure TdxRibbonGroupBarControl.DrawContentBackground;

  function DrawFadeContentBackground: Boolean;
  var
    R: TRect;
  begin
    R := WindowRect;
    OffsetRect(R, -R.Left, -R.Top);
    Dec(R.Top, ClientBounds.Top);
    Dec(R.Left, ClientBounds.Left);
    Result := dxFader.DrawFadeImage(Self, Canvas.Handle, R);
  end;

begin
  if not DrawFadeContentBackground then
    inherited DrawContentBackground;
end;

procedure TdxRibbonGroupBarControl.DrawGroupsArea(ACanvas: TcxCanvas; const ABounds: TRect);
begin
  Ribbon.ViewInfo.Painter.DrawGroupsArea(ACanvas, ABounds, IsAllowContextPaint, IsPopup);
end;

function TdxRibbonGroupBarControl.IsAllowContextPaint: Boolean;
begin
  Result := True;
end;

procedure TdxRibbonGroupBarControl.DoPaint;
var
  APrevWindowOrg: TPoint;
begin
  DrawBarParentBackground(Canvas);
  if Collapsed then
    TdxRibbonBarPainter(Painter).DrawToolbarContentPart(Self, Canvas)
  else
    inherited DoPaint;

  if IsDesignObjectsOnClientArea then
  begin
    APrevWindowOrg := Canvas.WindowOrg;
    try
      Canvas.WindowOrg := NCOffset;
      PaintDesignObjects(Canvas);
    finally
      Canvas.WindowOrg := APrevWindowOrg;
    end;
  end;
end;

procedure TdxRibbonGroupBarControl.DoBarMouseDown(Button: TMouseButton; Shift: TShiftState;
  const APoint: TPoint; AItemControl: TdxBarItemControl; APointInClientRect: Boolean);
begin
  if cxRectPtIn(GroupDesignRect, GetWindowPoint(APoint)) then
  begin
    Group.DesignSelectionHelper.SelectComponent;
    if Button = mbRight then
      ShowGroupDesignMenu;
  end
  else
    inherited DoBarMouseDown(Button, Shift, APoint, AItemControl, APointInClientRect);
end;

function TdxRibbonGroupBarControl.ClickAtHeader: Boolean;
begin
  Result := Collapsed and cxRectPtIn(WindowRect, GetMouseCursorPos) or inherited ClickAtHeader;
end;

function TdxRibbonGroupBarControl.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonGroupBarControlAccessibilityHelper;
end;

function TdxRibbonGroupBarControl.GetCaption: TCaption;
begin
  Result := Group.Caption;
end;

function TdxRibbonGroupBarControl.GetMarkDrawState: TdxBarMarkState;
begin
  if IAccessibilityHelper.IsSelected then
    Result := msSelected
  else
    Result := MarkState;
end;

function TdxRibbonGroupBarControl.GetMoreButtonsHint: string;
begin
  Result := Caption;
end;

function TdxRibbonGroupBarControl.GetQuickControlClass: TdxBarPopupControlClass;
begin
  Result := TdxRibbonCollapsedGroupPopupBarControl;
end;

function TdxRibbonGroupBarControl.GetRibbon: TdxCustomRibbon;
begin
  Result := FRibbon;
end;

function TdxRibbonGroupBarControl.GetViewInfoClass: TCustomdxBarControlViewInfoClass;
begin
  Result := TdxRibbonGroupBarControlViewInfo;
end;

procedure TdxRibbonGroupBarControl.GlyphChanged;
begin
  Ribbon.QuickAccessToolbar.UpdateGroupButton(Bar, False);
end;

function TdxRibbonGroupBarControl.HasCaptionButtons: Boolean;
begin
  Result := not Collapsed and inherited HasCaptionButtons;
end;

procedure TdxRibbonGroupBarControl.InitQuickControl(AQuickControl: TdxBarPopupControl);
begin
// do nothing
end;

procedure TdxRibbonGroupBarControl.MakeItemControlFullyVisible(
  AItemControl: TdxBarItemControl);
var
  R: TRect;
begin
  if DockControl = nil then
    Exit;
  R := AItemControl.ViewInfo.Bounds;
  R.TopLeft := DockControl.ScreenToClient(ClientToScreen(R.TopLeft));
  R.BottomRight := DockControl.ScreenToClient(ClientToScreen(R.BottomRight));
  TdxRibbonGroupsDockControl(DockControl).MakeRectFullyVisible(R);
end;

function TdxRibbonGroupBarControl.MarkExists: Boolean;
begin
  Result := Collapsed;
end;

procedure TdxRibbonGroupBarControl.ViewStateChanged(APrevValue: TdxBarViewState);
begin
  if Ribbon.CanFade then
  begin
    if ViewState = bvsHot then
      dxFader.FadeIn(Self)
    else
      if MarkState <> msPressed then
        dxFader.FadeOut(Self);
  end;
  FullInvalidate;
end;

procedure TdxRibbonGroupBarControl.UpdateCaptionButton(ACaptionButton: TdxBarCaptionButton);
var
  I: Integer;
  AButtonRect, AInvalidateRect: TRect;
  AButtonWidth: Integer;
begin
  if ACaptionButton = nil then
  begin
    AButtonRect := GroupCaptionRect;
    AButtonWidth := cxRectHeight(AButtonRect) + 1;
    AButtonRect.Left := AButtonRect.Right - AButtonWidth;
    for I := 0 to Bar.CaptionButtons.Count - 1 do
    begin
      Bar.CaptionButtons[I].Rect := AButtonRect;
      OffsetRect(AButtonRect, -AButtonWidth, 0);
    end;
    AInvalidateRect := CaptionButtons.Rect;
  end
  else
    AInvalidateRect := ACaptionButton.Rect;
  if HandleAllocated and IsWindowVisible(Handle) then
    InvalidateNCRect(AInvalidateRect);
end;

procedure TdxRibbonGroupBarControl.WindowPosChanged(var Message: TWMWindowPosMsg);
begin
  inherited WindowPosChanged(Message);
  if Message.WindowPos^.flags and SWP_NOSIZE = 0 then
  begin
    if HasCaptionButtons then
      UpdateCaptionButton(nil);
  end;
end;

procedure TdxRibbonGroupBarControl.DesignMenuClick(Sender: TObject);
begin
  case TdxBarButton(Sender).Tag of
    0: Ribbon.DesignAddTabGroup(Group.Tab, False);
    1: Ribbon.DesignAddTabGroup(Group.Tab, True);
    2: BarDesignController.DeleteSelectedObjects(True, True)
  end;
end;

procedure TdxRibbonGroupBarControl.DrawCaptionButtons(ACanvas: TcxCanvas);

  procedure DrawGlyph(AButton: TdxBarCaptionButton);
  const
    ADefaultGlyphSize = 12; // same as dxRibbonSkins.LaunchButtonGlyphSize
  var
    AGlyphRectSize: Integer;
    AGlyphRect: TRect;
    AGlyphRatio: Integer;
  begin
    AGlyphRectSize := Min(cxRectWidth(AButton.Rect), cxRectHeight(AButton.Rect)) - 2 {BorderSize} * 2;
    AGlyphRatio := Round(Max(1, AGlyphRectSize / ADefaultGlyphSize));
    AGlyphRectSize := ADefaultGlyphSize * AGlyphRatio;
    if AGlyphRatio > 1 then
      Dec(AGlyphRectSize, AGlyphRatio); // GDI+ feature
    AGlyphRect := cxRectCenter(AButton.Rect, AGlyphRectSize, AGlyphRectSize);
    if (AButton.Glyph = nil) or AButton.Glyph.Empty then
    begin
      OffsetRect(AGlyphRect, 1, 1); // because shadow
      Ribbon.GroupsPainter.Skin.DrawBackground(ACanvas.Handle,
        AGlyphRect, DXBAR_LAUNCHBUTTONDEFAULTGLYPH, AButton.State);
    end
    else
      TransparentDraw(ACanvas.Handle, AGlyphRect, AButton.Glyph, AButton.Enabled);
  end;

var
  I: Integer;
  AButton: TdxBarCaptionButton;
begin
  if CaptionButtons.Count = 0 then
    Exit;

  ACanvas.SetClipRegion(TcxRegion.Create(CaptionButtons.Rect), roSet);
  for I := 0 to CaptionButtons.Count - 1 do
  begin
    AButton := CaptionButtons[I];
    Ribbon.GroupsPainter.Skin.DrawBackground(ACanvas.Handle,
      AButton.Rect, DXBAR_LAUNCHBUTTONBACKGROUND, AButton.State);
    DrawGlyph(AButton);
  end;
end;

procedure TdxRibbonGroupBarControl.DrawSelectedFrame(DC: HDC; const R: TRect);

  procedure DrawLine(X1, Y1, X2, Y2: Integer);
  begin
    DrawRect(DC, cxRect(X1, Y1, X2, Y2), clBlack, True);
  end;

begin
  DrawLine(R.Left, R.Top, R.Right, R.Top + dxRibbonGroupSelectionFrameSize);
  DrawLine(R.Left, R.Bottom - dxRibbonGroupSelectionFrameSize, R.Right, R.Bottom);
  DrawLine(R.Left, R.Top, R.Left + dxRibbonGroupSelectionFrameSize, R.Bottom);
  DrawLine(R.Right - dxRibbonGroupSelectionFrameSize, R.Top, R.Right, R.Bottom);
end;

function TdxRibbonGroupBarControl.GetCollapsed: Boolean;
begin
  Result := ViewInfo.Collapsed;
end;

function TdxRibbonGroupBarControl.GetFadingOptions: TdxFadingOptions;
begin
  Result := Ribbon.OptionsFading.TabGroups;
end;

function TdxRibbonGroupBarControl.GetGroupCaptionRect: TRect;
begin
  Result := Ribbon.SkinGetCaptionRect(NCRect, Ribbon.GroupsPainter.GetToolbarSkinPart(Self));
end;

function TdxRibbonGroupBarControl.GetGroupDesignRect: TRect;
const
  MarkSize = 14;
begin
  if csDesigning in ComponentState then
  begin
    Result := WindowRect;
    OffsetRect(Result, -(Result.Left - 3), -(Result.Top + 3));
    Result.Top := Result.Bottom - MarkSize;
    Result.Right := Result.Left + MarkSize;
  end
  else
    Result := cxEmptyRect;
end;

function TdxRibbonGroupBarControl.GetIsDesignObjectsOnClientArea: Boolean;
var
  AClientBounds: TRect;
begin
  Result := csDesigning in ComponentState;
  if Result then
  begin
    AClientBounds := ClientBounds;
    Result := cxRectIntersect(AClientBounds, GroupDesignRect) or
      (AClientBounds.Left < dxRibbonGroupSelectionFrameSize) or
      (AClientBounds.Top < dxRibbonGroupSelectionFrameSize) or
      (NCRect.Right - AClientBounds.Right < dxRibbonGroupSelectionFrameSize) or
      (NCRect.Bottom - AClientBounds.Bottom < dxRibbonGroupSelectionFrameSize);
  end;
end;

function TdxRibbonGroupBarControl.GetIsComponentSelected: Boolean;
begin
  Result := Group.DesignSelectionHelper.IsComponentSelected;
end;

function TdxRibbonGroupBarControl.GetViewInfo: TdxRibbonGroupBarControlViewInfo;
begin
  Result := TdxRibbonGroupBarControlViewInfo(FViewInfo);
end;

procedure TdxRibbonGroupBarControl.PaintGroupBackground(ACanvas: TcxCanvas);
begin
  ACanvas.ExcludeClipRect(ClientBounds);
  if not dxFader.DrawFadeImage(Self, ACanvas.Handle, NCRect) then
    Ribbon.GroupsPainter.DrawToolbarNonContentPart(Self, ACanvas.Handle);
end;

procedure TdxRibbonGroupBarControl.PaintGroupCaptionText(ACanvas: TcxCanvas);
begin
  Ribbon.GroupsPainter.DrawToolbarNonContentPartCaption(Self, ACanvas.Handle);
end;

procedure TdxRibbonGroupBarControl.PaintDesignObjects(ACanvas: TcxCanvas);
begin
  cxDrawDesignRect(ACanvas, GetGroupDesignRect, IsComponentSelected);
  if IsComponentSelected then
    DrawSelectedFrame(ACanvas.Handle, NCRect);
end;

procedure TdxRibbonGroupBarControl.InitDesignMenu(AItemLinks: TdxBarItemLinks);
begin
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONADDEMPTYGROUP), DesignMenuClick, 0);
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONADDGROUPWITHTOOLBAR), DesignMenuClick, 1);
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONDELETEGROUP), DesignMenuClick, 2, True);
end;

procedure TdxRibbonGroupBarControl.ShowGroupDesignMenu;
begin
  BarDesignController.ShowCustomCustomizePopup(BarManager, InitDesignMenu, Painter);
end;

procedure TdxRibbonGroupBarControl.WMGestureNotify(var Message: TWMGestureNotify);
begin
  Message.Result := DefWindowProc(Handle, Message.Msg, Message.Unused, LPARAM(Message.NotifyStruct));
end;

procedure TdxRibbonGroupBarControl.WMNCHitTest(var Message: TWMNCHitTest);
begin
  if Collapsed then
  begin
    Message.Result := HTCLIENT;
    HitTest := HTCLIENT;
  end
  else
    inherited;
end;

//don't use Delphi 2007 WM_PAINT handler
procedure TdxRibbonGroupBarControl.WMPaint(var Message: TWMPaint);
var
  DC, MemDC: HDC;
  MemBitmap, OldBitmap: HBITMAP;
  PS: TPaintStruct;
begin
  if not FDoubleBuffered or (Message.DC <> 0) then
  begin
    if not (csCustomPaint in ControlState) and (ControlCount = 0) then
      inherited
    else
      PaintHandler(Message);
  end
  else
  begin
    DC := GetDC(0);
    MemBitmap := CreateCompatibleBitmap(DC, ClientRect.Right, ClientRect.Bottom);
    ReleaseDC(0, DC);
    MemDC := CreateCompatibleDC(0);
    OldBitmap := SelectObject(MemDC, MemBitmap);
    try
      DC := BeginPaint(Handle, PS);
      Perform(WM_ERASEBKGND, MemDC, MemDC);
      Message.DC := MemDC;
      WMPaint(Message);
      Message.DC := 0;
      BitBlt(DC, 0, 0, ClientRect.Right, ClientRect.Bottom, MemDC, 0, 0, SRCCOPY);
      EndPaint(Handle, PS);
    finally
      SelectObject(MemDC, OldBitmap);
      DeleteDC(MemDC);
      DeleteObject(MemBitmap);
    end;
  end;
end;

{$IFNDEF DELPHI14}
procedure TdxRibbonGroupBarControl.WMTabletQuerySystemGestureStatus(var Message: TMessage);
begin
  Message.Result := TABLET_DISABLE_FLICKS;
end;
{$ENDIF}

{ TdxRibbonGroupBarControlViewInfo }

procedure TdxRibbonGroupBarControlViewInfo.Calculate;
var
  I: Integer;
begin
  FNonContentAreaSize := GetNonContentAreaSize;
  if Collapsed then
  begin
    ContentSize := cxSize(Ribbon.GroupsPainter.GetCollapsedGroupWidth(BarControl),
      Ribbon.GetGroupHeight);
    RemoveSeparatorInfos;
    for I := 0 to ItemControlCount - 1 do
      IdxBarItemControlViewInfo(ItemControlViewInfos[I]).SetBounds(cxEmptyRect);
  end
  else
    LayoutCalculator.CalcLayout(CreateCalculateHelper);
end;

procedure TdxRibbonGroupBarControlViewInfo.AfterCalculate;
begin
  FKeyTipsBaseLinePositions.Calculated := False;
  FLayoutCalculator := nil;
  if FPrevCollapsedState <> FCollapsed then
  begin
    if BarControl.HandleAllocated then
      BarControl.FrameChanged;
  end;
  UpdateItemRects;
end;

procedure TdxRibbonGroupBarControlViewInfo.BeforeCalculate(ACollapsed: Boolean);
begin
  FPrevCollapsedState := Collapsed;
  Collapsed := ACollapsed;
  RecreateItemControlViewInfos;
  FLayoutCalculator := CreateLayoutCalculator;
  FLayoutCalculator.CalcInit(CreateCalculateHelper);
end;

function TdxRibbonGroupBarControlViewInfo.Reduce(AStage: TdxRibbonGroupsReduceStage;
  AUpToViewLevel: TdxBarItemRealViewLevel): Boolean;
begin
  Result := False;
  if BarControl.Group.Restriction <> rtgrNoExpand then
    case AStage of
      rgrsMultiColumnItemControlsColumnCount:
        Result := LayoutCalculator.DecreaseMultiColumnItemControlsColumnCount(CreateCalculateHelper);
      rgrsMultiColumnItemControlsCollapsing:
        Result := LayoutCalculator.CollapseMultiColumnItemControls(CreateCalculateHelper);
      rgrsItemControlsViewLevel:
        Result := LayoutCalculator.Reduce(CreateCalculateHelper, AUpToViewLevel);
    end;
  if (AStage = rgrsGroupsCollapsing) and (BarControl.Group.Restriction <> rtgrNoCollapse) then
  begin
    Collapsed := True;
    Calculate;
  end;
end;

procedure TdxRibbonGroupBarControlViewInfo.ReduceInit;
begin
  LayoutCalculator.ReduceInit(CreateCalculateHelper);
end;

procedure TdxRibbonGroupBarControlViewInfo.CalculateKeyTipsBaseLinePositions;
begin
  if not BarControl.HandleAllocated or not IsWindowVisible(BarControl.Handle) then
    raise EdxException.Create('');
  if not FKeyTipsBaseLinePositions.Calculated then
  begin
    DoCalculateKeyTipsBaseLinePositions;
    FKeyTipsBaseLinePositions.Calculated := True;
  end;
end;

procedure TdxRibbonGroupBarControlViewInfo.CheckGroupCollapsedStates;
begin
  if Collapsed <> FPrevCollapsedState then
  begin
    if Collapsed then
      BarControl.Group.Tab.Ribbon.DoTabGroupCollapsed(BarControl.Group.Tab, BarControl.Group)
    else
      BarControl.Group.Tab.Ribbon.DoTabGroupExpanded(BarControl.Group.Tab, BarControl.Group);
  end;
end;

function TdxRibbonGroupBarControlViewInfo.CreateLayoutCalculator: IdxRibbonGroupLayoutCalculator;
begin
  FGroupRowHeight := Ribbon.GetGroupRowHeight;
  Result := TdxRibbonGroupLayoutCalculator.Create(FGroupRowHeight, dxRibbonGroupRowCount);
end;

procedure TdxRibbonGroupBarControlViewInfo.DoCalculateKeyTipsBaseLinePositions;
begin
  SetLength(FKeyTipsBaseLinePositions.RowKeyTipsBaseLinePositions, dxRibbonGroupRowCount);
  FKeyTipsBaseLinePositions.RowKeyTipsBaseLinePositions[0] :=
    BarControl.ClientOrigin.Y - BarControl.WindowRect.Top;
  FKeyTipsBaseLinePositions.RowKeyTipsBaseLinePositions[2] := BarControl.GroupCaptionRect.Top;
  with FKeyTipsBaseLinePositions do
    RowKeyTipsBaseLinePositions[1] := (RowKeyTipsBaseLinePositions[0] + RowKeyTipsBaseLinePositions[2]) div 2;

  FKeyTipsBaseLinePositions.BottomKeyTipsBaseLinePosition :=
    BarControl.Height - Ribbon.SkinGetContentOffsets(DXBAR_COLLAPSEDTOOLBAR).Bottom;
end;

function TdxRibbonGroupBarControlViewInfo.GetNonContentAreaSize: TSize;
var
  R: TRect;
begin
  R := BarControl.Painter.GetToolbarContentOffsets(BarControl.Bar, dsNone, False);
  Result := cxSize(cxMarginsWidth(R), cxMarginsHeight(R));
end;

procedure TdxRibbonGroupBarControlViewInfo.RecreateItemControlViewInfos;

  function IsAllControlsCreated(AItemLinks: TdxBarItemLinks): Boolean;
  var
    I: Integer;
  begin
    Result := True;
    for I := 0 to AItemLinks.CanVisibleItemCount - 1 do
      Result := Result and (AItemLinks.CanVisibleItems[I].Control <> nil);
  end;

var
  AItemControl: TdxBarItemControl;
  AItemLinks: TdxBarItemLinks;
  I: Integer;
begin
  Clear;
  AItemLinks := BarControl.ItemLinks;
  if IsAllControlsCreated(AItemLinks) then
    for I := 0 to AItemLinks.CanVisibleItemCount - 1 do
    begin
      AItemControl := BarControl.ItemLinks.CanVisibleItems[I].Control;
      TdxBarItemControlAccess(AItemControl).LastInRow := I = AItemLinks.CanVisibleItemCount - 1;
      AddItemControlViewInfo(AItemControl.ViewInfo);
    end;
end;

procedure TdxRibbonGroupBarControlViewInfo.UpdateItemRects;

  function GetItemControlBounds(AIndex: Integer): TRect;
  begin
    if Collapsed then
      Result := cxEmptyRect
    else
      Result := ItemControlViewInfos[AIndex].Bounds;
  end;

var
  AItemLink: TdxBarItemLink;
  ANeedsInvalidateBarControl: Boolean;
  I: Integer;
begin
  TdxBarItemLinksAccess(BarControl.ItemLinks).BeginCalcItemRects;
  try
    ANeedsInvalidateBarControl := False;
    for I := 0 to ItemControlCount - 1 do
    begin
      AItemLink := ItemControlViewInfos[I].Control.ItemLink;
      ANeedsInvalidateBarControl := ANeedsInvalidateBarControl or not EqualRect(AItemLink.ItemRect, GetItemControlBounds(I));
      AItemLink.ItemRect := GetItemControlBounds(I);
    end;
  finally
    TdxBarItemLinksAccess(BarControl.ItemLinks).EndCalcItemRects;
  end;
  if ANeedsInvalidateBarControl and BarControl.HandleAllocated then
    InvalidateRect(BarControl.Handle, nil, False);
end;

function TdxRibbonGroupBarControlViewInfo.CreateCalculateHelper: IdxRibbonGroupViewInfo;
begin
  Result := TdxRibbonGroupBarControlViewInfoHelper.Create(Self);
end;

function TdxRibbonGroupBarControlViewInfo.GetBarControl: TdxRibbonGroupBarControl;
begin
  Result := FBarControl as TdxRibbonGroupBarControl;
end;

function TdxRibbonGroupBarControlViewInfo.GetBottomKeyTipsBaseLinePosition: Integer;
begin
  CalculateKeyTipsBaseLinePositions;
  Result := FKeyTipsBaseLinePositions.BottomKeyTipsBaseLinePosition +
    BarControl.WindowRect.Top;
end;

function TdxRibbonGroupBarControlViewInfo.GetRibbon: TdxCustomRibbon;
begin
  Result := BarControl.Ribbon;
end;

function TdxRibbonGroupBarControlViewInfo.GetRowKeyTipsBaseLinePosition(
  ARowIndex: Integer): Integer;
begin
  CalculateKeyTipsBaseLinePositions;
  if (ARowIndex < 0) or (ARowIndex > High(FKeyTipsBaseLinePositions.RowKeyTipsBaseLinePositions)) then
    raise EdxException.Create('');
  Result := FKeyTipsBaseLinePositions.RowKeyTipsBaseLinePositions[ARowIndex] +
    BarControl.WindowRect.Top;
end;

function TdxRibbonGroupBarControlViewInfo.GetSize: TSize;
begin
  Result := cxSize(FContentSize.cx + FNonContentAreaSize.cx,
    FContentSize.cy + FNonContentAreaSize.cy);
end;

{ TdxRibbonGroupBarControlDesignHelper }

class function TdxRibbonGroupBarControlDesignHelper.CanDynamicallyChangeViewLevels: Boolean;
begin
  Result := True;
end;

class function TdxRibbonGroupBarControlDesignHelper.GetForbiddenActions: TdxBarCustomizationActions;
begin
  Result := [caChangeButtonPaintStyle, caChangeRecentList];
end;

{ TdxRibbonCollapsedGroupPopupBarControl }

destructor TdxRibbonCollapsedGroupPopupBarControl.Destroy;
begin
  IsActive := False;
  inherited Destroy;
end;

procedure TdxRibbonCollapsedGroupPopupBarControl.Hide;
begin
  CloseUp;
end;

procedure TdxRibbonCollapsedGroupPopupBarControl.Popup(const AOwnerRect: TRect);
begin
  FAllowNCPaint := False;
  try
    inherited Popup(AOwnerRect);
  finally
    UpdateWindow(Handle);
    FAllowNCPaint := True;
    Perform(WM_NCPAINT, 1, 0);
  end;
end;

procedure TdxRibbonCollapsedGroupPopupBarControl.InitializeForPopup(AParentBarControl: TdxBarControl; ABar: TdxBar);
begin
  ABar.BarManager.Bars.BeginUpdate;
  try
    inherited;
    Bar.ItemLinks := ABar.ItemLinks;
    Bar.CaptionButtons := ABar.CaptionButtons;
  finally
    ABar.BarManager.Bars.EndUpdate;
  end;
  CreateControls;
  UpdateDoubleBuffered;
end;

function TdxRibbonCollapsedGroupPopupBarControl.AllowNCPaint: Boolean;
begin
  Result := FAllowNCPaint and inherited AllowNCPaint;
end;

procedure TdxRibbonCollapsedGroupPopupBarControl.DoBarMouseRightButtonDown(
  Shift: TShiftState; const APoint: TPoint; AItemControl: TdxBarItemControl;
  APrevSelectedControl: TdxBarItemControl; APointInClientRect: Boolean);
begin
  FocusItemControl(AItemControl);
  if CanShowPopupMenuOnMouseClick(True) then
    ShowPopup(AItemControl)
end;

function TdxRibbonCollapsedGroupPopupBarControl.GetCaption: TCaption;
begin
  Result := dxRibbonGetGroupCaption(MasterBar);
end;

function TdxRibbonCollapsedGroupPopupBarControl.GetPainter: TdxBarPainter;
begin
  Result := Ribbon.GroupsPainter;
end;

function TdxRibbonCollapsedGroupPopupBarControl.GetPopupSize: TSize;
begin
  HandleNeeded;
  ViewInfo.BeforeCalculate(False);
  try
    ViewInfo.Calculate;
  finally
    ViewInfo.AfterCalculate;
  end;
  Result := ViewInfo.GetSize;
end;

function TdxRibbonCollapsedGroupPopupBarControl.GetSizeForWidth(
  AStyle: TdxBarDockingStyle; AWidth: Integer): TSize;
begin
  Result := cxSize(ClientWidth, ClientHeight);
end;

function TdxRibbonCollapsedGroupPopupBarControl.IgnoreClickAreaWhenHidePopup: TRect;
begin
  Result := TdxRibbonGroupBarControl(ParentBar).WindowRect;
end;

function TdxRibbonCollapsedGroupPopupBarControl.IsPopup: Boolean;
begin
  Result := True;
end;

function TdxRibbonCollapsedGroupPopupBarControl.NeedHideOnNCMouseClick: Boolean;
begin
  Result := False;
end;

{ TdxRibbonTabGroup }

constructor TdxRibbonTabGroup.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FRestriction := rtgrNone;
  FDesignSelectionHelper := GetSelectableItem(TdxDesignSelectionHelper.Create(Ribbon, Self, Tab));
end;

destructor TdxRibbonTabGroup.Destroy;
begin
  CheckUndockToolbar;
  inherited Destroy;
  FDesignSelectionHelper := nil;
end;

function TdxRibbonTabGroup.IsMergeAllowed: Boolean;
begin
  Result := Visible and (MergeKind <> rmkNone) and not IsToolBarShared;
end;

procedure TdxRibbonTabGroup.Assign(Source: TPersistent);

  function IsInheritanceUpdating: Boolean;
  begin
    Result := (Tab <> nil) and (csUpdating in Tab.ComponentState);
  end;

  function GetSourceToolbar: TdxBar;
  begin
    if (TdxRibbonTabGroup(Source).Toolbar <> nil) and IsInheritanceUpdating then
      Result := Tab.Ribbon.BarManager.BarByComponentName(TdxRibbonTabGroup(Source).Toolbar.Name)
    else
      Result := TdxRibbonTabGroup(Source).Toolbar;
  end;

begin
  if Source is TdxRibbonTabGroup then
  begin
    Caption := TdxRibbonTabGroup(Source).Caption;
    Restriction := TdxRibbonTabGroup(Source).Restriction;
    AssignedValues := TdxRibbonTabGroup(Source).AssignedValues;
    MergeOrder := TdxRibbonTabGroup(Source).MergeOrder;
    MergeKind := TdxRibbonTabGroup(Source).MergeKind;
    ToolBar := GetSourceToolbar;
  end
  else
    inherited Assign(Source);
end;

procedure TdxRibbonTabGroup.DefineProperties(Filer: TFiler);

  function NeedWriteToolbarName: Boolean;
  var
    AAncestorToolbar: TdxBar;
  begin
    if Filer.Ancestor <> nil then
    begin
      AAncestorToolbar := TdxRibbonTabGroup(Filer.Ancestor).ToolBar;
      Result := (AAncestorToolbar = nil) and (Toolbar <> nil) or
        (AAncestorToolbar <> nil) and (ToolBar = nil) or
        (AAncestorToolbar <> nil) and (AAncestorToolbar.Name <> Toolbar.Name);
    end
    else
      Result := ToolBar <> nil;
  end;

begin
  inherited DefineProperties(Filer);
  Filer.DefineProperty('Caption', ReadCaption, WriteCaption, GetIsCaptionAssigned and (Caption = ''));
  Filer.DefineProperty('ToolbarName', ReadToolbarName, WriteToolbarName, NeedWriteToolbarName);
end;

procedure TdxRibbonTabGroup.DockToolbar(AToolbar: TdxBar);
var
  ADockControl: TdxRibbonGroupsDockControl;
begin
  if Tab.Active or not (AToolbar.DockControl is TdxRibbonGroupsDockControl) then
    RibbonDockToolBar(AToolbar, Tab.DockControl)
  else
  begin
    ADockControl := TdxRibbonGroupsDockControl(AToolbar.DockControl);
    if (ADockControl.Ribbon <> Ribbon) or not ADockControl.Tab.Active then
      RibbonDockToolBar(AToolbar, Tab.DockControl);
  end;
end;

function TdxRibbonTabGroup.IsMerged: Boolean;
begin
  Result := (ToolBar <> nil) and ToolBar.IsMerged;
end;

function TdxRibbonTabGroup.IsToolbarAcceptable(AToolbar: TdxBar): Boolean;
begin
  Result := (AToolbar = nil) or (Ribbon.BarManager <> nil) and (Ribbon.BarManager = AToolbar.BarManager);
end;

procedure TdxRibbonTabGroup.Merge(AGroup: TdxRibbonTabGroup;
  AMergeOptions: TdxRibbonMergeOptions = dxRibbonDefaultMergeOptions);
begin
  TdxRibbonMergeHelper.MergeToolbarContainers(Self, AGroup, rmoCanCreateNewGroup in AMergeOptions);
end;

procedure TdxRibbonTabGroup.ReadCaption(AReader: TReader);
begin
  Caption := AReader.ReadString;
end;

procedure TdxRibbonTabGroup.ReadToolbarName(AReader: TReader);
begin
  FLoadedToolbarName := AReader.ReadString;
end;

procedure TdxRibbonTabGroup.Unmerge(AGroup: TdxRibbonTabGroup = nil);
begin
  TdxRibbonMergeHelper.UnmergeToolbarContainers(Self, AGroup);
end;

procedure TdxRibbonTabGroup.UpdateBarManager(ABarManager: TdxBarManager);
begin
  if ToolBar <> nil then
    ToolBar.DockControl := Tab.DockControl;
end;

procedure TdxRibbonTabGroup.UpdateToolbarValue;
begin
  if (FLoadedToolbarName <> '') and Ribbon.IsBarManagerValid then
  begin
    ToolBar := Ribbon.BarManager.BarByComponentName(FLoadedToolbarName);
    FLoadedToolbarName := '';
  end;
end;

procedure TdxRibbonTabGroup.CheckUndockToolbar;
var
  ATab: TdxRibbonTab;
begin
  if GetAnotherTabWithOurToolbar(ATab) then
    RibbonDockToolBar(Toolbar, ATab.DockControl)
  else
    RibbonUndockToolBar(Toolbar);
end;

function TdxRibbonTabGroup.GetAnotherTabWithOurToolbar(out ATab: TdxRibbonTab): Boolean;
var
  ATabIndex: Integer;
begin
  Result := False;
  if ToolBar <> nil then
    for ATabIndex := 0 to Ribbon.TabCount - 1 do
      if Ribbon.Tabs[ATabIndex] <> Tab then
      begin
        Result := Ribbon.Tabs[ATabIndex].Groups.ContainsToolBar(ToolBar);
        if Result then
        begin
          ATab := Ribbon.Tabs[ATabIndex];
          Break;
        end;
      end;
end;

function TdxRibbonTabGroup.GetCanCollapse: Boolean;
begin
  Result := Restriction <> rtgrNoCollapse;
end;

function TdxRibbonTabGroup.GetCaption: string;
begin
  if GetIsCaptionAssigned then
    Result := FCaption
  else
    if ToolBar <> nil then
      Result := ToolBar.Caption
    else
      Result := ''
end;

function TdxRibbonTabGroup.GetIsCaptionAssigned: Boolean;
begin
  Result := rtgavCaption in AssignedValues;
end;

function TdxRibbonTabGroup.GetIsToolBarShared: Boolean;
var
  ATab: TdxRibbonTab;
begin
  Result := GetAnotherTabWithOurToolbar(ATab);
end;

function TdxRibbonTabGroup.GetRibbon: TdxCustomRibbon;
begin
  if Tab <> nil then
    Result := Tab.Ribbon
  else
    Result := nil
end;

function TdxRibbonTabGroup.GetTab: TdxRibbonTab;
begin
  if Collection <> nil then
    Result := (Collection as TdxRibbonTabGroups).Tab
  else
    Result := nil;
end;

function TdxRibbonTabGroup.GetToolbar: TdxBar;
begin
  if (FLoadedToolbarName <> '') and (Tab <> nil) and
    Ribbon.IsBarManagerValid and IsAncestorComponentDifferencesDetection(Tab)
  then
      Result := Ribbon.BarManager.BarByComponentName(FLoadedToolbarName)
  else
    Result := FToolbar;
end;

function TdxRibbonTabGroup.GetVisible: Boolean;
begin
  Result := (ToolBar <> nil) and ToolBar.Visible;
end;

procedure TdxRibbonTabGroup.SetAssignedValues(const AValue: TdxRibbonTabGroupAssignedValues);
begin
  if AssignedValues <> AValue then
  begin
    FAssignedValues := AValue;
    Changed(True);
  end;
end;

procedure TdxRibbonTabGroup.SetCanCollapse(Value: Boolean);
begin
  if Value then
    Restriction := rtgrNone
  else
    Restriction := rtgrNoCollapse;
end;

procedure TdxRibbonTabGroup.SetCaption(const AValue: string);
begin
  Include(FAssignedValues, rtgavCaption);
  if FCaption <> AValue then
  begin
    FCaption := AValue;
    Changed(True);
  end;
end;

procedure TdxRibbonTabGroup.SetMergeOrder(const Value: Integer);
begin
  FMergeOrder := Max(Value, 0);
end;

procedure TdxRibbonTabGroup.SetRestriction(AValue: TdxRibbonTabGroupRestriction);
begin
  if AValue <> FRestriction then
  begin
    FRestriction := AValue;
    if (ToolBar <> nil) and (Toolbar.Control <> nil) then
      ToolBar.Control.RepaintBar;
  end;
end;

procedure TdxRibbonTabGroup.SetToolbar(Value: TdxBar);
begin
  if IsToolbarAcceptable(Value) and (FToolbar <> Value) then
  begin
    CheckUndockToolbar;
    if Value = nil then
    begin
      Ribbon.QuickAccessToolbar.UpdateGroupButton(FToolbar, True);
      FToolbar := Value;
      Free;
    end
    else
    begin
      ValidateToolbar(Value);
      if FToolbar <> nil then
        Ribbon.QuickAccessToolbar.UpdateGroupButton(FToolbar, True);
      FToolbar := Value;
      Value.FreeNotification(Tab);
      DockToolbar(Value);
    end;
  end;
end;

procedure TdxRibbonTabGroup.ValidateToolbar(Value: TdxBar);
var
  I: Integer;
begin
  if Value = Ribbon.QuickAccessToolbar.Toolbar then
    raise EdxException.Create(sdxErrorToolbarUsedAsQAT);
  for I := 0 to Tab.Groups.Count - 1 do
    if (Tab.Groups[I] <> Self) and (Tab.Groups[I].ToolBar = Value) then
      raise EdxException.Create(sdxErrorToolbarUsedInAnotherGroupInThisTab);
end;

procedure TdxRibbonTabGroup.WriteCaption(AWriter: TWriter);
begin
  AWriter.WriteString(Caption);
end;

procedure TdxRibbonTabGroup.WriteToolbarName(AWriter: TWriter);
begin
  if ToolBar <> nil then
    AWriter.WriteString(ToolBar.Name)
  else
    AWriter.WriteString('');
end;

{ TdxRibbonTabGroups }

constructor TdxRibbonTabGroups.Create(ATab: TdxRibbonTab);
begin
  inherited Create(ATab.GetGroupClass);
  FTab := ATab;
end;

function TdxRibbonTabGroups.Add: TdxRibbonTabGroup;
begin
  Result := TdxRibbonTabGroup(inherited Add);
end;

function TdxRibbonTabGroups.ContainsToolBar(AToolBar: TdxBar): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count - 1 do
  begin
    Result := AToolBar = Items[I].ToolBar;
    if Result then Break;
  end;
end;

function TdxRibbonTabGroups.Find(const ACaption: string; out AGroup: TdxRibbonTabGroup): Boolean;
var
  I: Integer;
begin
  AGroup := nil;
  for I := 0 to Count - 1 do
    if ACaption = Items[I].Caption then
    begin
      AGroup := Items[I];
      Break;
    end;

  Result := AGroup <> nil;
end;

procedure TdxRibbonTabGroups.FreeNotification(AComponent: TComponent);
var
  I: Integer;
begin
  for I := Count - 1 downto 0 do
  begin
    if Items[I].Toolbar = AComponent then
      Items[I].Toolbar := nil;
  end;
end;

function TdxRibbonTabGroups.GetOwner: TPersistent;
begin
  Result := Tab;
end;

function TdxRibbonTabGroups.IndexOf(AGroup: TdxRibbonTabGroup): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Count - 1 do
    if Items[I] = AGroup then
    begin
      Result := I;
      Break;
    end;
end;

function TdxRibbonTabGroups.Insert(AIndex: Integer): TdxRibbonTabGroup;
begin
  Result := TdxRibbonTabGroup(inherited Insert(AIndex));
end;

procedure TdxRibbonTabGroups.Notify(Item: TCollectionItem; Action: TCollectionNotification);
begin
  inherited;
  Tab.Ribbon.Changed;
end;

procedure TdxRibbonTabGroups.Unmerge(AGroup: TdxRibbonTabGroup = nil);
var
  AItem: TdxRibbonTabGroup;
  I: Integer;
begin
  for I := Count - 1 downto 0 do
  begin
    AItem := Items[I];
    if (AGroup = nil) or TdxRibbonMergeHelper.IsMergedWith(AGroup.ToolBar, AItem.ToolBar) then    
      AItem.Unmerge(AGroup);
  end;
end;

procedure TdxRibbonTabGroups.Update(Item: TCollectionItem);
begin
  Tab.Ribbon.Changed;
  if Tab.Active then
  begin
    Tab.DockControl.UpdateDock;
    Tab.DockControl.FullInvalidate;
  end;
  if not Tab.IsDestroying then
  begin
    if Tab.MergeData.CreatedByMerging and (Tab.Groups.Count = 0) then
      Tab.Free;
  end;
end;

procedure TdxRibbonTabGroups.UpdateGroupToolbarValues;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].UpdateToolbarValue;
end;

function TdxRibbonTabGroups.GetItem(Index: Integer): TdxRibbonTabGroup;
begin
  Result := TdxRibbonTabGroup(inherited Items[Index]);
end;

procedure TdxRibbonTabGroups.SetItem(Index: Integer; const Value: TdxRibbonTabGroup);
begin
  TdxRibbonTabGroup(inherited Items[Index]).Assign(Value);
end;

{ TdxRibbonQuickAccessToolbar }

constructor TdxRibbonQuickAccessToolbar.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create;
  FRibbon := ARibbon;
  FPosition := qtpAboveRibbon;
  FVisible := True;
  FDockControl := CreateDockControl;
end;

destructor TdxRibbonQuickAccessToolbar.Destroy;
begin
  Toolbar := nil;
  FreeAndNil(FDockControl);
  inherited Destroy;
end;

function TdxRibbonQuickAccessToolbar.AddGroupButton(AToolbar: TdxBar): TdxRibbonQuickAccessGroupButton;
begin
  Result := nil;
  if AToolbar <> nil then
  begin
    Result := TdxRibbonQuickAccessGroupButton(Toolbar.ItemLinks.AddItem(TdxRibbonQuickAccessGroupButton).Item);
    if Result.IsToolbarAcceptable(AToolbar) then
    begin
      Result.Toolbar := AToolbar;
      Result.Name := 'QAT' + Result.Toolbar.Name;
    end
    else
    begin
      Toolbar.ItemLinks.Delete(Toolbar.ItemLinks.Count - 1);
      Result := nil;
    end;
  end;
end;

procedure TdxRibbonQuickAccessToolbar.Assign(Source: TPersistent);
begin
  if Source is TdxRibbonQuickAccessToolbar then
  begin
    Ribbon.BeginUpdate;
    try
      Position := TdxRibbonQuickAccessToolbar(Source).Position;
      Toolbar := TdxRibbonQuickAccessToolbar(Source).Toolbar;
      Visible := TdxRibbonQuickAccessToolbar(Source).Visible;
    finally
      Ribbon.EndUpdate;
    end;
  end;
end;

procedure TdxRibbonQuickAccessToolbar.BarManagerLoadIni(const AEventData: TdxBarIniFileEventData);
var
  ABar: TdxBar;
  ABarSection, AItemSection: string;
  AGroupButton: TdxRibbonQuickAccessGroupButton;
  I, ALinkCount: Integer;
begin
  if Toolbar <> nil then
  begin
    ABarSection := TdxBarAccess(Toolbar).GetIniSection(AEventData.BaseSection, Toolbar.Index);
    ALinkCount := AEventData.IniFile.ReadInteger(ABarSection, 'ItemLinkCount', 0);
    for I := 0 to ALinkCount - 1 do
    begin
      AItemSection := TdxBarItemLinkAccess.GetIniSection(ABarSection, I, AEventData.StoringKind);
      ABar := Ribbon.BarManager.BarByComponentName(AEventData.IniFile.ReadString(AItemSection, 'ToolbarName', ''));
      if ABar <> nil then
      begin
        AGroupButton := AddGroupButton(ABar);
        if (AGroupButton <> nil) and (I <> ALinkCount - 1) then
          Toolbar.ItemLinks.Move(Toolbar.ItemLinks.Count - 1, I);
      end;
    end;
  end;
end;

procedure TdxRibbonQuickAccessToolbar.BarManagerSaveIni(const AEventData: TdxBarIniFileEventData);
var
  AItemLink: TdxBarItemLink;
  ASection: string;
  I: Integer;
begin
  if Toolbar <> nil then
    for I := 0 to Toolbar.ItemLinks.Count - 1 do
    begin
      AItemLink := Toolbar.ItemLinks[I];
      if AItemLink.Item is TdxRibbonQuickAccessGroupButton then
      begin
        if TdxBarItemLinkAccess(AItemLink).CreatedFromMergingWith = nil then
        begin
          ASection := TdxBarAccess(Toolbar).GetIniSection(AEventData.BaseSection, Toolbar.Index);
          ASection := TdxBarItemLinkAccess(AItemLink).GetIniSection(ASection, I, AEventData.StoringKind);
          AEventData.IniFile.WriteString(ASection, 'ToolbarName',
            TdxRibbonQuickAccessGroupButton(AItemLink.Item).Toolbar.Name);
        end;
      end;
    end;
end;

function TdxRibbonQuickAccessToolbar.HasGroupButtonForToolbar(AToolbar: TdxBar): Boolean;
begin
  Result := (Toolbar <> nil) and
    TdxRibbonQuickAccessToolbarHelper.HasGroupButtonForToolbar(Toolbar.ItemLinks, AToolbar);
end;

procedure TdxRibbonQuickAccessToolbar.CheckUndockGroupToolbar(AValue: TdxBar);
var
  I, J: Integer;
begin
  for I := 0 to Ribbon.TabCount - 1 do
    for J := Ribbon.Tabs[I].Groups.Count - 1 downto 0 do
    begin
      with Ribbon.Tabs[I].Groups[J] do
        if ToolBar = AValue then ToolBar := nil;
    end;
end;

function TdxRibbonQuickAccessToolbar.Contains(AItemLink: TdxBarItemLink): Boolean;
begin
  if (AItemLink <> nil) and (AItemLink.OriginalItemLink <> nil) then
    AItemLink := AItemLink.OriginalItemLink;
  Result := Toolbar.ItemLinks.IndexOf(AItemLink) <> -1;
end;

function TdxRibbonQuickAccessToolbar.CreateDockControl: TdxRibbonQuickAccessDockControl;
begin
  Result := TdxRibbonQuickAccessDockControl.Create(Ribbon);
end;

function TdxRibbonQuickAccessToolbar.GetMenuItemsForMark: TdxRibbonPopupMenuItems;
begin
  Result := Ribbon.GetValidPopupMenuItems - [rpmiQATAddRemoveItem];
end;

function TdxRibbonQuickAccessToolbar.GetRealVisible: Boolean;
begin
  Result := DockControl.Visible;
end;

function TdxRibbonQuickAccessToolbar.GetRibbon: TdxCustomRibbon;
begin
  Result := FRibbon;
end;

function TdxRibbonQuickAccessToolbar.IsMerged: Boolean;
begin
  Result := (Toolbar <> nil) and Toolbar.IsMerged;
end;

procedure TdxRibbonQuickAccessToolbar.Merge(
  AQuickAccessToolbar: TdxRibbonQuickAccessToolbar;
  AMergeOptions: TdxRibbonMergeOptions = dxRibbonDefaultMergeOptions);
begin
  if (AQuickAccessToolbar <> nil) and (AQuickAccessToolbar.Toolbar <> nil) and AQuickAccessToolbar.RealVisible then
  begin
    TdxRibbonMergeHelper.MergeToolbarContainers(
      Self, AQuickAccessToolbar, rmoCanCreateQATToolbar in AMergeOptions);
  end;
end;

procedure TdxRibbonQuickAccessToolbar.Unmerge(AQuickAccessToolbar: TdxRibbonQuickAccessToolbar = nil);
begin
  TdxRibbonMergeHelper.UnmergeToolbarContainers(Self, AQuickAccessToolbar);
end;

procedure TdxRibbonQuickAccessToolbar.UpdateColorScheme;
begin
  if Visible and DockControl.Visible then
    DockControl.UpdateColorScheme;
end;

procedure TdxRibbonQuickAccessToolbar.UpdateGroupButton(AForToolbar: TdxBar; ABeforeUndock: Boolean);
var
  AGroupButton: TdxRibbonQuickAccessGroupButton;
  I: Integer;
begin
  if Toolbar = nil then
    Exit;
  for I := 0 to Toolbar.ItemLinks.Count - 1 do
    if Toolbar.ItemLinks[I].Item is TdxRibbonQuickAccessGroupButton then
    begin
      AGroupButton := TdxRibbonQuickAccessGroupButton(Toolbar.ItemLinks[I].Item);
      if AGroupButton.Toolbar = AForToolbar then
      begin
        if ABeforeUndock then
          AGroupButton.Toolbar := nil
        else
          AGroupButton.Update;
        Break;
      end;
    end;
end;

procedure TdxRibbonQuickAccessToolbar.UpdateMenuItems(AItems: TdxBarItemLinks);
begin
  Ribbon.PopulatePopupMenuItems(AItems, GetMenuItemsForMark, Ribbon.PopupMenuItemClick);
end;

procedure TdxRibbonQuickAccessToolbar.UpdateRibbon;
begin
  if Ribbon.IsDestroying then Exit;
  Ribbon.SetRedraw(False);
  try
    Ribbon.Changed;
  finally
    Ribbon.SetRedraw(True);
    WinControlFullInvalidate(Ribbon.Parent, True);
    Ribbon.Update;
  end;
end;

function TdxRibbonQuickAccessToolbar.GetToolbar: TdxBar;
begin
  Result := FToolbar;
end;

procedure TdxRibbonQuickAccessToolbar.SetPosition(AValue: TdxQuickAccessToolbarPosition);
begin
  if FPosition <> AValue then
  begin
    FPosition := AValue;
    UpdateRibbon;
  end;
end;

procedure TdxRibbonQuickAccessToolbar.SetToolbar(AValue: TdxBar);

  procedure RemoveGroupButtons(AToolbar: TdxBar);
  var
    I: Integer;
  begin
    for I := AToolbar.ItemLinks.Count - 1 downto 0 do
      if AToolbar.ItemLinks[I].Item is TdxRibbonQuickAccessGroupButton then
        AToolbar.ItemLinks[I].Item.Free;
  end;

begin
  if FToolbar <> AValue then
  begin
    Ribbon.BeginUpdate;
    try
      if (FToolbar <> nil) and not (csDestroying in FToolbar.ComponentState) then
      begin
        FToolbar.RemoveFreeNotification(Ribbon);
        RemoveGroupButtons(FToolbar);
        RibbonUndockToolBar(FToolbar);
      end;
      FToolbar := AValue;
      if FToolbar <> nil  then
      begin
        CheckUndockGroupToolbar(AValue);
        FToolbar.FreeNotification(Ribbon);
        RibbonDockToolBar(FToolbar, DockControl);
      end
      else
        DockControl.Visible := False;
    finally
      Ribbon.CancelUpdate;
      UpdateRibbon;
    end;
  end;
end;

procedure TdxRibbonQuickAccessToolbar.SetVisible(AValue: Boolean);
begin
  if FVisible <> AValue then
  begin
    FVisible := AValue;
    DockControl.Visible := AValue and (Toolbar <> nil);
    UpdateRibbon;
  end;
end;

{ TdxRibbonCustomButtonPersistent }

constructor TdxRibbonCustomButtonPersistent.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create;
  FRibbon := ARibbon;
  FGlyph := TBitmap.Create;
  FGlyph.OnChange := GlyphChanged;
  FStretchGlyph := True;
end;

destructor TdxRibbonCustomButtonPersistent.Destroy;
begin
  FGlyph.Free;
  inherited Destroy;
end;

procedure TdxRibbonCustomButtonPersistent.Assign(Source: TPersistent);
begin
  if Source is TdxRibbonApplicationButton then
  begin
    Ribbon.BeginUpdate;
    try
      Glyph := TdxRibbonApplicationButton(Source).Glyph;
      ScreenTip := TdxRibbonApplicationButton(Source).ScreenTip;
      StretchGlyph := TdxRibbonApplicationButton(Source).StretchGlyph;
    finally
      Ribbon.EndUpdate;
    end;
  end;
  inherited Assign(Source);
end;

procedure TdxRibbonCustomButtonPersistent.GlyphChanged(Sender: TObject);
begin
  Update;
end;

procedure TdxRibbonCustomButtonPersistent.SetGlyph(Value: TBitmap);
begin
  if IsGlyphAssigned(Value) and (Value.PixelFormat <> pf32bit) then
    cxMakeTrueColorBitmap(Value, FGlyph)
  else
    FGlyph.Assign(Value);
end;

procedure TdxRibbonCustomButtonPersistent.SetScreenTip(const Value: TdxScreenTip);
begin
  if FScreenTip <> Value then
  begin
    if FScreenTip <> nil then
      FScreenTip.RemoveFreeNotification(Ribbon);
    FScreenTip := Value;
    if FScreenTip <> nil then
      FScreenTip.FreeNotification(Ribbon);
  end;
end;

procedure TdxRibbonCustomButtonPersistent.SetStretchGlyph(const Value: Boolean);
begin
  if FStretchGlyph <> Value then
  begin
    FStretchGlyph := Value;
    Update;
  end;
end;

procedure TdxRibbonCustomButtonPersistent.Update;
begin
  Ribbon.Changed;
  if Ribbon.FormCaptionHelper <> nil then
    Ribbon.FormCaptionHelper.Calculate;
  Ribbon.FullInvalidate;
end;

{ TdxRibbonApplicationButton }

constructor TdxRibbonApplicationButton.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create(ARibbon);
  FVisible := True;
end;

destructor TdxRibbonApplicationButton.Destroy;
begin
  BarAccessibilityHelperOwnerObjectDestroyed(FIAccessibilityHelper);
  Menu := nil;
  inherited Destroy;
end;

procedure TdxRibbonApplicationButton.Assign(Source: TPersistent);
begin
  Ribbon.BeginUpdate;
  try
    if Source is TdxRibbonApplicationButton then
    begin
      KeyTip := TdxRibbonApplicationButton(Source).KeyTip;
      Menu := TdxRibbonApplicationButton(Source).Menu;
      Visible := TdxRibbonApplicationButton(Source).Visible;
    end;
    inherited Assign(Source);
  finally
    Ribbon.EndUpdate;
  end;
end;

function TdxRibbonApplicationButton.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonApplicationButtonAccessibilityHelper;
end;

function TdxRibbonApplicationButton.CanShowPopup: Boolean;
begin
  Result := (IMenu <> nil) and IMenu.CanShowPopup(Ribbon);
end;

procedure TdxRibbonApplicationButton.ClosePopup;
begin
  if IMenu <> nil then
    IMenu.ClosePopup;
end;

procedure TdxRibbonApplicationButton.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (Operation = opRemove) and (AComponent = Menu) then
    Menu := nil;
end;

function TdxRibbonApplicationButton.Popup(var AClosedByEscape: Boolean): Boolean;
begin
  Result := IMenu.Popup(Ribbon, AClosedByEscape)
end;

function TdxRibbonApplicationButton.GetIAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  if FIAccessibilityHelper = nil then
    FIAccessibilityHelper := GetAccessibilityHelperClass.Create(Self);
  Result := FIAccessibilityHelper;
end;

procedure TdxRibbonApplicationButton.SetMenu(const Value: TComponent);
var
  ANewIMenu: IdxRibbonApplicationMenu;
begin
  if FMenu <> Value then
  begin
    if (Value = nil) or Supports(Value, IdxRibbonApplicationMenu, ANewIMenu) then
    begin
      if FMenu <> nil then
      begin
        ClosePopup;
        FMenu.RemoveFreeNotification(Ribbon);
        FIMenu := nil;
        FMenu := nil;
      end;
      if Value <> nil then
      begin
        FMenu := Value;
        FMenu.FreeNotification(Ribbon);
        FIMenu := ANewIMenu;
      end;
    end;
  end;
end;

procedure TdxRibbonApplicationButton.SetText(const Value: string);
begin
  if FText <> Value then
  begin
    FText := Value;
    Update;
  end;
end;

procedure TdxRibbonApplicationButton.SetVisible(const Value: Boolean);
begin
  if FVisible <> Value then
  begin
    FVisible := Value;
    Update;
  end;
end;

{ TdxRibbonContext }

constructor TdxRibbonContext.Create(Collection: TCollection);
begin
  inherited Create(Collection);
  FColor := clWhite;
  FVisible := False;
end;

function TdxRibbonContext.GetDisplayName: string;
begin
  Result := Caption;
  if Result = '' then
    Result := inherited GetDisplayName;
end;

procedure TdxRibbonContext.Assign(Source: TPersistent);
begin
  if Source is TdxRibbonContext then
  begin
    FCaption := TdxRibbonContext(Source).Caption;
    FColor := TdxRibbonContext(Source).Color;
    FMergeOrder := TdxRibbonContext(Source).MergeOrder;
    FVisible := TdxRibbonContext(Source).Visible;
  end
  else
    inherited;
end;

procedure TdxRibbonContext.Activate(AActivateFirstTab: Boolean = True);
begin
  if TabCount > 0 then
  begin
    if not Visible then
    begin
      Ribbon.BeginUpdate;
      try
        Visible := True;
        Tabs[0].Active := True;
      finally
        Ribbon.EndUpdate;
      end;
    end
    else
      if AActivateFirstTab then
        Tabs[0].Active := True;

    if GetMergedWithContext <> nil then
      GetMergedWithContext.Activate(AActivateFirstTab)
  end;
end;

procedure TdxRibbonContext.ColorChanged;
var
  ATab: TdxRibbonTab;
begin
  Changed(False);
  ATab := Ribbon.ActiveTab;
  if (ATab <> nil) and (ATab.Context = Self) then
  begin
    if ATab.DockControl <> nil then
      ATab.DockControl.FullInvalidate;
  end;
end;

procedure TdxRibbonContext.UpdateMergeTargetVisibility;
begin
  if GetMergedWithContext <> nil then
    GetMergedWithContext.Visible := Visible;
end;

procedure TdxRibbonContext.VisibleChanged;
var
  ATab: TdxRibbonTab;
begin
  UpdateMergeTargetVisibility;
  if not Visible then
  begin
    ATab := Ribbon.ActiveTab;
    if (ATab <> nil) and (ATab.Context = Self) then
    begin
      Ribbon.ActiveTab := Ribbon.GetNextActiveTab(nil);
      Exit;
    end;
  end;
  Changed(False);
end;

function TdxRibbonContext.GetCollection: TdxRibbonContexts;
begin
  Result := TdxRibbonContexts(inherited Collection);
end;

function TdxRibbonContext.GetMergedWithContext: TdxRibbonContext;
var
  ATab: TdxRibbonTab;
begin
  Result := nil;
  if TabCount > 0 then
  begin
    ATab := Tabs[0];
    if (ATab.MergeData.MergedWith <> nil) then
      Result := ATab.MergeData.MergedWith.Context;
  end;
end;

function TdxRibbonContext.GetRibbon: TdxCustomRibbon;
begin
  Result := Collection.Ribbon;
end;

function TdxRibbonContext.GetTab(Index: Integer): TdxRibbonTab;
var
  I: Integer;
begin
  Result := nil;
  if Index >= 0 then
  begin
    for I := 0 to Ribbon.Tabs.Count - 1 do
      if Ribbon.Tabs[I].Context = Self then
      begin
        if Index = 0 then
        begin
          Result := Ribbon.Tabs[I];
          Break;
        end;
        Dec(Index);
      end;
  end;
end;

function TdxRibbonContext.GetTabCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to Ribbon.Tabs.Count - 1 do
  begin
    if Ribbon.Tabs[I].Context = Self then
      Inc(Result);
  end;
end;

procedure TdxRibbonContext.SetCaption(const AValue: string);
begin
  if Caption <> AValue then
  begin
    FCaption := AValue;
    Changed(False);
  end;
end;

procedure TdxRibbonContext.SetColor(AValue: TColor);
begin
  if Color <> AValue then
  begin
    FColor := AValue;
    ColorChanged;
  end;
end;

procedure TdxRibbonContext.SetMergeOrder(const AValue: Integer);
begin
  FMergeOrder := Max(AValue, 0);
end;

procedure TdxRibbonContext.SetVisible(AValue: Boolean);
begin
  if Visible <> AValue then
  begin
    FVisible := AValue;
    VisibleChanged;
  end;
end;

{ TdxRibbonContexts }

constructor TdxRibbonContexts.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create(TdxRibbonContext);
  FRibbon := ARibbon;
end;

function TdxRibbonContexts.Find(const ACaption: string): TdxRibbonContext;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if Items[I].Caption = ACaption then
    begin
      Result := Items[I];
      Break;
    end;
end;

function TdxRibbonContexts.Add: TdxRibbonContext;
begin
  Result := TdxRibbonContext(inherited Add);
end;

function TdxRibbonContexts.GetItemFromIndex(AIndex: Integer): TdxRibbonContext;
begin
  if (AIndex < 0) or (AIndex >= Count) then
    Result := nil
  else
    Result := Items[AIndex];
end;

function TdxRibbonContexts.IndexOf(AContext: TdxRibbonContext): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Count - 1 do
    if Items[I] = AContext then
    begin
      Result := I;
      Break;
    end;
end;

function TdxRibbonContexts.Insert(AIndex: Integer): TdxRibbonContext;
begin
  Result := TdxRibbonContext(inherited Insert(AIndex));
end;

procedure TdxRibbonContexts.Notify(Item: TCollectionItem; Action: TCollectionNotification);
begin
  inherited;
  if (Action = cnExtracting) and not Ribbon.IsDestroying then
    Ribbon.Tabs.RemoveContext(TdxRibbonContext(Item));
end;

procedure TdxRibbonContexts.Update(Item: TCollectionItem);
begin
  Ribbon.Changed;
end;

function TdxRibbonContexts.GetActiveContext: TdxRibbonContext;
begin
  if Ribbon.ActiveTab <> nil then
    Result := Ribbon.ActiveTab.Context
  else
    Result := nil;
end;

function TdxRibbonContexts.GetItem(Index: Integer): TdxRibbonContext;
begin
  Result := TdxRibbonContext(inherited Items[Index]);
end;

procedure TdxRibbonContexts.SetItem(Index: Integer; const Value: TdxRibbonContext);
begin
  TdxRibbonContext(inherited Items[Index]).Assign(Value);
end;

{ TdxRibbonTab }

constructor TdxRibbonTab.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FMergeData := TdxRibbonTabMergeData.Create;
  FDockControl := TdxRibbonGroupsDockControl.Create(Self);
  FDockControl.Visible := False;
  FDockControl.Align := dalNone;
  FVisible := True;
  FContextIndex := -1;
  FLoadedIndex := -1;
  FGroups := TdxRibbonTabGroups.Create(Self);
end;

destructor TdxRibbonTab.Destroy;
begin
  UnmergeBeforeDestroy;
  Context := nil;
  BarAccessibilityHelperOwnerObjectDestroyed(FIAccessibilityHelper);
  FLastIndex := Index;
  dxFader.Remove(Self);
  Groups.Clear;
  FreeAndNil(FGroups);
  FreeAndNil(FDockControl);
  FreeAndNil(FMergeData);
  inherited Destroy;
  FDesignSelectionHelper := nil;
end;

procedure TdxRibbonTab.Assign(Source: TPersistent);
begin
  if Source is TdxRibbonTab then
  begin
    Ribbon.BeginUpdate;
    try
      AssignCommonProperties(TdxRibbonTab(Source));
      Active := TdxRibbonTab(Source).Active;
      Groups := TdxRibbonTab(Source).Groups;
      Visible := TdxRibbonTab(Source).Visible;
    finally
      Ribbon.EndUpdate;
    end;
  end
  else
    inherited Assign(Source);
end;

procedure TdxRibbonTab.AssignCommonProperties(ASource: TdxRibbonTab);
begin
  Ribbon.BeginUpdate;
  try
    KeyTip := ASource.KeyTip;
    Caption := ASource.Caption;
    MergeKind := ASource.MergeKind;
    MergeOrder := ASource.MergeOrder;
  finally
    Ribbon.EndUpdate;
  end;
end;

procedure TdxRibbonTab.AddToolBar(AToolBar: TdxBar);
begin
  if AToolbar <> nil then
    Groups.Add.Toolbar := AToolBar;
end;

function TdxRibbonTab.IsMergeAllowed: Boolean;
begin
  Result := Visible and (MergeKind <> rmkNone);
end;

procedure TdxRibbonTab.Invalidate;
begin
  Ribbon.InvalidateRect(ViewInfo.Bounds, False);
  Ribbon.GroupsDockControlSite.Invalidate;
end;

procedure TdxRibbonTab.MakeVisible;
begin
  Visible := True;
  Ribbon.ViewInfo.TabsViewInfo.MakeTabVisible(Self);
end;

procedure TdxRibbonTab.DefineProperties(Filer: TFiler);
begin
  inherited DefineProperties(Filer);
  Filer.DefineProperty('Index', ReadIndex, WriteIndex, True);
  Filer.DefineProperty('ContextIndex', ReadContextIndex, WriteContextIndex, FContext <> nil);
end;

function TdxRibbonTab.GetCollectionFromParent(AParent: TComponent): TcxComponentCollection;
begin
  Result := (AParent as TdxCustomRibbon).Tabs;
end;

function TdxRibbonTab.GetDisplayName: string;
begin
  Result := Format('%s - ''%s''', [Name, Caption]);
end;

procedure TdxRibbonTab.Loaded;
begin
  inherited Loaded;
  Groups.UpdateGroupToolbarValues;
end;

procedure TdxRibbonTab.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Operation = opRemove then
  begin
    if Groups <> nil then
      Groups.FreeNotification(AComponent);
  end;
end;

procedure TdxRibbonTab.Merge(ATab: TdxRibbonTab;
  AMergeOptions: TdxRibbonMergeOptions = dxRibbonDefaultMergeOptions);

  function GetInsertPosition(ASourceGroup: TdxRibbonTabGroup): Integer;
  var
    I: Integer;
  begin
    Result := 0;
    for I := 0 to Groups.Count - 1 do
    begin
      if ASourceGroup.MergeOrder >= Groups[I].MergeOrder then
        Result := I + 1;
    end;
  end;

  function CanMerge(AGroup, ATargetGroup: TdxRibbonTabGroup): Boolean;
  begin
    Result := (AGroup.MergeKind = ATargetGroup.MergeKind) and
      (ATargetGroup.Caption = AGroup.Caption) and not ATargetGroup.IsToolBarShared;
  end;

  function FindTargetGroup(AGroup: TdxRibbonTabGroup; out ATargetGroup: TdxRibbonTabGroup): Boolean;
  var
    I: Integer;
  begin
    Result := False;
    for I := 0 to Groups.Count - 1 do
      if CanMerge(AGroup, Groups.Items[I]) then
      begin
        ATargetGroup := Groups.Items[I];
        Result := True;
        Break;
      end;
  end;

var
  AGroup: TdxRibbonTabGroup;
  ATargetGroup: TdxRibbonTabGroup;
  I: Integer;
begin
  if (ATab = nil) or (ATab = Self) then
    RaiseMergingError(@dxSBAR_RIBBONCANTMERGETAB);
  if not (Ribbon.IsBarManagerValid and ATab.Ribbon.IsBarManagerValid) then
    RaiseMergingError(@dxSBAR_RIBBONCANTMERGEWITHOUTBARMANAGER);
  if ATab.IsMerged then
    RaiseMergingError(@dxSBAR_RIBBONONEOFTABGROUPSALREADYMERGED);

  Ribbon.BeginUpdate;
  try
    MergeData.Children.Add(ATab);
    ATab.MergeData.MergedWith := Self;
    ATab.MergeData.VisibleBeforeMerging := ATab.Visible;
    ATab.Visible := False;

    for I := 0 to ATab.Groups.Count - 1 do
    begin
      AGroup := ATab.Groups[I];
      if AGroup.IsMergeAllowed and (AGroup.MergeKind = rmkMerge) then
      begin
        if FindTargetGroup(AGroup, ATargetGroup) then
          ATargetGroup.Merge(AGroup, AMergeOptions);
      end;
    end;

    if rmoCanCreateNewGroup in AMergeOptions then
    begin
      for I := 0 to ATab.Groups.Count - 1 do
      begin
        AGroup := ATab.Groups[I];
        if AGroup.IsMergeAllowed and not AGroup.IsMerged then
        begin
          ATargetGroup := Groups.Insert(GetInsertPosition(AGroup));
          ATargetGroup.Caption := AGroup.Caption;
          ATargetGroup.MergeKind := AGroup.MergeKind;
          ATargetGroup.MergeOrder := AGroup.MergeOrder;
          ATargetGroup.Merge(AGroup, AMergeOptions);
        end;
      end;
    end;
  finally
    Ribbon.EndUpdate;
  end;
end;

function TdxRibbonTab.InternalUnmerge(ATab: TdxRibbonTab): Boolean;
var
  I: Integer;
begin
  Result := (ATab <> nil) and (ATab.MergeData.MergedWith = Self);
  if Result then
  begin
    ATab.MergeData.MergedWith := nil;
    ATab.Visible := ATab.MergeData.VisibleBeforeMerging;
    MergeData.Children.Remove(ATab);
    for I := ATab.Groups.Count - 1 downto 0 do
      Groups.Unmerge(ATab.Groups[I]);
  end;
end;

procedure TdxRibbonTab.Unmerge(ATab: TdxRibbonTab = nil);
var
  I: Integer;
begin
  if ATab = Self then
    RaiseMergingError(@dxSBAR_RIBBONCANTUNMERGETAB);
  if (ATab <> nil) and (ATab.MergeData.MergedWith = nil) then
    Exit;
  if (ATab <> nil) and (ATab.MergeData.MergedWith <> Self) then
    RaiseMergingError(@dxSBAR_RIBBONTABSARENOTMERGED, Self, ATab);
  if MergeData.Children.Count = 0 then
    Exit;

  if ATab <> nil then
    InternalUnmerge(ATab)
  else
    for I := MergeData.Children.Count - 1 downto 0 do
      InternalUnmerge(TdxRibbonTab(MergeData.Children[I]));
end;

procedure TdxRibbonTab.UnmergeBeforeDestroy;
begin
  if MergeData.MergedWith <> nil then
    MergeData.MergedWith.Unmerge(Self);
  Unmerge;
end;

procedure TdxRibbonTab.SetName(const Value: TComponentName);
var
  AChangeText: Boolean;
begin
  AChangeText := not (csLoading in ComponentState) and (Name = Caption) and
    ((Owner = nil) or not (Owner is TControl) or
    not (csLoading in TControl(Owner).ComponentState));
  inherited SetName(Value);
  if AChangeText then
    Caption := Value;
end;

procedure TdxRibbonTab.Activate;
begin
  MakeVisible;
  if Ribbon.ShowTabGroups then
  begin
    UpdateDockControl;
    CheckGroupToolbarsDockControl;
    FDockControl.Visible := True;
  end
  else
    CheckGroupToolbarsDockControl;
end;

procedure TdxRibbonTab.CheckGroupToolbarsDockControl;
var
  I: Integer;
  AToolbar: TdxBar;
begin
  for I := 0 to Groups.Count - 1 do
  begin
    AToolbar := Groups[I].ToolBar;
    if (AToolBar <> nil) and (AToolBar.DockControl <> DockControl) then
      AToolBar.DockControl := DockControl;
  end;
end;

procedure TdxRibbonTab.Deactivate;
begin
  if not IsDestroying then
    DockControl.Visible := False;
end;

function TdxRibbonTab.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonTabAccessibilityHelper;
end;

function TdxRibbonTab.CanFade: Boolean;
begin
  Result := Ribbon.CanFade and (ViewInfo <> nil);
end;

function TdxRibbonTab.GetActive: Boolean;
begin
  Result := Ribbon.ActiveTab = Self;
end;

function TdxRibbonTab.GetFadingOptions: TdxFadingOptions;
begin
  Result := Ribbon.OptionsFading.Tabs;
end;

function TdxRibbonTab.GetFocused: Boolean;
begin
  Result := IAccessibilityHelper.IsSelected;
end;

function TdxRibbonTab.GetHighlighted: Boolean;
begin
  Result := Ribbon.HighlightedTab = Self;
end;

function TdxRibbonTab.GetIAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  if FIAccessibilityHelper = nil then
    FIAccessibilityHelper := GetAccessibilityHelperClass.Create(Self);
  Result := FIAccessibilityHelper;
end;

function TdxRibbonTab.GetIsDestroying: Boolean;
begin
  Result := csDestroying in ComponentState;
end;

function TdxRibbonTab.GetViewInfo: TdxRibbonTabViewInfo;
var
  I: Integer;
begin
  Result := nil;
  with Ribbon.ViewInfo do
  begin
    for I := 0 to TabsViewInfo.Count - 1 do
      if TabsViewInfo[I].Tab = Self then
      begin
        Result := TabsViewInfo[I];
        Break;
      end;
  end;
end;

function TdxRibbonTab.GetVisibleIndex: Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Ribbon.VisibleTabCount - 1 do
    if Ribbon.VisibleTabs[I] = Self then
    begin
      Result := I;
      break;
    end;
end;

procedure TdxRibbonTab.ReadContextIndex(Reader: TReader);
begin
  FContextIndex := Reader.ReadInteger;
end;

procedure TdxRibbonTab.ReadIndex(Reader: TReader);
begin
  FLoadedIndex := Reader.ReadInteger;
end;

procedure TdxRibbonTab.SetActive(Value: Boolean);
begin
  if Value then
    Ribbon.ActiveTab := Self;
end;

procedure TdxRibbonTab.SetCaption(const Value: string);
begin
  if FCaption <> Value then
  begin
    FCaption := Value;
    Ribbon.Changed;
  end;
end;

procedure TdxRibbonTab.SetContext(AValue: TdxRibbonContext);
var
  APrevContext: TdxRibbonContext;
begin
  if FContext <> AValue then
  begin
    APrevContext := Context;
    try
      FContext := AValue;
      UpdateContextIndex;
      if Active and not IsVisible then
        Ribbon.SetNextActiveTab(Self)
      else
      begin
        Ribbon.Changed;
        Ribbon.UpdateActiveTab;
      end;
    finally
      if not Ribbon.IsDestroying and (APrevContext <> nil) and APrevContext.FCreatedByMerging then
      begin
        if APrevContext.TabCount = 0 then
          APrevContext.Free;
      end;
    end;
  end;
end;

procedure TdxRibbonTab.SetHighlighted(Value: Boolean);
begin
  if Value then
    Ribbon.HighlightedTab := Self;
end;

procedure TdxRibbonTab.SetMergeOrder(const AValue: Integer);
begin
  FMergeOrder := Max(AValue, 0);
end;

procedure TdxRibbonTab.SetRibbon(Value: TdxCustomRibbon);
begin
  if FRibbon <> Value then
  begin
    FRibbon := Value;
    if FRibbon <> nil then
    begin
      FDesignSelectionHelper := nil;
      FDesignSelectionHelper := GetSelectableItem(TdxDesignSelectionHelper.Create(Ribbon, Self, Ribbon));
      FDockControl.BarManager := FRibbon.BarManager;
      FDockControl.Parent := FRibbon.GroupsDockControlSite;
    end;
  end;
end;

function TdxRibbonTab.GetDockControlBounds: TRect;
begin
  Result := cxRectContent(GetControlRect(Ribbon.GroupsDockControlSite),
    Ribbon.ViewInfo.GetTabGroupsDockControlOffset);
end;

function TdxRibbonTab.GetGroupClass: TdxRibbonTabGroupClass;
begin
  Result := TdxRibbonTabGroup;
end;

function TdxRibbonTab.IsMerged: Boolean;
var
  I: Integer;
begin
  Result := (MergeData.MergedWith <> nil) or (MergeData.Children.Count > 0);
  for I := 0 to Groups.Count - 1 do
    Result := Result or Groups[I].IsMerged;
end;

function TdxRibbonTab.IsVisible: Boolean;
begin
  Result := Visible and ((Context = nil) or Context.Visible);
end;

procedure TdxRibbonTab.RestoreContext;
begin
  FContextIndex := FSaveContextIndex;
end;

procedure TdxRibbonTab.RestoreIndex;
begin
  if LoadedIndex >= 0 then
    Index := LoadedIndex;
end;

procedure TdxRibbonTab.SaveContext;
begin
  FSaveContextIndex := FContextIndex;
end;

procedure TdxRibbonTab.ScrollDockControlGroups(AScrollLeft, AOnTimer: Boolean);
begin
  DockControl.ViewInfo.ScrollGroups(AScrollLeft, Ribbon.GroupsDockControlSite.Width -
    cxMarginsWidth(Ribbon.ViewInfo.GetTabGroupsDockControlOffset));
end;

procedure TdxRibbonTab.UpdateBarManager(ABarManager: TdxBarManager);
var
  I: Integer;
begin
  FDockControl.BarManager := ABarManager;
  for I := 0 to Groups.Count - 1 do
    Groups[I].UpdateBarManager(ABarManager);
end;

procedure TdxRibbonTab.UpdateColorScheme;
begin
  DockControl.UpdateColorScheme;
end;

procedure TdxRibbonTab.UpdateContextIndex;
begin
  if Context <> nil then
    FContextIndex := Context.Index
  else
    FContextIndex := -1;
end;

procedure TdxRibbonTab.UpdateDockControl;
var
  AIsDockControlVisible: Boolean;
begin
  if not Ribbon.IsLocked then
    if dxBarGetParentPopupWindow(DockControl, True) = nil then
    begin
      AIsDockControlVisible := Visible and not Ribbon.Hidden and Ribbon.ShowTabGroups and Active;
      if AIsDockControlVisible then
      begin
        DockControl.ViewInfo.Calculate(GetDockControlBounds);
        UpdateDockControlBounds;
      end;
      DockControl.Visible := AIsDockControlVisible;
    end
    else
    begin
      DockControl.ViewInfo.Calculate(DockControl.ClientRect);
      DockControl.UpdateGroupPositions;
    end;
end;

procedure TdxRibbonTab.UpdateDockControlBounds;
begin
  if not Ribbon.IsLocked then
    DockControl.BoundsRect := GetDockControlBounds;
end;

procedure TdxRibbonTab.UpdateGroupsFont;
var
  I, J: Integer;
  ABarControl: TdxBarControl;
begin
  for I := 0 to DockControl.RowCount - 1 do
    with DockControl.Rows[I] do
    begin
      for J := 0 to ColCount - 1 do
      begin
        ABarControl := Cols[J].BarControl;
        if (ABarControl <> nil) and ABarControl.HandleAllocated then
          ABarControl.UpdateFont;
      end;
    end;
end;

procedure TdxRibbonTab.WriteContextIndex(Writer: TWriter);
begin
  UpdateContextIndex;
  Writer.WriteInteger(FContextIndex);
end;

procedure TdxRibbonTab.WriteIndex(Writer: TWriter);
begin
  FLoadedIndex := Index;
  Writer.WriteInteger(FLoadedIndex);
end;

procedure TdxRibbonTab.SetGroups(const Value: TdxRibbonTabGroups);
begin
  FGroups.Assign(Value);
end;

procedure TdxRibbonTab.SetVisible(Value: Boolean);
begin
  if FVisible <> Value then
  begin
    FVisible := Value;
    if Active and not Value then
      Ribbon.SetNextActiveTab(Self);
    Ribbon.Changed;
  end;
end;

procedure TdxRibbonTab.FadingDrawFadeImage;
begin
  if not IsDestroying then
    Invalidate;
end;

procedure TdxRibbonTab.FadingGetFadingImages(out AFadeOutImage, AFadeInImage: TcxBitmap);
begin
  AFadeOutImage := ViewInfo.PrepareFadeImage(False);
  AFadeInImage := ViewInfo.PrepareFadeImage(True);
end;

{ TdxRibbonTabCollection }

constructor TdxRibbonTabCollection.Create(AOwner: TdxCustomRibbon);
begin
  inherited Create(AOwner, AOwner.GetTabClass);
  FOwner := AOwner;
end;

destructor TdxRibbonTabCollection.Destroy;
var
  I: Integer;
begin
  BarAccessibilityHelperOwnerObjectDestroyed(FIAccessibilityHelper);
  for I := Count - 1 downto 0 do
    Items[I].Free;
  inherited Destroy;
end;

function TdxRibbonTabCollection.Add: TdxRibbonTab;
begin
  Result := TdxRibbonTab(inherited Add);
end;

function TdxRibbonTabCollection.ContainsToolBar(AToolBar: TdxBar): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count - 1 do
  begin
    Result := Items[I].Groups.ContainsToolBar(AToolBar);
    if Result then Break;
  end;
end;

function TdxRibbonTabCollection.Insert(AIndex: Integer): TdxRibbonTab;
begin
  Result := TdxRibbonTab(inherited Insert(AIndex));
end;

function TdxRibbonTabCollection.IsMerged: Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count - 1 do 
    Result := Result or Items[I].IsMerged;
end;

function TdxRibbonTabCollection.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonTabCollectionAccessibilityHelper;
end;

function TdxRibbonTabCollection.Find(const ACaption: string): TdxRibbonTab;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if Items[I].Caption = ACaption then
    begin
      Result := Items[I];
      Break;
    end;
end;

function TdxRibbonTabCollection.FindByLoadedIndex(AIndex: Integer): TdxRibbonTab;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if Items[I].LoadedIndex = AIndex then
    begin
      Result := Items[I];
      Break;
    end;
end;

procedure TdxRibbonTabCollection.Notify(AItem: TcxComponentCollectionItem;
  AAction: TcxComponentCollectionNotification);
begin
  case AAction of
    ccnAdded:
      Owner.AddTab(TdxRibbonTab(AItem));
    ccnExtracted:
      Owner.RemoveTab(TdxRibbonTab(AItem));
  end;
  inherited;
end;

procedure TdxRibbonTabCollection.InternalUnmerge(ATab: TdxRibbonTab = nil);
var
  I: Integer;
begin
  BeginUpdate;
  try
    for I := Count - 1 downto 0 do
      Items[I].InternalUnmerge(ATab);
  finally
    EndUpdate;
  end;
end;

procedure TdxRibbonTabCollection.Update(AItem: TcxComponentCollectionItem;
  AAction: TcxComponentCollectionNotification);
begin
  inherited;
  if (AItem = nil) and not Owner.IsLocked then
    Owner.Changed;
end;

procedure TdxRibbonTabCollection.UpdateBarManager(ABarManager: TdxBarManager);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].UpdateBarManager(ABarManager);
end;

procedure TdxRibbonTabCollection.UpdateContexts;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].Context := FOwner.Contexts.GetItemFromIndex(Items[I].FContextIndex);
end;

procedure TdxRibbonTabCollection.RemoveContext(AContext: TdxRibbonContext);
var
  I: Integer;
begin
  if AContext <> nil then
  begin
    for I := 0 to Count - 1 do
    begin
      if Items[I].Context = AContext then
        Items[I].Context := nil;
    end;
    Changed;
  end;
end;

procedure TdxRibbonTabCollection.RestoreContexts;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].RestoreContext;
  UpdateContexts;
end;

procedure TdxRibbonTabCollection.RestoreOrder;
var
  I: Integer;
  AItem: TdxRibbonTab;
begin
  for I := 0 to Count - 1 do
  begin
    AItem := FindByLoadedIndex(I);
    if (AItem <> nil) and (AItem.LoadedIndex < Count) then
      AItem.RestoreIndex;
  end;
end;

procedure TdxRibbonTabCollection.SaveContexts;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].SaveContext;
end;

procedure TdxRibbonTabCollection.SetItemName(AItem: TcxComponentCollectionItem);
begin
  AItem.Name := CreateUniqueName(TdxRibbonTab(AItem).Ribbon.Owner,
    TdxRibbonTab(AItem).Ribbon, AItem, 'TdxRibbon', '');
end;

function TdxRibbonTabCollection.GetIAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  if FIAccessibilityHelper = nil then
    FIAccessibilityHelper := GetAccessibilityHelperClass.Create(Self);
  Result := FIAccessibilityHelper;
end;

function TdxRibbonTabCollection.GetItem(Index: Integer): TdxRibbonTab;
begin
  Result := TdxRibbonTab(inherited Items[Index]);
end;

procedure TdxRibbonTabCollection.SetItem(Index: Integer;
  const Value: TdxRibbonTab);
begin
  Items[Index].Assign(Value);
end;

{ TdxRibbonFonts }

constructor TdxRibbonFonts.Create(AOwner: TdxCustomRibbon);
var
  I: TdxRibbonAssignedFont;
begin
  inherited Create;
  FRibbon := AOwner;
  FDocumentNameColor := clDefault;
  FCaptionFont := TFont.Create;
  FInternalCaptionFont := TFont.Create;
  for I := Low(TdxRibbonAssignedFont) to High(TdxRibbonAssignedFont) do
  begin
    FFonts[I] := TFont.Create;
    FFonts[I].OnChange := FontChanged;
    FInternalFonts[I] := TFont.Create;
  end;
end;

destructor TdxRibbonFonts.Destroy;
var
  I: TdxRibbonAssignedFont;
begin
  for I := Low(TdxRibbonAssignedFont) to High(TdxRibbonAssignedFont) do
  begin
    FreeAndNil(FInternalFonts[I]);
    FreeAndNil(FFonts[I]);
  end;
  FreeAndNil(FInternalCaptionFont);
  FreeAndNil(FCaptionFont);
  inherited Destroy;
end;

procedure TdxRibbonFonts.Assign(Source: TPersistent);
var
  I: TdxRibbonAssignedFont;
begin
  if Source is TdxRibbonFonts then
  begin
    Ribbon.BeginUpdate;
    try
      FDocumentNameColor := TdxRibbonFonts(Source).DocumentNameColor;
      for I := Low(TdxRibbonAssignedFont) to High(TdxRibbonAssignedFont) do
        FFonts[I].Assign(TdxRibbonFonts(Source).FFonts[I]);
      FAssignedFonts := TdxRibbonFonts(Source).FAssignedFonts;
    finally
      Ribbon.EndUpdate;
    end;
  end
  else
    inherited Assign(Source);
end;

function TdxRibbonFonts.GetApplicationButtonFont(AState: TdxRibbonApplicationButtonState): TFont;
const
  StatesMap: array[TdxRibbonApplicationButtonState] of Integer = (DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED);
begin
  Result := GetInternalFont(afApplicationButton);
  Result.Color := GetPartColor(rspApplicationButton, StatesMap[AState]);
end;

function TdxRibbonFonts.GetContextFont(AContextColor: TColor = clDefault): TFont;
begin
  Result := GetInternalFont(afTabHeader);
  Ribbon.Painter.AdjustContextFont(Result, AContextColor);
end;

function TdxRibbonFonts.GetFormCaptionFont(AIsActive: Boolean): TFont;
begin
  Result := FInternalCaptionFont;
  Result.Assign(FCaptionFont);
  Result.Color := GetDefaultCaptionTextColor(AIsActive);
  Result.Size := Ribbon.ViewInfo.AdjustCaptionFontSize(Result.Size);
end;

function TdxRibbonFonts.GetGroupFont: TFont;
begin
  Result := GetInternalFont(afGroup);
end;

function TdxRibbonFonts.GetGroupHeaderFont: TFont;
begin
  Result := GetInternalFont(afGroupHeader);
  Result.Color := GetPartColor(rspTabGroupHeaderText);
end;

function TdxRibbonFonts.GetTabHeaderFont(AState: Integer; AContext: TdxRibbonContext): TFont;
begin
  Result := GetInternalFont(afTabHeader);
  if AContext <> nil then
    Ribbon.ColorScheme.AdjustContextTabFont(Result, AState, AContext.Color, Ribbon.ColorSchemeAccent)
  else
    Result.Color := GetPartColor(rspTabHeaderText, AState);
end;

function TdxRibbonFonts.GetPartColor(APart: Integer; AState: Integer = 0): TColor;
begin
  Result := Ribbon.SkinGetPartColor(APart, AState);
end;

procedure TdxRibbonFonts.Invalidate;
begin
  if Ribbon.Visible and (Ribbon.ActiveTab <> nil) then
    Ribbon.ActiveTab.UpdateColorScheme;
  Ribbon.RibbonFormInvalidate;
end;

procedure TdxRibbonFonts.UpdateFonts;
var
  AFont: TFont;
  AFontIndex: TdxRibbonAssignedFont;
begin
  FCaptionFont.Handle := CreateFontIndirect(dxSystemInfo.NonClientMetrics.lfCaptionFont);
  FLocked := True;
  try
    for AFontIndex := Low(TdxRibbonAssignedFont) to High(TdxRibbonAssignedFont) do
      if not (AFontIndex in AssignedFonts) then
      begin
        AFont := FFonts[AFontIndex];
        if Ribbon.IsBarManagerValid then
          AFont.Assign(Ribbon.BarManager.Font)
        else
          AFont.Assign(Ribbon.Font);

        case AFontIndex of
          afGroup:
            AFont.Color := GetPartColor(rspTabGroupText);
          afGroupHeader:
            AFont.Color := GetPartColor(rspTabGroupHeaderText);
        end;
      end;
  finally
    FLocked := False;
  end;
end;

procedure TdxRibbonFonts.FontChanged(Sender: TObject);
var
  I: TdxRibbonAssignedFont;
begin
  if not (Locked or Ribbon.IsLoading) then
  begin
    Ribbon.BeginUpdate;
    try
      for I := Low(TdxRibbonAssignedFont) to High(TdxRibbonAssignedFont) do
        if Sender = FFonts[I] then
        begin
          Include(FAssignedFonts, TdxRibbonAssignedFont(I));
          Break;
        end;
      UpdateGroupsFont;
    finally
      Ribbon.EndUpdate;
      Invalidate;
    end;
  end;
end;

function TdxRibbonFonts.GetDefaultCaptionTextColor(AIsActive: Boolean): TColor;

   function IsFormZoomed(AForm: TCustomForm): Boolean;
   begin
     Result := (AForm <> nil) and AForm.HandleAllocated and IsZoomed(AForm.Handle);
   end;

begin
  if Ribbon.ViewInfo.UseGlass then
  begin
    if IsWinSevenOrLater then
      Result := clBlack
    else
      if IsFormZoomed(Ribbon.RibbonForm) then
        Result := clWindow
      else
        if AIsActive then
          Result := clCaptionText
        else
          Result := clInactiveCaptionText
  end
  else
    Result := GetPartColor(rspFormCaptionText, Ord(not AIsActive));
end;

function TdxRibbonFonts.GetFont(const Index: Integer): TFont;
begin
  Result := FFonts[TdxRibbonAssignedFont(Index)]
end;

function TdxRibbonFonts.GetInternalFont(AIndex: TdxRibbonAssignedFont): TFont;
begin
  Result := FInternalFonts[AIndex];
  Result.Assign(FFonts[AIndex]);
end;

function TdxRibbonFonts.IsFontStored(const Index: Integer): Boolean;
begin
  Result := TdxRibbonAssignedFont(Index) in FAssignedFonts;
end;

procedure TdxRibbonFonts.SetAssignedFonts(const Value: TdxRibbonAssignedFonts);
begin
  if (FAssignedFonts <> Value) then
  begin
    FAssignedFonts := Value;
    UpdateFonts;
    FontChanged(nil);
  end;
end;

procedure TdxRibbonFonts.SetDocumentNameColor(const Value: TColor);
begin
  if FDocumentNameColor <> Value then
  begin
    FDocumentNameColor := Value;
    Ribbon.RibbonFormInvalidate;
  end;
end;

procedure TdxRibbonFonts.SetFont(const Index: Integer; const Value: TFont);
begin
  FFonts[TdxRibbonAssignedFont(Index)].Assign(Value);
end;

procedure TdxRibbonFonts.UpdateGroupsFont;
var
  I: Integer;
begin
  for I := 0 to Ribbon.TabCount - 1 do
    Ribbon.Tabs[I].UpdateGroupsFont;
end;

{ TdxRibbonComponentHelper }

constructor TdxRibbonHolderComponent.Create(AOwner: TComponent);
begin
  inherited Create;
  CheckAssignRibbon(AOwner);
end;

procedure TdxRibbonHolderComponent.CheckAssignRibbon(AOwner: TComponent);
begin
  if csDesigning in AOwner.ComponentState then
    Ribbon := FindRibbonForComponent(AOwner);
end;

procedure TdxRibbonHolderComponent.SetRibbon(Value: TdxCustomRibbon);
begin
  Component := Value;
end;

function TdxRibbonHolderComponent.GetRibbon: TdxCustomRibbon;
begin
  Result := TdxCustomRibbon(Component);
end;

{ TdxRibbonCustomPopupComponent }

constructor TdxRibbonCustomPopupComponent.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FRibbonHolder := TdxRibbonHolderComponent.Create(Self);
end;

destructor TdxRibbonCustomPopupComponent.Destroy;
begin
  FreeAndNil(FRibbonHolder);
  inherited Destroy;
end;

function TdxRibbonCustomPopupComponent.GetRibbon: TdxCustomRibbon;
begin
  Result := FRibbonHolder.Ribbon;
end;

procedure TdxRibbonCustomPopupComponent.SetRibbon(const Value: TdxCustomRibbon);
begin
  FRibbonHolder.Ribbon := Value;
end;

{ TdxRibbonCustomPopupMenu }

constructor TdxRibbonCustomPopupMenu.Create(AOwner: TComponent);
begin
  inherited;
  FRibbonHolder := TdxRibbonHolderComponent.Create(Self);
end;

destructor TdxRibbonCustomPopupMenu.Destroy;
begin
  FreeAndNil(FRibbonHolder);
  inherited;
end;

function TdxRibbonCustomPopupMenu.CreateBarControl: TCustomdxBarControl;
begin
  Result := inherited CreateBarControl;

  if Ribbon <> nil then
    TdxRibbonPopupMenuControl(Result).FPainter := Ribbon.GroupsPainter;
end;

function TdxRibbonCustomPopupMenu.GetControlClass: TCustomdxBarControlClass;
begin
  Result := TdxRibbonPopupMenuControl;
end;

procedure TdxRibbonCustomPopupMenu.SetRibbon(Value: TdxCustomRibbon);
begin
  FRibbonHolder.Ribbon := Value;
end;

function TdxRibbonCustomPopupMenu.GetRibbon: TdxCustomRibbon;
begin
  Result := FRibbonHolder.Ribbon;
end;

{ TdxRibbonPopupMenuControl }

function TdxRibbonPopupMenuControl.GetBehaviorOptions: TdxBarBehaviorOptions;
begin
  Result := dxRibbonBarBehaviorOptions +
    [bboAllowSelectWindowItemsWithoutFocusing, bboExtendItemWhenAlignedToClient] -
    [bboMouseCantUnselectNavigationItem, bboSubMenuCaptureMouse];
end;

{ TdxBarApplicationMenu }

function TdxBarApplicationMenu.ApplicationMenuPopup(
  ARibbon: TdxCustomRibbon; var AClosedByEscape: Boolean): Boolean;
var
  AOwnerBounds: TRect;
  AOwnerOffset: Integer;
  P: TPoint;
begin
  Result := True;
  FRibbonPainter := ARibbon.GroupsPainter;
  try
    P.Y := ARibbon.ViewInfo.TabsBounds.Top;
    P.X := ARibbon.ApplicationButtonViewInfo.Bounds.Left;
    AOwnerOffset := P.Y - ARibbon.ApplicationButtonViewInfo.ClientBounds.Top;
    AOwnerBounds := ARibbon.ApplicationButtonViewInfo.ClientBounds;
    P := ARibbon.ClientToScreen(P);
    PopupEx(P.X, P.Y, cxRectWidth(AOwnerBounds), AOwnerOffset, False, @AOwnerBounds, True, ARibbon);
    AClosedByEscape := FClosedByEscape;
  finally
    FRibbonPainter := nil;
  end;
end;

function TdxBarApplicationMenu.ClosePopup: Boolean;
begin
  Result := Visible;
  if Result then
    SubMenuControl.HideAll;
end;

procedure TdxBarApplicationMenu.DoCloseUp;
begin
  inherited DoCloseUp;
  FClosedByEscape := TdxBarSubMenuControlAccess(ItemLinks.BarControl).CloseUpReason = bcrEscape;
end;

procedure TdxBarApplicationMenu.DoPopup;
begin
  if FRibbonPainter <> nil then
    TCustomdxBarControlAccess(SubMenuControl).FPainter := FRibbonPainter;
  inherited DoPopup;
end;

function TdxBarApplicationMenu.GetControlClass: TCustomdxBarControlClass;
begin
  Result := TdxRibbonApplicationMenuControl;
end;

function TdxBarApplicationMenu.CanShowPopup(ARibbon: TdxCustomRibbon): Boolean;
begin
  Result := True;
end;

function TdxBarApplicationMenu.GetDisplayMode: TdxRibbonApplicationMenuDisplayMode;
begin
  Result := amdmPopup;
end;

procedure TdxBarApplicationMenu.Popup(X, Y: Integer);
begin
  if FRibbonPainter = nil then
    raise EdxException.Create(cxGetResourceString(@dxSBAR_APPMENUOUTSIDERIBBON));
  inherited Popup(X, Y);
end;

procedure TdxBarApplicationMenu.UpdateColorScheme;
begin
end;

procedure TdxBarApplicationMenu.UpdateNonClientArea;
begin
  // do nothing
end;

function TdxBarApplicationMenu.GetOrigin(AIsClientArea: Boolean): TPoint;
begin
  if AIsClientArea then
    Result := SubMenuControl.ClientOrigin
  else
    Result := cxGetWindowRect(SubMenuControl).TopLeft;
end;

procedure TdxBarApplicationMenu.GetTabOrderList(List: TList);
begin
  // do nothing
end;

function TdxBarApplicationMenu.GetRootAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  Result := nil;
end;

procedure TdxBarApplicationMenu.RibbonFormResized;
begin
end;

procedure TdxBarApplicationMenu.SelectAppMenuFirstItemControl;
begin
  SelectFirstSelectableAccessibleObject(ItemLinks.BarControl.IAccessibilityHelper.GetBarHelper);
end;

procedure TdxBarApplicationMenu.ShowKeyTips;
begin
  BarNavigationController.SetKeyTipsShowingState(ItemLinks.BarControl.IAccessibilityHelper, '');
end;

{ TdxRibbonApplicationMenuControl }

function TdxRibbonApplicationMenuControl.GetBehaviorOptions: TdxBarBehaviorOptions;
begin
  Result := inherited GetBehaviorOptions + [bboItemCustomizePopup];
end;

procedure TdxRibbonApplicationMenuControl.InitCustomizationPopup(AItemLinks: TdxBarItemLinks);
begin
  if Ribbon <> nil then
    Ribbon.PopulatePopupMenuItems(AItemLinks, GetPopupMenuItems, PopupMenuClick);
end;

function TdxRibbonApplicationMenuControl.GetPopupMenuItems: TdxRibbonPopupMenuItems;
begin
  Result := Ribbon.GetValidPopupMenuItems;
  if ExtraPaneItemLinks.IndexOf(BarDesignController.CustomizingItemLink) <> -1 then
    Exclude(Result, rpmiQATAddRemoveItem);
end;

procedure TdxRibbonApplicationMenuControl.PopupMenuClick(Sender: TObject); // see TdxRibbonCustomBarControl
var
  ALinkSelf: TcxObjectLink;
begin
  ALinkSelf := cxAddObjectLink(Self);
  try
    DoPopupMenuClick(Sender);
    if ALinkSelf.Ref <> nil then
      HideAll;
  finally
    cxRemoveObjectLink(ALinkSelf);
  end;
end;

function TdxRibbonApplicationMenuControl.GetRibbon: TdxCustomRibbon;
begin
  if OwnerControl is TdxCustomRibbon then
    Result := TdxCustomRibbon(OwnerControl)
  else
    Result := nil;
end;

procedure TdxRibbonApplicationMenuControl.DoPopupMenuClick(Sender: TObject);
begin
  Ribbon.PopupMenuItemClick(Sender);
end;

procedure TdxRibbonApplicationMenuControl.WMNCHitTest(var Message: TWMNCHitTest);
var
  ARect: TRect;
begin
  if (Ribbon <> nil) and Ribbon.HandleAllocated then
  begin
    ARect := dxMapWindowRect(Ribbon.Handle, 0, Ribbon.ApplicationButtonViewInfo.Bounds);
    if cxRectPtIn(ARect, SmallPointToPoint(Message.Pos)) then
      Message.Result := HTTRANSPARENT
    else
      inherited;
  end
  else
    inherited;
end;

{ TdxRibbonController }

constructor TdxRibbonController.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create;
  FRibbon := ARibbon;
  FHitInfo := TdxRibbonHitInfo.Create(ViewInfo);
  FHintInfo := TdxRibbonHitInfo.Create(ViewInfo);
  CreateTimer;
end;

destructor TdxRibbonController.Destroy;
begin
  FreeAndNil(FScrollTimer);
  FreeAndNil(FHitInfo);
  FreeAndNil(FHintInfo);
  inherited Destroy;
end;

function TdxRibbonController.NextTab(ATab: TdxRibbonTab): TdxRibbonTab;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to ViewInfo.TabsViewInfo.Count - 1 do
    if ViewInfo.TabsViewInfo[I].Tab = ATab then
    begin
      if I + 1 < ViewInfo.TabsViewInfo.Count then
      begin
        Result := ViewInfo.TabsViewInfo[I + 1].Tab;
        Exit;
      end;
    end;
  if (ATab = nil) and (ViewInfo.TabsViewInfo.Count > 0) then
    Result := ViewInfo.TabsViewInfo[0].Tab;
end;

function TdxRibbonController.PrevTab(ATab: TdxRibbonTab): TdxRibbonTab;
var
  I: Integer;
begin
  Result := nil;
  for I := ViewInfo.TabsViewInfo.Count - 1 downto 0 do
    if ViewInfo.TabsViewInfo[I].Tab = ATab then
    begin
      if I - 1 >= 0 then
      begin
        Result := ViewInfo.TabsViewInfo[I - 1].Tab;
        Exit;
      end;
    end;
  if (ATab = nil) and (ViewInfo.TabsViewInfo.Count > 0) then
    Result := ViewInfo.TabsViewInfo[ViewInfo.TabsViewInfo.Count - 1].Tab;
end;

procedure TdxRibbonController.DoScroll(AOnTimer: Boolean);
begin
  CancelHint;
  case FScrollKind of
    rhtTabScrollLeft, rhtTabScrollRight:
      ScrollTabs(FScrollKind = rhtTabScrollRight, AOnTimer);
    rhtGroupScrollLeft, rhtGroupScrollRight:
      ScrollGroups(FScrollKind = rhtGroupScrollRight, AOnTimer);
  end;
end;

procedure TdxRibbonController.InitTabDesignMenu(AItemLinks: TdxBarItemLinks);
begin
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONADDTAB), DesignTabMenuClick, 0);
  if BarDesignController.LastSelectedItem <> nil then
    BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
      cxGetResourceString(@dxSBAR_RIBBONDELETETAB), DesignTabMenuClick, 1);
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONADDEMPTYGROUP), DesignTabMenuClick, 2, True);
  BarDesignController.AddInternalItem(AItemLinks, TdxBarButton,
    cxGetResourceString(@dxSBAR_RIBBONADDGROUPWITHTOOLBAR), DesignTabMenuClick, 3);
end;

function TdxRibbonController.IsApplicationMenuDropped: Boolean;
begin
  Result := risAppMenuActive in Ribbon.InternalState;
end;

function TdxRibbonController.IsNeedShowHint(AObject: TdxRibbonHitTest): Boolean;
begin
  Result := IsOwnerForHintObject(AObject);
  if Result then
  begin
    case AObject of
      rhtTab:
        Result := (HintInfo.HitObjectAsTab <> nil) and ViewInfo.TabsViewInfo.NeedShowHint;
      rhtApplicationMenu:
        Result := (ApplicationButton.ScreenTip <> nil) and not IsApplicationMenuDropped;
      rhtHelpButton:
        Result := Ribbon.HelpButton.ScreenTip <> nil;
      rhtContext:
        Result := ViewInfo.ContextsViewInfo.NeedShowHint(HintInfo.HitObjectAsContext);
      rhtCustomButton:
        Result := HintInfo.HitObjectAsButton.Enabled and (HintInfo.HitObjectAsButton.Hint <> '');
    end;
  end;
end;

function TdxRibbonController.IsOwnerForHintObject(AObject: TdxRibbonHitTest): Boolean;
begin
  Result := AObject in [rhtTab, rhtApplicationMenu, rhtHelpButton, rhtCustomButton, rhtContext];
end;

procedure TdxRibbonController.HideHint;
begin
  if Ribbon.IsBarManagerValid then
    Ribbon.BarManager.HideHint;
end;

procedure TdxRibbonController.KeyDown(var Key: Word; Shift: TShiftState);
begin
  HideHint;
end;

procedure TdxRibbonController.KeyPress(var Key: Char);
begin
end;

procedure TdxRibbonController.KeyUp(var Key: Word; Shift: TShiftState);
begin
end;

procedure TdxRibbonController.MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  HideHint;
  if IsApplicationMenuDropped then
  begin
    if ApplicationMenuState = ramsShownAsMenu then
      ApplicationButton.ClosePopup;
  end;

  HitInfo.Calculate(Point(X, Y));
  case HitInfo.HitTest of
    rhtTab:
      ProcessTabOnMouseDown(Button, Shift);
    rhtApplicationMenu:
      if ProcessApplicationButtonMouseDown(Button, Shift) then
        Exit;
    rhtTabScrollLeft..rhtGroupScrollRight:
      if Button = mbLeft then
        StartScroll(HitInfo.HitTest);
  else
    if Button = mbRight then
    begin
      if cxRectPtIn(ViewInfo.TabsViewInfo.Bounds, X, Y) or
        (Ribbon.IsQuickAccessToolbarValid and ViewInfo.IsQATAtBottom and
        cxRectPtIn(ViewInfo.QuickAccessToolbarBounds, X, Y))
      then
        Ribbon.ShowCustomizePopup;
    end;
  end;
  if Button = mbLeft then
  begin
    PressedButton := HitInfo.HitObjectAsButton;
    PressedObject := HitInfo.HitTest;
  end;
  ProcessContextsOnMouseDown(ssDouble in Shift);

  if Ribbon.TabGroupsPopupWindow <> nil then
    Ribbon.TabGroupsPopupWindow.JustClosed; 
end;

procedure TdxRibbonController.MouseLeave;
begin
  if IsOwnerForHintObject(HintInfo.HitTest) then
    CancelHint;
  ApplicationButtonViewInfo.IsHot := False;
  Ribbon.HighlightedTab := nil;
  HotButton := nil;
  HotObject := rhtNone;
end;

procedure TdxRibbonController.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  HitInfo.Calculate(cxPoint(X, Y));
  ApplicationButtonViewInfo.IsHot := HitInfo.HitTest = rhtApplicationMenu;
  if not NotHandleMouseMove(cxPoint(X, Y)) then
  begin
    HotButton := HitInfo.HitObjectAsButton;
    Ribbon.HighlightedTab := HitInfo.HitObjectAsTab;
    HotObject := HitInfo.HitTest;
    HintInfo := HitInfo;
  end;
end;

procedure TdxRibbonController.MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  CancelScroll;
  HitInfo.Calculate(cxPoint(X, Y));
  if Button = mbLeft then
  begin
    ReleaseCapture;
    if HitInfo.HitObject = PressedButton then
    begin
      if (PressedButton <> nil) and PressedButton.Enabled then
        PressedButton.Click;
    end;
    PressedButton := nil;
    PressedObject := rhtNone;
  end;
  if (FPressedContext <> nil) and (HitInfo.HitObject = FPressedContext) then
  begin
    FPressedContext.Activate;
    FPressedContext := nil;
  end;
end;

function TdxRibbonController.MouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean;
var
  ATab: TdxRibbonTab;
begin
  ATab := NextTab(Ribbon.ActiveTab);
  Result := (ATab <> nil) and Ribbon.CanScrollTabs;
  if Result then
    Ribbon.ActiveTab := ATab;
end;

function TdxRibbonController.MouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean;
var
  ATab: TdxRibbonTab;
begin
  ATab := PrevTab(Ribbon.ActiveTab);
  Result := (ATab <> nil) and Ribbon.CanScrollTabs;
  if Result then
    Ribbon.ActiveTab := ATab;
end;

function TdxRibbonController.DoHint(var ANeedDeactivate: Boolean; out AHintText: string; out AShortCut: string): Boolean;
begin
  ANeedDeactivate := False;
  Result := IsNeedShowHint(HintInfo.HitTest);
  AHintText := '';
  AShortCut := '';
  if Result then
  begin
    case HintInfo.HitTest of
      rhtTab:
        AHintText := HintInfo.HitObjectAsTab.Caption;
      rhtApplicationMenu:
        AHintText := ApplicationButton.ScreenTip.Header.Text;
      rhtHelpButton:
        AHintText := Ribbon.HelpButton.ScreenTip.Header.Text;
      rhtCustomButton:
        AHintText := HintInfo.HitObjectAsButton.Hint;
      rhtContext:
        AHintText := HintInfo.HitObjectAsContext.Caption;
    end;
  end;
end;

function TdxRibbonController.CreateHintViewInfo(const AHintText, AShortCut: string): TdxBarCustomHintViewInfo;
var
  ABarManager: TdxBarManager;
  AScreenTip: TdxScreenTip;
begin
  if Ribbon.IsBarManagerValid then
    ABarManager := Ribbon.BarManager
  else
    ABarManager := nil;

  case HintInfo.HitTest of
    rhtApplicationMenu:
      AScreenTip := ApplicationButton.ScreenTip;
    rhtHelpButton:
      AScreenTip := Ribbon.HelpButton.ScreenTip;
    else
      AScreenTip := nil;
  end;
  Result := dxBarCreateScreenTipViewInfo(ABarManager, AHintText, AShortCut, AScreenTip, Ribbon.GroupsPainter);
end;

function TdxRibbonController.GetEnabled: Boolean;
begin
  Result := True;
end;

function TdxRibbonController.GetHintPosition(const ACursorPos: TPoint; AHeight: Integer): TPoint;
var
  R: TRect;
begin
  if HintInfo.HitTest = rhtApplicationMenu then
  begin
    R := ApplicationButtonViewInfo.Bounds;
    Result := cxPoint(R.Left, R.Bottom);
    Result := Ribbon.ClientToScreen(Result);
    if GetDesktopWorkArea(Result).Bottom - Result.Y < AHeight then
    begin
      Result := Ribbon.ClientToScreen(cxPoint(R.Left, 0));
      Dec(Result.Y, AHeight);
    end;
  end
  else
    Result := cxPoint(ACursorPos.X, ACursorPos.Y + dxRibbonHintOffset);
end;

procedure TdxRibbonController.CancelHint;
begin
  HintInfo.Reset;
  HideHint;
end;

procedure TdxRibbonController.CancelMode;
begin
  Ribbon.HighlightedTab := nil;
  CancelScroll;
  CancelHint;
end;

function TdxRibbonController.CanSwitchMinimizedOnDblClick: Boolean;
begin
  Result := not Ribbon.IsDesigning and Ribbon.MinimizeOnTabDblClick and
    (not Ribbon.ShowTabGroups or (not FSkipDblClick and HitInfo.HitObjectAsTab.Active));
end;

function TdxRibbonController.CloseApplicationMenu: Boolean;
begin
  Result := IsApplicationMenuDropped;
  if Result then
    ApplicationButton.ClosePopup;
end;

procedure TdxRibbonController.DesignTabMenuClick(Sender: TObject);
begin
  case TdxBarButton(Sender).Tag of
    0: Ribbon.Tabs.Add;
    1: BarDesignController.DeleteSelectedObjects(True, True);
    2: Ribbon.DesignAddTabGroup(nil, False);
    3: Ribbon.DesignAddTabGroup(nil, True);
  end;
  Ribbon.Modified;
end;

procedure TdxRibbonController.ScrollGroups(AScrollLeft, AOnTimer: Boolean);
begin
  Ribbon.ActiveTab.ScrollDockControlGroups(AScrollLeft, AOnTimer);
end;

procedure TdxRibbonController.ScrollTabs(AScrollLeft, AOnTimer: Boolean);
const
  ScrollDelta: array[Boolean, Boolean] of Integer = ((-dxRibbonTabMinWidth div 2, dxRibbonTabMinWidth div 2), (-3, 3));
begin
  with ViewInfo.TabsViewInfo do
    ScrollPosition := ScrollPosition + ScrollDelta[AOnTimer, AScrollLeft];
end;

procedure TdxRibbonController.SetHintInfo(const Value: TdxRibbonHitInfo);
var
  ANeedHide: Boolean;
begin
  if Ribbon.IsLocked or not Ribbon.IsBarManagerValid then
    Exit;

  if not HintInfo.Compare(Value) then
  begin
    ANeedHide := IsOwnerForHintObject(HintInfo.HitTest);
    HintInfo.HitObject := Value.HitObject;
    HintInfo.HitTest := Value.HitTest;
    if IsOwnerForHintObject(HintInfo.HitTest) then
      Ribbon.BarManager.ActivateHint(True, '', Self)
    else
      if ANeedHide then
        HideHint;
  end;
end;

procedure TdxRibbonController.SetHotButton(AValue: TdxRibbonCustomButtonViewInfo);
begin
  if FHotButton <> AValue then
  begin
    FHotButton := AValue;
    UpdateButtonsStates;
  end;
end;

procedure TdxRibbonController.SetPressedButton(AValue: TdxRibbonCustomButtonViewInfo);
begin
  if FPressedButton <> AValue then
  begin
    FPressedButton := AValue;
    UpdateButtonsStates;
  end;
end;

procedure TdxRibbonController.SetPressedObject(const Value: TdxRibbonHitTest);
begin
  if FPressedObject <> Value then
  begin
    FPressedObject := Value;
    if not (FPressedObject in [rhtNone, rhtTab, rhtApplicationMenu]) then
      SetCapture(Ribbon.Handle);
  end;
end;

procedure TdxRibbonController.ShowTabDesignMenu;
begin
  BarDesignController.ShowCustomCustomizePopup(
    Ribbon.BarManager, InitTabDesignMenu, Ribbon.GroupsPainter);
end;

function TdxRibbonController.NotHandleMouseMove(P: TPoint): Boolean;
begin
  if Ribbon.IsBarManagerValid and not Ribbon.IsDesigning then
    Result := (FScrollKind <> rhtNone) or not (IsFormActive(Ribbon.BarManager.ParentForm) or
      IsFormActive(Ribbon.TabGroupsPopupWindow)) or dxBarHasPopupWindowAbove(nil, False)
  else
    Result := True;
end;

function TdxRibbonController.ProcessApplicationButtonMouseDown(
  Button: TMouseButton; AShift: TShiftState): Boolean;
var
  ARibbonParentForm: TCustomForm;
begin
  Result := False;
  if Button = mbLeft then
  begin
    if ssDouble in AShift then
    begin
      if Ribbon.Style = rs2007 then
      begin
        ARibbonParentForm := GetParentForm(Ribbon);
        if ARibbonParentForm <> nil then
          ARibbonParentForm.Close;
      end;
    end
    else
      if not CloseApplicationMenu then
      begin
        if CloseActiveRibbonApplicationMenus then
        begin
          PostMessage(Ribbon.Handle, DXM_RIBBON_SHOWAPPLICATIONMENU, 0, 0);
          Result := True;
        end
        else
          Result := Ribbon.ApplicationMenuPopup;
      end;
  end;
end;

procedure TdxRibbonController.ProcessContextsOnMouseDown(AIsDoubleClick: Boolean);
var
  AForm: TForm;
begin
  if HitInfo.HitTest = rhtContext then
  begin
    FPressedContext := HitInfo.HitObjectAsContext;
    CloseApplicationMenu;
    if AIsDoubleClick then
    begin
      FPressedContext := nil;
      AForm := Ribbon.RibbonForm;
      if AForm.WindowState = wsNormal then
        AForm.WindowState := wsMaximized
      else if AForm.WindowState = wsMaximized then
        AForm.WindowState := wsNormal;
    end
    else
      if not Ribbon.ShowTabGroups and (Ribbon.TabGroupsPopupWindow = nil) then
        Ribbon.ShowTabGroups := True;
  end
  else
    FPressedContext := nil;
end;

procedure TdxRibbonController.ProcessTabClick(ATab: TdxRibbonTab; Button: TMouseButton; Shift: TShiftState);
begin
  if CanProcessDesignTime then
  begin
    Ribbon.ActiveTab := ATab;
    BarDesignController.SelectItem(ATab);
    if Button = mbRight then
      ShowTabDesignMenu;
  end;

  if Ribbon.IsDesigning then
    Exit;

  case Button of
    mbRight:
      Ribbon.ShowCustomizePopup;
    mbLeft:
      if (ssDouble in Shift) or Ribbon.ShowTabGroups then
        Ribbon.ActiveTab := ATab
      else
        if (Ribbon.ActiveTab <> ATab) or (Ribbon.TabGroupsPopupWindow = nil) or not Ribbon.TabGroupsPopupWindow.JustClosed then
        begin
          Ribbon.ActiveTab := ATab;
          Ribbon.ShowTabGroupsPopupWindow;
        end;
  end;
end;

procedure TdxRibbonController.ProcessTabOnMouseDown(AButton: TMouseButton; AShift: TShiftState);
var
  APrevActiveTab: TdxRibbonTab;
begin
  CloseApplicationMenu;
  APrevActiveTab := Ribbon.ActiveTab;
  if (AButton = mbLeft) and (ssDouble in AShift) and CanSwitchMinimizedOnDblClick then
    Ribbon.ShowTabGroups := not Ribbon.ShowTabGroups
  else
    ProcessTabClick(HitInfo.HitObjectAsTab, AButton, AShift);
  FSkipDblClick := APrevActiveTab <> Ribbon.ActiveTab;
end;

procedure TdxRibbonController.CancelScroll;
begin
  FScrollKind := rhtNone;
  FScrollTimer.Enabled := False;
  UpdateButtonsStates;
end;

function TdxRibbonController.CanProcessDesignTime: Boolean;
begin
  Result := Ribbon.IsDesigning and Ribbon.IsBarManagerValid;
end;

procedure TdxRibbonController.CreateTimer;
begin
  FScrollTimer := TcxTimer.Create(nil);
  FScrollTimer.Enabled := False;
  FScrollTimer.OnTimer := ScrollTimerHandler;
end;

function TdxRibbonController.GetViewInfo: TdxRibbonViewInfo;
begin
  Result := Ribbon.ViewInfo;
end;

function TdxRibbonController.GetApplicationButton: TdxRibbonApplicationButton;
begin
  Result := Ribbon.ApplicationButton;
end;

function TdxRibbonController.GetApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo;
begin
  Result := ViewInfo.ApplicationButtonViewInfo;
end;

function TdxRibbonController.GetApplicationMenuState: TdxRibbonApplicationMenuState;
const
  StateMap: array[TdxRibbonApplicationMenuDisplayMode] of TdxRibbonApplicationMenuState = (
    ramsShownAsMenu, ramsShownAsFrame, ramsShownAsFullScreenFrame
  );
begin
  if IsApplicationMenuDropped then
    Result := StateMap[ApplicationButton.IMenu.GetDisplayMode]
  else
    Result := ramsHidden;
end;

procedure TdxRibbonController.StartScroll(AScrollKind: TdxRibbonHitTest);
begin
  if AScrollKind in [rhtTabScrollLeft..rhtGroupScrollRight] then
  begin
    FScrollKind := AScrollKind;
    FScrollTimer.Interval := dxRibbonScrollDelay;
    DoScroll(False);
    FScrollTimer.Enabled := True;
  end;
end;

procedure TdxRibbonController.UpdateButtonsStates;
begin
  ViewInfo.UpdateButtonsStates;
end;

procedure TdxRibbonController.ScrollTimerHandler(Sender: TObject);
begin
  FScrollTimer.Interval := dxRibbonScrollInterval;
  HitInfo.Calculate(Ribbon.ScreenToClient(GetMouseCursorPos));
  if HitInfo.HitTest = FScrollKind then
    DoScroll(True);
end;

{ TdxRibbonGroupsDockControlScrollButtonViewInfo }

procedure TdxRibbonGroupsDockControlScrollButtonViewInfo.Draw(ACanvas: TcxCanvas);
begin
  inherited Draw(ACanvas);
  ACanvas.ExcludeClipRect(Bounds);
end;

procedure TdxRibbonGroupsDockControlScrollButtonViewInfo.DrawButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawGroupsScrollButton(ACanvas, R, FScrollButton = rsbLeft, AState);
end;

procedure TdxRibbonGroupsDockControlScrollButtonViewInfo.DrawButtonGlyph(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  Painter.DrawGroupsScrollButtonArrow(ACanvas, R, FScrollButton = rsbLeft);
end;

function TdxRibbonGroupsDockControlScrollButtonViewInfo.GetHitInfo(const AHitInfo: TdxRibbonHitInfo): Boolean;
const
  HitTestMap: array[TdxRibbonScrollButton] of TdxRibbonHitTest = (rhtGroupScrollLeft, rhtGroupScrollRight);
begin
  Result := inherited GetHitInfo(AHitInfo);
  if Result then
    AHitInfo.HitTest := HitTestMap[FScrollButton];
end;

{ TdxRibbonGroupsDockControlSiteViewInfo }

constructor TdxRibbonGroupsDockControlSiteViewInfo.Create(ASite: TdxRibbonGroupsDockControlSite);

  function AddButton(AScrollButton: TdxRibbonScrollButton): TdxRibbonGroupsDockControlScrollButtonViewInfo;
  begin
    Result := TdxRibbonGroupsDockControlScrollButtonViewInfo.Create(Self);
    Result.FScrollButton := AScrollButton;
    AddItem(Result);
  end;

begin
  FSite := ASite;
  inherited Create(RibbonViewInfo);
  FTabGroupsScrollButtonLeft := AddButton(rsbLeft);
  FTabGroupsScrollButtonRight := AddButton(rsbRight);
  FMinimizeRibbonButton := TdxRibbonMinimizeButtonViewInfo.Create(Self);
  AddItem(FMinimizeRibbonButton);
end;

procedure TdxRibbonGroupsDockControlSiteViewInfo.Calculate(const ABounds: TRect);
begin
  if RibbonViewInfo.IsTabGroupsVisible and (RibbonActiveTab <> nil) then
    FTabGroupsScrollButtons := RibbonActiveTab.DockControl.ViewInfo.ScrollButtons
  else
    FTabGroupsScrollButtons := [];

  inherited Calculate(ABounds);
end;

procedure TdxRibbonGroupsDockControlSiteViewInfo.CalculateButtonsBounds(const ABounds: TRect);

  function CalculateMinimizeRibbonButtonBounds: TRect;
  var
    ASize: TSize;
  begin
    ASize := GetMinimizeRibbonButtonSize;
    Result := cxRectSetRight(ABounds, ABounds.Right, ASize.cx);
    Result := cxRectSetBottom(Result, Result.Bottom, ASize.cy);
    Result := cxRectOffset(Result, RibbonViewInfo.GetTabGroupsContentOffset.BottomRight, False);
  end;

  procedure CalculateScrollButtons(AButtonWidth: Integer);
  var
    ARightSide: Integer;
  begin
    if cxRectIsEmpty(FMinimizeRibbonButton.Bounds) then
      ARightSide := ABounds.Right
    else
      ARightSide := FMinimizeRibbonButton.Bounds.Left;

    TabGroupsScrollButtonLeft.Bounds := cxRectSetWidth(
      ABounds, IfThen(rsbLeft in TabGroupsScrollButtons, AButtonWidth));
    TabGroupsScrollButtonRight.Bounds := cxRectSetRight(
      ABounds, ARightSide, IfThen(rsbRight in TabGroupsScrollButtons, AButtonWidth));
  end;

begin
  FMinimizeRibbonButton.Bounds := CalculateMinimizeRibbonButtonBounds;
  CalculateScrollButtons(RibbonViewInfo.ScrollButtonWidth);
end;

procedure TdxRibbonGroupsDockControlSiteViewInfo.Draw(ACanvas: TcxCanvas);
begin
  Ribbon.Painter.DrawGroupsArea(ACanvas, Bounds);
  DrawRibbonParts(ACanvas);
  inherited Draw(ACanvas);
end;

procedure TdxRibbonGroupsDockControlSiteViewInfo.DrawRibbonParts(ACanvas: TcxCanvas);
var
  ASavedOrg: TPoint;
begin
  ASavedOrg := ACanvas.WindowOrg;
  try
    ACanvas.WindowOrg := dxMapWindowPoint(FSite.Handle, Ribbon.Handle, ASavedOrg);
    RibbonViewInfo.ApplicationButtonViewInfo.Draw(ACanvas);
    ACanvas.ExcludeClipRect(RibbonViewInfo.ApplicationButtonViewInfo.Bounds);

    if (RibbonActiveTab <> nil) and (RibbonActiveTab.ViewInfo <> nil) then
    begin
      ACanvas.SaveClipRegion;
      try
        ACanvas.IntersectClipRect(RibbonViewInfo.TabsViewInfo.GetRealBounds);
        RibbonActiveTab.ViewInfo.Paint(ACanvas);
      finally
        ACanvas.RestoreClipRegion;
      end;
    end;
  finally
    ACanvas.WindowOrg := ASavedOrg;
  end;
end;

procedure TdxRibbonGroupsDockControlSiteViewInfo.InvalidateRect(const R: TRect);
begin
  if FSite.HandleAllocated then
    cxInvalidateRect(FSite.Handle, R);
end;

function TdxRibbonGroupsDockControlSiteViewInfo.GetMinimizeRibbonButtonSize: TSize;
begin
  if Ribbon.Style = rs2013 then
    Result := cxGetValueCurrentDPI(cxSize(30, 17))
  else
    Result := cxNullSize;
end;

function TdxRibbonGroupsDockControlSiteViewInfo.GetRibbonActiveTab: TdxRibbonTab;
begin
  Result := FSite.Ribbon.ActiveTab;
end;

function TdxRibbonGroupsDockControlSiteViewInfo.GetRibbonViewInfo: TdxRibbonViewInfo;
begin
  Result := FSite.Ribbon.ViewInfo;
end;

{ TdxRibbonGroupsDockControlSite }

constructor TdxRibbonGroupsDockControlSite.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create(ARibbon);
  FRibbon := ARibbon;
  FViewInfo := TdxRibbonGroupsDockControlSiteViewInfo.Create(Self);
  DoubleBuffered := True;
end;

destructor TdxRibbonGroupsDockControlSite.Destroy;
begin
  FreeAndNil(FViewInfo);
  inherited Destroy;
end;

function TdxRibbonGroupsDockControlSite.CanFocus: Boolean;
begin
  Result := False;
end;

// IdxGestureClient
function TdxRibbonGroupsDockControlSite.AllowPan(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := (AScrollKind = sbHorizontal) and (ViewInfo.TabGroupsScrollButtons <> []);
end;

procedure TdxRibbonGroupsDockControlSite.BeginGestureScroll(APos: TPoint);
begin
  inherited BeginGestureScroll(APos);
//  if Ribbon.IsBarManagerValid then
//    Ribbon.BarManager.HideAll;
end;

procedure TdxRibbonGroupsDockControlSite.GestureScroll(ADeltaX, ADeltaY: Integer);
begin
  DockControl.ViewInfo.InternalScrollGroups(ADeltaX,
    Width - cxMarginsWidth(Ribbon.ViewInfo.GetTabGroupsDockControlOffset));
  Update;
end;

function TdxRibbonGroupsDockControlSite.IsPanArea(const APoint: TPoint): Boolean;
begin
  Result := True;
end;

function TdxRibbonGroupsDockControlSite.NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := False;
end;

function TdxRibbonGroupsDockControlSite.IsGestureTarget(AWnd: THandle): Boolean;
begin
  Result := IsChildEx(Handle, AWnd);
end;

procedure TdxRibbonGroupsDockControlSite.AlignControls(AControl: TControl;
  var Rect: TRect);
begin
end;

procedure TdxRibbonGroupsDockControlSite.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.WindowClass.style := Params.WindowClass.style and not (CS_VREDRAW or CS_HREDRAW);
end;

procedure TdxRibbonGroupsDockControlSite.DoCancelMode;
begin
  inherited DoCancelMode;
  Ribbon.Controller.CancelMode;
end;

function TdxRibbonGroupsDockControlSite.DoMouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean;
begin
  Result := inherited DoMouseWheelDown(Shift, MousePos);
  if not Result then
    Result := Ribbon.Controller.MouseWheelDown(Shift, MousePos);
end;

function TdxRibbonGroupsDockControlSite.DoMouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean;
begin
  Result := inherited DoMouseWheelUp(Shift, MousePos);
  if not Result then
    Result := Ribbon.Controller.MouseWheelUp(Shift, MousePos);
end;

function TdxRibbonGroupsDockControlSite.MayFocus: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonGroupsDockControlSite.MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseDown(Button, Shift, X, Y);
  with Ribbon.ScreenToClient(ClientToScreen(Point(X, Y))) do
    Ribbon.Controller.MouseDown(Button, Shift, X, Y);
end;

procedure TdxRibbonGroupsDockControlSite.MouseLeave(AControl: TControl);
begin
  inherited MouseLeave(AControl);
  Ribbon.Controller.MouseLeave;
end;

procedure TdxRibbonGroupsDockControlSite.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseMove(Shift, X, Y);
  with Ribbon.ScreenToClient(ClientToScreen(Point(X, Y))) do
    Ribbon.Controller.MouseMove(Shift, X, Y);
end;

procedure TdxRibbonGroupsDockControlSite.MouseUp(Button: TMouseButton;
  Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  with Ribbon.ScreenToClient(ClientToScreen(Point(X, Y))) do
    Ribbon.Controller.MouseUp(Button, Shift, X, Y);
end;

function TdxRibbonGroupsDockControlSite.NeedsScrollBars: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonGroupsDockControlSite.Paint;
begin
  ViewInfo.Draw(Canvas);
end;

procedure TdxRibbonGroupsDockControlSite.SetRedraw(ARedraw: Boolean);
begin
  if HandleAllocated then
  begin
    SendMessage(Handle, WM_SETREDRAW, Ord(ARedraw), 0);
    if ARedraw and IsWindowVisible(Handle) then
      InvalidateWithChildren;
  end;
end;

function TdxRibbonGroupsDockControlSite.GetDockControl: TdxRibbonGroupsDockControl;
begin
  Result := Ribbon.ActiveTab.DockControl;
end;

{ TdxRibbonOptionsFading }

constructor TdxRibbonOptionsFading.Create;
begin
  FApplicationButton := TdxFadingOptions.Create;
  FBarItems := TdxFadingOptions.Create;
  FTabGroups := TdxFadingOptions.Create;
  FTabs := TdxFadingOptions.Create;
end;

destructor TdxRibbonOptionsFading.Destroy;
begin
  FreeAndNil(FApplicationButton);
  FreeAndNil(FBarItems);
  FreeAndNil(FTabGroups);
  FreeAndNil(FTabs);
  inherited Destroy;
end;

procedure TdxRibbonOptionsFading.Assign(Source: TPersistent);
begin
  if Source is TdxRibbonOptionsFading then
  begin
    ApplicationButton := TdxRibbonOptionsFading(Source).ApplicationButton;
    BarItems := TdxRibbonOptionsFading(Source).BarItems;
    TabGroups := TdxRibbonOptionsFading(Source).TabGroups;
    Tabs := TdxRibbonOptionsFading(Source).Tabs;
  end
  else
    inherited Assign(Source);
end;

procedure TdxRibbonOptionsFading.SetApplicationButton(AValue: TdxFadingOptions);
begin
  FApplicationButton.Assign(AValue);
end;

procedure TdxRibbonOptionsFading.SetBarItems(AValue: TdxFadingOptions);
begin
  FBarItems.Assign(AValue);
end;

procedure TdxRibbonOptionsFading.SetTabGroups(AValue: TdxFadingOptions);
begin
  FTabGroups.Assign(AValue);
end;

procedure TdxRibbonOptionsFading.SetTabs(AValue: TdxFadingOptions);
begin
  FTabs.Assign(AValue);
end;

{ TdxRibbonTouchModeHelper }

constructor TdxRibbonTouchModeHelper.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create;
  FRibbon := ARibbon;
end;

procedure TdxRibbonTouchModeHelper.AdjustFormBorderIconSize(
  AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean; var ASize: TSize);
var
  AScaleFactor: Single;
begin
  if IsEnabled and (ASize.cx > 0) then
  begin
    AScaleFactor := Max(1, cxGetValueCurrentDPI(29) / ASize.cy);
    ASize.cx := Trunc(ASize.cx * AScaleFactor);
    ASize.cy := Trunc(ASize.cy * AScaleFactor);
  end;
end;

procedure TdxRibbonTouchModeHelper.AdjustFormCaptionHeight(var AValue: Integer);
begin
  if IsEnabled then
    AValue := Max(AValue, cxGetValueCurrentDPI(48));
end;

procedure TdxRibbonTouchModeHelper.AdjustMargins(var AMargins: TRect; AMaxTargetValue: Integer);
var
  AMaxValue: Integer;
begin
  if IsEnabled then
  begin
    AMaxValue := MaxIntValue([1, AMargins.Left, AMargins.Top, AMargins.Right, AMargins.Bottom]);
    AMaxTargetValue := cxGetValueCurrentDPI(AMaxTargetValue);
    if AMaxValue < AMaxTargetValue then
      AMargins := cxRectScale(AMargins, AMaxTargetValue, AMaxValue);
  end;
end;

procedure TdxRibbonTouchModeHelper.AdjustPartOffsets(APart: Integer; var AValue: TRect);
const
  TargetValue = 7; 
begin
  if IsEnabled then
  begin
    AdjustMargins(AValue, TargetValue);
    if APart = DXBAR_APPLICATIONMENUCONTENT then
      AValue.Bottom := cxGetValueCurrentDPI(25)+  cxMarginsHeight(Ribbon.SkinGetContentOffsets(DXBAR_APPLICATIONMENUBUTTON));
  end;
end;

procedure TdxRibbonTouchModeHelper.AdjustPartSize(APart: Integer; var AValue: Integer);
begin
  // do nothing
end;

function TdxRibbonTouchModeHelper.IsEnabled: Boolean;
begin
  Result := cxIsTouchModeEnabled;
end;

{ TdxCustomRibbon }

constructor TdxCustomRibbon.Create(AOwner: TComponent);
begin
  Include(FInternalState, risCreating);
  RibbonCheckCreateComponent(AOwner, ClassType);
  Exclude(FInternalState, risCreating);
  inherited Create(AOwner);
  DoubleBuffered := True;
  FOptionsFading := TdxRibbonOptionsFading.Create;
  FPainter := CreatePainter;
  FHorizontalNavigationList := TInterfaceList.Create;
  FViewInfo := CreateViewInfo;
  FListeners := TInterfaceList.Create;
  FGroupsDockControlSite := TdxRibbonGroupsDockControlSite.Create(Self);
  FGroupsDockControlSite.Parent := Self;
  FGroupsPainter := CreateGroupsPainter;
  FFonts := TdxRibbonFonts.Create(Self);
  FContexts := TdxRibbonContexts.Create(Self);
  FTabs := TdxRibbonTabCollection.Create(Self);
  FMergeData := TdxRibbonMergeData.Create;
  Align := alTop;
  FShowTabGroups := True;
  FShowTabHeaders := True;
  FEnableTabAero := True;
  FApplicationButton := CreateApplicationButton;
  FHelpButton := CreateHelpButton;
  FQuickAccessToolbar := CreateQuickAccessToolbar;
  FController := CreateController;
  FTouchModeHelper := CreateTouchModeHelper;
  FPopupMenuItems := dxRibbonDefaultPopupMenuItems;
  FColorSchemeHandlers := TcxEventHandlerCollection.Create;
  FAffiliatedBarControlsForAccessibility := TComponentList.Create(False);

  FLockModified := True;
  try
    InitColorScheme;
    FGroupsPainter.CalculateDrawParams;
    if IsDesigning then
    begin
      BarManager := GetBarManagerByComponent(AOwner);
      if (FBarManager = nil) and (dxBarManagerList.Count > 0) then
        BarManager := TdxBarManager(dxBarManagerList[0]);
      Tabs.Add;
    end;
  finally
    FLockModified := False;
  end;
  Fading := True;
  FInternalItems := TComponentList.Create;
  FRibbonFormNonClientParts := TObjectList.Create(False);
  FMinimizeOnTabDblClick := True;
  InitializeRibbonForm;
end;

destructor TdxCustomRibbon.Destroy;
begin
  if risCreating in FInternalState then Exit;
  UnmergeBeforeDestroy;
  SupportNonClientDrawing := False;
  FreeAndNil(FRibbonFormNonClientParts);
  FreeAndNil(FTabGroupsPopupWindow);
  FreeAndNil(FInternalItems);
  FreeAndNil(FController);
  FreeAndNil(FAffiliatedBarControlsForAccessibility);
  FreeAndNil(FColorSchemeHandlers);
  BarManager := nil;
  FreeAndNil(FHelpButton);
  FreeAndNil(FApplicationButton);
  FreeAndNil(FQuickAccessToolbar);
  FreeAndNil(FMergeData);
  FreeAndNil(FTabs);
  FreeAndNil(FContexts);
  FreeAndNil(FViewInfo);
  FreeAndNil(FTouchModeHelper);
  FreeAndNil(FHorizontalNavigationList);
  FreeAndNil(FGroupsPainter);
  FreeAndNil(FListeners);
  FreeAndNil(FPainter);
  FreeAndNil(FOptionsFading);
  FreeAndNil(FFonts);
  inherited Destroy;
end;

function TdxCustomRibbon.ApplicationMenuPopup: Boolean;
var
  AClosedByEscape: Boolean;
  AObjectLink: TcxObjectLink;
begin
  Result := False;
  if not Controller.IsApplicationMenuDropped then
  begin
    AObjectLink := cxAddObjectLink(Self);
    try
      ApplicationButtonViewInfo.IsPressed := True;
      try
        if DoApplicationMenuClick or (ApplicationButton.IMenu = nil) then
          BarNavigationController.StopKeyboardHandling
        else
          if ApplicationButton.CanShowPopup then
          begin
            BeforeApplicationMenuPopup;
            Result := ApplicationButton.Popup(AClosedByEscape);
            if AObjectLink.Ref <> nil then
            begin
              if Result and AClosedByEscape and BarNavigationController.NavigationMode then
                ApplicationButton.IAccessibilityHelper.Select(False);
              AfterApplicationMenuPopup;
            end;
          end;
      finally
        if AObjectLink.Ref <> nil then
        begin
          ApplicationButtonViewInfo.IsPressed := False;
          Controller.PressedObject := rhtNone;
        end;
      end;
    finally
      cxRemoveObjectLink(AObjectLink);
    end;
  end;
end;

function TdxCustomRibbon.AreGroupsVisible: Boolean;
begin
  Result := not Hidden and (ShowTabGroups or IsPopupGroupsMode);
end;

procedure TdxCustomRibbon.BeginUpdate;
begin
  Inc(FLockCount);
  GroupsDockControlSite.SetRedraw(False);
end;

function TdxCustomRibbon.CanFocus: Boolean;
begin
  Result := False;
end;

procedure TdxCustomRibbon.CheckHide;
var
  AForm: TCustomForm;
  DC: HDC;
begin
  if Hidden <> ViewInfo.IsNeedHideControl then
  begin
    AForm := GetParentForm(Self{$IFDEF DELPHI8}, False{$ENDIF});
    if not Hidden and (AForm <> nil) and AForm.HandleAllocated then
    begin
      Changed;
      AForm.Invalidate;
      DC := GetDC(AForm.Handle);
      try
        SendMessage(AForm.Handle, WM_ERASEBKGND, DC, DC);
      finally
        ReleaseDC(AForm.Handle, DC);
      end;
    end
    else
      Changed;
  end;
end;

procedure TdxCustomRibbon.CloseTabGroupsPopupWindow;
begin
  InternalCloseTabGroupsPopupWindow;
end;

function TdxCustomRibbon.ContainsToolBar(AToolBar: TdxBar): Boolean;
begin
  Result := (QuickAccessToolbar.Toolbar = AToolBar) or Tabs.ContainsToolBar(AToolBar);
end;

procedure TdxCustomRibbon.EndUpdate;
begin
  Dec(FLockCount);
  if (FLockCount = 0) and not IsDestroying then
  begin
    Changed;
    GroupsDockControlSite.SetRedraw(True);
    RibbonFormInvalidate;
  end;
end;

function TdxCustomRibbon.GetTabAtPos(X, Y: Integer): TdxRibbonTab;
begin
  Result := ViewInfo.GetTabAtPos(X, Y);
end;

procedure TdxCustomRibbon.ShowTabGroupsPopupWindow;
begin
  if ShowTabGroups then Exit;
  if FTabGroupsPopupWindow = nil then
    FTabGroupsPopupWindow := TdxRibbonTabGroupsPopupWindow.Create(Self);
  FTabGroupsPopupWindow.AllowShowHideAnimation := Style = rs2013;
  FTabGroupsPopupWindow.OwnerBounds := BoundsRect;
  FTabGroupsPopupWindow.OwnerParent := Parent;
  FTabGroupsPopupWindow.Popup(nil);
  FTabGroupsPopupWindow.Invalidate;
  Invalidate;
end;

procedure TdxCustomRibbon.AddListener(AListener: IdxRibbonListener);
begin
  FListeners.Add(AListener);
end;

procedure TdxCustomRibbon.RemoveListener(AListener: IdxRibbonListener);
begin
  if FListeners <> nil then
    FListeners.Remove(AListener);
end;

procedure TdxCustomRibbon.AddTab(ATab: TdxRibbonTab);
begin
  if ATab = nil then Exit;
  ATab.Ribbon := Self;
  if ActiveTab = nil then
    ActiveTab := ATab;
  Changed;
end;

procedure TdxCustomRibbon.RemoveTab(ATab: TdxRibbonTab);
begin
  if ATab = nil then Exit;
  BarDesignController.LockDesignerModified;
  try
    ATab.Ribbon := nil;
    if ActiveTab = ATab then
      SetNextActiveTab(ATab);
    if FLoadedActiveTab = ATab then
      FLoadedActiveTab := nil;
    if FActiveTab = ATab then
      FActiveTab := nil;
  finally
    BarDesignController.UnLockDesignerModified;
  end;
  Changed;
end;

procedure TdxCustomRibbon.SetNextActiveTab(ATab: TdxRibbonTab);
begin
  FLockModified := csDestroying in ATab.ComponentState;
  try
    ActiveTab := GetNextActiveTab(ATab);
  finally
    FLockModified := False;
  end;
end;

procedure TdxCustomRibbon.FullInvalidate;
begin
  if IsDestroying or not (HandleAllocated and Visible) then Exit;
  QuickAccessToolbar.UpdateColorScheme;
  UpdateActiveTab;
  RibbonFormInvalidate;
  FGroupsDockControlSite.Invalidate; //for CBuilder
  Invalidate;
end;

procedure TdxCustomRibbon.Changed;
begin
  if IsLocked then Exit;
  if not (IsDesigning or LockedCancelHint) then
    dxFader.Clear;
  if not LockedCancelHint then
    Controller.CancelHint;
  if FormCaptionHelper <> nil then
    FormCaptionHelper.Calculate;
  ViewInfo.Calculate;
  Invalidate;
end;

procedure TdxCustomRibbon.RecalculateBars;
var
  I: Integer;
begin
  if IsBarManagerValid then
  begin

    with QuickAccessToolbar do
      if Assigned(Toolbar) and (Toolbar.Control is TdxRibbonQuickAccessBarControl) then
      begin
        with TdxRibbonQuickAccessBarControl(Toolbar.Control) do
          UpdateDefaultGlyph(FDefaultGlyph);
        Toolbar.Control.RepaintBar; // Flush glyph cache
      end;

    with BarManager do
    begin
      BeginUpdate;
      try
        for I := 0 to Bars.Count - 1 do
          if Bars.Items[I].Control <> nil then
            TdxBarControlAccess(Bars.Items[I].Control).CalcDrawingConsts;
      finally
        EndUpdate;
      end;
    end;

  end;
end;

function TdxCustomRibbon.AllowPan(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := (AScrollKind = sbHorizontal) and (ViewInfo.TabsViewInfo.ScrollButtons <> []);
end;

procedure TdxCustomRibbon.GestureScroll(ADeltaX, ADeltaY: Integer);
begin
  with ViewInfo.TabsViewInfo do
    ScrollPosition := ScrollPosition - ADeltaX;
end;

function TdxCustomRibbon.IsPanArea(const APoint: TPoint): Boolean;
var
  AHitInfo: TdxRibbonHitInfo;
begin
  AHitInfo := TdxRibbonHitInfo.Create(ViewInfo);
  try
    AHitInfo.Calculate(APoint);
    Result := AHitInfo.HitTest = rhtTab;
  finally
    AHitInfo.Free;
  end;
end;

function TdxCustomRibbon.NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := False;
end;

procedure TdxCustomRibbon.AdjustRibbonFormBorderIconSize(
  AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean; var ASize: TSize);
begin
  ColorScheme.AdjustRibbonFormBorderIconSize(AIcon, AIsToolWindow, ASize);
  TouchModeHelper.AdjustFormBorderIconSize(AIcon, AIsToolWindow, ASize);
end;

procedure TdxCustomRibbon.DrawRibbonFormCaption(ACanvas: TcxCanvas;
  const ABounds: TRect; const ACaption: string; const AData: TdxRibbonFormData);
begin
  Painter.DrawRibbonFormCaption(ACanvas, ABounds, AData);
end;

procedure TdxCustomRibbon.DrawRibbonFormBackground(DC: HDC; const ARect: TRect);
begin
  ColorScheme.DrawRibbonFormBackground(DC, ARect, ViewInfo.Bounds.Bottom - ARect.Top);
end;

procedure TdxCustomRibbon.DrawRibbonFormBorderIcon(ACanvas: TcxCanvas;
  const ABounds: TRect; AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState);
begin
  Painter.DrawRibbonFormBorderIcon(ACanvas, ABounds, AIcon, AState);
end;

procedure TdxCustomRibbon.DrawRibbonFormBorders(ACanvas: TcxCanvas;
  const AData: TdxRibbonFormData; const ABordersWidth: TRect);
begin
  CheckDrawRibbonFormStatusBarBorders(ACanvas, AData, ABordersWidth);
  Painter.DrawRibbonFormBorders(ACanvas, ABordersWidth, AData);
end;

function TdxCustomRibbon.GetApplicationMenuState: TdxRibbonApplicationMenuState;
begin
  Result := Controller.ApplicationMenuState;
end;

procedure TdxCustomRibbon.GetApplicationMenuTabOrderList(List: TList);
begin
  if ApplicationButton.IMenu <> nil then
    ApplicationButton.IMenu.GetTabOrderList(List)
end;

function TdxCustomRibbon.GetRibbonFormCaptionHeight: Integer;
begin
  Result := CalculateFormCaptionHeight(True);
end;

function TdxCustomRibbon.GetRibbonFormCaptionHeightForHiddenRibbon: Integer;
begin
  Result := CalculateFormCaptionHeight(False);
end;

function TdxCustomRibbon.GetRibbonFormColor: TColor;
begin
  Result := SkinGetPartColor(rfspRibbonForm);
end;

function TdxCustomRibbon.GetRibbonFormCaptionAreaExtention: Integer;
begin
  if ColorScheme.ExtendCaptionAreaOnTabs and (not ViewInfo.UseGlass or EnableTabAero) then
    Result := ViewInfo.TabsHeight
  else
    Result := 0;
end;

function TdxCustomRibbon.GetRibbonFormExtendedCaptionAreaRegion: HRGN;
var
  R: TRect;
begin
  Result := 0;
  if (GetRibbonFormCaptionAreaExtention > 0) and not IsAutoHideModeActive then
  begin
    R := ViewInfo.TabsBounds;
    if ViewInfo.TabsViewInfo.Count > 0 then
      R.Left := ViewInfo.TabsViewInfo.Last.Bounds.Right;
    if not cxRectIsEmpty(R) then
      Result := CreateRectRgnIndirect(R);
  end;
end;

function TdxCustomRibbon.GetRibbonLoadedHeight: Integer;
begin
  Result := FLoadedHeight;
end;

function TdxCustomRibbon.GetRibbonNonClientAreaObjectsRegion: HRGN;
begin
  Result := ViewInfo.GetNonClientAreaObjectsRegion;
end;

function TdxCustomRibbon.GetRibbonQATNonClientAreaBounds: TRect;
begin
  if ViewInfo.IsQATAtNonClientArea then
    Result := ViewInfo.GetQATDockControlBounds
  else
    Result := cxNullRect;
end;

function TdxCustomRibbon.GetRibbonStyle: TdxRibbonStyle;
begin
  Result := Style;
end;

function TdxCustomRibbon.GetTaskbarCaption: TCaption;
begin
  if (RibbonForm <> nil) and (RibbonForm.FormStyle = fsMDIForm) then
  begin
    Result := RibbonForm.Caption;
    if DocumentName <> '' then
      Result := Result + ' - ' + DocumentName;
  end
  else
    Result := ViewInfo.GetFormCaptionText;
end;

function TdxCustomRibbon.GetValidPopupMenuItems: TdxRibbonPopupMenuItems;
begin
  Result := PopupMenuItems;
  if not IsQuickAccessToolbarValid then
    Result := Result - [rpmiQATPosition, rpmiQATAddRemoveItem];
end;

function TdxCustomRibbon.GetWindowBordersWidth: TRect;
begin
  Result := ColorScheme.GetWindowBordersWidth(HasStatusBar);
end;

function TdxCustomRibbon.HasExternalRibbonFormShadow: Boolean;
begin
  Result := ColorScheme.HasExternalRibbonFormShadow;
end;

function TdxCustomRibbon.HasHelpButton: Boolean;
begin
  Result := Assigned(OnHelpButtonClick)
end;

function TdxCustomRibbon.HasStatusBar: Boolean;
begin
  Result := GetStatusBarInterface <> nil;
end;

function TdxCustomRibbon.UseRoundedWindowCorners: Boolean;
begin
  Result := ColorScheme.UseRoundedWindowCorners;
end;

procedure TdxCustomRibbon.RibbonFormCaptionChanged;
var
  AOnMDIForm: Boolean;
  AForm: TForm;
begin
  AOnMDIForm := IsOnRibbonMDIForm;
  LockedCancelHint := True;
  Inc(FLockCount);
  try
    if AOnMDIForm then
    begin
      AForm := RibbonForm.ActiveMDIChild;
      if (AForm <> nil) and IsZoomed(AForm.Handle) then
        DocumentName := AForm.Caption
      else
        DocumentName := '';
    end;
  finally
    Dec(FLockCount);
    LockedCancelHint := False;
    if RibbonForm <> nil then
    begin
      ViewInfo.Calculate;
      UpdateNonClientArea;
      if AOnMDIForm then
        Application.Title := GetTaskbarCaption;
    end;
  end;
end;

procedure TdxCustomRibbon.RibbonFormResized;
begin
  CheckHide;
  if Controller.IsApplicationMenuDropped then
    ApplicationButton.IMenu.RibbonFormResized;
end;

procedure TdxCustomRibbon.UpdateNonClientArea;
const
  RedrawFlags = RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW or RDW_ERASENOW;
begin
  if HandleAllocated and Visible then
  begin
    RedrawWindow(Handle, nil, 0, RedrawFlags);
    if ViewInfo.IsQATAtNonClientArea then
      RedrawWindow(QuickAccessToolbar.DockControl.Handle, nil, 0, RedrawFlags or RDW_ALLCHILDREN);
    if ApplicationButton.IMenu <> nil then
      ApplicationButton.IMenu.UpdateNonClientArea;
  end;
end;

procedure TdxCustomRibbon.DrawTabGroupBackground(
  DC: HDC; const ARect: TRect; AState: Integer; AIsInPopup: Boolean);
var
  R: TRect;
begin
  R := ARect;
  Dec(R.Bottom, GetGroupCaptionHeight + Painter.GetGroupCaptionBottomOffset);
  ColorScheme.DrawTabGroupBackground(DC, R, AState, AIsInPopup);
  ColorScheme.DrawTabGroupHeaderBackground(DC,
    Rect(R.Left, R.Bottom, R.Right, ARect.Bottom), AState, AIsInPopup);
end;

procedure TdxCustomRibbon.DXMShowApplicationMenu(var Message: TMessage);
begin
  ApplicationMenuPopup;
end;

function TdxCustomRibbon.GetGroupCaptionHeight: Integer;
begin
  Result := GroupsPainter.GetGroupCaptionHeight(Fonts.GetGroupHeaderFont);
end;

function TdxCustomRibbon.GetGroupContentHeight: Integer;
begin
  Result := GetGroupRowHeight * dxRibbonGroupRowCount;
end;

function TdxCustomRibbon.GetGroupHeight: Integer;
begin
  Result := GetGroupContentHeight + cxMarginsHeight(SkinGetContentOffsets(DXBAR_TOOLBAR));
end;

function TdxCustomRibbon.GetGroupRowHeight: Integer;
begin
  Result := GroupsPainter.GetGroupRowHeight(GroupsPainter.GetSmallIconSize, Fonts.GetGroupFont);
end;

function TdxCustomRibbon.GetHelpButtonScreenTip: TdxScreenTip;
begin
  Result := HelpButton.ScreenTip;
end;

function TdxCustomRibbon.GetHidden: Boolean;
begin
  Result := ViewInfo.Hidden;
end;

procedure TdxCustomRibbon.SkinDrawBackground(DC: HDC; const ARect: TRect; APart, AState: Integer);
begin
  SkinDrawBackgroundEx(DC, ARect, ARect, APart, AState);
end;

procedure TdxCustomRibbon.SkinDrawBackgroundEx(DC: HDC; const ARect: TRect;
  const AContentRect: TRect; APart: Integer; AState: Integer = 0);
begin
  case APart of
    DXBAR_BACKSTAGEVIEW:
      ColorScheme.DrawBackstageViewBackground(DC, ARect, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_BACKBUTTON:
      ColorScheme.DrawBackstageViewBackButton(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_MENUBAR:
      ColorScheme.DrawBackstageViewMenuBackground(DC, ARect, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_MENUBAR_HEADER:
      ColorScheme.DrawBackstageViewMenuHeader(DC, ARect, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM:
      ColorScheme.DrawBackstageViewMenuButton(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_MENUBAR_SEPARATOR:
      ColorScheme.DrawBackstageViewMenuSeparator(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_MENUBAR_TAB:
      ColorScheme.DrawBackstageViewTabButton(DC, ARect, AState, ColorSchemeAccent);

    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL:
      ColorScheme.DrawBackstageViewGalleryBackground(DC, ARect);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEM:
      ColorScheme.DrawBackstageViewGalleryItem(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_GROUPHEADER:
      ColorScheme.DrawBackstageViewGalleryGroupHeader(DC, ARect);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINBUTTON:
      ColorScheme.DrawBackstageViewGalleryItemPinButton(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINBUTTONGLYPH:
      ColorScheme.DrawBackstageViewGalleryItemPinButtonGlyph(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINTAG:
      ColorScheme.DrawBackstageViewGalleryItemPinTag(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_SEPARATOR:
      ColorScheme.DrawBackstageViewGallerySeparator(DC, ARect, ColorSchemeAccent);

    DXBAR_SCROLLBOX_SIZEGRIPAREA:
      ColorScheme.DrawScrollBoxSizeGripArea(DC, ARect, ColorSchemeAccent);
    DXBAR_SCROLLBARHORZ_BACKGROUND, DXBAR_SCROLLBARVERT_BACKGROUND:
      ColorScheme.DrawScrollBarBackground(DC, ARect, APart = DXBAR_SCROLLBARHORZ_BACKGROUND, ColorSchemeAccent);
    DXBAR_SCROLLBARHORZ_LINEDOWN, DXBAR_SCROLLBARVERT_LINEDOWN:
      ColorScheme.DrawScrollBarPart(DC, ARect, sbpLineDown, AState, APart = DXBAR_SCROLLBARHORZ_LINEDOWN, ColorSchemeAccent);
    DXBAR_SCROLLBARHORZ_LINEUP, DXBAR_SCROLLBARVERT_LINEUP:
      ColorScheme.DrawScrollBarPart(DC, ARect, sbpLineUp, AState, APart = DXBAR_SCROLLBARHORZ_LINEUP, ColorSchemeAccent);
    DXBAR_SCROLLBARHORZ_THUMBNAIL, DXBAR_SCROLLBARVERT_THUMBNAIL:
      ColorScheme.DrawScrollBarPart(DC, ARect, sbpThumbnail, AState, APart = DXBAR_SCROLLBARHORZ_THUMBNAIL, ColorSchemeAccent);
    DXBAR_SCROLLBARHORZ_PAGEDOWN, DXBAR_SCROLLBARVERT_PAGEDOWN:
      ColorScheme.DrawScrollBarPart(DC, ARect, sbpPageDown, AState, APart = DXBAR_SCROLLBARHORZ_PAGEDOWN, ColorSchemeAccent);
    DXBAR_SCROLLBARHORZ_PAGEUP, DXBAR_SCROLLBARVERT_PAGEUP:
      ColorScheme.DrawScrollBarPart(DC, ARect, sbpPageUp, AState, APart = DXBAR_SCROLLBARHORZ_PAGEUP, ColorSchemeAccent);

    DXBAR_PROGRESSSOLIDBAND:
      ColorScheme.DrawProgressSolidBand(DC, ARect);
    DXBAR_PROGRESSSUBSTRATE:
      ColorScheme.DrawProgressSubstrate(DC, ARect);
    DXBAR_PROGRESSDISCRETEBAND:
      ColorScheme.DrawProgressDiscreteBand(DC, ARect);

    DXBAR_INRIBBONGALLERY:
      ColorScheme.DrawInRibbonGalleryBackground(DC, ARect, AState);
    DXBAR_INRIBBONGALLERYSCROLLBAR_LINEUPBUTTON:
      ColorScheme.DrawInRibbonGalleryScrollBarButton(DC, ARect, gsbkLineUp, AState, ColorSchemeAccent);
    DXBAR_INRIBBONGALLERYSCROLLBAR_LINEDOWNBUTTON:
      ColorScheme.DrawInRibbonGalleryScrollBarButton(DC, ARect, gsbkLineDown, AState, ColorSchemeAccent);
    DXBAR_INRIBBONGALLERYSCROLLBAR_DROPDOWNBUTTON:
      ColorScheme.DrawInRibbonGalleryScrollBarButton(DC, ARect, gsbkDropDown, AState, ColorSchemeAccent);
    DXBAR_INRIBBONGALLERYSCROLLBAR_BACKGROUND:
      ColorScheme.DrawInRibbonGalleryScrollBarBackground(DC, ARect, AState);

    DXBAR_DROPDOWNGALLERY:
      ColorScheme.DrawDropDownGalleryBackground(DC, ARect);
    DXBAR_DROPDOWNGALLERY_TOPSIZINGBAND:
      ColorScheme.DrawDropDownGalleryTopSizingBand(DC, ARect);
    DXBAR_DROPDOWNGALLERY_BOTTOMSIZINGBAND:
      ColorScheme.DrawDropDownGalleryBottomSizingBand(DC, ARect);
    DXBAR_DROPDOWNGALLERY_TOPSIZEGRIP:
      ColorScheme.DrawDropDownGalleryTopSizeGrip(DC, ARect);
    DXBAR_DROPDOWNGALLERY_BOTTOMSIZEGRIP:
      ColorScheme.DrawDropDownGalleryBottomSizeGrip(DC, ARect);
    DXBAR_DROPDOWNGALLERY_TOPVERTICALSIZEGRIP:
      ColorScheme.DrawDropDownGalleryTopVerticalSizeGrip(DC, ARect);
    DXBAR_DROPDOWNGALLERY_BOTTOMVERTICALSIZEGRIP:
      ColorScheme.DrawDropDownGalleryBottomVerticalSizeGrip(DC, ARect);

    DXBAR_GALLERYGROUPHEADERBACKGROUND:
      ColorScheme.DrawGalleryGroupHeaderBackground(DC, ARect);
    DXBAR_GALLERYFILTERBAND:
      ColorScheme.DrawGalleryFilterBandBackground(DC, ARect);

    DXBAR_SEPARATOR_LINE:
      ColorScheme.DrawSeparatorLine(DC, ARect);
    DXBAR_SEPARATOR_BACKGROUND:
      ColorScheme.DrawSeparatorBackground(DC, ARect);

    DXBAR_MENUARROWDOWN:
      ColorScheme.DrawMenuArrowDown(DC, ARect);
    DXBAR_MENUARROWRIGHT:
      ColorScheme.DrawMenuArrowRight(DC, ARect);
    DXBAR_MENUCHECK:
      ColorScheme.DrawMenuCheck(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_MENUCHECKMARK:
      ColorScheme.DrawMenuCheckMark(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_MENUCONTENT:
      ColorScheme.DrawMenuContent(DC, ARect);
    DXBAR_MENUDETACHCAPTION:
      ColorScheme.DrawMenuDetachCaption(DC, ARect, AState);
    DXBAR_MENUGLYPH:
      ColorScheme.DrawMenuGlyph(DC, ARect);
    DXBAR_MENUITEM:
      ColorScheme.DrawMenuItem(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_MENUITEM_GLYPH:
      ColorScheme.DrawMenuItemDropButtonMainPart(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_MENUITEM_DROPBUTTON:
      ColorScheme.DrawMenuItemDropButtonArrowPart(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_MENUMARK: ColorScheme.DrawMenuMark(DC, ARect);
    DXBAR_MENUSEPARATORHORZ:
      ColorScheme.DrawMenuSeparatorHorz(DC, ARect);
    DXBAR_MENUSEPARATORVERT:
      ColorScheme.DrawMenuSeparatorVert(DC, ARect);
    DXBAR_MENUSCROLLAREA:
      ColorScheme.DrawMenuScrollArea(DC, ARect, AState);

    DXBAR_MENUEXTRAPANE_PINBUTTON:
      ColorScheme.DrawApplicationMenuExtraPanePinButton(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_MENUEXTRAPANE_BUTTON:
      ColorScheme.DrawApplicationMenuExtraPaneButton(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_MENUEXTRAPANE_SEPARATOR, DXBAR_MENUEXTRAPANE_SEPARATOR_VERT:
      ColorScheme.DrawMenuExtraSeparator(DC, ARect, APart = DXBAR_MENUEXTRAPANE_SEPARATOR);

    DXBAR_COLLAPSEDTOOLBAR:
      ColorScheme.DrawCollapsedToolbarBackground(DC, ARect, AState);
    DXBAR_COLLAPSEDTOOLBARGLYPHBACKGROUND:
      ColorScheme.DrawCollapsedToolbarGlyphBackground(DC, ARect, AState);

    DXBAR_ARROWDOWN:
      ColorScheme.DrawArrowDown(DC, ARect, AState);
    DXBAR_MARKARROW:
      ColorScheme.DrawMarkArrow(DC, ARect, AState);
    DXBAR_MARKTRUNCATED:
      ColorScheme.DrawMarkTruncated(DC, ARect, AState);
    DXBAR_SCROLLARROW:
      ColorScheme.DrawScrollArrow(DC, ARect);

    DXBAR_APPLICATIONMENU:
      begin
        ColorScheme.DrawApplicationMenuBackground(DC, ARect, AContentRect, ColorSchemeAccent);
        DrawApplicationMenuHeader(DC, True);
      end;
    DXBAR_APPLICATIONMENUBUTTON:
      ColorScheme.DrawApplicationMenuButton(DC, ARect, AState, ColorSchemeAccent);

    DXBAR_EDIT_ARROWBUTTON:
      ColorScheme.DrawEditArrowButton(DC, ARect, AState);
    DXBAR_EDIT_BUTTON:
      ColorScheme.DrawEditButton(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_EDIT_ELLIPSISBUTTON:
      ColorScheme.DrawEditEllipsisButton(DC, ARect, AState);

    DXBAR_SPINEDIT_UPBUTTON:
      ColorScheme.DrawEditSpinUpButton(DC, ARect, AState);
    DXBAR_SPINEDIT_DOWNBUTTON:
      ColorScheme.DrawEditSpinDownButton(DC, ARect, AState);

    DXBAR_SMALLBUTTON:
      ColorScheme.DrawSmallButton(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_SMALLBUTTON_GLYPH:
      ColorScheme.DrawSmallButtonDropButtonMainPart(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_SMALLBUTTON_DROPBUTTON:
      ColorScheme.DrawSmallButtonDropButtonArrowPart(DC, ARect, AState, ColorSchemeAccent);

    DXBAR_LARGEBUTTON:
      ColorScheme.DrawLargeButton(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_LARGEBUTTON_GLYPH:
      ColorScheme.DrawLargeButtonDropButtonMainPart(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_LARGEBUTTON_DROPBUTTON:
      ColorScheme.DrawLargeButtonDropButtonArrowPart(DC, ARect, AState, ColorSchemeAccent);

    DXBAR_BUTTONGROUP:
      ColorScheme.DrawButtonGroup(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BUTTONGROUP_DROPBUTTON:
      ColorScheme.DrawButtonGroupDropButtonArrowPart(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BUTTONGROUP_GLYPH:
      ColorScheme.DrawButtonGroupDropButtonMainPart(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_BUTTONGROUPBORDERLEFT:
      ColorScheme.DrawButtonGroupBorderLeft(DC, ARect);
    DXBAR_BUTTONGROUPBORDERMIDDLE:
      ColorScheme.DrawButtonGroupBorderMiddle(DC, ARect, AState);
    DXBAR_BUTTONGROUPBORDERRIGHT:
      ColorScheme.DrawButtonGroupBorderRight(DC, ARect);
    DXBAR_BUTTONGROUPSPLITBUTTONSEPARATOR:
      ColorScheme.DrawButtonGroupSplitButtonSeparator(DC, ARect, AState);

    DXBAR_LAUNCHBUTTONDEFAULTGLYPH:
      ColorScheme.DrawLaunchButtonDefaultGlyph(DC, ARect, AState, ColorSchemeAccent);
    DXBAR_LAUNCHBUTTONBACKGROUND:
      ColorScheme.DrawLaunchButtonBackground(DC, ARect, AState, ColorSchemeAccent);

    DXBAR_QUICKACCESSGROUPBUTTON:
      ColorScheme.DrawQuickAccessToolbarGroupButton(DC, ARect,
        ViewInfo.IsQATAtBottom, ViewInfo.SupportNonClientDrawing,
        ViewInfo.IsFormCaptionActive, AState, ColorSchemeAccent);
    DXBAR_SCREENTIP:
      ColorScheme.DrawScreenTip(DC, ARect);
    DXBAR_DROPDOWNBORDER:
      ColorScheme.DrawDropDownBorder(DC, ARect);
    DXBAR_MINITOOLBAR_BACKGROUND:
      ColorScheme.DrawMiniToolbarBackground(DC, ARect);
    DXBAR_ITEMSEPARATOR, DXBAR_ITEMSEPARATOR_VERT:
      ColorScheme.DrawItemSeparator(DC, ARect, APart = DXBAR_ITEMSEPARATOR);
    DXBAR_TOOLBAR, DXBAR_TOOLBARINPOPUP:
      DrawTabGroupBackground(DC, ARect, AState, APart = DXBAR_TOOLBARINPOPUP);

  end;
end;

procedure TdxCustomRibbon.SkinDrawCaption(DC: HDC; const ACaption: string;
  const ARect: TRect; APart, AState: Integer);
var
  ACaptionRect: TRect;
  APrevFont: HFONT;
  APrevTextColor: TColor;
  AFont: TFont;
begin
  if (APart = DXBAR_TOOLBAR) or (APart = DXBAR_TOOLBARINPOPUP) then
  begin
    AFont := Fonts.GetGroupHeaderFont;
    SetBkMode(DC, TRANSPARENT);
    APrevFont := SelectObject(DC, AFont.Handle);
    APrevTextColor := GetTextColor(DC);
    SetTextColor(DC, ColorToRGB(AFont.Color));
    ACaptionRect := ARect;
    Inc(ACaptionRect.Top, dxRibbonGroupCaptionHeightCorrection);
    cxDrawText(DC, ACaption, ACaptionRect, DT_SINGLELINE or DT_CENTER or DT_VCENTER);
    SelectObject(DC, APrevFont);
    SetTextColor(DC, APrevTextColor);
    SetBkMode(DC, OPAQUE);
  end;
end;

function TdxCustomRibbon.SkinGetCaptionRect(const ARect: TRect; APart: Integer): TRect;
begin
  case APart of
    DXBAR_TOOLBAR, DXBAR_TOOLBARINPOPUP:
      begin
        with SkinGetContentOffsets(APart) do
          Result := cxRectContent(ARect, Rect(Left, 0, Right, Painter.GetGroupCaptionBottomOffset));
        Result.Top := Result.Bottom - GetGroupCaptionHeight;
      end;
    else
      Result := cxEmptyRect;
  end;
end;

function TdxCustomRibbon.SkinGetContentOffsets(APart: Integer): TRect;
begin
  case APart of
    DXBAR_APPLICATIONMENUCONTENT:
      Result := ColorScheme.GetApplicationMenuContentOffset(ViewInfo.TabsBounds);

    DXBAR_TOOLBAR, DXBAR_TOOLBARINPOPUP:
      begin
        Result := ColorScheme.GetPartContentOffsets(APart);
        Inc(Result.Bottom, GetGroupCaptionHeight + Painter.GetGroupCaptionBottomOffset);
      end

    else
      Result := ColorScheme.GetPartContentOffsets(APart);
  end;
  TouchModeHelper.AdjustPartOffsets(APart, Result);
end;

function TdxCustomRibbon.SkinGetIsAlphaUsed(APart: Integer): Boolean;
begin
  Result := ColorScheme.GetIsAlphaUsed(APart);
end;

function TdxCustomRibbon.SkinGetName: string;
begin
  Result := ColorScheme.GetSkinName;
end;

function TdxCustomRibbon.SkinGetPartColor(APart: Integer; AState: Integer = 0): TColor;
begin
  Result := ColorScheme.GetPartColor(APart, AState, ColorSchemeAccent);
end;

function TdxCustomRibbon.SkinGetPartSize(APart: Integer): Integer;
begin
  Result := ColorScheme.GetPartSize(APart);
  TouchModeHelper.AdjustPartSize(APart, Result);
end;

function TdxCustomRibbon.CanProcessMouseWheel: Boolean;
begin
  Result := IsWindowEnabled(Handle) and not Hidden and (ShowTabHeaders or ShowTabGroups);
end;

procedure TdxCustomRibbon.FormKeyDown(var Key: Word; Shift: TShiftState);
begin
  if not IsDestroying and HandleAllocated then
  begin
    Controller.HideHint;
    if (Key = VK_F1) and (ssCtrl in Shift) and not IsPopupGroupsMode then
    begin
      ShowTabGroups := not ShowTabGroups;
      Key := 0;
    end;
  end;
end;

function TdxCustomRibbon.GetAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  Result := IAccessibilityHelper;
end;

procedure TdxCustomRibbon.ProcessMergeOperation(ABarManager: TdxBarManager;
  AOperation: TdxBarMergeOperation; var AHandled: Boolean);
var
  ARibbon: TdxCustomRibbon;
begin
  ARibbon := FindRibbonForComponent(ABarManager);
  if AOperation = bmoUnmerge then
    AHandled := (ABarManager = nil) or (ARibbon <> nil) and (ARibbon.MergeData.MergedWith = Self)
  else
    AHandled := (ARibbon <> nil);

  if AHandled then
  begin
    case AOperation of
      bmoMerge:
        Merge(ARibbon);
      bmoUnmerge:
        Unmerge(ARibbon);
    end;
  end;
end;

procedure TdxCustomRibbon.RibbonFormNonClientDrawAdd(AObject: TObject);
begin
  if RibbonFormNonClientParts.IndexOf(AObject) = -1 then
    RibbonFormNonClientParts.Add(AObject);
end;

procedure TdxCustomRibbon.RibbonFormNonClientDrawRemove(AObject: TObject);
begin
  RibbonFormNonClientParts.Remove(AObject);
end;

procedure TdxCustomRibbon.AfterApplicationMenuPopup;
var
  AHelper: IdxRibbonFormControllerHelper;
begin
  Exclude(FInternalState, risAppMenuActive);
  if Supports(RibbonForm, IdxRibbonFormControllerHelper, AHelper) then
    AHelper.DoAfterApplicationMenuPopup;
  Changed;
end;

procedure TdxCustomRibbon.AfterConstruction;
begin
  inherited AfterConstruction;
  if dxRibbonList <> nil then
    dxRibbonList.Add(Self);
end;

procedure TdxCustomRibbon.BeforeApplicationMenuPopup;
var
  AHelper: IdxRibbonFormControllerHelper;
begin
  Include(FInternalState, risAppMenuActive);
  if Supports(RibbonForm, IdxRibbonFormControllerHelper, AHelper) then
    AHelper.DoBeforeApplicationMenuPopup;
  Changed;
end;

procedure TdxCustomRibbon.BeforeDestruction;
begin
  inherited BeforeDestruction;
  if dxRibbonList <> nil then
    dxRibbonList.Remove(Self)
end;

procedure TdxCustomRibbon.BoundsChanged;
begin
  inherited BoundsChanged;
  Changed;
end;

function TdxCustomRibbon.CanResize(var NewWidth, NewHeight: Integer): Boolean;
begin
  Result := inherited CanResize(NewWidth, NewHeight);
  NewHeight := ViewInfo.GetRibbonHeight;
end;

function TdxCustomRibbon.CanScrollTabs: Boolean;
begin
  Result := AreGroupsVisible and not IsPopupGroupsMode and
    not ((ActiveBarControl is TdxRibbonCollapsedGroupPopupBarControl) or
    dxBarHasPopupWindowAbove(ActiveBarControl, False));
end;

procedure TdxCustomRibbon.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  with Params.WindowClass do
    style := style and not(CS_HREDRAW or CS_VREDRAW);
end;

procedure TdxCustomRibbon.CreateWindowHandle(const Params: TCreateParams);
begin
  inherited CreateWindowHandle(Params);
  if not (FIsMouseHookInstalled or IsDesigning) and IsWin2KOrLater then
  begin
    dxSetHook(htMouse, dxRibbonMouseHook);
    FIsMouseHookInstalled := True;
  end;
end;

procedure TdxCustomRibbon.DoCancelMode;
begin
  inherited DoCancelMode;
  Controller.CancelMode;
end;

procedure TdxCustomRibbon.DoMinimizeChanged;
begin
  if Assigned(OnMinimizedChanged) then OnMinimizedChanged(Self);
end;

procedure TdxCustomRibbon.LookAndFeelChanged(Sender: TcxLookAndFeel;
  AChangedValues: TcxLookAndFeelValues);
begin
  inherited LookAndFeelChanged(Sender, AChangedValues);
  UpdateColorScheme;
end;

procedure TdxCustomRibbon.DoContextPopup(MousePos: TPoint; var Handled: Boolean);
begin
  if IsDesigning then
    inherited DoContextPopup(MousePos, Handled)
  else
    Handled := True;
end;

function TdxCustomRibbon.DoMouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean;
begin
  Result := inherited DoMouseWheelDown(Shift, MousePos);
  if not Result then
    Result := Controller.MouseWheelDown(Shift, MousePos);
end;

function TdxCustomRibbon.DoMouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean;
begin
  Result := inherited DoMouseWheelUp(Shift, MousePos);
  if not Result then
    Result := Controller.MouseWheelUp(Shift, MousePos);
end;

procedure TdxCustomRibbon.FontChanged;
begin
  BeginUpdate;
  try
    inherited FontChanged;
    FFonts.UpdateFonts;
    if ActiveTab <> nil then
      ActiveTab.UpdateGroupsFont;
  finally
    EndUpdate;
  end;
end;

procedure TdxCustomRibbon.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
begin
  for I := 0 to Tabs.Count - 1 do
    if Tabs[I].Owner = Root then Proc(Tabs[I]);
end;

function TdxCustomRibbon.GetDesignHitTest(X, Y: Integer; Shift: TShiftState): Boolean;
begin
  Result := inherited GetDesignHitTest(X, Y, Shift);
  if not Result then
  begin
    Result := GetTabAtPos(X, Y) <> nil;
  end;
end;

procedure TdxCustomRibbon.KeyDown(var Key: Word; Shift: TShiftState);
begin
  Controller.KeyDown(Key, Shift);
  inherited;
end;

procedure TdxCustomRibbon.KeyPress(var Key: Char);
begin
  Controller.KeyPress(Key);
  inherited;
end;

procedure TdxCustomRibbon.KeyUp(var Key: Word; Shift: TShiftState);
begin
  Controller.KeyUp(Key, Shift);
  inherited;
end;

procedure TdxCustomRibbon.Loaded;
begin
  BeginUpdate;
  try
    Tabs.UpdateBarManager(BarManager);
    inherited Loaded;
    ActiveTab := FLoadedActiveTab;
    if ActiveTab <> nil then
      ActiveTab.CheckGroupToolbarsDockControl;
    Tabs.RestoreOrder;
    Tabs.UpdateContexts;
  finally
    EndUpdate;
  end;
end;

function TdxCustomRibbon.MayFocus: Boolean;
begin
  Result := False;
end;

procedure TdxCustomRibbon.Modified;
begin
  if not FLockModified then
    inherited;
end;

procedure TdxCustomRibbon.MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseDown(Button, Shift, X, Y);
  Controller.MouseDown(Button, Shift, X, Y);
end;

procedure TdxCustomRibbon.MouseLeave(AControl: TControl);
begin
  inherited MouseLeave(AControl);
  Controller.MouseLeave;
end;

procedure TdxCustomRibbon.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseMove(Shift, X, Y);
  Controller.MouseMove(Shift, X, Y);
end;

procedure TdxCustomRibbon.MouseUp(Button: TMouseButton; Shift: TShiftState;
  X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  Controller.MouseUp(Button, Shift, X, Y);
end;

procedure TdxCustomRibbon.Paint;
var
  AControl: TWinControl;
  P: TPoint;
begin
  if SupportNonClientDrawing and (FormCaptionHelper <> nil) then
  begin
    if ViewInfo.UseGlass then
      Canvas.FillRect(cxRectSetHeight(ClientRect, GetRibbonFormCaptionHeight), clBlack);
    FormCaptionHelper.UpdateCaptionArea;
  end;
  ViewInfo.Paint(Canvas);
  if IsDesigning and (csPaintCopy in ControlState) and HandleAllocated then
  begin
    if ViewInfo.IsQATVisible then
    begin
      Canvas.SaveDC;
      AControl := QuickAccessToolbar.Toolbar.Control;
      P := dxMapWindowPoint(AControl.Handle, Handle, cxNullPoint);
      AControl.PaintTo(Canvas.Canvas.Handle, P.X, P.Y);
      Canvas.RestoreDC;
    end;
  end;
end;

function TdxCustomRibbon.NeedsScrollBars: Boolean;
begin
  Result := False;
end;

procedure TdxCustomRibbon.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if ApplicationButton <> nil then
    ApplicationButton.Notification(AComponent, Operation);
  if Operation = opRemove then
  begin
    if AComponent = BarManager then
      BarManager := nil;
    if not IsDestroying then
    begin
      if (HelpButton <> nil) and (AComponent = HelpButton.ScreenTip) then
        HelpButton.ScreenTip := nil;
      if (ApplicationButton <> nil) and (AComponent = ApplicationButton.ScreenTip) then
        ApplicationButton.ScreenTip := nil;
      if QuickAccessToolbar <> nil then
      begin
        if (AComponent = BarManager) or (AComponent = QuickAccessToolbar.Toolbar) then
          QuickAccessToolbar.Toolbar := nil;
      end;
    end;
  end;
end;

procedure TdxCustomRibbon.ReadState(Reader: TReader);
begin
  if not FTabsLoaded then
  begin
    Tabs.Clear;
    FTabsLoaded := True;
  end;
  inherited ReadState(Reader);
  FLoadedHeight := Height;
end;

procedure TdxCustomRibbon.SetName(const Value: TComponentName);
begin
  inherited SetName(Value);
  if not FTabsLoaded and IsDesigning and (Tabs.Count > 0) then
  begin
    Tabs.SetItemName(Tabs[0]);
    Tabs[0].Caption := Tabs[0].Name;
  end;
end;

procedure TdxCustomRibbon.SetParent(AParent: TWinControl);
begin
  if Assigned(AParent) then
  begin
    AParent := GetParentForm(AParent{$IFDEF DELPHI9}, not (csDesigning in ComponentState){$ENDIF});
    if Assigned(AParent) and not (AParent is TCustomForm) then
      raise EdxException.CreateFmt(cxGetResourceString(@dxSBAR_RIBBONBADPARENT), [ClassName]);
  end;
  inherited SetParent(AParent);
  Top := 0;
  if FSupportNonClientDrawing and not IsLoading and (AParent <> nil) then
    UpdateNonClientDrawing;
end;

procedure TdxCustomRibbon.VisibleChanged;
begin
  if SupportNonClientDrawing and Assigned(RibbonForm) then
  begin
    RibbonForm.DisableAlign;
    try
      inherited VisibleChanged;
      UpdateNonClientDrawing;
    finally
      RibbonForm.EnableAlign;
      RibbonForm.FullUpdate;
    end;
  end
  else
    inherited VisibleChanged;
end;

procedure TdxCustomRibbon.Updating;
begin
  inherited Updating;
  Tabs.SaveContexts;
end;

procedure TdxCustomRibbon.Updated;
begin
  Tabs.RestoreContexts;
  inherited Updated;
end;

procedure TdxCustomRibbon.CheckDrawRibbonFormStatusBarBorders(
  ACanvas: TcxCanvas; const AData: TdxRibbonFormData; const ABordersWidth: TRect);
var
  AIntf: IdxRibbonFormStatusBar;
  AIsRectangular: Boolean;
  ALeftStatusBarBounds, ARightStatusBarBounds: TRect;
  ATop, ABottom: Integer;
begin
  if (AData.State <> wsNormal) or (ApplicationMenuState >= ramsShownAsFrame) then
    Exit;
  if Supports(GetStatusBarInterface, IdxRibbonFormStatusBar, AIntf) then
  begin
    ATop := AData.Bounds.Bottom - AIntf.GetHeight - GetWindowBordersWidth.Bottom;
    ABottom := AData.Bounds.Bottom;
    AIsRectangular := IsRectangularFormBottom(AData);
    if not AIsRectangular then Dec(ABottom);

    ALeftStatusBarBounds := cxRect(0, ATop, ABordersWidth.Left, ABottom);
    ColorScheme.DrawFormStatusBarPart(ACanvas.Handle, ALeftStatusBarBounds,
      True, AData.Active, AIntf.GetIsRaised(True), AIsRectangular, ColorSchemeAccent);
    ACanvas.ExcludeClipRect(ALeftStatusBarBounds);

    ARightStatusBarBounds := cxRect(AData.Bounds.Right - ABordersWidth.Right, ATop, AData.Bounds.Right, ABottom);
    ColorScheme.DrawFormStatusBarPart(ACanvas.Handle, ARightStatusBarBounds,
      False, AData.Active, AIntf.GetIsRaised(False), AIsRectangular, ColorSchemeAccent);
    ACanvas.ExcludeClipRect(ARightStatusBarBounds);
  end;
end;

procedure TdxCustomRibbon.DrawApplicationMenuHeader(ADC: THandle; AIsClientArea: Boolean);

  function GetOffset: TPoint;
  var
    ADestinationOrigin: TPoint;
    AWindowRect: TRect;
  begin
    AWindowRect := cxGetWindowRect(Self);
    ADestinationOrigin := ApplicationButton.IMenu.GetOrigin(AIsClientArea);
    Result := Point(AWindowRect.Left - ADestinationOrigin.X,
      AWindowRect.Top + (Height - ClientHeight) - ADestinationOrigin.Y);
  end;

var
  AOffset: TPoint;
begin
  cxPaintCanvas.BeginPaint(ADC);
  try
    AOffset := GetOffset;
    MoveWindowOrg(cxPaintCanvas.Handle, AOffset.X, AOffset.Y);
    ApplicationButtonViewInfo.Draw(cxPaintCanvas);
    MoveWindowOrg(cxPaintCanvas.Handle, -AOffset.X, -AOffset.Y);
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

function TdxCustomRibbon.AddGroupButtonToQAT(ABar: TdxBar): TdxRibbonQuickAccessGroupButton;
begin
  Result := QuickAccessToolbar.AddGroupButton(ABar);
end;

function TdxCustomRibbon.CalculateFormCaptionHeight(AIsQATAtNonClientArea: Boolean): Integer;
var
  H: Integer;
begin
  if SupportNonClientDrawing and (RibbonForm <> nil) then
  begin
    //text part
    if RibbonForm.IsUseAeroNCPaint then
      H := GetDefaultWindowNCSize(RibbonForm.Handle).Top
    else
      H := Max(GetSystemMetrics(SM_CYCAPTION) - 1, GetSystemMetrics(SM_CYSIZE)) + 6;

    H := Max(H, Abs(Fonts.GetFormCaptionFont(True).Height) * 2);
    H := Max(H, Abs(Fonts.GetFormCaptionFont(False).Height) * 2);

    //quick access toolbar
    if AIsQATAtNonClientArea and IsBarManagerValid then
      H := Max(H, GetGroupRowHeight + IfThen(RibbonForm.IsUseAeroNCPaint, 7, 9));
    Result := H + RibbonForm.GetCaptionHeightDelta(AIsQATAtNonClientArea);
    TouchModeHelper.AdjustFormCaptionHeight(Result);
  end
  else
    Result := 0;
end;

procedure TdxCustomRibbon.CancelUpdate;
begin
  Dec(FLockCount);
  if (FLockCount = 0) and not IsDestroying then
    GroupsDockControlSite.SetRedraw(True);
end;

function TdxCustomRibbon.CanFade: Boolean;
begin
  Result := Fading and dxFader.IsReady and not (IsLocked or
    IsDesigning or TdxCustomRibbonSkinAccess(ColorScheme).LowColors);
end;

function TdxCustomRibbon.CanPaint: Boolean;
begin
  Result := ComponentState * [csLoading, csReading, csDestroying] = [];
end;

function TdxCustomRibbon.CreateApplicationButton: TdxRibbonApplicationButton;
begin
  Result := TdxRibbonApplicationButton.Create(Self);
end;

function TdxCustomRibbon.CreateController: TdxRibbonController;
begin
  Result := TdxRibbonController.Create(Self);
end;

function TdxCustomRibbon.CreateFormCaptionHelper: TdxRibbonFormCaptionHelper;
begin
  Result := TdxRibbonFormCaptionHelper.Create(Self);
end;

function TdxCustomRibbon.CreateGroupsPainter: TdxRibbonBarPainter;
begin
  Result := TdxRibbonBarPainter.Create(TdxNativeUInt(Self));
end;

function TdxCustomRibbon.CreateHelpButton: TdxRibbonHelpButton;
begin
  Result := TdxRibbonHelpButton.Create(Self);
end;

function TdxCustomRibbon.CreatePainter: TdxRibbonPainter;
begin
  Result := TdxRibbonPainter.Create(Self);
end;

function TdxCustomRibbon.CreateQuickAccessToolbar: TdxRibbonQuickAccessToolbar;
begin
  Result := TdxRibbonQuickAccessToolbar.Create(Self);
end;

function TdxCustomRibbon.CreateContextAsByMerging(
  ASourceContext: TdxRibbonContext): TdxRibbonContext;

  function GetInsertPosition(ASourceContext: TdxRibbonContext): Integer;
  var
    I: Integer;
  begin
    Result := 0;
    for I := 0 to Contexts.Count - 1 do
    begin
      if ASourceContext.MergeOrder >= Contexts[I].MergeOrder then
        Result := I + 1;
    end;
  end;

begin
  Result := Contexts.Insert(GetInsertPosition(ASourceContext));
  Result.FCreatedByMerging := True;
  Result.FCreatedByMergingWith := ASourceContext;
  Result.Assign(ASourceContext);
end;

function TdxCustomRibbon.CreateTabAsByMerging(ASourceTab: TdxRibbonTab): TdxRibbonTab;

  function GetInsertPosition(ASourceTab: TdxRibbonTab): Integer;
  var
    I: Integer;
  begin
    Result := 0;
    for I := 0 to Tabs.Count - 1 do
    begin
      if ASourceTab.MergeOrder >= Tabs[I].MergeOrder then
        Result := I + 1;
    end;
  end;

  function GetTargetTabContext(ASourceContext: TdxRibbonContext): TdxRibbonContext;
  var
    AContext: TdxRibbonContext;
    I: Integer;
  begin
    Result := nil;
    if ASourceContext <> nil then
    begin
      for I := 0 to Contexts.Count - 1 do
      begin
        AContext := Contexts[I];
        if AContext.FCreatedByMerging and (AContext.FCreatedByMergingWith = ASourceContext) then
        begin
          Result := AContext;
          Break;
        end;
      end;
      if Result = nil then
        Result := CreateContextAsByMerging(ASourceContext);
    end;
  end;

begin
  Result := Tabs.Insert(GetInsertPosition(ASourceTab));
  Result.AssignCommonProperties(ASourceTab);
  Result.MergeData.CreatedByMerging := True;
  Result.Context := GetTargetTabContext(ASourceTab.Context);
end;

function TdxCustomRibbon.CreateToolbarAsByMerging: TdxBar;
begin
  Result := TdxBarManagerAccess(BarManager).CreateBarAsByMerging;
end;

function TdxCustomRibbon.CreateTouchModeHelper: TdxRibbonTouchModeHelper;
begin
  Result := TdxRibbonTouchModeHelper.Create(Self);
end;

function TdxCustomRibbon.CreateViewInfo: TdxRibbonViewInfo;
begin
  Result := TdxRibbonViewInfo.Create(Self);
end;

procedure TdxCustomRibbon.DesignAddTabGroup(ATab: TdxRibbonTab; ANewToolbar: Boolean);
var
  AGroup: TdxRibbonTabGroup;
begin
  if ATab = nil then
    ATab := ActiveTab;
  if (ATab = nil) or not IsDesigning then Exit;
  if ANewToolbar then
  begin
    BarManager.BeginUpdate;
    try
      AGroup := ATab.Groups.Add;
      AGroup.ToolBar := BarManager.AddToolBar;
      BarDesignController.SelectItem(AGroup.ToolBar);
    finally
      BarManager.EndUpdate;
    end;
  end
  else
    ATab.Groups.Add.DesignSelectionHelper.SelectComponent;
end;

function TdxCustomRibbon.DoApplicationMenuClick: Boolean;
begin
  Result := False;
  if Assigned(OnApplicationMenuClick) then
    OnApplicationMenuClick(Self, Result);
end;

procedure TdxCustomRibbon.DoHelpButtonClick;
begin
  if Assigned(OnHelpButtonClick) then
    OnHelpButtonClick(Self);
end;

function TdxCustomRibbon.DoHideMinimizedByClick(
  AWnd: HWND; AShift: TShiftState; const APos: TPoint): Boolean;
begin
  Result := True;
  if Assigned(OnHideMinimizedByClick) then
    OnHideMinimizedByClick(Self, AWnd, AShift, APos, Result);
end;

function TdxCustomRibbon.DoTabChanging(ANewTab: TdxRibbonTab): Boolean;
begin
  Result := True;
  if Assigned(OnTabChanging) then
    OnTabChanging(Self, ANewTab, Result);
end;

procedure TdxCustomRibbon.DoTabChanged;
begin
  if Assigned(OnTabChanged) then
    OnTabChanged(Self);
end;

procedure TdxCustomRibbon.DoTabGroupCollapsed(ATab: TdxRibbonTab; AGroup: TdxRibbonTabGroup);
begin
  if Assigned(OnTabGroupCollapsed) then
    OnTabGroupCollapsed(Self, ATab, AGroup);
end;

procedure TdxCustomRibbon.DoTabGroupExpanded(ATab: TdxRibbonTab; AGroup: TdxRibbonTabGroup);
begin
  if Assigned(OnTabGroupExpanded) then
    OnTabGroupExpanded(Self, ATab, AGroup);
end;

procedure TdxCustomRibbon.DoMoreCommandsExecute;
begin
  if Assigned(OnMoreCommandsExecute) then
    OnMoreCommandsExecute(Self)
  else
    BarManager.Customizing(True);
end;

function TdxCustomRibbon.GetVisibleTab(Index: Integer): TdxRibbonTab;
var
  I, J: Integer;
begin
  Result := nil;
  J := 0;
  for I := 0 to FTabs.Count - 1 do
    if Tabs[I].Visible then
    begin
      if J = Index then
      begin
        Result := Tabs[I];
        break;
      end;
      Inc(J);
    end;
end;

function TdxCustomRibbon.GetVisibleTabCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to FTabs.Count - 1 do
    if Tabs[I].Visible then Inc(Result);
end;

procedure TdxCustomRibbon.InitCustomizePopupMenu(AItemLinks: TdxBarItemLinks);
var
  AItems: TdxRibbonPopupMenuItems;
begin
  AItems := GetValidPopupMenuItems - [rpmiItems, rpmiQATAddRemoveItem];
  PopulatePopupMenuItems(AItemLinks, AItems, PopupMenuItemClick);
end;

procedure TdxCustomRibbon.AddAffiliatedBarControlForAccessibility(ABarControl: TCustomdxBarControl);
begin
  FAffiliatedBarControlsForAccessibility.Add(ABarControl);
end;

function TdxCustomRibbon.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonAccessibilityHelper;
end;

function TdxCustomRibbon.GetBar(ACustomizingBarControl: TCustomdxBarControl): TdxBar;
var
  ABarControl: TdxRibbonCustomBarControl;
begin
  ABarControl := ACustomizingBarControl as TdxRibbonCustomBarControl;
  if ABarControl.IsPopup then
    Result := ABarControl.MasterBar
  else
    Result := ABarControl.Bar;
end;

function TdxCustomRibbon.GetBarItemControlFadingOptions: TdxFadingOptions;
begin
  Result := OptionsFading.BarItems;
end;

function TdxCustomRibbon.GetBarManager: TdxBarManager;
begin
  if IsBarManagerValid then
    Result := BarManager
  else
    Result := nil;
end;

function TdxCustomRibbon.GetBarPainter: TdxBarPainter;
begin
  Result := GroupsPainter;
end;

function TdxCustomRibbon.GetNextHorizontalAccessibleObject(
  ACurrentObject: IdxBarAccessibilityHelper;
  ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;
var
  AIndex: Integer;
begin
  Result := nil;
  AIndex := HorizontalNavigationList.IndexOf(ACurrentObject);
  if AIndex <> -1 then
  begin
    if (ADirection = andRight) then
      Inc(AIndex)
    else
      Dec(AIndex);
    if AIndex < 0 then
      AIndex := HorizontalNavigationList.Count - 1
    else
      if AIndex > HorizontalNavigationList.Count - 1 then
        AIndex := 0;
    Result := HorizontalNavigationList[AIndex] as IdxBarAccessibilityHelper;
  end;
end;

function TdxCustomRibbon.GetTabClass: TdxRibbonTabClass;
begin
  Result := TdxRibbonTab;
end;

function TdxCustomRibbon.IsAutoHidden: Boolean;
begin
  Result := IsAutoHideModeActive and not RibbonForm.RibbonAutoHideMode.IsUIShown;
end;

function TdxCustomRibbon.IsAutoHideModeActive: Boolean;
begin
  Result := (RibbonForm <> nil) and RibbonForm.RibbonAutoHideMode.Active;
end;

function TdxCustomRibbon.IsBarManagerValid: Boolean;
begin
  Result := (BarManager <> nil) and not (csDestroying in BarManager.ComponentState);
end;

function TdxCustomRibbon.IsHelpButtonPlacedOnTabsArea: Boolean;
begin
  Result := HasHelpButton and ViewInfo.IsTabsVisible and
    ((FormCaptionHelper = nil) or not FormCaptionHelper.IsRibbonHelpButtonPlacedOnCaption);
end;

function TdxCustomRibbon.IsLocked: Boolean;
begin
  Result := (FLockCount > 0) or not HandleAllocated or
    not CanAllocateHandle(Self) or //todo: check condition
    ([csDestroying, csLoading] * ComponentState <> []);
end;

function TdxCustomRibbon.IsMerged: Boolean;
begin
  Result := QuickAccessToolbar.IsMerged or Tabs.IsMerged or
    (MergeData.MergedWith <> nil) or (MergeData.Children.Count > 0)
end;

function TdxCustomRibbon.IsQuickAccessToolbarValid: Boolean;
begin
  Result := QuickAccessToolbar.Visible and (QuickAccessToolbar.Toolbar <> nil);
end;

procedure TdxCustomRibbon.InitializeRibbonForm;
begin
  if not IsDesigning then
  begin
    if RibbonForm <> nil then
      RibbonForm.RibbonControl := Self;
  end;
end;

procedure TdxCustomRibbon.InternalCloseTabGroupsPopupWindow(AAllowAnimation: Boolean);
begin
  if IsPopupGroupsMode then
  begin
    if not AAllowAnimation then
      TabGroupsPopupWindow.AllowShowHideAnimation := False;
    TabGroupsPopupWindow.CloseUp;
  end;
end;

procedure TdxCustomRibbon.PopulatePopupMenuItems(ALinks: TdxBarItemLinks;
  AItems: TdxRibbonPopupMenuItems; AOnClick: TNotifyEvent);

  function GetQATPositionButtonCaption: string;
  begin
    if QuickAccessToolbar.Position = qtpAboveRibbon then
      Result := cxGetResourceString(@dxSBAR_SHOWBELOWRIBBON)
    else
      Result := cxGetResourceString(@dxSBAR_SHOWABOVERIBBON);
  end;

  function AddMenuItem(const ACaption: string; ANeedSeparator: Boolean;
    AItem: TdxRibbonPopupMenuItem; AData: TObject = nil): TdxBarButton;
  begin
    Result := TdxBarButton.Create(BarManager);
    BarDesignController.AddInternalItem(Result, FInternalItems);
    Result.Caption := ACaption;
    Result.OnClick := AOnClick;
    Result.Tag := Ord(AItem);
    Result.Data := AData;
    ALinks.Add(Result).BeginGroup := ANeedSeparator;
  end;

  procedure AddQATItem;

    function GetEnabled: Boolean;
    var
      ABar: TdxBar;
      I: Integer;
    begin
      if BarDesignController.CustomizingItemLink = nil then
      begin
        ABar := GetBar(BarDesignController.CustomizingBarControl);
        Result := not QuickAccessToolbar.HasGroupButtonForToolbar(ABar);
      end
      else
      begin
        Result := IsQuickAccessToolbarValid;
        if Result then
        begin
          ABar := QuickAccessToolbar.Toolbar;
          for I := 0 to ABar.ItemLinks.Count - 1 do
            if ABar.ItemLinks[I].Item = BarDesignController.CustomizingItemLink.Item then
            begin
              Result := False;
              Break;
            end;
        end;
      end;
    end;

    function GetAddMessage: string;
    begin
      if (BarDesignController.CustomizingItemLink = nil) or
        (BarDesignController.CustomizingItemLink.Item.GetAddMessageName = '') then
        Result := cxGetResourceString(@dxSBAR_ADDTOQAT)
      else
        Result := Format(cxGetResourceString(@dxSBAR_ADDTOQATITEMNAME),
          [BarDesignController.CustomizingItemLink.Item.GetAddMessageName]);
    end;

  begin
    if QuickAccessToolbar.Contains(BarDesignController.CustomizingItemLink) then
      AddMenuItem(cxGetResourceString(@dxSBAR_REMOVEFROMQAT), False, rpmiQATAddRemoveItem)
    else
      AddMenuItem(GetAddMessage, False, rpmiQATAddRemoveItem, BarDesignController.CustomizingBarControl).Enabled := GetEnabled;
  end;

var
  ANeedSeparator: Boolean;
  AButton: TdxBarButton;
begin
  FInternalItems.Clear;
  if not (rpmiItems in AItems) then
    ALinks.Clear;
  if rpmiQATAddRemoveItem in AItems then
    AddQATItem;
  ANeedSeparator := ALinks.Count > 0;
  if rpmiMoreCommands in AItems then
  begin
    AddMenuItem(cxGetResourceString(@dxSBAR_MORECOMMANDS), ANeedSeparator, rpmiMoreCommands);
    ANeedSeparator := False;
  end;
  if rpmiQATPosition in AItems then
    AddMenuItem(GetQATPositionButtonCaption, ANeedSeparator, rpmiQATPosition);
  if rpmiMinimizeRibbon in AItems then
  begin
    AButton := AddMenuItem(cxGetResourceString(@dxSBAR_MINIMIZERIBBON), True, rpmiMinimizeRibbon);
    if not ShowTabGroups then
    begin
      AButton.ButtonStyle := bsChecked;
      AButton.Down := True;
    end;
    AButton.Enabled := ViewInfo.TabsViewInfo.Count > 0;
  end;
end;

procedure TdxCustomRibbon.PopupMenuItemClick(Sender: TObject);

  procedure AddItemToQAT;
  var
    ACustomizingLink: TdxBarItemLink;
  begin
    ACustomizingLink := BarDesignController.CustomizingItemLink;
    if ACustomizingLink <> nil then
      QuickAccessToolbar.Toolbar.ItemLinks.Add.Item := ACustomizingLink.Item
    else
      AddGroupButtonToQAT(GetBar(TCustomdxBarControl(TdxBarItem(Sender).Data)));
  end;

  procedure RemoveItemFromQAT;
  var
    ACustomizingLink: TdxBarItemLink;
  begin
    ACustomizingLink := BarDesignController.CustomizingItemLink;
    if ACustomizingLink.Item is TdxRibbonQuickAccessGroupButton then
      BarDesignController.DeleteCustomizingItem
    else
    begin
      if ACustomizingLink.OriginalItemLink <> nil then
        ACustomizingLink.OriginalItemLink.Free
      else
        BarDesignController.DeleteCustomizingItemLink;
    end;
  end;

begin
  case TdxRibbonPopupMenuItem(TdxBarButton(Sender).Tag) of
    rpmiMinimizeRibbon:
      ShowTabGroups := not ShowTabGroups;
    rpmiMoreCommands:
      DoMoreCommandsExecute;
    rpmiQATAddRemoveItem:
      if QuickAccessToolbar.Contains(BarDesignController.CustomizingItemLink) then
        RemoveItemFromQAT
      else
        AddItemToQAT;
    rpmiQATPosition:
      with QuickAccessToolbar do
      begin
        if Position = qtpAboveRibbon then
          Position := qtpBelowRibbon
        else
          Position := qtpAboveRibbon;
      end;
  end;
end;

procedure TdxCustomRibbon.SetRedraw(ARedraw: Boolean);
begin
  if HandleAllocated and Visible then
  begin
    if ARedraw then
    begin
      SendMessage(Handle, WM_SETREDRAW, 1, 0);
      FullInvalidate;
    end
    else
      SendMessage(Handle, WM_SETREDRAW, 0, 0);
  end;
end;

procedure TdxCustomRibbon.ShowCustomizePopup;
begin
  if IsBarManagerValid then
    BarDesignController.ShowCustomCustomizePopup(BarManager, InitCustomizePopupMenu, GroupsPainter);
end;

procedure TdxCustomRibbon.UpdateActiveTab;
begin
  if ActiveTab <> nil then
    ActiveTab.UpdateColorScheme;
end;

procedure TdxCustomRibbon.UpdateControlsVisibility;
begin
  QuickAccessToolbar.DockControl.Visible := not Hidden and
    QuickAccessToolbar.Visible and (QuickAccessToolbar.Toolbar <> nil);
  if ActiveTab <> nil then
    ActiveTab.DockControl.Visible := not Hidden;
  Changed;
  RibbonFormInvalidate;
end;

procedure TdxCustomRibbon.UpdateHorizontalNavigationList;

  procedure TryAddToNavigationList(AIdxBarAccessibilityHelper: IdxBarAccessibilityHelper);
  begin
    if AIdxBarAccessibilityHelper.GetHelper.Selectable then
      FHorizontalNavigationList.Add(AIdxBarAccessibilityHelper);
  end;

var
  I: Integer;
begin
  FHorizontalNavigationList.Clear;
  for I := 0 to TabCount - 1 do
    TryAddToNavigationList(Tabs[I].IAccessibilityHelper);
  for I := 0 to ViewInfo.TabsAreaButtonsViewInfo.Count - 1 do
    TryAddToNavigationList(ViewInfo.TabsAreaButtonsViewInfo[I].AccessibilityHelper);
  TryAddToNavigationList(ApplicationButton.IAccessibilityHelper);
end;

procedure TdxCustomRibbon.UpdateHeight;
begin
  if not IsLoading then
  begin
    if Hidden and not IsDesigning then
      Height := ViewInfo.GetNonClientAreaHeight
    else
      Height := ViewInfo.GetRibbonHeight;
  end;
end;

procedure TdxCustomRibbon.UpdateHiddenActiveTabDockControl;
begin
  if ActiveTab <> nil then
    ActiveTab.UpdateDockControl;
end;

procedure TdxCustomRibbon.UpdateFormActionControl(ASetControl: Boolean);
var
  ARibbonForm: TdxCustomRibbonForm;
begin
  ARibbonForm := GetRibbonForm;
  if ARibbonForm <> nil then
  begin
    if ASetControl then
    begin
      if (ARibbonForm.FormStyle = fsMDIForm) and Assigned(ARibbonForm.ActiveMDIChild) then
        ARibbonForm.PrevActiveControl := ARibbonForm.ActiveMDIChild.ActiveControl
      else
        ARibbonForm.PrevActiveControl := ARibbonForm.ActiveControl
    end
    else
      ARibbonForm.PrevActiveControl := nil;
  end;
end;

function TdxCustomRibbon.GetActiveTab: TdxRibbonTab;
begin
  if csLoading in ComponentState then
    Result := FLoadedActiveTab
  else
    Result := FActiveTab;
end;

function TdxCustomRibbon.GetApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo;
begin
  Result := ViewInfo.ApplicationButtonViewInfo;
end;

function TdxCustomRibbon.GetColorSchemeName: string;
begin
  Result := FColorScheme.Name;
end;

function TdxCustomRibbon.GetIAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  if FIAccessibilityHelper = nil then
    FIAccessibilityHelper := GetAccessibilityHelperClass.Create(Self);
  Result := FIAccessibilityHelper;
end;

function TdxCustomRibbon.GetIniSection(const ADelimiter: string;
  const ASection: string): string;
var
  AOwner: TComponent;
begin
  Result := Name;
  AOwner := Owner;
  while (AOwner <> nil) and (AOwner.Name <> '') do
  begin
    Result := AOwner.Name + '_' + Result;
    AOwner := AOwner.Owner;
  end;

  Result := ASection + Result;
end;

function TdxCustomRibbon.GetIsPopupGroupsMode: Boolean;
begin
  Result := (TabGroupsPopupWindow <> nil) and TabGroupsPopupWindow.IsVisible;
end;

function TdxCustomRibbon.GetNextActiveTab(ATab: TdxRibbonTab): TdxRibbonTab;

  function GetIndex(ATab: TdxRibbonTab): Integer;
  begin
    if ATab = nil then
      Result := 0
    else
      if not (csDestroying in ATab.ComponentState) then
        Result := ATab.Index
      else
        Result := ATab.LastIndex;
  end;

var
  I, AIndex: Integer;
begin
  Result := nil;
  if not IsDestroying then
  begin
    AIndex := GetIndex(ATab);
    for I := AIndex to TabCount - 1 do
      if Tabs[I].IsVisible then
      begin
        Result := Tabs[I];
        Exit;
      end;

    for I := AIndex - 1 downto 0 do
      if Tabs[I].IsVisible then
      begin
        Result := Tabs[I];
        Exit;
      end;
  end;
end;

function TdxCustomRibbon.GetQATIAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  if (QuickAccessToolbar.Toolbar <> nil) and (QuickAccessToolbar.Toolbar.Control <> nil) then
    Result := QuickAccessToolbar.Toolbar.Control.IAccessibilityHelper
  else
    Result := nil;
end;

function TdxCustomRibbon.GetRibbonForm: TdxCustomRibbonForm;
begin
  if (Owner is TdxCustomRibbonForm) and not (csDestroying in Owner.ComponentState) then
    Result := TdxCustomRibbonForm(Owner)
  else
    Result := nil;
end;

function TdxCustomRibbon.GetStatusBarInterface: IUnknown;
var
  AForm: TCustomForm;
  AIntf: IdxRibbonFormStatusBar;
  I: Integer;
begin
  Result := nil;
  if SupportNonClientDrawing and not ViewInfo.UseGlass then
  begin
    AForm := RibbonForm;
    if (AForm <> nil) and AForm.HandleAllocated then
      for I := 0 to RibbonFormNonClientParts.Count - 1 do
      begin
        if Supports(RibbonFormNonClientParts[I], IdxRibbonFormStatusBar, AIntf) and AIntf.GetActive(AForm) then
        begin
          Result := AIntf;
          Break;
        end;
      end;
  end;
end;

function TdxCustomRibbon.GetStyle: TdxRibbonStyle;
begin
  Result := ColorScheme.Style;
end;

function TdxCustomRibbon.GetTabCount: Integer;
begin
  if FTabs <> nil then
    Result := FTabs.Count
  else
    Result := 0;
end;

function TdxCustomRibbon.GetTabsIAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  Result := Tabs.IAccessibilityHelper;
end;

procedure TdxCustomRibbon.InitColorScheme;
begin
  ColorScheme := dxRibbonSkinsManager.Skins[0];
end;

function TdxCustomRibbon.IsOnRibbonMDIForm: Boolean;
var
  AForm: TForm;
begin
  AForm := RibbonForm;
  Result := (AForm <> nil) and (AForm.FormStyle = fsMDIForm);
end;

procedure TdxCustomRibbon.RibbonFormInvalidate;
begin
  if SupportNonClientDrawing then
    WinControlFullInvalidate(RibbonForm);
end;

procedure TdxCustomRibbon.SetActiveTab(Value: TdxRibbonTab);
begin
  if csLoading in ComponentState then
    FLoadedActiveTab := Value
  else
    if (FActiveTab <> Value) and not (csDestroying in ComponentState) then
    begin
      if not IsDesigning then
      begin
        if IsBarManagerValid then
          BarManager.HideAll;
        dxFader.Remove(FActiveTab);
        dxFader.Remove(Value);
        if not DoTabChanging(Value) then Exit;
      end;
      CloseTabGroupsPopupWindow;
      if FActiveTab <> nil then
        FActiveTab.Deactivate;
      FActiveTab := Value;
      GroupsDockControlSite.SetRedraw(False);
      try
        if FActiveTab <> nil then
          FActiveTab.Activate;
        Changed;
        DoTabChanged;
      finally
        Changed;
        GroupsDockControlSite.SetRedraw(True);
      end;
      Modified;
    end;
end;

procedure TdxCustomRibbon.SetApplicationButton(AValue: TdxRibbonApplicationButton);
begin
  FApplicationButton.Assign(AValue);
end;

procedure TdxCustomRibbon.SetBarManager(Value: TdxBarManager);

  procedure RemoveChangeHandler(AHandlerCollection: TcxEventHandlerCollection; AEvent: TcxEventHandler);
  begin
    if AHandlerCollection <> nil then
      AHandlerCollection.Remove(AEvent);
  end;

var
  ALockedBarManager: TdxBarManager;
begin
  if FBarManager <> Value then
  begin
    ALockedBarManager := nil;
    BarManagerBeforeChange;
    try
      if FBarManager <> nil then
      begin
        if FBarManager.MergeOperationHandlers <> nil then
          FBarManager.MergeOperationHandlers.Remove(Self);
        RemoveChangeHandler(FBarManager.MDIStateChangedHandlers, MDIStateChanged);
        RemoveChangeHandler(FBarManager.SystemFontChangedHandlers, SystemFontChanged);
        RemoveChangeHandler(FBarManager.ReadIniFileHandlers, BarManagerLoadIni);
        RemoveChangeHandler(FBarManager.WriteIniFileHandlers, BarManagerSaveIni);
        FBarManager.RemoveFreeNotification(Self);
        if (Value = nil) and IsBarManagerValid then
          ALockedBarManager := FBarManager;
      end;
      FBarManager := Value;
      if IsBarManagerValid then
      begin
        FBarManager.FreeNotification(Self);
        FBarManager.MergeOperationHandlers.Add(Self);
        FBarManager.MDIStateChangedHandlers.Add(MDIStateChanged);
        FBarManager.SystemFontChangedHandlers.Add(SystemFontChanged);
        FBarManager.ReadIniFileHandlers.Add(BarManagerLoadIni);
        FBarManager.WriteIniFileHandlers.Add(BarManagerSaveIni);
        Fonts.UpdateFonts;
      end;
      if Assigned(ALockedBarManager) then ALockedBarManager.BeginUpdate;
      try
        Tabs.UpdateBarManager(Value);
        QuickAccessToolbar.DockControl.BarManager := Value;
      finally
        if Assigned(ALockedBarManager) then ALockedBarManager.EndUpdate;
      end;
    finally
      BarManagerAfterChange;
      Changed;
    end;
  end;
end;

procedure TdxCustomRibbon.SetColorScheme(Value: TdxCustomRibbonSkin);
begin
  if (FColorScheme <> Value) and (Value <> nil) then
  begin
    if FColorScheme <> nil then
      FColorScheme.RemoveReference;
    FColorScheme := Value;
    FColorScheme.AddReference;
    UpdateColorScheme;
    Modified;
  end;
end;

procedure TdxCustomRibbon.SetColorSchemeAccent(AValue: TdxRibbonColorSchemeAccent);
begin
  if AValue <> FColorSchemeAccent then
  begin
    FColorSchemeAccent := AValue;
    UpdateColorScheme;
  end;
end;

procedure TdxCustomRibbon.SetColorSchemeName(const Value: string);
begin
  ColorScheme := dxRibbonSkinsManager.Find(Value, Style);
end;

procedure TdxCustomRibbon.SetDocumentName(const Value: TCaption);
{$IFDEF DELPHI11}
var
  AForm: TCustomForm;
{$ENDIF}
begin
  if FDocumentName <> Value then
  begin
    FDocumentName := Value;
  {$IFDEF DELPHI11}
    AForm := RibbonForm;
    if (AForm <> nil) and (Application.MainForm = AForm) and (AForm.HandleAllocated) then
      SetWindowTextWithoutRedraw(AForm.Handle, ViewInfo.GetFormCaptionText);
  {$ENDIF}
    Changed;
  end;
end;

procedure TdxCustomRibbon.SetEnableTabAero(AValue: Boolean);
var
  ARibbonForm: TdxCustomRibbonForm;
begin
  if AValue <> FEnableTabAero then
  begin
    FEnableTabAero := AValue;
    ARibbonForm := RibbonForm;
    if ARibbonForm <> nil then
      ARibbonForm.UpdateBorders;
  end;
end;

procedure TdxCustomRibbon.SetFading(const Value: Boolean);
begin
  if FFading <> Value then
  begin
    FFading := Value;
    if not Value then
      dxFader.Clear;
    Invalidate;
  end;
end;

procedure TdxCustomRibbon.SetFonts(const Value: TdxRibbonFonts);
begin
  FFonts.Assign(Value);
end;

procedure TdxCustomRibbon.SetHelpButton(const Value: TdxRibbonHelpButton);
begin
  FHelpButton.Assign(Value);
end;

procedure TdxCustomRibbon.SetHelpButtonScreenTip(const Value: TdxScreenTip);
begin
  HelpButton.ScreenTip := Value;
end;

procedure TdxCustomRibbon.SetHighlightedTab(const Value: TdxRibbonTab);
begin
  if FHighlightedTab <> Value then
  begin
    if CanFade then
      dxFader.FadeOut(FHighlightedTab);
    FHighlightedTab := Value;
    if CanFade then
      dxFader.FadeIn(FHighlightedTab)
    else
      InvalidateRect(ViewInfo.GetTabsBounds, False);
  end;
end;

procedure TdxCustomRibbon.SetOptionsFading(AValue: TdxRibbonOptionsFading);
begin
  FOptionsFading.Assign(AValue);
end;

procedure TdxCustomRibbon.SetPopupMenuItems(const Value: TdxRibbonPopupMenuItems);
begin
  if Value <> FPopupMenuItems then
  begin
    FPopupMenuItems := Value;
    Changed;
  end;
end;

procedure TdxCustomRibbon.SetQuickAccessToolbar(const Value: TdxRibbonQuickAccessToolbar);
begin
  FQuickAccessToolbar.Assign(Value);
end;

procedure TdxCustomRibbon.SetShowTabGroups(const Value: Boolean);
begin
  if FShowTabGroups <> Value then
  begin
    FShowTabGroups := Value;
    InternalCloseTabGroupsPopupWindow(False);
    if not ShowTabGroups then
    begin
      if RibbonForm <> nil then
        RibbonForm.RibbonAutoHideMode.Active := False;
      if ActiveTab <> nil then
        ActiveTab.DockControl.Visible := False;
    end;
    DoMinimizeChanged;
    Changed;
  end;
end;

procedure TdxCustomRibbon.SetShowTabHeaders(const Value: Boolean);
begin
  if FShowTabHeaders <> Value then
  begin
    FShowTabHeaders := Value;
    InternalCloseTabGroupsPopupWindow(False);
    UpdateColorScheme;
  end;
end;

procedure TdxCustomRibbon.SetStyle(AValue: TdxRibbonStyle);

  function GetActualColorScheme(AValue: TdxRibbonStyle): TdxCustomRibbonSkin;
  var
    I: Integer;
  begin
    Result := dxRibbonSkinsManager.Find(ColorSchemeName, AValue);
    if Result = nil then
    begin
      for I := 0 to dxRibbonSkinsManager.SkinCount - 1 do
        if AValue = dxRibbonSkinsManager.Skins[I].Style then
        begin
          Result := dxRibbonSkinsManager.Skins[I];
          Break;
        end;
    end;
  end;

begin
  ColorScheme := GetActualColorScheme(AValue);
end;

procedure TdxCustomRibbon.SetSupportNonClientDrawing(const Value: Boolean);
begin
  if FSupportNonClientDrawing <> Value then
  begin
    if ComponentState * [csReading, csDesigning, csDestroying] = [] then
      Application.ProcessMessages;
    FSupportNonClientDrawing := Value;
    UpdateNonClientDrawing;
  end;
end;

procedure TdxCustomRibbon.SetContexts(const Value: TdxRibbonContexts);
begin
  FContexts.Assign(Value);
end;

procedure TdxCustomRibbon.SetTabs(Value: TdxRibbonTabCollection);
begin
  FTabs.Assign(Value);
end;

procedure TdxCustomRibbon.UpdateColorSchemeListeners;
begin
  FColorSchemeHandlers.CallEvents(Self, []);
end;

procedure TdxCustomRibbon.UpdateNonClientDrawing;
var
  AForm: TdxCustomRibbonForm;
begin
  AForm := RibbonForm;
  if AForm <> nil then
  begin
    CloseTabGroupsPopupWindow;
    ViewInfo.UpdateNonClientParams;

    if ViewInfo.SupportNonClientDrawing then
    begin
      if FFormCaptionHelper = nil then
        FFormCaptionHelper := CreateFormCaptionHelper;
    end
    else
      FreeAndNil(FFormCaptionHelper);

    AForm.DisableAlign;
    try
      AForm.RibbonNonClientHelper := FormCaptionHelper;
      Changed;
    finally
      AForm.EnableAlign;
    end;
    AForm.UpdateColorScheme;
    AForm.FullUpdate;
  end
  else
    FreeAndNil(FFormCaptionHelper);
end;

procedure TdxCustomRibbon.WMGetObject(var Message: TMessage);
begin
//  if CanReturnAccessibleObject(Message) then
//    Message.Result := WMGetObjectResultFromIAccessibilityHelper(Message, IAccessibilityHelper)
//  else
    inherited;
end;

procedure TdxCustomRibbon.WMPaint(var Message: TWMPaint);
begin
  if not CanPaint then Exit;
  if not FDoubleBuffered or (Message.DC <> 0) then
  begin
    if not (csCustomPaint in ControlState) and (ControlCount = 0) then
      inherited
    else
      PaintHandler(Message);
  end
  else
    dxBufferedPaintControl(Self);
end;

procedure TdxCustomRibbon.CMSelectAppMenuFirstItemControl(var Message: TMessage);
begin
  if Controller.IsApplicationMenuDropped then
    ApplicationButton.IMenu.SelectAppMenuFirstItemControl;
end;

procedure TdxCustomRibbon.CMShowKeyTips(var Message: TMessage);
begin
  if Controller.IsApplicationMenuDropped then
    ApplicationButton.IMenu.ShowKeyTips;
end;

procedure TdxCustomRibbon.BarManagerAfterChange;
var
  I: Integer;
begin
  for I := 0 to FListeners.Count - 1 do
    (FListeners[I] as IdxRibbonListener).AfterBarManagerChange;
end;

procedure TdxCustomRibbon.BarManagerBeforeChange;
var
  I: Integer;
begin
  for I := 0 to FListeners.Count - 1 do
    (FListeners[I] as IdxRibbonListener).BeforeBarManagerChange;
end;

procedure TdxCustomRibbon.BarManagerLoadIni(Sender: TObject; const AEventArgs);
var
  ASection: string;
  AEventData: TdxBarIniFileEventData;
begin
  AEventData := TdxBarIniFileEventData(AEventArgs);
  ASection := GetIniSection(AEventData.Delimiter, AEventData.BaseSection);
  if AEventData.IniFile.SectionExists(ASection) then
  begin
    QuickAccessToolbar.Position := TdxQuickAccessToolbarPosition(
      AEventData.IniFile.ReadInteger(ASection, 'QuickAccessToolbarPosition', 0));
    ShowTabGroups := AEventData.IniFile.ReadBool(ASection, 'ShowTabGroups', True);
  end;
  QuickAccessToolbar.BarManagerLoadIni(AEventData);
end;

procedure TdxCustomRibbon.BarManagerSaveIni(Sender: TObject; const AEventArgs);
var
  ASection: string;
  AEventData: TdxBarIniFileEventData;
begin
  AEventData := TdxBarIniFileEventData(AEventArgs);
  ASection := GetIniSection(AEventData.Delimiter, AEventData.BaseSection);
  AEventData.IniFile.WriteInteger(ASection, 'QuickAccessToolbarPosition', Ord(QuickAccessToolbar.Position));
  AEventData.IniFile.WriteBool(ASection, 'ShowTabGroups', ShowTabGroups);
  QuickAccessToolbar.BarManagerSaveIni(AEventData);
end;

procedure TdxCustomRibbon.MDIStateChanged(Sender: TObject; const AEventArgs);
var
  AEventData: TdxBarMDIStateChangeEventData;
begin
  if not IsDesigning and IsOnRibbonMDIForm then
  begin
    AEventData := TdxBarMDIStateChangeEventData(AEventArgs);
    if AEventData.Change in [scMaximizedChanged, scChildActivated] then
    begin
      BeginUpdate;
      try
        if IsZoomed(AEventData.Wnd) then
          DocumentName := cxGetWindowText(AEventData.Wnd)
        else
          DocumentName := '';

        Application.Title := GetTaskbarCaption;
      finally
        CancelUpdate;
        Changed;
      end;
    end;
  end;
end;

procedure TdxCustomRibbon.Merge(ARibbon: TdxCustomRibbon;
  AMergeOptions: TdxRibbonMergeOptions = dxRibbonDefaultMergeOptions);

  function CanMergeTab(ASourceTab, ATargetTab: TdxRibbonTab): Boolean;
  begin
    Result := (ASourceTab.MergeKind = ATargetTab.MergeKind) and
      (ATargetTab.Context = nil) and (ASourceTab.Caption = ATargetTab.Caption);
  end;

  function FindTargetTab(ASourceTab: TdxRibbonTab; out ATargetTab: TdxRibbonTab): Boolean;
  var
    I: Integer;
  begin
    Result := False;
    for I := 0 to Tabs.Count - 1 do
    begin
      Result := CanMergeTab(ASourceTab, Tabs[I]);
      if Result then
      begin
        ATargetTab := Tabs[I];
        Break;
      end;
    end;
  end;

var
  ATab: TdxRibbonTab;
  ATargetTab: TdxRibbonTab;
  I: Integer;
begin
  if (ARibbon = nil) or (ARibbon = Self) then
    RaiseMergingError(@dxSBAR_RIBBONCANTMERGE);
  if not (ARibbon.IsBarManagerValid and IsBarManagerValid) then
    RaiseMergingError(@dxSBAR_RIBBONCANTMERGEWITHOUTBARMANAGER);
  if ARibbon.IsMerged then
    RaiseMergingError(@dxSBAR_RIBBONONEOFTABGROUPSALREADYMERGED);

  BeginUpdate;
  try
    MergeData.Children.Add(ARibbon);
    ARibbon.MergeData.MergedWith := Self;
    ARibbon.MergeData.ActiveTabBeforeMerging := ARibbon.ActiveTab;
    ARibbon.MergeData.VisibleBeforeMerging := ARibbon.Visible;
    ARibbon.Visible := False;

    for I := 0 to ARibbon.Tabs.Count - 1 do
    begin
      ATab := ARibbon.Tabs[I];
      if ATab.IsMergeAllowed and (ATab.MergeKind = rmkMerge) then
      begin
        if FindTargetTab(ATab, ATargetTab) then
          ATargetTab.Merge(ATab, AMergeOptions);
      end;
    end;

    if rmoCanCreateNewTab in AMergeOptions then
    begin
      for I := 0 to ARibbon.Tabs.Count - 1 do
      begin
        ATab := ARibbon.Tabs[I];
        if ATab.IsMergeAllowed and not ATab.IsMerged then
        begin
          ATargetTab := CreateTabAsByMerging(ATab);
          ATargetTab.Merge(ATab, AMergeOptions);
          if ATargetTab.Groups.Count = 0 then
            ATargetTab.Free;
        end;
      end;
    end;

    QuickAccessToolbar.Merge(ARibbon.QuickAccessToolbar, AMergeOptions);
  finally
    EndUpdate;
  end;
end;

procedure TdxCustomRibbon.Unmerge(ARibbon: TdxCustomRibbon = nil);

  procedure InternalUnmerge(ARibbon: TdxCustomRibbon);
  var
    I: Integer;
  begin
    MergeData.Children.Remove(ARibbon);
    ARibbon.MergeData.MergedWith := nil;
    if not ARibbon.IsDestroying then
    begin
      ARibbon.ActiveTab := ARibbon.MergeData.ActiveTabBeforeMerging;
      ARibbon.Visible := ARibbon.MergeData.VisibleBeforeMerging;
    end;
    QuickAccessToolbar.Unmerge(ARibbon.QuickAccessToolbar);
    for I := 0 to ARibbon.Tabs.Count - 1 do
      Tabs.InternalUnmerge(ARibbon.Tabs[I]);
  end;

var
  I: Integer;
begin
  if (ARibbon = Self) then
    RaiseMergingError(@dxSBAR_RIBBONCANTUNMERGE);
  if (ARibbon <> nil) and (ARibbon.MergeData.MergedWith = nil) then
    Exit;
  if (ARibbon <> nil) and (ARibbon.MergeData.MergedWith <> Self) then
    RaiseMergingError(@dxSBAR_RIBBONSARENOTMERGED, Self, ARibbon);
  if MergeData.Children.Count = 0 then
    Exit;

  BeginUpdate;
  try
    if ARibbon <> nil then
      InternalUnmerge(ARibbon)
    else
      for I := MergeData.Children.Count - 1 downto 0 do
        InternalUnmerge(TdxCustomRibbon(MergeData.Children[I]));
  finally
    EndUpdate;
  end;
end;

procedure TdxCustomRibbon.UnmergeBeforeDestroy;
begin
  if MergeData.MergedWith <> nil then
    MergeData.MergedWith.Unmerge(Self);
  Unmerge;
end;

procedure TdxCustomRibbon.SystemFontChanged(Sender: TObject; const AEventArgs);
begin
  FontChanged;
end;

procedure TdxCustomRibbon.UpdateColorScheme;
var
  AForm: TCustomForm;
  AValid: Boolean;
begin
  AForm := GetParentForm(Self{$IFDEF DELPHI8}, False{$ENDIF});
  AValid := Assigned(AForm) and AForm.HandleAllocated and IsWindowVisible(AForm.Handle);
  if AValid then
    SendMessage(AForm.Handle, WM_SETREDRAW, 0, 0);
  try
    Fonts.UpdateFonts;
    RecalculateBars;
    Changed;
  finally
    UpdateColorSchemeListeners;
    if SupportNonClientDrawing then
      RecalculateNonClient(AForm);
    if AValid then
    begin
      SendMessage(AForm.Handle, WM_SETREDRAW, 1, 0);
      WinControlFullInvalidate(AForm, True, True);
    end;
    if RibbonForm <> nil then
      RibbonForm.UpdateColorScheme;
  end;
end;

{ TdxRibbonQuickAccessToolbarHelper }

class function TdxRibbonQuickAccessToolbarHelper.HasGroupButtonForToolbar(
  AQATLinks: TdxBarItemLinks; AToolbar: TdxBar): Boolean;
var
  AGroupButton: TdxRibbonQuickAccessGroupButton;
  ALink: TdxBarItemLinkAccess;
  I: Integer;
begin
  Result := False;
  if (AQATLinks <> nil) and (AToolbar <> nil) then
    for I := 0 to AQATLinks.Count - 1 do
    begin
      ALink := TdxBarItemLinkAccess(AQATLinks[I]);
      if not ALink.IsMarkedForDeletion and (ALink.Item is TdxRibbonQuickAccessGroupButton) then
      begin
        AGroupButton := TdxRibbonQuickAccessGroupButton(ALink.Item);
        if (AGroupButton.Toolbar = AToolbar) or TdxRibbonMergeHelper.IsMergedWith(AToolbar, AGroupButton.Toolbar) then
        begin
          Result := True;
          Break;
        end;
      end;
    end;
end;

class function TdxRibbonQuickAccessToolbarHelper.IsToolbarDockedInRibbon(
  ARibbon: TdxCustomRibbon; AToolbar: TdxBar): Boolean;
begin
  Result := (AToolbar <> nil) and (AToolbar.DockControl is TdxRibbonGroupsDockControl) and
    (TdxRibbonGroupsDockControl(AToolbar.DockControl).Ribbon = ARibbon);
end;

{ TdxRibbonQuickAccessGroupButton }

function TdxRibbonQuickAccessGroupButton.IsToolbarAcceptable(AToolbar: TdxBar): Boolean;
var
  AQATBar: TdxBar;
begin
  Result := TdxBarManagerAccess(BarManager).IsInitializing or (AToolbar = nil) or (LinkCount = 0);
  if not Result then
  begin
    AQATBar := TdxBar(Links[0].Owner.Owner);
    Result := TdxRibbonQuickAccessToolbarHelper.IsToolbarDockedInRibbon(
      TdxRibbonQuickAccessDockControl(AQATBar.RealDockControl).Ribbon, AToolbar) and
      not HasGroupButtonForToolbar(AQATBar, AToolbar);
  end;
end;

function TdxRibbonQuickAccessGroupButton.CanBePlacedOn(
  AParentKind: TdxBarItemControlParentKind; AToolbar: TdxBar; out AErrorText: string): Boolean;

  function IsDockedInRibbon(ABar: TdxBar): Boolean;
  var
    ARibbon: TdxCustomRibbon;
  begin
    if AToolbar.Control is TdxRibbonQuickAccessBarControl then
      ARibbon := TdxRibbonQuickAccessBarControl(AToolbar.Control).Ribbon
    else
      if AToolbar.DockControl is TdxRibbonQuickAccessDockControl then
        ARibbon := TdxRibbonQuickAccessDockControl(AToolbar.DockControl).Ribbon
      else
        ARibbon := nil;

    Result := TdxRibbonQuickAccessToolbarHelper.IsToolbarDockedInRibbon(ARibbon, ABar);
  end;

  function IsToolbarDockedInRibbon: Boolean;
  begin
    Result := (Toolbar.DockControl is TdxRibbonGroupsDockControl) and
      (TdxRibbonGroupsDockControl(Toolbar.DockControl).BarManager = BarManager) and
      (IsDockedInRibbon(Toolbar) or IsDockedInRibbon(TdxBarAccess(Toolbar).MergeData.MergedWith));
  end;

begin
  Result := TdxBarManagerAccess(BarManager).IsInitializing;
  if Result then
    Exit;

  if (AParentKind <> pkBar) or not GetBarControlClass(AToolbar).InheritsFrom(TdxRibbonQuickAccessBarControl) then
  begin
    AErrorText := cxGetResourceString(@dxSBAR_CANTPLACEQUICKACCESSGROUPBUTTON);
    Exit;
  end;

  if (Toolbar <> nil) and not IsToolbarDockedInRibbon then
  begin
    AErrorText := cxGetResourceString(@dxSBAR_QUICKACCESSGROUPBUTTONTOOLBARNOTDOCKEDINRIBBON);
    Exit;
  end;

  if HasGroupButtonForToolbar(AToolbar, Toolbar) then
  begin
    AErrorText := cxGetResourceString(@dxSBAR_QUICKACCESSALREADYHASGROUPBUTTON);
    Exit;
  end;
  Result := True;
end;

procedure TdxRibbonQuickAccessGroupButton.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = Toolbar) then
    Toolbar := nil;
end;

function TdxRibbonQuickAccessGroupButton.GetActualToolbar: TdxBar;
begin
  if (Toolbar <> nil) and (TdxBarAccess(Toolbar).MergeData.MergedWith <> nil) then
    Result := TdxBarAccess(Toolbar).MergeData.MergedWith
  else
    Result := Toolbar;
end;

function TdxRibbonQuickAccessGroupButton.GetCaption: string;
begin
  if Toolbar = nil then
    Result := 'GroupButton'
  else
    Result := dxRibbonGetGroupCaption(Toolbar);
end;

function TdxRibbonQuickAccessGroupButton.IsCaptionStored: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonQuickAccessGroupButton.SetCaption(const Value: string);
begin
end;

function TdxRibbonQuickAccessGroupButton.HasGroupButtonForToolbar(AParentBar, AToolbar: TdxBar): Boolean;
var
  AParentBarItemLinks: TdxBarItemLinks;
begin
  if AParentBar.Control <> nil then
    AParentBarItemLinks := AParentBar.Control.ItemLinks
  else
    AParentBarItemLinks := AParentBar.ItemLinks;

  Result := TdxRibbonQuickAccessToolbarHelper.HasGroupButtonForToolbar(AParentBarItemLinks, AToolbar);
end;

procedure TdxRibbonQuickAccessGroupButton.SetToolbar(Value: TdxBar);
begin
  if IsToolbarAcceptable(Value) and (Value <> FToolbar) then
  begin
    if FToolbar <> nil then
    begin
      FToolbar.RemoveFreeNotification(Self);
      FToolbar := nil;
    end;
    if Value <> nil then
    begin
      FToolbar := Value;
      FToolbar.FreeNotification(Self);
    end;
    Update;
  end;
end;

{ TdxRibbonQuickAccessGroupButtonControl }

destructor TdxRibbonQuickAccessGroupButtonControl.Destroy;
begin
  ClosePopup;
  inherited Destroy;
end;

function TdxRibbonQuickAccessGroupButtonControl.IsDroppedDown: Boolean;
begin
  Result := FPopupBarControl <> nil;
end;

procedure TdxRibbonQuickAccessGroupButtonControl.CalcDrawParams(AFull: Boolean = True);
begin
  inherited CalcDrawParams(AFull);
  DrawParams.DroppedDown := IsDroppedDown;
  DrawParams.Enabled := DrawParams.Enabled and (Item.IsDesigning or (Item.Toolbar <> nil));
end;

function TdxRibbonQuickAccessGroupButtonControl.CanActivate: Boolean;
begin
  Result := not BarManager.Designing and inherited CanActivate;
end;

procedure TdxRibbonQuickAccessGroupButtonControl.ControlClick(AByMouse: Boolean;
  AKey: Char = #0);
begin
  inherited ControlClick(AByMouse, AKey);
  if TdxRibbonQuickAccessBarControl(Parent).IsDowned then
    ControlActivate(True, AByMouse);
end;

procedure TdxRibbonQuickAccessGroupButtonControl.DoCloseUp(
  AHadSubMenuControl: Boolean);
begin
  ClosePopup;
  Repaint;
end;

procedure TdxRibbonQuickAccessGroupButtonControl.DoDropDown(AByMouse: Boolean);
var
  AToolbar: TdxBar;
  R: TRect;
begin
  AToolbar := Item.Toolbar;
  if AToolbar <> nil then
  begin
    FPopupBarControl := TdxRibbonQuickAccessGroupButtonPopupBarControl.CreateForPopup(Self);
    R := ItemLink.ItemRect;
    R.TopLeft := Parent.ClientToScreen(R.TopLeft);
    R.BottomRight := Parent.ClientToScreen(R.BottomRight);
    BarDesignController.ShowQuickControl(FPopupBarControl, Painter, R);
    if BarNavigationController.NavigationMode and not BarNavigationController.KeyTipsHandlingMode then
      SelectFirstSelectableAccessibleObject(FPopupBarControl.IAccessibilityHelper.GetBarHelper);
    Repaint;
  end;
end;

procedure TdxRibbonQuickAccessGroupButtonControl.DoPaint(ARect: TRect;
  PaintType: TdxBarPaintType);
begin
  TdxRibbonQuickAccessPainter(Painter).DrawGroupButtonControl(DrawParams, ARect);
end;

procedure TdxRibbonQuickAccessGroupButtonControl.DropDown(AByMouse: Boolean);
begin
  inherited DropDown(AByMouse);
  Click(AByMouse);
end;

function TdxRibbonQuickAccessGroupButtonControl.CanDestroyOnClick: Boolean;
begin
  Result := False;
end;

function TdxRibbonQuickAccessGroupButtonControl.IsDropDown: Boolean;
begin
  Result := True;
end;

procedure TdxRibbonQuickAccessGroupButtonControl.ClosePopup;
begin
  FreeAndNil(FPopupBarControl);
end;

function TdxRibbonQuickAccessGroupButtonControl.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper;
end;

function TdxRibbonQuickAccessGroupButtonControl.GetCurrentImage(
  AViewSize: TdxBarItemControlViewSize; ASelected: Boolean;
  out ACurrentGlyph: TBitmap; out ACurrentImages: TCustomImageList;
  out ACurrentImageIndex: Integer): Boolean;
begin
  if Item.Toolbar <> nil then
    ACurrentGlyph := Item.Toolbar.Glyph
  else
    ACurrentGlyph := nil;
  if (ACurrentGlyph <> nil) and ACurrentGlyph.Empty then
    ACurrentGlyph := nil;
  ACurrentImages := nil;
  Result := ACurrentGlyph <> nil;
end;

function TdxRibbonQuickAccessGroupButtonControl.GetHint: string;
begin
  Result := ItemLink.Caption;
end;

function TdxRibbonQuickAccessGroupButtonControl.GetItem: TdxRibbonQuickAccessGroupButton;
begin
  Result := TdxRibbonQuickAccessGroupButton(inherited Item);
end;

function TdxRibbonQuickAccessGroupButtonControl.GetViewStructure: TdxBarItemControlViewStructure;
begin
  Result := [cpIcon];
end;

{ TdxRibbonQuickAccessGroupButtonPopupBarControl }

constructor TdxRibbonQuickAccessGroupButtonPopupBarControl.CreateForPopup(
  AGroupButtonControl: TdxRibbonQuickAccessGroupButtonControl);
var
  AToolbar: TdxBar;
begin
  AToolbar := AGroupButtonControl.Item.ActualToolbar;
  inherited Create(AToolbar.BarManager);
  InitializeForPopup(TdxBarControl(AGroupButtonControl.Parent), AToolbar);
  FGroupButtonControl := AGroupButtonControl;
end;

procedure TdxRibbonQuickAccessGroupButtonPopupBarControl.CloseUp;
begin
  FGroupButtonControl.ClosePopup;
end;

function TdxRibbonQuickAccessGroupButtonPopupBarControl.CanActiveChange: Boolean;
begin
  Result := not FIsActiveChangeLocked and inherited CanActiveChange;
end;

procedure TdxRibbonQuickAccessGroupButtonPopupBarControl.CreateWnd;
begin
  inherited CreateWnd;
  IsActive := True;
end;

procedure TdxRibbonQuickAccessGroupButtonPopupBarControl.DestroyWnd;
begin
  if FGroupButtonControl.MousePressed then
    TdxRibbonQuickAccessBarControl(FGroupButtonControl.Parent).IgnoreMouseClick := True;
  inherited DestroyWnd;
end;

procedure TdxRibbonQuickAccessGroupButtonPopupBarControl.FocusItemControl(
  AItemControl: TdxBarItemControl);
begin
  if AItemControl <> nil then
  begin
    FIsActiveChangeLocked := True;
    try
      inherited FocusItemControl(AItemControl);
    finally
      FIsActiveChangeLocked := False;
    end;
  end;
end;

function TdxRibbonQuickAccessGroupButtonPopupBarControl.GetBehaviorOptions: TdxBarBehaviorOptions;
begin
  Result := inherited GetBehaviorOptions + [bboNeedsFocusWhenActive];
end;

procedure TdxRibbonQuickAccessGroupButtonPopupBarControl.HideAllByEscape;
var
  AGroupButtonControlToSelect: TdxRibbonQuickAccessGroupButtonControl;
begin
  if BarNavigationController.NavigationMode then
    AGroupButtonControlToSelect := FGroupButtonControl
  else
    AGroupButtonControlToSelect := nil;
  inherited HideAllByEscape;
  if AGroupButtonControlToSelect <> nil then
    AGroupButtonControlToSelect.IAccessibilityHelper.Select(False);
end;

function TdxRibbonQuickAccessGroupButtonPopupBarControl.IsAllowContextPaint: Boolean;
begin
  Result := False;
end;

{ TdxAddGroupButtonEditor }

class function TdxAddGroupButtonEditor.GetAddedItemClass(const AAddedItemName: string): TdxBarItemClass;
begin
  Result := TdxRibbonQuickAccessGroupButton;
end;

class function TdxAddGroupButtonEditor.GetPopupItemCaption: string;
begin
  Result := dxSBAR_CP_ADDGROUPBUTTON;
end;

{ TdxRibbonAccessibilityHelper }

constructor TdxRibbonAccessibilityHelper.Create(AOwnerObject: TObject);
begin
  inherited;
  FAccessibilityChilds := TList.Create;
end;

destructor TdxRibbonAccessibilityHelper.Destroy;
begin
  FreeAndNil(FAccessibilityChilds);
  inherited;
end;

// IdxBarAccessibilityHelper
function TdxRibbonAccessibilityHelper.AreKeyTipsSupported(
  out AKeyTipWindowsManager: IdxBarKeyTipWindowsManager): Boolean;
begin
  Result := True;
  if FKeyTipWindowsManager = nil then
    FKeyTipWindowsManager := TdxRibbonKeyTipWindows.Create(Ribbon);
  AKeyTipWindowsManager := FKeyTipWindowsManager;
end;

function TdxRibbonAccessibilityHelper.GetBarManager: TdxBarManager;
begin
  Result := Ribbon.BarManager;
end;

function TdxRibbonAccessibilityHelper.GetDefaultAccessibleObject: IdxBarAccessibilityHelper;
begin
  Result := nil;
  if Ribbon.AreGroupsVisible then
    Result := Ribbon.TabsIAccessibilityHelper.GetDefaultAccessibleObject;
  if (Result = nil) and Ribbon.ApplicationButton.IAccessibilityHelper.GetHelper.Visible then
    Result := Ribbon.ApplicationButton.IAccessibilityHelper;
end;

function TdxRibbonAccessibilityHelper.GetChild(AIndex: Integer): TcxAccessibilityHelper;
begin
  Result := IdxBarAccessibilityHelper(FAccessibilityChilds[AIndex]).GetHelper;
end;

function TdxRibbonAccessibilityHelper.GetChildCount: Integer;

  procedure AddAccessibilityChild(AChild: IdxBarAccessibilityHelper);
  begin
    FAccessibilityChilds.Add(Pointer(AChild));
  end;

var
  I: Integer;
begin
  FAccessibilityChilds.Clear;
  AddAccessibilityChild(Ribbon.TabsIAccessibilityHelper);
  for I := 0 to Ribbon.ViewInfo.TabsAreaButtonsViewInfo.Count - 1 do
    AddAccessibilityChild(Ribbon.ViewInfo.TabsAreaButtonsViewInfo[I].AccessibilityHelper);
  AddAccessibilityChild(Ribbon.ApplicationButton.IAccessibilityHelper);
  for I := 0 to Ribbon.FAffiliatedBarControlsForAccessibility.Count - 1 do
    AddAccessibilityChild(TCustomdxBarControl(Ribbon.FAffiliatedBarControlsForAccessibility[I]).IAccessibilityHelper);
  if Ribbon.QATIAccessibilityHelper <> nil then
    AddAccessibilityChild(Ribbon.QATIAccessibilityHelper);

  Result := FAccessibilityChilds.Count;
end;

function TdxRibbonAccessibilityHelper.GetChildIndex(
  AChild: TcxAccessibilityHelper): Integer;
begin
  Result := FAccessibilityChilds.IndexOf(Pointer(dxBar.GetAccessibilityHelper(AChild)));
end;

function TdxRibbonAccessibilityHelper.GetOwnerObjectWindow: HWND;
begin
  if Ribbon.HandleAllocated then
    Result := Ribbon.Handle
  else
    Result := 0;
end;

function TdxRibbonAccessibilityHelper.GetScreenBounds(
  AChildID: TcxAccessibleSimpleChildElementID): TRect;
begin
  if Visible then
    Result := cxGetWindowRect(GetOwnerObjectWindow)
  else
    Result := cxEmptyRect;
end;

function TdxRibbonAccessibilityHelper.GetState(
  AChildID: TcxAccessibleSimpleChildElementID): Integer;
var
  AHandle: HWND;
begin
  Result := cxSTATE_SYSTEM_NORMAL;
  AHandle := GetOwnerObjectWindow;
  if (AHandle = 0) or not IsWindowVisible(AHandle) then
    Result := Result or cxSTATE_SYSTEM_INVISIBLE;
end;

function TdxRibbonAccessibilityHelper.LogicalNavigationGetChild(
  AIndex: Integer): TdxBarAccessibilityHelper;
begin
  Result := Childs[AIndex];
end;

function TdxRibbonAccessibilityHelper.LogicalNavigationGetChildIndex(
  AChild: TdxBarAccessibilityHelper): Integer;
begin
  Result := GetChildIndex(AChild);
end;

function TdxRibbonAccessibilityHelper.GetRibbon: TdxCustomRibbon;
begin
  Result := TdxCustomRibbon(FOwnerObject);
end;

function TdxRibbonAccessibilityHelper.GetTabsAreaButtonsViewInfo: TdxRibbonButtonsContainerViewInfo;
begin
  Result := Ribbon.ViewInfo.TabsAreaButtonsViewInfo;
end;

{ TdxRibbonTabCollectionAccessibilityHelper }

// IdxBarAccessibilityHelper
function TdxRibbonTabCollectionAccessibilityHelper.GetBarManager: TdxBarManager;
begin
  Result := TabCollection.Owner.BarManager;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetDefaultAccessibleObject: IdxBarAccessibilityHelper;
begin
  if TabCollection.Owner.ActiveTab <> nil then
    Result := TabCollection.Owner.ActiveTab.IAccessibilityHelper
  else
    Result := nil;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetChild(
  AIndex: Integer): TcxAccessibilityHelper;
begin
  Result := TabCollection[AIndex].IAccessibilityHelper.GetHelper;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetChildCount: Integer;
begin
  Result := TabCollection.Count;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetChildIndex(
  AChild: TcxAccessibilityHelper): Integer;
begin
  if (AChild is TdxRibbonTabAccessibilityHelper) and (TdxRibbonTabAccessibilityHelper(AChild).Parent = Self) then
    Result := TdxRibbonTabAccessibilityHelper(AChild).Tab.Index
  else
    Result := -1;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetOwnerObjectWindow: HWND;
begin
  Result := Parent.OwnerObjectWindow;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetParent: TcxAccessibilityHelper;
begin
  Result := TabCollection.Owner.IAccessibilityHelper.GetHelper;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetScreenBounds(
  AChildID: TcxAccessibleSimpleChildElementID): TRect;
begin
  if Visible then
  begin
    Result := TabCollection.Owner.ViewInfo.TabsViewInfo.Bounds;
    with TabCollection.Owner do
    begin
      Result.TopLeft := ClientToScreen(Result.TopLeft);
      Result.BottomRight := ClientToScreen(Result.BottomRight);
    end;
  end
  else
    Result := cxEmptyRect;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetState(
  AChildID: TcxAccessibleSimpleChildElementID): Integer;
begin
  Result := Parent.States[cxAccessibleObjectSelfID];
  if not TabCollection.Owner.ViewInfo.IsTabsVisible then
    Result := Result or cxSTATE_SYSTEM_INVISIBLE;
end;

//function TdxRibbonTabCollectionAccessibilityHelper.ChildIsSimpleElement(
//  AIndex: Integer): Boolean;
//begin
//  Result := False;
//end;
//
//function TdxRibbonTabCollectionAccessibilityHelper.GetChildIndex(
//  AChild: TcxAccessibilityHelper): Integer;
//var
//  I: Integer;
//begin
//  Result := -1;
//  for I := 0 to TabCollection.Count - 1 do
//    if GetChild(I) = AChild then
//    begin
//      Result := I;
//      Break;
//    end;
//end;
//
//function TdxRibbonTabCollectionAccessibilityHelper.GetName(
//  AChildID: TcxAccessibleSimpleChildElementID): string;
//begin
//  Result := cxGetResourceString(@dxSBAR_ACCESSIBILITY_RIBBONTABCOLLECTIONNAME);
//end;
//
//function TdxRibbonTabCollectionAccessibilityHelper.GetRole(
//  AChildID: TcxAccessibleSimpleChildElementID): Integer;
//begin
//  Result := cxROLE_SYSTEM_PAGETABLIST;
//end;
//
//function TdxRibbonTabCollectionAccessibilityHelper.GetSupportedProperties(
//  AChildID: TcxAccessibleSimpleChildElementID): TcxAccessibleObjectProperties;
//begin
//  Result := [aopLocation];
//end;

function TdxRibbonTabCollectionAccessibilityHelper.LogicalNavigationGetChild(
  AIndex: Integer): TdxBarAccessibilityHelper;
begin
  if TabCollection.Owner.AreGroupsVisible then
    Result := TabCollection.Owner.ActiveTab.IAccessibilityHelper.GetBarHelper
  else
    Result := GetFirstSelectableObject;
end;

function TdxRibbonTabCollectionAccessibilityHelper.LogicalNavigationGetChildCount: Integer;
var
  AAreGroupsVisible: Boolean;
begin
  AAreGroupsVisible := TabCollection.Owner.AreGroupsVisible;
  if AAreGroupsVisible and (TabCollection.Owner.ActiveTab <> nil) or
    not AAreGroupsVisible and (GetFirstSelectableObject <> nil) then
      Result := 1
  else
    Result := 0;
end;

function TdxRibbonTabCollectionAccessibilityHelper.LogicalNavigationGetChildIndex(
  AChild: TdxBarAccessibilityHelper): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to LogicalNavigationGetChildCount - 1 do
    if AChild = LogicalNavigationGetChild(I) then
    begin
      Result := I;
      Break;
    end;
end;

function TdxRibbonTabCollectionAccessibilityHelper.GetTabCollection: TdxRibbonTabCollection;
begin
  Result := TdxRibbonTabCollection(FOwnerObject);
end;

{ TdxRibbonTabAccessibilityHelper }

procedure TdxRibbonTabAccessibilityHelper.CloseUpHandler(AReason: TdxBarCloseUpReason);
begin
  if (AReason = bcrEscape) and BarNavigationController.NavigationMode then
    Select(False);
end;

// IdxBarAccessibilityHelper
function TdxRibbonTabAccessibilityHelper.GetBarManager: TdxBarManager;
begin
  Result := Ribbon.BarManager;
end;

function TdxRibbonTabAccessibilityHelper.GetNextAccessibleObject(
  ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;
var
  ADockControlObject: TdxBarAccessibilityHelper;
begin
  Result := nil;
  case ADirection of
    andLeft, andRight:
      Result := Ribbon.GetNextHorizontalAccessibleObject(Self, ADirection);
    andUp:
      if Ribbon.QATIAccessibilityHelper = nil then
        Result := Self;
    andDown:
      begin
        ADockControlObject := Tab.DockControl.IAccessibilityHelper.GetBarHelper;
        if ADockControlObject.Visible then
          Result := ADockControlObject.GetFirstSelectableObject;
      end;
  end;
  if Result = nil then
    Result := inherited GetNextAccessibleObject(ADirection);
end;

function TdxRibbonTabAccessibilityHelper.HandleNavigationKey(var AKey: Word): Boolean;
begin
  Result := inherited HandleNavigationKey(AKey);
  if not Result and not Ribbon.AreGroupsVisible then
  begin
    Result := AKey in [VK_RETURN, VK_SPACE];
    if Result then
    begin
      Tab.Active := True;
      Ribbon.ShowTabGroupsPopupWindow;
      SelectFirstSelectableAccessibleObject(Tab.DockControl.IAccessibilityHelper.GetBarHelper);
    end;
  end;
end;

function TdxRibbonTabAccessibilityHelper.IsNavigationKey(AKey: Word): Boolean;
begin
  Result := inherited IsNavigationKey(AKey) or (AKey = VK_ESCAPE);
  if not Ribbon.AreGroupsVisible then
    Result := Result or (AKey in [VK_RETURN, VK_SPACE]);
end;

function TdxRibbonTabAccessibilityHelper.LogicalNavigationGetNextAccessibleObject(
  AShift: TShiftState): IdxBarAccessibilityHelper;
var
  AGoForward: Boolean;
begin
  AGoForward := not(ssShift in AShift);
  if AGoForward then
    Result := LogicalNavigationGetNextChild(-1, True)
  else
    Result := inherited LogicalNavigationGetNextAccessibleObject(AShift);
end;

procedure TdxRibbonTabAccessibilityHelper.Select(ASetFocus: Boolean);
begin
  inherited Select(ASetFocus);
  if Ribbon.AreGroupsVisible then
    Tab.Active := True;
  Tab.Invalidate;
end;

procedure TdxRibbonTabAccessibilityHelper.Unselect(
  ANextSelectedObject: IdxBarAccessibilityHelper);
begin
  inherited Unselect(ANextSelectedObject);
  Tab.Invalidate;
end;

function TdxRibbonTabAccessibilityHelper.GetChild(
  AIndex: Integer): TcxAccessibilityHelper;
begin
  Result := Tab.DockControl.IAccessibilityHelper.GetHelper;
end;

function TdxRibbonTabAccessibilityHelper.GetChildCount: Integer;
begin
  Result := 1;
end;

function TdxRibbonTabAccessibilityHelper.GetChildIndex(
  AChild: TcxAccessibilityHelper): Integer;
begin
  if AChild = Tab.DockControl.IAccessibilityHelper.GetHelper then
    Result := 0
  else
    Result := -1;
end;

function TdxRibbonTabAccessibilityHelper.GetOwnerObjectWindow: HWND;
begin
  Result := Parent.OwnerObjectWindow;
end;

function TdxRibbonTabAccessibilityHelper.GetParent: TcxAccessibilityHelper;
begin
  Result := TdxRibbonTabCollection(Tab.Collection).IAccessibilityHelper.GetHelper;
end;

function TdxRibbonTabAccessibilityHelper.GetScreenBounds(
  AChildID: TcxAccessibleSimpleChildElementID): TRect;
begin
  if Visible then
  begin
    Result := Tab.ViewInfo.Bounds;
    Result.TopLeft := Ribbon.ClientToScreen(Result.TopLeft);
    Result.BottomRight := Ribbon.ClientToScreen(Result.BottomRight);
  end
  else
    Result := cxEmptyRect;
end;

function TdxRibbonTabAccessibilityHelper.GetSelectable: Boolean;
begin
  Result := Visible;
end;

function TdxRibbonTabAccessibilityHelper.GetState(
  AChildID: TcxAccessibleSimpleChildElementID): Integer;
begin
  Result := Parent.States[cxAccessibleObjectSelfID];
  if not Tab.IsVisible then
    Result := Result or cxSTATE_SYSTEM_INVISIBLE;
end;

function TdxRibbonTabAccessibilityHelper.GetAssignedKeyTip: string;
begin
  Result := Tab.KeyTip;
  if (Length(Result) > 0) and dxCharInSet(Result[1], ['0'..'9']) then
    Result := '';
end;

function TdxRibbonTabAccessibilityHelper.GetDefaultKeyTip: string;
begin
  Result := 'Y';
end;

procedure TdxRibbonTabAccessibilityHelper.GetKeyTipInfo(out AKeyTipInfo: TdxBarKeyTipInfo);
var
  ABasePoint: TPoint;
  ATextMetric: TTextMetric;
begin
  inherited GetKeyTipInfo(AKeyTipInfo);
  cxGetTextMetrics(Tab.ViewInfo.Font, ATextMetric);
  with Tab.ViewInfo.TextBounds do
  begin
    ABasePoint.X := (Left + Right) div 2;
    ABasePoint.Y := Bottom - ATextMetric.tmDescent;
  end;
  AKeyTipInfo.BasePoint := Tab.Ribbon.ClientToScreen(ABasePoint);
  AKeyTipInfo.HorzAlign := taCenter;
  AKeyTipInfo.VertAlign := vaBottom;
  AKeyTipInfo.Enabled := True;
end;

procedure TdxRibbonTabAccessibilityHelper.KeyTipHandler(Sender: TObject);
begin
  BarNavigationController.ChangeSelectedObject(True, Self);
  if not Ribbon.AreGroupsVisible then
  begin
    Tab.Active := True;
    BarNavigationController.UnselectAssignedSelectedObject;
    Ribbon.ShowTabGroupsPopupWindow;
  end;
  BarNavigationController.SetKeyTipsShowingState(Self, '');
end;

procedure TdxRibbonTabAccessibilityHelper.KeyTipsEscapeHandler;
begin
  Ribbon.CloseTabGroupsPopupWindow;
  inherited KeyTipsEscapeHandler;
end;

function TdxRibbonTabAccessibilityHelper.GetRibbon: TdxCustomRibbon;
begin
  Result := Tab.Ribbon;
end;

function TdxRibbonTabAccessibilityHelper.GetTab: TdxRibbonTab;
begin
  Result := FOwnerObject as TdxRibbonTab;
end;

{ TdxRibbonApplicationButtonAccessibilityHelper }

// IdxBarAccessibilityHelper
function TdxRibbonApplicationButtonAccessibilityHelper.GetBarManager: TdxBarManager;
begin
  Result := Ribbon.BarManager;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetNextAccessibleObject(
  ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;
begin
  Result := nil;
  case ADirection of
    andLeft, andRight:
      Result := Ribbon.GetNextHorizontalAccessibleObject(Self, ADirection);
    andUp:
      Result := Self;
  end;
  if Result = nil then
    Result := inherited GetNextAccessibleObject(ADirection);
end;

function TdxRibbonApplicationButtonAccessibilityHelper.HandleNavigationKey(
  var AKey: Word): Boolean;
begin
  Result := inherited HandleNavigationKey(AKey);
  if not Result then
  begin
    Result := AKey in [VK_DOWN, VK_SPACE, VK_RETURN];
    if Result then
      ShowApplicationMenu(DXM_BAR_SELECTAPPMENUFIRSTITEMCONTROL);
  end;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.IsNavigationKey(AKey: Word): Boolean;
begin
  Result := inherited IsNavigationKey(AKey) or (AKey in [VK_ESCAPE, VK_SPACE, VK_RETURN]);
end;

procedure TdxRibbonApplicationButtonAccessibilityHelper.Select(ASetFocus: Boolean);
begin
  inherited Select(ASetFocus);
  ApplicationButtonViewInfo.Invalidate;
end;

procedure TdxRibbonApplicationButtonAccessibilityHelper.Unselect(
  ANextSelectedObject: IdxBarAccessibilityHelper);
begin
  inherited Unselect(ANextSelectedObject);
  ApplicationButtonViewInfo.Invalidate;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetOwnerObjectWindow: HWND;
begin
  Result := Parent.OwnerObjectWindow;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetParent: TcxAccessibilityHelper;
begin
  Result := Ribbon.IAccessibilityHelper.GetHelper;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetScreenBounds(
  AChildID: TcxAccessibleSimpleChildElementID): TRect;
begin
  if Visible then
  begin
    Result := ApplicationButtonViewInfo.Bounds;
    Result.TopLeft := Ribbon.ClientToScreen(Result.TopLeft);
    Result.BottomRight := Ribbon.ClientToScreen(Result.BottomRight);
  end
  else
    Result := cxEmptyRect;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetSelectable: Boolean;
begin
  Result := Visible;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetState(
  AChildID: TcxAccessibleSimpleChildElementID): Integer;
begin
  Result := Parent.States[cxAccessibleObjectSelfID];
  if not ApplicationButtonViewInfo.IsVisible then
    Result := Result or cxSTATE_SYSTEM_INVISIBLE;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetAssignedKeyTip: string;
begin
  Result := Ribbon.ApplicationButton.KeyTip;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetDefaultKeyTip: string;
begin
  Result := 'F';
end;

procedure TdxRibbonApplicationButtonAccessibilityHelper.GetKeyTipInfo(out AKeyTipInfo: TdxBarKeyTipInfo);
begin
  inherited GetKeyTipInfo(AKeyTipInfo);
  AKeyTipInfo.BasePoint := cxRectCenter(GetScreenBounds(cxAccessibleObjectSelfID));
  AKeyTipInfo.HorzAlign := taCenter;
  AKeyTipInfo.VertAlign := vaCenter;
  AKeyTipInfo.Enabled := True;
end;

procedure TdxRibbonApplicationButtonAccessibilityHelper.KeyTipHandler(Sender: TObject);
begin
  ShowApplicationMenu(DXM_BAR_SHOWKEYTIPS);
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetApplicationButtonViewInfo: TdxRibbonApplicationButtonViewInfo;
begin
  Result := Ribbon.ApplicationButtonViewInfo;
end;

function TdxRibbonApplicationButtonAccessibilityHelper.GetRibbon: TdxCustomRibbon;
begin
  Result := TdxRibbonApplicationButton(FOwnerObject).Ribbon;
end;

procedure TdxRibbonApplicationButtonAccessibilityHelper.ShowApplicationMenu(
  APostMessage: UINT);
begin
  BarNavigationController.UnselectAssignedSelectedObject;
  CloseActiveRibbonApplicationMenus;
  BarNavigationController.SetKeyTipsShowingState(nil, '');
  PostMessage(Ribbon.Handle, DXM_RIBBON_SHOWAPPLICATIONMENU, 0, 0);
  if Ribbon.ApplicationButton.IMenu <> nil then
    PostMessage(Ribbon.Handle, APostMessage, 0, 0);
end;

{ TdxRibbonGroupsDockControlAccessibilityHelper }

function TdxRibbonGroupsDockControlAccessibilityHelper.GetChild(
  AIndex: Integer): TcxAccessibilityHelper;
begin
  Result := DockControl.ViewInfo.GroupViewInfos[AIndex].BarControl.IAccessibilityHelper.GetHelper;
end;

function TdxRibbonGroupsDockControlAccessibilityHelper.GetChildCount: Integer;
begin
  Result := DockControl.ViewInfo.GroupCount;
end;

function TdxRibbonGroupsDockControlAccessibilityHelper.GetChildIndex(
  AChild: TcxAccessibilityHelper): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to ChildCount - 1 do
    if Childs[I] = AChild then
    begin
      Result := I;
      Break;
    end;
end;

function TdxRibbonGroupsDockControlAccessibilityHelper.GetParent: TcxAccessibilityHelper;
begin
  if dxBarGetParentPopupWindow(DockControl, False) <> nil then
    Result := nil
  else
    Result := TdxRibbonGroupsDockControl(DockControl).Tab.IAccessibilityHelper.GetHelper;
end;

function TdxRibbonGroupsDockControlAccessibilityHelper.GetState(
  AChildID: TcxAccessibleSimpleChildElementID): Integer;
begin
  Result := inherited GetState(AChildID);
  if not TdxRibbonGroupsDockControl(DockControl).Tab.Ribbon.AreGroupsVisible then
    Result := Result or cxSTATE_SYSTEM_INVISIBLE;
end;

function TdxRibbonGroupsDockControlAccessibilityHelper.GetParentForKeyTip: TdxBarAccessibilityHelper;
begin
  if dxBarGetParentPopupWindow(DockControl, False) <> nil then
    Result := DockControl.Tab.IAccessibilityHelper.GetBarHelper
  else
    Result := inherited GetParentForKeyTip;
end;

function TdxRibbonGroupsDockControlAccessibilityHelper.GetDockControl: TdxRibbonGroupsDockControl;
begin
  Result := TdxRibbonGroupsDockControl(FOwnerObject);
end;

{ TdxRibbonBarControlAccessibilityHelper }

function TdxRibbonBarControlAccessibilityHelper.LogicalNavigationGetNextChild(AChildIndex: Integer;
  AShift: TShiftState): TdxBarAccessibilityHelper;
begin
  Result := LogicalNavigationGetNextChild(AChildIndex, not(ssShift in AShift));
end;

{ TdxRibbonQuickAccessToolbarAccessibilityHelper }

function TdxRibbonQuickAccessBarControlAccessibilityHelper.GetChild(
  AIndex: Integer): TcxAccessibilityHelper;
begin
  if AIndex = ChildCount - 1 then
    Result := BarControl.MarkIAccessibilityHelper.GetHelper
  else
    Result := inherited GetChild(AIndex);
end;

function TdxRibbonQuickAccessBarControlAccessibilityHelper.GetChildCount: Integer;
begin
  Result := inherited GetChildCount;
  if TCustomdxBarControlAccess(BarControl).MarkExists then
    Inc(Result);
end;

function TdxRibbonQuickAccessBarControlAccessibilityHelper.GetChildIndex(
  AChild: TcxAccessibilityHelper): Integer;
begin
  if AChild = BarControl.MarkIAccessibilityHelper.GetHelper then
    Result := inherited GetChildCount
  else
    Result := inherited GetChildIndex(AChild);
end;

function TdxRibbonQuickAccessBarControlAccessibilityHelper.GetParent: TcxAccessibilityHelper;
begin
  Result := TdxRibbonQuickAccessBarControl(BarControl).Ribbon.IAccessibilityHelper.GetHelper;
end;

procedure TdxRibbonQuickAccessBarControlAccessibilityHelper.DoGetKeyTipsData(AKeyTipsData: TList);

  procedure GetItemsKeyTipsData(
    ABarControl: TCustomdxBarControl; AStartIndex, AEndIndex: Integer; AKeyTipsData: TList; AVisible: Boolean);
  var
    I: Integer;
    AChild: TdxBarAccessibilityHelper;
    AKeyTipData: TdxBarKeyTipData;
  begin
    for I := AStartIndex to AEndIndex do
    begin
      AChild := ABarControl.ItemLinks.VisibleItems[I].Control.IAccessibilityHelper.GetBarHelper;
      AKeyTipData := TdxBarAccessibilityHelperAccess(AChild).CreateKeyTipData;
      AKeyTipData.Visible := AVisible;
      AKeyTipsData.Add(AKeyTipData);
    end;
  end;

  procedure GenerateKeyTips(AItemKeyTipsData: TList);
  var
    I: Integer;
  begin
    for I := 0 to AItemKeyTipsData.Count - 1 do
    begin
      case I of
        0..8: TdxBarKeyTipData(AItemKeyTipsData[I]).KeyTip := IntToStr(I + 1);                   // '1'..'9'
        9..17: TdxBarKeyTipData(AItemKeyTipsData[I]).KeyTip := '0' + IntToStr(18 - I);           // '09'..'01'
        18..44: TdxBarKeyTipData(AItemKeyTipsData[I]).KeyTip := '0' + Char(Ord('A') + (I - 18)); // '0A'..'0Z'
      else
        TdxBarKeyTipData(AItemKeyTipsData[I]).KeyTip := '';
      end;
      AKeyTipsData.Add(AItemKeyTipsData[I])
    end;
  end;

var
  VisibleItemCount, ARealVisibleItemCount: Integer;
  AItemKeyTipsData: TList;
begin
  AItemKeyTipsData := TList.Create;
  try
    VisibleItemCount := TdxBarItemLinksAccess(BarControl.ItemLinks).VisibleItemCount;
    if BarControl.IsPopup then
    begin
      ARealVisibleItemCount := TdxBarItemLinksAccess(BarControl.ParentBar.ItemLinks).RealVisibleItemCount;
      GetItemsKeyTipsData(BarControl.ParentBar, 0, ARealVisibleItemCount - 1, AItemKeyTipsData, False);
      GetItemsKeyTipsData(BarControl, 0, VisibleItemCount - 1 - 1{Mark!!!}, AItemKeyTipsData, True);
    end
    else
    begin
      ARealVisibleItemCount := TdxBarItemLinksAccess(BarControl.ItemLinks).RealVisibleItemCount;
      GetItemsKeyTipsData(BarControl, 0, ARealVisibleItemCount - 1, AItemKeyTipsData, True);
      GetItemsKeyTipsData(BarControl, ARealVisibleItemCount, VisibleItemCount - 1, AItemKeyTipsData, False);
      if not BarControl.AllItemsVisible then
        TdxBarAccessibilityHelperAccess(BarControl.MarkIAccessibilityHelper.GetBarHelper).GetKeyTipData(AKeyTipsData);
    end;
    GenerateKeyTips(AItemKeyTipsData);
  finally
    AItemKeyTipsData.Free;
  end;
end;

procedure TdxRibbonQuickAccessBarControlAccessibilityHelper.InitializeItemKeyTipPosition(
  AItemLinkHelper: TdxBarItemLinkAccessibilityHelper; var AKeyTipInfo: TdxBarKeyTipInfo);
begin
  inherited;
  AKeyTipInfo.VertAlign := vaBottom;
end;

function TdxRibbonQuickAccessBarControlAccessibilityHelper.GetNextAccessibleObject(
  AItemLinkHelper: TdxBarItemLinkAccessibilityHelper;
  ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;

  function InternalGetRootObject: TdxBarAccessibilityHelper;
  begin
    if TdxRibbonQuickAccessBarControl(BarControl).IsPopup then
      Result := Self
    else
      Result := GetRootAccessibleObject.GetBarHelper;
  end;

var
  AObjects: TList;
begin
  AObjects := TList.Create;
  try
    GetChildrenForNavigation(AItemLinkHelper, InternalGetRootObject,
      AItemLinkHelper.GetScreenBounds(cxAccessibleObjectSelfID),
      ADirection, True, AObjects);
    Result := dxBar.GetNextAccessibleObject(AItemLinkHelper, AObjects, ADirection, True);
  finally
    AObjects.Free;
  end;
end;

function TdxRibbonQuickAccessBarControlAccessibilityHelper.GetParentForKeyTip: TdxBarAccessibilityHelper;
begin
  if BarControl.IsPopup then
    Result := BarControl.ParentBar.IAccessibilityHelper.GetBarHelper
  else
    Result := inherited GetParentForKeyTip;
end;

function TdxRibbonQuickAccessBarControlAccessibilityHelper.IsKeyTipContainer: Boolean;
begin
  Result := BarControl.IsPopup;
end;

procedure TdxRibbonQuickAccessBarControlAccessibilityHelper.KeyTipsEscapeHandler;
var
  AMarkAccessibleObject: IdxBarAccessibilityHelper;
  ASelectedControl: TdxBarItemControl;
begin
  if not BarControl.IsPopup then
  begin
    ASelectedControl := TdxRibbonQuickAccessBarControl(BarControl).SelectedControl;
    inherited KeyTipsEscapeHandler;
    BarNavigationController.ChangeSelectedObject(True, ASelectedControl.IAccessibilityHelper);
  end
  else
  begin
    BarNavigationController.SetKeyTipsShowingState(GetKeyTipContainerParent(Self), '');
    AMarkAccessibleObject := TdxRibbonQuickAccessBarControl(BarControl.ParentBar).MarkIAccessibilityHelper;
    TdxRibbonQuickAccessBarControl(BarControl.ParentBar).MarkState := msNone;
    if AMarkAccessibleObject.GetHelper.IsOwnerObjectLive then
      BarNavigationController.ChangeSelectedObject(True, AMarkAccessibleObject);
  end;
end;

function TdxRibbonQuickAccessBarControlAccessibilityHelper.GetBarControl: TdxRibbonQuickAccessBarControl;
begin
  Result := TdxRibbonQuickAccessBarControl(FOwnerObject);
end;

{ TdxRibbonQuickAccessBarControlMarkAccessibilityHelper }

// IdxBarAccessibilityHelper
function TdxRibbonQuickAccessBarControlMarkAccessibilityHelper.HandleNavigationKey(
  var AKey: Word): Boolean;
begin
  Result := inherited HandleNavigationKey(AKey);
  if (BarControl.MarkState = msPressed) and not BarControl.AllItemsVisible then
    SelectFirstSelectableAccessibleObject(
      BarDesignController.QuickControl.IAccessibilityHelper.GetBarHelper);
end;

procedure TdxRibbonQuickAccessBarControlMarkAccessibilityHelper.GetKeyTipInfo(out AKeyTipInfo: TdxBarKeyTipInfo);
begin
  inherited;
  AKeyTipInfo.BasePoint := cxRectCenter(GetScreenBounds(cxAccessibleObjectSelfID));
  AKeyTipInfo.HorzAlign := taCenter;
  AKeyTipInfo.VertAlign := vaBottom;
  AKeyTipInfo.Enabled := True;
end;

function TdxRibbonQuickAccessBarControlMarkAccessibilityHelper.GetKeyTip: string;
begin
  if BarControl.AllItemsVisible then
    Result := ''
  else
    Result := '00';
end;

procedure TdxRibbonQuickAccessBarControlMarkAccessibilityHelper.KeyTipHandler(Sender: TObject);
begin
  DropDown;
  BarNavigationController.SetKeyTipsShowingState(BarDesignController.QuickControl.IAccessibilityHelper, '');
end;

function TdxRibbonQuickAccessBarControlMarkAccessibilityHelper.GetBarControl: TdxRibbonQuickAccessBarControl;
begin
  Result := TdxRibbonQuickAccessBarControl(FOwnerObject);
end;

{ TdxRibbonGroupBarControlAccessibilityHelper }

procedure TdxRibbonGroupBarControlAccessibilityHelper.CloseUpHandler(AReason: TdxBarCloseUpReason);
begin
  if (AReason = bcrEscape) and BarNavigationController.NavigationMode then
    Select(False);
end;

// IdxBarAccessibilityHelper
function TdxRibbonGroupBarControlAccessibilityHelper.GetNextAccessibleObject(
  ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;
begin
  if BarControl.Collapsed then
    Result := GetNextAccessibleObject(nil, ADirection)
  else
    Result := inherited GetNextAccessibleObject(ADirection);
end;

function TdxRibbonGroupBarControlAccessibilityHelper.HandleNavigationKey(
  var AKey: Word): Boolean;
begin
  Result := inherited HandleNavigationKey(AKey);
  if Result then
    Exit;
  Result := BarControl.Collapsed and (AKey in [VK_RETURN, VK_SPACE]);
  if Result then
  begin
    ShowPopupBarControl;
    SelectFirstSelectableAccessibleObject(
      BarDesignController.QuickControl.IAccessibilityHelper.GetBarHelper);
  end;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.IsNavigationKey(AKey: Word): Boolean;
begin
  Result := inherited IsNavigationKey(AKey);
  if BarControl.Collapsed then
    Result := Result or (AKey in [VK_ESCAPE, VK_RETURN, VK_SPACE]);
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.Select(ASetFocus: Boolean);
begin
  if not BarControl.Collapsed then
    inherited Select(ASetFocus)
  else
  begin
    BarNavigationController.SelectedObject := Self;
    BarNavigationController.SelectedObjectParent := Parent;
    BarControl.Invalidate;

    TdxRibbonGroupsDockControl(BarControl.DockControl).MakeRectFullyVisible(BarControl.BoundsRect);
  end;
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.Unselect(
  ANextSelectedObject: IdxBarAccessibilityHelper);
begin
  if not BarControl.Collapsed then
    inherited Unselect(ANextSelectedObject)
  else
  begin
    BarNavigationController.SelectedObject := nil;
    BarNavigationController.SelectedObjectParent := nil;
    BarControl.Invalidate;
  end;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.GetSelectable: Boolean;
begin
  if BarControl.Collapsed then
    Result := Visible
  else
    Result := inherited GetSelectable;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.Expand: TCustomdxBarControlAccessibilityHelper;
begin
  if not IsCollapsed then
    raise EdxException.Create('');
  ShowPopupBarControl;
  Result := TCustomdxBarControlAccessibilityHelper(BarDesignController.QuickControl.IAccessibilityHelper.GetHelper);
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.GetCaptionButtonKeyTipPosition(
  ACaptionButton: TdxBarCaptionButton; out ABasePointY: Integer;
  out AVertAlign: TcxAlignmentVert);
begin
  ABasePointY := BarControl.ViewInfo.BottomKeyTipsBaseLinePosition;
  AVertAlign := vaBottom;
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.InitializeItemKeyTipPosition(
  AItemLinkHelper: TdxBarItemLinkAccessibilityHelper; var AKeyTipInfo: TdxBarKeyTipInfo);
var
  AOneRowHeightItemControl: Boolean;
  ARow: Integer;
  AItemControl: TdxBarItemControl;
begin
  AItemControl := AItemLinkHelper.ItemControl;
  AOneRowHeightItemControl := AItemControl.ViewInfo.ViewLevel <> ivlLargeIconWithText;

  if not AOneRowHeightItemControl then
    AKeyTipInfo.BasePoint.Y := BarControl.ViewInfo.RowKeyTipsBaseLinePositions[dxRibbonGroupRowCount - 1]
  else
  begin
    ARow := IdxBarItemControlViewInfo(AItemControl.ViewInfo).GetRow;
    if (IdxBarItemControlViewInfo(AItemControl.ViewInfo).GetColumnRowCount = 2) and (ARow = 1) then
      ARow := 2;
    if IdxBarItemControlViewInfo(AItemControl.ViewInfo).GetColumnRowCount = 1 then
      ARow := 1;
    AKeyTipInfo.BasePoint.Y := BarControl.ViewInfo.RowKeyTipsBaseLinePositions[ARow];
  end;
  AKeyTipInfo.VertAlign := vaCenter;

  if AOneRowHeightItemControl and
    (cpIcon in TdxBarItemControlAccess(AItemControl).FDrawParams.ViewStructure) then
  begin
    ProcessPaintMessages; // AItemControl.ViewInfo.ImageBounds are calculated on painting
    AKeyTipInfo.BasePoint.X := cxRectCenter(AItemControl.ViewInfo.ImageBounds).X;
    AKeyTipInfo.BasePoint.X := AItemControl.Parent.ClientToScreen(AKeyTipInfo.BasePoint).X;
    AKeyTipInfo.HorzAlign := taRightJustify;
  end
  else
  begin
    AKeyTipInfo.BasePoint.X := cxRectCenter(GetItemScreenBounds(AItemLinkHelper)).X;
    AKeyTipInfo.HorzAlign := taCenter;
  end;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.GetAssignedKeyTip: string;
begin
  Result := BarControl.Bar.KeyTip;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.GetDefaultKeyTip: string;

  function GetFirstChar(const AText: string): string;
  begin
    if Length(AText) > 0 then
      Result := AText[1]
    else
      Result := '';
  end;

begin
  Result := 'Z' + GetFirstChar(BarControl.Bar.Caption);
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.GetKeyTipInfo(out AKeyTipInfo: TdxBarKeyTipInfo);
var
  AKeyTipBasePoint: TPoint;
begin
  inherited;
  with GetScreenBounds(cxAccessibleObjectSelfID) do
    AKeyTipBasePoint.X := (Left + Right) div 2;
  AKeyTipBasePoint.Y := BarControl.ViewInfo.BottomKeyTipsBaseLinePosition;
  AKeyTipInfo.BasePoint := AKeyTipBasePoint;
  AKeyTipInfo.HorzAlign := taCenter;
  AKeyTipInfo.VertAlign := vaBottom;
  AKeyTipInfo.Enabled := True;
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.GetKeyTipData(AKeyTipsData: TList);

  procedure AddKeyTipsForItemControls;
  var
    AItemControl: TdxBarItemControl;
    I: Integer;
  begin
    for I := 0 to BarControl.ViewInfo.ItemControlCount - 1 do
    begin
      AItemControl := BarControl.ViewInfo.ItemControlViewInfos[I].Control;
      with TdxBarItemControlAccessibilityHelperAccess(AItemControl.IAccessibilityHelper.GetBarHelper) do
        if CanSelect then
          GetKeyTipData(AKeyTipsData);
    end;
  end;

  procedure AddKeyTipsForCaptionButtons;
  var
    ACaptionButton: TdxBarCaptionButton;
    I: Integer;
  begin
    for I := 0 to BarControl.Bar.CaptionButtons.Count - 1 do
    begin
      ACaptionButton := BarControl.Bar.CaptionButtons[I];
      TdxBarCaptionButtonAccessibilityHelperAccess(ACaptionButton.IAccessibilityHelper.GetHelper).GetKeyTipData(AKeyTipsData);
    end;
  end;

begin
  inherited GetKeyTipData(AKeyTipsData);
  AddKeyTipsForItemControls;
  AddKeyTipsForCaptionButtons;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.GetNextAccessibleObject(
  AItemLinkHelper: TdxBarItemLinkAccessibilityHelper;
  ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;

  function FindAmongItemControlsAndCollapsedBarControls(
    ASelectedObject: TdxBarAccessibilityHelper;
    const ASelectedObjectScreenBounds: TRect): IdxBarAccessibilityHelper;

    procedure GetBarControlChildren(ABarControl: TdxRibbonGroupBarControl;
      AObjects: TList);
    var
      AItemControl1: TdxBarItemControl;
      I: Integer;
    begin
      for I := 0 to ABarControl.ViewInfo.ItemControlCount - 1 do
      begin
        AItemControl1 := ABarControl.ViewInfo.ItemControlViewInfos[I].Control;
        GetChildrenForNavigation(ASelectedObject,
          AItemControl1.IAccessibilityHelper.GetBarHelper, ASelectedObjectScreenBounds,
          ADirection, False, AObjects);
      end;
    end;

  var
    ABarControl: TdxRibbonGroupBarControl;
    AObjects: TList;
    I: Integer;
  begin
    Result := nil;
    AObjects := TList.Create;
    try
      if BarControl.IsPopup then
        GetBarControlChildren(BarControl, AObjects)
      else
        for I := 0 to Parent.ChildCount - 1 do
        begin
          ABarControl := TdxRibbonGroupBarControlAccessibilityHelper(Parent.Childs[I]).BarControl;
          if ABarControl.Collapsed then
            GetChildrenForNavigation(ASelectedObject,
              ABarControl.IAccessibilityHelper.GetBarHelper, ASelectedObjectScreenBounds, ADirection, False, AObjects)
          else
            if not ((ADirection in [andUp, andDown]) and (ABarControl <> BarControl)) then
              GetBarControlChildren(ABarControl, AObjects);
        end;
      Result := dxBar.GetNextAccessibleObject(ASelectedObject, AObjects, ADirection, True);
    finally
      AObjects.Free;
    end;
  end;

var
  ACaptionButtonIndex: Integer;
  AObjects: TList;
  AScreenBounds: TRect;
  ASelectedObject: TdxBarAccessibilityHelper;
begin
  if AItemLinkHelper <> nil then
    ASelectedObject := AItemLinkHelper
  else
    ASelectedObject := Self;
  AScreenBounds := TdxBarAccessibilityHelperAccess(ASelectedObject).GetScreenBounds(cxAccessibleObjectSelfID);
  Result := FindAmongItemControlsAndCollapsedBarControls(ASelectedObject, AScreenBounds);
  if Result <> nil then
    Exit;
  case ADirection of
    andUp:
      if not (BarControl.IsPopup or TdxRibbonGroupBarControl(BarControl).Ribbon.IsPopupGroupsMode) then
        Result := TdxRibbonGroupBarControl(BarControl).Ribbon.ActiveTab.IAccessibilityHelper;
    andDown:
      begin
        ACaptionButtonIndex := -1;
        if not BarControl.Collapsed then
          ACaptionButtonIndex := BarControl.Bar.CaptionButtons.IAccessibilityHelper.GetHelper.GetNextSelectableChildIndex(-1, False);
        if ACaptionButtonIndex <> -1 then
          Result := BarControl.Bar.CaptionButtons[ACaptionButtonIndex].IAccessibilityHelper
        else
          if not (BarControl.IsPopup or TdxRibbonGroupBarControl(BarControl).Ribbon.IsPopupGroupsMode) and
            (BarControl.Ribbon.QATIAccessibilityHelper <> nil) then
          begin
            AObjects := TList.Create;
            try
              GetChildrenForNavigation(ASelectedObject,
                BarControl.Ribbon.QATIAccessibilityHelper.GetBarHelper,
                AScreenBounds, ADirection, False, AObjects);
              Result := dxBar.GetNextAccessibleObject(
                ASelectedObject, AObjects, ADirection, True);
            finally
              AObjects.Free;
            end;
          end;
      end;
  end;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.GetParentForKeyTip: TdxBarAccessibilityHelper;
begin
  if BarControl.IsPopup then
    Result := BarControl.ParentBar.IAccessibilityHelper.GetBarHelper
  else
    Result := inherited GetParentForKeyTip;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.IsCollapsed: Boolean;
begin
  Result := BarControl.Collapsed;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.IsKeyTipContainer: Boolean;
begin
  Result := BarControl.IsPopup;
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.KeyTipHandler(Sender: TObject);
begin
  ShowPopupBarControl;
  BarNavigationController.SetKeyTipsShowingState(
    BarDesignController.QuickControl.IAccessibilityHelper, '');
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.KeyTipsEscapeHandler;
var
  ASelectedItemControl: TdxBarItemControl;
begin
  if BarControl.IsPopup then
  begin
    if BarControl = BarDesignController.QuickControl then
    begin
      TdxRibbonGroupBarControlAccessibilityHelper(BarControl.ParentBar.IAccessibilityHelper.GetHelper).KeyTipsEscapeHandler;
      TCustomdxBarControlAccess(BarControl.ParentBar).MarkState := msNone;
    end
    else
    begin
      if not TCustomdxBarControlAccess(BarControl.ParentBar).IsPopup then
        TdxRibbonGroupBarControlAccessibilityHelper(BarControl.ParentBar.IAccessibilityHelper.GetHelper).KeyTipsEscapeHandler
      else
      begin
        ASelectedItemControl := TCustomdxBarControlAccess(BarControl.ParentBar).SelectedControl;
        BarControl.Hide;
        BarNavigationController.ChangeSelectedObject(True, ASelectedItemControl.IAccessibilityHelper);
        BarNavigationController.SetKeyTipsShowingState(ASelectedItemControl.Parent.IAccessibilityHelper, '');
      end;
    end;
  end
  else
    inherited KeyTipsEscapeHandler;
end;

function TdxRibbonGroupBarControlAccessibilityHelper.GetBarControl: TdxRibbonGroupBarControl;
begin
  Result := TdxRibbonGroupBarControl(FOwnerObject);
end;

procedure TdxRibbonGroupBarControlAccessibilityHelper.ShowPopupBarControl;
begin
  BarNavigationController.UnselectAssignedSelectedObject;
  BarControl.MarkState := msPressed;
end;

{ TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper }

function TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper.IsDropDownControl: Boolean;
begin
  Result := True;
end;

function TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper.ShowDropDownWindow: Boolean;
begin
  TdxRibbonQuickAccessGroupButtonControl(ItemControl).DropDown(True);
  Result := ItemControl.IsDroppedDown;
end;

{ TdxRibbonKeyTipWindow }

constructor TdxRibbonKeyTipWindow.Create(AColorScheme: TdxCustomRibbonSkin);
begin
  inherited Create(nil);
  FColorScheme := AColorScheme;
  Canvas.Font := Screen.HintFont;
  Canvas.Brush.Style := bsClear;
end;

procedure TdxRibbonKeyTipWindow.ShowKeyTip;
begin
  ParentWindow := Application.Handle;
  SetWindowRgn(Handle, CreateRoundRectRgn(0, 0, Width + 1, Height + 1, 2, 2), True);
  Invalidate;
end;

function TdxRibbonKeyTipWindow.CalcBoundsRect: TRect;
var
  ATempCanvas: TcxScreenCanvas;
begin
  Result := cxEmptyRect;
  ATempCanvas := TcxScreenCanvas.Create;
  try
    ATempCanvas.Font := Canvas.Font;
    cxDrawText(ATempCanvas.Handle, Caption, Result,
      DT_CALCRECT or DT_SINGLELINE or DT_LEFT or DT_NOPREFIX);
  finally
    ATempCanvas.Free;
  end;
  Inc(Result.Right, 6);
  Result.Right := Max(Result.Right, 16);
  Inc(Result.Bottom, 2);
end;

procedure TdxRibbonKeyTipWindow.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  with Params do
  begin
    Style := WS_POPUP;
    ExStyle := WS_EX_TOOLWINDOW or WS_EX_TOPMOST;
  end;
end;

procedure TdxRibbonKeyTipWindow.CreateWindowHandle(const Params: TCreateParams);
begin
  inherited;
  if not Enabled then
    cxSetLayeredWindowAttributes(Handle, 153);
end;

procedure TdxRibbonKeyTipWindow.Paint;
var
  R: TRect;
begin
  R := ClientRect;
  FColorScheme.DrawKeyTip(Canvas.Handle, R);
  Canvas.Font.Color := FColorScheme.GetPartColor(DXBAR_KEYTIP_TEXTCOLOR);
  cxDrawText(Canvas.Handle, Caption, R,
    DT_SINGLELINE or DT_CENTER or DT_NOPREFIX or DT_VCENTER);
end;

procedure TdxRibbonKeyTipWindow.UpdateBounds;
var
  R: TRect;
begin
  R := CalcBoundsRect;
  UpdateBoundsRect(R);
end;

procedure TdxRibbonKeyTipWindow.CMEnabledChanged(var Message: TMessage);
begin
  RecreateWnd;
end;

procedure TdxRibbonKeyTipWindow.CMTextChanged(var Message: TMessage);
begin
  inherited;
  UpdateBounds;
end;

procedure TdxRibbonKeyTipWindow.WMNCHitTest(var Message: TWMNCHitTest);
begin
  Message.Result := HTTRANSPARENT;
end;

{ TdxRibbonCustomKeyTipWindows }

constructor TdxRibbonCustomKeyTipWindows.Create(ARibbon: TdxCustomRibbon);
begin
  inherited Create;
  FRibbon := ARibbon;
  FWindowList := TcxObjectList.Create;
end;

destructor TdxRibbonCustomKeyTipWindows.Destroy;
begin
  FreeAndNil(FWindowList);
  inherited Destroy;
end;

// IdxBarKeyTipWindowsManager
procedure TdxRibbonCustomKeyTipWindows.Add(const ACaption: string;
  const ABasePoint: TPoint; AHorzAlign: TAlignment;
  AVertAlign: TcxAlignmentVert; AEnabled: Boolean; out AWindow: TObject);

  function GetWindowPosition(const AWindowSize: TSize; const ABasePoint: TPoint;
    AVertAlign: TcxAlignmentVert): TPoint;
  begin
    case AHorzAlign of
      taLeftJustify:
        Result.X := ABasePoint.X - AWindowSize.cx;
      taCenter:
        Result.X := ABasePoint.X - AWindowSize.cx div 2;
      taRightJustify:
        Result.X := ABasePoint.X;
    end;
    case AVertAlign of
      vaTop:
        Result.Y := ABasePoint.Y - AWindowSize.cy;
      vaCenter:
        Result.Y := ABasePoint.Y - AWindowSize.cy div 2;
      vaBottom:
        Result.Y := ABasePoint.Y;
    end;
  end;

var
  ATempWindow: TdxRibbonKeyTipWindow;
begin
  ATempWindow := TdxRibbonKeyTipWindow.Create(ColorScheme);
  ATempWindow.Caption := ACaption;
  ATempWindow.Enabled := AEnabled;
  with GetWindowPosition(cxSize(ATempWindow.Width, ATempWindow.Height),
    ABasePoint, AVertAlign) do
  begin
    ATempWindow.Left := X;
    ATempWindow.Top := Y;
  end;
  FWindowList.Add(ATempWindow);
  AWindow := ATempWindow;
end;

procedure TdxRibbonCustomKeyTipWindows.Delete(AWindow: TObject);
var
  AIndex: Integer;
begin
  AIndex := FWindowList.IndexOf(AWindow);
  TdxRibbonKeyTipWindow(FWindowList[AIndex]).Free;
  FWindowList.Delete(AIndex);
end;

procedure TdxRibbonCustomKeyTipWindows.Initialize;
begin
  // nothing to do
end;

procedure TdxRibbonCustomKeyTipWindows.Show;
var
  AWindow: TdxRibbonKeyTipWindow;
  I: Integer;
  WP: HDWP;
begin
  if Count > 0 then
  begin
    WP := BeginDeferWindowPos(Count);
    try
      for I := 0 to Count - 1 do
      begin
        AWindow := TdxRibbonKeyTipWindow(FWindowList[I]);
        DeferWindowPos(WP, AWindow.Handle, HWND_TOPMOST, AWindow.Left, AWindow.Top,
          AWindow.Width, AWindow.Height, SWP_NOACTIVATE or SWP_NOOWNERZORDER or SWP_NOZORDER);
        AWindow.ShowKeyTip;
      end;
    finally
      EndDeferWindowPos(WP);
    end;
  end;
end;

function TdxRibbonCustomKeyTipWindows.GetColorScheme: TdxCustomRibbonSkin;
begin
  Result := FRibbon.ColorScheme;
end;

function TdxRibbonCustomKeyTipWindows.GetCount: Integer;
begin
  Result := FWindowList.Count;
end;

{ TdxRibbonKeyTipWindows }

procedure TdxRibbonKeyTipWindows.Initialize;
var
  AHelper: IdxRibbonFormControllerHelper;
begin
  if Supports(FRibbon.RibbonForm, IdxRibbonFormControllerHelper, AHelper) then
    AHelper.DoBeforeShowKeyTips;
end;

{ TdxRibbonScrollBar }

function TdxRibbonScrollBar.GetHelperClass: TcxScrollBarHelperClass;
begin
  Result := TdxRibbonScrollBarHelper;
end;

function TdxRibbonScrollBar.GetRibbon: TdxCustomRibbon;
begin
  if Parent is TdxCustomRibbon then
    Result := TdxCustomRibbon(Parent)
  else
    Result := nil;
end;

{ TdxRibbonScrollBarHelper }

function TdxRibbonScrollBarHelper.GetPainterClass: TcxScrollBarPainterClass;
begin
  Result := TdxRibbonScrollBarPainter;
end;

{ TdxRibbonScrollBarPainter }

procedure TdxRibbonScrollBarPainter.DoDrawScrollBarPart(
  ACanvas: TcxCanvas; const R: TRect; APart: TcxScrollBarPart; AState: TcxButtonState);
const
  StateMap: array[TcxButtonState] of Integer = (
    DXBAR_NORMAL, DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED, DXBAR_DISABLED
  );
  PartMap: array[TScrollBarKind, TcxScrollBarPart] of Integer = (
    (0, DXBAR_SCROLLBARHORZ_LINEUP, DXBAR_SCROLLBARHORZ_LINEDOWN, DXBAR_SCROLLBARHORZ_THUMBNAIL,
      DXBAR_SCROLLBARHORZ_PAGEUP, DXBAR_SCROLLBARHORZ_PAGEDOWN),
    (0, DXBAR_SCROLLBARVERT_LINEUP, DXBAR_SCROLLBARVERT_LINEDOWN, DXBAR_SCROLLBARVERT_THUMBNAIL,
      DXBAR_SCROLLBARVERT_PAGEUP, DXBAR_SCROLLBARVERT_PAGEDOWN)
  );
begin
  if Skin <> nil then
    Skin.DrawBackground(ACanvas.Handle, R, PartMap[ScrollBar.Kind, APart], StateMap[AState])
  else
    inherited DoDrawScrollBarPart(ACanvas, R, APart, AState);
end;

procedure TdxRibbonScrollBarPainter.DrawScrollBarBackground(ACanvas: TcxCanvas; const R: TRect);
const
  PartMap: array[TScrollBarKind] of Integer = (DXBAR_SCROLLBARHORZ_BACKGROUND, DXBAR_SCROLLBARVERT_BACKGROUND);
begin
  if Skin <> nil then
    Skin.DrawBackground(ACanvas.Handle, R, PartMap[ScrollBar.Kind])
  else
    inherited DrawScrollBarBackground(ACanvas, R);
end;

function TdxRibbonScrollBarPainter.GetScrollBar: TdxRibbonScrollBar;
begin
  Result := TdxRibbonScrollBarHelper(inherited ScrollBar).Owner.GetControl as TdxRibbonScrollBar;
end;

function TdxRibbonScrollBarPainter.GetSkin: IdxSkin;
begin
  Supports(ScrollBar.Ribbon, IdxSkin, Result);
end;

{ TdxRibbonSizeGrip }

procedure TdxRibbonSizeGrip.Draw(ACanvas: TCanvas);
var
  ASkin: IdxSkin;
begin
  if Supports(Ribbon, IdxSkin, ASkin) then
    ASkin.DrawBackground(ACanvas.Handle, ClientRect, DXBAR_SCROLLBOX_SIZEGRIPAREA)
  else
    inherited Draw(ACanvas);
end;

function TdxRibbonSizeGrip.GetRibbon: TdxCustomRibbon;
begin
  if Parent is TdxCustomRibbon then
    Result := TdxCustomRibbon(Parent)
  else
    Result := nil;
end;

initialization
  FRibbonList := TList.Create;
  RegisterClasses([TdxRibbonTab]);
  dxBarRegisterItem(TdxRibbonQuickAccessPopupSubItem, TdxRibbonQuickAccessPopupSubItemControl, False);
  dxBarRegisterItem(TdxRibbonQuickAccessPopupSubItemButton, TdxRibbonQuickAccessPopupSubItemButtonControl, False);
  dxBarRegisterItem(TdxRibbonQuickAccessGroupButton, TdxRibbonQuickAccessGroupButtonControl, False);
  BarDesignController.RegisterBarControlDesignHelper(TdxRibbonGroupBarControl, TdxRibbonGroupBarControlDesignHelper);
  BarDesignController.RegisterBarControlDesignHelper(TdxRibbonQuickAccessBarControl, TdxRibbonQuickAccessBarControlDesignHelper);

  dxBarGetRootAccessibleObject := GetRootRibbonAccessibilityHelper;

finalization
  dxBarGetRootAccessibleObject := nil;
  BarDesignController.UnregisterBarControlDesignHelper(TdxRibbonQuickAccessBarControl, TdxRibbonQuickAccessBarControlDesignHelper);
  BarDesignController.UnregisterBarControlDesignHelper(TdxRibbonGroupBarControl, TdxRibbonGroupBarControlDesignHelper);
  dxBarUnregisterItem(TdxRibbonQuickAccessGroupButton);
  dxBarUnregisterItem(TdxRibbonQuickAccessPopupSubItemButton);
  dxBarUnregisterItem(TdxRibbonQuickAccessPopupSubItem);

  dxReleaseHook(dxRibbonMouseHook);
  FreeAndNil(FRibbonList);

end.
