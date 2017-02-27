// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxListView.pas' rev: 24.00 (Win64)

#ifndef CxlistviewHPP
#define CxlistviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxHeader.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlistview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxIconOptions;
class DELPHICLASS TcxListViewContainer;
class PASCALIMPLEMENTATION TcxIconOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Vcl::Comctrls::TIconOptions* FInnerIconOptions;
	TcxListViewContainer* FListViewContainer;
	Vcl::Comctrls::TIconArrangement __fastcall GetArrangement(void);
	bool __fastcall GetAutoArrange(void);
	bool __fastcall GetWrapText(void);
	void __fastcall SetArrangement(Vcl::Comctrls::TIconArrangement Value);
	void __fastcall SetAutoArrange(bool Value);
	void __fastcall SetWrapText(bool Value);
	
protected:
	__property TcxListViewContainer* ListViewContainer = {read=FListViewContainer};
	
public:
	__fastcall TcxIconOptions(TcxListViewContainer* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Comctrls::TIconArrangement Arrangement = {read=GetArrangement, write=SetArrangement, default=0};
	__property bool AutoArrange = {read=GetAutoArrange, write=SetAutoArrange, default=0};
	__property bool WrapText = {read=GetWrapText, write=SetWrapText, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxIconOptions(void) { }
	
};


typedef System::TMetaClass* TcxIconOptionsClass;

class DELPHICLASS TcxBaseInnerListView;
class PASCALIMPLEMENTATION TcxBaseInnerListView : public Vcl::Comctrls::TListView
{
	typedef Vcl::Comctrls::TListView inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	HWND FHeaderHandle;
	int FPressedHeaderItemIndex;
	Cxcontrols::TcxWindowProcLinkedObject* FWindowProcObject;
	bool FIsStored;
	int __fastcall GetHeaderHotItemIndex(void);
	System::Types::TRect __fastcall GetHeaderItemRect(int AItemIndex);
	int __fastcall GetHeaderPressedItemIndex(void);
	int __fastcall HeaderItemIndex(int AHeaderItem);
	HIDESBASE void __fastcall HeaderWndProc(Winapi::Messages::TMessage &Message);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	void __fastcall HScrollHandler(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall VScrollHandler(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	HIDESBASE MESSAGE void __fastcall WMGestureNotify(Winapi::Messages::TWMGestureNotify &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall LVMGetHeaderItemInfo(Cxheader::TDXMHeaderItemInfo &Message);
	
protected:
	TcxListViewContainer* FContainer;
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
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
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall DrawHeader(void);
	virtual Dxcore::TdxSortOrder __fastcall GetSortOrder(int AColumnIndex);
	void __fastcall HeaderInvalidate(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall NeedCheckScrollBars(Winapi::Messages::TMessage &Message);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	
public:
	__fastcall virtual TcxBaseInnerListView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxBaseInnerListView(void);
	DYNAMIC bool __fastcall CanFocus(void);
	virtual void __fastcall DefaultHandler(void *Message);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxBaseInnerListView(HWND ParentWindow) : Vcl::Comctrls::TListView(ParentWindow) { }
	
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


typedef System::TMetaClass* TcxInnerListViewClass;

class DELPHICLASS TcxCustomInnerListView;
class DELPHICLASS TcxCustomListView;
class PASCALIMPLEMENTATION TcxCustomInnerListView : public TcxBaseInnerListView
{
	typedef TcxBaseInnerListView inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNotify(Winapi::Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	TcxCustomListView* __fastcall GetContainer(void);
	
protected:
	DYNAMIC bool __fastcall CanEdit(Vcl::Comctrls::TListItem* Item);
	DYNAMIC void __fastcall DoStartDock(Vcl::Controls::TDragObject* &DragObject);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DoCancelEdit(void);
	__property TcxCustomListView* Container = {read=GetContainer};
	
public:
	virtual void __fastcall DeleteSelected(void);
public:
	/* TcxBaseInnerListView.Create */ inline __fastcall virtual TcxCustomInnerListView(System::Classes::TComponent* AOwner) : TcxBaseInnerListView(AOwner) { }
	/* TcxBaseInnerListView.Destroy */ inline __fastcall virtual ~TcxCustomInnerListView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerListView(HWND ParentWindow) : TcxBaseInnerListView(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxCustomInnerListViewClass;

class PASCALIMPLEMENTATION TcxListViewContainer : public Cxedit::TcxCustomEditContainer
{
	typedef Cxedit::TcxCustomEditContainer inherited;
	
private:
	TcxBaseInnerListView* FInnerListView;
	TcxIconOptions* FIconOptions;
	bool __fastcall GetMultiSelect(void);
	bool __fastcall GetReadOnly(void);
	bool __fastcall GetShowColumnHeaders(void);
	Vcl::Comctrls::TViewStyle __fastcall GetViewStyle(void);
	void __fastcall SetIconOptions(TcxIconOptions* Value);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetShowColumnHeaders(bool Value);
	
protected:
	virtual TcxIconOptionsClass __fastcall GetIconOptionsClass(void);
	virtual TcxInnerListViewClass __fastcall GetInnerListViewClass(void);
	virtual bool __fastcall HandleInnerContolGestures(void);
	virtual void __fastcall InitializeInnerListView(void);
	virtual bool __fastcall IsPanArea(const System::Types::TPoint APoint);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall SetReadOnly(bool Value);
	virtual void __fastcall SetViewStyle(Vcl::Comctrls::TViewStyle Value);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	__property TcxIconOptions* IconOptions = {read=FIconOptions, write=SetIconOptions};
	__property TcxBaseInnerListView* InnerListView = {read=FInnerListView};
	__property bool MultiSelect = {read=GetMultiSelect, write=SetMultiSelect, default=0};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property bool ShowColumnHeaders = {read=GetShowColumnHeaders, write=SetShowColumnHeaders, default=1};
	__property Vcl::Comctrls::TViewStyle ViewStyle = {read=GetViewStyle, write=SetViewStyle, default=0};
	
public:
	__fastcall virtual TcxListViewContainer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxListViewContainer(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxListViewContainer(HWND ParentWindow) : Cxedit::TcxCustomEditContainer(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomListView : public TcxListViewContainer
{
	typedef TcxListViewContainer inherited;
	
private:
	System::Classes::TNotifyEvent FOnCancelEdit;
	bool FOwnerDraw;
	Vcl::Comctrls::TListItems* __fastcall GetListItems(void);
	Vcl::Comctrls::TListColumns* __fastcall GetListColumns(void);
	Cxgraphics::TcxCanvas* __fastcall GetListViewCanvas(void);
	bool __fastcall GetColumnClick(void);
	bool __fastcall GetHideSelection(void);
	int __fastcall GetAllocBy(void);
	int __fastcall GetHoverTime(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetLargeImages(void);
	bool __fastcall GetOwnerData(void);
	bool __fastcall GetOwnerDraw(void);
	Vcl::Comctrls::TLVAdvancedCustomDrawEvent __fastcall GetOnAdvancedCustomDraw(void);
	Vcl::Comctrls::TLVAdvancedCustomDrawItemEvent __fastcall GetOnAdvancedCustomDrawItem(void);
	Vcl::Comctrls::TLVAdvancedCustomDrawSubItemEvent __fastcall GetOnAdvancedCustomDrawSubItem(void);
	Vcl::Comctrls::TLVChangeEvent __fastcall GetOnChange(void);
	Vcl::Comctrls::TLVChangingEvent __fastcall GetOnChanging(void);
	Vcl::Comctrls::TLVColumnClickEvent __fastcall GetOnColumnClick(void);
	System::Classes::TNotifyEvent __fastcall GetOnColumnDragged(void);
	Vcl::Comctrls::TLVColumnRClickEvent __fastcall GetOnColumnRightClick(void);
	Vcl::Comctrls::TLVCompareEvent __fastcall GetOnCompare(void);
	Vcl::Comctrls::TLVCustomDrawEvent __fastcall GetOnCustomDraw(void);
	Vcl::Comctrls::TLVCustomDrawItemEvent __fastcall GetOnCustomDrawItem(void);
	Vcl::Comctrls::TLVCustomDrawSubItemEvent __fastcall GetOnCustomDrawSubItem(void);
	Vcl::Comctrls::TLVOwnerDataEvent __fastcall GetOnData(void);
	Vcl::Comctrls::TLVOwnerDataFindEvent __fastcall GetOnDataFind(void);
	Vcl::Comctrls::TLVOwnerDataHintEvent __fastcall GetOnDataHint(void);
	Vcl::Comctrls::TLVOwnerDataStateChangeEvent __fastcall GetOnDataStateChange(void);
	Vcl::Comctrls::TLVDeletedEvent __fastcall GetOnDeletion(void);
	Vcl::Comctrls::TLVDrawItemEvent __fastcall GetOnDrawItem(void);
	Vcl::Comctrls::TLVEditedEvent __fastcall GetOnEdited(void);
	Vcl::Comctrls::TLVEditingEvent __fastcall GetOnEditing(void);
	Vcl::Comctrls::TLVInfoTipEvent __fastcall GetOnInfoTip(void);
	Vcl::Comctrls::TLVDeletedEvent __fastcall GetOnInsert(void);
	Vcl::Comctrls::TLVNotifyEvent __fastcall GetOnGetImageIndex(void);
	Vcl::Comctrls::TLVSubItemImageEvent __fastcall GetOnGetSubItemImage(void);
	bool __fastcall GetShowWorkAreas(void);
	Vcl::Comctrls::TLVSelectItemEvent __fastcall GetOnSelectItem(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetSmallImages(void);
	Vcl::Comctrls::TSortType __fastcall GetSortType(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetStateImages(void);
	Vcl::Comctrls::TLVCreateItemClassEvent __fastcall GetOnCreateItemClass(void);
	void __fastcall SetListItems(Vcl::Comctrls::TListItems* Value);
	void __fastcall SetListColumns(Vcl::Comctrls::TListColumns* Value);
	void __fastcall SetColumnClick(bool Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetAllocBy(int Value);
	void __fastcall SetHoverTime(int Value);
	void __fastcall SetLargeImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetOwnerData(bool Value);
	void __fastcall SetOwnerDraw(bool Value);
	void __fastcall SetOnAdvancedCustomDraw(Vcl::Comctrls::TLVAdvancedCustomDrawEvent Value);
	void __fastcall SetOnAdvancedCustomDrawItem(Vcl::Comctrls::TLVAdvancedCustomDrawItemEvent Value);
	void __fastcall SetOnAdvancedCustomDrawSubItem(Vcl::Comctrls::TLVAdvancedCustomDrawSubItemEvent Value);
	void __fastcall SetOnChange(Vcl::Comctrls::TLVChangeEvent Value);
	void __fastcall SetOnChanging(Vcl::Comctrls::TLVChangingEvent Value);
	void __fastcall SetOnColumnClick(Vcl::Comctrls::TLVColumnClickEvent Value);
	void __fastcall SetOnColumnDragged(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnColumnRightClick(Vcl::Comctrls::TLVColumnRClickEvent Value);
	void __fastcall SetOnCompare(Vcl::Comctrls::TLVCompareEvent Value);
	void __fastcall SetOnCustomDraw(Vcl::Comctrls::TLVCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawItem(Vcl::Comctrls::TLVCustomDrawItemEvent Value);
	void __fastcall SetOnCustomDrawSubItem(Vcl::Comctrls::TLVCustomDrawSubItemEvent Value);
	void __fastcall SetOnData(Vcl::Comctrls::TLVOwnerDataEvent Value);
	void __fastcall SetOnDataFind(Vcl::Comctrls::TLVOwnerDataFindEvent Value);
	void __fastcall SetOnDataHint(Vcl::Comctrls::TLVOwnerDataHintEvent Value);
	void __fastcall SetOnDataStateChange(Vcl::Comctrls::TLVOwnerDataStateChangeEvent Value);
	void __fastcall SetOnDeletion(Vcl::Comctrls::TLVDeletedEvent Value);
	void __fastcall SetOnDrawItem(Vcl::Comctrls::TLVDrawItemEvent Value);
	void __fastcall SetOnEdited(Vcl::Comctrls::TLVEditedEvent Value);
	void __fastcall SetOnEditing(Vcl::Comctrls::TLVEditingEvent Value);
	void __fastcall SetOnInfoTip(Vcl::Comctrls::TLVInfoTipEvent Value);
	void __fastcall SetOnInsert(Vcl::Comctrls::TLVDeletedEvent Value);
	void __fastcall SetOnGetImageIndex(Vcl::Comctrls::TLVNotifyEvent Value);
	void __fastcall SetOnGetSubItemImage(Vcl::Comctrls::TLVSubItemImageEvent Value);
	void __fastcall SetShowWorkAreas(bool Value);
	void __fastcall SetOnSelectItem(Vcl::Comctrls::TLVSelectItemEvent Value);
	void __fastcall SetSmallImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetSortType(Vcl::Comctrls::TSortType Value);
	void __fastcall SetStateImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetOnCreateItemClass(Vcl::Comctrls::TLVCreateItemClassEvent Value);
	bool __fastcall GetCheckBoxes(void);
	Vcl::Comctrls::TListColumn* __fastcall GetColumnFromIndex(int Index);
	Vcl::Comctrls::TListItem* __fastcall GetDropTarget(void);
	bool __fastcall GetFullDrag(void);
	bool __fastcall GetGridLines(void);
	bool __fastcall GetHotTrack(void);
	Vcl::Comctrls::TListHotTrackStyles __fastcall GetHotTrackStyles(void);
	TcxCustomInnerListView* __fastcall GetInnerListView(void);
	Vcl::Comctrls::TListItem* __fastcall GetItemFocused(void);
	bool __fastcall GetRowSelect(void);
	int __fastcall GetSelCount(void);
	Vcl::Comctrls::TListItem* __fastcall GetSelected(void);
	Vcl::Comctrls::TListItem* __fastcall GetTopItem(void);
	System::Types::TPoint __fastcall GetViewOrigin(void);
	int __fastcall GetVisibleRowCount(void);
	System::Types::TRect __fastcall GetBoundingRect(void);
	Vcl::Comctrls::TWorkAreas* __fastcall GetWorkAreas(void);
	void __fastcall SetCheckboxes(bool Value);
	void __fastcall SetDropTarget(Vcl::Comctrls::TListItem* Value);
	void __fastcall SetFullDrag(bool Value);
	void __fastcall SetGridLines(bool Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetHotTrackStyles(Vcl::Comctrls::TListHotTrackStyles Value);
	void __fastcall SetItemFocused(Vcl::Comctrls::TListItem* Value);
	void __fastcall SetRowSelect(bool Value);
	void __fastcall SetSelected(Vcl::Comctrls::TListItem* Value);
	
protected:
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall IsReadOnly(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall WriteState(System::Classes::TWriter* Writer);
	bool __fastcall CanChange(Vcl::Comctrls::TListItem* Item, int Change);
	bool __fastcall CanEdit(Vcl::Comctrls::TListItem* Item);
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	bool __fastcall ColumnsShowing(void);
	int __fastcall GetCount(void);
	virtual TcxInnerListViewClass __fastcall GetInnerListViewClass(void);
	int __fastcall GetItemIndex(void)/* overload */;
	__classmethod virtual TcxCustomInnerListViewClass __fastcall GetListViewClass();
	int __fastcall GetListViewItemIndex(void);
	virtual void __fastcall InitializeInnerListView(void);
	void __fastcall SetItemIndex(int Value);
	virtual void __fastcall SetReadOnly(bool Value);
	int __fastcall GetItemIndex(Vcl::Comctrls::TListItem* Value)/* overload */;
	void __fastcall UpdateColumn(int AnIndex);
	void __fastcall UpdateColumns(void);
	__property Vcl::Comctrls::TListColumns* Columns = {read=GetListColumns, write=SetListColumns};
	__property bool ColumnClick = {read=GetColumnClick, write=SetColumnClick, default=1};
	__property bool HideSelection = {read=GetHideSelection, write=SetHideSelection, default=1};
	__property Vcl::Comctrls::TListItems* Items = {read=GetListItems, write=SetListItems};
	__property int AllocBy = {read=GetAllocBy, write=SetAllocBy, default=0};
	__property int HoverTime = {read=GetHoverTime, write=SetHoverTime, default=-1};
	__property Cxgraphics::TcxCanvas* ListViewCanvas = {read=GetListViewCanvas};
	__property Vcl::Imglist::TCustomImageList* LargeImages = {read=GetLargeImages, write=SetLargeImages};
	__property bool OwnerData = {read=GetOwnerData, write=SetOwnerData, default=0};
	__property bool OwnerDraw = {read=GetOwnerDraw, write=SetOwnerDraw, default=0};
	__property bool RowSelect = {read=GetRowSelect, write=SetRowSelect, default=0};
	__property bool ShowWorkAreas = {read=GetShowWorkAreas, write=SetShowWorkAreas, default=0};
	__property Vcl::Imglist::TCustomImageList* SmallImages = {read=GetSmallImages, write=SetSmallImages};
	__property Vcl::Comctrls::TSortType SortType = {read=GetSortType, write=SetSortType, default=0};
	__property Vcl::Imglist::TCustomImageList* StateImages = {read=GetStateImages, write=SetStateImages};
	__property Vcl::Comctrls::TLVAdvancedCustomDrawEvent OnAdvancedCustomDraw = {read=GetOnAdvancedCustomDraw, write=SetOnAdvancedCustomDraw};
	__property Vcl::Comctrls::TLVAdvancedCustomDrawItemEvent OnAdvancedCustomDrawItem = {read=GetOnAdvancedCustomDrawItem, write=SetOnAdvancedCustomDrawItem};
	__property Vcl::Comctrls::TLVAdvancedCustomDrawSubItemEvent OnAdvancedCustomDrawSubItem = {read=GetOnAdvancedCustomDrawSubItem, write=SetOnAdvancedCustomDrawSubItem};
	__property System::Classes::TNotifyEvent OnCancelEdit = {read=FOnCancelEdit, write=FOnCancelEdit};
	__property Vcl::Comctrls::TLVChangeEvent OnChange = {read=GetOnChange, write=SetOnChange};
	__property Vcl::Comctrls::TLVChangingEvent OnChanging = {read=GetOnChanging, write=SetOnChanging};
	__property Vcl::Comctrls::TLVColumnClickEvent OnColumnClick = {read=GetOnColumnClick, write=SetOnColumnClick};
	__property System::Classes::TNotifyEvent OnColumnDragged = {read=GetOnColumnDragged, write=SetOnColumnDragged};
	__property Vcl::Comctrls::TLVColumnRClickEvent OnColumnRightClick = {read=GetOnColumnRightClick, write=SetOnColumnRightClick};
	__property Vcl::Comctrls::TLVCompareEvent OnCompare = {read=GetOnCompare, write=SetOnCompare};
	__property Vcl::Comctrls::TLVCustomDrawEvent OnCustomDraw = {read=GetOnCustomDraw, write=SetOnCustomDraw};
	__property Vcl::Comctrls::TLVCustomDrawItemEvent OnCustomDrawItem = {read=GetOnCustomDrawItem, write=SetOnCustomDrawItem};
	__property Vcl::Comctrls::TLVCustomDrawSubItemEvent OnCustomDrawSubItem = {read=GetOnCustomDrawSubItem, write=SetOnCustomDrawSubItem};
	__property Vcl::Comctrls::TLVOwnerDataEvent OnData = {read=GetOnData, write=SetOnData};
	__property Vcl::Comctrls::TLVOwnerDataFindEvent OnDataFind = {read=GetOnDataFind, write=SetOnDataFind};
	__property Vcl::Comctrls::TLVOwnerDataHintEvent OnDataHint = {read=GetOnDataHint, write=SetOnDataHint};
	__property Vcl::Comctrls::TLVOwnerDataStateChangeEvent OnDataStateChange = {read=GetOnDataStateChange, write=SetOnDataStateChange};
	__property Vcl::Comctrls::TLVDeletedEvent OnDeletion = {read=GetOnDeletion, write=SetOnDeletion};
	__property Vcl::Comctrls::TLVDrawItemEvent OnDrawItem = {read=GetOnDrawItem, write=SetOnDrawItem};
	__property Vcl::Comctrls::TLVEditedEvent OnEdited = {read=GetOnEdited, write=SetOnEdited};
	__property Vcl::Comctrls::TLVEditingEvent OnEditing = {read=GetOnEditing, write=SetOnEditing};
	__property Vcl::Comctrls::TLVInfoTipEvent OnInfoTip = {read=GetOnInfoTip, write=SetOnInfoTip};
	__property Vcl::Comctrls::TLVDeletedEvent OnInsert = {read=GetOnInsert, write=SetOnInsert};
	__property Vcl::Comctrls::TLVNotifyEvent OnGetImageIndex = {read=GetOnGetImageIndex, write=SetOnGetImageIndex};
	__property Vcl::Comctrls::TLVSubItemImageEvent OnGetSubItemImage = {read=GetOnGetSubItemImage, write=SetOnGetSubItemImage};
	__property Vcl::Comctrls::TLVSelectItemEvent OnSelectItem = {read=GetOnSelectItem, write=SetOnSelectItem};
	__property Vcl::Comctrls::TLVCreateItemClassEvent OnCreateItemClass = {read=GetOnCreateItemClass, write=SetOnCreateItemClass};
	
public:
	__fastcall virtual TcxCustomListView(System::Classes::TComponent* AOwner);
	bool __fastcall AlphaSort(void);
	void __fastcall Arrange(Vcl::Comctrls::TListArrangement Code);
	void __fastcall Clear(void);
	void __fastcall ClearSelection(void);
	void __fastcall AddItem(System::UnicodeString Item, System::TObject* AObject);
	void __fastcall CopySelection(Vcl::Controls::TCustomListControl* Destination);
	void __fastcall DeleteSelected(void);
	void __fastcall SelectAll(void);
	Vcl::Comctrls::TListItem* __fastcall FindCaption(int StartIndex, System::UnicodeString Value, bool Partial, bool Inclusive, bool Wrap);
	Vcl::Comctrls::TListItem* __fastcall FindData(int StartIndex, void * Value, bool Inclusive, bool Wrap);
	Vcl::Comctrls::THitTests __fastcall GetHitTestInfoAt(int X, int Y);
	Vcl::Comctrls::TListItem* __fastcall GetItemAt(int X, int Y);
	Vcl::Comctrls::TListItem* __fastcall GetNearestItem(System::Types::TPoint Point, Vcl::Comctrls::TSearchDirection Direction);
	Vcl::Comctrls::TListItem* __fastcall GetNextItem(Vcl::Comctrls::TListItem* StartItem, Vcl::Comctrls::TSearchDirection Direction, Vcl::Comctrls::TItemStates States);
	System::UnicodeString __fastcall GetSearchString(void);
	bool __fastcall IsEditing(void);
	bool __fastcall CustomSort(PFNLVCOMPARE SortProc, int lParam);
	int __fastcall StringWidth(System::UnicodeString S);
	void __fastcall UpdateItems(int FirstIndex, int LastIndex);
	__property bool Checkboxes = {read=GetCheckBoxes, write=SetCheckboxes, default=0};
	__property Vcl::Comctrls::TListColumn* Column[int Index] = {read=GetColumnFromIndex};
	__property Vcl::Comctrls::TListItem* DropTarget = {read=GetDropTarget, write=SetDropTarget};
	__property bool FullDrag = {read=GetFullDrag, write=SetFullDrag, default=0};
	__property bool GridLines = {read=GetGridLines, write=SetGridLines, default=0};
	__property bool HotTrack = {read=GetHotTrack, write=SetHotTrack, default=0};
	__property Vcl::Comctrls::TListHotTrackStyles HotTrackStyles = {read=GetHotTrackStyles, write=SetHotTrackStyles, default=0};
	__property TcxCustomInnerListView* InnerListView = {read=GetInnerListView};
	__property Vcl::Comctrls::TListItem* ItemFocused = {read=GetItemFocused, write=SetItemFocused};
	__property int ItemIndex = {read=GetListViewItemIndex, write=SetItemIndex, default=-1};
	__property int SelCount = {read=GetSelCount, nodefault};
	__property Vcl::Comctrls::TListItem* Selected = {read=GetSelected, write=SetSelected};
	__property Vcl::Comctrls::TListItem* TopItem = {read=GetTopItem};
	__property System::Types::TPoint ViewOrigin = {read=GetViewOrigin};
	__property int VisibleRowCount = {read=GetVisibleRowCount, nodefault};
	__property System::Types::TRect BoundingRect = {read=GetBoundingRect};
	__property Vcl::Comctrls::TWorkAreas* WorkAreas = {read=GetWorkAreas};
public:
	/* TcxListViewContainer.Destroy */ inline __fastcall virtual ~TcxCustomListView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomListView(HWND ParentWindow) : TcxListViewContainer(ParentWindow) { }
	
};


class DELPHICLASS TcxListView;
class PASCALIMPLEMENTATION TcxListView : public TcxCustomListView
{
	typedef TcxCustomListView inherited;
	
public:
	__property ListViewCanvas;
	
__published:
	__property AllocBy = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property Checkboxes = {default=0};
	__property ColumnClick = {default=1};
	__property Columns;
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property HideSelection = {default=1};
	__property HotTrack = {default=0};
	__property HoverTime = {default=-1};
	__property IconOptions;
	__property ItemIndex = {default=-1};
	__property Items;
	__property LargeImages;
	__property MultiSelect = {default=0};
	__property OwnerData = {default=0};
	__property OwnerDraw = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property RowSelect = {default=0};
	__property ShowColumnHeaders = {default=1};
	__property ShowHint;
	__property ShowWorkAreas = {default=0};
	__property SmallImages;
	__property SortType = {default=0};
	__property StateImages;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property ViewStyle = {default=0};
	__property Visible = {default=1};
	__property OnAdvancedCustomDraw;
	__property OnAdvancedCustomDrawItem;
	__property OnAdvancedCustomDrawSubItem;
	__property OnCancelEdit;
	__property OnChange;
	__property OnChanging;
	__property OnClick;
	__property OnColumnClick;
	__property OnColumnDragged;
	__property OnColumnRightClick;
	__property OnCompare;
	__property OnContextPopup;
	__property OnCreateItemClass;
	__property OnCustomDraw;
	__property OnCustomDrawItem;
	__property OnCustomDrawSubItem;
	__property OnData;
	__property OnDataFind;
	__property OnDataHint;
	__property OnDataStateChange;
	__property OnDblClick;
	__property OnDeletion;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawItem;
	__property OnEdited;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetImageIndex;
	__property OnGetSubItemImage;
	__property OnInfoTip;
	__property OnInsert;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnSelectItem;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomListView.Create */ inline __fastcall virtual TcxListView(System::Classes::TComponent* AOwner) : TcxCustomListView(AOwner) { }
	
public:
	/* TcxListViewContainer.Destroy */ inline __fastcall virtual ~TcxListView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxListView(HWND ParentWindow) : TcxCustomListView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const Vcl::Comctrls::TIconArrangement cxiaTop = (Vcl::Comctrls::TIconArrangement)(0);
}	/* namespace Cxlistview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLISTVIEW)
using namespace Cxlistview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlistviewHPP
