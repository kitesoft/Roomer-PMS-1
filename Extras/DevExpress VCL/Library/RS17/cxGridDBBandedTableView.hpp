// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridDBBandedTableView.pas' rev: 24.00 (Win32)

#ifndef CxgriddbbandedtableviewHPP
#define CxgriddbbandedtableviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDBData.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridDBDataDefinitions.hpp>	// Pascal unit
#include <cxGridBandedTableView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgriddbbandedtableview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridDBBandedColumn;
class PASCALIMPLEMENTATION TcxGridDBBandedColumn : public Cxgridbandedtableview::TcxGridBandedColumn
{
	typedef Cxgridbandedtableview::TcxGridBandedColumn inherited;
	
private:
	Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* __fastcall GetDataBinding(void);
	HIDESBASE void __fastcall SetDataBinding(Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* Value);
	
__published:
	__property Cxgriddbdatadefinitions::TcxGridItemDBDataBinding* DataBinding = {read=GetDataBinding, write=SetDataBinding};
public:
	/* TcxGridBandedColumn.Destroy */ inline __fastcall virtual ~TcxGridDBBandedColumn(void) { }
	
public:
	/* TcxGridColumn.Create */ inline __fastcall virtual TcxGridDBBandedColumn(System::Classes::TComponent* AOwner) : Cxgridbandedtableview::TcxGridBandedColumn(AOwner) { }
	
};


class DELPHICLASS TcxGridDBBandedTableView;
class PASCALIMPLEMENTATION TcxGridDBBandedTableView : public Cxgridbandedtableview::TcxGridBandedTableView
{
	typedef Cxgridbandedtableview::TcxGridBandedTableView inherited;
	
private:
	HIDESBASE TcxGridDBBandedColumn* __fastcall GetColumn(int Index);
	HIDESBASE Cxgriddbdatadefinitions::TcxGridDBDataController* __fastcall GetDataController(void);
	HIDESBASE void __fastcall SetColumn(int Index, TcxGridDBBandedColumn* Value);
	HIDESBASE void __fastcall SetDataController(Cxgriddbdatadefinitions::TcxGridDBDataController* Value);
	
protected:
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	virtual Cxcustomdata::TcxDataSummaryItemClass __fastcall GetSummaryItemClass(void);
	
public:
	HIDESBASE TcxGridDBBandedColumn* __fastcall CreateColumn(void);
	TcxGridDBBandedColumn* __fastcall GetColumnByFieldName(const System::UnicodeString AFieldName);
	__property TcxGridDBBandedColumn* Columns[int Index] = {read=GetColumn, write=SetColumn};
	
__published:
	__property Cxgriddbdatadefinitions::TcxGridDBDataController* DataController = {read=GetDataController, write=SetDataController};
public:
	/* TcxGridTableView.Create */ inline __fastcall virtual TcxGridDBBandedTableView(System::Classes::TComponent* AOwner) : Cxgridbandedtableview::TcxGridBandedTableView(AOwner) { }
	
public:
	/* TcxCustomGridTableView.Destroy */ inline __fastcall virtual ~TcxGridDBBandedTableView(void) { }
	
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridDBBandedTableView(Cxcontrols::TcxControl* AControl) : Cxgridbandedtableview::TcxGridBandedTableView(AControl) { }
	
public:
	/* TcxControlChildComponent.CreateEx */ inline __fastcall virtual TcxGridDBBandedTableView(Cxcontrols::TcxControl* AControl, bool AAssignOwner) : Cxgridbandedtableview::TcxGridBandedTableView(AControl, AAssignOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgriddbbandedtableview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDDBBANDEDTABLEVIEW)
using namespace Cxgriddbbandedtableview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgriddbbandedtableviewHPP
