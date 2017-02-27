// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRgKeya.pas' rev: 24.00 (Win64)

#ifndef DxrgkeyaHPP
#define DxrgkeyaHPP

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

//-- user supplied -----------------------------------------------------------

namespace Dxrgkeya
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmdxAddNewRegKey;
class PASCALIMPLEMENTATION TfrmdxAddNewRegKey : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TEdit* Edit;
	Vcl::Stdctrls::TLabel* lblName;
	Vcl::Stdctrls::TButton* bOk;
	Vcl::Stdctrls::TButton* bCancel;
	void __fastcall EditChange(System::TObject* Sender);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmdxAddNewRegKey(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmdxAddNewRegKey(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmdxAddNewRegKey(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmdxAddNewRegKey(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::UnicodeString __fastcall dxGetNewRegistryKey(void);
}	/* namespace Dxrgkeya */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRGKEYA)
using namespace Dxrgkeya;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxrgkeyaHPP
