{********************************************************************}
{                                                                    }
{           Developer Express Visual Component Library               }
{           Express Cross Platform Library controls                  }
{                                                                    }
{           Copyright (c) 2000-2014 Developer Express Inc.           }
{           ALL RIGHTS RESERVED                                      }
{                                                                    }
{   The entire contents of this file is protected by U.S. and        }
{   International Copyright Laws. Unauthorized reproduction,         }
{   reverse-engineering, and distribution of all or any portion of   }
{   the code contained in this file is strictly prohibited and may   }
{   result in severe civil and criminal penalties and will be        }
{   prosecuted to the maximum extent possible under the law.         }
{                                                                    }
{   RESTRICTIONS                                                     }
{                                                                    }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES            }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE     }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS    }
{   LICENSED TO DISTRIBUTE THE EXPRESSCROSSPLATFORMLIBRARY AND ALL   }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM       }
{   ONLY.                                                            }
{                                                                    }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED       }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE         }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE        }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT   }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                       }
{                                                                    }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON        }
{   ADDITIONAL RESTRICTIONS.                                         }
{                                                                    }
{********************************************************************}

{$A8}

unit dxTouch;

{$I cxVer.inc}

interface
  uses
    Windows, Messages, Types, Forms, Controls, Graphics, Dialogs, Classes, Themes, RTLConsts,
    dxCore, cxGeometry, dxUxTheme;

const
{$IFNDEF DELPHI14}
  WM_GESTURE = $0119;
 {$EXTERNALSYM WM_GESTURE}
  WM_GESTURENOTIFY = $011A;
 {$EXTERNALSYM WM_GESTURENOTIFY}
  WM_TABLET_QUERYSYSTEMGESTURESTATUS = $02CC;
 {$EXTERNALSYM WM_TABLET_QUERYSYSTEMGESTURESTATUS}

  GF_BEGIN = $00000001;
  {$EXTERNALSYM GF_BEGIN}
  GF_INERTIA = $00000002;
  {$EXTERNALSYM GF_INERTIA}
  GF_END = $00000004;
  {$EXTERNALSYM GF_END}

  GID_BEGIN = 1;
  {$EXTERNALSYM GID_BEGIN}
  GID_END = 2;
  {$EXTERNALSYM GID_END}
  GID_ZOOM = 3;
  {$EXTERNALSYM GID_ZOOM}
  GID_PAN = 4;
  {$EXTERNALSYM GID_PAN}
  GID_ROTATE = 5;
  {$EXTERNALSYM GID_ROTATE}
  GID_TWOFINGERTAP = 6;
  {$EXTERNALSYM GID_TWOFINGERTAP}
  GID_PRESSANDTAP = 7;
  {$EXTERNALSYM GID_PRESSANDTAP}
  GID_ROLLOVER = GID_PRESSANDTAP;
  {$EXTERNALSYM GID_ROLLOVER}

  GC_ALLGESTURES = $00000001;
  {$EXTERNALSYM GC_ALLGESTURES}

  GC_ZOOM = $00000001;
  {$EXTERNALSYM GC_ZOOM}

  GC_PAN = $00000001;
  {$EXTERNALSYM GC_PAN}
  GC_PAN_WITH_SINGLE_FINGER_VERTICALLY = $00000002;
  {$EXTERNALSYM GC_PAN_WITH_SINGLE_FINGER_VERTICALLY}
  GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY = $00000004;
  {$EXTERNALSYM GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY}
  GC_PAN_WITH_GUTTER = $00000008;
  {$EXTERNALSYM GC_PAN_WITH_GUTTER}
  GC_PAN_WITH_INERTIA = $00000010;
  {$EXTERNALSYM GC_PAN_WITH_INERTIA}

  GC_ROTATE = $00000001;
  {$EXTERNALSYM GC_ROTATE}

  GC_TWOFINGERTAP = $00000001;
  {$EXTERNALSYM GC_TWOFINGERTAP}

  GC_PRESSANDTAP = $00000001;
  {$EXTERNALSYM GC_PRESSANDTAP}
  GC_ROLLOVER = GC_PRESSANDTAP;
  {$EXTERNALSYM GC_ROLLOVER}

  GESTURECONFIGMAXCOUNT = 256;
  {$EXTERNALSYM GESTURECONFIGMAXCOUNT}

  TABLET_DISABLE_PRESSANDHOLD = $00000001;
  {$EXTERNALSYM TABLET_DISABLE_PRESSANDHOLD}
  TABLET_DISABLE_PENTAPFEEDBACK = $00000008;
  {$EXTERNALSYM TABLET_DISABLE_PENTAPFEEDBACK}
  TABLET_DISABLE_PENBARRELFEEDBACK = $00000010;
  {$EXTERNALSYM TABLET_DISABLE_PENBARRELFEEDBACK}
  TABLET_DISABLE_TOUCHUIFORCEON = $00000100;
  {$EXTERNALSYM TABLET_DISABLE_TOUCHUIFORCEON}
  TABLET_DISABLE_TOUCHUIFORCEOFF = $00000200;
  {$EXTERNALSYM TABLET_DISABLE_TOUCHUIFORCEOFF}
  TABLET_DISABLE_TOUCHSWITCH = $00008000;
  {$EXTERNALSYM TABLET_DISABLE_TOUCHSWITCH}
  TABLET_DISABLE_FLICKS = $00010000;
  {$EXTERNALSYM TABLET_DISABLE_FLICKS}
  TABLET_ENABLE_FLICKSONCONTEXT = $00020000;
  {$EXTERNALSYM TABLET_ENABLE_FLICKSONCONTEXT}
  TABLET_ENABLE_FLICKLEARNINGMODE = $00040000; 
  {$EXTERNALSYM TABLET_ENABLE_FLICKLEARNINGMODE}
  TABLET_DISABLE_SMOOTHSCROLLING = $00080000; 
  {$EXTERNALSYM TABLET_DISABLE_SMOOTHSCROLLING}
  TABLET_DISABLE_FLICKFALLBACKKEYS = $00100000; 
  {$EXTERNALSYM TABLET_DISABLE_FLICKFALLBACKKEYS}
{$ELSE}
  dxTouchInteractiveGestureToGestureID: array [TInteractiveGesture] of Integer = (
    GID_ZOOM, GID_PAN, GID_ROTATE, GID_TWOFINGERTAP, GID_PRESSANDTAP);
  dxTouchInteractiveGestureOptionToPanOption: array [igoPanSingleFingerHorizontal..igoPanGutter] of Integer = (
    GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY, GC_PAN_WITH_SINGLE_FINGER_VERTICALLY, GC_PAN_WITH_INERTIA, GC_PAN_WITH_GUTTER);
{$ENDIF}
  dxTouchPanOptions = GC_PAN or GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY or
    GC_PAN_WITH_SINGLE_FINGER_VERTICALLY or GC_PAN_WITH_INERTIA or GC_PAN_WITH_GUTTER;
  dxSupportedGestureCount = 5;
  dxSupportedGestureOptions: array [0..dxSupportedGestureCount-1] of Integer = (
    dxTouchPanOptions, GC_ZOOM, GC_ROTATE, GC_TWOFINGERTAP, GC_PRESSANDTAP);
  dxSupportedGestureIDs: array [0..dxSupportedGestureCount-1] of Integer = (GID_PAN, GID_ZOOM, GID_ROTATE,
    GID_TWOFINGERTAP, GID_PRESSANDTAP);

type
  TdxGestureInfo = record
    cbSize: UINT;
    dwFlags: DWORD;
    dwID: DWORD;
    hwndTarget: HWND;
    ptsLocation: TSmallPoint;
    dwInstanceID: DWORD;
    dwSequenceID: DWORD;
    ullArguments: UInt64;
    cbExtraArgs: UINT;
  end;

  TdxGestureNotifyStruct = record
    cbSize: UINT;
    dwFlags: DWORD;
    hwndTarget: HWND;
    ptsLocation: TSmallPoint;
    dwInstanceID: DWORD;
  end;
  PdxGestureNotifyStruct = ^TdxGestureNotifyStruct;

  TWMGestureNotify = record
    Msg: TdxNativeUInt;
    Unused: WPARAM;
    NotifyStruct: PdxGestureNotifyStruct;
    Result: LRESULT;
  end;

  TdxGestureConfig = record
    dwID: DWORD;
    dwWant: DWORD;
    dwBlock: DWORD;
  end;
  
  TdxGestureConfigs = array of TdxGestureConfig;

  IdxGestureClient = interface
  ['{652B8A09-DAC8-4332-9206-C8905AEE7791}']
    function AllowGesture(AGestureId: Integer): Boolean;
    function AllowPan(AScrollKind: TScrollBarKind): Boolean;
    procedure BeginGestureScroll(APos: TPoint);
    procedure EndGestureScroll;
    procedure GestureScroll(ADeltaX, ADeltaY: Integer);
    function GetPanOptions: Integer;
    function IsPanArea(const APoint: TPoint): Boolean;
    function NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean;
  end;

  IdxGestureOwner = interface
    ['{4DF001DA-BE2C-4817-B75C-55171270D158}']
    function GetGestureClient(const APoint: TPoint): IdxGestureClient;
    function GetHandle: THandle;
    function IsGestureTarget(AWnd: THandle): Boolean;
    function ScreenToClient(const APoint: TPoint): TPoint;
  end;

  IdxZoomClient = interface
    ['{B3A0623E-D155-462F-B234-22E9CFC6BFBF}']
    procedure Zoom(ADelta: Integer; var AHandled: Boolean);
  end;

  IdxRotateClient = interface
    ['{EAC9BA3A-C2C3-42E2-8CA8-8CEA85821CAE}']
    procedure Rotate(AAngle: Double; var AHandled: Boolean);
  end;

  TdxGestureHelper = class
  private
    FIsInertia: Boolean;
    FGestureClient: IdxGestureClient;
    FGestureNotifyClient: IdxGestureClient;
    FGestureOwner: IdxGestureOwner;
    FIsPanning: Boolean;
    FLastDistance: Integer;
    FPanPoint: TPoint;
    FOverPan: TPoint;
  {$IFDEF DELPHI14}
    FNotifyTouchControl: TControl;
    FTouchControl: TControl;
  {$ENDIF}
    procedure DoOverpan(AScrollKind: TScrollBarKind; ADelta: Integer);
    function GetTouchStartPoint: TPoint;
    function Pan(APos: TPoint; AIsBegin, AIsEnd, AIsInertia: Boolean): Boolean;
    function Rotate(AAngle: Double; AIsBegin, AIsEnd: Boolean): Boolean;
    function Zoom(ADistance: Integer; AIsBegin, AIsEnd: Boolean): Boolean;
  protected
    function AllowGesture(AGestureId: Integer): Boolean; virtual;
    function AllowPan(AScrollKind: TScrollBarKind): Boolean; virtual;
    procedure BeginGestureScroll(const APos: TPoint);
    function Gesture(var Message: TMessage): Boolean;
    function GestureNotify(var Message: TWMGestureNotify): Boolean;
    procedure EndGestureScroll;
    procedure GestureScroll(ADeltaX, ADeltaY: Integer);
    function GetAllowedPanOptions(const APoint: TPoint): Integer;
    function GetHandle: THandle; virtual;
    function GetPanOptions: Integer; virtual;
    function IsGestureTarget(AWnd: THandle): Boolean; virtual;
    function IsPanArea(const APoint: TPoint): Boolean; virtual;
    function NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean; virtual;
    function ScreenToClient(const APoint: TPoint): TPoint; virtual;

    property Handle: THandle read GetHandle;
  public
    constructor Create(AGestureOwner: IdxGestureOwner);
    destructor Destroy; override;
    procedure CheckOverpan(AScrollKind: TScrollBarKind;
      ANewDataPos, AMinDataPos, AMaxDataPos: Integer; ADeltaX, ADeltaY: Integer);
  {$IFDEF DELPHI14}
    procedure CheckGestureOptions(var Gestures: TInteractiveGestures;
      var Options: TInteractiveGestureOptions);
    procedure DoGesture(const EventInfo: TGestureEventInfo; var Handled: Boolean);
  {$ENDIF}
    function HandleMessage(var Message: TMessage): Boolean;

    property IsPanning: Boolean read FIsPanning;
  end;

  function dxGetGestureInfo(hGestureInfo: THandle; var AGestureInfo: TdxGestureInfo): Boolean;
  function dxCloseGestureInfoHandle(hGestureInfo: THandle): Boolean;
  function dxSetGestureConfig(AWindow: THandle; const AGestureConfigs: TdxGestureConfigs): Boolean;
  function dxLogicalToPhysicalPoint(AWindow: THandle; var APoint: TPoint): Boolean;
  function dxPhysicalToLogicalPoint(AWindow: THandle; var APoint: TPoint): Boolean;
  function dxLockGestures(AHandle: THandle; var Message: TWMGestureNotify): Boolean;
  function dxIsTouchEvent(Shift: TShiftState): Boolean;
{$IFDEF DELPHI14}
  function GetInteractiveGestureByGestureID(AGestureID: Integer): TInteractiveGesture;
  function GetInteractiveGestureOptionByPanOptionID(APanOptionID: Integer): TInteractiveGestureOption;
  function GetInteractiveGestureOptionsByPanOptions(APanOptions: Integer): TInteractiveGestureOptions;
  function GetPanOptionsByInteractiveGestureOptions(AGestureOptions: TInteractiveGestureOptions): Integer;
{$ENDIF}
implementation

uses
  Math, SysUtils, Registry, dxHooks, cxGraphics, dxCoreClasses;

var
  FUser32Lib: HMODULE;
  FGetGestureInfo: function (hGestureInfo: TdxNativeUInt;
    var pGestureInfo: TdxGestureInfo): BOOL; stdcall;
  FCloseGestureInfoHandle: function (hGestureInfo: TdxNativeUInt): BOOL; stdcall;
  FSetGestureConfig: function (hwnd: HWND; dwReserved: DWORD; cIDs: UINT;
    const pGestureConfig: TdxGestureConfigs; cbSize: UINT): BOOL; stdcall;
  FLogicalToPhysicalPoint: function (hWnd: HWND; var lpPoint: TPoint): BOOL; stdcall;
  FPhysicalToLogicalPoint: function (hWnd: HWND; var lpPoint: TPoint): BOOL; stdcall;
  FIsProcessDPIAware: function: BOOL; stdcall;
  FDesktopCurrentDPI: Integer;
  FGestureStartPoint: TPoint;
  FNeedScalePanning: Boolean;
  FTouchHelpers: TdxFastObjectList;

{$IFDEF DELPHI14}
procedure InitializeTouchHelpers;
var
  I: Integer;
begin
  for I := 0 to FTouchHelpers.Count - 1 do
    (FTouchHelpers[I] as TdxGestureHelper).FNotifyTouchControl := nil;
end;
{$ENDIF}

procedure dxTouchWndProcHook(ACode: Integer; wParam: WPARAM; lParam: LPARAM; var AHookResult: LRESULT);
begin
  if ACode <> HC_ACTION then
    Exit;
  if Windows.PCWPStruct(LParam)^.message = WM_GESTURENOTIFY then
  begin
    FGestureStartPoint := SmallPointToPoint(PdxGestureNotifyStruct(Windows.PCWPStruct(LParam)^.lParam)^.ptsLocation);
  {$IFDEF DELPHI14}
    InitializeTouchHelpers;
  {$ENDIF}
  end;
end;

function dxIsTouchEvent(Shift: TShiftState): Boolean;
{$IFNDEF DELPHI14}
  const
    MouseOriginMask  = $FFFFFF80;
    MouseOriginTouch = $FF515780;
{$ENDIF}
begin
  {$IFDEF DELPHI14}
    Result := [ssTouch, ssPen] * Shift <> [];
  {$ELSE}
    Result := GetMessageExtraInfo and MouseOriginMask = MouseOriginTouch;
  {$ENDIF}
end;

{$IFDEF DELPHI14}
function GetInteractiveGestureByGestureID(AGestureID: Integer): TInteractiveGesture;
begin
  Result := igPressAndTap;
  case AGestureID of
    GID_ZOOM: Result := igZoom;
    GID_PAN: Result := igPan;
    GID_ROTATE: Result := igRotate;
    GID_TWOFINGERTAP: Result := igTwoFingerTap;
    GID_PRESSANDTAP: Result := igPressAndTap;
  end;
end;

function GetInteractiveGestureOptionByPanOptionID(APanOptionID: Integer): TInteractiveGestureOption;
begin
  Result := igoPanInertia;
  case APanOptionID of
    GC_PAN_WITH_SINGLE_FINGER_VERTICALLY: Result := igoPanSingleFingerVertical;
    GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY: Result := igoPanSingleFingerHorizontal;
    GC_PAN_WITH_GUTTER: Result := igoPanGutter;
    GC_PAN_WITH_INERTIA: Result := igoPanInertia;
  end;
end;

function GetInteractiveGestureOptionsByPanOptions(APanOptions: Integer): TInteractiveGestureOptions;
const
  APanOptionIDCount = 4;
  APanOptionIDs: array [0..APanOptionIDCount-1] of Integer = (GC_PAN_WITH_SINGLE_FINGER_VERTICALLY,
    GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY, GC_PAN_WITH_GUTTER, GC_PAN_WITH_INERTIA);
var
  I: Integer;
begin
  Result := [];
  for I := 0 to APanOptionIDCount - 1 do
    if (APanOptionIDs[I] and APanOptions) <> 0 then
      Include(Result, GetInteractiveGestureOptionByPanOptionID(APanOptionIDs[I]));
end;

function GetPanOptionsByInteractiveGestureOptions(AGestureOptions: TInteractiveGestureOptions): Integer;
var
  I: TInteractiveGestureOption;
begin
  Result := 0;
  for I := igoPanSingleFingerHorizontal to igoPanGutter do
    if I in AGestureOptions then
      Result := Result or dxTouchInteractiveGestureOptionToPanOption[I];
end;
{$ENDIF}

function dxGetGestureInfo(hGestureInfo: THandle;
    var AGestureInfo: TdxGestureInfo): Boolean;
begin
  if Assigned(FGetGestureInfo) then
    Result := FGetGestureInfo(hGestureInfo, AGestureInfo)
  else
    Result := False;
end;

function dxCloseGestureInfoHandle(hGestureInfo: THandle): Boolean;
begin
  if Assigned(FCloseGestureInfoHandle) then
    Result := FCloseGestureInfoHandle(hGestureInfo)
  else
    Result := False;
end;

function dxSetGestureConfig(AWindow: THandle; const AGestureConfigs: TdxGestureConfigs): Boolean;
begin
  if Assigned(FSetGestureConfig) then
    Result := FSetGestureConfig(AWindow, 0, Length(AGestureConfigs), AGestureConfigs, SizeOf(TdxGestureConfig))
  else
    Result := False;
end;

function dxLogicalToPhysicalPoint(AWindow: THandle; var APoint: TPoint): Boolean;
begin
  if Assigned(FLogicalToPhysicalPoint) then
    Result := FLogicalToPhysicalPoint(AWindow, APoint)
  else
    Result := False;
end;

function dxPhysicalToLogicalPoint(AWindow: THandle; var APoint: TPoint): Boolean;
begin
  if Assigned(FPhysicalToLogicalPoint) then
    Result := FPhysicalToLogicalPoint(AWindow, APoint)
  else
    Result := False;
end;

function dxIsProcessDPIAware: Boolean;
begin
  if Assigned(FIsProcessDPIAware) then
    Result := FIsProcessDPIAware
  else
    Result := False;
end;

function dxLockGestures(AHandle: THandle; var Message: TWMGestureNotify): Boolean;
var
  AConfigs: TdxGestureConfigs;
begin
  SetLength(AConfigs, 1);
  AConfigs[0].dwID := 0;
  AConfigs[0].dwWant := 0;
  AConfigs[0].dwBlock := GC_ALLGESTURES;
  Result := dxSetGestureConfig(AHandle, AConfigs);
  Message.Result := 1;
end;

{ TdxGestureHelper }

constructor TdxGestureHelper.Create(AGestureOwner: IdxGestureOwner);
begin
  inherited Create;
  FGestureOwner := AGestureOwner;
  FTouchHelpers.Add(Self);
end;

destructor TdxGestureHelper.Destroy;
begin
  FTouchHelpers.Remove(Self);
  inherited;
end;

procedure TdxGestureHelper.CheckOverpan(AScrollKind: TScrollBarKind;
  ANewDataPos, AMinDataPos, AMaxDataPos: Integer; ADeltaX, ADeltaY: Integer);
begin
  if NeedPanningFeedback(AScrollKind) and
    not InRange(ANewDataPos, AMinDataPos + 1, AMaxDataPos - 1) then
    if AScrollKind = sbHorizontal then
      DoOverpan(AScrollKind, ADeltaX)
    else
      DoOverpan(AScrollKind, ADeltaY);
end;

{$IFDEF DELPHI14}
procedure TdxGestureHelper.CheckGestureOptions(var Gestures: TInteractiveGestures;
  var Options: TInteractiveGestureOptions);
begin
  FGestureNotifyClient := FGestureOwner.GetGestureClient(GetTouchStartPoint);
  if igPan in Gestures then
    if not IsPanArea(GetTouchStartPoint) then
      Options := Options - [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical]
    else
      if Options * [igoPanSingleFingerHorizontal, igoPanSingleFingerVertical] <> [] then
      begin
        if not AllowPan(sbHorizontal) then
          Options := Options - [igoPanSingleFingerHorizontal];
        if not AllowPan(sbVertical) then
          Options := Options - [igoPanSingleFingerVertical];
      end;
end;

procedure TdxGestureHelper.DoGesture(const EventInfo: TGestureEventInfo; var Handled: Boolean);
begin
  case EventInfo.GestureID of
    igiPan:
      Handled := Pan(EventInfo.Location, gfBegin in EventInfo.Flags, gfEnd in EventInfo.Flags, gfInertia in EventInfo.Flags);
    igiZoom:
      Handled := Zoom(EventInfo.Distance, gfBegin in EventInfo.Flags, gfEnd in EventInfo.Flags);
    igiRotate:
      Handled := Rotate(EventInfo.Angle, gfBegin in EventInfo.Flags, gfEnd in EventInfo.Flags);
  end;
end;
{$ENDIF}

function TdxGestureHelper.HandleMessage(var Message: TMessage): Boolean;
begin
  case Message.Msg of
    WM_GESTURE:
      Result := Gesture(Message);
    WM_GESTURENOTIFY:
      Result := GestureNotify(TWMGestureNotify(Message));
    WM_DESTROY:
      begin
        Result := False;
        if FIsPanning then
          EndGestureScroll;
      end;
  else
    Result := False;
  end;
end;

function TdxGestureHelper.AllowGesture(AGestureId: Integer): Boolean;
begin
  Result := FGestureNotifyClient.AllowGesture(AGestureId);
end;

function TdxGestureHelper.AllowPan(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := FGestureNotifyClient.AllowPan(AScrollKind);
end;

procedure TdxGestureHelper.BeginGestureScroll(const APos: TPoint);
begin
  FIsPanning := True;
  FGestureClient.BeginGestureScroll(APos);
  if NeedPanningFeedback(sbHorizontal) or
    NeedPanningFeedback(sbVertical) then
    dxBeginPanningFeedback(Handle);
  FOverPan := cxNullPoint;
end;

{$IFDEF DELPHI14}
function TdxGestureHelper.Gesture(var Message: TMessage): Boolean;
const
  AGestureMap: array[0..4] of TInteractiveGesture = (igZoom, igPan, igRotate,
    igTwoFingerTap, igPressAndTap);
var
  APoint: TPoint;
  AControl: TControl;
  AGestureInfo: GestureInfo;
  AEventInfo: TGestureEventInfo;
begin
  Result := True;
  ZeroMemory(@AGestureInfo, SizeOf(AGestureInfo));
  AGestureInfo.cbSize := Sizeof(AGestureInfo);
  if GetGestureInfo(Message.LParam, AGestureInfo) then
  try
    ZeroMemory(@AEventInfo, SizeOf(AEventInfo));
    AEventInfo.GestureID := AGestureInfo.dwID + igiFirst;
    AEventInfo.Flags := [];
    if AGestureInfo.dwFlags and GF_BEGIN = GF_BEGIN then
      Include(AEventInfo.Flags, gfBegin);
    if AGestureInfo.dwFlags and GF_INERTIA = GF_INERTIA then
      Include(AEventInfo.Flags, gfInertia);
    if AGestureInfo.dwFlags and GF_END = GF_END then
      Include(AEventInfo.Flags, gfEnd);

    if (AEventInfo.GestureID <> igiBegin) and (AEventInfo.GestureID <> igiEnd) and
      ((FTouchControl <> nil) or ((gfBegin in AEventInfo.Flags) and (FNotifyTouchControl <> nil))) then
    begin
      if gfBegin in AEventInfo.Flags then
        FTouchControl := FNotifyTouchControl;

      AControl := FTouchControl;
      while (AControl.Parent <> nil) and
        (igoParentPassthrough in AControl.Touch.InteractiveGestureOptions) and
         not (AGestureMap[AEventInfo.GestureID - igiZoom] in AControl.Touch.InteractiveGestures) do
        AControl := AControl.Parent;

      APoint := SmallPointToPoint(AGestureInfo.ptsLocation);
      AEventInfo.Location := AControl.ScreenToClient(APoint);
      case AEventInfo.GestureID of
        igiPan:
          begin
            AEventInfo.Distance := Cardinal(AGestureInfo.ullArguments);
            AEventInfo.InertiaVector := InertiaVectorFromArgument(AGestureInfo.ullArguments);
          end;
        igiZoom, igiTwoFingerTap:
          AEventInfo.Distance := Cardinal(AGestureInfo.ullArguments);
        igiPressAndTap:
          begin
            APoint := SmallPointToPoint(TSmallPoint(Cardinal(AGestureInfo.ullArguments)));
            Inc(APoint.X, AGestureInfo.ptsLocation.X);
            Inc(APoint.Y, AGestureInfo.ptsLocation.Y);
            if AControl is TWinControl then
              PhysicalToLogicalPoint(TWinControl(AControl).Handle, APoint)
            else
              PhysicalToLogicalPoint(AControl.Parent.Handle, APoint);
            AEventInfo.TapLocation := PointToSmallPoint(AControl.ScreenToClient(APoint));
          end;
        igiRotate:
          AEventInfo.Angle := RotateAngleFromArgument(AGestureInfo.ullArguments);
      end;
      Message.Result := AControl.Perform(CM_GESTURE, 0, @AEventInfo);
      if gfEnd in AEventInfo.Flags then
        FTouchControl := nil;
    end;
    if Message.Result <> 1 then
      Message.Result := DefWindowProc(Handle, Message.Msg, Message.WParam, Message.LParam);
  finally
    CloseGestureInfoHandle(Message.LParam);
  end;
end;
{$ELSE}
function TdxGestureHelper.Gesture(var Message: TMessage): Boolean;

  function RotateAngleFromArgument(Arg: Word): Double;
  begin
    Result := ((Arg / 65535.0) * 4.0 * 3.14159265) - 2.0 * 3.14159265;
  end;

var
  APoint: TPoint;
  AGestureInfo: TdxGestureInfo;
  AIsBeginGesture, AIsEndGesture: Boolean;
begin
  Result := True;
  ZeroMemory(@AGestureInfo, SizeOf(AGestureInfo));
  AGestureInfo.cbSize := Sizeof(AGestureInfo);
  if dxGetGestureInfo(Message.LParam, AGestureInfo) then
    try
      AIsBeginGesture := AGestureInfo.dwFlags and GF_BEGIN = GF_BEGIN;
      if ((FGestureClient <> nil) or
        (AIsBeginGesture and (FGestureNotifyClient <> nil))) and
        IsGestureTarget(AGestureInfo.hwndTarget) then
      begin
        APoint := SmallPointToPoint(AGestureInfo.ptsLocation);
        APoint := ScreenToClient(APoint);
        AIsEndGesture := AGestureInfo.dwFlags and GF_END = GF_END;
        case AGestureInfo.dwID of
          GID_PAN:
            Message.Result := IfThen(Pan(APoint, AIsBeginGesture, AIsEndGesture, AGestureInfo.dwFlags and GF_INERTIA = GF_INERTIA), 1);
          GID_ZOOM:
            Message.Result := IfThen(Zoom(Cardinal(AGestureInfo.ullArguments), AIsBeginGesture, AIsEndGesture), 1);
          GID_ROTATE:
            Message.Result := IfThen(Rotate(RotateAngleFromArgument(AGestureInfo.ullArguments), AIsBeginGesture, AIsEndGesture), 1);
        end;
      end;
      if Message.Result <> 1 then
        Message.Result := DefWindowProc(Handle, Message.Msg, Message.WParam, Message.LParam);
    finally
      dxCloseGestureInfoHandle(Message.LParam);
    end;
end;
{$ENDIF}

{$IFDEF DELPHI14}
function TdxGestureHelper.GestureNotify(var Message: TWMGestureNotify): Boolean;
var
  APoint: TPoint;
  AGestureOwnerControl: TWinControl;
begin
  Result := False;
  APoint := GetTouchStartPoint;
  AGestureOwnerControl := FindControl(Handle);
  if PtInRect(AGestureOwnerControl.ClientRect, APoint) then
  begin
    FNotifyTouchControl := AGestureOwnerControl.ControlAtPos(APoint, True);
    if FNotifyTouchControl = nil then
      FNotifyTouchControl := AGestureOwnerControl;
  end;
end;
{$ELSE}
function TdxGestureHelper.GestureNotify(var Message: TWMGestureNotify): Boolean;

  function GetGestureOptions(AIndex: Integer): Integer;
  begin
    if dxSupportedGestureIDs[AIndex] = GID_PAN then
      Result :=  GetAllowedPanOptions(GetTouchStartPoint)
    else
      Result := dxSupportedGestureOptions[AIndex];
  end;

  procedure Config(const AConfigs: TdxGestureConfigs; AIndex: Integer);
  const
    AWantFlag: array [Boolean] of Integer = (0, 1);
  var
    AGestureOptions: Integer;
    AAllowGesture: Boolean;
  begin
    AConfigs[AIndex].dwID := dxSupportedGestureIDs[AIndex];
    AGestureOptions := GetGestureOptions(AIndex);
    AAllowGesture := AllowGesture(dxSupportedGestureIDs[AIndex]);
    AConfigs[AIndex].dwWant := AGestureOptions * AWantFlag[AAllowGesture];
    AConfigs[AIndex].dwBlock := not AConfigs[AIndex].dwWant and dxSupportedGestureOptions[AIndex];
  end;

  function ApplyGestureConfig: Boolean;
  var
    AConfigs: TdxGestureConfigs;
    I: Integer;
  begin
    SetLength(AConfigs, dxSupportedGestureCount);
    ZeroMemory(@AConfigs[0], SizeOf(TdxGestureConfig)* dxSupportedGestureCount);
    for I := 0 to dxSupportedGestureCount - 1 do
      Config(AConfigs, I);
    Result := dxSetGestureConfig(Handle, AConfigs);
    Message.Result := 1;
  end;

begin
  FGestureNotifyClient := FGestureOwner.GetGestureClient(GetTouchStartPoint);
  Result := (FGestureNotifyClient <> nil) and
    IsGestureTarget(Message.NotifyStruct^.hwndTarget) and ApplyGestureConfig;
end;
{$ENDIF}

procedure TdxGestureHelper.EndGestureScroll;
begin
  FIsPanning := False;
  FGestureClient.EndGestureScroll;
  if NeedPanningFeedback(sbHorizontal) or
    NeedPanningFeedback(sbVertical) then
    dxEndPanningFeedback(Handle, True);
end;

procedure TdxGestureHelper.GestureScroll(ADeltaX, ADeltaY: Integer);
begin
  FGestureClient.GestureScroll(ADeltaX, ADeltaY);
end;

function TdxGestureHelper.GetAllowedPanOptions(const APoint: TPoint): Integer;

  procedure CheckPanOptions(var APanOptions: Integer);
  begin
    if not IsPanArea(APoint) then
      APanOptions := APanOptions and
        not GC_PAN_WITH_SINGLE_FINGER_VERTICALLY and
        not GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY
    else
    begin
      if not AllowPan(sbVertical) then
        APanOptions := APanOptions and not GC_PAN_WITH_SINGLE_FINGER_VERTICALLY;
      if not AllowPan(sbHorizontal) then
        APanOptions := APanOptions and not GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY;
    end;
  end;

begin
  Result := GetPanOptions;
  CheckPanOptions(Result);
end;

function TdxGestureHelper.GetHandle: THandle;
begin
  Result := FGestureOwner.GetHandle;
end;

function TdxGestureHelper.GetPanOptions: Integer;
begin
  Result := FGestureNotifyClient.GetPanOptions;
end;

function TdxGestureHelper.IsGestureTarget(AWnd: THandle): Boolean;
begin
  Result := FGestureOwner.IsGestureTarget(AWnd);
end;

function TdxGestureHelper.IsPanArea(const APoint: TPoint): Boolean;
begin
  Result := FGestureNotifyClient.IsPanArea(APoint);
end;

function TdxGestureHelper.NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := FGestureClient.NeedPanningFeedback(AScrollKind);
end;

function TdxGestureHelper.ScreenToClient(const APoint: TPoint): TPoint;
begin
  Result := FGestureOwner.ScreenToClient(APoint);
end;

procedure TdxGestureHelper.DoOverpan(AScrollKind: TScrollBarKind; ADelta: Integer);
begin
  if AScrollKind = sbHorizontal then
    Inc(FOverPan.X, ADelta)
  else
    Inc(FOverPan.Y, ADelta);
  dxUpdatePanningFeedback(Handle, FOverPan,  FIsInertia);
end;

function TdxGestureHelper.GetTouchStartPoint: TPoint;
begin
  Result := FGestureStartPoint;
  dxPhysicalToLogicalPoint(Handle, Result);
  Result := ScreenToClient(Result);
end;

function TdxGestureHelper.Pan(APos: TPoint; AIsBegin, AIsEnd, AIsInertia: Boolean): Boolean;

  procedure CheckOverpanned(AScrollKind: TScrollBarKind; var ADelta: Integer);
  var
    AOverpan, AOverpanDelta: Integer;
  begin
    AOverpan := IfThen(AScrollKind = sbHorizontal, FOverPan.X, FOverPan.Y);
    if (AOverpan <> 0) and (ADelta <> 0) and (Sign(ADelta) <> Sign(AOverpan)) and
      NeedPanningFeedback(AScrollKind) then
    begin
      if Abs(AOverpan) < Abs(ADelta) then
        AOverpanDelta := -AOverpan
      else
        AOverpanDelta := ADelta;
      DoOverpan(AScrollKind, AOverpanDelta);
      ADelta := ADelta - AOverpanDelta;
    end;
  end;

var
  ADeltaX, ADeltaY: Integer;
begin
  if FNeedScalePanning then
  begin
    APos.X := MulDiv(APos.X, cxGetCurrentDPI, FDesktopCurrentDPI);
    APos.Y := MulDiv(APos.Y, cxGetCurrentDPI, FDesktopCurrentDPI);
  end;
  FIsInertia := AIsInertia;
  if AIsBegin then
  begin
    FGestureClient := FGestureNotifyClient;
    BeginGestureScroll(APos);
  end
  else
  begin
    ADeltaX := APos.X - FPanPoint.X;
    ADeltaY := APos.Y - FPanPoint.Y;
    if AIsEnd then
      FOverPan := cxNullPoint;
    CheckOverpanned(sbHorizontal, ADeltaX);
    CheckOverpanned(sbVertical, ADeltaY);
    GestureScroll(ADeltaX, ADeltaY);
    if AIsEnd then
    begin
      EndGestureScroll;
      FGestureClient := nil;
    end;
  end;
  FPanPoint := APos;
  Result := True;
end;

function TdxGestureHelper.Rotate(AAngle: Double; AIsBegin, AIsEnd: Boolean): Boolean;
var
  ARotateClient: IdxRotateClient;
begin
  Result := False;
  if AIsBegin then
    FGestureClient := FGestureNotifyClient;
  if Supports(FGestureClient, IdxRotateClient, ARotateClient) then
    ARotateClient.Rotate(AAngle, Result);
  if AIsEnd then
    FGestureClient := nil;
end;

function TdxGestureHelper.Zoom(ADistance: Integer; AIsBegin, AIsEnd: Boolean): Boolean;
var
  AZoomClient: IdxZoomClient;
begin
  Result := False;
  if AIsBegin then
  begin
    FLastDistance := ADistance;
    FGestureClient := FGestureNotifyClient;
  end;
  if Supports(FGestureClient, IdxZoomClient, AZoomClient) then
    AZoomClient.Zoom(ADistance - FLastDistance, Result);
  FLastDistance := ADistance;
  if AIsEnd then
    FGestureClient := nil;
end;

function GetDesktopCurrentDPI: Integer;
const
  SAppliedDPI = 'AppliedDPI';
var
  ARegistry: TRegistry;
begin
  Result := cxGetCurrentDPI;
  ARegistry := TRegistry.Create;
  try
    ARegistry.RootKey := HKEY_CURRENT_USER;
    if ARegistry.OpenKeyReadOnly('Control Panel\Desktop\WindowMetrics') and
      ARegistry.ValueExists(SAppliedDPI) then
      Result := ARegistry.ReadInteger(SAppliedDPI);
  finally
    ARegistry.Free;
  end;
end;

initialization
  FUser32Lib := LoadLibrary(user32);
  if FUser32Lib <> 0 then
  begin
    @FGetGestureInfo := GetProcAddress(FUser32Lib, 'GetGestureInfo');
    @FCloseGestureInfoHandle := GetProcAddress(FUser32Lib, 'CloseGestureInfoHandle');
    @FSetGestureConfig := GetProcAddress(FUser32Lib, 'SetGestureConfig');
    @FLogicalToPhysicalPoint := GetProcAddress(FUser32Lib, 'LogicalToPhysicalPoint');
    @FPhysicalToLogicalPoint := GetProcAddress(FUser32Lib, 'PhysicalToLogicalPoint');
    @FIsProcessDPIAware := GetProcAddress(FUser32Lib, 'IsProcessDPIAware');
  end;
  FDesktopCurrentDPI := GetDesktopCurrentDPI;
  FNeedScalePanning := not IsWin8OrLater and not dxIsProcessDPIAware;
  FTouchHelpers := TdxFastObjectList.Create(False);
  dxSetHook(htWndProc, dxTouchWndProcHook);

finalization
  dxReleaseHook(dxTouchWndProcHook);
  FreeAndNil(FTouchHelpers);
  if FUser32Lib <> 0 then
    FreeLibrary(FUser32Lib);

end.
