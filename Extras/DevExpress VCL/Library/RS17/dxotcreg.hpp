// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxotcreg.pas' rev: 24.00 (Win32)

#ifndef DxotcregHPP
#define DxotcregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <dxorgchr.hpp>	// Pascal unit
#include <dxorgced.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxotcreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxOCCustomEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOCCustomEditor : public Dxcorereg::TdxComponentEditor
{
	typedef Dxcorereg::TdxComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetProductName(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxOCCustomEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxcorereg::TdxComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxOCCustomEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxOCEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOCEditor : public TdxOCCustomEditor
{
	typedef TdxOCCustomEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall InternalGetVerb(int AIndex);
	virtual int __fastcall InternalGetVerbCount(void);
	virtual void __fastcall InternalExecuteVerb(int AIndex);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TdxOCEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : TdxOCCustomEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TdxOCEditor(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define dxOCProductName L"ExpressOrgChart"
#define dxOCProductPage L"ExpressOrgChart"
extern PACKAGE void __fastcall Register(void);
}	/* namespace Dxotcreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXOTCREG)
using namespace Dxotcreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxotcregHPP
