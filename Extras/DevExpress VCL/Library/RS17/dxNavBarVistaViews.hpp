// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarVistaViews.pas' rev: 24.00 (Win32)

#ifndef DxnavbarvistaviewsHPP
#define DxnavbarvistaviewsHPP

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
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit
#include <dxNavBarSkinBasedViews.hpp>	// Pascal unit
#include <dxNavBarExplorerViews.hpp>	// Pascal unit
#include <dxNavBarXPViews.hpp>	// Pascal unit
#include <dxNavBarOfficeViews.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxNavBarOffice11Views.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarvistaviews
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarVistaPainterHelper;
class PASCALIMPLEMENTATION TdxNavBarVistaPainterHelper : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelper
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelper inherited;
	
public:
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarBackground(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarDragDropItemTarget(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarGroupButtonCaption(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarItem(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarSeparator(void);
public:
	/* TdxNavBarSkinBasedPainterHelper.Create */ inline __fastcall virtual TdxNavBarVistaPainterHelper(Cxclasses::TdxSkinName ASkinName) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelper(ASkinName) { }
	/* TdxNavBarSkinBasedPainterHelper.Destroy */ inline __fastcall virtual ~TdxNavBarVistaPainterHelper(void) { }
	
};


class DELPHICLASS TdxNavBarVistaExplorerBarViewInfo;
class PASCALIMPLEMENTATION TdxNavBarVistaExplorerBarViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo inherited;
	
protected:
	virtual bool __fastcall CanSelectLinkByRect(void);
	virtual System::Types::TRect __fastcall GetAbsoluteLinksImageEdges(void);
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
	__classmethod virtual int __fastcall GetGroupCaptionImageIndent();
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	virtual System::Types::TPoint __fastcall GetGroupEdges(void);
	virtual int __fastcall GetGroupSeparatorWidth(void);
	
public:
	virtual void __fastcall AssignDefaultItemHotTrackedStyle(void);
	virtual void __fastcall AssignDefaultItemPressedStyle(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarVistaExplorerBarViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarVistaExplorerBarViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarVistaExplorerBarSelectionPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarVistaExplorerBarSelectionPainter : public Dxnavbarcustompainters::TdxNavBarCustomSelectionPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomSelectionPainter inherited;
	
protected:
	__classmethod virtual void __fastcall GetColors(Dxnavbar::TdxNavBarObjectStates AState, System::Uitypes::TColor ABackColor, /* out */ System::Uitypes::TColor &AFillColor, /* out */ System::Uitypes::TColor &ATopLeftOuterColor, /* out */ System::Uitypes::TColor &ABottomRightOuterColor, /* out */ System::Uitypes::TColor &ATopLeftInnerColor, /* out */ System::Uitypes::TColor &ABottomRightInnerColor);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarVistaExplorerBarSelectionPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomSelectionPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarVistaExplorerBarSelectionPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarVistaExplorerBarButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarVistaExplorerBarButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarVistaExplorerBarButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarVistaExplorerBarButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarVistaExplorerBarPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarVistaExplorerBarPainter : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelperClass __fastcall GetSkinPainterHelperClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSelectionPainterClass __fastcall SelectionPainterClass();
	virtual Cxclasses::TdxSkinName __fastcall GetDefaultColorSchemeName(void);
	
public:
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawGroupControlSplitter(Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawItemSelection(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
public:
	/* TdxNavBarSkinBasedExplorerBarPainter.Create */ inline __fastcall virtual TdxNavBarVistaExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter(ANavBar) { }
	/* TdxNavBarSkinBasedExplorerBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarVistaExplorerBarPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarVistaExplorerBarLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarVistaExplorerBarLinkViewInfo : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarLinkViewInfo
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarLinkViewInfo inherited;
	
public:
	virtual Vcl::Graphics::TFont* __fastcall Font(void);
	virtual System::Uitypes::TColor __fastcall FontColor(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarVistaExplorerBarLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarVistaExplorerBarLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarVistaExplorerBarGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarVistaExplorerBarGroupViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo inherited;
	
protected:
	virtual int __fastcall GetSplitterSize(void);
	
public:
	virtual System::Uitypes::TColor __fastcall CaptionBackColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor2(void);
	virtual Vcl::Graphics::TFont* __fastcall CaptionFont(void);
	virtual System::Uitypes::TColor __fastcall CaptionFontColor(void);
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarVistaExplorerBarGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarVistaExplorerBarGroupViewInfo(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbarvistaviews */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARVISTAVIEWS)
using namespace Dxnavbarvistaviews;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarvistaviewsHPP
