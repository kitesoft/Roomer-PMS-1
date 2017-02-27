// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCustomData.pas' rev: 24.00 (Win32)

#ifndef CxcustomdataHPP
#define CxcustomdataHPP

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
#include <cxVariants.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcustomdata
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxInvalidDataControllerOperation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxInvalidDataControllerOperation : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxInvalidDataControllerOperation(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxInvalidDataControllerOperation(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxInvalidDataControllerOperation(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxInvalidDataControllerOperation(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxInvalidDataControllerOperation(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxInvalidDataControllerOperation(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxInvalidDataControllerOperation(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxInvalidDataControllerOperation(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxInvalidDataControllerOperation(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxInvalidDataControllerOperation(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxInvalidDataControllerOperation(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxInvalidDataControllerOperation(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxInvalidDataControllerOperation(void) { }
	
};

#pragma pack(pop)

typedef void * TcxDataRecordHandle;

typedef void * TcxDataItemHandle;

class DELPHICLASS TcxCustomDataSource;
class DELPHICLASS TcxCustomDataProvider;
class DELPHICLASS TcxCustomDataController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataSource : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataProvider* FCurrentProvider;
	TcxCustomDataProvider* FProvider;
	Dxcoreclasses::TdxFastList* FProviders;
	TcxCustomDataController* __fastcall GetDataController(void);
	TcxCustomDataProvider* __fastcall GetProvider(void);
	void __fastcall AddProvider(TcxCustomDataProvider* AProvider);
	void __fastcall RemoveProvider(TcxCustomDataProvider* AProvider);
	void __fastcall RemoveFromProviders(void);
	
protected:
	virtual void * __fastcall AppendRecord(void);
	virtual void __fastcall CustomSort(void);
	virtual void __fastcall DeleteRecord(void * ARecordHandle);
	virtual int __fastcall GetDefaultItemID(int AItemIndex);
	virtual bool __fastcall GetDetailHasChildren(int ARecordIndex, int ARelationIndex);
	virtual System::UnicodeString __fastcall GetDisplayText(void * ARecordHandle, void * AItemHandle);
	virtual bool __fastcall GetInfoForCompare(void * ARecordHandle, void * AItemHandle, char * &PValueBuffer);
	virtual void * __fastcall GetItemHandle(int AItemIndex);
	virtual int __fastcall GetRecordCount(void);
	virtual System::Variant __fastcall GetRecordId(void * ARecordHandle);
	virtual void * __fastcall GetRecordHandle(int ARecordIndex);
	virtual System::Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	virtual void * __fastcall InsertRecord(void * ARecordHandle);
	virtual bool __fastcall IsCustomSorting(void);
	virtual bool __fastcall IsNativeCompare(void);
	virtual bool __fastcall IsNativeCompareFunc(void);
	virtual bool __fastcall IsRecordIdSupported(void);
	virtual void __fastcall LoadRecordHandles(void);
	virtual int __fastcall NativeCompareFunc(void * ARecordHandle1, void * ARecordHandle2, void * AItemHandle);
	virtual void __fastcall SetRecordCount(int ARecordCount);
	virtual void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const System::Variant &AValue);
	virtual bool __fastcall IsMultiThreadingSupported(void);
	__property TcxCustomDataProvider* CurrentProvider = {read=FCurrentProvider, write=FCurrentProvider};
	int __fastcall AddRecordHandle(void * ARecordHandle);
	
public:
	__fastcall virtual ~TcxCustomDataSource(void);
	virtual void __fastcall DataChanged(void);
	virtual void * __fastcall GetRecordHandleByIndex(int ARecordIndex);
	int __fastcall GetRecordIndexByHandle(void * ARecordHandle);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxCustomDataProvider* Provider = {read=GetProvider};
public:
	/* TObject.Create */ inline __fastcall TcxCustomDataSource(void) : System::TObject() { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomDataSourceClass;

enum TcxDataChange : unsigned char { dcField, dcRecord, dcNew, dcDeleted, dcTotal };

struct DECLSPEC_DRECORD TcxDataChangeInfo
{
public:
	TcxDataChange Kind;
	int ItemIndex;
	int RecordIndex;
};


enum TcxDataLayoutChange : unsigned char { lcStructure, lcData };

typedef System::Set<TcxDataLayoutChange, TcxDataLayoutChange::lcStructure, TcxDataLayoutChange::lcData>  TcxDataLayoutChanges;

typedef System::DynamicArray<int> TcxDataSummaryCountValues;

typedef System::DynamicArray<System::Variant> TcxDataSummaryValues;

class DELPHICLASS TcxCustomDataField;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataProvider : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FActiveChanging;
	bool FChanging;
	TcxCustomDataSource* FCustomDataSource;
	bool FDataChangedLocked;
	TcxCustomDataController* FDataController;
	int FEditingRecordIndex;
	int FEditingRecordIndex1;
	int FEditingRecordIndex2;
	int FInsertedRecordIndex;
	bool FInUpdateData;
	int FLocateCount;
	int FLockCount;
	bool FModified;
	bool FRecreatedFieldsAfterFirst;
	int FSavedRecordIndex;
	void __fastcall SetCustomDataSource(TcxCustomDataSource* Value);
	
protected:
	bool FInInserting;
	bool FInserting;
	bool FLoadAllNeeded;
	virtual void __fastcall CustomSort(void);
	virtual bool __fastcall IsCustomDataSourceSupported(void);
	virtual bool __fastcall IsCustomSorting(void);
	virtual bool __fastcall IsGridMode(void);
	virtual bool __fastcall IsDataSource(void);
	virtual bool __fastcall IsOtherInsert(void);
	virtual bool __fastcall IsRecordIdSupported(void);
	virtual bool __fastcall IsSyncMode(void);
	virtual bool __fastcall IsActive(void);
	virtual bool __fastcall IsActiveDataSet(void);
	virtual bool __fastcall IsBOF(void);
	virtual bool __fastcall IsChanging(void);
	virtual bool __fastcall IsEditing(void);
	virtual bool __fastcall IsEOF(void);
	virtual bool __fastcall IsGridModeUpdating(void);
	virtual bool __fastcall IsInserting(void);
	virtual bool __fastcall IsModified(void);
	virtual bool __fastcall IsUnboundColumnMode(void);
	virtual void __fastcall CorrectRecordIndex(int ARecordIndex);
	virtual void __fastcall First(void);
	virtual void __fastcall Prev(void);
	virtual void __fastcall Next(void);
	virtual void __fastcall Last(void);
	virtual void __fastcall MoveBy(int ADistance);
	virtual void __fastcall Scroll(int ADistance);
	virtual void __fastcall SavePos(void);
	virtual void __fastcall RestorePos(void);
	virtual bool __fastcall CanAppend(void);
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanInitEditing(int ARecordIndex);
	virtual bool __fastcall CanInsert(void);
	virtual bool __fastcall CanModify(void);
	virtual void __fastcall Append(void);
	virtual void __fastcall Cancel(void);
	virtual void __fastcall DoUpdateData(void);
	virtual void __fastcall Delete(void);
	virtual void __fastcall DoDeleteRecords(System::Classes::TList* AList);
	virtual void __fastcall DeleteRecords(System::Classes::TList* AList);
	virtual void __fastcall DeleteSelection(void);
	virtual void __fastcall Edit(void);
	virtual System::Variant __fastcall GetEditValue(int ARecordIndex, TcxCustomDataField* AField, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall Insert(void);
	virtual void __fastcall Post(bool AForcePost = false);
	virtual void __fastcall PostEditingData(void);
	virtual bool __fastcall SetEditValue(int ARecordIndex, TcxCustomDataField* AField, const System::Variant &AValue, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall BeginDeleting(void);
	virtual void __fastcall EndDeleting(void);
	virtual void __fastcall AssignItemValue(int ARecordIndex, TcxCustomDataField* AField, const System::Variant &AValue);
	void __fastcall ClearSavedRecord(void);
	void __fastcall CreateSavedRecord(int ARecordIndex);
	virtual void __fastcall DoInitInsertingRecord(int AInsertingRecordIndex, const TcxDataSummaryValues AGroupValues);
	virtual void __fastcall EditingRecord(void);
	virtual void __fastcall DoInsertingRecord(bool AIsAppending);
	void __fastcall InsertingRecord(bool AIsAppending);
	virtual void __fastcall ResetChanging(void);
	virtual void __fastcall ResetEditing(void);
	virtual void __fastcall ResetModified(void);
	virtual void __fastcall SetChanging(void);
	virtual void __fastcall SetEditing(void);
	virtual void __fastcall SetModified(void);
	virtual void __fastcall BeginLocate(void);
	virtual void __fastcall EndLocate(void);
	virtual void __fastcall Freeze(void);
	virtual void __fastcall Unfreeze(void);
	int __fastcall AddRecordHandle(void * AData);
	virtual int __fastcall AppendRecord(void);
	virtual void __fastcall DeleteRecord(int ARecordIndex);
	virtual bool __fastcall GetDetailHasChildren(int ARecordIndex, int ARelationIndex);
	virtual System::UnicodeString __fastcall GetDisplayText(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::UnicodeString __fastcall GetExternalDataDisplayText(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetExternalDataValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetRecordId(int ARecordIndex);
	virtual int __fastcall GetRecordIndex(void);
	virtual System::Variant __fastcall GetValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual Cxdatastorage::TcxValueDefReaderClass __fastcall GetValueDefReaderClass(void);
	virtual int __fastcall InsertRecord(int ARecordIndex);
	virtual void __fastcall LoadDataBuffer(void);
	void __fastcall LoadRecordHandles(void);
	virtual int __fastcall NativeCompare(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField);
	virtual int __fastcall NativeCompareFunc(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField);
	virtual void __fastcall SetDisplayText(int ARecordIndex, TcxCustomDataField* AField, const System::UnicodeString Value);
	virtual void __fastcall SetRecordCount(int ARecordCount);
	virtual void __fastcall SetValue(int ARecordIndex, TcxCustomDataField* AField, const System::Variant &Value);
	virtual void __fastcall ActiveChanged(bool AActive);
	virtual void __fastcall DataChanged(TcxDataChange ADataChange, int AItemIndex, int ARecordIndex);
	virtual void __fastcall DataScrolled(int ADistance);
	virtual void __fastcall LayoutChanged(TcxDataLayoutChanges ADataLayoutChanges);
	__property bool ActiveChanging = {read=FActiveChanging, write=FActiveChanging, nodefault};
	__property TcxCustomDataSource* CustomDataSource = {read=FCustomDataSource, write=SetCustomDataSource};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int EditingRecordIndex = {read=FEditingRecordIndex, nodefault};
	__property int EditingRecordIndex1 = {read=FEditingRecordIndex1, nodefault};
	__property int EditingRecordIndex2 = {read=FEditingRecordIndex2, nodefault};
	__property int InsertedRecordIndex = {read=FInsertedRecordIndex, write=FInsertedRecordIndex, nodefault};
	__property int LocateCount = {read=FLocateCount, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	__property bool RecreatedFieldsAfterFirst = {read=FRecreatedFieldsAfterFirst, write=FRecreatedFieldsAfterFirst, nodefault};
	__property int SavedRecordIndex = {read=FSavedRecordIndex, write=FSavedRecordIndex, nodefault};
	
public:
	__fastcall virtual TcxCustomDataProvider(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxCustomDataProvider(void);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomDataProviderClass;

class DELPHICLASS TcxCustomDataFieldList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataField : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCachedIndex;
	TcxCustomDataFieldList* FFieldList;
	int FFlags;
	bool FIsInternal;
	System::TObject* FItem;
	int FLockRecreateData;
	bool FNeedConversion;
	int FNeedConversionFlag;
	bool FPrepared;
	TcxCustomDataField* FReferenceField;
	bool FTextStored;
	Cxdatastorage::TcxValueDef* FValueDef;
	Cxdatastorage::TcxValueTypeClass FValueTypeClass;
	TcxCustomDataController* __fastcall GetDataController(void);
	int __fastcall GetIndex(void);
	System::Classes::TComponent* __fastcall GetNotifier(void);
	bool __fastcall GetTextStored(void);
	Cxdatastorage::TcxValueDef* __fastcall GetValueDef(void);
	Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	void __fastcall SetIndex(int Value);
	void __fastcall SetIsInternal(bool Value);
	void __fastcall SetReferenceField(TcxCustomDataField* Value);
	void __fastcall SetTextStored(bool Value);
	void __fastcall SetValueTypeClass(Cxdatastorage::TcxValueTypeClass Value);
	
protected:
	void __fastcall BeginRecreateData(void);
	void __fastcall Changed(void);
	void __fastcall ClearData(void);
	void __fastcall CreateData(void);
	void __fastcall EndRecreateData(void);
	void __fastcall PrepareComparison(int AConversionFlag);
	virtual void __fastcall Reassign(TcxCustomDataField* ASource);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	void __fastcall ResetComparison(void);
	virtual bool __fastcall SupportsMultiThreading(void);
	__property TcxCustomDataFieldList* FieldList = {read=FFieldList};
	__property bool NeedConversion = {read=FNeedConversion, write=FNeedConversion, nodefault};
	__property int NeedConversionFlag = {read=FNeedConversionFlag, write=FNeedConversionFlag, nodefault};
	__property System::Classes::TComponent* Notifier = {read=GetNotifier};
	__property bool TextStored = {read=GetTextStored, write=SetTextStored, nodefault};
	__property Cxdatastorage::TcxValueDef* ValueDef = {read=GetValueDef};
	
public:
	__fastcall virtual TcxCustomDataField(TcxCustomDataFieldList* AFieldList);
	__fastcall virtual ~TcxCustomDataField(void);
	virtual bool __fastcall CanModify(Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual bool __fastcall IsUnbound(void);
	virtual bool __fastcall IsValueDefInternal(void);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property int Flags = {read=FFlags, write=FFlags, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property bool IsInternal = {read=FIsInternal, write=SetIsInternal, nodefault};
	__property System::TObject* Item = {read=FItem, write=FItem};
	__property TcxCustomDataField* ReferenceField = {read=FReferenceField, write=SetReferenceField};
	__property Cxdatastorage::TcxValueTypeClass ValueTypeClass = {read=GetValueTypeClass, write=SetValueTypeClass};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomDataFieldClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataFieldList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomDataField* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomDataController* FDataController;
	bool FFieldDestroyed;
	int FInternalCount;
	Dxcoreclasses::TdxFastList* FItems;
	int __fastcall GetCount(void);
	TcxCustomDataField* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	
protected:
	void __fastcall Add(TcxCustomDataField* AField);
	void __fastcall Clear(void);
	void __fastcall RemoveField(TcxCustomDataField* AField);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	void __fastcall Update(void);
	
public:
	__fastcall virtual TcxCustomDataFieldList(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxCustomDataFieldList(void);
	TcxCustomDataField* __fastcall FieldByItem(System::TObject* AItem);
	void __fastcall ReassignFields(TcxCustomDataField* ADestroyedField);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxCustomDataField* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TcxDetailInfoObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDetailInfoObject : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TObject* LinkObject;
	bool HasChildren;
	bool HasChildrenAssigned;
	__fastcall virtual ~TcxDetailInfoObject(void);
public:
	/* TObject.Create */ inline __fastcall TcxDetailInfoObject(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDetailObject;
class DELPHICLASS TcxCustomDataRelationList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDetailObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FActiveRelationIndex;
	Dxcoreclasses::TdxFastList* FInfoObjects;
	bool FExpanded;
	TcxDetailInfoObject* __fastcall GetInfoObject(int Index);
	int __fastcall GetInfoObjectCount(void);
	bool __fastcall GetIsEmpty(void);
	System::TObject* __fastcall GetLinkObject(int Index);
	int __fastcall GetLinkObjectCount(void);
	void __fastcall SetInfoObject(int Index, TcxDetailInfoObject* Value);
	void __fastcall SetLinkObject(int Index, System::TObject* Value);
	
protected:
	void __fastcall CorrectCount(TcxCustomDataRelationList* ARelations);
	
public:
	__fastcall TcxDetailObject(void);
	__fastcall virtual ~TcxDetailObject(void);
	void __fastcall Clear(void);
	bool __fastcall ClearHasChildrenFlag(void);
	void __fastcall ClearInfoObject(int AIndex);
	__property int ActiveRelationIndex = {read=FActiveRelationIndex, write=FActiveRelationIndex, nodefault};
	__property bool Expanded = {read=FExpanded, write=FExpanded, nodefault};
	__property int InfoObjectCount = {read=GetInfoObjectCount, nodefault};
	__property TcxDetailInfoObject* InfoObjects[int Index] = {read=GetInfoObject, write=SetInfoObject};
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
	__property int LinkObjectCount = {read=GetLinkObjectCount, nodefault};
	__property System::TObject* LinkObjects[int Index] = {read=GetLinkObject, write=SetLinkObject};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomDataRelation;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataRelation : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataController* FDetailDataController;
	System::TObject* FItem;
	TcxCustomDataRelationList* FRelationList;
	TcxCustomDataController* __fastcall GetDataController(void);
	int __fastcall GetIndex(void);
	
protected:
	void __fastcall Changed(void);
	virtual void __fastcall RemoveDataField(TcxCustomDataField* ADataField);
	
public:
	__fastcall virtual TcxCustomDataRelation(TcxCustomDataRelationList* ARelationList, System::TObject* AItem);
	__fastcall virtual ~TcxCustomDataRelation(void);
	virtual void __fastcall Assign(TcxCustomDataRelation* ASource);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxCustomDataController* DetailDataController = {read=FDetailDataController};
	__property int Index = {read=GetIndex, nodefault};
	__property System::TObject* Item = {read=FItem};
	__property TcxCustomDataRelationList* RelationList = {read=FRelationList};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomDataRelationClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataRelationList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomDataRelation* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomDataController* FDataController;
	TcxCustomDataField* FDataField;
	Dxcoreclasses::TdxFastList* FItems;
	int FLockCount;
	void __fastcall AddItem(TcxCustomDataRelation* AItem);
	int __fastcall GetCount(void);
	TcxCustomDataRelation* __fastcall GetItem(int Index);
	void __fastcall RemoveItem(TcxCustomDataRelation* AItem);
	
protected:
	void __fastcall Changed(TcxCustomDataRelation* ARelation);
	TcxDetailObject* __fastcall GetValueAsDetailObject(int ARecordIndex);
	void __fastcall RemoveDataField(TcxCustomDataField* ADataField);
	void __fastcall Update(TcxCustomDataRelation* ARelation);
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int LockCount = {read=FLockCount, nodefault};
	
public:
	__fastcall TcxCustomDataRelationList(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxCustomDataRelationList(void);
	TcxCustomDataRelation* __fastcall Add(System::TObject* AItem);
	void __fastcall Assign(TcxCustomDataRelationList* ASource);
	void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	bool __fastcall ClearDetailObject(int ARecordIndex, int ARelationIndex);
	void __fastcall EndUpdate(void);
	TcxCustomDataRelation* __fastcall FindByItem(System::TObject* AItem);
	TcxDetailObject* __fastcall GetDetailObject(int ARecordIndex);
	bool __fastcall IsDetailObjectExist(int ARecordIndex, int ARelationIndex);
	bool __fastcall IsEmpty(void);
	void __fastcall Move(int ACurIndex, int ANewIndex);
	void __fastcall RemoveByItem(System::TObject* AItem);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomDataRelation* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

typedef Dxcore::TdxSortOrder TcxDataSortOrder;

struct DECLSPEC_DRECORD TcxDataSortInfo
{
public:
	TcxCustomDataField* Field;
	Dxcore::TdxSortOrder SortOrder;
};


typedef TcxDataSortInfo *PcxDataSortInfo;

typedef void __fastcall (__closure *TcxNoParamsEvent)(void);

class DELPHICLASS TcxSortingFieldList;
class PASCALIMPLEMENTATION TcxSortingFieldList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxDataSortInfo operator[](int Index) { return Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastList* FItems;
	TcxNoParamsEvent FOnChanged;
	int __fastcall GetCount(void);
	TcxDataSortInfo __fastcall GetItem(int Index);
	
protected:
	void __fastcall Add(TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall Changed(void);
	void __fastcall Delete(int Index);
	int __fastcall Find(TcxCustomDataField* AField);
	void __fastcall Insert(int Index, TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall Move(int ACurIndex, int ANewIndex);
	void __fastcall Remove(TcxCustomDataField* AField);
	void __fastcall SetSortOrder(int Index, Dxcore::TdxSortOrder ASortOrder);
	
public:
	__fastcall TcxSortingFieldList(void);
	__fastcall virtual ~TcxSortingFieldList(void);
	void __fastcall AppendFrom(TcxSortingFieldList* AList);
	virtual void __fastcall ChangeSorting(TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall CheckField(TcxCustomDataField* AField);
	void __fastcall Clear(void);
	int __fastcall SortIndexByField(TcxCustomDataField* AField);
	Dxcore::TdxSortOrder __fastcall SortOrderByField(TcxCustomDataField* AField);
	bool __fastcall SupportsMultiThreading(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxDataSortInfo Items[int Index] = {read=GetItem/*, default*/};
	__property TcxNoParamsEvent OnChanged = {read=FOnChanged, write=FOnChanged};
};


class DELPHICLASS TcxGroupingFieldList;
class PASCALIMPLEMENTATION TcxGroupingFieldList : public TcxSortingFieldList
{
	typedef TcxSortingFieldList inherited;
	
public:
	void __fastcall ChangeGrouping(TcxCustomDataField* AField, int AGroupIndex);
	virtual void __fastcall ChangeSorting(TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	int __fastcall GroupIndexByField(TcxCustomDataField* AField);
	void __fastcall UpdateSorting(TcxSortingFieldList* ASortingFieldList);
public:
	/* TcxSortingFieldList.Create */ inline __fastcall TcxGroupingFieldList(void) : TcxSortingFieldList() { }
	/* TcxSortingFieldList.Destroy */ inline __fastcall virtual ~TcxGroupingFieldList(void) { }
	
};


class DELPHICLASS TcxDataControllerInfoHelper;
class DELPHICLASS TcxCustomDataControllerInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerInfoHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataControllerInfo* FDataControllerInfo;
	
protected:
	__property TcxCustomDataControllerInfo* DataControllerInfo = {read=FDataControllerInfo};
	
public:
	__fastcall virtual TcxDataControllerInfoHelper(TcxCustomDataControllerInfo* ADataControllerInfo);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataControllerInfoHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDataGroupInfo;
class PASCALIMPLEMENTATION TcxDataGroupInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int __fastcall GetRecordCount(void);
	
public:
	int RowIndex;
	int Level;
	int BeginRecordListIndex;
	int EndRecordListIndex;
	System::Variant SummaryValues;
	bool Expanded;
	__fastcall TcxDataGroupInfo(void);
	bool __fastcall Contains(int ARecordListIndex);
	__property int RecordCount = {read=GetRecordCount, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataGroupInfo(void) { }
	
};


struct DECLSPEC_DRECORD TcxGroupsRowInfo
{
public:
	bool Expanded;
	int Level;
	int Index;
	int RecordListIndex;
};


struct DECLSPEC_DRECORD TcxDataGroupCompareInfo
{
public:
	TcxDataGroupInfo* Info;
	int RecordIndex;
};


typedef TcxDataGroupCompareInfo *PcxDataGroupCompareInfo;

class DELPHICLASS TcxDataGroups;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataGroups : public TcxDataControllerInfoHelper
{
	typedef TcxDataControllerInfoHelper inherited;
	
public:
	TcxDataGroupInfo* operator[](int Index) { return Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastList* FFields;
	TcxCustomDataField* __fastcall GetField(int Index);
	int __fastcall GetFieldCount(void);
	TcxDataGroupInfo* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	int __fastcall GetRowCount(void);
	
protected:
	Dxcoreclasses::TdxFastObjectList* FItems;
	void __fastcall Add(TcxDataGroupInfo* const ADataGroupInfo);
	void __fastcall AddField(TcxCustomDataField* AField);
	TcxDataGroupInfo* __fastcall AddEmpty(void);
	void __fastcall AddToList(TcxDataGroupInfo* const ADataGroupInfo);
	void __fastcall Clear(void);
	int __fastcall Find(int ARowIndex, TcxDataGroupInfo* &AItem);
	int __fastcall FindByIndex(int ARecordListIndex, int ALevel);
	virtual TcxGroupsRowInfo __fastcall GetRowInfo(int ARowIndex);
	TcxDataGroupInfo* __fastcall GetTopVisibleItem(int ARowIndex, int &ACurIndex);
	int __fastcall IndexOf(TcxDataGroupInfo* AItem);
	bool __fastcall IsVisible(int AIndex);
	virtual bool __fastcall MakeVisible(int AIndex, bool AExpand);
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TcxCustomDataField* Fields[int Index] = {read=GetField};
	
public:
	__fastcall virtual TcxDataGroups(TcxCustomDataControllerInfo* ADataControllerInfo);
	__fastcall virtual ~TcxDataGroups(void);
	virtual void __fastcall ChangeExpanding(int ARowIndex, bool AExpanded, bool ARecursive);
	virtual void __fastcall FullExpanding(bool AExpanded);
	int __fastcall GetChildCount(int AIndex);
	int __fastcall GetChildIndex(int AParentIndex, int AIndex);
	int __fastcall GetChildRecordListIndex(int AParentIndex, int AIndex);
	virtual int __fastcall GetDataRecordListIndex(TcxDataGroupInfo* AInfo);
	int __fastcall GetFirstLevelCount(void);
	int __fastcall GetFirstLevelIndex(int AIndex);
	int __fastcall GetIndexByRowIndex(int ARowIndex);
	int __fastcall GetIndexByRowIndexLevel(int ARowIndex, int ALevel);
	int __fastcall GetLevel(int AIndex);
	int __fastcall GetParentIndex(int AChildIndex);
	virtual void __fastcall Rebuild(void);
	void __fastcall SetItem(int AIndex, TcxDataGroupInfo* AItem);
	__property int Count = {read=GetItemCount, nodefault};
	__property TcxDataGroupInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int LevelCount = {read=GetFieldCount, nodefault};
	__property TcxGroupsRowInfo RowInfo[int RowIndex] = {read=GetRowInfo};
	__property int RowCount = {read=GetRowCount, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataGroupsClass;

enum TcxDataControllerInfoChange : unsigned char { dcicLoad, dcicGrouping, dcicSorting, dcicFocusedRow, dcicView, dcicExpanding, dcicResetFocusedRow, dcicSelection, dcicSummary, dcicFocusedRecord };

typedef System::Set<TcxDataControllerInfoChange, TcxDataControllerInfoChange::dcicLoad, TcxDataControllerInfoChange::dcicFocusedRecord>  TcxDataControllerInfoChanges;

struct DECLSPEC_DRECORD TcxRowInfo
{
public:
	bool Expanded;
	int Level;
	int RecordIndex;
	int DataRowIndex;
	int RowIndex;
	int GroupIndex;
};


class DELPHICLASS TcxDataFocusingInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFocusingInfo : public TcxDataControllerInfoHelper
{
	typedef TcxDataControllerInfoHelper inherited;
	
private:
	bool FChangedFlag;
	int FLevel;
	bool FPrevNewItemRowFocused;
	int FPrevRecordIndex;
	int FRecordIndex;
	int FRowIndex;
	
protected:
	virtual void __fastcall Assign(TcxDataFocusingInfo* AFocusingInfo);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall IsEqual(TcxDataFocusingInfo* AFocusingInfo);
	virtual bool __fastcall IsNeedUpdate(void);
	virtual void __fastcall ResetPos(void);
	virtual void __fastcall SavePos(void);
	
public:
	__fastcall virtual TcxDataFocusingInfo(TcxCustomDataControllerInfo* ADataControllerInfo);
	__property int Level = {read=FLevel, write=FLevel, nodefault};
	__property int RecordIndex = {read=FRecordIndex, write=FRecordIndex, nodefault};
	__property int RowIndex = {read=FRowIndex, write=FRowIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataFocusingInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataFocusingInfoClass;

enum TcxDataExpandingInfoState : unsigned char { eisExpanded, eisSelected };

typedef System::Set<TcxDataExpandingInfoState, TcxDataExpandingInfoState::eisExpanded, TcxDataExpandingInfoState::eisSelected>  TcxDataExpandingInfoStateSet;

class DELPHICLASS TcxDataExpandingInfo;
class PASCALIMPLEMENTATION TcxDataExpandingInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int Level;
	System::Variant Value;
	TcxDataExpandingInfoStateSet State;
public:
	/* TObject.Create */ inline __fastcall TcxDataExpandingInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataExpandingInfo(void) { }
	
};


class DELPHICLASS TcxDataExpandingInfos;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataExpandingInfos : public TcxDataControllerInfoHelper
{
	typedef TcxDataControllerInfoHelper inherited;
	
public:
	TcxDataExpandingInfo* operator[](int Index) { return Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastList* FFields;
	Dxcoreclasses::TdxFastObjectList* FItems;
	TcxDataExpandingInfoStateSet FSaveStates;
	int __fastcall Find(TcxCustomDataField* AField);
	int __fastcall GetCount(void);
	bool __fastcall GetEmpty(void);
	TcxCustomDataField* __fastcall GetField(int Index);
	int __fastcall GetFieldCount(void);
	TcxDataExpandingInfo* __fastcall GetItem(int Index);
	
public:
	void __fastcall AddField(TcxCustomDataField* AField);
	void __fastcall AddItem(int ALevel, const System::Variant &AValue, TcxDataExpandingInfoStateSet AState);
	void __fastcall CheckField(TcxCustomDataField* AField);
	void __fastcall Clear(void);
	void __fastcall ClearFields(void);
	void __fastcall ClearValues(void);
	__fastcall virtual TcxDataExpandingInfos(TcxCustomDataControllerInfo* ADataControllerInfo);
	__fastcall virtual ~TcxDataExpandingInfos(void);
	__property int Count = {read=GetCount, nodefault};
	__property bool Empty = {read=GetEmpty, nodefault};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TcxCustomDataField* Fields[int Index] = {read=GetField};
	__property TcxDataExpandingInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxDataExpandingInfoStateSet SaveStates = {read=FSaveStates, write=FSaveStates, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataExpandingInfosClass;

struct DECLSPEC_DRECORD TcxDataSelectionInfo
{
public:
	int Level;
	int RecordIndex;
	int RowIndex;
};


typedef TcxDataSelectionInfo *PcxDataSelectionInfo;

class DELPHICLASS TcxDataSelection;
class PASCALIMPLEMENTATION TcxDataSelection : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	PcxDataSelectionInfo operator[](int Index) { return Items[Index]; }
	
private:
	int FAnchorRowIndex;
	TcxCustomDataController* FDataController;
	Dxcoreclasses::TdxFastList* FItems;
	Dxcoreclasses::TdxFastList* FFields;
	TcxNoParamsEvent FOnChanged;
	int __fastcall GetCount(void);
	TcxCustomDataField* __fastcall GetField(int Index);
	int __fastcall GetFieldCount(void);
	PcxDataSelectionInfo __fastcall GetItem(int Index);
	
protected:
	void __fastcall Changed(void);
	void __fastcall CheckAfterFiltering(void);
	virtual void __fastcall ClearAnchor(void);
	int __fastcall CompareSelections(void * AItem1, void * AItem2);
	virtual void __fastcall InternalAdd(int AIndex, int ARowIndex, int ARecordIndex, int ALevel);
	virtual void __fastcall InternalClear(void);
	virtual void __fastcall InternalDelete(int AIndex);
	virtual void __fastcall SetInternalCount(int ACount);
	
public:
	__fastcall virtual TcxDataSelection(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataSelection(void);
	virtual void __fastcall Add(int AIndex, int ARowIndex, int ARecordIndex, int ALevel);
	void __fastcall AddField(TcxCustomDataField* AField);
	void __fastcall Clear(void);
	void __fastcall ClearAll(void);
	void __fastcall ClearFields(void);
	void __fastcall Delete(int AIndex);
	int __fastcall FindByGroupIndex(int AGroupIndex);
	int __fastcall FindByRecordIndex(int ARecordIndex);
	virtual bool __fastcall FindByRowIndex(int ARowIndex, int &AIndex);
	bool __fastcall IsRecordSelected(int ARecordIndex);
	bool __fastcall IsRowSelected(int ARowIndex);
	void __fastcall Sort(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TcxCustomDataField* Fields[int Index] = {read=GetField};
	__property PcxDataSelectionInfo Items[int Index] = {read=GetItem/*, default*/};
	__property int AnchorRowIndex = {read=FAnchorRowIndex, nodefault};
	__property TcxNoParamsEvent OnChanged = {read=FOnChanged, write=FOnChanged};
};


typedef System::TMetaClass* TcxDataSelectionClass;

enum TcxDataControllerComparisonMode : unsigned char { dccmSorting, dccmGrouping, dccmOther };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataControllerInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxDataControllerComparisonMode FComparisonMode;
	TcxCustomDataController* FDataController;
	TcxDataGroups* FDataGroups;
	TcxDataExpandingInfos* FExpandingInfo;
	bool FExpandingFlag;
	bool FFocusingFlag;
	TcxDataFocusingInfo* FFocusingInfo;
	TcxGroupingFieldList* FGroupingFieldList;
	bool FInCanFocusedRowChanging;
	bool FInfoCalculation;
	int FLockCount;
	TcxDataFocusingInfo* FPrevFocusingInfo;
	Dxcoreclasses::TdxFastList* FRecordList;
	TcxDataSelection* FSelection;
	TcxSortingFieldList* FSortingFieldList;
	TcxSortingFieldList* FTotalSortingFieldList;
	bool FHasLockedInfoState;
	int FStateInfoCount;
	bool FSaveInfoSkipFlag;
	int __fastcall CompareRecords(void * ARecord1, void * ARecord2);
	int __fastcall GetDataRowCount(void);
	int __fastcall GetFocusedDataRowIndex(void);
	int __fastcall GetFocusedRecordIndex(void);
	int __fastcall GetFocusedRowIndex(void);
	int __fastcall GetGroupLevelCount(void);
	bool __fastcall GetNewItemRowFocusingChanged(void);
	int __fastcall GetPrevFocusedRecordIndex(void);
	int __fastcall GetPrevFocusedRowIndex(void);
	void __fastcall SetFocusedRowIndex(int Value);
	
protected:
	TcxDataControllerInfoChanges FChanges;
	void __fastcall CheckAfterCollapsing(void);
	void __fastcall CheckFocusingAfterFilter(void);
	void __fastcall CheckInfo(void);
	void __fastcall ClearInfo(void);
	void __fastcall SaveInfo(void);
	void __fastcall LockStateInfo(bool AUseLockedUpdate = true);
	void __fastcall UnlockStateInfo(bool AUseLockedUpdate = true);
	TcxDataExpandingInfoStateSet __fastcall GetStateInfoSet(bool ACheckChanges);
	bool __fastcall CanFocusedRowChanging(int ARowIndex);
	virtual void __fastcall CheckExpanding(void);
	virtual void __fastcall CheckFocusing(void);
	void __fastcall CorrectFocusedRow(int ARowIndex);
	void __fastcall DoChangeFocusedRow(int AValue, bool AIsInternal);
	virtual void __fastcall DoFilter(void);
	virtual void __fastcall DoGrouping(void);
	virtual void __fastcall DoLoad(void);
	virtual void __fastcall DoSort(void);
	void __fastcall DoBeginSummary(void);
	void __fastcall DoEndSummary(void);
	virtual void __fastcall DoUpdate(bool ASummaryChanged);
	virtual int __fastcall FindDataGroup(int ARecordListIndex);
	virtual int __fastcall FindFocusedRow(bool ANearest);
	void __fastcall ForwardChanges(void);
	virtual TcxDataExpandingInfosClass __fastcall GetDataExpandingInfosClass(void);
	virtual TcxDataFocusingInfoClass __fastcall GetDataFocusingInfoClass(void);
	virtual TcxDataGroupsClass __fastcall GetDataGroupsClass(void);
	virtual int __fastcall GetInternalRecordCount(void);
	int __fastcall GetInternalRecordListIndex(int ARecordIndex);
	virtual int __fastcall GetRecordListIndexByFocusingInfo(void);
	virtual int __fastcall GetSelectionMaxRecordCount(void);
	void __fastcall GetTotalSortingFields(void);
	bool __fastcall IsAlwaysExpanded(void);
	bool __fastcall IsGrouped(void);
	virtual bool __fastcall IsResetFocusingNeeded(void);
	bool __fastcall IsSummaryForSelectedRecords(void);
	bool __fastcall IsValidDataGroupInfo(void);
	virtual int __fastcall LocateGroupByLevel(int AGroupIndex, int ALevel);
	virtual int __fastcall LocateDetail(int AGroupIndex, int ARecordListIndex, bool AMakeVisible);
	void __fastcall PrepareSorting(TcxDataControllerComparisonMode AMode);
	void __fastcall RecalcSelection(void);
	void __fastcall RefreshGroups(void);
	virtual void __fastcall ResetFocusing(void);
	virtual void __fastcall SaveExpanding(TcxDataExpandingInfoStateSet ASaveStates);
	virtual void __fastcall TruncateSelection(void);
	void __fastcall UnprepareSorting(void);
	virtual void __fastcall Update(void);
	void __fastcall UpdatePrevFocusedInfo(void);
	void __fastcall DoSortBySummary(void);
	bool __fastcall IsSortingBySummary(void);
	__property TcxDataControllerInfoChanges Changes = {read=FChanges, nodefault};
	__property TcxDataExpandingInfos* ExpandingInfo = {read=FExpandingInfo};
	__property TcxDataFocusingInfo* FocusingInfo = {read=FFocusingInfo};
	__property int GroupLevelCount = {read=GetGroupLevelCount, nodefault};
	__property bool HasLockedInfoState = {read=FHasLockedInfoState, nodefault};
	__property TcxDataFocusingInfo* PrevFocusingInfo = {read=FPrevFocusingInfo};
	__property Dxcoreclasses::TdxFastList* RecordList = {read=FRecordList};
	__property TcxSortingFieldList* SortingFieldList = {read=FSortingFieldList};
	__property TcxSortingFieldList* TotalSortingFieldList = {read=FTotalSortingFieldList};
	
public:
	__fastcall virtual TcxCustomDataControllerInfo(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxCustomDataControllerInfo(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall CheckChanges(void);
	void __fastcall CheckRowIndex(int ARowIndex);
	int __fastcall GetInternalRecordIndex(int ARecordListIndex);
	void __fastcall Refresh(void);
	void __fastcall RefreshFocused(void);
	void __fastcall RefreshSummary(bool ARedrawOnly);
	void __fastcall RefreshView(void);
	void __fastcall ExpandingChanged(void);
	void __fastcall FocusedRecordChanged(bool AChangedFlag);
	void __fastcall GroupingChanged(void);
	void __fastcall SelectionChanged(void);
	void __fastcall SortingChanged(void);
	virtual void __fastcall RemoveField(TcxCustomDataField* AField);
	void __fastcall UpdateField(TcxCustomDataField* AField);
	void __fastcall ChangeSortIndex(TcxCustomDataField* AField, int ASortIndex);
	void __fastcall ChangeSorting(TcxCustomDataField* AField, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall ClearSorting(bool AKeepGroupedItems);
	void __fastcall ChangeExpanding(int ARowIndex, bool AExpanded, bool ARecursive);
	void __fastcall ChangeGrouping(TcxCustomDataField* AField, int AGroupIndex);
	void __fastcall ClearGrouping(void);
	int __fastcall CompareGroupRecords(int ARecordIndex1, int ARecordIndex2, int AIndex);
	void __fastcall FullCollapse(void);
	void __fastcall FullExpand(void);
	int __fastcall GetNearestRowIndex(int ARowIndex);
	int __fastcall GetRowCount(void);
	int __fastcall GetRowIndexByRecordIndex(int ARecordIndex, bool AMakeVisible);
	virtual TcxRowInfo __fastcall GetRowInfo(int ARowIndex);
	void __fastcall ChangeRowSelection(int ARowIndex, bool ASelection);
	void __fastcall ClearSelection(void);
	void __fastcall ClearSelectionAnchor(void);
	int __fastcall GetSelectedCount(void);
	int __fastcall GetSelectedRowIndex(int Index);
	bool __fastcall IsRowSelected(int ARowIndex);
	__property TcxDataSelection* Selection = {read=FSelection};
	__property int DataRowCount = {read=GetDataRowCount, nodefault};
	__property int FocusedDataRowIndex = {read=GetFocusedDataRowIndex, nodefault};
	__property int FocusedRecordIndex = {read=GetFocusedRecordIndex, nodefault};
	__property int FocusedRowIndex = {read=GetFocusedRowIndex, write=SetFocusedRowIndex, nodefault};
	__property bool NewItemRowFocusingChanged = {read=GetNewItemRowFocusingChanged, nodefault};
	__property int PrevFocusedRecordIndex = {read=GetPrevFocusedRecordIndex, nodefault};
	__property int PrevFocusedRowIndex = {read=GetPrevFocusedRowIndex, nodefault};
	__property TcxDataControllerComparisonMode ComparisonMode = {read=FComparisonMode, nodefault};
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property TcxDataGroups* DataGroups = {read=FDataGroups};
	__property TcxGroupingFieldList* GroupingFieldList = {read=FGroupingFieldList};
	__property int LockCount = {read=FLockCount, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxDataFilterCriteriaItem;
class PASCALIMPLEMENTATION TcxDataFilterCriteriaItem : public Cxfilter::TcxFilterCriteriaItem
{
	typedef Cxfilter::TcxFilterCriteriaItem inherited;
	
private:
	TcxCustomDataController* __fastcall GetDataController(void);
	TcxCustomDataField* __fastcall GetField(void);
	
protected:
	virtual System::Variant __fastcall GetDataValue(System::TObject* AData);
	virtual System::UnicodeString __fastcall GetFieldCaption(void);
	virtual System::UnicodeString __fastcall GetFieldName(void);
	virtual System::TObject* __fastcall GetItemLink(void);
	virtual void __fastcall SetItemLink(System::TObject* Value);
	virtual bool __fastcall SupportsMultiThreading(void);
	
public:
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxCustomDataField* Field = {read=GetField};
public:
	/* TcxFilterCriteriaItem.Create */ inline __fastcall virtual TcxDataFilterCriteriaItem(Cxfilter::TcxFilterCriteriaItemList* AOwner, System::TObject* AItemLink, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue) : Cxfilter::TcxFilterCriteriaItem(AOwner, AItemLink, AOperatorKind, AValue, ADisplayValue) { }
	/* TcxFilterCriteriaItem.Destroy */ inline __fastcall virtual ~TcxDataFilterCriteriaItem(void) { }
	
};


class DELPHICLASS TcxDataFilterValueList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFilterValueList : public Cxfilter::TcxFilterValueList
{
	typedef Cxfilter::TcxFilterValueList inherited;
	
private:
	TcxCustomDataController* __fastcall GetDataController(void);
	
public:
	virtual void __fastcall Load(int AItemIndex, bool AInitSortByDisplayText = true, bool AUseFilteredValues = false, bool AAddValueItems = true);
	__property TcxCustomDataController* DataController = {read=GetDataController};
public:
	/* TcxFilterValueList.Create */ inline __fastcall virtual TcxDataFilterValueList(Cxfilter::TcxFilterCriteria* ACriteria) : Cxfilter::TcxFilterValueList(ACriteria) { }
	/* TcxFilterValueList.Destroy */ inline __fastcall virtual ~TcxDataFilterValueList(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxDataFilterGetValueListEvent)(Cxfilter::TcxFilterCriteria* Sender, int AItemIndex, TcxDataFilterValueList* AValueList);

class DELPHICLASS TcxDataFilterCriteria;
class PASCALIMPLEMENTATION TcxDataFilterCriteria : public Cxfilter::TcxFilterCriteria
{
	typedef Cxfilter::TcxFilterCriteria inherited;
	
private:
	bool FActive;
	TcxCustomDataController* FDataController;
	bool FDestroying;
	TcxDataFilterGetValueListEvent FOnGetValueList;
	void __fastcall SetActive(bool Value);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	bool __fastcall DoFilterRecord(int ARecordIndex);
	virtual int __fastcall GetIDByItemLink(System::TObject* AItemLink);
	virtual System::UnicodeString __fastcall GetNameByItemLink(System::TObject* AItemLink);
	virtual Cxfilter::TcxFilterCriteriaItemClass __fastcall GetItemClass(void);
	virtual System::TObject* __fastcall GetItemLinkByID(int AID);
	virtual System::TObject* __fastcall GetItemLinkByName(const System::UnicodeString AName);
	virtual Cxfilter::TcxFilterValueListClass __fastcall GetValueListClass(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsInternal(void);
	bool __fastcall IsLoading(void);
	virtual void __fastcall Update(void);
	__property bool Destroying = {read=FDestroying, nodefault};
	
public:
	__fastcall virtual TcxDataFilterCriteria(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataFilterCriteria(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source, bool AIgnoreItemNames = false);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	virtual TcxDataFilterValueList* __fastcall CreateValueList(void);
	virtual Cxfilter::TcxFilterCriteriaItem* __fastcall FindItemByItemLink(System::TObject* AItemLink);
	virtual bool __fastcall IsFiltering(void);
	void __fastcall RemoveItemByField(TcxCustomDataField* AField);
	__property TcxCustomDataController* DataController = {read=FDataController};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property TcxDataFilterGetValueListEvent OnGetValueList = {read=FOnGetValueList, write=FOnGetValueList};
};


typedef System::TMetaClass* TcxDataFilterCriteriaClass;

class DELPHICLASS TcxDataFilterList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataFilterList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TcxDataFilterCriteria* operator[](int Index) { return Items[Index]; }
	
private:
	TcxDataFilterCriteria* __fastcall GetItem(int Index);
	
protected:
	void __fastcall RemoveItemByField(TcxCustomDataField* AField);
	
public:
	virtual void __fastcall Clear(void);
	__property TcxDataFilterCriteria* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxDataFilterList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxDataFilterList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

typedef int TcxDataGroupIndex;

class DELPHICLASS TcxDataControllerGroups;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerGroups : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataController* FDataController;
	int __fastcall GetChildCount(int DataGroupIndex);
	int __fastcall GetChildDataGroupIndex(int ParentDataGroupIndex, int ChildIndex);
	int __fastcall GetChildRecordIndex(int ParentDataGroupIndex, int ChildIndex);
	TcxCustomDataControllerInfo* __fastcall GetDataControllerInfo(void);
	int __fastcall GetDataGroupIndexByRowIndex(int RowIndex);
	TcxDataGroups* __fastcall GetDataGroups(void);
	int __fastcall GetFieldGroupIndex(TcxCustomDataField* AField);
	int __fastcall GetGroupingItemCount(void);
	int __fastcall GetGroupingItemIndex(int Index);
	System::UnicodeString __fastcall GetGroupDisplayText(int ADataGroupIndex);
	System::Variant __fastcall GetGroupValue(int ADataGroupIndex);
	int __fastcall GetItemGroupIndex(int AItemIndex);
	int __fastcall GetLevel(int ADataGroupIndex);
	int __fastcall GetParentDataGroupIndex(int ChildDataGroupIndex);
	
protected:
	int __fastcall GetGroupRecordIndex(int ADataGroupIndex);
	__property TcxCustomDataControllerInfo* DataControllerInfo = {read=GetDataControllerInfo};
	__property TcxDataGroups* DataGroups = {read=GetDataGroups};
	__property int LevelCount = {read=GetGroupingItemCount, nodefault};
	
public:
	__fastcall TcxDataControllerGroups(TcxCustomDataController* ADataController);
	void __fastcall ChangeExpanding(int ARowIndex, bool AExpanded, bool ARecursive);
	void __fastcall ChangeGrouping(int AItemIndex, int AGroupIndex);
	virtual void __fastcall ClearGrouping(void);
	virtual void __fastcall FullCollapse(void);
	virtual void __fastcall FullExpand(void);
	int __fastcall GetDataGroupIndexByGroupValue(int AParentDataGroupIndex, const System::Variant &AGroupValue);
	bool __fastcall HasAsParent(int ARowIndex, int AParentRowIndex);
	void __fastcall LoadRecordIndexes(System::Classes::TList* AList, int ADataGroupIndex);
	void __fastcall LoadRecordIndexesByRowIndex(System::Classes::TList* AList, int ARowIndex);
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int FieldGroupIndex[TcxCustomDataField* AField] = {read=GetFieldGroupIndex};
	__property int GroupingItemCount = {read=GetGroupingItemCount, nodefault};
	__property int GroupingItemIndex[int Index] = {read=GetGroupingItemIndex};
	__property int ItemGroupIndex[int ItemIndex] = {read=GetItemGroupIndex};
	__property int DataGroupIndexByRowIndex[int RowIndex] = {read=GetDataGroupIndexByRowIndex};
	__property int Level[int ADataGroupIndex] = {read=GetLevel};
	__property int ChildCount[int DataGroupIndex] = {read=GetChildCount};
	__property int ChildDataGroupIndex[int ParentDataGroupIndex][int ChildIndex] = {read=GetChildDataGroupIndex};
	__property int ChildRecordIndex[int ParentDataGroupIndex][int ChildIndex] = {read=GetChildRecordIndex};
	__property int ParentDataGroupIndex[int ChildDataGroupIndex] = {read=GetParentDataGroupIndex};
	__property System::UnicodeString GroupDisplayTexts[int ADataGroupIndex] = {read=GetGroupDisplayText};
	__property System::Variant GroupValues[int ADataGroupIndex] = {read=GetGroupValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataControllerGroups(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataControllerGroupsClass;

enum TcxSummaryKind : unsigned char { skNone, skSum, skMin, skMax, skCount, skAverage };

typedef System::Set<TcxSummaryKind, TcxSummaryKind::skNone, TcxSummaryKind::skAverage>  TcxSummaryKinds;

enum TcxSummaryValueType : unsigned char { svtFloat, svtCurrency, svtDate };

class DELPHICLASS TcxCustomDataSummaryItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataSummaryItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TcxCustomDataField* FField;
	System::UnicodeString FFormat;
	TcxSummaryKind FKind;
	System::TObject* __fastcall GetItemLink(void);
	void __fastcall SetFormat(const System::UnicodeString Value);
	void __fastcall SetItemLink(System::TObject* Value);
	void __fastcall SetKind(TcxSummaryKind Value);
	
protected:
	virtual void __fastcall AssignValues(TcxCustomDataSummaryItem* ASource);
	virtual bool __fastcall CanSetKind(TcxSummaryKind Value);
	virtual TcxCustomDataController* __fastcall GetDataController(void) = 0 ;
	virtual System::UnicodeString __fastcall GetValueFormat(TcxSummaryValueType AValueType, const System::Variant &AValue, bool AIsFooter);
	TcxSummaryValueType __fastcall GetValueType(System::Word AVarType);
	virtual bool __fastcall IsCurrency(System::Word AVarType);
	virtual void __fastcall ItemLinkChanging(TcxCustomDataField* AField);
	__property System::UnicodeString Format = {read=FFormat, write=SetFormat};
	__property TcxSummaryKind Kind = {read=FKind, write=SetKind, default=0};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual System::UnicodeString __fastcall FormatValue(const System::Variant &AValue, bool AIsFooter);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property System::TObject* ItemLink = {read=GetItemLink, write=SetItemLink};
	__property TcxCustomDataField* Field = {read=FField};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxCustomDataSummaryItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxCustomDataSummaryItem(void) { }
	
};

#pragma pack(pop)

enum TcxSummaryOption : unsigned char { soNullIgnore, soSelectedRecords, soMultipleSelectedRecords };

typedef System::Set<TcxSummaryOption, TcxSummaryOption::soNullIgnore, TcxSummaryOption::soMultipleSelectedRecords>  TcxSummaryOptions;

enum TcxSummaryPosition : unsigned char { spGroup, spFooter };

enum TcxSummaryProperty : unsigned char { spFormat, spKind, spSorted };

typedef System::Set<TcxSummaryProperty, TcxSummaryProperty::spFormat, TcxSummaryProperty::spSorted>  TcxSummaryProperties;

class DELPHICLASS TcxDataSummaryItem;
typedef void __fastcall (__closure *TcxDataSummaryItemGetTextEvent)(TcxDataSummaryItem* Sender, const System::Variant &AValue, bool AIsFooter, System::UnicodeString &AText);

class DELPHICLASS TcxDataSummaryItems;
class PASCALIMPLEMENTATION TcxDataSummaryItem : public TcxCustomDataSummaryItem
{
	typedef TcxCustomDataSummaryItem inherited;
	
private:
	bool FSorted;
	int FTag;
	TcxDataSummaryItemGetTextEvent FOnGetText;
	TcxSummaryPosition __fastcall GetPosition(void);
	TcxDataSummaryItems* __fastcall GetSummaryItems(void);
	void __fastcall SetPosition(TcxSummaryPosition Value);
	void __fastcall SetSorted(bool Value);
	
protected:
	TcxSummaryPosition FPosition;
	virtual void __fastcall AssignValues(TcxCustomDataSummaryItem* Source);
	virtual TcxCustomDataController* __fastcall GetDataController(void);
	virtual System::UnicodeString __fastcall GetValueFormat(TcxSummaryValueType AValueType, const System::Variant &AValue, bool AIsFooter);
	virtual bool __fastcall IsDataBinded(void);
	virtual bool __fastcall IsPositionStored(void);
	
public:
	__fastcall virtual ~TcxDataSummaryItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual TcxCustomDataField* __fastcall DataField(void);
	virtual System::UnicodeString __fastcall FormatValue(const System::Variant &AValue, bool AIsFooter);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxDataSummaryItems* SummaryItems = {read=GetSummaryItems};
	__property bool Sorted = {read=FSorted, write=SetSorted, default=0};
	
__published:
	__property Format = {default=0};
	__property Kind = {default=0};
	__property TcxSummaryPosition Position = {read=GetPosition, write=SetPosition, stored=IsPositionStored, nodefault};
	__property int Tag = {read=FTag, write=FTag, default=0};
	__property TcxDataSummaryItemGetTextEvent OnGetText = {read=FOnGetText, write=FOnGetText};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxDataSummaryItem(System::Classes::TCollection* Collection) : TcxCustomDataSummaryItem(Collection) { }
	
};


typedef System::TMetaClass* TcxDataSummaryItemClass;

struct DECLSPEC_DRECORD TcxSummaryEventArguments
{
public:
	int RecordIndex;
	TcxDataSummaryItem* SummaryItem;
};


struct DECLSPEC_DRECORD TcxSummaryEventOutArguments
{
public:
	System::Variant Value;
	System::Variant SummaryValue;
	int CountValue;
	bool Done;
};


typedef void __fastcall (__closure *TcxSummaryEvent)(TcxDataSummaryItems* ASender, TcxSummaryEventArguments &Arguments, TcxSummaryEventOutArguments &OutArguments);

class DELPHICLASS TcxDataSummary;
class PASCALIMPLEMENTATION TcxDataSummaryItems : public Dxcoreclasses::TcxCollection
{
	typedef Dxcoreclasses::TcxCollection inherited;
	
public:
	TcxDataSummaryItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxDataSummary* FSummary;
	TcxSummaryEvent FOnSummary;
	TcxCustomDataController* __fastcall GetDataController(void);
	HIDESBASE TcxDataSummaryItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxDataSummaryItem* Value);
	
protected:
	virtual void __fastcall BeforeSortingChange(TcxDataSummaryItem* AItem, bool AValue);
	void __fastcall ChangedView(void);
	virtual TcxSummaryPosition __fastcall GetItemPosition(TcxDataSummaryItem* AItem);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	int __fastcall IndexOfField(TcxCustomDataField* AField);
	virtual bool __fastcall IsPositionStored(TcxDataSummaryItem* AItem);
	TcxDataSummaryItem* __fastcall ItemOfField(TcxCustomDataField* AField);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	TcxDataSummaryItem* __fastcall AddDataItem(int AItemIndex, TcxSummaryPosition APosition);
	void __fastcall CheckItemEmpty(TcxDataSummaryItem* AItem);
	void __fastcall GetDataItemProperties(int AItemIndex, TcxSummaryPosition APosition, TcxSummaryProperties AProperties, System::UnicodeString &AFormat, TcxSummaryKind &AKind, bool &ASorted);
	virtual bool __fastcall IsPropertiesEmpty(TcxSummaryProperties AProperties, const System::UnicodeString AFormat, TcxSummaryKind AKind, bool ASorted);
	void __fastcall SetDataItemProperties(int AItemIndex, TcxSummaryPosition APosition, TcxSummaryProperties AProperties, const System::UnicodeString AFormat, TcxSummaryKind AKind, bool ASorted);
	void __fastcall SetItemProperties(TcxDataSummaryItem* AItem, TcxSummaryPosition APosition, TcxSummaryProperties AProperties, const System::UnicodeString AFormat, TcxSummaryKind AKind, bool ASorted);
	
public:
	__fastcall virtual TcxDataSummaryItems(TcxDataSummary* ASummary, TcxDataSummaryItemClass AItemClass);
	HIDESBASE TcxDataSummaryItem* __fastcall Add(void)/* overload */;
	HIDESBASE TcxDataSummaryItem* __fastcall Add(System::TObject* AItemLink, TcxSummaryPosition APosition, TcxSummaryKind AKind, const System::UnicodeString AFormat = System::UnicodeString())/* overload */;
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultFormat(TcxSummaryValueType AValueType, TcxSummaryKind ASummaryKind, bool AIsFooter);
	void __fastcall DeleteItems(System::TObject* AItemLink, TcxSummaryPosition APosition);
	TcxDataSummaryItem* __fastcall FindByTag(int ATag);
	virtual System::UnicodeString __fastcall GetGroupText(const System::Variant &ASummaryValues);
	int __fastcall IndexOf(TcxDataSummaryItem* AItem);
	int __fastcall IndexOfItemLink(System::TObject* AItemLink);
	TcxDataSummaryItem* __fastcall ItemOfItemLink(System::TObject* AItemLink);
	virtual TcxDataSummaryItem* __fastcall GetDataItem(int AItemIndex, TcxSummaryPosition APosition, bool ACheckKind = false, TcxSummaryKind AKind = (TcxSummaryKind)(0x0));
	System::UnicodeString __fastcall GetDataItemFormat(int AItemIndex, TcxSummaryPosition APosition);
	TcxSummaryKind __fastcall GetDataItemKind(int AItemIndex, TcxSummaryPosition APosition);
	bool __fastcall GetDataItemSorted(int AItemIndex, TcxSummaryPosition APosition);
	void __fastcall SetDataItemFormat(int AItemIndex, TcxSummaryPosition APosition, const System::UnicodeString Value);
	void __fastcall SetDataItemKind(int AItemIndex, TcxSummaryPosition APosition, TcxSummaryKind Value);
	void __fastcall SetDataItemSorted(int AItemIndex, TcxSummaryPosition APosition, bool Value);
	__property TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxDataSummaryItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxDataSummary* Summary = {read=FSummary};
	
__published:
	__property TcxSummaryEvent OnSummary = {read=FOnSummary, write=FOnSummary};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataSummaryItems(void) { }
	
};


class DELPHICLASS TcxDataFooterSummaryItems;
class PASCALIMPLEMENTATION TcxDataFooterSummaryItems : public TcxDataSummaryItems
{
	typedef TcxDataSummaryItems inherited;
	
protected:
	virtual TcxSummaryPosition __fastcall GetItemPosition(TcxDataSummaryItem* AItem);
	virtual bool __fastcall IsPositionStored(TcxDataSummaryItem* AItem);
public:
	/* TcxDataSummaryItems.Create */ inline __fastcall virtual TcxDataFooterSummaryItems(TcxDataSummary* ASummary, TcxDataSummaryItemClass AItemClass) : TcxDataSummaryItems(ASummary, AItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataFooterSummaryItems(void) { }
	
};


class DELPHICLASS TcxDataGroupSummaryItems;
class PASCALIMPLEMENTATION TcxDataGroupSummaryItems : public TcxDataSummaryItems
{
	typedef TcxDataSummaryItems inherited;
	
private:
	System::UnicodeString FBeginText;
	System::UnicodeString FEndText;
	System::UnicodeString FSeparator;
	System::Classes::TPersistent* FOwner;
	bool __fastcall IsBeginTextStored(void);
	bool __fastcall IsEndTextStored(void);
	bool __fastcall IsSeparatorStored(void);
	void __fastcall SetBeginText(const System::UnicodeString Value);
	void __fastcall SetEndText(const System::UnicodeString Value);
	void __fastcall SetSeparator(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall BeforeSortingChange(TcxDataSummaryItem* AItem, bool AValue);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxDataGroupSummaryItems(TcxDataSummary* ASummary, TcxDataSummaryItemClass AItemClass);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetGroupText(const System::Variant &ASummaryValues);
	TcxDataSummaryItem* __fastcall SortedSummaryItem(void);
	
__published:
	__property System::UnicodeString BeginText = {read=FBeginText, write=SetBeginText, stored=IsBeginTextStored};
	__property System::UnicodeString EndText = {read=FEndText, write=SetEndText, stored=IsEndTextStored};
	__property System::UnicodeString Separator = {read=FSeparator, write=SetSeparator, stored=IsSeparatorStored};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataGroupSummaryItems(void) { }
	
};


class DELPHICLASS TcxDataSummaryGroupItemLink;
class DELPHICLASS TcxDataSummaryGroupItemLinks;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSummaryGroupItemLink : public TcxCustomDataSummaryItem
{
	typedef TcxCustomDataSummaryItem inherited;
	
private:
	TcxDataSummaryGroupItemLinks* __fastcall GetSummaryGroupItemLinks(void);
	
protected:
	virtual TcxCustomDataController* __fastcall GetDataController(void);
	virtual void __fastcall ItemLinkChanging(TcxCustomDataField* AField);
	
public:
	__property TcxDataSummaryGroupItemLinks* SummaryGroupItemLinks = {read=GetSummaryGroupItemLinks};
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxDataSummaryGroupItemLink(System::Classes::TCollection* Collection) : TcxCustomDataSummaryItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxDataSummaryGroupItemLink(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataSummaryGroupItemLinkClass;

class DELPHICLASS TcxDataSummaryGroup;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSummaryGroupItemLinks : public Dxcoreclasses::TcxCollection
{
	typedef Dxcoreclasses::TcxCollection inherited;
	
public:
	TcxDataSummaryGroupItemLink* operator[](int Index) { return Items[Index]; }
	
private:
	TcxDataSummaryGroup* FSummaryGroup;
	HIDESBASE TcxDataSummaryGroupItemLink* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxDataSummaryGroupItemLink* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	int __fastcall IndexOfField(TcxCustomDataField* AField);
	TcxDataSummaryGroupItemLink* __fastcall ItemOfField(TcxCustomDataField* AField);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall virtual TcxDataSummaryGroupItemLinks(TcxDataSummaryGroup* ASummaryGroup, TcxDataSummaryGroupItemLinkClass AItemClass);
	HIDESBASE TcxDataSummaryGroupItemLink* __fastcall Add(void);
	int __fastcall IndexOfItemLink(System::TObject* AItemLink);
	TcxDataSummaryGroupItemLink* __fastcall ItemOfItemLink(System::TObject* AItemLink);
	__property TcxDataSummaryGroupItemLink* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxDataSummaryGroup* SummaryGroup = {read=FSummaryGroup};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataSummaryGroupItemLinks(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDataSummaryGroups;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSummaryGroup : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TcxDataSummaryGroupItemLinks* FItemLinks;
	TcxDataGroupSummaryItems* FSummaryItems;
	TcxDataSummaryGroupItemLinks* __fastcall GetItemLinks(void);
	TcxDataSummaryGroups* __fastcall GetSummaryGroups(void);
	void __fastcall SetItemLinks(TcxDataSummaryGroupItemLinks* Value);
	void __fastcall SetSummaryItems(TcxDataGroupSummaryItems* Value);
	
public:
	__fastcall virtual TcxDataSummaryGroup(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxDataSummaryGroup(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxDataSummaryGroups* SummaryGroups = {read=GetSummaryGroups};
	
__published:
	__property TcxDataSummaryGroupItemLinks* Links = {read=GetItemLinks, write=SetItemLinks};
	__property TcxDataGroupSummaryItems* SummaryItems = {read=FSummaryItems, write=SetSummaryItems};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataSummaryGroups : public Dxcoreclasses::TcxCollection
{
	typedef Dxcoreclasses::TcxCollection inherited;
	
public:
	TcxDataSummaryGroup* operator[](int Index) { return Items[Index]; }
	
private:
	TcxDataSummary* FSummary;
	HIDESBASE TcxDataSummaryGroup* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxDataSummaryGroup* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TcxDataSummaryGroups(TcxDataSummary* ASummary);
	HIDESBASE TcxDataSummaryGroup* __fastcall Add(void);
	TcxDataSummaryGroup* __fastcall FindByItemLink(System::TObject* AItemLink);
	__property TcxDataSummary* Summary = {read=FSummary};
	__property TcxDataSummaryGroup* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxDataSummaryGroups(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDataControllerObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataController* FDataController;
	
public:
	__fastcall virtual TcxDataControllerObject(TcxCustomDataController* ADataController);
	__property TcxCustomDataController* DataController = {read=FDataController};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataControllerObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDataControllerPersistent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomDataController* FDataController;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxDataControllerPersistent(TcxCustomDataController* ADataController);
	__property TcxCustomDataController* DataController = {read=FDataController};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDataControllerPersistent(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxAfterSummaryEvent)(TcxDataSummary* ASender);

class PASCALIMPLEMENTATION TcxDataSummary : public TcxDataControllerPersistent
{
	typedef TcxDataControllerPersistent inherited;
	
private:
	TcxDataGroupSummaryItems* FDefaultGroupSummaryItems;
	bool FDestroying;
	TcxDataFooterSummaryItems* FFooterSummaryItems;
	System::Variant FFooterSummaryValues;
	bool FInAfterSummary;
	int FLockCount;
	TcxSummaryOptions FOptions;
	bool FSetCustomSummary;
	TcxDataSummaryGroups* FSummaryGroups;
	TcxAfterSummaryEvent FOnAfterSummary;
	System::Variant __fastcall GetFooterSummaryValue(int Index);
	System::UnicodeString __fastcall GetFooterSummaryText(int Index);
	TcxDataGroupSummaryItems* __fastcall GetGroupSummaryItems(int Level);
	System::UnicodeString __fastcall GetGroupSummaryText(int RowIndex);
	System::Variant __fastcall GetGroupSummaryDisplayValue(int RowIndex, int Level, int Index);
	System::Variant __fastcall GetGroupSummaryValue(int DataGroupIndex, int Index);
	int __fastcall GetGroupFooterIndexOfItemLink(int Level, System::TObject* ItemLink);
	System::UnicodeString __fastcall GetGroupFooterSummaryText(int RowIndex, int Level, int Index);
	TcxSummaryOptions __fastcall GetOptions(void);
	void __fastcall SetDefaultGroupSummaryItems(TcxDataGroupSummaryItems* Value);
	void __fastcall SetFooterSummaryItems(TcxDataFooterSummaryItems* Value);
	void __fastcall SetFooterSummaryValue(int Index, const System::Variant &Value);
	void __fastcall SetGroupSummaryDisplayValue(int RowIndex, int Level, int Index, const System::Variant &Value);
	void __fastcall SetGroupSummaryValue(int DataGroupIndex, int Index, const System::Variant &Value);
	void __fastcall SetOptions(TcxSummaryOptions Value);
	void __fastcall SetSummaryGroups(TcxDataSummaryGroups* Value);
	
protected:
	virtual void __fastcall BeginCalculateSummary(TcxDataSummaryItems* ASummaryItems, TcxDataSummaryCountValues &ACountValues, TcxDataSummaryValues &ASummaryValues);
	virtual void __fastcall CalculateSummary(TcxDataSummaryItems* ASummaryItems, int ABeginIndex, int AEndIndex, TcxDataSummaryCountValues &ACountValues, TcxDataSummaryValues &ASummaryValues, System::Variant &SummaryValues);
	virtual void __fastcall Changed(bool ARedrawOnly);
	virtual void __fastcall DoAfterSummary(void);
	virtual void __fastcall DoFinishSummaryValue(TcxDataSummaryItem* ASummaryItem, System::Variant &SummaryValue, int &CountValue);
	virtual void __fastcall DoSummaryValue(TcxDataSummaryItem* ASummaryItem, int ARecordIndex, System::Variant &SummaryValue, int &CountValue);
	virtual void __fastcall EndCalculateSummary(TcxDataSummaryItems* ASummaryItems, TcxDataSummaryCountValues &ACountValues, TcxDataSummaryValues &ASummaryValues, System::Variant &SummaryValues);
	System::PVariant __fastcall GetGroupSummaryValues(int ADataGroupIndex);
	virtual int __fastcall GetRecordIndex(int ARecordListIndex);
	virtual TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass(void);
	virtual TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	virtual bool __fastcall IsValidSummaryValuesIndex(const System::Variant &ASummaryValues, int AIndex);
	virtual void __fastcall Update(bool ARedrawOnly);
	__property bool Destroying = {read=FDestroying, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	
public:
	__fastcall virtual TcxDataSummary(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataSummary(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AssignEvents(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	virtual void __fastcall BeginCalculate(void);
	virtual void __fastcall EndCalculate(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateFooterSummary(void);
	virtual void __fastcall CalculateGroupSummary(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	bool __fastcall GetGroupSummaryInfo(int ARowIndex, TcxDataSummaryItems* &ASummaryItems, System::PVariant &ASummaryValues);
	TcxDataSummaryItems* __fastcall GetPatternSummaryItems(TcxDataSummary* APatternSummary, TcxDataSummaryItems* ASummaryItems);
	void __fastcall Recalculate(void);
	void __fastcall RemoveItemByField(TcxCustomDataField* AField);
	__property System::Variant FooterSummaryValues[int Index] = {read=GetFooterSummaryValue, write=SetFooterSummaryValue};
	__property System::UnicodeString FooterSummaryTexts[int Index] = {read=GetFooterSummaryText};
	__property int GroupFooterIndexOfItemLink[int Level][System::TObject* ItemLink] = {read=GetGroupFooterIndexOfItemLink};
	__property TcxDataGroupSummaryItems* GroupSummaryItems[int Level] = {read=GetGroupSummaryItems};
	__property System::UnicodeString GroupFooterSummaryTexts[int RowIndex][int Level][int Index] = {read=GetGroupFooterSummaryText};
	__property System::UnicodeString GroupSummaryText[int RowIndex] = {read=GetGroupSummaryText};
	__property System::Variant GroupSummaryDisplayValues[int RowIndex][int Level][int Index] = {read=GetGroupSummaryDisplayValue, write=SetGroupSummaryDisplayValue};
	__property System::Variant GroupSummaryValues[int DataGroupIndex][int Index] = {read=GetGroupSummaryValue, write=SetGroupSummaryValue};
	
__published:
	__property TcxDataGroupSummaryItems* DefaultGroupSummaryItems = {read=FDefaultGroupSummaryItems, write=SetDefaultGroupSummaryItems};
	__property TcxDataFooterSummaryItems* FooterSummaryItems = {read=FFooterSummaryItems, write=SetFooterSummaryItems};
	__property TcxDataSummaryGroups* SummaryGroups = {read=FSummaryGroups, write=SetSummaryGroups};
	__property TcxSummaryOptions Options = {read=GetOptions, write=SetOptions, default=0};
	__property TcxAfterSummaryEvent OnAfterSummary = {read=FOnAfterSummary, write=FOnAfterSummary};
};


typedef System::TMetaClass* TcxDataSummaryClass;

class DELPHICLASS TcxDataControllerMultiThreadedOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerMultiThreadedOptions : public TcxDataControllerPersistent
{
	typedef TcxDataControllerPersistent inherited;
	
private:
	Dxcore::TdxDefaultBoolean FFiltering;
	Dxcore::TdxDefaultBoolean FSorting;
	Dxcore::TdxDefaultBoolean FSummary;
	bool __fastcall GetActualValue(Dxcore::TdxDefaultBoolean AValue);
	
protected:
	bool __fastcall IsMultiThreadedFiltering(void);
	bool __fastcall IsMultiThreadedSorting(void);
	bool __fastcall IsMultiThreadedSummary(void);
	__property Dxcore::TdxDefaultBoolean Summary = {read=FSummary, write=FSummary, default=2};
	
public:
	__fastcall virtual TcxDataControllerMultiThreadedOptions(TcxCustomDataController* ADataController);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Dxcore::TdxDefaultBoolean Filtering = {read=FFiltering, write=FFiltering, default=2};
	__property Dxcore::TdxDefaultBoolean Sorting = {read=FSorting, write=FSorting, default=2};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDataControllerMultiThreadedOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataControllerMultiThreadedOptionsClass;

class DELPHICLASS TcxDataControllerSearch;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerSearch : public TcxDataControllerObject
{
	typedef TcxDataControllerObject inherited;
	
private:
	bool FLocked;
	int __fastcall GetItemIndex(void);
	bool __fastcall GetSearching(void);
	System::UnicodeString __fastcall GetSearchText(void);
	void __fastcall SetItemIndex(const int Value);
	
protected:
	virtual void __fastcall DoFocusedRecord(int AFilteredRecordIndex);
	virtual int __fastcall DoSearch(int AStartFilteredRecordIndex, int AEndFilteredRecordIndex, const System::UnicodeString ASubText, bool AForward);
	
public:
	void __fastcall Cancel(void);
	virtual bool __fastcall Locate(int AItemIndex, const System::UnicodeString ASubText);
	virtual bool __fastcall LocateNext(bool AForward);
	virtual void __fastcall Lock(void);
	virtual void __fastcall Unlock(void);
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property bool Locked = {read=FLocked, nodefault};
	__property bool Searching = {read=GetSearching, nodefault};
	__property System::UnicodeString SearchText = {read=GetSearchText};
public:
	/* TcxDataControllerObject.Create */ inline __fastcall virtual TcxDataControllerSearch(TcxCustomDataController* ADataController) : TcxDataControllerObject(ADataController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataControllerSearch(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDataControllerSearchClass;

enum TcxDataControllerChange : unsigned char { dccLayout, dccData, dccFocus, dccSelection, dccDetail, dccSummary, dccSearch, dccSorting, dccGrouping, dccSyncMasterPos, dccBookmark, dccUpdateRecord, dccGridMode };

typedef System::Set<TcxDataControllerChange, TcxDataControllerChange::dccLayout, TcxDataControllerChange::dccGridMode>  TcxDataControllerChanges;

class DELPHICLASS TcxUpdateControlInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxUpdateControlInfo : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	TcxUpdateControlInfo* __fastcall Clone(void);
	virtual bool __fastcall CanNavigatorUpdate(void);
public:
	/* TObject.Create */ inline __fastcall TcxUpdateControlInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxUpdateControlInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxUpdateControlInfoClass;

class DELPHICLASS TcxFocusedRecordChangedInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFocusedRecordChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	int FFocusedRecordIndex;
	int FPrevFocusedRecordIndex;
	int FFocusedRowIndex;
	int FPrevFocusedRowIndex;
	bool FNewItemRowFocusingChanged;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	__fastcall TcxFocusedRecordChangedInfo(int APrevFocusedRecordIndex, int AFocusedRecordIndex, int APrevFocusedRowIndex, int AFocusedRowIndex, bool ANewItemRowFocusingChanged);
	__property int FocusedRecordIndex = {read=FFocusedRecordIndex, nodefault};
	__property int PrevFocusedRecordIndex = {read=FPrevFocusedRecordIndex, nodefault};
	__property int FocusedRowIndex = {read=FFocusedRowIndex, nodefault};
	__property int PrevFocusedRowIndex = {read=FPrevFocusedRowIndex, nodefault};
	__property bool NewItemRowFocusingChanged = {read=FNewItemRowFocusingChanged, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFocusedRecordChangedInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxFocusedRowChangedInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFocusedRowChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	int FFocusedRowIndex;
	int FPrevFocusedRowIndex;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	__fastcall TcxFocusedRowChangedInfo(int APrevFocusedRowIndex, int AFocusedRowIndex);
	__property int FocusedRowIndex = {read=FFocusedRowIndex, nodefault};
	__property int PrevFocusedRowIndex = {read=FPrevFocusedRowIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFocusedRowChangedInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGroupingChangingInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGroupingChangingInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
public:
	virtual bool __fastcall CanNavigatorUpdate(void);
public:
	/* TObject.Create */ inline __fastcall TcxGroupingChangingInfo(void) : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGroupingChangingInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxLayoutChangedInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxLayoutChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxLayoutChangedInfo(void) : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxLayoutChangedInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxUpdateRecordInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxUpdateRecordInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	int FRecordIndex;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	__fastcall TcxUpdateRecordInfo(int ARecordIndex);
	__property int RecordIndex = {read=FRecordIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxUpdateRecordInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDataChangedInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	
public:
	TcxDataChange Kind;
	int ItemIndex;
	int RecordIndex;
public:
	/* TObject.Create */ inline __fastcall TcxDataChangedInfo(void) : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataChangedInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxBookmarkChangedInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBookmarkChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxBookmarkChangedInfo(void) : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxBookmarkChangedInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSelectionChangedInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSelectionChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
private:
	System::Classes::TList* FRowIndexes;
	int __fastcall GetCount(void);
	int __fastcall GetRowIndex(int Index);
	
protected:
	virtual void __fastcall AssignTo(TcxUpdateControlInfo* AInfo);
	System::Classes::TList* __fastcall CreateRowIndexes(void);
	
public:
	__fastcall TcxSelectionChangedInfo(void);
	__fastcall TcxSelectionChangedInfo(int ARowIndex1, int ARowIndex2);
	__fastcall virtual ~TcxSelectionChangedInfo(void);
	virtual bool __fastcall CanNavigatorUpdate(void);
	__property int Count = {read=GetCount, nodefault};
	__property int RowIndexes[int Index] = {read=GetRowIndex};
};

#pragma pack(pop)

class DELPHICLASS TcxSearchChangedInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSearchChangedInfo : public TcxUpdateControlInfo
{
	typedef TcxUpdateControlInfo inherited;
	
public:
	/* TObject.Create */ inline __fastcall TcxSearchChangedInfo(void) : TcxUpdateControlInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSearchChangedInfo(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxDataSelectionChangedInfo
{
public:
	int SelectedCount;
	int RowIndex;
};


typedef void __fastcall (__closure *TcxUpdateControlEvent)(TcxUpdateControlInfo* AInfo);

class DELPHICLASS TcxDataControllerLocateObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerLocateObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomDataController* FDataController;
	int FInternalRecordIndex;
	
protected:
	__property TcxCustomDataController* DataController = {read=FDataController};
	__property int InternalRecordIndex = {read=FInternalRecordIndex, nodefault};
	
public:
	__fastcall virtual TcxDataControllerLocateObject(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataControllerLocateObject(void);
	virtual void __fastcall Clear(void);
	virtual int __fastcall FindRecordIndex(void) = 0 ;
	void __fastcall ReadData(Cxdatastorage::TcxValueDefReader* AValueDefReader);
};

#pragma pack(pop)

class DELPHICLASS TcxDataControllerKeyLocateObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerKeyLocateObject : public TcxDataControllerLocateObject
{
	typedef TcxDataControllerLocateObject inherited;
	
private:
	System::Classes::TList* FFields;
	
public:
	__fastcall virtual TcxDataControllerKeyLocateObject(TcxCustomDataController* ADataController);
	__fastcall virtual ~TcxDataControllerKeyLocateObject(void);
	void __fastcall AddField(TcxCustomDataField* AField);
	void __fastcall ClearFields(void);
	virtual int __fastcall FindRecordIndex(void);
	__property System::Classes::TList* FieldList = {read=FFields};
};

#pragma pack(pop)

class DELPHICLASS TcxDataControllerGroupLocateObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerGroupLocateObject : public TcxDataControllerLocateObject
{
	typedef TcxDataControllerLocateObject inherited;
	
private:
	bool FIsGroupDataSorted;
	int FLevel;
	
public:
	__fastcall virtual TcxDataControllerGroupLocateObject(TcxCustomDataController* ADataController);
	virtual int __fastcall FindRecordIndex(void);
	__property int Level = {read=FLevel, write=FLevel, nodefault};
public:
	/* TcxDataControllerLocateObject.Destroy */ inline __fastcall virtual ~TcxDataControllerGroupLocateObject(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxValueDefUnboundReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueDefUnboundReader : public Cxdatastorage::TcxValueDefReader
{
	typedef Cxdatastorage::TcxValueDefReader inherited;
	
private:
	System::Classes::TList* FItems;
	System::Classes::TList* FValues;
	
public:
	__fastcall virtual TcxValueDefUnboundReader(void);
	__fastcall virtual ~TcxValueDefUnboundReader(void);
	void __fastcall Clear(void);
	virtual System::Variant __fastcall GetValue(Cxdatastorage::TcxValueDef* AValueDef);
	virtual bool __fastcall IsInternal(Cxdatastorage::TcxValueDef* AValueDef);
	void __fastcall SetValue(Cxdatastorage::TcxValueDef* AValueDef, const System::Variant &AValue);
	void __fastcall Truncate(int AItemCount);
};

#pragma pack(pop)

class DELPHICLASS TcxValueDefRecordReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxValueDefRecordReader : public Cxdatastorage::TcxValueDefReader
{
	typedef Cxdatastorage::TcxValueDefReader inherited;
	
private:
	TcxCustomDataController* FDataController;
	int FRecordIndex;
	
public:
	__fastcall TcxValueDefRecordReader(TcxCustomDataController* ADataController, int ARecordIndex);
	virtual System::UnicodeString __fastcall GetDisplayText(Cxdatastorage::TcxValueDef* AValueDef);
	virtual System::Variant __fastcall GetValue(Cxdatastorage::TcxValueDef* AValueDef);
	virtual bool __fastcall IsInternal(Cxdatastorage::TcxValueDef* AValueDef);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxValueDefRecordReader(void) { }
	
};

#pragma pack(pop)

enum TcxDataControllerDetailMode : unsigned char { dcdmNone, dcdmPattern, dcdmClone };

typedef void __fastcall (__closure *TcxDataControllerEachDetailProc)(TcxCustomDataController* ADataController);

typedef void __fastcall (__closure *TcxDataControllerEachRowProc)(int ARowIndex, TcxRowInfo &ARowInfo);

class DELPHICLASS TcxDataControllerNotifier;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataControllerNotifier : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TcxCustomDataController* FDataController;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall TcxDataControllerNotifier(System::Classes::TComponent* AOwner, TcxCustomDataController* ADataController);
	__property TcxCustomDataController* DataController = {read=FDataController};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TcxDataControllerNotifier(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSortingBySummaryEngineClass;

class DELPHICLASS TcxSortingBySummaryEngine;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSortingBySummaryEngine : public TcxDataControllerInfoHelper
{
	typedef TcxDataControllerInfoHelper inherited;
	
private:
	TcxCustomDataController* __fastcall GetDataController(void);
	
protected:
	__property TcxCustomDataController* DataController = {read=GetDataController};
	
public:
	virtual void __fastcall Sort(void) = 0 ;
public:
	/* TcxDataControllerInfoHelper.Create */ inline __fastcall virtual TcxSortingBySummaryEngine(TcxCustomDataControllerInfo* ADataControllerInfo) : TcxDataControllerInfoHelper(ADataControllerInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSortingBySummaryEngine(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxDataControllerCompareEvent)(TcxCustomDataController* ADataController, int ARecordIndex1, int ARecordIndex2, int AItemIndex, const System::Variant &V1, const System::Variant &V2, int &Compare);

typedef void __fastcall (__closure *TcxDataRecordChangedEvent)(TcxCustomDataController* ADataController, int ARecordIndex, int AItemIndex);

typedef void __fastcall (__closure *TcxDataControllerNotifyEvent)(TcxCustomDataController* ADataController);

typedef void __fastcall (__closure *TcxDataDetailExpandingEvent)(TcxCustomDataController* ADataController, int ARecordIndex, bool &AAllow);

typedef void __fastcall (__closure *TcxDataDetailExpandedEvent)(TcxCustomDataController* ADataController, int ARecordIndex);

typedef TcxDataDetailExpandedEvent TcxDataRecordNotifyEvent;

enum TcxDataControllerOption : unsigned char { dcoAnsiSort, dcoCaseInsensitive, dcoAssignGroupingValues, dcoAssignMasterDetailKeys, dcoSaveExpanding, dcoSortByDisplayText, dcoFocusTopRowAfterSorting, dcoGroupsAlwaysExpanded, dcoImmediatePost, dcoInsertOnNewItemRowFocusing };

typedef System::Set<TcxDataControllerOption, TcxDataControllerOption::dcoAnsiSort, TcxDataControllerOption::dcoInsertOnNewItemRowFocusing>  TcxDataControllerOptions;

enum TcxDataControllerEditKind : unsigned char { dceInsert, dceEdit, dceChanging, dceModified };

typedef System::Set<TcxDataControllerEditKind, TcxDataControllerEditKind::dceInsert, TcxDataControllerEditKind::dceModified>  TcxDataControllerEditState;

enum TcxDataControllerEditOperation : unsigned char { dceoAppend, dceoDelete, dceoEdit, dceoInsert, dceoShowEdit };

typedef System::Set<TcxDataControllerEditOperation, TcxDataControllerEditOperation::dceoAppend, TcxDataControllerEditOperation::dceoShowEdit>  TcxDataControllerEditOperations;

class DELPHICLASS TcxDataListenerLink;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDataListenerLink : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomDataController* Ref;
public:
	/* TObject.Create */ inline __fastcall TcxDataListenerLink(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDataListenerLink(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxDataFilterRecordEvent)(TcxCustomDataController* ADataController, int ARecordIndex, bool &Accept);

class PASCALIMPLEMENTATION TcxCustomDataController : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FActive;
	bool FAfterSummaryFlag;
	int FBookmarkRecordIndex;
	bool FDataChangedFlag;
	int FDataChangedLockCount;
	TcxDataControllerChanges FChanges;
	bool FCheckFocusingAfterFilterNeeded;
	TcxCustomDataController* FCreatingDataController;
	bool FCreatingLinkObject;
	System::Classes::TList* FDataChangedListeners;
	int FDataChangeRefCount;
	TcxCustomDataControllerInfo* FDataControllerInfo;
	Cxdatastorage::TcxDataStorage* FDataStorage;
	bool FDestroying;
	bool FGroupingChangedFlag;
	TcxDataControllerGroups* FGroups;
	TcxCustomDataFieldList* FFields;
	TcxDataFilterCriteria* FFilter;
	bool FFilterChangedFlag;
	TcxDataFilterList* FFilters;
	bool FFocusedSelected;
	TcxCustomDataField* FIncrementalFilterField;
	System::UnicodeString FIncrementalFilterText;
	TcxCustomDataField* FIncrementalSearchField;
	bool FIncrementalSearching;
	System::UnicodeString FIncrementalSearchText;
	bool FInCancel;
	bool FInLoadStorage;
	bool FInNotifyControl;
	bool FInOnSortingChanged;
	bool FInternalFindRecord;
	bool FIsDetailExpanding;
	bool FIsPattern;
	bool FIsPatternSave;
	bool FInSetCustomDataSource;
	bool FInSmartLoad;
	System::Classes::TList* FListenerLinks;
	bool FLoadedStorage;
	int FLockGridModeNotifyCount;
	int FLockUpdateFieldsCount;
	bool FUpdateFieldsFlag;
	int FNewItemRecordIndex;
	bool FNewItemRowFocused;
	int FMasterRecordIndex;
	TcxCustomDataRelation* FMasterRelation;
	bool FMultiSelect;
	TcxDataControllerMultiThreadedOptions* FMultiThreadedOptions;
	TcxDataControllerNotifier* FNotifier;
	TcxDataControllerOptions FOptions;
	System::Classes::TComponent* FOwner;
	TcxDataSelectionChangedInfo FPrevSelectionChangedInfo;
	TcxCustomDataProvider* FProvider;
	TcxCustomDataField* FRecordHandlesField;
	bool FRecreatingLinkObject;
	TcxCustomDataRelationList* FRelations;
	int FSavedInternalRecordIndex;
	System::TObject* FSaveObject;
	int FSaveObjectLockCount;
	TcxDataControllerSearch* FSearch;
	TcxDataSelectionChangedInfo FSelectionChangedInfo;
	bool FSortingBySummaryChangedFlag;
	TcxCustomDataField* FSortingBySummaryDataItemField;
	bool FSortingChangedFlag;
	bool FStructureChanged;
	bool FStructureRecreated;
	TcxDataSummary* FSummary;
	bool FUpdateItems;
	bool FUseNewItemRowForEditing;
	TcxDataControllerNotifyEvent FOnAfterCancel;
	TcxDataControllerNotifyEvent FOnAfterDelete;
	TcxDataControllerNotifyEvent FOnAfterInsert;
	TcxDataControllerNotifyEvent FOnAfterPost;
	TcxDataControllerNotifyEvent FOnBeforeCancel;
	TcxDataDetailExpandedEvent FOnBeforeDelete;
	TcxDataControllerNotifyEvent FOnBeforeImmediatePost;
	TcxDataControllerNotifyEvent FOnBeforeInsert;
	TcxDataControllerNotifyEvent FOnBeforePost;
	TcxDataFilterRecordEvent FOnFilterRecord;
	TcxDataDetailExpandedEvent FOnNewRecord;
	TcxDataControllerCompareEvent FOnCompare;
	System::Classes::TNotifyEvent FOnDataChanged;
	TcxDataDetailExpandingEvent FOnDetailCollapsing;
	TcxDataDetailExpandedEvent FOnDetailCollapsed;
	TcxDataDetailExpandingEvent FOnDetailExpanding;
	TcxDataDetailExpandedEvent FOnDetailExpanded;
	System::Classes::TNotifyEvent FOnGroupingChanged;
	TcxDataRecordChangedEvent FOnRecordChanged;
	System::Classes::TNotifyEvent FOnSortingChanged;
	TcxUpdateControlEvent FOnUpdateControl;
	bool __fastcall FilterIterationStep(void * AContext, int ARecordIndex);
	TcxCustomDataSource* __fastcall GetCustomDataSource(void);
	TcxDataControllerDetailMode __fastcall GetDetailMode(void);
	int __fastcall GetFilteredIndexByRecordIndex(int Index);
	int __fastcall GetFilteredRecordCount(void);
	int __fastcall GetFilteredRecordIndex(int Index);
	bool __fastcall GetIsEditing(void);
	bool __fastcall GetIsPattern(void);
	int __fastcall GetLockCount(void);
	bool __fastcall GetNewItemRowFocused(void);
	TcxDataControllerOptions __fastcall GetOptions(void);
	TcxCustomDataRelationList* __fastcall GetRelations(void);
	int __fastcall GetSortingBySummaryDataItemIndex(void);
	void __fastcall SetCustomDataSource(TcxCustomDataSource* Value);
	void __fastcall SetIsPattern(bool Value);
	void __fastcall SetFilter(TcxDataFilterCriteria* Value);
	void __fastcall SetFocusedRowIndex(int Value);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetMultiThreadedOptions(TcxDataControllerMultiThreadedOptions* Value);
	void __fastcall SetNewItemRowFocused(bool Value);
	void __fastcall SetOnFilterRecord(TcxDataFilterRecordEvent Value);
	void __fastcall SetOptions(TcxDataControllerOptions Value);
	void __fastcall SetSummary(TcxDataSummary* Value);
	void __fastcall SetUseNewItemRowForEditing(bool Value);
	void __fastcall SetSortingBySummaryDataItemIndex(int Value);
	void __fastcall Update(void);
	void __fastcall BeforeGroupingNotification(void);
	void __fastcall BookmarkNotification(void);
	void __fastcall DataNotification(void);
	void __fastcall GridModeChanged(void);
	void __fastcall GroupingChanged(void);
	void __fastcall FocusedNotification(void);
	void __fastcall LayoutNotification(void);
	void __fastcall SearchNotification(void);
	void __fastcall SelectionNotification(void);
	void __fastcall SortingBySummaryChanged(void);
	void __fastcall SortingChanged(void);
	void __fastcall NotifyListenerLinks(void);
	void __fastcall ResetDataChangeInfo(void);
	void __fastcall UpdateRecordNotification(void);
	
protected:
	TcxDataChangeInfo FDataChangeInfo;
	bool FInDeleteSelection;
	bool FInFocusDetails;
	int FNearestRecordIndex;
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual TcxCustomDataField* __fastcall AddInternalField(void);
	virtual TcxCustomDataField* __fastcall AddField(void);
	virtual int __fastcall AppendInSmartLoad(void);
	bool __fastcall AreFieldValuesEqual(int ARecordIndex1, int ARecordIndex2, System::Classes::TList* AFields);
	virtual void __fastcall BeforeSorting(void);
	virtual int __fastcall CalcEditingRecordIndex(void);
	virtual bool __fastcall CanChangeDetailExpanding(int ARecordIndex, bool AExpanded);
	virtual bool __fastcall CanFocusRecord(int ARecordIndex);
	virtual bool __fastcall CanSelectRow(int ARowIndex);
	void __fastcall CheckChanges(void);
	void __fastcall Change(TcxDataControllerChanges AChanges);
	virtual void __fastcall CheckBookmarkValid(int ADeletedRecordIndex);
	virtual void __fastcall CheckDataSetCurrent(void);
	virtual void __fastcall CheckEditingRecordIndex(int ARecordIndex);
	void __fastcall CheckInternalRecordRange(int ARecordIndex);
	void __fastcall CheckItemRange(int AItemIndex);
	virtual bool __fastcall CheckDetailsBrowseMode(void);
	virtual bool __fastcall CheckMasterBrowseMode(void);
	void __fastcall CheckMode(void);
	void __fastcall CheckNearestFocusRow(void);
	void __fastcall CheckRange(int ARecordIndex, int AItemIndex);
	void __fastcall CheckRecordRange(int ARecordIndex);
	void __fastcall CheckSelectedCount(int ADeletedRecordIndex);
	void __fastcall ClearDataChangedListeners(void);
	void __fastcall ClearDetailsMasterRelation(TcxCustomDataRelation* ARelation);
	int __fastcall CompareIntegers(void * AItem1, void * AItem2);
	virtual void __fastcall CopyRecord(int AFromRecordIndex, int AToRecordIndex);
	virtual void __fastcall CorrectAfterInsert(int ARecordIndex);
	virtual void __fastcall CorrectAfterDelete(int ARecordIndex);
	void __fastcall CorrectPrevSelectionChangedInfo(void);
	virtual TcxCustomDataControllerInfo* __fastcall CreateDataControllerInfo(void);
	virtual void __fastcall DeleteInSmartLoad(int ARecordIndex);
	void __fastcall NotifyControl(TcxUpdateControlInfo* AUpdateControlInfo);
	virtual void __fastcall Unlocked(void);
	void __fastcall CancelIncrementalSearch(void);
	virtual void __fastcall DoAfterCancel(void);
	virtual void __fastcall DoAfterDelete(void);
	virtual void __fastcall DoAfterInsert(void);
	virtual void __fastcall DoAfterPost(void);
	virtual void __fastcall DoBeforeCancel(void);
	virtual void __fastcall DoBeforeDelete(int ARecordIndex);
	virtual void __fastcall DoBeforeImmediatePost(void);
	virtual void __fastcall DoBeforeInsert(void);
	virtual void __fastcall DoBeforePost(void);
	virtual void __fastcall DoGridModeChanged(void);
	virtual void __fastcall DoGroupingChanged(void);
	virtual bool __fastcall DoFilterRecord(int ARecordIndex);
	void __fastcall DoFilterRecordList(Dxcoreclasses::TdxFastList* ARecordList);
	virtual void __fastcall DoNewRecord(int ARecordIndex);
	bool __fastcall DoChangeDetailExpanding(TcxDetailObject* ADetailObject, int ARecordIndex, bool AExpanded);
	virtual void __fastcall DoDataChanged(void);
	virtual void __fastcall DoDetailExpanding(int ARecordIndex, bool &AAllow);
	virtual void __fastcall DoDetailExpanded(int ARecordIndex);
	virtual void __fastcall DoDetailCollapsing(int ARecordIndex, bool &AAllow);
	virtual void __fastcall DoDetailCollapsed(int ARecordIndex);
	virtual bool __fastcall DoIncrementalFilterRecord(int ARecordIndex);
	virtual void __fastcall DoReadRecord(int ARecordIndex);
	virtual bool __fastcall DoSearchInGridMode(const System::UnicodeString ASubText, bool AForward, bool ANext);
	virtual void __fastcall DoSortingChanged(void);
	virtual System::TObject* __fastcall FindItemByInternalID(int AID);
	virtual System::TObject* __fastcall FindItemByName(const System::UnicodeString AName);
	virtual System::TObject* __fastcall FindProperItemLink(System::TObject* AItemLink);
	virtual int __fastcall GetActiveRecordIndex(void);
	virtual bool __fastcall GetClearDetailsOnCollapse(void);
	virtual TcxCustomDataProviderClass __fastcall GetDataProviderClass(void);
	virtual int __fastcall GetDataRowCount(void);
	virtual TcxDataSelectionClass __fastcall GetDataSelectionClass(void);
	virtual TcxDataControllerEditOperations __fastcall GetEditOperations(void);
	virtual TcxDataControllerEditState __fastcall GetEditState(void);
	virtual int __fastcall GetDefaultActiveRelationIndex(void);
	virtual TcxCustomDataFieldClass __fastcall GetFieldClass(void);
	virtual TcxDataFilterCriteriaClass __fastcall GetFilterCriteriaClass(void);
	virtual int __fastcall GetFocusedDataRowIndex(void);
	virtual TcxDataControllerGroupsClass __fastcall GetGroupsClass(void);
	virtual System::UnicodeString __fastcall GetInternalDisplayText(int ARecordIndex, TcxCustomDataField* AField);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual System::UnicodeString __fastcall GetItemName(System::TObject* AItem);
	virtual System::Variant __fastcall GetInternalRecordId(int ARecordIndex, System::Classes::TList* AFieldList);
	virtual System::Variant __fastcall GetInternalValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual void __fastcall GetKeyFields(System::Classes::TList* AList);
	int __fastcall GetLastRecordIndex(void);
	virtual TcxDataControllerMultiThreadedOptionsClass __fastcall GetMultiThreadedOptionsClass(void);
	virtual int __fastcall GetRecordIndex(void);
	virtual TcxCustomDataRelationClass __fastcall GetRelationClass(void);
	virtual TcxDataControllerSearchClass __fastcall GetSearchClass(void);
	System::UnicodeString __fastcall GetStoredDisplayText(int ARecordIndex, TcxCustomDataField* AField);
	System::Variant __fastcall GetStoredValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual TcxDataSummaryClass __fastcall GetSummaryClass(void);
	virtual TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	virtual TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass(void);
	virtual bool __fastcall HasRecordFilter(void);
	virtual bool __fastcall InternalCheckBookmark(int ADeletedRecordIndex);
	virtual void __fastcall InternalClearBookmark(void);
	virtual void __fastcall InternalGotoBookmark(void);
	virtual bool __fastcall InternalSaveBookmark(void);
	bool __fastcall IsDataBound(void);
	bool __fastcall IsDataChangedListenersExist(void);
	virtual bool __fastcall IsDataField(TcxCustomDataField* AField);
	virtual bool __fastcall IsDestroying(void);
	virtual bool __fastcall IsFocusedSelectedMode(void);
	virtual bool __fastcall IsKeyNavigation(void);
	virtual bool __fastcall IsLoading(void);
	virtual bool __fastcall IsProviderDataSource(void);
	bool __fastcall IsRecordID(void);
	virtual bool __fastcall IsSmartLoad(void);
	virtual bool __fastcall IsSmartRefresh(void);
	virtual bool __fastcall IsUnboundMode(void);
	virtual void __fastcall LoadStorage(void);
	bool __fastcall IsNewItemRecordIndex(int ARecordIndex);
	virtual bool __fastcall LockOnAfterSummary(void);
	void __fastcall NotifyDataChangedListeners(void);
	virtual void __fastcall NotifyDataControllers(void);
	virtual void __fastcall PrepareField(TcxCustomDataField* AField);
	virtual void __fastcall PrepareFieldForSorting(TcxCustomDataField* AField, TcxDataControllerComparisonMode AMode);
	virtual void __fastcall ProviderValueDefSetProc(Cxdatastorage::TcxValueDef* AValueDef, int AFromRecordIndex, int AToRecordIndex, Cxdatastorage::TcxValueDefReader* AValueDefReader);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	virtual void __fastcall ResetFieldAfterSorting(TcxCustomDataField* AField);
	void __fastcall ResetMasterHasChildrenFlag(void);
	void __fastcall ResetNewItemRowFocused(void);
	virtual void __fastcall RestructData(void);
	void __fastcall SetStoredValue(int ARecordIndex, TcxCustomDataField* AField, const System::Variant &Value);
	virtual bool __fastcall SyncDetailsFocusWithMaster(void);
	virtual void __fastcall SyncMasterPos(void);
	virtual void __fastcall UpdateFields(void);
	virtual void __fastcall UpdateFocused(void);
	virtual void __fastcall UpdateRelations(TcxCustomDataRelation* ARelation);
	void __fastcall UpdateUseRecordIDState(void);
	void __fastcall UpdateStorage(bool AUpdateFields);
	virtual bool __fastcall UseRecordID(void);
	__classmethod TcxDataListenerLink* __fastcall AddListenerLink(TcxCustomDataController* ADataController);
	__classmethod void __fastcall RemoveListenerLink(TcxDataListenerLink* ALink);
	virtual void __fastcall DataStorageClearInternalRecords(System::TObject* Sender);
	virtual void __fastcall RemoveField(TcxCustomDataField* ADataField);
	virtual void __fastcall FilterChanged(void);
	virtual void __fastcall SummaryChanged(bool ARedrawOnly);
	virtual void __fastcall ActiveChanged(bool AActive);
	virtual void __fastcall DataChanged(TcxDataChange ADataChange, int AItemIndex, int ARecordIndex);
	virtual void __fastcall DataScrolled(int ADistance);
	virtual void __fastcall LayoutChanged(TcxDataLayoutChanges ADataLayoutChanges);
	virtual void __fastcall CustomDataSourceChanged(void);
	virtual void __fastcall DoBeforeFocusedRowChange(int ARowIndex);
	virtual void __fastcall DoValueTypeClassChanged(int AItemIndex);
	virtual void __fastcall UpdateControl(TcxUpdateControlInfo* AInfo);
	virtual System::UnicodeString __fastcall GetIncrementalSearchText(int ARecordIndex, int AItemIndex);
	virtual bool __fastcall GetIsRowInfoValid(void);
	virtual System::UnicodeString __fastcall GetFilterDisplayText(int ARecordIndex, int AItemIndex);
	virtual int __fastcall CompareByField(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField, TcxDataControllerComparisonMode AMode);
	virtual int __fastcall CompareEqualRecords(int ARecordIndex1, int ARecordIndex2);
	virtual int __fastcall CompareRecords(int ARecordIndex1, int ARecordIndex2, const TcxDataSortInfo &ASortInfo, TcxDataControllerComparisonMode AMode = (TcxDataControllerComparisonMode)(0x2));
	int __fastcall FindGroupRecord(int ABufferRecordIndex, int AGroupItemCount, bool AIsGroupDataSorted);
	virtual int __fastcall FindRecordByFields(int ABufferRecordIndex, System::Classes::TList* AFields);
	virtual System::Variant __fastcall GetComparedValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::UnicodeString __fastcall GetGroupRowDisplayText(const TcxRowInfo &ARowInfo, int &AItemIndex);
	virtual System::Variant __fastcall GetGroupRowValue(const TcxRowInfo &ARowInfo, int AItemIndex);
	virtual bool __fastcall IsConversionNeededForCompare(TcxCustomDataField* AField);
	virtual bool __fastcall IsFilterItemSortByDisplayText(int AItemIndex);
	virtual bool __fastcall IsStringConversionNeeded(TcxCustomDataField* AField);
	virtual bool __fastcall IsSortByDisplayTextNeeded(TcxCustomDataField* AField);
	int __fastcall NativeCompare(int ARecordIndex1, int ARecordIndex2, TcxCustomDataField* AField);
	void __fastcall DeleteFocusedRecord(void);
	void __fastcall DeleteRecords(System::Classes::TList* AList);
	virtual void __fastcall BeginSmartLoad(void);
	virtual void __fastcall EndSmartLoad(void);
	virtual int __fastcall LoadRecord(void * AData);
	virtual void __fastcall BeginReadRecord(void);
	virtual void __fastcall EndReadRecord(void);
	virtual TcxSortingBySummaryEngineClass __fastcall GetSortingBySummaryEngineClass(void);
	void __fastcall LockStateInfo(bool AUseLockedUpdate = true);
	void __fastcall UnlockStateInfo(bool AUseLockedUpdate = true);
	virtual bool __fastcall GetAnsiSortSetting(void);
	virtual bool __fastcall GetCaseInsensitiveSetting(void);
	virtual bool __fastcall GetAssignGroupingValuesSetting(void);
	virtual bool __fastcall GetAssignMasterDetailKeysSetting(void);
	virtual bool __fastcall GetSaveExpandingSetting(void);
	virtual bool __fastcall GetSortByDisplayTextSetting(void);
	virtual bool __fastcall GetFocusTopRowAfterSortingSetting(void);
	virtual bool __fastcall GetGroupsAlwaysExpandedSetting(void);
	virtual bool __fastcall GetImmediatePostSetting(void);
	virtual bool __fastcall GetInsertOnNewItemRowFocusingSetting(void);
	virtual bool __fastcall IsMultiThreadedFiltering(void);
	virtual bool __fastcall IsMultiThreadedSorting(void);
	virtual bool __fastcall IsMultiThreadedSummary(void);
	virtual void __fastcall PopulateFilterValues(TcxDataFilterValueList* AList, int AItemIndex, Cxfilter::TcxFilterCriteria* ACriteria, bool &AUseFilteredRecords, /* out */ bool &ANullExists);
	__property bool FilterChangedFlag = {read=FFilterChangedFlag, write=FFilterChangedFlag, nodefault};
	__property bool GroupingChangedFlag = {read=FGroupingChangedFlag, write=FGroupingChangedFlag, nodefault};
	__property bool InNotifyControl = {read=FInNotifyControl, nodefault};
	__property bool LoadedStorage = {read=FLoadedStorage, write=FLoadedStorage, nodefault};
	__property bool SortingBySummaryChangedFlag = {read=FSortingBySummaryChangedFlag, write=FSortingBySummaryChangedFlag, nodefault};
	__property bool SortingChangedFlag = {read=FSortingChangedFlag, write=FSortingChangedFlag, nodefault};
	__property Cxdatastorage::TcxDataStorage* DataStorage = {read=FDataStorage};
	__property TcxCustomDataFieldList* Fields = {read=FFields};
	__property TcxDataControllerNotifier* Notifier = {read=FNotifier};
	__property System::Classes::TComponent* Owner = {read=FOwner};
	__property TcxCustomDataProvider* Provider = {read=FProvider};
	__property int LockUpdateFieldsCount = {read=FLockUpdateFieldsCount, nodefault};
	
public:
	__fastcall virtual TcxCustomDataController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomDataController(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BeforeDestruction(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall BeginFullUpdate(void);
	virtual void __fastcall EndFullUpdate(void);
	void __fastcall BeginUpdateFields(void);
	void __fastcall EndUpdateFields(void);
	void __fastcall SaveKeys(void);
	void __fastcall RestoreKeys(void);
	virtual TcxDataFilterCriteria* __fastcall CreateFilter(void);
	virtual TcxSummaryKinds __fastcall GetAllowedSummaryKinds(Cxdatastorage::TcxValueTypeClass ATypeClass)/* overload */;
	virtual TcxSummaryKinds __fastcall GetAllowedSummaryKinds(int AItemIndex)/* overload */;
	virtual TcxSummaryKinds __fastcall GetAllowedSummaryKinds(TcxCustomDataField* AField)/* overload */;
	virtual bool __fastcall IsImmediatePost(void);
	virtual bool __fastcall IsProviderMode(void);
	virtual TcxCustomDataField* __fastcall AddItem(System::TObject* AItem);
	virtual bool __fastcall ItemPropertiesChanged(int AItemIndex);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall RemoveItem(System::TObject* AItem);
	virtual void __fastcall UpdateItemIndexes(void);
	virtual void __fastcall UpdateItems(bool AUpdateFields);
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	void __fastcall AddDataChangedListener(System::TObject* AInstance, System::Classes::TNotifyEvent ADataChangedEvent);
	void __fastcall RemoveDataChangedListener(System::TObject* AInstance, System::Classes::TNotifyEvent ADataChangedEvent);
	void __fastcall AddDataChangeRefCount(void);
	void __fastcall RemoveDataChangeRefCount(void);
	virtual bool __fastcall DataChangedNotifyLocked(void);
	bool __fastcall IsDataLoading(void);
	void __fastcall LockDataChangedNotify(void);
	void __fastcall UnlockDataChangedNotify(void);
	void __fastcall LockGridModeNotify(void);
	void __fastcall UnlockGridModeNotify(void);
	virtual void __fastcall ChangeNeedConversion(int AItemIndex, bool ANeedConversion);
	virtual void __fastcall ChangeTextStored(int AItemIndex, bool ATextStored);
	virtual void __fastcall ChangeValueTypeClass(int AItemIndex, Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	virtual System::TObject* __fastcall GetItem(int Index) = 0 ;
	virtual int __fastcall GetItemCount(void);
	virtual bool __fastcall GetItemNeedConversion(int AItemIndex);
	virtual bool __fastcall GetItemTextStored(int AItemIndex);
	Cxdatastorage::TcxValueTypeClass __fastcall GetItemValueTypeClass(int AItemIndex);
	virtual bool __fastcall IsDisplayFormatDefined(int AItemIndex, bool AIgnoreSimpleCurrency);
	virtual int __fastcall AppendRecord(void);
	void __fastcall DeleteRecord(int ARecordIndex);
	virtual System::Variant __fastcall GetGroupValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual void __fastcall GetGroupValues(int ARecordIndex, TcxDataSummaryValues &AValues);
	virtual System::UnicodeString __fastcall GetDisplayText(int ARecordIndex, int AItemIndex);
	virtual int __fastcall GetRecordCount(void);
	virtual System::Variant __fastcall GetRecordId(int ARecordIndex);
	virtual System::Variant __fastcall GetValue(int ARecordIndex, int AItemIndex);
	virtual int __fastcall InsertRecord(int ARecordIndex);
	virtual void __fastcall Refresh(void);
	virtual void __fastcall SetDisplayText(int ARecordIndex, int AItemIndex, const System::UnicodeString Value);
	virtual void __fastcall SetRecordCount(int Value);
	virtual void __fastcall SetValue(int ARecordIndex, int AItemIndex, const System::Variant &Value);
	void __fastcall SortByDisplayTextChanged(void);
	virtual void __fastcall Append(void);
	virtual void __fastcall Cancel(void);
	virtual bool __fastcall CanInitEditing(int AItemIndex);
	virtual void __fastcall CheckBrowseMode(void);
	virtual void __fastcall DeleteFocused(void);
	virtual void __fastcall DeleteSelection(void);
	virtual void __fastcall Edit(void);
	virtual void __fastcall FocusControl(int AItemIndex, bool &Done);
	virtual System::Variant __fastcall GetEditValue(int AItemIndex, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual void __fastcall Insert(void);
	virtual void __fastcall Post(bool AForcePost = false);
	virtual void __fastcall PostEditingData(void);
	virtual void __fastcall RefreshExternalData(void);
	virtual bool __fastcall SetEditValue(int AItemIndex, const System::Variant &AValue, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual void __fastcall UpdateData(void);
	virtual int __fastcall GetEditingRecordIndex(void);
	virtual int __fastcall GetNewItemRecordIndex(void);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	virtual TcxCustomDataController* __fastcall GetMasterDataController(void);
	virtual int __fastcall GetMasterRecordIndex(void);
	virtual TcxCustomDataRelation* __fastcall GetMasterRelation(void);
	TcxCustomDataController* __fastcall GetPatternDataController(void);
	TcxCustomDataController* __fastcall GetRootDataController(void);
	virtual bool __fastcall IsDetailMode(void);
	virtual System::TObject* __fastcall CreateDetailLinkObject(TcxCustomDataRelation* ARelation, int ARecordIndex);
	void __fastcall FocusDetails(int ARecordIndex);
	virtual TcxCustomDataController* __fastcall GetDetailDataControllerByLinkObject(System::TObject* ALinkObject);
	virtual void __fastcall ResetRelationByItem(System::TObject* AItem);
	void __fastcall SetMasterMode(TcxCustomDataRelation* AMasterRelation, bool AIsPattern);
	virtual void __fastcall SetMasterRelation(TcxCustomDataRelation* AMasterRelation, int AMasterRecordIndex);
	void __fastcall ChangeDetailActiveRelationIndex(int ARecordIndex, int ARelationIndex);
	bool __fastcall ChangeDetailExpanding(int ARecordIndex, bool AExpanded);
	void __fastcall ClearDetailLinkObject(int ARecordIndex, int ARelationIndex);
	void __fastcall ClearDetails(void);
	void __fastcall CollapseDetails(void);
	void __fastcall ForEachDetail(TcxCustomDataRelation* AMasterRelation, TcxDataControllerEachDetailProc AProc);
	int __fastcall GetDetailActiveRelationIndex(int ARecordIndex);
	TcxCustomDataController* __fastcall GetDetailDataController(int ARecordIndex, int ARelationIndex);
	bool __fastcall GetDetailExpanding(int ARecordIndex);
	bool __fastcall GetDetailHasChildren(int ARecordIndex, int ARelationIndex);
	System::TObject* __fastcall GetDetailLinkObject(int ARecordIndex, int ARelationIndex);
	bool __fastcall IsDetailDataControllerExist(int ARecordIndex, int ARelationIndex);
	void __fastcall ResetHasChildrenFlag(void);
	virtual void __fastcall ForEachRow(bool ASelectedRows, TcxDataControllerEachRowProc AProc);
	int __fastcall GetNearestRowIndex(int ARowIndex);
	int __fastcall GetRowCount(void);
	int __fastcall GetRowIndexByRecordIndex(int ARecordIndex, bool AMakeVisible);
	TcxRowInfo __fastcall GetRowInfo(int ARowIndex);
	System::UnicodeString __fastcall GetRowDisplayText(const TcxRowInfo &ARowInfo, int &AItemIndex);
	System::Variant __fastcall GetRowValue(const TcxRowInfo &ARowInfo, int AItemIndex);
	void __fastcall MakeRecordVisible(int ARecordIndex);
	virtual bool __fastcall FocusSelectedRow(int ASelectedIndex);
	virtual void __fastcall RestoreDataSetPos(void);
	virtual void __fastcall SaveDataSetPos(void);
	void __fastcall ChangeFocusedRecordIndex(int ARecordIndex);
	virtual bool __fastcall ChangeFocusedRowIndex(int ARowIndex);
	void __fastcall CheckFocusedRow(void);
	int __fastcall GetFocusedRecordIndex(void);
	int __fastcall GetFocusedRowIndex(void);
	void __fastcall GotoFirst(void);
	void __fastcall GotoLast(void);
	void __fastcall GotoNext(void);
	void __fastcall GotoPrev(void);
	bool __fastcall IsBOF(void);
	bool __fastcall IsEOF(void);
	bool __fastcall IsGridMode(void);
	void __fastcall MoveBy(int ADistance);
	void __fastcall Scroll(int ADistance);
	virtual void __fastcall SetFocus(void);
	void __fastcall ClearBookmark(void);
	void __fastcall GotoBookmark(void);
	virtual bool __fastcall IsBookmarkAvailable(void);
	virtual bool __fastcall IsBookmarkRow(int ARowIndex);
	void __fastcall SaveBookmark(void);
	virtual System::Variant __fastcall GetFilterDataValue(int ARecordIndex, TcxCustomDataField* AField);
	virtual System::UnicodeString __fastcall GetFilterItemFieldCaption(System::TObject* AItem);
	virtual System::UnicodeString __fastcall GetFilterItemFieldName(System::TObject* AItem);
	bool __fastcall ChangeIncrementalFilterText(const System::UnicodeString AText);
	virtual int __fastcall FindRecordIndexByText(int AStartRecordIndex, int AItemIndex, const System::UnicodeString AText, bool APartialCompare, bool ACircular, bool AForward);
	virtual System::UnicodeString __fastcall GetIncrementalFilterText(void);
	virtual bool __fastcall HasIncrementalFilter(void);
	virtual void __fastcall ResetIncrementalFilter(void);
	virtual int __fastcall SetIncrementalFilter(int AItemIndex, const System::UnicodeString AText);
	void __fastcall ChangeItemSortingIndex(int AItemIndex, int ASortingIndex);
	void __fastcall ChangeSorting(int AItemIndex, Dxcore::TdxSortOrder ASortOrder);
	void __fastcall ClearSorting(bool AKeepGroupedItems);
	virtual bool __fastcall GetItemSortByDisplayText(int AItemIndex, bool ASortByDisplayText);
	Dxcore::TdxSortOrder __fastcall GetItemSortOrder(int AItemIndex);
	int __fastcall GetItemSortingIndex(int AItemIndex);
	int __fastcall GetSortingItemCount(void);
	int __fastcall GetSortingItemIndex(int Index);
	virtual void __fastcall ChangeRowSelection(int ARowIndex, bool ASelection);
	void __fastcall CheckFocusedSelected(void);
	void __fastcall ClearSelection(void);
	virtual void __fastcall ClearSelectionAnchor(void);
	virtual System::Variant __fastcall GetRowId(int ARowIndex);
	int __fastcall GetSelectedCount(void);
	virtual int __fastcall GetSelectedRowIndex(int Index);
	virtual int __fastcall GetSelectionAnchorRowIndex(void);
	bool __fastcall IsRowSelected(int ARowIndex);
	virtual bool __fastcall IsSelectionAnchorExist(void);
	virtual void __fastcall SelectAll(void);
	virtual void __fastcall SelectFromAnchor(int ARowIndex, bool AKeepSelection);
	void __fastcall SelectRows(int AStartRowIndex, int AEndRowIndex);
	virtual void __fastcall SetSelectionAnchor(int ARowIndex);
	void __fastcall SyncSelected(bool ASelected);
	virtual void __fastcall SyncSelectionFocusedRecord(void);
	__property bool Active = {read=FActive, nodefault};
	__property TcxCustomDataSource* CustomDataSource = {read=GetCustomDataSource, write=SetCustomDataSource};
	__property TcxCustomDataControllerInfo* DataControllerInfo = {read=FDataControllerInfo};
	__property int DataRowCount = {read=GetDataRowCount, nodefault};
	__property TcxDataControllerDetailMode DetailMode = {read=GetDetailMode, nodefault};
	__property System::UnicodeString DisplayTexts[int RecordIndex][int ItemIndex] = {read=GetDisplayText, write=SetDisplayText};
	__property TcxDataControllerGroups* Groups = {read=FGroups};
	__property int EditingRecordIndex = {read=GetEditingRecordIndex, nodefault};
	__property TcxDataControllerEditOperations EditOperations = {read=GetEditOperations, nodefault};
	__property TcxDataControllerEditState EditState = {read=GetEditState, nodefault};
	__property TcxDataFilterCriteria* Filter = {read=FFilter, write=SetFilter};
	__property int FilteredIndexByRecordIndex[int Index] = {read=GetFilteredIndexByRecordIndex};
	__property int FilteredRecordCount = {read=GetFilteredRecordCount, nodefault};
	__property int FilteredRecordIndex[int Index] = {read=GetFilteredRecordIndex};
	__property int FocusedDataRowIndex = {read=GetFocusedDataRowIndex, nodefault};
	__property int FocusedRecordIndex = {read=GetFocusedRecordIndex, write=ChangeFocusedRecordIndex, nodefault};
	__property int FocusedRowIndex = {read=GetFocusedRowIndex, write=SetFocusedRowIndex, nodefault};
	__property bool IsCreatingLinkObject = {read=FCreatingLinkObject, nodefault};
	__property bool IsDetailExpanding = {read=FIsDetailExpanding, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property bool IsPattern = {read=GetIsPattern, write=SetIsPattern, nodefault};
	__property bool IsRowInfoValid = {read=GetIsRowInfoValid, nodefault};
	__property bool IsUpdatingItems = {read=FUpdateItems, nodefault};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property int LockCount = {read=GetLockCount, nodefault};
	__property int LockGridModeNotifyCount = {read=FLockGridModeNotifyCount, nodefault};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, nodefault};
	__property TcxDataControllerMultiThreadedOptions* MultiThreadedOptions = {read=FMultiThreadedOptions, write=SetMultiThreadedOptions};
	__property int NewItemRecordIndex = {read=GetNewItemRecordIndex, nodefault};
	__property bool NewItemRowFocused = {read=GetNewItemRowFocused, write=SetNewItemRowFocused, nodefault};
	__property TcxDataControllerOptions Options = {read=GetOptions, write=SetOptions, default=28};
	__property int RecordCount = {read=GetRecordCount, write=SetRecordCount, nodefault};
	__property TcxCustomDataRelationList* Relations = {read=GetRelations};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property TcxDataControllerSearch* Search = {read=FSearch};
	__property TcxDataSummary* Summary = {read=FSummary, write=SetSummary};
	__property bool UseNewItemRowForEditing = {read=FUseNewItemRowForEditing, write=SetUseNewItemRowForEditing, nodefault};
	__property System::Variant Values[int RecordIndex][int ItemIndex] = {read=GetValue, write=SetValue};
	__property int SortingBySummaryDataItemIndex = {read=GetSortingBySummaryDataItemIndex, write=SetSortingBySummaryDataItemIndex, nodefault};
	__property TcxDataControllerNotifyEvent OnAfterCancel = {read=FOnAfterCancel, write=FOnAfterCancel};
	__property TcxDataControllerNotifyEvent OnAfterDelete = {read=FOnAfterDelete, write=FOnAfterDelete};
	__property TcxDataControllerNotifyEvent OnAfterInsert = {read=FOnAfterInsert, write=FOnAfterInsert};
	__property TcxDataControllerNotifyEvent OnAfterPost = {read=FOnAfterPost, write=FOnAfterPost};
	__property TcxDataControllerNotifyEvent OnBeforeCancel = {read=FOnBeforeCancel, write=FOnBeforeCancel};
	__property TcxDataDetailExpandedEvent OnBeforeDelete = {read=FOnBeforeDelete, write=FOnBeforeDelete};
	__property TcxDataControllerNotifyEvent OnBeforeImmediatePost = {read=FOnBeforeImmediatePost, write=FOnBeforeImmediatePost};
	__property TcxDataControllerNotifyEvent OnBeforeInsert = {read=FOnBeforeInsert, write=FOnBeforeInsert};
	__property TcxDataControllerNotifyEvent OnBeforePost = {read=FOnBeforePost, write=FOnBeforePost};
	__property TcxDataFilterRecordEvent OnFilterRecord = {read=FOnFilterRecord, write=SetOnFilterRecord};
	__property TcxDataDetailExpandedEvent OnNewRecord = {read=FOnNewRecord, write=FOnNewRecord};
	__property TcxDataControllerCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	__property System::Classes::TNotifyEvent OnDataChanged = {read=FOnDataChanged, write=FOnDataChanged};
	__property TcxDataDetailExpandingEvent OnDetailCollapsing = {read=FOnDetailCollapsing, write=FOnDetailCollapsing};
	__property TcxDataDetailExpandedEvent OnDetailCollapsed = {read=FOnDetailCollapsed, write=FOnDetailCollapsed};
	__property TcxDataDetailExpandingEvent OnDetailExpanding = {read=FOnDetailExpanding, write=FOnDetailExpanding};
	__property TcxDataDetailExpandedEvent OnDetailExpanded = {read=FOnDetailExpanded, write=FOnDetailExpanded};
	__property System::Classes::TNotifyEvent OnGroupingChanged = {read=FOnGroupingChanged, write=FOnGroupingChanged};
	__property TcxDataRecordChangedEvent OnRecordChanged = {read=FOnRecordChanged, write=FOnRecordChanged};
	__property System::Classes::TNotifyEvent OnSortingChanged = {read=FOnSortingChanged, write=FOnSortingChanged};
	__property TcxUpdateControlEvent OnUpdateControl = {read=FOnUpdateControl, write=FOnUpdateControl};
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};


typedef System::TMetaClass* TcxCustomDataControllerClass;

class DELPHICLASS TcxCustomDataHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDataHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod Cxdatastorage::TcxValueDef* __fastcall GetValueDef(TcxCustomDataField* AField)/* overload */;
	__classmethod Cxdatastorage::TcxValueDef* __fastcall GetValueDef(TcxCustomDataController* ADataController, int AIndex)/* overload */;
	__classmethod void __fastcall SetTextStored(TcxCustomDataField* AField, bool ATextStored);
public:
	/* TObject.Create */ inline __fastcall TcxCustomDataHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomDataHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool dxDefaultMultiThreadedFiltering;
extern PACKAGE bool dxDefaultMultiThreadedSorting;
static const int cxNullEditingRecordIndex = int(-2147483647);
extern PACKAGE System::Byte cxDataFilterVersion;
extern PACKAGE void __fastcall InvalidOperation(const System::UnicodeString S);
extern PACKAGE System::UnicodeString __fastcall cxDataGetDataSummaryValueDefaultFormat(TcxSummaryValueType AValueType, TcxSummaryKind ASummaryKind, bool AIsFooter);
}	/* namespace Cxcustomdata */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCUSTOMDATA)
using namespace Cxcustomdata;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcustomdataHPP
