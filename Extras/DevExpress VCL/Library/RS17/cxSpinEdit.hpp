// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSpinEdit.pas' rev: 24.00 (Win32)

#ifndef CxspineditHPP
#define CxspineditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxspinedit
{
//-- type declarations -------------------------------------------------------
enum TcxSpinBoundsCheckingKind : unsigned char { bckDoNotExceed, bckExtendToBound, bckCircular };

enum TcxSpinEditButtonsPosition : unsigned char { sbpHorzLeftRight, sbpHorzRight, sbpVert };

enum TcxSpinEditButton : unsigned char { sebBackward, sebForward, sebFastBackward, sebFastForward };

class DELPHICLASS TcxSpinEditViewInfo;
class PASCALIMPLEMENTATION TcxSpinEditViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
protected:
	virtual void __fastcall DrawHotFlatButtonBorder(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawNativeButtonBorder(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo, System::Types::TRect &ARect, /* out */ System::Types::TRect &AContentRect, System::Uitypes::TColor &APenColor, System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawUltraFlatButtonBorder(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo, bool AIsOffice11Style, System::Types::TRect &ARect, System::Types::TRect &AContentRect, /* out */ System::Uitypes::TColor &APenColor, /* out */ System::Uitypes::TColor &ABrushColor);
	virtual void __fastcall DrawNativeButtonBackground(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo, const System::Types::TRect &ARect);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	int ArrowSize;
	TcxSpinEditButtonsPosition ButtonsPosition;
	System::StaticArray<System::Types::TPoint, 2> DelimiterLine;
	virtual void __fastcall DrawButtonContent(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AViewInfo, const System::Types::TRect &AContentRect, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, bool ANeedOffsetContent);
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxSpinEditViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxSpinEditViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


enum TcxSpinEditPressedState : unsigned char { epsNone, epsDown, epsUp, epsFastDown, epsFastUp };

class DELPHICLASS TcxSpinEditViewData;
class DELPHICLASS TcxCustomSpinEditProperties;
class PASCALIMPLEMENTATION TcxSpinEditViewData : public Cxtextedit::TcxCustomTextEditViewData
{
	typedef Cxtextedit::TcxCustomTextEditViewData inherited;
	
private:
	HIDESBASE TcxCustomSpinEditProperties* __fastcall GetProperties(void);
	
protected:
	virtual bool __fastcall CanPressButton(Cxedit::TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	virtual void __fastcall CalculateButtonNativePartInfo(NativeUInt ATheme, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo);
	virtual NativeUInt __fastcall GetButtonNativeTheme(Cxedit::TcxEditButtonViewInfo* AButtonViewInfo);
	virtual bool __fastcall IsButtonPressed(Cxedit::TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex);
	
public:
	TcxSpinEditPressedState PressedState;
	virtual void __fastcall CalculateButtonBounds(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex, System::Types::TRect &ButtonsRect);
	virtual void __fastcall CalculateButtonViewInfo(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo, int AButtonVisibleIndex, System::Types::TRect &ButtonsRect);
	virtual void __fastcall CheckButtonsOnly(Cxedit::TcxCustomEditViewInfo* AViewInfo, int APrevButtonsWidth, int AButtonsWidth);
	virtual bool __fastcall IgnoreButtonWhileStretching(int AButtonVisibleIndex);
	__property TcxCustomSpinEditProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxSpinEditViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxtextedit::TcxCustomTextEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSpinEditViewData(void) { }
	
};


class DELPHICLASS TcxSpinEditButtons;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSpinEditButtons : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	TcxSpinEditButtonsPosition FPosition;
	bool FShowFastButtons;
	bool FVisible;
	TcxCustomSpinEditProperties* __fastcall GetProperties(void);
	void __fastcall SetPosition(TcxSpinEditButtonsPosition Value);
	void __fastcall SetShowFastButtons(bool Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	void __fastcall Changed(void);
	__property TcxCustomSpinEditProperties* Properties = {read=GetProperties};
	
public:
	__fastcall virtual TcxSpinEditButtons(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxSpinEditButtonsPosition Position = {read=FPosition, write=SetPosition, default=2};
	__property bool ShowFastButtons = {read=FShowFastButtons, write=SetShowFastButtons, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSpinEditButtons(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSpinEditPropertiesValues;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSpinEditPropertiesValues : public Cxtextedit::TcxTextEditPropertiesValues
{
	typedef Cxtextedit::TcxTextEditPropertiesValues inherited;
	
private:
	bool FValueType;
	void __fastcall SetValueType(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool ValueType = {read=FValueType, write=SetValueType, stored=false, nodefault};
public:
	/* TcxCustomEditPropertiesValues.Create */ inline __fastcall virtual TcxSpinEditPropertiesValues(System::Classes::TPersistent* AOwner) : Cxtextedit::TcxTextEditPropertiesValues(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSpinEditPropertiesValues(void) { }
	
};

#pragma pack(pop)

enum TcxSpinEditValueType : unsigned char { vtInt, vtFloat };

typedef void __fastcall (__closure *TcxSpinEditGetValueEvent)(System::TObject* Sender, const Vcl::Controls::TCaption AText, /* out */ System::Variant &AValue, Vcl::Controls::TCaption &ErrorText, bool &Error);

class PASCALIMPLEMENTATION TcxCustomSpinEditProperties : public Cxmaskedit::TcxCustomMaskEditProperties
{
	typedef Cxmaskedit::TcxCustomMaskEditProperties inherited;
	
private:
	TcxSpinEditButtons* FSpinButtons;
	bool FCanEdit;
	bool FCircular;
	double FIncrement;
	double FLargeIncrement;
	bool FExceptionOnInvalidInput;
	bool FUseCtrlIncrement;
	TcxSpinEditValueType FValueType;
	TcxSpinEditGetValueEvent FOnGetValue;
	double __fastcall DoubleAsValueType(double AValue, TcxSpinEditValueType AValueType);
	HIDESBASE TcxSpinEditPropertiesValues* __fastcall GetAssignedValues(void);
	TcxSpinEditValueType __fastcall GetValueType(void);
	bool __fastcall IsIncrementStored(void);
	bool __fastcall IsLargeIncrementStored(void);
	bool __fastcall IsValueTypeStored(void);
	void __fastcall ReadZeroIncrement(System::Classes::TReader* Reader);
	void __fastcall ReadZeroLargeIncrement(System::Classes::TReader* Reader);
	HIDESBASE void __fastcall SetAssignedValues(TcxSpinEditPropertiesValues* Value);
	void __fastcall SetCircular(bool Value);
	void __fastcall SetSpinButtons(TcxSpinEditButtons* Value);
	void __fastcall SetValueType(TcxSpinEditValueType Value);
	bool __fastcall TryTextToValue(System::UnicodeString S, /* out */ System::Variant &AValue);
	System::Variant __fastcall VarToCurrentValueType(const System::Variant &AValue);
	void __fastcall WriteZeroIncrement(System::Classes::TWriter* Writer);
	void __fastcall WriteZeroLargeIncrement(System::Classes::TWriter* Writer);
	
protected:
	virtual System::Variant __fastcall DefaultFocusedDisplayValue(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall DoChanged(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall IsEditValueNumeric(void);
	System::Variant __fastcall CheckValueBounds(const System::Variant &Value);
	virtual bool __fastcall ExtendValueUpToBound(void);
	virtual TcxSpinBoundsCheckingKind __fastcall GetBoundsCheckingKind(void);
	double __fastcall GetIncrement(TcxSpinEditButton AButton);
	System::Variant __fastcall GetMaxMinValueForCurrentValueType(bool AMinValue = true);
	virtual System::Variant __fastcall InternalMaxValue(void);
	virtual System::Variant __fastcall InternalMinValue(void);
	virtual bool __fastcall IsDisplayValueNumeric(void);
	bool __fastcall IsValueBoundsValid(System::Extended AValue);
	virtual System::Variant __fastcall PrepareValue(const System::Variant &AValue, bool AEditFocused);
	virtual bool __fastcall PreserveSelection(void);
	System::Variant __fastcall SetVariantType(const System::Variant &Value);
	__property TcxSpinEditPropertiesValues* AssignedValues = {read=GetAssignedValues, write=SetAssignedValues};
	
public:
	__fastcall virtual TcxCustomSpinEditProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomSpinEditProperties(void);
	virtual Cxedit::TcxCustomEditViewData* __fastcall CreateViewData(Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace, bool APreviewMode = false);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsDisplayValueValid(System::Variant &DisplayValue, bool AEditFocused);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	__property bool CanEdit = {read=FCanEdit, write=FCanEdit, default=1};
	__property bool Circular = {read=FCircular, write=SetCircular, default=0};
	__property bool ExceptionOnInvalidInput = {read=FExceptionOnInvalidInput, write=FExceptionOnInvalidInput, default=0};
	__property double Increment = {read=FIncrement, write=FIncrement, stored=IsIncrementStored};
	__property double LargeIncrement = {read=FLargeIncrement, write=FLargeIncrement, stored=IsLargeIncrementStored};
	__property TcxSpinEditButtons* SpinButtons = {read=FSpinButtons, write=SetSpinButtons};
	__property bool UseCtrlIncrement = {read=FUseCtrlIncrement, write=FUseCtrlIncrement, default=0};
	__property TcxSpinEditValueType ValueType = {read=GetValueType, write=SetValueType, stored=IsValueTypeStored, nodefault};
	__property TcxSpinEditGetValueEvent OnGetValue = {read=FOnGetValue, write=FOnGetValue};
};


class DELPHICLASS TcxSpinEditProperties;
class PASCALIMPLEMENTATION TcxSpinEditProperties : public TcxCustomSpinEditProperties
{
	typedef TcxCustomSpinEditProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property BeepOnError = {default=0};
	__property CanEdit = {default=1};
	__property ClearKey = {default=0};
	__property DisplayFormat = {default=0};
	__property EchoMode = {default=0};
	__property EditFormat = {default=0};
	__property ExceptionOnInvalidInput = {default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediatePost = {default=0};
	__property Increment = {default=0};
	__property LargeIncrement = {default=0};
	__property MaxValue = {default=0};
	__property MinValue = {default=0};
	__property Nullstring = {default=0};
	__property PasswordChar = {default=0};
	__property ReadOnly;
	__property SpinButtons;
	__property UseCtrlIncrement = {default=0};
	__property UseDisplayFormatWhenEditing = {default=0};
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property ValueType;
	__property OnChange;
	__property OnEditValueChanged;
	__property OnGetValue;
	__property OnValidate;
public:
	/* TcxCustomSpinEditProperties.Create */ inline __fastcall virtual TcxSpinEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomSpinEditProperties(AOwner) { }
	/* TcxCustomSpinEditProperties.Destroy */ inline __fastcall virtual ~TcxSpinEditProperties(void) { }
	
};


class DELPHICLASS TcxCustomSpinEdit;
class PASCALIMPLEMENTATION TcxCustomSpinEdit : public Cxmaskedit::TcxCustomMaskEdit
{
	typedef Cxmaskedit::TcxCustomMaskEdit inherited;
	
private:
	System::Variant FInternalValue;
	bool FIsCustomText;
	bool FIsCustomTextAction;
	TcxSpinEditPressedState FPressedState;
	Cxclasses::TcxTimer* FTimer;
	HIDESBASE TcxCustomSpinEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomSpinEditProperties* __fastcall GetActiveProperties(void);
	void __fastcall HandleTimer(System::TObject* Sender);
	bool __fastcall IsValueStored(void);
	void __fastcall SetInternalValue(const System::Variant &AValue);
	void __fastcall SetPressedState(TcxSpinEditPressedState Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomSpinEditProperties* Value);
	void __fastcall StopTracking(void);
	
protected:
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	virtual void __fastcall CheckEditorValueBounds(void);
	virtual void __fastcall DoButtonDown(int AButtonVisibleIndex);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyPress(System::WideChar &Key);
	virtual void __fastcall DoEditKeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC bool __fastcall DoMouseWheelDown(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	DYNAMIC bool __fastcall DoMouseWheelUp(System::Classes::TShiftState Shift, const System::Types::TPoint &MousePos);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual void __fastcall Initialize(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	virtual Cxcontainer::TcxContainerStyleValues __fastcall InternalGetNotPublishedStyleValues(void);
	virtual void __fastcall InternalStoreEditValue(const System::Variant &Value);
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual void __fastcall SynchronizeDisplayValue(void);
	void __fastcall DoOnGetValue(const Vcl::Controls::TCaption AText, /* out */ System::Variant &AValue, Vcl::Controls::TCaption &ErrorText, bool &Error);
	virtual double __fastcall GetIncrement(TcxSpinEditButton AButton);
	virtual System::Variant __fastcall GetValue(void);
	virtual System::UnicodeString __fastcall IncrementValueToStr(const System::Variant &AValue);
	bool __fastcall InternalPrepareEditValue(const System::Variant &ADisplayValue, bool ARaiseException, /* out */ System::Variant &EditValue, /* out */ Vcl::Controls::TCaption &AErrorText);
	bool __fastcall IsOnGetValueEventAssigned(void);
	virtual void __fastcall SetValue(const System::Variant &Value);
	__property TcxSpinEditPressedState PressedState = {read=FPressedState, write=SetPressedState, nodefault};
	__property System::Variant Value = {read=GetValue, write=SetValue, stored=IsValueStored};
	
public:
	__fastcall virtual ~TcxCustomSpinEdit(void);
	virtual void __fastcall ClearSelection(void);
	virtual void __fastcall CutToClipboard(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual bool __fastcall Increment(TcxSpinEditButton AButton);
	virtual void __fastcall PasteFromClipboard(void);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomSpinEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomSpinEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomSpinEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxmaskedit::TcxCustomMaskEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomSpinEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxmaskedit::TcxCustomMaskEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomSpinEdit(HWND ParentWindow) : Cxmaskedit::TcxCustomMaskEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxSpinEdit;
class PASCALIMPLEMENTATION TcxSpinEdit : public TcxCustomSpinEdit
{
	typedef TcxCustomSpinEdit inherited;
	
private:
	HIDESBASE TcxSpinEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxSpinEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxSpinEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxSpinEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxSpinEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Value = {default=0};
	__property Visible = {default=1};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
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
	__property OnStartDrag;
	__property OnEndDock;
	__property OnStartDock;
public:
	/* TcxCustomSpinEdit.Destroy */ inline __fastcall virtual ~TcxSpinEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxSpinEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomSpinEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxSpinEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomSpinEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSpinEdit(HWND ParentWindow) : TcxCustomSpinEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterSpinEditHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterSpinEditHelper : public Cxmaskedit::TcxFilterMaskEditHelper
{
	typedef Cxmaskedit::TcxFilterMaskEditHelper inherited;
	
public:
	__classmethod virtual bool __fastcall EditPropertiesHasButtons();
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
public:
	/* TObject.Create */ inline __fastcall TcxFilterSpinEditHelper(void) : Cxmaskedit::TcxFilterMaskEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterSpinEditHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxSpinBackwardButtonIndex = System::Int8(0x0);
static const System::Int8 cxSpinForwardButtonIndex = System::Int8(0x1);
static const System::Int8 cxSpinFastBackwardButtonIndex = System::Int8(0x2);
static const System::Int8 cxSpinFastForwardButtonIndex = System::Int8(0x3);
}	/* namespace Cxspinedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSPINEDIT)
using namespace Cxspinedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxspineditHPP
