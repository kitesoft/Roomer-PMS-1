// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCalc.pas' rev: 24.00 (Win64)

#ifndef CxcalcHPP
#define CxcalcHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxFormats.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcalc
{
//-- type declarations -------------------------------------------------------
enum TcxCalcState : unsigned char { csFirst, csValid, csError };

typedef System::StaticArray<System::UnicodeString, 27> Cxcalc__1;

class DELPHICLASS TcxCalcEditButtonViewInfo;
class DELPHICLASS TcxCustomCalculator;
class DELPHICLASS TcxCalcEditButtonFadingHelper;
class PASCALIMPLEMENTATION TcxCalcEditButtonViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FDown;
	TcxCustomCalculator* FOwner;
	Cxlookandfeelpainters::TcxButtonState FState;
	bool FGrayed;
	bool __fastcall GetIsDefault(void);
	void __fastcall SetDown(bool AValue);
	void __fastcall SetState(const Cxlookandfeelpainters::TcxButtonState Value);
	void __fastcall SetGrayed(const bool Value);
	
protected:
	System::Types::TRect Bounds;
	TcxCalcEditButtonFadingHelper* FadingHelper;
	Cxlookandfeelpainters::TcxCalcButtonKind Kind;
	System::UnicodeString Text;
	Cxlookandfeelpainters::TcxButtonState __fastcall CalculateState(void);
	
public:
	__fastcall TcxCalcEditButtonViewInfo(TcxCustomCalculator* AOwner);
	__fastcall virtual ~TcxCalcEditButtonViewInfo(void);
	void __fastcall Invalidate(void);
	void __fastcall UpdateState(void);
	__property bool Down = {read=FDown, write=SetDown, nodefault};
	__property bool Grayed = {read=FGrayed, write=SetGrayed, nodefault};
	__property bool IsDefault = {read=GetIsDefault, nodefault};
	__property TcxCustomCalculator* Owner = {read=FOwner};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
};


class PASCALIMPLEMENTATION TcxCalcEditButtonFadingHelper : public Dxfading::TdxFadingObjectHelper
{
	typedef Dxfading::TdxFadingObjectHelper inherited;
	
private:
	TcxCalcEditButtonViewInfo* FViewInfo;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	virtual bool __fastcall CanFade(void);
	virtual void __fastcall DrawFadeImage(void);
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	
public:
	__fastcall virtual TcxCalcEditButtonFadingHelper(TcxCalcEditButtonViewInfo* AViewInfo);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property TcxCalcEditButtonViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxCalcEditButtonFadingHelper(void) { }
	
};


typedef System::StaticArray<TcxCalcEditButtonViewInfo*, 28> TcxCalcEditButtonsViewInfo;

typedef void __fastcall (__closure *TcxCalcButtonClick)(System::TObject* Sender, Cxlookandfeelpainters::TcxCalcButtonKind &ButtonKind);

typedef void __fastcall (__closure *TcxCalcGetEditValue)(System::TObject* Sender, System::UnicodeString &Value);

typedef void __fastcall (__closure *TcxCalcSetEditValue)(System::TObject* Sender, const System::UnicodeString Value);

class PASCALIMPLEMENTATION TcxCustomCalculator : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	bool FAutoFontSize;
	bool FBeepOnError;
	Vcl::Forms::TFormBorderStyle FBorderStyle;
	bool FFocusRectVisible;
	int FCalcFontSize;
	int FCalcBtnWidth;
	int FCalcBtnHeight;
	int FCalcLargeBtnWidth;
	int FCalcXOfs;
	int FCalcYOfs;
	int FCalcWidth;
	int FCalcHeight;
	System::Extended FMemory;
	Cxlookandfeelpainters::TcxCalcButtonKind FOperator;
	System::Extended FOperand;
	System::Byte FPrecision;
	TcxCalcState FStatus;
	Cxlookandfeelpainters::TcxCalcButtonKind FActiveButton;
	TcxCalcEditButtonsViewInfo FButtons;
	Cxlookandfeelpainters::TcxCalcButtonKind FDownButton;
	Cxlookandfeelpainters::TcxCalcButtonKind FPressedButton;
	bool FTracking;
	System::Classes::TNotifyEvent FOnDisplayChange;
	TcxCalcButtonClick FOnButtonClick;
	System::Classes::TNotifyEvent FOnResult;
	Cxedit::TcxEditClosePopupEvent FOnHidePopup;
	System::Extended __fastcall GetDisplay(void);
	System::Extended __fastcall GetMemory(void);
	void __fastcall SetDisplay(System::Extended Value);
	void __fastcall SetActiveButton(Cxlookandfeelpainters::TcxCalcButtonKind AValue);
	void __fastcall SetAutoFontSize(bool Value);
	HIDESBASE void __fastcall SetBorderStyle(Vcl::Forms::TBorderStyle Value);
	void __fastcall SetFocusRectVisible(bool Value);
	void __fastcall StopTracking(void);
	void __fastcall TrackButton(int X, int Y);
	void __fastcall DoButtonDown(Cxlookandfeelpainters::TcxCalcButtonKind ButtonKind);
	void __fastcall DoButtonUp(Cxlookandfeelpainters::TcxCalcButtonKind ButtonKind);
	void __fastcall Error(void);
	void __fastcall CheckFirst(void);
	void __fastcall Clear(void);
	void __fastcall CalcSize(int AWidth, int AHeight);
	void __fastcall UpdateMemoryButtons(void);
	void __fastcall InvalidateMemoryButtons(void);
	void __fastcall ResetOperands(void);
	
protected:
	bool IsPopupControl;
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall FocusChanged(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall SetEnabled(bool Value);
	void __fastcall CreateLayout(void);
	void __fastcall ButtonClick(Cxlookandfeelpainters::TcxCalcButtonKind ButtonKind);
	void __fastcall UpdateButtonsState(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, TcxCalcEditButtonViewInfo* AButtonInfo);
	virtual void __fastcall DrawButtons(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::UnicodeString __fastcall GetEditorValue(void);
	virtual void __fastcall SetEditorValue(const System::UnicodeString Value);
	virtual void __fastcall HidePopup(Cxcontrols::TcxControl* Sender, Cxedit::TcxEditCloseUpReason AReason);
	virtual void __fastcall LockChanges(bool ALock, bool AInvokeChangedOnUnlock = true);
	__property Color = {default=-16777201};
	__property ParentColor = {default=0};
	__property Vcl::Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=0};
	__property Cxlookandfeelpainters::TcxCalcButtonKind ActiveButton = {read=FActiveButton, write=SetActiveButton, nodefault};
	__property bool AutoFontSize = {read=FAutoFontSize, write=SetAutoFontSize, default=1};
	__property bool BeepOnError = {read=FBeepOnError, write=FBeepOnError, default=1};
	__property bool ShowFocusRect = {read=FFocusRectVisible, write=SetFocusRectVisible, default=1};
	__property System::Byte Precision = {read=FPrecision, write=FPrecision, default=15};
	__property System::UnicodeString EditorValue = {read=GetEditorValue, write=SetEditorValue};
	__property Cxedit::TcxEditClosePopupEvent OnHidePopup = {read=FOnHidePopup, write=FOnHidePopup};
	__property System::Classes::TNotifyEvent OnDisplayChange = {read=FOnDisplayChange, write=FOnDisplayChange};
	__property TcxCalcButtonClick OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property System::Classes::TNotifyEvent OnResult = {read=FOnResult, write=FOnResult};
	
public:
	__fastcall virtual TcxCustomCalculator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomCalculator(void);
	Cxlookandfeelpainters::TcxCalcButtonKind __fastcall GetButtonKindAt(int X, int Y);
	Cxlookandfeelpainters::TcxCalcButtonKind __fastcall GetButtonKindChar(System::WideChar Ch);
	Cxlookandfeelpainters::TcxCalcButtonKind __fastcall GetButtonKindKey(System::Word Key, System::Classes::TShiftState Shift);
	void __fastcall CopyToClipboard(void);
	void __fastcall PasteFromClipboard(void);
	__property System::Extended Memory = {read=GetMemory};
	__property System::Extended Value = {read=GetDisplay, write=SetDisplay};
	
__published:
	__property TabStop = {default=1};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCalculator(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TcxPopupCalculator;
class DELPHICLASS TcxCustomCalcEdit;
class PASCALIMPLEMENTATION TcxPopupCalculator : public TcxCustomCalculator
{
	typedef TcxCustomCalculator inherited;
	
private:
	TcxCustomCalcEdit* FEdit;
	
protected:
	virtual System::UnicodeString __fastcall GetEditorValue(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall SetEditorValue(const System::UnicodeString Value);
	virtual void __fastcall LockChanges(bool ALock, bool AInvokeChangedOnUnlock = true);
	__property TcxCustomCalcEdit* Edit = {read=FEdit, write=FEdit};
	
public:
	__fastcall virtual TcxPopupCalculator(System::Classes::TComponent* AOwner);
	virtual void __fastcall Init(void);
public:
	/* TcxCustomCalculator.Destroy */ inline __fastcall virtual ~TcxPopupCalculator(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPopupCalculator(HWND ParentWindow) : TcxCustomCalculator(ParentWindow) { }
	
};


class DELPHICLASS TcxCalcEditPropertiesValues;
class PASCALIMPLEMENTATION TcxCalcEditPropertiesValues : public Cxtextedit::TcxTextEditPropertiesValues
{
	typedef Cxtextedit::TcxTextEditPropertiesValues inherited;
	
private:
	bool FPrecision;
	void __fastcall SetPrecision(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool Precision = {read=FPrecision, write=SetPrecision, stored=false, nodefault};
public:
	/* TcxCustomEditPropertiesValues.Create */ inline __fastcall virtual TcxCalcEditPropertiesValues(System::Classes::TPersistent* AOwner) : Cxtextedit::TcxTextEditPropertiesValues(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCalcEditPropertiesValues(void) { }
	
};


class DELPHICLASS TcxCustomCalcEditProperties;
class PASCALIMPLEMENTATION TcxCustomCalcEditProperties : public Cxdropdownedit::TcxCustomPopupEditProperties
{
	typedef Cxdropdownedit::TcxCustomPopupEditProperties inherited;
	
private:
	bool FBeepOnError;
	System::Byte FPrecision;
	bool FQuickClose;
	bool FScientificFormat;
	bool FUseThousandSeparator;
	HIDESBASE TcxCalcEditPropertiesValues* __fastcall GetAssignedValues(void);
	System::Byte __fastcall GetPrecision(void);
	bool __fastcall IsPrecisionStored(void);
	HIDESBASE void __fastcall SetAssignedValues(TcxCalcEditPropertiesValues* Value);
	void __fastcall SetBeepOnError(bool Value);
	void __fastcall SetPrecision(System::Byte Value);
	void __fastcall SetQuickClose(bool Value);
	void __fastcall SetScientificFormat(bool Value);
	void __fastcall SetUseThousandSeparator(bool Value);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual bool __fastcall GetAlwaysPostEditValue(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	virtual bool __fastcall HasDigitGrouping(bool AIsDisplayValueSynchronizing);
	virtual bool __fastcall PopupWindowAcceptsAnySize(void);
	__property TcxCalcEditPropertiesValues* AssignedValues = {read=GetAssignedValues, write=SetAssignedValues};
	
public:
	__fastcall virtual TcxCustomCalcEditProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual bool __fastcall IsDisplayValueValid(System::Variant &DisplayValue, bool AEditFocused);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall DoPrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &Error, Cxedit::TcxCustomEdit* AEdit);
	__property bool BeepOnError = {read=FBeepOnError, write=SetBeepOnError, default=1};
	__property ImmediateDropDownWhenKeyPressed = {default=0};
	__property System::Byte Precision = {read=GetPrecision, write=SetPrecision, stored=IsPrecisionStored, nodefault};
	__property bool QuickClose = {read=FQuickClose, write=SetQuickClose, default=0};
	__property bool ScientificFormat = {read=FScientificFormat, write=SetScientificFormat, default=0};
	__property bool UseThousandSeparator = {read=FUseThousandSeparator, write=SetUseThousandSeparator, default=0};
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomCalcEditProperties(void) { }
	
};


class DELPHICLASS TcxCalcEditProperties;
class PASCALIMPLEMENTATION TcxCalcEditProperties : public TcxCustomCalcEditProperties
{
	typedef TcxCustomCalcEditProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property BeepOnError = {default=1};
	__property ButtonGlyph;
	__property ClearKey = {default=0};
	__property DisplayFormat = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=0};
	__property ImmediatePost = {default=0};
	__property Nullstring = {default=0};
	__property Precision;
	__property ReadOnly;
	__property QuickClose = {default=0};
	__property ScientificFormat = {default=0};
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property UseThousandSeparator = {default=0};
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnCloseUp;
	__property OnEditValueChanged;
	__property OnInitPopup;
	__property OnPopup;
	__property OnValidate;
public:
	/* TcxCustomCalcEditProperties.Create */ inline __fastcall virtual TcxCalcEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomCalcEditProperties(AOwner) { }
	
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TcxCalcEditProperties(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomCalcEdit : public Cxdropdownedit::TcxCustomPopupEdit
{
	typedef Cxdropdownedit::TcxCustomPopupEdit inherited;
	
private:
	TcxPopupCalculator* FCalculator;
	HIDESBASE TcxCustomCalcEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomCalcEditProperties* __fastcall GetActiveProperties(void);
	double __fastcall GetValue(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomCalcEditProperties* Value);
	void __fastcall SetValue(const double Value);
	
protected:
	virtual void __fastcall FormatChanged(void);
	virtual bool __fastcall CanDropDown(void);
	virtual void __fastcall CreatePopupWindow(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall DoInitPopup(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializePopupWindow(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	virtual bool __fastcall IsValidChar(System::WideChar Key);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall PopupWindowClosed(System::TObject* Sender);
	DYNAMIC void __fastcall PopupWindowShowed(System::TObject* Sender);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	bool __fastcall InternalPrepareEditValue(const System::UnicodeString ADisplayValue, /* out */ System::Variant &EditValue);
	__property TcxPopupCalculator* Calculator = {read=FCalculator};
	
public:
	__fastcall virtual ~TcxCustomCalcEdit(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PasteFromClipboard(void);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomCalcEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomCalcEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property double Value = {read=GetValue, write=SetValue, stored=false};
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomCalcEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomCalcEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCalcEdit(HWND ParentWindow) : Cxdropdownedit::TcxCustomPopupEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxCalcEdit;
class PASCALIMPLEMENTATION TcxCalcEdit : public TcxCustomCalcEdit
{
	typedef TcxCustomCalcEdit inherited;
	
private:
	HIDESBASE TcxCalcEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCalcEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCalcEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxCalcEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property EditValue = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxCalcEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property TextHint = {default=0};
	__property Value = {default=0};
	__property Visible = {default=1};
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
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property BiDiMode;
	__property ParentBiDiMode = {default=1};
	__property OnEndDock;
	__property OnStartDock;
public:
	/* TcxCustomCalcEdit.Destroy */ inline __fastcall virtual ~TcxCalcEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCalcEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomCalcEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCalcEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomCalcEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCalcEdit(HWND ParentWindow) : TcxCustomCalcEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterCalcEditHelper;
class PASCALIMPLEMENTATION TcxFilterCalcEditHelper : public Cxdropdownedit::TcxFilterDropDownEditHelper
{
	typedef Cxdropdownedit::TcxFilterDropDownEditHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
public:
	/* TObject.Create */ inline __fastcall TcxFilterCalcEditHelper(void) : Cxdropdownedit::TcxFilterDropDownEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterCalcEditHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxMaxCalcPrecision = System::Int8(0xf);
static const System::Int8 cxDefCalcPrecision = System::Int8(0xf);
static const System::Int8 cxMinCalcFontSize = System::Int8(0x8);
static const System::Int8 cxCalcMinBoldFontSize = System::Int8(0xa);
static const System::Int8 cxMinCalcBtnWidth = System::Int8(0x1c);
static const System::Int8 cxMinCalcBtnHeight = System::Int8(0x16);
static const int cxMinCalcLargeBtnWidth = int(47);
static const System::Int8 cxMinCalcXOfs = System::Int8(0x3);
static const System::Int8 cxMinCalcYOfs = System::Int8(0x3);
static const System::Byte cxMinCalcWidth = System::Byte(0xc6);
static const System::Byte cxMinCalcHeight = System::Byte(0x83);
extern PACKAGE Cxcalc__1 BtnCaptions;
}	/* namespace Cxcalc */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCALC)
using namespace Cxcalc;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcalcHPP
