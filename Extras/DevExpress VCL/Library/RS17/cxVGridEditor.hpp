// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVGridEditor.pas' rev: 24.00 (Win32)

#ifndef CxvgrideditorHPP
#define CxvgrideditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxDBVGrid.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvgrideditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxVerticalGridEditor;
class PASCALIMPLEMENTATION TcxVerticalGridEditor : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Stdctrls::TListBox* lbRows;
	Cxbuttons::TcxButton* btCategory;
	Cxbuttons::TcxButton* btEditor;
	Cxbuttons::TcxButton* btClose;
	Cxbuttons::TcxButton* btMultiEditor;
	Cxbuttons::TcxButton* btDelete;
	Cxbuttons::TcxButton* btClear;
	Cxbuttons::TcxButton* btCreateAll;
	Vcl::Menus::TPopupMenu* PopupMenu;
	Vcl::Menus::TMenuItem* miEditor;
	Vcl::Menus::TMenuItem* miCategory;
	Vcl::Menus::TMenuItem* miMultieditor;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miClearAll;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* miSelectAll;
	Cxbuttons::TcxButton* btLayoutEditor;
	void __fastcall btCloseClick(System::TObject* Sender);
	void __fastcall lbRowsClick(System::TObject* Sender);
	void __fastcall btCategoryClick(System::TObject* Sender);
	void __fastcall btEditorClick(System::TObject* Sender);
	void __fastcall btMultiEditorClick(System::TObject* Sender);
	void __fastcall btDeleteClick(System::TObject* Sender);
	void __fastcall btClearClick(System::TObject* Sender);
	void __fastcall FormActivate(System::TObject* Sender);
	void __fastcall btCreateAllClick(System::TObject* Sender);
	void __fastcall miEditorClick(System::TObject* Sender);
	void __fastcall miCategoryClick(System::TObject* Sender);
	void __fastcall miMultieditorClick(System::TObject* Sender);
	void __fastcall miDeleteClick(System::TObject* Sender);
	void __fastcall miClearAllClick(System::TObject* Sender);
	void __fastcall miSelectAllClick(System::TObject* Sender);
	void __fastcall btLayoutEditorClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	HIDESBASE void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	
private:
	bool FLocked;
	void __fastcall AddRow(Cxvgrid::TcxCustomRowClass ARowClass);
	Cxvgrid::TcxCustomVerticalGrid* __fastcall GetVerticalGrid(void);
	void __fastcall SelectItem(void * AItem);
	void __fastcall UpdateButtons(void);
	void __fastcall UpdateDesigner(System::TObject* Sender);
	void __fastcall UpdateItems(void);
	
protected:
	virtual void __fastcall InitFormEditor(void);
	
public:
	virtual void __fastcall DoItemsModified(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	__property Cxvgrid::TcxCustomVerticalGrid* VerticalGrid = {read=GetVerticalGrid};
public:
	/* TcxDesignWindow.Create */ inline __fastcall virtual TcxVerticalGridEditor(System::Classes::TComponent* AOwner) : Cxdesignwindows::TcxDesignFormEditor(AOwner) { }
	
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TcxVerticalGridEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxVerticalGridEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxVerticalGridEditor(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowVerticalGridEditor(Designintf::_di_IDesigner ADesigner, Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid);
}	/* namespace Cxvgrideditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVGRIDEDITOR)
using namespace Cxvgrideditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvgrideditorHPP
