// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditReg.pas' rev: 24.00 (Win32)

#ifndef CxeditregHPP
#define CxeditregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DSDesign.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxFieldsTarget;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFieldsTarget : public Designintf::TDragTarget
{
	typedef Designintf::TDragTarget inherited;
	
protected:
	void __fastcall CreateControls(System::Classes::TList* AFieldList, Dsdesign::TFieldsEditor* AEditor, System::TObject* ATarget, int X, int Y);
	virtual void __fastcall DoCreateFieldControl(Vcl::Controls::TControl* AParent, Vcl::Controls::TControl* AControl, Data::Db::TField* AField);
	Vcl::Controls::TControl* __fastcall GetAllowTarget(Vcl::Controls::TControl* ATarget);
	virtual System::UnicodeString __fastcall GetControlClass(Dsdesign::TFieldsEditor* AEditor, Data::Db::TField* AField);
	bool __fastcall NeedCreateCaption(Vcl::Controls::TControl* ATarget);
	
public:
	virtual void __fastcall DragDrop(System::TObject* Target, System::TObject* Source, int X, int Y);
	virtual bool __fastcall DragOver(System::TObject* Target, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State);
public:
	/* TDragTarget.Create */ inline __fastcall virtual TcxFieldsTarget(const Designintf::_di_IDesigner ADesigner) : Designintf::TDragTarget(ADesigner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFieldsTarget(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (*TcxGetControlClassNameProc)(Data::Db::TField* AField, /* out */ System::UnicodeString &AClassName);

typedef System::TMetaClass* TcxFieldsTargetClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxGetControlClassNameProc cxGetControlClassNameProc;
extern PACKAGE void __fastcall cxRegisterDragTarget(TcxFieldsTargetClass ATargetClass);
extern PACKAGE void __fastcall cxUnregisterDragTarget(TcxFieldsTargetClass ATargetClass);
extern PACKAGE Vcl::Controls::TControl* __fastcall cxCreateFieldControl(Designintf::_di_IDesigner ADesigner, Data::Db::TField* AField, Vcl::Controls::TWinControl* AParent, int X, int Y);
extern PACKAGE void __fastcall Register(void);
}	/* namespace Cxeditreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITREG)
using namespace Cxeditreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditregHPP
