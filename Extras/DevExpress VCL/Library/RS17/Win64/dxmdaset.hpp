// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxmdaset.pas' rev: 24.00 (Win64)

#ifndef DxmdasetHPP
#define DxmdasetHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Data.DBPlatform.hpp>	// Pascal unit
#include <System.Generics.Collections.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Data.SqlTimSt.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.Generics.Defaults.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxmdaset
{
//-- type declarations -------------------------------------------------------
typedef System::AnsiString TMemBlobData;

typedef System::PByte TdxMemDataBuffer;

typedef System::Generics::Collections::TList__1<Data::Db::TField*>* TdxMemDataFieldList;

class DELPHICLASS TdxIntegerList;
class PASCALIMPLEMENTATION TdxIntegerList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	NativeInt operator[](int Index) { return Items[Index]; }
	
private:
	NativeInt __fastcall GetItem(int AIndex);
	void __fastcall SetItem(int AIndex, NativeInt AValue);
	
public:
	HIDESBASE int __fastcall Add(NativeInt AValue);
	HIDESBASE int __fastcall IndexOf(NativeInt AValue);
	HIDESBASE void __fastcall Insert(int AIndex, NativeInt AValue);
	__property NativeInt Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxIntegerList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxIntegerList(void) : System::Classes::TList() { }
	
};


class DELPHICLASS TdxMemField;
class DELPHICLASS TdxMemFields;
class DELPHICLASS TdxCustomMemData;
class PASCALIMPLEMENTATION TdxMemField : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Data::Db::TField* FField;
	Data::Db::TFieldType FDataType;
	int FDataSize;
	int FOffSet;
	int FValueOffSet;
	int FMaxIncValue;
	TdxMemFields* FOwner;
	int FIndex;
	bool FIsNeedAutoInc;
	System::PByte __fastcall DataPointer(int AIndex, int AOffset);
	System::PByte __fastcall GetValues(int AIndex);
	bool __fastcall GetHasValue(int AIndex);
	char __fastcall GetHasValues(int AIndex);
	void __fastcall SetHasValue(int AIndex, bool AValue);
	void __fastcall SetHasValues(int AIndex, char AValue);
	void __fastcall SetAutoIncValue(const System::PByte ABuffer, System::PByte AValue);
	TdxCustomMemData* __fastcall GetDataSet(void);
	TdxMemFields* __fastcall GetMemFields(void);
	__property bool HasValue[int AIndex] = {read=GetHasValue, write=SetHasValue};
	
protected:
	virtual void __fastcall CreateField(Data::Db::TField* AField);
	bool __fastcall GetActiveBuffer(System::PByte AActiveBuffer, System::PByte ABuffer);
	void __fastcall SetActiveBuffer(System::PByte AActiveBuffer, System::PByte ABuffer);
	__property TdxMemFields* MemFields = {read=GetMemFields};
	
public:
	__fastcall TdxMemField(TdxMemFields* AOwner);
	void __fastcall AddValue(System::PByte ABuffer);
	void __fastcall InsertValue(int AIndex, System::PByte ABuffer);
	System::PByte __fastcall GetDataFromBuffer(System::PByte ABuffer);
	char __fastcall GetHasValueFromBuffer(System::PByte ABuffer);
	System::PByte __fastcall GetValueFromBuffer(System::PByte ABuffer);
	__property int OffSet = {read=FValueOffSet, nodefault};
	__property TdxCustomMemData* DataSet = {read=GetDataSet};
	__property Data::Db::TField* Field = {read=FField};
	__property int Index = {read=FIndex, nodefault};
	__property System::PByte Values[int AIndex] = {read=GetValues};
	__property char HasValues[int AIndex] = {read=GetHasValues, write=SetHasValues};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxMemField(void) { }
	
};


class PASCALIMPLEMENTATION TdxMemFields : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FItems;
	System::Classes::TList* FCalcFields;
	TdxCustomMemData* FDataSet;
	System::Classes::TList* FValues;
	System::Classes::TList* FIsNeedAutoIncList;
	int FValuesSize;
	int __fastcall GetRecordCount(void);
	TdxMemField* __fastcall GetItem(int Index);
	
protected:
	TdxMemField* __fastcall Add(Data::Db::TField* AField);
	void __fastcall Clear(void);
	void __fastcall DeleteRecord(int AIndex);
	void __fastcall InsertRecord(const System::PByte Buffer, int AIndex, bool Append);
	void __fastcall AddField(Data::Db::TField* Field);
	void __fastcall RemoveField(Data::Db::TField* Field);
	
public:
	__fastcall TdxMemFields(TdxCustomMemData* ADataSet);
	__fastcall virtual ~TdxMemFields(void);
	void __fastcall GetBuffer(System::PByte Buffer, int AIndex);
	void __fastcall SetBuffer(System::PByte Buffer, int AIndex);
	bool __fastcall GetActiveBuffer(System::PByte AActiveBuffer, System::PByte ABuffer, Data::Db::TField* Field);
	void __fastcall SetActiveBuffer(System::PByte AActiveBuffer, System::PByte ABuffer, Data::Db::TField* Field);
	int __fastcall GetCount(void);
	TdxMemField* __fastcall IndexOf(Data::Db::TField* Field);
	System::PByte __fastcall GetValue(TdxMemField* mField, int Index);
	char __fastcall GetHasValue(TdxMemField* mField, int Index);
	void __fastcall SetValue(TdxMemField* mField, int Index, System::PByte Buffer);
	void __fastcall SetHasValue(TdxMemField* mField, int Index, char Value);
	__property System::Classes::TList* Values = {read=FValues};
	__property TdxCustomMemData* DataSet = {read=FDataSet};
	__property int Count = {read=GetCount, nodefault};
	__property TdxMemField* Items[int Index] = {read=GetItem};
	__property int RecordCount = {read=GetRecordCount, nodefault};
};


struct TdxRecInfo;
typedef TdxRecInfo *PdxRecInfo;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxRecInfo
{
public:
	int Bookmark;
	Data::Db::TBookmarkFlag BookmarkFlag;
};
#pragma pack(pop)


class DELPHICLASS TdxMemBlobStream;
class PASCALIMPLEMENTATION TdxMemBlobStream : public System::Classes::TMemoryStream
{
	typedef System::Classes::TMemoryStream inherited;
	
private:
	Data::Db::TBlobField* FField;
	TdxCustomMemData* FDataSet;
	System::Byte *FRecordBuffer;
	Data::Db::TBlobStreamMode FMode;
	bool FOpened;
	bool FModified;
	
public:
	__fastcall TdxMemBlobStream(Data::Db::TBlobField* Field, Data::Db::TBlobStreamMode Mode);
	__fastcall virtual ~TdxMemBlobStream(void);
	virtual int __fastcall Write(const void *Buffer, int Count)/* overload */;
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Offset, int Count){ return System::Classes::TMemoryStream::Write(Buffer, Offset, Count); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Count){ return System::Classes::TStream::Write(Buffer, Count); }
	
};


enum TdxSortOption : unsigned char { soDesc, soCaseInsensitive };

typedef System::Set<TdxSortOption, TdxSortOption::soDesc, TdxSortOption::soCaseInsensitive>  TdxSortOptions;

class DELPHICLASS TdxMemIndex;
class PASCALIMPLEMENTATION TdxMemIndex : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool fIsDirty;
	Data::Db::TField* fField;
	TdxSortOptions FSortOptions;
	System::UnicodeString fLoadedFieldName;
	System::UnicodeString fFieldName;
	System::Classes::TList* FValueList;
	TdxIntegerList* FIndexList;
	void __fastcall SetIsDirty(bool Value);
	void __fastcall DeleteRecord(System::PByte pRecord);
	void __fastcall UpdateRecord(System::PByte pRecord);
	void __fastcall SetFieldName(System::UnicodeString Value);
	void __fastcall SetSortOptions(TdxSortOptions Value);
	void __fastcall SetFieldNameAfterMemdataLoaded(void);
	
protected:
	TdxCustomMemData* __fastcall GetMemData(void);
	void __fastcall Prepare(void);
	bool __fastcall GotoNearest(const System::PByte ABuffer, Data::Db::TLocateOptions ALocateOptions, /* out */ int &AIndex);
	__property bool IsDirty = {read=fIsDirty, write=SetIsDirty, nodefault};
	
public:
	__fastcall virtual TdxMemIndex(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxMemIndex(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxCustomMemData* MemData = {read=GetMemData};
	
__published:
	__property System::UnicodeString FieldName = {read=fFieldName, write=SetFieldName};
	__property TdxSortOptions SortOptions = {read=FSortOptions, write=SetSortOptions, nodefault};
};


class DELPHICLASS TdxMemIndexes;
class PASCALIMPLEMENTATION TdxMemIndexes : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
private:
	TdxCustomMemData* fMemData;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall SetIsDirty(void);
	void __fastcall DeleteRecord(System::PByte pRecord);
	void __fastcall UpdateRecord(System::PByte pRecord);
	void __fastcall RemoveField(Data::Db::TField* AField);
	void __fastcall CheckFields(void);
	void __fastcall AfterMemdataLoaded(void);
	
public:
	HIDESBASE TdxMemIndex* __fastcall Add(void);
	TdxMemIndex* __fastcall GetIndexByField(Data::Db::TField* AField);
	__property TdxCustomMemData* MemData = {read=fMemData};
public:
	/* TCollection.Create */ inline __fastcall TdxMemIndexes(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxMemIndexes(void) { }
	
};


enum TdxMemPersistentOption : unsigned char { poNone, poActive, poLoad };

class DELPHICLASS TdxMemPersistent;
class PASCALIMPLEMENTATION TdxMemPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TMemoryStream* FStream;
	TdxMemPersistentOption FOption;
	TdxCustomMemData* FMemData;
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	
public:
	__fastcall TdxMemPersistent(TdxCustomMemData* AMemData);
	__fastcall virtual ~TdxMemPersistent(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall SaveData(void);
	void __fastcall LoadData(void);
	bool __fastcall HasData(void);
	__property TdxCustomMemData* MemData = {read=FMemData};
	
__published:
	__property TdxMemPersistentOption Option = {read=FOption, write=FOption, default=1};
};


class PASCALIMPLEMENTATION TdxCustomMemData : public Data::Db::TDataSet
{
	typedef Data::Db::TDataSet inherited;
	
private:
	bool FActive;
	TdxMemFields* FData;
	int FRecBufSize;
	int FRecInfoOfs;
	int FCurRec;
	int FFilterCurRec;
	TdxIntegerList* FBookMarks;
	System::Classes::TList* FBlobList;
	TdxIntegerList* FFilterList;
	int FLastBookmark;
	bool FSaveChanges;
	bool FReadOnly;
	Data::Db::TField* FRecIdField;
	TdxSortOptions FSortOptions;
	System::UnicodeString FSortedFieldName;
	Data::Db::TField* FSortedField;
	bool FLoadFlag;
	System::WideChar FDelimiterChar;
	bool FIsFiltered;
	int FGotoNearestMin;
	int FGotoNearestMax;
	bool FProgrammedFilter;
	TdxMemIndexes* FIndexes;
	TdxMemPersistent* FPersistent;
	System::PByte __fastcall GetCalcBuffer(void);
	void * __fastcall AllocBufferForFieldValue(System::Variant &AValue, Data::Db::TField* AField);
	void * __fastcall AllocBufferForField(Data::Db::TField* AField);
	TdxSortOptions __fastcall GetSortOptions(void);
	void __fastcall FillValueList(System::Classes::TList* const AList);
	void __fastcall SetSortedField(System::UnicodeString Value);
	void __fastcall SetSortOptions(TdxSortOptions Value);
	void __fastcall SetIndexes(TdxMemIndexes* Value);
	void __fastcall SetPersistent(TdxMemPersistent* Value);
	bool __fastcall GetActiveRecBuf(System::PByte &ARecordBuffer);
	void __fastcall DoSort(System::Classes::TList* AList, TdxMemField* AmdField, TdxSortOptions ASortOptions, System::Classes::TList* AExhangeList);
	void __fastcall MakeSort(void);
	void __fastcall CreateRecIDField(void);
	void __fastcall CheckFields(System::UnicodeString FieldsName);
	int __fastcall GetStringLength(Data::Db::TFieldType AFieldType, const void * ABuffer);
	int __fastcall InternalSetRecNo(const int Value);
	int __fastcall InternalLocate(const System::UnicodeString KeyFields, const System::Variant &KeyValues, Data::Db::TLocateOptions Options);
	void __fastcall UpdateRecordFilteringAndSorting(bool AIsMakeSort);
	bool __fastcall InternalIsFiltering(void);
	__property System::PByte CalcBuffer = {read=GetCalcBuffer};
	__property bool IsBinaryDataLoading = {read=FLoadFlag, nodefault};
	
protected:
	HIDESBASE System::PByte __fastcall ActiveBuffer(void);
	void __fastcall InitializeBlobData(System::PByte ABuffer);
	void __fastcall FinalizeBlobData(System::PByte ABuffer);
	System::PByte __fastcall GetRecordData(System::PByte ARecordBuffer);
	bool __fastcall GetBlobInfo(System::PByte ADataBuffer, int AOffSet, /* out */ System::PByte &ABlobData, /* out */ int &ABlobSize)/* overload */;
	bool __fastcall GetBlobInfo(System::PByte ARecordBuffer, Data::Db::TField* AField, /* out */ System::PByte &ABlobData, /* out */ int &ABlobSize)/* overload */;
	System::PByte __fastcall GetBlobPointer(System::PByte ADataBuffer, int AOffSet);
	System::AnsiString __fastcall GetBlobData(System::PByte ADataBuffer, int AOffSet)/* overload */;
	System::AnsiString __fastcall GetBlobData(System::PByte ARecordBuffer, Data::Db::TField* AField)/* overload */;
	void __fastcall SetInternalBlobData(System::PByte ADataBuffer, int AOffSet, System::PByte AValue, int ASize)/* overload */;
	void __fastcall SetInternalBlobData(System::PByte ADataBuffer, int AOffSet, System::AnsiString AValue)/* overload */;
	void __fastcall SetBlobData(System::PByte ADataBuffer, int AOffSet, const System::PByte AValue, int ASize)/* overload */;
	void __fastcall SetBlobData(System::PByte ARecordBuffer, Data::Db::TField* AField, const System::AnsiString AValue)/* overload */;
	void __fastcall SetBlobData(System::PByte ARecordBuffer, Data::Db::TField* AField, const System::PByte AValue, int ASize)/* overload */;
	System::AnsiString __fastcall GetActiveBlobData(Data::Db::TField* Field);
	void __fastcall GetMemBlobData(System::PByte Buffer);
	void __fastcall SetMemBlobData(System::PByte Buffer);
	void __fastcall BlobClear(void);
	virtual void __fastcall Loaded(void);
	virtual System::PByte __fastcall AllocRecordBuffer(void);
	virtual void __fastcall FreeRecordBuffer(System::PByte &Buffer);
	virtual void __fastcall GetBookmarkData(System::PByte Buffer, void * Data)/* overload */;
	virtual void __fastcall GetBookmarkData(System::PByte Buffer, System::DynamicArray<System::Byte> Data)/* overload */;
	virtual Data::Db::TBookmarkFlag __fastcall GetBookmarkFlag(System::PByte Buffer);
	virtual Data::Db::TGetResult __fastcall GetRecord(System::PByte Buffer, Data::Db::TGetMode GetMode, bool DoCheck);
	virtual System::Word __fastcall GetRecordSize(void);
	virtual void __fastcall InternalAddRecord(void * Buffer, bool Append)/* overload */;
	virtual void __fastcall InternalAddRecord(System::PByte Buffer, bool Append)/* overload */;
	virtual void __fastcall InternalInsert(void);
	virtual void __fastcall InternalClose(void);
	virtual void __fastcall InternalDelete(void);
	virtual void __fastcall InternalFirst(void);
	virtual void __fastcall InternalGotoBookmark(void * Bookmark)/* overload */;
	virtual void __fastcall InternalHandleException(void);
	virtual void __fastcall InternalInitFieldDefs(void);
	virtual void __fastcall InternalInitRecord(System::PByte Buffer);
	virtual void __fastcall InternalLast(void);
	virtual void __fastcall InternalOpen(void);
	virtual void __fastcall InternalPost(void);
	virtual void __fastcall InternalSetToRecord(System::PByte Buffer);
	virtual bool __fastcall IsCursorOpen(void);
	virtual void __fastcall SetBookmarkFlag(System::PByte Buffer, Data::Db::TBookmarkFlag Value);
	virtual void __fastcall SetBookmarkData(System::PByte Buffer, void * Data)/* overload */;
	virtual void __fastcall SetBookmarkData(System::PByte Buffer, System::DynamicArray<System::Byte> Data)/* overload */;
	virtual void __fastcall SetFieldData(Data::Db::TField* Field, System::DynamicArray<System::Byte> Buffer)/* overload */;
	virtual void __fastcall SetFieldData(Data::Db::TField* Field, System::DynamicArray<System::Byte> Buffer, bool NativeFormat)/* overload */;
	virtual System::Variant __fastcall GetStateFieldValue(Data::Db::TDataSetState State, Data::Db::TField* Field);
	virtual void __fastcall DoAfterCancel(void);
	virtual void __fastcall DoAfterClose(void);
	virtual void __fastcall DoAfterInsert(void);
	virtual void __fastcall DoAfterOpen(void);
	virtual void __fastcall DoAfterPost(void);
	virtual void __fastcall DoBeforeClose(void);
	virtual void __fastcall DoBeforeInsert(void);
	virtual void __fastcall DoBeforeOpen(void);
	virtual void __fastcall DoBeforePost(void);
	virtual void __fastcall DoOnNewRecord(void);
	virtual void __fastcall ClearCalcFields(System::PByte Buffer);
	virtual void __fastcall GetCalcFields(System::PByte Buffer);
	virtual Data::Db::TFieldClass __fastcall GetFieldClass(Data::Db::TFieldType FieldType)/* overload */;
	virtual int __fastcall GetRecordCount(void);
	virtual int __fastcall GetRecNo(void);
	virtual void __fastcall SetRecNo(int Value);
	virtual bool __fastcall GetCanModify(void);
	virtual void __fastcall SetFiltered(bool Value);
	System::AnsiString __fastcall GetAnsiStringValue(const System::PByte ABuffer);
	System::WideString __fastcall GetWideStringValue(const System::PByte ABuffer);
	int __fastcall GetIntegerValue(const System::PByte ABuffer, Data::Db::TFieldType ADataType);
	__int64 __fastcall GetLargeIntValue(const System::PByte ABuffer);
	double __fastcall GetFloatValue(const System::PByte ABuffer);
	System::Extended __fastcall GetExtendedValue(const System::PByte ABuffer);
	System::Currency __fastcall GetCurrencyValue(const System::PByte ABuffer);
	System::TDateTime __fastcall GetDateTimeValue(const System::PByte ABuffer, Data::Db::TField* AField);
	Data::Sqltimst::TSQLTimeStamp __fastcall GetTimeStampValue(const System::PByte ABuffer, Data::Db::TField* AField);
	System::Variant __fastcall GetVariantValue(const System::PByte ABuffer, Data::Db::TField* AField);
	int __fastcall InternalCompareValues(const void * ABuffer1, const void * ABuffer2, TdxMemField* AMemField, bool AIsCaseInSensitive, int ACount = 0xffffffff);
	int __fastcall CompareValues(const System::PByte ABuffer1, const System::PByte ABuffer2, TdxMemField* AMemField, TdxSortOptions ASortOptions)/* overload */;
	int __fastcall CompareValues(const System::PByte ABuffer1, const System::PByte ABuffer2, TdxMemField* AMemField)/* overload */;
	int __fastcall CompareValues(const System::PByte ABuffer1, const System::PByte ABuffer2, Data::Db::TField* AField)/* overload */;
	bool __fastcall InternalGotoNearest(System::Classes::TList* AList, Data::Db::TField* AField, const System::PByte ABuffer, TdxSortOptions ASortOptions, Data::Db::TLocateOptions ALocateOptions, /* out */ int &AIndex);
	bool __fastcall GotoNearest(const System::PByte ABuffer, TdxSortOptions ASortOptions, Data::Db::TLocateOptions ALocateOptions, /* out */ int &AIndex);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall SetOnFilterRecord(const Data::Db::TFilterRecordEvent Value);
	void __fastcall InternalAddFilterRecord(void);
	void __fastcall MakeRecordSort(void);
	virtual void __fastcall UpdateFilterRecord(void);
	virtual void __fastcall CloseBlob(Data::Db::TField* Field);
	
public:
	__fastcall virtual TdxCustomMemData(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomMemData(void);
	virtual bool __fastcall GetFieldData(Data::Db::TField* Field, System::DynamicArray<System::Byte> Buffer)/* overload */;
	virtual bool __fastcall GetFieldData(Data::Db::TField* Field, System::DynamicArray<System::Byte> Buffer, bool NativeFormat)/* overload */;
	virtual bool __fastcall BookmarkValid(System::DynamicArray<System::Byte> Bookmark);
	virtual bool __fastcall GetCurrentRecord(System::PByte Buffer);
	virtual int __fastcall CompareBookmarks(System::DynamicArray<System::Byte> Bookmark1, System::DynamicArray<System::Byte> Bookmark2);
	virtual System::Classes::TStream* __fastcall CreateBlobStream(Data::Db::TField* Field, Data::Db::TBlobStreamMode Mode);
	virtual bool __fastcall Locate(const System::UnicodeString KeyFields, const System::Variant &KeyValues, Data::Db::TLocateOptions Options);
	virtual System::Variant __fastcall Lookup(const System::UnicodeString KeyFields, const System::Variant &KeyValues, const System::UnicodeString ResultFields);
	DYNAMIC void __fastcall LoadFromTextFile(const System::UnicodeString AFileName);
	DYNAMIC void __fastcall SaveToTextFile(const System::UnicodeString AFileName);
	DYNAMIC void __fastcall LoadFromStrings(System::Classes::TStrings* AStrings);
	DYNAMIC void __fastcall SaveToStrings(System::Classes::TStrings* AStrings);
	DYNAMIC void __fastcall LoadFromBinaryFile(const System::UnicodeString AFileName);
	DYNAMIC void __fastcall SaveToBinaryFile(const System::UnicodeString AFileName);
	DYNAMIC void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	DYNAMIC void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall AddFieldsFromDataSet(Data::Db::TDataSet* ADataSet, System::Classes::TComponent* AOwner = (System::Classes::TComponent*)(0x0));
	void __fastcall CreateFieldsFromBinaryFile(const System::UnicodeString AFileName);
	void __fastcall CreateFieldsFromStream(System::Classes::TStream* Stream);
	void __fastcall CreateFieldsFromDataSet(Data::Db::TDataSet* ADataSet, System::Classes::TComponent* AOwner = (System::Classes::TComponent*)(0x0));
	void __fastcall LoadFromDataSet(Data::Db::TDataSet* DataSet);
	void __fastcall CopyFromDataSet(Data::Db::TDataSet* DataSet);
	virtual int __fastcall GetRecNoByFieldValue(System::Variant &Value, System::UnicodeString FieldName);
	virtual bool __fastcall SupportedFieldType(Data::Db::TFieldType AType);
	void __fastcall FillBookMarks(void);
	void __fastcall MoveCurRecordTo(int AIndex);
	virtual void __fastcall UpdateFilters(void);
	int __fastcall GetValueCount(System::UnicodeString AFieldName, System::Variant &AValue);
	void __fastcall SetFilteredRecNo(int Value);
	__property int CurRec = {read=FCurRec, write=FCurRec, nodefault};
	__property BlobFieldCount;
	__property System::Classes::TList* BlobList = {read=FBlobList};
	__property TdxIntegerList* FilterList = {read=FFilterList};
	__property bool ProgrammedFilter = {read=FProgrammedFilter, write=FProgrammedFilter, nodefault};
	__property Data::Db::TField* RecIdField = {read=FRecIdField};
	__property bool IsLoading = {read=FLoadFlag, write=FLoadFlag, nodefault};
	__property TdxMemFields* Data = {read=FData};
	__property System::WideChar DelimiterChar = {read=FDelimiterChar, write=FDelimiterChar, nodefault};
	__property Filter = {default=0};
	__property TdxMemIndexes* Indexes = {read=FIndexes, write=SetIndexes};
	__property TdxMemPersistent* Persistent = {read=FPersistent, write=SetPersistent};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property TdxSortOptions SortOptions = {read=GetSortOptions, write=SetSortOptions, nodefault};
	__property System::UnicodeString SortedField = {read=FSortedFieldName, write=SetSortedField};
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  InternalGotoBookmark(System::DynamicArray<System::Byte> Bookmark){ Data::Db::TDataSet::InternalGotoBookmark(Bookmark); }
	inline void __fastcall  SetFieldData _DEPRECATED_ATTRIBUTE1("Use overloaded method instead") (Data::Db::TField* Field, void * Buffer){ Data::Db::TDataSet::SetFieldData(Field, Buffer); }
	inline void __fastcall  SetFieldData _DEPRECATED_ATTRIBUTE1("Use overloaded method instead") (Data::Db::TField* Field, void * Buffer, bool NativeFormat){ Data::Db::TDataSet::SetFieldData(Field, Buffer, NativeFormat); }
	inline Data::Db::TFieldClass __fastcall  GetFieldClass(Data::Db::TFieldDef* FieldDef){ return Data::Db::TDataSet::GetFieldClass(FieldDef); }
	
public:
	inline bool __fastcall  GetFieldData(int FieldNo, System::DynamicArray<System::Byte> Buffer){ return Data::Db::TDataSet::GetFieldData(FieldNo, Buffer); }
	inline bool __fastcall  GetFieldData _DEPRECATED_ATTRIBUTE1("Use overloaded method instead") (Data::Db::TField* Field, void * Buffer){ return Data::Db::TDataSet::GetFieldData(Field, Buffer); }
	inline bool __fastcall  GetFieldData _DEPRECATED_ATTRIBUTE1("Use overloaded method instead") (int FieldNo, void * Buffer){ return Data::Db::TDataSet::GetFieldData(FieldNo, Buffer); }
	inline bool __fastcall  GetFieldData _DEPRECATED_ATTRIBUTE1("Use overloaded method instead") (Data::Db::TField* Field, void * Buffer, bool NativeFormat){ return Data::Db::TDataSet::GetFieldData(Field, Buffer, NativeFormat); }
	
};


class DELPHICLASS TdxMemData;
class PASCALIMPLEMENTATION TdxMemData : public TdxCustomMemData
{
	typedef TdxCustomMemData inherited;
	
__published:
	__property Active = {default=0};
	__property Indexes;
	__property Persistent;
	__property ReadOnly = {default=0};
	__property SortOptions;
	__property SortedField = {default=0};
	__property BeforeOpen;
	__property AfterOpen;
	__property BeforeClose;
	__property AfterClose;
	__property BeforeInsert;
	__property AfterInsert;
	__property BeforeEdit;
	__property AfterEdit;
	__property BeforePost;
	__property AfterPost;
	__property BeforeCancel;
	__property AfterCancel;
	__property BeforeDelete;
	__property AfterDelete;
	__property BeforeScroll;
	__property AfterScroll;
	__property OnCalcFields;
	__property OnDeleteError;
	__property OnEditError;
	__property OnNewRecord;
	__property OnPostError;
	__property OnFilterRecord;
public:
	/* TdxCustomMemData.Create */ inline __fastcall virtual TdxMemData(System::Classes::TComponent* AOwner) : TdxCustomMemData(AOwner) { }
	/* TdxCustomMemData.Destroy */ inline __fastcall virtual ~TdxMemData(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
#define MemDataVer  (1.910000E+00)
extern PACKAGE void __fastcall DateTimeToMemDataValue(System::TDateTime Value, System::PByte pt, Data::Db::TField* Field);
extern PACKAGE bool __fastcall VariantToMemDataValue(System::Variant &AValue, void * AMemDataValue, Data::Db::TField* AField);
}	/* namespace Dxmdaset */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXMDASET)
using namespace Dxmdaset;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxmdasetHPP
