// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPDFExportDialog.pas' rev: 24.00 (Win32)

#ifndef DxpspdfexportdialogHPP
#define DxpspdfexportdialogHPP

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
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <dxPSPDFExport.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSEngn.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPrnDlg.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxTrackBar.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <dxPSRes.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPSPDFExportCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpspdfexportdialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSPDFExportDialogForm;
class PASCALIMPLEMENTATION TdxPSPDFExportDialogForm : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnOk;
	Cxcheckbox::TcxCheckBox* cbCompressed;
	Cxcheckbox::TcxCheckBox* cbEmbedFonts;
	Cxcheckbox::TcxCheckBox* cbJpgCompress;
	Cxcheckbox::TcxCheckBox* cbOpenAfterExport;
	Cxpc::TcxPageControl* cxPageControl;
	Cxtextedit::TcxTextEdit* edPageRanges;
	Cxgroupbox::TcxGroupBox* gbExportSettings;
	Cxlabel::TcxLabel* lbAuthor;
	Cxlabel::TcxLabel* lbCreator;
	Cxlabel::TcxLabel* lbKeywords;
	Cxlabel::TcxLabel* lbDescription;
	Cxlabel::TcxLabel* lbMaxCompression;
	Cxlabel::TcxLabel* lbMaxQuality;
	Cxlabel::TcxLabel* lbSubject;
	Cxlabel::TcxLabel* lbTitle;
	Cxradiogroup::TcxRadioButton* rbtnAllPages;
	Cxradiogroup::TcxRadioButton* rbtnCurrentPage;
	Cxradiogroup::TcxRadioButton* rbtnPageRanges;
	Cxtrackbar::TcxTrackBar* tbJpgCompression;
	Cxpc::TcxTabSheet* tbsExport;
	Cxpc::TcxTabSheet* tbsPageRange;
	Cxtextedit::TcxTextEdit* teAuthor;
	Cxtextedit::TcxTextEdit* teCreator;
	Cxtextedit::TcxTextEdit* teKeywords;
	Cxtextedit::TcxTextEdit* teSubject;
	Cxtextedit::TcxTextEdit* teTitle;
	Cxpc::TcxTabSheet* tbsDocInfo;
	Cxcheckbox::TcxCheckBox* cbUseCIDFonts;
	Cxpc::TcxTabSheet* tbsSecurity;
	Cxgroupbox::TcxGroupBox* gbSecuritySettings;
	Cxcheckbox::TcxCheckBox* cbAllowChanging;
	Cxcheckbox::TcxCheckBox* cbAllowPrinting;
	Cxcheckbox::TcxCheckBox* cbAllowComments;
	Cxcheckbox::TcxCheckBox* cbAllowContentCopying;
	Cxcheckbox::TcxCheckBox* cbSecurityEnable;
	Cxlabel::TcxLabel* lbUserPassword;
	Cxtextedit::TcxTextEdit* edUserPassword;
	Cxlabel::TcxLabel* lbOwnerPassword;
	Cxtextedit::TcxTextEdit* edOwnerPassword;
	Cxcheckbox::TcxCheckBox* cbAllowDocumentAssembly;
	Cxcheckbox::TcxCheckBox* cbAllowPrintingHiResolution;
	Cxlabel::TcxLabel* lbMethod;
	Cxdropdownedit::TcxComboBox* cbxMethod;
	void __fastcall cbJpgCompressClick(System::TObject* Sender);
	void __fastcall rbtnPageRangesClick(System::TObject* Sender);
	void __fastcall edPageRangesKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall cbSecurityEnableClick(System::TObject* Sender);
	void __fastcall cbxMethodPropertiesChange(System::TObject* Sender);
	
protected:
	Dxprndlg::TdxPageRanges __fastcall GetPageRanges(void);
	void __fastcall LoadSecurityOptions(Dxpspdfexportcore::TdxPSPDFSecurityOptions* AOptions);
	void __fastcall SaveSecurityOptions(Dxpspdfexportcore::TdxPSPDFSecurityOptions* AOptions);
	void __fastcall SetPageRanges(Dxprndlg::TdxPageRanges AValue);
	
public:
	__fastcall virtual TdxPSPDFExportDialogForm(System::Classes::TComponent* AOwner);
	void __fastcall LoadOptions(Dxpscore::TdxPSPDFReportExportOptions* AOptions);
	void __fastcall LoadTranslation(void);
	void __fastcall SaveOptions(Dxpscore::TdxPSPDFReportExportOptions* AOptions);
	__property Dxprndlg::TdxPageRanges PageRanges = {read=GetPageRanges, write=SetPageRanges, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxPSPDFExportDialogForm(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxPSPDFExportDialogForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSPDFExportDialogForm(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxPSShowPDFSettingsDialog(Dxpscore::TdxPSPDFReportExportOptions* AOptions, bool AIsDesignTime = false);
}	/* namespace Dxpspdfexportdialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPDFEXPORTDIALOG)
using namespace Dxpspdfexportdialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpspdfexportdialogHPP
