// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDesignWindows.pas' rev: 24.00 (Win32)

#ifndef CxdesignwindowsHPP
#define CxdesignwindowsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <ComponentDesigner.hpp>	// Pascal unit
#include <DesignConst.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdesignwindows
{
//-- type declarations -------------------------------------------------------
typedef Designintf::_di_IDesignerSelections TDesignerSelectionList;

class DELPHICLASS TcxDesignHelper;
class DELPHICLASS TcxDesignWindow;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDesignHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TComponent* FComponent;
	Designintf::_di_IDesigner FDesigner;
	System::Classes::TList* FList;
	int FRefCount;
	TcxDesignWindow* FWindow;
	Designintf::_di_IDesigner __fastcall GetDesigner(void);
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	void __fastcall NotifyListeners(System::Classes::TList* AList);
	void __fastcall SelectionsChanged(System::TObject* Sender, const Designintf::_di_IDesignerSelections ASelection);
	
public:
	__fastcall virtual TcxDesignHelper(System::Classes::TComponent* AComponent);
	__fastcall virtual ~TcxDesignHelper(void);
	void __fastcall ChangeSelection(System::Classes::TPersistent* AObject)/* overload */;
	void __fastcall GetSelection(System::Classes::TList* AList);
	bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject)/* overload */;
	void __fastcall SelectObject(System::Classes::TPersistent* AObject, bool AClearSelection = true, bool AActivateOwner = true)/* overload */;
	void __fastcall SetSelection(System::Classes::TList* AList);
	void __fastcall UnselectObject(System::Classes::TPersistent* AObject)/* overload */;
	void __fastcall AddSelectionChangedListener(System::Classes::TPersistent* AListener);
	bool __fastcall CanAddComponent(System::Classes::TComponent* AOwner);
	bool __fastcall CanDeleteComponent(System::Classes::TComponent* AOwner, System::Classes::TComponent* AComponent);
	void __fastcall ChangeSelection(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject)/* overload */;
	bool __fastcall IsObjectSelected(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject)/* overload */;
	virtual void __fastcall Modified(void);
	void __fastcall RemoveSelectionChangedListener(System::Classes::TPersistent* AListener);
	void __fastcall SelectObject(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject, bool AClearSelection = true, bool AActivateOwner = true)/* overload */;
	void __fastcall ShowComponentDefaultEventHandler(System::Classes::TComponent* AComponent);
	System::UnicodeString __fastcall UniqueName(const System::UnicodeString ABaseName);
	void __fastcall UnselectObject(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject)/* overload */;
	__property System::Classes::TComponent* Component = {read=FComponent, write=FComponent};
	__property Designintf::_di_IDesigner Designer = {read=GetDesigner};
private:
	void *__IcxDesignHelper;	/* Cxclasses::IcxDesignHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4C78CC4F-699B-43BD-94AC-E3BD2233F7A1}
	operator Cxclasses::_di_IcxDesignHelper()
	{
		Cxclasses::_di_IcxDesignHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxclasses::IcxDesignHelper*(void) { return (Cxclasses::IcxDesignHelper*)&__IcxDesignHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxDesignHelper; }
	#endif
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxSelectionsChanged)(System::TObject* Sender, const Designintf::_di_IDesignerSelections ASelection);

class PASCALIMPLEMENTATION TcxDesignWindow : public Designwindows::TDesignWindow
{
	typedef Designwindows::TDesignWindow inherited;
	
private:
	int FLockCount;
	TcxSelectionsChanged FOnSelectionsChanged;
	
protected:
	DYNAMIC void __fastcall Activated(void);
	virtual System::UnicodeString __fastcall UniqueName(System::Classes::TComponent* Component);
	
public:
	__fastcall virtual TcxDesignWindow(System::Classes::TComponent* AOwner);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(bool AForceUpdate = true);
	__classmethod System::UnicodeString __fastcall GetBaseRegKey(Componentdesigner::_di_IComponentDesigner ADesigner = Componentdesigner::_di_IComponentDesigner());
	void __fastcall GetSelectionList(System::Classes::TList* AList);
	virtual void __fastcall SelectionChanged(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignerSelections ASelection);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	void __fastcall SetSelectionList(System::Classes::TList* AList);
	void __fastcall UpdateSelection(void);
	__property int LockCount = {read=FLockCount, nodefault};
	__property TcxSelectionsChanged OnSelectionsChanged = {read=FOnSelectionsChanged, write=FOnSelectionsChanged};
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TcxDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Designwindows::TDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDesignWindow(HWND ParentWindow) : Designwindows::TDesignWindow(ParentWindow) { }
	
};


class DELPHICLASS TcxGlobalDesignWindow;
class PASCALIMPLEMENTATION TcxGlobalDesignWindow : public TcxDesignWindow
{
	typedef TcxDesignWindow inherited;
	
public:
	virtual void __fastcall SelectionChanged(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignerSelections ASelection);
public:
	/* TcxDesignWindow.Create */ inline __fastcall virtual TcxGlobalDesignWindow(System::Classes::TComponent* AOwner) : TcxDesignWindow(AOwner) { }
	
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TcxGlobalDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGlobalDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : TcxDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGlobalDesignWindow(HWND ParentWindow) : TcxDesignWindow(ParentWindow) { }
	
};


class DELPHICLASS TcxDesignFormEditor;
class PASCALIMPLEMENTATION TcxDesignFormEditor : public TcxDesignWindow
{
	typedef TcxDesignWindow inherited;
	
__published:
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	bool FClosing;
	System::Classes::TComponent* FComponent;
	System::UnicodeString FComponentClassName;
	
protected:
	System::Classes::TPersistent* ComponentProperty;
	System::UnicodeString ComponentPropertyName;
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CloseEditor(void);
	virtual void __fastcall InitFormEditor(void);
	virtual void __fastcall SetComponent(System::Classes::TComponent* AValue);
	virtual void __fastcall SetComponentClassName(const System::UnicodeString AValue);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall UpdateContent(void);
	
public:
	bool __fastcall CanAddComponent(void);
	bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent);
	virtual void __fastcall DesignerClosed(const Designintf::_di_IDesigner ADesigner, bool AGoingDormant);
	virtual void __fastcall DoItemDeleted(System::Classes::TPersistent* AItem);
	virtual void __fastcall DoItemsModified(void);
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, System::Classes::TPersistent* AItem);
	virtual void __fastcall ItemsModified(const Designintf::_di_IDesigner Designer);
	void __fastcall SelectComponent(System::Classes::TPersistent* AComponent);
	virtual void __fastcall SelectComponents(System::Classes::TList* AList, System::Classes::TPersistent* ADefaultComponent);
	void __fastcall ListBoxApplySelection(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TPersistent* ADefaultComponent);
	void __fastcall ListBoxSynchronizeSelection(Vcl::Stdctrls::TListBox* AListBox);
	__property bool Closing = {read=FClosing, nodefault};
	__property System::Classes::TComponent* Component = {read=FComponent, write=SetComponent};
	__property System::UnicodeString ComponentClassName = {read=FComponentClassName, write=SetComponentClassName};
public:
	/* TcxDesignWindow.Create */ inline __fastcall virtual TcxDesignFormEditor(System::Classes::TComponent* AOwner) : TcxDesignWindow(AOwner) { }
	
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TcxDesignFormEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxDesignFormEditor(System::Classes::TComponent* AOwner, int Dummy) : TcxDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDesignFormEditor(HWND ParentWindow) : TcxDesignWindow(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxDesignFormEditorClass;

typedef void __fastcall (__closure *TcxListBoxReindexProc)(System::Classes::TList* AList, int ANewIndex);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxDesignFormEditor* __fastcall ShowFormEditorClass(Designintf::_di_IDesigner ADesigner, System::Classes::TComponent* AComponent, System::Classes::TPersistent* AProperty, const System::UnicodeString APropertyName, TcxDesignFormEditorClass AFormEditorClass)/* overload */;
extern PACKAGE TcxDesignFormEditor* __fastcall ShowFormEditorClass(Designintf::_di_IDesigner ADesigner, System::Classes::TComponent* AComponent, TcxDesignFormEditorClass AFormEditorClass)/* overload */;
extern PACKAGE void __fastcall UpdateDesignFormEditors(System::Classes::TComponent* AComponent);
extern PACKAGE bool __fastcall CanAddComponent(System::Classes::TComponent* AOwner, const Designintf::_di_IDesigner ADesigner = Designintf::_di_IDesigner());
extern PACKAGE bool __fastcall CanDeleteComponent(System::Classes::TComponent* AOwner, System::Classes::TComponent* AComponent, const Designintf::_di_IDesigner ADesigner = Designintf::_di_IDesigner());
extern PACKAGE bool __fastcall CanChangeComponentList(System::Classes::TComponent* AOwner, Designintf::_di_IDesigner ADesigner = Designintf::_di_IDesigner());
extern PACKAGE Designintf::_di_IDesigner __fastcall GetObjectDesigner(System::Classes::TPersistent* AObject);
extern PACKAGE Designintf::_di_IDesignerSelections __fastcall CreateDesignerSelectionList(void);
extern PACKAGE void __fastcall DeleteDesignerSelectionList(Designintf::_di_IDesignerSelections &ASelection);
extern PACKAGE void __fastcall GetSelections(Designintf::_di_IDesigner ADesigner, System::Classes::TList* AList);
extern PACKAGE void __fastcall ConvertSelectionToList(const Designintf::_di_IDesignerSelections ASelectionList, System::Classes::TList* AList);
extern PACKAGE System::Classes::TNotifyEvent __fastcall LockListBox(Vcl::Stdctrls::TListBox* AListBox);
extern PACKAGE void __fastcall UnlockListBox(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TNotifyEvent APrevOnClick);
extern PACKAGE void __fastcall ListBoxSetItemIndex(Vcl::Stdctrls::TListBox* AListBox, int AItemIndex);
extern PACKAGE void __fastcall ListBoxSetSelected(Vcl::Stdctrls::TListBox* AListBox, int AItemIndex, bool ASelected);
extern PACKAGE void __fastcall ListBoxRestoreSelection(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TStringList* &ASelection, int AItemIndex, int ATopIndex);
extern PACKAGE void __fastcall ListBoxSaveSelection(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TStringList* &ASelection, int &AItemIndex, int &ATopIndex);
extern PACKAGE void __fastcall ListBoxRestorePos(Vcl::Stdctrls::TListBox* AListBox, int AItemIndex, int ATopIndex);
extern PACKAGE void __fastcall ListBoxSavePos(Vcl::Stdctrls::TListBox* AListBox, int &AItemIndex, int &ATopIndex);
extern PACKAGE int __fastcall ListBoxGetFirstSelectedIndex(Vcl::Stdctrls::TListBox* AListBox);
extern PACKAGE int __fastcall ListBoxGetLastSelectedIndex(Vcl::Stdctrls::TListBox* AListBox);
extern PACKAGE void __fastcall ListBoxDeleteSelection(Vcl::Stdctrls::TListBox* AListBox, bool ASetFocus, bool AKeepSelection = false);
extern PACKAGE void __fastcall ListBoxGetSelection(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TList* AList);
extern PACKAGE void __fastcall ListBoxLoadCollection(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TCollection* ACollection);
extern PACKAGE void __fastcall ListBoxSelectByObject(Vcl::Stdctrls::TListBox* AListBox, System::TObject* AObject);
extern PACKAGE void __fastcall ListBoxSyncSelection(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TList* AList);
extern PACKAGE void __fastcall ListBoxClearSelection(Vcl::Stdctrls::TListBox* AListBox);
extern PACKAGE void __fastcall ListBoxSelectAll(Vcl::Stdctrls::TListBox* AListBox);
extern PACKAGE void __fastcall ListBoxMoveItems(Vcl::Stdctrls::TListBox* AListBox, int AIndex, int &APrevDragIndex, TcxListBoxReindexProc AReindexProc);
extern PACKAGE void __fastcall ListBoxMoveUpItems(Vcl::Stdctrls::TListBox* AListBox, int &APrevDragIndex, TcxListBoxReindexProc AReindexProc);
extern PACKAGE void __fastcall ListBoxMoveDownItems(Vcl::Stdctrls::TListBox* AListBox, int &APrevDragIndex, TcxListBoxReindexProc AReindexProc);
extern PACKAGE void __fastcall ListBoxDragOver(Vcl::Stdctrls::TListBox* AListBox, System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept, int &APrevDragIndex);
extern PACKAGE void __fastcall ListBoxDragDrop(Vcl::Stdctrls::TListBox* AListBox, System::TObject* Sender, System::TObject* Source, int X, int Y, int &APrevDragIndex, TcxListBoxReindexProc AReindexProc);
extern PACKAGE void __fastcall ListBoxEndDrag(Vcl::Stdctrls::TListBox* AListBox, System::TObject* Sender, System::TObject* Target, int X, int Y, int &APrevDragIndex);
extern PACKAGE Vcl::Menus::TMenuItem* __fastcall CreateMenuItem(System::Classes::TComponent* AOwner, const System::UnicodeString ACaption, System::Classes::TNotifyEvent AOnClick = 0x0, bool AEnabled = true, int ATag = 0xffffffff, bool AChecked = false);
extern PACKAGE void __fastcall MakeColoredControlsOpaque(Vcl::Controls::TControl* ARoot);
}	/* namespace Cxdesignwindows */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDESIGNWINDOWS)
using namespace Cxdesignwindows;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdesignwindowsHPP
