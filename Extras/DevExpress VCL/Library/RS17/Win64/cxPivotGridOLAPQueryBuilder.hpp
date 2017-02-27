// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridOLAPQueryBuilder.pas' rev: 24.00 (Win64)

#ifndef CxpivotgridolapquerybuilderHPP
#define CxpivotgridolapquerybuilderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridolapquerybuilder
{
//-- type declarations -------------------------------------------------------
enum TcxOLAPStructureMembersType : unsigned char { smtAll, smtItem, smtChildren };

class DELPHICLASS TcxOLAPDataQueryBuilder;
class PASCALIMPLEMENTATION TcxOLAPDataQueryBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	int FAxisIndex;
	Cxcustompivotgrid::TcxPivotGridFields* FFilters;
	int FVersion;
	void __fastcall ClearAxisIndex(void);
	System::UnicodeString __fastcall CreateFilterAggregates(Cxcustompivotgrid::TcxPivotGridFields* AFilters);
	System::UnicodeString __fastcall CreateFilterAggregate(Cxcustompivotgrid::TcxPivotGridOLAPField* AField);
	System::UnicodeString __fastcall CreateFilterWhereClause(Cxcustompivotgrid::TcxPivotGridFields* AFilters, System::UnicodeString AAdditionalCondition);
	void __fastcall ExcludeExpandingMembersFormFilters(System::Classes::TList* AnExpandedMembers, Cxcustompivotgrid::TcxPivotGridFields* AFilters);
	void __fastcall ExcludeField(Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxPivotGridOLAPField* AField);
	System::UnicodeString __fastcall GetAxis(void);
	int __fastcall GetCountInArea(Cxcustompivotgrid::TcxPivotGridFields* AFields, Cxcustompivotgrid::TcxPivotGridFieldArea AArea);
	System::UnicodeString __fastcall GetExpandedMembers(System::Classes::TList* AnExpandedMembers, bool AClearMember = false);
	System::UnicodeString __fastcall GetFilterSetupString(Cxcustompivotgrid::TcxPivotGridFields* AFilters);
	System::UnicodeString __fastcall GetFilterString(Cxcustompivotgrid::TcxPivotGridOLAPField* AFilter);
	System::UnicodeString __fastcall GetMeasures(Cxcustompivotgrid::TcxPivotGridFields* AMeasures, const System::UnicodeString AAdditionalString = System::UnicodeString());
	System::UnicodeString __fastcall GetMember(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, const System::UnicodeString AType);
	System::UnicodeString __fastcall GetMemberName(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, const System::UnicodeString AType);
	System::UnicodeString __fastcall GetMembers(System::Classes::TStrings* AFilter);
	System::UnicodeString __fastcall GetNamedSetName(Cxcustompivotgrid::TcxPivotGridOLAPField* AField);
	System::Classes::TList* __fastcall GetNamedSets(System::Classes::TList* AnExpandedMembers);
	System::UnicodeString __fastcall GetNamedSetsQuery(System::Classes::TList* ANamedSets);
	System::UnicodeString __fastcall GetSortOrder(Cxcustompivotgrid::TcxPivotGridOLAPField* AField);
	System::UnicodeString __fastcall GetTuple(Cxcustompivotgrid::TcxPivotGridGroupItem* ATuple, bool IncludeLastMember = true, int MembersCount = 0x0);
	bool __fastcall IsHierarchy(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, Cxcustompivotgrid::TcxPivotGridOLAPField* AParentField);
	bool __fastcall IsFiltered(Cxcustompivotgrid::TcxPivotGridOLAPField* AField);
	bool __fastcall IsOLAPVersion8(void);
	bool __fastcall IsStrongRelationshipBetweenFilterAndDimensions(Cxcustompivotgrid::TcxPivotGridFields* AFilters);
	bool __fastcall IsMultipleFilteredValues(Cxcustompivotgrid::TcxPivotGridOLAPField* AField);
	System::UnicodeString __fastcall WriteAllMembers(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, bool IncludeCalculatedMembers);
	System::UnicodeString __fastcall WriteAllMembersWithSorting(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, bool IncludeCalculatedMembers, bool IncludeTotal);
	System::UnicodeString __fastcall WriteAllMembersCore(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, bool IncludeCalculatedMembers, bool ExcludeTotal, bool AFilter = true);
	System::UnicodeString __fastcall WriteSortedMembers(Cxcustompivotgrid::TcxPivotGridOLAPField* AField, const System::UnicodeString AContent);
	System::UnicodeString __fastcall FilterPart(Cxcustompivotgrid::TcxPivotGridFields* AColumns, Cxcustompivotgrid::TcxPivotGridFields* ARows, Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxPivotGridFields* AGlobalFilters);
	System::UnicodeString __fastcall FilterPartForTotals(Cxcustompivotgrid::TcxPivotGridFields* AColumns, System::Classes::TList* AnExpandedMembers, Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxPivotGridFields* AGlobalFilters);
	System::UnicodeString __fastcall ColumnPartVersion8(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AColumns, Cxcustompivotgrid::TcxPivotGridFields* AMeasures, bool IncludeCalculatedMembers, bool IncludeTotals, const System::UnicodeString AAdditionalString = System::UnicodeString());
	System::UnicodeString __fastcall ColumnPart(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AColumns, Cxcustompivotgrid::TcxPivotGridFields* AMeasures, bool IncludeCalculatedMembers, bool IncludeTotals, bool AddWith, const System::UnicodeString AAdditionalString = System::UnicodeString());
	System::UnicodeString __fastcall SourcePart(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AFilters, System::Classes::TList* ANamedSets, const System::UnicodeString AAdditionalCondition = System::UnicodeString());
	System::UnicodeString __fastcall SourcePartWithWhereCondition(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AFilters, System::Classes::TList* ANamedSets, const System::UnicodeString AAdditionalCondition = System::UnicodeString());
	System::UnicodeString __fastcall SourcePartWithSubSelect(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AFilters, System::Classes::TList* ANamedSets, const System::UnicodeString AAdditionalCondition = System::UnicodeString());
	void __fastcall TrimTrailingComma(System::UnicodeString &AStr);
	void __fastcall TrimTrailingSequence(System::UnicodeString &AStr, const System::UnicodeString ASequence);
	System::UnicodeString __fastcall GetSortBy(Cxcustompivotgrid::TcxPivotGridOLAPField* AField);
	
public:
	__fastcall TcxOLAPDataQueryBuilder(int AVersion);
	System::UnicodeString __fastcall GetDrillDownQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridCrossCell* ACrossCell, Cxclasses::TcxObjectList* AFieldList, int ASummaryIndex, bool ReturnDefaultFields);
	System::UnicodeString __fastcall GetExpandQueryString(const System::UnicodeString ACubeName, System::Classes::TList* AnExpandedMembers, Cxcustompivotgrid::TcxPivotGridFields* AFields, Cxcustompivotgrid::TcxPivotGridFields* AMeasures, Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AOLAPType, Cxcustompivotgrid::TcxOLAPKPIType AKPIType = (Cxcustompivotgrid::TcxOLAPKPIType)(0x0), const System::UnicodeString AKPIName = System::UnicodeString(), System::Classes::TList* AFilterMembers = (System::Classes::TList*)(0x0));
	System::UnicodeString __fastcall GetKPIQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AColumns, Cxcustompivotgrid::TcxPivotGridFields* ARows, Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxOLAPKPIType AKPIType, const System::UnicodeString AKPIName);
	System::UnicodeString __fastcall GetKPITotalQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AColumns, Cxcustompivotgrid::TcxPivotGridFields* ARows, Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxOLAPKPIType AKPIType, const System::UnicodeString AKPIName);
	System::UnicodeString __fastcall GetKPITotalsQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AColumns, Cxcustompivotgrid::TcxPivotGridFields* AFilters, System::Classes::TList* AnExpandedMembers, Cxcustompivotgrid::TcxOLAPKPIType AKPIType, const System::UnicodeString AKPIName);
	int __fastcall GetMeasuresCount(Cxcustompivotgrid::TcxPivotGridFields* AMeasures, Cxcustompivotgrid::TcxPivotGridOLAPFieldType AFieldType);
	System::UnicodeString __fastcall GetMembersQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridOLAPField* AField, System::Classes::TList* AnExpandedMembers, Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxPivotGridFields* AMeasures);
	System::UnicodeString __fastcall GetParentQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridOLAPField* AField, const System::UnicodeString AMemberUniqueName);
	System::UnicodeString __fastcall GetQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AColumns, Cxcustompivotgrid::TcxPivotGridFields* ARows, Cxcustompivotgrid::TcxPivotGridFields* AMeasures, Cxcustompivotgrid::TcxPivotGridFields* AFilters);
	System::UnicodeString __fastcall GetTotalQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AFilters, Cxcustompivotgrid::TcxPivotGridFields* AMeasures);
	System::UnicodeString __fastcall GetTotalsQueryString(const System::UnicodeString ACubeName, Cxcustompivotgrid::TcxPivotGridFields* AColumns, Cxcustompivotgrid::TcxPivotGridFields* ARowFilters, System::Classes::TList* AnExpandedMembers, Cxcustompivotgrid::TcxPivotGridFields* AMeasures, Cxcustompivotgrid::TcxPivotGridFields* AFilters);
	__property int Version = {read=FVersion, write=FVersion, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxOLAPDataQueryBuilder(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpivotgridolapquerybuilder */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDOLAPQUERYBUILDER)
using namespace Cxpivotgridolapquerybuilder;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridolapquerybuilderHPP
