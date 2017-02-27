// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCurrencyEdit.pas' rev: 24.00 (Win64)

#ifndef CxcurrencyeditHPP
#define CxcurrencyeditHPP

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
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcurrencyedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCurrencyEditPropertiesValues;
class PASCALIMPLEMENTATION TcxCurrencyEditPropertiesValues : public Cxtextedit::TcxTextEditPropertiesValues
{
	typedef Cxtextedit::TcxTextEditPropertiesValues inherited;
	
private:
	bool FDecimalPlaces;
	void __fastcall SetDecimalPlaces(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool DecimalPlaces = {read=FDecimalPlaces, write=SetDecimalPlaces, stored=false, nodefault};
public:
	/* TcxCustomEditPropertiesValues.Create */ inline __fastcall virtual TcxCurrencyEditPropertiesValues(System::Classes::TPersistent* AOwner) : Cxtextedit::TcxTextEditPropertiesValues(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCurrencyEditPropertiesValues(void) { }
	
};


class DELPHICLASS TcxCustomCurrencyEditProperties;
class PASCALIMPLEMENTATION TcxCustomCurrencyEditProperties : public Cxtextedit::TcxCustomTextEditProperties
{
	typedef Cxtextedit::TcxCustomTextEditProperties inherited;
	
private:
	int FDecimalPlaces;
	bool FFormatChanging;
	bool FNullable;
	bool FUseThousandSeparator;
	HIDESBASE TcxCurrencyEditPropertiesValues* __fastcall GetAssignedValues(void);
	int __fastcall GetDecimalPlaces(void);
	bool __fastcall IsDecimalPlacesStored(void);
	HIDESBASE void __fastcall SetAssignedValues(TcxCurrencyEditPropertiesValues* Value);
	void __fastcall SetDecimalPlaces(int Value);
	void __fastcall SetNullable(bool Value);
	void __fastcall SetUseThousandSeparator(const bool Value);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	virtual System::UnicodeString __fastcall GetDefaultDisplayFormat(void);
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	virtual bool __fastcall HasDigitGrouping(bool AIsDisplayValueSynchronizing);
	virtual System::UnicodeString __fastcall InternalGetEditFormat(/* out */ bool &AIsCurrency, /* out */ bool &AIsOnGetTextAssigned, Cxtextedit::TcxCustomTextEdit* AEdit = (Cxtextedit::TcxCustomTextEdit*)(0x0));
	virtual bool __fastcall IsEditValueNumeric(void);
	bool __fastcall StrToFloatEx(System::UnicodeString S, double &Value);
	__property TcxCurrencyEditPropertiesValues* AssignedValues = {read=GetAssignedValues, write=SetAssignedValues};
	
public:
	__fastcall virtual TcxCustomCurrencyEditProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	virtual bool __fastcall IsDisplayValueValid(System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall DoPrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	__property int DecimalPlaces = {read=GetDecimalPlaces, write=SetDecimalPlaces, stored=IsDecimalPlacesStored, nodefault};
	__property bool Nullable = {read=FNullable, write=SetNullable, default=1};
	__property ValidateOnEnter = {default=1};
	__property bool UseThousandSeparator = {read=FUseThousandSeparator, write=SetUseThousandSeparator, default=0};
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomCurrencyEditProperties(void) { }
	
};


class DELPHICLASS TcxCurrencyEditProperties;
class PASCALIMPLEMENTATION TcxCurrencyEditProperties : public TcxCustomCurrencyEditProperties
{
	typedef TcxCustomCurrencyEditProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property ClearKey = {default=0};
	__property DecimalPlaces;
	__property DisplayFormat = {default=0};
	__property EchoMode = {default=0};
	__property EditFormat = {default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property MaxLength;
	__property MaxValue = {default=0};
	__property MinValue = {default=0};
	__property Nullable = {default=1};
	__property Nullstring = {default=0};
	__property PasswordChar = {default=0};
	__property ReadOnly;
	__property UseDisplayFormatWhenEditing = {default=0};
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property UseThousandSeparator = {default=0};
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnValidate;
public:
	/* TcxCustomCurrencyEditProperties.Create */ inline __fastcall virtual TcxCurrencyEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomCurrencyEditProperties(AOwner) { }
	
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxCurrencyEditProperties(void) { }
	
};


class DELPHICLASS TcxCustomCurrencyEdit;
class PASCALIMPLEMENTATION TcxCustomCurrencyEdit : public Cxtextedit::TcxCustomTextEdit
{
	typedef Cxtextedit::TcxCustomTextEdit inherited;
	
private:
	HIDESBASE TcxCustomCurrencyEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomCurrencyEditProperties* __fastcall GetActiveProperties(void);
	double __fastcall GetValue(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomCurrencyEditProperties* Value);
	void __fastcall SetValue(double Value);
	
protected:
	virtual void __fastcall CheckEditorValueBounds(void);
	virtual void __fastcall Initialize(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	virtual bool __fastcall IsValidChar(System::WideChar Key);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PasteFromClipboard(void);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomCurrencyEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomCurrencyEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property double Value = {read=GetValue, write=SetValue, stored=false};
public:
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxCustomCurrencyEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxCustomCurrencyEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomCurrencyEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCurrencyEdit(HWND ParentWindow) : Cxtextedit::TcxCustomTextEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxCurrencyEdit;
class PASCALIMPLEMENTATION TcxCurrencyEdit : public TcxCustomCurrencyEdit
{
	typedef TcxCustomCurrencyEdit inherited;
	
private:
	HIDESBASE TcxCurrencyEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxCurrencyEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCurrencyEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxCurrencyEditProperties* ActiveProperties = {read=GetActiveProperties};
	
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
	__property TcxCurrencyEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnEditing;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property BiDiMode;
	__property ParentBiDiMode = {default=1};
	__property OnEndDock;
	__property OnStartDock;
public:
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxCurrencyEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomCurrencyEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxCurrencyEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCurrencyEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomCurrencyEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCurrencyEdit(HWND ParentWindow) : TcxCustomCurrencyEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterCurrencyEditHelper;
class PASCALIMPLEMENTATION TcxFilterCurrencyEditHelper : public Cxtextedit::TcxFilterTextEditHelper
{
	typedef Cxtextedit::TcxFilterTextEditHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
public:
	/* TObject.Create */ inline __fastcall TcxFilterCurrencyEditHelper(void) : Cxtextedit::TcxFilterTextEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterCurrencyEditHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxcurrencyedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCURRENCYEDIT)
using namespace Cxcurrencyedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcurrencyeditHPP
