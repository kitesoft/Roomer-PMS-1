// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerDBStorage.pas' rev: 24.00 (Win64)

#ifndef CxschedulerdbstorageHPP
#define CxschedulerdbstorageHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxSchedulerHolidays.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerdbstorage
{
//-- type declarations -------------------------------------------------------
typedef System::UnicodeString TcxFieldName;

class DELPHICLASS TcxSchedulerDataLink;
class DELPHICLASS TcxSchedulerDBStorageDataController;
class DELPHICLASS TcxSchedulerDBStorage;
class PASCALIMPLEMENTATION TcxSchedulerDataLink : public Cxdbdata::TcxDBCustomDataLink
{
	typedef Cxdbdata::TcxDBCustomDataLink inherited;
	
private:
	TcxSchedulerDBStorageDataController* FDataController;
	bool FDataLocate;
	bool FIsRefresh;
	bool FModified;
	bool __fastcall GetDataBusy(void);
	TcxSchedulerDBStorage* __fastcall GetStorage(void);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual bool __fastcall GetIsDataSetBusyState(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
	virtual void __fastcall UpdateData(void);
	
public:
	__fastcall virtual TcxSchedulerDataLink(TcxSchedulerDBStorageDataController* ADataController);
	__property TcxSchedulerDBStorageDataController* DataController = {read=FDataController};
	__property bool DataBusy = {read=GetDataBusy, nodefault};
	__property bool DataLocate = {read=FDataLocate, write=FDataLocate, nodefault};
	__property bool Modified = {read=FModified, write=FModified, nodefault};
	__property bool IsRefresh = {read=FIsRefresh, write=FIsRefresh, nodefault};
	__property TcxSchedulerDBStorage* Storage = {read=GetStorage};
public:
	/* TcxDBCustomDataLink.Destroy */ inline __fastcall virtual ~TcxSchedulerDataLink(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerDBStorageDataController : public Cxschedulerstorage::TcxSchedulerStorageDataController
{
	typedef Cxschedulerstorage::TcxSchedulerStorageDataController inherited;
	
private:
	TcxSchedulerDataLink* FDataLink;
	Data::Db::TField* FKeyField;
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	HIDESBASE TcxSchedulerDBStorage* __fastcall GetStorage(void);
	
protected:
	System::TObject* FDataSetBookmark;
	virtual void __fastcall ComponentRemoved(System::Classes::TComponent* AComponent);
	virtual void __fastcall Initialize(void);
	void __fastcall InitializeField(Data::Db::TField* &AField, const System::UnicodeString AFieldName);
	void __fastcall RestorePos(void);
	void __fastcall SavePos(bool ASetTopPosition);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual bool __fastcall UpdateEvent(Cxschedulerstorage::TcxSchedulerEvent* const AEvent);
	void __fastcall UpdateEventValues(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	__property TcxSchedulerDataLink* DataLink = {read=FDataLink};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property TcxSchedulerDBStorage* Storage = {read=GetStorage};
	
public:
	__fastcall virtual TcxSchedulerDBStorageDataController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSchedulerDBStorageDataController(void);
	virtual System::TObject* __fastcall GetItem(int Index);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall UpdateItemIndexes(void);
	__property Data::Db::TField* KeyField = {read=FKeyField};
};


class DELPHICLASS TcxSchedulerDBFieldLink;
class PASCALIMPLEMENTATION TcxSchedulerDBFieldLink : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Data::Db::TField* Field;
	int RefCount;
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerDBFieldLink(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDBFieldLink(void) { }
	
};


class DELPHICLASS TcxSchedulerDBStorageField;
class PASCALIMPLEMENTATION TcxSchedulerDBStorageField : public Cxschedulerstorage::TcxCustomSchedulerStorageField
{
	typedef Cxschedulerstorage::TcxCustomSchedulerStorageField inherited;
	
private:
	TcxSchedulerDBFieldLink* FFieldLink;
	System::UnicodeString FFieldName;
	HIDESBASE TcxSchedulerDBStorageDataController* __fastcall GetDataController(void);
	Data::Db::TField* __fastcall GetField(void);
	HIDESBASE TcxSchedulerDBStorage* __fastcall GetStorage(void);
	void __fastcall SetFieldName(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall Initialize(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual bool __fastcall GetIsActive(void);
	virtual bool __fastcall GetIsBlob(void);
	virtual bool __fastcall GetIsTextStored(void);
	__property TcxSchedulerDBStorageDataController* DataController = {read=GetDataController};
	__property TcxSchedulerDBFieldLink* FieldLink = {read=FFieldLink};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Data::Db::TField* Field = {read=GetField};
	__property TcxSchedulerDBStorage* Storage = {read=GetStorage};
	
__published:
	__property System::UnicodeString FieldName = {read=FFieldName, write=SetFieldName};
public:
	/* TcxCustomSchedulerStorageField.Create */ inline __fastcall virtual TcxSchedulerDBStorageField(System::Classes::TCollection* Collection) : Cxschedulerstorage::TcxCustomSchedulerStorageField(Collection) { }
	/* TcxCustomSchedulerStorageField.Destroy */ inline __fastcall virtual ~TcxSchedulerDBStorageField(void) { }
	
};


class DELPHICLASS TcxSchedulerDBStorageFields;
class PASCALIMPLEMENTATION TcxSchedulerDBStorageFields : public Cxschedulerstorage::TcxCustomSchedulerStorageFields
{
	typedef Cxschedulerstorage::TcxCustomSchedulerStorageFields inherited;
	
private:
	HIDESBASE TcxSchedulerDBStorageField* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxSchedulerDBStorageField* const AValue);
	
protected:
	virtual Cxschedulerstorage::TcxCustomSchedulerStorageField* __fastcall FindFieldByName(const System::UnicodeString AName);
	
public:
	HIDESBASE TcxSchedulerDBStorageField* __fastcall Add(void);
	TcxSchedulerDBStorageField* __fastcall ItemByFieldName(const System::UnicodeString AFieldName);
	__property TcxSchedulerDBStorageField* Items[int Index] = {read=GetItem, write=SetItem};
public:
	/* TCollection.Create */ inline __fastcall TcxSchedulerDBStorageFields(System::Classes::TCollectionItemClass ItemClass) : Cxschedulerstorage::TcxCustomSchedulerStorageFields(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxSchedulerDBStorageFields(void) { }
	
};


class DELPHICLASS TcxSchedulerDBStorageFieldNames;
class PASCALIMPLEMENTATION TcxSchedulerDBStorageFieldNames : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxFieldName FID;
	TcxSchedulerDBStorage* FOwner;
	TcxSchedulerDBStorageDataController* __fastcall GetDataController(void);
	void __fastcall SetIDFieldName(const TcxFieldName AValue);
	
protected:
	TcxFieldName __fastcall GetFieldName(int AIndex);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall SetFieldName(int AIndex, const TcxFieldName AValue);
	__property TcxFieldName ReminderTime = {read=GetFieldName, write=SetFieldName, index=10};
	
public:
	__fastcall virtual TcxSchedulerDBStorageFieldNames(TcxSchedulerDBStorage* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxSchedulerDBStorage* Storage = {read=FOwner};
	__property TcxSchedulerDBStorageDataController* DataController = {read=GetDataController};
	
__published:
	__property TcxFieldName ActualFinish = {read=GetFieldName, write=SetFieldName, index=15};
	__property TcxFieldName ActualStart = {read=GetFieldName, write=SetFieldName, index=16};
	__property TcxFieldName Caption = {read=GetFieldName, write=SetFieldName, index=0};
	__property TcxFieldName GroupID = {read=GetFieldName, write=SetFieldName, index=22};
	__property TcxFieldName EventType = {read=GetFieldName, write=SetFieldName, index=1};
	__property TcxFieldName Finish = {read=GetFieldName, write=SetFieldName, index=2};
	__property TcxFieldName ID = {read=FID, write=SetIDFieldName};
	__property TcxFieldName LabelColor = {read=GetFieldName, write=SetFieldName, index=3};
	__property TcxFieldName Location = {read=GetFieldName, write=SetFieldName, index=4};
	__property TcxFieldName Message = {read=GetFieldName, write=SetFieldName, index=5};
	__property TcxFieldName Options = {read=GetFieldName, write=SetFieldName, index=6};
	__property TcxFieldName ParentID = {read=GetFieldName, write=SetFieldName, index=7};
	__property TcxFieldName RecurrenceIndex = {read=GetFieldName, write=SetFieldName, index=8};
	__property TcxFieldName RecurrenceInfo = {read=GetFieldName, write=SetFieldName, index=9};
	__property TcxFieldName ReminderDate = {read=GetFieldName, write=SetFieldName, index=10};
	__property TcxFieldName ReminderMinutesBeforeStart = {read=GetFieldName, write=SetFieldName, index=11};
	__property TcxFieldName ReminderResourcesData = {read=GetFieldName, write=SetFieldName, index=21};
	__property TcxFieldName ResourceID = {read=GetFieldName, write=SetFieldName, index=12};
	__property TcxFieldName Start = {read=GetFieldName, write=SetFieldName, index=13};
	__property TcxFieldName State = {read=GetFieldName, write=SetFieldName, index=14};
	__property TcxFieldName TaskCompleteField = {read=GetFieldName, write=SetFieldName, index=17};
	__property TcxFieldName TaskIndexField = {read=GetFieldName, write=SetFieldName, index=18};
	__property TcxFieldName TaskLinksField = {read=GetFieldName, write=SetFieldName, index=19};
	__property TcxFieldName TaskStatusField = {read=GetFieldName, write=SetFieldName, index=20};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerDBStorageFieldNames(void) { }
	
};


class DELPHICLASS TcxSchedulerDBStorageResourceDataController;
class PASCALIMPLEMENTATION TcxSchedulerDBStorageResourceDataController : public Cxdbdata::TcxDBDataController
{
	typedef Cxdbdata::TcxDBDataController inherited;
	
protected:
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	
public:
	virtual System::TObject* __fastcall GetItem(int AIndex);
public:
	/* TcxDBDataController.Create */ inline __fastcall virtual TcxSchedulerDBStorageResourceDataController(System::Classes::TComponent* AOwner) : Cxdbdata::TcxDBDataController(AOwner) { }
	/* TcxDBDataController.Destroy */ inline __fastcall virtual ~TcxSchedulerDBStorageResourceDataController(void) { }
	
};


class DELPHICLASS TcxSchedulerDBStorageResources;
class PASCALIMPLEMENTATION TcxSchedulerDBStorageResources : public Cxschedulerstorage::TcxSchedulerStorageResources
{
	typedef Cxschedulerstorage::TcxSchedulerStorageResources inherited;
	
private:
	TcxSchedulerDBStorageResourceDataController* FDataController;
	Cxschedulerstorage::TcxSchedulerStorageResourceItems* FDataItems;
	Cxdbdata::TcxDBDataField* FResourceColorField;
	TcxFieldName FResourceColorFieldName;
	Cxdbdata::TcxDBDataField* FResourceIDField;
	TcxFieldName FResourceIDFieldName;
	Cxdbdata::TcxDBDataField* FResourceImageIndexField;
	TcxFieldName FResourceImageIndexFieldName;
	Cxdbdata::TcxDBDataField* FResourceNameField;
	TcxFieldName FResourceNameFieldName;
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	void __fastcall SetDataSource(Data::Db::TDataSource* AValue);
	void __fastcall SetResourceColorFieldName(const TcxFieldName AValue);
	void __fastcall SetResourceIDFieldName(const TcxFieldName AValue);
	void __fastcall SetResourceImageIndexFieldName(const TcxFieldName AValue);
	void __fastcall SetResourceNameFieldName(const TcxFieldName AValue);
	
protected:
	virtual TcxSchedulerDBStorageResourceDataController* __fastcall CreateDataController(void);
	virtual Cxschedulerstorage::TcxSchedulerStorageResourceItems* __fastcall GetResourceItems(void);
	System::Variant __fastcall GetValueDef(int ARecordIndex, Cxdbdata::TcxDBDataField* AField, const System::Variant &DefValue);
	virtual void __fastcall InitDataItem(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AItem, int AIndex);
	void __fastcall SetInternalFieldName(TcxFieldName &AFieldName, const TcxFieldName AValue, Cxdbdata::TcxDBDataField* &AField);
	virtual void __fastcall UpdateResourceItems(void);
	__property TcxSchedulerDBStorageResourceDataController* DataController = {read=FDataController};
	__property Cxdbdata::TcxDBDataField* ResourceColorField = {read=FResourceColorField};
	__property Cxdbdata::TcxDBDataField* ResourceIDField = {read=FResourceIDField};
	__property Cxdbdata::TcxDBDataField* ResourceImageIndexField = {read=FResourceImageIndexField};
	__property Cxdbdata::TcxDBDataField* ResourceNameField = {read=FResourceNameField};
	
public:
	__fastcall virtual TcxSchedulerDBStorageResources(Cxschedulerstorage::TcxCustomSchedulerStorage* AOwner);
	__fastcall virtual ~TcxSchedulerDBStorageResources(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItems* DataItems = {read=FDataItems};
	
__published:
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property TcxFieldName ResourceColor = {read=FResourceColorFieldName, write=SetResourceColorFieldName};
	__property TcxFieldName ResourceID = {read=FResourceIDFieldName, write=SetResourceIDFieldName};
	__property TcxFieldName ResourceImageIndex = {read=FResourceImageIndexFieldName, write=SetResourceImageIndexFieldName};
	__property TcxFieldName ResourceName = {read=FResourceNameFieldName, write=SetResourceNameFieldName};
	__property Images;
	__property Items;
	__property OnGetResourceImageIndex;
	__property OnGetResourceName;
};


typedef void __fastcall (__closure *TcxSchedulerGetEventGeneratedIDEvent)(TcxSchedulerDBStorage* Sender, Cxschedulerstorage::TcxSchedulerEvent* AEvent, System::Variant &EventID);

class PASCALIMPLEMENTATION TcxSchedulerDBStorage : public Cxschedulerstorage::TcxCustomSchedulerStorage
{
	typedef Cxschedulerstorage::TcxCustomSchedulerStorage inherited;
	
private:
	bool FDataBusy;
	TcxSchedulerDBStorageFieldNames* FFieldNames;
	Cxclasses::TcxObjectList* FFieldLinks;
	bool FGenerateGUIDForID;
	bool FSmartRefresh;
	Cxschedulerstorage::TcxSchedulerEvent* FUpdatingEvent;
	bool FUseIndexedID;
	TcxSchedulerGetEventGeneratedIDEvent FOnGetEventGeneratedID;
	TcxSchedulerDBStorageDataController* __fastcall GetDataController(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	TcxSchedulerDBStorageFields* __fastcall GetCustomFields(void);
	TcxSchedulerDBStorageResources* __fastcall GetResources(void);
	void __fastcall SetDataSource(Data::Db::TDataSource* AValue);
	void __fastcall SetCustomFields(TcxSchedulerDBStorageFields* const AValue);
	void __fastcall SetFieldNames(TcxSchedulerDBStorageFieldNames* AValue);
	HIDESBASE void __fastcall SetResources(TcxSchedulerDBStorageResources* AValue);
	void __fastcall SetSmartRefresh(bool AValue);
	void __fastcall SetUseIndexedID(bool AValue);
	
protected:
	virtual bool __fastcall AddEventRecord(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall AfterPostEditingData(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall BeforeDeleteEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall BeforePostEditingData(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual Cxschedulerstorage::TcxSchedulerEvent* __fastcall CreateEventInternal(void);
	virtual TcxSchedulerDBStorageFieldNames* __fastcall CreateFieldNames(void);
	virtual Cxschedulerstorage::TcxCustomSchedulerStorageFields* __fastcall CreateFields(void);
	virtual Cxschedulerstorage::TcxSchedulerStorageResources* __fastcall CreateResources(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DeleteEvents(Cxclasses::TcxObjectList* AEvents);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DoDestroyEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual System::Variant __fastcall DoGetEventGeneratedID(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AEventID);
	TcxSchedulerDBFieldLink* __fastcall GetFieldLink(Data::Db::TField* AField);
	TcxSchedulerDBFieldLink* __fastcall GetFieldLinkByIndex(int AFieldIndex);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual bool __fastcall GetIsBoundMode(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetFieldValueTypeClass(Cxschedulerstorage::TcxCustomSchedulerStorageField* AField);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	bool __fastcall MakeFocused(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall RelateFields(TcxSchedulerDBStorageField* AStorageField, Data::Db::TField* AField);
	void __fastcall RemoveDeletedEvents(System::Classes::TList* AList);
	virtual void __fastcall SetValue(const void * ARecordHandle, const int AFieldIndex, const System::Variant &AValue);
	virtual void __fastcall SetValueBeforePost(Cxschedulerstorage::TcxSchedulerEvent* AEvent, int AItemIndex);
	virtual void __fastcall SynchronizeEventsWithRecords(void);
	virtual void __fastcall SynchronizeIndexedEvents(void);
	virtual void __fastcall SynchronizeNoIndexedEvents(void);
	void __fastcall UpdateEventFieldValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, Data::Db::TField* AField);
	virtual void __fastcall BeginUpdateDataController(void);
	virtual void __fastcall EndUpdateDataController(void);
	__property TcxSchedulerDBStorageDataController* DataController = {read=GetDataController};
	__property bool DataBusy = {read=FDataBusy, write=FDataBusy, nodefault};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property Cxclasses::TcxObjectList* FieldLinks = {read=FFieldLinks};
	__property Cxschedulerstorage::TcxSchedulerEvent* UpdatingEvent = {read=FUpdatingEvent, write=FUpdatingEvent};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CheckRequiredFields(void);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall IsActive(void);
	virtual void __fastcall PostEvents(void);
	
__published:
	__property bool GenerateGUIDForID = {read=FGenerateGUIDForID, write=FGenerateGUIDForID, default=0};
	__property Reminders;
	__property TcxSchedulerDBStorageResources* Resources = {read=GetResources, write=SetResources};
	__property bool SmartRefresh = {read=FSmartRefresh, write=SetSmartRefresh, default=0};
	__property TcxSchedulerDBStorageFields* CustomFields = {read=GetCustomFields, write=SetCustomFields};
	__property Holidays;
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property TcxSchedulerDBStorageFieldNames* FieldNames = {read=FFieldNames, write=SetFieldNames};
	__property bool UseIndexedID = {read=FUseIndexedID, write=SetUseIndexedID, default=0};
	__property OnEventDeleted;
	__property OnEventInserted;
	__property OnEventIntersect;
	__property OnEventModified;
	__property OnFilterEvent;
	__property TcxSchedulerGetEventGeneratedIDEvent OnGetEventGeneratedID = {read=FOnGetEventGeneratedID, write=FOnGetEventGeneratedID};
public:
	/* TcxCustomSchedulerStorage.Create */ inline __fastcall virtual TcxSchedulerDBStorage(System::Classes::TComponent* AOwner) : Cxschedulerstorage::TcxCustomSchedulerStorage(AOwner) { }
	/* TcxCustomSchedulerStorage.Destroy */ inline __fastcall virtual ~TcxSchedulerDBStorage(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulerdbstorage */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERDBSTORAGE)
using namespace Cxschedulerdbstorage;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerdbstorageHPP
