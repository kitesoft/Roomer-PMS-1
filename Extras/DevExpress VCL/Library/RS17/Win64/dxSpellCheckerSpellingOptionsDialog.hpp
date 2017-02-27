// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerSpellingOptionsDialog.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckerspellingoptionsdialogHPP
#define DxspellcheckerspellingoptionsdialogHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <dxSpellChecker.hpp>	// Pascal unit
#include <dxSpellCheckerBaseForm.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <dxSpellCheckerOutlookDialog.hpp>	// Pascal unit
#include <cxRichEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxCheckComboBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerspellingoptionsdialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmSpellCheckerSpellingOptionsForm;
class PASCALIMPLEMENTATION TfmSpellCheckerSpellingOptionsForm : public Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm
{
	typedef Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnApply;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnOk;
	Cxgroupbox::TcxGroupBox* gbGeneralOptions;
	Cxcheckbox::TcxCheckBox* cbIgnoreEmails;
	Cxcheckbox::TcxCheckBox* cbIgnoreMixedCaseWords;
	Cxcheckbox::TcxCheckBox* cbIgnoreUpperCaseWords;
	Cxcheckbox::TcxCheckBox* cbIgnoreUrls;
	Cxcheckbox::TcxCheckBox* cbIgnoreWordsWithNumbers;
	Cxcheckbox::TcxCheckBox* cbIgnoreRepeatedWords;
	Cxgroupbox::TcxGroupBox* gbCustomDictionary;
	Cxlabel::TcxLabel* lbEditCustomDictionary;
	Cxbuttons::TcxButton* btnEdit;
	Cxgroupbox::TcxGroupBox* gbInternationalDictionaries;
	Cxlabel::TcxLabel* lbInternationalDictionaries;
	Cximage::TcxImage* cxImage1;
	Cximage::TcxImage* cxImage2;
	Cximage::TcxImage* cxImage3;
	Cxlabel::TcxLabel* lbLanguage;
	Cxcheckcombobox::TcxCheckComboBox* ccbLanguages;
	void __fastcall cbChange(System::TObject* Sender);
	void __fastcall btnEditClick(System::TObject* Sender);
	void __fastcall btnApplyClick(System::TObject* Sender);
	
private:
	bool FIsModified;
	int __fastcall GetDictionaryLanguage(Dxspellchecker::TdxCustomSpellCheckerDictionary* ADictionary);
	Dxspellchecker::TdxSpellCheckerSpellingOptions* __fastcall GetOptions(void);
	void __fastcall ValidateButtonsState(void);
	
protected:
	virtual void __fastcall Initialize(void);
	virtual void __fastcall Localize(void);
	void __fastcall PopulateLanguages(void);
	virtual void __fastcall Save(void);
	virtual void __fastcall SynchronizeDialogWithOptions(void);
	virtual void __fastcall SynchronizeOptionsWithDialog(void);
	
public:
	__property Dxspellchecker::TdxSpellCheckerSpellingOptions* Options = {read=GetOptions};
public:
	/* TdxCustomSpellCheckerForm.CreateEx */ inline __fastcall virtual TfmSpellCheckerSpellingOptionsForm(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker) : Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm(ASpellChecker) { }
	
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmSpellCheckerSpellingOptionsForm(System::Classes::TComponent* AOwner) : Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmSpellCheckerSpellingOptionsForm(System::Classes::TComponent* AOwner, int Dummy) : Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmSpellCheckerSpellingOptionsForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmSpellCheckerSpellingOptionsForm(HWND ParentWindow) : Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TfmSpellCheckerSpellingOptionsFormClass;

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckerspellingoptionsdialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERSPELLINGOPTIONSDIALOG)
using namespace Dxspellcheckerspellingoptionsdialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerspellingoptionsdialogHPP
