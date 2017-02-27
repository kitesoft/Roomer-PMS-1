// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridUICustomTableHelper.pas' rev: 24.00 (Win64)

#ifndef CxgriduicustomtablehelperHPP
#define CxgriduicustomtablehelperHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridUIHelper.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriduicustomtablehelper
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridCustomTableViewOperationHelper;
class PASCALIMPLEMENTATION TcxGridCustomTableViewOperationHelper : public Cxgriduihelper::TcxCustomGridViewOperationHelper
{
	typedef Cxgriduihelper::TcxCustomGridViewOperationHelper inherited;
	
protected:
	virtual void __fastcall RegisterOperations(void);
	void __fastcall DoCopyToClipboard(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowEditButtons(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
public:
	/* TcxCustomGridViewOperationHelper.Create */ inline __fastcall virtual TcxGridCustomTableViewOperationHelper(void) : Cxgriduihelper::TcxCustomGridViewOperationHelper() { }
	/* TcxCustomGridViewOperationHelper.Destroy */ inline __fastcall virtual ~TcxGridCustomTableViewOperationHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriduicustomtablehelper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDUICUSTOMTABLEHELPER)
using namespace Cxgriduicustomtablehelper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriduicustomtablehelperHPP
