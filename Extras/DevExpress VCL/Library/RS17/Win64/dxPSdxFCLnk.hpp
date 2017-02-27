// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSdxFCLnk.pas' rev: 24.00 (Win64)

#ifndef DxpsdxfclnkHPP
#define DxpsdxfclnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxflchrt.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdxfclnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxFlowChartReportLink;
class PASCALIMPLEMENTATION TdxFlowChartReportLink : public Dxpsgraphiclnk::TCustomdxGraphicReportLink
{
	typedef Dxpsgraphiclnk::TCustomdxGraphicReportLink inherited;
	
private:
	bool FUseMetafile;
	Dxflchrt::TdxCustomFlowChart* __fastcall GetFlowChart(void);
	
protected:
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(void);
	virtual void __fastcall InitializeGraphicItem(Dxpscore::TdxReportCellGraphic* AnItem);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	
public:
	__fastcall virtual TdxFlowChartReportLink(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Dxflchrt::TdxCustomFlowChart* FlowChart = {read=GetFlowChart};
	
__published:
	__property BorderColor = {default=0};
	__property Color = {default=16777215};
	__property DrawBorder = {default=0};
	__property Transparent = {default=1};
	__property TransparentColor = {default=-16777211};
	__property bool UseMetafile = {read=FUseMetafile, write=FUseMetafile, default=1};
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxFlowChartReportLink(void) { }
	
};


class DELPHICLASS TdxFCReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxFCReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Vcl::Extctrls::TPanel* pnlPreview;
	Vcl::Controls::TImageList* ilFlowChart;
	Cxlabel::TcxLabel* lblPreview;
	Cxlabel::TcxLabel* lblColor;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxlabel::TcxLabel* stTransparent;
	Cxlabel::TcxLabel* stDrawBorder;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxLineColor;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxcheckbox::TcxCheckBox* chbxDrawBorder;
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall chbxDrawBorderClick(System::TObject* Sender);
	void __fastcall chbxTransparentClick(System::TObject* Sender);
	void __fastcall lblColorClick(System::TObject* Sender);
	void __fastcall stDrawBorderClick(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	
private:
	void __fastcall CreateControls(void);
	TdxFlowChartReportLink* __fastcall GetReportLink(void);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	
protected:
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall UpdatePreview(void);
	virtual void __fastcall UpdateControlsState(void);
	
public:
	Vcl::Controls::TCustomControl* FPreviewBox;
	__fastcall virtual TdxFCReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__property TdxFlowChartReportLink* ReportLink = {read=GetReportLink};
public:
	/* TStandarddxReportLinkDesignWindow.Destroy */ inline __fastcall virtual ~TdxFCReportLinkDesignWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxFCReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxFCReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


struct TdxFlowChartGetAsGraphicData;
typedef TdxFlowChartGetAsGraphicData *PdxFlowChartGetAsGraphicData;

struct DECLSPEC_DRECORD TdxFlowChartGetAsGraphicData
{
public:
	Dxflchrt::TdxCustomFlowChart* FlowChart;
	Vcl::Graphics::TGraphicClass GraphicClass;
	bool Transparent;
	System::Uitypes::TColor TransparentColor;
	bool Enhanced;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Vcl::Graphics::TGraphic* __fastcall dxGetFlowChartAsGraphic(const PdxFlowChartGetAsGraphicData AData);
}	/* namespace Dxpsdxfclnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDXFCLNK)
using namespace Dxpsdxfclnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdxfclnkHPP
