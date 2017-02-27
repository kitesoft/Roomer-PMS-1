// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsdxRibbonPainter.pas' rev: 24.00 (Win64)

#ifndef DxskinsdxribbonpainterHPP
#define DxskinsdxribbonpainterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxBarSkin.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxBarSkinConsts.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <cxDWMApi.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxSkinInfo.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxOffice11.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdxribbonpainter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinRibbonPainter;
class PASCALIMPLEMENTATION TdxSkinRibbonPainter : public Dxribbonskins::TdxCustomRibbonSkin
{
	typedef Dxribbonskins::TdxCustomRibbonSkin inherited;
	
private:
	Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* FPainter;
	System::Uitypes::TColor __fastcall GetPopupMenuColor(void);
	Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* __fastcall GetSkinInfo(void);
	bool __fastcall GetTabAeroSupport(void);
	bool __fastcall GetUseSkins(void);
	
protected:
	void __fastcall CheckColorSchemeAccent(Dxribbonskins::TdxRibbonColorSchemeAccent &AColorSchemeAccent);
	System::Types::TRect __fastcall CorrectTabHeaderRect(const System::Types::TRect &R);
	System::Types::TRect __fastcall CorrectTabPanelRect(bool AIsInPopup, const System::Types::TRect &R);
	virtual Dxskinscore::TdxSkinElement* __fastcall GetApplicationButtonElement(void);
	int __fastcall GetApplicationButtonIndent(const System::UnicodeString AName);
	System::Types::TRect __fastcall GetBorderBounds(Cxgraphics::TcxBorder ASide, const System::Types::TRect &ABorders, const System::Types::TRect &ABounds);
	Dxskinscore::TdxSkinElement* __fastcall GetBorderIconElement(Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, bool AIsToolWindow);
	Dxskinscore::TdxSkinElement* __fastcall GetBorderSkinElement(Cxgraphics::TcxBorder ASide, bool AIsRectangular);
	System::Types::TRect __fastcall GetBordersWidth(bool AHasStatusBar);
	bool __fastcall GetCustomizeButtonOutsizeQAT(bool AHasAppButton);
	bool __fastcall GetElementContentIndents(Dxskinscore::TdxSkinElement* AElement, bool AConsideMargins, /* out */ int &ALeftIndent, /* out */ int &ARightIndent);
	System::Types::TSize __fastcall GetElementMinSize(Dxskinscore::TdxSkinElement* AElement);
	virtual System::UnicodeString __fastcall GetName(void);
	System::Uitypes::TColor __fastcall GetPropertyColor(Dxskinscore::TdxSkinColor* AColor);
	Dxskinscore::TdxSkinElement* __fastcall GetQATBackgroundElement(bool ABellow, bool AHasApplicationButton);
	int __fastcall GetQATLeftOffset(bool AHasApplicationButton);
	bool __fastcall DoDrawButtonGroupElement(HDC DC, const System::Types::TRect &R, int AState, Dxskinscore::TdxSkinElement* AElement);
	bool __fastcall DoDrawEditButtonGlyph(HDC DC, const System::Types::TRect &R, int AState, Cxlookandfeelpainters::TcxEditBtnKind AButtonKind);
	bool __fastcall DoDrawStatusBarBackground(HDC DC, const System::Types::TRect &R, const System::Types::TRect &AVisibleArea, bool AIsRaised);
	bool __fastcall DoDrawStatusBarPart(HDC DC, const System::Types::TRect &R, bool AIsRaised, bool AActive, bool AIsLeft);
	bool __fastcall DoDrawStatusBarRectangularPart(HDC DC, const System::Types::TRect &R, bool AIsRaised, bool AActive, bool AIsLeft);
	bool __fastcall DrawElement(HDC DC, const System::Types::TRect &R, Dxskinscore::TdxSkinElement* AElement)/* overload */;
	bool __fastcall DrawElement(HDC DC, const System::Types::TRect &R, int AState, Dxskinscore::TdxSkinElement* AElement, int AImageIndex = 0x0)/* overload */;
	void __fastcall DrawClippedElement(HDC DC, const System::Types::TRect &R, const System::Types::TRect &ASource, Dxskinscore::TdxSkinElement* AElement, Dxskinscore::TdxSkinElementState AState = (Dxskinscore::TdxSkinElementState)(0x0), Cxgraphics::TcxRegionOperation AOperation = (Cxgraphics::TcxRegionOperation)(0x3), int AImageIndex = 0x0);
	void __fastcall DrawColoredElement(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor, Dxskinscore::TdxSkinElement* AElement, Dxskinscore::TdxSkinElementState AState);
	void __fastcall DrawFormBorder(HDC DC, Cxgraphics::TcxBorder ASide, const System::Types::TRect &ABorderWidths, const System::Types::TRect &R, Dxskinscore::TdxSkinElement* AElement, bool AActive);
	void __fastcall DrawStatusBarFormBorder(HDC DC, const Dxribbonskins::TdxRibbonFormData &AData, const System::Types::TRect &ABorders);
	virtual void __fastcall LoadRibbonTexturesSet(Dxgdiplusclasses::TdxGPImage* AImage);
	__property Dxskinscore::TdxSkinElement* ApplicationButtonElement = {read=GetApplicationButtonElement};
	__property System::Uitypes::TColor PopupMenuColor = {read=GetPopupMenuColor, nodefault};
	__property Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* SkinInfo = {read=GetSkinInfo};
	__property bool TabAeroSupport = {read=GetTabAeroSupport, nodefault};
	
public:
	__fastcall virtual TdxSkinRibbonPainter(Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* APainter);
	virtual void __fastcall DrawApplicationButton(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonApplicationButtonState AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuBackground(HDC DC, const System::Types::TRect &R, const System::Types::TRect &AContentRect, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuButton(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuExtraPaneButton(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawApplicationMenuExtraPanePinButtonGlyph(HDC DC, const System::Types::TRect &R, int AState, bool AChecked, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewBackButton(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewBackground(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuBackground(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuButton(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuHeader(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuSeparator(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewTabButton(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewGalleryBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawBackstageViewGalleryItem(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewGallerySeparator(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroup(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawButtonGroupDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	void __fastcall DrawButtonGroupBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupBorderLeft(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupBorderMiddle(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawButtonGroupBorderRight(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawButtonGroupSplitButtonSeparator(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawCollapsedToolbarBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawCollapsedToolbarGlyphBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawEditArrowButton(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawEditEllipsisButton(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawEditSpinDownButton(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawEditSpinUpButton(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawProgressDiscreteBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawProgressSolidBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawProgressSubstrate(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownBorder(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryBottomSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryBottomSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryBottomVerticalSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryTopSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryTopSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownGalleryTopVerticalSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGalleryFilterBandBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawGalleryGroupHeaderBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawInRibbonGalleryBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawInRibbonGalleryScrollBarBackground(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawInRibbonGalleryScrollBarButton(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxInRibbonGalleryScrollBarButtonKind AButtonKind, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawRibbonFormBackground(HDC DC, const System::Types::TRect &R, int ARibbonHeight);
	virtual void __fastcall DrawFormBorders(HDC DC, const System::Types::TRect &ABordersWidth, const Dxribbonskins::TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormBorderIcon(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, Dxribbonskins::TdxRibbonBorderIconState AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawFormCaption(HDC DC, const System::Types::TRect &R, const Dxribbonskins::TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormStatusBarPart(HDC DC, const System::Types::TRect &R, bool AIsLeft, bool AIsActive, bool AIsRaised, bool AIsRectangular, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextBackground(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextBackgroundGlass(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextTabBackground(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonTabState AState, System::Uitypes::TColor AColor, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawContextTabGroupsArea(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AContextColor, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawContextTabSeparator(HDC DC, const System::Types::TRect &R, bool ABeginGroup);
	virtual void __fastcall DrawArrowDown(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawEditButton(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawGroupScrollButton(HDC DC, const System::Types::TRect &R, bool ALeft, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawHelpButton(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawItemSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawKeyTip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMarkArrow(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawMDIButton(HDC DC, const System::Types::TRect &R, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMDIButtonGlyph(HDC DC, const System::Types::TRect &R, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawMinimizeRibbonButtonGlyph(HDC DC, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, Dxribbonskins::TdxRibbonMinimizeButtonGlyph AGlyph, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawRibbonClientTopArea(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawRibbonTopFrameArea(HDC DC, const System::Types::TRect &R, bool AUseAeroGlass);
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawScreenTip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawSeparatorBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawLargeButton(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButtonDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLargeButtonDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLaunchButtonBackground(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawLaunchButtonDefaultGlyph(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuCheck(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuCheckMark(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuContent(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuExtraSeparator(HDC DC, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawMenuGlyph(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuItem(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuItemDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuItemDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawMenuMark(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuScrollArea(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DrawMenuSeparatorHorz(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuSeparatorVert(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawSmallButton(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButtonDropButtonArrowPart(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawSmallButtonDropButtonMainPart(HDC DC, const System::Types::TRect &R, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBar(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarGripBackground(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarPanel(HDC DC, const System::Types::TRect &Bounds, const System::Types::TRect &R, bool AIsLowered, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarPanelSeparator(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarSizeGrip(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawStatusBarToolbarSeparator(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetScrollBarPainter(void);
	virtual void __fastcall DrawTab(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonTabState AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTabAreaBackground(HDC DC, const System::Types::TRect &R, bool AActive, bool AUseAeroGlass, Dxribbonskins::TdxRibbonApplicationMenuState AApplicationMenuState);
	virtual void __fastcall DrawTabGroupBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupHeaderBackground(HDC DC, const System::Types::TRect &R, int AState, bool AIsInPopup);
	virtual void __fastcall DrawTabGroupsArea(HDC DC, const System::Types::TRect &R, bool AIsQATAtBottom, bool AIsInPopup);
	virtual void __fastcall DrawTabScrollButton(HDC DC, const System::Types::TRect &R, bool ALeft, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawTabSeparator(HDC DC, const System::Types::TRect &R, System::Byte Alpha);
	virtual void __fastcall DrawQuickAccessToolbar(HDC DC, const System::Types::TRect &R, bool ABellow, bool ANonClientDraw, bool AHasApplicationButton, bool AIsActive, bool ADontUseAero);
	virtual void __fastcall DrawQuickAccessToolbarDefaultGlyph(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawQuickAccessToolbarGroupButton(HDC DC, const System::Types::TRect &R, bool ABellow, bool ANonClientDraw, bool AIsActive, int AState, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawQuickAccessToolbarPopup(HDC DC, const System::Types::TRect &R);
	virtual int __fastcall AdjustCaptionFontSize(int ASize, bool AUseAeroGlass);
	virtual void __fastcall AdjustRibbonFormBorderIconSize(Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, bool AIsToolWindow, System::Types::TSize &ASize);
	virtual System::Types::TRect __fastcall GetApplicationMenuContentOffset(const System::Types::TRect &ATabsBounds);
	virtual System::Types::TSize __fastcall GetApplicationMenuGlyphSize(void);
	virtual bool __fastcall GetIsAlphaUsed(int APart);
	virtual int __fastcall GetMenuSeparatorSize(void);
	virtual System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent = (Dxribbonskins::TdxRibbonColorSchemeAccent)(0x0));
	virtual System::Types::TRect __fastcall GetPartContentOffsets(int APart);
	virtual int __fastcall GetPartSize(int APart);
	virtual int __fastcall GetQuickAccessToolbarLeftIndent(bool AHasApplicationButton, bool AUseAeroGlass);
	virtual int __fastcall GetQuickAccessToolbarMarkButtonOffset(bool AHasApplicationButton, bool ABelow);
	virtual int __fastcall GetQuickAccessToolbarOverrideWidth(bool AHasApplicationButton, bool AUseAeroGlass);
	virtual int __fastcall GetQuickAccessToolbarRightIndent(bool AHasApplicationButton);
	virtual System::UnicodeString __fastcall GetSkinName(void);
	virtual int __fastcall GetStatusBarSeparatorSize(void);
	virtual System::Types::TRect __fastcall GetWindowBordersWidth(bool AHasStatusBar);
	virtual bool __fastcall NeedDrawGroupScrollArrow(void);
	virtual bool __fastcall UseRoundedWindowCorners(void);
	__property Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* Painter = {read=FPainter};
	__property System::UnicodeString SkinName = {read=GetSkinName};
	__property bool UseSkins = {read=GetUseSkins, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinRibbonPainter(void) { }
	
};


class DELPHICLASS TdxSkinRibbon2010Painter;
class PASCALIMPLEMENTATION TdxSkinRibbon2010Painter : public TdxSkinRibbonPainter
{
	typedef TdxSkinRibbonPainter inherited;
	
protected:
	virtual Dxskinscore::TdxSkinElement* __fastcall GetApplicationButtonElement(void);
	virtual Dxribbonskins::TdxRibbonStyle __fastcall GetStyle(void);
	
public:
	virtual bool __fastcall ExtendCaptionAreaOnTabs(void);
	virtual System::Types::TRect __fastcall GetApplicationMenuContentOffset(const System::Types::TRect &ATabsBounds);
	virtual System::Types::TRect __fastcall GetPartContentOffsets(int APart);
public:
	/* TdxSkinRibbonPainter.Create */ inline __fastcall virtual TdxSkinRibbon2010Painter(Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* APainter) : TdxSkinRibbonPainter(APainter) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinRibbon2010Painter(void) { }
	
};


class DELPHICLASS TdxSkinRibbon2013Painter;
class PASCALIMPLEMENTATION TdxSkinRibbon2013Painter : public TdxSkinRibbon2010Painter
{
	typedef TdxSkinRibbon2010Painter inherited;
	
protected:
	virtual void __fastcall DrawBackstageViewBorders(HDC DC, const System::Types::TRect &R, const System::Types::TRect &ABordersWidth, bool AIsActive);
	virtual Dxribbonskins::TdxRibbonStyle __fastcall GetStyle(void);
	
public:
	virtual void __fastcall DrawBackstageViewMenuBackground(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawBackstageViewMenuHeader(HDC DC, const System::Types::TRect &R, Dxribbonskins::TdxRibbonColorSchemeAccent AColorSchemeAccent);
	virtual void __fastcall DrawFormBorders(HDC DC, const System::Types::TRect &ABordersWidth, const Dxribbonskins::TdxRibbonFormInfo &AInfo);
	virtual void __fastcall DrawFormCaption(HDC DC, const System::Types::TRect &R, const Dxribbonskins::TdxRibbonFormInfo &AInfo);
	virtual System::Types::TRect __fastcall GetPartContentOffsets(int APart);
public:
	/* TdxSkinRibbonPainter.Create */ inline __fastcall virtual TdxSkinRibbon2013Painter(Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* APainter) : TdxSkinRibbon2010Painter(APainter) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinRibbon2013Painter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinsdxribbonpainter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDXRIBBONPAINTER)
using namespace Dxskinsdxribbonpainter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdxribbonpainterHPP
