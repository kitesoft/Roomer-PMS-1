// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridFooterPopupMenuItems.pas' rev: 24.00 (Win64)

#ifndef CxgridfooterpopupmenuitemsHPP
#define CxgridfooterpopupmenuitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxGridMenuOperations.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridfooterpopupmenuitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridFooterSummaryOperation;
class PASCALIMPLEMENTATION TcxGridFooterSummaryOperation : public Cxgridmenuoperations::TcxGridTableColumnMenuOperation
{
	typedef Cxgridmenuoperations::TcxGridTableColumnMenuOperation inherited;
	
private:
	Cxcustomdata::TcxSummaryKind FKind;
	Cxgridtableview::TcxGridFooterViewInfo* __fastcall GetFooterViewInfo(void);
	bool __fastcall GetMultipleSummaries(void);
	Cxcustomdata::TcxDataSummaryItems* __fastcall GetSummaryItems(void);
	void __fastcall SetKind(Cxcustomdata::TcxSummaryKind Value);
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetDown(void);
	virtual bool __fastcall GetEnabled(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	__property Cxgridtableview::TcxGridFooterViewInfo* FooterViewInfo = {read=GetFooterViewInfo};
	__property bool MultipleSummaries = {read=GetMultipleSummaries, nodefault};
	__property Cxcustomdata::TcxDataSummaryItems* SummaryItems = {read=GetSummaryItems};
	
public:
	__property Cxcustomdata::TcxSummaryKind Kind = {read=FKind, write=SetKind, nodefault};
public:
	/* TcxGridPopupMenuOperation.Create */ inline __fastcall virtual TcxGridFooterSummaryOperation(void) : Cxgridmenuoperations::TcxGridTableColumnMenuOperation() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFooterSummaryOperation(void) { }
	
};


class DELPHICLASS TcxGridFooterPopupMenuOperations;
class PASCALIMPLEMENTATION TcxGridFooterPopupMenuOperations : public Cxgridmenuoperations::TcxGridPopupMenuOperations
{
	typedef Cxgridmenuoperations::TcxGridPopupMenuOperations inherited;
	
protected:
	virtual void __fastcall AddItems(void);
public:
	/* TcxGridPopupMenuOperations.Create */ inline __fastcall virtual TcxGridFooterPopupMenuOperations(void) : Cxgridmenuoperations::TcxGridPopupMenuOperations() { }
	/* TcxGridPopupMenuOperations.Destroy */ inline __fastcall virtual ~TcxGridFooterPopupMenuOperations(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridfooterpopupmenuitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDFOOTERPOPUPMENUITEMS)
using namespace Cxgridfooterpopupmenuitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridfooterpopupmenuitemsHPP
