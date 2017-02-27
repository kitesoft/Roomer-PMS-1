// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeADODataSource.pas' rev: 24.00 (Win32)

#ifndef DxservermodeadodatasourceHPP
#define DxservermodeadodatasourceHPP

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
#include <Data.Win.ADODB.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <dxServerModeClasses.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodeadodatasource
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxServerModeADOSQLQueryBuilder;
class PASCALIMPLEMENTATION TdxServerModeADOSQLQueryBuilder : public Dxservermodedata::TdxServerModeCustomSQLQueryBuilder
{
	typedef Dxservermodedata::TdxServerModeCustomSQLQueryBuilder inherited;
	
protected:
	virtual bool __fastcall CanCreateParam(const System::Variant &AValue);
public:
	/* TdxServerModeCustomSQLQueryBuilder.Create */ inline __fastcall virtual TdxServerModeADOSQLQueryBuilder(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeCustomSQLQueryBuilder(ADataSource) { }
	/* TdxServerModeCustomSQLQueryBuilder.Destroy */ inline __fastcall virtual ~TdxServerModeADOSQLQueryBuilder(void) { }
	
};


class DELPHICLASS TdxServerModeADODataSourceOptions;
class DELPHICLASS TdxServerModeADODataSource;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxServerModeADODataSourceOptions : public Dxservermodedata::TdxServerModeDataSourceOptions
{
	typedef Dxservermodedata::TdxServerModeDataSourceOptions inherited;
	
private:
	bool __fastcall GetEnableBCD(void);
	void __fastcall SetEnableBCD(const bool Value);
	TdxServerModeADODataSource* __fastcall GetDataSource(void);
	
protected:
	__property TdxServerModeADODataSource* DataSource = {read=GetDataSource};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool EnableBCD = {read=GetEnableBCD, write=SetEnableBCD, default=1};
public:
	/* TdxServerModeDataSourceOptions.Create */ inline __fastcall TdxServerModeADODataSourceOptions(Dxservermodedata::TdxServerModeCustomDataSource* AOwner) : Dxservermodedata::TdxServerModeDataSourceOptions(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeADODataSourceOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxServerModeADODataSourceHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxServerModeADODataSourceHelper : public Dxservermodedata::TdxServerModeDataSourceCustomHelper
{
	typedef Dxservermodedata::TdxServerModeDataSourceCustomHelper inherited;
	
protected:
	virtual Dxservermodedata::TdxDataSetClass __fastcall GetDataSetClass(void);
	virtual Dxservermodedata::TdxServerModeDataSourceOptionsClass __fastcall GetOptionsClass(void);
	virtual Dxservermodedata::TdxServerModeCustomSQLQueryBuilderClass __fastcall GetQueryBuilderClass(void);
	virtual void __fastcall DoExecuteCommand(Dxservermodedata::PDataSet AResultSet, const System::UnicodeString ACommand, Data::Db::TParams* AParams, bool AParamCheck);
	virtual void __fastcall DoInitializeDataSet(Data::Db::TDataSet* ADataSet);
	virtual void __fastcall DoSynchronizeDataSetConnection(Data::Db::TDataSet* ADataSet);
	virtual void __fastcall PrepareDatasetForIterate(Data::Db::TDataSet* ADataSet);
public:
	/* TdxServerModeDataSourceCustomHelper.Create */ inline __fastcall TdxServerModeADODataSourceHelper(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeDataSourceCustomHelper(ADataSource) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeADODataSourceHelper(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxServerModeADODataSource : public Dxservermodedata::TdxServerModeDataSource
{
	typedef Dxservermodedata::TdxServerModeDataSource inherited;
	
private:
	Data::Win::Adodb::TADOConnection* __fastcall GetConnection(void);
	Data::Win::Adodb::TADODataSet* __fastcall GetDataSet(void);
	TdxServerModeADODataSourceOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetConnection(Data::Win::Adodb::TADOConnection* Value);
	HIDESBASE void __fastcall SetOptions(TdxServerModeADODataSourceOptions* const Value);
	
protected:
	virtual void __fastcall DoPopulateKeyFields(System::Classes::TStrings* AList);
	virtual void __fastcall DoPopulateTableNames(System::Classes::TStrings* AList);
	virtual void __fastcall DoPopulateViewNames(System::Classes::TStrings* AList);
	virtual Dxservermodedata::TdxServerModeDataSourceCustomHelperClass __fastcall GetHelperClass(void);
	__property Data::Win::Adodb::TADODataSet* DataSet = {read=GetDataSet};
	
__published:
	__property Data::Win::Adodb::TADOConnection* Connection = {read=GetConnection, write=SetConnection};
	__property TdxServerModeADODataSourceOptions* Options = {read=GetOptions, write=SetOptions};
public:
	/* TdxServerModeCustomDataSource.Create */ inline __fastcall virtual TdxServerModeADODataSource(System::Classes::TComponent* AOwner) : Dxservermodedata::TdxServerModeDataSource(AOwner) { }
	/* TdxServerModeCustomDataSource.Destroy */ inline __fastcall virtual ~TdxServerModeADODataSource(void) { }
	
};


class DELPHICLASS TdxServerModeADOQueryDataSource;
class PASCALIMPLEMENTATION TdxServerModeADOQueryDataSource : public Dxservermodedata::TdxServerModeQueryDataSource
{
	typedef Dxservermodedata::TdxServerModeQueryDataSource inherited;
	
private:
	Data::Win::Adodb::TADOConnection* __fastcall GetConnection(void);
	Data::Win::Adodb::TADODataSet* __fastcall GetDataSet(void);
	TdxServerModeADODataSourceOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetConnection(Data::Win::Adodb::TADOConnection* Value);
	HIDESBASE void __fastcall SetOptions(TdxServerModeADODataSourceOptions* const Value);
	
protected:
	virtual Dxservermodedata::TdxServerModeDataSourceCustomHelperClass __fastcall GetHelperClass(void);
	__property Data::Win::Adodb::TADODataSet* DataSet = {read=GetDataSet};
	
__published:
	__property Data::Win::Adodb::TADOConnection* Connection = {read=GetConnection, write=SetConnection};
	__property TdxServerModeADODataSourceOptions* Options = {read=GetOptions, write=SetOptions};
public:
	/* TdxServerModeQueryDataSource.Create */ inline __fastcall virtual TdxServerModeADOQueryDataSource(System::Classes::TComponent* AOwner) : Dxservermodedata::TdxServerModeQueryDataSource(AOwner) { }
	/* TdxServerModeQueryDataSource.Destroy */ inline __fastcall virtual ~TdxServerModeADOQueryDataSource(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxservermodeadodatasource */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODEADODATASOURCE)
using namespace Dxservermodeadodatasource;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodeadodatasourceHPP
