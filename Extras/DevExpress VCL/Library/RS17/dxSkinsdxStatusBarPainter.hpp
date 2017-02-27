// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsdxStatusBarPainter.pas' rev: 24.00 (Win32)

#ifndef DxskinsdxstatusbarpainterHPP
#define DxskinsdxstatusbarpainterHPP

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
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <dxStatusBar.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdxstatusbarpainter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxStatusBarSkinPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStatusBarSkinPainter : public Dxstatusbar::TdxStatusBarStandardPainter
{
	typedef Dxstatusbar::TdxStatusBarStandardPainter inherited;
	
protected:
	__classmethod System::Types::TRect __fastcall CheckStatusBarRect(Dxskinscore::TdxSkinElement* AFormStatusBar, const System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawContainerControl(Dxstatusbar::TdxStatusBarContainerPanelStyle* APanelStyle);
	__classmethod bool __fastcall GetSkinInfo(Dxstatusbar::TdxCustomStatusBar* AStatusBar, /* out */ Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* &ASkinInfo);
	__classmethod bool __fastcall IsSkinAvailable(Dxstatusbar::TdxCustomStatusBar* AStatusBar);
	
public:
	__classmethod virtual void __fastcall AdjustTextColor(Dxstatusbar::TdxCustomStatusBar* AStatusBar, System::Uitypes::TColor &AColor, bool Active);
	__classmethod virtual System::Types::TRect __fastcall ContentExtents(Dxstatusbar::TdxCustomStatusBar* AStatusBar);
	__classmethod virtual bool __fastcall IsSizeGripInPanelArea(Dxstatusbar::TdxCustomStatusBar* AStatusBar);
	__classmethod virtual System::Types::TRect __fastcall SizeGripMargins(Dxstatusbar::TdxCustomStatusBar* AStatusBar);
	__classmethod virtual void __fastcall DrawBorder(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod void __fastcall DrawClippedElement(Dxskinscore::TdxSkinElement* AElement, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AClipRegion, Cxgraphics::TcxRegionOperation ARegionOperation = (Cxgraphics::TcxRegionOperation)(0x0));
	__classmethod virtual void __fastcall DrawEmptyPanel(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelBorder(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Dxstatusbar::TdxStatusBarPanelBevel ABevel, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelSeparator(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawSizeGrip(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall FillBackground(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Dxstatusbar::TdxStatusBarPanel* APanel, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual System::Types::TRect __fastcall PanelContentExtents(Dxstatusbar::TdxCustomStatusBar* AStatusBar, bool AHasBorders);
	__classmethod virtual int __fastcall SeparatorSize();
public:
	/* TObject.Create */ inline __fastcall TdxStatusBarSkinPainter(void) : Dxstatusbar::TdxStatusBarStandardPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarSkinPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinsdxstatusbarpainter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDXSTATUSBARPAINTER)
using namespace Dxskinsdxstatusbarpainter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdxstatusbarpainterHPP
