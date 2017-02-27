// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerOutlookDialog.pas' rev: 24.00 (Win32)

#ifndef DxspellcheckeroutlookdialogHPP
#define DxspellcheckeroutlookdialogHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
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
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckeroutlookdialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxCustomSpellCheckerForm;
class PASCALIMPLEMENTATION TdxCustomSpellCheckerForm : public Dxspellcheckerbaseform::TfmSpellCheckerBaseForm
{
	typedef Dxspellcheckerbaseform::TfmSpellCheckerBaseForm inherited;
	
private:
	bool FInitialized;
	Dxspellchecker::TdxCustomSpellChecker* FSpellChecker;
	Dxspellchecker::TdxSpellCheckerDialogCheckMode* __fastcall GetCheckMode(void);
	
protected:
	DYNAMIC void __fastcall Activate(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall Localize(void);
	virtual void __fastcall ShowSpellingOptionsDialog(void);
	__property Dxspellchecker::TdxSpellCheckerDialogCheckMode* CheckMode = {read=GetCheckMode};
	__property Dxspellchecker::TdxCustomSpellChecker* SpellChecker = {read=FSpellChecker};
	__property bool Initialized = {read=FInitialized, nodefault};
	
public:
	__fastcall virtual TdxCustomSpellCheckerForm(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxCustomSpellCheckerForm(System::Classes::TComponent* AOwner) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxCustomSpellCheckerForm(System::Classes::TComponent* AOwner, int Dummy) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxCustomSpellCheckerForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomSpellCheckerForm(HWND ParentWindow) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxCustomSpellCheckerFormClass;

class DELPHICLASS TfmSpellCheckerOutlookForm;
class PASCALIMPLEMENTATION TfmSpellCheckerOutlookForm : public TdxCustomSpellCheckerForm
{
	typedef TdxCustomSpellCheckerForm inherited;
	
__published:
	Vcl::Stdctrls::TLabel* lbMisspelled;
	Cxtextedit::TcxTextEdit* teMisspelledWord;
	Cxtextedit::TcxTextEdit* teSuggestion;
	Cxlistbox::TcxListBox* lbxSuggestions;
	Cxbuttons::TcxButton* btnIgnore;
	Cxbuttons::TcxButton* btnChange;
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnIgnoreAll;
	Cxbuttons::TcxButton* btnChangeAll;
	Cxbuttons::TcxButton* btnSuggest;
	Cxbuttons::TcxButton* btnOptions;
	Cxbuttons::TcxButton* btnUndoLast;
	Cxbuttons::TcxButton* btnCancel;
	Vcl::Stdctrls::TLabel* lbChangeTo;
	Vcl::Stdctrls::TLabel* lbSuggestions;
	void __fastcall lbxSuggestionsClick(System::TObject* Sender);
	void __fastcall btnSuggestClick(System::TObject* Sender);
	void __fastcall teSuggestionPropertiesChange(System::TObject* Sender);
	void __fastcall btnIgnoreClick(System::TObject* Sender);
	void __fastcall btnIgnoreAllClick(System::TObject* Sender);
	void __fastcall btnChangeClick(System::TObject* Sender);
	void __fastcall btnChangeAllClick(System::TObject* Sender);
	void __fastcall btnAddClick(System::TObject* Sender);
	void __fastcall btnUndoLastClick(System::TObject* Sender);
	void __fastcall btnOptionsClick(System::TObject* Sender);
	
private:
	bool FHasSuggestions;
	System::WideString FMisspelledWord;
	bool FSuggestionLockChange;
	void __fastcall ValidateCaptions(void);
	
protected:
	void __fastcall CheckNextMisspelledWord(void);
	virtual void __fastcall Initialize(void);
	bool __fastcall IsDeleteMisspelled(void);
	virtual void __fastcall Localize(void);
	virtual void __fastcall SetMisspelledWord(const System::WideString AValue);
	void __fastcall SetSuggestions(Dxspellchecker::TdxSpellCheckerSuggestionList* ASuggestions);
	void __fastcall SetSuggestionText(const System::WideString AText);
	void __fastcall SetMisspelledInfo(void);
	__property bool HasSuggestions = {read=FHasSuggestions, nodefault};
	__property System::WideString MisspelledWord = {read=FMisspelledWord, write=SetMisspelledWord};
public:
	/* TdxCustomSpellCheckerForm.CreateEx */ inline __fastcall virtual TfmSpellCheckerOutlookForm(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker) : TdxCustomSpellCheckerForm(ASpellChecker) { }
	
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmSpellCheckerOutlookForm(System::Classes::TComponent* AOwner) : TdxCustomSpellCheckerForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmSpellCheckerOutlookForm(System::Classes::TComponent* AOwner, int Dummy) : TdxCustomSpellCheckerForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmSpellCheckerOutlookForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmSpellCheckerOutlookForm(HWND ParentWindow) : TdxCustomSpellCheckerForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckeroutlookdialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKEROUTLOOKDIALOG)
using namespace Dxspellcheckeroutlookdialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckeroutlookdialogHPP
