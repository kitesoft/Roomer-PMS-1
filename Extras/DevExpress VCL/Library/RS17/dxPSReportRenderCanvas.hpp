// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSReportRenderCanvas.pas' rev: 24.00 (Win32)

#ifndef DxpsreportrendercanvasHPP
#define DxpsreportrendercanvasHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsreportrendercanvas
{
//-- type declarations -------------------------------------------------------
enum TdxPicturePaintMode : unsigned char { ppmCenter, ppmStretch, ppmTile, ppmProportional };

enum TdxCheckButtonEdgeStyle : unsigned char { cbesNone, cbes3D, cbesSoft3D, cbesBoldFlat, cbesUltraFlat, cbesSingle };

enum TdxPSReportRenderCanvasMappingMode : unsigned char { rrmmDefault, rrmmText, rrmmLoMetric, rrmmHiMetric, rrmmLoEnglish, rrmmHiEnglish, rrmmTwips, rrmmIsotropic, rrmmAnisotropic };

class DELPHICLASS TdxPSReportRenderCustomCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSReportRenderCustomCanvas : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TFont* FFont;
	void __fastcall DoFontChanged(System::TObject* Sender);
	void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	
protected:
	virtual Vcl::Graphics::TBrush* __fastcall GetBrush(void) = 0 ;
	virtual System::Types::TPoint __fastcall GetBrushOrg(void) = 0 ;
	virtual bool __fastcall GetIsPrinterCanvas(void) = 0 ;
	virtual int __fastcall GetPixelsPerInch(void) = 0 ;
	virtual bool __fastcall GetSupportsTransparentImagesDrawing(void);
	virtual System::Types::TSize __fastcall GetWindowExt(void) = 0 ;
	virtual System::Types::TPoint __fastcall GetWindowOrg(void) = 0 ;
	void __fastcall AssignCanvasFont(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DoFillEdge(HRGN ARegion, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AEdgeColor, bool AIsVerticalOrientation, System::TClass AEdgePattern);
	virtual void __fastcall FontChanged(void);
	virtual void __fastcall PrepareCanvasForCustomDraw(Vcl::Graphics::TFont* AFont, System::Uitypes::TColor AColor);
	virtual void __fastcall SetBrush(Vcl::Graphics::TBrush* AValue) = 0 ;
	virtual void __fastcall SetBrushOrg(const System::Types::TPoint &AValue) = 0 ;
	virtual void __fastcall SetWindowExt(const System::Types::TSize &ASize) = 0 ;
	virtual void __fastcall SetWindowOrg(const System::Types::TPoint &P) = 0 ;
	
public:
	__fastcall TdxPSReportRenderCustomCanvas(void);
	__fastcall virtual ~TdxPSReportRenderCustomCanvas(void);
	virtual int __fastcall CalculateLineThickness(int AUnitsPerPixel, int AUnitsPerPoint);
	virtual void __fastcall DeviceToLogicalCoordinates(System::Types::TRect &R) = 0 ;
	virtual void __fastcall FixupRect(System::Types::TRect &R);
	virtual void __fastcall LogicalToDeviceCoordinates(System::Types::TRect &R) = 0 ;
	virtual void __fastcall PrepareLogicalUnits(void);
	virtual void __fastcall RestoreState(void) = 0 ;
	virtual void __fastcall SaveState(void) = 0 ;
	virtual void __fastcall UnprepareLogicalUnits(void);
	virtual Vcl::Graphics::TCanvas* __fastcall BeginCustomDraw(const System::Types::TRect &AClipBounds, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor AColor) = 0 ;
	virtual void __fastcall EndCustomDraw(Vcl::Graphics::TCanvas* &ACanvas) = 0 ;
	virtual Cxdrawtextutils::TcxTextParams __fastcall CalculateTextParams(int ADrawTextFormat) = 0 ;
	virtual int __fastcall CalculateTextRect(const System::UnicodeString AText, System::Types::TRect &R, unsigned AFormat = (unsigned)(0x200), Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000)) = 0 ;
	virtual void __fastcall DrawText(System::Types::TRect &R, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), int AMaxLineCount = 0x0) = 0 ;
	virtual bool __fastcall MakeTextRows(System::WideChar * AText, int ATextLength, const System::Types::TRect &R, const Cxdrawtextutils::TcxTextParams &ATextParams, Cxdrawtextutils::TcxTextRows &ATextRows, /* out */ int &ACount, int AMaxLineCount = 0x0) = 0 ;
	virtual System::Types::TSize __fastcall TextSize(const System::UnicodeString AText) = 0 ;
	virtual void __fastcall RotatedTextOut(const System::Types::TRect &ABounds, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, Cxdrawtextutils::TcxTextAlignX AAlignHorz = (Cxdrawtextutils::TcxTextAlignX)(0x1), Cxdrawtextutils::TcxTextAlignY AAlignVert = (Cxdrawtextutils::TcxTextAlignY)(0x1), bool AWordBreak = true, Cxdrawtextutils::TcxVerticalTextOutDirection ADirection = (Cxdrawtextutils::TcxVerticalTextOutDirection)(0x1)) = 0 ;
	virtual int __fastcall ExcludeClipRect(const System::Types::TRect &R) = 0 ;
	virtual int __fastcall IntersectClipRgn(const System::Types::TRect &R) = 0 ;
	virtual bool __fastcall IsRectVisible(const System::Types::TRect &R) = 0 ;
	virtual System::Types::TPoint __fastcall OffsetWindowOrg(const System::Types::TPoint &P) = 0 ;
	virtual void __fastcall RestoreClipRgn(void) = 0 ;
	virtual void __fastcall SaveClipRgn(void) = 0 ;
	virtual void __fastcall SetCanvasExts(const System::Types::TPoint &APageSize, TdxPSReportRenderCanvasMappingMode AMappingMode, int AScaleNumerator, int AScaleDenominator, const System::Types::TRect &AViewPort) = 0 ;
	virtual void __fastcall SetClipRect(const System::Types::TRect &R) = 0 ;
	virtual void __fastcall DrawCheckBox(System::Types::TRect &R, bool AChecked, bool AEnabled, bool AIsRadio, TdxCheckButtonEdgeStyle AEdgeStyle, Vcl::Graphics::TFont* AMarlettFont, int ALineThickness, System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0xff000008)) = 0 ;
	virtual void __fastcall DrawEllipseFrame(const System::Types::TRect &R, System::Uitypes::TColor AColor, int AThickness) = 0 ;
	virtual void __fastcall DrawExpandButton(const System::Types::TRect &R, TdxCheckButtonEdgeStyle AEdgeStyle, Vcl::Graphics::TFont* AMarlettFont, Vcl::Graphics::TFont* ASymbolFont, bool AExpanded, bool AShadow, bool AFillInterior, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor ABackgroundColor, int ALineThickness) = 0 ;
	virtual void __fastcall DrawFrame(const System::Types::TRect &R, System::Uitypes::TColor ATopLeftColor, System::Uitypes::TColor ARightBottomColor, int ABorderWidth = 0x1, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom )) = 0 ;
	virtual void __fastcall DrawGlyph(const System::Types::TRect &R, Vcl::Graphics::TFont* AGlyphFont, System::Byte AGlyphIndex, bool ACenterOnRect, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0xff000008)) = 0 ;
	virtual void __fastcall DrawPicture(Vcl::Graphics::TGraphic* APicture, const System::Types::TRect &R, TdxPicturePaintMode APictureMode, int ANumerator, int ADenominator, int AOffsetX = 0x0, int AOffsetY = 0x0) = 0 ;
	virtual void __fastcall DrawRoundFrame(const System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor AColor, int AThickness) = 0 ;
	void __fastcall FillEdge(HRGN ARegion, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AEdgeColor, bool AIsVerticalOrientation, System::TClass AEdgePattern);
	virtual void __fastcall FillEllipse(const System::Types::TRect &R, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush) = 0 ;
	virtual void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor) = 0 ;
	virtual void __fastcall FillRegion(HRGN ARegion, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush) = 0 ;
	virtual void __fastcall FillRoundRect(const System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush) = 0 ;
	virtual void __fastcall Polyline(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor AColor, int ALineWidth) = 0 ;
	virtual void __fastcall Polygon(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor AColor, System::Uitypes::TColor ABackgroundColor, int ALineWidth, int AFillMode = 0x1) = 0 ;
	__property Vcl::Graphics::TBrush* Brush = {read=GetBrush, write=SetBrush};
	__property System::Types::TPoint BrushOrg = {read=GetBrushOrg, write=SetBrushOrg};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont};
	__property bool IsPrinterCanvas = {read=GetIsPrinterCanvas, nodefault};
	__property int PixelsPerInch = {read=GetPixelsPerInch, nodefault};
	__property bool SupportsTransparentImagesDrawing = {read=GetSupportsTransparentImagesDrawing, nodefault};
	__property System::Types::TSize WindowExt = {read=GetWindowExt, write=SetWindowExt};
	__property System::Types::TPoint WindowOrg = {read=GetWindowOrg, write=SetWindowOrg};
};

#pragma pack(pop)

class DELPHICLASS TdxPSReportRenderCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSReportRenderCanvas : public TdxPSReportRenderCustomCanvas
{
	typedef TdxPSReportRenderCustomCanvas inherited;
	
private:
	Cxgraphics::TcxCanvas* FCanvas;
	
protected:
	void __fastcall GetBorderColors(TdxCheckButtonEdgeStyle AEdgeStyle, System::Uitypes::TColor ADefaultBorderColor, bool AInnerBorder, /* out */ System::Uitypes::TColor &ATopLeftBorderColor, /* out */ System::Uitypes::TColor &ARightBottomBorderColor);
	virtual Vcl::Graphics::TBrush* __fastcall GetBrush(void);
	virtual System::Types::TPoint __fastcall GetBrushOrg(void);
	virtual bool __fastcall GetIsPrinterCanvas(void);
	virtual int __fastcall GetPixelsPerInch(void);
	virtual System::Types::TSize __fastcall GetWindowExt(void);
	virtual System::Types::TPoint __fastcall GetWindowOrg(void);
	bool __fastcall IsSolidFillPattern(Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	virtual void __fastcall FontChanged(void);
	virtual void __fastcall SetBrush(Vcl::Graphics::TBrush* AValue);
	virtual void __fastcall SetBrushOrg(const System::Types::TPoint &AValue);
	virtual void __fastcall SetWindowExt(const System::Types::TSize &AValue);
	virtual void __fastcall SetWindowOrg(const System::Types::TPoint &P);
	System::Types::TRect __fastcall CalculatePictureRect(Vcl::Graphics::TGraphic* APicture, const System::Types::TRect &R, TdxPicturePaintMode APictureMode, int ANumerator, int ADenominator);
	virtual void __fastcall InternalDrawFrameControl(const System::Types::TRect &R, int AType, int AState);
	void __fastcall InternalFillRectByBrushBitmap(const System::Types::TRect &R, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* ABrush);
	virtual void __fastcall DrawPictureStretch(Vcl::Graphics::TGraphic* APicture, const System::Types::TRect &R, int ANumerator, int ADenominator);
	virtual void __fastcall DrawPictureTile(Vcl::Graphics::TGraphic* APicture, const System::Types::TRect &R, int APictureWidth, int APictureHeight, int ANumerator, int ADenominator);
	
public:
	__fastcall TdxPSReportRenderCanvas(Vcl::Graphics::TCanvas* ACanvas);
	__fastcall virtual ~TdxPSReportRenderCanvas(void);
	virtual void __fastcall DeviceToLogicalCoordinates(System::Types::TRect &R);
	virtual void __fastcall LogicalToDeviceCoordinates(System::Types::TRect &R);
	virtual void __fastcall RestoreState(void);
	virtual void __fastcall SaveState(void);
	virtual Vcl::Graphics::TCanvas* __fastcall BeginCustomDraw(const System::Types::TRect &AClipBounds, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor AColor);
	virtual void __fastcall EndCustomDraw(Vcl::Graphics::TCanvas* &ACanvas);
	virtual Cxdrawtextutils::TcxTextParams __fastcall CalculateTextParams(int ADrawTextFormat);
	virtual int __fastcall CalculateTextRect(const System::UnicodeString AText, System::Types::TRect &R, unsigned AFormat = (unsigned)(0x200), Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawText(System::Types::TRect &R, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), int AMaxLineCount = 0x0);
	virtual bool __fastcall MakeTextRows(System::WideChar * AText, int ATextLength, const System::Types::TRect &R, const Cxdrawtextutils::TcxTextParams &ATextParams, Cxdrawtextutils::TcxTextRows &ATextRows, /* out */ int &ACount, int AMaxLineCount = 0x0);
	virtual System::Types::TSize __fastcall TextSize(const System::UnicodeString AText);
	virtual void __fastcall RotatedTextOut(const System::Types::TRect &ABounds, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, Cxdrawtextutils::TcxTextAlignX AAlignHorz = (Cxdrawtextutils::TcxTextAlignX)(0x1), Cxdrawtextutils::TcxTextAlignY AAlignVert = (Cxdrawtextutils::TcxTextAlignY)(0x1), bool AWordBreak = true, Cxdrawtextutils::TcxVerticalTextOutDirection ADirection = (Cxdrawtextutils::TcxVerticalTextOutDirection)(0x1));
	virtual int __fastcall ExcludeClipRect(const System::Types::TRect &R);
	virtual int __fastcall IntersectClipRgn(const System::Types::TRect &R);
	virtual bool __fastcall IsRectVisible(const System::Types::TRect &R);
	virtual System::Types::TPoint __fastcall OffsetWindowOrg(const System::Types::TPoint &P);
	virtual void __fastcall RestoreClipRgn(void);
	virtual void __fastcall SaveClipRgn(void);
	virtual void __fastcall SetCanvasExts(const System::Types::TPoint &APageSize, TdxPSReportRenderCanvasMappingMode AMappingMode, int AScaleNumerator, int AScaleDenominator, const System::Types::TRect &AViewPort);
	virtual void __fastcall SetClipRect(const System::Types::TRect &R);
	virtual void __fastcall DrawCheckBox(System::Types::TRect &R, bool AChecked, bool AEnabled, bool AIsRadio, TdxCheckButtonEdgeStyle AEdgeStyle, Vcl::Graphics::TFont* AMarlettFont, int ALineThickness, System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0xff000008));
	virtual void __fastcall DrawEllipseFrame(const System::Types::TRect &R, System::Uitypes::TColor AColor, int AThickness);
	virtual void __fastcall DrawExpandButton(const System::Types::TRect &R, TdxCheckButtonEdgeStyle AEdgeStyle, Vcl::Graphics::TFont* AMarlettFont, Vcl::Graphics::TFont* ASymbolFont, bool AExpanded, bool AShadow, bool AFillInterior, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor ABackgroundColor, int ALineThickness);
	virtual void __fastcall DrawFrame(const System::Types::TRect &R, System::Uitypes::TColor ATopLeftColor, System::Uitypes::TColor ARightBottomColor, int ABorderWidth = 0x1, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall DrawGlyph(const System::Types::TRect &R, Vcl::Graphics::TFont* AGlyphFont, System::Byte AGlyphIndex, bool ACenterOnRect, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0xff000008));
	virtual void __fastcall DrawPicture(Vcl::Graphics::TGraphic* APicture, const System::Types::TRect &R, TdxPicturePaintMode APictureMode, int ANumerator, int ADenominator, int AOffsetX = 0x0, int AOffsetY = 0x0);
	virtual void __fastcall DrawRoundFrame(const System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor AColor, int AThickness);
	virtual void __fastcall FillEllipse(const System::Types::TRect &R, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	virtual void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall FillRegion(HRGN ARegion, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	virtual void __fastcall FillRoundRect(const System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	virtual void __fastcall Polyline(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor AColor, int ALineWidth);
	virtual void __fastcall Polygon(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor AColor, System::Uitypes::TColor ABackgroundColor, int ALineWidth, int AFillMode = 0x1);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
};

#pragma pack(pop)

class DELPHICLASS TdxPSReportRenderScreenCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSReportRenderScreenCanvas : public TdxPSReportRenderCanvas
{
	typedef TdxPSReportRenderCanvas inherited;
	
private:
	Vcl::Graphics::TCanvas* FSourceCanvas;
	
public:
	__fastcall TdxPSReportRenderScreenCanvas(void);
	__fastcall virtual ~TdxPSReportRenderScreenCanvas(void);
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall cxBkgndDrawPicture(Vcl::Graphics::TGraphic* APicture, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, TdxPicturePaintMode APictureMode, int APixelsNumerator, int APixelsDenominator, int AOffsetX = 0x0, int AOffsetY = 0x0);
}	/* namespace Dxpsreportrendercanvas */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSREPORTRENDERCANVAS)
using namespace Dxpsreportrendercanvas;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsreportrendercanvasHPP
