// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarOfficeViews.pas' rev: 24.00 (Win64)

#ifndef DxnavbarofficeviewsHPP
#define DxnavbarofficeviewsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarBaseViews.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarofficeviews
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarOffice1ViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice1ViewInfo : public Dxnavbarbaseviews::TdxNavBarBaseViewInfo
{
	typedef Dxnavbarbaseviews::TdxNavBarBaseViewInfo inherited;
	
protected:
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	virtual int __fastcall GetGroupSeparatorWidth(void);
	
public:
	virtual void __fastcall AssignDefaultBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderStyle(void);
	virtual void __fastcall AssignDefaultItemStyle(void);
	virtual void __fastcall AssignDefaultItemDisabledStyle(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarOffice1ViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarbaseviews::TdxNavBarBaseViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice1ViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice1Painter;
class PASCALIMPLEMENTATION TdxNavBarOffice1Painter : public Dxnavbarbaseviews::TdxNavBarBasePainter
{
	typedef Dxnavbarbaseviews::TdxNavBarBasePainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarOffice1Painter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarbaseviews::TdxNavBarBasePainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarOffice1Painter(void) { }
	
};


class DELPHICLASS TdxNavBarOffice2Painter;
class PASCALIMPLEMENTATION TdxNavBarOffice2Painter : public TdxNavBarOffice1Painter
{
	typedef TdxNavBarOffice1Painter inherited;
	
protected:
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSelectionPainterClass __fastcall SelectionPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarOffice2Painter(Dxnavbar::TdxCustomNavBar* ANavBar) : TdxNavBarOffice1Painter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarOffice2Painter(void) { }
	
};


class DELPHICLASS TdxNavBarOffice3LinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice3LinkViewInfo : public Dxnavbar::TdxNavBarLinkViewInfo
{
	typedef Dxnavbar::TdxNavBarLinkViewInfo inherited;
	
public:
	virtual System::Types::TRect __fastcall SelectionRect(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarOffice3LinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbar::TdxNavBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice3LinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice3ViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice3ViewInfo : public TdxNavBarOffice1ViewInfo
{
	typedef TdxNavBarOffice1ViewInfo inherited;
	
protected:
	__classmethod virtual int __fastcall GetLinksLargeSeparatorWidth();
	virtual bool __fastcall CanSelectLinkByRect(void);
	
public:
	virtual void __fastcall AssignDefaultItemHotTrackedStyle(void);
	virtual void __fastcall AssignDefaultItemPressedStyle(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarOffice3ViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : TdxNavBarOffice1ViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice3ViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice3Painter;
class PASCALIMPLEMENTATION TdxNavBarOffice3Painter : public TdxNavBarOffice2Painter
{
	typedef TdxNavBarOffice2Painter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarOffice3Painter(Dxnavbar::TdxCustomNavBar* ANavBar) : TdxNavBarOffice2Painter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarOffice3Painter(void) { }
	
};


class DELPHICLASS TdxNavBarOfficeButtonPainter;
class PASCALIMPLEMENTATION TdxNavBarOfficeButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarOfficeButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarOfficeButtonPainter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbarofficeviews */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBAROFFICEVIEWS)
using namespace Dxnavbarofficeviews;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarofficeviewsHPP
