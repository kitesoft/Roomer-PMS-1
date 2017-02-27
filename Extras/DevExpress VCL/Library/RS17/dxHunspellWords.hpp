// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxHunspellWords.pas' rev: 24.00 (Win32)

#ifndef DxhunspellwordsHPP
#define DxhunspellwordsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxHunspellTypes.hpp>	// Pascal unit
#include <dxSpellCheckerUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxhunspellwords
{
//-- type declarations -------------------------------------------------------
enum TdxAffixFlagMode : unsigned char { afmCharacter, afmTwoCharacters, afmNumber, afmUnicode };

enum TdxWordStemOption : unsigned char { wsoMorphologyDescription, wsoMorphologyAliases, wsoMorphologyPhone, wsoReverse, wsoUpcaseOnly, wsoForbidden, wsoNoSuggest, wsoCompound, wsoCompoundBegin, wsoCompoundMiddle, wsoCompoundEnd, wsoCompoundRoot, wsoInCompoundOnly, wsoNeedAffix, wsoKeepCase };

typedef System::Set<TdxWordStemOption, TdxWordStemOption::wsoMorphologyDescription, TdxWordStemOption::wsoKeepCase>  TdxWordStemOptions;

class DELPHICLASS TdxHunspellWordStem;
typedef System::StaticArray<TdxHunspellWordStem*, 1> TdxWordStemTable;

typedef TdxWordStemTable *PdxWordStemTable;

class DELPHICLASS TdxHunspellFlags;
class DELPHICLASS TdxHunspellWordStemManager;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellFlags : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Word operator[](int Index) { return Items[Index]; }
	
private:
	TdxAffixFlagMode FAffixFlagMode;
	Dxhunspelltypes::TdxAffixFlagsData *FData;
	System::Word FDataSize;
	System::Word FLength;
	void __fastcall DisposeData(void);
	System::Word __fastcall GetItem(int Index);
	void __fastcall SetLength(System::Word ANewLength);
	
public:
	__fastcall TdxHunspellFlags(TdxAffixFlagMode AAffixFlagMode);
	__fastcall TdxHunspellFlags(TdxHunspellFlags* AFlags, TdxAffixFlagMode AAffixFlagMode);
	__fastcall virtual ~TdxHunspellFlags(void);
	void __fastcall Assign(TdxHunspellFlags* ASource);
	void __fastcall AssignCapitalized(TdxHunspellFlags* ASource);
	bool __fastcall ContainsFlag(System::Word AFlag);
	bool __fastcall Decode(TdxHunspellWordStemManager* AWordStemManager, System::WideChar * AFlags);
	bool __fastcall InitializeByAlias(TdxHunspellWordStemManager* AWordStemManager, System::WideChar * AAlias);
	void __fastcall Sort(void);
	__property Dxhunspelltypes::PdxAffixFlagsData Data = {read=FData, write=FData};
	__property System::Word Items[int Index] = {read=GetItem/*, default*/};
	__property System::Word Length = {read=FLength, write=SetLength, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxHunspellFlagsList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellFlagsList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxHunspellFlags* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxHunspellFlags* __fastcall GetItem(int Index);
	
public:
	__property TdxHunspellFlags* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxHunspellFlagsList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxHunspellFlagsList(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellWordStem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxHunspellFlags* FAffixFlags;
	TdxHunspellWordStem* FNext;
	TdxHunspellWordStem* FNextHomonym;
	System::WideChar *FMorphologicalDescription;
	TdxWordStemOptions FOptions;
	System::WideChar *FWordStem;
	System::Byte FWordStemLength;
	bool __fastcall GetCompound(void);
	bool __fastcall GetCompoundBegin(void);
	bool __fastcall GetCompoundEnd(void);
	bool __fastcall GetCompoundMiddle(void);
	bool __fastcall GetCompoundRoot(void);
	bool __fastcall GetForbidden(void);
	bool __fastcall GetInCompoundOnly(void);
	bool __fastcall GetKeepCase(void);
	bool __fastcall GetMorphologyAliases(void);
	bool __fastcall GetMorphologyPhone(void);
	bool __fastcall GetNeedAffix(void);
	bool __fastcall GetNoSuggest(void);
	bool __fastcall GetUpcaseOnly(void);
	void __fastcall SetAffixFlags(TdxHunspellFlags* const Value);
	void __fastcall UpdateOptionsByMorphology(void);
	
public:
	__fastcall TdxHunspellWordStem(const System::WideChar * AWord, int AWordLength, const System::WideChar * AIgnoreChars, bool AReverse);
	__fastcall virtual ~TdxHunspellWordStem(void);
	bool __fastcall IsCompatibleWithFlag(System::Word AFlag, bool CompatibleIfNull = false);
	void __fastcall ProcessFlags(TdxHunspellWordStemManager* AWordStemManager);
	void __fastcall SetMorphology(const System::WideChar * AMorphologocalDescription);
	void __fastcall SetMorphologyByAlias(const System::WideChar * AMorphologocalDescription);
	void __fastcall UpdateOptions(const TdxWordStemOptions AOptions);
	__property TdxHunspellFlags* AffixFlags = {read=FAffixFlags, write=SetAffixFlags};
	__property bool Compound = {read=GetCompound, nodefault};
	__property bool CompoundBegin = {read=GetCompoundBegin, nodefault};
	__property bool CompoundEnd = {read=GetCompoundEnd, nodefault};
	__property bool CompoundMiddle = {read=GetCompoundMiddle, nodefault};
	__property bool CompoundRoot = {read=GetCompoundRoot, nodefault};
	__property bool Forbidden = {read=GetForbidden, nodefault};
	__property bool InCompoundOnly = {read=GetInCompoundOnly, nodefault};
	__property bool KeepCase = {read=GetKeepCase, nodefault};
	__property bool MorphologyAliases = {read=GetMorphologyAliases, nodefault};
	__property bool MorphologyPhone = {read=GetMorphologyPhone, nodefault};
	__property bool NeedAffix = {read=GetNeedAffix, nodefault};
	__property bool NoSuggest = {read=GetNoSuggest, nodefault};
	__property bool UpcaseOnly = {read=GetUpcaseOnly, nodefault};
	__property System::WideChar * MorphologicalDescription = {read=FMorphologicalDescription};
	__property TdxHunspellWordStem* Next = {read=FNext, write=FNext};
	__property TdxHunspellWordStem* NextHomonym = {read=FNextHomonym, write=FNextHomonym};
	__property TdxWordStemOptions Options = {read=FOptions, nodefault};
	__property System::WideChar * WordStem = {read=FWordStem};
	__property System::Byte WordStemLength = {read=FWordStemLength, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxHunspellReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellReader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxspellcheckerutils::TdxSpellCheckerStrings* FData;
	int FLineIndex;
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	
public:
	__fastcall TdxHunspellReader(System::Classes::TStream* AStream, int ACodePage);
	__fastcall virtual ~TdxHunspellReader(void);
	bool __fastcall GetNextLine(void *ABuffer, int ABufferSize);
	void __fastcall Reset(void);
	__property int LineIndex = {read=FLineIndex, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellWordStemManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxHunspellFlagsList* FAffixFlagAliases;
	TdxAffixFlagMode FAffixFlagMode;
	Dxhunspelltypes::TdxPWideCharArray *FAffixMorphologicAliases;
	int FAffixMorphologicAliasesCount;
	unsigned FCodePage;
	bool FComplexPrefixes;
	System::Word FForbiddenWordFlag;
	TdxWordStemTable *FHashTable;
	int FHashTableSize;
	System::WideChar *FIgnoredChars;
	int FLanguage;
	bool __fastcall AllocateHashTable(System::WideChar * S);
	void __fastcall FreeHashTable(void);
	unsigned __fastcall Hash(System::WideChar * S);
	void __fastcall AddWord(const System::WideChar * AWord, int AWordLength, TdxHunspellFlags* AAffixFlags, const System::WideChar * AMorphologocalDescription, bool AOnlyUpperCase);
	void __fastcall CheckAddCapitalizedWord(System::WideChar * AWord, int AWordLength, TdxHunspellFlags* AAffixFlags, System::WideChar * ADescription);
	TdxHunspellWordStem* __fastcall CreateWordStem(const System::WideChar * AWord, int AWordLength, const System::WideChar * AMorphologyDescription);
	void __fastcall FreeAffixMorphologicAliases(void);
	System::WideChar * __fastcall GetAffixesDescription(System::WideChar * ALine);
	System::WideChar * __fastcall GetMorphologyDescription(System::WideChar * ALine);
	bool __fastcall InitializeAffixFlags(TdxHunspellFlags* AAffixFlags, System::WideChar * ADescription);
	bool __fastcall LoadWordStems(System::Classes::TStream* AStream);
	void __fastcall ParseWordStem(System::WideChar * ALine);
	void __fastcall SetupMorphology(TdxHunspellWordStem* &AWordStem, const System::WideChar * AMorphologyDescription);
	
public:
	__fastcall TdxHunspellWordStemManager(int ALanguage);
	__fastcall virtual ~TdxHunspellWordStemManager(void);
	void __fastcall AllocateAffixMorphologicAliases(int ASize);
	System::WideChar * __fastcall GetAffixMorphologyByAlias(int AAlias);
	TdxHunspellWordStem* __fastcall GetFirstItem(/* out */ int &ATableIndex);
	TdxHunspellWordStem* __fastcall GetNextItem(int &ATableIndex, TdxHunspellWordStem* AWordStem);
	bool __fastcall HasAffixFlagAliases(void);
	bool __fastcall HasAffixMorphologicAliases(void);
	bool __fastcall Load(System::Classes::TStream* ADictionaryStream);
	TdxHunspellWordStem* __fastcall Lookup(const System::WideChar * AWord);
	__property TdxHunspellFlagsList* AffixFlagAliases = {read=FAffixFlagAliases};
	__property TdxAffixFlagMode AffixFlagMode = {read=FAffixFlagMode, write=FAffixFlagMode, nodefault};
	__property Dxhunspelltypes::PdxPWideCharArray AffixMorphologicAliases = {read=FAffixMorphologicAliases};
	__property int AffixMorphologicAliasesCount = {read=FAffixMorphologicAliasesCount, nodefault};
	__property unsigned CodePage = {read=FCodePage, write=FCodePage, nodefault};
	__property bool ComplexPrefixes = {read=FComplexPrefixes, write=FComplexPrefixes, nodefault};
	__property System::Word ForbiddenWordFlag = {read=FForbiddenWordFlag, write=FForbiddenWordFlag, nodefault};
	__property System::WideChar * IgnoredChars = {read=FIgnoredChars, write=FIgnoredChars};
	__property int Language = {read=FLanguage, write=FLanguage, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxHunspellMaxDictionaryCount = System::Int8(0x14);
}	/* namespace Dxhunspellwords */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXHUNSPELLWORDS)
using namespace Dxhunspellwords;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxhunspellwordsHPP
