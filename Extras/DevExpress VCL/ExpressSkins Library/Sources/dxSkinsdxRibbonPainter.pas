{********************************************************************}
{                                                                    }
{           Developer Express Visual Component Library               }
{                    ExpressSkins Library                            }
{                                                                    }
{           Copyright (c) 2006-2014 Developer Express Inc.           }
{                     ALL RIGHTS RESERVED                            }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSSKINS AND ALL ACCOMPANYING     }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.              }
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

unit dxSkinsdxRibbonPainter;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Types, Windows, Classes, SysUtils, dxSkinsCore, dxSkinsLookAndFeelPainter, Graphics,
  dxRibbonSkins, dxBarSkin, cxLookAndFeels, cxLookAndFeelPainters, cxGraphics,
  cxClasses, dxBarSkinConsts, cxGeometry, dxRibbon, dxBar, Math, cxDWMApi,
  Forms, dxSkinInfo, dxGDIPlusAPI, dxGDIPlusClasses, dxOffice11, dxCore, dxCoreClasses;

type

  { TdxSkinRibbonPainter }

  TdxSkinRibbonPainter = class(TdxCustomRibbonSkin)
  private
    FPainter: TdxSkinLookAndFeelPainter;
    function GetPopupMenuColor: TColor;
    function GetSkinInfo: TdxSkinLookAndFeelPainterInfo; {$IFDEF DELPHI9} inline; {$ENDIF}
    function GetTabAeroSupport: Boolean;
    function GetUseSkins: Boolean;
  protected
    procedure CheckColorSchemeAccent(var AColorSchemeAccent: TdxRibbonColorSchemeAccent);
    function CorrectTabHeaderRect(const R: TRect): TRect;
    function CorrectTabPanelRect(AIsInPopup: Boolean; const R: TRect): TRect;
    function GetApplicationButtonElement: TdxSkinElement; virtual;
    function GetApplicationButtonIndent(const AName: string): Integer;
    function GetBorderBounds(ASide: TcxBorder; const ABorders, ABounds: TRect): TRect;
    function GetBorderIconElement(AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean): TdxSkinElement;
    function GetBorderSkinElement(ASide: TcxBorder; AIsRectangular: Boolean): TdxSkinElement;
    function GetBordersWidth(AHasStatusBar: Boolean): TRect;
    function GetCustomizeButtonOutsizeQAT(AHasAppButton: Boolean): Boolean;
    function GetElementContentIndents(AElement: TdxSkinElement;
      AConsideMargins: Boolean; out ALeftIndent, ARightIndent: Integer): Boolean;
    function GetElementMinSize(AElement: TdxSkinElement): TSize;
    function GetName: string; override;
    function GetPropertyColor(AColor: TdxSkinColor): TColor;
    function GetQATBackgroundElement(ABellow, AHasApplicationButton: Boolean): TdxSkinElement;
    function GetQATLeftOffset(AHasApplicationButton: Boolean): Integer;

    function DoDrawButtonGroupElement(DC: HDC; const R: TRect; AState: Integer; AElement: TdxSkinElement): Boolean;
    function DoDrawEditButtonGlyph(DC: HDC; const R: TRect; AState: Integer; AButtonKind: TcxEditBtnKind): Boolean;
    function DoDrawStatusBarBackground(DC: HDC; const R, AVisibleArea: TRect; AIsRaised: Boolean): Boolean;
    function DoDrawStatusBarPart(DC: HDC; const R: TRect; AIsRaised, AActive, AIsLeft: Boolean): Boolean;
    function DoDrawStatusBarRectangularPart(DC: HDC; const R: TRect; AIsRaised, AActive, AIsLeft: Boolean): Boolean;

    function DrawElement(DC: HDC; const R: TRect; AElement: TdxSkinElement): Boolean; overload;
    function DrawElement(DC: HDC; const R: TRect; AState: Integer; AElement: TdxSkinElement; AImageIndex: Integer = 0): Boolean; overload;

    procedure DrawClippedElement(DC: HDC; const R: TRect; const ASource: TRect;
      AElement: TdxSkinElement; AState: TdxSkinElementState = esNormal;
      AOperation: TcxRegionOperation = roIntersect; AImageIndex: Integer = 0);
    procedure DrawColoredElement(DC: HDC; const R: TRect;
      AColor: TColor; AElement: TdxSkinElement; AState: TdxSkinElementState);
    procedure DrawFormBorder(DC: HDC; ASide: TcxBorder;
      const ABorderWidths, R: TRect; AElement: TdxSkinElement; AActive: Boolean);
    procedure DrawStatusBarFormBorder(DC: HDC; const AData: TdxRibbonFormData; const ABorders: TRect);

    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); override;

    property ApplicationButtonElement: TdxSkinElement read GetApplicationButtonElement;
    property PopupMenuColor: TColor read GetPopupMenuColor;
    property SkinInfo: TdxSkinLookAndFeelPainterInfo read GetSkinInfo;
    property TabAeroSupport: Boolean read GetTabAeroSupport;
  public
    constructor Create(APainter: TdxSkinLookAndFeelPainter); virtual;

    //  Application
    procedure DrawApplicationButton(DC: HDC; const R: TRect;
      AState: TdxRibbonApplicationButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawApplicationMenuBackground(DC: HDC; const R, AContentRect: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawApplicationMenuButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawApplicationMenuExtraPaneButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawApplicationMenuExtraPanePinButtonGlyph(DC: HDC; const R: TRect; AState: Integer;
      AChecked: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // BackstageView
    procedure DrawBackstageViewBackButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuHeader(DC: HDC;
      const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuSeparator(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewTabButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // BackstageViewGallery
    procedure DrawBackstageViewGalleryBackground(DC: HDC; const R: TRect); override;
    procedure DrawBackstageViewGalleryItem(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewGallerySeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Button Group
    procedure DrawButtonGroup(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupBackground(DC: HDC; const R: TRect);
    procedure DrawButtonGroupBorderLeft(DC: HDC; const R: TRect); override;
    procedure DrawButtonGroupBorderMiddle(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawButtonGroupBorderRight(DC: HDC; const R: TRect); override;
    procedure DrawButtonGroupSplitButtonSeparator(DC: HDC; const R: TRect; AState: Integer); override;

    // CollapsedToolbar
    procedure DrawCollapsedToolbarBackground(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawCollapsedToolbarGlyphBackground(DC: HDC; const R: TRect; AState: Integer); override;

    // EditButton
    procedure DrawEditArrowButton(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawEditEllipsisButton(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawEditSpinDownButton(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawEditSpinUpButton(DC: HDC; const R: TRect; AState: Integer); override;

    // Custom controls
    procedure DrawProgressDiscreteBand(DC: HDC; const R: TRect); override;
    procedure DrawProgressSolidBand(DC: HDC; const R: TRect); override;
    procedure DrawProgressSubstrate(DC: HDC; const R: TRect); override;

    // DropDown Gallery
    procedure DrawDropDownBorder(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryBackground(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryBottomSizeGrip(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryBottomSizingBand(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryBottomVerticalSizeGrip(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryTopSizingBand(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryTopSizeGrip(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryTopVerticalSizeGrip(DC: HDC; const R: TRect); override;
    procedure DrawGalleryFilterBandBackground(DC: HDC; const R: TRect); override;
    procedure DrawGalleryGroupHeaderBackground(DC: HDC; const R: TRect); override;
    procedure DrawInRibbonGalleryBackground(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawInRibbonGalleryScrollBarBackground(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawInRibbonGalleryScrollBarButton(DC: HDC; const R: TRect;
      AButtonKind: TdxInRibbonGalleryScrollBarButtonKind; AState: Integer;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Form
    procedure DrawRibbonFormBackground(DC: HDC; const R: TRect; ARibbonHeight: Integer); override;
    procedure DrawFormBorders(DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo); override;
    procedure DrawFormBorderIcon(DC: HDC; const R: TRect; AIcon: TdxRibbonBorderDrawIcon;
      AState: TdxRibbonBorderIconState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawFormCaption(DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo); override;
    procedure DrawFormStatusBarPart(DC: HDC; const R: TRect; AIsLeft, AIsActive: Boolean;
      AIsRaised, AIsRectangular: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Contexts
    procedure DrawContextBackground(DC: HDC; const R: TRect; AColor: TColor); override;
    procedure DrawContextBackgroundGlass(DC: HDC; const R: TRect; AColor: TColor); override;
    procedure DrawContextTabBackground(DC: HDC; const R: TRect; AState: TdxRibbonTabState;
      AColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawContextTabGroupsArea(DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean); override;
    procedure DrawContextTabSeparator(DC: HDC; const R: TRect; ABeginGroup: Boolean); override;

    // Others
    procedure DrawArrowDown(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawEditButton(DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawGroupScrollButton(DC: HDC; const R: TRect; ALeft: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawHelpButton(DC: HDC; const R: TRect;
      AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawItemSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); override;
    procedure DrawKeyTip(DC: HDC; const R: TRect); override;
    procedure DrawMarkArrow(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawMDIButton(DC: HDC; const R: TRect; AButton: TdxBarMDIButton;
      AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMDIButtonGlyph(DC: HDC; const R: TRect; AButton: TdxBarMDIButton; AState: TcxButtonState); override;
    procedure DrawMinimizeRibbonButtonGlyph(DC: HDC; const R: TRect; AState: TcxButtonState;
      AGlyph: TdxRibbonMinimizeButtonGlyph; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawRibbonClientTopArea(DC: HDC; const R: TRect); override;
    procedure DrawRibbonTopFrameArea(DC: HDC; const R: TRect; AUseAeroGlass: Boolean); override;
    procedure DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect); override;
    procedure DrawScreenTip(DC: HDC; const R: TRect); override;
    procedure DrawSeparatorBackground(DC: HDC; const R: TRect); override;

    // Large buttons
    procedure DrawLargeButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLargeButtonDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLargeButtonDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Launch
    procedure DrawLaunchButtonBackground(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLaunchButtonDefaultGlyph(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Menus
    procedure DrawMenuCheck(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuCheckMark(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuContent(DC: HDC; const R: TRect); override;
    procedure DrawMenuExtraSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); override;
    procedure DrawMenuGlyph(DC: HDC; const R: TRect); override;
    procedure DrawMenuItem(DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuItemDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuItemDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuMark(DC: HDC; const R: TRect); override;
    procedure DrawMenuScrollArea(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawMenuSeparatorHorz(DC: HDC; const R: TRect); override;
    procedure DrawMenuSeparatorVert(DC: HDC; const R: TRect); override;

    // Small buttons
    procedure DrawSmallButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawSmallButtonDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawSmallButtonDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Status Bar
    procedure DrawStatusBar(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarGripBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarPanel(DC: HDC; const Bounds, R: TRect;
      AIsLowered: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarPanelSeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarSizeGrip(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarToolbarSeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // ScrollBar
    function GetScrollBarPainter: TcxCustomLookAndFeelPainter; override;

    // Tabs
    procedure DrawTab(DC: HDC; const R: TRect; AState: TdxRibbonTabState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawTabAreaBackground(DC: HDC; const R: TRect; AActive: Boolean;
      AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState); override;
    procedure DrawTabGroupBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); override;
    procedure DrawTabGroupHeaderBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); override;
    procedure DrawTabGroupsArea(DC: HDC; const R: TRect; AIsQATAtBottom, AIsInPopup: Boolean); override;
    procedure DrawTabScrollButton(DC: HDC; const R: TRect; ALeft: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawTabSeparator(DC: HDC; const R: TRect; Alpha: Byte); override;

    // QuickAccess
    procedure DrawQuickAccessToolbar(DC: HDC; const R: TRect;
      ABellow, ANonClientDraw, AHasApplicationButton, AIsActive, ADontUseAero: Boolean); override;
    procedure DrawQuickAccessToolbarDefaultGlyph(DC: HDC; const R: TRect); override;
    procedure DrawQuickAccessToolbarGroupButton(DC: HDC; const R: TRect;
      ABellow: Boolean; ANonClientDraw: Boolean; AIsActive: Boolean; AState: Integer;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawQuickAccessToolbarPopup(DC: HDC; const R: TRect); override;
    //
    function AdjustCaptionFontSize(ASize: Integer; AUseAeroGlass: Boolean): Integer; override;
    procedure AdjustRibbonFormBorderIconSize(AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean; var ASize: TSize); override;
    function GetApplicationMenuContentOffset(const ATabsBounds: TRect): TRect; override;
    function GetApplicationMenuGlyphSize: TSize; override;
    function GetIsAlphaUsed(APart: Integer): Boolean; override;
    function GetMenuSeparatorSize: Integer; override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
    function GetPartContentOffsets(APart: Integer): TRect; override;
    function GetPartSize(APart: Integer): Integer; override;
    function GetQuickAccessToolbarLeftIndent(AHasApplicationButton, AUseAeroGlass: Boolean): Integer; override;
    function GetQuickAccessToolbarMarkButtonOffset(AHasApplicationButton, ABelow: Boolean): Integer; override;
    function GetQuickAccessToolbarOverrideWidth(AHasApplicationButton, AUseAeroGlass: Boolean): Integer; override;
    function GetQuickAccessToolbarRightIndent(AHasApplicationButton: Boolean): Integer; override;
    function GetSkinName: string; override;
    function GetStatusBarSeparatorSize: Integer; override;
    function GetWindowBordersWidth(AHasStatusBar: Boolean): TRect; override;
    function NeedDrawGroupScrollArrow: Boolean; override;
    function UseRoundedWindowCorners: Boolean; override;
    //
    property Painter: TdxSkinLookAndFeelPainter read FPainter;
    property SkinName: string read GetSkinName;
    property UseSkins: Boolean read GetUseSkins;
  end;

  { TdxSkinRibbon2010Painter }

  TdxSkinRibbon2010Painter = class(TdxSkinRibbonPainter)
  protected
    function GetApplicationButtonElement: TdxSkinElement; override;
    function GetStyle: TdxRibbonStyle; override;
  public
    function ExtendCaptionAreaOnTabs: Boolean; override;
    function GetApplicationMenuContentOffset(const ATabsBounds: TRect): TRect; override;
    function GetPartContentOffsets(APart: Integer): TRect; override;
  end;

  { TdxSkinRibbon2013Painter }

  TdxSkinRibbon2013Painter = class(TdxSkinRibbon2010Painter)
  protected
    procedure DrawBackstageViewBorders(DC: HDC; const R, ABordersWidth: TRect; AIsActive: Boolean); virtual;
    function GetStyle: TdxRibbonStyle; override;
  public
    procedure DrawBackstageViewMenuBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuHeader(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawFormBorders(DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo); override;
    procedure DrawFormCaption(DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo); override;
    function GetPartContentOffsets(APart: Integer): TRect; override;
  end;

implementation

uses
  dxSkinsStrs;

const
  QATLeftDefaultOffset = 15;
  QATRightDefaultOffset = 12;

  RibbonFormBorderStates: array[Boolean] of TdxSkinElementState =
    (esActiveDisabled, esActive);
  RibbonTabStatesMap: array[TdxRibbonTabState] of TdxSkinElementState =
    (esNormal, esHot, esActive, esFocused, esFocused);

type

  { TdxSkinsRibbonPainterManager }

  TdxSkinsRibbonPainterManager = class(TcxIUnknownObject, IcxLookAndFeelPainterListener)
  private
    procedure FreePaintersList;
    procedure InitializePaintersList;
  protected
    procedure AddSkin(APainter: TcxCustomLookAndFeelPainter);
    // IcxLookAndFeelPainterListener
    procedure PainterAdded(APainter: TcxCustomLookAndFeelPainter);
    procedure PainterRemoved(APainter: TcxCustomLookAndFeelPainter);
  public
    constructor Create; virtual;
    destructor Destroy; override;
  end;

var
  FRibbonPainterManager: TdxSkinsRibbonPainterManager;

function RibbonStateToButtonState(AState: Integer): TcxButtonState;
begin
  case AState of
    DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
      Result := cxbsDisabled;
    DXBAR_DROPPEDDOWN, DXBAR_PRESSED, DXBAR_CHECKED, DXBAR_HOTCHECK:
      Result := cxbsPressed;
    DXBAR_HOT:
      Result := cxbsHot;
    else
      Result := cxbsNormal;
  end;
end;

function RibbonStateToSkinElementState(AState: Integer): TdxSkinElementState;
const
  StateMap: array[0..8] of TdxSkinElementState = (
    esNormal, esDisabled, esHot, esActive, esPressed,
    esChecked, esChecked, esHotCheck, esActiveDisabled
  );
begin
  if (Low(StateMap) <= AState) and (High(StateMap) >= AState) then
    Result := StateMap[AState]
  else
    Result := esNormal;
end;

function SkinElementCheckState(AElement: TdxSkinElement; AState: Integer): TdxSkinElementState;
begin
  Result := dxSkinElementCheckState(AElement, RibbonStateToSkinElementState(AState));
end;

{ TdxSkinRibbonPainter }

constructor TdxSkinRibbonPainter.Create(APainter: TdxSkinLookAndFeelPainter);
begin
  FPainter := APainter;
  inherited Create;
end;

function TdxSkinRibbonPainter.AdjustCaptionFontSize(
  ASize: Integer; AUseAeroGlass: Boolean): Integer;
begin
  Result := inherited AdjustCaptionFontSize(ASize, AUseAeroGlass);
  if not AUseAeroGlass then
  begin
    if UseSkins and (SkinInfo.RibbonCaptionFontDelta <> nil) then
      Inc(Result, SkinInfo.RibbonCaptionFontDelta.Value);
  end;
end;

procedure TdxSkinRibbonPainter.AdjustRibbonFormBorderIconSize(
  AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean; var ASize: TSize);
var
  AElement: TdxSkinElement;
begin
  AElement := GetBorderIconElement(AIcon, AIsToolWindow);
  if AElement <> nil then
    ASize := TdxSkinElementHelper.CalculateCaptionButtonSize(ASize.cy, AElement);
end;

procedure TdxSkinRibbonPainter.CheckColorSchemeAccent(var AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if Style = rs2007 then
    AColorSchemeAccent := rcsaYellow;
end;

function TdxSkinRibbonPainter.CorrectTabHeaderRect(const R: TRect): TRect;
begin
  Result := cxRectInflate(R, -1, -2, -1, 0);
end;

function TdxSkinRibbonPainter.CorrectTabPanelRect(AIsInPopup: Boolean; const R: TRect): TRect;
begin
  Result := R;
  if AIsInPopup and (SkinInfo.RibbonTabPanelBottomIndent <> nil) then
    Inc(Result.Bottom, SkinInfo.RibbonTabPanelBottomIndent.Value);
end;

function TdxSkinRibbonPainter.GetApplicationButtonElement: TdxSkinElement;
begin
  if UseSkins then
    Result := SkinInfo.RibbonApplicationButton
  else
    Result := nil;
end;

function TdxSkinRibbonPainter.GetApplicationButtonIndent(const AName: string): Integer;
begin
  if UseSkins then
    Result := SkinInfo.GetIntegerPropertyValue(ApplicationButtonElement, AName)
  else
    Result := 0
end;

function TdxSkinRibbonPainter.GetApplicationMenuContentOffset(const ATabsBounds: TRect): TRect;
begin
  if not UseSkins or (SkinInfo.RibbonApplicationBackground = nil) or
    (SkinInfo.RibbonApplicationHeaderBackground = nil) or
    (SkinInfo.RibbonApplicationFooterBackground = nil)
  then
    Result := inherited GetApplicationMenuContentOffset(ATabsBounds)
  else
    Result := cxGetValueCurrentDPI(cxRect(
      SkinInfo.RibbonApplicationBackground.ContentOffset.Left,
      GetElementMinSize(SkinInfo.RibbonApplicationHeaderBackground).cy,
      SkinInfo.RibbonApplicationBackground.ContentOffset.Right,
      Max(30, GetElementMinSize(SkinInfo.RibbonApplicationFooterBackground).cy)));
end;

function TdxSkinRibbonPainter.GetName: string;
begin
  Result := SkinName;
end;

function TdxSkinRibbonPainter.GetBorderBounds(
  ASide: TcxBorder; const ABorders, ABounds: TRect): TRect;
begin
  Result := ABounds;
  case ASide of
    bLeft:
      begin
        Inc(Result.Top, ABorders.Top);
        Result.Right := Result.Left + ABorders.Left;
      end;
    bRight:
      begin
        Inc(Result.Top, ABorders.Top);
        Result.Left := Result.Right - ABorders.Right;
      end;
    bBottom:
      begin
        Result.Top := Result.Bottom - ABorders.Bottom;
        Dec(Result.Right, ABorders.Right);
        Inc(Result.Left, ABorders.Left);
      end;
    else
      Result.Bottom := ABorders.Top;
  end;
end;

function TdxSkinRibbonPainter.GetBorderIconElement(
  AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean): TdxSkinElement;
const
  RibbonIconsToSkinFormIcons: array[TdxRibbonBorderDrawIcon] of TdxSkinFormIcon =
    (sfiMinimize, sfiMaximize, sfiRestore, sfiClose, sfiHelp, sfiHelp, sfiHelp);
begin
  if not UseSkins then
    Result := nil
  else
    case AIcon of
      rbdiAutoHide:
        Result := SkinInfo.RibbonFormButtonAutoHideMode;
      rbdiAutoHideModeShowUI:
        Result := SkinInfo.RibbonFormButtonAutoHideModeShowUI;
      else
        Result := SkinInfo.FormIcons[not AIsToolWindow, RibbonIconsToSkinFormIcons[AIcon]];
    end;
end;

function TdxSkinRibbonPainter.GetBorderSkinElement(
  ASide: TcxBorder; AIsRectangular: Boolean): TdxSkinElement;
begin
  case ASide of
    bLeft:
      Result := SkinInfo.RibbonFormLeft[AIsRectangular];
    bTop:
      Result := SkinInfo.RibbonFormCaption;
    bRight:
      Result := SkinInfo.RibbonFormRight[AIsRectangular];
    bBottom:
      Result := SkinInfo.RibbonFormBottom[AIsRectangular];
    else
      Result := nil;
  end;
end;

function TdxSkinRibbonPainter.GetBordersWidth(AHasStatusBar: Boolean): TRect;

  function GetBorderSize(ASide: TcxBorder): TSize;
  var
    AElement: TdxSkinElement;
  begin
    AElement := GetBorderSkinElement(ASide, False);
    if AElement = nil then
      Result := cxNullSize
    else
      Result := AElement.Size;
  end;

  function GetBottomBorderSize: Integer;
  begin
    if not AHasStatusBar then
      Result := GetBorderSize(bBottom).cy
    else
      if SkinInfo.RibbonStatusBarBackground = nil then
        Result := 1
      else
        Result := SkinInfo.RibbonStatusBarBackground.ContentOffset.Bottom;
  end;

begin
  Result.Top := 0;
  Result.Left := GetBorderSize(bLeft).cx;
  Result.Right := GetBorderSize(bRight).cx;
  Result.Bottom := GetBottomBorderSize;
end;

function TdxSkinRibbonPainter.GetCustomizeButtonOutsizeQAT(AHasAppButton: Boolean): Boolean;
var
  AProperty: TdxSkinBooleanProperty;
begin
  Result := False;
  if UseSkins then
  begin
    AProperty := SkinInfo.RibbonQATCustomizeButtonOutsizeQAT[AHasAppButton];
    if AProperty <> nil then
      Result := AProperty.Value;
  end;
end;

function TdxSkinRibbonPainter.GetElementMinSize(AElement: TdxSkinElement): TSize;
begin
  with AElement.Image.Margins do
  begin
    Result.cx := Max(Left + Right, Max(AElement.MinSize.Width, AElement.Size.cx));
    Result.cy := Max(Top + Bottom, Max(AElement.MinSize.Height, AElement.Size.cy));
  end;
end;

function TdxSkinRibbonPainter.GetPopupMenuColor: TColor;
begin
  if SkinInfo.PopupMenu = nil then
    Result := clWhite
  else
    Result := SkinInfo.PopupMenu.Color;
end;

function TdxSkinRibbonPainter.GetSkinInfo: TdxSkinLookAndFeelPainterInfo;
begin
  Result := Painter.SkinInfo;
end;

function TdxSkinRibbonPainter.GetQATBackgroundElement(
  ABellow, AHasApplicationButton: Boolean): TdxSkinElement;
begin
  if not UseSkins then
    Result := nil
  else
    if ABellow then
      Result := SkinInfo.RibbonQuickToolbarBelow
    else
      Result := SkinInfo.RibbonQuickToolbar[AHasApplicationButton];
end;

function TdxSkinRibbonPainter.GetQATLeftOffset(AHasApplicationButton: Boolean): Integer;
const
  QATOffsetDelta = 10;
begin
  if UseSkins then
  begin
    Result := QATOffsetDelta + GetApplicationButtonIndent(sdxRibbonAppButtonRightIndent) +
      SkinInfo.GetIntegerPropertyValue(GetQATBackgroundElement(False, AHasApplicationButton),
        sdxRibbonQuickAccessToolbarOffset);
  end
  else
    Result := 0;
end;

function TdxSkinRibbonPainter.GetTabAeroSupport: Boolean;
begin
  Result := UseSkins and Assigned(SkinInfo.RibbonTabAeroSupport) and
    SkinInfo.RibbonTabAeroSupport.Value;
end;

function TdxSkinRibbonPainter.GetUseSkins: Boolean;
begin
  Result := cxUseSkins;
end;

procedure TdxSkinRibbonPainter.DrawApplicationButton(DC: HDC; const R: TRect;
  AState: TdxRibbonApplicationButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  dxApplicationButtonStateToElementState: array[TdxRibbonApplicationButtonState] of
    TdxSkinElementState = (esNormal, esHot, esPressed);
begin
  CheckColorSchemeAccent(AColorSchemeAccent);
  if ApplicationButtonElement = nil then
    inherited DrawApplicationButton(DC, R, AState, AColorSchemeAccent)
  else
    ApplicationButtonElement.Draw(DC, R, Ord(AColorSchemeAccent), dxApplicationButtonStateToElementState[AState]);
end;

procedure TdxSkinRibbonPainter.DrawApplicationMenuButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  ButtonState: array [Boolean] of TdxSkinElementState = (esNormal, esHot);
begin
  if not UseSkins or (SkinInfo.ButtonElements = nil) then
    inherited DrawApplicationMenuButton(DC, R, AState, AColorSchemeAccent)
  else
    SkinInfo.ButtonElements.Draw(DC, R, 0, ButtonState[AState = DXBAR_HOT]);
end;

procedure TdxSkinRibbonPainter.DrawApplicationMenuExtraPaneButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not UseSkins or (SkinInfo.RibbonExtraPaneButton = nil) then
    inherited DrawApplicationMenuExtraPaneButton(DC, R, AState, AColorSchemeAccent)
  else
    SkinInfo.RibbonExtraPaneButton.Draw(DC, R, 0, RibbonStateToSkinElementState(AState));
end;

procedure TdxSkinRibbonPainter.DrawApplicationMenuExtraPanePinButtonGlyph(
  DC: HDC; const R: TRect; AState: Integer; AChecked: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not UseSkins or (SkinInfo.RibbonExtraPanePinButtonGlyph = nil) then
    inherited DrawApplicationMenuExtraPanePinButtonGlyph(DC, R, AState, AChecked, AColorSchemeAccent)
  else
    SkinInfo.RibbonExtraPanePinButtonGlyph.Draw(DC, R, Ord(AChecked));
end;

procedure TdxSkinRibbonPainter.DrawApplicationMenuBackground(
  DC: HDC; const R, AContentRect: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  if not UseSkins or (SkinInfo.RibbonApplicationBackground = nil) or
     (SkinInfo.RibbonApplicationFooterBackground = nil) or
     (SkinInfo.RibbonApplicationHeaderBackground = nil)
  then
    inherited DrawApplicationMenuBackground(DC, R, AContentRect, AColorSchemeAccent)
  else
  begin
    R1 := cxRect(R.Left, R.Top, R.Right, AContentRect.Top);
    DrawTabAreaBackground(DC, R1, True, False, ramsShownAsMenu);
    SkinInfo.RibbonApplicationHeaderBackground.Draw(DC, R1);

    R1 := cxRect(R.Left, AContentRect.Bottom, R.Right, R.Bottom);
    DrawTabAreaBackground(DC, R1, True, False, ramsShownAsMenu);
    SkinInfo.RibbonApplicationFooterBackground.Draw(DC, R1);

    R1 := cxRect(R.Left, AContentRect.Top, R.Right, AContentRect.Bottom);
    if SkinInfo.RibbonApplicationBackground.IsAlphaUsed then
      FillRectByColor(DC, R1, PopupMenuColor);
    SkinInfo.RibbonApplicationBackground.Draw(DC, R1);

    R1.Left := R.Left + SkinInfo.RibbonApplicationBackground.ContentOffset.Left;
    R1.Right := AContentRect.Left;
    FillRectByColor(DC, R1, PopupMenuColor);

    R1.Right := R.Right - SkinInfo.RibbonApplicationBackground.ContentOffset.Right;
    R1.Left := AContentRect.Right;
    FillRectByColor(DC, R1, GetPartColor(DXBAR_MENUEXTRAPANE));
  end;
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewBackButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if UseSkins and (SkinInfo.RibbonBackstageViewBackButton <> nil) then
  begin
    SkinInfo.RibbonBackstageViewBackButton.Draw(DC,
      cxRectCenter(R, SkinInfo.RibbonBackstageViewBackButton.MinSize.Size), 0,
      RibbonStateToSkinElementState(AState));
  end
  else
    inherited DrawBackstageViewBackButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  ALogoRect: TRect;
  AOffsets: TRect;
begin
  if UseSkins and (SkinInfo.RibbonBackstageView <> nil) then
  begin
    SkinInfo.RibbonBackstageView.UseCache := True;

    FillRectByColor(DC, R, SkinInfo.RibbonBackstageView.Color);
    if SkinInfo.RibbonBackstageViewImage <> nil then
    begin
      ALogoRect := R;
      ALogoRect.Left := ALogoRect.Right - SkinInfo.RibbonBackstageViewImage.Size.cx;
      ALogoRect.Top := ALogoRect.Bottom - SkinInfo.RibbonBackstageViewImage.Size.cy;
      SkinInfo.RibbonBackstageViewImage.Draw(DC, ALogoRect);
    end;

    AOffsets := GetPartContentOffsets(DXBAR_BACKSTAGEVIEW);
    if not cxRectIsEqual(AOffsets, cxNullRect) then
    begin
      cxPaintCanvas.BeginPaint(DC);
      try
        CheckColorSchemeAccent(AColorSchemeAccent);
        cxPaintCanvas.ExcludeClipRect(cxRectContent(R, AOffsets));
        SkinInfo.RibbonBackstageView.Draw(DC, R, Ord(AColorSchemeAccent));
      finally
        cxPaintCanvas.EndPaint;
      end;
    end;
  end
  else
    inherited DrawBackstageViewBackground(DC, R, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewMenuBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonBackstageViewMenu) then
    inherited DrawBackstageViewMenuBackground(DC, R, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewMenuButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  CheckColorSchemeAccent(AColorSchemeAccent);
  if not DrawElement(DC, R, AState, SkinInfo.RibbonBackstageViewMenuButton, Ord(AColorSchemeAccent)) then
    inherited DrawBackstageViewMenuButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewMenuHeader(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonBackstageViewMenuHeader) then
    inherited DrawBackstageViewMenuHeader(DC, R, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewMenuSeparator(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, AState, SkinInfo.RibbonBackstageViewMenuSeparator) then
    inherited DrawBackstageViewMenuSeparator(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewTabButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  AArrowRect: TRect;
  AArrowSize: TSize;
begin
  CheckColorSchemeAccent(AColorSchemeAccent);
  if DrawElement(DC, R, AState, SkinInfo.RibbonBackstageViewTab, Ord(AColorSchemeAccent)) then
  begin
    case AState of
      DXBAR_CHECKED, DXBAR_HOTCHECK, DXBAR_PRESSED:
        if SkinInfo.RibbonBackstageViewTabArrow <> nil then
        begin
          AArrowSize := SkinInfo.RibbonBackstageViewTabArrow.Size;
          AArrowRect := cxRectCenterVertically(R, AArrowSize.cy);
          AArrowRect := cxRectSetRight(AArrowRect, AArrowRect.Right, AArrowSize.cx);
          SkinInfo.RibbonBackstageViewTabArrow.Draw(DC, AArrowRect);
        end;
    end;
  end
  else
    inherited DrawBackstageViewTabButton(DC, R, AState, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewGalleryBackground(DC: HDC; const R: TRect);
begin
  if UseSkins and (SkinInfo.RibbonBackstageView <> nil) then
    FillRectByColor(DC, R, SkinInfo.RibbonBackstageView.Color)
  else
    inherited DrawBackstageViewGalleryBackground(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewGalleryItem(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if UseSkins and (SkinInfo.GalleryItem <> nil) then
    SkinInfo.GalleryItem.Draw(DC, R, 0, RibbonStateToSkinElementState(AState))
  else
    inherited DrawBackstageViewGalleryItem(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawBackstageViewGallerySeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if UseSkins then
  begin
    cxPaintCanvas.BeginPaint(DC);
    try
      Painter.DrawLabelLine(cxPaintCanvas, R, clDefault, clDefault, False);
    finally
      cxPaintCanvas.EndPaint;
    end;
  end
  else
    inherited DrawBackstageViewGallerySeparator(DC, R, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawButtonGroup(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DoDrawButtonGroupElement(DC, R, AState, SkinInfo.RibbonButtonGroupButton) then
    inherited DrawButtonGroup(DC, R, AState, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawButtonGroupDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DoDrawButtonGroupElement(DC, R, AState, SkinInfo.RibbonButtonGroupSplitButtonRight) then
    inherited DrawButtonGroupDropButtonArrowPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawButtonGroupDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DoDrawButtonGroupElement(DC, R, AState, SkinInfo.RibbonButtonGroupSplitButtonLeft) then
    inherited DrawButtonGroupDropButtonMainPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawButtonGroupBackground(DC: HDC; const R: TRect);
begin
  if SkinInfo.RibbonButtonGroup <> nil then
  begin
    with SkinInfo.RibbonButtonGroup.Image.Margins do
      DrawClippedElement(DC, R, cxRectInflate(R, Left, 0, Right, 0), SkinInfo.RibbonButtonGroup, esNormal);
  end;
end;

procedure TdxSkinRibbonPainter.DrawButtonGroupSplitButtonSeparator(
  DC: HDC; const R: TRect; AState: Integer);
begin
  if UseSkins then
    DrawButtonGroupBackground(DC, R)
  else
    inherited DrawButtonGroupSplitButtonSeparator(DC, R, AState)
end;

procedure TdxSkinRibbonPainter.DrawButtonGroupBorderLeft(DC: HDC; const R: TRect);
var
  ARect: TRect;
begin
  if UseSkins and (SkinInfo.RibbonButtonGroup <> nil) then
  begin
    ARect := R;
    ARect.Right := Max(R.Left + SkinInfo.RibbonButtonGroup.Size.cx, R.Right);
    DrawClippedElement(DC, R, ARect, SkinInfo.RibbonButtonGroup, esNormal);
  end
  else
    inherited DrawButtonGroupBorderLeft(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawButtonGroupBorderRight(DC: HDC; const R: TRect);
var
  ARect: TRect;
begin
  if UseSkins and (SkinInfo.RibbonButtonGroup <> nil) then
  begin
    if not IsRectEmpty(R) then
    begin
      ARect := R;
      ARect.Left := Min(R.Left, R.Right - SkinInfo.RibbonButtonGroup.Size.cx);
      DrawClippedElement(DC, R, ARect, SkinInfo.RibbonButtonGroup, esNormal, roSet);
    end;
  end
  else
    inherited DrawButtonGroupBorderRight(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawButtonGroupBorderMiddle(
  DC: HDC; const R: TRect; AState: Integer);
begin
  if UseSkins and (SkinInfo.RibbonButtonGroupSeparator <> nil) then
    SkinInfo.RibbonButtonGroupSeparator.Draw(DC, R, 0, RibbonStateToSkinElementState(AState))
  else
    inherited DrawButtonGroupBorderMiddle(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawCollapsedToolbarBackground(
  DC: HDC; const R: TRect; AState: Integer);
begin
  if UseSkins and (SkinInfo.RibbonCollapsedToolBarBackground <> nil) then
    SkinInfo.RibbonCollapsedToolBarBackground.Draw(DC, R, 0, RibbonStateToSkinElementState(AState))
  else
    inherited DrawCollapsedToolbarBackground(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawCollapsedToolbarGlyphBackground(
  DC: HDC; const R: TRect; AState: Integer);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonCollapsedToolBarGlyphBackground) then
    inherited DrawCollapsedToolbarGlyphBackground(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawContextTabSeparator(
  DC: HDC; const R: TRect; ABeginGroup: Boolean);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonContextualTabSeparator) then
    inherited DrawContextTabSeparator(DC, R, ABeginGroup);
end;

procedure TdxSkinRibbonPainter.DrawContextTabBackground(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  ARect: TRect;
begin
  if UseSkins and (SkinInfo.RibbonContextualTabHeader <> nil) then
  begin
    if SkinInfo.RibbonContextualTabHeader.ImageCount > 1 then
      DrawColoredElement(DC, R, AColor, SkinInfo.RibbonContextualTabHeader, RibbonTabStatesMap[AState])
    else
    begin
      ARect := CorrectTabHeaderRect(R);
      dxGpFillRect(DC, ARect, AColor);
      SkinInfo.RibbonContextualTabHeader.Draw(DC, ARect, 0, RibbonTabStatesMap[AState]);
    end;
  end
  else
    inherited DrawContextTabBackground(DC, R, AState, AColor, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawContextTabGroupsArea(
  DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean);
var
  ABitmap: TcxBitmap32;
begin
  if UseSkins and (SkinInfo.RibbonContextualTabPanel <> nil) then
  begin
    DrawElement(DC, R, SkinInfo.RibbonContextualTabPanel);
    if SkinInfo.RibbonContextualTabPanel.ImageCount > 1 then
    begin
      ABitmap := TcxBitmap32.CreateSize(R, True);
      try
        SkinInfo.RibbonContextualTabPanel.Draw(ABitmap.Canvas.Handle, ABitmap.ClientRect, 1);
        cxMakeColoredBitmap(ABitmap, AContextColor);
        cxAlphaBlend(DC, ABitmap, R, ABitmap.ClientRect);
      finally
        ABitmap.Free;
      end;
    end;
  end
  else
    inherited DrawContextTabGroupsArea(DC, R, AContextColor, AIsQATAtBottom, AIsInPopup)
end;

procedure TdxSkinRibbonPainter.DrawContextBackground(DC: HDC; const R: TRect; AColor: TColor);
var
  ARect: TRect;
  ASaveIndex: Integer;
begin
  if UseSkins and (SkinInfo.RibbonContextualTabLabel <> nil) then
  begin
    ASaveIndex := SaveDC(DC);
    try
      ARect := R;
      Inc(ARect.Bottom);
      IntersectClipRect(DC, ARect.Left, ARect.Top + 1, ARect.Right, ARect.Bottom);
      if SkinInfo.RibbonContextualTabLabel.ImageCount > 1 then
        DrawColoredElement(DC, ARect, AColor, SkinInfo.RibbonContextualTabLabel, esNormal)
      else
      begin
        FillRectByColor(DC, ARect, AColor);
        SkinInfo.RibbonContextualTabLabel.Draw(DC, ARect);
      end;
    finally
      RestoreDC(DC, ASaveIndex)
    end;
  end
  else
    inherited DrawContextBackground(DC, R, AColor);
end;

procedure TdxSkinRibbonPainter.DrawContextBackgroundGlass(DC: HDC; const R: TRect; AColor: TColor);
begin
  if UseSkins and (SkinInfo.RibbonContextualTabLabelOnGlass <> nil) then
  begin
    if SkinInfo.RibbonContextualTabLabelOnGlass.ImageCount > 1 then
      DrawColoredElement(DC, R, AColor, SkinInfo.RibbonContextualTabLabelOnGlass, esNormal)
    else
    begin
      dxGpFillRectByGradient(DC, R, 0, AColor, LinearGradientModeVertical, 0, 220);
      SkinInfo.RibbonContextualTabLabelOnGlass.Draw(DC, R)
    end;
  end
  else
    inherited DrawContextBackgroundGlass(DC, R, AColor);
end;

procedure TdxSkinRibbonPainter.DrawEditArrowButton(DC: HDC; const R: TRect; AState: Integer);
begin
  if not DoDrawEditButtonGlyph(DC, R, AState, cxbkComboBtn) then
    inherited DrawEditArrowButton(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawEditButton(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if UseSkins then
  begin
    cxPaintCanvas.BeginPaint(DC);
    Painter.DrawEditorButton(cxPaintCanvas, R, cxbkEditorBtn, RibbonStateToButtonState(AState));
    cxPaintCanvas.EndPaint;
  end
  else
    inherited DrawEditButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawEditEllipsisButton(DC: HDC; const R: TRect; AState: Integer);
begin
  if not DoDrawEditButtonGlyph(DC, R, AState, cxbkEllipsisBtn) then
    inherited DrawEditEllipsisButton(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawEditSpinDownButton(DC: HDC; const R: TRect; AState: Integer);
begin
  if not DoDrawEditButtonGlyph(DC, R, AState, cxbkSpinDownBtn) then
    inherited DrawEditSpinDownButton(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawEditSpinUpButton(DC: HDC; const R: TRect; AState: Integer);
begin
  if not DoDrawEditButtonGlyph(DC, R, AState, cxbkSpinUpBtn) then
    inherited DrawEditSpinUpButton(DC, R, AState);
end;

function TdxSkinRibbonPainter.DrawElement(DC: HDC; const R: TRect; AElement: TdxSkinElement): Boolean;
begin
  Result := UseSkins and (AElement <> nil);
  if Result then
    AElement.Draw(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawProgressDiscreteBand(DC: HDC; const R: TRect);
var
  AElement: TdxSkinElement;
  ARect: TRect;

  function CheckRect(const R: TRect): TRect;
  begin
    Result := R;
    if SkinInfo.ProgressBarElements[False, False] <> nil then
    begin
      InflateRect(Result, 0, 2);
      with SkinInfo.ProgressBarElements[False, False].ContentOffset.Rect do
      begin
        Inc(Result.Top, Top);
        Dec(Result.Bottom, Bottom);
      end;
    end;
  end;

begin
  if UseSkins then
    AElement := SkinInfo.ProgressBarElements[True, False]
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawProgressDiscreteBand(DC, R)
  else
  begin
    ARect := CheckRect(R);
    with AElement.Image.Margins.Margin do
    begin
      Dec(ARect.Left, Left);
      Inc(ARect.Right, Right);
    end;
    DrawClippedElement(DC, R, ARect, AElement, esNormal);
  end;
end;

procedure TdxSkinRibbonPainter.DrawProgressSolidBand(DC: HDC; const R: TRect);
var
  AElement: TdxSkinElement;
  ARect: TRect;
begin
  if UseSkins then
    AElement := SkinInfo.ProgressBarElements[True, False]
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawProgressDiscreteBand(DC, R)
  else
  begin
    ARect := R;
    if SkinInfo.ProgressBarElements[False, False] <> nil then
    begin
      InflateRect(ARect, 2, 2);
      ARect := cxRectContent(ARect, SkinInfo.ProgressBarElements[False, False].ContentOffset.Rect);
    end;
    DrawClippedElement(DC, R, ARect, AElement, esNormal);
  end;
end;

procedure TdxSkinRibbonPainter.DrawProgressSubstrate(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.ProgressBarElements[False, False]) then
    inherited DrawProgressSubstrate(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawDropDownBorder(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.PopupMenu) then
    inherited DrawDropDownBorder(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawDropDownGalleryBackground(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonGalleryBackground) then
    inherited DrawDropDownGalleryBackground(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawDropDownGalleryBottomSizeGrip(DC: HDC; const R: TRect);
var
  ARect: TRect;
begin
  if UseSkins and (SkinInfo.RibbonGallerySizeGrips <> nil) then
  begin
    ARect := cxRectInflate(R, 0, -3, -2, -1);
    ARect.Left := ARect.Right - cxRectHeight(ARect);
    SkinInfo.RibbonGallerySizeGrips.Draw(DC, ARect, 1);
  end
  else
    inherited DrawDropDownGalleryBottomSizeGrip(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawDropDownGalleryBottomSizingBand(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonGallerySizingPanel) then
    inherited DrawDropDownGalleryBottomSizingBand(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawDropDownGalleryBottomVerticalSizeGrip(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonGallerySizeGrips) then
    inherited DrawDropDownGalleryBottomVerticalSizeGrip(DC, R)
end;

procedure TdxSkinRibbonPainter.DrawDropDownGalleryTopSizingBand(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonGallerySizingPanel) then
    inherited DrawDropDownGalleryTopSizingBand(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawDropDownGalleryTopSizeGrip(DC: HDC; const R: TRect);
var
  ARect: TRect;
begin
  if UseSkins and (SkinInfo.RibbonGallerySizeGrips <> nil) then
  begin
    ARect := cxRectInflate(R, 0, -3, -2, -1);
    ARect.Left := ARect.Right - cxRectHeight(ARect);
    SkinInfo.RibbonGallerySizeGrips.Draw(DC, ARect, 2);
  end
  else
    inherited DrawDropDownGalleryTopSizingBand(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawDropDownGalleryTopVerticalSizeGrip(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonGallerySizeGrips) then
    inherited DrawDropDownGalleryTopVerticalSizeGrip(DC, R)
end;

procedure TdxSkinRibbonPainter.DrawGalleryFilterBandBackground(DC: HDC; const R: TRect);
begin
  DrawGalleryGroupHeaderBackground(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawGalleryGroupHeaderBackground(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonGalleryGroupCaption) then
    inherited DrawGalleryGroupHeaderBackground(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawInRibbonGalleryBackground(
  DC: HDC; const R: TRect; AState: Integer);
var
  R1: TRect;
begin
  if UseSkins and (SkinInfo.RibbonGalleryPane <> nil) then
  begin
    R1 := R;
    Inc(R1.Right, SkinInfo.RibbonGalleryPane.Image.Margins.Right);
    DrawClippedElement(DC, R, R1, SkinInfo.RibbonGalleryPane, RibbonStateToSkinElementState(AState));
  end
  else
    inherited DrawInRibbonGalleryBackground(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawInRibbonGalleryScrollBarButton(
  DC: HDC; const R: TRect; AButtonKind: TdxInRibbonGalleryScrollBarButtonKind;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  AElement: TdxSkinElement;
begin
  AElement := nil;
  if UseSkins then
  begin
    case AButtonKind of
      gsbkLineUp:
        AElement := SkinInfo.RibbonGalleryButtonUp;
      gsbkLineDown:
        AElement := SkinInfo.RibbonGalleryButtonDown;
      gsbkDropDown:
        AElement := SkinInfo.RibbonGalleryButtonDropDown;
    end;
  end;

  if AElement = nil then
    inherited DrawInRibbonGalleryScrollBarButton(DC, R, AButtonKind, AState, AColorSchemeAccent)
  else
    AElement.Draw(DC, R, 0, RibbonStateToSkinElementState(AState));
end;

procedure TdxSkinRibbonPainter.DrawInRibbonGalleryScrollBarBackground(
  DC: HDC; const R: TRect; AState: Integer);
var
  R1: TRect;
  AElement: TdxSkinElement;
begin
  if UseSkins then
    AElement := SkinInfo.RibbonGalleryPane
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawInRibbonGalleryScrollBarBackground(DC, R, AState)
  else
  begin
    R1 := R;
    Dec(R1.Left, Max(AElement.Size.cx, AElement.Image.Margins.Left));
    DrawClippedElement(DC, R, R1, AElement, RibbonStateToSkinElementState(AState));
  end;
end;

procedure TdxSkinRibbonPainter.DrawArrowDown(DC: HDC; const R: TRect; AState: Integer);
const
  StateMap: array[0..8] of TdxSkinElementState = (esNormal, esDisabled,
    esHot, esActive, esNormal, esNormal, esNormal, esNormal, esNormal
  );
begin
  if UseSkins and (SkinInfo.RibbonButtonArrow <> nil) then
    SkinInfo.RibbonButtonArrow.Draw(DC, R, 0, StateMap[AState])
  else
    inherited DrawArrowDown(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawClippedElement(DC: HDC; const R: TRect;
  const ASource: TRect; AElement: TdxSkinElement; AState: TdxSkinElementState = esNormal;
  AOperation: TcxRegionOperation = roIntersect; AImageIndex: Integer = 0);
begin
  if not cxRectIsEmpty(R) then
  begin
    cxPaintCanvas.BeginPaint(DC);
    try
      cxPaintCanvas.SetClipRegion(TcxRegion.Create(R), AOperation);
      AElement.Draw(cxPaintCanvas.Handle, ASource, AImageIndex, AState);
    finally
      cxPaintCanvas.EndPaint;
    end;
  end;
end;

procedure TdxSkinRibbonPainter.DrawColoredElement(DC: HDC; const R: TRect;
  AColor: TColor; AElement: TdxSkinElement; AState: TdxSkinElementState);
var
  ABitmap: TcxBitmap32;
begin
  ABitmap := TcxBitmap32.CreateSize(R, True);
  try
    AElement.Draw(ABitmap.Canvas.Handle, ABitmap.ClientRect, 0, AState);
    cxMakeColoredBitmap(ABitmap, AColor);
    AElement.Draw(ABitmap.Canvas.Handle, ABitmap.ClientRect, 1, AState);
    cxAlphaBlend(DC, ABitmap, R, ABitmap.ClientRect);
  finally
    ABitmap.Free;
  end;
end;

function TdxSkinRibbonPainter.DoDrawButtonGroupElement(
  DC: HDC; const R: TRect; AState: Integer; AElement: TdxSkinElement): Boolean;
begin
  Result := UseSkins and (AElement <> nil);
  if Result then
  begin
    DrawButtonGroupBackground(DC, R);
    DrawElement(DC, R, AState, AElement);
  end;
end;

function TdxSkinRibbonPainter.DoDrawEditButtonGlyph(DC: HDC;
  const R: TRect; AState: Integer; AButtonKind: TcxEditBtnKind): Boolean;
const
  ButtonState: array [DXBAR_NORMAL..DXBAR_ACTIVEDISABLED] of TcxButtonState = (
    cxbsNormal, cxbsDisabled, cxbsHot, cxbsNormal, cxbsPressed, cxbsPressed,
    cxbsDefault, cxbsDefault, cxbsDisabled);
begin
  Result := UseSkins;
  if Result then
  begin
    cxPaintCanvas.BeginPaint(DC);
    try
      Painter.DrawEditorButtonGlyph(cxPaintCanvas, R, AButtonKind, ButtonState[AState]);
    finally
      cxPaintCanvas.EndPaint;
    end;
  end;
end;

function TdxSkinRibbonPainter.DrawElement(DC: HDC; const R: TRect;
  AState: Integer; AElement: TdxSkinElement; AImageIndex: Integer = 0): Boolean;
begin
  Result := UseSkins and (AElement <> nil);
  if Result then
    AElement.Draw(DC, R, AImageIndex, SkinElementCheckState(AElement, AState));
end;

function TdxSkinRibbonPainter.DoDrawStatusBarBackground(
  DC: HDC; const R, AVisibleArea: TRect; AIsRaised: Boolean): Boolean;
var
  AElement: TdxSkinElement;
  AIndents: TRect;
begin
  if UseSkins then
    AElement := SkinInfo.RibbonStatusBarBackground
  else
    AElement := nil;

  Result := AElement <> nil;
  if Result then
  begin
    AIndents := GetBordersWidth(True);
    AIndents.Top := 0;
    if AIsRaised and AElement.IsAlphaUsed then
      DrawClippedElement(DC, AVisibleArea, cxRectInflate(R, AIndents), AElement, esNormal, roIntersect, 0);
    DrawClippedElement(DC, AVisibleArea, cxRectInflate(R, AIndents), AElement, esNormal, roIntersect, Integer(AIsRaised));
  end;
end;

function TdxSkinRibbonPainter.DoDrawStatusBarPart(
  DC: HDC; const R: TRect; AIsRaised, AActive, AIsLeft: Boolean): Boolean;

  function CalculateDestRect(AElement: TdxSkinElement): TRect;
  var
    AMinSize: TSize;
  begin
    AMinSize := GetElementMinSize(AElement);
    Result := cxRectSetBottom(R, R.Bottom, Max(AMinSize.cy, cxRectHeight(R)));
    if AIsLeft then
      Result.Right := Max(Result.Left + AMinSize.cx, Result.Right + AElement.Image.Margins.Right)
    else
      Result.Left := Min(Result.Right - AMinSize.cx, Result.Left - AElement.Image.Margins.Left);
  end;

const
  StateMap: array[Boolean] of TdxSkinElementState = (esActiveDisabled, esActive);
begin
  Result := UseSkins and (SkinInfo.RibbonStatusBarBackground <> nil);
  if Result then
  begin
    cxPaintCanvas.BeginPaint(DC);
    try
      cxPaintCanvas.IntersectClipRect(R);
      SkinInfo.RibbonStatusBarBackground.Draw(cxPaintCanvas.Handle,
        CalculateDestRect(SkinInfo.RibbonStatusBarBackground),
        Integer(AIsRaised and not AIsLeft), StateMap[AActive]);
    finally
      cxPaintCanvas.EndPaint;
    end;
  end;
end;

function TdxSkinRibbonPainter.DoDrawStatusBarRectangularPart(
  DC: HDC; const R: TRect; AIsRaised, AActive, AIsLeft: Boolean): Boolean;
const
  SideMap: array[Boolean] of TcxBorder = (bRight, bLeft);
begin
  Result := UseSkins;
  if Result then
  begin
    DrawFormBorder(DC, SideMap[AIsLeft], Rect(cxRectWidth(R), 0, cxRectWidth(R), 0),
      R, GetBorderSkinElement(SideMap[AIsLeft], True), AActive);
  end;
end;

procedure TdxSkinRibbonPainter.DrawFormBorders(
  DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo);

  procedure DrawBottomCorner(ASide: TcxBorder; R: TRect);
  var
    ABitmap: TcxBitmap;
    AElement: TdxSkinElement;
  begin
    AElement := GetBorderSkinElement(ASide, IsRectangularFormBottom(AInfo.FormData));
    if Assigned(AElement) then
    begin
      ABitmap := TcxBitmap.CreateSize(R);
      try
        ABitmap.cxCanvas.WindowOrg := R.TopLeft;
        Dec(R.Top, AElement.Size.cy);
        AElement.Draw(ABitmap.Canvas.Handle, R, Integer(not AInfo.FormData.Active));
        cxBitBlt(DC, ABitmap.Canvas.Handle, R, cxNullPoint, SRCCOPY);
      finally
        ABitmap.Free;
      end;
    end;
  end;

  procedure DrawBorder(ASide: TcxBorder; const ABordersWidth: TRect);
  begin
    if (ASide = bBottom) and AInfo.HasStatusBar then
      DrawStatusBarFormBorder(DC, AInfo.FormData, ABordersWidth)
    else
      DrawFormBorder(DC, ASide, ABordersWidth, AInfo.FormData.Bounds,
        GetBorderSkinElement(ASide, IsRectangularFormBottom(AInfo.FormData)),
        AInfo.FormData.Active);
  end;

  procedure DrawBorders(const ABordersWidth: TRect);
  var
    ASide: TcxBorder;
    R: TRect;
  begin
    for ASide := Low(TcxBorder) to High(TcxBorder) do
      DrawBorder(ASide, ABordersWidth);
    if ABordersWidth.Bottom > 1 then
    begin
      R := AInfo.FormData.Bounds;
      R.Top := R.Bottom - ABordersWidth.Bottom;
      DrawBottomCorner(bLeft, cxRectSetWidth(R, 4));
      DrawBottomCorner(bRight, cxRectSetLeft(R, R.Right - 4, 4));
    end;
  end;

var
  ABorders: TRect;
begin
  if UseSkins then
  begin
    cxPaintCanvas.BeginPaint(DC);
    try
      cxPaintCanvas.ExcludeClipRect(cxRectContent(AInfo.FormData.Bounds, ABordersWidth));
      ABorders := ABordersWidth;
      if TabAeroSupport then
        Inc(ABorders.Top, AInfo.TabsHeight);
      Inc(ABorders.Top, AInfo.CaptionHeight);
      DrawBorders(ABorders);
    finally
      cxPaintCanvas.EndPaint;
    end;
  end
  else
    inherited DrawFormBorders(DC, ABordersWidth, AInfo);
end;

procedure TdxSkinRibbonPainter.DrawFormBorder(DC: HDC; ASide: TcxBorder;
  const ABorderWidths, R: TRect; AElement: TdxSkinElement; AActive: Boolean);

  procedure CorrectBorderSourceRect(var R: TRect; const ASize: TSize);
  begin
    case ASide of
      bTop:
        R.Bottom := Max(R.Bottom, R.Top + ASize.cy);
      bLeft:
        R.Right := Max(R.Right, R.Left + ASize.cx);
      bRight:
        R.Left := Min(R.Left, R.Right - ASize.cx);
      bBottom:
        R.Top := Min(R.Top, R.Bottom - ASize.cy);
    end;
  end;

var
  ABorderRect: TRect;
  ASaveIndex: Integer;
begin
  if Assigned(AElement) and not IsRectEmpty(R) then
  begin
    ASaveIndex := SaveDC(DC);
    try
      ABorderRect := GetBorderBounds(ASide, ABorderWidths, R);
      IntersectClipRect(DC, ABorderRect.Left, ABorderRect.Top, ABorderRect.Right, ABorderRect.Bottom);
      CorrectBorderSourceRect(ABorderRect, AElement.Size);
      AElement.UseCache := True;
      AElement.Draw(DC, ABorderRect, Integer(not AActive), RibbonFormBorderStates[AActive]);
    finally
      RestoreDC(DC, ASaveIndex);
    end;
  end;
end;

procedure TdxSkinRibbonPainter.DrawStatusBarFormBorder(
  DC: HDC; const AData: TdxRibbonFormData; const ABorders: TRect);
var
  R, R1: TRect;
begin
  if UseSkins then
  begin
    if Assigned(SkinInfo.RibbonStatusBarBackground) and (ABorders.Bottom > 1) then
    begin
      R1 := cxRectSetTop(AData.Bounds, AData.Bounds.Bottom - ABorders.Bottom - 1, ABorders.Bottom);
      R := R1;
      Dec(R.Top, SkinInfo.RibbonStatusBarBackground.Size.cy - ABorders.Bottom);
      DrawClippedElement(DC, R1, R, SkinInfo.RibbonStatusBarBackground, esNormal);
    end;
    DrawFormBorder(DC, bBottom, Rect(ABorders.Left, 0, ABorders.Right, 1), AData.Bounds,
      GetBorderSkinElement(bBottom, IsRectangularFormBottom(AData)), AData.Active);
  end;
end;

procedure TdxSkinRibbonPainter.DrawStatusBarGripBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  AElement: TdxSkinElement;
  ALeftIndent, ARightIndent: Integer;
  R1: TRect;
begin
  if UseSkins then
    AElement := SkinInfo.RibbonStatusBarBackground
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawStatusBarGripBackground(DC, R, AColorSchemeAccent)
  else
    if not AElement.IsAlphaUsed then
    begin
      GetElementContentIndents(AElement, False, ALeftIndent, ARightIndent);
      R1 := GetBordersWidth(True);
      R1.Top := 0;
      R1.Left := ALeftIndent;
      DrawClippedElement(DC, R, cxRectInflate(R, R1), AElement, esNormal, roIntersect, 1);
    end;
end;

procedure TdxSkinRibbonPainter.DrawFormBorderIcon(DC: HDC; const R: TRect;
  AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  RibbonIconStateToSkinElementState: array[TdxRibbonBorderIconState] of TdxSkinElementState =
    (esNormal, esHot, esPressed, esActive, esHot);
var
  AElement: TdxSkinElement;
begin
  AElement := GetBorderIconElement(AIcon, False);
  if AElement = nil then
    inherited DrawFormBorderIcon(DC, R, AIcon, AState, AColorSchemeAccent)
  else
    AElement.Draw(DC, cxRectInflate(R, -1, -1), 0, RibbonIconStateToSkinElementState[AState]);
end;

procedure TdxSkinRibbonPainter.DrawFormCaption(
  DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo);
var
  AElement: TdxSkinElement;
begin
  AElement := nil;
  if UseSkins then
  begin
    if AInfo.IsRibbonHidden then
      AElement := SkinInfo.RibbonFormCaptionRibbonHidden;
    if AElement = nil then
      AElement := SkinInfo.RibbonFormCaption;
  end;

  if AElement = nil then
    inherited DrawFormCaption(DC, R, AInfo)
  else
  begin
    AElement.UseCache := True;
    AElement.Draw(DC, R, Byte(not AInfo.FormData.Active));
  end;
end;

procedure TdxSkinRibbonPainter.DrawFormStatusBarPart(DC: HDC; const R: TRect;
  AIsLeft, AIsActive, AIsRaised, AIsRectangular: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  AHandled: Boolean;
begin
  if AIsRectangular and UseRoundedWindowCorners then
    AHandled := DoDrawStatusBarRectangularPart(DC, R, AIsRaised, AIsActive, AIsLeft)
  else
    AHandled := DoDrawStatusBarPart(DC, R, AIsRaised, AIsActive, AIsLeft);

  if not AHandled then
    inherited DrawFormStatusBarPart(DC, R, AIsLeft, AIsActive, AIsRaised, AIsRectangular, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawLargeButton(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, AState, SkinInfo.RibbonLargeButton) then
    inherited DrawLargeButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawLargeButtonDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, AState, SkinInfo.RibbonLargeSplitButtonBottom) then
    inherited DrawLargeButton(DC, R, AState, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawLargeButtonDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, AState, SkinInfo.RibbonLargeSplitButtonTop) then
    inherited DrawLargeButton(DC, R, AState, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawLaunchButtonBackground(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  StateMap: array[0..8] of TdxSkinElementState = (esNormal, esNormal, esHot,
    esHot, esPressed, esNormal, esNormal, esNormal, esNormal);
var
  ARect: TRect;
begin
  if UseSkins and (SkinInfo.RibbonTabPanelGroupButton <> nil) then
  begin
    ARect := R;
    OffsetRect(ARect, 0, 1);
    InflateRect(ARect, -1, -1);
    SkinInfo.RibbonTabPanelGroupButton.Draw(DC, ARect, 0, StateMap[AState]);
  end
  else
    inherited DrawLaunchButtonBackground(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawLaunchButtonDefaultGlyph(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not UseSkins then
    inherited DrawLaunchButtonDefaultGlyph(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawHelpButton(DC: HDC; const R: TRect;
  AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  StateMap: array [TcxButtonState] of Integer = (
    DXBAR_NORMAL, DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED, DXBAR_DISABLED
  );
begin
  if UseSkins then
    DrawSmallButton(DC, R, StateMap[AState], AColorSchemeAccent)
  else
    inherited DrawHelpButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawGroupScrollButton(DC: HDC; const R: TRect;
  ALeft: Boolean; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  AElement: TdxSkinElement;
begin
  if UseSkins then
    AElement := SkinInfo.RibbonGroupScroll[ALeft]
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawGroupScrollButton(DC, R, ALeft, AState, AColorSchemeAccent)
  else
    AElement.Draw(DC, R, 0, RibbonStateToSkinElementState(AState));
end;

procedure TdxSkinRibbonPainter.DrawItemSeparator(
  DC: HDC; const R: TRect; AHorizontal: Boolean);
begin
  if UseSkins and (SkinInfo.RibbonTabGroupItemsSeparator <> nil) then
  begin
    SkinInfo.RibbonTabGroupItemsSeparator.Draw(DC,
      cxRectCenterHorizontally(R, SkinInfo.RibbonTabGroupItemsSeparator.MinSize.Size.cx))
  end
  else
    inherited DrawItemSeparator(DC, R, AHorizontal);
end;

procedure TdxSkinRibbonPainter.DrawKeyTip(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonKeyTip) then
    inherited DrawKeyTip(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawMarkArrow(DC: HDC; const R: TRect; AState: Integer);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonQuickToolbarGlyph) then
    inherited DrawMarkArrow(DC, R, AState);
end;

procedure TdxSkinRibbonPainter.DrawMDIButton(DC: HDC; const R: TRect;
  AButton: TdxBarMDIButton; AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  RibbonIconsToSkinFormIcons: array[TdxBarMDIButton] of TdxSkinFormIcon =
    (sfiMinimize, sfiRestore, sfiClose);
  ButtonStateToSkinElementState: array[TcxButtonState] of TdxSkinElementState =
    (esActive, esNormal, esHot, esPressed, esDisabled);
var
  AElement: TdxSkinElement;
begin
  if UseSkins then
    AElement := SkinInfo.FormIcons[True, RibbonIconsToSkinFormIcons[AButton]]
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawMDIButton(DC, R, AButton, AState, AColorSchemeAccent)
  else
    AElement.Draw(DC, cxRectInflate(R, -1, -1), 0, ButtonStateToSkinElementState[AState]);
end;

procedure TdxSkinRibbonPainter.DrawMDIButtonGlyph(DC: HDC;
  const R: TRect; AButton: TdxBarMDIButton; AState: TcxButtonState);
begin
  if not UseSkins then
    inherited DrawMDIButtonGlyph(DC, R, AButton, AState);
end;

procedure TdxSkinRibbonPainter.DrawMinimizeRibbonButtonGlyph(DC: HDC;
  const R: TRect; AState: TcxButtonState; AGlyph: TdxRibbonMinimizeButtonGlyph;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, 0, SkinInfo.RibbonMinimizeButtonGlyph, Ord(AGlyph <> rmbMinimize)) then
    inherited DrawMinimizeRibbonButtonGlyph(DC, R, AState, AGlyph, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawMenuCheck(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if UseSkins and (SkinInfo.PopupMenuCheck <> nil) then
    SkinInfo.PopupMenuCheck.Draw(DC, R, 1)
  else
    inherited DrawMenuCheck(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawMenuCheckMark(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, SkinInfo.PopupMenuCheck) then
    inherited DrawMenuCheckMark(DC, R, AState, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawMenuContent(DC: HDC; const R: TRect);
begin
  if UseSkins and (SkinInfo.PopupMenu <> nil) then
    FillRectByColor(DC, R, SkinInfo.PopupMenu.Color)
  else
    inherited DrawMenuContent(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawMenuExtraSeparator(
  DC: HDC; const R: TRect; AHorizontal: Boolean);
var
  AColor: TdxSkinColor;
  R1: TRect;
begin
  if UseSkins then
    AColor := SkinInfo.RibbonExtraPaneHeaderSeparator
  else
    AColor := nil;

  if (AColor = nil) or (AColor.Value = clDefault) then
    inherited DrawMenuExtraSeparator(DC, R, AHorizontal)
  else
  begin
    if AHorizontal then
      R1 := cxRectCenterVertically(R, 1)
    else
      R1 := cxRectCenterHorizontally(R, 1);

    FillRectByColor(DC, R1, AColor.Value);
  end;
end;

procedure TdxSkinRibbonPainter.DrawMenuGlyph(DC: HDC; const R: TRect);
var
  R1: TRect;
begin
  if UseSkins and (SkinInfo.PopupMenuSideStrip <> nil) then
  begin
    R1 := R;
    Inc(R1.Right, Max(2, SkinInfo.PopupMenuSideStrip.Image.Margins.Right));
    DrawClippedElement(DC, R, R1, SkinInfo.PopupMenuSideStrip, esNormal);
  end
  else
    inherited DrawMenuGlyph(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawMenuScrollArea(DC: HDC; const R: TRect; AState: Integer);
begin
  if not UseSkins then
    inherited DrawMenuScrollArea(DC, R, AState)
end;

procedure TdxSkinRibbonPainter.DrawMenuSeparatorHorz(DC: HDC; const R: TRect);
begin
  if UseSkins and (SkinInfo.PopupMenuSeparator <> nil) then
  begin
    if SkinInfo.PopupMenuSeparator.IsAlphaUsed then
      DrawMenuContent(DC, R);
    SkinInfo.PopupMenuSeparator.Draw(DC, R);
  end
  else
    inherited DrawMenuSeparatorHorz(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawMenuSeparatorVert(DC: HDC; const R: TRect);
var
  R1: TRect;
begin
  if UseSkins and (SkinInfo.PopupMenuSideStrip <> nil) then
  begin
    R1 := R;
    R1.Left := R.Right - Max(2, SkinInfo.PopupMenuSideStrip.Size.cx);
    DrawClippedElement(DC, R, R1, SkinInfo.PopupMenuSideStrip, esNormal);
  end
  else
    inherited DrawMenuGlyph(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawMenuItem(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if UseSkins and (SkinInfo.PopupMenuLinkSelected <> nil) then
  begin
    if AState in [DXBAR_HOT, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED] then
      SkinInfo.PopupMenuLinkSelected.Draw(DC, R, 0, esHot);
  end
  else
    inherited DrawMenuItem(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawMenuItemDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, SkinInfo.PopupMenuSplitButton2) then
    inherited DrawMenuItemDropButtonArrowPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawMenuItemDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, SkinInfo.PopupMenuSplitButton) then
    inherited DrawMenuItemDropButtonMainPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawMenuMark(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.PopupMenuExpandButton) then
    inherited DrawMenuMark(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawRibbonClientTopArea(DC: HDC; const R: TRect);
var
  ARect: TRect;
begin
  if UseSkins and (SkinInfo.RibbonFormCaption <> nil) then
  begin
    ARect := R;
    with SkinInfo.RibbonFormCaption.Image.Margins.Margin do
      ARect := Rect(R.Left - Left, R.Top - 1, R.Right + Right, R.Bottom);
    DrawClippedElement(DC, R, ARect, SkinInfo.RibbonFormCaption, esNormal);
  end
  else
    inherited DrawRibbonClientTopArea(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawRibbonFormBackground(DC: HDC; const R: TRect; ARibbonHeight: Integer);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonFormContent) then
    inherited DrawRibbonFormBackground(DC, R, ARibbonHeight);
end;

procedure TdxSkinRibbonPainter.DrawRibbonTopFrameArea(DC: HDC; const R: TRect; AUseAeroGlass: Boolean);
begin
  if AUseAeroGlass then
  begin
    if not DrawElement(DC, R, SkinInfo.RibbonHeaderBackgroundOnGlass) then
      inherited DrawRibbonTopFrameArea(DC, R, AUseAeroGlass)
  end;
end;

procedure TdxSkinRibbonPainter.DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect);
begin
  if not UseSkins then
    inherited DrawRibbonTopFrameAreaSeparator(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawScreenTip(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.ScreenTipWindow) then
    inherited DrawScreenTip(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawSeparatorBackground(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.ItemSeparator) then
    inherited DrawSeparatorBackground(DC, R);
end;

procedure TdxSkinRibbonPainter.DrawSmallButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  AElement: TdxSkinElement;
begin
  if UseSkins then
    AElement := SkinInfo.RibbonSmallButton
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawSmallButton(DC, R, AState, AColorSchemeAccent)
  else
  begin
    AElement.UseCache := True;
    AElement.Draw(DC, R, 0, dxSkinElementCheckState(AElement, RibbonStateToSkinElementState(AState)));
  end;
end;

procedure TdxSkinRibbonPainter.DrawSmallButtonDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, AState, SkinInfo.RibbonSplitButtonRight) then
    inherited DrawSmallButtonDropButtonArrowPart(DC, R, AState, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawSmallButtonDropButtonMainPart(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, AState, SkinInfo.RibbonSplitButtonLeft) then
    inherited DrawSmallButtonDropButtonMainPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawStatusBar(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DoDrawStatusBarBackground(DC, R, R, False) then
    inherited DrawStatusBar(DC, R, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawStatusBarSizeGrip(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  if UseSkins and (SkinInfo.SizeGrip <> nil) then
  begin
    R1 := cxRectSetBottom(R, R.Bottom, SkinInfo.SizeGrip.MinSize.Height);
    R1 := cxRectSetRight(R1, R1.Right - 2, SkinInfo.SizeGrip.MinSize.Width);
    SkinInfo.SizeGrip.Draw(DC, R1);
  end
  else
    inherited DrawStatusBarSizeGrip(DC, R, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawStatusBarPanel(DC: HDC;
  const Bounds, R: TRect; AIsLowered: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DoDrawStatusBarBackground(DC, Bounds, R, not AIsLowered) then
    inherited DrawStatusBarPanel(DC, Bounds, R, AIsLowered, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawStatusBarPanelSeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonStatusBarSeparator) then
    inherited DrawStatusBarPanelSeparator(DC, R, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawStatusBarToolbarSeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  if UseSkins and (SkinInfo.RibbonStatusBarSeparator <> nil) then
  begin
    R1 := R;
    Inc(R1.Bottom, GetBordersWidth(True).Bottom);
    SkinInfo.RibbonStatusBarSeparator.Draw(DC, R1);
  end
  else
    inherited DrawStatusBarToolbarSeparator(DC, R, AColorSchemeAccent);
end;

function TdxSkinRibbonPainter.GetScrollBarPainter: TcxCustomLookAndFeelPainter;
begin
  if UseSkins then
    Result := Painter
  else
    Result := inherited GetScrollBarPainter;
end;

procedure TdxSkinRibbonPainter.DrawTab(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if UseSkins and (SkinInfo.RibbonTab <> nil) then
    SkinInfo.RibbonTab.Draw(DC, CorrectTabHeaderRect(R), 0, RibbonTabStatesMap[AState])
  else
    inherited DrawTab(DC, R, AState, AColorSchemeAccent)
end;

procedure TdxSkinRibbonPainter.DrawTabAreaBackground(DC: HDC; const R: TRect;
  AActive, AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState);
var
  AElement: TdxSkinElement;
begin
  if UseSkins then
    AElement := SkinInfo.RibbonHeaderBackground
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawTabAreaBackground(DC, R, AActive, AUseAeroGlass, AApplicationMenuState)
  else
    if not (AUseAeroGlass and ExtendCaptionAreaOnTabs) then
    begin
      if AElement.IsAlphaUsed then
        AElement.Draw(DC, R, 1);
      AElement.Draw(DC, R);
    end;
end;

procedure TdxSkinRibbonPainter.DrawTabGroupBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
const
  StateMap: array[Boolean] of TdxSkinElementState = (esNormal, esHot);
var
  AElement: TdxSkinElement;
begin
  if UseSkins then
    AElement := SkinInfo.RibbonTabGroup
  else
    AElement := nil;

  if AElement = nil then
    inherited DrawTabGroupBackground(DC, R, AState, AIsInPopup)
  else
  begin
    AElement.UseCache := True;
    AElement.Draw(DC, R, 0, StateMap[AState = DXBAR_HOT]);
  end;
end;

procedure TdxSkinRibbonPainter.DrawTabGroupHeaderBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
const
  StateMap: array[Boolean] of TdxSkinElementState = (esNormal, esHot);
begin
  if UseSkins and (SkinInfo.RibbonTabGroupHeader <> nil) then
  begin
    SkinInfo.RibbonTabGroupHeader.Draw(DC,
      CorrectTabPanelRect(AIsInPopup, R), 0, StateMap[AState = DXBAR_HOT]);
  end
  else
    inherited DrawTabGroupHeaderBackground(DC, R, AState, AIsInPopup);
end;

procedure TdxSkinRibbonPainter.DrawTabGroupsArea(
  DC: HDC; const R: TRect; AIsQATAtBottom, AIsInPopup: Boolean);
begin
  if UseSkins and (SkinInfo.RibbonTabPanel <> nil) then
  begin
    SkinInfo.RibbonTabPanel.UseCache := True;
    SkinInfo.RibbonTabPanel.Draw(DC, CorrectTabPanelRect(AIsInPopup, R));
  end
  else
    inherited DrawTabGroupsArea(DC, R, AIsQATAtBottom, AIsInPopup);
end;

procedure TdxSkinRibbonPainter.DrawTabScrollButton(DC: HDC; const R: TRect;
  ALeft: Boolean; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if UseSkins and (SkinInfo.RibbonSmallButton <> nil) then
    SkinInfo.RibbonSmallButton.Draw(DC, R, 0, RibbonStateToSkinElementState(AState))
  else
    inherited DrawTabScrollButton(DC, R, ALeft, AState, AColorSchemeAccent);
end;

procedure TdxSkinRibbonPainter.DrawTabSeparator(DC: HDC; const R: TRect; Alpha: Byte);
var
  ABitmap: TcxBitmap32;
begin
  if UseSkins and (SkinInfo.RibbonTabSeparatorLine <> nil) then
  begin
    ABitmap := TcxBitmap32.CreateSize(R, True);
    try
      SkinInfo.RibbonTabSeparatorLine.Draw(ABitmap.Canvas.Handle, ABitmap.ClientRect);
      cxAlphaBlend(DC, ABitmap, R, ABitmap.ClientRect, False, Alpha);
    finally
      ABitmap.Free;
    end;
  end
  else
    inherited DrawTabSeparator(DC, R, Alpha);
end;

procedure TdxSkinRibbonPainter.DrawQuickAccessToolbar(DC: HDC; const R: TRect;
  ABellow, ANonClientDraw, AHasApplicationButton, AIsActive, ADontUseAero: Boolean);

  function IsAeroBackgroundUsed: Boolean;
  begin
    Result := ANonClientDraw and IsCompositionEnabled and not (ADontUseAero or ABellow);
  end;

  function NeedDrawCustomQuickAccessToolBar(AElement: TdxSkinElement): Boolean;
  begin
    Result := (AElement = nil) or IsAeroBackgroundUsed and not AElement.Image.Empty;
  end;

  function ValidateQATRect(const R: TRect; AParent: TdxSkinElement): TRect;
  var
    ARightIndent: Integer;
  begin
    Result := R;
    if not ABellow then
    begin
      if AParent = nil then
        ARightIndent := 0
      else
        with AParent.ContentOffset.Rect do
        begin
          ARightIndent := GetQuickAccessToolbarRightIndent(AHasApplicationButton);
          Result := cxRectInflate(R, 0, -Top, 0, -Bottom);
        end;

      if GetCustomizeButtonOutsizeQAT(AHasApplicationButton) then
      begin
        Dec(ARightIndent, QATRightDefaultOffset);
        Dec(ARightIndent, GetQuickAccessToolbarMarkButtonOffset(AHasApplicationButton, ABellow));
      end;
      Inc(Result.Right, ARightIndent);
    end;
  end;

var
  AElement: TdxSkinElement;
  ARect: TRect;
begin
  AElement := GetQATBackgroundElement(ABellow, AHasApplicationButton);
  if NeedDrawCustomQuickAccessToolBar(AElement) then
    inherited DrawQuickAccessToolbar(DC, R, ABellow, ANonClientDraw,
      AHasApplicationButton, AIsActive, ADontUseAero)
  else
    if not IsAeroBackgroundUsed then
    begin
      ARect := ValidateQATRect(R, SkinInfo.RibbonFormCaption);
      if ABellow or (cxRectWidth(ARect) >= cxRectHeight(ARect)) then
        AElement.Draw(DC, ARect);
    end;
end;

procedure TdxSkinRibbonPainter.DrawQuickAccessToolbarDefaultGlyph(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonQuickToolbarButtonGlyph) then
    inherited DrawQuickAccessToolbarDefaultGlyph(DC, R)
end;

procedure TdxSkinRibbonPainter.DrawQuickAccessToolbarGroupButton(DC: HDC;
  const R: TRect; ABellow: Boolean; ANonClientDraw: Boolean; AIsActive: Boolean;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  ABackground: TdxSkinElement;
  AElement: TdxSkinElement;
begin
  if UseSkins then
  begin
    ABackground := SkinInfo.RibbonButtonGroup;
    AElement := SkinInfo.RibbonButtonGroupButton;
  end
  else
  begin
    AElement := nil;
    ABackground := nil;
  end;

  if (AElement = nil) or (ABackground = nil) then
    inherited DrawQuickAccessToolbarGroupButton(DC, R,
      ABellow, ANonClientDraw, AIsActive, AState, AColorSchemeAccent)
  else
  begin
    ABackground.Draw(DC, R);
    AElement.Draw(DC, cxRectContent(R, ABackground.ContentOffset.Rect), 0,
      RibbonStateToSkinElementState(AState));
  end;
end;

procedure TdxSkinRibbonPainter.DrawQuickAccessToolbarPopup(DC: HDC; const R: TRect);
begin
  if not DrawElement(DC, R, SkinInfo.RibbonQuickToolbarDropDown) then
    inherited DrawQuickAccessToolbarPopup(DC, R)
end;

procedure TdxSkinRibbonPainter.LoadRibbonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONBLACK', AImage);
end;

function TdxSkinRibbonPainter.GetApplicationMenuGlyphSize: TSize;
begin
  if ApplicationButtonElement = nil then
    Result := inherited GetApplicationMenuGlyphSize
  else
    Result := GetElementMinSize(ApplicationButtonElement);
end;

function TdxSkinRibbonPainter.GetPropertyColor(AColor: TdxSkinColor): TColor;
begin
  if AColor = nil then
    Result := clDefault
  else
    Result := AColor.Value;
end;

function TdxSkinRibbonPainter.GetElementContentIndents(AElement: TdxSkinElement;
  AConsideMargins: Boolean; out ALeftIndent, ARightIndent: Integer): Boolean;
begin
  Result := Assigned(AElement);
  if Result then
  begin
    ALeftIndent := AElement.ContentOffset.Left;
    ARightIndent := AElement.ContentOffset.Right;
    if AConsideMargins then
    begin
      ALeftIndent := Max(AElement.Image.Margins.Left, ALeftIndent);
      ARightIndent := Max(AElement.Image.Margins.Right, ARightIndent);
    end;
  end;
end;

function TdxSkinRibbonPainter.GetIsAlphaUsed(APart: Integer): Boolean;
var
  AElement: TdxSkinElement;
begin
  AElement := nil;
  if UseSkins then
  begin
    if APart = DXBAR_INRIBBONGALLERYSCROLLBAR_BACKGROUND then
      AElement := SkinInfo.RibbonGalleryPane;
  end;
  if AElement = nil then
    Result := inherited GetIsAlphaUsed(APart)
  else
    Result := AElement.IsAlphaUsed;
end;

function TdxSkinRibbonPainter.GetMenuSeparatorSize: Integer;
begin
  if UseSkins and (SkinInfo.PopupMenuSeparator <> nil) then
    Result := SkinInfo.PopupMenuSeparator.Size.cy
  else
    Result := inherited GetMenuSeparatorSize;
end;

function TdxSkinRibbonPainter.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;

  function GetElementTextColor(AElement: TdxSkinElement; AState: Integer; const APropertyPrefix: string = ''): TColor;
  var
    AProperty: TdxSkinProperty;
    APropertyStateName: string;
  begin
    Result := clDefault;
    if AElement <> nil then
    begin
      APropertyStateName := APropertyPrefix + dxSkinElementTextColorPropertyNames[RibbonStateToButtonState(AState)];
      if AElement.GetPropertyByName(APropertyStateName + dxRibbonColorSchemeAccentNames[AColorSchemeAccent], AProperty) or
         AElement.GetPropertyByName(APropertyStateName, AProperty)
      then
        if AProperty is TdxSkinColor then
          Result := TdxSkinColor(AProperty).Value;

      if Result = clDefault then
        Result := AElement.TextColor;
    end;
  end;

begin
  Result := clDefault;
  if UseSkins then
  begin
    CheckColorSchemeAccent(AColorSchemeAccent);
    case APart of
      DXBAR_RADIALMENUACCENT:
        Result := GetPropertyColor(SkinInfo.RadialMenuBaseColor);
      DXBAR_RADIALMENUBACKGROUND:
        Result := GetPropertyColor(SkinInfo.RadialMenuBackgroundColor);
      DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_BORDER:
        Result := GetPropertyColor(SkinInfo.ContainerBorderColor);
      DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_GROUPHEADER_TEXTCOLOR:
        Result := GetElementTextColor(SkinInfo.GalleryGroup, AState);
      DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMCAPTIONTEXTCOLOR:
        Result := GetElementTextColor(SkinInfo.GalleryItem, AState);
      DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMDESCRIPTIONTEXTCOLOR:
        Result := GetElementTextColor(SkinInfo.GalleryItem, AState, sdxDescriptionTextColorPrefix);
      DXBAR_BACKSTAGEVIEW_MENUBAR_TAB_TEXTCOLOR:
        Result := GetElementTextColor(SkinInfo.RibbonBackstageViewTab, AState);
      DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM_TEXTCOLOR:
        Result := GetElementTextColor(SkinInfo.RibbonBackstageViewMenuButton, AState);

      DXBAR_DROPDOWNGALLERYITEM_TEXTCOLOR:
        begin
          if AState <> DXBAR_NORMAL then
            Result := GetElementTextColor(SkinInfo.RibbonSmallButton, AState);
          if Result = clDefault then
            Result := GetElementTextColor(SkinInfo.RibbonGalleryBackground, AState);
        end;

      DXBAR_ITEMTEXT:
        case AState of
          DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
            Result := SkinInfo.RibbonButtonText[True]
          else
            Result := SkinInfo.RibbonButtonText[False];
        end;

      DXBAR_SEPARATOR_TEXTCOLOR:
        Result := GetElementTextColor(SkinInfo.ItemSeparator, AState);

      DXBAR_APPLICATIONMENUBUTTON:
        Result := GetElementTextColor(SkinInfo.ButtonElements, AState);

      DXBAR_MENUITEMTEXT:
        case AState of
          DXBAR_DISABLED:
            Result := GetPropertyColor(SkinInfo.BarDisabledTextColor);
          else
            Result := GetElementTextColor(SkinInfo.PopupMenu, AState);
        end;

      DXBAR_EDIT_BORDER:
        if AState = DXBAR_ACTIVE then
          Result := GetPropertyColor(SkinInfo.ContainerHighlightBorderColor)
        else
          Result := GetPropertyColor(SkinInfo.ContainerBorderColor);

      rfspRibbonForm, rspRibbonBackground:
        if SkinInfo.FormContent <> nil then
          Result := SkinInfo.FormContent.Color;

      DXBAR_BACKSTAGEVIEW_TEXTCOLOR:
        if SkinInfo.RibbonBackstageView <> nil then
          Result := SkinInfo.RibbonBackstageView.TextColor;

      rspContextTabHeaderText:
        begin
          if AState = DXBAR_HOT then
            Result := SkinInfo.RibbonContextualTabHeaderTextHot
          else
            Result := SkinInfo.RibbonContextualTabHeaderText[AState = DXBAR_ACTIVE];

          if not cxColorIsValid(Result) then
            Result := GetPartColor(rspTabHeaderText, AState);
        end;

      rspTabHeaderText:
        begin
          case AState of
            DXBAR_HOT:
              Result := SkinInfo.RibbonTabTextHot;
            DXBAR_ACTIVE:
              Result := SkinInfo.RibbonTabText[True];
            else
              Result := clDefault;
          end;
          if Result = clDefault then
            Result := SkinInfo.RibbonTabText[False];
        end;

      rspContextText:
        Result := GetElementTextColor(SkinInfo.RibbonContextualTabLabel, AState);
      rspContextTextOnGlass:
        Result := GetElementTextColor(SkinInfo.RibbonContextualTabLabelOnGlass, AState);
      rspContextTextShadow:
        Result := GetPropertyColor(SkinInfo.RibbonContextualTabLabelShadowColor);
      rspContextTextOnGlassShadow:
        begin
          Result := GetPropertyColor(SkinInfo.RibbonContextualTabLabelOnGlassShadowColor);
          if Result = clDefault then
            Result := GetPartColor(rspContextTextShadow, AState, AColorSchemeAccent);
        end;

      DXBAR_KEYTIP_TEXTCOLOR:
        Result := GetElementTextColor(SkinInfo.RibbonKeyTip, AState);
      DXBAR_SCREENTIP_TITLE:
        Result := GetPropertyColor(SkinInfo.ScreenTipTitleItem);
      DXBAR_SCREENTIP_DESCRIPTION:
        Result := GetPropertyColor(SkinInfo.ScreenTipItem);
      DXBAR_MENUEXTRAPANE:
        Result := GetPropertyColor(SkinInfo.RibbonExtraPaneColor);
      DXBAR_MENUEXTRAPANE_BUTTON_TEXTCOLOR, DXBAR_MENUEXTRAPANE_HEADER_TEXTCOLOR:
        Result := GetElementTextColor(SkinInfo.RibbonExtraPaneButton, AState);
      DXBAR_EDIT_BACKGROUND:
        Result := GetPropertyColor(SkinInfo.RibbonEditorBackground);
      DXBAR_SEPARATOR_BACKGROUND:
        Result := GetPropertyColor(SkinInfo.ContentColor);
      DXBAR_EDIT_TEXTCOLOR:
        Result := Painter.DefaultEditorTextColor(AState = DXBAR_DISABLED);
      DXBAR_SCREENTIP_FOOTERLINE:
        Result := GetPropertyColor(SkinInfo.ContainerBorderColor);
      rspFormCaptionText:
        Result := SkinInfo.RibbonCaptionText[AState = DXBAR_NORMAL];
      rspDocumentNameText:
        Result := SkinInfo.RibbonDocumentNameTextColor[AState = DXBAR_NORMAL];
      rspTabGroupText:
        Result := GetElementTextColor(SkinInfo.RibbonSmallButton, AState);
      rspTabGroupHeaderText:
        Result := GetElementTextColor(SkinInfo.RibbonTabGroupHeader, AState);
      rspApplicationButton:
        Result := GetElementTextColor(SkinInfo.RibbonApplicationButton2010, AState);
      rspStatusBarText:
        case AState of
          DXBAR_NORMAL, DXBAR_HOT, DXBAR_HOTCHECK, DXBAR_DISABLED:
            Result := GetElementTextColor(SkinInfo.RibbonStatusBarButton, AState);
          DXBAR_CHECKED:
            begin
              Result := SkinInfo.RibbonStatusBarTextSelected;
              if Result = clDefault then
                Result := GetPartColor(rspStatusBarText, DXBAR_NORMAL);
            end;
        end;

      DXBAR_GALLERYGROUPHEADERTEXT, DXBAR_GALLERYFILTERBANDTEXT:
        Result := GetElementTextColor(SkinInfo.RibbonGalleryGroupCaption, AState);
    end;
  end;
  if Result = clDefault then
    Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
end;

function TdxSkinRibbonPainter.GetPartContentOffsets(APart: Integer): TRect;

  function GetElementForPart(APart: Integer; out AElement: TdxSkinElement): Boolean;
  begin
    case APart of
      DXBAR_BACKSTAGEVIEW:
        AElement := SkinInfo.RibbonBackstageView;
      DXBAR_BACKSTAGEVIEW_MENUBAR_TAB:
        AElement := SkinInfo.RibbonBackstageViewTab;
      DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_GROUPHEADER:
        AElement := SkinInfo.RibbonGalleryGroupCaption;
      DXBAR_APPLICATIONMENUBUTTON:
        AElement := SkinInfo.RibbonApplicationBackground;
      DXBAR_TOOLBAR, DXBAR_TOOLBARINPOPUP:
        AElement := SkinInfo.RibbonTabGroup;
      DXBAR_GALLERYFILTERBAND:
        AElement := SkinInfo.RibbonGallerySizingPanel;
      DXBAR_RIBBONTABGROUP:
        AElement := SkinInfo.RibbonTabPanel;
      DXBAR_RIBBONCONTEXTTABGROUP:
        AElement := SkinInfo.RibbonContextualTabPanel;
      DXBAR_QUICKACCESSTOOLBAR:
        AElement := SkinInfo.RibbonQuickToolbarBelow;
      DXBAR_APPLICATIONBUTTONICONOFFSET:
        AElement := ApplicationButtonElement;
    else
      AElement := nil;
    end;
    Result := AElement <> nil;
  end;

var
  AElement: TdxSkinElement;
begin
  if UseSkins and GetElementForPart(APart, AElement) then
  begin
    if APart = DXBAR_APPLICATIONMENUBUTTON then
    begin
      Result := inherited GetPartContentOffsets(APart);
      Result.Right := Max(Result.Top, AElement.ContentOffset.Right) - AElement.ContentOffset.Right;
    end
    else
      Result := AElement.ContentOffset.Rect;
  end
  else
    Result := inherited GetPartContentOffsets(APart);
end;

function TdxSkinRibbonPainter.GetPartSize(APart: Integer): Integer;

  function GetElementHeight(AElement: TdxSkinElement): Integer;
  begin
    if AElement <> nil then
      Result := AElement.MinSize.Height
    else
      Result := 0;
  end;

  function GetValue(AProperty: TdxSkinIntegerProperty): Integer;
  begin
    if AProperty = nil then
      Result := 1
    else
      Result := AProperty.Value;
  end;

begin
  Result := inherited GetPartSize(APart);
  if UseSkins then
  begin
    case APart of
      DXBAR_BACKSTAGEVIEW_BACKBUTTON:
        Result := GetElementHeight(SkinInfo.RibbonBackstageViewBackButton);
      DXBAR_BACKSTAGEVIEW_MENUBAR_TAB:
        Result := Max(Result, GetElementHeight(SkinInfo.RibbonBackstageViewTab));
      DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM:
        Result := Max(Result, GetElementHeight(SkinInfo.RibbonBackstageViewMenuButton));
      DXBAR_BACKSTAGEVIEW_MENUBAR_SEPARATOR:
        Result := GetElementHeight(SkinInfo.RibbonBackstageViewMenuSeparator);
      DXBAR_SEPARATOR_LINE:
        Result := 0;
      DXBAR_TOOLBAR, DXBAR_TOOLBARINPOPUP:
        Result := GetValue(SkinInfo.RibbonSpaceBetweenTabGroups);
      DXBAR_TABSGROUPSOVERLAPHEIGHT:
        Result := GetValue(SkinInfo.RibbonTabHeaderDownGrowIndent);
      DXBAR_BUTTONGROUPSPLITBUTTONSEPARATOR:
        Result := 0;
      DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_SEPARATOR:
        Result := Painter.LabelLineHeight;
    end;
  end;
end;

function TdxSkinRibbonPainter.GetQuickAccessToolbarLeftIndent(
  AHasApplicationButton: Boolean; AUseAeroGlass: Boolean): Integer;
begin
  if not AUseAeroGlass and UseSkins then
  begin
    Result := -QATLeftDefaultOffset;
    if SkinInfo.RibbonQuickToolbar[AHasApplicationButton] <> nil then
      Inc(Result, SkinInfo.RibbonQuickToolbar[AHasApplicationButton].ContentOffset.Left);
    Inc(Result, GetQATLeftOffset(AHasApplicationButton));
  end
  else
    Result := inherited GetQuickAccessToolbarLeftIndent(AHasApplicationButton, AUseAeroGlass);
end;

function TdxSkinRibbonPainter.GetQuickAccessToolbarMarkButtonOffset(
  AHasApplicationButton: Boolean; ABelow: Boolean): Integer;
var
  AOffsetProperty: TdxSkinIntegerProperty;
begin
  if UseSkins then
    AOffsetProperty := SkinInfo.RibbonQATIndentBeforeCustomizeButton[AHasApplicationButton]
  else
    AOffsetProperty := nil;

  if ABelow or (AOffsetProperty = nil) then
    Result := inherited GetQuickAccessToolbarMarkButtonOffset(AHasApplicationButton, ABelow)
  else
    Result := AOffsetProperty.Value;
end;

function TdxSkinRibbonPainter.GetQuickAccessToolbarOverrideWidth(
  AHasApplicationButton: Boolean; AUseAeroGlass: Boolean): Integer;
begin
  if not AUseAeroGlass and UseSkins then
  begin
    Result := GetQuickAccessToolbarLeftIndent(AHasApplicationButton, AUseAeroGlass) + QATLeftDefaultOffset;
    Dec(Result, GetQATLeftOffset(AHasApplicationButton));
  end
  else
    Result := inherited GetQuickAccessToolbarOverrideWidth(AHasApplicationButton, AUseAeroGlass);
end;

function TdxSkinRibbonPainter.GetQuickAccessToolbarRightIndent(AHasApplicationButton: Boolean): Integer;
begin
  if UseSkins and (SkinInfo.RibbonQuickToolbar[AHasApplicationButton] <> nil) then
    Result := SkinInfo.RibbonQuickToolbar[AHasApplicationButton].ContentOffset.Right
  else
    Result := inherited GetQuickAccessToolbarRightIndent(AHasApplicationButton);
end;

function TdxSkinRibbonPainter.GetSkinName: string;
begin
  Result := Painter.LookAndFeelName;
end;

function TdxSkinRibbonPainter.GetStatusBarSeparatorSize: Integer;
var
  AElement: TdxSkinElement;
begin
  if UseSkins then
    AElement := SkinInfo.RibbonStatusBarSeparator
  else
    AElement := nil;

  if AElement <> nil then
  begin
    Result := AElement.MinSize.Width;
    if Result = 0 then
      Result := AElement.Image.Size.cx;
    if Result = 0 then
      Result := inherited GetStatusBarSeparatorSize;
  end
  else
    Result := inherited GetStatusBarSeparatorSize;
end;

function TdxSkinRibbonPainter.GetWindowBordersWidth(AHasStatusBar: Boolean): TRect;
begin
  if UseSkins then
    Result := GetBordersWidth(AHasStatusBar)
  else
    Result := inherited GetWindowBordersWidth(AHasStatusBar);
end;

function TdxSkinRibbonPainter.NeedDrawGroupScrollArrow: Boolean;
begin
  Result := False;
end;

function TdxSkinRibbonPainter.UseRoundedWindowCorners: Boolean;
begin
  if UseSkins and (SkinInfo.RibbonUseRoundedWindowCorners <> nil) then
    Result := SkinInfo.RibbonUseRoundedWindowCorners.Value
  else
    Result := inherited UseRoundedWindowCorners;
end;

{ TdxSkinRibbon2010Painter }

function TdxSkinRibbon2010Painter.ExtendCaptionAreaOnTabs: Boolean;
begin
  if UseSkins then
    Result := TabAeroSupport
  else
    Result := inherited ExtendCaptionAreaOnTabs;
end;

function TdxSkinRibbon2010Painter.GetApplicationButtonElement: TdxSkinElement;
begin
  if UseSkins then
    Result := SkinInfo.RibbonApplicationButton2010
  else
    Result := nil;
end;

function TdxSkinRibbon2010Painter.GetApplicationMenuContentOffset(const ATabsBounds: TRect): TRect;
begin
  Result := inherited GetApplicationMenuContentOffset(ATabsBounds);
  if UseSkins then
    Result.Top := cxRectHeight(ATabsBounds);
end;

function TdxSkinRibbon2010Painter.GetPartContentOffsets(APart: Integer): TRect;
begin
  if UseSkins and (APart = DXBAR_APPLICATIONBUTTON) then
    Result := cxRect(GetApplicationButtonIndent(sdxRibbonAppButtonLeftIndent) + 1,
      2, GetApplicationButtonIndent(sdxRibbonAppButtonRightIndent), 0)
  else
    Result := inherited GetPartContentOffsets(APart);
end;

function TdxSkinRibbon2010Painter.GetStyle: TdxRibbonStyle;
begin
  Result := rs2010;
end;

{ TdxSkinRibbon2013Painter }

procedure TdxSkinRibbon2013Painter.DrawBackstageViewMenuBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  R1 := R;
  Dec(R1.Left, GetBordersWidth(False).Left);
  inherited DrawBackstageViewMenuBackground(DC, R1, AColorSchemeAccent);
end;

procedure TdxSkinRibbon2013Painter.DrawBackstageViewBorders(
  DC: HDC; const R, ABordersWidth: TRect; AIsActive: Boolean);
const 
  StateMap: array[Boolean] of TdxSkinElementState = (esActiveDisabled, esActive);
var
  ASaveIndex: Integer;
  ASide: TcxBorder;
  AThinBorders: TRect;
  R1: TRect;
begin
  ASaveIndex := SaveDC(DC);
  try
    R1 := cxRectContent(R, ABordersWidth);
    ExcludeClipRect(DC, R1.Left, R1.Top, R1.Right, R1.Bottom);

    AThinBorders.Bottom := Ord(ABordersWidth.Bottom > 0);
    AThinBorders.Right := Ord(ABordersWidth.Right > 0);
    AThinBorders.Left := Ord(ABordersWidth.Left > 0);
    AThinBorders.Top := Ord(ABordersWidth.Top > 0);

    R1 := cxRectContent(R, AThinBorders);
    FillRectByColor(DC, R1, SkinInfo.RibbonBackstageView.Color);
    ExcludeClipRect(DC, R1.Left, R1.Top, R1.Right, R1.Bottom);

    for ASide := Low(TcxBorder) to High(TcxBorder) do
    begin
      if ASide = bTop then
        SkinInfo.FormFrames[True][bTop].Draw(DC, R, 0, StateMap[AIsActive])
      else
        DrawFormBorder(DC, ASide, AThinBorders, R, GetBorderSkinElement(ASide, True), AIsActive);
    end;
  finally
    RestoreDC(DC, ASaveIndex);
  end;
end;

procedure TdxSkinRibbon2013Painter.DrawBackstageViewMenuHeader(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  R1 := R;
  Dec(R1.Left, GetBordersWidth(False).Left);
  Inc(R1.Top, GetBordersWidth(False).Bottom);
  inherited DrawBackstageViewMenuHeader(DC, R1, AColorSchemeAccent);
end;

procedure TdxSkinRibbon2013Painter.DrawFormBorders(
  DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo);
var
  ARect: TRect;
  ASaveIndex: Integer;
begin
  if (AInfo.ApplicationMenuState = ramsShownAsFullScreenFrame) and UseSkins then
  begin
    ASaveIndex := SaveDC(DC);
    try
      ARect := cxRectContent(AInfo.FormData.Bounds, ABordersWidth);
      ExcludeClipRect(DC, ARect.Left, ARect.Top, ARect.Right, ARect.Bottom);
      DrawBackstageViewBorders(DC, AInfo.FormData.Bounds,
        cxRect(ABordersWidth.Left, AInfo.CaptionHeight, ABordersWidth.Right, ABordersWidth.Bottom),
        AInfo.FormData.Active);
    finally
      RestoreDC(DC, ASaveIndex);
    end;
  end
  else
    inherited DrawFormBorders(DC, ABordersWidth, AInfo);
end;

procedure TdxSkinRibbon2013Painter.DrawFormCaption(
  DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo);
begin
  if (AInfo.ApplicationMenuState = ramsShownAsFullScreenFrame) and UseSkins then
    DrawBackstageViewBorders(DC, R, cxRect(0, cxRectHeight(R), 0, 0), AInfo.FormData.Active)
  else
    inherited DrawFormCaption(DC, R, AInfo);
end;

function TdxSkinRibbon2013Painter.GetPartContentOffsets(APart: Integer): TRect;
begin
  if (APart = DXBAR_BACKSTAGEVIEW) and UseSkins then
    Result := cxNullRect
  else
    Result := inherited GetPartContentOffsets(APart);
end;

function TdxSkinRibbon2013Painter.GetStyle: TdxRibbonStyle;
begin
  Result := rs2013;
end;

{ TdxSkinsRibbonPainterManager }

constructor TdxSkinsRibbonPainterManager.Create;
begin
  inherited Create;
  cxLookAndFeelPaintersManager.AddListener(Self);
  InitializePaintersList;
end;

destructor TdxSkinsRibbonPainterManager.Destroy;
begin
  cxLookAndFeelPaintersManager.RemoveListener(Self);
  FreePaintersList;  
  inherited Destroy;
end;

procedure TdxSkinsRibbonPainterManager.AddSkin(APainter: TcxCustomLookAndFeelPainter);

  function IsSkinAlreadyExists(const AName: string): Boolean;
  var
    AStyle: TdxRibbonStyle;
  begin
    Result := False;
    for AStyle := Low(TdxRibbonStyle) to High(TdxRibbonStyle) do
      Result := Result or (dxRibbonSkinsManager.Find(AName, AStyle) <> nil);
  end;

begin
  if APainter is TdxSkinLookAndFeelPainter then
  begin
    if not IsSkinAlreadyExists(APainter.LookAndFeelName) then
    begin
      dxRibbonSkinsManager.Add(TdxSkinRibbonPainter.Create(TdxSkinLookAndFeelPainter(APainter)));
      dxRibbonSkinsManager.Add(TdxSkinRibbon2010Painter.Create(TdxSkinLookAndFeelPainter(APainter)));
      dxRibbonSkinsManager.Add(TdxSkinRibbon2013Painter.Create(TdxSkinLookAndFeelPainter(APainter)));
    end;
  end;
end;

procedure TdxSkinsRibbonPainterManager.FreePaintersList;
var
  ASkin: TdxCustomRibbonSkin;
  I: Integer;
begin
  for I := dxRibbonSkinsManager.SkinCount - 1 downto 0 do
  begin
    ASkin := dxRibbonSkinsManager.Skins[I];
    if ASkin is TdxSkinRibbonPainter then
      dxRibbonSkinsManager.Remove(ASkin);
  end;    
end;

procedure TdxSkinsRibbonPainterManager.InitializePaintersList;
var
  I: Integer;
begin
  for I := 0 to cxLookAndFeelPaintersManager.Count - 1 do
    AddSkin(cxLookAndFeelPaintersManager[I]);
end;

procedure TdxSkinsRibbonPainterManager.PainterAdded(APainter: TcxCustomLookAndFeelPainter);
begin
  AddSkin(APainter);
end;

procedure TdxSkinsRibbonPainterManager.PainterRemoved(APainter: TcxCustomLookAndFeelPainter);
var
  ASkin: TdxCustomRibbonSkin;
  I: Integer;
begin
  for I := dxRibbonSkinsManager.SkinCount - 1 downto 0 do
  begin
    ASkin := dxRibbonSkinsManager.Skins[I];
    if (ASkin is TdxSkinRibbonPainter) and (TdxSkinRibbonPainter(ASkin).Painter = APainter) then
      dxRibbonSkinsManager.Remove(ASkin);
  end;
end;

procedure RegisterPainterManager;
begin
  FRibbonPainterManager := TdxSkinsRibbonPainterManager.Create;
end;

procedure UnregisterPainterManager;
begin
  FreeAndNil(FRibbonPainterManager);
end;

initialization
  dxUnitsLoader.AddUnit(@RegisterPainterManager, @UnregisterPainterManager);

finalization
  dxUnitsLoader.RemoveUnit(@UnregisterPainterManager);

end.
