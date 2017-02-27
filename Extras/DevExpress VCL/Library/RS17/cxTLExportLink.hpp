// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTLExportLink.pas' rev: 24.00 (Win32)

#ifndef CxtlexportlinkHPP
#define CxtlexportlinkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxTL.hpp>	// Pascal unit
#include <cxTLStrs.hpp>	// Pascal unit
#include <cxExport.hpp>	// Pascal unit
#include <cxXLSExport.hpp>	// Pascal unit
#include <dxXLSXExport.hpp>	// Pascal unit
#include <cxHtmlXmlTxtExport.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtlexportlink
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall cxExportTLToHTML(const System::UnicodeString AFileName, Cxtl::TcxCustomTreeList* ATreeList, bool AExpand = true, bool ASaveAll = true, const System::UnicodeString AFileExt = L"html");
extern PACKAGE void __fastcall cxExportTLToXML(const System::UnicodeString AFileName, Cxtl::TcxCustomTreeList* ATreeList, bool AExpand = true, bool ASaveAll = true, const System::UnicodeString AFileExt = L"xml");
extern PACKAGE void __fastcall cxExportTLToExcel(const System::UnicodeString AFileName, Cxtl::TcxCustomTreeList* ATreeList, bool AExpand = true, bool ASaveAll = true, bool AUseNativeFormat = true, const System::UnicodeString AFileExt = L"xls");
extern PACKAGE void __fastcall cxExportTLToText(const System::UnicodeString AFileName, Cxtl::TcxCustomTreeList* ATreeList, bool AExpand = true, bool ASaveAll = true, const System::UnicodeString ASeparator = System::UnicodeString(), const System::UnicodeString ABeginString = System::UnicodeString(), const System::UnicodeString AEndString = System::UnicodeString(), const System::UnicodeString AFileExt = L"txt");
extern PACKAGE void __fastcall cxExportTLToFile(System::UnicodeString AFileName, Cxtl::TcxCustomTreeList* ATreeList, int AExportType, bool AExpand, bool ASaveAll, bool AUseNativeFormat, System::UnicodeString const *ASeparators, const int ASeparators_Size, const System::UnicodeString AFileExt);
extern PACKAGE void __fastcall cxExportTLToXLSX(const System::UnicodeString AFileName, Cxtl::TcxCustomTreeList* ATreeList, bool AExpand = true, bool ASaveAll = true, bool AUseNativeFormat = true, const System::UnicodeString AFileExt = L"xlsx");
}	/* namespace Cxtlexportlink */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTLEXPORTLINK)
using namespace Cxtlexportlink;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtlexportlinkHPP
