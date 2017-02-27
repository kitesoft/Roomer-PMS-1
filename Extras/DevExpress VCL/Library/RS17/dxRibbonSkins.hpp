// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonSkins.pas' rev: 24.00 (Win32)

#ifndef DxribbonskinsHPP
#define DxribbonskinsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxBarSkin.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarSkinConsts.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxScreenTip.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonskins
{
//-- type declarations -------------------------------------------------------
enum TdxInRibbonGalleryScrollBarButtonKind : unsigned char { gsbkLineUp, gsbkLineDown, gsbkDropDown };

enum TdxRibbonApplicationButtonState : unsigned char { rabsNormal, rabsHot, rabsPressed };

enum TdxRibbonApplicationMenuState : unsigned char { ramsHidden, ramsShownAsMenu, ramsShownAsFrame, ramsShownAsFullScreenFrame };

enum TdxRibbonColorSchemeAccent : unsigned char { rcsaYellow, rcsaBlue, rcsaGreen, rcsaOrange, rcsaPurple };

enum TdxRibbonMinimizeButtonGlyph : unsigned char { rmbMinimize, rmbRestore, rmbPin };

enum TdxRibbonStyle : unsigned char { rs2007, rs2010, rs2013 };

enum TdxRibbonTabState : unsigned char { rtsNormal, rtsHot, rtsActive, rtsActiveHot, rtsFocused };

enum TdxRibbonBorderIcon : unsigned char { rbiSystemMenu, rbiMinimize, rbiMaximize, rbiHelp, rbiAutoHide, rbiAutoHideModeShowUI };

typedef System::Set<TdxRibbonBorderIcon, TdxRibbonBorderIcon::rbiSystemMenu, TdxRibbonBorderIcon::rbiAutoHideModeShowUI>  TdxRibbonBorderIcons;

enum TdxRibbonBorderIconState : unsigned char { rbisNormal, rbisHot, rbisPressed, rbisInactive, rbisHotInactive };

enum TdxRibbonBorderDrawIcon : unsigned char { rbdiMinimize, rbdiMaximize, rbdiRestore, rbdiClose, rbdiHelp, rbdiAutoHide, rbdiAutoHideModeShowUI };

struct DECLSPEC_DRECORD TdxRibbonFormData
{
public:
	bool Active;
	System::Types::TRect Bounds;
	Vcl::Forms::TFormBorderStyle Border;
	TdxRibbonBorderIcons BorderIcons;
	HWND Handle;
	System::Uitypes::TWindowState State;
	Vcl::Forms::TFormStyle Style;
	bool DontUseAero;
	bool UseRoundedWindowCorners;
};


struct DECLSPEC_DRECORD TdxRibbonFormInfo
{
public:
	TdxRibbonApplicationMenuState ApplicationMenuState;
	int CaptionAreaExtention;
	int CaptionHeight;
	TdxRibbonColorSchemeAccent ColorSchemeAccent;
	TdxRibbonFormData FormData;
	bool HasStatusBar;
	bool IsRibbonHidden;
	int TabsHeight;
	int RibbonHeight;
};


typedef System::StaticArray<int, 2> TTwoStateArray;

typedef System::StaticArray<int, 3> TThreeStateArray;

typedef System::StaticArray<int, 4> TFourStateArray;

typedef System::StaticArray<int, 9> TStatesArray;

class DELPHICLASS TdxCustomRibbonSkin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomRibbonSkin : public Dxbarskin::TdxCustomBarSkin
{
	typedef Dxbarskin::TdxCustomBarSkin inherited;
	
private:
	int FReferenceCount;
	bool FLowColors;
	
protected:
	int FApplicationMenuBorder;
	int FApplicationMenuButton;
	int FApplicationMenuContentFooter;
	int FApplicationMenuContentHeader;
	TStatesArray FButtonGroup;
	int FDropDownBorder;
	int FDropDownGalleryBottomSizeGrip;
	int FDropDownGalleryTopSizeGrip;
	int FDropDownGalleryVerticalSizeGrip;
	TStatesArray FEditButtons;
	int FHelpButton;
	TStatesArray FLaunchButtonDefaultGlyphs;
	TStatesArray FMarkTruncated;
	int FMenuContent;
	int FMenuGlyph;
	int FMenuMark;
	int FMenuSeparatorHorz;
	int FMenuSeparatorVert;
	TTwoStateArray FPinButtonGlyphs;
	int FProgressSubstrate;
	int FQATAtBottom;
	System::StaticArray<System::StaticArray<int, 2>, 2> FQATAtTopLeft;
	TTwoStateArray FQATAtTopRight;
	System::StaticArray<int, 2> FQATGlassAtTopLeft;
	int FQATGlassAtTopRight;
	TStatesArray FQATGroupButtonActive;
	TStatesArray FQATGroupButtonInactive;
	int FScreenTip;
	int FScrollArrow;
	int FTabSeparator;
	void __fastcall AddTwoStateElement(void * ABitmap, void *AParts, const System::Types::TRect &R, const System::Types::TRect &F, int ID, int AInterpolationMode = 0x5);
	void __fastcall InternalDrawSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2);
	virtual void __fastcall LoadCommonElements(void * ABitmap);
	virtual void __fastcall LoadCommonMenu(void * ABitmap);
	virtual void __fastcall LoadRibbonButtons(void * ABitmap);
	virtual void __fastcall LoadRibbonElements(void * ABitmap);
	virtual void __fastcall LoadRibbonForm(void * ABitmap);
	virtual void __fastcall LoadRibbonGallery(void * ABitmap);
	virtual void __fastcall LoadRibbonMenu(void * ABitmap);
	virtual void __fastcall LoadRibbonQAT(void * ABitmap);
	virtual void __fastcall LoadRibbonTab(void * ABitmap);
	virtual void __fastcall LoadCommonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage) = 0 ;
	void __fastcall LoadSkin(void);
	virtual TdxRibbonStyle __fastcall GetStyle(void);
	void __fastcall DrawArrow(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxArrowDirection AArrowDirection, int AState);
	void __fastcall DrawDropDownGalleryVerticalSizeGrip(HDC DC, const System::Types::TRect &R);
	void __fastcall DrawPart(HDC DC, const System::Types::TRect &R, int AState)/* overload */;
	void __fastcall DrawPart(int const *AParts, HDC DC, const System::Types::TRect &R, int AState)/* overload */;
	void __fastcall DrawPartCentered(HDC DC, const System::Types::TRect &R, int APartIndex);
	virtual void __fastcall DrawTabsAreaButton(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall GetApplicationMenuContentColors(System::Uitypes::TColor &AInnerBorderColor, System::Uitypes::TColor &AOuterBorderColor, System::Uitypes::TColor &ASideColor);
	__property bool LowColors = {read=FLowColors, write=FLowColors, nodefault};
	
public:
	__fastcall TdxCustomRibbonSkin(void);
	void __fastcall AddReference(void);
	void __fastcall RemoveReference(void);
	void __fastcall LoadBitmapFromStream(const System::UnicodeString AResName, Dxgdiplusclasses::TdxGPImage* AImage);
	void __fastcall LoadElementParts(void * ABitmap, void *AParts, const System::Types::TRect &R, int AID, const System::Types::TRect &AFixedSize, System::Byte const *AImageIndexes, const int AImageIndexes_Size, const Dxbar::TdxByteSet &APossibleStates, bool AIsTopDown = true, int AInterpolationMode = 0x0);
	void __fastcall LoadElementPartsFromFile(const System::UnicodeString AFileName, void *AParts, int AID, const System::Types::TRect &AFixedSize, System::Byte const *AImageIndexes, const int AImageIndexes_Size, const Dxbar::TdxByteSet &APossibleStates);
	void __fastcall LoadFourStateArray(void * ABitmap, const System::Types::TRect &R, const System::Types::TRect &Fixed, int *AStateArray, int AStartID, bool AIsVerticalLayout = true, int AInterpolationMode = 0x0);
	void __fastcall LoadThreeStateArray(void * ABitmap, const System::Types::TRect &R, const System::Types::TRect &Fixed, int *AStateArray, int AStartID, bool AIsVerticalLayout = true, int AInterpolationMode = 0x0);
	virtual void __fastcall DrawApplicationButton(HDC DC, const System::Types::TRect &R, TdxRibbonApplicationButtonState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuBackground(HDC DC, const System::Types::TRect &R, const System::Types::TRect &AContentRect, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuExtraPaneButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuExtraPanePinButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuExtraPanePinButtonGlyph(HDC DC, const System::Types::TRect &R, int AState, bool AChecked, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Types::TRect __fastcall GetApplicationMenuContentOffset(const System::Types::TRect &ATabsBounds);
	virtual System::Types::TSize __fastcall GetApplicationMenuGlyphSize(void);
	virtual System::Uitypes::TColor __fastcall GetApplicationMenuTextColor(TdxRibbonApplicationButtonState AState);
	virtual void __fastcall DrawButtonGroup(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupBorderLeft(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupBorderMiddle(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawButtonGroupBorderRight(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupSplitButtonSeparator(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawCollapsedToolbarBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawCollapsedToolbarGlyphBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawDropDownGalleryBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryBottomSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryBottomSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryBottomVerticalSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryTopSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryTopSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryTopVerticalSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawEditArrowButton(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawEditButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawEditEllipsisButton(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawEditSpinDownButton(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawEditSpinUpButton(HDC DC, const System::Types::TRect &R, int AState);
	virtual int __fastcall AdjustCaptionFontSize(int ASize, bool AUseAeroGlass);
	virtual void __fastcall AdjustRibbonFormBorderIconSize(TdxRibbonBorderDrawIcon AIcon, bool AIsToolWindow, System::Types::TSize &ASize);
	virtual bool __fastcall ExtendCaptionAreaOnTabs(void);
	virtual void __fastcall DrawFormBorderIcon(HDC DC, const System::Types::TRect &R, TdxRibbonBorderDrawIcon AIcon, TdxRibbonBorderIconState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawFormBorders(HDC DC, const System::Types::TRect &ABordersWidth, const TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormCaption(HDC DC, const System::Types::TRect &R, const TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormStatusBarPart(HDC DC, const System::Types::TRect &R, bool AIsLeft, bool AIsActive, bool AIsRaised, bool AIsRectangular, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Types::TRect __fastcall GetWindowBordersWidth(bool AHasStatusBar);
	virtual bool __fastcall HasExternalRibbonFormShadow(void);
	virtual bool __fastcall UseRoundedWindowCorners(void);
	virtual void __fastcall DrawHelpButton(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawHelpButtonGlyph(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawInRibbonGalleryBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawInRibbonGalleryScrollBarBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawInRibbonGalleryScrollBarButton(HDC DC, const System::Types::TRect &R, TdxInRibbonGalleryScrollBarButtonKind AButtonKind, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawInRibbonGalleryScrollBarButtonGlyph(HDC DC, const System::Types::TRect &R, TdxInRibbonGalleryScrollBarButtonKind AButtonKind, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButtonDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButtonDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLaunchButtonBackground(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLaunchButtonDefaultGlyph(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMDIButton(HDC DC, const System::Types::TRect &R, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMDIButtonGlyph(HDC DC, const System::Types::TRect &R, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawMenuArrowDown(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuArrowRight(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuCheck(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuCheckMark(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuContent(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuDetachCaption(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawMenuExtraSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawMenuGlyph(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuItem(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuItemDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuItemDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuMark(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuScrollArea(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawMenuSeparatorHorz(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuSeparatorVert(HDC DC, const System::Types::TRect &R);
	virtual int __fastcall GetMenuSeparatorSize(void);
	virtual void __fastcall DrawMinimizeRibbonButton(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, bool AMinimized, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMinimizeRibbonButtonGlyph(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, TdxRibbonMinimizeButtonGlyph AGlyph, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawProgressDiscreteBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawProgressSolidBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawProgressSubstrate(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawSmallButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButtonDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButtonDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewBackButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewBackground(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuBackground(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewTabButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuHeader(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuSeparator(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewGalleryBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawBackstageViewGalleryGroupHeader(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawBackstageViewGalleryItem(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewGalleryItemPinButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewGalleryItemPinButtonGlyph(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewGalleryItemPinTag(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewGallerySeparator(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMarkArrow(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawMarkTruncated(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawTab(HDC DC, const System::Types::TRect &R, TdxRibbonTabState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTabAreaBackground(HDC DC, const System::Types::TRect &R, bool AActive, bool AUseAeroGlass, TdxRibbonApplicationMenuState AApplicationMenuState);
	virtual void __fastcall DrawTabGroupBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupHeaderBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupsArea(HDC DC, const System::Types::TRect &R, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawTabScrollButton(HDC DC, const System::Types::TRect &R, bool ALeft, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTabSeparator(HDC DC, const System::Types::TRect &R, System::Byte Alpha);
	virtual void __fastcall AdjustContextFont(Vcl::Graphics::TFont* AFont, bool AUseGlass, System::Uitypes::TColor AContextColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall AdjustContextTabFont(Vcl::Graphics::TFont* AFont, int AState, System::Uitypes::TColor AContextColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextBackground(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AContextColor);
	virtual void __fastcall DrawContextBackgroundGlass(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AContextColor);
	virtual void __fastcall DrawContextTabBackground(HDC DC, const System::Types::TRect &R, TdxRibbonTabState AState, System::Uitypes::TColor AContextColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextTabGroupsArea(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AContextColor, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawContextTabSeparator(HDC DC, const System::Types::TRect &R, bool ABeginGroup);
	virtual void __fastcall AdjustQuickAccessToolbarVertical(System::Types::TRect &ABounds, bool ANonClientDraw, bool ADontUseAero);
	virtual void __fastcall DrawQuickAccessToolbar(HDC DC, const System::Types::TRect &R, bool ABellow, bool ANonClientDraw, bool AHasApplicationButton, bool AIsActive, bool ADontUseAero);
	virtual void __fastcall DrawQuickAccessToolbarDefaultGlyph(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawQuickAccessToolbarGroupButton(HDC DC, const System::Types::TRect &R, bool ABellow, bool ANonClientDraw, bool AIsActive, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawQuickAccessToolbarPopup(HDC DC, const System::Types::TRect &R);
	virtual int __fastcall GetQuickAccessToolbarLeftIndent(bool AHasApplicationButton, bool AUseAeroGlass);
	virtual int __fastcall GetQuickAccessToolbarMarkButtonOffset(bool AHasApplicationButton, bool ABelow);
	virtual int __fastcall GetQuickAccessToolbarOverrideWidth(bool AHasApplicationButton, bool AUseAeroGlass);
	virtual int __fastcall GetQuickAccessToolbarRightIndent(bool AHasApplicationButton);
	virtual void __fastcall DrawStatusBar(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarGripBackground(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarPanel(HDC DC, const System::Types::TRect &Bounds, const System::Types::TRect &R, bool AIsLowered, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarPanelSeparator(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarSizeGrip(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarToolbarSeparator(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual int __fastcall GetStatusBarSeparatorSize(void);
	virtual void __fastcall DrawScrollBarBackground(HDC DC, const System::Types::TRect &R, bool AHorizontal, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawScrollBarPart(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, int AState, bool AHorizontal, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawScrollBoxSizeGripArea(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetScrollBarPainter(void);
	virtual void __fastcall DrawGroupScrollButton(HDC DC, const System::Types::TRect &R, bool ALeft, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual bool __fastcall NeedDrawGroupScrollArrow(void);
	virtual void __fastcall DrawArrowDown(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawDropDownBorder(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGalleryFilterBandBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGalleryGroupHeaderBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawItemSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawKeyTip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMiniToolbarBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawRibbonBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawRibbonClientTopArea(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawRibbonFormBackground(HDC DC, const System::Types::TRect &R, int ARibbonHeight);
	virtual void __fastcall DrawRibbonTopFrameArea(HDC DC, const System::Types::TRect &R, bool AUseAeroGlass);
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawScreenTip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawScrollArrow(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawSeparatorBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawSeparatorLine(HDC DC, const System::Types::TRect &R);
	virtual bool __fastcall GetIsAlphaUsed(int APart);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
	virtual System::Types::TRect __fastcall GetPartContentOffsets(int APart);
	virtual int __fastcall GetPartSize(int APart);
	virtual System::UnicodeString __fastcall GetSkinName(void);
	void __fastcall UpdateBitsPerPixel(void);
	__property TdxRibbonStyle Style = {read=GetStyle, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxCustomRibbonSkin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomRibbonTexturedSkin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomRibbonTexturedSkin : public TdxCustomRibbonSkin
{
	typedef TdxCustomRibbonSkin inherited;
	
private:
	System::StaticArray<System::StaticArray<int, 3>, 5> FApplicationButton;
	TStatesArray FArrowsDown;
	System::StaticArray<System::StaticArray<int, 4>, 7> FBorderIconGlyph;
	TThreeStateArray FBorderIcons;
	System::StaticArray<System::StaticArray<int, 2>, 2> FBottomBorderThick;
	TTwoStateArray FBottomBorderThin;
	int FButtonGroupBorderLeft;
	TStatesArray FButtonGroupBorderMiddle;
	int FButtonGroupBorderRight;
	TStatesArray FButtonGroupSplitButtonSeparator;
	TTwoStateArray FCaption;
	TTwoStateArray FCaptionLeftBorder;
	TTwoStateArray FCaptionRightBorder;
	TTwoStateArray FCaptionZoomed;
	TStatesArray FCollapsedToolbarGlyphBackgrounds;
	TStatesArray FCollapsedToolbars;
	int FContextBackground;
	int FContextBackgroundGlass;
	TTwoStateArray FContextTabGroupsArea;
	System::StaticArray<int, 5> FContextTabIndex;
	TTwoStateArray FContextTabSeparator;
	int FDropDownGalleryBottomSizingBand;
	int FDropDownGalleryTopSizingBand;
	System::StaticArray<System::StaticArray<int, 4>, 2> FFormStatusBarLeftParts;
	System::StaticArray<System::StaticArray<int, 4>, 2> FFormStatusBarRightParts;
	int FGalleryFilterBand;
	int FGalleryGroupHeader;
	System::StaticArray<System::StaticArray<int, 3>, 2> FGroupScrollButtons;
	TStatesArray FInRibbonGalleryScrollBarDropDownButton;
	TStatesArray FInRibbonGalleryScrollBarDropDownButtonGlyph;
	TStatesArray FInRibbonGalleryScrollBarLineDownButton;
	TStatesArray FInRibbonGalleryScrollBarLineDownButtonGlyph;
	TStatesArray FInRibbonGalleryScrollBarLineUpButton;
	TStatesArray FInRibbonGalleryScrollBarLineUpButtonGlyph;
	TStatesArray FLargeButtonDropButtons;
	TStatesArray FLargeButtonGlyphBackgrounds;
	TStatesArray FLargeButtons;
	TStatesArray FLaunchButtonBackgrounds;
	TTwoStateArray FLeftBorder;
	TStatesArray FMarkArrow;
	int FMenuArrowDown;
	int FMenuArrowRight;
	TStatesArray FMenuCheck;
	TStatesArray FMenuCheckMark;
	TStatesArray FMenuDetachCaption;
	TStatesArray FMenuScrollArea;
	int FProgressDiscreteBand;
	int FProgressSolidBand;
	int FQATDefaultGlyph;
	int FQATPopup;
	int FRibbonTopArea;
	TTwoStateArray FRightBorder;
	TStatesArray FSmallButtonDropButtons;
	TStatesArray FSmallButtonGlyphBackgrounds;
	TStatesArray FSmallButtons;
	System::StaticArray<System::StaticArray<int, 4>, 2> FScrollBarBackground;
	System::StaticArray<System::StaticArray<int, 4>, 2> FScrollBarButtonRightBottom;
	System::StaticArray<int, 2> FScrollBarButtonRightBottomGlyph;
	System::StaticArray<System::StaticArray<int, 4>, 2> FScrollBarButtonLeftTop;
	System::StaticArray<int, 2> FScrollBarButtonLeftTopGlyph;
	System::StaticArray<System::StaticArray<int, 4>, 2> FScrollBarThumb;
	System::StaticArray<int, 2> FScrollBarThumbGlyph;
	int FStatusBar;
	int FStatusBarGripBackground;
	int FStatusBarPanel;
	int FStatusBarPanelLowered;
	int FStatusBarPanelRaised;
	int FStatusBarPanelSeparator;
	int FStatusBarToolbarSeparator;
	TThreeStateArray FTabGroupsArea;
	System::StaticArray<int, 5> FTabIndex;
	System::StaticArray<System::StaticArray<int, 3>, 2> FTabScrollButtons;
	TStatesArray FToolbar;
	TStatesArray FToolbarHeader;
	
protected:
	void __fastcall InternalDrawFormBorderIconGlyph(HDC DC, const System::Types::TRect &R, TdxRibbonBorderDrawIcon AIcon, TdxRibbonBorderIconState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Classes::TAlignment AAlignment = (System::Classes::TAlignment)(0x2));
	void __fastcall LoadCommonButtons(void * ABitmap);
	virtual void __fastcall LoadCommonElements(void * ABitmap);
	virtual void __fastcall LoadCommonMenu(void * ABitmap);
	virtual void __fastcall LoadRibbonApplicationButton(void * ABitmap);
	virtual void __fastcall LoadRibbonButtons(void * ABitmap);
	virtual void __fastcall LoadRibbonCollapsedToolbar(void * ABitmap);
	virtual void __fastcall LoadRibbonContexts(void * ABitmap);
	virtual void __fastcall LoadRibbonElements(void * ABitmap);
	virtual void __fastcall LoadRibbonForm(void * ABitmap);
	virtual void __fastcall LoadRibbonFormBorderIcons(void * ABitmap);
	void __fastcall LoadRibbonFormBorderIconsGlyphs(void * ABitmap, int X, int Y, int AWidth, int AHeight);
	virtual void __fastcall LoadRibbonFormBorders(void * ABitmap);
	virtual void __fastcall LoadRibbonGallery(void * ABitmap);
	virtual void __fastcall LoadRibbonGalleryInRibbonScrollBarButtons(void * ABitmap);
	virtual void __fastcall LoadRibbonGalleryInRibbonScrollBarButtonsGlyphs(void * ABitmap);
	virtual void __fastcall LoadRibbonGroup(void * ABitmap);
	virtual void __fastcall LoadRibbonMenu(void * ABitmap);
	virtual void __fastcall LoadRibbonQAT(void * ABitmap);
	virtual void __fastcall LoadRibbonScrollBars(void * ABitmap);
	virtual void __fastcall LoadRibbonScrollButtons(void * ABitmap);
	virtual void __fastcall LoadRibbonStatusBar(void * ABitmap);
	virtual void __fastcall LoadRibbonTab(void * ABitmap);
	
public:
	virtual void __fastcall DrawApplicationButton(HDC DC, const System::Types::TRect &R, TdxRibbonApplicationButtonState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawArrowDown(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawBackstageViewMenuSeparator(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupBorderLeft(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupBorderMiddle(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawButtonGroupBorderRight(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupSplitButtonSeparator(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawCollapsedToolbarBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawCollapsedToolbarGlyphBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawContextBackground(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextBackgroundGlass(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextTabBackground(HDC DC, const System::Types::TRect &R, TdxRibbonTabState AState, System::Uitypes::TColor AColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextTabGroupsArea(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AContextColor, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawContextTabSeparator(HDC DC, const System::Types::TRect &R, bool ABeginGroup);
	virtual void __fastcall DrawDropDownGalleryBottomSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryTopSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawFormBorders(HDC DC, const System::Types::TRect &ABordersWidth, const TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormBorderIcon(HDC DC, const System::Types::TRect &R, TdxRibbonBorderDrawIcon AIcon, TdxRibbonBorderIconState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawFormCaption(HDC DC, const System::Types::TRect &R, const TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormStatusBarPart(HDC DC, const System::Types::TRect &R, bool AIsLeft, bool AIsActive, bool AIsRaised, bool AIsRectangular, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawGalleryFilterBandBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGalleryGroupHeaderBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGroupScrollButton(HDC DC, const System::Types::TRect &R, bool ALeft, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawInRibbonGalleryScrollBarButton(HDC DC, const System::Types::TRect &R, TdxInRibbonGalleryScrollBarButtonKind AButtonKind, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButtonDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButtonDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLaunchButtonBackground(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLaunchButtonDefaultGlyph(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMarkArrow(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawMDIButton(HDC DC, const System::Types::TRect &R, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMDIButtonGlyph(HDC DC, const System::Types::TRect &R, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawMenuArrowDown(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuArrowRight(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuCheck(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuCheckMark(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuDetachCaption(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawMenuScrollArea(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawProgressDiscreteBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawProgressSolidBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawProgressSubstrate(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawQuickAccessToolbarDefaultGlyph(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawQuickAccessToolbarPopup(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawRibbonClientTopArea(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawScrollBarBackground(HDC DC, const System::Types::TRect &R, bool AHorizontal, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawScrollBarPart(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, int AState, bool AHorizontal, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButtonDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButtonDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBar(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarGripBackground(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarPanel(HDC DC, const System::Types::TRect &Bounds, const System::Types::TRect &R, bool AIsLowered, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarPanelSeparator(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarToolbarSeparator(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTab(HDC DC, const System::Types::TRect &R, TdxRibbonTabState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTabGroupBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupHeaderBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupsArea(HDC DC, const System::Types::TRect &R, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawTabScrollButton(HDC DC, const System::Types::TRect &R, bool ALeft, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxCustomRibbonTexturedSkin(void) : TdxCustomRibbonSkin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxCustomRibbonTexturedSkin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomRibbon2010Skin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomRibbon2010Skin : public TdxCustomRibbonTexturedSkin
{
	typedef TdxCustomRibbonTexturedSkin inherited;
	
protected:
	System::StaticArray<int, 5> FBackstageViewFrame;
	int FBackstageViewMenuBackground;
	System::StaticArray<System::StaticArray<int, 2>, 5> FBackstageViewMenuButton;
	int FBackstageViewMenuSeparator;
	int FBackstageViewTabArrow;
	System::StaticArray<System::StaticArray<int, 4>, 5> FBackstageViewTabs;
	TThreeStateArray FCloseButton;
	int FContextBackgroundMask;
	System::StaticArray<int, 5> FContextTabMaskIndex;
	TTwoStateArray FItemsSeparator;
	System::StaticArray<System::StaticArray<int, 4>, 3> FMDIButtonGlyphs;
	System::StaticArray<System::StaticArray<int, 2>, 3> FMinimizeRibbonButtonGlyph;
	int FTabsAreaOnGlass;
	virtual TdxRibbonStyle __fastcall GetStyle(void);
	void __fastcall DrawColoredElement(int APartIndex, HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawFormCaptionSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall LoadCommonApplicationButton(void * ABitmap);
	virtual void __fastcall LoadCommonBackstageView(void * ABitmap);
	virtual void __fastcall LoadCommonElements(void * ABitmap);
	virtual void __fastcall LoadCommonMenu(void * ABitmap);
	virtual void __fastcall LoadCommonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	virtual void __fastcall LoadRibbonApplicationButton(void * ABitmap);
	virtual void __fastcall LoadRibbonBackstageView(void * ABitmap);
	virtual void __fastcall LoadRibbonCollapsedToolbar(void * ABitmap);
	virtual void __fastcall LoadRibbonContexts(void * ABitmap);
	virtual void __fastcall LoadRibbonElements(void * ABitmap);
	virtual void __fastcall LoadRibbonForm(void * ABitmap);
	virtual void __fastcall LoadRibbonFormBorderIcons(void * ABitmap);
	virtual void __fastcall LoadRibbonFormBorders(void * ABitmap);
	virtual void __fastcall LoadRibbonGalleryInRibbonScrollBarButtonsGlyphs(void * ABitmap);
	virtual void __fastcall LoadRibbonGroup(void * ABitmap);
	virtual void __fastcall LoadRibbonStatusBar(void * ABitmap);
	virtual void __fastcall LoadRibbonTab(void * ABitmap);
	
public:
	virtual void __fastcall DrawBackstageViewBackground(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuBackground(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuSeparator(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewTabButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall AdjustContextFont(Vcl::Graphics::TFont* AFont, bool AUseGlass, System::Uitypes::TColor AContextColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextBackground(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextBackgroundGlass(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextTabBackground(HDC DC, const System::Types::TRect &R, TdxRibbonTabState AState, System::Uitypes::TColor AColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuBackground(HDC DC, const System::Types::TRect &R, const System::Types::TRect &AContentRect, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroup(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextTabGroupsArea(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AContextColor, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawFormBorderIcon(HDC DC, const System::Types::TRect &R, TdxRibbonBorderDrawIcon AIcon, TdxRibbonBorderIconState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawFormCaption(HDC DC, const System::Types::TRect &R, const TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawItemSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawMenuExtraSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawMDIButtonGlyph(HDC DC, const System::Types::TRect &R, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawMinimizeRibbonButtonGlyph(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, TdxRibbonMinimizeButtonGlyph AGlyph, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawQuickAccessToolbar(HDC DC, const System::Types::TRect &R, bool ABellow, bool ANonClientDraw, bool AHasApplicationButton, bool AIsActive, bool ADontUseAero);
	virtual void __fastcall DrawRibbonTopFrameArea(HDC DC, const System::Types::TRect &R, bool AUseAeroGlass);
	virtual void __fastcall DrawSeparatorLine(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawTabGroupBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupHeaderBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual System::Types::TRect __fastcall GetApplicationMenuContentOffset(const System::Types::TRect &ATabsBounds);
	virtual System::Types::TSize __fastcall GetApplicationMenuGlyphSize(void);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
	virtual System::Types::TRect __fastcall GetPartContentOffsets(int APart);
	virtual int __fastcall GetPartSize(int APart);
	virtual int __fastcall GetQuickAccessToolbarMarkButtonOffset(bool AHasApplicationButton, bool ABelow);
	virtual int __fastcall GetQuickAccessToolbarOverrideWidth(bool AHasApplicationButton, bool AUseAeroGlass);
	virtual System::Types::TRect __fastcall GetWindowBordersWidth(bool AHasStatusBar);
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxCustomRibbon2010Skin(void) : TdxCustomRibbonTexturedSkin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxCustomRibbon2010Skin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBlueRibbonSkin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBlueRibbonSkin : public TdxCustomRibbonTexturedSkin
{
	typedef TdxCustomRibbonTexturedSkin inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName(void);
	virtual void __fastcall GetApplicationMenuContentColors(System::Uitypes::TColor &AInnerBorderColor, System::Uitypes::TColor &AOuterBorderColor, System::Uitypes::TColor &ASideColor);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	
public:
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(HDC DC, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxBlueRibbonSkin(void) : TdxCustomRibbonTexturedSkin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxBlueRibbonSkin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBlackRibbonSkin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBlackRibbonSkin : public TdxCustomRibbonTexturedSkin
{
	typedef TdxCustomRibbonTexturedSkin inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName(void);
	virtual void __fastcall GetApplicationMenuContentColors(System::Uitypes::TColor &AInnerBorderColor, System::Uitypes::TColor &AOuterBorderColor, System::Uitypes::TColor &ASideColor);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	
public:
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(HDC DC, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxBlackRibbonSkin(void) : TdxCustomRibbonTexturedSkin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxBlackRibbonSkin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSilverRibbonSkin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSilverRibbonSkin : public TdxBlackRibbonSkin
{
	typedef TdxBlackRibbonSkin inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName(void);
	virtual void __fastcall GetApplicationMenuContentColors(System::Uitypes::TColor &AInnerBorderColor, System::Uitypes::TColor &AOuterBorderColor, System::Uitypes::TColor &ASideColor);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	
public:
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(HDC DC, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxSilverRibbonSkin(void) : TdxBlackRibbonSkin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSilverRibbonSkin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBlueRibbon2010Skin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBlueRibbon2010Skin : public TdxCustomRibbon2010Skin
{
	typedef TdxCustomRibbon2010Skin inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName(void);
	virtual void __fastcall DrawFormCaptionSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall GetApplicationMenuContentColors(System::Uitypes::TColor &AInnerBorderColor, System::Uitypes::TColor &AOuterBorderColor, System::Uitypes::TColor &ASideColor);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	
public:
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawTabAreaBackground(HDC DC, const System::Types::TRect &R, bool AActive, bool AUseAeroGlass, TdxRibbonApplicationMenuState AApplicationMenuState);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxBlueRibbon2010Skin(void) : TdxCustomRibbon2010Skin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxBlueRibbon2010Skin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxSilverRibbon2010Skin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSilverRibbon2010Skin : public TdxCustomRibbon2010Skin
{
	typedef TdxCustomRibbon2010Skin inherited;
	
protected:
	virtual void __fastcall DrawFormCaptionSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall GetApplicationMenuContentColors(System::Uitypes::TColor &AInnerBorderColor, System::Uitypes::TColor &AOuterBorderColor, System::Uitypes::TColor &ASideColor);
	virtual System::UnicodeString __fastcall GetName(void);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	
public:
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawTabAreaBackground(HDC DC, const System::Types::TRect &R, bool AActive, bool AUseAeroGlass, TdxRibbonApplicationMenuState AApplicationMenuState);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxSilverRibbon2010Skin(void) : TdxCustomRibbon2010Skin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSilverRibbon2010Skin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBlackRibbon2010Skin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBlackRibbon2010Skin : public TdxCustomRibbon2010Skin
{
	typedef TdxCustomRibbon2010Skin inherited;
	
protected:
	virtual void __fastcall DrawFormCaptionSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall GetApplicationMenuContentColors(System::Uitypes::TColor &AInnerBorderColor, System::Uitypes::TColor &AOuterBorderColor, System::Uitypes::TColor &ASideColor);
	virtual System::UnicodeString __fastcall GetName(void);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	
public:
	virtual void __fastcall DrawMenuExtraSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawTabAreaBackground(HDC DC, const System::Types::TRect &R, bool AActive, bool AUseAeroGlass, TdxRibbonApplicationMenuState AApplicationMenuState);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxBlackRibbon2010Skin(void) : TdxCustomRibbon2010Skin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxBlackRibbon2010Skin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomRibbon2013Skin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomRibbon2013Skin : public TdxCustomRibbon2010Skin
{
	typedef TdxCustomRibbon2010Skin inherited;
	
protected:
	TTwoStateArray FBackstageViewBackButton;
	virtual void __fastcall LoadCommonBackstageView(void * ABitmap);
	virtual void __fastcall LoadCommonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	virtual void __fastcall LoadRibbonFormBorderIcons(void * ABitmap);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	System::Uitypes::TColor __fastcall GetAccentColor(TdxRibbonColorSchemeAccent AColorSchemeAccent)/* overload */;
	System::Uitypes::TColor __fastcall GetAccentColor(TdxRibbonColorSchemeAccent AColorSchemeAccent, const double ALightnessDelta)/* overload */;
	virtual System::Uitypes::TColor __fastcall GetCaptionAreaColor(TdxRibbonApplicationMenuState AApplicationMenuState);
	virtual System::Uitypes::TColor __fastcall GetFormBackgroundColor1(void);
	virtual System::Uitypes::TColor __fastcall GetFormBackgroundColor2(void);
	virtual System::Uitypes::TColor __fastcall GetFormBorderColor(bool AActive, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Uitypes::TColor __fastcall GetFrameColor(void);
	virtual System::Uitypes::TColor __fastcall GetGlyphColor(int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Uitypes::TColor __fastcall GetHighlightBorderColor(TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Uitypes::TColor __fastcall GetHighlightContentColor(TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Uitypes::TColor __fastcall GetMasterColor(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetMenuBackgroundColor(TdxRibbonColorSchemeAccent AColorSchemeAccent)/* overload */;
	System::Uitypes::TColor __fastcall GetMenuBackgroundColor(TdxRibbonColorSchemeAccent AColorSchemeAccent, const double ALightnessDelta)/* overload */;
	virtual TdxRibbonStyle __fastcall GetStyle(void);
	virtual System::Uitypes::TColor __fastcall GetTabGroupsAreaContentColor(void) = 0 ;
	
public:
	virtual void __fastcall DrawApplicationButton(HDC DC, const System::Types::TRect &R, TdxRibbonApplicationButtonState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawArrowDown(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawRibbonClientTopArea(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawApplicationMenuBackground(HDC DC, const System::Types::TRect &R, const System::Types::TRect &AContentRect, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuExtraPanePinButtonGlyph(HDC DC, const System::Types::TRect &R, int AState, bool AChecked, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuExtraSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawBackstageViewBackButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuBackground(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuHeader(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuSeparator(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewTabButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroup(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupBorderLeft(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupBorderMiddle(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawButtonGroupBorderRight(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupSplitButtonSeparator(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawCollapsedToolbarGlyphBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawCollapsedToolbarBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall AdjustContextFont(Vcl::Graphics::TFont* AFont, bool AUseGlass, System::Uitypes::TColor AContextColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall AdjustContextTabFont(Vcl::Graphics::TFont* AFont, int AState, System::Uitypes::TColor AContextColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextBackground(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextBackgroundGlass(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AContextColor);
	virtual void __fastcall DrawContextTabBackground(HDC DC, const System::Types::TRect &R, TdxRibbonTabState AState, System::Uitypes::TColor AColor, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextTabGroupsArea(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AContextColor, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawContextTabSeparator(HDC DC, const System::Types::TRect &R, bool ABeginGroup);
	virtual void __fastcall DrawDropDownGalleryBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryBottomSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryTopSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGalleryFilterBandBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGalleryGroupHeaderBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawInRibbonGalleryScrollBarButton(HDC DC, const System::Types::TRect &R, TdxInRibbonGalleryScrollBarButtonKind AButtonKind, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawEditButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawFormBorderIcon(HDC DC, const System::Types::TRect &R, TdxRibbonBorderDrawIcon AIcon, TdxRibbonBorderIconState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawFormBorders(HDC DC, const System::Types::TRect &ABordersWidth, const TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormCaption(HDC DC, const System::Types::TRect &R, const TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormStatusBarPart(HDC DC, const System::Types::TRect &R, bool AIsLeft, bool AIsActive, bool AIsRaised, bool AIsRectangular, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawRibbonFormBackground(HDC DC, const System::Types::TRect &R, int ARibbonHeight);
	virtual void __fastcall DrawSmallButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButtonDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButtonDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButtonDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButtonDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLaunchButtonBackground(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLaunchButtonDefaultGlyph(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawDropDownBorder(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuCheck(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuCheckMark(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuContent(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuGlyph(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuSeparatorHorz(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuSeparatorVert(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawQuickAccessToolbar(HDC DC, const System::Types::TRect &R, bool ABellow, bool ANonClientDraw, bool AHasApplicationButton, bool AIsActive, bool ADontUseAero);
	virtual void __fastcall DrawQuickAccessToolbarGroupButton(HDC DC, const System::Types::TRect &R, bool ABellow, bool ANonClientDraw, bool AIsActive, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawQuickAccessToolbarPopup(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGroupScrollButton(HDC DC, const System::Types::TRect &R, bool ALeft, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTabScrollButton(HDC DC, const System::Types::TRect &R, bool ALeft, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawScrollBarBackground(HDC DC, const System::Types::TRect &R, bool AHorizontal, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawScrollBarPart(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, int AState, bool AHorizontal, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawScrollBoxSizeGripArea(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Uitypes::TColor __fastcall GetScrollBarBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetScrollBarPartBorderColor(Cxlookandfeelpainters::TcxScrollBarPart APart, int AState);
	virtual System::Uitypes::TColor __fastcall GetScrollBarPartContentColor(Cxlookandfeelpainters::TcxScrollBarPart APart, int AState);
	virtual void __fastcall DrawSeparatorBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawSeparatorLine(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawStatusBar(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarGripBackground(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarSizeGrip(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarPanel(HDC DC, const System::Types::TRect &Bounds, const System::Types::TRect &R, bool AIsLowered, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarPanelSeparator(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarToolbarSeparator(HDC DC, const System::Types::TRect &R, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTab(HDC DC, const System::Types::TRect &R, TdxRibbonTabState AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTabAreaBackground(HDC DC, const System::Types::TRect &R, bool AActive, bool AUseAeroGlass, TdxRibbonApplicationMenuState AApplicationMenuState);
	virtual void __fastcall DrawTabGroupBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupHeaderBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupsArea(HDC DC, const System::Types::TRect &R, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawMinimizeRibbonButtonGlyph(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, TdxRibbonMinimizeButtonGlyph AGlyph, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawItemSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawKeyTip(HDC DC, const System::Types::TRect &R);
	virtual bool __fastcall HasExternalRibbonFormShadow(void);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, TdxRibbonColorSchemeAccent AColorSchemeAccent = (TdxRibbonColorSchemeAccent)(0x0));
	virtual System::Types::TRect __fastcall GetPartContentOffsets(int APart);
	virtual int __fastcall GetPartSize(int APart);
	virtual System::Types::TRect __fastcall GetWindowBordersWidth(bool AHasStatusBar);
	virtual bool __fastcall UseRoundedWindowCorners(void);
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxCustomRibbon2013Skin(void) : TdxCustomRibbon2010Skin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxCustomRibbon2013Skin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxLightGrayRibbon2013Skin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxLightGrayRibbon2013Skin : public TdxCustomRibbon2013Skin
{
	typedef TdxCustomRibbon2013Skin inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName(void);
	virtual System::Uitypes::TColor __fastcall GetFormBackgroundColor2(void);
	virtual System::Uitypes::TColor __fastcall GetMasterColor(void);
	virtual System::Uitypes::TColor __fastcall GetMenuBackgroundColor(TdxRibbonColorSchemeAccent AColorSchemeAccent)/* overload */;
	virtual System::Uitypes::TColor __fastcall GetTabGroupsAreaContentColor(void);
	
public:
	virtual System::Uitypes::TColor __fastcall GetScrollBarBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetScrollBarPartContentColor(Cxlookandfeelpainters::TcxScrollBarPart APart, int AState);
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxLightGrayRibbon2013Skin(void) : TdxCustomRibbon2013Skin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxLightGrayRibbon2013Skin(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline System::Uitypes::TColor __fastcall  GetMenuBackgroundColor(TdxRibbonColorSchemeAccent AColorSchemeAccent, const double ALightnessDelta){ return TdxCustomRibbon2013Skin::GetMenuBackgroundColor(AColorSchemeAccent, ALightnessDelta); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxDarkGrayRibbon2013Skin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDarkGrayRibbon2013Skin : public TdxCustomRibbon2013Skin
{
	typedef TdxCustomRibbon2013Skin inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName(void);
	virtual System::Uitypes::TColor __fastcall GetFormBackgroundColor2(void);
	virtual System::Uitypes::TColor __fastcall GetFrameColor(void);
	virtual System::Uitypes::TColor __fastcall GetMasterColor(void);
	virtual System::Uitypes::TColor __fastcall GetMenuBackgroundColor(TdxRibbonColorSchemeAccent AColorSchemeAccent)/* overload */;
	virtual System::Uitypes::TColor __fastcall GetTabGroupsAreaContentColor(void);
	
public:
	virtual void __fastcall DrawBackstageViewTabButton(HDC DC, const System::Types::TRect &R, int AState, TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual System::Uitypes::TColor __fastcall GetScrollBarBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetScrollBarPartContentColor(Cxlookandfeelpainters::TcxScrollBarPart APart, int AState);
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxDarkGrayRibbon2013Skin(void) : TdxCustomRibbon2013Skin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxDarkGrayRibbon2013Skin(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline System::Uitypes::TColor __fastcall  GetMenuBackgroundColor(TdxRibbonColorSchemeAccent AColorSchemeAccent, const double ALightnessDelta){ return TdxCustomRibbon2013Skin::GetMenuBackgroundColor(AColorSchemeAccent, ALightnessDelta); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWhiteRibbon2013Skin;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWhiteRibbon2013Skin : public TdxCustomRibbon2013Skin
{
	typedef TdxCustomRibbon2013Skin inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetName(void);
	virtual System::Uitypes::TColor __fastcall GetFormBackgroundColor2(void);
	virtual System::Uitypes::TColor __fastcall GetMasterColor(void);
	virtual System::Uitypes::TColor __fastcall GetTabGroupsAreaContentColor(void);
	
public:
	virtual System::Uitypes::TColor __fastcall GetScrollBarPartBorderColor(Cxlookandfeelpainters::TcxScrollBarPart APart, int AState);
	virtual System::Uitypes::TColor __fastcall GetScrollBarPartContentColor(Cxlookandfeelpainters::TcxScrollBarPart APart, int AState);
public:
	/* TdxCustomRibbonSkin.Create */ inline __fastcall TdxWhiteRibbon2013Skin(void) : TdxCustomRibbon2013Skin() { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxWhiteRibbon2013Skin(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonSkinsManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonSkinsManager : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxCustomRibbonSkin* operator[](int Index) { return Skins[Index]; }
	
private:
	Cxclasses::TcxObjectList* FList;
	TdxCustomRibbonSkin* __fastcall GetSkin(int Index);
	int __fastcall GetSkinCount(void);
	
protected:
	virtual void __fastcall Changed(void);
	
public:
	__fastcall TdxRibbonSkinsManager(void);
	__fastcall virtual ~TdxRibbonSkinsManager(void);
	int __fastcall Add(TdxCustomRibbonSkin* ASkin);
	TdxCustomRibbonSkin* __fastcall Find(const System::UnicodeString AName, TdxRibbonStyle AStyle);
	bool __fastcall Remove(TdxCustomRibbonSkin* ASkin);
	__property int SkinCount = {read=GetSkinCount, nodefault};
	__property TdxCustomRibbonSkin* Skins[int Index] = {read=GetSkin/*, default*/};
};

#pragma pack(pop)

typedef System::StaticArray<System::UnicodeString, 5> Dxribbonskins__51;

//-- var, const, procedure ---------------------------------------------------
static const System::Word rfspActiveCaption = System::Word(0x2710);
static const System::Word rfspInactiveCaption = System::Word(0x2711);
static const System::Word rfspActiveCaptionZoomed = System::Word(0x2712);
static const System::Word rfspInactiveCaptionZoomed = System::Word(0x2713);
static const System::Word rfspActiveCaptionLeftBorder = System::Word(0x2714);
static const System::Word rfspInactiveCaptionLeftBorder = System::Word(0x2715);
static const System::Word rfspActiveCaptionRightBorder = System::Word(0x2716);
static const System::Word rfspInactiveCaptionRightBorder = System::Word(0x2717);
static const System::Word rfspActiveLeftBorder = System::Word(0x2718);
static const System::Word rfspInactiveLeftBorder = System::Word(0x2719);
static const System::Word rfspActiveRightBorder = System::Word(0x271a);
static const System::Word rfspInactiveRightBorder = System::Word(0x271b);
static const System::Word rfspActiveBottomBorderThin = System::Word(0x271c);
static const System::Word rfspInactiveBottomBorderThin = System::Word(0x271d);
static const System::Word rfspActiveBottomBorderThick = System::Word(0x271e);
static const System::Word rfspInactiveBottomBorderThick = System::Word(0x271f);
static const System::Word rfspActiveBottomBorderThickRectangular = System::Word(0x2720);
static const System::Word rfspInactiveBottomBorderThickRectangular = System::Word(0x2721);
static const System::Word rfspRibbonForm = System::Word(0x2722);
static const System::Word rspTabNormal = System::Word(0x273b);
static const System::Word rspTabHot = System::Word(0x273c);
static const System::Word rspTabActive = System::Word(0x273d);
static const System::Word rspTabActiveHot = System::Word(0x273e);
static const System::Word rspTabFocused = System::Word(0x273f);
static const System::Word rspTabGroupsArea = System::Word(0x2740);
static const System::Word rspTabGroupsArea2 = System::Word(0x2741);
static const System::Word rspTabSeparator = System::Word(0x2742);
static const System::Word rspTabGroupsAreaInPopup = System::Word(0x2743);
static const System::Word rspQATDefaultGlyph = System::Word(0x2744);
static const System::Word rspQATAtBottom = System::Word(0x2745);
static const System::Word rspRibbonClientTopArea = System::Word(0x2746);
static const System::Word rspQATNonClientLeft1Vista = System::Word(0x2747);
static const System::Word rspQATNonClientLeft2Vista = System::Word(0x2748);
static const System::Word rspQATNonClientRightVista = System::Word(0x2749);
static const System::Word rspQATPopup = System::Word(0x274a);
static const System::Word rspQATNonClientLeft1Active = System::Word(0x274b);
static const System::Word rspQATNonClientLeft1Inactive = System::Word(0x274c);
static const System::Word rspQATNonClientLeft2Active = System::Word(0x274d);
static const System::Word rspQATNonClientLeft2Inactive = System::Word(0x274e);
static const System::Word rspQATNonClientRightActive = System::Word(0x274f);
static const System::Word rspQATNonClientRightInactive = System::Word(0x2750);
static const System::Word rspRibbonBackground = System::Word(0x2751);
static const System::Word rspRibbonBottomEdge = System::Word(0x2752);
static const System::Word rspApplicationMenuBorder = System::Word(0x2756);
static const System::Word rspApplicationMenuContentHeader = System::Word(0x2757);
static const System::Word rspApplicationMenuContentFooter = System::Word(0x2758);
static const System::Word rspDropDownBorder = System::Word(0x2759);
static const System::Word rspMenuContent = System::Word(0x275a);
static const System::Word rspMenuGlyph = System::Word(0x275b);
static const System::Word rspMenuMark = System::Word(0x275c);
static const System::Word rspMenuSeparatorHorz = System::Word(0x275d);
static const System::Word rspMenuSeparatorVert = System::Word(0x275e);
static const System::Word rspMenuArrowDown = System::Word(0x275f);
static const System::Word rspMenuArrowRight = System::Word(0x2760);
static const System::Word rspProgressSolidBand = System::Word(0x2761);
static const System::Word rspProgressDiscreteBand = System::Word(0x2762);
static const System::Word rspProgressSubstrate = System::Word(0x2763);
static const System::Word rspButtonGroupBorderLeft = System::Word(0x2764);
static const System::Word rspButtonGroupBorderRight = System::Word(0x2765);
static const System::Word rspScrollArrow = System::Word(0x2766);
static const System::Word rspScreenTip = System::Word(0x2767);
static const System::Word rspHelpButton = System::Word(0x2768);
static const System::Word rspApplicationMenuButton = System::Word(0x2769);
static const System::Word rspStatusBar = System::Word(0x276a);
static const System::Word rspStatusBarPanel = System::Word(0x276b);
static const System::Word rspStatusBarPanelLowered = System::Word(0x276c);
static const System::Word rspStatusBarPanelRaised = System::Word(0x276d);
static const System::Word rspStatusBarPanelSeparator = System::Word(0x276e);
static const System::Word rspStatusBarGripBackground = System::Word(0x276f);
static const System::Word rspStatusBarToolbarSeparator = System::Word(0x2770);
static const System::Word rspStatusBarSizeGripColor1 = System::Word(0x2772);
static const System::Word rspStatusBarSizeGripColor2 = System::Word(0x2773);
static const System::Word rspStatusBarFormLeftPart = System::Word(0x2774);
static const System::Word rspStatusBarFormRightPart = System::Word(0x2778);
static const System::Word rspStatusBarFormLeftPartDialog = System::Word(0x277c);
static const System::Word rspStatusBarFormRightPartDialog = System::Word(0x2780);
static const System::Word rspDropDownGalleryTopSizingBand = System::Word(0x2788);
static const System::Word rspDropDownGalleryBottomSizingBand = System::Word(0x2789);
static const System::Word rspDropDownGalleryTopSizeGrip = System::Word(0x278a);
static const System::Word rspDropDownGalleryBottomSizeGrip = System::Word(0x278b);
static const System::Word rspDropDownGalleryVerticalSizeGrip = System::Word(0x278c);
static const System::Word rspGalleryFilterBand = System::Word(0x278d);
static const System::Word rspGalleryGroupHeader = System::Word(0x278e);
static const System::Word rspFormCaptionText = System::Word(0x2792);
static const System::Word rspDocumentNameText = System::Word(0x2793);
static const System::Word rspTabHeaderText = System::Word(0x2794);
static const System::Word rspTabGroupText = System::Word(0x2795);
static const System::Word rspTabGroupHeaderText = System::Word(0x2796);
static const System::Word rspStatusBarText = System::Word(0x279a);
static const System::Word rspContextText = System::Word(0x279b);
static const System::Word rspContextTextOnGlass = System::Word(0x279c);
static const System::Word rspContextTextShadow = System::Word(0x279d);
static const System::Word rspContextTextOnGlassShadow = System::Word(0x279e);
static const System::Word rspContextTabNormal = System::Word(0x279f);
static const System::Word rspContextTabHot = System::Word(0x27a0);
static const System::Word rspContextTabActive = System::Word(0x27a1);
static const System::Word rspContextTabActiveHot = System::Word(0x27a2);
static const System::Word rspContextTabFocused = System::Word(0x27a3);
static const System::Word rspContextTabGroupsArea = System::Word(0x27a4);
static const System::Word rspContextTabGroupsArea2 = System::Word(0x27a5);
static const System::Word rspContextTabSeparatorBegin = System::Word(0x27a6);
static const System::Word rspContextTabSeparatorEnd = System::Word(0x27a7);
static const System::Word rspContextBackground = System::Word(0x27a8);
static const System::Word rspContextBackgroundGlass = System::Word(0x27a9);
static const System::Word rspContextTabHeaderText = System::Word(0x27aa);
static const System::Word rfspBorderIconBackground = System::Word(0x27b0);
static const System::Word rfspBorderIconMinimizeGlyph = System::Word(0x27b3);
static const System::Word rfspBorderIconMaximizeGlyph = System::Word(0x27b7);
static const System::Word rfspBorderIconCloseGlyph = System::Word(0x27bb);
static const System::Word rfspBorderIconRestoreGlyph = System::Word(0x27bf);
static const System::Word rfspBorderIconHelpGlyph = System::Word(0x27c3);
static const System::Word rfspBorderIconAutoHideGlyph = System::Word(0x27c7);
static const System::Word rfspBorderIconAutoHideShowUIGlyph = System::Word(0x27cb);
static const System::Word rspTabGroupBottomOffset = System::Word(0x27cf);
static const System::Word rspQATGroupButtonActive = System::Word(0x27d0);
static const System::Word rspQATGroupButtonInactive = System::Word(0x27d9);
static const System::Word rspArrowDownNormal = System::Word(0x27e2);
static const System::Word rspMenuDetachCaptionNormal = System::Word(0x27eb);
static const System::Word rspMenuCheckNormal = System::Word(0x27f4);
static const System::Word rspMenuCheckMarkNormal = System::Word(0x27fd);
static const System::Word rspMenuScrollAreaNormal = System::Word(0x2806);
static const System::Word rspCollapsedToolbarNormal = System::Word(0x280f);
static const System::Word rspCollapsedToolbarGlyphBackgroundNormal = System::Word(0x2818);
static const System::Word rspEditButtonNormal = System::Word(0x2821);
static const System::Word rspSmallButtonNormal = System::Word(0x282a);
static const System::Word rspSmallButtonGlyphBackgroundNormal = System::Word(0x2833);
static const System::Word rspSmallButtonDropButtonNormal = System::Word(0x283c);
static const System::Word rspLargeButtonNormal = System::Word(0x2845);
static const System::Word rspLargeButtonGlyphBackgroundNormal = System::Word(0x284e);
static const System::Word rspLargeButtonDropButtonNormal = System::Word(0x2857);
static const System::Word rspButtonGroupNormal = System::Word(0x2860);
static const System::Word rspButtonGroupBorderMiddleNormal = System::Word(0x2869);
static const System::Word rspButtonGroupSplitButtonSeparatorNormal = System::Word(0x2872);
static const System::Word rspToolbarNormal = System::Word(0x287b);
static const System::Word rspToolbarHeaderNormal = System::Word(0x2884);
static const System::Word rspMarkArrowNormal = System::Word(0x288d);
static const System::Word rspMarkTruncatedNormal = System::Word(0x2896);
static const System::Word rspLaunchButtonBackgroundNormal = System::Word(0x289f);
static const System::Word rspLaunchButtonDefaultGlyphNormal = System::Word(0x28a8);
static const System::Word rspTabScrollLeftButtonNormal = System::Word(0x28b1);
static const System::Word rspTabScrollRightButtonNormal = System::Word(0x28ba);
static const System::Word rspGroupScrollLeftButtonNormal = System::Word(0x28c3);
static const System::Word rspGroupScrollRightButtonNormal = System::Word(0x28cc);
static const System::Word rspInRibbonGalleryScrollBarLineUpButtonNormal = System::Word(0x28d5);
static const System::Word rspInRibbonGalleryScrollBarLineUpButtonGlyphNormal = System::Word(0x28de);
static const System::Word rspInRibbonGalleryScrollBarLineDownButtonNormal = System::Word(0x28e7);
static const System::Word rspInRibbonGalleryScrollBarLineDownButtonGlyphNormal = System::Word(0x28f0);
static const System::Word rspInRibbonGalleryScrollBarDropDownButtonNormal = System::Word(0x28f9);
static const System::Word rspInRibbonGalleryScrollBarDropDownButtonGlyphNormal = System::Word(0x2902);
static const System::Word rfspCloseButtonHot = System::Word(0x290b);
static const System::Word rfspCloseButtonPressed = System::Word(0x290c);
static const System::Word rfspCloseButtonInactiveHot = System::Word(0x290d);
static const System::Word rspMinimizeRibbonButtonMinimize = System::Word(0x290e);
static const System::Word rspMinimizeRibbonButtonRestore = System::Word(0x2910);
static const System::Word rspMinimizeRibbonButtonPin = System::Word(0x2912);
static const System::Word rspItemSeparatorHorizontal = System::Word(0x2914);
static const System::Word rspItemSeparatorVertical = System::Word(0x2915);
static const System::Word rspMDIButtonMinimize = System::Word(0x2916);
static const System::Word rspMDIButtonRestore = System::Word(0x291a);
static const System::Word rspMDIButtonClose = System::Word(0x291e);
static const System::Word rspTabsAreaOnGlass = System::Word(0x2922);
static const System::Word rspContextBackgroundMask = System::Word(0x2923);
static const System::Word rspContextTabMaskNormal = System::Word(0x2924);
static const System::Word rspContextTabMaskHot = System::Word(0x2925);
static const System::Word rspContextTabMaskActive = System::Word(0x2926);
static const System::Word rspContextTabMaskActiveHot = System::Word(0x2927);
static const System::Word rspContextTabMaskFocused = System::Word(0x2928);
static const System::Word rbvpBackstageView = System::Word(0x2929);
static const System::Word rbvpBackstageViewBackButton = System::Word(0x292a);
static const System::Word rbvpBackstageViewFrame = System::Word(0x292c);
static const System::Word rbvpBackstageViewMenu = System::Word(0x2931);
static const System::Word rbvpBackstageViewMenuHeader = System::Word(0x2932);
static const System::Word rbvpBackstageViewMenuItem = System::Word(0x2933);
static const System::Word rbvpBackstageViewMenuTabButton = System::Word(0x293d);
static const System::Word rbvpBackstageViewMenuTabButtonArrow = System::Word(0x2951);
static const System::Word rbvpBackstageViewMenuSeparator = System::Word(0x2952);
static const System::Word rspPinButtonGlyph = System::Word(0x2953);
static const System::Word rspApplicationButton = System::Word(0x2955);
static const System::Word rspScrollBarHorz = System::Word(0x2964);
static const System::Word rspScrollBarHorzThumb = System::Word(0x2968);
static const System::Word rspScrollBarHorzThumbGlyph = System::Word(0x296c);
static const System::Word rspScrollBarVert = System::Word(0x296d);
static const System::Word rspScrollBarVertThumb = System::Word(0x2971);
static const System::Word rspScrollBarVertThumbGlyph = System::Word(0x2975);
static const System::Word rspScrollBarButtonBottom = System::Word(0x2976);
static const System::Word rspScrollBarButtonBottomGlyph = System::Word(0x297a);
static const System::Word rspScrollBarButtonTop = System::Word(0x297b);
static const System::Word rspScrollBarButtonTopGlyph = System::Word(0x297f);
static const System::Word rspScrollBarButtonLeft = System::Word(0x2980);
static const System::Word rspScrollBarButtonLeftGlyph = System::Word(0x2984);
static const System::Word rspScrollBarButtonRight = System::Word(0x2985);
static const System::Word rspScrollBarButtonRightGlyph = System::Word(0x2989);
extern PACKAGE Dxribbonskins__51 dxRibbonColorSchemeAccentNames;
extern PACKAGE TdxRibbonSkinsManager* __fastcall dxRibbonSkinsManager(void);
extern PACKAGE bool __fastcall IsRectangularFormBottom(const TdxRibbonFormData &AData);
}	/* namespace Dxribbonskins */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONSKINS)
using namespace Dxribbonskins;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonskinsHPP
