// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxInplaceContainerReg.pas' rev: 24.00 (Win32)

#ifndef CxinplacecontainerregHPP
#define CxinplacecontainerregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxEditPropEditors.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxinplacecontainerreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TItemDataBindingAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TItemDataBindingAccess : public Cxinplacecontainer::TcxItemDataBinding
{
	typedef Cxinplacecontainer::TcxItemDataBinding inherited;
	
public:
	/* TcxCustomItemDataBinding.Create */ inline __fastcall virtual TItemDataBindingAccess(System::Classes::TPersistent* AOwner) : Cxinplacecontainer::TcxItemDataBinding(AOwner) { }
	/* TcxCustomItemDataBinding.Destroy */ inline __fastcall virtual ~TItemDataBindingAccess(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxInplaceEditContainerPropertiesEventsProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInplaceEditContainerPropertiesEventsProperty : public Cxpropeditors::TcxNestedEventProperty
{
	typedef Cxpropeditors::TcxNestedEventProperty inherited;
	
protected:
	virtual System::Classes::TPersistent* __fastcall GetInstance(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxInplaceEditContainerPropertiesEventsProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TcxNestedEventProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxInplaceEditContainerPropertiesEventsProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxInplaceEditContainerPropertiesProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInplaceEditContainerPropertiesProperty : public Designeditors::TClassProperty
{
	typedef Designeditors::TClassProperty inherited;
	
protected:
	bool __fastcall HasSubProperties(void);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value)/* overload */;
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxInplaceEditContainerPropertiesProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxInplaceEditContainerPropertiesProperty(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetValue(const System::WideString Value){ Designeditors::TPropertyEditor::SetValue(Value); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDesignSelectionHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDesignSelectionHelper : public Cxinplacecontainer::TcxCustomDesignSelectionHelper
{
	typedef Cxinplacecontainer::TcxCustomDesignSelectionHelper inherited;
	
private:
	Cxdesignwindows::TcxDesignHelper* FDesignHelper;
	
protected:
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, System::Classes::TPersistent* AItem);
	void __fastcall ItemInserted(const Designintf::_di_IDesigner ADesigner, System::Classes::TPersistent* AItem);
	void __fastcall ItemsModified(const Designintf::_di_IDesigner ADesigner);
	void __fastcall SelectionChanged(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignerSelections ASelection);
	void __fastcall DesignerOpened(const Designintf::_di_IDesigner ADesigner, bool AResurrecting);
	void __fastcall DesignerClosed(const Designintf::_di_IDesigner ADesigner, bool AGoingDormant);
	
public:
	__fastcall virtual TcxDesignSelectionHelper(Cxinplacecontainer::TcxEditingControl* AControl);
	__fastcall virtual ~TcxDesignSelectionHelper(void);
	virtual bool __fastcall IsObjectSelected(System::Classes::TPersistent* AObject);
	virtual void __fastcall Select(System::Classes::TPersistent* AObject, System::Classes::TShiftState AShift);
	virtual void __fastcall SetSelection(System::Classes::TList* AList);
	virtual void __fastcall UnselectObject(System::Classes::TPersistent* AObject);
private:
	void *__IDesignNotification;	/* Designintf::IDesignNotification */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E8C9F739-5601-4ADD-9D95-594132D4CEFD}
	operator Designintf::_di_IDesignNotification()
	{
		Designintf::_di_IDesignNotification intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Designintf::IDesignNotification*(void) { return (Designintf::IDesignNotification*)&__IDesignNotification; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IDesignNotification; }
	#endif
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);
}	/* namespace Cxinplacecontainerreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXINPLACECONTAINERREG)
using namespace Cxinplacecontainerreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxinplacecontainerregHPP
