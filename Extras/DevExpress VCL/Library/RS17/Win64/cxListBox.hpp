// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxListBox.pas' rev: 24.00 (Win64)

#ifndef CxlistboxHPP
#define CxlistboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlistbox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxInnerListBox;
class DELPHICLASS TcxListBox;
class PASCALIMPLEMENTATION TcxInnerListBox : public Cxcontainer::TcxCustomInnerListBox
{
	typedef Cxcontainer::TcxCustomInnerListBox inherited;
	
private:
	TcxListBox* __fastcall GetContainer(void);
	void __fastcall SetContainer(TcxListBox* Value);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	
protected:
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DrawItem(int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	__property TcxListBox* Container = {read=GetContainer, write=SetContainer};
	
public:
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall CanFocus(void);
public:
	/* TcxCustomInnerListBox.Create */ inline __fastcall virtual TcxInnerListBox(System::Classes::TComponent* AOwner) : Cxcontainer::TcxCustomInnerListBox(AOwner) { }
	/* TcxCustomInnerListBox.Destroy */ inline __fastcall virtual ~TcxInnerListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxInnerListBox(HWND ParentWindow) : Cxcontainer::TcxCustomInnerListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxInnerListBoxClass;

typedef void __fastcall (__closure *TcxListBoxDrawItemEvent)(TcxListBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);

typedef void __fastcall (__closure *TcxListBoxMeasureItemEvent)(TcxListBox* AControl, int AIndex, int &Height);

class PASCALIMPLEMENTATION TcxListBox : public Cxedit::TcxCustomEditContainer
{
	typedef Cxedit::TcxCustomEditContainer inherited;
	
private:
	TcxInnerListBox* FInnerListBox;
	bool FIntegralHeight;
	bool FIsExitProcessing;
	TcxListBoxDrawItemEvent FOnDrawItem;
	TcxListBoxMeasureItemEvent FOnMeasureItem;
	void __fastcall DoMeasureItem(Vcl::Controls::TWinControl* Control, int Index, int &Height);
	bool __fastcall GetAutoComplete(void);
	unsigned __fastcall GetAutoCompleteDelay(void);
	int __fastcall GetColumns(void);
	int __fastcall GetCount(void);
	bool __fastcall GetExtendedSelect(void);
	Vcl::Stdctrls::TListBox* __fastcall GetInnerListBox(void);
	int __fastcall GetItemHeight(void);
	int __fastcall GetItemIndex(void);
	System::TObject* __fastcall GetItemObject(void);
	System::Classes::TStrings* __fastcall GetItems(void);
	Vcl::Stdctrls::TListBoxStyle __fastcall GetListStyle(void);
	bool __fastcall GetMultiSelect(void);
	bool __fastcall GetReadOnly(void);
	int __fastcall GetSelCount(void);
	bool __fastcall GetSelected(int Index);
	bool __fastcall GetSorted(void);
	int __fastcall GetTopIndex(void);
	void __fastcall SetAutoComplete(bool Value);
	void __fastcall SetAutoCompleteDelay(unsigned Value);
	void __fastcall SetColumns(int Value);
	void __fastcall SetExtendedSelect(bool Value);
	void __fastcall SetItemHeight(int Value);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetItemObject(System::TObject* Value);
	void __fastcall SetItems(System::Classes::TStrings* Value);
	void __fastcall SetListStyle(Vcl::Stdctrls::TListBoxStyle Value);
	void __fastcall SetMultiSelect(bool Value);
	void __fastcall SetOnMeasureItem(TcxListBoxMeasureItemEvent Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetSelected(int Index, bool Value);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetTopIndex(int Value);
	Vcl::Stdctrls::TLBGetDataEvent __fastcall GetOnData(void);
	Vcl::Stdctrls::TLBFindDataEvent __fastcall GetOnDataFind(void);
	Vcl::Stdctrls::TLBGetDataObjectEvent __fastcall GetOnDataObject(void);
	void __fastcall SetCount(int Value);
	void __fastcall SetOnData(Vcl::Stdctrls::TLBGetDataEvent Value);
	void __fastcall SetOnDataFind(Vcl::Stdctrls::TLBFindDataEvent Value);
	void __fastcall SetOnDataObject(Vcl::Stdctrls::TLBGetDataObjectEvent Value);
	int __fastcall GetScrollWidth(void);
	int __fastcall GetTabWidth(void);
	void __fastcall SetIntegralHeight(bool Value);
	void __fastcall SetScrollWidth(int Value);
	void __fastcall SetTabWidth(int Value);
	
protected:
	Cxdatautils::TcxCustomDataBinding* FDataBinding;
	virtual void __fastcall DataChange(void);
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall IsReadOnly(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall UpdateData(void);
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual void __fastcall DoSetSize(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall DrawItem(Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual Cxdatautils::TcxCustomDataBindingClass __fastcall GetDataBindingClass(void);
	virtual TcxInnerListBoxClass __fastcall GetInnerListBoxClass(void);
	void __fastcall GetOptimalHeight(int &ANewHeight);
	__property Cxdatautils::TcxCustomDataBinding* DataBinding = {read=FDataBinding};
	
public:
	__fastcall virtual TcxListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxListBox(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	void __fastcall AddItem(System::UnicodeString AItem, System::TObject* AObject);
	void __fastcall Clear(void);
	void __fastcall ClearSelection(void);
	void __fastcall DeleteSelected(void);
	int __fastcall ItemAtPos(const System::Types::TPoint APos, bool AExisting);
	System::Types::TRect __fastcall ItemRect(int Index);
	bool __fastcall ItemVisible(int Index);
	void __fastcall SelectAll(void);
	void __fastcall CopySelection(Vcl::Controls::TCustomListControl* ADestination);
	void __fastcall MoveSelection(Vcl::Controls::TCustomListControl* ADestination);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property Vcl::Stdctrls::TListBox* InnerListBox = {read=GetInnerListBox};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property System::TObject* ItemObject = {read=GetItemObject, write=SetItemObject};
	__property int SelCount = {read=GetSelCount, nodefault};
	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	__property int TopIndex = {read=GetTopIndex, write=SetTopIndex, nodefault};
	
__published:
	__property Anchors = {default=3};
	__property bool AutoComplete = {read=GetAutoComplete, write=SetAutoComplete, default=1};
	__property unsigned AutoCompleteDelay = {read=GetAutoCompleteDelay, write=SetAutoCompleteDelay, default=500};
	__property BiDiMode;
	__property int Columns = {read=GetColumns, write=SetColumns, default=0};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property bool ExtendedSelect = {read=GetExtendedSelect, write=SetExtendedSelect, default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property bool IntegralHeight = {read=FIntegralHeight, write=SetIntegralHeight, default=0};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, nodefault};
	__property System::Classes::TStrings* Items = {read=GetItems, write=SetItems};
	__property Vcl::Stdctrls::TListBoxStyle ListStyle = {read=GetListStyle, write=SetListStyle, default=0};
	__property bool MultiSelect = {read=GetMultiSelect, write=SetMultiSelect, default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property int ScrollWidth = {read=GetScrollWidth, write=SetScrollWidth, default=0};
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
	__property Vcl::Stdctrls::TLBGetDataEvent OnData = {read=GetOnData, write=SetOnData};
	__property Vcl::Stdctrls::TLBFindDataEvent OnDataFind = {read=GetOnDataFind, write=SetOnDataFind};
	__property Vcl::Stdctrls::TLBGetDataObjectEvent OnDataObject = {read=GetOnDataObject, write=SetOnDataObject};
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property TcxListBoxDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property TcxListBoxMeasureItemEvent OnMeasureItem = {read=FOnMeasureItem, write=SetOnMeasureItem};
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxListBox(HWND ParentWindow) : Cxedit::TcxCustomEditContainer(ParentWindow) { }
	
};


class DELPHICLASS TdxCustomListBoxItem;
class DELPHICLASS TdxCustomListBoxItems;
class PASCALIMPLEMENTATION TdxCustomListBoxItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FCaption;
	System::TObject* FData;
	int FImageIndex;
	bool FHasSeparator;
	TdxCustomListBoxItems* FOwner;
	int __fastcall GetIndex(void);
	void __fastcall SetCaption(const System::UnicodeString ACaption);
	void __fastcall SetImageIndex(int AValue);
	void __fastcall SetHasSeparator(const bool Value);
	
protected:
	void __fastcall Changed(void);
	
public:
	__fastcall virtual TdxCustomListBoxItem(TdxCustomListBoxItems* AOwner);
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property System::TObject* Data = {read=FData, write=FData};
	__property bool HasSeparator = {read=FHasSeparator, write=SetHasSeparator, nodefault};
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, nodefault};
	__property int Index = {read=GetIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomListBoxItem(void) { }
	
};


class DELPHICLASS TdxCustomListBox;
class PASCALIMPLEMENTATION TdxCustomListBoxItems : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxCustomListBoxItem* operator[](int Index) { return Items[Index]; }
	
private:
	int FLockCount;
	TdxCustomListBox* FOwnerControl;
	bool FSorted;
	int __fastcall FindInSortedList(const System::UnicodeString ACaption);
	HIDESBASE TdxCustomListBoxItem* __fastcall GetItem(int Index);
	void __fastcall SetSorted(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	__property int LockCount = {read=FLockCount, nodefault};
	
public:
	__fastcall virtual TdxCustomListBoxItems(TdxCustomListBox* AOwnerControl);
	HIDESBASE TdxCustomListBoxItem* __fastcall Add(const System::UnicodeString ACaption, int AImageIndex = 0xffffffff, System::TObject* AData = (System::TObject*)(0x0), bool AHasSeparator = false);
	TdxCustomListBoxItem* __fastcall AddObject(const System::UnicodeString ACaption, System::TObject* AData);
	TdxCustomListBoxItem* __fastcall AddSeparator(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	int __fastcall IndexOfCaption(const System::UnicodeString ACaption, bool ACaseSensitive = true);
	int __fastcall IndexOfObject(System::TObject* AObject);
	HIDESBASE TdxCustomListBoxItem* __fastcall Insert(int AIndex, const System::UnicodeString ACaption, int AImageIndex = 0xffffffff, System::TObject* AData = (System::TObject*)(0x0), bool AHasSeparator = false);
	bool __fastcall IsValidIndex(int AIndex);
	void __fastcall LoadFromStrings(System::Classes::TStrings* AStrings);
	__property TdxCustomListBoxItem* Items[int Index] = {read=GetItem/*, default*/};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxCustomListBoxItems(void) { }
	
};


typedef System::TMetaClass* TdxCustomListBoxItemsClass;

class DELPHICLASS TdxCustomListBoxHintHelper;
class PASCALIMPLEMENTATION TdxCustomListBoxHintHelper : public Dxcustomhint::TcxControlHintHelper
{
	typedef Dxcustomhint::TcxControlHintHelper inherited;
	
private:
	TdxCustomListBox* FOwnerControl;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetOwnerControl(void);
	virtual bool __fastcall PtInCaller(const System::Types::TPoint P);
	
public:
	__fastcall virtual TdxCustomListBoxHintHelper(TdxCustomListBox* AOwnerControl);
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TdxCustomListBoxHintHelper(void) { }
	
};


class PASCALIMPLEMENTATION TdxCustomListBox : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Vcl::Imglist::TChangeLink* FChangeLink;
	TdxCustomListBoxHintHelper* FHintHelper;
	int FHotIndex;
	Vcl::Imglist::TCustomImageList* FImages;
	bool FIncrementalSearch;
	int FItemHeight;
	int FItemIndex;
	TdxCustomListBoxItems* FItems;
	bool FLoopedNavigation;
	System::UnicodeString FSearchText;
	unsigned FStartIncrementalSearch;
	int FTopIndex;
	int __fastcall GetCount(void);
	System::Types::TRect __fastcall GetImagesAreaRect(void);
	int __fastcall GetImagesAreaSize(void);
	bool __fastcall GetIsLocked(void);
	int __fastcall GetItemsHeight(int Index);
	int __fastcall GetMaxTopIndex(void);
	int __fastcall GetPageSize(void);
	bool __fastcall GetSorted(void);
	int __fastcall GetTopIndex(void);
	void __fastcall DoImageListChanged(System::TObject* Sender);
	void __fastcall SetHotIndex(int AValue);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetItemHeight(int AValue);
	void __fastcall SetItemIndex(int AIndex);
	void __fastcall SetSorted(bool AValue);
	void __fastcall SetTopIndex(int AValue);
	bool __fastcall PtInCaller(const System::Types::TPoint P);
	
protected:
	virtual void __fastcall AdjustItemFont(Vcl::Graphics::TFont* AFont, TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	DYNAMIC void __fastcall BoundsChanged(void);
	bool __fastcall CanProcessIncSearch(System::WideChar Key);
	virtual bool __fastcall CanShowHint(int AItemIndex, /* out */ System::Types::TRect &AItemRect, /* out */ System::Types::TRect &AItemTextRect);
	bool __fastcall CanStartIncSearch(System::WideChar Key);
	virtual void __fastcall CheckFocusedItemIndex(void);
	virtual void __fastcall CheckTopItemIndex(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DoLayoutChanged(void);
	virtual void __fastcall EraseBackground(HDC DC)/* overload */;
	bool __fastcall GetHasSeparator(int Index);
	virtual TdxCustomListBoxItemsClass __fastcall GetItemsClass(void);
	virtual bool __fastcall HasBackground(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	void __fastcall InvalidateItem(int AIndex);
	void __fastcall InvalidateItems(const int AIndex1, const int AIndex2);
	virtual bool __fastcall IsIncSearchChar(System::WideChar AChar);
	virtual bool __fastcall IsStartIncSearchChar(System::WideChar AChar);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall MeasureItemHeight(int AIndex, int &AHeight);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall ProcessKeyPress(System::WideChar &Key);
	virtual bool __fastcall ProcessNavigationKey(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall TrackingCallerMouseLeave(void);
	void __fastcall UpdateHintState(void);
	void __fastcall UpdateHotState(void);
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	virtual System::Types::TRect __fastcall GetImageOffsets(void);
	virtual System::Types::TSize __fastcall GetImageSize(void);
	System::Types::TRect __fastcall GetItemImageRect(const System::Types::TRect &AItemRect);
	void __fastcall GetItemPartsRects(int AIndex, const System::Types::TRect &R, /* out */ System::Types::TRect &AItemRect, /* out */ System::Types::TRect &ASeparatorRect);
	System::Types::TRect __fastcall GetItemRect(int AItemIndex, const System::Types::TRect &APrevItemRect);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetItemState(int AIndex);
	System::Types::TRect __fastcall GetItemTextRect(const System::Types::TRect &AItemRect);
	virtual System::Uitypes::TColor __fastcall GetTextColor(TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual int __fastcall GetTextFlags(void);
	virtual System::Types::TRect __fastcall GetTextOffsets(void);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawItem(const System::Types::TRect &R, TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawItemBackground(const System::Types::TRect &R, TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawItemImage(const System::Types::TRect &R, TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawItemText(const System::Types::TRect &R, TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawItemSeparator(const System::Types::TRect &R);
	virtual void __fastcall Paint(void);
	virtual void __fastcall ClearIncrementalSearch(void);
	virtual bool __fastcall DoIncrementalSearch(System::WideChar &Key);
	bool __fastcall FocusNextItemWithText(const System::UnicodeString AText);
	bool __fastcall FocusItemWithText(const System::UnicodeString AText, int AStartIndex, int AFinishIndex);
	int __fastcall GetValidIndex(int AIndex);
	__property TdxCustomListBoxHintHelper* HintHelper = {read=FHintHelper};
	__property int HotIndex = {read=FHotIndex, write=SetHotIndex, nodefault};
	__property System::Types::TRect ImageOffsets = {read=GetImageOffsets};
	__property System::Types::TRect ImagesAreaRect = {read=GetImagesAreaRect};
	__property int ImagesAreaSize = {read=GetImagesAreaSize, nodefault};
	__property System::Types::TSize ImageSize = {read=GetImageSize};
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	__property int ItemsHeight[int Index] = {read=GetItemsHeight};
	__property int MaxTopIndex = {read=GetMaxTopIndex, nodefault};
	__property int PageSize = {read=GetPageSize, nodefault};
	__property System::UnicodeString SearchText = {read=FSearchText, write=FSearchText};
	__property System::Types::TRect TextOffsets = {read=GetTextOffsets};
	
public:
	__fastcall virtual TdxCustomListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomListBox(void);
	int __fastcall Add(const System::UnicodeString ACaption, int AImageIndex = 0xffffffff);
	int __fastcall AddItem(const System::UnicodeString ACaption, System::TObject* AObject, int AImageIndex = 0xffffffff);
	virtual System::Types::TSize __fastcall CalculateContentSize(int AMaxVisibleItemsCount);
	virtual int __fastcall CalculateItemHeight(void);
	void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	void __fastcall EndUpdate(void);
	virtual int __fastcall ItemAtPos(const System::Types::TPoint APoint, bool AExistOnly = false);
	System::Types::TRect __fastcall ItemRect(int AIndex);
	void __fastcall LayoutChanged(void);
	void __fastcall MakeVisible(int AIndex);
	HIDESBASE int __fastcall Remove(System::TObject* AObject);
	__property int Count = {read=GetCount, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property bool IncrementalSearch = {read=FIncrementalSearch, write=FIncrementalSearch, nodefault};
	__property int ItemHeight = {read=FItemHeight, write=SetItemHeight, nodefault};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, nodefault};
	__property TdxCustomListBoxItems* Items = {read=FItems, write=FItems};
	__property bool LoopedNavigation = {read=FLoopedNavigation, write=FLoopedNavigation, nodefault};
	__property int TopIndex = {read=GetTopIndex, write=SetTopIndex, nodefault};
	__property bool Sorted = {read=GetSorted, write=SetSorted, nodefault};
	__property Color = {default=-16777211};
	__property Font;
	__property LookAndFeel;
	__property OnClick;
	__property OnDblClick;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomListBox(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  EraseBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect){ Cxcontrols::TcxControl::EraseBackground(ACanvas, ARect); }
	
private:
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	
};


typedef void __fastcall (__closure *TdxCustomDropDownListBoxCloseUpEvent)(System::TObject* Sender, bool AClosedViaKeyboard);

typedef void __fastcall (__closure *TdxCustomDropDownListBoxSelectedEvent)(System::TObject* Sender, TdxCustomListBoxItem* AItem, bool ASelectedViaKeyboard);

class DELPHICLASS TdxCustomDropDownInnerListBox;
class PASCALIMPLEMENTATION TdxCustomDropDownInnerListBox : public TdxCustomListBox
{
	typedef TdxCustomListBox inherited;
	
private:
	int FDefaultItemIndex;
	System::Types::TPoint FPrevMousePosition;
	TdxCustomDropDownListBoxSelectedEvent FOnSelectItem;
	void __fastcall SetDefaultItemIndex(int AValue);
	
protected:
	virtual void __fastcall AdjustItemFont(Vcl::Graphics::TFont* AFont, TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DoLayoutChanged(void);
	virtual void __fastcall DoSelectItem(bool ASelectedViaKeyboard);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawItemBackground(const System::Types::TRect &R, TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual int __fastcall GetBorderSize(void);
	virtual System::Types::TRect __fastcall GetImageOffsets(void);
	virtual System::Types::TSize __fastcall GetImageSize(void);
	virtual System::Uitypes::TColor __fastcall GetTextColor(TdxCustomListBoxItem* AItem, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Types::TRect __fastcall GetTextOffsets(void);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall ProcessNavigationKey(System::Word &Key, System::Classes::TShiftState Shift);
	
public:
	__fastcall virtual TdxCustomDropDownInnerListBox(System::Classes::TComponent* AOwner);
	__property int DefaultItemIndex = {read=FDefaultItemIndex, write=SetDefaultItemIndex, default=-1};
	__property TdxCustomDropDownListBoxSelectedEvent OnSelectItem = {read=FOnSelectItem, write=FOnSelectItem};
public:
	/* TdxCustomListBox.Destroy */ inline __fastcall virtual ~TdxCustomDropDownInnerListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomDropDownInnerListBox(HWND ParentWindow) : TdxCustomListBox(ParentWindow) { }
	
};


class DELPHICLASS TdxCustomDropDownListBox;
class PASCALIMPLEMENTATION TdxCustomDropDownListBox : public Cxcontainer::TcxCustomPopupWindow
{
	typedef Cxcontainer::TcxCustomPopupWindow inherited;
	
private:
	unsigned FDisplayRowsCount;
	TdxCustomDropDownInnerListBox* FInnerListBox;
	unsigned FMaxWidth;
	unsigned FMinWidth;
	TdxCustomDropDownListBoxCloseUpEvent FOnCloseUp;
	TdxCustomDropDownListBoxSelectedEvent FOnSelect;
	void __fastcall ItemSelected(System::TObject* Sender, TdxCustomListBoxItem* AItem, bool ASelectedViaKeyboard);
	int __fastcall GetCount(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	int __fastcall GetItemHeight(void);
	int __fastcall GetItemIndex(void);
	TdxCustomListBoxItems* __fastcall GetItems(void);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* const Value);
	void __fastcall SetItemHeight(const int Value);
	void __fastcall SetItemIndex(const int Value);
	
protected:
	bool FClosedViaKeyboard;
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual System::Types::TPoint __fastcall CalculatePosition(void);
	virtual void __fastcall CalculateSize(void);
	virtual TdxCustomDropDownInnerListBox* __fastcall CreateInnerListBox(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DoCloseUp(bool AClosedViaKeyboard);
	DYNAMIC void __fastcall DoHide(void);
	virtual void __fastcall DoSelectItem(TdxCustomListBoxItem* AItem, bool ASelectedViaKeyboard);
	virtual void __fastcall InitInnerListBox(void);
	virtual void __fastcall InitPopup(void);
	
public:
	__fastcall virtual TdxCustomDropDownListBox(Vcl::Controls::TWinControl* AOwnerControl);
	__fastcall TdxCustomDropDownListBox(Vcl::Controls::TWinControl* AOwnerControl, Cxcontrols::TcxControl* AOwnerParent);
	__fastcall virtual ~TdxCustomDropDownListBox(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	DYNAMIC bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	HIDESBASE virtual void __fastcall CloseUp(bool AClosedViaKeyboard);
	HIDESBASE virtual void __fastcall Popup(void);
	void __fastcall PopupForBounds(const System::Types::TRect &ABounds, System::WideChar AActivateKey = (System::WideChar)(0x0));
	__property int Count = {read=GetCount, nodefault};
	__property unsigned DisplayRowsCount = {read=FDisplayRowsCount, write=FDisplayRowsCount, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=GetImages, write=SetImages};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, nodefault};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property TdxCustomListBoxItems* Items = {read=GetItems};
	__property TdxCustomDropDownInnerListBox* InnerListBox = {read=FInnerListBox};
	__property unsigned MaxWidth = {read=FMaxWidth, write=FMaxWidth, nodefault};
	__property unsigned MinWidth = {read=FMinWidth, write=FMinWidth, nodefault};
	__property TdxCustomDropDownListBoxCloseUpEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	__property TdxCustomDropDownListBoxSelectedEvent OnSelect = {read=FOnSelect, write=FOnSelect};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxCustomDropDownListBox(System::Classes::TComponent* AOwner, int Dummy) : Cxcontainer::TcxCustomPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomDropDownListBox(HWND ParentWindow) : Cxcontainer::TcxCustomPopupWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxlistbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLISTBOX)
using namespace Cxlistbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlistboxHPP
