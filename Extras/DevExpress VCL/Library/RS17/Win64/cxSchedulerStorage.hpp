// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerStorage.pas' rev: 24.00 (Win64)

#ifndef CxschedulerstorageHPP
#define CxschedulerstorageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxFormats.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerHolidays.hpp>	// Pascal unit
#include <cxDataConsts.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerstorage
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxCustomSchedulerStorageClass;

typedef System::TMetaClass* TcxSchedulerCachedEventListClass;

typedef System::TMetaClass* TcxSchedulerStorageResourcesClass;

typedef System::TMetaClass* TcxSchedulerStorageResourceItemClass;

class DELPHICLASS TcxSchedulerEvent;
typedef void __fastcall (__closure *TcxSchedulerForEachEventHandlerProc)(TcxSchedulerEvent* AEvent, void * AData);

typedef System::TMetaClass* TcxSchedulerReminderClass;

enum TcxEventType : unsigned char { etNone, etPattern, etOccurrence, etException, etCustom };

enum TcxRecurrence : unsigned char { cxreDaily, cxreWeekly, cxreMonthly, cxreYearly };

enum TcxRecurrenceValidStatus : unsigned char { rvsValid, rvsReplaceOccurrenceDate, rvsInvalidPattern, rvsInvalidDuration };

enum TcxDayType : unsigned char { cxdtDay, cxdtEveryDay, cxdtWeekDay, cxdtWeekEndDay, cxdtSunday, cxdtMonday, cxdtTuesday, cxdtWednesday, cxdtThursday, cxdtFriday, cxdtSaturday };

typedef int __fastcall (*TcxCompareEventsProc)(TcxSchedulerEvent* AEvent1, TcxSchedulerEvent* AEvent2);

class DELPHICLASS TcxSchedulerEventRecurrenceInfo;
typedef System::UnicodeString __fastcall (*TcxGetRecurrenceDescriptionStringProc)(TcxSchedulerEventRecurrenceInfo* ARecurrenceInfo, bool AFullDescription/* = false*/);

enum TcxSchedulerReminderDueTimeElement : unsigned char { dteMinute, dteHour, dteDay, dteWeek };

enum TcxSchedulerReminderDueTimeKind : unsigned char { dtkNow, dtkOverdue, dtkActual };

struct DECLSPEC_DRECORD TcxSchedulerReminderDueTimeInfo
{
public:
	TcxSchedulerReminderDueTimeKind DueKind;
	TcxSchedulerReminderDueTimeElement Element;
	int ElementValue;
	int Minutes;
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSchedulerReminderResource
{
public:
	System::TDateTime DismissDate;
	System::Variant ResourceID;
	System::TDateTime ReminderDate;
};
#pragma pack(pop)


typedef System::DynamicArray<TcxSchedulerReminderResource> TcxSchedulerReminderResources;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSchedulerReminderResourcesData
{
public:
	System::Byte Version;
	TcxSchedulerReminderResources Resources;
};
#pragma pack(pop)


typedef System::UnicodeString __fastcall (*TcxDueTimeInfoToTextProc)(const TcxSchedulerReminderDueTimeInfo &AInfo);

__interface IcxSchedulerStorageListener;
typedef System::DelphiInterface<IcxSchedulerStorageListener> _di_IcxSchedulerStorageListener;
__interface  INTERFACE_UUID("{87E0EBF3-F68A-4A51-8EA3-850D3819FBAB}") IcxSchedulerStorageListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall StorageChanged(System::TObject* Sender) = 0 ;
	virtual void __fastcall StorageRemoved(System::TObject* Sender) = 0 ;
};

__interface IcxSchedulerStorageListener2;
typedef System::DelphiInterface<IcxSchedulerStorageListener2> _di_IcxSchedulerStorageListener2;
__interface  INTERFACE_UUID("{4809FF3B-D9F8-4FD5-8647-33F8892599A4}") IcxSchedulerStorageListener2  : public IcxSchedulerStorageListener 
{
	
public:
	virtual void __fastcall AddEvent(TcxSchedulerEvent* AEvent) = 0 ;
	virtual void __fastcall RemoveEvent(TcxSchedulerEvent* AEvent) = 0 ;
};

__interface IcxSchedulerSelectionAdapter;
typedef System::DelphiInterface<IcxSchedulerSelectionAdapter> _di_IcxSchedulerSelectionAdapter;
class DELPHICLASS TcxSchedulerControlEvent;
__interface  INTERFACE_UUID("{68B007E5-1057-40DE-BDA4-0D72F3780CC7}") IcxSchedulerSelectionAdapter  : public System::IInterface 
{
	
public:
	virtual void __fastcall Add(TcxSchedulerControlEvent* AEvent, System::Classes::TShiftState Shift) = 0 ;
	virtual void __fastcall Clear(void) = 0 ;
	virtual bool __fastcall IsSelected(TcxSchedulerControlEvent* AEvent) = 0 ;
	virtual void __fastcall Update(void) = 0 ;
};

class DELPHICLASS TcxDoublyLinkedEventListData;
class PASCALIMPLEMENTATION TcxDoublyLinkedEventListData : public Dxcoreclasses::TcxDoublyLinkedData
{
	typedef Dxcoreclasses::TcxDoublyLinkedData inherited;
	
private:
	TcxSchedulerEvent* __fastcall GetEvent(void);
	TcxDoublyLinkedEventListData* __fastcall GetNext(void);
	TcxDoublyLinkedEventListData* __fastcall GetPrev(void);
	void __fastcall SetNext(TcxDoublyLinkedEventListData* const AValue);
	void __fastcall SetPrev(TcxDoublyLinkedEventListData* const AValue);
	
public:
	__property TcxSchedulerEvent* Event = {read=GetEvent};
	__property TcxDoublyLinkedEventListData* Next = {read=GetNext, write=SetNext};
	__property TcxDoublyLinkedEventListData* Prev = {read=GetPrev, write=SetPrev};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedEventListData(void) : Dxcoreclasses::TcxDoublyLinkedData() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedEventListData(void) { }
	
};


class DELPHICLASS TcxDoublyLinkedEventList;
class PASCALIMPLEMENTATION TcxDoublyLinkedEventList : public Dxcoreclasses::TcxDoublyLinkedDataList
{
	typedef Dxcoreclasses::TcxDoublyLinkedDataList inherited;
	
private:
	HIDESBASE TcxDoublyLinkedEventListData* __fastcall GetFirst(void);
	TcxDoublyLinkedEventListData* __fastcall GetLast(void);
	
public:
	HIDESBASE TcxDoublyLinkedEventListData* __fastcall Add(TcxSchedulerEvent* AEvent);
	virtual void __fastcall FreeEvents(void);
	virtual Dxcoreclasses::TcxDoublyLinkedObjectClass __fastcall GetLinkedObjectClass(void);
	void __fastcall ForEach(TcxSchedulerForEachEventHandlerProc AProc, void * AData, bool AGoForward = true);
	__property TcxDoublyLinkedEventListData* First = {read=GetFirst};
	__property TcxDoublyLinkedEventListData* Last = {read=GetLast};
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedEventList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedEventList(void) : Dxcoreclasses::TcxDoublyLinkedDataList() { }
	
};


class DELPHICLASS TcxSchedulerStorageDataController;
class DELPHICLASS TcxCustomSchedulerStorage;
class DELPHICLASS TcxCustomSchedulerStorageField;
class PASCALIMPLEMENTATION TcxSchedulerStorageDataController : public Cxcustomdata::TcxCustomDataController
{
	typedef Cxcustomdata::TcxCustomDataController inherited;
	
private:
	TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	
protected:
	void __fastcall ForEachEvent(TcxSchedulerForEachEventHandlerProc AProc, void * AData, bool AGoForward);
	void __fastcall InitializeEventFromRecordIndex(TcxSchedulerEvent* AEvent, void * AData);
	void __fastcall InitializeEventHandles(void);
	void __fastcall InitializeRecordIndexes(void);
	void __fastcall InitializeRecordIndexFromEvent(TcxSchedulerEvent* AEvent, void * AData);
	void __fastcall InsertValueDef(TcxCustomSchedulerStorageField* AField);
	void __fastcall InsertValueDefProc(TcxSchedulerEvent* AEvent, void * AData);
	void __fastcall RemoveValueDef(TcxCustomSchedulerStorageField* AField);
	void __fastcall RemoveValueDefProc(TcxSchedulerEvent* AEvent, void * AData);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual bool __fastcall UseRecordID(void);
	__property TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	
public:
	virtual void __fastcall ChangeValueTypeClass(int AItemIndex, Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	virtual System::TObject* __fastcall GetItem(int Index);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall UpdateItemIndexes(void);
public:
	/* TcxCustomDataController.Create */ inline __fastcall virtual TcxSchedulerStorageDataController(System::Classes::TComponent* AOwner) : Cxcustomdata::TcxCustomDataController(AOwner) { }
	/* TcxCustomDataController.Destroy */ inline __fastcall virtual ~TcxSchedulerStorageDataController(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerStorageDataControllerClass;

class PASCALIMPLEMENTATION TcxCustomSchedulerStorageField : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	int FIndex;
	bool FIsUnique;
	System::UnicodeString FName;
	bool __fastcall IsValueTypeStored(void);
	TcxSchedulerStorageDataController* __fastcall GetDataController(void);
	TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	System::Variant __fastcall GetValue(TcxSchedulerEvent* AEvent);
	int __fastcall GetValueCount(void);
	Cxdatastorage::TcxValueDef* __fastcall GetValueDef(void);
	System::UnicodeString __fastcall GetValueType(void);
	Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	void __fastcall SetName(const System::UnicodeString AValue);
	void __fastcall SetValue(TcxSchedulerEvent* AEvent, const System::Variant &AValue);
	void __fastcall SetValueType(const System::UnicodeString AValue);
	virtual void __fastcall SetValueTypeClass(Cxdatastorage::TcxValueTypeClass AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual bool __fastcall GetIsActive(void);
	virtual bool __fastcall GetIsBlob(void);
	virtual bool __fastcall GetIsTextStored(void);
	__property TcxSchedulerStorageDataController* DataController = {read=GetDataController};
	__property bool IsBlob = {read=GetIsBlob, nodefault};
	__property bool IsUnique = {read=FIsUnique, nodefault};
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property Cxdatastorage::TcxValueDef* ValueDef = {read=GetValueDef};
	__property System::Variant Values[TcxSchedulerEvent* AEvent] = {read=GetValue, write=SetValue};
	__property System::UnicodeString ValueType = {read=GetValueType, write=SetValueType, stored=IsValueTypeStored};
	__property Cxdatastorage::TcxValueTypeClass ValueTypeClass = {read=GetValueTypeClass, write=SetValueTypeClass};
	
public:
	__fastcall virtual TcxCustomSchedulerStorageField(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxCustomSchedulerStorageField(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool IsActive = {read=GetIsActive, nodefault};
	__property int Index = {read=FIndex, nodefault};
};


typedef System::TMetaClass* TcxSchedulerStorageFieldClass;

class DELPHICLASS TcxSchedulerStorageField;
class PASCALIMPLEMENTATION TcxSchedulerStorageField : public TcxCustomSchedulerStorageField
{
	typedef TcxCustomSchedulerStorageField inherited;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property ValueCount;
	__property Values;
	__property ValueTypeClass;
	
__published:
	__property Index;
	__property Name = {default=0};
	__property ValueType = {default=0};
public:
	/* TcxCustomSchedulerStorageField.Create */ inline __fastcall virtual TcxSchedulerStorageField(System::Classes::TCollection* Collection) : TcxCustomSchedulerStorageField(Collection) { }
	/* TcxCustomSchedulerStorageField.Destroy */ inline __fastcall virtual ~TcxSchedulerStorageField(void) { }
	
};


class DELPHICLASS TcxCustomSchedulerStorageFields;
class PASCALIMPLEMENTATION TcxCustomSchedulerStorageFields : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	
protected:
	virtual TcxCustomSchedulerStorageField* __fastcall FindFieldByName(const System::UnicodeString AName);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__property TcxCustomSchedulerStorage* Storage = {read=GetStorage};
public:
	/* TCollection.Create */ inline __fastcall TcxCustomSchedulerStorageFields(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxCustomSchedulerStorageFields(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerStorageFieldsClass;

class DELPHICLASS TcxSchedulerStorageFields;
class PASCALIMPLEMENTATION TcxSchedulerStorageFields : public TcxCustomSchedulerStorageFields
{
	typedef TcxCustomSchedulerStorageFields inherited;
	
private:
	HIDESBASE TcxSchedulerStorageField* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxSchedulerStorageField* AValue);
	
public:
	HIDESBASE TcxSchedulerStorageField* __fastcall Add(void);
	TcxSchedulerStorageField* __fastcall ItemByName(const System::UnicodeString AName);
	__property TcxSchedulerStorageField* Items[int Index] = {read=GetItem, write=SetItem};
	__property Storage;
public:
	/* TCollection.Create */ inline __fastcall TcxSchedulerStorageFields(System::Classes::TCollectionItemClass ItemClass) : TcxCustomSchedulerStorageFields(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxSchedulerStorageFields(void) { }
	
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSchedulerEventRecurrenceInfoData
{
public:
	int Count;
	int DayNumber;
	TcxDayType DayType;
	System::TDateTime Finish;
	Cxdateutils::TDays OccurDays;
	int Periodicity;
	TcxRecurrence Recurrence;
	System::TDateTime Start;
	int YearPeriodicity;
	System::Byte Reserved1;
	int DismissDate;
};
#pragma pack(pop)


class DELPHICLASS TcxSchedulerFilteredEventList;
class PASCALIMPLEMENTATION TcxSchedulerEventRecurrenceInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	double FDisplayTimeBias;
	TcxSchedulerEvent* FOwner;
	int __fastcall GetCount(void);
	int __fastcall GetDayNumber(void);
	TcxDayType __fastcall GetDayType(void);
	System::TDateTime __fastcall GetDismissDate(void);
	System::TDateTime __fastcall GetFinish(void);
	bool __fastcall GetIsInfinity(void);
	Cxdateutils::TDays __fastcall GetOccurDays(void);
	int __fastcall GetPeriodicity(void);
	TcxRecurrence __fastcall GetRecurrence(void);
	System::TDateTime __fastcall GetStart(void);
	TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	int __fastcall GetYearPeriodicity(void);
	void __fastcall SetCount(const int AValue);
	void __fastcall SetDayNumber(const int AValue);
	void __fastcall SetDayType(const TcxDayType AValue);
	void __fastcall SetDismissDate(const System::TDateTime AValue);
	void __fastcall SetFinish(System::TDateTime AValue);
	void __fastcall SetOccurDays(const Cxdateutils::TDays AValue);
	void __fastcall SetPeriodicity(const int AValue);
	void __fastcall SetRecurrence(const TcxRecurrence AValue);
	void __fastcall SetStart(const System::TDateTime AValue);
	void __fastcall SetYearPeriodicity(const int AValue);
	
protected:
	virtual void __fastcall AssignDefaultValues(void);
	TcxSchedulerEventRecurrenceInfoData __fastcall GetData(void);
	bool __fastcall GetOccurrences(TcxSchedulerFilteredEventList* AList, const System::TDateTime AStart, const System::TDateTime AFinish);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	bool __fastcall GetValue(System::AnsiString &AValue);
	void __fastcall SetDataItem(void * AOffset, int ASize, const void *AValue);
	void __fastcall SetValue(const System::AnsiString AValue);
	TcxRecurrenceValidStatus __fastcall GetDailyPatternStatus(void);
	TcxRecurrenceValidStatus __fastcall GetMonthlyPatternStatus(void);
	TcxRecurrenceValidStatus __fastcall GetWeeklyPatternStatus(void);
	TcxRecurrenceValidStatus __fastcall GetYearlyPatternStatus(void);
	__property TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	
public:
	__fastcall virtual TcxSchedulerEventRecurrenceInfo(TcxSchedulerEvent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::TDateTime __fastcall GetEndDate(void);
	TcxRecurrenceValidStatus __fastcall GetValidStatus(void);
	void __fastcall Validate(void);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property int DayNumber = {read=GetDayNumber, write=SetDayNumber, nodefault};
	__property TcxDayType DayType = {read=GetDayType, write=SetDayType, nodefault};
	__property System::TDateTime DismissDate = {read=GetDismissDate, write=SetDismissDate};
	__property double DisplayTimeBias = {read=FDisplayTimeBias, write=FDisplayTimeBias};
	__property TcxSchedulerEvent* Event = {read=FOwner};
	__property System::TDateTime Finish = {read=GetFinish, write=SetFinish};
	__property bool IsInfinity = {read=GetIsInfinity, nodefault};
	__property Cxdateutils::TDays OccurDays = {read=GetOccurDays, write=SetOccurDays, nodefault};
	__property int Periodicity = {read=GetPeriodicity, write=SetPeriodicity, nodefault};
	__property TcxRecurrence Recurrence = {read=GetRecurrence, write=SetRecurrence, nodefault};
	__property System::TDateTime Start = {read=GetStart, write=SetStart};
	__property int YearPeriodicity = {read=GetYearPeriodicity, write=SetYearPeriodicity, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerEventRecurrenceInfo(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerEventRecurrenceInfoClass;

enum TcxSchedulerEventRelation : unsigned char { trFinishToStart, trStartToStart, trFinishToFinish, trStartToFinish };

class DELPHICLASS TcxSchedulerEventItemLink;
class PASCALIMPLEMENTATION TcxSchedulerEventItemLink : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool FIsDestroying;
	TcxSchedulerEvent* FLink;
	int FLinkRecurrenceIndex;
	TcxSchedulerEventRelation FRelation;
	TcxSchedulerEvent* __fastcall GetEvent(void);
	TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	void __fastcall SetLink(TcxSchedulerEvent* AValue);
	void __fastcall SetRelation(TcxSchedulerEventRelation AValue);
	
protected:
	bool __fastcall CheckLinked(TcxSchedulerEvent* AEvent)/* overload */;
	bool __fastcall CheckLinked(const System::Variant &ID, int ARecurrenceIndex)/* overload */;
	virtual System::Variant __fastcall GetData(void);
	bool __fastcall IsAllowRelation(TcxSchedulerEventRelation ARelation);
	bool __fastcall IsValid(void);
	virtual void __fastcall SetData(const System::Variant &AData);
	virtual void __fastcall UpdateLink(void);
	__property TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	
public:
	__fastcall virtual TcxSchedulerEventItemLink(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxSchedulerEventItemLink(void);
	System::UnicodeString __fastcall GetRelationAsText(void);
	__property TcxSchedulerEvent* Event = {read=GetEvent};
	__property TcxSchedulerEvent* Link = {read=FLink, write=SetLink};
	__property int LinkRecurrenceIndex = {read=FLinkRecurrenceIndex, nodefault};
	__property TcxSchedulerEventRelation Relation = {read=FRelation, write=SetRelation, nodefault};
};


class DELPHICLASS TcxSchedulerEventLinks;
class PASCALIMPLEMENTATION TcxSchedulerEventLinks : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxSchedulerEventItemLink* operator[](int Index) { return ItemLinks[Index]; }
	
private:
	TcxSchedulerEvent* FEvent;
	bool __fastcall GetExpanded(void);
	TcxSchedulerEventItemLink* __fastcall GetItemLink(int AIndex);
	void __fastcall SetExpanded(bool AValue);
	void __fastcall SetItemLink(int AIndex, TcxSchedulerEventItemLink* AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall PrepareLinks(void);
	virtual void __fastcall RemoveLink(TcxSchedulerEvent* ALink);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	HIDESBASE TcxSchedulerEventItemLink* __fastcall Add(TcxSchedulerEvent* AEvent, TcxSchedulerEventRelation ARelation = (TcxSchedulerEventRelation)(0x3))/* overload */;
	bool __fastcall IsEventLinked(TcxSchedulerEvent* AEvent);
	void __fastcall UpdateLinksTime(void);
	__property System::UnicodeString DisplayText = {read=GetDisplayText};
	__property TcxSchedulerEvent* Event = {read=FEvent};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property TcxSchedulerEventItemLink* ItemLinks[int Index] = {read=GetItemLink, write=SetItemLink/*, default*/};
public:
	/* TCollection.Create */ inline __fastcall TcxSchedulerEventLinks(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxSchedulerEventLinks(void) { }
	
};


class DELPHICLASS TcxSchedulerEventTimeCalculator;
class PASCALIMPLEMENTATION TcxSchedulerEventTimeCalculator : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::TDateTime FFinish;
	TcxSchedulerEvent* FEvent;
	System::TDateTime FStart;
	System::TDateTime __fastcall GetDuration(void);
	System::TDateTime __fastcall GetStoredDuration(void);
	System::TDateTime __fastcall GetStoredFinish(void);
	System::TDateTime __fastcall GetStoredStart(void);
	
protected:
	virtual void __fastcall DoCalculate(void);
	virtual System::TDateTime __fastcall GetBaseFinish(void);
	virtual System::TDateTime __fastcall GetBaseStart(void);
	virtual void __fastcall GetValidTaskTimeRange(System::TDateTime &AStart, System::TDateTime &AFinish);
	__property System::TDateTime StoredDuration = {read=GetStoredDuration};
	__property System::TDateTime StoredFinish = {read=GetStoredFinish};
	__property System::TDateTime StoredStart = {read=GetStoredStart};
	
public:
	__fastcall virtual TcxSchedulerEventTimeCalculator(TcxSchedulerEvent* AEvent);
	void __fastcall Calculate(void);
	__property System::TDateTime Duration = {read=GetDuration};
	__property System::TDateTime Finish = {read=FFinish};
	__property TcxSchedulerEvent* Event = {read=FEvent};
	__property System::TDateTime Start = {read=FStart};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerEventTimeCalculator(void) { }
	
};


enum TcxSchedulerEventTaskStatus : unsigned char { tsNotStarted, tsInProgress, tsComplete, tsWaiting, tsDeferred };

class DELPHICLASS TcxSchedulerEventGroupItems;
class PASCALIMPLEMENTATION TcxSchedulerEventGroupItems : public TcxDoublyLinkedEventList
{
	typedef TcxDoublyLinkedEventList inherited;
	
private:
	TcxSchedulerEvent* FEvent;
	bool FExpanded;
	bool __fastcall GetHasChildren(void);
	System::Variant __fastcall GetID(void);
	void __fastcall SetExpanded(bool AValue);
	
protected:
	void __fastcall DeleteEvents(void);
	
public:
	__fastcall virtual TcxSchedulerEventGroupItems(TcxSchedulerEvent* AOwner);
	bool __fastcall IsChild(TcxSchedulerEvent* AEvent);
	TcxDoublyLinkedEventListData* __fastcall Find(TcxSchedulerEvent* AEvent);
	void __fastcall UpdateItemsTime(void);
	__property TcxSchedulerEvent* Event = {read=FEvent};
	__property bool Expanded = {read=FExpanded, write=SetExpanded, nodefault};
	__property bool HasChildren = {read=GetHasChildren, nodefault};
	__property System::Variant ID = {read=GetID};
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TcxSchedulerEventGroupItems(void) { }
	
};


class DELPHICLASS TcxSchedulerEventList;
class DELPHICLASS TcxSchedulerEventConflictsInfo;
class DELPHICLASS TcxSchedulerStorageResourceItem;
class PASCALIMPLEMENTATION TcxSchedulerEvent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxSchedulerEventGroupItems* FGroupItems;
	System::Variant FID;
	bool FIsDataValid;
	bool FIsModified;
	TcxSchedulerEvent* FLink;
	TcxSchedulerEvent* FParentGroup;
	bool FSkipExceptions;
	TcxCustomSchedulerStorage* FStorage;
	TcxSchedulerEventTimeCalculator* FTimeCalculator;
	int FPrevTaskComplete;
	TcxSchedulerEventRecurrenceInfo* FRecurrenceInfo;
	int __fastcall GetActualFinish(void);
	int __fastcall GetActualStart(void);
	bool __fastcall GetAllDayEvent(void);
	System::UnicodeString __fastcall GetCaption(void);
	System::TDateTime __fastcall GetDuration(void);
	System::Variant __fastcall GetEditValue(int AIndex);
	bool __fastcall GetEnabled(void);
	TcxEventType __fastcall GetEventType(void);
	System::TDateTime __fastcall GetFinish(void);
	System::Variant __fastcall GetGroupID(void);
	bool __fastcall GetIsBoundMode(void);
	bool __fastcall GetIsEditing(void);
	bool __fastcall GetIsGroup(void);
	bool __fastcall GetIsNewEvent(void);
	int __fastcall GetLabelColor(void);
	System::UnicodeString __fastcall GetLocation(void);
	System::UnicodeString __fastcall Getmessage(void);
	int __fastcall GetOptionsFlag(void);
	bool __fastcall GetReadOnly(void);
	int __fastcall GetRecurrenceIndex(void);
	bool __fastcall GetReminder(void);
	System::TDateTime __fastcall GetReminderDate(void);
	int __fastcall GetReminderMinutesBeforeStart(void);
	TcxSchedulerReminderResourcesData __fastcall GetReminderResourcesData(void);
	System::Variant __fastcall GetResourceID(void);
	int __fastcall GetResourceIDCount(void);
	System::Variant __fastcall GetResourceIDs(int Index);
	bool __fastcall GetShared(void);
	System::TDateTime __fastcall GetStart(void);
	int __fastcall GetState(void);
	int __fastcall GetTaskComplete(void);
	TcxSchedulerEventTaskStatus __fastcall GetTaskStatus(void);
	System::TDateTime __fastcall GetUTCFinish(void);
	System::TDateTime __fastcall GetUTCStart(void);
	int __fastcall GetValueCount(void);
	Cxdatastorage::TcxValueDef* __fastcall GetValueDef(int AFieldIndex);
	void __fastcall InternalSetFinish(const System::TDateTime AValue);
	void __fastcall InternalSetStart(const System::TDateTime AValue);
	void __fastcall InternalSetTaskComplete(const int AValue, bool AUpdateTaskStatus = true);
	void __fastcall InternalSetTaskStatus(TcxSchedulerEventTaskStatus AValue, bool AUpdateTaskComplete = true);
	void __fastcall SetAllDayEvent(const bool AValue);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetDuration(const System::TDateTime AValue);
	void __fastcall SetEditValue(int AIndex, const System::Variant &AValue);
	void __fastcall SetEnabled(const bool AValue);
	void __fastcall SetEventType(TcxEventType AValue);
	void __fastcall SetFinish(const System::TDateTime AValue);
	void __fastcall SetGroupID(const System::Variant &AValue);
	void __fastcall SetID(const System::Variant &AValue);
	void __fastcall SetIsDataValid(bool Value);
	void __fastcall SetIsGroup(const bool AValue);
	void __fastcall SetLabelColor(const int AValue);
	void __fastcall SetLocation(const System::UnicodeString AValue);
	void __fastcall SetMessage(const System::UnicodeString AValue);
	bool __fastcall SetOptionsFlag(const int AMask, bool AValue);
	void __fastcall SetParentGroup(TcxSchedulerEvent* AValue);
	void __fastcall SetParentID(const System::Variant &AValue);
	void __fastcall SetRecurrenceIndex(const int AValue);
	void __fastcall SetRecurrenceInfo(TcxSchedulerEventRecurrenceInfo* AValue);
	void __fastcall SetReminder(const bool AValue);
	void __fastcall SetReminderDate(System::TDateTime AValue);
	void __fastcall SetReminderMinutesBeforeStart(const int AValue);
	void __fastcall SetReminderResourcesData(const TcxSchedulerReminderResourcesData &AValue);
	void __fastcall SetResourceID(const System::Variant &AValue);
	void __fastcall SetStart(const System::TDateTime AValue);
	void __fastcall SetState(const int AValue);
	void __fastcall SetTaskComplete(const int AValue);
	void __fastcall SetTaskIndex(const int AValue);
	void __fastcall SetTaskStatus(TcxSchedulerEventTaskStatus AValue);
	void __fastcall SetUTCFinish(const System::TDateTime AValue);
	void __fastcall SetUTCStart(const System::TDateTime AValue);
	
protected:
	void *FData;
	int FEditCount;
	void *FEditingRecordHandle;
	TcxSchedulerEvent* FPattern;
	void *FRecordHandle;
	int FIndex;
	bool FIsDeletion;
	int FStartDate;
	int FOptions;
	TcxSchedulerEventLinks* FTaskLinks;
	TcxSchedulerEventList* FTaskLinkOwners;
	virtual void __fastcall AssignDefaultValues(void);
	void __fastcall CalculateActualTimeRange(void);
	void __fastcall CalculateActualTimeRangePost(void);
	virtual bool __fastcall CanMoveTo(System::TDateTime ANewTime);
	virtual void __fastcall CheckLinksOnChangeEventType(TcxEventType ANewEventType);
	void __fastcall CheckRecurrenceLink(TcxSchedulerEvent* AEvent);
	void __fastcall CheckRecurrenceLinkEx(TcxSchedulerEvent* AEvent);
	bool __fastcall CheckTimeRange(const int AStartDate, const int AFinishDate);
	virtual TcxSchedulerEventGroupItems* __fastcall CreateGroupItems(void);
	virtual TcxSchedulerEventRecurrenceInfo* __fastcall CreateRecurrenceInfo(void);
	TcxSchedulerReminderResourcesData __fastcall CreateReminderResourcesData(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual TcxSchedulerEventLinks* __fastcall CreateTaskLinks(void);
	virtual TcxSchedulerEventList* __fastcall CreateTaskLinkOwners(void);
	virtual void __fastcall DestroySubClasses(void);
	TcxSchedulerStorageDataController* __fastcall GetDataController(void);
	virtual System::Variant __fastcall GetID(void);
	virtual int __fastcall GetIndex(void);
	virtual bool __fastcall GetIsFreeState(void);
	virtual TcxSchedulerEventGroupItems* __fastcall GetGroupItems(void);
	bool __fastcall GetOccurrenceByIndex(int AIndex, TcxSchedulerEvent* &AOccurrence);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual System::Variant __fastcall GetParentID(void);
	virtual bool __fastcall GetRecurrenceInfoValue(System::AnsiString &AValue);
	void __fastcall GetStartFinishTime(System::TDateTime &AStart, System::TDateTime &AFinish);
	virtual int __fastcall GetTaskIndex(void);
	virtual TcxSchedulerEventLinks* __fastcall GetTaskLinks(void);
	virtual TcxSchedulerEventList* __fastcall GetTaskLinkOwners(void);
	virtual System::TDateTime __fastcall GetTaskCompleteDuration(void);
	virtual System::Variant __fastcall GetValueByIndex(int AIndex);
	virtual System::Variant __fastcall GetValueDefault(TcxCustomSchedulerStorageField* AField, const System::Variant &ADefValue);
	virtual void __fastcall DoGetValidTaskTimeRange(System::TDateTime &AStart, System::TDateTime &AFinish);
	virtual void __fastcall InternalMoveTo(const System::TDateTime AStartTime);
	virtual void __fastcall InvalidateReferences(void);
	void __fastcall Modified(void);
	void __fastcall PostEditingData(void);
	void __fastcall PrepareTaskLinks(void);
	void __fastcall RefreshTaskLinks(void);
	void __fastcall ResetReferences(void);
	virtual void __fastcall RemoveTaskLink(TcxSchedulerEvent* ALink);
	virtual void __fastcall RemoveTaskLinkOwnersReferences(void);
	void __fastcall ResetReminderResourcesData(void);
	void __fastcall SetActualTimeRange(const System::TDateTime ActualStart, const System::TDateTime ActualFinish);
	virtual void __fastcall SetRecurrenceInfoValue(const System::AnsiString AValue);
	virtual void __fastcall SetValue(TcxCustomSchedulerStorageField* AField, const System::Variant &AValue);
	virtual void __fastcall SetValueByIndex(int AIndex, const System::Variant &AValue);
	virtual void __fastcall TaskLinksChanged(TcxSchedulerEventLinks* Sender);
	void __fastcall UpdateReminderDate(void);
	void __fastcall UpdateParentGroup(void);
	void __fastcall UpdateTemporaryData(void);
	void __fastcall AddItem(TcxSchedulerEvent* AEvent);
	bool __fastcall CanAddItem(TcxSchedulerEvent* AEvent);
	void __fastcall RemoveItem(TcxSchedulerEvent* AEvent);
	__property TcxSchedulerStorageDataController* DataController = {read=GetDataController};
	__property bool IsBoundMode = {read=GetIsBoundMode, nodefault};
	__property bool IsFreeState = {read=GetIsFreeState, nodefault};
	__property bool IsNewEvent = {read=GetIsNewEvent, nodefault};
	__property bool IsModified = {read=FIsModified, write=FIsModified, nodefault};
	__property TcxSchedulerEvent* Link = {read=FLink};
	__property TcxSchedulerReminderResourcesData ReminderResourcesData = {read=GetReminderResourcesData, write=SetReminderResourcesData};
	__property TcxSchedulerEventTimeCalculator* TimeCalculator = {read=FTimeCalculator};
	__property Cxdatastorage::TcxValueDef* ValueDefs[int AFieldIndex] = {read=GetValueDef};
	
public:
	__fastcall virtual TcxSchedulerEvent(TcxCustomSchedulerStorage* AStorage, bool ADisableEditing)/* overload */;
	__fastcall virtual TcxSchedulerEvent(TcxCustomSchedulerStorage* AStorage, void * ARecordHandle)/* overload */;
	__fastcall virtual ~TcxSchedulerEvent(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall AllowLink(TcxSchedulerEvent* AEvent);
	virtual void __fastcall AssignAttributes(TcxSchedulerEvent* ASource, bool AUseSourceTime = true);
	virtual void __fastcall BeginEditing(void);
	void __fastcall Cancel(void);
	virtual bool __fastcall CanLink(TcxSchedulerEvent* AEvent);
	virtual bool __fastcall IsEventLinked(TcxSchedulerEvent* AHeaderEvent);
	bool __fastcall Conflicts(bool AExceptEventsWithoutResources);
	TcxSchedulerEventConflictsInfo* __fastcall CreateConflictsInfo(bool AExceptEventsWithoutResources);
	virtual void __fastcall Delete(void);
	virtual void __fastcall DeleteExceptions(void);
	virtual void __fastcall EndEditing(void);
	TcxSchedulerEvent* __fastcall GetOccurrence(System::TDateTime ADate);
	System::TDateTime __fastcall GetOriginalDate(void);
	TcxSchedulerStorageResourceItem* __fastcall GetResourceItem(void);
	TcxSchedulerEventList* __fastcall GetRecurrenceChain(void);
	virtual bool __fastcall GetTaskLinkOwnerRelation(TcxSchedulerEvent* ATaskLinkOwner, TcxSchedulerEventRelation &ARelation);
	void __fastcall GetValidTaskTimeRange(System::TDateTime &AStart, System::TDateTime &AFinish);
	virtual void __fastcall GetValidTaskTimeRangeByRelation(const TcxSchedulerEventRelation ARelation, TcxSchedulerEvent* AEvent, System::TDateTime &AStart, System::TDateTime &AFinish);
	bool __fastcall HasAsParentGroup(TcxSchedulerEvent* AEvent);
	bool __fastcall HasChildren(void);
	bool __fastcall HasExceptions(void);
	bool __fastcall HasReminderForResourceID(const System::Variant &AResourceID);
	bool __fastcall IsDayEvent(int ADate)/* overload */;
	bool __fastcall IsDayEvent(const System::TDateTime ADate)/* overload */;
	bool __fastcall IsRecurring(void);
	bool __fastcall IsResourceEvent(TcxSchedulerStorageResourceItem* AResource, bool AllowUnassigned);
	void __fastcall MoveTo(const System::TDateTime AStartTime);
	void __fastcall Post(void);
	virtual void __fastcall RemoveRecurrence(void);
	virtual double __fastcall TimeBias(void);
	void __fastcall ShareWithResource(TcxSchedulerStorageResourceItem* AResourceItem)/* overload */;
	void __fastcall ShareWithResource(System::Variant &AResourceID)/* overload */;
	bool __fastcall IsSharedWithResource(TcxSchedulerStorageResourceItem* AResourceItem)/* overload */;
	bool __fastcall IsSharedWithResource(System::Variant &AResourceID)/* overload */;
	void __fastcall UnshareWithResource(TcxSchedulerStorageResourceItem* AResourceItem)/* overload */;
	void __fastcall UnshareWithResource(System::Variant &AResourceID)/* overload */;
	void __fastcall ReplaceResourceID(System::Variant &AResourceID);
	System::Variant __fastcall GetCustomFieldValueByIndex(int AIndex);
	System::Variant __fastcall GetCustomFieldValueByName(const System::UnicodeString AName);
	System::Variant __fastcall GetCustomFieldValue(TcxCustomSchedulerStorageField* ACustomField);
	void __fastcall SetCustomFieldValueByIndex(int AIndex, const System::Variant &AValue);
	void __fastcall SetCustomFieldValueByName(const System::UnicodeString AName, const System::Variant &AValue);
	void __fastcall SetCustomFieldValue(TcxCustomSchedulerStorageField* ACustomField, const System::Variant &AValue);
	__property int ActualStart = {read=GetActualStart, nodefault};
	__property int ActualFinish = {read=GetActualFinish, nodefault};
	__property bool AllDayEvent = {read=GetAllDayEvent, write=SetAllDayEvent, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption};
	__property System::TDateTime Duration = {read=GetDuration, write=SetDuration};
	__property void * EditingRecordHandle = {read=FEditingRecordHandle, write=FEditingRecordHandle};
	__property System::Variant EditValues[int Index] = {read=GetEditValue, write=SetEditValue};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
	__property TcxEventType EventType = {read=GetEventType, write=SetEventType, nodefault};
	__property System::TDateTime Finish = {read=GetFinish, write=SetFinish};
	__property System::Variant GroupID = {read=GetGroupID};
	__property TcxSchedulerEventGroupItems* GroupItems = {read=GetGroupItems};
	__property System::Variant ID = {read=GetID, write=SetID};
	__property int Index = {read=GetIndex, nodefault};
	__property bool IsDataValid = {read=FIsDataValid, write=SetIsDataValid, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property bool IsGroup = {read=GetIsGroup, write=SetIsGroup, nodefault};
	__property int LabelColor = {read=GetLabelColor, write=SetLabelColor, nodefault};
	__property System::UnicodeString Location = {read=GetLocation, write=SetLocation};
	__property System::UnicodeString Message = {read=Getmessage, write=SetMessage};
	__property System::Variant ParentID = {read=GetParentID, write=SetParentID};
	__property TcxSchedulerEvent* Pattern = {read=FPattern};
	__property TcxSchedulerEvent* ParentGroup = {read=FParentGroup, write=SetParentGroup};
	__property bool ReadOnly = {read=GetReadOnly, nodefault};
	__property void * RecordHandle = {read=FRecordHandle, write=FRecordHandle};
	__property int RecurrenceIndex = {read=GetRecurrenceIndex, write=SetRecurrenceIndex, nodefault};
	__property TcxSchedulerEventRecurrenceInfo* RecurrenceInfo = {read=FRecurrenceInfo, write=SetRecurrenceInfo};
	__property bool Reminder = {read=GetReminder, write=SetReminder, nodefault};
	__property System::TDateTime ReminderDate = {read=GetReminderDate, write=SetReminderDate};
	__property int ReminderMinutesBeforeStart = {read=GetReminderMinutesBeforeStart, write=SetReminderMinutesBeforeStart, nodefault};
	__property System::Variant ResourceID = {read=GetResourceID, write=SetResourceID};
	__property int ResourceIDCount = {read=GetResourceIDCount, nodefault};
	__property System::Variant ResourceIDs[int Index] = {read=GetResourceIDs};
	__property bool Shared = {read=GetShared, nodefault};
	__property bool SkipExceptions = {read=FSkipExceptions, write=FSkipExceptions, nodefault};
	__property System::TDateTime Start = {read=GetStart, write=SetStart};
	__property int State = {read=GetState, write=SetState, nodefault};
	__property TcxCustomSchedulerStorage* Storage = {read=FStorage};
	__property int TaskComplete = {read=GetTaskComplete, write=SetTaskComplete, nodefault};
	__property int TaskIndex = {read=GetTaskIndex, write=SetTaskIndex, nodefault};
	__property TcxSchedulerEventLinks* TaskLinks = {read=GetTaskLinks};
	__property TcxSchedulerEventList* TaskLinkOwners = {read=GetTaskLinkOwners};
	__property TcxSchedulerEventTaskStatus TaskStatus = {read=GetTaskStatus, write=SetTaskStatus, nodefault};
	__property System::TDateTime UTCFinish = {read=GetUTCFinish, write=SetUTCFinish};
	__property System::TDateTime UTCStart = {read=GetUTCStart, write=SetUTCStart};
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property System::Variant Values[int Index] = {read=GetValueByIndex, write=SetValueByIndex};
};


class PASCALIMPLEMENTATION TcxSchedulerControlEvent : public TcxSchedulerEvent
{
	typedef TcxSchedulerEvent inherited;
	
private:
	bool FIsClone;
	bool FIsEditing;
	bool FIsSource;
	int FLineStart;
	System::Variant FLockedResource;
	_di_IcxSchedulerSelectionAdapter FSelectionAdapter;
	TcxSchedulerEvent* FSource;
	double FTimeBias;
	int FVisibleIndex;
	int __fastcall GetNonExceptionLinkCount(void);
	bool __fastcall GetSelected(void);
	void __fastcall SetPattern(TcxSchedulerEvent* AValue);
	void __fastcall SetSelected(bool AValue);
	
protected:
	virtual bool __fastcall CanMoveTo(System::TDateTime ANewTime);
	virtual void __fastcall CheckLinksOnChangeEventType(TcxEventType ANewEventType);
	virtual TcxSchedulerEventLinks* __fastcall CreateTaskLinks(void);
	virtual TcxSchedulerEventGroupItems* __fastcall GetGroupItems(void);
	virtual int __fastcall GetIndex(void);
	virtual System::Variant __fastcall GetParentID(void);
	virtual int __fastcall GetTaskIndex(void);
	virtual TcxSchedulerEventLinks* __fastcall GetTaskLinks(void);
	virtual TcxSchedulerEventList* __fastcall GetTaskLinkOwners(void);
	virtual System::Variant __fastcall GetValueByIndex(int AIndex);
	virtual void __fastcall DoGetValidTaskTimeRange(System::TDateTime &AStart, System::TDateTime &AFinish);
	virtual void __fastcall InvalidateReferences(void);
	virtual void __fastcall RemoveTaskLinkOwnersReferences(void);
	virtual void __fastcall SetValueByIndex(int AIndex, const System::Variant &AValue);
	__property int LineStart = {read=FLineStart, write=FLineStart, nodefault};
	__property _di_IcxSchedulerSelectionAdapter SelectionAdapter = {read=FSelectionAdapter, write=FSelectionAdapter};
	__property int VisibleIndex = {read=FVisibleIndex, write=FVisibleIndex, nodefault};
	
public:
	__fastcall virtual TcxSchedulerControlEvent(TcxCustomSchedulerStorage* AStorage, bool ADisableEditing)/* overload */;
	__fastcall TcxSchedulerControlEvent(TcxSchedulerEvent* ASource)/* overload */;
	__fastcall TcxSchedulerControlEvent(TcxSchedulerEvent* ASource, const System::TDateTime AStart, const System::TDateTime AFinish)/* overload */;
	__fastcall TcxSchedulerControlEvent(TcxSchedulerEvent* ASource, TcxSchedulerEvent* AOriginal)/* overload */;
	__fastcall virtual ~TcxSchedulerControlEvent(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignDefaultValues(void);
	virtual void __fastcall BeginEditing(void);
	virtual void __fastcall Delete(void);
	virtual void __fastcall EndEditing(void);
	virtual bool __fastcall GetTaskLinkOwnerRelation(TcxSchedulerEvent* ATaskLinkOwner, TcxSchedulerEventRelation &ARelation);
	virtual bool __fastcall IsOrigin(TcxSchedulerEvent* AEvent);
	void __fastcall lockResource(const System::Variant &ALockedResource);
	double __fastcall StorageTimeBias(void);
	virtual double __fastcall TimeBias(void);
	void __fastcall unlockResource(void);
	__property bool IsClone = {read=FIsClone, nodefault};
	__property bool IsEditing = {read=FIsEditing, nodefault};
	__property bool IsSource = {read=FIsSource, nodefault};
	__property int NonExceptionLinkCount = {read=GetNonExceptionLinkCount, nodefault};
	__property bool Selected = {read=GetSelected, write=SetSelected, nodefault};
	__property TcxSchedulerEvent* Source = {read=FSource};
	__property TcxSchedulerEvent* Pattern = {read=FPattern, write=SetPattern};
public:
	/* TcxSchedulerEvent.Create */ inline __fastcall virtual TcxSchedulerControlEvent(TcxCustomSchedulerStorage* AStorage, void * ARecordHandle)/* overload */ : TcxSchedulerEvent(AStorage, ARecordHandle) { }
	
};


typedef System::TMetaClass* TcxSchedulerEventClass;

typedef void __fastcall (__closure *TcxSchedulerGetResourceNameEvent)(System::TObject* Sender, TcxSchedulerStorageResourceItem* AResource, System::UnicodeString &AResourceName);

typedef void __fastcall (__closure *TcxSchedulerGetResourceImageIndexEvent)(System::TObject* Sender, TcxSchedulerStorageResourceItem* AResource, System::Uitypes::TImageIndex &AImageIndex);

class DELPHICLASS TcxSchedulerStorageResourceItems;
class DELPHICLASS TcxSchedulerStorageResources;
class PASCALIMPLEMENTATION TcxSchedulerStorageResourceItems : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxSchedulerStorageResourceItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxSchedulerStorageResources* FOwner;
	HIDESBASE TcxSchedulerStorageResourceItem* __fastcall GetItem(int AIndex);
	TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxSchedulerStorageResourceItem* AValue);
	TcxSchedulerStorageResourceItem* __fastcall GetVisibleResource(int AIndex);
	int __fastcall GetVisibleResourceCount(void);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property TcxSchedulerStorageResources* Resources = {read=FOwner};
	__property TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	
public:
	__fastcall virtual TcxSchedulerStorageResourceItems(TcxSchedulerStorageResources* AOwner, TcxSchedulerStorageResourceItemClass AItemClass);
	HIDESBASE TcxSchedulerStorageResourceItem* __fastcall Add(void);
	__property TcxSchedulerStorageResourceItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int VisibleResourceCount = {read=GetVisibleResourceCount, nodefault};
	__property TcxSchedulerStorageResourceItem* VisibleResources[int Index] = {read=GetVisibleResource};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxSchedulerStorageResourceItems(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerStorageResourceItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::Uitypes::TColor FColor;
	System::Uitypes::TImageIndex FImageIndex;
	System::UnicodeString FName;
	TcxSchedulerStorageResourceItem* FParent;
	bool FReadOnly;
	System::Variant FResourceID;
	bool FVisible;
	Cxdateutils::TDays FWorkDays;
	System::TTime FWorkFinish;
	bool FWorkFinishAssigned;
	System::TTime FWorkStart;
	bool FWorkStartAssigned;
	System::Uitypes::TImageIndex __fastcall GetActualImageIndex(void);
	bool __fastcall GetActuallyVisible(void);
	TcxSchedulerStorageResources* __fastcall GetResources(void);
	bool __fastcall IsWorkDaysStored(void);
	void __fastcall ReadWorkFinish(System::Classes::TReader* AReader);
	void __fastcall ReadWorkStart(System::Classes::TReader* AReader);
	void __fastcall SetParent(TcxSchedulerStorageResourceItem* AValue);
	void __fastcall WriteWorkFinish(System::Classes::TWriter* AWriter);
	void __fastcall WriteWorkStart(System::Classes::TWriter* AWriter);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual void __fastcall SetColor(const System::Uitypes::TColor AValue);
	virtual void __fastcall SetImageIndex(const System::Uitypes::TImageIndex AValue);
	virtual void __fastcall SetName(const System::UnicodeString AValue);
	virtual void __fastcall SetResourceID(const System::Variant &AValue);
	virtual void __fastcall SetVisible(const bool AValue);
	virtual void __fastcall SetWorkDays(Cxdateutils::TDays AValue);
	virtual void __fastcall SetWorkFinish(const System::TTime AValue);
	virtual void __fastcall SetWorkStart(const System::TTime AValue);
	
public:
	__fastcall virtual TcxSchedulerStorageResourceItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall HasAsParent(TcxSchedulerStorageResourceItem* AItem);
	__property System::Uitypes::TImageIndex ActualImageIndex = {read=GetActualImageIndex, nodefault};
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property TcxSchedulerStorageResources* Resources = {read=GetResources};
	
__published:
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property TcxSchedulerStorageResourceItem* Parent = {read=FParent, write=SetParent};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property System::Variant ResourceID = {read=FResourceID, write=SetResourceID};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property System::TTime WorkFinish = {read=FWorkFinish, write=SetWorkFinish, stored=false};
	__property System::TTime WorkStart = {read=FWorkStart, write=SetWorkStart, stored=false};
	__property Cxdateutils::TDays WorkDays = {read=FWorkDays, write=SetWorkDays, stored=IsWorkDaysStored, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxSchedulerStorageResourceItem(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerStorageResources : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FImages;
	TcxSchedulerStorageResourceItems* FItems;
	TcxCustomSchedulerStorage* FOwner;
	System::Classes::TList* FRestoringItems;
	TcxSchedulerGetResourceImageIndexEvent FOnGetResourceImageIndex;
	TcxSchedulerGetResourceNameEvent FOnGetResourceName;
	bool __fastcall GetAreImagesUsed(void);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetItems(TcxSchedulerStorageResourceItems* AValue);
	
protected:
	int __fastcall DecodePropertyName(const System::UnicodeString AName, System::UnicodeString &ASubValue);
	System::UnicodeString __fastcall GetObjectName(void);
	bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall Changed(void);
	virtual TcxSchedulerStorageResourceItems* __fastcall CreateItems(void);
	void __fastcall DoneRestore(void);
	virtual System::Uitypes::TImageIndex __fastcall DoGetResourceImageIndex(TcxSchedulerStorageResourceItem* AItem);
	virtual System::UnicodeString __fastcall DoGetResourceName(TcxSchedulerStorageResourceItem* AItem);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual TcxSchedulerStorageResourceItems* __fastcall GetResourceItems(void);
	void __fastcall InitRestore(void);
	__property TcxCustomSchedulerStorage* Storage = {read=FOwner};
	
public:
	__fastcall virtual TcxSchedulerStorageResources(TcxCustomSchedulerStorage* AOwner);
	__fastcall virtual ~TcxSchedulerStorageResources(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall PopulateItemsAsTreeStructure(System::Classes::TList* AList);
	System::UnicodeString __fastcall GetResourceName(TcxSchedulerStorageResourceItem* AResource);
	System::UnicodeString __fastcall GetResourceNameByID(const System::Variant &AResource);
	__property bool AreImagesUsed = {read=GetAreImagesUsed, nodefault};
	__property TcxSchedulerStorageResourceItems* ResourceItems = {read=GetResourceItems};
	
__published:
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TcxSchedulerStorageResourceItems* Items = {read=FItems, write=SetItems};
	__property TcxSchedulerGetResourceImageIndexEvent OnGetResourceImageIndex = {read=FOnGetResourceImageIndex, write=FOnGetResourceImageIndex};
	__property TcxSchedulerGetResourceNameEvent OnGetResourceName = {read=FOnGetResourceName, write=FOnGetResourceName};
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	
};


typedef void __fastcall (__closure *TcxSchedulerNotificationEvent)(System::TObject* Sender, TcxSchedulerEvent* AEvent, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerFilterEventEvent)(TcxCustomSchedulerStorage* Sender, TcxSchedulerEvent* AEvent, bool &Accept);

class DELPHICLASS TcxSchedulerControlEventID;
class PASCALIMPLEMENTATION TcxSchedulerEventConflictsInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FExceptEventsWithoutResources;
	TcxSchedulerFilteredEventList* FConflictEvents;
	TcxSchedulerEvent* FExcludedEvent;
	TcxSchedulerEvent* FEvent;
	TcxCustomSchedulerStorage* FStorage;
	Cxschedulerutils::TcxSchedulerTimeRanges* FTimeRanges;
	bool __fastcall GetHasConflicts(void);
	bool __fastcall GetHasFreeTime(void);
	
protected:
	TcxSchedulerControlEventID* ExcludedEventID;
	TcxSchedulerControlEventID* EventID;
	System::TDateTime Start;
	System::TDateTime Finish;
	System::Variant ResourceID;
	void __fastcall AddRange(System::TDateTime AStart, System::TDateTime AFinish);
	void __fastcall CheckFreeTimeRanges(void);
	void __fastcall CheckIntersectionWithEvents(void);
	void __fastcall CheckSomeIntersection(void);
	bool __fastcall ExcludeFromCalculate(TcxSchedulerEvent* AEvent);
	void __fastcall ExpandRange(TcxSchedulerEvent* AEvent, int &AIndex, System::TDateTime &ALastPosition);
	void __fastcall Init(TcxCustomSchedulerStorage* AStorage, bool AExceptEventsWithoutResources, System::Variant &AResourceID, const System::TDateTime AStart, const System::TDateTime AFinish);
	bool __fastcall IntersectEvents(TcxSchedulerEvent* ACheckedEvent)/* overload */;
	bool __fastcall IntersectEvents(TcxSchedulerEvent* AEvent1, TcxSchedulerEvent* AEvent2)/* overload */;
	bool __fastcall IntersectTime(const System::TDateTime AStart, const System::TDateTime AFinish)/* overload */;
	bool __fastcall IntersectTime(const System::TDateTime AStart, const System::TDateTime AFinish, const System::TDateTime AStart1, const System::TDateTime AFinish1)/* overload */;
	bool __fastcall IsSameEvent(TcxSchedulerEvent* ACheckedEvent);
	bool __fastcall IsSameSeries(TcxSchedulerEvent* AEvent1, TcxSchedulerEvent* AEvent2);
	
public:
	__fastcall virtual TcxSchedulerEventConflictsInfo(TcxSchedulerEvent* AEvent, bool AExceptEventsWithoutResources)/* overload */;
	__fastcall virtual TcxSchedulerEventConflictsInfo(TcxSchedulerEvent* AEvent, bool AExceptEventsWithoutResources, const System::TDateTime AStart, const System::TDateTime AFinish)/* overload */;
	__fastcall virtual TcxSchedulerEventConflictsInfo(TcxCustomSchedulerStorage* AStorage, bool AExceptEventsWithoutResources, const System::TDateTime AStart, const System::TDateTime AFinish, System::Variant &AResourceID, TcxSchedulerEvent* AExcludedEvent)/* overload */;
	__fastcall virtual ~TcxSchedulerEventConflictsInfo(void);
	virtual void __fastcall Calculate(bool ACalculateFreeTime = true);
	__property TcxSchedulerFilteredEventList* ConflictEvents = {read=FConflictEvents};
	__property bool ExceptEventsWithoutResources = {read=FExceptEventsWithoutResources, nodefault};
	__property TcxSchedulerEvent* Event = {read=FEvent};
	__property bool HasConflicts = {read=GetHasConflicts, nodefault};
	__property bool HasFreeTime = {read=GetHasFreeTime, nodefault};
	__property TcxCustomSchedulerStorage* Storage = {read=FStorage};
	__property Cxschedulerutils::TcxSchedulerTimeRanges* TimeRanges = {read=FTimeRanges};
};


typedef System::TMetaClass* TcxSchedulerEventConflictsInfoClass;

class DELPHICLASS TcxSchedulerEventLinksController;
class PASCALIMPLEMENTATION TcxSchedulerEventLinksController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomSchedulerStorage* FStorage;
	
protected:
	bool __fastcall IsLinked(TcxSchedulerEvent* AEvent, TcxSchedulerEvent* ALink, bool ACheckGroupItems = true);
	virtual bool __fastcall DoAllowLink(TcxSchedulerEvent* AEvent, TcxSchedulerEvent* ALink);
	
public:
	__fastcall virtual TcxSchedulerEventLinksController(TcxCustomSchedulerStorage* AStorage);
	bool __fastcall AllowLink(TcxSchedulerEvent* AEvent, TcxSchedulerEvent* ALink);
	__property TcxCustomSchedulerStorage* Storage = {read=FStorage};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerEventLinksController(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerEventLinksControllerClass;

typedef void __fastcall (__closure *TcxSchedulerEventIntersectEvent)(TcxCustomSchedulerStorage* Sender, TcxSchedulerEvent* AEvent1, TcxSchedulerEvent* AEvent2, bool &Allow);

class DELPHICLASS TcxSchedulerReminders;
class PASCALIMPLEMENTATION TcxCustomSchedulerStorage : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FActive;
	TcxCustomSchedulerStorageFields* FCustomFields;
	TcxSchedulerStorageDataController* FDataController;
	Vcl::Forms::TForm* FEditor;
	Cxschedulerholidays::TcxSchedulerHolidays* FHolidays;
	TcxCustomSchedulerStorageFields* FInternalFields;
	bool FIsChanged;
	bool FIsModified;
	bool FIsStructureUpdating;
	bool FInternalUpdate;
	TcxSchedulerEventLinksController* FLinksController;
	System::Classes::TInterfaceList* FListeners;
	TcxSchedulerReminders* FReminders;
	TcxSchedulerStorageResources* FResources;
	System::Classes::TNotifyEvent FRemindersEvents;
	System::Classes::TNotifyEvent FResourcesEvents;
	bool FStoreUsingGlobalTime;
	System::UnicodeString FStoringName;
	double FTimeBias;
	Vcl::Extctrls::TTimer* FUpdateRemindersTimer;
	bool FUseActualTimeRange;
	TcxSchedulerNotificationEvent FOnEventDeleted;
	TcxSchedulerNotificationEvent FOnEventInserted;
	TcxSchedulerEventIntersectEvent FOnEventIntersect;
	TcxSchedulerNotificationEvent FOnEventModified;
	TcxSchedulerFilterEventEvent FOnFilterEvent;
	TcxCustomSchedulerStorageField* __fastcall GetDataField(int AIndex);
	TcxSchedulerEvent* __fastcall GetEvent(int AIndex);
	int __fastcall GetEventCount(void);
	TcxCustomSchedulerStorageField* __fastcall GetField(int AIndex);
	int __fastcall GetFieldCount(void);
	int __fastcall GetInternalFieldCount(void);
	bool __fastcall GetIsDestroying(void);
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIsLocked(void);
	bool __fastcall GetCanUpdateReminders(void);
	bool __fastcall GetIsUpdatingMode(void);
	int __fastcall GetResourceCount(void);
	System::Variant __fastcall GetResourceID(int AIndex);
	System::UnicodeString __fastcall GetResourceName(int AIndex);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetEvent(int AIndex, TcxSchedulerEvent* AValue);
	void __fastcall SetHolidays(Cxschedulerholidays::TcxSchedulerHolidays* AValue);
	void __fastcall SetOnFilterEvent(TcxSchedulerFilterEventEvent AValue);
	void __fastcall SetReminders(TcxSchedulerReminders* AValue);
	void __fastcall SetResources(TcxSchedulerStorageResources* AValue);
	void __fastcall SetStoreUsingGlobalTime(bool AValue);
	void __fastcall StopUpdateRemindersTimer(void);
	void __fastcall UpdateReminders(void);
	void __fastcall UpdateRemindersTimerEvent(System::TObject* Sender);
	
protected:
	Cxclasses::TcxObjectList* FDeletedEvents;
	int FEventIDCounter;
	TcxSchedulerEventList* FEventsList;
	System::Classes::TList* FFields;
	bool FIsLoading;
	TcxSchedulerEvent* FLastEditedEvent;
	TcxSchedulerEventList* FNewEvents;
	int LockCount;
	TcxCustomSchedulerStorageField* FActualFinishField;
	TcxCustomSchedulerStorageField* FActualStartField;
	TcxCustomSchedulerStorageField* FCaptionField;
	TcxCustomSchedulerStorageField* FEventTypeField;
	TcxCustomSchedulerStorageField* FFinishField;
	TcxCustomSchedulerStorageField* FGroupIDField;
	TcxCustomSchedulerStorageField* FLabelColorField;
	TcxCustomSchedulerStorageField* FLocationField;
	TcxCustomSchedulerStorageField* FMessageField;
	TcxCustomSchedulerStorageField* FOptionsField;
	TcxCustomSchedulerStorageField* FParentIDField;
	TcxCustomSchedulerStorageField* FRecurrenceIndexField;
	TcxCustomSchedulerStorageField* FRecurrenceInfoField;
	TcxCustomSchedulerStorageField* FReminderDateField;
	TcxCustomSchedulerStorageField* FReminderMinutesBeforeStartField;
	TcxCustomSchedulerStorageField* FResourceIDField;
	TcxCustomSchedulerStorageField* FStartField;
	TcxCustomSchedulerStorageField* FStateField;
	TcxCustomSchedulerStorageField* FTaskCompleteField;
	TcxCustomSchedulerStorageField* FTaskIndexField;
	TcxCustomSchedulerStorageField* FTaskLinksField;
	TcxCustomSchedulerStorageField* FTaskStatusField;
	TcxCustomSchedulerStorageField* FReminderResourcesData;
	virtual bool __fastcall ActualTimeRangeAvailable(void);
	virtual bool __fastcall AddEventRecord(TcxSchedulerEvent* AEvent);
	virtual void __fastcall AddInternalField(TcxCustomSchedulerStorageField* &AField, Cxdatastorage::TcxValueTypeClass AValueType, bool AIsUnique = true);
	virtual void * __fastcall AllocateRecord(void);
	void __fastcall AssignIndexes(void);
	virtual void __fastcall AfterPostEditingData(TcxSchedulerEvent* AEvent);
	virtual void __fastcall BeforePostEditingData(TcxSchedulerEvent* AEvent);
	virtual void __fastcall BeforeDeleteEvent(TcxSchedulerEvent* AEvent);
	virtual void __fastcall CancelEvent(TcxSchedulerEvent* AEvent);
	virtual bool __fastcall CanGetValueFromPattern(int AIndex);
	virtual void __fastcall Changed(void);
	virtual void __fastcall CreateDefaultFields(const double AVersion);
	virtual TcxSchedulerEvent* __fastcall CreateEventInternal(void);
	virtual TcxCustomSchedulerStorageFields* __fastcall CreateFields(void);
	virtual void __fastcall CreateHolidayEvent(const System::UnicodeString ACaption, const System::TDateTime ADate, System::Variant &AResourceID);
	virtual TcxSchedulerReminders* __fastcall CreateReminders(void);
	virtual TcxSchedulerStorageResources* __fastcall CreateResources(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DeleteEvents(Cxclasses::TcxObjectList* AEvents);
	void __fastcall DestroyDefaultFields(double AVersion);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DoDeleteEvent(TcxSchedulerEvent* AEvent);
	virtual void __fastcall DoDestroyEvent(TcxSchedulerEvent* AEvent);
	virtual bool __fastcall DoEventDeleted(TcxSchedulerEvent* AEvent);
	virtual bool __fastcall DoEventInserted(TcxSchedulerEvent* AEvent);
	virtual bool __fastcall DoEventIntersect(TcxSchedulerEvent* AEvent1, TcxSchedulerEvent* AEvent2);
	virtual bool __fastcall DoEventModified(TcxSchedulerEvent* AEvent);
	virtual bool __fastcall DoFilterEvent(TcxSchedulerEvent* AEvent);
	virtual void __fastcall DoRefresh(void);
	virtual void __fastcall FreeRecord(void * &ARecordHandle);
	virtual void __fastcall GenerateHolidayEventsBySchedulerHolidays(const System::Variant &AResourceID, Cxschedulerholidays::TcxSchedulerHolidays* AHolidays);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual TcxSchedulerEventClass __fastcall GetEventClass(void);
	virtual System::Variant __fastcall GetEventID(TcxSchedulerEvent* AEvent);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetFieldValueTypeClass(TcxCustomSchedulerStorageField* AField);
	virtual TcxSchedulerEventLinksControllerClass __fastcall GetLinksControllerClass(void);
	Vcl::Forms::TForm* __fastcall GetParentForm(void);
	System::Variant __fastcall GetEventActualValue(TcxSchedulerEvent* AEvent, int AIndex);
	virtual System::Variant __fastcall GetEventValue(const void * AHandle, int AIndex);
	virtual bool __fastcall GetIsBoundMode(void);
	virtual bool __fastcall HasEventIntersect(TcxSchedulerEvent* AEvent1, TcxSchedulerEvent* AEvent2);
	virtual void __fastcall InternalDelete(TcxSchedulerEvent* AEvent);
	void __fastcall InternalRemove(TcxSchedulerEvent* AEvent);
	virtual bool __fastcall IsEventDeleting(TcxSchedulerEvent* AEvent);
	void __fastcall ItemAdded(TcxCustomSchedulerStorageField* AItem);
	void __fastcall ItemRemoved(TcxCustomSchedulerStorageField* AItem);
	virtual bool __fastcall IsDataSettingsValid(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall PostEvent(TcxSchedulerEvent* AEvent);
	virtual void __fastcall PostEditingData(TcxSchedulerEvent* AEvent);
	virtual void __fastcall SendNotification(TcxSchedulerEvent* AEvent, bool AIsRemoved = false, bool ACheckLockCount = true);
	virtual void __fastcall SetEventValue(TcxSchedulerEvent* AEvent, int AFieldIndex, const System::Variant &AValue);
	virtual void __fastcall SetPostFieldValue(TcxSchedulerEvent* AEvent, int AFieldIndex);
	virtual void __fastcall SetValue(const void * ARecordHandle, const int AFieldIndex, const System::Variant &AValue);
	virtual void __fastcall SetValueBeforePost(TcxSchedulerEvent* AEvent, int AItemIndex);
	virtual void __fastcall SynchronizeEventsWithRecords(void);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual void __fastcall UpdateData(void);
	void __fastcall UpdateItemIndexes(void);
	void __fastcall UpdateRemindersTimer(void);
	virtual void __fastcall UpdateStructure(void);
	virtual void __fastcall BeginUpdateDataController(void);
	virtual void __fastcall EndUpdateDataController(void);
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property bool CanUpdateReminders = {read=GetCanUpdateReminders, nodefault};
	__property TcxSchedulerStorageDataController* DataController = {read=FDataController};
	__property TcxCustomSchedulerStorageField* DataFields[int Index] = {read=GetDataField};
	__property Vcl::Forms::TForm* Editor = {read=FEditor, write=FEditor};
	__property TcxCustomSchedulerStorageFields* CustomFields = {read=FCustomFields};
	__property TcxCustomSchedulerStorageFields* InternalFields = {read=FInternalFields};
	__property int InternalFieldCount = {read=GetInternalFieldCount, nodefault};
	__property bool IsChanged = {read=FIsChanged, write=FIsChanged, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	__property bool IsModified = {read=FIsModified, nodefault};
	__property bool IsUpdatingMode = {read=GetIsUpdatingMode, nodefault};
	__property TcxSchedulerEvent* LastEditedEvent = {read=FLastEditedEvent};
	__property System::Classes::TInterfaceList* Listeners = {read=FListeners};
	__property TcxSchedulerNotificationEvent OnEventDeleted = {read=FOnEventDeleted, write=FOnEventDeleted};
	__property TcxSchedulerNotificationEvent OnEventInserted = {read=FOnEventInserted, write=FOnEventInserted};
	__property TcxSchedulerEventIntersectEvent OnEventIntersect = {read=FOnEventIntersect, write=FOnEventIntersect};
	__property TcxSchedulerNotificationEvent OnEventModified = {read=FOnEventModified, write=FOnEventModified};
	__property TcxSchedulerFilterEventEvent OnFilterEvent = {read=FOnFilterEvent, write=SetOnFilterEvent};
	
public:
	__fastcall virtual TcxCustomSchedulerStorage(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomSchedulerStorage(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall AddListener(_di_IcxSchedulerStorageListener AListener);
	virtual void __fastcall BeginUpdate(void);
	void __fastcall CalculateEventActualTimeRanges(void);
	virtual bool __fastcall CheckRequiredFields(void);
	virtual TcxSchedulerEvent* __fastcall createEvent(void);
	TcxSchedulerEvent* __fastcall CreateOccurrence(TcxSchedulerEvent* APattern, const System::TDateTime ADate, TcxEventType AType);
	virtual void __fastcall Clear(void);
	void __fastcall DoneRestore(void);
	void __fastcall EndUpdate(void);
	bool __fastcall FindAvailableAllDay(System::TDateTime &AStart, System::TDateTime &AFinish, System::Variant &AResourceID, bool AExceptEventsWithoutResources, System::TDateTime ADuration = 0.000000E+00);
	bool __fastcall FindAvailableTime(System::TDateTime &AStart, System::TDateTime &AFinish, bool AllDay, System::Variant &AResourceID, bool AExceptEventsWithoutResources, System::TDateTime ADuration = 0.000000E+00, TcxSchedulerEvent* AExcludedEvent = (TcxSchedulerEvent*)(0x0))/* overload */;
	bool __fastcall FindAvailableTime(TcxSchedulerEvent* AEvent, bool AExceptEventsWithoutResources, System::TDateTime &AStart, System::TDateTime &AFinish)/* overload */;
	void __fastcall FullRefresh(void);
	virtual void __fastcall GenerateHolidayEvents(const System::Variant &AResourceID);
	TcxSchedulerEvent* __fastcall GetEventByID(const System::Variant &AID);
	bool __fastcall GetEvents(TcxSchedulerFilteredEventList* AList, const System::TDateTime AStart, const System::TDateTime AFinish)/* overload */;
	bool __fastcall GetEvents(TcxSchedulerFilteredEventList* AList, const System::TDateTime AStart, const System::TDateTime AFinish, const System::Variant &AResourceID)/* overload */;
	TcxCustomSchedulerStorageField* __fastcall GetFieldByName(const System::UnicodeString AName);
	virtual bool __fastcall GetHolidayNamesByDate(System::TDate ADate, System::UnicodeString &ANames, bool AOnlyVisible = true);
	bool __fastcall GetReminderEvents(System::TDateTime ADateTime, TcxSchedulerFilteredEventList* AList);
	void __fastcall InitRestore(void);
	virtual bool __fastcall IsActive(void);
	virtual bool __fastcall IsCaptionAvailable(void);
	virtual bool __fastcall IsLabelColorAvailable(void);
	virtual bool __fastcall IsLocationAvailable(void);
	virtual bool __fastcall IsMessageAvailable(void);
	virtual bool __fastcall IsRecurrenceAvailable(void);
	virtual bool __fastcall IsReminderByResourceAvailable(void);
	virtual bool __fastcall IsReminderAvailable(void);
	virtual bool __fastcall IsStateAvailable(void);
	virtual void __fastcall PopulateHolidayDates(Cxschedulerutils::TcxSchedulerDateList* AList, System::TDate AStart, System::TDate AFinish, bool AOnlyVisible = true, bool AClearList = true);
	virtual void __fastcall PostEvents(void);
	void __fastcall RemoveListener(_di_IcxSchedulerStorageListener AListener);
	void __fastcall HolidaysChanged(System::TObject* Sender);
	void __fastcall HolidaysRemoved(System::TObject* Sender);
	__property int EventCount = {read=GetEventCount, nodefault};
	__property TcxSchedulerEvent* Events[int Index] = {read=GetEvent, write=SetEvent};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TcxCustomSchedulerStorageField* Fields[int Index] = {read=GetField};
	__property Cxschedulerholidays::TcxSchedulerHolidays* Holidays = {read=FHolidays, write=SetHolidays};
	__property bool InternalUpdate = {read=FInternalUpdate, nodefault};
	__property TcxSchedulerEventLinksController* LinksController = {read=FLinksController};
	__property TcxSchedulerReminders* Reminders = {read=FReminders, write=SetReminders};
	__property int ResourceCount = {read=GetResourceCount, nodefault};
	__property System::Variant ResourceIDs[int Index] = {read=GetResourceID};
	__property System::UnicodeString ResourceNames[int Index] = {read=GetResourceName};
	__property TcxSchedulerStorageResources* Resources = {read=FResources, write=SetResources};
	__property System::UnicodeString StoringName = {read=FStoringName, write=FStoringName};
	__property double TimeBias = {read=FTimeBias};
	
__published:
	__property bool UseActualTimeRange = {read=FUseActualTimeRange, write=FUseActualTimeRange, default=0};
	__property bool StoreUsingGlobalTime = {read=FStoreUsingGlobalTime, write=SetStoreUsingGlobalTime, default=0};
	__property System::Classes::TNotifyEvent RemindersEvents = {read=FRemindersEvents, write=FRemindersEvents};
	__property System::Classes::TNotifyEvent ResourcesEvents = {read=FResourcesEvents, write=FResourcesEvents};
private:
	void *__IcxSchedulerHolidaysListener;	/* Cxschedulerholidays::IcxSchedulerHolidaysListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0FE58B1C-71C0-4ED0-9A10-12074CE13EA3}
	operator Cxschedulerholidays::_di_IcxSchedulerHolidaysListener()
	{
		Cxschedulerholidays::_di_IcxSchedulerHolidaysListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulerholidays::IcxSchedulerHolidaysListener*(void) { return (Cxschedulerholidays::IcxSchedulerHolidaysListener*)&__IcxSchedulerHolidaysListener; }
	#endif
	
};


class DELPHICLASS TcxSchedulerStorage;
class PASCALIMPLEMENTATION TcxSchedulerStorage : public TcxCustomSchedulerStorage
{
	typedef TcxCustomSchedulerStorage inherited;
	
private:
	TcxSchedulerStorageFields* __fastcall GetCustomFields(void);
	void __fastcall SetCustomFields(TcxSchedulerStorageFields* const AValue);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual System::Variant __fastcall GetEventID(TcxSchedulerEvent* AEvent);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SaveToFile(const System::UnicodeString AFileName);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	
__published:
	__property TcxSchedulerStorageFields* CustomFields = {read=GetCustomFields, write=SetCustomFields};
	__property Holidays;
	__property Reminders;
	__property Resources;
	__property OnEventDeleted;
	__property OnEventInserted;
	__property OnEventIntersect;
	__property OnEventModified;
	__property OnFilterEvent;
public:
	/* TcxCustomSchedulerStorage.Create */ inline __fastcall virtual TcxSchedulerStorage(System::Classes::TComponent* AOwner) : TcxCustomSchedulerStorage(AOwner) { }
	/* TcxCustomSchedulerStorage.Destroy */ inline __fastcall virtual ~TcxSchedulerStorage(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerControlEventID : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Variant ID;
	System::Variant ParentID;
	int RecurrenceIndex;
	__fastcall TcxSchedulerControlEventID(TcxSchedulerEvent* AEvent);
	bool __fastcall SameEvent(TcxSchedulerEvent* AEvent);
	HIDESBASE bool __fastcall Equals(TcxSchedulerControlEventID* AValue);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerControlEventID(void) { }
	
};


typedef void __fastcall (__closure *TcxEventSelectionChangedEvent)(TcxSchedulerControlEvent* AEvent);

class DELPHICLASS TcxSchedulerEventSelection;
class PASCALIMPLEMENTATION TcxSchedulerEventSelection : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
public:
	TcxSchedulerControlEvent* operator[](int Index) { return Items[Index]; }
	
private:
	TcxEventSelectionChangedEvent FOnEventSelectionChanged;
	int __fastcall GetCount(void);
	TcxSchedulerControlEvent* __fastcall GetItem(int AIndex);
	TcxSchedulerControlEventID* __fastcall GetKey(int AIndex);
	int __fastcall GetKeyCount(void);
	
protected:
	System::Classes::TList* FKeys;
	System::Classes::TList* FEvents;
	TcxSchedulerEventList* FSourceEvents;
	void __fastcall ClearKeys(void);
	TcxSchedulerControlEventID* __fastcall CreateItem(TcxSchedulerControlEvent* AEvent);
	void __fastcall DoEventSelectionChanged(TcxSchedulerControlEvent* AEvent);
	int __fastcall KeyIndexOf(TcxSchedulerControlEvent* AEvent);
	int __fastcall IndexOf(TcxSchedulerControlEvent* AEvent);
	void __fastcall InternalClear(void);
	void __fastcall ReplaceSelection(void);
	__property int KeyCount = {read=GetKeyCount, nodefault};
	__property TcxSchedulerControlEventID* Keys[int Index] = {read=GetKey};
	
public:
	__fastcall virtual TcxSchedulerEventSelection(TcxSchedulerEventList* ASourceEvents);
	__fastcall virtual ~TcxSchedulerEventSelection(void);
	void __fastcall Add(TcxSchedulerControlEvent* AEvent, System::Classes::TShiftState AShift);
	void __fastcall Clear(void);
	bool __fastcall IsSelected(TcxSchedulerControlEvent* AEvent);
	void __fastcall Select(TcxSchedulerEvent* AEvent);
	void __fastcall Update(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxSchedulerControlEvent* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxEventSelectionChangedEvent OnEventSelectionChanged = {read=FOnEventSelectionChanged, write=FOnEventSelectionChanged};
private:
	void *__IcxSchedulerSelectionAdapter;	/* IcxSchedulerSelectionAdapter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68B007E5-1057-40DE-BDA4-0D72F3780CC7}
	operator _di_IcxSchedulerSelectionAdapter()
	{
		_di_IcxSchedulerSelectionAdapter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxSchedulerSelectionAdapter*(void) { return (IcxSchedulerSelectionAdapter*)&__IcxSchedulerSelectionAdapter; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxSchedulerEventList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxSchedulerEvent* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxSchedulerEvent* __fastcall GetFirst(void);
	TcxSchedulerEvent* __fastcall GetEvent(int AIndex);
	TcxSchedulerEvent* __fastcall GetLast(void);
	
protected:
	virtual void __fastcall EventAdded(TcxSchedulerEvent* AEvent);
	virtual void __fastcall DoClear(bool AFreeItems);
	
public:
	__fastcall virtual TcxSchedulerEventList(void);
	__fastcall virtual ~TcxSchedulerEventList(void);
	virtual void __fastcall Assign(TcxSchedulerEventList* ASource, System::Classes::TListAssignOp AOperator = (System::Classes::TListAssignOp)(0x0));
	virtual int __fastcall Add(TcxSchedulerEvent* AEvent);
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	void __fastcall DestroyItems(void);
	int __fastcall Remove(TcxSchedulerEvent* AEvent);
	int __fastcall IndexOf(TcxSchedulerEvent* AEvent);
	virtual void __fastcall Sort(TcxCompareEventsProc ACompare);
	__property int Count = {read=GetCount, nodefault};
	__property TcxSchedulerEvent* First = {read=GetFirst};
	__property TcxSchedulerEvent* Items[int Index] = {read=GetEvent/*, default*/};
	__property TcxSchedulerEvent* Last = {read=GetLast};
	__property System::Classes::TList* List = {read=FItems, write=FItems};
};


class DELPHICLASS TcxSchedulerOccurrenceCalculator;
class PASCALIMPLEMENTATION TcxSchedulerFilteredEventList : public TcxSchedulerEventList
{
	typedef TcxSchedulerEventList inherited;
	
public:
	TcxSchedulerControlEvent* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	bool FExceptEventsWithoutResources;
	System::TDateTime FFinish;
	System::TDateTime FNow;
	bool FReminderEventsOnly;
	System::TDateTime FStart;
	TcxCustomSchedulerStorage* FStorage;
	bool FUseTimeRange;
	HIDESBASE TcxSchedulerControlEvent* __fastcall GetEvent(int AIndex);
	
protected:
	TcxSchedulerControlEvent* __fastcall AddEvent(TcxSchedulerEvent* AEvent);
	TcxSchedulerControlEvent* __fastcall AddOccurrence(TcxSchedulerOccurrenceCalculator* ACalculator);
	virtual void __fastcall Changed(void);
	virtual void __fastcall CheckEvent(TcxSchedulerEvent* AEvent, const System::Variant &AResourceID);
	bool __fastcall CheckResourceID(const System::Variant &AEventResourceID, const System::Variant &AResourceID);
	void __fastcall CheckRecurrenceEvent(TcxSchedulerEvent* AEvent, const System::Variant &AResourceID);
	void __fastcall CheckSimpleEvent(TcxSchedulerEvent* AEvent, const System::Variant &AResourceID);
	virtual TcxSchedulerControlEvent* __fastcall CreateControlEvent(TcxSchedulerEvent* AEvent);
	virtual double __fastcall GetTimeBias(void);
	virtual System::TDateTime __fastcall GetTimeBiasDaylightSavingTime(System::TDateTime ATime);
	virtual void __fastcall Init(const System::TDateTime AStart, const System::TDateTime AFinish, TcxCustomSchedulerStorage* AStorage);
	bool __fastcall NeedAddOccurenceForReminder(TcxSchedulerOccurrenceCalculator* ACalculator);
	__property bool UseTimeRange = {read=FUseTimeRange, write=FUseTimeRange, nodefault};
	__property System::TDateTime Now = {read=FNow};
	
public:
	__fastcall virtual TcxSchedulerFilteredEventList(void);
	__fastcall virtual ~TcxSchedulerFilteredEventList(void);
	void __fastcall ValidateTimeBias(TcxSchedulerControlEvent* AEvent);
	__property bool ExceptEventsWithoutResources = {read=FExceptEventsWithoutResources, write=FExceptEventsWithoutResources, nodefault};
	__property System::TDateTime Finish = {read=FFinish};
	__property bool ReminderEventsOnly = {read=FReminderEventsOnly, nodefault};
	__property System::TDateTime Start = {read=FStart};
	__property TcxCustomSchedulerStorage* Storage = {read=FStorage};
	__property TcxSchedulerControlEvent* Items[int AIndex] = {read=GetEvent/*, default*/};
	__property Count;
};


class DELPHICLASS TcxSchedulerCachedEventList;
class PASCALIMPLEMENTATION TcxSchedulerCachedEventList : public TcxSchedulerFilteredEventList
{
	typedef TcxSchedulerFilteredEventList inherited;
	
public:
	TcxSchedulerControlEvent* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FAbsoluteItems;
	bool FAlwaysShowSelectedEvent;
	TcxSchedulerFilteredEventList* FClones;
	bool FDaylightSaving;
	TcxSchedulerEvent* FNewEvent;
	System::TDateTime FSelStart;
	System::TDateTime FSelFinish;
	TcxSchedulerEventSelection* FSelection;
	bool FShowEventsWithoutResource;
	double FTimeBias;
	int FTimeZone;
	int __fastcall GetAbsoluteCount(void);
	TcxSchedulerControlEvent* __fastcall GetAbsoluteItem(int AIndex);
	int __fastcall GetAbsoluteCountInternal(void);
	TcxSchedulerControlEvent* __fastcall GetAbsoluteItemInternal(int AIndex);
	TcxSchedulerControlEvent* __fastcall GetItem(int AIndex);
	void __fastcall SetSelFinish(const System::TDateTime AValue);
	void __fastcall SetSelStart(const System::TDateTime AValue);
	
protected:
	int FBeforePostCount;
	int FChangeRef;
	bool FExpandedTimeRange;
	bool FHasClones;
	int FSavedIndex;
	System::Variant FSavedPatternID;
	System::Variant FSavedSourceID;
	System::TDateTime FMinNecessaryDate;
	System::TDateTime FMaxNecessaryDate;
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE void __fastcall AddEvent(TcxSchedulerEvent* AEvent);
	void __fastcall RemoveEvent(TcxSchedulerEvent* AEvent);
	void __fastcall StorageChanged(System::TObject* Sender);
	void __fastcall StorageRemoved(System::TObject* Sender);
	virtual void __fastcall Changed(void);
	virtual void __fastcall CheckEvent(TcxSchedulerEvent* AEvent, const System::Variant &AResourceID);
	bool __fastcall CheckEventVisibility(TcxSchedulerEvent* AEvent, bool AIncludeUnassigned);
	virtual TcxSchedulerFilteredEventList* __fastcall CreateCloneList(void);
	virtual TcxSchedulerEventSelection* __fastcall CreateSelection(void);
	virtual void __fastcall DoClear(bool AFreeItems);
	virtual double __fastcall GetTimeBias(void);
	virtual System::TDateTime __fastcall GetTimeBiasDaylightSavingTime(System::TDateTime ATime);
	virtual void __fastcall EventAdded(TcxSchedulerEvent* AEvent);
	virtual void __fastcall Init(const System::TDateTime AStart, const System::TDateTime AFinish, TcxCustomSchedulerStorage* AStorage);
	void __fastcall InternalPost(TcxSchedulerControlEvent* AEvent, bool ACopy);
	bool __fastcall IsDayNoneEmpty(int ADay);
	bool __fastcall IsIntersect(TcxSchedulerEvent* AEvent1, TcxSchedulerEvent* AEvent2);
	virtual bool __fastcall IsSelected(TcxSchedulerControlEvent* AEvent);
	void __fastcall PopulateAbsoluteItems(void);
	virtual void __fastcall PostCloneForRecurrenceEvent(TcxSchedulerControlEvent* AEvent, bool ACopy);
	virtual void __fastcall PostCloneForSimpleEvent(TcxSchedulerControlEvent* AEvent, bool ACopy, TcxEventType AType);
	void __fastcall PostNewEvent(TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall SelectionAdd(TcxSchedulerControlEvent* AEvent, System::Classes::TShiftState Shift);
	virtual void __fastcall SelectionClear(void);
	virtual void __fastcall SelectionUpdate(void);
	
public:
	__fastcall virtual TcxSchedulerCachedEventList(void);
	__fastcall virtual ~TcxSchedulerCachedEventList(void);
	void __fastcall BeforeEditing(TcxSchedulerControlEvent* AEvent, bool AIsInplace);
	void __fastcall BeforeUpdate(void);
	void __fastcall DeleteEvent(TcxSchedulerControlEvent* AEvent);
	void __fastcall CalculateClonesRange(System::TDateTime &AMinDate, System::TDateTime &AMaxDate);
	bool __fastcall CalculateNecessaryDate(System::TDateTime &AMinDate, System::TDateTime &AMaxDate);
	void __fastcall CalculateSelectionRange(System::TDateTime &AMinDate, System::TDateTime &AMaxDate);
	void __fastcall CancelClones(void);
	TcxSchedulerEventList* __fastcall CreateClones(void);
	TcxSchedulerControlEvent* __fastcall CreateEvent(bool AInsertToList);
	void __fastcall ExtractEvents(const System::TDateTime ADate, TcxSchedulerEventList* AList);
	void __fastcall ExtractUsedDays(Cxschedulerutils::TcxSchedulerDateList* AList);
	bool __fastcall HasConflict(bool IsDragCopy, bool AStartDrag);
	bool __fastcall HasIntersection(TcxSchedulerControlEvent* AEvent)/* overload */;
	bool __fastcall HasIntersection(System::Classes::TList* AList)/* overload */;
	bool __fastcall HasIntersection(TcxSchedulerEventList* AList1, TcxSchedulerEventList* AList2, bool AExcludeEquals)/* overload */;
	TcxSchedulerControlEvent* __fastcall LastEditedEvent(void);
	void __fastcall PostClones(bool ACopy);
	void __fastcall PostEvent(TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall Sort(TcxCompareEventsProc ACompare);
	__property int AbsoluteCount = {read=GetAbsoluteCount, nodefault};
	__property TcxSchedulerControlEvent* AbsoluteItems[int Index] = {read=GetAbsoluteItem};
	__property System::Classes::TList* AbsoluteItemsList = {read=FAbsoluteItems};
	__property bool AlwaysShowSelectedEvent = {read=FAlwaysShowSelectedEvent, write=FAlwaysShowSelectedEvent, nodefault};
	__property int TimeZone = {read=FTimeZone, write=FTimeZone, nodefault};
	__property TcxSchedulerFilteredEventList* Clones = {read=FClones};
	__property bool DaylightSaving = {read=FDaylightSaving, write=FDaylightSaving, nodefault};
	__property bool ShowEventsWithoutResource = {read=FShowEventsWithoutResource, write=FShowEventsWithoutResource, nodefault};
	__property System::TDateTime SelStart = {read=FSelStart, write=SetSelStart};
	__property System::TDateTime SelFinish = {read=FSelFinish, write=SetSelFinish};
	__property TcxSchedulerEventSelection* Selection = {read=FSelection};
	__property TcxSchedulerControlEvent* Items[int Index] = {read=GetItem/*, default*/};
	__property UseTimeRange;
private:
	void *__IcxSchedulerStorageListener2;	/* IcxSchedulerStorageListener2 */
	void *__IcxSchedulerSelectionAdapter;	/* IcxSchedulerSelectionAdapter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4809FF3B-D9F8-4FD5-8647-33F8892599A4}
	operator _di_IcxSchedulerStorageListener2()
	{
		_di_IcxSchedulerStorageListener2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxSchedulerStorageListener2*(void) { return (IcxSchedulerStorageListener2*)&__IcxSchedulerStorageListener2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {87E0EBF3-F68A-4A51-8EA3-850D3819FBAB}
	operator _di_IcxSchedulerStorageListener()
	{
		_di_IcxSchedulerStorageListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxSchedulerStorageListener*(void) { return (IcxSchedulerStorageListener*)&__IcxSchedulerStorageListener2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {68B007E5-1057-40DE-BDA4-0D72F3780CC7}
	operator _di_IcxSchedulerSelectionAdapter()
	{
		_di_IcxSchedulerSelectionAdapter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxSchedulerSelectionAdapter*(void) { return (IcxSchedulerSelectionAdapter*)&__IcxSchedulerSelectionAdapter; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxSchedulerStorageListener2; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxSchedulerOccurrenceCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::TDateTime FReminderAdvanceTime;
	System::TDateTime __fastcall GetReminderStart(void);
	
protected:
	System::TDateTime FActualStart;
	bool FCalcForReminders;
	int FDate;
	System::Word FDay;
	int FDayNumber;
	TcxDayType FDayType;
	System::TDateTime FDismissDate;
	TcxSchedulerEvent* FEvent;
	System::TDateTime FFinishDate;
	int FIndex;
	System::Word FMonth;
	Cxdateutils::TDays FOccurDays;
	System::TDateTime FOccurrenceFinish;
	System::TDateTime FOccurrenceStart;
	int FPeriodicity;
	int FRecurCount;
	TcxRecurrence FRecurrence;
	int FStartOfWeek;
	System::TDateTime FVisibleFinish;
	System::TDateTime FVisibleStart;
	int FWeekStart;
	Cxdateutils::TDays FWorkDays;
	System::Word FYear;
	int FYearPeriodicity;
	TcxSchedulerControlEvent* FOccurence;
	int FOccurencePos;
	void __fastcall CalcFirstDate(void);
	void __fastcall CalcNextDate(void);
	int __fastcall GetCertainDay(const int ADate, const int ANumber, TcxDayType ADayType);
	virtual int __fastcall GetDayForMonth(void);
	int __fastcall GetDayFromOccurDays(const int APrevDate, const int APeriodicity);
	int __fastcall GetSomeDay(const int ADate, const int ANumber, bool AWeekEnd);
	void __fastcall InitTimes(void);
	bool __fastcall IsValidOccurrence(void);
	
public:
	__fastcall TcxSchedulerOccurrenceCalculator(TcxSchedulerEvent* AEvent, const System::TDateTime AStart, const System::TDateTime AFinish, bool ACalcForReminders);
	void __fastcall CalcOccurrence(int AIndex);
	void __fastcall CalcNearestOccurrenceIntervals(System::TDateTime AStart, System::TDateTime AFinish, System::TDateTime &AnIntervalBefore, System::TDateTime &AnIntervalAfter);
	virtual bool __fastcall GetNextOccurrence(void);
	int __fastcall GetOccurrenceCount(System::TDateTime AEndDate);
	__property TcxSchedulerEvent* Event = {read=FEvent};
	__property System::TDateTime DismissDate = {read=FDismissDate};
	__property int Index = {read=FIndex, nodefault};
	__property System::TDateTime OccurrenceFinish = {read=FOccurrenceFinish};
	__property System::TDateTime OccurrenceStart = {read=FOccurrenceStart};
	__property System::TDateTime ReminderStart = {read=GetReminderStart};
	__property int StartOfWeek = {read=FStartOfWeek, nodefault};
	__property System::TDateTime VisibleFinish = {read=FVisibleFinish};
	__property System::TDateTime VisibleStart = {read=FVisibleStart};
	__property Cxdateutils::TDays WorkDays = {read=FWorkDays, write=FWorkDays, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerOccurrenceCalculator(void) { }
	
};


class DELPHICLASS TcxSchedulerContentNavigationInfo;
class PASCALIMPLEMENTATION TcxSchedulerContentNavigationInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Variant FResourceID;
	System::TDateTime FIntervalBefore;
	System::TDateTime FIntervalAfter;
	__fastcall TcxSchedulerContentNavigationInfo(System::Variant &AResourceID);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerContentNavigationInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerContentNavigationCalculator;
class PASCALIMPLEMENTATION TcxSchedulerContentNavigationCalculator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	__classmethod void __fastcall CalcAppointmentIntervals(TcxSchedulerEvent* AnEvent, TcxSchedulerContentNavigationInfo* AInfo, System::TDateTime AStart, System::TDateTime AFinish, System::TDateTime AScaleUnit);
	__classmethod void __fastcall CalcIntervals(TcxSchedulerEvent* AnEvent, TcxSchedulerContentNavigationInfo* AInfo, System::TDateTime AStart, System::TDateTime AFinish, System::TDateTime AScaleUnit);
	__classmethod void __fastcall CalcPatternIntervals(TcxSchedulerEvent* AnEvent, TcxSchedulerContentNavigationInfo* AInfo, System::TDateTime AStart, System::TDateTime AFinish);
	__classmethod void __fastcall ChangeResourceNavigationIntervals(System::Contnrs::TObjectList* AContentNavigationInfo);
	__classmethod bool __fastcall IsEventSharedWithAnyResource(TcxCustomSchedulerStorage* AStorage, int AnEventIndex, bool ConsiderVisibility);
	
public:
	__classmethod void __fastcall FindNavigationIntervals(TcxCustomSchedulerStorage* AStorage, System::Contnrs::TObjectList* AContentNavigationInfo, System::TDateTime AStart, System::TDateTime AFinish, bool AWithoutResources, bool AShowEventsWithoutResource, System::TDateTime AScaleUnit);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerContentNavigationCalculator(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerContentNavigationCalculator(void) { }
	
};


class DELPHICLASS TcxSchedulerCustomReminderForm;
class PASCALIMPLEMENTATION TcxSchedulerCustomReminderForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TcxSchedulerReminders* FReminders;
	TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	
protected:
	virtual void __fastcall CheckFormPosition(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DoClose(System::Uitypes::TCloseAction &Action);
	DYNAMIC void __fastcall DoShow(void);
	void __fastcall FlashCaption(void);
	virtual System::Uitypes::TColor __fastcall GetFormColor(void);
	virtual bool __fastcall IsLocked(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall OpenEvent(TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall OpenEventSupported(void);
	virtual void __fastcall RestoreSelection(void);
	virtual void __fastcall SaveSelection(void);
	void __fastcall ShowInactive(void);
	virtual void __fastcall UpdateReminderList(void);
	virtual void __fastcall UpdateSelectionCaptions(void);
	__property TcxSchedulerReminders* Reminders = {read=FReminders};
	__property TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	
public:
	__fastcall virtual TcxSchedulerCustomReminderForm(TcxSchedulerReminders* AReminders);
	__fastcall virtual ~TcxSchedulerCustomReminderForm(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxSchedulerCustomReminderForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSchedulerCustomReminderForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxSchedulerReminderFormClass;

class DELPHICLASS TcxSchedulerReminderEventID;
class PASCALIMPLEMENTATION TcxSchedulerReminderEventID : public TcxSchedulerControlEventID
{
	typedef TcxSchedulerControlEventID inherited;
	
private:
	typedef System::DynamicArray<System::Variant> _TcxSchedulerReminderEventID__1;
	
	
protected:
	_TcxSchedulerReminderEventID__1 Values;
	
public:
	__fastcall TcxSchedulerReminderEventID(TcxSchedulerControlEvent* AEvent);
	__fastcall virtual ~TcxSchedulerReminderEventID(void);
	HIDESBASE bool __fastcall SameEvent(TcxSchedulerControlEvent* AEvent);
};


class DELPHICLASS TcxSchedulerEventReminders;
class DELPHICLASS TcxSchedulerReminder;
class PASCALIMPLEMENTATION TcxSchedulerEventReminders : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<TcxSchedulerReminder*> _TcxSchedulerEventReminders__1;
	
	
private:
	bool FInvalid;
	
public:
	TcxSchedulerReminderEventID* EventID;
	_TcxSchedulerEventReminders__1 Reminders;
	__fastcall TcxSchedulerEventReminders(TcxSchedulerControlEvent* AEvent);
	__fastcall virtual ~TcxSchedulerEventReminders(void);
	void __fastcall AddReminder(TcxSchedulerReminder* AReminder);
	TcxSchedulerReminder* __fastcall Find(System::TDateTime AReminderDate, const System::Variant &AResourceID);
	void __fastcall FreeReminderByIndex(int AIndex);
	void __fastcall FreeReminders(void);
	void __fastcall Invalidate(void);
	bool __fastcall IsValid(void);
	void __fastcall RemoveInvalidReminders(void);
	void __fastcall Validate(void);
};


class DELPHICLASS TcxSchedulerEventRemindersList;
class PASCALIMPLEMENTATION TcxSchedulerEventRemindersList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
private:
	HIDESBASE TcxSchedulerEventReminders* __fastcall GetItem(int AIndex);
	
public:
	TcxSchedulerEventReminders* __fastcall CreateEventReminders(TcxSchedulerControlEvent* AEvent);
	TcxSchedulerEventReminders* __fastcall FindForEvent(TcxSchedulerControlEvent* AEvent);
	void __fastcall Invalidate(void);
	HIDESBASE void __fastcall Remove(TcxSchedulerEventReminders* AEventReminders);
	void __fastcall RemoveInvalidItems(void);
	__property TcxSchedulerEventReminders* Items[int Index] = {read=GetItem};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxSchedulerEventRemindersList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxSchedulerEventRemindersList(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReminder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerControlEvent* FEvent;
	TcxSchedulerEventReminders* FEventReminders;
	TcxSchedulerReminders* FOwner;
	System::TDateTime FReminderDate;
	System::Variant FResourceID;
	bool FInvalid;
	TcxSchedulerReminderResourcesData __fastcall GetResourcesData(void);
	
protected:
	void __fastcall ClearReminder(void);
	virtual void __fastcall DismissEvent(void);
	virtual void __fastcall DismissEventForResource(void);
	virtual void __fastcall DoDismiss(void);
	virtual void __fastcall DoSnooze(System::TDateTime &ASnoozeTime);
	virtual System::TDateTime __fastcall GetRecurrenceDismissDate(void);
	void __fastcall SetData(const System::Variant &AResourceID, System::TDateTime AReminderDate);
	virtual void __fastcall SnoozeEvent(const System::TDateTime ASnoozeTime);
	virtual void __fastcall SnoozeEventForResource(const System::TDateTime ATime);
	void __fastcall Validate(TcxSchedulerControlEvent* AEvent);
	__property TcxSchedulerEventReminders* EventReminders = {read=FEventReminders};
	__property bool Invalid = {read=FInvalid, write=FInvalid, nodefault};
	
public:
	__fastcall virtual TcxSchedulerReminder(TcxSchedulerReminders* AOwner, TcxSchedulerControlEvent* AEvent);
	__fastcall virtual ~TcxSchedulerReminder(void);
	void __fastcall Dismiss(void);
	void __fastcall Snooze(System::TDateTime ASnoozeTime);
	__property TcxSchedulerControlEvent* Event = {read=FEvent};
	__property TcxSchedulerReminders* Owner = {read=FOwner};
	__property System::Variant ResourceID = {read=FResourceID};
	__property System::TDateTime ReminderDate = {read=FReminderDate};
};


class DELPHICLASS TcxSchedulerReminderList;
class PASCALIMPLEMENTATION TcxSchedulerReminderList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TcxSchedulerReminder* operator[](int Index) { return Items[Index]; }
	
private:
	bool FClearing;
	TcxSchedulerReminder* __fastcall GetItem(int Index);
	
public:
	virtual void __fastcall Clear(void);
	__property bool Clearing = {read=FClearing, nodefault};
	__property TcxSchedulerReminder* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxSchedulerReminderList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerReminderList(void) : System::Classes::TList() { }
	
};


typedef void __fastcall (__closure *TcxSchedulerReminderEvent)(TcxSchedulerReminders* Sender, TcxSchedulerReminder* AReminder, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerRemindersEvent)(TcxSchedulerReminders* Sender);

typedef void __fastcall (__closure *TcxSchedulerGetEventDueTimeTextEvent)(TcxSchedulerReminders* Sender, TcxSchedulerReminder* AReminder, const TcxSchedulerReminderDueTimeInfo &ADueTimeInfo, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxSchedulerGetReminderWindowCaption)(TcxSchedulerReminders* Sender, System::UnicodeString &ACaption);

typedef void __fastcall (__closure *TcxSchedulerSnoozeReminderEvent)(TcxSchedulerReminders* Sender, TcxSchedulerReminder* AReminder, System::TDateTime &ASnoozeTime, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerReminderOpenEvent)(TcxSchedulerReminders* Sender, TcxSchedulerControlEvent* AEvent);

class DELPHICLASS TcxSchedulerReminderEventsList;
class PASCALIMPLEMENTATION TcxSchedulerReminderEventsList : public TcxSchedulerFilteredEventList
{
	typedef TcxSchedulerFilteredEventList inherited;
	
private:
	TcxSchedulerReminders* FReminders;
	
protected:
	virtual TcxSchedulerControlEvent* __fastcall CreateControlEvent(TcxSchedulerEvent* AEvent);
	virtual double __fastcall GetTimeBias(void);
	virtual System::TDateTime __fastcall GetTimeBiasDaylightSavingTime(System::TDateTime ATime);
	__property TcxSchedulerReminders* Reminders = {read=FReminders};
	
public:
	__fastcall TcxSchedulerReminderEventsList(TcxSchedulerReminders* AOwner)/* overload */;
public:
	/* TcxSchedulerFilteredEventList.Destroy */ inline __fastcall virtual ~TcxSchedulerReminderEventsList(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReminders : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
public:
	TcxSchedulerReminder* operator[](int Index) { return Items[Index]; }
	
private:
	bool FActive;
	int FDefaultMinutesBeforeStart;
	bool FDefaultReminder;
	TcxSchedulerFilteredEventList* FEvents;
	TcxSchedulerEventRemindersList* FEventRemindersList;
	TcxSchedulerReminderList* FItems;
	int FLockCount;
	Cxlookandfeels::TcxLookAndFeel* FReminderWindowLookAndFeel;
	bool FNeedCloseWindow;
	bool FNeedRestoreSelection;
	bool FNeedShowWindow;
	bool FReminderByResource;
	TcxSchedulerCustomReminderForm* FReminderWindow;
	bool FShowResourcesInReminderWindow;
	TcxCustomSchedulerStorage* FStorage;
	int FTimeZone;
	bool FTimeZoneDaylightSaving;
	Vcl::Extctrls::TTimer* FUpdateEventsTimer;
	Vcl::Extctrls::TTimer* FUpdateRemindersTimer;
	bool FUpdatingReminderList;
	bool FUseReminderWindow;
	TcxSchedulerReminderEvent FOnAlertReminder;
	TcxSchedulerReminderEvent FOnDismissReminder;
	TcxSchedulerGetEventDueTimeTextEvent FOnGetEventDueTimeText;
	TcxSchedulerReminderOpenEvent FOnOpenEvent;
	TcxSchedulerSnoozeReminderEvent FOnSnoozeReminder;
	TcxSchedulerGetReminderWindowCaption FOnGetReminderWindowCaption;
	TcxSchedulerRemindersEvent FOnHideReminderWindow;
	TcxSchedulerRemindersEvent FOnShowReminderWindow;
	void __fastcall CreateTimers(void);
	int __fastcall GetCount(void);
	TcxSchedulerReminder* __fastcall GetItem(int Index);
	int __fastcall GetTimeZone(void);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetDefaultMinutesBeforeStart(int AValue);
	void __fastcall SetReminderByResource(bool AValue);
	void __fastcall SetReminderWindowLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetShowResourcesInReminderWindow(bool AValue);
	void __fastcall SetTimeZone(int AValue);
	void __fastcall StartReminder(void);
	void __fastcall StopReminder(void);
	void __fastcall UpdateReminderWindow(void);
	void __fastcall OnUpdateEventsTimer(System::TObject* Sender);
	void __fastcall OnUpdateRemindersTimer(System::TObject* Sender);
	
protected:
	void __fastcall FormatChanged(void);
	void __fastcall TimeChanged(void);
	void __fastcall AddReminder(TcxSchedulerControlEvent* AEvent, const System::Variant &AResourceID, System::TDateTime AReminderDate, TcxSchedulerEventReminders* &AEventReminders);
	void __fastcall AddReminderToEventReminders(TcxSchedulerReminder* AReminder, TcxSchedulerEventReminders* &AEventReminders);
	void __fastcall CheckAddReminder(TcxSchedulerControlEvent* AEvent, const System::Variant &AResourceID, System::TDateTime AReminderDate, TcxSchedulerEventReminders* &AEventReminders);
	void __fastcall CheckAddReminders(TcxSchedulerControlEvent* AEvent, TcxSchedulerEventReminders* AEventReminders);
	void __fastcall CheckRemindersForEvent(TcxSchedulerControlEvent* AEvent);
	virtual TcxSchedulerCustomReminderForm* __fastcall CreateReminderWindow(void);
	virtual bool __fastcall DoAlertReminder(TcxSchedulerReminder* AReminder);
	virtual bool __fastcall DoDismissReminder(TcxSchedulerReminder* AReminder);
	void __fastcall DoGetEventDueTimeText(TcxSchedulerReminder* AReminder, const TcxSchedulerReminderDueTimeInfo &ADueTimeInfo, System::UnicodeString &AText);
	virtual void __fastcall DoGetReminderWindowCaption(System::UnicodeString &ACaption);
	virtual void __fastcall DoOpenEvent(TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall DoSnoozeReminder(TcxSchedulerReminder* AReminder, System::TDateTime &ASnoozeTime);
	virtual void __fastcall DoHideReminderWindow(void);
	virtual void __fastcall DoShowReminderWindow(void);
	System::TDateTime __fastcall GetFirstReminderTimeForEvent(TcxSchedulerEvent* AEvent, System::TDateTime ANow);
	virtual System::TDateTime __fastcall GetNextPopulateEventsCacheTime(System::TDateTime ANow, bool AIsLocked);
	virtual System::TDateTime __fastcall GetNextRefreshRemindersTime(System::TDateTime ANow, bool AIsLocked);
	virtual System::TDateTime __fastcall GetNow(void);
	virtual TcxSchedulerReminderClass __fastcall GetReminderClass(void);
	TcxSchedulerReminderResources __fastcall GetReminderResourcesFromEvent(TcxSchedulerControlEvent* AEvent, bool AGetFromPattern);
	System::UnicodeString __fastcall GetReminderWindowCaption(void);
	virtual bool __fastcall IsNeedAddToReminders(TcxSchedulerControlEvent* AEvent, const System::TDateTime AReminderDate);
	virtual bool __fastcall PopulateEventsCache(void);
	virtual void __fastcall RefreshReminders(void);
	void __fastcall RemoveEvent(TcxSchedulerEvent* AEvent);
	void __fastcall RemoveEventReminders(TcxSchedulerReminder* AReminder);
	virtual void __fastcall StopTimers(void);
	virtual void __fastcall UpdateReminderList(void);
	void __fastcall UpdateTimer(Vcl::Extctrls::TTimer* ATimer, System::TDateTime AInterval);
	void __fastcall ValidateReminderList(void);
	void __fastcall CheckRemindersForRecurringEvent(TcxSchedulerControlEvent* AEvent, int &AIndex);
	void __fastcall ValidateRemindersForEvent(TcxSchedulerEventReminders* AEventReminders, TcxSchedulerControlEvent* AEvent);
	__property TcxSchedulerFilteredEventList* Events = {read=FEvents};
	__property bool NeedCloseWindow = {read=FNeedCloseWindow, nodefault};
	__property bool NeedRestoreSelection = {read=FNeedRestoreSelection, write=FNeedRestoreSelection, nodefault};
	__property bool NeedShowWindow = {read=FNeedShowWindow, nodefault};
	__property Vcl::Extctrls::TTimer* UpdateEventsTimer = {read=FUpdateEventsTimer};
	__property Vcl::Extctrls::TTimer* UpdateRemindersTimer = {read=FUpdateRemindersTimer};
	__property bool UpdatingReminderList = {read=FUpdatingReminderList, nodefault};
	
public:
	__fastcall virtual TcxSchedulerReminders(TcxCustomSchedulerStorage* AStorage);
	__fastcall virtual ~TcxSchedulerReminders(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall DismissAll(void);
	void __fastcall SnoozeAll(System::TDateTime ASnoozeTime);
	System::UnicodeString __fastcall GetEventDueTimeText(TcxSchedulerReminder* AReminder, System::TDateTime ATime);
	bool __fastcall HasReminders(void);
	void __fastcall HideReminderWindow(void);
	virtual bool __fastcall IsLocked(void);
	bool __fastcall IsReminderByResourceAvailable(void);
	bool __fastcall IsReminderValid(TcxSchedulerReminder* AReminder);
	bool __fastcall IsReminderWindowShown(void);
	void __fastcall Refresh(void);
	void __fastcall ShowReminderWindow(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxSchedulerReminder* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxSchedulerCustomReminderForm* ReminderWindow = {read=FReminderWindow};
	__property TcxCustomSchedulerStorage* Storage = {read=FStorage};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=1};
	__property int DefaultMinutesBeforeStart = {read=FDefaultMinutesBeforeStart, write=SetDefaultMinutesBeforeStart, default=15};
	__property bool DefaultReminder = {read=FDefaultReminder, write=FDefaultReminder, default=0};
	__property bool ReminderByResource = {read=FReminderByResource, write=SetReminderByResource, default=0};
	__property Cxlookandfeels::TcxLookAndFeel* ReminderWindowLookAndFeel = {read=FReminderWindowLookAndFeel, write=SetReminderWindowLookAndFeel};
	__property bool ShowResourcesInReminderWindow = {read=FShowResourcesInReminderWindow, write=SetShowResourcesInReminderWindow, default=1};
	__property int TimeZone = {read=GetTimeZone, write=SetTimeZone, default=-1};
	__property bool TimeZoneDaylightSaving = {read=FTimeZoneDaylightSaving, write=FTimeZoneDaylightSaving, default=0};
	__property bool UseReminderWindow = {read=FUseReminderWindow, write=FUseReminderWindow, default=1};
	__property TcxSchedulerReminderEvent OnAlertReminder = {read=FOnAlertReminder, write=FOnAlertReminder};
	__property TcxSchedulerReminderEvent OnDismissReminder = {read=FOnDismissReminder, write=FOnDismissReminder};
	__property TcxSchedulerReminderOpenEvent OnOpenEvent = {read=FOnOpenEvent, write=FOnOpenEvent};
	__property TcxSchedulerSnoozeReminderEvent OnSnoozeReminder = {read=FOnSnoozeReminder, write=FOnSnoozeReminder};
	__property TcxSchedulerRemindersEvent OnHideReminderWindow = {read=FOnHideReminderWindow, write=FOnHideReminderWindow};
	__property TcxSchedulerRemindersEvent OnShowReminderWindow = {read=FOnShowReminderWindow, write=FOnShowReminderWindow};
	__property TcxSchedulerGetEventDueTimeTextEvent OnGetEventDueTimeText = {read=FOnGetEventDueTimeText, write=FOnGetEventDueTimeText};
	__property TcxSchedulerGetReminderWindowCaption OnGetReminderWindowCaption = {read=FOnGetReminderWindowCaption, write=FOnGetReminderWindowCaption};
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxFormatControllerListener2;	/* Cxformats::IcxFormatControllerListener2 */
	void *__IcxFormatControllerListener;	/* Cxformats::IcxFormatControllerListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5E33A2A7-0C77-415F-A359-112103E54937}
	operator Cxformats::_di_IcxFormatControllerListener2()
	{
		Cxformats::_di_IcxFormatControllerListener2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener2*(void) { return (Cxformats::IcxFormatControllerListener2*)&__IcxFormatControllerListener2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A7F2F6D3-1A7D-4295-A6E6-9297BD83D0DE}
	operator Cxformats::_di_IcxFormatControllerListener()
	{
		Cxformats::_di_IcxFormatControllerListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener*(void) { return (Cxformats::IcxFormatControllerListener*)&__IcxFormatControllerListener; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 omAllDayEvent = System::Int8(0x1);
static const System::Int8 omEnabled = System::Int8(0x2);
static const System::Int8 omReminder = System::Int8(0x4);
static const System::Int8 omCollapsed = System::Int8(0x8);
static const System::Int8 omGroup = System::Int8(0x10);
static const System::Int8 tlsFree = System::Int8(0x0);
static const System::Int8 tlsTentative = System::Int8(0x1);
static const System::Int8 tlsBusy = System::Int8(0x2);
static const System::Int8 tlsOutOfOffice = System::Int8(0x3);
extern PACKAGE System::TDateTime cxDefaultEventDuration;
static const int cxMaxDate = int(0xbb422);
static const int cxInvalidRecordIndex = int(-2147483647);
extern PACKAGE double ReminderRefreshInterval;
extern PACKAGE TcxGetRecurrenceDescriptionStringProc cxGetRecurrenceDescriptionStringProc;
extern PACKAGE TcxDueTimeInfoToTextProc cxDueTimeInfoToTextProc;
extern PACKAGE TcxSchedulerEventConflictsInfoClass cxSchedulerEventConflictsInfoClass;
extern PACKAGE int cxMaxCheckedDuration;
extern PACKAGE System::StaticArray<System::Byte, 2> cxOriginalEventStates;
extern PACKAGE void __fastcall cxCheckDaysList(System::Classes::TList* AList, int &AStartDay, int &AFinishDay);
extern PACKAGE System::UnicodeString __fastcall cxGetRecurrenceDescriptionString(TcxSchedulerEventRecurrenceInfo* ARecurrenceInfo, bool AFullDescription = false);
extern PACKAGE System::AnsiString __fastcall cxRecurrenceInfoDataToString(const TcxSchedulerEventRecurrenceInfoData &AData);
extern PACKAGE TcxSchedulerEventRecurrenceInfoData __fastcall cxStringToRecurrenceInfoData(const System::AnsiString S);
extern PACKAGE TcxSchedulerReminderDueTimeInfo __fastcall cxMinutesToDueTimeInfo(int AMinutes);
extern PACKAGE System::UnicodeString __fastcall cxDueTimeInfoToText(const TcxSchedulerReminderDueTimeInfo &AInfo);
extern PACKAGE int __fastcall cxCompareSchedulerControlEvents(TcxSchedulerControlEvent* AEvent1, TcxSchedulerControlEvent* AEvent2);
extern PACKAGE System::Variant __fastcall cxVariantToFieldValue(const System::Variant &AValue, bool ABLOBFormat = false);
extern PACKAGE System::Variant __fastcall cxFieldValueToVariant(const System::Variant &AValue);
extern PACKAGE System::Variant __fastcall cxReminderResourcesDataToFieldValue(const TcxSchedulerReminderResourcesData &AValue);
extern PACKAGE TcxSchedulerReminderResourcesData __fastcall cxFieldValueToReminderResourcesData(const System::Variant &AValue);
extern PACKAGE System::Variant __fastcall cxTaskLinksToFieldValue(TcxSchedulerEventLinks* ALinks);
extern PACKAGE void __fastcall cxFieldValueToTaskLinks(const System::Variant &AValue, TcxSchedulerEventLinks* ALinks);
extern PACKAGE double __fastcall GetStreamVersion(System::Classes::TStream* const AStream, int &AFieldCount, int ACustomFieldCount = 0x0);
}	/* namespace Cxschedulerstorage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERSTORAGE)
using namespace Cxschedulerstorage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerstorageHPP
