// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSXplorerTreeView.pas' rev: 24.00 (Win32)

#ifndef DxpsxplorertreeviewHPP
#define DxpsxplorertreeviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsxplorertreeview
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxTreeViewClass;

class DELPHICLASS TCustomdxPSExplorerTreeViewContainer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TCustomdxPSExplorerTreeViewContainer : public Dxpscore::TCustomdxPSExplorerTreeContainer
{
	typedef Dxpscore::TCustomdxPSExplorerTreeContainer inherited;
	
private:
	System::Classes::TMemoryStream* FStorageStream;
	Vcl::Comctrls::TTreeNode* __fastcall GetFocusedNode(void);
	Vcl::Comctrls::TTreeNode* __fastcall GetRootNode(void);
	Cxtreeview::TcxTreeView* __fastcall GetTreeView(void);
	void __fastcall TreeCancelEdit(System::TObject* Sender, Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall TreeChanged(System::TObject* Sender, Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall TreeCollapsing(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowCollapse);
	void __fastcall TreeCustomDrawItem(Vcl::Comctrls::TCustomTreeView* Sender, Vcl::Comctrls::TTreeNode* Node, Vcl::Comctrls::TCustomDrawState State, bool &DefaultDraw);
	void __fastcall TreeDblClick(System::TObject* Sender);
	void __fastcall TreeDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall TreeDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall TreeEdited(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, System::UnicodeString &S);
	void __fastcall TreeEditing(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowEdit);
	void __fastcall TreeExpanding(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowExpansion);
	void __fastcall TreeKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall TreeKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall TreeMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall ReadTreeViewState(void);
	void __fastcall WriteTreeViewState(void);
	
protected:
	virtual void __fastcall AddItem(Dxpscore::TdxPSExplorerFolder* AParent, Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall Clear(void);
	virtual void __fastcall DeleteItem(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall InvalidateItem(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall MoveItem(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall RenameItem(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual Dxpscore::TdxPSExplorerFolder* __fastcall GetCreationParent(void);
	virtual Dxpscore::TCustomdxPSExplorerItem* __fastcall GetFocusedItem(void);
	virtual bool __fastcall GetIsEditing(void);
	virtual bool __fastcall GetIsFolderSelected(void);
	virtual bool __fastcall GetIsItemSelected(void);
	virtual bool __fastcall GetIsRootSelected(void);
	virtual Dxpscore::TdxPSExplorerFolder* __fastcall GetSelectedFolder(void);
	virtual Dxpscore::TCustomdxPSExplorerItem* __fastcall GetSelectedItem(void);
	virtual System::UnicodeString __fastcall GetSelectedItemText(void);
	virtual void __fastcall SetFocusedItem(Dxpscore::TCustomdxPSExplorerItem* Value);
	virtual void __fastcall SetSelectedItem(Dxpscore::TCustomdxPSExplorerItem* Value);
	virtual void __fastcall SetSelectedItemText(const System::UnicodeString Value);
	virtual void __fastcall RestoreState(void);
	virtual void __fastcall SaveState(void);
	virtual void __fastcall InitializeTreeContainer(void);
	virtual Vcl::Comctrls::TTreeNode* __fastcall AddNode(Vcl::Comctrls::TTreeNode* AParent, Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall CanDragNode(Vcl::Comctrls::TTreeNode* ANode);
	Vcl::Comctrls::THitTests __fastcall GetHitTestInfoAt(int X, int Y);
	Dxpscore::TCustomdxPSExplorerItem* __fastcall GetItemByNode(Vcl::Comctrls::TTreeNode* ANode);
	Vcl::Comctrls::TTreeNode* __fastcall GetNodeByItem(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	__property Vcl::Comctrls::TTreeNode* FocusedNode = {read=GetFocusedNode};
	__property Vcl::Comctrls::TTreeNode* RootNode = {read=GetRootNode};
	__property Cxtreeview::TcxTreeView* TreeView = {read=GetTreeView};
	
public:
	virtual bool __fastcall BeginEdit(bool AnImmediate = true);
	virtual void __fastcall EndEdit(bool ACancel);
	__classmethod virtual Vcl::Controls::TWinControlClass __fastcall ControlClass();
	__classmethod virtual TcxTreeViewClass __fastcall TreeViewClass();
	virtual void __fastcall CollapseItem(Dxpscore::TCustomdxPSExplorerItem* AnItem, bool ARecursive = false);
	virtual void __fastcall ExpandItem(Dxpscore::TCustomdxPSExplorerItem* AnItem, bool ARecursive = false);
	virtual void __fastcall ItemDataLoaded(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall ItemDataUnloaded(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall MakeItemVisible(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall EndUpdate(void);
	virtual void __fastcall RefreshSorting(System::TObject* ANode)/* overload */;
	virtual void __fastcall RefreshSorting(Dxpscore::TdxPSExplorerFolder* AFolder)/* overload */;
	virtual Dxpscore::TdxPSExplorerFolder* __fastcall GetDropTarget(int X, int Y);
	virtual Dxpscore::TCustomdxPSExplorerItem* __fastcall GetItemAt(int X, int Y);
	Dxpscore::TCustomdxPSExplorerItem* __fastcall GetItemAtMousePos(void);
public:
	/* TCustomdxPSExplorerTreeContainer.Create */ inline __fastcall virtual TCustomdxPSExplorerTreeViewContainer(Dxpscore::TCustomdxPSExplorer* AnExplorer, Dxpscore::_di_IdxPSExplorerTreeContainerHost AHost) : Dxpscore::TCustomdxPSExplorerTreeContainer(AnExplorer, AHost) { }
	/* TCustomdxPSExplorerTreeContainer.Destroy */ inline __fastcall virtual ~TCustomdxPSExplorerTreeViewContainer(void) { }
	
};

#pragma pack(pop)

enum TdxPSExplorerTreeViewScrollArea : unsigned char { etsaLeft, etsaTop, etsaRight, etsaBottom };

typedef System::Set<TdxPSExplorerTreeViewScrollArea, TdxPSExplorerTreeViewScrollArea::etsaLeft, TdxPSExplorerTreeViewScrollArea::etsaBottom>  TdxPSExplorerTreeViewScrollAreas;

class DELPHICLASS TdxPSExplorerTreeView;
class PASCALIMPLEMENTATION TdxPSExplorerTreeView : public Cxtreeview::TcxTreeView
{
	typedef Cxtreeview::TcxTreeView inherited;
	
private:
	TCustomdxPSExplorerTreeViewContainer* FContainer;
	Vcl::Controls::TDragImageList* FDragImage;
	Vcl::Extctrls::TTimer* FExpandTimer;
	bool FFlat;
	Vcl::Comctrls::TTreeNode* FSavedDropTarget;
	TdxPSExplorerTreeViewScrollAreas FSavedScrollActiveAreas;
	Vcl::Extctrls::TTimer* FScrollTimer;
	bool __fastcall GetIsMouseInScrollArea(void);
	bool __fastcall GetIsMouseInScrollAreaBound(TdxPSExplorerTreeViewScrollArea ScrollArea);
	TdxPSExplorerTreeViewScrollAreas __fastcall GetScrollActiveAreas(void);
	System::Types::TRect __fastcall GetScrollAreaBounds(TdxPSExplorerTreeViewScrollArea ScrollArea);
	void __fastcall SetFlat(bool Value);
	void __fastcall OnExpandTimer(System::TObject* Sender);
	void __fastcall OnScrollTimer(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	
protected:
	virtual bool __fastcall CanEdit(Vcl::Comctrls::TTreeNode* Node);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DblClick(void);
	void __fastcall DoChange(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__classmethod virtual Cxtreeview::TcxCustomInnerTreeViewClass __fastcall GetTreeViewClass();
	virtual bool __fastcall CanDragNode(Vcl::Comctrls::TTreeNode* ANode);
	virtual void __fastcall DrawFlatEdge(void);
	System::UnicodeString __fastcall GetInfoTip(HTREEITEM AnItem);
	virtual Vcl::Graphics::TBitmap* __fastcall MakeDragBitmap(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall UpdateDragMode(Vcl::Comctrls::TTreeNode* ANode);
	__property TCustomdxPSExplorerTreeViewContainer* Container = {read=FContainer, write=FContainer};
	__property bool IsMouseInScrollArea = {read=GetIsMouseInScrollArea, nodefault};
	__property bool IsMouseInScrollAreaBounds[TdxPSExplorerTreeViewScrollArea ScrollArea] = {read=GetIsMouseInScrollAreaBound};
	__property TdxPSExplorerTreeViewScrollAreas ScrollActiveAreas = {read=GetScrollActiveAreas, nodefault};
	__property System::Types::TRect ScrollAreaBounds[TdxPSExplorerTreeViewScrollArea ScrollArea] = {read=GetScrollAreaBounds};
	
public:
	__fastcall virtual TdxPSExplorerTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual TdxPSExplorerTreeView(System::Classes::TComponent* AOwner, TCustomdxPSExplorerTreeViewContainer* AContainer);
	virtual Vcl::Controls::TDragImageList* __fastcall GetDragImages(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	__property bool Flat = {read=FFlat, write=SetFlat, nodefault};
public:
	/* TcxTreeViewContainer.Destroy */ inline __fastcall virtual ~TdxPSExplorerTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPSExplorerTreeView(HWND ParentWindow) : Cxtreeview::TcxTreeView(ParentWindow) { }
	
};


class DELPHICLASS TdxPSExplorerTreeViewContainer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSExplorerTreeViewContainer : public TCustomdxPSExplorerTreeViewContainer
{
	typedef TCustomdxPSExplorerTreeViewContainer inherited;
	
private:
	HIDESBASE TdxPSExplorerTreeView* __fastcall GetTreeView(void);
	
protected:
	virtual void __fastcall InitializeTreeContainer(void);
	
public:
	__classmethod virtual TcxTreeViewClass __fastcall TreeViewClass();
	__property TdxPSExplorerTreeView* TreeView = {read=GetTreeView};
public:
	/* TCustomdxPSExplorerTreeContainer.Create */ inline __fastcall virtual TdxPSExplorerTreeViewContainer(Dxpscore::TCustomdxPSExplorer* AnExplorer, Dxpscore::_di_IdxPSExplorerTreeContainerHost AHost) : TCustomdxPSExplorerTreeViewContainer(AnExplorer, AHost) { }
	/* TCustomdxPSExplorerTreeContainer.Destroy */ inline __fastcall virtual ~TdxPSExplorerTreeViewContainer(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPSExplorerInnerTreeView;
class PASCALIMPLEMENTATION TcxPSExplorerInnerTreeView : public Cxtreeview::TcxCustomInnerTreeView
{
	typedef Cxtreeview::TcxCustomInnerTreeView inherited;
	
private:
	TCustomdxPSExplorerTreeViewContainer* __fastcall GetTreeViewContainer(void);
	
protected:
	DYNAMIC bool __fastcall CanCollapse(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC bool __fastcall CanExpand(Vcl::Comctrls::TTreeNode* Node);
	__property TCustomdxPSExplorerTreeViewContainer* TreeViewContainer = {read=GetTreeViewContainer};
public:
	/* TcxCustomInnerTreeView.Create */ inline __fastcall virtual TcxPSExplorerInnerTreeView(System::Classes::TComponent* AOwner) : Cxtreeview::TcxCustomInnerTreeView(AOwner) { }
	/* TcxCustomInnerTreeView.Destroy */ inline __fastcall virtual ~TcxPSExplorerInnerTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPSExplorerInnerTreeView(HWND ParentWindow) : Cxtreeview::TcxCustomInnerTreeView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsxplorertreeview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSXPLORERTREEVIEW)
using namespace Dxpsxplorertreeview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsxplorertreeviewHPP
