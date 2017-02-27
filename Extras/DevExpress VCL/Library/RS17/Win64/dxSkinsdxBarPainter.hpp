// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsdxBarPainter.pas' rev: 24.00 (Win64)

#ifndef DxskinsdxbarpainterHPP
#define DxskinsdxbarpainterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxScreenTip.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdxbarpainter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarSkinPainter;
class PASCALIMPLEMENTATION TdxBarSkinPainter : public Dxbar::TdxBarPainter
{
	typedef Dxbar::TdxBarPainter inherited;
	
private:
	Dxskinscore::TdxSkinElementCacheList* FBarElementCacheList;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FSkinPainter;
	Dxskinscore::TdxSkinElement* __fastcall GetBar(bool AIsVertical);
	Dxskinscore::TdxSkinElement* __fastcall GetBarCustomize(bool AIsVertical);
	Dxskinscore::TdxSkinColor* __fastcall GetBarDisabledTextColor(void);
	Dxskinscore::TdxSkinElement* __fastcall GetBarDrag(bool AIsVertical);
	Dxskinscore::TdxSkinElement* __fastcall GetBarSeparator(bool AIsVertical);
	Dxskinscore::TdxSkinElement* __fastcall GetDock(void);
	Dxskinscore::TdxSkinElement* __fastcall GetDockControlWindowButton(void);
	Dxskinscore::TdxSkinElement* __fastcall GetDockControlWindowButtonGlyph(void);
	Dxskinscore::TdxSkinElement* __fastcall GetFloatingBar(void);
	Dxskinscore::TdxSkinElement* __fastcall GetItemSeparator(void);
	Dxskinscore::TdxSkinElement* __fastcall GetLinkBorderPainter(void);
	Dxskinscore::TdxSkinElement* __fastcall GetLinkSelected(void);
	Dxskinscore::TdxSkinElement* __fastcall GetMainMenu(bool AIsVertical);
	Dxskinscore::TdxSkinElement* __fastcall GetMainMenuCustomize(bool AIsVertical);
	Dxskinscore::TdxSkinElement* __fastcall GetMainMenuDrag(void);
	Dxskinscore::TdxSkinElement* __fastcall GetMainMenuLinkSelected(void);
	Dxskinscore::TdxSkinElement* __fastcall GetMDIButton(Dxbar::TdxBarMDIButton AButton);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenu(void);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenuCheck(void);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenuExpandButton(void);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenuLinkSelected(void);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenuSeparator(void);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenuSideStrip(void);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenuSideStripNonRecent(void);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenuSplitButton(void);
	Dxskinscore::TdxSkinElement* __fastcall GetPopupMenuSplitButton2(void);
	Dxskinscore::TdxSkinElement* __fastcall GetStatusBar(void);
	Dxskinscore::TdxSkinColor* __fastcall GetScreenTipItem(void);
	Dxskinscore::TdxSkinElement* __fastcall GetScreenTipSeparator(void);
	Dxskinscore::TdxSkinColor* __fastcall GetScreenTipTitleItem(void);
	Dxskinscore::TdxSkinElement* __fastcall GetScreenTipWindow(void);
	bool __fastcall GetSkinPainterData(Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* &AData);
	bool __fastcall DrawSkinElement(Dxskinscore::TdxSkinElement* AElement, HDC DC, const System::Types::TRect &ARect, int AImageIndex = 0x0, Dxskinscore::TdxSkinElementState AState = (Dxskinscore::TdxSkinElementState)(0x0));
	bool __fastcall DrawSkinElementContent(Dxskinscore::TdxSkinElement* AElement, HDC DC, const System::Types::TRect &ARect, int AImageIndex = 0x0, Dxskinscore::TdxSkinElementState AState = (Dxskinscore::TdxSkinElementState)(0x0));
	bool __fastcall DrawSkinElementBorders(Dxskinscore::TdxSkinElement* AElement, HDC DC, const System::Types::TRect &ARect, int AImageIndex = 0x0, Dxskinscore::TdxSkinElementState AState = (Dxskinscore::TdxSkinElementState)(0x0));
	void __fastcall DrawSkinElementParentBackground(HDC DC, const System::Types::TRect &R, Dxbar::TCustomdxBarControl* ABarControl, Dxskinscore::TdxSkinElement* AElement);
	System::Uitypes::TColor __fastcall GetSkinEditorsBackgroundColor(Cxlookandfeelpainters::TcxEditStateColorKind AState);
	System::Uitypes::TColor __fastcall GetSkinEditorsTextColor(Cxlookandfeelpainters::TcxEditStateColorKind AState);
	System::Types::TSize __fastcall GetSkinElementSize(Dxskinscore::TdxSkinElement* ASkinElement);
	Dxskinscore::TdxSkinColor* __fastcall GetSkinElementTextColorHot(Dxskinscore::TdxSkinElement* ASkinElement);
	Dxskinscore::TdxSkinElement* __fastcall GetBarElement(Dxbar::TCustomdxBarControl* ABarControl)/* overload */;
	Dxskinscore::TdxSkinElement* __fastcall GetBarElement(Dxbar::TCustomdxBarControl* ABarControl, bool AVertical)/* overload */;
	Dxskinscore::TdxSkinElement* __fastcall GetBarMarkElement(bool AMainMenu, bool AVertical);
	Dxskinscore::TdxSkinElement* __fastcall GetTextColorElement(Dxbar::TCustomdxBarControl* ABarControl);
	bool __fastcall IsBarElementSkinned(Dxbar::TCustomdxBarControl* ABarControl);
	void __fastcall DrawArrowButtonElement(Dxskinscore::TdxSkinElement* AElement, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, int AImageIndex = 0x0, Dxskinscore::TdxSkinElementState AState = (Dxskinscore::TdxSkinElementState)(0x0));
	void __fastcall DrawFloatingBarCaptionButton(HDC DC, System::Types::TRect &ARect, int AContentType, Dxbar::TdxBarMarkState AState);
	void __fastcall InternalDrawDockedBarBackground(Dxbar::TdxBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AClientArea);
	Dxskinscore::TdxSkinElementState __fastcall ButtonLikeControlGetState(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams);
	bool __fastcall ButtonLikeDrawArrowFadingElement(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams, System::Types::TRect &R);
	bool __fastcall ButtonLikeDrawFadingElement(Dxbar::TdxBarItemControl* ABarItemControl, HDC DC, const System::Types::TRect &R, bool AIsSplit);
	
protected:
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	bool __fastcall BarMarkIsOpaque(void);
	void __fastcall DrawBarMarkState(Dxbar::TdxBarControl* ABarControl, HDC DC, const System::Types::TRect &R, Dxbar::TdxBarMarkState AState);
	void __fastcall DrawButtonBackground(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams);
	virtual System::Uitypes::TColor __fastcall GetDefaultEnabledTextColor(Dxbar::TdxBarItemControl* ABarItemControl, bool ASelected, bool AFlat);
	virtual void __fastcall GetDisabledTextColors(Dxbar::TdxBarItemControl* ABarItemControl, bool ASelected, bool AFlat, System::Uitypes::TColor &AColor1, System::Uitypes::TColor &AColor2);
	__classmethod virtual bool __fastcall UseTextColorForItemArrow();
	virtual void __fastcall DrawGlyphEmptyImage(Dxbar::TdxBarItemControl* ABarItemControl, HDC DC, System::Types::TRect &R, Dxbar::TdxBarPaintType APaintType, bool ADown);
	virtual void __fastcall DrawGlyphBorder(Dxbar::TdxBarItemControl* ABarItemControl, HDC DC, HBRUSH ABrush, bool NeedBorder, System::Types::TRect &R, Dxbar::TdxBarPaintType PaintType, bool IsGlyphEmpty, bool Selected, bool Down, bool DrawDowned, bool ADroppedDown, bool IsSplit);
	virtual unsigned __fastcall BarCaptionColor(Dxbar::TdxBarControl* ABarControl);
	__classmethod virtual bool __fastcall NeedDoubleBuffer();
	__classmethod virtual void __fastcall BarOffsetFloatingBarCaption(Dxbar::TdxBarControl* ABarControl, int &X, System::Types::TRect &R);
	virtual void __fastcall BarDrawGrip(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &R, HBRUSH AToolbarBrush);
	virtual void __fastcall BarDrawMarkBackground(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &ItemRect, HBRUSH AToolbarBrush);
	virtual void __fastcall SubMenuControlDrawMarkSelection(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, HDC ADC, const System::Types::TRect &AMarkRect);
	virtual Dxbar::TdxBarCustomHintViewInfo* __fastcall CreateHintViewInfo(Dxbar::TdxBarManager* ABarManager, System::UnicodeString AHintText, const System::UnicodeString AShortCut, Dxscreentip::TdxScreenTip* AScreenTip);
	__property Dxskinscore::TdxSkinElement* Bar[bool AIsVertical] = {read=GetBar};
	__property Dxskinscore::TdxSkinElement* BarCustomize[bool AIsVertical] = {read=GetBarCustomize};
	__property Dxskinscore::TdxSkinColor* BarDisabledTextColor = {read=GetBarDisabledTextColor};
	__property Dxskinscore::TdxSkinElement* BarDrag[bool AIsVertical] = {read=GetBarDrag};
	__property Dxskinscore::TdxSkinElementCacheList* BarElementCacheList = {read=FBarElementCacheList};
	__property Dxskinscore::TdxSkinElement* BarSeparator[bool AIsVertical] = {read=GetBarSeparator};
	__property Dxskinscore::TdxSkinElement* Dock = {read=GetDock};
	__property Dxskinscore::TdxSkinElement* DockControlWindowButton = {read=GetDockControlWindowButton};
	__property Dxskinscore::TdxSkinElement* DockControlWindowButtonGlyph = {read=GetDockControlWindowButtonGlyph};
	__property Dxskinscore::TdxSkinElement* FloatingBar = {read=GetFloatingBar};
	__property Dxskinscore::TdxSkinElement* ItemSeparator = {read=GetItemSeparator};
	__property Dxskinscore::TdxSkinElement* LinkBorderPainter = {read=GetLinkBorderPainter};
	__property Dxskinscore::TdxSkinElement* LinkSelected = {read=GetLinkSelected};
	__property Dxskinscore::TdxSkinElement* MainMenu[bool AIsVertical] = {read=GetMainMenu};
	__property Dxskinscore::TdxSkinElement* MainMenuCustomize[bool AIsVertical] = {read=GetMainMenuCustomize};
	__property Dxskinscore::TdxSkinElement* MainMenuDrag = {read=GetMainMenuDrag};
	__property Dxskinscore::TdxSkinElement* MainMenuLinkSelected = {read=GetMainMenuLinkSelected};
	__property Dxskinscore::TdxSkinElement* MDIButton[Dxbar::TdxBarMDIButton Button] = {read=GetMDIButton};
	__property Dxskinscore::TdxSkinElement* PopupMenu = {read=GetPopupMenu};
	__property Dxskinscore::TdxSkinElement* PopupMenuCheck = {read=GetPopupMenuCheck};
	__property Dxskinscore::TdxSkinElement* PopupMenuExpandButton = {read=GetPopupMenuExpandButton};
	__property Dxskinscore::TdxSkinElement* PopupMenuLinkSelected = {read=GetPopupMenuLinkSelected};
	__property Dxskinscore::TdxSkinElement* PopupMenuSeparator = {read=GetPopupMenuSeparator};
	__property Dxskinscore::TdxSkinElement* PopupMenuSideStrip = {read=GetPopupMenuSideStrip};
	__property Dxskinscore::TdxSkinElement* PopupMenuSideStripNonRecent = {read=GetPopupMenuSideStripNonRecent};
	__property Dxskinscore::TdxSkinElement* PopupMenuSplitButton = {read=GetPopupMenuSplitButton};
	__property Dxskinscore::TdxSkinElement* PopupMenuSplitButton2 = {read=GetPopupMenuSplitButton2};
	__property Dxskinscore::TdxSkinColor* ScreenTipItem = {read=GetScreenTipItem};
	__property Dxskinscore::TdxSkinElement* ScreenTipSeparator = {read=GetScreenTipSeparator};
	__property Dxskinscore::TdxSkinColor* ScreenTipTitleItem = {read=GetScreenTipTitleItem};
	__property Dxskinscore::TdxSkinElement* ScreenTipWindow = {read=GetScreenTipWindow};
	__property Dxskinscore::TdxSkinElement* StatusBar = {read=GetStatusBar};
	
public:
	__fastcall virtual TdxBarSkinPainter(NativeUInt AData);
	__fastcall virtual ~TdxBarSkinPainter(void);
	__classmethod virtual bool __fastcall IsFlatGlyphImage();
	__classmethod virtual bool __fastcall IsFlatItemText();
	virtual bool __fastcall IsCustomSelectedTextColorExists(Dxbar::TdxBarItemControl* ABarItemControl);
	__classmethod virtual int __fastcall GetPopupWindowBorderWidth();
	virtual void __fastcall DrawItemBackgroundInSubMenu(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams, System::Types::TRect &R);
	virtual int __fastcall GripperSize(Dxbar::TdxBarControl* ABarControl);
	__classmethod virtual int __fastcall BorderSizeX();
	__classmethod virtual int __fastcall BorderSizeY();
	virtual int __fastcall FingersSize(Dxbar::TdxBarControl* ABarControl);
	__classmethod virtual int __fastcall SubMenuBeginGroupIndent();
	__classmethod virtual bool __fastcall BarCaptionTransparent();
	virtual int __fastcall BarBeginGroupSize(void);
	virtual void __fastcall BarBorderPaintSizes(Dxbar::TdxBarControl* ABarControl, System::Types::TRect &R);
	virtual void __fastcall BarBorderSizes(Dxbar::TdxBar* ABar, Dxbar::TdxBarDockingStyle AStyle, System::Types::TRect &R);
	virtual System::Types::TRect __fastcall BarMarkItemRect(Dxbar::TdxBarControl* ABarControl);
	virtual System::Types::TRect __fastcall BarMarkRect(Dxbar::TdxBarControl* ABarControl);
	virtual int __fastcall MarkSizeX(Dxbar::TdxBarControl* ABarControl);
	virtual System::Types::TRect __fastcall StatusBarBorderOffsets(void);
	__classmethod virtual int __fastcall StatusBarTopBorderSize();
	virtual System::Types::TSize __fastcall StatusBarGripSize(Dxbar::TdxBarManager* ABarManager);
	virtual void __fastcall BarCaptionFillBackground(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &R, HBRUSH AToolbarBrush);
	virtual void __fastcall BarDrawBeginGroup(Dxbar::TCustomdxBarControl* ABarControl, HDC DC, System::Types::TRect &ABeginGroupRect, HBRUSH AToolbarBrush, bool AHorz);
	virtual void __fastcall BarDrawCloseButton(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &R);
	virtual void __fastcall BarDrawDockedBarBorder(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &R, HBRUSH AToolbarBrush);
	virtual void __fastcall BarDrawFloatingBarBorder(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &R, System::Types::TRect &CR, HBRUSH AToolbarBrush);
	virtual void __fastcall BarDrawFloatingBarCaption(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &R, System::Types::TRect &CR, HBRUSH AToolbarBrush);
	virtual void __fastcall BarDrawMDIButton(Dxbar::TdxBarControl* ABarControl, Dxbar::TdxBarMDIButton AButton, int AState, HDC DC, System::Types::TRect &R);
	virtual void __fastcall BarDrawStatusBarBorder(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &R, HBRUSH AToolbarBrush);
	virtual bool __fastcall BarLinkedOwnerHasShadow(Dxbar::TCustomdxBarControl* ABarControl);
	virtual void __fastcall BarMarkRectInvalidate(Dxbar::TdxBarControl* ABarControl);
	virtual void __fastcall StatusBarFillBackground(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &ADestR, System::Types::TRect &ASourceR, System::Types::TRect &AWholeR, HBRUSH ABrush, System::Uitypes::TColor AColor);
	virtual unsigned __fastcall EditGetDisabledBkColor(Dxbar::TdxBarCustomEditControl* ABarItemControl);
	virtual unsigned __fastcall EditGetDisabledTextColor(void);
	virtual unsigned __fastcall EditGetEnabledBkColor(Dxbar::TdxBarCustomEditControl* ABarItemControl);
	virtual unsigned __fastcall EditGetEnabledTextColor(void);
	virtual void __fastcall DockControlFillBackground(Dxbar::TdxDockControl* ADockControl, HDC DC, System::Types::TRect &ADestR, System::Types::TRect &ASourceR, System::Types::TRect &AWholeR, HBRUSH ABrush, System::Uitypes::TColor AColor);
	__classmethod virtual bool __fastcall IsNativeBackground();
	__classmethod virtual int __fastcall BarDockedGetRowIndent();
	virtual int __fastcall ComboBoxArrowWidth(Dxbar::TCustomdxBarControl* ABarControl, int cX);
	virtual void __fastcall BarDrawDockedBackground(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &ADestR, System::Types::TRect &ASourceR, HBRUSH ABrush, System::Uitypes::TColor AColor);
	virtual void __fastcall BarDrawFloatingBackground(Dxbar::TCustomdxBarControl* ABarControl, HDC DC, System::Types::TRect &ADestR, System::Types::TRect &ASourceR, HBRUSH ABrush, System::Uitypes::TColor AColor);
	__classmethod virtual void __fastcall BarDrawOwnerLink(Dxbar::TCustomdxBarControl* ABarControl, HDC DC);
	__classmethod virtual int __fastcall DropDownListBoxBorderSize();
	virtual void __fastcall DropDownListBoxDrawBorder(HDC DC, System::Uitypes::TColor AColor, System::Types::TRect &ARect);
	__classmethod virtual bool __fastcall SubMenuControlHasBand();
	__classmethod virtual int __fastcall SubMenuControlArrowsOffset();
	virtual System::Types::TRect __fastcall SubMenuControlBeginGroupRect(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, Dxbar::TdxBarItemControl* AControl, const System::Types::TRect &AItemRect);
	virtual int __fastcall SubMenuControlBeginGroupSize(void);
	virtual void __fastcall SubMenuControlCalcDrawingConsts(Cxgraphics::TcxCanvas* ACanvas, int ATextSize, /* out */ int &AMenuArrowWidth, /* out */ int &AMarkSize);
	__classmethod virtual int __fastcall SubMenuControlDetachCaptionAreaSize(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl);
	__classmethod virtual void __fastcall SubMenuControlOffsetDetachCaptionRect(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, System::Types::TRect &R);
	__classmethod virtual int __fastcall SubMenuControlGetItemTextIndent(Dxbar::TdxBarItemControlDrawParams* const ADrawParams);
	virtual void __fastcall SubMenuControlDrawBeginGroup(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, Dxbar::TdxBarItemControl* AControl, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABeginGroupRect);
	virtual void __fastcall SubMenuControlDrawBorder(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, HDC DC, System::Types::TRect &R);
	virtual void __fastcall SubMenuControlDrawClientBorder(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, HDC DC, const System::Types::TRect &R, HBRUSH ABrush);
	virtual void __fastcall SubMenuControlDrawBackground(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, HBRUSH ABrush, System::Uitypes::TColor AColor);
	virtual void __fastcall SubMenuControlDrawDetachCaption(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, HDC DC, System::Types::TRect &R);
	virtual void __fastcall SubMenuControlDrawMarkContent(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, HDC DC, System::Types::TRect &R, bool ASelected);
	virtual void __fastcall SubMenuControlDrawSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	void __fastcall SubMenuControlDrawSeparatorBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall BarDrawMark(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &MarkR);
	virtual void __fastcall BarDrawMarkElements(Dxbar::TdxBarControl* ABarControl, HDC DC, System::Types::TRect &ItemRect);
	__classmethod virtual bool __fastcall IsQuickControlPopupOnRight();
	virtual bool __fastcall IsButtonControlArrowBackgroundOpaque(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams);
	virtual bool __fastcall IsButtonControlArrowDrawSelected(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams);
	virtual bool __fastcall IsDropDownRepaintNeeded(void);
	__classmethod virtual void __fastcall CorrectButtonControlDefaultHeight(int &DefaultHeight);
	__classmethod virtual void __fastcall CorrectButtonControlDefaultWidth(int &DefaultWidth);
	virtual void __fastcall DrawButtonControlArrowBackground(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams, System::Types::TRect &R1, HBRUSH ABrush);
	virtual bool __fastcall ColorComboHasCompleteFrame(void);
	virtual System::Types::TRect __fastcall GetCustomColorButtonIndents(Dxbar::TdxBarPaintType APaintType);
	virtual int __fastcall GetCustomColorButtonWidth(Dxbar::TdxBarPaintType APaintType, const System::Types::TRect &ARect);
	virtual void __fastcall ColorComboDrawCustomButton(Dxbar::TdxBarColorComboControlDrawParams* const ADrawParams, System::Types::TRect &ARect);
	virtual void __fastcall ColorComboDrawCustomButtonAdjacentZone(Dxbar::TdxBarColorComboControlDrawParams* const ADrawParams, System::Types::TRect &ARect);
	__classmethod virtual bool __fastcall EditControlCaptionBackgroundIsOpaque(Dxbar::TdxBarEditLikeControlDrawParams* const ADrawParams);
	__classmethod virtual bool __fastcall EditControlCaptionRightIndentIsOpaque(Dxbar::TdxBarEditLikeControlDrawParams* const ADrawParams);
	__classmethod virtual System::Types::TRect __fastcall EditControlBorderOffsets(Dxbar::TdxBarPaintType APaintType);
	virtual void __fastcall EditControlDrawBackground(Dxbar::TdxBarEditLikeControlDrawParams* const ADrawParams);
	virtual void __fastcall EditControlDrawBorder(Dxbar::TdxBarEditLikeControlDrawParams* const ADrawParams, System::Types::TRect &ARect);
	virtual void __fastcall EditControlDrawSelectionFrame(Dxbar::TdxBarEditLikeControlDrawParams* const ADrawParams, const System::Types::TRect &ARect);
	__classmethod virtual int __fastcall EditControlCaptionAbsoluteLeftIndent(Dxbar::TdxBarEditLikeControlDrawParams* const ADrawParams);
	__classmethod virtual void __fastcall CustomComboDrawItem(Dxbar::TdxBarCustomCombo* ABarCustomCombo, Vcl::Graphics::TCanvas* ACanvas, int AIndex, System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState, bool AInteriorIsDrawing);
	__classmethod virtual int __fastcall ComboControlArrowOffset();
	virtual void __fastcall ComboControlDrawArrowButton(Dxbar::TdxBarEditLikeControlDrawParams* const ADrawParams, System::Types::TRect &ARect, bool AInClientArea);
	__classmethod virtual bool __fastcall IsDateNavigatorFlat();
	virtual System::Uitypes::TColor __fastcall DateNavigatorHeaderColor(void);
	virtual void __fastcall DateNavigatorDrawButton(Dxbar::TdxBarItem* ABarItem, HDC DC, System::Types::TRect &R, const System::UnicodeString ACaption, bool APressed);
	virtual bool __fastcall InPlaceSubItemControlIsArrowSelected(Dxbar::TdxBarInPlaceSubItemControlDrawParams* const ADrawParams);
	virtual void __fastcall InPlaceSubItemControlDrawBackground(Dxbar::TdxBarInPlaceSubItemControlDrawParams* const ADrawParams, System::Types::TRect &ARect);
	virtual int __fastcall GetSpinEditButtonWidth(Dxbar::TdxBarPaintType APaintType, const System::Types::TRect &ARect);
	virtual System::Types::TRect __fastcall GetSpinEditButtonIndents(Dxbar::TdxBarPaintType APaintType);
	virtual void __fastcall SpinEditControlDrawButton(Dxbar::TdxBarSpinEditDrawParams* const ADrawParams, System::Types::TRect &ARect, int AButtonIndex);
	virtual void __fastcall SpinEditControlDrawButtonsAdjacentZone(Dxbar::TdxBarSpinEditDrawParams* const ADrawParams, const System::Types::TRect &ARect);
	virtual void __fastcall CalculateSpinEditParts(Dxbar::TdxBarSpinEditDrawParams* const ADrawParams, System::Types::TRect *AParts, const int AParts_Size, System::Types::TRect *AAreaParts, const int AAreaParts_Size);
	virtual void __fastcall SpinEditCorrectFrameRect(Dxbar::TdxBarItemControlDrawParams* const ADrawParams, System::Types::TRect &ARect);
	virtual int __fastcall ProgressControlBarHeight(Dxbar::TdxBarItemControl* ABarItemControl);
	__classmethod virtual int __fastcall ProgressControlIndent(Dxbar::TdxBarItemControlDrawParams* const ADrawParams);
	virtual void __fastcall ProgressControlDrawBackground(Dxbar::TdxBarItemControlDrawParams* const ADrawParams, System::Types::TRect &BarR);
	virtual void __fastcall ProgressControlFillContent(Dxbar::TdxBarItemControlDrawParams* const ADrawParams, const System::Types::TRect &R, HBRUSH ABarBrush);
	virtual System::Types::TRect __fastcall StaticControlGetBorderOffsets(Dxbar::TCustomdxBarControl* AParent, Dxbar::TdxBarStaticBorderStyle ABorderStyle);
	virtual void __fastcall DrawStaticBackground(Dxbar::TdxBarStaticLikeControlDrawParams* const ADrawParams, System::Types::TRect &ARect);
	virtual void __fastcall DrawStaticBorder(Dxbar::TdxBarStaticLikeControlDrawParams* const ADrawParams, System::Types::TRect &ARect);
	virtual int __fastcall SubMenuGetSeparatorSize(void);
	virtual void __fastcall SeparatorControlGetTextColors(Dxbar::TdxBarItemControl* ABarItemControl, bool AEnabled, bool ASelected, bool AFlat, System::Uitypes::TColor &AColor1, System::Uitypes::TColor &AColor2);
	virtual void __fastcall DrawSeparatorGlyphAndCaption(Dxbar::TdxBarSeparatorControlDrawParams* const ADrawParams, const System::Types::TRect &ARect);
	virtual void __fastcall DropDownGalleryDrawBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawBorder(Dxbar::TdxBarSubMenuControl* ABarSubMenuControl, HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawBottomSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawBottomSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawBottomVerticalSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawFilterband(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawGroupHeaderBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawItem(HDC DC, const System::Types::TRect &R, int AState);
	virtual void __fastcall DropDownGalleryDrawScrollBarBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawTopSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawTopSizingBand(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DropDownGalleryDrawTopVerticalSizeGrip(HDC DC, const System::Types::TRect &R);
	virtual int __fastcall DropDownGalleryGetClientBorderSize(void);
	virtual System::Types::TRect __fastcall DropDownGalleryGetContentOffsets(int APart);
	virtual System::Uitypes::TColor __fastcall DropDownGalleryGetGroupHeaderTextColor(void);
	virtual int __fastcall DropDownGalleryGetNCBorderSize(void);
	virtual System::Uitypes::TColor __fastcall DropDownGalleryGetPartColor(int APart, int AState = 0x0);
private:
	void *__IdxFadingPainterHelper;	/* Dxbar::IdxFadingPainterHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B97FA518-6C2E-4219-9430-19546EF91A1F}
	operator Dxbar::_di_IdxFadingPainterHelper()
	{
		Dxbar::_di_IdxFadingPainterHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxFadingPainterHelper*(void) { return (Dxbar::IdxFadingPainterHelper*)&__IdxFadingPainterHelper; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinsdxbarpainter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDXBARPAINTER)
using namespace Dxskinsdxbarpainter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdxbarpainterHPP
