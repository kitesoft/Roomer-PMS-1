// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDockControlNETView.pas' rev: 24.00 (Win32)

#ifndef DxdockcontrolnetviewHPP
#define DxdockcontrolnetviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxDockControl.hpp>	// Pascal unit
#include <dxDockPanel.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdockcontrolnetview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDockControlNETPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDockControlNETPainter : public Dxdockcontrol::TdxDockControlPainter
{
	typedef Dxdockcontrol::TdxDockControlPainter inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetNETBackColor(void);
	virtual System::Uitypes::TColor __fastcall GetCaptionColor(bool IsActive);
	virtual System::Uitypes::TColor __fastcall GetCaptionFontColor(bool IsActive);
	virtual System::Uitypes::TColor __fastcall GetHideBarColor(void);
	
public:
	__classmethod virtual bool __fastcall HasLookAndFeelStyle(Cxlookandfeelpainters::TcxLookAndFeelStyle AStyle);
	virtual bool __fastcall CanVerticalCaption(void);
	virtual int __fastcall GetCaptionHeight(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive);
	virtual void __fastcall DrawCaptionText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive);
	virtual void __fastcall DrawCaptionButtonSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsActive, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsActive, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionHideButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive, bool IsSwitched, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionMaximizeButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive, bool IsSwitched, Cxlookandfeelpainters::TcxButtonState AState);
	virtual int __fastcall GetHideBarHeight(void);
	virtual int __fastcall GetHideBarWidth(void);
	virtual void __fastcall DrawHideBar(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonBackground(Cxgraphics::TcxCanvas* ACanvas, Dxdockcontrol::TdxDockSiteHideBarButton* AButton, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarScrollButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TcxArrowDirection AArrow);
public:
	/* TdxDockControlPainter.Create */ inline __fastcall virtual TdxDockControlNETPainter(Dxdockcontrol::TdxCustomDockControl* ADockControl) : Dxdockcontrol::TdxDockControlPainter(ADockControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockControlNETPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdockcontrolnetview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCKCONTROLNETVIEW)
using namespace Dxdockcontrolnetview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdockcontrolnetviewHPP
