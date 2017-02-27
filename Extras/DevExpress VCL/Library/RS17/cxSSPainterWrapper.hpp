// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSPainterWrapper.pas' rev: 24.00 (Win32)

#ifndef CxsspainterwrapperHPP
#define CxsspainterwrapperHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxsspainterwrapper
{
//-- type declarations -------------------------------------------------------
typedef System::Uitypes::TFontStyles TcxFontStyles;

typedef System::Uitypes::TFontCharset TcxFontCharset;

enum TcxBackgroundMode : unsigned char { bmTransparent, bmOpaque };

enum TcxPaintObjects : unsigned char { poBrush, poFont, poPen };

struct DECLSPEC_DRECORD TcxSSTextExtentsEx
{
private:
	typedef System::DynamicArray<int> _TcxSSTextExtentsEx__1;
	
	
public:
	System::Types::TSize Size;
	int SpaceWidth;
	int LineHeight;
	_TcxSSTextExtentsEx__1 TextWidths;
};


class DELPHICLASS TcxCanvasWrapper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvasWrapper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FBkColor;
	TcxBackgroundMode FBkMode;
	Vcl::Graphics::TCanvas* FCanvas;
	System::StaticArray<System::StaticArray<System::Uitypes::TColor, 3>, 2> FDefColors;
	Cxexcelconst::TcxExcelPalette FHighLightPalette;
	System::Uitypes::TColor FTextColor;
	HFONT FFontHandle;
	HDC FPainterHandle;
	void *FPalette;
	System::Uitypes::TColor FSelectionColor;
	System::Uitypes::TColor __fastcall GetDefBorderColor(void);
	System::Uitypes::TColor __fastcall GetDefTextColor(void);
	System::Uitypes::TColor __fastcall GetDefWindowColor(void);
	Cxexcelconst::PcxExcelPalette __fastcall GetPalette(void);
	void __fastcall SetDefaultColor(const System::Uitypes::TColor AValue, TcxPaintObjects AObject);
	void __fastcall SetDefBorderColor(const System::Uitypes::TColor AValue);
	void __fastcall SetDefTextColor(const System::Uitypes::TColor AValue);
	void __fastcall SetDefWindowColor(const System::Uitypes::TColor AValue);
	void __fastcall SetPalette(Cxexcelconst::PcxExcelPalette APalette);
	void __fastcall SetSelectionColor(const System::Uitypes::TColor AValue);
	
protected:
	bool __fastcall CheckHandle(int AHandle)/* overload */;
	bool __fastcall CheckHandle(System::TObject* AHandle)/* overload */;
	void __fastcall DrawLine(System::Types::TRect const *AVertex, const int AVertex_Size, Cxsstypes::TcxSSEdgeLineStyle AStyle, Dxcore::TdxOrientation AOrientation);
	virtual System::UnicodeString __fastcall GetWordFromPos(const System::UnicodeString AString, int &APos);
	virtual void __fastcall HandlesNeeded(void);
	virtual void __fastcall SplitToTextBricks(const System::UnicodeString AText, const System::Types::TRect &ARect, Cxsstypes::TcxHorzTextAlign HAlign, Cxsstypes::TcxVertTextAlign VAlign, Cxsstypes::TWordExtents &ATextBricks);
	virtual void __fastcall ReleaseHandles(void);
	__classmethod void __fastcall CreateBrushStyles();
	__classmethod void __fastcall CreatePenStyles();
	__classmethod void __fastcall InitColors();
	__classmethod void __fastcall RemoveBrushStyles();
	__classmethod void __fastcall RemovePenStyles();
	__property Cxexcelconst::PcxExcelPalette Palette = {read=GetPalette, write=SetPalette};
	
public:
	__fastcall virtual TcxCanvasWrapper(Cxexcelconst::PcxExcelPalette APalette);
	__fastcall virtual ~TcxCanvasWrapper(void);
	void __fastcall BeginPaint(Vcl::Graphics::TCanvas* ACanvas)/* overload */;
	void __fastcall BeginPaint(Cxexcelconst::PcxExcelPalette APalette, Vcl::Graphics::TCanvas* ACanvas)/* overload */;
	void __fastcall CalculateTextExtents(const System::UnicodeString AText, const System::Types::TRect &ATextRect, Cxsstypes::TcxHorzTextAlign AHorzAlign, Cxsstypes::TcxVertTextAlign AVertAlign, bool AWordBreak, Cxsstypes::TcxTextParameters &ATextParams);
	void __fastcall DrawText(const System::UnicodeString AText, const System::Types::TRect &ARect);
	void __fastcall DrawTriangleGlyph(const System::Types::TRect &ARect, System::Uitypes::TColor AColor, bool ALeftToRight, bool IsDrawLine);
	virtual void __fastcall EndPaint(void);
	void __fastcall ExcludeClipRect(const System::Types::TRect &ARect)/* overload */;
	void __fastcall ExcludeClipRect(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall ExcludeClipRgn(System::Types::TPoint const *APoints, const int APoints_Size);
	virtual void __fastcall ExDrawText(const System::Types::TRect &AClipRect, const Cxsstypes::TcxTextParameters &AextTextParams);
	void __fastcall FillRect(const System::Types::TRect &ARect, Cxsstypes::TcxSSFillStyle AStyle, const System::Uitypes::TColor ABkColor, const System::Uitypes::TColor AFgColor)/* overload */;
	void __fastcall FillRect(const System::Types::TRect &ARect, Cxsstypes::TcxSSFillStyle AStyle, const System::Word ABkColor, const System::Word AFgColor, bool IsSelected)/* overload */;
	void __fastcall FrameRect(const System::Types::TRect &ARect, System::Uitypes::TColor AColor, bool IsSelected = false)/* overload */;
	void __fastcall FrameRect(const System::Types::TRect &ARect, const System::Uitypes::TColor ATopColor, const System::Uitypes::TColor ABottomColor, bool IsSelected = false)/* overload */;
	__classmethod int __fastcall GetNativeColor(const System::Uitypes::TColor AColor);
	System::Types::TPoint __fastcall GetTextExtent(const System::UnicodeString AText);
	void __fastcall InvertRect(const System::Types::TRect &ARect);
	void __fastcall Line(const System::Types::TRect &AVertex, Cxsstypes::TcxSSEdgeLineStyle AStyle, Dxcore::TdxOrientation AOrientation, System::Uitypes::TColor ABkColor, System::Uitypes::TColor AFgColor)/* overload */;
	void __fastcall Line(System::Types::TRect const *AVertex, const int AVertex_Size, Cxsstypes::TcxSSEdgeLineStyle AStyle, Dxcore::TdxOrientation AOrientation, System::Word ABkColor, System::Word AFgColor, bool IsSelected)/* overload */;
	virtual void __fastcall PaletteChanged(void);
	void __fastcall Polygon(System::Types::TPoint const *APoints, const int APoints_Size, const System::Uitypes::TColor AColor);
	void __fastcall Rectangle(const System::Types::TRect &ARect, const HBRUSH ABrush);
	bool __fastcall RectIsVisible(const System::Types::TRect &ARect);
	void __fastcall SelectFonT(Vcl::Graphics::TFont* AFont)/* overload */;
	void __fastcall SelectFonT(const HFONT AFont, bool ACheckSettings = true)/* overload */;
	void __fastcall SelectFonT(const HFONT AFont, System::Word AColor)/* overload */;
	void __fastcall SetBkMode(TcxBackgroundMode AMode);
	virtual void __fastcall SetSingleText(const System::UnicodeString AText, const System::Types::TRect &ATextRect, Cxsstypes::TcxTextParameters &ATextSettings, bool AVertCenterAlign = true);
	void __fastcall SetBkColor(System::Uitypes::TColor AColor)/* overload */;
	void __fastcall SetBkColor(System::Word AColor, bool IsSelected, TcxPaintObjects AObject)/* overload */;
	void __fastcall SetTextColor(System::Uitypes::TColor AColor)/* overload */;
	void __fastcall SetTextColor(System::Word AColor, bool IsSelected, TcxPaintObjects AObject)/* overload */;
	int __fastcall TextWidth(const System::UnicodeString AText);
	int __fastcall TextHeight(const System::UnicodeString AText);
	__classmethod System::Uitypes::TColor __fastcall MixColors(System::Uitypes::TColor ASelColor, System::Uitypes::TColor ASrcColor);
	__property System::Uitypes::TColor BorderColor = {read=GetDefBorderColor, write=SetDefBorderColor, nodefault};
	__property Vcl::Graphics::TCanvas* Canvas = {read=FCanvas, write=FCanvas};
	__property HDC Handle = {read=FPainterHandle, nodefault};
	__property System::Uitypes::TColor TextColor = {read=GetDefTextColor, write=SetDefTextColor, nodefault};
	__property System::Uitypes::TColor WindowColor = {read=GetDefWindowColor, write=SetDefWindowColor, nodefault};
	__property System::Uitypes::TColor SelectionColor = {read=FSelectionColor, write=SetSelectionColor, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::StaticArray<System::Byte, 15> cxPenWidth;
extern PACKAGE System::StaticArray<System::Byte, 15> cxHalfPenWidth;
extern PACKAGE int cxBlackColor;
extern PACKAGE int cxWhiteColor;
extern PACKAGE int cxBtnFaceColor;
extern PACKAGE int cxBtnShadowColor;
extern PACKAGE int cxBtnHighLightColor;
extern PACKAGE int __fastcall ColorToRGB(const System::Uitypes::TColor AColor);
extern PACKAGE int __fastcall RectHeight(const System::Types::TRect &ARect);
extern PACKAGE int __fastcall RectWidth(const System::Types::TRect &ARect);
}	/* namespace Cxsspainterwrapper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSPAINTERWRAPPER)
using namespace Cxsspainterwrapper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxsspainterwrapperHPP
