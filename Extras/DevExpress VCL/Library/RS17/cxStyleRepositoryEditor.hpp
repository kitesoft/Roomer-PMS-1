// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxStyleRepositoryEditor.pas' rev: 24.00 (Win32)

#ifndef CxstylerepositoryeditorHPP
#define CxstylerepositoryeditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxstylerepositoryeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxStyleRepositoryEditor;
class PASCALIMPLEMENTATION TcxStyleRepositoryEditor : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Vcl::Stdctrls::TListBox* lbStyles;
	Vcl::Stdctrls::TButton* btStyleAdd;
	Vcl::Stdctrls::TButton* btStyleDelete;
	Vcl::Stdctrls::TButton* btClose;
	Vcl::Extctrls::TPanel* pnlStyles;
	Vcl::Menus::TPopupMenu* pmStyles;
	Vcl::Menus::TMenuItem* miStyleAdd;
	Vcl::Menus::TMenuItem* miStyleDelete;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* miStyleSelectAll;
	Vcl::Comctrls::TPageControl* PageControl1;
	Vcl::Comctrls::TTabSheet* tsStyles;
	Vcl::Comctrls::TTabSheet* tsStyleSheets;
	Vcl::Stdctrls::TListBox* lbStyleSheets;
	Vcl::Extctrls::TPanel* pnlStyleSheets;
	Vcl::Stdctrls::TButton* btStyleSheetAdd;
	Vcl::Stdctrls::TButton* btStyleSheetDelete;
	Vcl::Stdctrls::TButton* Button3;
	Vcl::Menus::TPopupMenu* pmStyleSheets;
	Vcl::Menus::TMenuItem* miStyleSheetAdd;
	Vcl::Menus::TMenuItem* miStyleSheetDelete;
	Vcl::Menus::TMenuItem* MenuItem3;
	Vcl::Menus::TMenuItem* miStyleSheetSelectAll;
	Vcl::Stdctrls::TButton* btnStyleSheetEdit;
	Vcl::Menus::TMenuItem* imStyleSheetEdit;
	Vcl::Menus::TPopupMenu* pmAddStyleSheet;
	Vcl::Stdctrls::TButton* btnStyleSheetsSave;
	Vcl::Dialogs::TSaveDialog* SaveDialog;
	Vcl::Stdctrls::TButton* btnStyleSheetsLoad;
	Vcl::Dialogs::TOpenDialog* OpenDialog;
	Vcl::Stdctrls::TButton* btnStyleSheetsPredefine;
	void __fastcall lbStylesClick(System::TObject* Sender);
	void __fastcall btStyleDeleteClick(System::TObject* Sender);
	void __fastcall btCloseClick(System::TObject* Sender);
	void __fastcall btStyleAddClick(System::TObject* Sender);
	void __fastcall miStyleSelectAllClick(System::TObject* Sender);
	void __fastcall btStyleSheetAddClick(System::TObject* Sender);
	void __fastcall btStyleSheetDeleteClick(System::TObject* Sender);
	void __fastcall miStyleSheetSelectAllClick(System::TObject* Sender);
	void __fastcall lbStyleSheetsClick(System::TObject* Sender);
	void __fastcall btnStyleSheetEditClick(System::TObject* Sender);
	void __fastcall btnStyleSheetsSaveClick(System::TObject* Sender);
	void __fastcall btnStyleSheetsLoadClick(System::TObject* Sender);
	void __fastcall btnStyleSheetsPredefineClick(System::TObject* Sender);
	
private:
	void __fastcall AddStyleSheets(System::Classes::TList* AList);
	System::UnicodeString __fastcall DoStyleGetName(Cxstyles::TcxStyle* AStyle);
	void __fastcall DoAddStyleSheetMenuItemClick(System::TObject* Sender);
	void __fastcall InitAddStyleSheetMenu(void);
	void __fastcall ListBoxSelectComponents(Vcl::Stdctrls::TListBox* AListBox);
	Cxstyles::TcxStyleRepository* __fastcall GetStyleRepository(void);
	void __fastcall UpdateButtons(void);
	void __fastcall UpdateDesigner(System::TObject* Sender);
	void __fastcall UpdateItems(void);
	void __fastcall SelectItem(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TPersistent* AItem);
	System::TObject* __fastcall FindItemToSelect(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall DeleteSelectedComponents(Vcl::Stdctrls::TListBox* AListBox);
	
protected:
	virtual void __fastcall InitFormEditor(void);
	
public:
	virtual void __fastcall DoItemsModified(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	__property Cxstyles::TcxStyleRepository* StyleRepository = {read=GetStyleRepository};
public:
	/* TcxDesignWindow.Create */ inline __fastcall virtual TcxStyleRepositoryEditor(System::Classes::TComponent* AOwner) : Cxdesignwindows::TcxDesignFormEditor(AOwner) { }
	
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TcxStyleRepositoryEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxStyleRepositoryEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxStyleRepositoryEditor(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowStyleRepositoryEditor(Designintf::_di_IDesigner ADesigner, Cxstyles::TcxStyleRepository* AStyleRepository);
}	/* namespace Cxstylerepositoryeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSTYLEREPOSITORYEDITOR)
using namespace Cxstylerepositoryeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxstylerepositoryeditorHPP
