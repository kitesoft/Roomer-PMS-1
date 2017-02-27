// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarSkinBasedViews.pas' rev: 24.00 (Win64)

#ifndef DxnavbarskinbasedviewsHPP
#define DxnavbarskinbasedviewsHPP

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
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarExplorerViews.hpp>	// Pascal unit
#include <dxNavBarConsts.hpp>	// Pascal unit
#include <dxNavBarOffice11Views.hpp>	// Pascal unit
#include <dxNavBarOfficeViews.hpp>	// Pascal unit
#include <dxSkinsStrs.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinInfo.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxNavBarBaseViews.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarskinbasedviews
{
//-- type declarations -------------------------------------------------------
__interface IdxNavBarColorSchemes;
typedef System::DelphiInterface<IdxNavBarColorSchemes> _di_IdxNavBarColorSchemes;
__interface  INTERFACE_UUID("{C49F9017-0A09-4C8E-BF28-BA5BE0614580}") IdxNavBarColorSchemes  : public System::IInterface 
{
	
public:
	virtual Cxclasses::TdxSkinName __fastcall GetName(void) = 0 ;
	virtual void __fastcall SetName(Cxclasses::TdxSkinName AValue) = 0 ;
	virtual void __fastcall PopulateNames(System::Classes::TStrings* AList) = 0 ;
};

class DELPHICLASS TdxNavBarSkin;
class PASCALIMPLEMENTATION TdxNavBarSkin : public Dxskinscore::TdxSkin
{
	typedef Dxskinscore::TdxSkin inherited;
	
__published:
	virtual void __fastcall LoadFromResource(NativeUInt hInst);
public:
	/* TdxSkin.Create */ inline __fastcall virtual TdxNavBarSkin(const System::UnicodeString AName, bool ALoadOnCreate, NativeUInt hInst) : Dxskinscore::TdxSkin(AName, ALoadOnCreate, hInst) { }
	/* TdxSkin.Destroy */ inline __fastcall virtual ~TdxNavBarSkin(void) { }
	
};


class DELPHICLASS TdxNavBarSkinInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinInfo : public Dxskininfo::TdxSkinInfo
{
	typedef Dxskininfo::TdxSkinInfo inherited;
	
protected:
	virtual void __fastcall InitializeAdditionalNavBarElements(void);
	virtual void __fastcall InitializeSkinInfo(void);
	
public:
	Dxskinscore::TdxSkinElement* NavBarDragDropItemTarget;
	Dxskinscore::TdxSkinElement* NavBarSeparator;
public:
	/* TdxSkinInfo.Create */ inline __fastcall virtual TdxNavBarSkinInfo(Dxskinscore::TdxSkin* ASkin)/* overload */ : Dxskininfo::TdxSkinInfo(ASkin) { }
	/* TdxSkinInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinBasedPainterHelper;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedPainterHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Dxskininfo::TdxSkinInfo* FCachedPainterData;
	Cxclasses::TdxSkinName FSkinName;
	System::Classes::TNotifyEvent FOnChanged;
	
protected:
	virtual void __fastcall DoChanged(void);
	virtual Cxclasses::TdxSkinName __fastcall GetFullSkinName(void);
	virtual Dxskininfo::TdxSkinInfoClass __fastcall GetSkinInfoClass(void);
	virtual Cxclasses::TdxSkinName __fastcall GetSkinName(void);
	virtual bool __fastcall GetSkinPainterData(Dxskininfo::TdxSkinInfo* &AData);
	virtual bool __fastcall IsSkinAvailable(void);
	virtual void __fastcall PopulateSkinNames(System::Classes::TStrings* AList);
	virtual void __fastcall SetSkinName(Cxclasses::TdxSkinName AValue);
	
public:
	__fastcall virtual TdxNavBarSkinBasedPainterHelper(Cxclasses::TdxSkinName ASkinName);
	__fastcall virtual ~TdxNavBarSkinBasedPainterHelper(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarBackground(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarDragDropItemTarget(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarGroupButtonCaption(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarGroupClient(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarGroupSigns(bool AIsClose);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarItem(void);
	virtual Dxskininfo::TdxSkinScrollInfo* __fastcall NavBarScrollBarElements(bool AIsHorizontal, Cxlookandfeelpainters::TcxScrollBarPart APart);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavBarSeparator(void);
	virtual Dxskinscore::TdxSkinIntegerProperty* __fastcall NavPaneCaptionFontSize(void);
	virtual Dxskinscore::TdxSkinIntegerProperty* __fastcall NavPaneCaptionHeight(void);
	virtual bool __fastcall NavPaneDoesGroupCaptionButtonRequireOffset(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneGroupButtonCaption(bool AIsSelected);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneGroupClient(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneHeader(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavePaneHeaderSign(bool ACollapse);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneItem(bool AIsSelected);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneItemPanel(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneOverflowPanel(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneOverflowPanelSign(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneOverflowPanelItem(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPanePopupControl(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPanePopupMenu(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPanePopupMenuSelection(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPanePopupMenuSeparator(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPanePopupMenuSideStrip(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneScrollButtons(bool AIsDown);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneSplitter(void);
	virtual Dxskinscore::TdxSkinElement* __fastcall NavPaneSizeGrip(void);
	__property Cxclasses::TdxSkinName SkinName = {read=GetSkinName, write=SetSkinName};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
private:
	void *__IdxNavBarColorSchemes;	/* IdxNavBarColorSchemes */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C49F9017-0A09-4C8E-BF28-BA5BE0614580}
	operator _di_IdxNavBarColorSchemes()
	{
		_di_IdxNavBarColorSchemes intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxNavBarColorSchemes*(void) { return (IdxNavBarColorSchemes*)&__IdxNavBarColorSchemes; }
	#endif
	
};


typedef System::TMetaClass* TdxNavBarSkinBasedPainterHelperClass;

class DELPHICLASS TdxNavBarSkinBasedNavPaneLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedNavPaneLinkViewInfo : public Dxnavbar::TdxNavBarLinkViewInfo
{
	typedef Dxnavbar::TdxNavBarLinkViewInfo inherited;
	
protected:
	TdxNavBarSkinBasedPainterHelper* __fastcall GetSkinHelper(void);
	
public:
	virtual System::Uitypes::TColor __fastcall FontColor(void);
	virtual System::Types::TRect __fastcall SelectionRect(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarSkinBasedNavPaneLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbar::TdxNavBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinBasedNavPaneLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinBasedNavPaneGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedNavPaneGroupViewInfo : public Dxnavbaroffice11views::TdxNavBarNavigationPaneGroupViewInfo
{
	typedef Dxnavbaroffice11views::TdxNavBarNavigationPaneGroupViewInfo inherited;
	
protected:
	TdxNavBarSkinBasedPainterHelper* __fastcall GetSkinHelper(void);
	
public:
	virtual System::Uitypes::TColor __fastcall CaptionFontColor(void);
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarSkinBasedNavPaneGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbaroffice11views::TdxNavBarNavigationPaneGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinBasedNavPaneGroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinBasedOverflowPanelViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedOverflowPanelViewInfo : public Dxnavbaroffice11views::TdxNavBarOverflowPanelViewInfo
{
	typedef Dxnavbaroffice11views::TdxNavBarOverflowPanelViewInfo inherited;
	
protected:
	TdxNavBarSkinBasedPainterHelper* __fastcall GetSkinHelper(void);
	bool __fastcall IsSkinAvailable(void);
	virtual System::Types::TRect __fastcall GetClientOffset(void);
	virtual int __fastcall GetSignWidth(void);
public:
	/* TdxNavBarOverflowPanelViewInfo.Create */ inline __fastcall virtual TdxNavBarSkinBasedOverflowPanelViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo) : Dxnavbaroffice11views::TdxNavBarOverflowPanelViewInfo(AViewInfo) { }
	/* TdxNavBarOverflowPanelViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinBasedOverflowPanelViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinBasedNavPaneViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedNavPaneViewInfo : public Dxnavbaroffice11views::TdxNavBarNavigationPaneViewInfo
{
	typedef Dxnavbaroffice11views::TdxNavBarNavigationPaneViewInfo inherited;
	
protected:
	virtual TdxNavBarSkinBasedPainterHelper* __fastcall GetSkinHelper(void);
	bool __fastcall IsSkinAvailable(void);
	int __fastcall GetDragDropItemTargetHeight(void);
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
	virtual System::Types::TPoint __fastcall GetGroupEdges(void);
	virtual int __fastcall GetGroupHeaderTextIndent(void);
	virtual Dxnavbaroffice11views::TdxNavBarOverflowPanelViewInfoClass __fastcall GetOverflowPanelViewInfoClass(void);
	
public:
	virtual void __fastcall AssignDefaultNavigationPaneHeaderStyle(void);
	virtual System::Uitypes::TColor __fastcall BorderColor(void);
	virtual System::Uitypes::TColor __fastcall CollapseBarFontColor(void);
	virtual int __fastcall GetHeaderHeight(void);
	virtual int __fastcall GetSplitterHeight(void);
	virtual System::Uitypes::TColor __fastcall HeaderFontColor(void);
public:
	/* TdxNavBarNavigationPaneViewInfo.Create */ inline __fastcall virtual TdxNavBarSkinBasedNavPaneViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbaroffice11views::TdxNavBarNavigationPaneViewInfo(APainter) { }
	/* TdxNavBarNavigationPaneViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinBasedNavPaneViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinBasedPopupControlViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedPopupControlViewInfo : public Dxnavbaroffice11views::TdxNavBarPopupControlViewInfo
{
	typedef Dxnavbaroffice11views::TdxNavBarPopupControlViewInfo inherited;
	
protected:
	TdxNavBarSkinBasedPainterHelper* __fastcall GetSkinHelper(void);
	virtual System::Types::TRect __fastcall GetBorderOffsets(void);
public:
	/* TdxNavBarNavigationPaneCustomViewInfo.Create */ inline __fastcall virtual TdxNavBarSkinBasedPopupControlViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo) : Dxnavbaroffice11views::TdxNavBarPopupControlViewInfo(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarSkinBasedPopupControlViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinBasedNavPanePainter;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedNavPanePainter : public Dxnavbaroffice11views::TdxNavBarNavigationPanePainter
{
	typedef Dxnavbaroffice11views::TdxNavBarNavigationPanePainter inherited;
	
private:
	System::Types::TRect __fastcall GetGroupCaptionButtonDrawOffsets(void);
	HIDESBASE TdxNavBarSkinBasedOverflowPanelViewInfo* __fastcall GetOverflowPanelViewInfo(void);
	bool __fastcall InternalDrawScrollButton(bool ADownButton, const System::Types::TRect &ARect, Dxnavbar::TdxNavBarObjectStates AState);
	
protected:
	TdxNavBarSkinBasedPainterHelper* FSkinBasedPainterHelper;
	virtual TdxNavBarSkinBasedPainterHelper* __fastcall CreateSkinHelper(void);
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	__classmethod virtual TdxNavBarSkinBasedPainterHelperClass __fastcall GetSkinPainterHelperClass();
	__classmethod virtual Dxnavbaroffice11views::TdxNavBarPopupControlViewInfoClass __fastcall GetPopupControlViewInfoClass();
	virtual void __fastcall ColorSchemeChanged(System::TObject* ASender);
	virtual _di_IdxNavBarColorSchemes __fastcall GetColorSchemeHelper(void);
	virtual Cxclasses::TdxSkinName __fastcall GetDefaultColorSchemeName(void);
	virtual Cxclasses::TdxSkinName __fastcall GetColorSchemeName(void);
	virtual bool __fastcall IsSkinAvailable(void);
	virtual void __fastcall SetColorSchemeName(const Cxclasses::TdxSkinName AValue);
	Dxskinscore::TdxSkinElementState __fastcall GetNavPaneElementState(const Dxnavbar::TdxNavBarPart APart);
	virtual int __fastcall GetSplitterType(void);
	virtual void __fastcall DoDrawDropTargetLinkSelection(Dxnavbar::TdxNavBarGroupViewInfo* AItemGroup, Dxnavbar::TdxNavBarLinkViewInfo* AItem1, Dxnavbar::TdxNavBarLinkViewInfo* AItem2);
	virtual void __fastcall DoDrawSplitter(void);
	__property _di_IdxNavBarColorSchemes ColorSchemeHelper = {read=GetColorSchemeHelper};
	
public:
	__fastcall virtual TdxNavBarSkinBasedNavPanePainter(Dxnavbar::TdxCustomNavBar* ANavBar);
	__fastcall virtual ~TdxNavBarSkinBasedNavPanePainter(void);
	virtual void __fastcall DrawBottomScrollButton(void);
	virtual void __fastcall DrawCollapseElementBackground(const System::Types::TRect &ARect, Dxnavbaroffice11views::TdxNavBarNavPanePartState AState);
	virtual void __fastcall DrawGroupCaptionButton(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawHeaderBackground(void);
	virtual void __fastcall DrawHeaderSign(void);
	virtual void __fastcall DrawItemSelection(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawOverflowPanelBackground(void);
	virtual void __fastcall DrawOverflowPanelItems(void);
	virtual void __fastcall DrawOverflowPanelSign(void);
	virtual void __fastcall DrawPopupControl(Cxgraphics::TcxCanvas* ACanvas, Dxnavbaroffice11views::TdxNavBarPopupControlViewInfo* AViewInfo);
	virtual void __fastcall DrawPopupMenuItem(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, System::UnicodeString AText, Dxnavbar::TdxNavBarObjectStates State);
	virtual void __fastcall DrawSeparator(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	virtual void __fastcall DrawTopScrollButton(void);
	__property TdxNavBarSkinBasedOverflowPanelViewInfo* OverflowPanelViewInfo = {read=GetOverflowPanelViewInfo};
	__property Cxclasses::TdxSkinName ColorSchemeName = {read=GetColorSchemeName, write=SetColorSchemeName};
private:
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C49F9017-0A09-4C8E-BF28-BA5BE0614580}
	operator _di_IdxNavBarColorSchemes() { return ColorSchemeHelper; }
	#else
	operator IdxNavBarColorSchemes*(void) { return (IdxNavBarColorSchemes*)ColorSchemeHelper; }
	#endif
	
};


class DELPHICLASS TdxNavBarSkinBasedExplorerBarViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedExplorerBarViewInfo : public Dxnavbaroffice11views::TdxNavBarOffice11ExplorerBarViewInfo
{
	typedef Dxnavbaroffice11views::TdxNavBarOffice11ExplorerBarViewInfo inherited;
	
protected:
	TdxNavBarSkinBasedPainterHelper* __fastcall GetSkinHelper(void);
	int __fastcall GetDragDropItemTargetHeight(void);
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarSkinBasedExplorerBarViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbaroffice11views::TdxNavBarOffice11ExplorerBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinBasedExplorerBarViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinBasedExplorerBarPainter;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedExplorerBarPainter : public Dxnavbaroffice11views::TdxNavBarOffice11ExplorerBarPainter
{
	typedef Dxnavbaroffice11views::TdxNavBarOffice11ExplorerBarPainter inherited;
	
protected:
	TdxNavBarSkinBasedPainterHelper* FSkinBasedPainterHelper;
	virtual TdxNavBarSkinBasedPainterHelper* __fastcall CreateSkinHelper(void);
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	__classmethod virtual TdxNavBarSkinBasedPainterHelperClass __fastcall GetSkinPainterHelperClass();
	virtual void __fastcall ColorSchemeChanged(System::TObject* ASender);
	virtual Cxclasses::TdxSkinName __fastcall GetColorSchemeName(void);
	virtual _di_IdxNavBarColorSchemes __fastcall GetColorSchemeHelper(void);
	virtual Cxclasses::TdxSkinName __fastcall GetDefaultColorSchemeName(void);
	virtual bool __fastcall IsSkinAvailable(void);
	virtual void __fastcall SetColorSchemeName(const Cxclasses::TdxSkinName AValue);
	virtual void __fastcall DoDrawDropTargetLinkSelection(Dxnavbar::TdxNavBarGroupViewInfo* AItemGroup, Dxnavbar::TdxNavBarLinkViewInfo* AItem1, Dxnavbar::TdxNavBarLinkViewInfo* AItem2);
	virtual bool __fastcall IsGroupCaptionButtonCompositeDraw(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	__property _di_IdxNavBarColorSchemes ColorSchemeHelper = {read=GetColorSchemeHelper};
	
public:
	__fastcall virtual TdxNavBarSkinBasedExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar);
	__fastcall virtual ~TdxNavBarSkinBasedExplorerBarPainter(void);
	virtual void __fastcall DrawGroupBorder(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionButton(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionSign(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupControlSplitter(Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawSeparator(Dxnavbar::TdxNavBarLinkViewInfo* ALinkViewInfo);
	__property Cxclasses::TdxSkinName ColorSchemeName = {read=GetColorSchemeName, write=SetColorSchemeName};
private:
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C49F9017-0A09-4C8E-BF28-BA5BE0614580}
	operator _di_IdxNavBarColorSchemes() { return ColorSchemeHelper; }
	#else
	operator IdxNavBarColorSchemes*(void) { return (IdxNavBarColorSchemes*)ColorSchemeHelper; }
	#endif
	
};


class DELPHICLASS TdxNavBarSkinBasedExplorerBarLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedExplorerBarLinkViewInfo : public Dxnavbarofficeviews::TdxNavBarOffice3LinkViewInfo
{
	typedef Dxnavbarofficeviews::TdxNavBarOffice3LinkViewInfo inherited;
	
public:
	virtual System::Uitypes::TColor __fastcall FontColor(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarSkinBasedExplorerBarLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbarofficeviews::TdxNavBarOffice3LinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinBasedExplorerBarLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarSkinBasedExplorerBarGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarSkinBasedExplorerBarGroupViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo inherited;
	
public:
	virtual System::Uitypes::TColor __fastcall CaptionFontColor(void);
	virtual void __fastcall CalculateBounds(int &X, int &Y);
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarSkinBasedExplorerBarGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarSkinBasedExplorerBarGroupViewInfo(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE _di_IdxNavBarColorSchemes __fastcall GetNavBarColorSchemes(Dxnavbar::TdxNavBarPainter* APainter);
extern PACKAGE Dxskinscore::TdxSkinElementState __fastcall NavBarObjectStateToSkinState(Dxnavbar::TdxNavBarObjectStates AState);
extern PACKAGE System::Types::TRect __fastcall GetSkinElementOffsets(Dxskinscore::TdxSkinElement* AElement);
extern PACKAGE bool __fastcall DrawSkinElement(Dxskinscore::TdxSkinElement* AElement, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, int AImageIndex = 0x0, Dxskinscore::TdxSkinElementState AState = (Dxskinscore::TdxSkinElementState)(0x0), bool ADrawContentOnly = false);
}	/* namespace Dxnavbarskinbasedviews */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARSKINBASEDVIEWS)
using namespace Dxnavbarskinbasedviews;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarskinbasedviewsHPP
