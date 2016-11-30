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

implementation

uses
  Math,
  sSkinProvider, sAlphaGraph, acntTypes;

type
  TStatus = (Ok, GenericError, InvalidParameter, OutOfMemory, ObjectBusy, InsufficientBuffer, NotImplemented, Win32Error, WrongState,
    Aborted, FileNotFound, ValueOverflow, AccessDenied, UnknownImageFormat, FontFamilyNotFound, FontStyleNotFound, NotTrueTypeFont,
    UnsupportedGdiplusVersion, GdiplusNotInitialized, PropertyNotFound, PropertyNotSupported
  );

  TUnit = (UnitWorld, UnitDisplay, UnitPixel, UnitPoint, UnitInch, UnitDocument, UnitMillimeter);
  TDebugEventLevel = (DebugEventLevelFatal, DebugEventLevelWarning);

  TGpPen = Pointer;
  TGpGraphics = Pointer;
  TGpBrush = Pointer;

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
{$ELSE}
  TQualityMode = Integer;
  TSmoothingMode = Integer;

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
{$ENDIF}

var
  acDefaultSmoothingMode: TSmoothingMode = SmoothingModeHighQuality;
  StartupInput: TGDIPlusStartupInput;

  acGdipCreateFromHDC:    function (hdc: HDC; out graphics: TGpGraphics): TStatus; stdcall;
  acGdipCreatePen1:       function (Color: ARGB; Width: Single; unit_: TUnit; out pen: TGpPen): TStatus; stdcall;
  acGdipCreateSolidFill:  function (color: ARGB; out brush: TGpBrush): TStatus; stdcall;
  acGdipSetSmoothingMode: function (graphics: TGpGraphics; smoothingMode: TSmoothingMode): TStatus; stdcall;
  acGdipDrawEllipse:      function (graphics: TGpGraphics; pen: TGpPen; X, Y, Width, Height: Single): TStatus; stdcall;
  acGdipFillEllipse:      function (graphics: TGpGraphics; brush: TGpBrush; x, y, width, height: Single): TStatus; stdcall;
  acGdipDrawLine:         function (graphics: TGpGraphics; pen: TGpPen; x1, y1, x2, y2: Single): TStatus; stdcall;
  acGdipDrawArc:          function (graphics: TGpGraphics; pen: TGpPen; X, Y, Width, Height, StartAngle, SweepAngle: Single): TStatus; stdcall;
  acGdiplusStartup:       function (out token: ULONG; input: PGdiplusStartupInput; output: PGdiplusStartupOutput): TStatus; stdcall;
  acGdiplusShutdown:      procedure (token: ULONG); stdcall;


procedure acgpDrawEllipse(DC: hdc; X, Y, Width, Height: Single; Color: TColor; PenWidth: Single = 1);
var
  GpP: TGpPen;
  GpG: TGpGraphics;
begin
  if Assigned(acGdipDrawEllipse) and (acGdipCreateFromHDC(DC, GpG) = Ok) then begin
    acGdipSetSmoothingMode(GpG, acDefaultSmoothingMode);
    if acGdipCreatePen1($FF000000 or Cardinal(SwapRedBlue(Color)), PenWidth, UnitWorld, GpP) = Ok then
      acGdipDrawEllipse(GpG, GpP, X, Y, Width, Height);
  end;
end;


procedure acgpDrawLine(DC: hdc; X1, Y1, X2, Y2: Single; Color: TColor; PenWidth: Single = 1);
var
  GpP: TGpPen;
  GpG: TGpGraphics;
begin
  if Assigned(acGdipDrawLine) and (acGdipCreateFromHDC(DC, GpG) = Ok) then begin
    acGdipSetSmoothingMode(GpG, acDefaultSmoothingMode);
    if acGdipCreatePen1($FF000000 or Cardinal(SwapRedBlue(Color)), PenWidth, UnitWorld, GpP) = Ok then
      acGdipDrawLine(GpG, GpP, X1, Y1, X2, Y2);
  end;
end;


procedure acgpFillEllipse(DC: hdc; X, Y, Width, Height: Single; Color: TColor);
var
  GpB: TGpBrush;
  GpG: TGpGraphics;
begin
  if Assigned(acGdipFillEllipse) and (acGdipCreateFromHDC(DC, GpG) = Ok) then begin
    acGdipSetSmoothingMode(GpG, acDefaultSmoothingMode);
    if acGdipCreateSolidFill($FF000000 or Cardinal(SwapRedBlue(Color)), GpB) = Ok then
      acGdipFillEllipse(GpG, GpB, X, Y, Width, Height);
  end;
end;


procedure acgpDrawArc(DC: hdc; X, Y, Width, Height, StartAngle, SweepAngle: Single; Color: TColor; PenWidth: Single = 1);
var
  GpP: TGpPen;
  GpG: TGpGraphics;
begin
  if Assigned(acGdipDrawEllipse) and (acGdipCreateFromHDC(DC, GpG) = Ok) then begin
    acGdipSetSmoothingMode(GpG, acDefaultSmoothingMode);
    if acGdipCreatePen1($FF000000 or Cardinal(SwapRedBlue(Color)), PenWidth, UnitWorld, GpP) = Ok then
      acGdipDrawArc(GpG, GpP, X, Y, Width, Height, StartAngle, SweepAngle);
  end;
end;


var
  hGP: HMODULE = 0;
  gdiplusToken: ULONG;


initialization
  if hGP = 0 then
    hGP := LoadLibrary('gdiplus.dll');

  if (hGP <> 0) and not Assigned(acGdipCreateFromHDC) then begin
    acGdipDrawArc          := GetProcAddress(hGP, 'GdipDrawArc');
    acGdipDrawLine         := GetProcAddress(hGP, 'GdipDrawLine');
    acGdipCreatePen1       := GetProcAddress(hGP, 'GdipCreatePen1');
    acGdiplusStartup       := GetProcAddress(hGP, 'GdiplusStartup');
    acGdiplusShutdown      := GetProcAddress(hGP, 'GdiplusShutdown');
    acGdipDrawEllipse      := GetProcAddress(hGP, 'GdipDrawEllipse');
    acGdipFillEllipse      := GetProcAddress(hGP, 'GdipFillEllipse');
    acGdipCreateFromHDC    := GetProcAddress(hGP, 'GdipCreateFromHDC');
    acGdipCreateSolidFill  := GetProcAddress(hGP, 'GdipCreateSolidFill');
    acGdipSetSmoothingMode := GetProcAddress(hGP, 'GdipSetSmoothingMode');
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
