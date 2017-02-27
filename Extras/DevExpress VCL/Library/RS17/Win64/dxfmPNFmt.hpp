// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxfmPNFmt.pas' rev: 24.00 (Win64)

#ifndef DxfmpnfmtHPP
#define DxfmpnfmtHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfmpnfmt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmPageNumberFormat;
class PASCALIMPLEMENTATION TdxfmPageNumberFormat : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxlabel::TcxLabel* lblPageNumberFormat;
	Cxlabel::TcxLabel* Bevel2;
	Cxdropdownedit::TcxComboBox* cbxPageNumberingFormat;
	Cxbuttons::TcxButton* btnDefault;
	Cxradiogroup::TcxRadioButton* rbtnContinueFromPrevSection;
	Cxradiogroup::TcxRadioButton* rbtnStartAt;
	Cxlabel::TcxLabel* lblPageNumbering;
	Vcl::Extctrls::TBevel* bvlStartAtHolder;
	void __fastcall cbxPageNumberingFormatChange(System::TObject* Sender);
	void __fastcall btnDefaultClick(System::TObject* Sender);
	void __fastcall lblPageNumberFormatClick(System::TObject* Sender);
	void __fastcall rbtnStartAtClick(System::TObject* Sender);
	void __fastcall rbtnContinueFromPrevSectionClick(System::TObject* Sender);
	void __fastcall btnHelpClick(System::TObject* Sender);
	
private:
	Dxextctrls::TdxPSValueEdit* FseStartAt;
	bool FAllowContinueFromPrevSection;
	bool FControlsUpdating;
	bool FContinueFromPrevSection;
	bool FModified;
	System::Classes::TStrings* FPageNumberFormats;
	Dxpsglbl::TdxPageNumberFormat FPageNumberFormat;
	int FStartPageIndex;
	bool FSetPageNumberingFormatAsDefault;
	void __fastcall CheckModified(void);
	void __fastcall CreateControls(void);
	void __fastcall Initialize(void);
	void __fastcall LoadStrings(void);
	void __fastcall SetContinueFromPrevSection(bool Value);
	void __fastcall SetPageNumberFormats(System::Classes::TStrings* Value);
	void __fastcall StartAtChanged(System::TObject* Sender);
	void __fastcall StartatExit(System::TObject* Sender);
	
public:
	__fastcall virtual TdxfmPageNumberFormat(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmPageNumberFormat(void);
	bool __fastcall Execute(void);
	__property bool AllowContinueFromPrevSection = {read=FAllowContinueFromPrevSection, write=FAllowContinueFromPrevSection, nodefault};
	__property bool ContinueFromPrevSection = {read=FContinueFromPrevSection, write=SetContinueFromPrevSection, nodefault};
	__property System::Classes::TStrings* PageNumberFormats = {read=FPageNumberFormats, write=SetPageNumberFormats};
	__property Dxpsglbl::TdxPageNumberFormat PageNumberFormat = {read=FPageNumberFormat, write=FPageNumberFormat, nodefault};
	__property bool SetPageNumberingFormatAsDefault = {read=FSetPageNumberingFormatAsDefault, write=FSetPageNumberingFormatAsDefault, nodefault};
	__property int StartPageIndex = {read=FStartPageIndex, write=FStartPageIndex, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmPageNumberFormat(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmPageNumberFormat(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


struct TdxPageNumberFormatDlgData;
typedef TdxPageNumberFormatDlgData *PdxPageNumberFormatDlgData;

struct DECLSPEC_DRECORD TdxPageNumberFormatDlgData
{
public:
	System::Classes::TStrings* PageNumberFormats;
	Dxpsglbl::TdxPageNumberFormat PageNumberFormat;
	bool ContinueFromPrevSection;
	int StartPageIndex;
	bool AllowContinueFromPrevSection;
	bool ShowAsDefaultButton;
	bool SetPageNumberFormatAsDefault;
	System::Classes::THelpContext HelpContext;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowPageNumberFormatDlg(TdxPageNumberFormatDlgData &AFormatsDlgData);
}	/* namespace Dxfmpnfmt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFMPNFMT)
using namespace Dxfmpnfmt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfmpnfmtHPP
