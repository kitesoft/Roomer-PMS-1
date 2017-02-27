// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxIBXAdapters.pas' rev: 24.00 (Win64)

#ifndef CxibxadaptersHPP
#define CxibxadaptersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <IBSQL.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDBFilter.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxibxadapters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxIBXProviderDetailFilterAdapter;
class PASCALIMPLEMENTATION TcxIBXProviderDetailFilterAdapter : public Cxdbdata::TcxDBProviderDetailFilterAdapter
{
	typedef Cxdbdata::TcxDBProviderDetailFilterAdapter inherited;
	
protected:
	System::Variant __fastcall GetParamValues(Ibsql::TIBXSQLDA* ASQLParams);
	void __fastcall SetParamValues(Ibsql::TIBXSQLDA* ASQLParams, const System::Variant &AValues);
	
public:
	virtual bool __fastcall IsCurrentQuery(Data::Db::TDataSet* ADataSet, const System::UnicodeString AParamNames, const System::Variant &AParamValues);
	virtual void __fastcall ReopenSQL(Data::Db::TDataSet* ADataSet, const System::UnicodeString AParamNames, const System::Variant &AParamValues, bool &AReopened);
public:
	/* TcxDBAdapterItem.Create */ inline __fastcall virtual TcxIBXProviderDetailFilterAdapter(Cxdb::TDataSetClass ADataSetClass) : Cxdbdata::TcxDBProviderDetailFilterAdapter(ADataSetClass) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxIBXProviderDetailFilterAdapter(void) { }
	
};


class DELPHICLASS TcxIBXFilterOperatorAdapter;
class PASCALIMPLEMENTATION TcxIBXFilterOperatorAdapter : public Cxdbfilter::TcxDBFilterOperatorAdapter
{
	typedef Cxdbfilter::TcxDBFilterOperatorAdapter inherited;
	
public:
	virtual void __fastcall PrepareOperatorClass(System::TObject* ASender, Data::Db::TDataSet* ADataSet, Cxfilter::TcxFilterOperatorClass &AOperatorClass);
public:
	/* TcxDBAdapterItem.Create */ inline __fastcall virtual TcxIBXFilterOperatorAdapter(Cxdb::TDataSetClass ADataSetClass) : Cxdbfilter::TcxDBFilterOperatorAdapter(ADataSetClass) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxIBXFilterOperatorAdapter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxibxadapters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXIBXADAPTERS)
using namespace Cxibxadapters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxibxadaptersHPP
