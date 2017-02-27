// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeSQLAdapters.pas' rev: 24.00 (Win64)

#ifndef DxservermodesqladaptersHPP
#define DxservermodesqladaptersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodesqladapters
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxServerModeMSSQLAdapter;
class PASCALIMPLEMENTATION TdxServerModeMSSQLAdapter : public Dxservermodedata::TdxServerModeCustomSQLAdapter
{
	typedef Dxservermodedata::TdxServerModeCustomSQLAdapter inherited;
	
protected:
	virtual bool __fastcall CanIdentifyInsertingRow(void);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetInsertingRowOutKey(const System::UnicodeString AKey);
	virtual System::UnicodeString __fastcall GetInsertSQLString(const System::UnicodeString AFrom, const System::UnicodeString AOutRowKey, const System::UnicodeString AFields, const System::UnicodeString AValues);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	virtual System::UnicodeString __fastcall GetUpdateSQLString(const System::UnicodeString AFrom, const System::UnicodeString AOutRowKey, const System::UnicodeString AValues, const System::UnicodeString AWhere);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
	virtual System::UnicodeString __fastcall GetSQLQueryKeyFieldNames(const System::UnicodeString ATableName);
	virtual System::UnicodeString __fastcall GetSQLQuerySchemaNames(void);
public:
	/* TdxServerModeCustomSQLAdapter.Create */ inline __fastcall virtual TdxServerModeMSSQLAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeCustomSQLAdapter(ADataSource) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeMSSQLAdapter(void) { }
	
};


class DELPHICLASS TdxServerModeMySQLAdapter;
class PASCALIMPLEMENTATION TdxServerModeMySQLAdapter : public Dxservermodedata::TdxServerModeCustomSQLAdapter
{
	typedef Dxservermodedata::TdxServerModeCustomSQLAdapter inherited;
	
protected:
	virtual void __fastcall CheckParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CheckRepeatedParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall GetParamCheck(void);
	virtual void __fastcall RenameParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	virtual System::UnicodeString __fastcall GetQuoteChar(void);
	virtual System::UnicodeString __fastcall DateDec(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DateDiff(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression1, const System::UnicodeString ADateExpression2);
	virtual System::UnicodeString __fastcall DateInc(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DatePart(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression);
	virtual bool __fastcall IsMicrosecondSupported(void);
	virtual bool __fastcall IsMillisecondSupported(void);
	virtual bool __fastcall NeedCastGroupingByDateRange(void);
	virtual System::UnicodeString __fastcall GetCaseFullFormat(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
	virtual System::UnicodeString __fastcall GetSQLQueryKeyFieldNames(const System::UnicodeString ATableName);
public:
	/* TdxServerModeCustomSQLAdapter.Create */ inline __fastcall virtual TdxServerModeMySQLAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeCustomSQLAdapter(ADataSource) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeMySQLAdapter(void) { }
	
};


class DELPHICLASS TdxServerModeFirebirdAdapter;
class PASCALIMPLEMENTATION TdxServerModeFirebirdAdapter : public Dxservermodedata::TdxServerModeCustomSQLAdapter
{
	typedef Dxservermodedata::TdxServerModeCustomSQLAdapter inherited;
	
protected:
	virtual void __fastcall CheckParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CheckRepeatedParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall GetParamCheck(void);
	virtual void __fastcall RenameParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall CanIdentifyInsertingRow(void);
	virtual bool __fastcall CanUseResultFieldName(void);
	virtual System::UnicodeString __fastcall DatePart(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetInsertSQLString(const System::UnicodeString AFrom, const System::UnicodeString AOutRowKey, const System::UnicodeString AFields, const System::UnicodeString AValues);
	virtual System::UnicodeString __fastcall GetUpdateSQLString(const System::UnicodeString AFrom, const System::UnicodeString AOutRowKey, const System::UnicodeString AValues, const System::UnicodeString AWhere);
	virtual System::UnicodeString __fastcall GetFieldsRetrieveQueryFormat(void);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
	virtual System::UnicodeString __fastcall GetSQLQueryKeyFieldNames(const System::UnicodeString ATableName);
public:
	/* TdxServerModeCustomSQLAdapter.Create */ inline __fastcall virtual TdxServerModeFirebirdAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeCustomSQLAdapter(ADataSource) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeFirebirdAdapter(void) { }
	
};


class DELPHICLASS TdxServerModeInterBaseAdapter;
class PASCALIMPLEMENTATION TdxServerModeInterBaseAdapter : public TdxServerModeFirebirdAdapter
{
	typedef TdxServerModeFirebirdAdapter inherited;
	
protected:
	virtual bool __fastcall CanUseResultFieldName(void);
	virtual System::UnicodeString __fastcall DatePart(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual bool __fastcall IsDateRangeGroupingSupported(void);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	virtual System::UnicodeString __fastcall GetTableNameFormat(void);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
public:
	/* TdxServerModeCustomSQLAdapter.Create */ inline __fastcall virtual TdxServerModeInterBaseAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : TdxServerModeFirebirdAdapter(ADataSource) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeInterBaseAdapter(void) { }
	
};


class DELPHICLASS TdxServerModeOracleAdapter;
class PASCALIMPLEMENTATION TdxServerModeOracleAdapter : public Dxservermodedata::TdxServerModeCustomSQLAdapter
{
	typedef Dxservermodedata::TdxServerModeCustomSQLAdapter inherited;
	
private:
	Dxservermodedata::TdxNullsSortOrder FNullsSortOrder;
	void __fastcall SetNullsSortOrder(const Dxservermodedata::TdxNullsSortOrder Value);
	
protected:
	virtual void __fastcall CheckParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CheckRepeatedParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual System::UnicodeString __fastcall GetOrderFormat(bool AIsDesc);
	virtual bool __fastcall GetParamCheck(void);
	virtual Dxservermodedata::TdxNullsSortOrder __fastcall GetNullsSortOrder(void);
	virtual void __fastcall RenameParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall CanUseGroupingByDateRangeParams(void);
	virtual System::UnicodeString __fastcall DateDiff(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression1, const System::UnicodeString ADateExpression2);
	virtual System::UnicodeString __fastcall DateInc(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DatePart(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetDateTimeFormat(void);
	virtual System::UnicodeString __fastcall TruncGroupingDate(const System::UnicodeString ADate, Dxservermodedata::TdxDateTimeGrouping ADateTimeGrouping);
	System::UnicodeString __fastcall GetSchemaName(void);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	
public:
	__fastcall virtual TdxServerModeOracleAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
	virtual System::UnicodeString __fastcall GetSQLQueryKeyFieldNames(const System::UnicodeString ATableName);
	virtual System::UnicodeString __fastcall GetSQLQuerySchemaNames(void);
	
__published:
	__property Dxservermodedata::TdxNullsSortOrder NullsSortOrder = {read=FNullsSortOrder, write=SetNullsSortOrder, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeOracleAdapter(void) { }
	
};


class DELPHICLASS TdxServerModePostgreSQLAdapter;
class PASCALIMPLEMENTATION TdxServerModePostgreSQLAdapter : public Dxservermodedata::TdxServerModeCustomSQLAdapter
{
	typedef Dxservermodedata::TdxServerModeCustomSQLAdapter inherited;
	
private:
	Dxservermodedata::TdxNullsSortOrder FNullsSortOrder;
	void __fastcall SetNullsSortOrder(const Dxservermodedata::TdxNullsSortOrder Value);
	
protected:
	virtual bool __fastcall CanUseResultFieldName(void);
	virtual bool __fastcall CanUseGroupingByDateRangeParams(void);
	virtual void __fastcall CheckParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CheckRepeatedParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual System::UnicodeString __fastcall GetOrderFormat(bool AIsDesc);
	virtual bool __fastcall GetParamCheck(void);
	virtual Dxservermodedata::TdxNullsSortOrder __fastcall GetNullsSortOrder(void);
	virtual void __fastcall RenameParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall CanIdentifyInsertingRow(void);
	virtual System::UnicodeString __fastcall DateDec(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DateDiff(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression1, const System::UnicodeString ADateExpression2);
	virtual System::UnicodeString __fastcall DateInc(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DatePart(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetInsertSQLString(const System::UnicodeString AFrom, const System::UnicodeString AOutRowKey, const System::UnicodeString AFields, const System::UnicodeString AValues);
	virtual System::UnicodeString __fastcall GetUpdateSQLString(const System::UnicodeString AFrom, const System::UnicodeString AOutRowKey, const System::UnicodeString AValues, const System::UnicodeString AWhere);
	virtual System::UnicodeString __fastcall TruncGroupingDate(const System::UnicodeString ADate, Dxservermodedata::TdxDateTimeGrouping ADateTimeGrouping);
	virtual void __fastcall CheckFilterFieldCaption(System::UnicodeString &AFieldCaption, Cxfilter::TcxFilterOperatorKind AOperatorKind);
	System::UnicodeString __fastcall GetSchemaName(void);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	
public:
	__fastcall virtual TdxServerModePostgreSQLAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
	virtual System::UnicodeString __fastcall GetSQLQueryKeyFieldNames(const System::UnicodeString ATableName);
	
__published:
	__property Dxservermodedata::TdxNullsSortOrder NullsSortOrder = {read=FNullsSortOrder, write=SetNullsSortOrder, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModePostgreSQLAdapter(void) { }
	
};


class DELPHICLASS TdxServerModeAdvantageAdapter;
class PASCALIMPLEMENTATION TdxServerModeAdvantageAdapter : public Dxservermodedata::TdxServerModeCustomSQLAdapter
{
	typedef Dxservermodedata::TdxServerModeCustomSQLAdapter inherited;
	
protected:
	virtual bool __fastcall IsMillisecondSupported(void);
	virtual System::UnicodeString __fastcall DateDec(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DateDiff(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression1, const System::UnicodeString ADateExpression2);
	virtual System::UnicodeString __fastcall DateInc(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DatePart(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression);
	virtual System::UnicodeString __fastcall GetCastAsDateFormat(void);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetCastAsTimeFormat(void);
	virtual System::UnicodeString __fastcall GetDatePart(Dxservermodedata::TdxSQLDatePart APart);
	virtual void __fastcall CheckFilterFieldCaption(System::UnicodeString &AFieldCaption, Cxfilter::TcxFilterOperatorKind AOperatorKind);
	virtual bool __fastcall CanUseResultFieldName(void);
	virtual bool __fastcall CanUseGroupingByDateRangeParams(void);
	virtual void __fastcall CheckParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CheckRepeatedParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall GetParamCheck(void);
	virtual void __fastcall RenameParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual System::UnicodeString __fastcall GetDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetFieldsRetrieveQueryFormat(void);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
	virtual System::UnicodeString __fastcall GetSQLQueryKeyFieldNames(const System::UnicodeString ATableName);
public:
	/* TdxServerModeCustomSQLAdapter.Create */ inline __fastcall virtual TdxServerModeAdvantageAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeCustomSQLAdapter(ADataSource) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeAdvantageAdapter(void) { }
	
};


class DELPHICLASS TdxServerModeMSAccessAdapter;
class PASCALIMPLEMENTATION TdxServerModeMSAccessAdapter : public Dxservermodedata::TdxServerModeCustomSQLAdapter
{
	typedef Dxservermodedata::TdxServerModeCustomSQLAdapter inherited;
	
protected:
	virtual void __fastcall CheckParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CheckRepeatedParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall GetParamCheck(void);
	virtual void __fastcall RenameParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall IsMillisecondSupported(void);
	virtual bool __fastcall IsSkipClauseSupported(void);
	virtual System::UnicodeString __fastcall DateDec(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DateDiff(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression1, const System::UnicodeString ADateExpression2);
	virtual System::UnicodeString __fastcall DateInc(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DatePart(Dxservermodedata::TdxSQLDatePart APart, const System::UnicodeString ADateExpression);
	virtual System::UnicodeString __fastcall GetCaseFullFormat(void);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetDatePart(Dxservermodedata::TdxSQLDatePart APart);
	virtual System::UnicodeString __fastcall IsNull(const System::UnicodeString AExpression);
	virtual bool __fastcall CanUseGroupingByDateRangeParams(void);
	virtual System::UnicodeString __fastcall GetDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetFieldNameFormat(void);
	virtual System::UnicodeString __fastcall GetQuoteChar(void);
	virtual System::UnicodeString __fastcall GetTableNameFormat(void);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
public:
	/* TdxServerModeCustomSQLAdapter.Create */ inline __fastcall virtual TdxServerModeMSAccessAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeCustomSQLAdapter(ADataSource) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeMSAccessAdapter(void) { }
	
};


class DELPHICLASS TdxServerModeSQLiteAdapter;
class PASCALIMPLEMENTATION TdxServerModeSQLiteAdapter : public Dxservermodedata::TdxServerModeCustomSQLAdapter
{
	typedef Dxservermodedata::TdxServerModeCustomSQLAdapter inherited;
	
protected:
	virtual void __fastcall CheckParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CheckRepeatedParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall GetParamCheck(void);
	virtual void __fastcall RenameParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall CanUseResultFieldName(void);
	virtual System::UnicodeString __fastcall GetDateTimeFormat(void);
	virtual bool __fastcall IsDateRangeGroupingSupported(void);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	
public:
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
public:
	/* TdxServerModeCustomSQLAdapter.Create */ inline __fastcall virtual TdxServerModeSQLiteAdapter(Dxservermodedata::TdxServerModeCustomDataSource* ADataSource) : Dxservermodedata::TdxServerModeCustomSQLAdapter(ADataSource) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeSQLiteAdapter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxservermodesqladapters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODESQLADAPTERS)
using namespace Dxservermodesqladapters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodesqladaptersHPP
