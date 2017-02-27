// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeConsts.pas' rev: 24.00 (Win32)

#ifndef DxservermodeconstsHPP
#define DxservermodeconstsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodeconsts
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
#define sdxMissingConnection L"The Connection property is not specified"
#define sdxMissingTableName L"The TableName property is not specified"
#define sdxMissingSQL L"The SQL property is not specified"
#define sdxMissingSQLAdapter L"The SQLAdapter property is not specified"
#define sdxPrimaryKeysNotFound L"Primary keys cannot be found. Specify the KeyFieldNames pr"\
	L"operty"
#define sdxDataSourceOpen L"Cannot perform this operation on an open data source"
#define sdxInternalErrorKeyAbsentFetchRowsAll L"internal error: key is absent after successful FetchRowsAl"\
	L"l"
#define sdxInternalErrorKeyAbsentFetchRowsTop L"internal error: key is absent after successful FetchRowsTo"\
	L"p"
#define sdxInternalErrorKeyAbsentDoFetchKeys L"internal error: key is absent after successful DoFetchKeys"
#define sdxInternalErrorResultValueNotFound L"internal error: (row cannot be found by index)"
#define sdxInternalErrorTakeLessFetchCount L"internal error: (APureTake(%d) < AFetchCount(%d)) (AGroupI"\
	L"nfo.ChildDataRowCount = %d)"
#define sdxInternalErrorTakeGreaterChildDataRowCount L"internal error: (APureTake(%d) > AGroupInfo.ChildDataRowCo"\
	L"unt(%d))"
#define sdxInternalErrorSkipAndTakeWereNotChosen L"internal error: neither skip nor take were chosen"
#define sdxInternalErrorDoubleResult L"internal error: (rowindex is duplicated)"
#define sdxInconsistencyWrongNestedGroupsRowCount L"The total row count of nested groups (%d) does not equal t"\
	L"o the row count in a parent group (%d)."
#define sdxInconsistencyKeyFoundTwice L"Key '%s' found twice at indices '%s' and '%d'"
#define sdxInconsistencyWrongRowCountOfKeys L"The number of returned rows (%d) does not equal the number"\
	L" of row keys in the query (%d)"
#define sdxInconsistencyCantFindKeyInCompletelyFetchedGroup L"Can't find key '%s' in the completely fetched group"
#define sdxInconsistencyCantFindKeyInNewlyFetchedGroup L"Can't find key '%s' in the newly fetched group"
#define sdxInconsistencyUnexpectedNumberOfRows L"Unexpected number of rows returned: %d. Expected: %d"
#define sdxInconsistencyWrongKeyByRowIndex L"Key '%s' of the row fetched at index %d does not match pre"\
	L"viously fetched key '%s' for the same index"
#define sdxInconsistencyCantFindAppropriateGroupForKey L"Can't find appropriate group for row with key '%s'"
#define sdxInconsistencyCantFindAppropriateGroupForRow L"Can't find an appropriate group for row %d"
#define sdxInconsistencyUnexpectedNumberOfKeys L"Unexpected number of returned keys: %d. Expected: %d"
#define sdxInconsistencyWrongKeyByIndex L"Key '%s' fetched at index %d does not match previously fet"\
	L"ched key '%s' for the same index"
#define sdxInconsistencyWrongFetchedRow L"Row with key '%s' fetched which was not queried. May be in"\
	L"ternal error or unsupported key design"
}	/* namespace Dxservermodeconsts */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODECONSTS)
using namespace Dxservermodeconsts;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodeconstsHPP
