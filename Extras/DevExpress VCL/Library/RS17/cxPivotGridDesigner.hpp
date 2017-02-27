// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridDesigner.pas' rev: 24.00 (Win32)

#ifndef CxpivotgriddesignerHPP
#define CxpivotgriddesignerHPP

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
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgriddesigner
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmPivotGridDesigner;
class PASCALIMPLEMENTATION TfrmPivotGridDesigner : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Vcl::Comctrls::TPageControl* pcDesigner;
	Vcl::Comctrls::TTabSheet* tbsFields;
	Cxbuttons::TcxButton* btnClose;
	Cxbuttons::TcxButton* btnDelete;
	Cxbuttons::TcxButton* btnMoveUp;
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnMoveDown;
	Cxbuttons::TcxButton* btnRetrieveFields;
	Cxlistbox::TcxListBox* lbFields;
	Vcl::Menus::TPopupMenu* pmFields;
	Vcl::Menus::TMenuItem* miMoveUp;
	Vcl::Menus::TMenuItem* miMoveDown;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* miSelectAll;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Comctrls::TTabSheet* tbsGroups;
	Vcl::Extctrls::TPanel* pnlGroups;
	Cxtreeview::TcxTreeView* tvGroups;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Extctrls::TPanel* pnlGroupUngroup;
	Vcl::Extctrls::TPanel* pnlUnlinked;
	Cxbuttons::TcxButton* btnUnlink;
	Cxbuttons::TcxButton* btnLink;
	Cxlistbox::TcxListBox* lbUnlinkedFields;
	Cxbuttons::TcxButton* btnAddGroup;
	Cxbuttons::TcxButton* btnDeleteGroup;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Menus::TPopupMenu* pmGroups;
	Vcl::Menus::TMenuItem* miAddGroup;
	Vcl::Menus::TMenuItem* miDeleteGroup;
	Vcl::Menus::TMenuItem* MenuItem3;
	Vcl::Menus::TMenuItem* miMoveUpInGroup;
	Vcl::Menus::TMenuItem* miMoveDownInGroup;
	Cxbuttons::TcxButton* btnMoveUpGroup;
	Cxbuttons::TcxButton* btnMoveDownGroup;
	void __fastcall btnFieldsPageClick(System::TObject* Sender);
	void __fastcall btnCloseClick(System::TObject* Sender);
	void __fastcall lbFieldsClick(System::TObject* Sender);
	void __fastcall lbFieldsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbFieldsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall tbsFieldsStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall lbFieldsEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall tbsGroupsResize(System::TObject* Sender);
	void __fastcall tvGroupsEditing(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowEdit);
	void __fastcall btnGroupClick(System::TObject* Sender);
	void __fastcall tvGroupsCustomDrawItem(Vcl::Comctrls::TCustomTreeView* Sender, Vcl::Comctrls::TTreeNode* Node, Vcl::Comctrls::TCustomDrawState State, bool &DefaultDraw);
	void __fastcall tvGroupsClick(System::TObject* Sender);
	void __fastcall lbUnlinkedFieldsClick(System::TObject* Sender);
	void __fastcall tvGroupsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall tvGroupsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall tvGroupsMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall miMoveInGroupClick(System::TObject* Sender);
	void __fastcall tvGroupsChange(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall tvGroupsEdited(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, System::UnicodeString &S);
	void __fastcall tvGroupsDblClick(System::TObject* Sender);
	void __fastcall lbUnlinkedFieldsDblClick(System::TObject* Sender);
	void __fastcall tvGroupsKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	
private:
	Cxcustompivotgrid::_di_IcxPivotGridDesignerIntf __fastcall GetPivotIntf(void);
	Cxcustompivotgrid::TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	
protected:
	bool FIsLocked;
	int FPrevDragIndex;
	System::TObject* DeletedGroup;
	void __fastcall AddField(void);
	void __fastcall DeleteSelection(void);
	System::Classes::TList* __fastcall GetFieldsFromDragSource(System::TObject* ASource);
	Cxcustompivotgrid::TcxPivotGridFieldGroup* __fastcall GetGroup(bool AGroupOnly = false);
	Cxcustompivotgrid::TcxPivotGridField* __fastcall GetGroupField(void);
	virtual void __fastcall InitFormEditor(void);
	void __fastcall SelectionMoveUp(void);
	void __fastcall SelectionMoveDown(void);
	void __fastcall SelectItem(System::Classes::TPersistent* AItem);
	void __fastcall ReindexFields(System::Classes::TList* AList, int ANewIndex);
	void __fastcall RetrieveFields(void);
	void __fastcall SyncGroupSelection(void);
	void __fastcall UpdateButtons(void);
	void __fastcall UpdateDesigner(void);
	void __fastcall UpdateFieldList(void);
	void __fastcall UpdateFieldListBox(Cxlistbox::TcxListBox* AListBox, bool AUnlinkedOnly);
	void __fastcall UpdateGroups(void);
	void __fastcall UpdateGroupsButtons(void);
	void __fastcall UpdateUnlinkedFieldList(void);
	
public:
	virtual void __fastcall DoItemsModified(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	__property Cxcustompivotgrid::TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid};
	__property Cxcustompivotgrid::_di_IcxPivotGridDesignerIntf PivotIntf = {read=GetPivotIntf};
public:
	/* TcxDesignWindow.Create */ inline __fastcall virtual TfrmPivotGridDesigner(System::Classes::TComponent* AOwner) : Cxdesignwindows::TcxDesignFormEditor(AOwner) { }
	
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TfrmPivotGridDesigner(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmPivotGridDesigner(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmPivotGridDesigner(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowPivotGridDesigner(Designintf::_di_IDesigner ADesigner, Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid);
}	/* namespace Cxpivotgriddesigner */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDDESIGNER)
using namespace Cxpivotgriddesigner;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgriddesignerHPP
