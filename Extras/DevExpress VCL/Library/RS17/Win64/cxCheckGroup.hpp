// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCheckGroup.pas' rev: 24.00 (Win64)

#ifndef CxcheckgroupHPP
#define CxcheckgroupHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxCheckComboBox.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcheckgroup
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCheckGroupItem;
class PASCALIMPLEMENTATION TcxCheckGroupItem : public Cxgroupbox::TcxButtonGroupItem
{
	typedef Cxgroupbox::TcxButtonGroupItem inherited;
	
__published:
	__property Caption = {default=0};
	__property Enabled = {default=1};
	__property Tag;
public:
	/* TcxButtonGroupItem.Create */ inline __fastcall virtual TcxCheckGroupItem(System::Classes::TCollection* Collection) : Cxgroupbox::TcxButtonGroupItem(Collection) { }
	/* TcxButtonGroupItem.Destroy */ inline __fastcall virtual ~TcxCheckGroupItem(void) { }
	
};


class DELPHICLASS TcxCheckGroupItems;
class PASCALIMPLEMENTATION TcxCheckGroupItems : public Cxgroupbox::TcxButtonGroupItems
{
	typedef Cxgroupbox::TcxButtonGroupItems inherited;
	
public:
	TcxCheckGroupItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxCheckGroupItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxCheckGroupItem* Value);
	
public:
	HIDESBASE TcxCheckGroupItem* __fastcall Add(void);
	__property TcxCheckGroupItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxOwnedInterfacedCollection.Destroy */ inline __fastcall virtual ~TcxCheckGroupItems(void) { }
	
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxCheckGroupItems(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : Cxgroupbox::TcxButtonGroupItems(AOwner, ItemClass) { }
	
};


class DELPHICLASS TcxCheckGroupButtonViewInfo;
class PASCALIMPLEMENTATION TcxCheckGroupButtonViewInfo : public Cxgroupbox::TcxButtonGroupButtonViewInfo
{
	typedef Cxgroupbox::TcxButtonGroupButtonViewInfo inherited;
	
public:
	Cxlookandfeelpainters::TcxCheckBoxState State;
	virtual System::Types::TRect __fastcall GetGlyphRect(const System::Types::TSize AGlyphSize, System::Classes::TLeftRight AAlignment, bool AIsPaintCopy);
public:
	/* TcxEditButtonViewInfo.Destroy */ inline __fastcall virtual ~TcxCheckGroupButtonViewInfo(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxCheckGroupButtonViewInfo(void) : Cxgroupbox::TcxButtonGroupButtonViewInfo() { }
	
};


class DELPHICLASS TcxCheckGroupViewInfo;
class DELPHICLASS TcxCustomCheckGroup;
class PASCALIMPLEMENTATION TcxCheckGroupViewInfo : public Cxgroupbox::TcxButtonGroupViewInfo
{
	typedef Cxgroupbox::TcxButtonGroupViewInfo inherited;
	
private:
	HIDESBASE TcxCustomCheckGroup* __fastcall GetEdit(void);
	
protected:
	virtual void __fastcall DrawButtonCaption(Cxgraphics::TcxCanvas* ACanvas, Cxgroupbox::TcxGroupBoxButtonViewInfo* AButtonViewInfo, const System::Types::TRect &AGlyphRect);
	virtual void __fastcall DrawButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, Cxgroupbox::TcxGroupBoxButtonViewInfo* AButtonViewInfo, const System::Types::TRect &AGlyphRect);
	virtual Cxedit::TcxEditButtonViewInfoClass __fastcall GetButtonViewInfoClass(void);
	virtual bool __fastcall IsButtonGlypthTransparent(Cxgroupbox::TcxGroupBoxButtonViewInfo* AButtonViewInfo);
	virtual void __fastcall SetOnDrawBackground(Cxedit::TcxEditDrawBackgroundEvent AValue);
	
public:
	Cxedit::TcxEditBorderStyle CheckBorderStyle;
	__property TcxCustomCheckGroup* Edit = {read=GetEdit};
public:
	/* TcxGroupBoxViewInfo.Create */ inline __fastcall virtual TcxCheckGroupViewInfo(void) : Cxgroupbox::TcxButtonGroupViewInfo() { }
	/* TcxGroupBoxViewInfo.Destroy */ inline __fastcall virtual ~TcxCheckGroupViewInfo(void) { }
	
};


class DELPHICLASS TcxCheckGroupViewData;
class PASCALIMPLEMENTATION TcxCheckGroupViewData : public Cxgroupbox::TcxButtonGroupViewData
{
	typedef Cxgroupbox::TcxButtonGroupViewData inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetCaptionRectExtent(void);
	virtual void __fastcall GetEditMetrics(bool AAutoHeight, Cxgraphics::TcxCanvas* ACanvas, /* out */ Cxgroupbox::TcxEditMetrics &AMetrics);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCheckGroupViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxgroupbox::TcxButtonGroupViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCheckGroupViewData(void) { }
	
};


class DELPHICLASS TcxCustomCheckGroupProperties;
class PASCALIMPLEMENTATION TcxCustomCheckGroupProperties : public Cxgroupbox::TcxCustomButtonGroupProperties
{
	typedef Cxgroupbox::TcxCustomButtonGroupProperties inherited;
	
private:
	bool FAllowGrayed;
	Cxcheckbox::TcxCheckStatesValueFormatEx FEditValueFormat;
	Vcl::Graphics::TBitmap* FGlyph;
	int FGlyphCount;
	System::Classes::TAlignment FItemAlignment;
	Cxcheckbox::TcxValueToCheckStatesEvent FOnEditValueToStates;
	Cxcheckbox::TcxCheckStatesToValueEvent FOnStatesToEditValue;
	Vcl::Graphics::TBitmap* __fastcall GetGlyph(void);
	TcxCheckGroupItems* __fastcall GetItems(void);
	void __fastcall GlyphChanged(System::TObject* Sender);
	void __fastcall SetAllowGrayed(bool Value);
	void __fastcall SetEditValueFormat(Cxcheckbox::TcxCheckStatesValueFormat Value);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* Value);
	void __fastcall SetGlyphCount(int Value);
	void __fastcall SetItemAlignment(System::Classes::TLeftRight Value);
	HIDESBASE void __fastcall SetItems(TcxCheckGroupItems* Value);
	void __fastcall CheckEditValueFormat(void);
	Cxcheckbox::TcxCheckStatesValueFormatEx __fastcall GetRealEditValueFormat(void);
	void __fastcall ItemsChanged(System::TObject* Sender, System::Classes::TCollectionItem* AItem);
	
protected:
	virtual Cxgroupbox::TcxButtonGroupItems* __fastcall CreateItems(void);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	virtual void __fastcall CalculateCheckStatesByEditValue(System::TObject* Sender, const System::Variant &AEditValue, Cxcheckbox::TcxCheckStates &ACheckStates);
	virtual void __fastcall CalculateEditValueByCheckStates(System::TObject* Sender, const Cxcheckbox::TcxCheckStates ACheckStates, /* out */ System::Variant &AEditValue);
	
public:
	__fastcall virtual TcxCustomCheckGroupProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomCheckGroupProperties(void);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxedit::TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	__property bool AllowGrayed = {read=FAllowGrayed, write=SetAllowGrayed, default=0};
	__property Cxcheckbox::TcxCheckStatesValueFormat EditValueFormat = {read=FEditValueFormat, write=SetEditValueFormat, default=1};
	__property Vcl::Graphics::TBitmap* Glyph = {read=GetGlyph, write=SetGlyph};
	__property int GlyphCount = {read=FGlyphCount, write=SetGlyphCount, default=6};
	__property System::Classes::TLeftRight ItemAlignment = {read=FItemAlignment, write=SetItemAlignment, default=0};
	__property TcxCheckGroupItems* Items = {read=GetItems, write=SetItems};
	__property Cxcheckbox::TcxValueToCheckStatesEvent OnEditValueToStates = {read=FOnEditValueToStates, write=FOnEditValueToStates};
	__property Cxcheckbox::TcxCheckStatesToValueEvent OnStatesToEditValue = {read=FOnStatesToEditValue, write=FOnStatesToEditValue};
};


class DELPHICLASS TcxCheckGroupProperties;
class PASCALIMPLEMENTATION TcxCheckGroupProperties : public TcxCustomCheckGroupProperties
{
	typedef TcxCustomCheckGroupProperties inherited;
	
__published:
	__property AllowGrayed = {default=0};
	__property AssignedValues;
	__property ClearKey = {default=0};
	__property Columns = {default=1};
	__property EditValueFormat = {default=1};
	__property Glyph;
	__property GlyphCount = {default=6};
	__property ImmediatePost = {default=0};
	__property ItemAlignment = {default=0};
	__property Items;
	__property ReadOnly;
	__property ShowEndEllipsis = {default=0};
	__property WordWrap = {default=0};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnEditValueToStates;
	__property OnStatesToEditValue;
public:
	/* TcxCustomCheckGroupProperties.Create */ inline __fastcall virtual TcxCheckGroupProperties(System::Classes::TPersistent* AOwner) : TcxCustomCheckGroupProperties(AOwner) { }
	/* TcxCustomCheckGroupProperties.Destroy */ inline __fastcall virtual ~TcxCheckGroupProperties(void) { }
	
};


class DELPHICLASS TcxCheckGroupCheckButtonViewInfo;
class PASCALIMPLEMENTATION TcxCheckGroupCheckButtonViewInfo : public Cxcheckbox::TcxCustomCheckBoxViewInfo
{
	typedef Cxcheckbox::TcxCustomCheckBoxViewInfo inherited;
	
protected:
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TcxCustomCheckBoxViewInfo.Create */ inline __fastcall virtual TcxCheckGroupCheckButtonViewInfo(void) : Cxcheckbox::TcxCustomCheckBoxViewInfo() { }
	/* TcxCustomCheckBoxViewInfo.Destroy */ inline __fastcall virtual ~TcxCheckGroupCheckButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxCheckGroupButtonProperties;
class PASCALIMPLEMENTATION TcxCheckGroupButtonProperties : public Cxcheckbox::TcxCheckBoxProperties
{
	typedef Cxcheckbox::TcxCheckBoxProperties inherited;
	
protected:
	virtual Vcl::Graphics::TBitmap* __fastcall InternalGetGlyph(void);
	virtual bool __fastcall IsEmbeddedEdit(void);
	
public:
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
public:
	/* TcxCustomCheckBoxProperties.Create */ inline __fastcall virtual TcxCheckGroupButtonProperties(System::Classes::TPersistent* AOwner) : Cxcheckbox::TcxCheckBoxProperties(AOwner) { }
	/* TcxCustomCheckBoxProperties.Destroy */ inline __fastcall virtual ~TcxCheckGroupButtonProperties(void) { }
	
};


class DELPHICLASS TcxCheckGroupButton;
class PASCALIMPLEMENTATION TcxCheckGroupButton : public Cxcheckbox::TcxCustomCheckBox
{
	typedef Cxcheckbox::TcxCustomCheckBox inherited;
	
private:
	int FColumn;
	int FRow;
	TcxCustomCheckGroup* __fastcall GetCheckGroup(void);
	
protected:
	virtual bool __fastcall CanAutoSize(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall Initialize(void);
	virtual bool __fastcall IsNativeBackground(void);
	virtual bool __fastcall IsNativeStyle(void);
	virtual bool __fastcall IsTransparent(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	void __fastcall CheckTransparentBorder(void);
	__property TcxCustomCheckGroup* CheckGroup = {read=GetCheckGroup};
	
public:
	__fastcall virtual ~TcxCheckGroupButton(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCheckGroupButton(System::Classes::TComponent* AOwner)/* overload */ : Cxcheckbox::TcxCustomCheckBox(AOwner) { }
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCheckGroupButton(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxcheckbox::TcxCustomCheckBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCheckGroupButton(HWND ParentWindow) : Cxcheckbox::TcxCustomCheckBox(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
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
	
};


class PASCALIMPLEMENTATION TcxCustomCheckGroup : public Cxgroupbox::TcxCustomButtonGroup
{
	typedef Cxgroupbox::TcxCustomButtonGroup inherited;
	
public:
	Cxlookandfeelpainters::TcxCheckBoxState operator[](int Index) { return States[Index]; }
	
private:
	bool FButtonStatesChanging;
	int FFocusedItemIndex;
	bool FStatesItems;
	void __fastcall DoButtonChange(System::TObject* Sender);
	void __fastcall DoButtonEditing(System::TObject* Sender, bool &CanEdit);
	void __fastcall DoButtonFocusChanged(System::TObject* Sender);
	HIDESBASE TcxCustomCheckGroupProperties* __fastcall GetActiveProperties(void);
	TcxCheckGroupButton* __fastcall GetButton(int Index);
	HIDESBASE TcxCustomCheckGroupProperties* __fastcall GetProperties(void);
	Cxlookandfeelpainters::TcxCheckBoxState __fastcall GetState(int Index);
	HIDESBASE void __fastcall SetProperties(TcxCustomCheckGroupProperties* Value);
	void __fastcall SetState(int Index, Cxlookandfeelpainters::TcxCheckBoxState Value);
	
protected:
	virtual void __fastcall ArrangeButtons(void);
	virtual void __fastcall DoSetFocusWhenActivate(void);
	virtual NativeUInt __fastcall GetButtonDC(int AButtonIndex);
	virtual Vcl::Controls::TWinControl* __fastcall GetButtonInstance(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	virtual bool __fastcall IsEditValueStored(void);
	virtual void __fastcall ParentBackgroundChanged(void);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall SynchronizeButtonsStyle(void);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall SynchronizeModifiedAfterEnter(void);
	virtual void __fastcall UpdateButtons(void);
	virtual bool __fastcall WantNavigationKeys(void);
	int __fastcall GetFirstEnabledItemIndex(int AStartIndex);
	__property TcxCheckGroupButton* Buttons[int Index] = {read=GetButton};
	__property InternalButtons;
	__property bool StatesItems = {read=FStatesItems, write=FStatesItems, stored=false, nodefault};
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual void __fastcall SetFocus(void);
	__property TcxCustomCheckGroupProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomCheckGroupProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Cxlookandfeelpainters::TcxCheckBoxState States[int Index] = {read=GetState, write=SetState/*, default*/};
	__property Transparent = {default=0};
public:
	/* TcxCustomButtonGroup.Destroy */ inline __fastcall virtual ~TcxCustomCheckGroup(void) { }
	
public:
	/* TcxCustomGroupBox.Create */ inline __fastcall virtual TcxCustomCheckGroup(System::Classes::TComponent* AOwner)/* overload */ : Cxgroupbox::TcxCustomButtonGroup(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomCheckGroup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxgroupbox::TcxCustomButtonGroup(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCheckGroup(HWND ParentWindow) : Cxgroupbox::TcxCustomButtonGroup(ParentWindow) { }
	
};


class DELPHICLASS TcxCheckGroup;
class PASCALIMPLEMENTATION TcxCheckGroup : public TcxCustomCheckGroup
{
	typedef TcxCustomCheckGroup inherited;
	
private:
	HIDESBASE TcxCheckGroupProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCheckGroupProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCheckGroupProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxCheckGroupProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property Caption = {default=0};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property EditValue = {default=0};
	__property Enabled = {default=1};
	__property ParentBackground = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxCheckGroupProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property StatesItems;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Transparent = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnFocusChanged;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomButtonGroup.Destroy */ inline __fastcall virtual ~TcxCheckGroup(void) { }
	
public:
	/* TcxCustomGroupBox.Create */ inline __fastcall virtual TcxCheckGroup(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomCheckGroup(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCheckGroup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomCheckGroup(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCheckGroup(HWND ParentWindow) : TcxCustomCheckGroup(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterCheckGroupHelper;
class PASCALIMPLEMENTATION TcxFilterCheckGroupHelper : public Cxcheckcombobox::TcxFilterChecksHelper
{
	typedef Cxcheckcombobox::TcxFilterChecksHelper inherited;
	
protected:
	__classmethod virtual Cxcheckbox::TcxCheckStatesValueFormat __fastcall GetEditValueFormat(Cxedit::TcxCustomEditProperties* AEditProperties);
	__classmethod virtual Cxcheckbox::_di_IcxCheckItems __fastcall GetItems(Cxedit::TcxCustomEditProperties* AEditProperties);
	__classmethod virtual void __fastcall InitializeItems(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties);
public:
	/* TObject.Create */ inline __fastcall TcxFilterCheckGroupHelper(void) : Cxcheckcombobox::TcxFilterChecksHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterCheckGroupHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxcheckgroup */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCHECKGROUP)
using namespace Cxcheckgroup;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcheckgroupHPP
