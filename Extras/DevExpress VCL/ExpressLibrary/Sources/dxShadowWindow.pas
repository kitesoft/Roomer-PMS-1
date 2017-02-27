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

unit dxShadowWindow;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Types, Windows, Messages, Controls, Graphics, Forms,
  dxMessages, cxControls, cxGraphics, cxGeometry, dxSkinsCore;

type

  { TdxCustomShadowWindow }

  TdxCustomShadowWindow = class(TCustomControl)
  private
    FOwnerWindow: TWinControl;
    FShadowMask: TdxSkinImage;
    FTransparent: Boolean;
    FShadowColor: TColor;
    function GetVisible: Boolean;
    procedure SetShadowColor(AValue: TColor);
    procedure SetTransparent(AValue: Boolean);
    procedure SetVisible(AValue: Boolean);
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    procedure DrawShadowImage(ACanvas: TcxCanvas); virtual;
    procedure Paint; override;
    procedure Resize; override;
    procedure UpdateLayer;
    // Messages
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd); message WM_ERASEBKGND;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
  public
    constructor Create(AOwnerWindow: TWinControl); reintroduce; virtual;
    destructor Destroy; override;
    procedure Hide; virtual;
    procedure Refresh;
    procedure Show; virtual;
    //
    property OwnerWindow: TWinControl read FOwnerWindow;
    property ShadowColor: TColor read FShadowColor write SetShadowColor;
    property Transparent: Boolean read FTransparent write SetTransparent;
    property Visible: Boolean read GetVisible write SetVisible;
  end;

  { TdxShadowWindow }

  TdxShadowWindow = class(TdxCustomShadowWindow)
  private
    FActivating: Boolean;
    FAllowResizeOwnerWindowViaShadow: Boolean;
    FOwnerWindowIsActive: Boolean;
    FOwnerWindowWndProcObject: TcxWindowProcLinkedObject;
    FShadowOffsets: TRect;
    procedure SetAllowResizeOwnerWindowViaShadow(const AValue: Boolean);
    procedure SetShadowOffsets(const AValue: TRect);
  protected
    function CalculateVisibility: Boolean; virtual;
    procedure DrawShadowImage(ACanvas: TcxCanvas); override;
    procedure OwnerWindowWndProc(var AMessage: TMessage); virtual;
    // Messages
    procedure WMActivate(var Message: TWMActivate); message WM_ACTIVATE;
    procedure WMMouseActivate(var Message: TWMMouseActivate); message WM_MOUSEACTIVATE;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
    procedure WMSizing(var Message: TMessage); message WM_SIZING;
    //
    property OwnerWindowIsActive: Boolean read FOwnerWindowIsActive;
    property OwnerWindowWndProcObject: TcxWindowProcLinkedObject read FOwnerWindowWndProcObject;
  public
    constructor Create(AOwnerWindow: TWinControl); override;
    destructor Destroy; override;
    procedure Show; override;
    procedure UpdateBounds;
    procedure UpdateVisibility;
    //
    property AllowResizeOwnerWindowViaShadow: Boolean read FAllowResizeOwnerWindowViaShadow write SetAllowResizeOwnerWindowViaShadow;
    property ShadowOffsets: TRect read FShadowOffsets write SetShadowOffsets;
  end;

function dxCanUseShadows: Boolean;
function dxCanUseTransparentShadows: Boolean;
procedure UpdateWindowLayer(AHandle: THandle; ABitmap: TBitmap; AAlpha: Integer = 255);

implementation

uses
  Math, SysUtils;

{$R dxShadowWindow.res}

var
  FUpdateLayeredWindow: function(Handle: HWND; hdcDest: HDC; pptDst: PPoint;
    Size: PSize; hdcSrc: HDC; pptSrc: PPoint; crKey: COLORREF;
    pblend: PBLENDFUNCTION; dwFlags: DWORD): Boolean; stdcall;

function dxCanUseShadows: Boolean;
begin
  Result := dxSystemInfo.IsDropShadow and not dxSystemInfo.IsRemoteSession;
end;

function dxCanUseTransparentShadows: Boolean;
begin
  Result := Assigned(FUpdateLayeredWindow) and dxCanUseShadows;
  if Result then
  begin
    Result := GetDeviceCaps(cxScreenCanvas.Handle, BITSPIXEL) > 8;
    cxScreenCanvas.Dormant;
  end;
end;

procedure UpdateWindowLayer(AHandle: THandle; ABitmap: TBitmap; AAlpha: Integer = 255);
var
  ABlend: TBlendFunction;
  APoint: TPoint;
  ASize: TSize;
begin
  APoint := cxNullPoint;
  ASize := cxSize(ABitmap.Width, ABitmap.Height);
  ABlend.BlendOp := AC_SRC_OVER;
  ABlend.BlendFlags := 0;
  ABlend.SourceConstantAlpha := AAlpha;
  ABlend.AlphaFormat := AC_SRC_ALPHA;
  if Assigned(FUpdateLayeredWindow) then
    FUpdateLayeredWindow(AHandle, 0, nil, @ASize, ABitmap.Canvas.Handle, @APoint, 0, @ABlend, LWA_ALPHA);
end;

{ TdxCustomShadowWindow }

constructor TdxCustomShadowWindow.Create(AOwnerWindow: TWinControl);
begin
  inherited Create(nil);
  FOwnerWindow := AOwnerWindow;
  FShadowMask := TdxSkinImage.Create(nil);
  FShadowMask.LoadFromResource(HInstance, 'DXSHADOWMASK', 'PNG');
  FShadowMask.Margins.All := 5;
  FShadowColor := clBlack;
  Transparent := True;
{$IFDEF DELPHI16}
  ControlStyle := ControlStyle + [csOverrideStylePaint];
{$ENDIF}
  Enabled := False;
end;

destructor TdxCustomShadowWindow.Destroy;
begin
  FreeAndNil(FShadowMask);
  inherited Destroy;
end;

procedure TdxCustomShadowWindow.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  Params.Style := WS_POPUP;
  Params.WndParent := OwnerWindow.Handle;
  Params.WindowClass.style := 0;

  if Transparent then
    Params.ExStyle := WS_EX_LAYERED
  else
    Params.ExStyle := 0;

  if GetWindowLong(OwnerWindow.Handle, GWL_EXSTYLE) and WS_EX_TOPMOST <> 0 then
    Params.ExStyle := Params.ExStyle or WS_EX_TOPMOST;

  if not Enabled then
    Params.Style := Params.Style or WS_DISABLED;
end;

procedure TdxCustomShadowWindow.DrawShadowImage(ACanvas: TcxCanvas);
begin
  FShadowMask.Draw(ACanvas.Handle, ClientRect);
end;

procedure TdxCustomShadowWindow.Hide;
begin
  if HandleAllocated then
  begin
    ShowWindow(Handle, SW_HIDE);
    DestroyHandle;
  end;
end;

procedure TdxCustomShadowWindow.Paint;
begin
  Canvas.Brush.Color := cl3DDkShadow;
  Canvas.FillRect(ClientRect);
end;

procedure TdxCustomShadowWindow.Refresh;
begin
  if Transparent then
    UpdateLayer
  else
    Invalidate;
end;

procedure TdxCustomShadowWindow.Resize;
begin
  inherited Resize;
  Refresh;
end;

procedure TdxCustomShadowWindow.Show;
begin
  dxSetZOrder(Handle, OwnerWindow.Handle, False, SWP_SHOWWINDOW);
  Refresh;
end;

procedure TdxCustomShadowWindow.UpdateLayer;
var
  ABitmap: TcxBitmap32;
begin
  if HandleAllocated and Visible then
  begin
    ABitmap := TcxBitmap32.CreateSize(ClientRect, True);
    try
      DrawShadowImage(ABitmap.cxCanvas);
      UpdateWindowLayer(Handle, ABitmap);
    finally
      ABitmap.Free;
    end;
  end;
end;

function TdxCustomShadowWindow.GetVisible: Boolean;
begin
  Result := HandleAllocated and IsWindowVisible(Handle); 
end;

procedure TdxCustomShadowWindow.SetShadowColor(AValue: TColor);
begin
  if (FShadowColor <> AValue) and cxColorIsValid(AValue) then
  begin
    FShadowColor := AValue;
    FShadowMask.Texture.ChangeColor(ShadowColor);
    UpdateLayer;
  end;
end;

procedure TdxCustomShadowWindow.SetTransparent(AValue: Boolean);
begin
  AValue := AValue and dxCanUseTransparentShadows;
  if AValue <> FTransparent then
  begin
    FTransparent := AValue;
    if HandleAllocated then
      RecreateWnd;
  end;
end;

procedure TdxCustomShadowWindow.SetVisible(AValue: Boolean);
begin
  if Visible <> AValue then
  begin
    if AValue then
      Show
    else
      Hide;
  end;
end;

procedure TdxCustomShadowWindow.WMNCHitTest(var Message: TWMNCHitTest);
begin
  inherited;
  Message.Result := HTTRANSPARENT;
end;

procedure TdxCustomShadowWindow.WMEraseBkgnd(var Message: TWMEraseBkgnd);
begin
  Message.Result := 0;
end;

procedure TdxCustomShadowWindow.WMPaint(var Message: TWMPaint);
begin
  if Transparent then
  begin
    DefaultHandler(Message);
    Message.Result := 0;
  end
  else
    inherited;
end;

{ TdxShadowWindow }

constructor TdxShadowWindow.Create(AOwnerWindow: TWinControl);
begin
  inherited Create(AOwnerWindow);
  FOwnerWindowWndProcObject := cxWindowProcController.Add(OwnerWindow, OwnerWindowWndProc);
  FOwnerWindowIsActive := OwnerWindow.HandleAllocated and (OwnerWindow.Handle = GetActiveWindow);
  ShadowOffsets := cxRect(4, 4, 4, 4);
end;

destructor TdxShadowWindow.Destroy;
begin
  cxWindowProcController.Remove(FOwnerWindowWndProcObject);
  inherited Destroy;
end;

function TdxShadowWindow.CalculateVisibility: Boolean;
begin
  Result := (OwnerWindowIsActive or FActivating) and IsWindowVisible(OwnerWindow.Handle) and
    dxCanUseShadows and not (IsZoomed(OwnerWindow.Handle) or IsIconic(OwnerWindow.Handle)) and
    (GetWindowLong(OwnerWindow.Handle, GWL_STYLE) and WS_CHILD = 0);
end;

procedure TdxShadowWindow.DrawShadowImage(ACanvas: TcxCanvas);
var
  ARegion: TcxRegion;
begin
  ACanvas.SaveClipRegion;
  try
    ACanvas.SaveClipRegion;
    try
      ARegion := TcxRegion.CreateFromWindow(OwnerWindow.Handle);
      ARegion.Offset(dxMapWindowPoint(OwnerWindow.Handle, Handle, cxNullPoint, False));
      ACanvas.SetClipRegion(ARegion, roSubtract);
      inherited DrawShadowImage(ACanvas);
    finally
      ACanvas.RestoreClipRegion;
    end;
  finally
    ACanvas.RestoreClipRegion;
  end;  
end;

procedure TdxShadowWindow.OwnerWindowWndProc(var AMessage: TMessage);
begin
  if AMessage.Msg = CM_SHOWINGCHANGED then
  begin
    if not OwnerWindow.Visible then
      Hide;
  end;

  OwnerWindowWndProcObject.DefaultProc(AMessage);

  case AMessage.Msg of
    WM_NCACTIVATE:
      begin
        FOwnerWindowIsActive := TWMNCActivate(AMessage).Active;
        UpdateVisibility;
      end;

    WM_WINDOWPOSCHANGED:
      with TWMWindowPosChanged(AMessage).WindowPos^ do
      begin
        if (flags and SWP_NOSIZE = 0) or (flags and SWP_NOMOVE = 0) then
        begin
          UpdateVisibility;
          UpdateBounds;
        end;
      end;
  end;
end;

procedure TdxShadowWindow.Show;
begin
  UpdateBounds;
  inherited Show;
end;

procedure TdxShadowWindow.UpdateBounds;
begin
  BoundsRect := cxRectInflate(OwnerWindow.BoundsRect, ShadowOffsets);
end;

procedure TdxShadowWindow.UpdateVisibility;
begin
  Visible := CalculateVisibility;
end;

procedure TdxShadowWindow.WMActivate(var Message: TWMActivate);
begin
  if not FActivating and (Message.Active <> WA_INACTIVE) then
  begin
    SetActiveWindow(OwnerWindow.Handle);
    Message.Result := 0;
    Exit;
  end;

  inherited;
  if Message.Active <> WA_INACTIVE then
    SendMessage(Message.ActiveWindow, WM_NCACTIVATE, WPARAM(True), 0);
  FActivating := False;
end;

procedure TdxShadowWindow.WMMouseActivate(var Message: TWMMouseActivate);
begin
  FActivating := True;
  inherited; 
end;

procedure TdxShadowWindow.WMNCHitTest(var Message: TWMNCHitTest);

  function CheckVerticalSide(const R: TRect; ATopCornerCode, ABottomCornerCode, ASideCode: Integer): Integer;
  begin
    if Message.YPos <= R.Top then
      Result := ATopCornerCode
    else
      if Message.YPos >= R.Bottom then
        Result := ABottomCornerCode
      else
        Result := ASideCode;
  end;
  
var
  R: TRect;
begin
  inherited; 
  if AllowResizeOwnerWindowViaShadow then
  begin  
    R := cxRectInflate(BoundsRect, -GetSystemMetrics(SM_CXSIZEFRAME), -GetSystemMetrics(SM_CYSIZEFRAME));
    if not PtInRect(R, SmallPointToPoint(Message.Pos)) then
    begin    
      if Message.XPos >= R.Right then
        Message.Result := CheckVerticalSide(R, HTTOPRIGHT, HTBOTTOMRIGHT, HTRIGHT)
      else

      if Message.XPos <= R.Left then
        Message.Result := CheckVerticalSide(R, HTTOPLEFT, HTBOTTOMLEFT, HTLEFT)
      else

      if Message.YPos <= R.Top then
        Message.Result := HTTOP
      else
        Message.Result := HTBOTTOM;
    end;
  end;
end;

procedure TdxShadowWindow.WMSizing(var Message: TMessage);
var
  R: PRect;
begin
  if AllowResizeOwnerWindowViaShadow then
  begin  
    R := PRect(Message.LParam);
    OwnerWindow.BoundsRect := cxRectContent(R^, ShadowOffsets);
    R^ := cxRectInflate(OwnerWindow.BoundsRect, ShadowOffsets);
  end;
  inherited;  
end;

procedure TdxShadowWindow.SetAllowResizeOwnerWindowViaShadow(const AValue: Boolean);
begin
  if FAllowResizeOwnerWindowViaShadow <> AValue then
  begin
    FAllowResizeOwnerWindowViaShadow := AValue;
    Enabled := AllowResizeOwnerWindowViaShadow;
  end;
end;

procedure TdxShadowWindow.SetShadowOffsets(const AValue: TRect);
begin
  if not cxRectIsEqual(FShadowOffsets, AValue) then
  begin
    FShadowOffsets := AValue;
    if Visible then    
      UpdateBounds;
  end;
end;

initialization
  @FUpdateLayeredWindow := GetProcAddress(GetModuleHandle(user32), 'UpdateLayeredWindow');
  
end.
