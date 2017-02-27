// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmStlAdd.pas' rev: 24.00 (Win32)

#ifndef DxpsfmstladdHPP
#define DxpsfmstladdHPP

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
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmstladd
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmSelectStyleClass;
class PASCALIMPLEMENTATION TdxfmSelectStyleClass : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxgroupbox::TcxGroupBox* GroupBox1;
	Cxdropdownedit::TcxComboBox* cbxStyleTypes;
	Cxlabel::TcxLabel* Label1;
	void __fastcall Label1Click(System::TObject* Sender);
	void __fastcall cbxStyleTypesChange(System::TObject* Sender);
	
private:
	Dxpgsdlg::TdxPrintStyleClass FStyleClass;
	void __fastcall RefreshList(void);
	
public:
	__fastcall virtual TdxfmSelectStyleClass(System::Classes::TComponent* AOwner);
	Dxpgsdlg::TdxPrintStyleClass __fastcall Execute(const System::Types::TPoint &Pt);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmSelectStyleClass(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxfmSelectStyleClass(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmSelectStyleClass(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Dxpgsdlg::TdxPrintStyleClass __fastcall dxSelectStyleClass(const System::Types::TPoint &Pt);
}	/* namespace Dxpsfmstladd */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMSTLADD)
using namespace Dxpsfmstladd;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmstladdHPP
