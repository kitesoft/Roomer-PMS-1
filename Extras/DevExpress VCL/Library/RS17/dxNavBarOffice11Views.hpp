// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarOffice11Views.pas' rev: 24.00 (Win32)

#ifndef Dxnavbaroffice11viewsHPP
#define Dxnavbaroffice11viewsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit
#include <dxNavBarBaseViews.hpp>	// Pascal unit
#include <dxNavBarOfficeViews.hpp>	// Pascal unit
#include <dxNavBarExplorerViews.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbaroffice11views
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarOffice11LinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice11LinkViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarLinkViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarLinkViewInfo inherited;
	
public:
	virtual System::Uitypes::TColor __fastcall FontColor(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarOffice11LinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbarexplorerviews::TdxNavBarExplorerBarLinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11LinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice11GroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice11GroupViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo inherited;
	
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
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarOffice11GroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11GroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice11ViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice11ViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo inherited;
	
private:
	bool __fastcall IsDefaultBgColor(void);
	
protected:
	virtual void __fastcall CreateColors(void);
	virtual void __fastcall RefreshColors(void);
	virtual void __fastcall ReleaseColors(void);
	virtual System::Types::TPoint __fastcall GetGroupEdges(void);
	virtual int __fastcall GetGroupSeparatorWidth(void);
	virtual System::Types::TRect __fastcall GetLinksImageEdges(void);
	
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
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarOffice11ViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11ViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice11Painter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice11Painter : public Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSignPainterClass __fastcall SignPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarOffice11Painter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11Painter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOffice11SignPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice11SignPainter : public Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter inherited;
	
protected:
	__classmethod void __fastcall PrepareBitmap(Vcl::Graphics::TCanvas* ACanvas, Vcl::Graphics::TBitmap* ABitmap, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
	__classmethod virtual void __fastcall InternalDrawSign(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarOffice11SignPainter(void) : Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11SignPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOffice11ExplorerBarGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice11ExplorerBarGroupViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo inherited;
	
private:
	bool __fastcall IsDefaultCaptionColor(void);
	
public:
	virtual System::Uitypes::TColor __fastcall CaptionBorderColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor2(void);
	virtual System::Byte __fastcall CaptionAlphaBlend(void);
	virtual System::Byte __fastcall CaptionAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall CaptionGradientMode(void);
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarOffice11ExplorerBarGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11ExplorerBarGroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice11ExplorerBarViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice11ExplorerBarViewInfo : public Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo inherited;
	
protected:
	virtual void __fastcall CreateColors(void);
	virtual void __fastcall RefreshColors(void);
	virtual void __fastcall ReleaseColors(void);
	virtual bool __fastcall CanSelectLinkByRect(void);
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	__classmethod virtual int __fastcall GetGroupCaptionImageIndent();
	virtual System::Types::TPoint __fastcall GetGroupEdges(void);
	virtual int __fastcall GetGroupSeparatorWidth(void);
	
public:
	virtual void __fastcall AssignDefaultBackgroundStyle(void);
	virtual void __fastcall AssignDefaultButtonStyle(void);
	virtual void __fastcall AssignDefaultGroupBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderStyle(void);
	virtual void __fastcall AssignDefaultItemStyle(void);
	virtual void __fastcall AssignDefaultItemDisabledStyle(void);
	virtual void __fastcall AssignDefaultNavigationPaneHeaderStyle(void);
public:
	/* TdxNavBarViewInfo.Create */ inline __fastcall virtual TdxNavBarOffice11ExplorerBarViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : Dxnavbarexplorerviews::TdxNavBarExplorerBarViewInfo(APainter) { }
	/* TdxNavBarViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11ExplorerBarViewInfo(void) { }
	
};


enum TdxNavBarOffice11ExplorerBarControllerState : unsigned char { ecsOverSizeGrip };

typedef System::Set<TdxNavBarOffice11ExplorerBarControllerState, TdxNavBarOffice11ExplorerBarControllerState::ecsOverSizeGrip, TdxNavBarOffice11ExplorerBarControllerState::ecsOverSizeGrip>  TdxNavBarOffice11ExplorerBarControllerStates;

class DELPHICLASS TdxNavBarOffice11ExplorerBarController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice11ExplorerBarController : public Dxnavbarexplorerviews::TdxNavBarExplorerBarController
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarController inherited;
	
private:
	TdxNavBarOffice11ExplorerBarControllerStates FInternalState;
	bool __fastcall GetMouseOverSizeGrip(void);
	void __fastcall SetMouseOverSizeGrip(bool AValue);
	__property bool MouseOverSizeGrip = {read=GetMouseOverSizeGrip, write=SetMouseOverSizeGrip, nodefault};
	
protected:
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint &APoint);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState AShift, const System::Types::TPoint &APoint);
	virtual HICON __fastcall GetCursor(void);
public:
	/* TdxNavBarExplorerBarController.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11ExplorerBarController(void) { }
	
public:
	/* TdxNavBarController.Create */ inline __fastcall virtual TdxNavBarOffice11ExplorerBarController(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarexplorerviews::TdxNavBarExplorerBarController(ANavBar) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOffice11ExplorerBarPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice11ExplorerBarPainter : public Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	virtual Dxnavbar::TdxNavBarControllerClass __fastcall GetControllerClass(void);
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomSignPainterClass __fastcall SignPainterClass();
	
public:
	virtual void __fastcall DrawNavBarControl(void);
	virtual void __fastcall DrawGroupControlSplitter(Dxnavbarexplorerviews::TdxNavBarExplorerBarGroupViewInfo* AGroupViewInfo);
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarOffice11ExplorerBarPainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarexplorerviews::TdxNavBarExplorerBarPainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11ExplorerBarPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOffice11ExplorerBarSignPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice11ExplorerBarSignPainter : public Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter
{
	typedef Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter inherited;
	
protected:
	__classmethod virtual void __fastcall DrawSignSelection(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AForeColor, System::Uitypes::TColor ABackColor1, System::Uitypes::TColor ABackColor2, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarOffice11ExplorerBarSignPainter(void) : Dxnavbarexplorerviews::TdxNavBarExplorerBarSignPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11ExplorerBarSignPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarNavigationPaneGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneGroupViewInfo : public Dxnavbar::TdxNavBarGroupViewInfo
{
	typedef Dxnavbar::TdxNavBarGroupViewInfo inherited;
	
private:
	bool __fastcall IsDefaultCaptionColor(void);
	
protected:
	virtual int __fastcall GetImageIndent(void);
	
public:
	virtual System::Uitypes::TColor __fastcall CaptionBorderColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor(void);
	virtual System::Uitypes::TColor __fastcall CaptionBackColor2(void);
	virtual System::Byte __fastcall CaptionAlphaBlend(void);
	virtual System::Byte __fastcall CaptionAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall CaptionGradientMode(void);
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarNavigationPaneGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : Dxnavbar::TdxNavBarGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneGroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice11NavPaneGroupViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice11NavPaneGroupViewInfo : public TdxNavBarNavigationPaneGroupViewInfo
{
	typedef TdxNavBarNavigationPaneGroupViewInfo inherited;
	
public:
	/* TdxNavBarGroupViewInfo.Create */ inline __fastcall TdxNavBarOffice11NavPaneGroupViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo, Dxnavbarcollns::TdxNavBarGroup* AGroup, bool ACaptionVisible, bool AItemsVisible) : TdxNavBarNavigationPaneGroupViewInfo(AViewInfo, AGroup, ACaptionVisible, AItemsVisible) { }
	/* TdxNavBarGroupViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11NavPaneGroupViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOffice11NavPaneLinkViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice11NavPaneLinkViewInfo : public Dxnavbarofficeviews::TdxNavBarOffice3LinkViewInfo
{
	typedef Dxnavbarofficeviews::TdxNavBarOffice3LinkViewInfo inherited;
	
public:
	virtual System::Uitypes::TColor __fastcall SeparatorColor(void);
public:
	/* TdxNavBarLinkViewInfo.Create */ inline __fastcall TdxNavBarOffice11NavPaneLinkViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo, Dxnavbarcollns::TdxNavBarItemLink* ALink, bool ACaptionVisible, bool AImageVisisble) : Dxnavbarofficeviews::TdxNavBarOffice3LinkViewInfo(AGroupViewInfo, ALink, ACaptionVisible, AImageVisisble) { }
	
public:
	/* TdxNavBarCustomItemViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11NavPaneLinkViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarNavigationPaneCustomViewInfo;
class DELPHICLASS TdxNavBarNavigationPaneViewInfo;
class DELPHICLASS TdxNavBarNavigationPanePainter;
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneCustomViewInfo : public Dxnavbar::TdxNavBarCustomViewInfo
{
	typedef Dxnavbar::TdxNavBarCustomViewInfo inherited;
	
private:
	Dxnavbar::TdxNavBarViewInfo* FViewInfo;
	TdxNavBarNavigationPaneViewInfo* __fastcall GetViewInfo(void);
	TdxNavBarNavigationPanePainter* __fastcall GetPainter(void);
	
protected:
	__property TdxNavBarNavigationPaneViewInfo* ViewInfo = {read=GetViewInfo};
	__property TdxNavBarNavigationPanePainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual TdxNavBarNavigationPaneCustomViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneCustomViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarOverflowPanelViewInfoItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOverflowPanelViewInfoItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Dxnavbarcollns::TdxNavBarGroup* Group;
	System::Types::TRect Rect;
	System::Types::TRect SelectionRect;
public:
	/* TObject.Create */ inline __fastcall TdxNavBarOverflowPanelViewInfoItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarOverflowPanelViewInfoItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOverflowPanelViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOverflowPanelViewInfo : public TdxNavBarNavigationPaneCustomViewInfo
{
	typedef TdxNavBarNavigationPaneCustomViewInfo inherited;
	
private:
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FIAccessibilityHelper;
	System::Classes::TList* FItems;
	System::Types::TRect FRect;
	System::Types::TRect FSignRect;
	int FVisibleItemCount;
	void __fastcall ClearRects(void);
	void __fastcall ClearItems(void);
	void __fastcall OffsetElements(int AHeightDifference);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	TdxNavBarOverflowPanelViewInfoItem* __fastcall AddItem(void);
	int __fastcall GetItemCount(void);
	TdxNavBarOverflowPanelViewInfoItem* __fastcall GetItems(int AIndex);
	
protected:
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual int __fastcall GetHeight(void);
	int __fastcall GetImageHeight(void);
	int __fastcall GetImageWidth(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImageList(void);
	int __fastcall GetImageIndex(Dxnavbarcollns::TdxNavBarGroup* AGroup);
	int __fastcall GetItemIndexAtPos(const System::Types::TPoint &pt);
	int __fastcall GetItemSelectionWidth(void);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroupAtPos(const System::Types::TPoint &pt);
	void __fastcall CalculateBounds(int X, int Y);
	bool __fastcall IsVisible(void);
	virtual int __fastcall GetImageWidthAddon(void);
	virtual int __fastcall GetSignWidth(void);
	virtual int __fastcall GetHeightAddon(void);
	virtual int __fastcall GetPopupMenuImageIndent(void);
	virtual int __fastcall GetPopupMenuTextIndent(void);
	virtual int __fastcall GetSeparator(void);
	virtual System::Types::TRect __fastcall GetClientOffset(void);
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxNavBarOverflowPanelViewInfoItem* Items[int AIndex] = {read=GetItems};
	
public:
	__fastcall virtual TdxNavBarOverflowPanelViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo);
	__fastcall virtual ~TdxNavBarOverflowPanelViewInfo(void);
	__property System::Types::TRect Rect = {read=FRect};
};


typedef System::TMetaClass* TdxNavBarOverflowPanelViewInfoClass;

class DELPHICLASS TdxNavBarItemPanelViewInfoItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarItemPanelViewInfoItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString __fastcall GetCaption(void);
	
protected:
	void __fastcall OffsetRects(int dX, int dY);
	
public:
	int Index;
	Dxnavbarcollns::TdxNavBarItemLink* ItemLink;
	Vcl::Graphics::TFont* Font;
	System::Types::TRect Rect;
	System::Types::TRect TextRect;
	System::Types::TRect ImageRect;
	Vcl::Imglist::TCustomImageList* ImageList;
	int ImageIndex;
	__property System::UnicodeString Caption = {read=GetCaption};
public:
	/* TObject.Create */ inline __fastcall TdxNavBarItemPanelViewInfoItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarItemPanelViewInfoItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarItemPanelViewInfo;
class PASCALIMPLEMENTATION TdxNavBarItemPanelViewInfo : public TdxNavBarNavigationPaneCustomViewInfo
{
	typedef TdxNavBarNavigationPaneCustomViewInfo inherited;
	
private:
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FIAccessibilityHelper;
	Dxnavbarcollns::TdxNavBarGroup* FCollapseBarGroup;
	System::Types::TRect FCollapseBarRect;
	System::Types::TRect FRect;
	Dxnavbar::TdxNavBarGroupViewInfo* FActiveGroupViewInfo;
	System::Contnrs::TObjectList* FItems;
	bool FIsCollapseMode;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetCollapseBarIAccessibilityHelper(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	int __fastcall GetItemCount(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetItemIAccessibilityHelper(int AIndex);
	TdxNavBarItemPanelViewInfoItem* __fastcall GetItems(int AIndex);
	void __fastcall SetActiveGroupViewInfo(Dxnavbar::TdxNavBarGroupViewInfo* AValue);
	TdxNavBarItemPanelViewInfoItem* __fastcall AddItem(void);
	void __fastcall ClearItems(void);
	void __fastcall CreateItems(void);
	
protected:
	int __fastcall GetMinHeight(void);
	void __fastcall CalculateBounds(int &X, int &Y);
	void __fastcall CorrectBounds(int AHeightDifference);
	Vcl::Graphics::TFont* __fastcall GetCollapseBarFont(void);
	System::UnicodeString __fastcall GetCollapseBarText(void);
	Vcl::Graphics::TFont* __fastcall GetItemFont(int AIndex);
	int __fastcall GetItemIndexAtPos(const System::Types::TPoint &pt);
	int __fastcall GetCollapseBarCaptionIndent(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property Dxnavbar::TdxNavBarGroupViewInfo* ActiveGroupViewInfo = {read=FActiveGroupViewInfo, write=SetActiveGroupViewInfo};
	__property Vcl::Graphics::TFont* CollapseBarFont = {read=GetCollapseBarFont};
	__property System::UnicodeString CollapseBarText = {read=GetCollapseBarText};
	__property System::Types::TRect CollapseBarRect = {read=FCollapseBarRect};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxNavBarItemPanelViewInfoItem* Items[int AIndex] = {read=GetItems};
	__property System::Types::TRect Rect = {read=FRect};
	
public:
	__fastcall virtual TdxNavBarItemPanelViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo);
	__fastcall virtual ~TdxNavBarItemPanelViewInfo(void);
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper CollapseBarIAccessibilityHelper = {read=GetCollapseBarIAccessibilityHelper};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper ItemIAccessibilityHelpers[int AIndex] = {read=GetItemIAccessibilityHelper};
};


class PASCALIMPLEMENTATION TdxNavBarNavigationPaneViewInfo : public Dxnavbarofficeviews::TdxNavBarOffice3ViewInfo
{
	typedef Dxnavbarofficeviews::TdxNavBarOffice3ViewInfo inherited;
	
private:
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FActiveGroupCaptionPanelIAccessibilityHelper;
	System::Types::TRect FSizeGripRect;
	System::Types::TRect FHeaderRect;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FHeaderSignIAccessibilityHelper;
	System::Types::TRect FHeaderSignRect;
	System::Types::TRect FHeaderTextRect;
	TdxNavBarOverflowPanelViewInfo* FOverflowPanelViewInfo;
	TdxNavBarItemPanelViewInfo* FItemPanelViewInfo;
	System::Types::TRect FSplitterRect;
	Vcl::Menus::TPopupMenu* FPopupMenu;
	Vcl::Controls::TImageList* FImageList;
	System::Types::TSize FMaxImageSize;
	bool FMaxImageSizeCalculated;
	bool FImageHeightPeer;
	TdxNavBarNavigationPanePainter* __fastcall GetPainter(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetActiveGroupCaptionPanelIAccessibilityHelper(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetHeaderSignIAccessibilityHelper(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetOverflowPanelIAccessibilityHelper(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetOverflowPanelSignIAccessibilityHelper(void);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetOverflowPanelItemIAccessibilityHelper(int AIndex);
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetNavPanePartIAccessibilityHelper(const Dxnavbar::TdxNavBarPart &APart);
	int __fastcall GetSmallImagesCount(void);
	int __fastcall GetOverflowPanelItemCount(void);
	TdxNavBarOverflowPanelViewInfoItem* __fastcall GetOverflowPanelItems(int AIndex);
	System::Types::TRect __fastcall GetOverflowPanelRect(void);
	System::Types::TRect __fastcall GetOverflowPanelSignRect(void);
	int __fastcall GetOverflowPanelVisibleItemCount(void);
	bool __fastcall IsActiveGroupVisible(void);
	bool __fastcall IsGroupReflectionNeeded(void);
	int __fastcall GetMinHeight(void);
	int __fastcall GetRealGroupStartIndex(void);
	int __fastcall GetRealGroupCount(void);
	bool __fastcall IsDefaultHeaderColor(void);
	bool __fastcall IsDefaultOverflowPanelColor(void);
	bool __fastcall IsDefaultBottomScrollButtonColor(void);
	bool __fastcall IsDefaultTopScrollButtonColor(void);
	void __fastcall RecreateImageList(void);
	void __fastcall DoMoreButtonsClick(System::TObject* Sender);
	void __fastcall DoFewerButtonsClick(System::TObject* Sender);
	void __fastcall DoAddRemoveButtonsClick(System::TObject* Sender);
	void __fastcall DoHiddenGroupClick(System::TObject* Sender);
	void __fastcall DoMeasureItem(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, int &Width, int &Height);
	void __fastcall DoDrawItem(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, bool Selected);
	
protected:
	virtual void __fastcall CreateColors(void);
	virtual void __fastcall RefreshColors(void);
	virtual void __fastcall ReleaseColors(void);
	virtual System::Types::TPoint __fastcall GetGroupEdges(void);
	virtual int __fastcall GetGroupSeparatorWidth(void);
	virtual System::Types::TRect __fastcall GetGroupBorderOffsets(void);
	__classmethod virtual int __fastcall GetGroupCaptionImageIndent();
	virtual int __fastcall GetGroupCaptionHeightAddon(void);
	virtual int __fastcall GetGroupHeaderTextIndent(void);
	virtual System::Types::TRect __fastcall GetHeaderClientOffset(void);
	virtual System::Types::TRect __fastcall GetHeaderSignIndents(void);
	virtual int __fastcall GetNavBarCollapsedWidth(void);
	virtual int __fastcall GetNavBarMinExpandedWidth(void);
	virtual bool __fastcall CanCollapse(void);
	bool __fastcall IsInternal(void);
	virtual bool __fastcall CanHasGroupViewAsIconView(void);
	virtual bool __fastcall CanHasImageInGroupCaption(void);
	virtual bool __fastcall CanGroupCaptionBoundsByImage(void);
	bool __fastcall IsBottomBorderNeeded(void);
	bool __fastcall IsCollapsed(void);
	bool __fastcall IsHeaderVisible(void);
	bool __fastcall IsSplitterVisible(void);
	bool __fastcall IsTopBorderNeeded(void);
	virtual void __fastcall CorrectBounds(void);
	virtual void __fastcall DoCreateGroupsInfo(void);
	virtual void __fastcall DoCalculateBounds(int X, int Y);
	System::Types::TRect __fastcall GetItemPanelRect(void);
	virtual Dxnavbarbase::TdxNavBarChangeType __fastcall GetBoundsUpdateType(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetActiveGroupCaptionPanelAccessibilityHelperClass(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetHeaderSignAccessibilityHelperClass(void);
	virtual TdxNavBarOverflowPanelViewInfoClass __fastcall GetOverflowPanelViewInfoClass(void);
	
public:
	__fastcall virtual TdxNavBarNavigationPaneViewInfo(Dxnavbar::TdxNavBarPainter* APainter);
	__fastcall virtual ~TdxNavBarNavigationPaneViewInfo(void);
	virtual void __fastcall CreateInfo(void);
	void __fastcall CreateItemPanelViewInfo(void);
	virtual void __fastcall CreateOverflowPanelInfo(int AItemCount, bool AClearOld);
	virtual void __fastcall CalculateSizeGripBounds(void);
	virtual void __fastcall CalculateHeaderBounds(int &X, int &Y);
	virtual void __fastcall CalculateMaxImageSize(void);
	virtual void __fastcall CalculateSplitterBounds(int &X, int &Y);
	virtual void __fastcall ClearRects(void);
	virtual Cxclasses::TcxDirection __fastcall GetExpandDirection(void);
	virtual int __fastcall GetHeaderHeight(void);
	virtual Cxclasses::TcxDirection __fastcall GetHeaderSignDirection(void);
	virtual int __fastcall GetGripSize(void);
	virtual Dxcore::TdxCorner __fastcall GetGripSizeCorner(void);
	virtual int __fastcall GetSplitterHeight(void);
	virtual Dxnavbar::TdxNavBarGroupViewInfo* __fastcall GetGroupViewInfoAtItemsPos(const System::Types::TPoint &pt);
	virtual int __fastcall GetViewInfoAtDragPosition(const System::Types::TPoint &pt, Dxnavbar::TdxNavBarGroupViewInfo* &ItemGroup, Dxnavbar::TdxNavBarLinkViewInfo* &Item1, Dxnavbar::TdxNavBarLinkViewInfo* &Item2);
	bool __fastcall IsPtIncNavigationPaneOverflowPanelItemCount(const System::Types::TPoint &pt);
	bool __fastcall IsPtDecNavigationPaneOverflowPanelItemCount(const System::Types::TPoint &pt);
	bool __fastcall IsPtNavigationPaneHeader(const System::Types::TPoint &pt);
	bool __fastcall IsPtNavigationPaneHeaderSign(const System::Types::TPoint &pt);
	bool __fastcall IsPtNavigationPaneOverflowPanel(const System::Types::TPoint &pt);
	bool __fastcall IsPtNavigationPaneOverflowPanelSign(const System::Types::TPoint &pt);
	bool __fastcall IsPtNavigationPaneSplitter(const System::Types::TPoint &pt);
	bool __fastcall IsPtNavigationPaneItemPanel(const System::Types::TPoint &pt);
	void __fastcall DoShowPopupMenu(const System::Types::TPoint &APoint);
	virtual void __fastcall DoUpdatePopupMenu(void);
	virtual Dxnavbarcollns::TdxNavBarGroup* __fastcall FindGroupWithAccel(System::Word AKey);
	virtual Dxnavbarcollns::TdxNavBarItemLink* __fastcall FindLinkWithAccel(System::Word AKey);
	virtual Dxnavbarcollns::TdxNavBarItemLink* __fastcall GetLinkAtPos(const System::Types::TPoint &pt);
	virtual int __fastcall BorderWidth(void);
	virtual System::Uitypes::TColor __fastcall BorderColor(void);
	virtual System::Uitypes::TColor __fastcall CollapseBarFontColor(void);
	virtual System::Uitypes::TColor __fastcall BottomScrollButtonBackColor(void);
	virtual System::Uitypes::TColor __fastcall BottomScrollButtonBackColor2(void);
	virtual System::Byte __fastcall BottomScrollButtonAlphaBlend(void);
	virtual System::Byte __fastcall BottomScrollButtonAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall BottomScrollButtonGradientMode(void);
	virtual System::Uitypes::TColor __fastcall TopScrollButtonBackColor(void);
	virtual System::Uitypes::TColor __fastcall TopScrollButtonBackColor2(void);
	virtual System::Byte __fastcall TopScrollButtonAlphaBlend(void);
	virtual System::Byte __fastcall TopScrollButtonAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall TopScrollButtonGradientMode(void);
	virtual System::Uitypes::TColor __fastcall HeaderBackColor(void);
	virtual System::Uitypes::TColor __fastcall HeaderBackColor2(void);
	virtual System::Byte __fastcall HeaderAlphaBlend(void);
	virtual System::Byte __fastcall HeaderAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall HeaderGradientMode(void);
	virtual System::Uitypes::TColor __fastcall HeaderFontColor(void);
	virtual System::Uitypes::TColor __fastcall OverflowPanelBackColor(void);
	virtual System::Uitypes::TColor __fastcall OverflowPanelBackColor2(void);
	virtual System::Byte __fastcall OverflowPanelAlphaBlend(void);
	virtual System::Byte __fastcall OverflowPanelAlphaBlend2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall OverflowPanelGradientMode(void);
	virtual System::Uitypes::TColor __fastcall SplitterBackColor(void);
	virtual System::Uitypes::TColor __fastcall SplitterBackColor2(void);
	virtual Dxnavbarstyles::TdxBarStyleGradientMode __fastcall SplitterGradientMode(void);
	virtual void __fastcall AssignDefaultBackgroundStyle(void);
	virtual void __fastcall AssignDefaultButtonStyle(void);
	virtual void __fastcall AssignDefaultGroupBackgroundStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderActiveStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderHotTrackedStyle(void);
	virtual void __fastcall AssignDefaultGroupHeaderPressedStyle(void);
	virtual void __fastcall AssignDefaultItemStyle(void);
	virtual void __fastcall AssignDefaultItemDisabledStyle(void);
	virtual void __fastcall AssignDefaultNavigationPaneHeaderStyle(void);
	__property System::Types::TRect HeaderRect = {read=FHeaderRect};
	__property System::Types::TRect HeaderSignRect = {read=FHeaderSignRect};
	__property System::Types::TRect ItemPanelRect = {read=GetItemPanelRect};
	__property int OverflowPanelItemCount = {read=GetOverflowPanelItemCount, nodefault};
	__property TdxNavBarOverflowPanelViewInfoItem* OverflowPanelItems[int Index] = {read=GetOverflowPanelItems};
	__property System::Types::TRect OverflowPanelRect = {read=GetOverflowPanelRect};
	__property System::Types::TRect OverflowPanelSignRect = {read=GetOverflowPanelSignRect};
	__property int OverflowPanelVisibleItemCount = {read=GetOverflowPanelVisibleItemCount, nodefault};
	__property System::Types::TRect SizeGripRect = {read=FSizeGripRect};
	__property System::Types::TRect SplitterRect = {read=FSplitterRect};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper ActiveGroupCaptionPanelIAccessibilityHelper = {read=GetActiveGroupCaptionPanelIAccessibilityHelper};
	__property Vcl::Controls::TImageList* ImageList = {read=FImageList};
	__property TdxNavBarItemPanelViewInfo* ItemPanelViewInfo = {read=FItemPanelViewInfo};
	__property Vcl::Menus::TPopupMenu* PopupMenu = {read=FPopupMenu};
	__property TdxNavBarNavigationPanePainter* Painter = {read=GetPainter};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper NavPanePartIAccessibilityHelpers[Dxnavbar::TdxNavBarPart APart] = {read=GetNavPanePartIAccessibilityHelper};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper OverflowPanelSignIAccessibilityHelper = {read=GetOverflowPanelSignIAccessibilityHelper};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper OverflowPanelIAccessibilityHelper = {read=GetOverflowPanelIAccessibilityHelper};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper HeaderSignIAccessibilityHelper = {read=GetHeaderSignIAccessibilityHelper};
};


class DELPHICLASS TdxNavBarOffice11NavPaneViewInfo;
class PASCALIMPLEMENTATION TdxNavBarOffice11NavPaneViewInfo : public TdxNavBarNavigationPaneViewInfo
{
	typedef TdxNavBarNavigationPaneViewInfo inherited;
	
public:
	/* TdxNavBarNavigationPaneViewInfo.Create */ inline __fastcall virtual TdxNavBarOffice11NavPaneViewInfo(Dxnavbar::TdxNavBarPainter* APainter) : TdxNavBarNavigationPaneViewInfo(APainter) { }
	/* TdxNavBarNavigationPaneViewInfo.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11NavPaneViewInfo(void) { }
	
};


class DELPHICLASS TdxNavBarPopupControlViewInfo;
class PASCALIMPLEMENTATION TdxNavBarPopupControlViewInfo : public TdxNavBarNavigationPaneCustomViewInfo
{
	typedef TdxNavBarNavigationPaneCustomViewInfo inherited;
	
private:
	System::Types::TRect FRect;
	System::Types::TRect __fastcall GetClientRect(void);
	
protected:
	virtual void __fastcall CalculateBounds(int AClientWidth);
	virtual System::Types::TPoint __fastcall CalculatePosition(void);
	virtual System::Types::TRect __fastcall GetBorderOffsets(void);
	virtual int __fastcall GetMaxHeight(void);
	virtual int __fastcall GetMinWidth(void);
	virtual bool __fastcall IsPtSizeGrip(const System::Types::TPoint &pt);
	
public:
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property System::Types::TRect Rect = {read=FRect};
public:
	/* TdxNavBarNavigationPaneCustomViewInfo.Create */ inline __fastcall virtual TdxNavBarPopupControlViewInfo(Dxnavbar::TdxNavBarViewInfo* AViewInfo) : TdxNavBarNavigationPaneCustomViewInfo(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarPopupControlViewInfo(void) { }
	
};


typedef System::TMetaClass* TdxNavBarPopupControlViewInfoClass;

enum TdxNavBarPopupControlState : unsigned char { pcsSizing, pcsOverSizeGrip };

typedef System::Set<TdxNavBarPopupControlState, TdxNavBarPopupControlState::pcsSizing, TdxNavBarPopupControlState::pcsOverSizeGrip>  TdxNavBarPopupControlStates;

class DELPHICLASS TdxNavBarPopupControl;
class PASCALIMPLEMENTATION TdxNavBarPopupControl : public Cxcontainer::TcxCustomPopupWindow
{
	typedef Cxcontainer::TcxCustomPopupWindow inherited;
	
private:
	int FCapturePointOffset;
	Dxnavbar::TdxCustomNavBar* FNavBar;
	int FOriginalWidth;
	Dxnavbar::TdxCustomNavBar* FInnerControl;
	TdxNavBarPopupControlStates FInternalState;
	Cxcontrols::TcxSizeFrame* FSizeFrame;
	TdxNavBarPopupControlViewInfo* FViewInfo;
	void __fastcall CreateViewInfo(void);
	TdxNavBarNavigationPanePainter* __fastcall GetPainter(void);
	void __fastcall SetNewBounds(int ALeft, int ATop, int AWidth, int AHeight);
	bool __fastcall GetMouseOverSizeGrip(void);
	void __fastcall SetMouseOverSizeGrip(bool AValue);
	__property bool MouseOverSizeGrip = {read=GetMouseOverSizeGrip, write=SetMouseOverSizeGrip, nodefault};
	
protected:
	bool __fastcall NeedAdjustWidth(void);
	virtual System::Types::TPoint __fastcall CalculatePosition(void);
	virtual void __fastcall CalculateSize(void);
	void __fastcall BeginResize(Vcl::Controls::TControl* AControl, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint &APoint);
	void __fastcall EndResize(bool ACancel = false);
	virtual void __fastcall DoShowed(void);
	void __fastcall DrawSizeFrame(const System::Types::TRect &R);
	virtual void __fastcall InitPopup(void);
	DYNAMIC void __fastcall Paint(void);
	void __fastcall RefreshPopupWindow(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedIgnoreMouseMessageAfterCloseUp(NativeUInt AWnd, unsigned AMsg, System::Classes::TShiftState AShift, const System::Types::TPoint &APos);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	
public:
	__fastcall virtual TdxNavBarPopupControl(Dxnavbar::TdxCustomNavBar* ANavBar);
	__fastcall virtual ~TdxNavBarPopupControl(void);
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall Popup(Vcl::Controls::TWinControl* AFocusedControl);
	__property TdxNavBarNavigationPanePainter* Painter = {read=GetPainter};
	__property TdxNavBarPopupControlViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxNavBarPopupControl(System::Classes::TComponent* AOwner, int Dummy) : Cxcontainer::TcxCustomPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxNavBarPopupControl(HWND ParentWindow) : Cxcontainer::TcxCustomPopupWindow(ParentWindow) { }
	
};


enum TdxNavBarNavPanePartState : unsigned char { oisNormal, oisHot, oisPressed, oisChecked, oisHotCheck, oisDroppedDown };

class DELPHICLASS TdxNavBarNavigationPaneController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneController : public Dxnavbarbaseviews::TdxNavBarNavigationBarController
{
	typedef Dxnavbarbaseviews::TdxNavBarNavigationBarController inherited;
	
private:
	TdxNavBarPopupControl* FPopupControl;
	Dxnavbar::TdxNavBarPart FDroppedDownPart;
	void __fastcall CalcOverflowPanelHintRect(System::TObject* AItem, System::Types::TRect &ARect);
	void __fastcall ChangeNavBarCollapseState(void);
	bool __fastcall IsAnyItemHotTracked(void);
	bool __fastcall IsPopupControlExists(void);
	bool __fastcall IsPopupControlVisible(void);
	bool __fastcall IsPopupJustClosed(void);
	bool __fastcall IsOverflowPanelGroupHotTracked(void);
	TdxNavBarNavPanePartState __fastcall GetNavPanePartState(const Dxnavbar::TdxNavBarPart &APart);
	int __fastcall GetOriginalWidth(void);
	HIDESBASE TdxNavBarNavigationPaneViewInfo* __fastcall GetViewInfo(void);
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetOverflowPanelGroup(int AIndex);
	void __fastcall SetDroppedDownPart(const Dxnavbar::TdxNavBarPart &APart);
	void __fastcall SetOriginalWidth(int AValue);
	__property Dxnavbarcollns::TdxNavBarGroup* OverflowPanelGroup[int AIndex] = {read=GetOverflowPanelGroup};
	
protected:
	virtual bool __fastcall CanFocusOnClick(const System::Types::TPoint &APoint);
	virtual HICON __fastcall GetCursor(void);
	virtual Dxnavbar::TdxNavBarPart __fastcall GetPartAtPos(const System::Types::TPoint &APoint);
	virtual void __fastcall DoClick(const Dxnavbar::TdxNavBarPart &APart);
	virtual void __fastcall DoCheckBounds(int &ALeft, int &ATop, int &AWidth, int &AHeight);
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, const System::Types::TPoint &APoint);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState AShift, const System::Types::TPoint &APoint);
	virtual void __fastcall DoMouseLeave(void);
	virtual void __fastcall DoSetHotPart(const Dxnavbar::TdxNavBarPart &APart);
	virtual void __fastcall DoSetPressedPart(const Dxnavbar::TdxNavBarPart &APart);
	virtual void __fastcall DoShowHint(Vcl::Controls::THintInfo &AHintInfo);
	virtual void __fastcall DoShowOverflowPanelHint(Vcl::Controls::THintInfo &AHintInfo);
	virtual System::Types::TRect __fastcall GetNavPaneItemHintRect(const System::Types::TPoint &ACursorPos);
	virtual System::UnicodeString __fastcall GetNavPaneItemHintText(void);
	virtual System::Types::TRect __fastcall GetNavPaneItemHintCursorRect(void);
	void __fastcall DoOverflowPanelItemClick(void);
	void __fastcall DoOverflowPanelSignClick(void);
	void __fastcall DoHeaderSignClick(void);
	void __fastcall DoCollapseBarClick(void);
	void __fastcall DoCollapseItemClick(void);
	void __fastcall DoSplitterDrag(const System::Types::TPoint &APoint);
	void __fastcall CollapseStateChaged(System::TObject* Sender);
	__property int OriginalWidth = {read=GetOriginalWidth, write=SetOriginalWidth, nodefault};
	__property TdxNavBarPopupControl* PopupControl = {read=FPopupControl};
	
public:
	__fastcall virtual TdxNavBarNavigationPaneController(Dxnavbar::TdxCustomNavBar* ANavBar);
	__fastcall virtual ~TdxNavBarNavigationPaneController(void);
	bool __fastcall Collapsible(void);
	bool __fastcall Collapsed(void);
	void __fastcall ClosePopupControl(void);
	void __fastcall ShowPopupControl(void);
	__property Dxnavbar::TdxNavBarPart DroppedDownPart = {read=FDroppedDownPart, write=SetDroppedDownPart};
	__property TdxNavBarNavigationPaneViewInfo* ViewInfo = {read=GetViewInfo};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarNavigationPanePainter : public Dxnavbarofficeviews::TdxNavBarOffice3Painter
{
	typedef Dxnavbarofficeviews::TdxNavBarOffice3Painter inherited;
	
private:
	TdxNavBarNavigationPaneController* __fastcall GetController(void);
	TdxNavBarOverflowPanelViewInfo* __fastcall GetOverflowPanelViewInfo(void);
	TdxNavBarNavigationPaneViewInfo* __fastcall GetViewInfo(void);
	void __fastcall DrawItemPanelPartFocusRect(const System::Types::TRect &APartRect);
	void __fastcall DrawVerticalText(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, const System::Types::TRect &ARect, TdxNavBarNavPanePartState AState);
	void __fastcall DrawOverflowPanelItemBackground(Vcl::Graphics::TCanvas* ACanvas, TdxNavBarNavPanePartState AState, const System::Types::TRect &ARect)/* overload */;
	void __fastcall DrawOverflowPanelItemBackground(Vcl::Graphics::TCanvas* ACanvas, const Dxnavbar::TdxNavBarPart &APart, const System::Types::TRect &ARect)/* overload */;
	
protected:
	TdxNavBarPopupControlViewInfo* __fastcall CreatePopupControlViewInfo(void);
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	virtual Dxnavbar::TdxNavBarControllerClass __fastcall GetControllerClass(void);
	__classmethod virtual TdxNavBarPopupControlViewInfoClass __fastcall GetPopupControlViewInfoClass();
	TdxNavBarNavPanePartState __fastcall GetNavPanePartState(const Dxnavbar::TdxNavBarPart &APart);
	virtual void __fastcall DoDrawHeader(void);
	virtual void __fastcall DoDrawOverflowPanel(void);
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DoDrawSplitter(void);
	
public:
	virtual void __fastcall DrawNavBarControl(void);
	virtual void __fastcall DrawGroupBackground(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaption(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawSizeGrip(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawHintWindow(Dxnavbar::TdxNavBarHintWindow* AHintWindow);
	virtual void __fastcall DrawItemPanel(void);
	virtual void __fastcall DrawItemsRect(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawGroupCaptionButton(Dxnavbar::TdxNavBarGroupViewInfo* AGroupViewInfo);
	virtual void __fastcall DrawCollapseBar(TdxNavBarItemPanelViewInfo* AItemPanelViewInfo);
	virtual void __fastcall DrawCollapseElementBackground(const System::Types::TRect &ARect, TdxNavBarNavPanePartState AState);
	virtual void __fastcall DrawCollapseItem(TdxNavBarItemPanelViewInfoItem* AItemViewInfo, TdxNavBarNavPanePartState AState);
	virtual void __fastcall DrawBorder(void);
	virtual void __fastcall DrawHeader(void);
	virtual void __fastcall DrawHeaderBackground(void);
	virtual void __fastcall DrawHeaderSign(void);
	virtual void __fastcall DrawHeaderText(void);
	virtual void __fastcall DrawOverflowPanel(void);
	virtual void __fastcall DrawOverflowPanelBackground(void);
	virtual void __fastcall DrawOverflowPanelSign(void);
	virtual void __fastcall DrawOverflowPanelItems(void);
	virtual void __fastcall DrawOverflowPanelHintWindow(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawPopupControl(Cxgraphics::TcxCanvas* ACanvas, TdxNavBarPopupControlViewInfo* AViewInfo);
	virtual void __fastcall DrawSplitter(void);
	virtual void __fastcall DrawSplitterSign(void);
	virtual void __fastcall DrawPopupMenuItem(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex, System::UnicodeString AText, Dxnavbar::TdxNavBarObjectStates State);
	__property TdxNavBarNavigationPaneController* Controller = {read=GetController};
	__property TdxNavBarOverflowPanelViewInfo* OverflowPanelViewInfo = {read=GetOverflowPanelViewInfo};
	__property TdxNavBarNavigationPaneViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarNavigationPanePainter(Dxnavbar::TdxCustomNavBar* ANavBar) : Dxnavbarofficeviews::TdxNavBarOffice3Painter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPanePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarNavigationPaneButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarNavigationPaneButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOffice11NavPaneButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice11NavPaneButtonPainter : public TdxNavBarNavigationPaneButtonPainter
{
	typedef TdxNavBarNavigationPaneButtonPainter inherited;
	
public:
	/* TObject.Create */ inline __fastcall TdxNavBarOffice11NavPaneButtonPainter(void) : TdxNavBarNavigationPaneButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11NavPaneButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOffice11NavPanePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice11NavPanePainter : public TdxNavBarNavigationPanePainter
{
	typedef TdxNavBarNavigationPanePainter inherited;
	
protected:
	__classmethod virtual Dxnavbar::TdxNavBarGroupViewInfoClass __fastcall GetGroupViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarLinkViewInfoClass __fastcall GetLinkViewInfoClass();
	__classmethod virtual Dxnavbar::TdxNavBarViewInfoClass __fastcall GetViewInfoClass();
	__classmethod virtual Dxnavbarcustompainters::TdxNavBarCustomButtonPainterClass __fastcall ButtonPainterClass();
public:
	/* TdxNavBarPainter.Create */ inline __fastcall virtual TdxNavBarOffice11NavPanePainter(Dxnavbar::TdxCustomNavBar* ANavBar) : TdxNavBarNavigationPanePainter(ANavBar) { }
	/* TdxNavBarPainter.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11NavPanePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarOffice11NavPaneGroupButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarOffice11NavPaneGroupButtonPainter : public Dxnavbarcustompainters::TdxNavBarCustomButtonPainter
{
	typedef Dxnavbarcustompainters::TdxNavBarCustomButtonPainter inherited;
	
protected:
	__classmethod virtual void __fastcall InternalDrawButton(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode, System::Uitypes::TColor ABorderColor, Dxnavbar::TdxNavBarObjectStates AState);
public:
	/* TObject.Create */ inline __fastcall TdxNavBarOffice11NavPaneGroupButtonPainter(void) : Dxnavbarcustompainters::TdxNavBarCustomButtonPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxNavBarOffice11NavPaneGroupButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarItemCollectionItemAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarItemCollectionItemAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	int FItemIndex;
	
public:
	__property int ItemIndex = {read=FItemIndex, write=FItemIndex, nodefault};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarItemCollectionItemAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarItemCollectionItemAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxNavBarItemCollectionItemAccessibilityHelperClass;

class DELPHICLASS TdxNavBarItemCollectionAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarItemCollectionAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	System::Classes::TInterfaceList* FItemIAccessibilityHelpers;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetItemIAccessibilityHelper(int AIndex);
	int __fastcall GetItemIAccessibilityHelperCount(void);
	void __fastcall SetItemIAccessibilityHelperCount(int Value);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetActualItemCount(void) = 0 ;
	virtual TdxNavBarItemCollectionItemAccessibilityHelperClass __fastcall GetItemAccessibilityHelperClass(void) = 0 ;
	virtual bool __fastcall IsContainer(void);
	
public:
	__fastcall virtual TdxNavBarItemCollectionAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl);
	__fastcall virtual ~TdxNavBarItemCollectionAccessibilityHelper(void);
	void __fastcall CheckItemIAccessibilityHelperCount(void);
	__property int ItemIAccessibilityHelperCount = {read=GetItemIAccessibilityHelperCount, nodefault};
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper ItemIAccessibilityHelpers[int AIndex] = {read=GetItemIAccessibilityHelper};
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarNavigationPaneOverflowPanelAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneOverflowPanelAccessibilityHelper : public TdxNavBarItemCollectionAccessibilityHelper
{
	typedef TdxNavBarItemCollectionAccessibilityHelper inherited;
	
private:
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FSignIAccessibilityHelper;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetSignIAccessibilityHelper(void);
	TdxNavBarOverflowPanelViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual int __fastcall GetActualItemCount(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual TdxNavBarItemCollectionItemAccessibilityHelperClass __fastcall GetItemAccessibilityHelperClass(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetSignAccessibilityHelperClass(void);
	__property TdxNavBarOverflowPanelViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual ~TdxNavBarNavigationPaneOverflowPanelAccessibilityHelper(void);
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper SignIAccessibilityHelper = {read=GetSignIAccessibilityHelper};
public:
	/* TdxNavBarItemCollectionAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarNavigationPaneOverflowPanelAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : TdxNavBarItemCollectionAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarNavigationPaneOverflowPanelItemAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneOverflowPanelItemAccessibilityHelper : public TdxNavBarItemCollectionItemAccessibilityHelper
{
	typedef TdxNavBarItemCollectionItemAccessibilityHelper inherited;
	
private:
	Dxnavbarcollns::TdxNavBarGroup* __fastcall GetGroup(void);
	TdxNavBarNavigationPaneViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual void __fastcall Click(System::Word AKey);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsClickKey(System::Word AKey);
	virtual bool __fastcall IsContainer(void);
	__property Dxnavbarcollns::TdxNavBarGroup* Group = {read=GetGroup};
	__property TdxNavBarNavigationPaneViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarNavigationPaneOverflowPanelItemAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : TdxNavBarItemCollectionItemAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneOverflowPanelItemAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarNavigationPaneOverflowPanelSignAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneOverflowPanelSignAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	TdxNavBarNavigationPaneViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual void __fastcall Click(System::Word AKey);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsClickKey(System::Word AKey);
	virtual bool __fastcall IsContainer(void);
	__property TdxNavBarNavigationPaneViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarNavigationPaneOverflowPanelSignAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneOverflowPanelSignAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarNavigationPaneActiveGroupCaptionPanelAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneActiveGroupCaptionPanelAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	Dxnavbar::TdxNavBarGroupViewInfo* __fastcall GetGroupViewInfo(void);
	Dxnavbar::TdxCustomNavBar* __fastcall GetNavBar(void);
	TdxNavBarNavigationPaneViewInfo* __fastcall GetNavBarViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall CanBeFocusedByDefault(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelper* __fastcall GetAssociatedObject(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsContainer(void);
	__property Dxnavbar::TdxCustomNavBar* NavBar = {read=GetNavBar};
	__property TdxNavBarNavigationPaneViewInfo* NavBarViewInfo = {read=GetNavBarViewInfo};
	__property Dxnavbar::TdxNavBarGroupViewInfo* GroupViewInfo = {read=GetGroupViewInfo};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarNavigationPaneActiveGroupCaptionPanelAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneActiveGroupCaptionPanelAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarNavigationPaneHeaderSignAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarNavigationPaneHeaderSignAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	TdxNavBarNavigationPaneViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual void __fastcall Click(System::Word AKey);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsClickKey(System::Word AKey);
	virtual bool __fastcall IsContainer(void);
	__property TdxNavBarNavigationPaneViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarNavigationPaneHeaderSignAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarNavigationPaneHeaderSignAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarItemPanelAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarItemPanelAccessibilityHelper : public TdxNavBarItemCollectionAccessibilityHelper
{
	typedef TdxNavBarItemCollectionAccessibilityHelper inherited;
	
private:
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper FCollapseBarIAccessibilityHelper;
	Dxnavbarbase::_di_IdxNavBarAccessibilityHelper __fastcall GetCollapseBarIAccessibilityHelper(void);
	TdxNavBarItemPanelViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual int __fastcall GetActualItemCount(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual Dxnavbarbase::TdxNavBarCustomAccessibilityHelperClass __fastcall GetCollapseBarAccessibilityHelperClass(void);
	virtual TdxNavBarItemCollectionItemAccessibilityHelperClass __fastcall GetItemAccessibilityHelperClass(void);
	__property TdxNavBarItemPanelViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual ~TdxNavBarItemPanelAccessibilityHelper(void);
	__property Dxnavbarbase::_di_IdxNavBarAccessibilityHelper CollapseBarIAccessibilityHelper = {read=GetCollapseBarIAccessibilityHelper};
public:
	/* TdxNavBarItemCollectionAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarItemPanelAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : TdxNavBarItemCollectionAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarItemPanelCollapseBarAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarItemPanelCollapseBarAccessibilityHelper : public Dxnavbarbase::TdxNavBarCustomAccessibilityHelper
{
	typedef Dxnavbarbase::TdxNavBarCustomAccessibilityHelper inherited;
	
private:
	TdxNavBarItemPanelViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall CanBeFocusedByDefault(void);
	virtual void __fastcall Click(System::Word AKey);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsClickKey(System::Word AKey);
	virtual bool __fastcall IsContainer(void);
	__property TdxNavBarItemPanelViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarItemPanelCollapseBarAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : Dxnavbarbase::TdxNavBarCustomAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarItemPanelCollapseBarAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxNavBarItemPanelItemAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarItemPanelItemAccessibilityHelper : public TdxNavBarItemCollectionItemAccessibilityHelper
{
	typedef TdxNavBarItemCollectionItemAccessibilityHelper inherited;
	
private:
	TdxNavBarItemPanelViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall CanBeFocusedByDefault(void);
	virtual void __fastcall Click(System::Word AKey);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual bool __fastcall IsClickKey(System::Word AKey);
	virtual bool __fastcall IsContainer(void);
	__property TdxNavBarItemPanelViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxNavBarCustomAccessibilityHelper.Create */ inline __fastcall virtual TdxNavBarItemPanelItemAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl) : TdxNavBarItemCollectionItemAccessibilityHelper(AOwnerObject, AOwnerObjectControl) { }
	/* TdxNavBarCustomAccessibilityHelper.Destroy */ inline __fastcall virtual ~TdxNavBarItemPanelItemAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 nbOverflowPanelSign = System::Int8(0x0);
static const System::Int8 nbOverflowPanelItem = System::Int8(0x1);
static const System::Int8 nbHeaderSign = System::Int8(0x2);
static const System::Int8 nbSplitter = System::Int8(0x3);
static const System::Int8 nbItemPanelCollapseItem = System::Int8(0x4);
static const System::Int8 nbItemPanelCollapseBar = System::Int8(0x5);
}	/* namespace Dxnavbaroffice11views */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBAROFFICE11VIEWS)
using namespace Dxnavbaroffice11views;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxnavbaroffice11viewsHPP
