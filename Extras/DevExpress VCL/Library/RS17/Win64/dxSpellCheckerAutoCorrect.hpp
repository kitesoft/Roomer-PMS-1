// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerAutoCorrect.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckerautocorrectHPP
#define DxspellcheckerautocorrectHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxSpellChecker.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerautocorrect
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSpellCheckerCorrectSentenceCapsRule;
class PASCALIMPLEMENTATION TdxSpellCheckerCorrectSentenceCapsRule : public Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule
{
	typedef Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule inherited;
	
private:
	System::WideString FPrevWord;
	System::WideString FSentenceDelimiters;
	
protected:
	virtual bool __fastcall GetActive(void);
	virtual void __fastcall InitializeDelimiters(void);
	bool __fastcall IsSentenceDelimiter(System::WideChar ACh);
	
public:
	virtual bool __fastcall IsCheckWord(const System::WideString AText, int &AStart, int &ALength, System::WideString &AWord);
	virtual void __fastcall Undo(void);
	__property System::WideString SentenceDelimiters = {read=FSentenceDelimiters};
public:
	/* TdxSpellCheckerAutoCorrectCustomRule.Create */ inline __fastcall virtual TdxSpellCheckerCorrectSentenceCapsRule(Dxspellchecker::TdxSpellCheckerCustomAutoCorrectManager* AManager) : Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule(AManager) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCorrectSentenceCapsRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCorrectCapsLockRule;
class PASCALIMPLEMENTATION TdxSpellCheckerCorrectCapsLockRule : public Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule
{
	typedef Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule inherited;
	
protected:
	virtual bool __fastcall GetActive(void);
	virtual void __fastcall InitializeDelimiters(void);
	
public:
	virtual void __fastcall AfterCorrect(void);
	virtual bool __fastcall IsCheckWord(const System::WideString AText, int &AStart, int &ALength, System::WideString &AWord);
public:
	/* TdxSpellCheckerAutoCorrectCustomRule.Create */ inline __fastcall virtual TdxSpellCheckerCorrectCapsLockRule(Dxspellchecker::TdxSpellCheckerCustomAutoCorrectManager* AManager) : Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule(AManager) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCorrectCapsLockRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCorrectInitialCapsRule;
class PASCALIMPLEMENTATION TdxSpellCheckerCorrectInitialCapsRule : public Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule
{
	typedef Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule inherited;
	
private:
	System::WideString FWord;
	
protected:
	virtual bool __fastcall GetActive(void);
	virtual void __fastcall InitializeDelimiters(void);
	
public:
	virtual bool __fastcall IsCheckWord(const System::WideString AText, int &AStart, int &ALength, System::WideString &AWord);
	virtual void __fastcall Undo(void);
public:
	/* TdxSpellCheckerAutoCorrectCustomRule.Create */ inline __fastcall virtual TdxSpellCheckerCorrectInitialCapsRule(Dxspellchecker::TdxSpellCheckerCustomAutoCorrectManager* AManager) : Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule(AManager) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCorrectInitialCapsRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerCorrectReplaceTextAsYouTypeRule;
class PASCALIMPLEMENTATION TdxSpellCheckerCorrectReplaceTextAsYouTypeRule : public Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule
{
	typedef Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule inherited;
	
protected:
	virtual bool __fastcall GetActive(void);
	virtual void __fastcall InitializeDelimiters(void);
	
public:
	virtual bool __fastcall IsCheckWord(const System::WideString AText, int &AStart, int &ALength, System::WideString &AWord);
	virtual bool __fastcall IsTerminating(void);
public:
	/* TdxSpellCheckerAutoCorrectCustomRule.Create */ inline __fastcall virtual TdxSpellCheckerCorrectReplaceTextAsYouTypeRule(Dxspellchecker::TdxSpellCheckerCustomAutoCorrectManager* AManager) : Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule(AManager) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSpellCheckerCorrectReplaceTextAsYouTypeRule(void) { }
	
};


class DELPHICLASS TdxSpellCheckerAutoCorrectManager;
class PASCALIMPLEMENTATION TdxSpellCheckerAutoCorrectManager : public Dxspellchecker::TdxSpellCheckerCustomAutoCorrectManager
{
	typedef Dxspellchecker::TdxSpellCheckerCustomAutoCorrectManager inherited;
	
private:
	System::WideString FPrevWord;
	Cxclasses::TcxObjectList* FRules;
	Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule* FLastApplyRule;
	
protected:
	void __fastcall ApplyChanges(const Cxcontrols::TdxSpellCheckerAutoCorrectWordRange &AWordRange);
	virtual void __fastcall DoActiveChanged(void);
	virtual void __fastcall DoOptionsChanged(void);
	Cxcontrols::TdxSpellCheckerAutoCorrectWordRange __fastcall GetAutoCorrectWordRange(void);
	virtual void __fastcall InitializeRules(void);
	virtual bool __fastcall IsConsistentWithRule(Dxspellchecker::TdxSpellCheckerAutoCorrectCustomRule* ARule, System::WideChar AKey, Cxcontrols::TdxSpellCheckerAutoCorrectWordRange &AWordRange);
	virtual void __fastcall Undo(void);
	
public:
	__fastcall virtual TdxSpellCheckerAutoCorrectManager(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker);
	__fastcall virtual ~TdxSpellCheckerAutoCorrectManager(void);
	virtual void __fastcall KeyPress(System::WideChar AKey);
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckerautocorrect */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERAUTOCORRECT)
using namespace Dxspellcheckerautocorrect;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerautocorrectHPP
