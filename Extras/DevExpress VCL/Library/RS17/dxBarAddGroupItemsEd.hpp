// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarAddGroupItemsEd.pas' rev: 24.00 (Win32)

#ifndef DxbaraddgroupitemsedHPP
#define DxbaraddgroupitemsedHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCommon.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbaraddgroupitemsed
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmAddGroupItems;
class PASCALIMPLEMENTATION TfrmAddGroupItems : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Extctrls::TPanel* Panel4;
	Vcl::Stdctrls::TListBox* lbGroupItems;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Stdctrls::TButton* btnOk;
	Vcl::Stdctrls::TButton* btnCancel;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall lbGroupItemsDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall lbGroupItemsMeasureItem(Vcl::Controls::TWinControl* Control, int Index, int &Height);
	
private:
	Dxbar::TdxBarGroup* FGroup;
	System::Classes::TWndMethod PrevListBoxWndProc;
	void __fastcall SetGroup(Dxbar::TdxBarGroup* Value);
	void __fastcall ListBoxWndProc(Winapi::Messages::TMessage &Message);
	
public:
	System::Classes::TList* GroupItems;
	__property Dxbar::TdxBarGroup* Group = {read=FGroup, write=SetGroup};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmAddGroupItems(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmAddGroupItems(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmAddGroupItems(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmAddGroupItems(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxBarChooseGroupItem(Dxbar::TdxBarGroup* AGroup, System::Classes::TList* AGroupItems);
}	/* namespace Dxbaraddgroupitemsed */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARADDGROUPITEMSED)
using namespace Dxbaraddgroupitemsed;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbaraddgroupitemsedHPP
