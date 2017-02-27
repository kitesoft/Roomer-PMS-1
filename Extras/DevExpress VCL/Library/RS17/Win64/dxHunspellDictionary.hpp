// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxHunspellDictionary.pas' rev: 24.00 (Win64)

#ifndef DxhunspelldictionaryHPP
#define DxhunspelldictionaryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxSpellCheckerUtils.hpp>	// Pascal unit
#include <dxHunspellWords.hpp>	// Pascal unit
#include <dxHunspellAffixes.hpp>	// Pascal unit
#include <dxSpellChecker.hpp>	// Pascal unit
#include <dxHunspellTypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxhunspelldictionary
{
//-- type declarations -------------------------------------------------------
enum TdxSpellInfoItem : unsigned char { siiCompound, siiForbidden, siiInitialCapitalization };

typedef System::Set<TdxSpellInfoItem, TdxSpellInfoItem::siiCompound, TdxSpellInfoItem::siiInitialCapitalization>  TdxSpellInfo;

class DELPHICLASS TdxHunspellDictionary;
class PASCALIMPLEMENTATION TdxHunspellDictionary : public Dxspellchecker::TdxCustomSpellCheckerDictionary
{
	typedef Dxspellchecker::TdxCustomSpellCheckerDictionary inherited;
	
private:
	Dxhunspellaffixes::TdxHunspellAffixManager* FAffixManager;
	bool FComplexPrefixes;
	System::Sysutils::TFileName FDictionaryPath;
	System::WideString FGrammarAlphabet;
	System::Sysutils::TFileName FGrammarPath;
	int FNgramDistance;
	bool FSuggestionsLiteMode;
	Dxhunspellwords::TdxHunspellWordStemManager* FWordStemManager;
	Dxhunspellwords::TdxHunspellWordStem* __fastcall CheckCompoundWord(const System::WideChar * AWord, int AWordLength, TdxSpellInfo &AInfo);
	bool __fastcall CheckForbiddenAndCompoundOnly(Dxhunspellwords::TdxHunspellWordStem* &AWordStem, TdxSpellInfo &AInfo);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall CheckWord(const System::WideChar * AWord, TdxSpellInfo &AInfo);
	int __fastcall CleanWord(System::WideChar * ADest, System::WideChar * ASource, /* out */ Dxspellcheckerutils::TdxCapitalizationType &ACapitalizationType, /* out */ int &AAbbreviationCount);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall GetAbbreviationWordStem(const System::WideChar * AWord, int AWordLength, TdxSpellInfo &AInfo, Dxspellcheckerutils::TdxCapitalizationType ACapitalizationType = (Dxspellcheckerutils::TdxCapitalizationType)(0x0));
	int __fastcall InputConverting(System::WideChar * ACleanedWord, System::WideChar * AWordForCompound, const System::WideChar * ASource, /* out */ Dxspellcheckerutils::TdxCapitalizationType &ACapitalizationType, /* out */ bool &AIsAbbreviation);
	bool __fastcall IsNumber(System::WideChar * AWord, int AWordLength);
	bool __fastcall LoadDictionary(void);
	void __fastcall LoadGrammar(void);
	Dxhunspellwords::TdxHunspellWordStem* __fastcall SpellSharps(System::WideChar * ABase, System::WideChar * APosition, int AIndex, int ANumRepeat, TdxSpellInfo &AInfo);
	void __fastcall SetDictionaryPath(const System::Sysutils::TFileName AValue);
	void __fastcall SetGrammarPath(const System::Sysutils::TFileName AValue);
	
protected:
	virtual Dxspellchecker::TdxSpellCheckerSuggestionBuilder* __fastcall CreateSuggestionBuilder(void);
	virtual bool __fastcall DoLoad(void);
	virtual bool __fastcall DoUnload(void);
	virtual void __fastcall FreeContent(void);
	virtual System::WideString __fastcall GetActiveAlphabet(void);
	virtual System::Classes::TStream* __fastcall GetDictionaryStream(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual System::Classes::TStream* __fastcall GetGrammarStream(void);
	bool __fastcall ProcessApostrophe(System::WideChar * AWord, Dxhunspellwords::TdxHunspellWordStem* &AWordStem, TdxSpellInfo &AInfo);
	bool __fastcall ProcessSharps(System::WideChar * AWord, int AWordLength, bool AIsAbbreviation, Dxhunspellwords::TdxHunspellWordStem* &AWordStem, TdxSpellInfo &AInfo);
	bool __fastcall ProcessWordBreak(const System::WideChar * AWord, TdxSpellInfo &AInfo);
	bool __fastcall Spell(const System::WideChar * AWord, TdxSpellInfo &AInfo);
	virtual void __fastcall UpdateWordChars(System::WideString &AWordChars);
	__property Dxhunspellaffixes::TdxHunspellAffixManager* AffixManager = {read=FAffixManager};
	__property Dxhunspellwords::TdxHunspellWordStemManager* WordStemManager = {read=FWordStemManager};
	
public:
	__fastcall virtual TdxHunspellDictionary(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall HasWord(const System::WideString AWord);
	
__published:
	__property System::Sysutils::TFileName DictionaryPath = {read=FDictionaryPath, write=SetDictionaryPath};
	__property Enabled = {default=1};
	__property System::Sysutils::TFileName GrammarPath = {read=FGrammarPath, write=SetGrammarPath};
	__property int NgramDistance = {read=FNgramDistance, write=FNgramDistance, default=0};
	__property bool SuggestionsLiteMode = {read=FSuggestionsLiteMode, write=FSuggestionsLiteMode, default=1};
	__property Language = {default=0};
	__property OnLoaded;
	__property OnLoading;
public:
	/* TdxCustomSpellCheckerDictionary.Destroy */ inline __fastcall virtual ~TdxHunspellDictionary(void) { }
	
};


enum TdxNgramOption : unsigned char { ngoLowering, ngoLongerWorse, ngoAnyMismatch };

typedef System::Set<TdxNgramOption, TdxNgramOption::ngoLowering, TdxNgramOption::ngoAnyMismatch>  TdxNgramOptions;

typedef System::StaticArray<System::WideChar *, 200> TdxGuessArray;

typedef TdxGuessArray *PdxGuessArray;

typedef System::StaticArray<int, 200> TdxGuessScoreArray;

typedef System::StaticArray<Dxhunspellwords::TdxHunspellWordStem*, 100> TdxWordStemArray;

typedef System::StaticArray<int, 100> TdxWordStemScoreArray;

typedef System::StaticArray<System::WideChar *, 100> TdxPhoneticWordStemArray;

typedef System::StaticArray<int, 100> TdxPhoneticWordStemScoreArray;

class DELPHICLASS TdxHunspellSuggestionBuilder;
class PASCALIMPLEMENTATION TdxHunspellSuggestionBuilder : public Dxspellchecker::TdxNearMissStrategy
{
	typedef Dxspellchecker::TdxNearMissStrategy inherited;
	
private:
	int FAbbreviationCount;
	Dxspellcheckerutils::TdxCapitalizationType FCapitalizationType;
	bool FCheckCompound;
	int FMaxNgramSuggestionCount;
	void __fastcall AddNgramSuggestions(System::WideChar * AWord, int AWordLength, Dxhunspellwords::TdxHunspellWordStem* const *AWordStems);
	void __fastcall AddPhoneticSuggestions(System::WideChar * AWord, int AWordLength, System::WideChar * *APhoneticWordStems, int *APhoneticScores);
	void __fastcall CalculateScores(System::WideChar * AWord, int AWordLength, /* out */ Dxhunspellwords::TdxHunspellWordStem* *AWordStems, /* out */ int *AWordStemScores, /* out */ System::WideChar * *APhoneticWordStems, /* out */ int *APhoneticScores);
	void __fastcall CheckDashedWord(System::WideChar * AWord, int AWordLength);
	void __fastcall CheckHungarianCompounding(System::WideChar * ACursor, System::WideChar const *ACandidate, int ACheck1, int ACheck2);
	int __fastcall CheckWord(const System::WideChar * AWord, int ALength, bool ACheckCompound);
	int __fastcall CommonCharacterPositions(System::WideChar * S1, System::WideChar * S2, /* out */ bool &AHasSwap);
	void __fastcall GenerateNgramGuessTables(System::WideChar * AWord, int AWordLength, System::WideChar * *AGuess, System::WideChar * *AGuessOrig, int *AGuessScore, Dxhunspellwords::TdxHunspellWordStem* const *AWordStems);
	void __fastcall GenerateNearMissSuggestions(System::WideChar * AWord, bool &AExistCapitalizedWords, bool &AOnlyCompoundSuggestions);
	void __fastcall GenerateNgramSuggestions(System::WideChar * AWord, bool &AExistCapitalizedWords, bool &AOnlyCompoundSuggestions);
	Dxhunspellaffixes::TdxHunspellAffixManager* __fastcall GetAffixManager(void);
	TdxHunspellDictionary* __fastcall GetDictionary(void);
	Dxhunspellaffixes::TdxPhoneTable* __fastcall GetPhoneTable(void);
	Dxhunspellwords::TdxHunspellWordStemManager* __fastcall GetWordStemManager(void);
	bool __fastcall HasSuggestionWithDash(void);
	void __fastcall HungarianReplaceDash(void);
	bool __fastcall IsForbidden(const System::WideChar * AWord);
	int __fastcall LeftCommonSubStringLength(System::WideChar * AWord1, System::WideChar * AWord2);
	System::WideChar * __fastcall MakeSecondWordCapitalized(System::WideChar * AWord);
	int __fastcall Ngram(System::WideChar * S1, System::WideChar * S2, int N, const TdxNgramOptions AOptions);
	void __fastcall NgramSuggestion(System::WideChar * AWord);
	void __fastcall ProcessMap(System::WideChar * AWord, System::WideChar * ACandidate, int AWordIndex, int ACandidateIndex, Dxhunspellaffixes::TdxMapTable* AMapTable);
	void __fastcall RemoveBadSuggestions(void);
	void __fastcall ReplaceTableSuggestion(void);
	void __fastcall Sort(PdxGuessArray S1, PdxGuessArray S2, Dxhunspelltypes::PIntegerArray AWeights, int ACount);
	int __fastcall Trigram(System::WideChar * S1, System::WideChar * S2, const TdxNgramOptions AOptions);
	
protected:
	void __fastcall CheckBadKey(void);
	void __fastcall CheckCapitalize(void);
	void __fastcall CheckCharMapping(void);
	void __fastcall CheckTwoWords(void);
	void __fastcall DoubleInterchangeTwoLetters(void);
	void __fastcall AddSuggestion(System::WideChar * AWord, int ADistance = 0x2);
	virtual bool __fastcall CanAddToSuggestions(const System::WideString ATestWord);
	virtual void __fastcall DoAddSuggestions(void);
	void __fastcall DoNearMissStrategy(System::WideChar * AWord, bool &AOnlyCompoundSuggestions);
	void __fastcall InsertSuggestion(System::WideChar * AWord, Dxspellchecker::TdxSpellCheckerSuggestionList* ASuggestions = (Dxspellchecker::TdxSpellCheckerSuggestionList*)(0x0));
	virtual bool __fastcall IsCaseSensitive(void);
	virtual System::WideString __fastcall PrepareWord(const System::WideString AWord);
	bool __fastcall Spell(System::WideChar * AWord);
	void __fastcall Suggest(System::WideChar * AWord);
	bool __fastcall SuggestionExist(System::WideChar * AWord);
	__property int MaxNgramSuggestionCount = {read=FMaxNgramSuggestionCount, nodefault};
	__property Dxhunspellaffixes::TdxPhoneTable* PhoneTable = {read=GetPhoneTable};
	
public:
	__fastcall virtual TdxHunspellSuggestionBuilder(Dxspellchecker::TdxCustomSpellCheckerDictionary* ADictionary);
	__property Dxhunspellaffixes::TdxHunspellAffixManager* AffixManager = {read=GetAffixManager};
	__property TdxHunspellDictionary* Dictionary = {read=GetDictionary};
	__property Dxhunspellwords::TdxHunspellWordStemManager* WordStemManager = {read=GetWordStemManager};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHunspellSuggestionBuilder(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Byte dxMaxGuessCount = System::Byte(0xc8);
static const System::Int8 dxMaxWordStemCount = System::Int8(0x64);
}	/* namespace Dxhunspelldictionary */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXHUNSPELLDICTIONARY)
using namespace Dxhunspelldictionary;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxhunspelldictionaryHPP
