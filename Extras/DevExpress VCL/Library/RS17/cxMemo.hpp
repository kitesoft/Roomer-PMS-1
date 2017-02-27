// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxMemo.pas' rev: 24.00 (Win32)

#ifndef CxmemoHPP
#define CxmemoHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxmemo
{
//-- type declarations -------------------------------------------------------
__interface IcxInnerMemo;
typedef System::DelphiInterface<IcxInnerMemo> _di_IcxInnerMemo;
__interface  INTERFACE_UUID("{9D0DFE35-58DC-4C0C-9C98-65C5AAD757C9}") IcxInnerMemo  : public Cxtextedit::IcxInnerTextEdit 
{
	
public:
	virtual System::Types::TPoint __fastcall GetCaretPos(void) = 0 ;
	virtual System::Classes::TStrings* __fastcall GetLines(void) = 0 ;
	virtual System::Uitypes::TScrollStyle __fastcall GetScrollBars(void) = 0 ;
	virtual bool __fastcall GetWantReturns(void) = 0 ;
	virtual bool __fastcall GetWantTabs(void) = 0 ;
	virtual bool __fastcall GetWordWrap(void) = 0 ;
	virtual void __fastcall SetCaretPos(const System::Types::TPoint &Value) = 0 ;
	virtual void __fastcall SetScrollBars(System::Uitypes::TScrollStyle Value) = 0 ;
	virtual void __fastcall SetWantReturns(bool Value) = 0 ;
	virtual void __fastcall SetWantTabs(bool Value) = 0 ;
	virtual void __fastcall SetWordWrap(bool Value) = 0 ;
	__property System::Types::TPoint CaretPos = {read=GetCaretPos, write=SetCaretPos};
	__property System::Classes::TStrings* Lines = {read=GetLines};
	__property System::Uitypes::TScrollStyle ScrollBars = {read=GetScrollBars, write=SetScrollBars};
	__property bool WantReturns = {read=GetWantReturns, write=SetWantReturns};
	__property bool WantTabs = {read=GetWantTabs, write=SetWantTabs};
	__property bool WordWrap = {read=GetWordWrap, write=SetWordWrap};
};

class DELPHICLASS TcxCustomMemoViewInfo;
class PASCALIMPLEMENTATION TcxCustomMemoViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
public:
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxCustomMemoViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxCustomMemoViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


class DELPHICLASS TcxCustomMemoViewData;
class DELPHICLASS TcxCustomMemoProperties;
class PASCALIMPLEMENTATION TcxCustomMemoViewData : public Cxtextedit::TcxCustomTextEditViewData
{
	typedef Cxtextedit::TcxCustomTextEditViewData inherited;
	
private:
	HIDESBASE TcxCustomMemoProperties* __fastcall GetProperties(void);
	
protected:
	virtual int __fastcall GetMaxLineCount(void);
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TSize __fastcall InternalGetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	
public:
	virtual unsigned __fastcall GetDrawTextFlags(void);
	virtual System::Types::TRect __fastcall GetDrawTextOffset(void);
	virtual System::Types::TSize __fastcall GetEditContentSizeCorrection(void);
	virtual System::Types::TSize __fastcall GetEditingContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	__property TcxCustomMemoProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomMemoViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxtextedit::TcxCustomTextEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomMemoViewData(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomMemoProperties : public Cxtextedit::TcxCustomTextEditProperties
{
	typedef Cxtextedit::TcxCustomTextEditProperties inherited;
	
private:
	System::Uitypes::TScrollStyle FScrollBars;
	int FVisibleLineCount;
	bool FWantReturns;
	bool FWantTabs;
	bool FWordWrap;
	System::Classes::TAlignment __fastcall GetAlignment(void);
	HIDESBASE bool __fastcall IsAlignmentStored(void);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetScrollBars(System::Uitypes::TScrollStyle Value);
	void __fastcall SetVisibleLineCount(int Value);
	void __fastcall SetWantReturns(bool Value);
	void __fastcall SetWantTabs(bool Value);
	void __fastcall SetWordWrap(bool Value);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall InnerEditNeedsTabs(void);
	virtual bool __fastcall IsMultiLine(void);
	
public:
	__fastcall virtual TcxCustomMemoProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Cxedit::TcxEditSpecialFeatures __fastcall GetSpecialFeatures(void);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	__property System::Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment, stored=IsAlignmentStored, nodefault};
	__property AutoSelect = {default=0};
	__property System::Uitypes::TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=0};
	__property int VisibleLineCount = {read=FVisibleLineCount, write=SetVisibleLineCount, default=0};
	__property bool WantReturns = {read=FWantReturns, write=SetWantReturns, default=1};
	__property bool WantTabs = {read=FWantTabs, write=SetWantTabs, default=0};
	__property bool WordWrap = {read=FWordWrap, write=SetWordWrap, default=1};
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomMemoProperties(void) { }
	
};


class DELPHICLASS TcxMemoProperties;
class PASCALIMPLEMENTATION TcxMemoProperties : public TcxCustomMemoProperties
{
	typedef TcxCustomMemoProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoSelect = {default=0};
	__property CharCase = {default=0};
	__property ClearKey = {default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property MaxLength;
	__property OEMConvert = {default=0};
	__property ReadOnly;
	__property ScrollBars = {default=0};
	__property ValidationOptions = {default=1};
	__property VisibleLineCount = {default=0};
	__property WantReturns = {default=1};
	__property WantTabs = {default=0};
	__property WordWrap = {default=1};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnValidate;
public:
	/* TcxCustomMemoProperties.Create */ inline __fastcall virtual TcxMemoProperties(System::Classes::TPersistent* AOwner) : TcxCustomMemoProperties(AOwner) { }
	
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxMemoProperties(void) { }
	
};


class DELPHICLASS TcxCustomMemo;
class PASCALIMPLEMENTATION TcxCustomMemo : public Cxtextedit::TcxCustomTextEdit
{
	typedef Cxtextedit::TcxCustomTextEdit inherited;
	
private:
	bool FInternalAction;
	HIDESBASE TcxCustomMemoProperties* __fastcall GetActiveProperties(void);
	System::Types::TPoint __fastcall GetCaretPos(void);
	System::Classes::TStrings* __fastcall GetLines(void);
	_di_IcxInnerMemo __fastcall GetInnerMemo(void);
	HIDESBASE TcxCustomMemoProperties* __fastcall GetProperties(void);
	void __fastcall SetCaretPos(const System::Types::TPoint &Value);
	void __fastcall SetLines(System::Classes::TStrings* Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomMemoProperties* Value);
	HIDESBASE MESSAGE void __fastcall WMCommand(Winapi::Messages::TWMCommand &Message);
	
protected:
	virtual void __fastcall AdjustInnerEdit(void);
	virtual void __fastcall AdjustInnerEditPosition(void);
	virtual bool __fastcall CanAutoSize(void);
	virtual bool __fastcall CanKeyPressModifyEdit(System::WideChar Key);
	virtual bool __fastcall CanScrollLineWithoutScrollBars(Cxclasses::TcxDirection ADirection);
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall EnabledChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializeViewData(Cxedit::TcxCustomEditViewData* AViewData);
	virtual bool __fastcall SupportsSpelling(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual bool __fastcall SendActivationKey(System::WideChar Key);
	virtual void __fastcall SetSelText(const Vcl::Controls::TCaption Value);
	virtual bool __fastcall TabsNeeded(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall CanMemoKeyModifyEdit(System::Word Key, System::Classes::TShiftState Shift, bool AIsKeyPress);
	void __fastcall InternalSynchronizeEditValue(void);
	__property _di_IcxInnerMemo InnerMemo = {read=GetInnerMemo};
	
public:
	virtual void __fastcall ClearSelection(void);
	virtual void __fastcall CutToClipboard(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual bool __fastcall IsEditClass(void);
	__property TcxCustomMemoProperties* ActiveProperties = {read=GetActiveProperties};
	__property System::Types::TPoint CaretPos = {read=GetCaretPos, write=SetCaretPos};
	__property System::Classes::TStrings* Lines = {read=GetLines, write=SetLines};
	__property TcxCustomMemoProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxCustomMemo(System::Classes::TComponent* AOwner)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxCustomMemo(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomMemo(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomMemo(HWND ParentWindow) : Cxtextedit::TcxCustomTextEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxMemo;
class PASCALIMPLEMENTATION TcxMemo : public TcxCustomMemo
{
	typedef TcxCustomMemo inherited;
	
private:
	HIDESBASE TcxMemoProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxMemoProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxMemoProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxMemoProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property Lines;
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxMemoProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
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
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxMemo(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomMemo(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxMemo(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxMemo(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomMemo(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxMemo(HWND ParentWindow) : TcxCustomMemo(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterMemoHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterMemoHelper : public Cxtextedit::TcxFilterTextEditHelper
{
	typedef Cxtextedit::TcxFilterTextEditHelper inherited;
	
public:
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
public:
	/* TObject.Create */ inline __fastcall TcxFilterMemoHelper(void) : Cxtextedit::TcxFilterTextEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterMemoHelper(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomInnerMemoHelper;
class DELPHICLASS TcxCustomInnerMemo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomInnerMemoHelper : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxCustomInnerMemo* FEdit;
	
protected:
	__property TcxCustomInnerMemo* Edit = {read=FEdit};
	
public:
	__fastcall virtual TcxCustomInnerMemoHelper(TcxCustomInnerMemo* AEdit);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	Vcl::Controls::TWinControl* __fastcall GetControl(void);
	NativeInt __fastcall CallDefWndProc(unsigned AMsg, NativeUInt WParam, NativeInt LParam);
	bool __fastcall CanProcessClipboardMessages(void);
	System::Variant __fastcall GetEditValue(void);
	System::Classes::TNotifyEvent __fastcall GetOnChange(void);
	void __fastcall LockBounds(bool ALock);
	void __fastcall SafelySetFocus(void);
	void __fastcall SetEditValue(const System::Variant &Value);
	void __fastcall SetParent(Vcl::Controls::TWinControl* Value);
	void __fastcall SetOnChange(System::Classes::TNotifyEvent Value);
	void __fastcall ClearSelection(void);
	void __fastcall CopyToClipboard(void);
	System::Classes::TAlignment __fastcall GetAlignment(void);
	bool __fastcall GetAutoSelect(void);
	System::Uitypes::TEditCharCase __fastcall GetCharCase(void);
	Cxtextedit::TcxEditEchoMode __fastcall GetEchoMode(void);
	int __fastcall GetFirstVisibleCharIndex(void);
	bool __fastcall GetHideSelection(void);
	System::WideChar __fastcall GetImeLastChar(void);
	Vcl::Controls::TImeMode __fastcall GetImeMode(void);
	Vcl::Controls::TImeName __fastcall GetImeName(void);
	bool __fastcall GetInternalUpdating(void);
	int __fastcall GetMaxLength(void);
	bool __fastcall GetMultiLine(void);
	bool __fastcall GetOEMConvert(void);
	System::Classes::TNotifyEvent __fastcall GetOnSelChange(void);
	System::WideChar __fastcall GetPasswordChar(void);
	bool __fastcall GetReadOnly(void);
	int __fastcall GetSelLength(void);
	int __fastcall GetSelStart(void);
	System::UnicodeString __fastcall GetSelText(void);
	bool __fastcall GetUseLeftAlignmentOnEditing(void);
	void __fastcall SelectAll(void);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetAutoSelect(bool Value);
	void __fastcall SetCharCase(System::Uitypes::TEditCharCase Value);
	void __fastcall SetEchoMode(Cxtextedit::TcxEditEchoMode Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetImeMode(Vcl::Controls::TImeMode Value);
	void __fastcall SetImeName(const Vcl::Controls::TImeName Value);
	void __fastcall SetInternalUpdating(bool Value);
	void __fastcall SetMaxLength(int Value);
	void __fastcall SetOEMConvert(bool Value);
	void __fastcall SetOnSelChange(System::Classes::TNotifyEvent Value);
	void __fastcall SetPasswordChar(System::WideChar Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall SetSelLength(int Value);
	void __fastcall SetSelStart(int Value);
	void __fastcall SetSelText(System::UnicodeString Value);
	void __fastcall SetUseLeftAlignmentOnEditing(bool Value);
	System::UnicodeString __fastcall GetTextHint(void);
	void __fastcall SetTextHint(System::UnicodeString Value);
	System::Types::TPoint __fastcall GetCaretPos(void);
	System::Classes::TStrings* __fastcall GetLines(void);
	System::Uitypes::TScrollStyle __fastcall GetScrollBars(void);
	bool __fastcall GetWantReturns(void);
	bool __fastcall GetWantTabs(void);
	bool __fastcall GetWordWrap(void);
	void __fastcall SetCaretPos(const System::Types::TPoint &Value);
	void __fastcall SetScrollBars(System::Uitypes::TScrollStyle Value);
	void __fastcall SetWantReturns(bool Value);
	void __fastcall SetWantTabs(bool Value);
	void __fastcall SetWordWrap(bool Value);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomInnerMemoHelper(void) { }
	
private:
	void *__IcxInnerMemo;	/* IcxInnerMemo */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9D0DFE35-58DC-4C0C-9C98-65C5AAD757C9}
	operator _di_IcxInnerMemo()
	{
		_di_IcxInnerMemo intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxInnerMemo*(void) { return (IcxInnerMemo*)&__IcxInnerMemo; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {263EBB8D-1EA9-4CAC-8367-ADD74D2A9651}
	operator Cxtextedit::_di_IcxInnerTextEdit()
	{
		Cxtextedit::_di_IcxInnerTextEdit intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxtextedit::IcxInnerTextEdit*(void) { return (Cxtextedit::IcxInnerTextEdit*)&__IcxInnerMemo; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {468D21B5-48AA-4077-8ED5-4C6112D460B1}
	operator Cxedit::_di_IcxCustomInnerEdit()
	{
		Cxedit::_di_IcxCustomInnerEdit intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxCustomInnerEdit*(void) { return (Cxedit::IcxCustomInnerEdit*)&__IcxInnerMemo; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator Cxcontainer::_di_IcxContainerInnerControl()
	{
		Cxcontainer::_di_IcxContainerInnerControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxInnerMemo; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxMultiLineEditCharPosition
{
public:
	int Line;
	int Col;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxInnerMemoSelectionState
{
public:
	TcxMultiLineEditCharPosition CursorPosition;
	TcxMultiLineEditCharPosition SelectionStart;
	TcxMultiLineEditCharPosition SelectionEnd;
};
#pragma pack(pop)


class PASCALIMPLEMENTATION TcxCustomInnerMemo : public Vcl::Stdctrls::TMemo
{
	typedef Vcl::Stdctrls::TMemo inherited;
	
private:
	bool FAutoSelect;
	Cxtextedit::TcxEditEchoMode FEchoMode;
	bool FEscapePressed;
	TcxCustomInnerMemoHelper* FHelper;
	int FInternalTextSettingCount;
	bool FInternalUpdating;
	bool FIsCreating;
	int FLockBoundsCount;
	System::Classes::TNotifyEvent FOnSelChange;
	void __fastcall BeginInternalTextSetting(void);
	void __fastcall EndInternalTextSetting(void);
	bool __fastcall IsInternalTextSetting(void);
	TcxCustomMemo* __fastcall GetContainer(void);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNKeyDown(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall EMReplaceSel(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMSetSel(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMClear(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMIMEComposition(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFont(Winapi::Messages::TWMSetFont &Message);
	MESSAGE void __fastcall WMSetText(Winapi::Messages::TWMSetText &Message);
	HIDESBASE MESSAGE void __fastcall WMHScroll(Winapi::Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Winapi::Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	
protected:
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	Cxedit::_di_IcxCustomInnerEdit __fastcall GetHelper(void);
	bool __fastcall AllowDrawEdgesAndBorders(void);
	__property bool AutoSelect = {read=FAutoSelect, write=FAutoSelect, default=0};
	__property TcxCustomMemo* Container = {read=GetContainer};
	__property TcxCustomInnerMemoHelper* Helper = {read=FHelper};
	
public:
	__fastcall virtual TcxCustomInnerMemo(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerMemo(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall CanFocus(void);
	virtual void __fastcall DefaultHandler(void *Message);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property CharCase = {default=0};
	__property System::Classes::TNotifyEvent OnSelChange = {read=FOnSelChange, write=FOnSelChange};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerMemo(HWND ParentWindow) : Vcl::Stdctrls::TMemo(ParentWindow) { }
	
private:
	void *__IcxPaintControlsHelper;	/* Cxgraphics::IcxPaintControlsHelper */
	void *__IcxInnerEditHelper;	/* Cxedit::IcxInnerEditHelper */
	void *__IcxContainerInnerControl;	/* Cxcontainer::IcxContainerInnerControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7EFAF634-E8D2-489D-9603-FCFC03ACA460}
	operator Cxgraphics::_di_IcxPaintControlsHelper()
	{
		Cxgraphics::_di_IcxPaintControlsHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgraphics::IcxPaintControlsHelper*(void) { return (Cxgraphics::IcxPaintControlsHelper*)&__IcxPaintControlsHelper; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {35667555-6DC8-40D5-B705-B08D5697C621}
	operator Cxedit::_di_IcxInnerEditHelper()
	{
		Cxedit::_di_IcxInnerEditHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxInnerEditHelper*(void) { return (Cxedit::IcxInnerEditHelper*)&__IcxInnerEditHelper; }
	#endif
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxPaintControlsHelper; }
	#endif
	
};


class DELPHICLASS TcxAutoHeightInplaceEditViewData;
class DELPHICLASS TcxAutoHeightInplaceEdit;
class PASCALIMPLEMENTATION TcxAutoHeightInplaceEditViewData : public TcxCustomMemoViewData
{
	typedef TcxCustomMemoViewData inherited;
	
private:
	TcxAutoHeightInplaceEdit* __fastcall GetEdit(void);
	
public:
	virtual System::Types::TRect __fastcall GetClientExtent(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TcxAutoHeightInplaceEdit* Edit = {read=GetEdit};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxAutoHeightInplaceEditViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : TcxCustomMemoViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxAutoHeightInplaceEditViewData(void) { }
	
};


class DELPHICLASS TcxAutoHeightInplaceEditViewInfo;
class PASCALIMPLEMENTATION TcxAutoHeightInplaceEditViewInfo : public TcxCustomMemoViewInfo
{
	typedef TcxCustomMemoViewInfo inherited;
	
private:
	TcxAutoHeightInplaceEdit* __fastcall GetEdit(void);
	
protected:
	virtual void __fastcall DrawParentFocusRect(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__property TcxAutoHeightInplaceEdit* Edit = {read=GetEdit};
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxAutoHeightInplaceEditViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxAutoHeightInplaceEditViewInfo(void) : TcxCustomMemoViewInfo() { }
	
};


class DELPHICLASS TcxAutoHeightInplaceEditProperties;
class PASCALIMPLEMENTATION TcxAutoHeightInplaceEditProperties : public TcxMemoProperties
{
	typedef TcxMemoProperties inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
public:
	/* TcxCustomMemoProperties.Create */ inline __fastcall virtual TcxAutoHeightInplaceEditProperties(System::Classes::TPersistent* AOwner) : TcxMemoProperties(AOwner) { }
	
public:
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxAutoHeightInplaceEditProperties(void) { }
	
};


class DELPHICLASS TcxAutoHeightInplaceEditInnerMemo;
class PASCALIMPLEMENTATION TcxAutoHeightInplaceEditInnerMemo : public TcxCustomInnerMemo
{
	typedef TcxCustomInnerMemo inherited;
	
public:
	__fastcall virtual TcxAutoHeightInplaceEditInnerMemo(System::Classes::TComponent* AOwner);
public:
	/* TcxCustomInnerMemo.Destroy */ inline __fastcall virtual ~TcxAutoHeightInplaceEditInnerMemo(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxAutoHeightInplaceEditInnerMemo(HWND ParentWindow) : TcxCustomInnerMemo(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxAutoHeightInplaceEdit : public TcxMemo
{
	typedef TcxMemo inherited;
	
private:
	Cxedit::TcxInplaceEditAutoHeight FAutoHeight;
	System::Uitypes::TColor FBorderColor;
	Cxgraphics::TcxBorders FBorders;
	int FCalculatedHeight;
	Cxedit::TcxCustomEditingController* FEditingController;
	int FPrevHeight;
	int __fastcall GetExtraEditHeight(void);
	HIDESBASE MESSAGE void __fastcall WMCommand(Winapi::Messages::TWMCommand &Message);
	
protected:
	void __fastcall CalculateHeight(void);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass(void);
	
public:
	__fastcall virtual TcxAutoHeightInplaceEdit(Cxedit::TcxCustomEditingController* AEditingController);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxedit::TcxInplaceEditAutoHeight AutoHeight = {read=FAutoHeight, write=FAutoHeight, nodefault};
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property Cxgraphics::TcxBorders Borders = {read=FBorders, write=FBorders, nodefault};
	__property int CalculatedHeight = {read=FCalculatedHeight, nodefault};
	__property Cxedit::TcxCustomEditingController* EditingController = {read=FEditingController};
public:
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxAutoHeightInplaceEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxAutoHeightInplaceEdit(HWND ParentWindow) : TcxMemo(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ExtractFirstLine(System::WideString &AText, int AMaxLength = 0x0);
extern PACKAGE void __fastcall SetMemoCaretPos(Vcl::Stdctrls::TCustomMemo* AMemo, const System::Types::TPoint &Value);
}	/* namespace Cxmemo */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXMEMO)
using namespace Cxmemo;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxmemoHPP
