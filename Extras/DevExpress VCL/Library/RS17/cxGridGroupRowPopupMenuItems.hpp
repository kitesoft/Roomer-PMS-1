// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridGroupRowPopupMenuItems.pas' rev: 24.00 (Win32)

#ifndef CxgridgrouprowpopupmenuitemsHPP
#define CxgridgrouprowpopupmenuitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxGridMenuOperations.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridgrouprowpopupmenuitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridGroupRowPopupMenuOperation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridGroupRowPopupMenuOperation : public Cxgridmenuoperations::TcxGridTablePopupMenuOperation
{
	typedef Cxgridmenuoperations::TcxGridTablePopupMenuOperation inherited;
	
private:
	Cxgridtableview::TcxGridGroupRow* __fastcall GetHitRow(void);
	
public:
	__property Cxgridtableview::TcxGridGroupRow* HitRow = {read=GetHitRow};
public:
	/* TcxGridPopupMenuOperation.Create */ inline __fastcall virtual TcxGridGroupRowPopupMenuOperation(void) : Cxgridmenuoperations::TcxGridTablePopupMenuOperation() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupRowPopupMenuOperation(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridGroupRowSortByGroupValuesOperation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridGroupRowSortByGroupValuesOperation : public TcxGridGroupRowPopupMenuOperation
{
	typedef TcxGridGroupRowPopupMenuOperation inherited;
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual bool __fastcall GetDown(void);
	
public:
	__fastcall virtual TcxGridGroupRowSortByGroupValuesOperation(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupRowSortByGroupValuesOperation(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridGroupRowSortBySummaryCaptionOperation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridGroupRowSortBySummaryCaptionOperation : public TcxGridGroupRowPopupMenuOperation
{
	typedef TcxGridGroupRowPopupMenuOperation inherited;
	
public:
	__fastcall virtual TcxGridGroupRowSortBySummaryCaptionOperation(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupRowSortBySummaryCaptionOperation(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridGroupRowSortBySummaryOperation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridGroupRowSortBySummaryOperation : public TcxGridGroupRowPopupMenuOperation
{
	typedef TcxGridGroupRowPopupMenuOperation inherited;
	
private:
	Cxcustomdata::TcxDataSummaryItem* FSummaryItem;
	void __fastcall SetSummaryItem(Cxcustomdata::TcxDataSummaryItem* Value);
	
protected:
	virtual void __fastcall Execute(System::TObject* Sender);
	virtual System::UnicodeString __fastcall GetCaption(void);
	virtual bool __fastcall GetDown(void);
	virtual System::UnicodeString __fastcall GetImageResourceName(void);
	
public:
	__fastcall virtual TcxGridGroupRowSortBySummaryOperation(void);
	__property Cxcustomdata::TcxDataSummaryItem* SummaryItem = {read=FSummaryItem, write=SetSummaryItem};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridGroupRowSortBySummaryOperation(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridGroupRowPopupMenuOperations;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridGroupRowPopupMenuOperations : public Cxgridmenuoperations::TcxGridPopupMenuOperations
{
	typedef Cxgridmenuoperations::TcxGridPopupMenuOperations inherited;
	
private:
	Cxgridtableview::TcxGridGroupRow* FGroupRow;
	void __fastcall SetGroupRow(Cxgridtableview::TcxGridGroupRow* Value);
	
protected:
	virtual void __fastcall AddItems(void);
	
public:
	virtual bool __fastcall CanProcess(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	__property Cxgridtableview::TcxGridGroupRow* GroupRow = {read=FGroupRow, write=SetGroupRow};
public:
	/* TcxGridPopupMenuOperations.Create */ inline __fastcall virtual TcxGridGroupRowPopupMenuOperations(void) : Cxgridmenuoperations::TcxGridPopupMenuOperations() { }
	/* TcxGridPopupMenuOperations.Destroy */ inline __fastcall virtual ~TcxGridGroupRowPopupMenuOperations(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridgrouprowpopupmenuitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDGROUPROWPOPUPMENUITEMS)
using namespace Cxgridgrouprowpopupmenuitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridgrouprowpopupmenuitemsHPP
