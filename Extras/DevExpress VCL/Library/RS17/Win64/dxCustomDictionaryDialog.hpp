// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCustomDictionaryDialog.pas' rev: 24.00 (Win64)

#ifndef DxcustomdictionarydialogHPP
#define DxcustomdictionarydialogHPP

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

//-- user supplied -----------------------------------------------------------

namespace Dxcustomdictionarydialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxCustomDictionaryForm;
class PASCALIMPLEMENTATION TdxCustomDictionaryForm : public Dxspellcheckerbaseform::TfmSpellCheckerBaseForm
{
	typedef Dxspellcheckerbaseform::TfmSpellCheckerBaseForm inherited;
	
private:
	Dxspellchecker::TdxUserSpellCheckerDictionary* FDictionary;
	
protected:
	virtual void __fastcall ApplyChanges(void);
	virtual void __fastcall Localize(void);
	__property Dxspellchecker::TdxUserSpellCheckerDictionary* Dictionary = {read=FDictionary};
	
public:
	__fastcall virtual TdxCustomDictionaryForm(Dxspellchecker::TdxUserSpellCheckerDictionary* ADictionary);
	virtual int __fastcall ShowModal(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxCustomDictionaryForm(System::Classes::TComponent* AOwner) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxCustomDictionaryForm(System::Classes::TComponent* AOwner, int Dummy) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxCustomDictionaryForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomDictionaryForm(HWND ParentWindow) : Dxspellcheckerbaseform::TfmSpellCheckerBaseForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxCustomDictionaryFormClass;

class DELPHICLASS TfmCustomDictionaryForm;
class PASCALIMPLEMENTATION TfmCustomDictionaryForm : public TdxCustomDictionaryForm
{
	typedef TdxCustomDictionaryForm inherited;
	
__published:
	Cxmemo::TcxMemo* meDictionary;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	void __fastcall meDictionaryPropertiesChange(System::TObject* Sender);
	
protected:
	virtual void __fastcall ApplyChanges(void);
	virtual void __fastcall Localize(void);
	
public:
	__fastcall virtual TfmCustomDictionaryForm(Dxspellchecker::TdxUserSpellCheckerDictionary* ADictionary);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmCustomDictionaryForm(System::Classes::TComponent* AOwner) : TdxCustomDictionaryForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmCustomDictionaryForm(System::Classes::TComponent* AOwner, int Dummy) : TdxCustomDictionaryForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmCustomDictionaryForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmCustomDictionaryForm(HWND ParentWindow) : TdxCustomDictionaryForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxcustomdictionarydialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCUSTOMDICTIONARYDIALOG)
using namespace Dxcustomdictionarydialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcustomdictionarydialogHPP
