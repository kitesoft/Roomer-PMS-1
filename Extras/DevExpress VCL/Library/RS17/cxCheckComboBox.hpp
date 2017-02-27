// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCheckComboBox.pas' rev: 24.00 (Win32)

#ifndef CxcheckcomboboxHPP
#define CxcheckcomboboxHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditUtils.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxExtEditUtils.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcheckcombobox
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCheckComboBoxItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCheckComboBoxItem : public Cxgroupbox::TcxButtonGroupItem
{
	typedef Cxgroupbox::TcxButtonGroupItem inherited;
	
private:
	Vcl::Controls::TCaption FShortDescription;
	Vcl::Controls::TCaption __fastcall GetDescription(void);
	void __fastcall SetDescription(const Vcl::Controls::TCaption Value);
	void __fastcall SetShortDescription(const Vcl::Controls::TCaption Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayDescription(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Controls::TCaption Description = {read=GetDescription, write=SetDescription};
	__property Enabled = {default=1};
	__property Vcl::Controls::TCaption ShortDescription = {read=FShortDescription, write=SetShortDescription};
	__property Tag;
public:
	/* TcxButtonGroupItem.Create */ inline __fastcall virtual TcxCheckComboBoxItem(System::Classes::TCollection* Collection) : Cxgroupbox::TcxButtonGroupItem(Collection) { }
	/* TcxButtonGroupItem.Destroy */ inline __fastcall virtual ~TcxCheckComboBoxItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCheckComboBoxItems;
class PASCALIMPLEMENTATION TcxCheckComboBoxItems : public Cxgroupbox::TcxButtonGroupItems
{
	typedef Cxgroupbox::TcxButtonGroupItems inherited;
	
public:
	TcxCheckComboBoxItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCheckComboBoxItem* __fastcall GetItems(int Index);
	void __fastcall SetItems(int Index, TcxCheckComboBoxItem* const Value);
	
public:
	HIDESBASE TcxCheckComboBoxItem* __fastcall Add(void);
	TcxCheckComboBoxItem* __fastcall AddCheckItem(const Vcl::Controls::TCaption ADescription, const Vcl::Controls::TCaption AShortDescription = Vcl::Controls::TCaption());
	__property TcxCheckComboBoxItem* Items[int Index] = {read=GetItems, write=SetItems/*, default*/};
public:
	/* TcxOwnedInterfacedCollection.Destroy */ inline __fastcall virtual ~TcxCheckComboBoxItems(void) { }
	
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxCheckComboBoxItems(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : Cxgroupbox::TcxButtonGroupItems(AOwner, ItemClass) { }
	
};


class DELPHICLASS TcxCustomCheckComboBoxViewData;
class DELPHICLASS TcxCustomCheckComboBoxProperties;
class PASCALIMPLEMENTATION TcxCustomCheckComboBoxViewData : public Cxdropdownedit::TcxCustomDropDownEditViewData
{
	typedef Cxdropdownedit::TcxCustomDropDownEditViewData inherited;
	
protected:
	HIDESBASE TcxCustomCheckComboBoxProperties* __fastcall GetProperties(void);
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	virtual bool __fastcall IsComboBoxStyle(void);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	__property TcxCustomCheckComboBoxProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomCheckComboBoxViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxdropdownedit::TcxCustomDropDownEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomCheckComboBoxViewData(void) { }
	
};


class DELPHICLASS TcxCustomCheckComboBoxListBox;
class DELPHICLASS TcxCustomCheckComboBox;
class PASCALIMPLEMENTATION TcxCustomCheckComboBoxListBox : public Cxdropdownedit::TcxCustomComboBoxListBox
{
	typedef Cxdropdownedit::TcxCustomComboBoxListBox inherited;
	
private:
	int FCapturedCheckIndex;
	int FCheckBorderOffset;
	System::Types::TSize FCheckSize;
	int FHotCheckIndex;
	bool FInternalUpdate;
	int FPressedCheckIndex;
	HIDESBASE TcxCustomCheckComboBox* __fastcall GetEdit(void);
	HIDESBASE MESSAGE void __fastcall LBGetTextLen(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	
protected:
	void __fastcall MouseTrackingMouseLeave(void);
	void __fastcall CheckHotTrack(void);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual void __fastcall DrawItem(int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall FullRepaint(void);
	int __fastcall GetCheckAt(int X, int Y);
	System::Types::TRect __fastcall GetCheckRect(const System::Types::TRect &R, bool AReturnFullRect);
	void __fastcall InternalMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall InvalidateCheck(int Index);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall RecreateWindow(void);
	virtual void __fastcall SetItemIndex(const int Value)/* overload */;
	void __fastcall SynchronizeCheckStates(int ANewHotCheckIndex, int ANewPressedIndex);
	virtual void __fastcall UpdateItemState(const int AIndex);
	__property TcxCustomCheckComboBox* Edit = {read=GetEdit};
	
public:
	__fastcall virtual TcxCustomCheckComboBoxListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomCheckComboBoxListBox(void);
	virtual int __fastcall GetItemHeight(int AIndex = 0xffffffff);
	virtual int __fastcall GetItemWidth(int AIndex);
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCheckComboBoxListBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBoxListBox(ParentWindow) { }
	
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


class DELPHICLASS TcxCheckComboBoxLookupData;
class PASCALIMPLEMENTATION TcxCheckComboBoxLookupData : public Cxdropdownedit::TcxComboBoxLookupData
{
	typedef Cxdropdownedit::TcxComboBoxLookupData inherited;
	
protected:
	virtual Cxtextedit::TcxCustomEditListBoxClass __fastcall GetListBoxClass(void);
	virtual System::UnicodeString __fastcall GetItem(int Index);
	virtual int __fastcall GetItemCount(void);
	
public:
	virtual void __fastcall TextChanged(void);
public:
	/* TcxCustomTextEditLookupData.Create */ inline __fastcall virtual TcxCheckComboBoxLookupData(System::Classes::TPersistent* AOwner) : Cxdropdownedit::TcxComboBoxLookupData(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCheckComboBoxLookupData(void) { }
	
};


class DELPHICLASS TcxCheckPaintHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCheckPaintHelper : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	Cxedit::TcxCustomEditStyle* FStyle;
	Vcl::Graphics::TBitmap* FGlyph;
	int FGlyphCount;
	void __fastcall SetStyle(Cxedit::TcxCustomEditStyle* Value);
	
protected:
	virtual Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetNextState(Cxlookandfeelpainters::TcxCheckBoxState Value);
	__property Cxedit::TcxCustomEditStyle* Style = {read=FStyle, write=SetStyle};
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=FGlyph};
	__property int GlyphCount = {read=FGlyphCount, write=FGlyphCount, nodefault};
	virtual System::Types::TRect __fastcall CalcTextRect(const System::Types::TRect &ARect, const Cxlookandfeelpainters::TcxCheckBoxState ACheckState);
	virtual System::Types::TPoint __fastcall CalcCheckPoint(const System::Types::TRect &ARect, const Cxlookandfeelpainters::TcxCheckBoxState ACheckState);
	bool __fastcall IsClickInCheck(const System::Types::TRect &AItemRect, const Cxlookandfeelpainters::TcxCheckBoxState ACheckState, int X, int Y, const bool AUseRightToLeftAlignment = false);
	virtual int __fastcall GetCheckWidth(void);
	
public:
	__fastcall virtual TcxCheckPaintHelper(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCheckPaintHelper(void);
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxCheckComboClickCheckEvent)(System::TObject* Sender, int ItemIndex, bool &AllowToggle);

class PASCALIMPLEMENTATION TcxCustomCheckComboBoxProperties : public Cxdropdownedit::TcxCustomComboBoxProperties
{
	typedef Cxdropdownedit::TcxCustomComboBoxProperties inherited;
	
private:
	bool FAllowGrayed;
	TcxCheckPaintHelper* FCheckPaintHelper;
	System::UnicodeString FDelimiter;
	Cxcheckbox::TcxCheckStatesValueFormatEx FEditValueFormat;
	System::UnicodeString FEmptySelectionText;
	Vcl::Graphics::TBitmap* FGlyph;
	int FGlyphCount;
	TcxCheckComboBoxItems* FItems;
	bool FShowEmptyText;
	TcxCheckComboClickCheckEvent FOnClickCheck;
	Cxcheckbox::TcxValueToCheckStatesEvent FOnEditValueToStates;
	Cxcheckbox::TcxCheckStatesToValueEvent FOnStatesToEditValue;
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	bool __fastcall IsDelimiterStored(void);
	bool __fastcall IsEmptySelectionTextStored(void);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetGlyphCount(int Value);
	void __fastcall SetDelimiter(System::UnicodeString Value);
	void __fastcall SetEditValueFormat(Cxcheckbox::TcxCheckStatesValueFormat Value);
	void __fastcall SetEmptySelectionText(System::UnicodeString Value);
	void __fastcall SetShowEmptyText(bool Value);
	HIDESBASE void __fastcall SetItems(TcxCheckComboBoxItems* const Value);
	void __fastcall CheckEditValueFormat(void);
	Cxcheckbox::TcxCheckStatesValueFormatEx __fastcall GetRealEditValueFormat(void);
	void __fastcall ItemsChanged(System::TObject* Sender, System::Classes::TCollectionItem* AItem);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	__classmethod virtual Cxdropdownedit::TcxCustomEditPopupWindowClass __fastcall GetPopupWindowClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	virtual void __fastcall CalculateCheckStatesByEditValue(System::TObject* Sender, const System::Variant &AEditValue, Cxcheckbox::TcxCheckStates &ACheckStates);
	virtual System::UnicodeString __fastcall CalculateDisplayValueByCheckStates(const Cxcheckbox::TcxCheckStates ACheckStates);
	virtual System::Variant __fastcall CalculateEditValueByCheckStates(System::TObject* Sender, const Cxcheckbox::TcxCheckStates ACheckStates);
	__property bool AllowGrayed = {read=FAllowGrayed, write=FAllowGrayed, stored=false, nodefault};
	
public:
	__fastcall virtual TcxCustomCheckComboBoxProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomCheckComboBoxProperties(void);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	__property Cxcheckbox::TcxCheckStatesValueFormat EditValueFormat = {read=FEditValueFormat, write=SetEditValueFormat, default=2};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int GlyphCount = {read=FGlyphCount, write=SetGlyphCount, default=6};
	__property System::UnicodeString Delimiter = {read=FDelimiter, write=SetDelimiter, stored=IsDelimiterStored};
	__property System::UnicodeString EmptySelectionText = {read=FEmptySelectionText, write=SetEmptySelectionText, stored=IsEmptySelectionTextStored};
	__property TcxCheckComboBoxItems* Items = {read=FItems, write=SetItems};
	__property bool ShowEmptyText = {read=FShowEmptyText, write=SetShowEmptyText, default=1};
	__property TcxCheckComboClickCheckEvent OnClickCheck = {read=FOnClickCheck, write=FOnClickCheck};
	__property Cxcheckbox::TcxValueToCheckStatesEvent OnEditValueToStates = {read=FOnEditValueToStates, write=FOnEditValueToStates};
	__property Cxcheckbox::TcxCheckStatesToValueEvent OnStatesToEditValue = {read=FOnStatesToEditValue, write=FOnStatesToEditValue};
};


class DELPHICLASS TcxCheckComboBoxProperties;
class PASCALIMPLEMENTATION TcxCheckComboBoxProperties : public TcxCustomCheckComboBoxProperties
{
	typedef TcxCustomCheckComboBoxProperties inherited;
	
__published:
	__property AllowGrayed;
	__property AssignedValues;
	__property Delimiter = {default=0};
	__property EmptySelectionText = {default=0};
	__property ShowEmptyText = {default=1};
	__property Alignment;
	__property BeepOnError = {default=0};
	__property ButtonGlyph;
	__property CharCase = {default=0};
	__property ClearKey = {default=0};
	__property DropDownAutoWidth = {default=1};
	__property DropDownRows = {default=8};
	__property DropDownSizeable = {default=0};
	__property DropDownWidth = {default=0};
	__property EditValueFormat = {default=2};
	__property Glyph;
	__property GlyphCount = {default=6};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=1};
	__property ImmediatePost = {default=0};
	__property Items;
	__property PopupAlignment = {default=0};
	__property ReadOnly;
	__property ValidateOnEnter = {default=1};
	__property OnChange;
	__property OnClickCheck;
	__property OnCloseUp;
	__property OnEditValueChanged;
	__property OnEditValueToStates;
	__property OnInitPopup;
	__property OnPopup;
	__property OnStatesToEditValue;
public:
	/* TcxCustomCheckComboBoxProperties.Create */ inline __fastcall virtual TcxCheckComboBoxProperties(System::Classes::TPersistent* AOwner) : TcxCustomCheckComboBoxProperties(AOwner) { }
	/* TcxCustomCheckComboBoxProperties.Destroy */ inline __fastcall virtual ~TcxCheckComboBoxProperties(void) { }
	
};


class DELPHICLASS TcxCheckComboBoxPopupWindow;
class PASCALIMPLEMENTATION TcxCheckComboBoxPopupWindow : public Cxdropdownedit::TcxComboBoxPopupWindow
{
	typedef Cxdropdownedit::TcxComboBoxPopupWindow inherited;
	
public:
	__property ViewInfo;
	__property SysPanelStyle;
public:
	/* TcxCustomEditPopupWindow.Create */ inline __fastcall virtual TcxCheckComboBoxPopupWindow(Vcl::Controls::TWinControl* AOwnerControl) : Cxdropdownedit::TcxComboBoxPopupWindow(AOwnerControl) { }
	/* TcxCustomEditPopupWindow.Destroy */ inline __fastcall virtual ~TcxCheckComboBoxPopupWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCheckComboBoxPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxdropdownedit::TcxComboBoxPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCheckComboBoxPopupWindow(HWND ParentWindow) : Cxdropdownedit::TcxComboBoxPopupWindow(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomCheckComboBox : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	Cxedit::TcxEditBorderStyle FCheckBorderStyle;
	bool FNativeStyle;
	Cxcheckbox::TcxCheckStates FStates;
	bool FStatesItems;
	HIDESBASE TcxCustomCheckComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCheckComboBoxLookupData* __fastcall GetLookupData(void);
	HIDESBASE TcxCustomCheckComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomCheckComboBoxProperties* Value);
	
protected:
	void __fastcall CalculateDrawCheckParams(void);
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall PopupControlsLookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall PopupWindowShowed(System::TObject* Sender);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual void __fastcall SetItemIndex(int Value);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall SynchronizeEditValue(void);
	virtual void __fastcall UpdateDrawValue(void);
	virtual bool __fastcall ClickCheck(int AItemIndex);
	bool __fastcall DoClickCheck(int AItemIndex);
	virtual System::Variant __fastcall GetEditingValue(void);
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializePopupWindow(void);
	virtual System::UnicodeString __fastcall InternalGetText(void);
	virtual bool __fastcall InternalSetText(const System::UnicodeString Value);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	virtual bool __fastcall IsEditValueStored(void);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	__property TcxCheckComboBoxLookupData* LookupData = {read=GetLookupData};
	__property System::Variant Value = {read=GetValue, write=SetValue, stored=false};
	virtual void __fastcall CloseUp(Cxedit::TcxEditCloseUpReason AReason);
	__property bool StatesItems = {read=FStatesItems, write=FStatesItems, stored=false, nodefault};
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetItemState(int AIndex);
	void __fastcall SetItemState(int AIndex, Cxlookandfeelpainters::TcxCheckBoxState AState);
	__property TcxCustomCheckComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomCheckComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Cxlookandfeelpainters::TcxCheckBoxState States[int AIndex] = {read=GetItemState, write=SetItemState};
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxCustomCheckComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomCheckComboBox(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomCheckComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCheckComboBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxCheckComboBox;
class PASCALIMPLEMENTATION TcxCheckComboBox : public TcxCustomCheckComboBox
{
	typedef TcxCustomCheckComboBox inherited;
	
private:
	HIDESBASE TcxCheckComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCheckComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCheckComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxCheckComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxCheckComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property StatesItems;
	__property EditValue = {default=0};
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Value = {default=0};
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxCheckComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCheckComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomCheckComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCheckComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomCheckComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCheckComboBox(HWND ParentWindow) : TcxCustomCheckComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterChecksHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterChecksHelper : public Cxdropdownedit::TcxFilterComboBoxHelper
{
	typedef Cxdropdownedit::TcxFilterComboBoxHelper inherited;
	
protected:
	__classmethod virtual Cxcheckbox::TcxCheckStatesValueFormat __fastcall GetEditValueFormat(Cxedit::TcxCustomEditProperties* AEditProperties);
	__classmethod virtual Cxcheckbox::_di_IcxCheckItems __fastcall GetItems(Cxedit::TcxCustomEditProperties* AEditProperties);
	__classmethod virtual void __fastcall InitializeItems(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
public:
	/* TObject.Create */ inline __fastcall TcxFilterChecksHelper(void) : Cxdropdownedit::TcxFilterComboBoxHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterChecksHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxFilterCheckComboBoxHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterCheckComboBoxHelper : public TcxFilterChecksHelper
{
	typedef TcxFilterChecksHelper inherited;
	
protected:
	__classmethod virtual Cxcheckbox::TcxCheckStatesValueFormat __fastcall GetEditValueFormat(Cxedit::TcxCustomEditProperties* AEditProperties);
	__classmethod virtual Cxcheckbox::_di_IcxCheckItems __fastcall GetItems(Cxedit::TcxCustomEditProperties* AEditProperties);
public:
	/* TObject.Create */ inline __fastcall TcxFilterCheckComboBoxHelper(void) : TcxFilterChecksHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterCheckComboBoxHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::WideChar cxCheckComboValuesDelimiter = (System::WideChar)(0x3b);
}	/* namespace Cxcheckcombobox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCHECKCOMBOBOX)
using namespace Cxcheckcombobox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcheckcomboboxHPP
