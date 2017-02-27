// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSTCLnkReg.pas' rev: 24.00 (Win32)

#ifndef DxpstclnkregHPP
#define DxpstclnkregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSReg.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpstclnkreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxTeeChartReportLinkGraphicClassNamePropertyEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTeeChartReportLinkGraphicClassNamePropertyEditor : public Designeditors::TStringProperty
{
	typedef Designeditors::TStringProperty inherited;
	
public:
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TdxTeeChartReportLinkGraphicClassNamePropertyEditor(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TStringProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TdxTeeChartReportLinkGraphicClassNamePropertyEditor(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxpstclnkreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSTCLNKREG)
using namespace Dxpstclnkreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpstclnkregHPP
