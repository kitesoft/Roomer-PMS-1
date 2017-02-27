// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarDBCheckLinksEd.pas' rev: 24.00 (Win32)

#ifndef DxbardbchecklinksedHPP
#define DxbardbchecklinksedHPP

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
#include <dxBarDBNav.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbardbchecklinksed
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarDBCheckLinksEditor;
class PASCALIMPLEMENTATION TdxBarDBCheckLinksEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TGroupBox* GroupBox1;
	Vcl::Stdctrls::TListBox* ListBox;
	Vcl::Stdctrls::TGroupBox* GroupBox2;
	Vcl::Stdctrls::TComboBox* ComboBox;
	Vcl::Stdctrls::TCheckBox* CheckBox1;
	Vcl::Stdctrls::TCheckBox* CheckBox4;
	Vcl::Stdctrls::TCheckBox* CheckBox2;
	Vcl::Stdctrls::TCheckBox* CheckBox5;
	Vcl::Stdctrls::TCheckBox* CheckBox6;
	Vcl::Stdctrls::TCheckBox* CheckBox3;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TButton* Button3;
	Vcl::Stdctrls::TButton* Button4;
	Vcl::Stdctrls::TButton* Button1;
	Vcl::Stdctrls::TButton* Button2;
	Vcl::Extctrls::TBevel* Bevel1;
	void __fastcall Button3Click(System::TObject* Sender);
	void __fastcall Button4Click(System::TObject* Sender);
	void __fastcall ListBoxClick(System::TObject* Sender);
	void __fastcall Button1Click(System::TObject* Sender);
	void __fastcall Button2Click(System::TObject* Sender);
	
private:
	Dxbardbnav::TdxBarDBNavigator* FBarDBNavigator;
	Dxbardbnav::TdxBarDBCheckLink* SelectedDBCheckLink;
	void __fastcall RefreshItems(int OldIndex);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxBarDBCheckLinksEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBarDBCheckLinksEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxBarDBCheckLinksEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarDBCheckLinksEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxBarDBCheckLinksEditor(Dxbardbnav::TdxBarDBNavigator* ABarDBNavigator);
}	/* namespace Dxbardbchecklinksed */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARDBCHECKLINKSED)
using namespace Dxbardbchecklinksed;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbardbchecklinksedHPP
