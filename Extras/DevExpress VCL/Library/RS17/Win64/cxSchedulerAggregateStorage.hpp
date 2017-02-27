// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerAggregateStorage.pas' rev: 24.00 (Win64)

#ifndef CxscheduleraggregatestorageHPP
#define CxscheduleraggregatestorageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerHolidays.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxscheduleraggregatestorage
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxSchedulerStorageLinkClass;

class DELPHICLASS TcxSchedulerStorageLink;
class DELPHICLASS TcxSchedulerAggregateStorage;
class DELPHICLASS TcxSchedulerStorageLinks;
class PASCALIMPLEMENTATION TcxSchedulerStorageLink : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool FIsDestroying;
	Cxschedulerstorage::TcxCustomSchedulerStorage* FStorage;
	TcxSchedulerAggregateStorage* __fastcall GetAggregateStorage(void);
	bool __fastcall GetDefault(void);
	TcxSchedulerStorageLinks* __fastcall GetLinks(void);
	void __fastcall SetDefault(bool AValue);
	void __fastcall SetStorage(Cxschedulerstorage::TcxCustomSchedulerStorage* AValue);
	
protected:
	__property bool IsDestroying = {read=FIsDestroying, nodefault};
	
public:
	__fastcall virtual ~TcxSchedulerStorageLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxSchedulerAggregateStorage* AggregateStorage = {read=GetAggregateStorage};
	__property TcxSchedulerStorageLinks* Links = {read=GetLinks};
	
__published:
	__property bool Default = {read=GetDefault, write=SetDefault, default=0};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=FStorage, write=SetStorage};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxSchedulerStorageLink(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerStorageLinks : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxSchedulerStorageLink* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	TcxSchedulerAggregateStorage* FAggregateStorage;
	TcxSchedulerStorageLink* FDefaultLink;
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetDefaultStorage(void);
	HIDESBASE TcxSchedulerStorageLink* __fastcall GetItem(int AIndex);
	void __fastcall SetDefaultLink(TcxSchedulerStorageLink* AValue);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxSchedulerStorageLink* AValue);
	
protected:
	virtual TcxSchedulerStorageLinkClass __fastcall GetItemLinkClass(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TcxSchedulerStorageLinks(TcxSchedulerAggregateStorage* AOwner);
	TcxSchedulerStorageLink* __fastcall AddStorageLink(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage);
	int __fastcall GetStorageLinkIndex(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage);
	void __fastcall PopulateHolidays(System::Classes::TList* AList);
	__property TcxSchedulerAggregateStorage* AggregateStorage = {read=FAggregateStorage};
	__property TcxSchedulerStorageLink* DefaultLink = {read=FDefaultLink, write=SetDefaultLink};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* DefaultStorage = {read=GetDefaultStorage};
	__property TcxSchedulerStorageLink* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Create */ inline __fastcall TcxSchedulerStorageLinks(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxSchedulerStorageLinks(void) { }
	
};


class DELPHICLASS TcxSchedulerAggregateStorageEvent;
class PASCALIMPLEMENTATION TcxSchedulerAggregateStorageEvent : public Cxschedulerstorage::TcxSchedulerEvent
{
	typedef Cxschedulerstorage::TcxSchedulerEvent inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* FSourceEvent;
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetSourceStorage(void);
	TcxSchedulerAggregateStorage* __fastcall GetStorage(void);
	void __fastcall SetSourceEvent(Cxschedulerstorage::TcxSchedulerEvent* AValue);
	
protected:
	virtual System::Variant __fastcall GetParentID(void);
	virtual System::Variant __fastcall GetValueByIndex(int AIndex);
	virtual System::Variant __fastcall GetValueDefault(Cxschedulerstorage::TcxCustomSchedulerStorageField* AField, const System::Variant &ADefValue);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxCustomSchedulerStorageField* AField, const System::Variant &AValue);
	
public:
	virtual void __fastcall DeleteExceptions(void);
	virtual void __fastcall EndEditing(void);
	virtual void __fastcall RemoveRecurrence(void);
	__property Cxschedulerstorage::TcxSchedulerEvent* SourceEvent = {read=FSourceEvent, write=SetSourceEvent};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* SourceStorage = {read=GetSourceStorage};
	__property TcxSchedulerAggregateStorage* Storage = {read=GetStorage};
public:
	/* TcxSchedulerEvent.Create */ inline __fastcall virtual TcxSchedulerAggregateStorageEvent(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, bool ADisableEditing)/* overload */ : Cxschedulerstorage::TcxSchedulerEvent(AStorage, ADisableEditing) { }
	/* TcxSchedulerEvent.Create */ inline __fastcall virtual TcxSchedulerAggregateStorageEvent(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage, void * ARecordHandle)/* overload */ : Cxschedulerstorage::TcxSchedulerEvent(AStorage, ARecordHandle) { }
	/* TcxSchedulerEvent.Destroy */ inline __fastcall virtual ~TcxSchedulerAggregateStorageEvent(void) { }
	
};


typedef void __fastcall (__closure *TcxSchedulerEventInsertingEvent)(TcxSchedulerAggregateStorage* Sender, Cxschedulerstorage::TcxSchedulerEvent* AEvent, Cxschedulerstorage::TcxCustomSchedulerStorage* &AStorage);

class PASCALIMPLEMENTATION TcxSchedulerAggregateStorage : public Cxschedulerstorage::TcxCustomSchedulerStorage
{
	typedef Cxschedulerstorage::TcxCustomSchedulerStorage inherited;
	
private:
	bool FIsPostEvent;
	TcxSchedulerStorageLinks* FLinks;
	TcxSchedulerEventInsertingEvent FOnEventInserting;
	bool __fastcall CanRefresh(void);
	Cxschedulerstorage::TcxSchedulerStorageFields* __fastcall GetCustomFields(void);
	void __fastcall SetCustomFields(Cxschedulerstorage::TcxSchedulerStorageFields* const AValue);
	
protected:
	virtual void __fastcall AddInternalField(Cxschedulerstorage::TcxCustomSchedulerStorageField* &AField, Cxdatastorage::TcxValueTypeClass AValueType, bool AIsUnique = true);
	virtual void __fastcall DoDeleteEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall DoEventInserting(Cxschedulerstorage::TcxSchedulerEvent* AEvent, /* out */ Cxschedulerstorage::TcxCustomSchedulerStorage* &AStorage);
	virtual bool __fastcall DoFilterEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall DoRefresh(void);
	virtual Cxschedulerstorage::TcxSchedulerEventClass __fastcall GetEventClass(void);
	TcxSchedulerAggregateStorageEvent* __fastcall GetEventBySource(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual TcxSchedulerAggregateStorageEvent* __fastcall InternalAddEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	bool __fastcall IsDesigning(void);
	bool __fastcall IsDestroining(void);
	virtual void __fastcall PopulateEventsFromStorage(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage);
	virtual void __fastcall PostEditingData(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall PostEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall RemoveStorageEvents(Cxschedulerstorage::TcxCustomSchedulerStorage* AStorage);
	virtual void __fastcall SendNotification(Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool AIsRemoved = false, bool ACheckLockCount = true);
	virtual void __fastcall BeginUpdateDataController(void);
	virtual void __fastcall EndUpdateDataController(void);
	void __fastcall AddEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall RemoveEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall StorageChanged(System::TObject* Sender);
	void __fastcall StorageRemoved(System::TObject* Sender);
	
public:
	__fastcall virtual TcxSchedulerAggregateStorage(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSchedulerAggregateStorage(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall Clear(void);
	virtual void __fastcall GenerateHolidayEvents(const System::Variant &AResourceID);
	virtual bool __fastcall GetHolidayNamesByDate(System::TDate ADate, System::UnicodeString &ANames, bool AOnlyVisible = true);
	virtual bool __fastcall IsActive(void);
	virtual void __fastcall PopulateHolidayDates(Cxschedulerutils::TcxSchedulerDateList* AList, System::TDate AStart, System::TDate AFinish, bool AOnlyVisible = true, bool AClearList = true);
	
__published:
	__property Cxschedulerstorage::TcxSchedulerStorageFields* CustomFields = {read=GetCustomFields, write=SetCustomFields};
	__property Reminders;
	__property Resources;
	__property TcxSchedulerStorageLinks* Links = {read=FLinks, write=FLinks};
	__property TcxSchedulerEventInsertingEvent OnEventInserting = {read=FOnEventInserting, write=FOnEventInserting};
	__property OnEventIntersect;
	__property OnFilterEvent;
private:
	void *__IcxSchedulerStorageListener2;	/* Cxschedulerstorage::IcxSchedulerStorageListener2 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4809FF3B-D9F8-4FD5-8647-33F8892599A4}
	operator Cxschedulerstorage::_di_IcxSchedulerStorageListener2()
	{
		Cxschedulerstorage::_di_IcxSchedulerStorageListener2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulerstorage::IcxSchedulerStorageListener2*(void) { return (Cxschedulerstorage::IcxSchedulerStorageListener2*)&__IcxSchedulerStorageListener2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {87E0EBF3-F68A-4A51-8EA3-850D3819FBAB}
	operator Cxschedulerstorage::_di_IcxSchedulerStorageListener()
	{
		Cxschedulerstorage::_di_IcxSchedulerStorageListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulerstorage::IcxSchedulerStorageListener*(void) { return (Cxschedulerstorage::IcxSchedulerStorageListener*)&__IcxSchedulerStorageListener2; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxscheduleraggregatestorage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERAGGREGATESTORAGE)
using namespace Cxscheduleraggregatestorage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxscheduleraggregatestorageHPP
