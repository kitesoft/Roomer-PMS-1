// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDB.pas' rev: 24.00 (Win32)

#ifndef CxdbHPP
#define CxdbHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Generics.Collections.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <System.Generics.Defaults.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdb
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TDataSetClass;

class DELPHICLASS TcxDBAdapterItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBAdapterItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TDataSetClass FDataSetClass;
	
public:
	__fastcall virtual TcxDBAdapterItem(TDataSetClass ADataSetClass);
	__property TDataSetClass DataSetClass = {read=FDataSetClass};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDBAdapterItem(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDBAdapterItemClass;

class DELPHICLASS TcxDBAdapterList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDBAdapterList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxDBAdapterItem* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TList* FItems;
	TcxDBAdapterItem* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	
public:
	__fastcall TcxDBAdapterList(void);
	__fastcall virtual ~TcxDBAdapterList(void);
	void __fastcall Clear(void);
	virtual bool __fastcall FindAdapter(TDataSetClass ADataSetClass, int &AIndex);
	virtual void __fastcall RegisterAdapter(TDataSetClass ADataSetClass, TcxDBAdapterItemClass AItemClass);
	virtual void __fastcall UnregisterAdapter(TDataSetClass ADataSetClass, TcxDBAdapterItemClass AItemClass);
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxDBAdapterItem* Items[int Index] = {read=GetItem/*, default*/};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomFieldDataLink;
class DELPHICLASS TcxCustomDBDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomFieldDataLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	Data::Db::TField* FField;
	System::UnicodeString FFieldName;
	bool FEditing;
	bool FModified;
	bool __fastcall GetCanModify(void);
	System::Classes::TComponent* __fastcall GetDataComponent(void);
	HIDESBASE void __fastcall SetEditing(bool Value);
	void __fastcall SetField(Data::Db::TField* Value);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	void __fastcall UpdateField(void);
	
protected:
	TcxCustomDBDataBinding* FDataBinding;
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataEvent(Data::Db::TDataEvent Event, NativeInt Info);
	virtual void __fastcall EditingChanged(void);
	virtual void __fastcall LayoutChanged(void);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall DataComponentChanged(void);
	virtual void __fastcall UpdateRightToLeft(void);
	virtual void __fastcall VisualControlChanged(void);
	__property TcxCustomDBDataBinding* DataBinding = {read=FDataBinding};
	__property System::Classes::TComponent* DataComponent = {read=GetDataComponent};
	
public:
	__fastcall virtual TcxCustomFieldDataLink(TcxCustomDBDataBinding* ADataBinding);
	HIDESBASE bool __fastcall Edit(void);
	void __fastcall Modified(void);
	void __fastcall Reset(void);
	__property bool CanModify = {read=GetCanModify, nodefault};
	__property bool Editing = {read=FEditing, nodefault};
	__property Data::Db::TField* Field = {read=FField};
	__property System::UnicodeString FieldName = {read=FFieldName, write=SetFieldName};
public:
	/* TDataLink.Destroy */ inline __fastcall virtual ~TcxCustomFieldDataLink(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomFieldDataLinkClass;

class PASCALIMPLEMENTATION TcxCustomDBDataBinding : public Cxdatautils::TcxCustomDataBinding
{
	typedef Cxdatautils::TcxCustomDataBinding inherited;
	
private:
	int FRefreshCount;
	System::UnicodeString __fastcall GetDataField(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	Data::Db::TField* __fastcall GetField(void);
	void __fastcall InternalDataChange(void);
	void __fastcall SetDataField(const System::UnicodeString Value);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	
protected:
	TcxCustomFieldDataLink* FDataLink;
	virtual bool __fastcall GetModified(void);
	virtual bool __fastcall GetReadOnly(void);
	virtual void __fastcall SetReadOnly(bool Value);
	virtual void __fastcall VisualControlChanged(void);
	void __fastcall DisableRefresh(void);
	void __fastcall EnableRefresh(void);
	virtual TcxCustomFieldDataLinkClass __fastcall GetDataLinkClass(void);
	bool __fastcall IsRefreshDisabled(void);
	
public:
	__fastcall virtual TcxCustomDBDataBinding(System::Classes::TComponent* AOwner, System::Classes::TComponent* ADataComponent);
	__fastcall virtual ~TcxCustomDBDataBinding(void);
	virtual bool __fastcall CanModify(void);
	virtual bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual System::Variant __fastcall GetStoredValue(Cxdatautils::TcxDataEditValueSource AValueSource, bool AFocused);
	virtual bool __fastcall IsControlReadOnly(void);
	virtual bool __fastcall IsDataSourceLive(void);
	virtual bool __fastcall IsDataStorage(void);
	virtual void __fastcall Reset(void);
	virtual bool __fastcall SetEditMode(void);
	virtual void __fastcall SetStoredValue(Cxdatautils::TcxDataEditValueSource AValueSource, const System::Variant &Value);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall UpdateDataSource(void);
	__property Data::Db::TField* Field = {read=GetField};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property System::UnicodeString DataField = {read=GetDataField, write=SetDataField};
	__property TcxCustomFieldDataLink* DataLink = {read=FDataLink};
};


class DELPHICLASS TcxDBDataBinding;
class PASCALIMPLEMENTATION TcxDBDataBinding : public TcxCustomDBDataBinding
{
	typedef TcxCustomDBDataBinding inherited;
	
__published:
	__property DataSource;
	__property DataField = {default=0};
public:
	/* TcxCustomDBDataBinding.Create */ inline __fastcall virtual TcxDBDataBinding(System::Classes::TComponent* AOwner, System::Classes::TComponent* ADataComponent) : TcxCustomDBDataBinding(AOwner, ADataComponent) { }
	/* TcxCustomDBDataBinding.Destroy */ inline __fastcall virtual ~TcxDBDataBinding(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall CanModifyLookupField(Data::Db::TField* AField);
extern PACKAGE void __fastcall CheckFilterFieldName(System::UnicodeString &AFieldName);
extern PACKAGE System::Variant __fastcall GetDataSetValues(Data::Db::TDataSet* ADataSet, System::Classes::TList* AFields);
extern PACKAGE System::UnicodeString __fastcall GetFilterFieldName(Data::Db::TField* AField, bool AIgnoreOrigin);
extern PACKAGE bool __fastcall IsDataAvailable(Data::Db::TField* AField);
extern PACKAGE bool __fastcall IsEqualFieldNames(const System::UnicodeString AFieldName1, const System::UnicodeString AFieldName2);
extern PACKAGE bool __fastcall IsFieldCanModify(Data::Db::TField* AField, bool AIsValueSource);
extern PACKAGE bool __fastcall IsFieldFormatted(Data::Db::TField* AField, bool AIsTextEdit);
extern PACKAGE bool __fastcall IsMultipleFieldNames(const System::UnicodeString AFieldNames);
extern PACKAGE bool __fastcall IsSimpleCurrencyField(Data::Db::TField* AField);
extern PACKAGE int __fastcall GetFieldNamesCount(const System::UnicodeString AFieldNames);
extern PACKAGE void __fastcall GetFieldNames(const System::UnicodeString AFieldNames, System::Classes::TStrings* AList);
extern PACKAGE System::Variant __fastcall GetFieldValue(Data::Db::TField* AField);
extern PACKAGE void __fastcall SetDataSetValues(Data::Db::TDataSet* ADataSet, System::Classes::TList* AFields, const System::Variant &AValues);
extern PACKAGE void __fastcall SetFieldValue(Data::Db::TField* AField, const System::Variant &AValue);
}	/* namespace Cxdb */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDB)
using namespace Cxdb;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdbHPP
