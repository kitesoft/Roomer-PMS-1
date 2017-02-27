// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTreeView.pas' rev: 24.00 (Win64)

#ifndef CxtreeviewHPP
#define CxtreeviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtreeview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxBaseInnerTreeView;
class DELPHICLASS TcxTreeViewContainer;
class PASCALIMPLEMENTATION TcxBaseInnerTreeView : public Vcl::Comctrls::TTreeView
{
	typedef Vcl::Comctrls::TTreeView inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	void __fastcall HScrollHandler(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall VScrollHandler(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	HIDESBASE MESSAGE void __fastcall WMGestureNotify(Winapi::Messages::TWMGestureNotify &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	
protected:
	TcxTreeViewContainer* FContainer;
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	
public:
	__fastcall virtual TcxBaseInnerTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxBaseInnerTreeView(void);
	DYNAMIC bool __fastcall CanFocus(void);
	virtual void __fastcall DefaultHandler(void *Message);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxBaseInnerTreeView(HWND ParentWindow) : Vcl::Comctrls::TTreeView(ParentWindow) { }
	
private:
	void *__IcxContainerInnerControl;	/* Cxcontainer::IcxContainerInnerControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator Cxcontainer::_di_IcxContainerInnerControl()
	{
		Cxcontainer::_di_IcxContainerInnerControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxContainerInnerControl; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxContainerInnerControl; }
	#endif
	
};


typedef System::TMetaClass* TcxInnerTreeViewClass;

class DELPHICLASS TcxCustomInnerTreeView;
class DELPHICLASS TcxCustomTreeView;
class PASCALIMPLEMENTATION TcxCustomInnerTreeView : public TcxBaseInnerTreeView
{
	typedef TcxBaseInnerTreeView inherited;
	
private:
	bool FIsRedrawLocked;
	int FItemHeight;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TcxCustomTreeView* __fastcall GetContainer(void);
	void __fastcall SetItemHeight(int Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	MESSAGE void __fastcall WMSetRedraw(Winapi::Messages::TWMSetRedraw &Message);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMFontChange(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	
protected:
	virtual void __fastcall DestroyWindowHandle(void);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	__property TcxCustomTreeView* Container = {read=GetContainer};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	DYNAMIC void __fastcall Expand(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall Change(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall Collapse(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall UpdateItemHeight(void);
	__property bool IsRedrawLocked = {read=FIsRedrawLocked, nodefault};
	
public:
	__fastcall virtual TcxCustomInnerTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerTreeView(void);
	__property Canvas;
	__property int ItemHeight = {read=FItemHeight, write=SetItemHeight, default=-1};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerTreeView(HWND ParentWindow) : TcxBaseInnerTreeView(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxCustomInnerTreeViewClass;

typedef void __fastcall (__closure *TcxInnerTreeViewWndProcEvent)(Vcl::Comctrls::TTreeView* ATreeView, Winapi::Messages::TMessage &Message, bool &ADone);

class PASCALIMPLEMENTATION TcxTreeViewContainer : public Cxedit::TcxCustomEditContainer
{
	typedef Cxedit::TcxCustomEditContainer inherited;
	
private:
	TcxBaseInnerTreeView* FInnerTreeView;
	TcxInnerTreeViewWndProcEvent FOnInnerTreeViewWndProc;
	bool __fastcall GetAutoExpand(void);
	int __fastcall GetChangeDelay(void);
	bool __fastcall GetHideSelection(void);
	bool __fastcall GetReadOnly(void);
	bool __fastcall GetRightClickSelect(void);
	bool __fastcall GetShowButtons(void);
	bool __fastcall GetShowLines(void);
	bool __fastcall GetShowRoot(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	void __fastcall SetAutoExpand(bool Value);
	void __fastcall SetChangeDelay(int Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetRightClickSelect(bool Value);
	void __fastcall SetShowButtons(bool Value);
	void __fastcall SetShowLines(bool Value);
	void __fastcall SetShowRoot(bool Value);
	void __fastcall SetStateImages(Vcl::Imglist::TCustomImageList* Value);
	
protected:
	virtual bool __fastcall DoInnerTreeViewWndProcHandler(Winapi::Messages::TMessage &Message);
	virtual TcxInnerTreeViewClass __fastcall GetInnerTreeViewClass(void);
	virtual bool __fastcall HandleInnerContolGestures(void);
	virtual void __fastcall InternalInitTreeView(void);
	virtual void __fastcall InitializeInternalTreeView(void);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SetReadOnly(bool Value);
	__property TcxBaseInnerTreeView* InnerTreeView = {read=FInnerTreeView};
	__property TcxInnerTreeViewWndProcEvent OnInnerTreeViewWndProc = {read=FOnInnerTreeViewWndProc, write=FOnInnerTreeViewWndProc};
	__property bool AutoExpand = {read=GetAutoExpand, write=SetAutoExpand, default=0};
	__property int ChangeDelay = {read=GetChangeDelay, write=SetChangeDelay, default=0};
	__property bool HideSelection = {read=GetHideSelection, write=SetHideSelection, default=1};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property bool RightClickSelect = {read=GetRightClickSelect, write=SetRightClickSelect, default=0};
	__property bool ShowButtons = {read=GetShowButtons, write=SetShowButtons, default=1};
	__property bool ShowLines = {read=GetShowLines, write=SetShowLines, default=1};
	__property bool ShowRoot = {read=GetShowRoot, write=SetShowRoot, default=1};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=GetStateImages, write=SetStateImages};
	
public:
	__fastcall virtual TcxTreeViewContainer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxTreeViewContainer(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeViewContainer(HWND ParentWindow) : Cxedit::TcxCustomEditContainer(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomTreeView : public TcxTreeViewContainer
{
	typedef TcxTreeViewContainer inherited;
	
private:
	bool __fastcall GetHotTrack(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	int __fastcall GetItemHeight(void);
	Vcl::Comctrls::TTreeNodes* __fastcall GetTreeNodes(void);
	int __fastcall GetIndent(void);
	bool __fastcall GetMultiSelect(void);
	Vcl::Comctrls::TMultiSelectStyle __fastcall GetMultiSelectStyle(void);
	Vcl::Comctrls::TTVCreateNodeClassEvent __fastcall GetOnCreateNodeClass(void);
	void __fastcall SetMultiSelectStyle(Vcl::Comctrls::TMultiSelectStyle Value);
	void __fastcall SetOnCreateNodeClass(Vcl::Comctrls::TTVCreateNodeClassEvent Value);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnAddition(void);
	Vcl::Comctrls::TTVChangedEvent __fastcall GetOnCancelEdit(void);
	bool __fastcall GetRowSelect(void);
	Vcl::Comctrls::TSortType __fastcall GetSortType(void);
	bool __fastcall GetToolTips(void);
	Cxgraphics::TcxCanvas* __fastcall GetTreeViewCanvas(void);
	Vcl::Comctrls::TTVAdvancedCustomDrawEvent __fastcall GetOnAdvancedCustomDraw(void);
	Vcl::Comctrls::TTVAdvancedCustomDrawItemEvent __fastcall GetOnAdvancedCustomDrawItem(void);
	Vcl::Comctrls::TTVChangedEvent __fastcall GetOnChange(void);
	Vcl::Comctrls::TTVChangingEvent __fastcall GetOnChanging(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnCollapsed(void);
	Vcl::Comctrls::TTVCollapsingEvent __fastcall GetOnCollapsing(void);
	Vcl::Comctrls::TTVCompareEvent __fastcall GetOnCompare(void);
	Vcl::Comctrls::TTVCustomDrawEvent __fastcall GetOnCustomDraw(void);
	Vcl::Comctrls::TTVCustomDrawItemEvent __fastcall GetOnCustomDrawItem(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnDeletion(void);
	Vcl::Comctrls::TTVEditingEvent __fastcall GetOnEditing(void);
	Vcl::Comctrls::TTVEditedEvent __fastcall GetOnEdited(void);
	Vcl::Comctrls::TTVExpandingEvent __fastcall GetOnExpanding(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnExpanded(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnGetImageIndex(void);
	Vcl::Comctrls::TTVExpandedEvent __fastcall GetOnGetSelectedIndex(void);
	Vcl::Comctrls::TTreeNode* __fastcall GetDropTarget(void);
	Vcl::Comctrls::TTreeNode* __fastcall GetSelected(void);
	Vcl::Comctrls::TTreeNode* __fastcall GetTopItem(void);
	unsigned __fastcall GetSelectionCount(void);
	Vcl::Comctrls::TTreeNode* __fastcall GetSelection(int Index);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetTreeNodes(Vcl::Comctrls::TTreeNodes* Value);
	void __fastcall SetIndent(int Value);
	void __fastcall SetItemHeight(int Value);
	void __fastcall SetRowSelect(bool Value);
	void __fastcall SetSortType(Vcl::Comctrls::TSortType Value);
	void __fastcall SetToolTips(bool Value);
	void __fastcall SetOnAddition(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnCancelEdit(Vcl::Comctrls::TTVChangedEvent Value);
	void __fastcall SetOnAdvancedCustomDraw(Vcl::Comctrls::TTVAdvancedCustomDrawEvent Value);
	void __fastcall SetOnAdvancedCustomDrawItem(Vcl::Comctrls::TTVAdvancedCustomDrawItemEvent Value);
	void __fastcall SetOnChange(Vcl::Comctrls::TTVChangedEvent Value);
	void __fastcall SetOnChanging(Vcl::Comctrls::TTVChangingEvent Value);
	void __fastcall SetOnCollapsed(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnCollapsing(Vcl::Comctrls::TTVCollapsingEvent Value);
	void __fastcall SetOnCompare(Vcl::Comctrls::TTVCompareEvent Value);
	void __fastcall SetOnCustomDraw(Vcl::Comctrls::TTVCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawItem(Vcl::Comctrls::TTVCustomDrawItemEvent Value);
	void __fastcall SetOnDeletion(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnEditing(Vcl::Comctrls::TTVEditingEvent Value);
	void __fastcall SetOnEdited(Vcl::Comctrls::TTVEditedEvent Value);
	void __fastcall SetOnExpanding(Vcl::Comctrls::TTVExpandingEvent Value);
	void __fastcall SetOnExpanded(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnGetImageIndex(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetOnGetSelectedIndex(Vcl::Comctrls::TTVExpandedEvent Value);
	void __fastcall SetDropTarget(Vcl::Comctrls::TTreeNode* Value);
	void __fastcall SetSelected(Vcl::Comctrls::TTreeNode* Value);
	void __fastcall SetTopItem(Vcl::Comctrls::TTreeNode* Value);
	MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	
protected:
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall IsReadOnly(void);
	virtual void __fastcall DoSetSize(void);
	virtual void __fastcall SetReadOnly(bool Value);
	virtual void __fastcall WriteState(System::Classes::TWriter* Writer);
	virtual TcxCustomInnerTreeView* __fastcall GetInnerTreeView(void);
	virtual TcxInnerTreeViewClass __fastcall GetInnerTreeViewClass(void);
	__classmethod virtual TcxCustomInnerTreeViewClass __fastcall GetTreeViewClass();
	virtual void __fastcall InitializeInternalTreeView(void);
	virtual bool __fastcall CanChange(Vcl::Comctrls::TTreeNode* Node);
	virtual bool __fastcall CanCollapse(Vcl::Comctrls::TTreeNode* Node);
	virtual bool __fastcall CanEdit(Vcl::Comctrls::TTreeNode* Node);
	virtual bool __fastcall CanExpand(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall Collapse(Vcl::Comctrls::TTreeNode* Node);
	void __fastcall Expand(Vcl::Comctrls::TTreeNode* Node);
	__property bool HotTrack = {read=GetHotTrack, write=SetHotTrack, default=0};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, default=-1};
	__property Vcl::Comctrls::TTreeNodes* Items = {read=GetTreeNodes, write=SetTreeNodes};
	__property int Indent = {read=GetIndent, write=SetIndent, default=19};
	__property bool MultiSelect = {read=GetMultiSelect, write=SetMultiSelect, default=0};
	__property Vcl::Comctrls::TMultiSelectStyle MultiSelectStyle = {read=GetMultiSelectStyle, write=SetMultiSelectStyle, default=1};
	__property bool RowSelect = {read=GetRowSelect, write=SetRowSelect, default=0};
	__property Vcl::Comctrls::TSortType SortType = {read=GetSortType, write=SetSortType, default=0};
	__property bool ToolTips = {read=GetToolTips, write=SetToolTips, default=1};
	__property Vcl::Comctrls::TTVExpandedEvent OnAddition = {read=GetOnAddition, write=SetOnAddition};
	__property Vcl::Comctrls::TTVChangedEvent OnCancelEdit = {read=GetOnCancelEdit, write=SetOnCancelEdit};
	__property Vcl::Comctrls::TTVAdvancedCustomDrawEvent OnAdvancedCustomDraw = {read=GetOnAdvancedCustomDraw, write=SetOnAdvancedCustomDraw};
	__property Vcl::Comctrls::TTVAdvancedCustomDrawItemEvent OnAdvancedCustomDrawItem = {read=GetOnAdvancedCustomDrawItem, write=SetOnAdvancedCustomDrawItem};
	__property Vcl::Comctrls::TTVChangedEvent OnChange = {read=GetOnChange, write=SetOnChange};
	__property Vcl::Comctrls::TTVChangingEvent OnChanging = {read=GetOnChanging, write=SetOnChanging};
	__property Vcl::Comctrls::TTVExpandedEvent OnCollapsed = {read=GetOnCollapsed, write=SetOnCollapsed};
	__property Vcl::Comctrls::TTVCollapsingEvent OnCollapsing = {read=GetOnCollapsing, write=SetOnCollapsing};
	__property Vcl::Comctrls::TTVCompareEvent OnCompare = {read=GetOnCompare, write=SetOnCompare};
	__property Vcl::Comctrls::TTVCustomDrawEvent OnCustomDraw = {read=GetOnCustomDraw, write=SetOnCustomDraw};
	__property Vcl::Comctrls::TTVCustomDrawItemEvent OnCustomDrawItem = {read=GetOnCustomDrawItem, write=SetOnCustomDrawItem};
	__property Vcl::Comctrls::TTVExpandedEvent OnDeletion = {read=GetOnDeletion, write=SetOnDeletion};
	__property Vcl::Comctrls::TTVEditingEvent OnEditing = {read=GetOnEditing, write=SetOnEditing};
	__property Vcl::Comctrls::TTVEditedEvent OnEdited = {read=GetOnEdited, write=SetOnEdited};
	__property Vcl::Comctrls::TTVExpandingEvent OnExpanding = {read=GetOnExpanding, write=SetOnExpanding};
	__property Vcl::Comctrls::TTVExpandedEvent OnExpanded = {read=GetOnExpanded, write=SetOnExpanded};
	__property Vcl::Comctrls::TTVExpandedEvent OnGetImageIndex = {read=GetOnGetImageIndex, write=SetOnGetImageIndex};
	__property Vcl::Comctrls::TTVExpandedEvent OnGetSelectedIndex = {read=GetOnGetSelectedIndex, write=SetOnGetSelectedIndex};
	__property Vcl::Comctrls::TTVCreateNodeClassEvent OnCreateNodeClass = {read=GetOnCreateNodeClass, write=SetOnCreateNodeClass};
	
public:
	__fastcall virtual TcxCustomTreeView(System::Classes::TComponent* AOwner);
	bool __fastcall AlphaSort(bool ARecurse = true);
	bool __fastcall CustomSort(PFNTVCOMPARE SortProc, int Data, bool ARecurse = true);
	void __fastcall FullCollapse(void);
	void __fastcall FullExpand(void);
	Vcl::Comctrls::THitTests __fastcall GetHitTestInfoAt(int X, int Y);
	Vcl::Comctrls::TTreeNode* __fastcall GetNodeAt(int X, int Y);
	bool __fastcall IsEditing(void);
	void __fastcall LoadFromFile(const System::UnicodeString FileName);
	void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	void __fastcall SaveToFile(const System::UnicodeString FileName);
	void __fastcall SaveToStream(System::Classes::TStream* Stream);
	virtual void __fastcall SetScrollBarsParameters(bool AIsScrolling = false);
	__property Vcl::Comctrls::TTreeNode* DropTarget = {read=GetDropTarget, write=SetDropTarget};
	__property Vcl::Comctrls::TTreeNode* Selected = {read=GetSelected, write=SetSelected};
	__property Vcl::Comctrls::TTreeNode* TopItem = {read=GetTopItem, write=SetTopItem};
	__property Cxgraphics::TcxCanvas* TreeViewCanvas = {read=GetTreeViewCanvas};
	virtual void __fastcall Select(Vcl::Comctrls::TTreeNode* Node, System::Classes::TShiftState ShiftState = System::Classes::TShiftState() )/* overload */;
	virtual void __fastcall Select(Vcl::Comctrls::TTreeNode* const *Nodes, const int Nodes_Size)/* overload */;
	virtual void __fastcall Select(System::Classes::TList* Nodes)/* overload */;
	virtual void __fastcall Deselect(Vcl::Comctrls::TTreeNode* Node);
	virtual void __fastcall Subselect(Vcl::Comctrls::TTreeNode* Node, bool Validate = false);
	__property unsigned SelectionCount = {read=GetSelectionCount, nodefault};
	__property Vcl::Comctrls::TTreeNode* Selections[int Index] = {read=GetSelection};
	virtual void __fastcall ClearSelection(bool KeepPrimary = false);
	Vcl::Comctrls::TTreeNode* __fastcall GetSelections(System::Classes::TList* AList);
	virtual Vcl::Comctrls::TTreeNode* __fastcall FindNextToSelect(void);
	__property TcxCustomInnerTreeView* InnerTreeView = {read=GetInnerTreeView};
public:
	/* TcxTreeViewContainer.Destroy */ inline __fastcall virtual ~TcxCustomTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomTreeView(HWND ParentWindow) : TcxTreeViewContainer(ParentWindow) { }
	
};


class DELPHICLASS TcxTreeView;
class PASCALIMPLEMENTATION TcxTreeView : public TcxCustomTreeView
{
	typedef TcxCustomTreeView inherited;
	
public:
	__property TreeViewCanvas;
	__property OnInnerTreeViewWndProc;
	
__published:
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Height = {default=100};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property Width = {default=120};
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnContextPopup;
	__property AutoExpand = {default=0};
	__property ChangeDelay = {default=0};
	__property HideSelection = {default=1};
	__property HotTrack = {default=0};
	__property Images;
	__property ItemHeight = {default=-1};
	__property Items;
	__property Indent = {default=19};
	__property MultiSelect = {default=0};
	__property MultiSelectStyle = {default=1};
	__property ReadOnly = {default=0};
	__property RightClickSelect = {default=0};
	__property RowSelect = {default=0};
	__property ShowButtons = {default=1};
	__property ShowLines = {default=1};
	__property ShowRoot = {default=1};
	__property SortType = {default=0};
	__property StateImages;
	__property ToolTips = {default=1};
	__property OnAddition;
	__property OnCancelEdit;
	__property OnAdvancedCustomDraw;
	__property OnAdvancedCustomDrawItem;
	__property OnChange;
	__property OnChanging;
	__property OnCollapsed;
	__property OnCollapsing;
	__property OnCompare;
	__property OnCustomDraw;
	__property OnCustomDrawItem;
	__property OnDeletion;
	__property OnEditing;
	__property OnEdited;
	__property OnExpanding;
	__property OnExpanded;
	__property OnGetImageIndex;
	__property OnGetSelectedIndex;
	__property OnCreateNodeClass;
public:
	/* TcxCustomTreeView.Create */ inline __fastcall virtual TcxTreeView(System::Classes::TComponent* AOwner) : TcxCustomTreeView(AOwner) { }
	
public:
	/* TcxTreeViewContainer.Destroy */ inline __fastcall virtual ~TcxTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeView(HWND ParentWindow) : TcxCustomTreeView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall CustomizationTreeViewWndProcHandler(Vcl::Comctrls::TTreeView* ATreeView, Winapi::Messages::TMessage &Message);
}	/* namespace Cxtreeview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTREEVIEW)
using namespace Cxtreeview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtreeviewHPP
