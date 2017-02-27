// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerICalendar.pas' rev: 24.00 (Win32)

#ifndef CxschedulericalendarHPP
#define CxschedulericalendarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulericalendar
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxSchedulerICalendarCustomPropertyClass;

class DELPHICLASS TcxSchedulerICalendarCustomParameter;
class DELPHICLASS TcxSchedulerICalendarCustomProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarCustomParameter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual bool __fastcall ConvertPropertyToParameterValue(TcxSchedulerICalendarCustomProperty* AProperty, System::Variant &AValue);
	__classmethod virtual bool __fastcall ConvertPropertyFromParameterValue(TcxSchedulerICalendarCustomProperty* AProperty, const System::UnicodeString AParameterValue, System::Variant &AValue);
	__classmethod virtual System::UnicodeString __fastcall GetValue(TcxSchedulerICalendarCustomProperty* AProperty);
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarCustomProperty* AProperty, const System::UnicodeString ATranslateValue, /* out */ System::Variant &AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarCustomProperty* AProperty, const System::Variant &AValue, /* out */ System::UnicodeString &ATranslateValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarCustomParameter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarCustomParameter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSchedulerICalendarCustomParameterClass;

class DELPHICLASS TcxSchedulerICalendar;
class DELPHICLASS TcxSchedulerICalendarCustomObject;
class PASCALIMPLEMENTATION TcxSchedulerICalendarCustomProperty : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerICalendar* FICalendar;
	System::Classes::TList* FCustomParameters;
	TcxSchedulerICalendarCustomObject* FParent;
	System::TObject* FSchedulerObject;
	System::Variant FValue;
	int __fastcall GetCustomParameterCount(void);
	TcxSchedulerICalendarCustomParameterClass __fastcall GetCustomParameter(int Index);
	
protected:
	__classmethod virtual bool __fastcall IsBegin(const System::UnicodeString S);
	__classmethod virtual bool __fastcall IsEnd(const System::UnicodeString S);
	__classmethod virtual System::TClass __fastcall SchedulerObjectClass();
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual void __fastcall AfterExport(System::Classes::TStringList* AStrings);
	virtual void __fastcall AfterImport(System::Classes::TStringList* AStrings);
	virtual void __fastcall BeforeExport(System::Classes::TStringList* AStrings);
	virtual void __fastcall BeforeImport(System::Classes::TStringList* AStrings);
	virtual bool __fastcall CanExport(void);
	virtual bool __fastcall CanImport(void);
	virtual void __fastcall DoExport(System::Classes::TStringList* AStrings);
	virtual void __fastcall DoImport(System::Classes::TStringList* AStrings);
	virtual System::Variant __fastcall FromString(const System::UnicodeString AValue, const System::UnicodeString AParameters);
	HIDESBASE virtual System::UnicodeString __fastcall ToString(void);
	virtual void __fastcall Calculate(void);
	void __fastcall CreateSchedulerObject(void);
	virtual void __fastcall DoCreateSchedulerObject(void);
	void __fastcall AddCustomParameter(TcxSchedulerICalendarCustomParameterClass AClass);
	virtual void __fastcall RegisterCustomParameters(void);
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	__property int CustomParameterCount = {read=GetCustomParameterCount, nodefault};
	__property TcxSchedulerICalendarCustomParameterClass CustomParameters[int Index] = {read=GetCustomParameter};
	__property System::TObject* SchedulerObject = {read=FSchedulerObject};
	__property System::Variant Value = {read=GetValue, write=SetValue};
	
public:
	__fastcall virtual TcxSchedulerICalendarCustomProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent);
	__fastcall virtual ~TcxSchedulerICalendarCustomProperty(void);
	void __fastcall Export(System::Classes::TStringList* AStrings);
	void __fastcall Import(System::Classes::TStringList* AStrings);
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__property TcxSchedulerICalendar* ICalendar = {read=FICalendar};
	__property TcxSchedulerICalendarCustomObject* Parent = {read=FParent};
};


class PASCALIMPLEMENTATION TcxSchedulerICalendarCustomObject : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
private:
	System::Classes::TList* FProperties;
	TcxSchedulerICalendarCustomPropertyClass __fastcall GetProperty(int Index);
	int __fastcall GetPropertyCount(void);
	
protected:
	__classmethod virtual bool __fastcall IsBegin(const System::UnicodeString S);
	__classmethod virtual bool __fastcall IsEnd(const System::UnicodeString S);
	virtual void __fastcall AfterExport(System::Classes::TStringList* AStrings);
	virtual void __fastcall BeforeExport(System::Classes::TStringList* AStrings);
	virtual bool __fastcall CanExport(void);
	virtual bool __fastcall CanImport(void);
	virtual void __fastcall DoExport(System::Classes::TStringList* AStrings);
	virtual void __fastcall DoImport(System::Classes::TStringList* AStrings);
	void __fastcall AddProperty(TcxSchedulerICalendarCustomPropertyClass AProperty);
	virtual bool __fastcall CanHaveProperty(TcxSchedulerICalendarCustomPropertyClass AProperty);
	virtual void __fastcall PopulateProperties(void);
	__property TcxSchedulerICalendarCustomPropertyClass Properties[int Index] = {read=GetProperty};
	__property int PropertyCount = {read=GetPropertyCount, nodefault};
	
public:
	__fastcall virtual TcxSchedulerICalendarCustomObject(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent);
	__fastcall virtual ~TcxSchedulerICalendarCustomObject(void);
};


typedef System::TMetaClass* TcxSchedulerICalendarCustomObjectClass;

class DELPHICLASS TcxSchedulerICalendarLanguageParameter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarLanguageParameter : public TcxSchedulerICalendarCustomParameter
{
	typedef TcxSchedulerICalendarCustomParameter inherited;
	
protected:
	__classmethod virtual bool __fastcall ConvertPropertyToParameterValue(TcxSchedulerICalendarCustomProperty* AProperty, System::Variant &AValue);
	__classmethod virtual bool __fastcall ConvertPropertyFromParameterValue(TcxSchedulerICalendarCustomProperty* AProperty, const System::UnicodeString AParameterValue, System::Variant &AValue)/* overload */;
	__classmethod virtual System::UnicodeString __fastcall GetValue(TcxSchedulerICalendarCustomProperty* AProperty);
	__classmethod virtual System::UnicodeString __fastcall TokenName();
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarLanguageParameter(void) : TcxSchedulerICalendarCustomParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarLanguageParameter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarStringParameter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarStringParameter : public TcxSchedulerICalendarCustomParameter
{
	typedef TcxSchedulerICalendarCustomParameter inherited;
	
protected:
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarCustomProperty* AProperty, const System::UnicodeString ATranslateValue, /* out */ System::Variant &AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarCustomProperty* AProperty, const System::Variant &AValue, /* out */ System::UnicodeString &ATranslateValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarStringParameter(void) : TcxSchedulerICalendarCustomParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarStringParameter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarStringCustomProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarStringCustomProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
protected:
	virtual void __fastcall RegisterCustomParameters(void);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarStringCustomProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarStringCustomProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarRecurrenceCustomValue;
class DELPHICLASS TcxSchedulerICalendarRecurrenceCustomProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceCustomValue : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceCustomValue(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceCustomValue(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSchedulerICalendarRecurrenceCustomValueClass;

class DELPHICLASS TcxSchedulerICalendarRecurrenceTypeValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceTypeValue : public TcxSchedulerICalendarRecurrenceCustomValue
{
	typedef TcxSchedulerICalendarRecurrenceCustomValue inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceTypeValue(void) : TcxSchedulerICalendarRecurrenceCustomValue() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceTypeValue(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarRecurrenceCountValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceCountValue : public TcxSchedulerICalendarRecurrenceCustomValue
{
	typedef TcxSchedulerICalendarRecurrenceCustomValue inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceCountValue(void) : TcxSchedulerICalendarRecurrenceCustomValue() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceCountValue(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarRecurrenceUntilValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceUntilValue : public TcxSchedulerICalendarRecurrenceCustomValue
{
	typedef TcxSchedulerICalendarRecurrenceCustomValue inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceUntilValue(void) : TcxSchedulerICalendarRecurrenceCustomValue() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceUntilValue(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarRecurrenceIntervalValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceIntervalValue : public TcxSchedulerICalendarRecurrenceCustomValue
{
	typedef TcxSchedulerICalendarRecurrenceCustomValue inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceIntervalValue(void) : TcxSchedulerICalendarRecurrenceCustomValue() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceIntervalValue(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarRecurrenceByDayValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceByDayValue : public TcxSchedulerICalendarRecurrenceCustomValue
{
	typedef TcxSchedulerICalendarRecurrenceCustomValue inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceByDayValue(void) : TcxSchedulerICalendarRecurrenceCustomValue() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceByDayValue(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarRecurrenceByMonthValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceByMonthValue : public TcxSchedulerICalendarRecurrenceCustomValue
{
	typedef TcxSchedulerICalendarRecurrenceCustomValue inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceByMonthValue(void) : TcxSchedulerICalendarRecurrenceCustomValue() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceByMonthValue(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarRecurrenceByMonthDayValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceByMonthDayValue : public TcxSchedulerICalendarRecurrenceCustomValue
{
	typedef TcxSchedulerICalendarRecurrenceCustomValue inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceByMonthDayValue(void) : TcxSchedulerICalendarRecurrenceCustomValue() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceByMonthDayValue(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarRecurrenceBySetPosValue;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceBySetPosValue : public TcxSchedulerICalendarRecurrenceCustomValue
{
	typedef TcxSchedulerICalendarRecurrenceCustomValue inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, const System::UnicodeString AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarRecurrenceCustomProperty* AProperty, /* out */ System::UnicodeString &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarRecurrenceBySetPosValue(void) : TcxSchedulerICalendarRecurrenceCustomValue() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarRecurrenceBySetPosValue(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxSchedulerICalendarRecurrenceCustomProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
private:
	System::Classes::TList* FValueParameters;
	TcxSchedulerICalendarRecurrenceCustomValueClass __fastcall GetValueParameter(int Index);
	int __fastcall GetValueParameterCount(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	void __fastcall AddValueParameter(TcxSchedulerICalendarRecurrenceCustomValueClass AParameter);
	void __fastcall PopulateValueParameters(void);
	virtual Cxdateutils::TDays __fastcall GetByDay(void) = 0 ;
	virtual int __fastcall GetByDayWeek(Cxdateutils::TDay ADay);
	virtual int __fastcall GetByMonth(void) = 0 ;
	virtual int __fastcall GetByMonthDay(void) = 0 ;
	virtual int __fastcall GetBySetPos(void) = 0 ;
	virtual int __fastcall GetCount(void) = 0 ;
	virtual int __fastcall GetInterval(void) = 0 ;
	virtual Cxschedulerstorage::TcxRecurrence __fastcall GetRecurrenceType(void) = 0 ;
	virtual System::TDateTime __fastcall GetRecurrenceUntil(void) = 0 ;
	virtual void __fastcall SetByDay(Cxdateutils::TDays AValue) = 0 ;
	virtual void __fastcall SetByDayWeek(Cxdateutils::TDay ADay, int AValue);
	virtual void __fastcall SetByMonth(int AValue) = 0 ;
	virtual void __fastcall SetByMonthDay(int AValue) = 0 ;
	virtual void __fastcall SetBySetPos(int AValue) = 0 ;
	virtual void __fastcall SetCount(int AValue) = 0 ;
	virtual void __fastcall SetInterval(int AValue) = 0 ;
	virtual void __fastcall SetRecurrenceType(Cxschedulerstorage::TcxRecurrence AValue) = 0 ;
	virtual void __fastcall SetRecurrenceUntil(System::TDateTime AValue) = 0 ;
	__property TcxSchedulerICalendarRecurrenceCustomValueClass ValueParameters[int Index] = {read=GetValueParameter};
	__property int ValueParameterCount = {read=GetValueParameterCount, nodefault};
	
public:
	__fastcall virtual TcxSchedulerICalendarRecurrenceCustomProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent);
	__fastcall virtual ~TcxSchedulerICalendarRecurrenceCustomProperty(void);
	__property Cxdateutils::TDays ByDay = {read=GetByDay, write=SetByDay, nodefault};
	__property int ByDayWeek[Cxdateutils::TDay ADay] = {read=GetByDayWeek, write=SetByDayWeek};
	__property int ByMonth = {read=GetByMonth, write=SetByMonth, nodefault};
	__property int ByMonthDay = {read=GetByMonthDay, write=SetByMonthDay, nodefault};
	__property int BySetPos = {read=GetBySetPos, write=SetBySetPos, nodefault};
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property int Interval = {read=GetInterval, write=SetInterval, nodefault};
	__property Cxschedulerstorage::TcxRecurrence RecurrenceType = {read=GetRecurrenceType, write=SetRecurrenceType, nodefault};
	__property System::TDateTime RecurrenceUntil = {read=GetRecurrenceUntil, write=SetRecurrenceUntil};
};


class DELPHICLASS TcxSchedulerICalendarTZIDParameter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarTZIDParameter : public TcxSchedulerICalendarCustomParameter
{
	typedef TcxSchedulerICalendarCustomParameter inherited;
	
protected:
	__classmethod virtual bool __fastcall ConvertPropertyToParameterValue(TcxSchedulerICalendarCustomProperty* AProperty, System::Variant &AValue);
	__classmethod virtual bool __fastcall ConvertPropertyFromParameterValue(TcxSchedulerICalendarCustomProperty* AProperty, const System::UnicodeString AParameterValue, System::Variant &AValue)/* overload */;
	__classmethod virtual System::UnicodeString __fastcall GetValue(TcxSchedulerICalendarCustomProperty* AProperty);
	__classmethod virtual System::UnicodeString __fastcall TokenName();
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarTZIDParameter(void) : TcxSchedulerICalendarCustomParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTZIDParameter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarDateParameter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarDateParameter : public TcxSchedulerICalendarCustomParameter
{
	typedef TcxSchedulerICalendarCustomParameter inherited;
	
protected:
	__classmethod virtual bool __fastcall ConvertPropertyToParameterValue(TcxSchedulerICalendarCustomProperty* AProperty, System::Variant &AValue);
	__classmethod virtual System::UnicodeString __fastcall GetValue(TcxSchedulerICalendarCustomProperty* AProperty);
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarCustomProperty* AProperty, const System::UnicodeString ATranslateValue, /* out */ System::Variant &AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarCustomProperty* AProperty, const System::Variant &AValue, /* out */ System::UnicodeString &ATranslateValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarDateParameter(void) : TcxSchedulerICalendarCustomParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarDateParameter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarDateTimeParameter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarDateTimeParameter : public TcxSchedulerICalendarDateParameter
{
	typedef TcxSchedulerICalendarDateParameter inherited;
	
protected:
	__classmethod virtual bool __fastcall ConvertPropertyToParameterValue(TcxSchedulerICalendarCustomProperty* AProperty, System::Variant &AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarCustomProperty* AProperty, const System::Variant &AValue, /* out */ System::UnicodeString &ATranslateValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarDateTimeParameter(void) : TcxSchedulerICalendarDateParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarDateTimeParameter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarDateTimeCustomProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarDateTimeCustomProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
private:
	int FTimeZone;
	bool FUseDateFormat;
	
protected:
	virtual void __fastcall RegisterCustomParameters(void);
	__property int TimeZone = {read=FTimeZone, write=FTimeZone, nodefault};
	__property bool UseDateFormat = {read=FUseDateFormat, write=FUseDateFormat, nodefault};
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarDateTimeCustomProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarDateTimeCustomProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarTZIDProperty;
class DELPHICLASS TcxSchedulerICalendarTimeZoneObject;
class PASCALIMPLEMENTATION TcxSchedulerICalendarTZIDProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
private:
	TcxSchedulerICalendarTimeZoneObject* __fastcall GetParent(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual void __fastcall RegisterCustomParameters(void);
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	
public:
	__property TcxSchedulerICalendarTimeZoneObject* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarTZIDProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTZIDProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarTimeZoneStartProperty;
class DELPHICLASS TcxSchedulerICalendarTimeZoneCustomRule;
class PASCALIMPLEMENTATION TcxSchedulerICalendarTimeZoneStartProperty : public TcxSchedulerICalendarDateTimeCustomProperty
{
	typedef TcxSchedulerICalendarDateTimeCustomProperty inherited;
	
private:
	TcxSchedulerICalendarTimeZoneCustomRule* __fastcall GetParent(void);
	
protected:
	virtual void __fastcall Calculate(void);
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	
public:
	__property TcxSchedulerICalendarTimeZoneCustomRule* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarTimeZoneStartProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarDateTimeCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTimeZoneStartProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarTimeZoneRuleCustomProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarTimeZoneRuleCustomProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
private:
	TcxSchedulerICalendarTimeZoneCustomRule* __fastcall GetParent(void);
	
protected:
	int __fastcall GetCurrentTimeZone(void);
	Cxschedulerutils::TcxTimeZoneInformation __fastcall GetTimeZoneInformation(void);
	System::UnicodeString __fastcall FromUtcOffset(const System::TDateTime AValue);
	
public:
	__property TcxSchedulerICalendarTimeZoneCustomRule* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarTimeZoneRuleCustomProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTimeZoneRuleCustomProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarTZOffsetToProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarTZOffsetToProperty : public TcxSchedulerICalendarTimeZoneRuleCustomProperty
{
	typedef TcxSchedulerICalendarTimeZoneRuleCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarTZOffsetToProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarTimeZoneRuleCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTZOffsetToProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarTZOffsetFromProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarTZOffsetFromProperty : public TcxSchedulerICalendarTimeZoneRuleCustomProperty
{
	typedef TcxSchedulerICalendarTimeZoneRuleCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarTZOffsetFromProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarTimeZoneRuleCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTZOffsetFromProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarTimeZoneRuleRecurrence;
class PASCALIMPLEMENTATION TcxSchedulerICalendarTimeZoneRuleRecurrence : public TcxSchedulerICalendarRecurrenceCustomProperty
{
	typedef TcxSchedulerICalendarRecurrenceCustomProperty inherited;
	
private:
	TcxSchedulerICalendarTimeZoneCustomRule* __fastcall GetParent(void);
	
protected:
	virtual bool __fastcall CanExport(void);
	virtual Cxdateutils::TDays __fastcall GetByDay(void);
	virtual int __fastcall GetByDayWeek(Cxdateutils::TDay ADay);
	virtual int __fastcall GetByMonth(void);
	virtual int __fastcall GetByMonthDay(void);
	virtual int __fastcall GetBySetPos(void);
	virtual int __fastcall GetCount(void);
	virtual int __fastcall GetInterval(void);
	virtual Cxschedulerstorage::TcxRecurrence __fastcall GetRecurrenceType(void);
	virtual System::TDateTime __fastcall GetRecurrenceUntil(void);
	virtual void __fastcall SetByDay(Cxdateutils::TDays AValue);
	virtual void __fastcall SetByDayWeek(Cxdateutils::TDay ADay, int AValue);
	virtual void __fastcall SetByMonth(int AValue);
	virtual void __fastcall SetByMonthDay(int AValue);
	virtual void __fastcall SetBySetPos(int AValue);
	virtual void __fastcall SetCount(int AValue);
	virtual void __fastcall SetInterval(int AValue);
	virtual void __fastcall SetRecurrenceType(Cxschedulerstorage::TcxRecurrence AValue);
	virtual void __fastcall SetRecurrenceUntil(System::TDateTime AValue);
	__property TcxSchedulerICalendarTimeZoneCustomRule* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarRecurrenceCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarTimeZoneRuleRecurrence(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarRecurrenceCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarRecurrenceCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTimeZoneRuleRecurrence(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerICalendarTimeZoneCustomRule : public TcxSchedulerICalendarCustomObject
{
	typedef TcxSchedulerICalendarCustomObject inherited;
	
private:
	System::TDateTime FBias;
	System::TDateTime FUtcOffset;
	TcxSchedulerICalendarTimeZoneObject* __fastcall GetParent(void);
	
protected:
	virtual void __fastcall Calculate(void);
	virtual bool __fastcall CanExport(void);
	virtual void __fastcall PopulateProperties(void);
	Cxdateutils::TDay __fastcall GetDayOfWeek(void);
	virtual bool __fastcall IsStandardRule(void);
	System::TDateTime __fastcall GetStart(void);
	
public:
	__property TcxSchedulerICalendarTimeZoneObject* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomObject.Create */ inline __fastcall virtual TcxSchedulerICalendarTimeZoneCustomRule(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomObject(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTimeZoneCustomRule(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarTimeZoneStandardRule;
class PASCALIMPLEMENTATION TcxSchedulerICalendarTimeZoneStandardRule : public TcxSchedulerICalendarTimeZoneCustomRule
{
	typedef TcxSchedulerICalendarTimeZoneCustomRule inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
public:
	/* TcxSchedulerICalendarCustomObject.Create */ inline __fastcall virtual TcxSchedulerICalendarTimeZoneStandardRule(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarTimeZoneCustomRule(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTimeZoneStandardRule(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarTimeZoneDaylightRule;
class PASCALIMPLEMENTATION TcxSchedulerICalendarTimeZoneDaylightRule : public TcxSchedulerICalendarTimeZoneCustomRule
{
	typedef TcxSchedulerICalendarTimeZoneCustomRule inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual bool __fastcall IsStandardRule(void);
public:
	/* TcxSchedulerICalendarCustomObject.Create */ inline __fastcall virtual TcxSchedulerICalendarTimeZoneDaylightRule(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarTimeZoneCustomRule(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTimeZoneDaylightRule(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerICalendarTimeZoneObject : public TcxSchedulerICalendarCustomObject
{
	typedef TcxSchedulerICalendarCustomObject inherited;
	
private:
	System::TDateTime __fastcall InternalSystemTimeToDateTime(const _SYSTEMTIME &ADate);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual void __fastcall PopulateProperties(void);
	System::TDateTime __fastcall GetDaylightDate(void);
	System::TDateTime __fastcall GetStandatdDate(void);
	Cxdateutils::TDay __fastcall GetDaylightDayOfWeek(void);
	Cxdateutils::TDay __fastcall GetStandardDayOfWeek(void);
	int __fastcall GetCurrentTimeZone(void);
	Cxschedulerutils::TcxTimeZoneInformation __fastcall GetTimeZoneInformation(void);
	bool __fastcall UseOnlyStandardTime(void);
public:
	/* TcxSchedulerICalendarCustomObject.Create */ inline __fastcall virtual TcxSchedulerICalendarTimeZoneObject(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomObject(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarTimeZoneObject(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventDateTimeProperty;
class DELPHICLASS TcxSchedulerICalendarEventObject;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventDateTimeProperty : public TcxSchedulerICalendarDateTimeCustomProperty
{
	typedef TcxSchedulerICalendarDateTimeCustomProperty inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEvent(void);
	TcxSchedulerICalendarEventObject* __fastcall GetParent(void);
	
protected:
	virtual void __fastcall Calculate(void);
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=GetEvent};
	__property TcxSchedulerICalendarEventObject* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventDateTimeProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarDateTimeCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventDateTimeProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventStampProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventStampProperty : public TcxSchedulerICalendarEventDateTimeProperty
{
	typedef TcxSchedulerICalendarEventDateTimeProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventStampProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventDateTimeProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventStampProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventStartProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventStartProperty : public TcxSchedulerICalendarEventDateTimeProperty
{
	typedef TcxSchedulerICalendarEventDateTimeProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventStartProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventDateTimeProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventStartProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventEndProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventEndProperty : public TcxSchedulerICalendarEventDateTimeProperty
{
	typedef TcxSchedulerICalendarEventDateTimeProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventEndProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventDateTimeProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventEndProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventCustomProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventCustomProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEvent(void);
	TcxSchedulerICalendarEventObject* __fastcall GetParent(void);
	
protected:
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=GetEvent};
	__property TcxSchedulerICalendarEventObject* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventCustomProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventCustomProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventUIDProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventUIDProperty : public TcxSchedulerICalendarEventCustomProperty
{
	typedef TcxSchedulerICalendarEventCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventUIDProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventUIDProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventRecurrenceProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventRecurrenceProperty : public TcxSchedulerICalendarRecurrenceCustomProperty
{
	typedef TcxSchedulerICalendarRecurrenceCustomProperty inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEvent(void);
	TcxSchedulerICalendarEventObject* __fastcall GetParent(void);
	Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* __fastcall GetRecurrenceInfo(void);
	
protected:
	virtual bool __fastcall CanExport(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	virtual Cxdateutils::TDays __fastcall GetByDay(void);
	virtual int __fastcall GetByMonth(void);
	virtual int __fastcall GetByMonthDay(void);
	virtual int __fastcall GetBySetPos(void);
	virtual int __fastcall GetCount(void);
	virtual int __fastcall GetInterval(void);
	virtual Cxschedulerstorage::TcxRecurrence __fastcall GetRecurrenceType(void);
	virtual System::TDateTime __fastcall GetRecurrenceUntil(void);
	virtual void __fastcall SetByDay(Cxdateutils::TDays AValue);
	virtual void __fastcall SetByMonth(int AValue);
	virtual void __fastcall SetByMonthDay(int AValue);
	virtual void __fastcall SetBySetPos(int AValue);
	virtual void __fastcall SetCount(int AValue);
	virtual void __fastcall SetInterval(int AValue);
	virtual void __fastcall SetRecurrenceType(Cxschedulerstorage::TcxRecurrence AValue);
	virtual void __fastcall SetRecurrenceUntil(System::TDateTime AValue);
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=GetEvent};
	__property TcxSchedulerICalendarEventObject* Parent = {read=GetParent};
	__property Cxschedulerstorage::TcxSchedulerEventRecurrenceInfo* RecurrenceInfo = {read=GetRecurrenceInfo};
public:
	/* TcxSchedulerICalendarRecurrenceCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventRecurrenceProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarRecurrenceCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarRecurrenceCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventRecurrenceProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventStringProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventStringProperty : public TcxSchedulerICalendarStringCustomProperty
{
	typedef TcxSchedulerICalendarStringCustomProperty inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEvent(void);
	TcxSchedulerICalendarEventObject* __fastcall GetParent(void);
	
protected:
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=GetEvent};
	__property TcxSchedulerICalendarEventObject* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventStringProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarStringCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventStringProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventDescriptionProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventDescriptionProperty : public TcxSchedulerICalendarEventStringProperty
{
	typedef TcxSchedulerICalendarEventStringProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventDescriptionProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventStringProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventDescriptionProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventLocationProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventLocationProperty : public TcxSchedulerICalendarEventStringProperty
{
	typedef TcxSchedulerICalendarEventStringProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventLocationProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventStringProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventLocationProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventSummaryProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventSummaryProperty : public TcxSchedulerICalendarEventStringProperty
{
	typedef TcxSchedulerICalendarEventStringProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventSummaryProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventStringProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventSummaryProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventStatusProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventStatusProperty : public TcxSchedulerICalendarEventCustomProperty
{
	typedef TcxSchedulerICalendarEventCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventStatusProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventStatusProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventLabelProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventLabelProperty : public TcxSchedulerICalendarEventCustomProperty
{
	typedef TcxSchedulerICalendarEventCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventLabelProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventLabelProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarEventResourcesProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventResourcesProperty : public TcxSchedulerICalendarEventStringProperty
{
	typedef TcxSchedulerICalendarEventStringProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarEventResourcesProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarEventStringProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventResourcesProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarAlarmCustomProperty;
class DELPHICLASS TcxSchedulerICalendarAlarmObject;
class PASCALIMPLEMENTATION TcxSchedulerICalendarAlarmCustomProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEvent(void);
	TcxSchedulerICalendarAlarmObject* __fastcall GetParent(void);
	
protected:
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=GetEvent};
	__property TcxSchedulerICalendarAlarmObject* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarAlarmCustomProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarAlarmCustomProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarAlarmTriggerParameter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerICalendarAlarmTriggerParameter : public TcxSchedulerICalendarCustomParameter
{
	typedef TcxSchedulerICalendarCustomParameter inherited;
	
protected:
	__classmethod virtual bool __fastcall FromString(TcxSchedulerICalendarCustomProperty* AProperty, const System::UnicodeString ATranslateValue, /* out */ System::Variant &AValue);
	__classmethod virtual bool __fastcall ToString(TcxSchedulerICalendarCustomProperty* AProperty, const System::Variant &AValue, /* out */ System::UnicodeString &ATranslateValue);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerICalendarAlarmTriggerParameter(void) : TcxSchedulerICalendarCustomParameter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarAlarmTriggerParameter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerICalendarAlarmTriggerProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarAlarmTriggerProperty : public TcxSchedulerICalendarAlarmCustomProperty
{
	typedef TcxSchedulerICalendarAlarmCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual void __fastcall RegisterCustomParameters(void);
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarAlarmTriggerProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarAlarmCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarAlarmTriggerProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarAlarmActionProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarAlarmActionProperty : public TcxSchedulerICalendarAlarmCustomProperty
{
	typedef TcxSchedulerICalendarAlarmCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarAlarmActionProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarAlarmCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarAlarmActionProperty(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerICalendarAlarmObject : public TcxSchedulerICalendarCustomObject
{
	typedef TcxSchedulerICalendarCustomObject inherited;
	
private:
	TcxSchedulerICalendarEventObject* __fastcall GetParent(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual bool __fastcall CanExport(void);
	virtual void __fastcall PopulateProperties(void);
	__property TcxSchedulerICalendarEventObject* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomObject.Create */ inline __fastcall virtual TcxSchedulerICalendarAlarmObject(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomObject(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarAlarmObject(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarStorageObject;
class PASCALIMPLEMENTATION TcxSchedulerICalendarEventObject : public TcxSchedulerICalendarCustomObject
{
	typedef TcxSchedulerICalendarCustomObject inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEvent(void);
	bool __fastcall GetIsAllDayEvent(void);
	void __fastcall SetIsAllDayEvent(bool Value);
	TcxSchedulerICalendarStorageObject* __fastcall GetParent(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual System::TClass __fastcall SchedulerObjectClass();
	virtual void __fastcall AfterImport(System::Classes::TStringList* AStrings);
	virtual void __fastcall DoCreateSchedulerObject(void);
	virtual void __fastcall PopulateProperties(void);
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=GetEvent};
	__property bool IsAllDayEvent = {read=GetIsAllDayEvent, write=SetIsAllDayEvent, nodefault};
	__property TcxSchedulerICalendarStorageObject* Parent = {read=GetParent};
public:
	/* TcxSchedulerICalendarCustomObject.Create */ inline __fastcall virtual TcxSchedulerICalendarEventObject(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomObject(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarEventObject(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarVersionProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarVersionProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarVersionProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarVersionProperty(void) { }
	
};


class DELPHICLASS TcxSchedulerICalendarProdIDProperty;
class PASCALIMPLEMENTATION TcxSchedulerICalendarProdIDProperty : public TcxSchedulerICalendarCustomProperty
{
	typedef TcxSchedulerICalendarCustomProperty inherited;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	virtual System::Variant __fastcall GetValue(void);
public:
	/* TcxSchedulerICalendarCustomProperty.Create */ inline __fastcall virtual TcxSchedulerICalendarProdIDProperty(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomProperty(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomProperty.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarProdIDProperty(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerICalendarStorageObject : public TcxSchedulerICalendarCustomObject
{
	typedef TcxSchedulerICalendarCustomObject inherited;
	
private:
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall TokenName();
	__classmethod virtual System::TClass __fastcall SchedulerObjectClass();
	virtual void __fastcall DoExport(System::Classes::TStringList* AStrings);
	virtual bool __fastcall CanHaveProperty(TcxSchedulerICalendarCustomPropertyClass AProperty);
	virtual void __fastcall PopulateProperties(void);
	virtual void __fastcall DoCreateSchedulerObject(void);
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=GetStorage};
public:
	/* TcxSchedulerICalendarCustomObject.Create */ inline __fastcall virtual TcxSchedulerICalendarStorageObject(TcxSchedulerICalendar* AICalendar, TcxSchedulerICalendarCustomObject* AParent) : TcxSchedulerICalendarCustomObject(AICalendar, AParent) { }
	/* TcxSchedulerICalendarCustomObject.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendarStorageObject(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerICalendar : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::TDateTime FDateTime;
	int FTimeZone;
	Cxschedulerstorage::TcxCustomSchedulerStorage* FStorage;
	
protected:
	virtual bool __fastcall CanExport(TcxSchedulerICalendarCustomObject* AObject);
	virtual bool __fastcall CanImport(TcxSchedulerICalendarCustomObject* AObject);
	void __fastcall ExportObject(System::TObject* AObject, TcxSchedulerICalendarCustomObject* AParent, System::Classes::TStringList* AStrings);
	void __fastcall ImportObject(TcxSchedulerICalendarCustomObject* AParent, System::Classes::TStringList* AStrings);
	int __fastcall FindTimeZone(const System::UnicodeString AName);
	int __fastcall GetStorageTimeZone(void);
	__property int TimeZone = {read=FTimeZone, write=FTimeZone, nodefault};
	
public:
	__fastcall TcxSchedulerICalendar(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage);
	void __fastcall Export(const System::UnicodeString AFileName);
	void __fastcall Import(const System::UnicodeString AFileName);
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=FStorage};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerICalendar(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString cxSchedulerICalendarProdID;
extern PACKAGE void __fastcall cxSchedulerICalendarExport(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, const System::UnicodeString AFileName);
extern PACKAGE void __fastcall cxSchedulerICalendarImport(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, const System::UnicodeString AFileName);
}	/* namespace Cxschedulericalendar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERICALENDAR)
using namespace Cxschedulericalendar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulericalendarHPP
