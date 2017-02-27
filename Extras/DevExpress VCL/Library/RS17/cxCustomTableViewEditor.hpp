// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCustomTableViewEditor.pas' rev: 24.00 (Win32)

#ifndef CxcustomtablevieweditorHPP
#define CxcustomtablevieweditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridStructureNavigator.hpp>	// Pascal unit
#include <cxViewEditor.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcustomtablevieweditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomTableViewEditor;
class PASCALIMPLEMENTATION TcxCustomTableViewEditor : public Cxvieweditor::TcxViewEditor
{
	typedef Cxvieweditor::TcxViewEditor inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* TSItems;
	Cxpc::TcxTabSheet* TSSummary;
	Vcl::Extctrls::TPanel* Panel1;
	Cxbuttons::TcxButton* BColumnAdd;
	Cxbuttons::TcxButton* BColumnDelete;
	Cxbuttons::TcxButton* BColumnAddAll;
	Cxbuttons::TcxButton* BColumnRestore;
	Vcl::Menus::TPopupMenu* PMColumns;
	Vcl::Menus::TMenuItem* MIColumnAdd;
	Vcl::Menus::TMenuItem* MIColumnDelete;
	Vcl::Menus::TMenuItem* MIColumnRestore;
	Vcl::Menus::TMenuItem* MIColumnSelectAll;
	Cxpc::TcxPageControl* PageControl2;
	Cxpc::TcxTabSheet* TSFooterSummaryItems;
	Cxpc::TcxTabSheet* TSDefaultGroupSummaryItems;
	Cxpc::TcxTabSheet* TabSheet3;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel3;
	Cxbuttons::TcxButton* BAddFooterSummaryItem;
	Cxbuttons::TcxButton* BDeleteFooterSummaryItem;
	Vcl::Stdctrls::TListBox* LBFooterSummary;
	Vcl::Extctrls::TPanel* Panel4;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Extctrls::TPanel* Panel6;
	Cxbuttons::TcxButton* BDefaultGroupSummaryAdd;
	Cxbuttons::TcxButton* BDefaultGroupSummaryDelete;
	Vcl::Stdctrls::TListBox* LBDefaultGroupsSummary;
	Vcl::Extctrls::TPanel* Panel7;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Extctrls::TPanel* PSummaryGroups;
	Vcl::Extctrls::TPanel* PLinks;
	Vcl::Extctrls::TPanel* PGroupItems;
	Vcl::Extctrls::TPanel* Panel11;
	Cxbuttons::TcxButton* BGroupSummaryItemAdd;
	Cxbuttons::TcxButton* BGroupSummaryItemDelete;
	Vcl::Stdctrls::TListBox* LBGroupSummaryItems;
	Vcl::Extctrls::TPanel* Panel12;
	Vcl::Stdctrls::TLabel* Label4;
	Vcl::Extctrls::TPanel* PGroups;
	Vcl::Extctrls::TPanel* Panel14;
	Cxbuttons::TcxButton* BSummaryGroupAdd;
	Cxbuttons::TcxButton* BSummaryGroupDelete;
	Vcl::Stdctrls::TListBox* LBSummaryGroups;
	Vcl::Extctrls::TPanel* Panel15;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Extctrls::TPanel* PUnlinkedColumns;
	Vcl::Stdctrls::TListBox* LBUnlinkedColumns;
	Vcl::Extctrls::TPanel* Panel19;
	Vcl::Stdctrls::TLabel* Label6;
	Vcl::Extctrls::TPanel* PLinkUnlink;
	Vcl::Extctrls::TPanel* PLinkedColumns;
	Vcl::Stdctrls::TListBox* LBLinkedColumns;
	Vcl::Extctrls::TPanel* Panel23;
	Vcl::Stdctrls::TLabel* Label7;
	Cxbuttons::TcxButton* BColumnLink;
	Cxbuttons::TcxButton* BColumnUnlink;
	Vcl::Extctrls::TSplitter* Splitter2;
	Vcl::Extctrls::TPanel* PGSeparator;
	Vcl::Menus::TMenuItem* N1;
	Cxbuttons::TcxButton* BColumnMoveUp;
	Cxbuttons::TcxButton* BColumnMoveDown;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* MIColumnMoveUp;
	Vcl::Menus::TMenuItem* MIColumnMoveDown;
	Vcl::Menus::TPopupMenu* PMFooterSummary;
	Vcl::Menus::TMenuItem* MIFooterSummaryAdd;
	Vcl::Menus::TMenuItem* MIFooterSummaryDelete;
	Vcl::Menus::TMenuItem* MenuItem4a;
	Vcl::Menus::TMenuItem* MIFooterSummarySelectAll;
	Vcl::Menus::TPopupMenu* PMDefaultGroupsSummary;
	Vcl::Menus::TMenuItem* MIDefaultGroupSummaryAdd;
	Vcl::Menus::TMenuItem* MIDefaultGroupSummaryDelete;
	Vcl::Menus::TMenuItem* MenuItem3b;
	Vcl::Menus::TMenuItem* MIDefaultGroupSummarySelectAll;
	Vcl::Menus::TPopupMenu* PMSummaryGroups;
	Vcl::Menus::TMenuItem* MISummaryGroupAdd;
	Vcl::Menus::TMenuItem* MISummaryGroupDelete;
	Vcl::Menus::TMenuItem* MenuItem5d;
	Vcl::Menus::TMenuItem* MISummaryGroupSelectAll;
	Vcl::Menus::TPopupMenu* PMGroupSummaryItems;
	Vcl::Menus::TMenuItem* MIGroupSummaryItemsAdd;
	Vcl::Menus::TMenuItem* MIGroupSummaryItemsDelete;
	Vcl::Menus::TMenuItem* MenuItem6c;
	Vcl::Menus::TMenuItem* MIGroupSummaryItemsSelectAll;
	Vcl::Extctrls::TPanel* Panel8;
	Vcl::Stdctrls::TListBox* LBColumns;
	Vcl::Extctrls::TPanel* Panel9;
	Vcl::Extctrls::TPanel* Panel10;
	Vcl::Extctrls::TPanel* Panel13;
	Vcl::Extctrls::TPanel* Panel16;
	Vcl::Extctrls::TPanel* Panel17;
	Vcl::Extctrls::TPanel* Panel18;
	Cxbuttons::TcxButton* BColumnAddMissing;
	void __fastcall LBColumnsClick(System::TObject* Sender);
	void __fastcall BColumnAddClick(System::TObject* Sender);
	void __fastcall BColumnDeleteClick(System::TObject* Sender);
	void __fastcall BColumnRestoreClick(System::TObject* Sender);
	void __fastcall MIColumnSelectAllClick(System::TObject* Sender);
	void __fastcall LBFooterSummaryClick(System::TObject* Sender);
	void __fastcall BAddFooterSummaryItemClick(System::TObject* Sender);
	void __fastcall BDeleteFooterSummaryItemClick(System::TObject* Sender);
	void __fastcall LBDefaultGroupsSummaryClick(System::TObject* Sender);
	void __fastcall BDefaultGroupSummaryAddClick(System::TObject* Sender);
	void __fastcall BDefaultGroupSummaryDeleteClick(System::TObject* Sender);
	void __fastcall LBSummaryGroupsClick(System::TObject* Sender);
	void __fastcall BSummaryGroupAddClick(System::TObject* Sender);
	void __fastcall BSummaryGroupDeleteClick(System::TObject* Sender);
	void __fastcall LBGroupSummaryItemsClick(System::TObject* Sender);
	void __fastcall BGroupSummaryItemAddClick(System::TObject* Sender);
	void __fastcall BGroupSummaryItemDeleteClick(System::TObject* Sender);
	void __fastcall LBUnlinkedColumnsClick(System::TObject* Sender);
	void __fastcall BColumnLinkClick(System::TObject* Sender);
	void __fastcall BColumnUnlinkClick(System::TObject* Sender);
	void __fastcall BColumnAddAllClick(System::TObject* Sender);
	void __fastcall PLinksResize(System::TObject* Sender);
	void __fastcall PSummaryGroupsResize(System::TObject* Sender);
	void __fastcall LBColumnsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall LBColumnsEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall LBColumnsStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall LBColumnsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall BColumnMoveUpClick(System::TObject* Sender);
	void __fastcall BColumnMoveDownClick(System::TObject* Sender);
	void __fastcall MIFooterSummarySelectAllClick(System::TObject* Sender);
	void __fastcall MIDefaultGroupSummarySelectAllClick(System::TObject* Sender);
	void __fastcall MISummaryGroupSelectAllClick(System::TObject* Sender);
	void __fastcall MIGroupSummaryItemsSelectAllClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall LBColumnsDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall BColumnAddMissingClick(System::TObject* Sender);
	
private:
	int FColumnsPrevDragIndex;
	Cxcustomdata::TcxDataSummaryGroup* FSummaryGroup;
	Cxcustomdata::TcxDataGroupSummaryItems* __fastcall GetDefaultGroupSummaryItems(void);
	Cxcustomdata::TcxDataFooterSummaryItems* __fastcall GetFooterSummaryItems(void);
	Cxcustomdata::TcxDataSummaryGroups* __fastcall GetSummaryGroups(void);
	Cxgridcustomtableview::TcxCustomGridTableView* __fastcall GetView(void);
	void __fastcall SetSummaryGroup(Cxcustomdata::TcxDataSummaryGroup* Value);
	void __fastcall ReindexColumnsProc(System::Classes::TList* AList, int ANewIndex);
	void __fastcall UpdateSummaryGroupLinks(void);
	void __fastcall UpdateSummaryGroups(void);
	
protected:
	void __fastcall CalculateListBoxItemHeight(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall CollectionItemsAdd(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TCollection* ACollection);
	void __fastcall CollectionItemsDelete(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TCollection* ACollection);
	void __fastcall DoCreateViewItems(bool AMissingItemsOnly);
	virtual void __fastcall DrawListBoxItem(Vcl::Controls::TWinControl* AListBox, int AIndex, const System::Types::TRect &R);
	Cxcustomdata::TcxDataSummaryGroup* __fastcall GetCurrentGroup(void);
	virtual System::UnicodeString __fastcall GetDeleteItemsCaption(void);
	void __fastcall SelectAllColumns(void);
	virtual void __fastcall UpdateButtons(void);
	virtual void __fastcall UpdateColumnList(void);
	virtual void __fastcall UpdateEditor(void);
	virtual void __fastcall UpdateSelection(void);
	void __fastcall UpdateSummary(void);
	void __fastcall UpdateSummarySelection(void);
	__property Cxcustomdata::TcxDataSummaryGroup* SummaryGroup = {read=FSummaryGroup, write=SetSummaryGroup};
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetViewByObject(System::Classes::TPersistent* APersistent);
	__property Cxcustomdata::TcxDataGroupSummaryItems* DefaultGroupSummaryItems = {read=GetDefaultGroupSummaryItems};
	__property Cxcustomdata::TcxDataFooterSummaryItems* FooterSummaryItems = {read=GetFooterSummaryItems};
	__property Cxcustomdata::TcxDataSummaryGroups* SummaryGroups = {read=GetSummaryGroups};
	__property Cxgridcustomtableview::TcxCustomGridTableView* View = {read=GetView};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxCustomTableViewEditor(System::Classes::TComponent* AOwner) : Cxvieweditor::TcxViewEditor(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomTableViewEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxvieweditor::TcxViewEditor(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxCustomTableViewEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomTableViewEditor(HWND ParentWindow) : Cxvieweditor::TcxViewEditor(ParentWindow) { }
	
};


class DELPHICLASS TcxCustomGridTableViewStorage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableViewStorage : public Cxvieweditor::TcxCustomGridViewStorage
{
	typedef Cxvieweditor::TcxCustomGridViewStorage inherited;
	
private:
	Cxnavigator::TcxNavigatorControlButtons* __fastcall GetNavigatorButtons(void);
	
protected:
	Cxgridcustomtableview::TcxCustomGridTableView* __fastcall CustomTableView(void);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
	
__published:
	__property Cxnavigator::TcxNavigatorControlButtons* NavigatorButtons = {read=GetNavigatorButtons};
public:
	/* TcxCustomGridViewStorage.Create */ inline __fastcall virtual TcxCustomGridTableViewStorage(Cxgridcustomview::TcxCustomGridView* AView) : Cxvieweditor::TcxCustomGridViewStorage(AView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridTableViewStorage(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableViewMenuProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableViewMenuProvider : public Cxvieweditor::TcxCustomGridViewMenuProvider
{
	typedef Cxvieweditor::TcxCustomGridViewMenuProvider inherited;
	
private:
	Cxgridcustomtableview::TcxCustomGridTableView* __fastcall GetGridView(void);
	System::UnicodeString __fastcall GetViewItemNameValue(void);
	
protected:
	bool __fastcall CanDeleteItems(void);
	void __fastcall CreateAllItems(Cxvieweditor::TcxGridViewMenuItem* Sender);
	void __fastcall CreateItem(Cxvieweditor::TcxGridViewMenuItem* Sender);
	void __fastcall CreateMissingItems(Cxvieweditor::TcxGridViewMenuItem* Sender);
	void __fastcall DeleteAllItems(Cxvieweditor::TcxGridViewMenuItem* Sender);
	virtual void __fastcall InitStructureCreationItems(void);
	virtual void __fastcall InitStructureItems(void);
	__property System::UnicodeString ViewItemName = {read=GetViewItemNameValue};
	
public:
	__property Cxgridcustomtableview::TcxCustomGridTableView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridViewMenuProvider.Create */ inline __fastcall virtual TcxCustomGridTableViewMenuProvider(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxvieweditor::TcxCustomGridViewMenuProvider(AGridView) { }
	/* TcxCustomGridViewMenuProvider.Destroy */ inline __fastcall virtual ~TcxCustomGridTableViewMenuProvider(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxcustomtablevieweditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCUSTOMTABLEVIEWEDITOR)
using namespace Cxcustomtablevieweditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcustomtablevieweditorHPP
