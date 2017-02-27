// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCoreReg.pas' rev: 24.00 (Win32)

#ifndef DxcoreregHPP
#define DxcoreregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignConst.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcorereg
{
//-- type declarations -------------------------------------------------------
typedef Designmenus::_di_IMenuItem TDesignMenuItem;

class DELPHICLASS TdxComponentEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxComponentEditor : public Designeditors::TComponentEditor
{
	typedef Designeditors::TComponentEditor inherited;
	
private:
	int __fastcall GetBaseVerbCount(void);
	void __fastcall AssignClick(System::TObject* Sender);
	void __fastcall CheckObjectsForAssign(const System::UnicodeString AObjectName);
	void __fastcall UpdateAssignableList(void);
	
protected:
	System::Classes::TStringList* FAssignableObjects;
	virtual bool __fastcall IsAssignable(void);
	virtual bool __fastcall IsObjectAssignable(System::TObject* AObject);
	virtual void __fastcall DoAssign(System::TObject* AObject);
	virtual System::UnicodeString __fastcall GetAssignItemCaption(void);
	virtual System::TClass __fastcall GetAssignTypeClass(void);
	virtual System::UnicodeString __fastcall GetProductVersion(void);
	virtual System::UnicodeString __fastcall GetProductName(void);
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
	
public:
	__fastcall virtual TdxComponentEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner);
	__fastcall virtual ~TdxComponentEditor(void);
	virtual System::UnicodeString __fastcall GetVerb(int Index);
	virtual int __fastcall GetVerbCount(void);
	virtual void __fastcall ExecuteVerb(int Index);
	virtual void __fastcall PrepareItem(int Index, const Designmenus::_di_IMenuItem AItem);
};

#pragma pack(pop)

class DELPHICLASS TdxDefaultBooleanPropertyEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxDefaultBooleanPropertyEditor : public Designeditors::TEnumProperty
{
	typedef Designeditors::TEnumProperty inherited;
	
protected:
	System::Types::TRect __fastcall GetCheckBoxBounds(const System::Types::TRect &ARect);
	virtual bool __fastcall GetDefaultValue(void) = 0 ;
	System::UnicodeString __fastcall GetDisplayText(Dxcore::TdxDefaultBoolean Value);
	void __fastcall PaintCheckbox(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, bool ASelected);
	
public:
	void __fastcall PropDrawName(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, bool ASelected);
	void __fastcall PropDrawValue(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, bool ASelected);
	System::Types::TRect __fastcall PropDrawNameRect(const System::Types::TRect &ARect);
	System::Types::TRect __fastcall PropDrawValueRect(const System::Types::TRect &ARect);
	void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y, bool InNameRect, const System::Types::TRect &ItemRect, bool &Handled);
	void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y, bool InNameRect, const System::Types::TRect &ItemRect, bool &Handled);
	void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y, bool InNameRect, const System::Types::TRect &ItemRect, bool &Handled);
	void __fastcall HintShow(Vcl::Controls::THintInfo &HintInfo, bool InNameRect, const System::Types::TRect &ItemRect, bool &Handled);
	virtual System::UnicodeString __fastcall GetValue(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	virtual void __fastcall SetValue(const System::UnicodeString Value)/* overload */;
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxDefaultBooleanPropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TEnumProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxDefaultBooleanPropertyEditor(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  SetValue(const System::WideString Value){ Designeditors::TPropertyEditor::SetValue(Value); }
	
private:
	void *__ICustomPropertyMessage;	/* Vcleditors::ICustomPropertyMessage */
	void *__ICustomPropertyDrawing80;	/* Vcleditors::ICustomPropertyDrawing80 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {60E3EB3A-23DD-459C-8936-0607A27D11A8}
	operator Vcleditors::_di_ICustomPropertyMessage()
	{
		Vcleditors::_di_ICustomPropertyMessage intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Vcleditors::ICustomPropertyMessage*(void) { return (Vcleditors::ICustomPropertyMessage*)&__ICustomPropertyMessage; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73100176-DF0B-4900-AA52-4E67D7D04895}
	operator Vcleditors::_di_ICustomPropertyDrawing80()
	{
		Vcleditors::_di_ICustomPropertyDrawing80 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Vcleditors::ICustomPropertyDrawing80*(void) { return (Vcleditors::ICustomPropertyDrawing80*)&__ICustomPropertyDrawing80; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E1A50419-1288-4B26-9EFA-6608A35F0824}
	operator Vcleditors::_di_ICustomPropertyDrawing()
	{
		Vcleditors::_di_ICustomPropertyDrawing intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Vcleditors::ICustomPropertyDrawing*(void) { return (Vcleditors::ICustomPropertyDrawing*)&__ICustomPropertyDrawing80; }
	#endif
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define dxCoreLibraryProductPage L"DevExpress"
#define dxCompanyName L"Developer Express Inc."
#define dxCompanyURL L"www.devexpress.com"
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxcorereg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCOREREG)
using namespace Dxcorereg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcoreregHPP
