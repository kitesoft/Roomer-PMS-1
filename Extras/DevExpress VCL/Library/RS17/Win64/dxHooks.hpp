// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxHooks.pas' rev: 24.00 (Win64)

#ifndef DxhooksHPP
#define DxhooksHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxhooks
{
//-- type declarations -------------------------------------------------------
enum TdxHookType : unsigned char { htKeyboard, htMouse, htWndProc, htGetMessage, htCBT };

typedef void __fastcall (*TdxHookProc)(int ACode, NativeUInt wParam, NativeInt lParam, NativeInt &AHookResult);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxSetHook(TdxHookType AHookType, TdxHookProc AHookProc);
extern PACKAGE void __fastcall dxReleaseHook(TdxHookProc AHookProc);
}	/* namespace Dxhooks */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXHOOKS)
using namespace Dxhooks;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxhooksHPP
