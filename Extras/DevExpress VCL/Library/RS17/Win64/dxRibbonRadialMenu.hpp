// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonRadialMenu.pas' rev: 24.00 (Win64)

#ifndef DxribbonradialmenuHPP
#define DxribbonradialmenuHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarSkinConsts.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit
#include <dxBarStrs.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <dxBarAccessibility.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonradialmenu
{
//-- type declarations -------------------------------------------------------
enum TdxRadialMenuState : unsigned char { rmsClosed, rmsCollapsed, rmsExpanded };

enum TdxRadialMenuMode : unsigned char { rmmAutoHide, rmmAutoCollapse };

class DELPHICLASS TdxRadialMenuDropDownList;
class PASCALIMPLEMENTATION TdxRadialMenuDropDownList : public Dxcoreclasses::TcxDoublyLinkedDataList
{
	typedef Dxcoreclasses::TcxDoublyLinkedDataList inherited;
	
public:
	virtual Dxcoreclasses::TcxDoublyLinkedObjectClass __fastcall GetLinkedObjectClass(void);
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TdxRadialMenuDropDownList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxRadialMenuDropDownList(void) : Dxcoreclasses::TcxDoublyLinkedDataList() { }
	
};


class DELPHICLASS TdxRadialMenuDropDownData;
class PASCALIMPLEMENTATION TdxRadialMenuDropDownData : public Dxcoreclasses::TcxDoublyLinkedData
{
	typedef Dxcoreclasses::TcxDoublyLinkedData inherited;
	
private:
	int FStartIndex;
public:
	/* TObject.Create */ inline __fastcall TdxRadialMenuDropDownData(void) : Dxcoreclasses::TcxDoublyLinkedData() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRadialMenuDropDownData(void) { }
	
};


class DELPHICLASS TdxRibbonCustomRadialMenu;
class PASCALIMPLEMENTATION TdxRibbonCustomRadialMenu : public Dxbar::TdxBarCustomPopupMenuComponent
{
	typedef Dxbar::TdxBarCustomPopupMenuComponent inherited;
	
private:
	Cxclasses::TcxComponentHolder* FRibbonHolder;
	Dxgdiplusclasses::TdxSmartImage* FGlyph;
	int FInnerSize;
	int FMenuSize;
	int FSectorCount;
	System::Classes::TNotifyEvent FOnCloseUp;
	System::Classes::TNotifyEvent FOnCollapse;
	System::Classes::TNotifyEvent FOnExpand;
	System::Classes::TNotifyEvent FOnPopup;
	void __fastcall InternalShowRadialMenu(int X, int Y, TdxRadialMenuMode AMode);
	Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	void __fastcall SetGlyph(Dxgdiplusclasses::TdxSmartImage* AGlyph);
	void __fastcall SetRibbon(Dxribbon::TdxCustomRibbon* AValue);
	
protected:
	virtual Dxbar::TCustomdxBarControl* __fastcall CreateBarControl(void);
	virtual Dxbar::TCustomdxBarControlClass __fastcall GetControlClass(void);
	virtual Dxbar::TdxBarItemLinksClass __fastcall GetItemLinksClass(void);
	__property int MenuSize = {read=FMenuSize, write=FMenuSize, default=0};
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=GetRibbon, write=SetRibbon};
	__property System::Classes::TNotifyEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	__property System::Classes::TNotifyEvent OnCollapse = {read=FOnCollapse, write=FOnCollapse};
	__property System::Classes::TNotifyEvent OnExpand = {read=FOnExpand, write=FOnExpand};
	__property System::Classes::TNotifyEvent OnPopup = {read=FOnPopup, write=FOnPopup};
	
public:
	__fastcall virtual TdxRibbonCustomRadialMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonCustomRadialMenu(void);
	virtual void __fastcall Popup(int X, int Y);
	void __fastcall Show(int X, int Y);
	void __fastcall Hide(void);
	__property Dxgdiplusclasses::TdxSmartImage* Glyph = {read=FGlyph, write=SetGlyph};
};


class DELPHICLASS TdxRibbonRadialMenu;
class PASCALIMPLEMENTATION TdxRibbonRadialMenu : public TdxRibbonCustomRadialMenu
{
	typedef TdxRibbonCustomRadialMenu inherited;
	
__published:
	__property Glyph;
	__property ItemLinks;
	__property Images;
	__property Ribbon;
	__property Font;
	__property UseOwnFont;
	__property OnCloseUp;
	__property OnCollapse;
	__property OnExpand;
	__property OnPopup;
public:
	/* TdxRibbonCustomRadialMenu.Create */ inline __fastcall virtual TdxRibbonRadialMenu(System::Classes::TComponent* AOwner) : TdxRibbonCustomRadialMenu(AOwner) { }
	/* TdxRibbonCustomRadialMenu.Destroy */ inline __fastcall virtual ~TdxRibbonRadialMenu(void) { }
	
};


struct DECLSPEC_DRECORD TdxRibbonRadialMenuHitTest
{
public:
	int SectorIndex;
	Dxbar::TdxBarItem* Item;
	int HitTestCode;
};


class DELPHICLASS TdxRibbonRadialMenuControl;
class PASCALIMPLEMENTATION TdxRibbonRadialMenuControl : public Dxbar::TCustomdxBarControl
{
	typedef Dxbar::TCustomdxBarControl inherited;
	
private:
	TdxRibbonCustomRadialMenu* FRadialMenu;
	Dxgdiplusclasses::TdxSmartImage* FBackArrowImage;
	TdxRadialMenuDropDownList* FDropDownsList;
	TdxRadialMenuState FExpandState;
	TdxRibbonRadialMenuHitTest FHitTest;
	TdxRadialMenuMode FMenuMode;
	bool FKeytipsWaiting;
	System::Classes::TList* FInternalVisibleLinks;
	System::Contnrs::TObjectList* FInternalItems;
	Dxbar::TdxBarInternalItemLinks* FInternalItemLinks;
	System::Uitypes::TColor FBaseAccentColor;
	System::Uitypes::TColor FBaseBackgroundColor;
	System::Uitypes::TColor FItemRingDefaultColor;
	System::Uitypes::TColor FItemTextColor;
	System::Uitypes::TColor FDropDownItemRingNormalColor;
	System::Uitypes::TColor FDropDownItemRingHotColor;
	System::Uitypes::TColor FBackArrowColor;
	int FMenuSize;
	int FInnerSize;
	int FSectorCount;
	System::Types::TPoint FMenuCenter;
	System::Types::TRect FCoreRingRect;
	System::Types::TRect FFullRingRect;
	System::Types::TRect FItemContentRingRect;
	System::Types::TRect FSmallRingRect;
	System::Types::TRect FThickRingRect;
	Dxanimation::TdxAnimationTransition* FShowAnimation;
	Dxanimation::TdxAnimationTransition* FHideAnimation;
	int FAnimationStep;
	void __fastcall SetHotItem(const System::Types::TPoint P)/* overload */;
	void __fastcall SetHotItem(int ASectorIndex, bool AInEdge = false)/* overload */;
	Dxbar::TdxBarItem* __fastcall GetClickableItem(Dxbar::TdxBarItem* AItem);
	int __fastcall GetVisibleItemCount(Dxbar::TdxBarItemLinks* AItemLinks);
	Dxbar::TdxBarItemLink* __fastcall GetCoreItemLink(void);
	Dxbar::TdxBarItemLinks* __fastcall GetCurrentItemLinks(void);
	int __fastcall GetCurrentItemLinksStartIndex(void);
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetCurrentCoreImage(void);
	Cxgeometry::TdxSector __fastcall GetItemSector(int ASectorIndex);
	Dxbar::TdxBarItem* __fastcall GetVisibleItem(int ASectorIndex);
	void __fastcall SetCurrentItemLinks(Dxbar::TdxBarItemLinks* AValue, int AStartIndex);
	void __fastcall SetExpandState(TdxRadialMenuState Value);
	void __fastcall ActivateRootLevel(void);
	void __fastcall InternalHide(void);
	bool __fastcall InternalClick(Dxbar::TdxBarItem* AItem);
	void __fastcall InternalCoreClick(void);
	bool __fastcall InternalCloseLastLevel(void);
	bool __fastcall InternalPopup(int ASectorIndex);
	bool __fastcall HandleNavigationKey(System::Word &AKey);
	void __fastcall SynchronizeInternalItems(void);
	bool __fastcall IsAnimationInProcess(void);
	void __fastcall ShowAnimationStep(Dxanimation::TdxAnimationTransition* Sender, int &APosition, bool &AFinished);
	void __fastcall HideAnimationStep(Dxanimation::TdxAnimationTransition* Sender, int &APosition, bool &AFinished);
	void __fastcall ShowAnimationTerminated(System::TObject* Sender);
	void __fastcall HideAnimationTerminated(System::TObject* Sender);
	TdxRadialMenuState __fastcall GetRealState(void);
	__property Dxbar::TdxBarItemLink* CoreItemLink = {read=GetCoreItemLink};
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Paint(void);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Dxbar::TCustomdxBarControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall SetItemLinks(Dxbar::TdxBarItemLinks* Value);
	virtual void __fastcall DoCreateControls(void);
	virtual void __fastcall SetFont(void);
	virtual void __fastcall ViewStateChanged(Dxbar::TdxBarViewState APrevValue);
	virtual void __fastcall DoHideAll(Dxbar::TdxBarCloseUpReason AReason);
	virtual void __fastcall NavigationHandler(System::Word &ACharCode, System::Classes::TShiftState AShiftState);
	virtual bool __fastcall NeedsKey(System::Word AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall DoKeyDown(Winapi::Messages::TWMKey &Message);
	virtual void __fastcall DoLButtonUp(Winapi::Messages::TWMMouse &Message);
	virtual void __fastcall DoBarMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, const System::Types::TPoint APoint, Dxbar::TdxBarItemControl* AItemControl, bool APointInClientRect);
	virtual void __fastcall DoBarMouseMove(System::Classes::TShiftState Shift, const System::Types::TPoint APoint, Dxbar::TdxBarItemControl* AItemControl);
	void __fastcall CalculateRects(void);
	void __fastcall InitializeColors(Dxbar::_di_IdxSkin ASkin);
	void __fastcall DrawRadialItemBackGround(Cxgraphics::TcxCanvas* ACanvas, Dxgdiplusclasses::TdxGPGraphics* AGPGraphics, Dxbar::TdxBarItem* AItem, Cxgeometry::TdxSector ASector);
	void __fastcall DrawRadialItemContent(Cxgraphics::TcxCanvas* ACanvas, Dxgdiplusclasses::TdxGPGraphics* AGPGraphics, Dxbar::TdxBarItem* AItem, System::Types::TRect &ARect);
	void __fastcall DrawRadialItems(Cxgraphics::TcxCanvas* ACanvas, Dxgdiplusclasses::TdxGPGraphics* AGPGraphics);
	void __fastcall DrawRadialMenu(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawRadialCore(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall UpdateLayer(void);
	__property TdxRadialMenuState ExpandState = {read=FExpandState, write=SetExpandState, nodefault};
	
public:
	__fastcall virtual TdxRibbonRadialMenuControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonRadialMenuControl(void);
	virtual void __fastcall Show(void);
	virtual void __fastcall Hide(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonRadialMenuControl(HWND ParentWindow) : Dxbar::TCustomdxBarControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonRadialMenuControlViewInfo;
class PASCALIMPLEMENTATION TdxRibbonRadialMenuControlViewInfo : public Dxbar::TCustomdxBarControlViewInfo
{
	typedef Dxbar::TCustomdxBarControlViewInfo inherited;
	
public:
	__fastcall virtual TdxRibbonRadialMenuControlViewInfo(Dxbar::TCustomdxBarControl* ABarControl);
	__fastcall virtual ~TdxRibbonRadialMenuControlViewInfo(void);
};


class DELPHICLASS TdxRibbonRadialMenuAccessibilityHelper;
class PASCALIMPLEMENTATION TdxRibbonRadialMenuAccessibilityHelper : public Dxbaraccessibility::TCustomdxBarControlAccessibilityHelper
{
	typedef Dxbaraccessibility::TCustomdxBarControlAccessibilityHelper inherited;
	
private:
	Dxbar::_di_IdxBarKeyTipWindowsManager FKeyTipWindowsManager;
	HIDESBASE TdxRibbonRadialMenuControl* __fastcall GetBarControl(void);
	void __fastcall ActivateKeyTips(Dxbar::_di_IdxBarAccessibilityHelper AHelper);
	
protected:
	virtual bool __fastcall AreKeyTipsSupported(/* out */ Dxbar::_di_IdxBarKeyTipWindowsManager &AKeyTipWindowsManager);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetDefaultAccessibleObject(void);
	virtual void __fastcall InitializeItemKeyTipPosition(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	int __fastcall GetChildSectorIndex(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper)/* overload */;
	int __fastcall GetChildSectorIndex(int AChildIndex)/* overload */;
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual void __fastcall DoClickItem(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper);
	virtual void __fastcall DoDropDownItem(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper);
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	__property TdxRibbonRadialMenuControl* BarControl = {read=GetBarControl};
	
public:
	__fastcall virtual TdxRibbonRadialMenuAccessibilityHelper(System::TObject* AOwnerObject);
	__fastcall virtual ~TdxRibbonRadialMenuAccessibilityHelper(void);
};


class DELPHICLASS TdxRibbonRadialMenuKeyTipWindows;
class PASCALIMPLEMENTATION TdxRibbonRadialMenuKeyTipWindows : public Dxribbon::TdxRibbonCustomKeyTipWindows
{
	typedef Dxribbon::TdxRibbonCustomKeyTipWindows inherited;
	
public:
	/* TdxRibbonCustomKeyTipWindows.Create */ inline __fastcall TdxRibbonRadialMenuKeyTipWindows(Dxribbon::TdxCustomRibbon* ARibbon) : Dxribbon::TdxRibbonCustomKeyTipWindows(ARibbon) { }
	/* TdxRibbonCustomKeyTipWindows.Destroy */ inline __fastcall virtual ~TdxRibbonRadialMenuKeyTipWindows(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxribbonradialmenu */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONRADIALMENU)
using namespace Dxribbonradialmenu;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonradialmenuHPP
