// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellBrowserDialog.pas' rev: 24.00 (Win32)

#ifndef CxshellbrowserdialogHPP
#define CxshellbrowserdialogHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxShellCommon.hpp>	// Pascal unit
#include <cxShellControls.hpp>	// Pascal unit
#include <cxShellDlgs.hpp>	// Pascal unit
#include <cxShellBrowser.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxshellbrowserdialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomShellBrowserDialog;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomShellBrowserDialog : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	Cxshellbrowser::TcxShellBrowserDlg* FDlg;
	System::UnicodeString FFolderCaption;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	System::UnicodeString FPath;
	Cxshelldlgs::TcxDlgShellRoot* FRoot;
	bool FShButtons;
	Cxshelldlgs::TcxDlgShellOptions* FShellOptions;
	bool FShInfoTips;
	bool FShShowLines;
	bool FShShowRoot;
	System::UnicodeString FTitle;
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	
protected:
	DYNAMIC Cxshellbrowser::TcxShellBrowserDlg* __fastcall CreateForm(void);
	__property System::UnicodeString FolderLabelCaption = {read=FFolderCaption, write=FFolderCaption};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property Cxshelldlgs::TcxDlgShellOptions* Options = {read=FShellOptions, write=FShellOptions};
	__property System::UnicodeString Path = {read=FPath, write=FPath};
	__property Cxshelldlgs::TcxDlgShellRoot* Root = {read=FRoot, write=FRoot};
	__property bool ShowButtons = {read=FShButtons, write=FShButtons, default=1};
	__property bool ShowInfoTips = {read=FShInfoTips, write=FShInfoTips, default=0};
	__property bool ShowLines = {read=FShShowLines, write=FShShowLines, default=1};
	__property bool ShowRoot = {read=FShShowRoot, write=FShShowRoot, default=1};
	__property System::UnicodeString Title = {read=FTitle, write=FTitle};
	
public:
	__fastcall virtual TcxCustomShellBrowserDialog(System::Classes::TComponent* aOwner);
	__fastcall virtual ~TcxCustomShellBrowserDialog(void);
	bool __fastcall Execute(void);
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TcxShellBrowserDialog;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxShellBrowserDialog : public TcxCustomShellBrowserDialog
{
	typedef TcxCustomShellBrowserDialog inherited;
	
__published:
	__property FolderLabelCaption = {default=0};
	__property LookAndFeel;
	__property Options;
	__property Path = {default=0};
	__property Root;
	__property ShowButtons = {default=1};
	__property ShowInfoTips = {default=0};
	__property ShowLines = {default=1};
	__property ShowRoot = {default=1};
	__property Title = {default=0};
public:
	/* TcxCustomShellBrowserDialog.Create */ inline __fastcall virtual TcxShellBrowserDialog(System::Classes::TComponent* aOwner) : TcxCustomShellBrowserDialog(aOwner) { }
	/* TcxCustomShellBrowserDialog.Destroy */ inline __fastcall virtual ~TcxShellBrowserDialog(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxshellbrowserdialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLBROWSERDIALOG)
using namespace Cxshellbrowserdialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshellbrowserdialogHPP
