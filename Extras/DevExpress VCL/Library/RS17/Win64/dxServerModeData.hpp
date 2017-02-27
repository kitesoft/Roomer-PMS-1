// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeData.pas' rev: 24.00 (Win64)

#ifndef DxservermodedataHPP
#define DxservermodedataHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDBFilter.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <dxServerModeClasses.hpp>	// Pascal unit
#include <dxServerModeHelpers.hpp>	// Pascal unit
#include <dxServerModeUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodedata
{
//-- type declarations -------------------------------------------------------
enum TdxNullsSortOrder : unsigned char { nsoFirstIfDesc, nsoFirstIfAsc };

typedef Data::Db::_di_IProviderSupportNG IdxProviderSupport;

class DELPHICLASS TdxServerModeCriteriaItem;
class DELPHICLASS TdxServerModeDescriptor;
class DELPHICLASS TdxServerModeCriteria;
class PASCALIMPLEMENTATION TdxServerModeCriteriaItem : public Cxfilter::TcxFilterCriteriaItem
{
	typedef Cxfilter::TcxFilterCriteriaItem inherited;
	
private:
	TdxServerModeDescriptor* FDescriptor;
	Data::Db::TField* __fastcall GetField(void);
	TdxServerModeCriteria* __fastcall InternalGetCriteria(void);
	
protected:
	virtual System::UnicodeString __fastcall GetFieldCaption(void);
	virtual System::UnicodeString __fastcall GetFieldName(void);
	virtual Cxfilter::TcxFilterOperatorClass __fastcall GetFilterOperatorClass(void);
	virtual void __fastcall ReadData(System::Classes::TStream* AStream);
	virtual void __fastcall WriteData(System::Classes::TStream* AStream);
	
public:
	virtual bool __fastcall IsEmpty(void);
	__property TdxServerModeCriteria* Criteria = {read=InternalGetCriteria};
	__property TdxServerModeDescriptor* Descriptor = {read=FDescriptor};
	__property Data::Db::TField* Field = {read=GetField};
public:
	/* TcxFilterCriteriaItem.Create */ inline __fastcall virtual TdxServerModeCriteriaItem(Cxfilter::TcxFilterCriteriaItemList* AOwner, System::TObject* AItemLink, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue) : Cxfilter::TcxFilterCriteriaItem(AOwner, AItemLink, AOperatorKind, AValue, ADisplayValue) { }
	/* TcxFilterCriteriaItem.Destroy */ inline __fastcall virtual ~TdxServerModeCriteriaItem(void) { }
	
};


class DELPHICLASS TdxServerModeCriteriaItemList;
class PASCALIMPLEMENTATION TdxServerModeCriteriaItemList : public Cxfilter::TcxFilterCriteriaItemList
{
	typedef Cxfilter::TcxFilterCriteriaItemList inherited;
	
public:
	TdxServerModeCriteriaItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxServerModeCriteriaItem* __fastcall GetItem(int Index);
	
public:
	void __fastcall Assign(TdxServerModeCriteriaItemList* Source);
	void __fastcall AssignItems(TdxServerModeCriteriaItemList* Source);
	__property TdxServerModeCriteriaItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxFilterCriteriaItemList.Create */ inline __fastcall virtual TdxServerModeCriteriaItemList(Cxfilter::TcxFilterCriteriaItemList* AOwner, Cxfilter::TcxFilterBoolOperatorKind ABoolOperatorKind) : Cxfilter::TcxFilterCriteriaItemList(AOwner, ABoolOperatorKind) { }
	/* TcxFilterCriteriaItemList.Destroy */ inline __fastcall virtual ~TdxServerModeCriteriaItemList(void) { }
	
};


typedef void __fastcall (__closure *TdxServerModeCriteriaGetValueEvent)(Cxfilter::TcxFilterCriteriaItem* AItem, const System::Variant &AValue, System::UnicodeString &ADisplayValue);

typedef void __fastcall (__closure *TdxServerModeCriteriaGetFieldCaptionEvent)(TdxServerModeCriteriaItem* AItem, System::UnicodeString &AFieldCaption);

class DELPHICLASS TdxServerModeCustomDataSource;
class PASCALIMPLEMENTATION TdxServerModeCriteria : public Cxfilter::TcxFilterCriteria
{
	typedef Cxfilter::TcxFilterCriteria inherited;
	
private:
	TdxServerModeCustomDataSource* FDataSource;
	TdxServerModeCriteriaGetFieldCaptionEvent FOnGetFieldCaption;
	TdxServerModeCriteriaGetValueEvent FOnGetValue;
	TdxServerModeCriteriaItemList* __fastcall GetRoot(void);
	
protected:
	void __fastcall DoGetFieldCaption(TdxServerModeCriteriaItem* AItem, System::UnicodeString &AFieldCaption);
	virtual void __fastcall FormatFilterTextValue(Cxfilter::TcxFilterCriteriaItem* AItem, const System::Variant &AValue, System::UnicodeString &ADisplayValue);
	virtual int __fastcall GetIDByItemLink(System::TObject* AItemLink);
	virtual System::TObject* __fastcall GetItemLinkByID(int AID);
	virtual Cxfilter::TcxFilterCriteriaItemClass __fastcall GetItemClass(void);
	virtual Cxfilter::TcxFilterCriteriaItemListClass __fastcall GetItemListClass(void);
	virtual Cxfilter::TcxFilterCriteriaItemListClass __fastcall GetRootClass(void);
	void __fastcall Operation(TdxServerModeCriteria* Value, Cxfilter::TcxFilterBoolOperatorKind AOperator, bool ADestroyValue);
	__property TdxServerModeCriteriaGetFieldCaptionEvent OnGetFieldCaption = {read=FOnGetFieldCaption, write=FOnGetFieldCaption};
	__property TdxServerModeCriteriaGetValueEvent OnGetValue = {read=FOnGetValue, write=FOnGetValue};
	
public:
	__fastcall virtual TdxServerModeCriteria(TdxServerModeCustomDataSource* ADataSource);
	HIDESBASE virtual TdxServerModeCriteriaItem* __fastcall AddItem(TdxServerModeDescriptor* ADescriptor, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue)/* overload */;
	HIDESBASE virtual TdxServerModeCriteriaItem* __fastcall AddItem(Cxfilter::TcxFilterCriteriaItemList* AParent, TdxServerModeDescriptor* ADescriptor, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue)/* overload */;
	void __fastcall AndCriteria(TdxServerModeCriteria* Value, bool ADestroyValue = false);
	void __fastcall OrCriteria(TdxServerModeCriteria* Value, bool ADestroyValue = false);
	TdxServerModeCriteria* __fastcall Clone(void);
	bool __fastcall IsEqual(TdxServerModeCriteria* AValue);
	__property TdxServerModeCustomDataSource* DataSource = {read=FDataSource};
	__property TdxServerModeCriteriaItemList* Root = {read=GetRoot};
public:
	/* TcxFilterCriteria.Destroy */ inline __fastcall virtual ~TdxServerModeCriteria(void) { }
	
};


typedef System::TMetaClass* TdxServerModeCriteriaClass;

enum TdxServerModeDescriptorChangeType : unsigned char { dctLink, dctSorting, dctSummaryKind };

typedef System::Set<TdxServerModeDescriptorChangeType, TdxServerModeDescriptorChangeType::dctLink, TdxServerModeDescriptorChangeType::dctSummaryKind>  TdxServerModeDescriptorChanges;

enum TdxDateTimeGrouping : unsigned char { dgDefault, dgByDateAndTime, dgRelativeToToday, dgByHour, dgByDate, dgByWeekDay, dgByMonth, dgByYear };

class DELPHICLASS TdxServerModeDescriptors;
class PASCALIMPLEMENTATION TdxServerModeDescriptor : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxServerModeDescriptorChanges FChanges;
	Dxcoreclasses::TdxFastList* FLinks;
	TdxDateTimeGrouping FDateTimeGrouping;
	int FLockCount;
	TdxServerModeDescriptor* FLinkedObject;
	TdxServerModeDescriptors* FOwner;
	TdxServerModeDescriptor* __fastcall GetLink(int Index);
	int __fastcall GetLinkCount(void);
	int __fastcall GetIndex(void);
	void __fastcall SetDateTimeGrouping(TdxDateTimeGrouping Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetOwner(TdxServerModeDescriptors* Value);
	void __fastcall SetLinkedObject(TdxServerModeDescriptor* Value);
	
protected:
	virtual void __fastcall Changed(TdxServerModeDescriptorChanges AChanges = TdxServerModeDescriptorChanges() );
	virtual void __fastcall DoAssign(TdxServerModeDescriptor* Source);
	virtual Data::Db::TField* __fastcall GetField(void);
	void __fastcall AddLink(TdxServerModeDescriptor* ALink);
	void __fastcall ClearLinks(void);
	void __fastcall RemoveLink(TdxServerModeDescriptor* ALink);
	void __fastcall BeginUpdate(void);
	bool __fastcall IsLocked(void);
	void __fastcall EndUpdate(void);
	bool __fastcall IsDateTimeGrouping(void);
	virtual bool __fastcall IsDistinct(void);
	virtual bool __fastcall IsSorting(void);
	virtual bool __fastcall IsSummary(void);
	__property int LinkCount = {read=GetLinkCount, nodefault};
	__property TdxServerModeDescriptor* Links[int Index] = {read=GetLink};
	
public:
	__fastcall virtual TdxServerModeDescriptor(void);
	__fastcall virtual ~TdxServerModeDescriptor(void);
	void __fastcall Assign(TdxServerModeDescriptor* Source);
	TdxServerModeDescriptor* __fastcall Clone(void);
	virtual bool __fastcall IsEqual(TdxServerModeDescriptor* AValue);
	virtual System::UnicodeString __fastcall ToString(void);
	__property TdxDateTimeGrouping DateTimeGrouping = {read=FDateTimeGrouping, write=SetDateTimeGrouping, nodefault};
	__property Data::Db::TField* Field = {read=GetField};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property TdxServerModeDescriptors* Owner = {read=FOwner, write=SetOwner};
	__property TdxServerModeDescriptor* LinkedObject = {read=FLinkedObject, write=SetLinkedObject};
};


typedef System::TMetaClass* TdxServerModeDescriptorClass;

typedef void __fastcall (__closure *TdxServerModeDescriptorsChangedEvent)(TdxServerModeDescriptors* Sender, TdxServerModeDescriptor* AItem, TdxServerModeDescriptorChanges AChanges);

class PASCALIMPLEMENTATION TdxServerModeDescriptors : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxServerModeDescriptor* operator[](int Index) { return Items[Index]; }
	
private:
	TdxServerModeCustomDataSource* FDataSource;
	Dxcoreclasses::TdxFastObjectList* FList;
	TdxServerModeDescriptorsChangedEvent FOnChanged;
	int __fastcall GetCount(void);
	TdxServerModeDescriptor* __fastcall GetItem(int Index);
	
protected:
	void __fastcall AddItem(TdxServerModeDescriptor* AItem);
	void __fastcall RemoveItem(TdxServerModeDescriptor* AItem);
	virtual void __fastcall DoChanged(TdxServerModeDescriptor* AItem, TdxServerModeDescriptorChanges AChanges);
	virtual TdxServerModeDescriptorClass __fastcall GetDescriptorClass(void);
	__property Dxcoreclasses::TdxFastObjectList* List = {read=FList};
	
public:
	__fastcall TdxServerModeDescriptors(TdxServerModeCustomDataSource* ADataSource);
	__fastcall virtual ~TdxServerModeDescriptors(void);
	void __fastcall Assign(TdxServerModeDescriptors* Source);
	virtual TdxServerModeDescriptor* __fastcall Add(Data::Db::TField* AField)/* overload */;
	void __fastcall AddItems(TdxServerModeDescriptors* AList);
	TdxServerModeDescriptor* __fastcall CreateLink(TdxServerModeDescriptor* ALinkedObject);
	void __fastcall CreateLinks(TdxServerModeDescriptors* AList);
	void __fastcall Clear(void);
	TdxServerModeDescriptors* __fastcall Clone(void);
	bool __fastcall Contains(Data::Db::TField* AField);
	int __fastcall IndexOf(Data::Db::TField* AField)/* overload */;
	int __fastcall IndexOf(TdxServerModeDescriptor* AItem)/* overload */;
	bool __fastcall IsEmpty(void);
	virtual bool __fastcall IsEqual(TdxServerModeDescriptors* AValue);
	void __fastcall Remove(Data::Db::TField* AField)/* overload */;
	__property int Count = {read=GetCount, nodefault};
	__property TdxServerModeCustomDataSource* DataSource = {read=FDataSource};
	__property TdxServerModeDescriptor* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxServerModeDescriptorsChangedEvent OnChanged = {read=FOnChanged, write=FOnChanged};
};


typedef System::TMetaClass* TdxServerModeDescriptorsClass;

class DELPHICLASS TdxServerModeSummaryDescriptor;
class PASCALIMPLEMENTATION TdxServerModeSummaryDescriptor : public TdxServerModeDescriptor
{
	typedef TdxServerModeDescriptor inherited;
	
private:
	int FGroupLevel;
	Cxcustomdata::TcxSummaryKind FKind;
	bool FSorted;
	void __fastcall SetGroupLevel(int Value);
	void __fastcall SetKind(Cxcustomdata::TcxSummaryKind Value);
	void __fastcall SetSorted(bool Value);
	
protected:
	virtual void __fastcall DoAssign(TdxServerModeDescriptor* Source);
	virtual bool __fastcall IsSummary(void);
	
public:
	__fastcall virtual TdxServerModeSummaryDescriptor(void)/* overload */;
	__fastcall TdxServerModeSummaryDescriptor(Cxcustomdata::TcxSummaryKind AKind)/* overload */;
	virtual bool __fastcall IsEqual(TdxServerModeDescriptor* AValue);
	__property int GroupLevel = {read=FGroupLevel, write=SetGroupLevel, nodefault};
	__property Cxcustomdata::TcxSummaryKind Kind = {read=FKind, write=SetKind, nodefault};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
public:
	/* TdxServerModeDescriptor.Destroy */ inline __fastcall virtual ~TdxServerModeSummaryDescriptor(void) { }
	
};


class DELPHICLASS TdxServerModeSummaryDescriptors;
class PASCALIMPLEMENTATION TdxServerModeSummaryDescriptors : public TdxServerModeDescriptors
{
	typedef TdxServerModeDescriptors inherited;
	
public:
	TdxServerModeSummaryDescriptor* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxServerModeSummaryDescriptor* __fastcall GetItem(int Index);
	
protected:
	virtual TdxServerModeDescriptorClass __fastcall GetDescriptorClass(void);
	
public:
	HIDESBASE virtual TdxServerModeSummaryDescriptor* __fastcall Add(Data::Db::TField* AField, Cxcustomdata::TcxSummaryKind AKind)/* overload */;
	HIDESBASE virtual TdxServerModeSummaryDescriptor* __fastcall Add(const System::UnicodeString AFieldName, Cxcustomdata::TcxSummaryKind AKind)/* overload */;
	HIDESBASE TdxServerModeSummaryDescriptors* __fastcall Clone(void);
	bool __fastcall IsGroupLevelSorted(int AGroupLevel);
	__property TdxServerModeSummaryDescriptor* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxServerModeDescriptors.Create */ inline __fastcall TdxServerModeSummaryDescriptors(TdxServerModeCustomDataSource* ADataSource) : TdxServerModeDescriptors(ADataSource) { }
	/* TdxServerModeDescriptors.Destroy */ inline __fastcall virtual ~TdxServerModeSummaryDescriptors(void) { }
	
/* Hoisted overloads: */
	
public:
	inline TdxServerModeDescriptor* __fastcall  Add(Data::Db::TField* AField){ return TdxServerModeDescriptors::Add(AField); }
	
};


typedef System::TMetaClass* TdxServerModeSummaryDescriptorsClass;

class DELPHICLASS TdxServerModeGroupInfoDescriptor;
class PASCALIMPLEMENTATION TdxServerModeGroupInfoDescriptor : public TdxServerModeDescriptor
{
	typedef TdxServerModeDescriptor inherited;
	
public:
	virtual bool __fastcall IsEqual(TdxServerModeDescriptor* AValue);
public:
	/* TdxServerModeDescriptor.Create */ inline __fastcall virtual TdxServerModeGroupInfoDescriptor(void) : TdxServerModeDescriptor() { }
	/* TdxServerModeDescriptor.Destroy */ inline __fastcall virtual ~TdxServerModeGroupInfoDescriptor(void) { }
	
};


class DELPHICLASS TdxServerModeGroupInfoDescriptors;
class PASCALIMPLEMENTATION TdxServerModeGroupInfoDescriptors : public TdxServerModeDescriptors
{
	typedef TdxServerModeDescriptors inherited;
	
public:
	TdxServerModeGroupInfoDescriptor* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxServerModeGroupInfoDescriptor* __fastcall GetItem(int Index);
	
public:
	__property TdxServerModeGroupInfoDescriptor* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxServerModeDescriptors.Create */ inline __fastcall TdxServerModeGroupInfoDescriptors(TdxServerModeCustomDataSource* ADataSource) : TdxServerModeDescriptors(ADataSource) { }
	/* TdxServerModeDescriptors.Destroy */ inline __fastcall virtual ~TdxServerModeGroupInfoDescriptors(void) { }
	
};


typedef System::TMetaClass* TdxServerModeGroupInfoDescriptorsClass;

class DELPHICLASS TdxServerModeSortInfoDescriptor;
class PASCALIMPLEMENTATION TdxServerModeSortInfoDescriptor : public TdxServerModeGroupInfoDescriptor
{
	typedef TdxServerModeGroupInfoDescriptor inherited;
	
private:
	bool FIsDesc;
	bool FIsKey;
	bool __fastcall GetIsDesc(void);
	void __fastcall SetIsDesc(bool Value);
	
protected:
	void __fastcall CheckGroupValue(System::Variant &AValue, bool AIsGroupValue);
	virtual void __fastcall DoAssign(TdxServerModeDescriptor* Source);
	virtual bool __fastcall IsSorting(void);
	
public:
	__fastcall TdxServerModeSortInfoDescriptor(bool AIsDesc, bool AIsKey);
	virtual bool __fastcall IsEqual(TdxServerModeDescriptor* AValue);
	__property bool IsDesc = {read=GetIsDesc, write=SetIsDesc, nodefault};
	__property bool IsKey = {read=FIsKey, nodefault};
public:
	/* TdxServerModeDescriptor.Destroy */ inline __fastcall virtual ~TdxServerModeSortInfoDescriptor(void) { }
	
};


class DELPHICLASS TdxServerModeSortInfoDescriptors;
class PASCALIMPLEMENTATION TdxServerModeSortInfoDescriptors : public TdxServerModeGroupInfoDescriptors
{
	typedef TdxServerModeGroupInfoDescriptors inherited;
	
public:
	TdxServerModeSortInfoDescriptor* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxServerModeSortInfoDescriptor* __fastcall GetItem(int Index);
	int __fastcall GetWithoutKeySortInfoCount(void);
	
protected:
	HIDESBASE TdxServerModeSortInfoDescriptor* __fastcall Add(Data::Db::TField* AField, bool AIsDesc, bool AIsKey)/* overload */;
	TdxServerModeSortInfoDescriptor* __fastcall AddKeySortInfo(Data::Db::TField* AField, bool AIsDesc);
	virtual TdxServerModeDescriptorClass __fastcall GetDescriptorClass(void);
	
public:
	HIDESBASE TdxServerModeSortInfoDescriptor* __fastcall Add(Data::Db::TField* AField, bool AIsDesc)/* overload */;
	HIDESBASE TdxServerModeSortInfoDescriptor* __fastcall Add(const System::UnicodeString AFieldName, bool AIsDesc)/* overload */;
	void __fastcall ClearKeySortInfo(void);
	HIDESBASE TdxServerModeSortInfoDescriptors* __fastcall Clone(bool AReversed);
	__property TdxServerModeSortInfoDescriptor* Items[int Index] = {read=GetItem/*, default*/};
	__property int WithoutKeySortInfoCount = {read=GetWithoutKeySortInfoCount, nodefault};
public:
	/* TdxServerModeDescriptors.Create */ inline __fastcall TdxServerModeSortInfoDescriptors(TdxServerModeCustomDataSource* ADataSource) : TdxServerModeGroupInfoDescriptors(ADataSource) { }
	/* TdxServerModeDescriptors.Destroy */ inline __fastcall virtual ~TdxServerModeSortInfoDescriptors(void) { }
	
/* Hoisted overloads: */
	
public:
	inline TdxServerModeDescriptor* __fastcall  Add(Data::Db::TField* AField){ return TdxServerModeDescriptors::Add(AField); }
	
};


typedef System::TMetaClass* TdxServerModeSortInfoDescriptorsClass;

class DELPHICLASS TdxServerModeFieldDescriptor;
class PASCALIMPLEMENTATION TdxServerModeFieldDescriptor : public TdxServerModeDescriptor
{
	typedef TdxServerModeDescriptor inherited;
	
private:
	Data::Db::TField* FField;
	bool FDistinct;
	
protected:
	virtual void __fastcall DoAssign(TdxServerModeDescriptor* Source);
	virtual Data::Db::TField* __fastcall GetField(void);
	virtual bool __fastcall IsDistinct(void);
	
public:
	__property bool Distinct = {read=FDistinct, write=FDistinct, nodefault};
public:
	/* TdxServerModeDescriptor.Create */ inline __fastcall virtual TdxServerModeFieldDescriptor(void) : TdxServerModeDescriptor() { }
	/* TdxServerModeDescriptor.Destroy */ inline __fastcall virtual ~TdxServerModeFieldDescriptor(void) { }
	
};


class DELPHICLASS TdxServerModeFieldDescriptors;
class PASCALIMPLEMENTATION TdxServerModeFieldDescriptors : public TdxServerModeDescriptors
{
	typedef TdxServerModeDescriptors inherited;
	
public:
	TdxServerModeFieldDescriptor* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxServerModeFieldDescriptor* __fastcall GetItem(int Index);
	
protected:
	virtual TdxServerModeDescriptorClass __fastcall GetDescriptorClass(void);
	
public:
	virtual TdxServerModeDescriptor* __fastcall Add(Data::Db::TField* AField)/* overload */;
	Data::Db::TField* __fastcall FieldByName(const System::UnicodeString AFieldName);
	int __fastcall IndexByName(const System::UnicodeString AFieldName);
	TdxServerModeDescriptor* __fastcall ItemByField(Data::Db::TField* AField);
	__property TdxServerModeFieldDescriptor* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxServerModeDescriptors.Create */ inline __fastcall TdxServerModeFieldDescriptors(TdxServerModeCustomDataSource* ADataSource) : TdxServerModeDescriptors(ADataSource) { }
	/* TdxServerModeDescriptors.Destroy */ inline __fastcall virtual ~TdxServerModeFieldDescriptors(void) { }
	
};


class DELPHICLASS TdxServerModeStateInfo;
class DELPHICLASS TdxServerModeCache;
class PASCALIMPLEMENTATION TdxServerModeStateInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxServerModeSortInfoDescriptors* FSortInfo;
	int FGroupCount;
	
public:
	__fastcall TdxServerModeStateInfo(int AGroupCount, TdxServerModeSortInfoDescriptors* ASortInfo);
	__fastcall virtual ~TdxServerModeStateInfo(void);
	int __fastcall GetMaxEqualDepth(TdxServerModeCache* ACache);
	__property int GroupCount = {read=FGroupCount, nodefault};
	__property TdxServerModeSortInfoDescriptors* SortInfo = {read=FSortInfo};
};


typedef void __fastcall (__closure *TdxServerModeInconsistencyDetectedEvent)(TdxServerModeCache* Sender, const System::UnicodeString AMessage);

typedef void __fastcall (__closure *TdxServerModeExceptionThrownEvent)(TdxServerModeCache* Sender, System::Sysutils::Exception* AException);

class PASCALIMPLEMENTATION TdxServerModeCache : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxServerModeCustomDataSource* FDataSource;
	bool FIsLanded;
	Dxservermodeclasses::TdxServerModeGroupInfo* FTopGroupInfo;
	TdxServerModeExceptionThrownEvent FOnExceptionThrown;
	TdxServerModeInconsistencyDetectedEvent FOnInconsistencyDetected;
	void __fastcall CalculateTotalSummaries(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo);
	void __fastcall CheckTopGroupInfo(TdxServerModeStateInfo* APrevStateInfo);
	Dxservermodeclasses::TdxServerModeGroupInfo* __fastcall CreateTopGroupInfo(void);
	void __fastcall FillChildrenIfNeeded(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo);
	TdxServerModeCriteria* __fastcall GetFilter(void);
	int __fastcall GetGroupCount(void);
	TdxServerModeFieldDescriptors* __fastcall GetKeyFields(void);
	TdxServerModeSortInfoDescriptors* __fastcall GetSortInfo(void);
	TdxServerModeSummaryDescriptors* __fastcall GetSummaries(void);
	TdxServerModeSummaryDescriptors* __fastcall GetTotalSummaries(void);
	Dxservermodeclasses::TdxServerModeGroupInfoData* __fastcall PrepareTopGroupInfoWithTrick(TdxServerModeSummaryDescriptors* ASummaries);
	
protected:
	bool __fastcall CanTrickCreateTopGroupFromNextGroups(void);
	virtual System::Variant __fastcall EvaluateOnInstance(const System::Variant &ARow, Data::Db::TField* AField);
	virtual void __fastcall Fatal(System::Sysutils::Exception* AException);
	virtual int __fastcall GetCount(TdxServerModeCriteria* ACriteria);
	TdxServerModeCriteria* __fastcall GetGroupWhere(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo);
	virtual int __fastcall GetInternalCount(void);
	Dxservermodeclasses::TdxServerModeGroupInfo* __fastcall GetTopGroupInfo(void);
	void __fastcall MakeStrongClause(TdxServerModeCriteria* ACriteria, Cxfilter::TcxFilterCriteriaItemList* AParentList, TdxServerModeDescriptor* ADescriptor, bool AIsDesc, bool ACanEqual, const System::Variant &AValue)/* overload */;
	void __fastcall MakeStrongClause(TdxServerModeCriteria* ACriteria, Cxfilter::TcxFilterCriteriaItemList* AParentList, TdxServerModeSortInfoDescriptor* ASortInfoDescriptor, const System::Variant &AValue)/* overload */;
	virtual Dxservermodeclasses::TdxServerModeGroupInfoDataList* __fastcall PrepareChildren(TdxServerModeCriteria* AGroupWhere, TdxServerModeSortInfoDescriptor* AGroupByDescriptor, TdxServerModeSummaryDescriptors* ASummaries);
	virtual int __fastcall PrepareTopGroupCount(void);
	virtual Dxservermodeclasses::TdxServerModeGroupInfoData* __fastcall PrepareTopGroupInfo(TdxServerModeSummaryDescriptors* ASummaries);
	void __fastcall RaiseInconsistencyDetected(const System::UnicodeString AFormat, System::TVarRec *Args, const int Args_Size)/* overload */;
	void __fastcall RaiseInconsistencyDetected(const System::UnicodeString AMessage)/* overload */;
	__property bool IsLanded = {read=FIsLanded, nodefault};
	
public:
	__fastcall virtual TdxServerModeCache(TdxServerModeCustomDataSource* ADataSource);
	__fastcall virtual ~TdxServerModeCache(void);
	virtual void __fastcall Clear(void);
	void __fastcall ClearGroupInfo(void);
	void __fastcall ClearTopGroupInfo(void);
	Dxservermodeclasses::TdxServerModeGroupInfoList* __fastcall GetGroupInfoList(Dxservermodeclasses::TdxServerModeGroupInfo* AParentGroup);
	Dxservermodeclasses::TdxServerModeSummaryList* __fastcall GetTotalSummary(void);
	bool __fastcall IsNothingButCount(TdxServerModeSummaryDescriptors* ASummaries);
	void __fastcall RecalculateSummaries(void);
	virtual void __fastcall SoftReset(void);
	virtual bool __fastcall Contains(const System::Variant &AValue) = 0 ;
	virtual System::Variant __fastcall GetKeyFromRow(const System::Variant &ARow);
	virtual int __fastcall GetRowIndexByKey(const System::Variant &AKey) = 0 ;
	virtual System::Variant __fastcall GetRowKey(int AIndex) = 0 ;
	virtual System::Variant __fastcall Indexer(int ARecordIndex) = 0 ;
	virtual int __fastcall IndexOf(const System::Variant &AValue) = 0 ;
	__property int Count = {read=GetInternalCount, nodefault};
	__property TdxServerModeCustomDataSource* DataSource = {read=FDataSource};
	__property TdxServerModeCriteria* Filter = {read=GetFilter};
	__property int GroupCount = {read=GetGroupCount, nodefault};
	__property TdxServerModeFieldDescriptors* KeyFields = {read=GetKeyFields};
	__property TdxServerModeSortInfoDescriptors* SortInfo = {read=GetSortInfo};
	__property TdxServerModeSummaryDescriptors* Summaries = {read=GetSummaries};
	__property Dxservermodeclasses::TdxServerModeGroupInfo* TopGroupInfo = {read=GetTopGroupInfo};
	__property TdxServerModeSummaryDescriptors* TotalSummaries = {read=GetTotalSummaries};
	__property TdxServerModeExceptionThrownEvent OnExceptionThrown = {read=FOnExceptionThrown, write=FOnExceptionThrown};
	__property TdxServerModeInconsistencyDetectedEvent OnInconsistencyDetected = {read=FOnInconsistencyDetected, write=FOnInconsistencyDetected};
};


typedef System::TMetaClass* TdxServerModeCacheClass;

class DELPHICLASS TdxServerModeKeyedCache;
class PASCALIMPLEMENTATION TdxServerModeKeyedCache : public TdxServerModeCache
{
	typedef TdxServerModeCache inherited;
	
private:
	Dxservermodeclasses::TdxServerModeKeysDictionary* FKeysByIndex;
	int FLastUsedRecordIndex;
	System::Variant FLastUsedRow;
	Dxservermodehelpers::TdxServerModeServerAndChannelModelBuilder* FRegressor;
	Dxservermodeclasses::TdxServerModeRowsDictionary* FRowsByIndex;
	Dxservermodehelpers::TdxServerModeServerAndChannelModel* FSafeModel;
	Dxservermodeclasses::TdxNullableBoolean ActualFetchRowsIsGood;
	Dxservermodeclasses::TdxNullableBoolean UseTakeEnforcer;
	void __fastcall FetchRowsAll(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo);
	void __fastcall FetchRowsTop(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, bool AIsFromBottom, int ATop);
	bool __fastcall FindFromCache(int ARecordIndex, System::Variant &ARow);
	int __fastcall GetCountBeforeRow(const System::Variant &ARow, Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, TdxServerModeSortInfoDescriptors* ASortInfo);
	Dxservermodeclasses::TdxServerModeGroupInfo* __fastcall GetGroupForKeysFetchingAround(int Index);
	double __fastcall GetMagicNumberAllowedSlowerThenBase(void);
	double __fastcall GetMagicNumberAllowedSlowerThenBaseVariance(void);
	int __fastcall GetMagicNumberFetchKeysTopPenaltyGap(void);
	int __fastcall GetMagicNumberTakeKeysBase(void);
	virtual int __fastcall GetMaxInSize(void);
	void __fastcall CalculateModel(int ARecordIndex, int APositionInGroup, Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, /* out */ int &ASkipTake, /* out */ int &ASkipSkip, /* out */ bool &ASkipIsFromBottom);
	void __fastcall CalculateTake(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, int AFetchCount, bool AIsFromBottom, /* out */ int &APureTake, /* out */ bool &APureTakeIsFromBottom);
	void __fastcall DoFetchKeys(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, bool AIsFromBottom, int ASkip, int ATake);
	void __fastcall DoFetchKeysSkipWithTakeBackup(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, bool ASkipIsFromBottom, int ASkipSkip, int ASkipTake, bool APureTakeIsFromBottom, int APureTake);
	Dxservermodeclasses::TdxServerModeKeyList* __fastcall FetchKeysTimed(TdxServerModeCriteria* AWhere, TdxServerModeSortInfoDescriptors* ASortInfo, int ASkip, int ATake);
	void __fastcall FillKeys(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, bool AIsFromBottom, int ASkip, int ATake, Dxservermodeclasses::TdxServerModeKeyList* AKeys);
	int __fastcall GetGlobalIndex(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, int APos, bool AIsReversed);
	void __fastcall PopulateDownKeysToFetch(Dxservermodeclasses::TdxServerModeKeyList* AKeysToFetch, Dxservermodeclasses::TdxServerModeLoadedKeysChunkDictionary* AIndexesByKeys, int ARecordIndex, int ASplitLen, /* out */ bool &AFillFromSplit);
	void __fastcall PopulateFetchKeys(Dxservermodeclasses::TdxServerModeGroupInfo* AGroupInfo, int APureTake, int ASkipSkip, int ASkipTake, bool ASkipIsFromBottom, bool APureTakeIsFromBottom);
	void __fastcall PopulateUpKeysToFetch(Dxservermodeclasses::TdxServerModeKeyList* AKeysToFetch, Dxservermodeclasses::TdxServerModeLoadedKeysChunkDictionary* AIndexesByKeys, int ARecordIndex, int AInSize);
	System::Variant __fastcall PopulateRowsByIndex(Dxservermodeclasses::TdxServerModeRowList* const ARows, Dxservermodeclasses::TdxServerModeLoadedKeysChunkDictionary* AIndexesByKeys, int AReturnRecordIndex);
	
protected:
	virtual bool __fastcall DecideIsFetchRowsGoodIdeaForSure(void);
	Dxservermodeclasses::TdxServerModeRowList* __fastcall FetchRowsByKeys(Dxservermodeclasses::TdxServerModeKeyList* AKeys);
	virtual int __fastcall GetMagicNumberFetchKeysAllThreshold(void);
	virtual int __fastcall GetMagicNumberFetchKeysModulo(void);
	virtual int __fastcall GetMagicNumberFetchRowsAllThreshold(void);
	virtual int __fastcall GetMagicNumberFetchRowsInSize(void);
	virtual int __fastcall GetMagicNumberFetchRowsTop(void);
	virtual int __fastcall GetMagicNumberFetchRowsTopThreshold(void);
	virtual int __fastcall GetMagicNumberScanKeysBase(void);
	virtual double __fastcall GetMagicNumberTakeIncreaseStepMultiplier(void);
	virtual int __fastcall GetMagicNumberTakeKeysUpperLimitAfterSkip(void);
	bool __fastcall IsFetchRowsGoodIdeaForSure(void);
	virtual Dxservermodeclasses::TdxKeyType __fastcall ResolveKeyType(TdxServerModeFieldDescriptors* ASingleKeyToResolve) = 0 ;
	virtual Dxservermodeclasses::TdxRowType __fastcall ResolveRowType(void) = 0 ;
	virtual Dxservermodeclasses::TdxServerModeKeyList* __fastcall FetchKeys(TdxServerModeCriteria* AWhere, TdxServerModeSortInfoDescriptors* ASortInfo, int ASkip, int ATake);
	virtual Dxservermodeclasses::TdxServerModeRowList* __fastcall FetchRows(TdxServerModeCriteria* AWhere, TdxServerModeSortInfoDescriptors* ASortInfo, int ATake)/* overload */;
	void __fastcall FetchRows(TdxServerModeCriteria* AWhere, int ATake, int AValidateCount, int AFirstRecord, bool AIsFromBottom)/* overload */;
	System::Variant __fastcall FetchRowByKey(const System::Variant &AKey);
	Dxservermodeclasses::TdxServerModeGroupInfo* __fastcall GetRowGroup(const System::Variant &ARow);
	virtual int __fastcall PrepareTopGroupCount(void);
	__property double MagicNumberAllowedSlowerThenBase = {read=GetMagicNumberAllowedSlowerThenBase};
	__property double MagicNumberAllowedSlowerThenBaseVariance = {read=GetMagicNumberAllowedSlowerThenBaseVariance};
	__property int MagicNumberFetchKeysAllThreshold = {read=GetMagicNumberFetchKeysAllThreshold, nodefault};
	__property int MagicNumberFetchKeysModulo = {read=GetMagicNumberFetchKeysModulo, nodefault};
	__property int MagicNumberFetchKeysTopPenaltyGap = {read=GetMagicNumberFetchKeysTopPenaltyGap, nodefault};
	__property int MagicNumberFetchRowsAllThreshold = {read=GetMagicNumberFetchRowsAllThreshold, nodefault};
	__property int MagicNumberFetchRowsInSize = {read=GetMagicNumberFetchRowsInSize, nodefault};
	__property int MagicNumberFetchRowsTop = {read=GetMagicNumberFetchRowsTop, nodefault};
	__property int MagicNumberFetchRowsTopThreshold = {read=GetMagicNumberFetchRowsTopThreshold, nodefault};
	__property int MagicNumberScanKeysBase = {read=GetMagicNumberScanKeysBase, nodefault};
	__property double MagicNumberTakeIncreaseStepMultiplier = {read=GetMagicNumberTakeIncreaseStepMultiplier};
	__property int MagicNumberTakeKeysBase = {read=GetMagicNumberTakeKeysBase, nodefault};
	__property int MagicNumberTakeKeysUpperLimitAfterSkip = {read=GetMagicNumberTakeKeysUpperLimitAfterSkip, nodefault};
	__property int MaxInSize = {read=GetMaxInSize, nodefault};
	__property Dxservermodehelpers::TdxServerModeServerAndChannelModelBuilder* Regressor = {read=FRegressor};
	__property Dxservermodehelpers::TdxServerModeServerAndChannelModel* SafeModel = {read=FSafeModel};
	__property Dxservermodeclasses::TdxServerModeKeysDictionary* KeysByIndex = {read=FKeysByIndex};
	__property Dxservermodeclasses::TdxServerModeRowsDictionary* RowsByIndex = {read=FRowsByIndex};
	
public:
	Dxservermodeclasses::TdxNullableBoolean FetchRowsIsGood;
	Dxservermodeclasses::TdxNullableBoolean ForceSkip;
	Dxservermodeclasses::TdxNullableBoolean ForceTake;
	bool MinimizeSingleRequestTransferSizeInsteadOfOverallOptimization;
	__fastcall virtual TdxServerModeKeyedCache(TdxServerModeCustomDataSource* ADataSource);
	__fastcall virtual ~TdxServerModeKeyedCache(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall SoftReset(void);
	bool __fastcall DecideIsFetchRowsGoodIdea(TdxServerModeSortInfoDescriptors* ASortInfo);
	virtual System::Variant __fastcall GetRowKey(int ARecordIndex);
	virtual System::Variant __fastcall Indexer(int ARecordIndex);
	virtual bool __fastcall Contains(const System::Variant &AValue);
	virtual int __fastcall GetRowIndexByKey(const System::Variant &AKey);
	virtual int __fastcall IndexOf(const System::Variant &AValue);
	bool __fastcall KeyEquals(const System::Variant &AKey1, const System::Variant &AKey2);
};


enum TdxServerModeDataSourceChangeType : unsigned char { ctConnection, ctCache, ctGroups, ctOptions, ctSummaries, ctTotalSummaries, ctSortingSummaries, ctFiltering, ctSorting };

typedef System::Set<TdxServerModeDataSourceChangeType, TdxServerModeDataSourceChangeType::ctConnection, TdxServerModeDataSourceChangeType::ctSorting>  TdxServerModeDataSourceChanges;

enum TdxSQLDatePart : unsigned char { dpYear, dpQuarter, dpMonth, dpDayOfYear, dpDay, dpWeekDay, dpWeek, dpHour, dpMinute, dpSecond, dpMillisecond, dpMicrosecond, dpNanosecond };

class DELPHICLASS TdxServerModeCustomSQLAdapter;
class PASCALIMPLEMENTATION TdxServerModeCustomSQLAdapter : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TdxServerModeCustomDataSource* FDataSource;
	
protected:
	void __fastcall Changed(const TdxServerModeDataSourceChanges AChanges = (TdxServerModeDataSourceChanges() << TdxServerModeDataSourceChangeType::ctOptions ));
	virtual void __fastcall CheckParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CheckRepeatedParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall CorrectCommandText(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	Data::Db::TParam* __fastcall CreateParam(Data::Db::TParams* AParams, const System::Variant &AValue, const Data::Db::TFieldType ADataType, System::UnicodeString &ADisplayValue);
	virtual bool __fastcall GetParamCheck(void);
	virtual System::UnicodeString __fastcall GetParamFakeNameFormat(void);
	virtual System::UnicodeString __fastcall GetParamFormat(void);
	virtual System::UnicodeString __fastcall GetParamNameFormat(void);
	virtual System::UnicodeString __fastcall GetParamServerFormat(void);
	virtual bool __fastcall IsMicrosecondSupported(void);
	virtual bool __fastcall IsMillisecondSupported(void);
	virtual bool __fastcall IsSkipClauseSupported(void);
	virtual TdxNullsSortOrder __fastcall GetNullsSortOrder(void);
	virtual void __fastcall RenameParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual void __fastcall SortParams(Data::Db::TParams* AParams, System::UnicodeString &ACommandText);
	virtual bool __fastcall CanIdentifyInsertingRow(void);
	virtual bool __fastcall CanUseResultFieldName(void);
	virtual bool __fastcall CanUseGroupingByDateRangeParams(void);
	virtual System::UnicodeString __fastcall ConvertBoolToStr(const System::Variant &AValue);
	virtual void __fastcall CheckFilterFieldCaption(System::UnicodeString &AFieldCaption, Cxfilter::TcxFilterOperatorKind AOperatorKind);
	virtual System::UnicodeString __fastcall DateDec(TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DateDiff(TdxSQLDatePart APart, const System::UnicodeString ADateExpression1, const System::UnicodeString ADateExpression2);
	virtual System::UnicodeString __fastcall DateInc(TdxSQLDatePart APart, const System::UnicodeString ADateExpression, const System::UnicodeString ADelta);
	virtual System::UnicodeString __fastcall DatePart(TdxSQLDatePart APart, const System::UnicodeString ADateExpression);
	System::UnicodeString __fastcall DateTimeToString(const System::TDateTime ADateTime);
	virtual System::UnicodeString __fastcall GetCastAsDateFormat(void);
	virtual System::UnicodeString __fastcall GetCastAsDateTimeFormat(void);
	virtual System::UnicodeString __fastcall GetCastAsTimeFormat(void);
	virtual System::UnicodeString __fastcall GetDatePart(TdxSQLDatePart APart);
	virtual System::UnicodeString __fastcall GetDateTimeFormat(void);
	System::UnicodeString __fastcall GetDateTimeGroupingResultFieldFormat(void);
	System::UnicodeString __fastcall GetDateTimeGroupingResultFieldName(Data::Db::TField* AField);
	virtual bool __fastcall IsDateRangeGroupingSupported(void);
	virtual System::UnicodeString __fastcall IsNull(const System::UnicodeString AExpression);
	virtual bool __fastcall NeedCastGroupingByDateRange(void);
	virtual System::UnicodeString __fastcall TruncGroupingDate(const System::UnicodeString ADate, TdxDateTimeGrouping ADateTimeGrouping);
	System::UnicodeString __fastcall GetCaseOperatorFormat(Cxfilter::TcxFilterOperatorKind AKind);
	virtual System::UnicodeString __fastcall GetCaseFullFormat(void);
	virtual System::WideChar __fastcall GetPercentWildcard(void);
	virtual System::WideChar __fastcall GetUnderscoreWildcard(void);
	System::UnicodeString __fastcall GetLikeValue(const System::Variant &AValue, System::WideChar APercentWildcard, System::WideChar AUnderscoreWildcard);
	virtual System::UnicodeString __fastcall GetDistinctFormat(void);
	virtual System::UnicodeString __fastcall GetFieldsRetrieveQueryFormat(void);
	virtual System::UnicodeString __fastcall GetFieldName(Data::Db::TField* AField);
	virtual System::UnicodeString __fastcall GetFieldNameFormat(void);
	virtual System::UnicodeString __fastcall GetFromQueryFormat(void);
	virtual System::UnicodeString __fastcall GetInsertingRowOutKey(const System::UnicodeString AKey);
	virtual System::UnicodeString __fastcall GetOrderFormat(bool AIsDesc);
	System::UnicodeString __fastcall GetServerFieldName(Data::Db::TField* AField);
	virtual System::UnicodeString __fastcall GetSummaryFormat(Cxcustomdata::TcxSummaryKind AKind);
	virtual System::UnicodeString __fastcall GetTableNameFormat(void);
	virtual System::UnicodeString __fastcall GetQuoteChar(void);
	virtual System::UnicodeString __fastcall GetDeleteSQLString(const System::UnicodeString AFrom, const System::UnicodeString AWhere);
	virtual System::UnicodeString __fastcall GetSelectSQLString(const System::UnicodeString AFields, const System::UnicodeString AFrom, const System::UnicodeString AWhere, const System::UnicodeString AGroup, const System::UnicodeString ASortInfo, int ATopRecords, int ASkipRecords);
	virtual System::UnicodeString __fastcall GetInsertSQLString(const System::UnicodeString AFrom, const System::UnicodeString AOutRowKey, const System::UnicodeString AFields, const System::UnicodeString AValues);
	virtual System::UnicodeString __fastcall GetUpdateSQLString(const System::UnicodeString AFrom, const System::UnicodeString AOutRowKey, const System::UnicodeString AValues, const System::UnicodeString AWhere);
	virtual System::UnicodeString __fastcall GetQueryFormat(void);
	__property bool ParamCheck = {read=GetParamCheck, nodefault};
	
public:
	__fastcall virtual TdxServerModeCustomSQLAdapter(TdxServerModeCustomDataSource* ADataSource);
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__classmethod virtual System::UnicodeString __fastcall GetDisplayName();
	virtual System::UnicodeString __fastcall GetSQLQueryKeyFieldNames(const System::UnicodeString ATableName);
	virtual System::UnicodeString __fastcall GetSQLQuerySchemaNames(void);
	__property TdxServerModeCustomDataSource* DataSource = {read=FDataSource};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeCustomSQLAdapter(void) { }
	
};


typedef System::TMetaClass* TdxServerModeCustomSQLAdapterClass;

enum TdxServerModeCustomQueryType : unsigned char { qtSelect, qtInsert, qtUpdate, qtDelete };

class DELPHICLASS TdxServerModeCustomSQLQueryBuilder;
class PASCALIMPLEMENTATION TdxServerModeCustomSQLQueryBuilder : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FCommandText;
	TdxServerModeCriteria* FCriteria;
	bool FCriteriaCalculating;
	TdxServerModeCustomDataSource* FDataSource;
	TdxServerModeDescriptors* FFields;
	bool FFieldsCalculating;
	TdxServerModeGroupInfoDescriptors* FGroupInfo;
	bool FGroupingByDateRangeCalculating;
	Data::Db::TParams* FParams;
	TdxServerModeSortInfoDescriptors* FSortInfo;
	bool FSortInfoCalculating;
	TdxServerModeSummaryDescriptors* FSummaries;
	int FSkipRecords;
	TdxServerModeCustomQueryType FQueryType;
	int FTopRecords;
	System::Variant FValues;
	void __fastcall CheckParams(void);
	TdxServerModeCustomSQLAdapter* __fastcall GetAdapter(void);
	void __fastcall GetFilterFieldCaptionHandler(TdxServerModeCriteriaItem* AItem, System::UnicodeString &AFieldCaption);
	void __fastcall GetFilterValueHandler(Cxfilter::TcxFilterCriteriaItem* AItem, const System::Variant &AValue, System::UnicodeString &ADisplayValue);
	void __fastcall SetCriteria(TdxServerModeCriteria* Value);
	
protected:
	virtual bool __fastcall CanCreateParam(const System::Variant &AValue);
	bool __fastcall CanDateTimeGrouping(TdxServerModeDescriptor* ADescriptor);
	bool __fastcall CanSorting(TdxServerModeDescriptor* ADescriptor);
	virtual bool __fastcall CanUseParams(void);
	virtual Data::Db::TParam* __fastcall CreateParam(const Data::Db::TFieldType ADataType, const System::Variant &AValue, System::UnicodeString &ADisplayValue);
	virtual Data::Db::TParam* __fastcall DoCreateParam(const Data::Db::TFieldType ADataType, const System::Variant &AValue, System::UnicodeString &ADisplayValue);
	virtual bool __fastcall GetParamCheck(void);
	bool __fastcall ValueToDisplayValue(const Data::Db::TFieldType ADataType, const System::Variant &AValue, System::UnicodeString &ADisplayValue);
	bool __fastcall CanCreateDateTimeParam(const System::TDateTime ADateTime);
	System::UnicodeString __fastcall CreateDateTimeParam(const System::TDateTime ADateTime);
	System::UnicodeString __fastcall DateTimeGroupingByRelativeToToday(const System::UnicodeString AFieldName);
	System::UnicodeString __fastcall GetGroupingStartDate(TdxDateTimeGrouping ADateTimeGrouping);
	System::UnicodeString __fastcall GroupingByDateRange(const System::UnicodeString AFieldName, TdxServerModeDescriptor* ADescriptor);
	virtual System::UnicodeString __fastcall GetFieldsSQLString(void);
	virtual System::UnicodeString __fastcall GetFromSQLString(void);
	virtual System::UnicodeString __fastcall GetGroupSQLString(void);
	virtual System::UnicodeString __fastcall GetInsertingRowOutKeys(void);
	virtual System::UnicodeString __fastcall GetSortInfoSQLString(void);
	virtual System::UnicodeString __fastcall GetWhereSQLString(void);
	virtual System::UnicodeString __fastcall GetValuesSQLString(void);
	System::UnicodeString __fastcall DescriptorToString(TdxServerModeDescriptor* ADescriptor);
	System::UnicodeString __fastcall DescriptorsToString(TdxServerModeDescriptors* ADescriptors);
	virtual System::UnicodeString __fastcall GetSQLString(void);
	void __fastcall CalculateQueryType(void);
	__property TdxServerModeCustomSQLAdapter* Adapter = {read=GetAdapter};
	__property bool ParamCheck = {read=GetParamCheck, nodefault};
	__property TdxServerModeCustomQueryType QueryType = {read=FQueryType, nodefault};
	
public:
	__fastcall virtual TdxServerModeCustomSQLQueryBuilder(TdxServerModeCustomDataSource* ADataSource);
	__fastcall virtual ~TdxServerModeCustomSQLQueryBuilder(void);
	void __fastcall Calculate(void);
	__property System::UnicodeString CommandText = {read=FCommandText};
	__property Data::Db::TParams* Params = {read=FParams};
	__property TdxServerModeCriteria* Criteria = {read=FCriteria, write=SetCriteria};
	__property TdxServerModeCustomDataSource* DataSource = {read=FDataSource};
	__property TdxServerModeDescriptors* Fields = {read=FFields, write=FFields};
	__property TdxServerModeGroupInfoDescriptors* GroupInfo = {read=FGroupInfo, write=FGroupInfo};
	__property TdxServerModeSortInfoDescriptors* SortInfo = {read=FSortInfo, write=FSortInfo};
	__property int SkipRecords = {read=FSkipRecords, write=FSkipRecords, nodefault};
	__property TdxServerModeSummaryDescriptors* Summaries = {read=FSummaries, write=FSummaries};
	__property int TopRecords = {read=FTopRecords, write=FTopRecords, nodefault};
	__property System::Variant Values = {read=FValues, write=FValues};
};


typedef System::TMetaClass* TdxServerModeCustomSQLQueryBuilderClass;

class DELPHICLASS TdxServerModeDataSourceOptions;
class PASCALIMPLEMENTATION TdxServerModeDataSourceOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxServerModeCustomDataSource* FOwner;
	bool FUseQueryParams;
	void __fastcall ReadSQLAdapter(System::Classes::TReader* Reader);
	
protected:
	virtual void __fastcall Changed(const TdxServerModeDataSourceChanges AChanges = (TdxServerModeDataSourceChanges() << TdxServerModeDataSourceChangeType::ctOptions ));
	void __fastcall CheckInactive(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TdxServerModeDataSourceOptions(TdxServerModeCustomDataSource* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetSchemaName(void);
	__property TdxServerModeCustomDataSource* Owner = {read=FOwner};
	
__published:
	__property bool UseQueryParams = {read=FUseQueryParams, write=FUseQueryParams, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxServerModeDataSourceOptions(void) { }
	
};


typedef System::TMetaClass* TdxServerModeDataSourceOptionsClass;

typedef System::TMetaClass* TdxDataSetClass;

typedef void __fastcall (__closure *TdxServerModeGetSQLAdapterClassEvent)(System::TObject* Sender, TdxServerModeCustomSQLAdapterClass &AClass);

typedef void __fastcall (__closure *TdxServerModeDataSourceNotifyEvent)(TdxServerModeCustomDataSource* Sender);

typedef Data::Db::TDataSet* *PDataSet;

class DELPHICLASS TdxServerModeDataSourceCustomHelper;
class PASCALIMPLEMENTATION TdxServerModeDataSourceCustomHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxServerModeCustomDataSource* FDataSource;
	Data::Db::TCustomConnection* __fastcall GetConnection(void);
	Data::Db::TDataSet* __fastcall GetDataSet(void);
	
protected:
	virtual TdxDataSetClass __fastcall GetDataSetClass(void) = 0 ;
	virtual TdxServerModeDataSourceOptionsClass __fastcall GetOptionsClass(void);
	virtual TdxServerModeCustomSQLQueryBuilderClass __fastcall GetQueryBuilderClass(void);
	virtual void __fastcall CheckParamValue(Data::Db::TParam* &AParam);
	void __fastcall CheckSQLAdapter(void);
	virtual void __fastcall DoExecuteCommand(PDataSet AResultSet, const System::UnicodeString ACommand, Data::Db::TParams* AParams, bool AParamCheck);
	virtual void __fastcall DoInitializeDataSet(Data::Db::TDataSet* ADataSet) = 0 ;
	virtual void __fastcall DoSynchronizeDataSetConnection(Data::Db::TDataSet* ADataSet) = 0 ;
	System::UnicodeString __fastcall GetSQLQuerySchemaNames(void);
	void __fastcall InitializeDataSet(void);
	bool __fastcall IsConnected(void);
	virtual void __fastcall PrepareDatasetForIterate(Data::Db::TDataSet* ADataSet);
	System::UnicodeString __fastcall GetFieldsRetrieveQuery(void);
	__property Data::Db::TCustomConnection* Connection = {read=GetConnection};
	__property Data::Db::TDataSet* DataSet = {read=GetDataSet};
	
public:
	__fastcall TdxServerModeDataSourceCustomHelper(TdxServerModeCustomDataSource* ADataSource);
	bool __fastcall ExecuteCommand(PDataSet AResultSet, const System::UnicodeString ACommandText, Data::Db::TParams* AParams, bool AParamCheck, bool ACheckSettings = true);
	__property TdxServerModeCustomDataSource* DataSource = {read=FDataSource};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeDataSourceCustomHelper(void) { }
	
};


typedef System::TMetaClass* TdxServerModeDataSourceCustomHelperClass;

class DELPHICLASS TdxServerModeDataController;
class DELPHICLASS TdxServerModeDataField;
class PASCALIMPLEMENTATION TdxServerModeCustomDataSource : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FActive;
	TdxServerModeCache* FCache;
	TdxServerModeDataSourceChanges FChanges;
	Data::Db::TCustomConnection* FConnection;
	TdxServerModeDataController* FDataController;
	Data::Db::TDataSet* FDataSet;
	Data::Db::TDataSetDesigner* FDataSetDesigner;
	TdxServerModeFieldDescriptors* FFieldDescriptors;
	TdxServerModeCriteria* FFilter;
	int FGroupCount;
	TdxServerModeDataSourceCustomHelper* FHelper;
	bool FIsDisconnecting;
	System::Classes::TStringList* FKeyFieldNames;
	TdxServerModeFieldDescriptors* FKeyFields;
	System::Classes::TStrings* FLoadingFieldNames;
	int FLockCount;
	TdxServerModeStateInfo* FPrevStateInfo;
	TdxServerModeDataSourceOptions* FOptions;
	TdxServerModeSortInfoDescriptors* FSortInfo;
	bool FStreamedActive;
	TdxServerModeCustomSQLAdapter* FSQLAdapter;
	TdxServerModeCustomSQLAdapterClass FSQLAdapterClass;
	System::Classes::TNotifyEvent FSQLAdapterEvents;
	TdxServerModeSummaryDescriptors* FSummaries;
	TdxServerModeSummaryDescriptors* FTotalSummaries;
	TdxServerModeDataSourceNotifyEvent FBeforeOpen;
	TdxServerModeDataSourceNotifyEvent FAfterOpen;
	TdxServerModeDataSourceNotifyEvent FBeforeClose;
	TdxServerModeDataSourceNotifyEvent FAfterClose;
	TdxServerModeGetSQLAdapterClassEvent FOnGetAdapterClass;
	void __fastcall BeginUpdateFields(void);
	void __fastcall EndUpdateFields(void);
	void __fastcall SendNotifications(void);
	void __fastcall ConnectionChangedHandler(System::TObject* Sender, bool Connecting);
	void __fastcall FilterChangedHandler(System::TObject* Sender);
	void __fastcall SortInfoChangedHandler(TdxServerModeDescriptors* Sender, TdxServerModeDescriptor* AItem, TdxServerModeDescriptorChanges AChanges);
	void __fastcall SummariesChangedHandler(TdxServerModeDescriptors* Sender, TdxServerModeDescriptor* AItem, TdxServerModeDescriptorChanges AChanges);
	void __fastcall TotalSummariesChangedHandler(TdxServerModeDescriptors* Sender, TdxServerModeDescriptor* AItem, TdxServerModeDescriptorChanges AChanges);
	void __fastcall AssignFields(void);
	void __fastcall ReadFields(System::Classes::TReader* Reader);
	void __fastcall WriteFields(System::Classes::TWriter* Writer);
	System::WideChar __fastcall GetDataControllerPercentWildcard(void);
	System::WideChar __fastcall GetDataControllerUnderscoreWildcard(void);
	void __fastcall DoSetActive(bool Value);
	Data::Db::TFieldDefs* __fastcall GetFieldDefs(void);
	Data::Db::TFields* __fastcall GetFields(void);
	System::UnicodeString __fastcall GetKeyFieldNames(void);
	System::Variant __fastcall GetRow(int Index);
	int __fastcall GetRowCount(void);
	System::UnicodeString __fastcall GetSQLAdapterClassName(void);
	void __fastcall RecreateSQLAdapter(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetConnection(Data::Db::TCustomConnection* Value);
	void __fastcall SetGroupCount(int Value);
	void __fastcall SetKeyFieldNames(const System::UnicodeString Value);
	void __fastcall SetOptions(TdxServerModeDataSourceOptions* Value);
	void __fastcall SetSQLAdapter(TdxServerModeCustomSQLAdapter* const Value);
	void __fastcall SetSQLAdapterClass(const TdxServerModeCustomSQLAdapterClass Value);
	void __fastcall SetSQLAdapterClassName(const System::UnicodeString Value);
	TdxServerModeCustomSQLAdapter* __fastcall GetAdapter(void);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetName(const System::Classes::TComponentName ANewName);
	void __fastcall AddDataController(TdxServerModeDataController* ADataController);
	void __fastcall RemoveDataController(TdxServerModeDataController* ADataController);
	virtual void __fastcall AddKeyField(Data::Db::TField* AField);
	virtual bool __fastcall CanModify(void);
	virtual bool __fastcall CanUpdate(void);
	virtual void __fastcall CheckInactive(void);
	void __fastcall CheckParamValue(Data::Db::TParam* &AParam);
	void __fastcall CheckSQLAdapter(void);
	virtual void __fastcall CheckSettings(void);
	virtual TdxServerModeCriteria* __fastcall CreateCriteria(void);
	Data::Db::TField* __fastcall CreateField(Data::Db::TFieldDef* AFieldDef, System::Classes::TComponent* AOwner);
	TdxServerModeGroupInfoDescriptors* __fastcall CreateGroupInfo(void);
	virtual System::Classes::TStringList* __fastcall CreateKeyFieldNames(void);
	TdxServerModeSortInfoDescriptors* __fastcall CreateSortInfo(void);
	TdxServerModeSummaryDescriptors* __fastcall CreateSummaries(void);
	void __fastcall DoInitializeDataSet(Data::Db::TDataSet* ADataSet);
	void __fastcall DoSynchronizeDataSetConnection(Data::Db::TDataSet* ADataSet);
	virtual void __fastcall DoUpdate(void);
	System::UnicodeString __fastcall GetFieldsRetrieveQuery(void);
	System::UnicodeString __fastcall GetFieldUniqueName(Data::Db::TField* AField);
	virtual System::UnicodeString __fastcall GetFromSQLString(void);
	bool __fastcall HasDataSourcePersistentFields(void);
	void __fastcall InitializeKeyFields(void);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalHandleException(void);
	virtual void __fastcall InternalOpen(void);
	void __fastcall MakeCriteriaWithBetweenOperator(TdxServerModeCriteria* &ACriteria, Dxservermodeclasses::TdxServerModeKeyList* const AKeys);
	void __fastcall OpenComplete(void);
	void __fastcall DestroyNonPersistentFields(void);
	bool __fastcall IsIgnoreNullOnSummary(void);
	bool __fastcall IsPersistentField(Data::Db::TField* AField);
	void __fastcall InitializeConnection(void);
	void __fastcall InitializeDataSet(void);
	virtual void __fastcall UpdateFieldDefs(void);
	virtual void __fastcall UpdateFields(void);
	virtual void __fastcall DoAfterClose(void);
	virtual void __fastcall DoAfterOpen(void);
	virtual void __fastcall DoBeforeClose(void);
	virtual void __fastcall DoBeforeOpen(void);
	virtual TdxServerModeCacheClass __fastcall GetCacheClass(void);
	virtual TdxServerModeCriteriaClass __fastcall GetCriteriaClass(void);
	virtual TdxServerModeGroupInfoDescriptorsClass __fastcall GetGroupInfoDescriptorsClass(void);
	virtual TdxServerModeDataSourceCustomHelperClass __fastcall GetHelperClass(void);
	TdxServerModeDataSourceOptionsClass __fastcall GetOptionsClass(void);
	virtual TdxServerModeSortInfoDescriptorsClass __fastcall GetSortInfoDescriptorsClass(void);
	TdxServerModeCustomSQLQueryBuilderClass __fastcall GetQueryBuilderClass(void);
	TdxDataSetClass __fastcall GetDataSetClass(void);
	virtual TdxServerModeSummaryDescriptorsClass __fastcall GetSummariesClass(void);
	void __fastcall DoExecuteCommand(PDataSet AResultSet, const System::UnicodeString ACommand, Data::Db::TParams* AParams, bool AParamCheck);
	bool __fastcall ExecuteCommand(PDataSet AResultSet, const System::UnicodeString ACommandText, Data::Db::TParams* AParams, bool AParamCheck, bool ACheckSettings = true)/* overload */;
	bool __fastcall ExecuteCommand(PDataSet AResultSet, TdxServerModeDescriptors* const AFields, TdxServerModeCriteria* ACriteria, TdxServerModeSortInfoDescriptors* ASortInfo, TdxServerModeGroupInfoDescriptors* AGroupInfo, int ATopRecords, int ASkipRecords)/* overload */;
	virtual Dxservermodeclasses::TdxServerModeKeyList* __fastcall FetchKeys(TdxServerModeCriteria* AWhere, TdxServerModeSortInfoDescriptors* ASortInfo, int ASkip, int ATake);
	virtual Dxservermodeclasses::TdxServerModeRowList* __fastcall FetchRows(TdxServerModeCriteria* AWhere, TdxServerModeSortInfoDescriptors* ASortInfo, int ATopRecords);
	virtual Dxservermodeclasses::TdxServerModeRowList* __fastcall FetchRowsByKeys(Dxservermodeclasses::TdxServerModeKeyList* AKeys);
	System::Variant __fastcall FindFirstKey(TdxServerModeCriteria* AWhere, bool ASearchDown);
	virtual int __fastcall GetCount(TdxServerModeCriteria* ACriteria);
	TdxServerModeCriteria* __fastcall GetFetchRowByIndexCondition(int ARowIndex);
	TdxServerModeCriteria* __fastcall GetFetchRowByKeyCondition(System::Variant &AKey);
	TdxServerModeCriteria* __fastcall GetFetchRowsByKeysCondition(Dxservermodeclasses::TdxServerModeKeyList* AKeys);
	virtual void __fastcall DoPopulateFields(System::Classes::TStrings* AList);
	virtual void __fastcall DoPopulateKeyFields(System::Classes::TStrings* AList);
	virtual Dxservermodeclasses::TdxServerModeGroupInfoDataList* __fastcall PrepareChildren(TdxServerModeCriteria* AGroupWhere, TdxServerModeSortInfoDescriptor* AGroupByDescriptor, TdxServerModeSummaryDescriptors* ASummaries);
	virtual Dxservermodeclasses::TdxServerModeGroupInfoData* __fastcall PrepareTopGroupInfo(TdxServerModeSummaryDescriptors* ASummaries);
	void __fastcall Change(TdxServerModeDataSourceChanges AChanges);
	void __fastcall Changed(void);
	void __fastcall Clear(void);
	void __fastcall Update(void);
	void __fastcall UpdateFieldIndex(TdxServerModeDataField* AField);
	void __fastcall Apply(TdxServerModeCriteria* AFilter, TdxServerModeSortInfoDescriptors* ASortInfo, int AGroupCount, TdxServerModeSummaryDescriptors* ASummaries, TdxServerModeSummaryDescriptors* ATotalSummaries);
	System::Variant __fastcall CreateEmptyRow(void);
	virtual void __fastcall Delete(TdxServerModeCriteria* ACriteria);
	int __fastcall FindIncremental(Data::Db::TField* AField, const System::UnicodeString ASubStr, int AStartIndex, bool ASearchDown = true, bool AIgnoreStartRow = false)/* overload */;
	int __fastcall FindIncremental(const System::UnicodeString AFieldName, const System::UnicodeString ASubStr, int AStartIndex, bool ASearchDown = true, bool AIgnoreStartRow = false)/* overload */;
	virtual void __fastcall PopulateFilterValues(Cxcustomdata::TcxDataFilterValueList* AList, Data::Db::TField* AField, Cxfilter::TcxFilterCriteria* ACriteria, bool &AUseFilteredRecords, /* out */ bool &ANullExists);
	virtual System::Variant __fastcall PostEditingData(int ARowIndex, const System::Variant &AEditingRow);
	__property TdxServerModeCustomSQLAdapter* Adapter = {read=GetAdapter};
	__property TdxServerModeCache* Cache = {read=FCache};
	__property TdxServerModeDataController* DataController = {read=FDataController};
	__property Data::Db::TDataSet* DataSet = {read=FDataSet};
	__property Data::Db::TFieldDefs* FieldDefs = {read=GetFieldDefs};
	__property TdxServerModeFieldDescriptors* FieldDescriptors = {read=FFieldDescriptors};
	__property TdxServerModeCriteria* Filter = {read=FFilter};
	__property int GroupCount = {read=FGroupCount, write=SetGroupCount, nodefault};
	__property TdxServerModeDataSourceCustomHelper* Helper = {read=FHelper};
	__property TdxServerModeFieldDescriptors* KeyFields = {read=FKeyFields};
	__property TdxServerModeStateInfo* PrevStateInfo = {read=FPrevStateInfo};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property System::Variant Rows[int Index] = {read=GetRow};
	__property TdxServerModeSortInfoDescriptors* SortInfo = {read=FSortInfo};
	__property TdxServerModeSummaryDescriptors* Summaries = {read=FSummaries};
	__property TdxServerModeSummaryDescriptors* TotalSummaries = {read=FTotalSummaries};
	__property TdxServerModeGetSQLAdapterClassEvent OnGetAdapterClass = {read=FOnGetAdapterClass, write=FOnGetAdapterClass};
	
public:
	__fastcall virtual TdxServerModeCustomDataSource(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxServerModeCustomDataSource(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall Open(void);
	void __fastcall Close(void);
	void __fastcall Refresh(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall PopulateFields(System::Classes::TStrings* AList);
	void __fastcall PopulateKeyFields(System::Classes::TStrings* AList);
	bool __fastcall IsConnected(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsLoading(void);
	bool __fastcall IsLocked(void);
	__property Data::Db::TFields* Fields = {read=GetFields};
	__property Data::Db::TCustomConnection* Connection = {read=FConnection, write=SetConnection};
	__property TdxServerModeCustomSQLAdapterClass SQLAdapterClass = {read=FSQLAdapterClass, write=SetSQLAdapterClass};
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property System::UnicodeString KeyFieldNames = {read=GetKeyFieldNames, write=SetKeyFieldNames};
	__property TdxServerModeDataSourceOptions* Options = {read=FOptions, write=SetOptions};
	__property System::UnicodeString SQLAdapterClassName = {read=GetSQLAdapterClassName, write=SetSQLAdapterClassName};
	__property TdxServerModeCustomSQLAdapter* SQLAdapter = {read=FSQLAdapter, write=SetSQLAdapter};
	__property TdxServerModeDataSourceNotifyEvent BeforeOpen = {read=FBeforeOpen, write=FBeforeOpen};
	__property TdxServerModeDataSourceNotifyEvent AfterOpen = {read=FAfterOpen, write=FAfterOpen};
	__property TdxServerModeDataSourceNotifyEvent BeforeClose = {read=FBeforeClose, write=FBeforeClose};
	__property TdxServerModeDataSourceNotifyEvent AfterClose = {read=FAfterClose, write=FAfterClose};
	__property System::Classes::TNotifyEvent SQLAdapterEvents = {read=FSQLAdapterEvents, write=FSQLAdapterEvents};
};


typedef System::TMetaClass* TdxServerModeCustomDataSourceClass;

class DELPHICLASS TdxServerModeDataSource;
class DELPHICLASS TdxCustomServerModeDataProvider;
class PASCALIMPLEMENTATION TdxServerModeDataSource : public TdxServerModeCustomDataSource
{
	typedef TdxServerModeCustomDataSource inherited;
	
private:
	bool FIsViewLinked;
	bool FIsViewLinkedCalculated;
	bool FReadOnly;
	System::UnicodeString FTableName;
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetTableName(const System::UnicodeString Value);
	TdxCustomServerModeDataProvider* __fastcall GetProvider(void);
	
protected:
	virtual bool __fastcall CanModify(void);
	virtual void __fastcall CheckSettings(void);
	void __fastcall CheckTableName(void);
	virtual System::UnicodeString __fastcall GetFromSQLString(void);
	virtual void __fastcall Delete(TdxServerModeCriteria* ACriteria);
	virtual void __fastcall DoPopulateKeyFields(System::Classes::TStrings* AList);
	virtual void __fastcall DoPopulateTableNames(System::Classes::TStrings* AList) = 0 ;
	virtual void __fastcall DoPopulateViewNames(System::Classes::TStrings* AList) = 0 ;
	bool __fastcall IsViewLinked(void);
	void __fastcall PopulateViewNames(System::Classes::TStrings* AList);
	virtual System::Variant __fastcall PostEditingData(int ARowIndex, const System::Variant &AEditingRow);
	__property TdxCustomServerModeDataProvider* Provider = {read=GetProvider};
	
public:
	void __fastcall PopulateTableNames(System::Classes::TStrings* AList);
	
__published:
	__property bool ReadOnly = {read=FReadOnly, write=SetReadOnly, default=0};
	__property System::UnicodeString TableName = {read=FTableName, write=SetTableName};
public:
	/* TdxServerModeCustomDataSource.Create */ inline __fastcall virtual TdxServerModeDataSource(System::Classes::TComponent* AOwner) : TdxServerModeCustomDataSource(AOwner) { }
	/* TdxServerModeCustomDataSource.Destroy */ inline __fastcall virtual ~TdxServerModeDataSource(void) { }
	
};


class DELPHICLASS TdxServerModeQueryDataSource;
class PASCALIMPLEMENTATION TdxServerModeQueryDataSource : public TdxServerModeCustomDataSource
{
	typedef TdxServerModeCustomDataSource inherited;
	
private:
	System::Classes::TStrings* FSQL;
	void __fastcall SetSQL(System::Classes::TStrings* const Value);
	
protected:
	virtual void __fastcall CheckSettings(void);
	void __fastcall CheckSQL(void);
	virtual System::UnicodeString __fastcall GetFromSQLString(void);
	
public:
	__fastcall virtual TdxServerModeQueryDataSource(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxServerModeQueryDataSource(void);
	
__published:
	__property System::Classes::TStrings* SQL = {read=FSQL, write=SetSQL};
};


class PASCALIMPLEMENTATION TdxServerModeDataField : public Cxcustomdata::TcxCustomDataField
{
	typedef Cxcustomdata::TcxCustomDataField inherited;
	
public:
	TdxServerModeDataField* operator[](int Index) { return Fields[Index]; }
	
private:
	Data::Db::TField* FField;
	int FFieldIndex;
	System::UnicodeString FFieldName;
	System::Classes::TList* FFields;
	bool FIsCurrency;
	bool FModified;
	TdxServerModeDataField* FParentField;
	HIDESBASE TdxServerModeDataController* __fastcall GetDataController(void);
	Data::Db::TField* __fastcall GetField(void);
	int __fastcall GetFieldIndex(void);
	TdxServerModeDataField* __fastcall GetFieldItem(int Index);
	int __fastcall GetFieldCount(void);
	bool __fastcall GetIsCurrency(void);
	bool __fastcall GetIsLookup(void);
	TdxCustomServerModeDataProvider* __fastcall GetProvider(void);
	void __fastcall SetField(Data::Db::TField* Value);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	
protected:
	void __fastcall AddField(TdxServerModeDataField* ADataField);
	void __fastcall ClearFields(void);
	void __fastcall DoPropertiesChanged(void);
	virtual void __fastcall Reassign(Cxcustomdata::TcxCustomDataField* ASource);
	void __fastcall RemoveField(TdxServerModeDataField* ADataField);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	bool __fastcall SetEditingData(int ARecordIndex, const System::Variant &AValue);
	void __fastcall SetPropertiesByField(Data::Db::TField* AField, bool AFieldChanged);
	__property TdxServerModeDataController* DataController = {read=GetDataController};
	__property Data::Db::TField* Field = {read=GetField, write=SetField};
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property System::UnicodeString FieldName = {read=FFieldName, write=SetFieldName};
	__property TdxServerModeDataField* Fields[int Index] = {read=GetFieldItem/*, default*/};
	__property int FieldIndex = {read=GetFieldIndex, nodefault};
	__property bool IsCurrency = {read=GetIsCurrency, nodefault};
	__property bool IsLookup = {read=GetIsLookup, nodefault};
	__property TdxServerModeDataField* ParentField = {read=FParentField};
	__property TdxCustomServerModeDataProvider* Provider = {read=GetProvider};
	
public:
	__fastcall virtual TdxServerModeDataField(Cxcustomdata::TcxCustomDataFieldList* AFieldList);
	__fastcall virtual ~TdxServerModeDataField(void);
	virtual bool __fastcall CanModify(Cxdatautils::TcxDataEditValueSource AEditValueSource);
	virtual bool __fastcall IsUnbound(void);
	virtual bool __fastcall IsValueDefInternal(void);
};


class DELPHICLASS TdxServerModeSummaryItem;
class PASCALIMPLEMENTATION TdxServerModeSummaryItem : public Cxcustomdata::TcxDataSummaryItem
{
	typedef Cxcustomdata::TcxDataSummaryItem inherited;
	
private:
	TdxServerModeDataField* FDataField;
	System::UnicodeString FFieldName;
	System::UnicodeString __fastcall GetFieldName(void);
	TdxServerModeDataController* __fastcall GetServerModeDataController(void);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	
protected:
	bool __fastcall AllowKind(Cxcustomdata::TcxSummaryKind Value);
	virtual bool __fastcall CanSetKind(Cxcustomdata::TcxSummaryKind Value);
	virtual bool __fastcall IsCurrency(System::Word AVarType);
	virtual bool __fastcall IsDataBinded(void);
	TdxServerModeDataField* __fastcall ServerModeDataField(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxServerModeDataController* DataController = {read=GetServerModeDataController};
	virtual Cxcustomdata::TcxCustomDataField* __fastcall DataField(void);
	
__published:
	__property System::UnicodeString FieldName = {read=GetFieldName, write=SetFieldName};
public:
	/* TcxDataSummaryItem.Destroy */ inline __fastcall virtual ~TdxServerModeSummaryItem(void) { }
	
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TdxServerModeSummaryItem(System::Classes::TCollection* Collection) : Cxcustomdata::TcxDataSummaryItem(Collection) { }
	
};


class DELPHICLASS TdxServerModeDataSummary;
class DELPHICLASS TdxServerModeDataGroupInfo;
class PASCALIMPLEMENTATION TdxServerModeDataSummary : public Cxcustomdata::TcxDataSummary
{
	typedef Cxcustomdata::TcxDataSummary inherited;
	
private:
	TdxServerModeDataController* __fastcall GetDataController(void);
	void __fastcall PopulateSummary(Cxcustomdata::TcxDataSummaryItems* ASummaryItems, Dxservermodeclasses::TdxServerModeSummaryList* AValues, Cxcustomdata::TcxDataSummaryCountValues &ACountValues, Cxcustomdata::TcxDataSummaryValues &ASummaryValues, System::Variant &SummaryValues);
	
protected:
	virtual void __fastcall CalculateSummary(Cxcustomdata::TcxDataSummaryItems* ASummaryItems, int ABeginIndex, int AEndIndex, Cxcustomdata::TcxDataSummaryCountValues &ACountValues, Cxcustomdata::TcxDataSummaryValues &ASummaryValues, System::Variant &SummaryValues);
	
public:
	virtual void __fastcall CalculateGroupSummary(void);
	void __fastcall UpdateGroupSummary(TdxServerModeDataGroupInfo* AParentGroup = (TdxServerModeDataGroupInfo*)(0x0));
	__property TdxServerModeDataController* DataController = {read=GetDataController};
public:
	/* TcxDataSummary.Create */ inline __fastcall virtual TdxServerModeDataSummary(Cxcustomdata::TcxCustomDataController* ADataController) : Cxcustomdata::TcxDataSummary(ADataController) { }
	/* TcxDataSummary.Destroy */ inline __fastcall virtual ~TdxServerModeDataSummary(void) { }
	
};


class DELPHICLASS TdxServerModeProviderDataSource;
class PASCALIMPLEMENTATION TdxServerModeProviderDataSource : public Cxcustomdata::TcxCustomDataSource
{
	typedef Cxcustomdata::TcxCustomDataSource inherited;
	
private:
	HIDESBASE TdxServerModeDataController* __fastcall GetDataController(void);
	HIDESBASE TdxCustomServerModeDataProvider* __fastcall GetProvider(void);
	
public:
	virtual void * __fastcall GetRecordHandleByIndex(int ARecordIndex);
	__property TdxServerModeDataController* DataController = {read=GetDataController};
	__property TdxCustomServerModeDataProvider* Provider = {read=GetProvider};
public:
	/* TcxCustomDataSource.Destroy */ inline __fastcall virtual ~TdxServerModeProviderDataSource(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxServerModeProviderDataSource(void) : Cxcustomdata::TcxCustomDataSource() { }
	
};


class PASCALIMPLEMENTATION TdxCustomServerModeDataProvider : public Cxcustomdata::TcxCustomDataProvider
{
	typedef Cxcustomdata::TcxCustomDataProvider inherited;
	
private:
	System::Variant FEditingRow;
	bool FInCanInitEditing;
	bool FIsAppending;
	void __fastcall AddRecord(bool AIsAppending);
	void __fastcall ClearEditingRow(void);
	void __fastcall CreateEditingRow(void);
	HIDESBASE void __fastcall SetCustomDataSource(TdxServerModeProviderDataSource* Value);
	TdxServerModeProviderDataSource* __fastcall GetCustomDataSource(void);
	TdxServerModeDataController* __fastcall GetDataController(void);
	TdxServerModeCustomDataSource* __fastcall GetDataSource(void);
	
protected:
	virtual bool __fastcall IsActive(void);
	virtual void __fastcall SavePos(void);
	virtual void __fastcall RestorePos(void);
	virtual void __fastcall Append(void);
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanInitEditing(int ARecordIndex);
	virtual bool __fastcall CanModify(void);
	virtual void __fastcall DeleteRecord(int ARecordIndex);
	HIDESBASE void __fastcall DeleteRecords(TdxServerModeCriteria* ACriteria);
	virtual void __fastcall DeleteSelection(void);
	virtual void __fastcall DoInsertingRecord(bool AIsAppending);
	virtual void __fastcall Edit(void);
	virtual void __fastcall Insert(void);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
	virtual void __fastcall AssignItemValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField, const System::Variant &AValue);
	virtual void __fastcall Post(bool AForcePost = false);
	virtual void __fastcall PostEditingData(void);
	virtual void __fastcall ResetEditing(void);
	void __fastcall UpdateData(void);
	System::Variant __fastcall GetEditingRowKey(void);
	int __fastcall GetRowIndexByKey(System::Variant &AKey);
	System::Variant __fastcall GetRowKey(int ARecordIndex);
	System::Variant __fastcall GetServerRowValue(int ARecordIndex, int AFieldIndex);
	void __fastcall InternalPost(void);
	bool __fastcall SetEditingData(int ARecordIndex, int AFieldIndex, const System::Variant &AValue);
	virtual bool __fastcall SetEditValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField, const System::Variant &AValue, Cxdatautils::TcxDataEditValueSource AEditValueSource);
	__property TdxServerModeProviderDataSource* CustomDataSource = {read=GetCustomDataSource, write=SetCustomDataSource};
	__property TdxServerModeDataController* DataController = {read=GetDataController};
	__property TdxServerModeCustomDataSource* DataSource = {read=GetDataSource};
	__property System::Variant EditingRow = {read=FEditingRow};
	__property bool IsAppending = {read=FIsAppending, nodefault};
	
public:
	__fastcall virtual TdxCustomServerModeDataProvider(Cxcustomdata::TcxCustomDataController* ADataController);
	__fastcall virtual ~TdxCustomServerModeDataProvider(void);
};


class DELPHICLASS TdxServerModeDataFocusingInfo;
class DELPHICLASS TdxServerModeDataControllerInfo;
class PASCALIMPLEMENTATION TdxServerModeDataFocusingInfo : public Cxcustomdata::TcxDataFocusingInfo
{
	typedef Cxcustomdata::TcxDataFocusingInfo inherited;
	
private:
	System::Variant FKey;
	bool FIsGroupKey;
	TdxServerModeDataControllerInfo* __fastcall GetDataControllerInfo(void);
	
protected:
	virtual void __fastcall Assign(Cxcustomdata::TcxDataFocusingInfo* AFocusingInfo);
	void __fastcall CalculateKey(int ADataGroupIndex);
	virtual void __fastcall Clear(void);
	virtual bool __fastcall IsEqual(Cxcustomdata::TcxDataFocusingInfo* AFocusingInfo);
	virtual bool __fastcall IsNeedUpdate(void);
	bool __fastcall IsUndefined(void);
	virtual void __fastcall SavePos(void);
	void __fastcall SetRowKey(const System::Variant &AKey);
	
public:
	__fastcall virtual TdxServerModeDataFocusingInfo(Cxcustomdata::TcxCustomDataControllerInfo* ADataControllerInfo);
	__property TdxServerModeDataControllerInfo* DataControllerInfo = {read=GetDataControllerInfo};
	__property System::Variant Key = {read=FKey};
	__property bool IsGroupKey = {read=FIsGroupKey, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeDataFocusingInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxServerModeDataGroupInfo : public Cxcustomdata::TcxDataGroupInfo
{
	typedef Cxcustomdata::TcxDataGroupInfo inherited;
	
private:
	System::Variant __fastcall GetGroupValue(void);
	
protected:
	void __fastcall AdjustByInsertingRecord(int ARecordIndex, bool AAppending);
	
public:
	bool ChildrenIsReady;
	TdxServerModeDataGroupInfo* ParentGroup;
	Dxservermodeclasses::TdxServerModeGroupInfo* ServerGroupInfo;
	__fastcall TdxServerModeDataGroupInfo(TdxServerModeDataGroupInfo* AParentGroup, Dxservermodeclasses::TdxServerModeGroupInfo* AServerGroupInfo);
	bool __fastcall IsEqual(const System::Variant &AValue, unsigned AHash);
	__property System::Variant GroupValue = {read=GetGroupValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeDataGroupInfo(void) { }
	
};


class DELPHICLASS TdxServerModeDataGroups;
class PASCALIMPLEMENTATION TdxServerModeDataGroups : public Cxcustomdata::TcxDataGroups
{
	typedef Cxcustomdata::TcxDataGroups inherited;
	
public:
	TdxServerModeDataGroupInfo* operator[](int Index) { return Items[Index]; }
	
private:
	bool FIsFullExpanding;
	HIDESBASE TdxServerModeDataGroupInfo* __fastcall GetItem(int Index);
	TdxServerModeDataControllerInfo* __fastcall GetDataControllerInfo(void);
	Dxservermodeclasses::TdxServerModeGroupInfo* __fastcall GetTopGroupInfo(void);
	
protected:
	void __fastcall CreateGroups(void);
	void __fastcall CreateGroup(Dxservermodeclasses::TdxServerModeGroupInfoList* AList, TdxServerModeDataGroupInfo* AParentGroup);
	void __fastcall ExpandItem(TdxServerModeDataGroupInfo* AItem, bool AExpanded);
	int __fastcall FindByServerGroupInfo(Dxservermodeclasses::TdxServerModeGroupInfo* const AServerGroupInfo);
	int __fastcall FindInnerGroup(int ARecordListIndex);
	int __fastcall GetRowIndexByGroupValue(const System::Variant &AGroupValue);
	virtual bool __fastcall MakeVisible(int AIndex, bool AExpand);
	void __fastcall RequestChildren(TdxServerModeDataGroupInfo* AParentGroup);
	void __fastcall UpdateGroupSummary(TdxServerModeDataGroupInfo* AParentGroup);
	__property TdxServerModeDataControllerInfo* DataControllerInfo = {read=GetDataControllerInfo};
	__property Dxservermodeclasses::TdxServerModeGroupInfo* TopGroupInfo = {read=GetTopGroupInfo};
	
public:
	virtual void __fastcall ChangeExpanding(int ARowIndex, bool AExpanded, bool ARecursive);
	virtual void __fastcall FullExpanding(bool AExpanded);
	virtual int __fastcall GetDataRecordListIndex(Cxcustomdata::TcxDataGroupInfo* AInfo);
	virtual void __fastcall Rebuild(void);
	__property TdxServerModeDataGroupInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxDataGroups.Create */ inline __fastcall virtual TdxServerModeDataGroups(Cxcustomdata::TcxCustomDataControllerInfo* ADataControllerInfo) : Cxcustomdata::TcxDataGroups(ADataControllerInfo) { }
	/* TcxDataGroups.Destroy */ inline __fastcall virtual ~TdxServerModeDataGroups(void) { }
	
};


class DELPHICLASS TdxServerModeDataSelection;
class PASCALIMPLEMENTATION TdxServerModeDataSelection : public Cxcustomdata::TcxDataSelection
{
	typedef Cxcustomdata::TcxDataSelection inherited;
	
private:
	TdxServerModeDataController* __fastcall GetDataController(void);
	
public:
	__property TdxServerModeDataController* DataController = {read=GetDataController};
public:
	/* TcxDataSelection.Create */ inline __fastcall virtual TdxServerModeDataSelection(Cxcustomdata::TcxCustomDataController* ADataController) : Cxcustomdata::TcxDataSelection(ADataController) { }
	/* TcxDataSelection.Destroy */ inline __fastcall virtual ~TdxServerModeDataSelection(void) { }
	
};


class PASCALIMPLEMENTATION TdxServerModeDataControllerInfo : public Cxcustomdata::TcxCustomDataControllerInfo
{
	typedef Cxcustomdata::TcxCustomDataControllerInfo inherited;
	
private:
	TdxServerModeCriteria* __fastcall CreateCriteria(void);
	TdxServerModeSortInfoDescriptors* __fastcall CreateSortInfo(void);
	TdxServerModeSummaryDescriptors* __fastcall CreateSummariesByItems(Cxcustomdata::TcxDataSummaryItems* AItems, int ALevel);
	TdxServerModeSummaryDescriptors* __fastcall CreateGroupSummaries(void);
	TdxServerModeSummaryDescriptors* __fastcall CreateTotalSummaries(void);
	TdxServerModeDataController* __fastcall GetDataController(void);
	TdxServerModeDataGroups* __fastcall GetDataGroups(void);
	TdxServerModeDataSelection* __fastcall GetSelection(void);
	TdxServerModeCache* __fastcall GetSource(void);
	TdxServerModeDataFocusingInfo* __fastcall GetFocusingInfo(void);
	void __fastcall PopulateSummariesByItems(TdxServerModeSummaryDescriptors* AList, Cxcustomdata::TcxDataSummaryItems* AItems, int ALevel);
	TdxServerModeCustomDataSource* __fastcall GetDataSource(void);
	
protected:
	virtual void __fastcall DoFilter(void);
	virtual void __fastcall DoGrouping(void);
	virtual void __fastcall DoLoad(void);
	virtual void __fastcall DoSort(void);
	virtual void __fastcall DoUpdate(bool ASummaryChanged);
	bool __fastcall IsDataSourceValid(void);
	virtual bool __fastcall IsUpdateDataSourceNeeded(void);
	void __fastcall UpdateDataSource(void);
	virtual Cxcustomdata::TcxDataFocusingInfoClass __fastcall GetDataFocusingInfoClass(void);
	virtual Cxcustomdata::TcxDataGroupsClass __fastcall GetDataGroupsClass(void);
	virtual void __fastcall CheckExpanding(void);
	virtual void __fastcall CheckFocusing(void);
	virtual int __fastcall FindDataGroup(int ARecordListIndex);
	int __fastcall FindFocusedGroup(void);
	virtual int __fastcall FindFocusedRow(bool ANearest);
	virtual int __fastcall GetInternalRecordCount(void);
	virtual int __fastcall GetRecordListIndexByFocusingInfo(void);
	virtual bool __fastcall IsResetFocusingNeeded(void);
	virtual int __fastcall LocateDetail(int AGroupIndex, int ARecordListIndex, bool AMakeVisible);
	virtual int __fastcall LocateGroupByLevel(int AGroupIndex, int ALevel);
	virtual void __fastcall ResetFocusing(void);
	virtual void __fastcall SaveExpanding(Cxcustomdata::TcxDataExpandingInfoStateSet ASaveStates);
	__property TdxServerModeDataFocusingInfo* FocusingInfo = {read=GetFocusingInfo};
	__property TdxServerModeCache* Source = {read=GetSource};
	
public:
	virtual Cxcustomdata::TcxRowInfo __fastcall GetRowInfo(int ARowIndex);
	virtual void __fastcall RemoveField(Cxcustomdata::TcxCustomDataField* AField);
	__property TdxServerModeDataController* DataController = {read=GetDataController};
	__property TdxServerModeDataGroups* DataGroups = {read=GetDataGroups};
	__property TdxServerModeCustomDataSource* DataSource = {read=GetDataSource};
	__property TdxServerModeDataSelection* Selection = {read=GetSelection};
public:
	/* TcxCustomDataControllerInfo.Create */ inline __fastcall virtual TdxServerModeDataControllerInfo(Cxcustomdata::TcxCustomDataController* ADataController) : Cxcustomdata::TcxCustomDataControllerInfo(ADataController) { }
	/* TcxCustomDataControllerInfo.Destroy */ inline __fastcall virtual ~TdxServerModeDataControllerInfo(void) { }
	
};


class DELPHICLASS TdxServerModeDataControllerSearch;
class PASCALIMPLEMENTATION TdxServerModeDataControllerSearch : public Cxcustomdata::TcxDataControllerSearch
{
	typedef Cxcustomdata::TcxDataControllerSearch inherited;
	
private:
	TdxServerModeDataController* __fastcall GetDataController(void);
	
protected:
	virtual int __fastcall DoSearch(int AStartFilteredRecordIndex, int AEndFilteredRecordIndex, const System::UnicodeString ASubText, bool AForward);
	
public:
	__property TdxServerModeDataController* DataController = {read=GetDataController};
public:
	/* TcxDataControllerObject.Create */ inline __fastcall virtual TdxServerModeDataControllerSearch(Cxcustomdata::TcxCustomDataController* ADataController) : Cxcustomdata::TcxDataControllerSearch(ADataController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeDataControllerSearch(void) { }
	
};


typedef void __fastcall (__closure *TdxServerDataInconsistencyEvent)(TdxServerModeDataController* Sender, const System::UnicodeString AMessage);

class DELPHICLASS TdxServerModeDataControllerGroups;
class PASCALIMPLEMENTATION TdxServerModeDataControllerGroups : public Cxcustomdata::TcxDataControllerGroups
{
	typedef Cxcustomdata::TcxDataControllerGroups inherited;
	
private:
	TdxServerModeDataController* __fastcall GetDataController(void);
	
protected:
	TdxServerModeCriteria* __fastcall GetCriteria(int ARowIndex);
	
public:
	__property TdxServerModeDataController* DataController = {read=GetDataController};
public:
	/* TcxDataControllerGroups.Create */ inline __fastcall TdxServerModeDataControllerGroups(Cxcustomdata::TcxCustomDataController* ADataController) : Cxcustomdata::TcxDataControllerGroups(ADataController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeDataControllerGroups(void) { }
	
};


class DELPHICLASS TdxServerModeDataFilterCriteriaItem;
class PASCALIMPLEMENTATION TdxServerModeDataFilterCriteriaItem : public Cxcustomdata::TcxDataFilterCriteriaItem
{
	typedef Cxcustomdata::TcxDataFilterCriteriaItem inherited;
	
protected:
	virtual Cxfilter::TcxFilterOperatorClass __fastcall GetFilterOperatorClass(void);
public:
	/* TcxFilterCriteriaItem.Create */ inline __fastcall virtual TdxServerModeDataFilterCriteriaItem(Cxfilter::TcxFilterCriteriaItemList* AOwner, System::TObject* AItemLink, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayValue) : Cxcustomdata::TcxDataFilterCriteriaItem(AOwner, AItemLink, AOperatorKind, AValue, ADisplayValue) { }
	/* TcxFilterCriteriaItem.Destroy */ inline __fastcall virtual ~TdxServerModeDataFilterCriteriaItem(void) { }
	
};


class DELPHICLASS TdxServerModeDataFilterCriteria;
class PASCALIMPLEMENTATION TdxServerModeDataFilterCriteria : public Cxcustomdata::TcxDataFilterCriteria
{
	typedef Cxcustomdata::TcxDataFilterCriteria inherited;
	
protected:
	virtual Cxfilter::TcxFilterCriteriaItemClass __fastcall GetItemClass(void);
public:
	/* TcxDataFilterCriteria.Create */ inline __fastcall virtual TdxServerModeDataFilterCriteria(Cxcustomdata::TcxCustomDataController* ADataController) : Cxcustomdata::TcxDataFilterCriteria(ADataController) { }
	/* TcxDataFilterCriteria.Destroy */ inline __fastcall virtual ~TdxServerModeDataFilterCriteria(void) { }
	
};


enum TdxServerModeDataControllerOption : unsigned char { sdcoAssignGroupingValues, sdcoGroupsAlwaysExpanded, sdcoImmediatePost, sdcoInsertOnNewItemRowFocusing, sdcoKeepFocusedRowOnUpdate, sdcoSaveExpanding };

typedef System::Set<TdxServerModeDataControllerOption, TdxServerModeDataControllerOption::sdcoAssignGroupingValues, TdxServerModeDataControllerOption::sdcoSaveExpanding>  TdxServerModeDataControllerOptions;

class PASCALIMPLEMENTATION TdxServerModeDataController : public Cxcustomdata::TcxCustomDataController
{
	typedef Cxcustomdata::TcxCustomDataController inherited;
	
private:
	TdxServerModeProviderDataSource* FCustomDataSource;
	TdxServerModeCustomDataSource* FDataSource;
	TdxServerModeDataControllerOptions FOptions;
	TdxServerDataInconsistencyEvent FOnServerDataInconsistency;
	TdxServerModeDataControllerGroups* __fastcall GetGroups(void);
	TdxCustomServerModeDataProvider* __fastcall GetProvider(void);
	TdxServerModeDataField* __fastcall GetField(int Index);
	int __fastcall GetFieldCount(void);
	TdxServerModeDataControllerInfo* __fastcall GetDataControllerInfo(void);
	TdxServerModeDataSummary* __fastcall GetSummary(void);
	void __fastcall SetDataSource(TdxServerModeCustomDataSource* const Value);
	HIDESBASE void __fastcall SetOptions(const TdxServerModeDataControllerOptions Value);
	HIDESBASE void __fastcall SetSummary(TdxServerModeDataSummary* Value);
	
protected:
	virtual Cxcustomdata::TcxCustomDataControllerInfo* __fastcall CreateDataControllerInfo(void);
	virtual Cxcustomdata::TcxCustomDataProviderClass __fastcall GetDataProviderClass(void);
	virtual Cxcustomdata::TcxDataSelectionClass __fastcall GetDataSelectionClass(void);
	virtual Cxcustomdata::TcxDataFilterCriteriaClass __fastcall GetFilterCriteriaClass(void);
	virtual Cxcustomdata::TcxDataControllerSearchClass __fastcall GetSearchClass(void);
	virtual Cxcustomdata::TcxDataSummaryClass __fastcall GetSummaryClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	virtual bool __fastcall CanFocusRecord(int ARecordIndex);
	virtual bool __fastcall GetIsRowInfoValid(void);
	virtual bool __fastcall IsSmartLoad(void);
	virtual void __fastcall PrepareField(Cxcustomdata::TcxCustomDataField* AField);
	virtual void __fastcall RemoveNotification(System::Classes::TComponent* AComponent);
	virtual bool __fastcall TryFocusRecord(int ARecordIndex);
	virtual void __fastcall Unlocked(void);
	virtual int __fastcall AppendInSmartLoad(void);
	virtual void __fastcall DeleteInSmartLoad(int ARecordIndex);
	void __fastcall DoUpdateRecord(int ARecordIndex);
	void __fastcall UpdateEditingRecord(void);
	void __fastcall ChangeFieldName(int AItemIndex, const System::UnicodeString AFieldName);
	virtual Cxcustomdata::TcxCustomDataFieldClass __fastcall GetFieldClass(void);
	TdxServerModeDataField* __fastcall GetFieldByFieldName(const System::UnicodeString AFieldName);
	virtual Cxcustomdata::TcxDataControllerGroupsClass __fastcall GetGroupsClass(void);
	System::TObject* __fastcall GetItemByFieldName(const System::UnicodeString AFieldName);
	Data::Db::TField* __fastcall GetItemField(int AItemIndex);
	System::UnicodeString __fastcall GetItemFieldName(int AItemIndex);
	bool __fastcall HasDataSourcePersistentFields(void);
	virtual bool __fastcall IsDataField(Cxcustomdata::TcxCustomDataField* AField);
	bool __fastcall IsDataSourcePersistentField(Data::Db::TField* AField);
	void __fastcall UpdateField(TdxServerModeDataField* ADataField, const System::UnicodeString AFieldNames, bool AIsLookup);
	void __fastcall UpdateInternalField(const System::UnicodeString AFieldName, TdxServerModeDataField* &AField);
	void __fastcall DataSourceChanged(void);
	virtual void __fastcall DoServerDataInconsistency(const System::UnicodeString AMessage);
	virtual void __fastcall InitializeDescriptor(Cxcustomdata::TcxCustomDataField* AField, TdxServerModeDescriptor* &ADescriptor);
	virtual System::UnicodeString __fastcall GetGroupRowDisplayText(const Cxcustomdata::TcxRowInfo &ARowInfo, int &AItemIndex);
	virtual System::Variant __fastcall GetGroupRowValue(const Cxcustomdata::TcxRowInfo &ARowInfo, int AItemIndex);
	virtual System::UnicodeString __fastcall GetInternalDisplayText(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField);
	virtual System::Variant __fastcall GetInternalValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField);
	virtual void __fastcall GetKeyFields(System::Classes::TList* AList);
	virtual bool __fastcall IsResetFocusedRowNeeded(void);
	void __fastcall ServerDataInconsistency(TdxServerModeCache* Sender, const System::UnicodeString AMessage);
	virtual int __fastcall CalcEditingRecordIndex(void);
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
	virtual bool __fastcall GetKeepFocusedRowOnUpdatingSetting(void);
	virtual void __fastcall PopulateFilterValues(Cxcustomdata::TcxDataFilterValueList* AList, int AItemIndex, Cxfilter::TcxFilterCriteria* ACriteria, bool &AUseFilteredRecords, /* out */ bool &ANullExists);
	__property int FieldCount = {read=GetFieldCount, nodefault};
	__property TdxServerModeDataField* Fields[int Index] = {read=GetField};
	
public:
	__fastcall virtual TdxServerModeDataController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxServerModeDataController(void);
	virtual void __fastcall Cancel(void);
	virtual void __fastcall CheckBrowseMode(void);
	virtual void __fastcall DeleteFocused(void);
	virtual System::UnicodeString __fastcall GetFilterItemFieldName(System::TObject* AItem);
	virtual int __fastcall GetRecordCount(void);
	virtual int __fastcall InsertRecord(int ARecordIndex);
	bool __fastcall IsKeyField(Data::Db::TField* AField);
	virtual bool __fastcall IsProviderMode(void);
	int __fastcall FindRecordIndexByKey(const System::Variant &AKeyFieldValues);
	virtual System::Variant __fastcall GetRecordId(int ARecordIndex);
	bool __fastcall LocateByKey(const System::Variant &AKeyFieldValues);
	virtual void __fastcall RefreshExternalData(void);
	__property TdxServerModeDataControllerGroups* Groups = {read=GetGroups};
	__property TdxCustomServerModeDataProvider* Provider = {read=GetProvider};
	__property TdxServerModeDataSummary* Summary = {read=GetSummary, write=SetSummary};
	__property TdxServerModeDataControllerInfo* DataControllerInfo = {read=GetDataControllerInfo};
	__property TdxServerModeCustomDataSource* DataSource = {read=FDataSource, write=SetDataSource};
	__property TdxServerModeDataControllerOptions Options = {read=FOptions, write=SetOptions, default=49};
	__property TdxServerDataInconsistencyEvent OnServerDataInconsistency = {read=FOnServerDataInconsistency, write=FOnServerDataInconsistency};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxclasses::TcxRegisteredClasses* __fastcall dxGetServerModeSQLAdapters(void);
extern PACKAGE void __fastcall dxServerModeRegisterAdapter(TdxServerModeCustomSQLAdapterClass AClass, const System::UnicodeString AName);
extern PACKAGE void __fastcall dxServerModeUnregisterAdapter(TdxServerModeCustomSQLAdapterClass AClass);
}	/* namespace Dxservermodedata */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODEDATA)
using namespace Dxservermodedata;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodedataHPP
