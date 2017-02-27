// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarExtDBItems.pas' rev: 24.00 (Win32)

#ifndef DxbarextdbitemsHPP
#define DxbarextdbitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Generics.Collections.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCommon.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <System.Generics.Defaults.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarextdbitems
{
//-- type declarations -------------------------------------------------------
typedef System::Generics::Collections::TList__1<Data::Db::TField*>* TdxBarDBFieldList;

class DELPHICLASS TdxBarLookupLink;
class DELPHICLASS TdxBarLookupCombo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarLookupLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	TdxBarLookupCombo* FBarLookupCombo;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall LayoutChanged(void);
public:
	/* TDataLink.Create */ inline __fastcall TdxBarLookupLink(void) : Data::Db::TDataLink() { }
	/* TDataLink.Destroy */ inline __fastcall virtual ~TdxBarLookupLink(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarPopupLookupControl;
class PASCALIMPLEMENTATION TdxBarLookupCombo : public Dxbar::TCustomdxBarCombo
{
	typedef Dxbar::TCustomdxBarCombo inherited;
	
private:
	bool FAllowResizing;
	System::Variant FCurKeyValue;
	TdxBarLookupLink* FListLink;
	TdxBarPopupLookupControl* FPopupList;
	System::UnicodeString FKeyFieldName;
	System::UnicodeString FListFieldName;
	int FListFieldIndex;
	Data::Db::TField* FKeyField;
	Data::Db::TField* FListField;
	System::Generics::Collections::TList__1<Data::Db::TField*>* FListFields;
	System::Variant FKeyValue;
	bool FSetValue;
	bool FListActive;
	System::Uitypes::TColor FColor;
	bool FImmediateDropDown;
	int FPopupWidth;
	int FRowCount;
	bool FListVisible;
	bool FFindSelection;
	System::UnicodeString FFindStr;
	bool FInFindSelection;
	Vcl::Stdctrls::TEdit* FLocateEdit;
	TdxBarPopupLookupControl* FLocateList;
	System::Classes::TNotifyEvent FOnKeyValueChange;
	Vcl::Forms::TForm* FForm;
	Vcl::Stdctrls::TButton* ButtonOk;
	Vcl::Stdctrls::TButton* ButtonCancel;
	Data::Db::TDataSource* __fastcall GetListSource(void);
	void __fastcall SetKeyFieldName(const System::UnicodeString Value);
	void __fastcall SetKeyValue(const System::Variant &Value);
	void __fastcall SetListFieldIndex(int Value);
	void __fastcall SetListFieldName(const System::UnicodeString Value);
	void __fastcall SetListSource(Data::Db::TDataSource* Value);
	void __fastcall SetRowCount(int Value);
	int __fastcall GetEditHandle(void);
	System::UnicodeString __fastcall GetEditText(void);
	void __fastcall SetEditText(System::UnicodeString AText);
	void __fastcall DoKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall DoKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall FormSize(System::TObject* Sender);
	
protected:
	DYNAMIC void __fastcall CloseUp(void);
	DYNAMIC void __fastcall DoEnter(void);
	DYNAMIC void __fastcall DropDown(int X, int Y);
	virtual HWND __fastcall GetDropDownWindow(void);
	virtual void __fastcall CheckDropDownPoint(int &X, int &Y);
	virtual bool __fastcall CheckKeyForDropDownWindow(System::Word Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	void __fastcall UpdateListFields(void);
	void __fastcall ListLinkDataChanged(void);
	void __fastcall KeyValueChanged(void);
	bool __fastcall LocateKey(void);
	void __fastcall ResetFindStr(void);
	__property System::UnicodeString EditText = {read=GetEditText, write=SetEditText};
	__property System::Generics::Collections::TList__1<Data::Db::TField*>* ListFields = {read=FListFields};
	__property TdxBarLookupLink* ListLink = {read=FListLink};
	
public:
	__fastcall virtual TdxBarLookupCombo(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarLookupCombo(void);
	DYNAMIC void __fastcall DoClick(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	__property System::Variant KeyValue = {read=FKeyValue, write=SetKeyValue};
	
__published:
	__property bool AllowResizing = {read=FAllowResizing, write=FAllowResizing, default=1};
	__property System::Uitypes::TColor Color = {read=FColor, write=FColor, default=-16777211};
	__property bool ImmediateDropDown = {read=FImmediateDropDown, write=FImmediateDropDown, default=0};
	__property System::UnicodeString KeyField = {read=FKeyFieldName, write=SetKeyFieldName};
	__property System::UnicodeString ListField = {read=FListFieldName, write=SetListFieldName};
	__property int ListFieldIndex = {read=FListFieldIndex, write=SetListFieldIndex, default=0};
	__property Data::Db::TDataSource* ListSource = {read=GetListSource, write=SetListSource};
	__property int RowCount = {read=FRowCount, write=SetRowCount, nodefault};
	__property Text = {stored=false, default=0};
	__property int PopupWidth = {read=FPopupWidth, write=FPopupWidth, default=0};
	__property System::Classes::TNotifyEvent OnKeyValueChange = {read=FOnKeyValueChange, write=FOnKeyValueChange};
};


class DELPHICLASS TdxBarLookupComboControl;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarLookupComboControl : public Dxbar::TCustomdxBarComboControl
{
	typedef Dxbar::TCustomdxBarComboControl inherited;
	
protected:
	virtual void __fastcall SetFocused(bool Value);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
public:
	/* TCustomdxBarComboControl.Destroy */ inline __fastcall virtual ~TdxBarLookupComboControl(void) { }
	
public:
	/* TdxBarEditControl.Create */ inline __fastcall virtual TdxBarLookupComboControl(Dxbar::TdxBarItemLink* AItemLink) : Dxbar::TCustomdxBarComboControl(AItemLink) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxBarPopupLookupLink;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxBarPopupLookupLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	TdxBarPopupLookupControl* FBarPopupLookup;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
public:
	/* TDataLink.Create */ inline __fastcall TdxBarPopupLookupLink(void) : Data::Db::TDataLink() { }
	/* TDataLink.Destroy */ inline __fastcall virtual ~TdxBarPopupLookupLink(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxBarPopupLookupControl : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	TdxBarPopupLookupLink* FListLink;
	System::UnicodeString FListFieldName;
	int FListFieldIndex;
	Data::Db::TField* FListField;
	System::Generics::Collections::TList__1<Data::Db::TField*>* FListFields;
	bool FListActive;
	int FRecordIndex;
	int FRecordCount;
	int FRowCount;
	bool FTracking;
	bool FTimerActive;
	int FMousePos;
	System::UnicodeString FSelectedItem;
	int FHScrollWidth;
	int FVScrollWidth;
	bool FCloseBtnDown;
	bool FCloseBtnPaint;
	int FComboTop;
	TdxBarLookupCombo* FCombo;
	Dxcore::TdxCorner FCorner;
	System::Types::TRect FCloseButtonRect;
	System::Types::TRect FGripRect;
	bool FCloseButtonIsTracking;
	bool FMouseAboveCloseButton;
	Data::Db::TDataSource* __fastcall GetListSource(void);
	Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	void __fastcall SetListFieldName(const System::UnicodeString Value);
	void __fastcall SetListSource(Data::Db::TDataSource* Value);
	void __fastcall SelectCurrent(void);
	void __fastcall SelectItemAt(int X, int Y);
	void __fastcall SetRowCount(int Value);
	void __fastcall StopTimer(void);
	void __fastcall StopTracking(void);
	void __fastcall TimerScroll(void);
	void __fastcall UpdateScrollBar(void);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMCaptureChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetMinMaxInfo(Winapi::Messages::TWMGetMinMaxInfo &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCLButtonDown(Winapi::Messages::TWMNCHitMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	MESSAGE void __fastcall WMTimer(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMVScroll(Winapi::Messages::TWMScroll &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ListLinkDataChanged(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	int __fastcall GetTextHeight(void);
	void __fastcall UpdateListFields(void);
	void __fastcall UpdateSizeGripCorner(const System::Types::TPoint &ADropDownPosition);
	__property System::UnicodeString ListField = {read=FListFieldName, write=SetListFieldName};
	__property int ListFieldIndex = {read=FListFieldIndex, write=FListFieldIndex, default=0};
	__property System::Generics::Collections::TList__1<Data::Db::TField*>* ListFields = {read=FListFields};
	__property TdxBarPopupLookupLink* ListLink = {read=FListLink};
	__property Data::Db::TDataSource* ListSource = {read=GetListSource, write=SetListSource};
	__property Dxbar::TdxBarPainter* Painter = {read=GetPainter};
	
public:
	bool IsPopup;
	__fastcall virtual TdxBarPopupLookupControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarPopupLookupControl(void);
	__property int ComboTop = {read=FComboTop, write=FComboTop, nodefault};
	__property int RowCount = {read=FRowCount, write=SetRowCount, stored=false, nodefault};
	__property System::UnicodeString SelectedItem = {read=FSelectedItem};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarPopupLookupControl(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxbarextdbitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBAREXTDBITEMS)
using namespace Dxbarextdbitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarextdbitemsHPP
