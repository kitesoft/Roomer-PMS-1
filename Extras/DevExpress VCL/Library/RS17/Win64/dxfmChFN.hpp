// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxfmChFN.pas' rev: 24.00 (Win64)

#ifndef DxfmchfnHPP
#define DxfmchfnHPP

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
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfmchfn
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmdxChangeFileName;
class PASCALIMPLEMENTATION TfmdxChangeFileName : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxgroupbox::TcxGroupBox* GroupBox1;
	Cxtextedit::TcxTextEdit* edFileName;
	Cxlabel::TcxLabel* lblEnterNewFileName;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall edFileNameChange(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	
private:
	System::UnicodeString FFileName;
	bool FModified;
	void __fastcall LoadStrings(void);
	bool __fastcall ValidateFileName(void);
	
public:
	bool __fastcall Execute(void);
	__property System::UnicodeString FileName = {read=FFileName, write=FFileName};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmdxChangeFileName(System::Classes::TComponent* AOwner) : Dxpsform::TCustomdxPSForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmdxChangeFileName(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmdxChangeFileName(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmdxChangeFileName(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowChooseFileNameDlg(System::UnicodeString &AFileName);
}	/* namespace Dxfmchfn */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFMCHFN)
using namespace Dxfmchfn;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfmchfnHPP
