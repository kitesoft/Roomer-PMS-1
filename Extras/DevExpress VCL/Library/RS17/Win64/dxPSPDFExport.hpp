// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPDFExport.pas' rev: 24.00 (Win64)

#ifndef DxpspdfexportHPP
#define DxpspdfexportHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPSPDFExportCore.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPrnDlg.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpspdfexport
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSPDFReportExportProvider;
class PASCALIMPLEMENTATION TdxPSPDFReportExportProvider : public Dxpscore::TdxPSCustomReportExportProvider
{
	typedef Dxpscore::TdxPSCustomReportExportProvider inherited;
	
private:
	Dxpscore::TdxPSPDFReportExportOptions* FOptions;
	Dxpspdfexportcore::TdxPSPDFPage* FPage;
	Dxpspdfexportcore::TdxPSPDFPageContent* FPageContent;
	Dxpspdfexportcore::TdxPSPDFFile* FPDFFile;
	void __fastcall SetOptions(Dxpscore::TdxPSPDFReportExportOptions* AOptions);
	void __fastcall SetPage(Dxpspdfexportcore::TdxPSPDFPage* AValue);
	
protected:
	void __fastcall AssignSettings(Dxpspdfexportcore::TdxPSPDFFile* APDFFile);
	virtual void __fastcall ExportPage(int APageIndex);
	int __fastcall ScaleValue(int AValue);
	
public:
	__fastcall virtual TdxPSPDFReportExportProvider(Dxpscore::TBasedxReportLink* AReportLink);
	__fastcall virtual ~TdxPSPDFReportExportProvider(void);
	virtual void __fastcall Build(void);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	__property Dxpscore::TdxPSPDFReportExportOptions* Options = {read=FOptions, write=SetOptions};
	__property Dxpspdfexportcore::TdxPSPDFPage* Page = {read=FPage, write=SetPage};
	__property Dxpspdfexportcore::TdxPSPDFPageContent* PageContent = {read=FPageContent};
	__property Dxpspdfexportcore::TdxPSPDFFile* PDFFile = {read=FPDFFile};
};


class DELPHICLASS TdxPSPDFReportRenderCanvas;
class PASCALIMPLEMENTATION TdxPSPDFReportRenderCanvas : public Dxpsreportrendercanvas::TdxPSReportRenderScreenCanvas
{
	typedef Dxpsreportrendercanvas::TdxPSReportRenderScreenCanvas inherited;
	
private:
	System::Types::TRect FCustomDrawBounds;
	Vcl::Graphics::TMetafile* FCustomDrawMetaFile;
	Vcl::Graphics::TMetafileCanvas* FCustomDrawMetaFileCanvas;
	System::Types::TPoint FPageSize;
	TdxPSPDFReportExportProvider* FProvider;
	Cxgraphics::TcxRegion* FRegion;
	Cxclasses::TcxObjectList* FSavedRegions;
	System::Types::TRect __fastcall AbsoluteRect(const System::Types::TRect &R);
	Dxpspdfexportcore::TdxPSPDFPageContent* __fastcall GetPageContent(void);
	void __fastcall InternalDrawText(const System::Types::TRect &ABounds, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, unsigned AFormat, int AMaxLineCount, bool AVertical, Cxdrawtextutils::TcxVerticalTextOutDirection ADirection);
	void __fastcall InternalFillRect(const System::Types::TRect &R, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	void __fastcall SelectFonT(Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor);
	
protected:
	virtual void __fastcall DoFillEdge(HRGN ARegion, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AEdgeColor, bool AIsVerticalOrientation, System::TClass AEdgePattern);
	virtual void __fastcall DrawPictureStretch(Vcl::Graphics::TGraphic* APicture, const System::Types::TRect &R, int ANumerator, int ADenominator);
	virtual void __fastcall DrawPictureTile(Vcl::Graphics::TGraphic* APicture, const System::Types::TRect &R, int APictureWidth, int APictureHeight, int ANumerator, int ADenominator);
	virtual bool __fastcall GetIsPrinterCanvas(void);
	virtual bool __fastcall GetSupportsTransparentImagesDrawing(void);
	
public:
	__fastcall TdxPSPDFReportRenderCanvas(TdxPSPDFReportExportProvider* AProvider);
	__fastcall virtual ~TdxPSPDFReportRenderCanvas(void);
	virtual int __fastcall CalculateLineThickness(int AUnitsPerPixel, int AUnitsPerPoint);
	virtual void __fastcall DeviceToLogicalCoordinates(System::Types::TRect &R);
	virtual void __fastcall LogicalToDeviceCoordinates(System::Types::TRect &R);
	virtual void __fastcall SetCanvasExts(const System::Types::TPoint APageSize, Dxpsreportrendercanvas::TdxPSReportRenderCanvasMappingMode AMappingMode, int AScaleNumerator, int AScaleDenominator, const System::Types::TRect &AViewPort);
	void __fastcall ResetPageRegion(void);
	virtual void __fastcall UnprepareLogicalUnits(void);
	virtual Vcl::Graphics::TCanvas* __fastcall BeginCustomDraw(const System::Types::TRect &AClipBounds, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor AColor);
	virtual void __fastcall EndCustomDraw(Vcl::Graphics::TCanvas* &ACanvas);
	virtual int __fastcall ExcludeClipRect(const System::Types::TRect &R);
	virtual int __fastcall IntersectClipRgn(const System::Types::TRect &R);
	void __fastcall IntersectClipRgnEx(HRGN ARegion);
	virtual void __fastcall RestoreClipRgn(void);
	virtual void __fastcall RestoreState(void);
	virtual void __fastcall SaveClipRgn(void);
	virtual void __fastcall SaveState(void);
	virtual void __fastcall SetClipRect(const System::Types::TRect &R);
	virtual int __fastcall CalculateTextRect(const System::UnicodeString AText, System::Types::TRect &R, unsigned AFormat = (unsigned)(0x200), Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), int AMaxLineCount = 0x0, int ALeftIndent = 0x0, int ARightIndent = 0x0, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawText(System::Types::TRect &R, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), int AMaxLineCount = 0x0);
	void __fastcall DrawTextLine(const System::Types::TRect &ATextRect, const System::Types::TRect &AClipBounds, int ATextWidth, const System::WideString AText, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), Cxgraphics::TcxRotationAngle ADirection = (Cxgraphics::TcxRotationAngle)(0x0), int ABreakExtraSpacing = 0x0);
	virtual void __fastcall RotatedTextOut(const System::Types::TRect &ABounds, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, Cxdrawtextutils::TcxTextAlignX AAlignHorz = (Cxdrawtextutils::TcxTextAlignX)(0x1), Cxdrawtextutils::TcxTextAlignY AAlignVert = (Cxdrawtextutils::TcxTextAlignY)(0x1), bool AWordBreak = true, Cxdrawtextutils::TcxVerticalTextOutDirection ADirection = (Cxdrawtextutils::TcxVerticalTextOutDirection)(0x1));
	virtual void __fastcall DrawEllipseFrame(const System::Types::TRect &R, System::Uitypes::TColor AColor, int AThickness);
	virtual void __fastcall DrawExpandButton(System::Types::TRect &R, Dxpsreportrendercanvas::TdxCheckButtonEdgeStyle AEdgeStyle, Vcl::Graphics::TFont* AMarlettFont, Vcl::Graphics::TFont* ASymbolFont, bool AExpanded, bool AShadow, bool AFillInterior, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor ABackgroundColor, int ALineThickness);
	virtual void __fastcall DrawFrame(const System::Types::TRect &R, System::Uitypes::TColor ATopLeftColor, System::Uitypes::TColor ARightBottomColor, int ABorderWidth = 0x1, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall DrawRoundFrame(const System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor AColor, int AThickness);
	virtual void __fastcall FillEllipse(const System::Types::TRect &R, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	virtual void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall FillRectEx(const System::Types::TRect &R, System::Uitypes::TColor AColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	virtual void __fastcall FillRegion(HRGN ARegion, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	virtual void __fastcall FillRoundRect(System::Types::TRect &R, int AEllipseWidth, int AEllipseHeight, System::Uitypes::TColor ABackColor, System::Uitypes::TColor AForeColor, Dxpsfillpatterns::TdxPSFillPatternClass APattern, Vcl::Graphics::TBrush* APatternBrush);
	virtual bool __fastcall IsRectVisible(const System::Types::TRect &R);
	void __fastcall Pie(const System::Types::TRect &R, const System::Types::TPoint APoint1, const System::Types::TPoint APoint2, System::Uitypes::TColor AColor);
	virtual void __fastcall Polyline(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor AColor, int ALineWidth);
	virtual void __fastcall Polygon(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor AColor, System::Uitypes::TColor ABackgroundColor, int ALineWidth, int AFillMode = 0x1);
	__property Dxpspdfexportcore::TdxPSPDFPageContent* PageContent = {read=GetPageContent};
	__property System::Types::TPoint PageSize = {read=FPageSize};
	__property TdxPSPDFReportExportProvider* Provider = {read=FProvider};
	__property Cxgraphics::TcxRegion* Region = {read=FRegion};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxPSExportToPDF(Dxpscore::TBasedxReportLink* AReportLink);
extern PACKAGE bool __fastcall dxPSExportToPDFFile(const System::UnicodeString AFileName, Dxpscore::TBasedxReportLink* AReportLink, bool AShowSettingsDialog = true, Dxpscore::TdxPSPDFReportExportOptions* ASettings = (Dxpscore::TdxPSPDFReportExportOptions*)(0x0));
extern PACKAGE bool __fastcall dxPSExportToPDFStream(System::Classes::TStream* AStream, Dxpscore::TBasedxReportLink* AReportLink, bool AShowSettingsDialog = true, Dxpscore::TdxPSPDFReportExportOptions* ASettings = (Dxpscore::TdxPSPDFReportExportOptions*)(0x0));
}	/* namespace Dxpspdfexport */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPDFEXPORT)
using namespace Dxpspdfexport;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpspdfexportHPP
