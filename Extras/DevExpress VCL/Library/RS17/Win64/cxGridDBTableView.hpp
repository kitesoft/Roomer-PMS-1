// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridDBTableView.pas' rev: 24.00 (Win64)

#ifndef CxgriddbtableviewHPP
#define CxgriddbtableviewHPP

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
#include <cxClasses.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriddbtableview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridDBColumn;
class PASCALIMPLEMENTATION TcxGridDBColumn : public Cxgridtableview::TcxGridColumn
{
	typedef Cxgridtableview::TcxGridColumn inherited;
	
private:
	Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* Value);
	
__published:
	__property Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxGridColumn.Create */ inline __fastcall virtual TcxGridDBColumn(System::Classes::TComponent* AOwner) : Cxgridtableview::TcxGridColumn(AOwner) { }
	/* TcxGridColumn.Destroy */ inline __fastcall virtual ~TcxGridDBColumn(void) { }
	
};


class DELPHICLASS TcxGridDBTableSummaryItem;
class PASCALIMPLEMENTATION TcxGridDBTableSummaryItem : public Cxdbdata::TcxDBDataSummaryItem
{
	typedef Cxdbdata::TcxDBDataSummaryItem inherited;
	
private:
	System::UnicodeString FDisplayText;
	bool FVisibleForCustomization;
	Cxgridtableview::TcxGridColumn* __fastcall GetColumn(void);
	Cxgridtableview::TcxGridTableView* __fastcall GetGridView(void);
	void __fastcall SetColumn(Cxgridtableview::TcxGridColumn* Value);
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
	__property Cxgridtableview::TcxGridTableView* GridView = {read=GetGridView};
	
public:
	__fastcall virtual TcxGridDBTableSummaryItem(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Cxgridtableview::TcxGridColumn* Column = {read=GetColumn, write=SetColumn};
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=SetDisplayText};
	__property Sorted = {default=0};
	__property bool VisibleForCustomization = {read=FVisibleForCustomization, write=SetVisibleForCustomization, default=1};
public:
	/* TcxDataSummaryItem.Destroy */ inline __fastcall virtual ~TcxGridDBTableSummaryItem(void) { }
	
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


class DELPHICLASS TcxGridDBTableView;
class PASCALIMPLEMENTATION TcxGridDBTableView : public Cxgridtableview::TcxGridTableView
{
	typedef Cxgridtableview::TcxGridTableView inherited;
	
private:
	HIDESBASE TcxGridDBColumn* __fastcall GetColumn(int Index);
	HIDESBASE Cxgriddbdatadefinitions::TcxGridDBDataController* __fastcall GetDataController(void);
	HIDESBASE void __fastcall SetColumn(int Index, TcxGridDBColumn* Value);
	HIDESBASE void __fastcall SetDataController(Cxgriddbdatadefinitions::TcxGridDBDataController* Value);
	
protected:
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	
public:
	HIDESBASE TcxGridDBColumn* __fastcall CreateColumn(void);
	TcxGridDBColumn* __fastcall GetColumnByFieldName(const System::UnicodeString AFieldName);
	__property TcxGridDBColumn* Columns[int Index] = {read=GetColumn, write=SetColumn};
	
__published:
	__property Cxgriddbdatadefinitions::TcxGridDBDataController* DataController = {read=GetDataController, write=SetDataController};
public:
	/* TcxGridTableView.Create */ inline __fastcall virtual TcxGridDBTableView(System::Classes::TComponent* AOwner) : Cxgridtableview::TcxGridTableView(AOwner) { }
	
public:
	/* TcxCustomGridTableView.Destroy */ inline __fastcall virtual ~TcxGridDBTableView(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridDBTableView(Cxcontrols::TcxControl* AControl) : Cxgridtableview::TcxGridTableView(AControl) { }
	
public:
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridDBTableView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridtableview::TcxGridTableView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriddbtableview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDDBTABLEVIEW)
using namespace Cxgriddbtableview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriddbtableviewHPP
