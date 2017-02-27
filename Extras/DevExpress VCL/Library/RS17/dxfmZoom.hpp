// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxfmZoom.pas' rev: 24.00 (Win32)

#ifndef DxfmzoomHPP
#define DxfmzoomHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxPreVw.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfmzoom
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmZoom;
class PASCALIMPLEMENTATION TfmZoom : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxgroupbox::TcxGroupBox* gbxPreview;
	Vcl::Extctrls::TBevel* bvlFontPreviewHolder;
	Cxgroupbox::TcxGroupBox* gbxZoomTo;
	Cxradiogroup::TcxRadioButton* rbtn500;
	Cxradiogroup::TcxRadioButton* rbtn200;
	Cxradiogroup::TcxRadioButton* rbtn150;
	Cxradiogroup::TcxRadioButton* rbtn100;
	Cxradiogroup::TcxRadioButton* rbtn75;
	Cxradiogroup::TcxRadioButton* rbtn50;
	Cxradiogroup::TcxRadioButton* rbtn10;
	Cxradiogroup::TcxRadioButton* rbtn25;
	Cxradiogroup::TcxRadioButton* rbtnTwoPages;
	Cxradiogroup::TcxRadioButton* rbtnWholePage;
	Cxradiogroup::TcxRadioButton* rbtnPageWidth;
	Cxradiogroup::TcxRadioButton* rbtnFourPages;
	Cxradiogroup::TcxRadioButton* rbtnManyPages;
	Cxlabel::TcxLabel* lblPercent;
	Cxlabel::TcxLabel* stxtFontPreview;
	Cxspinedit::TcxSpinEdit* sePercent;
	Cxbuttons::TcxButton* btnManyPages;
	Cxgraphics::TcxImageList* ilStub;
	Vcl::Extctrls::TPaintBox* pbPreview;
	Cxgraphics::TcxImageList* ilMonitor;
	void __fastcall btnManyPagesClick(System::TObject* Sender);
	void __fastcall lblPercentClick(System::TObject* Sender);
	void __fastcall PercentChange(System::TObject* Sender);
	void __fastcall PercentExit(System::TObject* Sender);
	void __fastcall PreviewPaint(System::TObject* Sender);
	void __fastcall rbtnClick(System::TObject* Sender);
	void __fastcall sePercentKeyPress(System::TObject* Sender, System::WideChar &Key);
	
private:
	bool FModified;
	Vcl::Controls::TCustomControl* FpnlFontPreview;
	Dxprevw::TdxPreview* FPreview;
	System::Types::TPoint FPreviewOwnerSize;
	int FUpdateCount;
	void __fastcall FontPreviewPaint(System::TObject* Sender);
	void __fastcall PercentsChanged(int ANewValue);
	void __fastcall SetZoomFactor(int Value);
	void __fastcall UpdateZoomRadioBoxes(void);
	
protected:
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall InitControls(void);
	void __fastcall InitPreview(Dxprevw::TdxPreview* APreview);
	virtual void __fastcall LoadStrings(void);
	void __fastcall UpdateControlsState(void);
	
public:
	__fastcall virtual TfmZoom(System::Classes::TComponent* AOwner);
	bool __fastcall Execute(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmZoom(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmZoom(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmZoom(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxZoomDlg(Dxprevw::TdxPreview* APreview);
}	/* namespace Dxfmzoom */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFMZOOM)
using namespace Dxfmzoom;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfmzoomHPP
