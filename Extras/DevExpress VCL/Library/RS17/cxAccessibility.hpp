// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxAccessibility.pas' rev: 24.00 (Win32)

#ifndef CxaccessibilityHPP
#define CxaccessibilityHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.OleServer.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <OleIdl.h>

namespace Cxaccessibility
{
//-- type declarations -------------------------------------------------------
typedef int TcxAccessibleSimpleChildElementID;

enum TcxAccessibleObjectProperty : unsigned char { aopDefaultAction, aopDescription, aopFocus, aopLocation, aopShortcut, aopValue };

typedef System::Set<TcxAccessibleObjectProperty, TcxAccessibleObjectProperty::aopDefaultAction, TcxAccessibleObjectProperty::aopValue>  TcxAccessibleObjectProperties;

enum TcxAccessibleObjectHitTest : unsigned char { aohtNone, aohtSelf, aohtChild };

enum TcxAccessibilityNavigationDirection : unsigned char { andLeft, andUp, andRight, andDown, andPrev, andNext };

__interface IcxAccessible;
typedef System::DelphiInterface<IcxAccessible> _di_IcxAccessible;
__interface  INTERFACE_UUID("{618736E0-3C3D-11CF-810C-00AA00389B71}") IcxAccessible  : public IDispatch 
{
	
public:
	virtual HRESULT __stdcall Get_accParent(/* out */ _di_IDispatch &ppdispParent) = 0 ;
	virtual HRESULT __stdcall Get_accChildCount(/* out */ int &pcountChildren) = 0 ;
	virtual HRESULT __stdcall Get_accChild(const System::OleVariant varChild, /* out */ _di_IDispatch &ppdispChild) = 0 ;
	virtual HRESULT __stdcall Get_accName(const System::OleVariant varChild, /* out */ System::WideString &pszName) = 0 ;
	virtual HRESULT __stdcall Get_accValue(const System::OleVariant varChild, /* out */ System::WideString &pszValue) = 0 ;
	virtual HRESULT __stdcall Get_accDescription(const System::OleVariant varChild, /* out */ System::WideString &pszDescription) = 0 ;
	virtual HRESULT __stdcall Get_accRole(const System::OleVariant varChild, /* out */ System::OleVariant &pvarRole) = 0 ;
	virtual HRESULT __stdcall Get_accState(const System::OleVariant varChild, /* out */ System::OleVariant &pvarState) = 0 ;
	virtual HRESULT __stdcall Get_accHelp(const System::OleVariant varChild, /* out */ System::WideString &pszHelp) = 0 ;
	virtual HRESULT __stdcall Get_accHelpTopic(/* out */ System::WideString &pszHelpFile, const System::OleVariant varChild, /* out */ int &pidTopic) = 0 ;
	virtual HRESULT __stdcall Get_accKeyboardShortcut(const System::OleVariant varChild, /* out */ System::WideString &pszKeyboardShortcut) = 0 ;
	virtual HRESULT __stdcall Get_accFocus(/* out */ System::OleVariant &pvarChild) = 0 ;
	virtual HRESULT __stdcall Get_accSelection(/* out */ System::OleVariant &pvarChildren) = 0 ;
	virtual HRESULT __stdcall Get_accDefaultAction(const System::OleVariant varChild, /* out */ System::WideString &pszDefaultAction) = 0 ;
	virtual HRESULT __stdcall accSelect(int flagsSelect, const System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall accLocation(/* out */ int &pxLeft, /* out */ int &pyTop, /* out */ int &pcxWidth, /* out */ int &pcyHeight, const System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall accNavigate(int navDir, const System::OleVariant varStart, /* out */ System::OleVariant &pvarEndUpAt) = 0 ;
	virtual HRESULT __stdcall accHitTest(int xLeft, int yTop, /* out */ System::OleVariant &pvarChild) = 0 ;
	virtual HRESULT __stdcall accDoDefaultAction(const System::OleVariant varChild) = 0 ;
	virtual HRESULT __stdcall Set_accName(const System::OleVariant varChild, const System::WideString pszName) = 0 ;
	virtual HRESULT __stdcall Set_accValue(const System::OleVariant varChild, const System::WideString pszValue) = 0 ;
};

__interface IcxAccessibilityHelper;
typedef System::DelphiInterface<IcxAccessibilityHelper> _di_IcxAccessibilityHelper;
class DELPHICLASS TcxAccessibilityHelper;
__interface  INTERFACE_UUID("{D4890860-09B2-4648-BD9E-DFFBD140E5F1}") IcxAccessibilityHelper  : public System::IInterface 
{
	
public:
	virtual TcxAccessibilityHelper* __fastcall GetHelper(void) = 0 ;
	virtual void __fastcall OwnerObjectDestroyed(void) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxAccessibilityHelper : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	bool FIsOwnerObjectLive;
	HRESULT __stdcall GetIDsOfNames(const GUID &IID, void * Names, int NameCount, int LocaleID, void * DispIDs);
	HRESULT __stdcall GetTypeInfo(int Index, int LocaleID, /* out */ void *TypeInfo);
	HRESULT __stdcall GetTypeInfoCount(/* out */ int &Count);
	HRESULT __stdcall Invoke(int DispID, const GUID &IID, int LocaleID, System::Word Flags, void *Params, void * VarResult, void * ExcepInfo, void * ArgErr);
	HRESULT __stdcall ContextSensitiveHelp(BOOL fEnterMode);
	HRESULT __stdcall GetWindow(/* out */ HWND &wnd);
	HRESULT __stdcall accDoDefaultAction(const System::OleVariant varChild);
	HRESULT __stdcall accHitTest(int xLeft, int yTop, /* out */ System::OleVariant &pvarChild);
	HRESULT __stdcall accLocation(/* out */ int &pxLeft, /* out */ int &pyTop, /* out */ int &pcxWidth, /* out */ int &pcyHeight, const System::OleVariant varChild);
	HRESULT __stdcall accNavigate(int navDir, const System::OleVariant varStart, /* out */ System::OleVariant &pvarEndUpAt);
	HRESULT __stdcall accSelect(int flagsSelect, const System::OleVariant varChild);
	HRESULT __stdcall Get_accChild(const System::OleVariant varChild, /* out */ _di_IDispatch &ppdispChild);
	HRESULT __stdcall Get_accChildCount(/* out */ int &pcountChildren);
	HRESULT __stdcall Get_accDefaultAction(const System::OleVariant varChild, /* out */ System::WideString &pszDefaultAction);
	HRESULT __stdcall Get_accDescription(const System::OleVariant varChild, /* out */ System::WideString &pszDescription);
	HRESULT __stdcall Get_accFocus(/* out */ System::OleVariant &pvarChild);
	HRESULT __stdcall Get_accHelp(const System::OleVariant varChild, /* out */ System::WideString &pszHelp);
	HRESULT __stdcall Get_accHelpTopic(/* out */ System::WideString &pszHelpFile, const System::OleVariant varChild, /* out */ int &pidTopic);
	HRESULT __stdcall Get_accKeyboardShortcut(const System::OleVariant varChild, /* out */ System::WideString &pszKeyboardShortcut);
	HRESULT __stdcall Get_accName(const System::OleVariant varChild, /* out */ System::WideString &pszName);
	HRESULT __stdcall Get_accParent(/* out */ _di_IDispatch &ppdispParent);
	HRESULT __stdcall Get_accRole(const System::OleVariant varChild, /* out */ System::OleVariant &pvarRole);
	HRESULT __stdcall Get_accSelection(/* out */ System::OleVariant &pvarChildren);
	HRESULT __stdcall Get_accState(const System::OleVariant varChild, /* out */ System::OleVariant &pvarState);
	HRESULT __stdcall Get_accValue(const System::OleVariant varChild, /* out */ System::WideString &pszValue);
	HRESULT __stdcall Set_accName(const System::OleVariant varChild, const System::WideString pszName);
	HRESULT __stdcall Set_accValue(const System::OleVariant varChild, const System::WideString pszValue);
	bool __fastcall CheckIsOwnerObjectLive(/* out */ HRESULT &AErrorCode);
	void __fastcall CheckSimpleChildElementToBeReturned(System::OleVariant &AVarChild);
	void __fastcall CheckStringToBeReturned(const System::WideString AStr, /* out */ HRESULT &AResult);
	bool __fastcall GetSimpleChildElementID(const System::OleVariant &AChildID, /* out */ TcxAccessibleSimpleChildElementID &ASimpleChildElementID, /* out */ HRESULT &AErrorCode);
	bool __fastcall GetVisible(void);
	
protected:
	System::TObject* FOwnerObject;
	TcxAccessibilityHelper* __fastcall GetHelper(void);
	virtual void __fastcall OwnerObjectDestroyed(void);
	virtual bool __fastcall ChildIsSimpleElement(int AIndex);
	virtual void __fastcall DoDefaultAction(TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall Focused(/* out */ bool &AIsChildFocused, /* out */ int &AFocusedChildIndex);
	virtual TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual int __fastcall GetChildIndex(TcxAccessibilityHelper* AChild);
	virtual System::UnicodeString __fastcall GetDefaultActionDescription(TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetDescription(TcxAccessibleSimpleChildElementID AChildID);
	virtual TcxAccessibleObjectHitTest __fastcall GetHitTest(int AScreenX, int AScreenY, /* out */ int &AChildIndex);
	virtual void __fastcall GetKeyboardAccessParameters(TcxAccessibleSimpleChildElementID AChildID, /* out */ System::Classes::TShortCut &AShortCut, /* out */ System::UnicodeString &ACaptionWithAccelChars);
	virtual System::UnicodeString __fastcall GetName(TcxAccessibleSimpleChildElementID AChildID);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual TcxAccessibilityHelper* __fastcall GetParent(void);
	virtual int __fastcall GetRole(TcxAccessibleSimpleChildElementID AChildID);
	virtual bool __fastcall GetSelectable(void);
	virtual int __fastcall GetState(TcxAccessibleSimpleChildElementID AChildID);
	virtual TcxAccessibleObjectProperties __fastcall GetSupportedProperties(TcxAccessibleSimpleChildElementID AChildID);
	virtual System::UnicodeString __fastcall GetValue(TcxAccessibleSimpleChildElementID AChildID);
	virtual int __fastcall NavigateToChild(int ACurrentChildIndex, TcxAccessibilityNavigationDirection ADirection);
	virtual void __fastcall SetValue(TcxAccessibleSimpleChildElementID AChildID, const System::UnicodeString Value);
	TcxAccessibilityHelper* __fastcall GetRootHelper(void);
	
public:
	int __fastcall GetNextSelectableChildIndex(int AStartIndex, bool AGoForward);
	virtual System::Types::TRect __fastcall GetScreenBounds(TcxAccessibleSimpleChildElementID AChildID);
	__fastcall virtual TcxAccessibilityHelper(System::TObject* AOwnerObject);
	__property TcxAccessibilityHelper* Childs[int AIndex] = {read=GetChild};
	__property int ChildCount = {read=GetChildCount, nodefault};
	__property bool IsOwnerObjectLive = {read=FIsOwnerObjectLive, nodefault};
	__property System::TObject* OwnerObject = {read=FOwnerObject};
	__property HWND OwnerObjectWindow = {read=GetOwnerObjectWindow, nodefault};
	__property TcxAccessibilityHelper* Parent = {read=GetParent};
	__property bool Selectable = {read=GetSelectable, nodefault};
	__property int States[TcxAccessibleSimpleChildElementID AChildID] = {read=GetState};
	__property bool Visible = {read=GetVisible, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxAccessibilityHelper(void) { }
	
private:
	void *__IcxAccessibilityHelper;	/* IcxAccessibilityHelper */
	void *__IcxAccessible;	/* IcxAccessible */
	void *__IOleWindow;	/* IOleWindow */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D4890860-09B2-4648-BD9E-DFFBD140E5F1}
	operator _di_IcxAccessibilityHelper()
	{
		_di_IcxAccessibilityHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxAccessibilityHelper*(void) { return (IcxAccessibilityHelper*)&__IcxAccessibilityHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {618736E0-3C3D-11CF-810C-00AA00389B71}
	operator _di_IcxAccessible()
	{
		_di_IcxAccessible intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxAccessible*(void) { return (IcxAccessible*)&__IcxAccessible; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000114-0000-0000-C000-000000000046}
	operator _di_IOleWindow()
	{
		_di_IOleWindow intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IOleWindow*(void) { return (IOleWindow*)&__IOleWindow; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00020400-0000-0000-C000-000000000046}
	operator _di_IDispatch()
	{
		_di_IDispatch intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IDispatch*(void) { return (IDispatch*)&__IcxAccessible; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxAccessibilityHelperClass;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxAccessibleObjectSelfID = System::Int8(0x0);
#define SID_IcxAccessible L"{618736E0-3C3D-11CF-810C-00AA00389B71}"
extern PACKAGE GUID IID_IcxAccessible;
static const System::Int8 cxROLE_SYSTEM_TITLEBAR = System::Int8(0x1);
static const System::Int8 cxROLE_SYSTEM_MENUBAR = System::Int8(0x2);
static const System::Int8 cxROLE_SYSTEM_SCROLLBAR = System::Int8(0x3);
static const System::Int8 cxROLE_SYSTEM_GRIP = System::Int8(0x4);
static const System::Int8 cxROLE_SYSTEM_SOUND = System::Int8(0x5);
static const System::Int8 cxROLE_SYSTEM_CURSOR = System::Int8(0x6);
static const System::Int8 cxROLE_SYSTEM_CARET = System::Int8(0x7);
static const System::Int8 cxROLE_SYSTEM_ALERT = System::Int8(0x8);
static const System::Int8 cxROLE_SYSTEM_WINDOW = System::Int8(0x9);
static const System::Int8 cxROLE_SYSTEM_CLIENT = System::Int8(0xa);
static const System::Int8 cxROLE_SYSTEM_MENUPOPUP = System::Int8(0xb);
static const System::Int8 cxROLE_SYSTEM_MENUITEM = System::Int8(0xc);
static const System::Int8 cxROLE_SYSTEM_TOOLTIP = System::Int8(0xd);
static const System::Int8 cxROLE_SYSTEM_APPLICATION = System::Int8(0xe);
static const System::Int8 cxROLE_SYSTEM_DOCUMENT = System::Int8(0xf);
static const System::Int8 cxROLE_SYSTEM_PANE = System::Int8(0x10);
static const System::Int8 cxROLE_SYSTEM_CHART = System::Int8(0x11);
static const System::Int8 cxROLE_SYSTEM_DIALOG = System::Int8(0x12);
static const System::Int8 cxROLE_SYSTEM_BORDER = System::Int8(0x13);
static const System::Int8 cxROLE_SYSTEM_GROUPING = System::Int8(0x14);
static const System::Int8 cxROLE_SYSTEM_SEPARATOR = System::Int8(0x15);
static const System::Int8 cxROLE_SYSTEM_TOOLBAR = System::Int8(0x16);
static const System::Int8 cxROLE_SYSTEM_STATUSBAR = System::Int8(0x17);
static const System::Int8 cxROLE_SYSTEM_TABLE = System::Int8(0x18);
static const System::Int8 cxROLE_SYSTEM_COLUMNHEADER = System::Int8(0x19);
static const System::Int8 cxROLE_SYSTEM_ROWHEADER = System::Int8(0x1a);
static const System::Int8 cxROLE_SYSTEM_COLUMN = System::Int8(0x1b);
static const System::Int8 cxROLE_SYSTEM_ROW = System::Int8(0x1c);
static const System::Int8 cxROLE_SYSTEM_CELL = System::Int8(0x1d);
static const System::Int8 cxROLE_SYSTEM_LINK = System::Int8(0x1e);
static const System::Int8 cxROLE_SYSTEM_HELPBALLOON = System::Int8(0x1f);
static const System::Int8 cxROLE_SYSTEM_CHARACTER = System::Int8(0x20);
static const System::Int8 cxROLE_SYSTEM_LIST = System::Int8(0x21);
static const System::Int8 cxROLE_SYSTEM_LISTITEM = System::Int8(0x22);
static const System::Int8 cxROLE_SYSTEM_OUTLINE = System::Int8(0x23);
static const System::Int8 cxROLE_SYSTEM_OUTLINEITEM = System::Int8(0x24);
static const System::Int8 cxROLE_SYSTEM_PAGETAB = System::Int8(0x25);
static const System::Int8 cxROLE_SYSTEM_PROPERTYPAGE = System::Int8(0x26);
static const System::Int8 cxROLE_SYSTEM_INDICATOR = System::Int8(0x27);
static const System::Int8 cxROLE_SYSTEM_GRAPHIC = System::Int8(0x28);
static const System::Int8 cxROLE_SYSTEM_STATICTEXT = System::Int8(0x29);
static const System::Int8 cxROLE_SYSTEM_TEXT = System::Int8(0x2a);
static const System::Int8 cxROLE_SYSTEM_PUSHBUTTON = System::Int8(0x2b);
static const System::Int8 cxROLE_SYSTEM_CHECKBUTTON = System::Int8(0x2c);
static const System::Int8 cxROLE_SYSTEM_RADIOBUTTON = System::Int8(0x2d);
static const System::Int8 cxROLE_SYSTEM_COMBOBOX = System::Int8(0x2e);
static const System::Int8 cxROLE_SYSTEM_DROPLIST = System::Int8(0x2f);
static const System::Int8 cxROLE_SYSTEM_PROGRESSBAR = System::Int8(0x30);
static const System::Int8 cxROLE_SYSTEM_DIAL = System::Int8(0x31);
static const System::Int8 cxROLE_SYSTEM_HOTKEYFIELD = System::Int8(0x32);
static const System::Int8 cxROLE_SYSTEM_SLIDER = System::Int8(0x33);
static const System::Int8 cxROLE_SYSTEM_SPINBUTTON = System::Int8(0x34);
static const System::Int8 cxROLE_SYSTEM_DIAGRAM = System::Int8(0x35);
static const System::Int8 cxROLE_SYSTEM_ANIMATION = System::Int8(0x36);
static const System::Int8 cxROLE_SYSTEM_EQUATION = System::Int8(0x37);
static const System::Int8 cxROLE_SYSTEM_BUTTONDROPDOWN = System::Int8(0x38);
static const System::Int8 cxROLE_SYSTEM_BUTTONMENU = System::Int8(0x39);
static const System::Int8 cxROLE_SYSTEM_BUTTONDROPDOWNGRID = System::Int8(0x3a);
static const System::Int8 cxROLE_SYSTEM_WHITESPACE = System::Int8(0x3b);
static const System::Int8 cxROLE_SYSTEM_PAGETABLIST = System::Int8(0x3c);
static const System::Int8 cxROLE_SYSTEM_CLOCK = System::Int8(0x3d);
static const System::Int8 cxROLE_SYSTEM_SPLITBUTTON = System::Int8(0x3e);
static const System::Int8 cxROLE_SYSTEM_IPADDRESS = System::Int8(0x3f);
static const System::Int8 cxROLE_SYSTEM_OUTLINEBUTTON = System::Int8(0x40);
static const System::Int8 cxSTATE_SYSTEM_NORMAL = System::Int8(0x0);
static const System::Int8 cxSTATE_SYSTEM_UNAVAILABLE = System::Int8(0x1);
static const System::Int8 cxSTATE_SYSTEM_SELECTED = System::Int8(0x2);
static const System::Int8 cxSTATE_SYSTEM_FOCUSED = System::Int8(0x4);
static const System::Int8 cxSTATE_SYSTEM_PRESSED = System::Int8(0x8);
static const System::Int8 cxSTATE_SYSTEM_CHECKED = System::Int8(0x10);
static const System::Int8 cxSTATE_SYSTEM_MIXED = System::Int8(0x20);
static const System::Int8 cxSTATE_SYSTEM_INDETERMINATE = System::Int8(0x20);
static const System::Int8 cxSTATE_SYSTEM_READONLY = System::Int8(0x40);
static const System::Byte cxSTATE_SYSTEM_HOTTRACKED = System::Byte(0x80);
static const System::Word cxSTATE_SYSTEM_DEFAULT = System::Word(0x100);
static const System::Word cxSTATE_SYSTEM_EXPANDED = System::Word(0x200);
static const System::Word cxSTATE_SYSTEM_COLLAPSED = System::Word(0x400);
static const System::Word cxSTATE_SYSTEM_BUSY = System::Word(0x800);
static const System::Word cxSTATE_SYSTEM_FLOATING = System::Word(0x1000);
static const System::Word cxSTATE_SYSTEM_MARQUEED = System::Word(0x2000);
static const System::Word cxSTATE_SYSTEM_ANIMATED = System::Word(0x4000);
static const System::Word cxSTATE_SYSTEM_INVISIBLE = System::Word(0x8000);
static const int cxSTATE_SYSTEM_OFFSCREEN = int(0x10000);
static const int cxSTATE_SYSTEM_SIZEABLE = int(0x20000);
static const int cxSTATE_SYSTEM_MOVEABLE = int(0x40000);
static const int cxSTATE_SYSTEM_SELFVOICING = int(0x80000);
static const int cxSTATE_SYSTEM_FOCUSABLE = int(0x100000);
static const int cxSTATE_SYSTEM_SELECTABLE = int(0x200000);
static const int cxSTATE_SYSTEM_LINKED = int(0x400000);
static const int cxSTATE_SYSTEM_TRAVERSED = int(0x800000);
static const int cxSTATE_SYSTEM_MULTISELECTABLE = int(0x1000000);
static const int cxSTATE_SYSTEM_EXTSELECTABLE = int(0x2000000);
static const int cxSTATE_SYSTEM_ALERT_LOW = int(0x4000000);
static const int cxSTATE_SYSTEM_ALERT_MEDIUM = int(0x8000000);
static const int cxSTATE_SYSTEM_ALERT_HIGH = int(0x10000000);
static const int cxSTATE_SYSTEM_PROTECTED = int(0x20000000);
static const int cxSTATE_SYSTEM_VALID = int(0x7fffffff);
static const int cxSTATE_SYSTEM_HASPOPUP = int(0x40000000);
extern PACKAGE NativeInt __fastcall WMGetObjectResultFromIAccessibilityHelper(const Winapi::Messages::TMessage &AWMGetObjectMessage, _di_IcxAccessibilityHelper AIHelper);
extern PACKAGE bool __fastcall CanReturnAccessibleObject(const Winapi::Messages::TMessage &AWMGetObjectMessage);
extern PACKAGE bool __fastcall IsAccessibilitySupported(void);
}	/* namespace Cxaccessibility */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXACCESSIBILITY)
using namespace Cxaccessibility;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxaccessibilityHPP
