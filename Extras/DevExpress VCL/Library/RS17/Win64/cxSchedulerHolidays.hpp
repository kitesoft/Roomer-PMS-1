// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerHolidays.pas' rev: 24.00 (Win64)

#ifndef CxschedulerholidaysHPP
#define CxschedulerholidaysHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerholidays
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerHolidaysLocationHoliday;
class DELPHICLASS TcxSchedulerHolidaysLocation;
class PASCALIMPLEMENTATION TcxSchedulerHolidaysLocationHoliday : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
private:
	System::TDateTime FDate;
	System::UnicodeString FName;
	bool FVisible;
	bool __fastcall GetIsVisible(void);
	TcxSchedulerHolidaysLocation* __fastcall GetLocation(void);
	void __fastcall SetDate(const System::TDateTime AValue);
	void __fastcall SetName(const System::UnicodeString AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(void);
	bool __fastcall IsDateHoliday(const System::TDate ADate, bool AOnlyVisible);
	bool __fastcall IsEqual(TcxSchedulerHolidaysLocationHoliday* AHoliday);
	bool __fastcall IsHolidayInRange(const System::TDate AStart, const System::TDate AFinish, bool AOnlyVisible);
	HIDESBASE virtual System::UnicodeString __fastcall ToString(void);
	virtual System::UnicodeString __fastcall GetStoredObjectName(void);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	
public:
	__fastcall virtual TcxSchedulerHolidaysLocationHoliday(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::UnicodeString DisplayText = {read=GetDisplayText};
	__property bool IsVisible = {read=GetIsVisible, nodefault};
	__property TcxSchedulerHolidaysLocation* Location = {read=GetLocation};
	
__published:
	__property System::TDateTime Date = {read=FDate, write=SetDate};
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxSchedulerHolidaysLocationHoliday(void) { }
	
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


typedef System::TMetaClass* TcxSchedulerHolidaysLocationHolidayClass;

class DELPHICLASS TcxSchedulerHolidaysLocations;
class PASCALIMPLEMENTATION TcxSchedulerHolidaysLocation : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
public:
	TcxSchedulerHolidaysLocationHoliday* operator[](int AIndex) { return Holidays[AIndex]; }
	
private:
	System::Classes::TCollection* FHolidays;
	System::UnicodeString FName;
	bool FVisible;
	int __fastcall GetCount(void);
	TcxSchedulerHolidaysLocationHoliday* __fastcall GetHoliday(int AIndex);
	TcxSchedulerHolidaysLocations* __fastcall GetLocations(void);
	void __fastcall SetHoliday(int AIndex, TcxSchedulerHolidaysLocationHoliday* AValue);
	void __fastcall SetName(const System::UnicodeString AValue);
	void __fastcall SetVisible(bool AValue);
	virtual void __fastcall ReadData(System::Classes::TReader* AReader);
	virtual void __fastcall WriteData(System::Classes::TWriter* AWriter);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	bool __fastcall IsEqual(TcxSchedulerHolidaysLocation* ALocation);
	HIDESBASE virtual System::UnicodeString __fastcall ToString(void);
	System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual System::UnicodeString __fastcall GetStoredObjectName(void);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property System::Classes::TCollection* HolidaysList = {read=FHolidays};
	
public:
	__fastcall virtual TcxSchedulerHolidaysLocation(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxSchedulerHolidaysLocation(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual TcxSchedulerHolidaysLocationHoliday* __fastcall AddHoliday(const System::UnicodeString AName, const System::TDateTime ADate)/* overload */;
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	bool __fastcall PopulateHolidayDates(const System::UnicodeString AName, Cxschedulerutils::TcxSchedulerDateList* &AList);
	virtual TcxSchedulerHolidaysLocationHoliday* __fastcall Find(const System::UnicodeString AName, const System::TDateTime ADate)/* overload */;
	void __fastcall Sort(Dxcore::TdxSortOrder ASortOrder, bool ASortByDate);
	__property int Count = {read=GetCount, nodefault};
	__property TcxSchedulerHolidaysLocationHoliday* Holidays[int AIndex] = {read=GetHoliday, write=SetHoliday/*, default*/};
	__property TcxSchedulerHolidaysLocations* Locations = {read=GetLocations};
	
__published:
	__property System::UnicodeString Name = {read=FName, write=SetName};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6AF48CD0-3A0B-4BEC-AC88-5D323432A686}
	operator Cxstorage::_di_IcxStoredParent()
	{
		Cxstorage::_di_IcxStoredParent intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredParent*(void) { return (Cxstorage::IcxStoredParent*)&__IcxStoredParent; }
	#endif
	
};


typedef System::TMetaClass* TcxSchedulerHolidaysLocationClass;

class DELPHICLASS TcxSchedulerHolidays;
class PASCALIMPLEMENTATION TcxSchedulerHolidaysLocations : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxSchedulerHolidaysLocation* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	TcxSchedulerHolidays* FOwner;
	HIDESBASE TcxSchedulerHolidaysLocation* __fastcall GetItem(int AIndex);
	TcxSchedulerHolidays* __fastcall GetOwnerHolidays(void);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxSchedulerHolidaysLocation* AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TcxSchedulerHolidaysLocations(TcxSchedulerHolidays* AOwner)/* overload */;
	__fastcall virtual ~TcxSchedulerHolidaysLocations(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HIDESBASE TcxSchedulerHolidaysLocation* __fastcall Add(const System::UnicodeString AName);
	TcxSchedulerHolidaysLocation* __fastcall GetLocationByName(const System::UnicodeString AName);
	void __fastcall Sort(Dxcore::TdxSortOrder ASortOrder);
	__property TcxSchedulerHolidaysLocation* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxSchedulerHolidays* OwnerHolidays = {read=GetOwnerHolidays};
};


__interface IcxSchedulerHolidaysListener;
typedef System::DelphiInterface<IcxSchedulerHolidaysListener> _di_IcxSchedulerHolidaysListener;
__interface  INTERFACE_UUID("{0FE58B1C-71C0-4ED0-9A10-12074CE13EA3}") IcxSchedulerHolidaysListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall HolidaysChanged(System::TObject* Sender) = 0 ;
	virtual void __fastcall HolidaysRemoved(System::TObject* Sender) = 0 ;
};

typedef void __fastcall (__closure *TcxSchedulerHolidaysImportExportHolidayEvent)(TcxSchedulerHolidays* ASender, TcxSchedulerHolidaysLocationHoliday* AHoliday, bool &Accept);

typedef void __fastcall (__closure *TcxSchedulerHolidaysImportUnknownDateEvent)(TcxSchedulerHolidays* ASender, System::Word &AYear, System::Word &AMonth, System::Word &ADay, const System::Word ATypeCalendar, bool &Accept);

class PASCALIMPLEMENTATION TcxSchedulerHolidays : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
public:
	TcxSchedulerHolidaysLocationHoliday* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	TcxSchedulerHolidaysLocations* FLocations;
	int FLockCount;
	System::Classes::TInterfaceList* FListeners;
	System::UnicodeString FStoringName;
	TcxSchedulerHolidaysImportExportHolidayEvent FOnExportHoliday;
	TcxSchedulerHolidaysImportExportHolidayEvent FOnImportHoliday;
	TcxSchedulerHolidaysImportUnknownDateEvent FOnImportUnknownDate;
	int __fastcall GetCount(void);
	TcxSchedulerHolidaysLocationHoliday* __fastcall GetItem(int AIndex);
	bool __fastcall GetIsDestroying(void);
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIsUpdatingMode(void);
	void __fastcall GetHolidaysIndex(int AIndex, /* out */ int &ALocationIndex, /* out */ int &AHolidayIndex);
	System::UnicodeString __fastcall GetStringPart(const System::UnicodeString S, int &APos, bool ACheckDateSeparator = true);
	void __fastcall SetLocations(TcxSchedulerHolidaysLocations* const AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual bool __fastcall CheckStreamFormat(System::Classes::TStream* AStream);
	virtual bool __fastcall DoExportHoliday(TcxSchedulerHolidaysLocationHoliday* AHoliday);
	virtual bool __fastcall DoImportHoliday(TcxSchedulerHolidaysLocationHoliday* AHoliday);
	virtual bool __fastcall DoImportUnknownDate(System::Word &AYear, System::Word &AMonth, System::Word &ADay, const System::Word ATypeCalendar);
	virtual void __fastcall SendNotification(bool AIsRemoved = false);
	virtual bool __fastcall TryCreateFromStream(System::Classes::TStream* AStream, /* out */ TcxSchedulerHolidaysLocations* &ALocations);
	bool __fastcall TryStringToHoliday(const System::UnicodeString S, TcxSchedulerHolidaysLocation* ALocation);
	bool __fastcall TryStringToLocation(const System::UnicodeString S, TcxSchedulerHolidaysLocations* ALocations);
	bool __fastcall TryStrToIntW(const System::UnicodeString S, /* out */ System::Word &AValue);
	virtual void __fastcall RestoreFrom(const System::UnicodeString AStorageName, System::Classes::TStream* AStream, Cxstorage::TcxCustomReaderClass AReaderClass, const System::UnicodeString ARestoreName);
	virtual void __fastcall StoreTo(const System::UnicodeString AStorageName, System::Classes::TStream* AStream, Cxstorage::TcxCustomWriterClass AWriterClass, const System::UnicodeString ASaveName);
	bool __fastcall IsStoringNameMode(void);
	System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual System::UnicodeString __fastcall GetStoredObjectName(void);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsUpdatingMode = {read=GetIsUpdatingMode, nodefault};
	__property System::Classes::TInterfaceList* Listeners = {read=FListeners};
	__property int LockCount = {read=FLockCount, write=FLockCount, nodefault};
	
public:
	__fastcall virtual TcxSchedulerHolidays(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSchedulerHolidays(void);
	TcxSchedulerHolidaysLocationHoliday* __fastcall AddHoliday(const System::UnicodeString ALocationName, const System::UnicodeString AHolidayName, const System::TDateTime ADate);
	void __fastcall AddListener(_di_IcxSchedulerHolidaysListener AListener);
	virtual TcxSchedulerHolidaysLocation* __fastcall AddLocation(const System::UnicodeString AName)/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall Clear(void);
	void __fastcall EndUpdate(void);
	virtual bool __fastcall GetHolidayNamesByDate(const System::TDate ADate, System::UnicodeString &ANames, bool AOnlyVisible = true);
	virtual void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall PopulateHolidayDates(Cxschedulerutils::TcxSchedulerDateList* AList, const System::TDate AStart, const System::TDate AFinish, bool AOnlyVisible = true, bool AClearList = true);
	void __fastcall RemoveListener(_di_IcxSchedulerHolidaysListener AListener);
	virtual void __fastcall SaveToFile(const System::UnicodeString AFileName);
	virtual void __fastcall SaveToStream(System::Classes::TStream* &AStream);
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall RestoreFromStream(System::Classes::TStream* AStream, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall RestoreFromStorage(const System::UnicodeString AStorageName, Cxstorage::TcxCustomReaderClass AReaderClass, const System::UnicodeString ARestoreName = System::UnicodeString());
	void __fastcall StoreToIniFile(const System::UnicodeString AStorageName, const System::UnicodeString ASaveName = System::UnicodeString());
	void __fastcall StoreToRegistry(const System::UnicodeString AStorageName, const System::UnicodeString ASaveName = System::UnicodeString());
	void __fastcall StoreToStream(System::Classes::TStream* AStream, const System::UnicodeString ASaveName = System::UnicodeString());
	void __fastcall StoreToStorage(const System::UnicodeString AStorageName, Cxstorage::TcxCustomWriterClass AWriterClass, const System::UnicodeString ASaveName = System::UnicodeString());
	__property int Count = {read=GetCount, nodefault};
	__property TcxSchedulerHolidaysLocationHoliday* Items[int AIndex] = {read=GetItem/*, default*/};
	
__published:
	__property TcxSchedulerHolidaysLocations* Locations = {read=FLocations, write=SetLocations};
	__property TcxSchedulerHolidaysImportExportHolidayEvent OnExportHoliday = {read=FOnExportHoliday, write=FOnExportHoliday};
	__property TcxSchedulerHolidaysImportExportHolidayEvent OnImportHoliday = {read=FOnImportHoliday, write=FOnImportHoliday};
	__property TcxSchedulerHolidaysImportUnknownDateEvent OnImportUnknownDate = {read=FOnImportUnknownDate, write=FOnImportUnknownDate};
private:
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6AF48CD0-3A0B-4BEC-AC88-5D323432A686}
	operator Cxstorage::_di_IcxStoredParent()
	{
		Cxstorage::_di_IcxStoredParent intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredParent*(void) { return (Cxstorage::IcxStoredParent*)&__IcxStoredParent; }
	#endif
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


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulerholidays */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERHOLIDAYS)
using namespace Cxschedulerholidays;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerholidaysHPP
