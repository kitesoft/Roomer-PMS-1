// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarVSToolBoxViews.pas' rev: 24.00 (Win64)

#ifndef DxnavbarvstoolboxviewsHPP
#define DxnavbarvstoolboxviewsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit
#include <dxNavBarBaseViews.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarvstoolboxviews
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarVSToolBoxLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarVSToolBoxLinkViewInfo : public Dxnavbar::TdxNavBarLinkViewInfo
{
	typedef Dxnavbar::TdxNavBarLinkViewInfo inherited;
	
public:
	virtual System::Types::TRect __fastcall SelectionRect(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarVSToolBoxLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbar::TdxNavBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarVSToolBoxLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarVSToolBoxViewInfo;
class PASCALIMPLEMENTATION TdxNavBarVSToolBoxViewInfo : public Dxnavbarbaseviews::TdxNavBarBaseViewInfo
{
	typedef Dxnavbarbaseviews::TdxNavBarBaseViewInfo inherited;
	
protected:
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	virtual int __fastcall GetGroupSeparatorWidth(void);
	__classmethod virtual int __fastcall GetGroupCaptionSeparatorWidth();
	virtual bool __fastcall CanHasScrollButtonInGroupCaption(void);
	virtual bool __fastcall CanLinksUseLargeImages(void);
	virtual bool __fastcall CanSelectLinkByRect(void);
	virtual System::Types::TRect __fastcall GetTopScrollButtonRect(void);
	virtual System::Types::TRect __fastcall GetBottomScrollButtonRect(void);
	
public:
	virtual void __fastcall AssignDefaultBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderStyle(void);
	virtual void __fastcall AssignDefaultItemStyle(void);
	virtual void __fastcall AssignDefaultItemDisabledStyle(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarVSToolBoxViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarbaseviews::TdxNavBarBaseViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarVSToolBoxViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarVSToolBoxController;
class PASCALIMPLEMENTATION TdxNavBarVSToolBoxController : public Dxnavbarbaseviews::TdxNavBarNavigationBarController
{
	typedef Dxnavbarbaseviews::TdxNavBarNavigationBarController inherited;
	
protected:
	virtual void __fastcall DoShowLinkHint(Vcl::Controls::THintInfo &AHintInfo, Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual System::Types::TRect __fastcall GetLinkHintRect(Dxnavbarcollns::TdxNavBarItemLink* ALink);
	virtual System::UnicodeString __fastcall GetLinkHintText(Dxnavbarcollns::TdxNavBarItemLink* ALink);
public:
	/* TdxNavBarController.Create */ inline __fastcall virtual TdxNavBarVSToolBoxController(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarbaseviews::TdxNavBarNavigationBarController(ANavBar) { }
	/* TdxNavBarController.Destroy */ inline __fastcall virtual ~TdxNavBarVSToolBoxController(void) { }
	
};


class DELPHICLASS TdxNavBarVSToolBoxPainter;
class PASCALIMPLEMENTATION TdxNavBarVSToolBoxPainter : public Dxnavbarbaseviews::TdxNavBarFlatPainter
{
	typedef Dxnavbarbaseviews::TdxNavBarFlatPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	virtual Dxnavbar::TdxNavBarControllerClass __fastcall GetControllerClass(void);
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSelectionPainterClass __fastcall SelectionPainterClass();
	
public:
	virtual void __fastcall DrawLinkHintWindow(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarVSToolBoxPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarbaseviews::TdxNavBarFlatPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarVSToolBoxPainter(void) { }
	
};


class DELPHICLASS TdxNavBarVSToolBoxSelectionPainter;
class PASCALIMPLEMENTATION TdxNavBarVSToolBoxSelectionPainter : public Dxnavbarbaseviews::TdxNavBarBaseSelectionPainter
{
	typedef Dxnavbarbaseviews::TdxNavBarBaseSelectionPainter inherited;
	
protected:
	__classmethod virtual void __fastcall GetColors(Dxnavbar::TdxNavBarObjectStates AState, System::Uitypes::TColor ABackColor, /* out */ System::Uitypes::TColor &AFillColor, /* out */ System::Uitypes::TColor &ATopLeftOuterColor, /* out */ System::Uitypes::TColor &ABottomRightOuterColor, /* out */ System::Uitypes::TColor &ATopLeftInnerColor, /* out */ System::Uitypes::TColor &ABottomRightInnerColor);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarVSToolBoxSelectionPainter(void) : Dxnavbarbaseviews::TdxNavBarBaseSelectionPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarVSToolBoxSelectionPainter(void) { }
	
};


class DELPHICLASS TdxNavBarVSToolBoxButtonPainter;
class PASCALIMPLEMENTATION TdxNavBarVSToolBoxButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarVSToolBoxButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarVSToolBoxButtonPainter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbarvstoolboxviews */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARVSTOOLBOXVIEWS)
using namespace Dxnavbarvstoolboxviews;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarvstoolboxviewsHPP
