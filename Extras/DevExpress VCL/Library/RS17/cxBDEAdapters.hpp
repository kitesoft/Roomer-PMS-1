// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxBDEAdapters.pas' rev: 24.00 (Win32)

#ifndef CxbdeadaptersHPP
#define CxbdeadaptersHPP

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

namespace Cxbdeadapters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxBDEFilterOperatorAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBDEFilterOperatorAdapter : public Cxdbfilter::TcxDBFilterOperatorAdapter
{
	typedef Cxdbfilter::TcxDBFilterOperatorAdapter inherited;
	
public:
	virtual void __fastcall PrepareOperatorClass(System::TObject* ASender, Data::Db::TDataSet* ADataSet, Cxfilter::TcxFilterOperatorClass &AOperatorClass);
public:
	/* TcxDBAdapterItem.Create */ inline __fastcall virtual TcxBDEFilterOperatorAdapter(Cxdb::TDataSetClass ADataSetClass) : Cxdbfilter::TcxDBFilterOperatorAdapter(ADataSetClass) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBDEFilterOperatorAdapter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxbdeadapters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXBDEADAPTERS)
using namespace Cxbdeadapters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxbdeadaptersHPP
