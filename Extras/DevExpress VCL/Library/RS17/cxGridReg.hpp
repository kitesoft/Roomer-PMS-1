// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridReg.pas' rev: 24.00 (Win32)

#ifndef CxgridregHPP
#define CxgridregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignMenus.hpp>	// Pascal unit
#include <VCLEditors.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomGridEditor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridEditor : public Dxcorereg::TdxComponentEditor
{
	typedef Dxcorereg::TdxComponentEditor inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetProductName(void);
public:
	/* TdxComponentEditor.Create */ inline __fastcall virtual TcxCustomGridEditor(System::Classes::TComponent* AComponent, Designintf::_di_IDesigner ADesigner) : Dxcorereg::TdxComponentEditor(AComponent, ADesigner) { }
	/* TdxComponentEditor.Destroy */ inline __fastcall virtual ~TcxCustomGridEditor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableItemProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableItemProperty : public Designeditors::TComponentProperty
{
	typedef Designeditors::TComponentProperty inherited;
	
protected:
	Cxgridcustomview::TcxCustomGridView* __fastcall GetGridView(void);
	virtual void __fastcall GetGridViewItemNames(Cxgridcustomview::TcxCustomGridView* AGridView, System::Classes::TGetStrProc Proc);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall InternalGetGridView(System::Classes::TPersistent* APersistent) = 0 ;
	
public:
	virtual void __fastcall GetValues(System::Classes::TGetStrProc Proc);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxCustomGridTableItemProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TComponentProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxCustomGridTableItemProperty(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridTableSummaryItemColumnProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTableSummaryItemColumnProperty : public TcxCustomGridTableItemProperty
{
	typedef TcxCustomGridTableItemProperty inherited;
	
protected:
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall InternalGetGridView(System::Classes::TPersistent* APersistent);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxGridTableSummaryItemColumnProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : TcxCustomGridTableItemProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxGridTableSummaryItemColumnProperty(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define cxGridProductName L"ExpressQuantumGrid Suite"
extern PACKAGE void __fastcall Register(void);
}	/* namespace Cxgridreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDREG)
using namespace Cxgridreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridregHPP
