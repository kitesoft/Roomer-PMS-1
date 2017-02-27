// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridCustomDataSet.pas' rev: 24.00 (Win64)

#ifndef CxpivotgridcustomdatasetHPP
#define CxpivotgridcustomdatasetHPP

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
#include <cxDBPivotGrid.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridcustomdataset
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPivotGridCustomDataSet;
typedef void __fastcall (__closure *TcxPivotGridDataSetFieldEvent)(TcxPivotGridCustomDataSet* Sender, Cxcustompivotgrid::TcxPivotGridField* APivotGridField, Data::Db::TField* ADataSetField);

class PASCALIMPLEMENTATION TcxPivotGridCustomDataSet : public Dxmdaset::TdxCustomMemData
{
	typedef Dxmdaset::TdxCustomMemData inherited;
	
private:
	Cxcustompivotgrid::TcxCustomPivotGrid* FPivotGrid;
	bool FSynchronizeData;
	TcxPivotGridDataSetFieldEvent FOnCreateField;
	System::Classes::TNotifyEvent FOnDataChanged;
	Cxcustompivotgrid::TcxPivotGridDataBuilder* __fastcall GetDataBuilder(void);
	Cxcustompivotgrid::TcxCustomPivotGrid* __fastcall GetPivotGrid(void);
	void __fastcall SetPivotGrid(Cxcustompivotgrid::TcxCustomPivotGrid* Value);
	void __fastcall SetSynchronizeData(bool Value);
	
protected:
	bool __fastcall IsDBFieldAssigned(Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	Data::Db::TField* __fastcall GetDBField(Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	virtual void __fastcall DataChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	virtual void __fastcall LayoutChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	virtual void __fastcall PivotRemoved(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	virtual void __fastcall SelectionChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	Data::Db::TFieldType __fastcall GetDefaultFieldType(Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	virtual Data::Db::TFieldType __fastcall GetFieldType(Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	virtual void __fastcall DoAssignFieldProperties(Data::Db::TField* AField, Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	virtual void __fastcall DoCreateData(void);
	virtual Data::Db::TField* __fastcall DoCreateField(Cxcustompivotgrid::TcxPivotGridField* APivotGridField);
	virtual void __fastcall DoCreateFields(void);
	virtual void __fastcall DoPopulate(void);
	void __fastcall ClearAll(void);
	__property Cxcustompivotgrid::TcxPivotGridDataBuilder* DataBuilder = {read=GetDataBuilder};
	__property Cxcustompivotgrid::TcxCustomPivotGrid* PivotGrid = {read=GetPivotGrid, write=SetPivotGrid};
	__property bool SynchronizeData = {read=FSynchronizeData, write=SetSynchronizeData, default=0};
	__property TcxPivotGridDataSetFieldEvent OnCreateField = {read=FOnCreateField, write=FOnCreateField};
	__property System::Classes::TNotifyEvent OnDataChanged = {read=FOnDataChanged, write=FOnDataChanged};
	
public:
	__fastcall virtual TcxPivotGridCustomDataSet(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxPivotGridCustomDataSet(void);
	void __fastcall CreateData(void);
private:
	void *__IcxPivotGridListener;	/* Cxcustompivotgrid::IcxPivotGridListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {34D8F0E7-C4E2-4F82-A85E-6EE378E7E8FA}
	operator Cxcustompivotgrid::_di_IcxPivotGridListener()
	{
		Cxcustompivotgrid::_di_IcxPivotGridListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcustompivotgrid::IcxPivotGridListener*(void) { return (Cxcustompivotgrid::IcxPivotGridListener*)&__IcxPivotGridListener; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpivotgridcustomdataset */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDCUSTOMDATASET)
using namespace Cxpivotgridcustomdataset;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridcustomdatasetHPP
