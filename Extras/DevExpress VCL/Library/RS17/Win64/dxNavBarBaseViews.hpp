// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarBaseViews.pas' rev: 24.00 (Win64)

#ifndef DxnavbarbaseviewsHPP
#define DxnavbarbaseviewsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarbaseviews
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarBaseViewInfo;
class PASCALIMPLEMENTATION TdxNavBarBaseViewInfo : public Dxnavbar::TdxNavBarViewInfo
{
	typedef Dxnavbar::TdxNavBarViewInfo inherited;
	
protected:
	virtual void __fastcall CorrectBounds(void);
	virtual int __fastcall GetActiveGroupMinHeight(void);
	
public:
	virtual void __fastcall DoGroupActivate(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual void __fastcall DoGroupDeactivate(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual bool __fastcall IsGroupActive(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual void __fastcall MakeLinkVisible(Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ATop = true);
	virtual void __fastcall MakeGroupVisible(Dxnavbarcollns::TdxNavBarGroup* AGroup, bool AExpandGroup = true, bool ATop = true);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarBaseViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbar::TdxNavBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarBaseViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarNavigationBarController;
class PASCALIMPLEMENTATION TdxNavBarNavigationBarController : public Dxnavbar::TdxNavBarController
{
	typedef Dxnavbar::TdxNavBarController inherited;
	
public:
	/* TdxNavBarController.Create */ inline __fastcall virtual TdxNavBarNavigationBarController(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbar::TdxNavBarController(ANavBar) { }
	/* TdxNavBarController.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationBarController(void) { }
	
};


class DELPHICLASS TdxNavBarBasePainter;
class PASCALIMPLEMENTATION TdxNavBarBasePainter : public Dxnavbarcustompainters::TdxNavBarElementPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarElementPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	virtual Dxnavbar::TdxNavBarControllerClass __fastcall GetControllerClass(void);
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomScrollButtonsPainterClass __fastcall ScrollButtonsPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSelectionPainterClass __fastcall SelectionPainterClass();
	
public:
	__classmethod virtual Dxnavbar::TdxNavBarViewCategories __fastcall GetCategories();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarBasePainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarcustompainters::TdxNavBarElementPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarBasePainter(void) { }
	
};


class DELPHICLASS TdxNavBarBaseSelectionPainter;
class PASCALIMPLEMENTATION TdxNavBarBaseSelectionPainter : public Dxnavbarcustompainters::TdxNavBarCustomSelectionPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomSelectionPainter inherited;
	
protected:
	__classmethod virtual void __fastcall GetColors(Dxnavbar::TdxNavBarObjectStates AState, System::Uitypes::TColor ABackColor, /* out */ System::Uitypes::TColor &AFillColor, /* out */ System::Uitypes::TColor &ATopLeftOuterColor, /* out */ System::Uitypes::TColor &ABottomRightOuterColor, /* out */ System::Uitypes::TColor &ATopLeftInnerColor, /* out */ System::Uitypes::TColor &ABottomRightInnerColor);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarBaseSelectionPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomSelectionPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarBaseSelectionPainter(void) { }
	
};


class DELPHICLASS TdxNavBarBaseButtonPainter;
class PASCALIMPLEMENTATION TdxNavBarBaseButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarBaseButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarBaseButtonPainter(void) { }
	
};


class DELPHICLASS TdxNavBarBaseScrollButtonsPainter;
class PASCALIMPLEMENTATION TdxNavBarBaseScrollButtonsPainter : public Dxnavbarcustompainters::TdxNavBarCustomScrollButtonsPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomScrollButtonsPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawBottomButton(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass AButtonPainterClass, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual void __fastcall InternalDrawTopButton(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass AButtonPainterClass, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarBaseScrollButtonsPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomScrollButtonsPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarBaseScrollButtonsPainter(void) { }
	
};


class DELPHICLASS TdxNavBarFlatPainter;
class PASCALIMPLEMENTATION TdxNavBarFlatPainter : public TdxNavBarBasePainter
{
	typedef TdxNavBarBasePainter inherited;
	
protected:
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarFlatPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : TdxNavBarBasePainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarFlatPainter(void) { }
	
};


class DELPHICLASS TdxNavBarFlatButtonPainter;
class PASCALIMPLEMENTATION TdxNavBarFlatButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarFlatButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarFlatButtonPainter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbarbaseviews */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARBASEVIEWS)
using namespace Dxnavbarbaseviews;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarbaseviewsHPP
