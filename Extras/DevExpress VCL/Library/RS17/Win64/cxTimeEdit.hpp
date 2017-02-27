// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTimeEdit.pas' rev: 24.00 (Win64)

#ifndef CxtimeeditHPP
#define CxtimeeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxFormats.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtimeedit
{
//-- type declarations -------------------------------------------------------
enum TcxTimeEditZoneKind : unsigned char { tzHour, tzMin, tzSec, tzTimeSuffix };

struct DECLSPEC_DRECORD TcxTimeEditZoneInfo
{
public:
	TcxTimeEditZoneKind Kind;
	int Start;
	int Length;
	Cxformats::TcxTimeSuffixKind TimeSuffixKind;
	bool Use24HourFormat;
};


class DELPHICLASS TcxTimeEditMaskMode;
class PASCALIMPLEMENTATION TcxTimeEditMaskMode : public Cxmaskedit::TcxMaskEditStandardMode
{
	typedef Cxmaskedit::TcxMaskEditStandardMode inherited;
	
protected:
	virtual System::WideChar __fastcall GetBlank(int APos);
public:
	/* TcxMaskEditStandardMode.Create */ inline __fastcall virtual TcxTimeEditMaskMode(Cxmaskedit::TcxCustomMaskEdit* AEdit, Cxmaskedit::TcxCustomMaskEditProperties* AProperties) : Cxmaskedit::TcxMaskEditStandardMode(AEdit, AProperties) { }
	/* TcxMaskEditStandardMode.Destroy */ inline __fastcall virtual ~TcxTimeEditMaskMode(void) { }
	
};


enum TcxTimeEditTimeFormat : unsigned char { tfHourMinSec, tfHourMin, tfHour };

class DELPHICLASS TcxCustomTimeEditProperties;
class PASCALIMPLEMENTATION TcxCustomTimeEditProperties : public Cxspinedit::TcxCustomSpinEditProperties
{
	typedef Cxspinedit::TcxCustomSpinEditProperties inherited;
	
private:
	bool FAutoCorrectHours;
	bool FShowDate;
	TcxTimeEditTimeFormat FTimeFormat;
	bool FUse24HourFormat;
	bool FUseTimeFormatWhenUnfocused;
	void __fastcall SetAutoCorrectHours(bool Value);
	void __fastcall SetUse24HourFormat(bool Value);
	void __fastcall SetShowDate(bool Value);
	void __fastcall SetTimeFormat(TcxTimeEditTimeFormat Value);
	void __fastcall SetUseTimeFormatWhenUnfocused(bool Value);
	
protected:
	virtual System::Variant __fastcall DefaultFocusedDisplayValue(void);
	virtual bool __fastcall ExtendValueUpToBound(void);
	virtual void __fastcall FormatChanged(void);
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	virtual Cxmaskedit::TcxMaskEditCustomModeClass __fastcall GetModeClass(Cxmaskedit::TcxEditMaskKind AMaskKind);
	virtual void __fastcall GetTimeZoneInfo(int APos, /* out */ TcxTimeEditZoneInfo &AInfo);
	virtual bool __fastcall IsDisplayValueNumeric(void);
	virtual bool __fastcall IsEditValueNumeric(void);
	virtual System::Variant __fastcall PrepareValue(const System::Variant &AValue, bool AEditFocused);
	virtual bool __fastcall PreserveSelection(void);
	TcxTimeEditZoneKind __fastcall GetEditingPlace(int APos);
	virtual int __fastcall GetTimePartLength(TcxTimeEditZoneKind AKind);
	virtual int __fastcall GetTimePartPos(TcxTimeEditZoneKind AKind);
	virtual Cxformats::TcxTimeSuffixKind __fastcall GetTimeSuffixKind(void);
	void __fastcall UpdateEditMask(void);
	
public:
	__fastcall virtual TcxCustomTimeEditProperties(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual bool __fastcall IsDisplayValueValid(System::Variant &DisplayValue, bool AEditFocused);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall DoPrepareDisplayValue(const System::Variant &AEditValue, System::Variant &ADisplayValue, bool AEditFocused);
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	__property bool AutoCorrectHours = {read=FAutoCorrectHours, write=SetAutoCorrectHours, default=1};
	__property bool ShowDate = {read=FShowDate, write=SetShowDate, default=0};
	__property TcxTimeEditTimeFormat TimeFormat = {read=FTimeFormat, write=SetTimeFormat, default=0};
	__property bool Use24HourFormat = {read=FUse24HourFormat, write=SetUse24HourFormat, default=1};
	__property bool UseTimeFormatWhenUnfocused = {read=FUseTimeFormatWhenUnfocused, write=SetUseTimeFormatWhenUnfocused, default=1};
public:
	/* TcxCustomSpinEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomTimeEditProperties(void) { }
	
};


class DELPHICLASS TcxTimeEditProperties;
class PASCALIMPLEMENTATION TcxTimeEditProperties : public TcxCustomTimeEditProperties
{
	typedef TcxCustomTimeEditProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoCorrectHours = {default=1};
	__property AutoSelect = {default=1};
	__property BeepOnError = {default=0};
	__property Circular = {default=0};
	__property ClearKey = {default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediatePost = {default=0};
	__property Increment = {default=0};
	__property LargeIncrement = {default=0};
	__property Nullstring = {default=0};
	__property ReadOnly;
	__property ShowDate = {default=0};
	__property SpinButtons;
	__property TimeFormat = {default=0};
	__property UseCtrlIncrement = {default=0};
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property Use24HourFormat = {default=1};
	__property UseTimeFormatWhenUnfocused = {default=1};
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnValidate;
public:
	/* TcxCustomTimeEditProperties.Create */ inline __fastcall virtual TcxTimeEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomTimeEditProperties(AOwner) { }
	
public:
	/* TcxCustomSpinEditProperties.Destroy */ inline __fastcall virtual ~TcxTimeEditProperties(void) { }
	
};


class DELPHICLASS TcxCustomTimeEdit;
class PASCALIMPLEMENTATION TcxCustomTimeEdit : public Cxspinedit::TcxCustomSpinEdit
{
	typedef Cxspinedit::TcxCustomSpinEdit inherited;
	
private:
	System::TDate FSavedDate;
	HIDESBASE TcxCustomTimeEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomTimeEditProperties* __fastcall GetActiveProperties(void);
	System::TTime __fastcall GetTime(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomTimeEditProperties* Value);
	void __fastcall SetTime(System::TTime Value);
	
protected:
	virtual double __fastcall GetIncrement(Cxspinedit::TcxSpinEditButton AButton);
	virtual System::Variant __fastcall GetValue(void);
	virtual System::UnicodeString __fastcall IncrementValueToStr(const System::Variant &AValue);
	virtual void __fastcall Initialize(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	virtual System::UnicodeString __fastcall InternalGetText(void);
	virtual void __fastcall InternalSetDisplayValue(const System::Variant &Value);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual bool __fastcall InternalSetText(const System::UnicodeString Value);
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	virtual bool __fastcall IsCharValidForPos(System::WideChar &AChar, int APos);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall SetValue(const System::Variant &Value);
	TcxTimeEditZoneKind __fastcall EditingPlace(void);
	
public:
	virtual void __fastcall Clear(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual bool __fastcall Increment(Cxspinedit::TcxSpinEditButton AButton);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomTimeEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomTimeEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property System::TTime Time = {read=GetTime, write=SetTime, stored=false};
public:
	/* TcxCustomSpinEdit.Destroy */ inline __fastcall virtual ~TcxCustomTimeEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomTimeEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxspinedit::TcxCustomSpinEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomTimeEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxspinedit::TcxCustomSpinEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomTimeEdit(HWND ParentWindow) : Cxspinedit::TcxCustomSpinEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxTimeEdit;
class PASCALIMPLEMENTATION TcxTimeEdit : public TcxCustomTimeEdit
{
	typedef TcxCustomTimeEdit inherited;
	
private:
	HIDESBASE TcxTimeEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxTimeEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxTimeEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxTimeEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragMode = {default=0};
	__property EditValue = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxTimeEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Time = {default=0};
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
	/* TcxCustomSpinEdit.Destroy */ inline __fastcall virtual ~TcxTimeEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxTimeEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomTimeEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxTimeEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomTimeEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTimeEdit(HWND ParentWindow) : TcxCustomTimeEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterTimeEditHelper;
class PASCALIMPLEMENTATION TcxFilterTimeEditHelper : public Cxspinedit::TcxFilterSpinEditHelper
{
	typedef Cxspinedit::TcxFilterSpinEditHelper inherited;
	
protected:
	__classmethod virtual void __fastcall InitializeEdit(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
public:
	/* TObject.Create */ inline __fastcall TcxFilterTimeEditHelper(void) : Cxspinedit::TcxFilterSpinEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterTimeEditHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IsCharValidForTimeEdit(Cxmaskedit::TcxCustomMaskEdit* ATimeEdit, System::WideChar &AChar, int APos, const TcxTimeEditZoneInfo &ATimeZoneInfo);
}	/* namespace Cxtimeedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTIMEEDIT)
using namespace Cxtimeedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtimeeditHPP
