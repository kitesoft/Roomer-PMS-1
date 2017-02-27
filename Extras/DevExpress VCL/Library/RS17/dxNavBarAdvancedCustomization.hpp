// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarAdvancedCustomization.pas' rev: 24.00 (Win32)

#ifndef DxnavbaradvancedcustomizationHPP
#define DxnavbaradvancedcustomizationHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxSplitter.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbaradvancedcustomization
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarAdvancedCustomizationForm;
class PASCALIMPLEMENTATION TdxNavBarAdvancedCustomizationForm : public Dxnavbar::TdxNavBarCustomCustomizationForm
{
	typedef Dxnavbar::TdxNavBarCustomCustomizationForm inherited;
	
__published:
	Cxgroupbox::TcxGroupBox* cxGroupBox1;
	Cxgroupbox::TcxGroupBox* gbGroups;
	Cxgroupbox::TcxGroupBox* gbItems;
	Cxsplitter::TcxSplitter* cxSplitter1;
	Cxtreeview::TcxTreeView* tvGroups;
	Cxtreeview::TcxTreeView* tvItems;
	Cxgraphics::TcxImageList* ilItems;
	Vcl::Actnlist::TActionList* alMain;
	Vcl::Actnlist::TAction* acAddGroup;
	Vcl::Actnlist::TAction* acDelete;
	Vcl::Actnlist::TAction* acExpandAll;
	Vcl::Actnlist::TAction* acCollapseAll;
	Cxgraphics::TcxImageList* ilActions;
	Vcl::Menus::TPopupMenu* pmMain;
	Vcl::Menus::TMenuItem* acAddGroup1;
	Vcl::Menus::TMenuItem* acDelete1;
	Vcl::Menus::TMenuItem* acExpandAll1;
	Vcl::Menus::TMenuItem* acCollapseAll1;
	Vcl::Menus::TMenuItem* N1;
	Cxgroupbox::TcxGroupBox* gbToolBar;
	Cxgroupbox::TcxGroupBox* gbGroupsIndent;
	Cxgroupbox::TcxGroupBox* gbItemsIndent;
	Cxbuttons::TcxButton* btnExpandAll;
	Cxbuttons::TcxButton* btnCollapseAll;
	Cxbuttons::TcxButton* btnAddGroup;
	Cxbuttons::TcxButton* btnDelete;
	void __fastcall tvStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall tvEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall tvDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall tvGroupsEditing(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowEdit);
	void __fastcall tvEdited(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, System::UnicodeString &S);
	void __fastcall tvGetImageIndex(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall acExpandAllExecute(System::TObject* Sender);
	void __fastcall acCollapseAllExecute(System::TObject* Sender);
	void __fastcall acDeleteExecute(System::TObject* Sender);
	void __fastcall tvGroupsChange(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall acAddGroupExecute(System::TObject* Sender);
	void __fastcall FormShortCut(Winapi::Messages::TWMKey &Msg, bool &Handled);
	
private:
	bool __fastcall CanDropItem(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall PopulateGroups(void);
	void __fastcall PopulateItems(void);
	void __fastcall TreeViewWndProcHandler(Vcl::Comctrls::TTreeView* ATreeView, Winapi::Messages::TMessage &Message, bool &ADone);
	void __fastcall UpdateButtonsState(void);
	
protected:
	virtual void __fastcall DoCreateControls(void);
	virtual void __fastcall DoRefreshItems(void);
	virtual void __fastcall Localize(void);
	virtual bool __fastcall CanProcessDropItem(System::TObject* Target, int X, int Y);
	virtual void __fastcall DoProcessDropItem(System::TObject* Target, int X, int Y);
	
public:
	__fastcall virtual TdxNavBarAdvancedCustomizationForm(System::Classes::TComponent* AOwner);
public:
	/* TdxNavBarCustomCustomizationForm.Destroy */ inline __fastcall virtual ~TdxNavBarAdvancedCustomizationForm(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxNavBarAdvancedCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Dxnavbar::TdxNavBarCustomCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxNavBarAdvancedCustomizationForm(HWND ParentWindow) : Dxnavbar::TdxNavBarCustomCustomizationForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbaradvancedcustomization */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARADVANCEDCUSTOMIZATION)
using namespace Dxnavbaradvancedcustomization;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbaradvancedcustomizationHPP
