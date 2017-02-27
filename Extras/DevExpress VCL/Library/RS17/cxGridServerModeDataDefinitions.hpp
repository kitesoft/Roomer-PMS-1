// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridServerModeDataDefinitions.pas' rev: 24.00 (Win32)

#ifndef CxgridservermodedatadefinitionsHPP
#define CxgridservermodedatadefinitionsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBEdit.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridservermodedatadefinitions
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridServerModeDefaultValuesProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridServerModeDefaultValuesProvider : public Cxdbedit::TcxCustomDBEditDefaultValuesProvider
{
	typedef Cxdbedit::TcxCustomDBEditDefaultValuesProvider inherited;
	
private:
	System::UnicodeString FFieldName;
	
public:
	virtual bool __fastcall CanSetEditMode(void);
	virtual bool __fastcall DefaultCanModify(void);
	virtual bool __fastcall IsDataAvailable(void);
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
	__property System::UnicodeString FieldName = {read=FFieldName, write=FFieldName};
public:
	/* TcxCustomDBEditDefaultValuesProvider.Create */ inline __fastcall virtual TcxGridServerModeDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Cxdbedit::TcxCustomDBEditDefaultValuesProvider(AOwner) { }
	/* TcxCustomDBEditDefaultValuesProvider.Destroy */ inline __fastcall virtual ~TcxGridServerModeDefaultValuesProvider(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridServerModeDataController;
class PASCALIMPLEMENTATION TcxGridServerModeDataController : public Dxservermodedata::TdxServerModeDataController
{
	typedef Dxservermodedata::TdxServerModeDataController inherited;
	
private:
	int FPrevScrollBarPos;
	Cxgridcustomtableview::TcxCustomGridTableController* __fastcall GetController(void);
	Cxgridcustomtableview::TcxCustomGridTableView* __fastcall GetGridViewValue(void);
	
protected:
	void __fastcall AssignData(Cxcustomdata::TcxCustomDataController* ADataController);
	void __fastcall DeleteAllItems(void);
	void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetGridView(void);
	bool __fastcall HasAllItems(void);
	bool __fastcall IsDataChangeable(void);
	bool __fastcall IsDataLinked(void);
	bool __fastcall SupportsCreateAllItems(void);
	void __fastcall CheckGridModeBufferCount(void);
	bool __fastcall DoScroll(bool AForward);
	bool __fastcall DoScrollPage(bool AForward);
	Cxgridcustomtableview::TcxGridItemDataBindingClass __fastcall GetItemDataBindingClass(void);
	Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetItemDefaultValuesProviderClass(void);
	bool __fastcall GetNavigatorIsBof(void);
	bool __fastcall GetNavigatorIsEof(void);
	int __fastcall GetScrollBarPos(void);
	int __fastcall GetScrollBarRecordCount(void);
	bool __fastcall SetScrollBarPos(int Value);
	virtual bool __fastcall CanSelectRow(int ARowIndex);
	virtual int __fastcall CompareByField(int ARecordIndex1, int ARecordIndex2, Cxcustomdata::TcxCustomDataField* AField, Cxcustomdata::TcxDataControllerComparisonMode AMode);
	void __fastcall DoDataSetCurrentChanged(bool AIsCurrent);
	void __fastcall DoDataSourceChanged(void);
	virtual void __fastcall DoValueTypeClassChanged(int AItemIndex);
	virtual void __fastcall FilterChanged(void);
	virtual int __fastcall GetDefaultActiveRelationIndex(void);
	int __fastcall GetDefaultGridModeBufferCount(void);
	virtual void __fastcall InitializeDescriptor(Cxcustomdata::TcxCustomDataField* AField, Dxservermodedata::TdxServerModeDescriptor* &ADescriptor);
	virtual System::UnicodeString __fastcall GetFilterDisplayText(int ARecordIndex, int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual Cxcustomdata::TcxSortingBySummaryEngineClass __fastcall GetSortingBySummaryEngineClass(void);
	virtual Cxcustomdata::TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	virtual void __fastcall PopulateFilterValues(Cxcustomdata::TcxDataFilterValueList* AList, int AItemIndex, Cxfilter::TcxFilterCriteria* ACriteria, bool &AUseFilteredRecords, /* out */ bool &ANullExists);
	virtual bool __fastcall SupportsScrollBarParams(void);
	virtual bool __fastcall SyncDetailsFocusWithMaster(void);
	void __fastcall UpdateScrollBars(void);
	
public:
	virtual void __fastcall BeginFullUpdate(void);
	virtual void __fastcall EndFullUpdate(void);
	virtual System::TObject* __fastcall CreateDetailLinkObject(Cxcustomdata::TcxCustomDataRelation* ARelation, int ARecordIndex);
	virtual void __fastcall FocusControl(int AItemIndex, bool &Done);
	virtual Cxcustomdata::TcxCustomDataController* __fastcall GetDetailDataControllerByLinkObject(System::TObject* ALinkObject);
	virtual System::UnicodeString __fastcall GetDisplayText(int ARecordIndex, int AItemIndex);
	virtual System::Variant __fastcall GetFilterDataValue(int ARecordIndex, Cxcustomdata::TcxCustomDataField* AField);
	virtual System::UnicodeString __fastcall GetFilterItemFieldCaption(System::TObject* AItem);
	virtual System::TObject* __fastcall GetItem(int Index);
	virtual bool __fastcall GetItemSortByDisplayText(int AItemIndex, bool ASortByDisplayText);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual void __fastcall UpdateData(void);
	void __fastcall CreateAllItems(bool AMissingItemsOnly = false);
	HIDESBASE Cxgridcustomtableview::TcxCustomGridTableItem* __fastcall GetItemByFieldName(const System::UnicodeString AFieldName);
	__property Cxgridcustomtableview::TcxCustomGridTableController* Controller = {read=GetController};
	__property Cxgridcustomtableview::TcxCustomGridTableView* GridView = {read=GetGridViewValue};
	
__published:
	__property DataSource;
	__property Filter;
	__property Options = {default=49};
	__property Summary;
	__property OnGroupingChanged;
	__property OnSortingChanged;
public:
	/* TdxServerModeDataController.Create */ inline __fastcall virtual TcxGridServerModeDataController(System::Classes::TComponent* AOwner) : Dxservermodedata::TdxServerModeDataController(AOwner) { }
	/* TdxServerModeDataController.Destroy */ inline __fastcall virtual ~TcxGridServerModeDataController(void) { }
	
private:
	void *__IcxGridDataController;	/* Cxgridcustomtableview::IcxGridDataController */
	void *__IcxCustomGridDataController;	/* Cxgridcustomview::IcxCustomGridDataController */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FEEE7E69-BD54-4B5D-BA0B-B6116B69C0CC}
	operator Cxgridcustomtableview::_di_IcxGridDataController()
	{
		Cxgridcustomtableview::_di_IcxGridDataController intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridcustomtableview::IcxGridDataController*(void) { return (Cxgridcustomtableview::IcxGridDataController*)&__IcxGridDataController; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B9ABDC6B-1A4A-4F11-A629-09B6FB9FB4BA}
	operator Cxgridcustomview::_di_IcxCustomGridDataController()
	{
		Cxgridcustomview::_di_IcxCustomGridDataController intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridcustomview::IcxCustomGridDataController*(void) { return (Cxgridcustomview::IcxCustomGridDataController*)&__IcxCustomGridDataController; }
	#endif
	
};


class DELPHICLASS TcxGridItemServerModeDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridItemServerModeDataBinding : public Cxgridcustomtableview::TcxGridItemDataBinding
{
	typedef Cxgridcustomtableview::TcxGridItemDataBinding inherited;
	
private:
	HIDESBASE TcxGridServerModeDataController* __fastcall GetDataController(void);
	Data::Db::TField* __fastcall GetField(void);
	System::UnicodeString __fastcall GetFieldName(void);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	
protected:
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetDefaultValueTypeClass(void);
	virtual System::UnicodeString __fastcall GetFilterFieldName(void);
	virtual void __fastcall Init(void);
	virtual bool __fastcall IsValueTypeStored(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual int __fastcall DefaultWidth(bool ATakeHeaderIntoAccount = true);
	__property TcxGridServerModeDataController* DataController = {read=GetDataController};
	__property Data::Db::TField* Field = {read=GetField};
	
__published:
	__property System::UnicodeString FieldName = {read=GetFieldName, write=SetFieldName};
public:
	/* TcxGridItemDataBinding.Create */ inline __fastcall virtual TcxGridItemServerModeDataBinding(Cxgridcustomtableview::TcxCustomGridTableItem* AItem) : Cxgridcustomtableview::TcxGridItemDataBinding(AItem) { }
	/* TcxGridItemDataBinding.Destroy */ inline __fastcall virtual ~TcxGridItemServerModeDataBinding(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridservermodedatadefinitions */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDSERVERMODEDATADEFINITIONS)
using namespace Cxgridservermodedatadefinitions;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridservermodedatadefinitionsHPP
