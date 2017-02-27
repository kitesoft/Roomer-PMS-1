// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsdxNavBarPainter.pas' rev: 24.00 (Win32)

#ifndef DxskinsdxnavbarpainterHPP
#define DxskinsdxnavbarpainterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarExplorerViews.hpp>	// Pascal unit
#include <dxNavBarGraphics.hpp>	// Pascal unit
#include <dxNavBarConsts.hpp>	// Pascal unit
#include <dxNavBarOffice11Views.hpp>	// Pascal unit
#include <dxNavBarOfficeViews.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxSkinInfo.hpp>	// Pascal unit
#include <dxNavBarSkinBasedViews.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit
#include <dxNavBarBaseViews.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsdxnavbarpainter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarSkinPainterHelper;
class PASCALIMPLEMENTATION TdxNavBarSkinPainterHelper : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelper
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelper inherited;
	
private:
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	
protected:
	virtual Dxskininfo::TdxSkinInfoClass __fastcall GetSkinInfoClass(void);
	virtual Cxclasses::TdxSkinName __fastcall GetSkinName(void);
	virtual bool __fastcall GetSkinPainterData(Dxskininfo::TdxSkinInfo* &AData);
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall PopulateSkinNames(System::Classes::TStrings* AList);
	virtual void __fastcall SetSkinName(Cxclasses::TdxSkinName AValue);
	
public:
	__fastcall virtual TdxNavBarSkinPainterHelper(Cxclasses::TdxSkinName ASkinName);
	__fastcall virtual ~TdxNavBarSkinPainterHelper(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarDragDropItemTarget(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarSeparator(void);
	virtual bool __fastcall NavPaneDoesGroupCaptionButtonRequireOffset(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPanePopupControl(void);
};


class DELPHICLASS TdxNavBarSkinNavPaneLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinNavPaneLinkViewInfo : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneLinkViewInfo
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneLinkViewInfo inherited;
	
public:
	virtual System::Types::TRect __fastcall SelectionRect(void);
	virtual System::Types::TRect __fastcall SeparatorRect(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarSkinNavPaneLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinNavPaneLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinNavPaneGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinNavPaneGroupViewInfo : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneGroupViewInfo
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneGroupViewInfo inherited;
	
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarSkinNavPaneGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinNavPaneGroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinOverflowPanelViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinOverflowPanelViewInfo : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedOverflowPanelViewInfo
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedOverflowPanelViewInfo inherited;
	
private:
	int __fastcall GetMinHeight(void);
	
protected:
	virtual int __fastcall GetHeight(void);
	virtual int __fastcall GetImageWidthAddon(void);
	virtual int __fastcall GetSignWidth(void);
public:
	/* TdxNavBarOverflowPanelViewInfo.Create */ inline __fastcall virtual TdxNavBarSkinOverflowPanelViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedOverflowPanelViewInfo(AViewInfo) { }
	/* TdxNavBarOverflowPanelViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinOverflowPanelViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinNavPaneViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinNavPaneViewInfo : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneViewInfo
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneViewInfo inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	virtual System::Types::TRect __fastcall GetGroupCaptionImageOffsets(void);
	virtual System::Types::TSize __fastcall GetGroupCaptionSignSize(void);
	virtual int __fastcall GetGroupHeaderTextIndent(void);
	virtual System::Types::TRect __fastcall GetHeaderClientOffset(void);
	virtual int __fastcall GetHeaderHeightAddon(void);
	virtual System::Types::TRect __fastcall GetHeaderSignIndents(void);
	virtual System::Types::TRect __fastcall GetLinksImageEdges(void);
	virtual Dxnavbaroffice11views::TdxNavBarOverflowPanelViewInfoClass __fastcall GetOverflowPanelViewInfoClass(void);
	
public:
	virtual System::Uitypes::TColor __fastcall BorderColor(void);
	virtual int __fastcall BorderWidth(void);
public:
	/* TdxNavBarNavigationPaneViewInfo.Create */ inline __fastcall virtual TdxNavBarSkinNavPaneViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPaneViewInfo(APainter) { }
	/* TdxNavBarNavigationPaneViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinNavPaneViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinPopupControlViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinPopupControlViewInfo : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedPopupControlViewInfo
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedPopupControlViewInfo inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetBorderOffsets(void);
public:
	/* TdxNavBarNavigationPaneCustomViewInfo.Create */ inline __fastcall virtual TdxNavBarSkinPopupControlViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedPopupControlViewInfo(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarSkinPopupControlViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinNavPanePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarSkinNavPanePainter : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPanePainter
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPanePainter inherited;
	
private:
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	HIDESBASE TdxNavBarSkinOverflowPanelViewInfo* __fastcall GetOverflowPanelViewInfo(void);
	Cxclasses::TdxSkinName __fastcall GetSkinName(void);
	bool __fastcall GetSkinNameAssigned(void);
	bool __fastcall IsSkinNameStored(void);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetSkinName(const Cxclasses::TdxSkinName AValue);
	void __fastcall SetSkinNameAssigned(bool AValue);
	
protected:
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	__classmethod virtual Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelperClass __fastcall GetSkinPainterHelperClass();
	__classmethod virtual Dxnavbaroffice11views::TdxNavBarPopupControlViewInfoClass __fastcall GetPopupControlViewInfoClass();
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetMasterLookAndFeel(void);
	virtual int __fastcall GetSplitterType(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawBorder(void);
	virtual void __fastcall DrawGroupBackground(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupControl(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawSeparator(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel, write=SetLookAndFeel};
	__property TdxNavBarSkinOverflowPanelViewInfo* OverflowPanelViewInfo = {read=GetOverflowPanelViewInfo};
	
__published:
	__property Cxclasses::TdxSkinName SkinName = {read=GetSkinName, write=SetSkinName, stored=IsSkinNameStored};
	__property bool SkinNameAssigned = {read=GetSkinNameAssigned, write=SetSkinNameAssigned, default=0};
public:
	/* TdxNavBarSkinBasedNavPanePainter.Create */ inline __fastcall virtual TdxNavBarSkinNavPanePainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedNavPanePainter(ANavBar) { }
	/* TdxNavBarSkinBasedNavPanePainter.Destroy */ inline __fastcall virtual ~TdxNavBarSkinNavPanePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarSkinExplorerBarViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinExplorerBarViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo inherited;
	
protected:
	TdxNavBarSkinPainterHelper* __fastcall GetHelper(void);
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	virtual System::Types::TSize __fastcall GetGroupCaptionSignSize(void);
	virtual System::Types::TPoint __fastcall GetGroupEdges(void);
	bool __fastcall IsEmbedded(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarSkinExplorerBarViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinExplorerBarViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinExplorerBarPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarSkinExplorerBarPainter : public Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter
{
	typedef Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter inherited;
	
private:
	bool FEmbedded;
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	Cxclasses::TdxSkinName __fastcall GetSkinName(void);
	bool __fastcall GetSkinNameAssigned(void);
	bool __fastcall IsSkinNameStored(void);
	void __fastcall SetEmbedded(const bool Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetSkinName(const Cxclasses::TdxSkinName AValue);
	void __fastcall SetSkinNameAssigned(bool AValue);
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbarskinbasedviews::TdxNavBarSkinBasedPainterHelperClass __fastcall GetSkinPainterHelperClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSignPainterClass __fastcall SignPainterClass();
	void __fastcall DrawGroupTopBorder(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetMasterLookAndFeel(void);
	virtual void __fastcall UpdateScrollBarLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawGroupBackground(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupBorder(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupControl(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupControlSplitter(Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawSeparator(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	__property bool Embedded = {read=FEmbedded, write=SetEmbedded, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel, write=SetLookAndFeel};
	
__published:
	__property Cxclasses::TdxSkinName SkinName = {read=GetSkinName, write=SetSkinName, stored=IsSkinNameStored};
	__property bool SkinNameAssigned = {read=GetSkinNameAssigned, write=SetSkinNameAssigned, default=0};
public:
	/* TdxNavBarSkinBasedExplorerBarPainter.Create */ inline __fastcall virtual TdxNavBarSkinExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarskinbasedviews::TdxNavBarSkinBasedExplorerBarPainter(ANavBar) { }
	/* TdxNavBarSkinBasedExplorerBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarSkinExplorerBarPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinsdxnavbarpainter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSDXNAVBARPAINTER)
using namespace Dxskinsdxnavbarpainter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsdxnavbarpainterHPP
