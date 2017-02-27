// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxGDIPlusAPI.pas' rev: 24.00 (Win64)

#ifndef DxgdiplusapiHPP
#define DxgdiplusapiHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <System.SysConst.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreGraphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxgdiplusapi
{
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<float> TSingleDynArray;

class DELPHICLASS TdxGpBase;
class PASCALIMPLEMENTATION TdxGpBase : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsGpUsed;
	
public:
	virtual void __fastcall AfterConstruction(void);
	__classmethod virtual System::TObject* __fastcall NewInstance();
	virtual void __fastcall FreeInstance(void);
public:
	/* TObject.Create */ inline __fastcall TdxGpBase(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxGpBase(void) { }
	
};


typedef BOOL __fastcall (*TgpImageAbort)(void);

typedef BOOL __stdcall (*GpEnumerateMetafileProc)(int ARecordType, unsigned AFlags, unsigned ADataSize, System::PByte AData, void * ACallbackData);

enum Unit_ : unsigned int { UnitWorld, UnitDisplay, UnitPixel, UnitPoint, UnitInch, UnitDocument, UnitMillimeter };

typedef Unit_ TdxGpUnit;

enum FillMode : unsigned int { FillModeAlternate, FillModeWinding };

typedef FillMode TdxGpFillMode;

enum WrapMode : unsigned int { WrapModeTile, WrapModeTileFlipX, WrapModeTileFlipY, WrapModeTileFlipXY, WrapModeClamp };

typedef WrapMode TdxGpWrapMode;

enum HatchStyle : unsigned int { HatchStyleHorizontal, HatchStyleVertical, HatchStyleForwardDiagonal, HatchStyleBackwardDiagonal, HatchStyleCross, HatchStyleDiagonalCross, HatchStyle05Percent, HatchStyle10Percent, HatchStyle20Percent, HatchStyle25Percent, HatchStyle30Percent, HatchStyle40Percent, HatchStyle50Percent, HatchStyle60Percent, HatchStyle70Percent, HatchStyle75Percent, HatchStyle80Percent, HatchStyle90Percent, HatchStyleLightDownwardDiagonal, HatchStyleLightUpwardDiagonal, HatchStyleDarkDownwardDiagonal, HatchStyleDarkUpwardDiagonal, HatchStyleWideDownwardDiagonal, HatchStyleWideUpwardDiagonal, HatchStyleLightVertical, HatchStyleLightHorizontal, HatchStyleNarrowVertical, HatchStyleNarrowHorizontal, HatchStyleDarkVertical, HatchStyleDarkHorizontal, 
	HatchStyleDashedDownwardDiagonal, HatchStyleDashedUpwardDiagonal, HatchStyleDashedHorizontal, HatchStyleDashedVertical, HatchStyleSmallConfetti, HatchStyleLargeConfetti, HatchStyleZigZag, HatchStyleWave, HatchStyleDiagonalBrick, HatchStyleHorizontalBrick, HatchStyleWeave, HatchStylePlaid, HatchStyleDivot, HatchStyleDottedGrid, HatchStyleDottedDiamond, HatchStyleShingle, HatchStyleTrellis, HatchStyleSphere, HatchStyleSmallGrid, HatchStyleSmallCheckerBoard, HatchStyleLargeCheckerBoard, HatchStyleOutlinedDiamond, HatchStyleSolidDiamond, HatchStyleTotal };

typedef unsigned TdxGpGraphicsState;

typedef unsigned TdxGpGraphicsContainer;

typedef int TdxGpPixelFormat;

typedef HatchStyle TdxGpHatchStyle;

enum DashStyle : unsigned int { DashStyleSolid, DashStyleDash, DashStyleDot, DashStyleDashDot, DashStyleDashDotDot, DashStyleCustom };

typedef DashStyle TdxGpDashStyle;

enum WarpMode : unsigned int { WarpModePerspective, WarpModeBilinear };

typedef WarpMode TdxGpWarpMode;

enum LinearGradientMode : unsigned int { LinearGradientModeHorizontal, LinearGradientModeVertical, LinearGradientModeForwardDiagonal, LinearGradientModeBackwardDiagonal };

typedef LinearGradientMode TdxGpLinearGradientMode;

enum PenAlignment : unsigned int { PenAlignmentCenter, PenAlignmentInset };

typedef PenAlignment TdxGpPenAlignment;

enum BrushType : unsigned int { BrushTypeSolidColor, BrushTypeHatchFill, BrushTypeTextureFill, BrushTypePathGradient, BrushTypeLinearGradient };

typedef BrushType TdxGpBrushType;

enum TdxGpLineCap : unsigned int { LineCapFlat, LineCapSquare, LineCapRound, LineCapTriangle, LineCapNoAnchor = 16, LineCapSquareAnchor, LineCapRoundAnchor, LineCapDiamondAnchor, LineCapArrowAnchor, LineCapCustom = 255, LineCapAnchorMask = 240 };

enum TdxGpDashCap : unsigned int { DashCapFlat, DashCapRound = 2, DashCapTriangle };

enum TdxGpLineJoin : unsigned int { LineJoinMiter, LineJoinBevel, LineJoinRound, LineJoinMiterClipped };

enum TdxGpCustomLineCapType : unsigned int { CustomLineCapTypeDefault, CustomLineCapTypeAdjustableArrow };

enum TdxGpImageType : unsigned int { ImageTypeUnknown, ImageTypeBitmap, ImageTypeMetafile };

enum TdxGpFlushIntention : unsigned int { FlushIntentionFlush, FlushIntentionSync };

enum TdxGpRotateFlipType : unsigned int { RotateNoneFlipNone, Rotate90FlipNone, Rotate180FlipNone, Rotate270FlipNone, RotateNoneFlipX, Rotate90FlipX, Rotate180FlipX, Rotate270FlipX };

enum TdxGpColorChannelFlags : unsigned int { ColorChannelFlagsC, ColorChannelFlagsM, ColorChannelFlagsY, ColorChannelFlagsK, ColorChannelFlagsLast };

struct DECLSPEC_DRECORD TGpPropertyItem
{
public:
	unsigned id;
	unsigned length;
	System::Word DataType;
	void *value;
};


typedef TGpPropertyItem *PGpPropertyItem;

enum TdxGpPixelOffsetMode: int { PixelOffsetModeInvalid = -1, PixelOffsetModeDefault, PixelOffsetModeHighSpeed, PixelOffsetModeHighQuality, PixelOffsetModeNone, PixelOffsetModeHalf };

enum TdxGpTextRenderingHint : unsigned int { TextRenderingHintSystemDefault, TextRenderingHintSingleBitPerPixelGridFit, TextRenderingHintSingleBitPerPixel, TextRenderingHintAntiAliasGridFit, TextRenderingHintAntiAlias, TextRenderingHintClearTypeGridFit };

enum TdxGpCoordinateSpace : unsigned int { CoordinateSpaceWorld, CoordinateSpacePage, CoordinateSpaceDevice };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPWMFRect16
{
public:
	short Left;
	short Top;
	short Right;
	short Bottom;
};
#pragma pack(pop)


typedef TdxPWMFRect16 *PPWMFRect16;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpWmfPlaceableFileHeader
{
public:
	unsigned Key;
	short Hmf;
	TdxPWMFRect16 BoundingBox;
	short Inch;
	unsigned Reserved;
	short Checksum;
};
#pragma pack(pop)


typedef TdxGpWmfPlaceableFileHeader *PGpWmfPlaceableFileHeader;

enum TdxGpMetafileFrameUnit : unsigned int { MetafileFrameUnitPixel = 2, MetafileFrameUnitPoint, MetafileFrameUnitInch, MetafileFrameUnitDocument, MetafileFrameUnitMillimeter, MetafileFrameUnitGdi };

enum TdxGpMetafileType : unsigned int { MetafileTypeInvalid, MetafileTypeWmf, MetafileTypeWmfPlaceable, MetafileTypeEmf, MetafileTypeEmfPlusOnly, MetafileTypeEmfPlusDual };

enum TdxGpEmfType : unsigned int { EmfTypeEmfOnly = 3, EmfTypeEmfPlusOnly, EmfTypeEmfPlusDual };

enum TdxGpStringAlignment : unsigned int { StringAlignmentNear, StringAlignmentCenter, StringAlignmentFar };

enum TdxGpStringFormatFlags : unsigned int { StringFormatFlagsNone, StringFormatFlagsDirectionRightToLeft, StringFormatFlagsDirectionVertical, StringFormatFlagsNoFitBlackBox = 0x4, StringFormatFlagsDisplayFormatControl = 0x20, StringFormatFlagsNoFontFallback = 0x400, StringFormatFlagsMeasureTrailingSpaces = 0x800, StringFormatFlagsNoWrap = 0x1000, StringFormatFlagsLineLimit = 0x2000, StringFormatFlagsNoClip = 0x4000 };

enum TdxGpStringTrimming : unsigned int { StringTrimmingNone, StringTrimmingCharacter, StringTrimmingWord, StringTrimmingEllipsisCharacter, StringTrimmingEllipsisWord, StringTrimmingEllipsisPath };

enum TdxGpStringDigitSubstitute : unsigned int { StringDigitSubstituteUser, StringDigitSubstituteNone, StringDigitSubstituteNational, StringDigitSubstituteTraditional };

typedef TdxGpStringDigitSubstitute *PdxGpStringDigitSubstitute;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpCharacterRange
{
public:
	int First;
	int Length;
};
#pragma pack(pop)


typedef TdxGpCharacterRange *PdxGpCharacterRange;

typedef int TdxGpPenType;

enum Status : unsigned int { Ok, GenericError, InvalidParameter, OutOfMemory, ObjectBusy, InsufficientBuffer, NotImplemented, Win32Error, WrongState, Aborted, FileNotFound, ValueOverflow, AccessDenied, UnknownImageFormat, FontFamilyNotFound, FontStyleNotFound, NotTrueTypeFont, UnsupportedGdiplusVersion, GdiplusNotInitialized, PropertyNotFound, PropertyNotSupported };

typedef Status TdxGpStatus;

enum TdxGpColorAdjustType : unsigned int { ColorAdjustTypeDefault, ColorAdjustTypeBitmap, ColorAdjustTypeBrush, ColorAdjustTypePen, ColorAdjustTypeText, ColorAdjustTypeCount, ColorAdjustTypeAny };

typedef System::StaticArray<System::StaticArray<float, 5>, 5> TdxGpColorMatrix;

typedef TdxGpColorMatrix *PdxGpColorMatrix;

enum TdxGpColorMatrixFlags : unsigned int { ColorMatrixFlagsDefault, ColorMatrixFlagsSkipGrays, ColorMatrixFlagsAltGray };

enum TGpCombineMode : unsigned int { CombineModeReplace, CombineModeIntersect, CombineModeUnion, CombineModeXor, CombineModeExclude, CombineModeComplement };

struct TdxGpSizeF;
typedef TdxGpSizeF *PdxGpSizeF;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpSizeF
{
public:
	float Width;
	float Height;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpSize
{
public:
	int Width;
	int Height;
};
#pragma pack(pop)


typedef TdxGpSize *PdxGpSize;

struct TdxGpPointF;
typedef TdxGpPointF *PdxGpPointF;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpPointF
{
public:
	float X;
	float Y;
};
#pragma pack(pop)


typedef System::DynamicArray<TdxGpPointF> TdxGpPointFDynArray;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpPoint
{
public:
	int X;
	int Y;
};
#pragma pack(pop)


typedef TdxGpPoint *PdxGpPoint;

typedef System::DynamicArray<TdxGpPoint> TdxGpPointDynArray;

struct TdxGpRectF;
typedef TdxGpRectF *PdxGpRectF;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpRectF
{
public:
	float X;
	float Y;
	float Width;
	float Height;
};
#pragma pack(pop)


typedef System::DynamicArray<TdxGpRectF> TdxGpRectFDynArray;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpRect
{
public:
	int X;
	int Y;
	int Width;
	int Height;
};
#pragma pack(pop)


typedef TdxGpRect *PdxGpRect;

typedef System::DynamicArray<TdxGpRect> TdxGpRectDynArray;

struct TdxGpImageCodecInfo;
typedef TdxGpImageCodecInfo *PdxGpImageCodecInfo;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxGpImageCodecInfo
{
public:
	GUID Clsid;
	GUID FormatID;
	void *CodecName;
	void *DllName;
	void *FormatDescription;
	void *FilenameExtension;
	void *MimeType;
	unsigned Flags;
	unsigned Version;
	unsigned SigCount;
	unsigned SigSize;
	System::Byte *SigPattern;
	System::Byte *SigMask;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TEncoderParameter
{
public:
	GUID Guid;
	unsigned NumberOfValues;
	unsigned Type_;
	void *Value;
};
#pragma pack(pop)


typedef TEncoderParameter *PEncoderParameter;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TEncoderParameters
{
public:
	unsigned Count;
	System::StaticArray<TEncoderParameter, 1> Parameter;
};
#pragma pack(pop)


typedef TEncoderParameters *PEncoderParameters;

enum DebugEventLevel : unsigned int { DebugEventLevelFatal, DebugEventLevelWarning };

typedef DebugEventLevel TDebugEventLevel;

typedef void __stdcall (*DebugEventProc)(DebugEventLevel level, System::WideChar * message);

typedef Status __stdcall (*NotificationHookProc)(/* out */ NativeInt &token);

typedef void __stdcall (*NotificationUnhookProc)(NativeInt token);

struct DECLSPEC_DRECORD GdiplusStartupInput
{
public:
	unsigned GdiplusVersion;
	DebugEventProc DebugEventCallback;
	BOOL SuppressBackgroundThread;
	BOOL SuppressExternalCodecs;
};


typedef GdiplusStartupInput TGdiplusStartupInput;

typedef GdiplusStartupInput *PGdiplusStartupInput;

#pragma pack(push,1)
struct DECLSPEC_DRECORD GdiplusStartupOutput
{
public:
	NotificationHookProc NotificationHook;
	NotificationUnhookProc NotificationUnhook;
};
#pragma pack(pop)


typedef GdiplusStartupOutput TGdiplusStartupOutput;

typedef GdiplusStartupOutput *PGdiplusStartupOutput;

typedef void * GpGraphics;

typedef unsigned ARGB;

typedef unsigned *PARGB;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGpColorPalette
{
public:
	unsigned Flags;
	unsigned Count;
	System::StaticArray<unsigned, 1> Entries;
};
#pragma pack(pop)


typedef TGpColorPalette *PGpColorPalette;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TGpColorMap
{
public:
	unsigned oldColor;
	unsigned newColor;
};
#pragma pack(pop)


typedef TGpColorMap *PGpColorMap;

enum TdxGpMatrixOrder : unsigned int { MatrixOrderPrepend, MatrixOrderAppend };

typedef System::Word *PUINT16;

typedef void * GpMetafile;

typedef void * GpBrush;

typedef void * GpTexture;

typedef void * GpRegion;

typedef void * GpSolidFill;

typedef void * GpLineGradient;

typedef void * GpMatrix;

typedef void * GpPathGradient;

typedef void * GpPathIterator;

typedef void * GpPath;

typedef void * GpFont;

typedef void * GpFontFamily;

typedef void * GpFontCollection;

typedef void * GpStringFormat;

typedef void * GpHatch;

typedef void * GpPen;

typedef void * GpImage;

typedef void * GpBitmap;

typedef void * GpCachedBitmap;

typedef void * GpImageAttributes;

typedef void * GpCustomLineCap;

typedef void * GpAdjustableArrowCap;

typedef Status GpStatus;

typedef FillMode GpFillMode;

typedef WrapMode GpWrapMode;

typedef Unit_ GpUnit;

typedef PdxGpPointF GpPointF;

typedef PdxGpPoint GpPoint;

typedef PdxGpRectF GpRectF;

typedef PdxGpRect GpRect;

typedef PdxGpSizeF GpSizeF;

typedef HatchStyle GpHatchStyle;

typedef DashStyle GpDashStyle;

typedef PenAlignment GpPenAlignment;

typedef int GpPenType;

typedef BrushType GpBrushType;

#pragma pack(push,1)
struct DECLSPEC_DRECORD BitmapData
{
public:
	unsigned Width;
	unsigned Height;
	int Stride;
	int PixelFormat;
	void *Scan0;
	unsigned Reserved;
};
#pragma pack(pop)


typedef BitmapData TBitmapData;

typedef BitmapData *PBitmapData;

class DELPHICLASS EdxGdipException;
class PASCALIMPLEMENTATION EdxGdipException : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
private:
	Status FStatus;
	
public:
	__fastcall EdxGdipException(Status AStatus);
	__property Status Status = {read=FStatus, nodefault};
public:
	/* Exception.CreateFmt */ inline __fastcall EdxGdipException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxGdipException(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxGdipException(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxGdipException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxGdipException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxGdipException(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxGdipException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxGdipException(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxGdipException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxGdipException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxGdipException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxGdipException(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 QualityModeInvalid = System::Int8(-1);
static const System::Int8 QualityModeDefault = System::Int8(0x0);
static const System::Int8 QualityModeLow = System::Int8(0x1);
static const System::Int8 QualityModeHigh = System::Int8(0x2);
static const System::Int8 InterpolationModeInvalid = System::Int8(-1);
static const System::Int8 InterpolationModeDefault = System::Int8(0x0);
static const System::Int8 InterpolationModeLowQuality = System::Int8(0x1);
static const System::Int8 InterpolationModeHighQuality = System::Int8(0x2);
static const System::Int8 InterpolationModeBilinear = System::Int8(0x3);
static const System::Int8 InterpolationModeBicubic = System::Int8(0x4);
static const System::Int8 InterpolationModeNearestNeighbor = System::Int8(0x5);
static const System::Int8 InterpolationModeHighQualityBilinear = System::Int8(0x6);
static const System::Int8 InterpolationModeHighQualityBicubic = System::Int8(0x7);
static const System::Int8 CompositingModeSourceOver = System::Int8(0x0);
static const System::Int8 CompositingModeSourceCopy = System::Int8(0x1);
static const System::Int8 CompositingQualityInvalid = System::Int8(-1);
static const System::Int8 CompositingQualityDefault = System::Int8(0x0);
static const System::Int8 CompositingQualityHighSpeed = System::Int8(0x1);
static const System::Int8 CompositingQualityHighQuality = System::Int8(0x2);
static const System::Int8 CompositingQualityGammaCorrected = System::Int8(0x3);
static const System::Int8 CompositingQualityAssumeLinear = System::Int8(0x4);
static const System::Int8 SmoothingModeInvalid = System::Int8(-1);
static const System::Int8 SmoothingModeDefault = System::Int8(0x0);
static const System::Int8 SmoothingModeHighSpeed = System::Int8(0x1);
static const System::Int8 SmoothingModeHighQuality = System::Int8(0x2);
static const System::Int8 SmoothingModeNone = System::Int8(0x3);
static const System::Int8 SmoothingModeAntiAlias = System::Int8(0x4);
static const int PixelFormat32bppPARGB = int(0xe200b);
extern PACKAGE GUID ImageFormatUndefined;
extern PACKAGE GUID ImageFormatMemoryBMP;
extern PACKAGE GUID ImageFormatBMP;
extern PACKAGE GUID ImageFormatEMF;
extern PACKAGE GUID ImageFormatWMF;
extern PACKAGE GUID ImageFormatJPEG;
extern PACKAGE GUID ImageFormatPNG;
extern PACKAGE GUID ImageFormatGIF;
extern PACKAGE GUID ImageFormatTIFF;
extern PACKAGE GUID ImageFormatEXIF;
extern PACKAGE GUID ImageFormatIcon;
static const HatchStyle HatchStyleLargeGrid = (HatchStyle)(4);
static const HatchStyle HatchStyleMin = (HatchStyle)(0);
static const HatchStyle HatchStyleMax = (HatchStyle)(52);
static const System::Int8 PenTypeSolidColor = System::Int8(0x0);
static const System::Int8 PenTypeHatchFill = System::Int8(0x1);
static const System::Int8 PenTypeTextureFill = System::Int8(0x2);
static const System::Int8 PenTypePathGradient = System::Int8(0x3);
static const System::Int8 PenTypeLinearGradient = System::Int8(0x4);
static const System::Int8 PenTypeUnknown = System::Int8(-1);
extern PACKAGE GUID PNGCodec;
extern PACKAGE GUID JPEGCodec;
extern PACKAGE GUID TIFFCodec;
extern PACKAGE GUID BMPCodec;
extern PACKAGE GUID GIFCodec;
extern PACKAGE void * __stdcall (*GdipAlloc)(unsigned ASize);
extern PACKAGE void __stdcall (*GdipFree)(void * APointer);
extern PACKAGE Status __stdcall (*GdiplusStartup)(/* out */ NativeInt &AToken, const GdiplusStartupInput &AInput, PGdiplusStartupOutput AOutput);
extern PACKAGE void __stdcall (*GdiplusShutdown)(NativeInt AToken);
extern PACKAGE Status __stdcall (*GdipCloneBrush)(void * ABrush, void * &AClonebrush);
extern PACKAGE Status __stdcall (*GdipDeleteBrush)(void * ABrush);
extern PACKAGE Status __stdcall (*GdipGetBrushType)(void * ABrush, BrushType &ABrushType);
extern PACKAGE Status __stdcall (*GdipCreateSolidFill)(unsigned AColor, void * &ABrush);
extern PACKAGE Status __stdcall (*GdipSetSolidFillColor)(void * ABrush, unsigned AColor);
extern PACKAGE Status __stdcall (*GdipGetSolidFillColor)(void * ABrush, unsigned &AColor);
extern PACKAGE Status __stdcall (*GdipCreatePathGradient)(PdxGpPointF APoints, int ACount, WrapMode AWrapMode, /* out */ void * &APolyGradient);
extern PACKAGE Status __stdcall (*GdipCreatePathGradientI)(PdxGpPoint APoints, int Acount, WrapMode AWrapMode, /* out */ void * &APolyGradient);
extern PACKAGE Status __stdcall (*GdipCreatePathGradientFromPath)(void * APath, /* out */ void * &APolyGradient);
extern PACKAGE Status __stdcall (*GdipGetPathGradientCenterColor)(void * ABrush, /* out */ unsigned &AColors);
extern PACKAGE Status __stdcall (*GdipSetPathGradientCenterColor)(void * ABrush, unsigned AColors);
extern PACKAGE Status __stdcall (*GdipGetPathGradientSurroundColorsWithCount)(void * ABrush, unsigned AColor, int &ACount);
extern PACKAGE Status __stdcall (*GdipSetPathGradientSurroundColorsWithCount)(void * ABrush, unsigned AColor, int &ACount);
extern PACKAGE Status __stdcall (*GdipGetPathGradientPath)(void * ABrush, void * APath);
extern PACKAGE Status __stdcall (*GdipSetPathGradientPath)(void * ABrush, void * APath);
extern PACKAGE Status __stdcall (*GdipGetPathGradientCenterPoint)(void * ABrush, PdxGpPointF APoints);
extern PACKAGE Status __stdcall (*GdipGetPathGradientCenterPointI)(void * ABrush, PdxGpPoint APoints);
extern PACKAGE Status __stdcall (*GdipSetPathGradientCenterPoint)(void * ABrush, PdxGpPointF APoints);
extern PACKAGE Status __stdcall (*GdipSetPathGradientCenterPointI)(void * ABrush, PdxGpPoint APoints);
extern PACKAGE Status __stdcall (*GdipGetPathGradientRect)(void * ABrush, PdxGpRectF ARect);
extern PACKAGE Status __stdcall (*GdipGetPathGradientRectI)(void * ABrush, PdxGpRect ARect);
extern PACKAGE Status __stdcall (*GdipGetPathGradientPointCount)(void * ABrush, int &ACount);
extern PACKAGE Status __stdcall (*GdipGetPathGradientSurroundColorCount)(void * ABrush, int &ACount);
extern PACKAGE Status __stdcall (*GdipSetPathGradientGammaCorrection)(void * ABrush, BOOL AUseGammaCorrection);
extern PACKAGE Status __stdcall (*GdipGetPathGradientGammaCorrection)(void * ABrush, BOOL &AUseGammaCorrection);
extern PACKAGE Status __stdcall (*GdipGetPathGradientBlendCount)(void * ABrush, int &ACount);
extern PACKAGE Status __stdcall (*GdipGetPathGradientBlend)(void * ABrush, Winapi::Windows::PSingle ABlend, Winapi::Windows::PSingle APositions, int ACount);
extern PACKAGE Status __stdcall (*GdipSetPathGradientBlend)(void * ABbrush, Winapi::Windows::PSingle ABlend, Winapi::Windows::PSingle APositions, int ACount);
extern PACKAGE Status __stdcall (*GdipGetPathGradientPresetBlendCount)(void * ABrush, int &ACount);
extern PACKAGE Status __stdcall (*GdipGetPathGradientPresetBlend)(void * ABrush, unsigned ABlend, Winapi::Windows::PSingle APositions, int ACount);
extern PACKAGE Status __stdcall (*GdipSetPathGradientPresetBlend)(void * ABrush, unsigned ABlend, Winapi::Windows::PSingle APositions, int ACount);
extern PACKAGE Status __stdcall (*GdipSetPathGradientSigmaBlend)(void * ABrush, float AFocus, float AScale);
extern PACKAGE Status __stdcall (*GdipSetPathGradientLinearBlend)(void * ABrush, float AFocus, float AScale);
extern PACKAGE Status __stdcall (*GdipGetPathGradientWrapMode)(void * ABrush, WrapMode &AWrapmode);
extern PACKAGE Status __stdcall (*GdipSetPathGradientWrapMode)(void * ABrush, WrapMode AWrapmode);
extern PACKAGE Status __stdcall (*GdipGetPathGradientTransform)(void * ABrush, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipSetPathGradientTransform)(void * ABrush, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipResetPathGradientTransform)(void * ABrush);
extern PACKAGE Status __stdcall (*GdipMultiplyPathGradientTransform)(void * ABrush, void * AMatrix, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipTranslatePathGradientTransform)(void * ABrush, float DX, float DY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipScalePathGradientTransform)(void * ABrush, float SX, float SY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipRotatePathGradientTransform)(void * ABrush, float AAngle, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipGetPathGradientFocusScales)(void * ABrush, float &AXScale, float &AYScale);
extern PACKAGE Status __stdcall (*GdipSetPathGradientFocusScales)(void * ABrush, float AXScale, float AYScale);
extern PACKAGE Status __stdcall (*GdipCreateLineBrush)(PdxGpPointF APoint1, PdxGpPointF APoint2, unsigned AColor1, unsigned AColor2, WrapMode AWrapMode, /* out */ void * &ALineGradient);
extern PACKAGE Status __stdcall (*GdipCreateLineBrushI)(PdxGpPoint APoint1, PdxGpPoint APoint2, unsigned AColor1, unsigned AColor2, WrapMode AWrapMode, /* out */ void * &ALineGradient);
extern PACKAGE Status __stdcall (*GdipCreateLineBrushFromRect)(const PdxGpRectF ARect, unsigned AColor1, unsigned AColor2, LinearGradientMode ALinearGradientMode, WrapMode AWrapMode, /* out */ void * &ALineGradient);
extern PACKAGE Status __stdcall (*GdipCreateLineBrushFromRectI)(const PdxGpRect ARect, unsigned Acolor1, unsigned AColor2, LinearGradientMode ALinearGradientMode, WrapMode AWrapMode, void * &ALineGradient);
extern PACKAGE Status __stdcall (*GdipCreateLineBrushFromRectWithAngle)(PdxGpRectF ARect, unsigned AColor1, unsigned AColor2, float AAngle, BOOL AIsAngleScalable, WrapMode AWrapMode, /* out */ void * &ALineGradient);
extern PACKAGE Status __stdcall (*GdipCreateLineBrushFromRectWithAngleI)(PdxGpRect ARect, unsigned AColor1, unsigned AColor2, float AAngle, BOOL AIsAngleScalable, WrapMode AWrapMode, /* out */ void * &ALineGradient);
extern PACKAGE Status __stdcall (*GdipGetLineRect)(void * ABrush, PdxGpRectF &ARect);
extern PACKAGE Status __stdcall (*GdipGetLineRectI)(void * ABrush, PdxGpRect &ARect);
extern PACKAGE Status __stdcall (*GdipSetLineColors)(void * ABrush, unsigned AColor1, unsigned AColor2);
extern PACKAGE Status __stdcall (*GdipGetLineColors)(void * ABrush, PARGB AColors);
extern PACKAGE Status __stdcall (*GdipSetLineGammaCorrection)(void * ABrush, BOOL AUseGammaCorrection);
extern PACKAGE Status __stdcall (*GdipGetLineGammaCorrection)(void * ABrush, /* out */ BOOL &AUseGammaCorrection);
extern PACKAGE Status __stdcall (*GdipGetLineBlendCount)(void * ABrush, /* out */ int &ACount);
extern PACKAGE Status __stdcall (*GdipGetLineBlend)(void * ABrush, Winapi::Windows::PSingle ABlend, Winapi::Windows::PSingle APositions, int ACount);
extern PACKAGE Status __stdcall (*GdipSetLineBlend)(void * ABrush, Winapi::Windows::PSingle ABlend, Winapi::Windows::PSingle APositions, int ACount);
extern PACKAGE Status __stdcall (*GdipGetLinePresetBlendCount)(void * ABrush, /* out */ int &ACount);
extern PACKAGE Status __stdcall (*GdipGetLinePresetBlend)(void * ABrush, unsigned ABlend, Winapi::Windows::PSingle APositions, int ACount);
extern PACKAGE Status __stdcall (*GdipSetLinePresetBlend)(void * ABrush, unsigned ABlend, Winapi::Windows::PSingle APositions, int ACount);
extern PACKAGE Status __stdcall (*GdipSetLineSigmaBlend)(void * ABrush, float AFocus, float AScale);
extern PACKAGE Status __stdcall (*GdipSetLineLinearBlend)(void * ABrush, float AFocus, float AScale);
extern PACKAGE Status __stdcall (*GdipSetLineWrapMode)(void * ABrush, WrapMode AWrapMode);
extern PACKAGE Status __stdcall (*GdipGetLineWrapMode)(void * ABrush, WrapMode AWrapMode);
extern PACKAGE Status __stdcall (*GdipGetLineTransform)(void * ABrush, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipSetLineTransform)(void * ABrush, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipResetLineTransform)(void * ABrush);
extern PACKAGE Status __stdcall (*GdipMultiplyLineTransform)(void * ABrush, void * AMatrix, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipTranslateLineTransform)(void * ABrush, float DX, float DY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipScaleLineTransform)(void * ABrush, float SX, float SY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipRotateLineTransform)(void * ABrush, float AAngle, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipCreateHatchBrush)(HatchStyle AHatchStyle, unsigned AForeColor, unsigned ABackColor, void * &ABrush);
extern PACKAGE Status __stdcall (*GdipGetHatchStyle)(void * ABrush, HatchStyle &AHatchStyle);
extern PACKAGE Status __stdcall (*GdipGetHatchForegroundColor)(void * ABrush, unsigned &AForeColor);
extern PACKAGE Status __stdcall (*GdipGetHatchBackgroundColor)(void * ABrush, unsigned &ABackColor);
extern PACKAGE Status __stdcall (*GdipCreatePen1)(unsigned AColor, float AWidth, Unit_ AUnit, void * &APen);
extern PACKAGE Status __stdcall (*GdipCreatePen2)(void * ABrush, float AWidth, Unit_ AUnit, void * &APen);
extern PACKAGE Status __stdcall (*GdipClonePen)(void * APen, void * &AClonePen);
extern PACKAGE Status __stdcall (*GdipDeletePen)(void * APen);
extern PACKAGE Status __stdcall (*GdipGetPenFillType)(void * APpen, int &APenType);
extern PACKAGE Status __stdcall (*GdipSetPenBrushFill)(void * APen, void * ABrush);
extern PACKAGE Status __stdcall (*GdipGetPenBrushFill)(void * APen, void * &ABrush);
extern PACKAGE Status __stdcall (*GdipSetPenColor)(void * APen, unsigned AColor);
extern PACKAGE Status __stdcall (*GdipGetPenColor)(void * APen, unsigned &AColor);
extern PACKAGE Status __stdcall (*GdipSetPenMode)(void * APen, PenAlignment APenMode);
extern PACKAGE Status __stdcall (*GdipGetPenMode)(void * pen, PenAlignment &penMode);
extern PACKAGE Status __stdcall (*GdipSetPenUnit)(void * APen, Unit_ AUnit);
extern PACKAGE Status __stdcall (*GdipGetPenUnit)(void * APen, Unit_ &AUnit);
extern PACKAGE Status __stdcall (*GdipSetPenWidth)(void * APen, float AWidth);
extern PACKAGE Status __stdcall (*GdipGetPenWidth)(void * APen, float &AWidth);
extern PACKAGE Status __stdcall (*GdipGetPenDashStyle)(void * APen, /* out */ DashStyle &ADashStyle);
extern PACKAGE Status __stdcall (*GdipSetPenDashStyle)(void * APen, DashStyle ADashStyle);
extern PACKAGE Status __stdcall (*GdipSetPenLineCap197819)(void * APen, TdxGpLineCap AStartCap, TdxGpLineCap AEndCap, TdxGpDashCap ADashCap);
extern PACKAGE Status __stdcall (*GdipSetPenStartCap)(void * APen, TdxGpLineCap AStartCap);
extern PACKAGE Status __stdcall (*GdipSetPenEndCap)(void * APen, TdxGpLineCap AEndCap);
extern PACKAGE Status __stdcall (*GdipSetPenDashCap197819)(void * APen, TdxGpDashCap ADashCap);
extern PACKAGE Status __stdcall (*GdipGetPenStartCap)(void * APen, /* out */ TdxGpLineCap &AStartCap);
extern PACKAGE Status __stdcall (*GdipGetPenEndCap)(void * APen, /* out */ TdxGpLineCap &AEndCap);
extern PACKAGE Status __stdcall (*GdipGetPenDashCap197819)(void * APen, /* out */ TdxGpDashCap &ADashCap);
extern PACKAGE Status __stdcall (*GdipSetPenLineJoin)(void * APen, TdxGpLineJoin ALineJoin);
extern PACKAGE Status __stdcall (*GdipGetPenLineJoin)(void * APen, TdxGpLineJoin &ALineJoin);
extern PACKAGE Status __stdcall (*GdipSetPenCustomStartCap)(void * APen, void * ACustomCap);
extern PACKAGE Status __stdcall (*GdipGetPenCustomStartCap)(void * APen, /* out */ void * &ACustomCap);
extern PACKAGE Status __stdcall (*GdipSetPenCustomEndCap)(void * APen, void * ACustomCap);
extern PACKAGE Status __stdcall (*GdipGetPenCustomEndCap)(void * APen, /* out */ void * &ACustomCap);
extern PACKAGE Status __stdcall (*GdipSetPenMiterLimit)(void * APen, float AMiterLimit);
extern PACKAGE Status __stdcall (*GdipGetPenMiterLimit)(void * APen, /* out */ float &AMiterLimit);
extern PACKAGE Status __stdcall (*GdipSetPenTransform)(void * APen, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipGetPenTransform)(void * APen, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipResetPenTransform)(void * APen);
extern PACKAGE Status __stdcall (*GdipMultiplyPenTransform)(void * APen, void * AMatrix, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipTranslatePenTransform)(void * APen, float DX, float DY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipScalePenTransform)(void * APen, float SX, float SY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipRotatePenTransform)(void * APen, float AAngle, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipGetPenDashOffset)(void * APen, /* out */ float &AOffset);
extern PACKAGE Status __stdcall (*GdipSetPenDashOffset)(void * APen, float AOffset);
extern PACKAGE Status __stdcall (*GdipGetPenDashCount)(void * APen, int &ACount);
extern PACKAGE Status __stdcall (*GdipSetPenDashArray)(void * APen, Winapi::Windows::PSingle ADash, int ACount);
extern PACKAGE Status __stdcall (*GdipGetPenDashArray)(void * APen, Winapi::Windows::PSingle ADash, int ACount);
extern PACKAGE Status __stdcall (*GdipGetPenCompoundCount)(void * APen, /* out */ int &ACount);
extern PACKAGE Status __stdcall (*GdipSetPenCompoundArray)(void * APen, Winapi::Windows::PSingle ADash, int ACount);
extern PACKAGE Status __stdcall (*GdipGetPenCompoundArray)(void * APen, Winapi::Windows::PSingle ADash, int ACount);
extern PACKAGE Status __stdcall (*GdipCreateCustomLineCap)(void * AFillPath, void * AStrokePath, TdxGpLineCap ABaseCap, float ABaseInset, /* out */ void * &ACustomCap);
extern PACKAGE Status __stdcall (*GdipDeleteCustomLineCap)(void * ACustomCap);
extern PACKAGE Status __stdcall (*GdipCloneCustomLineCap)(void * ACustomCap, /* out */ void * &AClonedCap);
extern PACKAGE Status __stdcall (*GdipGetCustomLineCapType)(void * ACustomCap, TdxGpCustomLineCapType &ACapType);
extern PACKAGE Status __stdcall (*GdipSetCustomLineCapStrokeCaps)(void * ACustomCap, TdxGpLineCap AStartCap);
extern PACKAGE Status __stdcall (*GdipGetCustomLineCapStrokeCaps)(void * ACustomCap, TdxGpLineCap &AStartCap, TdxGpLineCap &AEndCap);
extern PACKAGE Status __stdcall (*GdipSetCustomLineCapStrokeJoin)(void * ACustomCap, TdxGpLineJoin ALineJoin);
extern PACKAGE Status __stdcall (*GdipGetCustomLineCapStrokeJoin)(void * ACustomCap, TdxGpLineJoin &ALineJoin);
extern PACKAGE Status __stdcall (*GdipSetCustomLineCapBaseCap)(void * ACustomCap, TdxGpLineCap ABaseCap);
extern PACKAGE Status __stdcall (*GdipGetCustomLineCapBaseCap)(void * ACustomCap, TdxGpLineCap &ABaseCap);
extern PACKAGE Status __stdcall (*GdipSetCustomLineCapBaseInset)(void * ACustomCap, float AInset);
extern PACKAGE Status __stdcall (*GdipGetCustomLineCapBaseInset)(void * ACustomCap, float &AInset);
extern PACKAGE Status __stdcall (*GdipSetCustomLineCapWidthScale)(void * ACustomCap, float AWidthScale);
extern PACKAGE Status __stdcall (*GdipGetCustomLineCapWidthScale)(void * ACustomCap, float &AWidthScale);
extern PACKAGE Status __stdcall (*GdipCreateAdjustableArrowCap)(float AHeight, float AWidth, BOOL AIsFilled, /* out */ void * &ACap);
extern PACKAGE Status __stdcall (*GdipSetAdjustableArrowCapHeight)(void * ACap, float AHeight);
extern PACKAGE Status __stdcall (*GdipGetAdjustableArrowCapHeight)(void * ACap, float &AHeight);
extern PACKAGE Status __stdcall (*GdipSetAdjustableArrowCapWidth)(void * ACap, float AWidth);
extern PACKAGE Status __stdcall (*GdipGetAdjustableArrowCapWidth)(void * ACap, float &AWidth);
extern PACKAGE Status __stdcall (*GdipSetAdjustableArrowCapMiddleInset)(void * ACap, float AMiddleInset);
extern PACKAGE Status __stdcall (*GdipGetAdjustableArrowCapMiddleInset)(void * ACap, float &AMiddleInset);
extern PACKAGE Status __stdcall (*GdipSetAdjustableArrowCapFillState)(void * ACap, BOOL AFillState);
extern PACKAGE Status __stdcall (*GdipGetAdjustableArrowCapFillState)(void * ACap, BOOL &AFillState);
extern PACKAGE Status __stdcall (*GdipFlush)(void * AGraphics, TdxGpFlushIntention AIntention);
extern PACKAGE Status __stdcall (*GdipCreateFromHDC)(HDC DC, void * &AGraphics);
extern PACKAGE Status __stdcall (*GdipCreateFromHDC2)(HDC DC, NativeUInt AHDevice, /* out */ void * &AGraphics);
extern PACKAGE Status __stdcall (*GdipCreateFromHWND)(HWND AWnd, /* out */ void * &AGraphics);
extern PACKAGE Status __stdcall (*GdipCreateFromHWNDICM)(HWND AWnd, /* out */ void * &AGraphics);
extern PACKAGE Status __stdcall (*GdipDeleteGraphics)(void * AGraphics);
extern PACKAGE Status __stdcall (*GdipGetDC)(void * AGraphics, HDC &DC);
extern PACKAGE Status __stdcall (*GdipReleaseDC)(void * AGraphics, HDC DC);
extern PACKAGE Status __stdcall (*GdipGraphicsClear)(void * AGraphics, unsigned AColor);
extern PACKAGE HPALETTE __stdcall (*GdipCreateHalftonePalette)(void);
extern PACKAGE Status __stdcall (*GdipDrawLine)(void * AGraphics, void * APen, float X1, float Y1, float X2, float Y2);
extern PACKAGE Status __stdcall (*GdipDrawLineI)(void * AGraphics, void * APen, int X1, int Y1, int X2, int Y2);
extern PACKAGE Status __stdcall (*GdipDrawLines)(void * AGraphics, void * APen, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawLinesI)(void * AGraphics, void * APpen, const PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipFillRectangle)(void * AGraphics, void * ABrush, float X, float Y, float AWidth, float AHeight);
extern PACKAGE Status __stdcall (*GdipFillRectangleI)(void * graphics, void * brush, int x, int y, int width, int height);
extern PACKAGE Status __stdcall (*GdipFillRectangles)(void * AGraphics, void * ABrush, PdxGpRectF ARects, int ACount);
extern PACKAGE Status __stdcall (*GdipFillRectanglesI)(void * AGraphics, void * ABrush, PdxGpRect ARects, int ACount);
extern PACKAGE Status __stdcall (*GdipFillRegion)(void * AGraphics, void * ABrush, void * ARegion);
extern PACKAGE Status __stdcall (*GdipDrawImage)(void * AGraphics, void * AImage, float X, float Y);
extern PACKAGE Status __stdcall (*GdipDrawImageI)(void * AGraphics, void * AImage, int X, int Y);
extern PACKAGE Status __stdcall (*GdipDrawArc)(void * AGraphics, void * APen, float X, float Y, float AWidth, float AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipDrawArcI)(void * AGraphics, void * APen, int X, int Y, int AWidth, int AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipDrawBezier)(void * AGraphics, void * APen, float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4);
extern PACKAGE Status __stdcall (*GdipDrawBezierI)(void * AGraphics, void * APen, int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
extern PACKAGE Status __stdcall (*GdipDrawBeziers)(void * AGraphics, void * APen, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawBeziersI)(void * AGraphics, void * APen, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawRectangle)(void * AGraphics, void * APen, float X, float Y, float AWidth, float AHeight);
extern PACKAGE Status __stdcall (*GdipDrawRectangleI)(void * AGraphics, void * APen, int X, int Y, int AWdth, int AHeight);
extern PACKAGE Status __stdcall (*GdipDrawRectangles)(void * AGraphics, void * APen, PdxGpRectF ARects, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawRectanglesI)(void * AGraphics, void * APen, PdxGpRect ARects, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawEllipse)(void * AGraphics, void * APen, float X, float Y, float AWidth, float AHeight);
extern PACKAGE Status __stdcall (*GdipDrawEllipseI)(void * AGraphics, void * APen, int X, int Y, int AWidth, int AHeight);
extern PACKAGE Status __stdcall (*GdipDrawPie)(void * AGraphics, void * APpen, float X, float Y, float AWidth, float AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipDrawPieI)(void * AGraphics, void * APen, int X, int Y, int AWidth, int AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipDrawPolygon)(void * AGraphics, void * APen, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawPolygonI)(void * AGraphics, void * APen, const PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawCurve)(void * AGraphics, void * APen, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawCurveI)(void * AGraphics, void * APen, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawCurve2)(void * AGraphics, void * APen, PdxGpPointF APoints, int ACount, float ATension);
extern PACKAGE Status __stdcall (*GdipDrawCurve2I)(void * AGraphics, void * APen, const PdxGpPoint APoints, int ACount, float ATension);
extern PACKAGE Status __stdcall (*GdipDrawCurve3)(void * AGraphics, void * APen, PdxGpPointF APoints, int ACount, int AOffset, int ANumberOfSegments, float ATension);
extern PACKAGE Status __stdcall (*GdipDrawCurve3I)(void * AGraphics, void * APen, PdxGpPoint APoints, int ACount, int AOffset, int ANumberOfSegments, float ATension);
extern PACKAGE Status __stdcall (*GdipDrawClosedCurve)(void * AGraphics, void * APen, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawClosedCurveI)(void * AGraphics, void * APen, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawClosedCurve2)(void * AGraphics, void * APen, PdxGpPointF APoints, int ACount, float ATension);
extern PACKAGE Status __stdcall (*GdipDrawClosedCurve2I)(void * AGraphics, void * APen, const PdxGpPoint APoints, int ACount, float ATension);
extern PACKAGE Status __stdcall (*GdipFillPolygon)(void * AGraphics, void * ABrush, PdxGpPointF APoints, int ACount, FillMode AFillMode);
extern PACKAGE Status __stdcall (*GdipFillPolygonI)(void * AGraphics, void * ABrush, const PdxGpPoint APoints, int ACount, FillMode AFillMode);
extern PACKAGE Status __stdcall (*GdipFillPolygon2)(void * AGraphics, void * ABrush, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipFillPolygon2I)(void * AGraphics, void * ABrush, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipFillEllipse)(void * AGraphics, void * ABrush, float X, float Y, float AWidth, float AHeight);
extern PACKAGE Status __stdcall (*GdipFillEllipseI)(void * AGraphics, void * ABrush, int X, int Y, int AWidth, int AHeight);
extern PACKAGE Status __stdcall (*GdipFillPie)(void * AGraphics, void * ABrush, float X, float Y, float AWidth, float AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipFillPieI)(void * AGraphics, void * ABrush, int X, int Y, int AWidth, int AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipFillClosedCurve)(void * AGraphics, void * ABrush, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipFillClosedCurveI)(void * AGraphics, void * ABrush, const PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipFillClosedCurve2)(void * AGraphics, void * ABrush, PdxGpPointF APoints, int ACount, float ATension, FillMode AFillMode);
extern PACKAGE Status __stdcall (*GdipFillClosedCurve2I)(void * AGraphics, void * ABrush, PdxGpPoint APoints, int ACount, float ATension, FillMode AFillMode);
extern PACKAGE Status __stdcall (*GdipSetWorldTransform)(void * AGraphics, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipResetWorldTransform)(void * AGraphics);
extern PACKAGE Status __stdcall (*GdipMultiplyWorldTransform)(void * AGraphics, void * AMatrix, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipTranslateWorldTransform)(void * AGraphics, float DX, float DY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipScaleWorldTransform)(void * AGraphics, float SX, float SY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipRotateWorldTransform)(void * AGraphics, float AAngle, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipGetWorldTransform)(void * AGraphics, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipResetPageTransform)(void * AGraphics);
extern PACKAGE Status __stdcall (*GdipGetPageUnit)(void * AGraphics, Unit_ &AUnit);
extern PACKAGE Status __stdcall (*GdipGetPageScale)(void * AGraphics, float &AScale);
extern PACKAGE Status __stdcall (*GdipSetPageUnit)(void * AGraphics, Unit_ AUnit);
extern PACKAGE Status __stdcall (*GdipSetPageScale)(void * AGraphics, float AScale);
extern PACKAGE Status __stdcall (*GdipGetDpiX)(void * AGraphics, float &DPI);
extern PACKAGE Status __stdcall (*GdipGetDpiY)(void * AGraphics, float &DPI);
extern PACKAGE Status __stdcall (*GdipTransformPoints)(void * AGraphics, TdxGpCoordinateSpace ADestSpace, TdxGpCoordinateSpace ASrcSpace, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipTransformPointsI)(void * AGraphics, TdxGpCoordinateSpace ADestSpace, TdxGpCoordinateSpace ASrcSpace, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipGetNearestColor)(void * AGraphics, unsigned AColor);
extern PACKAGE Status __stdcall (*GdipLoadImageFromStream)(_di_IStream AStream, void * &AImage);
extern PACKAGE Status __stdcall (*GdipLoadImageFromStreamICM)(_di_IStream AStream, /* out */ void * &AImage);
extern PACKAGE Status __stdcall (*GdipSaveImageToStream)(void * AImage, _di_IStream AStream, System::PGUID AClsIDEncoder, void * AEncoderParams);
extern PACKAGE Status __stdcall (*GdipSaveImageToFile)(void * AImage, System::WideChar * AFilename, System::PGUID AClsIDEncoder, void * AEncoderParams);
extern PACKAGE Status __stdcall (*GdipGetImageRawFormat)(void * AImage, GUID &AFormat);
extern PACKAGE Status __stdcall (*GdipGetImagePixelFormat)(void * AImage, /* out */ int &AFormat);
extern PACKAGE Status __stdcall (*GdipGetImageThumbnail)(void * AImage, unsigned AThumbWidth, unsigned AThumbHeight, /* out */ void * &AThumbImage, TgpImageAbort ACallback, void * ACallbackData);
extern PACKAGE Status __stdcall (*GdipCreateHBITMAPFromBitmap)(void * AImage, HBITMAP &ABitmap, unsigned AColor);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromHICON)(HICON AHicon, /* out */ void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipCreateHICONFromBitmap)(void * ABitmap, /* out */ HICON &AHBMReturn);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromResource)(NativeUInt AHInstance, System::WideChar * AAlpBitmapName, /* out */ void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromHBITMAP)(HBITMAP AHBitmap, HPALETTE AHPalette, /* out */ void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromFile)(System::WideChar * AFileName, void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromStream)(_di_IStream AStream, void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromStreamICM)(_di_IStream AStream, /* out */ void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromFileICM)(System::WideChar * AFilename, void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipImageGetFrameCount)(void * AImage, System::PGUID ADimensionID, unsigned &ACount);
extern PACKAGE Status __stdcall (*GdipImageSelectActiveFrame)(void * AImage, System::PGUID ADimensionID, unsigned AFrameIndex);
extern PACKAGE Status __stdcall (*GdipImageRotateFlip)(void * AImage, TdxGpRotateFlipType ARotateFlipType);
extern PACKAGE Status __stdcall (*GdipGetImagePalette)(void * AImage, PGpColorPalette APalette, int ASize);
extern PACKAGE Status __stdcall (*GdipSetImagePalette)(void * AImage, PGpColorPalette APalette);
extern PACKAGE Status __stdcall (*GdipGetImagePaletteSize)(void * AImage, int &ASize);
extern PACKAGE Status __stdcall (*GdipGetPropertyCount)(void * AImage, unsigned &ANumOfProperty);
extern PACKAGE Status __stdcall (*GdipGetPropertyIdList)(void * AImage, unsigned ANumOfProperty, Winapi::Activex::PPropID AList);
extern PACKAGE Status __stdcall (*GdipGetPropertyItemSize)(void * AImage, unsigned APropId, unsigned &ASize);
extern PACKAGE Status __stdcall (*GdipGetPropertyItem)(void * AImage, unsigned APropId, unsigned APpropSize, PGpPropertyItem ABuffer);
extern PACKAGE Status __stdcall (*GdipGetPropertySize)(void * AImage, unsigned &ATotalBufferSize, unsigned &ANumProperties);
extern PACKAGE Status __stdcall (*GdipGetAllPropertyItems)(void * AImage, unsigned ATotalBufferSize, unsigned ANumProperties, PGpPropertyItem AAllItems);
extern PACKAGE Status __stdcall (*GdipRemovePropertyItem)(void * AImage, unsigned APropId);
extern PACKAGE Status __stdcall (*GdipSetPropertyItem)(void * AImage, PGpPropertyItem AItem);
extern PACKAGE Status __stdcall (*GdipImageForceValidation)(void * AImage);
extern PACKAGE Status __stdcall (*GdipLoadImageFromFile)(System::WideChar * AFileName, void * &AImage);
extern PACKAGE Status __stdcall (*GdipLoadImageFromFileICM)(System::WideChar * AFileName, /* out */ void * &AImage);
extern PACKAGE Status __stdcall (*GdipGetImageDimension)(void * AImage, float &AWidth, float &AHeight);
extern PACKAGE Status __stdcall (*GdipDrawImageRect)(void * AGraphics, void * AImage, float X, float Y, float AWidth, float AHeight);
extern PACKAGE Status __stdcall (*GdipDrawImageRectI)(void * AGraphics, void * AImage, int X, int Y, int AWidth, int AHeight);
extern PACKAGE Status __stdcall (*GdipDrawImagePoints)(void * AGraphics, void * AImage, PdxGpPointF ADstPoints, int ACount);
extern PACKAGE Status __stdcall (*GdipDrawImagePointsI)(void * AGraphics, void * AImage, PdxGpPoint ADstPoints, int ACount);
extern PACKAGE Status __stdcall (*GdipImageGetFrameDimensionsCount)(void * AImage, unsigned &ACount);
extern PACKAGE Status __stdcall (*GdipImageGetFrameDimensionsList)(void * AImage, System::PGUID ADimensionIDs, unsigned ACount);
extern PACKAGE Status __stdcall (*GdipDisposeImage)(void * AImage);
extern PACKAGE Status __stdcall (*GdipGetImageDecodersSize)(/* out */ unsigned &ANumDecoders, /* out */ unsigned &ASize);
extern PACKAGE Status __stdcall (*GdipGetImageDecoders)(unsigned ANumDecoders, unsigned ASize, PdxGpImageCodecInfo ADecoders);
extern PACKAGE Status __stdcall (*GdipGetImageEncodersSize)(/* out */ int &ANumEncoders, /* out */ int &ASize);
extern PACKAGE Status __stdcall (*GdipGetImageEncoders)(int ANumEncoders, int ASize, PdxGpImageCodecInfo AEncoders);
extern PACKAGE Status __stdcall (*GdipGetImageType)(void * AImage, TdxGpImageType &AType);
extern PACKAGE Status __stdcall (*GdipGetEncoderParameterListSize)(void * AImage, System::PGUID AClsIDEncoder, /* out */ unsigned &ASize);
extern PACKAGE Status __stdcall (*GdipGetEncoderParameterList)(void * AImage, System::PGUID AClsIDEncoder, unsigned ASize, PEncoderParameters ABuffer);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromGdiDib)(Winapi::Windows::PBitmapInfo AGdiBitmapInfo, void * AGdiBitmapData, /* out */ void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromScan0)(int AWidth, int AHeight, int AStrIDE, int AFormat, System::PByte AScan0, /* out */ void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipBitmapLockBits)(void * ABitmap, PdxGpRect ARect, unsigned AFlags, int AFormat, PBitmapData ALockedBitmapData);
extern PACKAGE Status __stdcall (*GdipBitmapUnlockBits)(void * ABitmap, PBitmapData ALockedBitmapData);
extern PACKAGE Status __stdcall (*GdipBitmapGetPixel)(void * ABitmap, int X, int Y, unsigned &AColor);
extern PACKAGE Status __stdcall (*GdipBitmapSetPixel)(void * ABitmap, int X, int Y, unsigned AColor);
extern PACKAGE Status __stdcall (*GdipBitmapSetResolution)(void * ABitmap, float AXDPI, float AYDPI);
extern PACKAGE Status __stdcall (*GdipDrawImageRectRect)(void * AGraphics, void * AImage, float ADstX, float ADstY, float ADstWidth, float ADstHeight, float ASrcX, float ASrcY, float ASrcWidth, float ASrcHeight, Unit_ ASrcUnit, void * AImageAttributes, TgpImageAbort ACallback, void * ACallbackData);
extern PACKAGE Status __stdcall (*GdipDrawImageRectRectI)(void * AGraphics, void * AImage, int ADstX, int ADstY, int ADstWidth, int ADstHeight, int ASrcX, int ASrcY, int ASrcWidth, int ASrcHeight, Unit_ ASrcUnit, void * AImageAttributes, TgpImageAbort ACallback, void * ACallbackData);
extern PACKAGE Status __stdcall (*GdipDrawImagePointRect)(void * AGraphics, void * AImage, float X, float Y, float ASrcX, float ASrcY, float ASrcWidth, float ASrcHeight, Unit_ ASrcUnit);
extern PACKAGE Status __stdcall (*GdipDrawImagePointRectI)(void * AGraphics, void * AImage, int X, int Y, int ASrcX, int ASrcY, int ASrcWidth, int ASrcHeight, Unit_ ASrcUnit);
extern PACKAGE Status __stdcall (*GdipDrawImagePointsRect)(void * AGraphics, void * AImage, PdxGpPointF APoints, int ACount, float ASrcX, float ASrcY, float ASrcWidth, float ASrcHeight, Unit_ ASrcUnit, void * AImageAttributes, TgpImageAbort ACallback, void * ACallbackData);
extern PACKAGE Status __stdcall (*GdipDrawImagePointsRectI)(void * AGraphics, void * AImage, PdxGpPointF APoints, int ACount, int ASrcX, int ASrcY, int ASrcWidth, int ASrcHeight, Unit_ ASrcUnit, void * AImageAttributes, TgpImageAbort ACallback, void * ACallbackData);
extern PACKAGE Status __stdcall (*GdipCloneImage)(void * AImage, /* out */ void * &ACloneImage);
extern PACKAGE Status __stdcall (*GdipCreateTexture)(void * AImage, WrapMode AWrapmode, void * &ATexture);
extern PACKAGE Status __stdcall (*GdipCreateTexture2)(void * AImage, WrapMode AWwrapmode, float X, float Y, float AWidth, float AHeight, /* out */ void * &ATexture);
extern PACKAGE Status __stdcall (*GdipCreateTexture2I)(void * AImage, WrapMode AWrapMode, int X, int Y, int AWidth, int AHeight, /* out */ void * &ATexture);
extern PACKAGE Status __stdcall (*GdipCreateTextureIA)(void * AImage, void * AImageAttributes, float X, float Y, float AWidth, float AHeight, /* out */ void * &ATexture);
extern PACKAGE Status __stdcall (*GdipCreateTextureIAI)(void * AImage, void * AImageAttributesibutes, int X, int Y, int AWidth, int AHeight, /* out */ void * &ATexture);
extern PACKAGE Status __stdcall (*GdipGetTextureTransform)(void * ABrush, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipResetTextureTransform)(void * ABrush);
extern PACKAGE Status __stdcall (*GdipMultiplyTextureTransform)(void * ABrush, void * AMatrix, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipTranslateTextureTransform)(void * ABrush, float DX, float DY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipScaleTextureTransform)(void * ABrush, float SX, float SY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipRotateTextureTransform)(void * ABrush, float AAngle, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipSaveAdd)(void * AImage, void * AEncoderParams);
extern PACKAGE Status __stdcall (*GdipSaveAddImage)(void * AImage, void * ANewImage, void * AEncoderParams);
extern PACKAGE Status __stdcall (*GdipSetTextureWrapMode)(void * ABrush, WrapMode AWrapmode);
extern PACKAGE Status __stdcall (*GdipGetTextureWrapMode)(void * ABrush, WrapMode &AWrapmode);
extern PACKAGE Status __stdcall (*GdipGetTextureImage)(void * ABrush, /* out */ void * &AImage);
extern PACKAGE Status __stdcall (*GdipCreateImageAttributes)(/* out */ void * &AImageAttributes);
extern PACKAGE Status __stdcall (*GdipCloneImageAttributes)(void * AImageAttributes, /* out */ void * &ACloneImageAttr);
extern PACKAGE Status __stdcall (*GdipDisposeImageAttributes)(void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesToIdentity)(void * AImageAttributes, TdxGpColorAdjustType AType);
extern PACKAGE Status __stdcall (*GdipResetImageAttributes)(void * AImageAttributes, TdxGpColorAdjustType AType);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesColorMatrix)(void * AImageAttributes, TdxGpColorAdjustType AType, BOOL AEnableFlag, PdxGpColorMatrix AColorMatrix, PdxGpColorMatrix AGrayMatrix, TdxGpColorMatrixFlags AFlags);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesThreshold)(void * AImageAttributes, TdxGpColorAdjustType AType, BOOL AEnableFlag, float AThreshold);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesGamma)(void * AImageAttributes, TdxGpColorAdjustType AType, BOOL AEnableFlag, float AGamma);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesColorKeys)(void * AImageAttributes, TdxGpColorAdjustType AType, BOOL AEnableFlag, unsigned AColorLow, unsigned AColorHigh);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesOutputChannel)(void * AImageAttributes, TdxGpColorAdjustType AType, BOOL AEnableFlag, TdxGpColorChannelFlags AChannelFlags);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesOutputChannelColorProfile)(void * AImageAttributes, TdxGpColorAdjustType AType, BOOL AEnableFlag, System::WideChar * AColorProfileFilename);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesRemapTable)(void * AImageAttributes, TdxGpColorAdjustType AType, BOOL AEnableFlag, unsigned AMapSize, PGpColorMap AMap);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesWrapMode)(void * AImageAttributes, WrapMode AWrap, unsigned AColor, BOOL AClamp);
extern PACKAGE Status __stdcall (*GdipSetImageAttributesICMMode)(void * AImageAttributes, BOOL On_);
extern PACKAGE Status __stdcall (*GdipGetImageAttributesAdjustedPalette)(void * AImageAttributes, PGpColorPalette AColorPalette, TdxGpColorAdjustType AColorAdjustType);
extern PACKAGE Status __stdcall (*GdipAddPathArc)(void * APath, float X, float Y, float Width, float Height, float StartAngle, float SweepAngle);
extern PACKAGE Status __stdcall (*GdipAddPathLine)(void * APath, float X1, float Y1, float X2, float Y2);
extern PACKAGE Status __stdcall (*GdipAddPathLine2)(void * APath, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathBezier)(void * APath, float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4);
extern PACKAGE Status __stdcall (*GdipAddPathBeziers)(void * APath, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathCurve)(void * APath, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathCurve2)(void * APath, PdxGpPointF APoints, int ACount, float ATension);
extern PACKAGE Status __stdcall (*GdipAddPathCurve3)(void * APath, PdxGpPointF APoints, int ACount, int AOffset, int ANumberOfSegments, float ATension);
extern PACKAGE Status __stdcall (*GdipAddPathClosedCurve)(void * APath, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathClosedCurve2)(void * APath, PdxGpPointF APoints, int ACount, float ATension);
extern PACKAGE Status __stdcall (*GdipAddPathRectangle)(void * APath, float X, float Y, float AWidth, float AHeight);
extern PACKAGE Status __stdcall (*GdipAddPathRectangles)(void * APath, PdxGpRectF ARects, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathEllipse)(void * APath, float X, float Y, float AWidth, float AHeight);
extern PACKAGE Status __stdcall (*GdipAddPathPie)(void * APath, float X, float Y, float AWidth, float AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipAddPathPolygon)(void * APath, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathPath)(void * APath, void * AAddingPath, BOOL AConnect);
extern PACKAGE Status __stdcall (*GdipAddPathString)(void * APath, System::WideChar * AString, int ALength, void * AFamily, int AStyle, float AEmSize, PdxGpRectF ALayoutRect, void * AFormat);
extern PACKAGE Status __stdcall (*GdipAddPathStringI)(void * APath, System::WideChar * AString, int ALength, void * AFamily, int AStyle, float AEmSize, PdxGpRect ALayoutRect, void * AFormat);
extern PACKAGE Status __stdcall (*GdipAddPathLineI)(void * APath, int X1, int Y1, int X2, int Y2);
extern PACKAGE Status __stdcall (*GdipAddPathLine2I)(void * APath, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathArcI)(void * APath, int X, int Y, int AWidth, int AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipAddPathBezierI)(void * APath, int X1, int Y1, int X2, int Y2, int X3, int Y3, int X4, int Y4);
extern PACKAGE Status __fastcall (*GdipAddPathBeziersI)(void * APath, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathCurveI)(void * APath, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathCurve2I)(void * APath, PdxGpPoint APoints, int ACount, float ATension);
extern PACKAGE Status __stdcall (*GdipAddPathCurve3I)(void * APath, PdxGpPoint APoints, int ACount, int AOffset, int ANumberOfSegments, float ATension);
extern PACKAGE Status __stdcall (*GdipAddPathClosedCurveI)(void * APath, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathClosedCurve2I)(void * APath, PdxGpPoint APoints, int ACount, float ATension);
extern PACKAGE Status __stdcall (*GdipAddPathRectangleI)(void * APath, int X, int Y, int AWidth, int AHeight);
extern PACKAGE Status __stdcall (*GdipAddPathRectanglesI)(void * APath, PdxGpRect ARects, int ACount);
extern PACKAGE Status __stdcall (*GdipAddPathEllipseI)(void * APath, int X, int Y, int AWidth, int AHeight);
extern PACKAGE Status __stdcall (*GdipAddPathPieI)(void * APath, int X, int Y, int AWidth, int AHeight, float AStartAngle, float ASweepAngle);
extern PACKAGE Status __stdcall (*GdipAddPathPolygonI)(void * APath, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipFlattenPath)(void * APath, void * AMatrix, float AFlatness);
extern PACKAGE Status __stdcall (*GdipWindingModeOutline)(void * APath, void * AMatrix, float AFlatness);
extern PACKAGE Status __stdcall (*GdipWidenPath)(void * ANativePath, void * APen, void * AMatrix, float AFlatness);
extern PACKAGE Status __stdcall (*GdipWarpPath)(void * APath, void * AMatrix, PdxGpPointF APoints, int ACount, float ASrcX, float ASrcY, float ASrcWidth, float ASrcHeight, WarpMode AWarpMode, float AFlatness);
extern PACKAGE Status __stdcall (*GdipTransformPath)(void * APath, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipGetPathWorldBounds)(void * APath, PdxGpRectF ABounds, void * AMatrix, void * APen);
extern PACKAGE Status __stdcall (*GdipGetPathWorldBoundsI)(void * APath, PdxGpRect ABounds, void * AMatrix, void * APen);
extern PACKAGE Status __stdcall (*GdipIsVisiblePathPoint)(void * APath, float X, float Y, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsVisiblePathPointI)(void * APath, int X, int Y, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsOutlineVisiblePathPoint)(void * APath, float X, float Y, void * APen, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsOutlineVisiblePathPointI)(void * APath, int X, int Y, void * APen, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipCreatePath)(FillMode AFillMode, /* out */ void * &APath);
extern PACKAGE Status __stdcall (*GdipCreatePath2)(PdxGpPointF APoint, System::PByte AValue1, int AValue2, FillMode AFillMode, /* out */ void * &APath);
extern PACKAGE Status __stdcall (*GdipCreatePath2I)(PdxGpPoint APoint, System::PByte AValue1, int AValue2, FillMode AFillMode, /* out */ void * &APath);
extern PACKAGE Status __stdcall (*GdipClonePath)(void * APath, /* out */ void * &AClonePath);
extern PACKAGE Status __stdcall (*GdipDeletePath)(void * APath);
extern PACKAGE Status __stdcall (*GdipResetPath)(void * APath);
extern PACKAGE Status __stdcall (*GdipGetPointCount)(void * APath, /* out */ int &ACount);
extern PACKAGE Status __stdcall (*GdipGetPathTypes)(void * APath, System::PByte ATypes, int ACount);
extern PACKAGE Status __stdcall (*GdipGetPathPoints)(void * APath, PdxGpPointF APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipGetPathPointsI)(void * APath, PdxGpPoint APoints, int ACount);
extern PACKAGE Status __stdcall (*GdipGetPathFillMode)(void * APath, FillMode &AFillMode);
extern PACKAGE Status __stdcall (*GdipSetPathFillMode)(void * APath, FillMode FillMode);
extern PACKAGE Status __stdcall (*GdipGetPathData)(void * APath, void * APathData);
extern PACKAGE Status __stdcall (*GdipDrawPath)(void * AGraphics, void * APen, void * APath);
extern PACKAGE Status __stdcall (*GdipFillPath)(void * AGraphics, void * ABrush, void * APath);
extern PACKAGE Status __stdcall (*GdipStartPathFigure)(void * APath);
extern PACKAGE Status __stdcall (*GdipClosePathFigure)(void * APath);
extern PACKAGE Status __stdcall (*GdipClosePathFigures)(void * APath);
extern PACKAGE Status __stdcall (*GdipSetPathMarker)(void * APath);
extern PACKAGE Status __stdcall (*GdipClearPathMarkers)(void * APath);
extern PACKAGE Status __stdcall (*GdipReversePath)(void * APath);
extern PACKAGE Status __stdcall (*GdipGetPathLastPoint)(void * APath, PdxGpPointF ALastPoint);
extern PACKAGE Status __stdcall (*GdipCreatePathIter)(/* out */ void * &AIterator, void * APath);
extern PACKAGE Status __stdcall (*GdipDeletePathIter)(void * AIterator);
extern PACKAGE Status __stdcall (*GdipPathIterNextSubpath)(void * AIterator, int &AResultCount, int &AStartIndex, int &AEndIndex, /* out */ BOOL &AIsClosed);
extern PACKAGE Status __stdcall (*GdipPathIterNextSubpathPath)(void * AIterator, int &AResultCount, void * APath, /* out */ BOOL &AIsClosed);
extern PACKAGE Status __stdcall (*GdipPathIterNextPathType)(void * AIterator, int &AResultCount, System::PByte APathType, int &AStartIndex, int &AEndIndex);
extern PACKAGE Status __stdcall (*GdipPathIterNextMarker)(void * AIterator, int &AResultCount, int &AStartIndex, int &AEndIndex);
extern PACKAGE Status __stdcall (*GdipPathIterNextMarkerPath)(void * AIterator, int &AResultCount, void * APath);
extern PACKAGE Status __stdcall (*GdipPathIterGetCount)(void * AIterator, /* out */ int &ACount);
extern PACKAGE Status __stdcall (*GdipPathIterGetSubpathCount)(void * AIterator, /* out */ int &ACcount);
extern PACKAGE Status __stdcall (*GdipPathIterIsValid)(void * AIterator, /* out */ BOOL &AValid);
extern PACKAGE Status __stdcall (*GdipPathIterHasCurve)(void * AIterator, /* out */ BOOL &AHasCurve);
extern PACKAGE Status __stdcall (*GdipPathIterRewind)(void * AIterator);
extern PACKAGE Status __stdcall (*GdipPathIterEnumerate)(void * AIterator, int &ARresultCount, PdxGpPointF APoints, System::PByte ATypes, int ACount);
extern PACKAGE Status __stdcall (*GdipPathIterCopyData)(void * AIterator, int &AResultCount, PdxGpPointF APpoints, System::PByte ATypes, int AStartIndex, int AEndIndex);
extern PACKAGE Status __stdcall (*GdipCreateMatrix)(/* out */ void * &AMatrix);
extern PACKAGE Status __stdcall (*GdipCreateMatrix2)(float M11, float M12, float M21, float M22, float DX, float DY, /* out */ void * &AMatrix);
extern PACKAGE Status __stdcall (*GdipCreateMatrix3)(PdxGpRectF ARect, PdxGpPointF ADstplg, /* out */ void * &AMatrix);
extern PACKAGE Status __stdcall (*GdipCreateMatrix3I)(PdxGpRect ARect, PdxGpPoint ADstplg, /* out */ void * &AMatrix);
extern PACKAGE Status __stdcall (*GdipCloneMatrix)(void * AMatrix, /* out */ void * &ACloneMatrix);
extern PACKAGE Status __stdcall (*GdipDeleteMatrix)(void * AMatrix);
extern PACKAGE Status __stdcall (*GdipSetMatrixElements)(void * AMatrix, float M11, float M12, float M21, float M22, float DX, float DY);
extern PACKAGE Status __stdcall (*GdipMultiplyMatrix)(void * AMatrix1, void * AMatrix2, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipTranslateMatrix)(void * AMatrix, float AOffsetX, float AOffsetY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipScaleMatrix)(void * AMatrix, float AScaleX, float AScaleY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipRotateMatrix)(void * AMatrix, float AAngle, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipShearMatrix)(void * AMatrix, float AShearX, float AShearY, TdxGpMatrixOrder AOrder);
extern PACKAGE Status __stdcall (*GdipInvertMatrix)(void * AMatrix);
extern PACKAGE Status __stdcall (*GdipTransformMatrixPoints)(void * AMatrix, PdxGpPointF APoint, int ACount);
extern PACKAGE Status __stdcall (*GdipTransformMatrixPointsI)(void * AMatrix, PdxGpPoint APoint, int ACount);
extern PACKAGE Status __stdcall (*GdipVectorTransformMatrixPoints)(void * AMatrix, PdxGpPointF APoint, int ACount);
extern PACKAGE Status __stdcall (*GdipVectorTransformMatrixPointsI)(void * AMatrix, PdxGpPoint APoint, int ACount);
extern PACKAGE Status __stdcall (*GdipGetMatrixElements)(void * AMatrix, Winapi::Windows::PSingle AMatrixOut);
extern PACKAGE Status __stdcall (*GdipIsMatrixInvertible)(void * AMatrix, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsMatrixIdentity)(void * AMatrix, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsMatrixEqual)(void * AMatrix1, void * AMatrix2, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipSetInterpolationMode)(void * AGraphics, int AInterpolationMode);
extern PACKAGE Status __stdcall (*GdipGetInterpolationMode)(void * AGraphics, /* out */ int &AInterpolationMode);
extern PACKAGE Status __stdcall (*GdipCreateCachedBitmap)(void * ABitmap, void * AGraphics, /* out */ void * &ACachedBitmap);
extern PACKAGE Status __stdcall (*GdipDeleteCachedBitmap)(void * ACachedBitmap);
extern PACKAGE Status __stdcall (*GdipDrawCachedBitmap)(void * AGraphics, void * ACachedBitmap, int X, int Y);
extern PACKAGE Status __stdcall (*GdipCreateBitmapFromGraphics)(int AWidth, int AHeight, void * ATarget, void * &ABitmap);
extern PACKAGE Status __stdcall (*GdipGetImageBounds)(void * AImage, PdxGpRectF ASrcRect, Unit_ &ASrcUnit);
extern PACKAGE Status __stdcall (*GdipGetImageGraphicsContext)(void * AImage, /* out */ void * &AGraphics);
extern PACKAGE Status __stdcall (*GdipGetImageWidth)(void * AImage, /* out */ int &AWidth);
extern PACKAGE Status __stdcall (*GdipGetImageHeight)(void * AImage, /* out */ int &AHeight);
extern PACKAGE Status __stdcall (*GdipGetImageHorizontalResolution)(void * AImage, float &AResolution);
extern PACKAGE Status __stdcall (*GdipGetImageVerticalResolution)(void * AImage, float &AResolution);
extern PACKAGE Status __stdcall (*GdipGetImageFlags)(void * AImage, unsigned &AFlags);
extern PACKAGE Status __stdcall (*GdipSetCompositingMode)(void * AGraphics, int ACompositingMode);
extern PACKAGE Status __stdcall (*GdipGetCompositingMode)(void * AGraphics, /* out */ int &ACompositingMode);
extern PACKAGE Status __stdcall (*GdipSetCompositingQuality)(void * AGraphics, int ACompositingQuality);
extern PACKAGE Status __stdcall (*GdipGetCompositingQuality)(void * AGraphics, /* out */ int &ACompositingQuality);
extern PACKAGE Status __stdcall (*GdipSetSmoothingMode)(void * AGraphics, int ASmoothingMode);
extern PACKAGE Status __stdcall (*GdipGetSmoothingMode)(void * AGraphics, /* out */ int &ASmoothingMode);
extern PACKAGE Status __stdcall (*GdipCloneBitmapArea)(float X, float Y, float AWidth, float AHeight, int AFormat, void * ASrcBitmap, /* out */ void * &ADstBitmap);
extern PACKAGE Status __stdcall (*GdipCloneBitmapAreaI)(int X, int Y, int AWidth, int AHeight, unsigned AFormat, void * ASrcBitmap, /* out */ void * &ADstBitmap);
extern PACKAGE Status __stdcall (*GdipSetRenderingOrigin)(void * AGraphics, int X, int Y);
extern PACKAGE Status __stdcall (*GdipGetRenderingOrigin)(void * AGraphics, int &X, int &Y);
extern PACKAGE Status __stdcall (*GdipSetPixelOffsetMode)(void * AGraphics, TdxGpPixelOffsetMode APixelOffsetMode);
extern PACKAGE Status __stdcall (*GdipGetPixelOffsetMode)(void * AGraphics, TdxGpPixelOffsetMode &APixelOffsetMode);
extern PACKAGE Status __stdcall (*GdipSetTextRenderingHint)(void * AGraphics, TdxGpTextRenderingHint AMode);
extern PACKAGE Status __stdcall (*GdipGetTextRenderingHint)(void * AGraphics, TdxGpTextRenderingHint &AMode);
extern PACKAGE Status __stdcall (*GdipSetTextContrast)(void * AGraphics, int AContrast);
extern PACKAGE Status __stdcall (*GdipGetTextContrast)(void * AGraphics, unsigned &AContrast);
extern PACKAGE Status __stdcall (*GdipCreateRegion)(/* out */ void * &ARegion);
extern PACKAGE Status __stdcall (*GdipCreateRegionPath)(void * APath, /* out */ void * &ARegion);
extern PACKAGE Status __stdcall (*GdipCreateRegionRect)(PdxGpRectF ARect, /* out */ void * &ARegion);
extern PACKAGE Status __stdcall (*GdipCreateRegionRectI)(PdxGpRect ARect, /* out */ void * &ARregion);
extern PACKAGE Status __stdcall (*GdipCreateRegionRgnData)(System::PByte ARegionData, int ASize, /* out */ void * &ARegion);
extern PACKAGE Status __stdcall (*GdipCreateRegionHrgn)(HRGN AHRgn, /* out */ void * &ARegion);
extern PACKAGE Status __stdcall (*GdipCloneRegion)(void * ARegion, /* out */ void * &ACloneRegion);
extern PACKAGE Status __stdcall (*GdipDeleteRegion)(void * ARegion);
extern PACKAGE Status __stdcall (*GdipSetInfinite)(void * ARegion);
extern PACKAGE Status __stdcall (*GdipSetEmpty)(void * ARegion);
extern PACKAGE Status __stdcall (*GdipCombineRegionRect)(void * ARegion, PdxGpRectF ARect, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipCombineRegionRectI)(void * ARegion, PdxGpRect ARect, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipCombineRegionPath)(void * ARegion, void * APath, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipCombineRegionRegion)(void * ARegion1, void * ARegion2, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipTranslateRegion)(void * ARegion, float DX, float DY);
extern PACKAGE Status __stdcall (*GdipTranslateRegionI)(void * ARegion, int DX, int DY);
extern PACKAGE Status __stdcall (*GdipTransformRegion)(void * ARegion, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipGetRegionBounds)(void * ARegion, void * AGraphics, PdxGpRectF ARect);
extern PACKAGE Status __stdcall (*GdipGetRegionBoundsI)(void * ARegion, void * AGraphics, PdxGpRect ARect);
extern PACKAGE Status __stdcall (*GdipGetRegionHRgn)(void * ARegion, void * AGraphics, /* out */ HRGN &AHRgn);
extern PACKAGE Status __stdcall (*GdipIsEmptyRegion)(void * ARegion, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsInfiniteRegion)(void * ARegion, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsEqualRegion)(void * ARegion1, void * ARegion2, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipGetRegionDataSize)(void * ARegion, /* out */ unsigned &ABufferSize);
extern PACKAGE Status __stdcall (*GdipGetRegionData)(void * ARegion, System::PByte ABuffer, unsigned ABufferSize, PUINT ASizeFilled);
extern PACKAGE Status __stdcall (*GdipIsVisibleRegionPoint)(void * ARegion, float X, float Y, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsVisibleRegionPointI)(void * ARegion, int X, int Y, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsVisibleRegionRect)(void * ARegion, float X, float Y, float AWidth, float AHeight, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsVisibleRegionRectI)(void * ARegion, int X, int Y, int AWidth, int AHeight, void * AGraphics, /* out */ BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipGetRegionScansCount)(void * ARegion, /* out */ unsigned &ACount, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipGetRegionScans)(void * ARegion, PdxGpRectF ARects, /* out */ int &ACount, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipGetRegionScansI)(void * ARegion, PdxGpRect ARects, /* out */ int &ACount, void * AMatrix);
extern PACKAGE Status __stdcall (*GdipGetClip)(void * AGraphics, void * ARegion);
extern PACKAGE Status __stdcall (*GdipResetClip)(void * AGraphics);
extern PACKAGE Status __stdcall (*GdipSetClipGraphics)(void * AGraphics, void * ASrcGraphics, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipSetClipRegion)(void * AGraphics, void * ARegion, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipSetClipRect)(void * AGraphics, float X, float Y, float AWidth, float AHeight, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipSetClipRectI)(void * AGraphics, int X, int Y, int AWidth, int AHeight, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipSetClipPath)(void * AGraphics, void * APath, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipSetClipHrgn)(void * AGraphics, HRGN AHRgn, TGpCombineMode ACombineMode);
extern PACKAGE Status __stdcall (*GdipTranslateClip)(void * AGraphics, float DX, float DY);
extern PACKAGE Status __stdcall (*GdipTranslateClipI)(void * AGraphics, int DX, int DY);
extern PACKAGE Status __stdcall (*GdipGetClipBounds)(void * AGraphics, PdxGpRectF ARect);
extern PACKAGE Status __stdcall (*GdipGetClipBoundsI)(void * AGraphics, PdxGpRect ARect);
extern PACKAGE Status __stdcall (*GdipIsClipEmpty)(void * AGraphics, PBOOL AResult);
extern PACKAGE Status __stdcall (*GdipGetVisibleClipBounds)(void * AGraphics, PdxGpRectF ARect);
extern PACKAGE Status __stdcall (*GdipGetVisibleClipBoundsI)(void * AGraphics, PdxGpRect ARect);
extern PACKAGE Status __stdcall (*GdipIsVisibleClipEmpty)(void * AGraphics, BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsVisiblePoint)(void * AGraphics, float X, float Y, BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsVisiblePointI)(void * AGraphics, int X, int Y, BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipSaveGraphics)(void * AGraphics, unsigned &AState);
extern PACKAGE Status __stdcall (*GdipRestoreGraphics)(void * AGraphics, unsigned AState);
extern PACKAGE Status __stdcall (*GdipBeginContainer)(void * AGraphics, PdxGpRectF ADstRect, PdxGpRectF ASrcrect, Unit_ AUnit, unsigned &AState);
extern PACKAGE Status __stdcall (*GdipBeginContainerI)(void * AGraphics, PdxGpRect ADstRect, PdxGpRect ASrcrect, Unit_ AUnit, unsigned &AState);
extern PACKAGE Status __stdcall (*GdipBeginContainer2)(void * AGraphics, unsigned &AState);
extern PACKAGE Status __stdcall (*GdipEndContainer)(void * AGraphics, unsigned AState);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileDestPoint)(void * AGraphics, void * AMetafile, PdxGpPointF ADestPoint, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileDestPointI)(void * AGraphics, void * AMetafile, PdxGpPoint ADestPoint, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileDestRect)(void * AGraphics, void * AMetafile, PdxGpRectF ADestRect, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileDestRectI)(void * AGraphics, void * AMetafile, PdxGpRect ADestRect, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileDestPoints)(void * AGraphics, void * AMetafile, PdxGpPointF ADestPoints, int ACount, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileDestPointsI)(void * AGraphics, void * AMetafile, PdxGpPoint ADestPoints, int ACount, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileSrcRectDestPoint)(void * AGraphics, void * AMetafile, PdxGpPointF ADestPoint, PdxGpRectF ASrcRect, Unit_ ASrcUnit, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileSrcRectDestPointI)(void * AGraphics, void * AMetafile, PdxGpPoint ADestPoint, PdxGpRect ASrcRect, Unit_ ASrcUnit, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileSrcRectDestRect)(void * AGraphics, void * AMetafile, PdxGpRectF ADestRect, PdxGpRectF ASrcRect, Unit_ ASrcUnit, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileSrcRectDestRectI)(void * AGraphics, void * AMetafile, PdxGpRect ADestRect, PdxGpRect ASrcRect, Unit_ ASrcUnit, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileSrcRectDestPoints)(void * AGraphics, void * AMetafile, PdxGpPointF ADestPoints, int ACount, PdxGpRectF ASrcRect, Unit_ ASrcUnit, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipEnumerateMetafileSrcRectDestPointsI)(void * AGraphics, void * AMetafile, PdxGpPoint ADestPoints, int ACount, PdxGpRect ASrcRect, Unit_ ASrcUnit, GpEnumerateMetafileProc ACallback, void * ACallbackData, void * AImageAttributes);
extern PACKAGE Status __stdcall (*GdipPlayMetafileRecord)(void * AMetafile, int ARecordType, unsigned AFlags, unsigned ADataSize, System::PByte AData);
extern PACKAGE Status __stdcall (*GdipGetMetafileHeaderFromWmf)(NativeUInt AHWmf, PGpWmfPlaceableFileHeader AWmfPlaceableFileHeader, void * AHeader);
extern PACKAGE Status __stdcall (*GdipGetMetafileHeaderFromEmf)(NativeUInt AHEmf, void * AHeader);
extern PACKAGE Status __stdcall (*GdipGetMetafileHeaderFromFile)(System::WideChar * AFileName, void * AHeader);
extern PACKAGE Status __stdcall (*GdipGetMetafileHeaderFromStream)(_di_IStream AStream, void * AHeader);
extern PACKAGE Status __stdcall (*GdipGetMetafileHeaderFromMetafile)(void * AMetafile, void * AHeader);
extern PACKAGE Status __stdcall (*GdipGetHemfFromMetafile)(void * AMetafile, NativeUInt &hEmf);
extern PACKAGE Status __stdcall (*GdipCreateStreamOnFile)(System::WideChar * AFileName, unsigned AAccess, /* out */ _di_IStream &AStream);
extern PACKAGE Status __stdcall (*GdipCreateMetafileFromWmf)(NativeUInt AHWmf, BOOL ADeleteWmf, PGpWmfPlaceableFileHeader AWmfPlaceableFileHeader, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipCreateMetafileFromEmf)(NativeUInt AHEmf, BOOL ADeleteEmf, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipCreateMetafileFromFile)(System::WideChar * AFileName, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipCreateMetafileFromWmfFile)(System::WideChar * AFileName, PGpWmfPlaceableFileHeader AWmfPlaceableFileHeader, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipCreateMetafileFromStream)(_di_IStream AStream, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipRecordMetafile)(HDC AReferenceDC, TdxGpEmfType AType, PdxGpRectF AFrameRect, TdxGpMetafileFrameUnit AFrameUnit, System::WideChar * ADescription, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipRecordMetafileI)(HDC AReferenceDC, TdxGpEmfType AType, PdxGpRect AFrameRect, TdxGpMetafileFrameUnit AFrameUnit, System::WideChar * ADescription, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipRecordMetafileFileName)(System::WideChar * AFileName, HDC AReferenceDC, TdxGpEmfType AType, PdxGpRectF AFrameRect, TdxGpMetafileFrameUnit AFrameUnit, System::WideChar * ADescription, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipRecordMetafileFileNameI)(System::WideChar * AFileName, HDC AReferenceDC, TdxGpEmfType AType, PdxGpRect AFrameRect, TdxGpMetafileFrameUnit AFrameUnit, System::WideChar * ADescription, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipRecordMetafileStream)(_di_IStream AStream, HDC AReferenceDC, TdxGpEmfType AType, PdxGpRectF AFrameRect, TdxGpMetafileFrameUnit AFrameUnit, System::WideChar * ADescription, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipRecordMetafileStreamI)(_di_IStream AStream, HDC AReferenceDC, TdxGpEmfType AType, PdxGpRect AFrameRect, TdxGpMetafileFrameUnit AFrameUnit, System::WideChar * ADescription, /* out */ void * &AMetafile);
extern PACKAGE Status __stdcall (*GdipSetMetafileDownLevelRasterizationLimit)(void * AMetafile, unsigned AMetafileRasterizationLimitDPI);
extern PACKAGE Status __stdcall (*GdipGetMetafileDownLevelRasterizationLimit)(void * AMetafile, unsigned &AMetafileRasterizationLimitDPI);
extern PACKAGE Status __stdcall (*GdipComment)(void * AGraphics, unsigned ASizeData, System::PByte AData);
extern PACKAGE Status __stdcall (*GdipIsVisibleRect)(void * AGraphics, float X, float Y, float AWidth, float AHeight, BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipIsVisibleRectI)(void * AGraphics, int X, int Y, int AWidth, int AHeight, BOOL &AResult);
extern PACKAGE Status __stdcall (*GdipCreateFontFamilyFromName)(System::WideChar * AName, void * AFontCollection, /* out */ void * &AFontFamily);
extern PACKAGE Status __stdcall (*GdipDeleteFontFamily)(void * AFontFamily);
extern PACKAGE Status __stdcall (*GdipCloneFontFamily)(void * AFontFamily, /* out */ void * &AClonedFontFamily);
extern PACKAGE Status __stdcall (*GdipGetGenericFontFamilySansSerif)(/* out */ void * &ANativeFamily);
extern PACKAGE Status __stdcall (*GdipGetGenericFontFamilySerif)(/* out */ void * &ANativeFamily);
extern PACKAGE Status __stdcall (*GdipGetGenericFontFamilyMonospace)(/* out */ void * &ANativeFamily);
extern PACKAGE Status __stdcall (*GdipGetFamilyName)(void * AFamily, System::WideChar * AName, System::Word ALanguage);
extern PACKAGE Status __stdcall (*GdipIsStyleAvailable)(void * AFamily, int AStyle, BOOL &AIsStyleAvailable);
extern PACKAGE Status __stdcall (*GdipFontCollectionEnumerable)(void * AFontCollection, void * AGraphics, int &ANumFound);
extern PACKAGE Status __stdcall (*GdipFontCollectionEnumerate)(void * AFontCollection, int ANumSought, void * *AgpFamilies, const int AgpFamilies_Size, int &ANnumFound, void * AGraphics);
extern PACKAGE Status __stdcall (*GdipGetEmHeight)(void * AFamily, int AStyle, /* out */ System::Word &AEmHeight);
extern PACKAGE Status __stdcall (*GdipGetCellAscent)(void * AFamily, int AStyle, System::Word &ACellAscent);
extern PACKAGE Status __stdcall (*GdipGetCellDescent)(void * AFamily, int AStyle, System::Word &ACellDescent);
extern PACKAGE Status __stdcall (*GdipGetLineSpacing)(void * AFamily, int AStyle, System::Word &ALineSpacing);
extern PACKAGE Status __stdcall (*GdipCreateFontFromDC)(HDC DC, /* out */ void * &AFont);
extern PACKAGE Status __stdcall (*GdipCreateFontFromLogfontA)(HDC DC, Winapi::Windows::PLogFontA ALogFont, /* out */ void * &AFont);
extern PACKAGE Status __stdcall (*GdipCreateFontFromLogfontW)(HDC DC, Winapi::Windows::PLogFontW ALogFont, /* out */ void * &AFont);
extern PACKAGE Status __stdcall (*GdipCreateFontFromLogfont)(HDC DC, Winapi::Windows::PLogFontW ALogFont, /* out */ void * &AFont);
extern PACKAGE Status __stdcall (*GdipCreateFont)(void * AFontFamily, float emSize, int AStyle, int AUnit, /* out */ void * &AFont);
extern PACKAGE Status __stdcall (*GdipCloneFont)(void * AFont, /* out */ void * &ACloneFont);
extern PACKAGE Status __stdcall (*GdipDeleteFont)(void * AFont);
extern PACKAGE Status __stdcall (*GdipGetFamily)(void * AFont, /* out */ void * &AFamily);
extern PACKAGE Status __stdcall (*GdipGetFontStyle)(void * AFont, int &AStyle);
extern PACKAGE Status __stdcall (*GdipGetFontSize)(void * AFont, float &ASize);
extern PACKAGE Status __stdcall (*GdipGetFontUnit)(void * AFont, Unit_ &AUnit);
extern PACKAGE Status __stdcall (*GdipGetFontHeight)(void * AFont, void * AGraphics, float &AHeight);
extern PACKAGE Status __stdcall (*GdipGetFontHeightGivenDPI)(void * AFont, float DPI, float &AHeight);
extern PACKAGE Status __stdcall (*GdipGetLogFontA)(void * AFont, void * AGraphics, tagLOGFONTA &ALogFontA);
extern PACKAGE Status __stdcall (*GdipGetLogFontW)(void * AFont, void * AGraphics, tagLOGFONTW &ALogfontW);
extern PACKAGE Status __stdcall (*GdipNewInstalledFontCollection)(/* out */ void * &AFontCollection);
extern PACKAGE Status __stdcall (*GdipNewPrivateFontCollection)(/* out */ void * &AFontCollection);
extern PACKAGE Status __stdcall (*GdipDeletePrivateFontCollection)(/* out */ void * &AFontCollection);
extern PACKAGE Status __stdcall (*GdipGetFontCollectionFamilyCount)(void * AFontCollection, int &ANumFound);
extern PACKAGE Status __stdcall (*GdipGetFontCollectionFamilyList)(void * AFontCollection, int ANumSought, void * AFamilies, int &ANumFound);
extern PACKAGE Status __stdcall (*GdipPrivateAddFontFile)(void * AFontCollection, System::WideChar * AFileName);
extern PACKAGE Status __stdcall (*GdipPrivateAddMemoryFont)(void * AFontCollection, void * AMemory, int ALength);
extern PACKAGE Status __stdcall (*GdipDrawString)(void * AGraphics, System::WideChar * AString, int ALength, void * AFont, PdxGpRectF ALayoutRect, void * AStringFormat, void * ABrush);
extern PACKAGE Status __stdcall (*GdipMeasureString)(void * AGraphics, System::WideChar * AString, int ALength, void * AFont, PdxGpRectF ALayoutRect, void * AStringFormat, PdxGpRectF ABoundingBox, int &ACodepointsFitted, int &LinesFilled);
extern PACKAGE Status __stdcall (*GdipMeasureCharacterRanges)(void * AGraphics, System::WideChar * AString, int ALength, void * AFont, PdxGpRectF ALayoutRect, void * AStringFormat, int ARegionCount, const void * ARegions);
extern PACKAGE Status __stdcall (*GdipDrawDriverString)(void * AGraphics, const System::WideChar * AText, int ALength, const void * AFont, const void * ABrush, const PdxGpPointF APositions, int AFlags, const void * AMatrix);
extern PACKAGE Status __stdcall (*GdipMeasureDriverString)(void * AGgraphics, PUINT16 AText, int ALength, void * AFont, PdxGpPointF APositions, int AFlags, void * AMatrix, PdxGpRectF ABoundingBox);
extern PACKAGE Status __stdcall (*GdipCreateStringFormat)(int AFormatAttributes, System::Word ALanguage, /* out */ void * &AFormat);
extern PACKAGE Status __stdcall (*GdipStringFormatGetGenericDefault)(/* out */ void * &AFormat);
extern PACKAGE Status __stdcall (*GdipStringFormatGetGenericTypographic)(/* out */ void * &AFormat);
extern PACKAGE Status __stdcall (*GdipDeleteStringFormat)(void * AFormat);
extern PACKAGE Status __stdcall (*GdipCloneStringFormat)(void * AFormat, /* out */ void * &ANewFormat);
extern PACKAGE Status __stdcall (*GdipSetStringFormatFlags)(void * AFormat, int AFlags);
extern PACKAGE Status __stdcall (*GdipGetStringFormatFlags)(void * AFormat, /* out */ int &AFlags);
extern PACKAGE Status __stdcall (*GdipSetStringFormatAlign)(void * AFormat, TdxGpStringAlignment AAlign);
extern PACKAGE Status __stdcall (*GdipGetStringFormatAlign)(void * AFormat, /* out */ TdxGpStringAlignment &AAlign);
extern PACKAGE Status __stdcall (*GdipSetStringFormatLineAlign)(void * AFormat, TdxGpStringAlignment AAlign);
extern PACKAGE Status __stdcall (*GdipGetStringFormatLineAlign)(void * AFormat, /* out */ TdxGpStringAlignment &AAlign);
extern PACKAGE Status __stdcall (*GdipSetStringFormatTrimming)(void * AFormat, TdxGpStringTrimming ATrimming);
extern PACKAGE Status __stdcall (*GdipGetStringFormatTrimming)(void * AFormat, /* out */ TdxGpStringTrimming &ATrimming);
extern PACKAGE Status __stdcall (*GdipSetStringFormatHotkeyPrefix)(void * AFormat, int AHotkeyPrefix);
extern PACKAGE Status __stdcall (*GdipGetStringFormatHotkeyPrefix)(void * AFormat, /* out */ int &AHotkeyPrefix);
extern PACKAGE Status __stdcall (*GdipSetStringFormatTabStops)(void * AFormat, float AFirstTabOffset, int ACount, Winapi::Windows::PSingle ATabStops);
extern PACKAGE Status __stdcall (*GdipGetStringFormatTabStops)(void * AFormat, int ACount, Winapi::Windows::PSingle AFirstTabOffset, Winapi::Windows::PSingle ATabStops);
extern PACKAGE Status __stdcall (*GdipGetStringFormatTabStopCount)(void * AFormat, /* out */ int &ACount);
extern PACKAGE Status __stdcall (*GdipSetStringFormatDigitSubstitution)(void * AFormat, System::Word ALanguage, TdxGpStringDigitSubstitute ASubstitute);
extern PACKAGE Status __stdcall (*GdipGetStringFormatDigitSubstitution)(void * AFormat, PUINT ALanguage, PdxGpStringDigitSubstitute ASubstitute);
extern PACKAGE Status __stdcall (*GdipGetStringFormatMeasurableCharacterRangeCount)(void * AFormat, /* out */ int &ACount);
extern PACKAGE Status __stdcall (*GdipSetStringFormatMeasurableCharacterRanges)(void * AFormat, int ARangeCount, PdxGpCharacterRange ARanges);
extern PACKAGE unsigned __stdcall (*GdipEmfToWmfBits)(NativeUInt AHemf, unsigned cbData16, System::PByte pData16, int iMapMode, int eFlags);
extern PACKAGE TdxGpColorMatrix dxGpDefaultColorMatrix;
extern PACKAGE System::ResourceString _scxGdipInvalidOperation;
#define Dxgdiplusapi_scxGdipInvalidOperation System::LoadResourceString(&Dxgdiplusapi::_scxGdipInvalidOperation)
extern PACKAGE void * __fastcall dxGpCreateFont(Vcl::Graphics::TFont* AFont);
extern PACKAGE void * __fastcall dxGpCreateBitmap(int AWidth, int AHeight)/* overload */;
extern PACKAGE void * __fastcall dxGpCreateBitmap(const System::Types::TSize ASize)/* overload */;
extern PACKAGE void * __fastcall dxGpCreateBitmap(const System::Types::TRect &R)/* overload */;
extern PACKAGE unsigned __fastcall dxGpColorToARGB(System::Uitypes::TColor AColor, System::Byte AAlpha = (System::Byte)(0xff));
extern PACKAGE unsigned __fastcall dxGpMakeARGBColor(System::Byte A, System::Byte R, System::Byte G, System::Byte B);
extern PACKAGE Status __fastcall GetCodecID(const System::UnicodeString CodecName, /* out */ GUID &Clsid);
extern PACKAGE TdxGpRect __fastcall MakeRect(int X, int Y, int AWidth, int AHeight)/* overload */;
extern PACKAGE TdxGpRect __fastcall MakeRect(const TdxGpPoint ALocation, const TdxGpSize ASize)/* overload */;
extern PACKAGE TdxGpRect __fastcall MakeRect(const System::Types::TRect &ARect)/* overload */;
extern PACKAGE TdxGpPoint __fastcall MakePoint(int X, int Y)/* overload */;
extern PACKAGE TdxGpPointF __fastcall MakePoint(float X, float Y)/* overload */;
extern PACKAGE bool __fastcall CheckGdiPlus(bool AHaltOnError = false);
extern PACKAGE void __fastcall CheckImageCodecs(void);
extern PACKAGE void __fastcall CheckPngCodec(void);
extern PACKAGE TdxGpSizeF __fastcall MakeSize(float AWidth, float AHeight)/* overload */;
extern PACKAGE TdxGpSize __fastcall MakeSize(int AWidth, int AHeight)/* overload */;
extern PACKAGE void __fastcall GdipCheck(Status AStatus)/* overload */;
extern PACKAGE TdxGpRectF __fastcall MakeRect(float X, float Y, float AWidth, float AHeight)/* overload */;
extern PACKAGE TdxGpRectF __fastcall MakeRect(const TdxGpPointF ALocationF, const TdxGpSizeF ASizeF)/* overload */;
extern PACKAGE TdxGpRectF __fastcall dxGpMakeRectF(const System::Types::TRect &ARect);
extern PACKAGE void __fastcall GdipCheck(bool AStatus)/* overload */;
}	/* namespace Dxgdiplusapi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXGDIPLUSAPI)
using namespace Dxgdiplusapi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxgdiplusapiHPP
