// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarAccessibility.pas' rev: 24.00 (Win64)

#ifndef DxbaraccessibilityHPP
#define DxbaraccessibilityHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbaraccessibility
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxDockControlAccessibilityHelper;
class PASCALIMPLEMENTATION TdxDockControlAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	Dxbar::TdxDockControl* __fastcall GetDockControl(void);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	__property Dxbar::TdxDockControl* DockControl = {read=GetDockControl};
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxDockControlAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDockControlAccessibilityHelper(void) { }
	
};


class DELPHICLASS TCustomdxBarControlAccessibilityHelper;
class DELPHICLASS TdxBarItemLinkAccessibilityHelper;
class PASCALIMPLEMENTATION TCustomdxBarControlAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
protected:
	Dxbar::TCustomdxBarControl* __fastcall GetBarControl(void);
	Dxbar::TdxBarItemLinks* __fastcall GetItemLinks(void);
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual bool __fastcall CanNavigateToChildren(System::Word AKey);
	virtual void __fastcall DoClickItem(TdxBarItemLinkAccessibilityHelper* AItemLinkHelper);
	virtual void __fastcall DoDropDownItem(TdxBarItemLinkAccessibilityHelper* AItemLinkHelper);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual TCustomdxBarControlAccessibilityHelper* __fastcall Expand(void);
	virtual void __fastcall InitializeItemKeyTipPosition(TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	System::Types::TRect __fastcall GetItemScreenBounds(TdxBarItemLinkAccessibilityHelper* AItemLinkHelper);
	HIDESBASE virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	virtual bool __fastcall IsCollapsed(void);
	virtual void __fastcall UnselectSelectedItemControl(void);
	virtual Dxbar::TdxBarAccessibilityHelper* __fastcall LogicalNavigationGetNextChild(int AChildIndex, System::Classes::TShiftState AShift)/* overload */;
	__property Dxbar::TCustomdxBarControl* BarControl = {read=GetBarControl};
	__property Dxbar::TdxBarItemLinks* ItemLinks = {read=GetItemLinks};
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TCustomdxBarControlAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TCustomdxBarControlAccessibilityHelper(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline Dxbar::_di_IdxBarAccessibilityHelper __fastcall  GetNextAccessibleObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection){ return Dxbar::TdxBarAccessibilityHelper::GetNextAccessibleObject(ADirection); }
	inline Dxbar::TdxBarAccessibilityHelper* __fastcall  LogicalNavigationGetNextChild(int AChildIndex, bool AGoForward){ return Dxbar::TdxBarAccessibilityHelper::LogicalNavigationGetNextChild(AChildIndex, AGoForward); }
	
};


class DELPHICLASS TdxBarControlAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarControlAccessibilityHelper : public TCustomdxBarControlAccessibilityHelper
{
	typedef TCustomdxBarControlAccessibilityHelper inherited;
	
private:
	Dxbar::TdxBar* __fastcall GetBar(void);
	HIDESBASE Dxbar::TdxBarControl* __fastcall GetBarControl(void);
	
protected:
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetDefaultAccessibleObject(void);
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual void __fastcall Select(bool ASetFocus);
	virtual void __fastcall Unselect(Dxbar::_di_IdxBarAccessibilityHelper ANextSelectedObject);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual void __fastcall GetCaptionButtonKeyTipPosition(Dxbar::TdxBarCaptionButton* ACaptionButton, /* out */ int &ABasePointY, /* out */ Cxclasses::TcxAlignmentVert &AVertAlign);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	__property Dxbar::TdxBar* Bar = {read=GetBar};
	__property Dxbar::TdxBarControl* BarControl = {read=GetBarControl};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarControlAccessibilityHelper(System::TObject* AOwnerObject) : TCustomdxBarControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarControlAccessibilityHelper(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline Dxbar::_di_IdxBarAccessibilityHelper __fastcall  GetNextAccessibleObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection){ return Dxbar::TdxBarAccessibilityHelper::GetNextAccessibleObject(ADirection); }
	
};


class DELPHICLASS TdxBarControlMarkAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarControlMarkAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	Dxbar::TdxBarControl* __fastcall GetBarControl(void);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual bool __fastcall IsNavigationKey(System::Word AKey);
	virtual void __fastcall Select(bool ASetFocus);
	virtual void __fastcall Unselect(Dxbar::_di_IdxBarAccessibilityHelper ANextSelectedObject);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual bool __fastcall GetSelectable(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	void __fastcall DropDown(void);
	void __fastcall UpdateMarkState(void);
	__property Dxbar::TdxBarControl* BarControl = {read=GetBarControl};
	
public:
	void __fastcall CloseUpHandler(Dxbar::TdxBarCloseUpReason AReason);
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarControlMarkAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarControlMarkAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarCaptionButtonsAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarCaptionButtonsAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	Dxbar::TdxBarCaptionButtons* __fastcall GetCaptionButtons(void);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual void __fastcall Unselect(Dxbar::_di_IdxBarAccessibilityHelper ANextSelectedObject);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(Cxaccessibility::TcxAccessibilityHelper* AChild);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	void __fastcall UpdateCaptionButtons(void);
	__property Dxbar::TdxBarCaptionButtons* CaptionButtons = {read=GetCaptionButtons};
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarCaptionButtonsAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarCaptionButtonsAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarCaptionButtonAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarCaptionButtonAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
private:
	void __fastcall DoButtonClick(void);
	Dxbar::TdxBarCaptionButton* __fastcall GetCaptionButton(void);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
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
	__property Dxbar::TdxBarCaptionButton* CaptionButton = {read=GetCaptionButton};
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarCaptionButtonAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarCaptionButtonAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarSubMenuControlAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarSubMenuControlAccessibilityHelper : public TCustomdxBarControlAccessibilityHelper
{
	typedef TCustomdxBarControlAccessibilityHelper inherited;
	
private:
	HIDESBASE Dxbar::TdxBarSubMenuControl* __fastcall GetBarControl(void);
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual void __fastcall InitializeItemKeyTipPosition(TdxBarItemLinkAccessibilityHelper* AItemLinkHelper, Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual Dxbar::TdxBarItemLink* __fastcall GetNextItemLink(Dxbar::TdxBarItemLink* AItemLink, bool AGoForward);
	virtual Dxbar::TdxBarAccessibilityHelper* __fastcall GetParentForKeyTip(void);
	virtual void __fastcall HandleHorzNavigationKey(bool ALeftKey);
	virtual void __fastcall HandleVertNavigationKey(bool AUpKey, bool AFocusItemControl);
	virtual bool __fastcall IsKeyTipContainer(void);
	virtual void __fastcall KeyTipsEscapeHandler(void);
	virtual void __fastcall UnselectSelectedItemControl(void);
	__property Dxbar::TdxBarSubMenuControl* BarControl = {read=GetBarControl};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarSubMenuControlAccessibilityHelper(System::TObject* AOwnerObject) : TCustomdxBarControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarSubMenuControlAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarItemAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarItemAccessibilityHelper : public Dxbar::TdxBarAccessibilityHelper
{
	typedef Dxbar::TdxBarAccessibilityHelper inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetAssignedKeyTip(void);
	virtual System::UnicodeString __fastcall GetDefaultKeyTip(void);
	virtual void __fastcall KeyTipHandler(System::TObject* Sender);
	virtual Dxbar::TdxBarItem* __fastcall GetItem(void) = 0 ;
	virtual System::Classes::TShortCut __fastcall GetShortCut(void);
	virtual void __fastcall DoClick(void) = 0 ;
	virtual void __fastcall DoDropDown(void) = 0 ;
	virtual bool __fastcall IsDropDownControl(void);
	
public:
	__property Dxbar::TdxBarItem* Item = {read=GetItem};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarItemAccessibilityHelper(System::TObject* AOwnerObject) : Dxbar::TdxBarAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarItemAccessibilityHelper(void) { }
	
};


class PASCALIMPLEMENTATION TdxBarItemLinkAccessibilityHelper : public TdxBarItemAccessibilityHelper
{
	typedef TdxBarItemAccessibilityHelper inherited;
	
protected:
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	virtual Dxbar::_di_IdxBarAccessibilityHelper __fastcall GetNextAccessibleObject(Cxaccessibility::TcxAccessibilityNavigationDirection ADirection)/* overload */;
	virtual bool __fastcall GetSelectable(void);
	virtual void __fastcall GetKeyTipInfo(/* out */ Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual Dxbar::TdxBarItem* __fastcall GetItem(void);
	virtual Dxbar::TdxBarItemLink* __fastcall GetItemLink(void);
	virtual Dxbar::TdxBarItemControl* __fastcall GetItemControl(void);
	virtual void __fastcall DoClick(void);
	virtual void __fastcall DoDropDown(void);
	
public:
	__property Dxbar::TdxBarItemLink* ItemLink = {read=GetItemLink};
	__property Dxbar::TdxBarItemControl* ItemControl = {read=GetItemControl};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarItemLinkAccessibilityHelper(System::TObject* AOwnerObject) : TdxBarItemAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarItemLinkAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarItemControlAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarItemControlAccessibilityHelper : public TdxBarItemLinkAccessibilityHelper
{
	typedef TdxBarItemLinkAccessibilityHelper inherited;
	
private:
	void __fastcall InvisibleKeyTipHandler(System::TObject* Sender);
	
protected:
	virtual bool __fastcall HandleNavigationKey(System::Word &AKey);
	virtual void __fastcall Select(bool ASetFocus);
	virtual void __fastcall Unselect(Dxbar::_di_IdxBarAccessibilityHelper ANextSelectedObject);
	virtual void __fastcall GetKeyTipInfo(/* out */ Dxbar::TdxBarKeyTipInfo &AKeyTipInfo);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual bool __fastcall GetSelectable(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	virtual Dxbar::TdxBarItem* __fastcall GetItem(void);
	virtual System::Classes::TShortCut __fastcall GetShortCut(void);
	virtual Dxbar::TdxBarItemLink* __fastcall GetItemLink(void);
	virtual Dxbar::TdxBarItemControl* __fastcall GetItemControl(void);
	bool __fastcall CanSelect(void);
	virtual bool __fastcall NeedsVisibilityForKeyTipHandling(void);
	
public:
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarItemControlAccessibilityHelper(System::TObject* AOwnerObject) : TdxBarItemLinkAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarItemControlAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarButtonLikeControlAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarButtonLikeControlAccessibilityHelper : public TdxBarItemControlAccessibilityHelper
{
	typedef TdxBarItemControlAccessibilityHelper inherited;
	
protected:
	virtual void __fastcall DoClick(void);
	virtual void __fastcall DoDropDown(void);
	virtual bool __fastcall IsDropDownControl(void);
	virtual bool __fastcall NeedsVisibilityForKeyTipHandling(void);
	virtual bool __fastcall ShowDropDownWindow(void) = 0 ;
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarButtonLikeControlAccessibilityHelper(System::TObject* AOwnerObject) : TdxBarItemControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarButtonLikeControlAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarButtonControlAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarButtonControlAccessibilityHelper : public TdxBarButtonLikeControlAccessibilityHelper
{
	typedef TdxBarButtonLikeControlAccessibilityHelper inherited;
	
private:
	Dxbar::TdxBarButtonControl* __fastcall GetButtonControl(void);
	
protected:
	virtual bool __fastcall IsDropDownControl(void);
	virtual bool __fastcall ShowDropDownWindow(void);
	__property Dxbar::TdxBarButtonControl* ButtonControl = {read=GetButtonControl};
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarButtonControlAccessibilityHelper(System::TObject* AOwnerObject) : TdxBarButtonLikeControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarButtonControlAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarSubItemControlAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarSubItemControlAccessibilityHelper : public TdxBarButtonLikeControlAccessibilityHelper
{
	typedef TdxBarButtonLikeControlAccessibilityHelper inherited;
	
protected:
	virtual bool __fastcall IsDropDownControl(void);
	virtual bool __fastcall ShowDropDownWindow(void);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarSubItemControlAccessibilityHelper(System::TObject* AOwnerObject) : TdxBarButtonLikeControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarSubItemControlAccessibilityHelper(void) { }
	
};


class DELPHICLASS TdxBarWinControlAccessibilityHelper;
class PASCALIMPLEMENTATION TdxBarWinControlAccessibilityHelper : public TdxBarItemControlAccessibilityHelper
{
	typedef TdxBarItemControlAccessibilityHelper inherited;
	
protected:
	virtual void __fastcall KeyTipHandler(System::TObject* Sender);
	virtual bool __fastcall NeedsVisibilityForKeyTipHandling(void);
public:
	/* TcxAccessibilityHelper.Create */ inline __fastcall virtual TdxBarWinControlAccessibilityHelper(System::TObject* AOwnerObject) : TdxBarItemControlAccessibilityHelper(AOwnerObject) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarWinControlAccessibilityHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxbaraccessibility */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARACCESSIBILITY)
using namespace Dxbaraccessibility;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbaraccessibilityHPP
