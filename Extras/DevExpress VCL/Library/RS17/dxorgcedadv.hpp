// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxorgcedadv.pas' rev: 24.00 (Win32)

#ifndef DxorgcedadvHPP
#define DxorgcedadvHPP

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
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxorgchr.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxorgcedadv
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmOrgChartAdvEditor;
class PASCALIMPLEMENTATION TfrmOrgChartAdvEditor : public Dxorgchr::TdxOrgChartCustomCustomizeForm
{
	typedef Dxorgchr::TdxOrgChartCustomCustomizeForm inherited;
	
__published:
	Cxdropdownedit::TcxComboBox* AlignEdit;
	Cxcolorcombobox::TcxColorComboBox* ColorEdit;
	Cxgroupbox::TcxGroupBox* PropBox;
	Dxorgchr::TdxOrgChart* Tree;
	Cxgroupbox::TcxGroupBox* TreeBox;
	Cxlabel::TcxLabel* Label1;
	Cxlabel::TcxLabel* Label2;
	Cxlabel::TcxLabel* Label3;
	Cxlabel::TcxLabel* Label4;
	Cxlabel::TcxLabel* Label5;
	Cxlabel::TcxLabel* Label6;
	Cxlabel::TcxLabel* Label7;
	Cxlabel::TcxLabel* Label8;
	Cxbuttons::TcxButton* OKButton;
	Cxbuttons::TcxButton* CancelButton;
	Cxdropdownedit::TcxComboBox* IAEdit;
	Cxdropdownedit::TcxComboBox* ShapeEdit;
	Cxtextedit::TcxTextEdit* WidthEdit;
	Cxtextedit::TcxTextEdit* HeightEdit;
	Cxtextedit::TcxTextEdit* IIEdit;
	Cxtextedit::TcxTextEdit* TTEdit;
	Cxbuttons::TcxButton* btnAntialiasing;
	Cxbuttons::TcxButton* CInsButton;
	Cxbuttons::TcxButton* DelButton;
	Cxbuttons::TcxButton* InsButton;
	Cxbuttons::TcxButton* RotateButton;
	Cxbuttons::TcxButton* ZoomButton;
	Cxbuttons::TcxButton* MultiButton;
	void __fastcall AlignEditClick(System::TObject* Sender);
	void __fastcall AlignEditExit(System::TObject* Sender);
	void __fastcall CInsButtonClick(System::TObject* Sender);
	void __fastcall ColorEditExit(System::TObject* Sender);
	void __fastcall ColorEditKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall DelButtonClick(System::TObject* Sender);
	void __fastcall FixButtonClick(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall HeightEditExit(System::TObject* Sender);
	void __fastcall IAEditExit(System::TObject* Sender);
	void __fastcall IIEditExit(System::TObject* Sender);
	void __fastcall InsButtonClick(System::TObject* Sender);
	void __fastcall Label1Click(System::TObject* Sender);
	void __fastcall MultiButtonClick(System::TObject* Sender);
	void __fastcall RotateButtonClick(System::TObject* Sender);
	void __fastcall SetButtonClick(System::TObject* Sender);
	void __fastcall SetNodeInfo(Dxorgchr::TdxOcNode* Node);
	void __fastcall ShapeEditClick(System::TObject* Sender);
	void __fastcall ShapeEditExit(System::TObject* Sender);
	void __fastcall TreeChange(System::TObject* Sender, Dxorgchr::TdxOcNode* Node);
	void __fastcall TTEditExit(System::TObject* Sender);
	void __fastcall WidthEditExit(System::TObject* Sender);
	void __fastcall WidthEditKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ZoomButtonClick(System::TObject* Sender);
	void __fastcall btnAntialiasingClick(System::TObject* Sender);
	
protected:
	virtual Dxorgchr::TdxCustomOrgChart* __fastcall GetPreviewOrgChart(void);
	virtual void __fastcall PreparePreview(Dxorgchr::TdxCustomOrgChart* APreview, Dxorgchr::TdxCustomOrgChart* ASource);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmOrgChartAdvEditor(System::Classes::TComponent* AOwner) : Dxorgchr::TdxOrgChartCustomCustomizeForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmOrgChartAdvEditor(System::Classes::TComponent* AOwner, int Dummy) : Dxorgchr::TdxOrgChartCustomCustomizeForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmOrgChartAdvEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmOrgChartAdvEditor(HWND ParentWindow) : Dxorgchr::TdxOrgChartCustomCustomizeForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxorgcedadv */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXORGCEDADV)
using namespace Dxorgcedadv;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxorgcedadvHPP
