// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmReportProperties.pas' rev: 24.00 (Win32)

#ifndef DxpsfmreportpropertiesHPP
#define DxpsfmreportpropertiesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmreportproperties
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmPSReportProperties;
class PASCALIMPLEMENTATION TdxfmPSReportProperties : public Dxpscore::TCustomdxPSExplorerItemPropertySheets
{
	typedef Dxpscore::TCustomdxPSExplorerItemPropertySheets inherited;
	
__published:
	Cxlabel::TcxLabel* Bevel1;
	Cxlabel::TcxLabel* Bevel2;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnPreview;
	Vcl::Extctrls::TBevel* bvlPreviewHost;
	Cxtextedit::TcxTextEdit* edCreationDate;
	Cxtextedit::TcxTextEdit* edCreator;
	Cxtextedit::TcxTextEdit* edName;
	Vcl::Extctrls::TImage* Image1;
	Cxlabel::TcxLabel* lblCreationDate;
	Cxlabel::TcxLabel* lblCreator;
	Cxmemo::TcxMemo* memDescription;
	Cxpc::TcxPageControl* pcDescription;
	Cxpc::TcxPageControl* pcSummary;
	Cxpc::TcxTabSheet* tshDescription;
	Cxpc::TcxTabSheet* tshPreview;
	Cxpc::TcxTabSheet* tshSummary;
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall PreviewClick(System::TObject* Sender);
	
private:
	Dxextctrls::TdxPSImageScrollBox* FPreviewBox;
	System::UnicodeString __fastcall GetFormCaption(void);
	System::UnicodeString __fastcall GetReportCaption(void);
	System::TDateTime __fastcall GetReportCreationDateTime(void);
	System::UnicodeString __fastcall GetReportCreator(void);
	System::UnicodeString __fastcall GetReportDescription(void);
	void __fastcall SetReportCaption(const System::UnicodeString Value);
	void __fastcall SetReportCreationDateTime(const System::TDateTime Value);
	void __fastcall SetReportCreator(const System::UnicodeString Value);
	void __fastcall SetReportDescription(const System::UnicodeString Value);
	void __fastcall SetReportPreview(Vcl::Graphics::TGraphic* Value);
	
protected:
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall BeforeConstruction(void);
	virtual void __fastcall Done(void);
	virtual void __fastcall Initialize(void);
	bool __fastcall HasGraphic(void);
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall LoadStrings(void);
	void __fastcall PrepareControlColors(void);
	
public:
	__fastcall virtual TdxfmPSReportProperties(System::Classes::TComponent* AOwner);
	HIDESBASE Dxpscore::TdxPSExplorerItem* __fastcall ExplorerItem(void)/* overload */;
	__property System::UnicodeString FormCaption = {read=GetFormCaption};
	__property Dxextctrls::TdxPSImageScrollBox* PreviewBox = {read=FPreviewBox};
	__property System::UnicodeString ReportCaption = {read=GetReportCaption, write=SetReportCaption};
	__property System::TDateTime ReportCreationDateTime = {read=GetReportCreationDateTime, write=SetReportCreationDateTime};
	__property System::UnicodeString ReportCreator = {read=GetReportCreator, write=SetReportCreator};
	__property System::UnicodeString ReportDescription = {read=GetReportDescription, write=SetReportDescription};
	__property Vcl::Graphics::TGraphic* ReportPreview = {write=SetReportPreview};
public:
	/* TCustomdxPSExplorerItemPropertySheets.CreateEx */ inline __fastcall virtual TdxfmPSReportProperties(Dxpscore::TCustomdxPSExplorerItem* AnExplorerItem) : Dxpscore::TCustomdxPSExplorerItemPropertySheets(AnExplorerItem) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmPSReportProperties(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TCustomdxPSExplorerItemPropertySheets(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxfmPSReportProperties(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmPSReportProperties(HWND ParentWindow) : Dxpscore::TCustomdxPSExplorerItemPropertySheets(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsfmreportproperties */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMREPORTPROPERTIES)
using namespace Dxpsfmreportproperties;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmreportpropertiesHPP
