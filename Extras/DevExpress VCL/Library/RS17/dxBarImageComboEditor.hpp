// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarImageComboEditor.pas' rev: 24.00 (Win32)

#ifndef DxbarimagecomboeditorHPP
#define DxbarimagecomboeditorHPP

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
#include <Vcl.Grids.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxBarExtItems.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarimagecomboeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarImageComboEditorForm;
class PASCALIMPLEMENTATION TdxBarImageComboEditorForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* ButtonOk;
	Vcl::Stdctrls::TButton* ButtonCancel;
	Vcl::Stdctrls::TButton* ButtonAdd;
	Vcl::Stdctrls::TButton* ButtonDelete;
	Vcl::Grids::TStringGrid* Grid;
	Vcl::Stdctrls::TButton* ButtonInsert;
	void __fastcall ButtonAddClick(System::TObject* Sender);
	void __fastcall ButtonInsertClick(System::TObject* Sender);
	void __fastcall ButtonDeleteClick(System::TObject* Sender);
	void __fastcall GridDrawCell(System::TObject* Sender, int Col, int Row, const System::Types::TRect &Rect, Vcl::Grids::TGridDrawState State);
	void __fastcall GridSelectCell(System::TObject* Sender, int Col, int Row, bool &CanSelect);
	void __fastcall GridSetEditText(System::TObject* Sender, int ACol, int ARow, const System::UnicodeString Value);
	void __fastcall GridGetEditText(System::TObject* Sender, int ACol, int ARow, System::UnicodeString &Value);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall GridKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	Dxbarextitems::TdxBarImageCombo* FCombo;
	System::UnicodeString FPrevCellText;
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxBarImageComboEditorForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBarImageComboEditorForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxBarImageComboEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarImageComboEditorForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxBarImageComboEdit(Dxbarextitems::TdxBarImageCombo* ACombo);
}	/* namespace Dxbarimagecomboeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARIMAGECOMBOEDITOR)
using namespace Dxbarimagecomboeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarimagecomboeditorHPP
