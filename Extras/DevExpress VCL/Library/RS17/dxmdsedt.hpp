// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxmdsedt.pas' rev: 24.00 (Win32)

#ifndef DxmdsedtHPP
#define DxmdsedtHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxmdaset.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxmdsedt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmdxMemDataEditor;
class PASCALIMPLEMENTATION TfrmdxMemDataEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	Vcl::Stdctrls::TListBox* ListBox;
	Vcl::Extctrls::TPanel* pnButtons;
	Vcl::Stdctrls::TButton* BAdd;
	Vcl::Stdctrls::TButton* BDelete;
	Vcl::Stdctrls::TButton* BUp;
	Vcl::Stdctrls::TButton* BDown;
	Vcl::Menus::TPopupMenu* pmColumns;
	Vcl::Menus::TMenuItem* miShowButtons;
	void __fastcall ListBoxClick(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall BAddClick(System::TObject* Sender);
	void __fastcall BDeleteClick(System::TObject* Sender);
	void __fastcall miUpClick(System::TObject* Sender);
	void __fastcall miDownClick(System::TObject* Sender);
	void __fastcall miSelectAllClick(System::TObject* Sender);
	void __fastcall miShowButtonsClick(System::TObject* Sender);
	void __fastcall ListBoxDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall ListBoxStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall ListBoxEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall ListBoxDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall CreateControls(void);
	void __fastcall MoveField(int ADirection);
	void __fastcall GetSelection(System::Classes::TList* AList);
	void __fastcall SetSelection(System::Classes::TList* AList);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	
public:
	Dxmdaset::TdxMemData* Data;
	Designintf::_di_IDesigner FormDesigner;
	void __fastcall FillList(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmdxMemDataEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmdxMemDataEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmdxMemDataEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmdxMemDataEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ShowMemDataFieldEditor(Dxmdaset::TdxMemData* AData, Designintf::_di_IDesigner AFormDesigner);
}	/* namespace Dxmdsedt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXMDSEDT)
using namespace Dxmdsedt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxmdsedtHPP
