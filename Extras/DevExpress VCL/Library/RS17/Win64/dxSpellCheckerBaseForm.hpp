// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpellCheckerBaseForm.pas' rev: 24.00 (Win64)

#ifndef DxspellcheckerbaseformHPP
#define DxspellcheckerbaseformHPP

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

//-- user supplied -----------------------------------------------------------

namespace Dxspellcheckerbaseform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmSpellCheckerBaseForm;
class PASCALIMPLEMENTATION TfmSpellCheckerBaseForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
protected:
	virtual void __fastcall Localize(void);
	
public:
	__fastcall TfmSpellCheckerBaseForm(void);
	virtual int __fastcall ShowModal(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmSpellCheckerBaseForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmSpellCheckerBaseForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmSpellCheckerBaseForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmSpellCheckerBaseForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxspellcheckerbaseform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPELLCHECKERBASEFORM)
using namespace Dxspellcheckerbaseform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspellcheckerbaseformHPP
