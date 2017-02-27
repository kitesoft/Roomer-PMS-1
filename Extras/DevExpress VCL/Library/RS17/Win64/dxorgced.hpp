// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxorgced.pas' rev: 24.00 (Win64)

#ifndef DxorgcedHPP
#define DxorgcedHPP

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
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxorgced
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmEChartEditor;
class PASCALIMPLEMENTATION TfrmEChartEditor : public Dxorgchr::TdxOrgChartCustomCustomizeForm
{
	typedef Dxorgchr::TdxOrgChartCustomCustomizeForm inherited;
	
__published:
	Vcl::Stdctrls::TComboBox* AlignEdit;
	Vcl::Stdctrls::TButton* CancelButton;
	Vcl::Buttons::TSpeedButton* CInsButton;
	Vcl::Stdctrls::TComboBox* ColorEdit;
	Vcl::Buttons::TSpeedButton* DelButton;
	Vcl::Stdctrls::TEdit* HeightEdit;
	Vcl::Stdctrls::TComboBox* IAEdit;
	Vcl::Stdctrls::TEdit* IIEdit;
	Vcl::Buttons::TSpeedButton* InsButton;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TLabel* Label3;
	Vcl::Stdctrls::TLabel* Label4;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Stdctrls::TLabel* Label6;
	Vcl::Stdctrls::TLabel* Label7;
	Vcl::Stdctrls::TLabel* Label8;
	Vcl::Buttons::TSpeedButton* MultiButton;
	Vcl::Stdctrls::TButton* OKButton;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Stdctrls::TGroupBox* PropBox;
	Vcl::Buttons::TSpeedButton* RotateButton;
	Vcl::Stdctrls::TComboBox* ShapeEdit;
	Dxorgchr::TdxOrgChart* Tree;
	Vcl::Stdctrls::TGroupBox* TreeBox;
	Vcl::Stdctrls::TEdit* TTEdit;
	Vcl::Stdctrls::TEdit* WidthEdit;
	Vcl::Buttons::TSpeedButton* ZoomButton;
	Vcl::Buttons::TSpeedButton* btnAntialiasing;
	void __fastcall AlignEditClick(System::TObject* Sender);
	void __fastcall AlignEditExit(System::TObject* Sender);
	void __fastcall CInsButtonClick(System::TObject* Sender);
	void __fastcall ColorEditClick(System::TObject* Sender);
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
	void __fastcall SetColors(const System::UnicodeString S);
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
	/* TCustomForm.Create */ inline __fastcall virtual TfrmEChartEditor(System::Classes::TComponent* AOwner) : Dxorgchr::TdxOrgChartCustomCustomizeForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmEChartEditor(System::Classes::TComponent* AOwner, int Dummy) : Dxorgchr::TdxOrgChartCustomCustomizeForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmEChartEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmEChartEditor(HWND ParentWindow) : Dxorgchr::TdxOrgChartCustomCustomizeForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxorgced */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXORGCED)
using namespace Dxorgced;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxorgcedHPP
