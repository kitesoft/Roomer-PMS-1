// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxISpellDecompressor.pas' rev: 24.00 (Win32)

#ifndef DxispelldecompressorHPP
#define DxispelldecompressorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxSpellChecker.hpp>	// Pascal unit
#include <dxSpellCheckerUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxispelldecompressor
{
//-- type declarations -------------------------------------------------------
enum TdxAffixElementState : unsigned char { aesNone, aesPrefix, aesSuffix };

class DELPHICLASS TdxCharValidator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCharValidator : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FAnyChar;
	System::WideString FChars;
	bool FValid;
	
public:
	__fastcall TdxCharValidator(const System::WideString AChars, bool AValid);
	__fastcall TdxCharValidator(void);
	bool __fastcall IsValidChar(System::WideChar AChar);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCharValidator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRuleValidator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRuleValidator : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxCharValidator* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxCharValidator* __fastcall GetItem(int Index);
	
public:
	void __fastcall AddAnyCharValid(void);
	void __fastcall AddCharInfo(const System::WideString AChars, bool AValid);
	bool __fastcall IsValid(const System::WideString AWord, bool AFromStart);
	__property TdxCharValidator* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxRuleValidator(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxRuleValidator(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAffixRule;
class DELPHICLASS TdxCustomAffixElement;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAffixRule : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomAffixElement* FAffix;
	System::WideString FAppendString;
	bool FForceValid;
	System::WideString FStripString;
	TdxRuleValidator* FValidator;
	bool __fastcall GetIsPrefix(void);
	
protected:
	virtual bool __fastcall DoParse(const System::WideString ARule) = 0 ;
	virtual System::WideString __fastcall RemoveComments(const System::WideString ARule) = 0 ;
	__property TdxCustomAffixElement* Affix = {read=FAffix};
	__property System::WideString AppendString = {read=FAppendString, write=FAppendString};
	__property bool ForceValid = {read=FForceValid, write=FForceValid, nodefault};
	__property bool IsPrefix = {read=GetIsPrefix, nodefault};
	__property System::WideString StripString = {read=FStripString, write=FStripString};
	__property TdxRuleValidator* Validator = {read=FValidator};
	
public:
	__fastcall TdxAffixRule(TdxCustomAffixElement* AAffix);
	__fastcall virtual ~TdxAffixRule(void);
	bool __fastcall CanApply(const System::WideString AWord);
	System::WideString __fastcall GetWordform(const System::WideString AWord, const System::WideString ACheckStripWord);
	virtual bool __fastcall Parse(const System::WideString ARule);
};

#pragma pack(pop)

class DELPHICLASS TdxAffixRuleList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAffixRuleList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxAffixRule* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxAffixRule* __fastcall GetItem(int Index);
	
public:
	void __fastcall AddWordforms(const System::WideString AWord, Dxspellcheckerutils::TdxSpellCheckerStrings* ADictionary, unsigned ALangID);
	__property TdxAffixRule* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxAffixRuleList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAffixRuleList(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomAffixElement : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FCanCombine;
	System::WideChar FKey;
	unsigned FLangID;
	TdxAffixRuleList* FRules;
	
protected:
	virtual TdxAffixRule* __fastcall CreateRule(void) = 0 ;
	virtual bool __fastcall GetIsPrefix(void) = 0 ;
	__property bool CanCombine = {read=FCanCombine, nodefault};
	__property bool IsPrefix = {read=GetIsPrefix, nodefault};
	__property unsigned LangID = {read=FLangID, nodefault};
	__property TdxAffixRuleList* Rules = {read=FRules};
	
public:
	__fastcall virtual TdxCustomAffixElement(System::WideChar AKey, bool ACanCombine, unsigned ALangID);
	__fastcall virtual ~TdxCustomAffixElement(void);
	void __fastcall AddRule(System::WideString ARuleDefinition);
	virtual void __fastcall AddWordforms(const System::WideString AWord, Dxspellcheckerutils::TdxSpellCheckerStrings* ADictionary);
	__property System::WideChar Key = {read=FKey, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxAffixList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAffixList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxCustomAffixElement* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxCustomAffixElement* __fastcall GetItem(int Index);
	
public:
	TdxCustomAffixElement* __fastcall FindForKey(System::WideChar AKey, bool AIsPrefix);
	__property TdxCustomAffixElement* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxAffixList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAffixList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxISpellAffixRule;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxISpellAffixRule : public TdxAffixRule
{
	typedef TdxAffixRule inherited;
	
protected:
	virtual void __fastcall BuildValidator(const System::WideString S);
	virtual bool __fastcall DoParse(const System::WideString ARule);
	virtual void __fastcall ParseNewWordform(const System::WideString S);
	virtual System::WideString __fastcall RemoveComments(const System::WideString ARule);
public:
	/* TdxAffixRule.Create */ inline __fastcall TdxISpellAffixRule(TdxCustomAffixElement* AAffix) : TdxAffixRule(AAffix) { }
	/* TdxAffixRule.Destroy */ inline __fastcall virtual ~TdxISpellAffixRule(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxISpellPrefix;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxISpellPrefix : public TdxCustomAffixElement
{
	typedef TdxCustomAffixElement inherited;
	
protected:
	virtual TdxAffixRule* __fastcall CreateRule(void);
	virtual bool __fastcall GetIsPrefix(void);
public:
	/* TdxCustomAffixElement.Create */ inline __fastcall virtual TdxISpellPrefix(System::WideChar AKey, bool ACanCombine, unsigned ALangID) : TdxCustomAffixElement(AKey, ACanCombine, ALangID) { }
	/* TdxCustomAffixElement.Destroy */ inline __fastcall virtual ~TdxISpellPrefix(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxISpellSuffix;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxISpellSuffix : public TdxISpellPrefix
{
	typedef TdxISpellPrefix inherited;
	
protected:
	virtual bool __fastcall GetIsPrefix(void);
public:
	/* TdxCustomAffixElement.Create */ inline __fastcall virtual TdxISpellSuffix(System::WideChar AKey, bool ACanCombine, unsigned ALangID) : TdxISpellPrefix(AKey, ACanCombine, ALangID) { }
	/* TdxCustomAffixElement.Destroy */ inline __fastcall virtual ~TdxISpellSuffix(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomAffixDecompressor;
class DELPHICLASS TdxAffixCompressionDictionary;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomAffixDecompressor : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxAffixList* FAffixes;
	System::WideString FAlphabet;
	unsigned FCodePage;
	TdxAffixCompressionDictionary* FDictionary;
	System::Classes::TList* FPrefixes;
	System::Classes::TList* FSuffixes;
	Dxspellcheckerutils::TdxSpellCheckerStrings* FWordforms;
	
protected:
	virtual void __fastcall CreateWordforms(const System::WideString AWordDefinition);
	void __fastcall CreateWordFormsForKeys(const System::WideString AWord, const System::WideString AKeys);
	virtual void __fastcall GetLanguageInfo(System::Classes::TStream* AStream, /* out */ unsigned &ACodePage, /* out */ System::WideString &AAlphabet) = 0 ;
	void __fastcall ExtractWordInfo(const System::WideString AWordDefinition, /* out */ System::WideString &AWord, /* out */ System::WideString &AKeys);
	virtual void __fastcall InitParsing(void);
	virtual void __fastcall Parse(Dxspellcheckerutils::TdxSpellCheckerStrings* AStrings);
	virtual void __fastcall ParseLine(System::WideString S) = 0 ;
	virtual System::WideString __fastcall RemoveComments(const System::WideString S);
	void __fastcall Reset(void);
	__property System::Classes::TList* Prefixes = {read=FPrefixes};
	__property System::Classes::TList* Suffixes = {read=FSuffixes};
	__property Dxspellcheckerutils::TdxSpellCheckerStrings* Wordforms = {read=FWordforms};
	
public:
	__fastcall virtual TdxCustomAffixDecompressor(TdxAffixCompressionDictionary* ADictionary);
	__fastcall virtual ~TdxCustomAffixDecompressor(void);
	virtual void __fastcall LoadFromFile(const System::Sysutils::TFileName AFileName);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall PopulateWordForms(const System::WideString AWordDefinition, Dxspellchecker::TdxSpellCheckerWordList* ADictionary);
	__property TdxAffixList* Affixes = {read=FAffixes};
	__property System::WideString Alphabet = {read=FAlphabet};
	__property unsigned CodePage = {read=FCodePage, nodefault};
	__property TdxAffixCompressionDictionary* Dictionary = {read=FDictionary};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxAffixCompressionDictionary : public Dxspellchecker::TdxSpellCheckerDictionary
{
	typedef Dxspellchecker::TdxSpellCheckerDictionary inherited;
	
private:
	System::Sysutils::TFileName FDictionaryPath;
	System::Sysutils::TFileName FGrammarPath;
	void __fastcall SetDictionaryPath(const System::Sysutils::TFileName AValue);
	void __fastcall SetGrammarPath(const System::Sysutils::TFileName AValue);
	
protected:
	virtual TdxCustomAffixDecompressor* __fastcall CreateDecompressor(void) = 0 ;
	virtual bool __fastcall DoLoad(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual void __fastcall LoadGrammar(TdxCustomAffixDecompressor* ADecompressor);
	virtual void __fastcall LoadWordBase(Dxspellcheckerutils::TdxSpellCheckerStrings* AWordBase);
	virtual void __fastcall UpdateByDecompressor(TdxCustomAffixDecompressor* ADecompressor);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Sysutils::TFileName DictionaryPath = {read=FDictionaryPath, write=SetDictionaryPath};
	__property System::Sysutils::TFileName GrammarPath = {read=FGrammarPath, write=SetGrammarPath};
public:
	/* TdxCustomSpellCheckerDictionary.Create */ inline __fastcall virtual TdxAffixCompressionDictionary(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker) : Dxspellchecker::TdxSpellCheckerDictionary(ASpellChecker) { }
	/* TdxCustomSpellCheckerDictionary.Destroy */ inline __fastcall virtual ~TdxAffixCompressionDictionary(void) { }
	
};


class DELPHICLASS TdxISpellDecompressor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxISpellDecompressor : public TdxCustomAffixDecompressor
{
	typedef TdxCustomAffixDecompressor inherited;
	
private:
	TdxCustomAffixElement* FCurrentAffix;
	TdxAffixElementState FCurrentState;
	
protected:
	virtual TdxCustomAffixElement* __fastcall CreateAffix(System::WideChar AKey, bool ACanCombine, TdxAffixElementState AState);
	virtual void __fastcall ExtractKeyInfo(const System::WideString ADefinition, /* out */ System::WideChar &AKey, /* out */ bool &ACanCombine);
	virtual void __fastcall GetLanguageInfo(System::Classes::TStream* AStream, /* out */ unsigned &ACodePage, /* out */ System::WideString &AAlphabet);
	virtual void __fastcall InitParsing(void);
	virtual bool __fastcall IsUnsupportedKeyWord(const System::WideString S);
	virtual void __fastcall ParseLine(System::WideString S);
public:
	/* TdxCustomAffixDecompressor.Create */ inline __fastcall virtual TdxISpellDecompressor(TdxAffixCompressionDictionary* ADictionary) : TdxCustomAffixDecompressor(ADictionary) { }
	/* TdxCustomAffixDecompressor.Destroy */ inline __fastcall virtual ~TdxISpellDecompressor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxISpellDictionary;
class PASCALIMPLEMENTATION TdxISpellDictionary : public TdxAffixCompressionDictionary
{
	typedef TdxAffixCompressionDictionary inherited;
	
protected:
	virtual TdxCustomAffixDecompressor* __fastcall CreateDecompressor(void);
	
__published:
	__property Alphabet = {default=0};
	__property CheckCapitalization = {default=0};
	__property CodePage = {default=0};
	__property DictionaryPath = {default=0};
	__property Enabled = {default=1};
	__property GrammarPath = {default=0};
	__property Language = {default=0};
	__property OnLoaded;
	__property OnLoading;
public:
	/* TdxCustomSpellCheckerDictionary.Create */ inline __fastcall virtual TdxISpellDictionary(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker) : TdxAffixCompressionDictionary(ASpellChecker) { }
	/* TdxCustomSpellCheckerDictionary.Destroy */ inline __fastcall virtual ~TdxISpellDictionary(void) { }
	
};


class DELPHICLASS TdxHunspellAffixRule;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellAffixRule : public TdxISpellAffixRule
{
	typedef TdxISpellAffixRule inherited;
	
protected:
	virtual void __fastcall BuildValidator(const System::WideString S);
	virtual bool __fastcall DoParse(const System::WideString ARule);
public:
	/* TdxAffixRule.Create */ inline __fastcall TdxHunspellAffixRule(TdxCustomAffixElement* AAffix) : TdxISpellAffixRule(AAffix) { }
	/* TdxAffixRule.Destroy */ inline __fastcall virtual ~TdxHunspellAffixRule(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHunspellPrefix;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellPrefix : public TdxCustomAffixElement
{
	typedef TdxCustomAffixElement inherited;
	
protected:
	virtual TdxAffixRule* __fastcall CreateRule(void);
	virtual bool __fastcall GetIsPrefix(void);
public:
	/* TdxCustomAffixElement.Create */ inline __fastcall virtual TdxHunspellPrefix(System::WideChar AKey, bool ACanCombine, unsigned ALangID) : TdxCustomAffixElement(AKey, ACanCombine, ALangID) { }
	/* TdxCustomAffixElement.Destroy */ inline __fastcall virtual ~TdxHunspellPrefix(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHunspellSuffix;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellSuffix : public TdxHunspellPrefix
{
	typedef TdxHunspellPrefix inherited;
	
protected:
	virtual bool __fastcall GetIsPrefix(void);
public:
	/* TdxCustomAffixElement.Create */ inline __fastcall virtual TdxHunspellSuffix(System::WideChar AKey, bool ACanCombine, unsigned ALangID) : TdxHunspellPrefix(AKey, ACanCombine, ALangID) { }
	/* TdxCustomAffixElement.Destroy */ inline __fastcall virtual ~TdxHunspellSuffix(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxHunspellDecompressor;
class DELPHICLASS TdxOpenOfficeDictionary;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxHunspellDecompressor : public TdxCustomAffixDecompressor
{
	typedef TdxCustomAffixDecompressor inherited;
	
private:
	System::WideChar FCurrentKey;
	bool FCurrentKeyCanCombine;
	int FRepCount;
	TdxOpenOfficeDictionary* __fastcall GetDictionary(void);
	
protected:
	virtual TdxCustomAffixElement* __fastcall CreateAffix(System::WideChar AKey, bool ACanCombine, TdxAffixElementState AState);
	virtual void __fastcall GetLanguageInfo(System::Classes::TStream* AStream, /* out */ unsigned &ACodePage, /* out */ System::WideString &AAlphabet);
	virtual void __fastcall InitParsing(void);
	virtual void __fastcall ParseLine(System::WideString S);
	void __fastcall ProcessAlphabet(System::WideString S);
	void __fastcall ProcessAffix(System::WideString S, TdxAffixElementState AState);
	void __fastcall ProcessSubstitution(System::WideString S);
	
public:
	__property TdxOpenOfficeDictionary* Dictionary = {read=GetDictionary};
public:
	/* TdxCustomAffixDecompressor.Create */ inline __fastcall virtual TdxHunspellDecompressor(TdxAffixCompressionDictionary* ADictionary) : TdxCustomAffixDecompressor(ADictionary) { }
	/* TdxCustomAffixDecompressor.Destroy */ inline __fastcall virtual ~TdxHunspellDecompressor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxOpenOfficeSuggestionBuilder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxOpenOfficeSuggestionBuilder : public Dxspellchecker::TdxNearMissStrategy
{
	typedef Dxspellchecker::TdxNearMissStrategy inherited;
	
private:
	TdxOpenOfficeDictionary* __fastcall GetDictionary(void);
	
protected:
	virtual void __fastcall DoAddSuggestions(void);
	bool __fastcall FindPos(const System::WideString ASubStr, const System::WideString AStr, int &AStartPos);
	void __fastcall ProcessSubstitutions(void);
	
public:
	__property TdxOpenOfficeDictionary* Dictionary = {read=GetDictionary};
public:
	/* TdxSpellCheckerSuggestionBuilder.Create */ inline __fastcall virtual TdxOpenOfficeSuggestionBuilder(Dxspellchecker::TdxCustomSpellCheckerDictionary* ADictionary) : Dxspellchecker::TdxNearMissStrategy(ADictionary) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxOpenOfficeSuggestionBuilder(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxOpenOfficeDictionary : public TdxAffixCompressionDictionary
{
	typedef TdxAffixCompressionDictionary inherited;
	
private:
	Dxspellchecker::TdxSpellCheckerReplacementList* FSubstitutions;
	
protected:
	virtual TdxCustomAffixDecompressor* __fastcall CreateDecompressor(void);
	virtual Dxspellchecker::TdxSpellCheckerSuggestionBuilder* __fastcall CreateSuggestionBuilder(void);
	virtual void __fastcall UpdateByDecompressor(TdxCustomAffixDecompressor* ADecompressor);
	__property Dxspellchecker::TdxSpellCheckerReplacementList* Substitutions = {read=FSubstitutions};
	
public:
	__fastcall virtual TdxOpenOfficeDictionary(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker);
	__fastcall virtual ~TdxOpenOfficeDictionary(void);
	
__published:
	__property CheckCapitalization = {default=0};
	__property DictionaryPath = {default=0};
	__property Enabled = {default=1};
	__property GrammarPath = {default=0};
	__property Language = {default=0};
	__property OnLoaded;
	__property OnLoading;
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxispelldecompressor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXISPELLDECOMPRESSOR)
using namespace Dxispelldecompressor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxispelldecompressorHPP
