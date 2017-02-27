// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridUICardHelper.pas' rev: 24.00 (Win64)

#ifndef CxgriduicardhelperHPP
#define CxgriduicardhelperHPP

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
#include <cxGridCardView.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriduicardhelper
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridCardViewOperationHelper;
class PASCALIMPLEMENTATION TcxGridCardViewOperationHelper : public Cxgriduicustomtablehelper::TcxGridCustomTableViewOperationHelper
{
	typedef Cxgriduicustomtablehelper::TcxGridCustomTableViewOperationHelper inherited;
	
protected:
	Cxgridcardview::TcxGridCardView* __fastcall GetCardViewFromParameter(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	virtual void __fastcall RegisterOperations(void);
	void __fastcall DoLayoutDirection(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowColumnsCustomizing(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
public:
	/* TcxCustomGridViewOperationHelper.Create */ inline __fastcall virtual TcxGridCardViewOperationHelper(void) : Cxgriduicustomtablehelper::TcxGridCustomTableViewOperationHelper() { }
	/* TcxCustomGridViewOperationHelper.Destroy */ inline __fastcall virtual ~TcxGridCardViewOperationHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriduicardhelper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDUICARDHELPER)
using namespace Cxgriduicardhelper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriduicardhelperHPP
