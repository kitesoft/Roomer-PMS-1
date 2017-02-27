// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridUIBandedTableHelper.pas' rev: 24.00 (Win64)

#ifndef CxgriduibandedtablehelperHPP
#define CxgriduibandedtablehelperHPP

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
#include <cxGridUICustomTableHelper.hpp>	// Pascal unit
#include <cxGridUITableHelper.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriduibandedtablehelper
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridBandedTableViewOperationHelper;
class PASCALIMPLEMENTATION TcxGridBandedTableViewOperationHelper : public Cxgriduitablehelper::TcxGridTableViewOperationHelper
{
	typedef Cxgriduitablehelper::TcxGridTableViewOperationHelper inherited;
	
protected:
	virtual void __fastcall RegisterOperations(void);
	void __fastcall DoShowBands(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
public:
	/* TcxCustomGridViewOperationHelper.Create */ inline __fastcall virtual TcxGridBandedTableViewOperationHelper(void) : Cxgriduitablehelper::TcxGridTableViewOperationHelper() { }
	/* TcxCustomGridViewOperationHelper.Destroy */ inline __fastcall virtual ~TcxGridBandedTableViewOperationHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriduibandedtablehelper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDUIBANDEDTABLEHELPER)
using namespace Cxgriduibandedtablehelper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriduibandedtablehelperHPP
