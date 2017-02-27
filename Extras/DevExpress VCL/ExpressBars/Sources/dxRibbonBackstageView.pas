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

unit dxRibbonBackstageView;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Types, Windows, Classes, SysUtils, Messages, Controls, Graphics, Math, Forms, ImgList,
  cxGraphics, cxGeometry, cxControls, cxClasses, dxBar, dxRibbon, dxRibbonSkins,
  dxCore, dxCoreClasses, dxMessages, dxBarStrs, StdCtrls,
  cxAccessibility, dxBarAccessibility,
  dxAnimation, dxRibbonFormCaptionHelper, cxLookAndFeelPainters, cxScrollBar;

const
  dxRibbonBackstageViewMinMenuWidth: Integer = 132;
  dxRibbonBackstageViewMinOwnerHeight: Integer = 400;
  dxRibbonBackstageViewMinOwnerWidth: Integer = 500;

  dxRibbonBackstageViewMenuScrollAnimationTime: Integer = 500;

type
  TdxRibbonBackstageViewMenuBarButton = class;
  TdxRibbonBackstageViewMenuBarControl = class;
  TdxRibbonBackstageViewMenuButton = class;
  TdxRibbonBackstageViewMenuButtons = class;
  TdxRibbonBackstageViewMenuDockControl = class;
  TdxRibbonBackstageViewMenuViewInfo = class;
  TdxRibbonBackstageViewPainter = class;
  TdxRibbonBackstageViewTabSheet = class;
  TdxRibbonBackstageViewTabSheetButtonList = class;
  TdxRibbonCustomBackstageView = class;

  TdxRibbonBackstageViewChange = (rbvcStruct, rbvcItemsData, rbvcTabsData);
  TdxRibbonBackstageViewChanges = set of TdxRibbonBackstageViewChange;
  TdxRibbonBackstageViewMenuButtonPosition = (mbpBeforeTabs, mbpAfterTabs);

  { IdxRibbonBackstageViewSelectableItem }

  IdxRibbonBackstageViewSelectableItem = interface
  ['{D5E058AB-1C90-4D21-BE0A-EB48530EF53B}']
    procedure SelectionChanged;
  end;

  { IdxRibbonBackstageViewKeyTipPositionInfo }

  IdxRibbonBackstageViewKeyTipPositionInfo = interface
  ['{7947E0B2-BBED-4AE0-9C34-5B578B412780}']
    function GetKeyTipBasePoint: TPoint;
  end;

  { TdxRibbonBackstageViewCustomObject }

  TdxRibbonBackstageViewCustomObject = class(TcxIUnknownObject)
  private
    FBackstageView: TdxRibbonCustomBackstageView;
    function GetBarManager: TdxBarManager;
    function GetIsBarManagerValid: Boolean;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView); virtual;
    //
    property BackstageView: TdxRibbonCustomBackstageView read FBackstageView;
    property BarManager: TdxBarManager read GetBarManager;
    property IsBarManagerValid: Boolean read GetIsBarManagerValid;
  end;

  { TdxRibbonBackstageViewCustomViewInfo }

  TdxRibbonBackstageViewCustomViewInfo = class(TdxRibbonBackstageViewCustomObject)
  private
    FBounds: TRect;
  public
    procedure Calculate(const ABounds: TRect); virtual;
    //
    property Bounds: TRect read FBounds;
  end;

  { TdxRibbonBackstageViewMenuBarAccessibilityHelper }

  TdxRibbonBackstageViewMenuBarAccessibilityHelper = class(TdxRibbonBarControlAccessibilityHelper)
  private
    FKeyTipWindowsManager: IdxBarKeyTipWindowsManager;
    function GetActiveTab: TdxRibbonBackstageViewTabSheet;
    function GetBackstageView: TdxRibbonCustomBackstageView;
    function GetMenuBarControl: TdxRibbonBackstageViewMenuBarControl;
  protected
    function AreKeyTipsSupported(out AKeyTipWindowsManager: IdxBarKeyTipWindowsManager): Boolean; override;
    function HandleNavigationKey(var AKey: Word): Boolean; override;
    procedure InitializeItemKeyTipPosition(AItemLinkHelper: TdxBarItemLinkAccessibilityHelper; var AKeyTipInfo: TdxBarKeyTipInfo); override;
    procedure KeyTipsEscapeHandler; override;
  public
    function GetDefaultSelectableObject(
      ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper; override;
    //
    property ActiveTab: TdxRibbonBackstageViewTabSheet read GetActiveTab;
    property BackstageView: TdxRibbonCustomBackstageView read GetBackstageView;
    property MenuBarControl: TdxRibbonBackstageViewMenuBarControl read GetMenuBarControl;
  end;

  { TdxRibbonBackstageViewMenuBarControl }

  TdxRibbonBackstageViewMenuBarControl = class(TdxRibbonCustomBarControl)
  private
    function GetBackstageView: TdxRibbonCustomBackstageView;
    function GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
    procedure CMDesignHitTest(var Message: TCMDesignHitTest); message CM_DESIGNHITTEST;
    procedure WMMouseWheel(var Message: TWMMouseWheel); message WM_MOUSEWHEEL;
  protected
    procedure DoBarMouseDown(Button: TMouseButton; Shift: TShiftState;
      const APoint: TPoint; AItemControl: TdxBarItemControl; APointInClientRect: Boolean); override;
    function CalcColumnItemRect(AItemLink: TdxBarItemLink; const AItemsRect: TRect): TRect; override;
    function CanCustomizing: Boolean; override;
    function CanDrawClippedItem(AItemRect: TRect): Boolean; override;
    procedure CalcControlsPositions; override;
    procedure DoKeyDown(var Message: TWMKey); override;
    function GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass; override;
    function GetCaption: TCaption; override;
    function GetItemControlOffset(AItemLink: TdxBarItemLink): Integer; override;
    function GetItemsRectOffset: TRect; override;
    function GetMaxWidth(AStyle: TdxBarDockingStyle): Integer; override;
    function GetMinWidth(AStyle: TdxBarDockingStyle): Integer; override;
    function GetNextBarControl(AForward: Boolean): TdxBarControl; override;
    function GetRibbon: TdxCustomRibbon; override;
    function GetViewInfoClass: TCustomdxBarControlViewInfoClass; override;
    function HasCaptionButtons: Boolean; override;
    function IsInternal: Boolean; override;
    function NeedsMouseWheel: Boolean; override;
    procedure MakeItemControlFullyVisible(AItemControl: TdxBarItemControl); override;
    procedure SetLayeredAttributes; override;
    procedure ShowPopup(AItem: TdxBarItemControl); override;
    procedure WndProc(var Message: TMessage); override;
    //
    property BackstageView: TdxRibbonCustomBackstageView read GetBackstageView;
    property MenuViewInfo: TdxRibbonBackstageViewMenuViewInfo read GetMenuViewInfo;
  public
    function IsVertical: Boolean; override;
  end;

  { TdxRibbonBackstageViewMenuBarControlViewInfo }

  TdxRibbonBackstageViewMenuBarControlViewInfo = class(TdxBarControlViewInfo)
  protected
    procedure DoCalcSeparatorInfo(AItemLink: TdxBarItemLink; const AItemRect: TRect); override;
  end;

  { TdxRibbonBackstageViewKeyTipWindows }

  TdxRibbonBackstageViewKeyTipWindows = class(TdxRibbonCustomKeyTipWindows);

  { TdxRibbonBackstageViewPainter }

  TdxRibbonBackstageViewPainter = class(TObject)
  private
    FBackstageView: TdxRibbonCustomBackstageView;
  protected
    function GetBackButtonSize: TSize; virtual;
    function GetContentOffsets: TRect; virtual;
    function GetSkin: IdxSkin; virtual;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView);
    procedure DrawBackButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); virtual;
    procedure DrawBackground(ACanvas: TcxCanvas; const R: TRect); virtual;
    procedure DrawMenuBarHeader(ACanvas: TcxCanvas; const R: TRect); virtual;
    //
    property BackButtonSize: TSize read GetBackButtonSize;
    property BackstageView: TdxRibbonCustomBackstageView read FBackstageView;
    property ContentOffsets: TRect read GetContentOffsets;
    property Skin: IdxSkin read GetSkin;
  end;

  { TdxRibbonBackstageViewMenuPainter }

  TdxRibbonBackstageViewMenuPainter = class(TdxBarSkinnedPainter)
  protected
    procedure DrawToolbarContentPart(ABarControl: TdxBarControl; ACanvas: TcxCanvas); override;
    procedure DrawToolbarNonContentPart(ABarControl: TdxBarControl; DC: HDC); override;
    procedure GetDisabledTextColors(ABarItemControl: TdxBarItemControl;
      ASelected: Boolean; AFlat: Boolean; var AColor1, AColor2: TColor); override;
    function GetEnabledTextColor(ABarItemControl: TdxBarItemControl;
      ASelected: Boolean; AFlat: Boolean): TColor; override;
  public
    function BarBeginGroupSize: Integer; override;
    procedure BarDrawBeginGroup(ABarControl: TCustomdxBarControl; DC: HDC;
      ABeginGroupRect: TRect; AToolbarBrush: HBRUSH; AHorz: Boolean); override;
    function GetToolbarContentOffsets(ABar: TdxBar;
      ADockingStyle: TdxBarDockingStyle; AHasSizeGrip: Boolean): TRect; override;
    procedure DrawButtonBackground(const ADrawParams: TdxBarButtonLikeControlDrawParams); override;
    procedure DockControlFillBackground(ADockControl: TdxDockControl; DC: HDC;
      ADestR: TRect; ASourceR: TRect; AWholeR: TRect; ABrush: HBRUSH; AColor: TColor); override;
    procedure DrawTabButton(const ADrawParams: TdxBarButtonLikeControlDrawParams; R: TRect); virtual;
    procedure DrawTabButtonBackground(DC: HDC; R: TRect; AState: Integer); virtual;
    function MenuBarButtonContentOffset: TRect; virtual;
    function MenuBarDefaultItemHeight: Integer; virtual;
    function MenuBarIndentBetweenItems: Integer; virtual;
    function MenuBarItemsRectOffset: TRect; virtual;
    function TabButtonContentOffset: TRect; virtual;
    function TabButtonDefaultHeight: Integer; virtual;
    function TabButtonTextColor(AState: Integer): TColor; virtual;
  end;

  { TdxRibbonBackstageViewMenuDockControl }

  TdxRibbonBackstageViewMenuDockControl = class(TdxBarDockControl)
  private
    FMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
    function GetBackstageView: TdxRibbonCustomBackstageView;
    function GetRibbon: TdxCustomRibbon;
  protected
    procedure CalcLayout; override;
    function CanCustomize: Boolean; override;
    function GetClientSize: Integer; override;
    function GetDockedBarControlClass: TdxBarControlClass; override;
    function GetDockingStyle: TdxBarDockingStyle; override;
    function GetMinSize: Integer; override;
    function GetPainter: TdxBarPainter; override;
    function GetSunkenBorder: Boolean; override;
    function IsDrawDesignBorder: Boolean; override;
    procedure ShowCustomizePopup; override;

    // IdxRibbonToolBarContainer
    function GetContainer: TObject;
    //
    procedure CMDesignHitTest(var Message: TCMDesignHitTest); message CM_DESIGNHITTEST;
  public
    constructor Create(AMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo); reintroduce;
    //
    property BackstageView: TdxRibbonCustomBackstageView read GetBackstageView;
    property MenuViewInfo: TdxRibbonBackstageViewMenuViewInfo read FMenuViewInfo;
    property Ribbon: TdxCustomRibbon read GetRibbon;
  end;

  { TdxRibbonBackstageViewTabSheetViewInfo }

  TdxRibbonBackstageViewTabSheetViewInfo = class(TObject)
  private
    FBounds: TRect;
    FTab: TdxRibbonBackstageViewTabSheet;
    function GetFrameAreaVisibleBounds: TRect;
  protected
    function GetMinHeight: Integer; virtual;
    function GetMinWidth: Integer; virtual;
  public
    constructor Create(ATab: TdxRibbonBackstageViewTabSheet); virtual;
    procedure Calculate(const R: TRect); virtual;
    procedure ValidateWindowPos(var APos: TWindowPos);
    //
    property Bounds: TRect read FBounds;
    property FrameAreaVisibleBounds: TRect read GetFrameAreaVisibleBounds;
    property MinHeight: Integer read GetMinHeight;
    property MinWidth: Integer read GetMinWidth;
    property Tab: TdxRibbonBackstageViewTabSheet read FTab;
  end;

  { TdxRibbonBackstageViewTabSheetSizeOptions }

  TdxRibbonBackstageViewTabSheetSizeOptions = class(TPersistent)
  private
    FHasChanges: Boolean;
    FMinHeight: Integer;
    FMinWidth: Integer;
    FTab: TdxRibbonBackstageViewTabSheet;
    FUpdateCount: Integer;
    function GetAutoSize: Boolean;
    procedure SetAutoSize(AValue: Boolean);
    procedure SetMinHeight(AValue: Integer);
    procedure SetMinWidth(AValue: Integer);
  protected
    procedure Changed;
  public
    constructor Create(ATab: TdxRibbonBackstageViewTabSheet); virtual;
    procedure Assign(Source: TPersistent); override;
    procedure BeginUpdate;
    procedure EndUpdate;
  published
    property AutoSize: Boolean read GetAutoSize write SetAutoSize default False;
    property MinHeight: Integer read FMinHeight write SetMinHeight default 0;
    property MinWidth: Integer read FMinWidth write SetMinWidth default 0;
  end;

  { TdxRibbonBackstageViewTabSheet }

  TdxRibbonBackstageViewTabSheet = class(TcxControl)
  private
    FBackstageView: TdxRibbonCustomBackstageView;
    FKeyTip: string;
    FSizeOptions: TdxRibbonBackstageViewTabSheetSizeOptions;
    FTabVisible: Boolean;
    FViewInfo: TdxRibbonBackstageViewTabSheetViewInfo;
    function GetActive: Boolean;
    function GetCanBeActive: Boolean;
    function GetPageIndex: Integer;
    function GetPainter: TdxRibbonBackstageViewPainter;
    procedure SetActive(AValue: Boolean);
    procedure SetBackstageView(AValue: TdxRibbonCustomBackstageView);
    procedure SetKeyTip(const AValue: string);
    procedure SetPageIndex(AValue: Integer);
    procedure SetSizeOptions(AValue: TdxRibbonBackstageViewTabSheetSizeOptions);
    procedure SetTabVisible(AValue: Boolean);
  protected
    function CanResize(var NewWidth, NewHeight: Integer): Boolean; override;
    function CreateViewInfo: TdxRibbonBackstageViewTabSheetViewInfo; virtual;
    procedure Activate; virtual;
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    procedure Calculate(const R: TRect); virtual;
    procedure Changed; virtual;
    procedure Deactivate; virtual;
    procedure DrawBackground(ACanvas: TcxCanvas);
    procedure NCPaint(DC: HDC); virtual;
    procedure Paint; override;
    procedure RefreshNonClientArea;
    procedure SetParent(AParent: TWinControl); override;
    //
    procedure CMEnabledChanged(var Message: TMessage); message CM_ENABLEDCHANGED;
    procedure CMTextChanged(var Message: TMessage); message CM_TEXTCHANGED;
    procedure WMNCPaint(var Message: TWMNCPaint); message WM_NCPAINT;
    procedure WMPrint(var Message: TWMPrint); message WM_PRINT;
    //
    property CanBeActive: Boolean read GetCanBeActive;
    property Painter: TdxRibbonBackstageViewPainter read GetPainter;
    property ViewInfo: TdxRibbonBackstageViewTabSheetViewInfo read FViewInfo;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure SetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    //
    property BackstageView: TdxRibbonCustomBackstageView read FBackstageView write SetBackstageView;
  published
    property Active: Boolean read GetActive write SetActive default False;
    property BorderWidth;
    property Caption;
    property Enabled;
    property Height stored False;
    property KeyTip: string read FKeyTip write SetKeyTip;
    property PageIndex: Integer read GetPageIndex write SetPageIndex stored False;
    property SizeOptions: TdxRibbonBackstageViewTabSheetSizeOptions read FSizeOptions write SetSizeOptions;
    property TabVisible: Boolean read FTabVisible write SetTabVisible default True;
    property Width stored False;
    //
    property OnResize;
  end;

  { TdxRibbonBackstageViewTabSheets }

  TdxRibbonBackstageViewTabSheets = class(TcxObjectList)
  private
    function GetItem(Index: Integer): TdxRibbonBackstageViewTabSheet;
  public
    property Items[Index: Integer]: TdxRibbonBackstageViewTabSheet read GetItem; default;
  end;

  { TdxRibbonBackstageViewTabSheetButton }

  TdxRibbonBackstageViewTabSheetButton = class(TdxBarButton)
  private
    FTab: TdxRibbonBackstageViewTabSheet;
    procedure SetTab(AValue: TdxRibbonBackstageViewTabSheet);
  protected
    function GetControlClass(AIsVertical: Boolean): TdxBarItemControlClass; override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure RefreshInfo;
    //
    property Tab: TdxRibbonBackstageViewTabSheet read FTab write SetTab;
  end;

  { TdxRibbonBackstageViewTabSheetButtonControl }

  TdxRibbonBackstageViewTabSheetButtonControl = class(TdxBarButtonControl,
    IdxRibbonBackstageViewKeyTipPositionInfo)
  private
    function GetItem: TdxRibbonBackstageViewTabSheetButton;
    function GetMenuPainter: TdxRibbonBackstageViewMenuPainter;
    function GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
  protected
    function CanCustomize: Boolean; override;
    procedure ActivateTab;
    procedure ControlActivate(AImmediately: Boolean; AByMouse: Boolean); override;
    procedure ControlClick(AByMouse: Boolean; AKey: Char = #0); override;
    procedure ControlUnclick(AByMouse: Boolean); override;
    procedure DoPaint(ARect: TRect; PaintType: TdxBarPaintType); override;
    function GetDefaultHeight: Integer; override;
    procedure GetFadingImages(out AFadeOutImage, AFadeInImage: TcxBitmap); override;
    function CanDestroyOnClick: Boolean; override;
    // IdxRibbonBackstageViewKeyTipPositionInfo
    function GetKeyTipBasePoint: TPoint;
    //
    property Item: TdxRibbonBackstageViewTabSheetButton read GetItem;
    property MenuPainter: TdxRibbonBackstageViewMenuPainter read GetMenuPainter;
    property MenuViewInfo: TdxRibbonBackstageViewMenuViewInfo read GetMenuViewInfo;
  end;

  { TdxRibbonBackstageViewTabSheetButtonList }
                           
  TdxRibbonBackstageViewTabSheetButtonList = class(TcxObjectList)
  private
    function GetItem(Index: Integer): TdxRibbonBackstageViewTabSheetButton;
  public
    function GetItemByTab(ATab: TdxRibbonBackstageViewTabSheet): TdxRibbonBackstageViewTabSheetButton;
    procedure RefreshInfo;
    procedure RemoveTab(ATab: TdxRibbonBackstageViewTabSheet);
    //
    property Items[Index: Integer]: TdxRibbonBackstageViewTabSheetButton read GetItem; default;
  end;

  { TdxRibbonBackstageViewMenuButtonList }

  TdxRibbonBackstageViewMenuButtonList = class(TcxObjectList)
  private
    function GetItem(Index: Integer): TdxRibbonBackstageViewMenuBarButton;
  public
    procedure RefreshInfo;
    //
    property Items[Index: Integer]: TdxRibbonBackstageViewMenuBarButton read GetItem; default;
  end;

  { TdxRibbonBackstageViewMenuViewInfo }

  TdxRibbonBackstageViewMenuViewInfo = class(TdxRibbonBackstageViewCustomViewInfo, IdxBarLinksOwner)
  private
    FDockControl: TdxRibbonBackstageViewMenuDockControl;
    FItemLinks: TdxBarItemLinks;
    FMenuButtonList: TdxRibbonBackstageViewMenuButtonList;
    FMinHeight: Integer;
    FMinWidth: Integer;
    FPainter: TdxRibbonBackstageViewMenuPainter;
    FTabButtonList: TdxRibbonBackstageViewTabSheetButtonList;
    function GetAccessibilityHelper: IdxBarAccessibilityHelper;
    function GetBarControl: TdxRibbonBackstageViewMenuBarControl;
    function GetIsDesigning: Boolean;
    function GetRibbon: TdxCustomRibbon;
    procedure AddButton(AButton: TdxRibbonBackstageViewMenuButton);
    procedure AddTabButton(ATab: TdxRibbonBackstageViewTabSheet);
  protected
    function CreatePainter(AData: TdxNativeUInt): TdxRibbonBackstageViewMenuPainter; virtual;
    procedure CreateBarControl;
    procedure CreateViewInfoItems;
    procedure DestroyViewInfoItems;
    // IdxBarLinksOwner
    function CanContainItem(AItem: TdxBarItem; out AErrorText: string): Boolean;
    function CreateItemLinksBarControl: TCustomdxBarControl;
    function GetImages: TCustomImageList;
    function GetInstance: TComponent;
    function GetItemLinks: TdxBarItemLinks;
    function IdxBarLinksOwner.CreateBarControl = CreateItemLinksBarControl;
    //
    property IsDesigning: Boolean read GetIsDesigning;
    property MenuButtonList: TdxRibbonBackstageViewMenuButtonList read FMenuButtonList;
    property Painter: TdxRibbonBackstageViewMenuPainter read FPainter;
    property TabButtonList: TdxRibbonBackstageViewTabSheetButtonList read FTabButtonList;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView); override;
    destructor Destroy; override;
    procedure Calculate(const ABounds: TRect); override;
    procedure CalculateSizes;
    procedure ClearInternalLists;
    procedure InitiateActions;
    procedure RecreateItemLinks;
    procedure RefreshMenuButtonsInfo;
    procedure RefreshTabsInfo;
    procedure UpdateFont;
    //
    property AccessibilityHelper: IdxBarAccessibilityHelper read GetAccessibilityHelper;
    property BarControl: TdxRibbonBackstageViewMenuBarControl read GetBarControl;
    property DockControl: TdxRibbonBackstageViewMenuDockControl read FDockControl;
    property ItemLinks: TdxBarItemLinks read FItemLinks;
    property MinHeight: Integer read FMinHeight;
    property MinWidth: Integer read FMinWidth;
    property Ribbon: TdxCustomRibbon read GetRibbon;
  end;

  { TdxRibbonBackstageViewDesignSelector }

  TdxRibbonBackstageViewDesignSelector = class(TcxDesignSelector)
  protected
    function GetSelected: Boolean; override;
  end;

  { TdxRibbonBackstageViewViewInfo }

  TdxRibbonBackstageViewViewInfo = class(TdxRibbonBackstageViewCustomViewInfo)
  private
    FContentHeight: Integer;
    FContentWidth: Integer;
    FFrameAreaBounds: TRect;
    FMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
    FScrollPositionX: Integer;
    FScrollPositionY: Integer;
    function GetActiveTab: TdxRibbonBackstageViewTabSheet;
    function GetActiveTabItemControl: TdxBarItemControl;
    function GetContentBounds: TRect;
    function GetDesignSelectorRect: TRect;
    function GetFrameAreaVisibleBounds: TRect;
    function GetMenuBarControl: TdxBarControl;
    procedure CheckScrollPosition(var AValue: Integer; AContentSize, ADisplaySize: Integer);
    procedure SetScrollPositionX(AValue: Integer);
    procedure SetScrollPositionY(AValue: Integer);
  protected
    function CalculateFrameBounds: TRect; virtual;
    function CalculateMenuBounds: TRect; virtual;
    function CalculateMinHeight: Integer; virtual;
    function CalculateMinWidth: Integer; virtual;
    function CreateMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo; virtual;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView); override;
    destructor Destroy; override;
    procedure Calculate(const ABounds: TRect); override;
    procedure DeactivateControls; virtual;
    function ProcessMouseWheel(ALineDown: Boolean): Boolean;
    //
    property ActiveTab: TdxRibbonBackstageViewTabSheet read GetActiveTab;
    property ActiveTabItemControl: TdxBarItemControl read GetActiveTabItemControl;
    property ContentBounds: TRect read GetContentBounds;
    property ContentHeight: Integer read FContentHeight;
    property ContentWidth: Integer read FContentWidth;
    property DesignSelectorRect: TRect read GetDesignSelectorRect;
    property FrameAreaBounds: TRect read FFrameAreaBounds;
    property FrameAreaVisibleBounds: TRect read GetFrameAreaVisibleBounds;
    property MenuBarControl: TdxBarControl read GetMenuBarControl;
    property MenuViewInfo: TdxRibbonBackstageViewMenuViewInfo read FMenuViewInfo;
    property ScrollPositionX: Integer read FScrollPositionX write SetScrollPositionX;
    property ScrollPositionY: Integer read FScrollPositionY write SetScrollPositionY;
  end;

  { TdxRibbonBackstageViewMenuBarButton }

  TdxRibbonBackstageViewMenuBarButton = class(TdxBarButton)
  private
    FMenuButton: TdxRibbonBackstageViewMenuButton;
    procedure SetMenuButton(AValue: TdxRibbonBackstageViewMenuButton);
  protected
    function GetControlClass(AIsVertical: Boolean): TdxBarItemControlClass; override;
  public
    procedure DirectClick; override;
    procedure RefreshInfo;
    //
    property MenuButton: TdxRibbonBackstageViewMenuButton read FMenuButton write SetMenuButton;
  end;

  { TdxRibbonBackstageViewMenuBarButtonControl }

  TdxRibbonBackstageViewMenuBarButtonControl = class(TdxBarButtonControl,
    IdxRibbonBackstageViewKeyTipPositionInfo)
  private
    function GetBackstageView: TdxRibbonCustomBackstageView;
    function GetItem: TdxRibbonBackstageViewMenuBarButton;
    function GetMenuPainter: TdxRibbonBackstageViewMenuPainter;
  protected
    function CanCustomize: Boolean; override;
    function GetDefaultHeight: Integer; override;
    function GetViewStructure: TdxBarItemControlViewStructure; override;
    function HasImage: Boolean;
    function IsTabButtonStyle: Boolean;
    procedure CalcDrawParams(AFull: Boolean = True); override;
    procedure DoPaint(ARect: TRect; PaintType: TdxBarPaintType); override;
    // IdxRibbonBackstageViewKeyTipPositionInfo
    function GetKeyTipBasePoint: TPoint;
  public
    property BackstageView: TdxRibbonCustomBackstageView read GetBackstageView;
    property Item: TdxRibbonBackstageViewMenuBarButton read GetItem;
    property MenuPainter: TdxRibbonBackstageViewMenuPainter read GetMenuPainter;
  end;

  { TdxRibbonBackstageViewMenuButton }

  TdxRibbonBackstageViewMenuButton = class(TcxInterfacedCollectionItem,
    IdxRibbonBackstageViewSelectableItem, IdxBarComponentListener)
  private
    FBeginGroup: Boolean;
    FItem: TdxBarButton;
    FPosition: TdxRibbonBackstageViewMenuButtonPosition;
    function GetCollection: TdxRibbonBackstageViewMenuButtons;
    procedure SetItem(AValue: TdxBarButton);
    procedure SetPosition(AValue: TdxRibbonBackstageViewMenuButtonPosition);
    procedure SetBeginGroup(AValue: Boolean);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation);
    // IdxRibbonBackstageViewSelectableItem
    procedure SelectionChanged;
    // IdxBarComponentListener
    procedure IdxBarComponentListener.EnabledChanged = BarComponentChanged;
    procedure IdxBarComponentListener.Changed = BarComponentChanged;
    procedure BarComponentChanged(AComponent: TdxBarComponent);
  public
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    //
    property Collection: TdxRibbonBackstageViewMenuButtons read GetCollection;
  published
    property BeginGroup: Boolean read FBeginGroup write SetBeginGroup default False;
    property Item: TdxBarButton read FItem write SetItem;
    property Position: TdxRibbonBackstageViewMenuButtonPosition read FPosition write SetPosition default mbpBeforeTabs;
  end;

  { TdxRibbonBackstageViewMenuButtons }

  TdxRibbonBackstageViewMenuButtons = class(TCollection)
  private
    FBackstageView: TdxRibbonCustomBackstageView;
    function GetItem(Index: Integer): TdxRibbonBackstageViewMenuButton;
    procedure SetItem(Index: Integer; Value: TdxRibbonBackstageViewMenuButton);
  protected
    function GetOwner: TPersistent; override;
    procedure Update(Item: TCollectionItem); override;
    procedure Notification(AComponent: TComponent; Operation: TOperation);
    //
    property BackstageView: TdxRibbonCustomBackstageView read FBackstageView;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView);
    function Add: TdxRibbonBackstageViewMenuButton;
    function IndexOf(AItem: TdxRibbonBackstageViewMenuButton): Integer;
    function Insert(AIndex: Integer): TdxRibbonBackstageViewMenuButton;
    //
    property Items[Index: Integer]: TdxRibbonBackstageViewMenuButton read GetItem write SetItem; default;
  end;

  { TdxRibbonBackstageViewMenuHelper }

  TdxRibbonBackstageViewMenuHelper = class(TcxMessageWindow)
  private
    FBackstageView: TdxRibbonCustomBackstageView;
  protected
    procedure WndProc(var Message: TMessage); override;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView); reintroduce;
    procedure PostClick(AButton: TdxRibbonBackstageViewMenuButton);
    procedure PostShowRibbonKeyTips;
    //
    property BackstageView: TdxRibbonCustomBackstageView read FBackstageView;
  end;

  { TdxRibbonBackstageViewApplicationMenuHelper }

  TdxRibbonBackstageViewApplicationMenuHelper = class(TInterfacedObject, IdxRibbonApplicationMenu)
  private
    FLinkToBackstageView: TcxObjectLink;
    function GetBackstageView: TdxRibbonCustomBackstageView;
  protected
    // IdxRibbonApplicationMenu
    function CanShowPopup(ARibbon: TdxCustomRibbon): Boolean;
    function ClosePopup: Boolean;
    function GetDisplayMode: TdxRibbonApplicationMenuDisplayMode; virtual;
    function GetOrigin(AIsClientArea: Boolean): TPoint; virtual;
    function GetRootAccessibilityHelper: IdxBarAccessibilityHelper; virtual;
    function Popup(ARibbon: TdxCustomRibbon; var AClosedByEscape: Boolean): Boolean; virtual;
    procedure GetTabOrderList(AList: TList); virtual;
    procedure RibbonFormResized; virtual;
    procedure SelectAppMenuFirstItemControl; virtual;
    procedure ShowKeyTips; virtual;
    procedure UpdateNonClientArea; virtual;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView); virtual;
    destructor Destroy; override;
    //
    property BackstageView: TdxRibbonCustomBackstageView read GetBackstageView;
  end;

  { TdxRibbonBackstageViewCustomButtonViewInfo }

  TdxRibbonBackstageViewCustomButtonViewInfo = class(TdxRibbonBackstageViewCustomViewInfo)
  private
    function GetState: TcxButtonState;
  public
    procedure Click; virtual; abstract;
    //
    property State: TcxButtonState read GetState;
  end;

  { TdxRibbonBackstageViewBackButtonViewInfo }

  TdxRibbonBackstageViewBackButtonViewInfo = class(TdxRibbonBackstageViewCustomButtonViewInfo)
  protected
    function GetMeasureSize: TSize; virtual;
  public
    procedure Click; override;
    procedure Draw(ACanvas: TcxCanvas); virtual;
    //
    property MeasureSize: TSize read GetMeasureSize;
  end;

  { TdxRibbonBackstageViewNonClientViewInfo }

  TdxRibbonBackstageViewNonClientViewInfo = class(TdxRibbonBackstageViewCustomViewInfo)
  private
    FBackButtonViewInfo: TdxRibbonBackstageViewBackButtonViewInfo;
    function GetClientRect: TRect;
    function GetContentRect: TRect;
    function GetDisplayMode: TdxRibbonApplicationMenuDisplayMode;
    function GetHasNonClientArea: Boolean;
    function GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
    function GetPainter: TdxRibbonBackstageViewPainter;
    function GetRibbon: TdxCustomRibbon;
    function GetRibbonFormCaptionHelper: TdxRibbonFormCaptionHelper;
  protected
    FBorderIconsArea: TRect;
    FCaptionArea: TRect;
    FCaptionTextRect: TRect;
    FMenuBarHeaderRect: TRect;
    FTabsArea: TRect;
    procedure CalculateBackButton; virtual;
    procedure CalculateCaptionArea; virtual;
    procedure CalculateMenuBarHeader; virtual;
    function CreateBackButtonViewInfo: TdxRibbonBackstageViewBackButtonViewInfo; virtual;
    procedure DrawBackground(ACanvas: TcxCanvas); virtual;
    procedure DrawCaptionArea(ACanvas: TcxCanvas); virtual;
    procedure DrawMenuBarHeader(ACanvas: TcxCanvas); virtual;
    function GetClientOffsets: TRect; virtual;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView); override;
    destructor Destroy; override;
    procedure Calculate(const ABounds: TRect); override;
    function CreateWindowRegion: TcxRegionHandle; virtual;
    procedure Draw(ACanvas: TcxCanvas); virtual;
    procedure Recalculate;
    //
    property BackButtonViewInfo: TdxRibbonBackstageViewBackButtonViewInfo read FBackButtonViewInfo;
    property BorderIconsArea: TRect read FBorderIconsArea;
    property CaptionArea: TRect read FCaptionArea;
    property CaptionTextRect: TRect read FCaptionTextRect;
    property ClientOffsets: TRect read GetClientOffsets;
    property ClientRect: TRect read GetClientRect;
    property ContentRect: TRect read GetContentRect;
    property DisplayMode: TdxRibbonApplicationMenuDisplayMode read GetDisplayMode;
    property HasNonClientArea: Boolean read GetHasNonClientArea;
    property MenuBarHeaderRect: TRect read FMenuBarHeaderRect;
    property MenuViewInfo: TdxRibbonBackstageViewMenuViewInfo read GetMenuViewInfo;
    property Painter: TdxRibbonBackstageViewPainter read GetPainter;
    property Ribbon: TdxCustomRibbon read GetRibbon;
    property RibbonFormCaptionHelper: TdxRibbonFormCaptionHelper read GetRibbonFormCaptionHelper;
    property TabsArea: TRect read FTabsArea;
  end;

  { TdxRibbonBackstageViewNonClientController }

  TdxRibbonBackstageViewNonClientController = class(TdxRibbonBackstageViewCustomObject,
    IcxMouseTrackingCaller,
    IcxMouseTrackingCaller2)
  private
    FHoveredCell: TdxRibbonBackstageViewCustomButtonViewInfo;
    FPressedCell: TdxRibbonBackstageViewCustomButtonViewInfo;
    function GetViewInfo: TdxRibbonBackstageViewNonClientViewInfo;
    procedure SetHoveredCell(AValue: TdxRibbonBackstageViewCustomButtonViewInfo);
    procedure SetPressedCell(AValue: TdxRibbonBackstageViewCustomButtonViewInfo);
  protected
    function ScreenToLocal(const P: TPoint): TPoint; overload;
    function ScreenToLocal(const P: TSmallPoint): TPoint; overload;
    // IcxMouseTrackingCaller2
    function PtInCaller(const P: TPoint): Boolean;
  public
    destructor Destroy; override;
    function HitTest(const P: TPoint): TdxRibbonBackstageViewCustomButtonViewInfo; virtual;
    procedure MouseDown(AButton: TMouseButton; const P: TPoint); virtual;
    procedure MouseLeave; virtual;
    procedure MouseMove(const P: TPoint); virtual;
    procedure MouseUp(AButton: TMouseButton; const P: TPoint); virtual;
    procedure ProcessMessage(var AMessage: TMessage); virtual;
    procedure RefreshState;
    //
    property HoveredCell: TdxRibbonBackstageViewCustomButtonViewInfo read FHoveredCell write SetHoveredCell;
    property PressedCell: TdxRibbonBackstageViewCustomButtonViewInfo read FPressedCell write SetPressedCell;
    property ViewInfo: TdxRibbonBackstageViewNonClientViewInfo read GetViewInfo;
  end;

  { TdxRibbonBackstageViewAnimationTransition }

  TdxRibbonBackstageViewAnimationTransitionMode = (bvatmShow, bvatmHide);

  TdxRibbonBackstageViewAnimationTransition = class(TdxAnimationTransition)
  private
    FActiveTabBuffer: TcxBitmap;
    FActiveTabIsSolidBackground: Boolean;
    FActiveTabRect: TRect;
    FBackstageView: TdxRibbonCustomBackstageView;
    FBackstageViewBuffer: TcxBitmap;
    FBackstageViewMenuBuffer: TcxBitmap;
    FBackstageViewRect: TRect;
    FMode: TdxRibbonBackstageViewAnimationTransitionMode;
    function GetActiveTab: TdxRibbonBackstageViewTabSheet;
    function GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
    function GetNonClientViewInfo: TdxRibbonBackstageViewNonClientViewInfo;
    function GetViewInfo: TdxRibbonBackstageViewViewInfo;
  protected
    function CalculateContentAlpha: Byte; virtual;
    procedure CalculateViewInfos; virtual;
    procedure DoAnimate; override;
    procedure Finalize; virtual;
    procedure Initalize; virtual;
    procedure PrepareBackstageViewBuffer(ACanvas: TcxCanvas);
    //
    property ActiveTab: TdxRibbonBackstageViewTabSheet read GetActiveTab;
    property ActiveTabBuffer: TcxBitmap read FActiveTabBuffer;
    property ActiveTabIsSolidBackground: Boolean read FActiveTabIsSolidBackground;
    property ActiveTabRect: TRect read FActiveTabRect;
    property BackstageViewBuffer: TcxBitmap read FBackstageViewBuffer;
    property BackstageViewMenuBuffer: TcxBitmap read FBackstageViewMenuBuffer;
    property BackstageViewRect: TRect read FBackstageViewRect;
    property MenuViewInfo: TdxRibbonBackstageViewMenuViewInfo read GetMenuViewInfo;
    property NonClientViewInfo: TdxRibbonBackstageViewNonClientViewInfo read GetNonClientViewInfo;
    property ViewInfo: TdxRibbonBackstageViewViewInfo read GetViewInfo;
  public
    constructor Create(ABackstageView: TdxRibbonCustomBackstageView;
      AMode: TdxRibbonBackstageViewAnimationTransitionMode); reintroduce; virtual;
    destructor Destroy; override;
    //
    property BackstageView: TdxRibbonCustomBackstageView read FBackstageView;
    property Mode: TdxRibbonBackstageViewAnimationTransitionMode read FMode;
  end;

  { TdxRibbonBackstageViewSizeGrip }

  TdxRibbonBackstageViewSizeGrip = class(TdxRibbonSizeGrip)
  protected
    function GetRibbon: TdxCustomRibbon; override;
  end;

  { TdxRibbonBackstageViewScrollBar }

  TdxRibbonBackstageViewScrollBar = class(TdxRibbonScrollBar)
  protected
    function GetRibbon: TdxCustomRibbon; override;
  end;

  { TdxRibbonCustomBackstageView }

  TdxRibbonBackstageViewTabChanging = procedure (Sender: TObject;
    ANewTab: TdxRibbonBackstageViewTabSheet; var AAllowChange: Boolean) of object;

  TdxRibbonCustomBackstageView = class(TcxControl,
    IdxRibbonListener,
    IdxRibbonBackstageViewSelectableItem,
    IdxRibbonMouseWheelReceiver)
  private
    FActiveTab: TdxRibbonBackstageViewTabSheet;
    FApplicationWndProcHooked: Boolean;
    FBarManagerHolder: TcxComponentHolder;
    FButtons: TdxRibbonBackstageViewMenuButtons;
    FChanges: TdxRibbonBackstageViewChanges;
    FDesignSelector: TdxRibbonBackstageViewDesignSelector;
    FMenuHelper: TdxRibbonBackstageViewMenuHelper;
    FNonClientController: TdxRibbonBackstageViewNonClientController;
    FNonClientViewInfo: TdxRibbonBackstageViewNonClientViewInfo;
    FPainter: TdxRibbonBackstageViewPainter;
    FRibbon: TdxCustomRibbon;
    FTabs: TdxRibbonBackstageViewTabSheets;
    FUpdateCount: Integer;
    FViewInfo: TdxRibbonBackstageViewViewInfo;

    FOnCloseUp: TNotifyEvent;
    FOnPopup: TNotifyEvent;
    FOnTabChanged: TNotifyEvent;
    FOnTabChanging: TdxRibbonBackstageViewTabChanging;

    procedure CheckAssignRibbon;
    function CanActivateTab(ATab: TdxRibbonBackstageViewTabSheet): Boolean;
    function GetBarManager: TdxBarManager;
    function GetIsBarManagerValid: Boolean;
    function GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
    function GetTabCount: Integer;
    function GetTabs(Index: Integer): TdxRibbonBackstageViewTabSheet;
    procedure RibbonAfterChange;
    procedure RibbonBeforeChange;
    procedure SetActiveTab(AValue: TdxRibbonBackstageViewTabSheet);
    procedure SetButtons(AValue: TdxRibbonBackstageViewMenuButtons);
    procedure SetRibbon(AValue: TdxCustomRibbon);
  protected
    FDesignHelper: IcxDesignHelper;
    function CanShowPopup(ARibbon: TdxCustomRibbon): Boolean; virtual;
    procedure ColorSchemeChangeHandler(Sender: TObject; const AEventArgs);
    function CreateApplicationMenuHelper: TdxRibbonBackstageViewApplicationMenuHelper; virtual;
    function CreateDesignSelector: TdxRibbonBackstageViewDesignSelector; virtual;
    function CreateNonClientController: TdxRibbonBackstageViewNonClientController; virtual;
    function CreateNonClientViewInfo: TdxRibbonBackstageViewNonClientViewInfo; virtual;
    function CreatePainter: TdxRibbonBackstageViewPainter; virtual;
    function CreateViewInfo: TdxRibbonBackstageViewViewInfo; virtual;
    procedure BoundsChanged; override;
    procedure Calculate; virtual;
    procedure CalculatePlace; virtual;
    procedure Changed(const AChanges: TdxRibbonBackstageViewChanges = []); virtual;
    procedure ClosePopup; virtual;
    procedure CreateWnd; override;
    procedure FocusChanged; override;
    procedure FullInvalidate;
    function Popup(ARibbon: TdxCustomRibbon; var AClosedByEscape: Boolean): Boolean; virtual;
    procedure PrepareForPopup(AForm: TCustomForm); virtual;
    procedure ShowControl(AControl: TControl); override;
    procedure UpdateWindowRegion; virtual;
    //
    function ApplicationWndProcHook(var Message: TMessage): Boolean; virtual;
    procedure HookApplicationWndProc;
    procedure UnhookApplicationWndProc;
    //
    procedure DoAddTab(ATab: TdxRibbonBackstageViewTabSheet);
    procedure DoAfterBarManagerChange(Sender: TObject);
    procedure DoBeforeBarManagerChange(Sender: TObject);
    procedure DoRemoveTab(ATab: TdxRibbonBackstageViewTabSheet);
    procedure DoTabVisibleChanged(ATab: TdxRibbonBackstageViewTabSheet);

    function GetNextTab(AIndex: Integer): TdxRibbonBackstageViewTabSheet; overload;
    function GetNextTab(ATab: TdxRibbonBackstageViewTabSheet): TdxRibbonBackstageViewTabSheet; overload;
    procedure ValidateActiveTab;
    //
    procedure DoCloseUp;
    function DoMouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean; override;
    function DoMouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean; override;
    procedure DoPopup;
    procedure DoTabChanged;
    function DoTabChanging(ANewTab: TdxRibbonBackstageViewTabSheet): Boolean;
  {$IFNDEF DELPHI12}
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
  {$ENDIF}
    procedure InitScrollBarsParameters; override;
    function GetScrollBarClass(AKind: TScrollBarKind): TcxControlScrollBarClass; override;
    function GetSizeGripClass: TcxSizeGripClass; override;
    function NeedsToBringInternalControlsToFront: Boolean; override;
    procedure NCPaint(DC: HDC); virtual;
    procedure MakeFullyVisible(R: TRect);
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure Paint; override;
    procedure PopupMessageLoop(AParentForm: TCustomForm);
    procedure Scroll(AScrollBarKind: TScrollBarKind; AScrollCode: TScrollCode; var AScrollPos: Integer); override;
    procedure SystemFontChanged(Sender: TObject; const AEventArgs);
    // Design
    function IsPersistentSelected(AObject: TPersistent): Boolean;
    procedure SelectPersistent(AObject: TPersistent);
    // IdxRibbonListener
    procedure AfterBarManagerChange;
    procedure BeforeBarManagerChange;
    // IdxRibbonMouseWheelReceiver
    function CanProcessMouseWheel: Boolean;
    // IdxRibbonBackstageViewSelectableItem
    procedure SelectionChanged;
    // IUnknown
    function QueryInterface(const IID: TGUID; out Obj): HRESULT; override; stdcall;
    //
    procedure CMVisibleChanged(var Message: TMessage); message CM_VISIBLECHANGED;
    procedure WMNCCalcSize(var Message: TWMNCCalcSize); message WM_NCCALCSIZE;
    procedure WMNCPaint(var Message: TWMNCPaint); message WM_NCPAINT;
    procedure WMPrint(var Message: TWMPrint); message WM_PRINT;
    procedure WMSize(var Message: TWMSize); message WM_SIZE;
    procedure WndProc(var Message: TMessage); override;
    //
    property BarManager: TdxBarManager read GetBarManager;
    property BarManagerHolder: TcxComponentHolder read FBarManagerHolder;
    property DesignSelector: TdxRibbonBackstageViewDesignSelector read FDesignSelector;
    property IsBarManagerValid: Boolean read GetIsBarManagerValid;
    property IsInPopupLoop: Boolean read FApplicationWndProcHooked;
    property MenuHelper: TdxRibbonBackstageViewMenuHelper read FMenuHelper;
    property MenuViewInfo: TdxRibbonBackstageViewMenuViewInfo read GetMenuViewInfo;
    property NonClientController: TdxRibbonBackstageViewNonClientController read FNonClientController;
    property NonClientViewInfo: TdxRibbonBackstageViewNonClientViewInfo read FNonClientViewInfo;
    property Painter: TdxRibbonBackstageViewPainter read FPainter;
    property ViewInfo: TdxRibbonBackstageViewViewInfo read FViewInfo;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function AddTab: TdxRibbonBackstageViewTabSheet;
    procedure DeleteAllTabs;
    procedure DeleteTab(AIndex: Integer);
    procedure FullRefresh;

  {$IFDEF DELPHI12}
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
  {$ENDIF}
    procedure BeginUpdate;
    procedure EndUpdate;
    //
    property ActiveTab: TdxRibbonBackstageViewTabSheet read FActiveTab write SetActiveTab;
    property Buttons: TdxRibbonBackstageViewMenuButtons read FButtons write SetButtons;
    property OnCloseUp: TNotifyEvent read FOnCloseUp write FOnCloseUp;
    property OnPopup: TNotifyEvent read FOnPopup write FOnPopup;
    property OnTabChanged: TNotifyEvent read FOnTabChanged write FOnTabChanged;
    property OnTabChanging: TdxRibbonBackstageViewTabChanging read FOnTabChanging write FOnTabChanging;
    property Ribbon: TdxCustomRibbon read FRibbon write SetRibbon;
    property TabCount: Integer read GetTabCount;
    property Tabs[Index: Integer]: TdxRibbonBackstageViewTabSheet read GetTabs;
  end;

  { TdxRibbonBackstageView }

  TdxRibbonBackstageView = class(TdxRibbonCustomBackstageView)
  published
    property Buttons;
    property OnCloseUp;
    property OnPopup;
    property OnTabChanged;
    property OnTabChanging;
    property Ribbon;
  end;

var
  FOnRegisterBackstageView: TcxNotifyProcedure;
  FOnUnregisterBackstageView: TcxNotifyProcedure;

implementation

uses
  cxDrawTextUtils, dxBarSkinConsts, dxFading, cxLookAndFeels, dxOffice11, dxRibbonForm;

const
  dxBackstageViewScrollLineSize = 17;

type
  TdxBarButtonAccess = class(TdxBarButton);
  TdxBarItemControlAccess = class(TdxBarItemControl);
  TdxBarItemLinksAccess = class(TdxBarItemLinks);
  TdxCustonRibbonAccess = class(TdxCustomRibbon);
  TWinControlAccess = class(TWinControl);

procedure RegisterBackstageView(ABackstageView: TdxRibbonCustomBackstageView);
begin
  if Assigned(FOnRegisterBackstageView) then
    FOnRegisterBackstageView(ABackstageView);
end;

procedure UnregisterBackstageView(ABackstageView: TdxRibbonCustomBackstageView);
begin
  if Assigned(FOnUnregisterBackstageView) then
    FOnUnregisterBackstageView(ABackstageView);
end;

{ TdxRibbonBackstageViewCustomObject }

constructor TdxRibbonBackstageViewCustomObject.Create(ABackstageView: TdxRibbonCustomBackstageView);
begin
  inherited Create;
  FBackstageView := ABackstageView;
end;

function TdxRibbonBackstageViewCustomObject.GetBarManager: TdxBarManager;
begin
  Result := BackstageView.BarManager;
end;

function TdxRibbonBackstageViewCustomObject.GetIsBarManagerValid: Boolean;
begin
  Result := BackstageView.IsBarManagerValid;
end;

{ TdxRibbonBackstageViewCustomViewInfo }

procedure TdxRibbonBackstageViewCustomViewInfo.Calculate(const ABounds: TRect);
begin
  FBounds := ABounds;
end;

{ TdxRibbonBackstageViewMenuBarAccessibilityHelper }

function TdxRibbonBackstageViewMenuBarAccessibilityHelper.AreKeyTipsSupported(
  out AKeyTipWindowsManager: IdxBarKeyTipWindowsManager): Boolean;
begin
  Result := True;
  if FKeyTipWindowsManager = nil then
    FKeyTipWindowsManager := TdxRibbonBackstageViewKeyTipWindows.Create(BackstageView.Ribbon);
  AKeyTipWindowsManager := FKeyTipWindowsManager;
end;

function TdxRibbonBackstageViewMenuBarAccessibilityHelper.HandleNavigationKey(var AKey: Word): Boolean;
begin
  Result := (AKey = VK_TAB) and (ActiveTab <> nil);
  if Result then
  begin
    UnselectSelectedItemControl;
    ActiveTab.SelectFirst;
  end
  else
    Result := inherited HandleNavigationKey(AKey);
end;

procedure TdxRibbonBackstageViewMenuBarAccessibilityHelper.KeyTipsEscapeHandler;
begin
  BackstageView.ClosePopup;
  BackstageView.MenuHelper.PostShowRibbonKeyTips;
end;

function TdxRibbonBackstageViewMenuBarAccessibilityHelper.GetDefaultSelectableObject(
  ADirection: TcxAccessibilityNavigationDirection): IdxBarAccessibilityHelper;
var
  AItemControl: TdxBarItemControl;
begin
  AItemControl := MenuBarControl.BackstageView.ViewInfo.ActiveTabItemControl;
  if AItemControl <> nil then
    Result := AItemControl.IAccessibilityHelper.GetNextAccessibleObject(ADirection)
  else
    Result := inherited GetDefaultSelectableObject(ADirection);
end;

procedure TdxRibbonBackstageViewMenuBarAccessibilityHelper.InitializeItemKeyTipPosition(
  AItemLinkHelper: TdxBarItemLinkAccessibilityHelper; var AKeyTipInfo: TdxBarKeyTipInfo);
var
  APositionInfo: IdxRibbonBackstageViewKeyTipPositionInfo;
begin
  if Supports(AItemLinkHelper.ItemControl, IdxRibbonBackstageViewKeyTipPositionInfo, APositionInfo) then
  begin
    AKeyTipInfo.BasePoint := GetItemScreenBounds(AItemLinkHelper).TopLeft;
    AKeyTipInfo.BasePoint := cxPointOffset(AKeyTipInfo.BasePoint, APositionInfo.GetKeyTipBasePoint);
    AKeyTipInfo.HorzAlign := taCenter;
    AKeyTipInfo.VertAlign := vaCenter;
  end
  else
    inherited InitializeItemKeyTipPosition(AItemLinkHelper, AKeyTipInfo);
end;

function TdxRibbonBackstageViewMenuBarAccessibilityHelper.GetActiveTab: TdxRibbonBackstageViewTabSheet;
begin
  Result := MenuBarControl.BackstageView.ActiveTab;
end;

function TdxRibbonBackstageViewMenuBarAccessibilityHelper.GetMenuBarControl: TdxRibbonBackstageViewMenuBarControl;
begin
  Result := TdxRibbonBackstageViewMenuBarControl(FOwnerObject);
end;

function TdxRibbonBackstageViewMenuBarAccessibilityHelper.GetBackstageView: TdxRibbonCustomBackstageView;
begin
  Result := MenuBarControl.BackstageView;
end;

{ TdxRibbonBackstageViewMenuBarControl }

function TdxRibbonBackstageViewMenuBarControl.CalcColumnItemRect(
  AItemLink: TdxBarItemLink; const AItemsRect: TRect): TRect;
begin
  Result := inherited CalcColumnItemRect(AItemLink, AItemsRect);
  if AItemLink.Control is TdxRibbonBackstageViewTabSheetButtonControl then
  begin
    with GetItemsRectOffset do
    begin
      Inc(Result.Right, Right);
      Dec(Result.Left, Left);
    end;
  end;
end;

procedure TdxRibbonBackstageViewMenuBarControl.CalcControlsPositions;
begin
  inherited CalcControlsPositions;
  CalcItemRects(ptMenu);
end;

function TdxRibbonBackstageViewMenuBarControl.CanCustomizing: Boolean;
begin
  Result := False;
end;

function TdxRibbonBackstageViewMenuBarControl.CanDrawClippedItem(AItemRect: TRect): Boolean;
begin
  Result := True;
end;

procedure TdxRibbonBackstageViewMenuBarControl.DoBarMouseDown(Button: TMouseButton;
  Shift: TShiftState; const APoint: TPoint; AItemControl: TdxBarItemControl; APointInClientRect: Boolean);

  function GetItemControlAtPos(const APos: TPoint): TdxBarItemControl;
  var
    I: Integer;
  begin
    Result := nil;
    for I := 0 to ViewInfo.ItemControlCount - 1 do
      if PtInRect(ViewInfo.ItemControlViewInfos[I].Bounds, APos) then
      begin
        Result := ViewInfo.ItemControlViewInfos[I].Control;
        Break;
      end;
  end;

  procedure SelectItemControlOwner(AItemControl: TdxBarItemControl);
  begin
    if AItemControl is TdxRibbonBackstageViewMenuBarButtonControl then
      BackstageView.SelectPersistent(TdxRibbonBackstageViewMenuBarButtonControl(AItemControl).Item.MenuButton)
    else
      if AItemControl is TdxRibbonBackstageViewTabSheetButtonControl then
      begin
        TdxRibbonBackstageViewTabSheetButtonControl(AItemControl).Item.Tab.Active := True;
        BackstageView.SelectPersistent(TdxRibbonBackstageViewTabSheetButtonControl(AItemControl).Item.Tab);
      end;
  end;

begin
  if BackstageView.IsDesigning then
  begin
    if AItemControl <> nil then
      SelectItemControlOwner(AItemControl)
    else
      SelectItemControlOwner(GetItemControlAtPos(APoint));
  end;
  inherited DoBarMouseDown(Button, Shift, APoint, AItemControl, APointInClientRect);
end;

procedure TdxRibbonBackstageViewMenuBarControl.DoKeyDown(var Message: TWMKey);
begin
  case Message.CharCode of
    VK_ESCAPE:
      begin
        BackstageView.ClosePopup;
        Message.CharCode := 0;
      end;
    else
      inherited;
  end;
end;

function TdxRibbonBackstageViewMenuBarControl.GetAccessibilityHelperClass: TdxBarAccessibilityHelperClass;
begin
  Result := TdxRibbonBackstageViewMenuBarAccessibilityHelper;
end;

function TdxRibbonBackstageViewMenuBarControl.GetBackstageView: TdxRibbonCustomBackstageView;
begin
  Result := MenuViewInfo.BackstageView;
end;

function TdxRibbonBackstageViewMenuBarControl.GetCaption: TCaption;
begin
  Result := '';
end;

function TdxRibbonBackstageViewMenuBarControl.GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
begin
  Result := TdxRibbonBackstageViewMenuDockControl(DockControl).MenuViewInfo;
end;

function TdxRibbonBackstageViewMenuBarControl.GetItemControlOffset(AItemLink: TdxBarItemLink): Integer;
begin
  Result := inherited GetItemControlOffset(AItemLink) + MenuViewInfo.Painter.MenuBarIndentBetweenItems;
end;

function TdxRibbonBackstageViewMenuBarControl.GetItemsRectOffset: TRect;
begin
  Result := MenuViewInfo.Painter.MenuBarItemsRectOffset;
end;

function TdxRibbonBackstageViewMenuBarControl.GetMaxWidth(AStyle: TdxBarDockingStyle): Integer;
begin
  Result := GetMinWidth(AStyle);
end;

function TdxRibbonBackstageViewMenuBarControl.GetMinWidth(AStyle: TdxBarDockingStyle): Integer;
var
  AControl: TdxBarItemControl;
  I: Integer;
begin
  Result := 0;
  for I := 0 to ItemLinks.CanVisibleItemCount - 1 do
  begin
    AControl := ItemLinks.CanVisibleItems[I].Control;
    if AControl <> nil then
    begin
      if not (AControl is TdxRibbonBackstageViewTabSheetButtonControl) then
        Result := Max(Result, TdxBarItemControlAccess(AControl).Width);
    end;
  end;
  Result := Max(Result + cxMarginsWidth(GetItemsRectOffset), dxRibbonBackstageViewMinMenuWidth);
end;

function TdxRibbonBackstageViewMenuBarControl.GetNextBarControl(AForward: Boolean): TdxBarControl;
begin
  Result := nil;
end;

function TdxRibbonBackstageViewMenuBarControl.GetRibbon: TdxCustomRibbon;
begin
  Result := MenuViewInfo.Ribbon;
end;

function TdxRibbonBackstageViewMenuBarControl.GetViewInfoClass: TCustomdxBarControlViewInfoClass;
begin
  Result := TdxRibbonBackstageViewMenuBarControlViewInfo;
end;

function TdxRibbonBackstageViewMenuBarControl.HasCaptionButtons: Boolean;
begin
  Result := False;
end;

function TdxRibbonBackstageViewMenuBarControl.IsInternal: Boolean;
begin
  Result := True;
end;

function TdxRibbonBackstageViewMenuBarControl.IsVertical: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonBackstageViewMenuBarControl.MakeItemControlFullyVisible(AItemControl: TdxBarItemControl);
begin
  if DockControl <> nil then
  begin
    BackstageView.MakeFullyVisible(dxMapWindowRect(
      Handle, BackstageView.Handle, AItemControl.ViewInfo.Bounds));
  end;
end;

function TdxRibbonBackstageViewMenuBarControl.NeedsMouseWheel: Boolean;
begin
  Result := BackstageView.CanProcessMouseWheel;
end;

procedure TdxRibbonBackstageViewMenuBarControl.SetLayeredAttributes;
begin
  //nothing
end;

procedure TdxRibbonBackstageViewMenuBarControl.ShowPopup(AItem: TdxBarItemControl);
begin
  //nothing
end;

procedure TdxRibbonBackstageViewMenuBarControl.WndProc(var Message: TMessage);
begin
  if ((Message.Msg = WM_LBUTTONDOWN) or (Message.Msg = WM_LBUTTONDBLCLK)) and BackstageView.IsDesigning then
  begin
    if not IsControlMouseMsg(TWMMouse(Message)) then
    begin
      ControlState := ControlState + [csLButtonDown];
      Dispatch(Message);
      ControlState := ControlState - [csLButtonDown];
    end;
  end
  else
    inherited WndProc(Message);
end;

procedure TdxRibbonBackstageViewMenuBarControl.CMDesignHitTest(var Message: TCMDesignHitTest);
begin
  Message.Result := 1;
end;

procedure TdxRibbonBackstageViewMenuBarControl.WMMouseWheel(var Message: TWMMouseWheel);
begin
  BackstageView.DoMouseWheel(KeysToShiftState(Message.Keys),
    Message.WheelDelta, SmallPointToPoint(Message.Pos));
  Message.Result := 1;
end;

{ TdxRibbonBackstageViewMenuBarControlViewInfo }

procedure TdxRibbonBackstageViewMenuBarControlViewInfo.DoCalcSeparatorInfo(
  AItemLink: TdxBarItemLink; const AItemRect: TRect);
begin
  AddSeparatorInfo(cxRectSetBottom(AItemRect, AItemRect.Top,
    TdxRibbonBackstageViewMenuBarControl(BarControl).BeginGroupSize),
    skHorizontal, AItemLink.Control);
end;

{ TdxRibbonBackstageViewPainter }

constructor TdxRibbonBackstageViewPainter.Create(ABackstageView: TdxRibbonCustomBackstageView);
begin
  inherited Create;
  FBackstageView := ABackstageView;
end;

procedure TdxRibbonBackstageViewPainter.DrawBackButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
const
  StateMap: array[TcxButtonState] of Integer = (
    DXBAR_ACTIVE, DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED, DXBAR_DISABLED
  );
begin
  if Skin = nil then
    BackstageView.LookAndFeelPainter.DrawBackButton(ACanvas, R, AState)
  else
    Skin.DrawBackground(ACanvas.Handle, R, DXBAR_BACKSTAGEVIEW_BACKBUTTON, StateMap[AState]);
end;

procedure TdxRibbonBackstageViewPainter.DrawBackground(ACanvas: TcxCanvas; const R: TRect);
begin
  if Skin = nil then
    ACanvas.FillRect(R, clCream)
  else
    Skin.DrawBackground(ACanvas.Handle, R, DXBAR_BACKSTAGEVIEW);
end;

procedure TdxRibbonBackstageViewPainter.DrawMenuBarHeader(ACanvas: TcxCanvas; const R: TRect);
begin
  if Skin = nil then
    ACanvas.FillRect(R, clCream)
  else
    Skin.DrawBackground(ACanvas.Handle, R, DXBAR_BACKSTAGEVIEW_MENUBAR_HEADER);
end;

function TdxRibbonBackstageViewPainter.GetBackButtonSize: TSize;
begin
  if Skin = nil then
    Result := BackstageView.LookAndFeelPainter.GetBackButtonSize
  else
    Result := cxSize(
      Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_BACKBUTTON),
      Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_BACKBUTTON));
end;

function TdxRibbonBackstageViewPainter.GetContentOffsets: TRect;
begin
  if Skin = nil then
    Result := cxNullRect
  else
    Result := Skin.GetContentOffsets(DXBAR_BACKSTAGEVIEW);
end;

function TdxRibbonBackstageViewPainter.GetSkin: IdxSkin;
begin
  if not Supports(FBackstageView.Ribbon, IdxSkin, Result) then
    Result := nil;
end;

{ TdxRibbonBackstageViewPainter }

function TdxRibbonBackstageViewMenuPainter.BarBeginGroupSize: Integer;
begin
  Result := Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_MENUBAR_SEPARATOR);
end;

procedure TdxRibbonBackstageViewMenuPainter.BarDrawBeginGroup(
  ABarControl: TCustomdxBarControl; DC: HDC; ABeginGroupRect: TRect;
  AToolbarBrush: HBRUSH; AHorz: Boolean);
begin
  Skin.DrawBackground(DC, ABeginGroupRect, DXBAR_BACKSTAGEVIEW_MENUBAR_SEPARATOR);
end;

procedure TdxRibbonBackstageViewMenuPainter.DrawButtonBackground(
  const ADrawParams: TdxBarButtonLikeControlDrawParams);
begin
  Skin.DrawBackground(ADrawParams.Canvas.Handle,
    ADrawParams.BarItemControl.ItemBounds, DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM,
    GetButtonPartState(ADrawParams, icpControl));
end;

procedure TdxRibbonBackstageViewMenuPainter.DockControlFillBackground(
  ADockControl: TdxDockControl; DC: HDC; ADestR: TRect; ASourceR: TRect;
  AWholeR: TRect; ABrush: HBRUSH; AColor: TColor);
begin
  Skin.DrawBackground(DC, AWholeR, DXBAR_BACKSTAGEVIEW_MENUBAR);
end;

procedure TdxRibbonBackstageViewMenuPainter.DrawTabButton(
  const ADrawParams: TdxBarButtonLikeControlDrawParams; R: TRect);

  function GetTabButtonState: Integer;
  begin
    if ADrawParams.IsPressed then
      Result := DXBAR_PRESSED
    else
      if not ADrawParams.Downed then
        Result := GetPartState(ADrawParams, icpControl)
      else
        if ADrawParams.HotPartIndex = icpControl then
          Result := DXBAR_HOTCHECK
        else
          Result := DXBAR_CHECKED;
  end;

  function GetTextColorState(AButtonState: Integer): Integer;
  begin
    Result := AButtonState;
    if ADrawParams.IsCustomizing then
    begin
      if not ADrawParams.Enabled then
        Result := DXBAR_DISABLED;
    end;
  end;

var
  AState: Integer;
begin
  AState := GetTabButtonState;
  if not dxFader.DrawFadeImage(ADrawParams.BarItemControl, ADrawParams.Canvas.Handle, R) then
    DrawTabButtonBackground(ADrawParams.Canvas.Handle, R, AState);

  if cpText in ADrawParams.ViewStructure then
  begin
    R := cxRectContent(R, TabButtonContentOffset);
    ADrawParams.Canvas.Font.Color := TabButtonTextColor(GetTextColorState(AState));
    cxTextOut(ADrawParams.Canvas.Handle, ADrawParams.Caption, R,
      CXTO_EDITCONTROL or CXTO_WORDBREAK or CXTO_CENTER_VERTICALLY);
  end;
end;

procedure TdxRibbonBackstageViewMenuPainter.DrawTabButtonBackground(DC: HDC; R: TRect; AState: Integer);
begin
  Skin.DrawBackground(DC, R, DXBAR_BACKSTAGEVIEW_MENUBAR_TAB, AState);
end;

procedure TdxRibbonBackstageViewMenuPainter.DrawToolbarContentPart(
  ABarControl: TdxBarControl; ACanvas: TcxCanvas);
var
  R: TRect;
begin
  ACanvas.SaveClipRegion;
  try
    R := dxMapWindowRect(ABarControl.DockControl.Handle, ABarControl.Handle, ABarControl.DockControl.ClientRect);
    ACanvas.IntersectClipRect(ABarControl.ClientRect);
    Skin.DrawBackground(ACanvas.Handle, R, DXBAR_BACKSTAGEVIEW_MENUBAR);
  finally
    ACanvas.RestoreClipRegion;
  end;
end;

procedure TdxRibbonBackstageViewMenuPainter.DrawToolbarNonContentPart(
  ABarControl: TdxBarControl; DC: HDC);
begin
end;

procedure TdxRibbonBackstageViewMenuPainter.GetDisabledTextColors(
  ABarItemControl: TdxBarItemControl; ASelected: Boolean; AFlat: Boolean;
  var AColor1, AColor2: TColor);
const
  StateMap: array[Boolean] of Integer = (DXBAR_DISABLED, DXBAR_ACTIVEDISABLED);
begin
  AColor1 := Skin.GetPartColor(DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM_TEXTCOLOR, StateMap[ASelected]);
  AColor2 := AColor1;
end;

function TdxRibbonBackstageViewMenuPainter.GetEnabledTextColor(
  ABarItemControl: TdxBarItemControl; ASelected: Boolean; AFlat: Boolean): TColor;
begin
  if Skin <> nil then
    Result := Skin.GetPartColor(DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM_TEXTCOLOR)
  else
    Result := inherited GetEnabledTextColor(ABarItemControl, ASelected, AFlat);
end;

function TdxRibbonBackstageViewMenuPainter.GetToolbarContentOffsets(
  ABar: TdxBar; ADockingStyle: TdxBarDockingStyle; AHasSizeGrip: Boolean): TRect;
begin
  Result := cxNullRect;
end;

function TdxRibbonBackstageViewMenuPainter.MenuBarButtonContentOffset: TRect;
begin
  if Skin <> nil then
    Result := Skin.GetContentOffsets(DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM)
  else
    Result := cxNullRect;
end;

function TdxRibbonBackstageViewMenuPainter.MenuBarDefaultItemHeight: Integer;
begin
  if Skin <> nil then
    Result := Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM)
  else
    Result := 0;
end;

function TdxRibbonBackstageViewMenuPainter.MenuBarIndentBetweenItems: Integer;
begin
  if Skin <> nil then
    Result := Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_MENUBAR_INDENTBETWEENITEMS)
  else
    Result := 0;
end;

function TdxRibbonBackstageViewMenuPainter.MenuBarItemsRectOffset: TRect;
begin
  if Skin <> nil then
    Result := Skin.GetContentOffsets(DXBAR_BACKSTAGEVIEW_MENUBAR)
  else
    Result := cxNullRect;
end;

function TdxRibbonBackstageViewMenuPainter.TabButtonContentOffset: TRect;
begin
  if Skin <> nil then
    Result := Skin.GetContentOffsets(DXBAR_BACKSTAGEVIEW_MENUBAR_TAB)
  else
    Result := cxNullRect;
end;

function TdxRibbonBackstageViewMenuPainter.TabButtonDefaultHeight: Integer;
begin
  if Skin <> nil then
    Result := Skin.GetPartSize(DXBAR_BACKSTAGEVIEW_MENUBAR_TAB)
  else
    Result := 0;
end;

function TdxRibbonBackstageViewMenuPainter.TabButtonTextColor(AState: Integer): TColor;
begin
  if Skin <> nil then
    Result := Skin.GetPartColor(DXBAR_BACKSTAGEVIEW_MENUBAR_TAB_TEXTCOLOR, AState)
  else
    Result := clWindowText;
end;

{ TdxRibbonBackstageViewMenuDockControl }

constructor TdxRibbonBackstageViewMenuDockControl.Create(
  AMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo);
begin
  inherited Create(AMenuViewInfo.BackstageView);
  FMenuViewInfo := AMenuViewInfo;
end;

procedure TdxRibbonBackstageViewMenuDockControl.CalcLayout;
var
  ABounds: TRect;
begin
  if MenuViewInfo.BarControl <> nil then
  begin
    ABounds := cxRectSetHeight(ClientRect, MenuViewInfo.MinHeight);
    if cxRectIsEqual(ABounds, MenuViewInfo.BarControl.BoundsRect) then
      MenuViewInfo.BarControl.CalcLayout
    else
      MenuViewInfo.BarControl.BoundsRect := ABounds;
  end;
end;

function TdxRibbonBackstageViewMenuDockControl.CanCustomize: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonBackstageViewMenuDockControl.CMDesignHitTest(var Message: TCMDesignHitTest);
begin
  Message.Result := 0;
end;

function TdxRibbonBackstageViewMenuDockControl.GetBackstageView: TdxRibbonCustomBackstageView;
begin
  Result := MenuViewInfo.BackstageView;
end;

function TdxRibbonBackstageViewMenuDockControl.GetContainer: TObject;
begin
  Result := BackstageView;
end;

function TdxRibbonBackstageViewMenuDockControl.GetClientSize: Integer;
begin
  Result := MenuViewInfo.MinWidth;
end;

function TdxRibbonBackstageViewMenuDockControl.GetDockedBarControlClass: TdxBarControlClass;
begin
  Result := TdxRibbonBackstageViewMenuBarControl;
end;

function TdxRibbonBackstageViewMenuDockControl.GetDockingStyle: TdxBarDockingStyle;
begin
  Result := dsLeft;
end;

function TdxRibbonBackstageViewMenuDockControl.GetMinSize: Integer;
begin
  if MenuViewInfo <> nil then
    Result := MenuViewInfo.MinWidth
  else
    Result := 0;
end;

function TdxRibbonBackstageViewMenuDockControl.GetPainter: TdxBarPainter;
begin
  Result := MenuViewInfo.Painter;
end;

function TdxRibbonBackstageViewMenuDockControl.GetRibbon: TdxCustomRibbon;
begin
  Result := MenuViewInfo.Ribbon;
end;

function TdxRibbonBackstageViewMenuDockControl.GetSunkenBorder: Boolean;
begin
  Result := False;
end;

function TdxRibbonBackstageViewMenuDockControl.IsDrawDesignBorder: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonBackstageViewMenuDockControl.ShowCustomizePopup;
begin
  // do nothing
end;

{ TdxRibbonBackstageViewTabSheetViewInfo }

constructor TdxRibbonBackstageViewTabSheetViewInfo.Create(ATab: TdxRibbonBackstageViewTabSheet);
begin
  inherited Create;
  FTab := ATab;
end;

procedure TdxRibbonBackstageViewTabSheetViewInfo.Calculate(const R: TRect);
begin
  FBounds := R;
end;

procedure TdxRibbonBackstageViewTabSheetViewInfo.ValidateWindowPos(var APos: TWindowPos);
begin
  APos.x := Bounds.Left;
  APos.y := Bounds.Top;
  APos.cx := cxRectWidth(Bounds);
  APos.cy := cxRectHeight(Bounds);
end;

function TdxRibbonBackstageViewTabSheetViewInfo.GetFrameAreaVisibleBounds: TRect;
begin
  Result := Tab.BackstageView.ViewInfo.FrameAreaVisibleBounds;
end;

function TdxRibbonBackstageViewTabSheetViewInfo.GetMinHeight: Integer;
var
  ANewWidth, ANewHeight: Integer;
begin
  Result := Tab.SizeOptions.MinHeight;
  if Tab.SizeOptions.AutoSize then
  begin
    Tab.CanAutoSize(ANewWidth, ANewHeight);
    Result := Max(Result, ANewHeight);
  end;
end;

function TdxRibbonBackstageViewTabSheetViewInfo.GetMinWidth: Integer;
var
  ANewWidth, ANewHeight: Integer;
begin
  Result := Tab.SizeOptions.MinWidth;
  if Tab.SizeOptions.AutoSize then
  begin
    Tab.CanAutoSize(ANewWidth, ANewHeight);
    Result := Max(Result, ANewWidth);
  end;
end;

{ TdxRibbonBackstageViewTabSheetSizeOptions }

constructor TdxRibbonBackstageViewTabSheetSizeOptions.Create(ATab: TdxRibbonBackstageViewTabSheet);
begin
  inherited Create;
  FTab := ATab;
end;

procedure TdxRibbonBackstageViewTabSheetSizeOptions.Assign(Source: TPersistent);
begin
  if Source is TdxRibbonBackstageViewTabSheetSizeOptions then
  begin
    BeginUpdate;
    try
      MinWidth := TdxRibbonBackstageViewTabSheetSizeOptions(Source).MinWidth;
      MinHeight := TdxRibbonBackstageViewTabSheetSizeOptions(Source).MinHeight;
      AutoSize := TdxRibbonBackstageViewTabSheetSizeOptions(Source).AutoSize;
    finally
      EndUpdate;
    end;
  end;
end;

procedure TdxRibbonBackstageViewTabSheetSizeOptions.BeginUpdate;
begin
  Inc(FUpdateCount);
end;

procedure TdxRibbonBackstageViewTabSheetSizeOptions.EndUpdate;
begin
  Dec(FUpdateCount);
  if (FUpdateCount = 0) and FHasChanges then
    Changed;
end;

procedure TdxRibbonBackstageViewTabSheetSizeOptions.Changed;
begin
  if FUpdateCount > 0 then
    FHasChanges := True
  else
  begin
    FHasChanges := False;
    FTab.Changed;
  end;
end;

function TdxRibbonBackstageViewTabSheetSizeOptions.GetAutoSize: Boolean;
begin
  Result := FTab.AutoSize;
end;

procedure TdxRibbonBackstageViewTabSheetSizeOptions.SetAutoSize(AValue: Boolean);
begin
  FTab.AutoSize := AValue;
end;

procedure TdxRibbonBackstageViewTabSheetSizeOptions.SetMinHeight(AValue: Integer);
begin
  AValue := Max(AValue, 0);
  if AValue <> FMinHeight then
  begin
    FMinHeight := AValue;
    Changed;
  end;
end;

procedure TdxRibbonBackstageViewTabSheetSizeOptions.SetMinWidth(AValue: Integer);
begin
  AValue := Max(AValue, 0);
  if AValue <> FMinWidth then
  begin
    FMinWidth := AValue;
    Changed;
  end;
end;

{ TdxRibbonBackstageViewTabSheet }

constructor TdxRibbonBackstageViewTabSheet.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ControlStyle := ControlStyle + [csAcceptsControls];
  FSizeOptions := TdxRibbonBackstageViewTabSheetSizeOptions.Create(Self);
  FViewInfo := CreateViewInfo;
  FTabVisible := True;
  ParentShowHint := False;
  ShowHint := False;
  TabStop := False;
  Visible := False;
end;

destructor TdxRibbonBackstageViewTabSheet.Destroy;
begin
  FreeAndNil(FViewInfo);
  FreeAndNil(FSizeOptions);
  inherited Destroy;
end;

procedure TdxRibbonBackstageViewTabSheet.Activate;
begin
  Visible := True;
  BringToFront;
end;

procedure TdxRibbonBackstageViewTabSheet.AlignControls(AControl: TControl; var Rect: TRect);
begin
  inherited AlignControls(AControl, Rect);
  RefreshNonClientArea;
end;

procedure TdxRibbonBackstageViewTabSheet.Calculate(const R: TRect);
begin
  ViewInfo.Calculate(R);
  BoundsRect := ViewInfo.Bounds;
end;

procedure TdxRibbonBackstageViewTabSheet.Changed;
begin
  if BackstageView <> nil then
  begin
    BarDesignController.LockDesignerModified;
    try
      BackstageView.Changed([rbvcTabsData]);
    finally
      BarDesignController.UnLockDesignerModified;
    end;
  end;
end;

function TdxRibbonBackstageViewTabSheet.CanResize(var NewWidth, NewHeight: Integer): Boolean;
begin
  Result := inherited CanResize(NewWidth, NewHeight);
  if Result then
  begin
    NewHeight := Max(NewHeight, ViewInfo.MinHeight);
    NewWidth := Max(NewWidth, ViewInfo.MinWidth);
  end;
end;

function TdxRibbonBackstageViewTabSheet.CreateViewInfo: TdxRibbonBackstageViewTabSheetViewInfo;
begin
  Result := TdxRibbonBackstageViewTabSheetViewInfo.Create(Self);
end;

procedure TdxRibbonBackstageViewTabSheet.Deactivate;
begin
  Visible := False;
end;

procedure TdxRibbonBackstageViewTabSheet.DrawBackground(ACanvas: TcxCanvas);
var
  R: TRect;
begin
  R := dxMapWindowRect(BackstageView.Handle, Handle, cxGetWindowBounds(BackstageView), False);
  R := cxRectOffset(R, cxGetClientOffset(Handle), False);
  Painter.DrawBackground(ACanvas, R);
end;

procedure TdxRibbonBackstageViewTabSheet.NCPaint(DC: HDC);
var
  R: TRect;
begin
  cxPaintCanvas.BeginPaint(DC);
  try
    R := Rect(0, 0, Width, Height);
    cxPaintCanvas.ExcludeClipRect(cxRectInflate(R, -BorderWidth, -BorderWidth));
    cxPaintCanvas.WindowOrg := cxPointInvert(cxGetClientOffset(Handle));
    DrawBackground(cxPaintCanvas);
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

procedure TdxRibbonBackstageViewTabSheet.RefreshNonClientArea;
begin
  if (BorderWidth > 0) and HandleAllocated then
    SendMessage(Handle, WM_NCPAINT, 0, 0);
end;

procedure TdxRibbonBackstageViewTabSheet.CMEnabledChanged(var Message: TMessage);
begin
  inherited;
  Changed;
end;

procedure TdxRibbonBackstageViewTabSheet.CMTextChanged(var Message: TMessage);
begin
  inherited;
  Changed;
end;

procedure TdxRibbonBackstageViewTabSheet.WMNCPaint(var Message: TWMNCPaint);
var
  DC: HDC;
begin
  if BorderWidth > 0 then
  begin
    DC := GetWindowDC(Handle);
    try
      NCPaint(DC);
    finally
      ReleaseDC(Handle, DC);
    end;
  end;
end;

procedure TdxRibbonBackstageViewTabSheet.WMPrint(var Message: TWMPrint);
begin
  if (PRF_NONCLIENT and Message.Flags <> 0) and (BorderWidth > 0) then
    NCPaint(Message.DC);
  inherited;
end;

function TdxRibbonBackstageViewTabSheet.GetActive: Boolean;
begin
  Result := (BackstageView <> nil) and (BackstageView.ActiveTab = Self);
end;

function TdxRibbonBackstageViewTabSheet.GetCanBeActive: Boolean;
begin
  Result := IsDesigning or TabVisible and Enabled;
end;

function TdxRibbonBackstageViewTabSheet.GetPageIndex: Integer;
begin
  if BackstageView = nil then
    Result := -1
  else
    Result := BackstageView.FTabs.IndexOf(Self);
end;

function TdxRibbonBackstageViewTabSheet.GetPainter: TdxRibbonBackstageViewPainter;
begin
  Result := BackstageView.Painter;
end;

procedure TdxRibbonBackstageViewTabSheet.Paint;
begin
  DrawBackground(Canvas);
end;

procedure TdxRibbonBackstageViewTabSheet.SetPageIndex(AValue: Integer);
begin
  if Assigned(BackstageView) and (AValue <> PageIndex) then
  begin
    if (AValue >= 0) and (AValue < BackstageView.TabCount) then
    begin
      BackstageView.FTabs.Move(PageIndex, AValue);
      BackstageView.Changed([rbvcStruct]);
    end;
  end;
end;

procedure TdxRibbonBackstageViewTabSheet.SetActive(AValue: Boolean);
begin
  if AValue and (BackstageView <> nil) then
    BackstageView.ActiveTab := Self;
end;

procedure TdxRibbonBackstageViewTabSheet.SetBackstageView(AValue: TdxRibbonCustomBackstageView);
begin
  if AValue <> BackstageView then
  begin
    if BackstageView <> nil then
      BackstageView.DoRemoveTab(Self);
    FBackstageView := AValue;
    Parent := BackstageView;
    if BackstageView <> nil then
      BackstageView.DoAddTab(Self);
  end;
end;

procedure TdxRibbonBackstageViewTabSheet.SetBounds(ALeft, ATop, AWidth, AHeight: Integer);
begin
  if Assigned(ViewInfo) then
  begin
    ATop := ViewInfo.Bounds.Top;
    ALeft := ViewInfo.Bounds.Left;
    AWidth := cxRectWidth(ViewInfo.Bounds);
    AHeight := cxRectHeight(ViewInfo.Bounds);
  end;
  inherited SetBounds(ALeft, ATop, AWidth, AHeight);
end;

procedure TdxRibbonBackstageViewTabSheet.SetKeyTip(const AValue: string);
begin
  if AValue <> FKeyTip then
  begin
    FKeyTip := AValue;
    Changed;
  end;
end;

procedure TdxRibbonBackstageViewTabSheet.SetParent(AParent: TWinControl);
begin
  if (AParent = nil) or (AParent is TdxRibbonCustomBackstageView) then
  begin
    BackstageView := TdxRibbonCustomBackstageView(AParent);
    inherited SetParent(AParent);
  end
  else
    Abort;
end;

procedure TdxRibbonBackstageViewTabSheet.SetSizeOptions(AValue: TdxRibbonBackstageViewTabSheetSizeOptions);
begin
  FSizeOptions.Assign(AValue);
end;

procedure TdxRibbonBackstageViewTabSheet.SetTabVisible(AValue: Boolean);
begin
  if AValue <> FTabVisible then
  begin
    FTabVisible := AValue;
    if BackstageView <> nil then
      BackstageView.DoTabVisibleChanged(Self);
  end;
end;

{ TdxRibbonBackstageViewTabSheets }

function TdxRibbonBackstageViewTabSheets.GetItem(Index: Integer): TdxRibbonBackstageViewTabSheet;
begin
  Result := TdxRibbonBackstageViewTabSheet(inherited Items[Index]);
end;

{ TdxRibbonBackstageViewTabSheetButton }

constructor TdxRibbonBackstageViewTabSheetButton.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  ButtonStyle := bsChecked;
end;

procedure TdxRibbonBackstageViewTabSheetButton.RefreshInfo;
begin
  if Tab <> nil then
  begin
    Caption := Tab.Caption;
    Enabled := Tab.Enabled;
    KeyTip := Tab.KeyTip;
    Down := Tab.Active;
    Hint := Tab.Hint;
  end;
end;

function TdxRibbonBackstageViewTabSheetButton.GetControlClass(AIsVertical: Boolean): TdxBarItemControlClass;
begin
  Result := TdxRibbonBackstageViewTabSheetButtonControl;
end;

procedure TdxRibbonBackstageViewTabSheetButton.SetTab(AValue: TdxRibbonBackstageViewTabSheet);
begin
  FTab := AValue;
  RefreshInfo;
end;

{ TdxRibbonBackstageViewTabSheetButtonControl }

procedure TdxRibbonBackstageViewTabSheetButtonControl.ActivateTab;
begin
  if Enabled then
  begin
    Item.Tab.Active := True;
    Item.RefreshInfo;
    IAccessibilityHelper.Select(True);
  end;
end;

function TdxRibbonBackstageViewTabSheetButtonControl.CanCustomize: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonBackstageViewTabSheetButtonControl.ControlActivate(
  AImmediately: Boolean; AByMouse: Boolean);
begin
  inherited ControlActivate(AImmediately, AByMouse);
  if not AByMouse then
    ActivateTab;
end;

procedure TdxRibbonBackstageViewTabSheetButtonControl.ControlClick(AByMouse: Boolean; AKey: Char = #0);
begin
  inherited ControlClick(AByMouse, AKey);
  ActivateTab;
end;

procedure TdxRibbonBackstageViewTabSheetButtonControl.ControlUnclick(AByMouse: Boolean);
begin
  inherited ControlUnclick(AByMouse);
  ActivateTab;
end;

procedure TdxRibbonBackstageViewTabSheetButtonControl.DoPaint(
  ARect: TRect; PaintType: TdxBarPaintType);
begin
  MenuPainter.DrawTabButton(DrawParams, ARect);
end;

function TdxRibbonBackstageViewTabSheetButtonControl.CanDestroyOnClick: Boolean;
begin
  Result := False;
end;

function TdxRibbonBackstageViewTabSheetButtonControl.GetDefaultHeight: Integer;
var
  AContentOffset: TRect;
  ASavedFont: TdxBarSavedFont;
  R: TRect;
begin
  AContentOffset := MenuPainter.TabButtonContentOffset;
  PrepareCanvasFont(0, Item.Style, ASavedFont);
  try
    R := cxRect(AContentOffset.Left, 0, MenuViewInfo.MinWidth - AContentOffset.Right, 0);
    cxTextOut(Canvas.Handle, Item.Caption, R,
      CXTO_EDITCONTROL or CXTO_CALCRECT or CXTO_WORDBREAK);
    Result := cxRectHeight(R) + AContentOffset.Top + AContentOffset.Bottom;
  finally
    RestoreCanvasFont(ASavedFont);
  end;
  Result := Max(Result, MenuPainter.TabButtonDefaultHeight);
end;

procedure TdxRibbonBackstageViewTabSheetButtonControl.GetFadingImages(
  out AFadeOutImage, AFadeInImage: TcxBitmap);

  function PrepareImage(const R: TRect; AState: Integer): TcxBitmap32;
  begin
    Result := TcxBitmap32.CreateSize(R, True);
    MenuPainter.DrawTabButtonBackground(Result.Canvas.Handle, R, AState);
  end;

var
  R: TRect;
begin
  if Down then
  begin
    AFadeInImage := nil;
    AFadeOutImage := nil;
  end
  else
  begin
    R := ItemBounds;
    OffsetRect(R, -R.Left, -R.Top);
    AFadeOutImage := PrepareImage(R, DXBAR_NORMAL);
    AFadeInImage := PrepareImage(R, DXBAR_HOT);
  end;
end;

function TdxRibbonBackstageViewTabSheetButtonControl.GetItem: TdxRibbonBackstageViewTabSheetButton;
begin
  Result := TdxRibbonBackstageViewTabSheetButton(inherited Item);
end;

function TdxRibbonBackstageViewTabSheetButtonControl.GetKeyTipBasePoint: TPoint;
begin
  Result := cxPointOffset(MenuPainter.TabButtonContentOffset.TopLeft, -2 * cxTextSpace, 0);
end;

function TdxRibbonBackstageViewTabSheetButtonControl.GetMenuPainter: TdxRibbonBackstageViewMenuPainter;
begin
  Result := MenuViewInfo.Painter;
end;

function TdxRibbonBackstageViewTabSheetButtonControl.GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
begin
  Result := Item.Tab.BackstageView.MenuViewInfo;
end;

{ TdxRibbonBackstageViewTabSheetButtonList }

function TdxRibbonBackstageViewTabSheetButtonList.GetItem(Index: Integer): TdxRibbonBackstageViewTabSheetButton;
begin
  Result := TdxRibbonBackstageViewTabSheetButton(inherited Items[Index]);
end;

function TdxRibbonBackstageViewTabSheetButtonList.GetItemByTab(
  ATab: TdxRibbonBackstageViewTabSheet): TdxRibbonBackstageViewTabSheetButton;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if Items[I].Tab = ATab then
    begin
      Result := Items[I];
      Break;
    end;
end;

procedure TdxRibbonBackstageViewTabSheetButtonList.RefreshInfo;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].RefreshInfo;
end;

procedure TdxRibbonBackstageViewTabSheetButtonList.RemoveTab(ATab: TdxRibbonBackstageViewTabSheet);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    if Items[I].Tab = ATab then
    begin
      FreeAndDelete(I);
      Break;
    end;
end;

{ TdxRibbonBackstageViewMenuButtonList }

function TdxRibbonBackstageViewMenuButtonList.GetItem(Index: Integer): TdxRibbonBackstageViewMenuBarButton;
begin
  Result := TdxRibbonBackstageViewMenuBarButton(inherited Items[Index]);
end;

procedure TdxRibbonBackstageViewMenuButtonList.RefreshInfo;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].RefreshInfo;
end;

{ TdxRibbonBackstageViewMenuViewInfo }

constructor TdxRibbonBackstageViewMenuViewInfo.Create(ABackstageView: TdxRibbonCustomBackstageView);
begin
  inherited Create(ABackstageView);
  FMenuButtonList := TdxRibbonBackstageViewMenuButtonList.Create;
  FTabButtonList := TdxRibbonBackstageViewTabSheetButtonList.Create;
  FDockControl := TdxRibbonBackstageViewMenuDockControl.Create(Self);
  FDockControl.AllowDocking := False;
  FDockControl.Parent := BackstageView;
  FDockControl.Visible := True;
  FDockControl.Align := dalNone;
  CreateViewInfoItems;
end;

destructor TdxRibbonBackstageViewMenuViewInfo.Destroy;
begin
  DestroyViewInfoItems;
  FreeAndNil(FMenuButtonList);
  FreeAndNil(FTabButtonList);
  FreeAndNil(FDockControl);
  inherited Destroy;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.AddButton(AButton: TdxRibbonBackstageViewMenuButton);
var
  AItem: TdxRibbonBackstageViewMenuBarButton;
  AItemLink: TdxBarItemLink;
begin
  if Assigned(AButton.Item) then
  begin
    AItem := TdxRibbonBackstageViewMenuBarButton(BarManager.AddItem(TdxRibbonBackstageViewMenuBarButton));
    BarDesignController.AddInternalItem(AItem, MenuButtonList);
    AItem.MenuButton := AButton;
    AItemLink := ItemLinks.Add;
    AItemLink.Item := AItem;
    AItemLink.BeginGroup := AButton.BeginGroup and (ItemLinks.Count > 1);
  end;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.AddTabButton(ATab: TdxRibbonBackstageViewTabSheet);
var
  ATabButton: TdxRibbonBackstageViewTabSheetButton;
begin
  if ATab.TabVisible then
  begin
    ATabButton := TdxRibbonBackstageViewTabSheetButton(BarManager.AddItem(TdxRibbonBackstageViewTabSheetButton));
    BarDesignController.AddInternalItem(ATabButton, TabButtonList);
    ATabButton.Tab := ATab;
    ItemLinks.Add.Item := ATabButton;
  end;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.Calculate(const ABounds: TRect);
begin
  inherited Calculate(ABounds);
  DockControl.BoundsRect := ABounds;
  DockControl.UpdateDock;
  if BarControl <> nil then
  begin
    BarControl.CalcLayout;
    BarControl.Invalidate;
  end;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.CalculateSizes;
begin
  if Assigned(BarControl) and IsBarManagerValid then
  begin
    BarControl.HandleNeeded;
    BarControl.CreateControls;
    FMinWidth := BarControl.GetMaxWidth(dsLeft);
    FMinHeight := BarControl.GetMaxHeight(dsLeft);
  end
  else
  begin
    FMinHeight := 0;
    FMinWidth := 0;
  end;
end;

function TdxRibbonBackstageViewMenuViewInfo.CanContainItem(
  AItem: TdxBarItem; out AErrorText: string): Boolean;
begin
  Result := True;
end;

function TdxRibbonBackstageViewMenuViewInfo.CreateItemLinksBarControl: TCustomdxBarControl;
begin
  Result := TdxRibbonBackstageViewMenuBarControl.Create(BarManager);
end;

function TdxRibbonBackstageViewMenuViewInfo.CreatePainter(AData: TdxNativeUInt): TdxRibbonBackstageViewMenuPainter;
begin
  Result := TdxRibbonBackstageViewMenuPainter.Create(AData);
end;

procedure TdxRibbonBackstageViewMenuViewInfo.CreateBarControl;
begin
  if Assigned(BarManager) then
  begin
    ItemLinks.CreateBarControl;
    BarControl.DockControl := DockControl;
    BarControl.DockingStyle := dsLeft;
    BarControl.Parent := DockControl;
    BarControl.Visible := True;
  end;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.CreateViewInfoItems;

  function GetPainterData: TdxNativeUInt;
  begin
    if IsBarManagerValid then
      Result := TdxNativeUInt(Ribbon)
    else
      Result := 0;
  end;

begin
  FPainter := CreatePainter(GetPainterData);
  FItemLinks := TdxBarControlItemLinks.Create(BarManager, Self);
  DockControl.BarManager := BarManager;
  CreateBarControl;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.DestroyViewInfoItems;
begin
  DockControl.BarManager := nil;
  FreeAndNil(FItemLinks);
  FreeAndNil(FPainter);
end;

function TdxRibbonBackstageViewMenuViewInfo.GetAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  if Assigned(ItemLinks) then
    Result := ItemLinks.BarControl.IAccessibilityHelper
  else
    Result := nil;
end;

function TdxRibbonBackstageViewMenuViewInfo.GetImages: TCustomImagelist;
begin
  Result := nil;
end;

function TdxRibbonBackstageViewMenuViewInfo.GetInstance: TComponent;
begin
  Result := BackstageView;
end;

function TdxRibbonBackstageViewMenuViewInfo.GetItemLinks: TdxBarItemLinks;
begin
  Result := ItemLinks;
end;

function TdxRibbonBackstageViewMenuViewInfo.GetBarControl: TdxRibbonBackstageViewMenuBarControl;
begin
  Result := TdxRibbonBackstageViewMenuBarControl(ItemLinks.BarControl);
end;

function TdxRibbonBackstageViewMenuViewInfo.GetIsDesigning: Boolean;
begin
  Result := BackstageView.IsDesigning;
end;

function TdxRibbonBackstageViewMenuViewInfo.GetRibbon: TdxCustomRibbon;
begin
  Result := BackstageView.Ribbon;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.ClearInternalLists;
begin
  if ItemLinks <> nil then
    ItemLinks.Clear;
  TabButtonList.Clear;
  MenuButtonList.Clear;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.InitiateActions;
begin
  if ItemLinks <> nil then
    TdxBarItemLinksAccess(ItemLinks).InitiateActions;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.RecreateItemLinks;

  function CanCreateItemLinks: Boolean;
  begin
    Result := IsBarManagerValid and BackstageView.HandleAllocated;
  end;

  procedure DoAddButtons(APosition: TdxRibbonBackstageViewMenuButtonPosition);
  var
    AButton: TdxRibbonBackstageViewMenuButton;
    I: Integer;
  begin
    for I := 0 to BackstageView.Buttons.Count - 1 do
    begin
      AButton := BackstageView.Buttons[I];
      if AButton.Position = APosition then
        AddButton(AButton);
    end;
  end;

var
  I: Integer;
begin
  if CanCreateItemLinks then
  begin
    BarManager.BeginUpdate;
    try
      ItemLinks.BeginUpdate;
      try
        ClearInternalLists;
        DoAddButtons(mbpBeforeTabs);
        for I := 0 to BackstageView.TabCount - 1 do
          AddTabButton(BackstageView.Tabs[I]);
        DoAddButtons(mbpAfterTabs);
      finally
        ItemLinks.EndUpdate;
      end;
    finally
      BarManager.EndUpdate;
    end;
  end
  else
    ClearInternalLists;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.RefreshMenuButtonsInfo;
begin
  MenuButtonList.RefreshInfo;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.RefreshTabsInfo;
begin
  TabButtonList.RefreshInfo;
end;

procedure TdxRibbonBackstageViewMenuViewInfo.UpdateFont;
begin
  if BarControl <> nil then
    BarControl.UpdateFont;
end;

{ TdxRibbonBackstageViewDesignSelector }

function TdxRibbonBackstageViewDesignSelector.GetSelected: Boolean;
begin
  Result := (Owner as TdxRibbonCustomBackstageView).IsPersistentSelected(Owner);
end;

{ TdxRibbonBackstageViewViewInfo }

constructor TdxRibbonBackstageViewViewInfo.Create(ABackstageView: TdxRibbonCustomBackstageView);
begin
  inherited Create(ABackstageView);
  FMenuViewInfo := CreateMenuViewInfo;
end;

destructor TdxRibbonBackstageViewViewInfo.Destroy;
begin
  FreeAndNil(FMenuViewInfo);
  inherited Destroy;
end;

procedure TdxRibbonBackstageViewViewInfo.Calculate(const ABounds: TRect);
begin
  inherited Calculate(ABounds);
  MenuViewInfo.CalculateSizes;
  FContentWidth := Max(CalculateMinWidth, cxRectWidth(Bounds));
  FContentHeight := Max(CalculateMinHeight, cxRectHeight(Bounds));
  CheckScrollPosition(FScrollPositionX, ContentWidth, cxRectWidth(Bounds));
  CheckScrollPosition(FScrollPositionY, ContentHeight, cxRectHeight(Bounds));
  FFrameAreaBounds := CalculateFrameBounds;
  MenuViewInfo.Calculate(CalculateMenuBounds);
end;

function TdxRibbonBackstageViewViewInfo.CalculateFrameBounds: TRect;
begin
  Result := ContentBounds;
  Result.Left := CalculateMenuBounds.Right;
end;

function TdxRibbonBackstageViewViewInfo.CalculateMenuBounds: TRect;
begin
  Result := cxRectSetWidth(ContentBounds, MenuViewInfo.MinWidth);
  Result.Bottom := Bounds.Bottom;
end;

function TdxRibbonBackstageViewViewInfo.CalculateMinHeight: Integer;
begin
  Result := MenuViewInfo.MinHeight;
  if Assigned(ActiveTab) then
    Result := Max(Result, ActiveTab.ViewInfo.MinHeight);
end;

function TdxRibbonBackstageViewViewInfo.CalculateMinWidth: Integer;
begin
  Result := MenuViewInfo.MinWidth;
  if Assigned(ActiveTab) then
    Inc(Result, ActiveTab.ViewInfo.MinWidth);
end;

procedure TdxRibbonBackstageViewViewInfo.CheckScrollPosition(
  var AValue: Integer; AContentSize, ADisplaySize: Integer);
begin
  AValue := Max(0, Min(AValue, AContentSize - ADisplaySize));
end;

function TdxRibbonBackstageViewViewInfo.CreateMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
begin
  Result := TdxRibbonBackstageViewMenuViewInfo.Create(BackstageView);
end;

procedure TdxRibbonBackstageViewViewInfo.DeactivateControls;
begin
  if MenuBarControl <> nil then
    MenuBarControl.IsActive := False;
end;

function TdxRibbonBackstageViewViewInfo.ProcessMouseWheel(ALineDown: Boolean): Boolean;
const
  Signs: array[Boolean] of Integer = (-1, 1);
begin
  Result := ContentHeight > cxRectHeight(Bounds);
  if Result then
    ScrollPositionY := ScrollPositionY + Signs[ALineDown] *
      Mouse.WheelScrollLines * dxBackstageViewScrollLineSize;
end;

function TdxRibbonBackstageViewViewInfo.GetActiveTab: TdxRibbonBackstageViewTabSheet;
begin
  Result := BackstageView.ActiveTab;
end;

function TdxRibbonBackstageViewViewInfo.GetActiveTabItemControl: TdxBarItemControl;
var
  AItem: TdxRibbonBackstageViewTabSheetButton;
begin
  AItem := MenuViewInfo.TabButtonList.GetItemByTab(ActiveTab);
  if (AItem <> nil) and (AItem.LinkCount > 0) and (AItem.Links[0].Control <> nil) then
    Result := AItem.Links[0].Control
  else
    Result := nil;
end;

function TdxRibbonBackstageViewViewInfo.GetContentBounds: TRect;
begin
  Result := Classes.Bounds(Bounds.Left - ScrollPositionX,
    Bounds.Top - ScrollPositionY, ContentWidth, ContentHeight);
end;

function TdxRibbonBackstageViewViewInfo.GetDesignSelectorRect: TRect;
begin
  Result := cxRectInflate(Bounds,
    -cxDesignSelectorIndentFromBorder,
    -cxDesignSelectorIndentFromBorder);
  Result.Left := Result.Right - cxDesignSelectorSize;
  Result.Top := Result.Bottom - cxDesignSelectorSize;
  if IsRectEmpty(Result) then
    Result := cxEmptyRect;
end;

function TdxRibbonBackstageViewViewInfo.GetFrameAreaVisibleBounds: TRect;
begin
  Result := Bounds;
  Result.Left := CalculateMenuBounds.Right;
end;

function TdxRibbonBackstageViewViewInfo.GetMenuBarControl: TdxBarControl;
begin
  Result := MenuViewInfo.BarControl;
end;

procedure TdxRibbonBackstageViewViewInfo.SetScrollPositionX(AValue: Integer);
begin
  CheckScrollPosition(AValue, ContentWidth, cxRectWidth(Bounds));
  if FScrollPositionX <> AValue then
  begin
    FScrollPositionX := AValue;
    BackstageView.Changed;
  end;
end;

procedure TdxRibbonBackstageViewViewInfo.SetScrollPositionY(AValue: Integer);
begin
  CheckScrollPosition(AValue, ContentHeight, cxRectHeight(Bounds));
  if FScrollPositionY <> AValue then
  begin
    FScrollPositionY := AValue;
    BackstageView.Changed;
  end;
end;

{ TdxRibbonBackstageViewMenuBarButton }

procedure TdxRibbonBackstageViewMenuBarButton.DirectClick;
var
  ABackstageView: TdxRibbonCustomBackstageView;
begin
  if Enabled and (MenuButton <> nil) then
  begin
    ABackstageView := MenuButton.Collection.BackstageView;
    ABackstageView.ClosePopup;
    ABackstageView.MenuHelper.PostClick(MenuButton);
  end;
end;

procedure TdxRibbonBackstageViewMenuBarButton.RefreshInfo;
begin
  if MenuButton <> nil then
    Assign(MenuButton.Item);
end;

function TdxRibbonBackstageViewMenuBarButton.GetControlClass(
  AIsVertical: Boolean): TdxBarItemControlClass;
begin
  Result := TdxRibbonBackstageViewMenuBarButtonControl;
end;

procedure TdxRibbonBackstageViewMenuBarButton.SetMenuButton(AValue: TdxRibbonBackstageViewMenuButton);
begin
  if FMenuButton <> AValue then
  begin
    FMenuButton := AValue;
    RefreshInfo;
  end;
end;

{ TdxRibbonBackstageViewMenuBarButtonControl }

function TdxRibbonBackstageViewMenuBarButtonControl.CanCustomize: Boolean;
begin
  Result := False;
end;

procedure TdxRibbonBackstageViewMenuBarButtonControl.CalcDrawParams(AFull: Boolean = True);
begin
  inherited CalcDrawParams(AFull);
  DrawParams.ContentOffset := MenuPainter.MenuBarButtonContentOffset;
end;

procedure TdxRibbonBackstageViewMenuBarButtonControl.DoPaint(ARect: TRect; PaintType: TdxBarPaintType);
begin
  if IsTabButtonStyle then
    MenuPainter.DrawTabButton(DrawParams, ARect)
  else
    inherited DoPaint(ARect, PaintType);

  if BackstageView.IsPersistentSelected(Item.MenuButton) then
    dxBarFocusRect(Canvas.Handle, ARect);
end;

function TdxRibbonBackstageViewMenuBarButtonControl.GetBackstageView: TdxRibbonCustomBackstageView;
begin
  Result := Item.MenuButton.Collection.BackstageView;
end;

function TdxRibbonBackstageViewMenuBarButtonControl.GetDefaultHeight: Integer;
begin
  Result := Max(inherited GetDefaultHeight, MenuPainter.MenuBarDefaultItemHeight);
end;

function TdxRibbonBackstageViewMenuBarButtonControl.GetItem: TdxRibbonBackstageViewMenuBarButton;
begin
  Result := TdxRibbonBackstageViewMenuBarButton(inherited Item);
end;

function TdxRibbonBackstageViewMenuBarButtonControl.GetKeyTipBasePoint: TPoint;
begin
  Result := MenuPainter.MenuBarButtonContentOffset.TopLeft;
  if not IsTabButtonStyle then
    Result := cxPointOffset(Result, GetGlyphAreaWidth - 2 * cxTextSpace, 0);
end;

function TdxRibbonBackstageViewMenuBarButtonControl.GetMenuPainter: TdxRibbonBackstageViewMenuPainter;
begin
  Result := BackstageView.MenuViewInfo.Painter;
end;

function TdxRibbonBackstageViewMenuBarButtonControl.GetViewStructure: TdxBarItemControlViewStructure;
begin
  Result := [cpIcon, cpText];
end;

function TdxRibbonBackstageViewMenuBarButtonControl.HasImage: Boolean;
begin
  Result := (Glyph <> nil) and not Glyph.Empty or (ImageIndex >= 0) and (Images <> nil);
end;

function TdxRibbonBackstageViewMenuBarButtonControl.IsTabButtonStyle: Boolean;
begin
  Result := (BackstageView.Ribbon <> nil) and (BackstageView.Ribbon.Style = rs2013) and not HasImage;
end;

{ TdxRibbonBackstageViewMenuButton }

destructor TdxRibbonBackstageViewMenuButton.Destroy;
begin
  Item := nil;
  inherited Destroy;
end;

procedure TdxRibbonBackstageViewMenuButton.Assign(Source: TPersistent);
begin
  if Source is TdxRibbonBackstageViewMenuButton then
  begin
    Item := TdxRibbonBackstageViewMenuButton(Source).Item;
    Position := TdxRibbonBackstageViewMenuButton(Source).Position;
    BeginGroup := TdxRibbonBackstageViewMenuButton(Source).BeginGroup;
  end
  else
    inherited Assign(Source);
end;

procedure TdxRibbonBackstageViewMenuButton.BarComponentChanged(AComponent: TdxBarComponent);
begin
  Changed(AComponent = nil);
end;

procedure TdxRibbonBackstageViewMenuButton.SelectionChanged;
begin
  Collection.BackstageView.InvalidateWithChildren;
end;

procedure TdxRibbonBackstageViewMenuButton.Notification(AComponent: TComponent; Operation: TOperation);
begin
  if (AComponent = FItem) and (Operation = opRemove) then
  begin
    BarDesignController.LockDesignerModified;
    try
      FItem := nil;
      Changed(True);
    finally
      BarDesignController.UnLockDesignerModified;
    end;
  end;
end;

function TdxRibbonBackstageViewMenuButton.GetCollection: TdxRibbonBackstageViewMenuButtons;
begin
  Result := TdxRibbonBackstageViewMenuButtons(inherited Collection);
end;

procedure TdxRibbonBackstageViewMenuButton.SetBeginGroup(AValue: Boolean);
begin
  if FBeginGroup <> AValue then
  begin
    FBeginGroup := AValue;
    Changed(True);
  end;
end;

procedure TdxRibbonBackstageViewMenuButton.SetItem(AValue: TdxBarButton);
begin
  if AValue <> Item then
  begin
    if Item <> nil then
    begin
      TdxBarButtonAccess(Item).RemoveChangeNotify(Self);
      Item.RemoveFreeNotification(Collection.BackstageView);
    end;
    FItem := AValue;
    if Item <> nil then
    begin
      Item.FreeNotification(Collection.BackstageView);
      TdxBarButtonAccess(Item).AddChangeNotify(Self);
    end;
    Changed(True);
  end;
end;

procedure TdxRibbonBackstageViewMenuButton.SetPosition(
  AValue: TdxRibbonBackstageViewMenuButtonPosition);
begin
  if AValue <> FPosition then
  begin
    FPosition := AValue;
    Changed(True);
  end;
end;

{ TdxRibbonBackstageViewMenuButtons }

constructor TdxRibbonBackstageViewMenuButtons.Create(ABackstageView: TdxRibbonCustomBackstageView);
begin
  inherited Create(TdxRibbonBackstageViewMenuButton);
  FBackstageView := ABackstageView
end;

function TdxRibbonBackstageViewMenuButtons.Add: TdxRibbonBackstageViewMenuButton;
begin
  Result := TdxRibbonBackstageViewMenuButton(inherited Add);
end;

function TdxRibbonBackstageViewMenuButtons.IndexOf(AItem: TdxRibbonBackstageViewMenuButton): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := 0 to Count - 1 do
    if Items[I] = AItem then
    begin
      Result := I;
      Break;
    end;
end;

function TdxRibbonBackstageViewMenuButtons.Insert(AIndex: Integer): TdxRibbonBackstageViewMenuButton;
begin
  Result := TdxRibbonBackstageViewMenuButton(inherited Insert(AIndex));
end;

function TdxRibbonBackstageViewMenuButtons.GetOwner: TPersistent;
begin
  Result := BackstageView;
end;

procedure TdxRibbonBackstageViewMenuButtons.Update(Item: TCollectionItem);
begin
  inherited Update(Item);
  if Item = nil then
    BackstageView.Changed([rbvcStruct])
  else
    BackstageView.Changed([rbvcItemsData]);
end;

procedure TdxRibbonBackstageViewMenuButtons.Notification(AComponent: TComponent; Operation: TOperation);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].Notification(AComponent, Operation);
end;

function TdxRibbonBackstageViewMenuButtons.GetItem(Index: Integer): TdxRibbonBackstageViewMenuButton;
begin
  Result := TdxRibbonBackstageViewMenuButton(inherited GetItem(Index));
end;

procedure TdxRibbonBackstageViewMenuButtons.SetItem(
  Index: Integer; Value: TdxRibbonBackstageViewMenuButton);
begin
  inherited SetItem(Index, Value);
end;

{ TdxRibbonBackstageViewMenuHelper }

constructor TdxRibbonBackstageViewMenuHelper.Create(ABackstageView: TdxRibbonCustomBackstageView);
begin
  inherited Create;
  FBackstageView := ABackstageView;
end;

procedure TdxRibbonBackstageViewMenuHelper.PostClick(AButton: TdxRibbonBackstageViewMenuButton);
begin
  PostMessage(Handle, DXM_BAR_FASTCOMMAND, 0, LPARAM(AButton));
end;

procedure TdxRibbonBackstageViewMenuHelper.PostShowRibbonKeyTips;
begin
  PostMessage(Handle, DXM_BAR_SHOWKEYTIPS, 0, 0);
end;

procedure TdxRibbonBackstageViewMenuHelper.WndProc(var Message: TMessage);
var
  AMenuButton: TdxRibbonBackstageViewMenuButton;
begin
  case Message.Msg of
    DXM_BAR_SHOWKEYTIPS:
      BarNavigationController.SetKeyTipsShowingState(BackstageView.Ribbon.IAccessibilityHelper, '');
    DXM_BAR_FASTCOMMAND:
      begin
        AMenuButton := TdxRibbonBackstageViewMenuButton(Message.LParam);
        if BackstageView.Buttons.IndexOf(AMenuButton) >= 0 then
        begin
          if AMenuButton.Item <> nil then
            TdxBarButtonAccess(AMenuButton.Item).DirectClick;
        end;
      end
  end;
  inherited WndProc(Message);
end;

{ TdxRibbonBackstageViewApplicationMenuHelper }

constructor TdxRibbonBackstageViewApplicationMenuHelper.Create(
  ABackstageView: TdxRibbonCustomBackstageView);
begin
  inherited Create;
  FLinkToBackstageView := cxAddObjectLink(ABackstageView);
end;

destructor TdxRibbonBackstageViewApplicationMenuHelper.Destroy;
begin
  cxRemoveObjectLink(FLinkToBackstageView);
  inherited Destroy;
end;

function TdxRibbonBackstageViewApplicationMenuHelper.CanShowPopup(ARibbon: TdxCustomRibbon): Boolean;
begin
  Result := BackstageView.CanShowPopup(ARibbon);
end;

function TdxRibbonBackstageViewApplicationMenuHelper.ClosePopup: Boolean;
begin
  Result := BackstageView <> nil;
  if Result then
    BackstageView.ClosePopup;
end;

function TdxRibbonBackstageViewApplicationMenuHelper.GetDisplayMode: TdxRibbonApplicationMenuDisplayMode;
begin
  Result := BackstageView.NonClientViewInfo.DisplayMode;
end;

function TdxRibbonBackstageViewApplicationMenuHelper.Popup(
  ARibbon: TdxCustomRibbon; var AClosedByEscape: Boolean): Boolean;
begin
  Result := BackstageView.Popup(ARibbon, AClosedByEscape);
end;

procedure TdxRibbonBackstageViewApplicationMenuHelper.RibbonFormResized;
begin
  BackstageView.CalculatePlace;
end;

procedure TdxRibbonBackstageViewApplicationMenuHelper.SelectAppMenuFirstItemControl;
begin
  BarNavigationController.ChangeSelectedObject(False,
    BackstageView.MenuViewInfo.AccessibilityHelper.GetBarHelper.GetFirstSelectableObject);
end;

procedure TdxRibbonBackstageViewApplicationMenuHelper.ShowKeyTips;
begin
  BarNavigationController.SetKeyTipsShowingState(BackstageView.MenuViewInfo.AccessibilityHelper, '');
  SelectAppMenuFirstItemControl;
end;

procedure TdxRibbonBackstageViewApplicationMenuHelper.UpdateNonClientArea;
begin
  BackstageView.FullInvalidate;
  BackstageView.Update;
end;

function TdxRibbonBackstageViewApplicationMenuHelper.GetBackstageView: TdxRibbonCustomBackstageView;
begin
  Result := TdxRibbonCustomBackstageView(FLinkToBackstageView.Ref);
end;

function TdxRibbonBackstageViewApplicationMenuHelper.GetOrigin(AIsClientArea: Boolean): TPoint;
begin
  Result := cxNullPoint;
end;

function TdxRibbonBackstageViewApplicationMenuHelper.GetRootAccessibilityHelper: IdxBarAccessibilityHelper;
begin
  if Assigned(BackstageView.MenuViewInfo.BarControl) then
    Result := BackstageView.MenuViewInfo.BarControl.IAccessibilityHelper
  else
    Result := nil;
end;

procedure TdxRibbonBackstageViewApplicationMenuHelper.GetTabOrderList(AList: TList);
begin
  BackstageView.GetTabOrderList(AList);
  if AList.IndexOf(BackstageView) < 0 then
    AList.Add(BackstageView);
end;

{ TdxRibbonBackstageViewCustomButtonViewInfo }

function TdxRibbonBackstageViewCustomButtonViewInfo.GetState: TcxButtonState;
begin
  if Self <> BackstageView.NonClientController.HoveredCell then
    Result := cxbsNormal
  else
    if Self <> BackstageView.NonClientController.PressedCell then
      Result := cxbsHot
    else
      Result := cxbsPressed;
end;

{ TdxRibbonBackstageViewBackButtonViewInfo }

procedure TdxRibbonBackstageViewBackButtonViewInfo.Click;
begin
  BackstageView.ClosePopup;
end;

procedure TdxRibbonBackstageViewBackButtonViewInfo.Draw(ACanvas: TcxCanvas);
begin
  BackstageView.Painter.DrawBackButton(ACanvas, Bounds, State);
end;

function TdxRibbonBackstageViewBackButtonViewInfo.GetMeasureSize: TSize;
begin
  Result := BackstageView.Painter.BackButtonSize;
end;

{ TdxRibbonBackstageViewNonClientViewInfo }

constructor TdxRibbonBackstageViewNonClientViewInfo.Create(ABackstageView: TdxRibbonCustomBackstageView);
begin
  inherited Create(ABackstageView);
  FBackButtonViewInfo := CreateBackButtonViewInfo;
end;

destructor TdxRibbonBackstageViewNonClientViewInfo.Destroy;
begin
  FreeAndNil(FBackButtonViewInfo);
  inherited Destroy;
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.Calculate(const ABounds: TRect);
begin
  inherited Calculate(ABounds);
  CalculateCaptionArea;
  CalculateMenuBarHeader;
  CalculateBackButton;
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.CalculateBackButton;
var
  R: TRect;
begin
  R := cxRectSetBottom(Bounds, TabsArea.Bottom, BackButtonViewInfo.MeasureSize.cy);
  R := cxRectSetWidth(R, BackButtonViewInfo.MeasureSize.cx);
  R := cxRectOffset(R, MenuViewInfo.Painter.TabButtonContentOffset.Left, 0);
  BackButtonViewInfo.Calculate(R);
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.CalculateCaptionArea;
var
  AOffset: TPoint;
begin
  if DisplayMode = amdmFrameFullScreen then
  begin
    AOffset := dxMapWindowPoint(Ribbon.Handle, BackstageView.Handle, cxNullPoint, False);
    FBorderIconsArea := cxRectOffset(RibbonFormCaptionHelper.BorderIconsArea, AOffset);
    FCaptionArea := cxRectOffset(RibbonFormCaptionHelper.FormCaptionDrawBounds, AOffset);
    FCaptionTextRect := FCaptionArea;
    FCaptionTextRect.Right := BorderIconsArea.Left;
    FCaptionTextRect.Left := Max(FCaptionTextRect.Left, Bounds.Left +
      BackstageView.ViewInfo.MenuViewInfo.MinWidth + dxRibbonFormCaptionTextSpace);
    FTabsArea := cxRectOffset(Ribbon.ViewInfo.TabsAreaBounds, AOffset);
    if TabsArea.Bottom <= TabsArea.Top then
      FTabsArea.Bottom := TabsArea.Top + cxRectHeight(CaptionArea);
  end
  else
  begin
    FTabsArea := cxRectSetHeight(Bounds, 0);
    FCaptionArea := TabsArea;
    FCaptionTextRect := FCaptionArea;
    FBorderIconsArea := cxNullRect;
  end;
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.CalculateMenuBarHeader;
begin
  FMenuBarHeaderRect := cxRectOffset(MenuViewInfo.Bounds, ClientOffsets.TopLeft);
  FMenuBarHeaderRect.Top := Bounds.Top;
  FMenuBarHeaderRect.Bottom := TabsArea.Bottom;
end;

function TdxRibbonBackstageViewNonClientViewInfo.CreateBackButtonViewInfo: TdxRibbonBackstageViewBackButtonViewInfo;
begin
  Result := TdxRibbonBackstageViewBackButtonViewInfo.Create(BackstageView);
end;

function TdxRibbonBackstageViewNonClientViewInfo.CreateWindowRegion: TcxRegionHandle;
var
  ARegion: TcxRegionHandle;
begin
  Result := 0;
  if DisplayMode = amdmFrameFullScreen then
  begin
    if not cxRectIsEmpty(BorderIconsArea) then
    begin
      Result := CreateRectRgnIndirect(Bounds);
      ARegion := CreateRectRgnIndirect(BorderIconsArea);
      CombineRgn(Result, Result, ARegion, RGN_DIFF);
      DeleteObject(ARegion);
    end;
  end;
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.Draw(ACanvas: TcxCanvas);
begin
  DrawBackground(ACanvas);
  DrawCaptionArea(ACanvas);
  DrawMenuBarHeader(ACanvas);
  BackButtonViewInfo.Draw(ACanvas);
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.DrawCaptionArea(ACanvas: TcxCanvas);
var
  R: TRect;
begin
  if DisplayMode = amdmFrameFullScreen then
  begin
    R := CaptionTextRect;
    ACanvas.Font := Ribbon.ViewInfo.GetFormCaptionFont(RibbonFormCaptionHelper.FormData.Active);
    ACanvas.Font.Color := Ribbon.ColorScheme.GetPartColor(DXBAR_BACKSTAGEVIEW_TEXTCOLOR);
    cxTextOut(ACanvas.Handle, Ribbon.ViewInfo.DocumentName + Ribbon.ViewInfo.Caption, R,
      CXTO_PREVENT_LEFT_EXCEED or CXTO_CENTER_HORIZONTALLY or CXTO_CENTER_VERTICALLY or
      CXTO_SINGLELINE or CXTO_END_ELLIPSIS);
  end;
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.DrawBackground(ACanvas: TcxCanvas);
begin
  Painter.DrawBackground(ACanvas, Bounds);
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.DrawMenuBarHeader(ACanvas: TcxCanvas);
begin
  if ACanvas.RectVisible(MenuBarHeaderRect) then
  begin
    if cxRectPtIn(ContentRect, MenuBarHeaderRect.TopLeft) and
       cxRectPtIn(ContentRect, MenuBarHeaderRect.BottomRight)
    then
      Painter.DrawMenuBarHeader(ACanvas, MenuBarHeaderRect)
    else
    begin
      ACanvas.SaveClipRegion;
      try
        ACanvas.IntersectClipRect(ContentRect);
        Painter.DrawMenuBarHeader(ACanvas, MenuBarHeaderRect);
      finally
        ACanvas.RestoreClipRegion;
      end;
    end;
  end;
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetClientOffsets: TRect;
begin
  Result := Painter.ContentOffsets;
  Inc(Result.Top, TabsArea.Bottom);
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetClientRect: TRect;
begin
  Result := cxRectContent(Bounds, ClientOffsets);
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetContentRect: TRect;
begin
  Result := cxRectContent(Bounds, Painter.ContentOffsets);
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetDisplayMode: TdxRibbonApplicationMenuDisplayMode;
begin
  if (RibbonFormCaptionHelper <> nil) and (Ribbon.Style = rs2013) and
    not UseAeroNCPaint(RibbonFormCaptionHelper.FormData) and not BackstageView.IsDesigning
  then
    Result := amdmFrameFullScreen
  else
    Result := amdmFrame;
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetHasNonClientArea: Boolean;
begin
  Result := not cxRectIsEqual(ClientOffsets, cxNullRect);
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
begin
  Result := BackstageView.MenuViewInfo;
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetRibbon: TdxCustomRibbon;
begin
  Result := BackstageView.Ribbon;
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetRibbonFormCaptionHelper: TdxRibbonFormCaptionHelper;
begin
  if Ribbon <> nil then
    Result := TdxCustonRibbonAccess(Ribbon).FormCaptionHelper
  else
    Result := nil;
end;

procedure TdxRibbonBackstageViewNonClientViewInfo.Recalculate;
begin
  Calculate(Bounds);
end;

function TdxRibbonBackstageViewNonClientViewInfo.GetPainter: TdxRibbonBackstageViewPainter;
begin
  Result := BackstageView.Painter;
end;

{ TdxRibbonBackstageViewNonClientController }

destructor TdxRibbonBackstageViewNonClientController.Destroy;
begin
  EndMouseTracking(Self);
  inherited Destroy;
end;

function TdxRibbonBackstageViewNonClientController.HitTest(const P: TPoint): TdxRibbonBackstageViewCustomButtonViewInfo;
begin
  if PtInRect(ViewInfo.BackButtonViewInfo.Bounds, P) then
    Result := ViewInfo.BackButtonViewInfo
  else
    Result := nil;
end;

procedure TdxRibbonBackstageViewNonClientController.MouseDown(AButton: TMouseButton; const P: TPoint);
begin
  PressedCell := HitTest(P);
end;

procedure TdxRibbonBackstageViewNonClientController.MouseLeave;
begin
  HoveredCell := nil;
end;

procedure TdxRibbonBackstageViewNonClientController.MouseMove(const P: TPoint);
begin
  if PressedCell <> nil then
  begin
    if not (ssLeft in KeyboardStateToShiftState) then
      PressedCell := nil;
  end;
  BeginMouseTracking(nil, cxNullRect, Self);
  HoveredCell := HitTest(P);
end;

procedure TdxRibbonBackstageViewNonClientController.MouseUp(AButton: TMouseButton; const P: TPoint);
var
  ALastPressedCell: TdxRibbonBackstageViewCustomButtonViewInfo;
begin
  if PressedCell <> nil then
  begin
    ALastPressedCell := PressedCell;
    PressedCell := nil;
    if ALastPressedCell = HoveredCell then
      ALastPressedCell.Click;
  end;
end;

procedure TdxRibbonBackstageViewNonClientController.ProcessMessage(var AMessage: TMessage);

  function DoScreenToLocal(const AMessage: TWMNCHitMessage): TPoint;
  begin
    Result := ScreenToLocal(Point(AMessage.XCursor, AMessage.YCursor));
  end;

var
  P: TPoint;
begin
  case AMessage.Msg of
    WM_NCLBUTTONDOWN:
      MouseDown(mbLeft, DoScreenToLocal(TWMNCLButtonDown(AMessage)));
    WM_NCMOUSEMOVE:
      MouseMove(DoScreenToLocal(TWMNCMouseMove(AMessage)));
    WM_NCLBUTTONUP:
      MouseUp(mbLeft, DoScreenToLocal(TWMNCLButtonUp(AMessage)));
    WM_NCHITTEST:
      begin
        P := ScreenToLocal(TWMNCHitTest(AMessage).Pos);
        if HitTest(P) <> nil then
          AMessage.Result := HTOBJECT
        else
          if PtInRect(ViewInfo.CaptionTextRect, P) then
            AMessage.Result := HTTRANSPARENT;
      end;
  end;
end;

function TdxRibbonBackstageViewNonClientController.PtInCaller(const P: TPoint): Boolean;
begin
  Result := HitTest(ScreenToLocal(P)) <> nil;
end;

procedure TdxRibbonBackstageViewNonClientController.RefreshState;
begin
  RedrawWindow(BackstageView.Handle, nil, 0, RDW_FRAME or RDW_INVALIDATE);
end;

function TdxRibbonBackstageViewNonClientController.ScreenToLocal(const P: TPoint): TPoint;
begin
  Result := cxPointOffset(P, cxGetWindowRect(BackstageView).TopLeft, False);;
end;

function TdxRibbonBackstageViewNonClientController.ScreenToLocal(const P: TSmallPoint): TPoint;
begin
  Result := ScreenToLocal(SmallPointToPoint(P));
end;

procedure TdxRibbonBackstageViewNonClientController.SetHoveredCell(
  AValue: TdxRibbonBackstageViewCustomButtonViewInfo);
begin
  if FHoveredCell <> AValue then
  begin
    FHoveredCell := AValue;
    RefreshState;
  end;
end;

procedure TdxRibbonBackstageViewNonClientController.SetPressedCell(
  AValue: TdxRibbonBackstageViewCustomButtonViewInfo);
begin
  if FPressedCell <> AValue then
  begin
    FPressedCell := AValue;
    RefreshState;
  end;
end;

function TdxRibbonBackstageViewNonClientController.GetViewInfo: TdxRibbonBackstageViewNonClientViewInfo;
begin
  Result := BackstageView.NonClientViewInfo;
end;

{ TdxRibbonBackstageViewAnimationTransition }

constructor TdxRibbonBackstageViewAnimationTransition.Create(
  ABackstageView: TdxRibbonCustomBackstageView;
  AMode: TdxRibbonBackstageViewAnimationTransitionMode);
begin
  FMode := AMode;
  FBackstageView := ABackstageView;
  inherited Create(dxRibbonBackstageViewMenuScrollAnimationTime, ateAccelerateDecelerate, MenuViewInfo.MinWidth);
  FActiveTabIsSolidBackground := True; 
  Initalize;
end;

destructor TdxRibbonBackstageViewAnimationTransition.Destroy;
begin
  Finalize;
  inherited Destroy;
end;

function TdxRibbonBackstageViewAnimationTransition.CalculateContentAlpha: Byte;
begin
  Result := MulDiv(Position, MaxByte, Length);
  if Mode = bvatmHide then
    Result := MaxByte - Result;
end;

procedure TdxRibbonBackstageViewAnimationTransition.CalculateViewInfos;
var
  AOffset: Integer;
begin
  if Mode = bvatmShow then
    AOffset := -MenuViewInfo.MinWidth + Position
  else
    AOffset := -Position;

  MenuViewInfo.Calculate(cxRectOffset(ViewInfo.CalculateMenuBounds, AOffset, 0));
  NonClientViewInfo.Recalculate;
  NonClientViewInfo.BackButtonViewInfo.Calculate(
    cxRectOffset(NonClientViewInfo.BackButtonViewInfo.Bounds, AOffset, 0));

  if ActiveTab <> nil then
    ActiveTab.Calculate(cxRectOffset(ViewInfo.FrameAreaBounds, AOffset, 0));
end;

procedure TdxRibbonBackstageViewAnimationTransition.DoAnimate;
var
  DC: HDC;
begin
  CalculateViewInfos;
  PrepareBackstageViewBuffer(BackstageViewBuffer.cxCanvas);
  DC := GetDCEx(BackstageView.Handle, 0, DCX_CACHE or DCX_WINDOW or DCX_LOCKWINDOWUPDATE);
  try
    cxBitBlt(DC, BackstageViewBuffer.Canvas.Handle, BackstageViewRect, cxNullPoint, SRCCOPY);
  finally
    ReleaseDC(BackstageView.Handle, DC);
  end;
end;

procedure TdxRibbonBackstageViewAnimationTransition.Finalize;
begin
  FreeAndNil(FBackstageViewMenuBuffer);
  FreeAndNil(FBackstageViewBuffer);
  FreeAndNil(FActiveTabBuffer);
  if Mode = bvatmShow then
  begin
    if ActiveTab <> nil then
      ActiveTab.Visible := True;
  end;
end;

procedure TdxRibbonBackstageViewAnimationTransition.Initalize;
begin
  if ActiveTab <> nil then
    ActiveTab.Visible := False;
  UpdateWindow(BackstageView.Ribbon.Handle);

  if ActiveTab <> nil then
  begin
    FActiveTabRect := cxGetWindowBounds(ActiveTab);
    FActiveTabBuffer := TcxBitmap.CreateSize(ActiveTabRect, pf24bit);
  end;

  FBackstageViewRect := cxGetWindowBounds(BackstageView);
  FBackstageViewBuffer := TcxBitmap.CreateSize(FBackstageViewRect);

  FBackstageViewMenuBuffer := TcxBitmap.CreateSize(BackstageView.MenuViewInfo.Bounds);
  cxPaintTo(BackstageView.MenuViewInfo.DockControl,
    BackstageViewMenuBuffer.cxCanvas, cxNullPoint, BackstageViewMenuBuffer.ClientRect);

  if (ActiveTab <> nil) and ActiveTabIsSolidBackground then
    cxPaintTo(ActiveTab, ActiveTabBuffer.cxCanvas, cxNullPoint, ActiveTabRect);
end;

procedure TdxRibbonBackstageViewAnimationTransition.PrepareBackstageViewBuffer(ACanvas: TcxCanvas);
var
  R: TRect;
begin
  ACanvas.Canvas.Lock;
  try
    cxPaintControlTo(BackstageView, ACanvas, cxNullPoint, BackstageViewRect, False, True);

    ACanvas.SaveClipRegion;
    try
      ACanvas.IntersectClipRect(NonClientViewInfo.ClientRect);
      cxBitBlt(ACanvas.Handle, BackstageViewMenuBuffer.Canvas.Handle,
        cxRectOffset(BackstageView.MenuViewInfo.Bounds, NonClientViewInfo.ClientRect.TopLeft),
        cxNullPoint, SRCCOPY);

      if ActiveTab <> nil then
      begin
        if not ActiveTabIsSolidBackground then
          cxPaintTo(ActiveTab, ActiveTabBuffer.cxCanvas, cxNullPoint, ActiveTabRect);

        R := dxMapWindowRect(ActiveTab.Handle, BackstageView.Handle, ActiveTabRect, False);
        if not SystemAlphaBlend(ACanvas.Handle, ActiveTabBuffer.Canvas.Handle,
          R, ActiveTabBuffer.ClientRect, CalculateContentAlpha, False)
        then
          cxBitBlt(ACanvas.Handle, ActiveTabBuffer.Canvas.Handle, R, cxNullPoint, SRCCOPY);
      end;
    finally
      ACanvas.RestoreClipRegion;
    end;
  finally
    ACanvas.Canvas.Unlock;
  end;
end;

function TdxRibbonBackstageViewAnimationTransition.GetActiveTab: TdxRibbonBackstageViewTabSheet;
begin
  Result := BackstageView.ActiveTab;
end;

function TdxRibbonBackstageViewAnimationTransition.GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
begin
  Result := BackstageView.MenuViewInfo;
end;

function TdxRibbonBackstageViewAnimationTransition.GetNonClientViewInfo: TdxRibbonBackstageViewNonClientViewInfo;
begin
  Result := BackstageView.NonClientViewInfo;
end;

function TdxRibbonBackstageViewAnimationTransition.GetViewInfo: TdxRibbonBackstageViewViewInfo;
begin
  Result := BackstageView.ViewInfo;
end;

{ TdxRibbonBackstageViewSizeGrip }

function TdxRibbonBackstageViewSizeGrip.GetRibbon: TdxCustomRibbon;
begin
  if Parent is TdxRibbonCustomBackstageView then
    Result := TdxRibbonCustomBackstageView(Parent).Ribbon
  else
    Result := nil;
end;

{ TdxRibbonBackstageViewScrollBar }

function TdxRibbonBackstageViewScrollBar.GetRibbon: TdxCustomRibbon;
begin
  if Parent is TdxRibbonCustomBackstageView then
    Result := TdxRibbonCustomBackstageView(Parent).Ribbon
  else
    Result := nil;
end;

{ TdxRibbonCustomBackstageView }

constructor TdxRibbonCustomBackstageView.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FBarManagerHolder := TcxComponentHolder.Create;
  FBarManagerHolder.OnAfterComponentChange := DoAfterBarManagerChange;
  FBarManagerHolder.OnBeforeComponentChange := DoBeforeBarManagerChange;
  FMenuHelper := TdxRibbonBackstageViewMenuHelper.Create(Self);
  FPainter := CreatePainter;
  FNonClientController := CreateNonClientController;
  FNonClientViewInfo := CreateNonClientViewInfo;
  FViewInfo := CreateViewInfo;
  FTabs := TdxRibbonBackstageViewTabSheets.Create;
  FButtons := TdxRibbonBackstageViewMenuButtons.Create(Self);
  if IsDesigning then
    FDesignSelector := CreateDesignSelector;
  CheckAssignRibbon;
  LookAndFeel.NativeStyle := True;
  RegisterBackstageView(Self);
  SetBounds(Left, Top, 450, 300);
  Visible := IsDesigning;
  ParentShowHint := False;
  ShowHint := False;
end;

destructor TdxRibbonCustomBackstageView.Destroy;
begin
  UnhookApplicationWndProc;
  UnregisterBackstageView(Self);
  ActiveTab := nil;
  DeleteAllTabs;
  Ribbon := nil;
  FreeAndNil(FTabs);
  FreeAndNil(FPainter);
  FreeAndNil(FButtons);
  FreeAndNil(FViewInfo);
  FreeAndNil(FMenuHelper);
  FreeAndNil(FNonClientController);
  FreeAndNil(FNonClientViewInfo);
  FreeAndNil(FBarManagerHolder);
  FreeAndNil(FDesignSelector);
  inherited Destroy;
end;

function TdxRibbonCustomBackstageView.AddTab: TdxRibbonBackstageViewTabSheet;
begin
  Result := TdxRibbonBackstageViewTabSheet.Create(Owner);
  Result.BackstageView := Self;
end;

procedure TdxRibbonCustomBackstageView.AfterBarManagerChange;
begin
  if Ribbon <> nil then
    BarManagerHolder.Component := Ribbon.BarManager
  else
    BarManagerHolder.Component := nil;
end;

function TdxRibbonCustomBackstageView.ApplicationWndProcHook(var Message: TMessage): Boolean;
begin
  Result := False;
  if (Message.Msg = CM_APPKEYDOWN) and (Message.WParam = VK_ESCAPE) then
  begin
    Result := Screen.ActiveForm = GetParentForm(Self);
    if Result then
      ClosePopup;
  end;
end;

procedure TdxRibbonCustomBackstageView.BeforeBarManagerChange;
begin
  BarManagerHolder.Component := nil;
end;

function TdxRibbonCustomBackstageView.CanProcessMouseWheel: Boolean;
begin
  Result := Enabled and Visible;
end;

function TdxRibbonCustomBackstageView.CanShowPopup(ARibbon: TdxCustomRibbon): Boolean;
begin
  Result := Assigned(Ribbon) and (ARibbon = Ribbon);
end;

procedure TdxRibbonCustomBackstageView.ClosePopup;
begin
  Hide;
end;

procedure TdxRibbonCustomBackstageView.ColorSchemeChangeHandler(Sender: TObject; const AEventArgs);
begin
  FullRefresh;
end;

function TdxRibbonCustomBackstageView.CreateApplicationMenuHelper: TdxRibbonBackstageViewApplicationMenuHelper;
begin
  Result := TdxRibbonBackstageViewApplicationMenuHelper.Create(Self);
end;

function TdxRibbonCustomBackstageView.CreateDesignSelector: TdxRibbonBackstageViewDesignSelector;
begin
  Result := TdxRibbonBackstageViewDesignSelector.Create(Self);
  Result.Parent := Self;
end;

function TdxRibbonCustomBackstageView.CreateNonClientController: TdxRibbonBackstageViewNonClientController;
begin
  Result := TdxRibbonBackstageViewNonClientController.Create(Self);
end;

function TdxRibbonCustomBackstageView.CreateNonClientViewInfo: TdxRibbonBackstageViewNonClientViewInfo;
begin
  Result := TdxRibbonBackstageViewNonClientViewInfo.Create(Self);
end;

function TdxRibbonCustomBackstageView.CreatePainter: TdxRibbonBackstageViewPainter;
begin
  Result := TdxRibbonBackstageViewPainter.Create(Self);
end;

function TdxRibbonCustomBackstageView.CreateViewInfo: TdxRibbonBackstageViewViewInfo;
begin
  Result := TdxRibbonBackstageViewViewInfo.Create(Self);
end;

function TdxRibbonCustomBackstageView.Popup(ARibbon: TdxCustomRibbon; var AClosedByEscape: Boolean): Boolean;

  function CanRestoreFocus(AFocus: HWND): Boolean;
  var
    AControl: TWinControl;
    AForm: TCustomForm;
  begin
    Result := IsChildEx(GetActiveWindow, AFocus);
    if Result then
    begin
      AControl := FindControl(AFocus);
      if AControl <> nil then
      begin
        AForm := GetParentForm(AControl);
        Result := (AForm <> nil) and AForm.Active;
      end;
    end;
  end;

var
  AForm: TCustomForm;
  AObjectLink: TcxObjectLink;
  ASavedBounds, R: TRect;
  ASavedConstraints: TSizeConstraints;
  ASavedFocus: HWND;
  ASavedParent: TWinControl;
begin
  Result := CanShowPopup(ARibbon);
  if Result then
  begin
    AObjectLink := cxAddObjectLink(Self);
    try
      ASavedConstraints := TSizeConstraints.Create(nil);
      try
        DoPopup;
        AForm := GetParentForm(Ribbon);
        ASavedParent := Parent;
        ASavedBounds := AForm.BoundsRect;
        ASavedConstraints.Assign(AForm.Constraints);
        ASavedFocus := GetFocus;
        try
          PrepareForPopup(AForm);
          R := AForm.BoundsRect;
          HookApplicationWndProc;
          BringToFront;
          Show;
          SetFocus;
          PopupMessageLoop(AForm);
        finally
          if AObjectLink.Ref <> nil then
          begin
            ViewInfo.DeactivateControls;
            Visible := False;
            UnhookApplicationWndProc;
            Parent := ASavedParent;
            AForm.Constraints.Assign(ASavedConstraints);
            if EqualRect(AForm.BoundsRect, R) then
              AForm.BoundsRect := ASavedBounds;
            DoCloseUp;
            if CanRestoreFocus(ASavedFocus) then
              Windows.SetFocus(ASavedFocus);
          end;
        end;
      finally
        ASavedConstraints.Free;
      end;
    finally
      cxRemoveObjectLink(AObjectLink);
    end;
  end;
end;

procedure TdxRibbonCustomBackstageView.PopupMessageLoop(AParentForm: TCustomForm);

  function IsModalFormClosing(AForm: TCustomForm): Boolean;
  begin
    Result := (fsModal in AForm.FormState) and (AForm.ModalResult <> mrNone);
  end;

begin
  while HandleAllocated and IsWindowVisible(Handle) do
  begin
    if Application.Terminated or IsModalFormClosing(AParentForm) then
      Break;
    Application.HandleMessage;
  end;
end;

procedure TdxRibbonCustomBackstageView.PrepareForPopup(AForm: TCustomForm);
begin
  Parent := AForm;
  MenuViewInfo.InitiateActions;
  ViewInfo.ScrollPositionX := 0;
  ViewInfo.ScrollPositionY := 0;
  AForm.Constraints.MinWidth := Max(AForm.Constraints.MinWidth, dxRibbonBackstageViewMinOwnerWidth);
  AForm.Constraints.MinHeight := Max(AForm.Constraints.MinHeight, dxRibbonBackstageViewMinOwnerHeight);
  CalculatePlace;
  NonClientViewInfo.Recalculate;
  SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE or SWP_NOZORDER or SWP_FRAMECHANGED);
  UpdateWindowRegion;
  if ActiveTab <> nil then
    ActiveTab.Visible := True;
end;

function TdxRibbonCustomBackstageView.QueryInterface(const IID: TGUID; out Obj): HRESULT;
begin
  if IsEqualGUID(IID, IdxRibbonApplicationMenu) then
  begin
    IdxRibbonApplicationMenu(Obj) := CreateApplicationMenuHelper;
    Result := S_OK;
  end
  else
    Result := inherited QueryInterface(IID, Obj);
end;

procedure TdxRibbonCustomBackstageView.SelectionChanged;
begin
  if DesignSelector <> nil then
    DesignSelector.Invalidate;
end;

procedure TdxRibbonCustomBackstageView.ShowControl(AControl: TControl);
begin
  if AControl is TdxRibbonBackstageViewTabSheet then
    TdxRibbonBackstageViewTabSheet(AControl).Active := True;
  inherited ShowControl(AControl);
end;

procedure TdxRibbonCustomBackstageView.BoundsChanged;
begin
  inherited BoundsChanged;
  Changed;
end;

procedure TdxRibbonCustomBackstageView.Calculate;
var
  I: Integer;
begin
  ViewInfo.Calculate(ClientBounds);
  for I := 0 to TabCount - 1 do
    Tabs[I].Calculate(ViewInfo.FrameAreaBounds);
  if DesignSelector <> nil then
  begin
    if not BarDesignController.IsDesignerModifiedLocked then
    begin
      DesignSelector.BoundsRect := ViewInfo.DesignSelectorRect;
      DesignSelector.BringToFront;
    end;
  end;
end;

procedure TdxRibbonCustomBackstageView.CalculatePlace;
var
  P: TPoint;
  R: TRect;
begin
  if Parent <> nil then
  begin
    R := Parent.ClientRect;
    if NonClientViewInfo.DisplayMode = amdmFrame then
    begin
      P := Ribbon.ViewInfo.TabsBounds.BottomRight;
      P := dxMapWindowPoint(Ribbon.Handle, Parent.Handle, P);
      R.Top := P.Y;
    end
    else
      Inc(R.Top);

    BoundsRect := R;
  end;
end;

procedure TdxRibbonCustomBackstageView.CheckAssignRibbon;
begin
  if IsDesigning then
    Ribbon := FindRibbonForComponent(Self);
end;

function TdxRibbonCustomBackstageView.CanActivateTab(ATab: TdxRibbonBackstageViewTabSheet): Boolean;
begin
  Result := ((ATab = nil) or ATab.CanBeActive) and (IsDesigning or DoTabChanging(ATab));
end;

procedure TdxRibbonCustomBackstageView.Changed(const AChanges: TdxRibbonBackstageViewChanges);
begin
  if FUpdateCount > 0 then
    FChanges := FChanges + AChanges
  else
    if not IsDestroying and HandleAllocated then
    begin
      if rbvcStruct in AChanges then
        MenuViewInfo.RecreateItemLinks
      else
      begin
        if rbvcItemsData in AChanges then
          MenuViewInfo.RefreshMenuButtonsInfo;
        if rbvcTabsData in AChanges then
          MenuViewInfo.RefreshTabsInfo;
      end;
      Calculate;
      NonClientViewInfo.Recalculate;
      ValidateActiveTab;
      UpdateScrollBars;
      FullInvalidate;
    end;
end;

procedure TdxRibbonCustomBackstageView.CreateWnd;
begin
  inherited CreateWnd;
  FullRefresh;
end;

procedure TdxRibbonCustomBackstageView.BeginUpdate;
begin
  Inc(FUpdateCount);
end;

procedure TdxRibbonCustomBackstageView.EndUpdate;
begin
  Dec(FUpdateCount);
  if FUpdateCount = 0 then
  begin
    Changed(FChanges);
    FChanges := [];
  end;
end;

procedure TdxRibbonCustomBackstageView.DeleteAllTabs;
begin
  BeginUpdate;
  try
    while TabCount > 0 do
      Tabs[TabCount - 1].Free;
  finally
    EndUpdate;
  end;
end;

procedure TdxRibbonCustomBackstageView.DeleteTab(AIndex: Integer);
begin
  Tabs[AIndex].Free;
end;

procedure TdxRibbonCustomBackstageView.DoAddTab(ATab: TdxRibbonBackstageViewTabSheet);
begin
  FTabs.Add(ATab);
  if ActiveTab = nil then
    ValidateActiveTab;
  if ActiveTab <> nil then
    ActiveTab.BringToFront;
  Changed([rbvcStruct]);
end;

procedure TdxRibbonCustomBackstageView.DoAfterBarManagerChange(Sender: TObject);
begin
  if IsBarManagerValid then
    BarManager.SystemFontChangedHandlers.Add(SystemFontChanged);
  MenuViewInfo.CreateViewInfoItems;
  MenuViewInfo.RecreateItemLinks;
end;

procedure TdxRibbonCustomBackstageView.DoBeforeBarManagerChange(Sender: TObject);
begin
  if IsBarManagerValid then
    BarManager.SystemFontChangedHandlers.Remove(SystemFontChanged);
  MenuViewInfo.ClearInternalLists;
  MenuViewInfo.DestroyViewInfoItems;
end;

procedure TdxRibbonCustomBackstageView.DoCloseUp;
begin
  CallNotify(OnCloseUp, Self);
end;

function TdxRibbonCustomBackstageView.DoMouseWheelDown(Shift: TShiftState; MousePos: TPoint): Boolean;
begin
  Result := inherited DoMouseWheelDown(Shift, MousePos);
  if not Result then
    Result := ViewInfo.ProcessMouseWheel(True);
end;

function TdxRibbonCustomBackstageView.DoMouseWheelUp(Shift: TShiftState; MousePos: TPoint): Boolean;
begin
  Result := inherited DoMouseWheelUp(Shift, MousePos);
  if not Result then
    Result := ViewInfo.ProcessMouseWheel(False);
end;

procedure TdxRibbonCustomBackstageView.DoPopup;
begin
  CallNotify(FOnPopup, Self);
end;

procedure TdxRibbonCustomBackstageView.DoRemoveTab(ATab: TdxRibbonBackstageViewTabSheet);

  function GetNewActiveTab: TdxRibbonBackstageViewTabSheet;
  begin
    if ActiveTab = ATab then
      Result := GetNextTab(ATab.PageIndex)
    else
      Result := ActiveTab;
  end;

var
  ANewActiveTab: TdxRibbonBackstageViewTabSheet;
begin
  ANewActiveTab := GetNewActiveTab;
  MenuViewInfo.TabButtonList.RemoveTab(ATab);
  FTabs.Extract(ATab);
  ActiveTab := ANewActiveTab;
  Changed([rbvcStruct]);
end;

procedure TdxRibbonCustomBackstageView.DoTabChanged;
begin
  CallNotify(OnTabChanged, Self);
end;

function TdxRibbonCustomBackstageView.DoTabChanging(ANewTab: TdxRibbonBackstageViewTabSheet): Boolean;
begin
  Result := True;
  if Assigned(OnTabChanging) then
    OnTabChanging(Self, ANewTab, Result);
end;

procedure TdxRibbonCustomBackstageView.DoTabVisibleChanged(ATab: TdxRibbonBackstageViewTabSheet);
begin
  BeginUpdate;
  try
    if not ATab.TabVisible then
      ActiveTab := GetNextTab(ATab);
    Changed([rbvcStruct, rbvcTabsData]);
  finally
    EndUpdate;
  end;
end;

procedure TdxRibbonCustomBackstageView.FullInvalidate;
begin
  if HandleAllocated then
    cxRedrawWindow(Handle, cxGetWindowBounds(Self), True, True);
end;

procedure TdxRibbonCustomBackstageView.FullRefresh;
begin
  if HandleAllocated then
    SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_NOSIZE or SWP_NOMOVE or SWP_NOZORDER or SWP_FRAMECHANGED);
  if ActiveTab <> nil then
    ActiveTab.RefreshNonClientArea;
  Changed([rbvcStruct, rbvcItemsData, rbvcTabsData]);
end;

procedure TdxRibbonCustomBackstageView.FocusChanged;
var
  AItemControl: TdxBarItemControl;
begin
  inherited FocusChanged;
  if Focused then
  begin
    AItemControl := ViewInfo.ActiveTabItemControl;
    if AItemControl <> nil then
      AItemControl.IAccessibilityHelper.Select(True);
  end;
end;

procedure TdxRibbonCustomBackstageView.InitScrollBarsParameters;
begin
  SetScrollBarInfo(sbHorizontal, 0, ViewInfo.ContentWidth, dxBackstageViewScrollLineSize,
    cxRectWidth(ViewInfo.Bounds) + 1, ViewInfo.ScrollPositionX, True, True);
  SetScrollBarInfo(sbVertical, 0, ViewInfo.ContentHeight, dxBackstageViewScrollLineSize,
    cxRectHeight(ViewInfo.Bounds) + 1, ViewInfo.ScrollPositionY, True, True);
end;

procedure TdxRibbonCustomBackstageView.Notification(
  AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if Buttons <> nil then
    Buttons.Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = Ribbon) then
    Ribbon := nil;
end;

procedure TdxRibbonCustomBackstageView.MakeFullyVisible(R: TRect);

  function CalculateScrollPosition(ASourceBound1, ASourceBound2: Integer;
    ATargetBound1, ATargetBound2, APosition: Integer): Integer;
  begin
    if ATargetBound1 < ASourceBound1 then
      Result := APosition - ASourceBound1 + ATargetBound1
    else
      if ATargetBound2 > ASourceBound2 then
        Result := APosition - ASourceBound2 + ATargetBound2
      else
        Result := APosition;
  end;

begin
  ViewInfo.ScrollPositionX := CalculateScrollPosition(ViewInfo.Bounds.Left,
    ViewInfo.Bounds.Right, R.Left, R.Right, ViewInfo.ScrollPositionX);
  ViewInfo.ScrollPositionY := CalculateScrollPosition(ViewInfo.Bounds.Top,
    ViewInfo.Bounds.Bottom, R.Top, R.Bottom, ViewInfo.ScrollPositionY);
end;

procedure TdxRibbonCustomBackstageView.NCPaint(DC: HDC);
begin
  cxPaintCanvas.BeginPaint(DC);
  try
    cxPaintCanvas.ExcludeClipRect(NonClientViewInfo.ClientRect);
    NonClientViewInfo.Draw(cxPaintCanvas);
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

function TdxRibbonCustomBackstageView.GetScrollBarClass(AKind: TScrollBarKind): TcxControlScrollBarClass;
begin
  Result := TdxRibbonBackstageViewScrollBar;
end;

function TdxRibbonCustomBackstageView.GetSizeGripClass: TcxSizeGripClass;
begin
  Result := TdxRibbonBackstageViewSizeGrip;
end;

function TdxRibbonCustomBackstageView.NeedsToBringInternalControlsToFront: Boolean;
begin
  Result := True;
end;

function TdxRibbonCustomBackstageView.IsPersistentSelected(AObject: TPersistent): Boolean;
begin
  Result := Assigned(FDesignHelper) and FDesignHelper.IsObjectSelected(Self, AObject);
end;

procedure TdxRibbonCustomBackstageView.Paint;
begin
  Painter.DrawBackground(Canvas, cxRectOffset(cxGetWindowBounds(Self),
    NonClientViewInfo.ClientOffsets.TopLeft, False));
end;

procedure TdxRibbonCustomBackstageView.Scroll(
  AScrollBarKind: TScrollBarKind; AScrollCode: TScrollCode; var AScrollPos: Integer);
begin
  case AScrollBarKind of
    sbHorizontal:
      begin
        ViewInfo.ScrollPositionX := AScrollPos;
        AScrollPos := ViewInfo.ScrollPositionX;
      end;

    sbVertical:
      begin
        ViewInfo.ScrollPositionY := AScrollPos;
        AScrollPos := ViewInfo.ScrollPositionY;
      end;
  end;
end;

procedure TdxRibbonCustomBackstageView.SelectPersistent(AObject: TPersistent);
begin
  if Assigned(FDesignHelper) then
    FDesignHelper.SelectObject(Self, AObject);
end;

procedure TdxRibbonCustomBackstageView.SystemFontChanged(Sender: TObject; const AEventArgs);
begin
  MenuViewInfo.UpdateFont;
  FullRefresh;
end;

procedure TdxRibbonCustomBackstageView.HookApplicationWndProc;
begin
  if not FApplicationWndProcHooked then
  begin
    Application.HookMainWindow(ApplicationWndProcHook);
    FApplicationWndProcHooked := True;
  end;
end;

procedure TdxRibbonCustomBackstageView.UnhookApplicationWndProc;
begin
  if FApplicationWndProcHooked then
  begin
    Application.UnhookMainWindow(ApplicationWndProcHook);
    FApplicationWndProcHooked := False;
  end;
end;

procedure TdxRibbonCustomBackstageView.UpdateWindowRegion;
var
  R: TRect;
begin
  R := cxGetWindowRect(Handle);
  R := cxRectOffset(R, R.TopLeft, False);
  NonClientViewInfo.Calculate(R);
  SetWindowRgn(Handle, NonClientViewInfo.CreateWindowRegion, True);
end;

procedure TdxRibbonCustomBackstageView.RibbonAfterChange;
begin
  if Ribbon <> nil then
  begin
    Ribbon.AddListener(Self);
    Ribbon.ColorSchemeHandlers.Add(ColorSchemeChangeHandler);
  end;
  AfterBarManagerChange;
end;

procedure TdxRibbonCustomBackstageView.RibbonBeforeChange;
begin
  BeforeBarManagerChange;
  if Ribbon <> nil then
  begin
    Ribbon.RemoveListener(Self);
    if Ribbon.ColorSchemeHandlers <> nil then
      Ribbon.ColorSchemeHandlers.Remove(ColorSchemeChangeHandler);
  end;
end;

procedure TdxRibbonCustomBackstageView.ValidateActiveTab;
begin
  if (ActiveTab = nil) or not ActiveTab.CanBeActive then
    ActiveTab := GetNextTab(ActiveTab);
end;

procedure TdxRibbonCustomBackstageView.CMVisibleChanged(var Message: TMessage);
var
  AAnimationTransition: TdxRibbonBackstageViewAnimationTransition;
begin
  if IsInPopupLoop and (Ribbon.Style = rs2013) then
  begin
    LockWindowUpdate(Handle);
    try
      if Visible then
      begin
        inherited;
        AAnimationTransition := TdxRibbonBackstageViewAnimationTransition.Create(Self, bvatmShow);
        AAnimationTransition.ImmediateAnimation;
      end
      else
      begin
        BarNavigationController.SetKeyTipsShowingState(nil, '');
        AAnimationTransition := TdxRibbonBackstageViewAnimationTransition.Create(Self, bvatmHide);
        AAnimationTransition.ImmediateAnimation;
        inherited;
      end;
    finally
      LockWindowUpdate(0);
      RedrawWindow(Handle, nil, 0, RDW_INVALIDATE or RDW_ALLCHILDREN or RDW_FRAME or RDW_UPDATENOW);
    end;
  end
  else
    inherited;
end;

procedure TdxRibbonCustomBackstageView.WMNCCalcSize(var Message: TWMNCCalcSize);
begin
  inherited;
  with Message.CalcSize_Params^ do
    rgrc[0] := cxRectContent(rgrc[0], NonClientViewInfo.ClientOffsets);
end;

procedure TdxRibbonCustomBackstageView.WMNCPaint(var Message: TWMNCPaint);
var
  AMemBmp: HBITMAP;
  AMemDC: HDC;
  DC: HDC;
begin
  if NonClientViewInfo.HasNonClientArea then
  begin
    DC := GetWindowDC(Handle);
    try
      AMemDC := CreateCompatibleDC(DC);
      AMemBmp := CreateCompatibleBitmap(DC, Width, Height);
      try
        SelectObject(AMemDC, AMemBmp);
        NCPaint(AMemDC);
        cxPaintCanvas.BeginPaint(DC);
        try
          cxPaintCanvas.ExcludeClipRect(NonClientViewInfo.ClientRect);
          cxBitBlt(cxPaintCanvas.Handle, AMemDC, cxGetWindowBounds(Self), cxNullPoint, SRCCOPY);
        finally
          cxPaintCanvas.EndPaint;
        end;
      finally
        DeleteObject(AMemBmp);
        DeleteObject(AMemDC);
      end;
    finally
      ReleaseDC(Handle, DC);
    end;
  end;
end;

procedure TdxRibbonCustomBackstageView.WMPrint(var Message: TWMPrint);
begin
  if PRF_NONCLIENT and Message.Flags <> 0 then
    NCPaint(Message.DC);
  inherited;
end;

procedure TdxRibbonCustomBackstageView.WMSize(var Message: TWMSize);
begin
  inherited;
  UpdateWindowRegion;
end;

procedure TdxRibbonCustomBackstageView.WndProc(var Message: TMessage);
begin
  inherited WndProc(Message);
  if NonClientController <> nil then
    NonClientController.ProcessMessage(Message);
end;

function TdxRibbonCustomBackstageView.GetBarManager: TdxBarManager;
begin
  Result := TdxBarManager(BarManagerHolder.Component);
end;

procedure TdxRibbonCustomBackstageView.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
begin
  for I := 0 to TabCount - 1 do
    Proc(Tabs[I]);
end;

function TdxRibbonCustomBackstageView.GetIsBarManagerValid: Boolean;
begin
  Result := (BarManager <> nil) and not (csDestroying in BarManager.ComponentState);
end;

function TdxRibbonCustomBackstageView.GetMenuViewInfo: TdxRibbonBackstageViewMenuViewInfo;
begin
  Result := ViewInfo.MenuViewInfo;
end;

function TdxRibbonCustomBackstageView.GetNextTab(ATab: TdxRibbonBackstageViewTabSheet): TdxRibbonBackstageViewTabSheet;
var
  AIndex: Integer;
begin
  if ATab = nil then
    AIndex := -1
  else
    AIndex := ATab.PageIndex;

  Result := GetNextTab(AIndex);
end;

function TdxRibbonCustomBackstageView.GetNextTab(AIndex: Integer): TdxRibbonBackstageViewTabSheet;
var
  I: Integer;
begin
  Result := nil;
  for I := AIndex + 1 to TabCount - 1 do
    if Tabs[I].CanBeActive then
    begin
      Result := Tabs[I];
      Exit;
    end;

  for I := AIndex - 1 downto 0 do
    if Tabs[I].CanBeActive then
    begin
      Result := Tabs[I];
      Exit;
    end;
end;

function TdxRibbonCustomBackstageView.GetTabs(Index: Integer): TdxRibbonBackstageViewTabSheet;
begin
  Result := FTabs[Index];
end;

function TdxRibbonCustomBackstageView.GetTabCount: Integer;
begin
  Result := FTabs.Count;
end;

procedure TdxRibbonCustomBackstageView.SetActiveTab(AValue: TdxRibbonBackstageViewTabSheet);
begin
  if (FActiveTab <> AValue) and CanActivateTab(AValue) then
  begin
    if ActiveTab <> nil then
      ActiveTab.Deactivate;
    FActiveTab := AValue;
    if ActiveTab <> nil then
      ActiveTab.Activate;
    if IsDesigning and not IsLoading then
      Modified;
    Changed([rbvcTabsData]);
    DoTabChanged;
  end;
end;

procedure TdxRibbonCustomBackstageView.SetButtons(AValue: TdxRibbonBackstageViewMenuButtons);
begin
  FButtons.Assign(AValue);
end;

procedure TdxRibbonCustomBackstageView.SetRibbon(AValue: TdxCustomRibbon);
begin
  if AValue <> FRibbon then
  begin
    RibbonBeforeChange;
    FRibbon := AValue;
    RibbonAfterChange;
    FullRefresh;
  end;
end;

initialization
  RegisterClass(TdxRibbonBackstageViewTabSheet);
end.

