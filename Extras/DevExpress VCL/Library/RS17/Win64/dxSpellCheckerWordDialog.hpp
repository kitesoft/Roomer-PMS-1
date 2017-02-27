// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerWordDialog.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckerworddialogHPP
#define DxspellcheckerworddialogHPP

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
#include <dxSpellCheckerOutlookDialog.hpp>	// Pascal unit
#include <cxRichEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerworddialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmSpellCheckerWordForm;
class PASCALIMPLEMENTATION TfmSpellCheckerWordForm : public Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm
{
	typedef Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm inherited;
	
__published:
	Vcl::Stdctrls::TLabel* lbMisspelled;
	Cxlistbox::TcxListBox* lbxSuggestions;
	Cxbuttons::TcxButton* btnIgnore;
	Cxbuttons::TcxButton* btnChange;
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnIgnoreAll;
	Cxbuttons::TcxButton* btnChangeAll;
	Cxbuttons::TcxButton* btnOptions;
	Cxbuttons::TcxButton* btnUndo;
	Cxbuttons::TcxButton* btnCancel;
	Vcl::Stdctrls::TLabel* lbSuggestions;
	Cxrichedit::TcxRichEdit* reMisspelledText;
	Cxbuttons::TcxButton* btnUndoEdit;
	void __fastcall lbxSuggestionsClick(System::TObject* Sender);
	void __fastcall btnIgnoreClick(System::TObject* Sender);
	void __fastcall btnIgnoreAllClick(System::TObject* Sender);
	void __fastcall btnChangeAllClick(System::TObject* Sender);
	void __fastcall btnChangeClick(System::TObject* Sender);
	void __fastcall btnAddClick(System::TObject* Sender);
	void __fastcall btnUndoClick(System::TObject* Sender);
	void __fastcall reMisspelledPropertiesChange(System::TObject* Sender);
	void __fastcall btnUndoEditClick(System::TObject* Sender);
	void __fastcall btnOptionsClick(System::TObject* Sender);
	
private:
	bool FChangeAll;
	bool FHasSuggestions;
	Dxspellchecker::TdxSpellCheckerSentence FMisspelledSentence;
	System::WideString FMisspelledWord;
	HIDESBASE Dxspellchecker::TdxSpellCheckerWordCheckMode* __fastcall GetCheckMode(void);
	bool __fastcall GetIsChanged(void);
	void __fastcall InnerChange(const System::WideString AWord);
	bool __fastcall IsValidSuggestion(void);
	void __fastcall SetUndoEditVisible(bool AVisible);
	void __fastcall UpdateMisspelledText(void);
	void __fastcall ValidateButtonsCaption(void);
	void __fastcall ValidateChange(void);
	void __fastcall ConfirmUseUnknownWord(const System::WideString AWord);
	
protected:
	void __fastcall CheckNextMisspelledWord(void);
	virtual void __fastcall Initialize(void);
	bool __fastcall IsDeleteMisspelled(void);
	bool __fastcall IsModifyMisspelledWordOnly(/* out */ System::WideString &ANewWord);
	virtual void __fastcall Localize(void);
	virtual void __fastcall SetMisspelledWord(const System::WideString AValue);
	void __fastcall SetSuggestions(Dxspellchecker::TdxSpellCheckerSuggestionList* ASuggestions);
	void __fastcall SetMisspelledInfo(void);
	void __fastcall ValidateButtonsState(void);
	__property Dxspellchecker::TdxSpellCheckerWordCheckMode* CheckMode = {read=GetCheckMode};
	__property bool IsChanged = {read=GetIsChanged, nodefault};
	__property bool HasSuggestions = {read=FHasSuggestions, nodefault};
	__property Dxspellchecker::TdxSpellCheckerSentence MisspelledSentence = {read=FMisspelledSentence};
	__property System::WideString MisspelledWord = {read=FMisspelledWord, write=SetMisspelledWord};
public:
	/* TdxCustomSpellCheckerForm.CreateEx */ inline __fastcall virtual TfmSpellCheckerWordForm(Dxspellchecker::TdxCustomSpellChecker* ASpellChecker) : Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm(ASpellChecker) { }
	
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmSpellCheckerWordForm(System::Classes::TComponent* AOwner) : Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmSpellCheckerWordForm(System::Classes::TComponent* AOwner, int Dummy) : Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmSpellCheckerWordForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmSpellCheckerWordForm(HWND ParentWindow) : Dxspellcheckeroutlookdialog::TdxCustomSpellCheckerForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckerworddialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERWORDDIALOG)
using namespace Dxspellcheckerworddialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerworddialogHPP
