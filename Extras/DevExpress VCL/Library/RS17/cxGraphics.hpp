// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGraphics.pas' rev: 24.00 (Win32)

#ifndef CxgraphicsHPP
#define CxgraphicsHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgraphics
{
//-- type declarations -------------------------------------------------------
__interface IcxFontListener;
typedef System::DelphiInterface<IcxFontListener> _di_IcxFontListener;
__interface  INTERFACE_UUID("{B144DD7E-0B27-439A-B908-FC3ACFE6A2D3}") IcxFontListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall Changed(System::TObject* Sender, Vcl::Graphics::TFont* AFont) = 0 ;
};

enum TcxBorder : unsigned char { bLeft, bTop, bRight, bBottom };

typedef System::Set<TcxBorder, TcxBorder::bLeft, TcxBorder::bBottom>  TcxBorders;

typedef HBRUSH TBrushHandle;

typedef System::DynamicArray<System::Types::TPoint> TPointArray;

typedef System::DynamicArray<System::Types::TRect> TRectArray;

typedef System::Int8 TcxColorPart;

enum TcxGridLines : unsigned char { glBoth, glNone, glVertical, glHorizontal };

struct TcxViewParams;
typedef TcxViewParams *PcxViewParams;

struct DECLSPEC_DRECORD TcxViewParams
{
public:
	Vcl::Graphics::TBitmap* Bitmap;
	System::Uitypes::TColor Color;
	Vcl::Graphics::TFont* Font;
	System::Uitypes::TColor TextColor;
};


__interface IcxPaintControlsHelper;
typedef System::DelphiInterface<IcxPaintControlsHelper> _di_IcxPaintControlsHelper;
__interface  INTERFACE_UUID("{7EFAF634-E8D2-489D-9603-FCFC03ACA460}") IcxPaintControlsHelper  : public System::IInterface 
{
	
public:
	virtual bool __fastcall AllowDrawEdgesAndBorders(void) = 0 ;
};

__interface IcxImageCollectionListener;
typedef System::DelphiInterface<IcxImageCollectionListener> _di_IcxImageCollectionListener;
__interface  INTERFACE_UUID("{FDFF372B-F49E-40C9-9E03-E0D6B110774A}") IcxImageCollectionListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall ImageCollectionChanged(void) = 0 ;
	virtual void __fastcall ImageCollectionDestroyed(void) = 0 ;
};

struct DECLSPEC_DRECORD TdxHSV
{
public:
	double H;
	double S;
	double V;
};


struct DECLSPEC_DRECORD TdxHSL
{
public:
	double H;
	double S;
	double L;
};


typedef System::Uitypes::TImageIndex TcxImageIndex;

typedef HRGN TcxRegionHandle;

enum TcxRegionOperation : unsigned char { roSet, roAdd, roSubtract, roIntersect };

class DELPHICLASS TcxRegion;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxRegion : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	HRGN FHandle;
	System::Types::TRect __fastcall GetBoundsRect(void);
	bool __fastcall GetIsEmpty(void);
	
protected:
	void __fastcall DestroyHandle(void);
	void __fastcall DoCombine(HRGN ARegionHandle, TcxRegionOperation AOperation);
	
public:
	__fastcall TcxRegion(HRGN AHandle)/* overload */;
	__fastcall TcxRegion(const System::Types::TRect &ABounds)/* overload */;
	__fastcall TcxRegion(void)/* overload */;
	__fastcall TcxRegion(int ALeft, int ATop, int ARight, int ABottom)/* overload */;
	__fastcall TcxRegion(HWND AHandle, int ADummy)/* overload */;
	__fastcall TcxRegion(int ALeft, int ATop, int ARight, int ABottom, int AWidthEllepse, int AHeightEllepse)/* overload */;
	__fastcall TcxRegion(const System::Types::TRect &ABounds, int AWidthEllepse, int AHeightEllepse)/* overload */;
	__fastcall virtual ~TcxRegion(void);
	void __fastcall Combine(TcxRegion* ARegion, TcxRegionOperation AOperation, bool ADestroyRegion = true)/* overload */;
	void __fastcall Combine(const System::Types::TRect &R, TcxRegionOperation AOperation)/* overload */;
	bool __fastcall IsEqual(TcxRegion* ARegion)/* overload */;
	bool __fastcall IsEqual(HRGN ARegionHandle)/* overload */;
	void __fastcall Offset(const System::Types::TPoint &P)/* overload */;
	void __fastcall Offset(int DX, int DY)/* overload */;
	bool __fastcall PtInRegion(const System::Types::TPoint &Pt)/* overload */;
	bool __fastcall PtInRegion(int X, int Y)/* overload */;
	bool __fastcall RectInRegion(const System::Types::TRect &R)/* overload */;
	bool __fastcall RectInRegion(int ALeft, int ATop, int ARight, int ABottom)/* overload */;
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect};
	__property HRGN Handle = {read=FHandle, write=FHandle, nodefault};
	__property bool IsEmpty = {read=GetIsEmpty, nodefault};
};

#pragma pack(pop)

enum TcxRotationAngle : unsigned char { ra0, raPlus90, raMinus90, ra180 };

struct DECLSPEC_DRECORD TcxCanvasState
{
public:
	Vcl::Graphics::TFont* Font;
	Vcl::Graphics::TBrush* Brush;
	Vcl::Graphics::TPen* Pen;
};


typedef System::DynamicArray<TcxCanvasState> TcxCanvasStates;

struct DECLSPEC_DRECORD TcxDCState
{
public:
	NativeUInt Handle;
	int State;
};


typedef System::DynamicArray<TcxDCState> TcxDCStates;

class DELPHICLASS TcxCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCanvas : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Graphics::TCanvas* FCanvas;
	TcxDCStates FSavedDCs;
	System::Classes::TList* FSavedRegions;
	TcxCanvasStates FSavedStates;
	Vcl::Graphics::TBrush* __fastcall GetBrush(void);
	int __fastcall GetCopyMode(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	HDC __fastcall GetHandle(void);
	Vcl::Graphics::TPen* __fastcall GetPen(void);
	System::Types::TPoint __fastcall GetViewportOrg(void);
	void __fastcall SetBrush(Vcl::Graphics::TBrush* Value);
	void __fastcall SetCopyMode(int Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetPen(Vcl::Graphics::TPen* Value);
	void __fastcall SetPixel(int X, int Y, System::Uitypes::TColor Value);
	void __fastcall SetViewportOrg(const System::Types::TPoint &P);
	
protected:
	virtual System::Types::TPoint __fastcall GetDCOrigin(void);
	virtual System::Types::TPoint __fastcall GetWindowOrg(void);
	virtual void __fastcall SetWindowOrg(const System::Types::TPoint &P);
	void __fastcall SynchronizeObjects(NativeUInt ADC)/* overload */;
	void __fastcall SynchronizeObjects(Vcl::Graphics::TCanvas* ACanvas, NativeUInt ADC)/* overload */;
	
public:
	__fastcall virtual TcxCanvas(Vcl::Graphics::TCanvas* ACanvas);
	__fastcall virtual ~TcxCanvas(void);
	void __fastcall AngleArc(int X, int Y, unsigned Radius, float StartAngle, float SweepAngle);
	void __fastcall Arc(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void __fastcall ArcTo(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void __fastcall BrushCopy(const System::Types::TRect &Dest, Vcl::Graphics::TBitmap* Bitmap, const System::Types::TRect &Source, System::Uitypes::TColor Color);
	void __fastcall Chord(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
	void __fastcall CopyRect(const System::Types::TRect &Dest, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &Source);
	void __fastcall Draw(int X, int Y, Vcl::Graphics::TGraphic* Graphic)/* overload */;
	void __fastcall Draw(int X, int Y, Vcl::Graphics::TGraphic* Graphic, System::Byte Opacity)/* overload */;
	void __fastcall Ellipse(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall Ellipse(const System::Types::TRect &Rect)/* overload */;
	void __fastcall FloodFill(int X, int Y, System::Uitypes::TColor Color, Vcl::Graphics::TFillStyle FillStyle);
	bool __fastcall HandleAllocated(void);
	void __fastcall LineTo(int X, int Y);
	void __fastcall MoveTo(int X, int Y);
	void __fastcall Pie(int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4)/* overload */;
	void __fastcall PolyBezier(System::Types::TPoint const *Points, const int Points_Size);
	void __fastcall PolyBezierTo(System::Types::TPoint const *Points, const int Points_Size);
	void __fastcall Polygon(System::Types::TPoint const *Points, const int Points_Size);
	void __fastcall Polyline(System::Types::TPoint const *Points, const int Points_Size);
	void __fastcall Rectangle(const System::Types::TRect &R)/* overload */;
	void __fastcall Rectangle(int X1, int Y1, int X2, int Y2)/* overload */;
	void __fastcall Rectangle(const System::Types::TRect &R, const TcxViewParams &AParams, const TcxBorders ABorders = TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ALineWidth = 0x1, bool AExcludeRect = false)/* overload */;
	void __fastcall Refresh(void);
	void __fastcall RoundRect(int X1, int Y1, int X2, int Y2, int X3, int Y3);
	void __fastcall StretchDraw(const System::Types::TRect &Rect, Vcl::Graphics::TGraphic* Graphic);
	void __fastcall TextOut(int X, int Y, const System::UnicodeString Text);
	void __fastcall AlignMultiLineTextRectVertically(System::Types::TRect &R, const System::UnicodeString AText, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AWordBreak, bool AShowPrefix, bool AEnabled = true, bool ADontBreakChars = false, bool AEndEllipsis = false);
	void __fastcall DrawComplexFrame(const System::Types::TRect &R, System::Uitypes::TColor ALeftTopColor, System::Uitypes::TColor ARightBottomColor, TcxBorders ABorders = (TcxBorders() << TcxBorder::bLeft << TcxBorder::bTop << TcxBorder::bRight << TcxBorder::bBottom ), int ABorderWidth = 0x1);
	void __fastcall DrawDesignSelection(const System::Types::TRect &ARect, int AWidth = 0x2);
	void __fastcall DrawEdge(const System::Types::TRect &R, bool ASunken, bool AOuter, TcxBorders ABorders = (TcxBorders() << TcxBorder::bLeft << TcxBorder::bTop << TcxBorder::bRight << TcxBorder::bBottom ));
	void __fastcall DrawFocusRect(const System::Types::TRect &R);
	void __fastcall DrawFocusRectEx(const System::Types::TRect &R, TcxBorders ABorders, bool AExclude = false);
	void __fastcall DrawGlyph(int X, int Y, Vcl::Graphics::TBitmap* AGlyph, bool AEnabled = true, System::Uitypes::TColor ABackgroundColor = (System::Uitypes::TColor)(0x1fffffff));
	void __fastcall DrawImage(Vcl::Imglist::TCustomImageList* Images, int X, int Y, int Index, bool Enabled = true);
	void __fastcall DrawRegion(TcxRegion* ARegion, System::Uitypes::TColor AContentColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ABorderWidth = 0x1, int ABorderHeight = 0x1)/* overload */;
	void __fastcall DrawRegion(HRGN ARegion, System::Uitypes::TColor AContentColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ABorderWidth = 0x1, int ABorderHeight = 0x1)/* overload */;
	void __fastcall DrawTexT(const System::UnicodeString Text, const System::Types::TRect &R, int Flags, bool Enabled = true)/* overload */;
	void __fastcall DrawTexT(const System::UnicodeString Text, const System::Types::TRect &R, int Flags, bool Enabled, TcxRotationAngle ARotationAngle)/* overload */;
	void __fastcall DrawTexT(const System::UnicodeString Text, const System::Types::TRect &R, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis)/* overload */;
	void __fastcall ExcludeFrameRect(const System::Types::TRect &R, int ALineWidth = 0x1, TcxBorders ABorders = (TcxBorders() << TcxBorder::bLeft << TcxBorder::bTop << TcxBorder::bRight << TcxBorder::bBottom ));
	void __fastcall FillRect(const System::Types::TRect &R, System::Uitypes::TColor AColor)/* overload */;
	void __fastcall FillRect(const System::Types::TRect &R, Vcl::Graphics::TBitmap* ABitmap = (Vcl::Graphics::TBitmap*)(0x0), bool AExcludeRect = false)/* overload */;
	void __fastcall FillRect(const System::Types::TRect &R, const TcxViewParams &AParams, bool AExcludeRect = false)/* overload */;
	void __fastcall FillRegion(TcxRegion* ARegion, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
	void __fastcall FillRegion(HRGN ARegion, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
	void __fastcall FlipHorizontally(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall FrameRect(const System::Types::TRect &R, System::Uitypes::TColor Color = (System::Uitypes::TColor)(0x20000000), int ALineWidth = 0x1, const TcxBorders ABorders = (TcxBorders() << TcxBorder::bLeft << TcxBorder::bTop << TcxBorder::bRight << TcxBorder::bBottom ), bool AExcludeFrame = false)/* overload */;
	void __fastcall FrameRegion(TcxRegion* ARegion, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), int ABorderWidth = 0x1, int ABorderHeight = 0x1)/* overload */;
	void __fastcall FrameRegion(HRGN ARegion, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), int ABorderWidth = 0x1, int ABorderHeight = 0x1)/* overload */;
	int __fastcall FontHeight(Vcl::Graphics::TFont* AFont);
	void __fastcall InvertFrame(const System::Types::TRect &R, int ABorderSize);
	void __fastcall InvertRect(const System::Types::TRect &R);
	void __fastcall Pie(const System::Types::TRect &R, const System::Types::TPoint &ARadial1, const System::Types::TPoint &ARadial2)/* overload */;
	void __fastcall Pie(const System::Types::TRect &R, int AStartAngle, int ASweepAngle)/* overload */;
	void __fastcall RotateBitmap(Vcl::Graphics::TBitmap* ABitmap, TcxRotationAngle ARotationAngle, bool AFlipVertically = false);
	System::Types::TSize __fastcall TextExtent(const System::UnicodeString Text)/* overload */;
	void __fastcall TextExtent(const System::UnicodeString Text, System::Types::TRect &R, int Flags)/* overload */;
	int __fastcall TextHeight(const System::UnicodeString Text);
	int __fastcall TextWidth(const System::UnicodeString Text);
	void __fastcall TransparentDraw(int X, int Y, Vcl::Graphics::TBitmap* ABitmap, System::Byte AAlpha, Vcl::Graphics::TBitmap* ABackground = (Vcl::Graphics::TBitmap*)(0x0));
	void __fastcall RestoreDC(void);
	void __fastcall SaveDC(void);
	void __fastcall RestoreClipRegion(void);
	void __fastcall SaveClipRegion(void);
	void __fastcall RestoreState(void);
	void __fastcall SaveState(void);
	void __fastcall GetParams(TcxViewParams &AParams);
	void __fastcall SetParams(const TcxViewParams &AParams);
	void __fastcall SetBrushColor(System::Uitypes::TColor Value);
	void __fastcall SetFontAngle(int Value);
	void __fastcall GetTextStringsBounds(System::UnicodeString Text, const System::Types::TRect &R, int Flags, bool Enabled, TRectArray &ABounds);
	void __fastcall BeginPath(void);
	void __fastcall EndPath(void);
	TcxRegion* __fastcall PathToRegion(bool AConsiderOrigin = true);
	void __fastcall WidenPath(void);
	void __fastcall ExcludeClipRect(const System::Types::TRect &R);
	void __fastcall IntersectClipRect(const System::Types::TRect &R);
	TcxRegion* __fastcall GetClipRegion(bool AConsiderOrigin = true);
	void __fastcall SetClipRegion(TcxRegion* ARegion, TcxRegionOperation AOperation, bool ADestroyRegion = true, bool AConsiderOrigin = true);
	bool __fastcall RectFullyVisible(const System::Types::TRect &R);
	bool __fastcall RectVisible(const System::Types::TRect &R);
	__property Vcl::Graphics::TBrush* Brush = {read=GetBrush, write=SetBrush};
	__property Vcl::Graphics::TCanvas* Canvas = {read=FCanvas, write=FCanvas};
	__property int CopyMode = {read=GetCopyMode, write=SetCopyMode, nodefault};
	__property System::Types::TPoint DCOrigin = {read=GetDCOrigin};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont};
	__property HDC Handle = {read=GetHandle, nodefault};
	__property Vcl::Graphics::TPen* Pen = {read=GetPen, write=SetPen};
	__property System::Uitypes::TColor Pixels[int X][int Y] = {write=SetPixel};
	__property System::Types::TPoint ViewportOrg = {read=GetViewportOrg, write=SetViewportOrg};
	__property System::Types::TPoint WindowOrg = {read=GetWindowOrg, write=SetWindowOrg};
};

#pragma pack(pop)

class DELPHICLASS TcxControlCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxControlCanvas : public TcxCanvas
{
	typedef TcxCanvas inherited;
	
private:
	System::Types::TPoint FBrushOrigin;
	System::Types::TPoint FOrigin;
	
protected:
	virtual System::Types::TPoint __fastcall GetDCOrigin(void);
	virtual System::Types::TPoint __fastcall GetWindowOrg(void);
	virtual void __fastcall SetWindowOrg(const System::Types::TPoint &P);
	
public:
	void __fastcall BeginPaint(void);
	void __fastcall EndPaint(void);
	__property System::Types::TPoint BrushOrigin = {read=FBrushOrigin, write=FBrushOrigin};
	__property System::Types::TPoint Origin = {read=FOrigin, write=FOrigin};
public:
	/* TcxCanvas.Create */ inline __fastcall virtual TcxControlCanvas(Vcl::Graphics::TCanvas* ACanvas) : TcxCanvas(ACanvas) { }
	/* TcxCanvas.Destroy */ inline __fastcall virtual ~TcxControlCanvas(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxScreenCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxScreenCanvas : public TcxCanvas
{
	typedef TcxCanvas inherited;
	
public:
	__fastcall virtual TcxScreenCanvas(void);
	__fastcall virtual ~TcxScreenCanvas(void);
	void __fastcall Dormant(void);
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxPaintCanvasState
{
public:
	Vcl::Graphics::TCanvas* PrevCanvas;
	int FSaveDC;
};


typedef System::DynamicArray<TcxPaintCanvasState> TcxPaintCanvasStates;

class DELPHICLASS TcxPaintCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPaintCanvas : public TcxCanvas
{
	typedef TcxCanvas inherited;
	
private:
	int FCounter;
	TcxPaintCanvasStates FSavedStates;
	void __fastcall SetCapacity(int AValue);
	
public:
	__fastcall TcxPaintCanvas(void);
	__fastcall virtual ~TcxPaintCanvas(void);
	void __fastcall BeginPaint(NativeUInt ADC)/* overload */;
	void __fastcall BeginPaint(Vcl::Graphics::TCanvas* ACanvas)/* overload */;
	void __fastcall EndPaint(void);
};

#pragma pack(pop)

class DELPHICLASS TcxBitmap;
class PASCALIMPLEMENTATION TcxBitmap : public Vcl::Graphics::TBitmap
{
	typedef Vcl::Graphics::TBitmap inherited;
	
private:
	bool FCompressData;
	TcxCanvas* FcxCanvas;
	int FLockCount;
	bool FModified;
	HIDESBASE TcxCanvas* __fastcall GetCanvas(void);
	System::Types::TRect __fastcall GetClientRect(void);
	void __fastcall CompressByBlock(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize, int ABlockSize);
	void __fastcall DecompressByBlock(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize, int ABlockSize);
	void __fastcall Compress(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize);
	void __fastcall Decompress1(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize);
	void __fastcall Decompress2(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, int ASize);
	
protected:
	virtual void __fastcall Changed(System::TObject* Sender);
	bool __fastcall ChangeLocked(void);
	virtual void __fastcall Initialize(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat);
	virtual void __fastcall Update(void);
	virtual void __fastcall ReadData(System::Classes::TStream* Stream);
	virtual void __fastcall WriteData(System::Classes::TStream* Stream);
	
public:
	__fastcall virtual TcxBitmap(void)/* overload */;
	__fastcall TcxBitmap(const System::Types::TRect &ARect)/* overload */;
	__fastcall virtual TcxBitmap(int AWidth, int AHeight)/* overload */;
	__fastcall TcxBitmap(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */;
	__fastcall TcxBitmap(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */;
	__fastcall virtual ~TcxBitmap(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(bool AForceUpdate = true);
	void __fastcall CopyBitmap(Vcl::Graphics::TBitmap* ASrcBitmap, unsigned ACopyMode = (unsigned)(0xcc0020))/* overload */;
	void __fastcall CopyBitmap(Vcl::Graphics::TBitmap* ASrcBitmap, const System::Types::TRect &ADestRect, const System::Types::TPoint &ASrcTopLeft, unsigned ACopyMode = (unsigned)(0xcc0020))/* overload */;
	void __fastcall Rotate(TcxRotationAngle ARotationAngle, bool AFlipVertically = false);
	virtual void __fastcall SetSize(int AWidth, int AHeight)/* overload */;
	HIDESBASE void __fastcall SetSize(const System::Types::TRect &ARect)/* overload */;
	__property bool CompressData = {read=FCompressData, write=FCompressData, nodefault};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property TcxCanvas* cxCanvas = {read=GetCanvas};
};


enum TcxImageDrawMode : unsigned char { idmNormal, idmDisabled, idmFaded, idmGrayScale, idmDingy, idmShadowed };

enum TcxImageFitMode : unsigned char { ifmNormal, ifmStretch, ifmProportionalStretch, ifmFit, ifmFill };

enum TcxBitmapTransformationMode : unsigned char { btmDingy, btmDirty, btmGrayScale, btmSetOpaque, btmMakeMask, btmFade, btmDisable, btmCorrectBlend, btmHatch, btmClear, btmResetAlpha };

typedef void __fastcall (__closure *TcxBitmapTransformationProc)(tagRGBQUAD &AColor);

typedef bool __fastcall (*TcxDrawImageProc)(Vcl::Graphics::TCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, Vcl::Graphics::TBitmap* AGlyph, const System::Types::TRect &ARect, TcxImageDrawMode ADrawMode);

struct DECLSPEC_DRECORD TcxColorTransitionMap
{
public:
	float RedScale;
	float GreenScale;
	float BlueScale;
	System::Byte SrcAlpha;
	System::Byte SrcConstantAlpha;
};


struct DECLSPEC_DRECORD TcxHatchData
{
public:
	tagRGBQUAD Color1;
	System::Byte Alpha1;
	tagRGBQUAD Color2;
	System::Byte Alpha2;
	System::Byte Step;
};


class DELPHICLASS TcxBitmap32;
class PASCALIMPLEMENTATION TcxBitmap32 : public TcxBitmap
{
	typedef TcxBitmap inherited;
	
private:
	bool __fastcall GetIsAlphaUsed(void);
	
protected:
	virtual void __fastcall Update(void);
	void __fastcall Resize(int ANewWidth, int ANewHeight, bool AStretch, bool ASmooth, System::Uitypes::TColor AFillColor = (System::Uitypes::TColor)(0x1fffffff));
	
public:
	__fastcall TcxBitmap32(int AWidth, int AHeight, bool AClear)/* overload */;
	__fastcall TcxBitmap32(const System::Types::TRect &ARect, bool AClear)/* overload */;
	__fastcall virtual TcxBitmap32(int AWidth, int AHeight)/* overload */;
	void __fastcall GetBitmapColors(/* out */ Dxcore::TRGBColors &AColors);
	void __fastcall SetBitmapColors(const Dxcore::TRGBColors AColors);
	void __fastcall AlphaBlend(TcxBitmap32* ADestBitmap, const System::Types::TRect &ARect, bool ASmoothImage, System::Byte AConstantAlpha = (System::Byte)(0xff));
	virtual void __fastcall Clear(void);
	void __fastcall Darken(System::Byte APercent);
	void __fastcall Filter(TcxBitmap32* AMaskBitmap);
	void __fastcall Invert(void);
	void __fastcall Lighten(System::Byte APercent);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* Stream);
	void __fastcall MakeOpaque(void);
	void __fastcall RecoverTransparency(System::Uitypes::TColor ATransparentColor);
	void __fastcall SetAlphaChannel(System::Byte Alpha);
	__property bool IsAlphaUsed = {read=GetIsAlphaUsed, nodefault};
public:
	/* TcxBitmap.Create */ inline __fastcall virtual TcxBitmap32(void)/* overload */ : TcxBitmap() { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxBitmap32(const System::Types::TRect &ARect)/* overload */ : TcxBitmap(ARect) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxBitmap32(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : TcxBitmap(ARect, APixelFormat) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxBitmap32(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : TcxBitmap(AWidth, AHeight, APixelFormat) { }
	/* TcxBitmap.Destroy */ inline __fastcall virtual ~TcxBitmap32(void) { }
	
};


class DELPHICLASS TcxColorList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxColorList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	HIDESBASE int __fastcall Add(System::Uitypes::TColor AColor);
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxColorList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxColorList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxAlphaBitmap;
class PASCALIMPLEMENTATION TcxAlphaBitmap : public TcxBitmap32
{
	typedef TcxBitmap32 inherited;
	
private:
	tagRGBQUAD FTransparentBkColor;
	TcxColorList* FTransparentPixels;
	System::Types::TPoint FCurrentColorIndex;
	TcxHatchData FHatchData;
	void __fastcall CorrectBlend(tagRGBQUAD &AColor);
	void __fastcall ClearColor(tagRGBQUAD &AColor);
	void __fastcall Dingy(tagRGBQUAD &AColor);
	void __fastcall Dirty(tagRGBQUAD &AColor);
	void __fastcall Disable(tagRGBQUAD &AColor);
	void __fastcall Fade(tagRGBQUAD &AColor);
	void __fastcall GrayScale(tagRGBQUAD &AColor);
	void __fastcall Hatch(tagRGBQUAD &AColor);
	void __fastcall MakeMask(tagRGBQUAD &AColor);
	void __fastcall SetOpaque(tagRGBQUAD &AColor);
	void __fastcall ResetAlpha(tagRGBQUAD &AColor);
	bool __fastcall IsColorTransparent(const tagRGBQUAD AColor);
	
protected:
	virtual void __fastcall Initialize(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat);
	void __fastcall ScaleColor(tagRGBQUAD &AColor, const TcxColorTransitionMap &AColorMap);
	__property TcxHatchData HatchData = {read=FHatchData, write=FHatchData};
	__property tagRGBQUAD TransparentBkColor = {read=FTransparentBkColor, write=FTransparentBkColor};
	__property TcxColorList* TransparentPixels = {read=FTransparentPixels};
	
public:
	__fastcall virtual TcxAlphaBitmap(int AWidth, int AHeight)/* overload */;
	__fastcall TcxAlphaBitmap(int AWidth, int AHeight, tagRGBQUAD ATransparentBkColor)/* overload */;
	__fastcall virtual ~TcxAlphaBitmap(void);
	virtual void __fastcall Clear(void);
	void __fastcall DrawHatch(const TcxHatchData &AHatchData)/* overload */;
	void __fastcall DrawHatch(System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AStep, System::Byte AAlpha1 = (System::Byte)(0xff), System::Byte AAlpha2 = (System::Byte)(0xff))/* overload */;
	void __fastcall DrawShadow(TcxAlphaBitmap* AMaskBitmap, int AShadowSize, System::Uitypes::TColor AShadowColor, bool AInflateSize = false);
	void __fastcall RecoverAlphaChannel(System::Uitypes::TColor ATransparentColor);
	void __fastcall Shade(TcxAlphaBitmap* AMaskBitmap);
	void __fastcall TransformBitmap(TcxBitmapTransformationMode AMode);
	void __fastcall RefreshImage(int AWidth, int AHeight)/* overload */;
	void __fastcall RefreshImage(const System::Types::TRect &ARect)/* overload */;
public:
	/* TcxBitmap32.CreateSize */ inline __fastcall TcxAlphaBitmap(int AWidth, int AHeight, bool AClear)/* overload */ : TcxBitmap32(AWidth, AHeight, AClear) { }
	/* TcxBitmap32.CreateSize */ inline __fastcall TcxAlphaBitmap(const System::Types::TRect &ARect, bool AClear)/* overload */ : TcxBitmap32(ARect, AClear) { }
	
public:
	/* TcxBitmap.Create */ inline __fastcall virtual TcxAlphaBitmap(void)/* overload */ : TcxBitmap32() { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxAlphaBitmap(const System::Types::TRect &ARect)/* overload */ : TcxBitmap32(ARect) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxAlphaBitmap(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : TcxBitmap32(ARect, APixelFormat) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TcxAlphaBitmap(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : TcxBitmap32(AWidth, AHeight, APixelFormat) { }
	
};


class DELPHICLASS TcxImageInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImageInfo : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Vcl::Graphics::TBitmap* FImage;
	Vcl::Graphics::TBitmap* FMask;
	System::Uitypes::TColor FMaskColor;
	Vcl::Graphics::TBitmap* FInternalMask;
	void __fastcall AssignBitmap(Vcl::Graphics::TBitmap* ASourceBitmap, Vcl::Graphics::TBitmap* ADestBitmap);
	void __fastcall Dormant(void);
	
protected:
	virtual void __fastcall SetImage(Vcl::Graphics::TBitmap* Value);
	virtual void __fastcall SetMask(Vcl::Graphics::TBitmap* Value);
	
public:
	__fastcall TcxImageInfo(void);
	__fastcall virtual ~TcxImageInfo(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Vcl::Graphics::TBitmap* Image = {read=FImage, write=SetImage};
	__property Vcl::Graphics::TBitmap* Mask = {read=FMask, write=SetMask};
	__property System::Uitypes::TColor MaskColor = {read=FMaskColor, write=FMaskColor, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TcxImageList;
class PASCALIMPLEMENTATION TcxImageList : public Vcl::Controls::TDragImageList
{
	typedef Vcl::Controls::TDragImageList inherited;
	
private:
	bool FAlphaBlending;
	int FFormatVersion;
	System::Classes::TCollection* FImages;
	int FLockCount;
	bool FSynchronization;
	bool __fastcall GetCompressData(void);
	void __fastcall SetCompressData(bool Value);
	HIDESBASE NativeUInt __fastcall GetHandle(void);
	HIDESBASE void __fastcall SetHandle(NativeUInt Value);
	void __fastcall ReadFormatVersion(System::Classes::TReader* AReader);
	void __fastcall WriteFormatVersion(System::Classes::TWriter* AWriter);
	void __fastcall ReadImageInfo(System::Classes::TReader* AReader);
	void __fastcall WriteImageInfo(System::Classes::TWriter* AWriter);
	void __fastcall ReadDesignInfo(System::Classes::TReader* AReader);
	void __fastcall WriteDesignInfo(System::Classes::TWriter* AWriter);
	bool __fastcall NeedSynchronizeImageInfo(void);
	void __fastcall SynchronizeImageInfo(void);
	void __fastcall SynchronizeHandle(void);
	void __fastcall AddToInternalCollection(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, System::Uitypes::TColor AMaskColor = (System::Uitypes::TColor)(0x1fffffff));
	void __fastcall DormantImage(int AIndex);
	HIDESBASE int __fastcall GetImageHandle(Vcl::Graphics::TBitmap* AImage);
	int __fastcall GetHeight(void);
	HIDESBASE void __fastcall SetHeight(int AValue);
	int __fastcall GetWidth(void);
	HIDESBASE void __fastcall SetWidth(int AValue);
	
protected:
	bool __fastcall ChangeLocked(void);
	DYNAMIC void __fastcall Change(void);
	virtual void __fastcall DoDraw(int Index, Vcl::Graphics::TCanvas* Canvas, int X, int Y, unsigned Style, bool Enabled = true);
	void __fastcall DoDrawEx(int AIndex, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, unsigned AStyle, bool AStretch, bool ASmoothResize, bool AEnabled);
	virtual void __fastcall Initialize(void);
	void __fastcall Finalize(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	void __fastcall Dormant(void);
	int __fastcall AddImageInfo(TcxImageInfo* AImageInfo);
	void __fastcall ConvertImageInfoTo32bit(TcxImageInfo* AImageInfo);
	void __fastcall ConvertTo32bit(void);
	void __fastcall InternalCopyImageInfos(TcxImageList* AImageList, int AStartIndex, int AEndIndex);
	void __fastcall InternalCopyImages(Vcl::Imglist::TCustomImageList* AImageList, int AStartIndex, int AEndIndex);
	void __fastcall GetImageInfo(int AIndex, TcxImageInfo* AImageInfo)/* overload */;
	
public:
	__fastcall virtual ~TcxImageList(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	HIDESBASE int __fastcall Add(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask);
	HIDESBASE int __fastcall AddIcon(Vcl::Graphics::TIcon* AIcon);
	HIDESBASE int __fastcall AddMasked(Vcl::Graphics::TBitmap* AImage, System::Uitypes::TColor AMaskColor);
	HIDESBASE void __fastcall Move(int ACurIndex, int ANewIndex);
	HIDESBASE void __fastcall Delete(int AIndex);
	int __fastcall AddBitmap(Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask, System::Uitypes::TColor AMaskColor, bool AStretch, bool ASmooth);
	HIDESBASE int __fastcall AddImage(Vcl::Imglist::TCustomImageList* AValue, int AIndex);
	HIDESBASE void __fastcall AddImages(Vcl::Imglist::TCustomImageList* AImages);
	HIDESBASE void __fastcall CopyImages(Vcl::Imglist::TCustomImageList* AImages, int AStartIndex = 0x0, int AEndIndex = 0xffffffff);
	HIDESBASE void __fastcall Clear(void);
	HIDESBASE void __fastcall Insert(int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask);
	HIDESBASE void __fastcall InsertIcon(int AIndex, Vcl::Graphics::TIcon* AIcon);
	HIDESBASE void __fastcall InsertMasked(int AIndex, Vcl::Graphics::TBitmap* AImage, System::Uitypes::TColor AMaskColor);
	HIDESBASE void __fastcall Replace(int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask);
	HIDESBASE void __fastcall ReplaceIcon(int AIndex, Vcl::Graphics::TIcon* AIcon);
	HIDESBASE void __fastcall ReplaceMasked(int AIndex, Vcl::Graphics::TBitmap* AImage, System::Uitypes::TColor AMaskColor);
	bool __fastcall LoadImage(NativeUInt AInstance, const System::UnicodeString AResourceName, System::Uitypes::TColor AMaskColor = (System::Uitypes::TColor)(0x20000000), int AWidth = 0x0, Vcl::Imglist::TLoadResources AFlags = Vcl::Imglist::TLoadResources() );
	HIDESBASE bool __fastcall FileLoad(Vcl::Imglist::TResType AResType, const System::UnicodeString AName, System::Uitypes::TColor AMaskColor);
	HIDESBASE bool __fastcall GetResource(Vcl::Imglist::TResType AResType, const System::UnicodeString AName, int AWidth, Vcl::Imglist::TLoadResources ALoadFlags, System::Uitypes::TColor AMaskColor);
	HIDESBASE bool __fastcall GetInstRes(NativeUInt AInstance, Vcl::Imglist::TResType AResType, const System::UnicodeString AName, int AWidth, Vcl::Imglist::TLoadResources ALoadFlags, System::Uitypes::TColor AMaskColor)/* overload */;
	HIDESBASE bool __fastcall GetInstRes(NativeUInt AInstance, Vcl::Imglist::TResType AResType, unsigned AResID, int AWidth, Vcl::Imglist::TLoadResources ALoadFlags, System::Uitypes::TColor AMaskColor)/* overload */;
	HIDESBASE bool __fastcall ResourceLoad(Vcl::Imglist::TResType AResType, const System::UnicodeString AName, System::Uitypes::TColor AMaskColor);
	HIDESBASE bool __fastcall ResInstLoad(NativeUInt AInstance, Vcl::Imglist::TResType AResType, const System::UnicodeString AName, System::Uitypes::TColor AMaskColor);
	HIDESBASE void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	HIDESBASE void __fastcall EndUpdate(void);
	HIDESBASE void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, int AIndex, bool AStretch = true, bool ASmoothResize = false, bool AEnabled = true)/* overload */;
	void __fastcall GetImageInfo(int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask)/* overload */;
	void __fastcall GetImage(int AIndex, Vcl::Graphics::TBitmap* AImage);
	void __fastcall GetMask(int AIndex, Vcl::Graphics::TBitmap* AMask);
	__classmethod void __fastcall GetImageInfo(Vcl::Imglist::TCustomImageList* AImages, int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask)/* overload */;
	__classmethod void __fastcall GetImageInfo(NativeUInt AHandle, int AIndex, Vcl::Graphics::TBitmap* AImage, Vcl::Graphics::TBitmap* AMask)/* overload */;
	__classmethod int __fastcall GetPixelFormat(NativeUInt AHandle);
	HIDESBASE void __fastcall SetSize(int AWidth, int AHeight);
	__property bool AlphaBlending = {read=FAlphaBlending, write=FAlphaBlending, nodefault};
	__property NativeUInt Handle = {read=GetHandle, write=SetHandle, nodefault};
	
__published:
	__property BlendColor = {default=536870911};
	__property BkColor = {default=536870911};
	__property ColorDepth = {default=6};
	__property bool CompressData = {read=GetCompressData, write=SetCompressData, default=0};
	__property DrawingStyle = {default=2};
	__property int Height = {read=GetHeight, write=SetHeight, default=16};
	__property ImageType = {default=0};
	__property ShareImages = {default=0};
	__property int Width = {read=GetWidth, write=SetWidth, default=16};
	__property OnChange;
public:
	/* TCustomImageList.Create */ inline __fastcall virtual TcxImageList(System::Classes::TComponent* AOwner) : Vcl::Controls::TDragImageList(AOwner) { }
	/* TCustomImageList.CreateSize */ inline __fastcall TcxImageList(int AWidth, int AHeight) : Vcl::Controls::TDragImageList(AWidth, AHeight) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Draw(Vcl::Graphics::TCanvas* Canvas, int X, int Y, int Index, bool Enabled = true){ Vcl::Imglist::TCustomImageList::Draw(Canvas, X, Y, Index, Enabled); }
	inline void __fastcall  Draw(Vcl::Graphics::TCanvas* Canvas, int X, int Y, int Index, Vcl::Imglist::TDrawingStyle ADrawingStyle, Vcl::Imglist::TImageType AImageType, bool Enabled = true){ Vcl::Imglist::TCustomImageList::Draw(Canvas, X, Y, Index, ADrawingStyle, AImageType, Enabled); }
	
};


class DELPHICLASS TcxImageCollectionItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImageCollectionItem : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	Vcl::Graphics::TPicture* FPicture;
	int FTag;
	System::Types::TRect __fastcall GetClientRect(void);
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	void __fastcall SetPicture(Vcl::Graphics::TPicture* AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	void __fastcall DoPictureChanged(System::TObject* Sender);
	
public:
	__fastcall virtual TcxImageCollectionItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxImageCollectionItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, int X, int Y)/* overload */;
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, bool AStretch = true, bool ASmoothResize = false, bool AEnabled = true)/* overload */;
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property int Height = {read=GetHeight, nodefault};
	__property int Width = {read=GetWidth, nodefault};
	
__published:
	__property Vcl::Graphics::TPicture* Picture = {read=FPicture, write=SetPicture};
	__property int Tag = {read=FTag, write=FTag, default=0};
};

#pragma pack(pop)

class DELPHICLASS TcxImageCollectionItems;
class DELPHICLASS TcxImageCollection;
class PASCALIMPLEMENTATION TcxImageCollectionItems : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TcxImageCollectionItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxImageCollection* FCollection;
	HIDESBASE TcxImageCollectionItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TcxImageCollectionItem* AValue);
	
protected:
	virtual void __fastcall SetItemName(Cxclasses::TcxComponentCollectionItem* AItem);
	virtual void __fastcall Update(Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	
public:
	__fastcall TcxImageCollectionItems(TcxImageCollection* ACollection);
	HIDESBASE TcxImageCollectionItem* __fastcall Add(void);
	bool __fastcall FindItemByName(const System::UnicodeString AName, /* out */ TcxImageCollectionItem* &AItem);
	HIDESBASE TcxImageCollectionItem* __fastcall FindItemByID(int ID);
	HIDESBASE TcxImageCollectionItem* __fastcall Insert(int Index);
	__property TcxImageCollectionItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TcxImageCollectionItems(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxImageCollection : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	TcxImageCollectionItems* FItems;
	System::Classes::TInterfaceList* FListeners;
	int __fastcall GetCount(void);
	void __fastcall SetItems(TcxImageCollectionItems* AItems);
	
protected:
	void __fastcall Changed(void);
	void __fastcall DoDestroyed(void);
	
public:
	__fastcall virtual TcxImageCollection(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxImageCollection(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, int X, int Y, int AIndex)/* overload */;
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, int AIndex, bool AStretch = true, bool ASmoothResize = false, bool AEnabled = true)/* overload */;
	void __fastcall AddListener(_di_IcxImageCollectionListener AListener);
	void __fastcall RemoveListener(_di_IcxImageCollectionListener AListener);
	__property int Count = {read=GetCount, nodefault};
	
__published:
	__property TcxImageCollectionItems* Items = {read=FItems, write=SetItems};
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxBrushData
{
public:
	Vcl::Graphics::TBrush* Brush;
	System::Uitypes::TColor Color;
	int RefCount;
};


typedef System::DynamicArray<TcxBrushData> TcxBrushesData;

class DELPHICLASS EBrushCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EBrushCache : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EBrushCache(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EBrushCache(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EBrushCache(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EBrushCache(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EBrushCache(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EBrushCache(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EBrushCache(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EBrushCache(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EBrushCache(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EBrushCache(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EBrushCache(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EBrushCache(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EBrushCache(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxBrushCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxBrushCache : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FCapacity;
	int FCount;
	TcxBrushesData FData;
	int FDeletedCount;
	int FLockRef;
	
protected:
	Vcl::Graphics::TBrush* __fastcall Add(System::Uitypes::TColor AColor);
	Vcl::Graphics::TBrush* __fastcall AddItemAt(int AIndex, System::Uitypes::TColor AColor);
	void __fastcall CacheCheck(bool Value, const System::UnicodeString AMessage);
	void __fastcall Delete(int AIndex);
	bool __fastcall IndexOf(System::Uitypes::TColor AColor, /* out */ int &AIndex);
	void __fastcall InitItem(TcxBrushData &AItem, System::Uitypes::TColor AColor);
	bool __fastcall IsSystemBrush(Vcl::Graphics::TBrush* ABrush);
	int __fastcall FindNearestItem(System::Uitypes::TColor AColor);
	void __fastcall Move(int ASrc, int ADst, int ACount);
	void __fastcall Pack(void);
	void __fastcall Recreate(void);
	void __fastcall Release(int AIndex);
	
public:
	__fastcall virtual ~TcxBrushCache(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	void __fastcall ReleaseBrush(Vcl::Graphics::TBrush* &ABrush);
	void __fastcall SetBrushColor(Vcl::Graphics::TBrush* &ABrush, System::Uitypes::TColor AColor);
public:
	/* TObject.Create */ inline __fastcall TcxBrushCache(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxColorSpaceConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxColorSpaceConverter : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod TdxHSL __fastcall ColorToHSL(System::Uitypes::TColor AColor);
	__classmethod TdxHSV __fastcall ColorToHSV(System::Uitypes::TColor AColor);
	__classmethod System::Uitypes::TColor __fastcall HSLToColor(const TdxHSL &AHSL);
	__classmethod System::Uitypes::TColor __fastcall HSVToColor(const TdxHSV &AHSV);
public:
	/* TObject.Create */ inline __fastcall TdxColorSpaceConverter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxColorSpaceConverter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxColorHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxColorHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod System::Uitypes::TColor __fastcall ChangeLightness(System::Uitypes::TColor AColor, const double ALightnessDelta);
public:
	/* TObject.Create */ inline __fastcall TdxColorHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxColorHelper(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TcxColorInfo
{
public:
	System::UnicodeString Name;
	System::Uitypes::TColor Color;
};


typedef System::StaticArray<TcxColorInfo, 169> Cxgraphics__91;

enum TcxModifyStringType : unsigned char { mstEndEllipsis, mstPathEllipsis };

//-- var, const, procedure ---------------------------------------------------
#define dxMeasurePattern L"Zq"
static const System::Int8 cxAlignLeft = System::Int8(0x1);
static const System::Int8 cxAlignRight = System::Int8(0x2);
static const System::Int8 cxAlignHCenter = System::Int8(0x4);
static const System::Int8 cxAlignTop = System::Int8(0x8);
static const System::Int8 cxAlignBottom = System::Int8(0x10);
static const System::Int8 cxAlignVCenter = System::Int8(0x20);
static const System::Int8 cxAlignCenter = System::Int8(0x24);
static const System::Int8 cxSingleLine = System::Int8(0x40);
static const System::Byte cxDontClip = System::Byte(0x80);
static const System::Word cxExpandTabs = System::Word(0x100);
static const System::Word cxShowPrefix = System::Word(0x200);
static const System::Word cxWordBreak = System::Word(0x400);
static const System::Word cxShowEndEllipsis = System::Word(0x800);
static const System::Word cxCalcRect = System::Word(0x1000);
static const System::Word cxShowPathEllipsis = System::Word(0x2000);
static const System::Word cxDontBreakChars = System::Word(0x4000);
static const System::Word cxNoFullWidthCharBreak = System::Word(0x8000);
static const System::Word cxDontPrint = System::Word(0x1000);
extern PACKAGE System::StaticArray<int, 3> SystemAlignmentsHorz;
extern PACKAGE System::StaticArray<int, 3> SystemAlignmentsVert;
extern PACKAGE System::StaticArray<int, 3> cxAlignmentsHorz;
extern PACKAGE System::StaticArray<int, 3> cxAlignmentsVert;
static const int clcxLightGray = int(0xcfcfcf);
extern PACKAGE System::Types::TRect cxEmptyRect;
static const System::Int8 cxDesignSelectionWidth = System::Int8(0x2);
static const System::Byte cxDefaultAlphaValue = System::Byte(0xc8);
extern PACKAGE Vcl::Graphics::TBrush* cxHalfToneBrush;
extern PACKAGE Vcl::Graphics::TPixelFormat cxDoubleBufferedBitmapPixelFormat;
static const System::Word cxMaxRegionSize = System::Word(0x7530);
#define cxBordersAll (System::Set<TcxBorder, TcxBorder::bLeft, TcxBorder::bBottom> () << TcxBorder::bLeft << TcxBorder::bTop << TcxBorder::bRight << TcxBorder::bBottom )
extern PACKAGE TcxColorTransitionMap DisableMap;
extern PACKAGE TcxColorTransitionMap FadeMap;
extern PACKAGE TcxColorTransitionMap GrayMap;
extern PACKAGE System::StaticArray<TcxImageDrawMode, 2> EnabledImageDrawModeMap;
extern PACKAGE Cxgraphics__91 cxColorsByName;
extern PACKAGE TcxDrawImageProc CustomDrawImageProc;
extern PACKAGE bool dxUseAntialiasingForRotatedText;
extern PACKAGE int __fastcall cxGetCurrentDPI(void);
extern PACKAGE int __fastcall cxGetValueCurrentDPI(int AValue)/* overload */;
extern PACKAGE System::Types::TSize __fastcall cxGetValueCurrentDPI(const System::Types::TSize &AValue)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxGetValueCurrentDPI(const System::Types::TRect &AValue)/* overload */;
extern PACKAGE System::Types::TSize __fastcall cxGetPixelsPerInch(void);
extern PACKAGE int __fastcall cxFlagsToDTFlags(int Flags);
extern PACKAGE void __fastcall cxSetImageList(Vcl::Imglist::TCustomImageList* const AValue, Vcl::Imglist::TCustomImageList* &AFieldValue, Vcl::Imglist::TChangeLink* const AChangeLink, System::Classes::TComponent* ANotifyComponent);
extern PACKAGE bool __fastcall IsGlyphAssigned(Vcl::Graphics::TBitmap* AGlyph);
extern PACKAGE bool __fastcall IsImageAssigned(Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex)/* overload */;
extern PACKAGE bool __fastcall IsImageAssigned(Vcl::Graphics::TGraphic* AImage)/* overload */;
extern PACKAGE bool __fastcall IsPictureAssigned(Vcl::Graphics::TPicture* APicture);
extern PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Graphics::TGraphic* AImage, Vcl::Imglist::TCustomImageList* AImageList, int AImageIndex)/* overload */;
extern PACKAGE System::Types::TSize __fastcall dxGetImageSize(Vcl::Graphics::TPicture* APicture)/* overload */;
extern PACKAGE bool __fastcall IsXPManifestEnabled(void);
extern PACKAGE System::Uitypes::TColor __fastcall GetRealColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall cxGetActualColor(const System::Uitypes::TColor AValue, const System::Uitypes::TColor ADefaultValue);
extern PACKAGE TdxHSV __fastcall dxColorToHSV(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall dxHSVToColor(const TdxHSV &AHSV);
extern PACKAGE System::Uitypes::TColor __fastcall dxGetColorTint(System::Uitypes::TColor AColor, int ATintPercent);
extern PACKAGE System::Uitypes::TColor __fastcall GetLightColor(TcxColorPart ABtnFaceColorPart, TcxColorPart AHighlightColorPart, TcxColorPart AWindowColorPart);
extern PACKAGE System::Uitypes::TColor __fastcall GetLightBtnFaceColor(void);
extern PACKAGE System::Uitypes::TColor __fastcall GetLightDownedColor(void);
extern PACKAGE System::Uitypes::TColor __fastcall GetLightDownedSelColor(void);
extern PACKAGE System::Uitypes::TColor __fastcall GetLightSelColor(void);
extern PACKAGE bool __fastcall CanApplySystemAlphaBlending(void);
extern PACKAGE bool __fastcall SystemAlphaBlend(HDC ADestDC, HDC ASrcDC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, System::Byte AAlpha = (System::Byte)(0xff), bool AHasPerPixelAlpha = true);
extern PACKAGE bool __fastcall cxColorByName(const System::UnicodeString AText, System::Uitypes::TColor &AColor);
extern PACKAGE bool __fastcall cxNameByColor(System::Uitypes::TColor AColor, System::UnicodeString &AText);
extern PACKAGE void __fastcall cxAlphaBlend(Vcl::Graphics::TBitmap* ADestBitmap, Vcl::Graphics::TBitmap* ASrcBitmap, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, bool ASmoothImage = false, System::Byte AConstantAlpha = (System::Byte)(0xff))/* overload */;
extern PACKAGE void __fastcall cxAlphaBlend(HDC ADestDC, Vcl::Graphics::TBitmap* ASrcBitmap, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, bool ASmoothImage = false, System::Byte AConstantAlpha = (System::Byte)(0xff))/* overload */;
extern PACKAGE void __fastcall cxAlphaBlend(HDC ADestDC, HDC ASrcDC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, bool ASmoothImage = false, System::Byte AConstantAlpha = (System::Byte)(0xff))/* overload */;
extern PACKAGE void __fastcall cxBitBlt(HDC ADestDC, HDC ASrcDC, const System::Types::TRect &ADestRect, const System::Types::TPoint &ASrcTopLeft, unsigned ROP);
extern PACKAGE void __fastcall cxBlendFunction(const tagRGBQUAD ASource, tagRGBQUAD &ADest, System::Byte ASourceConstantAlpha);
extern PACKAGE bool __fastcall cxColorIsValid(System::Uitypes::TColor AColor);
extern PACKAGE bool __fastcall cxColorIsEqual(const tagRGBQUAD AColor1, const tagRGBQUAD AColor2);
extern PACKAGE void __fastcall cxExchangeColors(System::Uitypes::TColor &AColor1, System::Uitypes::TColor &AColor2);
extern PACKAGE HRGN __fastcall cxCreateRegionFromBitmap(Vcl::Graphics::TBitmap* ABitmap, System::Uitypes::TColor ATransparentColor);
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateBitmap(const System::Types::TSize &ASize, Vcl::Graphics::TPixelFormat AFormat = (Vcl::Graphics::TPixelFormat)(0x6))/* overload */;
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateBitmap(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat AFormat = (Vcl::Graphics::TPixelFormat)(0x6))/* overload */;
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateBitmap(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat AFormat = (Vcl::Graphics::TPixelFormat)(0x6))/* overload */;
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateTrueColorBitmap(const System::Types::TSize &ASize)/* overload */;
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall cxCreateTrueColorBitmap(int AWidth, int AHeight)/* overload */;
extern PACKAGE HBITMAP __fastcall cxCreateTrueColorBitmapHandle(int AWidth, int AHeight, int ABPP = 0x20);
extern PACKAGE void __fastcall cxDrawHatchRect(TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor);
extern PACKAGE void __fastcall cxDrawDesignRect(TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ASelected);
extern PACKAGE void __fastcall cxDrawBitmap(NativeUInt ADestDC, Vcl::Graphics::TBitmap* ASrcBitmap, const System::Types::TRect &ADestRect, const System::Types::TPoint &ASrcPoint, int AMode = 0xcc0020);
extern PACKAGE void __fastcall cxDrawImage(NativeUInt ADC, const System::Types::TRect &AGlyphRect, const System::Types::TRect &ABackgroundRect, Vcl::Graphics::TBitmap* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, TcxImageDrawMode ADrawMode, bool ASmoothImage = false, NativeUInt ABrush = (NativeUInt)(0x0), System::Uitypes::TColor ATransparentColor = (System::Uitypes::TColor)(0x1fffffff), bool AUseLeftBottomPixelAsTransparent = true)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxGetImageRect(const System::Types::TRect &ADrawRect, const System::Types::TSize &AImageSize, TcxImageFitMode AFitMode)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxGetImageRect(const System::Types::TRect &ADrawRect, const System::Types::TSize &AImageSize, TcxImageFitMode AFitMode, bool ACentre, int AScale)/* overload */;
extern PACKAGE void __fastcall cxDrawImage(TcxCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TBitmap* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, TcxImageFitMode AFitMode, TcxImageDrawMode ADrawMode = (TcxImageDrawMode)(0x0))/* overload */;
extern PACKAGE void __fastcall cxDrawImage(TcxCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TBitmap* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, bool AEnabled)/* overload */;
extern PACKAGE void __fastcall cxDrawPicture(TcxCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TPicture* APicture, TcxImageFitMode AFitMode);
extern PACKAGE void __fastcall cxDrawImage(TcxCanvas* ACanvas, const System::Types::TRect &ARect, Vcl::Graphics::TGraphic* AImage, TcxImageFitMode AFitMode)/* overload */;
extern PACKAGE void __fastcall cxDrawImageList(NativeUInt AImageListHandle, int AImageIndex, HDC ADC, const System::Types::TPoint &APoint, Vcl::Imglist::TDrawingStyle ADrawingStyle, Vcl::Imglist::TImageType AImageType);
extern PACKAGE void __fastcall cxDrawHatch(HDC ADC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AStep, System::Byte AAlpha1 = (System::Byte)(0xff), System::Byte AAlpha2 = (System::Byte)(0xff));
extern PACKAGE void __fastcall cxPrepareBitmapForDrawing(Vcl::Graphics::TBitmap* AGlyph, Vcl::Imglist::TCustomImageList* AImages, int AImageIndex, bool AUseLeftBottomPixelAsTransparent, System::Uitypes::TColor ATransparentColor, /* out */ TcxAlphaBitmap* &AImageBitmap, /* out */ TcxAlphaBitmap* &AMaskBitmap, /* out */ bool &AIsAlphaUsed);
extern PACKAGE void __fastcall cxSmoothResizeBitmap(Vcl::Graphics::TBitmap* ASource, Vcl::Graphics::TBitmap* ADestination, bool AForceUseLanczos3Filter = false);
extern PACKAGE void __fastcall cxStretchBlt(HDC ADestDC, HDC ASrcDC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASrcRect, unsigned ROP);
extern PACKAGE void __fastcall cxMakeColoredBitmap(Vcl::Graphics::TBitmap* ABitmap, System::Uitypes::TColor AColor);
extern PACKAGE void __fastcall cxMakeTrueColorBitmap(Vcl::Graphics::TBitmap* ASourceBitmap, Vcl::Graphics::TBitmap* ATrueColorBitmap);
extern PACKAGE void __fastcall cxMakeMaskBitmap(Vcl::Graphics::TBitmap* ASourceBitmap, Vcl::Graphics::TBitmap* AMaskBitmap);
extern PACKAGE System::Types::TSize __fastcall cxGetCursorSize(void);
extern PACKAGE void __fastcall cxAlphaBlend(Vcl::Graphics::TBitmap* ASource, const System::Types::TRect &ARect, const System::Uitypes::TColor ASelColor, System::Byte Alpha = (System::Byte)(0xaa))/* overload */;
extern PACKAGE void __fastcall cxAlphaBlend(Vcl::Graphics::TBitmap* ADest, Vcl::Graphics::TBitmap* ABkSource, Vcl::Graphics::TBitmap* ASource, System::Byte Alpha = (System::Byte)(0xc8))/* overload */;
extern PACKAGE void __fastcall cxApplyViewParams(TcxCanvas* ACanvas, const TcxViewParams &AViewParams);
extern PACKAGE void __fastcall cxCopyImage(Vcl::Graphics::TBitmap* ASource, Vcl::Graphics::TBitmap* ADest, const System::Types::TPoint &ASrcOffset, const System::Types::TPoint &ADstOffset, const System::Types::TRect &ARect)/* overload */;
extern PACKAGE void __fastcall cxCopyImage(Vcl::Graphics::TCanvas* ASource, Vcl::Graphics::TCanvas* ADest, const System::Types::TPoint &ASrcOffset, const System::Types::TPoint &ADstOffset, const System::Types::TRect &ARect)/* overload */;
extern PACKAGE void __fastcall cxDrawArrows(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, TcxBorder ASide, System::Uitypes::TColor AColor, System::Uitypes::TColor APenColor = (System::Uitypes::TColor)(0x20000000));
extern PACKAGE void __fastcall cxFillHalfToneRect(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABkColor, System::Uitypes::TColor AColor);
extern PACKAGE bool __fastcall cxGetTextExtentPoint32(NativeUInt ADC, const System::UnicodeString AText, /* out */ System::Types::TSize &ASize, int ACharCount = 0xffffffff);
extern PACKAGE void __fastcall cxGetTextLines(const System::UnicodeString AText, TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Classes::TStrings* ALines);
extern PACKAGE int __fastcall cxDrawText(NativeUInt ADC, const System::UnicodeString AText, System::Types::TRect &ARect, unsigned AFormat, int ACharCount = 0xffffffff, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), int ABkMode = 0x1)/* overload */;
extern PACKAGE int __fastcall cxDrawText(Vcl::Graphics::TCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ARect, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
extern PACKAGE int __fastcall cxDrawText(TcxCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ARect, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), TcxRotationAngle ARotationAngle = (TcxRotationAngle)(0x0))/* overload */;
extern PACKAGE int __fastcall cxDrawMultilineText(TcxCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ARect, unsigned AFormat, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
extern PACKAGE int __fastcall cxDrawMultilineText(TcxCanvas* ACanvas, const System::UnicodeString AText, const System::Types::TRect &ARect, System::Classes::TAlignment ATextAlignHorz = (System::Classes::TAlignment)(0x0), Cxclasses::TcxAlignmentVert ATextAlignVert = (Cxclasses::TcxAlignmentVert)(0x0), System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000))/* overload */;
extern PACKAGE bool __fastcall cxExtTextOut(NativeUInt ADC, const System::UnicodeString AText, const System::Types::TPoint &APoint, const System::Types::TRect &ARect, unsigned AOptions, int ACharCount = 0xffffffff)/* overload */;
extern PACKAGE bool __fastcall cxExtTextOut(NativeUInt ADC, const System::UnicodeString AText, const System::Types::TPoint &APoint, unsigned AOptions, int ACharCount = 0xffffffff)/* overload */;
extern PACKAGE void __fastcall cxInvalidateRect(NativeUInt AHandle, const System::Types::TRect &ARect, bool AEraseBackground = true)/* overload */;
extern PACKAGE void __fastcall cxInvalidateRect(NativeUInt AHandle, bool AEraseBackground = true)/* overload */;
extern PACKAGE void __fastcall cxRedrawWindow(NativeUInt AHandle, const System::Types::TRect &ARect, bool AEraseBackground = true, bool ARedrawNC = false);
extern PACKAGE int __fastcall cxTextHeight(Vcl::Graphics::TFont* AFont)/* overload */;
extern PACKAGE int __fastcall cxTextHeight(NativeUInt ADC)/* overload */;
extern PACKAGE int __fastcall cxTextHeight(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AFontSize = 0x0)/* overload */;
extern PACKAGE int __fastcall cxTextWidth(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AFontSize = 0x0);
extern PACKAGE System::Types::TSize __fastcall cxTextExtent(NativeUInt AFontHandle, const System::UnicodeString S)/* overload */;
extern PACKAGE System::Types::TSize __fastcall cxTextExtent(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AFontSize = 0x0)/* overload */;
extern PACKAGE System::Types::TSize __fastcall cxTextSize(NativeUInt ADC, const System::UnicodeString AText)/* overload */;
extern PACKAGE System::Types::TSize __fastcall cxTextSize(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxGetTextRect(NativeUInt ADC, const System::UnicodeString AText, int ARowCount, bool AReturnMaxRectHeight = false)/* overload */;
extern PACKAGE System::Types::TRect __fastcall cxGetTextRect(Vcl::Graphics::TFont* AFont, const System::UnicodeString AText, int ARowCount)/* overload */;
extern PACKAGE void __fastcall cxGetTextRect(System::Types::TRect &ARect, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, int ADTFlags)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxGetStringAdjustedToWidth(HDC ADC, HFONT AFontHandle, const System::UnicodeString S, int AWidth, TcxModifyStringType AModifyStringType = (TcxModifyStringType)(0x0))/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxGetStringAdjustedToWidth(Vcl::Graphics::TFont* AFont, const System::UnicodeString S, int AWidth, TcxModifyStringType AModifyStringType = (TcxModifyStringType)(0x0))/* overload */;
extern PACKAGE bool __fastcall cxCompareBitmaps(Vcl::Graphics::TBitmap* ABitmap1, Vcl::Graphics::TBitmap* ABitmap2);
extern PACKAGE bool __fastcall cxGetBitmapData(HBITMAP ABitmapHandle, /* out */ tagBITMAP &ABitmapData);
extern PACKAGE bool __fastcall cxGetBrushData(HBRUSH ABrushHandle, /* out */ tagLOGBRUSH &ALogBrush)/* overload */;
extern PACKAGE tagLOGBRUSH __fastcall cxGetBrushData(HBRUSH ABrushHandle)/* overload */;
extern PACKAGE bool __fastcall cxGetFontData(HFONT AFontHandle, /* out */ tagLOGFONTW &ALogFont);
extern PACKAGE bool __fastcall cxGetPenData(HPEN APenHandle, /* out */ tagLOGPEN &ALogPen);
extern PACKAGE bool __fastcall cxGetTextMetrics(Vcl::Graphics::TFont* AFont, /* out */ tagTEXTMETRICW &ATextMetric);
extern PACKAGE Vcl::Graphics::TCanvasOrientation __fastcall cxGetWritingDirection(System::Uitypes::TFontCharset AFontCharset, const System::UnicodeString AText);
extern PACKAGE void __fastcall cxDrawThemeParentBackground(Vcl::Controls::TWinControl* AControl, TcxCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
extern PACKAGE void __fastcall cxDrawThemeParentBackground(Vcl::Controls::TWinControl* AControl, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
extern PACKAGE void __fastcall cxPaintControlTo(Vcl::Controls::TWinControl* ADrawingControl, TcxCanvas* ACanvas, const System::Types::TPoint &ADestinatioPoint, const System::Types::TRect &ADrawingRect, bool ADrawParentWithChildren, bool ADrawNC);
extern PACKAGE void __fastcall cxDrawTransparentControlBackground(Vcl::Controls::TWinControl* AControl, TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool APaintParentWithChildren = true)/* overload */;
extern PACKAGE void __fastcall cxDrawTransparentControlBackground(Vcl::Controls::TWinControl* AControl, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, bool APaintParentWithChildren = true)/* overload */;
extern PACKAGE void __fastcall cxDrawTransparentControlBackground(Vcl::Controls::TWinControl* AControl, TcxCanvas* ACanvas, const System::Types::TRect &ASourceRect, const System::Types::TPoint &ADestinationPoint, bool APaintParentWithChildren = true)/* overload */;
extern PACKAGE void __fastcall cxPaintTo(Vcl::Controls::TWinControl* ASourceControl, TcxCanvas* ADestinationCanvas, const System::Types::TPoint &ADestinationPoint, const System::Types::TRect &ASourceRect, System::Classes::TList* ASkipList = (System::Classes::TList*)(0x0));
extern PACKAGE void __fastcall cxPaintToBitmap(Vcl::Controls::TWinControl* AControl, TcxBitmap* ABitmap, bool ADrawNCArea = false);
extern PACKAGE void __fastcall cxResetFont(Vcl::Graphics::TFont* const AFont);
extern PACKAGE TcxScreenCanvas* __fastcall cxScreenCanvas(void);
extern PACKAGE TcxPaintCanvas* __fastcall cxPaintCanvas(void);
extern PACKAGE bool __fastcall cxPtInRegion(HRGN ARegionHandle, const int X, const int Y)/* overload */;
extern PACKAGE bool __fastcall cxPtInRegion(HRGN ARegionHandle, const System::Types::TPoint &P)/* overload */;
extern PACKAGE void __fastcall cxTransformImages(TcxImageList* AImageList, System::Uitypes::TColor ABkColor, bool AEnabled = true)/* overload */;
extern PACKAGE void __fastcall cxTransformImages(TcxImageList* ASourceImageList, TcxImageList* ADestinationImageList, System::Uitypes::TColor ABkColor, bool AEnabled = true)/* overload */;
extern PACKAGE void __fastcall cxAdvancedDrawPopupMenuItem(Vcl::Menus::TMenuItem* AMenuItem, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState, Vcl::Imglist::TCustomImageList* AExternalImages = (Vcl::Imglist::TCustomImageList*)(0x0));
extern PACKAGE void __fastcall dxSetFontAsNonAntialiased(Vcl::Graphics::TFont* AFont);
}	/* namespace Cxgraphics */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRAPHICS)
using namespace Cxgraphics;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgraphicsHPP
