// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditRepositoryEditor.pas' rev: 24.00 (Win32)

#ifndef CxeditrepositoryeditorHPP
#define CxeditrepositoryeditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditrepositoryeditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxEditRepositoryEditor;
class PASCALIMPLEMENTATION TcxEditRepositoryEditor : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Vcl::Stdctrls::TListBox* LBItems;
	Vcl::Stdctrls::TButton* btAdd;
	Vcl::Stdctrls::TButton* btDelete;
	Vcl::Stdctrls::TButton* btClose;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Menus::TPopupMenu* PopupMenu1;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* miSelectAll;
	Vcl::Extctrls::TBevel* bvTopSpacer;
	Vcl::Extctrls::TBevel* bvBottomSpacer;
	Vcl::Extctrls::TBevel* bvLeftSpacer;
	Vcl::Extctrls::TBevel* bvRightSpacer;
	void __fastcall LBItemsClick(System::TObject* Sender);
	void __fastcall btDeleteClick(System::TObject* Sender);
	void __fastcall btCloseClick(System::TObject* Sender);
	void __fastcall btAddClick(System::TObject* Sender);
	void __fastcall SelectItem(System::TObject* AItem);
	void __fastcall miAddClick(System::TObject* Sender);
	void __fastcall miDeleteClick(System::TObject* Sender);
	void __fastcall miSelectAllClick(System::TObject* Sender);
	
private:
	Cxedit::TcxEditRepository* __fastcall GetEditRepository(void);
	void __fastcall UpdateButtons(void);
	void __fastcall UpdateDesigner(System::TObject* Sender);
	void __fastcall UpdateItems(void);
	
protected:
	virtual void __fastcall InitFormEditor(void);
	
public:
	virtual void __fastcall DoItemsModified(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	__property Cxedit::TcxEditRepository* EditRepository = {read=GetEditRepository};
public:
	/* TcxDesignWindow.Create */ inline __fastcall virtual TcxEditRepositoryEditor(System::Classes::TComponent* AOwner) : Cxdesignwindows::TcxDesignFormEditor(AOwner) { }
	
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TcxEditRepositoryEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxEditRepositoryEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxEditRepositoryEditor(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall RegisterEditRepositoryItem(Cxedit::TcxEditRepositoryItemClass AEditRepositoryItemClass, const System::UnicodeString ADescription);
extern PACKAGE void __fastcall UnRegisterEditRepositoryItem(Cxedit::TcxEditRepositoryItemClass AEditRepositoryItemClass);
extern PACKAGE void __fastcall ShowEditRepositoryEditor(Designintf::_di_IDesigner ADesigner, Cxedit::TcxEditRepository* AEditRepository);
extern PACKAGE void __fastcall GenEditRepositoryItemName(Cxedit::TcxEditRepository* AEditRepository, Cxedit::TcxEditRepositoryItem* AItem);
}	/* namespace Cxeditrepositoryeditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITREPOSITORYEDITOR)
using namespace Cxeditrepositoryeditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditrepositoryeditorHPP
