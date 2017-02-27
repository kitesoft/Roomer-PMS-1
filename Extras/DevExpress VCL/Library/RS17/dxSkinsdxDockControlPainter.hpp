// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsdxDockControlPainter.pas' rev: 24.00 (Win32)

#ifndef DxskinsdxdockcontrolpainterHPP
#define DxskinsdxdockcontrolpainterHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxDockControl.hpp>	// Pascal unit
#include <dxDockControlXPView.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxDockControlOfficeView.hpp>	// Pascal unit
#include <dxSkinInfo.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxSkinscxPCPainter.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxPCPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdxdockcontrolpainter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDockControlSkinPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDockControlSkinPainter : public Dxdockcontrolxpview::TdxDockControlXPPainter
{
	typedef Dxdockcontrolxpview::TdxDockControlXPPainter inherited;
	
private:
	Dxskinscore::TdxSkinElementCache* FPanelBackgroundCache;
	
protected:
	virtual bool __fastcall DrawCaptionFirst(void);
	virtual System::Uitypes::TColor __fastcall GetCaptionFontColor(bool IsActive);
	virtual System::Types::TRect __fastcall GetCaptionRect(const System::Types::TRect &ARect, bool AIsVertical);
	Dxskinscore::TdxSkinElementState __fastcall GetElementState(bool AActive, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall GetHideBarButtonFontColor(void);
	System::Uitypes::TColor __fastcall GetHideBarButtonFontColorEx(bool AActive);
	bool __fastcall GetSkinPainterData(Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* &AData);
	bool __fastcall DrawCaptionButton(Cxgraphics::TcxCanvas* ACanvas, int AGlyphIndex, const System::Types::TRect &ARect, Dxskinscore::TdxSkinElementState AState);
	bool __fastcall IsWorkingControl(Dxdockcontrol::TdxCustomDockControl* AControl);
	
public:
	__fastcall virtual TdxDockControlSkinPainter(Dxdockcontrol::TdxCustomDockControl* ADockControl);
	__fastcall virtual ~TdxDockControlSkinPainter(void);
	__classmethod virtual Cxpc::TcxPCPainterClass __fastcall GetTabsPainter(Cxpc::TcxPCStyleID ATabsStyle);
	__classmethod virtual bool __fastcall HasLookAndFeelStyle(Cxlookandfeelpainters::TcxLookAndFeelStyle AStyle);
	virtual bool __fastcall CanVerticalCaption(void);
	virtual System::Types::TRect __fastcall GetCaptionContentOffsets(bool AIsVertical);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive);
	virtual void __fastcall DrawCaptionCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsActive, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionHideButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive, bool IsSwitched, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionMaximizeButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive, bool IsSwitched, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawCaptionText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive);
	virtual void __fastcall DrawClient(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual System::Types::TRect __fastcall GetBorderWidths(void);
	virtual System::Types::TSize __fastcall GetCaptionButtonSize(void);
	virtual int __fastcall GetCaptionHeight(void);
	virtual int __fastcall GetCaptionSeparatorSize(void);
	virtual void __fastcall DrawHideBar(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonBackground(Cxgraphics::TcxCanvas* ACanvas, Dxdockcontrol::TdxDockSiteHideBarButton* AButton, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonText(Cxgraphics::TcxCanvas* ACanvas, Dxdockcontrol::TdxCustomDockControl* AControl, const System::Types::TRect &ARect, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonSection(Cxgraphics::TcxCanvas* ACanvas, Dxdockcontrol::TdxDockSiteHideBarButtonSection* AButtonSection, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonSectionSeparator(Cxgraphics::TcxCanvas* ACanvas, Dxdockcontrol::TdxDockSiteHideBarButtonSection* AButtonSection, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarScrollButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TcxArrowDirection AArrow);
	virtual bool __fastcall IsHideBarButtonHotTrackSupports(void);
};

#pragma pack(pop)

class DELPHICLASS TdxDockControlSkinTabPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDockControlSkinTabPainter : public Dxskinscxpcpainter::TcxPCSkinPainter
{
	typedef Dxskinscxpcpainter::TcxPCSkinPainter inherited;
	
private:
	Dxskinscore::TdxSkinElement* __fastcall GetHeaderLine(void);
	System::Types::TRect __fastcall GetHeaderLineRect(void);
	System::Types::TSize __fastcall GetHeaderLineSize(void);
	Dxskinscore::TdxSkinElement* __fastcall GetTabCloseButton(void);
	
protected:
	virtual void __fastcall DoDrawTabCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState);
	void __fastcall DrawHeaderLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawParentBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall FillFreeSpaceArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall InternalPaintFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual Dxskinscore::TdxSkinElement* __fastcall GetButtonHorz(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall GetButtonVert(void);
	virtual System::Types::TSize __fastcall GetCloseButtonSize(void);
	virtual System::Uitypes::TColor __fastcall GetFreeSpaceColor(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall GetHeader(void);
	virtual int __fastcall GetIndentByIndex(Dxskinscxpcpainter::TcxPCSkinIndents AType);
	virtual System::Types::TRect __fastcall GetNativeContentOffset(void);
	virtual System::Uitypes::TColor __fastcall GetTextColor(int ATabVisibleIndex);
	virtual void __fastcall PrepareTabBitmapBackground(Cxgraphics::TcxBitmap* ABitmap, const System::Types::TRect &ARect, Cxpc::TcxTabViewInfo* ATabViewInfo);
	virtual bool __fastcall UseLookAndFeelTabButton(void);
	__property Dxskinscore::TdxSkinElement* HeaderLine = {read=GetHeaderLine};
	__property System::Types::TRect HeaderLineRect = {read=GetHeaderLineRect};
	__property System::Types::TSize HeaderLineSize = {read=GetHeaderLineSize};
	__property Dxskinscore::TdxSkinElement* TabCloseButton = {read=GetTabCloseButton};
public:
	/* TcxPCSkinPainter.Create */ inline __fastcall virtual TdxDockControlSkinTabPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : Dxskinscxpcpainter::TcxPCSkinPainter(AViewInfo) { }
	/* TcxPCSkinPainter.Destroy */ inline __fastcall virtual ~TdxDockControlSkinTabPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinsdxdockcontrolpainter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDXDOCKCONTROLPAINTER)
using namespace Dxskinsdxdockcontrolpainter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdxdockcontrolpainterHPP
