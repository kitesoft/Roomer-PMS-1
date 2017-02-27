// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFilter.pas' rev: 24.00 (Win64)

#ifndef CxfilterHPP
#define CxfilterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxfilter
{
//-- type declarations -------------------------------------------------------
enum TcxFilterOperatorKind : unsigned char { foEqual, foNotEqual, foLess, foLessEqual, foGreater, foGreaterEqual, foLike, foNotLike, foBetween, foNotBetween, foInList, foNotInList, foYesterday, foToday, foTomorrow, foLast7Days, foLastWeek, foLast14Days, foLastTwoWeeks, foLast30Days, foLastMonth, foLastYear, foInPast, foThisWeek, foThisMonth, foThisYear, foNext7Days, foNextWeek, foNext14Days, foNextTwoWeeks, foNext30Days, foNextMonth, foNextYear, foInFuture };

typedef System::Set<TcxFilterOperatorKind, TcxFilterOperatorKind::foEqual, TcxFilterOperatorKind::foInFuture>  TcxFilterOperatorKinds;

enum TcxFilterBoolOperatorKind : unsigned char { fboAnd, fboOr, fboNotAnd, fboNotOr };

class DELPHICLASS TcxFilterOperator;
class DELPHICLASS TcxFilterCriteriaItem;
class PASCALIMPLEMENTATION TcxFilterOperator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxFilterCriteriaItem* FCriteriaItem;
	_RTL_CRITICAL_SECTION FCriticalSection;
	
protected:
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall GetExpressionValue(const System::Variant &AValue);
	void __fastcall Lock(void);
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	virtual void __fastcall Prepare(void);
	virtual bool __fastcall PrepareExpressionValue(const System::Variant &AValue, System::UnicodeString &DisplayValue);
	void __fastcall Unlock(void);
	
public:
	__fastcall virtual TcxFilterOperator(TcxFilterCriteriaItem* ACriteriaItem);
	__fastcall virtual ~TcxFilterOperator(void);
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2) = 0 ;
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void) = 0 ;
	virtual bool __fastcall IsDescription(void);
	virtual bool __fastcall IsExpression(void);
	virtual bool __fastcall IsNullOperator(void);
	__property TcxFilterCriteriaItem* CriteriaItem = {read=FCriteriaItem};
};


typedef System::TMetaClass* TcxFilterOperatorClass;

class DELPHICLASS TcxFilterEqualOperator;
class PASCALIMPLEMENTATION TcxFilterEqualOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
	virtual bool __fastcall IsExpression(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterEqualOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterEqualOperator(void) { }
	
};


class DELPHICLASS TcxFilterNotEqualOperator;
class PASCALIMPLEMENTATION TcxFilterNotEqualOperator : public TcxFilterEqualOperator
{
	typedef TcxFilterEqualOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotEqualOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterEqualOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotEqualOperator(void) { }
	
};


class DELPHICLASS TcxFilterLessOperator;
class PASCALIMPLEMENTATION TcxFilterLessOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLessOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLessOperator(void) { }
	
};


class DELPHICLASS TcxFilterLessEqualOperator;
class PASCALIMPLEMENTATION TcxFilterLessEqualOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLessEqualOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLessEqualOperator(void) { }
	
};


class DELPHICLASS TcxFilterGreaterOperator;
class PASCALIMPLEMENTATION TcxFilterGreaterOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterGreaterOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterGreaterOperator(void) { }
	
};


class DELPHICLASS TcxFilterGreaterEqualOperator;
class PASCALIMPLEMENTATION TcxFilterGreaterEqualOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterGreaterEqualOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterGreaterEqualOperator(void) { }
	
};


class DELPHICLASS TcxFilterLikeOperator;
class PASCALIMPLEMENTATION TcxFilterLikeOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
protected:
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLikeOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLikeOperator(void) { }
	
};


class DELPHICLASS TcxFilterNotLikeOperator;
class PASCALIMPLEMENTATION TcxFilterNotLikeOperator : public TcxFilterLikeOperator
{
	typedef TcxFilterLikeOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
	virtual bool __fastcall IsExpression(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotLikeOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterLikeOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotLikeOperator(void) { }
	
};


class DELPHICLASS TcxFilterBetweenOperator;
class PASCALIMPLEMENTATION TcxFilterBetweenOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	virtual bool __fastcall PrepareExpressionValue(const System::Variant &AValue, System::UnicodeString &DisplayValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
	virtual bool __fastcall IsDescription(void);
	virtual bool __fastcall IsExpression(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterBetweenOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterBetweenOperator(void) { }
	
};


class DELPHICLASS TcxFilterNotBetweenOperator;
class PASCALIMPLEMENTATION TcxFilterNotBetweenOperator : public TcxFilterBetweenOperator
{
	typedef TcxFilterBetweenOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotBetweenOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterBetweenOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotBetweenOperator(void) { }
	
};


class DELPHICLASS TcxFilterInListOperator;
class PASCALIMPLEMENTATION TcxFilterInListOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	virtual bool __fastcall PrepareExpressionValue(const System::Variant &AValue, System::UnicodeString &DisplayValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
	virtual bool __fastcall IsDescription(void);
	virtual bool __fastcall IsExpression(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterInListOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterInListOperator(void) { }
	
};


class DELPHICLASS TcxFilterNotInListOperator;
class PASCALIMPLEMENTATION TcxFilterNotInListOperator : public TcxFilterInListOperator
{
	typedef TcxFilterInListOperator inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotInListOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterInListOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotInListOperator(void) { }
	
};


class DELPHICLASS TcxFilterNullOperator;
class PASCALIMPLEMENTATION TcxFilterNullOperator : public TcxFilterEqualOperator
{
	typedef TcxFilterEqualOperator inherited;
	
protected:
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual bool __fastcall IsNullOperator(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNullOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterEqualOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNullOperator(void) { }
	
};


class DELPHICLASS TcxFilterNotNullOperator;
class PASCALIMPLEMENTATION TcxFilterNotNullOperator : public TcxFilterNullOperator
{
	typedef TcxFilterNullOperator inherited;
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall DisplayText(void);
	virtual System::UnicodeString __fastcall FilterText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNotNullOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterNullOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNotNullOperator(void) { }
	
};


class DELPHICLASS TcxFilterDateOperator;
class PASCALIMPLEMENTATION TcxFilterDateOperator : public TcxFilterOperator
{
	typedef TcxFilterOperator inherited;
	
private:
	System::TDateTime FDate1;
	System::TDateTime FDate2;
	
protected:
	virtual void __fastcall PrepareDisplayValue(System::UnicodeString &DisplayValue);
	virtual System::UnicodeString __fastcall GetExpressionFilterText(const System::Variant &AValue);
	
public:
	virtual bool __fastcall CompareValues(const System::Variant &AValue1, const System::Variant &AValue2);
	virtual System::UnicodeString __fastcall FilterText(void);
	virtual bool __fastcall IsExpression(void);
	__property System::TDateTime Date1 = {read=FDate1, write=FDate1};
	__property System::TDateTime Date2 = {read=FDate2, write=FDate2};
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterDateOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterDateOperator(void) { }
	
};


class DELPHICLASS TcxFilterYesterdayOperator;
class PASCALIMPLEMENTATION TcxFilterYesterdayOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterYesterdayOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterYesterdayOperator(void) { }
	
};


class DELPHICLASS TcxFilterTodayOperator;
class PASCALIMPLEMENTATION TcxFilterTodayOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterTodayOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterTodayOperator(void) { }
	
};


class DELPHICLASS TcxFilterTomorrowOperator;
class PASCALIMPLEMENTATION TcxFilterTomorrowOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterTomorrowOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterTomorrowOperator(void) { }
	
};


class DELPHICLASS TcxFilterLastNDaysOperator;
class PASCALIMPLEMENTATION TcxFilterLastNDaysOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual int __fastcall DayCount(void) = 0 ;
	virtual void __fastcall Prepare(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastNDaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastNDaysOperator(void) { }
	
};


class DELPHICLASS TcxFilterLast7DaysOperator;
class PASCALIMPLEMENTATION TcxFilterLast7DaysOperator : public TcxFilterLastNDaysOperator
{
	typedef TcxFilterLastNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLast7DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterLastNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLast7DaysOperator(void) { }
	
};


class DELPHICLASS TcxFilterLastWeekOperator;
class PASCALIMPLEMENTATION TcxFilterLastWeekOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastWeekOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastWeekOperator(void) { }
	
};


class DELPHICLASS TcxFilterLast14DaysOperator;
class PASCALIMPLEMENTATION TcxFilterLast14DaysOperator : public TcxFilterLastNDaysOperator
{
	typedef TcxFilterLastNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLast14DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterLastNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLast14DaysOperator(void) { }
	
};


class DELPHICLASS TcxFilterLastTwoWeeksOperator;
class PASCALIMPLEMENTATION TcxFilterLastTwoWeeksOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastTwoWeeksOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastTwoWeeksOperator(void) { }
	
};


class DELPHICLASS TcxFilterLast30DaysOperator;
class PASCALIMPLEMENTATION TcxFilterLast30DaysOperator : public TcxFilterLastNDaysOperator
{
	typedef TcxFilterLastNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLast30DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterLastNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLast30DaysOperator(void) { }
	
};


class DELPHICLASS TcxFilterLastMonthOperator;
class PASCALIMPLEMENTATION TcxFilterLastMonthOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastMonthOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastMonthOperator(void) { }
	
};


class DELPHICLASS TcxFilterLastYearOperator;
class PASCALIMPLEMENTATION TcxFilterLastYearOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterLastYearOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterLastYearOperator(void) { }
	
};


class DELPHICLASS TcxFilterInPastOperator;
class PASCALIMPLEMENTATION TcxFilterInPastOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterInPastOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterInPastOperator(void) { }
	
};


class DELPHICLASS TcxFilterThisWeekOperator;
class PASCALIMPLEMENTATION TcxFilterThisWeekOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterThisWeekOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterThisWeekOperator(void) { }
	
};


class DELPHICLASS TcxFilterThisMonthOperator;
class PASCALIMPLEMENTATION TcxFilterThisMonthOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterThisMonthOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterThisMonthOperator(void) { }
	
};


class DELPHICLASS TcxFilterThisYearOperator;
class PASCALIMPLEMENTATION TcxFilterThisYearOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterThisYearOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterThisYearOperator(void) { }
	
};


class DELPHICLASS TcxFilterNextNDaysOperator;
class PASCALIMPLEMENTATION TcxFilterNextNDaysOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual int __fastcall DayCount(void) = 0 ;
	virtual void __fastcall Prepare(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextNDaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextNDaysOperator(void) { }
	
};


class DELPHICLASS TcxFilterNext7DaysOperator;
class PASCALIMPLEMENTATION TcxFilterNext7DaysOperator : public TcxFilterNextNDaysOperator
{
	typedef TcxFilterNextNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNext7DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterNextNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNext7DaysOperator(void) { }
	
};


class DELPHICLASS TcxFilterNextWeekOperator;
class PASCALIMPLEMENTATION TcxFilterNextWeekOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextWeekOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextWeekOperator(void) { }
	
};


class DELPHICLASS TcxFilterNext14DaysOperator;
class PASCALIMPLEMENTATION TcxFilterNext14DaysOperator : public TcxFilterNextNDaysOperator
{
	typedef TcxFilterNextNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNext14DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterNextNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNext14DaysOperator(void) { }
	
};


class DELPHICLASS TcxFilterNextTwoWeeksOperator;
class PASCALIMPLEMENTATION TcxFilterNextTwoWeeksOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextTwoWeeksOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextTwoWeeksOperator(void) { }
	
};


class DELPHICLASS TcxFilterNext30DaysOperator;
class PASCALIMPLEMENTATION TcxFilterNext30DaysOperator : public TcxFilterNextNDaysOperator
{
	typedef TcxFilterNextNDaysOperator inherited;
	
protected:
	virtual int __fastcall DayCount(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNext30DaysOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterNextNDaysOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNext30DaysOperator(void) { }
	
};


class DELPHICLASS TcxFilterNextMonthOperator;
class PASCALIMPLEMENTATION TcxFilterNextMonthOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextMonthOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextMonthOperator(void) { }
	
};


class DELPHICLASS TcxFilterNextYearOperator;
class PASCALIMPLEMENTATION TcxFilterNextYearOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterNextYearOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterNextYearOperator(void) { }
	
};


class DELPHICLASS TcxFilterInFutureOperator;
class PASCALIMPLEMENTATION TcxFilterInFutureOperator : public TcxFilterDateOperator
{
	typedef TcxFilterDateOperator inherited;
	
protected:
	virtual void __fastcall Prepare(void);
	
public:
	virtual System::UnicodeString __fastcall DisplayText(void);
public:
	/* TcxFilterOperator.Create */ inline __fastcall virtual TcxFilterInFutureOperator(TcxFilterCriteriaItem* ACriteriaItem) : TcxFilterDateOperator(ACriteriaItem) { }
	/* TcxFilterOperator.Destroy */ inline __fastcall virtual ~TcxFilterInFutureOperator(void) { }
	
};


class DELPHICLASS TcxCustomFilterCriteriaItem;
class DELPHICLASS TcxFilterCriteriaItemList;
class DELPHICLASS TcxFilterCriteria;
class PASCALIMPLEMENTATION TcxCustomFilterCriteriaItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxFilterCriteriaItemList* FParent;
	
protected:
	virtual void __fastcall Changed(void);
	virtual TcxFilterCriteria* __fastcall GetCriteria(void);
	virtual bool __fastcall GetIsItemList(void) = 0 ;
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	__fastcall TcxCustomFilterCriteriaItem(TcxFilterCriteriaItemList* AOwner);
	__fastcall virtual ~TcxCustomFilterCriteriaItem(void);
	virtual bool __fastcall IsEmpty(void) = 0 ;
	__property bool IsItemList = {read=GetIsItemList, nodefault};
	__property TcxFilterCriteria* Criteria = {read=GetCriteria};
	__property TcxFilterCriteriaItemList* Parent = {read=FParent};
};


typedef System::TMetaClass* TcxFilterCriteriaItemListClass;

class PASCALIMPLEMENTATION TcxFilterCriteriaItemList : public TcxCustomFilterCriteriaItem
{
	typedef TcxCustomFilterCriteriaItem inherited;
	
public:
	TcxCustomFilterCriteriaItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxFilterBoolOperatorKind FBoolOperatorKind;
	TcxFilterCriteria* FCriteria;
	Dxcoreclasses::TdxFastList* FItems;
	int __fastcall GetCount(void);
	TcxCustomFilterCriteriaItem* __fastcall GetItem(int Index);
	void __fastcall SetBoolOperatorKind(TcxFilterBoolOperatorKind Value);
	
protected:
	virtual TcxFilterCriteria* __fastcall GetCriteria(void);
	virtual bool __fastcall GetIsItemList(void);
	virtual void __fastcall RemoveItem(TcxCustomFilterCriteriaItem* AItem);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	TcxCustomFilterCriteriaItem* __fastcall ReadItem(System::Classes::TStream* AStream);
	void __fastcall WriteItem(System::Classes::TStream* AStream, TcxCustomFilterCriteriaItem* AItem);
	
public:
	__fastcall virtual TcxFilterCriteriaItemList(TcxFilterCriteriaItemList* AOwner, TcxFilterBoolOperatorKind ABoolOperatorKind);
	__fastcall virtual ~TcxFilterCriteriaItemList(void);
	TcxFilterCriteriaItem* __fastcall AddItem(System::TObject* AItemLink, TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue);
	TcxFilterCriteriaItemList* __fastcall AddItemList(TcxFilterBoolOperatorKind ABoolOperatorKind);
	void __fastcall Clear(void);
	virtual bool __fastcall IsEmpty(void);
	__property TcxFilterBoolOperatorKind BoolOperatorKind = {read=FBoolOperatorKind, write=SetBoolOperatorKind, default=0};
	__property int Count = {read=GetCount, nodefault};
	__property TcxFilterCriteria* Criteria = {read=GetCriteria};
	__property TcxCustomFilterCriteriaItem* Items[int Index] = {read=GetItem/*, default*/};
};


class PASCALIMPLEMENTATION TcxFilterCriteriaItem : public TcxCustomFilterCriteriaItem
{
	typedef TcxCustomFilterCriteriaItem inherited;
	
private:
	System::UnicodeString FDisplayValue;
	System::TObject* FItemLink;
	TcxFilterOperator* FOperator;
	TcxFilterOperatorKind FOperatorKind;
	System::Variant FPreparedValue;
	System::Variant FValue;
	void __fastcall InternalSetValue(const System::Variant &Value);
	void __fastcall SetDisplayValue(const System::UnicodeString Value);
	void __fastcall SetOperatorKind(TcxFilterOperatorKind Value);
	void __fastcall SetValue(const System::Variant &Value);
	
protected:
	void __fastcall CheckDisplayValue(void);
	virtual System::Variant __fastcall GetDataValue(System::TObject* AData) = 0 ;
	virtual System::UnicodeString __fastcall GetDisplayValue(void);
	virtual System::UnicodeString __fastcall GetExpressionValue(bool AIsCaption);
	virtual System::UnicodeString __fastcall GetFieldCaption(void);
	virtual System::UnicodeString __fastcall GetFieldName(void);
	virtual TcxFilterOperatorClass __fastcall GetFilterOperatorClass(void);
	virtual System::TObject* __fastcall GetItemLink(void);
	virtual void __fastcall SetItemLink(System::TObject* Value);
	virtual bool __fastcall GetIsItemList(void);
	void __fastcall Prepare(void);
	void __fastcall PrepareValue(void);
	virtual void __fastcall RecreateOperator(void);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual bool __fastcall SupportsMultiThreading(void);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual TcxFilterCriteriaItem(TcxFilterCriteriaItemList* AOwner, System::TObject* AItemLink, TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue);
	__fastcall virtual ~TcxFilterCriteriaItem(void);
	virtual bool __fastcall IsEmpty(void);
	virtual bool __fastcall ValueIsNull(const System::Variant &AValue);
	__property System::UnicodeString DisplayValue = {read=FDisplayValue, write=SetDisplayValue};
	__property System::TObject* ItemLink = {read=GetItemLink};
	__property TcxFilterOperator* Operator = {read=FOperator};
	__property TcxFilterOperatorKind OperatorKind = {read=FOperatorKind, write=SetOperatorKind, nodefault};
	__property System::Variant PreparedValue = {read=FPreparedValue};
	__property System::Variant Value = {read=FValue, write=SetValue};
};


typedef System::TMetaClass* TcxFilterCriteriaItemClass;

enum TcxFilterValueItemKind : unsigned char { fviAll, fviCustom, fviBlanks, fviNonBlanks, fviUser, fviValue, fviMRU, fviMRUSeparator, fviSpecial, fviUserEx };

class DELPHICLASS TcxFilterValueItem;
class DELPHICLASS TcxFilterValueList;
class PASCALIMPLEMENTATION TcxFilterValueItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FPreparedDisplayText;
	System::Variant FPreparedValue;
	System::UnicodeString FDisplayText;
	TcxFilterValueItemKind FKind;
	TcxFilterValueList* FOwner;
	System::Variant FValue;
	TcxFilterCriteria* __fastcall GetCriteria(void);
	
protected:
	void __fastcall Prepare(void);
	__property TcxFilterCriteria* Criteria = {read=GetCriteria};
	__property System::UnicodeString PreparedDisplayText = {read=FPreparedDisplayText};
	__property System::Variant PreparedValue = {read=FPreparedValue};
	
public:
	__fastcall TcxFilterValueItem(TcxFilterValueList* AOwner, TcxFilterValueItemKind AKind, const System::Variant &AValue, const System::UnicodeString ADisplayText);
	int __fastcall ComparePreparedValue(const System::Variant &APreparedValue, const System::UnicodeString APreparedDisplayText);
	__property TcxFilterValueItemKind Kind = {read=FKind, nodefault};
	__property System::Variant Value = {read=FValue};
	__property System::UnicodeString DisplayText = {read=FDisplayText};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterValueItem(void) { }
	
};


class PASCALIMPLEMENTATION TcxFilterValueList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxFilterValueItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxFilterCriteria* FCriteria;
	Dxcoreclasses::TdxFastObjectList* FItems;
	bool FIsUnsortedValues;
	bool FSortByDisplayText;
	int __fastcall GetCount(void);
	TcxFilterValueItem* __fastcall GetItem(int Index);
	int __fastcall GetMaxCount(void);
	
protected:
	virtual int __fastcall CompareItem(int AIndex, const System::Variant &APreparedValue, const System::UnicodeString APreparedDisplayText);
	TcxFilterValueItem* __fastcall CreateItem(TcxFilterValueItemKind AKind, const System::Variant &AValue, const System::UnicodeString ADisplayText);
	int __fastcall GetMRUSeparatorIndex(void);
	int __fastcall GetStartValueIndex(void);
	bool __fastcall FindValueIndex(const System::Variant &APreparedValue, const System::UnicodeString APreparedDisplayText, /* out */ int &AIndex);
	
public:
	__fastcall virtual TcxFilterValueList(TcxFilterCriteria* ACriteria);
	__fastcall virtual ~TcxFilterValueList(void);
	virtual void __fastcall Add(TcxFilterValueItemKind AKind, const System::Variant &AValue, const System::UnicodeString ADisplayText, bool ANoSorting);
	virtual void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	virtual bool __fastcall Find(const System::Variant &AValue, const System::UnicodeString ADisplayText, int &AIndex);
	int __fastcall FindItemByKind(TcxFilterValueItemKind AKind)/* overload */;
	int __fastcall FindItemByKind(TcxFilterValueItemKind AKind, const System::Variant &AValue)/* overload */;
	int __fastcall FindItemByValue(const System::Variant &AValue);
	virtual int __fastcall GetIndexByCriteriaItem(TcxFilterCriteriaItem* ACriteriaItem);
	__property int Count = {read=GetCount, nodefault};
	__property TcxFilterCriteria* Criteria = {read=FCriteria};
	__property TcxFilterValueItem* Items[int Index] = {read=GetItem/*, default*/};
	__property Dxcoreclasses::TdxFastObjectList* ItemsList = {read=FItems};
	__property int MaxCount = {read=GetMaxCount, nodefault};
	__property bool SortByDisplayText = {read=FSortByDisplayText, write=FSortByDisplayText, nodefault};
};


typedef System::TMetaClass* TcxFilterValueListClass;

enum TcxFilterCriteriaOption : unsigned char { fcoCaseInsensitive, fcoShowOperatorDescription, fcoSoftNull, fcoSoftCompare, fcoIgnoreNull };

typedef System::Set<TcxFilterCriteriaOption, TcxFilterCriteriaOption::fcoCaseInsensitive, TcxFilterCriteriaOption::fcoIgnoreNull>  TcxFilterCriteriaOptions;

class PASCALIMPLEMENTATION TcxFilterCriteria : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FChanged;
	_RTL_CRITICAL_SECTION FCriticalSection;
	System::UnicodeString FDateTimeFormat;
	bool FIsUnicode;
	System::Byte FLoadedVersion;
	int FLockCount;
	int FMaxValueListCount;
	TcxFilterCriteriaOptions FOptions;
	System::WideChar FPercentWildcard;
	TcxFilterCriteriaItemList* FRoot;
	System::Byte FSavedVersion;
	bool FSavingToStream;
	bool FSupportedLike;
	bool FTranslateBetween;
	bool FTranslateLike;
	bool FTranslateIn;
	System::WideChar FUnderscoreWildcard;
	System::Byte FVersion;
	System::Classes::TNotifyEvent FOnChanged;
	TcxFilterCriteriaOptions __fastcall GetOptions(void);
	bool __fastcall GetStoreItemLinkNames(void);
	void __fastcall SetDateTimeFormat(const System::UnicodeString Value);
	void __fastcall SetOptions(TcxFilterCriteriaOptions Value);
	void __fastcall SetPercentWildcard(System::WideChar Value);
	void __fastcall SetStoreItemLinkNames(bool Value);
	void __fastcall SetUnderscoreWildcard(System::WideChar Value);
	
protected:
	virtual void __fastcall CheckChanges(void);
	virtual System::UnicodeString __fastcall ConvertBoolToStr(const System::Variant &AValue);
	virtual System::UnicodeString __fastcall ConvertDateToStr(const System::Variant &AValue);
	bool __fastcall DoFilterData(System::TObject* AData);
	virtual void __fastcall FormatFilterTextValue(TcxFilterCriteriaItem* AItem, const System::Variant &AValue, System::UnicodeString &ADisplayValue);
	virtual System::UnicodeString __fastcall GetFilterCaption(void);
	virtual System::UnicodeString __fastcall GetFilterExpression(bool AIsCaption);
	virtual System::UnicodeString __fastcall GetFilterText(void);
	virtual int __fastcall GetIDByItemLink(System::TObject* AItemLink) = 0 ;
	virtual System::UnicodeString __fastcall GetNameByItemLink(System::TObject* AItemLink) = 0 ;
	virtual TcxFilterCriteriaItemClass __fastcall GetItemClass(void);
	virtual TcxFilterCriteriaItemListClass __fastcall GetItemListClass(void);
	virtual System::UnicodeString __fastcall GetItemExpression(TcxFilterCriteriaItem* AItem, bool AIsCaption);
	virtual System::UnicodeString __fastcall GetItemExpressionFieldName(TcxFilterCriteriaItem* AItem, bool AIsCaption);
	virtual System::UnicodeString __fastcall GetItemExpressionOperator(TcxFilterCriteriaItem* AItem, bool AIsCaption);
	virtual System::UnicodeString __fastcall GetItemExpressionValue(TcxFilterCriteriaItem* AItem, bool AIsCaption);
	virtual System::TObject* __fastcall GetItemLinkByID(int AID) = 0 ;
	virtual System::TObject* __fastcall GetItemLinkByName(const System::UnicodeString AName) = 0 ;
	virtual TcxFilterCriteriaItemListClass __fastcall GetRootClass(void);
	virtual TcxFilterValueListClass __fastcall GetValueListClass(void);
	bool __fastcall IsStore(void);
	void __fastcall Lock(void);
	virtual void __fastcall Prepare(void);
	virtual System::UnicodeString __fastcall PrepareDisplayText(const System::UnicodeString ADisplayText);
	virtual System::Variant __fastcall PrepareValue(const System::Variant &AValue);
	virtual void __fastcall SetFilterText(const System::UnicodeString Value);
	bool __fastcall SupportsMultiThreading(void);
	void __fastcall Unlock(void);
	virtual void __fastcall Update(void);
	__property bool IsUnicode = {read=FIsUnicode, nodefault};
	__property System::Byte LoadedVersion = {read=FLoadedVersion, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	__property System::Byte SavedVersion = {read=FSavedVersion, nodefault};
	__property System::Byte Version = {read=FVersion, write=FVersion, nodefault};
	
public:
	__fastcall TcxFilterCriteria(void);
	__fastcall virtual ~TcxFilterCriteria(void);
	HIDESBASE virtual void __fastcall Assign(System::Classes::TPersistent* Source, bool AIgnoreItemNames = false);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignItems(TcxFilterCriteria* ASource, bool AIgnoreItemNames = false);
	virtual TcxFilterCriteriaItem* __fastcall AddItem(TcxFilterCriteriaItemList* AParent, System::TObject* AItemLink, TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall Clear(void);
	virtual void __fastcall Changed(void);
	void __fastcall EndUpdate(void);
	bool __fastcall EqualItems(TcxFilterCriteria* AFilterCriteria, bool AIgnoreItemNames = false);
	virtual TcxFilterCriteriaItem* __fastcall FindItemByItemLink(System::TObject* AItemLink);
	virtual bool __fastcall IsEmpty(void);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall Refresh(void);
	void __fastcall RemoveItemByItemLink(System::TObject* AItemLink);
	virtual void __fastcall RestoreDefaults(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	virtual bool __fastcall ValueIsNull(const System::Variant &AValue);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	void __fastcall WriteData(System::Classes::TStream* AStream)/* overload */;
	virtual void __fastcall WriteData(System::Classes::TStream* AStream, System::Byte AVersion)/* overload */;
	__property System::UnicodeString DateTimeFormat = {read=FDateTimeFormat, write=SetDateTimeFormat};
	__property System::UnicodeString FilterCaption = {read=GetFilterCaption};
	__property System::UnicodeString FilterText = {read=GetFilterText, write=SetFilterText};
	__property TcxFilterCriteriaItemList* Root = {read=FRoot};
	__property bool StoreItemLinkNames = {read=GetStoreItemLinkNames, write=SetStoreItemLinkNames, nodefault};
	__property bool SupportedLike = {read=FSupportedLike, write=FSupportedLike, default=1};
	__property bool TranslateBetween = {read=FTranslateBetween, write=FTranslateBetween, default=0};
	__property bool TranslateIn = {read=FTranslateIn, write=FTranslateIn, default=0};
	__property bool TranslateLike = {read=FTranslateLike, write=FTranslateLike, default=0};
	
__published:
	__property int MaxValueListCount = {read=FMaxValueListCount, write=FMaxValueListCount, default=0};
	__property TcxFilterCriteriaOptions Options = {read=GetOptions, write=SetOptions, default=0};
	__property System::WideChar PercentWildcard = {read=FPercentWildcard, write=SetPercentWildcard, default=37};
	__property System::WideChar UnderscoreWildcard = {read=FUnderscoreWildcard, write=SetUnderscoreWildcard, default=95};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool cxFilterIncludeTodayInLastNextDaysList;
extern PACKAGE System::UnicodeString __fastcall ExtractFilterDisplayValue(const System::UnicodeString AValues, int &Pos);
extern PACKAGE System::UnicodeString __fastcall VarBetweenArrayToStr(const System::Variant &AValue);
extern PACKAGE System::UnicodeString __fastcall VarListArrayToStr(const System::Variant &AValue);
}	/* namespace Cxfilter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFILTER)
using namespace Cxfilter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxfilterHPP
