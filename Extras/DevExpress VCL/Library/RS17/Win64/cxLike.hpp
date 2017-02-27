// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLike.pas' rev: 24.00 (Win64)

#ifndef CxlikeHPP
#define CxlikeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlike
{
//-- type declarations -------------------------------------------------------
enum TcxFilterLikeOperator : unsigned char { floLike, floBeginsWith, floEndsWith, floContains };

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxFilterLikeOperator __fastcall LikeOperatorByPattern(System::UnicodeString &APatternStr, System::WideChar APercent);
extern PACKAGE bool __fastcall LikeStr(const System::UnicodeString AStr, const System::UnicodeString APatternStr, System::WideChar APercent, System::WideChar AUnderline);
}	/* namespace Cxlike */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLIKE)
using namespace Cxlike;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlikeHPP
