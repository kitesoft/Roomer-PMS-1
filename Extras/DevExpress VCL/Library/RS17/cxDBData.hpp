// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBData.pas' rev: 24.00 (Win32)

#ifndef CxdbdataHPP
#define CxdbdataHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDBFilter.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbdata
{
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<System::Byte> TcxBookmark;

typedef void __fastcall (__closure *TGetListProc)(System::Classes::TList* AList);

class DELPHICLASS TcxDBProviderDetailFilterAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBProviderDetailFilterAdapter : public Cxdb::TcxDBAdapterItem
{
	typedef Cxdb::TcxDBAdapterItem inherited;
	
public:
	virtual bool __fastcall IsCurrentQuery(Data::Db::TDataSet* ADataSet, const System::UnicodeString AParamNames, const System::Variant &AParamValues);
	virtual void __fastcall ReopenSQL(Data::Db::TDataSet* ADataSet, const System::UnicodeString AParamNames, const System::Variant &AParamValues, bool &AReopened);
	virtual void __fastcall SetFilter(Data::Db::TDataSet* ADataSet, const System::UnicodeString AMasterDetailKeyFieldNames, const System::Variant &AMasterDetailKeyValues, bool AIsSQLMode, bool &AReopened);
public:
	/* TcxDBAdapterItem.Create */ inline __fastcall virtual TcxDBProviderDetailFilterAdapter(Cxdb::TDataSetClass ADataSetClass) : Cxdb::TcxDBAdapterItem(ADataSetClass) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDBProviderDetailFilterAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBCustomDataLink;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBCustomDataLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	bool __fastcall GetIsDataSetBusy(void);
	
protected:
	virtual bool __fastcall GetIsDataSetBusyState(void);
	__property bool IsDataSetBusy = {read=GetIsDataSetBusy, nodefault};
	
public:
	__fastcall TcxDBCustomDataLink(void);
	__fastcall virtual ~TcxDBCustomDataLink(void);
};

#pragma pack(pop)

class DELPHICLASS TcxDBDataLink;
class DELPHICLASS TcxDBDataProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBDataLink : public TcxDBCustomDataLink
{
	typedef TcxDBCustomDataLink inherited;
	
private:
	bool FLayoutChangedFlag;
	bool FPreventLayoutChanged;
	TcxDBDataProvider* FProvider;
	void __fastcall DoInsertingRecord(void);
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataEvent(Data::Db::TDataEvent Event, NativeInt Info);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall FocusControl(Data::Db::TFieldRef Field);
	virtual bool __fastcall GetIsDataSetBusyState(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
	virtual void __fastcall UpdateData(void);
	__property TcxDBDataProvider* Provider = {read=FProvider};
	
public:
	__fastcall TcxDBDataLink(TcxDBDataProvider* AProvider);
public:
	/* TcxDBCustomDataLink.Destroy */ inline __fastcall virtual ~TcxDBDataLink(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxDBDataProviderSavePosInfo
{
public:
	System::DynamicArray<System::Byte> Bookmark;
	// System::TArray__1<System::Byte>  Bookmark;
	bool Bof;
	bool Eof;
	int ActiveRecord;
};


class DELPHICLASS TcxDBDataAssignedFields;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBDataAssignedFields : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Generics::Collections::TList__1<Data::Db::TField*>* FFields;
	
public:
	__fastcall TcxDBDataAssignedFields(void);
	__fastcall virtual ~TcxDBDataAssignedFields(void);
	void __fastcall AddField(Data::Db::TField* AField);
	void __fastcall AddFieldsByFieldList(System::Classes::TList* AFieldList);
	void __fastcall AddFieldsByFieldNames(Data::Db::TDataSet* ADataSet, const System::UnicodeString AFieldNames);
	void __fastcall Clear(void);
	bool __fastcall IsEmpty(void);
	bool __fastcall IsFieldExists(Data::Db::TField* AField);
};

#pragma pack(pop)

class DELPHICLASS TcxDBDataController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBDataProvider : public Cxcustomdata::TcxCustomDataProvider
{
	typedef Cxcustomdata::TcxCustomDataProvider inherited;
	
private:
	TcxDBDataAssignedFields* FAssignedFields;
	TcxDBDataLink* FDataLink;
	bool FInCanInitEditing;
	bool FInSetDataSource;
	bool FIncrementalSearching;
	bool FInFirst;
	bool FInInsert;
	bool FInsertOperation;
	bool FInUpdateGridMode;
	bool FIsDataSetCurrent;
	bool FInNotify;
	System::Classes::TList* FListeners;
	bool FPostLocateFlag;
	int FRecordIndex;
	TcxDBDataProviderSavePosInfo FSavePosInfo;
	int FUpdatingPrevFocusedRecordIndex;
	int FUpdatingRecordIndex;
	bool FUpdatingRecordIsInserting;
	int FUpdatingNewRecordIndex;
	void __fastcall AddNewRecord(Data::Db::TDataOperation AOperation);
	TcxDBDataController* __fastcall GetDataController(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	bool __fastcall GetIsDataSetCurrent(void);
	bool __fastcall GetIsSmartRefresh(void);
	void __fastcall RemoveFromListeners(void);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetIsDataSetCurrent(bool Value);
	
protected:
	virtual bool __fastcall IsCustomDataSourceSupported(void);
	virtual bool __fastcall IsGridMode(void);
	virtual bool __fastcall IsDataSource(void);
	bool __fastcall IsKeyNavigation(void);
	virtual bool __fastcall IsOtherInsert(void);
	bool __fastcall IsSyncInsert(void);
	virtual bool __fastcall IsSyncMode(void);
	int __fastcall DataSet_ActiveRecord(void);
	bool __fastcall DataSet_BookmarkAvailable(void);
	int __fastcall DataSet_BufferCount(void);
	virtual bool __fastcall IsActive(void);
	virtual bool __fastcall IsActiveDataSet(void);
	virtual bool __fastcall IsBOF(void);
	virtual bool __fastcall IsChanging(void);
	virtual bool __fastcall IsEditing(void);
	virtual bool __fastcall IsEOF(void);
	virtual bool __fastcall IsGridModeUpdating(void);
	virtual bool __fastcall IsInserting(void);
	virtual bool __fastcall IsModified(void);
	virtual bool __fastcall IsDataSetModified(void);
	virtual bool __fastcall BookmarkValid(const System::DynamicArray<System::Byte> ABookmark);
	virtual int __fastcall CompareBookmarks(const System::DynamicArray<System::Byte> AItem1, const System::DynamicArray<System::Byte> AItem2);
	virtual void __fastcall CorrectRecordIndex(int ARecordIndex);
	virtual void __fastcall First(void);
	virtual void __fastcall Prev(void);
	virtual void __fastcall Next(void);
	virtual void __fastcall Last(void);
	virtual void __fastcall MoveBy(int ADistance);
	virtual void __fastcall Scroll(int ADistance);
	virtual void __fastcall SavePos(void);
	virtual void __fastcall RestorePos(void);
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanInitEditing(int ARecordIndex);
	virtual bool __fastcall CanModify(void);
	virtual void __fastcall Append(void);
	virtual void __fastcall InternalCancel(void);
	virtual void __fastcall Cancel(void);
	virtual void __fastcall Delete(void);
	virtual void __fastcall DeleteRecords(System::Classes::TList* AList);
	virtual void __fastcall DeleteSelection(void);
	virtual void __fastcall Edit(void);
	virtual System::Variant __fastcall GetEditValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall Insert(void);
	virtual void __fastcall Post(bool AForcePost = false);
	virtual void __fastcall PostEditingData(void);
	virtual bool __fastcall SetEditValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField, const System::Variant &AValue, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall BeginDeleting(void);
	virtual void __fastcall EndDeleting(void);
	virtual void __fastcall AssignItemValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField, const System::Variant &AValue);
	virtual void __fastcall DoInitInsertingRecord(int AInsertingRecordIndex, const Cxcustomdata::TcxDataSummaryValues AGroupValues);
	virtual void __fastcall ActiveChanged(bool AActive);
	void __fastcall AddListener(TcxDBDataProvider* AProvider);
	virtual void __fastcall BeginLocate(void);
	virtual void __fastcall DataScrolled(int ADistance);
	virtual void __fastcall Freeze(void);
	virtual void __fastcall LayoutChanged(Cxcustomdata::TcxDataLayoutChanges ADataLayoutChanges);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
	void __fastcall ResetPostLocateFlag(void);
	void __fastcall ResetSmartRefresh(void);
	void __fastcall SetPostLocateFlag(void);
	virtual void __fastcall Unfreeze(void);
	void __fastcall SmartDataChanged(void);
	void __fastcall CheckExpandedDetails(void);
	bool __fastcall DoLocate(const System::UnicodeString ASubText, bool AForward, bool ANext);
	int __fastcall GetDataBufferCount(void);
	int __fastcall GetDataRecordCount(void);
	virtual System::UnicodeString __fastcall GetExternalDataDisplayText(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetExternalDataValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField);
	virtual void __fastcall LoadDataBuffer(void);
	void __fastcall UpdateGridMode(void);
	virtual bool __fastcall GetDetailHasChildren(int ARecordIndex, int ARelationIndex);
	virtual int __fastcall GetRecordIndex(void);
	virtual Cxdatastorage::TcxValueDefReaderClass __fastcall GetValueDefReaderClass(void);
	__property TcxDBDataController* DataController = {read=GetDataController};
	__property TcxDBDataLink* DataLink = {read=FDataLink};
	__property int UpdatingRecordIndex = {read=FUpdatingRecordIndex, nodefault};
	
public:
	__fastcall virtual TcxDBDataProvider(Cxcustomdata::TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDBDataProvider(void);
	bool __fastcall IsCanInitEditingBusy(void);
	bool __fastcall IsDataSetBusy(void);
	bool __fastcall IsDetailDataSetBusy(void);
	bool __fastcall IsOtherDataControllerUpdating(void);
	bool __fastcall IsOtherDetailDataSetInInsert(void);
	bool __fastcall IsOtherDetailChanged(void);
	bool __fastcall IsUniDirectional(void);
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property bool IsDataSetCurrent = {read=GetIsDataSetCurrent, write=SetIsDataSetCurrent, nodefault};
	__property bool IsSmartRefresh = {read=GetIsSmartRefresh, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxValueDefDBReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueDefDBReader : public Cxdatastorage::TcxValueDefReader
{
	typedef Cxdatastorage::TcxValueDefReader inherited;
	
public:
	virtual System::UnicodeString __fastcall GetDisplayText(Cxdatastorage::TcxValueDef* AValueDef);
	virtual System::Variant __fastcall GetValue(Cxdatastorage::TcxValueDef* AValueDef);
	virtual bool __fastcall IsInternal(Cxdatastorage::TcxValueDef* AValueDef);
public:
	/* TcxValueDefReader.Create */ inline __fastcall virtual TcxValueDefDBReader(void) : Cxdatastorage::TcxValueDefReader() { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxValueDefDBReader(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBDataField;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBDataField : public Cxcustomdata::TcxCustomDataField
{
	typedef Cxcustomdata::TcxCustomDataField inherited;
	
public:
	TcxDBDataField* operator[](int Index) { return Fields[Index]; }
	
private:
	Data::Db::TField* FField;
	System::UnicodeString FFieldName;
	System::Classes::TList* FFields;
	bool FIsCurrency;
	TcxDBDataField* FParentField;
	HIDESBASE TcxDBDataController* __fastcall GetDataController(void);
	Data::Db::TField* __fastcall GetField(void);
	TcxDBDataField* __fastcall GetFieldItem(int Index);
	int __fastcall GetFieldCount(void);
	bool __fastcall GetIsLookup(void);
	TcxDBDataProvider* __fastcall GetProvider(void);
	void __fastcall SetField(Data::Db::TField* Value);
	
protected:
	void __fastcall AddField(TcxDBDataField* ADataField);
	void __fastcall ClearFields(void);
	void __fastcall DoPropertiesChanged(void);
	virtual void __fastcall Reassign(Cxcustomdata::TcxCustomDataField* ASource);
	void __fastcall RemoveField(TcxDBDataField* ADataField);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	void __fastcall SetPropertiesByField(Data::Db::TField* AField, bool AFieldChanged);
	__property TcxDBDataController* DataController = {read=GetDataController};
	__property Data::Db::TField* Field = {read=GetField, write=SetField};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property System::UnicodeString FieldName = {read=FFieldName, write=FFieldName};
	__property TcxDBDataField* Fields[int Index] = {read=GetFieldItem/*, default*/};
	__property bool IsCurrency = {read=FIsCurrency, nodefault};
	__property bool IsLookup = {read=GetIsLookup, nodefault};
	__property TcxDBDataField* ParentField = {read=FParentField};
	__property TcxDBDataProvider* Provider = {read=GetProvider};
	
public:
	__fastcall virtual ~TcxDBDataField(void);
	virtual bool __fastcall CanModify(Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual bool __fastcall IsUnbound(void);
	virtual bool __fastcall IsValueDefInternal(void);
public:
	/* TcxCustomDataField.Create */ inline __fastcall virtual TcxDBDataField(Cxcustomdata::TcxCustomDataFieldList* AFieldList) : Cxcustomdata::TcxCustomDataField(AFieldList) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBDataRelation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBDataRelation : public Cxcustomdata::TcxCustomDataRelation
{
	typedef Cxcustomdata::TcxCustomDataRelation inherited;
	
private:
	TcxDBDataField* FMasterKeyField;
	HIDESBASE TcxDBDataController* __fastcall GetDataController(void);
	System::UnicodeString __fastcall GetDetailKeyFieldNames(void);
	System::UnicodeString __fastcall GetMasterKeyFieldNames(void);
	
protected:
	void __fastcall GetMasterKeyFields(System::Classes::TList* AList);
	virtual bool __fastcall IsLinked(void);
	virtual void __fastcall RemoveDataField(Cxcustomdata::TcxCustomDataField* ADataField);
	void __fastcall RemoveMasterKeyField(void);
	void __fastcall UpdateMasterDetailKeyFieldNames(void);
	
public:
	__fastcall virtual ~TcxDBDataRelation(void);
	System::Variant __fastcall GetMasterRecordID(int ARecordIndex);
	__property TcxDBDataController* DataController = {read=GetDataController};
	__property System::UnicodeString DetailKeyFieldNames = {read=GetDetailKeyFieldNames};
	__property System::UnicodeString MasterKeyFieldNames = {read=GetMasterKeyFieldNames};
public:
	/* TcxCustomDataRelation.Create */ inline __fastcall virtual TcxDBDataRelation(Cxcustomdata::TcxCustomDataRelationList* ARelationList, System::TObject* AItem) : Cxcustomdata::TcxCustomDataRelation(ARelationList, AItem) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBDataFilterCriteriaItem;
class PASCALIMPLEMENTATION TcxDBDataFilterCriteriaItem : public Cxcustomdata::TcxDataFilterCriteriaItem
{
	typedef Cxcustomdata::TcxDataFilterCriteriaItem inherited;
	
private:
	HIDESBASE TcxDBDataController* __fastcall GetDataController(void);
	TcxDBDataField* __fastcall GetDBField(void);
	
protected:
	virtual Cxfilter::TcxFilterOperatorClass __fastcall GetFilterOperatorClass(void);
	
public:
	__property TcxDBDataController* DataController = {read=GetDataController};
	__property TcxDBDataField* DBField = {read=GetDBField};
public:
	/* TcxFilterCriteriaItem.Create */ inline __fastcall virtual TcxDBDataFilterCriteriaItem(Cxfilter::TcxFilterCriteriaItemList* AOwner, System::TObject* AItemLink, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue) : Cxcustomdata::TcxDataFilterCriteriaItem(AOwner, AItemLink, AOperatorKind, AValue, ADisplayValue) { }
	/* TcxFilterCriteriaItem.Destroy */ inline __fastcall virtual ~TcxDBDataFilterCriteriaItem(void) { }
	
};


class DELPHICLASS TcxDBDataFilterCriteria;
typedef void __fastcall (__closure *TcxDBDataFilterBeforeChangeEvent)(TcxDBDataFilterCriteria* Sender, Data::Db::TDataSet* ADataSet, const System::UnicodeString AFilterText);

typedef void __fastcall (__closure *TcxDBDataFilterFormatFilterTextValueEvent)(TcxDBDataFilterCriteria* Sender, Cxfilter::TcxFilterCriteriaItem* AItem, const System::Variant &AValue, System::UnicodeString &ADisplayValue);

class PASCALIMPLEMENTATION TcxDBDataFilterCriteria : public Cxcustomdata::TcxDataFilterCriteria
{
	typedef Cxcustomdata::TcxDataFilterCriteria inherited;
	
private:
	bool FAutoDataSetFilter;
	bool FIgnoreOrigin;
	TcxDBDataFilterBeforeChangeEvent FOnBeforeChange;
	TcxDBDataFilterFormatFilterTextValueEvent FOnFormatFilterTextValue;
	TcxDBDataController* __fastcall GetDataController(void);
	void __fastcall SetAutoDataSetFilter(bool Value);
	void __fastcall SetIgnoreOrigin(bool Value);
	
protected:
	virtual void __fastcall FormatFilterTextValue(Cxfilter::TcxFilterCriteriaItem* AItem, const System::Variant &AValue, System::UnicodeString &ADisplayValue);
	virtual Cxfilter::TcxFilterCriteriaItemClass __fastcall GetItemClass(void);
	virtual void __fastcall Update(void);
	
public:
	__fastcall virtual TcxDBDataFilterCriteria(Cxcustomdata::TcxCustomDataController* ADataController);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source, bool AIgnoreItemNames = false);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	bool __fastcall IsAutoDataSetFilter(void);
	virtual bool __fastcall IsFiltering(void);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxDBDataController* DataController = {read=GetDataController};
	
__published:
	__property bool AutoDataSetFilter = {read=FAutoDataSetFilter, write=SetAutoDataSetFilter, default=0};
	__property DateTimeFormat = {default=0};
	__property bool IgnoreOrigin = {read=FIgnoreOrigin, write=SetIgnoreOrigin, default=1};
	__property TranslateBetween = {default=0};
	__property TranslateIn = {default=0};
	__property TranslateLike = {default=0};
	__property SupportedLike = {default=1};
	__property TcxDBDataFilterBeforeChangeEvent OnBeforeChange = {read=FOnBeforeChange, write=FOnBeforeChange};
	__property TcxDBDataFilterFormatFilterTextValueEvent OnFormatFilterTextValue = {read=FOnFormatFilterTextValue, write=FOnFormatFilterTextValue};
public:
	/* TcxDataFilterCriteria.Destroy */ inline __fastcall virtual ~TcxDBDataFilterCriteria(void) { }
	
};


class DELPHICLASS TcxDBDataSummaryItem;
class PASCALIMPLEMENTATION TcxDBDataSummaryItem : public Cxcustomdata::TcxDataSummaryItem
{
	typedef Cxcustomdata::TcxDataSummaryItem inherited;
	
private:
	TcxDBDataField* FDataField;
	System::UnicodeString FFieldName;
	TcxDBDataController* __fastcall GetDBDataController(void);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	
protected:
	virtual bool __fastcall IsCurrency(System::Word AVarType);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxDBDataController* DataController = {read=GetDBDataController};
	virtual Cxcustomdata::TcxCustomDataField* __fastcall DataField(void);
	
__published:
	__property System::UnicodeString FieldName = {read=FFieldName, write=SetFieldName};
public:
	/* TcxDataSummaryItem.Destroy */ inline __fastcall virtual ~TcxDBDataSummaryItem(void) { }
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxDBDataSummaryItem(System::Classes::TCollection* Collection) : Cxcustomdata::TcxDataSummaryItem(Collection) { }
	
};


class DELPHICLASS TcxDBDataModeController;
typedef bool __fastcall (__closure *TcxDBDataModeControllerDetailIsCurrentQueryEvent)(TcxDBDataModeController* Sender, Data::Db::TDataSet* ADataSet, const System::UnicodeString AMasterDetailKeyFieldNames, const System::Variant &AMasterDetailKeyValues);

typedef void __fastcall (__closure *TcxDBDataModeControllerDetailFirstEvent)(TcxDBDataModeController* Sender, Data::Db::TDataSet* ADataSet, const System::UnicodeString AMasterDetailKeyFieldNames, const System::Variant &AMasterDetailKeyValues, bool &AReopened);

class PASCALIMPLEMENTATION TcxDBDataModeController : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxDBDataController* FDataController;
	bool FDetailInSQLMode;
	bool FDetailInSyncMode;
	bool FGridMode;
	int FGridModeBufferCount;
	bool FSmartRefresh;
	bool FSyncInsert;
	bool FSyncMode;
	TcxDBDataModeControllerDetailFirstEvent FOnDetailFirst;
	TcxDBDataModeControllerDetailIsCurrentQueryEvent FOnDetailIsCurrentQuery;
	void __fastcall SetGridMode(bool Value);
	void __fastcall SetGridModeBufferCount(int Value);
	void __fastcall SetSmartRefresh(bool Value);
	void __fastcall SetSyncMode(bool Value);
	
protected:
	virtual bool __fastcall DetailIsCurrentQuery(const System::UnicodeString AMasterDetailKeyFieldNames, const System::Variant &AMasterDetailKeyValues);
	virtual void __fastcall DoDetailFirst(const System::UnicodeString AMasterDetailKeyFieldNames, const System::Variant &AMasterDetailKeyValues, bool &AReopened);
	__property bool DetailInSyncMode = {read=FDetailInSyncMode, write=FDetailInSyncMode, default=1};
	
public:
	__fastcall TcxDBDataModeController(TcxDBDataController* ADataController);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxDBDataController* DataController = {read=FDataController};
	__property bool SyncInsert = {read=FSyncInsert, write=FSyncInsert, default=1};
	
__published:
	__property bool DetailInSQLMode = {read=FDetailInSQLMode, write=FDetailInSQLMode, default=0};
	__property bool GridMode = {read=FGridMode, write=SetGridMode, default=0};
	__property int GridModeBufferCount = {read=FGridModeBufferCount, write=SetGridModeBufferCount, default=0};
	__property bool SmartRefresh = {read=FSmartRefresh, write=SetSmartRefresh, default=0};
	__property bool SyncMode = {read=FSyncMode, write=SetSyncMode, default=1};
	__property TcxDBDataModeControllerDetailFirstEvent OnDetailFirst = {read=FOnDetailFirst, write=FOnDetailFirst};
	__property TcxDBDataModeControllerDetailIsCurrentQueryEvent OnDetailIsCurrentQuery = {read=FOnDetailIsCurrentQuery, write=FOnDetailIsCurrentQuery};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDBDataModeController(void) { }
	
};


class DELPHICLASS TcxBookmarkList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBookmarkList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<System::DynamicArray<System::Byte> > _TcxBookmarkList__1;
	
	
public:
	System::DynamicArray<System::Byte> operator[](int Index) { return Items[Index]; }
	
private:
	_TcxBookmarkList__1 FItems;
	int __fastcall GetCount(void);
	System::DynamicArray<System::Byte> __fastcall GetItem(int AIndex);
	
public:
	__fastcall TcxBookmarkList(void);
	__fastcall virtual ~TcxBookmarkList(void);
	void __fastcall Clear(void);
	void __fastcall Add(System::DynamicArray<System::Byte> AItem);
	void __fastcall Insert(int AIndex, System::DynamicArray<System::Byte> AItem);
	void __fastcall Delete(int AIndex);
	__property int Count = {read=GetCount, nodefault};
	__property System::DynamicArray<System::Byte> Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TcxDBDataSelection;
class PASCALIMPLEMENTATION TcxDBDataSelection : public Cxcustomdata::TcxDataSelection
{
	typedef Cxcustomdata::TcxDataSelection inherited;
	
private:
	System::DynamicArray<System::Byte> FAnchorBookmark;
	// System::TArray__1<System::Byte>  FAnchorBookmark;
	TcxBookmarkList* FBookmarks;
	bool FInSelectAll;
	TcxDBDataController* __fastcall GetDataController(void);
	
protected:
	virtual void __fastcall ClearAnchor(void);
	int __fastcall CompareBookmarks(const System::DynamicArray<System::Byte> AItem1, const System::DynamicArray<System::Byte> AItem2);
	virtual void __fastcall InternalAdd(int AIndex, int ARowIndex, int ARecordIndex, int ALevel);
	virtual void __fastcall InternalClear(void);
	virtual void __fastcall InternalDelete(int AIndex);
	bool __fastcall FindBookmark(const System::DynamicArray<System::Byte> ABookmark, int &AIndex);
	virtual System::DynamicArray<System::Byte> __fastcall GetRowBookmark(int ARowIndex);
	bool __fastcall RefreshBookmarks(void);
	void __fastcall SyncCount(void);
	
public:
	__fastcall virtual TcxDBDataSelection(Cxcustomdata::TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDBDataSelection(void);
	virtual bool __fastcall FindByRowIndex(int ARowIndex, int &AIndex);
	void __fastcall SelectAll(void);
	void __fastcall SelectFromAnchor(System::DynamicArray<System::Byte> AToBookmark, bool AKeepSelection);
	__property TcxDBDataController* DataController = {read=GetDataController};
};


class DELPHICLASS TcxDBDataControllerInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBDataControllerInfo : public Cxcustomdata::TcxCustomDataControllerInfo
{
	typedef Cxcustomdata::TcxCustomDataControllerInfo inherited;
	
private:
	TcxDBDataController* __fastcall GetDataController(void);
	
protected:
	virtual int __fastcall GetSelectionMaxRecordCount(void);
	
public:
	__property TcxDBDataController* DataController = {read=GetDataController};
public:
	/* TcxCustomDataControllerInfo.Create */ inline __fastcall virtual TcxDBDataControllerInfo(Cxcustomdata::TcxCustomDataController* ADataController) : Cxcustomdata::TcxCustomDataControllerInfo(ADataController) { }
	/* TcxCustomDataControllerInfo.Destroy */ inline __fastcall virtual ~TcxDBDataControllerInfo(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxDBDataDetailHasChildrenEvent)(TcxDBDataController* Sender, int ARecordIndex, int ARelationIndex, const System::UnicodeString AMasterDetailKeyFieldNames, const System::Variant &AMasterDetailKeyValues, bool &HasChildren);

typedef void __fastcall (__closure *TcxDBDataControllerGridModeChangedEvent)(TcxDBDataController* Sender);

class PASCALIMPLEMENTATION TcxDBDataController : public Cxcustomdata::TcxCustomDataController
{
	typedef Cxcustomdata::TcxCustomDataController inherited;
	
private:
	System::DynamicArray<System::Byte> FBookmark;
	// System::TArray__1<System::Byte>  FBookmark;
	Cxcustomdata::TcxCustomDataController* FCreatedDataController;
	TcxDBDataModeController* FDataModeController;
	System::UnicodeString FDetailKeyFieldNames;
	bool FFocusingRecord;
	int FFocusingRecordIndex;
	bool FInCheckBrowseMode;
	bool FInCheckCurrentQuery;
	bool FInResetDataSetCurrent;
	bool FInUnboundCopy;
	bool FInUpdateGridModeBufferCount;
	TcxDBDataField* FKeyField;
	System::UnicodeString FKeyFieldNames;
	bool FLoaded;
	System::Classes::TList* FMasterDetailKeyFields;
	System::Variant FMasterDetailKeyValues;
	System::UnicodeString FMasterKeyFieldNames;
	bool FResetDBFields;
	bool FUpdateDataSetPos;
	TcxDBDataDetailHasChildrenEvent FOnDetailHasChildren;
	TcxDBDataControllerGridModeChangedEvent FOnGridModeChanged;
	TcxDBDataField* __fastcall AddInternalDBField(void);
	TcxDBDataControllerInfo* __fastcall GetDataControllerInfo(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	int __fastcall GetDataSetRecordCount(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	TcxDBDataField* __fastcall GetDBField(int Index);
	TcxDBDataSelection* __fastcall GetDBSelection(void);
	TcxDBDataFilterCriteria* __fastcall GetFilter(void);
	System::UnicodeString __fastcall GetMasterDetailKeyFieldNames(void);
	System::Classes::TList* __fastcall GetMasterDetailKeyFields(void);
	TcxDBDataProvider* __fastcall GetProvider(void);
	int __fastcall GetRecNo(void);
	void __fastcall MasterDetailKeyFieldsRemoveNotification(System::Classes::TComponent* AComponent);
	void __fastcall RemoveKeyField(void);
	void __fastcall SetDataModeController(TcxDBDataModeController* Value);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetDetailKeyFieldNames(const System::UnicodeString Value);
	HIDESBASE void __fastcall SetFilter(TcxDBDataFilterCriteria* Value);
	void __fastcall SetKeyFieldNames(const System::UnicodeString Value);
	void __fastcall SetMasterKeyFieldNames(const System::UnicodeString Value);
	void __fastcall SetRecNo(int Value);
	void __fastcall SyncDataSetPos(void);
	Cxcustomdata::TcxCustomDataController* __fastcall SyncMasterDetail(void);
	void __fastcall SyncMasterDetailDataSetPos(void);
	void __fastcall UpdateRelationFields(void);
	
protected:
	virtual void __fastcall ActiveChanged(bool AActive);
	virtual bool __fastcall CanChangeDetailExpanding(int ARecordIndex, bool AExpanded);
	virtual bool __fastcall CanFocusRecord(int ARecordIndex);
	virtual void __fastcall CheckDataSetCurrent(void);
	virtual bool __fastcall CheckMasterBrowseMode(void);
	void __fastcall ClearMasterDetailKeyFields(void);
	virtual void __fastcall CorrectAfterDelete(int ARecordIndex);
	virtual Cxcustomdata::TcxCustomDataControllerInfo* __fastcall CreateDataControllerInfo(void);
	virtual void __fastcall DoDataSetCurrentChanged(bool AIsCurrent);
	virtual void __fastcall DoDataSourceChanged(void);
	virtual void __fastcall DoGridModeChanged(void);
	virtual void __fastcall DoInitInsertingRecord(int AInsertingRecordIndex);
	virtual bool __fastcall DoSearchInGridMode(const System::UnicodeString ASubText, bool AForward, bool ANext);
	virtual int __fastcall FindRecordByFields(int ABufferRecordIndex, System::Classes::TList* AFields);
	int __fastcall FindRecordIndexInGridMode(const System::Variant &AKeyFieldValues);
	virtual int __fastcall GetActiveRecordIndex(void);
	virtual bool __fastcall GetClearDetailsOnCollapse(void);
	virtual Cxcustomdata::TcxCustomDataProviderClass __fastcall GetDataProviderClass(void);
	virtual int __fastcall GetDataRowCount(void);
	virtual Cxcustomdata::TcxDataSelectionClass __fastcall GetDataSelectionClass(void);
	virtual int __fastcall GetDefaultGridModeBufferCount(void);
	virtual Cxcustomdata::TcxCustomDataFieldClass __fastcall GetFieldClass(void);
	virtual Cxcustomdata::TcxDataFilterCriteriaClass __fastcall GetFilterCriteriaClass(void);
	virtual int __fastcall GetFocusedDataRowIndex(void);
	virtual void __fastcall GetKeyFields(System::Classes::TList* AList);
	virtual Cxcustomdata::TcxCustomDataRelationClass __fastcall GetRelationClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	virtual bool __fastcall InternalCheckBookmark(int ADeletedRecordIndex);
	virtual void __fastcall InternalClearBookmark(void);
	virtual void __fastcall InternalGotoBookmark(void);
	virtual bool __fastcall InternalSaveBookmark(void);
	virtual void __fastcall InvalidateDataBuffer(void);
	virtual bool __fastcall IsDataField(Cxcustomdata::TcxCustomDataField* AField);
	virtual bool __fastcall IsKeyNavigation(void);
	bool __fastcall IsOtherDetailChanged(void);
	bool __fastcall IsOtherDetailCreating(void);
	virtual bool __fastcall IsProviderDataSource(void);
	virtual bool __fastcall IsSmartRefresh(void);
	virtual void __fastcall LoadStorage(void);
	virtual int __fastcall LocateRecordIndex(TGetListProc AGetFieldsProc);
	virtual bool __fastcall LockOnAfterSummary(void);
	virtual void __fastcall NotifyDataControllers(void);
	void __fastcall NotifyDetailAfterFieldsRecreating(Cxcustomdata::TcxCustomDataController* ADataController);
	void __fastcall NotifyDetailsAfterFieldsRecreating(bool ACreatingLinkObject);
	virtual void __fastcall PrepareField(Cxcustomdata::TcxCustomDataField* AField);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	void __fastcall ResetDataSetCurrent(Cxcustomdata::TcxCustomDataController* ADataController);
	void __fastcall ResetDBFields(void);
	virtual void __fastcall RestructData(void);
	void __fastcall ResyncDBFields(void);
	void __fastcall RetrieveField(TcxDBDataField* ADataField, bool AIsLookupKeyOnly);
	virtual bool __fastcall TryFocusRecord(int ARecordIndex);
	void __fastcall UpdateEditingRecord(void);
	void __fastcall UpdateField(TcxDBDataField* ADataField, const System::UnicodeString AFieldNames, bool AIsLookup);
	virtual void __fastcall UpdateFields(void);
	virtual void __fastcall UpdateFocused(void);
	void __fastcall UpdateInternalKeyFields(const System::UnicodeString AFieldNames, TcxDBDataField* &AField);
	void __fastcall UpdateLookupFields(void);
	virtual void __fastcall UpdateRelations(Cxcustomdata::TcxCustomDataRelation* ARelation);
	virtual void __fastcall UpdateScrollBars(void);
	virtual void __fastcall BeginReadRecord(void);
	virtual void __fastcall EndReadRecord(void);
	__property TcxDBDataField* DBFields[int Index] = {read=GetDBField};
	__property TcxDBDataSelection* DBSelection = {read=GetDBSelection};
	__property TcxDBDataField* KeyField = {read=FKeyField};
	__property System::UnicodeString MasterDetailKeyFieldNames = {read=GetMasterDetailKeyFieldNames};
	__property System::Classes::TList* MasterDetailKeyFields = {read=GetMasterDetailKeyFields};
	__property System::Variant MasterDetailKeyValues = {read=FMasterDetailKeyValues};
	
public:
	__fastcall virtual TcxDBDataController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxDBDataController(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	void __fastcall ChangeFieldName(int AItemIndex, const System::UnicodeString AFieldName);
	virtual void __fastcall ChangeValueTypeClass(int AItemIndex, Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	System::TObject* __fastcall GetItemByFieldName(const System::UnicodeString AFieldName);
	Data::Db::TField* __fastcall GetItemField(int AItemIndex);
	System::UnicodeString __fastcall GetItemFieldName(int AItemIndex);
	virtual bool __fastcall IsDisplayFormatDefined(int AItemIndex, bool AIgnoreSimpleCurrency);
	virtual void __fastcall Loaded(void);
	void __fastcall BeginLocate(void);
	void __fastcall EndLocate(void);
	void __fastcall DoUpdateRecord(int ARecordIndex);
	virtual System::Variant __fastcall GetGroupValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField);
	void __fastcall GetKeyDBFields(System::Classes::TList* AList);
	System::Variant __fastcall GetKeyFieldsValues(void);
	virtual System::Variant __fastcall GetRecordId(int ARecordIndex);
	void __fastcall UpdateGridModeBufferCount(void);
	virtual void __fastcall CheckBrowseMode(void);
	virtual bool __fastcall DataChangedNotifyLocked(void);
	virtual void __fastcall RefreshExternalData(void);
	virtual void __fastcall SetFocus(void);
	virtual bool __fastcall IsBookmarkAvailable(void);
	virtual bool __fastcall IsBookmarkRow(int ARowIndex);
	virtual System::Variant __fastcall GetFilterDataValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField);
	virtual System::UnicodeString __fastcall GetFilterItemFieldName(System::TObject* AItem);
	int __fastcall FindRecordIndexByKey(const System::Variant &AKeyFieldValues);
	bool __fastcall LocateByKey(const System::Variant &AKeyFieldValues);
	void __fastcall CheckCurrentQuery(void);
	virtual TcxDBProviderDetailFilterAdapter* __fastcall GetDetailFilterAdapter(void);
	virtual void __fastcall SetMasterRelation(Cxcustomdata::TcxCustomDataRelation* AMasterRelation, int AMasterRecordIndex);
	virtual System::Variant __fastcall GetRowId(int ARowIndex);
	System::DynamicArray<System::Byte> __fastcall GetSelectedBookmark(int Index);
	virtual int __fastcall GetSelectedRowIndex(int Index);
	System::DynamicArray<System::Byte> __fastcall GetSelectionAnchorBookmark(void);
	virtual int __fastcall GetSelectionAnchorRowIndex(void);
	virtual bool __fastcall IsSelectionAnchorExist(void);
	virtual void __fastcall SelectAll(void);
	virtual void __fastcall SelectFromAnchor(int ARowIndex, bool AKeepSelection);
	virtual void __fastcall SetSelectionAnchor(int ARowIndex);
	virtual bool __fastcall FocusSelectedRow(int ASelectedIndex);
	virtual void __fastcall ForEachRow(bool ASelectedRows, Cxcustomdata::TcxDataControllerEachRowProc AProc);
	bool __fastcall IsSequenced(void);
	__property TcxDBDataControllerInfo* DataControllerInfo = {read=GetDataControllerInfo};
	__property TcxDBDataModeController* DataModeController = {read=FDataModeController, write=SetDataModeController};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property System::UnicodeString DetailKeyFieldNames = {read=FDetailKeyFieldNames, write=SetDetailKeyFieldNames};
	__property TcxDBDataFilterCriteria* Filter = {read=GetFilter, write=SetFilter};
	__property System::UnicodeString KeyFieldNames = {read=FKeyFieldNames, write=SetKeyFieldNames};
	__property System::UnicodeString MasterKeyFieldNames = {read=FMasterKeyFieldNames, write=SetMasterKeyFieldNames};
	__property TcxDBDataProvider* Provider = {read=GetProvider};
	__property int RecNo = {read=GetRecNo, write=SetRecNo, nodefault};
	__property int DataSetRecordCount = {read=GetDataSetRecordCount, nodefault};
	__property TcxDBDataDetailHasChildrenEvent OnDetailHasChildren = {read=FOnDetailHasChildren, write=FOnDetailHasChildren};
	__property TcxDBDataControllerGridModeChangedEvent OnGridModeChanged = {read=FOnGridModeChanged, write=FOnGridModeChanged};
};


class DELPHICLASS TcxDataSetBookmark;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSetBookmark : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int SaveActiveRecord;
	bool SaveBOF;
	System::DynamicArray<System::Byte> SaveBookmark;
	// System::TArray__1<System::Byte>  SaveBookmark;
	bool SaveEOF;
public:
	/* TObject.Create */ inline __fastcall TcxDataSetBookmark(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataSetBookmark(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxdb::TcxDBAdapterList* cxDetailFilterControllers;
extern PACKAGE TcxDataSetBookmark* __fastcall cxDataSetCreateBookmark(Data::Db::TDataSet* ADataSet);
extern PACKAGE void __fastcall cxDataSetRestoreBookmark(Data::Db::TDataSet* ADataSet, TcxDataSetBookmark* &ABookmark);
extern PACKAGE bool __fastcall CanCallDataSetLocate(Data::Db::TDataSet* ADataSet, const System::UnicodeString AKeyFieldNames, const System::Variant &AValue);
extern PACKAGE Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClassByField(Data::Db::TField* AField);
}	/* namespace Cxdbdata */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBDATA)
using namespace Cxdbdata;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbdataHPP
