unit acgpUtils;
{$I sDefs.inc}

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms,
  sConst;

procedure acgpDrawEllipse(DC: hdc; X, Y, Width, Height: Single; Color: TColor; PenWidth: Single = 1);
procedure acgpDrawLine(DC: hdc; X1, Y1, X2, Y2: Single; Color: TColor; PenWidth: Single = 1);
procedure acgpFillEllipse(DC: hdc; X, Y, Width, Height: Single; Color: TColor);
procedure acgpDrawArc(DC: hdc; X, Y, Width, Height, StartAngle, SweepAngle: Single; Color: TColor; PenWidth: Single = 1);
procedure acgpStretchRect(DstBmp, SrcBmp: TBitmap; SrcX, SrcY, SrcWidth, SrcHeight: integer);

implementation

uses
  Math,
  sSkinProvider, sAlphaGraph, acntTypes, acntUtils, sGraphUtils;

type
  TStatus = (Ok, GenericError, InvalidParameter, OutOfMemory, ObjectBusy, InsufficientBuffer, NotImplemented, Win32Error, WrongState,
    Aborted, FileNotFound, ValueOverflow, AccessDenied, UnknownImageFormat, FontFamilyNotFound, FontStyleNotFound, NotTrueTypeFont,
    UnsupportedGdiplusVersion, GdiplusNotInitialized, PropertyNotFound, PropertyNotSupported
  );

  TUnit = (UnitWorld, UnitDisplay, UnitPixel, UnitPoint, UnitInch, UnitDocument, UnitMillimeter);
  TDebugEventLevel = (DebugEventLevelFatal, DebugEventLevelWarning);

  TGpPen      = Pointer;
  TGpGraphics = Pointer;
  TGpBrush    = Pointer;
  TGpBitmap   = Pointer;
  TGpImage    = Pointer;

  PARGB = ^ARGB;
  ARGB  = DWORD;

  NotificationUnhookProc = procedure (token: ULONG); stdcall;
  DebugEventProc         = procedure (level: TDebugEventLevel; message: PChar); stdcall;
  NotificationHookProc   = function (out token: ULONG): TStatus; stdcall;

  TGdiplusStartupInput = record
    GdiplusVersion: Cardinal;
    DebugEventCallback: DebugEventProc;
    SuppressBackgroundThread: BOOL;
    SuppressExternalCodecs: BOOL;
  end;
  PGdiplusStartupInput = ^TGdiplusStartupInput;

  TGdiplusStartupOutput = record
    NotificationHook  : NotificationHookProc;
    NotificationUnhook: NotificationUnhookProc;
  end;
  PGdiplusStartupOutput = ^TGdiplusStartupOutput;

  ImageAbort = function: BOOL; stdcall;
  DrawImageAbort = ImageAbort;

  TCompositingMode = (
    CompositingModeSourceOver, // 0
    CompositingModeSourceCopy  // 1 - faster
  );

{$IFDEF DELPHI6UP}
  TQualityMode = (
    QualityModeInvalid = -1,
    QualityModeDefault = 0,
    QualityModeLow     = 1,
    QualityModeHigh    = 2
  );

  TSmoothingMode = (
    SmoothingModeInvalid     = -1,
    SmoothingModeDefault     = 0,
    SmoothingModeHighSpeed   = 1,
    SmoothingModeHighQuality = 2,
    SmoothingModeNone,
    SmoothingModeAntiAlias8x4,
    SmoothingModeAntiAlias = SmoothingModeAntiAlias8x4,
    SmoothingModeAntiAlias8x8
  );

  TCompositingQuality = (
    CompositingQualityInvalid          = ord(QualityModeInvalid),
    CompositingQualityDefault          = ord(QualityModeDefault),
    CompositingQualityHighSpeed        = ord(QualityModeLow),
    CompositingQualityHighQuality      = ord(QualityModeHigh),
    CompositingQualityGammaCorrected,
    CompositingQualityAssumeLinear
  );
{$ELSE}
  TQualityMode = Integer;
  TSmoothingMode = Integer;
  TCompositingQuality = Integer;

const
  QualityModeInvalid = -1;
  QualityModeDefault = 0;
  QualityModeLow     = 1;
  QualityModeHigh    = 2;

  SmoothingModeInvalid     = -1;
  SmoothingModeDefault     = 0;
  SmoothingModeHighSpeed   = 1;
  SmoothingModeHighQuality = 2;
  SmoothingModeNone        = 3;
  SmoothingModeAntiAlias   = 4;

  CompositingQualityInvalid          = QualityModeInvalid;
  CompositingQualityDefault          = QualityModeDefault;
  CompositingQualityHighSpeed        = QualityModeLow;
  CompositingQualityHighQuality      = QualityModeHigh;
  CompositingQualityGammaCorrected   = 3;
  CompositingQualityAssumeLinear     = 4;

{$ENDIF}

type

  PGPRect = ^TGPRect;
  TGPRect = record
    X     : Integer;
    Y     : Integer;
    Width : Integer;
    Height: Integer;
  end;

  TBitmapData = record
    Width       : UINT;
    Height      : UINT;
    Stride      : Integer;
    PixelFormat : integer;
    Scan0       : Pointer;
    Reserved    : {$IFDEF DELPHI7UP}NativeUInt{$ELSE}Cardinal{$ENDIF};
  end;
  PBitmapData = ^TBitmapData;

var
  acDefaultSmoothingMode: TSmoothingMode = SmoothingModeHighQuality;
  StartupInput: TGDIPlusStartupInput;

  acGdipCreateFromHDC:         function (hdc: HDC; out graphics: TGpGraphics): TStatus; stdcall;
  acGdipCreatePen1:            function (Color: ARGB; Width: Single; unit_: TUnit; out pen: TGpPen): TStatus; stdcall;
  acGdipCreateSolidFill:       function (color: ARGB; out brush: TGpBrush): TStatus; stdcall;
  acGdipSetSmoothingMode:      function (graphics: TGpGraphics; smoothingMode: TSmoothingMode): TStatus; stdcall;
  acGdipDrawEllipse:           function (graphics: TGpGraphics; pen: TGpPen; X, Y, Width, Height: Single): TStatus; stdcall;
  acGdipFillEllipse:           function (graphics: TGpGraphics; brush: TGpBrush; x, y, width, height: Single): TStatus; stdcall;
  acGdipDrawLine:              function (graphics: TGpGraphics; pen: TGpPen; x1, y1, x2, y2: Single): TStatus; stdcall;
  acGdipDrawArc:               function (graphics: TGpGraphics; pen: TGpPen; X, Y, Width, Height, StartAngle, SweepAngle: Single): TStatus; stdcall;
  acGdiplusStartup:            function (out token: ULONG; input: PGdiplusStartupInput; output: PGdiplusStartupOutput): TStatus; stdcall;
  acGdiplusShutdown:           procedure (token: ULONG); stdcall;
  acGdipDeleteGraphics:        function (graphics: TGpGraphics): TStatus; stdcall;
  acGdipSetCompositingQuality: function (graphics: TGpGraphics; compositingQuality: TCompositingQuality): TStatus; stdcall;
  acGdipSetCompositingMode:    function (graphics: TGpGraphics; compositingMode: TCompositingMode): TStatus; stdcall;
  acGdipDisposeImage:          function (Image: Pointer): TStatus; stdcall;
  acGdipBitmapLockBits:        function (bitmap: TGpBitmap; rect: PGPRect; flags: UINT; format: integer; lockedBitmapData: PBITMAPDATA): TStatus; stdcall;
  acGdipCreateBitmapFromScan0: function (width: Integer; height: Integer; stride: Integer; format: integer; scan0: PBYTE; out bitmap: TGpBitmap): TStatus; stdcall;
  acGdipBitmapUnlockBits:      function (bitmap: TGpBitmap; lockedBitmapData: PBITMAPDATA): TStatus; stdcall;
  acGdipDrawImageRectRect:     function (graphics: TGpGraphics; image: TGpImage;
                                         dstx: Single; dsty: Single; dstwidth: Single; dstheight: Single;
                                         srcx: Single; srcy: Single; srcwidth: Single; srcheight: Single;
                                         srcUnit: TUnit; imageAttributes: Pointer; callback: DRAWIMAGEABORT; callbackData: Pointer): TStatus; stdcall;


procedure acgpDrawEllipse(DC: hdc; X, Y, Width, Height: Single; Color: TColor; PenWidth: Single = 1);
var
  GpP: TGpPen;
  GpG: TGpGraphics;
begin
  if Assigned(acGdipDrawEllipse) and (acGdipCreateFromHDC(DC, GpG) = Ok) then
    try
      acGdipSetSmoothingMode(GpG, acDefaultSmoothingMode);
      if acGdipCreatePen1($FF000000 or Cardinal(SwapRedBlue(Color)), PenWidth, UnitWorld, GpP) = Ok then
        acGdipDrawEllipse(GpG, GpP, X, Y, Width, Height);
    finally
      acGdipDeleteGraphics(GpG);
    end;
end;


procedure acgpDrawLine(DC: hdc; X1, Y1, X2, Y2: Single; Color: TColor; PenWidth: Single = 1);
var
  GpP: TGpPen;
  GpG: TGpGraphics;
begin
  if Assigned(acGdipDrawLine) and (acGdipCreateFromHDC(DC, GpG) = Ok) then
    try
      acGdipSetSmoothingMode(GpG, acDefaultSmoothingMode);
      if acGdipCreatePen1($FF000000 or Cardinal(SwapRedBlue(Color)), PenWidth, UnitWorld, GpP) = Ok then
        acGdipDrawLine(GpG, GpP, X1, Y1, X2, Y2);
    finally
      acGdipDeleteGraphics(GpG);
    end;
end;


procedure acgpFillEllipse(DC: hdc; X, Y, Width, Height: Single; Color: TColor);
var
  GpB: TGpBrush;
  GpG: TGpGraphics;
begin
  if Assigned(acGdipFillEllipse) and (acGdipCreateFromHDC(DC, GpG) = Ok) then
    try
      acGdipSetSmoothingMode(GpG, acDefaultSmoothingMode);
      if acGdipCreateSolidFill($FF000000 or Cardinal(SwapRedBlue(Color)), GpB) = Ok then
        acGdipFillEllipse(GpG, GpB, X, Y, Width, Height);
    finally
      acGdipDeleteGraphics(GpG);
    end;
end;


procedure acgpDrawArc(DC: hdc; X, Y, Width, Height, StartAngle, SweepAngle: Single; Color: TColor; PenWidth: Single = 1);
var
  GpP: TGpPen;
  GpG: TGpGraphics;
begin
  if Assigned(acGdipDrawEllipse) and (acGdipCreateFromHDC(DC, GpG) = Ok) then
    try
      acGdipSetSmoothingMode(GpG, acDefaultSmoothingMode);
      if acGdipCreatePen1($FF000000 or Cardinal(SwapRedBlue(Color)), PenWidth, UnitWorld, GpP) = Ok then
        acGdipDrawArc(GpG, GpP, X, Y, Width, Height, StartAngle, SweepAngle);
    finally
      acGdipDeleteGraphics(GpG);
    end;
end;


procedure acgpStretchRect(DstBmp, SrcBmp: TBitmap; SrcX, SrcY, SrcWidth, SrcHeight: integer);
const
  PixelFormat32bppARGB = 2498570;
type
  PGPColorRec = ^TsColor_;
var
  GpG: TGpGraphics;
  bitmap: TGpBitmap;
  S0, S: PRGBAArray_;
  bmData: TBitmapData;
  Delta, X, Y: integer;
  gpaPColor: PGPColorRec;
begin
  if acGdipCreateFromHDC(DstBmp.Canvas.Handle, GpG) = Ok then begin
    if acGdipCreateBitmapFromScan0(SrcBmp.Width, SrcBmp.Height, SrcBmp.Width * 4, PixelFormat32bppARGB, nil, bitmap) = OK then begin
      if InitLine(SrcBmp, Pointer(S0), Delta) then begin
        acGdipBitmapLockBits(bitmap, nil, 3{ImageLockModeRead or ImageLockModeWrite}, PixelFormat32bppARGB, @bmData);
        for Y := 0 to SrcBmp.Height - 1 do begin
          S := Pointer(LongInt(S0) + Delta * Y);
          gpaPColor := Pointer(Integer(bmData.Scan0) + Y * bmData.Stride);
          for X := 0 to SrcBmp.Width - 1 do begin
            gpaPColor.C := S[X].C;
            gpaPColor.A := 127 + S[X].A shr 1;
            inc(gpaPColor);
          end;
        end;
        acGdipBitmapUnlockBits(bitmap, @bmData);
      end;
      acGdipSetCompositingMode(GpG, CompositingModeSourceCopy);
      acGdipSetCompositingQuality(GpG, CompositingQualityHighSpeed);
      acGdipDrawImageRectRect(GpG, bitmap, 0, 0, DstBmp.Width{ - 1}, DstBmp.Height{ - 1}, SrcX, SrcY, SrcWidth, SrcHeight, UnitPixel, nil, nil, nil);
      acGdipDisposeImage(bitmap);
    end;
    acGdipDeleteGraphics(GpG);
    if InitLine(DstBmp, Pointer(S0), Delta) then
      for Y := 0 to DstBmp.Height - 1 do begin
        S := Pointer(LongInt(S0) + Delta * Y);
        for X := 0 to DstBmp.Width - 1 do
          with S[X] do
            if A <> 0 then begin
              R := min(MaxByte, R shl 8 div A);
              G := min(MaxByte, G shl 8 div A);
              B := min(MaxByte, B shl 8 div A);
              A := min(MaxByte, A shl 1 + 1 - MaxByte);
            end;
      end;
  end;
end;


var
  hGP: HMODULE = 0;
  gdiplusToken: ULONG;


initialization
  if hGP = 0 then
    hGP := LoadLibrary('gdiplus.dll');

  if (hGP <> 0) and not Assigned(acGdipCreateFromHDC) then begin
    acGdipDrawArc                 := GetProcAddress(hGP, 'GdipDrawArc');
    acGdipDrawLine                := GetProcAddress(hGP, 'GdipDrawLine');
    acGdipCreatePen1              := GetProcAddress(hGP, 'GdipCreatePen1');
    acGdiplusStartup              := GetProcAddress(hGP, 'GdiplusStartup');
    acGdiplusShutdown             := GetProcAddress(hGP, 'GdiplusShutdown');
    acGdipDrawEllipse             := GetProcAddress(hGP, 'GdipDrawEllipse');
    acGdipFillEllipse             := GetProcAddress(hGP, 'GdipFillEllipse');
    acGdipCreateFromHDC           := GetProcAddress(hGP, 'GdipCreateFromHDC');
    acGdipCreateSolidFill         := GetProcAddress(hGP, 'GdipCreateSolidFill');
    acGdipSetSmoothingMode        := GetProcAddress(hGP, 'GdipSetSmoothingMode');
    acGdipDrawImageRectRect       := GetProcAddress(hGP, 'GdipDrawImageRectRect');
    acGdipSetCompositingMode      := GetProcAddress(hGP, 'GdipSetCompositingMode');
    acGdipSetCompositingQuality   := GetProcAddress(hGP, 'GdipSetCompositingQuality');
    acGdipDeleteGraphics          := GetProcAddress(hGP, 'GdipDeleteGraphics');
    acGdipDisposeImage            := GetProcAddress(hGP, 'GdipDisposeImage');
    acGdipBitmapLockBits          := GetProcAddress(hGP, 'GdipBitmapLockBits');
    acGdipCreateBitmapFromScan0   := GetProcAddress(hGP, 'GdipCreateBitmapFromScan0');
    acGdipBitmapUnlockBits        := GetProcAddress(hGP, 'GdipBitmapUnlockBits');

    if Assigned(acGdiplusStartup) then begin
      StartupInput.DebugEventCallback := nil;
      StartupInput.SuppressBackgroundThread := False;
      StartupInput.SuppressExternalCodecs := False;
      StartupInput.GdiplusVersion := 1;
      acGdiplusStartup(gdiplusToken, @StartupInput, nil);
    end;
  end;


finalization
  if hGP <> 0 then begin
    acGdiplusShutdown(gdiplusToken);
    FreeLibrary(hGP);
  end;

end.
