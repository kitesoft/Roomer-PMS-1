// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxHunspellUtils.pas' rev: 24.00 (Win64)

#ifndef DxhunspellutilsHPP
#define DxhunspellutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxHunspellTypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxhunspellutils
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define mlPhon L"ph:"
static const int mlTagLength = int(3);
static const System::Word dxDefaultFlags = System::Word(0xffe6);
static const System::Word dxForbiddenWordFlag = System::Word(0xffe6);
static const System::Word dxOnlyUpcaseFlag = System::Word(0xffe7);
static const System::Int8 dxNullFlag = System::Int8(0x0);
extern PACKAGE System::Word dxDefaultHunspellCodePage;
extern PACKAGE System::WideChar *dxDefaultHunspellKeyboardString;
extern PACKAGE bool dxHunspellWarningFlag;
extern PACKAGE System::UnicodeString dxHunspellLastWarningMessage;
extern PACKAGE int dxHunspellLastWarningLineIndex;
extern PACKAGE bool __fastcall ContainsFlag(Dxhunspelltypes::PdxAffixFlagsData AFlags, int ALength, System::Word ARequiredFlag);
extern PACKAGE System::WideChar * __fastcall CopyMorphology(System::WideChar * ADestination, const System::WideChar * AMorphologicalDescription, const System::WideChar * AMorphologicalField);
extern PACKAGE int __fastcall GetLanguageID(System::WideChar * ALanguage);
extern PACKAGE bool __fastcall GetSecondPartOfString(System::WideChar * S, /* out */ System::WideChar * &ADest);
extern PACKAGE void __fastcall HunspellError(const System::UnicodeString AMessage, int ALineIndex);
extern PACKAGE System::WideChar * __fastcall IntStr(int AValue);
extern PACKAGE bool __fastcall IsDigit(System::WideChar AChar);
extern PACKAGE bool __fastcall IsSpace(System::WideChar AChar);
extern PACKAGE bool __fastcall IsUpCase(System::WideChar AChar);
extern PACKAGE void __fastcall MakeAllCapital(System::WideChar * S, unsigned ALangID, int ALength = 0x0);
extern PACKAGE void __fastcall MakeAllSmall(System::WideChar * S, unsigned ALangID, int ALength = 0x0);
extern PACKAGE void __fastcall MakeCapitalized(System::WideChar * S, unsigned ALangID);
extern PACKAGE void __fastcall MakeCharLower(System::WideChar * S, int AIndex, unsigned ALangID);
extern PACKAGE void __fastcall RemoveCRLF(System::WideChar * S);
extern PACKAGE void __fastcall RemoveIgnoredChars(System::WideChar * S, const System::WideChar * AIgnoreChars);
extern PACKAGE void __fastcall SortFlags(System::Word *AFlags, const int AFlags_Size, int ABegin, int AEnd);
extern PACKAGE System::WideChar * __fastcall StrCopyReverse(System::WideChar * S);
extern PACKAGE void __fastcall StrFreeAndNil(System::WideChar * &S);
extern PACKAGE int __fastcall StrInt(System::WideChar * S);
extern PACKAGE System::WideChar * __fastcall StrReplace(System::WideChar * S, System::WideChar * APattern, System::WideChar * AReplacement);
extern PACKAGE System::WideChar * __fastcall StrReverse(System::WideChar * S);
extern PACKAGE System::WideChar * __fastcall StrSeparate(Dxhunspelltypes::PPWideChar S, const System::WideChar ADelimiter);
}	/* namespace Dxhunspellutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXHUNSPELLUTILS)
using namespace Dxhunspellutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxhunspellutilsHPP
