// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxConverterUtils.pas' rev: 24.00 (Win64)

#ifndef CxconverterutilsHPP
#define CxconverterutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxconverterutils
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall CompareFonts(Vcl::Graphics::TFont* AFont1, Vcl::Graphics::TFont* AFont2);
extern PACKAGE System::Classes::TAlignment __fastcall ConvertAlignment(const System::UnicodeString AValue);
extern PACKAGE System::Uitypes::TEditCharCase __fastcall ConvertCharCase(const System::UnicodeString AValue);
extern PACKAGE System::Uitypes::TScrollStyle __fastcall ConvertScrollStyle(const System::UnicodeString AValue);
extern PACKAGE bool __fastcall DefaultFont(Vcl::Graphics::TFont* AFont);
}	/* namespace Cxconverterutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCONVERTERUTILS)
using namespace Cxconverterutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxconverterutilsHPP
