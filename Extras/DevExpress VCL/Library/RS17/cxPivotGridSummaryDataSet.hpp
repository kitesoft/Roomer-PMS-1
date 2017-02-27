// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridSummaryDataSet.pas' rev: 24.00 (Win32)

#ifndef CxpivotgridsummarydatasetHPP
#define CxpivotgridsummarydatasetHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxmdaset.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxPivotGridCustomDataSet.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridsummarydataset
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomPivotGridSummaryDataSet;
class PASCALIMPLEMENTATION TcxCustomPivotGridSummaryDataSet : public Cxpivotgridcustomdataset::TcxPivotGridCustomDataSet
{
	typedef Cxpivotgridcustomdataset::TcxPivotGridCustomDataSet inherited;
	
protected:
	virtual Data::Db::TFieldType __fastcall GetFieldType(Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	virtual void __fastcall DataChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	virtual void __fastcall LayoutChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	virtual Data::Db::TField* __fastcall DoCreateField(Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	virtual void __fastcall DoCreateFields(void);
	virtual void __fastcall DoPopulate(void);
public:
	/* TcxPivotGridCustomDataSet.Create */ inline __fastcall virtual TcxCustomPivotGridSummaryDataSet(System::Classes::TComponent* AOwner) : Cxpivotgridcustomdataset::TcxPivotGridCustomDataSet(AOwner) { }
	/* TcxPivotGridCustomDataSet.Destroy */ inline __fastcall virtual ~TcxCustomPivotGridSummaryDataSet(void) { }
	
};


class DELPHICLASS TcxPivotGridSummaryDataSet;
class PASCALIMPLEMENTATION TcxPivotGridSummaryDataSet : public TcxCustomPivotGridSummaryDataSet
{
	typedef TcxCustomPivotGridSummaryDataSet inherited;
	
__published:
	__property PivotGrid;
	__property SynchronizeData = {default=0};
	__property OnCreateField;
	__property OnDataChanged;
public:
	/* TcxPivotGridCustomDataSet.Create */ inline __fastcall virtual TcxPivotGridSummaryDataSet(System::Classes::TComponent* AOwner) : TcxCustomPivotGridSummaryDataSet(AOwner) { }
	/* TcxPivotGridCustomDataSet.Destroy */ inline __fastcall virtual ~TcxPivotGridSummaryDataSet(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpivotgridsummarydataset */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDSUMMARYDATASET)
using namespace Cxpivotgridsummarydataset;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridsummarydatasetHPP
