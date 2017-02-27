// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinscxPCPainter.pas' rev: 24.00 (Win32)

#ifndef DxskinscxpcpainterHPP
#define DxskinscxpcpainterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxPCPainters.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <cxPCPaintersFactory.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinscxpcpainter
{
//-- type declarations -------------------------------------------------------
enum TcxPCSkinIndents : unsigned char { siFar, siNear, siSelectedDownGrow, siHorzGrow, siVertGrow, siDownGrow, siDownGrowBottomRight, siSelectedDownGrowBottomRight };

class DELPHICLASS TcxPCSkinPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCSkinPainter : public Cxpcpainters::TcxPCTabsPainter
{
	typedef Cxpcpainters::TcxPCTabsPainter inherited;
	
private:
	Dxskinscore::TdxSkinElementCache* FFrameContentCache;
	bool __fastcall GetNeedDrawTabBitmapBackground(void);
	Dxskinscore::TdxSkinElementState __fastcall GetTabState(Cxpc::TcxTabViewInfo* ATabViewInfo);
	void __fastcall InternalCorrectCustomTabRect(Cxpc::TcxTabPosition APosition, System::Types::TRect &ARect);
	void __fastcall InternalCorrectMainTabRect(Cxpc::TcxTabPosition APosition, System::Types::TRect &ARect);
	Dxskinscore::TdxSkinElement* __fastcall GetHeaderButton(void);
	
protected:
	virtual int __fastcall CalculateTabNormalWidth(Cxpc::TcxTabViewInfo* ATabViewInfo);
	virtual void __fastcall CorrectTabNormalWidth(int &AValue);
	virtual Dxskinscore::TdxSkinElement* __fastcall GetButtonHorz(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall GetButtonVert(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall GetFrameContent(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall GetHeader(void);
	virtual int __fastcall GetIndentByIndex(TcxPCSkinIndents AType);
	bool __fastcall GetSkinPainterData(Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* &AData);
	virtual Cxgraphics::TcxRegion* __fastcall GetTabClipRgn(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetTabCorrection(int ATabVisibleIndex);
	virtual void __fastcall DoPaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawNativeTabBackground(HDC DC, Cxpc::TcxTabSheet* ATab);
	virtual void __fastcall FillTabPaneContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetButtonDrawOffsets(void);
	virtual int __fastcall GetButtonWidth(Cxpc::TcxPCNavigatorButton Button);
	virtual System::Uitypes::TColor __fastcall GetFreeSpaceColor(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	virtual int __fastcall GetNativeButtonHeight(void);
	virtual int __fastcall GetNativeButtonsDistance(Cxpc::TcxPCNavigatorButton AButton1, Cxpc::TcxPCNavigatorButton AButton2);
	virtual System::Types::TRect __fastcall GetNativeContentOffset(void);
	virtual System::Types::TRect __fastcall GetTabButtonGlyphOffset(void);
	virtual Cxpc::TcxPCWOffset __fastcall GetTabContentWOffset(int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetTabFocusRect(const System::Types::TRect &ATabBounds);
	virtual int __fastcall GetTabNormalContentOffset(int ATabVisibleIndex);
	virtual Cxpc::TcxPCDistance __fastcall GetTabsNormalDistance(void);
	virtual Cxpc::TcxPCTabsPosition __fastcall GetTabsPosition(void);
	virtual int __fastcall GetTabTextNormalWidth(int ATabVisibleIndex);
	virtual System::Uitypes::TColor __fastcall GetTextColor(int ATabVisibleIndex);
	virtual void __fastcall InternalDrawText(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString ACaption, const System::Types::TRect &ARect, int ATabVisibleIndex);
	virtual void __fastcall InternalPaintFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall IsEnableHotTrack(void);
	virtual bool __fastcall IsNativePainting(void);
	bool __fastcall IsSkinAvailable(void);
	virtual bool __fastcall IsTabBorderThick(int ATabVisibleIndex);
	virtual bool __fastcall NeedDisabledTextShadow(void);
	virtual bool __fastcall NeedDoubleBuffer(void);
	virtual void __fastcall DrawParentBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall PaintButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState, Cxpc::TcxPCNavigatorButton AType);
	virtual void __fastcall PaintHeaderButton(Cxgraphics::TcxCanvas* ACanvas, Cxpc::TcxPCHeaderButtonViewInfo* AButtonInfo);
	virtual void __fastcall PaintNativeTabBackground(HDC DC, int ATabVisibleIndex, const System::Types::TRect &ABounds);
	virtual void __fastcall PaintTabsRegion(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PrepareTabBitmapBackground(Cxgraphics::TcxBitmap* ABitmap, const System::Types::TRect &ARect, Cxpc::TcxTabViewInfo* ATabViewInfo);
	__property Dxskinscore::TdxSkinElement* ButtonHorz = {read=GetButtonHorz};
	__property Dxskinscore::TdxSkinElement* ButtonVert = {read=GetButtonVert};
	__property Dxskinscore::TdxSkinElement* FrameContent = {read=GetFrameContent};
	__property Dxskinscore::TdxSkinElementCache* FrameContentCache = {read=FFrameContentCache};
	__property Dxskinscore::TdxSkinElement* Header = {read=GetHeader};
	__property Dxskinscore::TdxSkinElement* HeaderButton = {read=GetHeaderButton};
	__property int Indents[TcxPCSkinIndents AType] = {read=GetIndentByIndex};
	__property bool NeedDrawTabBitmapBackground = {read=GetNeedDrawTabBitmapBackground, nodefault};
	
public:
	__fastcall virtual TcxPCSkinPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo);
	__fastcall virtual ~TcxPCSkinPainter(void);
	virtual int __fastcall CalculateTabNormalHeight(void);
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxpc::TcxPCDistance cxNullPCDistance;
}	/* namespace Dxskinscxpcpainter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSCXPCPAINTER)
using namespace Dxskinscxpcpainter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinscxpcpainterHPP
