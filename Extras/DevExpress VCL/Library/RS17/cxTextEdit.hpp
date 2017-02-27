// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTextEdit.pas' rev: 24.00 (Win32)

#ifndef CxtexteditHPP
#define CxtexteditHPP

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
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxFormats.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtextedit
{
//-- type declarations -------------------------------------------------------
enum TcxEditEchoMode : unsigned char { eemNormal, eemPassword };

enum TcxEditScrollCause : unsigned char { escKeyboard, escMouseWheel };

enum TcxEditValueBound : unsigned char { evbMin, evbMax };

enum TcxTextEditViewStyle : unsigned char { vsNormal, vsHideCursor, vsButtonsOnly, vsButtonsAutoWidth };

typedef void __fastcall (__closure *TcxTextEditCustomDrawHandler)(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect);

__interface IcxInnerTextEdit;
typedef System::DelphiInterface<IcxInnerTextEdit> _di_IcxInnerTextEdit;
__interface  INTERFACE_UUID("{263EBB8D-1EA9-4CAC-8367-ADD74D2A9651}") IcxInnerTextEdit  : public Cxedit::IcxCustomInnerEdit 
{
	
public:
	virtual void __fastcall ClearSelection(void) = 0 ;
	virtual void __fastcall CopyToClipboard(void) = 0 ;
	virtual System::Classes::TAlignment __fastcall GetAlignment(void) = 0 ;
	virtual bool __fastcall GetAutoSelect(void) = 0 ;
	virtual System::Uitypes::TEditCharCase __fastcall GetCharCase(void) = 0 ;
	virtual TcxEditEchoMode __fastcall GetEchoMode(void) = 0 ;
	virtual int __fastcall GetFirstVisibleCharIndex(void) = 0 ;
	virtual bool __fastcall GetHideSelection(void) = 0 ;
	virtual System::WideChar __fastcall GetImeLastChar(void) = 0 ;
	virtual Vcl::Controls::TImeMode __fastcall GetImeMode(void) = 0 ;
	virtual Vcl::Controls::TImeName __fastcall GetImeName(void) = 0 ;
	virtual bool __fastcall GetInternalUpdating(void) = 0 ;
	virtual int __fastcall GetMaxLength(void) = 0 ;
	virtual bool __fastcall GetMultiLine(void) = 0 ;
	virtual bool __fastcall GetOEMConvert(void) = 0 ;
	virtual System::Classes::TNotifyEvent __fastcall GetOnSelChange(void) = 0 ;
	virtual System::WideChar __fastcall GetPasswordChar(void) = 0 ;
	virtual int __fastcall GetSelLength(void) = 0 ;
	virtual int __fastcall GetSelStart(void) = 0 ;
	virtual System::UnicodeString __fastcall GetSelText(void) = 0 ;
	virtual bool __fastcall GetUseLeftAlignmentOnEditing(void) = 0 ;
	virtual void __fastcall SelectAll(void) = 0 ;
	virtual void __fastcall SetAlignment(System::Classes::TAlignment Value) = 0 ;
	virtual void __fastcall SetAutoSelect(bool Value) = 0 ;
	virtual void __fastcall SetCharCase(System::Uitypes::TEditCharCase Value) = 0 ;
	virtual void __fastcall SetEchoMode(TcxEditEchoMode Value) = 0 ;
	virtual void __fastcall SetHideSelection(bool Value) = 0 ;
	virtual void __fastcall SetInternalUpdating(bool Value) = 0 ;
	virtual void __fastcall SetImeMode(Vcl::Controls::TImeMode Value) = 0 ;
	virtual void __fastcall SetImeName(const Vcl::Controls::TImeName Value) = 0 ;
	virtual void __fastcall SetMaxLength(int Value) = 0 ;
	virtual void __fastcall SetOEMConvert(bool Value) = 0 ;
	virtual void __fastcall SetOnSelChange(System::Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetPasswordChar(System::WideChar Value) = 0 ;
	virtual void __fastcall SetSelLength(int Value) = 0 ;
	virtual void __fastcall SetSelStart(int Value) = 0 ;
	virtual void __fastcall SetSelText(System::UnicodeString Value) = 0 ;
	virtual void __fastcall SetUseLeftAlignmentOnEditing(bool Value) = 0 ;
	virtual System::UnicodeString __fastcall GetTextHint(void) = 0 ;
	virtual void __fastcall SetTextHint(System::UnicodeString Value) = 0 ;
	__property System::Classes::TAlignment Alignment = {read=GetAlignment, write=SetAlignment};
	__property bool AutoSelect = {read=GetAutoSelect, write=SetAutoSelect};
	__property System::Uitypes::TEditCharCase CharCase = {read=GetCharCase, write=SetCharCase};
	__property TcxEditEchoMode EchoMode = {read=GetEchoMode, write=SetEchoMode};
	__property bool HideSelection = {read=GetHideSelection, write=SetHideSelection};
	__property System::WideChar ImeLastChar = {read=GetImeLastChar};
	__property Vcl::Controls::TImeMode ImeMode = {read=GetImeMode, write=SetImeMode};
	__property Vcl::Controls::TImeName ImeName = {read=GetImeName, write=SetImeName};
	__property bool InternalUpdating = {read=GetInternalUpdating, write=SetInternalUpdating};
	__property int MaxLength = {read=GetMaxLength, write=SetMaxLength};
	__property bool MultiLine = {read=GetMultiLine};
	__property bool OEMConvert = {read=GetOEMConvert, write=SetOEMConvert};
	__property System::WideChar PasswordChar = {read=GetPasswordChar, write=SetPasswordChar};
	__property int SelLength = {read=GetSelLength, write=SetSelLength};
	__property int SelStart = {read=GetSelStart, write=SetSelStart};
	__property System::UnicodeString SelText = {read=GetSelText, write=SetSelText};
	__property bool UseLeftAlignmentOnEditing = {read=GetUseLeftAlignmentOnEditing, write=SetUseLeftAlignmentOnEditing};
	__property System::UnicodeString TextHint = {read=GetTextHint, write=SetTextHint};
	__property System::Classes::TNotifyEvent OnSelChange = {read=GetOnSelChange, write=SetOnSelChange};
};

class DELPHICLASS TcxCustomInnerTextEditHelper;
class DELPHICLASS TcxCustomInnerTextEdit;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomInnerTextEditHelper : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	TcxCustomInnerTextEdit* FEdit;
	int FSelLength;
	int FSelStart;
	
protected:
	__property TcxCustomInnerTextEdit* Edit = {read=FEdit};
	
public:
	__fastcall virtual TcxCustomInnerTextEditHelper(TcxCustomInnerTextEdit* AEdit);
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
	TcxEditEchoMode __fastcall GetEchoMode(void);
	int __fastcall GetFirstVisibleCharIndex(void);
	bool __fastcall GetHideSelection(void);
	System::WideChar __fastcall GetImeLastChar(void);
	Vcl::Controls::TImeMode __fastcall GetImeMode(void);
	Vcl::Controls::TImeName __fastcall GetImeName(void);
	bool __fastcall GetInternalUpdating(void);
	bool __fastcall GetIsInplace(void);
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
	void __fastcall SetEchoMode(TcxEditEchoMode Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetInternalUpdating(bool Value);
	void __fastcall SetImeMode(Vcl::Controls::TImeMode Value);
	void __fastcall SetImeName(const Vcl::Controls::TImeName Value);
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
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomInnerTextEditHelper(void) { }
	
private:
	void *__IcxInnerTextEdit;	/* IcxInnerTextEdit */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {263EBB8D-1EA9-4CAC-8367-ADD74D2A9651}
	operator _di_IcxInnerTextEdit()
	{
		_di_IcxInnerTextEdit intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxInnerTextEdit*(void) { return (IcxInnerTextEdit*)&__IcxInnerTextEdit; }
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
	operator Cxedit::IcxCustomInnerEdit*(void) { return (Cxedit::IcxCustomInnerEdit*)&__IcxInnerTextEdit; }
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
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxInnerTextEdit; }
	#endif
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxCustomInnerTextEditPrevState
{
public:
	bool IsPrevTextSaved;
	System::UnicodeString PrevText;
	int PrevSelLength;
	int PrevSelStart;
};


class DELPHICLASS TcxCustomTextEdit;
class PASCALIMPLEMENTATION TcxCustomInnerTextEdit : public Vcl::Stdctrls::TCustomEdit
{
	typedef Vcl::Stdctrls::TCustomEdit inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	TcxEditEchoMode FEchoMode;
	TcxCustomInnerTextEditHelper* FHelper;
	int FImeCharCount;
	System::WideChar FImeLastChar;
	bool FInternalUpdating;
	bool FIsCreating;
	int FLockBoundsCount;
	System::WideChar FPasswordChar;
	bool FUseLeftAlignmentOnEditing;
	System::Classes::TNotifyEvent FOnSelChange;
	TcxCustomTextEdit* __fastcall GetContainer(void);
	int __fastcall GetCursorPos(void);
	bool __fastcall GetIsDestroying(void);
	bool __fastcall IsDesigning(void);
	HIDESBASE void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetEchoMode(const TcxEditEchoMode Value);
	void __fastcall SetUseLeftAlignmentOnEditing(bool Value);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMReplaceSel(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall EMSetSel(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMChar(Winapi::Messages::TWMKey &Message);
	MESSAGE void __fastcall WMClear(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	MESSAGE void __fastcall WMIMEChar(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMIMEComposition(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMKeyDown(Winapi::Messages::TWMKey &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFont(Winapi::Messages::TWMSetFont &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	MESSAGE void __fastcall WMUndo(Winapi::Messages::TWMSize &Message);
	
protected:
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	Cxedit::_di_IcxCustomInnerEdit __fastcall GetHelper(void);
	DYNAMIC void __fastcall Change(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	System::Classes::TAlignment __fastcall GetBasedAlignment(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall AdjustMargins(void);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	HIDESBASE void __fastcall RecreateWnd(void);
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property TcxCustomTextEdit* Container = {read=GetContainer};
	__property int CursorPos = {read=GetCursorPos, nodefault};
	__property TcxCustomInnerTextEditHelper* Helper = {read=FHelper};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool UseLeftAlignmentOnEditing = {read=FUseLeftAlignmentOnEditing, write=SetUseLeftAlignmentOnEditing, nodefault};
	
public:
	__fastcall virtual TcxCustomInnerTextEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerTextEdit(void);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall CanFocus(void);
	virtual void __fastcall DefaultHandler(void *Message);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property AutoSelect = {default=1};
	__property CharCase = {default=0};
	__property TcxEditEchoMode EchoMode = {read=FEchoMode, write=SetEchoMode, nodefault};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property MaxLength = {default=0};
	__property OEMConvert = {default=0};
	__property ReadOnly = {default=0};
	__property OnChange;
	__property System::Classes::TNotifyEvent OnSelChange = {read=FOnSelChange, write=FOnSelChange};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerTextEdit(HWND ParentWindow) : Vcl::Stdctrls::TCustomEdit(ParentWindow) { }
	
private:
	void *__IcxInnerEditHelper;	/* Cxedit::IcxInnerEditHelper */
	void *__IcxContainerInnerControl;	/* Cxcontainer::IcxContainerInnerControl */
	
public:
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxInnerEditHelper; }
	#endif
	
};


class DELPHICLASS TcxTextEditPropertiesValues;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxTextEditPropertiesValues : public Cxedit::TcxCustomEditPropertiesValues
{
	typedef Cxedit::TcxCustomEditPropertiesValues inherited;
	
private:
	bool FDisplayFormat;
	bool FEditFormat;
	bool FMaxLength;
	bool __fastcall IsDisplayFormatStored(void);
	bool __fastcall IsEditFormatStored(void);
	void __fastcall SetDisplayFormat(bool Value);
	void __fastcall SetEditFormat(bool Value);
	void __fastcall SetMaxLength(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool DisplayFormat = {read=FDisplayFormat, write=SetDisplayFormat, stored=IsDisplayFormatStored, nodefault};
	__property bool EditFormat = {read=FEditFormat, write=SetEditFormat, stored=IsEditFormatStored, nodefault};
	__property bool MaxLength = {read=FMaxLength, write=SetMaxLength, stored=false, nodefault};
	__property MaxValue;
	__property MinValue;
public:
	/* TcxCustomEditPropertiesValues.Create */ inline __fastcall virtual TcxTextEditPropertiesValues(System::Classes::TPersistent* AOwner) : Cxedit::TcxCustomEditPropertiesValues(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTextEditPropertiesValues(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomEditListBox;
class PASCALIMPLEMENTATION TcxCustomEditListBox : public Cxcontainer::TcxCustomInnerListBox
{
	typedef Cxcontainer::TcxCustomInnerListBox inherited;
	
private:
	bool FHotTrack;
	System::Classes::TNotifyEvent FOnSelectItem;
	TcxCustomTextEdit* __fastcall GetEdit(void);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	
protected:
	DYNAMIC void __fastcall Click(void);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	virtual void __fastcall DrawItem(int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	DYNAMIC NativeInt __fastcall GetItemData(int Index);
	virtual bool __fastcall NeedDrawFocusRect(void);
	virtual void __fastcall MeasureItem(int Index, int &Height);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall SetItemData(int Index, NativeInt AData);
	virtual bool __fastcall DoDrawItem(int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall DoSelectItem(void);
	int __fastcall GetDefaultItemHeight(void);
	virtual System::UnicodeString __fastcall GetItem(int Index);
	void __fastcall InternalRecreateWindow(void);
	virtual void __fastcall RecreateWindow(void);
	void __fastcall SetItemCount(int Value);
	virtual void __fastcall SetItemIndex(const int Value)/* overload */;
	__property TcxCustomTextEdit* Edit = {read=GetEdit};
	__property bool HotTrack = {read=FHotTrack, write=FHotTrack, nodefault};
	__property System::Classes::TNotifyEvent OnSelectItem = {read=FOnSelectItem, write=FOnSelectItem};
	
public:
	__fastcall virtual TcxCustomEditListBox(System::Classes::TComponent* AOwner);
	virtual int __fastcall GetHeight(int ARowCount, int AMaxHeight);
	HIDESBASE virtual int __fastcall GetItemHeight(int AIndex = 0xffffffff);
	virtual int __fastcall GetItemWidth(int AIndex);
	bool __fastcall IsVisible(void);
	HIDESBASE void __fastcall SetScrollWidth(int Value);
public:
	/* TcxCustomInnerListBox.Destroy */ inline __fastcall virtual ~TcxCustomEditListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomEditListBox(HWND ParentWindow) : Cxcontainer::TcxCustomInnerListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxCustomEditListBoxClass;

enum TcxEditLookupDataGoDirection : unsigned char { egdBegin, egdEnd, egdNext, egdPrev, egdPageUp, egdPageDown };

__interface IcxTextEditLookupData;
typedef System::DelphiInterface<IcxTextEditLookupData> _di_IcxTextEditLookupData;
__interface  INTERFACE_UUID("{F49C5F08-7758-4362-A360-1DF02354E708}") IcxTextEditLookupData  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanResizeVisualArea(System::Types::TSize &NewSize, int AMaxHeight = 0x0, int AMaxWidth = 0x0) = 0 ;
	virtual void __fastcall CloseUp(void) = 0 ;
	virtual void __fastcall Deinitialize(void) = 0 ;
	virtual void __fastcall DropDown(void) = 0 ;
	virtual void __fastcall DroppedDown(const System::UnicodeString AFindStr) = 0 ;
	virtual bool __fastcall Find(const System::UnicodeString AText) = 0 ;
	virtual Vcl::Controls::TControl* __fastcall GetActiveControl(void) = 0 ;
	virtual System::Variant __fastcall GetCurrentKey(void) = 0 ;
	virtual System::UnicodeString __fastcall GetDisplayText(const System::Variant &AKey) = 0 /* overload */;
	virtual System::Classes::TNotifyEvent __fastcall GetOnCurrentKeyChanged(void) = 0 ;
	virtual System::Classes::TNotifyEvent __fastcall GetOnSelectItem(void) = 0 ;
	virtual int __fastcall GetSelectedItem(void) = 0 ;
	virtual System::Types::TSize __fastcall GetVisualAreaPreferredSize(int AMaxHeight, int AWidth = 0x0) = 0 ;
	virtual void __fastcall Go(TcxEditLookupDataGoDirection ADirection, bool ACircular) = 0 ;
	virtual void __fastcall Initialize(Vcl::Controls::TWinControl* AVisualControlsParent) = 0 ;
	virtual bool __fastcall IsEmpty(void) = 0 ;
	virtual bool __fastcall IsMouseOverList(const System::Types::TPoint &P) = 0 ;
	virtual bool __fastcall Locate(System::UnicodeString &AText, System::UnicodeString &ATail, bool ANext) = 0 ;
	virtual void __fastcall PositionVisualArea(const System::Types::TRect &AClientRect) = 0 ;
	virtual void __fastcall PropertiesChanged(void) = 0 ;
	virtual void __fastcall SelectItem(void) = 0 ;
	virtual void __fastcall SetCurrentKey(const System::Variant &AKey) = 0 ;
	virtual void __fastcall SetOnCurrentKeyChanged(System::Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetOnSelectItem(System::Classes::TNotifyEvent Value) = 0 ;
	virtual void __fastcall SetSelectedItem(int Value) = 0 ;
	virtual void __fastcall TextChanged(void) = 0 ;
	__property Vcl::Controls::TControl* ActiveControl = {read=GetActiveControl};
	__property System::Variant CurrentKey = {read=GetCurrentKey, write=SetCurrentKey};
	__property int SelectedItem = {read=GetSelectedItem, write=SetSelectedItem};
	__property System::Classes::TNotifyEvent OnCurrentKeyChanged = {read=GetOnCurrentKeyChanged, write=SetOnCurrentKeyChanged};
	__property System::Classes::TNotifyEvent OnSelectItem = {read=GetOnSelectItem, write=SetOnSelectItem};
};

class DELPHICLASS TcxCustomTextEditLookupData;
class DELPHICLASS TcxCustomTextEditProperties;
class PASCALIMPLEMENTATION TcxCustomTextEditLookupData : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	int FCurrentKey;
	int FItemIndex;
	TcxCustomEditListBox* FList;
	System::Classes::TPersistent* FOwner;
	System::Classes::TNotifyEvent FOnCurrentKeyChanged;
	System::Classes::TNotifyEvent FOnSelectItem;
	TcxCustomTextEdit* __fastcall GetEdit(void);
	System::Classes::TStrings* __fastcall GetItems(void);
	TcxCustomTextEditProperties* __fastcall GetActiveProperties(void);
	int __fastcall IndexOf(const System::UnicodeString AText);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetItems(System::Classes::TStrings* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall DoCurrentKeyChanged(void);
	void __fastcall DoSelectItem(void);
	virtual System::UnicodeString __fastcall GetItem(int Index);
	virtual int __fastcall GetItemCount(void);
	virtual TcxCustomEditListBoxClass __fastcall GetListBoxClass(void);
	virtual int __fastcall GetSelectedItem(void);
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	virtual bool __fastcall InternalLocate(System::UnicodeString &AText, System::UnicodeString &ATail, bool ANext, bool ASynchronizeWithText);
	void __fastcall InternalSetItemIndex(int Value);
	virtual void __fastcall ListChanged(void);
	virtual void __fastcall SetSelectedItem(int Value);
	__property TcxCustomTextEdit* Edit = {read=GetEdit};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, stored=false, nodefault};
	__property System::Classes::TStrings* Items = {read=GetItems, write=SetItems};
	__property TcxCustomEditListBox* List = {read=FList};
	__property TcxCustomTextEditProperties* ActiveProperties = {read=GetActiveProperties};
	
public:
	__fastcall virtual TcxCustomTextEditLookupData(System::Classes::TPersistent* AOwner);
	virtual bool __fastcall CanResizeVisualArea(System::Types::TSize &NewSize, int AMaxHeight = 0x0, int AMaxWidth = 0x0);
	void __fastcall CloseUp(void);
	void __fastcall Deinitialize(void);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall DroppedDown(const System::UnicodeString AFindStr);
	virtual bool __fastcall Find(const System::UnicodeString AText);
	Vcl::Controls::TControl* __fastcall GetActiveControl(void);
	System::Variant __fastcall GetCurrentKey(void);
	System::UnicodeString __fastcall GetDisplayText(const System::Variant &AKey)/* overload */;
	System::Classes::TNotifyEvent __fastcall GetOnCurrentKeyChanged(void);
	System::Classes::TNotifyEvent __fastcall GetOnSelectItem(void);
	virtual System::Types::TSize __fastcall GetVisualAreaPreferredSize(int AMaxHeight, int AWidth = 0x0);
	void __fastcall Go(TcxEditLookupDataGoDirection ADirection, bool ACircular);
	virtual void __fastcall Initialize(Vcl::Controls::TWinControl* AVisualControlsParent);
	void __fastcall InternalSetCurrentKey(int Value);
	bool __fastcall IsEmpty(void);
	bool __fastcall IsMouseOverList(const System::Types::TPoint &P);
	bool __fastcall Locate(System::UnicodeString &AText, System::UnicodeString &ATail, bool ANext);
	virtual void __fastcall PositionVisualArea(const System::Types::TRect &AClientRect);
	virtual void __fastcall PropertiesChanged(void);
	void __fastcall SelectItem(void);
	void __fastcall SetCurrentKey(const System::Variant &AKey);
	void __fastcall SetOnCurrentKeyChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnSelectItem(System::Classes::TNotifyEvent Value);
	virtual void __fastcall TextChanged(void);
	__property Vcl::Controls::TControl* ActiveControl = {read=GetActiveControl};
	__property System::Variant CurrentKey = {read=GetCurrentKey, write=SetCurrentKey};
	__property System::Classes::TNotifyEvent OnCurrentKeyChanged = {read=GetOnCurrentKeyChanged, write=SetOnCurrentKeyChanged};
	__property System::Classes::TNotifyEvent OnSelectItem = {read=GetOnSelectItem, write=SetOnSelectItem};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomTextEditLookupData(void) { }
	
private:
	void *__IcxTextEditLookupData;	/* IcxTextEditLookupData */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F49C5F08-7758-4362-A360-1DF02354E708}
	operator _di_IcxTextEditLookupData()
	{
		_di_IcxTextEditLookupData intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxTextEditLookupData*(void) { return (IcxTextEditLookupData*)&__IcxTextEditLookupData; }
	#endif
	
};


class DELPHICLASS TcxCustomTextEditViewData;
class PASCALIMPLEMENTATION TcxCustomTextEditViewData : public Cxedit::TcxCustomEditViewData
{
	typedef Cxedit::TcxCustomEditViewData inherited;
	
private:
	bool FIsValueFormatted;
	TcxCustomTextEditProperties* __fastcall GetProperties(void);
	System::Uitypes::TColor __fastcall InvertColor(System::Uitypes::TColor AColor);
	
protected:
	virtual void __fastcall CalculateButtonNativePartInfo(NativeUInt ATheme, Cxedit::TcxEditButtonViewInfo* AButtonViewInfo);
	virtual void __fastcall InitCacheData(void);
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	virtual System::Types::TSize __fastcall InternalGetEditContentSize(Cxgraphics::TcxCanvas* ACanvas, const System::Variant &AEditValue, const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	virtual bool __fastcall GetIsEditClass(void);
	virtual int __fastcall GetMaxLineCount(void);
	virtual bool __fastcall IsComboBoxStyle(void);
	virtual void __fastcall PrepareDrawTextFlags(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual System::Types::TRect __fastcall GetClientExtent(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall DisplayValueToDrawValue(const System::Variant &ADisplayValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual unsigned __fastcall GetDrawTextFlags(void);
	virtual System::Types::TRect __fastcall GetDrawTextOffset(void);
	void __fastcall PrepareSelection(Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TcxCustomTextEditProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxCustomTextEditViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxedit::TcxCustomEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomTextEditViewData(void) { }
	
};


struct DECLSPEC_DRECORD TcxTextOutData
{
public:
	bool ForceEndEllipsis;
	bool Initialized;
	int RowCount;
	int SelStart;
	int SelLength;
	System::Uitypes::TColor SelBackgroundColor;
	System::Uitypes::TColor SelTextColor;
	Cxdrawtextutils::TcxTextParams TextParams;
	System::Types::TRect TextRect;
	Cxdrawtextutils::TcxTextRows TextRows;
};


class DELPHICLASS TcxCustomTextEditViewInfo;
class PASCALIMPLEMENTATION TcxCustomTextEditViewInfo : public Cxedit::TcxCustomEditViewInfo
{
	typedef Cxedit::TcxCustomEditViewInfo inherited;
	
protected:
	virtual Cxedit::TcxEditBackgroundPaintingStyle __fastcall GetBackgroundPaintingStyle(void);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	bool ComboBoxStyle;
	TcxTextEditCustomDrawHandler CustomDrawHandler;
	bool DrawSelectionBar;
	unsigned DrawTextFlags;
	Cxedit::TcxEditEditingStyle EditingStyle;
	bool HasPopupWindow;
	bool IsEditClass;
	bool IsOwnerDrawing;
	int MaxLineCount;
	int SelStart;
	int SelLength;
	System::Uitypes::TColor SelTextColor;
	System::Uitypes::TColor SelBackgroundColor;
	System::UnicodeString Text;
	TcxTextOutData TextOutData;
	System::Types::TRect TextRect;
	__fastcall virtual ~TcxCustomTextEditViewInfo(void);
	virtual bool __fastcall NeedShowHint(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint &P, const System::Types::TRect &AVisibleBounds, /* out */ Vcl::Controls::TCaption &AText, /* out */ bool &AIsMultiLine, /* out */ System::Types::TRect &ATextRect, int AMaxLineCount = 0x0);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall DrawText(Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetTextBaseLine(void);
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxCustomTextEditViewInfo(void) : Cxedit::TcxCustomEditViewInfo() { }
	
};


typedef void __fastcall (__closure *TcxNewLookupDisplayTextEvent)(System::TObject* Sender, const Vcl::Controls::TCaption AText);

typedef System::Set<char, 0, 255>  TcxTextEditChars;

class PASCALIMPLEMENTATION TcxCustomTextEditProperties : public Cxedit::TcxCustomEditProperties
{
	typedef Cxedit::TcxCustomEditProperties inherited;
	
private:
	System::Uitypes::TEditCharCase FCharCase;
	System::UnicodeString FDisplayFormat;
	TcxEditEchoMode FEchoMode;
	System::UnicodeString FEditFormat;
	bool FFixedListSelection;
	bool FFormatChanging;
	bool FHideCursor;
	bool FHideSelection;
	Vcl::Controls::TImeMode FImeMode;
	Vcl::Controls::TImeName FImeName;
	bool FImmediateUpdateText;
	bool FIncrementalSearch;
	System::Classes::TStringList* FLookupItems;
	int FMaxLength;
	bool FMRUMode;
	System::UnicodeString FNullstring;
	bool FOEMConvert;
	System::WideChar FPasswordChar;
	bool FUseDisplayFormatWhenEditing;
	bool FUseNullString;
	TcxTextEditChars FValidChars;
	TcxNewLookupDisplayTextEvent FOnNewLookupDisplayText;
	TcxTextEditPropertiesValues* __fastcall GetAssignedValues(void);
	System::UnicodeString __fastcall GetDisplayFormat(void);
	System::UnicodeString __fastcall GetEditFormat(void);
	int __fastcall GetInnerEditMaxLength(void);
	System::Classes::TStrings* __fastcall GetLookupItems(void);
	bool __fastcall GetLookupItemsSorted(void);
	int __fastcall GetMaxLength(void);
	TcxTextEditViewStyle __fastcall GetViewStyle(void);
	bool __fastcall IsDisplayFormatStored(void);
	bool __fastcall IsEditFormatStored(void);
	bool __fastcall IsMaxLengthStored(void);
	void __fastcall LookupItemsChanged(System::TObject* Sender);
	void __fastcall ReadIsDisplayFormatAssigned(System::Classes::TReader* Reader);
	HIDESBASE void __fastcall SetAssignedValues(TcxTextEditPropertiesValues* Value);
	void __fastcall SetDisplayFormat(const System::UnicodeString Value);
	void __fastcall SetEchoMode(TcxEditEchoMode Value);
	void __fastcall SetEditFormat(const System::UnicodeString Value);
	void __fastcall SetFixedListSelection(bool Value);
	void __fastcall SetHideCursor(bool Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetImeMode(Vcl::Controls::TImeMode Value);
	void __fastcall SetImeName(const Vcl::Controls::TImeName Value);
	void __fastcall SetIncrementalSearch(bool Value);
	void __fastcall SetLookupItems(System::Classes::TStrings* Value);
	void __fastcall SetLookupItemsSorted(bool Value);
	void __fastcall SetMaxLength(int Value);
	void __fastcall SetMRUMode(bool Value);
	void __fastcall SetNullstring(const System::UnicodeString Value);
	void __fastcall SetOEMConvert(bool Value);
	void __fastcall SetPasswordChar(System::WideChar Value);
	void __fastcall SetUseDisplayFormatWhenEditing(bool Value);
	void __fastcall SetUseNullString(const bool Value);
	void __fastcall SetViewStyle(TcxTextEditViewStyle Value);
	
protected:
	virtual void __fastcall AlignmentChangedHandler(System::TObject* Sender);
	virtual void __fastcall BaseSetAlignment(Cxedit::TcxEditAlignment* Value);
	virtual bool __fastcall CanValidate(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	virtual System::UnicodeString __fastcall GetValidateErrorText(int AErrorKind);
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	virtual bool __fastcall HasDisplayValue(void);
	virtual void __fastcall FormatChanged(void);
	bool __fastcall CanIncrementalSearch(void);
	virtual void __fastcall CheckEditValueBounds(const System::Variant &AEditValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	virtual void __fastcall CheckDisplayValueBounds(const System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	virtual System::Variant __fastcall DefaultFocusedDisplayValue(void);
	virtual void __fastcall DoPrepareDisplayValue(const System::Variant &AEditValue, System::Variant &ADisplayValue, bool AEditFocused);
	virtual bool __fastcall FindLookupText(const System::UnicodeString AText);
	virtual System::UnicodeString __fastcall GetDefaultDisplayFormat(void);
	System::Variant __fastcall GetDefaultDisplayValue(const System::Variant &AEditValue, bool AEditFocused);
	virtual int __fastcall GetDefaultMaxLength(void);
	virtual Cxedit::TcxEditVertAlignment __fastcall GetDefaultVertAlignment(void);
	virtual int __fastcall GetDropDownPageRowCount(void);
	virtual Cxedit::TcxEditEditingStyle __fastcall GetEditingStyle(void);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	virtual bool __fastcall HasDigitGrouping(bool AIsDisplayValueSynchronizing);
	virtual System::UnicodeString __fastcall InternalGetEditFormat(/* out */ bool &AIsCurrency, /* out */ bool &AIsOnGetTextAssigned, TcxCustomTextEdit* AEdit = (TcxCustomTextEdit*)(0x0));
	virtual void __fastcall LookupDataChanged(System::TObject* Sender);
	virtual void __fastcall MaxLengthChanged(void);
	virtual void __fastcall SetCharCase(System::Uitypes::TEditCharCase Value);
	virtual bool __fastcall UseLookupData(void);
	virtual bool __fastcall IsEditValueEmpty(const System::Variant &AEditValue);
	virtual bool __fastcall IsEditValueNumeric(void);
	virtual bool __fastcall IsLookupDataVisual(void);
	virtual bool __fastcall IsMultiLine(void);
	virtual bool __fastcall IsPopupKey(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall IsValueBoundDefined(TcxEditValueBound ABound);
	virtual bool __fastcall IsValueBoundsDefined(void);
	__property TcxTextEditPropertiesValues* AssignedValues = {read=GetAssignedValues, write=SetAssignedValues};
	__property Cxedit::TcxEditEditingStyle EditingStyle = {read=GetEditingStyle, nodefault};
	__property bool FixedListSelection = {read=FFixedListSelection, write=SetFixedListSelection, default=1};
	__property bool FormatChanging = {read=FFormatChanging, nodefault};
	__property bool HideCursor = {read=FHideCursor, write=SetHideCursor, stored=false, nodefault};
	__property bool MRUMode = {read=FMRUMode, write=SetMRUMode, default=0};
	__property System::UnicodeString Nullstring = {read=FNullstring, write=SetNullstring};
	__property bool UseNullString = {read=FUseNullString, write=SetUseNullString, default=0};
	
public:
	__fastcall virtual TcxCustomTextEditProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomTextEditProperties(void);
	virtual bool __fastcall CanCompareEditValue(void);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual Cxedit::TcxEditSupportedOperations __fastcall GetSupportedOperations(void);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual bool __fastcall IsResetEditClass(void);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall ValidateDisplayValue(System::Variant &DisplayValue, Vcl::Controls::TCaption &ErrorText, bool &Error, Cxedit::TcxCustomEdit* AEdit);
	virtual void __fastcall DisplayValueToDisplayText(System::UnicodeString &ADisplayValue);
	virtual bool __fastcall IsDisplayValueValid(System::Variant &DisplayValue, bool AEditFocused);
	void __fastcall SetMinMaxValues(double AMinValue, double AMaxValue);
	__property TcxTextEditChars ValidChars = {read=FValidChars, write=FValidChars};
	__property System::Uitypes::TEditCharCase CharCase = {read=FCharCase, write=SetCharCase, default=0};
	__property System::UnicodeString DisplayFormat = {read=GetDisplayFormat, write=SetDisplayFormat, stored=IsDisplayFormatStored};
	__property TcxEditEchoMode EchoMode = {read=FEchoMode, write=SetEchoMode, default=0};
	__property System::UnicodeString EditFormat = {read=GetEditFormat, write=SetEditFormat, stored=IsEditFormatStored};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=1};
	__property Vcl::Controls::TImeMode ImeMode = {read=FImeMode, write=SetImeMode, default=3};
	__property Vcl::Controls::TImeName ImeName = {read=FImeName, write=SetImeName};
	__property bool ImmediateUpdateText = {read=FImmediateUpdateText, write=FImmediateUpdateText, default=0};
	__property bool IncrementalSearch = {read=FIncrementalSearch, write=SetIncrementalSearch, default=1};
	__property System::Classes::TStrings* LookupItems = {read=GetLookupItems, write=SetLookupItems};
	__property bool LookupItemsSorted = {read=GetLookupItemsSorted, write=SetLookupItemsSorted, default=0};
	__property int MaxLength = {read=GetMaxLength, write=SetMaxLength, stored=IsMaxLengthStored, nodefault};
	__property MaxValue = {default=0};
	__property MinValue = {default=0};
	__property bool OEMConvert = {read=FOEMConvert, write=SetOEMConvert, default=0};
	__property System::WideChar PasswordChar = {read=FPasswordChar, write=SetPasswordChar, default=0};
	__property bool UseDisplayFormatWhenEditing = {read=FUseDisplayFormatWhenEditing, write=SetUseDisplayFormatWhenEditing, default=0};
	__property TcxTextEditViewStyle ViewStyle = {read=GetViewStyle, write=SetViewStyle, default=0};
	__property TcxNewLookupDisplayTextEvent OnNewLookupDisplayText = {read=FOnNewLookupDisplayText, write=FOnNewLookupDisplayText};
private:
	void *__IcxFormatControllerListener;	/* Cxformats::IcxFormatControllerListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A7F2F6D3-1A7D-4295-A6E6-9297BD83D0DE}
	operator Cxformats::_di_IcxFormatControllerListener()
	{
		Cxformats::_di_IcxFormatControllerListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener*(void) { return (Cxformats::IcxFormatControllerListener*)&__IcxFormatControllerListener; }
	#endif
	
};


class DELPHICLASS TcxTextEditProperties;
class PASCALIMPLEMENTATION TcxTextEditProperties : public TcxCustomTextEditProperties
{
	typedef TcxCustomTextEditProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property BeepOnError = {default=0};
	__property CharCase = {default=0};
	__property ClearKey = {default=0};
	__property EchoMode = {default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property IncrementalSearch = {default=1};
	__property LookupItems;
	__property LookupItemsSorted = {default=0};
	__property MaxLength;
	__property Nullstring = {default=0};
	__property OEMConvert = {default=0};
	__property PasswordChar = {default=0};
	__property ReadOnly;
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property ValidateOnEnter = {default=0};
	__property ValidationOptions = {default=1};
	__property OnChange;
	__property OnEditValueChanged;
	__property OnNewLookupDisplayText;
	__property OnValidate;
public:
	/* TcxCustomTextEditProperties.Create */ inline __fastcall virtual TcxTextEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomTextEditProperties(AOwner) { }
	/* TcxCustomTextEditProperties.Destroy */ inline __fastcall virtual ~TcxTextEditProperties(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomTextEdit : public Cxedit::TcxCustomEdit
{
	typedef Cxedit::TcxCustomEdit inherited;
	
private:
	bool FBeepOnEnter;
	bool FDisableRefresh;
	bool FFindSelection;
	bool FInternalTextSetting;
	bool FIsDisplayValueSynchronizing;
	int FLastFirstVisibleCharIndex;
	int FLastSelLength;
	int FLastSelPosition;
	bool FLookupItemsScrolling;
	Vcl::Controls::TCaption FText;
	int __fastcall GetCursorPos(void);
	Vcl::Controls::TCaption __fastcall GetEditingText(void);
	_di_IcxInnerTextEdit __fastcall GetInnerTextEdit(void);
	_di_IcxTextEditLookupData __fastcall GetILookupData(void);
	TcxCustomTextEditLookupData* __fastcall GetLookupData(void);
	TcxCustomTextEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomTextEditProperties* __fastcall GetActiveProperties(void);
	int __fastcall GetSelLength(void);
	int __fastcall GetSelStart(void);
	Vcl::Controls::TCaption __fastcall GetSelText(void);
	HIDESBASE TcxCustomTextEditViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetFindSelection(bool Value);
	void __fastcall SetItemObject(System::TObject* Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomTextEditProperties* Value);
	void __fastcall SetSelLength(int Value);
	void __fastcall SetSelStart(int Value);
	System::UnicodeString __fastcall GetTextHint(void);
	void __fastcall SetTextHint(System::UnicodeString Value);
	MESSAGE void __fastcall WMClear(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMCommand(Winapi::Messages::TWMCommand &Message);
	MESSAGE void __fastcall WMGetText(Winapi::Messages::TWMGetText &Message);
	MESSAGE void __fastcall WMGetTextLength(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMSetText(Winapi::Messages::TWMSetText &Message);
	
protected:
	bool FInnerEditPositionAdjusting;
	bool FIsPopupWindowJustClosed;
	Dxcoreclasses::TcxInterfacedPersistent* FLookupData;
	bool FLookupDataTextChangedLocked;
	bool FIsChangeBySpellChecker;
	DYNAMIC void __fastcall DoExit(void);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall AdjustInnerEditPosition(void);
	virtual bool __fastcall CanKeyDownModifyEdit(System::Word Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall CanKeyPressModifyEdit(System::WideChar Key);
	virtual void __fastcall ChangeHandler(System::TObject* Sender);
	virtual void __fastcall ContainerStyleChanged(System::TObject* Sender);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyPress(System::WideChar &Key);
	virtual void __fastcall DoEditValueChanged(void);
	virtual void __fastcall DoFocusChanged(void);
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	virtual void __fastcall DoSetFocusWhenActivate(void);
	virtual void __fastcall DoValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError);
	virtual void __fastcall PopulateSizeProperties(Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	virtual System::UnicodeString __fastcall GetDisplayValue(void);
	virtual Cxcontainer::TcxContainerInnerControlBounds __fastcall GetInnerControlBounds(const System::Types::TRect &AInnerControlsRegion, Vcl::Controls::TControl* AInnerControl);
	virtual Vcl::Controls::TControlClass __fastcall GetInnerEditClass(void);
	virtual void __fastcall Initialize(void);
	virtual bool __fastcall InternalDoEditing(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	virtual void __fastcall InternalSetDisplayValue(const System::Variant &Value);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	virtual bool __fastcall IsTextInputMode(void);
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual bool __fastcall SetDisplayText(const System::UnicodeString Value);
	virtual void __fastcall SetInternalDisplayValue(const System::Variant &Value);
	virtual bool __fastcall WantNavigationKeys(void);
	virtual void __fastcall LockedInnerEditWindowProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall UnlockInnerEditRepainting(void);
	virtual void __fastcall FormatChanged(void);
	virtual bool __fastcall CanSpellCheckerPostEditValue(void);
	virtual void __fastcall DoDrawMisspellings(void);
	virtual void __fastcall DoLayoutChanged(void);
	virtual void __fastcall DoSelectionChanged(void);
	virtual void __fastcall DoSpellCheckerPostEditValue(void);
	virtual void __fastcall DoTextChanged(void);
	void __fastcall InternalCheckSelection(void);
	virtual void __fastcall InternalSpellCheckerHandler(Winapi::Messages::TMessage &Message);
	void __fastcall RedrawMisspelledWords(void);
	void __fastcall SpellCheckerPostEditValue(void);
	virtual void __fastcall SpellCheckerSetSelText(const System::UnicodeString AValue, bool APost = false);
	virtual void __fastcall AdjustInnerEdit(void);
	virtual bool __fastcall CanChangeSelText(const System::UnicodeString Value, /* out */ System::UnicodeString &ANewText, /* out */ int &ANewSelStart);
	virtual bool __fastcall CanSelectItem(bool AFindSelection);
	virtual void __fastcall CheckEditValue(void);
	virtual void __fastcall CheckEditorValueBounds(void);
	virtual void __fastcall DoOnNewLookupDisplayText(const System::UnicodeString AText);
	virtual int __fastcall GetInnerEditHeight(void);
	virtual int __fastcall GetItemIndex(void);
	virtual System::TObject* __fastcall GetItemObject(void);
	virtual bool __fastcall GetScrollLookupDataList(TcxEditScrollCause AScrollCause);
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	virtual System::UnicodeString __fastcall InternalGetText(void);
	virtual bool __fastcall InternalSetText(const System::UnicodeString Value);
	virtual System::Variant __fastcall ItemIndexToLookupKey(int AItemIndex);
	void __fastcall LockLookupDataTextChanged(void);
	virtual System::Variant __fastcall LookupKeyToEditValue(const System::Variant &AKey);
	virtual int __fastcall LookupKeyToItemIndex(const System::Variant &AKey);
	virtual bool __fastcall NeedResetInvalidTextWhenPropertiesChanged(void);
	virtual void __fastcall ResetOnNewDisplayValue(void);
	virtual void __fastcall SelChange(System::TObject* Sender);
	virtual void __fastcall SetEditingText(const Vcl::Controls::TCaption Value);
	virtual void __fastcall SetItemIndex(int Value);
	virtual void __fastcall SetSelText(const Vcl::Controls::TCaption Value);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall SynchronizeEditValue(void);
	virtual void __fastcall UndoPerformed(void);
	void __fastcall UnlockLookupDataTextChanged(void);
	virtual void __fastcall UpdateDrawValue(void);
	virtual void __fastcall UpdateDisplayValue(void);
	__property bool BeepOnEnter = {read=FBeepOnEnter, write=FBeepOnEnter, default=1};
	__property _di_IcxInnerTextEdit InnerTextEdit = {read=GetInnerTextEdit};
	__property int ItemIndex = {read=GetItemIndex, write=SetItemIndex, stored=false, nodefault};
	__property System::TObject* ItemObject = {read=GetItemObject, write=SetItemObject};
	__property TcxCustomTextEditLookupData* LookupData = {read=GetLookupData};
	__property bool LookupItemsScrolling = {read=FLookupItemsScrolling, write=FLookupItemsScrolling, nodefault};
	__property ParentColor = {default=0};
	__property TcxCustomTextEditViewInfo* ViewInfo = {read=GetViewInfo};
	__property System::UnicodeString TextHint = {read=GetTextHint, write=SetTextHint};
	
public:
	__fastcall virtual TcxCustomTextEdit(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TcxCustomTextEdit(void);
	virtual void __fastcall DefaultHandler(void *Message);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall CopyToClipboard(void);
	virtual void __fastcall CutToClipboard(void);
	virtual bool __fastcall IsEditClass(void);
	virtual void __fastcall PasteFromClipboard(void);
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	virtual void __fastcall SelectAll(void);
	virtual int __fastcall GetTextBaseLine(void);
	virtual bool __fastcall HasTextBaseLine(void);
	virtual void __fastcall ClearSelection(void);
	virtual bool __fastcall DoInnerControlDefaultHandler(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall IsChildWindow(NativeUInt AWnd);
	virtual void __fastcall SetScrollBarsParameters(bool AIsScrolling = false);
	void __fastcall SetSelection(int ASelStart, int ASelLength);
	virtual void __fastcall Undo(void);
	__property TcxCustomTextEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property int CursorPos = {read=GetCursorPos, nodefault};
	__property Vcl::Controls::TCaption EditingText = {read=GetEditingText, write=SetEditingText};
	__property bool FindSelection = {read=FFindSelection, write=SetFindSelection, nodefault};
	__property _di_IcxTextEditLookupData ILookupData = {read=GetILookupData};
	__property TcxCustomTextEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property int SelLength = {read=GetSelLength, write=SetSelLength, nodefault};
	__property int SelStart = {read=GetSelStart, write=SetSelStart, nodefault};
	__property Vcl::Controls::TCaption SelText = {read=GetSelText, write=SetSelText};
	__property Text = {default=0};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomTextEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxedit::TcxCustomEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomTextEdit(HWND ParentWindow) : Cxedit::TcxCustomEdit(ParentWindow) { }
	
private:
	void *__IcxFormatControllerListener;	/* Cxformats::IcxFormatControllerListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A7F2F6D3-1A7D-4295-A6E6-9297BD83D0DE}
	operator Cxformats::_di_IcxFormatControllerListener()
	{
		Cxformats::_di_IcxFormatControllerListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener*(void) { return (Cxformats::IcxFormatControllerListener*)&__IcxFormatControllerListener; }
	#endif
	
};


class DELPHICLASS TcxTextEdit;
class PASCALIMPLEMENTATION TcxTextEdit : public TcxCustomTextEdit
{
	typedef TcxCustomTextEdit inherited;
	
private:
	HIDESBASE TcxTextEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxTextEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxTextEditProperties* Value);
	
protected:
	virtual bool __fastcall SupportsSpelling(void);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxTextEditProperties* ActiveProperties = {read=GetActiveProperties};
	
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
	__property TcxTextEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxTextEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomTextEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxTextEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxTextEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomTextEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTextEdit(HWND ParentWindow) : TcxCustomTextEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterTextEditHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFilterTextEditHelper : public Cxfiltercontrolutils::TcxCustomFilterEditHelper
{
	typedef Cxfiltercontrolutils::TcxCustomFilterEditHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
	__classmethod virtual void __fastcall SetFilterValue(Cxedit::TcxCustomEdit* AEdit, Cxedit::TcxCustomEditProperties* AEditProperties, const System::Variant &AValue);
public:
	/* TObject.Create */ inline __fastcall TcxFilterTextEditHelper(void) : Cxfiltercontrolutils::TcxCustomFilterEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterTextEditHelper(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxEditDefaultDropDownPageRowCount = System::Int8(0x8);
static const System::Int8 ekValueOutOfBounds = System::Int8(0x1);
extern PACKAGE Cxedit::TcxEditVertAlignment cxTextEditDefaultVertAlignment;
extern PACKAGE void __fastcall CheckCharsRegister(System::UnicodeString &AText, System::Uitypes::TEditCharCase ACharCase);
extern PACKAGE bool __fastcall CheckTextEditState(_di_IcxInnerTextEdit ATextEdit, const TcxCustomInnerTextEditPrevState &APrevState);
extern PACKAGE void __fastcall DrawEditText(Cxgraphics::TcxCanvas* ACanvas, TcxCustomTextEditViewInfo* AViewInfo);
extern PACKAGE void __fastcall DrawTextEdit(Cxgraphics::TcxCanvas* ACanvas, TcxCustomTextEditViewInfo* AViewInfo);
extern PACKAGE System::Types::TSize __fastcall GetTextEditContentSize(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewData* AViewData, const System::UnicodeString AText, unsigned ADrawTextFlags, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, int ALineCount = 0x0, bool ACorrectWidth = true);
extern PACKAGE System::Types::TRect __fastcall GetTextEditDrawTextOffset(Cxedit::TcxCustomEditViewData* AViewData)/* overload */;
extern PACKAGE System::Types::TRect __fastcall GetTextEditDrawTextOffset(System::Classes::TAlignment AAlignment, bool AIsInplace)/* overload */;
extern PACKAGE void __fastcall InternalTextOut(Vcl::Graphics::TCanvas* ACanvas, TcxCustomTextEditViewInfo* AViewInfo, System::WideChar * AText, System::Types::TRect &R, unsigned AFormat, int ASelStart, int ASelLength, System::Uitypes::TColor ASelBackgroundColor, System::Uitypes::TColor ASelTextColor, int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0);
extern PACKAGE void __fastcall InsertThousandSeparator(System::UnicodeString &S);
extern PACKAGE System::UnicodeString __fastcall RemoveExponentialPart(System::UnicodeString &S);
extern PACKAGE void __fastcall RemoveThousandSeparator(System::UnicodeString &S);
extern PACKAGE void __fastcall SaveTextEditState(_di_IcxInnerTextEdit ATextEdit, bool ASaveText, TcxCustomInnerTextEditPrevState &APrevState);
extern PACKAGE void __fastcall SeparateDigitGroups(TcxCustomTextEdit* AEdit);
}	/* namespace Cxtextedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTEXTEDIT)
using namespace Cxtextedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtexteditHPP
