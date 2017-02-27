// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxMaskEdit.pas' rev: 24.00 (Win32)

#ifndef CxmaskeditHPP
#define CxmaskeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxRegExpr.hpp>	// Pascal unit
#include <cxStandardMask.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxmaskedit
{
//-- type declarations -------------------------------------------------------
typedef System::UnicodeString TcxEditMask;

enum TcxEditMaskKind : unsigned char { emkStandard, emkRegExpr, emkRegExprEx };

class DELPHICLASS EcxMaskEditError;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EcxMaskEditError : public Cxedit::EcxEditError
{
	typedef Cxedit::EcxEditError inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxMaskEditError(const System::UnicodeString Msg) : Cxedit::EcxEditError(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxMaskEditError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Cxedit::EcxEditError(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxMaskEditError(NativeUInt Ident)/* overload */ : Cxedit::EcxEditError(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxMaskEditError(System::PResStringRec ResStringRec)/* overload */ : Cxedit::EcxEditError(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxMaskEditError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Cxedit::EcxEditError(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxMaskEditError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Cxedit::EcxEditError(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxMaskEditError(const System::UnicodeString Msg, int AHelpContext) : Cxedit::EcxEditError(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxMaskEditError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Cxedit::EcxEditError(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxMaskEditError(NativeUInt Ident, int AHelpContext)/* overload */ : Cxedit::EcxEditError(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxMaskEditError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Cxedit::EcxEditError(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxMaskEditError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Cxedit::EcxEditError(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxMaskEditError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Cxedit::EcxEditError(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxMaskEditError(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxMaskEditCustomMode;
class DELPHICLASS TcxCustomMaskEditProperties;
class DELPHICLASS TcxCustomMaskEdit;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMaskEditCustomMode : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TEditCharCase FCharCase;
	Cxtextedit::TcxEditEchoMode FEchoMode;
	System::UnicodeString FEditMask;
	TcxCustomMaskEditProperties* FProperties;
	TcxCustomMaskEditProperties* __fastcall GetProperties(void);
	
protected:
	int FClipboardTextLength;
	TcxCustomMaskEdit* FEdit;
	bool FNeedUpdateEditValue;
	void __fastcall ClearText(void);
	virtual TcxEditMaskKind __fastcall GetMaskKind(void);
	bool __fastcall HasEdit(void);
	__property System::Uitypes::TEditCharCase CharCase = {read=FCharCase, write=FCharCase, nodefault};
	__property Cxtextedit::TcxEditEchoMode EchoMode = {read=FEchoMode, write=FEchoMode, nodefault};
	__property System::UnicodeString EditMask = {read=FEditMask};
	__property TcxCustomMaskEditProperties* Properties = {read=GetProperties};
	
public:
	__fastcall virtual TcxMaskEditCustomMode(TcxCustomMaskEdit* AEdit, TcxCustomMaskEditProperties* AProperties);
	virtual void __fastcall AfterPasteFromClipboard(void) = 0 ;
	void __fastcall BeepOnError(void);
	virtual void __fastcall Compile(System::UnicodeString AMask) = 0 ;
	virtual System::UnicodeString __fastcall GetEmptyString(void) = 0 ;
	virtual System::UnicodeString __fastcall GetFormattedText(System::UnicodeString AText, bool AMatchForBlanksAndLiterals = true) = 0 ;
	virtual void __fastcall GotoEnd(void) = 0 ;
	virtual bool __fastcall IsCursorBegin(void) = 0 ;
	virtual bool __fastcall IsCursorEnd(void) = 0 ;
	virtual bool __fastcall IsFullValidText(System::UnicodeString AText) = 0 ;
	virtual void __fastcall LMouseDown(void) = 0 ;
	virtual void __fastcall PrePasteFromClipboard(void) = 0 ;
	virtual bool __fastcall PressBackSpace(void) = 0 ;
	virtual bool __fastcall PressDelete(void) = 0 ;
	virtual bool __fastcall PressEnd(void) = 0 ;
	virtual bool __fastcall PressHome(void) = 0 ;
	virtual bool __fastcall PressLeft(void) = 0 ;
	virtual bool __fastcall PressRight(void) = 0 ;
	virtual bool __fastcall PressSymbol(System::WideChar &ASymbol) = 0 ;
	virtual void __fastcall SetText(System::UnicodeString AText) = 0 ;
	virtual void __fastcall SynchronizeEditValue(void);
	virtual void __fastcall UpdateEditValue(void) = 0 ;
	virtual System::UnicodeString __fastcall GetUpdatedText(const System::UnicodeString AText, bool AMatchForBlanksAndLiterals = true) = 0 ;
	__property int ClipboardTextLength = {read=FClipboardTextLength, write=FClipboardTextLength, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxMaskEditCustomMode(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxMaskEditCustomModeClass;

class DELPHICLASS TcxMaskEditStandardMode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMaskEditStandardMode : public TcxMaskEditCustomMode
{
	typedef TcxMaskEditCustomMode inherited;
	
protected:
	Cxstandardmask::TcxStandardMask* FMask;
	int FSelStart;
	virtual System::WideChar __fastcall GetBlank(int APos);
	
public:
	__fastcall virtual TcxMaskEditStandardMode(TcxCustomMaskEdit* AEdit, TcxCustomMaskEditProperties* AProperties);
	__fastcall virtual ~TcxMaskEditStandardMode(void);
	virtual void __fastcall AfterPasteFromClipboard(void);
	virtual void __fastcall Compile(System::UnicodeString AMask);
	virtual System::UnicodeString __fastcall GetEmptyString(void);
	virtual System::UnicodeString __fastcall GetFormattedText(System::UnicodeString AText, bool AMatchForBlanksAndLiterals = true);
	virtual void __fastcall GotoEnd(void);
	virtual bool __fastcall IsCursorBegin(void);
	virtual bool __fastcall IsCursorEnd(void);
	virtual bool __fastcall IsFullValidText(System::UnicodeString AText);
	virtual void __fastcall LMouseDown(void);
	virtual void __fastcall PrePasteFromClipboard(void);
	virtual bool __fastcall PressBackSpace(void);
	virtual bool __fastcall PressDelete(void);
	virtual bool __fastcall PressEnd(void);
	virtual bool __fastcall PressHome(void);
	virtual bool __fastcall PressLeft(void);
	virtual bool __fastcall PressRight(void);
	virtual bool __fastcall PressSymbol(System::WideChar &ASymbol);
	virtual void __fastcall SetText(System::UnicodeString AText);
	virtual void __fastcall SynchronizeEditValue(void);
	virtual void __fastcall UpdateEditValue(void);
	virtual System::UnicodeString __fastcall GetUpdatedText(const System::UnicodeString AText, bool AMatchForBlanksAndLiterals = true);
};

#pragma pack(pop)

class DELPHICLASS TcxMaskEditRegExprMode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMaskEditRegExprMode : public TcxMaskEditCustomMode
{
	typedef TcxMaskEditCustomMode inherited;
	
protected:
	bool FBeginCursor;
	System::UnicodeString FHead;
	Cxregexpr::TcxRegExpr* FRegExpr;
	System::UnicodeString FSelect;
	System::UnicodeString FTail;
	bool FMouseAction;
	void __fastcall ClearTail(void);
	bool __fastcall CompileRegExpr(Cxregexpr::TcxRegExpr* ARegExpr);
	void __fastcall CursorCorrection(void);
	virtual void __fastcall DeleteSelection(void);
	virtual TcxEditMaskKind __fastcall GetMaskKind(void);
	bool __fastcall NextTail(void);
	virtual void __fastcall RestoreSelection(void);
	void __fastcall Reset(const System::UnicodeString AText);
	
public:
	__fastcall virtual TcxMaskEditRegExprMode(TcxCustomMaskEdit* AEdit, TcxCustomMaskEditProperties* AProperties);
	__fastcall virtual ~TcxMaskEditRegExprMode(void);
	virtual void __fastcall AfterPasteFromClipboard(void);
	virtual void __fastcall Compile(System::UnicodeString AMask);
	virtual System::UnicodeString __fastcall GetEmptyString(void);
	virtual System::UnicodeString __fastcall GetFormattedText(System::UnicodeString AText, bool AMatchForBlanksAndLiterals = true);
	virtual void __fastcall GotoEnd(void);
	virtual bool __fastcall IsCursorBegin(void);
	virtual bool __fastcall IsCursorEnd(void);
	virtual bool __fastcall IsFullValidText(System::UnicodeString AText);
	virtual void __fastcall LMouseDown(void);
	virtual void __fastcall PrePasteFromClipboard(void);
	virtual bool __fastcall PressBackSpace(void);
	virtual bool __fastcall PressDelete(void);
	virtual bool __fastcall PressEnd(void);
	virtual bool __fastcall PressHome(void);
	virtual bool __fastcall PressLeft(void);
	virtual bool __fastcall PressRight(void);
	virtual bool __fastcall PressSymbol(System::WideChar &ASymbol);
	virtual void __fastcall SetText(System::UnicodeString AText);
	void __fastcall SetRegExprCaseInsensitive(void);
	virtual void __fastcall SynchronizeEditValue(void);
	virtual void __fastcall UpdateEditValue(void);
	virtual System::UnicodeString __fastcall GetUpdatedText(const System::UnicodeString AText, bool AMatchForBlanksAndLiterals = true);
};

#pragma pack(pop)

class DELPHICLASS TcxMaskEditRegExprExMode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxMaskEditRegExprExMode : public TcxMaskEditRegExprMode
{
	typedef TcxMaskEditRegExprMode inherited;
	
private:
	System::UnicodeString FInternalUpdate;
	void __fastcall InternalSymbolUpdate(System::WideChar ASymbol);
	
protected:
	int FDeleteNumber;
	int FNewCursorPos;
	System::UnicodeString FUpdate;
	void __fastcall Clear(void);
	HIDESBASE void __fastcall CursorCorrection(void);
	virtual void __fastcall DeleteSelection(void);
	virtual TcxEditMaskKind __fastcall GetMaskKind(void);
	virtual void __fastcall RestoreSelection(void);
	void __fastcall SymbolDelete(void);
	void __fastcall SymbolUpdate(System::WideChar ASymbol);
	void __fastcall UpdateTail(void);
	
public:
	__fastcall virtual TcxMaskEditRegExprExMode(TcxCustomMaskEdit* AEdit, TcxCustomMaskEditProperties* AProperties);
	__fastcall virtual ~TcxMaskEditRegExprExMode(void);
	virtual void __fastcall AfterPasteFromClipboard(void);
	virtual void __fastcall Compile(System::UnicodeString AMask);
	virtual System::UnicodeString __fastcall GetEmptyString(void);
	virtual System::UnicodeString __fastcall GetFormattedText(System::UnicodeString AText, bool AMatchForBlanksAndLiterals = true);
	virtual void __fastcall GotoEnd(void);
	virtual bool __fastcall IsFullValidText(System::UnicodeString AText);
	virtual void __fastcall PrePasteFromClipboard(void);
	virtual bool __fastcall PressBackSpace(void);
	virtual bool __fastcall PressDelete(void);
	virtual bool __fastcall PressEnd(void);
	virtual bool __fastcall PressHome(void);
	virtual bool __fastcall PressLeft(void);
	virtual bool __fastcall PressRight(void);
	virtual bool __fastcall PressSymbol(System::WideChar &ASymbol);
	virtual void __fastcall SetText(System::UnicodeString AText);
	virtual void __fastcall UpdateEditValue(void);
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomMaskEditProperties : public Cxtextedit::TcxCustomTextEditProperties
{
	typedef Cxtextedit::TcxCustomTextEditProperties inherited;
	
private:
	bool FAlwaysShowBlanksAndLiterals;
	bool FCaseInsensitive;
	TcxEditMask FEditMask;
	System::UnicodeString FEmptyString;
	bool FIgnoreMaskBlank;
	TcxEditMaskKind FMaskKind;
	bool FMaxLengthSetting;
	TcxMaskEditCustomMode* FTempMode;
	TcxMaskEditCustomMode* __fastcall CreateMode(void);
	TcxMaskEditCustomMode* __fastcall CreateMode1(void);
	TcxEditMask __fastcall GetEditMask(void);
	bool __fastcall GetIsMasked(void);
	void __fastcall SetAlwaysShowBlanksAndLiterals(bool AValue);
	void __fastcall SetCaseInsensitive(bool AValue);
	void __fastcall SetEditMask(TcxEditMask Value);
	void __fastcall SetMaskKind(TcxEditMaskKind Value);
	bool __fastcall SpaceToken(System::WideChar AToken);
	bool __fastcall TestTempEditMask(void);
	bool __fastcall TestTempMaskKind(void);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall DoChanged(void);
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	virtual void __fastcall MaxLengthChanged(void);
	virtual void __fastcall SetCharCase(System::Uitypes::TEditCharCase Value);
	virtual bool __fastcall UseLookupData(void);
	bool __fastcall EmptyMask(System::UnicodeString AMask);
	System::UnicodeString __fastcall GetEmptyString(void);
	virtual TcxMaskEditCustomModeClass __fastcall GetModeClass(TcxEditMaskKind AMaskKind);
	
public:
	__fastcall virtual TcxCustomMaskEditProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomMaskEditProperties(void);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall DoPrepareDisplayValue(const System::Variant &AEditValue, System::Variant &ADisplayValue, bool AEditFocused);
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &Error, Cxedit::TcxCustomEdit* AEdit);
	__property bool IsMasked = {read=GetIsMasked, nodefault};
	__property bool AlwaysShowBlanksAndLiterals = {read=FAlwaysShowBlanksAndLiterals, write=SetAlwaysShowBlanksAndLiterals, default=0};
	__property bool CaseInsensitive = {read=FCaseInsensitive, write=SetCaseInsensitive, default=1};
	__property TcxEditMask EditMask = {read=GetEditMask, write=SetEditMask};
	__property bool IgnoreMaskBlank = {read=FIgnoreMaskBlank, write=FIgnoreMaskBlank, default=0};
	__property TcxEditMaskKind MaskKind = {read=FMaskKind, write=SetMaskKind, default=0};
	__property ValidateOnEnter = {default=1};
};


class PASCALIMPLEMENTATION TcxCustomMaskEdit : public Cxtextedit::TcxCustomTextEdit
{
	typedef Cxtextedit::TcxCustomTextEdit inherited;
	
private:
	bool FInternalTextSelection;
	TcxMaskEditCustomMode* FMode;
	bool FMyMessage;
	bool FShiftOn;
	System::UnicodeString FText;
	Vcl::Controls::TCaption __fastcall GetEditText(void);
	HIDESBASE TcxCustomMaskEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomMaskEditProperties* __fastcall GetActiveProperties(void);
	System::UnicodeString __fastcall InternalGetEmptyString(void);
	void __fastcall InternalSetValue(System::UnicodeString AValue);
	bool __fastcall IsCursorBegin(void);
	bool __fastcall IsCursorEnd(void);
	void __fastcall SetEditText(Vcl::Controls::TCaption AValue);
	HIDESBASE void __fastcall SetProperties(TcxCustomMaskEditProperties* Value);
	void __fastcall SendMyKeyDown(System::Word Key, System::Classes::TShiftState Shift);
	void __fastcall SendMyKeyPress(System::WideChar AKey);
	
protected:
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DoEnter(void);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyPress(System::WideChar &Key);
	virtual void __fastcall Initialize(void);
	virtual System::UnicodeString __fastcall InternalGetText(void);
	virtual void __fastcall InternalSetDisplayValue(const System::Variant &Value);
	virtual bool __fastcall InternalSetText(const System::UnicodeString Value);
	virtual bool __fastcall IsTextInputMode(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall LockInnerEditRepainting(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall SelChange(System::TObject* Sender);
	virtual void __fastcall SetSelText(const Vcl::Controls::TCaption Value);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall UndoPerformed(void);
	virtual void __fastcall UnlockInnerEditRepainting(void);
	virtual bool __fastcall CanSynchronizeModeText(void);
	void __fastcall DirectSetSelLength(int AValue);
	void __fastcall DirectSetSelStart(int AValue);
	virtual bool __fastcall IsCharValidForPos(System::WideChar &AChar, int APos);
	virtual void __fastcall UpdateTextFormatting(void);
	__property TcxMaskEditCustomMode* Mode = {read=FMode};
	
public:
	__fastcall virtual TcxCustomMaskEdit(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TcxCustomMaskEdit(void);
	virtual void __fastcall CutToClipboard(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PasteFromClipboard(void);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomMaskEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property Vcl::Controls::TCaption EditText = {read=GetEditText, write=SetEditText};
	__property TcxCustomMaskEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomMaskEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomMaskEdit(HWND ParentWindow) : Cxtextedit::TcxCustomTextEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxMaskEditProperties;
class PASCALIMPLEMENTATION TcxMaskEditProperties : public TcxCustomMaskEditProperties
{
	typedef TcxCustomMaskEditProperties inherited;
	
__published:
	__property Alignment;
	__property AlwaysShowBlanksAndLiterals = {default=0};
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property BeepOnError = {default=0};
	__property CaseInsensitive = {default=1};
	__property CharCase = {default=0};
	__property ClearKey = {default=0};
	__property EchoMode = {default=0};
	__property HideSelection = {default=1};
	__property IgnoreMaskBlank = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property IncrementalSearch = {default=1};
	__property LookupItems;
	__property LookupItemsSorted = {default=0};
	__property MaskKind = {default=0};
	__property EditMask = {default=0};
	__property MaxLength;
	__property Nullstring = {default=0};
	__property OEMConvert = {default=0};
	__property PasswordChar = {default=0};
	__property ReadOnly;
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnNewLookupDisplayText;
	__property OnValidate;
public:
	/* TcxCustomMaskEditProperties.Create */ inline __fastcall virtual TcxMaskEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomMaskEditProperties(AOwner) { }
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TcxMaskEditProperties(void) { }
	
};


class DELPHICLASS TcxMaskEdit;
class PASCALIMPLEMENTATION TcxMaskEdit : public TcxCustomMaskEdit
{
	typedef TcxCustomMaskEdit inherited;
	
private:
	HIDESBASE TcxMaskEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxMaskEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxMaskEditProperties* Value);
	
public:
	virtual bool __fastcall SupportsSpelling(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxMaskEditProperties* ActiveProperties = {read=GetActiveProperties};
	
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
	__property TcxMaskEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Text = {default=0};
	__property TextHint = {default=0};
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
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxMaskEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomMaskEdit(AOwner) { }
	/* TcxCustomMaskEdit.Destroy */ inline __fastcall virtual ~TcxMaskEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxMaskEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomMaskEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxMaskEdit(HWND ParentWindow) : TcxCustomMaskEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterMaskEditHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterMaskEditHelper : public Cxtextedit::TcxFilterTextEditHelper
{
	typedef Cxtextedit::TcxFilterTextEditHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
public:
	/* TObject.Create */ inline __fastcall TcxFilterMaskEditHelper(void) : Cxtextedit::TcxFilterTextEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterMaskEditHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IsAlphaChar(System::WideChar ch);
}	/* namespace Cxmaskedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXMASKEDIT)
using namespace Cxmaskedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxmaskeditHPP
