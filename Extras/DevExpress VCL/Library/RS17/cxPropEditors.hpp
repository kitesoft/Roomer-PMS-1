// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPropEditors.pas' rev: 24.00 (Win32)

#ifndef CxpropeditorsHPP
#define CxpropeditorsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpropeditors
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxNestedEventProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNestedEventProperty : public Designeditors::TMethodProperty
{
	typedef Designeditors::TMethodProperty inherited;
	
protected:
	virtual System::Classes::TPersistent* __fastcall GetInstance(void) = 0 ;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetName(void);
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
	virtual System::UnicodeString __fastcall GetValue(void);
	__property System::Classes::TPersistent* Instance = {read=GetInstance};
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxNestedEventProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TMethodProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxNestedEventProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxNestedParentElementEventProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNestedParentElementEventProperty : public Designeditors::TNestedProperty
{
	typedef Designeditors::TNestedProperty inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	System::Typinfo::TPropInfo *FPropInfo;
	Designeditors::TPropertyEditor* FParent;
	System::Classes::TPersistent* __fastcall GetInstance(void);
	
protected:
	__fastcall TcxNestedParentElementEventProperty(Designeditors::TPropertyEditor* Parent, System::Classes::TPersistent* AOwner, System::Typinfo::PPropInfo APropInfo);
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual System::UnicodeString __fastcall GetName(void);
	__property System::Classes::TPersistent* Instance = {read=GetInstance};
public:
	/* TNestedProperty.Destroy */ inline __fastcall virtual ~TcxNestedParentElementEventProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxNestedElementEventProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNestedElementEventProperty : public Designeditors::TNestedProperty
{
	typedef Designeditors::TNestedProperty inherited;
	
private:
	Designeditors::TPropertyEditor* FParent;
	System::Typinfo::TPropInfo *FPropInfo;
	System::UnicodeString __fastcall GetTrimmedEventName(void);
	System::UnicodeString __fastcall GetPersistentClassNames(void);
	System::Classes::TPersistent* __fastcall GetInstance(void);
	
protected:
	__fastcall TcxNestedElementEventProperty(Designeditors::TPropertyEditor* Parent, System::Typinfo::PPropInfo APropInfo);
	virtual System::UnicodeString __fastcall GetFormMethodName(void);
	__property System::Classes::TPersistent* Instance = {read=GetInstance};
	
public:
	virtual bool __fastcall AllEqual(void);
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual int __fastcall GetEditLimit(void);
	virtual System::UnicodeString __fastcall GetName(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString AValue)/* overload */;
public:
	/* TNestedProperty.Destroy */ inline __fastcall virtual ~TcxNestedElementEventProperty(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetValue(const System::WideString Value){ Designeditors::TPropertyEditor::SetValue(Value); }
	
};

#pragma pack(pop)

class DELPHICLASS TImageIndexProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TImageIndexProperty : public Designeditors::TIntegerProperty
{
	typedef Designeditors::TIntegerProperty inherited;
	
public:
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void) = 0 ;
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value)/* overload */;
	virtual void __fastcall ListMeasureHeight(const System::UnicodeString Value, Vcl::Graphics::TCanvas* ACanvas, int &AHeight);
	virtual void __fastcall ListMeasureWidth(const System::UnicodeString Value, Vcl::Graphics::TCanvas* ACanvas, int &AWidth);
	virtual void __fastcall ListDrawValue(const System::UnicodeString Value, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, bool ASelected);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TImageIndexProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TIntegerProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TImageIndexProperty(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetValue(const System::WideString Value){ Designeditors::TPropertyEditor::SetValue(Value); }
	
private:
	void *__ICustomPropertyListDrawing;	/* Vcleditors::ICustomPropertyListDrawing */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {BE2B8CF7-DDCA-4D4B-BE26-2396B969F8E0}
	operator Vcleditors::_di_ICustomPropertyListDrawing()
	{
		Vcleditors::_di_ICustomPropertyListDrawing intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Vcleditors::ICustomPropertyListDrawing*(void) { return (Vcleditors::ICustomPropertyListDrawing*)&__ICustomPropertyListDrawing; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TcxStyleControllerStyleProperty;
class PASCALIMPLEMENTATION TcxStyleControllerStyleProperty : public Designeditors::TClassProperty
{
	typedef Designeditors::TClassProperty inherited;
	
private:
	Designintf::TGetPropProc FProc;
	void __fastcall GetPropProc(const Designintf::_di_IProperty Prop);
	
protected:
	virtual Cxcontainer::TcxContainerStyle* __fastcall GetStyle(void);
	virtual bool __fastcall IsPropertyVisible(const System::UnicodeString APropertyName);
	
public:
	virtual void __fastcall GetProperties(Designintf::TGetPropProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxStyleControllerStyleProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxStyleControllerStyleProperty(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ObjectInspectorCollapseProperty(void);
}	/* namespace Cxpropeditors */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPROPEDITORS)
using namespace Cxpropeditors;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpropeditorsHPP
