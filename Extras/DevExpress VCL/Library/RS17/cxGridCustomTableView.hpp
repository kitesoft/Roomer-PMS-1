// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridCustomTableView.pas' rev: 24.00 (Win32)

#ifndef CxgridcustomtableviewHPP
#define CxgridcustomtableviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxFilterControl.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridcustomtableview
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridItemDataBindingClass;

typedef System::TMetaClass* TcxCustomGridRecordViewInfoClass;

class DELPHICLASS TcxGridDataChange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDataChange : public Cxgridcustomview::TcxCustomGridViewChange
{
	typedef Cxgridcustomview::TcxCustomGridViewChange inherited;
	
public:
	virtual void __fastcall Execute(void);
	virtual bool __fastcall IsLockable(void);
public:
	/* TcxCustomGridViewChange.Create */ inline __fastcall virtual TcxGridDataChange(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridViewChange(AGridView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDataChange(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridRecordChange;
class DELPHICLASS TcxCustomGridTableItem;
class DELPHICLASS TcxCustomGridRecord;
class DELPHICLASS TcxCustomGridTableView;
class DELPHICLASS TcxCustomGridRecordViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridRecordChange : public Cxgridcustomview::TcxCustomGridViewChange
{
	typedef Cxgridcustomview::TcxCustomGridViewChange inherited;
	
private:
	TcxCustomGridTableItem* FItem;
	TcxCustomGridRecord* FRecord;
	int FRecordIndex;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	TcxCustomGridRecordViewInfo* __fastcall GetRecordViewInfo(void);
	
public:
	__fastcall virtual TcxGridRecordChange(Cxgridcustomview::TcxCustomGridView* AGridView, TcxCustomGridRecord* ARecord, int ARecordIndex, TcxCustomGridTableItem* AItem);
	virtual void __fastcall Execute(void);
	virtual bool __fastcall IsCompatibleWith(Cxgridcommon::TcxCustomGridChange* AChange);
	virtual bool __fastcall IsEqual(Cxgridcommon::TcxCustomGridChange* AChange);
	bool __fastcall IsItemVisible(void);
	__property TcxCustomGridRecord* GridRecord = {read=FRecord};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridTableItem* Item = {read=FItem};
	__property int RecordIndex = {read=FRecordIndex, nodefault};
	__property TcxCustomGridRecordViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridRecordChange(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFocusedRecordChange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFocusedRecordChange : public Cxgridcustomview::TcxCustomGridViewChange
{
	typedef Cxgridcustomview::TcxCustomGridViewChange inherited;
	
private:
	int FFocusedDataRecordIndex;
	int FFocusedRecordIndex;
	bool FNewItemRecordFocusingChanged;
	int FPrevFocusedDataRecordIndex;
	int FPrevFocusedRecordIndex;
	
public:
	__fastcall virtual TcxGridFocusedRecordChange(Cxgridcustomview::TcxCustomGridView* AGridView, int APrevFocusedRecordIndex, int AFocusedRecordIndex, int APrevFocusedDataRecordIndex, int AFocusedDataRecordIndex, bool ANewItemRecordFocusingChanged);
	virtual bool __fastcall CanExecuteWhenLocked(void);
	virtual void __fastcall Execute(void);
	__property int FocusedRecordIndex = {read=FFocusedRecordIndex, nodefault};
	__property bool NewItemRecordFocusingChanged = {read=FNewItemRecordFocusingChanged, nodefault};
	__property int PrevFocusedRecordIndex = {read=FPrevFocusedRecordIndex, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFocusedRecordChange(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridFilterHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridFilterHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterCloseButtonHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterCloseButtonHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridFilterCloseButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridFilterCloseButtonHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterActivateButtonHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterActivateButtonHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridFilterActivateButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridFilterActivateButtonHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterDropDownButtonHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterDropDownButtonHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridFilterDropDownButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridFilterDropDownButtonHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterCustomizeButtonHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterCustomizeButtonHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridFilterCustomizeButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridFilterCustomizeButtonHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridRecordHitTest;
class DELPHICLASS TcxCustomGridTableViewData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridRecordHitTest : public Cxgridcustomview::TcxCustomGridViewHitTest
{
	typedef Cxgridcustomview::TcxCustomGridViewHitTest inherited;
	
private:
	int FGridRecordIndex;
	int FGridRecordKind;
	TcxCustomGridTableViewData* FViewData;
	TcxCustomGridRecord* __fastcall GetGridRecord(void);
	void __fastcall SetGridRecord(TcxCustomGridRecord* Value);
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__classmethod virtual bool __fastcall CanClick();
	__property TcxCustomGridRecord* GridRecord = {read=GetGridRecord, write=SetGridRecord};
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridRecordHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridRecordHitTest(void) : Cxgridcustomview::TcxCustomGridViewHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridRecordCellHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridRecordCellHitTest : public TcxGridRecordHitTest
{
	typedef TcxGridRecordHitTest inherited;
	
protected:
	virtual void __fastcall Assign(Cxgridcustomview::TcxCustomGridHitTest* Source);
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	TcxCustomGridTableItem* Item;
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridRecordCellHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridRecordCellHitTest(void) : TcxGridRecordHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridExpandButtonHitTest;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridExpandButtonHitTest : public TcxGridRecordHitTest
{
	typedef TcxGridRecordHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__classmethod virtual bool __fastcall CanClick();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridExpandButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridExpandButtonHitTest(void) : TcxGridRecordHitTest() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridDefaultValuesProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDefaultValuesProvider : public Cxedit::TcxCustomEditDefaultValuesProvider
{
	typedef Cxedit::TcxCustomEditDefaultValuesProvider inherited;
	
public:
	virtual bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
public:
	/* TcxCustomEditDefaultValuesProvider.Destroy */ inline __fastcall virtual ~TcxGridDefaultValuesProvider(void) { }
	
public:
	/* TcxInterfacedPersistent.Create */ inline __fastcall virtual TcxGridDefaultValuesProvider(System::Classes::TPersistent* AOwner) : Cxedit::TcxCustomEditDefaultValuesProvider(AOwner) { }
	
};

#pragma pack(pop)

__interface IcxGridDataController;
typedef System::DelphiInterface<IcxGridDataController> _di_IcxGridDataController;
__interface  INTERFACE_UUID("{FEEE7E69-BD54-4B5D-BA0B-B6116B69C0CC}") IcxGridDataController  : public System::IInterface 
{
	
public:
	virtual void __fastcall CheckGridModeBufferCount(void) = 0 ;
	virtual bool __fastcall DoScroll(bool AForward) = 0 ;
	virtual bool __fastcall DoScrollPage(bool AForward) = 0 ;
	virtual TcxGridItemDataBindingClass __fastcall GetItemDataBindingClass(void) = 0 ;
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetItemDefaultValuesProviderClass(void) = 0 ;
	virtual bool __fastcall GetNavigatorIsBof(void) = 0 ;
	virtual bool __fastcall GetNavigatorIsEof(void) = 0 ;
	virtual int __fastcall GetScrollBarPos(void) = 0 ;
	virtual int __fastcall GetScrollBarRecordCount(void) = 0 ;
	virtual bool __fastcall SetScrollBarPos(int Value) = 0 ;
};

class DELPHICLASS TcxGridDataController;
class PASCALIMPLEMENTATION TcxGridDataController : public Cxdata::TcxDataController
{
	typedef Cxdata::TcxDataController inherited;
	
private:
	System::Classes::TMemoryStream* FLoadedData;
	TcxCustomGridTableView* __fastcall GetGridViewValue(void);
	void __fastcall ReadData(System::Classes::TStream* Stream);
	void __fastcall WriteData(System::Classes::TStream* Stream);
	
protected:
	void __fastcall AssignData(Cxcustomdata::TcxCustomDataController* ADataController);
	void __fastcall CreateAllItems(bool AMissingItemsOnly);
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
	TcxGridItemDataBindingClass __fastcall GetItemDataBindingClass(void);
	Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetItemDefaultValuesProviderClass(void);
	bool __fastcall GetNavigatorIsBof(void);
	bool __fastcall GetNavigatorIsEof(void);
	int __fastcall GetScrollBarPos(void);
	int __fastcall GetScrollBarRecordCount(void);
	bool __fastcall SetScrollBarPos(int Value);
	virtual bool __fastcall CanSelectRow(int ARowIndex);
	virtual int __fastcall CompareByField(int ARecordIndex1, int ARecordIndex2, Cxcustomdata::TcxCustomDataField* AField, Cxcustomdata::TcxDataControllerComparisonMode AMode);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoValueTypeClassChanged(int AItemIndex);
	virtual void __fastcall FilterChanged(void);
	virtual int __fastcall GetDefaultActiveRelationIndex(void);
	virtual System::UnicodeString __fastcall GetFilterDisplayText(int ARecordIndex, int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual Cxcustomdata::TcxSortingBySummaryEngineClass __fastcall GetSortingBySummaryEngineClass(void);
	virtual Cxcustomdata::TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	
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
	virtual void __fastcall Loaded(void);
	virtual void __fastcall UpdateData(void);
	__property TcxCustomGridTableView* GridView = {read=GetGridViewValue};
	
__published:
	__property Filter;
	__property Options = {default=28};
	__property Summary;
	__property OnAfterCancel;
	__property OnAfterDelete;
	__property OnAfterInsert;
	__property OnAfterPost;
	__property OnBeforeCancel;
	__property OnBeforeDelete;
	__property OnBeforeInsert;
	__property OnBeforePost;
	__property OnNewRecord;
	__property OnCompare;
	__property OnDataChanged;
	__property OnDetailCollapsing;
	__property OnDetailCollapsed;
	__property OnDetailExpanding;
	__property OnDetailExpanded;
	__property OnFilterRecord;
	__property OnGroupingChanged;
	__property OnRecordChanged;
	__property OnSortingChanged;
public:
	/* TcxDataController.Create */ inline __fastcall virtual TcxGridDataController(System::Classes::TComponent* AOwner) : Cxdata::TcxDataController(AOwner) { }
	/* TcxDataController.Destroy */ inline __fastcall virtual ~TcxGridDataController(void) { }
	
private:
	void *__IcxGridDataController;	/* IcxGridDataController */
	void *__IcxCustomGridDataController;	/* Cxgridcustomview::IcxCustomGridDataController */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FEEE7E69-BD54-4B5D-BA0B-B6116B69C0CC}
	operator _di_IcxGridDataController()
	{
		_di_IcxGridDataController intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxGridDataController*(void) { return (IcxGridDataController*)&__IcxGridDataController; }
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


typedef System::TMetaClass* TcxGridFilterValueListClass;

class DELPHICLASS TcxGridFilterValueList;
class DELPHICLASS TcxCustomGridDateRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterValueList : public Cxcustomdata::TcxDataFilterValueList
{
	typedef Cxcustomdata::TcxDataFilterValueList inherited;
	
protected:
	virtual void __fastcall AddDateTimeAbsoluteFilters(TcxCustomGridDateRange* ADateRange, bool AIgnoreTime)/* overload */;
	virtual void __fastcall AddDateTimeAbsoluteFilters(TcxCustomGridTableItem* AItem)/* overload */;
	virtual void __fastcall AddDateTimeRelativeFilters(TcxCustomGridTableItem* AItem);
	virtual Cxfilter::TcxFilterOperatorKinds __fastcall SupportedSpecialOperatorKinds(void);
	
public:
	void __fastcall ApplyFilter(TcxCustomGridTableItem* AItem, int AIndex, Cxfilter::TcxFilterCriteriaItemList* AFilterList, bool AReplaceExistent, bool AAddToMRUItemsList);
	virtual int __fastcall GetIndexByCriteriaItem(Cxfilter::TcxFilterCriteriaItem* ACriteriaItem);
	HIDESBASE virtual void __fastcall Load(TcxCustomGridTableItem* AItem, bool AInitSortByDisplayText = true, bool AUseFilteredValues = false, bool AAddValueItems = true);
public:
	/* TcxFilterValueList.Create */ inline __fastcall virtual TcxGridFilterValueList(Cxfilter::TcxFilterCriteria* ACriteria) : Cxcustomdata::TcxDataFilterValueList(ACriteria) { }
	/* TcxFilterValueList.Destroy */ inline __fastcall virtual ~TcxGridFilterValueList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterMRUValueItem;
class PASCALIMPLEMENTATION TcxGridFilterMRUValueItem : public Cxclasses::TcxMRUItem
{
	typedef Cxclasses::TcxMRUItem inherited;
	
public:
	System::Variant Value;
	System::UnicodeString DisplayText;
	__fastcall TcxGridFilterMRUValueItem(const System::Variant &AValue, const System::UnicodeString ADisplayText);
	virtual bool __fastcall Equals(Cxclasses::TcxMRUItem* AItem);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFilterMRUValueItem(void) { }
	
};


typedef System::TMetaClass* TcxGridFilterMRUValueItemsClass;

class DELPHICLASS TcxGridFilterMRUValueItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterMRUValueItems : public Cxclasses::TcxMRUItems
{
	typedef Cxclasses::TcxMRUItems inherited;
	
public:
	TcxGridFilterMRUValueItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxGridFilterMRUValueItem* __fastcall GetItem(int Index);
	
public:
	HIDESBASE void __fastcall Add(const System::Variant &AValue, const System::UnicodeString ADisplayText);
	void __fastcall AddItemsTo(TcxGridFilterValueList* AValueList);
	__property TcxGridFilterMRUValueItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxMRUItems.Create */ inline __fastcall virtual TcxGridFilterMRUValueItems(void) : Cxclasses::TcxMRUItems() { }
	/* TcxMRUItems.Destroy */ inline __fastcall virtual ~TcxGridFilterMRUValueItems(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridItemDataBinding;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridItemDataBinding : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::TObject* FData;
	Cxedit::TcxCustomEditDefaultValuesProvider* FDefaultValuesProvider;
	TcxCustomGridTableItem* FItem;
	TcxGridFilterMRUValueItems* FFilterMRUValueItems;
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	Cxcustomdata::TcxDataFilterCriteria* __fastcall GetFilter(void);
	Cxfilter::TcxFilterCriteriaItem* __fastcall GetFilterCriteriaItem(void);
	bool __fastcall GetFiltered(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	System::UnicodeString __fastcall GetValueType(void);
	Cxdatastorage::TcxValueTypeClass __fastcall GetValueTypeClass(void);
	void __fastcall SetData(System::TObject* Value);
	void __fastcall SetFiltered(bool Value);
	void __fastcall SetValueType(const System::UnicodeString Value);
	void __fastcall SetValueTypeClass(Cxdatastorage::TcxValueTypeClass Value);
	
protected:
	Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetDefaultValueTypeClass(void);
	virtual System::UnicodeString __fastcall GetFilterFieldName(void);
	virtual TcxGridFilterMRUValueItemsClass __fastcall GetFilterMRUValueItemsClass(void);
	virtual void __fastcall Init(void);
	virtual bool __fastcall IsValueTypeStored(void);
	__property Cxedit::TcxCustomEditDefaultValuesProvider* DefaultValuesProvider = {read=FDefaultValuesProvider};
	
public:
	__fastcall virtual TcxGridItemDataBinding(TcxCustomGridTableItem* AItem);
	__fastcall virtual ~TcxGridItemDataBinding(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual int __fastcall DefaultWidth(bool ATakeHeaderIntoAccount = true);
	Cxcustomdata::TcxSummaryKinds __fastcall GetAllowedSummaryKinds(void);
	Cxedit::_di_IcxEditDefaultValuesProvider __fastcall GetDefaultValuesProvider(Cxedit::TcxCustomEditProperties* AProperties = (Cxedit::TcxCustomEditProperties*)(0x0));
	bool __fastcall IsDisplayFormatDefined(bool AIsCurrencyValueAccepted);
	Cxfilter::TcxFilterCriteriaItem* __fastcall AddToFilter(Cxfilter::TcxFilterCriteriaItemList* AParent, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, const System::UnicodeString ADisplayText = System::UnicodeString(), bool AReplaceExistent = true);
	void __fastcall GetFilterDisplayText(const System::Variant &AValue, System::UnicodeString &ADisplayText);
	void __fastcall GetFilterStrings(System::Classes::TStrings* AStrings, TcxGridFilterValueList* AValueList);
	void __fastcall GetFilterValues(TcxGridFilterValueList* AValueList, bool AValuesOnly = true, bool AInitSortByDisplayText = false, bool ACanUseFilteredValues = false);
	void __fastcall GetFilterActiveValueIndexes(TcxGridFilterValueList* AValueList, Cxgridcustomview::TcxGridIndexes &AIndexes);
	void __fastcall SetFilterActiveValueIndexes(TcxGridFilterValueList* AValueList, const Cxgridcustomview::TcxGridIndexes AIndexes);
	__property System::TObject* Data = {read=FData, write=SetData};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property Cxcustomdata::TcxDataFilterCriteria* Filter = {read=GetFilter};
	__property Cxfilter::TcxFilterCriteriaItem* FilterCriteriaItem = {read=GetFilterCriteriaItem};
	__property bool Filtered = {read=GetFiltered, write=SetFiltered, nodefault};
	__property System::UnicodeString FilterFieldName = {read=GetFilterFieldName};
	__property TcxGridFilterMRUValueItems* FilterMRUValueItems = {read=FFilterMRUValueItems};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridTableItem* Item = {read=FItem};
	__property Cxdatastorage::TcxValueTypeClass ValueTypeClass = {read=GetValueTypeClass, write=SetValueTypeClass};
	
__published:
	__property System::UnicodeString ValueType = {read=GetValueType, write=SetValueType, stored=IsValueTypeStored};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridDateRangeClass;

class DELPHICLASS TcxGridDateRanges;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridDateRange : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxGridDateRanges* FContainer;
	int __fastcall GetIndex(void);
	void __fastcall SetIndex(int Value);
	
public:
	__fastcall virtual ~TcxCustomGridDateRange(void);
	virtual bool __fastcall Contains(const System::TDateTime ADate) = 0 ;
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate) = 0 ;
	virtual System::Variant __fastcall GetRangeValue(const System::TDateTime ADate, bool AIgnoreTime);
	virtual System::Variant __fastcall GetSortingValue(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate) = 0 ;
	virtual bool __fastcall NeedsSortingByTime(void);
	virtual bool __fastcall NeedsTime(void);
	__property TcxGridDateRanges* Container = {read=FContainer};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridDateRange(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridHourRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridHourRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
	virtual bool __fastcall NeedsSortingByTime(void);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridHourRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridHourRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridDayRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDayRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridDayRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridDayRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridMonthRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridMonthRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetRangeValue(const System::TDateTime ADate, bool AIgnoreTime);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridMonthRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridMonthRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridYearRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridYearRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetRangeValue(const System::TDateTime ADate, bool AIgnoreTime);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridYearRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridYearRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridYesterdayRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridYesterdayRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridYesterdayRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridYesterdayRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridTodayRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTodayRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridTodayRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridTodayRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridTomorrowRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTomorrowRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridTomorrowRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridTomorrowRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridLastWeekRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLastWeekRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridLastWeekRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridLastWeekRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridThisWeekRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridThisWeekRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridThisWeekRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridThisWeekRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridNextWeekRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridNextWeekRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridNextWeekRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridNextWeekRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridLastMonthRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLastMonthRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridLastMonthRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridLastMonthRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridThisMonthRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridThisMonthRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridThisMonthRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridThisMonthRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridNextMonthRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridNextMonthRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridNextMonthRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridNextMonthRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridLastYearRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLastYearRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridLastYearRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridLastYearRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridThisYearRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridThisYearRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridThisYearRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridThisYearRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridNextYearRange;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridNextYearRange : public TcxCustomGridDateRange
{
	typedef TcxCustomGridDateRange inherited;
	
public:
	virtual bool __fastcall Contains(const System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDisplayText(const System::TDateTime ADate);
	virtual System::Variant __fastcall GetValue(const System::TDateTime ADate);
public:
	/* TcxCustomGridDateRange.Destroy */ inline __fastcall virtual ~TcxGridNextYearRange(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridNextYearRange(void) : TcxCustomGridDateRange() { }
	
};

#pragma pack(pop)

enum TcxGridDateTimeFilter : unsigned char { dtfRelativeDays, dtfRelativeDayPeriods, dtfRelativeWeeks, dtfRelativeMonths, dtfRelativeYears, dtfPastFuture, dtfMonths, dtfYears };

typedef System::Set<TcxGridDateTimeFilter, TcxGridDateTimeFilter::dtfRelativeDays, TcxGridDateTimeFilter::dtfYears>  TcxGridDateTimeFilters;

enum TcxGridDateTimeGrouping : unsigned char { dtgDefault, dtgByDateAndTime, dtgRelativeToToday, dtgByHour, dtgByDate, dtgByMonth, dtgByYear };

typedef System::TMetaClass* TcxGridDateRangesClass;

class DELPHICLASS TcxCustomGridTableDateTimeHandling;
class PASCALIMPLEMENTATION TcxGridDateRanges : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomGridDateRange* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomGridTableDateTimeHandling* FDateTimeHandling;
	System::Classes::TList* FItems;
	System::TDateTime FStartOfThisWeek;
	System::Word FThisDay;
	System::Word FThisMonth;
	int FThisMonthNumber;
	System::Word FThisYear;
	System::TDateTime FToday;
	int __fastcall GetCount(void);
	TcxCustomGridDateRange* __fastcall GetItem(int Index);
	
protected:
	void __fastcall AddItem(TcxCustomGridDateRange* AItem);
	void __fastcall RemoveItem(TcxCustomGridDateRange* AItem);
	int __fastcall GetItemIndex(TcxCustomGridDateRange* AItem);
	void __fastcall SetItemIndex(TcxCustomGridDateRange* AItem, int AValue);
	virtual void __fastcall InitConsts(void);
	
public:
	__fastcall virtual TcxGridDateRanges(void);
	__fastcall virtual ~TcxGridDateRanges(void);
	void __fastcall Add(TcxCustomGridDateRange* ARange)/* overload */;
	void __fastcall Add(TcxCustomGridDateRangeClass ARangeClass)/* overload */;
	void __fastcall Clear(void);
	TcxCustomGridDateRange* __fastcall GetRange(const System::TDateTime ADate)/* overload */;
	TcxCustomGridDateRange* __fastcall GetRange(TcxCustomGridDateRangeClass ARangeClass)/* overload */;
	virtual void __fastcall Init(TcxCustomGridTableDateTimeHandling* ADateTimeHandling);
	bool __fastcall IsEmpty(void);
	bool __fastcall NeedSortingByTime(void);
	bool __fastcall NeedTime(void);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomGridDateRange* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxCustomGridTableDateTimeHandling* DateTimeHandling = {read=FDateTimeHandling};
	__property System::TDateTime StartOfThisWeek = {read=FStartOfThisWeek};
	__property System::Word ThisDay = {read=FThisDay, nodefault};
	__property System::Word ThisMonth = {read=FThisMonth, nodefault};
	__property int ThisMonthNumber = {read=FThisMonthNumber, nodefault};
	__property System::Word ThisYear = {read=FThisYear, nodefault};
	__property System::TDateTime Today = {read=FToday};
};


typedef System::TMetaClass* TcxGridFilteringDateRangesClass;

class DELPHICLASS TcxGridFilteringDateRanges;
class PASCALIMPLEMENTATION TcxGridFilteringDateRanges : public TcxGridDateRanges
{
	typedef TcxGridDateRanges inherited;
	
public:
	HIDESBASE virtual void __fastcall Init(TcxCustomGridTableDateTimeHandling* ADateTimeHandling, TcxGridDateTimeFilters ADateTimeFilters);
public:
	/* TcxGridDateRanges.Create */ inline __fastcall virtual TcxGridFilteringDateRanges(void) : TcxGridDateRanges() { }
	/* TcxGridDateRanges.Destroy */ inline __fastcall virtual ~TcxGridFilteringDateRanges(void) { }
	
};


typedef System::TMetaClass* TcxGridGroupingDateRangesClass;

class DELPHICLASS TcxGridGroupingDateRanges;
class PASCALIMPLEMENTATION TcxGridGroupingDateRanges : public TcxGridDateRanges
{
	typedef TcxGridDateRanges inherited;
	
public:
	HIDESBASE virtual void __fastcall Init(TcxCustomGridTableDateTimeHandling* ADateTimeHandling, TcxGridDateTimeGrouping ADateTimeGrouping);
public:
	/* TcxGridDateRanges.Create */ inline __fastcall virtual TcxGridGroupingDateRanges(void) : TcxGridDateRanges() { }
	/* TcxGridDateRanges.Destroy */ inline __fastcall virtual ~TcxGridGroupingDateRanges(void) { }
	
};


typedef System::TMetaClass* TcxCustomGridRecordClass;

class DELPHICLASS TcxCustomGridTableController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridRecord : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FIndex;
	TcxCustomGridTableViewData* FViewData;
	TcxCustomGridRecordViewInfo* FViewInfo;
	TcxCustomGridTableController* __fastcall GetController(void);
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	bool __fastcall GetDragHighlighted(void);
	bool __fastcall GetFocused(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	bool __fastcall GetIsEditing(void);
	bool __fastcall GetIsNewItemRecord(void);
	bool __fastcall GetIsValid(void);
	int __fastcall GetLastParentRecordCount(void);
	int __fastcall GetLevel(void);
	bool __fastcall GetPartVisible(void);
	int __fastcall GetRecordIndex(void);
	void __fastcall SetExpanded(bool Value);
	void __fastcall SetFocused(bool Value);
	
protected:
	int FPixelScrollPosition;
	Cxcustomdata::TcxRowInfo RecordInfo;
	virtual void __fastcall RefreshRecordInfo(void);
	virtual void __fastcall DoCollapse(bool ARecurse);
	virtual void __fastcall DoExpand(bool ARecurse);
	virtual bool __fastcall GetExpandable(void);
	virtual bool __fastcall GetExpanded(void);
	virtual void __fastcall ToggleExpanded(void);
	virtual bool __fastcall GetHasCells(void);
	virtual bool __fastcall GetIsData(void);
	virtual bool __fastcall GetIsFirst(void);
	virtual bool __fastcall GetIsLast(void);
	virtual bool __fastcall GetIsParent(void);
	bool __fastcall GetIsParentRecordLast(int AIndex);
	virtual TcxCustomGridRecord* __fastcall GetParentRecord(void);
	virtual bool __fastcall GetSelected(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall SetSelected(bool Value);
	virtual System::UnicodeString __fastcall GetDisplayText(int Index);
	virtual int __fastcall GetValueCount(void);
	virtual System::Variant __fastcall GetValue(int Index);
	virtual void __fastcall SetDisplayText(int Index, const System::UnicodeString Value);
	virtual void __fastcall SetValue(int Index, const System::Variant &Value);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheItemClass __fastcall GetViewInfoCacheItemClass(void) = 0 ;
	virtual TcxCustomGridRecordViewInfoClass __fastcall GetViewInfoClass(void) = 0 ;
	__property bool IsParent = {read=GetIsParent, nodefault};
	__property bool IsParentRecordLast[int AIndex] = {read=GetIsParentRecordLast};
	__property bool IsValid = {read=GetIsValid, nodefault};
	__property int LastParentRecordCount = {read=GetLastParentRecordCount, nodefault};
	__property TcxCustomGridTableController* Controller = {read=GetController};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	
public:
	__fastcall virtual TcxCustomGridRecord(TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo);
	__fastcall virtual ~TcxCustomGridRecord(void);
	virtual bool __fastcall CanFocus(void);
	virtual bool __fastcall CanFocusCells(void);
	void __fastcall Collapse(bool ARecurse);
	void __fastcall Expand(bool ARecurse);
	virtual TcxCustomGridRecord* __fastcall GetFirstFocusableChild(void);
	virtual TcxCustomGridRecord* __fastcall GetLastFocusableChild(bool ARecursive);
	virtual void __fastcall Invalidate(TcxCustomGridTableItem* AItem = (TcxCustomGridTableItem*)(0x0));
	void __fastcall MakeVisible(void);
	__property bool DragHighlighted = {read=GetDragHighlighted, nodefault};
	__property System::UnicodeString DisplayTexts[int Index] = {read=GetDisplayText, write=SetDisplayText};
	__property bool Expandable = {read=GetExpandable, nodefault};
	__property bool Expanded = {read=GetExpanded, write=SetExpanded, nodefault};
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property bool HasCells = {read=GetHasCells, nodefault};
	__property int Index = {read=FIndex, nodefault};
	__property bool IsData = {read=GetIsData, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property bool IsFirst = {read=GetIsFirst, nodefault};
	__property bool IsLast = {read=GetIsLast, nodefault};
	__property bool IsNewItemRecord = {read=GetIsNewItemRecord, nodefault};
	__property int Level = {read=GetLevel, nodefault};
	__property TcxCustomGridRecord* ParentRecord = {read=GetParentRecord};
	__property bool PartVisible = {read=GetPartVisible, nodefault};
	__property int PixelScrollPosition = {read=FPixelScrollPosition, nodefault};
	__property int RecordIndex = {read=GetRecordIndex, nodefault};
	__property bool Selected = {read=GetSelected, write=SetSelected, nodefault};
	__property int ValueCount = {read=GetValueCount, nodefault};
	__property System::Variant Values[int Index] = {read=GetValue, write=SetValue};
	__property TcxCustomGridTableViewData* ViewData = {read=FViewData};
	__property TcxCustomGridRecordViewInfo* ViewInfo = {read=FViewInfo};
	__property bool Visible = {read=GetVisible, nodefault};
};

#pragma pack(pop)

enum TcxGridDataOperation : unsigned char { doSorting, doGrouping, doFiltering };

class DELPHICLASS TcxCustomGridTableViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableViewData : public Cxgridcustomview::TcxCustomGridViewData
{
	typedef Cxgridcustomview::TcxCustomGridViewData inherited;
	
private:
	TcxCustomGridRecord* FEditingRecord;
	TcxCustomGridRecord* FNewItemRecord;
	Dxcoreclasses::TdxFastList* FRecords;
	HIDESBASE TcxCustomGridTableController* __fastcall GetController(void);
	TcxCustomGridRecord* __fastcall GetEditingRecord(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	TcxCustomGridRecord* __fastcall GetInternalRecord(int Index);
	TcxCustomGridRecord* __fastcall GetRecord(int Index);
	int __fastcall GetRecordCount(void);
	HIDESBASE TcxCustomGridTableViewInfo* __fastcall GetViewInfo(void);
	TcxCustomGridRecord* __fastcall CreateRecord(int AIndex);
	
protected:
	virtual TcxGridFilterValueListClass __fastcall GetFilterValueListClass(void);
	int __fastcall GetPixelScrollSize(void);
	virtual TcxCustomGridRecord* __fastcall GetRecordByKind(int AKind, int AIndex);
	virtual TcxCustomGridRecordClass __fastcall GetRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo) = 0 ;
	virtual int __fastcall GetRecordKind(TcxCustomGridRecord* ARecord);
	void __fastcall AssignEditingRecord(void);
	void __fastcall CreateNewItemRecord(void);
	void __fastcall DestroyNewItemRecord(void);
	virtual TcxCustomGridRecordClass __fastcall GetNewItemRecordClass(void);
	void __fastcall RecreateNewItemRecord(void);
	__property TcxCustomGridTableController* Controller = {read=GetController};
	__property TcxCustomGridRecord* InternalRecords[int Index] = {read=GetInternalRecord};
	__property TcxCustomGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomGridTableViewData(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridTableViewData(void);
	virtual void __fastcall Collapse(bool ARecurse);
	void __fastcall DestroyRecords(void);
	virtual void __fastcall Expand(bool ARecurse);
	TcxCustomGridRecord* __fastcall GetRecordByIndex(int AIndex);
	TcxCustomGridRecord* __fastcall GetRecordByRecordIndex(int ARecordIndex);
	int __fastcall GetRecordIndexByRecord(TcxCustomGridRecord* ARecord);
	bool __fastcall IsRecordIndexValid(int AIndex);
	virtual void __fastcall Refresh(int ARecordCount);
	void __fastcall RefreshRecords(void);
	void __fastcall CheckNewItemRecord(void);
	virtual bool __fastcall HasNewItemRecord(void);
	Cxfilter::TcxFilterCriteriaItem* __fastcall AddItemToFilter(Cxfilter::TcxFilterCriteriaItemList* AParent, TcxCustomGridTableItem* AItem, Cxfilter::TcxFilterOperatorKind AOperatorKind, const System::Variant &AValue, System::UnicodeString ADisplayText = System::UnicodeString(), bool AReplaceExistent = true);
	TcxGridFilterValueList* __fastcall CreateFilterValueList(void);
	virtual bool __fastcall GetDisplayText(int ARecordIndex, int AItemIndex, /* out */ System::UnicodeString &AText, bool AUseCustomValue = false, TcxGridDataOperation ACustomValueOperation = (TcxGridDataOperation)(0x1));
	virtual int __fastcall CustomCompareDataValues(Cxcustomdata::TcxCustomDataField* AField, const System::Variant &AValue1, const System::Variant &AValue2, Cxcustomdata::TcxDataControllerComparisonMode AMode);
	virtual System::UnicodeString __fastcall GetCustomDataDisplayText(int ARecordIndex, int AItemIndex, TcxGridDataOperation AOperation)/* overload */;
	virtual System::UnicodeString __fastcall GetCustomDataDisplayText(int AItemIndex, const System::Variant &AValue)/* overload */;
	System::Variant __fastcall GetCustomDataValue(Cxcustomdata::TcxCustomDataField* AField, const System::Variant &AValue, TcxGridDataOperation AOperation)/* overload */;
	virtual System::Variant __fastcall GetCustomDataValue(TcxCustomGridTableItem* AItem, const System::Variant &AValue, TcxGridDataOperation AOperation)/* overload */;
	bool __fastcall HasCustomDataHandling(Cxcustomdata::TcxCustomDataField* AField, TcxGridDataOperation AOperation)/* overload */;
	virtual bool __fastcall HasCustomDataHandling(TcxCustomGridTableItem* AItem, TcxGridDataOperation AOperation)/* overload */;
	virtual bool __fastcall NeedsCustomDataComparison(Cxcustomdata::TcxCustomDataField* AField, Cxcustomdata::TcxDataControllerComparisonMode AMode);
	__property TcxCustomGridRecord* EditingRecord = {read=FEditingRecord};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridRecord* NewItemRecord = {read=FNewItemRecord};
	__property int RecordCount = {read=GetRecordCount, nodefault};
	__property TcxCustomGridRecord* Records[int Index] = {read=GetRecord};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableMovingObject;
class DELPHICLASS TcxCustomGridTableCustomizationForm;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableMovingObject : public Cxgridcustomview::TcxCustomGridMovingObject
{
	typedef Cxgridcustomview::TcxCustomGridMovingObject inherited;
	
private:
	HIDESBASE TcxCustomGridTableController* __fastcall GetController(void);
	HIDESBASE TcxCustomGridTableCustomizationForm* __fastcall GetCustomizationForm(void);
	
protected:
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	__property TcxCustomGridTableController* Controller = {read=GetController};
	__property TcxCustomGridTableCustomizationForm* CustomizationForm = {read=GetCustomizationForm};
public:
	/* TcxDragAndDropObject.Create */ inline __fastcall virtual TcxCustomGridTableMovingObject(Cxcontrols::TcxControl* AControl) : Cxgridcustomview::TcxCustomGridMovingObject(AControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridTableMovingObject(void) { }
	
};

#pragma pack(pop)

typedef int TcxGridItemContainerKind;

class DELPHICLASS TcxGridItemContainerZone;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridItemContainerZone : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int ItemIndex;
	__fastcall TcxGridItemContainerZone(int AItemIndex);
	virtual bool __fastcall IsEqual(TcxGridItemContainerZone* Value);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridItemContainerZone(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableItemMovingObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableItemMovingObject : public TcxCustomGridTableMovingObject
{
	typedef TcxCustomGridTableMovingObject inherited;
	
private:
	int FDestItemContainerKind;
	TcxGridItemContainerZone* FDestZone;
	int FSourceItemContainerKind;
	void __fastcall SetDestItemContainerKind(int Value);
	void __fastcall SetDestZone(TcxGridItemContainerZone* Value);
	
protected:
	virtual void __fastcall CalculateDestParams(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, /* out */ int &AContainerKind, /* out */ TcxGridItemContainerZone* &AZone);
	virtual void __fastcall CheckDestItemContainerKind(int &AValue);
	virtual Cxgridcustomview::TcxCustomGridItemsListBox* __fastcall GetCustomizationFormListBox(void);
	virtual bool __fastcall IsSourceCustomizationForm(void);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	__property int DestItemContainerKind = {read=FDestItemContainerKind, write=SetDestItemContainerKind, nodefault};
	__property TcxGridItemContainerZone* DestZone = {read=FDestZone, write=SetDestZone};
	__property int SourceItemContainerKind = {read=FSourceItemContainerKind, write=FSourceItemContainerKind, nodefault};
	
public:
	__fastcall virtual TcxCustomGridTableItemMovingObject(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TcxCustomGridTableItemMovingObject(void);
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridTableItemsListBoxClass;

class DELPHICLASS TcxCustomGridTableItemsListBox;
class PASCALIMPLEMENTATION TcxCustomGridTableItemsListBox : public Cxgridcustomview::TcxCustomGridItemsListBox
{
	typedef Cxgridcustomview::TcxCustomGridItemsListBox inherited;
	
private:
	HIDESBASE TcxCustomGridTableView* __fastcall GetGridView(void);
	
protected:
	void __fastcall RefreshItemsAsTableItems(void);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridItemsListBox.Create */ inline __fastcall virtual TcxCustomGridTableItemsListBox(System::Classes::TComponent* AOwner) : Cxgridcustomview::TcxCustomGridItemsListBox(AOwner) { }
	
public:
	/* TcxListBox.Destroy */ inline __fastcall virtual ~TcxCustomGridTableItemsListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridTableItemsListBox(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridItemsListBox(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomGridTableCustomizationForm : public Cxgridcustomview::TcxCustomGridCustomizationForm
{
	typedef Cxgridcustomview::TcxCustomGridCustomizationForm inherited;
	
private:
	TcxCustomGridTableItemsListBox* FItemsListBox;
	Cxpc::TcxTabSheet* FItemsPage;
	
protected:
	virtual void __fastcall CreateControls(void);
	virtual TcxCustomGridTableItemsListBoxClass __fastcall GetItemsListBoxClass(void);
	virtual System::UnicodeString __fastcall GetItemsPageCaption(void) = 0 ;
	virtual bool __fastcall GetItemsPageVisible(void);
	virtual void __fastcall InitPageControl(void);
	__property TcxCustomGridTableItemsListBox* ItemsListBox = {read=FItemsListBox};
	
public:
	virtual void __fastcall RefreshData(void);
	__property Cxpc::TcxTabSheet* ItemsPage = {read=FItemsPage};
public:
	/* TcxCustomGridCustomizationForm.Create */ inline __fastcall virtual TcxCustomGridTableCustomizationForm(Cxgridcustomview::TcxCustomGridController* AController) : Cxgridcustomview::TcxCustomGridCustomizationForm(AController) { }
	/* TcxCustomGridCustomizationForm.Destroy */ inline __fastcall virtual ~TcxCustomGridTableCustomizationForm(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomGridTableCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomview::TcxCustomGridCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridTableCustomizationForm(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridCustomizationForm(ParentWindow) { }
	
};


__interface IcxGridFilterPopupOwner;
typedef System::DelphiInterface<IcxGridFilterPopupOwner> _di_IcxGridFilterPopupOwner;
__interface  INTERFACE_UUID("{1FC070B2-36E5-4388-B22D-1FF5D240E95F}") IcxGridFilterPopupOwner  : public Cxgridcustomview::IcxCustomGridPopupOwner 
{
	
public:
	virtual TcxCustomGridTableItem* __fastcall GetItem(void) = 0 ;
};

class DELPHICLASS TcxGridFilterPopupListBox;
class DELPHICLASS TcxGridFilterPopup;
class PASCALIMPLEMENTATION TcxGridFilterPopupListBox : public Cxgridcustomview::TcxGridPopupListBox
{
	typedef Cxgridcustomview::TcxGridPopupListBox inherited;
	
private:
	TcxGridFilterPopup* __fastcall GetPopup(void);
	
protected:
	virtual bool __fastcall CanHaveCheck(int AItemIndex);
	virtual void __fastcall DrawItemContent(Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	virtual bool __fastcall HasCheck(int AItemIndex);
	
public:
	__property TcxGridFilterPopup* Popup = {read=GetPopup};
public:
	/* TcxGridPopupListBox.Create */ inline __fastcall virtual TcxGridFilterPopupListBox(Cxgridcustomview::TcxCustomGridPopup* APopup) : Cxgridcustomview::TcxGridPopupListBox(APopup) { }
	/* TcxGridPopupListBox.Destroy */ inline __fastcall virtual ~TcxGridFilterPopupListBox(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridFilterPopupListBox(HWND ParentWindow) : Cxgridcustomview::TcxGridPopupListBox(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridFilterPopupClass;

class PASCALIMPLEMENTATION TcxGridFilterPopup : public Cxgridcustomview::TcxCustomGridPopup
{
	typedef Cxgridcustomview::TcxCustomGridPopup inherited;
	
private:
	Cxbuttons::TcxButton* FButton;
	bool FFilterChangedByCheck;
	TcxCustomGridTableItem* FItem;
	TcxGridFilterPopupListBox* FListBox;
	System::Classes::TStringList* FListBoxItems;
	TcxGridFilterValueList* FValueList;
	Cxcustomdata::TcxDataFilterCriteria* __fastcall GetFilter(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	void __fastcall SetFilterChangedByCheck(bool Value);
	void __fastcall ButtonClicked(System::TObject* Sender);
	void __fastcall ListBoxAction(Cxgridcustomview::TcxGridPopupListBox* Sender, int AItemIndex);
	
protected:
	virtual void __fastcall AddListBoxItems(void);
	virtual void __fastcall AdjustListBoxSize(void);
	virtual void __fastcall ApplyFilterUsingCheckedItems(const Cxgridcustomview::TcxGridIndexes AItemIndexes);
	virtual void __fastcall ApplyFilterUsingClickedItem(int AItemIndex);
	virtual bool __fastcall GetImmediateFilterUsingChecks(void);
	virtual Cxgridcustomview::TcxGridIndexes __fastcall GetListBoxCheckedItemIndexes(void);
	virtual int __fastcall GetSelectedItemIndex(void);
	virtual void __fastcall InitButton(void);
	virtual void __fastcall InitListBox(void);
	virtual void __fastcall InitPopup(void);
	virtual bool __fastcall IsButtonVisible(void);
	virtual bool __fastcall IsCheck(int AItemIndex);
	bool __fastcall IsMRUItemsListSeparator(int AItemIndex);
	virtual bool __fastcall SupportsChecks(void);
	virtual void __fastcall UpdateButtonEnabled(void);
	__property Cxbuttons::TcxButton* Button = {read=FButton};
	__property Cxcustomdata::TcxDataFilterCriteria* Filter = {read=GetFilter};
	__property bool FilterChangedByCheck = {read=FFilterChangedByCheck, write=SetFilterChangedByCheck, nodefault};
	__property bool ImmediateFilterUsingChecks = {read=GetImmediateFilterUsingChecks, nodefault};
	__property TcxGridFilterPopupListBox* ListBox = {read=FListBox};
	__property System::Classes::TStringList* ListBoxItems = {read=FListBoxItems};
	__property int SelectedItemIndex = {read=GetSelectedItemIndex, nodefault};
	__property TcxGridFilterValueList* ValueList = {read=FValueList};
	
public:
	__fastcall virtual TcxGridFilterPopup(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxGridFilterPopup(void);
	virtual void __fastcall CloseUp(void);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridTableItem* Item = {read=FItem};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridFilterPopup(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomview::TcxCustomGridPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridFilterPopup(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridPopup(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridFilterMRUItemsPopupClass;

class DELPHICLASS TcxGridFilterMRUItemsPopup;
class DELPHICLASS TcxCustomGridTableFiltering;
class PASCALIMPLEMENTATION TcxGridFilterMRUItemsPopup : public Cxgridcustomview::TcxCustomGridPopup
{
	typedef Cxgridcustomview::TcxCustomGridPopup inherited;
	
private:
	Cxgridcustomview::TcxGridPopupListBox* FListBox;
	TcxCustomGridTableFiltering* __fastcall GetFiltering(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	void __fastcall ListBoxAction(Cxgridcustomview::TcxGridPopupListBox* Sender, int AItemIndex);
	
protected:
	virtual void __fastcall AddFilterMRUItems(System::Classes::TStrings* AStrings);
	virtual void __fastcall ApplyFilterMRUItem(int AItemIndex);
	virtual Cxgridcustomview::TcxGridPopupListBoxClass __fastcall GetListBoxClass(void);
	virtual int __fastcall GetTextOffsetHorz(void);
	virtual void __fastcall InitPopup(void);
	virtual void __fastcall UpdateInnerControlsHeight(int &AClientHeight);
	__property TcxCustomGridTableFiltering* Filtering = {read=GetFiltering};
	__property Cxgridcustomview::TcxGridPopupListBox* ListBox = {read=FListBox};
	
public:
	__fastcall virtual TcxGridFilterMRUItemsPopup(Cxgridcustomview::TcxCustomGridView* AGridView);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property int TextOffsetHorz = {read=GetTextOffsetHorz, nodefault};
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxGridFilterMRUItemsPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridFilterMRUItemsPopup(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomview::TcxCustomGridPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridFilterMRUItemsPopup(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridPopup(ParentWindow) { }
	
};


class DELPHICLASS TcxCustomGridCustomizationPopup;
class PASCALIMPLEMENTATION TcxCustomGridCustomizationPopup : public Cxgridcustomview::TcxCustomGridPopup
{
	typedef Cxgridcustomview::TcxCustomGridPopup inherited;
	
private:
	Cxchecklistbox::TcxCheckListBox* FCheckListBox;
	int FDragItemIndex;
	Cxclasses::TcxDirection FScrollDirection;
	Cxclasses::TcxTimer* FScrollTimer;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	void __fastcall SetScrollDirection(Cxclasses::TcxDirection Value);
	void __fastcall CheckListBoxClick(System::TObject* Sender);
	void __fastcall CheckListBoxCheckClick(System::TObject* Sender, int AIndex, Cxlookandfeelpainters::TcxCheckBoxState APrevState, Cxlookandfeelpainters::TcxCheckBoxState ANewState);
	void __fastcall CheckListBoxEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall CheckListBoxKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall CheckListBoxMouseDown(System::TObject* Sender, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall CheckListBoxStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall CheckListBoxDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall CheckListBoxDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall ScrollTimerHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall AddCheckListBoxItems(void) = 0 ;
	virtual void __fastcall AdjustCheckListBoxSize(bool AFixedHeight = false);
	virtual void __fastcall CheckClicked(int AIndex, bool AChecked);
	virtual void __fastcall CreateCheckListBox(void);
	virtual int __fastcall GetCheckListBoxColumnWidth(void);
	virtual int __fastcall GetDropDownCount(void) = 0 ;
	int __fastcall GetItemInsertionIndex(int X, int Y);
	virtual void __fastcall InitPopup(void);
	void __fastcall RefreshCheckListBoxItems(void);
	virtual bool __fastcall SupportsItemMoving(void) = 0 ;
	void __fastcall GetCheckListBoxSelectedItems(System::Classes::TList* AItems);
	void __fastcall SetCheckListBoxSelectedItems(System::Classes::TList* AItems);
	virtual void __fastcall ItemClicked(System::TObject* AItem, bool AChecked) = 0 ;
	virtual int __fastcall GetItemIndex(System::TObject* AItem) = 0 ;
	virtual void __fastcall SetItemIndex(System::TObject* AItem, int AIndex) = 0 ;
	__property int CheckListBoxColumnWidth = {read=GetCheckListBoxColumnWidth, nodefault};
	__property int DragItemIndex = {read=FDragItemIndex, write=FDragItemIndex, nodefault};
	__property Cxclasses::TcxDirection ScrollDirection = {read=FScrollDirection, write=SetScrollDirection, nodefault};
	
public:
	__fastcall virtual TcxCustomGridCustomizationPopup(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall CorrectBoundsWithDesktopWorkArea(System::Types::TPoint &APosition);
	virtual void __fastcall Popup(void);
	__property Cxchecklistbox::TcxCheckListBox* CheckListBox = {read=FCheckListBox};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxCustomGridCustomizationPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomGridCustomizationPopup(System::Classes::TComponent* AOwner, int Dummy) : Cxgridcustomview::TcxCustomGridPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridCustomizationPopup(HWND ParentWindow) : Cxgridcustomview::TcxCustomGridPopup(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxCustomGridItemsCustomizationPopupClass;

class DELPHICLASS TcxCustomGridItemsCustomizationPopup;
class PASCALIMPLEMENTATION TcxCustomGridItemsCustomizationPopup : public TcxCustomGridCustomizationPopup
{
	typedef TcxCustomGridCustomizationPopup inherited;
	
protected:
	virtual void __fastcall AddCheckListBoxItems(void);
	virtual int __fastcall GetDropDownCount(void);
	virtual bool __fastcall SupportsItemMoving(void);
	virtual void __fastcall ItemClicked(System::TObject* AItem, bool AChecked);
	virtual int __fastcall GetItemIndex(System::TObject* AItem);
	virtual void __fastcall SetItemIndex(System::TObject* AItem, int AIndex);
public:
	/* TcxCustomGridCustomizationPopup.Create */ inline __fastcall virtual TcxCustomGridItemsCustomizationPopup(Cxgridcustomview::TcxCustomGridView* AGridView) : TcxCustomGridCustomizationPopup(AGridView) { }
	
public:
	/* TcxCustomPopupWindow.Destroy */ inline __fastcall virtual ~TcxCustomGridItemsCustomizationPopup(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomGridItemsCustomizationPopup(System::Classes::TComponent* AOwner, int Dummy) : TcxCustomGridCustomizationPopup(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomGridItemsCustomizationPopup(HWND ParentWindow) : TcxCustomGridCustomizationPopup(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxGridEditingControllerClass;

class DELPHICLASS TcxGridEditingController;
class DELPHICLASS TcxGridTableDataCellViewInfo;
class PASCALIMPLEMENTATION TcxGridEditingController : public Cxedit::TcxCustomEditingController
{
	typedef Cxedit::TcxCustomEditingController inherited;
	
private:
	TcxCustomGridTableController* FController;
	TcxCustomGridTableItem* FEditingItem;
	bool FEditingItemSetting;
	TcxCustomGridTableItem* FEditShowingTimerItem;
	bool FIsEditAutoHeight;
	Cxmemo::TcxAutoHeightInplaceEdit* FMultiLineEdit;
	int FMultiLineEditMinHeight;
	bool FUpdateEditStyleNeeded;
	TcxGridTableDataCellViewInfo* __fastcall GetEditingCellViewInfo(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetEditingProperties(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	Cxedit::TcxInplaceEditAutoHeight __fastcall GetAutoHeight(void);
	void __fastcall SetEditingItem(TcxCustomGridTableItem* Value);
	
protected:
	void __fastcall AfterAssignMultilineEditProperties(void);
	void __fastcall BeforeAssignMultilineEditProperties(void);
	bool __fastcall CanUpdateMultilineEditHeight(void);
	virtual bool __fastcall CanUseAutoHeightEditor(void);
	System::Types::TRect __fastcall GetAdjustedMultilineEditBounds(const System::Types::TRect &ABounds);
	virtual void __fastcall MultilineEditTextChanged(void);
	virtual void __fastcall StartEditAutoHeight(bool AHeightChanged);
	void __fastcall UpdateMultilineEditBounds(const System::Types::TRect &ABounds);
	virtual void __fastcall AfterViewInfoCalculate(void);
	virtual void __fastcall BeforeViewInfoCalculate(void);
	virtual bool __fastcall CanInitEditing(void);
	virtual bool __fastcall CanUpdateEditValue(void);
	System::Types::TRect __fastcall CellEditBoundsToEditBounds(const System::Types::TRect &ACellEditBounds);
	void __fastcall CheckEdit(void);
	void __fastcall CheckUsingMultilineEdit(void);
	virtual void __fastcall ClearEditingItem(void);
	virtual Cxmemo::TcxAutoHeightInplaceEdit* __fastcall CreateMultilineEdit(void);
	virtual void __fastcall DoEditKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoHideEdit(bool Accept);
	virtual void __fastcall DoUpdateEdit(void);
	virtual void __fastcall FocusedRecordChanged(void);
	virtual bool __fastcall GetCancelEditingOnExit(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetEditParent(void);
	virtual System::Types::TRect __fastcall GetFocusedCellBounds(void);
	virtual System::Types::TRect __fastcall GetFocusRectBounds(void);
	virtual bool __fastcall GetHideEditOnExit(void);
	virtual bool __fastcall GetHideEditOnFocusedRecordChange(void);
	virtual bool __fastcall GetIsEditing(void);
	virtual void __fastcall InitEdit(void);
	virtual void __fastcall InitMultilineEdit(void);
	virtual bool __fastcall IsNeedInvokeEditChangedEventsBeforePost(void);
	virtual void __fastcall PostEditingData(void);
	virtual bool __fastcall PrepareEdit(TcxCustomGridTableItem* AItem, bool AOnMouseEvent);
	virtual void __fastcall StartEditingByTimer(void);
	void __fastcall UpdateEditBounds(const System::Types::TRect &AEditBounds);
	void __fastcall UpdateEditStyle(TcxGridTableDataCellViewInfo* AEditCellViewInfo);
	virtual void __fastcall UpdateInplaceParamsPosition(void);
	virtual Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall SetValue(const System::Variant &AValue);
	virtual void __fastcall EditAfterKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditChanged(System::TObject* Sender);
	virtual void __fastcall EditDblClick(System::TObject* Sender);
	virtual void __fastcall EditFocusChanged(System::TObject* Sender);
	virtual void __fastcall EditKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditKeyPress(System::TObject* Sender, System::WideChar &Key);
	virtual void __fastcall EditKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditValueChanged(System::TObject* Sender);
	__property Cxedit::TcxInplaceEditAutoHeight AutoHeight = {read=GetAutoHeight, nodefault};
	__property TcxGridTableDataCellViewInfo* EditingCellViewInfo = {read=GetEditingCellViewInfo};
	__property Cxedit::TcxCustomEditProperties* EditingProperties = {read=GetEditingProperties};
	__property bool HideEditOnFocusedRecordChange = {read=GetHideEditOnFocusedRecordChange, nodefault};
	__property bool IsEditAutoHeight = {read=FIsEditAutoHeight, nodefault};
	__property Cxmemo::TcxAutoHeightInplaceEdit* MultiLineEdit = {read=FMultiLineEdit};
	__property int MultiLineEditMinHeight = {read=FMultiLineEditMinHeight, nodefault};
	
public:
	__fastcall virtual TcxGridEditingController(TcxCustomGridTableController* AController);
	__fastcall virtual ~TcxGridEditingController(void);
	virtual void __fastcall HideEdit(bool Accept);
	void __fastcall ShowEdit(TcxCustomGridTableItem* AItem = (TcxCustomGridTableItem*)(0x0))/* overload */;
	void __fastcall ShowEdit(TcxCustomGridTableItem* AItem, System::WideChar Key)/* overload */;
	void __fastcall ShowEdit(TcxCustomGridTableItem* AItem, System::Classes::TShiftState Shift, int X, int Y)/* overload */;
	HIDESBASE void __fastcall StartEditShowingTimer(TcxCustomGridTableItem* AItem);
	__property TcxCustomGridTableController* Controller = {read=FController};
	__property TcxCustomGridTableItem* EditingItem = {read=FEditingItem, write=SetEditingItem};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
};


class DELPHICLASS TcxGridDragOpenInfoExpand;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDragOpenInfoExpand : public Cxgridcommon::TcxCustomGridDragOpenInfo
{
	typedef Cxgridcommon::TcxCustomGridDragOpenInfo inherited;
	
public:
	TcxCustomGridRecord* GridRecord;
	__fastcall virtual TcxGridDragOpenInfoExpand(TcxCustomGridRecord* AGridRecord);
	virtual bool __fastcall Equals(Cxgridcommon::TcxCustomGridDragOpenInfo* AInfo);
	virtual void __fastcall Run(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDragOpenInfoExpand(void) { }
	
};

#pragma pack(pop)

typedef bool __fastcall (*TcxCustomGridTableCanItemFocus)(TcxCustomGridTableView* AOwner, int AItemIndex, System::TObject* AData);

struct DECLSPEC_DRECORD TcxGridTableClickedDataCellInfo
{
public:
	TcxCustomGridTableItem* Item;
	TcxGridTableDataCellViewInfo* Cell;
	int RecordIndex;
};


class PASCALIMPLEMENTATION TcxCustomGridTableController : public Cxgridcustomview::TcxCustomGridController
{
	typedef Cxgridcustomview::TcxCustomGridController inherited;
	
private:
	bool FAllowAppendRecord;
	bool FAllowCheckEdit;
	bool FBlockRecordKeyboardHandling;
	bool FCheckEditNeeded;
	bool FCheckingCoordinate;
	TcxGridTableDataCellViewInfo* FClickedCellViewInfo;
	TcxGridTableClickedDataCellInfo FClickedDataCellInfo;
	System::UnicodeString FDragDropText;
	Cxclasses::TcxDirection FDragScrollDirection;
	Cxclasses::TcxTimer* FDragScrollTimer;
	TcxCustomGridRecord* FDragHighlightedRecord;
	bool FEatKeyPress;
	TcxGridEditingController* FEditingController;
	TcxGridFilterMRUItemsPopup* FFilterMRUItemsPopup;
	TcxGridFilterPopup* FFilterPopup;
	TcxCustomGridTableItem* FFocusedItem;
	bool FFocusOnRecordFocusing;
	TcxCustomGridTableItem* FForcingWidthItem;
	bool FGridModeBufferCountUpdateNeeded;
	Cxclasses::TcxTimer* FGridModeBufferCountUpdateTimer;
	bool FIsPullFocusing;
	bool FIsReadyForImmediateEditing;
	bool FIsRecordUnselecting;
	TcxCustomGridItemsCustomizationPopup* FItemsCustomizationPopup;
	TcxCustomGridTableItem* FMovingItem;
	int FPixelScrollRecordOffset;
	int FPixelScrollTopRecordIndexMaxValue;
	int FPixelScrollTopRecordOffsetMaxValue;
	int FPrevFocusedRecordIndex;
	TcxCustomGridTableItem* FPullFocusingItem;
	System::Types::TPoint FPullFocusingMousePos;
	Cxgridcustomview::TcxCustomGridHitTest* FPullFocusingOriginHitTest;
	System::Variant FPullFocusingRecordId;
	Cxclasses::TcxDirection FPullFocusingScrollingDirection;
	Cxclasses::TcxTimer* FPullFocusingScrollingTimer;
	Cxclasses::TcxDirection FScrollDirection;
	Cxclasses::TcxTimer* FScrollTimer;
	int FTopRecordIndex;
	int FUnselectingRecordIndex;
	TcxCustomGridTableItem* __fastcall GetEditingItem(void);
	TcxGridFilterMRUItemsPopup* __fastcall GetFilterMRUItemsPopup(void);
	TcxGridFilterPopup* __fastcall GetFilterPopup(void);
	int __fastcall GetFocusedItemIndex(void);
	int __fastcall GetFocusedRecordIndex(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	TcxCustomGridTableItem* __fastcall GetIncSearchingItem(void);
	System::UnicodeString __fastcall GetIncSearchingText(void);
	bool __fastcall GetIsEditing(void);
	bool __fastcall GetIsIncSearching(void);
	bool __fastcall GetIsItemMoving(void);
	TcxCustomGridItemsCustomizationPopup* __fastcall GetItemsCustomizationPopup(void);
	int __fastcall GetLastVisibleRecordIndex(void);
	TcxCustomGridTableController* __fastcall GetMasterController(void);
	bool __fastcall GetMultiSelect(void);
	bool __fastcall GetNewItemRecordFocused(void);
	int __fastcall GetPrevFocusedRecordIndex(void);
	TcxCustomGridRecord* __fastcall GetSelectedRecord(int Index);
	int __fastcall GetSelectedRecordCount(void);
	HIDESBASE TcxCustomGridTableViewData* __fastcall GetViewData(void);
	HIDESBASE TcxCustomGridTableViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetDragHighlightedRecord(TcxCustomGridRecord* Value);
	void __fastcall SetEditingItem(TcxCustomGridTableItem* Value);
	void __fastcall SetFocusedItem(TcxCustomGridTableItem* Value);
	void __fastcall SetFocusedItemIndex(int Value);
	void __fastcall SetFocusedRecordIndex(int Value);
	void __fastcall SetIncSearchingText(const System::UnicodeString Value);
	void __fastcall SetInternalTopRecordIndex(int Value);
	void __fastcall SetNewItemRecordFocused(bool Value);
	void __fastcall SetPixelScrollRecordOffset(const int Value);
	void __fastcall SetScrollDirection(Cxclasses::TcxDirection Value);
	void __fastcall SetTopRecordIndex(int Value);
	void __fastcall DragScrollTimerHandler(System::TObject* Sender);
	void __fastcall GridModeBufferCountUpdateTimerHandler(System::TObject* Sender);
	void __fastcall PullFocusingScrollingTimerHandler(System::TObject* Sender);
	void __fastcall CreateScrollTimer(void);
	void __fastcall DestroyScrollTimer(void);
	void __fastcall ScrollTimerHandler(System::TObject* Sender);
	
protected:
	virtual void __fastcall AfterPaint(void);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall BeforePaint(void);
	virtual bool __fastcall CanCancelDragStartOnCaptureObjectClear(void);
	virtual bool __fastcall CanFocusOnClick(int X, int Y);
	virtual void __fastcall DetailFocused(Cxgridcustomview::TcxCustomGridView* ADetail);
	virtual void __fastcall DoEnter(void);
	virtual void __fastcall DoExit(void);
	virtual bool __fastcall MayFocus(void);
	virtual void __fastcall RemoveFocus(void);
	virtual void __fastcall SetFocus(bool ANotifyMaster);
	virtual void __fastcall AfterOffset(void);
	virtual void __fastcall BeforeOffset(void);
	virtual bool __fastcall CanAppend(bool ACheckOptions);
	void __fastcall CancelCheckEditPost(void);
	virtual bool __fastcall CanCopyToClipboard(void);
	virtual bool __fastcall CanDelete(bool ACheckOptions);
	virtual bool __fastcall CanEdit(void);
	virtual void __fastcall CheckCoordinates(void);
	virtual bool __fastcall CanHScrollBarHide(void);
	virtual bool __fastcall CanInsert(bool ACheckOptions);
	virtual bool __fastcall CanUseAutoHeightEditing(void);
	virtual void __fastcall CheckEdit(void);
	virtual void __fastcall CheckTopRecordIndex(int &Value);
	virtual void __fastcall CheckTopRecordIndexAndOffset(int &AIndex, int &AOffset);
	virtual int __fastcall DataScrollSize(void);
	virtual int __fastcall DoGetScrollBarPos(void);
	virtual void __fastcall DoSetScrollBarPos(int Value);
	bool __fastcall FindNextCustomItem(int AFocusedItemIndex, int AItemCount, bool AGoForward, bool AGoOnCycle, TcxCustomGridTableCanItemFocus ACanFocus, System::TObject* AData, int &AItemIndex, /* out */ bool &ACycleChanged);
	virtual void __fastcall FocusedItemChanged(TcxCustomGridTableItem* APrevFocusedItem);
	virtual void __fastcall FocusedRecordChanged(int APrevFocusedRecordIndex, int AFocusedRecordIndex, int APrevFocusedDataRecordIndex, int AFocusedDataRecordIndex, bool ANewItemRecordFocusingChanged);
	virtual bool __fastcall GetCancelEditingOnExit(void);
	virtual TcxGridFilterMRUItemsPopupClass __fastcall GetFilterMRUItemsPopupClass(void);
	virtual TcxGridFilterPopupClass __fastcall GetFilterPopupClass(void);
	virtual TcxCustomGridRecord* __fastcall GetFocusedRecord(void);
	virtual bool __fastcall GetIsRecordsScrollHorizontal(void) = 0 ;
	virtual TcxCustomGridItemsCustomizationPopupClass __fastcall GetItemsCustomizationPopupClass(void);
	virtual int __fastcall GetMaxTopRecordIndexValue(void);
	virtual void __fastcall GetPixelScrollTopRecordIndexAndOffsetByBottomRecord(int ABottomRecordIndex, /* out */ int &ATopRecordIndex, /* out */ int &ATopRecordPixelScrollOffset);
	virtual void __fastcall GetPixelScrollTopRecordIndexAndOffsetMaxValues(/* out */ int &ARecordIndex, /* out */ int &APixelScrollOffset);
	int __fastcall GetPageVisibleRecordCount(int AFirstRecordIndex, bool ACalculateDown = true);
	virtual System::Classes::TPersistent* __fastcall GetPatternObject(System::Classes::TPersistent* AObject);
	virtual int __fastcall GetScrollBarOffsetBegin(void);
	virtual int __fastcall GetScrollBarOffsetEnd(void);
	virtual int __fastcall GetScrollBarPos(void);
	virtual int __fastcall GetScrollBarRecordCount(void);
	virtual int __fastcall GetScrollDelta(void);
	virtual int __fastcall GetVisibleRecordCount(int AFirstRecordIndex, bool ACalculateDown = true);
	bool __fastcall IsClickedCell(TcxGridTableDataCellViewInfo* ACell);
	bool __fastcall IsPixelBasedScrollDataPos(void);
	bool __fastcall IsRecordPixelScrolling(void);
	void __fastcall PostCheckEdit(void);
	void __fastcall ProcessCheckEditPost(void);
	virtual void __fastcall ScrollData(Cxclasses::TcxDirection ADirection);
	void __fastcall SetClickedCellInfo(TcxGridTableDataCellViewInfo* ACell);
	virtual void __fastcall SetFocusedRecord(TcxCustomGridRecord* Value);
	virtual void __fastcall SetScrollBarPos(int Value);
	void __fastcall SetTopRecordIndexWithOffset(int ATopRecordIndex, int ATopRecordOffset);
	virtual int __fastcall VisibleDataScrollSize(void);
	void __fastcall CancelGridModeBufferCountUpdate(void);
	void __fastcall CheckGridModeBufferCountUpdatePost(void);
	void __fastcall PostGridModeBufferCountUpdate(void);
	__property bool GridModeBufferCountUpdateNeeded = {read=FGridModeBufferCountUpdateNeeded, nodefault};
	virtual void __fastcall AfterScrolling(void);
	virtual void __fastcall BeforeScrolling(void);
	virtual void __fastcall BeginGestureScroll(const System::Types::TPoint &APos);
	void __fastcall CheckPixelScrollTopRecordIndexAndOffsetValues(int &ATopRecordIndex, int &APixelScrollRecordOffset);
	virtual void __fastcall DoOverpan(Vcl::Forms::TScrollBarKind AScrollKind, int ADelta);
	void __fastcall UpdatePixelScrollTopRecordIndexAndOffsetMaxValues(void);
	virtual void __fastcall ScrollContentByGesture(Vcl::Forms::TScrollBarKind AScrollKind, int ADelta);
	virtual bool __fastcall CanScrollData(Cxclasses::TcxDirection ADirection);
	virtual int __fastcall GetScrollDataTimeInterval(Cxclasses::TcxDirection ADirection);
	__property Cxclasses::TcxDirection ScrollDirection = {read=FScrollDirection, write=SetScrollDirection, nodefault};
	virtual bool __fastcall CanPostponeRecordSelection(System::Classes::TShiftState AShift);
	virtual bool __fastcall CanProcessMultiSelect(bool AIsKeyboard)/* overload */;
	virtual bool __fastcall CanProcessMultiSelect(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift)/* overload */;
	virtual bool __fastcall CanProcessMultiSelect(System::Word AKey, System::Classes::TShiftState AShift, bool AFocusedRecordChanged)/* overload */;
	void __fastcall ChangeRecordSelection(TcxCustomGridRecord* ARecord, bool Value);
	void __fastcall CheckFocusedRecordSelectionWhenExit(TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoMouseNormalSelection(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall DoMouseRangeSelection(bool AClearSelection = true, System::TObject* AData = (System::TObject*)(0x0));
	virtual void __fastcall DoNormalSelection(void);
	void __fastcall DoNormalSelectionWithAnchor(bool ASelect = true);
	void __fastcall DoRangeSelection(bool AClearSelection = true);
	void __fastcall DoToggleRecordSelection(void);
	virtual void __fastcall FinishSelection(void);
	virtual void __fastcall InvalidateFocusedRecord(void);
	virtual void __fastcall InvalidateSelection(void);
	virtual bool __fastcall IsKeyForMultiSelect(System::Word AKey, System::Classes::TShiftState AShift, bool AFocusedRecordChanged);
	bool __fastcall IsRecordSelected(TcxCustomGridRecord* ARecord);
	virtual void __fastcall MultiSelectKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MultiSelectMouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	virtual void __fastcall MultiSelectMouseUp(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	void __fastcall SelectFocusedRecord(void);
	void __fastcall SetSelectionAnchor(int AGridRecordIndex);
	virtual bool __fastcall SupportsAdditiveSelection(void);
	virtual bool __fastcall SupportsRecordSelectionToggling(void);
	virtual bool __fastcall CanFocusNextItem(int AFocusedItemIndex, int ANextItemIndex, bool AGoForward, bool AGoOnCycle, bool AGoToNextRecordOnCycle);
	bool __fastcall FocusedRecordHasCells(bool ACheckCellSelectionAbility);
	virtual void __fastcall FocusNextPage(bool ASyncSelection);
	virtual void __fastcall FocusPrevPage(bool ASyncSelection);
	virtual int __fastcall GetPageRecordCount(void);
	virtual bool __fastcall IsKeyForController(System::Word AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall ScrollPage(bool AForward);
	virtual void __fastcall ScrollRecords(bool AForward, int ACount);
	virtual void __fastcall ShowNextPage(void);
	virtual void __fastcall ShowPrevPage(void);
	virtual void __fastcall DoPullFocusing(TcxGridRecordHitTest* AHitTest);
	virtual void __fastcall DoPullFocusingScrolling(Cxclasses::TcxDirection ADirection);
	virtual bool __fastcall GetPullFocusingScrollingDirection(int X, int Y, /* out */ Cxclasses::TcxDirection &ADirection);
	bool __fastcall IsPullFocusingPosChanged(void);
	void __fastcall SavePullFocusingPos(void);
	virtual void __fastcall StartPullFocusing(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	void __fastcall StopPullFocusing(void);
	void __fastcall StartPullFocusingScrolling(Cxclasses::TcxDirection ADirection);
	void __fastcall StopPullFocusingScrolling(void);
	virtual bool __fastcall SupportsPullFocusing(void);
	__property Cxgridcustomview::TcxCustomGridHitTest* PullFocusingOriginHitTest = {read=FPullFocusingOriginHitTest};
	virtual Cxclasses::TcxDirection __fastcall GetDragScrollDirection(int X, int Y);
	virtual int __fastcall GetDragScrollInterval(void);
	virtual bool __fastcall IsFirstRecordForDragScroll(TcxCustomGridRecord* ARecord);
	virtual bool __fastcall IsLastRecordForDragScroll(TcxCustomGridRecord* ARecord);
	void __fastcall ProcessDragFocusing(int X, int Y);
	void __fastcall StartDragScroll(Cxclasses::TcxDirection ADirection);
	void __fastcall StopDragScroll(void);
	bool __fastcall IsDragScroll(void);
	virtual Cxgridcommon::TcxCustomGridDragOpenInfo* __fastcall GetDragOpenInfo(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	bool __fastcall IsDragOpenHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, /* out */ Cxgridcommon::TcxCustomGridDragOpenInfo* &ADragOpenInfo);
	__property TcxCustomGridRecord* DragHighlightedRecord = {read=FDragHighlightedRecord, write=SetDragHighlightedRecord};
	virtual TcxCustomGridTableItem* __fastcall GetItemForIncSearching(void);
	virtual void __fastcall IncSearchKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	__property TcxCustomGridTableItem* ItemForIncSearching = {read=GetItemForIncSearching};
	virtual TcxGridEditingControllerClass __fastcall GetEditingControllerClass(void);
	__property bool AllowAppendRecord = {read=FAllowAppendRecord, write=FAllowAppendRecord, nodefault};
	__property bool AllowCheckEdit = {read=FAllowCheckEdit, write=FAllowCheckEdit, nodefault};
	__property bool BlockRecordKeyboardHandling = {read=FBlockRecordKeyboardHandling, write=FBlockRecordKeyboardHandling, nodefault};
	__property bool CancelEditingOnExit = {read=GetCancelEditingOnExit, nodefault};
	__property bool EatKeyPress = {read=FEatKeyPress, write=FEatKeyPress, nodefault};
	__property bool FocusOnRecordFocusing = {read=FFocusOnRecordFocusing, write=FFocusOnRecordFocusing, nodefault};
	__property TcxCustomGridTableItem* ForcingWidthItem = {read=FForcingWidthItem, write=FForcingWidthItem};
	__property int InternalTopRecordIndex = {read=FTopRecordIndex, write=SetInternalTopRecordIndex, nodefault};
	__property bool IsReadyForImmediateEditing = {read=FIsReadyForImmediateEditing, write=FIsReadyForImmediateEditing, nodefault};
	__property bool IsRecordsScrollHorizontal = {read=GetIsRecordsScrollHorizontal, nodefault};
	__property int LastVisibleRecordIndex = {read=GetLastVisibleRecordIndex, nodefault};
	__property bool MultiSelect = {read=GetMultiSelect, nodefault};
	__property int PixelScrollRecordOffset = {read=FPixelScrollRecordOffset, write=SetPixelScrollRecordOffset, nodefault};
	__property int ScrollBarOffsetBegin = {read=GetScrollBarOffsetBegin, nodefault};
	__property int ScrollBarOffsetEnd = {read=GetScrollBarOffsetEnd, nodefault};
	__property int ScrollBarRecordCount = {read=GetScrollBarRecordCount, nodefault};
	__property int ScrollBarPos = {read=GetScrollBarPos, write=SetScrollBarPos, nodefault};
	__property int ScrollDelta = {read=GetScrollDelta, nodefault};
	__property TcxCustomGridTableViewData* ViewData = {read=GetViewData};
	__property TcxCustomGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomGridTableController(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridTableController(void);
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall ControlFocusChanged(void);
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall DoKeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual int __fastcall FindNextItem(int AFocusedItemIndex, bool AGoForward, bool AGoOnCycle, bool AFollowVisualOrder, /* out */ bool &ACycleChanged, TcxCustomGridRecord* ARecord);
	int __fastcall FindNextRecord(int AFocusedRecordIndex, bool AGoForward, bool AGoOnCycle, /* out */ bool &ACycleChanged);
	bool __fastcall HasFilterMRUItemsPopup(void);
	bool __fastcall HasFilterPopup(void);
	virtual bool __fastcall HasFocusedControls(void);
	bool __fastcall HasItemsCustomizationPopup(void);
	virtual void __fastcall IMEStartComposition(void);
	bool __fastcall IsClickableRecordHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall IsDataFullyVisible(bool AIsCallFromMaster = false);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall ProcessDetailDialogChar(Cxgridcustomview::TcxCustomGridView* ADetail, System::Word ACharCode);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	virtual bool __fastcall SupportsTabAccelerators(TcxCustomGridRecord* AGridRecord);
	virtual void __fastcall BeforeStartDrag(void);
	virtual bool __fastcall CanDrag(int X, int Y);
	virtual void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall DrawDragImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual System::UnicodeString __fastcall GetDragDropText(Vcl::Controls::TDragObject* ADragObject);
	virtual void __fastcall GetDragDropTextViewParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual System::Types::TPoint __fastcall GetDragImagesSize(void);
	virtual bool __fastcall HasDragImages(void);
	virtual void __fastcall StartDrag(Vcl::Controls::TDragObject* &DragObject);
	__property System::UnicodeString DragDropText = {read=FDragDropText};
	void __fastcall CancelIncSearching(void);
	bool __fastcall CheckEditing(int &AFocusedRecordIndex, bool AGoForward);
	virtual void __fastcall CheckScrolling(const System::Types::TPoint &P);
	virtual void __fastcall ClearSelection(void);
	virtual void __fastcall CreateNewRecord(bool AtEnd);
	virtual void __fastcall DeleteSelection(void);
	bool __fastcall FocusFirstAvailableItem(void);
	bool __fastcall FocusNextCell(bool AGoForward, bool AProcessCellsOnly = true, bool AAllowCellsCycle = true, bool AFollowVisualOrder = true);
	bool __fastcall FocusNextItem(int AFocusedItemIndex, bool AGoForward, bool AGoOnCycle, bool AGoToNextRecordOnCycle, bool AFollowVisualOrder);
	bool __fastcall FocusNextRecord(int AFocusedRecordIndex, bool AGoForward, bool AGoOnCycle, bool AGoIntoDetail, bool AGoOutOfDetail);
	bool __fastcall FocusNextRecordWithSelection(int AFocusedRecordIndex, bool AGoForward, bool AGoOnCycle, bool AGoIntoDetail, bool ASyncSelection = true);
	bool __fastcall FocusRecord(int AFocusedRecordIndex, bool ASyncSelection);
	void __fastcall MakeFocusedItemVisible(void);
	void __fastcall MakeFocusedRecordVisible(void);
	virtual void __fastcall MakeItemVisible(TcxCustomGridTableItem* AItem) = 0 ;
	virtual void __fastcall MakeRecordVisible(TcxCustomGridRecord* ARecord);
	virtual void __fastcall SelectAll(void);
	void __fastcall SelectAllRecords(void);
	bool __fastcall GoToFirst(bool ASyncSelection = true);
	bool __fastcall GoToLast(bool AGoIntoDetail, bool ASyncSelection = true);
	bool __fastcall GoToNext(bool AGoIntoDetail, bool ASyncSelection = true);
	bool __fastcall GoToPrev(bool AGoIntoDetail, bool ASyncSelection = true);
	bool __fastcall IsFinish(void);
	bool __fastcall IsStart(void);
	__property TcxGridTableDataCellViewInfo* ClickedCellViewInfo = {read=FClickedCellViewInfo, write=FClickedCellViewInfo};
	__property TcxGridEditingController* EditingController = {read=FEditingController};
	__property TcxCustomGridTableItem* EditingItem = {read=GetEditingItem, write=SetEditingItem};
	__property TcxGridFilterMRUItemsPopup* FilterMRUItemsPopup = {read=GetFilterMRUItemsPopup};
	__property TcxGridFilterPopup* FilterPopup = {read=GetFilterPopup};
	__property TcxCustomGridTableItem* FocusedItem = {read=FFocusedItem, write=SetFocusedItem};
	__property int FocusedItemIndex = {read=GetFocusedItemIndex, write=SetFocusedItemIndex, nodefault};
	__property TcxCustomGridRecord* FocusedRecord = {read=GetFocusedRecord, write=SetFocusedRecord};
	__property int FocusedRecordIndex = {read=GetFocusedRecordIndex, write=SetFocusedRecordIndex, nodefault};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridTableItem* IncSearchingItem = {read=GetIncSearchingItem};
	__property System::UnicodeString IncSearchingText = {read=GetIncSearchingText, write=SetIncSearchingText};
	__property bool IsPullFocusing = {read=FIsPullFocusing, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property bool IsIncSearching = {read=GetIsIncSearching, nodefault};
	__property bool IsItemMoving = {read=GetIsItemMoving, nodefault};
	__property TcxCustomGridItemsCustomizationPopup* ItemsCustomizationPopup = {read=GetItemsCustomizationPopup};
	__property TcxCustomGridTableController* MasterController = {read=GetMasterController};
	__property TcxCustomGridTableItem* MovingItem = {read=FMovingItem};
	__property bool NewItemRecordFocused = {read=GetNewItemRecordFocused, write=SetNewItemRecordFocused, nodefault};
	__property int PrevFocusedRecordIndex = {read=GetPrevFocusedRecordIndex, write=FPrevFocusedRecordIndex, nodefault};
	__property int SelectedRecordCount = {read=GetSelectedRecordCount, nodefault};
	__property TcxCustomGridRecord* SelectedRecords[int Index] = {read=GetSelectedRecord};
	__property int TopRecordIndex = {read=FTopRecordIndex, write=SetTopRecordIndex, nodefault};
};


class DELPHICLASS TcxCustomGridPartPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridPartPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxCustomGridPartPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridPartPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridFilterButtonPainter;
class DELPHICLASS TcxCustomGridFilterButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridFilterButtonPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxCustomGridFilterButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall ExcludeFromClipRect(void);
	__property TcxCustomGridFilterButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxCustomGridFilterButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridFilterButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterCloseButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterCloseButtonPainter : public TcxCustomGridFilterButtonPainter
{
	typedef TcxCustomGridFilterButtonPainter inherited;
	
protected:
	virtual void __fastcall DrawContent(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridFilterCloseButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridFilterButtonPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFilterCloseButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterActivateButtonPainter;
class DELPHICLASS TcxGridFilterActivateButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterActivateButtonPainter : public TcxCustomGridFilterButtonPainter
{
	typedef TcxCustomGridFilterButtonPainter inherited;
	
private:
	HIDESBASE TcxGridFilterActivateButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	__property TcxGridFilterActivateButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridFilterActivateButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridFilterButtonPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFilterActivateButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterDropDownButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterDropDownButtonPainter : public TcxCustomGridFilterButtonPainter
{
	typedef TcxCustomGridFilterButtonPainter inherited;
	
protected:
	virtual void __fastcall DrawContent(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridFilterDropDownButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridFilterButtonPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFilterDropDownButtonPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterCustomizeButtonPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterCustomizeButtonPainter : public TcxCustomGridFilterButtonPainter
{
	typedef TcxCustomGridFilterButtonPainter inherited;
	
protected:
	virtual void __fastcall Paint(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridFilterCustomizeButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridFilterButtonPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFilterCustomizeButtonPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridFilterPainterClass;

class DELPHICLASS TcxGridFilterPainter;
class DELPHICLASS TcxGridFilterViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterPainter : public TcxCustomGridPartPainter
{
	typedef TcxCustomGridPartPainter inherited;
	
private:
	bool FTextWasUnderlined;
	TcxGridFilterViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(const System::Types::TRect &R)/* overload */;
	virtual void __fastcall DrawButtons(void);
	virtual bool __fastcall ExcludeFromClipRect(void);
	virtual void __fastcall Paint(void);
	virtual void __fastcall PrepareCanvasForDrawText(void);
	virtual void __fastcall UnprepareCanvasForDrawText(void);
	__property TcxGridFilterViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridFilterPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : TcxCustomGridPartPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridFilterPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(void){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridTableDataCellPainterClass;

class DELPHICLASS TcxGridTableDataCellPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTableDataCellPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridTableDataCellViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContent(void);
	virtual bool __fastcall CanDrawFocusRect(void);
	virtual void __fastcall DoDrawFocusRect(void);
	void __fastcall DrawFocusRect(void);
	virtual System::Types::TRect __fastcall GetFocusRect(void);
	virtual void __fastcall Paint(void);
	__property TcxGridTableDataCellViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridTableDataCellPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridTableDataCellPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridRecordPainterClass;

class DELPHICLASS TcxCustomGridRecordPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridRecordPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxCustomGridRecordViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeforePaint(void);
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual void __fastcall DrawExpandButton(void);
	virtual bool __fastcall DrawExpandButtonBeforePaint(void);
	virtual void __fastcall DrawFocusRect(void);
	virtual void __fastcall Paint(void);
	__property TcxCustomGridRecordViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxCustomGridRecordPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridRecordPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridRecordsPainterClass;

class DELPHICLASS TcxCustomGridRecordsPainter;
class DELPHICLASS TcxCustomGridRecordsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridRecordsPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	TcxCustomGridRecordsViewInfo* FViewInfo;
	
protected:
	virtual void __fastcall Paint(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property TcxCustomGridRecordsViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxCustomGridRecordsPainter(Cxgraphics::TcxCanvas* ACanvas, TcxCustomGridRecordsViewInfo* AViewInfo);
	void __fastcall MainPaint(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridRecordsPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxNavigatorSitePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNavigatorSitePainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
protected:
	virtual bool __fastcall ExcludeFromClipRect(void);
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxNavigatorSitePainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxNavigatorSitePainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTablePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTablePainter : public Cxgridcustomview::TcxCustomGridPainter
{
	typedef Cxgridcustomview::TcxCustomGridPainter inherited;
	
private:
	HIDESBASE TcxCustomGridTableController* __fastcall GetController(void);
	HIDESBASE TcxCustomGridTableViewInfo* __fastcall GetViewInfo(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	
protected:
	virtual bool __fastcall CanOffset(int AItemsOffset, int DX, int DY);
	virtual void __fastcall DrawBackground(void);
	virtual void __fastcall DrawFilterBar(void);
	virtual void __fastcall DrawInfoText(void);
	virtual void __fastcall DrawNavigator(void);
	virtual void __fastcall DrawRecords(void);
	virtual void __fastcall Offset(int AItemsOffset)/* overload */;
	virtual void __fastcall Offset(int DX, int DY)/* overload */;
	virtual void __fastcall PaintBefore(void);
	virtual void __fastcall PaintContent(void);
	
public:
	void __fastcall DoOffset(int AItemsOffset, int DX, int DY);
	virtual void __fastcall DrawFocusRect(const System::Types::TRect &R, bool AHideFocusRect);
	__property TcxCustomGridTableController* Controller = {read=GetController};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridTableViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxCustomGridTablePainter(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridPainter(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridTablePainter(void) { }
	
};

#pragma pack(pop)

enum TcxGridPartAlignment : unsigned char { gpaTop, gpaBottom };

class DELPHICLASS TcxCustomGridPartViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridPartViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	int FHeight;
	HIDESBASE TcxCustomGridTableView* __fastcall GetGridView(void);
	TcxCustomGridTableViewInfo* __fastcall GetGridViewInfo(void);
	int __fastcall GetIndex(void);
	void __fastcall SetIndex(int Value);
	
protected:
	virtual System::Types::TRect __fastcall CalculateBounds(void);
	virtual void __fastcall CalculateInvisible(void);
	virtual void __fastcall CalculateVisible(void);
	virtual bool __fastcall CustomDrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxGridPartAlignment __fastcall GetAlignment(void) = 0 ;
	virtual bool __fastcall GetIsAutoWidth(void) = 0 ;
	virtual bool __fastcall GetIsPart(void);
	virtual bool __fastcall GetIsScrollable(void) = 0 ;
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall HasCustomDrawBackground(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	__property int Height = {read=FHeight, write=FHeight, nodefault};
	__property bool IsPart = {read=GetIsPart, nodefault};
	
public:
	__fastcall virtual TcxCustomGridPartViewInfo(TcxCustomGridTableViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxCustomGridPartViewInfo(void);
	void __fastcall MainCalculate(void);
	__property TcxGridPartAlignment Alignment = {read=GetAlignment, nodefault};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
	__property bool IsAutoWidth = {read=GetIsAutoWidth, nodefault};
	__property bool IsScrollable = {read=GetIsScrollable, nodefault};
};

#pragma pack(pop)

enum TcxGridFilterButtonAlignment : unsigned char { fbaLeft, fbaRight };

typedef System::TMetaClass* TcxCustomGridFilterButtonViewInfoClass;

class DELPHICLASS TcxGridFilterButtonsViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridFilterButtonViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridFilterButtonsViewInfo* FContainer;
	Cxcustomdata::TcxDataFilterCriteria* __fastcall GetFilter(void);
	HIDESBASE TcxCustomGridTableView* __fastcall GetGridView(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual int __fastcall DoCalculateHeight(void) = 0 ;
	virtual int __fastcall DoCalculateWidth(void) = 0 ;
	virtual TcxGridFilterButtonAlignment __fastcall GetAlignment(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual bool __fastcall GetVisible(void);
	__property TcxGridFilterButtonsViewInfo* Container = {read=FContainer};
	__property Cxcustomdata::TcxDataFilterCriteria* Filter = {read=GetFilter};
	
public:
	__fastcall virtual TcxCustomGridFilterButtonViewInfo(TcxGridFilterButtonsViewInfo* AContainer);
	__property TcxGridFilterButtonAlignment Alignment = {read=GetAlignment, nodefault};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxCustomGridFilterButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterCloseButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterCloseButtonViewInfo : public TcxCustomGridFilterButtonViewInfo
{
	typedef TcxCustomGridFilterButtonViewInfo inherited;
	
protected:
	virtual void __fastcall Click(void);
	virtual int __fastcall DoCalculateHeight(void);
	virtual int __fastcall DoCalculateWidth(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
public:
	/* TcxCustomGridFilterButtonViewInfo.Create */ inline __fastcall virtual TcxGridFilterCloseButtonViewInfo(TcxGridFilterButtonsViewInfo* AContainer) : TcxCustomGridFilterButtonViewInfo(AContainer) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridFilterCloseButtonViewInfo(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterActivateButtonViewInfo : public TcxCustomGridFilterButtonViewInfo
{
	typedef TcxCustomGridFilterButtonViewInfo inherited;
	
private:
	bool __fastcall GetChecked(void);
	
protected:
	virtual void __fastcall Click(void);
	virtual int __fastcall DoCalculateHeight(void);
	virtual int __fastcall DoCalculateWidth(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	
public:
	__property bool Checked = {read=GetChecked, nodefault};
public:
	/* TcxCustomGridFilterButtonViewInfo.Create */ inline __fastcall virtual TcxGridFilterActivateButtonViewInfo(TcxGridFilterButtonsViewInfo* AContainer) : TcxCustomGridFilterButtonViewInfo(AContainer) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridFilterActivateButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterDropDownButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterDropDownButtonViewInfo : public TcxCustomGridFilterButtonViewInfo
{
	typedef TcxCustomGridFilterButtonViewInfo inherited;
	
private:
	TcxGridFilterMRUItemsPopup* __fastcall GetDropDownWindowValue(void);
	
protected:
	virtual void __fastcall BeforeStateChange(void);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual int __fastcall DoCalculateHeight(void);
	virtual int __fastcall DoCalculateWidth(void);
	virtual TcxGridFilterButtonAlignment __fastcall GetAlignment(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall DropDownWindowExists(void);
	virtual Cxgridcustomview::TcxCustomGridPopup* __fastcall GetDropDownWindow(void);
	virtual System::Types::TRect __fastcall GetDropDownWindowOwnerBounds(void);
	__property TcxGridFilterMRUItemsPopup* DropDownWindow = {read=GetDropDownWindowValue};
	
public:
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
public:
	/* TcxCustomGridFilterButtonViewInfo.Create */ inline __fastcall virtual TcxGridFilterDropDownButtonViewInfo(TcxGridFilterButtonsViewInfo* AContainer) : TcxCustomGridFilterButtonViewInfo(AContainer) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridFilterDropDownButtonViewInfo(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterCustomizeButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterCustomizeButtonViewInfo : public TcxCustomGridFilterButtonViewInfo
{
	typedef TcxCustomGridFilterButtonViewInfo inherited;
	
protected:
	virtual void __fastcall Click(void);
	virtual int __fastcall DoCalculateHeight(void);
	virtual int __fastcall DoCalculateWidth(void);
	virtual TcxGridFilterButtonAlignment __fastcall GetAlignment(void);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Cxgraphics::TcxBorders __fastcall GetBorders(void);
	virtual int __fastcall GetBorderWidth(Cxgraphics::TcxBorder AIndex);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
public:
	/* TcxCustomGridFilterButtonViewInfo.Create */ inline __fastcall virtual TcxGridFilterCustomizeButtonViewInfo(TcxGridFilterButtonsViewInfo* AContainer) : TcxCustomGridFilterButtonViewInfo(AContainer) { }
	
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridFilterCustomizeButtonViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridFilterButtonsViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterButtonsViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomGridFilterButtonViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TcxGridFilterViewInfo* FFilterViewInfo;
	Dxcoreclasses::TdxFastObjectList* FItems;
	int __fastcall GetCount(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	int __fastcall GetHeight(void);
	TcxCustomGridFilterButtonViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetWidth(TcxGridFilterButtonAlignment AAlignment);
	int __fastcall GetWidthLeftPart(void);
	int __fastcall GetWidthRightPart(void);
	
protected:
	TcxGridFilterDropDownButtonViewInfo* FDropDownButtonViewInfo;
	virtual void __fastcall AddItems(void);
	virtual void __fastcall DestroyItems(void);
	__property TcxGridFilterViewInfo* FilterViewInfo = {read=FFilterViewInfo};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxGridFilterButtonsViewInfo(TcxGridFilterViewInfo* AFilterViewInfo);
	__fastcall virtual ~TcxGridFilterButtonsViewInfo(void);
	TcxCustomGridFilterButtonViewInfo* __fastcall AddItem(TcxCustomGridFilterButtonViewInfoClass AItemClass);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property int Count = {read=GetCount, nodefault};
	__property TcxGridFilterDropDownButtonViewInfo* DropDownButtonViewInfo = {read=FDropDownButtonViewInfo};
	__property int Height = {read=GetHeight, nodefault};
	__property TcxCustomGridFilterButtonViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int WidthLeftPart = {read=GetWidthLeftPart, nodefault};
	__property int WidthRightPart = {read=GetWidthRightPart, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridFilterViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterViewInfo : public TcxCustomGridPartViewInfo
{
	typedef TcxCustomGridPartViewInfo inherited;
	
private:
	TcxGridFilterButtonsViewInfo* FButtonsViewInfo;
	Cxcustomdata::TcxDataFilterCriteria* __fastcall GetFilter(void);
	TcxCustomGridTableFiltering* __fastcall GetFiltering(void);
	void __fastcall CreateButtonsViewInfo(void);
	void __fastcall DestroyButtonsViewInfo(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculateButtonsViewInfoBounds(void);
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual TcxGridPartAlignment __fastcall GetAlignment(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual bool __fastcall GetIsAutoWidth(void);
	virtual bool __fastcall GetIsCheck(void);
	virtual bool __fastcall GetIsScrollable(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall HasMouse(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall InvalidateOnStateChange(void);
	virtual void __fastcall StateChanged(Cxgridcommon::TcxGridCellState APrevState);
	virtual TcxGridFilterButtonsViewInfoClass __fastcall GetButtonsViewInfoClass(void);
	__property Cxcustomdata::TcxDataFilterCriteria* Filter = {read=GetFilter};
	__property TcxCustomGridTableFiltering* Filtering = {read=GetFiltering};
	
public:
	__fastcall virtual TcxGridFilterViewInfo(TcxCustomGridTableViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxGridFilterViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property TcxGridFilterButtonsViewInfo* ButtonsViewInfo = {read=FButtonsViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridTableCellViewInfo;
class DELPHICLASS TcxCustomGridTableViewInfoCacheItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTableCellViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxCustomGridRecordViewInfo* FRecordViewInfo;
	bool FSelected;
	bool FSelectedCalculated;
	TcxCustomGridTableViewInfoCacheItem* __fastcall GetCacheItem(void);
	HIDESBASE TcxCustomGridTableController* __fastcall GetController(void);
	HIDESBASE TcxCustomGridTableView* __fastcall GetGridView(void);
	TcxCustomGridRecord* __fastcall GetGridRecord(void);
	bool __fastcall GetSelected(void);
	
protected:
	virtual bool __fastcall CalculateSelected(void);
	virtual bool __fastcall GetAlwaysSelected(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	TcxCustomGridTableViewInfo* __fastcall GetGridViewInfo(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetTransparent(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	__property bool AlwaysSelected = {read=GetAlwaysSelected, nodefault};
	__property TcxCustomGridTableViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property TcxCustomGridTableController* Controller = {read=GetController};
	
public:
	__fastcall virtual TcxGridTableCellViewInfo(TcxCustomGridRecordViewInfo* ARecordViewInfo);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall CanDrawSelected(void);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxCustomGridRecord* GridRecord = {read=GetGridRecord};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxCustomGridRecordViewInfo* RecordViewInfo = {read=FRecordViewInfo};
	__property bool Selected = {read=GetSelected, nodefault};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridTableCellViewInfo(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridTableDataCellViewInfo : public TcxGridTableCellViewInfo
{
	typedef TcxGridTableCellViewInfo inherited;
	
private:
	Cxedit::TcxCustomEditViewData* FEditViewData;
	Cxedit::TcxCustomEditViewInfo* FEditViewInfo;
	bool FIsLocalCopyOfEditViewData;
	TcxCustomGridTableItem* FItem;
	Cxedit::TcxCustomEditProperties* FProperties;
	Cxedit::TcxEditStyle* FStyle;
	bool FWasFocusedBeforeClick;
	bool __fastcall GetEditing(void);
	System::Types::TPoint __fastcall GetMousePos(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void);
	bool __fastcall GetShowButtons(void);
	
protected:
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall BeforeCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall CalculateEditViewInfo(Cxedit::TcxCustomEditViewInfo* AEditViewInfo, const System::Types::TPoint &AMousePos);
	virtual int __fastcall CalculateHeight(void);
	virtual bool __fastcall CalculateSelected(void);
	virtual bool __fastcall CanActivateEditOnMouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall CanImmediateEdit(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall CanShowEdit(void);
	void __fastcall CheckEditHotTrack(const System::Types::TPoint &AMousePos);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoCalculateParams(void);
	void __fastcall EditHotTrackChanged(void);
	virtual System::Types::TRect __fastcall GetAreaBounds(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual System::Variant __fastcall GetDisplayValue(void);
	virtual System::Types::TRect __fastcall GetEditBounds(void);
	System::Types::TSize __fastcall GetEditSize(const Cxedit::TcxEditSizeProperties &AEditSizeProperties);
	virtual System::Types::TRect __fastcall GetEditViewDataBounds(void);
	virtual void __fastcall GetEditViewDataContentOffsets(System::Types::TRect &R);
	virtual bool __fastcall GetFocused(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual int __fastcall GetMaxLineCount(void);
	virtual bool __fastcall GetMultiLine(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetShowEndEllipsis(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::Variant __fastcall GetValue(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall HasCustomDraw(void);
	virtual bool __fastcall HasFocusRect(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual void __fastcall InitTextSelection(void);
	virtual bool __fastcall InvalidateOnStateChange(void);
	virtual bool __fastcall IsTextSelected(void);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall RestoreParams(const Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall SaveParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall StateChanged(Cxgridcommon::TcxGridCellState APrevState);
	virtual bool __fastcall SupportsZeroHeight(void);
	virtual bool __fastcall CanShowAutoHint(void);
	virtual bool __fastcall CanShowCustomHint(void);
	virtual bool __fastcall CanShowHint(void);
	virtual System::Types::TRect __fastcall GetCellBoundsForHint(void);
	virtual bool __fastcall NeedShowHint(const System::Types::TPoint &AMousePos, /* out */ Vcl::Controls::TCaption &AHintText, /* out */ bool &AIsHintMultiLine, /* out */ System::Types::TRect &ATextRect);
	virtual bool __fastcall UseStandardNeedShowHint(void);
	virtual void __fastcall InitStyle(void);
	virtual void __fastcall ValidateDrawValue(void);
	Cxedit::TcxCustomEditViewInfo* __fastcall CreateEditViewInfo(void);
	void __fastcall CreateEditViewData(void);
	void __fastcall DestroyEditViewData(void);
	void __fastcall UpdateEdit(void);
	Cxedit::TcxCustomEditViewData* __fastcall EditOwnerGetViewData(/* out */ bool &AIsViewDataCreated);
	void __fastcall EditOwnerInvalidate(const System::Types::TRect &R, bool AEraseBackground = true);
	__property bool AutoHeight = {read=GetAutoHeight, nodefault};
	__property Cxedit::TcxCustomEditViewData* EditViewData = {read=FEditViewData};
	__property System::Types::TRect EditViewDataBounds = {read=GetEditViewDataBounds};
	__property int MaxLineCount = {read=GetMaxLineCount, nodefault};
	__property System::Types::TPoint MousePos = {read=GetMousePos};
	__property bool ShowButtons = {read=GetShowButtons, nodefault};
	__property bool WasFocusedBeforeClick = {read=FWasFocusedBeforeClick, nodefault};
	
public:
	__fastcall virtual TcxGridTableDataCellViewInfo(TcxCustomGridRecordViewInfo* ARecordViewInfo, TcxCustomGridTableItem* AItem);
	__fastcall virtual ~TcxGridTableDataCellViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall CanDrawSelected(void);
	Cxedit::TcxInplaceEditPosition __fastcall GetInplaceEditPosition(void);
	HIDESBASE virtual void __fastcall Invalidate(bool ARecalculate);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall MouseMove(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	virtual bool __fastcall MouseUp(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property System::Variant DisplayValue = {read=GetDisplayValue};
	__property System::Types::TRect EditBounds = {read=GetEditBounds};
	__property bool Editing = {read=GetEditing, nodefault};
	__property Cxedit::TcxCustomEditViewInfo* EditViewInfo = {read=FEditViewInfo};
	__property bool Focused = {read=GetFocused, nodefault};
	__property TcxCustomGridTableItem* Item = {read=FItem};
	__property Cxedit::TcxCustomEditProperties* Properties = {read=GetProperties};
	__property Cxedit::TcxEditStyle* Style = {read=FStyle};
	__property System::Variant Value = {read=GetValue};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
private:
	void *__IcxEditOwner;	/* Cxedit::IcxEditOwner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4129100C-7FC6-436E-8711-47A5C978CA73}
	operator Cxedit::_di_IcxEditOwner()
	{
		Cxedit::_di_IcxEditOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditOwner*(void) { return (Cxedit::IcxEditOwner*)&__IcxEditOwner; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridRecordViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	System::Types::TRect FExpandButtonBounds;
	bool FExpanded;
	bool FExpandedCalculated;
	bool FIsRecordViewInfoAssigned;
	TcxCustomGridRecordsViewInfo* FRecordsViewInfo;
	bool FSelected;
	bool FSelectedCalculated;
	TcxCustomGridTableViewInfoCacheItem* __fastcall GetCacheItem(void);
	bool __fastcall GetExpanded(void);
	bool __fastcall GetFocused(void);
	HIDESBASE TcxCustomGridTableView* __fastcall GetGridView(void);
	TcxCustomGridTableViewInfo* __fastcall GetGridViewInfo(void);
	int __fastcall GetIndex(void);
	bool __fastcall GetSelected(void);
	
protected:
	TcxCustomGridRecord* FRecord;
	virtual bool __fastcall AdjustToIntegralBottomBound(int &ABound);
	virtual void __fastcall CalculateExpandButtonBounds(System::Types::TRect &ABounds) = 0 ;
	virtual int __fastcall CalculateMultilineEditMinHeight(void);
	virtual bool __fastcall CalculateSelected(void);
	virtual bool __fastcall CanGenerateExpandButtonHitTest(void);
	virtual bool __fastcall CanShowDataCellHint(void);
	virtual void __fastcall ControlFocusChanged(void);
	virtual bool __fastcall GetAutoHeight(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual System::Types::TRect __fastcall GetBackgroundBounds(void);
	virtual System::Types::TRect __fastcall GetBackgroundBitmapBounds(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual bool __fastcall GetCellTransparent(TcxGridTableCellViewInfo* ACell);
	HIDESBASE virtual System::Types::TRect __fastcall GetContentBounds(void);
	virtual System::Types::TRect __fastcall GetExpandButtonAreaBounds(void);
	virtual System::Types::TRect __fastcall GetFocusRectBounds(void);
	virtual bool __fastcall GetFullyVisible(void);
	virtual int __fastcall GetHeight(void);
	virtual bool __fastcall GetHideFocusRectOnExit(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual int __fastcall GetPixelScrollSize(void);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall HasFocusRect(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall IsClickHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall IsDetailVisible(Cxgridcustomview::TcxCustomGridView* ADetail);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall VisibilityChanged(bool AVisible);
	__property bool AutoHeight = {read=GetAutoHeight, nodefault};
	__property System::Types::TRect BackgroundBitmapBounds = {read=GetBackgroundBitmapBounds};
	__property TcxCustomGridTableViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property System::Types::TRect ExpandButtonAreaBounds = {read=GetExpandButtonAreaBounds};
	__property bool Expanded = {read=GetExpanded, nodefault};
	
public:
	__fastcall virtual TcxCustomGridRecordViewInfo(TcxCustomGridRecordsViewInfo* ARecordsViewInfo, TcxCustomGridRecord* ARecord);
	__fastcall virtual ~TcxCustomGridRecordViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	HIDESBASE virtual bool __fastcall Click(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual System::Types::TRect __fastcall GetBoundsForInvalidate(TcxCustomGridTableItem* AItem);
	virtual System::Types::TRect __fastcall GetBoundsForItem(TcxCustomGridTableItem* AItem);
	virtual TcxGridTableDataCellViewInfo* __fastcall GetCellViewInfoByItem(TcxCustomGridTableItem* AItem);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual void __fastcall MainCalculate(int ALeftBound, int ATopBound);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall ProcessDialogChar(System::Word ACharCode);
	HIDESBASE void __fastcall Recalculate(void);
	__property System::Types::TRect ContentBounds = {read=GetContentBounds};
	__property System::Types::TRect ExpandButtonBounds = {read=FExpandButtonBounds};
	__property bool Focused = {read=GetFocused, nodefault};
	__property System::Types::TRect FocusRectBounds = {read=GetFocusRectBounds};
	__property bool FullyVisible = {read=GetFullyVisible, nodefault};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridRecord* GridRecord = {read=FRecord};
	__property TcxCustomGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property int Index = {read=GetIndex, nodefault};
	__property bool HideFocusRectOnExit = {read=GetHideFocusRectOnExit, nodefault};
	__property TcxCustomGridRecordsViewInfo* RecordsViewInfo = {read=FRecordsViewInfo};
	__property bool Selected = {read=GetSelected, nodefault};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridRecordsViewInfoClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridRecordsViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomGridRecordViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	Vcl::Graphics::TBitmap* FBackgroundBitmap;
	System::Types::TRect FBounds;
	System::Types::TRect FContentBounds;
	TcxCustomGridTableViewInfo* FGridViewInfo;
	TcxGridTableDataCellViewInfo* FIncSearchingCellViewInfo;
	bool FIsIncSearchingCellViewInfoCalculated;
	bool FIsPixelScrollInfoCalculating;
	Dxcoreclasses::TdxFastObjectList* FItems;
	int FItemsOffset;
	System::Types::TRect FPrevFocusedItemBounds;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	TcxCustomGridTableController* __fastcall GetController(void);
	int __fastcall GetCount(void);
	int __fastcall GetFirstRecordIndex(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	TcxGridTableDataCellViewInfo* __fastcall GetIncSearchingCellViewInfo(void);
	TcxCustomGridRecordViewInfo* __fastcall GetItem(int Index);
	int __fastcall GetMaxCount(void);
	int __fastcall GetTopRecordIndex(void);
	TcxCustomGridTableViewData* __fastcall GetViewData(void);
	void __fastcall CreateItems(void);
	void __fastcall DestroyItems(void);
	TcxCustomGridRecordViewInfo* __fastcall CreateRecordViewInfo(int AIndex)/* overload */;
	
protected:
	int FPartVisibleCount;
	int FVisibleCount;
	int __fastcall AddRecordViewInfo(TcxCustomGridRecordViewInfo* AViewInfo);
	void __fastcall AdjustEditorBoundsToIntegralHeight(System::Types::TRect &AEditorBounds);
	virtual void __fastcall AfterCalculate(void);
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall BeforeCalculate(void);
	virtual void __fastcall BeforeItemRecalculation(void);
	virtual void __fastcall AfterOffset(void);
	virtual void __fastcall BeforeOffset(void);
	virtual void __fastcall Calculate(void);
	virtual System::Types::TRect __fastcall CalculateBounds(void);
	virtual System::Types::TRect __fastcall CalculateContentBounds(void);
	virtual TcxGridTableDataCellViewInfo* __fastcall CalculateIncSearchingCellViewInfo(void);
	virtual void __fastcall CalculatePixelScrollInfo(int &ARecordIndex, int &ARecordOffset, int AMaxRecordIndex, int AMaxRecordOffset, int ADelta, /* out */ bool &AOverPan);
	virtual void __fastcall CalculateVisibleCount(void);
	void __fastcall Clear(void);
	void __fastcall CreateEditViewDatas(void);
	TcxCustomGridRecordViewInfo* __fastcall CreateRecordViewInfo(TcxCustomGridRecord* ARecord)/* overload */;
	void __fastcall DestroyEditViewDatas(void);
	virtual System::Types::TRect __fastcall GetAreaBoundsForCell(TcxGridTableDataCellViewInfo* ACellViewInfo);
	virtual bool __fastcall GetAutoDataCellHeight(void);
	virtual bool __fastcall GetAutoDataRecordHeight(void);
	virtual bool __fastcall GetAutoRecordHeight(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetBackgroundBitmap(void);
	virtual int __fastcall GetPixelScrollContentSize(void);
	virtual int __fastcall GetItemLeftBound(int AIndex) = 0 ;
	virtual int __fastcall GetItemsOffset(int AItemCountDelta) = 0 ;
	virtual int __fastcall GetItemTopBound(int AIndex) = 0 ;
	int __fastcall GetRecordIndex(int AViewInfoIndex);
	int __fastcall GetRecordScrollSize(int ARecordIndex);
	TcxCustomGridRecordViewInfo* __fastcall GetRecordViewInfo(int ARecordIndex, /* out */ bool &ANewlyCreated);
	int __fastcall GetViewInfoIndex(int ARecordIndex);
	virtual bool __fastcall IsEmpty(void);
	virtual void __fastcall OffsetItem(int AIndex, int AOffset) = 0 ;
	virtual void __fastcall ControlFocusChanged(void);
	virtual void __fastcall VisibilityChanged(bool AVisible);
	virtual TcxCustomGridRecordsPainterClass __fastcall GetPainterClass(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property TcxCustomGridTableController* Controller = {read=GetController};
	__property int FirstRecordIndex = {read=GetFirstRecordIndex, nodefault};
	__property TcxCustomGridTableViewInfo* GridViewInfo = {read=FGridViewInfo};
	__property TcxGridTableDataCellViewInfo* IncSearchingCellViewInfo = {read=GetIncSearchingCellViewInfo};
	__property bool IsPixelScrollInfoCalculating = {read=FIsPixelScrollInfoCalculating, nodefault};
	__property int MaxCount = {read=GetMaxCount, nodefault};
	__property int TopRecordIndex = {read=GetTopRecordIndex, nodefault};
	__property TcxCustomGridTableViewData* ViewData = {read=GetViewData};
	
public:
	__fastcall virtual TcxCustomGridRecordsViewInfo(TcxCustomGridTableViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxCustomGridRecordsViewInfo(void);
	virtual bool __fastcall CanOffset(int AItemCountDelta);
	virtual int __fastcall GetCellHeight(int ACellContentHeight);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	virtual TcxCustomGridRecordViewInfo* __fastcall GetRealItem(TcxCustomGridRecord* ARecord);
	virtual bool __fastcall IsCellMultiLine(TcxCustomGridTableItem* AItem);
	virtual void __fastcall MainCalculate(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall OffsetRecords(int AItemCountDelta, int APixelScrollRecordOffsetDelta);
	void __fastcall Paint(void);
	__property bool AutoDataCellHeight = {read=GetAutoDataCellHeight, nodefault};
	__property bool AutoDataRecordHeight = {read=GetAutoDataRecordHeight, nodefault};
	__property bool AutoRecordHeight = {read=GetAutoRecordHeight, nodefault};
	__property Vcl::Graphics::TBitmap* BackgroundBitmap = {read=FBackgroundBitmap, write=FBackgroundBitmap};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::Types::TRect ContentBounds = {read=FContentBounds};
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridRecordViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property int ItemsOffset = {read=FItemsOffset, nodefault};
	__property int PartVisibleCount = {read=FPartVisibleCount, nodefault};
	__property System::Types::TRect PrevFocusedItemBounds = {read=FPrevFocusedItemBounds, write=FPrevFocusedItemBounds};
	__property int VisibleCount = {read=FVisibleCount, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxGridCustomTableNavigatorViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCustomTableNavigatorViewInfo : public Cxnavigator::TcxInplaceNavigatorViewInfo
{
	typedef Cxnavigator::TcxInplaceNavigatorViewInfo inherited;
	
private:
	TcxCustomGridTableViewInfo* FGridViewInfo;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetControl(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	virtual int __fastcall GetNavigatorOffset(void);
	virtual void __fastcall UpdateNavigatorSiteBounds(const System::Types::TRect &ABounds);
	
public:
	__fastcall virtual TcxGridCustomTableNavigatorViewInfo(TcxCustomGridTableViewInfo* AGridViewInfo);
public:
	/* TcxNavigatorViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCustomTableNavigatorViewInfo(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridCustomTableNavigatorViewInfoClass;

typedef System::TMetaClass* TcxNavigatorSiteViewInfoClass;

class DELPHICLASS TcxNavigatorSiteViewInfo;
class DELPHICLASS TcxGridViewNavigator;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxNavigatorSiteViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	int FCalculatedHeight;
	TcxGridCustomTableNavigatorViewInfo* FNavigatorViewInfo;
	TcxCustomGridTableViewInfo* __fastcall GetGridViewInfo(void);
	TcxGridViewNavigator* __fastcall GetNavigator(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	void __fastcall CalculateNavigator(void);
	virtual int __fastcall CalculateWidth(void);
	virtual int __fastcall GetHeight(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	System::Types::TRect __fastcall GetNavigatorBounds(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall MouseLeave(void);
	void __fastcall NavigatorStateChanged(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual int __fastcall GetWidth(void);
	bool __fastcall IsNavigatorSizeChanged(void);
	void __fastcall ResetCalculatedHeight(void);
	__property TcxGridViewNavigator* Navigator = {read=GetNavigator};
	
public:
	__fastcall virtual TcxNavigatorSiteViewInfo(Cxgridcustomview::TcxCustomGridViewInfo* AGridViewInfo);
	__fastcall virtual ~TcxNavigatorSiteViewInfo(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall MouseMove(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Classes::TShiftState AShift);
	virtual bool __fastcall MouseUp(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxCustomGridTableViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridCustomTableNavigatorViewInfo* NavigatorViewInfo = {read=FNavigatorViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableViewInfo : public Cxgridcustomview::TcxCustomGridViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewInfo inherited;
	
private:
	bool FCalculateDown;
	TcxGridFilterViewInfo* FFilterViewInfo;
	int FFirstRecordIndex;
	TcxNavigatorSiteViewInfo* FNavigatorSiteViewInfo;
	Dxcoreclasses::TdxFastList* FParts;
	int FPixelScrollRecordOffset;
	TcxCustomGridRecordsViewInfo* FRecordsViewInfo;
	HIDESBASE TcxCustomGridTableController* __fastcall GetController(void);
	int __fastcall GetExpandButtonSize(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	Cxnavigator::TcxNavigatorViewInfo* __fastcall GetNavigatorViewInfo(void);
	TcxCustomGridPartViewInfo* __fastcall GetPart(int Index);
	int __fastcall GetPartCount(void);
	int __fastcall GetPartsBottomHeight(void);
	int __fastcall GetPartsCustomHeight(TcxGridPartAlignment AAlignment);
	int __fastcall GetPartsTopHeight(void);
	int __fastcall GetScrollableAreaWidth(void);
	HIDESBASE TcxCustomGridTableViewData* __fastcall GetViewData(void);
	int __fastcall GetVisibleRecordCount(void);
	void __fastcall AddPart(TcxCustomGridPartViewInfo* AItem);
	void __fastcall RemovePart(TcxCustomGridPartViewInfo* AItem);
	
protected:
	virtual System::Types::TRect __fastcall GetNavigatorBounds(void);
	Cxnavigator::TcxCustomNavigatorButtons* __fastcall GetNavigatorButtons(void);
	Vcl::Graphics::TCanvas* __fastcall GetNavigatorCanvas(void);
	Vcl::Controls::TWinControl* __fastcall GetNavigatorControl(void);
	bool __fastcall GetNavigatorFocused(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetNavigatorLookAndFeel(void);
	System::Classes::TComponent* __fastcall GetNavigatorOwner(void);
	bool __fastcall GetNavigatorShowHint(void);
	bool __fastcall GetNavigatorTabStop(void);
	void __fastcall NavigatorStateChanged(void);
	void __fastcall NavigatorChanged(Cxnavigator::TcxNavigatorChangeType AChangeType);
	void __fastcall RefreshNavigator(void);
	Cxnavigator::TcxCustomNavigatorInfoPanel* __fastcall GetNavigatorInfoPanel(void);
	virtual void __fastcall CreateViewInfos(void);
	virtual void __fastcall DestroyViewInfos(bool AIsRecreating);
	virtual void __fastcall AfterCalculating(void);
	virtual void __fastcall AfterOffset(void);
	virtual void __fastcall BeforeCalculating(void);
	virtual void __fastcall BeforeOffset(void);
	virtual void __fastcall Calculate(void);
	virtual System::Types::TRect __fastcall CalculateClientBounds(void);
	virtual int __fastcall GetEqualHeightRecordScrollSize(void);
	virtual void __fastcall CalculateHeight(const System::Types::TPoint &AMaxSize, int &AHeight, bool &AFullyVisible);
	void __fastcall CalculateNavigator(void);
	virtual System::Types::TRect __fastcall CalculatePartBounds(TcxCustomGridPartViewInfo* APart);
	virtual int __fastcall CalculateVisibleEqualHeightRecordCount(void);
	virtual void __fastcall ControlFocusChanged(void);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall DoGetHitTest(const System::Types::TPoint &P);
	virtual int __fastcall GetBottomNonClientHeight(void);
	virtual System::Types::TRect __fastcall GetContentBounds(void);
	virtual int __fastcall GetDefaultGridModeBufferCount(void);
	virtual int __fastcall GetFirstRecordIndex(void);
	virtual void __fastcall GetHScrollBarBounds(System::Types::TRect &ABounds);
	virtual TcxGridFilterViewInfoClass __fastcall GetFilterViewInfoClass(void);
	virtual bool __fastcall GetIsInternalUse(void);
	virtual System::Types::TRect __fastcall GetMultilineEditorBounds(const System::Types::TRect &ACellEditBounds, int ACalculatedHeight, Cxedit::TcxInplaceEditAutoHeight AAutoHeight);
	virtual int __fastcall GetNavigatorOffset(void);
	virtual TcxNavigatorSiteViewInfoClass __fastcall GetNavigatorSiteViewInfoClass(void);
	virtual TcxGridCustomTableNavigatorViewInfoClass __fastcall GetNavigatorViewInfoClass(void);
	virtual System::UnicodeString __fastcall GetNoDataInfoText(void);
	virtual System::Types::TRect __fastcall GetNoDataInfoTextAreaBounds(void);
	virtual void __fastcall GetNoDataInfoTextParams(/* out */ Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetNoDataInfoTextAreaVisible(void);
	virtual int __fastcall GetNonRecordsAreaHeight(bool ACheckScrollBar);
	virtual int __fastcall GetPixelScrollRecordOffset(void);
	virtual TcxCustomGridRecordsViewInfoClass __fastcall GetRecordsViewInfoClass(void) = 0 ;
	virtual System::Types::TRect __fastcall GetScrollableAreaBounds(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsForEdit(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsHorz(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsVert(void);
	bool __fastcall IsFirstRecordIndexAssigned(void);
	bool __fastcall IsPixelScrollRecordOffsetAssigned(void);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall OffsetRecords(int ARecordCountDelta, int APixelScrollRecordOffsetDelta);
	virtual void __fastcall VisibilityChanged(bool AVisible);
	__property TcxCustomGridTableController* Controller = {read=GetController};
	__property int PartCount = {read=GetPartCount, nodefault};
	__property TcxCustomGridPartViewInfo* Parts[int Index] = {read=GetPart};
	__property TcxCustomGridTableViewData* ViewData = {read=GetViewData};
	
public:
	__fastcall virtual TcxCustomGridTableViewInfo(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridTableViewInfo(void);
	virtual bool __fastcall CanOffset(int ARecordCountDelta, int DX, int DY);
	virtual bool __fastcall CanOffsetView(int ARecordCountDelta);
	virtual void __fastcall DoOffset(int ARecordCountDelta, int APixelScrollRecordOffsetDelta, int DX, int DY);
	virtual int __fastcall GetNearestPopupHeight(int AHeight, bool AAdditionalRecord = false);
	virtual int __fastcall GetPopupHeight(int ADropDownRecordCount);
	__property bool CalculateDown = {read=FCalculateDown, write=FCalculateDown, nodefault};
	__property int ExpandButtonSize = {read=GetExpandButtonSize, nodefault};
	__property TcxGridFilterViewInfo* FilterViewInfo = {read=FFilterViewInfo};
	__property int FirstRecordIndex = {read=GetFirstRecordIndex, write=FFirstRecordIndex, nodefault};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property System::Types::TRect NavigatorBounds = {read=GetNavigatorBounds};
	__property int NavigatorOffset = {read=GetNavigatorOffset, nodefault};
	__property TcxNavigatorSiteViewInfo* NavigatorSiteViewInfo = {read=FNavigatorSiteViewInfo};
	__property Cxnavigator::TcxNavigatorViewInfo* NavigatorViewInfo = {read=GetNavigatorViewInfo};
	__property System::UnicodeString NoDataInfoText = {read=GetNoDataInfoText};
	__property System::Types::TRect NoDataInfoTextAreaBounds = {read=GetNoDataInfoTextAreaBounds};
	__property bool NoDataInfoTextAreaVisible = {read=GetNoDataInfoTextAreaVisible, nodefault};
	__property int PartsBottomHeight = {read=GetPartsBottomHeight, nodefault};
	__property int PartsTopHeight = {read=GetPartsTopHeight, nodefault};
	__property int PixelScrollRecordOffset = {read=GetPixelScrollRecordOffset, write=FPixelScrollRecordOffset, nodefault};
	__property TcxCustomGridRecordsViewInfo* RecordsViewInfo = {read=FRecordsViewInfo};
	__property System::Types::TRect ScrollableAreaBounds = {read=GetScrollableAreaBounds};
	__property System::Types::TRect ScrollableAreaBoundsForEdit = {read=GetScrollableAreaBoundsForEdit};
	__property System::Types::TRect ScrollableAreaBoundsHorz = {read=GetScrollableAreaBoundsHorz};
	__property System::Types::TRect ScrollableAreaBoundsVert = {read=GetScrollableAreaBoundsVert};
	__property int ScrollableAreaWidth = {read=GetScrollableAreaWidth, nodefault};
	__property int VisibleRecordCount = {read=GetVisibleRecordCount, nodefault};
private:
	void *__IcxNavigatorOwner2;	/* Cxnavigator::IcxNavigatorOwner2 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5AC3BE65-B332-40D4-9635-869F52634B17}
	operator Cxnavigator::_di_IcxNavigatorOwner2()
	{
		Cxnavigator::_di_IcxNavigatorOwner2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigatorOwner2*(void) { return (Cxnavigator::IcxNavigatorOwner2*)&__IcxNavigatorOwner2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {504B7F43-8847-46C5-B84A-C24F8E5E61A6}
	operator Cxnavigator::_di_IcxNavigatorOwner()
	{
		Cxnavigator::_di_IcxNavigatorOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigatorOwner*(void) { return (Cxnavigator::IcxNavigatorOwner*)&__IcxNavigatorOwner2; }
	#endif
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableViewInfoCacheItem : public Cxgridcustomview::TcxCustomGridViewInfoCacheItem
{
	typedef Cxgridcustomview::TcxCustomGridViewInfoCacheItem inherited;
	
private:
	int FHeight;
	bool FIsHeightAssigned;
	TcxCustomGridRecord* __fastcall GetGridRecord(void);
	void __fastcall SetHeight(int Value);
	
protected:
	__property TcxCustomGridRecord* GridRecord = {read=GetGridRecord};
	
public:
	virtual void __fastcall UnassignValues(bool AKeepMaster);
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property bool IsHeightAssigned = {read=FIsHeightAssigned, write=FIsHeightAssigned, nodefault};
public:
	/* TcxCustomGridViewInfoCacheItem.Create */ inline __fastcall virtual TcxCustomGridTableViewInfoCacheItem(Cxgridcustomview::TcxCustomGridViewInfoCache* AOwner, int AIndex) : Cxgridcustomview::TcxCustomGridViewInfoCacheItem(AOwner, AIndex) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridTableViewInfoCacheItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableViewInfoCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableViewInfoCache : public Cxgridcustomview::TcxCustomGridViewInfoCache
{
	typedef Cxgridcustomview::TcxCustomGridViewInfoCache inherited;
	
private:
	HIDESBASE TcxCustomGridTableViewData* __fastcall GetViewData(void);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheItemClass __fastcall GetItemClass(int Index);
	__property TcxCustomGridTableViewData* ViewData = {read=GetViewData};
public:
	/* TcxCustomGridViewInfoCache.Create */ inline __fastcall virtual TcxCustomGridTableViewInfoCache(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridViewInfoCache(AGridView) { }
	/* TcxCustomGridViewInfoCache.Destroy */ inline __fastcall virtual ~TcxCustomGridTableViewInfoCache(void) { }
	
};

#pragma pack(pop)

enum TcxGridTableItemChange : unsigned char { ticProperty, ticLayout, ticSize };

class DELPHICLASS TcxCustomGridTableItemCustomOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableItemCustomOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomGridTableItem* FItem;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall Changed(TcxGridTableItemChange AChange = (TcxGridTableItemChange)(0x1));
	
public:
	__fastcall virtual TcxCustomGridTableItemCustomOptions(TcxCustomGridTableItem* AItem);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxCustomGridTableItem* Item = {read=FItem};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridTableItemCustomOptions(void) { }
	
};

#pragma pack(pop)

enum TcxGridItemShowEditButtons : unsigned char { isebDefault, isebNever, isebAlways };

enum TcxGridItemSortByDisplayText : unsigned char { isbtDefault, isbtOn, isbtOff };

typedef System::TMetaClass* TcxCustomGridTableItemOptionsClass;

class DELPHICLASS TcxCustomGridTableItemOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableItemOptions : public TcxCustomGridTableItemCustomOptions
{
	typedef TcxCustomGridTableItemCustomOptions inherited;
	
private:
	Cxedit::TcxItemInplaceEditAutoHeight FEditAutoHeight;
	bool FEditing;
	bool FFiltering;
	bool FFilteringAddValueItems;
	bool FFilteringFilteredItemsList;
	bool FFilteringMRUItemsList;
	bool FFilteringPopup;
	bool FFilteringPopupMultiSelect;
	bool FFocusing;
	bool FGrouping;
	bool FIgnoreTimeForFiltering;
	bool FIncSearch;
	bool FMoving;
	bool FShowCaption;
	TcxGridItemShowEditButtons FShowEditButtons;
	TcxGridItemSortByDisplayText FSortByDisplayText;
	bool FSorting;
	void __fastcall SetEditAutoHeight(Cxedit::TcxItemInplaceEditAutoHeight Value);
	void __fastcall SetEditing(bool Value);
	void __fastcall SetFiltering(bool Value);
	void __fastcall SetFilteringAddValueItems(bool Value);
	void __fastcall SetFilteringFilteredItemsList(bool Value);
	void __fastcall SetFilteringMRUItemsList(bool Value);
	void __fastcall SetFilteringPopup(bool Value);
	void __fastcall SetFilteringPopupMultiSelect(bool Value);
	void __fastcall SetFocusing(bool Value);
	void __fastcall SetGrouping(bool Value);
	void __fastcall SetIgnoreTimeForFiltering(bool Value);
	void __fastcall SetIncSearch(bool Value);
	void __fastcall SetMoving(bool Value);
	void __fastcall SetShowCaption(bool Value);
	void __fastcall SetShowEditButtons(TcxGridItemShowEditButtons Value);
	void __fastcall SetSortByDisplayText(TcxGridItemSortByDisplayText Value);
	void __fastcall SetSorting(bool Value);
	
protected:
	virtual void __fastcall BeforeShowCaptionChange(void);
	__property Cxedit::TcxItemInplaceEditAutoHeight EditAutoHeight = {read=FEditAutoHeight, write=SetEditAutoHeight, default=0};
	__property bool Grouping = {read=FGrouping, write=SetGrouping, default=1};
	__property bool Moving = {read=FMoving, write=SetMoving, default=1};
	__property bool ShowCaption = {read=FShowCaption, write=SetShowCaption, default=1};
	__property TcxGridItemSortByDisplayText SortByDisplayText = {read=FSortByDisplayText, write=SetSortByDisplayText, default=0};
	__property bool Sorting = {read=FSorting, write=SetSorting, default=1};
	
public:
	__fastcall virtual TcxCustomGridTableItemOptions(TcxCustomGridTableItem* AItem);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Editing = {read=FEditing, write=SetEditing, default=1};
	__property bool Filtering = {read=FFiltering, write=SetFiltering, default=1};
	__property bool FilteringAddValueItems = {read=FFilteringAddValueItems, write=SetFilteringAddValueItems, default=1};
	__property bool FilteringFilteredItemsList = {read=FFilteringFilteredItemsList, write=SetFilteringFilteredItemsList, default=1};
	__property bool FilteringMRUItemsList = {read=FFilteringMRUItemsList, write=SetFilteringMRUItemsList, default=1};
	__property bool FilteringPopup = {read=FFilteringPopup, write=SetFilteringPopup, default=1};
	__property bool FilteringPopupMultiSelect = {read=FFilteringPopupMultiSelect, write=SetFilteringPopupMultiSelect, default=1};
	__property bool Focusing = {read=FFocusing, write=SetFocusing, default=1};
	__property bool IgnoreTimeForFiltering = {read=FIgnoreTimeForFiltering, write=SetIgnoreTimeForFiltering, default=1};
	__property bool IncSearch = {read=FIncSearch, write=SetIncSearch, default=1};
	__property TcxGridItemShowEditButtons ShowEditButtons = {read=FShowEditButtons, write=SetShowEditButtons, default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridTableItemOptions(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxGridGetCellStyleEvent)(TcxCustomGridTableView* Sender, TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxGridGetRecordStyleEvent)(TcxCustomGridTableView* Sender, TcxCustomGridRecord* ARecord, Cxstyles::TcxStyle* &AStyle);

typedef System::TMetaClass* TcxCustomGridTableItemStylesClass;

class DELPHICLASS TcxCustomGridTableItemStyles;
class PASCALIMPLEMENTATION TcxCustomGridTableItemStyles : public Cxgridcustomview::TcxCustomGridStyles
{
	typedef Cxgridcustomview::TcxCustomGridStyles inherited;
	
private:
	TcxGridGetCellStyleEvent FOnGetContentStyle;
	TcxCustomGridTableView* __fastcall GetGridViewValue(void);
	HIDESBASE TcxCustomGridTableItem* __fastcall GetItem(void);
	void __fastcall SetOnGetContentStyle(TcxGridGetCellStyleEvent Value);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetGridView(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetContentParams(TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxCustomGridTableView* GridView = {read=GetGridViewValue};
	__property TcxCustomGridTableItem* Item = {read=GetItem};
	
__published:
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=0};
	__property TcxGridGetCellStyleEvent OnGetContentStyle = {read=FOnGetContentStyle, write=SetOnGetContentStyle};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxCustomGridTableItemStyles(System::Classes::TPersistent* AOwner) : Cxgridcustomview::TcxCustomGridStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxCustomGridTableItemStyles(void) { }
	
};


typedef Dxcore::TdxSortOrder TcxGridSortOrder;

typedef void __fastcall (__closure *TcxGridTableDataCellCustomDrawEvent)(TcxCustomGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridTableDataCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridGetCellHintEvent)(TcxCustomGridTableItem* Sender, TcxCustomGridRecord* ARecord, TcxGridTableDataCellViewInfo* ACellViewInfo, const System::Types::TPoint &AMousePos, Vcl::Controls::TCaption &AHintText, bool &AIsHintMultiLine, System::Types::TRect &AHintTextRect);

typedef void __fastcall (__closure *TcxGridGetDataTextEvent)(TcxCustomGridTableItem* Sender, int ARecordIndex, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxGridGetDisplayTextEvent)(TcxCustomGridTableItem* Sender, TcxCustomGridRecord* ARecord, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxGridGetFilterDisplayTextEvent)(TcxCustomGridTableItem* Sender, const System::Variant &AValue, System::UnicodeString &ADisplayText);

typedef void __fastcall (__closure *TcxGridGetFilterValuesEvent)(TcxCustomGridTableItem* Sender, Cxcustomdata::TcxDataFilterValueList* AValueList);

typedef void __fastcall (__closure *TcxGridGetPropertiesEvent)(TcxCustomGridTableItem* Sender, TcxCustomGridRecord* ARecord, Cxedit::TcxCustomEditProperties* &AProperties);

typedef void __fastcall (__closure *TcxGridInitDateRangesEvent)(TcxCustomGridTableItem* Sender, TcxGridDateRanges* ADateRanges);

typedef void __fastcall (__closure *TcxGridTableItemGetStoredPropertiesEvent)(TcxCustomGridTableItem* Sender, System::Classes::TStrings* AProperties);

typedef void __fastcall (__closure *TcxGridTableItemGetStoredPropertyValueEvent)(TcxCustomGridTableItem* Sender, const System::UnicodeString AName, System::Variant &AValue);

typedef void __fastcall (__closure *TcxGridTableItemSetStoredPropertyValueEvent)(TcxCustomGridTableItem* Sender, const System::UnicodeString AName, const System::Variant &AValue);

typedef void __fastcall (__closure *TcxGridUserFilteringEvent)(TcxCustomGridTableItem* Sender, const System::Variant &AValue, const System::UnicodeString ADisplayText);

typedef void __fastcall (__closure *TcxGridUserFilteringExEvent)(TcxCustomGridTableItem* Sender, Cxfilter::TcxFilterCriteriaItemList* AFilterList, const System::Variant &AValue, const System::UnicodeString ADisplayText);

typedef void __fastcall (__closure *TcxGridValidateDrawValueEvent)(TcxCustomGridTableItem* Sender, TcxCustomGridRecord* ARecord, const System::Variant &AValue, Cxedit::TcxEditValidateInfo* AData);

typedef System::TMetaClass* TcxCustomGridTableItemClass;

class PASCALIMPLEMENTATION TcxCustomGridTableItem : public Cxclasses::TcxComponent
{
	typedef Cxclasses::TcxComponent inherited;
	
private:
	System::UnicodeString FAlternateCaption;
	int FBestFitMaxWidth;
	System::UnicodeString FCaption;
	Dxcoreclasses::TdxFastList* FCells;
	Cxedit::TcxEditStyle* FCellStyle;
	int FCellStyleUseCounter;
	TcxGridItemDataBinding* FDataBinding;
	TcxGridDateTimeGrouping FDateTimeGrouping;
	Cxedit::TcxCustomEditData* FEditData;
	Cxedit::TcxCustomEditViewData* FEditViewData;
	TcxGridFilteringDateRanges* FFilteringDateRanges;
	TcxCustomGridTableView* FGridView;
	TcxGridGroupingDateRanges* FGroupingDateRanges;
	System::Classes::TAlignment FHeaderAlignmentHorz;
	Cxclasses::TcxAlignmentVert FHeaderAlignmentVert;
	System::UnicodeString FHeaderHint;
	int FID;
	bool FIgnoreLoadingStatus;
	int FIndex;
	bool FIsCaptionAssigned;
	bool FIsHeaderAlignmentHorzAssigned;
	bool FIsHeaderAlignmentVertAssigned;
	bool FIsWidthAssigned;
	Cxedit::TcxCustomEditProperties* FLastEditingProperties;
	Cxedit::TcxEditRepositoryItem* FLastUsedDefaultRepositoryItem;
	int FMinWidth;
	Cxedit::TcxCustomEditProperties* FNonSharedRepositoryProperties;
	TcxCustomGridTableItemOptions* FOptions;
	Cxedit::TcxCustomEditProperties* FProperties;
	Cxedit::TcxCustomEditPropertiesClass FPropertiesClass;
	Cxedit::TcxCustomEditProperties* FPropertiesValue;
	Cxedit::TcxEditRepositoryItem* FRepositoryItem;
	bool FSavedVisible;
	TcxCustomGridTableItemStyles* FStyles;
	bool FVisible;
	bool FVisibleForCustomization;
	int FVisibleIndex;
	bool FWasVisibleBeforeGrouping;
	int FWidth;
	TcxGridTableDataCellCustomDrawEvent FOnCustomDrawCell;
	TcxGridGetCellHintEvent FOnGetCellHint;
	TcxGridGetDataTextEvent FOnGetDataText;
	TcxGridGetDisplayTextEvent FOnGetDisplayText;
	TcxGridGetFilterDisplayTextEvent FOnGetFilterDisplayText;
	TcxGridGetFilterValuesEvent FOnGetFilterValues;
	TcxGridGetPropertiesEvent FOnGetProperties;
	TcxGridGetPropertiesEvent FOnGetPropertiesForEdit;
	TcxGridTableItemGetStoredPropertiesEvent FOnGetStoredProperties;
	TcxGridTableItemGetStoredPropertyValueEvent FOnGetStoredPropertyValue;
	TcxGridInitDateRangesEvent FOnInitFilteringDateRanges;
	TcxGridInitDateRangesEvent FOnInitGroupingDateRanges;
	TcxGridTableItemSetStoredPropertyValueEvent FOnSetStoredPropertyValue;
	TcxGridUserFilteringEvent FOnUserFiltering;
	TcxGridUserFilteringExEvent FOnUserFilteringEx;
	TcxGridValidateDrawValueEvent FOnValidateDrawValue;
	System::Classes::TNotifyEvent FSubClassEvents;
	int __fastcall GetActualMinWidth(void);
	System::UnicodeString __fastcall GetCaption(void);
	TcxGridTableDataCellViewInfo* __fastcall GetCell(int Index);
	int __fastcall GetCellCount(void);
	TcxCustomGridTableController* __fastcall GetController(void);
	Cxcustomdata::TcxCustomDataController* __fastcall GetDataController(void);
	bool __fastcall GetEditing(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetEditingProperties(void);
	System::UnicodeString __fastcall GetFilterCaption(void);
	bool __fastcall GetFiltered(void);
	bool __fastcall GetFocused(void);
	int __fastcall GetGroupIndex(void);
	System::Classes::TAlignment __fastcall GetHeaderAlignmentHorz(void);
	Cxclasses::TcxAlignmentVert __fastcall GetHeaderAlignmentVert(void);
	bool __fastcall GetHidden(void);
	bool __fastcall GetIsLoading(void);
	bool __fastcall GetIncSearching(void);
	HIDESBASE bool __fastcall GetIsDestroying(void);
	bool __fastcall GetIsFirst(void);
	bool __fastcall GetIsLast(void);
	bool __fastcall GetIsReading(void);
	bool __fastcall GetIsUpdating(void);
	int __fastcall GetMinWidth(void);
	System::UnicodeString __fastcall GetPropertiesClassName(void);
	int __fastcall GetSortIndex(void);
	Dxcore::TdxSortOrder __fastcall GetSortOrder(void);
	int __fastcall GetTag(void);
	TcxCustomGridTableViewData* __fastcall GetViewData(void);
	int __fastcall GetWidth(void);
	void __fastcall SetAlternateCaption(const System::UnicodeString Value);
	void __fastcall SetBestFitMaxWidth(int Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetDataBinding(TcxGridItemDataBinding* Value);
	void __fastcall SetDateTimeGrouping(TcxGridDateTimeGrouping Value);
	void __fastcall SetEditing(bool Value);
	void __fastcall SetFiltered(bool Value);
	void __fastcall SetFocused(bool Value);
	void __fastcall SetGroupIndex(int Value);
	void __fastcall SetHeaderAlignmentHorz(System::Classes::TAlignment Value);
	void __fastcall SetHeaderAlignmentVert(Cxclasses::TcxAlignmentVert Value);
	void __fastcall SetHeaderHint(const System::UnicodeString Value);
	void __fastcall SetHidden(bool Value);
	void __fastcall SetIndex(int Value);
	void __fastcall SetMinWidth(int Value);
	void __fastcall SetOnCustomDrawCell(TcxGridTableDataCellCustomDrawEvent Value);
	void __fastcall SetOnGetCellHint(TcxGridGetCellHintEvent Value);
	void __fastcall SetOnGetDataText(TcxGridGetDataTextEvent Value);
	void __fastcall SetOnGetDisplayText(TcxGridGetDisplayTextEvent Value);
	void __fastcall SetOnGetFilterDisplayText(TcxGridGetFilterDisplayTextEvent Value);
	void __fastcall SetOnGetFilterValues(TcxGridGetFilterValuesEvent Value);
	void __fastcall SetOnGetProperties(TcxGridGetPropertiesEvent Value);
	void __fastcall SetOnGetPropertiesForEdit(TcxGridGetPropertiesEvent Value);
	void __fastcall SetOnGetStoredProperties(TcxGridTableItemGetStoredPropertiesEvent Value);
	void __fastcall SetOnGetStoredPropertyValue(TcxGridTableItemGetStoredPropertyValueEvent Value);
	void __fastcall SetOnInitFilteringDateRanges(TcxGridInitDateRangesEvent Value);
	void __fastcall SetOnInitGroupingDateRanges(TcxGridInitDateRangesEvent Value);
	void __fastcall SetOnSetStoredPropertyValue(TcxGridTableItemSetStoredPropertyValueEvent Value);
	void __fastcall SetOnUserFiltering(TcxGridUserFilteringEvent Value);
	void __fastcall SetOnUserFilteringEx(TcxGridUserFilteringExEvent Value);
	void __fastcall SetOnValidateDrawValue(TcxGridValidateDrawValueEvent Value);
	void __fastcall SetOptions(TcxCustomGridTableItemOptions* Value);
	void __fastcall SetProperties(Cxedit::TcxCustomEditProperties* Value);
	void __fastcall SetPropertiesClass(Cxedit::TcxCustomEditPropertiesClass Value);
	void __fastcall SetPropertiesClassName(const System::UnicodeString Value);
	void __fastcall SetRepositoryItem(Cxedit::TcxEditRepositoryItem* Value);
	void __fastcall SetSortIndex(int Value);
	void __fastcall SetSortOrder(Dxcore::TdxSortOrder Value);
	void __fastcall SetStyles(TcxCustomGridTableItemStyles* Value);
	void __fastcall SetTag(int Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetVisibleForCustomization(bool Value);
	void __fastcall SetWidth(int Value);
	void __fastcall ReadHidden(System::Classes::TReader* Reader);
	void __fastcall ReadIsCaptionAssigned(System::Classes::TReader* Reader);
	void __fastcall WriteIsCaptionAssigned(System::Classes::TWriter* Writer);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsSortOrderStored(void);
	bool __fastcall IsTagStored(void);
	bool __fastcall IsWidthStored(void);
	TcxGridItemDataBindingClass __fastcall GetDataBindingClass(void);
	void __fastcall CreateProperties(void);
	void __fastcall DestroyProperties(void);
	void __fastcall RecreateProperties(void);
	void __fastcall CreateNonSharedRepositoryProperties(Cxedit::TcxCustomEditProperties* APattern);
	void __fastcall DestroyNonSharedRepositoryProperties(void);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* AParent);
	void __fastcall ItemRemoved(Cxedit::TcxEditRepositoryItem* Sender);
	void __fastcall RepositoryItemPropertiesChanged(Cxedit::TcxEditRepositoryItem* Sender);
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall CreateDataBinding(void);
	virtual void __fastcall DestroyDataBinding(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual TcxGridFilteringDateRangesClass __fastcall GetFilteringDateRangesClass(void);
	virtual TcxGridGroupingDateRangesClass __fastcall GetGroupingDateRangesClass(void);
	virtual TcxCustomGridTableItemOptionsClass __fastcall GetOptionsClass(void);
	virtual TcxCustomGridTableItemStylesClass __fastcall GetStylesClass(void);
	bool __fastcall IsHeaderAlignmentHorzStored(void);
	bool __fastcall IsHeaderAlignmentVertStored(void);
	virtual void __fastcall BestFitApplied(bool AFireEvents);
	virtual int __fastcall CalculateBestFitWidth(void);
	virtual bool __fastcall CanAutoHeight(void);
	virtual bool __fastcall CanEdit(void);
	virtual bool __fastcall CanEditAutoHeight(void);
	virtual bool __fastcall CanFilter(bool AVisually);
	virtual bool __fastcall CanFilterUsingChecks(void);
	virtual bool __fastcall CanFilterMRUValueItems(void);
	virtual bool __fastcall CanFocus(TcxCustomGridRecord* ARecord);
	virtual bool __fastcall CanGroup(void);
	virtual bool __fastcall CanHide(void);
	virtual bool __fastcall CanHorzSize(void);
	virtual bool __fastcall CanIgnoreTimeForFiltering(void);
	virtual bool __fastcall CanIncSearch(void);
	virtual bool __fastcall CanInitEditing(void);
	virtual bool __fastcall CanMove(void);
	virtual bool __fastcall CanScroll(void);
	virtual bool __fastcall CanSort(void);
	virtual void __fastcall CaptionChanged(void);
	virtual void __fastcall Changed(TcxGridTableItemChange AChange);
	virtual void __fastcall ChangeGroupIndex(int Value);
	void __fastcall ChangeSortIndex(int Value);
	void __fastcall CheckWidthValue(int &Value);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DateTimeGroupingChanged(void);
	virtual void __fastcall DoSetVisible(bool Value);
	virtual void __fastcall ForceWidth(int Value);
	virtual bool __fastcall GetActuallyVisible(void);
	virtual void __fastcall GetBestFitRecordRange(/* out */ int &AFirstIndex, /* out */ int &ALastIndex);
	virtual int __fastcall GetBestFitWidth(void);
	virtual TcxGridDateTimeFilters __fastcall GetDateTimeFilters(void);
	TcxGridDateTimeGrouping __fastcall GetDateTimeGrouping(void);
	virtual bool __fastcall GetEditable(void);
	virtual Cxedit::TcxInplaceEditAutoHeight __fastcall GetEditAutoHeight(void);
	virtual bool __fastcall GetEditPartVisible(void);
	virtual System::Variant __fastcall GetEditValue(void);
	virtual bool __fastcall GetFilterable(void);
	virtual void __fastcall GetFilterDisplayText(const System::Variant &AValue, System::UnicodeString &ADisplayText);
	virtual bool __fastcall GetFixed(void);
	virtual TcxGridTableDataCellViewInfo* __fastcall GetFocusedCellViewInfo(void);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetPropertiesForEdit(void);
	Cxedit::TcxCustomEditProperties* __fastcall GetPropertiesValue(void);
	virtual bool __fastcall GetVisible(void);
	virtual System::UnicodeString __fastcall GetVisibleCaption(void);
	virtual bool __fastcall GetVisibleForCustomization(void);
	int __fastcall GetVisibleIndex(void);
	virtual bool __fastcall GetVisibleInQuickCustomizationPopup(void);
	virtual void __fastcall GroupingChanging(void);
	bool __fastcall HasCustomDrawCell(void);
	virtual bool __fastcall HasFixedWidth(void);
	virtual void __fastcall InitFilteringDateRanges(void);
	virtual void __fastcall InitGroupingDateRanges(void);
	virtual void __fastcall InitProperties(Cxedit::TcxCustomEditProperties* AProperties);
	bool __fastcall IsSortingByDisplayText(bool ASortByDisplayText);
	virtual bool __fastcall IsVisibleStored(void);
	virtual bool __fastcall IsVisibleForCustomizationStored(void);
	void __fastcall PropertiesChanged(void);
	void __fastcall PropertiesChangedHandler(System::TObject* Sender);
	void __fastcall PropertiesValueChanged(void);
	void __fastcall RecalculateDefaultWidth(void);
	virtual void __fastcall SetEditValue(const System::Variant &Value);
	virtual void __fastcall SetGridView(TcxCustomGridTableView* Value);
	virtual bool __fastcall ShowButtons(bool AFocused);
	virtual bool __fastcall ShowOnUngrouping(void);
	virtual bool __fastcall SupportsDateTimeFilters(bool ARelativeFilters);
	virtual bool __fastcall SupportsGroupingDateRanges(bool ACheckCustomHandlers);
	virtual bool __fastcall UseFilteredValuesForFilterValueList(void);
	bool __fastcall UseOwnProperties(void);
	virtual bool __fastcall UseValueItemsForFilterValueList(void);
	void __fastcall ValidateEditData(Cxedit::TcxCustomEditProperties* AEditProperties);
	virtual void __fastcall ValueTypeClassChanged(void);
	virtual void __fastcall VisibleChanged(void);
	virtual void __fastcall VisibleForCustomizationChanged(void);
	virtual System::UnicodeString __fastcall DefaultAlternateCaption(void);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	System::Classes::TAlignment __fastcall DefaultHeaderAlignmentHorz(void);
	Cxclasses::TcxAlignmentVert __fastcall DefaultHeaderAlignmentVert(void);
	Cxedit::TcxEditRepositoryItem* __fastcall DefaultRepositoryItem(void);
	virtual int __fastcall DefaultWidth(void);
	Cxedit::TcxEditStyle* __fastcall GetCellStyle(void);
	virtual void __fastcall InitStyle(Cxedit::TcxCustomEditStyle* AStyle, const Cxgraphics::TcxViewParams &AParams, bool AFocused);
	void __fastcall ReleaseCellStyle(void);
	void __fastcall AddCell(TcxGridTableDataCellViewInfo* ACell);
	void __fastcall RemoveCell(TcxGridTableDataCellViewInfo* ACell);
	__property int CellCount = {read=GetCellCount, nodefault};
	__property TcxGridTableDataCellViewInfo* Cells[int Index] = {read=GetCell};
	Cxedit::TcxCustomEditViewData* __fastcall CreateEditViewData(Cxedit::TcxCustomEditProperties* AProperties);
	void __fastcall DestroyEditViewData(Cxedit::TcxCustomEditViewData* &AEditViewData);
	void __fastcall DoCreateEditViewData(void);
	void __fastcall DoDestroyEditViewData(void);
	void __fastcall EditViewDataGetDisplayTextHandler(Cxedit::TcxCustomEditViewData* Sender, System::UnicodeString &AText);
	Cxedit::TcxCustomEditViewData* __fastcall GetEditViewData(Cxedit::TcxCustomEditProperties* AProperties, /* out */ bool &AIsLocalCopy);
	void __fastcall ReleaseEditViewData(Cxedit::TcxCustomEditViewData* &AEditViewData, bool AIsLocalCopy);
	__property Cxedit::TcxCustomEditViewData* EditViewData = {read=FEditViewData};
	void __fastcall CheckVisible(void);
	void __fastcall SaveVisible(void);
	__property bool SavedVisible = {read=FSavedVisible, nodefault};
	virtual void __fastcall DoCustomDrawCell(Cxgraphics::TcxCanvas* ACanvas, TcxGridTableDataCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoGetCellHint(TcxCustomGridRecord* ARecord, TcxGridTableDataCellViewInfo* ACellViewInfo, const System::Types::TPoint &AMousePos, Vcl::Controls::TCaption &AHintText, bool &AIsHintMultiLine, System::Types::TRect &AHintTextRect);
	virtual void __fastcall DoGetDataText(int ARecordIndex, System::UnicodeString &AText);
	virtual void __fastcall DoGetDisplayText(TcxCustomGridRecord* ARecord, System::UnicodeString &AText);
	virtual void __fastcall DoGetFilterValues(Cxcustomdata::TcxDataFilterValueList* AValueList);
	virtual Cxedit::TcxCustomEditProperties* __fastcall DoGetProperties(TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoGetPropertiesForEdit(TcxCustomGridRecord* ARecord, Cxedit::TcxCustomEditProperties* &AProperties);
	virtual void __fastcall DoInitFilteringDateRanges(void);
	virtual void __fastcall DoInitGroupingDateRanges(void);
	virtual void __fastcall DoUserFiltering(const System::Variant &AValue, const System::UnicodeString ADisplayText);
	virtual void __fastcall DoUserFilteringEx(Cxfilter::TcxFilterCriteriaItemList* AFilterList, const System::Variant &AValue, const System::UnicodeString ADisplayText);
	virtual void __fastcall DoValidateDrawValue(TcxCustomGridRecord* ARecord, const System::Variant &AValue, Cxedit::TcxEditValidateInfo* AData);
	bool __fastcall HasCellHintHandler(void);
	bool __fastcall HasCustomPropertiesForEditHandler(void);
	bool __fastcall HasCustomPropertiesHandler(void);
	bool __fastcall HasDataTextHandler(void);
	bool __fastcall HasInitFilteringDateRangesHandler(void);
	bool __fastcall HasInitFilteringDateRangesHandlers(void);
	bool __fastcall HasInitGroupingDateRangesHandler(void);
	bool __fastcall HasInitGroupingDateRangesHandlers(void);
	bool __fastcall HasValidateDrawValueHandler(void);
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property bool IsLoading = {read=GetIsLoading, nodefault};
	__property bool IsReading = {read=GetIsReading, nodefault};
	__property bool IsUpdating = {read=GetIsUpdating, nodefault};
	__property int ActualMinWidth = {read=GetActualMinWidth, nodefault};
	__property TcxCustomGridTableController* Controller = {read=GetController};
	__property Cxcustomdata::TcxCustomDataController* DataController = {read=GetDataController};
	__property TcxGridDateTimeGrouping DateTimeGrouping = {read=FDateTimeGrouping, write=SetDateTimeGrouping, default=0};
	__property Cxedit::TcxCustomEditProperties* EditingProperties = {read=GetEditingProperties};
	__property bool EditPartVisible = {read=GetEditPartVisible, nodefault};
	__property bool Filterable = {read=GetFilterable, nodefault};
	__property System::UnicodeString FilterCaption = {read=GetFilterCaption};
	__property bool Fixed = {read=GetFixed, nodefault};
	__property int GroupIndex = {read=GetGroupIndex, write=SetGroupIndex, default=-1};
	__property TcxGridGroupingDateRanges* GroupingDateRanges = {read=FGroupingDateRanges};
	__property System::Classes::TAlignment HeaderAlignmentHorz = {read=GetHeaderAlignmentHorz, write=SetHeaderAlignmentHorz, stored=IsHeaderAlignmentHorzStored, nodefault};
	__property Cxclasses::TcxAlignmentVert HeaderAlignmentVert = {read=GetHeaderAlignmentVert, write=SetHeaderAlignmentVert, stored=IsHeaderAlignmentVertStored, nodefault};
	__property System::UnicodeString HeaderHint = {read=FHeaderHint, write=SetHeaderHint};
	__property bool Hidden = {read=GetHidden, write=SetHidden, nodefault};
	__property bool IgnoreLoadingStatus = {read=FIgnoreLoadingStatus, write=FIgnoreLoadingStatus, nodefault};
	__property bool InternalVisible = {read=FVisible, nodefault};
	__property int MinWidth = {read=GetMinWidth, write=SetMinWidth, default=20};
	__property TcxCustomGridTableViewData* ViewData = {read=GetViewData};
	__property bool VisibleForCustomization = {read=GetVisibleForCustomization, write=SetVisibleForCustomization, stored=IsVisibleForCustomizationStored, nodefault};
	__property bool VisibleInQuickCustomizationPopup = {read=GetVisibleInQuickCustomizationPopup, nodefault};
	__property bool WasVisibleBeforeGrouping = {read=FWasVisibleBeforeGrouping, nodefault};
	__property int Width = {read=GetWidth, write=SetWidth, stored=IsWidthStored, nodefault};
	__property TcxGridInitDateRangesEvent OnInitGroupingDateRanges = {read=FOnInitGroupingDateRanges, write=SetOnInitGroupingDateRanges};
	
public:
	__fastcall virtual TcxCustomGridTableItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomGridTableItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	virtual void __fastcall ApplyBestFit(bool ACheckSizingAbility = false, bool AFireEvents = false);
	virtual int __fastcall CalculateDefaultCellHeight(Cxgraphics::TcxCanvas* ACanvas, Vcl::Graphics::TFont* AFont);
	virtual Cxedit::TcxEditStyle* __fastcall CreateEditStyle(void);
	virtual void __fastcall FocusWithSelection(void);
	System::UnicodeString __fastcall GetAlternateCaption(void);
	Cxedit::_di_IcxEditDefaultValuesProvider __fastcall GetDefaultValuesProvider(Cxedit::TcxCustomEditProperties* AProperties = (Cxedit::TcxCustomEditProperties*)(0x0));
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(void)/* overload */;
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(TcxCustomGridRecord* ARecord)/* overload */;
	Cxedit::TcxCustomEditProperties* __fastcall GetProperties(int ARecordIndex)/* overload */;
	Cxedit::TcxEditRepositoryItem* __fastcall GetRepositoryItem(void);
	void __fastcall MakeVisible(void);
	virtual void __fastcall RestoreDefaults(void);
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property int BestFitMaxWidth = {read=FBestFitMaxWidth, write=SetBestFitMaxWidth, default=0};
	__property bool Editable = {read=GetEditable, nodefault};
	__property bool Editing = {read=GetEditing, write=SetEditing, nodefault};
	__property System::Variant EditValue = {read=GetEditValue, write=SetEditValue};
	__property bool Filtered = {read=GetFiltered, write=SetFiltered, nodefault};
	__property TcxGridFilteringDateRanges* FilteringDateRanges = {read=FFilteringDateRanges};
	__property bool Focused = {read=GetFocused, write=SetFocused, nodefault};
	__property TcxGridTableDataCellViewInfo* FocusedCellViewInfo = {read=GetFocusedCellViewInfo};
	__property TcxCustomGridTableView* GridView = {read=FGridView};
	__property bool Hideable = {read=CanHide, nodefault};
	__property int ID = {read=FID, nodefault};
	__property bool IncSearching = {read=GetIncSearching, nodefault};
	__property int Index = {read=FIndex, write=SetIndex, nodefault};
	__property bool IsFirst = {read=GetIsFirst, nodefault};
	__property bool IsLast = {read=GetIsLast, nodefault};
	__property TcxCustomGridTableItemOptions* Options = {read=FOptions, write=SetOptions};
	__property Cxedit::TcxCustomEditPropertiesClass PropertiesClass = {read=FPropertiesClass, write=SetPropertiesClass};
	__property int SortIndex = {read=GetSortIndex, write=SetSortIndex, default=-1};
	__property Dxcore::TdxSortOrder SortOrder = {read=GetSortOrder, write=SetSortOrder, stored=IsSortOrderStored, nodefault};
	__property TcxCustomGridTableItemStyles* Styles = {read=FStyles, write=SetStyles};
	__property System::UnicodeString VisibleCaption = {read=GetVisibleCaption};
	__property int VisibleIndex = {read=FVisibleIndex, nodefault};
	
__published:
	__property System::UnicodeString AlternateCaption = {read=FAlternateCaption, write=SetAlternateCaption};
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property TcxGridItemDataBinding* DataBinding = {read=FDataBinding, write=SetDataBinding};
	__property System::UnicodeString PropertiesClassName = {read=GetPropertiesClassName, write=SetPropertiesClassName};
	__property Cxedit::TcxCustomEditProperties* Properties = {read=FProperties, write=SetProperties};
	__property Cxedit::TcxEditRepositoryItem* RepositoryItem = {read=FRepositoryItem, write=SetRepositoryItem};
	__property bool Visible = {read=GetVisible, write=SetVisible, stored=IsVisibleStored, default=1};
	__property System::Classes::TNotifyEvent PropertiesEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property System::Classes::TNotifyEvent StylesEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property int Tag = {read=GetTag, write=SetTag, stored=IsTagStored, nodefault};
	__property TcxGridTableDataCellCustomDrawEvent OnCustomDrawCell = {read=FOnCustomDrawCell, write=SetOnCustomDrawCell};
	__property TcxGridGetCellHintEvent OnGetCellHint = {read=FOnGetCellHint, write=SetOnGetCellHint};
	__property TcxGridGetDataTextEvent OnGetDataText = {read=FOnGetDataText, write=SetOnGetDataText};
	__property TcxGridGetDisplayTextEvent OnGetDisplayText = {read=FOnGetDisplayText, write=SetOnGetDisplayText};
	__property TcxGridGetFilterDisplayTextEvent OnGetFilterDisplayText = {read=FOnGetFilterDisplayText, write=SetOnGetFilterDisplayText};
	__property TcxGridGetFilterValuesEvent OnGetFilterValues = {read=FOnGetFilterValues, write=SetOnGetFilterValues};
	__property TcxGridGetPropertiesEvent OnGetProperties = {read=FOnGetProperties, write=SetOnGetProperties};
	__property TcxGridGetPropertiesEvent OnGetPropertiesForEdit = {read=FOnGetPropertiesForEdit, write=SetOnGetPropertiesForEdit};
	__property TcxGridTableItemGetStoredPropertiesEvent OnGetStoredProperties = {read=FOnGetStoredProperties, write=SetOnGetStoredProperties};
	__property TcxGridTableItemGetStoredPropertyValueEvent OnGetStoredPropertyValue = {read=FOnGetStoredPropertyValue, write=SetOnGetStoredPropertyValue};
	__property TcxGridInitDateRangesEvent OnInitFilteringDateRanges = {read=FOnInitFilteringDateRanges, write=SetOnInitFilteringDateRanges};
	__property TcxGridTableItemSetStoredPropertyValueEvent OnSetStoredPropertyValue = {read=FOnSetStoredPropertyValue, write=SetOnSetStoredPropertyValue};
	__property TcxGridUserFilteringEvent OnUserFiltering = {read=FOnUserFiltering, write=SetOnUserFiltering};
	__property TcxGridUserFilteringExEvent OnUserFilteringEx = {read=FOnUserFilteringEx, write=SetOnUserFilteringEx};
	__property TcxGridValidateDrawValueEvent OnValidateDrawValue = {read=FOnValidateDrawValue, write=SetOnValidateDrawValue};
private:
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IcxEditRepositoryItemListener;	/* Cxedit::IcxEditRepositoryItemListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator Cxedit::_di_IcxEditRepositoryItemListener()
	{
		Cxedit::_di_IcxEditRepositoryItemListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditRepositoryItemListener*(void) { return (Cxedit::IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
	#endif
	
};


class DELPHICLASS TcxCustomGridTableBackgroundBitmaps;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableBackgroundBitmaps : public Cxgridcustomview::TcxCustomGridBackgroundBitmaps
{
	typedef Cxgridcustomview::TcxCustomGridBackgroundBitmaps inherited;
	
protected:
	virtual int __fastcall GetBitmapStyleIndex(int Index);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Vcl::Graphics::TBitmap* Content = {read=GetValue, write=SetValue, index=1};
	__property Vcl::Graphics::TBitmap* FilterBox = {read=GetValue, write=SetValue, index=2};
public:
	/* TcxCustomGridBackgroundBitmaps.Create */ inline __fastcall virtual TcxCustomGridTableBackgroundBitmaps(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomview::TcxCustomGridBackgroundBitmaps(AGridView) { }
	/* TcxCustomGridBackgroundBitmaps.Destroy */ inline __fastcall virtual ~TcxCustomGridTableBackgroundBitmaps(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridTableDateTimeHandlingClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableDateTimeHandling : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	System::UnicodeString FDateFormat;
	TcxGridDateTimeFilters FFilters;
	TcxGridDateTimeGrouping FGrouping;
	System::UnicodeString FHourFormat;
	bool FIgnoreTimeForFiltering;
	System::UnicodeString FMonthFormat;
	bool FUseLongDateFormat;
	bool FUseShortTimeFormat;
	System::UnicodeString FYearFormat;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	void __fastcall SetDateFormat(const System::UnicodeString Value);
	void __fastcall SetFilters(TcxGridDateTimeFilters Value);
	void __fastcall SetGrouping(TcxGridDateTimeGrouping Value);
	void __fastcall SetHourFormat(const System::UnicodeString Value);
	void __fastcall SetIgnoreTimeForFiltering(bool Value);
	void __fastcall SetMonthFormat(const System::UnicodeString Value);
	void __fastcall SetUseLongDateFormat(bool Value);
	void __fastcall SetUseShortTimeFormat(bool Value);
	void __fastcall SetYearFormat(const System::UnicodeString Value);
	
protected:
	__property System::UnicodeString DateFormat = {read=FDateFormat, write=SetDateFormat};
	__property TcxGridDateTimeGrouping Grouping = {read=FGrouping, write=SetGrouping, default=1};
	__property System::UnicodeString HourFormat = {read=FHourFormat, write=SetHourFormat};
	__property bool UseLongDateFormat = {read=FUseLongDateFormat, write=SetUseLongDateFormat, default=1};
	__property bool UseShortTimeFormat = {read=FUseShortTimeFormat, write=SetUseShortTimeFormat, default=1};
	
public:
	__fastcall virtual TcxCustomGridTableDateTimeHandling(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::UnicodeString __fastcall GetDateFormat(void);
	System::UnicodeString __fastcall GetHourFormat(void);
	System::UnicodeString __fastcall GetMonthFormat(void);
	System::UnicodeString __fastcall GetYearFormat(void);
	void __fastcall GroupingChanged(void);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	
__published:
	__property TcxGridDateTimeFilters Filters = {read=FFilters, write=SetFilters, default=0};
	__property bool IgnoreTimeForFiltering = {read=FIgnoreTimeForFiltering, write=SetIgnoreTimeForFiltering, default=0};
	__property System::UnicodeString MonthFormat = {read=FMonthFormat, write=SetMonthFormat};
	__property System::UnicodeString YearFormat = {read=FYearFormat, write=SetYearFormat};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridTableDateTimeHandling(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridFilterMRUItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterMRUItem : public Cxclasses::TcxMRUItem
{
	typedef Cxclasses::TcxMRUItem inherited;
	
private:
	System::UnicodeString __fastcall GetCaption(void);
	
protected:
	bool __fastcall StreamEquals(System::Classes::TMemoryStream* AStream);
	
public:
	Cxcustomdata::TcxDataFilterCriteria* Filter;
	__fastcall TcxGridFilterMRUItem(Cxcustomdata::TcxDataFilterCriteria* AFilter);
	__fastcall virtual ~TcxGridFilterMRUItem(void);
	void __fastcall AssignTo(Cxcustomdata::TcxDataFilterCriteria* AFilter);
	virtual bool __fastcall Equals(Cxclasses::TcxMRUItem* AItem);
	bool __fastcall FilterEquals(Cxcustomdata::TcxDataFilterCriteria* AFilter);
	System::Classes::TMemoryStream* __fastcall GetStream(void);
	__property System::UnicodeString Caption = {read=GetCaption};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridFilterMRUItemsClass;

class DELPHICLASS TcxGridFilterMRUItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterMRUItems : public Cxclasses::TcxMRUItems
{
	typedef Cxclasses::TcxMRUItems inherited;
	
public:
	TcxGridFilterMRUItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomGridTableFiltering* FFiltering;
	int FLockCount;
	Dxcoreclasses::TdxFastList* FVisibleItems;
	bool __fastcall GetIsLocked(void);
	HIDESBASE TcxGridFilterMRUItem* __fastcall GetItem(int Index);
	int __fastcall GetVisibleCount(void);
	TcxGridFilterMRUItem* __fastcall GetVisibleItem(int Index);
	
protected:
	void __fastcall DeleteEmptyItems(void);
	void __fastcall FilterChanged(void);
	void __fastcall RefreshVisibleItemsList(void);
	HIDESBASE void __fastcall SetMaxCount(int AMaxCount);
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	
public:
	__fastcall virtual TcxGridFilterMRUItems(TcxCustomGridTableFiltering* AFiltering);
	__fastcall virtual ~TcxGridFilterMRUItems(void);
	HIDESBASE void __fastcall Add(Cxcustomdata::TcxDataFilterCriteria* AFilter);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	__property TcxCustomGridTableFiltering* Filtering = {read=FFiltering};
	__property TcxGridFilterMRUItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	__property TcxGridFilterMRUItem* VisibleItems[int Index] = {read=GetVisibleItem};
};

#pragma pack(pop)

enum TcxGridFilterPosition : unsigned char { fpTop, fpBottom };

enum TcxGridFilterVisible : unsigned char { fvNever, fvNonEmpty, fvAlways };

typedef System::TMetaClass* TcxGridFilterBoxClass;

class DELPHICLASS TcxGridFilterBox;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridFilterBox : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	TcxGridFilterButtonAlignment FCustomizeButtonAlignment;
	bool FCustomizeDialog;
	int FMRUItemsListDropDownCount;
	TcxGridFilterPosition FPosition;
	TcxGridFilterVisible FVisible;
	void __fastcall SetButtonPosition(const TcxGridFilterButtonAlignment Value);
	void __fastcall SetCustomizeDialog(bool Value);
	void __fastcall SetMRUItemsListDropDownCount(int Value);
	void __fastcall SetPosition(TcxGridFilterPosition Value);
	void __fastcall SetVisible(TcxGridFilterVisible Value);
	
public:
	__fastcall virtual TcxGridFilterBox(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxGridFilterButtonAlignment CustomizeButtonAlignment = {read=FCustomizeButtonAlignment, write=SetButtonPosition, default=1};
	__property bool CustomizeDialog = {read=FCustomizeDialog, write=SetCustomizeDialog, default=1};
	__property int MRUItemsListDropDownCount = {read=FMRUItemsListDropDownCount, write=SetMRUItemsListDropDownCount, default=0};
	__property TcxGridFilterPosition Position = {read=FPosition, write=SetPosition, default=1};
	__property TcxGridFilterVisible Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridFilterBox(void) { }
	
};

#pragma pack(pop)

enum TcxGridItemFilterPopupApplyChangesMode : unsigned char { fpacImmediately, fpacOnButtonClick };

typedef System::TMetaClass* TcxGridItemFilterPopupOptionsClass;

class DELPHICLASS TcxGridItemFilterPopupOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridItemFilterPopupOptions : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	TcxGridItemFilterPopupApplyChangesMode FApplyMultiSelectChanges;
	int FDropDownWidth;
	int FMaxDropDownItemCount;
	bool FMultiSelect;
	void __fastcall SetApplyMultiSelectChanges(TcxGridItemFilterPopupApplyChangesMode Value);
	void __fastcall SetDropDownWidth(int Value);
	void __fastcall SetMaxDropDownItemCount(int Value);
	void __fastcall SetMultiSelect(bool Value);
	
public:
	__fastcall virtual TcxGridItemFilterPopupOptions(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxGridItemFilterPopupApplyChangesMode ApplyMultiSelectChanges = {read=FApplyMultiSelectChanges, write=SetApplyMultiSelectChanges, default=0};
	__property int DropDownWidth = {read=FDropDownWidth, write=SetDropDownWidth, default=0};
	__property int MaxDropDownItemCount = {read=FMaxDropDownItemCount, write=SetMaxDropDownItemCount, default=15};
	__property bool MultiSelect = {read=FMultiSelect, write=SetMultiSelect, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridItemFilterPopupOptions(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxCustomGridTableFilteringClass;

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableFiltering : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	bool FItemAddValueItems;
	bool FItemFilteredItemsList;
	bool FItemMRUItemsList;
	int FItemMRUItemsListCount;
	TcxGridItemFilterPopupOptions* FItemPopup;
	TcxGridFilterMRUItems* FMRUItems;
	bool FMRUItemsList;
	int FMRUItemsListCount;
	bool FSynchronizeWithControlDialog;
	bool __fastcall GetCustomizeDialog(void);
	TcxCustomGridTableView* __fastcall GetGridView(void);
	int __fastcall GetMRUItemsListDropDownCount(void);
	TcxGridFilterPosition __fastcall GetPosition(void);
	TcxGridFilterVisible __fastcall GetVisible(void);
	void __fastcall SetCustomizeDialog(bool Value);
	void __fastcall SetItemAddValueItems(bool Value);
	void __fastcall SetItemFilteredItemsList(bool Value);
	void __fastcall SetItemMRUItemsList(bool Value);
	void __fastcall SetItemMRUItemsListCount(int Value);
	void __fastcall SetItemPopup(TcxGridItemFilterPopupOptions* Value);
	void __fastcall SetMRUItemsList(bool Value);
	void __fastcall SetMRUItemsListCount(int Value);
	void __fastcall SetMRUItemsListDropDownCount(int Value);
	void __fastcall SetPosition(TcxGridFilterPosition Value);
	void __fastcall SetVisible(TcxGridFilterVisible Value);
	void __fastcall AfterFilterControlDialogApply(System::TObject* Sender);
	void __fastcall BeforeFilterControlDialogApply(System::TObject* Sender);
	void __fastcall FilterControlDialogApply(System::TObject* Sender);
	void __fastcall ReadCustomizeDialog(System::Classes::TReader* Reader);
	void __fastcall ReadMRUItemsListDropDownCount(System::Classes::TReader* Reader);
	void __fastcall ReadPosition(System::Classes::TReader* Reader);
	void __fastcall ReadVisible(System::Classes::TReader* Reader);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall FilterChanged(void);
	virtual TcxGridItemFilterPopupOptionsClass __fastcall GetItemPopupClass(void);
	virtual TcxGridFilterMRUItemsClass __fastcall GetMRUItemsClass(void);
	virtual bool __fastcall IsMRUItemsListAvailable(void);
	virtual void __fastcall MRUItemsVisibleCountChanged(int AOldCount, int ANewCount);
	__property bool ItemAddValueItems = {read=FItemAddValueItems, write=SetItemAddValueItems, default=1};
	__property bool ItemFilteredItemsList = {read=FItemFilteredItemsList, write=SetItemFilteredItemsList, default=0};
	__property bool ItemMRUItemsList = {read=FItemMRUItemsList, write=SetItemMRUItemsList, default=1};
	__property int ItemMRUItemsListCount = {read=FItemMRUItemsListCount, write=SetItemMRUItemsListCount, default=5};
	__property TcxGridItemFilterPopupOptions* ItemPopup = {read=FItemPopup, write=SetItemPopup};
	int __fastcall GetItemPopupDropDownWidth(void);
	int __fastcall GetItemPopupMaxDropDownItemCount(void);
	void __fastcall SetItemPopupDropDownWidth(int Value);
	void __fastcall SetItemPopupMaxDropDownItemCount(int Value);
	void __fastcall ReadItemPopupDropDownWidth(System::Classes::TReader* Reader);
	void __fastcall ReadItemPopupMaxDropDownCount(System::Classes::TReader* Reader);
	__property int DropDownWidth = {read=GetItemPopupDropDownWidth, write=SetItemPopupDropDownWidth, nodefault};
	__property int MaxDropDownCount = {read=GetItemPopupMaxDropDownItemCount, write=SetItemPopupMaxDropDownItemCount, nodefault};
	
public:
	__fastcall virtual TcxCustomGridTableFiltering(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxCustomGridTableFiltering(void);
	void __fastcall AddFilterToMRUItems(Cxcustomdata::TcxDataFilterCriteria* AFilter = (Cxcustomdata::TcxDataFilterCriteria*)(0x0));
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall RunCustomizeDialog(TcxCustomGridTableItem* AItem = (TcxCustomGridTableItem*)(0x0));
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	__property TcxGridFilterMRUItems* MRUItems = {read=FMRUItems};
	__property bool CustomizeDialog = {read=GetCustomizeDialog, write=SetCustomizeDialog, nodefault};
	__property int MRUItemsListDropDownCount = {read=GetMRUItemsListDropDownCount, write=SetMRUItemsListDropDownCount, nodefault};
	__property TcxGridFilterPosition Position = {read=GetPosition, write=SetPosition, nodefault};
	__property TcxGridFilterVisible Visible = {read=GetVisible, write=SetVisible, nodefault};
	
__published:
	__property bool MRUItemsList = {read=FMRUItemsList, write=SetMRUItemsList, default=1};
	__property int MRUItemsListCount = {read=FMRUItemsListCount, write=SetMRUItemsListCount, default=10};
};

#pragma pack(pop)

class DELPHICLASS TcxGridViewNavigatorButtons;
class PASCALIMPLEMENTATION TcxGridViewNavigatorButtons : public Cxnavigator::TcxNavigatorControlButtons
{
	typedef Cxnavigator::TcxNavigatorControlButtons inherited;
	
private:
	TcxCustomGridTableView* FGridView;
	
public:
	__fastcall virtual TcxGridViewNavigatorButtons(TcxCustomGridTableView* AGridView);
	__property TcxCustomGridTableView* GridView = {read=FGridView};
	
__published:
	__property ConfirmDelete = {default=0};
public:
	/* TcxCustomNavigatorButtons.Destroy */ inline __fastcall virtual ~TcxGridViewNavigatorButtons(void) { }
	
};


class DELPHICLASS TcxGridViewNavigatorInfoPanel;
class PASCALIMPLEMENTATION TcxGridViewNavigatorInfoPanel : public Cxnavigator::TcxCustomNavigatorInfoPanel
{
	typedef Cxnavigator::TcxCustomNavigatorInfoPanel inherited;
	
private:
	TcxCustomGridTableView* FGridView;
	
public:
	__fastcall virtual TcxGridViewNavigatorInfoPanel(TcxCustomGridTableView* AGridView);
	virtual Cxgraphics::TcxViewParams __fastcall GetViewParams(void);
	__property TcxCustomGridTableView* GridView = {read=FGridView};
	
__published:
	__property DisplayMask = {default=0};
	__property Visible = {default=0};
	__property Width = {default=0};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridViewNavigatorInfoPanel(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridViewNavigator : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	TcxGridViewNavigatorButtons* FButtons;
	TcxGridViewNavigatorInfoPanel* FInfoPanel;
	bool FVisible;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	Cxnavigator::_di_IcxNavigatorRecordPosition __fastcall GetIRecordPosition(void);
	void __fastcall SetButtons(TcxGridViewNavigatorButtons* Value);
	void __fastcall SetInfoPanel(TcxGridViewNavigatorInfoPanel* Value);
	void __fastcall SetVisible(bool Value);
	
public:
	__fastcall virtual TcxGridViewNavigator(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxGridViewNavigator(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	
__published:
	__property TcxGridViewNavigatorButtons* Buttons = {read=FButtons, write=SetButtons};
	__property TcxGridViewNavigatorInfoPanel* InfoPanel = {read=FInfoPanel, write=SetInfoPanel};
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxGridViewNavigatorClass;

class DELPHICLASS TcxCustomGridTableShowLockedStateImageOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableShowLockedStateImageOptions : public Cxgridcustomview::TcxCustomGridShowLockedStateImageOptions
{
	typedef Cxgridcustomview::TcxCustomGridShowLockedStateImageOptions inherited;
	
private:
	Cxcontrols::TcxLockedStateImageShowingMode FBestFit;
	Cxcontrols::TcxLockedStateImageShowingMode FFiltering;
	Cxcontrols::TcxLockedStateImageShowingMode FGrouping;
	Cxcontrols::TcxLockedStateImageShowingMode FSorting;
	
protected:
	__property Cxgridcustomview::TcxGridShowLockedStateImageMode BestFit = {read=FBestFit, write=FBestFit, default=1};
	__property Cxgridcustomview::TcxGridShowLockedStateImageMode Filtering = {read=FFiltering, write=FFiltering, default=1};
	__property Cxgridcustomview::TcxGridShowLockedStateImageMode Grouping = {read=FGrouping, write=FGrouping, default=1};
	__property Cxgridcustomview::TcxGridShowLockedStateImageMode Sorting = {read=FSorting, write=FSorting, default=1};
	
public:
	__fastcall virtual TcxCustomGridTableShowLockedStateImageOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomGridTableShowLockedStateImageOptions(void) { }
	
};

#pragma pack(pop)

enum TcxGridDragFocusing : unsigned char { dfNone, dfDragOver, dfDragDrop };

class DELPHICLASS TcxCustomGridTableOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableOptionsBehavior : public Cxgridcustomview::TcxCustomGridOptionsBehavior
{
	typedef Cxgridcustomview::TcxCustomGridOptionsBehavior inherited;
	
private:
	bool FAlwaysShowEditor;
	int FBestFitMaxRecordCount;
	bool FCellHints;
	bool FCopyCaptionsToClipboard;
	bool FCopyRecordsToClipboard;
	bool FDragDropText;
	TcxGridDragFocusing FDragFocusing;
	bool FDragHighlighting;
	bool FDragOpening;
	bool FDragScrolling;
	Cxedit::TcxInplaceEditAutoHeight FEditAutoHeight;
	bool FFocusCellOnCycle;
	bool FFocusCellOnTab;
	bool FFocusFirstCellOnNewRecord;
	bool FGoToNextCellOnEnter;
	bool FImmediateEditor;
	bool FIncSearch;
	TcxCustomGridTableItem* FIncSearchItem;
	bool FNavigatorHints;
	bool FPullFocusing;
	Cxcontrols::TcxRecordScrollMode FRecordScrollMode;
	bool FRepaintVisibleRecordsOnScroll;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	TcxCustomGridTableShowLockedStateImageOptions* __fastcall GetShowLockedStateImageOptions(void);
	void __fastcall SetAlwaysShowEditor(bool Value);
	void __fastcall SetBestFitMaxRecordCount(int Value);
	void __fastcall SetCellHints(bool Value);
	void __fastcall SetCopyCaptionsToClipboard(bool Value);
	void __fastcall SetCopyRecordsToClipboard(bool Value);
	void __fastcall SetDragDropText(bool Value);
	void __fastcall SetDragFocusing(TcxGridDragFocusing Value);
	void __fastcall SetDragHighlighting(bool Value);
	void __fastcall SetDragOpening(bool Value);
	void __fastcall SetDragScrolling(bool Value);
	void __fastcall SetEditAutoHeight(Cxedit::TcxInplaceEditAutoHeight Value);
	void __fastcall SetFocusCellOnCycle(bool Value);
	void __fastcall SetFocusCellOnTab(bool Value);
	void __fastcall SetFocusFirstCellOnNewRecord(bool Value);
	void __fastcall SetGoToNextCellOnEnter(bool Value);
	void __fastcall SetImmediateEditor(bool Value);
	void __fastcall SetIncSearch(bool Value);
	void __fastcall SetIncSearchItem(TcxCustomGridTableItem* Value);
	void __fastcall SetNavigatorHints(bool Value);
	void __fastcall SetPullFocusing(bool Value);
	void __fastcall SetRecordScrollMode(Cxcontrols::TcxRecordScrollMode Value);
	void __fastcall SetRepaintVisibleRecordsOnScroll(bool Value);
	HIDESBASE void __fastcall SetShowLockedStateImageOptions(TcxCustomGridTableShowLockedStateImageOptions* Value);
	
protected:
	virtual Cxgridcustomview::TcxCustomGridShowLockedStateImageOptionsClass __fastcall GetShowLockedStateImageOptionsClass(void);
	__property Cxedit::TcxInplaceEditAutoHeight EditAutoHeight = {read=FEditAutoHeight, write=SetEditAutoHeight, default=0};
	__property bool FocusCellOnCycle = {read=FFocusCellOnCycle, write=SetFocusCellOnCycle, default=0};
	__property Cxcontrols::TcxRecordScrollMode RecordScrollMode = {read=FRecordScrollMode, write=SetRecordScrollMode, default=0};
	__property TcxCustomGridTableShowLockedStateImageOptions* ShowLockedStateImageOptions = {read=GetShowLockedStateImageOptions, write=SetShowLockedStateImageOptions};
	__property bool PullFocusing = {read=FPullFocusing, write=SetPullFocusing, default=0};
	__property bool RepaintVisibleRecordsOnScroll = {read=FRepaintVisibleRecordsOnScroll, write=SetRepaintVisibleRecordsOnScroll, default=0};
	
public:
	__fastcall virtual TcxCustomGridTableOptionsBehavior(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int BestFitMaxRecordCount = {read=FBestFitMaxRecordCount, write=SetBestFitMaxRecordCount, default=0};
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	
__published:
	__property bool AlwaysShowEditor = {read=FAlwaysShowEditor, write=SetAlwaysShowEditor, default=0};
	__property bool CellHints = {read=FCellHints, write=SetCellHints, default=0};
	__property bool CopyCaptionsToClipboard = {read=FCopyCaptionsToClipboard, write=SetCopyCaptionsToClipboard, default=1};
	__property bool CopyRecordsToClipboard = {read=FCopyRecordsToClipboard, write=SetCopyRecordsToClipboard, default=1};
	__property bool DragDropText = {read=FDragDropText, write=SetDragDropText, default=0};
	__property TcxGridDragFocusing DragFocusing = {read=FDragFocusing, write=SetDragFocusing, default=0};
	__property bool DragHighlighting = {read=FDragHighlighting, write=SetDragHighlighting, default=1};
	__property bool DragOpening = {read=FDragOpening, write=SetDragOpening, default=1};
	__property bool DragScrolling = {read=FDragScrolling, write=SetDragScrolling, default=1};
	__property bool FocusCellOnTab = {read=FFocusCellOnTab, write=SetFocusCellOnTab, default=0};
	__property bool FocusFirstCellOnNewRecord = {read=FFocusFirstCellOnNewRecord, write=SetFocusFirstCellOnNewRecord, default=0};
	__property bool GoToNextCellOnEnter = {read=FGoToNextCellOnEnter, write=SetGoToNextCellOnEnter, default=0};
	__property HintHidePause = {default=0};
	__property bool ImmediateEditor = {read=FImmediateEditor, write=SetImmediateEditor, default=1};
	__property bool IncSearch = {read=FIncSearch, write=SetIncSearch, default=0};
	__property TcxCustomGridTableItem* IncSearchItem = {read=FIncSearchItem, write=SetIncSearchItem};
	__property bool NavigatorHints = {read=FNavigatorHints, write=SetNavigatorHints, default=0};
	__property ShowHourglassCursor = {default=1};
	__property SuppressHintOnMouseDown = {default=1};
public:
	/* TcxCustomGridOptionsBehavior.Destroy */ inline __fastcall virtual ~TcxCustomGridTableOptionsBehavior(void) { }
	
};

#pragma pack(pop)

enum TcxGridQuickCustomizationReordering : unsigned char { qcrDefault, qcrEnabled, qcrDisabled };

typedef System::TMetaClass* TcxCustomGridTableOptionsCustomizeClass;

class DELPHICLASS TcxCustomGridTableOptionsCustomize;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableOptionsCustomize : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	bool FItemFiltering;
	bool FItemGrouping;
	bool FItemHiding;
	bool FItemMoving;
	bool FItemSorting;
	bool FItemsQuickCustomization;
	int FItemsQuickCustomizationMaxDropDownCount;
	TcxGridQuickCustomizationReordering FItemsQuickCustomizationReordering;
	void __fastcall SetItemFiltering(bool Value);
	void __fastcall SetItemGrouping(bool Value);
	void __fastcall SetItemHiding(bool Value);
	void __fastcall SetItemMoving(bool Value);
	void __fastcall SetItemSorting(bool Value);
	void __fastcall SetItemsQuickCustomization(bool Value);
	void __fastcall SetItemsQuickCustomizationMaxDropDownCount(int Value);
	void __fastcall SetItemsQuickCustomizationReordering(TcxGridQuickCustomizationReordering Value);
	
protected:
	__property bool ItemFiltering = {read=FItemFiltering, write=SetItemFiltering, default=1};
	__property bool ItemGrouping = {read=FItemGrouping, write=SetItemGrouping, default=1};
	__property bool ItemHiding = {read=FItemHiding, write=SetItemHiding, default=0};
	__property bool ItemMoving = {read=FItemMoving, write=SetItemMoving, default=1};
	__property bool ItemSorting = {read=FItemSorting, write=SetItemSorting, default=1};
	__property bool ItemsQuickCustomization = {read=FItemsQuickCustomization, write=SetItemsQuickCustomization, default=0};
	__property int ItemsQuickCustomizationMaxDropDownCount = {read=FItemsQuickCustomizationMaxDropDownCount, write=SetItemsQuickCustomizationMaxDropDownCount, default=0};
	__property TcxGridQuickCustomizationReordering ItemsQuickCustomizationReordering = {read=FItemsQuickCustomizationReordering, write=SetItemsQuickCustomizationReordering, default=0};
	
public:
	__fastcall virtual TcxCustomGridTableOptionsCustomize(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall SupportsItemsQuickCustomizationReordering(void);
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridTableOptionsCustomize(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableOptionsData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableOptionsData : public Cxgridcustomview::TcxCustomGridOptionsData
{
	typedef Cxgridcustomview::TcxCustomGridOptionsData inherited;
	
private:
	bool FAppending;
	bool FCancelOnExit;
	bool FDeleting;
	bool FDeletingConfirmation;
	bool FEditing;
	bool FInserting;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	void __fastcall SetAppending(bool Value);
	void __fastcall SetCancelOnExit(bool Value);
	void __fastcall SetDeleting(bool Value);
	void __fastcall SetDeletingConfirmation(bool Value);
	void __fastcall SetEditing(bool Value);
	void __fastcall SetInserting(bool Value);
	
public:
	__fastcall virtual TcxCustomGridTableOptionsData(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	
__published:
	__property bool Appending = {read=FAppending, write=SetAppending, default=0};
	__property bool CancelOnExit = {read=FCancelOnExit, write=SetCancelOnExit, default=1};
	__property bool Deleting = {read=FDeleting, write=SetDeleting, default=1};
	__property bool DeletingConfirmation = {read=FDeletingConfirmation, write=SetDeletingConfirmation, default=1};
	__property bool Editing = {read=FEditing, write=SetEditing, default=1};
	__property bool Inserting = {read=FInserting, write=SetInserting, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridTableOptionsData(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableOptionsSelection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableOptionsSelection : public Cxgridcustomview::TcxCustomGridOptionsSelection
{
	typedef Cxgridcustomview::TcxCustomGridOptionsSelection inherited;
	
private:
	bool FCellSelect;
	bool FHideFocusRectOnExit;
	bool FHideSelection;
	bool FInvertSelect;
	bool FUnselectFocusedRecordOnExit;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	bool __fastcall GetMultiSelect(void);
	void __fastcall SetHideFocusRectOnExit(bool Value);
	void __fastcall SetHideSelection(bool Value);
	void __fastcall SetUnselectFocusedRecordOnExit(bool Value);
	
protected:
	virtual void __fastcall SetCellSelect(bool Value);
	virtual void __fastcall SetInvertSelect(bool Value);
	virtual void __fastcall SetMultiSelect(bool Value);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxCustomGridTableOptionsSelection(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CellSelect = {read=FCellSelect, write=SetCellSelect, default=1};
	__property bool HideFocusRect = {read=FHideFocusRectOnExit, write=SetHideFocusRectOnExit, stored=false, nodefault};
	__property bool HideFocusRectOnExit = {read=FHideFocusRectOnExit, write=SetHideFocusRectOnExit, default=1};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=0};
	__property bool InvertSelect = {read=FInvertSelect, write=SetInvertSelect, default=1};
	__property bool MultiSelect = {read=GetMultiSelect, write=SetMultiSelect, default=0};
	__property bool UnselectFocusedRecordOnExit = {read=FUnselectFocusedRecordOnExit, write=SetUnselectFocusedRecordOnExit, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridTableOptionsSelection(void) { }
	
};

#pragma pack(pop)

enum TcxGridShowEditButtons : unsigned char { gsebNever, gsebForFocusedRecord, gsebAlways };

enum TcxGridShowItemFilterButtons : unsigned char { sfbAlways, sfbWhenSelected };

enum TcxGridItemFilterButtonShowMode : unsigned char { fbmButton, fbmSmartTag };

class DELPHICLASS TcxCustomGridTableOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableOptionsView : public Cxgridcustomview::TcxCustomGridOptionsView
{
	typedef Cxgridcustomview::TcxCustomGridOptionsView inherited;
	
private:
	bool FCellAutoHeight;
	bool FCellEndEllipsis;
	int FCellTextMaxLineCount;
	System::Uitypes::TColor FEditAutoHeightBorderColor;
	bool FFocusRect;
	bool FItemCaptionAutoHeight;
	bool FItemCaptionEndEllipsis;
	TcxGridItemFilterButtonShowMode FItemFilterButtonShowMode;
	int FNavigatorOffset;
	System::UnicodeString FNoDataToDisplayInfoText;
	TcxGridShowEditButtons FShowEditButtons;
	TcxGridShowItemFilterButtons FShowItemFilterButtons;
	TcxCustomGridTableView* __fastcall GetGridView(void);
	void __fastcall ReadNavigator(System::Classes::TReader* Reader);
	void __fastcall SetCellAutoHeight(bool Value);
	void __fastcall SetCellEndEllipsis(bool Value);
	void __fastcall SetCellTextMaxLineCount(int Value);
	void __fastcall SetEditAutoHeightBorderColor(System::Uitypes::TColor Value);
	void __fastcall SetFocusRect(bool Value);
	void __fastcall SetItemCaptionAutoHeight(bool Value);
	void __fastcall SetItemCaptionEndEllipsis(bool Value);
	void __fastcall SetItemFilterButtonShowMode(TcxGridItemFilterButtonShowMode Value);
	void __fastcall SetNavigatorOffset(int Value);
	void __fastcall SetNoDataToDisplayInfoText(const System::UnicodeString Value);
	void __fastcall SetShowEditButtons(TcxGridShowEditButtons Value);
	void __fastcall SetShowItemFilterButtons(TcxGridShowItemFilterButtons Value);
	bool __fastcall IsNoDataToDisplayInfoTextAssigned(void);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall ItemCaptionAutoHeightChanged(void);
	__property bool CellAutoHeight = {read=FCellAutoHeight, write=SetCellAutoHeight, default=0};
	__property int CellTextMaxLineCount = {read=FCellTextMaxLineCount, write=SetCellTextMaxLineCount, default=0};
	__property System::Uitypes::TColor EditAutoHeightBorderColor = {read=FEditAutoHeightBorderColor, write=SetEditAutoHeightBorderColor, default=536870912};
	__property bool ItemCaptionAutoHeight = {read=FItemCaptionAutoHeight, write=SetItemCaptionAutoHeight, default=0};
	__property TcxGridItemFilterButtonShowMode ItemFilterButtonShowMode = {read=FItemFilterButtonShowMode, write=SetItemFilterButtonShowMode, default=0};
	__property bool ItemCaptionEndEllipsis = {read=FItemCaptionEndEllipsis, write=SetItemCaptionEndEllipsis, default=0};
	__property TcxGridShowItemFilterButtons ShowItemFilterButtons = {read=FShowItemFilterButtons, write=SetShowItemFilterButtons, default=1};
	
public:
	__fastcall virtual TcxCustomGridTableOptionsView(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::Uitypes::TColor __fastcall GetGridLineColor(void);
	System::UnicodeString __fastcall GetNoDataToDisplayInfoText(void);
	__property TcxCustomGridTableView* GridView = {read=GetGridView};
	
__published:
	__property bool CellEndEllipsis = {read=FCellEndEllipsis, write=SetCellEndEllipsis, default=0};
	__property bool FocusRect = {read=FFocusRect, write=SetFocusRect, default=1};
	__property int NavigatorOffset = {read=FNavigatorOffset, write=SetNavigatorOffset, default=50};
	__property System::UnicodeString NoDataToDisplayInfoText = {read=FNoDataToDisplayInfoText, write=SetNoDataToDisplayInfoText, stored=IsNoDataToDisplayInfoTextAssigned};
	__property ScrollBars = {default=3};
	__property TcxGridShowEditButtons ShowEditButtons = {read=FShowEditButtons, write=SetShowEditButtons, default=0};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxCustomGridTableOptionsView(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridCellPos;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridCellPos : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomGridRecord* GridRecord;
	System::TObject* Item;
	__fastcall TcxGridCellPos(TcxCustomGridRecord* AGridRecord, System::TObject* AItem);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridCellPos(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridDataCellPos;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridDataCellPos : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomGridRecord* GridRecord;
	TcxCustomGridTableItem* Item;
	__fastcall TcxGridDataCellPos(TcxCustomGridRecord* AGridRecord, TcxCustomGridTableItem* AItem)/* overload */;
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridDataCellPos(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableViewStyles;
class PASCALIMPLEMENTATION TcxCustomGridTableViewStyles : public Cxgridcustomview::TcxCustomGridViewStyles
{
	typedef Cxgridcustomview::TcxCustomGridViewStyles inherited;
	
private:
	TcxGridGetCellStyleEvent FOnGetContentStyle;
	TcxCustomGridTableView* __fastcall GetGridViewValue(void);
	void __fastcall SetOnGetContentStyle(TcxGridGetCellStyleEvent Value);
	
protected:
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetSelectionParams(TcxCustomGridRecord* ARecord, System::TObject* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetCellContentParams(TcxCustomGridRecord* ARecord, System::TObject* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetContentParams(TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetDataCellContentParams(TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetDataCellParams(TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams, bool AUseViewInfo = false, TcxGridTableCellViewInfo* ACellViewInfo = (TcxGridTableCellViewInfo*)(0x0), bool AIgnoreSelection = false);
	virtual void __fastcall GetRecordContentParams(TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxCustomGridTableView* GridView = {read=GetGridViewValue};
	
__published:
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* ContentEven = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* ContentOdd = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* FilterBox = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* Inactive = {read=GetValue, write=SetValue, index=5};
	__property Cxstyles::TcxStyle* IncSearch = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* Navigator = {read=GetValue, write=SetValue, index=7};
	__property Cxstyles::TcxStyle* NavigatorInfoPanel = {read=GetValue, write=SetValue, index=9};
	__property Cxstyles::TcxStyle* Selection = {read=GetValue, write=SetValue, index=8};
	__property TcxGridGetCellStyleEvent OnGetContentStyle = {read=FOnGetContentStyle, write=SetOnGetContentStyle};
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxCustomGridTableViewStyles(System::Classes::TPersistent* AOwner) : Cxgridcustomview::TcxCustomGridViewStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxCustomGridTableViewStyles(void) { }
	
};


class DELPHICLASS TcxGridOpenTableItemList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridOpenTableItemList : public Cxclasses::TcxOpenList
{
	typedef Cxclasses::TcxOpenList inherited;
	
public:
	TcxCustomGridTableItem* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxCustomGridTableItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxCustomGridTableItem* Value);
	
public:
	__property TcxCustomGridTableItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxGridOpenTableItemList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridOpenTableItemList(void) : Cxclasses::TcxOpenList() { }
	
};

#pragma pack(pop)

enum TcxGridViewRestoringFilterAttribute : unsigned char { rfaActive, rfaData, rfaMRUItems };

typedef System::Set<TcxGridViewRestoringFilterAttribute, TcxGridViewRestoringFilterAttribute::rfaActive, TcxGridViewRestoringFilterAttribute::rfaMRUItems>  TcxGridViewRestoringFilterAttributes;

typedef void __fastcall (__closure *TcxGridTableCellCustomDrawEvent)(TcxCustomGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridTableCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridAllowRecordOperationEvent)(TcxCustomGridTableView* Sender, TcxCustomGridRecord* ARecord, bool &AAllow);

typedef void __fastcall (__closure *TcxGridCellClickEvent)(TcxCustomGridTableView* Sender, TcxGridTableDataCellViewInfo* ACellViewInfo, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, bool &AHandled);

typedef void __fastcall (__closure *TcxGridCustomTableViewEvent)(TcxCustomGridTableView* Sender);

typedef void __fastcall (__closure *TcxGridEditingEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* AItem, bool &AAllow);

typedef void __fastcall (__closure *TcxGridEditDblClickEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit);

typedef void __fastcall (__closure *TcxGridEditKeyEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit, System::Word &Key, System::Classes::TShiftState Shift);

typedef void __fastcall (__closure *TcxGridEditKeyPressEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit, System::WideChar &Key);

typedef void __fastcall (__closure *TcxGridCustomTableItemEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* AItem);

typedef void __fastcall (__closure *TcxGridFilterCustomizationEvent)(TcxCustomGridTableView* Sender, bool &ADone);

typedef void __fastcall (__closure *TcxGridFilterDialogShowEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* AItem, bool &ADone);

typedef void __fastcall (__closure *TcxGridFocusedItemChangedEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* APrevFocusedItem, TcxCustomGridTableItem* AFocusedItem);

typedef void __fastcall (__closure *TcxGridFocusedRecordChangedEvent)(TcxCustomGridTableView* Sender, TcxCustomGridRecord* APrevFocusedRecord, TcxCustomGridRecord* AFocusedRecord, bool ANewItemRecordFocusingChanged);

typedef void __fastcall (__closure *TcxGridGetCellHeightEvent)(TcxCustomGridTableView* Sender, TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, TcxGridTableDataCellViewInfo* ACellViewInfo, int &AHeight);

typedef void __fastcall (__closure *TcxGridGetDragDropTextEvent)(TcxCustomGridTableView* Sender, TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxGridInitEditEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit);

typedef void __fastcall (__closure *TcxGridInitEditValueEvent)(TcxCustomGridTableView* Sender, TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit, System::Variant &AValue);

typedef void __fastcall (__closure *TcxGridPartCustomDrawBackgroundEvent)(TcxCustomGridTableView* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxGridRecordEvent)(TcxCustomGridTableView* Sender, TcxCustomGridRecord* ARecord);

enum TcxGridDataControllerChange : unsigned char { dccItemAdded, dccItemRemoved, dccIndexesChanged };

class PASCALIMPLEMENTATION TcxCustomGridTableView : public Cxgridcustomview::TcxCustomGridView
{
	typedef Cxgridcustomview::TcxCustomGridView inherited;
	
private:
	TcxGridOpenTableItemList* FAssigningGroupedItems;
	TcxGridOpenTableItemList* FAssigningSortedItems;
	System::Classes::TList* FCopyToClipboardItems;
	System::UnicodeString FCopyToClipboardStr;
	TcxCustomGridTableDateTimeHandling* FDateTimeHandling;
	bool FDontMakeMasterRecordVisible;
	System::Classes::TList* FFilterableItems;
	TcxGridFilterBox* FFilterBox;
	TcxCustomGridTableFiltering* FFiltering;
	bool FIgnorePropertiesChanges;
	bool FIsAfterAssigningItems;
	bool FIsAssigningItems;
	System::Classes::TList* FItems;
	TcxGridViewNavigator* FNavigator;
	Cxnavigator::TcxNavigatorControlNotifier* FNavigatorNotifier;
	int FNextID;
	TcxCustomGridTableOptionsCustomize* FOptionsCustomize;
	bool FRestoringFilterActive;
	TcxGridViewRestoringFilterAttributes FRestoringFilterAttributes;
	System::AnsiString FRestoringFilterData;
	System::Classes::TStringList* FRestoringFilterMRUItems;
	TcxGridOpenTableItemList* FRestoringItems;
	System::Classes::TList* FVisibleItems;
	TcxGridAllowRecordOperationEvent FOnCanFocusRecord;
	TcxGridAllowRecordOperationEvent FOnCanSelectRecord;
	TcxGridCellClickEvent FOnCellClick;
	TcxGridCellClickEvent FOnCellDblClick;
	TcxGridTableDataCellCustomDrawEvent FOnCustomDrawCell;
	TcxGridPartCustomDrawBackgroundEvent FOnCustomDrawPartBackground;
	TcxGridEditingEvent FOnEditing;
	TcxGridCustomTableItemEvent FOnEditChanged;
	TcxGridEditDblClickEvent FOnEditDblClick;
	TcxGridEditKeyEvent FOnEditKeyDown;
	TcxGridEditKeyPressEvent FOnEditKeyPress;
	TcxGridEditKeyEvent FOnEditKeyUp;
	TcxGridCustomTableItemEvent FOnEditValueChanged;
	System::Classes::TNotifyEvent FOnFilterControlDialogShow;
	TcxGridFilterCustomizationEvent FOnFilterCustomization;
	TcxGridFilterDialogShowEvent FOnFilterDialogShow;
	TcxGridFocusedItemChangedEvent FOnFocusedItemChanged;
	TcxGridFocusedRecordChangedEvent FOnFocusedRecordChanged;
	TcxGridGetCellHeightEvent FOnGetCellHeight;
	TcxGridGetDragDropTextEvent FOnGetDragDropText;
	TcxGridInitDateRangesEvent FOnInitFilteringDateRanges;
	TcxGridInitDateRangesEvent FOnInitGroupingDateRanges;
	TcxGridInitEditEvent FOnInitEdit;
	TcxGridInitEditValueEvent FOnInitEditValue;
	TcxGridCustomTableViewEvent FOnSelectionChanged;
	System::Classes::TNotifyEvent FOnTopRecordIndexChanged;
	TcxGridInitEditEvent FOnUpdateEdit;
	System::Classes::TNotifyEvent FSubClassEvents;
	TcxCustomGridTableBackgroundBitmaps* __fastcall GetBackgroundBitmaps(void);
	TcxCustomGridTableController* __fastcall GetController(void);
	TcxCustomGridTableItem* __fastcall GetFilterableItem(int Index);
	int __fastcall GetFilterableItemCount(void);
	TcxCustomGridTableItem* __fastcall GetGroupedItem(int Index);
	int __fastcall GetGroupedItemCount(void);
	TcxCustomGridTableItem* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	TcxCustomGridRecord* __fastcall GetMasterGridRecord(void);
	Cxnavigator::TcxNavigatorControlButtons* __fastcall GetNavigatorButtons(void);
	TcxCustomGridTableOptionsBehavior* __fastcall GetOptionsBehavior(void);
	TcxCustomGridTableOptionsData* __fastcall GetOptionsData(void);
	TcxCustomGridTableOptionsSelection* __fastcall GetOptionsSelection(void);
	TcxCustomGridTableOptionsView* __fastcall GetOptionsView(void);
	TcxCustomGridTablePainter* __fastcall GetPainter(void);
	HIDESBASE TcxCustomGridTableView* __fastcall GetPatternGridView(void);
	Cxnavigator::_di_IcxNavigator __fastcall GetNavigatorButtonsControl(void);
	TcxCustomGridTableItem* __fastcall GetSortedItem(int Index);
	int __fastcall GetSortedItemCount(void);
	TcxCustomGridTableViewStyles* __fastcall GetStyles(void);
	TcxCustomGridTableViewData* __fastcall GetViewData(void);
	TcxCustomGridTableViewInfo* __fastcall GetViewInfo(void);
	TcxCustomGridTableItem* __fastcall GetVisibleItem(int Index);
	int __fastcall GetVisibleItemCount(void);
	HIDESBASE void __fastcall SetBackgroundBitmaps(TcxCustomGridTableBackgroundBitmaps* Value);
	void __fastcall SetDateTimeHandling(TcxCustomGridTableDateTimeHandling* Value);
	void __fastcall SetFilterBox(TcxGridFilterBox* Value);
	void __fastcall SetFiltering(TcxCustomGridTableFiltering* Value);
	void __fastcall SetItem(int Index, TcxCustomGridTableItem* Value);
	void __fastcall SetNavigator(TcxGridViewNavigator* Value);
	void __fastcall SetNavigatorButtons(Cxnavigator::TcxNavigatorControlButtons* Value);
	void __fastcall SetOnCanFocusRecord(TcxGridAllowRecordOperationEvent Value);
	void __fastcall SetOnCanSelectRecord(TcxGridAllowRecordOperationEvent Value);
	void __fastcall SetOnCellClick(TcxGridCellClickEvent Value);
	void __fastcall SetOnCellDblClick(TcxGridCellClickEvent Value);
	void __fastcall SetOnCustomDrawCell(TcxGridTableDataCellCustomDrawEvent Value);
	void __fastcall SetOnCustomDrawPartBackground(TcxGridPartCustomDrawBackgroundEvent Value);
	void __fastcall SetOnEditChanged(TcxGridCustomTableItemEvent Value);
	void __fastcall SetOnEditDblClick(TcxGridEditDblClickEvent Value);
	void __fastcall SetOnEditing(TcxGridEditingEvent Value);
	void __fastcall SetOnEditKeyDown(TcxGridEditKeyEvent Value);
	void __fastcall SetOnEditKeyPress(TcxGridEditKeyPressEvent Value);
	void __fastcall SetOnEditKeyUp(TcxGridEditKeyEvent Value);
	void __fastcall SetOnEditValueChanged(TcxGridCustomTableItemEvent Value);
	void __fastcall SetOnFilterControlDialogShow(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnFilterCustomization(TcxGridFilterCustomizationEvent Value);
	void __fastcall SetOnFilterDialogShow(TcxGridFilterDialogShowEvent Value);
	void __fastcall SetOnFocusedItemChanged(TcxGridFocusedItemChangedEvent Value);
	void __fastcall SetOnFocusedRecordChanged(TcxGridFocusedRecordChangedEvent Value);
	void __fastcall SetOnGetCellHeight(TcxGridGetCellHeightEvent Value);
	void __fastcall SetOnGetDragDropText(TcxGridGetDragDropTextEvent Value);
	void __fastcall SetOnInitFilteringDateRanges(TcxGridInitDateRangesEvent Value);
	void __fastcall SetOnInitGroupingDateRanges(TcxGridInitDateRangesEvent Value);
	void __fastcall SetOnInitEdit(TcxGridInitEditEvent Value);
	void __fastcall SetOnInitEditValue(TcxGridInitEditValueEvent Value);
	void __fastcall SetOnSelectionChanged(TcxGridCustomTableViewEvent Value);
	void __fastcall SetOnTopRecordIndexChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetOnUpdateEdit(TcxGridInitEditEvent Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxCustomGridTableOptionsBehavior* Value);
	void __fastcall SetOptionsCustomize(TcxCustomGridTableOptionsCustomize* Value);
	HIDESBASE void __fastcall SetOptionsData(TcxCustomGridTableOptionsData* Value);
	HIDESBASE void __fastcall SetOptionsSelection(TcxCustomGridTableOptionsSelection* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxCustomGridTableOptionsView* Value);
	HIDESBASE void __fastcall SetStyles(TcxCustomGridTableViewStyles* Value);
	void __fastcall CopyForEachRowProc(int ARowIndex, const Cxcustomdata::TcxRowInfo &ARowInfo);
	void __fastcall RefreshItemIndexes(void);
	
protected:
	System::UnicodeString __fastcall GetFilterCaption(int Index);
	int __fastcall GetFilterCount(void);
	Cxfilter::TcxFilterCriteria* __fastcall GetFilterCriteria(void);
	System::UnicodeString __fastcall GetFilterFieldName(int Index);
	System::TObject* __fastcall GetFilterItemLink(int Index);
	int __fastcall GetFilterItemLinkID(int Index);
	System::UnicodeString __fastcall GetFilterItemLinkName(int Index);
	Cxedit::TcxCustomEditProperties* __fastcall GetFilterProperties(int Index);
	Cxdatastorage::TcxValueTypeClass __fastcall GetFilterValueType(int Index);
	bool __fastcall NavigatorIsActive(void);
	bool __fastcall NavigatorIsBof(void);
	bool __fastcall NavigatorIsEof(void);
	bool __fastcall NavigatorCanAppend(void);
	bool __fastcall NavigatorCanEdit(void);
	bool __fastcall NavigatorCanDelete(void);
	bool __fastcall NavigatorCanInsert(void);
	bool __fastcall NavigatorIsEditing(void);
	void __fastcall NavigatorClearBookmark(void);
	bool __fastcall NavigatorIsBookmarkAvailable(void);
	void __fastcall NavigatorDoAction(int AButtonIndex);
	Cxnavigator::TcxNavigatorControlNotifier* __fastcall NavigatorGetNotifier(void);
	bool __fastcall NavigatorIsActionSupported(int AButtonIndex);
	int __fastcall NavigatorGetRecordCount(void);
	int __fastcall NavigatorGetRecordIndex(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual System::TObject* __fastcall CreateStoredObject(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual void __fastcall AssignLayout(Cxgridcustomview::TcxCustomGridView* ALayoutView);
	virtual void __fastcall BeforeEditLayout(Cxgridcustomview::TcxCustomGridView* ALayoutView);
	virtual System::Uitypes::TScrollStyle __fastcall GetSystemSizeScrollBars(void);
	virtual bool __fastcall HasLayoutCustomizationForm(void);
	virtual void __fastcall ApplyRestoredFilter(void);
	virtual void __fastcall BeforeRestoring(void);
	virtual void __fastcall AfterRestoring(void);
	virtual void __fastcall ReadState(System::Classes::TReader* Reader);
	__property TcxGridOpenTableItemList* RestoringItems = {read=FRestoringItems};
	void __fastcall BeginAssignItems(void);
	virtual void __fastcall DoBeforeAssignItems(void);
	virtual void __fastcall DoItemsAssigned(void);
	void __fastcall EndAssignItems(void);
	__property TcxGridOpenTableItemList* AssigningGroupedItems = {read=FAssigningGroupedItems};
	__property TcxGridOpenTableItemList* AssigningSortedItems = {read=FAssigningSortedItems};
	__property bool IsAssigningItems = {read=FIsAssigningItems, nodefault};
	__property bool IsAfterAssigningItems = {read=FIsAfterAssigningItems, nodefault};
	virtual bool __fastcall CanOffset(int ARecordCountDelta);
	virtual bool __fastcall CanSelectRecord(int ARecordIndex);
	virtual bool __fastcall CanTabStop(void);
	virtual void __fastcall DetailVisibleChanged(System::Classes::TComponent* ADetailLevel, int APrevVisibleDetailCount, int AVisibleDetailCount);
	virtual void __fastcall DoAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual TcxCustomGridTableItem* __fastcall FindItemByObjectName(const System::UnicodeString AObjectName);
	virtual void __fastcall FocusEdit(int AItemIndex, bool &ADone);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual int __fastcall GetDefaultActiveDetailIndex(void);
	virtual Cxedit::TcxInplaceEditAutoHeight __fastcall GetEditAutoHeight(void);
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	virtual bool __fastcall GetIsControlFocused(void);
	virtual void __fastcall GetItemsListForClipboard(System::Classes::TList* AItems, bool ACopyAll);
	bool __fastcall GetItemSortByDisplayText(int AItemIndex, bool ASortByDisplayText);
	Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(int AItemIndex);
	virtual void __fastcall GetVisibleItemsList(System::Classes::TList* AItems);
	bool __fastcall HasCustomDrawCell(void);
	bool __fastcall HasCustomDrawPartBackground(void);
	virtual void __fastcall Init(void);
	virtual bool __fastcall IsDetailVisible(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual bool __fastcall IsEqualHeightRecords(void);
	virtual bool __fastcall IsEqualScrollSizeRecords(void);
	virtual bool __fastcall IsRecordHeightDependsOnData(void);
	virtual bool __fastcall IsRecordHeightDependsOnFocus(void);
	virtual bool __fastcall IsRecordPixelScrolling(void);
	virtual void __fastcall LoadingComplete(void);
	virtual void __fastcall Offset(int ARecordCountDelta, int APixelScrollRecordOffsetDelta, int DX, int DY);
	DYNAMIC void __fastcall SetChildOrder(System::Classes::TComponent* Child, int Order);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	virtual void __fastcall UpdateControl(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	void __fastcall UpdateDataController(TcxGridDataControllerChange AChange, TcxCustomGridTableItem* AItem = (TcxCustomGridTableItem*)(0x0));
	virtual void __fastcall UpdateRecord(void);
	virtual void __fastcall CreateHandlers(void);
	virtual void __fastcall DestroyHandlers(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual void __fastcall AddItem(TcxCustomGridTableItem* AItem);
	virtual void __fastcall RemoveItem(TcxCustomGridTableItem* AItem);
	void __fastcall AssignVisibleItemsIndexes(void);
	virtual void __fastcall ChangeItemIndex(TcxCustomGridTableItem* AItem, int Value);
	void __fastcall CheckItemVisibles(void);
	void __fastcall SaveItemVisibles(void);
	virtual void __fastcall ItemIndexChanged(TcxCustomGridTableItem* AItem, int AOldIndex);
	virtual void __fastcall ItemVisibilityChanged(TcxCustomGridTableItem* AItem, bool Value);
	virtual void __fastcall RefreshVisibleItemsList(void);
	virtual TcxCustomGridTableItemClass __fastcall GetItemClass(void) = 0 ;
	virtual TcxGridItemDataBindingClass __fastcall GetItemDataBindingClass(void);
	int __fastcall GetNextID(void);
	void __fastcall ReleaseID(int AID);
	virtual void __fastcall Deactivate(void);
	virtual void __fastcall DestroyingSiteHandle(void);
	virtual void __fastcall DataChanged(void);
	virtual void __fastcall DataLayoutChanged(void);
	virtual bool __fastcall DoCellClick(TcxGridTableDataCellViewInfo* ACellViewInfo, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall DoCellDblClick(TcxGridTableDataCellViewInfo* ACellViewInfo, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual bool __fastcall DoEditing(TcxCustomGridTableItem* AItem);
	virtual void __fastcall DoTopRecordIndexChanged(void);
	virtual void __fastcall DoUnlockNotification(Cxcustomdata::TcxUpdateControlInfo* AInfo);
	virtual void __fastcall FilterChanged(void);
	virtual void __fastcall FocusedItemChanged(TcxCustomGridTableItem* APrevFocusedItem, TcxCustomGridTableItem* AFocusedItem);
	virtual void __fastcall FocusedRecordChanged(int APrevFocusedRecordIndex, int AFocusedRecordIndex, int APrevFocusedDataRecordIndex, int AFocusedDataRecordIndex, bool ANewItemRecordFocusingChanged);
	virtual void __fastcall GroupingChanging(void);
	virtual void __fastcall ItemCaptionChanged(TcxCustomGridTableItem* AItem);
	virtual void __fastcall ItemValueTypeClassChanged(int AItemIndex);
	bool __fastcall IsLongFilterOperation(void);
	void __fastcall NotifySelectionChanged(Cxcustomdata::TcxSelectionChangedInfo* AInfo = (Cxcustomdata::TcxSelectionChangedInfo*)(0x0));
	void __fastcall RecalculateDefaultWidths(void);
	virtual void __fastcall RecordChanged(int ARecordIndex);
	virtual void __fastcall RecordCountChanged(void);
	void __fastcall RefreshFilterableItemsList(void);
	void __fastcall RefreshNavigators(void);
	virtual void __fastcall SearchChanged(void);
	virtual void __fastcall SelectionChanged(Cxcustomdata::TcxSelectionChangedInfo* AInfo);
	virtual bool __fastcall CalculateDataCellSelected(TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, bool AUseViewInfo, TcxGridTableCellViewInfo* ACellViewInfo);
	virtual bool __fastcall DrawDataCellSelected(TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, bool AUseViewInfo = false, TcxGridTableCellViewInfo* ACellViewInfo = (TcxGridTableCellViewInfo*)(0x0));
	virtual bool __fastcall DrawRecordActive(TcxCustomGridRecord* ARecord);
	virtual bool __fastcall DrawRecordFocused(TcxCustomGridRecord* ARecord);
	virtual bool __fastcall DrawRecordSelected(TcxCustomGridRecord* ARecord);
	virtual bool __fastcall DrawSelection(void);
	virtual bool __fastcall DoCanFocusRecord(TcxCustomGridRecord* ARecord);
	virtual void __fastcall DoCustomDrawCell(Cxgraphics::TcxCanvas* ACanvas, TcxGridTableDataCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawPartBackground(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoEditChanged(TcxCustomGridTableItem* AItem);
	virtual void __fastcall DoEditDblClick(TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit);
	virtual void __fastcall DoEditKeyDown(TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditKeyPress(TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit, System::WideChar &Key);
	virtual void __fastcall DoEditKeyUp(TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoEditValueChanged(TcxCustomGridTableItem* AItem);
	virtual bool __fastcall DoFilterCustomization(void);
	virtual bool __fastcall DoFilterDialogShow(TcxCustomGridTableItem* AItem);
	virtual void __fastcall DoFocusedRecordChanged(int APrevFocusedRecordIndex, int AFocusedRecordIndex, int APrevFocusedDataRecordIndex, int AFocusedDataRecordIndex, bool ANewItemRecordFocusingChanged);
	virtual void __fastcall DoGetCellHeight(TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem, TcxGridTableDataCellViewInfo* ACellViewInfo, int &AHeight);
	virtual System::UnicodeString __fastcall DoGetDragDropText(TcxCustomGridRecord* ARecord, TcxCustomGridTableItem* AItem);
	virtual void __fastcall DoInitEdit(TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit);
	virtual void __fastcall DoInitEditValue(TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit, System::Variant &AValue);
	virtual void __fastcall DoInitFilteringDateRanges(TcxCustomGridTableItem* AItem);
	virtual void __fastcall DoInitGroupingDateRanges(TcxCustomGridTableItem* AItem);
	virtual void __fastcall DoUpdateEdit(TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit);
	virtual void __fastcall DoSelectionChanged(void);
	bool __fastcall HasCustomProperties(void);
	bool __fastcall HasInitFilteringDateRangesHandler(void);
	bool __fastcall HasInitGroupingDateRangesHandler(void);
	bool __fastcall IsGetCellHeightAssigned(void);
	virtual Cxgridcustomview::TcxCustomGridControllerClass __fastcall GetControllerClass(void);
	virtual Cxgridcustomview::TcxCustomGridPainterClass __fastcall GetPainterClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewDataClass __fastcall GetViewDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheClass __fastcall GetViewInfoCacheClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void);
	virtual Cxgridcustomview::TcxCustomGridBackgroundBitmapsClass __fastcall GetBackgroundBitmapsClass(void);
	virtual TcxCustomGridTableDateTimeHandlingClass __fastcall GetDateTimeHandlingClass(void);
	virtual TcxGridFilterBoxClass __fastcall GetFilterBoxClass(void);
	virtual TcxCustomGridTableFilteringClass __fastcall GetFilteringClass(void);
	virtual Cxnavigator::TcxNavigatorControlButtonsClass __fastcall GetNavigatorButtonsClass(void);
	virtual TcxGridViewNavigatorClass __fastcall GetNavigatorClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual TcxCustomGridTableOptionsCustomizeClass __fastcall GetOptionsCustomizeClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewStylesClass __fastcall GetStylesClass(void);
	virtual Cxcustomdata::TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	__property TcxCustomGridTableBackgroundBitmaps* BackgroundBitmaps = {read=GetBackgroundBitmaps, write=SetBackgroundBitmaps};
	__property bool DontMakeMasterRecordVisible = {read=FDontMakeMasterRecordVisible, write=FDontMakeMasterRecordVisible, nodefault};
	__property int FilterableItemCount = {read=GetFilterableItemCount, nodefault};
	__property TcxCustomGridTableItem* FilterableItems[int Index] = {read=GetFilterableItem};
	__property bool IgnorePropertiesChanges = {read=FIgnorePropertiesChanges, write=FIgnorePropertiesChanges, nodefault};
	__property System::Classes::TList* ItemsList = {read=FItems};
	__property Cxnavigator::TcxNavigatorControlNotifier* NavigatorNotifier = {read=FNavigatorNotifier};
	__property int NextID = {read=FNextID, nodefault};
	__property System::Classes::TList* VisibleItemsList = {read=FVisibleItems};
	__property TcxGridInitDateRangesEvent OnInitGroupingDateRanges = {read=FOnInitGroupingDateRanges, write=SetOnInitGroupingDateRanges};
	
public:
	__fastcall virtual ~TcxCustomGridTableView(void);
	virtual void __fastcall ApplyBestFit(TcxCustomGridTableItem* AItem = (TcxCustomGridTableItem*)(0x0), bool ACheckSizingAbility = false, bool AFireEvents = false);
	void __fastcall ClearItems(void);
	void __fastcall CopyToClipboard(bool ACopyAll);
	TcxCustomGridTableItem* __fastcall CreateItem(void);
	TcxCustomGridTableItem* __fastcall FindItemByID(int AID);
	TcxCustomGridTableItem* __fastcall FindItemByName(const System::UnicodeString AName);
	TcxCustomGridTableItem* __fastcall FindItemByTag(int ATag);
	int __fastcall IndexOfItem(TcxCustomGridTableItem* AItem);
	void __fastcall MakeMasterGridRecordVisible(void);
	virtual void __fastcall RestoreDefaults(void);
	void __fastcall BeginBestFitUpdate(void);
	void __fastcall EndBestFitUpdate(void);
	void __fastcall BeginFilteringUpdate(void);
	void __fastcall EndFilteringUpdate(void);
	void __fastcall BeginGroupingUpdate(void);
	void __fastcall EndGroupingUpdate(void);
	void __fastcall BeginSortingUpdate(void);
	void __fastcall EndSortingUpdate(void);
	__classmethod virtual bool __fastcall CanBeLookupList();
	virtual bool __fastcall CanPopupAutoHeight(void);
	__property TcxCustomGridTableController* Controller = {read=GetController};
	__property TcxCustomGridTableDateTimeHandling* DateTimeHandling = {read=FDateTimeHandling, write=SetDateTimeHandling};
	__property TcxCustomGridTableFiltering* Filtering = {read=FFiltering, write=SetFiltering};
	__property int GroupedItemCount = {read=GetGroupedItemCount, nodefault};
	__property TcxCustomGridTableItem* GroupedItems[int Index] = {read=GetGroupedItem};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxCustomGridTableItem* Items[int Index] = {read=GetItem, write=SetItem};
	__property TcxCustomGridRecord* MasterGridRecord = {read=GetMasterGridRecord};
	__property TcxCustomGridTableOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxCustomGridTableOptionsCustomize* OptionsCustomize = {read=FOptionsCustomize, write=SetOptionsCustomize};
	__property TcxCustomGridTableOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	__property TcxCustomGridTableOptionsSelection* OptionsSelection = {read=GetOptionsSelection, write=SetOptionsSelection};
	__property TcxCustomGridTableOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxCustomGridTablePainter* Painter = {read=GetPainter};
	__property TcxCustomGridTableView* PatternGridView = {read=GetPatternGridView};
	__property int SortedItemCount = {read=GetSortedItemCount, nodefault};
	__property TcxCustomGridTableItem* SortedItems[int Index] = {read=GetSortedItem};
	__property TcxCustomGridTableViewStyles* Styles = {read=GetStyles, write=SetStyles};
	__property TcxCustomGridTableViewData* ViewData = {read=GetViewData};
	__property TcxCustomGridTableViewInfo* ViewInfo = {read=GetViewInfo};
	__property int VisibleItemCount = {read=GetVisibleItemCount, nodefault};
	__property TcxCustomGridTableItem* VisibleItems[int Index] = {read=GetVisibleItem};
	
__published:
	__property TcxGridViewNavigator* Navigator = {read=FNavigator, write=SetNavigator};
	__property TcxGridFilterBox* FilterBox = {read=FFilterBox, write=SetFilterBox};
	__property Cxnavigator::TcxNavigatorControlButtons* NavigatorButtons = {read=GetNavigatorButtons, write=SetNavigatorButtons, stored=false};
	__property System::Classes::TNotifyEvent NavigatorEvents = {read=FSubClassEvents, write=FSubClassEvents};
	__property TcxGridAllowRecordOperationEvent OnCanFocusRecord = {read=FOnCanFocusRecord, write=SetOnCanFocusRecord};
	__property TcxGridAllowRecordOperationEvent OnCanSelectRecord = {read=FOnCanSelectRecord, write=SetOnCanSelectRecord};
	__property TcxGridCellClickEvent OnCellClick = {read=FOnCellClick, write=SetOnCellClick};
	__property TcxGridCellClickEvent OnCellDblClick = {read=FOnCellDblClick, write=SetOnCellDblClick};
	__property TcxGridTableDataCellCustomDrawEvent OnCustomDrawCell = {read=FOnCustomDrawCell, write=SetOnCustomDrawCell};
	__property TcxGridPartCustomDrawBackgroundEvent OnCustomDrawPartBackground = {read=FOnCustomDrawPartBackground, write=SetOnCustomDrawPartBackground};
	__property TcxGridEditingEvent OnEditing = {read=FOnEditing, write=SetOnEditing};
	__property TcxGridCustomTableItemEvent OnEditChanged = {read=FOnEditChanged, write=SetOnEditChanged};
	__property TcxGridEditDblClickEvent OnEditDblClick = {read=FOnEditDblClick, write=SetOnEditDblClick};
	__property TcxGridEditKeyEvent OnEditKeyDown = {read=FOnEditKeyDown, write=SetOnEditKeyDown};
	__property TcxGridEditKeyPressEvent OnEditKeyPress = {read=FOnEditKeyPress, write=SetOnEditKeyPress};
	__property TcxGridEditKeyEvent OnEditKeyUp = {read=FOnEditKeyUp, write=SetOnEditKeyUp};
	__property TcxGridCustomTableItemEvent OnEditValueChanged = {read=FOnEditValueChanged, write=SetOnEditValueChanged};
	__property System::Classes::TNotifyEvent OnFilterControlDialogShow = {read=FOnFilterControlDialogShow, write=SetOnFilterControlDialogShow};
	__property TcxGridFilterCustomizationEvent OnFilterCustomization = {read=FOnFilterCustomization, write=SetOnFilterCustomization};
	__property TcxGridFilterDialogShowEvent OnFilterDialogShow = {read=FOnFilterDialogShow, write=SetOnFilterDialogShow};
	__property TcxGridFocusedItemChangedEvent OnFocusedItemChanged = {read=FOnFocusedItemChanged, write=SetOnFocusedItemChanged};
	__property TcxGridFocusedRecordChangedEvent OnFocusedRecordChanged = {read=FOnFocusedRecordChanged, write=SetOnFocusedRecordChanged};
	__property TcxGridGetCellHeightEvent OnGetCellHeight = {read=FOnGetCellHeight, write=SetOnGetCellHeight};
	__property TcxGridGetDragDropTextEvent OnGetDragDropText = {read=FOnGetDragDropText, write=SetOnGetDragDropText};
	__property TcxGridInitEditEvent OnInitEdit = {read=FOnInitEdit, write=SetOnInitEdit};
	__property TcxGridInitEditValueEvent OnInitEditValue = {read=FOnInitEditValue, write=SetOnInitEditValue};
	__property TcxGridInitDateRangesEvent OnInitFilteringDateRanges = {read=FOnInitFilteringDateRanges, write=SetOnInitFilteringDateRanges};
	__property OnInitStoredObject;
	__property TcxGridCustomTableViewEvent OnSelectionChanged = {read=FOnSelectionChanged, write=SetOnSelectionChanged};
	__property System::Classes::TNotifyEvent OnTopRecordIndexChanged = {read=FOnTopRecordIndexChanged, write=SetOnTopRecordIndexChanged};
	__property TcxGridInitEditEvent OnUpdateEdit = {read=FOnUpdateEdit, write=SetOnUpdateEdit};
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxCustomGridTableView(Cxcontrols::TcxControl* AControl) : Cxgridcustomview::TcxCustomGridView(AControl) { }
	
public:
	/* TcxControlChildComponent.Create */ inline __fastcall virtual TcxCustomGridTableView(System::Classes::TComponent* AOwner) : Cxgridcustomview::TcxCustomGridView(AOwner) { }
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxCustomGridTableView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridcustomview::TcxCustomGridView(AControl, AAssignOwner) { }
	
private:
	void *__IcxNavigatorRecordPosition;	/* Cxnavigator::IcxNavigatorRecordPosition */
	void *__IcxNavigator;	/* Cxnavigator::IcxNavigator */
	void *__IcxFilterControl;	/* Cxfiltercontrol::IcxFilterControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {715C9E38-5BA0-4ED8-B35C-BB40EA739362}
	operator Cxnavigator::_di_IcxNavigatorRecordPosition()
	{
		Cxnavigator::_di_IcxNavigatorRecordPosition intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigatorRecordPosition*(void) { return (Cxnavigator::IcxNavigatorRecordPosition*)&__IcxNavigatorRecordPosition; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A15F80CA-DE56-47CB-B0EB-035D0BF90E9D}
	operator Cxnavigator::_di_IcxNavigator()
	{
		Cxnavigator::_di_IcxNavigator intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxnavigator::IcxNavigator*(void) { return (Cxnavigator::IcxNavigator*)&__IcxNavigator; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B9890E09-5400-428D-8F72-1FF8FD15937C}
	operator Cxfiltercontrol::_di_IcxFilterControl()
	{
		Cxfiltercontrol::_di_IcxFilterControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxfiltercontrol::IcxFilterControl*(void) { return (Cxfiltercontrol::IcxFilterControl*)&__IcxFilterControl; }
	#endif
	
};


class DELPHICLASS TcxCustomGridTableControllerAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableControllerAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void __fastcall FocusNextPage(TcxCustomGridTableController* AInstance, bool ASyncSelection);
	__classmethod void __fastcall FocusPrevPage(TcxCustomGridTableController* AInstance, bool ASyncSelection);
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridTableControllerAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridTableControllerAccess(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableItemAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableItemAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall CanGroup(TcxCustomGridTableItem* AInstance);
	__classmethod bool __fastcall CanHide(TcxCustomGridTableItem* AInstance);
	__classmethod bool __fastcall CanHorzSize(TcxCustomGridTableItem* AInstance);
	__classmethod bool __fastcall CanSort(TcxCustomGridTableItem* AInstance);
	__classmethod void __fastcall CheckWidthValue(TcxCustomGridTableItem* AInstance, int &Value);
	__classmethod void __fastcall DoGetDataText(TcxCustomGridTableItem* AInstance, int ARecordIndex, System::UnicodeString &AText);
	__classmethod void __fastcall DoGetDisplayText(TcxCustomGridTableItem* AInstance, TcxCustomGridRecord* ARecord, System::UnicodeString &AText);
	__classmethod int __fastcall GetGroupIndex(TcxCustomGridTableItem* AInstance);
	__classmethod System::UnicodeString __fastcall GetFilterCaption(TcxCustomGridTableItem* AInstance);
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridTableItemAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridTableItemAccess(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableOptionsBehaviorAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableOptionsBehaviorAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall GetPullFocusing(TcxCustomGridTableOptionsBehavior* AInstance);
	__classmethod void __fastcall SetPullFocusing(TcxCustomGridTableOptionsBehavior* AInstance, bool Value);
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridTableOptionsBehaviorAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridTableOptionsBehaviorAccess(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableOptionsViewAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableOptionsViewAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall GetCellAutoHeight(TcxCustomGridTableOptionsView* AInstance);
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridTableOptionsViewAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridTableOptionsViewAccess(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableViewAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableViewAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall CanSelectRecord(TcxCustomGridTableView* AInstance, int ARecordIndex);
	__classmethod void __fastcall FilterChanged(TcxCustomGridTableView* AInstance);
	__classmethod TcxCustomGridTableItem* __fastcall FindItemByObjectName(TcxCustomGridTableView* AInstance, const System::UnicodeString AObjectName);
	__classmethod void __fastcall FocusEdit(TcxCustomGridTableView* AInstance, int AItemIndex, bool &ADone);
	__classmethod int __fastcall GetDefaultActiveDetailIndex(TcxCustomGridTableView* AInstance);
	__classmethod TcxCustomGridTableItemClass __fastcall GetItemClass(TcxCustomGridTableView* AInstance);
	__classmethod bool __fastcall GetItemSortByDisplayText(TcxCustomGridTableView* AInstance, int AItemIndex, bool ASortByDisplayText);
	__classmethod Cxdatautils::TcxDataEditValueSource __fastcall GetItemValueSource(TcxCustomGridTableView* AInstance, int AItemIndex);
	__classmethod Cxcustomdata::TcxDataSummaryGroupItemLinkClass __fastcall GetSummaryGroupItemLinkClass(TcxCustomGridTableView* AInstance);
	__classmethod Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(TcxCustomGridTableView* AInstance);
	__classmethod bool __fastcall IsEqualHeightRecords(TcxCustomGridTableView* AInstance);
	__classmethod bool __fastcall IsGetCellHeightAssigned(TcxCustomGridTableView* AInstance);
	__classmethod void __fastcall ItemValueTypeClassChanged(TcxCustomGridTableView* AInstance, int AItemIndex);
	__classmethod void __fastcall RefreshNavigators(TcxCustomGridTableView* AInstance);
	__classmethod void __fastcall UpdateRecord(TcxCustomGridTableView* AInstance);
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridTableViewAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridTableViewAccess(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomGridTableViewInfoAccess;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomGridTableViewInfoAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod int __fastcall GetDefaultGridModeBufferCount(TcxCustomGridTableViewInfo* AInstance);
public:
	/* TObject.Create */ inline __fastcall TcxCustomGridTableViewInfoAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomGridTableViewInfoAccess(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxGridFilterDefaultItemMRUItemsListCount = System::Int8(0x5);
static const System::Int8 cxGridFilterDefaultItemPopupMaxDropDownItemCount = System::Int8(0xf);
static const System::Int8 cxGridFilterDefaultMRUItemsListCount = System::Int8(0xa);
static const System::Int8 cxGridItemDefaultMinWidth = System::Int8(0x14);
static const System::Int8 cxGridNavigatorDefaultOffset = System::Int8(0x32);
static const System::Int8 htCustomGridTableBase = System::Int8(0x64);
static const System::Int8 htFilter = System::Int8(0x65);
static const System::Int8 htFilterActivateButton = System::Int8(0x66);
static const System::Int8 htFilterCloseButton = System::Int8(0x67);
static const System::Int8 htFilterDropDownButton = System::Int8(0x68);
static const System::Int8 htFilterCustomizeButton = System::Int8(0x69);
static const System::Int8 htRecord = System::Int8(0x6a);
static const System::Int8 htCell = System::Int8(0x6b);
static const System::Int8 htExpandButton = System::Int8(0x6c);
static const System::Int8 rkNone = System::Int8(-1);
static const System::Int8 rkNormal = System::Int8(0x0);
static const System::Int8 rkNewItem = System::Int8(0x1);
static const System::Int8 isCustomItemFirst = System::Int8(0x0);
static const System::Int8 isContent = System::Int8(0x0);
static const System::Int8 isCustomItemLast = System::Int8(0x0);
static const System::Int8 bbCustomTableFirst = System::Int8(0x1);
static const System::Int8 bbContent = System::Int8(0x1);
static const System::Int8 bbFilterBox = System::Int8(0x2);
static const System::Int8 bbCustomTableLast = System::Int8(0x2);
static const System::Int8 vsCustomTableFirst = System::Int8(0x1);
static const System::Int8 vsContent = System::Int8(0x1);
static const System::Int8 vsContentEven = System::Int8(0x2);
static const System::Int8 vsContentOdd = System::Int8(0x3);
static const System::Int8 vsFilterBox = System::Int8(0x4);
static const System::Int8 vsInactive = System::Int8(0x5);
static const System::Int8 vsIncSearch = System::Int8(0x6);
static const System::Int8 vsNavigator = System::Int8(0x7);
static const System::Int8 vsSelection = System::Int8(0x8);
static const System::Int8 vsNavigatorInfoPanel = System::Int8(0x9);
static const System::Int8 vsCustomTableLast = System::Int8(0x9);
extern PACKAGE System::UnicodeString __fastcall GetViewItemName(TcxCustomGridTableView* AView);
extern PACKAGE TcxCustomGridTableItem* __fastcall CreateViewItem(TcxCustomGridTableView* AView);
}	/* namespace Cxgridcustomtableview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDCUSTOMTABLEVIEW)
using namespace Cxgridcustomtableview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridcustomtableviewHPP
