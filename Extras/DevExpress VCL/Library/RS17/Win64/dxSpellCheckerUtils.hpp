// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerUtils.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckerutilsHPP
#define DxspellcheckerutilsHPP

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
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerutils
{
//-- type declarations -------------------------------------------------------
enum TdxCapitalizationType : unsigned char { ctLower, ctCapitalized, ctUpper, ctMixedCapitalized, ctMixed };

class DELPHICLASS TdxSpellCheckerStrings;
class PASCALIMPLEMENTATION TdxSpellCheckerStrings : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	System::WideChar * operator[](int Index) { return Items[Index]; }
	
private:
	unsigned FCodePage;
	System::WideChar * __fastcall GetItem(int Index);
	System::WideString __fastcall GetText(void);
	void __fastcall SetText(const System::WideString AValue);
	int __fastcall GetLength(int Index);
	
protected:
	System::WideChar * __fastcall AddRaw(void * AData, unsigned ALength);
	int __fastcall ItemLength(System::WideChar * P);
	
public:
	__fastcall TdxSpellCheckerStrings(unsigned ACodePage);
	HIDESBASE System::WideChar * __fastcall Add(const System::WideString S);
	virtual void __fastcall Clear(void);
	void __fastcall LoadFromFile(const System::Sysutils::TFileName AFileName);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	void __fastcall SaveToFile(const System::Sysutils::TFileName AFileName);
	void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property unsigned CodePage = {read=FCodePage, write=FCodePage, nodefault};
	__property System::WideChar * Items[int Index] = {read=GetItem/*, default*/};
	__property int Lengths[int Index] = {read=GetLength};
	__property System::WideString Text = {read=GetText, write=SetText};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerStrings(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCodePage;
class PASCALIMPLEMENTATION TdxSpellCheckerCodePage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	unsigned FCode;
	System::WideString __fastcall GetName(void);
	
public:
	__fastcall TdxSpellCheckerCodePage(unsigned ACode);
	__property unsigned Code = {read=FCode, nodefault};
	__property System::WideString Name = {read=GetName};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCodePage(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCodePages;
class PASCALIMPLEMENTATION TdxSpellCheckerCodePages : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSpellCheckerCodePage* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	unsigned __fastcall GetCode(int AIndex);
	unsigned __fastcall GetCodeByName(const System::WideString AName);
	HIDESBASE TdxSpellCheckerCodePage* __fastcall GetItem(int AIndex);
	System::WideString __fastcall GetName(int AIndex);
	System::WideString __fastcall GetNameByCode(unsigned ACode);
	
protected:
	unsigned __stdcall CallbackProc(System::WideChar * ACodePage);
	
public:
	__fastcall TdxSpellCheckerCodePages(bool AOnlyInstalled);
	void __fastcall PopulateCodePages(System::Classes::TStringList* AList);
	__property unsigned Code[int AIndex] = {read=GetCode};
	__property unsigned CodeByName[const System::WideString AName] = {read=GetCodeByName};
	__property TdxSpellCheckerCodePage* Items[int AIndex] = {read=GetItem/*, default*/};
	__property System::WideString Name[int AIndex] = {read=GetName};
	__property System::WideString NameByCode[unsigned ACode] = {read=GetNameByCode};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCodePages(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall StrEquals(const System::WideChar * S1, const System::WideChar * S2);
extern PACKAGE System::WideString __fastcall CreateAlphabetFromAnsiString(unsigned ACodePage, const System::AnsiString AnsiAlphabet, bool ACaseSensitive);
extern PACKAGE System::WideString __fastcall CreateDefaultAlphabet(unsigned ACodePage, bool ACaseSensitive = false);
extern PACKAGE unsigned __fastcall GetCodePageByName(System::AnsiString AName)/* overload */;
extern PACKAGE unsigned __fastcall GetCodePageByName(System::WideChar * AName)/* overload */;
extern PACKAGE int __fastcall GetWideCharCount(System::WideChar AChar, const System::WideString S);
extern PACKAGE TdxCapitalizationType __fastcall GetWordCapitalizationType(System::WideChar * S, int ALength, unsigned ALangID)/* overload */;
extern PACKAGE TdxCapitalizationType __fastcall GetWordCapitalizationType(const System::WideString S)/* overload */;
extern PACKAGE bool __fastcall IsUrl(const System::WideString S);
extern PACKAGE int __fastcall LanguageToCodePage(unsigned ALanguage);
extern PACKAGE System::WideString __fastcall WideCapitalizeCase(const System::WideString S);
extern PACKAGE bool __fastcall WideCharInSet(System::WideChar C, const Dxcore::TdxAnsiCharSet &ACharSet);
extern PACKAGE bool __fastcall WideIsAlphaNumeric(System::WideChar Ch);
extern PACKAGE bool __fastcall WideIsSpace(System::WideChar Ch);
extern PACKAGE bool __fastcall WideIsUpCase(System::WideChar Ch);
extern PACKAGE bool __fastcall WideIsLoCase(System::WideChar Ch);
extern PACKAGE System::WideChar __fastcall WideLowCase(System::WideChar Ch, unsigned ALangID);
extern PACKAGE System::WideChar __fastcall WideUpCase(System::WideChar Ch, unsigned ALangID);
extern PACKAGE System::WideString __fastcall WidePatternCase(const System::WideString APattern, const System::WideString S);
extern PACKAGE int __fastcall WidePos(const System::WideString ASubStr, const System::WideString S);
extern PACKAGE bool __fastcall WideStringContainsAlpha(const System::WideString S);
extern PACKAGE int __fastcall WideCharPos(System::WideChar Ch, const System::WideString S);
extern PACKAGE bool __fastcall WideStartsWith(const System::WideString ASubStr, const System::WideString S);
extern PACKAGE bool __fastcall WideEndsWith(const System::WideString ASubStr, const System::WideString S);
extern PACKAGE System::AnsiString __fastcall StreamToAnsiString(System::Classes::TStream* AStream, int APos, int ASize = 0x0);
extern PACKAGE System::WideString __fastcall StreamToWideString(System::Classes::TStream* AStream, unsigned ACodePage, int APos, int ASize = 0x0);
extern PACKAGE System::WideString __fastcall dxGetCodePageName(unsigned ACodePage);
extern PACKAGE void __fastcall dxPopulateCodePages(System::Classes::TStringList* AList, bool AOnlyInstalled = true);
}	/* namespace Dxspellcheckerutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERUTILS)
using namespace Dxspellcheckerutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerutilsHPP
