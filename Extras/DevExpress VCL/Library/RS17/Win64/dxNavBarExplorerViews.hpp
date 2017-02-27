// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarExplorerViews.pas' rev: 24.00 (Win64)

#ifndef DxnavbarexplorerviewsHPP
#define DxnavbarexplorerviewsHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarexplorerviews
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarExplorerBarLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarExplorerBarLinkViewInfo : public Dxnavbar::TdxNavBarLinkViewInfo
{
	typedef Dxnavbar::TdxNavBarLinkViewInfo inherited;
	
public:
	virtual System::Uitypes::TColor __fastcall SeparatorColor(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarExplorerBarLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbar::TdxNavBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarExplorerBarLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarExplorerBarGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarExplorerBarGroupViewInfo : public Dxnavbar::TdxNavBarGroupViewInfo
{
	typedef Dxnavbar::TdxNavBarGroupViewInfo inherited;
	
private:
	Cxclasses::TcxAlignmentVert FAlign;
	System::Types::TRect FSplitterRect;
	bool FUseRestSpace;
	
protected:
	void __fastcall AdjustBoundsByAlignment(int ARestSpaceValue);
	virtual int __fastcall GetSplitterSize(void);
	
public:
	virtual void __fastcall CalculateBounds(int &X, int &Y);
	virtual void __fastcall CorrectBounds(int dX, int dY);
	__property Cxclasses::TcxTopBottom Align = {read=FAlign, write=FAlign, nodefault};
	__property System::Types::TRect SplitterRect = {read=FSplitterRect};
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarExplorerBarGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbar::TdxNavBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarExplorerBarGroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarExplorerBarViewInfo;
class PASCALIMPLEMENTATION TdxNavBarExplorerBarViewInfo : public Dxnavbar::TdxNavBarViewInfo
{
	typedef Dxnavbar::TdxNavBarViewInfo inherited;
	
private:
	void __fastcall CheckJustExpandedGroup(void);
	bool __fastcall IsEnoughSpaceForScrollBar(void);
	
protected:
	virtual void __fastcall CorrectScrollInfo(void);
	virtual void __fastcall CorrectBounds(void);
	virtual void __fastcall DoCalculateBounds(int X, int Y);
	virtual void __fastcall DoCreateGroupsInfo(void);
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	virtual System::Types::TSize __fastcall GetGroupCaptionSignSize(void);
	virtual int __fastcall GetGroupSeparatorWidth(void);
	virtual System::Types::TPoint __fastcall GetGroupEdges(void);
	virtual System::Types::TRect __fastcall GetAbsoluteLinksImageEdges(void);
	virtual System::Types::TRect __fastcall GetLinksImageEdges(void);
	virtual bool __fastcall CanHasActiveGroup(void);
	virtual bool __fastcall CanHasSpecialGroup(void);
	virtual bool __fastcall CanHasImageInGroupCaption(void);
	virtual bool __fastcall CanHasSignInGroupCaption(void);
	virtual bool __fastcall CanHasGroupViewAsIconView(void);
	virtual bool __fastcall CanHasGroupWithNoCaption(void);
	virtual bool __fastcall CanHasVisibleItemsInGroup(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	
public:
	virtual void __fastcall AssignDefaultBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderActiveStyle(void);
	virtual void __fastcall AssignDefaultItemStyle(void);
	virtual void __fastcall AssignDefaultItemDisabledStyle(void);
	virtual void __fastcall AssignDefaultItemHotTrackedStyle(void);
	virtual void __fastcall AssignDefaultItemPressedStyle(void);
	virtual void __fastcall DoGroupActivate(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual void __fastcall DoGroupDeactivate(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual bool __fastcall IsGroupActive(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	virtual void __fastcall MakeLinkVisible(Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ATop = true);
	virtual void __fastcall MakeGroupVisible(Dxnavbarcollns::TdxNavBarGroup* AGroup, bool AExpandGroup = true, bool ATop = true);
	virtual int __fastcall GetGroupViewInfoIndexAtSplitterPos(const System::Types::TPoint pt);
	virtual Dxnavbar::TdxNavBarGroupViewInfo* __fastcall GetGroupViewInfoAtSplitterPos(const System::Types::TPoint pt);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarExplorerBarViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbar::TdxNavBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarExplorerBarViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarExplorerBarController;
class PASCALIMPLEMENTATION TdxNavBarExplorerBarController : public Dxnavbar::TdxNavBarController
{
	typedef Dxnavbar::TdxNavBarController inherited;
	
private:
	System::Types::TPoint FStartDragPoint;
	int FStartDragHeight;
	Dxnavbar::TdxNavBarGroupViewInfo* __fastcall GetSizedGroup(void);
	
protected:
	virtual Dxnavbar::TdxNavBarPart __fastcall GetPartAtPos(const System::Types::TPoint APoint);
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	virtual void __fastcall DoMouseUp(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint APoint);
	virtual HICON __fastcall GetCursor(void);
	void __fastcall DoSplitterStartDrag(const System::Types::TPoint APoint);
	void __fastcall DoSplitterDrag(const System::Types::TPoint APoint);
	void __fastcall DoSplitterEndDrag(const System::Types::TPoint APoint);
	void __fastcall DoSplitterCancelDrag(void);
	
public:
	__fastcall virtual ~TdxNavBarExplorerBarController(void);
public:
	/* TdxNavBarController.Create */ inline __fastcall virtual TdxNavBarExplorerBarController(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbar::TdxNavBarController(ANavBar) { }
	
};


class DELPHICLASS TdxNavBarExplorerBarPainter;
class PASCALIMPLEMENTATION TdxNavBarExplorerBarPainter : public Dxnavbarcustompainters::TdxNavBarElementPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarElementPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	virtual Dxnavbar::TdxNavBarControllerClass __fastcall GetControllerClass(void);
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomGroupBorderPainterClass __fastcall GroupBorderPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSignPainterClass __fastcall SignPainterClass();
	virtual bool __fastcall NeedScrollBar(void);
	
public:
	virtual void __fastcall DrawGroup(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupControlSplitter(TdxNavBarExplorerBarGroupViewInfo* AGroupViewInfo);
	__classmethod virtual Dxnavbar::TdxNavBarViewCategories __fastcall GetCategories();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarcustompainters::TdxNavBarElementPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarExplorerBarPainter(void) { }
	
};


class DELPHICLASS TdxNavBarExplorerBarBorderPainter;
class PASCALIMPLEMENTATION TdxNavBarExplorerBarBorderPainter : public Dxnavbarcustompainters::TdxNavBarCustomGroupBorderPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomGroupBorderPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawBorder(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, System::Uitypes::TColor AColor, bool AWithCaption);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarExplorerBarBorderPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomGroupBorderPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarExplorerBarBorderPainter(void) { }
	
};


class DELPHICLASS TdxNavBarExplorerBarSignPainter;
class PASCALIMPLEMENTATION TdxNavBarExplorerBarSignPainter : public Dxnavbarcustompainters::TdxNavBarCustomSignPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomSignPainter inherited;
	
protected:
	__classmethod virtual void __fastcall DrawSignSelection(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual void __fastcall InternalDrawSign(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarExplorerBarSignPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomSignPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarExplorerBarSignPainter(void) { }
	
};


class DELPHICLASS TdxNavBarUltraFlatExplorerBarPainter;
class PASCALIMPLEMENTATION TdxNavBarUltraFlatExplorerBarPainter : public TdxNavBarExplorerBarPainter
{
	typedef TdxNavBarExplorerBarPainter inherited;
	
protected:
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSelectionPainterClass __fastcall SelectionPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarUltraFlatExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : TdxNavBarExplorerBarPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarUltraFlatExplorerBarPainter(void) { }
	
};


class DELPHICLASS TdxNavBarAdvExplorerBarLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarAdvExplorerBarLinkViewInfo : public TdxNavBarExplorerBarLinkViewInfo
{
	typedef TdxNavBarExplorerBarLinkViewInfo inherited;
	
public:
	virtual System::Uitypes::TColor __fastcall FontColor(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarAdvExplorerBarLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : TdxNavBarExplorerBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarAdvExplorerBarLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarAdvExplorerBarGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarAdvExplorerBarGroupViewInfo : public TdxNavBarExplorerBarGroupViewInfo
{
	typedef TdxNavBarExplorerBarGroupViewInfo inherited;
	
private:
	bool __fastcall IsDefaultBgColor(void);
	bool __fastcall IsDefaultCaptionColor(void);
	
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
	virtual System::Uitypes::TColor __fastcall CaptionFontColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionSignColor(void);
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarAdvExplorerBarGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : TdxNavBarExplorerBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarAdvExplorerBarGroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarAdvExplorerBarViewInfo;
class PASCALIMPLEMENTATION TdxNavBarAdvExplorerBarViewInfo : public TdxNavBarExplorerBarViewInfo
{
	typedef TdxNavBarExplorerBarViewInfo inherited;
	
private:
	bool __fastcall IsDefaultBgColor(void);
	
protected:
	virtual void __fastcall CreateColors(void);
	virtual void __fastcall RefreshColors(void);
	virtual void __fastcall ReleaseColors(void);
	virtual System::Types::TSize __fastcall GetGroupCaptionSignSize(void);
	
public:
	virtual System::Uitypes::TColor __fastcall BgBackColor(void);
	virtual System::Uitypes::TColor __fastcall BgBackColor2(void);
	virtual System::Byte __fastcall BgAlphaBlend(void);
	virtual System::Byte __fastcall BgAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall BgGradientMode(void);
	virtual void __fastcall AssignDefaultBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderActiveStyle(void);
	virtual void __fastcall AssignDefaultItemStyle(void);
	virtual void __fastcall AssignDefaultItemDisabledStyle(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarAdvExplorerBarViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : TdxNavBarExplorerBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarAdvExplorerBarViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarAdvExplorerBarPainter;
class PASCALIMPLEMENTATION TdxNavBarAdvExplorerBarPainter : public TdxNavBarExplorerBarPainter
{
	typedef TdxNavBarExplorerBarPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSignPainterClass __fastcall SignPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarAdvExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : TdxNavBarExplorerBarPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarAdvExplorerBarPainter(void) { }
	
};


class DELPHICLASS TdxNavBarAdvExplorerButtonPainter;
class PASCALIMPLEMENTATION TdxNavBarAdvExplorerButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarAdvExplorerButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarAdvExplorerButtonPainter(void) { }
	
};


class DELPHICLASS TdxNavBarAdvExplorerBarSignPainter;
class PASCALIMPLEMENTATION TdxNavBarAdvExplorerBarSignPainter : public TdxNavBarExplorerBarSignPainter
{
	typedef TdxNavBarExplorerBarSignPainter inherited;
	
protected:
	__classmethod void __fastcall PrepareBitmap(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Graphics::TBitmap* ABitmap, System::Uitypes::TColor AForeColor, Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual void __fastcall InternalDrawSign(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarAdvExplorerBarSignPainter(void) : TdxNavBarExplorerBarSignPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarAdvExplorerBarSignPainter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 ebSplitter = System::Int8(0x3);
}	/* namespace Dxnavbarexplorerviews */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBAREXPLORERVIEWS)
using namespace Dxnavbarexplorerviews;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarexplorerviewsHPP
