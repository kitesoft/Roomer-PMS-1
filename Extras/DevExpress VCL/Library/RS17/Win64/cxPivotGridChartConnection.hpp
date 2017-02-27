// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridChartConnection.pas' rev: 24.00 (Win64)

#ifndef CxpivotgridchartconnectionHPP
#define CxpivotgridchartconnectionHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxGridChartView.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridchartconnection
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPivotGridChartCellInfo;
class PASCALIMPLEMENTATION TcxPivotGridChartCellInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Variant FValue;
	int FColumnIndex;
	int FRowIndex;
	
public:
	__fastcall TcxPivotGridChartCellInfo(const System::Variant &AValue, int AColumnIndex, int ARowIndex);
	__property int ColumnIndex = {read=FColumnIndex, nodefault};
	__property int RowIndex = {read=FRowIndex, nodefault};
	__property System::Variant Value = {read=FValue};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPivotGridChartCellInfo(void) { }
	
};


class DELPHICLASS TcxPivotGridChartCellInfosList;
class PASCALIMPLEMENTATION TcxPivotGridChartCellInfosList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TcxPivotGridChartCellInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxPivotGridChartCellInfo* __fastcall GetItem(int AIndex);
	
public:
	__property TcxPivotGridChartCellInfo* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TcxPivotGridChartCellInfosList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxPivotGridChartCellInfosList(void) { }
	
};


class DELPHICLASS TcxPivotGridChartConnectionStorage;
class PASCALIMPLEMENTATION TcxPivotGridChartConnectionStorage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxPivotGridChartCellInfosList* FCells;
	System::Classes::TStringList* FColumns;
	System::Classes::TStringList* FRows;
	System::UnicodeString __fastcall GetDataItemDisplayText(Cxcustompivotgrid::TcxPivotGridViewDataItem* ADataItem);
	Cxcustompivotgrid::TcxPivotGridViewDataItem* __fastcall GetRowDataItem(int Index);
	
public:
	__fastcall virtual TcxPivotGridChartConnectionStorage(void);
	__fastcall virtual ~TcxPivotGridChartConnectionStorage(void);
	void __fastcall AddCell(const System::Variant &AValue, Cxcustompivotgrid::TcxPivotGridViewDataItem* ARow, Cxcustompivotgrid::TcxPivotGridViewDataItem* AColumn);
	__property TcxPivotGridChartCellInfosList* Cells = {read=FCells};
	__property System::Classes::TStringList* Columns = {read=FColumns};
	__property Cxcustompivotgrid::TcxPivotGridViewDataItem* RowDataItem[int Index] = {read=GetRowDataItem};
	__property System::Classes::TStringList* Rows = {read=FRows};
};


enum TcxPivotGridChartViewSourceForCategories : unsigned char { sfcRows, sfcColumns };

enum TcxPivotGridChartViewSourceData : unsigned char { sdAllShown, sdSelected };

class DELPHICLASS TcxPivotGridChartConnection;
typedef void __fastcall (__closure *TcxPivotGridChartGetDataCellsEvent)(TcxPivotGridChartConnection* Sender, int ACol, int ARow, Cxcustompivotgrid::TcxPivotGridCrossCellSummary* ACell, bool &AUseInCalculations);

typedef void __fastcall (__closure *TcxPivotGridChartGetSeriesDisplayTextEvent)(TcxPivotGridChartConnection* Sender, Cxgridchartview::TcxGridChartSeries* ASeries, System::UnicodeString &ADisplayText);

class PASCALIMPLEMENTATION TcxPivotGridChartConnection : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	Cxgridchartview::TcxGridChartView* FGridChartView;
	TcxPivotGridChartGetDataCellsEvent FOnGetDataCells;
	TcxPivotGridChartGetSeriesDisplayTextEvent FOnGetSeriesDisplayText;
	Cxcustompivotgrid::TcxCustomPivotGrid* FPivotGrid;
	TcxPivotGridChartViewSourceData FSourceData;
	TcxPivotGridChartViewSourceForCategories FSourceForCategories;
	Cxcustompivotgrid::TcxPivotGridField* __fastcall GetDataFieldFromViewData(Cxcustompivotgrid::TcxPivotGridDataBuilder* ADataBuilder, Cxcustompivotgrid::TcxPivotGridViewDataItem* AItem);
	bool __fastcall GetDataFieldValue(Cxcustompivotgrid::TcxPivotGridViewDataItem* ACol, Cxcustompivotgrid::TcxPivotGridViewDataItem* ARow, Cxcustompivotgrid::TcxPivotGridViewData* AViewData, Cxcustompivotgrid::TcxPivotGridCrossCellSummary* ACell, System::Variant &AValue);
	bool __fastcall GetSummaryType(Cxcustompivotgrid::TcxPivotGridViewDataItem* ACol, Cxcustompivotgrid::TcxPivotGridViewDataItem* ARow, Cxcustompivotgrid::TcxPivotGridSummaryType &ASummaryType);
	System::UnicodeString __fastcall GetValidName(System::UnicodeString AName);
	void __fastcall SetGridChartView(Cxgridchartview::TcxGridChartView* AValue);
	void __fastcall SetPivodGrid(Cxcustompivotgrid::TcxCustomPivotGrid* AValue);
	void __fastcall SetSourceData(TcxPivotGridChartViewSourceData AValue);
	void __fastcall SetSourceForCategories(TcxPivotGridChartViewSourceForCategories AValue);
	
protected:
	virtual void __fastcall DoChanged(void);
	virtual bool __fastcall DoGetDataCells(int ACol, int ARow, Cxcustompivotgrid::TcxPivotGridViewData* AViewData);
	virtual System::UnicodeString __fastcall DoGetSeriesDisplayText(Cxgridchartview::TcxGridChartSeries* ASeries, const System::UnicodeString ADisplayText);
	virtual void __fastcall InitializeChart(TcxPivotGridChartConnectionStorage* AStorage, Cxgridchartview::TcxGridChartView* AGridChartView);
	bool __fastcall IsDesignMode(void);
	bool __fastcall IsTotal(int ACol, int ARow, Cxcustompivotgrid::TcxPivotGridViewData* AViewData);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall PopulateStorage(Cxcustompivotgrid::TcxPivotGridViewData* const AViewData, TcxPivotGridChartConnectionStorage* const AStorage);
	virtual void __fastcall PopulateChartView(Cxgridchartview::TcxGridChartView* AGridChartView, TcxPivotGridChartConnectionStorage* AStorage);
	void __fastcall RebuildChartSeries(Cxgridchartview::TcxGridChartView* AChartView, Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid);
	void __fastcall DataChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	void __fastcall LayoutChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	void __fastcall PivotRemoved(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	void __fastcall SelectionChanged(Cxcustompivotgrid::TcxCustomPivotGrid* Sender);
	
public:
	__fastcall virtual ~TcxPivotGridChartConnection(void);
	virtual void __fastcall Refresh(void);
	
__published:
	__property Cxgridchartview::TcxGridChartView* GridChartView = {read=FGridChartView, write=SetGridChartView};
	__property Cxcustompivotgrid::TcxCustomPivotGrid* PivotGrid = {read=FPivotGrid, write=SetPivodGrid};
	__property TcxPivotGridChartViewSourceData SourceData = {read=FSourceData, write=SetSourceData, default=0};
	__property TcxPivotGridChartViewSourceForCategories SourceForCategories = {read=FSourceForCategories, write=SetSourceForCategories, default=0};
	__property TcxPivotGridChartGetDataCellsEvent OnGetDataCells = {read=FOnGetDataCells, write=FOnGetDataCells};
	__property TcxPivotGridChartGetSeriesDisplayTextEvent OnGetSeriesDisplayText = {read=FOnGetSeriesDisplayText, write=FOnGetSeriesDisplayText};
public:
	/* TComponent.Create */ inline __fastcall virtual TcxPivotGridChartConnection(System::Classes::TComponent* AOwner) : Cxclasses::TcxCustomComponent(AOwner) { }
	
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
}	/* namespace Cxpivotgridchartconnection */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDCHARTCONNECTION)
using namespace Cxpivotgridchartconnection;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridchartconnectionHPP
