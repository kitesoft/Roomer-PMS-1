// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxHunspellAffixes.pas' rev: 24.00 (Win64)

#ifndef DxhunspellaffixesHPP
#define DxhunspellaffixesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.StrUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxHunspellUtils.hpp>	// Pascal unit
#include <dxHunspellWords.hpp>	// Pascal unit
#include <dxHunspellTypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxhunspellaffixes
{
//-- type declarations -------------------------------------------------------
enum TdxAffixOption : unsigned char { aoPrefixSuffixUnion, aoAffixFlagAliasTable, aoAffixMorphologyTable, aoCompoundMiddle, aoCompoundEnd, aoInCompoundOnly, aoNeedAffix, aoCompoundForbid, aoCompoundPermit, aoCircumfix };

typedef System::Set<TdxAffixOption, TdxAffixOption::aoPrefixSuffixUnion, TdxAffixOption::aoCircumfix>  TdxAffixOptions;

typedef System::StaticArray<System::Byte, 65536> TdxExistentAffixFlags;

struct DECLSPEC_DRECORD TdxStringData
{
public:
	System::WideChar *Data;
	int Length;
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxReplaceTableItem
{
public:
	System::WideChar *Text;
	System::WideChar *Replacement;
};
#pragma pack(pop)


typedef System::StaticArray<TdxReplaceTableItem, 1> TdxReplaceArray;

typedef TdxReplaceArray *PdxReplaceArray;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxMapTableItem
{
public:
	System::WideChar *CharacterSet;
	int Length;
};
#pragma pack(pop)


typedef System::StaticArray<TdxMapTableItem, 1> TdxMapArray;

typedef TdxMapArray *PdxMapArray;

typedef System::StaticArray<int, 65536> TdxPhoneHashArray;

struct TdxGuessWord;
typedef TdxGuessWord *PdxGuessWord;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGuessWord
{
public:
	System::WideChar *Word;
	System::WideChar *Orig;
	bool Allow;
};
#pragma pack(pop)


typedef System::StaticArray<TdxGuessWord, 1> TdxGuessWordArray;

typedef TdxGuessWordArray *PdxGuessWordArray;

struct DECLSPEC_DRECORD TdxCompoundForbidPattern
{
public:
	System::WideChar *Pattern;
	System::WideChar *Pattern2;
	System::WideChar *Pattern3;
	System::Word Condition;
	System::Word Condition2;
};


typedef System::StaticArray<TdxCompoundForbidPattern, 1> TdxCompoundForbidPatternArray;

typedef TdxCompoundForbidPatternArray *PdxCompoundForbidPatternArray;

enum TdxAffixType : unsigned char { atPrefix, atSuffix };

enum TdxCompoundWordPart : unsigned char { cwpNone, cwpFirst, cwpLast, cwpOther };

class DELPHICLASS TdxAffix;
typedef System::StaticArray<TdxAffix*, 65536> TAffixTable;

typedef System::StaticArray<System::WideChar, 104> TWordFormArray;

typedef System::StaticArray<bool, 65536> TAffixManagerFlagArray;

struct TdxAffixItem;
typedef TdxAffixItem *PdxAffixItem;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxAffixItem
{
public:
	System::WideChar *StripString;
	System::Byte StripStringLength;
	System::WideChar *AppendString;
	System::Byte AppendStringLength;
	System::Int8 ConditionLength;
	Dxhunspellwords::TdxHunspellFlags* CompatibleFlags;
	System::WideChar *MorphologicalDescription;
	System::WideChar *Condition;
};
#pragma pack(pop)


typedef System::StaticArray<TdxAffixItem, 1> TdxAffixItemArray;

typedef TdxAffixItemArray *PdxAffixItemArray;

struct TdxCompoundFlag;
typedef TdxCompoundFlag *PdxCompoundFlag;

struct DECLSPEC_DRECORD TdxCompoundFlag
{
public:
	Dxhunspelltypes::TdxAffixFlagsData *Pattern;
	int Count;
	int Length;
};


typedef System::StaticArray<TdxCompoundFlag, 1> TdxCompoundFlagArray;

typedef TdxCompoundFlagArray *PdxCompoundFlagArray;

typedef System::StaticArray<Dxhunspellwords::TdxHunspellWordStem*, 101> TdxCompoundWordRules;

class DELPHICLASS TdxCustomHunspellDataTable;
class PASCALIMPLEMENTATION TdxCustomHunspellDataTable : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCurrentDataIndex;
	System::WideChar *FDataIdentifier;
	System::WideChar *FCachedIdentifier;
	int FIdentifierLength;
	int FSize;
	void __fastcall FreeData(void);
	
protected:
	void *FData;
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall AfterReadData(void);
	virtual bool __fastcall IsAllPiecesFound(int APieceIndex);
	bool __fastcall CheckDataType(const System::WideChar * APiece);
	virtual void __fastcall FreeDataItems(void) = 0 ;
	virtual int __fastcall GetCount(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void) = 0 ;
	virtual int __fastcall GetDataItemSize(void) = 0 ;
	virtual int __fastcall GetPieceQuantity(void) = 0 ;
	virtual void __fastcall InitializeItem(int Index);
	virtual bool __fastcall ReadDataHeader(System::WideChar * ALine);
	virtual bool __fastcall ParseHeader(System::WideChar * ALine, /* out */ int &ATableSize);
	bool __fastcall ParseData(Dxhunspellwords::TdxHunspellReader* AAffixReader);
	
public:
	__fastcall TdxCustomHunspellDataTable(void)/* overload */;
	__fastcall TdxCustomHunspellDataTable(System::WideChar * ADataIdentifier)/* overload */;
	__fastcall virtual ~TdxCustomHunspellDataTable(void);
	void __fastcall AllocateData(int ASize);
	bool __fastcall ReadData(System::WideChar * ALine, Dxhunspellwords::TdxHunspellReader* AAffixFileReader);
	__property int Count = {read=GetCount, nodefault};
};


class DELPHICLASS TdxHunspellDataLinkedTable;
class DELPHICLASS TdxHunspellAffixManager;
class PASCALIMPLEMENTATION TdxHunspellDataLinkedTable : public TdxCustomHunspellDataTable
{
	typedef TdxCustomHunspellDataTable inherited;
	
private:
	TdxHunspellAffixManager* FAffixManager;
	Dxhunspellwords::TdxHunspellWordStemManager* __fastcall GetWordStemManager(void);
	
public:
	__fastcall TdxHunspellDataLinkedTable(TdxHunspellAffixManager* AAffixManager);
	__property TdxHunspellAffixManager* AffixManager = {read=FAffixManager};
	__property Dxhunspellwords::TdxHunspellWordStemManager* WordStemManager = {read=GetWordStemManager};
public:
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxHunspellDataLinkedTable(void) { }
	
};


class DELPHICLASS TdxAffixItemTable;
class PASCALIMPLEMENTATION TdxAffixItemTable : public TdxHunspellDataLinkedTable
{
	typedef TdxHunspellDataLinkedTable inherited;
	
public:
	TdxAffixItem operator[](int Index) { return Items[Index]; }
	
private:
	bool FAffixesIsCreated;
	System::Word FDecodedFlag;
	System::WideChar *FFlag;
	bool FPrefixSuffixUnion;
	void __fastcall AddLineRemainderToMorphologicDescription(System::WideChar * ALine, int ADataIndex);
	bool __fastcall CheckFlag(System::WideChar * ALine);
	int __fastcall ConditionLength(System::WideChar * ALine);
	bool __fastcall EncodeAffixCondition(System::WideChar * ALine, int ADataIndex);
	bool __fastcall HasAffixFlagAliases(void);
	bool __fastcall HasAffixMorphologicAliases(void);
	bool __fastcall FlagIsNil(void);
	void __fastcall FreeIfZero(TdxStringData &AString);
	PdxAffixItemArray __fastcall GetData(void);
	TdxAffixItem __fastcall GetItem(int Index);
	TdxAffixOptions __fastcall GetOptions(const TdxAffixItem &AItem);
	bool __fastcall IsReverseWritingDirection(void);
	void __fastcall ParseAppendString(const System::WideChar * ALine, int ADataIndex);
	bool __fastcall ParseAppendStringWithAffixes(const System::WideChar * ALine, int ADataIndex);
	bool __fastcall ParseCompatibleFlags(const System::WideChar * ALine, int ADataIndex);
	bool __fastcall ParseCondition(System::WideChar * ALine, int ADataIndex);
	bool __fastcall ParseFlag(System::WideChar * ALine);
	bool __fastcall ParseMorphologicDescription(System::WideChar * ALine, int ADataIndex);
	void __fastcall ParsePrefixSuffixUnion(System::WideChar * ALine);
	void __fastcall ParseStripString(const System::WideChar * ALine, int ADataIndex);
	bool __fastcall ParseTableSize(System::WideChar * ALine, /* out */ int &ATableSize);
	void __fastcall ProcessReverseString(System::WideChar * ALine);
	void __fastcall RegisterCompatibleFlags(int ADataIndex);
	void __fastcall ReverseCondition(System::WideChar * ACondition);
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual bool __fastcall IsAllPiecesFound(int APieceIndex);
	bool __fastcall IsComplexPrefixes(void);
	virtual void __fastcall BuildAffixes(void);
	virtual bool __fastcall ConditionContainsDuplicateInformation(System::WideChar * AStripString, int AStripStringLen, const System::WideChar * ACondition, /* out */ bool &Contains) = 0 ;
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual int __fastcall GetPieceQuantity(void);
	virtual void __fastcall FreeDataItems(void);
	virtual bool __fastcall IsPrefix(void) = 0 ;
	virtual bool __fastcall ParseHeader(System::WideChar * ALine, /* out */ int &ATableSize);
	__property PdxAffixItemArray Data = {read=GetData};
	__property TdxAffixItem Items[int Index] = {read=GetItem/*, default*/};
	
public:
	__fastcall virtual ~TdxAffixItemTable(void);
	__property System::WideChar * Flag = {read=FFlag};
public:
	/* TdxHunspellDataLinkedTable.Create */ inline __fastcall TdxAffixItemTable(TdxHunspellAffixManager* AAffixManager) : TdxHunspellDataLinkedTable(AAffixManager) { }
	
};


typedef System::TMetaClass* TdxAffixItemTableClass;

class DELPHICLASS TdxPrefixItemTable;
class PASCALIMPLEMENTATION TdxPrefixItemTable : public TdxAffixItemTable
{
	typedef TdxAffixItemTable inherited;
	
protected:
	virtual bool __fastcall ConditionContainsDuplicateInformation(System::WideChar * AStripString, int AStripStringLen, const System::WideChar * ACondition, /* out */ bool &AContains);
	virtual bool __fastcall IsPrefix(void);
	
public:
	virtual void __fastcall BuildAffixes(void);
public:
	/* TdxAffixItemTable.Destroy */ inline __fastcall virtual ~TdxPrefixItemTable(void) { }
	
public:
	/* TdxHunspellDataLinkedTable.Create */ inline __fastcall TdxPrefixItemTable(TdxHunspellAffixManager* AAffixManager) : TdxAffixItemTable(AAffixManager) { }
	
};


class DELPHICLASS TdxSuffixItemTable;
class PASCALIMPLEMENTATION TdxSuffixItemTable : public TdxAffixItemTable
{
	typedef TdxAffixItemTable inherited;
	
protected:
	virtual bool __fastcall ConditionContainsDuplicateInformation(System::WideChar * AStripString, int AStripStringLength, const System::WideChar * ACondition, /* out */ bool &Contains);
	virtual bool __fastcall IsPrefix(void);
	
public:
	virtual void __fastcall BuildAffixes(void);
public:
	/* TdxAffixItemTable.Destroy */ inline __fastcall virtual ~TdxSuffixItemTable(void) { }
	
public:
	/* TdxHunspellDataLinkedTable.Create */ inline __fastcall TdxSuffixItemTable(TdxHunspellAffixManager* AAffixManager) : TdxAffixItemTable(AAffixManager) { }
	
};


class DELPHICLASS TdxBreakTable;
class PASCALIMPLEMENTATION TdxBreakTable : public TdxCustomHunspellDataTable
{
	typedef TdxCustomHunspellDataTable inherited;
	
public:
	System::WideChar * operator[](int Index) { return Items[Index]; }
	
private:
	void __fastcall FillDefaultData(void);
	Dxhunspelltypes::PdxPWideCharArray __fastcall GetData(void);
	System::WideChar * __fastcall GetItem(int Index);
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall FreeDataItems(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual int __fastcall GetPieceQuantity(void);
	
public:
	__fastcall TdxBreakTable(void);
	__property Dxhunspelltypes::PdxPWideCharArray Data = {read=GetData};
	__property System::WideChar * Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxBreakTable(void) { }
	
};


class DELPHICLASS TdxCheckCompoundPatternTable;
class PASCALIMPLEMENTATION TdxCheckCompoundPatternTable : public TdxHunspellDataLinkedTable
{
	typedef TdxHunspellDataLinkedTable inherited;
	
public:
	TdxCompoundForbidPattern operator[](int Index) { return Items[Index]; }
	
private:
	bool FIsSimplified;
	void __fastcall ExtractCondition(System::WideChar * APattern, System::Word &ACondition);
	PdxCompoundForbidPatternArray __fastcall GetData(void);
	TdxCompoundForbidPattern __fastcall GetItem(int Index);
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall FreeDataItems(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual int __fastcall GetPieceQuantity(void);
	virtual void __fastcall InitializeItem(int Index);
	
public:
	__property PdxCompoundForbidPatternArray Data = {read=GetData};
	__property bool IsSimplified = {read=FIsSimplified, nodefault};
	__property TdxCompoundForbidPattern Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxHunspellDataLinkedTable.Create */ inline __fastcall TdxCheckCompoundPatternTable(TdxHunspellAffixManager* AAffixManager) : TdxHunspellDataLinkedTable(AAffixManager) { }
	
public:
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxCheckCompoundPatternTable(void) { }
	
};


class DELPHICLASS TdxCompoundRuleTable;
class PASCALIMPLEMENTATION TdxCompoundRuleTable : public TdxHunspellDataLinkedTable
{
	typedef TdxHunspellDataLinkedTable inherited;
	
public:
	TdxCompoundFlag operator[](int Index) { return Items[Index]; }
	
private:
	PdxCompoundFlagArray __fastcall GetData(void);
	TdxCompoundFlag __fastcall GetItem(int Index);
	bool __fastcall ParseFlags(System::WideChar * APiece, int AIndex);
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall FreeDataItems(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual int __fastcall GetPieceQuantity(void);
	virtual void __fastcall InitializeItem(int Index);
	
public:
	bool __fastcall IsPartOfCompoundWordFlag(System::WideChar * AFlag)/* overload */;
	bool __fastcall IsPartOfCompoundWordFlag(System::Word AFlag)/* overload */;
	__property PdxCompoundFlagArray Data = {read=GetData};
	__property TdxCompoundFlag Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxHunspellDataLinkedTable.Create */ inline __fastcall TdxCompoundRuleTable(TdxHunspellAffixManager* AAffixManager) : TdxHunspellDataLinkedTable(AAffixManager) { }
	
public:
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxCompoundRuleTable(void) { }
	
};


class DELPHICLASS TdxMapTable;
class PASCALIMPLEMENTATION TdxMapTable : public TdxCustomHunspellDataTable
{
	typedef TdxCustomHunspellDataTable inherited;
	
public:
	TdxMapTableItem operator[](int Index) { return Items[Index]; }
	
private:
	PdxMapArray __fastcall GetData(void);
	TdxMapTableItem __fastcall GetItem(int Index);
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall FreeDataItems(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual int __fastcall GetPieceQuantity(void);
	virtual void __fastcall InitializeItem(int Index);
	
public:
	__property PdxMapArray Data = {read=GetData};
	__property TdxMapTableItem Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxCustomHunspellDataTable.Create */ inline __fastcall TdxMapTable(void)/* overload */ : TdxCustomHunspellDataTable() { }
	/* TdxCustomHunspellDataTable.Create */ inline __fastcall TdxMapTable(System::WideChar * ADataIdentifier)/* overload */ : TdxCustomHunspellDataTable(ADataIdentifier) { }
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxMapTable(void) { }
	
};


class DELPHICLASS TdxPhoneTable;
class PASCALIMPLEMENTATION TdxPhoneTable : public TdxCustomHunspellDataTable
{
	typedef TdxCustomHunspellDataTable inherited;
	
private:
	int FCount;
	Dxhunspelltypes::TdxPWideCharArray *FRules;
	TdxPhoneHashArray FHash;
	void __fastcall InitializeHash(void);
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall AfterReadData(void);
	virtual void __fastcall FreeDataItems(void);
	void __fastcall FreeRules(void);
	virtual int __fastcall GetCount(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetPieceQuantity(void);
	virtual bool __fastcall ReadDataHeader(System::WideChar * ALine);
	__property Dxhunspelltypes::PdxPWideCharArray Rules = {read=FRules};
	
public:
	__fastcall virtual ~TdxPhoneTable(void);
	int __fastcall Phonetic(const System::WideChar * AWord, System::WideChar * ADest, int ALength);
public:
	/* TdxCustomHunspellDataTable.Create */ inline __fastcall TdxPhoneTable(void)/* overload */ : TdxCustomHunspellDataTable() { }
	/* TdxCustomHunspellDataTable.Create */ inline __fastcall TdxPhoneTable(System::WideChar * ADataIdentifier)/* overload */ : TdxCustomHunspellDataTable(ADataIdentifier) { }
	
};


class DELPHICLASS TdxReplaceTable;
class PASCALIMPLEMENTATION TdxReplaceTable : public TdxCustomHunspellDataTable
{
	typedef TdxCustomHunspellDataTable inherited;
	
public:
	TdxReplaceTableItem operator[](int Index) { return Items[Index]; }
	
private:
	PdxReplaceArray __fastcall GetData(void);
	TdxReplaceTableItem __fastcall GetItem(int Index);
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall FreeDataItems(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual int __fastcall GetPieceQuantity(void);
	virtual void __fastcall InitializeItem(int Index);
	
public:
	__property PdxReplaceArray Data = {read=GetData};
	__property TdxReplaceTableItem Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TdxCustomHunspellDataTable.Create */ inline __fastcall TdxReplaceTable(void)/* overload */ : TdxCustomHunspellDataTable() { }
	/* TdxCustomHunspellDataTable.Create */ inline __fastcall TdxReplaceTable(System::WideChar * ADataIdentifier)/* overload */ : TdxCustomHunspellDataTable(ADataIdentifier) { }
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxReplaceTable(void) { }
	
};


class DELPHICLASS TdxConvertTable;
class PASCALIMPLEMENTATION TdxConvertTable : public TdxReplaceTable
{
	typedef TdxReplaceTable inherited;
	
private:
	int __fastcall FindNear(const System::WideChar * AWord);
	int __fastcall Match(const System::WideChar * AWord, int AIndex);
	void __fastcall Sort(int AIndex);
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	
public:
	bool __fastcall Convert(const System::WideChar * AWord, System::WideChar * ADest);
public:
	/* TdxCustomHunspellDataTable.Create */ inline __fastcall TdxConvertTable(void)/* overload */ : TdxReplaceTable() { }
	/* TdxCustomHunspellDataTable.Create */ inline __fastcall TdxConvertTable(System::WideChar * ADataIdentifier)/* overload */ : TdxReplaceTable(ADataIdentifier) { }
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxConvertTable(void) { }
	
};


class DELPHICLASS TdxAffixFlagAliasesTable;
class PASCALIMPLEMENTATION TdxAffixFlagAliasesTable : public TdxHunspellDataLinkedTable
{
	typedef TdxHunspellDataLinkedTable inherited;
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall FreeDataItems(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual int __fastcall GetPieceQuantity(void);
public:
	/* TdxHunspellDataLinkedTable.Create */ inline __fastcall TdxAffixFlagAliasesTable(TdxHunspellAffixManager* AAffixManager) : TdxHunspellDataLinkedTable(AAffixManager) { }
	
public:
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxAffixFlagAliasesTable(void) { }
	
};


class DELPHICLASS TdxMorphologicAliasesTable;
class PASCALIMPLEMENTATION TdxMorphologicAliasesTable : public TdxHunspellDataLinkedTable
{
	typedef TdxHunspellDataLinkedTable inherited;
	
protected:
	virtual bool __fastcall AddDataPiece(const System::WideChar * APiece, int ADataIndex, int APieceIndex);
	virtual void __fastcall FreeDataItems(void);
	virtual int __fastcall GetCount(void);
	virtual System::WideChar * __fastcall GetDataIdentifier(void);
	virtual int __fastcall GetDataItemSize(void);
	virtual int __fastcall GetPieceQuantity(void);
	virtual bool __fastcall ReadDataHeader(System::WideChar * ALine);
public:
	/* TdxHunspellDataLinkedTable.Create */ inline __fastcall TdxMorphologicAliasesTable(TdxHunspellAffixManager* AAffixManager) : TdxHunspellDataLinkedTable(AAffixManager) { }
	
public:
	/* TdxCustomHunspellDataTable.Destroy */ inline __fastcall virtual ~TdxMorphologicAliasesTable(void) { }
	
};


class PASCALIMPLEMENTATION TdxAffix : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	TdxHunspellAffixManager* FAffixManager;
	System::WideChar *FAppendString;
	System::WideChar *FStripString;
	System::Byte FAppendStringLength;
	System::Byte FStripStringLength;
	System::Int8 FConditionLength;
	TdxAffixOptions FOptions;
	System::Word FFlag;
	System::WideChar *FMorphologicalDescription;
	Dxhunspellwords::TdxHunspellFlags* FCompatibleFlags;
	System::WideChar *FCondition;
	TdxAffix* FNext;
	TdxAffix* FNextSimilar;
	TdxAffix* FNextDifferent;
	TdxAffix* FNextByFlag;
	bool __fastcall GetCircumfix(void);
	bool __fastcall GetCompoundEnd(void);
	bool __fastcall GetCompoundForbid(void);
	bool __fastcall GetCompoundMiddle(void);
	bool __fastcall GetCompoundPermit(void);
	bool __fastcall GetInCompoundOnly(void);
	bool __fastcall GetNeedAffix(void);
	bool __fastcall GetPrefixSuffixUnion(void);
	virtual bool __fastcall CanUseInCompoundWordPart(TdxCompoundWordPart ACompoundWordPart) = 0 ;
	virtual System::WideChar * __fastcall GetAppendString(void);
	bool __fastcall IsCompatibleWithFlag(System::Word AFlag, bool CompatibleIfNull = false);
	bool __fastcall IsPrefixSuffixUnion(const TdxAffixOptions AOptions);
	bool __fastcall IsWithoutAffixWordLengthCorrect(int ALengthWithoutAffix);
	void __fastcall SearchConditionGroupEnd(System::WideChar * &AConditionCursor);
	
public:
	__fastcall TdxAffix(TdxHunspellAffixManager* AAffixManager, PdxAffixItem AAffixItem, System::Word AFlag, const TdxAffixOptions AOptions);
	__fastcall virtual ~TdxAffix(void);
	bool __fastcall CanUseInSimpleWordsOrIsFogemorpheme(TdxCompoundWordPart ACompoundWordPart);
	bool __fastcall CanUseInTheMiddleOfCompoundWords(TdxCompoundWordPart ACompoundWordPart);
	__property bool Circumfix = {read=GetCircumfix, nodefault};
	__property bool CompoundEnd = {read=GetCompoundEnd, nodefault};
	__property bool CompoundForbid = {read=GetCompoundForbid, nodefault};
	__property bool CompoundMiddle = {read=GetCompoundMiddle, nodefault};
	__property bool CompoundPermit = {read=GetCompoundPermit, nodefault};
	__property bool InCompoundOnly = {read=GetInCompoundOnly, nodefault};
	__property bool NeedAffix = {read=GetNeedAffix, nodefault};
	__property bool PrefixSuffixUnion = {read=GetPrefixSuffixUnion, nodefault};
	__property TdxHunspellAffixManager* AffixManager = {read=FAffixManager};
	__property System::WideChar * AppendString = {read=GetAppendString};
	__property System::Byte AppendStringLength = {read=FAppendStringLength, write=FAppendStringLength, nodefault};
	__property Dxhunspellwords::TdxHunspellFlags* CompatibleFlags = {read=FCompatibleFlags, write=FCompatibleFlags};
	__property System::Word Flag = {read=FFlag, nodefault};
	__property System::WideChar * MorphologicalDescription = {read=FMorphologicalDescription};
	__property TdxAffixOptions Options = {read=FOptions, write=FOptions, nodefault};
	__property TdxAffix* Next = {read=FNext, write=FNext};
	__property TdxAffix* NextSimilar = {read=FNextSimilar, write=FNextSimilar};
	__property TdxAffix* NextDifferent = {read=FNextDifferent, write=FNextDifferent};
	__property TdxAffix* NextByFlag = {read=FNextByFlag, write=FNextByFlag};
};


class DELPHICLASS TdxPrefix;
class DELPHICLASS TdxSuffix;
class PASCALIMPLEMENTATION TdxPrefix : public TdxAffix
{
	typedef TdxAffix inherited;
	
protected:
	virtual bool __fastcall CanUseInCompoundWordPart(TdxCompoundWordPart ACompoundWordPart);
	
public:
	Dxhunspellwords::TdxHunspellWordStem* __fastcall CheckWord(const System::WideChar * AWord, int AWordLength, TdxSuffix* &ATakenSuffix, TdxCompoundWordPart ACompoundWordPart, const System::Word ACompoundFlag = (System::Word)(0x0));
	System::WideChar * __fastcall GetWordWithAffix(const System::WideChar * AWord, int AWordLength);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall MakeInitialWordFormAndProcessTwoSuffixCheck(const System::WideChar * AWord, int AWordLength, TdxSuffix* &ATakenSuffix, TdxCompoundWordPart ACompoundWordPart, const System::Word ACompoundFlag = (System::Word)(0x0));
	bool __fastcall IsWordSuitableForCondition(System::WideChar * AWord);
public:
	/* TdxAffix.Create */ inline __fastcall TdxPrefix(TdxHunspellAffixManager* AAffixManager, PdxAffixItem AAffixItem, System::Word AFlag, const TdxAffixOptions AOptions) : TdxAffix(AAffixManager, AAffixItem, AFlag, AOptions) { }
	/* TdxAffix.Destroy */ inline __fastcall virtual ~TdxPrefix(void) { }
	
};


class PASCALIMPLEMENTATION TdxSuffix : public TdxAffix
{
	typedef TdxAffix inherited;
	
private:
	System::WideChar *FReverseAppendString;
	
protected:
	virtual bool __fastcall CanUseInCompoundWordPart(TdxCompoundWordPart ACompoundWordPart);
	virtual System::WideChar * __fastcall GetAppendString(void);
	__property System::WideChar * ReverseAppendString = {read=FAppendString};
	
public:
	__fastcall TdxSuffix(TdxHunspellAffixManager* AAffixManager, PdxAffixItem AAffixItem, System::Word AFlag, const TdxAffixOptions AOptions);
	__fastcall virtual ~TdxSuffix(void);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall CheckWord(const System::WideChar * AWord, int AWordLength, const TdxAffixOptions AOptions, TdxPrefix* APrefix, const System::Word ACompatibleFlag = (System::Word)(0x0), const System::Word ACompoundFlag = (System::Word)(0x0), const System::Word AIncompatibleFlag = (System::Word)(0x0));
	Dxhunspellwords::TdxHunspellWordStem* __fastcall MakeInitialWordFormAndProcessSuffixCheck(const System::WideChar * AWord, int AWordLength, const TdxAffixOptions AOptions, TdxPrefix* APrefix, TdxSuffix* &ATakenSuffix, const System::Word ACompoundFlag = (System::Word)(0x0));
	System::WideChar * __fastcall GetWordWithAffix(const System::WideChar * AWord, int AWordLength);
	bool __fastcall IsWordSuitableForCondition(System::WideChar * AWordEnd, System::WideChar * AWordBegin);
};


struct DECLSPEC_DRECORD TdxSuffixInfo
{
public:
	System::Word Flag;
	System::WideChar *AppendString;
};


struct DECLSPEC_DRECORD TdxBackTrackingItem
{
public:
	short MetacharacterPosition;
	short WordsIndex;
	int MatchedWordCount;
};


typedef System::StaticArray<TdxBackTrackingItem, 100> TdxBackTrackingTable;

class DELPHICLASS TdxAffixReaderList;
class PASCALIMPLEMENTATION TdxHunspellAffixManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxBreakTable* FBreakTable;
	bool FCheckCompoundCase;
	bool FCheckCompoundDup;
	TdxCheckCompoundPatternTable* FCheckCompoundPatternTable;
	bool FCheckCompoundRep;
	bool FCheckCompoundTriple;
	bool FCheckSharps;
	System::Word FCircumfix;
	TAffixManagerFlagArray FCompatibleFlags;
	bool FCompatibleFlagsExist;
	System::Word FCompoundBegin;
	System::Word FCompoundEnd;
	System::Word FCompoundFlag;
	System::Word FCompoundForbid;
	System::Word FCompoundMiddle;
	int FCompoundPartMin;
	System::Word FCompoundPermit;
	System::Word FCompoundRoot;
	TdxCompoundRuleTable* FCompoundRuleTable;
	System::WideChar *FCompoundVowels;
	int FCompoundWordMax;
	TdxExistentAffixFlags FExistentAffixFlags;
	bool FFullStrip;
	TdxConvertTable* FInputConvertTable;
	bool FIsHungarian;
	System::Word FKeepCase;
	System::WideChar *FKeyboardString;
	System::Word FLemmaPresent;
	TdxMapTable* FMapTable;
	int FMaxCompoundSyllable;
	int FMaxNgramSuggestionCount;
	System::Word FNeedAffix;
	bool FNoSplitSugs;
	System::Word FNoSuggest;
	System::Word FInCompoundOnly;
	TdxConvertTable* FOutputConvertTable;
	TdxPhoneTable* FPhoneTable;
	TAffixTable FPrefixTableArrangedByAppendString;
	TAffixTable FPrefixTableIndexedByFlag;
	TdxReplaceTable* FReplaceTable;
	TdxSuffixInfo FSavedSuffixInfo;
	bool FSimplifiedTriple;
	System::Word FSubstandard;
	TAffixTable FSuffixTableArrangedByAppendString;
	TAffixTable FSuffixTableIndexedByFlag;
	bool FSugsWithDots;
	System::WideChar *FSyllableNum;
	System::WideChar *FTryChars;
	System::WideChar *FVersion;
	Dxhunspellwords::TdxHunspellWordStemManager* FWordStemManager;
	System::WideChar *FWordChars;
	bool __fastcall ParseAffix(System::WideChar * ALine, Dxhunspellwords::TdxHunspellReader* AAffixFileReader, TdxAffixType AAffixType);
	bool __fastcall ParseCompoundSyllable(System::WideChar * ALine, Dxhunspellwords::TdxHunspellReader* AAffixFileReader);
	bool __fastcall ParseRep(System::WideChar * ALine, Dxhunspellwords::TdxHunspellReader* AAffixFileReader);
	bool __fastcall AreAffixesBothCircumfixesOrNot(TdxAffix* APrefix, TdxAffix* ASuffix);
	bool __fastcall CanBeFirstPartInCompoundWord(Dxhunspellwords::TdxHunspellWordStem* AWordStem, unsigned AWordPartIndex);
	void __fastcall CheckHungarianSyllableCount(System::WideChar * AWord, Dxhunspellwords::TdxHunspellWordStem* AWordStem, short &ASyllableCount);
	void __fastcall CheckWordsCompatibilityWithCompoundRule(const Dxhunspellwords::PdxWordStemTable AWords, TdxBackTrackingItem *ABackTrackingTable, short AWordCount, int ACompoundRuleTableIndex, short &AFlagIndex, short &AWordIndex, short &ABackTrackingIndex, bool &AIsWordStemCompatibleWithCompoundRule, bool &AIsAllWordsCompatibleWithCompoundRule);
	bool __fastcall CompoundPartAffixCheck(System::WideChar const *AInitialWordForm, const int AInitialWordJoint, Dxhunspellwords::TdxHunspellWordStem* &AWordStem, const short AWordPartIndex, const TdxCompoundWordPart ACompoundWordPart, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix);
	void __fastcall CorrectBackTrackingIndex(TdxBackTrackingItem *ABackTrackingTable, short &AFlagIndex, short &AWordIndex, short &ABackTrackingIndex);
	void __fastcall CompoundRootCheck(Dxhunspellwords::TdxHunspellWordStem* AWordStem, short &AWordPartIndex);
	bool __fastcall EndOfCompoundRulePattern(int ACompoundRuleTableIndex, int AFlagIndex);
	bool __fastcall FindSuitableCheckCompoundPatternTableIndex(int &ATableIndex, System::WideChar * AWordSecondPart);
	bool __fastcall GetIsAllWordsCompatibleWithCompoundRule(const Dxhunspellwords::PdxWordStemTable AWords, short &AWordIndex, int AWordIndexMax, System::Word AFlag);
	bool __fastcall IsWordStemCompatibleWithCompoundRule(Dxhunspellwords::TdxHunspellWordStem* AWordStem);
	void __fastcall GetWordStemSuitableForAffixAndCompoundRules(Dxhunspellwords::TdxHunspellWordStem* &AWordStem, short AWordPartIndex, int ATableIndex, Dxhunspellwords::PdxWordStemTable &AWords, short AWordIndex, Dxhunspellwords::PdxWordStemTable ACompoundRuleWords, bool AIsFirstWordPart);
	void __fastcall GenerateCompoundFirstPartWithAffixes(Dxhunspellwords::TdxHunspellWordStem* &AWordStem, System::WideChar const *AInitialWordForm, int AInitialWordJoint, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix, TdxCompoundWordPart ACompoundWordPart);
	bool __fastcall IsAffixesForbidden(TdxPrefix* ATakenPrefix, TdxSuffix* ATakenSuffix);
	bool __fastcall IsAffixesIncompatibleWithCompoundParts(TdxPrefix* ATakenPrefix, TdxSuffix* ATakenSuffix, bool AIsAffixChecked, short AWordPartIndex);
	bool __fastcall IsWordPartSuitsCheckCompoundPatternTable(Dxhunspellwords::TdxHunspellWordStem* AWordStem, int ATableIndex, bool AIsFirstWordPart);
	bool __fastcall IsWordPartSuitsCompoundFlags(Dxhunspellwords::TdxHunspellWordStem* AWordStem, short AWordPartIndex, bool AIsFirstWordPart, Dxhunspellwords::PdxWordStemTable AWords);
	bool __fastcall IsSyllablesAndCompoundPartsWithinLimits(short AWordPartIndex, short ASyllableCount);
	bool __fastcall IsTripleLettersExistAndForbid(System::WideChar * AWord, unsigned AJoint);
	void __fastcall MakeWordWithCheckCompoundPatternTable(const System::WideChar * AWord, System::WideChar * AInitialWordForm, int ACompoundWordJoint, int &AInitialWordJoint, int &AWordLength, int ATableIndex);
	bool __fastcall CheckHungarianFlagsCompatibility(Dxhunspellwords::TdxHunspellWordStem* AWordStem, bool AIsHungarianMoveRule);
	bool __fastcall CheckHungarianFlagsCompatibilityWithSuffix(Dxhunspellwords::TdxHunspellWordStem* &AWordStem, System::WideChar const *AInitialWordForm, int ACompoundWordJoint, bool AIsHungarianMoveRule, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix);
	void __fastcall BuildAffixTree(TdxAffix* AAffix, TdxAffix* *AAffixTableArrangedByAppendString, TdxAffix* *AAffixTableIndexedByFlag);
	bool __fastcall ProcessSuffixOrPrefixCheck(const System::WideChar * AWord, int AWordLength, System::Word ACompoundFlag, TdxCompoundWordPart ACompoundWordPart, Dxhunspellwords::TdxHunspellWordStem* &AWordStem, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix);
	void __fastcall LinkAffixesIntoSubsets(TdxAffix* const *AAffixTableArrangedByAppendString);
	TdxAffix* __fastcall OrderAffixTree(TdxAffix* AAffix, TdxAffix* ANextAffix);
	void __fastcall AffixTreeToList(TdxAffix* *ATable);
	Dxhunspellwords::TdxAffixFlagMode __fastcall GetAffixFlagMode(void);
	unsigned __fastcall GetCodePage(void);
	bool __fastcall GetComplexPrefixes(void);
	System::Word __fastcall GetForbiddenWordFlag(void);
	System::WideChar * __fastcall GetIgnoredChars(void);
	bool __fastcall GetIsCompoundWordsAvailable(void);
	int __fastcall GetLanguage(void);
	void __fastcall ProcessPrefixes(const System::WideChar * ARoot, int ARootLength, Dxhunspellwords::TdxHunspellFlags* const AFlags, PdxGuessWordArray AWords, int AWordCount, int &AIndex, System::WideChar * ABad, int ABadLength);
	void __fastcall ProcessSuffixes(const System::WideChar * ARoot, int ARootLength, Dxhunspellwords::TdxHunspellFlags* const AFlags, int &AIndex, PdxGuessWordArray AWords, int AWordCount, System::WideChar * ABad, int ABadLength, System::WideChar * APhonetic);
	void __fastcall SetComplexPrefixes(bool Value);
	void __fastcall SetIgnoredChars(System::WideChar * Value);
	void __fastcall SetLanguage(int Value);
	
protected:
	System::Word __fastcall DecodeFlag(const System::WideChar * AFlag);
	System::WideChar * __fastcall EncodeFlag(System::Word AFlag);
	virtual TdxAffixReaderList* __fastcall GetReaders(void);
	virtual TdxAffixReaderList* __fastcall GetInitialReaders(void);
	void __fastcall InitCodePage(System::Classes::TStream* AStream);
	bool __fastcall IsAffixKeyUnique(System::Word AFlag, bool IsPrefix);
	virtual int __fastcall ParseGrammar(System::Classes::TStream* AStream);
	void __fastcall SetAffixKeyExist(System::Word AFlag, bool IsPrefix);
	void __fastcall UpdateAffixesOptions(TdxAffix* *ATable);
	void __fastcall UpdateAffixOptions(TdxAffix* AAffix);
	__property bool FullStrip = {read=FFullStrip, nodefault};
	__property Dxhunspellwords::TdxHunspellWordStemManager* WordStemManager = {read=FWordStemManager};
	
public:
	__fastcall TdxHunspellAffixManager(Dxhunspellwords::TdxHunspellWordStemManager* AWordStemManager);
	__fastcall virtual ~TdxHunspellAffixManager(void);
	void __fastcall UpdateWordStemOptions(void);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall AffixCheck(const System::WideChar * AWord, int AWordLength, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix, const System::Word ACompoundFlag = (System::Word)(0x0), TdxCompoundWordPart ACompoundWordPart = (TdxCompoundWordPart)(0x0));
	Dxhunspellwords::TdxHunspellWordStem* __fastcall ProcessPrefixCheck(const System::WideChar * AWord, int AWordLength, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix, TdxCompoundWordPart ACompoundWordPart, const System::Word ACompoundFlag = (System::Word)(0x0));
	bool __fastcall IsForbiddenOrNoSuggestWord(Dxhunspellwords::TdxHunspellWordStem* AWordStem, bool ASuggest);
	bool __fastcall IsLeadingSubset(System::WideChar * ASubset, System::WideChar * ASet);
	bool __fastcall IsTrailingReversedSubset(System::WideChar * AReversedSubset, System::WideChar * AEndOfSet, int ASetLength);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall ProcessPrefixWithSuffixesCheck(const System::WideChar * AWord, int AWordLength, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix, TdxCompoundWordPart ACompoundWordPart, const System::Word ACompoundFlag = (System::Word)(0x0));
	Dxhunspellwords::TdxHunspellWordStem* __fastcall ProcessSuffixCheck(const System::WideChar * AWord, int AWordLength, const TdxAffixOptions AOptions, TdxPrefix* APrefix, TdxSuffix* &ATakenSuffix, const System::Word ACompatibleFlag = (System::Word)(0x0), const System::Word ACompoundFlag = (System::Word)(0x0), TdxCompoundWordPart ACompoundWordPart = (TdxCompoundWordPart)(0x0));
	Dxhunspellwords::TdxHunspellWordStem* __fastcall ProcessTwoSuffixCheck(const System::WideChar * AWord, int AWordLength, const TdxAffixOptions AOptions, TdxPrefix* APrefix, TdxSuffix* &ATakenSuffix, const System::Word ACompoundFlag = (System::Word)(0x0));
	short __fastcall GetSyllableCount(const System::WideChar * AWord, int AWordLength);
	bool __fastcall IsSimpleWordWithReplacedCharacters(const System::WideChar * AWord, int AWordLength, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix);
	bool __fastcall IsForbiddenByCheckCompoundPattern(const System::WideChar * AWord, int AJoint, Dxhunspellwords::TdxHunspellWordStem* AFirstPartWordStem, Dxhunspellwords::TdxHunspellWordStem* ASecondPartWordStem);
	bool __fastcall IsWordPartsSuitCompoundRule(Dxhunspellwords::PdxWordStemTable &AWords, short AWordCount, Dxhunspellwords::TdxHunspellWordStem* AWordStem, Dxhunspellwords::PdxWordStemTable ADefaultWords, bool AIsFirstWordPart);
	bool __fastcall IsJointUpperCaseExistAndForbid(const System::WideChar * AWord, int AJoint);
	bool __fastcall CompoundWordWithReplacedCharactersExists(const System::WideChar * AWord, int AWordLength, TdxPrefix* &ATakenPrefix, TdxSuffix* &ATakenSuffix);
	void __fastcall GetCompoundWordJointRange(int &ACompoundWordJointMin, int &ACompoundWordJointMax, const System::WideChar * AWord, int AWordLength);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall CompoundCheck(const System::WideChar * AWord, short AWordPartIndex, short ASyllableCount, short AWordPartMaxCount, short AWordIndex, Dxhunspellwords::PdxWordStemTable AWords = (Dxhunspellwords::PdxWordStemTable)(0x0), bool AIsHungarianMoveRule = false, bool ASuggest = false);
	void __fastcall Load(System::Classes::TStream* AStream);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall Lookup(const System::WideChar * AWord);
	void __fastcall SetCompatibleFlags(int AIndex, bool AValue);
	int __fastcall ExpandWordStem(PdxGuessWordArray AWords, int AWordCount, const System::WideChar * ARoot, int ARootLength, Dxhunspellwords::TdxHunspellFlags* const AFlags, System::WideChar * ABad, int ABadLength, System::WideChar * APhonetic);
	__property Dxhunspellwords::TdxAffixFlagMode AffixFlagMode = {read=GetAffixFlagMode, nodefault};
	__property TdxBreakTable* BreakTable = {read=FBreakTable};
	__property bool CheckSharps = {read=FCheckSharps, nodefault};
	__property unsigned CodePage = {read=GetCodePage, nodefault};
	__property bool CompatibleFlagsExist = {read=FCompatibleFlagsExist, write=FCompatibleFlagsExist, nodefault};
	__property bool ComplexPrefixes = {read=GetComplexPrefixes, write=SetComplexPrefixes, nodefault};
	__property System::Word CompoundFlag = {read=FCompoundFlag, nodefault};
	__property System::Word ForbiddenWordFlag = {read=GetForbiddenWordFlag, nodefault};
	__property System::WideChar * IgnoredChars = {read=GetIgnoredChars, write=SetIgnoredChars};
	__property TdxConvertTable* InputConvertTable = {read=FInputConvertTable};
	__property bool IsCompoundWordsAvailable = {read=GetIsCompoundWordsAvailable, nodefault};
	__property bool IsHungarian = {read=FIsHungarian, nodefault};
	__property System::Word KeepCase = {read=FKeepCase, nodefault};
	__property System::WideChar * KeyboardString = {read=FKeyboardString};
	__property int Language = {read=GetLanguage, write=SetLanguage, nodefault};
	__property TdxMapTable* MapTable = {read=FMapTable};
	__property int MaxNgramSuggestionCount = {read=FMaxNgramSuggestionCount, nodefault};
	__property System::Word NeedAffix = {read=FNeedAffix, nodefault};
	__property TdxConvertTable* OutputConvertTable = {read=FOutputConvertTable};
	__property System::Word InCompoundOnly = {read=FInCompoundOnly, nodefault};
	__property TdxPhoneTable* PhoneTable = {read=FPhoneTable};
	__property TdxReplaceTable* ReplaceTable = {read=FReplaceTable};
	__property bool SugsWithDots = {read=FSugsWithDots, nodefault};
	__property System::WideChar * TryChars = {read=FTryChars};
	__property System::WideChar * WordChars = {read=FWordChars};
};


class DELPHICLASS TdxAffixFileAttributeReader;
class PASCALIMPLEMENTATION TdxAffixFileAttributeReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxHunspellAffixManager* FAffixManager;
	Dxhunspellwords::TdxHunspellWordStemManager* __fastcall GetWordStemManager(void);
	
protected:
	virtual System::WideChar * __fastcall GetDataIdentifier(void) = 0 ;
	virtual bool __fastcall Process(System::WideChar * ALine, Dxhunspellwords::TdxHunspellReader* AReader) = 0 ;
	bool __fastcall ParseFlag(System::WideChar * ALine, System::Word &ADecodedFlag, Dxhunspellwords::TdxHunspellReader* AReader);
	bool __fastcall ParseNumber(System::WideChar * ALine, /* out */ int &ANumber);
	virtual bool __fastcall Repeating(void);
	__property TdxHunspellAffixManager* AffixManager = {read=FAffixManager};
	__property Dxhunspellwords::TdxHunspellWordStemManager* WordStemManager = {read=GetWordStemManager};
	
public:
	__fastcall TdxAffixFileAttributeReader(TdxHunspellAffixManager* AAffixManager);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAffixFileAttributeReader(void) { }
	
};


typedef System::TMetaClass* TdxAffixFileAttributeReaderClass;

class PASCALIMPLEMENTATION TdxAffixReaderList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxAffixFileAttributeReader* operator[](int Index) { return Items[Index]; }
	
private:
	TdxHunspellAffixManager* FAffixManager;
	HIDESBASE TdxAffixFileAttributeReader* __fastcall GetItem(int Index);
	
public:
	__fastcall TdxAffixReaderList(TdxHunspellAffixManager* AAffixManager);
	HIDESBASE void __fastcall Add(TdxAffixFileAttributeReaderClass AReaderClass);
	void __fastcall ProcessLine(System::WideChar * ALine, Dxhunspellwords::TdxHunspellReader* AReader);
	__property TdxAffixFileAttributeReader* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAffixReaderList(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const int dxAffixTableSize = int(0x10000);
static const int dxMaxFlagCount = int(0x10000);
static const int dxPhoneHashSize = int(0x10000);
static const System::Word dxMaxPhonetLength = System::Word(0x100);
}	/* namespace Dxhunspellaffixes */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXHUNSPELLAFFIXES)
using namespace Dxhunspellaffixes;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxhunspellaffixesHPP
