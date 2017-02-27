// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxfmDTFmt.pas' rev: 24.00 (Win64)

#ifndef DxfmdtfmtHPP
#define DxfmdtfmtHPP

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
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfmdtfmt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmDateTimeFormats;
class PASCALIMPLEMENTATION TdxfmDateTimeFormats : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxgroupbox::TcxGroupBox* GroupBox1;
	Cxlabel::TcxLabel* lblAvailableDateFormats;
	Cxlabel::TcxLabel* lblAvailableTimeFormats;
	Cxbuttons::TcxButton* btnDefault;
	Cxcheckbox::TcxCheckBox* chbxAutoUpdate;
	Cxlistbox::TcxListBox* lbxDateFormats;
	Cxlistbox::TcxListBox* lbxTimeFormats;
	void __fastcall btnDefaultClick(System::TObject* Sender);
	void __fastcall TimeFormatsChanged(System::TObject* Sender);
	void __fastcall lblAvailableDateFormatsClick(System::TObject* Sender);
	void __fastcall lbxDateFormatsClick(System::TObject* Sender);
	void __fastcall chbxAutoUpdateClick(System::TObject* Sender);
	void __fastcall lbxDTFormatsDblClick(System::TObject* Sender);
	
private:
	bool FAutoUpdateDateTime;
	bool FControlsUpdating;
	int FDateFormatIndex;
	System::Classes::TStrings* FDateFormats;
	bool FDTFormatIndexChanged;
	bool FModified;
	bool FSetDateTimeFormatAsDefault;
	int FTimeFormatIndex;
	System::Classes::TStrings* FTimeFormats;
	void __fastcall CheckModified(void);
	void __fastcall LoadStrings(void);
	void __fastcall SetDateFormats(System::Classes::TStrings* Value);
	void __fastcall SetTimeFormats(System::Classes::TStrings* Value);
	void __fastcall StartSettings(void);
	void __fastcall UpdateControlsState(void);
	
public:
	__fastcall virtual TdxfmDateTimeFormats(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmDateTimeFormats(void);
	bool __fastcall Execute(void);
	__property bool AutoUpdateDateTime = {read=FAutoUpdateDateTime, write=FAutoUpdateDateTime, nodefault};
	__property int DateFormatIndex = {read=FDateFormatIndex, write=FDateFormatIndex, nodefault};
	__property System::Classes::TStrings* DateFormats = {read=FDateFormats, write=SetDateFormats};
	__property bool SetDateTimeFormatAsDefault = {read=FSetDateTimeFormatAsDefault, write=FSetDateTimeFormatAsDefault, nodefault};
	__property int TimeFormatIndex = {read=FTimeFormatIndex, write=FTimeFormatIndex, nodefault};
	__property System::Classes::TStrings* TimeFormats = {read=FTimeFormats, write=SetTimeFormats};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmDateTimeFormats(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmDateTimeFormats(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


struct TdxDateTimeFormatDlgData;
typedef TdxDateTimeFormatDlgData *PdxDateTimeFormatDlgData;

struct DECLSPEC_DRECORD TdxDateTimeFormatDlgData
{
public:
	bool AutoUpdateDateTime;
	int DateFormatIndex;
	System::Classes::TStrings* DateFormats;
	bool ShowAsDefaultButton;
	bool SetDateTimeFormatAsDefault;
	int TimeFormatIndex;
	System::Classes::TStrings* TimeFormats;
	System::Classes::THelpContext HelpContext;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowDateTimeFormatDlg(TdxDateTimeFormatDlgData &AFormatsDlgData);
}	/* namespace Dxfmdtfmt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFMDTFMT)
using namespace Dxfmdtfmt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfmdtfmtHPP
