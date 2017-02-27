// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxDrawRichTextUtils.pas' rev: 24.00 (Win32)

#ifndef DxdrawrichtextutilsHPP
#define DxdrawrichtextutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.RichEdit.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdrawrichtextutils
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxRichTextHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRichTextHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Comctrls::TRichEdit* FRichEdit;
	
public:
	__fastcall virtual TdxRichTextHelper(void);
	__fastcall virtual ~TdxRichTextHelper(void);
	virtual void __fastcall CalculateTextHeight(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect);
	virtual void __fastcall DrawText(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall Init(Vcl::Graphics::TCanvas* ACanvas, const System::UnicodeString AText);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxDrawRichEdit(HDC ADC, const System::Types::TRect &ARect, HWND ARichHandle, int AMinCharIndex, int AMaxCharIndex, bool ACalculateHeight, /* out */ int &AHeight)/* overload */;
extern PACKAGE void __fastcall dxDrawRichEdit(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Comctrls::TRichEdit* ARichEdit, int AMinCharIndex, int AMaxCharIndex, bool ACalculateHeight, /* out */ int &AHeight)/* overload */;
extern PACKAGE bool __fastcall dxIsRichText(const System::UnicodeString AText);
extern PACKAGE int __fastcall dxPixelsToTwips(int AValue);
extern PACKAGE void __fastcall dxRichLoadFromString(System::Classes::TStrings* ALines, const System::UnicodeString S);
}	/* namespace Dxdrawrichtextutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDRAWRICHTEXTUTILS)
using namespace Dxdrawrichtextutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdrawrichtextutilsHPP
