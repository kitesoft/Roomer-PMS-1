// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSReg.pas' rev: 24.00 (Win32)

#ifndef DxpsregHPP
#define DxpsregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <PicEdit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSPrVw.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxReportLinkComponentPropertyEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxReportLinkComponentPropertyEditor : public Designeditors::TComponentProperty
{
	typedef Designeditors::TComponentProperty inherited;
	
private:
	System::Classes::TStringList* FComponents;
	Dxpscore::TBasedxReportLink* __fastcall GetReportLink(void);
	
protected:
	void __fastcall AddComponent(const System::UnicodeString AName);
	virtual void __fastcall GetComponents(void);
	virtual bool __fastcall IsComponentValid(System::Classes::TComponent* AComponent);
	
public:
	__fastcall virtual ~TdxReportLinkComponentPropertyEditor(void);
	virtual void __fastcall Initialize(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
	__property Dxpscore::TBasedxReportLink* ReportLink = {read=GetReportLink};
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxReportLinkComponentPropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TComponentProperty(ADesigner, APropCount) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define dxPSProductName L"ExpressPrinting System"
#define dxPSProductPage L"ExpressPrinting System"
static const bool dxPSAutoFillReportLinkUnits = true;
extern PACKAGE void __fastcall Register(void);
extern PACKAGE void __fastcall dxPSRegisterReportLinkUnit(const System::UnicodeString AUnitName, Dxpscore::TdxReportLinkClass ALinkClass);
}	/* namespace Dxpsreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSREG)
using namespace Dxpsreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsregHPP
