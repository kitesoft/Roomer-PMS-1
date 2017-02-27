// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPDFMetaFileParser.pas' rev: 24.00 (Win32)

#ifndef DxpspdfmetafileparserHPP
#define DxpspdfmetafileparserHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxPSPDFExportCore.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxPSPDFExport.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpspdfmetafileparser
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSPDFMetaFileGdiObjectItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPDFMetaFileGdiObjectItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FColor;
	NativeUInt FHandle;
	System::TObject* FSourceObject;
	
public:
	__fastcall TdxPSPDFMetaFileGdiObjectItem(NativeUInt AHandle, System::TObject* ASourceObject, System::Uitypes::TColor AColor);
	__fastcall virtual ~TdxPSPDFMetaFileGdiObjectItem(void);
	__property System::Uitypes::TColor Color = {read=FColor, nodefault};
	__property NativeUInt Handle = {read=FHandle, nodefault};
	__property System::TObject* SourceObject = {read=FSourceObject};
};

#pragma pack(pop)

class DELPHICLASS TdxPSPDFMetaFileGdiObjectList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPDFMetaFileGdiObjectList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	TdxPSPDFMetaFileGdiObjectItem* __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	
public:
	HBRUSH __fastcall CreateBrush(const tagLOGBRUSH32 &ABrushInfo);
	HFONT __fastcall CreateFont(const tagEXTLOGFONTW &AFontInfo);
	HPEN __fastcall CreatePen(const tagLOGPEN &APenInfo);
	HPEN __fastcall CreatePenEx(const tagEXTLOGPEN32 &APenInfo);
	bool __fastcall FindObject(NativeUInt AHandle, TdxPSPDFMetaFileGdiObjectItem* &AObject);
	__property TdxPSPDFMetaFileGdiObjectItem* Items[int Index] = {read=GetItem};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxPSPDFMetaFileGdiObjectList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSPDFMetaFileGdiObjectList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSPDFMetaFileCanvasState;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPDFMetaFileCanvasState : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FBackgroundColor;
	int FBackgroundMode;
	Vcl::Graphics::TBrush* FBrush;
	int FMapMode;
	Vcl::Graphics::TPen* FPen;
	int FPolyFillMode;
	System::Uitypes::TColor FTextColor;
	tagXFORM FTransform;
	System::Types::TSize FViewPortExt;
	System::Types::TPoint FViewPortOrg;
	System::Types::TSize FWindowExt;
	System::Types::TPoint FWindowOrg;
	
public:
	__fastcall virtual TdxPSPDFMetaFileCanvasState(void);
	__fastcall virtual ~TdxPSPDFMetaFileCanvasState(void);
	void __fastcall Assign(TdxPSPDFMetaFileCanvasState* ASource);
	TdxPSPDFMetaFileCanvasState* __fastcall Clone(void);
	__property System::Uitypes::TColor BackgroundColor = {read=FBackgroundColor, write=FBackgroundColor, nodefault};
	__property int BackgroundMode = {read=FBackgroundMode, write=FBackgroundMode, nodefault};
	__property Vcl::Graphics::TBrush* Brush = {read=FBrush};
	__property int MapMode = {read=FMapMode, write=FMapMode, nodefault};
	__property Vcl::Graphics::TPen* Pen = {read=FPen};
	__property int PolyFillMode = {read=FPolyFillMode, write=FPolyFillMode, nodefault};
	__property System::Uitypes::TColor TextColor = {read=FTextColor, write=FTextColor, nodefault};
	__property tagXFORM Transform = {read=FTransform, write=FTransform};
	__property System::Types::TSize ViewPortExt = {read=FViewPortExt, write=FViewPortExt};
	__property System::Types::TPoint ViewPortOrg = {read=FViewPortOrg, write=FViewPortOrg};
	__property System::Types::TSize WindowExt = {read=FWindowExt, write=FWindowExt};
	__property System::Types::TPoint WindowOrg = {read=FWindowOrg, write=FWindowOrg};
};

#pragma pack(pop)

class DELPHICLASS TdxPSPDFMetaFileTextInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPDFMetaFileTextInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TFont* FFont;
	int FOptions;
	System::WideString FText;
	System::Types::TRect FTextBounds;
	int FTextWidth;
	int __fastcall CalculateTextWidth(const Winapi::Windows::PEMRExtTextOut R);
	
public:
	__fastcall TdxPSPDFMetaFileTextInfo(void);
	__fastcall virtual ~TdxPSPDFMetaFileTextInfo(void);
	bool __fastcall Concatenate(TdxPSPDFMetaFileTextInfo* AInfo);
	void __fastcall Initialize(const Winapi::Windows::PEMRExtTextOut R, bool AIsUnicode, Vcl::Graphics::TFont* AFont);
	__property Vcl::Graphics::TFont* Font = {read=FFont};
	__property int Options = {read=FOptions, nodefault};
	__property System::WideString Text = {read=FText};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
	__property int TextWidth = {read=FTextWidth, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxPSPDFMetaFileExportProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSPDFMetaFileExportProvider : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TPoint FBaseWindowOrg;
	TdxPSPDFMetaFileGdiObjectList* FGdiObjectList;
	System::Types::TPoint FMoveToPoint;
	Dxpspdfexport::TdxPSPDFReportRenderCanvas* FPDFCanvas;
	TdxPSPDFMetaFileTextInfo* FPrevTextOut;
	Cxclasses::TcxObjectList* FSavedStates;
	float FScaleFactor;
	TdxPSPDFMetaFileCanvasState* FState;
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	Vcl::Graphics::TBrush* __fastcall GetBrush(void);
	bool __fastcall GetHasBackground(void);
	Dxpspdfexportcore::TdxPSPDFPageContent* __fastcall GetPageContent(void);
	System::Uitypes::TColor __fastcall GetPatternColor(void);
	Vcl::Graphics::TPen* __fastcall GetPen(void);
	int __fastcall GetPenWidth(void);
	void __fastcall OutputPrevTextInfo(void);
	void __fastcall SelectStockObject(int AIndex);
	System::Types::TRect __fastcall ValidateRect(const System::Types::TRect &R);
	
protected:
	bool __fastcall CheckROP(unsigned ARop);
	Cxgraphics::TcxRegion* __fastcall CreateRegion(Winapi::Windows::PRgnData ARgnData, int ARgnDataSize);
	Cxgraphics::TcxBitmap* __fastcall ExtractBitmap(void * ARecordAddress, const System::Types::TRect &ARect, unsigned ABitmapInfoOffset, unsigned ABitmapBitsOffset, unsigned ABitmapBitsSize, unsigned AColorUsage);
	void __fastcall DrawBitmap(const System::Types::TRect &ADest, const System::Types::TRect &ASource, void * ARecordAddress, unsigned ABitmapInfoOffset, unsigned ABitmapBitsOffset, unsigned ABitmapBitsSize, unsigned AColorUsage);
	void __fastcall TextOut(TdxPSPDFMetaFileTextInfo* AInfo);
	System::Types::TPoint __fastcall ConvertPoint(const System::Types::TPoint &P, bool AConvertPosition = true);
	Cxgraphics::TPointArray __fastcall ConvertPoints(System::PByte P, int ACount, bool AIsSmallPoints);
	System::Types::TRect __fastcall ConvertRect(const System::Types::TRect &R);
	Cxgraphics::TcxRegion* __fastcall ConvertRegion(HRGN ARegion);
	int __fastcall ConvertValue(int AValue, float AMapScale, float AViewPortOffset, float AWorldOffset, float AWorldScale, bool AConvertPosition = false);
	int __fastcall ConvertValueX(int AValue, bool AConvertPosition = false);
	int __fastcall ConvertValueY(int AValue, bool AConvertPosition = false);
	void __fastcall EmfAlphaBlend(const PEMRAlphaBlend ARecord);
	void __fastcall EmfBitBlt(const Winapi::Windows::PEMRBitBlt ARecord);
	void __fastcall EmfCreateBrush(const Winapi::Windows::PEMRCreateBrushIndirect ARecord, Winapi::Windows::PHandleTable ATable);
	void __fastcall EmfCreateFont(const Winapi::Windows::PEMRExtCreateFontIndirect ARecord, Winapi::Windows::PHandleTable ATable);
	void __fastcall EmfCreatePen(const Winapi::Windows::PEMRCreatePen ARecord, Winapi::Windows::PHandleTable ATable);
	void __fastcall EmfCreatePenEx(const Winapi::Windows::PEMRExtCreatePen ARecord, Winapi::Windows::PHandleTable ATable);
	void __fastcall EmfDeleteObject(const Winapi::Windows::PEMRSelectObject ARecord, Winapi::Windows::PHandleTable ATable);
	void __fastcall EmfEllipse(const System::Types::TRect &R);
	void __fastcall EmfExcludeClipRect(const Winapi::Windows::PEMRExcludeClipRect ARecord);
	void __fastcall EmfExtTextOut(const Winapi::Windows::PEMRExtTextOut ARecord, bool AIsUnicode);
	void __fastcall EmfFillRgn(const tagEMRFILLRGN &ARecord, Winapi::Windows::PHandleTable ATable);
	void __fastcall EmfIntersectClipRect(const Winapi::Windows::PEMRExcludeClipRect ARecord);
	void __fastcall EmfLineTo(const tagEMRLINETO &ARecord);
	void __fastcall EmfMaskBlt(const Winapi::Windows::PEMRMaskBlt ARecord);
	void __fastcall EmfModifyWorldTransform(const Winapi::Windows::PEMRModifyWorldTransform AInfo);
	void __fastcall EmfPaintRgn(const tagEMRINVERTRGN &ARecord);
	void __fastcall EmfPie(const tagEMRARC &ARecord, Winapi::Windows::PHandleTable ATable);
	void __fastcall EmfPolygon(const Winapi::Windows::PEMRPolyline APolygon, bool ASmallPoints);
	void __fastcall EmfPolyline(const Winapi::Windows::PEMRPolyline P, bool ASmallPoints);
	void __fastcall EmfPolyPolygon(const Winapi::Windows::PEMRPolyPolyline APolygon, bool ASmallPoints);
	void __fastcall EmfPolyPolyline(const Winapi::Windows::PEMRPolyPolyline APolyline, bool ASmallPoints);
	void __fastcall EmfRectangle(const System::Types::TRect &R);
	void __fastcall EmfRestoreState(void);
	void __fastcall EmfRoundRect(const System::Types::TRect &R, const System::Types::TSize &ACorners);
	void __fastcall EmfSaveState(void);
	void __fastcall EmfSelectClipRgn(const Winapi::Windows::PEMRExtSelectClipRgn ARecord);
	void __fastcall EmfSelectObject(const Winapi::Windows::PEMRSelectObject ARecord, Winapi::Windows::PHandleTable ATable);
	void __fastcall EmfSetPixel(const tagEMRSETPIXELV &ARecord);
	void __fastcall EmfSetWindowOrg(const Winapi::Windows::PEMRSetViewportOrgEx ARecord);
	void __fastcall EmfStretctBlt(const Winapi::Windows::PEMRStretchBlt ARecord);
	void __fastcall EmfStretctDIBits(const Winapi::Windows::PEMRStretchDIBits ARecord);
	void __fastcall ProcessMetaFileObject(Winapi::Windows::PHandleTable ATable, int AObjectsInTable, const Winapi::Windows::PEnhMetaRecord ARecord);
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	__property System::Types::TPoint BaseWindowOrg = {read=FBaseWindowOrg};
	__property Vcl::Graphics::TBrush* Brush = {read=GetBrush};
	__property TdxPSPDFMetaFileGdiObjectList* GdiObjectList = {read=FGdiObjectList};
	__property bool HasBackground = {read=GetHasBackground, nodefault};
	__property Dxpspdfexportcore::TdxPSPDFPageContent* PageContent = {read=GetPageContent};
	__property System::Uitypes::TColor PatternColor = {read=GetPatternColor, nodefault};
	__property Vcl::Graphics::TPen* Pen = {read=GetPen};
	__property int PenWidth = {read=GetPenWidth, nodefault};
	__property float ScaleFactor = {read=FScaleFactor};
	__property TdxPSPDFMetaFileCanvasState* State = {read=FState};
	
public:
	__fastcall virtual TdxPSPDFMetaFileExportProvider(Dxpspdfexport::TdxPSPDFReportRenderCanvas* APDFCanvas);
	__fastcall virtual ~TdxPSPDFMetaFileExportProvider(void);
	virtual void __fastcall Render(Vcl::Graphics::TMetafile* AMetaFile, const System::Types::TRect &R, float AScaleFactor);
	__property Dxpspdfexport::TdxPSPDFReportRenderCanvas* PDFCanvas = {read=FPDFCanvas};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxPDFExportMetaFile(Dxpspdfexport::TdxPSPDFReportRenderCanvas* APDFCanvas, Vcl::Graphics::TMetafile* AMetaFile, const System::Types::TRect &R, int ANumerator, int ADenominator);
}	/* namespace Dxpspdfmetafileparser */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPDFMETAFILEPARSER)
using namespace Dxpspdfmetafileparser;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpspdfmetafileparserHPP
