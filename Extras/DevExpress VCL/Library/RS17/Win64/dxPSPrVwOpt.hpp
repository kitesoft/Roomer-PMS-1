// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPrVwOpt.pas' rev: 24.00 (Win64)

#ifndef DxpsprvwoptHPP
#define DxpsprvwoptHPP

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
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxPreVw.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsprvwopt
{
//-- type declarations -------------------------------------------------------
struct TdxPreviewOptionsDlgData;
typedef TdxPreviewOptionsDlgData *PdxPreviewOptionsDlgData;

struct DECLSPEC_DRECORD TdxPreviewOptionsDlgData
{
public:
	System::Uitypes::TColor MarginColor;
	Dxprnpg::TdxMeasurementUnits MeasurementUnits;
	bool ShowMarginsHintWhileDragging;
	bool ShowMarginHints;
	bool ShowMargins;
	bool ZoomOnMouseRoll;
	int ZoomStep;
};


class DELPHICLASS TdxfmOptions;
class PASCALIMPLEMENTATION TdxfmOptions : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnOk;
	Cxcolorcombobox::TcxColorComboBox* cbxMarginColor;
	Cxdropdownedit::TcxComboBox* cbxMeasurementUnits;
	Cxcheckbox::TcxCheckBox* chbxShowMargins;
	Cxcheckbox::TcxCheckBox* chbxShowMarginsHints;
	Cxcheckbox::TcxCheckBox* chbxShowMarginsHintsWhileDragging;
	Cxcheckbox::TcxCheckBox* chbxZoomOnRoll;
	Cxgroupbox::TcxGroupBox* gbxMarginsColor;
	Cxgroupbox::TcxGroupBox* gbxMeasurementUnits;
	Cxgroupbox::TcxGroupBox* gbxShow;
	Cxgroupbox::TcxGroupBox* gbxZoomOpt;
	Cxlabel::TcxLabel* lblMarginsColor;
	Cxlabel::TcxLabel* lblMeasurementUnits;
	Cxlabel::TcxLabel* lblZoomStep;
	Cxpc::TcxPageControl* pcMain;
	Cxspinedit::TcxSpinEdit* seZoomStep;
	Cxpc::TcxTabSheet* tshGeneral;
	void __fastcall FormChanged(System::TObject* Sender);
	void __fastcall lblMarginsColorClick(System::TObject* Sender);
	void __fastcall btnHelpClick(System::TObject* Sender);
	
private:
	bool FControlsUpdating;
	TdxPreviewOptionsDlgData FData;
	bool FModified;
	void __fastcall CheckModified(void);
	void __fastcall LoadStrings(void);
	void __fastcall StartSettings(void);
	void __fastcall UpdateControlsState(void);
	
public:
	__fastcall virtual TdxfmOptions(System::Classes::TComponent* AOwner);
	bool __fastcall Execute(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmOptions(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxfmOptions(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmOptions(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowPSPreviewOptionsDlg(TdxPreviewOptionsDlgData &AData);
}	/* namespace Dxpsprvwopt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPRVWOPT)
using namespace Dxpsprvwopt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsprvwoptHPP
