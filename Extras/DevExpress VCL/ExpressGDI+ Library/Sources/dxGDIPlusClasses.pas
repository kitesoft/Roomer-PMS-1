{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       GDI+ Library                                                }
{                                                                   }
{       Copyright (c) 2002-2014 Developer Express Inc.              }
{       ALL RIGHTS RESERVED                                         }
{                                                                   }
{   The entire contents of this file is protected by U.S. and       }
{   International Copyright Laws. Unauthorized reproduction,        }
{   reverse-engineering, and distribution of all or any portion of  }
{   the code contained in this file is strictly prohibited and may  }
{   result in severe civil and criminal penalties and will be       }
{   prosecuted to the maximum extent possible under the law.        }
{                                                                   }
{   RESTRICTIONS                                                    }
{                                                                   }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES           }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE    }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS   }
{   LICENSED TO DISTRIBUTE THE GDIPLUS LIBRARY AND ALL ACCOMPANYING }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.             }
{                                                                   }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED      }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE        }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE       }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT  }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                      }
{                                                                   }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON       }
{   ADDITIONAL RESTRICTIONS.                                        }
{                                                                   }
{*******************************************************************}

unit dxGDIPlusClasses;

{$I cxVer.inc}
{$DEFINE DXREGISTERPNGIMAGE}

interface

uses
  Windows, Classes, SysUtils, Graphics, ActiveX, Types,
  dxCore, cxGeometry, dxGDIPlusAPI;

type
  TdxPNGImage = class;
  TdxGPImage = class;

  TdxImageDataFormat = (dxImageUnknown, dxImageBitmap, dxImageJpeg, dxImagePng,
    dxImageTiff, dxImageGif);

  TdxGPInterpolationMode = (
    imDefault = InterpolationModeDefault,
    imLowQuality = InterpolationModeLowQuality,
    imHighQuality = InterpolationModeHighQuality,
    imBilinear = InterpolationModeBilinear,
    imBicubic = InterpolationModeBicubic,
    imNearestNeighbor = InterpolationModeNearestNeighbor,
    imHighQualityBilinear = InterpolationModeHighQualityBilinear,
    imHighQualityBicubic = InterpolationModeHighQualityBicubic);

  TdxGPSmoothingMode = (smDefault, smHighSpeed, smHighQuality, smNone, smAntiAlias);

  { TdxGPBrush }

  TdxGPBrush = class(TdxGPBase)
  private
    FNativeBrush: GpBrush;
    FLastResult: TdxGPStatus;
  protected
    constructor CreateNative (nativeBrush: GpBrush; AStatus: Status);
    procedure SetNativeBrush(ANativeBrush: GpBrush);
    function SetStatus(AStatus: TdxGPStatus): TdxGPStatus;
  public
    constructor Create;
    destructor Destroy; override;
    function Clone: TdxGPBrush; virtual;
    function GetType: BrushType;
    function GetLastStatus: Status;
  end;

  { TdxGPSolidBrush }

  TdxGPSolidBrush = class(TdxGPBrush)
  private
    function GetColor: DWORD;
    procedure SetColor(const Value: DWORD);
  public
    constructor Create; overload;
    constructor Create(color: TColor); overload;
    property Color: DWORD read GetColor write SetColor;
  end;

  { TdxGPTextureBrush }

  TdxGPTextureBrush = class(TdxGPBrush)
  end;

  { TdxGPLinearGradientBrush }

  TdxGPLinearGradientBrush = class(TdxGPBrush)
  private
    procedure SetWrapMode(const Value: TdxGPWrapMode);
    function GetWrapMode: TdxGPWrapMode;
  public
    constructor Create; overload;
    constructor Create(rect: TdxGPRect; color1, color2: DWORD; mode: TdxGPLinearGradientMode); overload;
    function SetLinearColors(color1, color2: DWORD): TdxGPStatus;
    function GetLinearColors(out color1, color2: DWORD): TdxGPStatus;
    function GetRectangle: TdxGPRect; overload;
    property WrapMode: TdxGPWrapMode read GetWrapMode write SetWrapMode;
  end;

  { TdxGPHatchBrush }

  TdxGPHatchBrush = class(TdxGPBrush)
  public
    constructor Create; overload;
    constructor Create(hatchStyle: TdxGPHatchStyle; foreColor: DWORD; backColor: DWORD); overload;
    function GetHatchStyle: TdxGPHatchStyle;
    function GetForegroundColor: DWORD;
    function GetBackgroundColor: DWORD;
  end;

  { TdxGPPen }

  TdxGPPen = class(TdxGPBase)
  private
    FNativePen: GpPen;
    FLastResult: TdxGPStatus;

    function GetAlignment: TdxGPPenAlignment;
    function GetColor: DWORD;
    function GetBrush: TdxGPBrush;
    function GetWidth: Single;
    procedure SetAlignment(const Value: TdxGPPenAlignment);
    procedure SetColor(const Value: DWORD);
    procedure SetBrush(const Value: TdxGPBrush);
    procedure SetWidth(const Value: Single);
  protected
    procedure SetNativePen(ANativePen: GpPen);
    function SetStatus(AStatus: TdxGPStatus): TdxGPStatus;
  public
    constructor Create(color: DWORD; width: Single = 1.0); overload;
    constructor Create(brush: TdxGPBrush; width: Single = 1.0); overload;
    destructor Destroy; override;
    function GetLastStatus: TdxGPStatus;
    function GetPenType: TdxGPPenType;
    //
    property ALignment: TdxGPPenAlignment read GetAlignment write SetAlignment;
    property Brush: TdxGPBrush read GetBrush write SetBrush;
    property Color: DWORD read GetColor write SetColor;
    property Width: Single read GetWidth write SetWidth;
  end;

  { TdxGPCanvas }

  TdxGPCanvas = class(TdxGPBase)
  private
    FHandle: GpGraphics;
    function GetInterpolationMode: TdxGPInterpolationMode;
    function GetSmoothingMode: TdxGPSmoothingMode;
    procedure SetInterpolationMode(AValue: TdxGPInterpolationMode);
    procedure SetSmoothingMode(AValue: TdxGPSmoothingMode);
  protected
    procedure CheckDestRect(var R: TRect);
    procedure CreateHandle(DC: HDC);
    procedure FreeHandle;
  public
    constructor Create(AHandle: GpGraphics); overload;
    constructor Create(DC: THandle); overload;
    destructor Destroy; override;
    //
    function GetHDC: HDC;
    procedure ReleaseHDC(DC: HDC);
    procedure Clear(AColor: TColor);
    //
    procedure Draw(AGraphic: TdxGPImage; const ADestRect, ASourceRect: TRect; AAlpha: Byte = 255); overload;
    procedure Draw(AGraphic: TdxGPImage; const R: TRect; AAlpha: Byte = 255); overload;
    procedure DrawBitmap(ABitmap: TBitmap; const R: TRect; AAlpha: Byte = 255); // deprecated
    procedure DrawTile(AGraphic: TdxGPImage; const R: TRect; AAlpha: Byte = 255); overload;
    //
    procedure Arc(R: TRect; AStartAngle, ASweepAngle: Single; APenColor: TColor;
      APenWidth: Single = 1; APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255);
    procedure Ellipse(R: TRect; APenColor, ABrushColor: TColor; APenWidth: Single = 1;
      APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255);
    procedure Line(X1, Y1, X2, Y2: Integer; APenColor: TColor; APenWidth: Single = 1;
      APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255);
    procedure Pie(R: TRect; AStartAngle, ASweepAngle: Single; APenColor: TColor;
      ABrushColor: TColor; APenWidth: Single = 1; APenStyle: TPenStyle = psSolid;
      APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255);
    procedure Polygon(const APoints: array of TPoint; APenColor: TColor;
      ABrushColor: TColor; APenWidth: Single = 1; APenStyle: TPenStyle = psSolid;
      APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255); overload;
    procedure Polygon(const APoints: array of TdxPointF; APenColor: TColor;
      ABrushColor: TColor; APenWidth: Single = 1; APenStyle: TPenStyle = psSolid;
      APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255); overload;
    procedure Polyline(const APoints: array of TPoint; APenColor: TColor;
      APenWidth: Single = 1; APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255);
    procedure Rectangle(R: TRect; APenColor, ABrushColor: TColor; APenWidth: Single = 1;
      APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255);
    procedure RoundRect(const R: TRect; APenColor, ABrushColor: TColor; ARadiusX, ARadiusY: Integer;
      APenWidth: Integer = 1; APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255);
    //
    property Handle: GpGraphics read FHandle;
    property InterpolationMode: TdxGPInterpolationMode read GetInterpolationMode write SetInterpolationMode;
    property SmoothingMode: TdxGPSmoothingMode read GetSmoothingMode write SetSmoothingMode;
  end;

  TdxGPGraphics = class(TdxGPCanvas);

  { TdxGPCustomPaintCanvas }

  TdxGPPaintCanvasState = record
    Handle: GpGraphics;
    Buffer: TBitmap;
    DrawRect: TRect;
    DC: HDC;
  end;
  TdxGPPaintCanvasStates = array of TdxGPPaintCanvasState;

  TdxGPCustomPaintCanvas = class(TdxGPGraphics)
  private
    FBuffer: TBitmap;
    FDrawRect: TRect;
    FDrawDC: HDC;

    procedure CreateBuffer(DC: HDC; const R: TRect);
    procedure FreeBuffer;
    procedure OutputBuffer;
  protected
    procedure SaveState; virtual;
    procedure RestoreState; virtual;
  public
    procedure BeginPaint(DC: HDC; const R: TRect); overload;
    procedure BeginPaint(AHandle: GpGraphics); overload;
    procedure EndPaint;
  end;

  { TdxGPPaintCanvas }

  TdxGPPaintCanvas = class(TdxGPCustomPaintCanvas)
  private
    FCounter: Integer;
    FSavedStates: TdxGPPaintCanvasStates;

    procedure SetCapacity(AValue: Integer);
  protected
    procedure SaveState; override;
    procedure RestoreState; override;
  public
    destructor Destroy; override;
  end;

  { TdxGPMemoryStream }

  TdxGPMemoryStream = class(TMemoryStream)
  protected
    function Realloc(var ANewCapacity: Integer): Pointer; override;
  end;

  { TdxGPStreamAdapter }

  TdxGPStreamAdapter = class(TStreamAdapter)
  public
    function Stat(out StatStg: TStatStg; StatFlag: Integer): HRESULT; override; stdcall;
  end;

  { TdxGPImageData }

  TdxGPImageData = class(TObject)
  private
    function GetIsEmpty: Boolean;
  protected
    FBits: TRGBColors;
    FBitsBounds: TSize;
    FData: TdxGPMemoryStream;
    FNewSize: TSize;
    procedure Assign(AData: TdxGPImageData);
    procedure FreeImageData;
    procedure LoadFromBits(const ABits: TRGBColors; const ASize: TSize; AHasAlphaChannel: Boolean);
    procedure LoadFromStream(AStream: TStream);
  public
    destructor Destroy; override;
    //
    property Empty: Boolean read GetIsEmpty;
  end;

  { TdxGPImage }

  TdxGPImage = class(TGraphic)
  private
    FHandle: GpImage;
    FImageData: TdxGPImageData;
    FImageDataFormat: TdxImageDataFormat;
    FIsAlphaUsed: Boolean;
    FIsAlphaUsedAssigned: Boolean;
    function CheckAlphaUsed: Boolean;
    function GetClientRect: TRect;
    function GetHandle: GpImage;
    function GetHandleAllocated: Boolean;
    function GetImageDataFormat: TdxImageDataFormat;
    function GetIsAlphaUsed: Boolean;
    procedure RecognizeImageRawDataFormat;
    procedure SetImageDataFormat(AValue: TdxImageDataFormat);
  protected
    function CheckHasAlphaChannel(const ABits: TRGBColors): Boolean;
    procedure CreateHandleFromBitmap(ABitmap: TBitmap);
    procedure CreateHandleFromBits(AWidth, AHeight: Integer; const ABits: TRGBColors; AHasAlphaChannel: Boolean);
    procedure CreateHandleFromHBITMAP(ABitmap: HBITMAP; APalette: HPALETTE);
    procedure CreateHandleFromImageData;
    procedure CreateHandleFromStream(AStream: TStream);

    procedure AssignFromGpImage(AGpImage: TdxGPImage); virtual;
    procedure AssignFromGraphic(AGraphic: TGraphic); virtual;
    procedure AssignTo(ADest: TPersistent); override;
    procedure Draw(ACanvas: TCanvas; const ARect: TRect); override;
    procedure FreeHandle;
    function GetEmpty: Boolean; override;
    function GetHeight: Integer; override;
    function GetLoaded: Boolean; virtual;
    function GetSize: TSize;
    function GetTransparent: Boolean; override;
    function GetWidth: Integer; override;
    procedure SetHandle(AValue: GPImage);
    procedure SetHeight(Value: Integer); override;
    procedure SetWidth(Value: Integer); override;
    procedure Changed(Sender: TObject); override;
    //
    property Loaded: Boolean read GetLoaded;  
    property ImageData: TdxGPImageData read FImageData;
  public
    constructor Create; override;
    constructor CreateSize(const ASize: TSize; AColor: ARGB = 255); overload; virtual;
    constructor CreateSize(const R: TRect; AColor: ARGB = 255); overload;
    constructor CreateSize(AWidth, AHeight: Integer; AColor: ARGB = 255); overload;
    constructor CreateFromBitmap(ABitmap: TBitmap); virtual;
    constructor CreateFromHBitmap(ABitmap: HBitmap); virtual;
    constructor CreateFromBits(AWidth, AHeight: Integer;
      const ABits: TRGBColors; AHasAlphaChannel: Boolean); virtual;
    constructor CreateFromStream(AStream: TStream); virtual;
    destructor Destroy; override;

    procedure Assign(ASource: TPersistent); override;
    procedure LoadFromBits(AWidth, AHeight: Integer; const ABits: TRGBColors; AHasAlphaChannel: Boolean);
    procedure LoadFromClipboardFormat(AFormat: Word; AData: THandle; APalette: HPALETTE); override;
    procedure LoadFromFieldValue(const AValue: Variant);
    procedure LoadFromResource(AInstance: THandle; const AResName: string; AResType: PChar);
    procedure LoadFromStream(AStream: TStream); override;
    procedure SaveToClipboardFormat(var AFormat: Word; var AData: THandle; var APalette: HPALETTE); override;
    procedure SaveToStream(AStream: TStream); override;
    procedure SaveToStreamByCodec(AStream: TStream; AImageFormat: TdxImageDataFormat);

    function Clone: TdxGPImage; virtual;
    procedure ChangeColor(AColor: TColor); virtual;
    function Compare(AImage: TdxGPImage): Boolean; virtual;
    procedure ConvertToBitmap;
    procedure Clear; virtual;
    function GetAsBitmap: TBitmap; virtual;
    function GetBitmapBits: TRGBColors;
    function MakeComposition(AOverlayImage: TdxGPImage; AOverlayAlpha: Byte): TdxGPImage; overload;
    function MakeComposition(AOverlayImage: TdxGPImage; AOverlayAlpha, ASourceAlpha: Byte): TdxGPImage; overload;
    procedure HandleNeeded;
    procedure Resize(const AWidth, AHeight: Integer); overload; virtual;
    procedure Resize(const ASize: TSize); overload;
    procedure SetBitmap(ABitmap: TBitmap); virtual;
    procedure Scale(const M, D: Integer);
    procedure StretchDraw(DC: HDC; const ADest, ASource: TRect; AAlpha: Byte = 255); overload; // deprecated
    procedure StretchDraw(DC: HDC; const ADest: TRect; AAlpha: Byte = 255); overload; // deprecated

    property ClientRect: TRect read GetClientRect;
    property Handle: GpImage read GetHandle write SetHandle;
    property HandleAllocated: Boolean read GetHandleAllocated;
    property ImageDataFormat: TdxImageDataFormat read GetImageDataFormat write SetImageDataFormat;
    property IsAlphaUsed: Boolean read GetIsAlphaUsed;
    property Size: TSize read GetSize;
  end;

  TdxGPImageClass = class of TdxGPImage;

  { TdxSmartImage }

  TdxSmartImage = class(TdxGPImage)
  protected
    procedure ReadData(Stream: TStream); override;
    procedure WriteData(Stream: TStream); override;
  end;

  { TdxPNGImage }

  TdxPNGImage = class(TdxSmartImage)
  public
    procedure SaveToStream(AStream: TStream); override;
  end;

  { TdxJPEGImage }

  TdxJPEGImage = class(TdxSmartImage)
  public
    procedure SaveToStream(AStream: TStream); override;
  end;

  { TdxGIFImage }

  TdxGIFImage = class(TdxSmartImage)
  public
    procedure SaveToStream(AStream: TStream); override;
  end;

  { TdxTIFFImage }

  TdxTIFFImage = class(TdxSmartImage)
  public
    procedure SaveToStream(AStream: TStream); override;
  end;

  { TdxBMPImage }

  TdxBMPImage = class(TdxSmartImage)
  public
    procedure SaveToStream(AStream: TStream); override;
  end;

function dxGpIsDoubleBufferedNeeded(DC: HDC): Boolean;
function dxGpIsRectVisible(AGraphics: GpGraphics; const R: TRect): LongBool;

procedure dxGpDrawImage(AGraphics: GpGraphics; const ADestRect: TRect;
  const ASourceRect: TRect; AImage: GpImage; AAlpha: Byte = 255); overload;
procedure dxGPDrawText(AGraphics: TdxGPGraphics; const AText: string;
  const ARect: TRect; AFont: TFont; ATextColor: TColor;
  AHorzAlignment: TAlignment = taLeftJustify; AVertAlignment: TVerticalAlignment = taVerticalCenter;
  AWordWrap: Boolean = False; ARendering: TdxGpTextRenderingHint = TextRenderingHintSystemDefault;
  AAlpha: Integer = 255);
procedure dxGpFillRect(DC: HDC; const R: TRect; AColor: TColor; AColorAlpha: Byte = 255); overload;
procedure dxGpFillRect(AGraphics: GpGraphics; const R: TRect; AColor: ARGB); overload;
procedure dxGpFillRectByGradient(AGraphics: GpGraphics; const R: TRect;
  AColor1, AColor2: ARGB; AMode: TdxGPLinearGradientMode); overload;
procedure dxGpFillRectByGradient(DC: HDC; const R: TRect;
  AColor1, AColor2: TColor; AMode: TdxGPLinearGradientMode;
  AColor1Alpha: Byte = 255; AColor2Alpha: Byte = 255); overload;
procedure dxGpTilePart(DC: HDC; const ADestRect, ASourceRect: TRect; AImage: GpBitmap);
procedure dxGpTilePartEx(AGraphics: GpGraphics;
  const ADestRect, ASourceRect: TRect; AImage: GpBitmap; AAlpha: Byte = 255);
procedure dxGpResetRect(AGraphics: GpGraphics; const R: TRect);
procedure dxGpRoundRect(DC: HDC; const R: TRect;
  APenColor: TColor; ABrushColor: TColor; ARadius: Integer; APenWidth: Integer = 1;
  APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255);

function dxGpBeginPaint(AHandle: GpGraphics): TdxGPGraphics; overload;
function dxGpBeginPaint(DC: HDC; const R: TRect): TdxGPGraphics; overload;
procedure dxGpEndPaint(var AGraphics: TdxGPGraphics);

function dxGetImageDataFormat(const AFormatId: TGUID): TdxImageDataFormat;
function dxGetImageEncoder(AImageDataFormat: TdxImageDataFormat): TGUID; overload;

function dxGPPaintCanvas: TdxGPPaintCanvas;

implementation

uses
  Math, RTLConsts;

type
  TdxWindowFromDCFunc = function (hDC: HDC): HWND; stdcall;

  TMemoryStreamAccess = class(TMemoryStream);

  { TdxGPAlphaBlendAttributes }

  TdxGPAlphaBlendAttributes = class(TdxGPBase)
  private
    FAlpha: Byte;
    FColorMatrix: TdxGPColorMatrix;
    FHandle: GpImageAttributes;
    procedure SetAlpha(AValue: Byte);
  public
    constructor Create; virtual;
    destructor Destroy; override;
    //
    property Alpha: Byte read FAlpha write SetAlpha;
    property Handle: GpImageAttributes read FHandle;
  end;

  { TdxGPImageDataHelper }

  TdxGPImageDataHelper = class
  public
    class function IsBitmapStream(AStream: TStream): Boolean;
  end;

var
  FWindowFromDC: TdxWindowFromDCFunc;
  GPAlphaBlendAttributes: TdxGPAlphaBlendAttributes;
  GPPaintCanvas: TdxGPPaintCanvas;

function dxWindowFromDC(DC: HDC): HWND;
begin
  if Assigned(FWindowFromDC) then
    Result := FWindowFromDC(DC)
  else
    Result := 0;
end;

function dxGpGetAlphaBlendAttributes(const AAlpha: Byte): TdxGPAlphaBlendAttributes;
begin
  if GPAlphaBlendAttributes = nil then
    GPAlphaBlendAttributes := TdxGPAlphaBlendAttributes.Create;
  GPAlphaBlendAttributes.Alpha := AAlpha;
  Result := GPAlphaBlendAttributes;
end;

function dxCloneStream(AStream: TdxGPMemoryStream): TdxGPMemoryStream;
var
  APrevStreamPosition: Int64;
begin
  if AStream <> nil then
  begin
    APrevStreamPosition := AStream.Position;
    try
      AStream.Position := 0;
      Result := TdxGPMemoryStream.Create;
      Result.Size := AStream.Size;
      Result.CopyFrom(AStream, AStream.Size);
      Result.Position := 0;
    finally
      AStream.Position := APrevStreamPosition;
    end;
  end
  else
    Result := nil;
end;

function dxGpBeginPaint(AHandle: GpGraphics): TdxGPGraphics;
begin
  Result := TdxGPCustomPaintCanvas.Create(nil);
  TdxGPCustomPaintCanvas(Result).BeginPaint(AHandle);
end;

function dxGpBeginPaint(DC: HDC; const R: TRect): TdxGPGraphics;
begin
  Result := TdxGPCustomPaintCanvas.Create(nil);
  TdxGPCustomPaintCanvas(Result).BeginPaint(DC, R);
end;

procedure dxGpEndPaint(var AGraphics: TdxGPGraphics);
begin
  (AGraphics as TdxGPCustomPaintCanvas).EndPaint;
  FreeAndNil(AGraphics);
end;

function dxGetImageDataFormat(const AFormatId: TGUID): TdxImageDataFormat;
begin
  if IsEqualGUID(AFormatId, ImageFormatBMP) or IsEqualGUID(AFormatId, ImageFormatMemoryBMP) then
    Result := dxImageBitmap
  else
  if IsEqualGUID(AFormatId, ImageFormatJPEG) then
    Result := dxImageJpeg
  else
  if IsEqualGUID(AFormatId, ImageFormatPNG) then
    Result := dxImagePng
  else
  if IsEqualGUID(AFormatId, ImageFormatTIFF) then
    Result := dxImageTiff
  else
  if IsEqualGUID(AFormatId, ImageFormatGIF) then
    Result := dxImageGif
  else
  if IsEqualGUID(AFormatId, ImageFormatEMF) or IsEqualGUID(AFormatId, ImageFormatWMF) then
    Result := dxImageBitmap
  else
  if IsEqualGUID(AFormatId, ImageFormatIcon) then
    Result := dxImageBitmap
  else
    Result := dxImageUnknown;
end;

function dxGetImageEncoder(AImageDataFormat: TdxImageDataFormat): TGUID;
begin
  case AImageDataFormat of
    dxImageBitmap:
      Result := BMPCodec;
    dxImageJpeg:
      Result := JPEGCodec;
    dxImagePng:
      Result := PNGCodec;
    dxImageTiff:
      Result := TIFFCodec;
    dxImageGif:
      Result := GIFCodec;
  else
    raise EdxException.Create('dxGetImageEncoder fails');
  end;
end;

procedure dxGpDrawImage(AGraphics: GpGraphics; const ADestRect: TRect;
  const ASourceRect: TRect; AImage: GpImage; AAlpha: Byte = 255);
var
  AAttributes: GpImageAttributes;
  DstH, DstW, SrcH, SrcW: Integer;
begin
  SrcW := ASourceRect.Right - ASourceRect.Left;
  SrcH := ASourceRect.Bottom - ASourceRect.Top;
  DstW := ADestRect.Right - ADestRect.Left;
  DstH := ADestRect.Bottom - ADestRect.Top;
  if (SrcW < 1) or (SrcH < 1) or (DstW < 1) or (DstH < 1) then Exit;
  if (DstW > SrcW) and (SrcW > 1) then Dec(SrcW);
  if (DstH > SrcH) and (SrcH > 1) then Dec(SrcH);
  if dxGpIsRectVisible(AGraphics, ADestRect) then
  begin
    if AAlpha < 255 then
      AAttributes := dxGpGetAlphaBlendAttributes(AAlpha).Handle
    else
      AAttributes := nil;

    GdipCheck(GdipDrawImageRectRectI(AGraphics, AImage, ADestRect.Left,
      ADestRect.Top, DstW, DstH, ASourceRect.Left, ASourceRect.Top, SrcW, SrcH,
      UnitPixel, AAttributes, nil, nil));
  end;
end;

procedure dxGPDrawText(AGraphics: TdxGPGraphics; const AText: string;
  const ARect: TRect; AFont: TFont; ATextColor: TColor;
  AHorzAlignment: TAlignment; AVertAlignment: TVerticalAlignment; AWordWrap: Boolean;
  ARendering: TdxGpTextRenderingHint; AAlpha: Integer);
const
  WordWrapMap: array[Boolean] of TdxGpStringFormatFlags = (StringFormatFlagsNoWrap, StringFormatFlagsNone);
  HorzAlignmentMap: array[TAlignment] of TdxGpStringAlignment = (StringAlignmentNear, StringAlignmentFar, StringAlignmentCenter);
  VertAlignmentMap: array[TVerticalAlignment] of TdxGpStringAlignment = (StringAlignmentNear, StringAlignmentFar, StringAlignmentCenter);
var
  AGpBrush: GpBrush;
  AGpFont: GpFont;
  ARectF: TdxGpRectF;
  AStringFormat: GpStringFormat;
begin
  if cxRectIsEmpty(ARect) or (AText = '') then Exit;

  GdipCheck(GdipCreateStringFormat(Integer(WordWrapMap[AWordWrap]), LANG_NEUTRAL, AStringFormat));
  GdipCheck(GdipCreateSolidFill(dxGpColorToARGB(ATextColor, AAlpha), AGpBrush));
  AGpFont := dxGpCreateFont(AFont);
  try
    GdipCheck(GdipSetStringFormatAlign(AStringFormat, HorzAlignmentMap[AHorzAlignment]));
    GdipCheck(GdipSetStringFormatLineAlign(AStringFormat, VertAlignmentMap[AVertAlignment]));
    GdipCheck(GdipSetTextRenderingHint(AGraphics.Handle, ARendering));

    ARectF := dxGpMakeRectF(ARect);
    GdipCheck(GdipDrawString(AGraphics.Handle, PWideChar(WideString(AText)), -1, AGpFont, @ARectF, AStringFormat, AGpBrush));
  finally
    GdipDeleteFont(AGpFont);
    GdipDeleteBrush(AGpBrush);
    GdipDeleteStringFormat(AStringFormat);
  end;
end;

procedure dxGpFillRect(DC: HDC; const R: TRect; AColor: TColor; AColorAlpha: Byte = 255);
begin
  dxGPPaintCanvas.BeginPaint(DC, R);
  dxGpFillRect(dxGPPaintCanvas.Handle, R, dxGpColorToARGB(AColor, AColorAlpha));
  dxGPPaintCanvas.EndPaint;
end;

procedure dxGpFillRect(AGraphics: GpGraphics; const R: TRect; AColor: ARGB);
var
  ABrush: GpSolidFill;
  R1: TdxGPRect;
begin
  R1 := MakeRect(R.Left, R.Top, cxRectWidth(R), cxRectHeight(R));
  GdipCheck(GdipCreateSolidFill(AColor, ABrush));
  GdipCheck(GdipFillRectangleI(AGraphics, ABrush, R1.X, R1.Y, R1.Width, R1.Height));
  GdipCheck(GdipDeleteBrush(ABrush));
end;

procedure dxGpFillRectByGradient(DC: HDC; const R: TRect;
  AColor1, AColor2: TColor; AMode: TdxGPLinearGradientMode;
  AColor1Alpha: Byte = 255; AColor2Alpha: Byte = 255);
begin
  if not IsRectEmpty(R) then
  begin
    dxGPPaintCanvas.BeginPaint(DC, R);
    dxGpFillRectByGradient(dxGPPaintCanvas.Handle, R,
      dxGpColorToARGB(AColor1, AColor1Alpha),
      dxGpColorToARGB(AColor2, AColor2Alpha), AMode);
    dxGPPaintCanvas.EndPaint;
  end;
end;

procedure dxGpFillRectByGradient(AGraphics: GpGraphics;
  const R: TRect; AColor1, AColor2: ARGB; AMode: TdxGPLinearGradientMode);
var
  ABrush: GpLineGradient;
  ABrushRect: TdxGPRect;
begin
  // Inflate: Avoid GDIPlus gradient fill bug
  ABrushRect := MakeRect(R.Left - 1, R.Top - 1, R.Right - R.Left + 2, R.Bottom - R.Top + 2);
  GdipCheck(GdipCreateLineBrushFromRectI(@ABrushRect, AColor1, AColor2, AMode, WrapModeTile, ABrush));
  GdipCheck(GdipFillRectangleI(AGraphics, ABrush, R.Left, R.Top, R.Right - R.Left, R.Bottom - R.Top));
  GdipCheck(GdipDeleteBrush(ABrush));
end;

function dxGpCreateBrush(out ABrushHandle: GpBrush; ABrushColor: TColor; ABrushColorAlpha: Byte = 255): Boolean;
begin
  Result := ABrushColor <> clNone;
  if Result then
    GdipCheck(GdipCreateSolidFill(dxGpColorToARGB(ABrushColor, ABrushColorAlpha), ABrushHandle));
end;

function dxGpCreatePen(out APenHandle: GpPen; APenColor: TColor; APenWidth: Single;
  APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255): Boolean;
const
  PenStylesMap: array[psSolid..psDashDotDot] of GpDashStyle = (
    DashStyleSolid, DashStyleDash, DashStyleDot, DashStyleDashDot, DashStyleDashDotDot
  );
begin
  Result := (APenColor <> clNone) and (APenWidth > 0) and (APenStyle >= psSolid) and (APenStyle <= psDashDotDot);
  if Result then
  begin
    GdipCheck(GdipCreatePen1(dxGpColorToARGB(APenColor, APenColorAlpha), APenWidth, UnitPixel, APenHandle));
    GdipCheck(GdipSetPenDashStyle(APenHandle, PenStylesMap[APenStyle]));
  end;
end;

function dxGpIsDoubleBufferedNeeded(DC: HDC): Boolean;
var
  AWindowHandle: HWND;
begin
  Result := (GetDeviceCaps(DC, BITSPIXEL) <= 16) or
    (GetDeviceCaps(DC, TECHNOLOGY) = DT_RASPRINTER) or
    (GetDeviceCaps(DC, NUMCOLORS) > 1);

  if not (Result or IsWinVistaOrLater) then 
  begin
    AWindowHandle := dxWindowFromDC(DC);
    if AWindowHandle <> 0 then
      Result := GetWindowLong(AWindowHandle, GWL_EXSTYLE) and WS_EX_LAYERED <> 0;
  end;
end;

function dxGpIsRectVisible(AGraphics: GpGraphics; const R: TRect): LongBool;
begin
  GdipCheck(GdipIsVisibleRectI(AGraphics, R.Left, R.Top, cxRectWidth(R), cxRectHeight(R), Result));
end;

procedure dxGpTilePart(DC: HDC; const ADestRect, ASourceRect: TRect; AImage: GpBitmap);
begin
  dxGPPaintCanvas.BeginPaint(DC, ADestRect);
  dxGpTilePartEx(dxGPPaintCanvas.Handle, ADestRect, ASourceRect, AImage);
  dxGPPaintCanvas.EndPaint;
end;

procedure dxGpTilePartEx(AGraphics: GpGraphics;
  const ADestRect, ASourceRect: TRect; AImage: GpBitmap; AAlpha: Byte = 255);

  function CreateTextureBrush(const R: TRect; out ATexture: GpTexture): Boolean;
  begin
    Result := GdipCreateTexture2I(AImage, WrapModeTile,
      R.Left, R.Top, cxRectWidth(R), cxRectHeight(R), ATexture) = Ok;
  end;

  procedure ManualTilePart(const ADest, ASource: TRect;
    ADestWidth, ADestHeight, ASourceWidth, ASourceHeight: Integer);
  var
    ALastCol, ALastRow, ACol, ARow: Integer;
    RDest, RSrc: TRect;
  begin
    ALastCol := ADestWidth div ASourceWidth - Ord(ADestWidth mod ASourceWidth = 0);
    ALastRow := ADestHeight div ASourceHeight - Ord(ADestHeight mod ASourceHeight = 0);
    for ARow := 0 to ALastRow do
    begin
      RSrc.Top := ASource.Top;
      RSrc.Bottom := ASource.Bottom;
      RDest.Top := ADest.Top + ASourceHeight * ARow;
      RDest.Bottom := RDest.Top + ASourceHeight;
      if RDest.Bottom > ADest.Bottom then
      begin
        Dec(RSrc.Bottom, RDest.Bottom - ADest.Bottom);
        RDest.Bottom := ADest.Bottom;
      end;
      for ACol := 0 to ALastCol do
      begin
        RSrc.Left := ASource.Left;
        RSrc.Right := ASource.Right;
        RDest.Left := ADest.Left + ASourceWidth * ACol;
        RDest.Right := RDest.Left + ASourceWidth;
        if RDest.Right > ADest.Right then
        begin
          Dec(RSrc.Right, RDest.Right - ADest.Right);
          RDest.Right := ADest.Right;
        end;
        dxGpDrawImage(AGraphics, RDest, RSrc, AImage, AAlpha);
      end;
    end;
  end;

  function TilePartByBrush(const R, ASource: TRect): Boolean;
  var
    ABitmap: GpBitmap;
    ABitmapGraphics: GpGraphics;
    ATexture: GpTexture;
    AWidth, AHeight: Integer;
  begin
    Result := CreateTextureBrush(ASource, ATexture);
    if Result then
    try
      AWidth := cxRectWidth(R);
      AHeight := cxRectHeight(R);
      GdipCheck(GdipCreateBitmapFromScan0(AWidth, AHeight, 0, PixelFormat32bppPARGB, nil, ABitmap));
      try
        GdipCheck(GdipGetImageGraphicsContext(ABitmap, ABitmapGraphics));
        GdipCheck(GdipFillRectangleI(ABitmapGraphics, ATexture, 0, 0, AWidth, AHeight));
        GdipCheck(GdipDrawImageRectI(AGraphics, ABitmap, R.Left, R.Top, AWidth, AHeight));
        GdipCheck(GdipDeleteGraphics(ABitmapGraphics));
      finally
        GdipCheck(GdipDisposeImage(ABitmap));
      end;
    finally
      GdipCheck(GdipDeleteBrush(ATexture));
    end;
  end;

var
  ADestWidth, ADestHeight: Integer;
  ASourceWidth, ASourceHeight: Integer;
begin
  if not IsRectEmpty(ASourceRect) and dxGpIsRectVisible(AGraphics, ADestRect) then
  begin
    ADestWidth := cxRectWidth(ADestRect);
    ADestHeight := cxRectHeight(ADestRect);
    ASourceWidth := cxRectWidth(ASourceRect);
    ASourceHeight := cxRectHeight(ASourceRect);
    if (AAlpha <> 255) or (ADestWidth <= ASourceWidth) and (ADestHeight <= ASourceHeight) or
      not TilePartByBrush(ADestRect, ASourceRect)
    then
      ManualTilePart(ADestRect, ASourceRect, ADestWidth, ADestHeight, ASourceWidth, ASourceHeight);
  end;
end;

procedure dxGpResetRect(AGraphics: GpGraphics; const R: TRect);
var
  ACompositionMode: Integer;
begin
  GdipCheck(GdipGetCompositingMode(AGraphics, ACompositionMode));
  try
    GdipCheck(GdipSetCompositingMode(AGraphics, CompositingModeSourceCopy));
    dxGpFillRect(AGraphics, R, 0);
  finally
    GdipCheck(GdipSetCompositingMode(AGraphics, ACompositionMode))
  end;
end;

procedure dxGpRoundRect(DC: HDC; const R: TRect; APenColor: TColor;
  ABrushColor: TColor; ARadius: Integer; APenWidth: Integer = 1;
  APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255);
begin
  dxGPPaintCanvas.BeginPaint(DC, R);
  try
    dxGPPaintCanvas.RoundRect(R, APenColor, ABrushColor,
      ARadius, ARadius, APenWidth, APenColorAlpha, ABrushColorAlpha);
  finally
    dxGPPaintCanvas.EndPaint;
  end;
end;

function dxGPPaintCanvas: TdxGPPaintCanvas;
begin
  if GPPaintCanvas = nil then
    GPPaintCanvas := TdxGPPaintCanvas.Create(nil);
  Result := GPPaintCanvas;
end;

{ TdxGPImageDataHelper }

class function TdxGPImageDataHelper.IsBitmapStream(AStream: TStream): Boolean;
var
  AHeader: TBitmapFileHeader;
begin
  AStream.ReadBuffer(AHeader, SizeOf(AHeader));
  Result := AHeader.bfType = $4D42;
  AStream.Seek(-SizeOf(AHeader), soCurrent);
end;

{ TdxGPAlphaBlendAttributes }

constructor TdxGPAlphaBlendAttributes.Create;
begin
  inherited Create;
  GdipCheck(GdipCreateImageAttributes(FHandle));
  FColorMatrix := dxGpDefaultColorMatrix;
  Alpha := 255;
end;

destructor TdxGPAlphaBlendAttributes.Destroy;
begin
  GdipCheck(GdipDisposeImageAttributes(FHandle));
  inherited Destroy;
end;

procedure TdxGPAlphaBlendAttributes.SetAlpha(AValue: Byte);
begin
  if AValue <> FAlpha then
  begin
    FAlpha := AValue;
    FColorMatrix[3, 3] := Alpha / 255;
    GdipCheck(GdipSetImageAttributesColorMatrix(FHandle,
      ColorAdjustTypeBitmap, True, @FColorMatrix, nil, ColorMatrixFlagsDefault));
  end;
end;

{ TdxGPMemoryStream }

function TdxGPMemoryStream.Realloc(var ANewCapacity: Integer): Pointer;
begin
  Result := Memory;
  if ANewCapacity <> Capacity then
  begin
    if ANewCapacity > 0 then
    begin
      Result := GdipAlloc(ANewCapacity);
      if Result = nil then
        raise EStreamError.CreateRes(@SMemoryStreamError);
      if Capacity > 0 then
        Move(Memory^, Result^, Min(Capacity, ANewCapacity));
    end
    else
      Result := nil;

    if Capacity > 0 then
      GdipFree(Memory);
  end;
end;

{ TdxGPStreamAdapter }

function TdxGPStreamAdapter.Stat(out StatStg: TStatStg; StatFlag: Integer): HRESULT;
begin
  Result := S_OK;
  try
    if @StatStg <> nil then
    begin
      ZeroMemory(@StatStg, SizeOf(StatStg));
      Result := inherited Stat(StatStg, StatFlag);
    end;
  except
    Result := E_UNEXPECTED;
  end;
end;

{ TdxGPBrush }

constructor TdxGPBrush.Create;
begin
  SetStatus(NotImplemented);
  FNativeBrush := nil;
end;

destructor TdxGPBrush.Destroy;
begin
  GdipDeleteBrush(FNativeBrush);
  inherited;
end;

constructor TdxGPBrush.CreateNative(nativeBrush: GpBrush; AStatus: Status);
begin
  inherited Create;
  FLastResult := AStatus;
  SetNativeBrush(FNativeBrush);
end;

function TdxGPBrush.Clone: TdxGPBrush;
var
  gpB: GpBrush;
begin
  gpB := nil;
  Result := nil;
  SetStatus (GdipCloneBrush(FNativeBrush, gpB));
  try
    Result := TdxGPBrush.CreateNative(gpB, FLastResult);
  except
    GdipDeleteBrush(gpB);
  end;
end;

function TdxGPBrush.GetLastStatus: Status;
begin
  Result := FLastResult;
  FLastResult := Ok;
end;

function TdxGPBrush.GetType: BrushType;
begin
  SetStatus(GdipGetBrushType (FNativeBrush, Result));
end;

procedure TdxGPBrush.SetNativeBrush(ANativeBrush: GpBrush);
begin
  FNativeBrush := ANativeBrush;
end;

function TdxGPBrush.SetStatus(AStatus: TdxGPStatus): TdxGPStatus;
begin
  Result := AStatus;
  if (AStatus <> Ok) and (FLastResult <> AStatus) then
  Result := GenericError;
end;

{ TdxGPSolidBrush }

constructor TdxGPSolidBrush.Create(color: TColor);
var
  ABrush: GpSolidFill;
begin
  ABrush := nil;
  FLastResult := GdipCreateSolidFill(color, ABrush);
  SetNativeBrush(ABrush);
end;

constructor TdxGPSolidBrush.Create;
begin
// hide parent method
end;

function TdxGPSolidBrush.GetColor: DWORD;
begin
  SetStatus(GdipGetSolidFillColor(GPSOLIDFILL(FNativeBrush), Result));
end;

procedure TdxGPSolidBrush.SetColor(const Value: DWORD);
begin
  SetStatus(GdipSetSolidFillColor(GpSolidFill(FNativeBrush), Value));
end;

{ TdxGPLinearGradientBrush }

constructor TdxGPLinearGradientBrush.Create(rect: TdxGPRect; color1, color2: DWORD; mode: TdxGPLinearGradientMode);
var
  ABrush: GpLineGradient;
begin
  ABrush := nil;
  FLastResult := GdipCreateLineBrushFromRectI(@rect, color1, color2, mode, WrapModeTile, ABrush);
  SetNativeBrush(ABrush);
end;

constructor TdxGPLinearGradientBrush.Create;
begin
// hide parent method
end;

function TdxGPLinearGradientBrush.GetLinearColors(out color1, color2: DWORD): TdxGPStatus;
var
  AColors: array[0..1] of DWORD;
begin
  SetStatus(GdipGetLineColors(GpLineGradient(FNativeBrush), PARGB(@AColors)));
  if (FLastResult = Ok) then
  begin
    color1 := AColors[0];
    color2 := AColors[1];
  end;
  Result := FLastResult;
end;

function TdxGPLinearGradientBrush.GetRectangle: TdxGPRect;
var
  ARect: PdxGPRect;
begin
  ARect := @Result;
  SetStatus(GdipGetLineRectI(GpLineGradient(FNativeBrush), ARect));
end;

function TdxGPLinearGradientBrush.GetWrapMode: TdxGPWrapMode;
begin
   Result := WrapModeTile;
   SetStatus(GdipGetLineWrapMode(GpLineGradient(FNativeBrush), Result));
end;

function TdxGPLinearGradientBrush.SetLinearColors(color1, color2: DWORD): TdxGPStatus;
begin
  Result := SetStatus(GdipSetLineColors(GpLineGradient(FNativeBrush), color1, color2));
end;

procedure TdxGPLinearGradientBrush.SetWrapMode(const Value: TdxGPWrapMode);
begin
  SetStatus(GdipSetLineWrapMode(GpLineGradient(FNativeBrush), Value));
end;

{ TdxGPHatchBrush }

constructor TdxGPHatchBrush.Create;
begin
// hide parent method
end;

constructor TdxGPHatchBrush.Create(hatchStyle: TdxGPHatchStyle; foreColor,
  backColor: DWORD);
var
  ABrush: GpHatch;
begin
  ABrush := nil;
  FLastResult := GdipCreateHatchBrush(hatchStyle, foreColor, backColor, ABrush);
  SetNativeBrush(ABrush);
end;

function TdxGPHatchBrush.GetBackgroundColor: DWORD;
begin
  SetStatus(GdipGetHatchBackgroundColor(GpHatch(FNativeBrush), Result));
end;

function TdxGPHatchBrush.GetForegroundColor: DWORD;
begin
  SetStatus(GdipGetHatchForegroundColor(GpHatch(FNativeBrush), Result));
end;

function TdxGPHatchBrush.GetHatchStyle: TdxGPHatchStyle;
begin
  SetStatus(GdipGetHatchStyle(GpHatch(FNativeBrush), Result));
end;

{ TdxGPPen }

constructor TdxGPPen.Create(brush: TdxGPBrush; width: Single);
var
  unit_: TdxGPUnit;
begin
  unit_ := UnitWorld;
  FNativePen := nil;
  FLastResult := GdipCreatePen2(brush.FNativeBrush, width, unit_, FNativePen);
end;

constructor TdxGPPen.Create(color: DWORD; width: Single);
var
  unit_: TdxGPUnit;
begin
  unit_ := UnitPixel;
  FNativePen := nil;
  FLastResult := GdipCreatePen1(color, width, unit_, FNativePen);
end;

destructor TdxGPPen.Destroy;
begin
  GdipDeletePen(FNativePen);
  inherited;
end;

function TdxGPPen.GetAlignment: TdxGPPenAlignment;
begin
  SetStatus(GdipGetPenMode(FNativePen, Result));
end;

function TdxGPPen.GetBrush: TdxGPBrush;
var
  ABrush: TdxGPBrush;
  ANativeBrush: GpBrush;
begin
  case GetPenType of
    PenTypeSolidColor:
      ABrush := TdxGPSolidBrush.Create;
    PenTypeHatchFill:
      ABrush := TdxGPHatchBrush.Create;
    PenTypeTextureFill:
      ABrush := TdxGPTextureBrush.Create;
    PenTypePathGradient:
      ABrush := TdxGPBrush.Create;
    PenTypeLinearGradient:
      ABrush := TdxGPLinearGradientBrush.Create;
    else
      ABrush := nil;
  end;
  if ABrush <> nil then
  begin
    SetStatus(GdipGetPenBrushFill(FNativePen, ANativeBrush));
    brush.SetNativeBrush(ANativeBrush);
  end;
  Result := ABrush;
end;

function TdxGPPen.GetColor: DWORD;
var
  AColor: ARGB;
begin
  Result := 0;
  if GetPenType = PenTypeSolidColor then
  begin
    SetStatus(GdipGetPenColor(FNativePen, AColor));
    if FLastResult = Ok then
      Result := AColor;
  end;
end;

function TdxGPPen.GetLastStatus: TdxGPStatus;
begin
  Result := FLastResult;
  FLastResult := Ok;
end;

function TdxGPPen.GetPenType: TdxGPPenType;
begin
  SetStatus(GdipGetPenFillType(FNativePen, Result));
end;

function TdxGPPen.GetWidth: Single;
begin
  SetStatus(GdipGetPenWidth(FNativePen, Result));
end;

procedure TdxGPPen.SetAlignment(const Value: TdxGPPenAlignment);
begin
  SetStatus(GdipSetPenMode(FNativePen, Value));
end;

procedure TdxGPPen.SetBrush(const Value: TdxGPBrush);
begin
  SetStatus(GdipSetPenBrushFill(FNativePen, Value.FNativeBrush));
end;

procedure TdxGPPen.SetColor(const Value: DWORD);
begin
  SetStatus(GdipSetPenColor(FNativePen, Value));
end;

procedure TdxGPPen.SetNativePen(ANativePen: GpPen);
begin
  FNativePen := ANativePen;
end;

function TdxGPPen.SetStatus(AStatus: TdxGPStatus): TdxGPStatus;
begin
  if AStatus <> Ok then
    FLastResult := AStatus;
  Result := AStatus;
end;

procedure TdxGPPen.SetWidth(const Value: Single);
begin
  SetStatus(GdipSetPenWidth(FNativePen, Value));
end;

{ TdxGPCanvas }

constructor TdxGPCanvas.Create(AHandle: GpGraphics);
begin
  inherited Create;
  FHandle := AHandle;
end;

constructor TdxGPCanvas.Create(DC: THandle);
begin
  inherited Create;
  CreateHandle(DC);
end;

destructor TdxGPCanvas.Destroy;
begin
  FreeHandle;
  inherited Destroy;
end;

procedure TdxGPCanvas.CheckDestRect(var R: TRect);
begin
  Dec(R.Bottom);
  Dec(R.Right);
end;

procedure TdxGPCanvas.Clear(AColor: TColor);
begin
  GdipCheck(GdipGraphicsClear(Handle, dxGpColorToARGB(AColor)));
end;

procedure TdxGPCanvas.Draw(AGraphic: TdxGPImage; const R: TRect; AAlpha: Byte = 255);
begin
  Draw(AGraphic, R, AGraphic.ClientRect, AAlpha);
end;

procedure TdxGPCanvas.Draw(AGraphic: TdxGPImage;
  const ADestRect, ASourceRect: TRect; AAlpha: Byte = 255);
begin
  dxGpDrawImage(Handle, ADestRect, ASourceRect, AGraphic.Handle, AAlpha);
end;

procedure TdxGPCanvas.DrawBitmap(ABitmap: TBitmap; const R: TRect; AAlpha: Byte = 255);
var
  AImage: TdxGPImage;
begin
  if not ABitmap.Empty then
  begin
    AImage := TdxGPImage.CreateFromBitmap(ABitmap);
    try
      Draw(AImage, R, AAlpha);
    finally
      AImage.Free;
    end;
  end;
end;

procedure TdxGPCanvas.DrawTile(AGraphic: TdxGPImage; const R: TRect; AAlpha: Byte);
begin
  dxGpTilePartEx(Handle, R, AGraphic.ClientRect, AGraphic.Handle, AAlpha);
end;

procedure TdxGPCanvas.Arc(R: TRect; AStartAngle, ASweepAngle: Single; APenColor: TColor;
  APenWidth: Single = 1; APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255);
var
  APen: GpPen;
begin
  CheckDestRect(R);
  if dxGpCreatePen(APen, APenColor, APenWidth, APenStyle, APenColorAlpha) then
  begin
    GdipCheck(GdipDrawArcI(Handle, APen, R.Left, R.Top,
      cxRectWidth(R), cxRectHeight(R), -AStartAngle, -ASweepAngle));
    GdipCheck(GdipDeletePen(APen));
  end;
end;

procedure TdxGPCanvas.Ellipse(R: TRect; APenColor, ABrushColor: TColor;
  APenWidth: Single = 1; APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255;
  ABrushColorAlpha: Byte = 255);
var
  ABrush: GpBrush;
  APen: GpPen;
begin
  CheckDestRect(R);

  if dxGpCreateBrush(ABrush, ABrushColor, ABrushColorAlpha) then
  begin
    GdipCheck(GdipFillEllipseI(Handle, ABrush, R.Left, R.Top, cxRectWidth(R), cxRectHeight(R)));
    GdipCheck(GdipDeleteBrush(ABrush));
  end;

  if dxGpCreatePen(APen, APenColor, APenWidth, APenStyle, APenColorAlpha) then
  begin
    GdipCheck(GdipDrawEllipseI(Handle, APen, R.Left, R.Top, cxRectWidth(R), cxRectHeight(R)));
    GdipCheck(GdipDeletePen(APen));
  end;
end;

procedure TdxGPCanvas.Line(X1, Y1, X2, Y2: Integer; APenColor: TColor;
  APenWidth: Single = 1; APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255);
var
  APen: GpPen;
begin
  if dxGpCreatePen(APen, APenColor, APenWidth, APenStyle, APenColorAlpha) then
  begin
    GdipCheck(GdipDrawLineI(Handle, APen, X1, Y1, X2, Y2));
    GdipCheck(GdipDeletePen(APen));
  end;
end;

procedure TdxGPCanvas.Pie(R: TRect; AStartAngle, ASweepAngle: Single;
  APenColor: TColor; ABrushColor: TColor; APenWidth: Single = 1;
  APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255;
  ABrushColorAlpha: Byte = 255);
var
  ABrush: GpBrush;
  APen: GpPen;
begin
  CheckDestRect(R);

  if dxGpCreateBrush(ABrush, ABrushColor, ABrushColorAlpha) then
  begin
    GdipCheck(GdipFillPieI(Handle, ABrush, R.Left, R.Top,
      cxRectWidth(R), cxRectHeight(R), -AStartAngle, -ASweepAngle));
    GdipCheck(GdipDeleteBrush(ABrush));
  end;

  if dxGpCreatePen(APen, APenColor, APenWidth, APenStyle, APenColorAlpha) then
  begin
    GdipCheck(GdipDrawPieI(Handle, APen, R.Left, R.Top,
      cxRectWidth(R), cxRectHeight(R), -AStartAngle, -ASweepAngle));
    GdipCheck(GdipDeletePen(APen));
  end;
end;

procedure TdxGPCanvas.Polygon(const APoints: array of TPoint; APenColor: TColor;
  ABrushColor: TColor; APenWidth: Single = 1; APenStyle: TPenStyle = psSolid;
  APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255);
var
  ABrush: GpBrush;
  APen: GpPen;
begin
  if dxGpCreateBrush(ABrush, ABrushColor, ABrushColorAlpha) then
  begin
    GdipCheck(GdipFillPolygonI(Handle, ABrush, @APoints[0], Length(APoints), FillModeWinding));
    GdipCheck(GdipDeleteBrush(ABrush));
  end;

  if dxGpCreatePen(APen, APenColor, APenWidth, APenStyle, APenColorAlpha) then
  begin
    GdipCheck(GdipDrawPolygonI(Handle, APen, @APoints[0], Length(APoints)));
    GdipCheck(GdipDeletePen(APen));
  end;
end;

procedure TdxGPCanvas.Polygon(const APoints: array of TdxPointF; APenColor: TColor;
  ABrushColor: TColor; APenWidth: Single = 1; APenStyle: TPenStyle = psSolid;
  APenColorAlpha: Byte = 255; ABrushColorAlpha: Byte = 255);
var
  ABrush: GpBrush;
  APen: GpPen;
begin
  if dxGpCreateBrush(ABrush, ABrushColor, ABrushColorAlpha) then
  begin
    GdipCheck(GdipFillPolygon(Handle, ABrush, @APoints[0], Length(APoints), FillModeWinding));
    GdipCheck(GdipDeleteBrush(ABrush));
  end;

  if dxGpCreatePen(APen, APenColor, APenWidth, APenStyle, APenColorAlpha) then
  begin
    GdipCheck(GdipDrawPolygon(Handle, APen, @APoints[0], Length(APoints)));
    GdipCheck(GdipDeletePen(APen));
  end;
end;

procedure TdxGPCanvas.Polyline(const APoints: array of TPoint; APenColor: TColor;
  APenWidth: Single = 1; APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255);
var
  APen: GpPen;
begin
  if dxGpCreatePen(APen, APenColor, APenWidth, APenStyle, APenColorAlpha) then
  begin
    GdipCheck(GdipDrawLinesI(Handle, APen, @APoints[0], Length(APoints)));
    GdipCheck(GdipDeletePen(APen));
  end;
end;

procedure TdxGPCanvas.Rectangle(R: TRect; APenColor, ABrushColor: TColor;
  APenWidth: Single = 1; APenStyle: TPenStyle = psSolid; APenColorAlpha: Byte = 255;
  ABrushColorAlpha: Byte = 255);
var
  ABrush: GpBrush;
  APen: GpPen;
begin
  CheckDestRect(R);

  if dxGpCreateBrush(ABrush, ABrushColor, ABrushColorAlpha) then
  begin
    GdipCheck(GdipFillRectangleI(Handle, ABrush, R.Left, R.Top, cxRectWidth(R), cxRectHeight(R)));
    GdipCheck(GdipDeleteBrush(ABrush));
  end;

  if dxGpCreatePen(APen, APenColor, APenWidth, APenStyle, APenColorAlpha) then
  begin
    GdipCheck(GdipDrawRectangleI(Handle, APen, R.Left, R.Top, cxRectWidth(R), cxRectHeight(R)));
    GdipCheck(GdipDeletePen(APen));
  end;
end;

procedure TdxGPCanvas.RoundRect(const R: TRect; APenColor, ABrushColor: TColor;
  ARadiusX, ARadiusY: Integer; APenWidth: Integer = 1;APenColorAlpha: Byte = 255;
  ABrushColorAlpha: Byte = 255);

  function CreateRoundRectPath(R: TRect; ARadiusX, ARadiusY: Integer): GpPath;
  begin
    ARadiusX := Min(ARadiusX, cxRectWidth(R) div 3);
    ARadiusY := Min(ARadiusY, cxRectHeight(R) div 3);

    CheckDestRect(R);
    GdipCheck(GdipCreatePath(FillModeAlternate, Result));
    GdipStartPathFigure(Result);
    GdipAddPathLine(Result, R.Left + ARadiusX, R.Top, R.Right - 2 * ARadiusX, R.Top);
    GdipAddPathArc(Result, R.Right - 2 * ARadiusX, R.Top, 2 * ARadiusX, 2 * ARadiusY, 270, 90);
    GdipAddPathLine(Result, R.Right, R.Top + ARadiusY, R.Right, R.Bottom - 2 * ARadiusY);
    GdipAddPathArc(Result, R.Right - 2 * ARadiusX, R.Bottom - 2 * ARadiusY, 2 * ARadiusX, 2 * ARadiusY, 0, 90);
    GdipAddPathLine(Result, R.Right - 2 * ARadiusX, R.Bottom, R.Left + ARadiusX, R.Bottom);
    GdipAddPathArc(Result, R.Left, R.Bottom - 2 * ARadiusY, 2 * ARadiusX, 2 * ARadiusY, 90, 90);
    GdipAddPathLine(Result, R.Left, R.Bottom - 2 * ARadiusY, R.Left, R.Top + ARadiusY);
    GdipAddPathArc(Result, R.Left, R.Top, 2 * ARadiusX, 2 * ARadiusY, 180, 90);
    GdipClosePathFigure(Result);
  end;

var
  ABrush: GpBrush;
  APath: GpPath;
  APen: GpPen;
begin
  APath := CreateRoundRectPath(R, ARadiusX, ARadiusY);
  try
    if dxGpCreateBrush(ABrush, ABrushColor, ABrushColorAlpha) then
    begin
      GdipCheck(GdipFillPath(Handle, ABrush, APath));
      GdipCheck(GdipDeleteBrush(ABrush));
    end;

    if dxGpCreatePen(APen, APenColor, APenWidth, psSolid, APenColorAlpha) then
    begin
      GdipCheck(GdipDrawPath(Handle, APen, APath));
      GdipCheck(GdipDeletePen(APen));
    end;
  finally
    GdipCheck(GdipDeletePath(APath));
  end;
end;

procedure TdxGPCanvas.CreateHandle(DC: HDC);
begin
  GdipCheck(GdipCreateFromHDC(DC, FHandle));
end;

procedure TdxGPCanvas.FreeHandle;
begin
  if FHandle <> nil then
  begin
    GdipCheck(GdipDeleteGraphics(FHandle));
    FHandle := nil;
  end;
end;

function TdxGPCanvas.GetHDC: HDC;
begin
  GdipCheck(GdipGetDC(Handle, Result));
end;

procedure TdxGPCanvas.ReleaseHDC(DC: HDC);
begin
  GdipCheck(GdipReleaseDC(Handle, DC));
end;

function TdxGPCanvas.GetInterpolationMode: TdxGPInterpolationMode;
var
  AResult: Integer;
begin
  GdipCheck(GdipGetInterpolationMode(Handle, AResult));
  if (AResult >= Ord(Low(TdxGPInterpolationMode))) and (AResult <= Ord(High(TdxGPInterpolationMode))) then
    Result := TdxGPInterpolationMode(AResult)
  else
    Result := imDefault;
end;

function TdxGPCanvas.GetSmoothingMode: TdxGPSmoothingMode;
var
  AResult: Integer;
begin
  GdipCheck(GdipGetSmoothingMode(Handle, AResult));
  if (AResult >= Ord(Low(TdxGPSmoothingMode))) and (AResult <= Ord(High(TdxGPSmoothingMode))) then
    Result := TdxGPSmoothingMode(AResult)
  else
    Result := smDefault;
end;

procedure TdxGPCanvas.SetInterpolationMode(AValue: TdxGPInterpolationMode);
begin
  GdipCheck(GdipSetInterpolationMode(Handle, Integer(AValue)));
end;

procedure TdxGPCanvas.SetSmoothingMode(AValue: TdxGPSmoothingMode);
begin
  GdipCheck(GdipSetSmoothingMode(Handle, Integer(AValue)));
end;

{ TdxGPCustomPaintCanvas }

procedure TdxGPCustomPaintCanvas.BeginPaint(DC: HDC; const R: TRect);
begin
  SaveState;
  FDrawRect := R;
  FDrawDC := DC;
  if dxGpIsDoubleBufferedNeeded(DC) then
  begin
    CreateBuffer(DC, R);
    DC := FBuffer.Canvas.Handle;
  end
  else
    FBuffer := nil;

  CreateHandle(DC);
end;

procedure TdxGPCustomPaintCanvas.BeginPaint(AHandle: GpGraphics);
begin
  SaveState;
  FDrawRect := Rect(0, 0, 0, 0);
  FDrawDC := 0;
  FHandle := AHandle;
  FBuffer := nil;
end;

procedure TdxGPCustomPaintCanvas.EndPaint;
begin
  if FDrawDC <> 0 then
    FreeHandle;
  if FBuffer <> nil then
    FreeBuffer;
  RestoreState;
end;

procedure TdxGPCustomPaintCanvas.CreateBuffer(DC: HDC; const R: TRect);
begin
  FBuffer := TBitmap.Create;
  FBuffer.PixelFormat := pf32bit;
  FBuffer.Height := cxRectHeight(R) + 1;
  FBuffer.Width := cxRectWidth(R) + 1;
  FBuffer.Canvas.Lock;

  BitBlt(FBuffer.Canvas.Handle, 0, 0, FBuffer.Width, FBuffer.Height, DC, R.Left, R.Top, SRCCOPY);
  SetWindowOrgEx(FBuffer.Canvas.Handle, R.Left, R.Top, nil);
end;

procedure TdxGPCustomPaintCanvas.FreeBuffer;
begin
  OutputBuffer;
  FBuffer.Canvas.Unlock;
  FreeAndNil(FBuffer);
end;

procedure TdxGPCustomPaintCanvas.OutputBuffer;
var
  ACanvas: TCanvas;
  ASaveIndex: Integer;
begin
  ACanvas := TCanvas.Create;
  try
    ACanvas.Lock;
    try
      ASaveIndex := SaveDC(FDrawDC);
      ACanvas.Handle := FDrawDC;
      SetWindowOrgEx(FBuffer.Canvas.Handle, 0, 0, nil);
      ACanvas.Draw(FDrawRect.Left, FDrawRect.Top, FBuffer);
      ACanvas.Handle := 0;
      RestoreDC(FDrawDC, ASaveIndex);
    finally
      ACanvas.Unlock;
    end;
  finally
    ACanvas.Free;
  end;
end;

procedure TdxGPCustomPaintCanvas.SaveState;
begin
//do nothing
end;

procedure TdxGPCustomPaintCanvas.RestoreState;
begin
//do nothing
end;

{ TdxGPPaintCanvas }

destructor TdxGPPaintCanvas.Destroy;
begin
  Finalize(FSavedStates);
  inherited Destroy;
end;

procedure TdxGPPaintCanvas.SaveState;
begin
  SetCapacity(FCounter + 1);
  FSavedStates[FCounter].Handle := Handle;
  FSavedStates[FCounter].Buffer := FBuffer;
  FSavedStates[FCounter].DrawRect := FDrawRect;
  FSavedStates[FCounter].DC := FDrawDC;
  Inc(FCounter);
end;

procedure TdxGPPaintCanvas.RestoreState;
begin
  Dec(FCounter);
  FHandle := FSavedStates[FCounter].Handle;
  FBuffer := FSavedStates[FCounter].Buffer;
  FDrawRect := FSavedStates[FCounter].DrawRect;
  FDrawDC := FSavedStates[FCounter].DC;
end;

procedure TdxGPPaintCanvas.SetCapacity(AValue: Integer);
begin
  if AValue > Length(FSavedStates) then
    SetLength(FSavedStates, Max(AValue, Length(FSavedStates) + 4));
end;

{ TdxGPImage }

constructor TdxGPImage.Create;
begin
  inherited Create;
  FImageData := TdxGPImageData.Create;
end;

constructor TdxGPImage.CreateSize(const ASize: TSize; AColor: ARGB = 255);
var
  I: Integer;
  ABits: TRGBColors;
begin
  Create;
  SetLength(ABits, ASize.cx * ASize.cy);
  for I := 0 to Length(ABits) - 1 do
    Integer(ABits[I]) := AColor;
  CreateHandleFromBits(ASize.cx, ASize.cy, ABits, True);
end;

constructor TdxGPImage.CreateSize(const R: TRect; AColor: ARGB);
begin
  CreateSize(cxSize(R), AColor);
end;

constructor TdxGPImage.CreateSize(AWidth, AHeight: Integer; AColor: ARGB = 255);
begin
  CreateSize(cxSize(AWidth, AHeight), AColor);
end;

constructor TdxGPImage.CreateFromBitmap(ABitmap: TBitmap);
begin
  Create;
  CreateHandleFromBitmap(ABitmap);
end;

constructor TdxGPImage.CreateFromHBitmap(ABitmap: HBitmap);
begin
  Create;
  CreateHandleFromHBITMAP(ABitmap, 0);
end;

constructor TdxGPImage.CreateFromBits(AWidth, AHeight: Integer;
  const ABits: TRGBColors; AHasAlphaChannel: Boolean);
begin
  Create;
  CreateHandleFromBits(AWidth, AHeight, ABits, AHasAlphaChannel);
end;

constructor TdxGPImage.CreateFromStream(AStream: TStream);
begin
  Create;
  CreateHandleFromStream(AStream);
end;

destructor TdxGPImage.Destroy;
begin
  FreeHandle;
  FreeAndNil(FImageData);
  inherited Destroy;
end;

procedure TdxGPImage.Assign(ASource: TPersistent);
begin
  if ASource = nil then
    Clear
  else
    if ASource is TdxGPImage then
      AssignFromGpImage(TdxGPImage(ASource))
    else
      if ASource is TGraphic then
        AssignFromGraphic(TGraphic(ASource))
      else
        inherited Assign(ASource);
end;

procedure TdxGPImage.AssignFromGpImage(AGpImage: TdxGPImage);
var
  ABitmap: TBitmap;
  AStream: TMemoryStream;
begin
  if AGpImage.Empty then
    Clear
  else
    if not AGpImage.ImageData.Empty then
    begin
      FreeHandle;
      ImageData.Assign(AGpImage.ImageData);
      Changed(Self);
    end
    else
      if AGpImage.ImageDataFormat = dxImageBitmap then
      begin
        ABitmap := AGpImage.GetAsBitmap;
        try
          SetBitmap(ABitmap);
        finally
          ABitmap.Free;
        end;
      end
      else
      begin
        AStream := TMemoryStream.Create;
        try
          AGpImage.SaveToStream(AStream);
          AStream.Position := 0;
          LoadFromStream(AStream);
        finally
          AStream.Free;
        end;
      end;
end;

procedure TdxGPImage.AssignFromGraphic(AGraphic: TGraphic);
var
  ABitmap: TBitmap;
begin
  if AGraphic is TBitmap then
    SetBitmap(TBitmap(AGraphic))
  else
  begin
    ABitmap := TBitmap.Create;
    try
      ABitmap.PixelFormat := pf24bit;
    {$IFDEF DELPHI10}
      ABitmap.SetSize(AGraphic.Width, AGraphic.Height);
    {$ELSE}
      ABitmap.Width := AGraphic.Width;
      ABitmap.Height := AGraphic.Height;
    {$ENDIF}
      ABitmap.Canvas.Draw(0, 0, AGraphic);
      SetBitmap(ABitmap);
    finally
      ABitmap.Free;
    end;
  end;
end;

procedure TdxGPImage.AssignTo(ADest: TPersistent);
var
  ABitmap: TBitmap;
begin
  if ADest is TdxGPImage then
    ADest.Assign(Self)
  else
    if ADest is TBitmap then
    begin
      ABitmap := GetAsBitmap;
      try
        ADest.Assign(ABitmap);
      finally
        ABitmap.Free;
      end;
    end
    else
      inherited AssignTo(ADest);
end;

function TdxGPImage.CheckHasAlphaChannel(const ABits: TRGBColors): Boolean;

  function HasNonTransparentPixels: Boolean;
  var
    I: Integer;
  begin
    Result := False;
    for I := 0 to Length(ABits) - 1 do
    begin
      Result := ABits[I].rgbReserved > 0;
      if Result then
        Break;
    end;
  end;

  function CheckTransparentPixels: Boolean;
  var
    I: Integer;
  begin
    Result := False;
    for I := 0 to Length(ABits) - 1 do
    begin
      Result := ABits[I].rgbBlue + ABits[I].rgbGreen + ABits[I].rgbRed = 0;
      if not Result then
        Break;
    end;
  end;

begin
  Result := HasNonTransparentPixels or CheckTransparentPixels;
end;

procedure TdxGPImage.CreateHandleFromBitmap(ABitmap: TBitmap);
var
  AColors: TRGBColors;
begin
  if cxGetBitmapPixelFormat(ABitmap) < 32 then
    CreateHandleFromHBITMAP(ABitmap.Handle, ABitmap.Palette)
  else
    if dxCore.GetBitmapBits(ABitmap, AColors, True) then
      CreateHandleFromBits(ABitmap.Width, ABitmap.Height, AColors, CheckHasAlphaChannel(AColors));
end;

procedure TdxGPImage.CreateHandleFromBits(AWidth, AHeight: Integer;
  const ABits: TRGBColors; AHasAlphaChannel: Boolean);
begin
  FreeHandle;
  ImageData.LoadFromBits(ABits, cxSize(AWidth, AHeight), AHasAlphaChannel);
end;

procedure TdxGPImage.CreateHandleFromHBITMAP(ABitmap: HBITMAP; APalette: HPALETTE);
begin
  FreeHandle;
  GdipCheck(GdipCreateBitmapFromHBITMAP(ABitmap, APalette, FHandle));
  RecognizeImageRawDataFormat;
end;

procedure TdxGPImage.CreateHandleFromImageData;
var
  ABitmap: TBitmap;
  AStreamAdapter: IStream;
begin
  if not ImageData.Empty then
  begin
    if Length(ImageData.FBits) > 0 then
      GdipCheck(GdipCreateBitmapFromScan0(ImageData.FBitsBounds.cx,
        ImageData.FBitsBounds.cy, ImageData.FBitsBounds.cx * 4,
        PixelFormat32bppPARGB, @ImageData.FBits[0], FHandle))
    else
    begin
      ImageData.FData.Position := 0;
      if TdxGPImageDataHelper.IsBitmapStream(ImageData.FData) then
      begin
        ABitmap := TBitmap.Create;
        try
          ABitmap.LoadFromStream(ImageData.FData);
          ImageData.FreeImageData;
          CreateHandleFromBitmap(ABitmap);
        finally
          ABitmap.Free;
        end;
      end
      else
      begin
        AStreamAdapter := TdxGPStreamAdapter.Create(ImageData.FData, soReference);
        GdipCheck(GdipLoadImageFromStream(AStreamAdapter, FHandle));
        AStreamAdapter := nil;
      end;
    end;
    if (ImageData.FNewSize.cx > 0) and (ImageData.FNewSize.cy > 0) then
      Resize(ImageData.FNewSize);
  end;
  RecognizeImageRawDataFormat;
end;

procedure TdxGPImage.CreateHandleFromStream(AStream: TStream);
begin
  FreeHandle;
  ImageData.LoadFromStream(AStream);
end;

procedure TdxGPImage.ChangeColor(AColor: TColor);
var
  AColors: TRGBColors;
  R, G, B, A: Byte;
  I: Integer;
begin
  if (AColor <> clNone) and (AColor <> clDefault) and not Empty then
  begin
    AColor := ColorToRGB(AColor);
    R := GetRValue(AColor);
    G := GetGValue(AColor);
    B := GetBValue(AColor);
    AColors := GetBitmapBits;
    for I := 0 to Length(AColors) - 1 do
    begin
      A := AColors[I].rgbReserved;
      AColors[I].rgbBlue := MulDiv(B, A, MaxByte);
      AColors[I].rgbGreen := MulDiv(G, A, MaxByte);
      AColors[I].rgbRed := MulDiv(R, A, MaxByte);
    end;
    LoadFromBits(Width, Height, AColors, True);
  end;
end;

procedure TdxGPImage.Changed(Sender: TObject);
begin
  FIsAlphaUsedAssigned := False;
  inherited Changed(Sender);
end;

function TdxGPImage.CheckAlphaUsed: Boolean;
var
  AColors: TRGBColors;
  I: Integer;
begin
  AColors := nil;
  Result := False;
  if not Empty then
  begin
    AColors := GetBitmapBits;
    for I := Low(AColors) to High(AColors) do
    begin
      Result := AColors[I].rgbReserved <> 255;
      if Result then Break;
    end;
  end;
end;

function TdxGPImage.Clone: TdxGPImage;
begin
  Result := TdxGPImageClass(ClassType).Create;
  Result.AssignFromGpImage(Self);
end;

function TdxGPImage.Compare(AImage: TdxGPImage): Boolean;
var
  AColors: TRGBColors;
  AColors2: TRGBColors;
begin
  AColors := nil;
  AColors2 := nil;
  Result := (AImage.Height = Height) and (AImage.Width = Width);
  if Result and not (AImage.Empty or Empty) then
  begin
    AColors := GetBitmapBits;
    AColors2 := AImage.GetBitmapBits;
    Result := CompareMem(@AColors[0], @AColors2[0], SizeOf(AColors[0]) * Length(AColors));
  end;
end;

procedure TdxGPImage.ConvertToBitmap;
var
  AGraphics: GpGraphics;
  ANewHandle: GpImage;
begin
  if Handle <> nil then
  begin
    ANewHandle := dxGpCreateBitmap(Width, Height);
    GdipCheck(GdipGetImageGraphicsContext(ANewHandle, AGraphics));
    GdipCheck(GdipDrawImageRectI(AGraphics, Handle, 0, 0, Width, Height));
    Handle := ANewHandle;
  end;
end;

procedure TdxGPImage.Clear;
begin
  if HandleAllocated or not ImageData.Empty then
  begin
    FreeHandle;
    Changed(Self);
  end;
end;

procedure TdxGPImage.Draw(ACanvas: TCanvas; const ARect: TRect);
begin
  StretchDraw(ACanvas.Handle, ARect);
end;

procedure TdxGPImage.FreeHandle;
begin
  if HandleAllocated then
  begin
    GdipDisposeImage(FHandle);
    FImageDataFormat := dxImageUnknown;
    FHandle := nil;
  end;
  FImageData.FreeImageData;
end;

procedure TdxGPImage.LoadFromBits(AWidth, AHeight: Integer; const ABits: TRGBColors; AHasAlphaChannel: Boolean);
begin
  CreateHandleFromBits(AWidth, AHeight, ABits, AHasAlphaChannel);
  Changed(Self);
end;

procedure TdxGPImage.LoadFromClipboardFormat(AFormat: Word; AData: THandle; APalette: HPALETTE);
var
  ABitmap: TBitmap;
begin
  ABitmap := TBitmap.Create;
  try
    ABitmap.PixelFormat := pf32Bit;
    ABitmap.HandleType := bmDIB;
    ABitmap.LoadFromClipboardFormat(AFormat, AData, APalette);
    SetBitmap(ABitmap);
  finally
    ABitmap.Free;
  end;
end;

procedure TdxGPImage.LoadFromFieldValue(const AValue: Variant);
type
  TGraphicHeader = record
    Count: Word;
    HType: Word;
    Size: Longint;
  end;
var
  AHeader: TGraphicHeader;
  ASize: Longint;
  AStream: TMemoryStream;
  AValueAsString: AnsiString;
begin
  if not dxVarIsBlob(AValue) then Exit;
  AStream := TMemoryStream.Create;
  try
    AValueAsString := dxVariantToAnsiString(AValue);
    ASize := Length(AValueAsString);
    if ASize >= SizeOf(AHeader) then
    begin
      TMemoryStreamAccess(AStream).SetPointer(@AValueAsString[1], ASize);
      AStream.Position := 0;
      AStream.Read(AHeader, SizeOf(AHeader));
      if (AHeader.Count <> 1) or (AHeader.HType <> $0100) or
        (AHeader.Size <> ASize - SizeOf(AHeader)) then
        AStream.Position := 0;
    end;
    if AStream.Size > 0 then
      LoadFromStream(AStream);
  finally
    AStream.Free;
  end;
end;

procedure TdxGPImage.LoadFromResource(
  AInstance: THandle; const AResName: string; AResType: PChar);
var
  AStream: TStream;
begin
  AStream := TResourceStream.Create(AInstance, AResName, AResType);
  try
    LoadFromStream(AStream);
  finally
    AStream.Free;
  end;
end;

procedure TdxGPImage.LoadFromStream(AStream: TStream);
begin
  CreateHandleFromStream(AStream);
  Changed(Self);
end;

function TdxGPImage.MakeComposition(AOverlayImage: TdxGPImage; AOverlayAlpha: Byte): TdxGPImage;
begin
  Result := MakeComposition(AOverlayImage, AOverlayAlpha, 255);
end;

function TdxGPImage.MakeComposition(
  AOverlayImage: TdxGPImage; AOverlayAlpha, ASourceAlpha: Byte): TdxGPImage;
var
  AGraphics: GpGraphics;
begin
  Result := TdxGPImage.CreateSize(cxSize(Width, Height));
  if not Result.Empty then
  begin
    GdipCheck(GdipGetImageGraphicsContext(Result.Handle, AGraphics));
    try
      dxGPPaintCanvas.BeginPaint(AGraphics);
      try
        dxGPPaintCanvas.Draw(Self, Result.ClientRect, ASourceAlpha);
        dxGPPaintCanvas.Draw(AOverlayImage, Result.ClientRect, AOverlayImage.ClientRect, AOverlayAlpha);
      finally
        dxGPPaintCanvas.EndPaint;
      end;
    finally
      GdipCheck(GdipDeleteGraphics(AGraphics));
    end;
  end;
end;

procedure TdxGPImage.RecognizeImageRawDataFormat;
var
  AFormatID: TGUID;
begin
  if Handle <> nil then
  begin
    GdipCheck(GdipGetImageRawFormat(Handle, AFormatID));
    FImageDataFormat := dxGetImageDataFormat(AFormatID);
  end
  else
    FImageDataFormat := dxImageUnknown;
end;

procedure TdxGPImage.SetImageDataFormat(AValue: TdxImageDataFormat);
var
  AStream: TMemoryStream;
begin
  if AValue = ImageDataFormat then Exit;
  AStream := TMemoryStream.Create;
  try
    SaveToStreamByCodec(AStream, AValue);
    AStream.Position := 0;
    LoadFromStream(AStream);
  finally
    AStream.Free;
  end;
end;

procedure TdxGPImage.SaveToClipboardFormat(
  var AFormat: Word; var AData: THandle; var APalette: HPALETTE);
var
  ABitmap: TBitmap;
begin
  ABitmap := TBitmap.Create;
  try
    ABitmap.Width := Width;
    ABitmap.Height := Height;
    ABitmap.Canvas.Brush.Color := clWhite;
    ABitmap.Canvas.FillRect(ClientRect);
    Draw(ABitmap.Canvas, ClientRect);
    ABitmap.SaveToClipboardFormat(AFormat, AData, APalette);
  finally
    ABitmap.Free;
  end;
end;

procedure TdxGPImage.SaveToStream(AStream: TStream);
begin
  SaveToStreamByCodec(AStream, ImageDataFormat);
end;

procedure TdxGPImage.SaveToStreamByCodec(
  AStream: TStream; AImageFormat: TdxImageDataFormat);

  function CreateStream(AImageFormat: TdxImageDataFormat): TMemoryStream;
  var
    ACodec: TGUID;
  begin
    Result := TdxGPMemoryStream.Create;
    ACodec := dxGetImageEncoder(AImageFormat);
    GdipCheck(GdipSaveImageToStream(Handle, TdxGPStreamAdapter.Create(Result, soReference), @ACodec, nil));
    Result.Position := 0;
  end;

  procedure RecreateHandle(AStream: TStream; AFreeStream: Boolean = False);
  begin
    AStream.Position := 0;
    CreateHandleFromStream(AStream);
    if AFreeStream then
      AStream.Free;
  end;

var
  ATempStream: TMemoryStream;
begin
  if Handle <> nil then
  begin
    ATempStream := CreateStream(AImageFormat);
    try
      AStream.CopyFrom(ATempStream, ATempStream.Size);

      if AImageFormat <> ImageDataFormat then
        RecreateHandle(CreateStream(ImageDataFormat), True)
      else
        RecreateHandle(ATempStream);
    finally
      ATempStream.Free;
    end;
  end;
end;

procedure TdxGPImage.StretchDraw(DC: HDC; const ADest: TRect; AAlpha: Byte = 255);
begin
  StretchDraw(DC, ADest, ClientRect, AAlpha);
end;

procedure TdxGPImage.StretchDraw(DC: HDC; const ADest, ASource: TRect; AAlpha: Byte = 255);
begin
  if Handle <> nil then
  begin
    dxGPPaintCanvas.BeginPaint(DC, ADest);
    dxGPPaintCanvas.Draw(Self, ADest, ASource, AAlpha);
    dxGPPaintCanvas.EndPaint;
  end;
end;

function TdxGPImage.GetAsBitmap: TBitmap;
var
  ABitmapHandle: HBITMAP;
begin
  GdipCheck(GdipCreateHBITMAPFromBitmap(Handle, ABitmapHandle, 0));
  Result := TBitmap.Create;
  Result.PixelFormat := pf32Bit;
  Result.Handle := ABitmapHandle;
end;

function TdxGPImage.GetBitmapBits: TRGBColors;
var
  ABitmap: TBitmap;
begin
  ABitmap := GetAsBitmap;
  try
    dxCore.GetBitmapBits(ABitmap, Result, True);
  finally
    ABitmap.Free;
  end;
end;

function TdxGPImage.GetClientRect: TRect;
begin
  Result := cxRect(GetSize);
end;

function TdxGPImage.GetEmpty: Boolean;
begin
  Result := cxRectIsEmpty(ClientRect);
end;

function TdxGPImage.GetIsAlphaUsed: Boolean;
begin
  if not FIsAlphaUsedAssigned then
  begin
    FIsAlphaUsed := CheckAlphaUsed;
    FIsAlphaUsedAssigned := True;
  end;
  Result := FIsAlphaUsed
end;

function TdxGPImage.GetHandle: GpImage;
begin
  HandleNeeded;
  Result := FHandle;
end;

function TdxGPImage.GetHandleAllocated: Boolean;
begin
  Result := FHandle <> nil;
end;

function TdxGPImage.GetImageDataFormat: TdxImageDataFormat;
begin
  HandleNeeded;
  Result := FImageDataFormat;
end;

function TdxGPImage.GetHeight: Integer;
begin
  Result := GetSize.cy;
end;

function TdxGPImage.GetLoaded: Boolean;
begin
  Result := HandleAllocated or ImageData.Empty;
end;

function TdxGPImage.GetSize: TSize;
var
  W, H: Single;
begin
  if Handle <> nil then
    GdipCheck(GdipGetImageDimension(Handle, W, H))
  else
  begin
    W := 0;
    H := 0;
  end;
  Result.cx := Trunc(W);
  Result.cy := Trunc(H);
end;

function TdxGPImage.GetWidth: Integer;
begin
  Result := GetSize.cx;
end;

procedure TdxGPImage.HandleNeeded;
begin
  if not Loaded then
    CreateHandleFromImageData;
end;

function TdxGPImage.GetTransparent: Boolean;
begin
  Result := IsAlphaUsed;
end;

procedure TdxGPImage.Resize(const AWidth, AHeight: Integer);
var
  AGraphics: GpGraphics;
  AScaledImageHandle: GpBitmap;
  R: TRect;
begin
  FImageData.FNewSize := cxSize(AWidth, AHeight);
  if HandleAllocated then
  begin
    R := cxRect(FImageData.FNewSize);
    AScaledImageHandle := dxGpCreateBitmap(R);
    GdipCheck(GdipGetImageGraphicsContext(AScaledImageHandle, AGraphics));
    GdipCheck(GdipDrawImageRectI(AGraphics, Handle, R.Left, R.Top, R.Right, R.Bottom));
    GdipCheck(GdipDeleteGraphics(AGraphics));
    Handle := AScaledImageHandle;
  end;
end;

procedure TdxGPImage.Resize(const ASize: TSize);
begin
  Resize(ASize.cx, ASize.cy);
end;

procedure TdxGPImage.Scale(const M, D: Integer);
begin
  Resize(MulDiv(Width, M, D),  MulDiv(Height, M, D));
end;

procedure TdxGPImage.SetBitmap(ABitmap: TBitmap);
begin
  CreateHandleFromBitmap(ABitmap);
  Changed(Self);
end;

procedure TdxGPImage.SetWidth(Value: Integer);
begin
end;

procedure TdxGPImage.SetHandle(AValue: GPImage);
begin
  if AValue <> FHandle then
  begin
    FreeHandle;
    FHandle := AValue;
    RecognizeImageRawDataFormat;
    Changed(Self);
  end;
end;

procedure TdxGPImage.SetHeight(Value: Integer);
begin
end;

{ TdxGPImageData}

destructor TdxGPImageData.Destroy;
begin
  FreeImageData;
  inherited Destroy;
end;

procedure TdxGPImageData.Assign(AData: TdxGPImageData);
begin
  FreeImageData;
  if AData <> nil then
  begin
    FBits := AData.FBits;
    FBitsBounds := AData.FBitsBounds;
    FNewSize := AData.FNewSize;
    FData := dxCloneStream(AData.FData);
  end;
end;

procedure TdxGPImageData.FreeImageData;
begin
  FBits := nil;
  FBitsBounds := cxNullSize;
  FNewSize := cxNullSize;
  FreeAndNil(FData);
end;

procedure TdxGPImageData.LoadFromBits(const ABits: TRGBColors;
  const ASize: Size; AHasAlphaChannel: Boolean);
var
  I: Integer;
begin
  FreeImageData;
  FBits := ABits;
  FBitsBounds := ASize;
  if not AHasAlphaChannel then
  begin
    for I := 0 to Length(FBits) - 1 do
      FBits[I].rgbReserved := 255;
  end;
end;

procedure TdxGPImageData.LoadFromStream(AStream: TStream);
var
  ASize: Integer;
begin
  FreeImageData;
  ASize := AStream.Size - AStream.Position;
  if ASize > 0 then
  begin
    FData := TdxGPMemoryStream.Create;
    FData.Size := ASize;
    FData.CopyFrom(AStream, ASize);
    FData.Position := 0;
  end;
end;

function TdxGPImageData.GetIsEmpty: Boolean;
begin
  Result := (FData = nil) and (Length(FBits) = 0);
end;

{ TdxSmartImage }

procedure TdxSmartImage.ReadData(Stream: TStream);
begin
  LoadFromStream(Stream);
end;

procedure TdxSmartImage.WriteData(Stream: TStream);
begin
  SaveToStream(Stream);
end;

{ TdxPNGImage }

procedure TdxPNGImage.SaveToStream(AStream: TStream);
begin
  SaveToStreamByCodec(AStream, dxImagePng);
end;

{ TdxJPEGImage }

procedure TdxJPEGImage.SaveToStream(AStream: TStream);
begin
  SaveToStreamByCodec(AStream, dxImageJpeg);
end;

{ TdxGIFImage }

procedure TdxGIFImage.SaveToStream(AStream: TStream);
begin
  SaveToStreamByCodec(AStream, dxImageGif);
end;

{ TdxTIFFImage }

procedure TdxTIFFImage.SaveToStream(AStream: TStream);
begin
  SaveToStreamByCodec(AStream, dxImageTiff);
end;

{ TdxBMPImage }

procedure TdxBMPImage.SaveToStream(AStream: TStream);
begin
  SaveToStreamByCodec(AStream, dxImageBitmap);
end;

//

procedure RegisterAssistants;
begin
  @FWindowFromDC := GetProcAddress(GetModuleHandle(user32), 'WindowFromDC');
  if CheckGdiPlus then
  begin
    CheckImageCodecs;
    RegisterClasses([TdxPNGImage, TdxSmartImage]);
  {$IFDEF DXREGISTERPNGIMAGE}
    TPicture.RegisterFileFormat('PNG', 'PNG graphics from DevExpress', TdxPNGImage);
    TPicture.RegisterFileFormat('TIF;*.TIFF;*.GIF;*.BMP;*.JPG;*.JPEG', 'All graphics', TdxSmartImage);
  {$ELSE}
    TPicture.RegisterFileFormat('', '', TdxGPImage);
  {$ENDIF}
  end;                     
end;

procedure UnregisterAssistants;
begin
  FreeAndNil(GPAlphaBlendAttributes);
  FreeAndNil(GPPaintCanvas);
  TPicture.UnregisterGraphicClass(TdxSmartImage);
  TPicture.UnregisterGraphicClass(TdxPNGImage);
  UnregisterClasses([TdxPNGImage, TdxSmartImage]);
end;

initialization
  dxUnitsLoader.AddUnit(@RegisterAssistants, @UnregisterAssistants);

finalization
  dxUnitsLoader.RemoveUnit(@UnregisterAssistants);
end.
