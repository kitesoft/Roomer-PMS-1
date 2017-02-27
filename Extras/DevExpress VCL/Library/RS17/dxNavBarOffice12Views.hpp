// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarOffice12Views.pas' rev: 24.00 (Win32)

#ifndef Dxnavbaroffice12viewsHPP
#define Dxnavbaroffice12viewsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarSkinBasedViews.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinInfo.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxNavBarOffice11Views.hpp>	// Pascal unit
#include <dxNavBarOfficeViews.hpp>	// Pascal unit
#include <dxNavBarBaseViews.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit
#include <dxNavBarExplorerViews.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbaroffice12views
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarOffice12PainterHelper;
class PASCALIMPLEMENTATION TdxNavBarOffice12PainterHelper : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelper
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelper inherited;
	
protected:
	virtual Cxclasses::TdxSkinName __fastcall GetFullSkinName(void);
	virtual void __fastcall PopulateSkinNames(System::Classes::TStrings* AList);
	virtual void __fastcall SetSkinName(Cxclasses::TdxSkinName AValue);
public:
	/* TdxNavBarSkinBasedPainterHelper.Create */ inline __fastcall virtual TdxNavBarOffice12PainterHelper(Cxclasses::TdxSkinName ASkinName) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelper(ASkinName) { }
	/* TdxNavBarSkinBasedPainterHelper.Destroy */ inline __fastcall virtual ~TdxNavBarOffice12PainterHelper(void) { }
	
};


class DELPHICLASS TdxNavBarOffice12NavPanePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice12NavPanePainter : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPanePainter
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPanePainter inherited;
	
protected:
	__classmethod virtual Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelperClass __fastcall GetSkinPainterHelperClass();
	virtual Cxclasses::TdxSkinName __fastcall GetDefaultColorSchemeName(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property ColorSchemeName = {default=0};
public:
	/* TdxNavBarSkinBasedNavPanePainter.Create */ inline __fastcall virtual TdxNavBarOffice12NavPanePainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPanePainter(ANavBar) { }
	/* TdxNavBarSkinBasedNavPanePainter.Destroy */ inline __fastcall virtual ~TdxNavBarOffice12NavPanePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOffice12ExplorerBarPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice12ExplorerBarPainter : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter inherited;
	
protected:
	__classmethod virtual Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelperClass __fastcall GetSkinPainterHelperClass();
	virtual Cxcontrols::TcxControlScrollBarHelper* __fastcall CreatecxScrollBarHelper(Dxnavbar::TdxNavBarScrollBar* AOwner);
	virtual Cxcontrols::TcxControlScrollBarHelperClass __fastcall GetcxScrollBarHelperClass(void);
	void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	int __fastcall ScrollBarMinimalThumbSize(void);
	virtual bool __fastcall IsGroupCaptionButtonCompositeDraw(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual Cxclasses::TdxSkinName __fastcall GetDefaultColorSchemeName(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawItemSelection(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	
__published:
	__property ColorSchemeName = {default=0};
public:
	/* TdxNavBarSkinBasedExplorerBarPainter.Create */ inline __fastcall virtual TdxNavBarOffice12ExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter(ANavBar) { }
	/* TdxNavBarSkinBasedExplorerBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarOffice12ExplorerBarPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbaroffice12views */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBAROFFICE12VIEWS)
using namespace Dxnavbaroffice12views;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxnavbaroffice12viewsHPP
