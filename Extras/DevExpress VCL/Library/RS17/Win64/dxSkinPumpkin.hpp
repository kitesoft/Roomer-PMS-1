// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinPumpkin.pas' rev: 24.00 (Win64)

#ifndef DxskinpumpkinHPP
#define DxskinpumpkinHPP

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

namespace Dxskinpumpkin
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinPumpkinPainter;
class PASCALIMPLEMENTATION TdxSkinPumpkinPainter : public Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter
{
	typedef Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter inherited;
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
public:
	/* TdxSkinLookAndFeelPainter.Create */ inline __fastcall virtual TdxSkinPumpkinPainter(const System::UnicodeString ASkinResName, NativeUInt ASkinResInstance) : Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter(ASkinResName, ASkinResInstance) { }
	/* TdxSkinLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TdxSkinPumpkinPainter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinpumpkin */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINPUMPKIN)
using namespace Dxskinpumpkin;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinpumpkinHPP
