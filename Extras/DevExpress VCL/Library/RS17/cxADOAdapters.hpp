// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxADOAdapters.pas' rev: 24.00 (Win32)

#ifndef CxadoadaptersHPP
#define CxadoadaptersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDBFilter.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxadoadapters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxADOProviderDetailFilterAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxADOProviderDetailFilterAdapter : public Cxdbdata::TcxDBProviderDetailFilterAdapter
{
	typedef Cxdbdata::TcxDBProviderDetailFilterAdapter inherited;
	
public:
	virtual bool __fastcall IsCurrentQuery(Data::Db::TDataSet* ADataSet, const System::UnicodeString AParamNames, const System::Variant &AParamValues);
	virtual void __fastcall ReopenSQL(Data::Db::TDataSet* ADataSet, const System::UnicodeString AParamNames, const System::Variant &AParamValues, bool &AReopened);
public:
	/* TcxDBAdapterItem.Create */ inline __fastcall virtual TcxADOProviderDetailFilterAdapter(Cxdb::TDataSetClass ADataSetClass) : Cxdbdata::TcxDBProviderDetailFilterAdapter(ADataSetClass) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxADOProviderDetailFilterAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxADOFilterOperatorAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxADOFilterOperatorAdapter : public Cxdbfilter::TcxDBFilterOperatorAdapter
{
	typedef Cxdbfilter::TcxDBFilterOperatorAdapter inherited;
	
public:
	virtual void __fastcall PrepareOperatorClass(System::TObject* ASender, Data::Db::TDataSet* ADataSet, Cxfilter::TcxFilterOperatorClass &AOperatorClass);
public:
	/* TcxDBAdapterItem.Create */ inline __fastcall virtual TcxADOFilterOperatorAdapter(Cxdb::TDataSetClass ADataSetClass) : Cxdbfilter::TcxDBFilterOperatorAdapter(ADataSetClass) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxADOFilterOperatorAdapter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxadoadapters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXADOADAPTERS)
using namespace Cxadoadapters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxadoadaptersHPP
