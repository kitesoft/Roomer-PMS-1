// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxMaskEditTextEditor.pas' rev: 24.00 (Win32)

#ifndef CxmaskedittexteditorHPP
#define CxmaskedittexteditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxmaskedittexteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxMaskEditTextEditorDlg;
class PASCALIMPLEMENTATION TcxMaskEditTextEditorDlg : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Cxmaskedit::TcxMaskEdit* cxMaskEdit1;
	Vcl::Stdctrls::TLabel* Label3;
	Vcl::Extctrls::TBevel* Bevel1;
	Vcl::Stdctrls::TButton* cxButton2;
	Vcl::Stdctrls::TButton* cxButton1;
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall cxButton1Click(System::TObject* Sender);
	void __fastcall cxButton2Click(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	Cxmaskedit::TcxCustomMaskEdit* FMaskEdit;
	
public:
	__property Cxmaskedit::TcxCustomMaskEdit* MaskEdit = {read=FMaskEdit, write=FMaskEdit};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxMaskEditTextEditorDlg(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxMaskEditTextEditorDlg(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxMaskEditTextEditorDlg(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxMaskEditTextEditorDlg(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxMaskEditTextEditorDlg* cxMaskEditTextEditorDlg;
}	/* namespace Cxmaskedittexteditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXMASKEDITTEXTEDITOR)
using namespace Cxmaskedittexteditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxmaskedittexteditorHPP
