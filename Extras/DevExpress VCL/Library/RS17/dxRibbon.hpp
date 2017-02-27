// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbon.pas' rev: 24.00 (Win32)

#ifndef DxribbonHPP
#define DxribbonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
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
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxScreenTip.hpp>	// Pascal unit
#include <dxBarSkin.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <dxBarAccessibility.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxRibbonForm.hpp>	// Pascal unit
#include <dxRibbonFormCaptionHelper.hpp>	// Pascal unit
#include <dxBarApplicationMenu.hpp>	// Pascal unit
#include <dxShadowWindow.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbon
{
//-- type declarations -------------------------------------------------------
enum TdxRibbonMergeOption : unsigned char { rmoCanCreateNewTab, rmoCanCreateNewGroup, rmoCanCreateQATToolbar };

typedef System::Set<TdxRibbonMergeOption, TdxRibbonMergeOption::rmoCanCreateNewTab, TdxRibbonMergeOption::rmoCanCreateQATToolbar>  TdxRibbonMergeOptions;

enum TdxRibbonPopupMenuItem : unsigned char { rpmiItems, rpmiMoreCommands, rpmiQATPosition, rpmiQATAddRemoveItem, rpmiMinimizeRibbon };

typedef System::Set<TdxRibbonPopupMenuItem, TdxRibbonPopupMenuItem::rpmiItems, TdxRibbonPopupMenuItem::rpmiMinimizeRibbon>  TdxRibbonPopupMenuItems;

typedef System::TMetaClass* TdxRibbonGroupsDockControlViewInfoClass;

typedef System::TMetaClass* TdxRibbonTabPainterClass;

enum TdxRibbonApplicationMenuDisplayMode : unsigned char { amdmPopup, amdmFrame, amdmFrameFullScreen };

enum TdxRibbonMergeKind : unsigned char { rmkMerge, rmkAdd, rmkNone };

enum TdxRibbonScrollButton : unsigned char { rsbLeft, rsbRight };

typedef System::Set<TdxRibbonScrollButton, TdxRibbonScrollButton::rsbLeft, TdxRibbonScrollButton::rsbRight>  TdxRibbonScrollButtons;

__interface IdxRibbonApplicationMenu;
typedef System::DelphiInterface<IdxRibbonApplicationMenu> _di_IdxRibbonApplicationMenu;
class DELPHICLASS TdxCustomRibbon;
__interface  INTERFACE_UUID("{DF34053B-F30D-4FC6-94D5-5863620E8F28}") IdxRibbonApplicationMenu  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanShowPopup(TdxCustomRibbon* ARibbon) = 0 ;
	virtual bool __fastcall ClosePopup(void) = 0 ;
	virtual TdxRibbonApplicationMenuDisplayMode __fastcall GetDisplayMode(void) = 0 ;
	virtual System::Types::TPoint __fastcall GetOrigin(bool AIsClientArea) = 0 ;
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetRootAccessibilityHelper(void) = 0 ;
	virtual void __fastcall GetTabOrderList(System::Classes::TList* List) = 0 ;
	virtual bool __fastcall Popup(TdxCustomRibbon* ARibbon, bool &AClosedByEscape) = 0 ;
	virtual void __fastcall RibbonFormResized(void) = 0 ;
	virtual void __fastcall SelectAppMenuFirstItemControl(void) = 0 ;
	virtual void __fastcall ShowKeyTips(void) = 0 ;
	virtual void __fastcall UpdateNonClientArea(void) = 0 ;
};

__interface IdxRibbonListener;
typedef System::DelphiInterface<IdxRibbonListener> _di_IdxRibbonListener;
__interface  INTERFACE_UUID("{E3CD1F8D-4F7F-4448-A877-28726BDDD97F}") IdxRibbonListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall AfterBarManagerChange(void) = 0 ;
	virtual void __fastcall BeforeBarManagerChange(void) = 0 ;
};

__interface IdxRibbonMouseWheelReceiver;
typedef System::DelphiInterface<IdxRibbonMouseWheelReceiver> _di_IdxRibbonMouseWheelReceiver;
__interface  INTERFACE_UUID("{A5D2167B-0343-4525-915F-D41B49832045}") IdxRibbonMouseWheelReceiver  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanProcessMouseWheel(void) = 0 ;
	virtual bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos) = 0 ;
};

__interface IdxRibbonToolbarContainer;
typedef System::DelphiInterface<IdxRibbonToolbarContainer> _di_IdxRibbonToolbarContainer;
__interface  INTERFACE_UUID("{4C6EF60C-C784-44B7-A40E-382ADDB36F61}") IdxRibbonToolbarContainer  : public System::IInterface 
{
	
public:
	virtual TdxCustomRibbon* __fastcall GetRibbon(void) = 0 ;
	virtual Dxbar::TdxBar* __fastcall GetToolbar(void) = 0 ;
	virtual void __fastcall SetToolbar(Dxbar::TdxBar* AValue) = 0 ;
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property Dxbar::TdxBar* Toolbar = {read=GetToolbar, write=SetToolbar};
};

__interface IdxRibbonFormNonClientDraw;
typedef System::DelphiInterface<IdxRibbonFormNonClientDraw> _di_IdxRibbonFormNonClientDraw;
__interface  INTERFACE_UUID("{0A28260B-C352-4704-A88B-44DD8461955C}") IdxRibbonFormNonClientDraw  : public System::IInterface 
{
	
public:
	virtual void __fastcall Add(System::TObject* AObject) = 0 ;
	virtual void __fastcall Remove(System::TObject* AObject) = 0 ;
};

__interface IdxRibbonFormStatusBar;
typedef System::DelphiInterface<IdxRibbonFormStatusBar> _di_IdxRibbonFormStatusBar;
__interface  INTERFACE_UUID("{E6AA56DF-B87A-4D98-98CF-B41BA751594D}") IdxRibbonFormStatusBar  : public System::IInterface 
{
	
public:
	virtual bool __fastcall GetActive(Vcl::Forms::TCustomForm* AForm) = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetControl(void) = 0 ;
	virtual int __fastcall GetHeight(void) = 0 ;
	virtual bool __fastcall GetIsRaised(bool ALeft) = 0 ;
};

class DELPHICLASS TdxRibbonCustomMergeData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomMergeData : public Dxbar::TdxBarCustomMergeData
{
	typedef Dxbar::TdxBarCustomMergeData inherited;
	
private:
	Cxclasses::TcxComponentList* FChildren;
	void __fastcall ListChangeHandler(System::TObject* Sender, System::Classes::TComponent* AComponent, System::Classes::TListNotification AAction);
	
protected:
	virtual void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	
public:
	__fastcall virtual TdxRibbonCustomMergeData(void);
	__fastcall virtual ~TdxRibbonCustomMergeData(void);
	__property Cxclasses::TcxComponentList* Children = {read=FChildren};
};

#pragma pack(pop)

class DELPHICLASS TdxCustomDesignSelectionHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomDesignSelectionHelper : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	System::Classes::TComponent* FComponent;
	System::Classes::TPersistent* FOwner;
	System::Classes::TPersistent* FParent;
	
protected:
	bool __fastcall CanDelete(bool ADestruction = false);
	void __fastcall DeleteSelection(Dxbar::_di_IdxBarSelectableItem &AReference, bool ADestruction);
	void __fastcall ExecuteCustomizationAction(Dxbar::TdxBarCustomizationAction ABasicAction);
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	System::Classes::TPersistent* __fastcall GetInstance(void);
	void __fastcall GetMasterObjects(Dxbar::TdxObjectList* AList);
	Dxbar::_di_IdxBarSelectableItem __fastcall GetNextSelectableItem(void);
	System::Classes::TPersistent* __fastcall GetSelectableParent(void);
	Dxbar::TdxBarSelectionStatus __fastcall GetSelectionStatus(void);
	Dxbar::TdxBarCustomizationActions __fastcall GetSupportedActions(void);
	virtual void __fastcall Invalidate(void);
	bool __fastcall IsComplex(void);
	bool __fastcall IsComponentSelected(void);
	void __fastcall SelectComponent(Dxbar::TdxBarSelectionOperation ASelectionOperation = (Dxbar::TdxBarSelectionOperation)(0x2));
	bool __fastcall SelectParentComponent(void);
	void __fastcall SelectionChanged(void);
	__property Dxbar::TdxBarManager* BarManager = {read=GetBarManager};
	__property System::Classes::TComponent* Component = {read=FComponent};
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	__property System::Classes::TPersistent* Parent = {read=FParent};
	
public:
	__fastcall TdxCustomDesignSelectionHelper(System::Classes::TComponent* AComponent, System::Classes::TPersistent* AOwner, System::Classes::TPersistent* AParent);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomDesignSelectionHelper(void) { }
	
private:
	void *__IdxBarSelectableItem;	/* Dxbar::IdxBarSelectableItem */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6DCCAA42-48D0-4D7D-BEDF-1EADC2197131}
	operator Dxbar::_di_IdxBarSelectableItem()
	{
		Dxbar::_di_IdxBarSelectableItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarSelectableItem*(void) { return (Dxbar::IdxBarSelectableItem*)&__IdxBarSelectableItem; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxDesignSelectionHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDesignSelectionHelper : public TdxCustomDesignSelectionHelper
{
	typedef TdxCustomDesignSelectionHelper inherited;
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	virtual void __fastcall Invalidate(void);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
public:
	/* TdxCustomDesignSelectionHelper.Create */ inline __fastcall TdxDesignSelectionHelper(System::Classes::TComponent* AComponent, System::Classes::TPersistent* AOwner, System::Classes::TPersistent* AParent) : TdxCustomDesignSelectionHelper(AComponent, AOwner, AParent) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDesignSelectionHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomRibbon* FRibbon;
	Dxribbonskins::TdxCustomRibbonSkin* __fastcall GetColorScheme(void);
	
protected:
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Dxribbonskins::TdxRibbonTabState AState);
	virtual void __fastcall DrawContextTabBackground(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor AColor, const System::Types::TRect &ABounds, Dxribbonskins::TdxRibbonTabState AState);
	virtual void __fastcall DrawContextTabSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, bool ABeginGroup);
	virtual void __fastcall DrawTabSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Byte Alpha);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, bool AHasSeparator, bool AIsPaintOnGlass);
	
public:
	__fastcall TdxRibbonTabPainter(TdxCustomRibbon* ARibbon);
	__property Dxribbonskins::TdxCustomRibbonSkin* ColorScheme = {read=GetColorScheme};
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonTabPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonPainter;
class DELPHICLASS TdxRibbonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomRibbon* FRibbon;
	Dxribbonskins::TdxCustomRibbonSkin* __fastcall GetColorScheme(void);
	Dxribbonskins::TdxRibbonColorSchemeAccent __fastcall GetColorSchemeAccent(void);
	HICON __fastcall GetFormIconHandle(void);
	bool __fastcall GetIsFormZoomed(void);
	TdxRibbonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	void __fastcall DrawEmptyRibbon(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxRibbonPainter(TdxCustomRibbon* ARibbon);
	void __fastcall AdjustContextFont(Vcl::Graphics::TFont* AFont, System::Uitypes::TColor AContextColor);
	virtual int __fastcall GetGroupCaptionBottomOffset(void);
	Dxribbonskins::TdxRibbonFormInfo __fastcall GetRibbonFormInfo(const Dxribbonskins::TdxRibbonFormData &AData);
	virtual void __fastcall DrawRibbonFormCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const Dxribbonskins::TdxRibbonFormData &AData);
	virtual void __fastcall DrawRibbonFormCaptionFrameArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, const Dxribbonskins::TdxRibbonFormData &AData);
	virtual void __fastcall DrawRibbonFormBorderIcon(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, Dxribbonskins::TdxRibbonBorderIconState AState);
	virtual void __fastcall DrawRibbonFormBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABordersWidth, const Dxribbonskins::TdxRibbonFormData &AData);
	virtual void __fastcall DrawApplicationButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Dxribbonskins::TdxRibbonApplicationButtonState AState);
	virtual void __fastcall DrawApplicationButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Vcl::Graphics::TBitmap* AGlyph);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawContextBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextBackgroundGlass(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContextGroupsArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, bool AIsQATAtBottom, bool AIsInPopup);
	void __fastcall DrawFormDefaultIcon(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawGlyph(Cxgraphics::TcxCanvas* ACanvas, Vcl::Graphics::TBitmap* AGlyph, const System::Types::TRect &ABounds);
	void __fastcall DrawGlowingText(HDC DC, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor, unsigned AFlags, bool ATransparent = false);
	virtual void __fastcall DrawGroupsArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, bool AIsAllowContextPaint = true, bool AIsInPopup = false);
	virtual void __fastcall DrawGroupsScrollButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, bool ALeft, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawGroupsScrollButtonArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, bool ALeft);
	virtual void __fastcall DrawRibbonFormCaptionText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString ADocumentName, const System::UnicodeString ACaption, const Dxribbonskins::TdxRibbonFormData &AData);
	virtual void __fastcall DrawRibbonGlassFormCaptionText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString ADocumentName, const System::UnicodeString ACaption, bool AIsActive);
	virtual void __fastcall DrawRibbonTopFrameAreaSeparator(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawQuickAccessToolbar(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, bool AIsActive);
	virtual void __fastcall DrawTabAreaBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawTabScrollButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, bool ALeft, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawTabScrollButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, bool ALeft);
	virtual void __fastcall DrawHelpButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawHelpButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, Vcl::Graphics::TBitmap* AGlyph, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawMDIButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawMDIButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Dxbar::TdxBarMDIButton AButton, Cxlookandfeelpainters::TcxButtonState AState);
	void __fastcall DrawMinimizeButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxButtonState AState, bool AMinimized);
	void __fastcall DrawMinimizeButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, Dxribbonskins::TdxRibbonMinimizeButtonGlyph AGlyph);
	__property Dxribbonskins::TdxCustomRibbonSkin* ColorScheme = {read=GetColorScheme};
	__property Dxribbonskins::TdxRibbonColorSchemeAccent ColorSchemeAccent = {read=GetColorSchemeAccent, nodefault};
	__property bool IsFormZoomed = {read=GetIsFormZoomed, nodefault};
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
	__property TdxRibbonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonPainter(void) { }
	
};

#pragma pack(pop)

enum TdxRibbonHitTest : unsigned char { rhtNone, rhtTab, rhtApplicationMenu, rhtContext, rhtTabScrollLeft, rhtTabScrollRight, rhtGroupScrollLeft, rhtGroupScrollRight, rhtHelpButton, rhtCustomButton, rhtFormButton };

class DELPHICLASS TdxRibbonHitInfo;
class DELPHICLASS TdxRibbonCustomButtonViewInfo;
class DELPHICLASS TdxRibbonContext;
class DELPHICLASS TdxRibbonTab;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonHitInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxRibbonViewInfo* FOwner;
	TdxRibbonHitTest FHitTest;
	System::TObject* FHitObject;
	System::Types::TPoint FHitPoint;
	TdxRibbonCustomButtonViewInfo* __fastcall GetHitObjectAsButton(void);
	TdxRibbonContext* __fastcall GetHitObjectAsContext(void);
	TdxRibbonTab* __fastcall GetHitObjectAsTab(void);
	
public:
	__fastcall virtual TdxRibbonHitInfo(TdxRibbonViewInfo* AOwner);
	virtual void __fastcall Calculate(const System::Types::TPoint &P);
	bool __fastcall Compare(TdxRibbonHitInfo* const AHitTest);
	virtual void __fastcall Reset(void);
	__property System::TObject* HitObject = {read=FHitObject, write=FHitObject};
	__property TdxRibbonCustomButtonViewInfo* HitObjectAsButton = {read=GetHitObjectAsButton};
	__property TdxRibbonContext* HitObjectAsContext = {read=GetHitObjectAsContext};
	__property TdxRibbonTab* HitObjectAsTab = {read=GetHitObjectAsTab};
	__property System::Types::TPoint HitPoint = {read=FHitPoint, write=Calculate};
	__property TdxRibbonHitTest HitTest = {read=FHitTest, write=FHitTest, nodefault};
	__property TdxRibbonViewInfo* Owner = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonHitInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonCustomViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomViewInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TdxRibbonViewInfo* FOwner;
	TdxCustomRibbon* __fastcall GetRibbon(void);
	
protected:
	System::Types::TRect FBounds;
	
public:
	__fastcall virtual TdxRibbonCustomViewInfo(TdxRibbonViewInfo* AOwner);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
	void __fastcall Invalidate(void);
	virtual void __fastcall InvalidateRect(const System::Types::TRect &R);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TdxRibbonViewInfo* Owner = {read=FOwner};
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonCustomViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonCustomContainerViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomContainerViewInfo : public TdxRibbonCustomViewInfo
{
	typedef TdxRibbonCustomViewInfo inherited;
	
public:
	System::TObject* operator[](int Index) { return Items[Index]; }
	
private:
	Cxclasses::TcxObjectList* FCells;
	int __fastcall GetCount(void);
	System::TObject* __fastcall GetItem(int Index);
	
public:
	__fastcall virtual TdxRibbonCustomContainerViewInfo(TdxRibbonViewInfo* AOwner);
	__fastcall virtual ~TdxRibbonCustomContainerViewInfo(void);
	int __fastcall AddItem(System::TObject* AObject);
	void __fastcall Clear(void);
	__property int Count = {read=GetCount, nodefault};
	__property System::TObject* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonCustomButtonAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomButtonAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	TdxRibbonCustomButtonViewInfo* FButtonViewInfo;
	TdxCustomRibbon* __fastcall GetRibbon(void);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual bool __fastcall IsNavigationKey(System::Word AKey);
	virtual void __fastcall Select(bool ASetFocus);
	virtual void __fastcall Unselect(Dxbar::_di_IdxBarAccessibilityHelper ANextSelectedObject);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual bool __fastcall GetSelectable(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetAssignedKeyTip(void);
	virtual System::UnicodeString __fastcall GetDefaultKeyTip(void);
	virtual void __fastcall GetKeyTipData(System::Classes::TList* AKeyTipsData);
	__property TdxRibbonCustomButtonViewInfo* ButtonViewInfo = {read=FButtonViewInfo};
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	
public:
	__fastcall virtual TdxRibbonCustomButtonAccessibilityHelper(TdxRibbonCustomButtonViewInfo* AButtonViewInfo);
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonCustomButtonAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonCustomButtonAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomButtonViewInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Dxbar::_di_IdxBarAccessibilityHelper FAccessibilityHelper;
	System::Types::TRect FBounds;
	TdxRibbonCustomContainerViewInfo* FOwner;
	Cxlookandfeelpainters::TcxButtonState FState;
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetAccessibilityHelper(void);
	TdxRibbonPainter* __fastcall GetPainter(void);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	TdxRibbonViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AValue);
	
protected:
	virtual TdxRibbonCustomButtonAccessibilityHelper* __fastcall CreateAccessibilityHelper(void);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual bool __fastcall GetIsEnabled(void);
	virtual void __fastcall CalculateState(void);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	bool __fastcall CanFade(void);
	void __fastcall DrawFadeImage(void);
	void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	Dxfading::TdxFadingOptions* __fastcall GetFadingOptions(void);
	
public:
	__fastcall virtual TdxRibbonCustomButtonViewInfo(TdxRibbonCustomContainerViewInfo* AOwner);
	__fastcall virtual ~TdxRibbonCustomButtonViewInfo(void);
	virtual void __fastcall Click(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Invalidate(void);
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
	__property Dxbar::_di_IdxBarAccessibilityHelper AccessibilityHelper = {read=GetAccessibilityHelper};
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property bool Enabled = {read=GetIsEnabled, nodefault};
	__property System::UnicodeString Hint = {read=GetHint};
	__property TdxRibbonCustomContainerViewInfo* Owner = {read=FOwner};
	__property TdxRibbonPainter* Painter = {read=GetPainter};
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=GetState, write=SetState, nodefault};
	__property TdxRibbonViewInfo* ViewInfo = {read=GetViewInfo};
private:
	void *__IdxFadingObjectFadingOptions;	/* Dxfading::IdxFadingObjectFadingOptions */
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FAAAF4F8-7F10-42CD-9368-2BB5A1F1482B}
	operator Dxfading::_di_IdxFadingObjectFadingOptions()
	{
		Dxfading::_di_IdxFadingObjectFadingOptions intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObjectFadingOptions*(void) { return (Dxfading::IdxFadingObjectFadingOptions*)&__IdxFadingObjectFadingOptions; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator Dxfading::_di_IdxFadingObject()
	{
		Dxfading::_di_IdxFadingObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObject*(void) { return (Dxfading::IdxFadingObject*)&__IdxFadingObject; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonCustomScrollButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomScrollButtonViewInfo : public TdxRibbonCustomButtonViewInfo
{
	typedef TdxRibbonCustomButtonViewInfo inherited;
	
protected:
	TdxRibbonScrollButton FScrollButton;
public:
	/* TdxRibbonCustomButtonViewInfo.Create */ inline __fastcall virtual TdxRibbonCustomScrollButtonViewInfo(TdxRibbonCustomContainerViewInfo* AOwner) : TdxRibbonCustomButtonViewInfo(AOwner) { }
	/* TdxRibbonCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonCustomScrollButtonViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxRibbonTabViewInfoClass;

class DELPHICLASS TdxRibbonTabViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxRibbonTabPainter* FPainter;
	TdxRibbonTab* FTab;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	int __fastcall GetContextTabSeparatorWidth(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	bool __fastcall GetIsPaintOnGlass(void);
	bool __fastcall GetIsTabActive(void);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	
protected:
	bool FCanHasSeparator;
	bool FContextBegin;
	bool FContextEnd;
	int FMinWidth;
	int FOptimalWidth;
	int FSeparatorAlphaValue;
	System::Types::TRect FSeparatorBounds;
	System::Types::TRect FTextBounds;
	int FTextWidth;
	int FWidth;
	virtual void __fastcall CalculateWidths(TdxRibbonViewInfo* AViewInfo);
	void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Dxribbonskins::TdxRibbonTabState AState);
	virtual System::Types::TRect __fastcall GetTextBounds(void);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(void);
	virtual Dxribbonskins::TdxRibbonTabState __fastcall GetState(void);
	virtual TdxRibbonTabPainterClass __fastcall GetPainterClass(void);
	bool __fastcall IsSelected(void);
	Cxgraphics::TcxBitmap* __fastcall PrepareFadeImage(bool ADrawHot);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property int ContextTabSeparatorWidth = {read=GetContextTabSeparatorWidth, nodefault};
	__property bool IsPaintOnGlass = {read=GetIsPaintOnGlass, nodefault};
	__property bool IsTabActive = {read=GetIsTabActive, nodefault};
	__property TdxRibbonTabPainter* Painter = {read=FPainter};
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property int Width = {read=FWidth, nodefault};
	
public:
	System::Types::TRect Bounds;
	__fastcall virtual TdxRibbonTabViewInfo(TdxRibbonTab* ATab);
	__fastcall virtual ~TdxRibbonTabViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds, System::Byte ASeparatorAlpha);
	bool __fastcall HasSeparator(void);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property bool ContextBegin = {read=FContextBegin, write=FContextBegin, nodefault};
	__property bool ContextEnd = {read=FContextEnd, write=FContextEnd, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property int MinWidth = {read=FMinWidth, nodefault};
	__property int OptimalWidth = {read=FOptimalWidth, nodefault};
	__property int SeparatorAlphaValue = {read=FSeparatorAlphaValue, nodefault};
	__property System::Types::TRect SeparatorBounds = {read=FSeparatorBounds};
	__property Dxribbonskins::TdxRibbonTabState State = {read=GetState, nodefault};
	__property TdxRibbonTab* Tab = {read=FTab};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
	__property int TextWidth = {read=FTextWidth, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabsScrollButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabsScrollButtonViewInfo : public TdxRibbonCustomScrollButtonViewInfo
{
	typedef TdxRibbonCustomScrollButtonViewInfo inherited;
	
protected:
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	
public:
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
public:
	/* TdxRibbonCustomButtonViewInfo.Create */ inline __fastcall virtual TdxRibbonTabsScrollButtonViewInfo(TdxRibbonCustomContainerViewInfo* AOwner) : TdxRibbonCustomScrollButtonViewInfo(AOwner) { }
	/* TdxRibbonCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonTabsScrollButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabsViewInfo;
class DELPHICLASS TdxRibbonController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabsViewInfo : public TdxRibbonCustomContainerViewInfo
{
	typedef TdxRibbonCustomContainerViewInfo inherited;
	
public:
	TdxRibbonTabViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	Cxgraphics::TcxBitmap32* FBitmap;
	bool FHasButtonOnRight;
	bool FNeedShowHint;
	TdxRibbonTabsScrollButtonViewInfo* FScrollButtonLeft;
	TdxRibbonTabsScrollButtonViewInfo* FScrollButtonRight;
	TdxRibbonScrollButtons FScrollButtons;
	int FScrollPosition;
	int FScrollWidth;
	System::Byte FSeparatorAlpha;
	int FTotalMinimalWidth;
	int FTotalOptimalWidth;
	void __fastcall CalculateScrollButtons(void);
	void __fastcall CheckScrollPosition(int &Value);
	TdxRibbonController* __fastcall GetController(void);
	int __fastcall GetLongestTabWidth(void);
	TdxRibbonPainter* __fastcall GetPainter(void);
	int __fastcall GetRealMinItemWidth(int Index);
	int __fastcall GetScrollWidth(void);
	TdxRibbonTabViewInfo* __fastcall GetTabViewInfo(int Index);
	void __fastcall RemoveScrolling(void);
	void __fastcall SetScrollPosition(int Value);
	
protected:
	void __fastcall BalancedReduce(int ATotalDelta);
	virtual void __fastcall CalculateComplexTabLayout(void);
	virtual void __fastcall CalculateSimpleTabLayout(void);
	virtual void __fastcall CalculateScrollingTabLayout(void);
	virtual void __fastcall CreateContextualTabsViewInfoCells(void);
	virtual void __fastcall CreateTabsViewInfoCells(void);
	void __fastcall SimpleReduce(int ATotalDelta);
	__property TdxRibbonController* Controller = {read=GetController};
	
public:
	__fastcall virtual TdxRibbonTabsViewInfo(TdxRibbonViewInfo* AOwner);
	__fastcall virtual ~TdxRibbonTabsViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
	System::Types::TRect __fastcall GetRealBounds(void);
	TdxRibbonTabViewInfo* __fastcall Last(void);
	void __fastcall MakeTabVisible(TdxRibbonTab* ATab);
	void __fastcall RecreateViewInfoCells(void);
	void __fastcall UpdateButtonsStates(void);
	void __fastcall UpdateDockControls(void);
	__property Cxgraphics::TcxBitmap32* Bitmap = {read=FBitmap};
	__property TdxRibbonTabViewInfo* Items[int Index] = {read=GetTabViewInfo/*, default*/};
	__property bool NeedShowHint = {read=FNeedShowHint, nodefault};
	__property TdxRibbonPainter* Painter = {read=GetPainter};
	__property TdxRibbonScrollButtons ScrollButtons = {read=FScrollButtons, nodefault};
	__property int ScrollPosition = {read=FScrollPosition, write=SetScrollPosition, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonHelpButtonViewInfo;
class DELPHICLASS TdxRibbonHelpButton;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonHelpButtonViewInfo : public TdxRibbonCustomButtonViewInfo
{
	typedef TdxRibbonCustomButtonViewInfo inherited;
	
private:
	TdxRibbonHelpButton* __fastcall GetHelpButton(void);
	System::Types::TRect __fastcall GetGlyphBounds(void);
	
protected:
	virtual bool __fastcall GetIsEnabled(void);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	
public:
	virtual void __fastcall Click(void);
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
	__property TdxRibbonHelpButton* HelpButton = {read=GetHelpButton};
	__property System::Types::TRect GlyphBounds = {read=GetGlyphBounds};
public:
	/* TdxRibbonCustomButtonViewInfo.Create */ inline __fastcall virtual TdxRibbonHelpButtonViewInfo(TdxRibbonCustomContainerViewInfo* AOwner) : TdxRibbonCustomButtonViewInfo(AOwner) { }
	/* TdxRibbonCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonHelpButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonMinimizeButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonMinimizeButtonViewInfo : public TdxRibbonCustomButtonViewInfo
{
	typedef TdxRibbonCustomButtonViewInfo inherited;
	
private:
	HIDESBASE TdxCustomRibbon* __fastcall GetRibbon(void);
	HIDESBASE Dxribbonskins::TdxRibbonMinimizeButtonGlyph __fastcall GetState(void);
	
protected:
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::UnicodeString __fastcall GetHint(void);
	
public:
	virtual void __fastcall Click(void);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property Dxribbonskins::TdxRibbonMinimizeButtonGlyph State = {read=GetState, nodefault};
public:
	/* TdxRibbonCustomButtonViewInfo.Create */ inline __fastcall virtual TdxRibbonMinimizeButtonViewInfo(TdxRibbonCustomContainerViewInfo* AOwner) : TdxRibbonCustomButtonViewInfo(AOwner) { }
	/* TdxRibbonCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonMinimizeButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonMDIButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonMDIButtonViewInfo : public TdxRibbonCustomButtonViewInfo
{
	typedef TdxRibbonCustomButtonViewInfo inherited;
	
protected:
	Dxbar::TdxBarMDIButton FButtonType;
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual bool __fastcall GetIsEnabled(void);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	
public:
	virtual void __fastcall Click(void);
	__property Dxbar::TdxBarMDIButton ButtonType = {read=FButtonType, nodefault};
public:
	/* TdxRibbonCustomButtonViewInfo.Create */ inline __fastcall virtual TdxRibbonMDIButtonViewInfo(TdxRibbonCustomContainerViewInfo* AOwner) : TdxRibbonCustomButtonViewInfo(AOwner) { }
	/* TdxRibbonCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonMDIButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonButtonsContainerViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonButtonsContainerViewInfo : public TdxRibbonCustomContainerViewInfo
{
	typedef TdxRibbonCustomContainerViewInfo inherited;
	
public:
	TdxRibbonCustomButtonViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxRibbonCustomButtonViewInfo* __fastcall GetItem(int Index);
	TdxRibbonCustomButtonViewInfo* __fastcall GetSelectedButton(void);
	
protected:
	virtual void __fastcall CalculateButtonsBounds(const System::Types::TRect &ABounds) = 0 ;
	void __fastcall CalculateButtonsStates(void);
	virtual void __fastcall RecreateButtonsViewInfo(void);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
	__property TdxRibbonCustomButtonViewInfo* SelectedButton = {read=GetSelectedButton};
	__property TdxRibbonCustomButtonViewInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxRibbonCustomContainerViewInfo.Create */ inline __fastcall virtual TdxRibbonButtonsContainerViewInfo(TdxRibbonViewInfo* AOwner) : TdxRibbonCustomContainerViewInfo(AOwner) { }
	/* TdxRibbonCustomContainerViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonButtonsContainerViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabsAreaButtonsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabsAreaButtonsViewInfo : public TdxRibbonButtonsContainerViewInfo
{
	typedef TdxRibbonButtonsContainerViewInfo inherited;
	
protected:
	virtual void __fastcall CalculateButtonsBounds(const System::Types::TRect &ABounds);
	virtual void __fastcall RecreateButtonsViewInfo(void);
	
public:
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TdxRibbonCustomContainerViewInfo.Create */ inline __fastcall virtual TdxRibbonTabsAreaButtonsViewInfo(TdxRibbonViewInfo* AOwner) : TdxRibbonButtonsContainerViewInfo(AOwner) { }
	/* TdxRibbonCustomContainerViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonTabsAreaButtonsViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonContextViewInfo;
class DELPHICLASS TdxRibbonContextsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonContextViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxRibbonContext* FContext;
	TdxRibbonContextsViewInfo* FOwner;
	System::UnicodeString FText;
	System::Types::TRect __fastcall CalculateTextBounds(HDC DC, int AIndent);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	System::Uitypes::TColor __fastcall GetFontShadowColor(void);
	TdxRibbonPainter* __fastcall GetPainter(void);
	Dxribbonskins::TdxRibbonStyle __fastcall GetRibbonStyle(void);
	bool __fastcall IsPaintOnGlass(void);
	void __fastcall InternalDrawText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor ATextColor, bool AHasGlowing);
	
protected:
	bool FNeedShowHint;
	System::Types::TRect FTextBounds;
	int FTextWidth;
	void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	int __fastcall GetFullTextWidth(void);
	System::Types::TRect __fastcall GetTextBounds(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property TdxRibbonContextsViewInfo* Owner = {read=FOwner};
	__property TdxRibbonPainter* Painter = {read=GetPainter};
	__property Dxribbonskins::TdxRibbonStyle RibbonStyle = {read=GetRibbonStyle, nodefault};
	
public:
	System::Types::TRect Bounds;
	__fastcall virtual TdxRibbonContextViewInfo(TdxRibbonContextsViewInfo* AOwner);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds, TdxRibbonContext* AContext);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property TdxRibbonContext* Context = {read=FContext};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property System::Uitypes::TColor FontShadowColor = {read=GetFontShadowColor, nodefault};
	__property bool NeedShowHint = {read=FNeedShowHint, nodefault};
	__property System::UnicodeString Text = {read=FText};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonContextViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonContextsViewInfo : public TdxRibbonCustomContainerViewInfo
{
	typedef TdxRibbonCustomContainerViewInfo inherited;
	
public:
	TdxRibbonContextViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TdxRibbonContextViewInfo* __fastcall GetContextTabViewInfo(int Index);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	TdxRibbonContextViewInfo* __fastcall GetContextViewInfo(TdxRibbonContext* AContext);
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
	bool __fastcall NeedShowHint(TdxRibbonContext* AContext);
	__property TdxRibbonContextViewInfo* Items[int Index] = {read=GetContextTabViewInfo/*, default*/};
public:
	/* TdxRibbonCustomContainerViewInfo.Create */ inline __fastcall virtual TdxRibbonContextsViewInfo(TdxRibbonViewInfo* AOwner) : TdxRibbonCustomContainerViewInfo(AOwner) { }
	/* TdxRibbonCustomContainerViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonContextsViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonApplicationButtonViewInfo;
class DELPHICLASS TdxRibbonApplicationButton;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonApplicationButtonViewInfo : public TdxRibbonCustomViewInfo
{
	typedef TdxRibbonCustomViewInfo inherited;
	
private:
	bool FIsHot;
	bool FIsPressed;
	bool __fastcall CanShowApplicationButtonText(void);
	TdxRibbonApplicationButton* __fastcall GetApplicationButton(void);
	System::Types::TRect __fastcall GetClientBounds(void);
	System::Types::TRect __fastcall GetClientOffsets(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	System::Types::TRect __fastcall GetGlyphBounds(void);
	System::Types::TRect __fastcall GetGlyphOffsets(void);
	bool __fastcall GetIsPaintOnGlass(void);
	bool __fastcall GetIsPlacedOnTabsArea(void);
	TdxRibbonPainter* __fastcall GetPainter(void);
	Dxribbonskins::TdxRibbonApplicationButtonState __fastcall GetState(void);
	void __fastcall SetIsHot(bool AValue);
	void __fastcall SetIsPressed(bool AValue);
	
protected:
	virtual System::Types::TSize __fastcall CalculateContentSize(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawGlyph(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall CanFade(void);
	void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	Dxfading::TdxFadingOptions* __fastcall GetFadingOptions(void);
	__property bool IsHot = {read=FIsHot, write=SetIsHot, nodefault};
	__property bool IsPressed = {read=FIsPressed, write=SetIsPressed, nodefault};
	__property TdxRibbonPainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual ~TdxRibbonApplicationButtonViewInfo(void);
	HIDESBASE virtual void __fastcall Calculate(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
	bool __fastcall IsVisible(bool AIgnoreHidden = false);
	virtual void __fastcall InvalidateRect(const System::Types::TRect &R);
	__property TdxRibbonApplicationButton* ApplicationButton = {read=GetApplicationButton};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::Types::TRect ClientBounds = {read=GetClientBounds};
	__property System::Types::TRect ClientOffsets = {read=GetClientOffsets};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property System::Types::TRect GlyphBounds = {read=GetGlyphBounds};
	__property System::Types::TRect GlyphOffsets = {read=GetGlyphOffsets};
	__property bool IsPaintOnGlass = {read=GetIsPaintOnGlass, nodefault};
	__property bool IsPlacedOnTabsArea = {read=GetIsPlacedOnTabsArea, nodefault};
	__property Dxribbonskins::TdxRibbonApplicationButtonState State = {read=GetState, nodefault};
public:
	/* TdxRibbonCustomViewInfo.Create */ inline __fastcall virtual TdxRibbonApplicationButtonViewInfo(TdxRibbonViewInfo* AOwner) : TdxRibbonCustomViewInfo(AOwner) { }
	
private:
	void *__IdxFadingObjectFadingOptions;	/* Dxfading::IdxFadingObjectFadingOptions */
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FAAAF4F8-7F10-42CD-9368-2BB5A1F1482B}
	operator Dxfading::_di_IdxFadingObjectFadingOptions()
	{
		Dxfading::_di_IdxFadingObjectFadingOptions intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObjectFadingOptions*(void) { return (Dxfading::IdxFadingObjectFadingOptions*)&__IdxFadingObjectFadingOptions; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator Dxfading::_di_IdxFadingObject()
	{
		Dxfading::_di_IdxFadingObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObject*(void) { return (Dxfading::IdxFadingObject*)&__IdxFadingObject; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGroupsDockControlSiteViewInfo;
class DELPHICLASS TdxRibbonQuickAccessDockControl;
class DELPHICLASS TdxRibbonQuickAccessToolbar;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxRibbonApplicationButtonViewInfo* FApplicationButtonViewInfo;
	System::Types::TRect FBounds;
	TdxRibbonContextsViewInfo* FContextsViewInfo;
	bool FDrawEmptyRibbon;
	Vcl::Graphics::TFont* FFont;
	System::Types::TRect FFormCaptionBounds;
	bool FFormCaptionTheLeftOfContext;
	System::Types::TRect FGroupsDockControlSiteBounds;
	bool FHidden;
	System::Types::TSize FQATBarControlSize;
	System::Types::TRect FQuickAccessToolbarBounds;
	TdxCustomRibbon* FRibbon;
	bool FSupportNonClientDrawing;
	System::Types::TRect FTabGroupsDockControlBounds;
	TdxRibbonTabsAreaButtonsViewInfo* FTabsAreaButtonsViewInfo;
	TdxRibbonTabsViewInfo* FTabsViewInfo;
	bool FUseGlass;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	Dxribbonskins::TdxCustomRibbonSkin* __fastcall GetColorScheme(void);
	TdxRibbonGroupsDockControlSiteViewInfo* __fastcall GetGroupsDockControlSiteViewInfo(void);
	bool __fastcall GetHasActiveContextTab(void);
	bool __fastcall GetIsFormCaptionActive(void);
	bool __fastcall GetIsTabsOnGlass(void);
	TdxRibbonPainter* __fastcall GetPainter(void);
	TdxRibbonQuickAccessDockControl* __fastcall GetQATDockControl(void);
	TdxRibbonQuickAccessToolbar* __fastcall GetQuickAccessToolbar(void);
	int __fastcall GetScrollButtonWidth(void);
	Dxribbonskins::TdxRibbonStyle __fastcall GetStyle(void);
	int __fastcall GetTabsVerticalOffset(void);
	void __fastcall UpdateGroupsDockControlSite(void);
	
protected:
	virtual void __fastcall CalculateContexts(void);
	virtual void __fastcall CalculateQuickAccessToolbar(void);
	virtual void __fastcall CalculateRibbonFormCaption(void);
	virtual void __fastcall CalculateTabGroups(void);
	virtual void __fastcall CalculateTabs(void);
	virtual void __fastcall CalculateTabsAreaButtons(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	virtual int __fastcall GetNonClientAreaHeight(void);
	virtual HRGN __fastcall GetNonClientAreaObjectsRegion(void);
	virtual int __fastcall GetRibbonHeight(void);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual System::UnicodeString __fastcall GetDocumentName(void);
	virtual System::Types::TRect __fastcall GetRibbonFormCaptionClientBounds(void);
	virtual System::Types::TRect __fastcall GetRibbonFormCaptionTextBounds(void);
	virtual System::Types::TRect __fastcall GetRibbonFormCaptionTextBoundsWithContext(const System::Types::TRect &ABounds, const System::Types::TRect &ACenterRect, int ATextWidth);
	int __fastcall GetQATAvailWidth(void);
	virtual System::Types::TSize __fastcall GetQATBarControlSize(void);
	virtual System::Types::TRect __fastcall GetQATBounds(void);
	virtual int __fastcall GetQATHeight(void);
	virtual int __fastcall GetQATLeft(void);
	int __fastcall GetQATOverrideWidth(bool AIgnoreHidden = false);
	virtual int __fastcall GetQATTop(void);
	virtual int __fastcall GetQATWidth(void);
	virtual System::Types::TRect __fastcall GetQATDockControlBounds(void);
	virtual System::Types::TRect __fastcall GetQATDockControlOffset(bool AIgnoreHidden = false);
	virtual System::Types::TRect __fastcall GetGroupsDockControlSiteBounds(void);
	virtual System::Types::TRect __fastcall GetTabGroupsContentOffset(void);
	virtual System::Types::TRect __fastcall GetTabGroupsDockControlBounds(void);
	virtual System::Types::TRect __fastcall GetTabGroupsDockControlOffset(void);
	virtual int __fastcall GetTabGroupsHeight(bool AIgnoreHidden = false);
	virtual System::Types::TRect __fastcall GetTabsAreaBounds(void);
	virtual System::Types::TRect __fastcall GetTabsBounds(void);
	virtual int __fastcall GetTabsHeight(void);
	virtual System::Types::TRect __fastcall GetTabContentOffsets(void);
	virtual TdxRibbonTabViewInfoClass __fastcall GetTabViewInfoClass(void);
	bool __fastcall HasMDIButtons(void);
	bool __fastcall IsMDIButtonEnabled(Dxbar::TdxBarMDIButton AButton, int AState);
	bool __fastcall CanShowBarControls(bool AIgnoreHidden = false);
	int __fastcall GetContextCaptionWidth(const System::UnicodeString ACaption);
	void __fastcall DrawRibbonBackground(Cxgraphics::TcxCanvas* ACanvas);
	bool __fastcall IsNeedDrawBottomLine(void);
	bool __fastcall IsNeedHideControl(void);
	bool __fastcall IsQATAtBottom(void);
	void __fastcall UpdateButtonsStates(void);
	void __fastcall UpdateNonClientParams(void);
	void __fastcall UpdateQATDockControl(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property Dxribbonskins::TdxCustomRibbonSkin* ColorScheme = {read=GetColorScheme};
	__property bool DrawEmptyRibbon = {read=FDrawEmptyRibbon, nodefault};
	__property bool IsTabsOnGlass = {read=GetIsTabsOnGlass, nodefault};
	__property TdxRibbonQuickAccessDockControl* QATDockControl = {read=GetQATDockControl};
	__property TdxRibbonQuickAccessToolbar* QuickAccessToolbar = {read=GetQuickAccessToolbar};
	__property int ScrollButtonWidth = {read=GetScrollButtonWidth, nodefault};
	__property Dxribbonskins::TdxRibbonStyle Style = {read=GetStyle, nodefault};
	__property int TabsHeight = {read=GetTabsHeight, nodefault};
	__property bool UseGlass = {read=FUseGlass, nodefault};
	
public:
	__fastcall virtual TdxRibbonViewInfo(TdxCustomRibbon* ARibbon);
	__fastcall virtual ~TdxRibbonViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateHitInfo(TdxRibbonHitInfo* AHitTest);
	int __fastcall AdjustCaptionFontSize(int ASize);
	bool __fastcall CanDrawFormDefaultIcon(const Dxribbonskins::TdxRibbonFormData &AData);
	virtual System::Uitypes::TColor __fastcall GetDocumentNameTextColor(bool AIsActive);
	virtual Vcl::Graphics::TFont* __fastcall GetFormCaptionFont(bool AIsActive);
	Vcl::Controls::TCaption __fastcall GetFormCaptionText(void);
	TdxRibbonTab* __fastcall GetTabAtPos(int X, int Y);
	bool __fastcall IsApplicationButtonNearQAT(bool AIgnoreHidden = false);
	bool __fastcall IsContextsVisible(void);
	bool __fastcall IsQATAtNonClientArea(bool AIgnoreHidden = false);
	bool __fastcall IsQATOnGlass(void);
	bool __fastcall IsQATVisible(bool AIgnoreHidden = false);
	bool __fastcall IsTabGroupsVisible(bool AIgnoreHidden = false);
	bool __fastcall IsTabsVisible(bool AIgnoreHidden = false);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	__property TdxRibbonApplicationButtonViewInfo* ApplicationButtonViewInfo = {read=FApplicationButtonViewInfo};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::UnicodeString Caption = {read=GetCaption};
	__property System::UnicodeString DocumentName = {read=GetDocumentName};
	__property System::Types::TRect FormCaptionBounds = {read=FFormCaptionBounds};
	__property bool Hidden = {read=FHidden, nodefault};
	__property System::Types::TRect TabsAreaBounds = {read=GetTabsAreaBounds};
	__property System::Types::TRect TabsBounds = {read=GetTabsBounds};
	__property bool HasActiveContextTab = {read=GetHasActiveContextTab, nodefault};
	__property bool IsFormCaptionActive = {read=GetIsFormCaptionActive, nodefault};
	__property TdxRibbonPainter* Painter = {read=GetPainter};
	__property System::Types::TRect QuickAccessToolbarBounds = {read=FQuickAccessToolbarBounds};
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
	__property bool SupportNonClientDrawing = {read=FSupportNonClientDrawing, nodefault};
	__property System::Types::TRect GroupsDockControlSiteBounds = {read=FGroupsDockControlSiteBounds};
	__property System::Types::TRect TabGroupsDockControlBounds = {read=FTabGroupsDockControlBounds};
	__property TdxRibbonContextsViewInfo* ContextsViewInfo = {read=FContextsViewInfo};
	__property TdxRibbonGroupsDockControlSiteViewInfo* GroupsDockControlSiteViewInfo = {read=GetGroupsDockControlSiteViewInfo};
	__property TdxRibbonTabsAreaButtonsViewInfo* TabsAreaButtonsViewInfo = {read=FTabsAreaButtonsViewInfo};
	__property TdxRibbonTabsViewInfo* TabsViewInfo = {read=FTabsViewInfo};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonBarPainter;
class DELPHICLASS TdxRibbonGroupBarControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBarPainter : public Dxbar::TdxBarSkinnedPainter
{
	typedef Dxbar::TdxBarSkinnedPainter inherited;
	
private:
	int FCollapsedGroupElementSizeDenominator;
	int FCollapsedGroupElementSizeNumerator;
	Dxbar::TdxBarButtonLikeControlDrawParams* FDrawParams;
	TdxCustomRibbon* FRibbon;
	Vcl::Graphics::TBitmap* __fastcall GetCollapsedGroupGlyph(Dxbar::TdxBarControl* ABarControl);
	System::Types::TSize __fastcall GetCollapsedGroupGlyphBackgroundSize(Dxbar::TdxBarControl* ABarControl);
	System::Types::TSize __fastcall GetCollapsedGroupGlyphSize(Dxbar::TdxBarControl* ABarControl);
	int __fastcall GetGroupState(Dxbar::TdxBarControl* ABarControl);
	int __fastcall InternalGetGroupCaptionHeight(int ATextHeight);
	
protected:
	void __fastcall CalculateDrawParams(void);
	void __fastcall DrawCollapsedToolbarBackgroundPart(TdxRibbonGroupBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas, int AGroupState);
	void __fastcall DrawCollapsedToolbarContentPart(TdxRibbonGroupBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas, int AGroupState);
	virtual void __fastcall DrawToolbarContentPart(Dxbar::TdxBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawToolbarNonContentPart(Dxbar::TdxBarControl* ABarControl, HDC DC);
	virtual int __fastcall GetButtonPartState(Dxbar::TdxBarButtonLikeControlDrawParams* const ADrawParams, int AControlPart);
	virtual System::Types::TRect __fastcall GetCollapsedGroupCaptionRect(const System::Types::TRect &AGroupRect);
	virtual int __fastcall GetCollapsedGroupWidth(TdxRibbonGroupBarControl* ABarControl);
	virtual int __fastcall GetGroupCaptionHeight(Vcl::Graphics::TFont* ACaptionFont);
	virtual int __fastcall GetGroupMinWidth(TdxRibbonGroupBarControl* ABarControl);
	__property Dxbar::TdxBarButtonLikeControlDrawParams* DrawParams = {read=FDrawParams};
	
public:
	__fastcall virtual TdxRibbonBarPainter(NativeUInt AData);
	__fastcall virtual ~TdxRibbonBarPainter(void);
	virtual void __fastcall BarDrawBackground(Dxbar::TdxBarControl* ABarControl, HDC ADC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, HBRUSH ABrush, System::Uitypes::TColor AColor);
	virtual System::Types::TRect __fastcall BarMarkRect(Dxbar::TdxBarControl* ABarControl);
	virtual System::Types::TRect __fastcall BarMarkItemRect(Dxbar::TdxBarControl* ABarControl);
	virtual int __fastcall GetGroupRowHeight(int AIconSize, Vcl::Graphics::TFont* AGroupFont);
	virtual int __fastcall DropDownGalleryGetSizingBandHeight(int AIconSize, Vcl::Graphics::TFont* AGroupFont);
	virtual System::Types::TRect __fastcall GetToolbarContentOffsets(Dxbar::TdxBar* ABar, Dxbar::TdxBarDockingStyle ADockingStyle, bool AHasSizeGrip);
	virtual int __fastcall SubMenuControlBeginGroupSize(void);
	virtual int __fastcall SubMenuGetSeparatorSize(void);
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
};

#pragma pack(pop)

class DELPHICLASS TdxCustomRibbonDockControl;
class PASCALIMPLEMENTATION TdxCustomRibbonDockControl : public Dxbar::TdxBarDockControl
{
	typedef Dxbar::TdxBarDockControl inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDblClk(Winapi::Messages::TWMMouse &Message);
	
protected:
	DYNAMIC void __fastcall AdjustSize(void);
	virtual bool __fastcall AllowUndockWhenLoadFromIni(void);
	virtual void __fastcall FillBackground(HDC DC, const System::Types::TRect &ADestR, const System::Types::TRect &ASourceR, HBRUSH ABrush, System::Uitypes::TColor AColor);
	virtual bool __fastcall GetSunkenBorder(void);
	virtual bool __fastcall IsDrawDesignBorder(void);
	virtual bool __fastcall IsTransparent(void);
	virtual void __fastcall VisibleChanged(void);
	
public:
	virtual void __fastcall UpdateColorScheme(void);
public:
	/* TdxBarDockControl.Create */ inline __fastcall virtual TdxCustomRibbonDockControl(System::Classes::TComponent* AOwner) : Dxbar::TdxBarDockControl(AOwner) { }
	
public:
	/* TdxDockControl.CreateEx */ inline __fastcall TdxCustomRibbonDockControl(System::Classes::TComponent* AOwner, Dxbar::TdxBarManager* ABarManager, Dxbar::TdxBarDockingStyle ADockStyle) : Dxbar::TdxBarDockControl(AOwner, ABarManager, ADockStyle) { }
	/* TdxDockControl.Destroy */ inline __fastcall virtual ~TdxCustomRibbonDockControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomRibbonDockControl(HWND ParentWindow) : Dxbar::TdxBarDockControl(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TdxRibbonGroupOffsetsInfo
{
public:
	int ButtonGroupOffset;
	int ContentLeftOffset;
	int ContentRightOffset;
};


__interface IdxRibbonGroupViewInfo;
typedef System::DelphiInterface<IdxRibbonGroupViewInfo> _di_IdxRibbonGroupViewInfo;
__interface  INTERFACE_UUID("{A2CAD367-1836-4FA7-8730-8E7531463C8C}") IdxRibbonGroupViewInfo  : public System::IInterface 
{
	
public:
	virtual void __fastcall AddSeparator(const Dxbar::TdxBarItemSeparatorInfo &Value) = 0 ;
	virtual void __fastcall DeleteSeparators(void) = 0 ;
	virtual System::Types::TSize __fastcall GetContentSize(void) = 0 ;
	virtual int __fastcall GetItemControlCount(void) = 0 ;
	virtual Dxbar::_di_IdxBarItemControlViewInfo __fastcall GetItemControlViewInfo(int AIndex) = 0 ;
	virtual int __fastcall GetMinContentWidth(void) = 0 ;
	virtual TdxRibbonGroupOffsetsInfo __fastcall GetOffsetsInfo(void) = 0 ;
	virtual int __fastcall GetSeparatorCount(void) = 0 ;
	virtual Dxbar::TdxBarItemSeparatorInfo __fastcall GetSeparatorInfo(int AIndex) = 0 ;
	virtual void __fastcall SetContentSize(const System::Types::TSize &Value) = 0 ;
	virtual void __fastcall SetSeparatorInfo(int AIndex, const Dxbar::TdxBarItemSeparatorInfo &Value) = 0 ;
};

__interface IdxRibbonGroupLayoutCalculator;
typedef System::DelphiInterface<IdxRibbonGroupLayoutCalculator> _di_IdxRibbonGroupLayoutCalculator;
__interface  INTERFACE_UUID("{894AC146-F69A-4ED2-9293-AA54AAAE1189}") IdxRibbonGroupLayoutCalculator  : public System::IInterface 
{
	
public:
	virtual void __fastcall CalcInit(_di_IdxRibbonGroupViewInfo AGroupViewInfo) = 0 ;
	virtual void __fastcall CalcLayout(_di_IdxRibbonGroupViewInfo AGroupViewInfo) = 0 ;
	virtual bool __fastcall CollapseMultiColumnItemControls(_di_IdxRibbonGroupViewInfo AGroupViewInfo) = 0 ;
	virtual bool __fastcall DecreaseMultiColumnItemControlsColumnCount(_di_IdxRibbonGroupViewInfo AGroupViewInfo) = 0 ;
	virtual bool __fastcall Reduce(_di_IdxRibbonGroupViewInfo AGroupViewInfo, Dxbar::TdxBarItemRealViewLevel AUpToViewLevel) = 0 ;
	virtual void __fastcall ReduceInit(_di_IdxRibbonGroupViewInfo AGroupViewInfo) = 0 ;
};

class DELPHICLASS TdxRibbonGroupsDockControl;
class DELPHICLASS TdxRibbonGroupsDockControlViewInfo;
class PASCALIMPLEMENTATION TdxRibbonGroupsDockControl : public TdxCustomRibbonDockControl
{
	typedef TdxCustomRibbonDockControl inherited;
	
private:
	TdxRibbonTab* FTab;
	void __fastcall DesignMenuClick(System::TObject* Sender);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	TdxRibbonGroupsDockControlSiteViewInfo* __fastcall GetSiteViewInfo(void);
	void __fastcall InitDesignMenu(Dxbar::TdxBarItemLinks* AItemLinks);
	void __fastcall ShowDesignMenu(void);
	HIDESBASE MESSAGE void __fastcall WMGestureNotify(Dxtouch::TWMGestureNotify &Message);
	
protected:
	TdxRibbonGroupsDockControlViewInfo* FViewInfo;
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall CalcRowToolbarPositions(int ARowIndex, int AClientSize);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall FillBackground(HDC DC, const System::Types::TRect &ADestR, const System::Types::TRect &ASourceR, HBRUSH ABrush, System::Uitypes::TColor AColor);
	void __fastcall FullInvalidate(void);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Dxbar::TdxBarControlClass __fastcall GetDockedBarControlClass(void);
	virtual Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	virtual TdxRibbonGroupsDockControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall IsMultiRow(void);
	virtual void __fastcall MakeRectFullyVisible(const System::Types::TRect &R);
	virtual void __fastcall Paint(void);
	virtual void __fastcall SetSize(void);
	virtual void __fastcall ShowCustomizePopup(void);
	void __fastcall UpdateGroupPositions(void);
	virtual void __fastcall VisibleChanged(void);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property TdxRibbonGroupsDockControlSiteViewInfo* SiteViewInfo = {read=GetSiteViewInfo};
	__property TdxRibbonGroupsDockControlViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TdxRibbonGroupsDockControl(TdxRibbonTab* ATab);
	__fastcall virtual ~TdxRibbonGroupsDockControl(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TdxRibbonTab* Tab = {read=FTab};
public:
	/* TdxDockControl.CreateEx */ inline __fastcall TdxRibbonGroupsDockControl(System::Classes::TComponent* AOwner, Dxbar::TdxBarManager* ABarManager, Dxbar::TdxBarDockingStyle ADockStyle) : TdxCustomRibbonDockControl(AOwner, ABarManager, ADockStyle) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonGroupsDockControl(HWND ParentWindow) : TdxCustomRibbonDockControl(ParentWindow) { }
	
};


enum TdxRibbonGroupsReduceStage : unsigned char { rgrsMultiColumnItemControlsColumnCount, rgrsMultiColumnItemControlsCollapsing, rgrsItemControlsViewLevel, rgrsGroupsCollapsing };

class DELPHICLASS TdxRibbonGroupBarControlViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGroupsDockControlViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxRibbonScrollButtons FScrollButtons;
	int FScrollPosition;
	void __fastcall CheckGroupsCollapsedStates(void);
	int __fastcall GetFirstGroupPosition(void);
	int __fastcall GetGroupCount(void);
	TdxRibbonGroupBarControlViewInfo* __fastcall GetGroupViewInfo(int AIndex);
	bool __fastcall IsValidToolbar(Dxbar::TdxBar* AToolbar);
	int __fastcall TotalGroupsWidth(void);
	bool __fastcall TryPlaceGroups(int AMaxContentWidth);
	
protected:
	TdxRibbonGroupsDockControl* FDockControl;
	virtual void __fastcall CalculateGroupsScrollInfo(int AMaxContentWidth);
	virtual void __fastcall InternalScrollGroups(int ADelta, int AMaxContentWidth);
	
public:
	__fastcall virtual TdxRibbonGroupsDockControlViewInfo(TdxRibbonGroupsDockControl* ADockControl);
	virtual void __fastcall Calculate(const System::Types::TRect &ABoundsRect);
	void __fastcall ResetScrollInfo(void);
	virtual void __fastcall ScrollGroups(bool AScrollLeft, int AMaxContentWidth);
	__property TdxRibbonGroupsDockControl* DockControl = {read=FDockControl};
	__property int FirstGroupPosition = {read=GetFirstGroupPosition, nodefault};
	__property int GroupCount = {read=GetGroupCount, nodefault};
	__property TdxRibbonGroupBarControlViewInfo* GroupViewInfos[int AIndex] = {read=GetGroupViewInfo};
	__property TdxRibbonScrollButtons ScrollButtons = {read=FScrollButtons, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonGroupsDockControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabGroupsPopupWindow;
class DELPHICLASS TdxRibbonGroupsDockControlSite;
class PASCALIMPLEMENTATION TdxRibbonTabGroupsPopupWindow : public Cxcontainer::TcxCustomPopupWindow
{
	typedef Cxcontainer::TcxCustomPopupWindow inherited;
	
private:
	bool FAllowShowHideAnimation;
	TdxCustomRibbon* FRibbon;
	Dxbar::TdxBarShadow* FShadow;
	bool FSwitchingBetweenTabs;
	bool __fastcall CanShowShadow(void);
	System::Types::TRect __fastcall GetBounds(void);
	TdxRibbonGroupsDockControlSite* __fastcall GetGroupsDockControlSite(void);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMShowWindow(Winapi::Messages::TWMShowWindow &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	
protected:
	virtual System::Types::TPoint __fastcall CalculatePosition(void);
	virtual void __fastcall CalculateSize(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall Deactivate(void);
	virtual void __fastcall DoClosed(void);
	virtual void __fastcall DoShowed(void);
	virtual void __fastcall DoShowing(void);
	void __fastcall HandleNavigationKey(System::Word AKey);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual bool __fastcall NeedIgnoreMouseMessageAfterCloseUp(NativeUInt AWnd, unsigned AMsg, System::Classes::TShiftState AShift, const System::Types::TPoint &APos);
	void __fastcall SetGroupsDockControlSite(void);
	
public:
	__fastcall virtual TdxRibbonTabGroupsPopupWindow(TdxCustomRibbon* ARibbon);
	__fastcall virtual ~TdxRibbonTabGroupsPopupWindow(void);
	__property bool AllowShowHideAnimation = {read=FAllowShowHideAnimation, write=FAllowShowHideAnimation, nodefault};
	__property TdxRibbonGroupsDockControlSite* GroupsDockControlSite = {read=GetGroupsDockControlSite};
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxRibbonTabGroupsPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxcontainer::TcxCustomPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonTabGroupsPopupWindow(HWND ParentWindow) : Cxcontainer::TcxCustomPopupWindow(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonCustomBarControl;
class PASCALIMPLEMENTATION TdxRibbonCustomBarControl : public Dxbar::TdxBarPopupControl
{
	typedef Dxbar::TdxBarPopupControl inherited;
	
private:
	TdxRibbonQuickAccessToolbar* __fastcall GetQuickAccessToolbar(void);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual bool __fastcall AllowSelectionFrame(void);
	virtual bool __fastcall AllowFade(void);
	virtual void __fastcall InitializeForDock(Dxbar::TdxBar* ABar);
	virtual bool __fastcall AllowQuickCustomizing(void);
	virtual bool __fastcall CanAlignControl(Dxbar::TdxBarItemControl* AControl);
	virtual bool __fastcall CanMoving(void);
	virtual void __fastcall DrawBarParentBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Dxbar::TdxBarBehaviorOptions __fastcall GetBehaviorOptions(void);
	virtual Vcl::Graphics::TFont* __fastcall GetEditFont(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual System::Types::TRect __fastcall GetFullItemRect(Dxbar::TdxBarItemControl* Item);
	virtual bool __fastcall GetIsMainMenu(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual TdxCustomRibbon* __fastcall GetRibbon(void) = 0 ;
	virtual bool __fastcall MarkExists(void);
	virtual bool __fastcall NotHandleMouseMove(bool ACheckLastMousePos = true);
	virtual bool __fastcall RealMDIButtonsOnBar(void);
	virtual bool __fastcall ClickAtHeader(void);
	virtual void __fastcall DoPopupMenuClick(System::TObject* Sender);
	virtual TdxRibbonPopupMenuItems __fastcall GetPopupMenuItems(void);
	virtual void __fastcall InitCustomizationPopup(Dxbar::TdxBarItemLinks* AItemLinks);
	void __fastcall PopupMenuClick(System::TObject* Sender);
	virtual void __fastcall ShowPopup(Dxbar::TdxBarItemControl* AItem);
	__property TdxRibbonQuickAccessToolbar* QuickAccessToolbar = {read=GetQuickAccessToolbar};
	
public:
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
public:
	/* TdxBarPopupControl.Create */ inline __fastcall virtual TdxRibbonCustomBarControl(System::Classes::TComponent* AOwner) : Dxbar::TdxBarPopupControl(AOwner) { }
	/* TdxBarPopupControl.Destroy */ inline __fastcall virtual ~TdxRibbonCustomBarControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonCustomBarControl(HWND ParentWindow) : Dxbar::TdxBarPopupControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonQuickAccessBarControl;
class DELPHICLASS TdxRibbonQuickAccessBarControlViewInfo;
class PASCALIMPLEMENTATION TdxRibbonQuickAccessBarControl : public TdxRibbonCustomBarControl
{
	typedef TdxRibbonCustomBarControl inherited;
	
private:
	Cxgraphics::TcxBitmap32* FBitmap;
	Vcl::Graphics::TBitmap* FDefaultGlyph;
	bool FIsWindowCreation;
	int __fastcall GetSeparatorWidth(Dxbar::TdxBarItemControl* AItemControl);
	TdxRibbonQuickAccessBarControlViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	
protected:
	virtual void __fastcall InitializeForDock(Dxbar::TdxBar* ABar);
	bool __fastcall AllItemsVisible(void);
	virtual void __fastcall CalcControlsPositions(void);
	virtual bool __fastcall CanHideAllItemsInSingleLine(void);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DoPaintItem(Dxbar::TdxBarItemControl* AControl, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &AItemRect);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	HIDESBASE virtual System::Types::TRect __fastcall GetClientOffset(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetDefaultItemGlyph(void);
	virtual Dxbar::TdxBarItemViewLevel __fastcall GetItemControlDefaultViewLevel(Dxbar::TdxBarItemControl* AItemControl);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetMarkAccessibilityHelperClass(void);
	virtual int __fastcall GetMarkSize(void);
	virtual int __fastcall GetMinHeight(Dxbar::TdxBarDockingStyle AStyle);
	virtual int __fastcall GetMinWidth(Dxbar::TdxBarDockingStyle AStyle);
	virtual TdxRibbonPopupMenuItems __fastcall GetPopupMenuItems(void);
	virtual Dxbar::TdxBarPopupControlClass __fastcall GetQuickControlClass(void);
	virtual TdxCustomRibbon* __fastcall GetRibbon(void);
	System::Types::TSize __fastcall GetSize(int AMaxWidth);
	virtual System::Types::TSize __fastcall GetSizeForWidth(Dxbar::TdxBarDockingStyle AStyle, int AWidth);
	virtual Dxbar::TCustomdxBarControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall AllowQuickCustomizing(void);
	virtual void __fastcall InitQuickCustomizeItemLinks(Dxbar::TdxBarPopupControl* AQuickControl);
	virtual void __fastcall InitAddRemoveSubItemPopup(Dxbar::TdxBarItemLinks* AItemLinks);
	virtual void __fastcall InitCustomizationPopup(Dxbar::TdxBarItemLinks* AItemLinks);
	virtual bool __fastcall MarkExists(void);
	void __fastcall RemoveItemFromQAT(void);
	virtual void __fastcall ShowPopup(Dxbar::TdxBarItemControl* AItem);
	virtual void __fastcall UpdateDefaultGlyph(Vcl::Graphics::TBitmap* AGlyph);
	virtual void __fastcall UpdateDoubleBuffered(void);
	__property TdxRibbonQuickAccessBarControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxRibbonQuickAccessBarControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonQuickAccessBarControl(void);
	virtual bool __fastcall IsOnGlass(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonQuickAccessBarControl(HWND ParentWindow) : TdxRibbonCustomBarControl(ParentWindow) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessBarControlViewInfo : public Dxbar::TdxBarControlViewInfo
{
	typedef Dxbar::TdxBarControlViewInfo inherited;
	
protected:
	virtual bool __fastcall CanShowSeparators(void);
	virtual bool __fastcall IsLastVisibleItemControl(Dxbar::TdxBarItemControl* AItemControl);
public:
	/* TCustomdxBarControlViewInfo.Create */ inline __fastcall virtual TdxRibbonQuickAccessBarControlViewInfo(Dxbar::TCustomdxBarControl* ABarControl) : Dxbar::TdxBarControlViewInfo(ABarControl) { }
	/* TCustomdxBarControlViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessBarControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessPainter : public TdxRibbonBarPainter
{
	typedef TdxRibbonBarPainter inherited;
	
protected:
	virtual void __fastcall BarDrawMarkBackground(Dxbar::TdxBarControl* ABarControl, HDC DC, const System::Types::TRect &ItemRect, HBRUSH AToolbarBrush);
	virtual void __fastcall DrawGroupButtonControl(Dxbar::TdxBarButtonLikeControlDrawParams* ADrawParams, const System::Types::TRect &ARect);
	virtual void __fastcall DrawToolbarContentPart(Dxbar::TdxBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall MarkButtonWidth(void);
	
public:
	virtual System::Types::TRect __fastcall BarMarkRect(Dxbar::TdxBarControl* ABarControl);
	virtual System::Types::TRect __fastcall BarMarkItemRect(Dxbar::TdxBarControl* ABarControl);
	virtual void __fastcall ComboControlDrawArrowButton(Dxbar::TdxBarEditLikeControlDrawParams* const ADrawParams, const System::Types::TRect &ARect, bool AInClientArea);
	virtual System::Types::TRect __fastcall GetToolbarContentOffsets(Dxbar::TdxBar* ABar, Dxbar::TdxBarDockingStyle ADockingStyle, bool AHasSizeGrip);
	virtual int __fastcall MarkButtonOffset(void);
	virtual int __fastcall MarkSizeX(Dxbar::TdxBarControl* ABarControl);
public:
	/* TdxRibbonBarPainter.Create */ inline __fastcall virtual TdxRibbonQuickAccessPainter(NativeUInt AData) : TdxRibbonBarPainter(AData) { }
	/* TdxRibbonBarPainter.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessPainter(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxRibbonQuickAccessDockControl : public TdxCustomRibbonDockControl
{
	typedef TdxCustomRibbonDockControl inherited;
	
private:
	TdxRibbonQuickAccessPainter* FPainter;
	TdxCustomRibbon* FRibbon;
	
protected:
	virtual void __fastcall CalcLayout(void);
	virtual Dxbar::TdxBarControlClass __fastcall GetDockedBarControlClass(void);
	virtual Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	virtual void __fastcall ShowCustomizePopup(void);
	virtual void __fastcall VisibleChanged(void);
	
public:
	__fastcall virtual TdxRibbonQuickAccessDockControl(TdxCustomRibbon* AOwner);
	__fastcall virtual ~TdxRibbonQuickAccessDockControl(void);
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
public:
	/* TdxDockControl.CreateEx */ inline __fastcall TdxRibbonQuickAccessDockControl(System::Classes::TComponent* AOwner, Dxbar::TdxBarManager* ABarManager, Dxbar::TdxBarDockingStyle ADockStyle) : TdxCustomRibbonDockControl(AOwner, ABarManager, ADockStyle) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonQuickAccessDockControl(HWND ParentWindow) : TdxCustomRibbonDockControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonQuickAccessBarControlDesignHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessBarControlDesignHelper : public Dxbar::TCustomdxBarControlDesignHelper
{
	typedef Dxbar::TCustomdxBarControlDesignHelper inherited;
	
public:
	__classmethod virtual void __fastcall GetEditors(System::Classes::TList* AEditors);
	__classmethod virtual Dxbar::TdxBarCustomizationActions __fastcall GetForbiddenActions();
public:
	/* TObject.Create */ inline __fastcall TdxRibbonQuickAccessBarControlDesignHelper(void) : Dxbar::TCustomdxBarControlDesignHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessBarControlDesignHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessPopupBarControl;
class PASCALIMPLEMENTATION TdxRibbonQuickAccessPopupBarControl : public TdxRibbonQuickAccessBarControl
{
	typedef TdxRibbonQuickAccessBarControl inherited;
	
private:
	Dxbar::TdxBarPainter* FPainter;
	TdxRibbonQuickAccessBarControl* __fastcall GetQuickAccessBarControl(void);
	Dxbar::TdxBarItemLink* __fastcall GetMarkLink(void);
	Dxbar::TCustomdxBarSubItem* __fastcall GetMarkSubItem(void);
	
protected:
	virtual void __fastcall InitializeForDock(Dxbar::TdxBar* ABar);
	virtual System::Types::TRect __fastcall GetClientOffset(void);
	virtual Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	virtual TdxCustomRibbon* __fastcall GetRibbon(void);
	virtual System::Types::TSize __fastcall GetPopupSize(void);
	virtual bool __fastcall HasShadow(void);
	virtual bool __fastcall IsPopup(void);
	__property TdxRibbonQuickAccessBarControl* QuickAccessBarControl = {read=GetQuickAccessBarControl};
	
public:
	__fastcall virtual ~TdxRibbonQuickAccessPopupBarControl(void);
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall Popup(const System::Types::TRect &AOwnerRect);
public:
	/* TdxRibbonQuickAccessBarControl.Create */ inline __fastcall virtual TdxRibbonQuickAccessPopupBarControl(System::Classes::TComponent* AOwner) : TdxRibbonQuickAccessBarControl(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonQuickAccessPopupBarControl(HWND ParentWindow) : TdxRibbonQuickAccessBarControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonQuickAccessPopupPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessPopupPainter : public TdxRibbonQuickAccessPainter
{
	typedef TdxRibbonQuickAccessPainter inherited;
	
protected:
	virtual void __fastcall DrawQuickAccessPopupSubItem(HDC DC, const System::Types::TRect &ARect, int AState);
	virtual void __fastcall DrawToolbarContentPart(Dxbar::TdxBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas);
	
public:
	virtual int __fastcall MarkButtonOffset(void);
	virtual int __fastcall MarkSizeX(Dxbar::TdxBarControl* ABarControl);
public:
	/* TdxRibbonBarPainter.Create */ inline __fastcall virtual TdxRibbonQuickAccessPopupPainter(NativeUInt AData) : TdxRibbonQuickAccessPainter(AData) { }
	/* TdxRibbonBarPainter.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessPopupPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessPopupSubItem;
class PASCALIMPLEMENTATION TdxRibbonQuickAccessPopupSubItem : public Dxbar::TdxBarSubItem
{
	typedef Dxbar::TdxBarSubItem inherited;
	
protected:
	virtual Dxbar::TCustomdxBarControl* __fastcall CreateBarControl(void);
public:
	/* TdxBarSubItem.Create */ inline __fastcall virtual TdxRibbonQuickAccessPopupSubItem(System::Classes::TComponent* AOwner) : Dxbar::TdxBarSubItem(AOwner) { }
	
public:
	/* TCustomdxBarSubItem.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessPopupSubItem(void) { }
	
};


class DELPHICLASS TdxRibbonQuickAccessPopupSubMenuControl;
class PASCALIMPLEMENTATION TdxRibbonQuickAccessPopupSubMenuControl : public Dxbar::TdxBarSubMenuControl
{
	typedef Dxbar::TdxBarSubMenuControl inherited;
	
protected:
	virtual void __fastcall ShowPopup(Dxbar::TdxBarItemControl* AItem);
public:
	/* TdxBarSubMenuControl.Create */ inline __fastcall virtual TdxRibbonQuickAccessPopupSubMenuControl(System::Classes::TComponent* AOwner) : Dxbar::TdxBarSubMenuControl(AOwner) { }
	/* TdxBarSubMenuControl.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessPopupSubMenuControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonQuickAccessPopupSubMenuControl(HWND ParentWindow) : Dxbar::TdxBarSubMenuControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonQuickAccessPopupSubItemControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessPopupSubItemControl : public Dxbar::TdxBarSubItemControl
{
	typedef Dxbar::TdxBarSubItemControl inherited;
	
protected:
	DYNAMIC void __fastcall DoCloseUp(bool AHadSubMenuControl);
	virtual void __fastcall DoPaint(const System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	virtual int __fastcall GetDefaultWidth(void);
public:
	/* TdxBarSubItemControl.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessPopupSubItemControl(void) { }
	
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxRibbonQuickAccessPopupSubItemControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarSubItemControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessPopupSubItemButton;
class PASCALIMPLEMENTATION TdxRibbonQuickAccessPopupSubItemButton : public Dxbar::TdxBarButton
{
	typedef Dxbar::TdxBarButton inherited;
	
public:
	DYNAMIC void __fastcall DoClick(void);
public:
	/* TdxBarButton.Create */ inline __fastcall virtual TdxRibbonQuickAccessPopupSubItemButton(System::Classes::TComponent* AOwner) : Dxbar::TdxBarButton(AOwner) { }
	
public:
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessPopupSubItemButton(void) { }
	
};


class DELPHICLASS TdxRibbonQuickAccessPopupSubItemButtonControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessPopupSubItemButtonControl : public Dxbar::TdxBarButtonControl
{
	typedef Dxbar::TdxBarButtonControl inherited;
	
public:
	/* TdxBarButtonLikeControl.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessPopupSubItemButtonControl(void) { }
	
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxRibbonQuickAccessPopupSubItemButtonControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarButtonControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabGroup;
class PASCALIMPLEMENTATION TdxRibbonGroupBarControl : public TdxRibbonCustomBarControl
{
	typedef TdxRibbonCustomBarControl inherited;
	
private:
	TdxRibbonTabGroup* FGroup;
	TdxCustomRibbon* FRibbon;
	void __fastcall DesignMenuClick(System::TObject* Sender);
	void __fastcall DrawCaptionButtons(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawSelectedFrame(HDC DC, const System::Types::TRect &R);
	bool __fastcall GetCollapsed(void);
	System::Types::TRect __fastcall GetGroupCaptionRect(void);
	System::Types::TRect __fastcall GetGroupDesignRect(void);
	bool __fastcall GetIsComponentSelected(void);
	bool __fastcall GetIsDesignObjectsOnClientArea(void);
	TdxRibbonGroupBarControlViewInfo* __fastcall GetViewInfo(void);
	void __fastcall InitDesignMenu(Dxbar::TdxBarItemLinks* AItemLinks);
	void __fastcall PaintDesignObjects(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall PaintGroupBackground(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall PaintGroupCaptionText(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall ShowGroupDesignMenu(void);
	HIDESBASE MESSAGE void __fastcall WMGestureNotify(Dxtouch::TWMGestureNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	
protected:
	virtual void __fastcall InitializeForDock(Dxbar::TdxBar* ABar);
	Dxfading::TdxFadingOptions* __fastcall GetFadingOptions(void);
	bool __fastcall FadingCanFade(void);
	void __fastcall FadingDrawFadeImage(void);
	void __fastcall FadingGetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	virtual void __fastcall AdjustHintWindowPosition(System::Types::TPoint &APos, const System::Types::TRect &ABoundsRect, int AHeight);
	virtual void __fastcall CalcLayout(void);
	virtual bool __fastcall CanProcessShortCut(void);
	virtual void __fastcall CaptionChanged(void);
	virtual void __fastcall DoHideAll(Dxbar::TdxBarCloseUpReason AReason);
	virtual void __fastcall DoNCPaint(HDC DC);
	void __fastcall DoOpaqueNCPaint(HDC DC);
	virtual void __fastcall DoPaint(void);
	void __fastcall DoTransparentNCPaint(HDC DC);
	virtual void __fastcall DrawBarParentBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContentBackground(void);
	void __fastcall DrawGroupsArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual bool __fastcall IsAllowContextPaint(void);
	virtual void __fastcall DoBarMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, const System::Types::TPoint &APoint, Dxbar::TdxBarItemControl* AItemControl, bool APointInClientRect);
	virtual bool __fastcall ClickAtHeader(void);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual Vcl::Controls::TCaption __fastcall GetCaption(void);
	virtual Dxbar::TdxBarMarkState __fastcall GetMarkDrawState(void);
	virtual System::UnicodeString __fastcall GetMoreButtonsHint(void);
	virtual Dxbar::TdxBarPopupControlClass __fastcall GetQuickControlClass(void);
	virtual TdxCustomRibbon* __fastcall GetRibbon(void);
	virtual Dxbar::TCustomdxBarControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall GlyphChanged(void);
	virtual bool __fastcall HasCaptionButtons(void);
	virtual void __fastcall InitQuickControl(Dxbar::TdxBarPopupControl* AQuickControl);
	virtual void __fastcall MakeItemControlFullyVisible(Dxbar::TdxBarItemControl* AItemControl);
	virtual bool __fastcall MarkExists(void);
	virtual void __fastcall ViewStateChanged(Dxbar::TdxBarViewState APrevValue);
	virtual void __fastcall UpdateCaptionButton(Dxbar::TdxBarCaptionButton* ACaptionButton);
	virtual void __fastcall WindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	__property System::Types::TRect GroupCaptionRect = {read=GetGroupCaptionRect};
	__property System::Types::TRect GroupDesignRect = {read=GetGroupDesignRect};
	__property bool IsComponentSelected = {read=GetIsComponentSelected, nodefault};
	__property bool IsDesignObjectsOnClientArea = {read=GetIsDesignObjectsOnClientArea, nodefault};
	__property TdxRibbonGroupBarControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual ~TdxRibbonGroupBarControl(void);
	virtual void __fastcall CloseUp(void);
	__property bool Collapsed = {read=GetCollapsed, nodefault};
	__property TdxRibbonTabGroup* Group = {read=FGroup};
public:
	/* TdxBarPopupControl.Create */ inline __fastcall virtual TdxRibbonGroupBarControl(System::Classes::TComponent* AOwner) : TdxRibbonCustomBarControl(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonGroupBarControl(HWND ParentWindow) : TdxRibbonCustomBarControl(ParentWindow) { }
	
private:
	void *__IdxFadingObjectFadingOptions;	/* Dxfading::IdxFadingObjectFadingOptions */
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FAAAF4F8-7F10-42CD-9368-2BB5A1F1482B}
	operator Dxfading::_di_IdxFadingObjectFadingOptions()
	{
		Dxfading::_di_IdxFadingObjectFadingOptions intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObjectFadingOptions*(void) { return (Dxfading::IdxFadingObjectFadingOptions*)&__IdxFadingObjectFadingOptions; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator Dxfading::_di_IdxFadingObject()
	{
		Dxfading::_di_IdxFadingObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObject*(void) { return (Dxfading::IdxFadingObject*)&__IdxFadingObject; }
	#endif
	
};


struct DECLSPEC_DRECORD TdxRibbonGroupKeyTipsBaseLinePositions
{
private:
	typedef System::DynamicArray<int> _TdxRibbonGroupKeyTipsBaseLinePositions__1;
	
	
public:
	int BottomKeyTipsBaseLinePosition;
	bool Calculated;
	_TdxRibbonGroupKeyTipsBaseLinePositions__1 RowKeyTipsBaseLinePositions;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGroupBarControlViewInfo : public Dxbar::TCustomdxBarControlViewInfo
{
	typedef Dxbar::TCustomdxBarControlViewInfo inherited;
	
private:
	bool FCollapsed;
	System::Types::TSize FContentSize;
	int FGroupRowHeight;
	TdxRibbonGroupKeyTipsBaseLinePositions FKeyTipsBaseLinePositions;
	_di_IdxRibbonGroupLayoutCalculator FLayoutCalculator;
	System::Types::TSize FNonContentAreaSize;
	bool FPrevCollapsedState;
	_di_IdxRibbonGroupViewInfo __fastcall CreateCalculateHelper(void);
	TdxRibbonGroupBarControl* __fastcall GetBarControl(void);
	int __fastcall GetBottomKeyTipsBaseLinePosition(void);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	int __fastcall GetRowKeyTipsBaseLinePosition(int ARowIndex);
	System::Types::TSize __fastcall GetSize(void);
	
protected:
	void __fastcall CalculateKeyTipsBaseLinePositions(void);
	virtual _di_IdxRibbonGroupLayoutCalculator __fastcall CreateLayoutCalculator(void);
	virtual void __fastcall DoCalculateKeyTipsBaseLinePositions(void);
	virtual System::Types::TSize __fastcall GetNonContentAreaSize(void);
	void __fastcall RecreateItemControlViewInfos(void);
	void __fastcall UpdateItemRects(void);
	__property System::Types::TSize ContentSize = {read=FContentSize, write=FContentSize};
	__property _di_IdxRibbonGroupLayoutCalculator LayoutCalculator = {read=FLayoutCalculator};
	
public:
	virtual void __fastcall AfterCalculate(void);
	virtual void __fastcall BeforeCalculate(bool ACollapsed);
	virtual void __fastcall Calculate(void);
	void __fastcall CheckGroupCollapsedStates(void);
	bool __fastcall Reduce(TdxRibbonGroupsReduceStage AStage, Dxbar::TdxBarItemRealViewLevel AUpToViewLevel);
	void __fastcall ReduceInit(void);
	__property TdxRibbonGroupBarControl* BarControl = {read=GetBarControl};
	__property bool Collapsed = {read=FCollapsed, write=FCollapsed, nodefault};
	__property System::Types::TSize Size = {read=GetSize};
	__property int BottomKeyTipsBaseLinePosition = {read=GetBottomKeyTipsBaseLinePosition, nodefault};
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property int RowKeyTipsBaseLinePositions[int ARowIndex] = {read=GetRowKeyTipsBaseLinePosition};
public:
	/* TCustomdxBarControlViewInfo.Create */ inline __fastcall virtual TdxRibbonGroupBarControlViewInfo(Dxbar::TCustomdxBarControl* ABarControl) : Dxbar::TCustomdxBarControlViewInfo(ABarControl) { }
	/* TCustomdxBarControlViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonGroupBarControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGroupBarControlDesignHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGroupBarControlDesignHelper : public Dxbar::TCustomdxBarControlDesignHelper
{
	typedef Dxbar::TCustomdxBarControlDesignHelper inherited;
	
public:
	__classmethod virtual bool __fastcall CanDynamicallyChangeViewLevels();
	__classmethod virtual Dxbar::TdxBarCustomizationActions __fastcall GetForbiddenActions();
public:
	/* TObject.Create */ inline __fastcall TdxRibbonGroupBarControlDesignHelper(void) : Dxbar::TCustomdxBarControlDesignHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonGroupBarControlDesignHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonCollapsedGroupPopupBarControl;
class PASCALIMPLEMENTATION TdxRibbonCollapsedGroupPopupBarControl : public TdxRibbonGroupBarControl
{
	typedef TdxRibbonGroupBarControl inherited;
	
private:
	bool FAllowNCPaint;
	
protected:
	virtual bool __fastcall AllowNCPaint(void);
	virtual void __fastcall DoBarMouseRightButtonDown(System::Classes::TShiftState Shift, const System::Types::TPoint &APoint, Dxbar::TdxBarItemControl* AItemControl, Dxbar::TdxBarItemControl* APrevSelectedControl, bool APointInClientRect);
	virtual Vcl::Controls::TCaption __fastcall GetCaption(void);
	virtual Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	virtual System::Types::TSize __fastcall GetPopupSize(void);
	virtual System::Types::TSize __fastcall GetSizeForWidth(Dxbar::TdxBarDockingStyle AStyle, int AWidth);
	virtual System::Types::TRect __fastcall IgnoreClickAreaWhenHidePopup(void);
	virtual void __fastcall InitializeForPopup(Dxbar::TdxBarControl* AParentBarControl, Dxbar::TdxBar* ABar);
	virtual bool __fastcall IsPopup(void);
	virtual bool __fastcall NeedHideOnNCMouseClick(void);
	
public:
	__fastcall virtual ~TdxRibbonCollapsedGroupPopupBarControl(void);
	virtual void __fastcall Hide(void);
	virtual void __fastcall Popup(const System::Types::TRect &AOwnerRect);
public:
	/* TdxBarPopupControl.Create */ inline __fastcall virtual TdxRibbonCollapsedGroupPopupBarControl(System::Classes::TComponent* AOwner) : TdxRibbonGroupBarControl(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonCollapsedGroupPopupBarControl(HWND ParentWindow) : TdxRibbonGroupBarControl(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxRibbonTabGroupClass;

enum TdxRibbonTabGroupAssignedValue : unsigned char { rtgavCaption };

typedef System::Set<TdxRibbonTabGroupAssignedValue, TdxRibbonTabGroupAssignedValue::rtgavCaption, TdxRibbonTabGroupAssignedValue::rtgavCaption>  TdxRibbonTabGroupAssignedValues;

enum TdxRibbonTabGroupRestriction : unsigned char { rtgrNone, rtgrNoExpand, rtgrNoCollapse };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabGroup : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
private:
	TdxRibbonTabGroupAssignedValues FAssignedValues;
	System::UnicodeString FCaption;
	Dxbar::_di_IdxBarSelectableItem FDesignSelectionHelper;
	System::UnicodeString FLoadedToolbarName;
	TdxRibbonMergeKind FMergeKind;
	int FMergeOrder;
	TdxRibbonTabGroupRestriction FRestriction;
	Dxbar::TdxBar* FToolbar;
	void __fastcall CheckUndockToolbar(void);
	bool __fastcall GetAnotherTabWithOurToolbar(/* out */ TdxRibbonTab* &ATab);
	bool __fastcall GetCanCollapse(void);
	System::UnicodeString __fastcall GetCaption(void);
	bool __fastcall GetIsCaptionAssigned(void);
	bool __fastcall GetIsToolBarShared(void);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	TdxRibbonTab* __fastcall GetTab(void);
	Dxbar::TdxBar* __fastcall GetToolbar(void);
	bool __fastcall GetVisible(void);
	void __fastcall ReadCaption(System::Classes::TReader* AReader);
	void __fastcall ReadToolbarName(System::Classes::TReader* AReader);
	void __fastcall SetAssignedValues(const TdxRibbonTabGroupAssignedValues AValue);
	void __fastcall SetCanCollapse(bool Value);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetMergeOrder(const int Value);
	void __fastcall SetRestriction(TdxRibbonTabGroupRestriction AValue);
	void __fastcall SetToolbar(Dxbar::TdxBar* Value);
	void __fastcall ValidateToolbar(Dxbar::TdxBar* Value);
	void __fastcall WriteCaption(System::Classes::TWriter* AWriter);
	void __fastcall WriteToolbarName(System::Classes::TWriter* AWriter);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DockToolbar(Dxbar::TdxBar* AToolbar);
	bool __fastcall IsToolbarAcceptable(Dxbar::TdxBar* AToolbar);
	void __fastcall UpdateBarManager(Dxbar::TdxBarManager* ABarManager);
	void __fastcall UpdateToolbarValue(void);
	__property Dxbar::_di_IdxBarSelectableItem DesignSelectionHelper = {read=FDesignSelectionHelper};
	
public:
	__fastcall virtual TdxRibbonTabGroup(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxRibbonTabGroup(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall IsMergeAllowed(void);
	virtual bool __fastcall IsMerged(void);
	virtual void __fastcall Merge(TdxRibbonTabGroup* AGroup, TdxRibbonMergeOptions AMergeOptions = (TdxRibbonMergeOptions() << TdxRibbonMergeOption::rmoCanCreateNewTab << TdxRibbonMergeOption::rmoCanCreateNewGroup << TdxRibbonMergeOption::rmoCanCreateQATToolbar ));
	virtual void __fastcall Unmerge(TdxRibbonTabGroup* AGroup = (TdxRibbonTabGroup*)(0x0));
	__property bool IsToolBarShared = {read=GetIsToolBarShared, nodefault};
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property TdxRibbonTab* Tab = {read=GetTab};
	__property bool Visible = {read=GetVisible, nodefault};
	
__published:
	__property TdxRibbonTabGroupAssignedValues AssignedValues = {read=FAssignedValues, write=SetAssignedValues, stored=false, nodefault};
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=GetIsCaptionAssigned};
	__property TdxRibbonMergeKind MergeKind = {read=FMergeKind, write=FMergeKind, default=0};
	__property int MergeOrder = {read=FMergeOrder, write=SetMergeOrder, default=0};
	__property TdxRibbonTabGroupRestriction Restriction = {read=FRestriction, write=SetRestriction, default=0};
	__property Dxbar::TdxBar* ToolBar = {read=GetToolbar, write=SetToolbar, stored=false};
	__property bool CanCollapse = {read=GetCanCollapse, write=SetCanCollapse, default=1};
private:
	void *__IdxRibbonToolbarContainer;	/* IdxRibbonToolbarContainer */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4C6EF60C-C784-44B7-A40E-382ADDB36F61}
	operator _di_IdxRibbonToolbarContainer()
	{
		_di_IdxRibbonToolbarContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonToolbarContainer*(void) { return (IdxRibbonToolbarContainer*)&__IdxRibbonToolbarContainer; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6DCCAA42-48D0-4D7D-BEDF-1EADC2197131}
	operator Dxbar::_di_IdxBarSelectableItem() { return DesignSelectionHelper; }
	#else
	operator Dxbar::IdxBarSelectableItem*(void) { return (Dxbar::IdxBarSelectableItem*)DesignSelectionHelper; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabGroups;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabGroups : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxRibbonTabGroup* operator[](int Index) { return Items[Index]; }
	
private:
	TdxRibbonTab* FTab;
	HIDESBASE TdxRibbonTabGroup* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxRibbonTabGroup* const Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	virtual void __fastcall Notify(System::Classes::TCollectionItem* Item, System::Classes::TCollectionNotification Action);
	void __fastcall Unmerge(TdxRibbonTabGroup* AGroup = (TdxRibbonTabGroup*)(0x0));
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	void __fastcall UpdateGroupToolbarValues(void);
	
public:
	__fastcall TdxRibbonTabGroups(TdxRibbonTab* ATab);
	HIDESBASE TdxRibbonTabGroup* __fastcall Add(void);
	bool __fastcall ContainsToolBar(Dxbar::TdxBar* AToolBar);
	bool __fastcall Find(const System::UnicodeString ACaption, /* out */ TdxRibbonTabGroup* &AGroup);
	int __fastcall IndexOf(TdxRibbonTabGroup* AGroup);
	HIDESBASE TdxRibbonTabGroup* __fastcall Insert(int AIndex);
	__property TdxRibbonTabGroup* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TdxRibbonTab* Tab = {read=FTab};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxRibbonTabGroups(void) { }
	
};

#pragma pack(pop)

enum TdxQuickAccessToolbarPosition : unsigned char { qtpAboveRibbon, qtpBelowRibbon };

class DELPHICLASS TdxRibbonQuickAccessGroupButton;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessToolbar : public System::Classes::TInterfacedPersistent
{
	typedef System::Classes::TInterfacedPersistent inherited;
	
private:
	TdxRibbonQuickAccessDockControl* FDockControl;
	TdxQuickAccessToolbarPosition FPosition;
	TdxCustomRibbon* FRibbon;
	Dxbar::TdxBar* FToolbar;
	bool FVisible;
	bool __fastcall GetRealVisible(void);
	void __fastcall CheckUndockGroupToolbar(Dxbar::TdxBar* AValue);
	void __fastcall SetPosition(TdxQuickAccessToolbarPosition AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	void __fastcall BarManagerLoadIni(const Dxbar::TdxBarIniFileEventData &AEventData);
	void __fastcall BarManagerSaveIni(const Dxbar::TdxBarIniFileEventData &AEventData);
	bool __fastcall Contains(Dxbar::TdxBarItemLink* AItemLink);
	virtual TdxRibbonQuickAccessDockControl* __fastcall CreateDockControl(void);
	virtual TdxRibbonPopupMenuItems __fastcall GetMenuItemsForMark(void);
	virtual void __fastcall UpdateColorScheme(void);
	void __fastcall UpdateGroupButton(Dxbar::TdxBar* AForToolbar, bool ABeforeUndock);
	void __fastcall UpdateMenuItems(Dxbar::TdxBarItemLinks* AItems);
	void __fastcall UpdateRibbon(void);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	Dxbar::TdxBar* __fastcall GetToolbar(void);
	void __fastcall SetToolbar(Dxbar::TdxBar* AValue);
	__property TdxRibbonQuickAccessDockControl* DockControl = {read=FDockControl};
	__property bool RealVisible = {read=GetRealVisible, nodefault};
	
public:
	__fastcall virtual TdxRibbonQuickAccessToolbar(TdxCustomRibbon* ARibbon);
	__fastcall virtual ~TdxRibbonQuickAccessToolbar(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TdxRibbonQuickAccessGroupButton* __fastcall AddGroupButton(Dxbar::TdxBar* AToolbar);
	bool __fastcall HasGroupButtonForToolbar(Dxbar::TdxBar* AToolbar);
	virtual bool __fastcall IsMerged(void);
	virtual void __fastcall Merge(TdxRibbonQuickAccessToolbar* AQuickAccessToolbar, TdxRibbonMergeOptions AMergeOptions = (TdxRibbonMergeOptions() << TdxRibbonMergeOption::rmoCanCreateNewTab << TdxRibbonMergeOption::rmoCanCreateNewGroup << TdxRibbonMergeOption::rmoCanCreateQATToolbar ));
	virtual void __fastcall Unmerge(TdxRibbonQuickAccessToolbar* AQuickAccessToolbar = (TdxRibbonQuickAccessToolbar*)(0x0));
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	
__published:
	__property TdxQuickAccessToolbarPosition Position = {read=FPosition, write=SetPosition, default=0};
	__property Dxbar::TdxBar* Toolbar = {read=GetToolbar, write=SetToolbar};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
private:
	void *__IdxRibbonToolbarContainer;	/* IdxRibbonToolbarContainer */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4C6EF60C-C784-44B7-A40E-382ADDB36F61}
	operator _di_IdxRibbonToolbarContainer()
	{
		_di_IdxRibbonToolbarContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonToolbarContainer*(void) { return (IdxRibbonToolbarContainer*)&__IdxRibbonToolbarContainer; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonCustomButtonPersistent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomButtonPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Vcl::Graphics::TBitmap* FGlyph;
	TdxCustomRibbon* FRibbon;
	Dxscreentip::TdxScreenTip* FScreenTip;
	bool FStretchGlyph;
	void __fastcall GlyphChanged(System::TObject* Sender);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetScreenTip(Dxscreentip::TdxScreenTip* const Value);
	void __fastcall SetStretchGlyph(const bool Value);
	
protected:
	void __fastcall Update(void);
	
public:
	__fastcall virtual TdxRibbonCustomButtonPersistent(TdxCustomRibbon* ARibbon);
	__fastcall virtual ~TdxRibbonCustomButtonPersistent(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
	
__published:
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property Dxscreentip::TdxScreenTip* ScreenTip = {read=FScreenTip, write=SetScreenTip};
	__property bool StretchGlyph = {read=FStretchGlyph, write=SetStretchGlyph, default=1};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonHelpButton : public TdxRibbonCustomButtonPersistent
{
	typedef TdxRibbonCustomButtonPersistent inherited;
	
public:
	/* TdxRibbonCustomButtonPersistent.Create */ inline __fastcall virtual TdxRibbonHelpButton(TdxCustomRibbon* ARibbon) : TdxRibbonCustomButtonPersistent(ARibbon) { }
	/* TdxRibbonCustomButtonPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonHelpButton(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonApplicationButton : public TdxRibbonCustomButtonPersistent
{
	typedef TdxRibbonCustomButtonPersistent inherited;
	
private:
	Dxbar::_di_IdxBarAccessibilityHelper FIAccessibilityHelper;
	_di_IdxRibbonApplicationMenu FIMenu;
	System::UnicodeString FKeyTip;
	System::Classes::TComponent* FMenu;
	System::UnicodeString FText;
	bool FVisible;
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	void __fastcall SetMenu(System::Classes::TComponent* const Value);
	void __fastcall SetText(const System::UnicodeString Value);
	void __fastcall SetVisible(const bool Value);
	
protected:
	bool __fastcall CanShowPopup(void);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	bool __fastcall Popup(bool &AClosedByEscape);
	void __fastcall ClosePopup(void);
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property Dxbar::_di_IdxBarAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property _di_IdxRibbonApplicationMenu IMenu = {read=FIMenu};
	
public:
	__fastcall virtual TdxRibbonApplicationButton(TdxCustomRibbon* ARibbon);
	__fastcall virtual ~TdxRibbonApplicationButton(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::UnicodeString KeyTip = {read=FKeyTip, write=FKeyTip};
	__property System::Classes::TComponent* Menu = {read=FMenu, write=SetMenu};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonContexts;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonContext : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::UnicodeString FCaption;
	System::Uitypes::TColor FColor;
	int FMergeOrder;
	bool FVisible;
	TdxRibbonContexts* __fastcall GetCollection(void);
	TdxRibbonContext* __fastcall GetMergedWithContext(void);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	TdxRibbonTab* __fastcall GetTab(int Index);
	int __fastcall GetTabCount(void);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetMergeOrder(const int AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	bool FCreatedByMerging;
	TdxRibbonContext* FCreatedByMergingWith;
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	void __fastcall ColorChanged(void);
	void __fastcall UpdateMergeTargetVisibility(void);
	void __fastcall VisibleChanged(void);
	__property TdxRibbonContexts* Collection = {read=GetCollection};
	__property TdxRibbonContext* MergedWithContext = {read=GetMergedWithContext};
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	
public:
	__fastcall virtual TdxRibbonContext(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Activate(bool AActivateFirstTab = true);
	__property int TabCount = {read=GetTabCount, nodefault};
	__property TdxRibbonTab* Tabs[int Index] = {read=GetTab};
	
__published:
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=16777215};
	__property int MergeOrder = {read=FMergeOrder, write=SetMergeOrder, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TdxRibbonContext(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonContexts : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxRibbonContext* operator[](int Index) { return Items[Index]; }
	
private:
	TdxCustomRibbon* FRibbon;
	TdxRibbonContext* __fastcall GetActiveContext(void);
	HIDESBASE TdxRibbonContext* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxRibbonContext* const Value);
	
protected:
	TdxRibbonContext* __fastcall GetItemFromIndex(int AIndex);
	virtual void __fastcall Notify(System::Classes::TCollectionItem* Item, System::Classes::TCollectionNotification Action);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TdxRibbonContexts(TdxCustomRibbon* ARibbon);
	HIDESBASE TdxRibbonContext* __fastcall Add(void);
	TdxRibbonContext* __fastcall Find(const System::UnicodeString ACaption);
	int __fastcall IndexOf(TdxRibbonContext* AContext);
	HIDESBASE TdxRibbonContext* __fastcall Insert(int AIndex);
	__property TdxRibbonContext* ActiveContext = {read=GetActiveContext};
	__property TdxRibbonContext* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxRibbonContexts(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabMergeData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabMergeData : public TdxRibbonCustomMergeData
{
	typedef TdxRibbonCustomMergeData inherited;
	
public:
	TdxRibbonTab* MergedWith;
public:
	/* TdxRibbonCustomMergeData.Create */ inline __fastcall virtual TdxRibbonTabMergeData(void) : TdxRibbonCustomMergeData() { }
	/* TdxRibbonCustomMergeData.Destroy */ inline __fastcall virtual ~TdxRibbonTabMergeData(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxRibbonTabClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTab : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	System::UnicodeString FCaption;
	TdxRibbonContext* FContext;
	int FContextIndex;
	Dxbar::_di_IdxBarSelectableItem FDesignSelectionHelper;
	TdxRibbonGroupsDockControl* FDockControl;
	TdxRibbonTabGroups* FGroups;
	Dxbar::_di_IdxBarAccessibilityHelper FIAccessibilityHelper;
	System::UnicodeString FKeyTip;
	int FLastIndex;
	int FLoadedIndex;
	bool FLocked;
	TdxRibbonTabMergeData* FMergeData;
	TdxRibbonMergeKind FMergeKind;
	int FMergeOrder;
	TdxCustomRibbon* FRibbon;
	int FSaveContextIndex;
	bool FVisible;
	bool __fastcall GetActive(void);
	bool __fastcall GetFocused(void);
	bool __fastcall GetHighlighted(void);
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	bool __fastcall GetIsDestroying(void);
	TdxRibbonTabViewInfo* __fastcall GetViewInfo(void);
	int __fastcall GetVisibleIndex(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetContext(TdxRibbonContext* AValue);
	void __fastcall SetGroups(TdxRibbonTabGroups* const Value);
	void __fastcall SetHighlighted(bool Value);
	void __fastcall SetMergeOrder(const int AValue);
	void __fastcall SetRibbon(TdxCustomRibbon* Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall ReadContextIndex(System::Classes::TReader* Reader);
	void __fastcall ReadIndex(System::Classes::TReader* Reader);
	void __fastcall WriteContextIndex(System::Classes::TWriter* Writer);
	void __fastcall WriteIndex(System::Classes::TWriter* Writer);
	
protected:
	bool __fastcall CanFade(void);
	void __fastcall FadingDrawFadeImage(void);
	void __fastcall FadingGetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	Dxfading::TdxFadingOptions* __fastcall GetFadingOptions(void);
	virtual bool __fastcall InternalUnmerge(TdxRibbonTab* ATab);
	void __fastcall UnmergeBeforeDestroy(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	virtual void __fastcall Activate(void);
	virtual void __fastcall AssignCommonProperties(TdxRibbonTab* ASource);
	void __fastcall CheckGroupToolbarsDockControl(void);
	virtual void __fastcall Deactivate(void);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual System::Types::TRect __fastcall GetDockControlBounds(void);
	virtual TdxRibbonTabGroupClass __fastcall GetGroupClass(void);
	bool __fastcall IsVisible(void);
	void __fastcall RestoreContext(void);
	void __fastcall RestoreIndex(void);
	void __fastcall SaveContext(void);
	void __fastcall ScrollDockControlGroups(bool AScrollLeft, bool AOnTimer);
	void __fastcall UpdateBarManager(Dxbar::TdxBarManager* ABarManager);
	virtual void __fastcall UpdateColorScheme(void);
	void __fastcall UpdateContextIndex(void);
	void __fastcall UpdateDockControl(void);
	void __fastcall UpdateDockControlBounds(void);
	void __fastcall UpdateGroupsFont(void);
	__property Dxbar::_di_IdxBarSelectableItem DesignSelectionHelper = {read=FDesignSelectionHelper};
	__property bool Focused = {read=GetFocused, nodefault};
	__property bool Highlighted = {read=GetHighlighted, write=SetHighlighted, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property int LastIndex = {read=FLastIndex, nodefault};
	__property int LoadedIndex = {read=FLoadedIndex, nodefault};
	__property bool Locked = {read=FLocked, nodefault};
	__property TdxRibbonTabMergeData* MergeData = {read=FMergeData};
	__property TdxRibbonTabViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TdxRibbonTab(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonTab(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddToolBar(Dxbar::TdxBar* AToolBar);
	void __fastcall Invalidate(void);
	void __fastcall MakeVisible(void);
	virtual bool __fastcall IsMergeAllowed(void);
	virtual bool __fastcall IsMerged(void);
	virtual void __fastcall Merge(TdxRibbonTab* ATab, TdxRibbonMergeOptions AMergeOptions = (TdxRibbonMergeOptions() << TdxRibbonMergeOption::rmoCanCreateNewTab << TdxRibbonMergeOption::rmoCanCreateNewGroup << TdxRibbonMergeOption::rmoCanCreateQATToolbar ));
	virtual void __fastcall Unmerge(TdxRibbonTab* ATab = (TdxRibbonTab*)(0x0));
	__property TdxRibbonGroupsDockControl* DockControl = {read=FDockControl};
	__property Dxbar::_di_IdxBarAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property TdxCustomRibbon* Ribbon = {read=FRibbon, write=SetRibbon};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property TdxRibbonContext* Context = {read=FContext, write=SetContext, stored=false};
	__property TdxRibbonTabGroups* Groups = {read=FGroups, write=SetGroups};
	__property System::UnicodeString KeyTip = {read=FKeyTip, write=FKeyTip};
	__property TdxRibbonMergeKind MergeKind = {read=FMergeKind, write=FMergeKind, default=0};
	__property int MergeOrder = {read=FMergeOrder, write=SetMergeOrder, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int VisibleIndex = {read=GetVisibleIndex, nodefault};
private:
	void *__IdxFadingObjectFadingOptions;	/* Dxfading::IdxFadingObjectFadingOptions */
	void *__IdxFadingObject;	/* Dxfading::IdxFadingObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FAAAF4F8-7F10-42CD-9368-2BB5A1F1482B}
	operator Dxfading::_di_IdxFadingObjectFadingOptions()
	{
		Dxfading::_di_IdxFadingObjectFadingOptions intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObjectFadingOptions*(void) { return (Dxfading::IdxFadingObjectFadingOptions*)&__IdxFadingObjectFadingOptions; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator Dxfading::_di_IdxFadingObject()
	{
		Dxfading::_di_IdxFadingObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxfading::IdxFadingObject*(void) { return (Dxfading::IdxFadingObject*)&__IdxFadingObject; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6DCCAA42-48D0-4D7D-BEDF-1EADC2197131}
	operator Dxbar::_di_IdxBarSelectableItem() { return DesignSelectionHelper; }
	#else
	operator Dxbar::IdxBarSelectableItem*(void) { return (Dxbar::IdxBarSelectableItem*)DesignSelectionHelper; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabCollection;
class PASCALIMPLEMENTATION TdxRibbonTabCollection : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TdxRibbonTab* operator[](int Index) { return Items[Index]; }
	
private:
	TdxCustomRibbon* FOwner;
	Dxbar::_di_IdxBarAccessibilityHelper FIAccessibilityHelper;
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	HIDESBASE TdxRibbonTab* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxRibbonTab* const Value);
	
protected:
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	TdxRibbonTab* __fastcall FindByLoadedIndex(int AIndex);
	void __fastcall InternalUnmerge(TdxRibbonTab* ATab = (TdxRibbonTab*)(0x0));
	virtual void __fastcall Notify(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall RemoveContext(TdxRibbonContext* AContext);
	void __fastcall RestoreContexts(void);
	void __fastcall RestoreOrder(void);
	void __fastcall SaveContexts(void);
	virtual void __fastcall SetItemName(Cxclasses::TcxComponentCollectionItem* AItem);
	virtual void __fastcall Update(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall UpdateBarManager(Dxbar::TdxBarManager* ABarManager);
	void __fastcall UpdateContexts(void);
	__property Dxbar::_di_IdxBarAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property TdxCustomRibbon* Owner = {read=FOwner};
	
public:
	__fastcall TdxRibbonTabCollection(TdxCustomRibbon* AOwner);
	__fastcall virtual ~TdxRibbonTabCollection(void);
	HIDESBASE TdxRibbonTab* __fastcall Add(void);
	bool __fastcall ContainsToolBar(Dxbar::TdxBar* AToolBar);
	TdxRibbonTab* __fastcall Find(const System::UnicodeString ACaption);
	HIDESBASE TdxRibbonTab* __fastcall Insert(int AIndex);
	bool __fastcall IsMerged(void);
	__property TdxRibbonTab* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
};


enum TdxRibbonAssignedFont : unsigned char { afTabHeader, afGroup, afGroupHeader, afApplicationButton };

typedef System::Set<TdxRibbonAssignedFont, TdxRibbonAssignedFont::afTabHeader, TdxRibbonAssignedFont::afApplicationButton>  TdxRibbonAssignedFonts;

class DELPHICLASS TdxRibbonFonts;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonFonts : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxRibbonAssignedFonts FAssignedFonts;
	Vcl::Graphics::TFont* FCaptionFont;
	System::Uitypes::TColor FDocumentNameColor;
	System::StaticArray<Vcl::Graphics::TFont*, 4> FFonts;
	Vcl::Graphics::TFont* FInternalCaptionFont;
	System::StaticArray<Vcl::Graphics::TFont*, 4> FInternalFonts;
	bool FLocked;
	TdxCustomRibbon* FRibbon;
	void __fastcall FontChanged(System::TObject* Sender);
	System::Uitypes::TColor __fastcall GetDefaultCaptionTextColor(bool AIsActive);
	Vcl::Graphics::TFont* __fastcall GetFont(const int Index);
	Vcl::Graphics::TFont* __fastcall GetInternalFont(TdxRibbonAssignedFont AIndex);
	bool __fastcall IsFontStored(const int Index);
	void __fastcall SetAssignedFonts(const TdxRibbonAssignedFonts Value);
	void __fastcall SetDocumentNameColor(const System::Uitypes::TColor Value);
	void __fastcall SetFont(const int Index, Vcl::Graphics::TFont* const Value);
	void __fastcall UpdateGroupsFont(void);
	
protected:
	System::Uitypes::TColor __fastcall GetPartColor(int APart, int AState = 0x0);
	void __fastcall Invalidate(void);
	void __fastcall UpdateFonts(void);
	__property bool Locked = {read=FLocked, nodefault};
	
public:
	__fastcall virtual TdxRibbonFonts(TdxCustomRibbon* AOwner);
	__fastcall virtual ~TdxRibbonFonts(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Vcl::Graphics::TFont* __fastcall GetApplicationButtonFont(Dxribbonskins::TdxRibbonApplicationButtonState AState);
	virtual Vcl::Graphics::TFont* __fastcall GetContextFont(System::Uitypes::TColor AContextColor = (System::Uitypes::TColor)(0x20000000));
	virtual Vcl::Graphics::TFont* __fastcall GetFormCaptionFont(bool AIsActive);
	virtual Vcl::Graphics::TFont* __fastcall GetGroupFont(void);
	virtual Vcl::Graphics::TFont* __fastcall GetGroupHeaderFont(void);
	Vcl::Graphics::TFont* __fastcall GetTabHeaderFont(int AState, TdxRibbonContext* AContext);
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
	
__published:
	__property Vcl::Graphics::TFont* ApplicationButton = {read=GetFont, write=SetFont, stored=IsFontStored, index=3};
	__property TdxRibbonAssignedFonts AssignedFonts = {read=FAssignedFonts, write=SetAssignedFonts, default=0};
	__property System::Uitypes::TColor DocumentNameColor = {read=FDocumentNameColor, write=SetDocumentNameColor, default=536870912};
	__property Vcl::Graphics::TFont* Group = {read=GetFont, write=SetFont, stored=IsFontStored, index=1};
	__property Vcl::Graphics::TFont* GroupHeader = {read=GetFont, write=SetFont, stored=IsFontStored, index=2};
	__property Vcl::Graphics::TFont* TabHeader = {read=GetFont, write=SetFont, stored=IsFontStored, index=0};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonHolderComponent;
class PASCALIMPLEMENTATION TdxRibbonHolderComponent : public Cxclasses::TcxComponentHolder
{
	typedef Cxclasses::TcxComponentHolder inherited;
	
private:
	void __fastcall CheckAssignRibbon(System::Classes::TComponent* AOwner);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	void __fastcall SetRibbon(TdxCustomRibbon* Value);
	
public:
	__fastcall TdxRibbonHolderComponent(System::Classes::TComponent* AOwner);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon, write=SetRibbon};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TdxRibbonHolderComponent(void) { }
	
};


class DELPHICLASS TdxRibbonCustomPopupComponent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomPopupComponent : public Dxbar::TdxBarCustomPopupComponent
{
	typedef Dxbar::TdxBarCustomPopupComponent inherited;
	
private:
	TdxRibbonHolderComponent* FRibbonHolder;
	TdxCustomRibbon* __fastcall GetRibbon(void);
	void __fastcall SetRibbon(TdxCustomRibbon* const Value);
	
public:
	__fastcall virtual TdxRibbonCustomPopupComponent(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonCustomPopupComponent(void);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon, write=SetRibbon};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonCustomPopupMenu;
class PASCALIMPLEMENTATION TdxRibbonCustomPopupMenu : public Dxbar::TdxBarCustomPopupMenu
{
	typedef Dxbar::TdxBarCustomPopupMenu inherited;
	
private:
	TdxRibbonHolderComponent* FRibbonHolder;
	void __fastcall SetRibbon(TdxCustomRibbon* Value);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	
protected:
	virtual Dxbar::TCustomdxBarControl* __fastcall CreateBarControl(void);
	virtual Dxbar::TCustomdxBarControlClass __fastcall GetControlClass(void);
	
public:
	__fastcall virtual TdxRibbonCustomPopupMenu(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonCustomPopupMenu(void);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon, write=SetRibbon};
};


class DELPHICLASS TdxRibbonPopupMenu;
class PASCALIMPLEMENTATION TdxRibbonPopupMenu : public TdxRibbonCustomPopupMenu
{
	typedef TdxRibbonCustomPopupMenu inherited;
	
__published:
	__property BarManager;
	__property BarSize = {default=0};
	__property Font;
	__property ItemLinks;
	__property ItemOptions;
	__property PopupAlignment = {default=0};
	__property Ribbon;
	__property UseOwnFont;
	__property UseRecentItems = {default=0};
	__property OnCloseUp;
	__property OnPaintBar;
	__property OnPopup;
public:
	/* TdxRibbonCustomPopupMenu.Create */ inline __fastcall virtual TdxRibbonPopupMenu(System::Classes::TComponent* AOwner) : TdxRibbonCustomPopupMenu(AOwner) { }
	/* TdxRibbonCustomPopupMenu.Destroy */ inline __fastcall virtual ~TdxRibbonPopupMenu(void) { }
	
};


class DELPHICLASS TdxRibbonPopupMenuControl;
class PASCALIMPLEMENTATION TdxRibbonPopupMenuControl : public Dxbar::TdxBarSubMenuControl
{
	typedef Dxbar::TdxBarSubMenuControl inherited;
	
protected:
	virtual Dxbar::TdxBarBehaviorOptions __fastcall GetBehaviorOptions(void);
public:
	/* TdxBarSubMenuControl.Create */ inline __fastcall virtual TdxRibbonPopupMenuControl(System::Classes::TComponent* AOwner) : Dxbar::TdxBarSubMenuControl(AOwner) { }
	/* TdxBarSubMenuControl.Destroy */ inline __fastcall virtual ~TdxRibbonPopupMenuControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonPopupMenuControl(HWND ParentWindow) : Dxbar::TdxBarSubMenuControl(ParentWindow) { }
	
};


class DELPHICLASS TdxBarApplicationMenu;
class PASCALIMPLEMENTATION TdxBarApplicationMenu : public Dxbarapplicationmenu::TdxBarCustomApplicationMenu
{
	typedef Dxbarapplicationmenu::TdxBarCustomApplicationMenu inherited;
	
private:
	bool FClosedByEscape;
	Dxbar::TdxBarPainter* FRibbonPainter;
	
protected:
	virtual void __fastcall DoCloseUp(void);
	virtual void __fastcall DoPopup(void);
	virtual Dxbar::TCustomdxBarControlClass __fastcall GetControlClass(void);
	bool __fastcall ApplicationMenuPopup(TdxCustomRibbon* ARibbon, bool &AClosedByEscape);
	bool __fastcall CanShowPopup(TdxCustomRibbon* ARibbon);
	bool __fastcall ClosePopup(void);
	TdxRibbonApplicationMenuDisplayMode __fastcall GetDisplayMode(void);
	System::Types::TPoint __fastcall GetOrigin(bool AIsClientArea);
	void __fastcall GetTabOrderList(System::Classes::TList* List);
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetRootAccessibilityHelper(void);
	void __fastcall RibbonFormResized(void);
	void __fastcall SelectAppMenuFirstItemControl(void);
	void __fastcall ShowKeyTips(void);
	void __fastcall UpdateColorScheme(void);
	void __fastcall UpdateNonClientArea(void);
	
public:
	virtual void __fastcall Popup(int X, int Y);
	
__published:
	__property BackgroundBitmap;
	__property BarManager;
	__property BarSize = {default=0};
	__property Buttons;
	__property ExtraPane;
	__property ExtraPaneEvents;
	__property Font;
	__property ItemLinks;
	__property ItemOptions;
	__property UseOwnFont;
	__property OnCloseUp;
	__property OnPaintBar;
	__property OnPopup;
	__property ExtraPaneWidthRatio = {stored=false, default=0};
	__property ExtraPaneSize = {stored=false};
	__property ExtraPaneItems = {stored=false};
	__property ExtraPaneHeader = {stored=false, default=0};
	__property OnExtraPaneItemClick = {stored=false};
public:
	/* TdxBarCustomApplicationMenu.Create */ inline __fastcall virtual TdxBarApplicationMenu(System::Classes::TComponent* AOwner) : Dxbarapplicationmenu::TdxBarCustomApplicationMenu(AOwner) { }
	/* TdxBarCustomApplicationMenu.Destroy */ inline __fastcall virtual ~TdxBarApplicationMenu(void) { }
	
private:
	void *__IdxRibbonApplicationMenu;	/* IdxRibbonApplicationMenu */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {DF34053B-F30D-4FC6-94D5-5863620E8F28}
	operator _di_IdxRibbonApplicationMenu()
	{
		_di_IdxRibbonApplicationMenu intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonApplicationMenu*(void) { return (IdxRibbonApplicationMenu*)&__IdxRibbonApplicationMenu; }
	#endif
	
};


class DELPHICLASS TdxRibbonApplicationMenuControl;
class PASCALIMPLEMENTATION TdxRibbonApplicationMenuControl : public Dxbarapplicationmenu::TdxBarApplicationMenuControl
{
	typedef Dxbarapplicationmenu::TdxBarApplicationMenuControl inherited;
	
private:
	TdxCustomRibbon* __fastcall GetRibbon(void);
	void __fastcall DoPopupMenuClick(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual Dxbar::TdxBarBehaviorOptions __fastcall GetBehaviorOptions(void);
	virtual void __fastcall InitCustomizationPopup(Dxbar::TdxBarItemLinks* AItemLinks);
	TdxRibbonPopupMenuItems __fastcall GetPopupMenuItems(void);
	void __fastcall PopupMenuClick(System::TObject* Sender);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
public:
	/* TdxBarApplicationMenuControl.Create */ inline __fastcall virtual TdxRibbonApplicationMenuControl(System::Classes::TComponent* AOwner) : Dxbarapplicationmenu::TdxBarApplicationMenuControl(AOwner) { }
	/* TdxBarApplicationMenuControl.Destroy */ inline __fastcall virtual ~TdxRibbonApplicationMenuControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonApplicationMenuControl(HWND ParentWindow) : Dxbarapplicationmenu::TdxBarApplicationMenuControl(ParentWindow) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TdxRibbonHitInfo* FHintInfo;
	TdxRibbonHitInfo* FHitInfo;
	TdxRibbonCustomButtonViewInfo* FHotButton;
	TdxRibbonHitTest FHotObject;
	TdxRibbonCustomButtonViewInfo* FPressedButton;
	TdxRibbonContext* FPressedContext;
	TdxRibbonHitTest FPressedObject;
	TdxCustomRibbon* FRibbon;
	TdxRibbonHitTest FScrollKind;
	Cxclasses::TcxTimer* FScrollTimer;
	bool FSkipDblClick;
	void __fastcall CancelScroll(void);
	bool __fastcall CanProcessDesignTime(void);
	void __fastcall CreateTimer(void);
	TdxRibbonApplicationButton* __fastcall GetApplicationButton(void);
	TdxRibbonApplicationButtonViewInfo* __fastcall GetApplicationButtonViewInfo(void);
	Dxribbonskins::TdxRibbonApplicationMenuState __fastcall GetApplicationMenuState(void);
	TdxRibbonViewInfo* __fastcall GetViewInfo(void);
	void __fastcall ScrollTimerHandler(System::TObject* Sender);
	void __fastcall SetHintInfo(TdxRibbonHitInfo* const Value);
	void __fastcall SetHotButton(TdxRibbonCustomButtonViewInfo* AValue);
	void __fastcall SetPressedButton(TdxRibbonCustomButtonViewInfo* AValue);
	void __fastcall SetPressedObject(const TdxRibbonHitTest Value);
	
protected:
	bool __fastcall DoHint(bool &ANeedDeactivate, /* out */ System::UnicodeString &AHintText, /* out */ System::UnicodeString &AShortCut);
	Dxbar::TdxBarCustomHintViewInfo* __fastcall CreateHintViewInfo(const System::UnicodeString AHintText, const System::UnicodeString AShortCut);
	bool __fastcall GetEnabled(void);
	System::Types::TPoint __fastcall GetHintPosition(const System::Types::TPoint &ACursorPos, int AHeight);
	void __fastcall CancelHint(void);
	virtual void __fastcall CancelMode(void);
	virtual bool __fastcall CanSwitchMinimizedOnDblClick(void);
	bool __fastcall CloseApplicationMenu(void);
	void __fastcall DesignTabMenuClick(System::TObject* Sender);
	void __fastcall DoScroll(bool AOnTimer);
	virtual void __fastcall HideHint(void);
	virtual void __fastcall InitTabDesignMenu(Dxbar::TdxBarItemLinks* AItemLinks);
	bool __fastcall IsApplicationMenuDropped(void);
	virtual bool __fastcall IsNeedShowHint(TdxRibbonHitTest AObject);
	virtual bool __fastcall IsOwnerForHintObject(TdxRibbonHitTest AObject);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall MouseWheelDown(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	virtual bool __fastcall MouseWheelUp(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	virtual bool __fastcall NotHandleMouseMove(const System::Types::TPoint &P);
	bool __fastcall ProcessApplicationButtonMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState AShift);
	void __fastcall ProcessContextsOnMouseDown(bool AIsDoubleClick);
	void __fastcall ProcessTabClick(TdxRibbonTab* ATab, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift);
	void __fastcall ProcessTabOnMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	void __fastcall ScrollGroups(bool AScrollLeft, bool AOnTimer);
	void __fastcall ScrollTabs(bool AScrollLeft, bool AOnTimer);
	virtual void __fastcall ShowTabDesignMenu(void);
	void __fastcall StartScroll(TdxRibbonHitTest AScrollKind);
	virtual void __fastcall UpdateButtonsStates(void);
	__property TdxRibbonHitInfo* HintInfo = {read=FHintInfo, write=SetHintInfo};
	__property TdxRibbonHitInfo* HitInfo = {read=FHitInfo};
	__property TdxRibbonHitTest HotObject = {read=FHotObject, write=FHotObject, nodefault};
	__property TdxRibbonHitTest PressedObject = {read=FPressedObject, write=SetPressedObject, nodefault};
	
public:
	__fastcall virtual TdxRibbonController(TdxCustomRibbon* ARibbon);
	__fastcall virtual ~TdxRibbonController(void);
	TdxRibbonTab* __fastcall NextTab(TdxRibbonTab* ATab);
	TdxRibbonTab* __fastcall PrevTab(TdxRibbonTab* ATab);
	__property TdxRibbonApplicationButton* ApplicationButton = {read=GetApplicationButton};
	__property TdxRibbonApplicationButtonViewInfo* ApplicationButtonViewInfo = {read=GetApplicationButtonViewInfo};
	__property Dxribbonskins::TdxRibbonApplicationMenuState ApplicationMenuState = {read=GetApplicationMenuState, nodefault};
	__property TdxRibbonCustomButtonViewInfo* HotButton = {read=FHotButton, write=SetHotButton};
	__property TdxRibbonCustomButtonViewInfo* PressedButton = {read=FPressedButton, write=SetPressedButton};
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
	__property TdxRibbonHitTest ScrollKind = {read=FScrollKind, nodefault};
	__property TdxRibbonViewInfo* ViewInfo = {read=GetViewInfo};
private:
	void *__IdxBarHintKeeper;	/* Dxbar::IdxBarHintKeeper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {587A00C4-A7E0-4032-98E5-4DB8F3918ADF}
	operator Dxbar::_di_IdxBarHintKeeper()
	{
		Dxbar::_di_IdxBarHintKeeper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarHintKeeper*(void) { return (Dxbar::IdxBarHintKeeper*)&__IdxBarHintKeeper; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGroupsDockControlScrollButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGroupsDockControlScrollButtonViewInfo : public TdxRibbonCustomScrollButtonViewInfo
{
	typedef TdxRibbonCustomScrollButtonViewInfo inherited;
	
protected:
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	
public:
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall GetHitInfo(TdxRibbonHitInfo* const AHitInfo);
public:
	/* TdxRibbonCustomButtonViewInfo.Create */ inline __fastcall virtual TdxRibbonGroupsDockControlScrollButtonViewInfo(TdxRibbonCustomContainerViewInfo* AOwner) : TdxRibbonCustomScrollButtonViewInfo(AOwner) { }
	/* TdxRibbonCustomButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonGroupsDockControlScrollButtonViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGroupsDockControlSiteViewInfo : public TdxRibbonButtonsContainerViewInfo
{
	typedef TdxRibbonButtonsContainerViewInfo inherited;
	
private:
	TdxRibbonMinimizeButtonViewInfo* FMinimizeRibbonButton;
	TdxRibbonGroupsDockControlSite* FSite;
	TdxRibbonGroupsDockControlScrollButtonViewInfo* FTabGroupsScrollButtonLeft;
	TdxRibbonGroupsDockControlScrollButtonViewInfo* FTabGroupsScrollButtonRight;
	TdxRibbonScrollButtons FTabGroupsScrollButtons;
	TdxRibbonTab* __fastcall GetRibbonActiveTab(void);
	TdxRibbonViewInfo* __fastcall GetRibbonViewInfo(void);
	
protected:
	virtual void __fastcall CalculateButtonsBounds(const System::Types::TRect &ABounds);
	void __fastcall DrawRibbonParts(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__fastcall virtual TdxRibbonGroupsDockControlSiteViewInfo(TdxRibbonGroupsDockControlSite* ASite);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall InvalidateRect(const System::Types::TRect &R);
	virtual System::Types::TSize __fastcall GetMinimizeRibbonButtonSize(void);
	__property TdxRibbonTab* RibbonActiveTab = {read=GetRibbonActiveTab};
	__property TdxRibbonViewInfo* RibbonViewInfo = {read=GetRibbonViewInfo};
	__property TdxRibbonScrollButtons TabGroupsScrollButtons = {read=FTabGroupsScrollButtons, nodefault};
	__property TdxRibbonGroupsDockControlScrollButtonViewInfo* TabGroupsScrollButtonLeft = {read=FTabGroupsScrollButtonLeft};
	__property TdxRibbonGroupsDockControlScrollButtonViewInfo* TabGroupsScrollButtonRight = {read=FTabGroupsScrollButtonRight};
public:
	/* TdxRibbonCustomContainerViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonGroupsDockControlSiteViewInfo(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxRibbonGroupsDockControlSite : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxCustomRibbon* FRibbon;
	TdxRibbonGroupsDockControlSiteViewInfo* FViewInfo;
	TdxRibbonGroupsDockControl* __fastcall GetDockControl(void);
	
protected:
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	virtual void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint &APoint);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoCancelMode(void);
	DYNAMIC bool __fastcall DoMouseWheelDown(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	DYNAMIC bool __fastcall MayFocus(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall Paint(void);
	void __fastcall SetRedraw(bool ARedraw);
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
	__property TdxRibbonGroupsDockControl* DockControl = {read=GetDockControl};
	__property TdxRibbonGroupsDockControlSiteViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall TdxRibbonGroupsDockControlSite(TdxCustomRibbon* ARibbon);
	__fastcall virtual ~TdxRibbonGroupsDockControlSite(void);
	DYNAMIC bool __fastcall CanFocus(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonGroupsDockControlSite(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonOptionsFading;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonOptionsFading : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Dxfading::TdxFadingOptions* FApplicationButton;
	Dxfading::TdxFadingOptions* FTabs;
	Dxfading::TdxFadingOptions* FTabGroups;
	Dxfading::TdxFadingOptions* FBarItems;
	void __fastcall SetApplicationButton(Dxfading::TdxFadingOptions* AValue);
	void __fastcall SetBarItems(Dxfading::TdxFadingOptions* AValue);
	void __fastcall SetTabGroups(Dxfading::TdxFadingOptions* AValue);
	void __fastcall SetTabs(Dxfading::TdxFadingOptions* AValue);
	
public:
	__fastcall virtual TdxRibbonOptionsFading(void);
	__fastcall virtual ~TdxRibbonOptionsFading(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Dxfading::TdxFadingOptions* ApplicationButton = {read=FApplicationButton, write=SetApplicationButton};
	__property Dxfading::TdxFadingOptions* BarItems = {read=FBarItems, write=SetBarItems};
	__property Dxfading::TdxFadingOptions* TabGroups = {read=FTabGroups, write=SetTabGroups};
	__property Dxfading::TdxFadingOptions* Tabs = {read=FTabs, write=SetTabs};
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonMergeData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonMergeData : public TdxRibbonCustomMergeData
{
	typedef TdxRibbonCustomMergeData inherited;
	
public:
	TdxRibbonTab* ActiveTabBeforeMerging;
	TdxCustomRibbon* MergedWith;
public:
	/* TdxRibbonCustomMergeData.Create */ inline __fastcall virtual TdxRibbonMergeData(void) : TdxRibbonCustomMergeData() { }
	/* TdxRibbonCustomMergeData.Destroy */ inline __fastcall virtual ~TdxRibbonMergeData(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTouchModeHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTouchModeHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomRibbon* FRibbon;
	
public:
	__fastcall TdxRibbonTouchModeHelper(TdxCustomRibbon* ARibbon);
	virtual void __fastcall AdjustFormBorderIconSize(Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, bool AIsToolWindow, System::Types::TSize &ASize);
	virtual void __fastcall AdjustFormCaptionHeight(int &AValue);
	virtual void __fastcall AdjustMargins(System::Types::TRect &AMargins, int AMaxTargetValue);
	virtual void __fastcall AdjustPartOffsets(int APart, System::Types::TRect &AValue);
	virtual void __fastcall AdjustPartSize(int APart, int &AValue);
	bool __fastcall IsEnabled(void);
	__property TdxCustomRibbon* Ribbon = {read=FRibbon};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonTouchModeHelper(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxRibbonEvent)(TdxCustomRibbon* Sender);

typedef void __fastcall (__closure *TdxRibbonApplicationMenuClickEvent)(TdxCustomRibbon* Sender, bool &AHandled);

typedef void __fastcall (__closure *TdxRibbonTabChangingEvent)(TdxCustomRibbon* Sender, TdxRibbonTab* ANewTab, bool &Allow);

typedef void __fastcall (__closure *TdxRibbonTabGroupNotifyEvent)(TdxCustomRibbon* Sender, TdxRibbonTab* ATab, TdxRibbonTabGroup* AGroup);

typedef void __fastcall (__closure *TdxRibbonHideMinimizedByClickEvent)(TdxCustomRibbon* Sender, HWND AWnd, System::Classes::TShiftState AShift, const System::Types::TPoint &APos, bool &AAllowProcessing);

enum TdxRibbonInternalState : unsigned char { risCreating, risAppMenuActive };

typedef System::Set<TdxRibbonInternalState, TdxRibbonInternalState::risCreating, TdxRibbonInternalState::risAppMenuActive>  TdxRibbonInternalStates;

class PASCALIMPLEMENTATION TdxCustomRibbon : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxRibbonTab* FActiveTab;
	TdxRibbonApplicationButton* FApplicationButton;
	Dxbar::TdxBarManager* FBarManager;
	Dxribbonskins::TdxCustomRibbonSkin* FColorScheme;
	Dxribbonskins::TdxRibbonColorSchemeAccent FColorSchemeAccent;
	Cxclasses::TcxEventHandlerCollection* FColorSchemeHandlers;
	TdxRibbonContexts* FContexts;
	TdxRibbonController* FController;
	Vcl::Controls::TCaption FDocumentName;
	bool FEnableTabAero;
	bool FFading;
	TdxRibbonFonts* FFonts;
	Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* FFormCaptionHelper;
	TdxRibbonGroupsDockControlSite* FGroupsDockControlSite;
	TdxRibbonBarPainter* FGroupsPainter;
	TdxRibbonHelpButton* FHelpButton;
	TdxRibbonTab* FHighlightedTab;
	System::Classes::TInterfaceList* FHorizontalNavigationList;
	System::Contnrs::TComponentList* FInternalItems;
	TdxRibbonInternalStates FInternalState;
	System::Classes::TInterfaceList* FListeners;
	TdxRibbonTab* FLoadedActiveTab;
	int FLoadedHeight;
	int FLockCount;
	bool FLockedCancelHint;
	bool FLockModified;
	TdxRibbonMergeData* FMergeData;
	bool FMinimizeOnTabDblClick;
	TdxRibbonOptionsFading* FOptionsFading;
	TdxRibbonPainter* FPainter;
	TdxRibbonPopupMenuItems FPopupMenuItems;
	TdxRibbonQuickAccessToolbar* FQuickAccessToolbar;
	System::Contnrs::TObjectList* FRibbonFormNonClientParts;
	bool FShowTabGroups;
	bool FShowTabHeaders;
	bool FSupportNonClientDrawing;
	TdxRibbonTabGroupsPopupWindow* FTabGroupsPopupWindow;
	TdxRibbonTabCollection* FTabs;
	bool FTabsLoaded;
	TdxRibbonTouchModeHelper* FTouchModeHelper;
	TdxRibbonViewInfo* FViewInfo;
	Dxbar::_di_IdxBarAccessibilityHelper FIAccessibilityHelper;
	System::Contnrs::TComponentList* FAffiliatedBarControlsForAccessibility;
	TdxRibbonApplicationMenuClickEvent FOnApplicationMenuClick;
	TdxRibbonEvent FOnHelpButtonClick;
	TdxRibbonHideMinimizedByClickEvent FOnHideMinimizedByClick;
	TdxRibbonEvent FOnMinimizedChanged;
	TdxRibbonEvent FOnMoreCommandsExecute;
	TdxRibbonEvent FOnTabChanged;
	TdxRibbonTabChangingEvent FOnTabChanging;
	TdxRibbonTabGroupNotifyEvent FOnTabGroupCollapsed;
	TdxRibbonTabGroupNotifyEvent FOnTabGroupExpanded;
	void __fastcall CheckDrawRibbonFormStatusBarBorders(Cxgraphics::TcxCanvas* ACanvas, const Dxribbonskins::TdxRibbonFormData &AData, const System::Types::TRect &ABordersWidth);
	void __fastcall DrawApplicationMenuHeader(NativeUInt ADC, bool AIsClientArea);
	TdxRibbonTab* __fastcall GetActiveTab(void);
	TdxRibbonApplicationButtonViewInfo* __fastcall GetApplicationButtonViewInfo(void);
	Dxribbonskins::TdxRibbonApplicationMenuState __fastcall GetApplicationMenuState(void);
	System::UnicodeString __fastcall GetColorSchemeName(void);
	Dxscreentip::TdxScreenTip* __fastcall GetHelpButtonScreenTip(void);
	bool __fastcall GetHidden(void);
	System::UnicodeString __fastcall GetIniSection(const System::UnicodeString ADelimiter, const System::UnicodeString ASection);
	bool __fastcall GetIsPopupGroupsMode(void);
	TdxRibbonTab* __fastcall GetNextActiveTab(TdxRibbonTab* ATab);
	Dxribbonform::TdxCustomRibbonForm* __fastcall GetRibbonForm(void);
	Dxribbonskins::TdxRibbonStyle __fastcall GetStyle(void);
	int __fastcall GetTabCount(void);
	TdxRibbonTab* __fastcall GetVisibleTab(int Index);
	int __fastcall GetVisibleTabCount(void);
	void __fastcall InitCustomizePopupMenu(Dxbar::TdxBarItemLinks* AItemLinks);
	void __fastcall InitColorScheme(void);
	bool __fastcall IsOnRibbonMDIForm(void);
	void __fastcall InternalCloseTabGroupsPopupWindow(bool AAllowAnimation = true);
	void __fastcall RibbonFormInvalidate(void);
	void __fastcall SetActiveTab(TdxRibbonTab* Value);
	void __fastcall SetOptionsFading(TdxRibbonOptionsFading* AValue);
	void __fastcall SetApplicationButton(TdxRibbonApplicationButton* AValue);
	void __fastcall SetBarManager(Dxbar::TdxBarManager* Value);
	void __fastcall SetColorScheme(Dxribbonskins::TdxCustomRibbonSkin* Value);
	void __fastcall SetColorSchemeAccent(Dxribbonskins::TdxRibbonColorSchemeAccent AValue);
	void __fastcall SetColorSchemeName(const System::UnicodeString Value);
	void __fastcall SetDocumentName(const Vcl::Controls::TCaption Value);
	void __fastcall SetEnableTabAero(bool AValue);
	void __fastcall SetFading(const bool Value);
	void __fastcall SetFonts(TdxRibbonFonts* const Value);
	void __fastcall SetHelpButton(TdxRibbonHelpButton* const Value);
	void __fastcall SetHelpButtonScreenTip(Dxscreentip::TdxScreenTip* const Value);
	void __fastcall SetHighlightedTab(TdxRibbonTab* const Value);
	void __fastcall SetPopupMenuItems(const TdxRibbonPopupMenuItems Value);
	void __fastcall SetQuickAccessToolbar(TdxRibbonQuickAccessToolbar* const Value);
	void __fastcall SetShowTabGroups(const bool Value);
	void __fastcall SetShowTabHeaders(const bool Value);
	void __fastcall SetStyle(Dxribbonskins::TdxRibbonStyle AValue);
	void __fastcall SetSupportNonClientDrawing(const bool Value);
	void __fastcall SetTabs(TdxRibbonTabCollection* Value);
	void __fastcall UpdateColorSchemeListeners(void);
	void __fastcall UpdateNonClientDrawing(void);
	MESSAGE void __fastcall CMSelectAppMenuFirstItemControl(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMShowKeyTips(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMShowApplicationMenu(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetObject(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	void __fastcall BarManagerAfterChange(void);
	void __fastcall BarManagerBeforeChange(void);
	void __fastcall BarManagerLoadIni(System::TObject* Sender, const void *AEventArgs);
	void __fastcall BarManagerSaveIni(System::TObject* Sender, const void *AEventArgs);
	void __fastcall MDIStateChanged(System::TObject* Sender, const void *AEventArgs);
	void __fastcall SystemFontChanged(System::TObject* Sender, const void *AEventArgs);
	void __fastcall UpdateColorScheme(void);
	void __fastcall SetContexts(TdxRibbonContexts* const Value);
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetIAccessibilityHelper(void);
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetQATIAccessibilityHelper(void);
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetTabsIAccessibilityHelper(void);
	
protected:
	virtual int __fastcall CalculateFormCaptionHeight(bool AIsQATAtNonClientArea);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint &APoint);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall AdjustRibbonFormBorderIconSize(Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, bool AIsToolWindow, System::Types::TSize &ASize);
	void __fastcall DrawRibbonFormBackground(HDC DC, const System::Types::TRect &ARect);
	void __fastcall DrawRibbonFormCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString ACaption, const Dxribbonskins::TdxRibbonFormData &AData);
	void __fastcall DrawRibbonFormBorderIcon(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, Dxribbonskins::TdxRibbonBorderIconState AState);
	void __fastcall DrawRibbonFormBorders(Cxgraphics::TcxCanvas* ACanvas, const Dxribbonskins::TdxRibbonFormData &AData, const System::Types::TRect &ABordersWidth);
	void __fastcall GetApplicationMenuTabOrderList(System::Classes::TList* List);
	Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	Dxbar::TdxBarPainter* __fastcall GetBarPainter(void);
	virtual int __fastcall GetRibbonFormCaptionAreaExtention(void);
	virtual int __fastcall GetRibbonFormCaptionHeight(void);
	virtual int __fastcall GetRibbonFormCaptionHeightForHiddenRibbon(void);
	System::Uitypes::TColor __fastcall GetRibbonFormColor(void);
	virtual HRGN __fastcall GetRibbonFormExtendedCaptionAreaRegion(void);
	int __fastcall GetRibbonLoadedHeight(void);
	HRGN __fastcall GetRibbonNonClientAreaObjectsRegion(void);
	System::Types::TRect __fastcall GetRibbonQATNonClientAreaBounds(void);
	Dxribbonskins::TdxRibbonStyle __fastcall GetRibbonStyle(void);
	System::_di_IInterface __fastcall GetStatusBarInterface(void);
	virtual Vcl::Controls::TCaption __fastcall GetTaskbarCaption(void);
	virtual TdxRibbonPopupMenuItems __fastcall GetValidPopupMenuItems(void);
	System::Types::TRect __fastcall GetWindowBordersWidth(void);
	bool __fastcall HasExternalRibbonFormShadow(void);
	bool __fastcall HasHelpButton(void);
	bool __fastcall HasStatusBar(void);
	virtual void __fastcall UpdateNonClientArea(void);
	bool __fastcall UseRoundedWindowCorners(void);
	virtual void __fastcall RibbonFormCaptionChanged(void);
	virtual void __fastcall RibbonFormResized(void);
	void __fastcall DrawTabGroupBackground(HDC DC, const System::Types::TRect &ARect, int AState, bool AIsInPopup);
	Dxfading::TdxFadingOptions* __fastcall GetBarItemControlFadingOptions(void);
	int __fastcall GetGroupCaptionHeight(void);
	int __fastcall GetGroupContentHeight(void);
	int __fastcall GetGroupHeight(void);
	int __fastcall GetGroupRowHeight(void);
	void __fastcall SkinDrawBackground(HDC DC, const System::Types::TRect &ARect, int APart, int AState);
	void __fastcall SkinDrawBackgroundEx(HDC DC, const System::Types::TRect &ARect, const System::Types::TRect &AContentRect, int APart, int AState = 0x0);
	void __fastcall SkinDrawCaption(HDC DC, const System::UnicodeString ACaption, const System::Types::TRect &ARect, int APart, int AState);
	System::Types::TRect __fastcall SkinGetCaptionRect(const System::Types::TRect &ARect, int APart);
	System::Types::TRect __fastcall SkinGetContentOffsets(int APart);
	bool __fastcall SkinGetIsAlphaUsed(int APart);
	System::UnicodeString __fastcall SkinGetName(void);
	System::Uitypes::TColor __fastcall SkinGetPartColor(int APart, int AState = 0x0);
	int __fastcall SkinGetPartSize(int APart);
	bool __fastcall CanProcessMouseWheel(void);
	void __fastcall FormKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetAccessibilityHelper(void);
	void __fastcall ProcessMergeOperation(Dxbar::TdxBarManager* ABarManager, Dxbar::TdxBarMergeOperation AOperation, bool &AHandled);
	void __fastcall RibbonFormNonClientDrawAdd(System::TObject* AObject);
	void __fastcall RibbonFormNonClientDrawRemove(System::TObject* AObject);
	void __fastcall AfterApplicationMenuPopup(void);
	void __fastcall BeforeApplicationMenuPopup(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	bool __fastcall CanScrollTabs(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoCancelMode(void);
	virtual void __fastcall DoMinimizeChanged(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall DoContextPopup(const System::Types::TPoint &MousePos, bool &Handled);
	DYNAMIC bool __fastcall DoMouseWheelDown(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC bool __fastcall MayFocus(void);
	virtual void __fastcall Modified(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall SetName(const System::Classes::TComponentName Value);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	DYNAMIC void __fastcall VisibleChanged(void);
	DYNAMIC void __fastcall Updating(void);
	DYNAMIC void __fastcall Updated(void);
	virtual TdxRibbonContext* __fastcall CreateContextAsByMerging(TdxRibbonContext* ASourceContext);
	virtual TdxRibbonTab* __fastcall CreateTabAsByMerging(TdxRibbonTab* ASourceTab);
	virtual Dxbar::TdxBar* __fastcall CreateToolbarAsByMerging(void);
	virtual void __fastcall UnmergeBeforeDestroy(void);
	TdxRibbonQuickAccessGroupButton* __fastcall AddGroupButtonToQAT(Dxbar::TdxBar* ABar);
	void __fastcall CancelUpdate(void);
	bool __fastcall CanFade(void);
	bool __fastcall CanPaint(void);
	virtual TdxRibbonApplicationButton* __fastcall CreateApplicationButton(void);
	virtual TdxRibbonController* __fastcall CreateController(void);
	virtual Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* __fastcall CreateFormCaptionHelper(void);
	virtual TdxRibbonBarPainter* __fastcall CreateGroupsPainter(void);
	virtual TdxRibbonHelpButton* __fastcall CreateHelpButton(void);
	virtual TdxRibbonPainter* __fastcall CreatePainter(void);
	virtual TdxRibbonQuickAccessToolbar* __fastcall CreateQuickAccessToolbar(void);
	virtual TdxRibbonTouchModeHelper* __fastcall CreateTouchModeHelper(void);
	virtual TdxRibbonViewInfo* __fastcall CreateViewInfo(void);
	void __fastcall DesignAddTabGroup(TdxRibbonTab* ATab, bool ANewToolbar);
	bool __fastcall DoApplicationMenuClick(void);
	virtual void __fastcall DoHelpButtonClick(void);
	virtual bool __fastcall DoHideMinimizedByClick(HWND AWnd, System::Classes::TShiftState AShift, const System::Types::TPoint &APos);
	virtual bool __fastcall DoTabChanging(TdxRibbonTab* ANewTab);
	virtual void __fastcall DoMoreCommandsExecute(void);
	virtual void __fastcall DoTabChanged(void);
	virtual void __fastcall DoTabGroupCollapsed(TdxRibbonTab* ATab, TdxRibbonTabGroup* AGroup);
	virtual void __fastcall DoTabGroupExpanded(TdxRibbonTab* ATab, TdxRibbonTabGroup* AGroup);
	Dxbar::TdxBar* __fastcall GetBar(Dxbar::TCustomdxBarControl* ACustomizingBarControl);
	Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextHorizontalAccessibleObject(Dxbar::_di_IdxBarAccessibilityHelper ACurrentObject, Cxaccessibility::TcxAccessibilityNavigationDirection ADirection);
	virtual TdxRibbonTabClass __fastcall GetTabClass(void);
	bool __fastcall IsAutoHidden(void);
	bool __fastcall IsAutoHideModeActive(void);
	bool __fastcall IsBarManagerValid(void);
	bool __fastcall IsHelpButtonPlacedOnTabsArea(void);
	bool __fastcall IsLocked(void);
	bool __fastcall IsQuickAccessToolbarValid(void);
	void __fastcall InitializeRibbonForm(void);
	void __fastcall PopulatePopupMenuItems(Dxbar::TdxBarItemLinks* ALinks, TdxRibbonPopupMenuItems AItems, System::Classes::TNotifyEvent AOnClick);
	void __fastcall PopupMenuItemClick(System::TObject* Sender);
	void __fastcall UpdateFormActionControl(bool ASetControl);
	void __fastcall SetRedraw(bool ARedraw);
	virtual void __fastcall ShowCustomizePopup(void);
	void __fastcall UpdateActiveTab(void);
	void __fastcall UpdateControlsVisibility(void);
	void __fastcall UpdateHorizontalNavigationList(void);
	virtual void __fastcall UpdateHeight(void);
	void __fastcall UpdateHiddenActiveTabDockControl(void);
	void __fastcall AddTab(TdxRibbonTab* ATab);
	void __fastcall RemoveTab(TdxRibbonTab* ATab);
	void __fastcall SetNextActiveTab(TdxRibbonTab* ATab);
	HIDESBASE void __fastcall Changed(void);
	void __fastcall FullInvalidate(void);
	void __fastcall RecalculateBars(void);
	void __fastcall AddAffiliatedBarControlForAccessibility(Dxbar::TCustomdxBarControl* ABarControl);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	__property Dxbar::_di_IdxBarAccessibilityHelper QATIAccessibilityHelper = {read=GetQATIAccessibilityHelper};
	__property Dxbar::_di_IdxBarAccessibilityHelper TabsIAccessibilityHelper = {read=GetTabsIAccessibilityHelper};
	__property TdxRibbonApplicationButtonViewInfo* ApplicationButtonViewInfo = {read=GetApplicationButtonViewInfo};
	__property Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* FormCaptionHelper = {read=FFormCaptionHelper};
	__property TdxRibbonBarPainter* GroupsPainter = {read=FGroupsPainter};
	__property TdxRibbonTab* HighlightedTab = {read=FHighlightedTab, write=SetHighlightedTab};
	__property System::Classes::TInterfaceList* HorizontalNavigationList = {read=FHorizontalNavigationList};
	__property bool LockedCancelHint = {read=FLockedCancelHint, write=FLockedCancelHint, nodefault};
	__property System::Contnrs::TObjectList* RibbonFormNonClientParts = {read=FRibbonFormNonClientParts};
	__property TdxRibbonTabGroupsPopupWindow* TabGroupsPopupWindow = {read=FTabGroupsPopupWindow};
	__property Dxribbonskins::TdxRibbonApplicationMenuState ApplicationMenuState = {read=GetApplicationMenuState, nodefault};
	__property TdxRibbonController* Controller = {read=FController};
	__property bool Fading = {read=FFading, write=SetFading, default=0};
	__property TdxRibbonGroupsDockControlSite* GroupsDockControlSite = {read=FGroupsDockControlSite};
	__property TdxRibbonInternalStates InternalState = {read=FInternalState, nodefault};
	__property TdxRibbonMergeData* MergeData = {read=FMergeData};
	__property TdxRibbonPainter* Painter = {read=FPainter};
	__property Dxribbonform::TdxCustomRibbonForm* RibbonForm = {read=GetRibbonForm};
	__property TdxRibbonTouchModeHelper* TouchModeHelper = {read=FTouchModeHelper};
	
public:
	__fastcall virtual TdxCustomRibbon(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomRibbon(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
	bool __fastcall ApplicationMenuPopup(void);
	bool __fastcall AreGroupsVisible(void);
	void __fastcall BeginUpdate(void);
	DYNAMIC bool __fastcall CanFocus(void);
	void __fastcall CheckHide(void);
	bool __fastcall ContainsToolBar(Dxbar::TdxBar* AToolBar);
	void __fastcall EndUpdate(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	TdxRibbonTab* __fastcall GetTabAtPos(int X, int Y);
	void __fastcall CloseTabGroupsPopupWindow(void);
	void __fastcall ShowTabGroupsPopupWindow(void);
	void __fastcall AddListener(_di_IdxRibbonListener AListener);
	void __fastcall RemoveListener(_di_IdxRibbonListener AListener);
	virtual bool __fastcall IsMerged(void);
	virtual void __fastcall Merge(TdxCustomRibbon* ARibbon, TdxRibbonMergeOptions AMergeOptions = (TdxRibbonMergeOptions() << TdxRibbonMergeOption::rmoCanCreateNewTab << TdxRibbonMergeOption::rmoCanCreateNewGroup << TdxRibbonMergeOption::rmoCanCreateQATToolbar ));
	virtual void __fastcall Unmerge(TdxCustomRibbon* ARibbon = (TdxCustomRibbon*)(0x0));
	__property TdxRibbonTab* ActiveTab = {read=GetActiveTab, write=SetActiveTab};
	__property TdxRibbonApplicationButton* ApplicationButton = {read=FApplicationButton, write=SetApplicationButton};
	__property Dxbar::TdxBarManager* BarManager = {read=FBarManager, write=SetBarManager};
	__property Dxribbonskins::TdxCustomRibbonSkin* ColorScheme = {read=FColorScheme, write=SetColorScheme};
	__property Dxribbonskins::TdxRibbonColorSchemeAccent ColorSchemeAccent = {read=FColorSchemeAccent, write=SetColorSchemeAccent, default=0};
	__property Cxclasses::TcxEventHandlerCollection* ColorSchemeHandlers = {read=FColorSchemeHandlers};
	__property System::UnicodeString ColorSchemeName = {read=GetColorSchemeName, write=SetColorSchemeName, stored=true};
	__property Vcl::Controls::TCaption DocumentName = {read=FDocumentName, write=SetDocumentName};
	__property bool EnableTabAero = {read=FEnableTabAero, write=SetEnableTabAero, default=1};
	__property TdxRibbonFonts* Fonts = {read=FFonts, write=SetFonts};
	__property TdxRibbonHelpButton* HelpButton = {read=FHelpButton, write=SetHelpButton};
	__property bool Hidden = {read=GetHidden, nodefault};
	__property Dxbar::_di_IdxBarAccessibilityHelper IAccessibilityHelper = {read=GetIAccessibilityHelper};
	__property bool IsPopupGroupsMode = {read=GetIsPopupGroupsMode, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	__property bool MinimizeOnTabDblClick = {read=FMinimizeOnTabDblClick, write=FMinimizeOnTabDblClick, default=1};
	__property TdxRibbonOptionsFading* OptionsFading = {read=FOptionsFading, write=SetOptionsFading};
	__property TdxRibbonQuickAccessToolbar* QuickAccessToolbar = {read=FQuickAccessToolbar, write=SetQuickAccessToolbar};
	__property TdxRibbonPopupMenuItems PopupMenuItems = {read=FPopupMenuItems, write=SetPopupMenuItems, default=31};
	__property TdxRibbonContexts* Contexts = {read=FContexts, write=SetContexts};
	__property bool ShowTabGroups = {read=FShowTabGroups, write=SetShowTabGroups, default=1};
	__property bool ShowTabHeaders = {read=FShowTabHeaders, write=SetShowTabHeaders, default=1};
	__property Dxribbonskins::TdxRibbonStyle Style = {read=GetStyle, write=SetStyle, default=0};
	__property bool SupportNonClientDrawing = {read=FSupportNonClientDrawing, write=SetSupportNonClientDrawing, default=0};
	__property int TabCount = {read=GetTabCount, nodefault};
	__property TdxRibbonTabCollection* Tabs = {read=FTabs, write=SetTabs};
	__property TdxRibbonViewInfo* ViewInfo = {read=FViewInfo};
	__property int VisibleTabCount = {read=GetVisibleTabCount, nodefault};
	__property TdxRibbonTab* VisibleTabs[int Index] = {read=GetVisibleTab};
	__property Dxscreentip::TdxScreenTip* HelpButtonScreenTip = {read=GetHelpButtonScreenTip, write=SetHelpButtonScreenTip};
	__property TdxRibbonApplicationMenuClickEvent OnApplicationMenuClick = {read=FOnApplicationMenuClick, write=FOnApplicationMenuClick};
	__property TdxRibbonEvent OnHelpButtonClick = {read=FOnHelpButtonClick, write=FOnHelpButtonClick};
	__property TdxRibbonHideMinimizedByClickEvent OnHideMinimizedByClick = {read=FOnHideMinimizedByClick, write=FOnHideMinimizedByClick};
	__property TdxRibbonEvent OnMinimizedChanged = {read=FOnMinimizedChanged, write=FOnMinimizedChanged};
	__property TdxRibbonEvent OnMoreCommandsExecute = {read=FOnMoreCommandsExecute, write=FOnMoreCommandsExecute};
	__property TdxRibbonEvent OnTabChanged = {read=FOnTabChanged, write=FOnTabChanged};
	__property TdxRibbonTabChangingEvent OnTabChanging = {read=FOnTabChanging, write=FOnTabChanging};
	__property TdxRibbonTabGroupNotifyEvent OnTabGroupCollapsed = {read=FOnTabGroupCollapsed, write=FOnTabGroupCollapsed};
	__property TdxRibbonTabGroupNotifyEvent OnTabGroupExpanded = {read=FOnTabGroupExpanded, write=FOnTabGroupExpanded};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomRibbon(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxBarAccessibleObject;	/* Dxbar::IdxBarAccessibleObject */
	void *__IdxBarManagerMergeOperationHandler;	/* Dxbar::IdxBarManagerMergeOperationHandler */
	void *__IdxFormKeyPreviewListener;	/* Dxribbonformcaptionhelper::IdxFormKeyPreviewListener */
	void *__IdxRibbonMouseWheelReceiver;	/* IdxRibbonMouseWheelReceiver */
	void *__IdxRibbonFormNonClientDraw;	/* IdxRibbonFormNonClientDraw */
	void *__IdxRibbonFormNonClientHelper;	/* Dxribbonformcaptionhelper::IdxRibbonFormNonClientHelper */
	void *__IdxRibbonFormNonClientPart;	/* Dxribbonformcaptionhelper::IdxRibbonFormNonClientPart */
	void *__IdxRibbonFormClient;	/* Dxribbonform::IdxRibbonFormClient */
	void *__IdxSkin;	/* Dxbar::IdxSkin */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6411B5B8-FFF8-42BD-BFD4-0B53151C97DC}
	operator Dxbar::_di_IdxBarAccessibleObject()
	{
		Dxbar::_di_IdxBarAccessibleObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarAccessibleObject*(void) { return (Dxbar::IdxBarAccessibleObject*)&__IdxBarAccessibleObject; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B4B24468-7933-4935-B025-F7D4F21541CF}
	operator Dxbar::_di_IdxBarManagerMergeOperationHandler()
	{
		Dxbar::_di_IdxBarManagerMergeOperationHandler intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarManagerMergeOperationHandler*(void) { return (Dxbar::IdxBarManagerMergeOperationHandler*)&__IdxBarManagerMergeOperationHandler; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7192BF84-F80D-4DB0-A53B-06F6703B1A97}
	operator Dxribbonformcaptionhelper::_di_IdxFormKeyPreviewListener()
	{
		Dxribbonformcaptionhelper::_di_IdxFormKeyPreviewListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbonformcaptionhelper::IdxFormKeyPreviewListener*(void) { return (Dxribbonformcaptionhelper::IdxFormKeyPreviewListener*)&__IdxFormKeyPreviewListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A5D2167B-0343-4525-915F-D41B49832045}
	operator _di_IdxRibbonMouseWheelReceiver()
	{
		_di_IdxRibbonMouseWheelReceiver intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonMouseWheelReceiver*(void) { return (IdxRibbonMouseWheelReceiver*)&__IdxRibbonMouseWheelReceiver; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0A28260B-C352-4704-A88B-44DD8461955C}
	operator _di_IdxRibbonFormNonClientDraw()
	{
		_di_IdxRibbonFormNonClientDraw intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonFormNonClientDraw*(void) { return (IdxRibbonFormNonClientDraw*)&__IdxRibbonFormNonClientDraw; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2F024903-3552-4859-961F-F778ED5E1DB6}
	operator Dxribbonformcaptionhelper::_di_IdxRibbonFormNonClientHelper()
	{
		Dxribbonformcaptionhelper::_di_IdxRibbonFormNonClientHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbonformcaptionhelper::IdxRibbonFormNonClientHelper*(void) { return (Dxribbonformcaptionhelper::IdxRibbonFormNonClientHelper*)&__IdxRibbonFormNonClientHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9266F6BD-0C9A-402A-A49F-D6405A2DDAF0}
	operator Dxribbonformcaptionhelper::_di_IdxRibbonFormNonClientPart()
	{
		Dxribbonformcaptionhelper::_di_IdxRibbonFormNonClientPart intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbonformcaptionhelper::IdxRibbonFormNonClientPart*(void) { return (Dxribbonformcaptionhelper::IdxRibbonFormNonClientPart*)&__IdxRibbonFormNonClientPart; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C409C9EF-4458-4133-AAA1-DCDCBFBC0B83}
	operator Dxribbonform::_di_IdxRibbonFormClient()
	{
		Dxribbonform::_di_IdxRibbonFormClient intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbonform::IdxRibbonFormClient*(void) { return (Dxribbonform::IdxRibbonFormClient*)&__IdxRibbonFormClient; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {ABCD2B3A-5F77-45A1-ADE2-3C028D4DB64C}
	operator Dxbar::_di_IdxSkin()
	{
		Dxbar::_di_IdxSkin intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxSkin*(void) { return (Dxbar::IdxSkin*)&__IdxSkin; }
	#endif
	
};


class DELPHICLASS TdxRibbon;
class PASCALIMPLEMENTATION TdxRibbon : public TdxCustomRibbon
{
	typedef TdxCustomRibbon inherited;
	
__published:
	__property HelpButtonScreenTip;
	__property OptionsFading;
	__property ApplicationButton;
	__property BarManager;
	__property Style = {default=0};
	__property ColorSchemeAccent = {default=0};
	__property ColorSchemeName = {default=0};
	__property DocumentName = {default=0};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property EnableTabAero = {default=1};
	__property Fonts;
	__property HelpButton;
	__property MinimizeOnTabDblClick = {default=1};
	__property PopupMenuItems = {default=31};
	__property QuickAccessToolbar;
	__property ShowTabGroups = {default=1};
	__property ShowTabHeaders = {default=1};
	__property SupportNonClientDrawing = {default=0};
	__property Contexts;
	__property Tabs;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property OnApplicationMenuClick;
	__property OnHelpButtonClick;
	__property OnHideMinimizedByClick;
	__property OnMinimizedChanged;
	__property OnMoreCommandsExecute;
	__property OnTabChanged;
	__property OnTabChanging;
	__property OnTabGroupCollapsed;
	__property OnTabGroupExpanded;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TdxCustomRibbon.Create */ inline __fastcall virtual TdxRibbon(System::Classes::TComponent* AOwner) : TdxCustomRibbon(AOwner) { }
	/* TdxCustomRibbon.Destroy */ inline __fastcall virtual ~TdxRibbon(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbon(HWND ParentWindow) : TdxCustomRibbon(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonQuickAccessToolbarHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessToolbarHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall HasGroupButtonForToolbar(Dxbar::TdxBarItemLinks* AQATLinks, Dxbar::TdxBar* AToolbar);
	__classmethod bool __fastcall IsToolbarDockedInRibbon(TdxCustomRibbon* ARibbon, Dxbar::TdxBar* AToolbar);
public:
	/* TObject.Create */ inline __fastcall TdxRibbonQuickAccessToolbarHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessToolbarHelper(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxRibbonQuickAccessGroupButton : public Dxbar::TdxBarItem
{
	typedef Dxbar::TdxBarItem inherited;
	
private:
	Dxbar::TdxBar* FToolbar;
	Dxbar::TdxBar* __fastcall GetActualToolbar(void);
	void __fastcall SetToolbar(Dxbar::TdxBar* Value);
	
protected:
	virtual bool __fastcall CanBePlacedOn(Dxbar::TdxBarItemControlParentKind AParentKind, Dxbar::TdxBar* AToolbar, /* out */ System::UnicodeString &AErrorText);
	virtual System::UnicodeString __fastcall GetCaption(void);
	bool __fastcall HasGroupButtonForToolbar(Dxbar::TdxBar* AParentBar, Dxbar::TdxBar* AToolbar);
	virtual bool __fastcall IsCaptionStored(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetCaption(const System::UnicodeString Value);
	__property Dxbar::TdxBar* ActualToolbar = {read=GetActualToolbar};
	
public:
	bool __fastcall IsToolbarAcceptable(Dxbar::TdxBar* AToolbar);
	
__published:
	__property Dxbar::TdxBar* Toolbar = {read=FToolbar, write=SetToolbar};
public:
	/* TdxBarItem.Create */ inline __fastcall virtual TdxRibbonQuickAccessGroupButton(System::Classes::TComponent* AOwner) : Dxbar::TdxBarItem(AOwner) { }
	/* TdxBarItem.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessGroupButton(void) { }
	
};


class DELPHICLASS TdxRibbonQuickAccessGroupButtonControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessGroupButtonControl : public Dxbar::TdxBarButtonLikeControl
{
	typedef Dxbar::TdxBarButtonLikeControl inherited;
	
private:
	Dxbar::TdxBarPopupControl* FPopupBarControl;
	HIDESBASE TdxRibbonQuickAccessGroupButton* __fastcall GetItem(void);
	
protected:
	virtual void __fastcall CalcDrawParams(bool AFull = true);
	virtual bool __fastcall CanActivate(void);
	virtual bool __fastcall CanDestroyOnClick(void);
	void __fastcall ClosePopup(void);
	virtual void __fastcall ControlClick(bool AByMouse, System::WideChar AKey = (System::WideChar)(0x0));
	DYNAMIC void __fastcall DoCloseUp(bool AHadSubMenuControl);
	DYNAMIC void __fastcall DoDropDown(bool AByMouse);
	virtual void __fastcall DoPaint(const System::Types::TRect &ARect, Dxbar::TdxBarPaintType PaintType);
	virtual void __fastcall DropDown(bool AByMouse);
	virtual Dxbar::TdxBarAccessibilityHelperClass __fastcall GetAccessibilityHelperClass(void);
	virtual bool __fastcall GetCurrentImage(Dxbar::TdxBarItemControlViewSize AViewSize, bool ASelected, /* out */ Vcl::Graphics::TBitmap* &ACurrentGlyph, /* out */ Vcl::Imglist::TCustomImageList* &ACurrentImages, /* out */ int &ACurrentImageIndex);
	virtual System::UnicodeString __fastcall GetHint(void);
	virtual Dxbar::TdxBarItemControlViewStructure __fastcall GetViewStructure(void);
	virtual bool __fastcall IsDropDown(void);
	
public:
	__fastcall virtual ~TdxRibbonQuickAccessGroupButtonControl(void);
	virtual bool __fastcall IsDroppedDown(void);
	__property TdxRibbonQuickAccessGroupButton* Item = {read=GetItem};
public:
	/* TdxBarItemControl.Create */ inline __fastcall virtual TdxRibbonQuickAccessGroupButtonControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TdxBarButtonLikeControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessGroupButtonPopupBarControl;
class PASCALIMPLEMENTATION TdxRibbonQuickAccessGroupButtonPopupBarControl : public TdxRibbonCollapsedGroupPopupBarControl
{
	typedef TdxRibbonCollapsedGroupPopupBarControl inherited;
	
private:
	TdxRibbonQuickAccessGroupButtonControl* FGroupButtonControl;
	bool FIsActiveChangeLocked;
	
protected:
	virtual bool __fastcall CanActiveChange(void);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall FocusItemControl(Dxbar::TdxBarItemControl* AItemControl);
	virtual Dxbar::TdxBarBehaviorOptions __fastcall GetBehaviorOptions(void);
	virtual bool __fastcall IsAllowContextPaint(void);
	
public:
	__fastcall virtual TdxRibbonQuickAccessGroupButtonPopupBarControl(TdxRibbonQuickAccessGroupButtonControl* AGroupButtonControl);
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall HideAllByEscape(void);
public:
	/* TdxRibbonCollapsedGroupPopupBarControl.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessGroupButtonPopupBarControl(void) { }
	
public:
	/* TdxBarPopupControl.Create */ inline __fastcall virtual TdxRibbonQuickAccessGroupButtonPopupBarControl(System::Classes::TComponent* AOwner) : TdxRibbonCollapsedGroupPopupBarControl(AOwner) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonQuickAccessGroupButtonPopupBarControl(HWND ParentWindow) : TdxRibbonCollapsedGroupPopupBarControl(ParentWindow) { }
	
};


class DELPHICLASS TdxAddGroupButtonEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAddGroupButtonEditor : public Dxbar::TdxAddSubItemEditor
{
	typedef Dxbar::TdxAddSubItemEditor inherited;
	
protected:
	__classmethod virtual Dxbar::TdxBarItemClass __fastcall GetAddedItemClass(const System::UnicodeString AAddedItemName);
	__classmethod virtual System::UnicodeString __fastcall GetPopupItemCaption();
public:
	/* TObject.Create */ inline __fastcall TdxAddGroupButtonEditor(void) : Dxbar::TdxAddSubItemEditor() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAddGroupButtonEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	System::Classes::TList* FAccessibilityChilds;
	Dxbar::_di_IdxBarKeyTipWindowsManager FKeyTipWindowsManager;
	TdxCustomRibbon* __fastcall GetRibbon(void);
	TdxRibbonButtonsContainerViewInfo* __fastcall GetTabsAreaButtonsViewInfo(void);
	
protected:
	virtual bool __fastcall AreKeyTipsSupported(/* out */ Dxbar::_di_IdxBarKeyTipWindowsManager &AKeyTipWindowsManager);
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetDefaultAccessibleObject(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Dxbar::TdxBarAccessibilityHelper* __fastcall LogicalNavigationGetChild(int AIndex);
	virtual int __fastcall LogicalNavigationGetChildIndex(Dxbar::TdxBarAccessibilityHelper* AChild);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property TdxRibbonButtonsContainerViewInfo* TabsAreaButtonsViewInfo = {read=GetTabsAreaButtonsViewInfo};
	
public:
	__fastcall virtual TdxRibbonAccessibilityHelper(System::TObject* AOwnerObject);
	__fastcall virtual ~TdxRibbonAccessibilityHelper(void);
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabCollectionAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabCollectionAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	TdxRibbonTabCollection* __fastcall GetTabCollection(void);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetDefaultAccessibleObject(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Dxbar::TdxBarAccessibilityHelper* __fastcall LogicalNavigationGetChild(int AIndex);
	virtual int __fastcall LogicalNavigationGetChildCount(void);
	virtual int __fastcall LogicalNavigationGetChildIndex(Dxbar::TdxBarAccessibilityHelper* AChild);
	__property TdxRibbonTabCollection* TabCollection = {read=GetTabCollection};
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonTabCollectionAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonTabCollectionAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonTabAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonTabAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	TdxCustomRibbon* __fastcall GetRibbon(void);
	TdxRibbonTab* __fastcall GetTab(void);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual bool __fastcall IsNavigationKey(System::Word AKey);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall LogicalNavigationGetNextAccessibleObject(System::Classes::TShiftState AShift);
	virtual void __fastcall Select(bool ASetFocus);
	virtual void __fastcall Unselect(Dxbar::_di_IdxBarAccessibilityHelper ANextSelectedObject);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual bool __fastcall GetSelectable(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetAssignedKeyTip(void);
	virtual System::UnicodeString __fastcall GetDefaultKeyTip(void);
	virtual void __fastcall GetKeyTipInfo(/* out */ Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual void __fastcall KeyTipHandler(System::TObject* Sender);
	virtual void __fastcall KeyTipsEscapeHandler(void);
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property TdxRibbonTab* Tab = {read=GetTab};
	
public:
	void __fastcall CloseUpHandler(Dxbar::TdxBarCloseUpReason AReason);
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonTabAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonTabAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonApplicationButtonAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonApplicationButtonAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	TdxRibbonApplicationButtonViewInfo* __fastcall GetApplicationButtonViewInfo(void);
	TdxCustomRibbon* __fastcall GetRibbon(void);
	void __fastcall ShowApplicationMenu(unsigned APostMessage);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual bool __fastcall IsNavigationKey(System::Word AKey);
	virtual void __fastcall Select(bool ASetFocus);
	virtual void __fastcall Unselect(Dxbar::_di_IdxBarAccessibilityHelper ANextSelectedObject);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual bool __fastcall GetSelectable(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetAssignedKeyTip(void);
	virtual System::UnicodeString __fastcall GetDefaultKeyTip(void);
	virtual void __fastcall GetKeyTipInfo(/* out */ Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual void __fastcall KeyTipHandler(System::TObject* Sender);
	__property TdxRibbonApplicationButtonViewInfo* ApplicationButtonViewInfo = {read=GetApplicationButtonViewInfo};
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonApplicationButtonAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonApplicationButtonAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGroupsDockControlAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGroupsDockControlAccessibilityHelper : public Dxbaraccessibility::TdxDockControlAccessibilityHelper
{
	typedef Dxbaraccessibility::TdxDockControlAccessibilityHelper inherited;
	
private:
	HIDESBASE TdxRibbonGroupsDockControl* __fastcall GetDockControl(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Dxbar::TdxBarAccessibilityHelper* __fastcall GetParentForKeyTip(void);
	__property TdxRibbonGroupsDockControl* DockControl = {read=GetDockControl};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonGroupsDockControlAccessibilityHelper(System::TObject* AOwnerObject) : Dxbaraccessibility::TdxDockControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonGroupsDockControlAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonBarControlAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonBarControlAccessibilityHelper : public Dxbaraccessibility::TdxBarControlAccessibilityHelper
{
	typedef Dxbaraccessibility::TdxBarControlAccessibilityHelper inherited;
	
protected:
	virtual Dxbar::TdxBarAccessibilityHelper* __fastcall LogicalNavigationGetNextChild(int AChildIndex, System::Classes::TShiftState AShift)/* overload */;
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonBarControlAccessibilityHelper(System::TObject* AOwnerObject) : Dxbaraccessibility::TdxBarControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonBarControlAccessibilityHelper(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline Dxbar::TdxBarAccessibilityHelper* __fastcall  LogicalNavigationGetNextChild(int AChildIndex, bool AGoForward){ return Dxbar::TdxBarAccessibilityHelper::LogicalNavigationGetNextChild(AChildIndex, AGoForward); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessBarControlAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessBarControlAccessibilityHelper : public TdxRibbonBarControlAccessibilityHelper
{
	typedef TdxRibbonBarControlAccessibilityHelper inherited;
	
private:
	HIDESBASE TdxRibbonQuickAccessBarControl* __fastcall GetBarControl(void);
	
protected:
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual void __fastcall DoGetKeyTipsData(System::Classes::TList* AKeyTipsData);
	virtual void __fastcall InitializeItemKeyTipPosition(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	virtual Dxbar::TdxBarAccessibilityHelper* __fastcall GetParentForKeyTip(void);
	virtual bool __fastcall IsKeyTipContainer(void);
	virtual void __fastcall KeyTipsEscapeHandler(void);
	__property TdxRibbonQuickAccessBarControl* BarControl = {read=GetBarControl};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonQuickAccessBarControlAccessibilityHelper(System::TObject* AOwnerObject) : TdxRibbonBarControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessBarControlAccessibilityHelper(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline Dxbar::_di_IdxBarAccessibilityHelper __fastcall  GetNextAccessibleObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection){ return Dxbar::TdxBarAccessibilityHelper::GetNextAccessibleObject(ADirection); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessBarControlMarkAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessBarControlMarkAccessibilityHelper : public Dxbaraccessibility::TdxBarControlMarkAccessibilityHelper
{
	typedef Dxbaraccessibility::TdxBarControlMarkAccessibilityHelper inherited;
	
private:
	HIDESBASE TdxRibbonQuickAccessBarControl* __fastcall GetBarControl(void);
	
protected:
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual void __fastcall GetKeyTipInfo(/* out */ Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual System::UnicodeString __fastcall GetKeyTip(void);
	virtual void __fastcall KeyTipHandler(System::TObject* Sender);
	__property TdxRibbonQuickAccessBarControl* BarControl = {read=GetBarControl};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonQuickAccessBarControlMarkAccessibilityHelper(System::TObject* AOwnerObject) : Dxbaraccessibility::TdxBarControlMarkAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessBarControlMarkAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonGroupBarControlAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonGroupBarControlAccessibilityHelper : public TdxRibbonBarControlAccessibilityHelper
{
	typedef TdxRibbonBarControlAccessibilityHelper inherited;
	
private:
	HIDESBASE TdxRibbonGroupBarControl* __fastcall GetBarControl(void);
	void __fastcall ShowPopupBarControl(void);
	
protected:
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual bool __fastcall IsNavigationKey(System::Word AKey);
	virtual void __fastcall Select(bool ASetFocus);
	virtual void __fastcall Unselect(Dxbar::_di_IdxBarAccessibilityHelper ANextSelectedObject);
	virtual bool __fastcall GetSelectable(void);
	virtual Dxbaraccessibility::TCustomdxBarControlAccessibilityHelper* __fastcall Expand(void);
	virtual void __fastcall GetCaptionButtonKeyTipPosition(Dxbar::TdxBarCaptionButton* ACaptionButton, /* out */ int &ABasePointY, /* out */ Cxclasses::TcxAlignmentVert &AVertAlign);
	virtual void __fastcall InitializeItemKeyTipPosition(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual System::UnicodeString __fastcall GetAssignedKeyTip(void);
	virtual System::UnicodeString __fastcall GetDefaultKeyTip(void);
	virtual void __fastcall GetKeyTipInfo(/* out */ Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual void __fastcall GetKeyTipData(System::Classes::TList* AKeyTipsData);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(Dxbaraccessibility::TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	virtual Dxbar::TdxBarAccessibilityHelper* __fastcall GetParentForKeyTip(void);
	virtual bool __fastcall IsCollapsed(void);
	virtual bool __fastcall IsKeyTipContainer(void);
	virtual void __fastcall KeyTipHandler(System::TObject* Sender);
	virtual void __fastcall KeyTipsEscapeHandler(void);
	__property TdxRibbonGroupBarControl* BarControl = {read=GetBarControl};
	
public:
	void __fastcall CloseUpHandler(Dxbar::TdxBarCloseUpReason AReason);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonGroupBarControlAccessibilityHelper(System::TObject* AOwnerObject) : TdxRibbonBarControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonGroupBarControlAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper : public Dxbaraccessibility::TdxBarButtonLikeControlAccessibilityHelper
{
	typedef Dxbaraccessibility::TdxBarButtonLikeControlAccessibilityHelper inherited;
	
protected:
	virtual bool __fastcall IsDropDownControl(void);
	virtual bool __fastcall ShowDropDownWindow(void);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper(System::TObject* AOwnerObject) : Dxbaraccessibility::TdxBarButtonLikeControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonQuickAccessGroupButtonControlAccessibilityHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonKeyTipWindow;
class PASCALIMPLEMENTATION TdxRibbonKeyTipWindow : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	Dxribbonskins::TdxCustomRibbonSkin* FColorScheme;
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	System::Types::TRect __fastcall CalcBoundsRect(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Paint(void);
	HIDESBASE void __fastcall UpdateBounds(void);
	
public:
	__fastcall virtual TdxRibbonKeyTipWindow(Dxribbonskins::TdxCustomRibbonSkin* AColorScheme);
	void __fastcall ShowKeyTip(void);
	__property Caption = {default=0};
	__property Enabled = {default=1};
public:
	/* TCustomControl.Destroy */ inline __fastcall virtual ~TdxRibbonKeyTipWindow(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonKeyTipWindow(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonCustomKeyTipWindows;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonCustomKeyTipWindows : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	TdxCustomRibbon* FRibbon;
	Cxclasses::TcxObjectList* FWindowList;
	Dxribbonskins::TdxCustomRibbonSkin* __fastcall GetColorScheme(void);
	int __fastcall GetCount(void);
	
protected:
	void __fastcall Add(const System::UnicodeString ACaption, const System::Types::TPoint &ABasePoint, System::Classes::TAlignment AHorzAlign, Cxclasses::TcxAlignmentVert AVertAlign, bool AEnabled, /* out */ System::TObject* &AWindow);
	virtual void __fastcall Initialize(void);
	void __fastcall Delete(System::TObject* AWindow);
	void __fastcall Show(void);
	__property Dxribbonskins::TdxCustomRibbonSkin* ColorScheme = {read=GetColorScheme};
	__property int Count = {read=GetCount, nodefault};
	
public:
	__fastcall TdxRibbonCustomKeyTipWindows(TdxCustomRibbon* ARibbon);
	__fastcall virtual ~TdxRibbonCustomKeyTipWindows(void);
private:
	void *__IdxBarKeyTipWindowsManager;	/* Dxbar::IdxBarKeyTipWindowsManager */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {ABA47F3E-5F8B-4A4B-863F-B70AC02F3C1D}
	operator Dxbar::_di_IdxBarKeyTipWindowsManager()
	{
		Dxbar::_di_IdxBarKeyTipWindowsManager intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarKeyTipWindowsManager*(void) { return (Dxbar::IdxBarKeyTipWindowsManager*)&__IdxBarKeyTipWindowsManager; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonKeyTipWindows;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonKeyTipWindows : public TdxRibbonCustomKeyTipWindows
{
	typedef TdxRibbonCustomKeyTipWindows inherited;
	
protected:
	virtual void __fastcall Initialize(void);
public:
	/* TdxRibbonCustomKeyTipWindows.Create */ inline __fastcall TdxRibbonKeyTipWindows(TdxCustomRibbon* ARibbon) : TdxRibbonCustomKeyTipWindows(ARibbon) { }
	/* TdxRibbonCustomKeyTipWindows.Destroy */ inline __fastcall virtual ~TdxRibbonKeyTipWindows(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonScrollBar;
class PASCALIMPLEMENTATION TdxRibbonScrollBar : public Cxcontrols::TcxControlScrollBar
{
	typedef Cxcontrols::TcxControlScrollBar inherited;
	
protected:
	virtual Cxscrollbar::TcxScrollBarHelperClass __fastcall GetHelperClass(void);
	virtual TdxCustomRibbon* __fastcall GetRibbon(void);
	
public:
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
public:
	/* TcxControlScrollBar.Create */ inline __fastcall virtual TdxRibbonScrollBar(System::Classes::TComponent* AOwner) : Cxcontrols::TcxControlScrollBar(AOwner) { }
	/* TcxControlScrollBar.Destroy */ inline __fastcall virtual ~TdxRibbonScrollBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonScrollBar(HWND ParentWindow) : Cxcontrols::TcxControlScrollBar(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonScrollBarHelper;
class PASCALIMPLEMENTATION TdxRibbonScrollBarHelper : public Cxcontrols::TcxControlScrollBarHelper
{
	typedef Cxcontrols::TcxControlScrollBarHelper inherited;
	
protected:
	virtual Cxscrollbar::TcxScrollBarPainterClass __fastcall GetPainterClass(void);
public:
	/* TcxControlScrollBarHelper.Create */ inline __fastcall virtual TdxRibbonScrollBarHelper(Cxscrollbar::_di_IcxScrollBarOwner AOwner) : Cxcontrols::TcxControlScrollBarHelper(AOwner) { }
	/* TcxControlScrollBarHelper.Destroy */ inline __fastcall virtual ~TdxRibbonScrollBarHelper(void) { }
	
};


class DELPHICLASS TdxRibbonScrollBarPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonScrollBarPainter : public Cxscrollbar::TcxScrollBarPainter
{
	typedef Cxscrollbar::TcxScrollBarPainter inherited;
	
private:
	TdxRibbonScrollBar* __fastcall GetScrollBar(void);
	Dxbar::_di_IdxSkin __fastcall GetSkin(void);
	
protected:
	virtual void __fastcall DoDrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawScrollBarBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	
public:
	__property TdxRibbonScrollBar* ScrollBar = {read=GetScrollBar};
	__property Dxbar::_di_IdxSkin Skin = {read=GetSkin};
public:
	/* TcxScrollBarPainter.Create */ inline __fastcall virtual TdxRibbonScrollBarPainter(Cxscrollbar::TcxScrollBarHelper* AScrollBar) : Cxscrollbar::TcxScrollBarPainter(AScrollBar) { }
	/* TcxScrollBarPainter.Destroy */ inline __fastcall virtual ~TdxRibbonScrollBarPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonSizeGrip;
class PASCALIMPLEMENTATION TdxRibbonSizeGrip : public Cxcontrols::TcxSizeGrip
{
	typedef Cxcontrols::TcxSizeGrip inherited;
	
protected:
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas);
	virtual TdxCustomRibbon* __fastcall GetRibbon(void);
	
public:
	__property TdxCustomRibbon* Ribbon = {read=GetRibbon};
public:
	/* TcxSizeGrip.Create */ inline __fastcall virtual TdxRibbonSizeGrip(System::Classes::TComponent* AOwner) : Cxcontrols::TcxSizeGrip(AOwner) { }
	/* TcxSizeGrip.Destroy */ inline __fastcall virtual ~TdxRibbonSizeGrip(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonSizeGrip(HWND ParentWindow) : Cxcontrols::TcxSizeGrip(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxRibbonHintOffset = System::Int8(0x14);
static const System::Int8 dxRibbonFormCaptionMinWidth = System::Int8(0x32);
static const System::Int8 dxRibbonFormContextsMinWidth = System::Int8(0x8);
static const System::Int8 dxRibbonFormCaptionTextSpace = System::Int8(0x4);
static const System::Int8 dxRibbonTabIndent = System::Int8(0x11);
static const System::Int8 dxRibbonTabMinWidth = System::Int8(0x1c);
static const System::Int8 dxRibbonTabTextOffset = System::Int8(0x5);
static const System::Int8 dxRibbonOptimalTabSpace = System::Int8(0x1b);
static const System::Int8 dxRibbonTabSeparatorVisibilityLimit = System::Int8(0xe);
extern PACKAGE int dxRibbonOwnerMinimalWidth;
extern PACKAGE int dxRibbonOwnerMinimalHeight;
static const System::Word dxRibbonScrollDelay = System::Word(0x190);
static const System::Int8 dxRibbonScrollInterval = System::Int8(0x14);
extern PACKAGE int dxRibbonTabGroupsPopupWindowShowAnimationTime;
extern PACKAGE int dxRibbonTabGroupsPopupWindowHideAnimationTime;
static const System::Int8 dxRibbonGroupRowCount = System::Int8(0x3);
#define dxRibbonDefaultMergeOptions (System::Set<TdxRibbonMergeOption, TdxRibbonMergeOption::rmoCanCreateNewTab, TdxRibbonMergeOption::rmoCanCreateQATToolbar> () << TdxRibbonMergeOption::rmoCanCreateNewTab << TdxRibbonMergeOption::rmoCanCreateNewGroup << TdxRibbonMergeOption::rmoCanCreateQATToolbar )
#define dxRibbonDefaultPopupMenuItems (System::Set<TdxRibbonPopupMenuItem, TdxRibbonPopupMenuItem::rpmiItems, TdxRibbonPopupMenuItem::rpmiMinimizeRibbon> () << TdxRibbonPopupMenuItem::rpmiItems << TdxRibbonPopupMenuItem::rpmiMoreCommands << TdxRibbonPopupMenuItem::rpmiQATPosition << TdxRibbonPopupMenuItem::rpmiQATAddRemoveItem << TdxRibbonPopupMenuItem::rpmiMinimizeRibbon )
extern PACKAGE void __fastcall RibbonCheckCreateComponent(System::Classes::TComponent* &AOwner, System::TClass AClass);
extern PACKAGE void __fastcall RibbonDockToolBar(Dxbar::TdxBar* AToolBar, Dxbar::TdxBarDockControl* ADockControl);
extern PACKAGE void __fastcall RibbonUndockToolBar(Dxbar::TdxBar* AToolBar);
extern PACKAGE TdxCustomRibbon* __fastcall FindRibbonForComponent(System::Classes::TComponent* AComponent);
}	/* namespace Dxribbon */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBON)
using namespace Dxribbon;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonHPP
