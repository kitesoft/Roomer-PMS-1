// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinLiquidSky.pas' rev: 24.00 (Win64)

#ifndef DxskinliquidskyHPP
#define DxskinliquidskyHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinliquidsky
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinLiquidSkyPainter;
class PASCALIMPLEMENTATION TdxSkinLiquidSkyPainter : public Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter
{
	typedef Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter inherited;
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
public:
	/* TdxSkinLookAndFeelPainter.Create */ inline __fastcall virtual TdxSkinLiquidSkyPainter(const System::UnicodeString ASkinResName, NativeUInt ASkinResInstance) : Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter(ASkinResName, ASkinResInstance) { }
	/* TdxSkinLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TdxSkinLiquidSkyPainter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinliquidsky */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINLIQUIDSKY)
using namespace Dxskinliquidsky;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinliquidskyHPP
