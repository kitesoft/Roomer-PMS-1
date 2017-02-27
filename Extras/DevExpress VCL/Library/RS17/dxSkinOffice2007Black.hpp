// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinOffice2007Black.pas' rev: 24.00 (Win32)

#ifndef Dxskinoffice2007blackHPP
#define Dxskinoffice2007blackHPP

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

namespace Dxskinoffice2007black
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinOffice2007BlackPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxSkinOffice2007BlackPainter : public Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter
{
	typedef Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter inherited;
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
public:
	/* TdxSkinLookAndFeelPainter.Create */ inline __fastcall virtual TdxSkinOffice2007BlackPainter(const System::UnicodeString ASkinResName, NativeUInt ASkinResInstance) : Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter(ASkinResName, ASkinResInstance) { }
	/* TdxSkinLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TdxSkinOffice2007BlackPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxskinoffice2007black */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINOFFICE2007BLACK)
using namespace Dxskinoffice2007black;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxskinoffice2007blackHPP
