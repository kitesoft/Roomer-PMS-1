// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerRules.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckerrulesHPP
#define DxspellcheckerrulesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerrules
{
//-- type declarations -------------------------------------------------------
enum TdxSpellCheckerSpellingCode : unsigned char { scNoError, scMisspelled, scRepeatedWords };

class DELPHICLASS TdxCustomSpellCheckerTextHelper;
class PASCALIMPLEMENTATION TdxCustomSpellCheckerTextHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	virtual System::WideString __fastcall GetPrevWord(void) = 0 ;
	virtual bool __fastcall WordExists(const System::WideString AWord) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TdxCustomSpellCheckerTextHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomSpellCheckerTextHelper(void) { }
	
};


class DELPHICLASS TdxSpellCheckerRule;
class PASCALIMPLEMENTATION TdxSpellCheckerRule : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxCustomSpellCheckerTextHelper* FTextHelper;
	
protected:
	virtual bool __fastcall Explicit(void);
	virtual TdxSpellCheckerSpellingCode __fastcall GetErrorCode(void);
	__property TdxCustomSpellCheckerTextHelper* TextHelper = {read=FTextHelper};
	
public:
	__fastcall TdxSpellCheckerRule(TdxCustomSpellCheckerTextHelper* ATextHelper);
	virtual bool __fastcall CanApply(const System::WideString AWord) = 0 ;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerRule(void) { }
	
};


typedef System::TMetaClass* TdxSpellCheckerRuleClass;

class DELPHICLASS TdxSpellCheckerRules;
class PASCALIMPLEMENTATION TdxSpellCheckerRules : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSpellCheckerRule* operator[](int Index) { return Items[Index]; }
	
private:
	TdxSpellCheckerSpellingCode FErrorCode;
	HIDESBASE TdxSpellCheckerRule* __fastcall GetItem(int Index);
	
public:
	HIDESBASE void __fastcall Add(TdxSpellCheckerRule* ARule);
	TdxSpellCheckerRule* __fastcall FindNextRuleByClass(int &AIndex, TdxSpellCheckerRuleClass ARuleClass);
	TdxSpellCheckerRule* __fastcall FindRule(const System::WideString AWord);
	bool __fastcall IsValid(const System::WideString AWord);
	bool __fastcall IsValidExplicit(const System::WideString AWord);
	bool __fastcall IsValidImplicit(const System::WideString AWord);
	__property TdxSpellCheckerSpellingCode ErrorCode = {read=FErrorCode, nodefault};
	__property TdxSpellCheckerRule* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxSpellCheckerRules(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSpellCheckerRules(void) { }
	
};


class DELPHICLASS TdxSpellCheckerIgnoreUrlRule;
class PASCALIMPLEMENTATION TdxSpellCheckerIgnoreUrlRule : public TdxSpellCheckerRule
{
	typedef TdxSpellCheckerRule inherited;
	
public:
	virtual bool __fastcall CanApply(const System::WideString AWord);
public:
	/* TdxSpellCheckerRule.Create */ inline __fastcall TdxSpellCheckerIgnoreUrlRule(TdxCustomSpellCheckerTextHelper* ATextHelper) : TdxSpellCheckerRule(ATextHelper) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerIgnoreUrlRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerIgnoreEmailRule;
class PASCALIMPLEMENTATION TdxSpellCheckerIgnoreEmailRule : public TdxSpellCheckerRule
{
	typedef TdxSpellCheckerRule inherited;
	
public:
	virtual bool __fastcall CanApply(const System::WideString AWord);
public:
	/* TdxSpellCheckerRule.Create */ inline __fastcall TdxSpellCheckerIgnoreEmailRule(TdxCustomSpellCheckerTextHelper* ATextHelper) : TdxSpellCheckerRule(ATextHelper) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerIgnoreEmailRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerIgnoreUpperCaseWordsRule;
class PASCALIMPLEMENTATION TdxSpellCheckerIgnoreUpperCaseWordsRule : public TdxSpellCheckerRule
{
	typedef TdxSpellCheckerRule inherited;
	
public:
	virtual bool __fastcall CanApply(const System::WideString AWord);
public:
	/* TdxSpellCheckerRule.Create */ inline __fastcall TdxSpellCheckerIgnoreUpperCaseWordsRule(TdxCustomSpellCheckerTextHelper* ATextHelper) : TdxSpellCheckerRule(ATextHelper) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerIgnoreUpperCaseWordsRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerIgnoreMixedCaseWordsRule;
class PASCALIMPLEMENTATION TdxSpellCheckerIgnoreMixedCaseWordsRule : public TdxSpellCheckerRule
{
	typedef TdxSpellCheckerRule inherited;
	
public:
	virtual bool __fastcall CanApply(const System::WideString AWord);
public:
	/* TdxSpellCheckerRule.Create */ inline __fastcall TdxSpellCheckerIgnoreMixedCaseWordsRule(TdxCustomSpellCheckerTextHelper* ATextHelper) : TdxSpellCheckerRule(ATextHelper) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerIgnoreMixedCaseWordsRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerIgnoreWordsWithNumbersRule;
class PASCALIMPLEMENTATION TdxSpellCheckerIgnoreWordsWithNumbersRule : public TdxSpellCheckerRule
{
	typedef TdxSpellCheckerRule inherited;
	
public:
	virtual bool __fastcall CanApply(const System::WideString AWord);
public:
	/* TdxSpellCheckerRule.Create */ inline __fastcall TdxSpellCheckerIgnoreWordsWithNumbersRule(TdxCustomSpellCheckerTextHelper* ATextHelper) : TdxSpellCheckerRule(ATextHelper) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerIgnoreWordsWithNumbersRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerWordExistsRule;
class PASCALIMPLEMENTATION TdxSpellCheckerWordExistsRule : public TdxSpellCheckerRule
{
	typedef TdxSpellCheckerRule inherited;
	
public:
	virtual bool __fastcall CanApply(const System::WideString AWord);
public:
	/* TdxSpellCheckerRule.Create */ inline __fastcall TdxSpellCheckerWordExistsRule(TdxCustomSpellCheckerTextHelper* ATextHelper) : TdxSpellCheckerRule(ATextHelper) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerWordExistsRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerRepeatedWordsRule;
class PASCALIMPLEMENTATION TdxSpellCheckerRepeatedWordsRule : public TdxSpellCheckerRule
{
	typedef TdxSpellCheckerRule inherited;
	
protected:
	virtual bool __fastcall Explicit(void);
	virtual TdxSpellCheckerSpellingCode __fastcall GetErrorCode(void);
	
public:
	virtual bool __fastcall CanApply(const System::WideString AWord);
public:
	/* TdxSpellCheckerRule.Create */ inline __fastcall TdxSpellCheckerRepeatedWordsRule(TdxCustomSpellCheckerTextHelper* ATextHelper) : TdxSpellCheckerRule(ATextHelper) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerRepeatedWordsRule(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckerrules */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERRULES)
using namespace Dxspellcheckerrules;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerrulesHPP
