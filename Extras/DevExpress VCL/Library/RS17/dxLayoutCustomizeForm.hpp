// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutCustomizeForm.pas' rev: 24.00 (Win32)

#ifndef DxlayoutcustomizeformHPP
#define DxlayoutcustomizeformHPP

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
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxLayoutControl.hpp>	// Pascal unit
#include <dxLayoutDragAndDrop.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <dxLayoutcxEditAdapters.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <dxLayoutControlAdapters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutcustomizeform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxLayoutControlCustomizeForm;
class PASCALIMPLEMENTATION TdxLayoutControlCustomizeForm : public Dxlayoutcontainer::TdxLayoutControlCustomCustomizeForm
{
	typedef Dxlayoutcontainer::TdxLayoutControlCustomCustomizeForm inherited;
	
__published:
	Vcl::Actnlist::TActionList* alMain;
	Vcl::Actnlist::TAction* acAddGroup;
	Vcl::Actnlist::TAction* acAddItem;
	Vcl::Actnlist::TAction* acClose;
	Vcl::Actnlist::TAction* acTreeViewExpandAll;
	Vcl::Actnlist::TAction* acTreeViewCollapseAll;
	Vcl::Actnlist::TAction* acTreeViewItemsDelete;
	Vcl::Actnlist::TAction* acAlignLeftSide;
	Vcl::Actnlist::TAction* acAlignRightSide;
	Vcl::Actnlist::TAction* acAlignTopSide;
	Vcl::Actnlist::TAction* acAlignBottomSide;
	Vcl::Actnlist::TAction* acAlignNone;
	Cxgraphics::TcxImageList* ilActions;
	Cxgraphics::TcxImageList* ilItems;
	Vcl::Menus::TPopupMenu* pmTreeViewActions;
	Vcl::Menus::TMenuItem* miExpandAll;
	Vcl::Menus::TMenuItem* miCallapseAll;
	Vcl::Menus::TMenuItem* miSeparator1;
	Vcl::Menus::TMenuItem* miTreeViewDelete;
	Vcl::Menus::TMenuItem* miSeparator2;
	Vcl::Menus::TMenuItem* miAlignBy;
	Vcl::Menus::TPopupMenu* pmAvailableItemsActions;
	Vcl::Menus::TMenuItem* AddGroup1;
	Vcl::Menus::TMenuItem* AddItem1;
	Vcl::Menus::TMenuItem* Delete1;
	Vcl::Menus::TPopupMenu* pmAlign;
	Vcl::Menus::TMenuItem* Left1;
	Vcl::Menus::TMenuItem* Right1;
	Vcl::Menus::TMenuItem* op1;
	Vcl::Menus::TMenuItem* Bottom1;
	Vcl::Menus::TMenuItem* miSeparator3;
	Vcl::Menus::TMenuItem* miSeparator4;
	Vcl::Menus::TMenuItem* None1;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainGroup_Root;
	Dxlayoutcontrol::TdxLayoutControl* lcMain;
	Dxlayoutcontainer::TdxLayoutGroup* lcgTreeView;
	Dxlayoutcontainer::TdxLayoutGroup* lcgAvailableItems;
	Vcl::Actnlist::TAction* acAvailableItemsDelete;
	Vcl::Actnlist::TAction* acAvailableItemsExpandAll;
	Vcl::Actnlist::TAction* acAvailableItemsCollapseAll;
	Vcl::Actnlist::TAction* acAvailableItemsViewAsList;
	Vcl::Actnlist::TAction* acTabbedView;
	Vcl::Actnlist::TAction* acHighlightRoot;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainGroup1;
	Vcl::Actnlist::TAction* acShowDesignSelectors;
	Vcl::Actnlist::TAction* acStore;
	Vcl::Actnlist::TAction* acRestore;
	Cxgraphics::TcxImageList* ilHelper;
	Vcl::Actnlist::TAction* acTreeViewItemRename;
	Vcl::Menus::TMenuItem* miTreeViewItemRename;
	Vcl::Menus::TMenuItem* Rename2;
	Vcl::Actnlist::TAction* acAvailableItemRename;
	Vcl::Actnlist::TAction* acUndo;
	Vcl::Actnlist::TAction* acRedo;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* Undo1;
	Vcl::Menus::TMenuItem* Redo1;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* Undo2;
	Vcl::Menus::TMenuItem* Redo2;
	Vcl::Actnlist::TAction* acAlignBy;
	Cxtreeview::TcxTreeView* tvItems;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem6;
	Cxtreeview::TcxTreeView* tvAvailableItems;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem8;
	Cxbuttons::TcxButton* btnClose;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem1;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainGroup3;
	Cxcheckbox::TcxCheckBox* cbTabbedView;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem4;
	Dxlayoutcontainer::TdxLayoutItem* liShowDesignSelectors;
	Cxbuttons::TcxButton* btnShowDesignSelectors;
	Dxlayoutcontainer::TdxLayoutItem* liHighlightRoot;
	Cxbuttons::TcxButton* btnHighlightRoot;
	Dxlayoutcontainer::TdxLayoutItem* liRestore;
	Cxbuttons::TcxButton* btnRestore;
	Dxlayoutcontainer::TdxLayoutItem* liStore;
	Cxbuttons::TcxButton* btnStore;
	Dxlayoutcontainer::TdxLayoutItem* liRedo;
	Cxbuttons::TcxButton* btnRedo;
	Dxlayoutcontainer::TdxLayoutItem* liUndo;
	Cxbuttons::TcxButton* btnUndo;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainGroup2;
	Dxlayoutcontainer::TdxLayoutItem* liAlignBy;
	Cxbuttons::TcxButton* btnAlignBy;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem7;
	Cxbuttons::TcxButton* btnTreeViewItemsDelete;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem9;
	Cxbuttons::TcxButton* btnTreeViewCollapseAll;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem10;
	Cxbuttons::TcxButton* btnTreeViewExpandAll;
	Dxlayoutcontainer::TdxLayoutGroup* lgTreeView;
	Dxlayoutcontainer::TdxLayoutGroup* lgAvailableItems;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem3;
	Cxbuttons::TcxButton* btnAvailableItemsViewAsList;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem11;
	Cxbuttons::TcxButton* btnAvailableItemsDelete;
	Dxlayoutcontainer::TdxLayoutItem* liAddCustomItem;
	Cxbuttons::TcxButton* btnAddItem;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem13;
	Cxbuttons::TcxButton* btnAddGroup;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem14;
	Cxbuttons::TcxButton* btnAvailableItemsCollapseAll;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem15;
	Cxbuttons::TcxButton* btnAvailableItemsExpandAll;
	Vcl::Actnlist::TAction* acHAlignLeft;
	Vcl::Actnlist::TAction* acHAlignCenter;
	Vcl::Actnlist::TAction* acHAlignRight;
	Vcl::Actnlist::TAction* acHAlignClient;
	Vcl::Actnlist::TAction* acHAlignParent;
	Vcl::Menus::TMenuItem* miAlignHorz;
	Vcl::Menus::TMenuItem* miHLeft;
	Vcl::Menus::TMenuItem* miHCenter;
	Vcl::Menus::TMenuItem* miHRight;
	Vcl::Menus::TMenuItem* miHClient;
	Vcl::Menus::TMenuItem* miHParentManaged;
	Vcl::Actnlist::TAction* acVAlignTop;
	Vcl::Actnlist::TAction* acVAlignBottom;
	Vcl::Actnlist::TAction* acVAlignCenter;
	Vcl::Actnlist::TAction* acVAlignClient;
	Vcl::Actnlist::TAction* acVAlignParent;
	Vcl::Menus::TMenuItem* miAlignVert;
	Vcl::Menus::TMenuItem* miVAlignTop;
	Vcl::Menus::TMenuItem* miVAlignCenter;
	Vcl::Menus::TMenuItem* miVAlignBottom;
	Vcl::Menus::TMenuItem* miVAlignClient;
	Vcl::Menus::TMenuItem* miVAlignParent;
	Vcl::Actnlist::TAction* acDirectionHorizontal;
	Vcl::Actnlist::TAction* acDirectionVertical;
	Vcl::Actnlist::TAction* acDirectionTabbed;
	Vcl::Menus::TMenuItem* miDirection;
	Vcl::Menus::TMenuItem* miDirectionHorizontal;
	Vcl::Menus::TMenuItem* miDirectionVertical;
	Vcl::Menus::TMenuItem* miDirectionTabbed;
	Vcl::Actnlist::TAction* acAddEmptySpaceItem;
	Vcl::Actnlist::TAction* acBorder;
	Vcl::Menus::TMenuItem* miBorder;
	Vcl::Actnlist::TAction* acAddSeparator;
	Vcl::Menus::TMenuItem* AddEmptySpaceItem1;
	Vcl::Menus::TMenuItem* acAddSeparator1;
	Vcl::Actnlist::TAction* acAddSplitter;
	Vcl::Actnlist::TAction* acAddLabeledItem;
	Vcl::Menus::TPopupMenu* pmAddCustomItem;
	Vcl::Menus::TMenuItem* AddEmptySpaceItem2;
	Vcl::Menus::TMenuItem* acAddLabeledItem1;
	Vcl::Menus::TMenuItem* acAddSeparator2;
	Vcl::Menus::TMenuItem* acAddSplitter1;
	Vcl::Actnlist::TAction* acAddCustomItem;
	Vcl::Menus::TMenuItem* AddSplitter1;
	Vcl::Menus::TMenuItem* AddLabel1;
	Dxlayoutcontainer::TdxLayoutSeparatorItem* lcMainSeparatorItem1;
	Dxlayoutcontainer::TdxLayoutSeparatorItem* lcMainSeparatorItem2;
	Vcl::Menus::TMenuItem* N3;
	Dxlayoutcontainer::TdxLayoutSeparatorItem* lcMainSeparatorItem3;
	Dxlayoutcontainer::TdxLayoutSeparatorItem* lsAlignBy;
	Vcl::Menus::TMenuItem* N4;
	Vcl::Menus::TMenuItem* ExpandAll1;
	Vcl::Menus::TMenuItem* CallapseAll1;
	Dxlayoutcontainer::TdxLayoutItem* liAddItem;
	Cxbuttons::TcxButton* cxButton1;
	Dxlayoutcontainer::TdxLayoutSeparatorItem* lsSeparator4;
	Vcl::Actnlist::TAction* acExpandButton;
	Vcl::Menus::TMenuItem* miExpandButton;
	Vcl::Menus::TMenuItem* miTextPosition;
	Vcl::Menus::TMenuItem* miTextPositionLeft;
	Vcl::Menus::TMenuItem* miTextPositionTop;
	Vcl::Menus::TMenuItem* miTextPositionRight;
	Vcl::Menus::TMenuItem* miTextPositionBottom;
	Vcl::Actnlist::TAction* acTextPositionLeft;
	Vcl::Actnlist::TAction* acTextPositionTop;
	Vcl::Actnlist::TAction* acTextPositionRight;
	Vcl::Actnlist::TAction* acTextPositionBottom;
	Vcl::Menus::TMenuItem* miCaptionAlignHorz;
	Vcl::Menus::TMenuItem* miCaptionAlignHorzLeft;
	Vcl::Menus::TMenuItem* miCaptionAlignHorzCenter;
	Vcl::Menus::TMenuItem* miCaptionAlignHorzRight;
	Vcl::Actnlist::TAction* acCaptionAlignHorzLeft;
	Vcl::Actnlist::TAction* acCaptionAlignHorzCenter;
	Vcl::Actnlist::TAction* acCaptionAlignHorzRight;
	Vcl::Menus::TMenuItem* miCaption;
	Vcl::Actnlist::TAction* acCaption;
	Vcl::Menus::TMenuItem* miCaptionAlignVert;
	Vcl::Menus::TMenuItem* miCaptionAlignVertTop;
	Vcl::Menus::TMenuItem* miCaptionAlignVertCenter;
	Vcl::Menus::TMenuItem* miCaptionAlignVertBottom;
	Vcl::Actnlist::TAction* acCaptionAlignVertTop;
	Vcl::Actnlist::TAction* acCaptionAlignVertCenter;
	Vcl::Actnlist::TAction* acCaptionAlignVertBottom;
	Vcl::Menus::TMenuItem* miGroup;
	Vcl::Menus::TMenuItem* miUngroup;
	Vcl::Actnlist::TAction* acGroup;
	Vcl::Actnlist::TAction* acUngroup;
	Vcl::Menus::TMenuItem* N5;
	Vcl::Menus::TMenuItem* N6;
	Vcl::Menus::TMenuItem* N7;
	void __fastcall acCloseExecute(System::TObject* Sender);
	void __fastcall acAddGroupExecute(System::TObject* Sender);
	void __fastcall acAddItemExecute(System::TObject* Sender);
	void __fastcall tvItemsEdited(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, System::UnicodeString &S);
	void __fastcall tvItemsMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ItemsMouseMove(System::TObject* Sender, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ItemsMouseUp(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall tvItemsChange(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall tvItemsChanging(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowChange);
	void __fastcall AlignExecute(System::TObject* Sender);
	void __fastcall acTreeViewItemsDeleteExecute(System::TObject* Sender);
	void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall tvItemsContextPopup(System::TObject* Sender, const System::Types::TPoint &MousePos, bool &Handled);
	void __fastcall acAvailableItemsDeleteExecute(System::TObject* Sender);
	void __fastcall tvItemsCustomDrawItem(Vcl::Comctrls::TCustomTreeView* Sender, Vcl::Comctrls::TTreeNode* Node, Vcl::Comctrls::TCustomDrawState State, bool &DefaultDraw);
	void __fastcall tvAvailableItemsContextPopup(System::TObject* Sender, const System::Types::TPoint &MousePos, bool &Handled);
	void __fastcall acAvailableItemsExpandAllExecute(System::TObject* Sender);
	void __fastcall acAvailableItemsCollapseAllExecute(System::TObject* Sender);
	void __fastcall acTreeViewExpandAllExecute(System::TObject* Sender);
	void __fastcall acTreeViewCollapseAllExecute(System::TObject* Sender);
	void __fastcall acAvailableItemsViewAsListExecute(System::TObject* Sender);
	void __fastcall tvItemsEditing(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowEdit);
	void __fastcall FormShortCut(Winapi::Messages::TWMKey &Msg, bool &Handled);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall acTabbedViewExecute(System::TObject* Sender);
	void __fastcall acHighlightRootExecute(System::TObject* Sender);
	void __fastcall acShowDesignSelectorsExecute(System::TObject* Sender);
	void __fastcall acStoreExecute(System::TObject* Sender);
	void __fastcall acRestoreExecute(System::TObject* Sender);
	void __fastcall acTreeViewItemRenameExecute(System::TObject* Sender);
	void __fastcall acAvailableItemRenameExecute(System::TObject* Sender);
	void __fastcall acUndoExecute(System::TObject* Sender);
	void __fastcall acRedoExecute(System::TObject* Sender);
	void __fastcall acAlignByExecute(System::TObject* Sender);
	void __fastcall acHAlignExecute(System::TObject* Sender);
	void __fastcall pmTreeViewActionsPopup(System::TObject* Sender);
	void __fastcall acVAlignExecute(System::TObject* Sender);
	void __fastcall acDirectionsExecute(System::TObject* Sender);
	void __fastcall acAddEmptySpaceItemExecute(System::TObject* Sender);
	void __fastcall acBorderExecute(System::TObject* Sender);
	void __fastcall acAddSeparatorExecute(System::TObject* Sender);
	void __fastcall acAddCustomItemExecute(System::TObject* Sender);
	void __fastcall acAddLabeledItemExecute(System::TObject* Sender);
	void __fastcall acAddSplitterExecute(System::TObject* Sender);
	void __fastcall tvItemsDeletion(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall acExpandButtonExecute(System::TObject* Sender);
	void __fastcall acTextPositionExecute(System::TObject* Sender);
	void __fastcall acCaptionAlignHorzExecute(System::TObject* Sender);
	void __fastcall acCaptionExecute(System::TObject* Sender);
	void __fastcall acCaptionAlignVertExecute(System::TObject* Sender);
	void __fastcall acGroupExecute(System::TObject* Sender);
	void __fastcall acUngroupExecute(System::TObject* Sender);
	
private:
	Dxlayoutdraganddrop::TdxLayoutDragAndDropHelper* FDragHelper;
	Cxclasses::TcxComponentList* FCollapsedAvailableItems;
	Cxclasses::TcxComponentList* FCollapsedItems;
	int FLockCount;
	Cxcontrols::TcxWindowProcLinkedObject* FAvailableItemsWindowProcLinkedObject;
	Cxcontrols::TcxWindowProcLinkedObject* FItemsWindowProcLinkedObject;
	void __fastcall AddItemNode(Vcl::Comctrls::TTreeNodes* ANodes, Vcl::Comctrls::TTreeNode* AParentNode, Dxlayoutcontainer::TdxCustomLayoutItem* AItem, bool AAddChildren = true);
	void __fastcall AvailableItemsWndProc(Winapi::Messages::TMessage &Message);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall CreateItem(Dxlayoutcontainer::TdxCustomLayoutItemClass AClass, const System::UnicodeString ACaption);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall DoCreateItem(Dxlayoutcontainer::TdxCustomLayoutItemClass AClass, const System::UnicodeString ACaption);
	void __fastcall DoAfterInsertionItem(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	int __fastcall GetImageIndex(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	bool __fastcall GetIsLocked(void);
	Dxlayoutcontainer::TdxLayoutCustomizeFormMenuItems __fastcall GetMenuItems(void);
	bool __fastcall HasClassInSelection(System::TClass AClass);
	void __fastcall InitializePopupMenu(void);
	bool __fastcall IsHiddenGroup(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	void __fastcall ItemsWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall RefreshImages(void);
	void __fastcall RefreshLists(bool ARefreshSelection = false);
	void __fastcall RefreshNode(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall RefreshButtonStates(void);
	void __fastcall RefreshView(void);
	void __fastcall SaveToUndo(void);
	bool __fastcall CanSelectItem(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	void __fastcall SelectItem(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	void __fastcall SetItemsSelections(System::Classes::TList* AList);
	void __fastcall SetLayoutItemsSelections(Vcl::Comctrls::TTreeView* ATreeView);
	bool __fastcall TreeViewWndProcHandler(Vcl::Comctrls::TTreeView* ATreeView, Winapi::Messages::TMessage &Message);
	void __fastcall RestoreCollapsedNodes(Vcl::Comctrls::TTreeView* ATreeView, Cxclasses::TcxComponentList* AList);
	void __fastcall StoreCollapsedNodes(Vcl::Comctrls::TTreeView* ATreeView, Cxclasses::TcxComponentList* AList);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall CanModify(void);
	virtual void __fastcall DoInitializeControl(void);
	virtual void __fastcall ItemChanged(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	virtual void __fastcall InitializeControl(void);
	virtual Vcl::Menus::TPopupMenu* __fastcall GetLayoutPopupMenu(void);
	bool __fastcall CanDeleteItems(Cxtreeview::TcxTreeView* ATreeView);
	void __fastcall DeleteItems(System::Contnrs::TComponentList* AList, Vcl::Comctrls::TTreeView* ATreeView);
	bool __fastcall GetNode(Dxlayoutcontainer::TdxCustomLayoutItem* AItem, /* out */ Vcl::Comctrls::TTreeNode* &ANode);
	virtual void __fastcall Localize(void);
	void __fastcall RefreshAvailableItems(void);
	virtual void __fastcall RefreshEnableds(void);
	virtual void __fastcall RefreshLayoutLookAndFeel(void);
	virtual void __fastcall RefreshStoring(void);
	void __fastcall RefreshTreeView(void);
	virtual void __fastcall CalculateTreeViewPopupActionEnables(void);
	virtual void __fastcall CalculateTreeViewPopupActionVisibilities(void);
	bool __fastcall HasLabeledItemInSelection(void);
	bool __fastcall HasGroupInSelection(void);
	bool __fastcall HasDirectionalItemInSelection(void);
	bool __fastcall HasRootInSelection(void);
	bool __fastcall HasHiddenGroupInSelection(void);
	bool __fastcall HasLockedItemInSelection(void);
	bool __fastcall HasLockedGroupInSelection(void);
	virtual void __fastcall SynchronizeTreeViewPopupActionStates(void);
	void __fastcall StoreTreeViewWndProc(Vcl::Comctrls::TTreeView* ATreeView, /* out */ Cxcontrols::TcxWindowProcLinkedObject* &AWindowProcObject, System::Classes::TWndMethod ANewWndMethod);
	void __fastcall RestoreTreeViewWndProc(Cxcontrols::TcxWindowProcLinkedObject* &AWindowProcObject);
	__property Dxlayoutdraganddrop::TdxLayoutDragAndDropHelper* DragHelper = {read=FDragHelper};
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	__property int LockCount = {read=FLockCount, nodefault};
	
public:
	__fastcall virtual TdxLayoutControlCustomizeForm(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxLayoutControlCustomizeForm(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual void __fastcall ToggleHotTrackState(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall UpdateAvailableItems(void);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall UpdateContent(void);
	virtual void __fastcall UpdateDragAndDropState(void);
	virtual void __fastcall UpdateSelection(void);
	virtual void __fastcall UpdateView(void);
	virtual void __fastcall UpdateVisibleItems(void);
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxLayoutControlCustomizeForm(System::Classes::TComponent* AOwner, int Dummy) : Dxlayoutcontainer::TdxLayoutControlCustomCustomizeForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxLayoutControlCustomizeForm(HWND ParentWindow) : Dxlayoutcontainer::TdxLayoutControlCustomCustomizeForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall cxTreeViewGetSelection(Vcl::Comctrls::TTreeView* ATreeView, System::Classes::TList* AList);
extern PACKAGE void __fastcall cxTreeViewSyncSelection(Vcl::Comctrls::TTreeView* ATreeView, System::Classes::TList* AList);
}	/* namespace Dxlayoutcustomizeform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTCUSTOMIZEFORM)
using namespace Dxlayoutcustomizeform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutcustomizeformHPP
