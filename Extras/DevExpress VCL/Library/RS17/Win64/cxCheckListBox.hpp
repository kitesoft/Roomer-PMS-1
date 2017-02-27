// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCheckListBox.pas' rev: 24.00 (Win64)

#ifndef CxchecklistboxHPP
#define CxchecklistboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxExtEditUtils.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxchecklistbox
{
//-- type declarations -------------------------------------------------------
enum TcxCheckListBoxImageLayout : unsigned char { ilBeforeChecks, ilAfterChecks };

typedef void __fastcall (__closure *TcxClickCheckEvent)(System::TObject* Sender, int AIndex, Cxlookandfeelpainters::TcxCheckBoxState APrevState, Cxlookandfeelpainters::TcxCheckBoxState ANewState);

typedef void __fastcall (__closure *TcxCheckStatesToEditValueEvent)(System::TObject* Sender, const Cxcheckbox::TcxCheckStates ACheckStates, /* out */ System::Variant &AEditValue);

typedef void __fastcall (__closure *TcxEditValueToCheckStatesEvent)(System::TObject* Sender, const System::Variant &AEditValue, Cxcheckbox::TcxCheckStates &ACheckStates);

class DELPHICLASS TcxCheckListBoxItem;
class DELPHICLASS TcxCustomInnerCheckListBox;
class DELPHICLASS TcxCheckListBoxItems;
class PASCALIMPLEMENTATION TcxCheckListBoxItem : public Cxcheckbox::TcxCaptionItem
{
	typedef Cxcheckbox::TcxCaptionItem inherited;
	
private:
	bool FEnabled;
	System::Uitypes::TImageIndex FImageIndex;
	System::TObject* FItemObject;
	Cxlookandfeelpainters::TcxCheckBoxState FState;
	bool __fastcall GetChecked(void);
	TcxCustomInnerCheckListBox* __fastcall GetCheckListBox(void);
	TcxCheckListBoxItems* __fastcall GetCollection(void);
	Vcl::Controls::TCaption __fastcall GetText(void);
	void __fastcall SetText(const Vcl::Controls::TCaption Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	void __fastcall SetState(Cxlookandfeelpainters::TcxCheckBoxState Value);
	void __fastcall SetChecked(bool Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	__property TcxCustomInnerCheckListBox* CheckListBox = {read=GetCheckListBox};
	__property TcxCheckListBoxItems* Collection = {read=GetCollection};
	
public:
	__fastcall virtual TcxCheckListBoxItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool Checked = {read=GetChecked, write=SetChecked, nodefault};
	__property System::TObject* ItemObject = {read=FItemObject, write=FItemObject};
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property Cxlookandfeelpainters::TcxCheckBoxState State = {read=FState, write=SetState, default=0};
	__property Tag;
	__property Vcl::Controls::TCaption Text = {read=GetText, write=SetText};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxCheckListBoxItem(void) { }
	
};


class PASCALIMPLEMENTATION TcxCheckListBoxItems : public Cxcheckbox::TcxCaptionItems
{
	typedef Cxcheckbox::TcxCaptionItems inherited;
	
public:
	TcxCheckListBoxItem* operator[](int Index) { return Items[Index]; }
	
private:
	int FChangedLockCount;
	TcxCustomInnerCheckListBox* FCheckListBox;
	TcxCheckListBoxItem* __fastcall GetItems(int Index);
	System::TObject* __fastcall GetObjects(int Index);
	void __fastcall SetItems(int Index, TcxCheckListBoxItem* const Value);
	void __fastcall SetObjects(int Index, System::TObject* Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	bool __fastcall IsChangedLocked(void);
	void __fastcall LockChanged(bool ALock, bool AInvokeChangedOnUnlock = true);
	
public:
	__fastcall TcxCheckListBoxItems(TcxCustomInnerCheckListBox* AOwner, System::Classes::TCollectionItemClass AItemClass);
	__fastcall virtual ~TcxCheckListBoxItems(void);
	__property TcxCustomInnerCheckListBox* CheckListBox = {read=FCheckListBox};
	__property TcxCheckListBoxItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
	HIDESBASE TcxCheckListBoxItem* __fastcall Add(void);
	HIDESBASE void __fastcall Delete(int Index);
	int __fastcall IndexOf(const Vcl::Controls::TCaption S);
	int __fastcall IndexOfObject(System::TObject* AObject);
	void __fastcall LoadStrings(System::Classes::TStrings* AStrings);
	__property System::TObject* Objects[int Index] = {read=GetObjects, write=SetObjects};
};


struct DECLSPEC_DRECORD TcxCheckListBoxMetrics
{
public:
	int CheckFrameWidth;
	int ContentOffset;
	int ImageFrameWidth;
	int TextAreaOffset;
	int TextOffset;
	int TextWidthCorrection;
};


class DELPHICLASS TcxCustomCheckListBox;
class PASCALIMPLEMENTATION TcxCustomInnerCheckListBox : public Cxcontainer::TcxCustomInnerListBox
{
	typedef Cxcontainer::TcxCustomInnerListBox inherited;
	
private:
	bool FAllowGrayed;
	bool FAllowDblClickToggle;
	int FCapturedCheckIndex;
	TcxCheckListBoxItems* FCheckItems;
	Vcl::Graphics::TBitmap* FGlyph;
	int FGlyphCount;
	int FHotCheckIndex;
	TcxCheckListBoxMetrics FMetrics;
	int FNewPressedCheckIndex;
	bool FNewPressedCheckItemFullyVisible;
	int FPressedCheckIndex;
	TcxClickCheckEvent FOnClickCheck;
	TcxCustomCheckListBox* __fastcall GetContainer(void);
	void __fastcall DrawCheck(System::Types::TRect &R, Cxlookandfeelpainters::TcxCheckBoxState AState, Cxlookandfeelpainters::TcxEditCheckState ACheckState);
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetGlyphCount(int Value);
	void __fastcall ToggleClickCheck(int Index);
	void __fastcall InvalidateCheck(int Index);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CNDrawItem(Winapi::Messages::TWMDrawItem &Message);
	HIDESBASE MESSAGE void __fastcall CNMeasureItem(Winapi::Messages::TWMMeasureItem &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	
protected:
	void __fastcall MouseTrackingMouseLeave(void);
	void __fastcall AdjustItemHeight(void);
	void __fastcall CheckHotTrack(void);
	DYNAMIC void __fastcall Click(void);
	int __fastcall GetCheckAt(int X, int Y);
	System::Types::TSize __fastcall GetCheckAreaSize(void);
	System::Types::TRect __fastcall GetCheckAreaRect(const System::Types::TRect &R);
	void __fastcall GetCheckMetrics(/* out */ System::Types::TSize &ACheckSize, /* out */ int &ACheckBorderOffset);
	System::Types::TRect __fastcall GetCheckRect(const System::Types::TRect &R, bool AReturnFullRect);
	virtual int __fastcall GetCheckRegionWidth(void);
	virtual TcxCheckListBoxMetrics __fastcall GetMetrics(void);
	virtual int __fastcall GetStandardItemHeight(void);
	void __fastcall InternalMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall FullRepaint(void);
	virtual void __fastcall InvalidateItem(int Index);
	void __fastcall SynchronizeCheckStates(int ANewHotCheckIndex, int ANewPressedCheckIndex);
	void __fastcall UpdateCheckStates(void);
	void __fastcall UpdateEditValue(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	virtual void __fastcall DoClickCheck(const int AIndex, const Cxlookandfeelpainters::TcxCheckBoxState OldState, const Cxlookandfeelpainters::TcxCheckBoxState NewState);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall DblClick(void);
	__property bool AllowDblClickToggle = {read=FAllowDblClickToggle, write=FAllowDblClickToggle, default=1};
	__property bool AllowGrayed = {read=FAllowGrayed, write=FAllowGrayed, default=0};
	__property TcxCheckListBoxItems* CheckItems = {read=FCheckItems, write=FCheckItems};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int GlyphCount = {read=FGlyphCount, write=SetGlyphCount, default=6};
	__property TcxCheckListBoxMetrics Metrics = {read=FMetrics};
	__property TcxClickCheckEvent OnClickCheck = {read=FOnClickCheck, write=FOnClickCheck};
	
public:
	__fastcall virtual TcxCustomInnerCheckListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerCheckListBox(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	__property TcxCustomCheckListBox* Container = {read=GetContainer};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerCheckListBox(HWND ParentWindow) : Cxcontainer::TcxCustomInnerListBox(ParentWindow) { }
	
private:
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	void *__IInterface;	/* System::IInterface */
	
public:
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};


typedef System::TMetaClass* TcxCustomInnerCheckListBoxClass;

class PASCALIMPLEMENTATION TcxCustomCheckListBox : public Cxedit::TcxCustomEditContainer
{
	typedef Cxedit::TcxCustomEditContainer inherited;
	
private:
	Cxedit::TcxEditBorderStyle FCheckBorderStyle;
	System::Variant FEditValue;
	Cxcheckbox::TcxCheckStatesValueFormatEx FEditValueFormat;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TChangeLink* FImagesChangeLink;
	TcxCheckListBoxImageLayout FImageLayout;
	TcxCustomInnerCheckListBox* FInnerCheckListBox;
	bool FIntegralHeight;
	bool FIsExitProcessing;
	bool FIsModified;
	Vcl::Stdctrls::TListBoxStyle FListStyle;
	bool FLoadedSortedValue;
	bool FNativeStyle;
	bool FShowChecks;
	TcxCheckStatesToEditValueEvent FOnCheckStatesToEditValue;
	Vcl::Stdctrls::TDrawItemEvent FOnDrawItem;
	System::Classes::TNotifyEvent FOnEditValueChanged;
	TcxEditValueToCheckStatesEvent FOnEditValueToCheckStates;
	Vcl::Stdctrls::TMeasureItemEvent FOnMeasureItem;
	TcxClickCheckEvent __fastcall GetOnClickCheck(void);
	Cxclasses::TcxCollectionCompareEvent __fastcall GetOnCompare(void);
	bool __fastcall GetAllowGrayed(void);
	bool __fastcall GetAllowDblClickToggle(void);
	bool __fastcall GetAutoComplete(void);
	unsigned __fastcall GetAutoCompleteDelay(void);
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	int __fastcall GetGlyphCount(void);
	int __fastcall GetItemHeight(void);
	TcxCheckListBoxItems* __fastcall GetItems(void);
	int __fastcall GetColumns(void);
	int __fastcall GetCount(void);
	int __fastcall GetItemIndex(void);
	int __fastcall GetScrollWidth(void);
	bool __fastcall GetSelected(int Index);
	bool __fastcall GetSorted(void);
	int __fastcall GetTabWidth(void);
	int __fastcall GetTopIndex(void);
	void __fastcall ImagesChanged(System::TObject* Sender);
	bool __fastcall IsItemHeightStored(void);
	void __fastcall SetOnClickCheck(TcxClickCheckEvent Value);
	void __fastcall SetOnCompare(Cxclasses::TcxCollectionCompareEvent Value);
	void __fastcall SetAllowGrayed(bool Value);
	void __fastcall SetAllowDblClickToggle(bool Value);
	void __fastcall SetAutoComplete(bool Value);
	void __fastcall SetAutoCompleteDelay(unsigned Value);
	void __fastcall SetDataBinding(Cxdatautils::TcxCustomDataBinding* Value);
	void __fastcall SetEditValueFormat(Cxcheckbox::TcxCheckStatesValueFormat Value);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetGlyphCount(int Value);
	void __fastcall SetItemHeight(int Value);
	void __fastcall SetItems(TcxCheckListBoxItems* Value);
	void __fastcall SetColumns(int Value);
	void __fastcall SetImageLayout(TcxCheckListBoxImageLayout Value);
	void __fastcall SetIntegralHeight(bool Value);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetListStyle(Vcl::Stdctrls::TListBoxStyle Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetScrollWidth(int Value);
	void __fastcall SetSelected(int Index, bool Value);
	void __fastcall SetShowChecks(bool Value);
	void __fastcall SetSorted(bool Value);
	void __fastcall SetTabWidth(int Value);
	void __fastcall SetTopIndex(int Value);
	void __fastcall SetCount(int Value);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall CheckEditValueFormat(void);
	Cxcheckbox::TcxCheckStatesValueFormatEx __fastcall GetRealEditValueFormat(void);
	void __fastcall ItemsChanged(System::TObject* Sender, System::Classes::TCollectionItem* AItem);
	
protected:
	Cxdatautils::TcxCustomDataBinding* FDataBinding;
	void __fastcall CalculateDrawCheckParams(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual bool __fastcall IsReadOnly(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	DYNAMIC void __fastcall FontChanged(void);
	void __fastcall GetOptimalHeight(int &ANewHeight);
	virtual bool __fastcall IsInternalControl(Vcl::Controls::TControl* AControl);
	virtual void __fastcall DoSetSize(void);
	__classmethod virtual Cxdatautils::TcxCustomDataBindingClass __fastcall GetDataBindingClass();
	virtual void __fastcall DataChange(void);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall DrawItem(Vcl::Controls::TWinControl* Control, int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	virtual void __fastcall DoEditValueChanged(void);
	virtual TcxCustomInnerCheckListBoxClass __fastcall GetInnerCheckListBoxClass(void);
	virtual void __fastcall SetEditValue(const System::Variant &Value);
	virtual bool __fastcall IsValueValid(const System::Variant &AValue, bool AAllowEmpty);
	__property bool AllowDblClickToggle = {read=GetAllowDblClickToggle, write=SetAllowDblClickToggle, default=1};
	__property bool AllowGrayed = {read=GetAllowGrayed, write=SetAllowGrayed, default=0};
	__property bool AutoComplete = {read=GetAutoComplete, write=SetAutoComplete, default=1};
	__property unsigned AutoCompleteDelay = {read=GetAutoCompleteDelay, write=SetAutoCompleteDelay, default=500};
	__property int Columns = {read=GetColumns, write=SetColumns, default=0};
	__property Cxdatautils::TcxCustomDataBinding* DataBinding = {read=FDataBinding, write=SetDataBinding};
	__property System::Variant EditValue = {read=FEditValue, write=SetEditValue, stored=false};
	__property Cxcheckbox::TcxCheckStatesValueFormat EditValueFormat = {read=FEditValueFormat, write=SetEditValueFormat, default=2};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int GlyphCount = {read=GetGlyphCount, write=SetGlyphCount, default=6};
	__property TcxCheckListBoxImageLayout ImageLayout = {read=FImageLayout, write=SetImageLayout, default=0};
	__property bool IntegralHeight = {read=FIntegralHeight, write=SetIntegralHeight, default=0};
	__property int ItemHeight = {read=GetItemHeight, write=SetItemHeight, stored=IsItemHeightStored, nodefault};
	__property Vcl::Stdctrls::TListBoxStyle ListStyle = {read=FListStyle, write=SetListStyle, default=0};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
	__property int ScrollWidth = {read=GetScrollWidth, write=SetScrollWidth, default=0};
	__property bool ShowChecks = {read=FShowChecks, write=SetShowChecks, default=1};
	__property bool Sorted = {read=GetSorted, write=SetSorted, default=0};
	__property int TabWidth = {read=GetTabWidth, write=SetTabWidth, default=0};
	__property TcxCheckStatesToEditValueEvent OnCheckStatesToEditValue = {read=FOnCheckStatesToEditValue, write=FOnCheckStatesToEditValue};
	__property TcxClickCheckEvent OnClickCheck = {read=GetOnClickCheck, write=SetOnClickCheck};
	__property Cxclasses::TcxCollectionCompareEvent OnCompare = {read=GetOnCompare, write=SetOnCompare};
	__property Vcl::Stdctrls::TDrawItemEvent OnDrawItem = {read=FOnDrawItem, write=FOnDrawItem};
	__property System::Classes::TNotifyEvent OnEditValueChanged = {read=FOnEditValueChanged, write=FOnEditValueChanged};
	__property TcxEditValueToCheckStatesEvent OnEditValueToCheckStates = {read=FOnEditValueToCheckStates, write=FOnEditValueToCheckStates};
	__property Vcl::Stdctrls::TMeasureItemEvent OnMeasureItem = {read=FOnMeasureItem, write=FOnMeasureItem};
	
public:
	__fastcall virtual TcxCustomCheckListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomCheckListBox(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	int __fastcall CheckAtPos(const System::Types::TPoint APos);
	void __fastcall Clear(void);
	int __fastcall GetBestFitWidth(void);
	virtual int __fastcall GetHeight(int ARowCount);
	virtual int __fastcall GetItemWidth(int AIndex);
	int __fastcall ItemAtPos(const System::Types::TPoint APos, bool AExisting);
	System::Types::TRect __fastcall ItemRect(int Index);
	void __fastcall Sort(void);
	void __fastcall AddItem(const System::UnicodeString AItem);
	void __fastcall CopySelection(TcxCustomCheckListBox* ADestination);
	void __fastcall DeleteSelected(void);
	void __fastcall MoveSelection(TcxCustomCheckListBox* ADestination);
	__property TcxCustomInnerCheckListBox* InnerCheckListBox = {read=FInnerCheckListBox, write=FInnerCheckListBox};
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property bool IsModified = {read=FIsModified, write=FIsModified, nodefault};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, nodefault};
	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	__property int TopIndex = {read=GetTopIndex, write=SetTopIndex, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
	__property TcxCheckListBoxItems* Items = {read=GetItems, write=SetItems};
	__property LookAndFeel;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCheckListBox(HWND ParentWindow) : Cxedit::TcxCustomEditContainer(ParentWindow) { }
	
};


class DELPHICLASS TcxCheckListBox;
class PASCALIMPLEMENTATION TcxCheckListBox : public TcxCustomCheckListBox
{
	typedef TcxCustomCheckListBox inherited;
	
__published:
	__property AllowDblClickToggle = {default=1};
	__property AllowGrayed = {default=0};
	__property Anchors = {default=3};
	__property AutoComplete = {default=1};
	__property AutoCompleteDelay = {default=500};
	__property BiDiMode;
	__property Columns = {default=0};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property EditValue = {default=0};
	__property EditValueFormat = {default=2};
	__property Enabled = {default=1};
	__property Glyph;
	__property GlyphCount = {default=6};
	__property Images;
	__property ImageLayout = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property IntegralHeight = {default=0};
	__property Items;
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property ScrollWidth = {default=0};
	__property ShowChecks = {default=1};
	__property ShowHint;
	__property Sorted = {default=0};
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property TabWidth = {default=0};
	__property Visible = {default=1};
	__property OnCheckStatesToEditValue;
	__property OnClick;
	__property OnClickCheck;
	__property OnCompare;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnDrawItem;
	__property OnEditValueChanged;
	__property OnEditValueToCheckStates;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMeasureItem;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomCheckListBox.Create */ inline __fastcall virtual TcxCheckListBox(System::Classes::TComponent* AOwner) : TcxCustomCheckListBox(AOwner) { }
	/* TcxCustomCheckListBox.Destroy */ inline __fastcall virtual ~TcxCheckListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCheckListBox(HWND ParentWindow) : TcxCustomCheckListBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxchecklistbox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCHECKLISTBOX)
using namespace Cxchecklistbox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxchecklistboxHPP
