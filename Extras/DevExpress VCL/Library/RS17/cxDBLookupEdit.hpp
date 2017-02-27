// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDBLookupEdit.pas' rev: 24.00 (Win32)

#ifndef CxdblookupeditHPP
#define CxdblookupeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxDB.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxLookupEdit.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdblookupedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomDBLookupEditLookupData;
class DELPHICLASS TcxCustomDBLookupEditProperties;
class PASCALIMPLEMENTATION TcxCustomDBLookupEditLookupData : public Cxlookupedit::TcxCustomLookupEditLookupData
{
	typedef Cxlookupedit::TcxCustomLookupEditLookupData inherited;
	
private:
	HIDESBASE Cxdbdata::TcxDBDataController* __fastcall GetDataController(void);
	HIDESBASE TcxCustomDBLookupEditProperties* __fastcall GetProperties(void);
	
protected:
	virtual void __fastcall DoSetCurrentKey(int ARecordIndex);
	virtual void __fastcall DoSyncGrid(void);
	__property Cxdbdata::TcxDBDataController* DataController = {read=GetDataController};
	__property TcxCustomDBLookupEditProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomLookupEditLookupData.Create */ inline __fastcall virtual TcxCustomDBLookupEditLookupData(System::Classes::TPersistent* AOwner) : Cxlookupedit::TcxCustomLookupEditLookupData(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomDBLookupEditLookupData(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomDBLookupEditProperties : public Cxlookupedit::TcxCustomLookupEditProperties
{
	typedef Cxlookupedit::TcxCustomLookupEditProperties inherited;
	
private:
	Data::Db::TDataSource* FCachedLookupSource;
	bool FCaseSensitiveSearch;
	int FLockGridModeCount;
	Data::Db::TField* FLookupField;
	Cxdatastorage::TcxLookupList* FLookupList;
	Data::Db::TDataSource* FLookupSource;
	Dxcoreclasses::TcxFreeNotificator* FLookupSourceFreeNotificator;
	bool FSyncLookup;
	bool __fastcall GetIsUseLookupList(void);
	System::UnicodeString __fastcall GetKeyFieldNames(void);
	Data::Db::TField* __fastcall GetListField(void);
	int __fastcall GetListFieldIndex(void);
	System::UnicodeString __fastcall GetListFieldNames(void);
	void __fastcall SetIsUseLookupList(bool Value);
	void __fastcall SetKeyFieldNames(const System::UnicodeString Value);
	void __fastcall SetListFieldIndex(int Value);
	void __fastcall SetListFieldNames(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall DBLookupGridBeginUpdate(void);
	virtual void __fastcall DBLookupGridCheckColumnByFieldName(const System::UnicodeString AFieldName);
	virtual void __fastcall DBLookupGridCreateColumnsByFieldNames(const System::UnicodeString AFieldNames);
	virtual void __fastcall DBLookupGridEndUpdate(void);
	virtual Data::Db::TField* __fastcall GetDBLookupGridColumnField(int AIndex);
	virtual System::UnicodeString __fastcall GetDBLookupGridColumnFieldName(int AIndex);
	virtual int __fastcall GetDBLookupGridColumnIndexByFieldName(const System::UnicodeString AFieldName);
	virtual Cxdbdata::TcxDBDataController* __fastcall GetDBLookupGridDataController(void);
	bool __fastcall CanDisplayArbitraryEditValue(void);
	virtual void __fastcall CheckLookup(void);
	virtual void __fastcall CheckLookupColumn(void);
	void __fastcall CheckLookupList(void);
	virtual void __fastcall DefaultValuesProviderDestroyed(void);
	void __fastcall DefineByLookupError(void);
	virtual void __fastcall DoChanged(void);
	virtual int __fastcall FindByText(int AItemIndex, const System::UnicodeString AText, bool APartialCompare);
	virtual int __fastcall GetDisplayColumnIndex(void);
	virtual System::UnicodeString __fastcall GetDisplayLookupText(const System::Variant &AKey);
	virtual System::Classes::TAlignment __fastcall GetDefaultHorzAlignment(void);
	virtual int __fastcall GetDefaultMaxLength(void);
	virtual bool __fastcall GetIncrementalFiltering(void);
	System::Variant __fastcall GetKeyByRecordIndex(int ARecordIndex);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	System::UnicodeString __fastcall GetLookupResultFieldName(void);
	virtual System::Variant __fastcall GetNullKey(void);
	int __fastcall GetRecordIndexByKey(const System::Variant &AKey);
	virtual bool __fastcall IsPickMode(void);
	virtual void __fastcall LockDataChanged(void);
	virtual void __fastcall LookupSourceFreeNotification(System::Classes::TComponent* Sender);
	virtual void __fastcall SetDisplayColumnIndex(int Value);
	void __fastcall SetLookupField(Data::Db::TField* ALookupField);
	virtual void __fastcall UnlockDataChanged(void);
	__property bool InSyncLookup = {read=FSyncLookup, nodefault};
	__property bool IsUseLookupList = {read=GetIsUseLookupList, write=SetIsUseLookupList, nodefault};
	
public:
	__fastcall virtual ~TcxCustomDBLookupEditProperties(void);
	virtual bool __fastcall AllowRepositorySharing(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	Data::Db::TField* __fastcall GetDataField(void);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	Data::Db::TField* __fastcall GetLookupField(void);
	virtual bool __fastcall IsLookupField(void);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	virtual void __fastcall RefreshNonShareable(void);
	__property bool CaseSensitiveSearch = {read=FCaseSensitiveSearch, write=FCaseSensitiveSearch, default=0};
	__property Cxdbdata::TcxDBDataController* DataController = {read=GetDBLookupGridDataController};
	__property System::UnicodeString KeyFieldNames = {read=GetKeyFieldNames, write=SetKeyFieldNames};
	__property Data::Db::TField* ListField = {read=GetListField};
	__property System::UnicodeString ListFieldNames = {read=GetListFieldNames, write=SetListFieldNames, stored=false};
	__property int ListFieldIndex = {read=GetListFieldIndex, write=SetListFieldIndex, default=0};
public:
	/* TcxCustomLookupEditProperties.Create */ inline __fastcall virtual TcxCustomDBLookupEditProperties(System::Classes::TPersistent* AOwner) : Cxlookupedit::TcxCustomLookupEditProperties(AOwner) { }
	
};


class DELPHICLASS TcxCustomDBLookupEdit;
class PASCALIMPLEMENTATION TcxCustomDBLookupEdit : public Cxlookupedit::TcxCustomLookupEdit
{
	typedef Cxlookupedit::TcxCustomLookupEdit inherited;
	
private:
	HIDESBASE TcxCustomDBLookupEditProperties* __fastcall GetProperties(void);
	HIDESBASE TcxCustomDBLookupEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomDBLookupEditProperties* Value);
	
protected:
	virtual System::Variant __fastcall GetClearValue(void);
	virtual bool __fastcall IsValidChar(System::WideChar AChar);
	virtual System::Variant __fastcall ItemIndexToLookupKey(int AItemIndex);
	virtual System::Variant __fastcall LookupKeyToEditValue(const System::Variant &AKey);
	virtual int __fastcall LookupKeyToItemIndex(const System::Variant &AKey);
	DYNAMIC void __fastcall PopupWindowClosed(System::TObject* Sender);
	virtual void __fastcall PrepareDisplayValue(const System::Variant &AEditValue, System::Variant &DisplayValue, bool AEditFocused);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxCustomDBLookupEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property TcxCustomDBLookupEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomDropDownEdit.Destroy */ inline __fastcall virtual ~TcxCustomDBLookupEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomDBLookupEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxlookupedit::TcxCustomLookupEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomDBLookupEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxlookupedit::TcxCustomLookupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDBLookupEdit(HWND ParentWindow) : Cxlookupedit::TcxCustomLookupEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDBLookupEditDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBLookupEditDataBinding : public Cxdbedit::TcxDBTextEditDataBinding
{
	typedef Cxdbedit::TcxDBTextEditDataBinding inherited;
	
protected:
	virtual bool __fastcall IsLookupControl(void);
public:
	/* TcxDBEditDataBinding.Create */ inline __fastcall virtual TcxDBLookupEditDataBinding(Cxedit::TcxCustomEdit* AEdit) : Cxdbedit::TcxDBTextEditDataBinding(AEdit) { }
	/* TcxDBEditDataBinding.Destroy */ inline __fastcall virtual ~TcxDBLookupEditDataBinding(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall IsLinkedToDataSet(Data::Db::TDataSource* ADataSource, Data::Db::TDataSet* ADataSet);
}	/* namespace Cxdblookupedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDBLOOKUPEDIT)
using namespace Cxdblookupedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdblookupeditHPP
