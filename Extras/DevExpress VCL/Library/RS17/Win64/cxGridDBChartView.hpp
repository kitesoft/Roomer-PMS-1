// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridDBChartView.pas' rev: 24.00 (Win64)

#ifndef CxgriddbchartviewHPP
#define CxgriddbchartviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridChartView.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriddbchartview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridDBChartDataController;
class DELPHICLASS TcxGridDBChartView;
class PASCALIMPLEMENTATION TcxGridDBChartDataController : public Cxdbdata::TcxDBDataController
{
	typedef Cxdbdata::TcxDBDataController inherited;
	
private:
	TcxGridDBChartView* __fastcall GetGridViewValue(void);
	Cxcustomdata::TcxAfterSummaryEvent __fastcall GetOnAfterSummary(void);
	Cxcustomdata::TcxSummaryEvent __fastcall GetOnSummary(void);
	void __fastcall SetOnAfterSummary(Cxcustomdata::TcxAfterSummaryEvent Value);
	void __fastcall SetOnSummary(Cxcustomdata::TcxSummaryEvent Value);
	
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
	Cxgridchartview::TcxGridChartItem* __fastcall GetChartItem(Cxgridchartview::TcxGridChartItemClass AItemClass, int AIndex);
	void __fastcall GetItemCaptions(Cxgridchartview::TcxGridChartItemClass AItemClass, System::Classes::TStringList* ACaptions);
	void __fastcall InitItem(Cxgridchartview::TcxGridChartItem* AItem, int AIndex);
	virtual void __fastcall DoDataSourceChanged(void);
	virtual void __fastcall DoValueTypeClassChanged(int AItemIndex);
	virtual int __fastcall GetItemID(System::TObject* AItem);
	virtual Cxcustomdata::TcxSortingBySummaryEngineClass __fastcall GetSortingBySummaryEngineClass(void);
	void __fastcall GetValidValueFields(Cxgridchartview::TcxGridChartItemClass AItemClass, System::Classes::TList* AFields);
	virtual void __fastcall Unlocked(void);
	
public:
	virtual void __fastcall BeginFullUpdate(void);
	virtual void __fastcall EndFullUpdate(void);
	virtual System::TObject* __fastcall GetItem(int Index);
	__property TcxGridDBChartView* GridView = {read=GetGridViewValue};
	
__published:
	__property DataModeController;
	__property DataSource;
	__property DetailKeyFieldNames = {default=0};
	__property KeyFieldNames = {default=0};
	__property MasterKeyFieldNames = {default=0};
	__property Options = {default=28};
	__property Cxcustomdata::TcxAfterSummaryEvent OnAfterSummary = {read=GetOnAfterSummary, write=SetOnAfterSummary};
	__property OnCompare;
	__property OnDataChanged;
	__property OnFilterRecord;
	__property Cxcustomdata::TcxSummaryEvent OnSummary = {read=GetOnSummary, write=SetOnSummary};
public:
	/* TcxDBDataController.Create */ inline __fastcall virtual TcxGridDBChartDataController(System::Classes::TComponent* AOwner) : Cxdbdata::TcxDBDataController(AOwner) { }
	/* TcxDBDataController.Destroy */ inline __fastcall virtual ~TcxGridDBChartDataController(void) { }
	
private:
	void *__IcxGridChartViewItemsProvider;	/* Cxgridchartview::IcxGridChartViewItemsProvider */
	void *__IcxCustomGridDataController;	/* Cxgridcustomview::IcxCustomGridDataController */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {852B466D-5068-4600-BBC6-0061BF69A0B0}
	operator Cxgridchartview::_di_IcxGridChartViewItemsProvider()
	{
		Cxgridchartview::_di_IcxGridChartViewItemsProvider intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridchartview::IcxGridChartViewItemsProvider*(void) { return (Cxgridchartview::IcxGridChartViewItemsProvider*)&__IcxGridChartViewItemsProvider; }
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


class DELPHICLASS TcxGridDBChartItemDataBinding;
class PASCALIMPLEMENTATION TcxGridDBChartItemDataBinding : public Cxgridchartview::TcxGridChartItemDataBinding
{
	typedef Cxgridchartview::TcxGridChartItemDataBinding inherited;
	
private:
	HIDESBASE TcxGridDBChartDataController* __fastcall GetDataController(void);
	Data::Db::TField* __fastcall GetField(void);
	System::UnicodeString __fastcall GetFieldName(void);
	void __fastcall SetFieldName(const System::UnicodeString Value);
	
protected:
	virtual System::UnicodeString __fastcall GetDefaultDisplayText(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall GetDefaultRepositoryItem(void);
	virtual Cxedit::TcxCustomEditDefaultValuesProviderClass __fastcall GetDefaultValuesProviderClass(void);
	virtual Cxdatastorage::TcxValueTypeClass __fastcall GetDefaultValueTypeClass(void);
	virtual void __fastcall InitDefaultValuesProvider(Cxedit::TcxCustomEditDefaultValuesProvider* ADefaultValuesProvider);
	virtual bool __fastcall IsValueTypeStored(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridDBChartDataController* DataController = {read=GetDataController};
	__property Data::Db::TField* Field = {read=GetField};
	
__published:
	__property System::UnicodeString FieldName = {read=GetFieldName, write=SetFieldName};
public:
	/* TcxGridChartItemDataBinding.Create */ inline __fastcall virtual TcxGridDBChartItemDataBinding(Cxgridchartview::TcxGridChartView* AGridView, bool AIsValue, Cxdatastorage::TcxValueTypeClass ADefaultValueTypeClass) : Cxgridchartview::TcxGridChartItemDataBinding(AGridView, AIsValue, ADefaultValueTypeClass) { }
	/* TcxGridChartItemDataBinding.Destroy */ inline __fastcall virtual ~TcxGridDBChartItemDataBinding(void) { }
	
};


class DELPHICLASS TcxGridDBChartCategories;
class PASCALIMPLEMENTATION TcxGridDBChartCategories : public Cxgridchartview::TcxGridChartCategories
{
	typedef Cxgridchartview::TcxGridChartCategories inherited;
	
private:
	HIDESBASE TcxGridDBChartItemDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(TcxGridDBChartItemDataBinding* Value);
	
__published:
	__property TcxGridDBChartItemDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxGridChartCategories.Create */ inline __fastcall virtual TcxGridDBChartCategories(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridchartview::TcxGridChartCategories(AGridView) { }
	/* TcxGridChartCategories.Destroy */ inline __fastcall virtual ~TcxGridDBChartCategories(void) { }
	
};


class DELPHICLASS TcxGridDBChartDataGroup;
class PASCALIMPLEMENTATION TcxGridDBChartDataGroup : public Cxgridchartview::TcxGridChartDataGroup
{
	typedef Cxgridchartview::TcxGridChartDataGroup inherited;
	
private:
	HIDESBASE TcxGridDBChartItemDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(TcxGridDBChartItemDataBinding* Value);
	
__published:
	__property TcxGridDBChartItemDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxGridChartItem.Create */ inline __fastcall virtual TcxGridDBChartDataGroup(System::Classes::TComponent* AOwner) : Cxgridchartview::TcxGridChartDataGroup(AOwner) { }
	/* TcxGridChartItem.Destroy */ inline __fastcall virtual ~TcxGridDBChartDataGroup(void) { }
	
};


class DELPHICLASS TcxGridDBChartSeries;
class PASCALIMPLEMENTATION TcxGridDBChartSeries : public Cxgridchartview::TcxGridChartSeries
{
	typedef Cxgridchartview::TcxGridChartSeries inherited;
	
private:
	HIDESBASE TcxGridDBChartItemDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(TcxGridDBChartItemDataBinding* Value);
	
__published:
	__property TcxGridDBChartItemDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxGridChartSeries.Create */ inline __fastcall virtual TcxGridDBChartSeries(System::Classes::TComponent* AOwner) : Cxgridchartview::TcxGridChartSeries(AOwner) { }
	/* TcxGridChartSeries.Destroy */ inline __fastcall virtual ~TcxGridDBChartSeries(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridDBChartView : public Cxgridchartview::TcxGridChartView
{
	typedef Cxgridchartview::TcxGridChartView inherited;
	
private:
	TcxGridDBChartCategories* __fastcall GetCategories(void);
	HIDESBASE TcxGridDBChartDataController* __fastcall GetDataController(void);
	HIDESBASE TcxGridDBChartDataGroup* __fastcall GetDataGroup(int Index);
	HIDESBASE TcxGridDBChartSeries* __fastcall GetSeries(int Index);
	HIDESBASE void __fastcall SetCategories(TcxGridDBChartCategories* Value);
	HIDESBASE void __fastcall SetDataController(TcxGridDBChartDataController* Value);
	HIDESBASE void __fastcall SetDataGroup(int Index, TcxGridDBChartDataGroup* Value);
	HIDESBASE void __fastcall SetSeries(int Index, TcxGridDBChartSeries* Value);
	
protected:
	virtual Cxgridchartview::TcxGridChartCategoriesClass __fastcall GetCategoriesClass(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridchartview::TcxGridChartItemDataBindingClass __fastcall GetItemDataBindingClass(void);
	Cxgridchartview::TcxGridChartItem* __fastcall FindItemByFieldName(Cxgridchartview::TcxGridChartItemClass AItemClass, const System::UnicodeString AFieldName);
	
public:
	HIDESBASE TcxGridDBChartDataGroup* __fastcall CreateDataGroup(void);
	TcxGridDBChartDataGroup* __fastcall FindDataGroupByFieldName(const System::UnicodeString AFieldName);
	virtual Cxgridchartview::TcxGridChartDataGroupClass __fastcall GetDataGroupClass(void);
	__property TcxGridDBChartDataGroup* DataGroups[int Index] = {read=GetDataGroup, write=SetDataGroup};
	HIDESBASE TcxGridDBChartSeries* __fastcall CreateSeries(void);
	TcxGridDBChartSeries* __fastcall FindSeriesByFieldName(const System::UnicodeString AFieldName);
	virtual Cxgridchartview::TcxGridChartSeriesClass __fastcall GetSeriesClass(void);
	__property TcxGridDBChartSeries* Series[int Index] = {read=GetSeries, write=SetSeries};
	
__published:
	__property TcxGridDBChartCategories* Categories = {read=GetCategories, write=SetCategories};
	__property TcxGridDBChartDataController* DataController = {read=GetDataController, write=SetDataController};
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridDBChartView(Cxcontrols::TcxControl* AControl) : Cxgridchartview::TcxGridChartView(AControl) { }
	/* TcxCustomGridView.Destroy */ inline __fastcall virtual ~TcxGridDBChartView(void) { }
	
public:
	/* TcxControlChildComponent.Create */ inline __fastcall virtual TcxGridDBChartView(System::Classes::TComponent* AOwner) : Cxgridchartview::TcxGridChartView(AOwner) { }
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridDBChartView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridchartview::TcxGridChartView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriddbchartview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDDBCHARTVIEW)
using namespace Cxgriddbchartview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriddbchartviewHPP
