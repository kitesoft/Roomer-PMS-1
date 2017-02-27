// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxHunspellTypes.pas' rev: 24.00 (Win32)

#ifndef DxhunspelltypesHPP
#define DxhunspelltypesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxhunspelltypes
{
//-- type declarations -------------------------------------------------------
typedef System::WideChar * *PPWideChar;

typedef System::Word *PWord;

typedef PWord *PPWord;

typedef System::StaticArray<System::Word, 1> TWordArray;

typedef TWordArray *PWordArray;

typedef System::StaticArray<int, 1> TIntegerArray;

typedef TIntegerArray *PIntegerArray;

typedef System::StaticArray<System::WideChar *, 1> TdxPWideCharArray;

typedef TdxPWideCharArray *PdxPWideCharArray;

typedef System::StaticArray<System::WideChar, 16000> TdxLineBuffer;

typedef System::StaticArray<System::Word, 1> TdxAffixFlagsData;

typedef TdxAffixFlagsData *PdxAffixFlagsData;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxMaxWordLength = System::Int8(0x64);
static const System::Word dxMaxLineLength = System::Word(0x3e80);
static const System::Int8 LanguageNone = System::Int8(0x0);
static const System::Word LanguageHu = System::Word(0x40e);
#define diAf L"AF"
#define diAm L"AM"
#define diBreak L"BREAK"
#define diCheckCompoundCase L"CHECKCOMPOUNDCASE"
#define diCheckCompoundDup L"CHECKCOMPOUNDDUP"
#define diCheckCompoundPattern L"CHECKCOMPOUNDPATTERN"
#define diCheckCompoundRep L"CHECKCOMPOUNDREP"
#define diCheckCompoundTriple L"CHECKCOMPOUNDTRIPLE"
#define diCheckSharps L"CHECKSHARPS"
#define diCircumfix L"CIRCUMFIX"
#define diComplexPrefixes L"COMPLEXPREFIXES"
#define diCompoundFlag L"COMPOUNDFLAG"
#define diCompoundBegin L"COMPOUNDBEGIN"
#define diCompoundEnd L"COMPOUNDEND"
#define diCompoundMiddle L"COMPOUNDMIDDLE"
#define diCompoundWordMax L"COMPOUNDWORDMAX"
#define diCompoundRoot L"COMPOUNDROOT"
#define diCompoundPermitFlag L"COMPOUNDPERMITFLAG"
#define diCompoundForbidFlag L"COMPOUNDFORBIDFLAG"
#define diCompoundMin L"COMPOUNDMIN"
#define diCompoundRule L"COMPOUNDRULE"
#define diCompoundSyllable L"COMPOUNDSYLLABLE"
#define diFlag L"FLAG"
#define diForbiddenWord L"FORBIDDENWORD"
#define diFullStrip L"FULLSTRIP"
#define diIConv L"ICONV"
#define diIgnore L"IGNORE"
#define diKeepCase L"KEEPCASE"
#define diKey L"KEY"
#define diLang L"LANG"
#define diLemmaPresent L"LEMMA_PRESENT"
#define diMap L"MAP"
#define diNeedAffix L"NEEDAFFIX"
#define diMaxNgramSugs L"MAXNGRAMSUGS"
#define diNoSplitSugs L"NOSPLITSUGS"
#define diNoSuggest L"NOSUGGEST"
#define diOConv L"OCONV"
#define diInCompoundOnly L"ONLYINCOMPOUND"
#define diPhone L"PHONE"
#define diPrefix L"PFX"
#define diPseudoRoot L"PSEUDOROOT"
#define diRep L"REP"
#define diSet L"SET"
#define diSimplifiedTriple L"SIMPLIFIEDTRIPLE"
#define diSubStandard L"SUBSTANDARD"
#define diSuffix L"SFX"
#define diSugsWithDots L"SUGSWITHDOTS"
#define diSyllableNum L"SYLLABLENUM"
#define diTry L"TRY"
#define diVersion L"VERSION"
#define diWordChars L"WORDCHARS"
}	/* namespace Dxhunspelltypes */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXHUNSPELLTYPES)
using namespace Dxhunspelltypes;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxhunspelltypesHPP
