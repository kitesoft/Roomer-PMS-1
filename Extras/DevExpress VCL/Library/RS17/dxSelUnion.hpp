// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSelUnion.pas' rev: 24.00 (Win32)

#ifndef DxselunionHPP
#define DxselunionHPP

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
#include <dxflchrt.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxselunion
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TFSelectUnion;
class PASCALIMPLEMENTATION TFSelectUnion : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* Button1;
	Vcl::Stdctrls::TButton* Button2;
	Vcl::Stdctrls::TListBox* lbUnions;
	void __fastcall FormCreate(System::TObject* Sender);
	
public:
	void __fastcall PopulateList(Dxflchrt::TdxFlowChart* Chart, Dxflchrt::TdxFcObject* Obj);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TFSelectUnion(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TFSelectUnion(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TFSelectUnion(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TFSelectUnion(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Dxflchrt::TdxFcObject* __fastcall SelectUnion(Dxflchrt::TdxFlowChart* Chart, Dxflchrt::TdxFcObject* Obj);
}	/* namespace Dxselunion */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSELUNION)
using namespace Dxselunion;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxselunionHPP
