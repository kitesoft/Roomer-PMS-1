// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridDrillDownDataSet.pas' rev: 24.00 (Win64)

#ifndef CxpivotgriddrilldowndatasetHPP
#define CxpivotgriddrilldowndatasetHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxmdaset.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxPivotGridCustomDataSet.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgriddrilldowndataset
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxCustomPivotGridDrillDownDataSet;
class PASCALIMPLEMENTATION TcxCustomPivotGridDrillDownDataSet : public Cxpivotgridcustomdataset::TcxPivotGridCustomDataSet
{
	typedef Cxpivotgridcustomdataset::TcxPivotGridCustomDataSet inherited;
	
private:
	Cxcustompivotgrid::TcxPivotGridCrossCellDataSource* FDrillDownDatasource;
	
protected:
	virtual void __fastcall SelectionChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	virtual void __fastcall DoAssignFieldProperties(Data::Db::TField* AField, Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	virtual void __fastcall DoCreateData(void);
	virtual void __fastcall DoCreateFields(void);
	virtual void __fastcall DoPopulate(void);
public:
	/* TcxPivotGridCustomDataSet.Create */ inline __fastcall virtual TcxCustomPivotGridDrillDownDataSet(System::Classes::TComponent* AOwner) : Cxpivotgridcustomdataset::TcxPivotGridCustomDataSet(AOwner) { }
	/* TcxPivotGridCustomDataSet.Destroy */ inline __fastcall virtual ~TcxCustomPivotGridDrillDownDataSet(void) { }
	
};


class DELPHICLASS TcxPivotGridDrillDownDataSet;
class PASCALIMPLEMENTATION TcxPivotGridDrillDownDataSet : public TcxCustomPivotGridDrillDownDataSet
{
	typedef TcxCustomPivotGridDrillDownDataSet inherited;
	
__published:
	__property PivotGrid;
	__property SynchronizeData = {default=0};
	__property OnCreateField;
	__property OnDataChanged;
public:
	/* TcxPivotGridCustomDataSet.Create */ inline __fastcall virtual TcxPivotGridDrillDownDataSet(System::Classes::TComponent* AOwner) : TcxCustomPivotGridDrillDownDataSet(AOwner) { }
	/* TcxPivotGridCustomDataSet.Destroy */ inline __fastcall virtual ~TcxPivotGridDrillDownDataSet(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpivotgriddrilldowndataset */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDDRILLDOWNDATASET)
using namespace Cxpivotgriddrilldowndataset;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgriddrilldowndatasetHPP
