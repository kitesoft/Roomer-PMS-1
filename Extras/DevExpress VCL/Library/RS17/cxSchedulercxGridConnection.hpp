// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulercxGridConnection.pas' rev: 24.00 (Win32)

#ifndef CxschedulercxgridconnectionHPP
#define CxschedulercxgridconnectionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxSchedulerDialogs.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxColorComboBox.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxProgressBar.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxGridPopupMenu.hpp>	// Pascal unit
#include <cxGridCustomPopupMenu.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulercxgridconnection
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerStorageDataSource;
class DELPHICLASS TcxSchedulerGridConnection;
class DELPHICLASS TcxSchedulerFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerStorageDataSource : public Cxcustomdata::TcxCustomDataSource
{
	typedef Cxcustomdata::TcxCustomDataSource inherited;
	
private:
	TcxSchedulerGridConnection* FConnection;
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	
protected:
	void * __fastcall AddNewEvent(void);
	virtual void * __fastcall AppendRecord(void);
	virtual void __fastcall DeleteRecord(void * ARecordHandle);
	bool __fastcall GetAdapter(void * AItemHandle, /* out */ TcxSchedulerFieldAdapter* &Adapter);
	virtual int __fastcall GetRecordCount(void);
	virtual void * __fastcall GetRecordHandle(int ARecordIndex);
	virtual System::Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	virtual void * __fastcall InsertRecord(void * ARecordHandle);
	virtual void __fastcall SetValue(void * ARecordHandle, void * AItemHandle, const System::Variant &AValue);
	
public:
	__property TcxSchedulerGridConnection* Connection = {read=FConnection};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=GetStorage};
public:
	/* TcxCustomDataSource.Destroy */ inline __fastcall virtual ~TcxSchedulerStorageDataSource(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerStorageDataSource(void) : Cxcustomdata::TcxCustomDataSource() { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerFieldAdapter : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxSchedulerGridConnection* FConnection;
	Cxedit::TcxCustomEditProperties* FEditProperties;
	Cxschedulerstorage::TcxCustomSchedulerStorageField* FField;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	Cxgridcustomtableview::TcxCustomGridTableItem* FItem;
	System::Classes::TCollectionItem* FLink;
	void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	System::UnicodeString __fastcall GetCaption(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void);
	bool __fastcall GetReadOnly(void);
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetCaption(System::UnicodeString AValue);
	void __fastcall SetItem(Cxgridcustomtableview::TcxCustomGridTableItem* AValue);
	void __fastcall SetReadOnly(const bool AValue);
	void __fastcall SetVisible(const bool AValue);
	
protected:
	virtual void __fastcall DeleteItem(void);
	virtual void __fastcall DoGetPropertiesForEdit(Cxgridcustomtableview::TcxCustomGridTableItem* Sender, Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxedit::TcxCustomEditProperties* &AProperties);
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEvent(int ARecordIndex);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesForEditClass(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializeAdapter(void);
	virtual void __fastcall InitializeEditProperties(void);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
	__property System::Classes::TCollectionItem* Link = {read=FLink, write=FLink};
	
public:
	__fastcall virtual TcxSchedulerFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink);
	__fastcall virtual TcxSchedulerFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField);
	__fastcall virtual ~TcxSchedulerFieldAdapter(void);
	__classmethod void __fastcall Register();
	__classmethod void __fastcall Unregister();
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption};
	__property TcxSchedulerGridConnection* Connection = {read=FConnection};
	__property Cxedit::TcxCustomEditProperties* EditProperties = {read=FEditProperties, write=FEditProperties};
	__property Cxschedulerstorage::TcxCustomSchedulerStorageField* Field = {read=FField};
	__property Cxgridcustomtableview::TcxCustomGridTableItem* Item = {read=FItem, write=SetItem};
	__property Cxedit::TcxCustomEditProperties* Properties = {read=GetProperties};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, nodefault};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	__property System::Variant Values[Cxschedulerstorage::TcxSchedulerEvent* AEvent] = {read=GetValue, write=SetValue};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSchedulerFieldAdapterClass;

class DELPHICLASS TcxSchedulerNullAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerNullAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual void __fastcall DeleteItem(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
	
public:
	__fastcall virtual TcxSchedulerNullAdapter(TcxSchedulerGridConnection* AConnection, Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerNullAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerNullAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerNullAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerIntegerFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerIntegerFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerIntegerFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerIntegerFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerIntegerFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerTextFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTextFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerTextFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerTextFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerTextFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerCheckFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerCheckFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerCheckFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerCheckFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerCheckFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerDateTimeFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateTimeFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual void __fastcall Initialize(void);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerDateTimeFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerDateTimeFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerDateTimeFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerEventStartFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerEventStartFieldAdapter : public TcxSchedulerDateTimeFieldAdapter
{
	typedef TcxSchedulerDateTimeFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerEventStartFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerDateTimeFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerEventStartFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerDateTimeFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerEventStartFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerEventFinishFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerEventFinishFieldAdapter : public TcxSchedulerDateTimeFieldAdapter
{
	typedef TcxSchedulerDateTimeFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerEventFinishFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerDateTimeFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerEventFinishFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerDateTimeFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerEventFinishFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerImageComboFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerImageComboFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
private:
	HIDESBASE Cximagecombobox::TcxImageComboBoxProperties* __fastcall GetProperties(void);
	
protected:
	void __fastcall AddItems(System::Variant const *AItemsValues, const int AItemsValues_Size);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	
public:
	__property Cximagecombobox::TcxImageComboBoxProperties* Properties = {read=GetProperties};
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerImageComboFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerImageComboFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerImageComboFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerIDFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerIDFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerIDFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerIDFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerIDFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerGroupIDFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerGroupIDFieldAdapter : public TcxSchedulerIDFieldAdapter
{
	typedef TcxSchedulerIDFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerGroupIDFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerIDFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerGroupIDFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerIDFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerGroupIDFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerTypeFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTypeFieldAdapter : public TcxSchedulerImageComboFieldAdapter
{
	typedef TcxSchedulerImageComboFieldAdapter inherited;
	
protected:
	virtual void __fastcall Initialize(void);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerTypeFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerImageComboFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerTypeFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerImageComboFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerTypeFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerAllDayFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerAllDayFieldAdapter : public TcxSchedulerCheckFieldAdapter
{
	typedef TcxSchedulerCheckFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerAllDayFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerCheckFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerAllDayFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerCheckFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerAllDayFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerEnabledFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerEnabledFieldAdapter : public TcxSchedulerCheckFieldAdapter
{
	typedef TcxSchedulerCheckFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerEnabledFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerCheckFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerEnabledFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerCheckFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerEnabledFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerReminderFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerReminderFieldAdapter : public TcxSchedulerCheckFieldAdapter
{
	typedef TcxSchedulerCheckFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerReminderFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerCheckFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerReminderFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerCheckFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerReminderFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerLabelColorFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerLabelColorFieldAdapter : public TcxSchedulerImageComboFieldAdapter
{
	typedef TcxSchedulerImageComboFieldAdapter inherited;
	
protected:
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerLabelColorFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerImageComboFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerLabelColorFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerImageComboFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerLabelColorFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerRecurringFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerRecurringFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerRecurringFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerRecurringFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerRecurringFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerStateFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerStateFieldAdapter : public TcxSchedulerImageComboFieldAdapter
{
	typedef TcxSchedulerImageComboFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall Initialize(void);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerStateFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerImageComboFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerStateFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerImageComboFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerStateFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerResourceIDFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerResourceIDFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	virtual void __fastcall Initialize(void);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerResourceIDFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerResourceIDFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerResourceIDFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerCompleteFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerCompleteFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass(void);
	virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesForEditClass(void);
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall InitializeEditProperties(void);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerCompleteFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerCompleteFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerCompleteFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerLinksFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerLinksFieldAdapter : public TcxSchedulerFieldAdapter
{
	typedef TcxSchedulerFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerLinksFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerLinksFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerLinksFieldAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerStatusFieldAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerStatusFieldAdapter : public TcxSchedulerImageComboFieldAdapter
{
	typedef TcxSchedulerImageComboFieldAdapter inherited;
	
protected:
	virtual System::Variant __fastcall GetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall SetValue(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::Variant &AValue);
public:
	/* TcxSchedulerFieldAdapter.Create */ inline __fastcall virtual TcxSchedulerStatusFieldAdapter(TcxSchedulerGridConnection* AConnection, System::Classes::TCollectionItem* ALink) : TcxSchedulerImageComboFieldAdapter(AConnection, ALink) { }
	/* TcxSchedulerFieldAdapter.CreateWithField */ inline __fastcall virtual TcxSchedulerStatusFieldAdapter(TcxSchedulerGridConnection* AConnection, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField) : TcxSchedulerImageComboFieldAdapter(AConnection, AField) { }
	/* TcxSchedulerFieldAdapter.Destroy */ inline __fastcall virtual ~TcxSchedulerStatusFieldAdapter(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxSchedulerInitializeGridItemEvent)(TcxSchedulerGridConnection* Sender, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, TcxSchedulerFieldAdapter* Adapter);

typedef void __fastcall (__closure *TcxSchedulerGetFieldAdapterEvent)(TcxSchedulerGridConnection* Sender, Cxschedulerstorage::TcxCustomSchedulerStorageField* AField, TcxSchedulerFieldAdapterClass &AdapterClass);

typedef void __fastcall (__closure *TcxSchedulerConnectionEditEventEvent)(TcxSchedulerGridConnection* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool &AModified, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerConnectionGridViewDblClickEvent)(System::TObject* Sender, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerConnectionNewEventEvent)(TcxSchedulerGridConnection* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* &AEvent, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerConnectionInitEditDialogEvent)(TcxSchedulerGridConnection* Sender, Cxschedulercustomcontrols::TcxSchedulerEventEditInfo* &AEditInfo);

class DELPHICLASS TcxSchedulerGridBuildInPopupMenu;
class DELPHICLASS TcxSchedulerGridBuildInPopupMenuController;
class PASCALIMPLEMENTATION TcxSchedulerGridConnection : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FActive;
	System::Classes::TCollection* FAdapters;
	Cxschedulercustomcontrols::TcxSchedulerEventEditInfo* FEventEditInfo;
	TcxSchedulerGridBuildInPopupMenu* FGridPopupMenu;
	System::Classes::TNotifyEvent FGridPopupMenuEvents;
	TcxSchedulerGridBuildInPopupMenuController* FGridPopupMenuController;
	Cxgridcustomtableview::TcxCustomGridTableView* FGridView;
	bool FIsChanged;
	int FLockCount;
	TcxSchedulerStorageDataSource* FProvider;
	Cxschedulerstorage::TcxCustomSchedulerStorage* FStorage;
	TcxSchedulerConnectionEditEventEvent FOnEditEvent;
	TcxSchedulerGetFieldAdapterEvent FOnGetFieldAdapter;
	TcxSchedulerConnectionGridViewDblClickEvent FOnGridViewDblClick;
	TcxSchedulerConnectionInitEditDialogEvent FOnInitEditDialog;
	TcxSchedulerInitializeGridItemEvent FOnInitializeItem;
	TcxSchedulerConnectionNewEventEvent FOnNewEvent;
	TcxSchedulerFieldAdapter* __fastcall GetAdapter(int AIndex);
	int __fastcall GetCount(void);
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetEvent(int ARowIndex);
	int __fastcall GetEventCount(void);
	bool __fastcall GetIsDestroying(void);
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIsLocked(void);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetGridPopupMenu(TcxSchedulerGridBuildInPopupMenu* AValue);
	void __fastcall SetGridView(Cxgridcustomtableview::TcxCustomGridTableView* AValue);
	void __fastcall SetStorage(Cxschedulerstorage::TcxCustomSchedulerStorage* AValue);
	void __fastcall SetupBuildInPopupMenu(void);
	void __fastcall ReadLinks(System::Classes::TReader* Reader);
	void __fastcall WriteLinks(System::Classes::TWriter* Writer);
	
protected:
	virtual Cxschedulerstorage::TcxSchedulerEvent* __fastcall AddNewEvent(bool ARecurrence = false, bool AnAllDayEvent = false);
	TcxSchedulerFieldAdapter* __fastcall AdapterByItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	System::Classes::TCollectionItem* __fastcall AddAdapterLink(TcxSchedulerFieldAdapter* Adapter);
	TcxSchedulerFieldAdapter* __fastcall AddAdapter(Cxschedulerstorage::TcxCustomSchedulerStorageField* AField, TcxSchedulerFieldAdapterClass AdapterClass, void * ACaption, bool AVisible, bool ACanEdit);
	TcxSchedulerFieldAdapter* __fastcall AddAdapterEx(System::Classes::TCollectionItem* ALink, TcxSchedulerFieldAdapterClass AdapterClass);
	TcxSchedulerFieldAdapter* __fastcall AddAdapterForCustomField(Cxschedulerstorage::TcxCustomSchedulerStorageField* AField);
	void __fastcall BeginUpdate(void);
	TcxSchedulerStorageDataSource* __fastcall CreateDataSource(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DblClickGridHandler(System::TObject* Sender);
	bool __fastcall DoGridViewDblClick(System::TObject* Sender);
	virtual void __fastcall DoInitEditDialog(void);
	virtual void __fastcall DoInitializeItem(Cxschedulerstorage::TcxCustomSchedulerStorageField* AField, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, TcxSchedulerFieldAdapter* AAdapter);
	virtual void __fastcall DoEditEventUsingDialog(Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool ARecurrence = false, bool AReadOnly = false, bool AForcePatternEditing = false);
	virtual void __fastcall DoGetItemAdapter(Cxschedulerstorage::TcxCustomSchedulerStorageField* AField, TcxSchedulerFieldAdapterClass &AdapterClass);
	void __fastcall EndUpdate(void);
	Cxschedulercustomcontrols::TcxSchedulerEventEditInfo* __fastcall GetEventEditInfo(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool ARecurrence = false);
	Cxschedulerstorage::TcxSchedulerEvent* __fastcall GetFocusedEvent(void);
	bool __fastcall GetIsFieldActive(Cxschedulerstorage::TcxCustomSchedulerStorageField* AField);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall OpenEventEditDialog(bool AForcePatternEditing = false, bool AReadOnly = false);
	void __fastcall Reactivate(void);
	virtual void __fastcall SetupView(void);
	virtual void __fastcall Loaded(void);
	void __fastcall RestoreItems(void);
	void __fastcall StoreItems(void);
	DYNAMIC void __fastcall Updated(void);
	DYNAMIC void __fastcall Updating(void);
	virtual void __fastcall StorageChanged(System::TObject* Sender);
	virtual void __fastcall StorageRemoved(System::TObject* Sender);
	__property TcxSchedulerFieldAdapter* Adapters[int Index] = {read=GetAdapter};
	__property int Count = {read=GetCount, nodefault};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property int EventCount = {read=GetEventCount, nodefault};
	__property Cxschedulerstorage::TcxSchedulerEvent* Events[int ARowIndex] = {read=GetEvent};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	
public:
	__fastcall virtual TcxSchedulerGridConnection(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSchedulerGridConnection(void);
	void __fastcall Refresh(void);
	__property TcxSchedulerStorageDataSource* Provider = {read=FProvider};
	
__published:
	__property TcxSchedulerGridBuildInPopupMenu* GridPopupMenu = {read=FGridPopupMenu, write=SetGridPopupMenu};
	__property System::Classes::TNotifyEvent GridPopupMenuEvents = {read=FGridPopupMenuEvents, write=FGridPopupMenuEvents};
	__property Cxgridcustomtableview::TcxCustomGridTableView* GridView = {read=FGridView, write=SetGridView};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=FStorage, write=SetStorage};
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property TcxSchedulerConnectionEditEventEvent OnEditEvent = {read=FOnEditEvent, write=FOnEditEvent};
	__property TcxSchedulerGetFieldAdapterEvent OnGetFieldAdapter = {read=FOnGetFieldAdapter, write=FOnGetFieldAdapter};
	__property TcxSchedulerConnectionGridViewDblClickEvent OnGridViewDblClick = {read=FOnGridViewDblClick, write=FOnGridViewDblClick};
	__property TcxSchedulerInitializeGridItemEvent OnInitializeItem = {read=FOnInitializeItem, write=FOnInitializeItem};
	__property TcxSchedulerConnectionInitEditDialogEvent OnInitEditDialog = {read=FOnInitEditDialog, write=FOnInitEditDialog};
	__property TcxSchedulerConnectionNewEventEvent OnNewEvent = {read=FOnNewEvent, write=FOnNewEvent};
private:
	void *__IcxSchedulerStorageListener;	/* Cxschedulerstorage::IcxSchedulerStorageListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {87E0EBF3-F68A-4A51-8EA3-850D3819FBAB}
	operator Cxschedulerstorage::_di_IcxSchedulerStorageListener()
	{
		Cxschedulerstorage::_di_IcxSchedulerStorageListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulerstorage::IcxSchedulerStorageListener*(void) { return (Cxschedulerstorage::IcxSchedulerStorageListener*)&__IcxSchedulerStorageListener; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxSchedulerStorageListener; }
	#endif
	
};


enum TcxSchedulerGridBuildInPopupMenuItem : unsigned char { bpmiNewEvent, bpmiNewAllDayEvent, bpmiNewReccuringEvent, bpmiOpen, bpmiEditSeries, bpmiShowTimeAs, bpmiLabel, bpmiDelete };

typedef System::Set<TcxSchedulerGridBuildInPopupMenuItem, TcxSchedulerGridBuildInPopupMenuItem::bpmiNewEvent, TcxSchedulerGridBuildInPopupMenuItem::bpmiDelete>  TcxSchedulerGridBuildInPopupMenuItems;

typedef void __fastcall (__closure *TcxSchedulerGridBuildInPopupMenuPopupEvent)(TcxSchedulerGridBuildInPopupMenu* Sender, Vcl::Menus::TPopupMenu* ABuiltInMenu, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerGridBuildInPopupMenuClickEvent)(TcxSchedulerGridBuildInPopupMenu* Sender, TcxSchedulerGridBuildInPopupMenuItem AItem, int ASubItemIndex, bool &AHandled);

class PASCALIMPLEMENTATION TcxSchedulerGridBuildInPopupMenu : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxSchedulerGridBuildInPopupMenuItems FItems;
	TcxSchedulerGridConnection* FOwner;
	System::Classes::TComponent* FPopupMenu;
	bool FUseBuiltInPopupMenu;
	TcxSchedulerGridBuildInPopupMenuPopupEvent FOnPopup;
	TcxSchedulerGridBuildInPopupMenuClickEvent FOnClick;
	void __fastcall SetPopupMenu(System::Classes::TComponent* AValue);
	
protected:
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall TcxSchedulerGridBuildInPopupMenu(TcxSchedulerGridConnection* ASchedulerGridConnection);
	__fastcall virtual ~TcxSchedulerGridBuildInPopupMenu(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxSchedulerGridBuildInPopupMenuItems Items = {read=FItems, write=FItems, default=255};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property bool UseBuiltInPopupMenu = {read=FUseBuiltInPopupMenu, write=FUseBuiltInPopupMenu, default=1};
	__property TcxSchedulerGridBuildInPopupMenuClickEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TcxSchedulerGridBuildInPopupMenuPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerGridBuildInPopupMenuController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerEvent* FEvent;
	Cxgridpopupmenu::TcxGridPopupMenu* FGridPopupMenu;
	Vcl::Menus::TPopupMenu* FInternalMenu;
	Cxgridcustompopupmenu::TcxPopupMenuInfo* FMenuInfo;
	TcxSchedulerGridConnection* FOwner;
	bool __fastcall CanEventEdit(void);
	void __fastcall CreateLabelItems(void);
	void __fastcall CreateTimeItems(void);
	void __fastcall DeleteEvent(void);
	void __fastcall EditEvent(void);
	void __fastcall EditSeries(void);
	TcxSchedulerGridBuildInPopupMenu* __fastcall GetBuildInPopupMenu(void);
	int __fastcall GetCommand(TcxSchedulerGridBuildInPopupMenuItem AItem, int ASubItemIndex);
	TcxSchedulerGridBuildInPopupMenuItems __fastcall GetItems(void);
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	void __fastcall GridMenuPopup(System::Classes::TComponent* ASenderMenu, Cxgridcustomview::TcxCustomGridHitTest* AHitTest, int X, int Y);
	bool __fastcall IsEventsReadOnly(void);
	void __fastcall NewAllDayEvent(void);
	void __fastcall NewEvent(void);
	void __fastcall NewRecurrence(void);
	void __fastcall SetEvent(void);
	void __fastcall SetEventLabelColor(int AColor);
	void __fastcall SetEventState(int AState);
	void __fastcall UnpackCommand(int ACommand, /* out */ TcxSchedulerGridBuildInPopupMenuItem &AItem, /* out */ int &ASubItemIndex);
	
protected:
	Vcl::Menus::TMenuItem* __fastcall AddValidSeparator(Vcl::Menus::TMenuItem* AOwner);
	void __fastcall CreateInternalMenu(void);
	void __fastcall CreateItems(void);
	Vcl::Menus::TMenuItem* __fastcall CreateSubItem(Vcl::Menus::TMenuItem* AOwner, const System::UnicodeString ACaption, int ACommand = 0xffffffff, int AImageIndex = 0xffffffff, bool AEnabled = true, bool AChecked = false);
	bool __fastcall DoOnClick(int ACommand);
	bool __fastcall DoOnPopup(void);
	bool __fastcall IsValidCommand(int ACommand);
	void __fastcall OnItemClickHandler(System::TObject* Sender);
	__property TcxSchedulerGridBuildInPopupMenu* BuildInPopupMenu = {read=GetBuildInPopupMenu};
	__property TcxSchedulerGridBuildInPopupMenuItems Items = {read=GetItems, nodefault};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	
public:
	__fastcall TcxSchedulerGridBuildInPopupMenuController(TcxSchedulerGridConnection* ASchedulerGridConnection);
	__fastcall virtual ~TcxSchedulerGridBuildInPopupMenuController(void);
	bool __fastcall Popup(int X, int Y);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulercxgridconnection */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERCXGRIDCONNECTION)
using namespace Cxschedulercxgridconnection;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulercxgridconnectionHPP
