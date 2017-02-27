// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarXPViews.pas' rev: 24.00 (Win32)

#ifndef DxnavbarxpviewsHPP
#define DxnavbarxpviewsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarGraphics.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit
#include <dxNavBarBaseViews.hpp>	// Pascal unit
#include <dxNavBarExplorerViews.hpp>	// Pascal unit
#include <dxNavBarOfficeViews.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarxpviews
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarXP1GroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarXP1GroupViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo inherited;
	
private:
	bool __fastcall IsDefaultBgColor(void);
	bool __fastcall IsDefaultCaptionColor(void);
	
public:
	virtual System::Uitypes::TColor __fastcall BgBackColor(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor2(void);
	virtual System::Byte __fastcall BgAlphaBlend(void);
	virtual System::Byte __fastcall BgAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall BgGradientMode(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor2(void);
	virtual System::Byte __fastcall CaptionAlphaBlend(void);
	virtual System::Byte __fastcall CaptionAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall CaptionGradientMode(void);
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarXP1GroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarXP1GroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarXP1ViewInfo;
class PASCALIMPLEMENTATION TdxNavBarXP1ViewInfo : public Dxnavbarbaseviews::TdxNavBarBaseViewInfo
{
	typedef Dxnavbarbaseviews::TdxNavBarBaseViewInfo inherited;
	
public:
	virtual void __fastcall AssignDefaultBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderStyle(void);
	virtual void __fastcall AssignDefaultItemStyle(void);
	virtual void __fastcall AssignDefaultItemDisabledStyle(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarXP1ViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarbaseviews::TdxNavBarBaseViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarXP1ViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarXP1Painter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXP1Painter : public Dxnavbarbaseviews::TdxNavBarFlatPainter
{
	typedef Dxnavbarbaseviews::TdxNavBarFlatPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomScrollButtonsPainterClass __fastcall ScrollButtonsPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSelectionPainterClass __fastcall SelectionPainterClass();
	
public:
	virtual void __fastcall DrawGroupCaptionButton(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarXP1Painter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarbaseviews::TdxNavBarFlatPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarXP1Painter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXP2Painter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXP2Painter : public Dxnavbarofficeviews::TdxNavBarOffice1Painter
{
	typedef Dxnavbarofficeviews::TdxNavBarOffice1Painter inherited;
	
protected:
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomBackgroundPainterClass __fastcall BackgroundPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomGroupBackgroundPainterClass __fastcall GroupBackgroundPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomScrollButtonsPainterClass __fastcall ScrollButtonsPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSelectionPainterClass __fastcall SelectionPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarXP2Painter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarofficeviews::TdxNavBarOffice1Painter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarXP2Painter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPExplorerBarLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarXPExplorerBarLinkViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarLinkViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarLinkViewInfo inherited;
	
public:
	virtual Vcl::Graphics::TFont* __fastcall Font(void);
	virtual System::Uitypes::TColor __fastcall FontColor(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarXPExplorerBarLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbarexplorerviews::TdxNavBarExplorerBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarXPExplorerBarLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarXPExplorerBarGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarXPExplorerBarGroupViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo inherited;
	
public:
	virtual System::Uitypes::TColor __fastcall BorderColor(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor2(void);
	virtual System::Byte __fastcall BgAlphaBlend(void);
	virtual System::Byte __fastcall BgAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall BgGradientMode(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor2(void);
	virtual System::Byte __fastcall CaptionAlphaBlend(void);
	virtual System::Byte __fastcall CaptionAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall CaptionGradientMode(void);
	virtual Vcl::Graphics::TFont* __fastcall CaptionFont(void);
	virtual System::Uitypes::TColor __fastcall CaptionFontColor(void);
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarXPExplorerBarGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarXPExplorerBarGroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarXPExplorerBarViewInfo;
class PASCALIMPLEMENTATION TdxNavBarXPExplorerBarViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo inherited;
	
protected:
	virtual void __fastcall CreateColors(void);
	virtual void __fastcall RefreshColors(void);
	virtual void __fastcall ReleaseColors(void);
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	virtual System::Types::TSize __fastcall GetGroupCaptionSignSize(void);
	
public:
	virtual System::Uitypes::TColor __fastcall BgBackColor(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor2(void);
	virtual System::Byte __fastcall BgAlphaBlend(void);
	virtual System::Byte __fastcall BgAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall BgGradientMode(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarXPExplorerBarViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarXPExplorerBarViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarXPExplorerBarPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPExplorerBarPainter : public Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomBackgroundPainterClass __fastcall BackgroundPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSignPainterClass __fastcall SignPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarXPExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarXPExplorerBarPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPExplorerBarButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPExplorerBarButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod Vcl::Graphics::TBitmap* __fastcall GetButtonBitmap(Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPExplorerBarButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPExplorerBarButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPExplorerBarSignPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPExplorerBarSignPainter : public Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter inherited;
	
protected:
	__classmethod void __fastcall CreateBitmap(HDC &ADC, HBITMAP &ABitmap, HBITMAP &AOldBitmap, void * &AData, int AWidth, int AHeight);
	__classmethod void __fastcall deleteBitmap(HDC &ADC, HBITMAP &ABitmap, HBITMAP &AOldBitmap, void * &AData);
	__classmethod void __fastcall DrawMaskBitmap(int DestX, int DestY, NativeUInt DestHandle, Vcl::Graphics::TBitmap* Bitmap);
	__classmethod Vcl::Graphics::TBitmap* __fastcall GetSignBitmap(Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual void __fastcall InternalDrawSign(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPExplorerBarSignPainter(void) : Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPExplorerBarSignPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPPainter : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall DrawObject(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Dxthememanager::TdxThemedObjectType AObject, int iPartId, int iStateId);
	__classmethod bool __fastcall DrawText(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::UnicodeString ACaption, int ADrawTextFlag, Dxthememanager::TdxThemedObjectType AObject, int iPartId, int iStateId);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPBackgroundPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPBackgroundPainter : public Dxnavbarcustompainters::TdxNavBarCustomBackgroundPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomBackgroundPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, bool AEraseBackground, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPBackgroundPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomBackgroundPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPBackgroundPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPGroupBackgroundPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPGroupBackgroundPainter : public Dxnavbarcustompainters::TdxNavBarCustomGroupBackgroundPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomGroupBackgroundPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPGroupBackgroundPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomGroupBackgroundPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPGroupBackgroundPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPSelectionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPSelectionPainter : public Dxnavbarbaseviews::TdxNavBarBaseSelectionPainter
{
	typedef Dxnavbarbaseviews::TdxNavBarBaseSelectionPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawSelection(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPSelectionPainter(void) : Dxnavbarbaseviews::TdxNavBarBaseSelectionPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPSelectionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPScrollButtonsPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPScrollButtonsPainter : public Dxnavbarbaseviews::TdxNavBarBaseScrollButtonsPainter
{
	typedef Dxnavbarbaseviews::TdxNavBarBaseScrollButtonsPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawBottomButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass AButtonPainterClass, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual void __fastcall InternalDrawTopButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass AButtonPainterClass, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPScrollButtonsPainter(void) : Dxnavbarbaseviews::TdxNavBarBaseScrollButtonsPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPScrollButtonsPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPButtonPainter : public Dxnavbarofficeviews::TdxNavBarOfficeButtonPainter
{
	typedef Dxnavbarofficeviews::TdxNavBarOfficeButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPButtonPainter(void) : Dxnavbarofficeviews::TdxNavBarOfficeButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarXPExplorerBarBackgroundPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarXPExplorerBarBackgroundPainter : public Dxnavbarcustompainters::TdxNavBarCustomBackgroundPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomBackgroundPainter inherited;
	
protected:
	__classmethod Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap();
	__classmethod virtual void __fastcall InternalDrawBackground(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, bool AEraseBackground, System::Uitypes::TColor ABackgroundColor, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarXPExplorerBarBackgroundPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomBackgroundPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarXPExplorerBarBackgroundPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbarxpviews */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARXPVIEWS)
using namespace Dxnavbarxpviews;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarxpviewsHPP
