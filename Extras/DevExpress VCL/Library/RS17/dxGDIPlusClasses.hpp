// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxGDIPlusClasses.pas' rev: 24.00 (Win32)

#ifndef DxgdiplusclassesHPP
#define DxgdiplusclassesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxgdiplusclasses
{
//-- type declarations -------------------------------------------------------
enum TdxImageDataFormat : unsigned char { dxImageUnknown, dxImageBitmap, dxImageJpeg, dxImagePng, dxImageTiff, dxImageGif };

enum TdxGPInterpolationMode : unsigned char { imDefault, imLowQuality, imHighQuality, imBilinear, imBicubic, imNearestNeighbor, imHighQualityBilinear, imHighQualityBicubic };

enum TdxGPSmoothingMode : unsigned char { smDefault, smHighSpeed, smHighQuality, smNone, smAntiAlias };

class DELPHICLASS TdxGPBrush;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPBrush : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	void *FNativeBrush;
	Dxgdiplusapi::Status FLastResult;
	
protected:
	__fastcall TdxGPBrush(void * nativeBrush, Dxgdiplusapi::Status AStatus);
	void __fastcall SetNativeBrush(void * ANativeBrush);
	Dxgdiplusapi::Status __fastcall SetStatus(Dxgdiplusapi::Status AStatus);
	
public:
	__fastcall TdxGPBrush(void);
	__fastcall virtual ~TdxGPBrush(void);
	virtual TdxGPBrush* __fastcall Clone(void);
	Dxgdiplusapi::BrushType __fastcall GetType(void);
	Dxgdiplusapi::Status __fastcall GetLastStatus(void);
};

#pragma pack(pop)

class DELPHICLASS TdxGPSolidBrush;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPSolidBrush : public TdxGPBrush
{
	typedef TdxGPBrush inherited;
	
private:
	unsigned __fastcall GetColor(void);
	void __fastcall SetColor(const unsigned Value);
	
public:
	__fastcall TdxGPSolidBrush(void)/* overload */;
	__fastcall TdxGPSolidBrush(System::Uitypes::TColor color)/* overload */;
	__property unsigned Color = {read=GetColor, write=SetColor, nodefault};
protected:
	/* TdxGPBrush.CreateNative */ inline __fastcall TdxGPSolidBrush(void * nativeBrush, Dxgdiplusapi::Status AStatus) : TdxGPBrush(nativeBrush, AStatus) { }
	
public:
	/* TdxGPBrush.Destroy */ inline __fastcall virtual ~TdxGPSolidBrush(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGPTextureBrush;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPTextureBrush : public TdxGPBrush
{
	typedef TdxGPBrush inherited;
	
protected:
	/* TdxGPBrush.CreateNative */ inline __fastcall TdxGPTextureBrush(void * nativeBrush, Dxgdiplusapi::Status AStatus) : TdxGPBrush(nativeBrush, AStatus) { }
	
public:
	/* TdxGPBrush.Create */ inline __fastcall TdxGPTextureBrush(void) : TdxGPBrush() { }
	/* TdxGPBrush.Destroy */ inline __fastcall virtual ~TdxGPTextureBrush(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGPLinearGradientBrush;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPLinearGradientBrush : public TdxGPBrush
{
	typedef TdxGPBrush inherited;
	
private:
	void __fastcall SetWrapMode(const Dxgdiplusapi::WrapMode Value);
	Dxgdiplusapi::WrapMode __fastcall GetWrapMode(void);
	
public:
	__fastcall TdxGPLinearGradientBrush(void)/* overload */;
	__fastcall TdxGPLinearGradientBrush(const Dxgdiplusapi::TdxGpRect &rect, unsigned color1, unsigned color2, Dxgdiplusapi::LinearGradientMode mode)/* overload */;
	Dxgdiplusapi::Status __fastcall SetLinearColors(unsigned color1, unsigned color2);
	Dxgdiplusapi::Status __fastcall GetLinearColors(/* out */ unsigned &color1, /* out */ unsigned &color2);
	Dxgdiplusapi::TdxGpRect __fastcall GetRectangle(void)/* overload */;
	__property Dxgdiplusapi::WrapMode WrapMode = {read=GetWrapMode, write=SetWrapMode, nodefault};
protected:
	/* TdxGPBrush.CreateNative */ inline __fastcall TdxGPLinearGradientBrush(void * nativeBrush, Dxgdiplusapi::Status AStatus) : TdxGPBrush(nativeBrush, AStatus) { }
	
public:
	/* TdxGPBrush.Destroy */ inline __fastcall virtual ~TdxGPLinearGradientBrush(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGPHatchBrush;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPHatchBrush : public TdxGPBrush
{
	typedef TdxGPBrush inherited;
	
public:
	__fastcall TdxGPHatchBrush(void)/* overload */;
	__fastcall TdxGPHatchBrush(Dxgdiplusapi::HatchStyle hatchStyle, unsigned foreColor, unsigned backColor)/* overload */;
	Dxgdiplusapi::HatchStyle __fastcall GetHatchStyle(void);
	unsigned __fastcall GetForegroundColor(void);
	unsigned __fastcall GetBackgroundColor(void);
protected:
	/* TdxGPBrush.CreateNative */ inline __fastcall TdxGPHatchBrush(void * nativeBrush, Dxgdiplusapi::Status AStatus) : TdxGPBrush(nativeBrush, AStatus) { }
	
public:
	/* TdxGPBrush.Destroy */ inline __fastcall virtual ~TdxGPHatchBrush(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGPPen;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPPen : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	void *FNativePen;
	Dxgdiplusapi::Status FLastResult;
	Dxgdiplusapi::PenAlignment __fastcall GetAlignment(void);
	unsigned __fastcall GetColor(void);
	TdxGPBrush* __fastcall GetBrush(void);
	float __fastcall GetWidth(void);
	void __fastcall SetAlignment(const Dxgdiplusapi::PenAlignment Value);
	void __fastcall SetColor(const unsigned Value);
	void __fastcall SetBrush(TdxGPBrush* const Value);
	void __fastcall SetWidth(const float Value);
	
protected:
	void __fastcall SetNativePen(void * ANativePen);
	Dxgdiplusapi::Status __fastcall SetStatus(Dxgdiplusapi::Status AStatus);
	
public:
	__fastcall TdxGPPen(unsigned color, float width)/* overload */;
	__fastcall TdxGPPen(TdxGPBrush* brush, float width)/* overload */;
	__fastcall virtual ~TdxGPPen(void);
	Dxgdiplusapi::Status __fastcall GetLastStatus(void);
	int __fastcall GetPenType(void);
	__property Dxgdiplusapi::PenAlignment ALignment = {read=GetAlignment, write=SetAlignment, nodefault};
	__property TdxGPBrush* Brush = {read=GetBrush, write=SetBrush};
	__property unsigned Color = {read=GetColor, write=SetColor, nodefault};
	__property float Width = {read=GetWidth, write=SetWidth};
};

#pragma pack(pop)

class DELPHICLASS TdxGPCanvas;
class DELPHICLASS TdxGPImage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPCanvas : public Dxgdiplusapi::TdxGpBase
{
	typedef Dxgdiplusapi::TdxGpBase inherited;
	
private:
	void *FHandle;
	TdxGPInterpolationMode __fastcall GetInterpolationMode(void);
	TdxGPSmoothingMode __fastcall GetSmoothingMode(void);
	void __fastcall SetInterpolationMode(TdxGPInterpolationMode AValue);
	void __fastcall SetSmoothingMode(TdxGPSmoothingMode AValue);
	
protected:
	void __fastcall CheckDestRect(System::Types::TRect &R);
	void __fastcall CreateHandle(HDC DC);
	void __fastcall FreeHandle(void);
	
public:
	__fastcall TdxGPCanvas(void * AHandle)/* overload */;
	__fastcall TdxGPCanvas(NativeUInt DC)/* overload */;
	__fastcall virtual ~TdxGPCanvas(void);
	HDC __fastcall GetHDC(void);
	void __fastcall ReleaseHDC(HDC DC);
	void __fastcall Clear(System::Uitypes::TColor AColor);
	void __fastcall Draw(TdxGPImage* AGraphic, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall Draw(TdxGPImage* AGraphic, const System::Types::TRect &R, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall DrawBitmap(Vcl::Graphics::TBitmap* ABitmap, const System::Types::TRect &R, System::Byte AAlpha = (System::Byte)(0xff));
	void __fastcall DrawTile(TdxGPImage* AGraphic, const System::Types::TRect &R, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall Arc(const System::Types::TRect &R, float AStartAngle, float ASweepAngle, System::Uitypes::TColor APenColor, float APenWidth = 1.000000E+00, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), System::Byte APenColorAlpha = (System::Byte)(0xff));
	void __fastcall Ellipse(const System::Types::TRect &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth = 1.000000E+00, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), System::Byte APenColorAlpha = (System::Byte)(0xff), System::Byte ABrushColorAlpha = (System::Byte)(0xff));
	void __fastcall Line(int X1, int Y1, int X2, int Y2, System::Uitypes::TColor APenColor, float APenWidth = 1.000000E+00, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), System::Byte APenColorAlpha = (System::Byte)(0xff));
	void __fastcall Pie(const System::Types::TRect &R, float AStartAngle, float ASweepAngle, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth = 1.000000E+00, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), System::Byte APenColorAlpha = (System::Byte)(0xff), System::Byte ABrushColorAlpha = (System::Byte)(0xff));
	void __fastcall Polygon(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth = 1.000000E+00, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), System::Byte APenColorAlpha = (System::Byte)(0xff), System::Byte ABrushColorAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall Polygon(Cxgeometry::TdxPointF const *APoints, const int APoints_Size, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth = 1.000000E+00, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), System::Byte APenColorAlpha = (System::Byte)(0xff), System::Byte ABrushColorAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall Polyline(System::Types::TPoint const *APoints, const int APoints_Size, System::Uitypes::TColor APenColor, float APenWidth = 1.000000E+00, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), System::Byte APenColorAlpha = (System::Byte)(0xff));
	void __fastcall Rectangle(const System::Types::TRect &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, float APenWidth = 1.000000E+00, Vcl::Graphics::TPenStyle APenStyle = (Vcl::Graphics::TPenStyle)(0x0), System::Byte APenColorAlpha = (System::Byte)(0xff), System::Byte ABrushColorAlpha = (System::Byte)(0xff));
	void __fastcall RoundRect(const System::Types::TRect &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, int ARadiusX, int ARadiusY, int APenWidth = 0x1, System::Byte APenColorAlpha = (System::Byte)(0xff), System::Byte ABrushColorAlpha = (System::Byte)(0xff));
	__property void * Handle = {read=FHandle};
	__property TdxGPInterpolationMode InterpolationMode = {read=GetInterpolationMode, write=SetInterpolationMode, nodefault};
	__property TdxGPSmoothingMode SmoothingMode = {read=GetSmoothingMode, write=SetSmoothingMode, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxGPGraphics;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPGraphics : public TdxGPCanvas
{
	typedef TdxGPCanvas inherited;
	
public:
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPGraphics(void * AHandle)/* overload */ : TdxGPCanvas(AHandle) { }
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPGraphics(NativeUInt DC)/* overload */ : TdxGPCanvas(DC) { }
	/* TdxGPCanvas.Destroy */ inline __fastcall virtual ~TdxGPGraphics(void) { }
	
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TdxGPPaintCanvasState
{
public:
	void *Handle;
	Vcl::Graphics::TBitmap* Buffer;
	System::Types::TRect DrawRect;
	HDC DC;
};


typedef System::DynamicArray<TdxGPPaintCanvasState> TdxGPPaintCanvasStates;

class DELPHICLASS TdxGPCustomPaintCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPCustomPaintCanvas : public TdxGPGraphics
{
	typedef TdxGPGraphics inherited;
	
private:
	Vcl::Graphics::TBitmap* FBuffer;
	System::Types::TRect FDrawRect;
	HDC FDrawDC;
	void __fastcall CreateBuffer(HDC DC, const System::Types::TRect &R);
	void __fastcall FreeBuffer(void);
	void __fastcall OutputBuffer(void);
	
protected:
	virtual void __fastcall SaveState(void);
	virtual void __fastcall RestoreState(void);
	
public:
	void __fastcall BeginPaint(HDC DC, const System::Types::TRect &R)/* overload */;
	void __fastcall BeginPaint(void * AHandle)/* overload */;
	void __fastcall EndPaint(void);
public:
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPCustomPaintCanvas(void * AHandle)/* overload */ : TdxGPGraphics(AHandle) { }
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPCustomPaintCanvas(NativeUInt DC)/* overload */ : TdxGPGraphics(DC) { }
	/* TdxGPCanvas.Destroy */ inline __fastcall virtual ~TdxGPCustomPaintCanvas(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGPPaintCanvas;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPPaintCanvas : public TdxGPCustomPaintCanvas
{
	typedef TdxGPCustomPaintCanvas inherited;
	
private:
	int FCounter;
	TdxGPPaintCanvasStates FSavedStates;
	void __fastcall SetCapacity(int AValue);
	
protected:
	virtual void __fastcall SaveState(void);
	virtual void __fastcall RestoreState(void);
	
public:
	__fastcall virtual ~TdxGPPaintCanvas(void);
public:
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPPaintCanvas(void * AHandle)/* overload */ : TdxGPCustomPaintCanvas(AHandle) { }
	/* TdxGPCanvas.Create */ inline __fastcall TdxGPPaintCanvas(NativeUInt DC)/* overload */ : TdxGPCustomPaintCanvas(DC) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGPMemoryStream;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPMemoryStream : public System::Classes::TMemoryStream
{
	typedef System::Classes::TMemoryStream inherited;
	
protected:
	virtual void * __fastcall Realloc(int &ANewCapacity);
public:
	/* TMemoryStream.Destroy */ inline __fastcall virtual ~TdxGPMemoryStream(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxGPMemoryStream(void) : System::Classes::TMemoryStream() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGPStreamAdapter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPStreamAdapter : public System::Classes::TStreamAdapter
{
	typedef System::Classes::TStreamAdapter inherited;
	
public:
	virtual HRESULT __stdcall Stat(/* out */ tagSTATSTG &StatStg, int StatFlag);
public:
	/* TStreamAdapter.Create */ inline __fastcall TdxGPStreamAdapter(System::Classes::TStream* Stream, System::Classes::TStreamOwnership Ownership) : System::Classes::TStreamAdapter(Stream, Ownership) { }
	/* TStreamAdapter.Destroy */ inline __fastcall virtual ~TdxGPStreamAdapter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxGPImageData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGPImageData : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool __fastcall GetIsEmpty(void);
	
protected:
	Dxcore::TRGBColors FBits;
	System::Types::TSize FBitsBounds;
	TdxGPMemoryStream* FData;
	System::Types::TSize FNewSize;
	void __fastcall Assign(TdxGPImageData* AData);
	void __fastcall FreeImageData(void);
	void __fastcall LoadFromBits(const Dxcore::TRGBColors ABits, const System::Types::TSize &ASize, bool AHasAlphaChannel);
	void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	
public:
	__fastcall virtual ~TdxGPImageData(void);
	__property bool Empty = {read=GetIsEmpty, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxGPImageData(void) : System::TObject() { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxGPImage : public Vcl::Graphics::TGraphic
{
	typedef Vcl::Graphics::TGraphic inherited;
	
private:
	void *FHandle;
	TdxGPImageData* FImageData;
	TdxImageDataFormat FImageDataFormat;
	bool FIsAlphaUsed;
	bool FIsAlphaUsedAssigned;
	bool __fastcall CheckAlphaUsed(void);
	System::Types::TRect __fastcall GetClientRect(void);
	void * __fastcall GetHandle(void);
	bool __fastcall GetHandleAllocated(void);
	TdxImageDataFormat __fastcall GetImageDataFormat(void);
	bool __fastcall GetIsAlphaUsed(void);
	void __fastcall RecognizeImageRawDataFormat(void);
	void __fastcall SetImageDataFormat(TdxImageDataFormat AValue);
	
protected:
	bool __fastcall CheckHasAlphaChannel(const Dxcore::TRGBColors ABits);
	void __fastcall CreateHandleFromBitmap(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall CreateHandleFromBits(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel);
	void __fastcall CreateHandleFromHBITMAP(HBITMAP ABitmap, HPALETTE APalette);
	void __fastcall CreateHandleFromImageData(void);
	void __fastcall CreateHandleFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall AssignFromGpImage(TdxGPImage* AGpImage);
	virtual void __fastcall AssignFromGraphic(Vcl::Graphics::TGraphic* AGraphic);
	virtual void __fastcall AssignTo(System::Classes::TPersistent* ADest);
	virtual void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect);
	void __fastcall FreeHandle(void);
	virtual bool __fastcall GetEmpty(void);
	virtual int __fastcall GetHeight(void);
	virtual bool __fastcall GetLoaded(void);
	System::Types::TSize __fastcall GetSize(void);
	virtual bool __fastcall GetTransparent(void);
	virtual int __fastcall GetWidth(void);
	void __fastcall SetHandle(void * AValue);
	virtual void __fastcall SetHeight(int Value);
	virtual void __fastcall SetWidth(int Value);
	virtual void __fastcall Changed(System::TObject* Sender);
	__property bool Loaded = {read=GetLoaded, nodefault};
	__property TdxGPImageData* ImageData = {read=FImageData};
	
public:
	__fastcall virtual TdxGPImage(void);
	__fastcall virtual TdxGPImage(const System::Types::TSize &ASize, unsigned AColor)/* overload */;
	__fastcall TdxGPImage(const System::Types::TRect &R, unsigned AColor)/* overload */;
	__fastcall TdxGPImage(int AWidth, int AHeight, unsigned AColor)/* overload */;
	__fastcall virtual TdxGPImage(Vcl::Graphics::TBitmap* ABitmap);
	__fastcall virtual TdxGPImage(HBITMAP ABitmap);
	__fastcall virtual TdxGPImage(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel);
	__fastcall virtual TdxGPImage(System::Classes::TStream* AStream);
	__fastcall virtual ~TdxGPImage(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* ASource);
	void __fastcall LoadFromBits(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel);
	virtual void __fastcall LoadFromClipboardFormat(System::Word AFormat, NativeUInt AData, HPALETTE APalette);
	void __fastcall LoadFromFieldValue(const System::Variant &AValue);
	void __fastcall LoadFromResource(NativeUInt AInstance, const System::UnicodeString AResName, System::WideChar * AResType);
	virtual void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall SaveToClipboardFormat(System::Word &AFormat, NativeUInt &AData, HPALETTE &APalette);
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
	void __fastcall SaveToStreamByCodec(System::Classes::TStream* AStream, TdxImageDataFormat AImageFormat);
	virtual TdxGPImage* __fastcall Clone(void);
	virtual void __fastcall ChangeColor(System::Uitypes::TColor AColor);
	virtual bool __fastcall Compare(TdxGPImage* AImage);
	void __fastcall ConvertToBitmap(void);
	virtual void __fastcall Clear(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetAsBitmap(void);
	Dxcore::TRGBColors __fastcall GetBitmapBits(void);
	TdxGPImage* __fastcall MakeComposition(TdxGPImage* AOverlayImage, System::Byte AOverlayAlpha)/* overload */;
	TdxGPImage* __fastcall MakeComposition(TdxGPImage* AOverlayImage, System::Byte AOverlayAlpha, System::Byte ASourceAlpha)/* overload */;
	void __fastcall HandleNeeded(void);
	virtual void __fastcall Resize(const int AWidth, const int AHeight)/* overload */;
	void __fastcall Resize(const System::Types::TSize &ASize)/* overload */;
	virtual void __fastcall SetBitmap(Vcl::Graphics::TBitmap* ABitmap);
	void __fastcall Scale(const int M, const int D);
	void __fastcall StretchDraw(HDC DC, const System::Types::TRect &ADest, const System::Types::TRect &ASource, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	void __fastcall StretchDraw(HDC DC, const System::Types::TRect &ADest, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property void * Handle = {read=GetHandle, write=SetHandle};
	__property bool HandleAllocated = {read=GetHandleAllocated, nodefault};
	__property TdxImageDataFormat ImageDataFormat = {read=GetImageDataFormat, write=SetImageDataFormat, nodefault};
	__property bool IsAlphaUsed = {read=GetIsAlphaUsed, nodefault};
	__property System::Types::TSize Size = {read=GetSize};
};


typedef System::TMetaClass* TdxGPImageClass;

class DELPHICLASS TdxSmartImage;
class PASCALIMPLEMENTATION TdxSmartImage : public TdxGPImage
{
	typedef TdxGPImage inherited;
	
protected:
	virtual void __fastcall ReadData(System::Classes::TStream* Stream);
	virtual void __fastcall WriteData(System::Classes::TStream* Stream);
public:
	/* TdxGPImage.Create */ inline __fastcall virtual TdxSmartImage(void) : TdxGPImage() { }
	/* TdxGPImage.CreateSize */ inline __fastcall virtual TdxSmartImage(const System::Types::TSize &ASize, unsigned AColor)/* overload */ : TdxGPImage(ASize, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxSmartImage(const System::Types::TRect &R, unsigned AColor)/* overload */ : TdxGPImage(R, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxSmartImage(int AWidth, int AHeight, unsigned AColor)/* overload */ : TdxGPImage(AWidth, AHeight, AColor) { }
	/* TdxGPImage.CreateFromBitmap */ inline __fastcall virtual TdxSmartImage(Vcl::Graphics::TBitmap* ABitmap) : TdxGPImage(ABitmap) { }
	/* TdxGPImage.CreateFromHBitmap */ inline __fastcall virtual TdxSmartImage(HBITMAP ABitmap) : TdxGPImage(ABitmap) { }
	/* TdxGPImage.CreateFromBits */ inline __fastcall virtual TdxSmartImage(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel) : TdxGPImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxGPImage.CreateFromStream */ inline __fastcall virtual TdxSmartImage(System::Classes::TStream* AStream) : TdxGPImage(AStream) { }
	/* TdxGPImage.Destroy */ inline __fastcall virtual ~TdxSmartImage(void) { }
	
};


class DELPHICLASS TdxPNGImage;
class PASCALIMPLEMENTATION TdxPNGImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxGPImage.Create */ inline __fastcall virtual TdxPNGImage(void) : TdxSmartImage() { }
	/* TdxGPImage.CreateSize */ inline __fastcall virtual TdxPNGImage(const System::Types::TSize &ASize, unsigned AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxPNGImage(const System::Types::TRect &R, unsigned AColor)/* overload */ : TdxSmartImage(R, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxPNGImage(int AWidth, int AHeight, unsigned AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxGPImage.CreateFromBitmap */ inline __fastcall virtual TdxPNGImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromHBitmap */ inline __fastcall virtual TdxPNGImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromBits */ inline __fastcall virtual TdxPNGImage(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel) : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxGPImage.CreateFromStream */ inline __fastcall virtual TdxPNGImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxGPImage.Destroy */ inline __fastcall virtual ~TdxPNGImage(void) { }
	
};


class DELPHICLASS TdxJPEGImage;
class PASCALIMPLEMENTATION TdxJPEGImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxGPImage.Create */ inline __fastcall virtual TdxJPEGImage(void) : TdxSmartImage() { }
	/* TdxGPImage.CreateSize */ inline __fastcall virtual TdxJPEGImage(const System::Types::TSize &ASize, unsigned AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxJPEGImage(const System::Types::TRect &R, unsigned AColor)/* overload */ : TdxSmartImage(R, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxJPEGImage(int AWidth, int AHeight, unsigned AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxGPImage.CreateFromBitmap */ inline __fastcall virtual TdxJPEGImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromHBitmap */ inline __fastcall virtual TdxJPEGImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromBits */ inline __fastcall virtual TdxJPEGImage(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel) : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxGPImage.CreateFromStream */ inline __fastcall virtual TdxJPEGImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxGPImage.Destroy */ inline __fastcall virtual ~TdxJPEGImage(void) { }
	
};


class DELPHICLASS TdxGIFImage;
class PASCALIMPLEMENTATION TdxGIFImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxGPImage.Create */ inline __fastcall virtual TdxGIFImage(void) : TdxSmartImage() { }
	/* TdxGPImage.CreateSize */ inline __fastcall virtual TdxGIFImage(const System::Types::TSize &ASize, unsigned AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxGIFImage(const System::Types::TRect &R, unsigned AColor)/* overload */ : TdxSmartImage(R, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxGIFImage(int AWidth, int AHeight, unsigned AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxGPImage.CreateFromBitmap */ inline __fastcall virtual TdxGIFImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromHBitmap */ inline __fastcall virtual TdxGIFImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromBits */ inline __fastcall virtual TdxGIFImage(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel) : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxGPImage.CreateFromStream */ inline __fastcall virtual TdxGIFImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxGPImage.Destroy */ inline __fastcall virtual ~TdxGIFImage(void) { }
	
};


class DELPHICLASS TdxTIFFImage;
class PASCALIMPLEMENTATION TdxTIFFImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxGPImage.Create */ inline __fastcall virtual TdxTIFFImage(void) : TdxSmartImage() { }
	/* TdxGPImage.CreateSize */ inline __fastcall virtual TdxTIFFImage(const System::Types::TSize &ASize, unsigned AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxTIFFImage(const System::Types::TRect &R, unsigned AColor)/* overload */ : TdxSmartImage(R, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxTIFFImage(int AWidth, int AHeight, unsigned AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxGPImage.CreateFromBitmap */ inline __fastcall virtual TdxTIFFImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromHBitmap */ inline __fastcall virtual TdxTIFFImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromBits */ inline __fastcall virtual TdxTIFFImage(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel) : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxGPImage.CreateFromStream */ inline __fastcall virtual TdxTIFFImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxGPImage.Destroy */ inline __fastcall virtual ~TdxTIFFImage(void) { }
	
};


class DELPHICLASS TdxBMPImage;
class PASCALIMPLEMENTATION TdxBMPImage : public TdxSmartImage
{
	typedef TdxSmartImage inherited;
	
public:
	virtual void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TdxGPImage.Create */ inline __fastcall virtual TdxBMPImage(void) : TdxSmartImage() { }
	/* TdxGPImage.CreateSize */ inline __fastcall virtual TdxBMPImage(const System::Types::TSize &ASize, unsigned AColor)/* overload */ : TdxSmartImage(ASize, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxBMPImage(const System::Types::TRect &R, unsigned AColor)/* overload */ : TdxSmartImage(R, AColor) { }
	/* TdxGPImage.CreateSize */ inline __fastcall TdxBMPImage(int AWidth, int AHeight, unsigned AColor)/* overload */ : TdxSmartImage(AWidth, AHeight, AColor) { }
	/* TdxGPImage.CreateFromBitmap */ inline __fastcall virtual TdxBMPImage(Vcl::Graphics::TBitmap* ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromHBitmap */ inline __fastcall virtual TdxBMPImage(HBITMAP ABitmap) : TdxSmartImage(ABitmap) { }
	/* TdxGPImage.CreateFromBits */ inline __fastcall virtual TdxBMPImage(int AWidth, int AHeight, const Dxcore::TRGBColors ABits, bool AHasAlphaChannel) : TdxSmartImage(AWidth, AHeight, ABits, AHasAlphaChannel) { }
	/* TdxGPImage.CreateFromStream */ inline __fastcall virtual TdxBMPImage(System::Classes::TStream* AStream) : TdxSmartImage(AStream) { }
	/* TdxGPImage.Destroy */ inline __fastcall virtual ~TdxBMPImage(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxGPGraphics* __fastcall dxGpBeginPaint(void * AHandle)/* overload */;
extern PACKAGE TdxGPGraphics* __fastcall dxGpBeginPaint(HDC DC, const System::Types::TRect &R)/* overload */;
extern PACKAGE void __fastcall dxGpEndPaint(TdxGPGraphics* &AGraphics);
extern PACKAGE TdxImageDataFormat __fastcall dxGetImageDataFormat(const GUID &AFormatId);
extern PACKAGE GUID __fastcall dxGetImageEncoder(TdxImageDataFormat AImageDataFormat)/* overload */;
extern PACKAGE void __fastcall dxGpDrawImage(void * AGraphics, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, void * AImage, System::Byte AAlpha = (System::Byte)(0xff))/* overload */;
extern PACKAGE void __fastcall dxGPDrawText(TdxGPGraphics* AGraphics, const System::UnicodeString AText, const System::Types::TRect &ARect, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Classes::TAlignment AHorzAlignment = (System::Classes::TAlignment)(0x0), System::Classes::TVerticalAlignment AVertAlignment = (System::Classes::TVerticalAlignment)(0x2), bool AWordWrap = false, Dxgdiplusapi::TdxGpTextRenderingHint ARendering = (Dxgdiplusapi::TdxGpTextRenderingHint)(0x0), int AAlpha = 0xff);
extern PACKAGE void __fastcall dxGpFillRect(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor, System::Byte AColorAlpha = (System::Byte)(0xff))/* overload */;
extern PACKAGE void __fastcall dxGpFillRect(void * AGraphics, const System::Types::TRect &R, unsigned AColor)/* overload */;
extern PACKAGE void __fastcall dxGpFillRectByGradient(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, Dxgdiplusapi::LinearGradientMode AMode, System::Byte AColor1Alpha = (System::Byte)(0xff), System::Byte AColor2Alpha = (System::Byte)(0xff))/* overload */;
extern PACKAGE void __fastcall dxGpFillRectByGradient(void * AGraphics, const System::Types::TRect &R, unsigned AColor1, unsigned AColor2, Dxgdiplusapi::LinearGradientMode AMode)/* overload */;
extern PACKAGE bool __fastcall dxGpIsDoubleBufferedNeeded(HDC DC);
extern PACKAGE BOOL __fastcall dxGpIsRectVisible(void * AGraphics, const System::Types::TRect &R);
extern PACKAGE void __fastcall dxGpTilePart(HDC DC, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, void * AImage);
extern PACKAGE void __fastcall dxGpTilePartEx(void * AGraphics, const System::Types::TRect &ADestRect, const System::Types::TRect &ASourceRect, void * AImage, System::Byte AAlpha = (System::Byte)(0xff));
extern PACKAGE void __fastcall dxGpResetRect(void * AGraphics, const System::Types::TRect &R);
extern PACKAGE void __fastcall dxGpRoundRect(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor APenColor, System::Uitypes::TColor ABrushColor, int ARadius, int APenWidth = 0x1, System::Byte APenColorAlpha = (System::Byte)(0xff), System::Byte ABrushColorAlpha = (System::Byte)(0xff));
extern PACKAGE TdxGPPaintCanvas* __fastcall dxGPPaintCanvas(void);
}	/* namespace Dxgdiplusclasses */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXGDIPLUSCLASSES)
using namespace Dxgdiplusclasses;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxgdiplusclassesHPP
