// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutEditForm.pas' rev: 24.00 (Win64)

#ifndef DxlayouteditformHPP
#define DxlayouteditformHPP

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
#include <dxLayoutControl.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxLayoutControlAdapters.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayouteditform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TLayoutEditForm;
class PASCALIMPLEMENTATION TLayoutEditForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Dxlayoutcontrol::TdxLayoutControl* LayoutControl;
	Dxlayoutcontainer::TdxLayoutItem* LayoutControlItemEdit;
	Dxlayoutcontainer::TdxLayoutGroup* dxLayoutControl1Group1;
	Vcl::Stdctrls::TButton* btnOK;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item2;
	Vcl::Stdctrls::TButton* btnCancel;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item3;
	Vcl::Stdctrls::TComboBox* cbDescriptions;
	
public:
	__fastcall virtual TLayoutEditForm(System::Classes::TComponent* AOwner);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TLayoutEditForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TLayoutEditForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TLayoutEditForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxLayoutControlSelectLookAndFeel(Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelClass &ALookAndFeelClass);
}	/* namespace Dxlayouteditform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTEDITFORM)
using namespace Dxlayouteditform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayouteditformHPP
