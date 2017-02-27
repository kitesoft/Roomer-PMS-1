// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExtEditUtils.pas' rev: 24.00 (Win64)

#ifndef CxexteditutilsHPP
#define CxexteditutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditPaintUtils.hpp>	// Pascal unit
#include <cxEditUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexteditutils
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const System::Int8 MRUDelimiterWidth = System::Int8(0x3);
extern PACKAGE System::Types::TRect __fastcall DrawBounds(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &Bounds, const System::Uitypes::TColor AUpperLeftColor, const System::Uitypes::TColor ALowerRightColor);
extern PACKAGE void __fastcall DrawCanvasLine(Vcl::Graphics::TCanvas* ACanvas, const System::Uitypes::TColor AColor, const System::Types::TPoint AFromPoint, const System::Types::TPoint AToPoint);
extern PACKAGE void __fastcall DrawMRUDelimiter(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &AItemRect, bool AIsItemSelected);
extern PACKAGE int __fastcall CalcMaxWidth(Vcl::Graphics::TCanvas* ACanvas, const System::UnicodeString AText);
extern PACKAGE System::Uitypes::TColor __fastcall IncColor(const System::Uitypes::TColor AColor, const int AR, const int AG, const int AB);
extern PACKAGE int __fastcall CalcCenterPosHeight(const System::Types::TRect &ARect, const int ADrawHeight);
extern PACKAGE int __fastcall CalcDrawWidth(const System::Types::TRect &ARect, const int ADrawHeight);
extern PACKAGE bool __fastcall IsVarEmpty(const System::Variant &AValue);
extern PACKAGE bool __fastcall IsValidStringForInt(System::UnicodeString S);
extern PACKAGE bool __fastcall IsValidStringForDouble(const System::UnicodeString AValue);
extern PACKAGE int __fastcall cxStrToInt(const System::UnicodeString AValue, bool AToFirstNonNum = false);
extern PACKAGE System::Extended __fastcall cxStrToFloat(const System::UnicodeString AValue, bool AToFirstNonNum = false);
extern PACKAGE bool __fastcall cxStrToColor(System::UnicodeString S, /* out */ System::Uitypes::TColor &AColor);
extern PACKAGE System::Uitypes::TColor __fastcall cxRGBStringColorToColor(const System::UnicodeString AString);
extern PACKAGE System::Uitypes::TColor __fastcall cxHexRGBStringColorToColor(const System::UnicodeString AString);
extern PACKAGE System::UnicodeString __fastcall CheckStateToString(const Cxlookandfeelpainters::TcxCheckBoxState Value);
extern PACKAGE Cxlookandfeelpainters::TcxCheckBoxState __fastcall StringToCheckState(const System::UnicodeString Value, const bool AllowGrayed);
extern PACKAGE System::UnicodeString __fastcall GetWord(const int APosition, const System::UnicodeString S, const System::WideChar Delimiter);
extern PACKAGE bool __fastcall AdjustCanvasFont(Vcl::Graphics::TCanvas* ACanvas, Vcl::Graphics::TFont* AFont, int AAngle);
}	/* namespace Cxexteditutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXTEDITUTILS)
using namespace Cxexteditutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexteditutilsHPP
