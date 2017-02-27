// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxServerModeUtils.pas' rev: 24.00 (Win32)

#ifndef DxservermodeutilsHPP
#define DxservermodeutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxServerModeClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxservermodeutils
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Variant __fastcall dxServerModeGetFieldValue(Data::Db::TField* AField);
extern PACKAGE System::Variant __fastcall dxCreateServerModeRow(Data::Db::TFields* AFields);
extern PACKAGE int __fastcall dxGetServerModeRowValueCount(const System::Variant &ARow);
extern PACKAGE System::UnicodeString __fastcall dxVarArrayToDelimetedText(const System::Variant &AValue, const System::UnicodeString ADelimiter, const System::UnicodeString AQuote);
extern PACKAGE System::UnicodeString __fastcall dxKeyToText(const System::Variant &AKey);
}	/* namespace Dxservermodeutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSERVERMODEUTILS)
using namespace Dxservermodeutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxservermodeutilsHPP
