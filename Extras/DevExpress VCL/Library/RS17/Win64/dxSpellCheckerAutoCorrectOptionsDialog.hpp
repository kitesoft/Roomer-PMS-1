// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerAutoCorrectOptionsDialog.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckerautocorrectoptionsdialogHPP
#define DxspellcheckerautocorrectoptionsdialogHPP

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
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerautocorrectoptionsdialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxCustomSpellCheckerAutoCorrectForm;
class PASCALIMPLEMENTATION TdxCustomSpellCheckerAutoCorrectForm : public Dxspellcheckerbaseform::TfmSpellCheckerBaseForm
{
	typedef Dxspellcheckerbaseform::TfmSpellCheckerBaseForm inherited;
	
private:
	Dxspellchecker::TdxSpellCheckerAutoCorrectOptions* FOptions;
	
protected:
	virtual void __fastcall ApplyChanges(void);
	__property Dxspellchecker::TdxSpellCheckerAutoCorrectOptions* Options = {read=FOptions};
	
public:
	__fastcall virtual TdxCustomSpellCheckerAutoCorrectForm(Dxspellchecker::TdxSpellCheckerAutoCorrectOptions* AOptions);
	virtual int __fastcall ShowModal(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxCustomSpellCheckerAutoCorrectForm(System::Classes::TComponent* AOwner) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxCustomSpellCheckerAutoCorrectForm(System::Classes::TComponent* AOwner, int Dummy) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxCustomSpellCheckerAutoCorrectForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomSpellCheckerAutoCorrectForm(HWND ParentWindow) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxCustomSpellCheckerAutoCorrectFormClass;

class DELPHICLASS TfmSpellCheckerAutoCorrectOptionsForm;
class PASCALIMPLEMENTATION TfmSpellCheckerAutoCorrectOptionsForm : public TdxCustomSpellCheckerAutoCorrectForm
{
	typedef TdxCustomSpellCheckerAutoCorrectForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	Cxgroupbox::TcxGroupBox* gbCapitalize;
	Cxcheckbox::TcxCheckBox* cbCorrectInitialCaps;
	Cxcheckbox::TcxCheckBox* cbCorrectSentenceCaps;
	Cxcheckbox::TcxCheckBox* cbCorrectCapsLock;
	Cxcheckbox::TcxCheckBox* cbReplaceTextAsYouType;
	Cxbuttons::TcxButton* btnExceptions;
	Cxgroupbox::TcxGroupBox* gbReplaceTextAsYouType;
	Cxlabel::TcxLabel* lbReplace;
	Cxlabel::TcxLabel* lbWith;
	Cxtextedit::TcxTextEdit* teReplace;
	Cxtextedit::TcxTextEdit* teWith;
	Cxlistview::TcxListView* lvReplacements;
	Cxbuttons::TcxButton* btnDelete;
	Cxbuttons::TcxButton* btnOperation;
	Cxcheckbox::TcxCheckBox* cbDisableCapsLock;
	Cxcheckbox::TcxCheckBox* cbAutomaticallyUseSuggestions;
	void __fastcall btnExceptionsClick(System::TObject* Sender);
	void __fastcall teReplacePropertiesChange(System::TObject* Sender);
	void __fastcall lvReplacementsClick(System::TObject* Sender);
	void __fastcall btnOperationClick(System::TObject* Sender);
	void __fastcall btnDeleteClick(System::TObject* Sender);
	
private:
	bool __fastcall IsAddOperation(void);
	void __fastcall PopulateReplaces(void);
	void __fastcall SelectItem(void);
	void __fastcall SynchronizeDialogWithOptions(void);
	void __fastcall SynchronizeOptionsWithDialog(void);
	void __fastcall UpdateButtonsState(void);
	void __fastcall UpdateButtonsCaption(void);
	
protected:
	virtual void __fastcall ApplyChanges(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall Localize(void);
	
public:
	__fastcall virtual TfmSpellCheckerAutoCorrectOptionsForm(Dxspellchecker::TdxSpellCheckerAutoCorrectOptions* AOptions);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmSpellCheckerAutoCorrectOptionsForm(System::Classes::TComponent* AOwner) : TdxCustomSpellCheckerAutoCorrectForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmSpellCheckerAutoCorrectOptionsForm(System::Classes::TComponent* AOwner, int Dummy) : TdxCustomSpellCheckerAutoCorrectForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmSpellCheckerAutoCorrectOptionsForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmSpellCheckerAutoCorrectOptionsForm(HWND ParentWindow) : TdxCustomSpellCheckerAutoCorrectForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckerautocorrectoptionsdialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERAUTOCORRECTOPTIONSDIALOG)
using namespace Dxspellcheckerautocorrectoptionsdialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerautocorrectoptionsdialogHPP
