// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRegEd.pas' rev: 24.00 (Win64)

#ifndef DxregedHPP
#define DxregedHPP

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
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxreged
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmdxLibREgPathEditor;
class PASCALIMPLEMENTATION TfrmdxLibREgPathEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel;
	Vcl::Comctrls::TTreeView* TreeView;
	Vcl::Stdctrls::TButton* bOk;
	Vcl::Stdctrls::TButton* bCancel;
	Vcl::Stdctrls::TButton* bNew;
	Vcl::Controls::TImageList* ImageList;
	Vcl::Stdctrls::TLabel* lbRegistry;
	Vcl::Stdctrls::TButton* bDelete;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall TreeViewChange(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall bNewClick(System::TObject* Sender);
	void __fastcall TreeViewGetImageIndex(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall TreeViewGetSelectedIndex(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall TreeViewExpanded(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall TreeViewCollapsed(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall bDeleteClick(System::TObject* Sender);
	
private:
	System::Win::Registry::TRegistry* reg;
	System::UnicodeString __fastcall GetFullText(Vcl::Comctrls::TTreeNode* Node);
	HIDESBASE MESSAGE void __fastcall WMGetMinMaxInfo(Winapi::Messages::TWMGetMinMaxInfo &Message);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmdxLibREgPathEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmdxLibREgPathEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmdxLibREgPathEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmdxLibREgPathEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxGetRegistryPath(System::UnicodeString &APath);
}	/* namespace Dxreged */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXREGED)
using namespace Dxreged;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxregedHPP
