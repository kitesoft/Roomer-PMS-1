// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSdxOCLnk.pas' rev: 24.00 (Win32)

#ifndef DxpsdxoclnkHPP
#define DxpsdxoclnkHPP

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
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxorgchr.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGraphicLnk.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdxoclnk
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TCustomdxOrgChartReportLink;
class PASCALIMPLEMENTATION TCustomdxOrgChartReportLink : public Dxpsgraphiclnk::TCustomdxGraphicReportLink
{
	typedef Dxpsgraphiclnk::TCustomdxGraphicReportLink inherited;
	
private:
	bool FFullExpand;
	bool FUseMetafile;
	Dxorgchr::TdxOrgChart* __fastcall GetOrgChart(void);
	void __fastcall SetFullExpand(bool Value);
	
protected:
	virtual Vcl::Graphics::TGraphic* __fastcall GetGraphic(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall GetGraphicClass(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall InternalRestoreFromOriginal(void);
	__property Dxorgchr::TdxOrgChart* OrgChart = {read=GetOrgChart};
	
public:
	__fastcall virtual TCustomdxOrgChartReportLink(System::Classes::TComponent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Color = {default=16777215};
	__property bool FullExpand = {read=FFullExpand, write=SetFullExpand, default=0};
	__property Transparent = {default=1};
	__property bool UseMetafile = {read=FUseMetafile, write=FUseMetafile, default=1};
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TCustomdxOrgChartReportLink(void) { }
	
};


class DELPHICLASS TdxOrgChartReportLink;
class PASCALIMPLEMENTATION TdxOrgChartReportLink : public TCustomdxOrgChartReportLink
{
	typedef TCustomdxOrgChartReportLink inherited;
	
public:
	__property OrgChart;
	
__published:
	__property BorderColor = {default=0};
	__property Color = {default=16777215};
	__property DrawBorder = {default=0};
	__property FullExpand = {default=0};
	__property Transparent = {default=1};
	__property TransparentColor = {default=-16777211};
	__property UseMetafile = {default=1};
public:
	/* TCustomdxOrgChartReportLink.Create */ inline __fastcall virtual TdxOrgChartReportLink(System::Classes::TComponent* AOwner) : TCustomdxOrgChartReportLink(AOwner) { }
	
public:
	/* TBasedxReportLink.Destroy */ inline __fastcall virtual ~TdxOrgChartReportLink(void) { }
	
};


class DELPHICLASS TdxOCReportLinkDesignWindow;
class PASCALIMPLEMENTATION TdxOCReportLinkDesignWindow : public Dxpscore::TStandarddxReportLinkDesignWindow
{
	typedef Dxpscore::TStandarddxReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshOptions;
	Vcl::Extctrls::TPanel* pnlPreview;
	Dxorgchr::TdxOrgChart* ocPreview;
	Cxlabel::TcxLabel* stDrawBorder;
	Cxlabel::TcxLabel* lblPreview;
	Cxlabel::TcxLabel* lblGridLinesColor;
	Cxcheckbox::TcxCheckBox* chbxFullExpand;
	Cxcheckbox::TcxCheckBox* chbxDrawBorder;
	Cxcolorcombobox::TcxColorComboBox* ccbxGridLineColor;
	Cxcheckbox::TcxCheckBox* chbxTransparent;
	Cxlabel::TcxLabel* stTransparent;
	Cxlabel::TcxLabel* lblColor;
	Cxcolorcombobox::TcxColorComboBox* ccbxColor;
	void __fastcall ccbxColorChange(System::TObject* Sender);
	void __fastcall chbxDrawBorderClick(System::TObject* Sender);
	void __fastcall chbxFullExpandClick(System::TObject* Sender);
	void __fastcall chbxTransparentClick(System::TObject* Sender);
	void __fastcall lblColorClick(System::TObject* Sender);
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall stDrawBorderClick(System::TObject* Sender);
	void __fastcall stTransparentClick(System::TObject* Sender);
	
private:
	Vcl::Graphics::TBitmap* FOCBmp;
	void __fastcall CreateControls(void);
	TCustomdxOrgChartReportLink* __fastcall GetReportLink(void);
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	Vcl::Controls::TCustomControl* FPreviewBox;
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall PaintPreview(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall UpdatePreview(void);
	virtual void __fastcall UpdateControlsState(void);
	
public:
	__fastcall virtual TdxOCReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxOCReportLinkDesignWindow(void);
	__property TCustomdxOrgChartReportLink* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxOCReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TStandarddxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxOCReportLinkDesignWindow(HWND ParentWindow) : Dxpscore::TStandarddxReportLinkDesignWindow(ParentWindow) { }
	
};


struct TdxOrgChartGetAsGraphicData;
typedef TdxOrgChartGetAsGraphicData *PdxOrgChartGetAsGraphicData;

struct DECLSPEC_DRECORD TdxOrgChartGetAsGraphicData
{
public:
	Dxorgchr::TdxCustomOrgChart* OrgChart;
	Vcl::Graphics::TGraphicClass GraphicClass;
	bool FullExpand;
	bool Transparent;
	System::Uitypes::TColor TransparentColor;
	bool Enhanced;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Vcl::Graphics::TGraphic* __fastcall dxGetOrgChartAsGraphic(const TdxOrgChartGetAsGraphicData &AData);
}	/* namespace Dxpsdxoclnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDXOCLNK)
using namespace Dxpsdxoclnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdxoclnkHPP
