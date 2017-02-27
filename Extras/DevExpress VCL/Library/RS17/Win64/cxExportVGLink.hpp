// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExportVGLink.pas' rev: 24.00 (Win64)

#ifndef CxexportvglinkHPP
#define CxexportvglinkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexportvglink
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall cxExportVGToFile(System::UnicodeString AFileName, Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid, int AExportType, bool AExpand, bool AUseNativeFormat, System::UnicodeString const *ASeparators, const int ASeparators_Size, int ARecordPerBand, const System::UnicodeString AFileExt);
extern PACKAGE void __fastcall cxExportVGToHTML(const System::UnicodeString AFileName, Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid, bool AExpand = true, int ARecordPerBand = 0x8, const System::UnicodeString AFileExt = L"html");
extern PACKAGE void __fastcall cxExportVGToXML(const System::UnicodeString AFileName, Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid, bool AExpand = true, int ARecordPerBand = 0x8, const System::UnicodeString AFileExt = L"xml");
extern PACKAGE void __fastcall cxExportVGToExcel(const System::UnicodeString AFileName, Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid, bool AExpand = true, bool AUseNativeFormat = true, int ARecordPerBand = 0x8, const System::UnicodeString AFileExt = L"xls");
extern PACKAGE void __fastcall cxExportVGToXLSX(const System::UnicodeString AFileName, Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid, bool AExpand = true, bool AUseNativeFormat = true, int ARecordPerBand = 0x8, const System::UnicodeString AFileExt = L"xlsx");
extern PACKAGE void __fastcall cxExportVGToText(const System::UnicodeString AFileName, Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid, bool AExpand = true, const System::UnicodeString ASeparator = System::UnicodeString(), const System::UnicodeString ABeginString = System::UnicodeString(), const System::UnicodeString AEndString = System::UnicodeString(), int ARecordPerBand = 0x8, const System::UnicodeString AFileExt = L"txt");
}	/* namespace Cxexportvglink */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXPORTVGLINK)
using namespace Cxexportvglink;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexportvglinkHPP
