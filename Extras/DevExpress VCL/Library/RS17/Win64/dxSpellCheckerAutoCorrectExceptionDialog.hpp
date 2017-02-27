// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerAutoCorrectExceptionDialog.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckerautocorrectexceptiondialogHPP
#define DxspellcheckerautocorrectexceptiondialogHPP

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
#include <dxSpellCheckerBaseForm.hpp>	// Pascal unit
#include <dxSpellChecker.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <dxSpellCheckerAutoCorrectOptionsDialog.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerautocorrectexceptiondialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmSpellCheckerAutoCorrectExceptionsForm;
class PASCALIMPLEMENTATION TfmSpellCheckerAutoCorrectExceptionsForm : public Dxspellcheckerautocorrectoptionsdialog::TdxCustomSpellCheckerAutoCorrectForm
{
	typedef Dxspellcheckerautocorrectoptionsdialog::TdxCustomSpellCheckerAutoCorrectForm inherited;
	
__published:
	Cxgroupbox::TcxGroupBox* gbFirstLetter;
	Cxgroupbox::TcxGroupBox* gbInitialCaps;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnClose;
	
private:
	Vcl::Forms::TCustomFrame* FFirstLetterExceptionsFrame;
	Vcl::Forms::TCustomFrame* FInitialCapsExceptionsFrame;
	bool __fastcall IsValidCandidate(const System::WideString S, int AMinLength = 0x1, const System::WideChar APossibleLastChar = (System::WideChar)(0x0));
	
protected:
	virtual void __fastcall ApplyChanges(void);
	void __fastcall FirstLetterExceptionsExistHandler(System::WideString &S, bool &AResult);
	void __fastcall FirstLetterExceptionsValidateHandler(System::WideString &S, bool &AResult);
	void __fastcall InitialCapsExceptionsValidateHandler(System::WideString &S, bool &AResult);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall Localize(void);
	
public:
	__fastcall virtual TfmSpellCheckerAutoCorrectExceptionsForm(Dxspellchecker::TdxSpellCheckerAutoCorrectOptions* AOptions);
	__fastcall virtual ~TfmSpellCheckerAutoCorrectExceptionsForm(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmSpellCheckerAutoCorrectExceptionsForm(System::Classes::TComponent* AOwner) : Dxspellcheckerautocorrectoptionsdialog::TdxCustomSpellCheckerAutoCorrectForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmSpellCheckerAutoCorrectExceptionsForm(System::Classes::TComponent* AOwner, int Dummy) : Dxspellcheckerautocorrectoptionsdialog::TdxCustomSpellCheckerAutoCorrectForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmSpellCheckerAutoCorrectExceptionsForm(HWND ParentWindow) : Dxspellcheckerautocorrectoptionsdialog::TdxCustomSpellCheckerAutoCorrectForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckerautocorrectexceptiondialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERAUTOCORRECTEXCEPTIONDIALOG)
using namespace Dxspellcheckerautocorrectexceptiondialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerautocorrectexceptiondialogHPP
