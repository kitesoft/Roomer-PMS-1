// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxOIStringsEd.pas' rev: 24.00 (Win32)

#ifndef CxoistringsedHPP
#define CxoistringsedHPP

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
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxoistringsed
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxfmStringsEditor;
class PASCALIMPLEMENTATION TcxfmStringsEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* pnlClient;
	Vcl::Stdctrls::TGroupBox* GroupBox;
	Vcl::Extctrls::TPanel* pnlClientTop;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Extctrls::TPanel* pnlClientClient;
	Cxmemo::TcxMemo* Memo1;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	void __fastcall Memo1PropertiesChange(System::TObject* Sender);
	void __fastcall FormPaint(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	
private:
	System::Types::TRect FSizeGripBounds;
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DoShow(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxfmStringsEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxfmStringsEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxfmStringsEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxfmStringsEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


struct TcxStringsEditorDlgData;
typedef TcxStringsEditorDlgData *PcxStringsEditorDlgData;

struct DECLSPEC_DRECORD TcxStringsEditorDlgData
{
public:
	System::UnicodeString Caption;
	Cxlookandfeels::TcxLookAndFeel* LookAndFeel;
	System::UnicodeString Text;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall cxShowStringsEditor(const PcxStringsEditorDlgData AData);
}	/* namespace Cxoistringsed */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXOISTRINGSED)
using namespace Cxoistringsed;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxoistringsedHPP
