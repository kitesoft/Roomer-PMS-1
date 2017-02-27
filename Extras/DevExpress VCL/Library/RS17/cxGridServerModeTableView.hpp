// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridServerModeTableView.pas' rev: 24.00 (Win32)

#ifndef CxgridservermodetableviewHPP
#define CxgridservermodetableviewHPP

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
#include <cxGridDBDataDefinitions.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxGridDBTableView.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <dxServerModeData.hpp>	// Pascal unit
#include <cxGridServerModeDataDefinitions.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridservermodetableview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridServerModeColumnOptions;
class DELPHICLASS TcxGridServerModeTableView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridServerModeColumnOptions : public Cxgridcustomtableview::TcxCustomGridTableItemOptions
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemOptions inherited;
	
private:
	bool FCellMerging;
	bool FGroupFooters;
	bool FHorzSizing;
	HIDESBASE TcxGridServerModeTableView* __fastcall GetGridView(void);
	void __fastcall SetCellMerging(bool Value);
	void __fastcall SetGroupFooters(bool Value);
	void __fastcall SetHorzSizing(bool Value);
	
protected:
	__property TcxGridServerModeTableView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxGridServerModeColumnOptions(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool CellMerging = {read=FCellMerging, write=SetCellMerging, default=0};
	__property EditAutoHeight = {default=0};
	__property bool GroupFooters = {read=FGroupFooters, write=SetGroupFooters, default=1};
	__property Grouping = {default=1};
	__property bool HorzSizing = {read=FHorzSizing, write=SetHorzSizing, default=1};
	__property Moving = {default=1};
	__property ShowCaption = {default=1};
	__property Sorting = {default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridServerModeColumnOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridServerModeColumn;
class PASCALIMPLEMENTATION TcxGridServerModeColumn : public Cxgridtableview::TcxGridColumn
{
	typedef Cxgridtableview::TcxGridColumn inherited;
	
private:
	Cxgridservermodedatadefinitions::TcxGridItemServerModeDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE TcxGridServerModeTableView* __fastcall GetGridView(void);
	HIDESBASE void __fastcall SetDataBinding(Cxgridservermodedatadefinitions::TcxGridItemServerModeDataBinding* Value);
	HIDESBASE TcxGridServerModeColumnOptions* __fastcall GetOptions(void);
	HIDESBASE void __fastcall SetOptions(TcxGridServerModeColumnOptions* const Value);
	
protected:
	virtual bool __fastcall CanCellMerging(void);
	virtual bool __fastcall CanShowGroupFooters(void);
	virtual void __fastcall GetBestFitRecordRange(/* out */ int &AFirstIndex, /* out */ int &ALastIndex);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemOptionsClass __fastcall GetOptionsClass(void);
	virtual bool __fastcall HasFixedWidth(void);
	
public:
	__property TcxGridServerModeTableView* GridView = {read=GetGridView};
	
__published:
	__property Cxgridservermodedatadefinitions::TcxGridItemServerModeDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
	__property TcxGridServerModeColumnOptions* Options = {read=GetOptions, write=SetOptions};
public:
	/* TcxGridColumn.Create */ inline __fastcall virtual TcxGridServerModeColumn(System::Classes::TComponent* AOwner) : Cxgridtableview::TcxGridColumn(AOwner) { }
	/* TcxGridColumn.Destroy */ inline __fastcall virtual ~TcxGridServerModeColumn(void) { }
	
};


class DELPHICLASS TcxGridServerModeSummaryItem;
class PASCALIMPLEMENTATION TcxGridServerModeSummaryItem : public Dxservermodedata::TdxServerModeSummaryItem
{
	typedef Dxservermodedata::TdxServerModeSummaryItem inherited;
	
private:
	System::UnicodeString FDisplayText;
	bool FVisibleForCustomization;
	TcxGridServerModeColumn* __fastcall GetColumn(void);
	TcxGridServerModeTableView* __fastcall GetGridView(void);
	void __fastcall SetColumn(TcxGridServerModeColumn* Value);
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
	__property TcxGridServerModeTableView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxGridServerModeSummaryItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TcxGridServerModeColumn* Column = {read=GetColumn, write=SetColumn};
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=SetDisplayText};
	__property Sorted = {default=0};
	__property bool VisibleForCustomization = {read=FVisibleForCustomization, write=SetVisibleForCustomization, default=1};
public:
	/* TcxDataSummaryItem.Destroy */ inline __fastcall virtual ~TcxGridServerModeSummaryItem(void) { }
	
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


class DELPHICLASS TcxGridServerModeGroupRow;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridServerModeGroupRow : public Cxgridtableview::TcxGridGroupRow
{
	typedef Cxgridtableview::TcxGridGroupRow inherited;
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayText(int Index);
public:
	/* TcxCustomGridRecord.Create */ inline __fastcall virtual TcxGridServerModeGroupRow(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo) : Cxgridtableview::TcxGridGroupRow(AViewData, AIndex, ARecordInfo) { }
	/* TcxCustomGridRecord.Destroy */ inline __fastcall virtual ~TcxGridServerModeGroupRow(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridServerModeViewData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridServerModeViewData : public Cxgridtableview::TcxGridViewData
{
	typedef Cxgridtableview::TcxGridViewData inherited;
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetGroupRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo);
public:
	/* TcxGridViewData.Destroy */ inline __fastcall virtual ~TcxGridServerModeViewData(void) { }
	
public:
	/* TcxCustomGridTableViewData.Create */ inline __fastcall virtual TcxGridServerModeViewData(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridtableview::TcxGridViewData(AGridView) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxGridServerModeTableView : public Cxgridtableview::TcxGridTableView
{
	typedef Cxgridtableview::TcxGridTableView inherited;
	
private:
	HIDESBASE TcxGridServerModeColumn* __fastcall GetColumn(int Index);
	HIDESBASE Cxgridservermodedatadefinitions::TcxGridServerModeDataController* __fastcall GetDataController(void);
	HIDESBASE void __fastcall SetColumn(int Index, TcxGridServerModeColumn* Value);
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
	__fastcall virtual ~TcxGridServerModeTableView(void);
	HIDESBASE TcxGridServerModeColumn* __fastcall CreateColumn(void);
	TcxGridServerModeColumn* __fastcall GetColumnByFieldName(const System::UnicodeString AFieldName);
	__property TcxGridServerModeColumn* Columns[int Index] = {read=GetColumn, write=SetColumn};
	
__published:
	__property Cxgridservermodedatadefinitions::TcxGridServerModeDataController* DataController = {read=GetDataController, write=SetDataController};
public:
	/* TcxGridTableView.Create */ inline __fastcall virtual TcxGridServerModeTableView(System::Classes::TComponent* AOwner) : Cxgridtableview::TcxGridTableView(AOwner) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridServerModeTableView(Cxcontrols::TcxControl* AControl) : Cxgridtableview::TcxGridTableView(AControl) { }
	
public:
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridServerModeTableView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridtableview::TcxGridTableView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridservermodetableview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDSERVERMODETABLEVIEW)
using namespace Cxgridservermodetableview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridservermodetableviewHPP
