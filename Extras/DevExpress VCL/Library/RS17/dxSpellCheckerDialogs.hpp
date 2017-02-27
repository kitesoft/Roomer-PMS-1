// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerDialogs.pas' rev: 24.00 (Win32)

#ifndef DxspellcheckerdialogsHPP
#define DxspellcheckerdialogsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxSpellChecker.hpp>	// Pascal unit
#include <dxCustomDictionaryDialog.hpp>	// Pascal unit
#include <dxSpellCheckerOutlookDialog.hpp>	// Pascal unit
#include <dxSpellCheckerWordDialog.hpp>	// Pascal unit
#include <dxSpellCheckerSpellingOptionsDialog.hpp>	// Pascal unit
#include <dxSpellCheckerAutoCorrectOptionsDialog.hpp>	// Pascal unit
#include <dxSpellCheckerAutoCorrectExceptionDialog.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerdialogs
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Dxcustomdictionarydialog::TdxCustomDictionaryFormClass dxCustomDictionaryDialogClass;
extern PACKAGE Dxspellcheckerautocorrectoptionsdialog::TdxCustomSpellCheckerAutoCorrectFormClass dxSpellCheckerAutoCorrectExceptionsDialogClass;
extern PACKAGE Dxspellcheckerautocorrectoptionsdialog::TdxCustomSpellCheckerAutoCorrectFormClass dxSpellCheckerAutoCorrectOptionsDialogClass;
extern PACKAGE Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerFormClass dxSpellCheckerOutlookDialogClass;
extern PACKAGE Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerFormClass dxSpellCheckerWordDialogClass;
extern PACKAGE Dxspellcheckerspellingoptionsdialog::TfmSpellCheckerSpellingOptionsFormClass dxSpellCheckerSpellingOptionsDialogClass;
extern PACKAGE int __fastcall dxShowCustomDictionaryDialog(Dxspellchecker::TdxUserSpellCheckerDictionary* ADictionary, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0));
extern PACKAGE int __fastcall dxShowAutoCorrectExceptionsDialog(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0));
extern PACKAGE int __fastcall dxShowAutoCorrectOptionsDialog(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0));
extern PACKAGE int __fastcall dxShowOutlookSpellingDialog(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0));
extern PACKAGE int __fastcall dxShowSpellingOptionsDialog(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0));
extern PACKAGE int __fastcall dxShowWordSpellingDialog(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0));
}	/* namespace Dxspellcheckerdialogs */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERDIALOGS)
using namespace Dxspellcheckerdialogs;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerdialogsHPP
