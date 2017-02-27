// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarNameEd.pas' rev: 24.00 (Win32)

#ifndef DxbarnameedHPP
#define DxbarnameedHPP

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
#include <dxBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarnameed
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarNameEd;
class PASCALIMPLEMENTATION TdxBarNameEd : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TEdit* EName;
	Vcl::Stdctrls::TButton* BOK;
	Vcl::Stdctrls::TButton* BCancel;
	Vcl::Stdctrls::TLabel* LName;
	void __fastcall ENameChange(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	
public:
	int Kind;
	Dxbar::TdxBarManager* BarManager;
	Dxbar::TdxBar* Bar;
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxBarNameEd(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBarNameEd(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxBarNameEd(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarNameEd(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxBarEditName(System::UnicodeString &AName, int Kind1, int Kind2, Dxbar::TdxBarManager* ABarManager, Dxbar::TdxBar* ABar);
}	/* namespace Dxbarnameed */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARNAMEED)
using namespace Dxbarnameed;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarnameedHPP
