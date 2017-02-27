// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBFilter.pas' rev: 24.00 (Win64)

#ifndef CxdbfilterHPP
#define CxdbfilterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbfilter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxFilterSQLNullOperator;
class PASCALIMPLEMENTATION TcxFilterSQLNullOperator : public Cxfilter::TcxFilterNullOperator
{
	typedef Cxfilter::TcxFilterNullOperator inherited;
	
public:
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterSQLNullOperator(Cxfilter::TcxFilterCriteriaItem* ACriteriaItem) : Cxfilter::TcxFilterNullOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterSQLNullOperator(void) { }
	
};


class DELPHICLASS TcxFilterSQLNotNullOperator;
class PASCALIMPLEMENTATION TcxFilterSQLNotNullOperator : public Cxfilter::TcxFilterNotNullOperator
{
	typedef Cxfilter::TcxFilterNotNullOperator inherited;
	
public:
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterSQLNotNullOperator(Cxfilter::TcxFilterCriteriaItem* ACriteriaItem) : Cxfilter::TcxFilterNotNullOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterSQLNotNullOperator(void) { }
	
};


class DELPHICLASS TcxDBFilterOperatorAdapter;
class PASCALIMPLEMENTATION TcxDBFilterOperatorAdapter : public Cxdb::TcxDBAdapterItem
{
	typedef Cxdb::TcxDBAdapterItem inherited;
	
public:
	virtual void __fastcall PrepareOperatorClass(System::TObject* ASender, Data::Db::TDataSet* ADataSet, Cxfilter::TcxFilterOperatorClass &AOperatorClass);
public:
	/* TcxDBAdapterItem.Create */ inline __fastcall virtual TcxDBFilterOperatorAdapter(Cxdb::TDataSetClass ADataSetClass) : Cxdb::TcxDBAdapterItem(ADataSetClass) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDBFilterOperatorAdapter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxdb::TcxDBAdapterList* cxFilterOperatorAdapters;
extern PACKAGE TcxDBFilterOperatorAdapter* __fastcall cxGetFilterOperatorAdapter(Data::Db::TDataSet* ADataSet);
}	/* namespace Cxdbfilter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBFILTER)
using namespace Cxdbfilter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbfilterHPP
