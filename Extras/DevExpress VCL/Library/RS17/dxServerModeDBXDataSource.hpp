// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeDBXDataSource.pas' rev: 24.00 (Win32)

#ifndef DxservermodedbxdatasourceHPP
#define DxservermodedbxdatasourceHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.SqlExpr.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxServerModeClasses.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodedbxdatasource
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxServerModeDBXSQLQueryBuilder;
class PASCALIMPLEMENTATION TdxServerModeDBXSQLQueryBuilder : public Dxservermodedata::TdxServerModeCustomSQLQueryBuilder
{
	typedef Dxservermodedata::TdxServerModeCustomSQLQueryBuilder inherited;
	
protected:
	virtual bool __fastcall CanUseParams(void);
public:
	/* TdxServerModeCustomSQLQueryBuilder.Create */ inline __fastcall virtual TdxServerModeDBXSQLQueryBuilder(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeCustomSQLQueryBuilder(ADataSource) { }
	/* TdxServerModeCustomSQLQueryBuilder.Destroy */ inline __fastcall virtual ~TdxServerModeDBXSQLQueryBuilder(void) { }
	
};


class DELPHICLASS TdxServerModeDBXDataSourceOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxServerModeDBXDataSourceOptions : public Dxservermodedata::TdxServerModeDataSourceOptions
{
	typedef Dxservermodedata::TdxServerModeDataSourceOptions inherited;
	
private:
	System::UnicodeString FSchemaName;
	void __fastcall SetSchemaName(const System::UnicodeString Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetSchemaName(void);
	
__published:
	__property System::UnicodeString SchemaName = {read=FSchemaName, write=SetSchemaName};
public:
	/* TdxServerModeDataSourceOptions.Create */ inline __fastcall TdxServerModeDBXDataSourceOptions(Dxservermodedata::TdxServerModeCustomDataSource* AOwner) : Dxservermodedata::TdxServerModeDataSourceOptions(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeDBXDataSourceOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxServerModeDBXDataSourceHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxServerModeDBXDataSourceHelper : public Dxservermodedata::TdxServerModeDataSourceCustomHelper
{
	typedef Dxservermodedata::TdxServerModeDataSourceCustomHelper inherited;
	
protected:
	virtual Dxservermodedata::TdxDataSetClass __fastcall GetDataSetClass(void);
	virtual Dxservermodedata::TdxServerModeDataSourceOptionsClass __fastcall GetOptionsClass(void);
	virtual Dxservermodedata::TdxServerModeCustomSQLQueryBuilderClass __fastcall GetQueryBuilderClass(void);
	virtual void __fastcall CheckParamValue(Data::Db::TParam* &AParam);
	virtual void __fastcall DoInitializeDataSet(Data::Db::TDataSet* ADataSet);
	virtual void __fastcall DoSynchronizeDataSetConnection(Data::Db::TDataSet* ADataSet);
	virtual void __fastcall PrepareDatasetForIterate(Data::Db::TDataSet* ADataSet);
	
public:
	void __fastcall PopulateSchemaNames(System::Classes::TStrings* AList);
public:
	/* TdxServerModeDataSourceCustomHelper.Create */ inline __fastcall TdxServerModeDBXDataSourceHelper(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeDataSourceCustomHelper(ADataSource) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeDBXDataSourceHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxServerModeDBXDataSource;
class PASCALIMPLEMENTATION TdxServerModeDBXDataSource : public Dxservermodedata::TdxServerModeDataSource
{
	typedef Dxservermodedata::TdxServerModeDataSource inherited;
	
private:
	Data::Sqlexpr::TSQLConnection* __fastcall GetConnection(void);
	TdxServerModeDBXDataSourceOptions* __fastcall GetOptions(void);
	TdxServerModeDBXDataSourceHelper* __fastcall GetHelper(void);
	HIDESBASE void __fastcall SetConnection(Data::Sqlexpr::TSQLConnection* Value);
	HIDESBASE void __fastcall SetOptions(TdxServerModeDBXDataSourceOptions* const Value);
	
protected:
	virtual void __fastcall DoPopulateTableNames(System::Classes::TStrings* AList);
	virtual void __fastcall DoPopulateViewNames(System::Classes::TStrings* AList);
	virtual Dxservermodedata::TdxServerModeDataSourceCustomHelperClass __fastcall GetHelperClass(void);
	__property TdxServerModeDBXDataSourceHelper* Helper = {read=GetHelper};
	
public:
	void __fastcall PopulateSchemaNames(System::Classes::TStrings* AList);
	
__published:
	__property Data::Sqlexpr::TSQLConnection* Connection = {read=GetConnection, write=SetConnection};
	__property TdxServerModeDBXDataSourceOptions* Options = {read=GetOptions, write=SetOptions};
public:
	/* TdxServerModeCustomDataSource.Create */ inline __fastcall virtual TdxServerModeDBXDataSource(System::Classes::TComponent* AOwner) : Dxservermodedata::TdxServerModeDataSource(AOwner) { }
	/* TdxServerModeCustomDataSource.Destroy */ inline __fastcall virtual ~TdxServerModeDBXDataSource(void) { }
	
};


class DELPHICLASS TdxServerModeDBXQueryDataSource;
class PASCALIMPLEMENTATION TdxServerModeDBXQueryDataSource : public Dxservermodedata::TdxServerModeQueryDataSource
{
	typedef Dxservermodedata::TdxServerModeQueryDataSource inherited;
	
private:
	Data::Sqlexpr::TSQLConnection* __fastcall GetConnection(void);
	TdxServerModeDBXDataSourceOptions* __fastcall GetOptions(void);
	TdxServerModeDBXDataSourceHelper* __fastcall GetHelper(void);
	HIDESBASE void __fastcall SetConnection(Data::Sqlexpr::TSQLConnection* Value);
	HIDESBASE void __fastcall SetOptions(TdxServerModeDBXDataSourceOptions* const Value);
	
protected:
	virtual Dxservermodedata::TdxServerModeDataSourceCustomHelperClass __fastcall GetHelperClass(void);
	__property TdxServerModeDBXDataSourceHelper* Helper = {read=GetHelper};
	
public:
	void __fastcall PopulateSchemaNames(System::Classes::TStrings* AList);
	
__published:
	__property Data::Sqlexpr::TSQLConnection* Connection = {read=GetConnection, write=SetConnection};
	__property TdxServerModeDBXDataSourceOptions* Options = {read=GetOptions, write=SetOptions};
public:
	/* TdxServerModeQueryDataSource.Create */ inline __fastcall virtual TdxServerModeDBXQueryDataSource(System::Classes::TComponent* AOwner) : Dxservermodedata::TdxServerModeQueryDataSource(AOwner) { }
	/* TdxServerModeQueryDataSource.Destroy */ inline __fastcall virtual ~TdxServerModeDBXQueryDataSource(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxservermodedbxdatasource */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODEDBXDATASOURCE)
using namespace Dxservermodedbxdatasource;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodedbxdatasourceHPP
