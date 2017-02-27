// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulercxGridConnectionReg.pas' rev: 24.00 (Win32)

#ifndef CxschedulercxgridconnectionregHPP
#define CxschedulercxgridconnectionregHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <cxSchedulercxGridConnection.hpp>	// Pascal unit
#include <dxCoreReg.hpp>	// Pascal unit
#include <cxSchedulerReg.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulercxgridconnectionreg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerGridConnectionGridPopupMenuEventsProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerGridConnectionGridPopupMenuEventsProperty : public Cxpropeditors::TcxNestedEventProperty
{
	typedef Cxpropeditors::TcxNestedEventProperty inherited;
	
protected:
	virtual System::Classes::TPersistent* __fastcall GetInstance(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxSchedulerGridConnectionGridPopupMenuEventsProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Cxpropeditors::TcxNestedEventProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxSchedulerGridConnectionGridPopupMenuEventsProperty(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall Register(void);
}	/* namespace Cxschedulercxgridconnectionreg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERCXGRIDCONNECTIONREG)
using namespace Cxschedulercxgridconnectionreg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulercxgridconnectionregHPP
