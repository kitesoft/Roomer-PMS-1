// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerExceptionsFrame.pas' rev: 24.00 (Win32)

#ifndef DxspellcheckerexceptionsframeHPP
#define DxspellcheckerexceptionsframeHPP

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
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <dxSpellChecker.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerexceptionsframe
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TfrmSpellCheckerCandidateEvent)(System::WideString &S, bool &AResult);

class DELPHICLASS TfrmSpellCheckerExceptions;
class PASCALIMPLEMENTATION TfrmSpellCheckerExceptions : public Vcl::Forms::TFrame
{
	typedef Vcl::Forms::TFrame inherited;
	
__published:
	Cxlistbox::TcxListBox* lbxList;
	Cxtextedit::TcxTextEdit* teCandidate;
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnDelete;
	Cxcheckbox::TcxCheckBox* cbAutoInclude;
	void __fastcall teCandidatePropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall btnAddClick(System::TObject* Sender);
	void __fastcall btnDeleteClick(System::TObject* Sender);
	void __fastcall lbxListClick(System::TObject* Sender);
	void __fastcall teCandidateKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	Dxspellchecker::TdxSpellCheckerAutoCorrectExceptions* FExceptions;
	TfrmSpellCheckerCandidateEvent FOnCandidateExist;
	TfrmSpellCheckerCandidateEvent FOnCandidateValidate;
	bool __fastcall DoCandidateExist(System::WideString &S);
	bool __fastcall DoCandidateValidate(System::WideString &S);
	int __fastcall GetCandidateIndex(void);
	void __fastcall Initialize(void);
	void __fastcall Localize(void);
	void __fastcall PopulateList(void);
	void __fastcall SelectItem(void);
	void __fastcall UpdateButtonsState(void);
	
public:
	__fastcall virtual TfrmSpellCheckerExceptions(System::Classes::TComponent* AOwner, Dxspellchecker::TdxSpellCheckerAutoCorrectExceptions* AExceptions);
	__property Dxspellchecker::TdxSpellCheckerAutoCorrectExceptions* Exceptions = {read=FExceptions};
	__property TfrmSpellCheckerCandidateEvent OnCandidateExist = {read=FOnCandidateExist, write=FOnCandidateExist};
	__property TfrmSpellCheckerCandidateEvent OnCandidateValidate = {read=FOnCandidateValidate, write=FOnCandidateValidate};
public:
	/* TCustomFrame.Create */ inline __fastcall virtual TfrmSpellCheckerExceptions(System::Classes::TComponent* AOwner) : Vcl::Forms::TFrame(AOwner) { }
	
public:
	/* TScrollingWinControl.Destroy */ inline __fastcall virtual ~TfrmSpellCheckerExceptions(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmSpellCheckerExceptions(HWND ParentWindow) : Vcl::Forms::TFrame(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckerexceptionsframe */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKEREXCEPTIONSFRAME)
using namespace Dxspellcheckerexceptionsframe;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerexceptionsframeHPP
