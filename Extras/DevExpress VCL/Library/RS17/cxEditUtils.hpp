// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditUtils.pas' rev: 24.00 (Win32)

#ifndef CxeditutilsHPP
#define CxeditutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditPaintUtils.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditutils
{
//-- type declarations -------------------------------------------------------
typedef HDC TcxEditCanvasHandle;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxEditButtonMaxBorderWidth = System::Int8(0x2);
static const System::Int8 cxEditMaxBorderWidth = System::Int8(0x2);
static const System::Int8 cxEditMaxCheckBoxBorderWidth = System::Int8(0x2);
static const System::Int8 cxEditShadowWidth = System::Int8(0x3);
extern PACKAGE void __fastcall DrawArrow(Cxgraphics::TcxCanvas* ACanvas, int AArrowSize, const System::Types::TRect &AContentRect, Cxlookandfeelpainters::TcxArrowDirection AArrowDirection, bool AIsDoubleArrow, bool AOffsetContent, System::Uitypes::TColor AColor);
extern PACKAGE void __fastcall DrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, System::Uitypes::TColor AColor);
extern PACKAGE void __fastcall DrawGlyph(Vcl::Graphics::TCanvas* ACanvas, int X, int Y, Vcl::Graphics::TBitmap* AGlyph, bool AEnabled, System::Uitypes::TColor ABrushColor = (System::Uitypes::TColor)(0x1fffffff), Vcl::Graphics::TBitmap* ABackgroundBitmap = (Vcl::Graphics::TBitmap*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawGlyph(Cxgraphics::TcxCanvas* ACanvas, int X, int Y, Vcl::Graphics::TBitmap* AGlyph, bool AEnabled, System::Uitypes::TColor ABrushColor = (System::Uitypes::TColor)(0x1fffffff), Vcl::Graphics::TBitmap* ABackgroundBitmap = (Vcl::Graphics::TBitmap*)(0x0))/* overload */;
extern PACKAGE void __fastcall DrawGlyph(Cxgraphics::TcxCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImageList, System::Uitypes::TImageIndex AImageIndex, const System::Types::TRect &AGlyphRect, System::Uitypes::TColor ABrushColor, bool AEnabled, Vcl::Graphics::TBitmap* ABackgroundBitmap = (Vcl::Graphics::TBitmap*)(0x0))/* overload */;
extern PACKAGE Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainterClass(bool ANativeStyle, Cxlookandfeels::TcxLookAndFeelKind ALookAndFeel);
extern PACKAGE void __fastcall InternalPolyLine(Cxgraphics::TcxCanvas* ACanvas, System::Types::TPoint const *Points, const int Points_Size, System::Uitypes::TColor AColor, bool AOrtoDrawing = false);
extern PACKAGE bool __fastcall VerifyBitmap(Vcl::Graphics::TBitmap* ABitmap);
extern PACKAGE bool __fastcall VerifyImages(Vcl::Imglist::TCustomImageList* AImages);
extern PACKAGE int __fastcall CalculateEditDefaultButtonWidth(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AViewInfo);
extern PACKAGE void __fastcall cxEditFillRect(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor)/* overload */;
extern PACKAGE void __fastcall cxEditFillRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor)/* overload */;
extern PACKAGE void __fastcall cxEditFillRect(HDC ACanvasHandle, const System::Types::TRect &R, HBRUSH ABrush)/* overload */;
extern PACKAGE bool __fastcall cxIsDigitChar(System::WideChar C);
extern PACKAGE bool __fastcall cxOffsetRect(System::Types::TRect &ARect, const System::Types::TPoint &AOffset);
extern PACKAGE int __fastcall cxTextOutFlagsToDrawTextFlags(unsigned AFlags);
extern PACKAGE int __fastcall DrawTextFlagsTocxTextOutFlags(unsigned AFlags);
extern PACKAGE void __fastcall InternalFillRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &AOuterRect, const System::Types::TRect &AInternalRect, HBRUSH ABrush);
extern PACKAGE void __fastcall DrawCustomEdit(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool ACanDrawBackground);
extern PACKAGE void __fastcall DrawCustomEditBackground(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool ACanDrawBackground);
extern PACKAGE System::Types::TSize __fastcall GetArrowSize(const System::Types::TSize &AContentSize, Cxlookandfeelpainters::TcxArrowDirection AArrowDirection);
extern PACKAGE int __fastcall GetEditButtonsContentVerticalOffset(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonStyle AButtonsStyle, bool ANativeStyle);
extern PACKAGE System::Uitypes::TColor __fastcall GetHotTrackColor(void);
extern PACKAGE int __fastcall GetNativeInnerTextEditContentHeightCorrection(Cxedit::TcxCustomEditProperties* AProperties, bool AIsInplace);
extern PACKAGE Cxgraphics::TcxRegion* __fastcall GetEditButtonRegion(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxEditButtonViewInfo* AViewInfo);
extern PACKAGE System::Uitypes::TColor __fastcall GetEditBorderHighlightColor(bool AIsOffice11Style);
extern PACKAGE System::Uitypes::TColor __fastcall GetEditButtonHighlightColor(bool APressed, bool AIsOffice11Style);
extern PACKAGE bool __fastcall IsShadowDrawingNeeded(Cxedit::TcxCustomEditViewData* AViewData);
extern PACKAGE void __fastcall RestoreCanvasFont _DEPRECATED_ATTRIBUTE0 (Cxgraphics::TcxCanvas* ACanvas, const tagLOGFONTW &ASavedLogFont);
extern PACKAGE void __fastcall SaveCanvasFont _DEPRECATED_ATTRIBUTE0 (Cxgraphics::TcxCanvas* ACanvas, /* out */ tagLOGFONTW &ALogFont);
}	/* namespace Cxeditutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITUTILS)
using namespace Cxeditutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditutilsHPP
