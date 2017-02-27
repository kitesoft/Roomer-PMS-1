// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonBackstageView.pas' rev: 24.00 (Win64)

#ifndef DxribbonbackstageviewHPP
#define DxribbonbackstageviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxBarStrs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <dxBarAccessibility.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit
#include <dxRibbonFormCaptionHelper.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonbackstageview
{
//-- type declarations -------------------------------------------------------
enum TdxRibbonBackstageViewChange : unsigned char { rbvcStruct, rbvcItemsData, rbvcTabsData };

typedef System::Set<TdxRibbonBackstageViewChange, TdxRibbonBackstageViewChange::rbvcStruct, TdxRibbonBackstageViewChange::rbvcTabsData>  TdxRibbonBackstageViewChanges;

enum TdxRibbonBackstageViewMenuButtonPosition : unsigned char { mbpBeforeTabs, mbpAfterTabs };

__interface IdxRibbonBackstageViewSelectableItem;
typedef System::DelphiInterface<IdxRibbonBackstageViewSelectableItem> _di_IdxRibbonBackstageViewSelectableItem;
__interface  INTERFACE_UUID("{D5E058AB-1C90-4D21-BE0A-EB48530EF53B}") IdxRibbonBackstageViewSelectableItem  : public System::IInterface 
{
	
public:
	virtual void __fastcall SelectionChanged(void) = 0 ;
};

__interface IdxRibbonBackstageViewKeyTipPositionInfo;
typedef System::DelphiInterface<IdxRibbonBackstageViewKeyTipPositionInfo> _di_IdxRibbonBackstageViewKeyTipPositionInfo;
__interface  INTERFACE_UUID("{7947E0B2-BBED-4AE0-9C34-5B578B412780}") IdxRibbonBackstageViewKeyTipPositionInfo  : public System::IInterface 
{
	
public:
	virtual System::Types::TPoint __fastcall GetKeyTipBasePoint(void) = 0 ;
};

class DELPHICLASS TdxRibbonBackstageViewCustomObject;
class DELPHICLASS TdxRibbonCustomBackstageView;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewCustomObject : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TdxRibbonCustomBackstageView* FBackstageView;
	Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	bool __fastcall GetIsBarManagerValid(void);
	
public:
	__fastcall virtual TdxRibbonBackstageViewCustomObject(TdxRibbonCustomBackstageView* ABackstageView);
	__property TdxRibbonCustomBackstageView* BackstageView = {read=FBackstageView};
	__property Dxbar::TdxBarManager* BarManager = {read=GetBarManager};
	__property bool IsBarManagerValid = {read=GetIsBarManagerValid, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewCustomObject(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewCustomViewInfo;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewCustomViewInfo : public TdxRibbonBackstageViewCustomObject
{
	typedef TdxRibbonBackstageViewCustomObject inherited;
	
private:
	System::Types::TRect FBounds;
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	__property System::Types::TRect Bounds = {read=FBounds};
public:
	/* TdxRibbonBackstageViewCustomObject.Create */ inline __fastcall virtual TdxRibbonBackstageViewCustomViewInfo(TdxRibbonCustomBackstageView* ABackstageView) : TdxRibbonBackstageViewCustomObject(ABackstageView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewCustomViewInfo(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuBarAccessibilityHelper;
class DELPHICLASS TdxRibbonBackstageViewTabSheet;
class DELPHICLASS TdxRibbonBackstageViewMenuBarControl;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuBarAccessibilityHelper : public Dxribbon::TdxRibbonBarControlAccessibilityHelper
{
	typedef Dxribbon::TdxRibbonBarControlAccessibilityHelper inherited;
	
private:
	Dxbar::_di_IdxBarKeyTipWindowsManager FKeyTipWindowsManager;
	TdxRibbonBackstageViewTabSheet* __fastcall GetActiveTab(void);
	TdxRibbonCustomBackstageView* __fastcall GetBackstageView(void);
	TdxRibbonBackstageViewMenuBarControl* __fastcall GetMenuBarControl(void);
	
protected:
	virtual bool __fastcall AreKeyTipsSupported(/* out */ Dxbar::_di_IdxBarKeyTipWindowsManager &AKeyTipWindowsManager);
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual void __fastcall InitializeItemKeyTipPosition(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual void __fastcall KeyTipsEscapeHandler(void);
	
public:
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetDefaultSelectableObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection);
	__property TdxRibbonBackstageViewTabSheet* ActiveTab = {read=GetActiveTab};
	__property TdxRibbonCustomBackstageView* BackstageView = {read=GetBackstageView};
	__property TdxRibbonBackstageViewMenuBarControl* MenuBarControl = {read=GetMenuBarControl};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonBackstageViewMenuBarAccessibilityHelper(System::TObject* AOwnerObject) : Dxribbon::TdxRibbonBarControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuBarAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuViewInfo;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuBarControl : public Dxribbon::TdxRibbonCustomBarControl
{
	typedef Dxribbon::TdxRibbonCustomBarControl inherited;
	
private:
	TdxRibbonCustomBackstageView* __fastcall GetBackstageView(void);
	TdxRibbonBackstageViewMenuViewInfo* __fastcall GetMenuViewInfo(void);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseWheel(Winapi::Messages::TWMMouseWheel &Message);
	
protected:
	virtual void __fastcall DoBarMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, const System::Types::TPoint APoint, Dxbar::TdxBarItemControl* AItemControl, bool APointInClientRect);
	virtual System::Types::TRect __fastcall CalcColumnItemRect(Dxbar::TdxBarItemLink* AItemLink, const System::Types::TRect &AItemsRect);
	virtual bool __fastcall CanCustomizing(void);
	virtual bool __fastcall CanDrawClippedItem(System::Types::TRect &AItemRect);
	virtual void __fastcall CalcControlsPositions(void);
	virtual void __fastcall DoKeyDown(Winapi::Messages::TWMKey &Message);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Vcl::Controls::TCaption __fastcall GetCaption(void);
	virtual int __fastcall GetItemControlOffset(Dxbar::TdxBarItemLink* AItemLink);
	virtual System::Types::TRect __fastcall GetItemsRectOffset(void);
	virtual int __fastcall GetMaxWidth(Dxbar::TdxBarDockingStyle AStyle);
	virtual int __fastcall GetMinWidth(Dxbar::TdxBarDockingStyle AStyle);
	virtual Dxbar::TdxBarControl* __fastcall GetNextBarControl(bool AForward);
	virtual Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	virtual Dxbar::TCustomdxBarControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall HasCaptionButtons(void);
	virtual bool __fastcall IsInternal(void);
	virtual bool __fastcall NeedsMouseWheel(void);
	virtual void __fastcall MakeItemControlFullyVisible(Dxbar::TdxBarItemControl* AItemControl);
	virtual void __fastcall SetLayeredAttributes(void);
	virtual void __fastcall ShowPopup(Dxbar::TdxBarItemControl* AItem);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property TdxRibbonCustomBackstageView* BackstageView = {read=GetBackstageView};
	__property TdxRibbonBackstageViewMenuViewInfo* MenuViewInfo = {read=GetMenuViewInfo};
	
public:
	virtual bool __fastcall IsVertical(void);
public:
	/* TdxBarPopupControl.Create */ inline __fastcall virtual TdxRibbonBackstageViewMenuBarControl(System::Classes::TComponent* AOwner) : Dxribbon::TdxRibbonCustomBarControl(AOwner) { }
	/* TdxBarPopupControl.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuBarControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewMenuBarControl(HWND ParentWindow) : Dxribbon::TdxRibbonCustomBarControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuBarControlViewInfo;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuBarControlViewInfo : public Dxbar::TdxBarControlViewInfo
{
	typedef Dxbar::TdxBarControlViewInfo inherited;
	
protected:
	virtual void __fastcall DoCalcSeparatorInfo(Dxbar::TdxBarItemLink* AItemLink, const System::Types::TRect &AItemRect);
public:
	/* TCustomdxBarControlViewInfo.Create */ inline __fastcall virtual TdxRibbonBackstageViewMenuBarControlViewInfo(Dxbar::TCustomdxBarControl* ABarControl) : Dxbar::TdxBarControlViewInfo(ABarControl) { }
	/* TCustomdxBarControlViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuBarControlViewInfo(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewKeyTipWindows;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewKeyTipWindows : public Dxribbon::TdxRibbonCustomKeyTipWindows
{
	typedef Dxribbon::TdxRibbonCustomKeyTipWindows inherited;
	
public:
	/* TdxRibbonCustomKeyTipWindows.Create */ inline __fastcall TdxRibbonBackstageViewKeyTipWindows(Dxribbon::TdxCustomRibbon* ARibbon) : Dxribbon::TdxRibbonCustomKeyTipWindows(ARibbon) { }
	/* TdxRibbonCustomKeyTipWindows.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewKeyTipWindows(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewPainter;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxRibbonCustomBackstageView* FBackstageView;
	
protected:
	virtual System::Types::TSize __fastcall GetBackButtonSize(void);
	virtual System::Types::TRect __fastcall GetContentOffsets(void);
	virtual Dxbar::_di_IdxSkin __fastcall GetSkin(void);
	
public:
	__fastcall TdxRibbonBackstageViewPainter(TdxRibbonCustomBackstageView* ABackstageView);
	virtual void __fastcall DrawBackButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawMenuBarHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__property System::Types::TSize BackButtonSize = {read=GetBackButtonSize};
	__property TdxRibbonCustomBackstageView* BackstageView = {read=FBackstageView};
	__property System::Types::TRect ContentOffsets = {read=GetContentOffsets};
	__property Dxbar::_di_IdxSkin Skin = {read=GetSkin};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewPainter(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuPainter;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuPainter : public Dxbar::TdxBarSkinnedPainter
{
	typedef Dxbar::TdxBarSkinnedPainter inherited;
	
protected:
	virtual void __fastcall DrawToolbarContentPart(Dxbar::TdxBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawToolbarNonContentPart(Dxbar::TdxBarControl* ABarControl, HDC DC);
	virtual void __fastcall GetDisabledTextColors(Dxbar::TdxBarItemControl* ABarItemControl, bool ASelected, bool AFlat, System::Uitypes::TColor &AColor1, System::Uitypes::TColor &AColor2);
	virtual System::Uitypes::TColor __fastcall GetEnabledTextColor(Dxbar::TdxBarItemControl* ABarItemControl, bool ASelected, bool AFlat);
	
public:
	virtual int __fastcall BarBeginGroupSize(void);
	virtual void __fastcall BarDrawBeginGroup(Dxbar::TCustomdxBarControl* ABarControl, HDC DC, System::Types::TRect &ABeginGroupRect, HBRUSH AToolbarBrush, bool AHorz);
	virtual System::Types::TRect __fastcall GetToolbarContentOffsets(Dxbar::TdxBar* ABar, Dxbar::TdxBarDockingStyle ADockingStyle, bool AHasSizeGrip);
	virtual void __fastcall DrawButtonBackground(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams);
	virtual void __fastcall DockControlFillBackground(Dxbar::TdxDockControl* ADockControl, HDC DC, System::Types::TRect &ADestR, System::Types::TRect &ASourceR, System::Types::TRect &AWholeR, HBRUSH ABrush, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawTabButton(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams, System::Types::TRect &R);
	virtual void __fastcall DrawTabButtonBackground(HDC DC, System::Types::TRect &R, int AState);
	virtual System::Types::TRect __fastcall MenuBarButtonContentOffset(void);
	virtual int __fastcall MenuBarDefaultItemHeight(void);
	virtual int __fastcall MenuBarIndentBetweenItems(void);
	virtual System::Types::TRect __fastcall MenuBarItemsRectOffset(void);
	virtual System::Types::TRect __fastcall TabButtonContentOffset(void);
	virtual int __fastcall TabButtonDefaultHeight(void);
	virtual System::Uitypes::TColor __fastcall TabButtonTextColor(int AState);
public:
	/* TdxBarSkinnedPainter.Create */ inline __fastcall virtual TdxRibbonBackstageViewMenuPainter(NativeUInt AData) : Dxbar::TdxBarSkinnedPainter(AData) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuPainter(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuDockControl;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuDockControl : public Dxbar::TdxBarDockControl
{
	typedef Dxbar::TdxBarDockControl inherited;
	
private:
	TdxRibbonBackstageViewMenuViewInfo* FMenuViewInfo;
	TdxRibbonCustomBackstageView* __fastcall GetBackstageView(void);
	Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	
protected:
	virtual void __fastcall CalcLayout(void);
	virtual bool __fastcall CanCustomize(void);
	virtual int __fastcall GetClientSize(void);
	virtual Dxbar::TdxBarControlClass __fastcall GetDockedBarControlClass(void);
	virtual Dxbar::TdxBarDockingStyle __fastcall GetDockingStyle(void);
	virtual int __fastcall GetMinSize(void);
	virtual Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	virtual bool __fastcall GetSunkenBorder(void);
	virtual bool __fastcall IsDrawDesignBorder(void);
	virtual void __fastcall ShowCustomizePopup(void);
	System::TObject* __fastcall GetContainer(void);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	
public:
	__fastcall TdxRibbonBackstageViewMenuDockControl(TdxRibbonBackstageViewMenuViewInfo* AMenuViewInfo);
	__property TdxRibbonCustomBackstageView* BackstageView = {read=GetBackstageView};
	__property TdxRibbonBackstageViewMenuViewInfo* MenuViewInfo = {read=FMenuViewInfo};
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=GetRibbon};
public:
	/* TdxDockControl.CreateEx */ inline __fastcall TdxRibbonBackstageViewMenuDockControl(System::Classes::TComponent* AOwner, Dxbar::TdxBarManager* ABarManager, Dxbar::TdxBarDockingStyle ADockStyle) : Dxbar::TdxBarDockControl(AOwner, ABarManager, ADockStyle) { }
	/* TdxDockControl.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuDockControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewMenuDockControl(HWND ParentWindow) : Dxbar::TdxBarDockControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewTabSheetViewInfo;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewTabSheetViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxRibbonBackstageViewTabSheet* FTab;
	System::Types::TRect __fastcall GetFrameAreaVisibleBounds(void);
	
protected:
	virtual int __fastcall GetMinHeight(void);
	virtual int __fastcall GetMinWidth(void);
	
public:
	__fastcall virtual TdxRibbonBackstageViewTabSheetViewInfo(TdxRibbonBackstageViewTabSheet* ATab);
	virtual void __fastcall Calculate(const System::Types::TRect &R);
	void __fastcall ValidateWindowPos(tagWINDOWPOS &APos);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::Types::TRect FrameAreaVisibleBounds = {read=GetFrameAreaVisibleBounds};
	__property int MinHeight = {read=GetMinHeight, nodefault};
	__property int MinWidth = {read=GetMinWidth, nodefault};
	__property TdxRibbonBackstageViewTabSheet* Tab = {read=FTab};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewTabSheetViewInfo(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewTabSheetSizeOptions;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewTabSheetSizeOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FHasChanges;
	int FMinHeight;
	int FMinWidth;
	TdxRibbonBackstageViewTabSheet* FTab;
	int FUpdateCount;
	bool __fastcall GetAutoSize(void);
	void __fastcall SetAutoSize(bool AValue);
	void __fastcall SetMinHeight(int AValue);
	void __fastcall SetMinWidth(int AValue);
	
protected:
	void __fastcall Changed(void);
	
public:
	__fastcall virtual TdxRibbonBackstageViewTabSheetSizeOptions(TdxRibbonBackstageViewTabSheet* ATab);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	
__published:
	__property bool AutoSize = {read=GetAutoSize, write=SetAutoSize, default=0};
	__property int MinHeight = {read=FMinHeight, write=SetMinHeight, default=0};
	__property int MinWidth = {read=FMinWidth, write=SetMinWidth, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewTabSheetSizeOptions(void) { }
	
};


class PASCALIMPLEMENTATION TdxRibbonBackstageViewTabSheet : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxRibbonCustomBackstageView* FBackstageView;
	System::UnicodeString FKeyTip;
	TdxRibbonBackstageViewTabSheetSizeOptions* FSizeOptions;
	bool FTabVisible;
	TdxRibbonBackstageViewTabSheetViewInfo* FViewInfo;
	bool __fastcall GetActive(void);
	bool __fastcall GetCanBeActive(void);
	int __fastcall GetPageIndex(void);
	TdxRibbonBackstageViewPainter* __fastcall GetPainter(void);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetBackstageView(TdxRibbonCustomBackstageView* AValue);
	void __fastcall SetKeyTip(const System::UnicodeString AValue);
	void __fastcall SetPageIndex(int AValue);
	void __fastcall SetSizeOptions(TdxRibbonBackstageViewTabSheetSizeOptions* AValue);
	void __fastcall SetTabVisible(bool AValue);
	
protected:
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual TdxRibbonBackstageViewTabSheetViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall Activate(void);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall Calculate(const System::Types::TRect &R);
	HIDESBASE virtual void __fastcall Changed(void);
	virtual void __fastcall Deactivate(void);
	void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall NCPaint(HDC DC);
	virtual void __fastcall Paint(void);
	void __fastcall RefreshNonClientArea(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMPrint(Winapi::Messages::TWMPrint &Message);
	__property bool CanBeActive = {read=GetCanBeActive, nodefault};
	__property TdxRibbonBackstageViewPainter* Painter = {read=GetPainter};
	__property TdxRibbonBackstageViewTabSheetViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TdxRibbonBackstageViewTabSheet(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonBackstageViewTabSheet(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TdxRibbonCustomBackstageView* BackstageView = {read=FBackstageView, write=SetBackstageView};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property BorderWidth = {default=0};
	__property Caption = {default=0};
	__property Enabled = {default=1};
	__property Height = {stored=false};
	__property System::UnicodeString KeyTip = {read=FKeyTip, write=SetKeyTip};
	__property int PageIndex = {read=GetPageIndex, write=SetPageIndex, stored=false, nodefault};
	__property TdxRibbonBackstageViewTabSheetSizeOptions* SizeOptions = {read=FSizeOptions, write=SetSizeOptions};
	__property bool TabVisible = {read=FTabVisible, write=SetTabVisible, default=1};
	__property Width = {stored=false};
	__property OnResize;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewTabSheet(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewTabSheets;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewTabSheets : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxRibbonBackstageViewTabSheet* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxRibbonBackstageViewTabSheet* __fastcall GetItem(int Index);
	
public:
	__property TdxRibbonBackstageViewTabSheet* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxRibbonBackstageViewTabSheets(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewTabSheets(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewTabSheetButton;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewTabSheetButton : public Dxbar::TdxBarButton
{
	typedef Dxbar::TdxBarButton inherited;
	
private:
	TdxRibbonBackstageViewTabSheet* FTab;
	void __fastcall SetTab(TdxRibbonBackstageViewTabSheet* AValue);
	
protected:
	virtual Dxbar::TdxBarItemControlClass __fastcall GetControlClass(bool AIsVertical);
	
public:
	__fastcall virtual TdxRibbonBackstageViewTabSheetButton(System::Classes::TComponent* AOwner);
	void __fastcall RefreshInfo(void);
	__property TdxRibbonBackstageViewTabSheet* Tab = {read=FTab, write=SetTab};
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewTabSheetButton(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewTabSheetButtonControl;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewTabSheetButtonControl : public Dxbar::TdxBarButtonControl
{
	typedef Dxbar::TdxBarButtonControl inherited;
	
private:
	HIDESBASE TdxRibbonBackstageViewTabSheetButton* __fastcall GetItem(void);
	TdxRibbonBackstageViewMenuPainter* __fastcall GetMenuPainter(void);
	TdxRibbonBackstageViewMenuViewInfo* __fastcall GetMenuViewInfo(void);
	
protected:
	virtual bool __fastcall CanCustomize(void);
	void __fastcall ActivateTab(void);
	virtual void __fastcall ControlActivate(bool AImmediately, bool AByMouse);
	virtual void __fastcall ControlClick(bool AByMouse, System::WideChar AKey = (System::WideChar)(0x0));
	virtual void __fastcall ControlUnclick(bool AByMouse);
	virtual void __fastcall DoPaint(System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	virtual int __fastcall GetDefaultHeight(void);
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	virtual bool __fastcall CanDestroyOnClick(void);
	System::Types::TPoint __fastcall GetKeyTipBasePoint(void);
	__property TdxRibbonBackstageViewTabSheetButton* Item = {read=GetItem};
	__property TdxRibbonBackstageViewMenuPainter* MenuPainter = {read=GetMenuPainter};
	__property TdxRibbonBackstageViewMenuViewInfo* MenuViewInfo = {read=GetMenuViewInfo};
public:
	/* TdxBarButtonLikeControl.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewTabSheetButtonControl(void) { }
	
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxRibbonBackstageViewTabSheetButtonControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarButtonControl(AItemLink) { }
	
private:
	void *__IdxRibbonBackstageViewKeyTipPositionInfo;	/* IdxRibbonBackstageViewKeyTipPositionInfo */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7947E0B2-BBED-4AE0-9C34-5B578B412780}
	operator _di_IdxRibbonBackstageViewKeyTipPositionInfo()
	{
		_di_IdxRibbonBackstageViewKeyTipPositionInfo intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonBackstageViewKeyTipPositionInfo*(void) { return (IdxRibbonBackstageViewKeyTipPositionInfo*)&__IdxRibbonBackstageViewKeyTipPositionInfo; }
	#endif
	
};


class DELPHICLASS TdxRibbonBackstageViewTabSheetButtonList;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewTabSheetButtonList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxRibbonBackstageViewTabSheetButton* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxRibbonBackstageViewTabSheetButton* __fastcall GetItem(int Index);
	
public:
	TdxRibbonBackstageViewTabSheetButton* __fastcall GetItemByTab(TdxRibbonBackstageViewTabSheet* ATab);
	void __fastcall RefreshInfo(void);
	void __fastcall RemoveTab(TdxRibbonBackstageViewTabSheet* ATab);
	__property TdxRibbonBackstageViewTabSheetButton* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxRibbonBackstageViewTabSheetButtonList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewTabSheetButtonList(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuButtonList;
class DELPHICLASS TdxRibbonBackstageViewMenuBarButton;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuButtonList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxRibbonBackstageViewMenuBarButton* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxRibbonBackstageViewMenuBarButton* __fastcall GetItem(int Index);
	
public:
	void __fastcall RefreshInfo(void);
	__property TdxRibbonBackstageViewMenuBarButton* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxRibbonBackstageViewMenuButtonList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuButtonList(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuButton;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuViewInfo : public TdxRibbonBackstageViewCustomViewInfo
{
	typedef TdxRibbonBackstageViewCustomViewInfo inherited;
	
private:
	TdxRibbonBackstageViewMenuDockControl* FDockControl;
	Dxbar::TdxBarItemLinks* FItemLinks;
	TdxRibbonBackstageViewMenuButtonList* FMenuButtonList;
	int FMinHeight;
	int FMinWidth;
	TdxRibbonBackstageViewMenuPainter* FPainter;
	TdxRibbonBackstageViewTabSheetButtonList* FTabButtonList;
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetAccessibilityHelper(void);
	TdxRibbonBackstageViewMenuBarControl* __fastcall GetBarControl(void);
	bool __fastcall GetIsDesigning(void);
	Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	void __fastcall AddButton(TdxRibbonBackstageViewMenuButton* AButton);
	void __fastcall AddTabButton(TdxRibbonBackstageViewTabSheet* ATab);
	
protected:
	virtual TdxRibbonBackstageViewMenuPainter* __fastcall CreatePainter(NativeUInt AData);
	void __fastcall CreateBarControl(void);
	void __fastcall CreateViewInfoItems(void);
	void __fastcall DestroyViewInfoItems(void);
	bool __fastcall CanContainItem(Dxbar::TdxBarItem* AItem, /* out */ System::UnicodeString &AErrorText);
	Dxbar::TCustomdxBarControl* __fastcall CreateItemLinksBarControl(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	System::Classes::TComponent* __fastcall GetInstance(void);
	Dxbar::TdxBarItemLinks* __fastcall GetItemLinks(void);
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property TdxRibbonBackstageViewMenuButtonList* MenuButtonList = {read=FMenuButtonList};
	__property TdxRibbonBackstageViewMenuPainter* Painter = {read=FPainter};
	__property TdxRibbonBackstageViewTabSheetButtonList* TabButtonList = {read=FTabButtonList};
	
public:
	__fastcall virtual TdxRibbonBackstageViewMenuViewInfo(TdxRibbonCustomBackstageView* ABackstageView);
	__fastcall virtual ~TdxRibbonBackstageViewMenuViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	void __fastcall CalculateSizes(void);
	void __fastcall ClearInternalLists(void);
	void __fastcall InitiateActions(void);
	void __fastcall RecreateItemLinks(void);
	void __fastcall RefreshMenuButtonsInfo(void);
	void __fastcall RefreshTabsInfo(void);
	void __fastcall UpdateFont(void);
	__property Dxbar::_di_IdxBarAccessibilityHelper AccessibilityHelper = {read=GetAccessibilityHelper};
	__property TdxRibbonBackstageViewMenuBarControl* BarControl = {read=GetBarControl};
	__property TdxRibbonBackstageViewMenuDockControl* DockControl = {read=FDockControl};
	__property Dxbar::TdxBarItemLinks* ItemLinks = {read=FItemLinks};
	__property int MinHeight = {read=FMinHeight, nodefault};
	__property int MinWidth = {read=FMinWidth, nodefault};
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=GetRibbon};
private:
	void *__IdxBarLinksOwner;	/* Dxbar::IdxBarLinksOwner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1CB4E538-769E-45F4-9BE3-20814F440106}
	operator Dxbar::_di_IdxBarLinksOwner()
	{
		Dxbar::_di_IdxBarLinksOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarLinksOwner*(void) { return (Dxbar::IdxBarLinksOwner*)&__IdxBarLinksOwner; }
	#endif
	
};


class DELPHICLASS TdxRibbonBackstageViewDesignSelector;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewDesignSelector : public Cxcontrols::TcxDesignSelector
{
	typedef Cxcontrols::TcxDesignSelector inherited;
	
protected:
	virtual bool __fastcall GetSelected(void);
public:
	/* TcxDesignSelector.Create */ inline __fastcall virtual TdxRibbonBackstageViewDesignSelector(System::Classes::TComponent* AOwner) : Cxcontrols::TcxDesignSelector(AOwner) { }
	
public:
	/* TcxControl.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewDesignSelector(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewDesignSelector(HWND ParentWindow) : Cxcontrols::TcxDesignSelector(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewViewInfo;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewViewInfo : public TdxRibbonBackstageViewCustomViewInfo
{
	typedef TdxRibbonBackstageViewCustomViewInfo inherited;
	
private:
	int FContentHeight;
	int FContentWidth;
	System::Types::TRect FFrameAreaBounds;
	TdxRibbonBackstageViewMenuViewInfo* FMenuViewInfo;
	int FScrollPositionX;
	int FScrollPositionY;
	TdxRibbonBackstageViewTabSheet* __fastcall GetActiveTab(void);
	Dxbar::TdxBarItemControl* __fastcall GetActiveTabItemControl(void);
	System::Types::TRect __fastcall GetContentBounds(void);
	System::Types::TRect __fastcall GetDesignSelectorRect(void);
	System::Types::TRect __fastcall GetFrameAreaVisibleBounds(void);
	Dxbar::TdxBarControl* __fastcall GetMenuBarControl(void);
	void __fastcall CheckScrollPosition(int &AValue, int AContentSize, int ADisplaySize);
	void __fastcall SetScrollPositionX(int AValue);
	void __fastcall SetScrollPositionY(int AValue);
	
protected:
	virtual System::Types::TRect __fastcall CalculateFrameBounds(void);
	virtual System::Types::TRect __fastcall CalculateMenuBounds(void);
	virtual int __fastcall CalculateMinHeight(void);
	virtual int __fastcall CalculateMinWidth(void);
	virtual TdxRibbonBackstageViewMenuViewInfo* __fastcall CreateMenuViewInfo(void);
	
public:
	__fastcall virtual TdxRibbonBackstageViewViewInfo(TdxRibbonCustomBackstageView* ABackstageView);
	__fastcall virtual ~TdxRibbonBackstageViewViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall DeactivateControls(void);
	bool __fastcall ProcessMouseWheel(bool ALineDown);
	__property TdxRibbonBackstageViewTabSheet* ActiveTab = {read=GetActiveTab};
	__property Dxbar::TdxBarItemControl* ActiveTabItemControl = {read=GetActiveTabItemControl};
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
	__property int ContentHeight = {read=FContentHeight, nodefault};
	__property int ContentWidth = {read=FContentWidth, nodefault};
	__property System::Types::TRect DesignSelectorRect = {read=GetDesignSelectorRect};
	__property System::Types::TRect FrameAreaBounds = {read=FFrameAreaBounds};
	__property System::Types::TRect FrameAreaVisibleBounds = {read=GetFrameAreaVisibleBounds};
	__property Dxbar::TdxBarControl* MenuBarControl = {read=GetMenuBarControl};
	__property TdxRibbonBackstageViewMenuViewInfo* MenuViewInfo = {read=FMenuViewInfo};
	__property int ScrollPositionX = {read=FScrollPositionX, write=SetScrollPositionX, nodefault};
	__property int ScrollPositionY = {read=FScrollPositionY, write=SetScrollPositionY, nodefault};
};


class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuBarButton : public Dxbar::TdxBarButton
{
	typedef Dxbar::TdxBarButton inherited;
	
private:
	TdxRibbonBackstageViewMenuButton* FMenuButton;
	void __fastcall SetMenuButton(TdxRibbonBackstageViewMenuButton* AValue);
	
protected:
	virtual Dxbar::TdxBarItemControlClass __fastcall GetControlClass(bool AIsVertical);
	
public:
	DYNAMIC void __fastcall DirectClick(void);
	void __fastcall RefreshInfo(void);
	__property TdxRibbonBackstageViewMenuButton* MenuButton = {read=FMenuButton, write=SetMenuButton};
public:
	/* TdxBarButton.Create */ inline __fastcall virtual TdxRibbonBackstageViewMenuBarButton(System::Classes::TComponent* AOwner) : Dxbar::TdxBarButton(AOwner) { }
	
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuBarButton(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuBarButtonControl;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuBarButtonControl : public Dxbar::TdxBarButtonControl
{
	typedef Dxbar::TdxBarButtonControl inherited;
	
private:
	TdxRibbonCustomBackstageView* __fastcall GetBackstageView(void);
	HIDESBASE TdxRibbonBackstageViewMenuBarButton* __fastcall GetItem(void);
	TdxRibbonBackstageViewMenuPainter* __fastcall GetMenuPainter(void);
	
protected:
	virtual bool __fastcall CanCustomize(void);
	virtual int __fastcall GetDefaultHeight(void);
	virtual Dxbar::TdxBarItemControlViewStructure __fastcall GetViewStructure(void);
	bool __fastcall HasImage(void);
	bool __fastcall IsTabButtonStyle(void);
	virtual void __fastcall CalcDrawParams(bool AFull = true);
	virtual void __fastcall DoPaint(System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	System::Types::TPoint __fastcall GetKeyTipBasePoint(void);
	
public:
	__property TdxRibbonCustomBackstageView* BackstageView = {read=GetBackstageView};
	__property TdxRibbonBackstageViewMenuBarButton* Item = {read=GetItem};
	__property TdxRibbonBackstageViewMenuPainter* MenuPainter = {read=GetMenuPainter};
public:
	/* TdxBarButtonLikeControl.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuBarButtonControl(void) { }
	
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxRibbonBackstageViewMenuBarButtonControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarButtonControl(AItemLink) { }
	
private:
	void *__IdxRibbonBackstageViewKeyTipPositionInfo;	/* IdxRibbonBackstageViewKeyTipPositionInfo */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7947E0B2-BBED-4AE0-9C34-5B578B412780}
	operator _di_IdxRibbonBackstageViewKeyTipPositionInfo()
	{
		_di_IdxRibbonBackstageViewKeyTipPositionInfo intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonBackstageViewKeyTipPositionInfo*(void) { return (IdxRibbonBackstageViewKeyTipPositionInfo*)&__IdxRibbonBackstageViewKeyTipPositionInfo; }
	#endif
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuButtons;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuButton : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
private:
	bool FBeginGroup;
	Dxbar::TdxBarButton* FItem;
	TdxRibbonBackstageViewMenuButtonPosition FPosition;
	TdxRibbonBackstageViewMenuButtons* __fastcall GetCollection(void);
	void __fastcall SetItem(Dxbar::TdxBarButton* AValue);
	void __fastcall SetPosition(TdxRibbonBackstageViewMenuButtonPosition AValue);
	void __fastcall SetBeginGroup(bool AValue);
	
protected:
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall SelectionChanged(void);
	void __fastcall BarComponentChanged(Dxbar::TdxBarComponent* AComponent);
	
public:
	__fastcall virtual ~TdxRibbonBackstageViewMenuButton(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxRibbonBackstageViewMenuButtons* Collection = {read=GetCollection};
	
__published:
	__property bool BeginGroup = {read=FBeginGroup, write=SetBeginGroup, default=0};
	__property Dxbar::TdxBarButton* Item = {read=FItem, write=SetItem};
	__property TdxRibbonBackstageViewMenuButtonPosition Position = {read=FPosition, write=SetPosition, default=0};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TdxRibbonBackstageViewMenuButton(System::Classes::TCollection* Collection) : Cxclasses::TcxInterfacedCollectionItem(Collection) { }
	
private:
	void *__IdxBarComponentListener;	/* Dxbar::IdxBarComponentListener */
	void *__IdxRibbonBackstageViewSelectableItem;	/* IdxRibbonBackstageViewSelectableItem */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5E594B1F-C8BD-479B-8A22-E2E04545D354}
	operator Dxbar::_di_IdxBarComponentListener()
	{
		Dxbar::_di_IdxBarComponentListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarComponentListener*(void) { return (Dxbar::IdxBarComponentListener*)&__IdxBarComponentListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D5E058AB-1C90-4D21-BE0A-EB48530EF53B}
	operator _di_IdxRibbonBackstageViewSelectableItem()
	{
		_di_IdxRibbonBackstageViewSelectableItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonBackstageViewSelectableItem*(void) { return (IdxRibbonBackstageViewSelectableItem*)&__IdxRibbonBackstageViewSelectableItem; }
	#endif
	
};


class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuButtons : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxRibbonBackstageViewMenuButton* operator[](int Index) { return Items[Index]; }
	
private:
	TdxRibbonCustomBackstageView* FBackstageView;
	HIDESBASE TdxRibbonBackstageViewMenuButton* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxRibbonBackstageViewMenuButton* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property TdxRibbonCustomBackstageView* BackstageView = {read=FBackstageView};
	
public:
	__fastcall TdxRibbonBackstageViewMenuButtons(TdxRibbonCustomBackstageView* ABackstageView);
	HIDESBASE TdxRibbonBackstageViewMenuButton* __fastcall Add(void);
	int __fastcall IndexOf(TdxRibbonBackstageViewMenuButton* AItem);
	HIDESBASE TdxRibbonBackstageViewMenuButton* __fastcall Insert(int AIndex);
	__property TdxRibbonBackstageViewMenuButton* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuButtons(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewMenuHelper;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewMenuHelper : public Cxcontrols::TcxMessageWindow
{
	typedef Cxcontrols::TcxMessageWindow inherited;
	
private:
	TdxRibbonCustomBackstageView* FBackstageView;
	
protected:
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall TdxRibbonBackstageViewMenuHelper(TdxRibbonCustomBackstageView* ABackstageView);
	void __fastcall PostClick(TdxRibbonBackstageViewMenuButton* AButton);
	void __fastcall PostShowRibbonKeyTips(void);
	__property TdxRibbonCustomBackstageView* BackstageView = {read=FBackstageView};
public:
	/* TcxMessageWindow.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewMenuHelper(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewApplicationMenuHelper;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewApplicationMenuHelper : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	Cxclasses::TcxObjectLink* FLinkToBackstageView;
	TdxRibbonCustomBackstageView* __fastcall GetBackstageView(void);
	
protected:
	bool __fastcall CanShowPopup(Dxribbon::TdxCustomRibbon* ARibbon);
	bool __fastcall ClosePopup(void);
	virtual Dxribbon::TdxRibbonApplicationMenuDisplayMode __fastcall GetDisplayMode(void);
	virtual System::Types::TPoint __fastcall GetOrigin(bool AIsClientArea);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetRootAccessibilityHelper(void);
	virtual bool __fastcall Popup(Dxribbon::TdxCustomRibbon* ARibbon, bool &AClosedByEscape);
	virtual void __fastcall GetTabOrderList(System::Classes::TList* AList);
	virtual void __fastcall RibbonFormResized(void);
	virtual void __fastcall SelectAppMenuFirstItemControl(void);
	virtual void __fastcall ShowKeyTips(void);
	virtual void __fastcall UpdateNonClientArea(void);
	
public:
	__fastcall virtual TdxRibbonBackstageViewApplicationMenuHelper(TdxRibbonCustomBackstageView* ABackstageView);
	__fastcall virtual ~TdxRibbonBackstageViewApplicationMenuHelper(void);
	__property TdxRibbonCustomBackstageView* BackstageView = {read=GetBackstageView};
private:
	void *__IdxRibbonApplicationMenu;	/* Dxribbon::IdxRibbonApplicationMenu */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {DF34053B-F30D-4FC6-94D5-5863620E8F28}
	operator Dxribbon::_di_IdxRibbonApplicationMenu()
	{
		Dxribbon::_di_IdxRibbonApplicationMenu intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbon::IdxRibbonApplicationMenu*(void) { return (Dxribbon::IdxRibbonApplicationMenu*)&__IdxRibbonApplicationMenu; }
	#endif
	
};


class DELPHICLASS TdxRibbonBackstageViewCustomButtonViewInfo;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewCustomButtonViewInfo : public TdxRibbonBackstageViewCustomViewInfo
{
	typedef TdxRibbonBackstageViewCustomViewInfo inherited;
	
private:
	Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	
public:
	virtual void __fastcall Click(void) = 0 ;
	__property Cxlookandfeelpainters::TcxButtonState State = {read=GetState, nodefault};
public:
	/* TdxRibbonBackstageViewCustomObject.Create */ inline __fastcall virtual TdxRibbonBackstageViewCustomButtonViewInfo(TdxRibbonCustomBackstageView* ABackstageView) : TdxRibbonBackstageViewCustomViewInfo(ABackstageView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewCustomButtonViewInfo(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewBackButtonViewInfo;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewBackButtonViewInfo : public TdxRibbonBackstageViewCustomButtonViewInfo
{
	typedef TdxRibbonBackstageViewCustomButtonViewInfo inherited;
	
protected:
	virtual System::Types::TSize __fastcall GetMeasureSize(void);
	
public:
	virtual void __fastcall Click(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TSize MeasureSize = {read=GetMeasureSize};
public:
	/* TdxRibbonBackstageViewCustomObject.Create */ inline __fastcall virtual TdxRibbonBackstageViewBackButtonViewInfo(TdxRibbonCustomBackstageView* ABackstageView) : TdxRibbonBackstageViewCustomButtonViewInfo(ABackstageView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewBackButtonViewInfo(void) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewNonClientViewInfo;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewNonClientViewInfo : public TdxRibbonBackstageViewCustomViewInfo
{
	typedef TdxRibbonBackstageViewCustomViewInfo inherited;
	
private:
	TdxRibbonBackstageViewBackButtonViewInfo* FBackButtonViewInfo;
	System::Types::TRect __fastcall GetClientRect(void);
	System::Types::TRect __fastcall GetContentRect(void);
	Dxribbon::TdxRibbonApplicationMenuDisplayMode __fastcall GetDisplayMode(void);
	bool __fastcall GetHasNonClientArea(void);
	TdxRibbonBackstageViewMenuViewInfo* __fastcall GetMenuViewInfo(void);
	TdxRibbonBackstageViewPainter* __fastcall GetPainter(void);
	Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* __fastcall GetRibbonFormCaptionHelper(void);
	
protected:
	System::Types::TRect FBorderIconsArea;
	System::Types::TRect FCaptionArea;
	System::Types::TRect FCaptionTextRect;
	System::Types::TRect FMenuBarHeaderRect;
	System::Types::TRect FTabsArea;
	virtual void __fastcall CalculateBackButton(void);
	virtual void __fastcall CalculateCaptionArea(void);
	virtual void __fastcall CalculateMenuBarHeader(void);
	virtual TdxRibbonBackstageViewBackButtonViewInfo* __fastcall CreateBackButtonViewInfo(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawCaptionArea(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawMenuBarHeader(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetClientOffsets(void);
	
public:
	__fastcall virtual TdxRibbonBackstageViewNonClientViewInfo(TdxRibbonCustomBackstageView* ABackstageView);
	__fastcall virtual ~TdxRibbonBackstageViewNonClientViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual HRGN __fastcall CreateWindowRegion(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Recalculate(void);
	__property TdxRibbonBackstageViewBackButtonViewInfo* BackButtonViewInfo = {read=FBackButtonViewInfo};
	__property System::Types::TRect BorderIconsArea = {read=FBorderIconsArea};
	__property System::Types::TRect CaptionArea = {read=FCaptionArea};
	__property System::Types::TRect CaptionTextRect = {read=FCaptionTextRect};
	__property System::Types::TRect ClientOffsets = {read=GetClientOffsets};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property System::Types::TRect ContentRect = {read=GetContentRect};
	__property Dxribbon::TdxRibbonApplicationMenuDisplayMode DisplayMode = {read=GetDisplayMode, nodefault};
	__property bool HasNonClientArea = {read=GetHasNonClientArea, nodefault};
	__property System::Types::TRect MenuBarHeaderRect = {read=FMenuBarHeaderRect};
	__property TdxRibbonBackstageViewMenuViewInfo* MenuViewInfo = {read=GetMenuViewInfo};
	__property TdxRibbonBackstageViewPainter* Painter = {read=GetPainter};
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* RibbonFormCaptionHelper = {read=GetRibbonFormCaptionHelper};
	__property System::Types::TRect TabsArea = {read=FTabsArea};
};


class DELPHICLASS TdxRibbonBackstageViewNonClientController;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewNonClientController : public TdxRibbonBackstageViewCustomObject
{
	typedef TdxRibbonBackstageViewCustomObject inherited;
	
private:
	TdxRibbonBackstageViewCustomButtonViewInfo* FHoveredCell;
	TdxRibbonBackstageViewCustomButtonViewInfo* FPressedCell;
	TdxRibbonBackstageViewNonClientViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetHoveredCell(TdxRibbonBackstageViewCustomButtonViewInfo* AValue);
	void __fastcall SetPressedCell(TdxRibbonBackstageViewCustomButtonViewInfo* AValue);
	
protected:
	System::Types::TPoint __fastcall ScreenToLocal(const System::Types::TPoint P)/* overload */;
	System::Types::TPoint __fastcall ScreenToLocal(const System::Types::TSmallPoint P)/* overload */;
	bool __fastcall PtInCaller(const System::Types::TPoint P);
	
public:
	__fastcall virtual ~TdxRibbonBackstageViewNonClientController(void);
	virtual TdxRibbonBackstageViewCustomButtonViewInfo* __fastcall HitTest(const System::Types::TPoint P);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton AButton, const System::Types::TPoint P);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(const System::Types::TPoint P);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton AButton, const System::Types::TPoint P);
	virtual void __fastcall ProcessMessage(Winapi::Messages::TMessage &AMessage);
	void __fastcall RefreshState(void);
	__property TdxRibbonBackstageViewCustomButtonViewInfo* HoveredCell = {read=FHoveredCell, write=SetHoveredCell};
	__property TdxRibbonBackstageViewCustomButtonViewInfo* PressedCell = {read=FPressedCell, write=SetPressedCell};
	__property TdxRibbonBackstageViewNonClientViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxRibbonBackstageViewCustomObject.Create */ inline __fastcall virtual TdxRibbonBackstageViewNonClientController(TdxRibbonCustomBackstageView* ABackstageView) : TdxRibbonBackstageViewCustomObject(ABackstageView) { }
	
private:
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	
};


enum TdxRibbonBackstageViewAnimationTransitionMode : unsigned char { bvatmShow, bvatmHide };

class DELPHICLASS TdxRibbonBackstageViewAnimationTransition;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewAnimationTransition : public Dxanimation::TdxAnimationTransition
{
	typedef Dxanimation::TdxAnimationTransition inherited;
	
private:
	Cxgraphics::TcxBitmap* FActiveTabBuffer;
	bool FActiveTabIsSolidBackground;
	System::Types::TRect FActiveTabRect;
	TdxRibbonCustomBackstageView* FBackstageView;
	Cxgraphics::TcxBitmap* FBackstageViewBuffer;
	Cxgraphics::TcxBitmap* FBackstageViewMenuBuffer;
	System::Types::TRect FBackstageViewRect;
	TdxRibbonBackstageViewAnimationTransitionMode FMode;
	TdxRibbonBackstageViewTabSheet* __fastcall GetActiveTab(void);
	TdxRibbonBackstageViewMenuViewInfo* __fastcall GetMenuViewInfo(void);
	TdxRibbonBackstageViewNonClientViewInfo* __fastcall GetNonClientViewInfo(void);
	TdxRibbonBackstageViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual System::Byte __fastcall CalculateContentAlpha(void);
	virtual void __fastcall CalculateViewInfos(void);
	virtual void __fastcall DoAnimate(void);
	virtual void __fastcall Finalize(void);
	virtual void __fastcall Initalize(void);
	void __fastcall PrepareBackstageViewBuffer(Cxgraphics::TcxCanvas* ACanvas);
	__property TdxRibbonBackstageViewTabSheet* ActiveTab = {read=GetActiveTab};
	__property Cxgraphics::TcxBitmap* ActiveTabBuffer = {read=FActiveTabBuffer};
	__property bool ActiveTabIsSolidBackground = {read=FActiveTabIsSolidBackground, nodefault};
	__property System::Types::TRect ActiveTabRect = {read=FActiveTabRect};
	__property Cxgraphics::TcxBitmap* BackstageViewBuffer = {read=FBackstageViewBuffer};
	__property Cxgraphics::TcxBitmap* BackstageViewMenuBuffer = {read=FBackstageViewMenuBuffer};
	__property System::Types::TRect BackstageViewRect = {read=FBackstageViewRect};
	__property TdxRibbonBackstageViewMenuViewInfo* MenuViewInfo = {read=GetMenuViewInfo};
	__property TdxRibbonBackstageViewNonClientViewInfo* NonClientViewInfo = {read=GetNonClientViewInfo};
	__property TdxRibbonBackstageViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxRibbonBackstageViewAnimationTransition(TdxRibbonCustomBackstageView* ABackstageView, TdxRibbonBackstageViewAnimationTransitionMode AMode);
	__fastcall virtual ~TdxRibbonBackstageViewAnimationTransition(void);
	__property TdxRibbonCustomBackstageView* BackstageView = {read=FBackstageView};
	__property TdxRibbonBackstageViewAnimationTransitionMode Mode = {read=FMode, nodefault};
};


class DELPHICLASS TdxRibbonBackstageViewSizeGrip;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewSizeGrip : public Dxribbon::TdxRibbonSizeGrip
{
	typedef Dxribbon::TdxRibbonSizeGrip inherited;
	
protected:
	virtual Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
public:
	/* TcxSizeGrip.Create */ inline __fastcall virtual TdxRibbonBackstageViewSizeGrip(System::Classes::TComponent* AOwner) : Dxribbon::TdxRibbonSizeGrip(AOwner) { }
	/* TcxSizeGrip.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewSizeGrip(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewSizeGrip(HWND ParentWindow) : Dxribbon::TdxRibbonSizeGrip(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonBackstageViewScrollBar;
class PASCALIMPLEMENTATION TdxRibbonBackstageViewScrollBar : public Dxribbon::TdxRibbonScrollBar
{
	typedef Dxribbon::TdxRibbonScrollBar inherited;
	
protected:
	virtual Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
public:
	/* TcxControlScrollBar.Create */ inline __fastcall virtual TdxRibbonBackstageViewScrollBar(System::Classes::TComponent* AOwner) : Dxribbon::TdxRibbonScrollBar(AOwner) { }
	/* TcxControlScrollBar.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageViewScrollBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageViewScrollBar(HWND ParentWindow) : Dxribbon::TdxRibbonScrollBar(ParentWindow) { }
	
};


typedef void __fastcall (__closure *TdxRibbonBackstageViewTabChanging)(System::TObject* Sender, TdxRibbonBackstageViewTabSheet* ANewTab, bool &AAllowChange);

class PASCALIMPLEMENTATION TdxRibbonCustomBackstageView : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxRibbonBackstageViewTabSheet* FActiveTab;
	bool FApplicationWndProcHooked;
	Cxclasses::TcxComponentHolder* FBarManagerHolder;
	TdxRibbonBackstageViewMenuButtons* FButtons;
	TdxRibbonBackstageViewChanges FChanges;
	TdxRibbonBackstageViewDesignSelector* FDesignSelector;
	TdxRibbonBackstageViewMenuHelper* FMenuHelper;
	TdxRibbonBackstageViewNonClientController* FNonClientController;
	TdxRibbonBackstageViewNonClientViewInfo* FNonClientViewInfo;
	TdxRibbonBackstageViewPainter* FPainter;
	Dxribbon::TdxCustomRibbon* FRibbon;
	TdxRibbonBackstageViewTabSheets* FTabs;
	int FUpdateCount;
	TdxRibbonBackstageViewViewInfo* FViewInfo;
	System::Classes::TNotifyEvent FOnCloseUp;
	System::Classes::TNotifyEvent FOnPopup;
	System::Classes::TNotifyEvent FOnTabChanged;
	TdxRibbonBackstageViewTabChanging FOnTabChanging;
	void __fastcall CheckAssignRibbon(void);
	bool __fastcall CanActivateTab(TdxRibbonBackstageViewTabSheet* ATab);
	Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	bool __fastcall GetIsBarManagerValid(void);
	TdxRibbonBackstageViewMenuViewInfo* __fastcall GetMenuViewInfo(void);
	int __fastcall GetTabCount(void);
	TdxRibbonBackstageViewTabSheet* __fastcall GetTabs(int Index);
	void __fastcall RibbonAfterChange(void);
	void __fastcall RibbonBeforeChange(void);
	void __fastcall SetActiveTab(TdxRibbonBackstageViewTabSheet* AValue);
	void __fastcall SetButtons(TdxRibbonBackstageViewMenuButtons* AValue);
	void __fastcall SetRibbon(Dxribbon::TdxCustomRibbon* AValue);
	
protected:
	Cxclasses::_di_IcxDesignHelper FDesignHelper;
	virtual bool __fastcall CanShowPopup(Dxribbon::TdxCustomRibbon* ARibbon);
	void __fastcall ColorSchemeChangeHandler(System::TObject* Sender, const void *AEventArgs);
	virtual TdxRibbonBackstageViewApplicationMenuHelper* __fastcall CreateApplicationMenuHelper(void);
	virtual TdxRibbonBackstageViewDesignSelector* __fastcall CreateDesignSelector(void);
	virtual TdxRibbonBackstageViewNonClientController* __fastcall CreateNonClientController(void);
	virtual TdxRibbonBackstageViewNonClientViewInfo* __fastcall CreateNonClientViewInfo(void);
	virtual TdxRibbonBackstageViewPainter* __fastcall CreatePainter(void);
	virtual TdxRibbonBackstageViewViewInfo* __fastcall CreateViewInfo(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculatePlace(void);
	HIDESBASE virtual void __fastcall Changed(const TdxRibbonBackstageViewChanges AChanges = TdxRibbonBackstageViewChanges() );
	virtual void __fastcall ClosePopup(void);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall FocusChanged(void);
	void __fastcall FullInvalidate(void);
	virtual bool __fastcall Popup(Dxribbon::TdxCustomRibbon* ARibbon, bool &AClosedByEscape);
	virtual void __fastcall PrepareForPopup(Vcl::Forms::TCustomForm* AForm);
	virtual void __fastcall ShowControl(Vcl::Controls::TControl* AControl);
	virtual void __fastcall UpdateWindowRegion(void);
	virtual bool __fastcall ApplicationWndProcHook(Winapi::Messages::TMessage &Message);
	void __fastcall HookApplicationWndProc(void);
	void __fastcall UnhookApplicationWndProc(void);
	void __fastcall DoAddTab(TdxRibbonBackstageViewTabSheet* ATab);
	void __fastcall DoAfterBarManagerChange(System::TObject* Sender);
	void __fastcall DoBeforeBarManagerChange(System::TObject* Sender);
	void __fastcall DoRemoveTab(TdxRibbonBackstageViewTabSheet* ATab);
	void __fastcall DoTabVisibleChanged(TdxRibbonBackstageViewTabSheet* ATab);
	TdxRibbonBackstageViewTabSheet* __fastcall GetNextTab(int AIndex)/* overload */;
	TdxRibbonBackstageViewTabSheet* __fastcall GetNextTab(TdxRibbonBackstageViewTabSheet* ATab)/* overload */;
	void __fastcall ValidateActiveTab(void);
	void __fastcall DoCloseUp(void);
	DYNAMIC bool __fastcall DoMouseWheelDown(System::Classes::TShiftState Shift, System::Types::TPoint MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(System::Classes::TShiftState Shift, System::Types::TPoint MousePos);
	void __fastcall DoPopup(void);
	void __fastcall DoTabChanged(void);
	bool __fastcall DoTabChanging(TdxRibbonBackstageViewTabSheet* ANewTab);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual Cxcontrols::TcxControlScrollBarClass __fastcall GetScrollBarClass(Vcl::Forms::TScrollBarKind AKind);
	virtual Cxcontrols::TcxSizeGripClass __fastcall GetSizeGripClass(void);
	virtual bool __fastcall NeedsToBringInternalControlsToFront(void);
	virtual void __fastcall NCPaint(HDC DC);
	void __fastcall MakeFullyVisible(System::Types::TRect &R);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	void __fastcall PopupMessageLoop(Vcl::Forms::TCustomForm* AParentForm);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall SystemFontChanged(System::TObject* Sender, const void *AEventArgs);
	bool __fastcall IsPersistentSelected(System::Classes::TPersistent* AObject);
	void __fastcall SelectPersistent(System::Classes::TPersistent* AObject);
	void __fastcall AfterBarManagerChange(void);
	void __fastcall BeforeBarManagerChange(void);
	bool __fastcall CanProcessMouseWheel(void);
	void __fastcall SelectionChanged(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMPrint(Winapi::Messages::TWMPrint &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property Dxbar::TdxBarManager* BarManager = {read=GetBarManager};
	__property Cxclasses::TcxComponentHolder* BarManagerHolder = {read=FBarManagerHolder};
	__property TdxRibbonBackstageViewDesignSelector* DesignSelector = {read=FDesignSelector};
	__property bool IsBarManagerValid = {read=GetIsBarManagerValid, nodefault};
	__property bool IsInPopupLoop = {read=FApplicationWndProcHooked, nodefault};
	__property TdxRibbonBackstageViewMenuHelper* MenuHelper = {read=FMenuHelper};
	__property TdxRibbonBackstageViewMenuViewInfo* MenuViewInfo = {read=GetMenuViewInfo};
	__property TdxRibbonBackstageViewNonClientController* NonClientController = {read=FNonClientController};
	__property TdxRibbonBackstageViewNonClientViewInfo* NonClientViewInfo = {read=FNonClientViewInfo};
	__property TdxRibbonBackstageViewPainter* Painter = {read=FPainter};
	__property TdxRibbonBackstageViewViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TdxRibbonCustomBackstageView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonCustomBackstageView(void);
	TdxRibbonBackstageViewTabSheet* __fastcall AddTab(void);
	void __fastcall DeleteAllTabs(void);
	void __fastcall DeleteTab(int AIndex);
	void __fastcall FullRefresh(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	__property TdxRibbonBackstageViewTabSheet* ActiveTab = {read=FActiveTab, write=SetActiveTab};
	__property TdxRibbonBackstageViewMenuButtons* Buttons = {read=FButtons, write=SetButtons};
	__property System::Classes::TNotifyEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	__property System::Classes::TNotifyEvent OnPopup = {read=FOnPopup, write=FOnPopup};
	__property System::Classes::TNotifyEvent OnTabChanged = {read=FOnTabChanged, write=FOnTabChanged};
	__property TdxRibbonBackstageViewTabChanging OnTabChanging = {read=FOnTabChanging, write=FOnTabChanging};
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=FRibbon, write=SetRibbon};
	__property int TabCount = {read=GetTabCount, nodefault};
	__property TdxRibbonBackstageViewTabSheet* Tabs[int Index] = {read=GetTabs};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonCustomBackstageView(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxRibbonMouseWheelReceiver;	/* Dxribbon::IdxRibbonMouseWheelReceiver */
	void *__IdxRibbonBackstageViewSelectableItem;	/* IdxRibbonBackstageViewSelectableItem */
	void *__IdxRibbonListener;	/* Dxribbon::IdxRibbonListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A5D2167B-0343-4525-915F-D41B49832045}
	operator Dxribbon::_di_IdxRibbonMouseWheelReceiver()
	{
		Dxribbon::_di_IdxRibbonMouseWheelReceiver intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbon::IdxRibbonMouseWheelReceiver*(void) { return (Dxribbon::IdxRibbonMouseWheelReceiver*)&__IdxRibbonMouseWheelReceiver; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D5E058AB-1C90-4D21-BE0A-EB48530EF53B}
	operator _di_IdxRibbonBackstageViewSelectableItem()
	{
		_di_IdxRibbonBackstageViewSelectableItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonBackstageViewSelectableItem*(void) { return (IdxRibbonBackstageViewSelectableItem*)&__IdxRibbonBackstageViewSelectableItem; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E3CD1F8D-4F7F-4448-A877-28726BDDD97F}
	operator Dxribbon::_di_IdxRibbonListener()
	{
		Dxribbon::_di_IdxRibbonListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbon::IdxRibbonListener*(void) { return (Dxribbon::IdxRibbonListener*)&__IdxRibbonListener; }
	#endif
	
};


class DELPHICLASS TdxRibbonBackstageView;
class PASCALIMPLEMENTATION TdxRibbonBackstageView : public TdxRibbonCustomBackstageView
{
	typedef TdxRibbonCustomBackstageView inherited;
	
__published:
	__property Buttons;
	__property OnCloseUp;
	__property OnPopup;
	__property OnTabChanged;
	__property OnTabChanging;
	__property Ribbon;
public:
	/* TdxRibbonCustomBackstageView.Create */ inline __fastcall virtual TdxRibbonBackstageView(System::Classes::TComponent* AOwner) : TdxRibbonCustomBackstageView(AOwner) { }
	/* TdxRibbonCustomBackstageView.Destroy */ inline __fastcall virtual ~TdxRibbonBackstageView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonBackstageView(HWND ParentWindow) : TdxRibbonCustomBackstageView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int dxRibbonBackstageViewMinMenuWidth;
extern PACKAGE int dxRibbonBackstageViewMinOwnerHeight;
extern PACKAGE int dxRibbonBackstageViewMinOwnerWidth;
extern PACKAGE int dxRibbonBackstageViewMenuScrollAnimationTime;
extern PACKAGE Cxclasses::TcxNotifyProcedure FOnRegisterBackstageView;
extern PACKAGE Cxclasses::TcxNotifyProcedure FOnUnregisterBackstageView;
}	/* namespace Dxribbonbackstageview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONBACKSTAGEVIEW)
using namespace Dxribbonbackstageview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonbackstageviewHPP
