// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSpinImagePropEditor.pas' rev: 24.00 (Win32)

#ifndef DxspinimagepropeditorHPP
#define DxspinimagepropeditorHPP

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
#include <dximctrl.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxspinimagepropeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmSpinImagePropEditor;
class PASCALIMPLEMENTATION TfrmSpinImagePropEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Stdctrls::TButton* bAdd;
	Vcl::Stdctrls::TButton* bInsert;
	Vcl::Stdctrls::TButton* bDelete;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Stdctrls::TEdit* Edit1;
	Dximctrl::TdxImageListBox* ListBox;
	Vcl::Stdctrls::TButton* bUp;
	Vcl::Stdctrls::TButton* bDown;
	Vcl::Stdctrls::TLabel* LabelHint;
	Vcl::Stdctrls::TButton* bClear;
	Vcl::Stdctrls::TLabel* LabelValue;
	Vcl::Stdctrls::TLabel* LabelImageIndex;
	Vcl::Stdctrls::TEdit* Edit2;
	Vcl::Stdctrls::TButton* BOk;
	Vcl::Stdctrls::TButton* bCancel;
	Vcl::Stdctrls::TButton* bHelp;
	Dximctrl::TdxSpinImage* SpinImage;
	Vcl::Stdctrls::TMemo* Edit3;
	void __fastcall Edit2KeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall Edit2Exit(System::TObject* Sender);
	void __fastcall bAddClick(System::TObject* Sender);
	void __fastcall bInsertClick(System::TObject* Sender);
	void __fastcall bDeleteClick(System::TObject* Sender);
	void __fastcall Edit1Exit(System::TObject* Sender);
	void __fastcall ListBoxClick(System::TObject* Sender);
	void __fastcall bUpClick(System::TObject* Sender);
	void __fastcall bDownClick(System::TObject* Sender);
	void __fastcall ListBoxDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall ListBoxDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall bClearClick(System::TObject* Sender);
	void __fastcall Edit3Exit(System::TObject* Sender);
	void __fastcall SpinImageChange(System::TObject* Sender, int ItemIndex);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmSpinImagePropEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmSpinImagePropEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmSpinImagePropEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmSpinImagePropEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ExpressSpinImageItemsPropEditor(Dximctrl::TdxCustomSpinImage* Control);
}	/* namespace Dxspinimagepropeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSPINIMAGEPROPEDITOR)
using namespace Dxspinimagepropeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxspinimagepropeditorHPP
