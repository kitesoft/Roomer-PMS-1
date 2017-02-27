// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridServerModeBandedTableView.pas' rev: 24.00 (Win64)

#ifndef CxgridservermodebandedtableviewHPP
#define CxgridservermodebandedtableviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxGridServerModeTableView.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGridBandedTableView.hpp>	// Pascal unit
#include <cxGridServerModeDataDefinitions.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGridDBDataDefinitions.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridservermodebandedtableview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridServerModeBandedColumn;
class DELPHICLASS TcxGridServerModeBandedTableView;
class PASCALIMPLEMENTATION TcxGridServerModeBandedColumn : public Cxgridbandedtableview::TcxGridBandedColumn
{
	typedef Cxgridbandedtableview::TcxGridBandedColumn inherited;
	
private:
	Cxgridservermodedatadefinitions::TcxGridItemServerModeDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE TcxGridServerModeBandedTableView* __fastcall GetGridView(void);
	HIDESBASE void __fastcall SetDataBinding(Cxgridservermodedatadefinitions::TcxGridItemServerModeDataBinding* Value);
	
protected:
	virtual void __fastcall GetBestFitRecordRange(/* out */ int &AFirstIndex, /* out */ int &ALastIndex);
	
public:
	__property TcxGridServerModeBandedTableView* GridView = {read=GetGridView};
	
__published:
	__property Cxgridservermodedatadefinitions::TcxGridItemServerModeDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxGridBandedColumn.Destroy */ inline __fastcall virtual ~TcxGridServerModeBandedColumn(void) { }
	
public:
	/* TcxGridColumn.Create */ inline __fastcall virtual TcxGridServerModeBandedColumn(System::Classes::TComponent* AOwner) : Cxgridbandedtableview::TcxGridBandedColumn(AOwner) { }
	
};


class DELPHICLASS TcxGridServerModeBandedSummaryItem;
class PASCALIMPLEMENTATION TcxGridServerModeBandedSummaryItem : public Dxservermodedata::TdxServerModeSummaryItem
{
	typedef Dxservermodedata::TdxServerModeSummaryItem inherited;
	
private:
	System::UnicodeString FDisplayText;
	bool FVisibleForCustomization;
	TcxGridServerModeBandedColumn* __fastcall GetColumn(void);
	TcxGridServerModeBandedTableView* __fastcall GetGridView(void);
	void __fastcall SetColumn(TcxGridServerModeBandedColumn* Value);
	void __fastcall SetDisplayText(const System::UnicodeString Value);
	void __fastcall SetVisibleForCustomization(bool Value);
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	System::UnicodeString __fastcall GetObjectName(void);
	bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	System::UnicodeString __fastcall GetDisplayText(void);
	bool __fastcall GetVisibleForCustomization(void);
	__property TcxGridServerModeBandedTableView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxGridServerModeBandedSummaryItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxGridServerModeBandedColumn* Column = {read=GetColumn, write=SetColumn};
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=SetDisplayText};
	__property Sorted = {default=0};
	__property bool VisibleForCustomization = {read=FVisibleForCustomization, write=SetVisibleForCustomization, default=1};
public:
	/* TcxDataSummaryItem.Destroy */ inline __fastcall virtual ~TcxGridServerModeBandedSummaryItem(void) { }
	
private:
	void *__IcxGridSummaryItem;	/* Cxgridtableview::IcxGridSummaryItem */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6F9A0C3E-E33F-4E77-9357-82F1D19CDB67}
	operator Cxgridtableview::_di_IcxGridSummaryItem()
	{
		Cxgridtableview::_di_IcxGridSummaryItem intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridtableview::IcxGridSummaryItem*(void) { return (Cxgridtableview::IcxGridSummaryItem*)&__IcxGridSummaryItem; }
	#endif
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
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxGridSummaryItem; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxGridServerModeBandedTableView : public Cxgridbandedtableview::TcxGridBandedTableView
{
	typedef Cxgridbandedtableview::TcxGridBandedTableView inherited;
	
private:
	HIDESBASE TcxGridServerModeBandedColumn* __fastcall GetColumn(int Index);
	HIDESBASE Cxgridservermodedatadefinitions::TcxGridServerModeDataController* __fastcall GetDataController(void);
	HIDESBASE void __fastcall SetColumn(int Index, TcxGridServerModeBandedColumn* Value);
	HIDESBASE void __fastcall SetDataController(Cxgridservermodedatadefinitions::TcxGridServerModeDataController* Value);
	
protected:
	virtual bool __fastcall CanEditViewLayoutAndData(void);
	virtual bool __fastcall CanBeUsedAsDetail(void);
	virtual bool __fastcall CanBeUsedAsMaster(void);
	virtual bool __fastcall CanGetHitTest(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewDataClass __fastcall GetViewDataClass(void);
	
public:
	__fastcall virtual ~TcxGridServerModeBandedTableView(void);
	HIDESBASE TcxGridServerModeBandedColumn* __fastcall CreateColumn(void);
	TcxGridServerModeBandedColumn* __fastcall GetColumnByFieldName(const System::UnicodeString AFieldName);
	__property TcxGridServerModeBandedColumn* Columns[int Index] = {read=GetColumn, write=SetColumn};
	
__published:
	__property Cxgridservermodedatadefinitions::TcxGridServerModeDataController* DataController = {read=GetDataController, write=SetDataController};
public:
	/* TcxGridTableView.Create */ inline __fastcall virtual TcxGridServerModeBandedTableView(System::Classes::TComponent* AOwner) : Cxgridbandedtableview::TcxGridBandedTableView(AOwner) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridServerModeBandedTableView(Cxcontrols::TcxControl* AControl) : Cxgridbandedtableview::TcxGridBandedTableView(AControl) { }
	
public:
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridServerModeBandedTableView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridbandedtableview::TcxGridBandedTableView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridservermodebandedtableview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDSERVERMODEBANDEDTABLEVIEW)
using namespace Cxgridservermodebandedtableview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridservermodebandedtableviewHPP
