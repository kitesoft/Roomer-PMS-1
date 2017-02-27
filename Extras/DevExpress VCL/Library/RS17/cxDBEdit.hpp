// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBEdit.pas' rev: 24.00 (Win32)

#ifndef CxdbeditHPP
#define CxdbeditHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.DBCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxBlobEdit.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <cxCalc.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxCurrencyEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxHyperLinkEdit.hpp>	// Pascal unit
#include <cxImage.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxMRUEdit.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdbedit
{
//-- type declarations -------------------------------------------------------
__interface IcxEditorFieldLink2;
typedef System::DelphiInterface<IcxEditorFieldLink2> _di_IcxEditorFieldLink2;
__interface  INTERFACE_UUID("{4A1B4837-FF36-4408-AF91-D195D16F2BA0}") IcxEditorFieldLink2  : public Cxedit::IcxEditorFieldLink 
{
	
public:
	virtual void __fastcall DoCreateFieldControl(Vcl::Controls::TControl* AControl, Data::Db::TField* AField) = 0 ;
	virtual bool __fastcall NeedCreateCaption(void) = 0 ;
};

class DELPHICLASS TcxCustomDBEditDefaultValuesProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomDBEditDefaultValuesProvider : public Cxedit::TcxCustomEditDefaultValuesProvider
{
	typedef Cxedit::TcxCustomEditDefaultValuesProvider inherited;
	
private:
	Data::Db::TDataSource* FDataSource;
	Data::Db::TField* FField;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotifier;
	void __fastcall FieldFreeNotification(System::Classes::TComponent* Sender);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetField(Data::Db::TField* Value);
	bool __fastcall IsDefaultDataAvailable(void);
	
public:
	__fastcall virtual TcxCustomDBEditDefaultValuesProvider(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomDBEditDefaultValuesProvider(void);
	virtual bool __fastcall CanSetEditMode(void);
	virtual System::Classes::TAlignment __fastcall DefaultAlignment(void);
	virtual Cxedit::TcxBlobKind __fastcall DefaultBlobKind(void);
	virtual bool __fastcall DefaultCanModify(void);
	virtual System::UnicodeString __fastcall DefaultDisplayFormat(void);
	virtual System::UnicodeString __fastcall DefaultEditFormat(void);
	virtual System::UnicodeString __fastcall DefaultEditMask(void);
	virtual bool __fastcall DefaultIsFloatValue(void);
	virtual int __fastcall DefaultMaxLength(void);
	virtual double __fastcall DefaultMaxValue(void);
	virtual double __fastcall DefaultMinValue(void);
	virtual int __fastcall DefaultPrecision(void);
	virtual bool __fastcall DefaultReadOnly(void);
	virtual bool __fastcall DefaultRequired(void);
	virtual bool __fastcall IsBlob(void);
	virtual bool __fastcall IsCurrency(void);
	virtual bool __fastcall IsDataAvailable(void);
	virtual bool __fastcall IsDataStorage(void);
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
	virtual bool __fastcall IsOnGetTextAssigned(void);
	virtual bool __fastcall IsOnSetTextAssigned(void);
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	__property Data::Db::TDataSource* DataSource = {read=FDataSource, write=SetDataSource};
	__property Data::Db::TField* Field = {read=FField, write=SetField};
};

#pragma pack(pop)

class DELPHICLASS TcxDBFieldDataLink;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBFieldDataLink : public Cxdb::TcxCustomFieldDataLink
{
	typedef Cxdb::TcxCustomFieldDataLink inherited;
	
protected:
	virtual void __fastcall FocusControl(Data::Db::TFieldRef Field);
	virtual void __fastcall VisualControlChanged(void);
	virtual void __fastcall UpdateRightToLeft(void);
public:
	/* TcxCustomFieldDataLink.Create */ inline __fastcall virtual TcxDBFieldDataLink(Cxdb::TcxCustomDBDataBinding* ADataBinding) : Cxdb::TcxCustomFieldDataLink(ADataBinding) { }
	
public:
	/* TDataLink.Destroy */ inline __fastcall virtual ~TcxDBFieldDataLink(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxEditFieldDataLink;
class DELPHICLASS TcxDBEditDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditFieldDataLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	System::Classes::TComponent* FControl;
	TcxDBEditDataBinding* FDataBinding;
	bool FEditing;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotifier;
	bool FModified;
	Data::Db::TField* FDataField;
	System::UnicodeString FFieldName;
	Data::Db::TField* FMasterField;
	Data::Db::TField* FPropertiesField;
	void __fastcall FieldFreeNotification(System::Classes::TComponent* Sender);
	bool __fastcall GetCanModify(void);
	void __fastcall InternalSetField(Data::Db::TField* ADataField, Data::Db::TField* APropertiesField);
	HIDESBASE void __fastcall SetEditing(bool Value);
	void __fastcall SetField(Data::Db::TField* ADataField, Data::Db::TField* APropertiesField);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	void __fastcall UpdateField(void);
	void __fastcall UpdateMasterField(void);
	void __fastcall UpdateRightToLeft(void);
	
protected:
	virtual void __fastcall DataEvent(Data::Db::TDataEvent Event, NativeInt Info);
	virtual void __fastcall FocusControl(Data::Db::TFieldRef Field);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Data::Db::TField* AField);
	void __fastcall ResetModified(void);
	__property Data::Db::TField* DataField = {read=FDataField};
	__property Data::Db::TField* PropertiesField = {read=FPropertiesField};
	
public:
	__fastcall TcxEditFieldDataLink(TcxDBEditDataBinding* ADataBinding);
	__fastcall virtual ~TcxEditFieldDataLink(void);
	HIDESBASE bool __fastcall Edit(void);
	void __fastcall Modified(void);
	void __fastcall Reset(void);
	__property bool CanModify = {read=GetCanModify, nodefault};
	__property System::Classes::TComponent* Control = {read=FControl, write=FControl};
	__property bool Editing = {read=FEditing, nodefault};
	__property Data::Db::TField* Field = {read=FDataField};
	__property System::UnicodeString FieldName = {read=FFieldName, write=SetFieldName};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBEditDataBinding : public Cxedit::TcxEditDataBinding
{
	typedef Cxedit::TcxEditDataBinding inherited;
	
private:
	TcxEditFieldDataLink* FDataLink;
	int FRefreshCount;
	System::UnicodeString __fastcall GetDataFieldName(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	TcxCustomDBEditDefaultValuesProvider* __fastcall GetDefaultValuesProvider(void);
	Data::Db::TField* __fastcall GetDataField(void);
	Data::Db::TField* __fastcall GetProperiesField(void);
	void __fastcall SetDataFieldName(const System::UnicodeString Value);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	
protected:
	virtual void __fastcall DefaultValuesChanged(void);
	virtual bool __fastcall GetEditing(void);
	virtual bool __fastcall GetIsDataAvailable(void);
	virtual bool __fastcall GetModified(void);
	virtual System::Variant __fastcall GetStoredValue(void);
	virtual bool __fastcall IsNull(void);
	virtual bool __fastcall IsInnerControlHaveToBeReadOnly(void);
	virtual void __fastcall Reset(void);
	virtual void __fastcall SetDisplayValue(const System::Variant &Value);
	virtual bool __fastcall SetEditMode(void);
	virtual void __fastcall SetStoredValue(const System::Variant &Value);
	void __fastcall DisableRefresh(void);
	void __fastcall EnableRefresh(void);
	bool __fastcall IsRefreshDisabled(void);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DataSetChange(void);
	virtual void __fastcall EditingChanged(void);
	virtual bool __fastcall IsLookupControl(void);
	virtual void __fastcall UpdateData(void);
	__property TcxCustomDBEditDefaultValuesProvider* DefaultValuesProvider = {read=GetDefaultValuesProvider};
	__property Data::Db::TField* ProperiesField = {read=GetProperiesField};
	
public:
	__fastcall virtual TcxDBEditDataBinding(Cxedit::TcxCustomEdit* AEdit);
	__fastcall virtual ~TcxDBEditDataBinding(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CanCheckEditorValue(void);
	virtual bool __fastcall CanModify(void);
	virtual bool __fastcall CanPostEditorValue(void);
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	__classmethod virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass();
	virtual void __fastcall SetModified(void);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall UpdateDisplayValue(void);
	virtual void __fastcall UpdateNotConnectedDBEditDisplayValue(void);
	__property TcxEditFieldDataLink* DataLink = {read=FDataLink};
	__property Data::Db::TField* Field = {read=GetDataField};
	
__published:
	__property System::UnicodeString DataField = {read=GetDataFieldName, write=SetDataFieldName};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
};

#pragma pack(pop)

class DELPHICLASS TcxDBTextEditDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBTextEditDataBinding : public TcxDBEditDataBinding
{
	typedef TcxDBEditDataBinding inherited;
	
protected:
	virtual void __fastcall SetDisplayValue(const System::Variant &Value);
	
public:
	virtual void __fastcall UpdateNotConnectedDBEditDisplayValue(void);
public:
	/* TcxDBEditDataBinding.Create */ inline __fastcall virtual TcxDBTextEditDataBinding(Cxedit::TcxCustomEdit* AEdit) : TcxDBEditDataBinding(AEdit) { }
	/* TcxDBEditDataBinding.Destroy */ inline __fastcall virtual ~TcxDBTextEditDataBinding(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDBTextEdit;
class PASCALIMPLEMENTATION TcxDBTextEdit : public Cxtextedit::TcxCustomTextEdit
{
	typedef Cxtextedit::TcxCustomTextEdit inherited;
	
private:
	HIDESBASE Cxtextedit::TcxTextEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxtextedit::TcxTextEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxtextedit::TcxTextEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	virtual bool __fastcall SupportsSpelling(void);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxtextedit::TcxTextEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxtextedit::TcxTextEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxDBTextEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxDBTextEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBTextEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxtextedit::TcxCustomTextEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBTextEdit(HWND ParentWindow) : Cxtextedit::TcxCustomTextEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBMemo;
class PASCALIMPLEMENTATION TcxDBMemo : public Cxmemo::TcxCustomMemo
{
	typedef Cxmemo::TcxCustomMemo inherited;
	
private:
	HIDESBASE Cxmemo::TcxMemoProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxmemo::TcxMemoProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxmemo::TcxMemoProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxmemo::TcxMemoProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxmemo::TcxMemoProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxDBMemo(System::Classes::TComponent* AOwner)/* overload */ : Cxmemo::TcxCustomMemo(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxDBMemo(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBMemo(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxmemo::TcxCustomMemo(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBMemo(HWND ParentWindow) : Cxmemo::TcxCustomMemo(ParentWindow) { }
	
};


class DELPHICLASS TcxDBMaskEdit;
class PASCALIMPLEMENTATION TcxDBMaskEdit : public Cxmaskedit::TcxCustomMaskEdit
{
	typedef Cxmaskedit::TcxCustomMaskEdit inherited;
	
private:
	HIDESBASE Cxmaskedit::TcxMaskEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxmaskedit::TcxMaskEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxmaskedit::TcxMaskEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	virtual bool __fastcall SupportsSpelling(void);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxmaskedit::TcxMaskEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxmaskedit::TcxMaskEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBMaskEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxmaskedit::TcxCustomMaskEdit(AOwner) { }
	/* TcxCustomMaskEdit.Destroy */ inline __fastcall virtual ~TcxDBMaskEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBMaskEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxmaskedit::TcxCustomMaskEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBMaskEdit(HWND ParentWindow) : Cxmaskedit::TcxCustomMaskEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBButtonEdit;
class PASCALIMPLEMENTATION TcxDBButtonEdit : public Cxbuttonedit::TcxCustomButtonEdit
{
	typedef Cxbuttonedit::TcxCustomButtonEdit inherited;
	
private:
	HIDESBASE Cxbuttonedit::TcxButtonEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxbuttonedit::TcxButtonEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxbuttonedit::TcxButtonEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxbuttonedit::TcxButtonEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxbuttonedit::TcxButtonEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBButtonEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxbuttonedit::TcxCustomButtonEdit(AOwner) { }
	/* TcxCustomMaskEdit.Destroy */ inline __fastcall virtual ~TcxDBButtonEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBButtonEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxbuttonedit::TcxCustomButtonEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBButtonEdit(HWND ParentWindow) : Cxbuttonedit::TcxCustomButtonEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBCheckBox;
class PASCALIMPLEMENTATION TcxDBCheckBox : public Cxcheckbox::TcxCustomCheckBox
{
	typedef Cxcheckbox::TcxCustomCheckBox inherited;
	
private:
	HIDESBASE Cxcheckbox::TcxCheckBoxProperties* __fastcall GetActiveProperties(void);
	TcxDBEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxcheckbox::TcxCheckBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxcheckbox::TcxCheckBoxProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxcheckbox::TcxCheckBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property Checked;
	
__published:
	__property Action;
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property Caption = {default=0};
	__property Constraints;
	__property TcxDBEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentBackground = {default=1};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Cxcheckbox::TcxCheckBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
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
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBCheckBox(System::Classes::TComponent* AOwner)/* overload */ : Cxcheckbox::TcxCustomCheckBox(AOwner) { }
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBCheckBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxcheckbox::TcxCustomCheckBox(AOwner, AIsInplace) { }
	/* TcxCustomEdit.Destroy */ inline __fastcall virtual ~TcxDBCheckBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBCheckBox(HWND ParentWindow) : Cxcheckbox::TcxCustomCheckBox(ParentWindow) { }
	
};


class DELPHICLASS TcxDBComboBox;
class PASCALIMPLEMENTATION TcxDBComboBox : public Cxdropdownedit::TcxCustomComboBox
{
	typedef Cxdropdownedit::TcxCustomComboBox inherited;
	
private:
	HIDESBASE Cxdropdownedit::TcxComboBoxProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxdropdownedit::TcxComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxdropdownedit::TcxComboBoxProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	virtual bool __fastcall SupportsSpelling(void);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxdropdownedit::TcxComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property ItemIndex;
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxdropdownedit::TcxComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxDBComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBComboBox(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBComboBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxDBPopupEdit;
class PASCALIMPLEMENTATION TcxDBPopupEdit : public Cxdropdownedit::TcxCustomPopupEdit
{
	typedef Cxdropdownedit::TcxCustomPopupEdit inherited;
	
private:
	HIDESBASE Cxdropdownedit::TcxPopupEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxdropdownedit::TcxPopupEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxdropdownedit::TcxPopupEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	virtual bool __fastcall SupportsSpelling(void);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxdropdownedit::TcxPopupEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxdropdownedit::TcxPopupEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomPopupEdit.Destroy */ inline __fastcall virtual ~TcxDBPopupEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBPopupEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBPopupEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBPopupEdit(HWND ParentWindow) : Cxdropdownedit::TcxCustomPopupEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBSpinEdit;
class PASCALIMPLEMENTATION TcxDBSpinEdit : public Cxspinedit::TcxCustomSpinEdit
{
	typedef Cxspinedit::TcxCustomSpinEdit inherited;
	
private:
	HIDESBASE Cxspinedit::TcxSpinEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxspinedit::TcxSpinEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxspinedit::TcxSpinEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxspinedit::TcxSpinEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property Value = {default=0};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxspinedit::TcxSpinEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomSpinEdit.Destroy */ inline __fastcall virtual ~TcxDBSpinEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBSpinEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxspinedit::TcxCustomSpinEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBSpinEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxspinedit::TcxCustomSpinEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBSpinEdit(HWND ParentWindow) : Cxspinedit::TcxCustomSpinEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBTimeEdit;
class PASCALIMPLEMENTATION TcxDBTimeEdit : public Cxtimeedit::TcxCustomTimeEdit
{
	typedef Cxtimeedit::TcxCustomTimeEdit inherited;
	
private:
	HIDESBASE Cxtimeedit::TcxTimeEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxtimeedit::TcxTimeEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxtimeedit::TcxTimeEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxtimeedit::TcxTimeEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxtimeedit::TcxTimeEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	/* TcxCustomSpinEdit.Destroy */ inline __fastcall virtual ~TcxDBTimeEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBTimeEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxtimeedit::TcxCustomTimeEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBTimeEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxtimeedit::TcxCustomTimeEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBTimeEdit(HWND ParentWindow) : Cxtimeedit::TcxCustomTimeEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBBlobEdit;
class PASCALIMPLEMENTATION TcxDBBlobEdit : public Cxblobedit::TcxCustomBlobEdit
{
	typedef Cxblobedit::TcxCustomBlobEdit inherited;
	
private:
	HIDESBASE Cxblobedit::TcxBlobEditProperties* __fastcall GetActiveProperties(void);
	TcxDBEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxblobedit::TcxBlobEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxblobedit::TcxBlobEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxblobedit::TcxBlobEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxblobedit::TcxBlobEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnGetGraphicClass;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomBlobEdit.Destroy */ inline __fastcall virtual ~TcxDBBlobEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBBlobEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxblobedit::TcxCustomBlobEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBBlobEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxblobedit::TcxCustomBlobEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBBlobEdit(HWND ParentWindow) : Cxblobedit::TcxCustomBlobEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBCalcEdit;
class PASCALIMPLEMENTATION TcxDBCalcEdit : public Cxcalc::TcxCustomCalcEdit
{
	typedef Cxcalc::TcxCustomCalcEdit inherited;
	
private:
	HIDESBASE Cxcalc::TcxCalcEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxcalc::TcxCalcEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxcalc::TcxCalcEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxcalc::TcxCalcEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property Value = {default=0};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxcalc::TcxCalcEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomCalcEdit.Destroy */ inline __fastcall virtual ~TcxDBCalcEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBCalcEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxcalc::TcxCustomCalcEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBCalcEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxcalc::TcxCustomCalcEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBCalcEdit(HWND ParentWindow) : Cxcalc::TcxCustomCalcEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBDateEdit;
class PASCALIMPLEMENTATION TcxDBDateEdit : public Cxcalendar::TcxCustomDateEdit
{
	typedef Cxcalendar::TcxCustomDateEdit inherited;
	
private:
	HIDESBASE Cxcalendar::TcxDateEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxcalendar::TcxDateEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxcalendar::TcxDateEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxcalendar::TcxDateEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxcalendar::TcxDateEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomDateEdit.Destroy */ inline __fastcall virtual ~TcxDBDateEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBDateEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxcalendar::TcxCustomDateEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBDateEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxcalendar::TcxCustomDateEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBDateEdit(HWND ParentWindow) : Cxcalendar::TcxCustomDateEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBCurrencyEdit;
class PASCALIMPLEMENTATION TcxDBCurrencyEdit : public Cxcurrencyedit::TcxCustomCurrencyEdit
{
	typedef Cxcurrencyedit::TcxCustomCurrencyEdit inherited;
	
private:
	HIDESBASE Cxcurrencyedit::TcxCurrencyEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxcurrencyedit::TcxCurrencyEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxcurrencyedit::TcxCurrencyEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxcurrencyedit::TcxCurrencyEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxcurrencyedit::TcxCurrencyEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnEditing;
	__property OnEndDock;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
public:
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxDBCurrencyEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxcurrencyedit::TcxCustomCurrencyEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxDBCurrencyEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBCurrencyEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxcurrencyedit::TcxCustomCurrencyEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBCurrencyEdit(HWND ParentWindow) : Cxcurrencyedit::TcxCustomCurrencyEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBHyperLinkEdit;
class PASCALIMPLEMENTATION TcxDBHyperLinkEdit : public Cxhyperlinkedit::TcxCustomHyperLinkEdit
{
	typedef Cxhyperlinkedit::TcxCustomHyperLinkEdit inherited;
	
private:
	HIDESBASE Cxhyperlinkedit::TcxHyperLinkEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxhyperlinkedit::TcxHyperLinkEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxhyperlinkedit::TcxHyperLinkEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxhyperlinkedit::TcxHyperLinkEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxhyperlinkedit::TcxHyperLinkEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnEditing;
	__property OnEndDock;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
public:
	/* TcxCustomTextEdit.Create */ inline __fastcall virtual TcxDBHyperLinkEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxhyperlinkedit::TcxCustomHyperLinkEdit(AOwner) { }
	/* TcxCustomTextEdit.Destroy */ inline __fastcall virtual ~TcxDBHyperLinkEdit(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBHyperLinkEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxhyperlinkedit::TcxCustomHyperLinkEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBHyperLinkEdit(HWND ParentWindow) : Cxhyperlinkedit::TcxCustomHyperLinkEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBImage;
class PASCALIMPLEMENTATION TcxDBImage : public Cximage::TcxCustomImage
{
	typedef Cximage::TcxCustomImage inherited;
	
private:
	HIDESBASE Cximage::TcxImageProperties* __fastcall GetActiveProperties(void);
	TcxDBEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cximage::TcxImageProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cximage::TcxImageProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cximage::TcxImageProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=0};
	__property Constraints;
	__property TcxDBEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentColor = {default=0};
	__property PopupMenu;
	__property Cximage::TcxImageProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
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
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetGraphicClass;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomImage.Create */ inline __fastcall virtual TcxDBImage(System::Classes::TComponent* AOwner)/* overload */ : Cximage::TcxCustomImage(AOwner) { }
	/* TcxCustomImage.Destroy */ inline __fastcall virtual ~TcxDBImage(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBImage(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cximage::TcxCustomImage(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBImage(HWND ParentWindow) : Cximage::TcxCustomImage(ParentWindow) { }
	
};


class DELPHICLASS TcxDBImageComboBox;
class PASCALIMPLEMENTATION TcxDBImageComboBox : public Cximagecombobox::TcxCustomImageComboBox
{
	typedef Cximagecombobox::TcxCustomImageComboBox inherited;
	
private:
	HIDESBASE Cximagecombobox::TcxImageComboBoxProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cximagecombobox::TcxImageComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cximagecombobox::TcxImageComboBoxProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cximagecombobox::TcxImageComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property ItemIndex;
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cximagecombobox::TcxImageComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnEditing;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxDBImageComboBox(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBImageComboBox(System::Classes::TComponent* AOwner)/* overload */ : Cximagecombobox::TcxCustomImageComboBox(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBImageComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cximagecombobox::TcxCustomImageComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBImageComboBox(HWND ParentWindow) : Cximagecombobox::TcxCustomImageComboBox(ParentWindow) { }
	
};


class DELPHICLASS TcxDBMRUEdit;
class PASCALIMPLEMENTATION TcxDBMRUEdit : public Cxmruedit::TcxCustomMRUEdit
{
	typedef Cxmruedit::TcxCustomMRUEdit inherited;
	
private:
	HIDESBASE Cxmruedit::TcxMRUEditProperties* __fastcall GetActiveProperties(void);
	TcxDBTextEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxmruedit::TcxMRUEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBTextEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxmruedit::TcxMRUEditProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxmruedit::TcxMRUEditProperties* ActiveProperties = {read=GetActiveProperties};
	
protected:
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property TcxDBTextEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
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
	__property Cxmruedit::TcxMRUEditProperties* Properties = {read=GetProperties, write=SetProperties};
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
	__property OnEditing;
	__property OnEndDock;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxDBMRUEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDBMRUEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxmruedit::TcxCustomMRUEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBMRUEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxmruedit::TcxCustomMRUEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBMRUEdit(HWND ParentWindow) : Cxmruedit::TcxCustomMRUEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBRadioGroupButton;
class PASCALIMPLEMENTATION TcxDBRadioGroupButton : public Cxradiogroup::TcxCustomRadioGroupButton
{
	typedef Cxradiogroup::TcxCustomRadioGroupButton inherited;
	
private:
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TcxDBRadioGroupButton(System::Classes::TComponent* AOwner);
public:
	/* TcxCustomRadioGroupButton.Destroy */ inline __fastcall virtual ~TcxDBRadioGroupButton(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBRadioGroupButton(HWND ParentWindow) : Cxradiogroup::TcxCustomRadioGroupButton(ParentWindow) { }
	
};


class DELPHICLASS TcxDBRadioGroup;
class PASCALIMPLEMENTATION TcxDBRadioGroup : public Cxradiogroup::TcxCustomRadioGroup
{
	typedef Cxradiogroup::TcxCustomRadioGroup inherited;
	
private:
	HIDESBASE Cxradiogroup::TcxRadioGroupProperties* __fastcall GetActiveProperties(void);
	TcxDBEditDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE Cxradiogroup::TcxRadioGroupProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetDataBinding(TcxDBEditDataBinding* Value);
	HIDESBASE void __fastcall SetProperties(Cxradiogroup::TcxRadioGroupProperties* Value);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Cxradiogroup::TcxRadioGroupProperties* ActiveProperties = {read=GetActiveProperties};
	
protected:
	virtual Vcl::Controls::TWinControl* __fastcall GetButtonInstance(void);
	__classmethod virtual Cxedit::TcxEditDataBindingClass __fastcall GetDataBindingClass();
	
__published:
	__property Alignment = {default=0};
	__property Anchors = {default=3};
	__property Caption = {default=0};
	__property Constraints;
	__property Ctl3D;
	__property TcxDBEditDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ParentBackground = {default=1};
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Cxradiogroup::TcxRadioGroupProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
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
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomButtonGroup.Destroy */ inline __fastcall virtual ~TcxDBRadioGroup(void) { }
	
public:
	/* TcxCustomGroupBox.Create */ inline __fastcall virtual TcxDBRadioGroup(System::Classes::TComponent* AOwner)/* overload */ : Cxradiogroup::TcxCustomRadioGroup(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDBRadioGroup(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxradiogroup::TcxCustomRadioGroup(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBRadioGroup(HWND ParentWindow) : Cxradiogroup::TcxCustomRadioGroup(ParentWindow) { }
	
};


class DELPHICLASS TcxDBListBox;
class PASCALIMPLEMENTATION TcxDBListBox : public Cxlistbox::TcxListBox
{
	typedef Cxlistbox::TcxListBox inherited;
	
private:
	Cxdb::TcxDBDataBinding* __fastcall GetDataBinding(void);
	void __fastcall SetDataBinding(Cxdb::TcxDBDataBinding* Value);
	
protected:
	virtual Cxdatautils::TcxCustomDataBindingClass __fastcall GetDataBindingClass(void);
	
__published:
	__property Cxdb::TcxDBDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxListBox.Create */ inline __fastcall virtual TcxDBListBox(System::Classes::TComponent* AOwner) : Cxlistbox::TcxListBox(AOwner) { }
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TcxDBListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDBListBox(HWND ParentWindow) : Cxlistbox::TcxListBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Data::Db::TDataLink* __fastcall GetcxDBEditDataLink(Cxedit::TcxCustomEdit* AEdit);
}	/* namespace Cxdbedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBEDIT)
using namespace Cxdbedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbeditHPP
