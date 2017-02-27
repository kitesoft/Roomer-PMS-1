// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellBrowser.pas' rev: 24.00 (Win64)

#ifndef CxshellbrowserHPP
#define CxshellbrowserHPP

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
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxShellTreeView.hpp>	// Pascal unit
#include <cxShellCommon.hpp>	// Pascal unit
#include <cxShellControls.hpp>	// Pascal unit
#include <cxShellDlgs.hpp>	// Pascal unit
#include <Winapi.ShlObj.hpp>	// Pascal unit
#include <System.Win.ComObj.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <Vcl.FileCtrl.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxshellbrowser
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxShellBrowserDlg;
class PASCALIMPLEMENTATION TcxShellBrowserDlg : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxshelltreeview::TcxShellTreeView* cxStv;
	Cxlabel::TcxLabel* lblFolder;
	Cxtextedit::TcxTextEdit* cxTeFolder;
	Cxbuttons::TcxButton* cxButton1;
	Cxbuttons::TcxButton* cxButton2;
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall cxStvChange(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall FormPaint(System::TObject* Sender);
	
private:
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	System::Types::TRect FSizeGripRect;
	System::UnicodeString __fastcall GetFolder(void);
	void __fastcall SetFolder(const System::UnicodeString Value);
	System::UnicodeString __fastcall GetCaption(void);
	void __fastcall SetCaption(const System::UnicodeString Value);
	System::UnicodeString __fastcall GetFolderCaption(void);
	void __fastcall SetFolderCaption(const System::UnicodeString Value);
	Cxshellcontrols::TcxShellTreeViewOptions* __fastcall GetShellOptions(void);
	void __fastcall SetShellOptions(Cxshellcontrols::TcxShellTreeViewOptions* Value);
	Cxshellcontrols::TcxShellTreeRoot* __fastcall GetRoot(void);
	void __fastcall SetRoot(Cxshellcontrols::TcxShellTreeRoot* const Value);
	bool __fastcall GetShButtons(void);
	bool __fastcall GetShInfoTips(void);
	bool __fastcall GetShShowLines(void);
	bool __fastcall GetShShowRoot(void);
	void __fastcall SetSfShowRoot(const bool Value);
	void __fastcall SetShButtons(const bool Value);
	void __fastcall SetShInfoTips(const bool Value);
	void __fastcall SetShShowLines(const bool Value);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	void __fastcall LFChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	
public:
	__fastcall virtual TcxShellBrowserDlg(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxShellBrowserDlg(void);
	__property System::UnicodeString DlgCaption = {read=GetCaption, write=SetCaption};
	__property System::UnicodeString DlgFolderLabelCaption = {read=GetFolderCaption, write=SetFolderCaption};
	__property Cxshellcontrols::TcxShellTreeViewOptions* DlgOptions = {read=GetShellOptions, write=SetShellOptions};
	__property bool DlgShowButtons = {read=GetShButtons, write=SetShButtons, nodefault};
	__property bool DlgShowInfoTips = {read=GetShInfoTips, write=SetShInfoTips, nodefault};
	__property bool DlgShowLines = {read=GetShShowLines, write=SetShShowLines, nodefault};
	__property bool DlgShowRoot = {read=GetShShowRoot, write=SetSfShowRoot, nodefault};
	__property Cxshellcontrols::TcxShellTreeRoot* DlgRoot = {read=GetRoot, write=SetRoot};
	__property System::UnicodeString DlgFolder = {read=GetFolder, write=SetFolder};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxShellBrowserDlg(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxShellBrowserDlg(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxshellbrowser */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLBROWSER)
using namespace Cxshellbrowser;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshellbrowserHPP
