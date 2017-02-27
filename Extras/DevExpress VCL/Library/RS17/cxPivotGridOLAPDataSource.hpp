// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridOLAPDataSource.pas' rev: 24.00 (Win32)

#ifndef CxpivotgridolapdatasourceHPP
#define CxpivotgridolapdatasourceHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Data.Win.ADODB.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <cxPivotGridOLAPQueryBuilder.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxPivotGridStrs.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridolapdatasource
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPivotGridOLAPDrillDownDataSource;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridOLAPDrillDownDataSource : public Cxcustompivotgrid::TcxPivotGridCrossCellDataSource
{
	typedef Cxcustompivotgrid::TcxPivotGridCrossCellDataSource inherited;
	
private:
	bool __fastcall IsUniqueNamesEqual(System::UnicodeString APivotFieldName, System::UnicodeString ADrillDownName, int &ACoincidenceCount);
	
protected:
	Data::Win::Adodb::TADODataSet* FDataSet;
	System::Classes::TList* FDataSetFields;
	System::Classes::TList* FPivotGridFields;
	virtual int __fastcall GetFieldCount(void);
	virtual Cxcustompivotgrid::TcxPivotGridField* __fastcall GetPivotGridField(int AIndex);
	virtual int __fastcall GetRecordCount(void);
	virtual System::Variant __fastcall GetValue(void * ARecordHandle, void * AItemHandle);
	
public:
	__fastcall virtual ~TcxPivotGridOLAPDrillDownDataSource(void);
public:
	/* TcxPivotGridCrossCellDataSource.Create */ inline __fastcall virtual TcxPivotGridOLAPDrillDownDataSource(Cxcustompivotgrid::TcxPivotGridCrossCell* ACell) : Cxcustompivotgrid::TcxPivotGridCrossCellDataSource(ACell) { }
	/* TcxPivotGridCrossCellDataSource.CreateEx */ inline __fastcall virtual TcxPivotGridOLAPDrillDownDataSource(System::Classes::TList* ACrossCells) : Cxcustompivotgrid::TcxPivotGridCrossCellDataSource(ACrossCells) { }
	
};

#pragma pack(pop)

typedef void * __fastcall (__closure *TcxPivotGridAddOLAPStructureItemProc)(void * AParent, const System::UnicodeString ACaption, const int ANameIndex, const int AImageIndex);

class DELPHICLASS TcxPivotGridOLAPDataSource;
class PASCALIMPLEMENTATION TcxPivotGridOLAPDataSource : public Cxcustompivotgrid::TcxPivotGridCustomOLAPDataSource
{
	typedef Cxcustompivotgrid::TcxPivotGridCustomOLAPDataSource inherited;
	
private:
	System::UnicodeString FCachedFileName;
	bool FCacheLocalCubes;
	Data::Win::Adodb::TADOConnection* FConnection;
	System::WideString FConnectionString;
	System::UnicodeString FCube;
	System::Classes::TStringList* FCubes;
	bool FIsCubeNameAssigned;
	bool FTerminated;
	int FVersion;
	Cxpivotgridolapquerybuilder::TcxOLAPDataQueryBuilder* FQueryBuilder;
	void __fastcall CreateQueryBuilder(void);
	void __fastcall ExpandedItemWithParentsToList(System::Classes::TList* AnItems, System::Classes::TList* AList, bool AWithParents = true)/* overload */;
	void __fastcall ExpandedItemWithParentsToList(Cxcustompivotgrid::TcxPivotGridGroupItem* AnItem, System::Classes::TList* AList, bool AWithParents = true)/* overload */;
	System::UnicodeString __fastcall ExtractMemberName(System::UnicodeString AFullName);
	bool __fastcall GetActive(void);
	System::UnicodeString __fastcall GetDrillDownCommandText(Cxcustompivotgrid::TcxPivotGridCrossCell* ACell, Cxclasses::TcxObjectList* AFieldList, int ASummaryIndex);
	System::WideString __fastcall GetConnectionString(void);
	int __fastcall GetDataFieldCount(Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AOLAPType);
	bool __fastcall IsDataValid(void);
	bool __fastcall IsOLAPVersion8(void);
	HIDESBASE void __fastcall SetActive(bool AValue);
	void __fastcall SetConnectionString(const System::WideString AValue);
	void __fastcall SetCube(const System::UnicodeString AValue);
	
protected:
	Data::Win::Adodb::TADODataSet* FADODataSet;
	bool FIsLocalCube;
	void __fastcall AddDimensions(void);
	void __fastcall AddLevels(System::Classes::TStringList* ALevels);
	void __fastcall AddMeasures(void);
	void __fastcall AddKPIs(void);
	void __fastcall AddSETs(void);
	bool __fastcall CheckCubeName(void);
	Cxcustompivotgrid::TcxPivotGridOLAPStructureNode* __fastcall CreateNode(Cxcustompivotgrid::TcxPivotGridOLAPStructureNode* AParent, const System::UnicodeString ACaption, Cxcustompivotgrid::TcxOLAPStructureNodeType ANodeType);
	virtual void __fastcall CreateStructure(void);
	void __fastcall CreateTemporaryCube(void);
	void __fastcall DeleteCachedFile(void);
	System::UnicodeString __fastcall GetLastNameFromPath(const System::UnicodeString APath);
	System::UnicodeString __fastcall GetPathItem(System::UnicodeString &APath);
	Data::Win::Adodb::TADODataSet* __fastcall CreateDrillDownDataSet(System::Classes::TList* ACells, Cxclasses::TcxObjectList* AFieldList, int ASummaryIndex);
	virtual Cxcustompivotgrid::TcxPivotGridCrossCellDataSource* __fastcall CreateDrillDownDataSource(System::Classes::TList* ACells, Cxclasses::TcxObjectList* AFieldList, int ASummaryIndex)/* overload */;
	virtual void __fastcall CreateMembers(Cxcustompivotgrid::TcxPivotGridField* AField, Cxcustompivotgrid::TcxPivotGridGroupItem* AParent, bool AHasChildren, Cxcustompivotgrid::TcxPivotGridFields* ADataFields);
	bool __fastcall ExecuteQuery(System::WideString AQuery);
	void __fastcall ExtractProviderVersion(const System::UnicodeString AVersion);
	bool __fastcall OpenSchema(const System::UnicodeString ASchemaType);
	virtual bool __fastcall GetIsActive(void);
	virtual bool __fastcall GetIsTerminated(void);
	System::UnicodeString __fastcall GetMeasureName(System::UnicodeString AFullName);
	Cxcustompivotgrid::TcxPivotGridFields* __fastcall GetNonExpandedFields(Cxcustompivotgrid::TcxPivotGridDataBuilder* ADataBuilder, Cxcustompivotgrid::TcxPivotGridGroupItem* AnExpandingItem, Cxcustompivotgrid::TcxPivotGridGroupItem* AnItem, System::Classes::TList* ACrossGroupItems, bool AddHierarchyField);
	int __fastcall GetFieldIndex(Cxcustompivotgrid::TcxPivotGridField* AField, int AStartIndex)/* overload */;
	int __fastcall GetFieldIndex(Cxcustompivotgrid::TcxPivotGridField* AField, int AStartIndex, /* out */ System::UnicodeString &ALevelUniqueName)/* overload */;
	System::UnicodeString __fastcall GetRowID(int &AExpandingFieldIndex, Cxcustompivotgrid::TcxPivotGridField* ARowField);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializeCrossCells(Cxcustompivotgrid::TcxPivotGridGroupItem* ARowsGroup, Cxcustompivotgrid::TcxPivotGridGroupItem* AColumnsGroup, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AOLAPType);
	void __fastcall InitializeCrossCellsKPI(Cxcustompivotgrid::TcxPivotGridGroupItem* ARowsGroup, Cxcustompivotgrid::TcxPivotGridGroupItem* AColumnsGroup, Cxcustompivotgrid::TcxPivotGridField* ARowField, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AOLAPType, int AFieldIndex, int AExpandingFieldIndex);
	void __fastcall InitializeKPITotal(Cxcustompivotgrid::TcxPivotGridGroupItem* AColumnsGroup, Cxcustompivotgrid::TcxPivotGridGroupItem* ARowsGroup, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AOLAPType, int AFieldIndex);
	void __fastcall InitializeKPITotals(Cxcustompivotgrid::TcxPivotGridGroupItem* AColumnsGroup, Cxcustompivotgrid::TcxPivotGridGroupItem* ARowsGroup, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AOLAPType, int AFieldIndex);
	virtual void __fastcall InitializeExpanding(Cxcustompivotgrid::TcxPivotGridDataBuilder* ADataBuilder, Cxcustompivotgrid::TcxPivotGridField* AField, Cxcustompivotgrid::TcxPivotGridGroupItem* AnExpandingItem, Cxcustompivotgrid::TcxPivotGridGroupItem* ACrossGroup, Cxcustompivotgrid::TcxPivotGridFields* ADataFields);
	virtual void __fastcall InitializeLayoutKPI(Cxcustompivotgrid::TcxPivotGridFields* ARowFields, Cxcustompivotgrid::TcxPivotGridFields* AColumnFields, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridFields* AFilterFields, Cxcustompivotgrid::TcxPivotGridGroupItem* ARowsGroup, Cxcustompivotgrid::TcxPivotGridGroupItem* AColumnsGroup);
	virtual void __fastcall InitializeTotal(Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridFields* AFilterFields, Cxcustompivotgrid::TcxPivotGridGroupItem* AColumns, Cxcustompivotgrid::TcxPivotGridGroupItem* ARows);
	virtual void __fastcall CreateLayoutTotals(Cxcustompivotgrid::TcxPivotGridGroupItem* AColumns, Cxcustompivotgrid::TcxPivotGridGroupItem* ARows, Cxcustompivotgrid::TcxPivotGridFields* ASummaryFields, System::Classes::TList* AnExpandedMembers);
	bool __fastcall IsValueVisible(Cxcustompivotgrid::TcxPivotGridFieldFilter* AFilter, const System::WideString AValue);
	virtual void __fastcall InitializeStructureMembers(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, Cxcustompivotgrid::TcxPivotGridVariantList* AList);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall PopulateFilteredUniqueNames(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, Cxcustompivotgrid::TcxPivotGridFieldFilter* AFilter, System::Classes::TStringList* &AUniqueValues);
	virtual void __fastcall PopulateFilteredValues(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, Cxcustompivotgrid::TcxPivotGridFieldFilter* AFilter, System::Classes::TStrings* AValues, System::Classes::TStringList* AUniqueValues);
	void __fastcall ProcessColumns(Cxcustompivotgrid::TcxPivotGridGroupItem* AColumnsGroup, Cxcustompivotgrid::TcxPivotGridGroupItem* ARow, int AFieldIndex);
	void __fastcall ProcessDataField(Cxcustompivotgrid::TcxPivotGridGroupItem* AColumn, Cxcustompivotgrid::TcxPivotGridGroupItem* ARow, int AFieldIndex, int ASummaryFieldIndex);
	void __fastcall ProcessDataFields(Cxcustompivotgrid::TcxPivotGridGroupItem* AColumn, Cxcustompivotgrid::TcxPivotGridGroupItem* ARow, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, int AFieldIndex, const System::UnicodeString AFieldDimension, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AOLAPType, /* out */ int &AProcessedFieldCount);
	void __fastcall ProcessDataFieldsEx(Cxcustompivotgrid::TcxPivotGridGroupItem* AColumn, Cxcustompivotgrid::TcxPivotGridGroupItem* ARow, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, int ARecordIndex, int AStartColumnIndex, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AOLAPType);
	virtual void __fastcall QueryLayout(Cxcustompivotgrid::TcxPivotGridFields* ARowFields, Cxcustompivotgrid::TcxPivotGridFields* AColumnFields, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridFields* AFilterFields);
	virtual void __fastcall QueryLayoutTotals(Cxcustompivotgrid::TcxPivotGridFields* AColumnFields, Cxcustompivotgrid::TcxPivotGridFields* ARowFields, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, Cxcustompivotgrid::TcxPivotGridFields* AFilterFields, System::Classes::TList* AnExpandedMembers);
	void __fastcall QueryKPIExpandCrossCells(Cxcustompivotgrid::TcxPivotGridDataBuilder* ADataBuilder, System::Classes::TList* AMembers, Cxcustompivotgrid::TcxPivotGridFields* AFields, Cxcustompivotgrid::TcxPivotGridFields* ADataFields, int ADataFieldIndex);
	bool __fastcall QueryKPILayout(Cxcustompivotgrid::TcxPivotGridFields* AColumnFields, Cxcustompivotgrid::TcxPivotGridFields* ARowFields, Cxcustompivotgrid::TcxPivotGridFields* AFilterFields, Cxcustompivotgrid::TcxPivotGridOLAPField* ADataField, Cxcustompivotgrid::TcxOLAPKPIType AOLAPType);
	bool __fastcall QueryKPITotal(Cxcustompivotgrid::TcxPivotGridFields* AFilterFields, Cxcustompivotgrid::TcxPivotGridFields* AColumnFields, Cxcustompivotgrid::TcxPivotGridFields* ARowFields, Cxcustompivotgrid::TcxPivotGridOLAPField* ADataField, Cxcustompivotgrid::TcxOLAPKPIType AKPIType);
	bool __fastcall QueryKPITotals(Cxcustompivotgrid::TcxPivotGridFields* AColumnFields, Cxcustompivotgrid::TcxPivotGridFields* AFilterFields, Cxcustompivotgrid::TcxPivotGridOLAPField* ADataField, Cxcustompivotgrid::TcxOLAPKPIType AKPIType, System::Classes::TList* AnExpandedMembers);
	virtual void __fastcall QueryRootMembers(Cxcustompivotgrid::TcxPivotGridField* AField, System::Classes::TList* AParentMembers, Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxPivotGridFields* ADataFields);
	bool __fastcall SeparateDimensionAndMeasure(System::UnicodeString AValue, /* out */ System::UnicodeString &ADimension, /* out */ System::UnicodeString &AMeasure);
	void __fastcall TerminateConnection(void);
	__property bool IsCubeNameAssigned = {read=FIsCubeNameAssigned, write=FIsCubeNameAssigned, nodefault};
	__property Cxpivotgridolapquerybuilder::TcxOLAPDataQueryBuilder* QueryBuilder = {read=FQueryBuilder, write=FQueryBuilder};
	__property int Version = {read=FVersion, nodefault};
	
public:
	__fastcall virtual TcxPivotGridOLAPDataSource(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxPivotGridOLAPDataSource(void);
	__property Data::Win::Adodb::TADOConnection* Connection = {read=FConnection};
	__property Data::Win::Adodb::TADODataSet* ADODataSet = {read=FADODataSet};
	__property System::Classes::TStringList* Cubes = {read=FCubes};
	
__published:
	__property bool CacheLocalCubes = {read=FCacheLocalCubes, write=FCacheLocalCubes, nodefault};
	__property System::WideString ConnectionString = {read=GetConnectionString, write=SetConnectionString};
	__property System::UnicodeString Cube = {read=FCube, write=SetCube, stored=FIsCubeNameAssigned};
	__property bool Active = {read=GetActive, write=SetActive, nodefault};
	__property OnInitializeField;
/* Hoisted overloads: */
	
protected:
	inline Cxcustompivotgrid::TcxPivotGridCrossCellDataSource* __fastcall  CreateDrillDownDataSource(Cxcustompivotgrid::TcxPivotGridCrossCell* ACell, Cxclasses::TcxObjectList* FieldList, int ASummaryIndex){ return Cxcustompivotgrid::TcxPivotGridCustomOLAPDataSource::CreateDrillDownDataSource(ACell, FieldList, ASummaryIndex); }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpivotgridolapdatasource */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDOLAPDATASOURCE)
using namespace Cxpivotgridolapdatasource;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridolapdatasourceHPP
