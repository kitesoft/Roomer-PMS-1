// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerOutlookExchange.pas' rev: 24.00 (Win64)

#ifndef CxscheduleroutlookexchangeHPP
#define CxscheduleroutlookexchangeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <System.Win.ComObj.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxscheduleroutlookexchange
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (*TcxSchedulerExchangeProgressProc)(int ACurrent, int ACount, bool &Abort);

typedef bool __fastcall (*TcxAcceptEventExportFunc)(Cxschedulerstorage::TcxSchedulerEvent* AEvent);

typedef bool __fastcall (*TcxAcceptAppointmentItemImportFunc)(const System::OleVariant &AppointmentItem);

typedef void __fastcall (*TcxAppointmentItemToEventProc)(const System::OleVariant &AppointmentItem, Cxschedulerstorage::TcxSchedulerEvent* AEvent);

typedef void __fastcall (*TcxEventToAppointmentItemProc)(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::OleVariant &AppointmentItem);

class DELPHICLASS TcxAppointmentInfo;
class PASCALIMPLEMENTATION TcxAppointmentInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::OleVariant FAppointmentItem;
	System::UnicodeString FEntryID;
	
public:
	__fastcall TcxAppointmentInfo(const System::OleVariant &AAppointmentItem);
	__property System::OleVariant AppointmentItem = {read=FAppointmentItem};
	__property System::UnicodeString EntryID = {read=FEntryID};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxAppointmentInfo(void) { }
	
};


class DELPHICLASS TcxAppointmentEntryIDList;
class PASCALIMPLEMENTATION TcxAppointmentEntryIDList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxAppointmentInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxAppointmentInfo* __fastcall GetItems(int Index);
	
public:
	HIDESBASE void __fastcall Add(const System::OleVariant &AppointmentItem);
	System::OleVariant __fastcall ExtractAppointmentItem(int AIndex);
	bool __fastcall FindEntryID(const System::UnicodeString AEntryID, int &Index);
	int __fastcall IndexOfEntryID(const System::UnicodeString AEntryID);
	void __fastcall Populate(System::OleVariant &ACalendarFolder);
	__property TcxAppointmentInfo* Items[int Index] = {read=GetItems/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxAppointmentEntryIDList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxAppointmentEntryIDList(void) { }
	
};


class DELPHICLASS TcxEventInfo;
class PASCALIMPLEMENTATION TcxEventInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* FEvent;
	System::UnicodeString FEntryID;
	
public:
	__fastcall TcxEventInfo(Cxschedulerstorage::TcxSchedulerEvent* AEvent, Cxschedulerstorage::TcxCustomSchedulerStorageField* AEntryIDField);
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=FEvent};
	__property System::UnicodeString EntryID = {read=FEntryID};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEventInfo(void) { }
	
};


class DELPHICLASS TcxEventEntryIDList;
class PASCALIMPLEMENTATION TcxEventEntryIDList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxEventInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxEventInfo* __fastcall GetItem(int Index);
	
public:
	HIDESBASE void __fastcall Add(Cxschedulerstorage::TcxSchedulerEvent* AEvent, Cxschedulerstorage::TcxCustomSchedulerStorageField* AEntryIDField);
	void __fastcall DeleteEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall ExtractEvent(int AIndex);
	bool __fastcall FindEntryID(const System::UnicodeString AEntryID, int &Index);
	int __fastcall IndexOfEntryID(const System::UnicodeString AEntryID);
	void __fastcall Populate(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, Cxschedulerstorage::TcxCustomSchedulerStorageField* AEntryIDField);
	__property TcxEventInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxEventEntryIDList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxEventEntryIDList(void) { }
	
};


class DELPHICLASS TcxOutlookExchange;
class PASCALIMPLEMENTATION TcxOutlookExchange : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::OleVariant FCalendarFolder;
	bool FOleInitialized;
	System::OleVariant FOutlookApp;
	Cxschedulerstorage::TcxCustomSchedulerStorage* FStorage;
	bool FWasCreated;
	TcxAcceptAppointmentItemImportFunc FOnAcceptAppointmentItem;
	TcxAcceptEventExportFunc FOnAcceptEvent;
	TcxAppointmentItemToEventProc FOnConvertAppointmentItemToEvent;
	TcxEventToAppointmentItemProc FOnConvertEventToAppointmentItem;
	TcxSchedulerExchangeProgressProc FOnProgress;
	bool __fastcall GetAllDayEvent(const System::OleVariant &AppointmentItem);
	Cxdateutils::TDays __fastcall GetDaysOfWeekFromMask(int AMask);
	Cxschedulerstorage::TcxDayType __fastcall GetDayTypeFromMask(int AMask);
	int __fastcall GetMaskFromDaysOfWeek(Cxdateutils::TDays ADays);
	int __fastcall GetMaskFromDayType(Cxschedulerstorage::TcxDayType ADayType);
	
protected:
	bool __fastcall CanAcceptAppointmentItem(const System::OleVariant &AppointmentItem);
	bool __fastcall CanAcceptEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual bool __fastcall CanImportAppointmentItem(const System::OleVariant &AppointmentItem);
	void __fastcall ConvertAppointmentItemToEvent(const System::OleVariant &AppointmentItem, Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall ConvertEventToAppointmentItem(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::OleVariant &AppointmentItem);
	void __fastcall ImportRecurrenceChain(Cxschedulerstorage::TcxSchedulerEvent* APatternEvent, const System::OleVariant &ARecurrencePattern);
	void __fastcall CheckRecurrencePatternExceptions(const System::OleVariant &ARecurrencePattern, Cxschedulerstorage::TcxSchedulerEvent* APatternEvent);
	void __fastcall ExportRecurrenceChain(Cxschedulerstorage::TcxSchedulerEvent* APatternEvent, const System::OleVariant &AppointmentItem);
	void __fastcall ExportRecurrenceException(Cxschedulerstorage::TcxSchedulerEvent* APatternEvent, const System::TDateTime AStart);
	virtual bool __fastcall GetIsValid(void);
	bool __fastcall InitOleObject(void);
	void __fastcall PostCustomOccurrence(const System::OleVariant &ARecurrencePattern, const System::OleVariant &AException, Cxschedulerstorage::TcxSchedulerEvent* APatternEvent);
	virtual void __fastcall PostRecurrenceExeption(Cxschedulerstorage::TcxSchedulerEvent* AOccurrence);
	virtual System::TDateTime __fastcall RoundTime(System::TDateTime ATime, bool ASaveDate);
	void __fastcall SetAppointmentItemRecurrence(const System::OleVariant &ARecurrencePattern, Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall SetupAppointmentItemInfo(const System::OleVariant &AppointmentItem, Cxschedulerstorage::TcxSchedulerEvent* const AEvent, bool ASetTime = true);
	void __fastcall SetupEventInfo(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::OleVariant &AppointmentItem);
	void __fastcall SetupEventRecurrenceInfo(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::OleVariant &ARecurrencePattern);
	virtual void __fastcall UpdateAppointmentItem(const System::OleVariant &AppointmentItem, Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall UpdateEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::OleVariant &AppointmentItem, bool APostData = true);
	void __fastcall UpdateEventWithRecurrenceInfo(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::OleVariant &AppointmentItem);
	bool __fastcall DoProgress(int ACurrent, int ACount);
	__property System::OleVariant CalendarFolder = {read=FCalendarFolder};
	__property bool IsValid = {read=GetIsValid, nodefault};
	__property System::OleVariant OutlookApp = {read=FOutlookApp};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=FStorage};
	
public:
	__fastcall virtual TcxOutlookExchange(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage);
	__fastcall virtual ~TcxOutlookExchange(void);
	void __fastcall ExportEventToOutlook(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall ExportToOutlook(void);
	void __fastcall ImportAppointmentItemFromOutlook(const System::OleVariant &AppointmentItem);
	void __fastcall ImportFromOutlook(void);
	__property TcxAcceptAppointmentItemImportFunc OnAcceptAppointmentItem = {read=FOnAcceptAppointmentItem, write=FOnAcceptAppointmentItem};
	__property TcxAcceptEventExportFunc OnAcceptEvent = {read=FOnAcceptEvent, write=FOnAcceptEvent};
	__property TcxAppointmentItemToEventProc OnConvertAppointmentItemToEvent = {read=FOnConvertAppointmentItemToEvent, write=FOnConvertAppointmentItemToEvent};
	__property TcxEventToAppointmentItemProc OnConvertEventToAppointmentItem = {read=FOnConvertEventToAppointmentItem, write=FOnConvertEventToAppointmentItem};
	__property TcxSchedulerExchangeProgressProc OnProgress = {read=FOnProgress, write=FOnProgress};
};


class DELPHICLASS TcxOutlookSynchronize;
class PASCALIMPLEMENTATION TcxOutlookSynchronize : public TcxOutlookExchange
{
	typedef TcxOutlookExchange inherited;
	
private:
	Cxschedulerstorage::TcxCustomSchedulerStorageField* FEntryIDField;
	
protected:
	void __fastcall DeleteEventExceptions(Cxschedulerstorage::TcxSchedulerEvent* AEvent, TcxEventEntryIDList* AEntryIDs);
	void __fastcall DeleteUnsynchronizedAppointments(TcxAppointmentEntryIDList* AEntryIDs);
	void __fastcall DeleteUnsynchronizedEvents(TcxEventEntryIDList* AEntryIDs);
	System::UnicodeString __fastcall GetEntryIDFromEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual bool __fastcall GetIsValid(void);
	bool __fastcall IsEqualRecurrencePattern(const System::OleVariant &AppointmentItem, Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall PostRecurrenceExeption(Cxschedulerstorage::TcxSchedulerEvent* AOccurrence);
	void __fastcall PurgeDeletedOccurrences(Cxschedulerstorage::TcxSchedulerEvent* APatternEvent, TcxEventEntryIDList* AEntryIDs);
	virtual void __fastcall UpdateAppointmentItem(const System::OleVariant &AppointmentItem, Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall UpdateExistingAppointmentItem(const System::OleVariant &AppointmentItem, Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall UpdateExistingEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::OleVariant &AppointmentItem, TcxEventEntryIDList* AEntryIDs);
	virtual void __fastcall UpdateEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::OleVariant &AppointmentItem, bool APostData = true);
	void __fastcall SynchronizeRecurrenceChainWithOutlook(Cxschedulerstorage::TcxSchedulerEvent* APatternEvent, const System::OleVariant &ARecurrencePattern, TcxEventEntryIDList* AEntryIDs);
	
public:
	void __fastcall SynchronizeWithOutlook(bool ADeleteUnsynchronizedEvents = false);
	void __fastcall SynchronizeWithStorage(bool ADeleteUnsynchronizedAppointments = false);
	__property Cxschedulerstorage::TcxCustomSchedulerStorageField* EntryIDField = {read=FEntryIDField, write=FEntryIDField};
public:
	/* TcxOutlookExchange.Create */ inline __fastcall virtual TcxOutlookSynchronize(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage) : TcxOutlookExchange(AStorage) { }
	/* TcxOutlookExchange.Destroy */ inline __fastcall virtual ~TcxOutlookSynchronize(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall cxSchedulerExportToOutlook(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, TcxAcceptEventExportFunc AcceptFunc = 0x0, TcxEventToAppointmentItemProc AConvertProc = 0x0, TcxSchedulerExchangeProgressProc AProgressProc = 0x0);
extern PACKAGE void __fastcall cxSchedulerImportFromOutlook(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, TcxAcceptAppointmentItemImportFunc AcceptFunc = 0x0, TcxAppointmentItemToEventProc AConvertProc = 0x0, TcxSchedulerExchangeProgressProc AProgressProc = 0x0);
extern PACKAGE void __fastcall cxSchedulerSynchronizeOutlookWithStorage(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, Cxschedulerstorage::TcxCustomSchedulerStorageField* AppointmentItemIDField, bool ADeleteUnsynchronizedAppointments = false, TcxAcceptEventExportFunc AcceptFunc = 0x0, TcxEventToAppointmentItemProc AConvertProc = 0x0, TcxSchedulerExchangeProgressProc AProgressProc = 0x0);
extern PACKAGE void __fastcall cxSchedulerSynchronizeStorageWithOutlook(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, Cxschedulerstorage::TcxCustomSchedulerStorageField* AppointmentItemIDField, bool ADeleteUnsynchronizedEvents = false, TcxAcceptAppointmentItemImportFunc AcceptFunc = 0x0, TcxAppointmentItemToEventProc AConvertProc = 0x0, TcxSchedulerExchangeProgressProc AProgressProc = 0x0);
}	/* namespace Cxscheduleroutlookexchange */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULEROUTLOOKEXCHANGE)
using namespace Cxscheduleroutlookexchange;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxscheduleroutlookexchangeHPP
