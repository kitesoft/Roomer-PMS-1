// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDockControlXPView.pas' rev: 24.00 (Win32)

#ifndef DxdockcontrolxpviewHPP
#define DxdockcontrolxpviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxDockControl.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdockcontrolxpview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDockControlXPPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDockControlXPPainter : public Dxdockcontrol::TdxDockControlPainter
{
	typedef Dxdockcontrol::TdxDockControlPainter inherited;
	
protected:
	virtual bool __fastcall NeedRedrawOnResize(void);
	
public:
	__classmethod virtual bool __fastcall HasLookAndFeelStyle(Cxlookandfeelpainters::TcxLookAndFeelStyle AStyle);
	virtual bool __fastcall CanVerticalCaption(void);
	virtual System::Types::TSize __fastcall GetCaptionButtonSize(void);
	virtual int __fastcall GetCaptionHeight(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive);
	virtual void __fastcall DrawCaptionSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawCaptionText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive);
	virtual void __fastcall DrawCaptionCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsActive, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionHideButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive, bool IsSwitched, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawCaptionMaximizeButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool IsActive, bool IsSwitched, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawClient(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawHideBar(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarButtonBackground(Cxgraphics::TcxCanvas* ACanvas, Dxdockcontrol::TdxDockSiteHideBarButton* AButton, Dxdockcontrol::TdxAutoHidePosition APosition);
	virtual void __fastcall DrawHideBarScrollButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TcxArrowDirection AArrow);
	virtual System::Types::TSize __fastcall GetHideBarScrollButtonSize(void);
public:
	/* TdxDockControlPainter.Create */ inline __fastcall virtual TdxDockControlXPPainter(Dxdockcontrol::TdxCustomDockControl* ADockControl) : Dxdockcontrol::TdxDockControlPainter(ADockControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockControlXPPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdockcontrolxpview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDOCKCONTROLXPVIEW)
using namespace Dxdockcontrolxpview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdockcontrolxpviewHPP
