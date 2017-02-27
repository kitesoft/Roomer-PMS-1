// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarItemEd.pas' rev: 24.00 (Win64)

#ifndef DxbaritemedHPP
#define DxbaritemedHPP

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
#include <dxBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbaritemed
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarItemAddEditor;
class PASCALIMPLEMENTATION TdxBarItemAddEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TLabel* LName;
	Vcl::Stdctrls::TLabel* LCaption;
	Vcl::Stdctrls::TLabel* LType;
	Vcl::Stdctrls::TLabel* LCategory;
	Vcl::Stdctrls::TEdit* Edit1;
	Vcl::Stdctrls::TEdit* Edit2;
	Vcl::Stdctrls::TComboBox* ComboBox1;
	Vcl::Stdctrls::TComboBox* ComboBox2;
	Vcl::Stdctrls::TButton* BOk;
	Vcl::Stdctrls::TButton* BCancel;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ComboBox1Click(System::TObject* Sender);
	void __fastcall BOkClick(System::TObject* Sender);
	
private:
	Dxbar::TdxBarItem* ABarItem;
	Dxbar::TdxBarManager* BarManager;
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxBarItemAddEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBarItemAddEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxBarItemAddEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarItemAddEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Dxbar::TdxBarItem* __fastcall dxBarItemAddEditor(Dxbar::TdxBarManager* ABarManager, int ACategoryIndex);
}	/* namespace Dxbaritemed */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARITEMED)
using namespace Dxbaritemed;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbaritemedHPP
