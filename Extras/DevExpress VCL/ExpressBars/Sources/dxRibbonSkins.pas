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

unit dxRibbonSkins;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  StdCtrls, ImgList, ExtCtrls, dxCore, cxClasses, cxGraphics, dxBarSkin, dxBar,
  dxBarSkinConsts, dxGDIPlusAPI, dxGDIPlusClasses, cxLookAndFeelPainters, dxScreenTip;

const
  //ribbon's form consts
  rfspActiveCaption              = 10000; //don't change order
  rfspInactiveCaption            = 10001;
  rfspActiveCaptionZoomed        = 10002;
  rfspInactiveCaptionZoomed      = 10003;
  rfspActiveCaptionLeftBorder    = 10004;
  rfspInactiveCaptionLeftBorder  = 10005;
  rfspActiveCaptionRightBorder   = 10006;
  rfspInactiveCaptionRightBorder = 10007;
  rfspActiveLeftBorder           = 10008;
  rfspInactiveLeftBorder         = 10009;
  rfspActiveRightBorder          = 10010;
  rfspInactiveRightBorder        = 10011;
  rfspActiveBottomBorderThin     = 10012;
  rfspInactiveBottomBorderThin   = 10013;
  rfspActiveBottomBorderThick    = 10014;
  rfspInactiveBottomBorderThick  = 10015;
  rfspActiveBottomBorderThickRectangular   = 10016;
  rfspInactiveBottomBorderThickRectangular = 10017;
  rfspRibbonForm                 = 10018;

  //ribbon skin consts
  rspTabNormal                   = 10043;
  rspTabHot                      = 10044;
  rspTabActive                   = 10045;
  rspTabActiveHot                = 10046;
  rspTabFocused                  = 10047;
  rspTabGroupsArea               = 10048;
  rspTabGroupsArea2              = 10049;
  rspTabSeparator                = 10050;
  rspTabGroupsAreaInPopup        = 10051;

  rspQATDefaultGlyph             = 10052;
  rspQATAtBottom                 = 10053;
  rspRibbonClientTopArea         = 10054;

  rspQATNonClientLeft1Vista      = 10055;
  rspQATNonClientLeft2Vista      = 10056;
  rspQATNonClientRightVista      = 10057;
  rspQATPopup                    = 10058;

  rspQATNonClientLeft1Active     = 10059;
  rspQATNonClientLeft1Inactive   = 10060;
  rspQATNonClientLeft2Active     = 10061;
  rspQATNonClientLeft2Inactive   = 10062;
  rspQATNonClientRightActive     = 10063;
  rspQATNonClientRightInactive   = 10064;

  rspRibbonBackground            = 10065;
  rspRibbonBottomEdge            = 10066;

  rspApplicationMenuBorder       = 10070;
  rspApplicationMenuContentHeader= 10071;
  rspApplicationMenuContentFooter= 10072;
  rspDropDownBorder              = 10073;
  rspMenuContent                 = 10074;
  rspMenuGlyph                   = 10075;
  rspMenuMark                    = 10076;
  rspMenuSeparatorHorz           = 10077;
  rspMenuSeparatorVert           = 10078;
  rspMenuArrowDown               = 10079;
  rspMenuArrowRight              = 10080;
  rspProgressSolidBand           = 10081;
  rspProgressDiscreteBand        = 10082;
  rspProgressSubstrate           = 10083;
  rspButtonGroupBorderLeft       = 10084;
  rspButtonGroupBorderRight      = 10085;
  rspScrollArrow                 = 10086;
  rspScreenTip                   = 10087;
  rspHelpButton                  = 10088;
  rspApplicationMenuButton       = 10089;

  rspStatusBar                   = 10090;
  rspStatusBarPanel              = 10091;
  rspStatusBarPanelLowered       = 10092;
  rspStatusBarPanelRaised        = 10093;
  rspStatusBarPanelSeparator     = 10094;
  rspStatusBarGripBackground     = 10095;
  rspStatusBarToolbarSeparator   = 10096;
  rspStatusBarSizeGripColor1     = 10098;
  rspStatusBarSizeGripColor2     = 10099;
  rspStatusBarFormLeftPart       = 10100;
  rspStatusBarFormRightPart      = 10104;
  rspStatusBarFormLeftPartDialog = 10108;
  rspStatusBarFormRightPartDialog= 10112;

  rspDropDownGalleryTopSizingBand = 10120;
  rspDropDownGalleryBottomSizingBand = 10121;
  rspDropDownGalleryTopSizeGrip  = 10122;
  rspDropDownGalleryBottomSizeGrip = 10123;
  rspDropDownGalleryVerticalSizeGrip = 10124;
  rspGalleryFilterBand           = 10125;
  rspGalleryGroupHeader          = 10126;

  //ribbon font colors
  rspFormCaptionText             = 10130;
  rspDocumentNameText            = 10131;
  rspTabHeaderText               = 10132;
  rspTabGroupText                = 10133;
  rspTabGroupHeaderText          = 10134;
  rspStatusBarText               = 10138;
  rspContextText                 = 10139;
  rspContextTextOnGlass          = 10140;
  rspContextTextShadow           = 10141;
  rspContextTextOnGlassShadow    = 10142;

  //context tabs
  rspContextTabNormal            = 10143;
  rspContextTabHot               = 10144;
  rspContextTabActive            = 10145;
  rspContextTabActiveHot         = 10146;
  rspContextTabFocused           = 10147;
  rspContextTabGroupsArea        = 10148;
  rspContextTabGroupsArea2       = 10149;
  rspContextTabSeparatorBegin    = 10150;
  rspContextTabSeparatorEnd      = 10151;
  rspContextBackground           = 10152;
  rspContextBackgroundGlass      = 10153;
  rspContextTabHeaderText        = 10154;

  //border icons
  rfspBorderIconBackground       = 10160; // 3 states
  rfspBorderIconMinimizeGlyph    = rfspBorderIconBackground + 3; // 4 states
  rfspBorderIconMaximizeGlyph    = rfspBorderIconMinimizeGlyph + 4; // 4 states
  rfspBorderIconCloseGlyph       = rfspBorderIconMaximizeGlyph + 4; // 4 states
  rfspBorderIconRestoreGlyph     = rfspBorderIconCloseGlyph + 4; // 4 states
  rfspBorderIconHelpGlyph        = rfspBorderIconRestoreGlyph + 4; // 4 states;
  rfspBorderIconAutoHideGlyph    = rfspBorderIconHelpGlyph + 4; // 4 states;
  rfspBorderIconAutoHideShowUIGlyph = rfspBorderIconAutoHideGlyph + 4; // 4 states;

  rspTabGroupBottomOffset  = rfspBorderIconAutoHideShowUIGlyph + 4;

  //state's groups const
  rspQATGroupButtonActive        = rspTabGroupBottomOffset + 1;
  rspQATGroupButtonInactive      = rspQATGroupButtonActive + DXBAR_STATESCOUNT;
  rspArrowDownNormal             = rspQATGroupButtonInactive + DXBAR_STATESCOUNT;
  rspMenuDetachCaptionNormal     = rspArrowDownNormal + DXBAR_STATESCOUNT;
  rspMenuCheckNormal             = rspMenuDetachCaptionNormal + DXBAR_STATESCOUNT;
  rspMenuCheckMarkNormal         = rspMenuCheckNormal + DXBAR_STATESCOUNT;
  rspMenuScrollAreaNormal        = rspMenuCheckMarkNormal + DXBAR_STATESCOUNT;

  rspCollapsedToolbarNormal = rspMenuScrollAreaNormal + DXBAR_STATESCOUNT;
  rspCollapsedToolbarGlyphBackgroundNormal = rspCollapsedToolbarNormal + DXBAR_STATESCOUNT;

  rspEditButtonNormal            = rspCollapsedToolbarGlyphBackgroundNormal + DXBAR_STATESCOUNT;

  rspSmallButtonNormal           = rspEditButtonNormal + DXBAR_STATESCOUNT;
  rspSmallButtonGlyphBackgroundNormal = rspSmallButtonNormal + DXBAR_STATESCOUNT;
  rspSmallButtonDropButtonNormal = rspSmallButtonGlyphBackgroundNormal + DXBAR_STATESCOUNT;

  rspLargeButtonNormal           = rspSmallButtonDropButtonNormal + DXBAR_STATESCOUNT;
  rspLargeButtonGlyphBackgroundNormal = rspLargeButtonNormal + DXBAR_STATESCOUNT;
  rspLargeButtonDropButtonNormal = rspLargeButtonGlyphBackgroundNormal + DXBAR_STATESCOUNT;

  rspButtonGroupNormal           = rspLargeButtonDropButtonNormal + DXBAR_STATESCOUNT;
  rspButtonGroupBorderMiddleNormal = rspButtonGroupNormal + DXBAR_STATESCOUNT;
  rspButtonGroupSplitButtonSeparatorNormal = rspButtonGroupBorderMiddleNormal + DXBAR_STATESCOUNT;

  rspToolbarNormal               = rspButtonGroupSplitButtonSeparatorNormal + DXBAR_STATESCOUNT;
  rspToolbarHeaderNormal         = rspToolbarNormal + DXBAR_STATESCOUNT;

  rspMarkArrowNormal             = rspToolbarHeaderNormal + DXBAR_STATESCOUNT;
  rspMarkTruncatedNormal         = rspMarkArrowNormal + DXBAR_STATESCOUNT;
  rspLaunchButtonBackgroundNormal= rspMarkTruncatedNormal + DXBAR_STATESCOUNT;
  rspLaunchButtonDefaultGlyphNormal = rspLaunchButtonBackgroundNormal + DXBAR_STATESCOUNT;

  rspTabScrollLeftButtonNormal   = rspLaunchButtonDefaultGlyphNormal + DXBAR_STATESCOUNT;
  rspTabScrollRightButtonNormal  = rspTabScrollLeftButtonNormal + DXBAR_STATESCOUNT;
  rspGroupScrollLeftButtonNormal = rspTabScrollRightButtonNormal + DXBAR_STATESCOUNT;
  rspGroupScrollRightButtonNormal= rspGroupScrollLeftButtonNormal + DXBAR_STATESCOUNT;

  rspInRibbonGalleryScrollBarLineUpButtonNormal = rspGroupScrollRightButtonNormal + DXBAR_STATESCOUNT;
  rspInRibbonGalleryScrollBarLineUpButtonGlyphNormal = rspInRibbonGalleryScrollBarLineUpButtonNormal + DXBAR_STATESCOUNT;
  rspInRibbonGalleryScrollBarLineDownButtonNormal = rspInRibbonGalleryScrollBarLineUpButtonGlyphNormal + DXBAR_STATESCOUNT;
  rspInRibbonGalleryScrollBarLineDownButtonGlyphNormal = rspInRibbonGalleryScrollBarLineDownButtonNormal + DXBAR_STATESCOUNT;
  rspInRibbonGalleryScrollBarDropDownButtonNormal = rspInRibbonGalleryScrollBarLineDownButtonGlyphNormal + DXBAR_STATESCOUNT;
  rspInRibbonGalleryScrollBarDropDownButtonGlyphNormal = rspInRibbonGalleryScrollBarDropDownButtonNormal + DXBAR_STATESCOUNT;

  // For Ribbon 2010
  rfspCloseButtonHot               = rspInRibbonGalleryScrollBarDropDownButtonGlyphNormal + DXBAR_STATESCOUNT;
  rfspCloseButtonPressed           = rfspCloseButtonHot + 1;
  rfspCloseButtonInactiveHot       = rfspCloseButtonPressed + 1;
  rspMinimizeRibbonButtonMinimize  = rfspCloseButtonInactiveHot + 1; // 2 states
  rspMinimizeRibbonButtonRestore   = rspMinimizeRibbonButtonMinimize + 2;
  rspMinimizeRibbonButtonPin       = rspMinimizeRibbonButtonRestore + 2;
  rspItemSeparatorHorizontal       = rspMinimizeRibbonButtonPin + 2;
  rspItemSeparatorVertical         = rspItemSeparatorHorizontal + 1;
  rspMDIButtonMinimize             = rspItemSeparatorVertical + 1;
  rspMDIButtonRestore              = rspMDIButtonMinimize + 4;
  rspMDIButtonClose                = rspMDIButtonRestore + 4;
  rspTabsAreaOnGlass               = rspMDIButtonClose + 4;

  rspContextBackgroundMask         = rspTabsAreaOnGlass + 1;
  rspContextTabMaskNormal          = rspContextBackgroundMask + 1;
  rspContextTabMaskHot             = rspContextTabMaskNormal + 1;
  rspContextTabMaskActive          = rspContextTabMaskHot + 1;
  rspContextTabMaskActiveHot       = rspContextTabMaskActive + 1;
  rspContextTabMaskFocused         = rspContextTabMaskActiveHot + 1;

  // Ribbon BackstageView consts
  rbvpBackstageView               = rspContextTabMaskFocused + 1;
  rbvpBackstageViewBackButton     = rbvpBackstageView + 1; // 1 glyph + 1 mask
  rbvpBackstageViewFrame          = rbvpBackstageViewBackButton + 2; // 5 color schemes
  rbvpBackstageViewMenu           = rbvpBackstageViewFrame + 5;
  rbvpBackstageViewMenuHeader     = rbvpBackstageViewMenu + 1;
  rbvpBackstageViewMenuItem       = rbvpBackstageViewMenuHeader + 1; // 2 states * 5 color schemes
  rbvpBackstageViewMenuTabButton  = rbvpBackstageViewMenuItem + 10; // 4 states * 5 color schemes
  rbvpBackstageViewMenuTabButtonArrow  = rbvpBackstageViewMenuTabButton + 20;
  rbvpBackstageViewMenuSeparator  = rbvpBackstageViewMenuTabButtonArrow + 1;

  // PinButton
  rspPinButtonGlyph = rbvpBackstageViewMenuSeparator + 1; // 2 states

  // Application Button
  rspApplicationButton = rspPinButtonGlyph + 2; // 3 states * 5 color schemes

  // ScrollBar
  rspScrollBarHorz = rspApplicationButton + 15;
  rspScrollBarHorzThumb = rspScrollBarHorz + 4;
  rspScrollBarHorzThumbGlyph = rspScrollBarHorzThumb + 4;

  rspScrollBarVert = rspScrollBarHorzThumbGlyph + 1;
  rspScrollBarVertThumb = rspScrollBarVert + 4;
  rspScrollBarVertThumbGlyph = rspScrollBarVertThumb + 4;

  rspScrollBarButtonBottom = rspScrollBarVertThumbGlyph + 1;
  rspScrollBarButtonBottomGlyph = rspScrollBarButtonBottom + 4;
  rspScrollBarButtonTop = rspScrollBarButtonBottomGlyph + 1;
  rspScrollBarButtonTopGlyph = rspScrollBarButtonTop + 4;
  rspScrollBarButtonLeft = rspScrollBarButtonTopGlyph + 1;
  rspScrollBarButtonLeftGlyph = rspScrollBarButtonLeft + 4;
  rspScrollBarButtonRight = rspScrollBarButtonLeftGlyph + 1;
  rspScrollBarButtonRightGlyph = rspScrollBarButtonRight + 4;

  //next = rspScrollBarButtonRightGlyph + 1;

type
  TdxInRibbonGalleryScrollBarButtonKind = (gsbkLineUp, gsbkLineDown, gsbkDropDown);

  TdxRibbonApplicationButtonState = (rabsNormal, rabsHot, rabsPressed);
  TdxRibbonApplicationMenuState = (ramsHidden, ramsShownAsMenu, ramsShownAsFrame, ramsShownAsFullScreenFrame);
  TdxRibbonColorSchemeAccent = (rcsaYellow, rcsaBlue, rcsaGreen, rcsaOrange, rcsaPurple);
  TdxRibbonMinimizeButtonGlyph = (rmbMinimize, rmbRestore, rmbPin);
  TdxRibbonStyle = (rs2007, rs2010, rs2013);
  TdxRibbonTabState = (rtsNormal, rtsHot, rtsActive, rtsActiveHot, rtsFocused);

  TdxRibbonBorderIcon = (rbiSystemMenu, rbiMinimize, rbiMaximize, rbiHelp, rbiAutoHide, rbiAutoHideModeShowUI);
  TdxRibbonBorderIcons = set of TdxRibbonBorderIcon;
  TdxRibbonBorderIconState = (rbisNormal, rbisHot, rbisPressed, rbisInactive, rbisHotInactive);
  TdxRibbonBorderDrawIcon = (rbdiMinimize, rbdiMaximize, rbdiRestore, rbdiClose,
    rbdiHelp, rbdiAutoHide, rbdiAutoHideModeShowUI);

  { TdxRibbonFormData }

  TdxRibbonFormData = record
    Active: Boolean;
    Bounds: TRect;
    Border: TBorderStyle;
    BorderIcons: TdxRibbonBorderIcons;
    Handle: HWND;
    State: TWindowState;
    Style: TFormStyle;
    DontUseAero: Boolean;
    UseRoundedWindowCorners: Boolean;
  end;

  { TdxRibbonFormInfo }

  TdxRibbonFormInfo = record
    ApplicationMenuState: TdxRibbonApplicationMenuState;
    CaptionAreaExtention: Integer;
    CaptionHeight: Integer;
    ColorSchemeAccent: TdxRibbonColorSchemeAccent;
    FormData: TdxRibbonFormData;
    HasStatusBar: Boolean;
    IsRibbonHidden: Boolean;
    TabsHeight: Integer;
    RibbonHeight: Integer;
  end;

  TTwoStateArray = array[Boolean] of Integer;
  TThreeStateArray = array[0..2] of Integer;
  TFourStateArray = array[0..3] of Integer;
  TStatesArray = array[0..DXBAR_STATESCOUNT-1] of Integer;

  { TdxCustomRibbonSkin }

  TdxCustomRibbonSkin = class(TdxCustomBarSkin)
  private
    FReferenceCount: Integer;
    FLowColors: Boolean;
  protected
    FApplicationMenuBorder: Integer;
    FApplicationMenuButton: Integer;
    FApplicationMenuContentFooter: Integer;
    FApplicationMenuContentHeader: Integer;
    FButtonGroup: TStatesArray;
    FDropDownBorder: Integer;
    FDropDownGalleryBottomSizeGrip: Integer;
    FDropDownGalleryTopSizeGrip: Integer;
    FDropDownGalleryVerticalSizeGrip: Integer;
    FEditButtons: TStatesArray;
    FHelpButton: Integer;
    FLaunchButtonDefaultGlyphs: TStatesArray;
    FMarkTruncated: TStatesArray;
    FMenuContent: Integer;
    FMenuGlyph: Integer;
    FMenuMark: Integer;
    FMenuSeparatorHorz: Integer;
    FMenuSeparatorVert: Integer;
    FPinButtonGlyphs: TTwoStateArray;
    FProgressSubstrate: Integer;
    FQATAtBottom: Integer;
    FQATAtTopLeft: array[Boolean] of TTwoStateArray;
    FQATAtTopRight: TTwoStateArray;
    FQATGlassAtTopLeft: array[Boolean] of Integer;
    FQATGlassAtTopRight: Integer;
    FQATGroupButtonActive: TStatesArray;
    FQATGroupButtonInactive: TStatesArray;
    FScreenTip: Integer;
    FScrollArrow: Integer;
    FTabSeparator: Integer;
    //
    procedure AddTwoStateElement(ABitmap: GpBitmap; var AParts; const R, F: TRect;
      ID: Integer; AInterpolationMode: Integer = InterpolationModeNearestNeighbor);
    procedure InternalDrawSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean; AColor1, AColor2: TColor);
    // Common
    procedure LoadCommonElements(ABitmap: GpBitmap); virtual;
    procedure LoadCommonMenu(ABitmap: GpBitmap); virtual;
    // Ribbon
    procedure LoadRibbonButtons(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonElements(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonForm(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonGallery(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonMenu(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonQAT(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonTab(ABitmap: GpBitmap); virtual;
    //
    procedure LoadCommonTexturesSet(AImage: TdxGPImage); virtual;
    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); virtual; abstract;
    procedure LoadSkin;
    //
    function GetStyle: TdxRibbonStyle; virtual;
    //
    procedure DrawArrow(DC: HDC; const R: TRect; AArrowDirection: TcxArrowDirection; AState: Integer);
    procedure DrawDropDownGalleryVerticalSizeGrip(DC: HDC; const R: TRect);
    procedure DrawPart(DC: HDC; const R: TRect; AState: Integer); overload;
    procedure DrawPart(const AParts: TStatesArray; DC: HDC; const R: TRect; AState: Integer); overload;
    procedure DrawPartCentered(DC: HDC; const R: TRect; APartIndex: Integer);
    procedure DrawTabsAreaButton(DC: HDC; const R: TRect;
      AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure GetApplicationMenuContentColors(var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor); virtual;
    //
    property LowColors: Boolean read FLowColors write FLowColors;
  public
    constructor Create;
    procedure AddReference;
    procedure RemoveReference;

    // Load
    procedure LoadBitmapFromStream(const AResName: string; AImage: TdxGPImage);
    procedure LoadElementParts(ABitmap: GpBitmap; var AParts; const R: TRect; AID: Integer; const AFixedSize: TRect;
      const AImageIndexes: array of Byte; const APossibleStates: TdxByteSet; AIsTopDown: Boolean = True;
      AInterpolationMode: Integer = InterpolationModeDefault);
    procedure LoadElementPartsFromFile(const AFileName: string; var AParts; AID: Integer; const AFixedSize: TRect;
      const AImageIndexes: array of Byte; const APossibleStates: TdxByteSet);
    procedure LoadFourStateArray(ABitmap: GpBitmap; R: TRect; const Fixed: TRect; var AStateArray: TFourStateArray;
      AStartID: Integer; AIsVerticalLayout: Boolean = True; AInterpolationMode: Integer = InterpolationModeDefault);
    procedure LoadThreeStateArray(ABitmap: GpBitmap; R: TRect; const Fixed: TRect; var AStateArray: TThreeStateArray;
      AStartID: Integer; AIsVerticalLayout: Boolean = True; AInterpolationMode: Integer = InterpolationModeDefault);

    // Application Button
    procedure DrawApplicationButton(DC: HDC; const R: TRect;
      AState: TdxRibbonApplicationButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawApplicationMenuBackground(DC: HDC; const R, AContentRect: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawApplicationMenuButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawApplicationMenuExtraPaneButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawApplicationMenuExtraPanePinButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawApplicationMenuExtraPanePinButtonGlyph(DC: HDC; const R: TRect; AState: Integer;
      AChecked: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    function GetApplicationMenuContentOffset(const ATabsBounds: TRect): TRect; virtual;
    function GetApplicationMenuGlyphSize: TSize; virtual;
    function GetApplicationMenuTextColor(AState: TdxRibbonApplicationButtonState): TColor; virtual;

    // Button Group
    procedure DrawButtonGroup(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawButtonGroupDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawButtonGroupDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawButtonGroupBorderLeft(DC: HDC; const R: TRect); virtual;
    procedure DrawButtonGroupBorderMiddle(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawButtonGroupBorderRight(DC: HDC; const R: TRect); virtual;
    procedure DrawButtonGroupSplitButtonSeparator(DC: HDC; const R: TRect; AState: Integer); virtual;

    // CollapsedToolbar
    procedure DrawCollapsedToolbarBackground(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawCollapsedToolbarGlyphBackground(DC: HDC; const R: TRect; AState: Integer); virtual;

    // DropDownGaller
    procedure DrawDropDownGalleryBackground(DC: HDC; const R: TRect); virtual;
    procedure DrawDropDownGalleryBottomSizeGrip(DC: HDC; const R: TRect); virtual;
    procedure DrawDropDownGalleryBottomSizingBand(DC: HDC; const R: TRect); virtual;
    procedure DrawDropDownGalleryBottomVerticalSizeGrip(DC: HDC; const R: TRect); virtual;
    procedure DrawDropDownGalleryTopSizeGrip(DC: HDC; const R: TRect); virtual;
    procedure DrawDropDownGalleryTopSizingBand(DC: HDC; const R: TRect); virtual;
    procedure DrawDropDownGalleryTopVerticalSizeGrip(DC: HDC; const R: TRect); virtual;

    // Edit
    procedure DrawEditArrowButton(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawEditButton(DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawEditEllipsisButton(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawEditSpinDownButton(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawEditSpinUpButton(DC: HDC; const R: TRect; AState: Integer); virtual;

    // Form
    function AdjustCaptionFontSize(ASize: Integer; AUseAeroGlass: Boolean): Integer; virtual;
    procedure AdjustRibbonFormBorderIconSize(AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean; var ASize: TSize); virtual;
    function ExtendCaptionAreaOnTabs: Boolean; virtual;
    procedure DrawFormBorderIcon(DC: HDC; const R: TRect; AIcon: TdxRibbonBorderDrawIcon;
      AState: TdxRibbonBorderIconState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawFormBorders(DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo); virtual;
    procedure DrawFormCaption(DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo); virtual;
    procedure DrawFormStatusBarPart(DC: HDC; const R: TRect; AIsLeft, AIsActive, AIsRaised, AIsRectangular: Boolean;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    function GetWindowBordersWidth(AHasStatusBar: Boolean): TRect; virtual;
    function HasExternalRibbonFormShadow: Boolean; virtual;
    function UseRoundedWindowCorners: Boolean; virtual;

    // HelpButton
    procedure DrawHelpButton(DC: HDC; const R: TRect;
      AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawHelpButtonGlyph(DC: HDC; const R: TRect); virtual;

    // InRibbonGallery
    procedure DrawInRibbonGalleryBackground(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawInRibbonGalleryScrollBarBackground(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawInRibbonGalleryScrollBarButton(DC: HDC; const R: TRect; AButtonKind: TdxInRibbonGalleryScrollBarButtonKind;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawInRibbonGalleryScrollBarButtonGlyph(DC: HDC; R: TRect; AButtonKind: TdxInRibbonGalleryScrollBarButtonKind;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;

    // LargeButton
    procedure DrawLargeButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawLargeButtonDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawLargeButtonDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;

    // LaunchButton
    procedure DrawLaunchButtonBackground(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawLaunchButtonDefaultGlyph(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;

    // MDI Button
    procedure DrawMDIButton(DC: HDC; const R: TRect; AButton: TdxBarMDIButton;
      AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawMDIButtonGlyph(DC: HDC; const R: TRect; AButton: TdxBarMDIButton; AState: TcxButtonState); virtual;

    // Menu
    procedure DrawMenuArrowDown(DC: HDC; const R: TRect); virtual;
    procedure DrawMenuArrowRight(DC: HDC; const R: TRect); virtual;
    procedure DrawMenuCheck(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawMenuCheckMark(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawMenuContent(DC: HDC; const R: TRect); virtual;
    procedure DrawMenuDetachCaption(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawMenuExtraSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); virtual;
    procedure DrawMenuGlyph(DC: HDC; const R: TRect); virtual;
    procedure DrawMenuItem(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawMenuItemDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawMenuItemDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawMenuMark(DC: HDC; const R: TRect); virtual;
    procedure DrawMenuScrollArea(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawMenuSeparatorHorz(DC: HDC; const R: TRect); virtual;
    procedure DrawMenuSeparatorVert(DC: HDC; const R: TRect); virtual;
    function GetMenuSeparatorSize: Integer; virtual;

    // Minimize Button
    procedure DrawMinimizeRibbonButton(DC: HDC; const R: TRect; AState: TcxButtonState;
      AMinimized: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawMinimizeRibbonButtonGlyph(DC: HDC; const R: TRect; AState: TcxButtonState;
      AGlyph: TdxRibbonMinimizeButtonGlyph; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;

    // Progress
    procedure DrawProgressDiscreteBand(DC: HDC; const R: TRect); virtual;
    procedure DrawProgressSolidBand(DC: HDC; const R: TRect); virtual;
    procedure DrawProgressSubstrate(DC: HDC; const R: TRect); virtual;

    // SmallButton
    procedure DrawSmallButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawSmallButtonDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawSmallButtonDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;

    // BackstageView
    procedure DrawBackstageViewBackButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewMenuBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewMenuButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewTabButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewMenuHeader(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewMenuSeparator(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;

    // BackstageViewGalleryControl
    procedure DrawBackstageViewGalleryBackground(DC: HDC; const R: TRect); virtual;
    procedure DrawBackstageViewGalleryGroupHeader(DC: HDC; const R: TRect); virtual;
    procedure DrawBackstageViewGalleryItem(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewGalleryItemPinButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewGalleryItemPinButtonGlyph(DC: HDC; const R:
      TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewGalleryItemPinTag(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawBackstageViewGallerySeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;

    // Marks
    procedure DrawMarkArrow(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawMarkTruncated(DC: HDC; const R: TRect; AState: Integer); virtual;

    // Tab
    procedure DrawTab(DC: HDC; const R: TRect; AState: TdxRibbonTabState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawTabAreaBackground(DC: HDC; const R: TRect; AActive, AUseAeroGlass: Boolean;
      AApplicationMenuState: TdxRibbonApplicationMenuState); virtual;
    procedure DrawTabGroupBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); virtual;
    procedure DrawTabGroupHeaderBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); virtual;
    procedure DrawTabGroupsArea(DC: HDC; const R: TRect; AIsQATAtBottom, AIsInPopup: Boolean); virtual;
    procedure DrawTabScrollButton(DC: HDC; const R: TRect; ALeft: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawTabSeparator(DC: HDC; const R: TRect; Alpha: Byte); virtual;

    // Context
    procedure AdjustContextFont(AFont: TFont; AUseGlass: Boolean;
      AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure AdjustContextTabFont(AFont: TFont; AState: Integer;
      AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawContextBackground(DC: HDC; const R: TRect; AContextColor: TColor); virtual;
    procedure DrawContextBackgroundGlass(DC: HDC; const R: TRect; AContextColor: TColor); virtual;
    procedure DrawContextTabBackground(DC: HDC; const R: TRect; AState: TdxRibbonTabState;
      AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawContextTabGroupsArea(DC: HDC; const R: TRect;
      AContextColor: TColor; AIsQATAtBottom: Boolean; AIsInPopup: Boolean); virtual;
    procedure DrawContextTabSeparator(DC: HDC; const R: TRect; ABeginGroup: Boolean); virtual;

    // QAT
    procedure AdjustQuickAccessToolbarVertical(var ABounds: TRect; ANonClientDraw, ADontUseAero: Boolean); virtual;
    procedure DrawQuickAccessToolbar(DC: HDC; const R: TRect;
      ABellow, ANonClientDraw, AHasApplicationButton, AIsActive, ADontUseAero: Boolean); virtual;
    procedure DrawQuickAccessToolbarDefaultGlyph(DC: HDC; const R: TRect); virtual;
    procedure DrawQuickAccessToolbarGroupButton(DC: HDC; const R: TRect; ABellow, ANonClientDraw, AIsActive: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawQuickAccessToolbarPopup(DC: HDC; const R: TRect); virtual;
    function GetQuickAccessToolbarLeftIndent(AHasApplicationButton, AUseAeroGlass: Boolean): Integer; virtual;
    function GetQuickAccessToolbarMarkButtonOffset(AHasApplicationButton, ABelow: Boolean): Integer; virtual;
    function GetQuickAccessToolbarOverrideWidth(AHasApplicationButton, AUseAeroGlass: Boolean): Integer; virtual;
    function GetQuickAccessToolbarRightIndent(AHasApplicationButton: Boolean): Integer; virtual;

    // StatusBar
    procedure DrawStatusBar(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawStatusBarGripBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawStatusBarPanel(DC: HDC; const Bounds, R: TRect; AIsLowered: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawStatusBarPanelSeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawStatusBarSizeGrip(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawStatusBarToolbarSeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    function GetStatusBarSeparatorSize: Integer; virtual;

    // ScrollBars
    procedure DrawScrollBarBackground(DC: HDC; const R: TRect; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawScrollBarPart(DC: HDC; const R: TRect; APart: TcxScrollBarPart;
      AState: Integer; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    procedure DrawScrollBoxSizeGripArea(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    function GetScrollBarPainter: TcxCustomLookAndFeelPainter; virtual;

    // GroupScroll
    procedure DrawGroupScrollButton(DC: HDC; const R: TRect; ALeft: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); virtual;
    function NeedDrawGroupScrollArrow: Boolean; virtual;

    procedure DrawArrowDown(DC: HDC; const R: TRect; AState: Integer); virtual;
    procedure DrawDropDownBorder(DC: HDC; const R: TRect); virtual;
    procedure DrawGalleryFilterBandBackground(DC: HDC; const R: TRect); virtual;
    procedure DrawGalleryGroupHeaderBackground(DC: HDC; const R: TRect); virtual;
    procedure DrawItemSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); virtual;
    procedure DrawKeyTip(DC: HDC; const R: TRect); virtual;
    procedure DrawMiniToolbarBackground(DC: HDC; const R: TRect); virtual;
    procedure DrawRibbonBackground(DC: HDC; const R: TRect); virtual;
    procedure DrawRibbonClientTopArea(DC: HDC; const R: TRect); virtual;
    procedure DrawRibbonFormBackground(DC: HDC; const R: TRect; ARibbonHeight: Integer); virtual;
    procedure DrawRibbonTopFrameArea(DC: HDC; const R: TRect; AUseAeroGlass: Boolean); virtual;
    procedure DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect); virtual;
    procedure DrawScreenTip(DC: HDC; const R: TRect); virtual;
    procedure DrawScrollArrow(DC: HDC; const R: TRect); virtual;
    procedure DrawSeparatorBackground(DC: HDC; const R: TRect); virtual;
    procedure DrawSeparatorLine(DC: HDC; const R: TRect); virtual;

    function GetIsAlphaUsed(APart: Integer): Boolean; virtual;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; virtual;
    function GetPartContentOffsets(APart: Integer): TRect; virtual;
    function GetPartSize(APart: Integer): Integer; virtual;
    function GetSkinName: string; virtual;
    procedure UpdateBitsPerPixel;
    //
    property Style: TdxRibbonStyle read GetStyle;
  end;

  { TdxCustomRibbonTextureSkin }

  TdxCustomRibbonTexturedSkin = class(TdxCustomRibbonSkin)
  private
    FApplicationButton: array[TdxRibbonColorSchemeAccent] of TThreeStateArray;
    FArrowsDown: TStatesArray;
    FBorderIconGlyph: array[TdxRibbonBorderDrawIcon] of TFourStateArray;
    FBorderIcons: TThreeStateArray;
    FBottomBorderThick: array[Boolean] of TTwoStateArray;
    FBottomBorderThin: TTwoStateArray;
    FButtonGroupBorderLeft: Integer;
    FButtonGroupBorderMiddle: TStatesArray;
    FButtonGroupBorderRight: Integer;
    FButtonGroupSplitButtonSeparator: TStatesArray;
    FCaption: TTwoStateArray;
    FCaptionLeftBorder: TTwoStateArray;
    FCaptionRightBorder: TTwoStateArray;
    FCaptionZoomed: TTwoStateArray;
    FCollapsedToolbarGlyphBackgrounds: TStatesArray;
    FCollapsedToolbars: TStatesArray;
    FContextBackground: Integer;
    FContextBackgroundGlass: Integer;
    FContextTabGroupsArea: TTwoStateArray;
    FContextTabIndex: array[TdxRibbonTabState] of Integer;
    FContextTabSeparator: TTwoStateArray;
    FDropDownGalleryBottomSizingBand: Integer;
    FDropDownGalleryTopSizingBand: Integer;
    FFormStatusBarLeftParts: array[Boolean] of TFourStateArray;
    FFormStatusBarRightParts: array[Boolean] of TFourStateArray;
    FGalleryFilterBand: Integer;
    FGalleryGroupHeader: Integer;
    FGroupScrollButtons: array[Boolean] of TThreeStateArray;
    FInRibbonGalleryScrollBarDropDownButton: TStatesArray;
    FInRibbonGalleryScrollBarDropDownButtonGlyph: TStatesArray;
    FInRibbonGalleryScrollBarLineDownButton: TStatesArray;
    FInRibbonGalleryScrollBarLineDownButtonGlyph: TStatesArray;
    FInRibbonGalleryScrollBarLineUpButton: TStatesArray;
    FInRibbonGalleryScrollBarLineUpButtonGlyph: TStatesArray;
    FLargeButtonDropButtons: TStatesArray;
    FLargeButtonGlyphBackgrounds: TStatesArray;
    FLargeButtons: TStatesArray;
    FLaunchButtonBackgrounds: TStatesArray;
    FLeftBorder: TTwoStateArray;
    FMarkArrow: TStatesArray;
    FMenuArrowDown: Integer;
    FMenuArrowRight: Integer;
    FMenuCheck: TStatesArray;
    FMenuCheckMark: TStatesArray;
    FMenuDetachCaption: TStatesArray;
    FMenuScrollArea: TStatesArray;
    FProgressDiscreteBand: Integer;
    FProgressSolidBand: Integer;
    FQATDefaultGlyph: Integer;
    FQATPopup: Integer;
    FRibbonTopArea: Integer;
    FRightBorder: TTwoStateArray;
    FSmallButtonDropButtons: TStatesArray;
    FSmallButtonGlyphBackgrounds: TStatesArray;
    FSmallButtons: TStatesArray;
    FScrollBarBackground: array [Boolean] of TFourStateArray;
    FScrollBarButtonRightBottom: array [Boolean] of TFourStateArray;
    FScrollBarButtonRightBottomGlyph: array [Boolean] of Integer;
    FScrollBarButtonLeftTop: array [Boolean] of TFourStateArray;
    FScrollBarButtonLeftTopGlyph: array [Boolean] of Integer;
    FScrollBarThumb: array [Boolean] of TFourStateArray;
    FScrollBarThumbGlyph: array [Boolean] of Integer;
    FStatusBar: Integer;
    FStatusBarGripBackground: Integer;
    FStatusBarPanel: Integer;
    FStatusBarPanelLowered: Integer;
    FStatusBarPanelRaised: Integer;
    FStatusBarPanelSeparator: Integer;
    FStatusBarToolbarSeparator: Integer;
    FTabGroupsArea: TThreeStateArray;
    FTabIndex: array[TdxRibbonTabState] of Integer;
    FTabScrollButtons: array[Boolean] of TThreeStateArray;
    FToolbar: TStatesArray;
    FToolbarHeader: TStatesArray;
  protected
    procedure InternalDrawFormBorderIconGlyph(DC: HDC; const R: TRect;
      AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState;
      AColor: TColor = clDefault; AAlignment: TAlignment = taCenter);
    // Common
    procedure LoadCommonButtons(ABitmap: GpBitmap);
    procedure LoadCommonElements(ABitmap: GpBitmap); override;
    procedure LoadCommonMenu(ABitmap: GpBitmap); override;
    // Ribbon
    procedure LoadRibbonApplicationButton(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonButtons(ABitmap: GpBitmap); override;
    procedure LoadRibbonCollapsedToolbar(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonContexts(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonElements(ABitmap: GpBitmap); override;
    procedure LoadRibbonForm(ABitmap: GpBitmap); override;
    procedure LoadRibbonFormBorderIcons(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonFormBorderIconsGlyphs(ABitmap: GpBitmap; X, Y, AWidth, AHeight: Integer);
    procedure LoadRibbonFormBorders(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonGallery(ABitmap: GpBitmap); override;
    procedure LoadRibbonGalleryInRibbonScrollBarButtons(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonGalleryInRibbonScrollBarButtonsGlyphs(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonGroup(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonMenu(ABitmap: GpBitmap); override;
    procedure LoadRibbonQAT(ABitmap: GpBitmap); override;
    procedure LoadRibbonScrollBars(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonScrollButtons(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonStatusBar(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonTab(ABitmap: GpBitmap); override;
  public
    procedure DrawApplicationButton(DC: HDC; const R: TRect;
      AState: TdxRibbonApplicationButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawArrowDown(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawBackstageViewMenuSeparator(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupBorderLeft(DC: HDC; const R: TRect); override;
    procedure DrawButtonGroupBorderMiddle(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawButtonGroupBorderRight(DC: HDC; const R: TRect); override;
    procedure DrawButtonGroupSplitButtonSeparator(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawCollapsedToolbarBackground(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawCollapsedToolbarGlyphBackground(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawContextBackground(DC: HDC; const R: TRect; AColor: TColor); override;
    procedure DrawContextBackgroundGlass(DC: HDC; const R: TRect; AColor: TColor); override;
    procedure DrawContextTabBackground(DC: HDC; const R: TRect; AState: TdxRibbonTabState;
      AColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawContextTabGroupsArea(DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean); override;
    procedure DrawContextTabSeparator(DC: HDC; const R: TRect; ABeginGroup: Boolean); override;
    procedure DrawDropDownGalleryBottomSizingBand(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryTopSizingBand(DC: HDC; const R: TRect); override;
    procedure DrawFormBorders(DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo); override;
    procedure DrawFormBorderIcon(DC: HDC; const R: TRect; AIcon: TdxRibbonBorderDrawIcon;
      AState: TdxRibbonBorderIconState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawFormCaption(DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo); override;
    procedure DrawFormStatusBarPart(DC: HDC; const R: TRect;
      AIsLeft, AIsActive, AIsRaised, AIsRectangular: Boolean;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawGalleryFilterBandBackground(DC: HDC; const R: TRect); override;
    procedure DrawGalleryGroupHeaderBackground(DC: HDC; const R: TRect); override;
    procedure DrawGroupScrollButton(DC: HDC; const R: TRect; ALeft: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawInRibbonGalleryScrollBarButton(DC: HDC; const R: TRect;
      AButtonKind: TdxInRibbonGalleryScrollBarButtonKind; AState: Integer;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLargeButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLargeButtonDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLargeButtonDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLaunchButtonBackground(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLaunchButtonDefaultGlyph(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMarkArrow(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawMDIButton(DC: HDC; const R: TRect; AButton: TdxBarMDIButton;
      AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMDIButtonGlyph(DC: HDC; const R: TRect;
      AButton: TdxBarMDIButton; AState: TcxButtonState); override;
    procedure DrawMenuArrowDown(DC: HDC; const R: TRect); override;
    procedure DrawMenuArrowRight(DC: HDC; const R: TRect); override;
    procedure DrawMenuCheck(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuCheckMark(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuDetachCaption(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawMenuScrollArea(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawProgressDiscreteBand(DC: HDC; const R: TRect); override;
    procedure DrawProgressSolidBand(DC: HDC; const R: TRect); override;
    procedure DrawProgressSubstrate(DC: HDC; const R: TRect); override;
    procedure DrawQuickAccessToolbarDefaultGlyph(DC: HDC; const R: TRect); override;
    procedure DrawQuickAccessToolbarPopup(DC: HDC; const R: TRect); override;
    procedure DrawRibbonClientTopArea(DC: HDC; const R: TRect); override;
    procedure DrawScrollBarBackground(DC: HDC; const R: TRect; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawScrollBarPart(DC: HDC; const R: TRect; APart: TcxScrollBarPart;
      AState: Integer; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawSmallButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawSmallButtonDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawSmallButtonDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBar(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarGripBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarPanel(DC: HDC; const Bounds, R: TRect; AIsLowered: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarPanelSeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarToolbarSeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawTab(DC: HDC; const R: TRect; AState: TdxRibbonTabState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawTabGroupBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); override;
    procedure DrawTabGroupHeaderBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); override;
    procedure DrawTabGroupsArea(DC: HDC; const R: TRect; AIsQATAtBottom, AIsInPopup: Boolean); override;
    procedure DrawTabScrollButton(DC: HDC; const R: TRect; ALeft: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
  end;

  { TdxCustomRibbon2010Skin }

  TdxCustomRibbon2010Skin = class(TdxCustomRibbonTexturedSkin)
  protected
    FBackstageViewFrame: array[TdxRibbonColorSchemeAccent] of Integer;
    FBackstageViewMenuBackground: Integer;
    FBackstageViewMenuButton: array[TdxRibbonColorSchemeAccent] of TTwoStateArray;
    FBackstageViewMenuSeparator: Integer;
    FBackstageViewTabArrow: Integer;
    FBackstageViewTabs: array[TdxRibbonColorSchemeAccent] of TFourStateArray;
    FCloseButton: TThreeStateArray;
    FContextBackgroundMask: Integer;
    FContextTabMaskIndex: array[TdxRibbonTabState] of Integer;
    FItemsSeparator: TTwoStateArray;
    FMDIButtonGlyphs: array[TdxBarMDIButton] of TFourStateArray;
    FMinimizeRibbonButtonGlyph: array[TdxRibbonMinimizeButtonGlyph] of TTwoStateArray;
    FTabsAreaOnGlass: Integer;

    function GetStyle: TdxRibbonStyle; override;
    procedure DrawColoredElement(APartIndex: Integer; DC: HDC; const R: TRect; AColor: TColor);
    procedure DrawFormCaptionSeparator(DC: HDC; const R: TRect); virtual;
    // Common
    procedure LoadCommonApplicationButton(ABitmap: GpBitmap); virtual;
    procedure LoadCommonBackstageView(ABitmap: GpBitmap); virtual;
    procedure LoadCommonElements(ABitmap: GpBitmap); override;
    procedure LoadCommonMenu(ABitmap: GpBitmap); override;
    procedure LoadCommonTexturesSet(AImage: TdxGPImage); override;
    // Ribbon
    procedure LoadRibbonApplicationButton(ABitmap: GpBitmap); override;
    procedure LoadRibbonBackstageView(ABitmap: GpBitmap); virtual;
    procedure LoadRibbonCollapsedToolbar(ABitmap: GpBitmap); override;
    procedure LoadRibbonContexts(ABitmap: GpBitmap); override;
    procedure LoadRibbonElements(ABitmap: GpBitmap); override;
    procedure LoadRibbonForm(ABitmap: GpBitmap); override;
    procedure LoadRibbonFormBorderIcons(ABitmap: GpBitmap); override;
    procedure LoadRibbonFormBorders(ABitmap: GpBitmap); override;
    procedure LoadRibbonGalleryInRibbonScrollBarButtonsGlyphs(ABitmap: GpBitmap); override;
    procedure LoadRibbonGroup(ABitmap: GpBitmap); override;
    procedure LoadRibbonStatusBar(ABitmap: GpBitmap); override;
    procedure LoadRibbonTab(ABitmap: GpBitmap); override;
  public
    procedure DrawBackstageViewBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuSeparator(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewTabButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    procedure AdjustContextFont(AFont: TFont; AUseGlass: Boolean;
      AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawContextBackground(DC: HDC; const R: TRect; AColor: TColor); override;
    procedure DrawContextBackgroundGlass(DC: HDC; const R: TRect; AColor: TColor); override;
    procedure DrawContextTabBackground(DC: HDC; const R: TRect; AState: TdxRibbonTabState;
      AColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    procedure DrawApplicationMenuBackground(DC: HDC; const R, AContentRect: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroup(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawContextTabGroupsArea(DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean); override;
    procedure DrawFormBorderIcon(DC: HDC; const R: TRect; AIcon: TdxRibbonBorderDrawIcon;
      AState: TdxRibbonBorderIconState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawFormCaption(DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo); override;
    procedure DrawItemSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); override;
    procedure DrawMenuExtraSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); override;
    procedure DrawMDIButtonGlyph(DC: HDC; const R: TRect;
      AButton: TdxBarMDIButton; AState: TcxButtonState); override;
    procedure DrawMinimizeRibbonButtonGlyph(DC: HDC; const R: TRect; AState: TcxButtonState;
      AGlyph: TdxRibbonMinimizeButtonGlyph; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawQuickAccessToolbar(DC: HDC; const R: TRect;
      ABellow, ANonClientDraw, AHasApplicationButton, AIsActive, ADontUseAero: Boolean); override;
    procedure DrawRibbonTopFrameArea(DC: HDC; const R: TRect; AUseAeroGlass: Boolean); override;
    procedure DrawSeparatorLine(DC: HDC; const R: TRect); override;
    procedure DrawTabGroupBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); override;
    procedure DrawTabGroupHeaderBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); override;
    function GetApplicationMenuContentOffset(const ATabsBounds: TRect): TRect; override;
    function GetApplicationMenuGlyphSize: TSize; override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
    function GetPartContentOffsets(APart: Integer): TRect; override;
    function GetPartSize(APart: Integer): Integer; override;
    function GetQuickAccessToolbarMarkButtonOffset(AHasApplicationButton, ABelow: Boolean): Integer; override;
    function GetQuickAccessToolbarOverrideWidth(AHasApplicationButton, AUseAeroGlass: Boolean): Integer; override;
    function GetWindowBordersWidth(AHasStatusBar: Boolean): TRect; override;
  end;

  { TdxBlueRibbonSkin }

  TdxBlueRibbonSkin = class(TdxCustomRibbonTexturedSkin)
  protected
    function GetName: string; override;
    procedure GetApplicationMenuContentColors(var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor); override;
    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); override;
  public
    procedure DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect); override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
  end;

  { TdxBlackRibbonSkin }

  TdxBlackRibbonSkin = class(TdxCustomRibbonTexturedSkin)
  protected
    function GetName: string; override;
    procedure GetApplicationMenuContentColors(var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor); override;
    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); override;
  public
    procedure DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect); override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
  end;

  { TdxSilverRibbonSkin }

  TdxSilverRibbonSkin = class(TdxBlackRibbonSkin)
  protected
    function GetName: string; override;
    procedure GetApplicationMenuContentColors(var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor); override;
    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); override;
  public
    procedure DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect); override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
  end;

  { TdxBlueRibbon2010Skin }

  TdxBlueRibbon2010Skin = class(TdxCustomRibbon2010Skin)
  protected
    function GetName: string; override;
    procedure DrawFormCaptionSeparator(DC: HDC; const R: TRect); override;
    procedure GetApplicationMenuContentColors(var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor); override;
    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); override;
  public
    procedure DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect); override;
    procedure DrawTabAreaBackground(DC: HDC; const R: TRect; AActive: Boolean;
      AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState); override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
  end;

  { TdxSilverRibbon2010Skin }

  TdxSilverRibbon2010Skin = class(TdxCustomRibbon2010Skin)
  protected
    procedure DrawFormCaptionSeparator(DC: HDC; const R: TRect); override;
    procedure GetApplicationMenuContentColors(var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor); override;
    function GetName: string; override;
    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); override;
  public
    procedure DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect); override;
    procedure DrawTabAreaBackground(DC: HDC; const R: TRect;
      AActive, AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState); override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
  end;

  { TdxBlackRibbon2010Skin }

  TdxBlackRibbon2010Skin = class(TdxCustomRibbon2010Skin)
  protected
    procedure DrawFormCaptionSeparator(DC: HDC; const R: TRect); override;
    procedure GetApplicationMenuContentColors(var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor); override;
    function GetName: string; override;
    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); override;
  public
    procedure DrawMenuExtraSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); override;
    procedure DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect); override;
    procedure DrawTabAreaBackground(DC: HDC; const R: TRect; AActive: Boolean;
      AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState); override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
  end;

  { TdxCustomRibbon2013Skin }

  TdxCustomRibbon2013Skin = class(TdxCustomRibbon2010Skin)
  protected
    FBackstageViewBackButton: TTwoStateArray;
    procedure LoadCommonBackstageView(ABitmap: Pointer); override;
    procedure LoadCommonTexturesSet(AImage: TdxGPImage); override;
    procedure LoadRibbonFormBorderIcons(ABitmap: Pointer); override;
    procedure LoadRibbonTexturesSet(AImage: TdxGPImage); override;

    function GetAccentColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor; overload;
    function GetAccentColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent; const ALightnessDelta: Double): TColor; overload;
    function GetCaptionAreaColor(AApplicationMenuState: TdxRibbonApplicationMenuState): TColor; virtual;
    function GetFormBackgroundColor1: TColor; virtual;
    function GetFormBackgroundColor2: TColor; virtual;
    function GetFormBorderColor(AActive: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor; virtual;
    function GetFrameColor: TColor; virtual;
    function GetGlyphColor(AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor; virtual;
    function GetHighlightBorderColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor; virtual;
    function GetHighlightContentColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor; virtual;
    function GetMasterColor: TColor; virtual; abstract;
    function GetMenuBackgroundColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor; overload; virtual;
    function GetMenuBackgroundColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent; const ALightnessDelta: Double): TColor; overload;
    function GetStyle: TdxRibbonStyle; override;
    function GetTabGroupsAreaContentColor: TColor; virtual; abstract;
  public
    procedure DrawApplicationButton(DC: HDC; const R: TRect;
      AState: TdxRibbonApplicationButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawArrowDown(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawRibbonClientTopArea(DC: HDC; const R: TRect); override;

    // Application Menu
    procedure DrawApplicationMenuBackground(DC: HDC; const R: TRect;
      const AContentRect: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawApplicationMenuButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawApplicationMenuExtraPanePinButtonGlyph(DC: HDC; const R: TRect; AState: Integer;
      AChecked: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuExtraSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); override;

    // BackstageView
    procedure DrawBackstageViewBackButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuBackground(DC: HDC; const R: TRect;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuHeader(DC: HDC; const R: TRect;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewMenuSeparator(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawBackstageViewTabButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // ButtonGroup
    procedure DrawButtonGroup(DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupBorderLeft(DC: HDC; const R: TRect); override;
    procedure DrawButtonGroupBorderMiddle(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawButtonGroupBorderRight(DC: HDC; const R: TRect); override;
    procedure DrawButtonGroupDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawButtonGroupSplitButtonSeparator(DC: HDC; const R: TRect; AState: Integer); override;

    // Collapsed Toolbar
    procedure DrawCollapsedToolbarGlyphBackground(DC: HDC; const R: TRect; AState: Integer); override;
    procedure DrawCollapsedToolbarBackground(DC: HDC; const R: TRect; AState: Integer); override;

    // Context
    procedure AdjustContextFont(AFont: TFont; AUseGlass: Boolean;
      AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure AdjustContextTabFont(AFont: TFont; AState: Integer;
      AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawContextBackground(DC: HDC; const R: TRect; AColor: TColor); override;
    procedure DrawContextBackgroundGlass(DC: HDC; const R: TRect; AContextColor: TColor); override;
    procedure DrawContextTabBackground(DC: HDC; const R: TRect; AState: TdxRibbonTabState;
      AColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawContextTabGroupsArea(DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean); override;
    procedure DrawContextTabSeparator(DC: HDC; const R: TRect; ABeginGroup: Boolean); override;

    // Gallery
    procedure DrawDropDownGalleryBackground(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryBottomSizingBand(DC: HDC; const R: TRect); override;
    procedure DrawDropDownGalleryTopSizingBand(DC: HDC; const R: TRect); override;
    procedure DrawGalleryFilterBandBackground(DC: HDC; const R: TRect); override;
    procedure DrawGalleryGroupHeaderBackground(DC: HDC; const R: TRect); override;
    procedure DrawInRibbonGalleryScrollBarButton(DC: HDC; const R: TRect;
      AButtonKind: TdxInRibbonGalleryScrollBarButtonKind; AState: Integer;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Edit
    procedure DrawEditButton(DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Form
    procedure DrawFormBorderIcon(DC: HDC; const R: TRect; AIcon: TdxRibbonBorderDrawIcon;
      AState: TdxRibbonBorderIconState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawFormBorders(DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo); override;
    procedure DrawFormCaption(DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo); override;
    procedure DrawFormStatusBarPart(DC: HDC; const R: TRect; AIsLeft, AIsActive: Boolean;
      AIsRaised, AIsRectangular: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawRibbonFormBackground(DC: HDC; const R: TRect; ARibbonHeight: Integer); override;

    // SmallButton
    procedure DrawSmallButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawSmallButtonDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawSmallButtonDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // LargeButton
    procedure DrawLargeButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLargeButtonDropButtonArrowPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLargeButtonDropButtonMainPart(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // LaunchButton
    procedure DrawLaunchButtonBackground(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawLaunchButtonDefaultGlyph(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    //Menu
    procedure DrawDropDownBorder(DC: HDC; const R: TRect); override;
    procedure DrawMenuCheck(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuCheckMark(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawMenuContent(DC: HDC; const R: TRect); override;
    procedure DrawMenuGlyph(DC: HDC; const R: TRect); override;
    procedure DrawMenuSeparatorHorz(DC: HDC; const R: TRect); override;
    procedure DrawMenuSeparatorVert(DC: HDC; const R: TRect); override;

    // QuickAccessToolbar
    procedure DrawQuickAccessToolbar(DC: HDC; const R: TRect;
      ABellow, ANonClientDraw, AHasApplicationButton, AIsActive, ADontUseAero: Boolean); override;
    procedure DrawQuickAccessToolbarGroupButton(DC: HDC; const R: TRect;
      ABellow, ANonClientDraw, AIsActive: Boolean; AState: Integer;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawQuickAccessToolbarPopup(DC: HDC; const R: TRect); override;

    // ScrollButton
    procedure DrawGroupScrollButton(DC: HDC; const R: TRect; ALeft: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawTabScrollButton(DC: HDC; const R: TRect; ALeft: Boolean;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // ScrollBar
    procedure DrawScrollBarBackground(DC: HDC; const R: TRect;
      AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawScrollBarPart(DC: HDC; const R: TRect; APart: TcxScrollBarPart;
      AState: Integer; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawScrollBoxSizeGripArea(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    function GetScrollBarBackgroundColor: TColor; virtual;
    function GetScrollBarPartBorderColor(APart: TcxScrollBarPart; AState: Integer): TColor; virtual;
    function GetScrollBarPartContentColor(APart: TcxScrollBarPart; AState: Integer): TColor; virtual;

    // Separator
    procedure DrawSeparatorBackground(DC: HDC; const R: TRect); override;
    procedure DrawSeparatorLine(DC: HDC; const R: TRect); override;

    // StatusBar
    procedure DrawStatusBar(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarGripBackground(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarSizeGrip(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarPanel(DC: HDC; const Bounds: TRect; const R: TRect;
      AIsLowered: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarPanelSeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawStatusBarToolbarSeparator(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;

    // Tab
    procedure DrawTab(DC: HDC; const R: TRect; AState: TdxRibbonTabState; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawTabAreaBackground(DC: HDC; const R: TRect; AActive: Boolean;
      AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState); override;

    // TabGroup
    procedure DrawTabGroupBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); override;
    procedure DrawTabGroupHeaderBackground(DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean); override;
    procedure DrawTabGroupsArea(DC: HDC; const R: TRect; AIsQATAtBottom, AIsInPopup: Boolean); override;

    procedure DrawMinimizeRibbonButtonGlyph(DC: HDC; const R: TRect; AState: TcxButtonState;
      AGlyph: TdxRibbonMinimizeButtonGlyph; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    procedure DrawItemSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean); override;
    procedure DrawKeyTip(DC: HDC; const R: TRect); override;

    function HasExternalRibbonFormShadow: Boolean; override;
    function GetPartColor(APart: Integer; AState: Integer = 0;
      AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor; override;
    function GetPartContentOffsets(APart: Integer): TRect; override;
    function GetPartSize(APart: Integer): Integer; override;
    function GetWindowBordersWidth(AHasStatusBar: Boolean): TRect; override;
    function UseRoundedWindowCorners: Boolean; override;
  end;

  { TdxLightGrayRibbon2013Skin }

  TdxLightGrayRibbon2013Skin = class(TdxCustomRibbon2013Skin)
  protected
    function GetName: string; override;
    function GetFormBackgroundColor2: TColor; override;
    function GetMasterColor: TColor; override;
    function GetMenuBackgroundColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor; override;
    function GetTabGroupsAreaContentColor: TColor; override;
  public
    // ScrollBar
    function GetScrollBarBackgroundColor: TColor; override;
    function GetScrollBarPartContentColor(APart: TcxScrollBarPart; AState: Integer): TColor; override;
  end;

  { TdxDarkGrayRibbon2013Skin }

  TdxDarkGrayRibbon2013Skin = class(TdxCustomRibbon2013Skin)
  protected
    function GetName: string; override;
    function GetFormBackgroundColor2: TColor; override;
    function GetFrameColor: TColor; override;
    function GetMasterColor: TColor; override;
    function GetMenuBackgroundColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor; override;
    function GetTabGroupsAreaContentColor: TColor; override;
  public
    procedure DrawBackstageViewTabButton(DC: HDC; const R: TRect;
      AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent); override;
    // ScrollBar
    function GetScrollBarBackgroundColor: TColor; override;
    function GetScrollBarPartContentColor(APart: TcxScrollBarPart; AState: Integer): TColor; override;
  end;

  { TdxWhiteRibbon2013Skin }

  TdxWhiteRibbon2013Skin = class(TdxCustomRibbon2013Skin)
  protected
    function GetName: string; override;
    function GetFormBackgroundColor2: TColor; override;
    function GetMasterColor: TColor; override;
    function GetTabGroupsAreaContentColor: TColor; override;
  public
    // ScrollBar
    function GetScrollBarPartBorderColor(APart: TcxScrollBarPart; AState: Integer): TColor; override;
    function GetScrollBarPartContentColor(APart: TcxScrollBarPart; AState: Integer): TColor; override;
  end;

  { TdxRibbonSkinsManager }

  TdxRibbonSkinsManager = class(TObject)
  private
    FList: TcxObjectList;
    function GetSkin(Index: Integer): TdxCustomRibbonSkin;
    function GetSkinCount: Integer;
  protected
    procedure Changed; virtual;
  public
    constructor Create;
    destructor Destroy; override;
    function Add(ASkin: TdxCustomRibbonSkin): Integer;
    function Find(const AName: string; AStyle: TdxRibbonStyle): TdxCustomRibbonSkin;
    function Remove(ASkin: TdxCustomRibbonSkin): Boolean;
    //
    property SkinCount: Integer read GetSkinCount;
    property Skins[Index: Integer]: TdxCustomRibbonSkin read GetSkin; default;
  end;

const
  dxRibbonColorSchemeAccentNames: array[TdxRibbonColorSchemeAccent] of string = (
    'Yellow', 'Blue', 'Green', 'Orange', 'Purple'
  );

function IsRectangularFormBottom(const AData: TdxRibbonFormData): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function dxRibbonSkinsManager: TdxRibbonSkinsManager;
implementation

uses
  Types, cxGeometry, dxOffice11, Math, cxDWMApi;

{$R dxRibbonSkins.res}

const
  BorderIconStateToPartIndex: array[TdxRibbonBorderIconState] of Integer = (-1, 0, 1, -1, 2);
  DefaultFixedSize: TRect = (Left: 2; Top: 2; Right: 2; Bottom: 2);

var
  FSkinsManager: TdxRibbonSkinsManager;

function dxRibbonSkinsManager: TdxRibbonSkinsManager;
begin
  if FSkinsManager = nil then
    FSkinsManager := TdxRibbonSkinsManager.Create;
  Result := FSkinsManager;
end;

function IsRectangularFormBottom(const AData: TdxRibbonFormData): Boolean;
begin
  Result := (AData.Border in [bsDialog, bsSingle, bsToolWindow]) or
    (AData.Style = fsMDIChild) or (AData.State = wsMinimized) or not AData.UseRoundedWindowCorners;
end;

procedure ExcludeClipRect(DC: HDC; const R: TRect);
begin
  Windows.ExcludeClipRect(DC, R.Left, R.Top, R.Right, R.Bottom);
end;

procedure DrawFrame(DC: HDC; const R: TRect; AColor, ABorderColor: TColor;
  const ABorders: TcxBorders = cxBordersAll; ABorderWidth: Integer = 1; AIsPaintOnGlass: Boolean = False);

  function GetBorderBounds(ABorder: TcxBorder; var ABounds: TRect): TRect;
  begin
    Result := R;
    case ABorder of
      bLeft:
        begin
          Result.Right := Result.Left + ABorderWidth;
          Inc(ABounds.Left, ABorderWidth);
        end;
      bTop:
        begin
          Result.Bottom := Result.Top + ABorderWidth;
          Inc(ABounds.Top, ABorderWidth);
        end;
      bRight:
        begin
          Result.Left := Result.Right - ABorderWidth;
          Dec(ABounds.Right, ABorderWidth);
        end;
      bBottom:
        begin
          Result.Top := Result.Bottom - ABorderWidth;
          Dec(ABounds.Bottom, ABorderWidth);
        end;
    end;
  end;

  procedure DoFillRect(const R: TRect; AColor: TColor);
  begin
    if cxColorIsValid(AColor) and not cxRectIsEmpty(R) then
    begin
      if AIsPaintOnGlass then
        dxGpFillRect(DC, R, AColor)
      else
        FillRectByColor(DC, R, AColor);
    end;
  end;

var
  ABorder: TcxBorder;
  ABounds: TRect;
begin
  if not cxRectIsEmpty(R) then
  begin
    ABounds := R;
    if (ABorders <> []) and (ABorderColor <> clNone) then
    begin
      for ABorder := Low(ABorder) to High(ABorder) do
      begin
        if ABorder in ABorders then
          DoFillRect(GetBorderBounds(ABorder, ABounds), ABorderColor);
      end;
    end;
    DoFillRect(ABounds, AColor);
  end;
end;

function RibbonStateToButtonState(AState: Integer): TcxButtonState;
begin
  case AState of
    DXBAR_DISABLED:
      Result := cxbsDisabled;
    DXBAR_HOT:
      Result := cxbsHot;
    DXBAR_PRESSED:
      Result := cxbsPressed;
    else
      Result := cxbsNormal;
  end;
end;

procedure OutError;
begin
  raise EdxException.Create('');
end;

{ TdxCustomRibbonSkin }

constructor TdxCustomRibbonSkin.Create;
begin
  inherited Create;
  UpdateBitsPerPixel;
end;

procedure TdxCustomRibbonSkin.AddReference;
begin
  Inc(FReferenceCount);
  if FReferenceCount = 1 then
    LoadSkin;
end;

procedure TdxCustomRibbonSkin.RemoveReference;
begin
  Dec(FReferenceCount);
  if FReferenceCount = 0 then
    Clear;
end;

procedure TdxCustomRibbonSkin.LoadBitmapFromStream(const AResName: string; AImage: TdxGPImage);
var
  AResStream: TStream;
begin
  AResStream := TResourceStream.Create(HInstance, AResName, RT_RCDATA);
  try
    AImage.LoadFromStream(AResStream);
  finally
    AResStream.Free;
  end;
end;

procedure TdxCustomRibbonSkin.LoadElementParts(ABitmap: GpBitmap;
  var AParts; const R: TRect; AID: Integer; const AFixedSize: TRect;
  const AImageIndexes: array of Byte; const APossibleStates: TdxByteSet;
  AIsTopDown: Boolean = True; AInterpolationMode: Integer = InterpolationModeDefault);
var
  I, J, AImageIndex: Integer;
  AOffsetSize: TSize;
  ALoadRect: TRect;
begin
  J := 0;
  if AIsTopDown then
  begin
    AOffsetSize.cx := 0;
    AOffsetSize.cy := cxRectHeight(R);
  end
  else
  begin
    AOffsetSize.cx := cxRectWidth(R);
    AOffsetSize.cy := 0;
  end;
  for I := Low(TStatesArray) to High(TStatesArray) do
  begin
    if (APossibleStates = []) or (I in APossibleStates) then
    begin
      if Length(AImageIndexes) = 0 then
        AImageIndex := J
      else
        if J < Length(AImageIndexes) then
          AImageIndex := AImageIndexes[J]
        else
          AImageIndex := 0;
      ALoadRect := cxRectOffset(R, AOffsetSize.cx * AImageIndex, AOffsetSize.cy * AImageIndex);
      Inc(J);
      if cxRectIsEqual(cxEmptyRect, AFixedSize) then
        TStatesArray(AParts)[I] := AddPart1x1(ABitmap, ALoadRect, AID, '', AInterpolationMode)
      else
        TStatesArray(AParts)[I] := AddPart3x3(ABitmap, ALoadRect, AFixedSize, AID, '', AInterpolationMode);
    end;
    Inc(AID);
  end;
end;

procedure TdxCustomRibbonSkin.LoadElementPartsFromFile(const AFileName: string; var AParts; AID: Integer;
  const AFixedSize: TRect; const AImageIndexes: array of Byte; const APossibleStates: TdxByteSet);
var
  ABitmap: GpGraphics;
  AImageRect: TRect;
begin
  if not CheckGdiPlus then Exit;
  GdipCheck(GdipLoadImageFromFile(PWideChar(WideString(AFileName)), ABitmap));
  AImageRect.Left := 0;
  AImageRect.Top := 0;
  GdipCheck(GdipGetImageWidth(ABitmap, AImageRect.Right));
  GdipCheck(GdipGetImageHeight(ABitmap, AImageRect.Bottom));
  LoadElementParts(ABitmap, AParts, AImageRect, AID, AFixedSize, AImageIndexes,
    APossibleStates);
  GdipDisposeImage(ABitmap);
end;

procedure TdxCustomRibbonSkin.LoadFourStateArray(ABitmap: GpBitmap; R: TRect; const Fixed: TRect;
  var AStateArray: TFourStateArray; AStartID: Integer; AIsVerticalLayout: Boolean; AInterpolationMode: Integer);
var
  I: Integer;
begin
  for I := 0 to 3 do
  begin
    AStateArray[I] := AddPart3x3(ABitmap, R, Fixed, AStartID, '', AInterpolationMode);
    if AIsVerticalLayout then
      OffsetRect(R, 0, R.Bottom - R.Top)
    else
      OffsetRect(R, R.Right - R.Left, 0);
    Inc(AStartID);
  end;
end;

procedure TdxCustomRibbonSkin.LoadThreeStateArray(ABitmap: GpBitmap; R: TRect; const Fixed: TRect;
  var AStateArray: TThreeStateArray; AStartID: Integer; AIsVerticalLayout: Boolean = True;
  AInterpolationMode: Integer = InterpolationModeDefault);
var
  I: Integer;
begin
  for I := 0 to 2 do
  begin
    AStateArray[I] := AddPart3x3(ABitmap, R, Fixed, AStartID, '', AInterpolationMode);
    if AIsVerticalLayout then
      OffsetRect(R, 0, R.Bottom - R.Top)
    else
      OffsetRect(R, R.Right - R.Left, 0);
    Inc(AStartID);
  end;
end;

procedure TdxCustomRibbonSkin.DrawApplicationButton(DC: HDC; const R: TRect;
  AState: TdxRibbonApplicationButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  PenColorMap: array[Boolean] of TColor = (clBtnShadow, clWhite);
  BrushColorMap: array[Boolean] of TColor = (clHighlight, clBtnFace);
  TabStateMap: array[TdxRibbonApplicationButtonState] of TdxRibbonTabState = (rtsNormal, rtsHot, rtsActive);
var
  ARect: TRect;
begin
  if Style >= rs2010 then
    DrawTab(DC, R, TabStateMap[AState], AColorSchemeAccent)
  else
  begin
    cxPaintCanvas.BeginPaint(DC);
    try
      ARect := cxRectInflate(R, -1, -1);

      cxPaintCanvas.Brush.Color := BrushColorMap[AState = rabsNormal];
      cxPaintCanvas.Pen.Color := PenColorMap[AState <> rabsPressed];
      cxPaintCanvas.Pen.Width := 3;
      cxPaintCanvas.Canvas.Ellipse(ARect);

      cxPaintCanvas.Brush.Style := bsClear;;
      cxPaintCanvas.Pen.Color := clBlack;
      cxPaintCanvas.Pen.Width := 1;
      cxPaintCanvas.Canvas.Ellipse(ARect);
    finally
      cxPaintCanvas.EndPaint;
    end;
  end;
end;

procedure TdxCustomRibbonSkin.DrawApplicationMenuBackground(
  DC: HDC; const R, AContentRect: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  AInnerBorderColor, AOuterBorderColor, ASideColor: TColor;
  AInnerBorderRect, AOuterBorderRect: TRect;
  R1, AHeaderRect, AFooterRect: TRect;
begin
  R1 := cxRectInflate(R, -2, -2);
  AInnerBorderRect := cxRectInflate(AContentRect, 1, 1);
  AOuterBorderRect := cxRectInflate(AInnerBorderRect, 1, 1);
  AHeaderRect := cxRectSetHeight(R1, AOuterBorderRect.Top - R1.Top);
  AFooterRect := cxRectSetTop(R1, AOuterBorderRect.Bottom, R1.Bottom - AOuterBorderRect.Bottom);

  if LowColors then
  begin
    FillRectByColor(DC, AHeaderRect, clMenu);
    FillRectByColor(DC, AFooterRect, clMenu);
    DrawFrame(DC, R, clMenu, clBlack);
  end
  else
  begin
    Parts[FApplicationMenuContentHeader].Draw(DC, AHeaderRect);
    Parts[FApplicationMenuContentFooter].Draw(DC, AFooterRect);
    Parts[FApplicationMenuBorder].Draw(DC, R);
  end;

  GetApplicationMenuContentColors(AInnerBorderColor, AOuterBorderColor, ASideColor);
  DrawFrame(DC, AInnerBorderRect, clNone, AInnerBorderColor);
  DrawFrame(DC, AOuterBorderRect, clNone, AOuterBorderColor);
  FillRectByColor(DC, Rect(AOuterBorderRect.Right, AHeaderRect.Bottom, R1.Right, AFooterRect.Top), ASideColor);
  FillRectByColor(DC, Rect(R1.Left, AHeaderRect.Bottom, AOuterBorderRect.Left, AFooterRect.Top), ASideColor);
end;

procedure TdxCustomRibbonSkin.DrawApplicationMenuButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if AState = DXBAR_HOT then
    DrawSmallButton(DC, R, AState, AColorSchemeAccent)
  else
    Parts[FApplicationMenuButton].Draw(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawApplicationMenuExtraPaneButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if AState in [DXBAR_HOT, DXBAR_HOTCHECK] then
    DrawSmallButton(DC, R, DXBAR_HOT, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawApplicationMenuExtraPanePinButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawApplicationMenuExtraPaneButton(DC, R, AState, AColorSchemeAccent);
  DrawApplicationMenuExtraPanePinButtonGlyph(DC, R, AState, AState in [DXBAR_CHECKED, DXBAR_HOTCHECK], AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawApplicationMenuExtraPanePinButtonGlyph(
  DC: HDC; const R: TRect; AState: Integer; AChecked: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPartCentered(DC, R, FPinButtonGlyphs[AChecked]);
end;

function TdxCustomRibbonSkin.GetApplicationMenuContentOffset(const ATabsBounds: TRect): TRect;
begin
  Result := GetPartContentOffsets(DXBAR_APPLICATIONMENUCONTENT);
end;

function TdxCustomRibbonSkin.GetApplicationMenuGlyphSize: TSize;
begin
  Result := cxSize(42, 42);
end;

function TdxCustomRibbonSkin.GetApplicationMenuTextColor(AState: TdxRibbonApplicationButtonState): TColor;
begin
  Result := clWindowText;
end;

procedure TdxCustomRibbonSkin.DrawButtonGroup(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(FButtonGroup, DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawButtonGroupDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawButtonGroup(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawButtonGroupDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawButtonGroup(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawButtonGroupBorderLeft(DC: HDC; const R: TRect);
begin
end;

procedure TdxCustomRibbonSkin.DrawButtonGroupBorderMiddle(DC: HDC; const R: TRect; AState: Integer);
begin
end;

procedure TdxCustomRibbonSkin.DrawButtonGroupBorderRight(DC: HDC; const R: TRect);
begin
end;

procedure TdxCustomRibbonSkin.DrawButtonGroupSplitButtonSeparator(DC: HDC; const R: TRect; AState: Integer);
begin
end;

procedure TdxCustomRibbonSkin.DrawCollapsedToolbarBackground(DC: HDC; const R: TRect; AState: Integer);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawCollapsedToolbarGlyphBackground(DC: HDC; const R: TRect; AState: Integer);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawDropDownGalleryBackground(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, GetPartColor(DXBAR_DROPDOWNGALLERY, DXBAR_NORMAL));
end;

procedure TdxCustomRibbonSkin.DrawDropDownGalleryBottomSizeGrip(DC: HDC; const R: TRect);
var
  ARect: TRect;
begin
  ARect := cxRectInflate(R, 0, -3, -2, -1);
  ARect.Left := ARect.Right - cxRectHeight(ARect);
  Parts[FDropDownGalleryBottomSizeGrip].Draw(DC, ARect);
end;

procedure TdxCustomRibbonSkin.DrawDropDownGalleryBottomSizingBand(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clWindow);
end;

procedure TdxCustomRibbonSkin.DrawDropDownGalleryBottomVerticalSizeGrip(DC: HDC; const R: TRect);
begin
  DrawDropDownGalleryVerticalSizeGrip(DC, Rect(R.Left, R.Top + 1, R.Right, R.Bottom));
end;

procedure TdxCustomRibbonSkin.DrawDropDownGalleryTopSizeGrip(DC: HDC; const R: TRect);
var
  ARect: TRect;
begin
  ARect := cxRectInflate(R, 0, -1, -2, -3);
  ARect.Left := ARect.Right - cxRectHeight(ARect);
  Parts[FDropDownGalleryTopSizeGrip].Draw(DC, ARect);
end;

procedure TdxCustomRibbonSkin.DrawDropDownGalleryTopSizingBand(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clWindow);
end;

procedure TdxCustomRibbonSkin.DrawDropDownGalleryTopVerticalSizeGrip(DC: HDC; const R: TRect);
begin
  DrawDropDownGalleryVerticalSizeGrip(DC, Rect(R.Left, R.Top, R.Right, R.Bottom - 1));
end;

procedure TdxCustomRibbonSkin.DrawEditArrowButton(DC: HDC; const R: TRect; AState: Integer);
begin
  // do nothing
end;

procedure TdxCustomRibbonSkin.DrawEditButton(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(FEditButtons, DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawEditEllipsisButton(DC: HDC; const R: TRect; AState: Integer);
begin
  // do nothing
end;

procedure TdxCustomRibbonSkin.DrawEditSpinDownButton(DC: HDC; const R: TRect; AState: Integer);
begin
  // do nothing
end;

procedure TdxCustomRibbonSkin.DrawEditSpinUpButton(DC: HDC; const R: TRect; AState: Integer);
begin
  // do nothing
end;

function TdxCustomRibbonSkin.AdjustCaptionFontSize(ASize: Integer; AUseAeroGlass: Boolean): Integer;
begin
  Result := ASize;
end;

procedure TdxCustomRibbonSkin.AdjustRibbonFormBorderIconSize(
  AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean; var ASize: TSize);
begin
  //nothing
end;

function TdxCustomRibbonSkin.ExtendCaptionAreaOnTabs: Boolean;
begin
  Result := Style >= rs2010;
end;

procedure TdxCustomRibbonSkin.DrawFormBorderIcon(DC: HDC; const R: TRect;
  AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  Pushes: array[Boolean] of Integer = (0, DFCS_PUSHED);
  Buttons: array[TdxRibbonBorderDrawIcon] of Integer = (
    DFCS_CAPTIONMIN, DFCS_CAPTIONMAX, DFCS_CAPTIONRESTORE,
    DFCS_CAPTIONCLOSE, DFCS_CAPTIONHELP, 0, 0
  );
begin
  DrawFrameControl(DC, cxRect(R.Left + 1, R.Top + 2, R.Right - 1, R.Bottom),
    DFC_CAPTION, Buttons[AIcon] or Pushes[AState = rbisPressed]);
end;

procedure TdxCustomRibbonSkin.DrawFormBorders(
  DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo);

  function CreateFrameRegion(const R: TRect): TcxRegion;
  const
    CornerRadius = 9;
  begin
    Result := TcxRegion.CreateRoundCorners(R, CornerRadius, CornerRadius);
    if IsRectangularFormBottom(AInfo.FormData) then
      Result.Combine(TcxRegion.Create(R.Left + 1, R.Top + CornerRadius, R.Right - 1, R.Bottom - 1), roAdd);
  end;

var
  ABrush: HBRUSH;
  ARegion: TcxRegion;
  ASaveIndex: Integer;
  R: TRect;
begin
  ASaveIndex := SaveDC(DC);
  try
    R := AInfo.FormData.Bounds;
    ExcludeClipRect(DC, cxRectContent(R, ABordersWidth));
    FillRectByColor(DC, R, clBtnFace);

    ARegion := CreateFrameRegion(R);
    try
      ARegion.Combine(CreateFrameRegion(cxRectInflate(R, -1, -1)), roSubtract);
      ABrush := CreateSolidBrush(ColorToRGB(clBtnHighlight));
      FillRgn(DC, ARegion.Handle, ABrush);
      DeleteObject(ABrush);
    finally
      ARegion.Free;
    end;
  finally
    RestoreDC(DC, ASaveIndex);
  end;
end;

procedure TdxCustomRibbonSkin.DrawFormCaption(
  DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo);
const
  ColorMap: array[Boolean] of TColor = (clInactiveCaption, clActiveCaption);
var
  ARect: TRect;
begin
  ARect := R;
  if AInfo.FormData.State <> wsMaximized then
  begin
    FillRectByColor(DC, cxRectSetHeight(ARect, 1), clBtnFace);
    Inc(ARect.Top);
    FillRectByColor(DC, cxRectSetHeight(ARect, 1), clBtnHighlight);
    Inc(ARect.Top);
    FillRectByColor(DC, cxRectSetHeight(ARect, 2), clBtnFace);
    Inc(ARect.Top, 2);
  end;
  FillRectByColor(DC, ARect, ColorMap[AInfo.FormData.Active]);
end;

procedure TdxCustomRibbonSkin.DrawFormStatusBarPart(DC: HDC; const R: TRect;
  AIsLeft, AIsActive, AIsRaised, AIsRectangular: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, clBtnFace);
end;

function TdxCustomRibbonSkin.GetWindowBordersWidth(AHasStatusBar: Boolean): TRect;
begin
  Result := cxRect(4, 0, 4, 4);
  if AHasStatusBar then
    Result.Bottom := 1;
end;

function TdxCustomRibbonSkin.HasExternalRibbonFormShadow: Boolean;
begin
  Result := False;
end;

function TdxCustomRibbonSkin.UseRoundedWindowCorners: Boolean;
begin
  Result := True;
end;

procedure TdxCustomRibbonSkin.DrawHelpButton(DC: HDC; const R: TRect;
  AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawTabsAreaButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawHelpButtonGlyph(DC: HDC; const R: TRect);
var
  GR: TRect;
begin
  GR := cxRectBounds(R.Left, R.Top, 16, 16);
  OffsetRect(GR, (R.Right - R.Left - 16) div 2, (R.Bottom - R.Top - 16) div 2);
  Parts[FHelpButton].Draw(DC, GR);
end;

procedure TdxCustomRibbonSkin.DrawInRibbonGalleryBackground(DC: HDC;
  const R: TRect; AState: Integer);
begin
  DrawFrame(DC, R, GetPartColor(DXBAR_INRIBBONGALLERY_BACKGROUND, AState),
    GetPartColor(DXBAR_INRIBBONGALLERY_BORDER, AState));
end;

procedure TdxCustomRibbonSkin.DrawInRibbonGalleryScrollBarBackground(
  DC: HDC; const R: TRect; AState: Integer);
begin
  //nothing
end;

procedure TdxCustomRibbonSkin.DrawInRibbonGalleryScrollBarButton(
  DC: HDC; const R: TRect; AButtonKind: TdxInRibbonGalleryScrollBarButtonKind;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);

  procedure DrawButtonBackground(DC: HDC; const R: TRect);
  begin
    case AState of
      DXBAR_HOT, DXBAR_CHECKED, DXBAR_HOTCHECK:
        DrawFrame(DC, R, clHighlight, clWhite);
      DXBAR_PRESSED:
        DrawFrame(DC, R, clHighlight, clBtnShadow)
      else
        DrawFrame(DC, R, clBtnFace, clBtnShadow);
    end;
  end;

var
  ASaveIndex: Integer;
  R1: TRect;
begin
  R1 := R;
  ASaveIndex := SaveDC(DC);
  try
    IntersectClipRect(DC, R.Left, R.Top, R.Right, R.Bottom);
    Inc(R1.Bottom, Ord(AButtonKind <> gsbkDropDown));
    DrawButtonBackground(DC, R1);
    DrawInRibbonGalleryScrollBarButtonGlyph(DC, R, AButtonKind, AState, AColorSchemeAccent);
  finally
    RestoreDC(DC, ASaveIndex);
  end;
end;

procedure TdxCustomRibbonSkin.DrawInRibbonGalleryScrollBarButtonGlyph(DC: HDC;
  R: TRect; AButtonKind: TdxInRibbonGalleryScrollBarButtonKind; AState: Integer;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  ASaveIndex: Integer;
begin
  ASaveIndex := SaveDC(DC);
  try
    IntersectClipRect(DC, R.Left, R.Top, R.Right, R.Bottom);
    R := cxRectCenter(R, 4, 4);
    R := cxRectOffset(R, 1, 0);
    case AButtonKind of
      gsbkLineUp:
        DrawArrow(DC, R, adUp, AState);
      gsbkLineDown:
        DrawArrow(DC, R, adDown, AState);
      gsbkDropDown:
        begin
          DrawArrow(DC, cxRectOffset(R, 0, 2), adDown, AState);
          FillRectByColor(DC,
            cxRectInflate(cxRectSetBottom(R, R.Top, 1), 3, 0, 0, 0),
            GetPartColor(DXBAR_ARROWDOWN, AState));
        end;
    end;
  finally
    RestoreDC(DC, ASaveIndex);
  end;
end;

procedure TdxCustomRibbonSkin.DrawLargeButton(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  case AState of
    DXBAR_HOT, DXBAR_CHECKED, DXBAR_HOTCHECK, DXBAR_ACTIVE:
      DrawFrame(DC, R, clHighlight, clWhite);
    DXBAR_PRESSED, DXBAR_DROPPEDDOWN:
      DrawFrame(DC, R, clHighlight, clBtnShadow);
    else
      DrawFrame(DC, R, clBtnFace, clNone);
  end
end;

procedure TdxCustomRibbonSkin.DrawLargeButtonDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  case AState of
    DXBAR_HOT, DXBAR_CHECKED, DXBAR_HOTCHECK, DXBAR_ACTIVE:
      DrawFrame(DC, R, clHighlight, clWhite, [bLeft, bTop, bRight]);
    DXBAR_PRESSED, DXBAR_DROPPEDDOWN:
      DrawFrame(DC, R, clHighlight, clBtnShadow, [bLeft, bTop, bRight]);
    else
      DrawFrame(DC, R, clBtnFace, clNone);
  end;
end;

procedure TdxCustomRibbonSkin.DrawLargeButtonDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawLargeButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawLaunchButtonBackground(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawLaunchButtonDefaultGlyph(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawMDIButton(DC: HDC; const R: TRect;
  AButton: TdxBarMDIButton; AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  // do nothing
end;

procedure TdxCustomRibbonSkin.DrawMDIButtonGlyph(
  DC: HDC; const R: TRect; AButton: TdxBarMDIButton; AState: TcxButtonState);
const
  Buttons: array[TdxBarMDIButton] of Integer = (
    DFCS_CAPTIONMIN, DFCS_CAPTIONRESTORE, DFCS_CAPTIONCLOSE);
  Pushes: array[Boolean] of Integer = (0, DFCS_PUSHED);
begin
  DrawFrameControl(DC, cxRect(R.Left + 1, R.Top + 3, R.Right - 1, R.Bottom - 3),
    DFC_CAPTION, Buttons[AButton] or Pushes[AState = cxbsPressed]);
end;

procedure TdxCustomRibbonSkin.DrawMenuArrowDown(DC: HDC; const R: TRect);
begin
  DrawArrow(DC, R, adDown, DXBAR_NORMAL);
end;

procedure TdxCustomRibbonSkin.DrawMenuArrowRight(DC: HDC; const R: TRect);
begin
  DrawArrow(DC, R, adRight, DXBAR_NORMAL);
end;

procedure TdxCustomRibbonSkin.DrawMenuCheck(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawMenuCheckMark(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawMenuContent(DC: HDC; const R: TRect);
begin
  Parts[FMenuContent].Draw(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawMenuDetachCaption(DC: HDC; const R: TRect; AState: Integer);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawMenuExtraSeparator(
  DC: HDC; const R: TRect; AHorizontal: Boolean);
begin
  InternalDrawSeparator(DC, R, AHorizontal, $F5F5F5, $D8D8D8);
end;

procedure TdxCustomRibbonSkin.DrawMenuGlyph(DC: HDC; const R: TRect);
begin
  Parts[FMenuGlyph].Draw(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawMenuItem(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawMenuItemDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButtonDropButtonArrowPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawMenuItemDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButtonDropButtonMainPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawMenuMark(DC: HDC; const R: TRect);
begin
  Parts[FMenuMark].Draw(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawMenuScrollArea(DC: HDC; const R: TRect; AState: Integer);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawMenuSeparatorHorz(DC: HDC; const R: TRect);
begin
  Parts[FMenuSeparatorHorz].Draw(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawMenuSeparatorVert(DC: HDC; const R: TRect);
begin
  Parts[FMenuSeparatorVert].Draw(DC, R);
end;

function TdxCustomRibbonSkin.GetMenuSeparatorSize: Integer;
begin
  Result := 2;
end;

procedure TdxCustomRibbonSkin.DrawMinimizeRibbonButton(DC: HDC; const R: TRect;
  AState: TcxButtonState; AMinimized: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawTabsAreaButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawMinimizeRibbonButtonGlyph(DC: HDC;
  const R: TRect; AState: TcxButtonState; AGlyph: TdxRibbonMinimizeButtonGlyph;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
end;

procedure TdxCustomRibbonSkin.DrawProgressDiscreteBand(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clHighlight);
end;

procedure TdxCustomRibbonSkin.DrawProgressSolidBand(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clHighlight);
end;

procedure TdxCustomRibbonSkin.DrawProgressSubstrate(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clBtnFace);
end;

procedure TdxCustomRibbonSkin.DrawSmallButton(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawSmallButtonDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawSmallButtonDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewBackButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, GetPartColor(DXBAR_BACKSTAGEVIEW));
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewMenuBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, $FCFCFC);
  FillRectByColor(DC, cxRectSetRight(R, R.Right, 1), $F0F0F0);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewMenuButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewTabButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewMenuHeader(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, $FCFCFC);
  FillRectByColor(DC, cxRectSetRight(R, R.Right, 1), $F0F0F0);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewMenuSeparator(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  R1 := cxRectInflate(R, -4, 0);
  FillRectByColor(DC, cxRectSetHeight(R1, 1), clBtnShadow);
  FillRectByColor(DC, cxRectSetBottom(R1, R1.Bottom, 1), clBtnHighlight);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewGalleryBackground(DC: HDC; const R: TRect);
begin
  DrawDropDownGalleryBackground(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewGalleryGroupHeader(DC: HDC; const R: TRect);
begin
  DrawGalleryGroupHeaderBackground(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewGalleryItem(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewGalleryItemPinButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  case AState of
    DXBAR_CHECKED:
      AState := DXBAR_NORMAL;
    DXBAR_HOTCHECK:
      AState := DXBAR_HOT;
  end;
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewGalleryItemPinButtonGlyph(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawApplicationMenuExtraPanePinButtonGlyph(DC, R, AState, AState in [DXBAR_CHECKED, DXBAR_HOTCHECK], AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewGalleryItemPinTag(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawBackstageViewGalleryItemPinButtonGlyph(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawBackstageViewGallerySeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawMenuSeparatorHorz(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawMarkArrow(DC: HDC; const R: TRect; AState: Integer);
var
  H: Integer;
begin
  H := (R.Bottom - R.Top) div 7;
  DrawPart(DC, cxRect(R.Left + 3, R.Top + H * 3, R.Right - 3, R.Bottom - H * 2), AState);
end;

procedure TdxCustomRibbonSkin.DrawMarkTruncated(DC: HDC; const R: TRect; AState: Integer);
var
  H: Integer;
begin
  if LowColors then
  begin
    H := (R.Bottom - R.Top) div 7;
    DrawPart(DC, cxRect(R.Left + H + 1, R.Top + H * 3, R.Right - H + 1, R.Bottom - H * 2), AState);
  end
  else
    DrawPartCentered(DC, R, FMarkTruncated[AState]);
end;

procedure TdxCustomRibbonSkin.DrawTab(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  R1 := R;
  Dec(R1.Bottom);
  case AState of
    rtsNormal:
      FillRectByColor(DC, R1, clBtnFace);
    rtsActive:
      DrawFrame(DC, R1, clHighlight, clWhite, [bLeft, bTop, bRight]);
    else
      DrawFrame(DC, R1, clHighlight, clBtnFace, [bTop]);
  end;
end;

procedure TdxCustomRibbonSkin.DrawTabAreaBackground(DC: HDC; const R: TRect;
  AActive, AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState);
begin
  if not AUseAeroGlass then
    DrawRibbonBackground(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawTabGroupBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
begin
  DrawFrame(DC, R, clBtnFace, clBtnShadow, [bTop, bLeft, bRight])
end;

procedure TdxCustomRibbonSkin.DrawTabGroupHeaderBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
var
  R1: TRect;
begin
  R1 := cxRect(R.Left + 4, R.Top, R.Right - 4, R.Top + 1);
  FillRectByColor(DC, R1, clBtnShadow);
  ExcludeClipRect(DC, R1);
  DrawFrame(DC, R, clBtnFace, clBtnShadow, [bBottom, bLeft, bRight]);
end;

procedure TdxCustomRibbonSkin.DrawTabGroupsArea(
  DC: HDC; const R: TRect; AIsQATAtBottom, AIsInPopup: Boolean);
begin
  DrawFrame(DC, R, clBtnFace, clBtnShadow)
end;

procedure TdxCustomRibbonSkin.DrawTabScrollButton(DC: HDC; const R: TRect;
  ALeft: Boolean; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawGroupScrollButton(DC, R, ALeft, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawTabSeparator(DC: HDC; const R: TRect; Alpha: Byte);
begin
  Parts[FTabSeparator].Draw(DC, R, Alpha);
end;

procedure TdxCustomRibbonSkin.AdjustContextFont(AFont: TFont; AUseGlass: Boolean;
  AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  ColorsMap: array[Boolean] of Integer = (rspContextText, rspContextTextOnGlass);
begin
  AFont.Color := GetPartColor(ColorsMap[AUseGlass], 0, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.AdjustContextTabFont(AFont: TFont; AState: Integer;
  AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  AFont.Color := GetPartColor(rspTabHeaderText, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.DrawContextBackground(DC: HDC; const R: TRect; AContextColor: TColor);
var
  ASaveIndex: Integer;
  R1: TRect;
begin
  ASaveIndex := SaveDC(DC);
  try
    R1 := cxRectInflate(R, -2, -4, -2, -2);
    FillRectByColor(DC, R1, clHighlight);
    ExcludeClipRect(DC, R1);
    FillRectByColor(DC, R, AContextColor);
  finally
    RestoreDC(DC, ASaveIndex)
  end;
end;

procedure TdxCustomRibbonSkin.DrawContextBackgroundGlass(DC: HDC; const R: TRect; AContextColor: TColor);
begin
  FillRectByColor(DC, R, clBtnFace) //Is it possible?
end;

procedure TdxCustomRibbonSkin.DrawContextTabBackground(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, AContextColor);
  case AState of
    rtsNormal:
      FillRectByColor(DC, R, clBtnFace);
    rtsActive:
      DrawFrame(DC, R, clHighlight, clWhite, [bLeft, bTop, bRight]);
    else
      DrawFrame(DC, R, clHighlight, clBtnFace, [bTop]);
  end;
end;

procedure TdxCustomRibbonSkin.DrawContextTabGroupsArea(
  DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean);
begin
  DrawFrame(DC, R, clBtnFace, clBtnShadow)
end;

procedure TdxCustomRibbonSkin.DrawContextTabSeparator(DC: HDC; const R: TRect; ABeginGroup: Boolean);
begin
end;

procedure TdxCustomRibbonSkin.AdjustQuickAccessToolbarVertical(
  var ABounds: TRect; ANonClientDraw, ADontUseAero: Boolean);
begin
  if ANonClientDraw then
  begin
    if IsCompositionEnabled and not ADontUseAero then
    begin
      Inc(ABounds.Top, 3);
      Dec(ABounds.Bottom, 2);
    end
    else
    begin
      Inc(ABounds.Top, 4);
      Dec(ABounds.Bottom, 3);
    end;
  end
  else
  begin
    Inc(ABounds.Top, 3);
    Dec(ABounds.Bottom, 4);
  end;
end;

procedure TdxCustomRibbonSkin.DrawQuickAccessToolbar(DC: HDC; const R: TRect;
  ABellow, ANonClientDraw, AHasApplicationButton, AIsActive, ADontUseAero: Boolean);

  procedure GetQuickAccessToolBarParts(var ALeftPart, ARightPart: Integer);
  var
    AInactive: Boolean;
  begin
    if ANonClientDraw and IsCompositionEnabled and not ADontUseAero then
    begin
      ALeftPart := FQATGlassAtTopLeft[AHasApplicationButton];
      ARightPart := FQATGlassAtTopRight;
    end
    else
    begin
      AInactive := ANonClientDraw and not AIsActive;
      ALeftPart := FQATAtTopLeft[AHasApplicationButton][AInactive];
      ARightPart := FQATAtTopRight[AInactive];
    end;
  end;

var
  AWidth, ALeftPart, ARightPart: Integer;
  R1: TRect;
begin
  if ABellow then
    Parts[FQATAtBottom].Draw(DC, R)
  else
  begin
    AWidth := cxRectHeight(R) div 2;
    if cxRectWidth(R) >= 2 * AWidth then
    begin
      GetQuickAccessToolBarParts(ALeftPart, ARightPart);
      R1 := cxRectSetWidth(R, Parts[ALeftPart].Size.cx);
      AdjustQuickAccessToolbarVertical(R1, ANonClientDraw, ADontUseAero);
      Parts[ALeftPart].Draw(DC, R1);
      R1.Left := R1.Right;
      R1.Right := R.Right - AWidth;
      Parts[ARightPart].Draw(DC, R1);
    end;
  end;
end;

procedure TdxCustomRibbonSkin.DrawQuickAccessToolbarDefaultGlyph(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clBtnFace)
end;

procedure TdxCustomRibbonSkin.DrawQuickAccessToolbarGroupButton(DC: HDC;
  const R: TRect; ABellow, ANonClientDraw, AIsActive: Boolean; AState: Integer;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if ABellow or ANonClientDraw and not AIsActive then
    DrawPart(FQATGroupButtonInactive, DC, R, AState)
  else
    DrawPart(FQATGroupButtonActive, DC, R, AState);
end;

procedure TdxCustomRibbonSkin.DrawQuickAccessToolbarPopup(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clBtnFace);
end;

function TdxCustomRibbonSkin.GetQuickAccessToolbarMarkButtonOffset(
  AHasApplicationButton: Boolean; ABelow: Boolean): Integer;
begin
  if ABelow then
    Result := 5
  else
    Result := 12;
end;

function TdxCustomRibbonSkin.GetQuickAccessToolbarOverrideWidth(AHasApplicationButton: Boolean; AUseAeroGlass: Boolean): Integer;
begin
  if AHasApplicationButton then
    Result := 14
  else
    Result := 0;
end;

function TdxCustomRibbonSkin.GetQuickAccessToolbarLeftIndent(AHasApplicationButton: Boolean; AUseAeroGlass: Boolean): Integer;
begin
  Result := 0;
end;

function TdxCustomRibbonSkin.GetQuickAccessToolbarRightIndent(AHasApplicationButton: Boolean): Integer;
begin
  Result := 0;
end;

procedure TdxCustomRibbonSkin.DrawStatusBar(DC: HDC;
  const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, clBtnFace)
end;

procedure TdxCustomRibbonSkin.DrawStatusBarGripBackground(DC: HDC;
  const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, clBtnFace)
end;

procedure TdxCustomRibbonSkin.DrawStatusBarPanel(DC: HDC; const Bounds, R: TRect;
  AIsLowered: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, clBtnFace);
end;

procedure TdxCustomRibbonSkin.DrawStatusBarPanelSeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, clBtnFace);
  FillRectByColor(DC, cxRect(R.Left, R.Top + 1, R.Left + 1, R.Bottom - 1), clBtnShadow);
end;

procedure TdxCustomRibbonSkin.DrawStatusBarSizeGrip(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  Office11DrawSizeGrip(DC, R,
    GetPartColor(rspStatusBarSizeGripColor1),
    GetPartColor(rspStatusBarSizeGripColor2));
end;

procedure TdxCustomRibbonSkin.DrawStatusBarToolbarSeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, clBtnFace);
  FillRectByColor(DC, cxRect(R.Left, R.Top, R.Left + 1, R.Bottom - 1), clBtnShadow);
end;

function TdxCustomRibbonSkin.GetStatusBarSeparatorSize: Integer;
begin
  Result := 3;
end;

procedure TdxCustomRibbonSkin.DrawScrollBarBackground(DC: HDC;
  const R: TRect; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  cxPaintCanvas.BeginPaint(DC);
  try
    GetScrollBarPainter.DrawScrollBarBackground(cxPaintCanvas, R, AHorizontal);
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

procedure TdxCustomRibbonSkin.DrawScrollBarPart(DC: HDC; const R: TRect;
  APart: TcxScrollBarPart; AState: Integer; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  cxPaintCanvas.BeginPaint(DC);
  try
    GetScrollBarPainter.DrawScrollBarPart(cxPaintCanvas, AHorizontal, R, APart, RibbonStateToButtonState(AState));
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

procedure TdxCustomRibbonSkin.DrawScrollBoxSizeGripArea(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, GetScrollBarPainter.DefaultSizeGripAreaColor);
end;

function TdxCustomRibbonSkin.GetScrollBarPainter: TcxCustomLookAndFeelPainter;
begin
  Result := cxLookAndFeelPaintersManager.GetPainter(lfsNative);
end;

procedure TdxCustomRibbonSkin.DrawGroupScrollButton(DC: HDC; const R: TRect;
  ALeft: Boolean; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawFrame(DC, R, clBtnFace, clBlack);
  DrawSmallButton(DC, R, AState, AColorSchemeAccent)
end;

function TdxCustomRibbonSkin.NeedDrawGroupScrollArrow: Boolean;
begin
  Result := True;
end;

procedure TdxCustomRibbonSkin.DrawArrowDown(DC: HDC; const R: TRect; AState: Integer);
begin
  DrawArrow(DC, R, adDown, AState);
end;

procedure TdxCustomRibbonSkin.DrawDropDownBorder(DC: HDC; const R: TRect);
begin
  Parts[FDropDownBorder].Draw(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawGalleryFilterBandBackground(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clWindow);
end;

procedure TdxCustomRibbonSkin.DrawGalleryGroupHeaderBackground(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, clBtnShadow);
end;

procedure TdxCustomRibbonSkin.DrawItemSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean);
begin
  InternalDrawSeparator(DC, R, AHorizontal, $EBE8E6, $AAA6A2);
end;

procedure TdxCustomRibbonSkin.DrawKeyTip(DC: HDC; const R: TRect);
begin
  DrawScreenTip(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawMiniToolbarBackground(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, GetPartColor(DXBAR_MINITOOLBAR_BACKGROUND));
end;

procedure TdxCustomRibbonSkin.DrawRibbonBackground(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, GetPartColor(rspRibbonBackground));
end;

procedure TdxCustomRibbonSkin.DrawRibbonClientTopArea(DC: HDC; const R: TRect);
begin
end;

procedure TdxCustomRibbonSkin.DrawRibbonFormBackground(DC: HDC; const R: TRect; ARibbonHeight: Integer);
begin
  FillRectByColor(DC, R, GetPartColor(rfspRibbonForm));
end;

procedure TdxCustomRibbonSkin.DrawRibbonTopFrameArea(
  DC: HDC; const R: TRect; AUseAeroGlass: Boolean);
begin
end;

procedure TdxCustomRibbonSkin.DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect);
begin
end;

procedure TdxCustomRibbonSkin.DrawScreenTip(DC: HDC; const R: TRect);
begin
  Parts[FScreenTip].Draw(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawScrollArrow(DC: HDC; const R: TRect);
begin
  Parts[FScrollArrow].Draw(DC, R);
end;

procedure TdxCustomRibbonSkin.DrawSeparatorBackground(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, GetPartColor(DXBAR_SEPARATOR_BACKGROUND));
end;

procedure TdxCustomRibbonSkin.DrawSeparatorLine(DC: HDC; const R: TRect);
begin
  DrawMenuSeparatorHorz(DC, R);
end;

function TdxCustomRibbonSkin.GetIsAlphaUsed(APart: Integer): Boolean;
begin
  Result := False;
end;

function TdxCustomRibbonSkin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
begin
  Result := clDefault;
  case APart of
    DXBAR_BACKSTAGEVIEW_MENUBAR_TAB_TEXTCOLOR,
    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM_TEXTCOLOR,
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMCAPTIONTEXTCOLOR:
      Result := GetPartColor(DXBAR_MENUITEMTEXT, AState, AColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMDESCRIPTIONTEXTCOLOR:
      Result := clGrayText;
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_GROUPHEADER_TEXTCOLOR:
      Result := GetPartColor(DXBAR_GALLERYGROUPHEADERTEXT, AState, AColorSchemeAccent);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_BORDER:
      Result := GetPartColor(DXBAR_INRIBBONGALLERY_BORDER, AState, AColorSchemeAccent);

    DXBAR_APPLICATIONMENUBUTTON, DXBAR_INRIBBONGALLERYITEM_TEXTCOLOR:
      Result := GetPartColor(DXBAR_ITEMTEXT, AState, AColorSchemeAccent);
    DXBAR_DROPDOWNGALLERYITEM_TEXTCOLOR:
      Result := GetPartColor(DXBAR_MENUITEMTEXT, AState, AColorSchemeAccent);
    DXBAR_GALLERYGROUPHEADERTEXT:
      Result := GetPartColor(DXBAR_MENUITEMTEXT, 0, AColorSchemeAccent);

    DXBAR_SEPARATOR_TEXTCOLOR,
    DXBAR_MENUEXTRAPANE_BUTTON_TEXTCOLOR,
    DXBAR_MENUEXTRAPANE_HEADER_TEXTCOLOR:
      Result := GetPartColor(DXBAR_MENUITEMTEXT, AState, AColorSchemeAccent);

    rspContextText:
      Result := GetPartColor(rspTabHeaderText, 0, AColorSchemeAccent);
    rspContextTabHeaderText:
      Result := GetPartColor(rspTabHeaderText, AState, AColorSchemeAccent);
    rspContextTextShadow, rspContextTextOnGlassShadow:
      Result := clNone;

    DXBAR_ARROWDOWN:
      Result := clBlack;
    DXBAR_KEYTIP_TEXTCOLOR:
      Result := clBtnText;
    DXBAR_INRIBBONGALLERY_BACKGROUND:
      Result := clBtnFace;
    DXBAR_INRIBBONGALLERY_BORDER:
      Result := clBtnShadow;
    DXBAR_GALLERYFILTERBANDTEXT:
      Result := clBtnText;
    DXBAR_DROPDOWNGALLERY:
      Result := clBtnFace;
    DXBAR_SCREENTIP_FOOTERLINE:
      Result := $DDBB9E;
    DXBAR_DATENAVIGATOR_HEADER:
      Result := $DAD5D2;
    DXBAR_SEPARATOR_BACKGROUND:
      Result := $EFE7DE;
    rspRibbonBottomEdge:
      Result := $F3E2D5;
    DXBAR_EDIT_BACKGROUND:
      Result := clBtnFace;
    DXBAR_EDIT_TEXTCOLOR:
      if AState = DXBAR_DISABLED then
        Result := clGrayText
      else
        Result := clWindowText;
    rspApplicationButton:
      Result := clBtnText;
    rspFormCaptionText, rspDocumentNameText:
      if AState = DXBAR_NORMAL then
        Result := clCaptionText
      else
        Result := clInactiveCaptionText;
    rspTabHeaderText, rspContextTextOnGlass:
      if AState = DXBAR_NORMAL then
        Result := clWindowText
      else
        Result := clHighlightText;
    rspTabGroupHeaderText:
      Result := clWindowText;
    DXBAR_GALLERYGROUPITEM_OUTERBORDER, DXBAR_GALLERYGROUPITEM_INNERBORDER:
      Result := clHighlight;
    DXBAR_MINITOOLBAR_BACKGROUND:
      Result := $F5F5F5;
    rfspRibbonForm:
      Result := clBtnShadow;
    DXBAR_MENUEDITSEPARATOR:
      case AState of
        DXBAR_ACTIVE:
          Result := $85B6CA;
        DXBAR_ACTIVEDISABLED:
          Result := $CDCDCD;
      end;
    DXBAR_EDIT_BORDER, DXBAR_EDIT_BUTTON_BORDER:
      case AState of
        DXBAR_NORMAL, DXBAR_DISABLED:
          Result := clBtnShadow;
        else
          Result := clWhite;
      end;

    DXBAR_BACKSTAGEVIEW_TEXTCOLOR:
      Result := clBlack;

    rspStatusBarText:
      case AState of
        DXBAR_NORMAL, DXBAR_CHECKED:
          Result := clWindowText;
        DXBAR_DISABLED:
          Result := clGrayText;
        else
          Result := clHighlightText;
      end;

    DXBAR_ITEMTEXT, rspTabGroupText:
      case AState of
        DXBAR_NORMAL:
          Result := clWindowText;
        DXBAR_DISABLED:
          Result := clGrayText;
        else
          Result := clHighlightText;
      end;

    DXBAR_MENUITEMTEXT:
      case AState of
        DXBAR_NORMAL:
          Result := clMenuText;
        DXBAR_DISABLED:
          Result := clGrayText;
        else
          Result := clHighlightText;
      end;

    DXBAR_RADIALMENUACCENT:
      Result := GetPartColor(rspRibbonBackground);
    DXBAR_RADIALMENUBACKGROUND:
      Result := clWhite;
  else
    if LowColors then
      Result := clBtnFace;
  end;
end;

function TdxCustomRibbonSkin.GetPartContentOffsets(APart: Integer): TRect;
begin
  case APart of
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_GROUPHEADER:
      Result := cxRect(7, 4, 7, 4);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINTAG:
      Result := Rect(3, 3, 3, 3);
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINBUTTON,
    DXBAR_MENUEXTRAPANE_PINBUTTON:
      Result := Rect(7, 0, 8, 0);
    DXBAR_APPLICATIONMENUBUTTON:
      Result := Rect(0, 4, 0, 3);
    DXBAR_COLLAPSEDTOOLBAR:
      Result := Rect(2, 2, 2, 2);
    DXBAR_COLLAPSEDTOOLBARGLYPHBACKGROUND:
      Result := Rect(7, 4, 7, 11);
    DXBAR_QUICKACCESSGROUPBUTTON, DXBAR_SMALLBUTTON:
      Result := Rect(3, 3, 3, 3);
    DXBAR_LARGEBUTTON:
      Result := Rect(5, 3, 5, 3);
    DXBAR_APPLICATIONBUTTON:
      Result := cxGetValueCurrentDPI(cxRect(3, 5, 4, 0));
    DXBAR_APPLICATIONMENUCONTENT:
      Result := cxGetValueCurrentDPI(cxRect(4, 16, 4, 29));
    DXBAR_APPLICATIONBUTTONICONOFFSET:
      Result := cxGetValueCurrentDPI(cxRect(8, 8, 10, 10));
    DXBAR_TOOLBARINPOPUP, DXBAR_TOOLBAR:
      Result := cxRect(2, 2, 2, 1);
    DXBAR_RIBBONTABGROUP, DXBAR_RIBBONCONTEXTTABGROUP:
      Result := cxRect(3, 3, 3, 4);
    DXBAR_QUICKACCESSTOOLBAR:
      Result := cxRect(2, 2, 2, 2);
    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM:
      Result := cxRect(10, 0, 0, 0);
    DXBAR_BACKSTAGEVIEW_MENUBAR_TAB:
      Result := cxRect(21, 12, 11, 12);
    DXBAR_BACKSTAGEVIEW_MENUBAR:
      Result := cxRect(6, 5, 6, 6);
    else
      Result := cxNullRect;
  end;
end;

function TdxCustomRibbonSkin.GetPartSize(APart: Integer): Integer;
begin
  case APart of
    DXBAR_MENUSEPARATORHORZ, DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_SEPARATOR:
      Result := GetMenuSeparatorSize;
    DXBAR_SEPARATOR_LINE:
      Result := 1;
    rspTabGroupBottomOffset:
      Result := 3;
    DXBAR_BACKSTAGEVIEW_BACKBUTTON:
      Result := 32;
    DXBAR_BACKSTAGEVIEW_MENUBAR_SEPARATOR:
      Result := 2;
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_BORDER:
      Result := 1;
    rspContextTabSeparatorBegin, rspContextTabSeparatorEnd:
      Result := 1;
    DXBAR_BACKSTAGEVIEW_MENUBAR_TAB:
      Result := 40;
    DXBAR_BACKSTAGEVIEW_MENUBAR_INDENTBETWEENITEMS:
      Result := 1;
    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM:
      Result := 25;
    DXBAR_TOOLBARINPOPUP, DXBAR_TOOLBAR, DXBAR_TABSGROUPSOVERLAPHEIGHT:
      Result := 1;
    DXBAR_BUTTONGROUPBORDERLEFT, DXBAR_BUTTONGROUPBORDERRIGHT:
      Result :=  2;
    DXBAR_BUTTONGROUPSPLITBUTTONSEPARATOR:
      Result := 3;
    DXBAR_BUTTONGROUP:
      Result := 3;
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINBUTTON,
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMPINTAG,
    DXBAR_MENUEXTRAPANE_PINBUTTON:
      Result := Parts[FPinButtonGlyphs[False]].MinSize.cx + cxMarginsWidth(GetPartContentOffsets(APart));
    else
      Result := 0;
  end;
end;

function TdxCustomRibbonSkin.GetSkinName: string;
begin
  Result := '';
end;

procedure TdxCustomRibbonSkin.UpdateBitsPerPixel;
var
  DC: HDC;
begin
  DC := GetDC(0);
  FLowColors := GetDeviceCaps(DC, BITSPIXEL) <= 8;
  ReleaseDC(0, DC);
end;

procedure TdxCustomRibbonSkin.AddTwoStateElement(
  ABitmap: GpBitmap; var AParts; const R, F: TRect; ID: Integer;
  AInterpolationMode: Integer = InterpolationModeNearestNeighbor);
begin
  LoadElementParts(ABitmap, AParts, R, ID, F, [0, 1], [0, 1]);
  Parts[TTwoStateArray(AParts)[False]].InterpolationMode := AInterpolationMode;
  Parts[TTwoStateArray(AParts)[True]].InterpolationMode := AInterpolationMode;
end;

procedure TdxCustomRibbonSkin.InternalDrawSeparator(
  DC: HDC; const R: TRect; AHorizontal: Boolean; AColor1, AColor2: TColor);
var
  R1: TRect;
begin
  if AHorizontal then
  begin
    R1 := cxRectCenterVertically(R, 1);
    FillRectByColor(DC, R1, AColor2);
    FillRectByColor(DC, cxRectOffset(R1, 0, 1), AColor1);
  end
  else
  begin
    R1 := cxRectCenterHorizontally(R, 1);
    FillRectByColor(DC, R1, AColor1);
    FillRectByColor(DC, cxRectOffset(R1, 1, 0), AColor2);
  end;
end;

procedure TdxCustomRibbonSkin.LoadCommonElements(ABitmap: GpBitmap);

  procedure AddElement(var AParts; const R, AFixedRect: TRect; ID: Integer;
    AInterpolationMode: Integer = InterpolationModeNearestNeighbor);
  begin
    LoadElementParts(ABitmap, AParts, R, ID, AFixedRect, [0], [0]);
    Parts[Integer(AParts)].InterpolationMode := AInterpolationMode;
  end;

begin
  AddElement(FQATGlassAtTopLeft[True], cxRectBounds(0, 353, 16, 26), cxRect(0, 2, 2, 2),
    rspQATNonClientLeft1Vista, InterpolationModeHighQualityBicubic);
  AddElement(FQATGlassAtTopLeft[False], cxRectBounds(34, 353, 4, 26), cxRect(3, 2, 0, 1),
    rspQATNonClientLeft2Vista, InterpolationModeHighQualityBicubic);
  AddElement(FQATGlassAtTopRight, cxRectBounds(16, 353, 18, 26), cxRect(0, 7, 15, 7),
    rspQATNonClientRightVista, InterpolationModeHighQualityBicubic);
  FHelpButton := AddPart1x1(ABitmap, cxRectBounds(42, 353, 16, 16), rspHelpButton, '', 7);
  LoadElementParts(ABitmap, FPinButtonGlyphs, cxRectBounds(89, 378, 16, 16),
    rspPinButtonGlyph, cxRect(0, 0, 15, 13), [0, 1], [0, 1], False);
  LoadCommonMenu(ABitmap);
end;

procedure TdxCustomRibbonSkin.LoadCommonMenu(ABitmap: GpBitmap);
begin
  FMenuGlyph := AddPart3x3(ABitmap, cxRectBounds(14, 331, 3, 4), Rect(1, 1, 0, 1), rspMenuGlyph);
  FMenuContent := AddPart3x3(ABitmap, cxRectBounds(18, 331, 3, 4), Rect(0, 1, 1, 1), rspMenuContent);
  FMenuSeparatorHorz := AddPart1x1(ABitmap, cxRectBounds(17, 337, 4, 2), rspMenuSeparatorHorz);
  FMenuSeparatorVert := AddPart1x1(ABitmap, cxRectBounds(14, 336, 2, 2), rspMenuSeparatorVert);
  FDropDownBorder := AddPart3x3(ABitmap, cxRectBounds(28, 331, 8, 8), Rect(3, 3, 3, 3), rspDropDownBorder);
end;

procedure TdxCustomRibbonSkin.LoadRibbonButtons(ABitmap: GpBitmap);
const
  ApplicationMenuButtonHeight = 22;
  ApplicationMenuButtonWidth  = 6;
  ButtonGroupHeight = 22;
  ButtonGroupWidth = 3;
  EditButtonHeight = 20;
  EditButtonWidth  = 12;
  LaunchButtonGlyphSize = 12;
begin
  FApplicationMenuButton := AddPart3x3(ABitmap,
    cxRectBounds(0, 250, ApplicationMenuButtonWidth, ApplicationMenuButtonHeight),
    DefaultFixedSize, rspApplicationMenuButton);
  LoadElementParts(ABitmap, FEditButtons,
    cxRectBounds(0, 116, EditButtonWidth, EditButtonHeight),
    rspEditButtonNormal, DefaultFixedSize, [0, 1, 2, 3, 4, 5, 1],
    [DXBAR_NORMAL..DXBAR_DROPPEDDOWN, DXBAR_ACTIVEDISABLED]);
  LoadElementParts(ABitmap, FButtonGroup,
    cxRectBounds(73, 0, ButtonGroupWidth, ButtonGroupHeight),
    rspButtonGroupNormal, Rect(1, 2, 1, 2), [], []);
  LoadElementParts(ABitmap, FLaunchButtonDefaultGlyphs,
    cxRectBounds(34, 249, LaunchButtonGlyphSize, LaunchButtonGlyphSize),
    rspLaunchButtonDefaultGlyphNormal, cxNullRect, [0, 1, 0, 0, 0],
    [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED], True, 5);
end;

procedure TdxCustomRibbonSkin.LoadRibbonForm(ABitmap: GpBitmap);
begin
  AddTwoStateElement(ABitmap, FQATAtTopLeft[True],
    cxRectBounds(93, 113, 15, 26), cxRect(13, 5, 0, 5), rspQATNonClientLeft1Active);
  AddTwoStateElement(ABitmap, FQATAtTopLeft[False],
    cxRectBounds(125, 113, 7, 26), cxRect(2, 5, 0, 5), rspQATNonClientLeft2Active);
  AddTwoStateElement(ABitmap, FQATAtTopRight,
    cxRectBounds(106, 113, 18, 26), cxRect(0, 5, 13, 5), rspQATNonClientRightActive);
end;

procedure TdxCustomRibbonSkin.LoadRibbonElements(ABitmap: GpBitmap);
begin
  FScrollArrow := AddPart1x1(ABitmap, cxRectBounds(14, 245, 5, 3), rspScrollArrow);
  FScreenTip := AddPart3x3(ABitmap, cxRectBounds(66, 0, 6, 165), DefaultFixedSize, rspScreenTip);

  LoadRibbonTab(ABitmap);
  LoadRibbonButtons(ABitmap);
  LoadRibbonMenu(ABitmap);
  LoadRibbonQAT(ABitmap);
  LoadRibbonGallery(ABitmap);
  LoadRibbonForm(ABitmap);
end;

procedure TdxCustomRibbonSkin.LoadRibbonGallery(ABitmap: GpBitmap);
begin
  FDropDownGalleryTopSizeGrip := AddPart3x3(ABitmap, cxRectBounds(54, 423, 7, 7),
    cxEmptyRect, rspDropDownGalleryTopSizeGrip, '', InterpolationModeNearestNeighbor);
  FDropDownGalleryBottomSizeGrip := AddPart3x3(ABitmap, cxRectBounds(46, 423, 7, 7),
    cxEmptyRect, rspDropDownGalleryBottomSizeGrip, '', InterpolationModeNearestNeighbor);
  FDropDownGalleryVerticalSizeGrip := AddPart3x3(ABitmap, cxRectBounds(46, 431,
    DropDownGalleryVerticalSizeGripBitmapSize.cx, DropDownGalleryVerticalSizeGripBitmapSize.cy),
    cxEmptyRect, rspDropDownGalleryVerticalSizeGrip);
end;

procedure TdxCustomRibbonSkin.LoadRibbonMenu(ABitmap: GpBitmap);
begin
  FApplicationMenuBorder := AddPart3x3(ABitmap, cxRectBounds(48, 321, 8, 8), Rect(3, 3, 3, 3), rspApplicationMenuBorder);
  FApplicationMenuContentHeader := AddPart1x1(ABitmap, cxRectBounds(57, 325, 2, 14), rspApplicationMenuContentHeader);
  FApplicationMenuContentFooter := AddPart1x1(ABitmap, cxRectBounds(62, 323, 2, 25), rspApplicationMenuContentFooter);
  FMenuMark := AddPart1x1(ABitmap, cxRectBounds(48, 277, 17, 17), rspMenuMark);
  LoadElementParts(ABitmap, FMarkTruncated, cxRectBounds(36, 234, 8, 6),
    rspMarkTruncatedNormal, cxEmptyRect, [0, 0, 1], [DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED], True);
end;

procedure TdxCustomRibbonSkin.LoadRibbonQAT(ABitmap: GpBitmap);

  procedure LoadGroupButton(R: TRect; AStartID: Integer; var AStates: TFourStateArray);
  var
    I: Integer;
  begin
    for I := 0 to 3 do
    begin
      AStates[I] := AddPart3x3(ABitmap, R, cxRect(2, 2, 2, 2), AStartID + I);
      OffsetRect(R, 0, cxRectHeight(R));
    end;
  end;

begin
  FQATAtBottom := AddPart3x3(ABitmap, cxRectBounds(13, 209, 10, 26), cxRect(3, 3, 3, 3), rspQATAtBottom);
  LoadElementParts(ABitmap, FQATGroupButtonActive, cxRectBounds(0, 350, 22, 22),
    rspQATGroupButtonActive, DefaultFixedSize, [0, 3, 1, 1, 2, 2, 1],
    [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED, DXBAR_DROPPEDDOWN, DXBAR_ACTIVEDISABLED]);
  LoadElementParts(ABitmap, FQATGroupButtonInactive, cxRectBounds(23, 350, 22, 22),
    rspQATGroupButtonInactive, DefaultFixedSize, [0, 3, 1, 1, 2, 2, 1],
    [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED, DXBAR_DROPPEDDOWN, DXBAR_ACTIVEDISABLED]);
end;

procedure TdxCustomRibbonSkin.LoadRibbonTab(ABitmap: GpBitmap);
begin
  FTabSeparator := AddPart1x1(ABitmap, cxRectBounds(42, 86, 1, 22), rspTabSeparator);
end;

procedure TdxCustomRibbonSkin.LoadCommonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONCOMMON', AImage);
end;

procedure TdxCustomRibbonSkin.LoadSkin;
var
  AImage: TdxGPImage;
begin
  AImage := TdxGPImage.Create;
  try
    LoadCommonTexturesSet(AImage);
    LoadCommonElements(AImage.Handle);
    LoadRibbonTexturesSet(AImage);
    LoadRibbonElements(AImage.Handle);
  finally
    AImage.Free;
  end;
end;

function TdxCustomRibbonSkin.GetStyle: TdxRibbonStyle;
begin
  Result := rs2007;
end;

procedure TdxCustomRibbonSkin.DrawArrow(
  DC: HDC; const R: TRect; AArrowDirection: TcxArrowDirection; AState: Integer);
var
  ABrush: HBRUSH;
  APoints: TcxArrowPoints;
  ARegion: HRGN;
begin
  cxLookAndFeelPaintersManager.GetPainter(lfsStandard).CalculateArrowPoints(R, APoints, AArrowDirection, False, 4);
  if AArrowDirection in [adUp] then
    Dec(APoints[1].Y);
  if AArrowDirection in [adUp, adDown] then
  begin
    Dec(APoints[0].X);
    Dec(APoints[1].X);
  end;
  ABrush := CreateSolidBrush(ColorToRGB(GetPartColor(DXBAR_ARROWDOWN, AState)));
  ARegion := CreatePolygonRgn(APoints, 3, WINDING);
  FillRgn(DC, ARegion, ABrush);
  DeleteObject(ARegion);
  DeleteObject(ABrush)
end;

procedure TdxCustomRibbonSkin.DrawDropDownGalleryVerticalSizeGrip(DC: HDC; const R: TRect);
var
  ARect: TRect;
begin
  ARect := Rect(0, R.Top, 0, R.Bottom);
  ARect.Right := DropDownGalleryVerticalSizeGripBitmapSize.cx *
    cxRectHeight(ARect) div DropDownGalleryVerticalSizeGripBitmapSize.cy;
  OffsetRect(ARect, (cxRectWidth(R) - cxRectWidth(ARect)) div 2, 0);
  Parts[FDropDownGalleryVerticalSizeGrip].Draw(DC, ARect);
end;

procedure TdxCustomRibbonSkin.DrawPart(DC: HDC; const R: TRect; AState: Integer);
begin
  case AState of
    DXBAR_HOT, DXBAR_CHECKED, DXBAR_HOTCHECK:
      DrawFrame(DC, R, clHighlight, clWhite);
    DXBAR_PRESSED:
      DrawFrame(DC, R, clHighlight, clBtnShadow)
    else
      DrawFrame(DC, R, clBtnFace, clBtnShadow);
  end
end;

procedure TdxCustomRibbonSkin.DrawPart(const AParts: TStatesArray; DC: HDC; const R: TRect; AState: Integer);
begin
  if AParts[AState] <> 0 then
  begin
    if LowColors then
      DrawPart(DC, R, AState)
    else
      Parts[AParts[AState]].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbonSkin.DrawPartCentered(DC: HDC; const R: TRect; APartIndex: Integer);
var
  APart: TdxSkinnedRect;
begin
  APart := Parts[APartIndex];
  APart.Draw(DC, cxRectCenter(R, APart.Size));
end;

procedure TdxCustomRibbonSkin.DrawTabsAreaButton(DC: HDC; const R: TRect;
  AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APart: Integer;
begin
  case AState of
    cxbsHot:
      APart := DXBAR_HOT;
    cxbsPressed:
      APart := DXBAR_PRESSED;
    else
      APart := DXBAR_NORMAL;
  end;
  if APart <> DXBAR_NORMAL then
    DrawSmallButton(DC, R, APart, AColorSchemeAccent);
end;

procedure TdxCustomRibbonSkin.GetApplicationMenuContentColors(
  var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor);
begin
  AInnerBorderColor := $CAAF9B;
  AOuterBorderColor := clWhite;
  ASideColor := $EDD3BE;
end;

{ TdxCustomRibbonTexturedSkin }

procedure TdxCustomRibbonTexturedSkin.DrawApplicationButton(DC: HDC; const R: TRect;
  AState: TdxRibbonApplicationButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawApplicationButton(DC, R, AState, AColorSchemeAccent)
  else
    Parts[FApplicationButton[AColorSchemeAccent][Ord(AState)]].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawArrowDown(DC: HDC; const R: TRect; AState: Integer);
begin
  if LowColors then
    inherited DrawArrowDown(DC, R, AState)
  else
    DrawPart(FArrowsDown, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawBackstageViewMenuSeparator(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  R1 := cxRectInflate(R, -4, 0);
  FillRectByColor(DC, cxRectSetHeight(R1, 1), $E0E0E0);
  FillRectByColor(DC, cxRectSetBottom(R1, R1.Bottom, 1), clBtnHighlight);
end;

procedure TdxCustomRibbonTexturedSkin.DrawButtonGroupBorderLeft(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawButtonGroupBorderLeft(DC, R)
  else
    Parts[FButtonGroupBorderLeft].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawButtonGroupBorderMiddle(DC: HDC; const R: TRect; AState: Integer);
begin
  if LowColors then
    inherited DrawButtonGroupBorderMiddle(DC, R, AState)
  else
    DrawPart(FButtonGroupBorderMiddle, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawButtonGroupBorderRight(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawButtonGroupBorderRight(DC, R)
  else
    Parts[FButtonGroupBorderRight].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawButtonGroupSplitButtonSeparator(
  DC: HDC; const R: TRect; AState: Integer);
begin
  if LowColors then
    inherited DrawButtonGroupSplitButtonSeparator(DC, R, AState)
  else
    DrawPart(FButtonGroupSplitButtonSeparator, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawCollapsedToolbarBackground(
  DC: HDC; const R: TRect; AState: Integer);
begin
  if LowColors then
    inherited DrawCollapsedToolbarBackground(DC, R, AState)
  else
    case AState of
      0, 2, 3, 4:
        Parts[FCollapsedToolbars[AState]].Draw(DC, R);
      else
        Parts[FCollapsedToolbars[0]].Draw(DC, R);
    end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawCollapsedToolbarGlyphBackground(
  DC: HDC; const R: TRect; AState: Integer);
begin
  DrawPart(FCollapsedToolbarGlyphBackgrounds, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawContextBackground(
  DC: HDC; const R: TRect; AColor: TColor);
begin
  if LowColors then
    inherited DrawContextBackground(DC, R, AColor)
  else
  begin
    FillRectByColor(DC, R, AColor);
    Parts[FContextBackground].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawContextBackgroundGlass(
  DC: HDC; const R: TRect; AColor: TColor);
begin
  if LowColors then
    inherited DrawContextBackgroundGlass(DC, R, AColor)
  else
  begin
    dxGpFillRectByGradient(DC, R, 0, AColor, LinearGradientModeVertical, 0, 220);
    Parts[FContextBackgroundGlass].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawContextTabBackground(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawContextTabBackground(DC, R, AState, AColor, AColorSchemeAccent)
  else
  begin
    dxGpFillRect(DC, R, AColor);
    Parts[FContextTabIndex[AState]].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawContextTabGroupsArea(
  DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean);
begin
  if LowColors then
    inherited DrawContextTabGroupsArea(DC, R, AContextColor, AIsQATAtBottom, AIsInPopup)
  else
    Parts[FContextTabGroupsArea[AIsQATAtBottom]].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawContextTabSeparator(
  DC: HDC; const R: TRect; ABeginGroup: Boolean);
begin
  if LowColors then
    inherited DrawContextTabSeparator(DC, R, ABeginGroup)
  else
    Parts[FContextTabSeparator[ABeginGroup]].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawDropDownGalleryBottomSizingBand(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawDropDownGalleryBottomSizingBand(DC, R)
  else
    Parts[FDropDownGalleryBottomSizingBand].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawDropDownGalleryTopSizingBand(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawDropDownGalleryTopSizingBand(DC, R)
  else
    Parts[FDropDownGalleryTopSizingBand].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawFormBorders(
  DC: HDC; const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo);
var
  ARectangularBottom: Boolean;
  R: TRect;
begin
  if LowColors then
    inherited DrawFormBorders(DC, ABordersWidth, AInfo)
  else
  begin
    if AInfo.CaptionHeight + AInfo.CaptionAreaExtention > 0 then
    begin
      R := AInfo.FormData.Bounds;
      R.Bottom := AInfo.CaptionHeight + AInfo.CaptionAreaExtention;
      R.Right := R.Left + ABordersWidth.Left;
      Parts[FCaptionLeftBorder[not AInfo.FormData.Active]].Draw(DC, R);
      R.Right := AInfo.FormData.Bounds.Right;
      R.Left := R.Right - ABordersWidth.Right;
      Parts[FCaptionRightBorder[not AInfo.FormData.Active]].Draw(DC, R)
    end;
    ARectangularBottom := IsRectangularFormBottom(AInfo.FormData);
    if ABordersWidth.Bottom > 1 then
    begin
      R := AInfo.FormData.Bounds;
      R.Top := R.Bottom - ABordersWidth.Bottom;
      Parts[FBottomBorderThick[ARectangularBottom][not AInfo.FormData.Active]].Draw(DC, R);
      ExcludeClipRect(DC, R);
    end
    else
    begin
      R := AInfo.FormData.Bounds;
      R.Top := R.Bottom - ABordersWidth.Bottom;
      Inc(R.Left, ABordersWidth.Left);
      Dec(R.Right, ABordersWidth.Right);
      Parts[FBottomBorderThin[not AInfo.FormData.Active]].Draw(DC, R);
    end;
    R := AInfo.FormData.Bounds;
    if not ARectangularBottom then
      Dec(R.Bottom);
    R.Top := AInfo.CaptionHeight + AInfo.CaptionAreaExtention + ABordersWidth.Top;
    R.Right := R.Left + ABordersWidth.Left;
    Parts[FLeftBorder[not AInfo.FormData.Active]].Draw(DC, R);
    R.Right := AInfo.FormData.Bounds.Right;
    R.Left := R.Right - ABordersWidth.Right;
    Parts[FRightBorder[not AInfo.FormData.Active]].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawFormBorderIcon(DC: HDC; const R: TRect;
  AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APart: Integer;
begin
  if LowColors then
    inherited DrawFormBorderIcon(DC, R, AIcon, AState, AColorSchemeAccent)
  else
  begin
    APart := BorderIconStateToPartIndex[AState];
    if APart >= 0 then
      Parts[FBorderIcons[APart]].Draw(DC, R);
    InternalDrawFormBorderIconGlyph(DC, R, AIcon, AState);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawFormCaption(
  DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo);
var
  ARect: TRect;
begin
  if LowColors then
    inherited DrawFormCaption(DC, R, AInfo)
  else
    if AInfo.FormData.State = wsMaximized then
      Parts[FCaptionZoomed[not AInfo.FormData.Active]].Draw(DC, R)
    else
      if AInfo.FormData.State = wsMinimized then
      begin
        ARect := R;
        Dec(ARect.Bottom, 1);
        Parts[FCaption[not AInfo.FormData.Active]].Draw(DC, ARect);
        ARect := R;
        ARect.Top := ARect.Bottom - 1;
        Parts[FBottomBorderThin[not AInfo.FormData.Active]].Draw(DC, ARect);
      end
      else
        Parts[FCaption[not AInfo.FormData.Active]].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawFormStatusBarPart(DC: HDC; const R: TRect;
  AIsLeft, AIsActive, AIsRaised, AIsRectangular: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APart: Integer;
begin
  if LowColors then
    inherited DrawFormStatusBarPart(DC, R, AIsLeft, AIsActive, AIsRaised, AIsRectangular, AColorSchemeAccent)
  else
  begin
    APart := 0;
    Inc(APart, Ord(AIsRaised));
    Inc(APart, Ord(not AIsActive) * 2);
    if AIsLeft then
      Parts[FFormStatusBarLeftParts[AIsRectangular][APart]].Draw(DC, R)
    else
      Parts[FFormStatusBarRightParts[AIsRectangular][APart]].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawGalleryFilterBandBackground(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawGalleryFilterBandBackground(DC, R)
  else
    Parts[FGalleryFilterBand].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawGalleryGroupHeaderBackground(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawGalleryGroupHeaderBackground(DC, R)
  else
    Parts[FGalleryGroupHeader].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawGroupScrollButton(DC: HDC; const R: TRect;
  ALeft: Boolean; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APartIndex: Integer;
begin
  if LowColors then
    inherited DrawGroupScrollButton(DC, R, ALeft, AState, AColorSchemeAccent)
  else
  begin
    case AState of
      DXBAR_HOT:
        APartIndex := 1;
      DXBAR_PRESSED:
        APartIndex := 2;
      else
        APartIndex := 0;
    end;
    Parts[FGroupScrollButtons[ALeft][APartIndex]].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawInRibbonGalleryScrollBarButton(
  DC: HDC; const R: TRect; AButtonKind: TdxInRibbonGalleryScrollBarButtonKind;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);

  procedure DoDrawGalleryScrollButton(const AButtonParts, AGlyphsParts: TStatesArray);
  var
    APart: TdxSkinnedRect;
  begin
    DrawPart(AButtonParts, DC, R, AState);
    if AGlyphsParts[AState] <> 0 then
    begin
      APart := Parts[AGlyphsParts[AState]];
      APart.Draw(DC, cxRectOffset(cxRectCenter(R, APart.Size), 0, 1));
    end;
  end;

begin
  if LowColors then
    inherited DrawInRibbonGalleryScrollBarButton(DC, R, AButtonKind, AState, AColorSchemeAccent)
  else
    case AButtonKind of
      gsbkLineUp:
        DoDrawGalleryScrollButton(FInRibbonGalleryScrollBarLineUpButton,
          FInRibbonGalleryScrollBarLineUpButtonGlyph);
      gsbkLineDown:
        DoDrawGalleryScrollButton(FInRibbonGalleryScrollBarLineDownButton,
          FInRibbonGalleryScrollBarLineDownButtonGlyph);
      gsbkDropDown:
        DoDrawGalleryScrollButton(FInRibbonGalleryScrollBarDropDownButton,
          FInRibbonGalleryScrollBarDropDownButtonGlyph);
    end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawLargeButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawLargeButton(DC, R, AState, AColorSchemeAccent)
  else
    DrawPart(FLargeButtons, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawLargeButtonDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawLargeButtonDropButtonArrowPart(DC, R, AState, AColorSchemeAccent)
  else
    DrawPart(FLargeButtonDropButtons, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawLargeButtonDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawLargeButtonDropButtonMainPart(DC, R, AState, AColorSchemeAccent)
  else
    DrawPart(FLargeButtonGlyphBackgrounds, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawLaunchButtonBackground(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(FLaunchButtonBackgrounds, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawLaunchButtonDefaultGlyph(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(FLaunchButtonDefaultGlyphs, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawMarkArrow(DC: HDC; const R: TRect; AState: Integer);
var
  APart: TdxSkinnedRect;
begin
  if LowColors then
    inherited DrawMarkArrow(DC, R, AState)
  else
  begin
    APart := Parts[FMarkArrow[AState]];
    APart.Draw(DC, cxRectOffset(cxRectCenter(R, APart.Size), 0, 1));
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawMDIButton(DC: HDC; const R: TRect;
  AButton: TdxBarMDIButton; AState: TcxButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawTabsAreaButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbonTexturedSkin.DrawMDIButtonGlyph(
  DC: HDC; const R: TRect; AButton: TdxBarMDIButton; AState: TcxButtonState);
const
  PartMap: array[TcxButtonState] of Integer = (0, 0, 1, 2, 3);
var
  AIcon: TdxRibbonBorderDrawIcon;
  GR: TRect;
begin
  if LowColors then
    inherited DrawMDIButtonGlyph(DC, R, AButton, AState)
  else
  begin
    GR := cxRectBounds(R.Left, R.Top, 9, 9);
    OffsetRect(GR, (R.Right - R.Left - 9) div 2, (R.Bottom - R.Top - 9) div 2 + 1);
    case AButton of
      mdibMinimize:
        AIcon := rbdiMinimize;
      mdibRestore:
        AIcon := rbdiRestore;
      else
        AIcon := rbdiClose;
    end;
    Parts[FBorderIconGlyph[AIcon][PartMap[AState]]].Draw(DC, GR);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawMenuArrowDown(DC: HDC; const R: TRect);
var
  APart: TdxSkinnedRect;
begin
  if LowColors then
    inherited DrawMenuArrowDown(DC, R)
  else
  begin
    APart := Parts[FMenuArrowDown];
    APart.Draw(DC, cxRectCenter(R, APart.Size));
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawMenuArrowRight(DC: HDC; const R: TRect);
var
  APart: TdxSkinnedRect;
begin
  if LowColors then
    inherited DrawMenuArrowRight(DC, R)
  else
  begin
    APart := Parts[FMenuArrowRight];
    APart.Draw(DC, cxRectCenter(R, APart.Size));
  end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawMenuCheck(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(FMenuCheck, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawMenuCheckMark(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawMenuCheck(DC, R, AState, AColorSchemeAccent);
  DrawPartCentered(DC, R, FMenuCheckMark[AState]);
end;

procedure TdxCustomRibbonTexturedSkin.DrawMenuDetachCaption(DC: HDC; const R: TRect; AState: Integer);
begin
  DrawPart(FMenuDetachCaption, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawMenuScrollArea(DC: HDC; const R: TRect; AState: Integer);
begin
  DrawPart(FMenuScrollArea, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawProgressDiscreteBand(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawProgressDiscreteBand(DC, R)
  else
    Parts[FProgressDiscreteBand].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawProgressSolidBand(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawProgressSolidBand(DC, R)
  else
    Parts[FProgressSolidBand].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawProgressSubstrate(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawProgressSubstrate(DC, R)
  else
    Parts[FProgressSubstrate].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawQuickAccessToolbarDefaultGlyph(DC: HDC; const R: TRect);
begin
  if FLowColors then
    inherited DrawQuickAccessToolbarDefaultGlyph(DC, R)
  else
    Parts[FQATDefaultGlyph].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawQuickAccessToolbarPopup(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawQuickAccessToolbarPopup(DC, R)
  else
    Parts[FQATPopup].Draw(DC, R)
end;

procedure TdxCustomRibbonTexturedSkin.DrawRibbonClientTopArea(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawRibbonClientTopArea(DC, R)
  else
    Parts[FRibbonTopArea].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawScrollBarBackground(
  DC: HDC; const R: TRect; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawScrollBarBackground(DC, R, AHorizontal, AColorSchemeAccent)
  else
    Parts[FScrollBarBackground[AHorizontal][0]].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawScrollBarPart(DC: HDC; const R: TRect;
  APart: TcxScrollBarPart; AState: Integer; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);

  procedure DrawBackgroundPart(const AParts: TFourStateArray);
  var
    APartIndex: Integer;
  begin
    case AState of
      DXBAR_HOT:
        APartIndex := 1;
      DXBAR_PRESSED:
        APartIndex := 2;
      DXBAR_DISABLED:
        APartIndex := 3;
    else
      APartIndex := 0;
    end;
    Parts[AParts[APartIndex]].Draw(DC, R);
  end;

begin
  if LowColors then
    inherited DrawScrollBarPart(DC, R, APart, AState, AHorizontal, AColorSchemeAccent)
  else
    case APart of
      sbpPageUp, sbpPageDown:
        DrawBackgroundPart(FScrollBarBackground[AHorizontal]);
      sbpThumbnail:
        begin
          DrawBackgroundPart(FScrollBarThumb[AHorizontal]);
          DrawPartCentered(DC, R, FScrollBarThumbGlyph[AHorizontal]);
        end;
      sbpLineUp:
        begin
          DrawBackgroundPart(FScrollBarButtonLeftTop[AHorizontal]);
          DrawPartCentered(DC, R, FScrollBarButtonLeftTopGlyph[AHorizontal]);
        end;
      sbpLineDown:
        begin
          DrawBackgroundPart(FScrollBarButtonRightBottom[AHorizontal]);
          DrawPartCentered(DC, R, FScrollBarButtonRightBottomGlyph[AHorizontal]);
        end;
    end;
end;

procedure TdxCustomRibbonTexturedSkin.DrawSmallButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(FSmallButtons, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawSmallButtonDropButtonArrowPart(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(FSmallButtonDropButtons, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawSmallButtonDropButtonMainPart(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawPart(FSmallButtonGlyphBackgrounds, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawStatusBar(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawStatusBar(DC, R, AColorSchemeAccent)
  else
    Parts[FStatusBar].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawStatusBarGripBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawStatusBarGripBackground(DC, R, AColorSchemeAccent)
  else
    Parts[FStatusBarGripBackground].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawStatusBarPanel(DC: HDC;
  const Bounds, R: TRect; AIsLowered: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if FLowColors then
    inherited DrawStatusBarPanel(DC, Bounds, R, AIsLowered, AColorSchemeAccent)
  else
    if AIsLowered then
      Parts[FStatusBarPanelLowered].Draw(DC, R)
    else
      Parts[FStatusBarPanelRaised].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawStatusBarPanelSeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawStatusBarPanelSeparator(DC, R, AColorSchemeAccent)
  else
    Parts[FStatusBarPanelSeparator].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawStatusBarToolbarSeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawStatusBarToolbarSeparator(DC, R, AColorSchemeAccent)
  else
    Parts[FStatusBarToolbarSeparator].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawTab(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawTab(DC, R, AState, AColorSchemeAccent)
  else
    Parts[FTabIndex[AState]].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawTabGroupBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
begin
  if LowColors then
    inherited DrawTabGroupBackground(DC, R, AState, AIsInPopup)
  else
    DrawPart(FToolbar, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawTabGroupHeaderBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
begin
  if LowColors then
    inherited DrawTabGroupHeaderBackground(DC, R, AState, AIsInPopup)
  else
    DrawPart(FToolbarHeader, DC, R, AState);
end;

procedure TdxCustomRibbonTexturedSkin.DrawTabGroupsArea(
  DC: HDC; const R: TRect; AIsQATAtBottom, AIsInPopup: Boolean);

  function GetPartIndex: Integer;
  begin
    if AIsInPopup then
      Result := 2
    else
      Result := Ord(AIsQATAtBottom);
  end;

begin
  if LowColors then
    inherited DrawTabGroupsArea(DC, R, AIsQATAtBottom, AIsInPopup)
  else
    Parts[FTabGroupsArea[GetPartIndex]].Draw(DC, R);
end;

procedure TdxCustomRibbonTexturedSkin.DrawTabScrollButton(DC: HDC; const R: TRect;
  ALeft: Boolean; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APartIndex: Integer;
begin
  if LowColors then
    inherited DrawTabScrollButton(DC, R, ALeft, AState, AColorSchemeAccent)
  else
  begin
    case AState of
      DXBAR_HOT:
        APartIndex := 1;
      DXBAR_PRESSED:
        APartIndex := 2;
      else
        APartIndex := 0;
    end;
    Parts[FTabScrollButtons[ALeft][APartIndex]].Draw(DC, R);
  end;
end;

function TdxCustomRibbonTexturedSkin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  case APart of
    DXBAR_BACKSTAGEVIEW:
      Result := clWhite;
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMDESCRIPTIONTEXTCOLOR:
      Result := $646464;

    DXBAR_KEYTIP_TEXTCOLOR:
      Result := dxScreenTipFontColor;
    DXBAR_MENUEXTRAPANE:
      Result := $EEEAE9;
    DXBAR_MENUARROWSEPARATOR:
      Result := $BDB6A5;
    DXBAR_MENUDETACHCAPTIONAREA:
      Result := $F7F7F7;
    DXBAR_MENUITEMTEXT:
      if AState in [DXBAR_DISABLED, DXBAR_ACTIVEDISABLED] then
        Result := $A7A7A7;

    DXBAR_ITEMTEXT:
      case AState of
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
          Result := $8D8D8D;
        else
          Result := GetPartColor(rspTabGroupText, 0, AColorSchemeAccent);
      end;

    DXBAR_DROPDOWNGALLERY:
      Result := $FAFAFA;
    DXBAR_DROPDOWNBORDER_INNERLINE:
      Result := $F5F5F5;

    DXBAR_GALLERYGROUPITEM_OUTERBORDER:
      case AState of
        DXBAR_HOT:
          Result := $3694F2;
        DXBAR_CHECKED:
          Result := $1048EF;
        DXBAR_HOTCHECK:
          Result := $3695F2;
      end;

    DXBAR_GALLERYGROUPITEM_INNERBORDER:
      case AState of
        DXBAR_HOT:
          Result := $94E2FF;
        DXBAR_CHECKED:
          Result := $94E2FF;
        DXBAR_HOTCHECK:
          Result := $95E3FF;
      end;

    DXBAR_MINITOOLBAR_BACKGROUND:
      Result := $F5F5F5;
    rspContextTextOnGlass:
      Result := clBlack;
  end;
end;

procedure TdxCustomRibbonTexturedSkin.InternalDrawFormBorderIconGlyph(DC: HDC;
  const  R: TRect; AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState;
  AColor: TColor = clDefault; AAlignment: TAlignment = taCenter);
const
  StateMap: array[TdxRibbonBorderIconState] of Integer = (0, 1, 2, 3, 3);
var
  AGlyph: TdxSkinnedRect;
  ARect: TRect;
begin
  AGlyph := Parts[FBorderIconGlyph[AIcon][StateMap[AState]]];
  ARect := cxRectOffset(cxRectCenterVertically(R, AGlyph.Size.cy), 0, 1);
  case AAlignment of
    taLeftJustify:
      begin
        ARect := cxRectOffset(ARect, ARect.Top - R.Top, 0);
        ARect.Right := ARect.Left + AGlyph.Size.cx;
      end;

    taRightJustify:
      begin
        ARect := cxRectOffset(ARect, R.Top - ARect.Top, 0);
        ARect.Left := ARect.Right - AGlyph.Size.cx;
      end;

    else
      ARect := cxRectCenterHorizontally(ARect, AGlyph.Size.cx);
  end;
  AGlyph.DrawColored(DC, ARect, AColor);
end;

procedure TdxCustomRibbonTexturedSkin.LoadCommonButtons(ABitmap: GpBitmap);
const
  SmallButtonSize  = 22;
  SmallButtonGlyphBackgroundWidth = 29;
  SmallButtonDropButtonWidth = 12;

  LargeButtonWidth  = 42;
  LargeButtonHeight = 66;
  LargeButtonGlyphBackgroundWidth = 42;
  LargeButtonGlyphBackgroundHeight = 39;
  LargeButtonDropButtonWidth = 42;
  LargeButtonDropButtonHeight = 27;

  LaunchButtonWidth = 15;
  LaunchButtonHeight = 14;
begin
  LoadElementParts(ABitmap, FSmallButtons,
    cxRectBounds(99, 155, SmallButtonSize, SmallButtonSize),
    rspSmallButtonNormal, DefaultFixedSize, [0, 0, 1, 2, 2, 3, 4], DXBAR_BTN_STATES);
  LoadElementParts(ABitmap, FSmallButtonGlyphBackgrounds,
    cxRectBounds(86, 0, SmallButtonGlyphBackgroundWidth, SmallButtonSize),
    rspSmallButtonGlyphBackgroundNormal, DefaultFixedSize, [], DXBAR_BTN_STATES);
  LoadElementParts(ABitmap, FSmallButtonDropButtons,
    cxRectBounds(86, 155, SmallButtonDropButtonWidth, SmallButtonSize),
    rspSmallButtonDropButtonNormal, DefaultFixedSize, [], DXBAR_BTN_STATES);

  LoadElementParts(ABitmap, FLargeButtons,
    cxRectBounds(0, 0, LargeButtonWidth, LargeButtonHeight),
    rspLargeButtonNormal, DefaultFixedSize, [0, 0, 1, 2, 2, 3, 4], DXBAR_BTN_STATES);
  LoadElementParts(ABitmap, FLargeButtonGlyphBackgrounds,
    cxRectBounds(43, 0, LargeButtonGlyphBackgroundWidth, LargeButtonGlyphBackgroundHeight),
    rspLargeButtonGlyphBackgroundNormal, DefaultFixedSize, [0, 1, 2, 1, 3, 4], DXBAR_BTN_STATES);
  LoadElementParts(ABitmap, FLargeButtonDropButtons,
    cxRectBounds(43, 235, LargeButtonDropButtonWidth, LargeButtonDropButtonHeight),
    rspLargeButtonDropButtonNormal, DefaultFixedSize, [0, 1, 1, 2, 2, 0, 3], DXBAR_BTN_STATES);

  LoadElementParts(ABitmap, FLaunchButtonBackgrounds,
    cxRectBounds(101, 350, LaunchButtonWidth, LaunchButtonHeight),
    rspLaunchButtonBackgroundNormal, DefaultFixedSize, [0, 0, 1],
    [DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED]);
end;

procedure TdxCustomRibbonTexturedSkin.LoadCommonElements(ABitmap: GpBitmap);
begin
  inherited LoadCommonElements(ABitmap);
  FProgressSolidBand := AddPart3x3(ABitmap, cxRectBounds(6, 344, 86, 8), DefaultFixedSize, rspProgressSolidband);
  FProgressDiscreteBand := AddPart3x3(ABitmap, cxRectBounds(0, 344, 5, 8), DefaultFixedSize, rspProgressDiscreteBand);
  FContextBackgroundGlass := AddPart3x3(ABitmap,  cxRectBounds(61, 353, 17, 25), cxRect(2, 9, 2, 1), rspContextBackgroundGlass);
  LoadCommonButtons(ABitmap);
end;

procedure TdxCustomRibbonTexturedSkin.LoadCommonMenu(ABitmap: GpBitmap);
const
  MenuCheckSize = 6;
  MenuCheckMarkSize = 20;
  MenuDetachCaptionSize = 5;
begin
  inherited LoadCommonMenu(ABitmap);
  LoadElementParts(ABitmap, FMenuDetachCaption,
    cxRectBounds(1, 331, MenuDetachCaptionSize, MenuDetachCaptionSize),
    rspMenuDetachCaptionNormal, DefaultFixedSize, [], [DXBAR_NORMAL, DXBAR_HOT]);
  LoadElementParts(ABitmap, FMenuCheck,
    cxRectBounds(99, 310, MenuCheckSize, MenuCheckSize),
    rspMenuCheckNormal, DefaultFixedSize, [0, 1, 0], [DXBAR_NORMAL, DXBAR_HOT, DXBAR_DISABLED]);
  LoadElementParts(ABitmap, FMenuCheckMark,
    cxRectBounds(99, 266, MenuCheckMarkSize, MenuCheckMarkSize),
    rspMenuCheckMarkNormal, DefaultFixedSize, [0, 1, 0], [DXBAR_NORMAL, DXBAR_HOT, DXBAR_DISABLED]);
  LoadElementParts(ABitmap, FMenuScrollArea, cxRectBounds(86, 310, 6, 12),
    rspMenuScrollAreaNormal, DefaultFixedSize, [], [DXBAR_HOT, DXBAR_PRESSED]);
  FQATDefaultGlyph := AddPart1x1(ABitmap, cxRectBounds(100, 330, 16, 16), rspQATDefaultGlyph);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonApplicationButton(ABitmap: GpBitmap);
var
  AIndex: TdxRibbonColorSchemeAccent;
begin
  LoadThreeStateArray(ABitmap, cxRectBounds(93, 166, 42, 42), cxEmptyRect,
    FApplicationButton[rcsaYellow], rspApplicationButton, True, InterpolationModeHighQualityBicubic);
  for AIndex := Low(TdxRibbonColorSchemeAccent) to High(TdxRibbonColorSchemeAccent) do
    FApplicationButton[AIndex] := FApplicationButton[rcsaYellow];
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonButtons(ABitmap: GpBitmap);
const
  ArrowDownHeight = 4;
  ArrowDownWidth = 5;
  ButtonGroupHeight = 22;
  ButtonGroupMiddleBorderWidth = 1;
  ButtonGroupWidth = 3;
  MenuArrowDownHeight = 4;
  MenuArrowDownWidth = 7;
begin
  inherited LoadRibbonButtons(ABitmap);
  LoadElementParts(ABitmap, FArrowsDown,
    cxRectBounds(0, 237, ArrowDownWidth, ArrowDownHeight),
    rspArrowDownNormal, cxEmptyRect, [0, 1, 2, 2, 2, 2, 0, 0, 1], []);
  FMenuArrowDown := AddPart1x1(ABitmap,
    cxRectBounds(6, 245, MenuArrowDownWidth, MenuArrowDownHeight), rspMenuArrowDown);
  FMenuArrowRight := AddPart1x1(ABitmap,
    cxRectBounds(6, 237, MenuArrowDownHeight, MenuArrowDownWidth), rspMenuArrowRight);
  FButtonGroupBorderLeft := AddPart3x3(ABitmap, cxRectBounds(37, 197, 2, ButtonGroupHeight),
    Rect(0, 2, 0, 2), rspButtonGroupBorderLeft);
  FButtonGroupBorderRight := AddPart3x3(ABitmap, cxRectBounds(38, 197, 2, ButtonGroupHeight),
    Rect(0, 2, 0, 2), rspButtonGroupBorderRight);
  LoadElementParts(ABitmap, FButtonGroupBorderMiddle,
    cxRectBounds(40, 86, ButtonGroupMiddleBorderWidth, ButtonGroupHeight),
    rspButtonGroupBorderMiddleNormal, Rect(0, 2, 0, 2), [0, 1, 2, 2, 2, 2, 2, 2, 3], []);
  LoadElementParts(ABitmap, FButtonGroupSplitButtonSeparator, cxRectBounds(37, 86, 2, ButtonGroupHeight),
    rspButtonGroupSplitButtonSeparatorNormal, Rect(0, 2, 0, 2), [0, 1, 2, 2, 3, 2, 2, 2, 4], []);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonCollapsedToolbar(ABitmap: GpBitmap);
const
  CollapsedToolbarWidth  = 7;
  CollapsedToolbarHeight = 85;
  CollapsedToolbarFixedSize: TRect = (Left: 3; Top: 15; Right: 3; Bottom: 3);
  CollapsedToolbarGlyphBackgroundWidth = 10;
  CollapsedToolbarGlyphBackgroundHeight = 31;
  CollapsedToolbarGlyphBackgroundFixedSize: TRect = (Left: 4; Top: 9; Right: 4; Bottom: 8);
begin
  LoadElementParts(ABitmap, FCollapsedToolbars,
    cxRectBounds(25, 0, CollapsedToolbarWidth, CollapsedToolbarHeight),
    rspCollapsedToolbarNormal, CollapsedToolbarFixedSize, [0,1,3,2],
    [DXBAR_NORMAL, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED]);
  LoadElementParts(ABitmap, FCollapsedToolbarGlyphBackgrounds,
    cxRectBounds(66, 199, CollapsedToolbarGlyphBackgroundWidth,
    CollapsedToolbarGlyphBackgroundHeight),
    rspCollapsedToolbarGlyphBackgroundNormal,
    CollapsedToolbarGlyphBackgroundFixedSize, [0,1,3,2],
    [DXBAR_NORMAL, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED]);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonContexts(ABitmap: GpBitmap);
begin
  FContextBackground := AddPart3x3(ABitmap,
    cxRectBounds(25, 439, 17, 25), cxRect(2,9,2,1), rspContextBackground);
  FContextTabGroupsArea[False] := AddPart3x3(ABitmap,
    cxRectBounds(12, 250, 11, 92), cxRect(5, 17, 5, 7), rspContextTabGroupsArea);
  FContextTabGroupsArea[True] := FContextTabGroupsArea[False];
  FContextTabSeparator[False] := AddPart3x3(ABitmap,
    cxRectBounds(25, 465, 1, 16), cxNullRect, rspContextTabSeparatorBegin);
  FContextTabSeparator[True] := AddPart3x3(ABitmap,
    cxRectBounds(25, 465, 1, 16), cxNullRect, rspContextTabSeparatorEnd);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonElements(ABitmap: GpBitmap);
begin
  inherited LoadRibbonElements(ABitmap);
  FProgressSubstrate := AddPart3x3(ABitmap, cxRectBounds(11, 237, 7, 7), DefaultFixedSize, rspProgressSubstrate);
  LoadRibbonCollapsedToolbar(ABitmap);
  LoadRibbonScrollBars(ABitmap);
  LoadRibbonScrollButtons(ABitmap);
  LoadRibbonContexts(ABitmap);
  LoadRibbonGroup(ABitmap);
  LoadRibbonStatusBar(ABitmap);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonForm(ABitmap: GpBitmap);
begin
  inherited LoadRibbonForm(ABitmap);
  FRibbonTopArea := AddPart3x3(ABitmap, cxRectBounds(99, 38, 2, 30), cxRect(0, 9, 0, 5), rspRibbonClientTopArea);
  LoadRibbonFormBorders(ABitmap);
  LoadRibbonFormBorderIcons(ABitmap);
  LoadRibbonApplicationButton(ABitmap);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonFormBorderIcons(ABitmap: GpBitmap);
begin
  LoadRibbonFormBorderIconsGlyphs(ABitmap, 93, 0, 9, 9);
  LoadElementParts(ABitmap, FBorderIcons, cxRectBounds(118, 37, 25, 25),
    rfspBorderIconBackground, DefaultFixedSize, [0, 1, 2], [0, 1, 2], True,
    InterpolationModeNearestNeighbor);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonFormBorderIconsGlyphs(
  ABitmap: GpBitmap; X, Y, AWidth, AHeight: Integer);
var
  I: TdxRibbonBorderDrawIcon;
  ID: Integer;
  R: TRect;
begin
  ID := rfspBorderIconMinimizeGlyph;
  for I := Low(TdxRibbonBorderDrawIcon) to High(TdxRibbonBorderDrawIcon) do
  begin
    R := cxRectBounds(X, Y, AWidth, AHeight);
    LoadElementParts(ABitmap, FBorderIconGlyph[I], R, ID, DefaultFixedSize,
      [0, 1, 2, 3], [0, 1, 2, 3], True, InterpolationModeNearestNeighbor);
    Inc(X, AWidth + 1);
    Inc(ID, 4);
  end;
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonFormBorders(ABitmap: GpBitmap);
var
  R: TRect;
begin
  AddTwoStateElement(ABitmap, FCaption,
    cxRectBounds(93, 37, 14, 31), cxRect(6, 10, 6, 5), rfspActiveCaption);
  AddTwoStateElement(ABitmap, FCaptionZoomed,
    cxRectBounds(99, 37, 2, 31), cxRect(0, 10, 0, 5), rfspActiveCaptionZoomed);
  // Caption Borders
  R := cxRectBounds(93, 37, 4, 31);
  AddTwoStateElement(ABitmap, FCaptionLeftBorder, R, cxRect(0, 9, 0, 2), rfspActiveCaptionLeftBorder);
  OffsetRect(R, 10, 0);
  AddTwoStateElement(ABitmap, FCaptionRightBorder, R, cxRect(0, 9, 0, 2), rfspActiveCaptionRightBorder);
  //active border
  R := cxRectBounds(108, 37, 4, 6);
  AddTwoStateElement(ABitmap, FLeftBorder, R, cxRect(0, 0, 0, 5), rfspActiveLeftBorder);
  OffsetRect(R, 5, 0);
  AddTwoStateElement(ABitmap, FRightBorder, R, cxRect(0, 0, 0, 5), rfspActiveRightBorder);
  //bottom border
  AddTwoStateElement(ABitmap, FBottomBorderThin,
    cxRectBounds(108, 50, 2, 2), cxEmptyRect, rfspActiveBottomBorderThin);
  AddTwoStateElement(ABitmap, FBottomBorderThick[False],
    cxRectBounds(133, 113, 10, 4), cxRect(4, 0, 4, 0), rfspActiveBottomBorderThick);
  AddTwoStateElement(ABitmap, FBottomBorderThick[True],
    cxRectBounds(133, 121, 10, 4), cxRect(4, 0, 4, 0), rfspActiveBottomBorderThickRectangular);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonGallery(ABitmap: GpBitmap);
begin
  inherited LoadRibbonGallery(ABitmap);
  LoadRibbonGalleryInRibbonScrollBarButtons(ABitmap);
  LoadRibbonGalleryInRibbonScrollBarButtonsGlyphs(ABitmap);
  FGalleryFilterBand := AddPart3x3(ABitmap, cxRectBounds(7, 250, 4, 13),
    cxRectBounds(1, 1, 1, 0), rspGalleryFilterBand);
  FGalleryGroupHeader := AddPart3x3(ABitmap, cxRectBounds(0, 273, 4, 4),
    cxRectBounds(0, 0, 0, 2), rspGalleryGroupHeader);
  FDropDownGalleryTopSizingBand := AddPart3x3(ABitmap, cxRectBounds(38, 29, 4, 11),
    cxRectBounds(1, 1, 1, 1), rspDropDownGalleryTopSizingBand);
  FDropDownGalleryBottomSizingBand := AddPart3x3(ABitmap, cxRectBounds(33, 29, 4, 11),
    cxRectBounds(1, 1, 1, 1), rspDropDownGalleryBottomSizingBand);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonGalleryInRibbonScrollBarButtons(ABitmap: GpBitmap);
const
  ScrollBarButtonWidth = 15;
  ScrollBarButtonHeight = 20;
begin
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarLineUpButton,
    cxRectBounds(78, 0, ScrollBarButtonWidth, ScrollBarButtonHeight),
    rspInRibbonGalleryScrollBarLineUpButtonNormal, DefaultFixedSize,
    [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED]);
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarLineDownButton,
    cxRectBounds(78, 80, ScrollBarButtonWidth, ScrollBarButtonHeight),
    rspInRibbonGalleryScrollBarLineDownButtonNormal, DefaultFixedSize,
    [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED]);
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarDropDownButton,
    cxRectBounds(78, 160, ScrollBarButtonWidth, ScrollBarButtonHeight),
    rspInRibbonGalleryScrollBarDropDownButtonNormal, DefaultFixedSize,
    [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED]);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonGalleryInRibbonScrollBarButtonsGlyphs(ABitmap: GpBitmap);
begin
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarLineUpButtonGlyph,
    cxRectBounds(66, 388, 5, 4), rspInRibbonGalleryScrollBarLineUpButtonGlyphNormal,
    cxNullRect, [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED]);
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarLineDownButtonGlyph,
    cxRectBounds(71, 388, 5, 4), rspInRibbonGalleryScrollBarLineDownButtonGlyphNormal,
    cxNullRect, [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED]);
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarDropDownButtonGlyph,
    cxRectBounds(66, 405, 5, 7), rspInRibbonGalleryScrollBarDropDownButtonGlyphNormal,
    cxNullRect, [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED], False);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonGroup(ABitmap: GpBitmap);
begin
  LoadElementParts(ABitmap, FToolbar, cxRectBounds(66, 350, 10, 20),
    rspToolbarNormal, cxRect(3, 2, 3, 0), [], [DXBAR_NORMAL, DXBAR_HOT], False);
  LoadElementParts(ABitmap, FToolbarHeader, cxRectBounds(66, 370, 10, 17),
    rspToolbarHeaderNormal, cxRect(3, 0, 3, 3), [], [DXBAR_NORMAL, DXBAR_HOT], False);
  LoadElementParts(ABitmap, FMarkArrow, cxRectBounds(36, 220, 7, 7),
    rspMarkArrowNormal, cxEmptyRect, [0, 0, 1], [DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED], True);
  FTabGroupsArea[0] := AddPart3x3(ABitmap, cxRectBounds(13, 116, 11, 92), cxRect(5, 17, 5, 7), rspTabGroupsArea);
  FTabGroupsArea[1] := FTabGroupsArea[0];
  FTabGroupsArea[2] := FTabGroupsArea[0];
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonMenu(ABitmap: GpBitmap);
begin
  inherited LoadRibbonMenu(ABitmap);
  FMenuScrollArea[DXBAR_NORMAL] := AddPart3x3(ABitmap,
    cxRectBounds(20, 237, 4, 12), Rect(1, 1, 1, 1), rspMenuScrollAreaNormal);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonQAT(ABitmap: GpBitmap);
begin
  inherited LoadRibbonQAT(ABitmap);
  FQATPopup :=  AddPart3x3(ABitmap, cxRectBounds(33, 0, 6, 28), cxRect(2, 2, 2, 2), rspQATPopup);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonScrollBars(ABitmap: GpBitmap);
begin
  LoadFourStateArray(ABitmap, cxRectBounds(43, 466, 10, 17), cxRect(4, 4, 4, 4), FScrollBarBackground[True], rspScrollBarHorz);
  LoadFourStateArray(ABitmap, cxRectBounds(54, 466, 17, 10), cxRect(4, 4, 4, 4), FScrollBarBackground[False], rspScrollBarVert);

  FScrollBarThumbGlyph[True] := AddPart1x1(ABitmap, cxRectBounds(54, 518, 11, 11), rspScrollBarVertThumbGlyph);
  FScrollBarThumbGlyph[False] := AddPart1x1(ABitmap, cxRectBounds(54, 507, 11, 11), rspScrollBarHorzThumbGlyph);
  LoadFourStateArray(ABitmap, cxRectBounds(72, 466, 17, 17), cxRect(4, 4, 4, 4), FScrollBarThumb[True], rspScrollBarHorzThumb);
  LoadFourStateArray(ABitmap, cxRectBounds(90, 466, 17, 17), cxRect(4, 4, 4, 4), FScrollBarThumb[False], rspScrollBarVertThumb);

  FScrollBarButtonLeftTopGlyph[False] := AddPart1x1(ABitmap, cxRectBounds(72, 535, 9, 9), rspScrollBarButtonTopGlyph);
  FScrollBarButtonLeftTopGlyph[True] := AddPart1x1(ABitmap, cxRectBounds(90, 535, 9, 9), rspScrollBarButtonLeftGlyph);
  FScrollBarButtonRightBottomGlyph[False] := AddPart1x1(ABitmap, cxRectBounds(81, 535, 9, 9), rspScrollBarButtonBottomGlyph);
  FScrollBarButtonRightBottomGlyph[True] := AddPart1x1(ABitmap, cxRectBounds(99, 535, 9, 9), rspScrollBarButtonRightGlyph);

  LoadFourStateArray(ABitmap, cxRectBounds(108, 466, 17, 17), cxRect(4, 4, 4, 4), FScrollBarButtonLeftTop[False], rspScrollBarButtonTop);
  LoadFourStateArray(ABitmap, cxRectBounds(43, 544, 17, 17), cxRect(4, 4, 4, 4), FScrollBarButtonLeftTop[True], rspScrollBarButtonLeft, False);
  LoadFourStateArray(ABitmap, cxRectBounds(126, 466, 17, 17), cxRect(4, 4, 4, 4), FScrollBarButtonRightBottom[False], rspScrollBarButtonBottom);
  LoadFourStateArray(ABitmap, cxRectBounds(43, 562, 17, 17), cxRect(4, 4, 4, 4), FScrollBarButtonRightBottom[True], rspScrollBarButtonRight, False);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonScrollButtons(ABitmap: GpBitmap);
var
  R, FR: TRect;
begin
  FR := cxRect(3, 4, 3, 5);
  R := cxRectBounds(46, 350, 9, 24);
  LoadThreeStateArray(ABitmap, R, FR, FTabScrollButtons[True], rspTabScrollLeftButtonNormal);
  R := cxRectBounds(56, 350, 9, 24);
  LoadThreeStateArray(ABitmap, R, FR, FTabScrollButtons[False], rspTabScrollRightButtonNormal);
  R := cxRectBounds(48, 0, 8, 92);
  LoadThreeStateArray(ABitmap, R, cxRect(4, 4, 2, 4), FGroupScrollButtons[True], rspGroupScrollLeftButtonNormal);
  R := cxRectBounds(57, 0, 8, 92);
  LoadThreeStateArray(ABitmap, R, cxRect(2, 4, 4, 4), FGroupScrollButtons[False], rspGroupScrollRightButtonNormal);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonStatusBar(ABitmap: GpBitmap);
begin
  FStatusBar := AddPart1x3(ABitmap, cxRectBounds(42, 138, 2, 22), 2, 3, rspStatusBar);
  FStatusBarPanel := FStatusBar;
  FStatusBarPanelLowered := FStatusBar;
  FStatusBarPanelRaised := AddPart1x3(ABitmap, cxRectBounds(42, 160, 2, 22), 2, 3, rspStatusBarPanelRaised);

  FStatusBarPanelSeparator := AddPart1x3(ABitmap,
    cxRectBounds(42, 183, 3, 22), 2, 3, rspStatusBarPanelSeparator);
  FStatusBarToolbarSeparator := AddPart1x3(ABitmap,
    cxRectBounds(45, 138, 2, 22), 2, 3, rspStatusBarToolbarSeparator);
  FStatusBarGripBackground := AddPart3x3(ABitmap,
    cxRectBounds(42, 183, 5, 22), cxRect(3, 2, 0, 3), rspStatusBarGripBackground);

  LoadElementParts(ABitmap, FFormStatusBarLeftParts[False], cxRectBounds(77, 241, 4, 22),
    rspStatusBarFormLeftPart, cxRect(0, 2, 0, 3), [0, 1, 2, 3], [0, 1, 2, 3]);
  LoadElementParts(ABitmap, FFormStatusBarLeftParts[True], cxRectBounds(85, 241, 4, 22),
    rspStatusBarFormLeftPartDialog, cxRect(0, 2, 0, 3), [0, 1, 2, 3], [0, 1, 2, 3]);
  LoadElementParts(ABitmap, FFormStatusBarRightParts[False], cxRectBounds(81, 241, 4, 22),
    rspStatusBarFormRightPart, cxRect(0, 2, 0, 3), [0, 1, 2, 3], [0, 1, 2, 3]);
  LoadElementParts(ABitmap, FFormStatusBarRightParts[True], cxRectBounds(89, 241, 4, 22),
    rspStatusBarFormRightPartDialog, cxRect(0, 2, 0, 3), [0, 1, 2, 3], [0, 1, 2, 3]);
end;

procedure TdxCustomRibbonTexturedSkin.LoadRibbonTab(ABitmap: GpBitmap);
begin
  inherited LoadRibbonTab(ABitmap);
  LoadElementParts(ABitmap, FTabIndex, cxRectBounds(0, 0, 24, 23), rspTabNormal,
    cxRect(4, 4, 4, 4), [0, 1, 2, 3, 4], [0, 1, 2, 3, 4]);
  LoadElementParts(ABitmap, FContextTabIndex, cxRectBounds(0, 439, 24, 23), rspContextTabNormal,
    cxRect(5, 3, 5, 1), [0, 1, 2, 3, 4], [0, 1, 2, 3, 4]);
end;

{ TdxCustomRibbon2010Skin }

procedure TdxCustomRibbon2010Skin.DrawBackstageViewBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  inherited DrawBackstageViewBackground(DC, R, AColorSchemeAccent);
  Parts[FBackstageViewFrame[AColorSchemeAccent]].Draw(DC, cxRectSetHeight(R, 2));
end;

procedure TdxCustomRibbon2010Skin.DrawBackstageViewMenuBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawBackstageViewMenuBackground(DC, R, AColorSchemeAccent)
  else
    Parts[FBackstageViewMenuBackground].Draw(DC, R);
end;

procedure TdxCustomRibbon2010Skin.DrawBackstageViewMenuButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawBackstageViewMenuButton(DC, R, AState, AColorSchemeAccent)
  else
  begin
    case AState of
      DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED:
        AState := 0;
      DXBAR_ACTIVEDISABLED:
        AState := 1;
      else
        Exit;
    end;
    Parts[FBackstageViewMenuButton[AColorSchemeAccent][AState = 1]].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbon2010Skin.DrawBackstageViewMenuSeparator(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  Parts[FBackstageViewMenuSeparator].Draw(DC, R);
end;

procedure TdxCustomRibbon2010Skin.DrawBackstageViewTabButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APart: TdxSkinnedRect;
  APartIndex: Integer;
  R1: TRect;
begin
  if LowColors then
  begin
    inherited DrawBackstageViewTabButton(DC, R, AState, AColorSchemeAccent);
    Exit;
  end;

  case AState of
    DXBAR_HOT, DXBAR_ACTIVE:
      APartIndex := 0;
    DXBAR_CHECKED, DXBAR_PRESSED:
      APartIndex := 1;
    DXBAR_HOTCHECK:
      APartIndex := 2;
    DXBAR_ACTIVEDISABLED:
      APartIndex := 3;
    else
      Exit;
  end;
  if APartIndex >= 0 then
    Parts[FBackstageViewTabs[AColorSchemeAccent][APartIndex]].Draw(DC, R);
  if APartIndex in [1, 2] then
  begin
    APart := Parts[FBackstageViewTabArrow];
    R1 := cxRectCenterVertically(R, APart.Size.cy);
    APart.Draw(DC, cxRectSetRight(R1, R1.Right, APart.Size.cx));
  end;
end;

procedure TdxCustomRibbon2010Skin.AdjustContextFont(AFont: TFont; AUseGlass: Boolean;
  AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  inherited AdjustContextFont(AFont, AUseGlass, AContextColor, AColorSchemeAccent);
  AFont.Style := AFont.Style + [fsBold];
end;

procedure TdxCustomRibbon2010Skin.DrawContextBackground(DC: HDC; const R: TRect; AColor: TColor);
var
  R1: TRect;
begin
  if LowColors then
    inherited DrawContextBackground(DC, R, AColor)
  else
  begin
    R1 := cxRectSetHeight(R, cxRectHeight(R) + 1);
    DrawColoredElement(FContextBackgroundMask, DC, R1, AColor);
    Parts[FContextBackground].Draw(DC, R1);
  end;
end;

procedure TdxCustomRibbon2010Skin.DrawContextBackgroundGlass(
  DC: HDC; const R: TRect; AColor: TColor);
var
  ASaveIndex: Integer;
begin
  ASaveIndex := SaveDC(DC);
  try
    IntersectClipRect(DC, R.Left, R.Top, R.Right, R.Bottom);
    DrawContextBackground(DC, cxRectOffset(R, 0, -1), AColor);
  finally
    RestoreDC(DC, ASaveIndex);
  end;
end;

procedure TdxCustomRibbon2010Skin.DrawContextTabBackground(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawContextTabBackground(DC, R, AState, AColor, AColorSchemeAccent)
  else
  begin
    DrawColoredElement(FContextTabMaskIndex[AState], DC, R, AColor);
    Parts[FContextTabIndex[AState]].Draw(DC, R);
  end;
end;

procedure TdxCustomRibbon2010Skin.DrawApplicationMenuBackground(
  DC: HDC; const R, AContentRect: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  ABorderRect, R1: TRect;
  AHeaderRect, AFooterRect: TRect;
  ABorderColor, ATempColor: TColor;
begin
  R1 := cxRectInflate(R, -2, -2);
  ABorderRect := cxRectInflate(AContentRect, 0, 1, 0, 1);
  AHeaderRect := cxRectSetHeight(R1, ABorderRect.Top - R1.Top);
  AFooterRect := cxRectSetTop(R1, ABorderRect.Bottom, R1.Bottom - ABorderRect.Bottom);

  if LowColors then
  begin
    FillRectByColor(DC, AHeaderRect, clMenu);
    FillRectByColor(DC, AFooterRect, clMenu);
    DrawFrame(DC, R, clMenu, clBlack);
  end
  else
  begin
    Parts[FApplicationMenuContentHeader].Draw(DC, AHeaderRect);
    Parts[FApplicationMenuContentFooter].Draw(DC, AFooterRect);
    Parts[FApplicationMenuBorder].Draw(DC, R);
  end;

  GetApplicationMenuContentColors(ATempColor, ABorderColor, ATempColor);
  DrawFrame(DC, ABorderRect, clNone, ABorderColor);
end;

procedure TdxCustomRibbon2010Skin.DrawButtonGroup(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2010Skin.DrawButtonGroupDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButtonDropButtonArrowPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2010Skin.DrawButtonGroupDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButtonDropButtonMainPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2010Skin.DrawContextTabGroupsArea(
  DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean);
begin
  if AIsInPopup then
    DrawTabGroupsArea(DC, R, AIsQATAtBottom, AIsInPopup)
  else
    inherited DrawContextTabGroupsArea(DC, R, AContextColor, AIsQATAtBottom, AIsInPopup);
end;

procedure TdxCustomRibbon2010Skin.DrawFormBorderIcon(DC: HDC; const R: TRect;
  AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APart: Integer;
begin
  if LowColors or (AIcon <> rbdiClose) then
    inherited DrawFormBorderIcon(DC, R, AIcon, AState, AColorSchemeAccent)
  else
  begin
    APart := BorderIconStateToPartIndex[AState];
    if APart >= 0 then
      Parts[FCloseButton[APart]].Draw(DC, R);
    InternalDrawFormBorderIconGlyph(DC, R, AIcon, AState);
  end;
end;

procedure TdxCustomRibbon2010Skin.DrawFormCaption(
  DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo);
begin
  inherited DrawFormCaption(DC, R, AInfo);
  if (AInfo.IsRibbonHidden or (AInfo.CaptionHeight = AInfo.RibbonHeight)) and (AInfo.FormData.State <> wsMinimized) then
    DrawFormCaptionSeparator(DC, cxRectSetBottom(R, R.Bottom, 1));
end;

procedure TdxCustomRibbon2010Skin.DrawItemSeparator(
  DC: HDC; const R: TRect; AHorizontal: Boolean);
var
  APart: TdxSkinnedRect;
  R1: TRect;
begin
  if LowColors then
    inherited DrawItemSeparator(DC, R, AHorizontal)
  else
  begin
    APart := Parts[FItemsSeparator[AHorizontal]];
    if AHorizontal then
      R1 := cxRectCenterVertically(R, APart.Size.cy)
    else
      R1 := cxRectCenterHorizontally(R, APart.Size.cx);
    APart.Draw(DC, R1);
  end;
end;

procedure TdxCustomRibbon2010Skin.DrawMenuExtraSeparator(
  DC: HDC; const R: TRect; AHorizontal: Boolean);
begin
  InternalDrawSeparator(DC, R, AHorizontal, clWhite, $EBDBCF);
end;

procedure TdxCustomRibbon2010Skin.DrawMDIButtonGlyph(
  DC: HDC; const R: TRect; AButton: TdxBarMDIButton; AState: TcxButtonState);
const
  PartStateMap: array[TcxButtonState] of Integer = (0, 0, 1, 2, 3);
var
  APart: TdxSkinnedRect;
begin
  APart := Parts[FMDIButtonGlyphs[AButton][PartStateMap[AState]]];
  APart.Draw(DC, cxRectCenter(R, APart.Size));
end;

procedure TdxCustomRibbon2010Skin.DrawMinimizeRibbonButtonGlyph(DC: HDC;
  const R: TRect; AState: TcxButtonState; AGlyph: TdxRibbonMinimizeButtonGlyph;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APart: TdxSkinnedRect;
begin
  APart := Parts[FMinimizeRibbonButtonGlyph[AGlyph][AState = cxbsDisabled]];
  APart.Draw(DC, cxRectCenter(R, APart.Size));
end;

procedure TdxCustomRibbon2010Skin.DrawQuickAccessToolbar(DC: HDC; const R: TRect;
  ABellow, ANonClientDraw, AHasApplicationButton, AIsActive, ADontUseAero: Boolean);
begin
  inherited DrawQuickAccessToolbar(DC, R, ABellow, ANonClientDraw, False, AIsActive, ABellow);
end;

procedure TdxCustomRibbon2010Skin.DrawRibbonTopFrameArea(
  DC: HDC; const R: TRect; AUseAeroGlass: Boolean);
var
  R1: TRect;
begin
  if AUseAeroGlass then
  begin
    R1 := R;
    Dec(R1.Bottom);
    Parts[FTabsAreaOnGlass].Draw(DC, R1);
  end;
end;

procedure TdxCustomRibbon2010Skin.DrawSeparatorLine(DC: HDC; const R: TRect);
begin
end;

procedure TdxCustomRibbon2010Skin.DrawTabGroupBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
begin
  if not AIsInPopup then
    inherited DrawTabGroupBackground(DC, R, AState, AIsInPopup);
end;

procedure TdxCustomRibbon2010Skin.DrawTabGroupHeaderBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
begin
  if not AIsInPopup then
    inherited DrawTabGroupHeaderBackground(DC, R, AState, AIsInPopup);
end;

function TdxCustomRibbon2010Skin.GetApplicationMenuContentOffset(const ATabsBounds: TRect): TRect;
begin
  Result := cxGetValueCurrentDPI(cxRect(2, 0, 2, 30));
  Result.Top := cxRectHeight(ATabsBounds) + 1;
end;

function TdxCustomRibbon2010Skin.GetApplicationMenuGlyphSize: TSize;
begin
  Result := cxSize(56, 25);
end;

function TdxCustomRibbon2010Skin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  if LowColors then Exit;

  case APart of
    DXBAR_MENUEXTRAPANE:
      Result := GetPartColor(DXBAR_EDIT_BACKGROUND, DXBAR_NORMAL, AColorSchemeAccent);
    DXBAR_DROPDOWNGALLERY:
      Result := clWhite;
    DXBAR_SEPARATOR_BACKGROUND, DXBAR_DATENAVIGATOR_HEADER:
      Result := $F5F2F0;
    DXBAR_INRIBBONGALLERY_BORDER:
      Result := GetPartColor(DXBAR_EDIT_BORDER, DXBAR_NORMAL, AColorSchemeAccent);
    DXBAR_MINITOOLBAR_BACKGROUND:
      Result := $FFFFFF;

    rspApplicationButton:
      Result := clWhite;
    rspFormCaptionText, rspDocumentNameText, rspTabHeaderText, rspTabGroupText, rspTabGroupHeaderText:
      Result := $5B391E;
    rspStatusBarText:
      if AState = DXBAR_DISABLED then
        Result := GetPartColor(DXBAR_ITEMTEXT, DXBAR_DISABLED, AColorSchemeAccent)
      else
        Result := $5B391E;
    rspContextText:
      Result := clWhite;
    rspContextTextShadow:
      Result := clGray;
    rspContextTextOnGlass:
      Result := $5B391E;

    DXBAR_MENUITEMTEXT:
      if not (AState in [DXBAR_DISABLED, DXBAR_ACTIVEDISABLED]) then
        Result := $5B391E;

    DXBAR_EDIT_BUTTON_BORDER:
      case AState of
        DXBAR_HOT:
          Result := $54CCF0;
        DXBAR_DROPPEDDOWN, DXBAR_PRESSED:
          Result := $3888C2;
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED, DXBAR_NORMAL:
          Result := GetPartColor(DXBAR_EDIT_BACKGROUND, DXBAR_NORMAL, AColorSchemeAccent);
        DXBAR_ACTIVE:
          Result := GetPartColor(DXBAR_EDIT_BORDER, DXBAR_ACTIVE, AColorSchemeAccent);
      end;

    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM_TEXTCOLOR:
      case AState of
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
          Result := $AAA6A5;
        else
          Result := clBlack;
      end;

    DXBAR_BACKSTAGEVIEW_MENUBAR_TAB_TEXTCOLOR:
      case AState of
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
          Result := $AAA6A5;
        DXBAR_HOTCHECK, DXBAR_CHECKED, DXBAR_PRESSED:
          if AColorSchemeAccent = rcsaYellow then
            Result := clBlack
          else
            Result := clWhite;
        else
          Result := clBlack;
      end;
  end;
end;

function TdxCustomRibbon2010Skin.GetPartContentOffsets(APart: Integer): TRect;
begin
  case APart of
    DXBAR_BACKSTAGEVIEW:
      Result := Rect(0, 2, 0, 0);
    DXBAR_APPLICATIONMENUBUTTON:
       Result := Rect(0, 4, 2, 4);
    DXBAR_APPLICATIONBUTTON:
      Result := cxRect(0, 0, cxGetValueCurrentDPI(4), 0);
    DXBAR_APPLICATIONBUTTONICONOFFSET:
      Result := cxGetValueCurrentDPI(cxRect(12, 5, 12, 4));
    DXBAR_COLLAPSEDTOOLBAR:
      Result := cxRect(2, 2, 5, 2);
    DXBAR_COLLAPSEDTOOLBARGLYPHBACKGROUND:
      Result := Rect(7, 7, 7, 7);
    DXBAR_TOOLBAR:
      Result := cxRect(0, 3, 5, 1);
    DXBAR_TOOLBARINPOPUP:
      Result := cxRect(2, 3, 2, 1);
    else
      Result := inherited GetPartContentOffsets(APart);
  end;
end;

function TdxCustomRibbon2010Skin.GetPartSize(APart: Integer): Integer;
begin
  case APart of
    DXBAR_SEPARATOR_LINE:
      Result := 0;
    rspContextTabSeparatorBegin, rspContextTabSeparatorEnd:
      Result := 2;
    DXBAR_TOOLBAR, DXBAR_TOOLBARINPOPUP:
      Result := 0;
    DXBAR_BACKSTAGEVIEW_MENUBAR_SEPARATOR:
      Result := Parts[FBackstageViewMenuSeparator].Size.cy;
    else
      Result := inherited GetPartSize(APart);
  end;
end;

function TdxCustomRibbon2010Skin.GetQuickAccessToolbarMarkButtonOffset(
  AHasApplicationButton, ABelow: Boolean): Integer;
begin
  Result := 8;
end;

function TdxCustomRibbon2010Skin.GetQuickAccessToolbarOverrideWidth(
  AHasApplicationButton, AUseAeroGlass: Boolean): Integer;
begin
  Result := 4;
end;

function TdxCustomRibbon2010Skin.GetWindowBordersWidth(AHasStatusBar: Boolean): TRect;
begin
  Result := cxRect(8, 0, 8, 8);
end;

function TdxCustomRibbon2010Skin.GetStyle: TdxRibbonStyle;
begin
  Result := rs2010;
end;

procedure TdxCustomRibbon2010Skin.DrawColoredElement(
  APartIndex: Integer; DC: HDC; const R: TRect; AColor: TColor);
var
  ABitmap: TcxBitmap32;
begin
  ABitmap := TcxBitmap32.CreateSize(R, True);
  try
    Parts[APartIndex].Draw(ABitmap.Canvas.Handle, ABitmap.ClientRect);
    cxMakeColoredBitmap(ABitmap, AColor);
    cxAlphaBlend(DC, ABitmap, R, ABitmap.ClientRect);
  finally
    ABitmap.Free;
  end;
end;

procedure TdxCustomRibbon2010Skin.DrawFormCaptionSeparator(DC: HDC; const R: TRect);
begin
end;

procedure TdxCustomRibbon2010Skin.LoadCommonApplicationButton(ABitmap: GpBitmap);
var
  AIndex: TdxRibbonColorSchemeAccent;
  R: TRect;
begin
  R := cxRectBounds(238, 0, 34, 21);
  for AIndex := Low(TdxRibbonColorSchemeAccent) to High(TdxRibbonColorSchemeAccent) do
  begin
    LoadThreeStateArray(ABitmap, R, cxRect(4, 4, 4, 4), FApplicationButton[AIndex],
      rspApplicationButton + 3 * Ord(AIndex), True, InterpolationModeHighQualityBicubic);
    OffsetRect(R, 0, 3 * cxRectHeight(R));
  end;
end;

procedure TdxCustomRibbon2010Skin.LoadCommonBackstageView(ABitmap: GpBitmap);
var
  AIndex: TdxRibbonColorSchemeAccent;
  R: TRect;
begin
  R := cxRectBounds(0, 398, 360, 2);
  for AIndex := Low(AIndex) to High(AIndex) do
  begin
    FBackstageViewFrame[AIndex] := AddPart1x1(ABitmap, R, rbvpBackstageViewFrame + Ord(AIndex));
    OffsetRect(R, 0, cxRectHeight(R));
  end;

  R := cxRectBounds(0, 409, 120, 41);
  for AIndex := Low(AIndex) to High(AIndex) do
  begin
    LoadElementParts(ABitmap, FBackstageViewTabs[AIndex],
      R, rbvpBackstageViewMenuTabButton + 4 * Ord(AIndex),
      cxRect(0, 4, 0, 4), [0, 1, 2, 3], [0, 1, 2, 3]);
    OffsetRect(R, cxRectWidth(R), 0);
  end;

  R := cxRectBounds(122, 0, 115, 27);
  for AIndex := Low(AIndex) to High(AIndex) do
  begin
    LoadElementParts(ABitmap, FBackstageViewMenuButton[AIndex], R,
      rbvpBackstageViewMenuItem + 2 * Ord(AIndex), DefaultFixedSize, [0, 1], [0, 1]);
    OffsetRect(R, 0, 2 * cxRectHeight(R));
  end;

  FBackstageViewMenuSeparator := AddPart1x1(ABitmap, cxRectBounds(273, 0, 113, 3), rbvpBackstageViewMenuSeparator);
end;

procedure TdxCustomRibbon2010Skin.LoadCommonElements(ABitmap: GpBitmap);
begin
  inherited LoadCommonElements(ABitmap);
  LoadCommonApplicationButton(ABitmap);
  LoadCommonBackstageView(ABitmap);
end;

procedure TdxCustomRibbon2010Skin.LoadCommonMenu(ABitmap: GpBitmap);
begin
  inherited LoadCommonMenu(ABitmap);
  Parts[FMenuSeparatorHorz].StretchMode := srsmTile;
end;

procedure TdxCustomRibbon2010Skin.LoadCommonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONCOMMON2010', AImage);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonApplicationButton(ABitmap: GpBitmap);
begin
  // nothing to do
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonBackstageView(ABitmap: GpBitmap);
begin
  FBackstageViewMenuBackground := AddPart3x3(ABitmap,
    cxRectBounds(240, 209, 17, 115), cxRect(0, 0, 7, 0), rbvpBackstageViewMenu);
  FBackstageViewTabArrow := AddPart1x1(ABitmap,
    cxRectBounds(175, 208, 15, 30), rbvpBackstageViewMenuTabButtonArrow);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonCollapsedToolbar(ABitmap: GpBitmap);
begin
  LoadElementParts(ABitmap, FCollapsedToolbars, cxRectBounds(94, 177, 68, 68),
    rspCollapsedToolbarNormal, cxRect(0, 0, 3, 3), [0, 1, 3, 2],
    [DXBAR_NORMAL, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED]);
  LoadElementParts(ABitmap, FCollapsedToolbarGlyphBackgrounds,
    cxRectBounds(66, 199, 10, 31), rspCollapsedToolbarGlyphBackgroundNormal,
    DefaultFixedSize, [0, 1, 3, 2], [DXBAR_NORMAL, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_PRESSED]);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonContexts(ABitmap: GpBitmap);
begin
  FContextBackground := AddPart3x3(ABitmap,
    cxRectBounds(25, 439, 17, 25), cxRect(2,9,2,1), rspContextBackground);
  FContextBackgroundMask := AddPart3x3(ABitmap,
    cxRectBounds(8, 439, 17, 25), cxRect(2, 9, 2, 1), rspContextBackgroundMask);
  LoadElementParts(ABitmap, FContextTabSeparator, cxRectBounds(0, 440, 2, 16),
    rspContextTabSeparatorBegin, cxNullRect, [0, 1], [0, 1], False);
  LoadElementParts(ABitmap, FContextTabGroupsArea, cxRectBounds(12, 250, 5, 92),
    rspContextTabGroupsArea, cxRect(0, 17, 0, 7), [0, 1], [0, 1], False);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonElements(ABitmap: GpBitmap);
begin
  inherited LoadRibbonElements(ABitmap);
  FItemsSeparator[False] := AddPart1x1(ABitmap, cxRectBounds(24, 320, 3, 22), rspItemSeparatorVertical);
  FItemsSeparator[True] := AddPart1x1(ABitmap, cxRectBounds(12, 343, 22, 3), rspItemSeparatorHorizontal);
  LoadRibbonBackstageView(ABitmap);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonForm(ABitmap: GpBitmap);
begin
  LoadRibbonFormBorders(ABitmap);
  LoadRibbonFormBorderIcons(ABitmap);
  FQATAtTopLeft[True][True] := AddPart3x3(ABitmap, cxRectBounds(252, 110, 5, 21), cxRect(3, 4, 0, 4), rspQATNonClientLeft1Active);
  FQATAtTopLeft[True][False] := FQATAtTopLeft[True][True];
  FQATAtTopLeft[False] := FQATAtTopLeft[True];
  FQATAtTopRight[True] := AddPart3x3(ABitmap, cxRectBounds(250, 110, 5, 21), cxRect(0, 4, 3, 4), rspQATNonClientRightActive);
  FQATAtTopRight[False] := FQATAtTopRight[True];
  FRibbonTopArea := AddPart3x3(ABitmap, cxRectBounds(169, 38, 2, 30), cxRect(0, 9, 0, 5), rspRibbonClientTopArea);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonFormBorderIcons(ABitmap: GpBitmap);
const
  OffsetMap: array[TdxBarMDIButton] of Integer = (14, 42, 0);
  PartIDMap: array[TdxBarMDIButton] of Integer = (
    rspMDIButtonMinimize, rspMDIButtonRestore, rspMDIButtonClose
  );
var
  AButton: TdxBarMDIButton;
begin
  LoadRibbonFormBorderIconsGlyphs(ABitmap, 177, 110, 13, 11);
  LoadElementParts(ABitmap, FBorderIcons, cxRectBounds(195, 37, 17, 17),
    rfspBorderIconBackground, DefaultFixedSize, [0, 1, 2], [0, 1, 2], True,
    InterpolationModeNearestNeighbor);
  LoadElementParts(ABitmap, FCloseButton, cxRectBounds(213, 37, 17, 17),
    rfspCloseButtonHot, DefaultFixedSize, [0, 1, 2], [0, 1, 2], True,
    InterpolationModeNearestNeighbor);
  LoadElementParts(ABitmap, FMinimizeRibbonButtonGlyph[rmbMinimize],
    cxRectBounds(195, 89, 9, 7), rspMinimizeRibbonButtonMinimize,
    cxNullRect, [0, 1], [0, 1], True, InterpolationModeNearestNeighbor);
  LoadElementParts(ABitmap, FMinimizeRibbonButtonGlyph[rmbRestore],
    cxRectBounds(204, 89, 9, 7), rspMinimizeRibbonButtonRestore,
    cxNullRect, [0, 1], [0, 1], True, InterpolationModeNearestNeighbor);
  LoadElementParts(ABitmap, FMinimizeRibbonButtonGlyph[rmbPin],
    cxRectBounds(213, 89, 12, 9), rspMinimizeRibbonButtonPin,
    cxNullRect, [0, 1], [0, 1], True, InterpolationModeNearestNeighbor);
  for AButton := Low(AButton) to High(AButton) do
  begin
    LoadElementParts(ABitmap, FMDIButtonGlyphs[AButton],
      cxRectBounds(163 + OffsetMap[AButton], 110, 13, 11), PartIDMap[AButton],
      cxNullRect, [0, 1, 2, 3], [0, 1, 2, 3], True, InterpolationModeNearestNeighbor);
  end;
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonFormBorders(ABitmap: GpBitmap);
var
  R: TRect;
begin
  // Caption
  AddTwoStateElement(ABitmap, FCaption,
    cxRectBounds(163, 37, 14, 31), cxRect(6, 10, 6, 5), rfspActiveCaption);
  AddTwoStateElement(ABitmap, FCaptionZoomed,
    cxRectBounds(169, 37, 2, 31), cxRect(0, 10, 0, 5), rfspActiveCaptionZoomed);
  R := cxRectBounds(163, 37, 8, 31);
  AddTwoStateElement(ABitmap, FCaptionLeftBorder, R, cxRect(0, 9, 0, 2), rfspActiveCaptionLeftBorder);
  OffsetRect(R, 6, 0);
  AddTwoStateElement(ABitmap, FCaptionRightBorder, R, cxRect(0, 9, 0, 2), rfspActiveCaptionRightBorder);
  //active border
  R := cxRectBounds(178, 37, 8, 11);
  AddTwoStateElement(ABitmap, FLeftBorder, R, cxRect(0, 0, 0, 7), rfspActiveLeftBorder);
  OffsetRect(R, 8, 0);
  AddTwoStateElement(ABitmap, FRightBorder, R, cxRect(0, 0, 0, 7), rfspActiveRightBorder);
  //bottom border
  AddTwoStateElement(ABitmap, FBottomBorderThin,
    cxRectBounds(178, 60, 3, 1), cxEmptyRect, rfspActiveBottomBorderThin);
  AddTwoStateElement(ABitmap, FBottomBorderThick[False],
    cxRectBounds(178, 67, 16, 8), cxRect(7, 0, 7, 0), rfspActiveBottomBorderThick);
  AddTwoStateElement(ABitmap, FBottomBorderThick[True],
    cxRectBounds(178, 83, 16, 8), cxRect(7, 0, 7, 0), rfspActiveBottomBorderThickRectangular);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonGalleryInRibbonScrollBarButtonsGlyphs(ABitmap: GpBitmap);
begin
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarLineUpButtonGlyph,
    cxRectBounds(66, 388, 5, 3), rspInRibbonGalleryScrollBarLineUpButtonGlyphNormal,
    cxNullRect, [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED]);
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarLineDownButtonGlyph,
    cxRectBounds(71, 388, 5, 3), rspInRibbonGalleryScrollBarLineDownButtonGlyphNormal,
    cxNullRect, [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED]);
  LoadElementParts(ABitmap, FInRibbonGalleryScrollBarDropDownButtonGlyph,
    cxRectBounds(77, 388, 7, 7), rspInRibbonGalleryScrollBarDropDownButtonGlyphNormal,
    cxNullRect, [0, 3, 1, 2], [DXBAR_NORMAL, DXBAR_DISABLED, DXBAR_HOT, DXBAR_PRESSED]);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonGroup(ABitmap: GpBitmap);
begin
  LoadElementParts(ABitmap, FTabGroupsArea, cxRectBounds(13, 116, 5, 92),
    rspTabGroupsArea, cxRect(0, 17, 0, 7), [0, 1], [0, 1], False);
  FTabGroupsArea[2] := AddPart3x3(ABitmap, cxRectBounds(24, 116, 5, 89),
    cxRect(2, 17, 2, 7), rspTabGroupsAreaInPopup);

  LoadElementParts(ABitmap, FToolbar, cxRectBounds(94, 0, 68, 68),
    rspToolbarNormal, cxRect(0, 0, 3, 0), [], [DXBAR_NORMAL, DXBAR_HOT]);
  LoadElementParts(ABitmap, FToolbarHeader, cxRectBounds(94, 136, 68, 20),
    rspToolbarHeaderNormal, cxRect(0, 0, 3, 2), [], [DXBAR_NORMAL, DXBAR_HOT]);
  LoadElementParts(ABitmap, FMarkArrow, cxRectBounds(36, 220, 7, 7),
    rspMarkArrowNormal, cxEmptyRect, [0, 0, 1], [DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED], True);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonStatusBar(ABitmap: GpBitmap);
begin
  FStatusBar := AddPart1x3(ABitmap, cxRectBounds(198, 354, 3, 30), 2, 0, rspStatusBar);
  FStatusBarGripBackground := FStatusBar;
  FStatusBarPanelLowered := FStatusBar;
  FStatusBarPanelRaised := FStatusBar;
  FStatusBarPanel := FStatusBar;

  FStatusBarPanelSeparator := AddPart1x3(ABitmap,
    cxRectBounds(202, 354, 3, 30), 2, 0, rspStatusBarPanelSeparator);
  FStatusBarToolbarSeparator := AddPart1x3(ABitmap,
    cxRectBounds(206, 354, 3, 20), 2, 0, rspStatusBarToolbarSeparator);

  LoadElementParts(ABitmap, FFormStatusBarLeftParts[False], cxRectBounds(163, 354, 8, 21),
    rspStatusBarFormLeftPart, cxRect(0, 2, 0, 8), [0, 1, 2, 3], [0, 1, 2, 3]);
  LoadElementParts(ABitmap, FFormStatusBarRightParts[False], cxRectBounds(172, 354, 8, 21),
    rspStatusBarFormRightPart, cxRect(0, 2, 0, 8), [0, 1, 2, 3], [0, 1, 2, 3]);
  LoadElementParts(ABitmap, FFormStatusBarLeftParts[True], cxRectBounds(180, 354, 8, 22),
    rspStatusBarFormLeftPartDialog, cxRect(0, 2, 0, 8), [0, 1, 2, 3], [0, 1, 2, 3]);
  LoadElementParts(ABitmap, FFormStatusBarRightParts[True], cxRectBounds(189, 354, 8, 22),
    rspStatusBarFormRightPartDialog, cxRect(0, 2, 0, 8), [0, 1, 2, 3], [0, 1, 2, 3]);
end;

procedure TdxCustomRibbon2010Skin.LoadRibbonTab(ABitmap: GpBitmap);
begin
  LoadElementParts(ABitmap, FTabIndex, cxRectBounds(0, 0, 24, 23),
    rspTabNormal, cxRect(4, 4, 4, 4), [0, 1, 2, 3, 4], [0, 1, 2, 3, 4]);
  LoadElementParts(ABitmap, FContextTabIndex, cxRectBounds(163, 253, 36, 20),
    rspContextTabNormal, cxRect(5, 3, 5, 1), [0, 1, 2, 3, 4], [0, 1, 2, 3, 4]);
  LoadElementParts(ABitmap, FContextTabMaskIndex, cxRectBounds(199, 253, 36, 20),
    rspContextTabMaskNormal, cxRect(5, 3, 5, 1), [0, 1, 2, 3, 4], [0, 1, 2, 3, 4]);
  FTabSeparator := AddPart1x1(ABitmap, cxRectBounds(42, 86, 2, 16), rspTabSeparator);
  FTabsAreaOnGlass := AddPart3x3(ABitmap, cxRectBounds(163, 0, 95, 36),
    cxRect(42, 0, 42, 0), rspTabsAreaOnGlass, '', InterpolationModeHighQualityBicubic);
end;

{ TdxBlueRibbonSkin }

procedure TdxBlueRibbonSkin.DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect);
var
  R1: TRect;
begin
  R1 := R;
  Dec(R1.Bottom);
  FillRectByColor(DC, R1, $EBC3A4);
  OffsetRect(R1, 0, 1);
  FillRectByColor(DC, R1, $F3E2D5);
end;

function TdxBlueRibbonSkin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
const
  RibbonEditHotBackgroundColor = clWhite;
  RibbonEditNormalBorderColor = $DEC1AB;
  RibbonEditHotBorderColor = $E1C7B3;
  RibbonEditDisabledBorderColor = $C6BBB1;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  if LowColors then Exit;
  case APart of
    DXBAR_MENUEDITSEPARATOR:
      case AState of
        DXBAR_ACTIVE:  Result := $85B6CA;
        DXBAR_ACTIVEDISABLED:  Result := $CDCDCD;
      end;
    DXBAR_MENUITEMTEXT:
      if not (AState in [DXBAR_DISABLED, DXBAR_ACTIVEDISABLED]) then
        Result := $6E1500;
    DXBAR_EDIT_BORDER:
      case AState of
        DXBAR_NORMAL: Result := RibbonEditNormalBorderColor;
        DXBAR_HOT, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := RibbonEditHotBorderColor;
        DXBAR_DISABLED: Result := RibbonEditDisabledBorderColor;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN: Result := RibbonEditHotBorderColor;
      end;
    DXBAR_EDIT_BACKGROUND:
      case AState of
        DXBAR_NORMAL: Result := $FBF2EA;
        DXBAR_HOT, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := RibbonEditHotBackgroundColor;
        DXBAR_DISABLED: Result := $EFEFEF;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN: Result := RibbonEditHotBackgroundColor;
      end;
    DXBAR_EDIT_BUTTON_BORDER:
      case AState of
        DXBAR_NORMAL: Result := RibbonEditNormalBorderColor;
        DXBAR_ACTIVE: Result := $DEC7AD;
        DXBAR_HOT: Result := $99CEDB;
        DXBAR_PRESSED: Result := $45667B;
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED: Result := RibbonEditDisabledBorderColor;
        DXBAR_DROPPEDDOWN: Result := $6B99A5;
      end;
    DXBAR_SCREENTIP_FOOTERLINE:
      Result := $DDBB9E;
    DXBAR_DATENAVIGATOR_HEADER:
      Result := $DAD5D2;
    DXBAR_SEPARATOR_BACKGROUND:
      Result := $EFE7DE;
    DXBAR_INRIBBONGALLERY_BACKGROUND:
      if AState in [DXBAR_ACTIVE, DXBAR_HOT] then
        Result := $FBF3EC
      else
        Result := $F8E6D4;
    DXBAR_INRIBBONGALLERY_BORDER:
      Result := $EDD0B9;
    DXBAR_GALLERYFILTERBANDTEXT:
      if AState = DXBAR_NORMAL then
        Result := $6E1500
      else if AState = DXBAR_HOT then
        Result := $FF6600
      else
        OutError;
    rspRibbonBackground:
      Result := $FFDBBF;
    rspRibbonBottomEdge:
      Result := $F3E2D5;
    rfspRibbonForm:
      Result := $EBC3A4;
    rspFormCaptionText:
      if AState = DXBAR_NORMAL then
        Result := $AA6A3E
      else
        Result := $A0A0A0;
    rspDocumentNameText:
      if AState = DXBAR_NORMAL then
        Result := $797069
      else
        Result := $A0A0A0;
    rspTabHeaderText, rspTabGroupText:
      Result := $8B4215;
    rspTabGroupHeaderText:
      Result := $AA6A3E;
    rspStatusBarText:
      if AState = DXBAR_DISABLED then
        Result := $8D8D8D
      else
        Result := $8B4215;
    rspStatusBarSizeGripColor1:
      Result := $805D45;
    rspStatusBarSizeGripColor2:
      Result := $E8C9B1;
  end;
end;

function TdxBlueRibbonSkin.GetName: string;
begin
  Result := 'Blue';
end;

procedure TdxBlueRibbonSkin.GetApplicationMenuContentColors(
  var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor);
begin
  if LowColors then
    inherited GetApplicationMenuContentColors(AInnerBorderColor, AOuterBorderColor, ASideColor)
  else
  begin
    AInnerBorderColor := $CAAF9B;
    AOuterBorderColor := clWhite;
    ASideColor := $EDD3BE;
  end;
end;

procedure TdxBlueRibbonSkin.LoadRibbonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONBLUE', AImage);
end;

{ TdxBlackRibbonSkin }

procedure TdxBlackRibbonSkin.DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect);
var
  R1: TRect;
begin
  R1 := R;
  Dec(R1.Bottom);
  FillRectByColor(DC, R1, $4F4F4F);
  OffsetRect(R1, 0, 1);
  FillRectByColor(DC, R1, $626262);
end;

function TdxBlackRibbonSkin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
const
  RibbonEditHotBackgroundColor = clWhite;
  RibbonEditNormalBorderColor = $898989;
  RibbonEditHotBorderColor = $898989;
  RibbonEditDisabledBorderColor = $CCCCCC;
  RibbonItemText = $464646;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  if LowColors then Exit;
  case APart of
    DXBAR_MENUEDITSEPARATOR:
      case AState of
        DXBAR_ACTIVE:  Result := $85B6CA;
        DXBAR_ACTIVEDISABLED:  Result := $CDCDCD;
      end;
    DXBAR_MENUITEMTEXT:
      if not (AState in [DXBAR_DISABLED, DXBAR_ACTIVEDISABLED]) then
        Result := RibbonItemText;
    DXBAR_EDIT_BORDER:
      case AState of
        DXBAR_NORMAL: Result := RibbonEditNormalBorderColor;
        DXBAR_HOT, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := RibbonEditHotBorderColor;
        DXBAR_DISABLED: Result := RibbonEditDisabledBorderColor;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN: Result := RibbonEditHotBorderColor;
      end;
    DXBAR_EDIT_BACKGROUND:
      case AState of
        DXBAR_NORMAL: Result := $E8E8E8;
        DXBAR_HOT, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := RibbonEditHotBackgroundColor;
        DXBAR_DISABLED: Result := $EFEFEF;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN: Result := RibbonEditHotBackgroundColor;
      end;
    DXBAR_EDIT_BUTTON_BORDER:
      case AState of
        DXBAR_NORMAL: Result := RibbonEditNormalBorderColor;
        DXBAR_ACTIVE: Result := $B7B7B7;
        DXBAR_HOT: Result := $99CEDB;
        DXBAR_PRESSED: Result := $45667B;
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED: Result := RibbonEditDisabledBorderColor;
        DXBAR_DROPPEDDOWN: Result := $6B99A5;
      end;
    DXBAR_DATENAVIGATOR_HEADER:
      Result := $DAD5D2;
    DXBAR_SEPARATOR_BACKGROUND:
      Result := $EFEBEF;
    DXBAR_SCREENTIP_FOOTERLINE:
      Result := $A49991;
    DXBAR_INRIBBONGALLERY_BACKGROUND:
      if AState in [DXBAR_ACTIVE, DXBAR_HOT] then
        Result := $F7F7F7
      else
        Result := $E2E2DA;
    DXBAR_INRIBBONGALLERY_BORDER:
      Result := $ACACAC;
    DXBAR_GALLERYFILTERBANDTEXT:
      if AState = DXBAR_NORMAL then
        Result := $FFFFFF
      else if AState = DXBAR_HOT then
        Result := $32D2FF
      else
        OutError;
    rspRibbonBackground:
      Result := $535353;
    rspRibbonBottomEdge:
      Result := $626262;
    rfspRibbonForm:
      Result := $696969;
    rspFormCaptionText:
      if AState = DXBAR_NORMAL then
        Result := $FFD1AE
      else
        Result := $E1E1E1;
    rspDocumentNameText:
      if AState = DXBAR_NORMAL then
        Result := $FFFFFF
      else
        Result := $E1E1E1;
    rspTabHeaderText:
      if AState = DXBAR_ACTIVE then
        Result := clBlack
      else
        Result := $FFFFFF;
    rspTabGroupText:
      Result := RibbonItemText;
    rspTabGroupHeaderText:
      Result := $FFFFFF;
    rspStatusBarText:
      case AState of
        DXBAR_NORMAL:
          Result := $FFFFFF;
        DXBAR_HOT, DXBAR_HOTCHECK, DXBAR_CHECKED:
          Result := clBlack;
        else
          Result := $C2C2C2;
      end;
    rspStatusBarSizeGripColor1:
      Result := $252525;
    rspStatusBarSizeGripColor2:
      Result := $CCCCCC;
  end;
end;

function TdxBlackRibbonSkin.GetName: string;
begin
  Result := 'Black';
end;

procedure TdxBlackRibbonSkin.GetApplicationMenuContentColors(
  var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor);
begin
  if LowColors then
    inherited GetApplicationMenuContentColors(AInnerBorderColor, AOuterBorderColor, ASideColor)
  else
  begin
    AInnerBorderColor := $414243;
    AOuterBorderColor := $716C6B;
    ASideColor := $504F4F;
  end;
end;

procedure TdxBlackRibbonSkin.LoadRibbonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONBLACK', AImage);
end;

{ TdxSilverRibbonSkin }

procedure TdxSilverRibbonSkin.DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect);
var
  R1: TRect;
begin
  R1 := R;
  Dec(R1.Bottom);
  FillRectByColor(DC, R1, $808080);
  OffsetRect(R1, 0, 1);
  FillRectByColor(DC, R1, $DCE1EB);
end;

function TdxSilverRibbonSkin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
const
  RibbonItemText = $5C534C;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  if LowColors then Exit;
  case APart of
    DXBAR_MENUITEMTEXT:
      if not (AState in [DXBAR_DISABLED, DXBAR_ACTIVEDISABLED]) then
        Result := RibbonItemText;
    DXBAR_INRIBBONGALLERY_BACKGROUND:
      if AState in [DXBAR_ACTIVE, DXBAR_HOT] then
        Result := $F2F1F0
      else
        Result := $ECEAE8;
    DXBAR_INRIBBONGALLERY_BORDER:
      if AState in [DXBAR_ACTIVE, DXBAR_HOT] then
        Result := $A4A4A4
      else
        Result := $B8B1A9;
    DXBAR_GALLERYFILTERBANDTEXT:
      if AState = DXBAR_NORMAL then
        Result := $FFFFFF
      else if AState = DXBAR_HOT then
        Result := $32D2FF
      else
        OutError;
    rspRibbonBackground:
      Result := $DDD4D0;
    rspRibbonBottomEdge:
      Result := $808080;
    rfspRibbonForm:
      Result := $B5AEAA;
    rspFormCaptionText:
      if AState = DXBAR_NORMAL then
        Result := $AA6E35
      else
        Result := $8A8A8A;
    rspDocumentNameText:
      if AState = DXBAR_NORMAL then
        Result := $6A625C
      else
        Result := $8A8A8A;
    rspTabHeaderText:
      Result := $595453;
    rspTabGroupText, rspTabGroupHeaderText:
      Result := RibbonItemText;
    rspStatusBarText:
      if AState = DXBAR_DISABLED then
        Result := $8D8D8D
      else
        Result := $595453;
    rspStatusBarSizeGripColor1:
      Result := $7E77670;
    rspStatusBarSizeGripColor2:
      Result := $D9D0CD;
  end;
end;

function TdxSilverRibbonSkin.GetName: string;
begin
  Result := 'Silver';
end;

procedure TdxSilverRibbonSkin.GetApplicationMenuContentColors(
  var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor);
begin
  if LowColors then
    inherited GetApplicationMenuContentColors(AInnerBorderColor, AOuterBorderColor, ASideColor)
  else
  begin
    AInnerBorderColor := $B4AEA9;
    AOuterBorderColor := $FAFAFA;
    ASideColor := $D8D2CD;
  end;
end;

procedure TdxSilverRibbonSkin.LoadRibbonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONSILVER', AImage);
end;

{ TdxBlueRibbon2010Skin }

procedure TdxBlueRibbon2010Skin.DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, $AD8E72);
end;

function TdxBlueRibbon2010Skin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  if LowColors then Exit;

  case APart of
    DXBAR_INRIBBONGALLERY_BACKGROUND:
      case AState of
        DXBAR_ACTIVE, DXBAR_HOT:
          Result := $FCF7F2
        else
          Result := $FDF5ED;
      end;
    DXBAR_EDIT_BORDER:
      case AState of
        DXBAR_NORMAL: Result := $D6C0B1;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN, DXBAR_HOT,
        DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := $D0BAAB;
        DXBAR_DISABLED: Result := $DEDDCD;
      end;
    DXBAR_EDIT_BACKGROUND:
      case AState of
        DXBAR_NORMAL: Result := $FDF5ED;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN, DXBAR_HOT,
        DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := $FCF7F2;
        DXBAR_DISABLED: Result := $FDF5ED;
      end;
    DXBAR_SCREENTIP_FOOTERLINE:
      Result := $DDBB9E;
    rspStatusBarSizeGripColor1:
      Result := $BD9D84;
    rspStatusBarSizeGripColor2:
      Result := $F1E1D4;
    rspRibbonBackground, rfspRibbonForm:
      Result := $E4CCB7;
    rspFormCaptionText, rspDocumentNameText:
      if AState <> DXBAR_NORMAL then
        Result := $A36736;
  end;
end;

procedure TdxBlueRibbon2010Skin.DrawTabAreaBackground(DC: HDC; const R: TRect;
  AActive, AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState);
const
  ColorMap: array[Boolean] of TColor = ($F7EBDF, $E8D0BD);
begin
  if LowColors then
    inherited DrawTabAreaBackground(DC, R, AActive, AUseAeroGlass, AApplicationMenuState)
  else
    if not AUseAeroGlass then
      FillRectByColor(DC, R, ColorMap[AActive]);
end;

procedure TdxBlueRibbon2010Skin.DrawFormCaptionSeparator(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, $AD8E72);
end;

procedure TdxBlueRibbon2010Skin.GetApplicationMenuContentColors(
  var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor);
begin
  AInnerBorderColor := clNone;
  AOuterBorderColor := $B9AFA8;
  ASideColor := clNone;
end;

function TdxBlueRibbon2010Skin.GetName: string;
begin
  Result := 'Blue';
end;

procedure TdxBlueRibbon2010Skin.LoadRibbonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONBLUE2010', AImage);
end;

{ TdxSilverRibbon2010Skin }

procedure TdxSilverRibbon2010Skin.DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, $928C87);
end;

procedure TdxSilverRibbon2010Skin.DrawTabAreaBackground(DC: HDC; const R: TRect;
  AActive, AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState);
const
  ColorMap: array[Boolean] of TColor = ($FCFCFC, $E8E6E3);
begin
  if LowColors then
    inherited DrawTabAreaBackground(DC, R, AActive, AUseAeroGlass, AApplicationMenuState)
  else
    if not AUseAeroGlass then
      FillRectByColor(DC, R, ColorMap[AActive]);
end;

function TdxSilverRibbon2010Skin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  if LowColors then Exit;

  case APart of
    DXBAR_GALLERYFILTERBANDTEXT:
      if AState = DXBAR_HOT then
        Result := $32D2FF
      else
        Result := $FFFFFF;
    DXBAR_INRIBBONGALLERY_BACKGROUND:
      Result := $FFFFFF;
    DXBAR_EDIT_BORDER:
      case AState of
        DXBAR_NORMAL: Result := $D9D6D4;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN, DXBAR_HOT,
        DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := $C4BFBB;
        DXBAR_DISABLED: Result := $EBE7E4;
      end;
    DXBAR_EDIT_BACKGROUND:
      case AState of
        DXBAR_NORMAL, DXBAR_FOCUSED, DXBAR_DROPPEDDOWN, DXBAR_HOT,
        DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := $FFFFFF;
        DXBAR_DISABLED: Result := $FAFAFA;
      end;
    DXBAR_SCREENTIP_FOOTERLINE:
      Result := $BDBDBD;
    rspContextText:
      Result := clGray;
    rspContextTextShadow:
      Result := clWhite;
    rspStatusBarSizeGripColor1:
      Result := $C7BEB5;
    rspStatusBarSizeGripColor2:
      Result := $FFFFFF;
    rspRibbonBackground, rfspRibbonForm:
      Result := $F1EDE9;
    rspFormCaptionText, rspDocumentNameText:
      if AState <> DXBAR_NORMAL then
        Result := $8A8A8A;
  end;
end;

procedure TdxSilverRibbon2010Skin.DrawFormCaptionSeparator(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, $928C87);
end;

procedure TdxSilverRibbon2010Skin.GetApplicationMenuContentColors(
  var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor);
begin
  AInnerBorderColor := clNone;
  AOuterBorderColor := $C6C3C0;
  ASideColor := clNone;
end;

function TdxSilverRibbon2010Skin.GetName: string;
begin
  Result := 'Silver';
end;

procedure TdxSilverRibbon2010Skin.LoadRibbonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONSILVER2010', AImage);
end;

{ TdxBlackRibbon2010Skin }

procedure TdxBlackRibbon2010Skin.DrawMenuExtraSeparator(
  DC: HDC; const R: TRect; AHorizontal: Boolean);
begin
  InternalDrawSeparator(DC, R, AHorizontal, $CECECE, $ABABAB);
end;

procedure TdxBlackRibbon2010Skin.DrawRibbonTopFrameAreaSeparator(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, $484848);
end;

procedure TdxBlackRibbon2010Skin.DrawTabAreaBackground(DC: HDC; const R: TRect;
  AActive, AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState);
const
  ColorMap: array[Boolean] of TColor = ($9E9E9E, $717171);
begin
  if LowColors then
    inherited DrawTabAreaBackground(DC, R, AActive, AUseAeroGlass, AApplicationMenuState)
  else
    if not AUseAeroGlass then
      FillRectByColor(DC, R, ColorMap[AActive]);
end;

function TdxBlackRibbon2010Skin.GetPartColor(APart: Integer; AState: Integer = 0;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent = rcsaYellow): TColor;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  if LowColors then Exit;

  case APart of
    DXBAR_INRIBBONGALLERY_BACKGROUND:
      case AState of
        DXBAR_ACTIVE, DXBAR_HOT:
          Result := $C1C1C1
        else
          Result := $BBBBBB;
      end;

    DXBAR_GALLERYFILTERBANDTEXT:
      if AState = DXBAR_HOT then
        Result := $32D2FF
      else
        Result := $FFFFFF;

    DXBAR_EDIT_BORDER:
      case AState of
        DXBAR_NORMAL, DXBAR_FOCUSED, DXBAR_DROPPEDDOWN, DXBAR_HOT,
        DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := $848484;
        DXBAR_DISABLED: Result := $A0A0A0;
      end;

    DXBAR_EDIT_BACKGROUND:
      case AState of
        DXBAR_NORMAL: Result := $C6C6C6;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN, DXBAR_HOT,
        DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED: Result := $CCCCCC;
        DXBAR_DISABLED: Result := $B6B6B6;
      end;

    rspTabHeaderText:
      case AState of
        DXBAR_ACTIVE:
          Result := clBlack;
        DXBAR_HOT:
          Result := $F0F0F0;
        else
          Result := $E2E2E2;
      end;

    rspStatusBarText:
      case AState of
        DXBAR_HOT, DXBAR_HOTCHECK, DXBAR_CHECKED:
          Result := clBlack;
        DXBAR_DISABLED:
          Result := GetPartColor(DXBAR_ITEMTEXT, DXBAR_DISABLED, AColorSchemeAccent);
        else
          Result := $E2E2E2;
      end;

    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM_TEXTCOLOR:
      case AState of
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
          Result := $A7A7A7;
        else
          Result := clWhite;
      end;

    DXBAR_BACKSTAGEVIEW_MENUBAR_TAB_TEXTCOLOR:
      case AState of
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
          Result := $A7A7A7;
        DXBAR_HOTCHECK, DXBAR_CHECKED, DXBAR_PRESSED:
          if AColorSchemeAccent = rcsaYellow then
            Result := clBlack
          else
            Result := clWhite;
        else
          Result := clWhite;
      end;

   DXBAR_SCREENTIP_FOOTERLINE:
      Result := $BDBDBD;
    rspStatusBarSizeGripColor1:
      Result := $1B1B1B;
    rspStatusBarSizeGripColor2:
      Result := $595959;
    rspRibbonBackground, rfspRibbonForm:
      Result := $8B8B8B;
    rspFormCaptionText, rspDocumentNameText:
      if AState <> DXBAR_NORMAL then
        Result := $D4D4D4
      else
        Result := $E2E2E2;
  end;
end;

procedure TdxBlackRibbon2010Skin.DrawFormCaptionSeparator(DC: HDC; const R: TRect);
begin
  FillRectByColor(DC, R, $484848);
end;

procedure TdxBlackRibbon2010Skin.GetApplicationMenuContentColors(
  var AInnerBorderColor, AOuterBorderColor, ASideColor: TColor);
begin
  AInnerBorderColor := clNone;
  AOuterBorderColor := $ABABAB;
  ASideColor := clNone;
end;

function TdxBlackRibbon2010Skin.GetName: string;
begin
  Result := 'Black';
end;

procedure TdxBlackRibbon2010Skin.LoadRibbonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONBLACK2010', AImage);
end;

{ TdxCustomRibbon2013Skin }

procedure TdxCustomRibbon2013Skin.DrawFormStatusBarPart(DC: HDC; const R: TRect;
  AIsLeft, AIsActive, AIsRaised, AIsRectangular: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawFormStatusBarPart(DC, R, AIsLeft, AIsActive, AIsRaised, AIsRectangular, AColorSchemeAccent)
  else
    FillRectByColor(DC, R, GetFormBorderColor(AIsActive, AColorSchemeAccent));
end;

procedure TdxCustomRibbon2013Skin.DrawStatusBarPanel(DC: HDC;
  const Bounds, R: TRect; AIsLowered: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawStatusBar(DC, R, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawTabAreaBackground(DC: HDC; const R: TRect;
  AActive, AUseAeroGlass: Boolean; AApplicationMenuState: TdxRibbonApplicationMenuState);
begin
  if LowColors then
    inherited DrawTabAreaBackground(DC, R, AActive, AUseAeroGlass, AApplicationMenuState)
  else
    if not AUseAeroGlass then
      FillRectByColor(DC, R, GetCaptionAreaColor(AApplicationMenuState));
end;

function TdxCustomRibbon2013Skin.GetPartColor(APart, AState: Integer;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
begin
  Result := inherited GetPartColor(APart, AState, AColorSchemeAccent);
  if LowColors then
    Exit;

  case APart of
    rspContextTextShadow:
      Result := clNone;
    rspTabGroupHeaderText:
      Result := GetPartColor(DXBAR_ITEMTEXT, AState, AColorSchemeAccent);
    rspRibbonBackground, rfspRibbonForm:
      Result := GetMasterColor;
    DXBAR_BACKSTAGEVIEW:
      Result := clWhite;
    DXBAR_MENUARROWSEPARATOR:
      Result := $E5E2DF;
    DXBAR_SEPARATOR_TEXTCOLOR:
      Result := $646464;
    DXBAR_KEYTIP_TEXTCOLOR:
      Result := clWhite;
    DXBAR_INRIBBONGALLERY_BACKGROUND:
      Result := GetPartColor(DXBAR_EDIT_BACKGROUND, DXBAR_NORMAL, AColorSchemeAccent);
    rspApplicationButton:
      Result := clWhite;

    DXBAR_BACKSTAGEVIEW_TEXTCOLOR:
      Result := clBlack;
    DXBAR_BACKSTAGEVIEW_GALLERYCONTROL_ITEMCAPTIONTEXTCOLOR:
      Result := $262626;
    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM_TEXTCOLOR,
    DXBAR_BACKSTAGEVIEW_MENUBAR_TAB_TEXTCOLOR:
      case AState of
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
          Result := GetMenuBackgroundColor(AColorSchemeAccent, 0.2);
        else
          Result := clWhite;
      end;

    rspStatusBarText:
      case AState of
        DXBAR_NORMAL:
          Result := clWhite;
        DXBAR_DISABLED:
          Result := GetMenuBackgroundColor(AColorSchemeAccent, 0.2);
        else
          Result := GetPartColor(DXBAR_ITEMTEXT, AState, AColorSchemeAccent);
      end;

    rspTabHeaderText:
      case AState of
        DXBAR_ACTIVE, DXBAR_HOT, DXBAR_FOCUSED:
          begin
            Result := GetAccentColor(AColorSchemeAccent);
            if AColorSchemeAccent = rcsaYellow then
              Result := TdxColorHelper.ChangeLightness(Result, -0.2);
          end;
        else
          Result := GetPartColor(DXBAR_ITEMTEXT, AState, AColorSchemeAccent);
      end;

    rspFormCaptionText, rspDocumentNameText:
      if AState <> DXBAR_NORMAL then
        Result := $818181
      else
        Result := $292929;

    DXBAR_ITEMTEXT:
      case AState of
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
          Result := $8D8D8D;
        else
          Result := $282828;
      end;

    DXBAR_EDIT_BACKGROUND:
      case AState of
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
          Result := $FFFFFF;
        else
          Result := $FEFEFE;
      end;

    DXBAR_ARROWDOWN:
      case AState of
        DXBAR_DISABLED:
          Result := $C6C6C6;
        DXBAR_HOT, DXBAR_PRESSED, DXBAR_DROPPEDDOWN:
          Result := $444444;
        else
          Result := $777777;
      end;

    DXBAR_MENUITEMTEXT:
      case AState of
        DXBAR_DISABLED, DXBAR_ACTIVEDISABLED:
          Result := $B1B1B1;
        else
          Result := $646464;
      end;

    DXBAR_EDIT_BORDER, DXBAR_EDIT_BUTTON_BORDER:
      case AState of
        DXBAR_NORMAL:
          Result := GetFrameColor;
        DXBAR_FOCUSED, DXBAR_DROPPEDDOWN, DXBAR_HOT, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
          Result := GetHighlightBorderColor(AColorSchemeAccent);
        DXBAR_DISABLED:
          Result := $E2E2E2;
      end;

    DXBAR_RADIALMENUACCENT:
      Result := GetMenuBackgroundColor(AColorSchemeAccent);
    DXBAR_RADIALMENUBACKGROUND:
      Result := GetPartColor(rspRibbonBackground);
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawApplicationButton(DC: HDC; const R: TRect;
  AState: TdxRibbonApplicationButtonState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawApplicationButton(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      rabsNormal, rabsPressed:
        dxGpFillRect(DC, R, GetMenuBackgroundColor(AColorSchemeAccent));
      rabsHot:
        dxGpFillRect(DC, R, GetAccentColor(AColorSchemeAccent, 0.1));
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawArrowDown(DC: HDC; const R: TRect; AState: Integer);
begin
  if LowColors then
    inherited DrawArrowDown(DC, R, AState)
  else
    DrawArrow(DC, cxRectOffset(R, 1, 0), adDown, AState);
end;

procedure TdxCustomRibbon2013Skin.DrawRibbonClientTopArea(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawRibbonClientTopArea(DC, R)
  else
    FillRectByColor(DC, R, GetCaptionAreaColor(ramsHidden));
end;

procedure TdxCustomRibbon2013Skin.DrawApplicationMenuBackground(
  DC: HDC; const R: TRect; const AContentRect: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, GetMasterColor);
  FillRectByColor(DC, cxRectSetTop(R, AContentRect.Bottom, R.Bottom - AContentRect.Bottom), $F0F0F0);
  FillRectByColor(DC, cxRectSetBottom(R, AContentRect.Top, AContentRect.Top - R.Top), GetMenuBackgroundColor(AColorSchemeAccent));
  DrawFrame(DC, R, clNone, GetFormBorderColor(True, AColorSchemeAccent));
end;

procedure TdxCustomRibbon2013Skin.DrawApplicationMenuButton(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawApplicationMenuExtraPanePinButtonGlyph(
  DC: HDC; const R: TRect; AState: Integer; AChecked: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);

  function GetGlyphColor(AState: Integer): TColor;
  begin
    case AState of
      DXBAR_HOT, DXBAR_HOTCHECK:
        Result := GetAccentColor(AColorSchemeAccent, 0.1);
      else
        Result := clDefault;
    end;
  end;

var
  APart: TdxSkinnedRect;
begin
  APart := Parts[FPinButtonGlyphs[AChecked]];
  APart.DrawColored(DC, cxRectCenter(R, APart.Size), GetGlyphColor(AState));
end;

procedure TdxCustomRibbon2013Skin.DrawMenuExtraSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean);
begin
  InternalDrawSeparator(DC, R, AHorizontal, clWhite, GetFrameColor);
end;

procedure TdxCustomRibbon2013Skin.DrawBackstageViewBackButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);

  function GetGlyphColor(AState: Integer): TColor;
  begin
    case AState of
      DXBAR_HOT:
        Result := GetAccentColor(AColorSchemeAccent, 0.3);
      DXBAR_PRESSED:
        Result := GetAccentColor(AColorSchemeAccent, 0.1);
      else
        Result := clWhite;
    end;
  end;

var
  ABackgroundColor: TColor;
  AGlyphColor: TColor;
begin
  if LowColors then
  begin
    ABackgroundColor := $FCFCFC;
    AGlyphColor := clBlack;
  end
  else
  begin
    ABackgroundColor := GetMenuBackgroundColor(AColorSchemeAccent);
    AGlyphColor := GetGlyphColor(AState);
  end;
  Parts[FBackstageViewBackButton[True]].DrawColored(DC, R, ABackgroundColor);
  Parts[FBackstageViewBackButton[False]].DrawColored(DC, R, AGlyphColor);
end;

procedure TdxCustomRibbon2013Skin.DrawBackstageViewMenuBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawBackstageViewMenuBackground(DC, R, AColorSchemeAccent)
  else
    FillRectByColor(DC, R, GetMenuBackgroundColor(AColorSchemeAccent));
end;

procedure TdxCustomRibbon2013Skin.DrawBackstageViewMenuButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawBackstageViewMenuButton(DC, R, AState, AColorSchemeAccent)
  else
    DrawBackstageViewTabButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawBackstageViewMenuHeader(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawBackstageViewMenuHeader(DC, R, AColorSchemeAccent)
  else
    DrawBackstageViewMenuBackground(DC, R, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawBackstageViewMenuSeparator(
  DC: HDC; const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawBackstageViewMenuSeparator(DC, R, AState, AColorSchemeAccent)
  else
    FillRectByColor(DC,
      cxRectInflate(cxRectCenterVertically(R, 1), -15, 0),
      GetMenuBackgroundColor(AColorSchemeAccent, 0.1));
end;

procedure TdxCustomRibbon2013Skin.DrawBackstageViewTabButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawBackstageViewTabButton(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      DXBAR_PRESSED, DXBAR_HOT, DXBAR_HOTCHECK, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
        FillRectByColor(DC, R, GetMenuBackgroundColor(AColorSchemeAccent, -0.08));
      DXBAR_CHECKED:
        FillRectByColor(DC, R, GetMenuBackgroundColor(AColorSchemeAccent, 0.08));
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawButtonGroup(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawButtonGroupBorderLeft(DC: HDC; const R: TRect);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawButtonGroupBorderMiddle(DC: HDC; const R: TRect; AState: Integer);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawButtonGroupBorderRight(DC: HDC; const R: TRect);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawButtonGroupDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButtonDropButtonArrowPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawButtonGroupDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButtonDropButtonMainPart(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawButtonGroupSplitButtonSeparator(
  DC: HDC; const R: TRect; AState: Integer);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawCollapsedToolbarGlyphBackground(
  DC: HDC; const R: TRect; AState: Integer);
begin
  if LowColors then
    inherited DrawCollapsedToolbarGlyphBackground(DC, R, AState)
  else
    DrawFrame(DC, R, $FDFDFD, $C7C7C7);
end;

procedure TdxCustomRibbon2013Skin.DrawCollapsedToolbarBackground(
  DC: HDC; const R: TRect; AState: Integer);
begin
  if LowColors then
  begin
    inherited DrawCollapsedToolbarBackground(DC, R, AState);
    Exit;
  end;

  case AState of
    DXBAR_HOT:
      FillRectByColor(DC, R, $ECECEC);
    DXBAR_PRESSED:
      FillRectByColor(DC, R, $E6E6E6);
  end;
  FillRectByColor(DC, cxRectSetRight(R, R.Right, 1), GetFrameColor);
end;

procedure TdxCustomRibbon2013Skin.AdjustContextFont(AFont: TFont; AUseGlass: Boolean;
  AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited AdjustContextFont(AFont, AUseGlass, AContextColor, AColorSchemeAccent)
  else
    AFont.Color := TdxColorHelper.ChangeLightness(AContextColor, -0.2);
end;

procedure TdxCustomRibbon2013Skin.AdjustContextTabFont(AFont: TFont;
  AState: Integer; AContextColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited AdjustContextTabFont(AFont, AState, AContextColor, AColorSchemeAccent)
  else
    case AState of
      DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
        AFont.Color := TdxColorHelper.ChangeLightness(AContextColor, -0.2)
      else
        inherited AdjustContextTabFont(AFont, AState, AContextColor, AColorSchemeAccent);
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawContextBackground(DC: HDC; const R: TRect; AColor: TColor);
var
  R1: TRect;
begin
  if LowColors then
  begin
    inherited DrawContextBackground(DC, R, AColor);
    Exit;
  end;

  R1 := R;
  Inc(R1.Top);
  Inc(R1.Bottom);
  dxGpFillRect(DC, R1, AColor);
  Inc(R1.Top, 4);
  dxGpFillRect(DC, R1, clWhite, 200);
end;

procedure TdxCustomRibbon2013Skin.DrawContextBackgroundGlass(
  DC: HDC; const R: TRect; AContextColor: TColor);
var
  ABitmap: TcxBitmap32;
begin
  ABitmap := TcxBitmap32.CreateSize(R, True);
  try
    DrawContextBackground(ABitmap.Canvas.Handle, ABitmap.ClientRect, AContextColor);
    cxBitBlt(DC, ABitmap.Canvas.Handle, R, cxNullPoint, SRCCOPY);
  finally
    ABitmap.Free;
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawContextTabBackground(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AColor: TColor; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  R1: TRect;
begin
  if LowColors then
    inherited DrawContextTabBackground(DC, R, AState, AColor, AColorSchemeAccent)
  else
  begin
    R1 := cxRectSetHeight(R, cxRectHeight(R) - GetPartSize(DXBAR_TABSGROUPSOVERLAPHEIGHT));
    dxGpFillRect(DC, R1, AColor);
    dxGpFillRect(DC, R1, clWhite, 200);
    DrawTab(DC, R, AState, AColorSchemeAccent);
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawContextTabGroupsArea(
  DC: HDC; const R: TRect; AContextColor: TColor; AIsQATAtBottom, AIsInPopup: Boolean);
begin
  if LowColors then
    inherited DrawContextTabGroupsArea(DC, R, AContextColor, AIsQATAtBottom, AIsInPopup)
  else
    DrawTabGroupsArea(DC, R, AIsQATAtBottom, AIsInPopup);
end;

procedure TdxCustomRibbon2013Skin.DrawContextTabSeparator(
  DC: HDC; const R: TRect; ABeginGroup: Boolean);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawDropDownGalleryBackground(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawDropDownGalleryBackground(DC, R)
  else
    FillRectByColor(DC, R, clWhite);
end;

procedure TdxCustomRibbon2013Skin.DrawDropDownGalleryBottomSizingBand(DC: HDC; const R: TRect);
begin
  DrawDropDownGalleryBackground(DC, R);
end;

procedure TdxCustomRibbon2013Skin.DrawDropDownGalleryTopSizingBand(DC: HDC; const R: TRect);
begin
  DrawDropDownGalleryBackground(DC, R);
end;

procedure TdxCustomRibbon2013Skin.DrawGalleryFilterBandBackground(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawGalleryFilterBandBackground(DC, R)
  else
    FillRectByColor(DC, R, $E5E5E5);
end;

procedure TdxCustomRibbon2013Skin.DrawGalleryGroupHeaderBackground(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawGalleryGroupHeaderBackground(DC, R)
  else
    FillRectByColor(DC, R, $EEEEEE);
end;

procedure TdxCustomRibbon2013Skin.DrawInRibbonGalleryScrollBarButton(DC: HDC;
  const R: TRect; AButtonKind: TdxInRibbonGalleryScrollBarButtonKind; AState: Integer;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);

  function GetBorderColor(AState: Integer): TColor;
  begin
    case AState of
      DXBAR_HOT, DXBAR_PRESSED, DXBAR_DROPPEDDOWN:
        Result := GetHighlightBorderColor(AColorSchemeAccent)
      else
        Result := GetPartColor(DXBAR_EDIT_BORDER, AState, AColorSchemeAccent);
    end;
  end;

  function GetContentColor(AState: Integer): TColor;
  begin
    case AState of
      DXBAR_HOT:
        Result := GetHighlightContentColor(AColorSchemeAccent);
      DXBAR_PRESSED, DXBAR_DROPPEDDOWN:
        Result := GetHighlightBorderColor(AColorSchemeAccent);
      else
        Result := clNone;
    end;
  end;

const
  OuterBorders: array[TdxInRibbonGalleryScrollBarButtonKind] of TcxBorders = (
    [bTop, bRight], [bRight], [bBottom, bRight]
  );
var
  ASaveIndex: Integer;
  R1: TRect;
begin
  if LowColors then
    inherited DrawInRibbonGalleryScrollBarButton(DC, R, AButtonKind, AState, AColorSchemeAccent)
  else
  begin
    R1 := R;
    ASaveIndex := SaveDC(DC);
    try
      IntersectClipRect(DC, R.Left, R.Top, R.Right, R.Bottom);
      Inc(R1.Bottom, Ord(AButtonKind <> gsbkDropDown));
      DrawFrame(DC, R1, GetContentColor(AState), GetBorderColor(AState));
      DrawFrame(DC, R1, clNone, GetBorderColor(DXBAR_NORMAL), OuterBorders[AButtonKind]);
      DrawInRibbonGalleryScrollBarButtonGlyph(DC, R, AButtonKind, AState, AColorSchemeAccent);
    finally
      RestoreDC(DC, ASaveIndex);
    end;
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawEditButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawEditButton(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      DXBAR_HOT:
        FillRectByColor(DC, R, GetHighlightContentColor(AColorSchemeAccent));
      DXBAR_PRESSED, DXBAR_DROPPEDDOWN:
        FillRectByColor(DC, R, GetHighlightBorderColor(AColorSchemeAccent));
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawFormBorderIcon(DC: HDC; const R: TRect;
  AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  AlignmentMap: array[Boolean] of TAlignment = (taRightJustify, taCenter);
  BorderIconStateToBarState: array[TdxRibbonBorderIconState] of Integer = (
    DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED, DXBAR_NORMAL, DXBAR_HOT
  );
begin
  DrawEditButton(DC, R, BorderIconStateToBarState[AState], AColorSchemeAccent);
  InternalDrawFormBorderIconGlyph(DC, R, AIcon, AState,
    GetGlyphColor(BorderIconStateToBarState[AState], AColorSchemeAccent),
    AlignmentMap[AIcon <> rbdiAutoHideModeShowUI]);
end;

procedure TdxCustomRibbon2013Skin.DrawFormBorders(DC: HDC;
  const ABordersWidth: TRect; const AInfo: TdxRibbonFormInfo);
var
  ASaveIndex: Integer;
begin
  if LowColors then
    inherited DrawFormBorders(DC, ABordersWidth, AInfo)
  else
  begin
    ASaveIndex := SaveDC(DC);
    try
      ExcludeClipRect(DC, cxRectContent(AInfo.FormData.Bounds, ABordersWidth));
      FillRectByColor(DC, AInfo.FormData.Bounds,
        GetFormBorderColor(AInfo.FormData.Active, AInfo.ColorSchemeAccent));
    finally
      RestoreDC(DC, ASaveIndex)
    end;
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawFormCaption(
  DC: HDC; const R: TRect; const AInfo: TdxRibbonFormInfo);
const
  BordersMap: array[Boolean] of TcxBorders = ([bTop], cxBordersAll);
begin
  if LowColors then
    inherited DrawFormCaption(DC, R, AInfo)
  else
  begin
    DrawFrame(DC, R, GetCaptionAreaColor(AInfo.ApplicationMenuState),
      GetFormBorderColor(AInfo.FormData.Active, AInfo.ColorSchemeAccent),
      BordersMap[AInfo.FormData.State = wsMinimized]);
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawRibbonFormBackground(DC: HDC; const R: TRect; ARibbonHeight: Integer);
begin
  if LowColors then
    inherited DrawRibbonFormBackground(DC, R, ARibbonHeight)
  else
  begin
    DrawRibbonBackground(DC, cxRectSetHeight(R, ARibbonHeight));
    FillGradientRect(DC,
      cxRectSetBottom(R, R.Bottom, cxRectHeight(R) - ARibbonHeight),
      GetFormBackgroundColor1, GetFormBackgroundColor2, False);
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawSmallButton(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawSmallButton(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      DXBAR_HOT, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
        dxGpFillRect(DC, R, GetHighlightContentColor(AColorSchemeAccent));
      DXBAR_CHECKED, DXBAR_DROPPEDDOWN, DXBAR_PRESSED:
        dxGpFillRect(DC, R, GetHighlightBorderColor(AColorSchemeAccent));
      DXBAR_HOTCHECK:
        DrawFrame(DC, R,
          GetHighlightContentColor(AColorSchemeAccent),
          GetHighlightBorderColor(AColorSchemeAccent), cxBordersAll, 1, True);
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawSmallButtonDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawSmallButtonDropButtonArrowPart(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
        DrawFrame(DC, R, $FEFEFE, GetHighlightContentColor(AColorSchemeAccent), [bTop..bBottom], 1, True);
      else
        DrawSmallButton(DC, R, AState, AColorSchemeAccent);
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawSmallButtonDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawSmallButtonDropButtonMainPart(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
        DrawFrame(DC, R, $FEFEFE, GetHighlightContentColor(AColorSchemeAccent), [bLeft, bTop, bBottom], 1, True);
      else
        DrawSmallButton(DC, R, AState, AColorSchemeAccent);
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawLargeButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawLargeButton(DC, R, AState, AColorSchemeAccent)
  else
    DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawLargeButtonDropButtonArrowPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawLargeButtonDropButtonArrowPart(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
        DrawFrame(DC, R, clNone, GetHighlightContentColor(AColorSchemeAccent), [bLeft, bRight, bBottom]);
    else
      DrawLargeButton(DC, R, AState, AColorSchemeAccent);
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawLargeButtonDropButtonMainPart(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawLargeButtonDropButtonMainPart(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
        DrawFrame(DC, R, clNone, GetHighlightContentColor(AColorSchemeAccent), [bLeft, bTop, bRight]);
      DXBAR_NORMAL:
        begin
          DrawLargeButton(DC, R, AState, AColorSchemeAccent);
          DrawFrame(DC, cxRectInflate(R, -6, 0), clNone, $D4D4D4, [bBottom]);
        end;
    else
      DrawLargeButton(DC, R, AState, AColorSchemeAccent);
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawLaunchButtonBackground(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawLaunchButtonBackground(DC, R, AState, AColorSchemeAccent)
  else
    DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawLaunchButtonDefaultGlyph(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);

  procedure DoDrawGlyph(DC: HDC; R: TRect; AColor: TColor);
  begin
    R := cxRectCenter(R, 7, 7);
    DrawFrame(DC, cxRectInflate(R, 0, 0, -1, -1), clNone, AColor, [bLeft, bTop]);
    R := cxRect(R.Right - 4, R.Bottom - 4, R.Right, R.Bottom);
    DrawFrame(DC, R, clNone, AColor, [bRight, bBottom]);
    FillRectByColor(DC, cxRectSetSize(R, 1, 1), AColor);
    FillRectByColor(DC, cxRectInflate(R, -1, -1), AColor);
  end;

begin
  if LowColors then
    inherited DrawLaunchButtonDefaultGlyph(DC, R, AState, AColorSchemeAccent)
  else
    DoDrawGlyph(DC, R, GetGlyphColor(AState, AColorSchemeAccent));
end;

procedure TdxCustomRibbon2013Skin.DrawDropDownBorder(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawDropDownBorder(DC, R)
  else
    DrawFrame(DC, R, clWhite, $C6C6C6);
end;

procedure TdxCustomRibbon2013Skin.DrawMenuCheck(DC: HDC; const R: TRect;
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawMenuCheck(DC, R, AState, AColorSchemeAccent)
  else
    DrawFrame(DC, R,
      GetHighlightContentColor(AColorSchemeAccent),
      GetHighlightBorderColor(AColorSchemeAccent))
end;

procedure TdxCustomRibbon2013Skin.DrawMenuCheckMark(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
var
  APart: TdxSkinnedRect;
begin
  if LowColors then
    inherited DrawMenuCheckMark(DC, R, AState, AColorSchemeAccent)
  else
  begin
    APart := Parts[FMenuCheckMark[AState]];
    APart.Draw(DC, cxRectCenter(R, APart.Size));
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawMenuContent(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawMenuContent(DC, R)
  else
    FillRectByColor(DC, R, clWhite);
end;

procedure TdxCustomRibbon2013Skin.DrawMenuGlyph(DC: HDC; const R: TRect);
begin
  DrawMenuContent(DC, R);
end;

procedure TdxCustomRibbon2013Skin.DrawMenuSeparatorHorz(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawMenuSeparatorHorz(DC, R)
  else
    FillRectByColor(DC, cxRectCenterVertically(R, 1), $E5E2DF);
end;

procedure TdxCustomRibbon2013Skin.DrawMenuSeparatorVert(DC: HDC; const R: TRect);
begin
  DrawMenuContent(DC, R);
end;

procedure TdxCustomRibbon2013Skin.DrawQuickAccessToolbar(DC: HDC; const R: TRect;
  ABellow, ANonClientDraw, AHasApplicationButton, AIsActive, ADontUseAero: Boolean);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawQuickAccessToolbarGroupButton(DC: HDC;
  const R: TRect; ABellow, ANonClientDraw, AIsActive: Boolean; AState: Integer;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawSmallButton(DC, R, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawQuickAccessToolbarPopup(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawQuickAccessToolbarPopup(DC, R)
  else
    DrawFrame(DC, R, GetCaptionAreaColor(ramsHidden), $777777);
end;

procedure TdxCustomRibbon2013Skin.DrawGroupScrollButton(DC: HDC; const R: TRect;
  ALeft: Boolean; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);

  function GetBorderColor: TColor;
  begin
    case AState of
      DXBAR_HOT:
        Result := GetHighlightBorderColor(AColorSchemeAccent);
      DXBAR_PRESSED:
        Result := TdxColorHelper.ChangeLightness(GetHighlightBorderColor(AColorSchemeAccent), -0.1);
      else
        Result := GetFrameColor;
    end;
  end;

  function GetContentColor: TColor;
  begin
    case AState of
      DXBAR_HOT:
        Result := GetHighlightContentColor(AColorSchemeAccent);
      DXBAR_PRESSED:
        Result := GetHighlightBorderColor(AColorSchemeAccent);
      else
        Result := $FDFDFD;
    end;
  end;

begin
  if LowColors then
    inherited DrawGroupScrollButton(DC, R, ALeft, AState, AColorSchemeAccent)
  else
    DrawFrame(DC, R, GetContentColor, GetBorderColor);
end;

procedure TdxCustomRibbon2013Skin.DrawTabScrollButton(DC: HDC; const R: TRect;
  ALeft: Boolean; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawGroupScrollButton(DC, R, ALeft, AState, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawScrollBarBackground(DC: HDC;
  const R: TRect; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawScrollBarBackground(DC, R, AHorizontal, AColorSchemeAccent)
  else
    FillRectByColor(DC, R, GetScrollBarBackgroundColor);
end;

procedure TdxCustomRibbon2013Skin.DrawScrollBarPart(DC: HDC; const R: TRect;
  APart: TcxScrollBarPart; AState: Integer; AHorizontal: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawScrollBarPart(DC, R, APart, AState, AHorizontal, AColorSchemeAccent)
  else
  begin
    if APart in [sbpThumbnail, sbpLineUp, sbpLineDown] then
      DrawFrame(DC, R, GetScrollBarPartContentColor(APart, AState), GetScrollBarPartBorderColor(APart, AState));
    case APart of
      sbpLineUp:
        DrawPartCentered(DC, R, FScrollBarButtonLeftTopGlyph[AHorizontal]);
      sbpLineDown:
        DrawPartCentered(DC, R, FScrollBarButtonRightBottomGlyph[AHorizontal]);
    end;
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawScrollBoxSizeGripArea(DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  FillRectByColor(DC, R, clWhite);
end;

function TdxCustomRibbon2013Skin.GetScrollBarBackgroundColor: TColor;
begin
  Result := $F3F3F3;
end;

function TdxCustomRibbon2013Skin.GetScrollBarPartBorderColor(APart: TcxScrollBarPart; AState: Integer): TColor;
begin
  case AState of
    DXBAR_HOT, DXBAR_PRESSED:
      Result := $777777;
  else
    Result := $ABABAB;
  end;
end;

function TdxCustomRibbon2013Skin.GetScrollBarPartContentColor(APart: TcxScrollBarPart; AState: Integer): TColor;
begin
  Result := clWhite;
end;

procedure TdxCustomRibbon2013Skin.DrawSeparatorBackground(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawSeparatorBackground(DC, R)
  else
    FillRectByColor(DC, R, $EEEEEE);
end;

procedure TdxCustomRibbon2013Skin.DrawSeparatorLine(DC: HDC; const R: TRect);
begin
  DrawSeparatorBackground(DC, R);
end;

procedure TdxCustomRibbon2013Skin.DrawStatusBar(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawStatusBar(DC, R, AColorSchemeAccent)
  else
    FillRectByColor(DC, R, GetMenuBackgroundColor(AColorSchemeAccent));
end;

procedure TdxCustomRibbon2013Skin.DrawStatusBarGripBackground(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  DrawStatusBar(DC, R, AColorSchemeAccent);
end;

procedure TdxCustomRibbon2013Skin.DrawStatusBarSizeGrip(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawStatusBarPanelSeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawStatusBarToolbarSeparator(
  DC: HDC; const R: TRect; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  // do nothing
end;

procedure TdxCustomRibbon2013Skin.DrawTab(DC: HDC; const R: TRect;
  AState: TdxRibbonTabState; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawTab(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      rtsActive, rtsActiveHot:
        DrawFrame(DC, R, GetTabGroupsAreaContentColor, GetFrameColor, [bLeft..bRight], 1, True);
      rtsFocused:
        DrawFrame(DC, R,
          GetHighlightContentColor(AColorSchemeAccent),
          GetHighlightBorderColor(AColorSchemeAccent), [bLeft..bRight], 1, True);
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawTabGroupBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
begin
  if LowColors then
    inherited DrawTabGroupBackground(DC, R, AState, AIsInPopup)
  else
    if AIsInPopup then
      DrawFrame(DC, R, $FFFFFF, $C6C6C6, [bLeft..bRight])
    else
      FillRectByColor(DC, cxRectSetRight(R, R.Right, 1), GetFrameColor);
end;

procedure TdxCustomRibbon2013Skin.DrawTabGroupHeaderBackground(
  DC: HDC; const R: TRect; AState: Integer; AIsInPopup: Boolean);
var
  R1: TRect;
begin
  if LowColors then
    inherited DrawTabGroupHeaderBackground(DC, R, AState, AIsInPopup)
  else
    if AIsInPopup then
      DrawFrame(DC, R, $FFFFFF, $C6C6C6, [bLeft, bRight, bBottom])
    else
    begin
      R1 := cxRectSetRight(R, R.Right, 1);
      R1 := cxRectSetHeight(R1, cxRectHeight(R1) - 4);
      FillRectByColor(DC, R1, GetFrameColor);
    end;
end;

procedure TdxCustomRibbon2013Skin.DrawTabGroupsArea(
  DC: HDC; const R: TRect; AIsQATAtBottom, AIsInPopup: Boolean);
begin
  if LowColors then
    inherited DrawTabGroupsArea(DC, R, AIsQATAtBottom, AIsInPopup)
  else
  begin
    FillRectByColor(DC, cxRectSetHeight(R, 1), GetFrameColor);
    FillRectByColor(DC, cxRectSetBottom(R, R.Bottom, 1), GetFrameColor);
    FillRectByColor(DC, cxRectInflate(R, 0, -1), GetTabGroupsAreaContentColor);
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawMinimizeRibbonButtonGlyph(DC: HDC;
  const R: TRect; AState: TcxButtonState; AGlyph: TdxRibbonMinimizeButtonGlyph;
  AColorSchemeAccent: TdxRibbonColorSchemeAccent);
const
  StateMap: array[TcxButtonState] of Integer = (
    DXBAR_NORMAL, DXBAR_NORMAL, DXBAR_HOT, DXBAR_PRESSED, DXBAR_DISABLED
  );
var
  APart: TdxSkinnedRect;
begin
  if LowColors then
    inherited DrawMinimizeRibbonButtonGlyph(DC, R, AState, AGlyph, AColorSchemeAccent)
  else
  begin
    APart := Parts[FMinimizeRibbonButtonGlyph[AGlyph][AState = cxbsDisabled]];
    APart.DrawColored(DC, cxRectCenter(R, APart.Size), GetGlyphColor(StateMap[AState], AColorSchemeAccent));
  end;
end;

procedure TdxCustomRibbon2013Skin.DrawItemSeparator(DC: HDC; const R: TRect; AHorizontal: Boolean);
begin
  if LowColors then
    inherited DrawItemSeparator(DC, R, AHorizontal)
  else
    InternalDrawSeparator(DC, R, AHorizontal, GetFrameColor, clNone);
end;

procedure TdxCustomRibbon2013Skin.DrawKeyTip(DC: HDC; const R: TRect);
begin
  if LowColors then
    inherited DrawKeyTip(DC, R)
  else
    FillRectByColor(DC, R, $535353);
end;

function TdxCustomRibbon2013Skin.HasExternalRibbonFormShadow: Boolean;
begin
  Result := True;
end;

function TdxCustomRibbon2013Skin.GetPartContentOffsets(APart: Integer): TRect;
begin
  case APart of
    DXBAR_BACKSTAGEVIEW:
      Result := cxNullRect;
    DXBAR_BACKSTAGEVIEW_MENUBAR:
      Result := cxRect(0, 18, 0, 0);
    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM:
      Result := cxRect(16, 0, 0, 0);
    DXBAR_BACKSTAGEVIEW_MENUBAR_TAB:
      Result := cxRect(21, 11, 11, 11);
    DXBAR_TOOLBAR:
      Result := cxRect(2, 2, 2, 2);
    DXBAR_RIBBONTABGROUP, DXBAR_RIBBONCONTEXTTABGROUP:
      Result := cxRect(2, 2, 2, 3);
  else
    Result := inherited GetPartContentOffsets(APart);
  end;
end;

function TdxCustomRibbon2013Skin.GetPartSize(APart: Integer): Integer;
begin
  case APart of
    rspTabGroupBottomOffset:
      Result := 0;
    DXBAR_BACKSTAGEVIEW_BACKBUTTON:
      Result := 35;
    DXBAR_BACKSTAGEVIEW_MENUBAR_INDENTBETWEENITEMS:
      Result := 0;
    DXBAR_BACKSTAGEVIEW_MENUBAR_ITEM, DXBAR_BACKSTAGEVIEW_MENUBAR_TAB:
      Result := 38;
    DXBAR_BACKSTAGEVIEW_MENUBAR_SEPARATOR:
      Result := 23;
    DXBAR_BUTTONGROUPSPLITBUTTONSEPARATOR:
      Result := 0;
  else
    Result := inherited GetPartSize(APart);
  end;
end;

function TdxCustomRibbon2013Skin.GetWindowBordersWidth(AHasStatusBar: Boolean): TRect;
begin
  Result := Rect(1, 0, 1, 1);
end;

function TdxCustomRibbon2013Skin.UseRoundedWindowCorners: Boolean;
begin
  Result := False;
end;

procedure TdxCustomRibbon2013Skin.LoadCommonBackstageView(ABitmap: Pointer);
begin
  inherited LoadCommonBackstageView(ABitmap);
  LoadElementParts(ABitmap, FBackstageViewBackButton, cxRect(0, 0, 40, 40),
    rbvpBackstageViewBackButton, cxNullRect, [0, 1], [0, 1]);
end;

procedure TdxCustomRibbon2013Skin.LoadCommonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONCOMMON2013', AImage);
end;

procedure TdxCustomRibbon2013Skin.LoadRibbonFormBorderIcons(ABitmap: Pointer);
const
  OffsetMap: array[TdxBarMDIButton] of Integer = (15, 47, 0);
  PartIDMap: array[TdxBarMDIButton] of Integer = (
    rspMDIButtonMinimize, rspMDIButtonRestore, rspMDIButtonClose
  );
var
  AButton: TdxBarMDIButton;
begin
  LoadRibbonFormBorderIconsGlyphs(ABitmap, 147, 110, 15, 11);
  LoadElementParts(ABitmap, FBorderIcons, cxRectBounds(195, 37, 17, 17),
    rfspBorderIconBackground, DefaultFixedSize, [0, 1, 2], [0, 1, 2], True,
    InterpolationModeNearestNeighbor);
  LoadElementParts(ABitmap, FCloseButton, cxRectBounds(213, 37, 17, 17),
    rfspCloseButtonHot, DefaultFixedSize, [0, 1, 2], [0, 1, 2], True,
    InterpolationModeNearestNeighbor);
  LoadElementParts(ABitmap, FMinimizeRibbonButtonGlyph[rmbMinimize],
    cxRectBounds(195, 89, 9, 7), rspMinimizeRibbonButtonMinimize,
    cxNullRect, [0, 1], [0, 1], True, InterpolationModeNearestNeighbor);
  LoadElementParts(ABitmap, FMinimizeRibbonButtonGlyph[rmbRestore],
    cxRectBounds(204, 89, 9, 7), rspMinimizeRibbonButtonRestore,
    cxNullRect, [0, 1], [0, 1], True, InterpolationModeNearestNeighbor);
  LoadElementParts(ABitmap, FMinimizeRibbonButtonGlyph[rmbPin],
    cxRectBounds(213, 89, 12, 9), rspMinimizeRibbonButtonPin,
    cxNullRect, [0, 1], [0, 1], True, InterpolationModeNearestNeighbor);
  for AButton := Low(AButton) to High(AButton) do
  begin
    LoadElementParts(ABitmap, FMDIButtonGlyphs[AButton],
      cxRectBounds(131 + OffsetMap[AButton], 109, 15, 11), PartIDMap[AButton],
      cxNullRect, [0, 1, 2, 3], [0, 1, 2, 3], True, InterpolationModeNearestNeighbor);
  end;
end;

procedure TdxCustomRibbon2013Skin.LoadRibbonTexturesSet(AImage: TdxGPImage);
begin
  LoadBitmapFromStream('RIBBONALL2013', AImage);
end;

function TdxCustomRibbon2013Skin.GetAccentColor(
  AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
const
  ColorMap: array[TdxRibbonColorSchemeAccent] of TColor = (
    $3EA5EA, $9A572B, $457220, $2647D2, $7B3880
  );
begin
  Result := ColorMap[AColorSchemeAccent];
end;

function TdxCustomRibbon2013Skin.GetAccentColor(
  AColorSchemeAccent: TdxRibbonColorSchemeAccent; const ALightnessDelta: Double): TColor;
begin
  Result := TdxColorHelper.ChangeLightness(GetAccentColor(AColorSchemeAccent), ALightnessDelta);
end;

function TdxCustomRibbon2013Skin.GetCaptionAreaColor(
  AApplicationMenuState: TdxRibbonApplicationMenuState): TColor;
begin
  if AApplicationMenuState = ramsShownAsFullScreenFrame then
    Result := clWhite
  else
    Result := GetMasterColor;
end;

function TdxCustomRibbon2013Skin.GetFormBackgroundColor1: TColor;
begin
  Result := GetMasterColor;
end;

function TdxCustomRibbon2013Skin.GetFormBackgroundColor2: TColor;
begin
  Result := GetFormBackgroundColor1;
end;

function TdxCustomRibbon2013Skin.GetFormBorderColor(
  AActive: Boolean; AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
begin
  if AActive then
    Result := GetMenuBackgroundColor(AColorSchemeAccent)
  else
    Result := $848484;
end;

function TdxCustomRibbon2013Skin.GetFrameColor: TColor;
begin
  Result := $C6C6C6;
end;

function TdxCustomRibbon2013Skin.GetGlyphColor(
  AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
begin
  case AState of
    DXBAR_HOT:
      Result := TdxColorHelper.ChangeLightness(GetHighlightBorderColor(AColorSchemeAccent), -0.3);
    DXBAR_PRESSED:
      Result := TdxColorHelper.ChangeLightness(GetHighlightBorderColor(AColorSchemeAccent), -0.4);
    else
      Result := $777777;
  end;
end;

function TdxCustomRibbon2013Skin.GetHighlightBorderColor(
  AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
const
  ColorMap: array[TdxRibbonColorSchemeAccent] of TColor = (
    $9CD0F4, $E2BCA2, $A0BF86, $9CB9F4, $DEBFE0
  );
begin
  Result := ColorMap[AColorSchemeAccent];
end;

function TdxCustomRibbon2013Skin.GetHighlightContentColor(
  AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
const
  ColorMap: array[TdxRibbonColorSchemeAccent] of TColor = (
    $C8E3FD, $F2E1D5, $E0F0D3, $DDE5FD, $EEDAF0
  );
begin
  Result := ColorMap[AColorSchemeAccent];
end;

function TdxCustomRibbon2013Skin.GetMenuBackgroundColor(
  AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
begin
  Result := GetAccentColor(AColorSchemeAccent);
end;

function TdxCustomRibbon2013Skin.GetMenuBackgroundColor(
  AColorSchemeAccent: TdxRibbonColorSchemeAccent; const ALightnessDelta: Double): TColor;
begin
  Result := TdxColorHelper.ChangeLightness(GetMenuBackgroundColor(AColorSchemeAccent), ALightnessDelta);
end;

function TdxCustomRibbon2013Skin.GetStyle: TdxRibbonStyle;
begin
  Result := rs2013;
end;

{ TdxLightGrayRibbon2013Skin }

function TdxLightGrayRibbon2013Skin.GetScrollBarBackgroundColor: TColor;
begin
  Result := $E6E6E6;
end;

function TdxLightGrayRibbon2013Skin.GetScrollBarPartContentColor(APart: TcxScrollBarPart; AState: Integer): TColor;
begin
  if AState = DXBAR_PRESSED then
    Result := $E1E1E1
  else
    Result := clWhite;
end;

function TdxLightGrayRibbon2013Skin.GetName: string;
begin
  Result := 'LightGray';
end;

function TdxLightGrayRibbon2013Skin.GetFormBackgroundColor2: TColor;
begin
  Result := $E8E8E8;
end;

function TdxLightGrayRibbon2013Skin.GetMasterColor: TColor;
begin
  Result := $F6F6F6;
end;

function TdxLightGrayRibbon2013Skin.GetMenuBackgroundColor(
  AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
begin
  Result := GetAccentColor(AColorSchemeAccent, -0.05);
end;

function TdxLightGrayRibbon2013Skin.GetTabGroupsAreaContentColor: TColor;
begin
  Result := $FCFCFC;
end;

{ TdxDarkGrayRibbon2013Skin }

procedure TdxDarkGrayRibbon2013Skin.DrawBackstageViewTabButton(DC: HDC;
  const R: TRect; AState: Integer; AColorSchemeAccent: TdxRibbonColorSchemeAccent);
begin
  if LowColors then
    inherited DrawBackstageViewTabButton(DC, R, AState, AColorSchemeAccent)
  else
    case AState of
      DXBAR_PRESSED, DXBAR_HOT, DXBAR_HOTCHECK, DXBAR_ACTIVE, DXBAR_ACTIVEDISABLED:
        FillRectByColor(DC, R, GetAccentColor(AColorSchemeAccent, -0.1));
      DXBAR_CHECKED:
        FillRectByColor(DC, R, GetAccentColor(AColorSchemeAccent, 0.1));
    end;
end;

function TdxDarkGrayRibbon2013Skin.GetScrollBarBackgroundColor: TColor;
begin
  Result := $D6D6D6;
end;

function TdxDarkGrayRibbon2013Skin.GetScrollBarPartContentColor(APart: TcxScrollBarPart; AState: Integer): TColor;
begin
  if AState <> DXBAR_PRESSED then
    Result := clWhite
  else
    if APart = sbpThumbnail then
      Result := $E1E1E1
    else
      Result := $F0F0F0;
end;

function TdxDarkGrayRibbon2013Skin.GetName: string;
begin
  Result := 'DarkGray';
end;

function TdxDarkGrayRibbon2013Skin.GetFormBackgroundColor2: TColor;
begin
  Result := $C1C1C1;
end;

function TdxDarkGrayRibbon2013Skin.GetFrameColor: TColor;
begin
  Result := $ABABAB;
end;

function TdxDarkGrayRibbon2013Skin.GetMasterColor: TColor;
begin
  Result := $E5E5E5;
end;

function TdxDarkGrayRibbon2013Skin.GetMenuBackgroundColor(AColorSchemeAccent: TdxRibbonColorSchemeAccent): TColor;
begin
  Result := $333333;
end;

function TdxDarkGrayRibbon2013Skin.GetTabGroupsAreaContentColor: TColor;
begin
  Result := $F3F3F3;
end;

{ TdxWhiteRibbon2013Skin }

function TdxWhiteRibbon2013Skin.GetScrollBarPartBorderColor(APart: TcxScrollBarPart; AState: Integer): TColor;
begin
  if APart <> sbpThumbnail then
    Result := inherited GetScrollBarPartBorderColor(APart, AState)
  else
    if AState = DXBAR_PRESSED then
      Result := $777777
    else
      Result := $ABABAB;
end;

function TdxWhiteRibbon2013Skin.GetScrollBarPartContentColor(APart: TcxScrollBarPart; AState: Integer): TColor;
begin
  Result := clWhite;
  case AState of
    DXBAR_PRESSED:
      Result := $F0F0F0;
    DXBAR_HOT:
      if APart = sbpThumbnail then
        Result := $F0F0F0;
  end;
end;

function TdxWhiteRibbon2013Skin.GetName: string;
begin
  Result := 'White';
end;

function TdxWhiteRibbon2013Skin.GetFormBackgroundColor2: TColor;
begin
  Result := $FFFFFF;
end;

function TdxWhiteRibbon2013Skin.GetMasterColor: TColor;
begin
  Result := $FFFFFF;
end;

function TdxWhiteRibbon2013Skin.GetTabGroupsAreaContentColor: TColor;
begin
  Result := clWhite;
end;

{ TdxRibbonSkinsManager }

constructor TdxRibbonSkinsManager.Create;
begin
  inherited Create;
  FList := TcxObjectList.Create;
end;

destructor TdxRibbonSkinsManager.Destroy;
begin
  FreeAndNil(FList);
  inherited Destroy;
end;

function TdxRibbonSkinsManager.Add(ASkin: TdxCustomRibbonSkin): Integer;
begin
  Result := -1;
  if CheckGdiPlus then
  begin
    if (ASkin <> nil) and (Find(ASkin.Name, ASkin.Style) = nil) then
    begin
      Result := FList.Add(ASkin);
      Changed;
    end;
  end
end;

function TdxRibbonSkinsManager.Find(const AName: string; AStyle: TdxRibbonStyle): TdxCustomRibbonSkin;
var
  ASkin: TdxCustomRibbonSkin;
  I: Integer;
begin
  Result := nil;
  for I := 0 to SkinCount - 1 do
  begin
    ASkin := Skins[I];
    if SameText(ASkin.Name, AName) and (ASkin.Style = AStyle) then
    begin
      Result := ASkin;
      Break;
    end;
  end;
end;

function TdxRibbonSkinsManager.Remove(ASkin: TdxCustomRibbonSkin): Boolean;
begin
  Result := FList.FreeAndRemove(ASkin) >= 0;
  if Result then
    Changed;
end;

procedure TdxRibbonSkinsManager.Changed;
begin
  // do nothing
end;

function TdxRibbonSkinsManager.GetSkin(Index: Integer): TdxCustomRibbonSkin;
begin
  Result := TdxCustomRibbonSkin(FList[Index]);
end;

function TdxRibbonSkinsManager.GetSkinCount: Integer;
begin
  Result := FList.Count;
end;

//

procedure CreateSkins;
begin
  if not CheckGdiPlus(True) then Exit;

  dxRibbonSkinsManager.Add(TdxBlueRibbonSkin.Create);
  dxRibbonSkinsManager.Add(TdxBlackRibbonSkin.Create);
  dxRibbonSkinsManager.Add(TdxSilverRibbonSkin.Create);

  dxRibbonSkinsManager.Add(TdxBlueRibbon2010Skin.Create);
  dxRibbonSkinsManager.Add(TdxSilverRibbon2010Skin.Create);
  dxRibbonSkinsManager.Add(TdxBlackRibbon2010Skin.Create);

  dxRibbonSkinsManager.Add(TdxWhiteRibbon2013Skin.Create);
  dxRibbonSkinsManager.Add(TdxLightGrayRibbon2013Skin.Create);
  dxRibbonSkinsManager.Add(TdxDarkGrayRibbon2013Skin.Create);
end;

procedure DestroySkins;
begin
  FreeAndNil(FSkinsManager);
end;

initialization
  dxUnitsLoader.AddUnit(@CreateSkins, @DestroySkins);

finalization
  dxUnitsLoader.RemoveUnit(@DestroySkins);
end.




