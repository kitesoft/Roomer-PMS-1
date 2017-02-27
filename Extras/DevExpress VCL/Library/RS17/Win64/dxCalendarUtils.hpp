// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCalendarUtils.pas' rev: 24.00 (Win64)

#ifndef DxcalendarutilsHPP
#define DxcalendarutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcalendarutils
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGregorianCalendarTable;
class PASCALIMPLEMENTATION TcxGregorianCalendarTable : public Cxdateutils::TcxCustomCalendarTable
{
	typedef Cxdateutils::TcxCustomCalendarTable inherited;
	
private:
	Cxdateutils::TcxEra* FDefaultEra;
	
protected:
	virtual Cxdateutils::TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType(void);
	virtual unsigned __fastcall GetCalendarID(void);
	virtual Cxdateutils::TcxEra* __fastcall GetDefaultEra(void);
	virtual System::TDateTime __fastcall GetMaxSupportedDate(void);
	virtual System::TDateTime __fastcall GetMinSupportedDate(void);
	virtual int __fastcall GetMaxSupportedYear(void);
	virtual int __fastcall GetMinSupportedYear(void);
	
public:
	__fastcall virtual TcxGregorianCalendarTable(void);
	__fastcall virtual ~TcxGregorianCalendarTable(void);
	virtual Cxdateutils::TcxDateTime __fastcall FromDateTime(System::TDateTime ADate)/* overload */;
	virtual System::Byte __fastcall GetFirstWeekDay(void);
	virtual unsigned __fastcall GetWeekNumber(Cxdateutils::TcxDateTime &ADate, Cxdateutils::TDay AStartOfWeek, Cxdateutils::TcxFirstWeekOfYear AFirstWeekOfYear)/* overload */;
	virtual unsigned __fastcall GetDaysInMonth(int AEra, unsigned AYear, unsigned AMonth)/* overload */;
	virtual unsigned __fastcall GetDaysInYear(int AEra, unsigned AYear)/* overload */;
	virtual unsigned __fastcall GetFullWeeksInYear(unsigned AYear);
	virtual unsigned __fastcall GetMonthsInYear(int AEra, unsigned AYear)/* overload */;
	virtual bool __fastcall IsLeapDay(int AEra, unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsLeapMonth(int AEra, unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsLeapYear(int AEra, unsigned AYear)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(Cxdateutils::TcxDateTime &ADateTime)/* overload */;
/* Hoisted overloads: */
	
public:
	inline Cxdateutils::TcxDateTime __fastcall  FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::FromDateTime(AYear, AMonth, ADay); }
	inline Cxdateutils::TcxDateTime __fastcall  FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds){ return Cxdateutils::TcxCustomCalendarTable::FromDateTime(AYear, AMonth, ADay, AHours, AMinutes, ASeconds, AMilliseconds); }
	inline unsigned __fastcall  GetWeekNumber(System::TDateTime ADate, Cxdateutils::TDay AStartOfWeek, Cxdateutils::TcxFirstWeekOfYear AFirstWeekOfYear){ return Cxdateutils::TcxCustomCalendarTable::GetWeekNumber(ADate, AStartOfWeek, AFirstWeekOfYear); }
	inline unsigned __fastcall  GetDaysInMonth(unsigned AYear, unsigned AMonth){ return Cxdateutils::TcxCustomCalendarTable::GetDaysInMonth(AYear, AMonth); }
	inline unsigned __fastcall  GetDaysInYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::GetDaysInYear(AYear); }
	inline unsigned __fastcall  GetMonthsInYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::GetMonthsInYear(AYear); }
	inline bool __fastcall  IsLeapDay(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::IsLeapDay(AYear, AMonth, ADay); }
	inline bool __fastcall  IsLeapMonth(unsigned AYear, unsigned AMonth){ return Cxdateutils::TcxCustomCalendarTable::IsLeapMonth(AYear, AMonth); }
	inline bool __fastcall  IsLeapYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::IsLeapYear(AYear); }
	inline System::TDateTime __fastcall  ToDateTime(Cxdateutils::TcxDate &ADate){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(ADate); }
	inline System::TDateTime __fastcall  ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(AYear, AMonth, ADay); }
	inline System::TDateTime __fastcall  ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(AYear, AMonth, ADay, AHours, AMinutes, ASeconds, AMilliseconds); }
	
};


class DELPHICLASS TcxGregorianUSEnglishCalendarTable;
class PASCALIMPLEMENTATION TcxGregorianUSEnglishCalendarTable : public TcxGregorianCalendarTable
{
	typedef TcxGregorianCalendarTable inherited;
	
protected:
	virtual unsigned __fastcall GetCalendarID(void);
public:
	/* TcxGregorianCalendarTable.Create */ inline __fastcall virtual TcxGregorianUSEnglishCalendarTable(void) : TcxGregorianCalendarTable() { }
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxGregorianUSEnglishCalendarTable(void) { }
	
};


class DELPHICLASS TcxGregorianMiddleEastFrenchCalendarTable;
class PASCALIMPLEMENTATION TcxGregorianMiddleEastFrenchCalendarTable : public TcxGregorianCalendarTable
{
	typedef TcxGregorianCalendarTable inherited;
	
protected:
	virtual unsigned __fastcall GetCalendarID(void);
	
public:
	virtual System::Byte __fastcall GetFirstWeekDay(void);
public:
	/* TcxGregorianCalendarTable.Create */ inline __fastcall virtual TcxGregorianMiddleEastFrenchCalendarTable(void) : TcxGregorianCalendarTable() { }
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxGregorianMiddleEastFrenchCalendarTable(void) { }
	
};


class DELPHICLASS TcxGregorianArabicCalendarTable;
class PASCALIMPLEMENTATION TcxGregorianArabicCalendarTable : public TcxGregorianCalendarTable
{
	typedef TcxGregorianCalendarTable inherited;
	
protected:
	virtual unsigned __fastcall GetCalendarID(void);
	
public:
	virtual System::Byte __fastcall GetFirstWeekDay(void);
public:
	/* TcxGregorianCalendarTable.Create */ inline __fastcall virtual TcxGregorianArabicCalendarTable(void) : TcxGregorianCalendarTable() { }
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxGregorianArabicCalendarTable(void) { }
	
};


class DELPHICLASS TcxGregorianTransliteratedEnglishCalendarTable;
class PASCALIMPLEMENTATION TcxGregorianTransliteratedEnglishCalendarTable : public TcxGregorianCalendarTable
{
	typedef TcxGregorianCalendarTable inherited;
	
protected:
	virtual unsigned __fastcall GetCalendarID(void);
	
public:
	virtual System::Byte __fastcall GetFirstWeekDay(void);
public:
	/* TcxGregorianCalendarTable.Create */ inline __fastcall virtual TcxGregorianTransliteratedEnglishCalendarTable(void) : TcxGregorianCalendarTable() { }
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxGregorianTransliteratedEnglishCalendarTable(void) { }
	
};


class DELPHICLASS TcxGregorianTransliteratedFrenchCalendarTable;
class PASCALIMPLEMENTATION TcxGregorianTransliteratedFrenchCalendarTable : public TcxGregorianCalendarTable
{
	typedef TcxGregorianCalendarTable inherited;
	
protected:
	virtual unsigned __fastcall GetCalendarID(void);
	
public:
	virtual System::Byte __fastcall GetFirstWeekDay(void);
public:
	/* TcxGregorianCalendarTable.Create */ inline __fastcall virtual TcxGregorianTransliteratedFrenchCalendarTable(void) : TcxGregorianCalendarTable() { }
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxGregorianTransliteratedFrenchCalendarTable(void) { }
	
};


class DELPHICLASS TcxJapaneseCalendarTable;
class PASCALIMPLEMENTATION TcxJapaneseCalendarTable : public TcxGregorianCalendarTable
{
	typedef TcxGregorianCalendarTable inherited;
	
protected:
	virtual Cxdateutils::TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType(void);
	virtual unsigned __fastcall GetCalendarID(void);
	virtual Cxdateutils::TcxEra* __fastcall GetDefaultEra(void);
	virtual System::TDateTime __fastcall GetMaxSupportedDate(void);
	virtual System::TDateTime __fastcall GetMinSupportedDate(void);
	virtual int __fastcall GetMaxSupportedYear(void);
	virtual int __fastcall GetMinSupportedYear(void);
	
public:
	__fastcall virtual TcxJapaneseCalendarTable(void);
	virtual Cxdateutils::TcxDateTime __fastcall FromDateTime(System::TDateTime ADate)/* overload */;
	virtual System::Byte __fastcall GetFirstWeekDay(void);
	virtual System::TDateTime __fastcall ToDateTime(Cxdateutils::TcxDateTime &ADateTime)/* overload */;
public:
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxJapaneseCalendarTable(void) { }
	
/* Hoisted overloads: */
	
public:
	inline Cxdateutils::TcxDateTime __fastcall  FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::FromDateTime(AYear, AMonth, ADay); }
	inline Cxdateutils::TcxDateTime __fastcall  FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds){ return Cxdateutils::TcxCustomCalendarTable::FromDateTime(AYear, AMonth, ADay, AHours, AMinutes, ASeconds, AMilliseconds); }
	inline System::TDateTime __fastcall  ToDateTime(Cxdateutils::TcxDate &ADate){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(ADate); }
	inline System::TDateTime __fastcall  ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(AYear, AMonth, ADay); }
	inline System::TDateTime __fastcall  ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(AYear, AMonth, ADay, AHours, AMinutes, ASeconds, AMilliseconds); }
	
};


class DELPHICLASS TcxTaiwanCalendarTable;
class PASCALIMPLEMENTATION TcxTaiwanCalendarTable : public TcxJapaneseCalendarTable
{
	typedef TcxJapaneseCalendarTable inherited;
	
protected:
	virtual Cxdateutils::TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType(void);
	virtual unsigned __fastcall GetCalendarID(void);
	virtual Cxdateutils::TcxEra* __fastcall GetDefaultEra(void);
	virtual System::TDateTime __fastcall GetMinSupportedDate(void);
	virtual int __fastcall GetMaxSupportedYear(void);
	virtual int __fastcall GetMinSupportedYear(void);
	
public:
	__fastcall virtual TcxTaiwanCalendarTable(void);
public:
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxTaiwanCalendarTable(void) { }
	
};


class DELPHICLASS TcxKoreanCalendarTable;
class PASCALIMPLEMENTATION TcxKoreanCalendarTable : public TcxJapaneseCalendarTable
{
	typedef TcxJapaneseCalendarTable inherited;
	
protected:
	virtual Cxdateutils::TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType(void);
	virtual unsigned __fastcall GetCalendarID(void);
	virtual Cxdateutils::TcxEra* __fastcall GetDefaultEra(void);
	virtual System::TDateTime __fastcall GetMinSupportedDate(void);
	virtual int __fastcall GetMaxSupportedYear(void);
	virtual int __fastcall GetMinSupportedYear(void);
	
public:
	__fastcall virtual TcxKoreanCalendarTable(void);
public:
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxKoreanCalendarTable(void) { }
	
};


class DELPHICLASS TcxHijriCalendarTable;
class PASCALIMPLEMENTATION TcxHijriCalendarTable : public Cxdateutils::TcxCustomCalendarTable
{
	typedef Cxdateutils::TcxCustomCalendarTable inherited;
	
private:
	Cxdateutils::TcxEra* FDefaultEra;
	
protected:
	virtual Cxdateutils::TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType(void);
	virtual unsigned __fastcall GetCalendarID(void);
	virtual Cxdateutils::TcxEra* __fastcall GetDefaultEra(void);
	virtual System::TDateTime __fastcall GetMaxSupportedDate(void);
	virtual System::TDateTime __fastcall GetMinSupportedDate(void);
	virtual int __fastcall GetMaxSupportedYear(void);
	virtual int __fastcall GetMinSupportedYear(void);
	
public:
	__fastcall virtual TcxHijriCalendarTable(void);
	__fastcall virtual ~TcxHijriCalendarTable(void);
	virtual Cxdateutils::TcxDateTime __fastcall FromDateTime(System::TDateTime ADate)/* overload */;
	virtual System::Byte __fastcall GetFirstWeekDay(void);
	virtual unsigned __fastcall GetWeekNumber(Cxdateutils::TcxDateTime &ADate, Cxdateutils::TDay AStartOfWeek, Cxdateutils::TcxFirstWeekOfYear AFirstWeekOfYear)/* overload */;
	virtual unsigned __fastcall GetDaysInMonth(int AEra, unsigned AYear, unsigned AMonth)/* overload */;
	virtual unsigned __fastcall GetDaysInYear(int AEra, unsigned AYear)/* overload */;
	virtual unsigned __fastcall GetFullWeeksInYear(unsigned AYear);
	virtual unsigned __fastcall GetMonthsInYear(int AEra, unsigned AYear)/* overload */;
	virtual bool __fastcall IsLeapDay(int AEra, unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsLeapMonth(int AEra, unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsLeapYear(int AEra, unsigned AYear)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(Cxdateutils::TcxDateTime &ADateTime)/* overload */;
	virtual int __fastcall GetMonthNumber(int AYear, const System::UnicodeString S);
/* Hoisted overloads: */
	
public:
	inline Cxdateutils::TcxDateTime __fastcall  FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::FromDateTime(AYear, AMonth, ADay); }
	inline Cxdateutils::TcxDateTime __fastcall  FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds){ return Cxdateutils::TcxCustomCalendarTable::FromDateTime(AYear, AMonth, ADay, AHours, AMinutes, ASeconds, AMilliseconds); }
	inline unsigned __fastcall  GetWeekNumber(System::TDateTime ADate, Cxdateutils::TDay AStartOfWeek, Cxdateutils::TcxFirstWeekOfYear AFirstWeekOfYear){ return Cxdateutils::TcxCustomCalendarTable::GetWeekNumber(ADate, AStartOfWeek, AFirstWeekOfYear); }
	inline unsigned __fastcall  GetDaysInMonth(unsigned AYear, unsigned AMonth){ return Cxdateutils::TcxCustomCalendarTable::GetDaysInMonth(AYear, AMonth); }
	inline unsigned __fastcall  GetDaysInYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::GetDaysInYear(AYear); }
	inline unsigned __fastcall  GetMonthsInYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::GetMonthsInYear(AYear); }
	inline bool __fastcall  IsLeapDay(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::IsLeapDay(AYear, AMonth, ADay); }
	inline bool __fastcall  IsLeapMonth(unsigned AYear, unsigned AMonth){ return Cxdateutils::TcxCustomCalendarTable::IsLeapMonth(AYear, AMonth); }
	inline bool __fastcall  IsLeapYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::IsLeapYear(AYear); }
	inline System::TDateTime __fastcall  ToDateTime(Cxdateutils::TcxDate &ADate){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(ADate); }
	inline System::TDateTime __fastcall  ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(AYear, AMonth, ADay); }
	inline System::TDateTime __fastcall  ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(AYear, AMonth, ADay, AHours, AMinutes, ASeconds, AMilliseconds); }
	
};


class DELPHICLASS TcxThaiCalendarTable;
class PASCALIMPLEMENTATION TcxThaiCalendarTable : public TcxJapaneseCalendarTable
{
	typedef TcxJapaneseCalendarTable inherited;
	
protected:
	virtual Cxdateutils::TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType(void);
	virtual unsigned __fastcall GetCalendarID(void);
	virtual Cxdateutils::TcxEra* __fastcall GetDefaultEra(void);
	virtual System::TDateTime __fastcall GetMinSupportedDate(void);
	virtual int __fastcall GetMaxSupportedYear(void);
	virtual int __fastcall GetMinSupportedYear(void);
	
public:
	__fastcall virtual TcxThaiCalendarTable(void);
public:
	/* TcxGregorianCalendarTable.Destroy */ inline __fastcall virtual ~TcxThaiCalendarTable(void) { }
	
};


enum TcxHebrewCalendarTableTypeYear : unsigned char { hctyDeficient = 1, hctyNormal, hctyPerfect };

class DELPHICLASS TcxHebrewCalendarTable;
class PASCALIMPLEMENTATION TcxHebrewCalendarTable : public Cxdateutils::TcxCustomCalendarTable
{
	typedef Cxdateutils::TcxCustomCalendarTable inherited;
	
private:
	Cxdateutils::TcxEra* FDefaultEra;
	int __fastcall GetDayDifference(int ALunarYearType, int AMonth, int ADay, int ALunarMonth, int ALunarDay);
	int __fastcall HebrewNumber(const System::UnicodeString S);
	void __fastcall GetLunarMonthDay(int AYear, Cxdateutils::TcxDate &ADate);
	
protected:
	virtual Cxdateutils::TcxCalendarAlgorithmType __fastcall GetCalendarAlgorithmType(void);
	virtual unsigned __fastcall GetCalendarID(void);
	virtual Cxdateutils::TcxEra* __fastcall GetDefaultEra(void);
	virtual System::TDateTime __fastcall GetMaxSupportedDate(void);
	virtual System::TDateTime __fastcall GetMinSupportedDate(void);
	virtual int __fastcall GetMaxSupportedYear(void);
	virtual int __fastcall GetMinSupportedYear(void);
	
public:
	__fastcall virtual TcxHebrewCalendarTable(void);
	__fastcall virtual ~TcxHebrewCalendarTable(void);
	virtual Cxdateutils::TcxDateTime __fastcall FromDateTime(System::TDateTime ADate)/* overload */;
	virtual System::Byte __fastcall GetFirstWeekDay(void);
	TcxHebrewCalendarTableTypeYear __fastcall GetYearType(unsigned AYear);
	virtual unsigned __fastcall GetWeekNumber(Cxdateutils::TcxDateTime &ADate, Cxdateutils::TDay AStartOfWeek, Cxdateutils::TcxFirstWeekOfYear AFirstWeekOfYear)/* overload */;
	virtual unsigned __fastcall GetDaysInMonth(int AEra, unsigned AYear, unsigned AMonth)/* overload */;
	virtual unsigned __fastcall GetDaysInYear(int AEra, unsigned AYear)/* overload */;
	virtual unsigned __fastcall GetFullWeeksInYear(unsigned AYear);
	virtual unsigned __fastcall GetMonthsInYear(int AEra, unsigned AYear)/* overload */;
	virtual bool __fastcall IsLeapDay(int AEra, unsigned AYear, unsigned AMonth, unsigned ADay)/* overload */;
	virtual bool __fastcall IsLeapMonth(int AEra, unsigned AYear, unsigned AMonth)/* overload */;
	virtual bool __fastcall IsLeapYear(int AEra, unsigned AYear)/* overload */;
	virtual System::TDateTime __fastcall ToDateTime(Cxdateutils::TcxDateTime &ADateTime)/* overload */;
	virtual int __fastcall GetDayNumber(const System::UnicodeString S);
	virtual int __fastcall GetMonthNumber(int AYear, const System::UnicodeString S);
	virtual int __fastcall GetYearNumber(const System::UnicodeString S);
/* Hoisted overloads: */
	
public:
	inline Cxdateutils::TcxDateTime __fastcall  FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::FromDateTime(AYear, AMonth, ADay); }
	inline Cxdateutils::TcxDateTime __fastcall  FromDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds){ return Cxdateutils::TcxCustomCalendarTable::FromDateTime(AYear, AMonth, ADay, AHours, AMinutes, ASeconds, AMilliseconds); }
	inline unsigned __fastcall  GetWeekNumber(System::TDateTime ADate, Cxdateutils::TDay AStartOfWeek, Cxdateutils::TcxFirstWeekOfYear AFirstWeekOfYear){ return Cxdateutils::TcxCustomCalendarTable::GetWeekNumber(ADate, AStartOfWeek, AFirstWeekOfYear); }
	inline unsigned __fastcall  GetDaysInMonth(unsigned AYear, unsigned AMonth){ return Cxdateutils::TcxCustomCalendarTable::GetDaysInMonth(AYear, AMonth); }
	inline unsigned __fastcall  GetDaysInYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::GetDaysInYear(AYear); }
	inline unsigned __fastcall  GetMonthsInYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::GetMonthsInYear(AYear); }
	inline bool __fastcall  IsLeapDay(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::IsLeapDay(AYear, AMonth, ADay); }
	inline bool __fastcall  IsLeapMonth(unsigned AYear, unsigned AMonth){ return Cxdateutils::TcxCustomCalendarTable::IsLeapMonth(AYear, AMonth); }
	inline bool __fastcall  IsLeapYear(unsigned AYear){ return Cxdateutils::TcxCustomCalendarTable::IsLeapYear(AYear); }
	inline System::TDateTime __fastcall  ToDateTime(Cxdateutils::TcxDate &ADate){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(ADate); }
	inline System::TDateTime __fastcall  ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(AYear, AMonth, ADay); }
	inline System::TDateTime __fastcall  ToDateTime(unsigned AYear, unsigned AMonth, unsigned ADay, System::Byte AHours, System::Byte AMinutes, System::Byte ASeconds, System::Word AMilliseconds){ return Cxdateutils::TcxCustomCalendarTable::ToDateTime(AYear, AMonth, ADay, AHours, AMinutes, ASeconds, AMilliseconds); }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxdateutils::TcxCustomCalendarTableClass __fastcall cxGetCalendarClass(unsigned ACalendType);
extern PACKAGE bool __fastcall cxIsGregorianCalendar(Cxdateutils::TcxCustomCalendarTable* ACalendar = (Cxdateutils::TcxCustomCalendarTable*)(0x0));
}	/* namespace Dxcalendarutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCALENDARUTILS)
using namespace Dxcalendarutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcalendarutilsHPP
