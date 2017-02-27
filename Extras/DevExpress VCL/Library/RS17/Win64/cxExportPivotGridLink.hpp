// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExportPivotGridLink.pas' rev: 24.00 (Win64)

#ifndef CxexportpivotgridlinkHPP
#define CxexportpivotgridlinkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexportpivotgridlink
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall cxExportPivotGridToFile(System::UnicodeString AFileName, Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid, int AExportType, bool AExpand, bool AUseNativeFormat, System::UnicodeString const *ASeparators, const int ASeparators_Size, const System::UnicodeString AFileExt);
extern PACKAGE void __fastcall cxExportPivotGridToHTML(const System::UnicodeString AFileName, Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid, bool AExpand = true, const System::UnicodeString AFileExt = L"html");
extern PACKAGE void __fastcall cxExportPivotGridToXML(const System::UnicodeString AFileName, Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid, bool AExpand = true, const System::UnicodeString AFileExt = L"xml");
extern PACKAGE void __fastcall cxExportPivotGridToExcel(const System::UnicodeString AFileName, Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid, bool AExpand = true, bool AUseNativeFormat = true, const System::UnicodeString AFileExt = L"xls");
extern PACKAGE void __fastcall cxExportPivotGridToXLSX(const System::UnicodeString AFileName, Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid, bool AExpand = true, bool AUseNativeFormat = true, const System::UnicodeString AFileExt = L"xlsx");
extern PACKAGE void __fastcall cxExportPivotGridToText(const System::UnicodeString AFileName, Cxcustompivotgrid::TcxCustomPivotGrid* APivotGrid, bool AExpand = true, const System::UnicodeString ASeparator = System::UnicodeString(), const System::UnicodeString ABeginString = System::UnicodeString(), const System::UnicodeString AEndString = System::UnicodeString(), const System::UnicodeString AFileExt = L"txt");
}	/* namespace Cxexportpivotgridlink */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXPORTPIVOTGRIDLINK)
using namespace Cxexportpivotgridlink;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexportpivotgridlinkHPP
