// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridUITableHelper.pas' rev: 24.00 (Win32)

#ifndef CxgriduitablehelperHPP
#define CxgriduitablehelperHPP

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

//-- user supplied -----------------------------------------------------------

namespace Cxgriduitablehelper
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridTableViewOperationHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTableViewOperationHelper : public Cxgriduicustomtablehelper::TcxGridCustomTableViewOperationHelper
{
	typedef Cxgriduicustomtablehelper::TcxGridCustomTableViewOperationHelper inherited;
	
protected:
	virtual void __fastcall RegisterOperations(void);
	void __fastcall DoShowColumnsCustomizing(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowGroupingPanel(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowSummaryFooter(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowGrid(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoColumnAutoWidth(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowPreview(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowHeaders(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowColumnCustomize(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoInvertSelect(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	void __fastcall DoShowIndicator(Cxgriduihelper::TcxCustomGridOperationHelperParameters* const AParameter);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
	virtual bool __fastcall IsOperationEnabled(Cxgridcustomview::TcxCustomGridView* AView, int AOperationIndex);
public:
	/* TcxCustomGridViewOperationHelper.Create */ inline __fastcall virtual TcxGridTableViewOperationHelper(void) : Cxgriduicustomtablehelper::TcxGridCustomTableViewOperationHelper() { }
	/* TcxCustomGridViewOperationHelper.Destroy */ inline __fastcall virtual ~TcxGridTableViewOperationHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriduitablehelper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDUITABLEHELPER)
using namespace Cxgriduitablehelper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriduitablehelperHPP
