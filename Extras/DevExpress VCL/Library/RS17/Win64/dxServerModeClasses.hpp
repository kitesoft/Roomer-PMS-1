// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeClasses.pas' rev: 24.00 (Win64)

#ifndef DxservermodeclassesHPP
#define DxservermodeclassesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodeclasses
{
//-- type declarations -------------------------------------------------------
enum TdxNullableBoolean : unsigned char { bNull, bTrue, bFalse };

enum TdxKeyType : unsigned char { ktInteger };

enum TdxRowType : unsigned char { rtRow };

enum TdxBlockRelation : unsigned char { brNone, brLess, brPrev, brIntersectStart, brEquals, brIntersectFinish, brNext, brGreater };

class DELPHICLASS TdxServerModeException;
class PASCALIMPLEMENTATION TdxServerModeException : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall TdxServerModeException(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall TdxServerModeException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall TdxServerModeException(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall TdxServerModeException(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall TdxServerModeException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall TdxServerModeException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall TdxServerModeException(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall TdxServerModeException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall TdxServerModeException(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall TdxServerModeException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall TdxServerModeException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall TdxServerModeException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~TdxServerModeException(void) { }
	
};


class DELPHICLASS TdxServerModeInvalidOperationException;
class PASCALIMPLEMENTATION TdxServerModeInvalidOperationException : public TdxServerModeException
{
	typedef TdxServerModeException inherited;
	
public:
	/* Exception.Create */ inline __fastcall TdxServerModeInvalidOperationException(const System::UnicodeString Msg) : TdxServerModeException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall TdxServerModeInvalidOperationException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : TdxServerModeException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall TdxServerModeInvalidOperationException(NativeUInt Ident)/* overload */ : TdxServerModeException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall TdxServerModeInvalidOperationException(System::PResStringRec ResStringRec)/* overload */ : TdxServerModeException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall TdxServerModeInvalidOperationException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : TdxServerModeException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall TdxServerModeInvalidOperationException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : TdxServerModeException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall TdxServerModeInvalidOperationException(const System::UnicodeString Msg, int AHelpContext) : TdxServerModeException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall TdxServerModeInvalidOperationException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : TdxServerModeException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall TdxServerModeInvalidOperationException(NativeUInt Ident, int AHelpContext)/* overload */ : TdxServerModeException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall TdxServerModeInvalidOperationException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : TdxServerModeException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall TdxServerModeInvalidOperationException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : TdxServerModeException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall TdxServerModeInvalidOperationException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : TdxServerModeException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~TdxServerModeInvalidOperationException(void) { }
	
};


class DELPHICLASS TdxServerModeInconsistencyDetectedException;
class PASCALIMPLEMENTATION TdxServerModeInconsistencyDetectedException : public TdxServerModeException
{
	typedef TdxServerModeException inherited;
	
public:
	/* Exception.Create */ inline __fastcall TdxServerModeInconsistencyDetectedException(const System::UnicodeString Msg) : TdxServerModeException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall TdxServerModeInconsistencyDetectedException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : TdxServerModeException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall TdxServerModeInconsistencyDetectedException(NativeUInt Ident)/* overload */ : TdxServerModeException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall TdxServerModeInconsistencyDetectedException(System::PResStringRec ResStringRec)/* overload */ : TdxServerModeException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall TdxServerModeInconsistencyDetectedException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : TdxServerModeException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall TdxServerModeInconsistencyDetectedException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : TdxServerModeException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall TdxServerModeInconsistencyDetectedException(const System::UnicodeString Msg, int AHelpContext) : TdxServerModeException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall TdxServerModeInconsistencyDetectedException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : TdxServerModeException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall TdxServerModeInconsistencyDetectedException(NativeUInt Ident, int AHelpContext)/* overload */ : TdxServerModeException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall TdxServerModeInconsistencyDetectedException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : TdxServerModeException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall TdxServerModeInconsistencyDetectedException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : TdxServerModeException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall TdxServerModeInconsistencyDetectedException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : TdxServerModeException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~TdxServerModeInconsistencyDetectedException(void) { }
	
};


typedef System::Variant TdxServerModeRow;

class DELPHICLASS TdxServerModeRowList;
class PASCALIMPLEMENTATION TdxServerModeRowList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Variant operator[](int Index) { return Items[Index]; }
	
private:
	Cxvariants::TVariantArray FList;
	int __fastcall GetCount(void);
	System::Variant __fastcall GetItem(int Index);
	System::Variant __fastcall GetLast(void);
	void __fastcall SetCount(const int Value);
	void __fastcall SetLast(const System::Variant &Value);
	
public:
	__fastcall virtual ~TdxServerModeRowList(void);
	int __fastcall Add(const System::Variant &Value);
	void __fastcall Insert(int Index, const System::Variant &Value);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property System::Variant Items[int Index] = {read=GetItem/*, default*/};
	__property System::Variant Last = {read=GetLast, write=SetLast};
	__property Cxvariants::TVariantArray List = {read=FList};
public:
	/* TObject.Create */ inline __fastcall TdxServerModeRowList(void) : System::TObject() { }
	
};


class DELPHICLASS TdxServerModeKeyList;
class PASCALIMPLEMENTATION TdxServerModeKeyList : public TdxServerModeRowList
{
	typedef TdxServerModeRowList inherited;
	
public:
	/* TdxServerModeRowList.Destroy */ inline __fastcall virtual ~TdxServerModeKeyList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxServerModeKeyList(void) : TdxServerModeRowList() { }
	
};


class DELPHICLASS TdxServerModeSummaryList;
class PASCALIMPLEMENTATION TdxServerModeSummaryList : public TdxServerModeRowList
{
	typedef TdxServerModeRowList inherited;
	
public:
	/* TdxServerModeRowList.Destroy */ inline __fastcall virtual ~TdxServerModeSummaryList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxServerModeSummaryList(void) : TdxServerModeRowList() { }
	
};


class DELPHICLASS TdxServerModeIntDictionaryItem;
class PASCALIMPLEMENTATION TdxServerModeIntDictionaryItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FKey;
	TdxServerModeIntDictionaryItem* FNext;
	System::Variant FValue;
	
public:
	__fastcall TdxServerModeIntDictionaryItem(int AKey, const System::Variant &AValue);
	__property int Key = {read=FKey, nodefault};
	__property TdxServerModeIntDictionaryItem* Next = {read=FNext};
	__property System::Variant Value = {read=FValue, write=FValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeIntDictionaryItem(void) { }
	
};


class DELPHICLASS TdxCustomServerModeIntDictionary;
class PASCALIMPLEMENTATION TdxCustomServerModeIntDictionary : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<TdxServerModeIntDictionaryItem*> _TdxCustomServerModeIntDictionary__1;
	
	
private:
	int FCount;
	_TdxCustomServerModeIntDictionary__1 FTable;
	int FTableSize;
	
protected:
	TdxServerModeIntDictionaryItem* __fastcall Find(int AKey);
	
public:
	__fastcall TdxCustomServerModeIntDictionary(int ATableSize);
	__fastcall virtual ~TdxCustomServerModeIntDictionary(void);
	TdxServerModeIntDictionaryItem* __fastcall Add(int AKey, const System::Variant &AValue);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(int AKey);
	bool __fastcall TryGetValue(int AKey, /* out */ System::Variant &AValue);
	__property int Count = {read=FCount, nodefault};
};


class DELPHICLASS TdxServerModeLinkedDictionaryItem;
class PASCALIMPLEMENTATION TdxServerModeLinkedDictionaryItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FKey;
	TdxServerModeLinkedDictionaryItem* FNext;
	TdxServerModeIntDictionaryItem* FValue;
	
public:
	__fastcall TdxServerModeLinkedDictionaryItem(unsigned AKey, TdxServerModeIntDictionaryItem* AValue);
	__property unsigned Key = {read=FKey, nodefault};
	__property TdxServerModeLinkedDictionaryItem* Next = {read=FNext};
	__property TdxServerModeIntDictionaryItem* Value = {read=FValue, write=FValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeLinkedDictionaryItem(void) { }
	
};


class DELPHICLASS TdxServerModeLinkedDictionary;
class PASCALIMPLEMENTATION TdxServerModeLinkedDictionary : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<TdxServerModeLinkedDictionaryItem*> _TdxServerModeLinkedDictionary__1;
	
	
private:
	int FCount;
	_TdxServerModeLinkedDictionary__1 FTable;
	unsigned FTableSize;
	
protected:
	TdxServerModeLinkedDictionaryItem* __fastcall Find(const System::Variant &AKey);
	
public:
	__fastcall TdxServerModeLinkedDictionary(int ATableSize);
	__fastcall virtual ~TdxServerModeLinkedDictionary(void);
	void __fastcall Add(const System::Variant &AKey, TdxServerModeIntDictionaryItem* const AValue);
	void __fastcall Clear(void);
	bool __fastcall ContainsKey(const System::Variant &AKey);
	bool __fastcall TryGetValue(const System::Variant &AKey, /* out */ int &AValue);
	__property int Count = {read=FCount, nodefault};
};


class DELPHICLASS TdxServerModeCustomDictionary;
class PASCALIMPLEMENTATION TdxServerModeCustomDictionary : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomServerModeIntDictionary* FIntDictionary;
	TdxServerModeLinkedDictionary* FLinkedDictionary;
	int __fastcall GetCount(void);
	
protected:
	bool __fastcall GetKeyByValue(const System::Variant &AValue, /* out */ int &AKey);
	
public:
	__fastcall TdxServerModeCustomDictionary(int ATableSize);
	__fastcall virtual ~TdxServerModeCustomDictionary(void);
	void __fastcall Add(int AKey, const System::Variant &AValue);
	virtual void __fastcall Clear(void);
	bool __fastcall ContainsKey(int AKey);
	bool __fastcall TryGetValue(int AKey, /* out */ System::Variant &AValue);
	__property int Count = {read=GetCount, nodefault};
};


class DELPHICLASS TdxServerModeRowsDictionary;
class PASCALIMPLEMENTATION TdxServerModeRowsDictionary : public TdxCustomServerModeIntDictionary
{
	typedef TdxCustomServerModeIntDictionary inherited;
	
public:
	/* TdxCustomServerModeIntDictionary.Create */ inline __fastcall TdxServerModeRowsDictionary(int ATableSize) : TdxCustomServerModeIntDictionary(ATableSize) { }
	/* TdxCustomServerModeIntDictionary.Destroy */ inline __fastcall virtual ~TdxServerModeRowsDictionary(void) { }
	
};


class DELPHICLASS TdxLoadedRecordsBlock;
class PASCALIMPLEMENTATION TdxLoadedRecordsBlock : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FFinish;
	int FStart;
	
public:
	__fastcall TdxLoadedRecordsBlock(int AStart, int AFinish);
	TdxBlockRelation __fastcall GetStatus(int AStart, int AFinish);
	bool __fastcall InRange(int AIndex);
	__property int Finish = {read=FFinish, write=FFinish, nodefault};
	__property int Start = {read=FStart, write=FStart, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLoadedRecordsBlock(void) { }
	
};


class DELPHICLASS TdxLoadedRecordsHelper;
class PASCALIMPLEMENTATION TdxLoadedRecordsHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxLoadedRecordsBlock* operator[](int Index) { return Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastObjectList* FList;
	int __fastcall GetCount(void);
	TdxLoadedRecordsBlock* __fastcall GetFirst(void);
	TdxLoadedRecordsBlock* __fastcall GetItem(int Index);
	TdxLoadedRecordsBlock* __fastcall GetLast(void);
	
protected:
	bool __fastcall FindPosition(int AStart, /* out */ int &AItemIndex);
	void __fastcall UpdateNext(int AItemIndex);
	
public:
	__fastcall TdxLoadedRecordsHelper(void);
	__fastcall virtual ~TdxLoadedRecordsHelper(void);
	void __fastcall Add(int AFirstRecord, int ACount, bool AIsFromBottom)/* overload */;
	void __fastcall Add(int AStart, int AFinish)/* overload */;
	void __fastcall Clear(void);
	void __fastcall GetClosestPopulatedIndexes(int AIndex, /* out */ int &AStartIndex, /* out */ int &AFinishIndex);
	__property int Count = {read=GetCount, nodefault};
	__property TdxLoadedRecordsBlock* First = {read=GetFirst};
	__property TdxLoadedRecordsBlock* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxLoadedRecordsBlock* Last = {read=GetLast};
};


class DELPHICLASS TdxServerModeKeysDictionary;
class PASCALIMPLEMENTATION TdxServerModeKeysDictionary : public TdxServerModeCustomDictionary
{
	typedef TdxServerModeCustomDictionary inherited;
	
protected:
	TdxLoadedRecordsHelper* FLoadedRecordsHelper;
	
public:
	__fastcall TdxServerModeKeysDictionary(int ATableSize);
	__fastcall virtual ~TdxServerModeKeysDictionary(void);
	virtual void __fastcall Clear(void);
	bool __fastcall TryGetKeyByValue(const System::Variant &AValue, /* out */ int &AKey);
	__property TdxLoadedRecordsHelper* LoadedRecordsHelper = {read=FLoadedRecordsHelper};
};


class DELPHICLASS TdxServerModeLoadedKeysChunkDictionary;
class PASCALIMPLEMENTATION TdxServerModeLoadedKeysChunkDictionary : public TdxServerModeCustomDictionary
{
	typedef TdxServerModeCustomDictionary inherited;
	
public:
	__fastcall TdxServerModeLoadedKeysChunkDictionary(void);
	HIDESBASE void __fastcall Add(const System::Variant &AIndex, int AValue);
	HIDESBASE bool __fastcall ContainsKey(const System::Variant &AKey);
	HIDESBASE bool __fastcall TryGetValue(const System::Variant &AIndex, /* out */ int &AValue);
public:
	/* TdxServerModeCustomDictionary.Destroy */ inline __fastcall virtual ~TdxServerModeLoadedKeysChunkDictionary(void) { }
	
};


class DELPHICLASS TdxListSourceGroupInfo;
class PASCALIMPLEMENTATION TdxListSourceGroupInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FDataRowCount;
	int FLevel;
	
public:
	__fastcall TdxListSourceGroupInfo(int ALevel);
	__property int DataRowCount = {read=FDataRowCount, write=FDataRowCount, nodefault};
	__property int Level = {read=FLevel, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxListSourceGroupInfo(void) { }
	
};


class DELPHICLASS TdxServerModeGroupInfo;
class DELPHICLASS TdxServerModeGroupInfoList;
class PASCALIMPLEMENTATION TdxServerModeGroupInfo : public TdxListSourceGroupInfo
{
	typedef TdxListSourceGroupInfo inherited;
	
private:
	TdxServerModeGroupInfoList* FChildrenGroups;
	System::Variant FGroupValue;
	unsigned FGroupValueHash;
	TdxServerModeGroupInfo* FParent;
	TdxServerModeSummaryList* FSummary;
	int FTopDataRowIndex;
	
public:
	__fastcall TdxServerModeGroupInfo(TdxServerModeGroupInfo* AParent, const System::Variant &AGroupValue, int ALevel, int ATopRecordIndex);
	__fastcall virtual ~TdxServerModeGroupInfo(void);
	void __fastcall CreateChildren(void);
	bool __fastcall Contains(int ADataRowIndex);
	bool __fastcall IsEqual(const System::Variant &AValue, unsigned AHash);
	void __fastcall ResetChildren(void);
	__property TdxServerModeGroupInfoList* ChildrenGroups = {read=FChildrenGroups};
	__property System::Variant GroupValue = {read=FGroupValue};
	__property TdxServerModeGroupInfo* Parent = {read=FParent};
	__property TdxServerModeSummaryList* Summary = {read=FSummary};
	__property int TopDataRowIndex = {read=FTopDataRowIndex, nodefault};
};


class PASCALIMPLEMENTATION TdxServerModeGroupInfoList : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	TdxServerModeGroupInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TdxServerModeGroupInfo* FParent;
	HIDESBASE TdxServerModeGroupInfo* __fastcall GetItem(int Index);
	
public:
	__fastcall TdxServerModeGroupInfoList(TdxServerModeGroupInfo* AParent);
	int __fastcall Find(const System::Variant &AGroupValue)/* overload */;
	void __fastcall UpdateDataRowIndexes(void);
	__property TdxServerModeGroupInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxServerModeGroupInfo* Parent = {read=FParent};
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TdxServerModeGroupInfoList(void) { }
	
};


class DELPHICLASS TdxServerModeGroupInfoData;
class PASCALIMPLEMENTATION TdxServerModeGroupInfoData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FDataRowCount;
	System::Variant FGroupValue;
	System::Variant FSummary;
	
public:
	__fastcall TdxServerModeGroupInfoData(const System::Variant &AGroupValue, int AChildDataRowCount, const System::Variant &ASummary)/* overload */;
	__fastcall TdxServerModeGroupInfoData(const System::Variant &AGroupValue, const System::Variant &ASummary)/* overload */;
	__property int DataRowCount = {read=FDataRowCount, nodefault};
	__property System::Variant GroupValue = {read=FGroupValue};
	__property System::Variant Summary = {read=FSummary};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxServerModeGroupInfoData(void) { }
	
};


class DELPHICLASS TdxServerModeGroupInfoDataList;
class PASCALIMPLEMENTATION TdxServerModeGroupInfoDataList : public Dxcoreclasses::TdxFastObjectList
{
	typedef Dxcoreclasses::TdxFastObjectList inherited;
	
public:
	TdxServerModeGroupInfoData* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxServerModeGroupInfoData* __fastcall GetItem(int Index);
	
public:
	__property TdxServerModeGroupInfoData* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxFastObjectList.Create */ inline __fastcall TdxServerModeGroupInfoDataList(bool AOwnsObjects, int ACapacity) : Dxcoreclasses::TdxFastObjectList(AOwnsObjects, ACapacity) { }
	
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TdxServerModeGroupInfoDataList(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Word dxDefaultDictionaryHashTableSize = System::Word(0x41cb);
static const System::Word dxKeysChunkDictionaryHashTableSize = System::Word(0x1069);
}	/* namespace Dxservermodeclasses */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODECLASSES)
using namespace Dxservermodeclasses;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodeclassesHPP
