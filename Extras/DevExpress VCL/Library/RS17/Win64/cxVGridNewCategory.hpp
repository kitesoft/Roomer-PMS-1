// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVGridNewCategory.pas' rev: 24.00 (Win64)

#ifndef CxvgridnewcategoryHPP
#define CxvgridnewcategoryHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvgridnewcategory
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmCreateCategory;
class PASCALIMPLEMENTATION TfmCreateCategory : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TLabel* lbCaption;
	Vcl::Extctrls::TBevel* Bevel;
	Cxbuttons::TcxButton* btOK;
	Cxbuttons::TcxButton* btCancel;
	Cxtextedit::TcxTextEdit* edCaption;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall edCaptionPropertiesChange(System::TObject* Sender);
	
public:
	void __fastcall Prepare(Vcl::Forms::TForm* AOwnerForm, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmCreateCategory(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmCreateCategory(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmCreateCategory(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmCreateCategory(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall cxShowNewCategoryForm(Vcl::Forms::TForm* AOwnerForm, System::UnicodeString &ACaption, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0));
}	/* namespace Cxvgridnewcategory */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVGRIDNEWCATEGORY)
using namespace Cxvgridnewcategory;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvgridnewcategoryHPP
