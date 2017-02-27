// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditPaintUtils.pas' rev: 24.00 (Win32)

#ifndef CxeditpaintutilsHPP
#define CxeditpaintutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditpaintutils
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSolidBrushCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSolidBrushCache : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<System::Uitypes::TColor> _TcxSolidBrushCache__1;
	
	typedef System::DynamicArray<HBRUSH> _TcxSolidBrushCache__2;
	
	typedef System::DynamicArray<unsigned> _TcxSolidBrushCache__3;
	
	
private:
	_TcxSolidBrushCache__1 FBrushColors;
	_TcxSolidBrushCache__2 FBrushes;
	_TcxSolidBrushCache__3 FCounts;
	int FDepth;
	int FMaxDepth;
	Cxlookandfeels::TcxSystemPaletteChangedNotifier* FSystemPaletteChangedNotifier;
	
protected:
	virtual void __fastcall SystemPaletteChanged(void);
	
public:
	__fastcall TcxSolidBrushCache(void)/* overload */;
	__fastcall TcxSolidBrushCache(int AMaxDepth)/* overload */;
	__fastcall virtual ~TcxSolidBrushCache(void);
	void __fastcall Clear(void);
	HBRUSH __fastcall GetBrush(System::Uitypes::TColor ABrushColor);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Byte cxSolidBrushCacheDefaultMaxDepth = System::Byte(0x80);
extern PACKAGE HBRUSH __fastcall GetSolidBrush(System::Uitypes::TColor ABrushColor)/* overload */;
extern PACKAGE HBRUSH __fastcall GetSolidBrush(Vcl::Graphics::TCanvas* ACanvas, System::Uitypes::TColor ABrushColor)/* overload */;
extern PACKAGE HBRUSH __fastcall GetSolidBrush(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor ABrushColor)/* overload */;
extern PACKAGE void __fastcall ResetSolidBrushCache(void);
}	/* namespace Cxeditpaintutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITPAINTUTILS)
using namespace Cxeditpaintutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditpaintutilsHPP
