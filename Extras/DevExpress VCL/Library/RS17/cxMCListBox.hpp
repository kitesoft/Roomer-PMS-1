// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxMCListBox.pas' rev: 24.00 (Win32)

#ifndef CxmclistboxHPP
#define CxmclistboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxExtEditUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxHeader.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxmclistbox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxMCInnerHeader;
class DELPHICLASS TcxMCListBox;
class PASCALIMPLEMENTATION TcxMCInnerHeader : public Cxheader::TcxHeader
{
	typedef Cxheader::TcxHeader inherited;
	
private:
	Cxcontainer::TcxContainer* FContainer;
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	TcxMCListBox* __fastcall GetContainer(void);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	
protected:
	DYNAMIC void __fastcall AdjustSize(void);
	DYNAMIC void __fastcall Click(void);
	virtual bool __fastcall IsInnerControl(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall UpdateHeight(void);
	__property TcxMCListBox* Container = {read=GetContainer};
	
public:
	__fastcall virtual TcxMCInnerHeader(System::Classes::TComponent* AOwner);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
public:
	/* TcxCustomHeader.Destroy */ inline __fastcall virtual ~TcxMCInnerHeader(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxMCInnerHeader(HWND ParentWindow) : Cxheader::TcxHeader(ParentWindow) { }
	
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


class DELPHICLASS TcxMCInnerListBox;
class PASCALIMPLEMENTATION TcxMCInnerListBox : public Cxcontainer::TcxCustomInnerListBox
{
	typedef Cxcontainer::TcxCustomInnerListBox inherited;
	
private:
	System::Classes::TStrings* FItems;
	bool FVScrollBarVisible;
	TcxMCListBox* __fastcall GetContainer(void);
	bool __fastcall IsVScrollBarVisible(void);
	void __fastcall ItemsChanged(System::Classes::TStrings* Sender, int AStartIndex, int AEndIndex);
	void __fastcall SetContainer(TcxMCListBox* Value);
	HIDESBASE void __fastcall SetItems(System::Classes::TStrings* Value);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	
protected:
	__property TcxMCListBox* Container = {read=GetContainer, write=SetContainer};
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall RecalcItemRects(int AStartIndex = 0xffffffff, int AEndIndex = 0xffffffff);
	virtual void __fastcall DrawLine(int X, int Y1, int Y2);
	virtual void __fastcall DrawLines(void);
	virtual void __fastcall FullRepaint(void);
	__property bool VScrollBarVisible = {read=FVScrollBarVisible, nodefault};
	
public:
	__fastcall virtual TcxMCInnerListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxMCInnerListBox(void);
	DYNAMIC bool __fastcall CanFocus(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	
__published:
	__property System::Classes::TStrings* Items = {read=FItems, write=SetItems};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxMCInnerListBox(HWND ParentWindow) : Cxcontainer::TcxCustomInnerListBox(ParentWindow) { }
	
};


class DELPHICLASS TcxMCInnerPanel;
class PASCALIMPLEMENTATION TcxMCInnerPanel : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TcxMCListBox* __fastcall GetMCListBox(void);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	
protected:
	void __fastcall AdjustChildsPosition(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Paint(void);
	__property TcxMCListBox* MCListBox = {read=GetMCListBox};
	
public:
	__fastcall virtual TcxMCInnerPanel(System::Classes::TComponent* AOwner);
public:
	/* TcxControl.Destroy */ inline __fastcall virtual ~TcxMCInnerPanel(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxMCInnerPanel(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxMCListBox : public Cxedit::TcxCustomEditContainer
{
	typedef Cxedit::TcxCustomEditContainer inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	System::Uitypes::TColor FColumnLineColor;
	System::WideChar FDelimiter;
	TcxMCInnerHeader* FInnerHeader;
	Cxheader::TcxHeaderSectionRects FInnerHeaderSectionRectsWithoutScrollbar;
	Cxheader::TcxHeaderSectionRects FInnerHeaderSectionRectsWithScrollbar;
	TcxMCInnerListBox* FInnerListBox;
	TcxMCInnerPanel* FInnerPanel;
	bool FIntegralHeight;
	bool FInternalFlagCreatedHeader;
	bool FMultiLines;
	bool FOverflowEmptyColumn;
	System::Classes::TStringList* FOverLoadList;
	Vcl::Stdctrls::TScrollEvent FSavedHScroll;
	int FSavedIndex;
	bool FShowColumnLines;
	bool FShowEndEllipsis;
	bool FShowHeader;
	bool FIsExitProcessing;
	bool FIsInternalPaint;
	bool FIsSorting;
	System::Types::TRect __fastcall CalcCellTextRect(const System::Types::TRect &AApproximateRect, int AItemIndex, int AColumnIndex);
	void __fastcall DrawCellTextEx(System::Types::TRect &ARect, int AFlags, int AItemIndex, int AColumnIndex);
	void __fastcall DrawCellText(const System::Types::TRect &ARect, int AItemIndex, int AColumnIndex);
	System::Types::TRect __fastcall GetCellRect(int AItemIndex, int AColumnIndex, int ATop, int ABottom, bool AVScrollBarVisible);
	System::Types::TRect __fastcall GetCellTextRect(int AItemIndex, int AColumnIndex, int ATop, int ABottom, bool AVScrollBarVisible);
	System::WideChar __fastcall GetDelimiter(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	System::Types::TRect __fastcall GetHeaderSectionRect(int AIndex, bool AVScrollBarVisible);
	Cxheader::TcxHeaderSections* __fastcall GetHeaderSections(void);
	void __fastcall SetHeaderSections(Cxheader::TcxHeaderSections* Value);
	void __fastcall SectionEndResizeHandler(Cxheader::TcxCustomHeader* HeaderControl, Cxheader::TcxHeaderSection* Section);
	void __fastcall SectionTrackHandler(Cxheader::TcxCustomHeader* HeaderControl, Cxheader::TcxHeaderSection* Section, int Width, Cxheader::TcxSectionTrackState State);
	void __fastcall SetMultiLines(bool Value);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetShowEndEllipsis(bool Value);
	void __fastcall SetDelimiter(System::WideChar Value);
	bool __fastcall GetHeaderDragReorder(void);
	void __fastcall SetHeaderDragReorder(bool Value);
	void __fastcall SetShowColumnLines(bool Value);
	void __fastcall SetShowHeader(bool Value);
	void __fastcall SetColumnLineColor(System::Uitypes::TColor Value);
	void __fastcall SetOverflowEmptyColumn(bool Value);
	void __fastcall SectionsChangeHandler(System::TObject* Sender);
	void __fastcall HScrollHandler(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall SectionEndDragHandler(System::TObject* Sender);
	void __fastcall DrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall MeasureItem(Vcl::Controls::TWinControl* Control, int Index, int &Height);
	int __fastcall GetCount(void);
	bool __fastcall GetExtendedSelect(void);
	int __fastcall GetItemHeight(void);
	int __fastcall GetItemIndex(void);
	System::Classes::TStrings* __fastcall GetItems(void);
	bool __fastcall GetMultiSelect(void);
	bool __fastcall GetReadOnly(void);
	int __fastcall GetSelCount(void);
	bool __fastcall GetSelected(int Index);
	bool __fastcall GetSorted(void);
	int __fastcall GetTopIndex(void);
	void __fastcall SetExtendedSelect(bool Value);
	void __fastcall SetItemHeight(int Value);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetItems(System::Classes::TStrings* Value);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetSelected(int Index, bool Value);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetTopIndex(int Value);
	bool __fastcall GetAutoComplete(void);
	unsigned __fastcall GetAutoCompleteDelay(void);
	void __fastcall SetAutoComplete(bool Value);
	void __fastcall SetAutoCompleteDelay(unsigned Value);
	int __fastcall GetScrollWidth(void);
	int __fastcall GetTabWidth(void);
	void __fastcall SetIntegralHeight(bool Value);
	void __fastcall SetScrollWidth(int Value);
	void __fastcall SetTabWidth(int Value);
	
protected:
	Cxdatautils::TcxCustomDataBinding* FDataBinding;
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall AdjustInnerControl(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall IsReadOnly(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall UpdateData(void);
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual void __fastcall SetDragMode(System::Uitypes::TDragMode Value);
	virtual void __fastcall DoSetSize(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	DYNAMIC void __fastcall CursorChanged(void);
	virtual void __fastcall DataChange(void);
	DYNAMIC void __fastcall FontChanged(void);
	void __fastcall ItemsChanged(void);
	void __fastcall CalcHeaderSectionRects(void);
	virtual int __fastcall CalcItemHeight(int AIndex, bool AVScrollBarVisible);
	virtual Cxdatautils::TcxCustomDataBindingClass __fastcall GetDataBindingClass(void);
	System::UnicodeString __fastcall GetTextPart(int AItemIndex, int AColumnIndex);
	void __fastcall GetOptimalHeight(int &ANewHeight);
	void __fastcall FullRepaint(void);
	virtual void __fastcall SectionSortChangedHandler(System::TObject* Sender, Cxheader::TcxHeaderSection* const Section, const Dxcore::TdxSortOrder ASortOrder);
	__property Cxdatautils::TcxCustomDataBinding* DataBinding = {read=FDataBinding};
	__property TcxMCInnerHeader* InnerHeader = {read=FInnerHeader};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, nodefault};
	__property int ScrollWidth = {read=GetScrollWidth, write=SetScrollWidth, default=0};
	
public:
	__fastcall virtual TcxMCListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxMCListBox(void);
	DYNAMIC bool __fastcall Focused(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	void __fastcall AddItem(System::UnicodeString AItem, System::TObject* AObject);
	void __fastcall Clear(void);
	void __fastcall ClearSelection(void);
	void __fastcall DeleteSelected(void);
	int __fastcall ItemAtPos(const System::Types::TPoint &APos, bool AExisting);
	System::Types::TRect __fastcall ItemRect(int Index);
	bool __fastcall ItemVisible(int Index);
	void __fastcall SelectAll(void);
	void __fastcall CopySelection(Vcl::Controls::TCustomListControl* ADestination);
	void __fastcall MoveSelection(Vcl::Controls::TCustomListControl* ADestination);
	__property int Count = {read=GetCount, nodefault};
	__property TcxMCInnerListBox* InnerListBox = {read=FInnerListBox, write=FInnerListBox};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property int SelCount = {read=GetSelCount, nodefault};
	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	__property int TopIndex = {read=GetTopIndex, write=SetTopIndex, nodefault};
	
__published:
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property bool AutoComplete = {read=GetAutoComplete, write=SetAutoComplete, default=1};
	__property unsigned AutoCompleteDelay = {read=GetAutoCompleteDelay, write=SetAutoCompleteDelay, default=500};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property System::Uitypes::TColor ColumnLineColor = {read=FColumnLineColor, write=SetColumnLineColor, default=-16777200};
	__property Constraints;
	__property System::WideChar Delimiter = {read=GetDelimiter, write=SetDelimiter, default=59};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property bool ExtendedSelect = {read=GetExtendedSelect, write=SetExtendedSelect, default=1};
	__property bool HeaderDragReorder = {read=GetHeaderDragReorder, write=SetHeaderDragReorder, default=0};
	__property Cxheader::TcxHeaderSections* HeaderSections = {read=GetHeaderSections, write=SetHeaderSections};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property bool IntegralHeight = {read=FIntegralHeight, write=SetIntegralHeight, default=0};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, default=16};
	__property System::Classes::TStrings* Items = {read=GetItems, write=SetItems};
	__property bool MultiLines = {read=FMultiLines, write=SetMultiLines, default=0};
	__property bool MultiSelect = {read=GetMultiSelect, write=SetMultiSelect, default=0};
	__property bool OverflowEmptyColumn = {read=FOverflowEmptyColumn, write=SetOverflowEmptyColumn, default=1};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool ShowColumnLines = {read=FShowColumnLines, write=SetShowColumnLines, default=1};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=SetShowEndEllipsis, default=1};
	__property bool ShowHeader = {read=FShowHeader, write=SetShowHeader, default=1};
	__property ShowHint;
	__property bool Sorted = {read=GetSorted, write=SetSorted, default=0};
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property int TabWidth = {read=GetTabWidth, write=SetTabWidth, default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
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
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxMCListBox(HWND ParentWindow) : Cxedit::TcxCustomEditContainer(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxmclistbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXMCLISTBOX)
using namespace Cxmclistbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxmclistboxHPP
