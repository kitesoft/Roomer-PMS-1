// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDateUtils.pas' rev: 24.00 (Win32)

#ifndef CxdateutilsHPP
#define CxdateutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdateutils
{
//-- type declarations -------------------------------------------------------
enum TcxDateElement : unsigned char { deYear, deMonth, deDay };

enum TcxFirstWeekOfYear : unsigned char { fwySystem, fwyJan1, fwyFirstFullWeek, fwyFirstFourDays };

enum TDay : unsigned char { dSunday, dMonday, dTuesday, dWednesday, dThursday, dFriday, dSaturday };

typedef System::Set<TDay, TDay::dSunday, TDay::dSaturday>  TDays;

typedef System::Int8 TdxDayOfWeek;

typedef System::Int8 TdxDayOfWeekSystem;

typedef System::Int8 TdxDayOfWeekVCL;

enum TcxCalendarAlgorithmType : unsigned char { catUnknown, catSolarCalendar, catLunarCalendar, catLunarSolarCalendar };

enum TcxDateEditSmartInput : unsigned char { deiToday, deiYesterday, deiTomorrow, deiSunday, deiMonday, deiTuesday, deiWednesday, deiThursday, deiFriday, deiSaturday, deiFirst, deiSecond, deiThird, deiFourth, deiFifth, deiSixth, deiSeventh, deiBOM, deiEOM, deiNow };

struct DECLSPEC_DRECORD TcxDateTime
{
public:
	int Era;
	unsigned Year;
	unsigned Month;
	unsigned Day;
	System::Byte Hours;
	System::Byte Minutes;
	System::Byte Seconds;
	System::Word Milliseconds;
};


struct DECLSPEC_DRECORD TcxDate
{
public:
	int Era;
	unsigned Year;
	unsigned Month;
	unsigned Day;
};


struct DECLSPEC_DRECORD TcxTime
{
public:
	unsigned Hours;
	unsigned Minutes;
	unsigned Seconds;
	unsigned Miliseconds;
};


class DELPHICLASS TcxEra;
class PASCALIMPLEMENTATION TcxEra : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FEra;
	int FMaxEraYear;
	int FMinEraYear;
	System::TDateTime FStartDate;
	int FYearOffset;
	
public:
	__fastcall TcxEra(int AEra, System::TDateTime AStartDate, int AYearOffset, int AMinEraYear, int AMaxEraYear);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int Era = {read=FEra, write=FEra, nodefault};
	__property int MaxEraYear = {read=FMaxEraYear, write=FMaxEraYear, nodefault};
	__property int MinEraYear = {read=FMinEraYear, write=FMinEraYear, nodefault};
	__property System::TDateTime StartDate = {read=FStartDate, write=FStartDate};
	__property int YearOffset = {read=FYearOffset, write=FYearOffset, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxEra(void) { }
	
};


class DELPHICLASS TcxEras;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEras : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	TcxEra* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxEra* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxEra* AValue);
	
public:
	__property TcxEra* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TdxFastObjectList.Create */ inline __fastcall TcxEras(bool AOwnsObjects, int ACapacity) : Dxcoreclasses::TdxFastObjectList(AOwnsObjects, ACapacity) { }
	
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TcxEras(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomCalendarTable;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomCalendarTable : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TcxEras* FEras;
	virtual void __fastcall AdjustYear(int &AYear, int &AEra)/* overload */;
	virtual void __fastcall AdjustYear(int &AYear, int &AEra, int AMonth, int ADay)/* overload */;
	virtual TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType(void) = 0 ;
	virtual unsigned __fastcall GetCalendarID(void) = 0 ;
	virtual TcxEra* __fastcall GetDefaultEra(void) = 0 ;
	virtual System::TDateTime __fastcall GetMaxSupportedDate(void) = 0 ;
	virtual System::TDateTime __fastcall GetMinSupportedDate(void) = 0 ;
	virtual void __fastcall CheckDateTime(System::TDateTime &ADateTime);
	virtual int __fastcall GetMaxSupportedYear(void) = 0 ;
	virtual int __fastcall GetMinSupportedYear(void) = 0 ;
	bool __fastcall IsNotValid(const TcxDateTime &ADate, /* out */ System::TDateTime &AResult);
	void __fastcall YearToGregorianYear(unsigned &AYear, int AEra);
	
public:
	__fastcall virtual TcxCustomCalendarTable(void);
	__fastcall virtual ~TcxCustomCalendarTable(void);
	virtual System::TDateTime __fastcall AddDays(const TcxDateTime &ADate, int ACountDays)/* overload */;
	virtual System::TDateTime __fastcall AddMonths(System::TDateTime ADate, int ACountMonths)/* overload */;
	virtual System::TDateTime __fastcall AddMonths(const TcxDateTime &ADate, int ACountMonths)/* overload */;
	virtual System::TDateTime __fastcall AddYears(System::TDateTime ADate, int ACountYears)/* overload */;
	virtual System::TDateTime __fastcall AddYears(const TcxDateTime &ADate, int ACountYears)/* overload */;
	virtual System::TDateTime __fastcall AddWeeks(System::TDateTime ADate, int ACountWeeks)/* overload */;
	virtual System::TDateTime __fastcall AddWeeks(const TcxDateTime &ADate, int ACountWeeks)/* overload */;
	virtual TcxDateTime __fastcall FromDateTime(System::TDateTime ADate) = 0 /* overload */;
	virtual TcxDateTime __fastcall FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual TcxDateTime __fastcall FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds)/* overload */;
	virtual unsigned __fastcall GetDayOfYear(System::TDateTime ADate)/* overload */;
	virtual unsigned __fastcall GetDayOfYear(const TcxDateTime &ADate)/* overload */;
	virtual unsigned __fastcall GetDaysInMonth(unsigned AYear, unsigned AMonth)/* overload */;
	virtual unsigned __fastcall GetDaysInMonth(int AEra, unsigned AYear, unsigned AMonth) = 0 /* overload */;
	virtual unsigned __fastcall GetDaysInYear(unsigned AYear)/* overload */;
	virtual unsigned __fastcall GetDaysInYear(int AEra, unsigned AYear) = 0 /* overload */;
	virtual int __fastcall GetEra(int AYear)/* overload */;
	virtual int __fastcall GetEra(int AYear, int AMonth, int ADay)/* overload */;
	virtual System::TDateTime __fastcall GetFirstDayOfWeek(System::TDateTime ADate)/* overload */;
	virtual System::TDateTime __fastcall GetFirstDayOfWeek(System::TDateTime ADate, TDay AStartDayOfWeek)/* overload */;
	virtual TcxDateTime __fastcall GetFirstDayOfWeek(const TcxDateTime &ADate)/* overload */;
	virtual TcxDateTime __fastcall GetFirstDayOfWeek(const TcxDateTime &ADate, TDay AStartDayOfWeek)/* overload */;
	virtual System::TDateTime __fastcall GetFirstDayOfMonth(const System::TDateTime ADate)/* overload */;
	virtual TcxDateTime __fastcall GetFirstDayOfMonth(const TcxDateTime &ADate)/* overload */;
	virtual System::TDateTime __fastcall GetFirstDayOfYear(const System::TDateTime ADate)/* overload */;
	virtual TcxDateTime __fastcall GetFirstDayOfYear(const TcxDateTime &ADate)/* overload */;
	virtual System::Byte __fastcall GetFirstWeekDay(void) = 0 ;
	virtual unsigned __fastcall GetFullWeeksInYear(unsigned AYear) = 0 ;
	virtual System::TDateTime __fastcall GetLastDayOfMonth(const System::TDateTime ADate)/* overload */;
	virtual TcxDateTime __fastcall GetLastDayOfMonth(const TcxDateTime &ADate)/* overload */;
	virtual System::TDateTime __fastcall GetLastDayOfYear(const System::TDateTime ADate)/* overload */;
	virtual TcxDateTime __fastcall GetLastDayOfYear(const TcxDateTime &ADate)/* overload */;
	virtual unsigned __fastcall GetMonthsInYear(unsigned AYear)/* overload */;
	virtual unsigned __fastcall GetMonthsInYear(int AEra, unsigned AYear) = 0 /* overload */;
	virtual unsigned __fastcall GetYear(System::TDateTime ADate)/* overload */;
	virtual unsigned __fastcall GetYear(const TcxDate &ADate)/* overload */;
	virtual unsigned __fastcall GetYear(const TcxDateTime &ADate)/* overload */;
	virtual System::Byte __fastcall GetWeekDay(System::TDateTime ADate)/* overload */;
	virtual System::Byte __fastcall GetWeekDay(const TcxDateTime &ADate)/* overload */;
	virtual unsigned __fastcall GetWeekNumber(System::TDateTime ADate, TDay AStartOfWeek, TcxFirstWeekOfYear AFirstWeekOfYear)/* overload */;
	virtual unsigned __fastcall GetWeekNumber(const TcxDateTime &ADate, TDay AStartOfWeek, TcxFirstWeekOfYear AFirstWeekOfYear) = 0 /* overload */;
	virtual bool __fastcall IsLeapDay(unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsLeapDay(int AEra, unsigned AYear, unsigned AMonth, unsigned ADay) = 0 /* overload */;
	virtual bool __fastcall IsLeapMonth(unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsLeapMonth(int AEra, unsigned AYear, unsigned AMonth) = 0 /* overload */;
	virtual bool __fastcall IsLeapYear(unsigned AYear)/* overload */;
	virtual bool __fastcall IsLeapYear(int AEra, unsigned Year) = 0 /* overload */;
	virtual bool __fastcall IsValidYear(unsigned AYear)/* overload */;
	virtual bool __fastcall IsValidYear(int AEra, unsigned AYear)/* overload */;
	virtual bool __fastcall IsValidMonth(unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsValidMonth(int AEra, unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsValidDay(unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsValidDay(int AEra, unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsValidDate(System::TDateTime ADate);
	virtual System::TDateTime __fastcall ToDateTime(const TcxDate &ADate)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(const TcxDateTime &ADateTime) = 0 /* overload */;
	virtual int __fastcall GetDayNumber(const System::UnicodeString S);
	virtual int __fastcall GetMonthNumber(int AYear, const System::UnicodeString S);
	virtual int __fastcall GetYearNumber(const System::UnicodeString S);
	__property TcxCalendarAlgorithmType AlgorithmType = {read=GetCalendarAlgorithmType, nodefault};
	__property unsigned CalendarID = {read=GetCalendarID, nodefault};
	__property TcxEra* DefaultEra = {read=GetDefaultEra};
	__property TcxEras* Eras = {read=FEras};
	__property System::TDateTime MaxSupportedDate = {read=GetMaxSupportedDate};
	__property System::TDateTime MinSupportedDate = {read=GetMinSupportedDate};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomCalendarTableClass;

typedef System::StaticArray<System::UnicodeString, 20> Cxdateutils__4;

//-- var, const, procedure ---------------------------------------------------
static const int NullDate = int(-700000);
static const int InvalidDate = int(-699999);
extern PACKAGE bool __fastcall (*SmartTextToDateFunc)(const System::UnicodeString AText, System::TDateTime &ADate);
extern PACKAGE int dxMinYear;
extern PACKAGE int dxMaxYear;
extern PACKAGE bool cxUseSingleCharWeekNames;
extern PACKAGE Cxdateutils__4 scxDateEditSmartInput;
extern PACKAGE System::UnicodeString __fastcall cxDateToLocalFormatStr(System::TDateTime ADate);
extern PACKAGE System::UnicodeString __fastcall cxDateToStr(System::TDateTime ADate)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxDateToStr(System::TDateTime ADate, const System::Sysutils::TFormatSettings &AFormat)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxDayNumberToLocalFormatStr(System::TDateTime ADate)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxDayNumberToLocalFormatStr(int ADay, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0))/* overload */;
extern PACKAGE System::WideChar __fastcall cxGetLocalDateSeparator(void);
extern PACKAGE System::Sysutils::TFormatSettings __fastcall cxGetLocalFormatSettings(void);
extern PACKAGE System::UnicodeString __fastcall cxGetLocalLongDateFormat(void);
extern PACKAGE System::UnicodeString __fastcall cxGetLocalLongTimeFormat(void);
extern PACKAGE System::UnicodeString __fastcall cxGetLocalMonthName(System::TDateTime ADate, TcxCustomCalendarTable* ACalendar)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxGetLocalMonthName(int AYear, int AMonth, TcxCustomCalendarTable* ACalendar)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxGetLocalMonthYear(System::TDateTime ADate, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0));
extern PACKAGE System::UnicodeString __fastcall cxGetLocalShortDateFormat(void);
extern PACKAGE System::UnicodeString __fastcall cxGetLocalTimeAMString(void);
extern PACKAGE System::UnicodeString __fastcall cxGetLocalTimePMString(void);
extern PACKAGE System::WideChar __fastcall cxGetLocalTimeSeparator(void);
extern PACKAGE System::UnicodeString __fastcall cxGetLocalYear(System::TDateTime ADate, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0));
extern PACKAGE System::UnicodeString __fastcall cxGetDayOfWeekName(TDay ADay, System::Uitypes::TFontCharset AFontCharset);
extern PACKAGE System::TDateTime __fastcall cxLocalFormatStrToDate(const System::UnicodeString ADateStr);
extern PACKAGE TcxDateTime __fastcall cxStrToDate(const System::UnicodeString ADateStr, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0))/* overload */;
extern PACKAGE TcxDateTime __fastcall cxStrToDate(const System::UnicodeString ADateStr, const System::Sysutils::TFormatSettings &AFormat, TcxCustomCalendarTable* ACalendar = (TcxCustomCalendarTable*)(0x0))/* overload */;
extern PACKAGE System::TDate __fastcall cxStrToDate(const System::UnicodeString ADateString, const System::Sysutils::TFormatSettings &AFormat, unsigned ACALTYPE)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxTimeToStr(System::TDateTime ATime)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxTimeToStr(System::TDateTime ATime, const System::UnicodeString ATimeFormat)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxTimeToStr(System::TDateTime ATime, const System::Sysutils::TFormatSettings &AFormatSettings)/* overload */;
extern PACKAGE int __fastcall cxGetCalendarInfo(unsigned Locale, unsigned Calendar, unsigned CalendType, System::WideChar * lpCalData, int cchData, PDWORD lpValue);
extern PACKAGE TcxCustomCalendarTable* __fastcall cxGetCalendar(unsigned ACalendType);
extern PACKAGE unsigned __fastcall cxGetLocalCalendarID(void);
extern PACKAGE TcxCustomCalendarTable* __fastcall cxGetLocalCalendar(void);
extern PACKAGE void __fastcall AddDateRegExprMaskSmartInput(System::UnicodeString &AMask, bool ACanEnterTime);
extern PACKAGE int __fastcall dxGetCalendarDateElement(System::TDateTime ADate, TcxDateElement AElement, TcxCustomCalendarTable* ACalendar);
extern PACKAGE bool __fastcall cxGetDateFormat(System::TDateTime ADate, /* out */ System::UnicodeString &AFormatDate, int AFlags, const System::UnicodeString AFormat = System::UnicodeString());
extern PACKAGE System::UnicodeString __fastcall DateToLongDateStr(System::TDateTime ADate);
extern PACKAGE bool __fastcall SmartTextToDate(const System::UnicodeString AText, System::TDateTime &ADate);
extern PACKAGE bool __fastcall TextToDateEx(System::UnicodeString AText, System::TDateTime &ADate, const System::UnicodeString AFormatString = System::UnicodeString());
extern PACKAGE System::UnicodeString __fastcall cxDateTimeToText(System::TDateTime ADate, bool AFourDigitYearNeeded = false, bool AUseDelphiDateTimeFormats = false);
extern PACKAGE System::TDateTime __fastcall cxTextToDateTime(const System::UnicodeString AText, bool AUseDelphiDateTimeFormats = false);
extern PACKAGE System::UnicodeString __fastcall DateTimeToText(System::TDateTime ADate, bool AFourDigitYearNeeded = false);
extern PACKAGE System::UnicodeString __fastcall DateTimeToTextEx(const System::TDateTime ADate, bool AIsMasked, bool AIsDateTimeEdit = false, bool AFourDigitYearNeeded = false);
extern PACKAGE bool __fastcall cxStrToDateTime(System::UnicodeString S, bool AUseOleDateFormat, /* out */ System::TDateTime &ADate);
extern PACKAGE void __fastcall dxDecMonth(System::Word &AYear, System::Word &AMonth);
extern PACKAGE void __fastcall dxIncMonth(System::Word &AYear, System::Word &AMonth)/* overload */;
extern PACKAGE void __fastcall dxChangeMonth(System::Word &AYear, System::Word &AMonth, int Delta);
extern PACKAGE bool __fastcall IsLeapYear(int AYear);
extern PACKAGE int __fastcall DaysPerMonth(int AYear, int AMonth);
extern PACKAGE int __fastcall CheckDay(int AYear, int AMonth, int ADay);
extern PACKAGE System::TDateTime __fastcall dxTimeOf(const System::TDateTime AValue);
extern PACKAGE System::TDateTime __fastcall dxDateOf(const System::TDateTime AValue);
extern PACKAGE bool __fastcall cxIsDateValid(double ADate);
extern PACKAGE int __fastcall dxGetDateElement(System::TDateTime ADate, TcxDateElement AElement);
extern PACKAGE System::TDateTime __fastcall dxGetStartDateOfMonth(const System::TDateTime ADate);
extern PACKAGE System::TDateTime __fastcall dxGetEndDateOfMonth(const System::TDateTime ADate, bool AIgnoreTime);
extern PACKAGE System::TDateTime __fastcall dxGetStartDateOfYear(const System::TDateTime ADate);
extern PACKAGE System::TDateTime __fastcall dxGetEndDateOfYear(const System::TDateTime ADate, bool AIgnoreTime);
extern PACKAGE TDay __fastcall dxGetStartOfWeek(void);
extern PACKAGE bool __fastcall dxGetAssignedStartOfWeek(void);
extern PACKAGE void __fastcall dxResetAssignedStartOfWeek(void);
extern PACKAGE void __fastcall dxSetStartOfWeek(TDay AValue);
extern PACKAGE TcxFirstWeekOfYear __fastcall dxGetLocalFirstWeekOfYear(void);
extern PACKAGE TDay __fastcall dxGetLocalStartOfWeek(void);
extern PACKAGE int __fastcall dxGetWeekNumber(System::TDateTime ADate, TDay AStartOfWeek, TcxFirstWeekOfYear AFirstWeekOfYear);
extern PACKAGE int __fastcall dxGetMonthNumber(const System::TDateTime ADate);
extern PACKAGE TDay __fastcall dxDayOfWeek(const System::TDateTime AValue);
extern PACKAGE TdxDayOfWeek __fastcall dxDayOfWeekOffset(const System::TDateTime AValue)/* overload */;
extern PACKAGE TdxDayOfWeek __fastcall dxDayOfWeekOffset(const System::TDateTime AValue, TDay AStartOfWeek)/* overload */;
extern PACKAGE TDay __fastcall dxDayOfWeekFromVCL(const TdxDayOfWeekVCL AValue);
extern PACKAGE TDay __fastcall dxDayOfWeekFromSystem(const TdxDayOfWeekSystem AValue);
extern PACKAGE TdxDayOfWeekVCL __fastcall dxDayOfWeekToVCL(TDay AValue);
extern PACKAGE TdxDayOfWeekSystem __fastcall dxDayOfWeekToSystem(TDay AValue);
extern PACKAGE TDay __fastcall dxGetDayOfWeek(TDay ADayFrom, int ADaysCount);
extern PACKAGE System::TDateTime __fastcall dxGetStartDateOfWeek(const System::TDateTime AValue);
}	/* namespace Cxdateutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDATEUTILS)
using namespace Cxdateutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdateutilsHPP
