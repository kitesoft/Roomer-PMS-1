// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCoreGraphics.pas' rev: 24.00 (Win64)

#ifndef DxcoregraphicsHPP
#define DxcoregraphicsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcoregraphics
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxGetBitmapData(HBITMAP ABitmapHandle, /* out */ tagBITMAP &ABitmapData);
extern PACKAGE bool __fastcall dxGetBrushData(HBRUSH ABrushHandle, /* out */ tagLOGBRUSH &ALogBrush)/* overload */;
extern PACKAGE tagLOGBRUSH __fastcall dxGetBrushData(HBRUSH ABrushHandle)/* overload */;
extern PACKAGE bool __fastcall dxGetFontData(HFONT AFontHandle, /* out */ tagLOGFONTW &ALogFont)/* overload */;
extern PACKAGE tagLOGFONTW __fastcall dxGetFontData(HFONT AFontHandle)/* overload */;
extern PACKAGE bool __fastcall dxGetPenData(HPEN APenHandle, /* out */ tagLOGPEN &ALogPen);
}	/* namespace Dxcoregraphics */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCOREGRAPHICS)
using namespace Dxcoregraphics;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcoregraphicsHPP
