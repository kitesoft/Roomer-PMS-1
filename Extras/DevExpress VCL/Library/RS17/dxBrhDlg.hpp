// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBrhDlg.pas' rev: 24.00 (Win32)

#ifndef DxbrhdlgHPP
#define DxbrhdlgHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbrhdlg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBrushDlg;
class PASCALIMPLEMENTATION TdxBrushDlg : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnOK;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxgroupbox::TcxGroupBox* GroupBox;
	Cxlabel::TcxLabel* lblColor;
	Cxlabel::TcxLabel* lblStyle;
	Vcl::Extctrls::TBevel* bvlStyleHolder;
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall ccbxStyleChange(System::TObject* Sender);
	void __fastcall lblClick(System::TObject* Sender);
	
private:
	Vcl::Graphics::TBrush* FBrush;
	Cxdropdownedit::TcxCustomComboBox* FcbxStyle;
	bool FLockControls;
	bool FModified;
	void __fastcall BrushChanged(System::TObject* Sender);
	void __fastcall SetBrush(Vcl::Graphics::TBrush* Value);
	void __fastcall CreateControls(void);
	void __fastcall CreateBrush(void);
	void __fastcall LoadStrings(void);
	
public:
	__fastcall virtual TdxBrushDlg(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBrushDlg(void);
	bool __fastcall Execute(void);
	__property Vcl::Graphics::TBrush* Brush = {read=FBrush, write=SetBrush};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBrushDlg(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBrushDlg(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall AreEqualBrushes(Vcl::Graphics::TBrush* const *ABrushes, const int ABrushes_Size);
extern PACKAGE bool __fastcall ChooseBrush(Vcl::Graphics::TBrush* ABrush);
}	/* namespace Dxbrhdlg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBRHDLG)
using namespace Dxbrhdlg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbrhdlgHPP
