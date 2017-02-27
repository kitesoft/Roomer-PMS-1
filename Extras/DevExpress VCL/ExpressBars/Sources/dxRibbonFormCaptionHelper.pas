{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       ExpressBars components                                      }
{                                                                   }
{       Copyright (c) 1998-2014 Developer Express Inc.              }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSBARS AND ALL ACCOMPANYING VCL }
{   CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.                 }
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

unit dxRibbonFormCaptionHelper;      

{$I cxVer.inc}

{$ALIGN ON} 

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Types, Windows, Messages, SysUtils, Classes, Graphics, Controls, ExtCtrls, Forms,
  dxCore, dxMessages, cxClasses, cxGraphics, cxControls, dxBar, dxRibbonSkins, dxCoreClasses;

type
  TdxRibbonBorderIconBounds = array[TdxRibbonBorderIcon] of TRect;
  TdxRibbonFormRegion = (rfrWindow, rfrClient, rfrNCHitTest);
  TdxRibbonTrackedBorderIcon = (tbiNone, tbiSystemMenu, tbiMinimize,
    tbiMaximize, tbiHelp, tbiAutoHide, tbiAutoHideModeShowUI);

  { IdxRibbonFormNonClientPart }

  IdxRibbonFormNonClientPart = interface
  ['{9266F6BD-0C9A-402A-A49F-D6405A2DDAF0}']
  end;

  { IdxRibbonFormNonClientHelper }

  IdxRibbonFormNonClientHelper = interface
  ['{2F024903-3552-4859-961F-F778ED5E1DB6}']
    procedure AdjustRibbonFormBorderIconSize(
      AIcon: TdxRibbonBorderDrawIcon; AIsToolWindow: Boolean; var ASize: TSize);
    procedure DoHelpButtonClick;
    procedure DrawRibbonFormBackground(DC: HDC; const ARect: TRect);
    procedure DrawRibbonFormBorders(ACanvas: TcxCanvas;
      const AData: TdxRibbonFormData; const ABordersWidth: TRect);
    procedure DrawRibbonFormBorderIcon(ACanvas: TcxCanvas; const ABounds: TRect;
      AIcon: TdxRibbonBorderDrawIcon; AState: TdxRibbonBorderIconState);
    procedure DrawRibbonFormCaption(ACanvas: TcxCanvas;
      const ABounds: TRect; const ACaption: string; const AData: TdxRibbonFormData);
    procedure GetApplicationMenuTabOrderList(List: TList);
    function GetApplicationMenuState: TdxRibbonApplicationMenuState;
    function GetBarManager: TdxBarManager;
    function GetBarPainter: TdxBarPainter;
    function GetRibbonFormCaptionAreaExtention: Integer;
    function GetRibbonFormCaptionHeight: Integer;
    function GetRibbonFormCaptionHeightForHiddenRibbon: Integer;
    function GetRibbonFormColor: TColor;
    function GetRibbonFormExtendedCaptionAreaRegion: HRGN;
    function GetRibbonLoadedHeight: Integer;
    function GetRibbonNonClientAreaObjectsRegion: HRGN;
    function GetRibbonQATNonClientAreaBounds: TRect;
    function GetRibbonStyle: TdxRibbonStyle;
    function GetStatusBarInterface: IUnknown;
    function GetTaskbarCaption: TCaption;
    function GetWindowBordersWidth: TRect;
    function HasExternalRibbonFormShadow: Boolean;
    function HasHelpButton: Boolean;
    function HasStatusBar: Boolean;
    function UseRoundedWindowCorners: Boolean;
    procedure UpdateNonClientArea;
  end;

  { IdxFormKeyPreviewListener }

  IdxFormKeyPreviewListener = interface
  ['{7192BF84-F80D-4DB0-A53B-06F6703B1A97}']
    procedure FormKeyDown(var Key: Word; Shift: TShiftState);
  end;

  { TdxRibbonFormCaptionHelper }

  TdxRibbonFormCaptionHelper = class(TcxIUnknownObject, IdxBarHintKeeper)
  private
    FBitmap: TcxBitmap32;
    FBorderIcons: TdxRibbonBorderIcons;
    FBorderIconsArea: TRect;
    FFormCaptionDrawBounds: TRect;
    FFormCaptionRegions: array[TdxRibbonFormRegion] of HRGN;
    FFormData: TdxRibbonFormData;
    FHotBorderIcon: TdxRibbonTrackedBorderIcon;
    FIsClientDrawing: Boolean;
    FMouseTimer: TcxTimer;
    FOldWndProc: TWndMethod;
    FOwner: TcxControl;
    FPressedBorderIcon: TdxRibbonTrackedBorderIcon;
    FRibbonHelper: IdxRibbonFormNonClientHelper;
    FSysMenuBounds: TRect;
    FWasCapture: Boolean;
    procedure CalculateFormCaption;
    function CanProcessFormCaptionHitTest(X, Y: Integer): Boolean;
    procedure DestroyCaptionRegions;
    procedure DrawBorderIcons(ACanvas: TcxCanvas);
    procedure ExcludeCaptionRgn(DC: HDC);
    function GetApplicationMenuState: TdxRibbonApplicationMenuState;
    function GetBarManager: TdxBarManager;
    function GetBorderIconAtPoint(const P: TPoint): TdxRibbonBorderIcon;
    function GetBorderIconState(AIcon: TdxRibbonBorderIcon): TdxRibbonBorderIconState;
    function GetClientCaptionBounds: TRect;
    function GetClientCaptionRegion: HRGN;
    function GetClientRect: TRect;
    function GetDrawIconFromBorderIcon(AIcon: TdxRibbonBorderIcon): TdxRibbonBorderDrawIcon;
    function GetExtentedCaptionAreaRegion: HRGN;
    function GetForm: TCustomForm;
    function GetFormCaptionDrawBounds: TRect;
    function GetFormCaptionRegionsForDC(DC: HDC; ARegionKind: TdxRibbonFormRegion): HRGN;
    function GetHandle: THandle;
    function GetIsValid: Boolean;
    function GetNCHitTestRegion: HRGN;
    function GetNonClientAreaObjectsRegion: HRGN;
    function HasSysMenu: Boolean;
    function IsBorderIconMouseEvent(const P: TPoint; out CP: TPoint; ACheckComposition: Boolean = True): Boolean;
    procedure MouseTimerHandler(Sender: TObject);
    procedure RepaintBorderIcons;
    procedure SetHotBorderIcon(AValue: TdxRibbonTrackedBorderIcon);
    procedure SetPressedBorderIcon(AValue: TdxRibbonTrackedBorderIcon);
    procedure StartMouseTimer;
    procedure StopMouseTimer;
    //
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd);
    procedure WMNCHitTest(var Message: TWMNCHitTest);
    procedure WMPaint(var Message: TWMPaint);
    procedure WMSize(var Message: TWMSize);
    procedure WMShowWindow(var Message: TMessage);
  protected
    FBorderIconBounds: TdxRibbonBorderIconBounds;
    FSysMenuIconBounds: TRect;
    FTextBounds: TRect;
    procedure BufferedDrawCaption(ADestCanvas: TcxCanvas; const ACaption: TCaption);
    function CalculateBorderIconSize(ABorderIcon: TdxRibbonBorderIcon): TSize;
    procedure CalculateBorderIcons; virtual;
    procedure CalculateBorderIconsForCustomSkinning; virtual;
    procedure CalculateSysMenuIconBounds; virtual;
    procedure CalculateTextBounds; virtual;
    function CanCalculate: Boolean;
    procedure DrawWindowBorderIcon(ACanvas: TcxCanvas; const ABounds: TRect;
      AIcon: TdxRibbonBorderIcon; AState: TdxRibbonBorderIconState);
    function GetWindowCaptionBounds: TRect; virtual;
    function GetWindowCaptionRegion: HRGN; virtual;
    procedure InitializeHelpers; virtual;
    procedure OriginalWndProc(var Message);
    procedure WndProc(var Message: TMessage); virtual;
    // IdxBarHintKeeper
    function CreateHintViewInfo(const AHintText, AShortCut: string): TdxBarCustomHintViewInfo;
    function DoHint(var ANeedDeactivate: Boolean; out AHintText, AShortCut: string): Boolean;
    function GetEnabled: Boolean;
    function GetHintPosition(const ACursorPos: TPoint; AHeight: Integer): TPoint;

    property BarManager: TdxBarManager read GetBarManager;
    property Form: TCustomForm read GetForm;
    property Handle: THandle read GetHandle;
    property HotBorderIcon: TdxRibbonTrackedBorderIcon read FHotBorderIcon write SetHotBorderIcon;
    property PressedBorderIcon: TdxRibbonTrackedBorderIcon read FPressedBorderIcon write SetPressedBorderIcon;
    property Valid: Boolean read GetIsValid;
  public
    constructor Create(AOwner: TcxControl);
    destructor Destroy; override;
    procedure Calculate;
    procedure CalculateWindowCaptionHitTest(var Message: TWMNCHitTest); virtual;
    procedure CancelMode;
    procedure CheckWindowStates(const AFormData: TdxRibbonFormData);
    procedure DrawWindowBorders(ACanvas: TcxCanvas);
    procedure DrawWindowCaption(ACanvas: TcxCanvas; const ACaption: TCaption);
    procedure DrawRibbonFormBackground(DC: HDC; const ARect: TRect);
    procedure GetDesignInfo(out ALoadedHeight, ACurrentHeight: Integer);
    procedure GetApplicationMenuTabOrderList(AList: TList);
    function GetCaptionAreaExtention: Integer; virtual;
    function GetTaskbarCaption: TCaption; virtual;
    function GetWindowBordersWidth: TRect; virtual;
    function GetWindowCaptionHeight: Integer; virtual;
    function GetWindowCaptionHeightForHiddenRibbon: Integer; virtual;
    function GetWindowColor: TColor;
    function GetWindowRegion: HRGN; virtual;
    function GetWindowSystemMenuBounds: TRect; virtual;
    function IsInCaptionArea(const P: TPoint): Boolean; virtual;
    function IsRibbonHelpButtonPlacedOnCaption: Boolean; virtual;
    function MouseDown(const P: TPoint; AButton: TMouseButton): Boolean; virtual;
    function MouseUp(const P: TPoint; AButton: TMouseButton): Boolean; virtual;
    procedure UpdateCaptionArea(ACanvas: TcxCanvas = nil);
    procedure UpdateNonClientArea;
    procedure UpdateWindowBorderIcons(const AIcons: TdxRibbonBorderIcons);
    function UseRoundedWindowCorners: Boolean;

    property ApplicationMenuState: TdxRibbonApplicationMenuState read GetApplicationMenuState;
    property BorderIconsArea: TRect read FBorderIconsArea;
    property Control: TcxControl read FOwner;
    property FormCaptionDrawBounds: TRect read FFormCaptionDrawBounds;
    property FormData: TdxRibbonFormData read FFormData;
    property RibbonHelper: IdxRibbonFormNonClientHelper read FRibbonHelper;
    property SysMenuIconBounds: TRect read FSysMenuIconBounds;
    property TextBounds: TRect read FTextBounds;
  end;

function GetClipRegion(DC: HDC): HRGN;
function GetDefaultWindowBordersWidth(H: THandle): TRect;
function GetDefaultWindowNCSize(H: THandle): TRect;
function IsShowMinimizedOnDesktop(H: THandle): Boolean;
procedure RecalculateNonClient(AControl: TWinControl);
function UseAeroNCPaint(const AData: TdxRibbonFormData): Boolean;
procedure WinControlFullInvalidate(AControl: TWinControl;
  AIncludeChildren: Boolean = False; AForceUpdate: Boolean = False);

procedure dxCombineRectRegion(var ARegion: HRGN; const R: TRect; ACombineMode: Integer); overload;
procedure dxCombineRectRegion(var ARegion: HRGN; X0, Y0, X1, Y1, ACombineMode: Integer); overload;
implementation

uses
  cxGeometry, Math, cxDWMApi, dxRibbon, dxBarStrs;

const
  BorderIconsMap: array[TdxRibbonBorderIcon] of TdxRibbonTrackedBorderIcon = (
    tbiSystemMenu, tbiMinimize, tbiMaximize, tbiHelp, tbiAutoHide, tbiAutoHideModeShowUI
  );

type
  TCustomFormAccess = class(TCustomForm);

procedure dxCombineRectRegion(var ARegion: HRGN; const R: TRect; ACombineMode: Integer);
begin
  dxCombineRectRegion(ARegion, R.Left, R.Top, R.Right, R.Bottom, ACombineMode);
end;

procedure dxCombineRectRegion(var ARegion: HRGN; X0, Y0, X1, Y1, ACombineMode: Integer);
var
  R: HRGN;
begin
  if ARegion = 0 then
    ARegion := CreateRectRgnIndirect(cxNullRect);
  R := CreateRectRgn(X0, Y0, X1, Y1);
  CombineRgn(ARegion, ARegion, R, ACombineMode);
  DeleteObject(R);
end;

function TestWindowStyle(AHandle: HWND; AMaskStyle: Cardinal): Cardinal;
begin
  Result := GetWindowLong(AHandle, GWL_STYLE) and AMaskStyle;
end;

function GetClipRegion(DC: HDC): HRGN;
begin
  Result := CreateRectRgn(0, 0, 0, 0);
  if GetClipRgn(DC, Result) = 0 then
    SetRectRgn(Result, 0, 0, cxMaxRegionSize, cxMaxRegionSize);
end;

function GetDefaultWindowNCSize(H: THandle): TRect;
begin
  Result := cxEmptyRect;
  if not IsIconic(H) then
  begin
    AdjustWindowRectEx(Result, GetWindowLong(H, GWL_STYLE), False, GetWindowLong(H, GWL_EXSTYLE));
    Result.Top := -Result.Top;
    Result.Left := -Result.Left;
  end;
end;

function GetDefaultWindowBordersWidth(H: THandle): TRect;
begin
  Result := GetDefaultWindowNCSize(H);
  if not cxRectIsEqual(Result, cxEmptyRect) then
    Dec(Result.Top, GetSystemMetrics(SM_CYCAPTION));
end;

function IsShowMinimizedOnDesktop(H: THandle): Boolean;
begin
  Result := (TestWindowStyle(H, WS_CHILDWINDOW) <> 0) or
    (GetWindowLong(H, GWL_EXSTYLE) and WS_EX_APPWINDOW = 0);
end;

procedure RecalculateNonClient(AControl: TWinControl);
begin
  if Assigned(AControl) and AControl.HandleAllocated then
    SetWindowPos(AControl.Handle, 0, 0, 0, 0, 0,
      SWP_NOSIZE or SWP_NOMOVE or SWP_NOZORDER or SWP_NOACTIVATE or
      SWP_NOSENDCHANGING or SWP_FRAMECHANGED);
end;

function UseAeroNCPaint(const AData: TdxRibbonFormData): Boolean;
begin
  Result := not AData.DontUseAero and (AData.Style <> fsMDIChild) and
    (AData.Handle <> 0) and IsCompositionEnabled;
end;

procedure WinControlFullInvalidate(AControl: TWinControl; AIncludeChildren: Boolean = False;
  AForceUpdate: Boolean = False);
var
  AFlags: Cardinal;
begin
  if (AControl <> nil) and AControl.HandleAllocated and IsWindowVisible(AControl.Handle) then
  begin
    AControl.Invalidate;
    AFlags := RDW_ERASE or RDW_INVALIDATE or RDW_FRAME;
    if AIncludeChildren then
      AFlags := AFlags or RDW_ALLCHILDREN;
    if AForceUpdate then
      AFlags := AFlags or RDW_UPDATENOW or RDW_ERASENOW;
    RedrawWindow(AControl.Handle, nil, 0, AFlags);
    if not AForceUpdate then
      AControl.Update;
  end;
end;

{ TdxRibbonFormCaptionHelper }

constructor TdxRibbonFormCaptionHelper.Create(AOwner: TcxControl);
begin
  inherited Create;
  FOwner := AOwner;
  InitializeHelpers;
  FBitmap := TcxBitmap32.Create;
  FOldWndProc := Control.WindowProc;
  Control.WindowProc := WndProc;
end;

destructor TdxRibbonFormCaptionHelper.Destroy;
begin
  StopMouseTimer;
  Control.WindowProc := FOldWndProc;
  DestroyCaptionRegions;
  FreeAndNil(FBitmap);
  inherited Destroy;
end;

procedure TdxRibbonFormCaptionHelper.Calculate;
begin
  if CanCalculate then
  begin
    CalculateFormCaption;
    CalculateBorderIcons;
    CalculateSysMenuIconBounds;
    CalculateTextBounds;
  end;
end;

procedure TdxRibbonFormCaptionHelper.CalculateWindowCaptionHitTest(var Message: TWMNCHitTest);
var
  AIcon: TdxRibbonBorderIcon;
  APoint: TPoint;
begin
  if IsInCaptionArea(cxPoint(Message.XPos, Message.YPos)) then
  begin
    Message.Result := HTCAPTION;
    APoint := Control.ScreenToClient(cxPoint(Message.XPos, Message.YPos));
    if cxRectPtIn(FBorderIconsArea, APoint) then
    begin
      StartMouseTimer;
      for AIcon := Low(TdxRibbonBorderIcon) to High(TdxRibbonBorderIcon) do
        if (AIcon in FBorderIcons) and cxRectPtIn(FBorderIconBounds[AIcon], APoint) then
        begin
          HotBorderIcon := BorderIconsMap[AIcon];
          Message.Result := HTNOWHERE;
          Exit;
        end;
    end;
    if cxRectPtIn(FSysMenuBounds, APoint) then
      Message.Result := HTSYSMENU;
    HotBorderIcon := tbiNone;
  end;
end;

procedure TdxRibbonFormCaptionHelper.CancelMode;
begin
  PressedBorderIcon := tbiNone;
  FWasCapture := False;
end;

procedure TdxRibbonFormCaptionHelper.CheckWindowStates(const AFormData: TdxRibbonFormData);
begin
  if not CompareMem(@AFormData, @FFormData, SizeOf(TdxRibbonFormData)) then
  begin
    FFormData := AFormData;
    Calculate;
  end;
end;

procedure TdxRibbonFormCaptionHelper.DrawWindowBorderIcon(ACanvas: TcxCanvas;
  const ABounds: TRect; AIcon: TdxRibbonBorderIcon; AState: TdxRibbonBorderIconState);
begin
  if not cxRectIsEmpty(ABounds) then
  begin
    RibbonHelper.DrawRibbonFormBorderIcon(
      ACanvas, ABounds, GetDrawIconFromBorderIcon(AIcon), AState);
  end;
end;

function TdxRibbonFormCaptionHelper.GetApplicationMenuState: TdxRibbonApplicationMenuState;
begin
  Result := RibbonHelper.GetApplicationMenuState;
end;

procedure TdxRibbonFormCaptionHelper.GetApplicationMenuTabOrderList(AList: TList);
begin
  RibbonHelper.GetApplicationMenuTabOrderList(AList);
end;

function TdxRibbonFormCaptionHelper.GetCaptionAreaExtention: Integer;
begin
  Result := RibbonHelper.GetRibbonFormCaptionAreaExtention;
end;

function TdxRibbonFormCaptionHelper.GetTaskbarCaption: TCaption;
begin
  Result := RibbonHelper.GetTaskbarCaption;
end;

function TdxRibbonFormCaptionHelper.GetWindowBordersWidth: TRect;
begin
  Result := RibbonHelper.GetWindowBordersWidth;
end;

function TdxRibbonFormCaptionHelper.GetWindowColor: TColor;
var
  AForm: TCustomForm;
begin
  if RibbonHelper <> nil then
    Result := RibbonHelper.GetRibbonFormColor
  else
  begin
    AForm := Form;
    if AForm <> nil then
      Result := AForm.Color
    else
      Result := clBtnFace;
  end;
end;

function TdxRibbonFormCaptionHelper.GetWindowRegion: HRGN;
const
  Radius = 9;
var
  AForm: TCustomForm;
  AWidth, AHeight: Integer;
  AWindowRect: TRect;
begin
  Result := 0;
  AForm := Form;
  if (AForm <> nil) and AForm.HandleAllocated and GetWindowRect(AForm.Handle, AWindowRect) then
  begin
    AWidth := cxRectWidth(AWindowRect);
    AHeight := cxRectHeight(AWindowRect);
    if UseRoundedWindowCorners then
    begin
      Result := CreateRoundRectRgn(0, 0, AWidth + 1, AHeight + 1, Radius, Radius);
      if IsRectangularFormBottom(FormData) then
        dxCombineRectRegion(Result, 0, Radius, AWidth + 1, AHeight + 1, RGN_OR)
    end
    else
      Result := CreateRectRgn(0, 0, AWidth, AHeight);
  end;
end;

function TdxRibbonFormCaptionHelper.GetWindowSystemMenuBounds: TRect;
var
  R: TRect;
  H: Integer;
begin
  R := GetDefaultWindowBordersWidth(FormData.Handle);
  if UseAeroNCPaint(FormData) then
  begin
    H := GetSystemMetrics(SM_CYCAPTION);
    Result := cxRectBounds(0, R.Top, H, H);
  end
  else
    Result := cxRect(0, R.Top, GetSystemMetrics(SM_CYSIZE) + 2, GetWindowCaptionHeight - 2);
end;

function TdxRibbonFormCaptionHelper.UseRoundedWindowCorners: Boolean;
begin
  Result := RibbonHelper.UseRoundedWindowCorners and
    (RibbonHelper.GetApplicationMenuState <> ramsShownAsFullScreenFrame);
end;

procedure TdxRibbonFormCaptionHelper.InitializeHelpers;
begin
  if not Supports(FOwner, IdxRibbonFormNonClientHelper, FRibbonHelper) then
    FRibbonHelper := nil;
end;

function TdxRibbonFormCaptionHelper.IsInCaptionArea(const P: TPoint): Boolean;
begin
  Result := (FFormCaptionRegions[rfrWindow] <> 0) and Valid;
  if Result then
  begin
    if FormData.State = wsMinimized then
      Result := True
    else
      Result := cxPtInRegion(FFormCaptionRegions[rfrNCHitTest], Control.ScreenToClient(P));
  end;
end;

function TdxRibbonFormCaptionHelper.IsRibbonHelpButtonPlacedOnCaption: Boolean;
begin
  Result := RibbonHelper.HasHelpButton and (RibbonHelper.GetRibbonStyle = rs2013) and
    (Form <> nil) and not (biHelp in TCustomFormAccess(Form).BorderIcons) and
    not UseAeroNCPaint(FormData);
end;

procedure TdxRibbonFormCaptionHelper.BufferedDrawCaption(ADestCanvas: TcxCanvas; const ACaption: TCaption);
var
  R1, R2: HRGN;
begin
  ADestCanvas.SaveDC;
  try
    FBitmap.Clear;
    RibbonHelper.DrawRibbonFormCaption(FBitmap.cxCanvas, FFormCaptionDrawBounds, ACaption, FormData);
    DrawBorderIcons(FBitmap.cxCanvas);
    if FormData.State <> wsMinimized then
    begin
      R1 := GetClipRegion(ADestCanvas.Handle);
      R2 := GetFormCaptionRegionsForDC(ADestCanvas.Handle, rfrClient);
      CombineRgn(R2, R2, R1, RGN_AND);
      SelectClipRgn(ADestCanvas.Handle, R2);
      DeleteObject(R1);
      DeleteObject(R2);
    end;
    BitBlt(ADestCanvas.Handle, 0, 0, FBitmap.Width, FBitmap.Height,
      FBitmap.cxCanvas.Handle, 0, 0, SRCCOPY);
  finally
    ADestCanvas.RestoreDC;
  end;
end;

procedure TdxRibbonFormCaptionHelper.DrawWindowBorders(ACanvas: TcxCanvas);
begin
  RibbonHelper.DrawRibbonFormBorders(ACanvas, FormData, GetWindowBordersWidth);
end;

procedure TdxRibbonFormCaptionHelper.DrawWindowCaption(ACanvas: TcxCanvas;
  const ACaption: TCaption);
var
  ASaveIndex: Integer;
begin
  if Valid then
  begin
    if FIsClientDrawing or UseAeroNCPaint(FormData) then
    begin
      ASaveIndex := SaveDC(Control.Canvas.Handle);
      SelectClipRgn(Control.Canvas.Handle, FFormCaptionRegions[rfrClient]);
      RibbonHelper.DrawRibbonFormCaption(Control.Canvas,
        FFormCaptionDrawBounds, ACaption, FormData);
      DrawBorderIcons(Control.Canvas);
      RestoreDC(Control.Canvas.Handle, ASaveIndex);
      ExcludeCaptionRgn(Control.Canvas.Handle);
    end
    else
      if FormData.State = wsMinimized then
        BufferedDrawCaption(ACanvas, ACaption)
      else
      begin
        BufferedDrawCaption(Control.ActiveCanvas, ACaption);
        ExcludeCaptionRgn(Control.ActiveCanvas.Handle);
      end;
  end;
end;

procedure TdxRibbonFormCaptionHelper.GetDesignInfo(out ALoadedHeight, ACurrentHeight: Integer);
begin
  ALoadedHeight := RibbonHelper.GetRibbonLoadedHeight;
  ACurrentHeight := Control.Height;
end;

procedure TdxRibbonFormCaptionHelper.CalculateBorderIcons;
begin
  if UseAeroNCPaint(FormData) then
  begin
    if FormData.Handle <> 0 then
    begin
      DwmGetWindowAttribute(FormData.Handle, DWMWA_CAPTION_BUTTON_BOUNDS, @FBorderIconsArea, SizeOf(FBorderIconsArea));
      OffsetRect(FBorderIconsArea, -GetDefaultWindowBordersWidth(FormData.Handle).Right, 0);
    end;
  end
  else
    CalculateBorderIconsForCustomSkinning;
end;

procedure TdxRibbonFormCaptionHelper.CalculateBorderIconsForCustomSkinning;

  function CalculateBorderIconsArea: TRect;
  var
    AIconSize: TSize;
    AIndent: Integer;
  begin
    AIconSize := CalculateBorderIconSize(rbiSystemMenu);
    AIndent := (GetWindowCaptionHeight - AIconSize.cy) div 2;
    Result := cxRectSetTop(GetClientRect, AIndent, AIconSize.cy);
    if (FormData.Handle <> 0) and (FormData.State = wsMinimized) then
      Dec(Result.Bottom);
    Dec(Result.Right, Max(0, AIndent - GetWindowBordersWidth.Right));
    Inc(Result.Left, Max(0, AIndent - GetWindowBordersWidth.Left));
  end;

  procedure PlaceBorderIcon(AIcon: TdxRibbonBorderIcon; var R: TRect);
  begin
    FBorderIconBounds[AIcon] := cxNullRect;
    if (AIcon in FBorderIcons) and (AIcon <> rbiAutoHideModeShowUI) then
    begin
      R := cxRectSetRight(R, R.Right, CalculateBorderIconSize(AIcon).cx);
      FBorderIconBounds[AIcon] := R;
      R.Right := R.Left;
    end;
  end;

const
  IconsOrder: array[Boolean, 0..4] of TdxRibbonBorderIcon = (
    (rbiSystemMenu, rbiHelp, rbiMaximize, rbiMinimize, rbiAutoHide),
    (rbiSystemMenu, rbiMaximize, rbiMinimize, rbiAutoHide, rbiHelp)
  );
var
  AIs2013Style: Boolean;
  I: Integer;
  R: TRect;
begin
  FBorderIconsArea := CalculateBorderIconsArea;

  R := BorderIconsArea;
  AIs2013Style := RibbonHelper.GetRibbonStyle = rs2013;
  for I := Low(IconsOrder[AIs2013Style]) to High(IconsOrder[AIs2013Style]) do
    PlaceBorderIcon(IconsOrder[AIs2013Style][I], R);

  if rbiAutoHideModeShowUI in FBorderIcons then
  begin
    R.Left := BorderIconsArea.Left;
    FBorderIconBounds[rbiAutoHideModeShowUI] := R;
  end
  else
  begin
    FBorderIconBounds[rbiAutoHideModeShowUI] := cxNullRect;
    FBorderIconsArea.Left := R.Right;
    if HasSysMenu then
      FBorderIconsArea.Left := Max(BorderIconsArea.Left, SysMenuIconBounds.Right + 2);
  end;
end;

function TdxRibbonFormCaptionHelper.CalculateBorderIconSize(ABorderIcon: TdxRibbonBorderIcon): TSize;
var
  AIsToolWindow: Boolean;
begin
  AIsToolWindow := (FormData.Handle = 0) or (FormData.Border in [bsToolWindow, bsSizeToolWin]);
  if AIsToolWindow then
    Result := cxSize(GetSystemMetrics(SM_CXSMSIZE), GetSystemMetrics(SM_CYSMSIZE))
  else
    Result := cxSize(GetSystemMetrics(SM_CXSIZE), GetSystemMetrics(SM_CYSIZE));

  RibbonHelper.AdjustRibbonFormBorderIconSize(
    GetDrawIconFromBorderIcon(ABorderIcon), AIsToolWindow, Result);
end;

procedure TdxRibbonFormCaptionHelper.CalculateFormCaption;
begin
  DestroyCaptionRegions;
  FFormCaptionRegions[rfrWindow] := GetWindowCaptionRegion;
  FFormCaptionRegions[rfrClient] := GetClientCaptionRegion;
  FFormCaptionRegions[rfrNCHitTest] := GetNCHitTestRegion;
  FFormCaptionDrawBounds := GetFormCaptionDrawBounds;

  if Abs(cxRectWidth(FFormCaptionDrawBounds)) > 10000 then
  begin
    FFormCaptionDrawBounds.Left := 0;
    FFormCaptionDrawBounds := GetFormCaptionDrawBounds;
  end;

  FBitmap.SetSize(cxRectWidth(FFormCaptionDrawBounds), GetWindowCaptionHeight);
end;

function TdxRibbonFormCaptionHelper.CanProcessFormCaptionHitTest(X, Y: Integer): Boolean;
begin
  Result := (FFormCaptionRegions[rfrNCHitTest] <> 0) and (GetCapture = 0);
  if Result then
    Result := cxPtInRegion(FFormCaptionRegions[rfrNCHitTest], Control.ScreenToClient(Point(X, Y)));
end;

procedure TdxRibbonFormCaptionHelper.CalculateSysMenuIconBounds;
var
  AIconOffsetX: Integer;
  AIconOffsetY: Integer;
  AIconSize: Integer;
  AQATBounds: TRect;
begin
  FSysMenuBounds := cxEmptyRect;
  FSysMenuIconBounds := cxEmptyRect;
  if HasSysMenu then
  begin
    AIconSize := GetSystemMetrics(SM_CYSMICON);
    FSysMenuBounds := GetWindowSystemMenuBounds;

    AIconOffsetX := Max(2, GetSystemMetrics(SM_CXSIZEFRAME) - GetWindowBordersWidth.Left);
    AQATBounds := RibbonHelper.GetRibbonQATNonClientAreaBounds;
    if cxRectIsEmpty(AQATBounds) then
      AIconOffsetY := GetDefaultWindowBordersWidth(FormData.Handle).Top + (cxRectHeight(FSysMenuBounds) - AIconSize) div 2 - 2
    else
      AIconOffsetY := (AQATBounds.Top + AQATBounds.Bottom - AIconSize) div 2;

    FSysMenuIconBounds := cxRectBounds(AIconOffsetX, AIconOffsetY, AIconSize, AIconSize);
    if FormData.State = wsMinimized then
      OffsetRect(FSysMenuIconBounds, 4, 4);
  end;
end;

procedure TdxRibbonFormCaptionHelper.CalculateTextBounds;
begin
  FTextBounds := GetClientRect;
  Inc(FTextBounds.Top);
  FTextBounds.Left := FSysMenuIconBounds.Right;
  FTextBounds.Bottom := GetWindowCaptionHeight;
  if FBorderIcons <> [] then
    FTextBounds.Right := FBorderIconsArea.Left;
end;

function TdxRibbonFormCaptionHelper.CanCalculate: Boolean;
begin
  Result := (FFormData.Handle <> 0) and
    (not IsIconic(FFormData.Handle) or IsShowMinimizedOnDesktop(FFormData.Handle));
end;

procedure TdxRibbonFormCaptionHelper.DrawBorderIcons(ACanvas: TcxCanvas);
var
  I: TdxRibbonBorderIcon;
begin
  if not UseAeroNCPaint(FormData) then
  begin
    ACanvas.SaveClipRegion;
    try
      ACanvas.IntersectClipRect(BorderIconsArea);
      for I := Low(TdxRibbonBorderIcon) to High(TdxRibbonBorderIcon) do
        DrawWindowBorderIcon(ACanvas, FBorderIconBounds[I], I, GetBorderIconState(I));
    finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

procedure TdxRibbonFormCaptionHelper.DrawRibbonFormBackground(DC: HDC; const ARect: TRect);
begin
  RibbonHelper.DrawRibbonFormBackground(DC, ARect);
end;

procedure TdxRibbonFormCaptionHelper.ExcludeCaptionRgn(DC: HDC);
var
  R1, R2: HRGN;
begin
  if FFormCaptionRegions[rfrClient] = 0 then Exit;
  R1 := GetClipRegion(DC);
  R2 := GetFormCaptionRegionsForDC(DC, rfrClient);
  CombineRgn(R1, R1, R2, RGN_DIFF);
  SelectClipRgn(DC, R1);
  DeleteObject(R1);
  DeleteObject(R2);
end;

function TdxRibbonFormCaptionHelper.GetBorderIconState(AIcon: TdxRibbonBorderIcon): TdxRibbonBorderIconState;
const
  InactiveMap: array[Boolean] of TdxRibbonBorderIconState = (rbisInactive, rbisHotInactive);
  PressedMap: array[Boolean] of TdxRibbonBorderIconState = (rbisHot, rbisPressed);
begin
  if not FormData.Active then
    Result := InactiveMap[BorderIconsMap[AIcon] = HotBorderIcon]
  else
    if BorderIconsMap[AIcon] = HotBorderIcon then
      Result := PressedMap[PressedBorderIcon = HotBorderIcon]
    else
      Result := rbisNormal;
end;

function TdxRibbonFormCaptionHelper.GetBarManager: TdxBarManager;
begin
  Result := RibbonHelper.GetBarManager;
end;

function TdxRibbonFormCaptionHelper.GetBorderIconAtPoint(const P: TPoint): TdxRibbonBorderIcon;
var
  I: TdxRibbonBorderIcon;
begin
  Result := rbiSystemMenu;
  for I := Low(TdxRibbonBorderIcon) to High(TdxRibbonBorderIcon) do
    if cxRectPtIn(FBorderIconBounds[I], P) then
    begin
      Result := I;
      Break;
    end;
end;

function TdxRibbonFormCaptionHelper.GetClientRect: TRect;
begin
  if FormData.Handle = 0 then
    Result := Control.ClientRect
  else
    if FormData.State = wsMinimized then
    begin
      Result := FormData.Bounds;
      Dec(Result.Right, GetWindowBordersWidth.Left);
    end
    else
      Result := cxGetClientRect(Form.Handle);
end;

function TdxRibbonFormCaptionHelper.GetDrawIconFromBorderIcon(AIcon: TdxRibbonBorderIcon): TdxRibbonBorderDrawIcon;
begin
  case AIcon of
    rbiSystemMenu:
      Result := rbdiClose;
    rbiAutoHide:
      Result := rbdiAutoHide;
    rbiAutoHideModeShowUI:
      Result := rbdiAutoHideModeShowUI;

    rbiMinimize:
      if FormData.State = wsMinimized then
        Result := rbdiRestore
      else
        Result := rbdiMinimize;

    rbiMaximize:
      if FormData.State = wsMaximized then
        Result := rbdiRestore
      else
        Result := rbdiMaximize;

  else
    Result := rbdiHelp;
  end;
end;

function TdxRibbonFormCaptionHelper.GetForm: TCustomForm;
begin
  if Control.Owner is TCustomForm then
    Result := TCustomForm(Control.Owner)
  else
    Result := nil;
end;

function TdxRibbonFormCaptionHelper.GetFormCaptionRegionsForDC(
  DC: HDC; ARegionKind: TdxRibbonFormRegion): HRGN;
var
  AWindowOrg, AViewportOrg: TPoint;
begin
  Result := 0;
  if FFormCaptionRegions[ARegionKind] = 0 then Exit;
  Result := CreateRectRgnIndirect(cxEmptyRect);
  CombineRgn(Result, FFormCaptionRegions[ARegionKind], 0, RGN_COPY);
  GetWindowOrgEx(DC, AWindowOrg);
  GetViewportOrgEx(DC, AViewportOrg);
  OffsetRgn(Result, AViewportOrg.X - AWindowOrg.X, AViewportOrg.Y - AWindowOrg.Y);
end;

function TdxRibbonFormCaptionHelper.GetHandle: THandle;
begin
  Result := FOwner.Handle;
end;

function TdxRibbonFormCaptionHelper.GetIsValid: Boolean;
begin
  Result := FOwner.HandleAllocated and
   (FOwner.ComponentState * [{csDestroying,} csLoading] = []);
end;

function TdxRibbonFormCaptionHelper.HasSysMenu: Boolean;
begin
  Result := (TestWindowStyle(FormData.Handle, WS_SYSMENU) <> 0) and (FormData.Border in [bsSingle, bsSizeable]);
end;

function TdxRibbonFormCaptionHelper.IsBorderIconMouseEvent(
  const P: TPoint; out CP: TPoint; ACheckComposition: Boolean = True): Boolean;
begin
  CP := Control.ScreenToClient(P);
  Result := not (ACheckComposition and UseAeroNCPaint(FormData)) and cxRectPtIn(FBorderIconsArea, CP);
end;

function TdxRibbonFormCaptionHelper.GetWindowCaptionBounds: TRect;
var
  R: TRect;
begin
  Result := Control.ClientRect;
  if FormData.Handle <> 0 then
  begin
    Result := FormData.Bounds;
    if FormData.State = wsMaximized then
    begin
      R := GetDefaultWindowBordersWidth(FormData.Handle);
      Inc(Result.Left, R.Left);
      Inc(Result.Top, R.Top);
      Dec(Result.Right, R.Right);
    end;
  end;
  Result.Bottom := Result.Top + GetWindowCaptionHeight;
end;

function TdxRibbonFormCaptionHelper.GetWindowCaptionHeight: Integer;
begin
  if (FormData.Handle <> 0) and (FormData.State = wsMinimized) then
    Result := cxRectHeight(FormData.Bounds)
  else
    Result := RibbonHelper.GetRibbonFormCaptionHeight;
end;

function TdxRibbonFormCaptionHelper.GetWindowCaptionHeightForHiddenRibbon: Integer;
begin
  Result := RibbonHelper.GetRibbonFormCaptionHeightForHiddenRibbon;
end;

function TdxRibbonFormCaptionHelper.GetClientCaptionBounds: TRect;
var
  R: TRect;
begin
  if FormData.Handle <> 0 then
  begin
    Result := GetClientRect;
    R := GetWindowBordersWidth;
    Dec(Result.Left, R.Left);
    Dec(Result.Top, R.Top);
    Inc(Result.Right, R.Right);
  end
  else
    Result := Control.ClientRect;

  Result.Bottom := Result.Top + GetWindowCaptionHeight;
end;

function TdxRibbonFormCaptionHelper.GetClientCaptionRegion: HRGN;
var
  RW, B: TRect;
begin
  if FFormCaptionRegions[rfrWindow] = 0 then
  begin
    Result := 0;
    Exit;
  end;
  Result := CreateRectRgnIndirect(cxEmptyRect);
  CombineRgn(Result, FFormCaptionRegions[rfrWindow], 0, RGN_COPY);
  if (FormData.Handle <> 0) and (FormData.State <> wsMaximized) and GetWindowRect(FormData.Handle, RW) then
  begin
    OffsetRect(RW, -RW.Left, -RW.Top);
    B := GetWindowBordersWidth;
    dxCombineRectRegion(Result, 0, 0, B.Left, GetWindowCaptionHeight, RGN_DIFF); //exclude left border
    dxCombineRectRegion(Result, RW.Right - B.Right, 0, RW.Right, GetWindowCaptionHeight, RGN_DIFF); //exclude right border
    OffsetRgn(Result, -B.Left, -B.Top);
  end
end;

function TdxRibbonFormCaptionHelper.GetExtentedCaptionAreaRegion: HRGN;
begin
  if (FormData.Handle <> 0) and (FormData.State <> wsMinimized) then
    Result := RibbonHelper.GetRibbonFormExtendedCaptionAreaRegion
  else
    Result := 0;
end;

function TdxRibbonFormCaptionHelper.GetFormCaptionDrawBounds: TRect;
begin
  if (FormData.Handle <> 0) and (FormData.State = wsMinimized) then
  begin
    Result := GetClientRect;
    Inc(Result.Right, GetWindowBordersWidth.Left);
  end
  else
    Result := GetClientCaptionBounds;
end;

function TdxRibbonFormCaptionHelper.GetNCHitTestRegion: HRGN;

  procedure DoCombineRegion(AResultRegion, ASourceRegion: HRGN; AOperaion: Integer);
  begin
    if ASourceRegion <> 0 then
    begin
      CombineRgn(AResultRegion, AResultRegion, ASourceRegion, AOperaion);
      DeleteObject(ASourceRegion);
    end;
  end;

begin
  if FFormCaptionRegions[rfrClient] <> 0 then
  begin
    Result := CreateRectRgnIndirect(cxEmptyRect);
    CombineRgn(Result, FFormCaptionRegions[rfrClient], 0, RGN_COPY);
    if ApplicationMenuState <> ramsShownAsFullScreenFrame then
    begin
      DoCombineRegion(Result, GetNonClientAreaObjectsRegion, RGN_DIFF);
      DoCombineRegion(Result, GetExtentedCaptionAreaRegion, RGN_OR);
    end;
  end
  else
    Result := 0;
end;

function TdxRibbonFormCaptionHelper.GetNonClientAreaObjectsRegion: HRGN;
begin
  if (FormData.Handle <> 0) and (FormData.State <> wsMinimized) then
    Result := RibbonHelper.GetRibbonNonClientAreaObjectsRegion
  else
    Result := 0;
end;

function TdxRibbonFormCaptionHelper.GetWindowCaptionRegion: HRGN;
var
  RW: TRect;
begin
  if FormData.Handle = 0 then
  begin
    Result := 0;
    Exit;
  end;
  RW := FormData.Bounds;
  RW.Bottom := RW.Top + GetWindowCaptionHeight;
  Result := CreateRectRgnIndirect(RW);
end;

procedure TdxRibbonFormCaptionHelper.RepaintBorderIcons;
var
  ACanvas: TcxCanvas;
  DC: HDC;
begin
  if not Valid or UseAeroNCPaint(FormData) then Exit;
  if FormData.State = wsMinimized then
  begin
    DC := GetDCEx(FormData.Handle, 0, DCX_CACHE or DCX_CLIPSIBLINGS or DCX_WINDOW or DCX_VALIDATE);
    cxPaintCanvas.BeginPaint(DC);
    cxPaintCanvas.Canvas.Lock;
    try
      cxPaintCanvas.SetClipRegion(TcxRegion.Create(FBorderIconsArea), roSet);
      BufferedDrawCaption(cxPaintCanvas, '');
    finally
      cxPaintCanvas.Canvas.Unlock;
      cxPaintCanvas.EndPaint;
      ReleaseDC(FormData.Handle, DC);
    end;
  end
  else
  begin
    ACanvas := Control.ActiveCanvas;
    ACanvas.Canvas.Lock;
    try
      ACanvas.SaveClipRegion;
      ACanvas.SetClipRegion(TcxRegion.Create(FBorderIconsArea), roSet);
      BufferedDrawCaption(ACanvas, '');
      ACanvas.RestoreClipRegion;
    finally
      ACanvas.Canvas.Unlock;
    end;
  end;
end;

function TdxRibbonFormCaptionHelper.MouseDown(const P: TPoint; AButton: TMouseButton): Boolean;
var
  ALocalPoint: TPoint;
begin
  Result := Valid and (AButton = mbLeft) and IsBorderIconMouseEvent(P, ALocalPoint);
  if Result then
  begin
    PressedBorderIcon := BorderIconsMap[GetBorderIconAtPoint(ALocalPoint)];
    SetCapture(FormData.Handle);
    FWasCapture := True;
  end;
end;

function TdxRibbonFormCaptionHelper.MouseUp(const P: TPoint; AButton: TMouseButton): Boolean;
var
  AIcon: TdxRibbonBorderIcon;
  ALocalPoint: TPoint;
begin
  Result := False;
  if not Valid then Exit;

  if BarManager <> nil then
    BarManager.HideHint;
  case AButton of
    mbLeft:
      begin
        if IsBorderIconMouseEvent(P, ALocalPoint) and (PressedBorderIcon <> tbiNone) then
        begin
          Result := True;
          AIcon := GetBorderIconAtPoint(ALocalPoint);
          if BorderIconsMap[AIcon] = PressedBorderIcon then
            SendMessage(FormData.Handle, DXM_RIBBONFORM_SYSCOMMAND, Ord(AIcon), 0);
          PressedBorderIcon := tbiNone;
        end;
        if FWasCapture and (GetCapture = FormData.Handle) then
          ReleaseCapture;
      end;

    mbRight:
      if not IsBorderIconMouseEvent(P, ALocalPoint, False) and
        (TestWindowStyle(FormData.Handle, WS_SYSMENU or WS_CHILD) = WS_SYSMENU) then
      begin
        Result := True;
        SendMessage(FormData.Handle, DXM_BAR_SHOWSYSTEMMENU, 0, 0);
      end;
  end;
end;

procedure TdxRibbonFormCaptionHelper.MouseTimerHandler(Sender: TObject);

  function NeedRepaint(const AMousePos: TPoint; H: HWND): Boolean;
  var
    AClientPos: TPoint;
  begin
    AClientPos := dxMapWindowPoint(0, H, AMousePos);
    Result := not cxRectPtIn(FBorderIconsArea, AClientPos);
    if not Result then
    begin
      if FormData.State = wsMinimized then
        Result := WindowFromPoint(AMousePos) <> H
      else
        Result := RealChildWindowFromPoint(H, AClientPos) <> Handle;
    end;
  end;

begin
  if (FormData.Handle <> 0) and Valid then
  begin
    if NeedRepaint(GetMouseCursorPos, FormData.Handle) then
    begin
      StopMouseTimer;
      HotBorderIcon := tbiNone;
    end;
  end
  else
    StopMouseTimer;
end;

procedure TdxRibbonFormCaptionHelper.StartMouseTimer;
begin
  if FMouseTimer = nil then
  begin
    FMouseTimer := TcxTimer.Create(nil);
    FMouseTimer.Interval := 20;
    FMouseTimer.OnTimer := MouseTimerHandler;
  end;
end;

procedure TdxRibbonFormCaptionHelper.StopMouseTimer;
begin
  FreeAndNil(FMouseTimer);
end;

procedure TdxRibbonFormCaptionHelper.WMEraseBkgnd(var Message: TWMEraseBkgnd);
var
  ASaveIndex: Integer;
begin
  if Message.DC <> 0 then
  begin
    ASaveIndex := SaveDC(Message.DC);
    try
      ExcludeCaptionRgn(Message.DC);
      inherited;
    finally
      RestoreDC(Message.DC, ASaveIndex);
    end;
  end
  else
    inherited;
end;

procedure TdxRibbonFormCaptionHelper.WMNCHitTest(var Message: TWMNCHitTest);
begin
  if CanProcessFormCaptionHitTest(Message.XPos, Message.YPos) then
    Message.Result := HTTRANSPARENT
  else
    OriginalWndProc(Message);
end;

procedure TdxRibbonFormCaptionHelper.WMPaint(var Message: TWMPaint);
begin
  FIsClientDrawing := True;
  OriginalWndProc(Message);
  FIsClientDrawing := False;
end;

procedure TdxRibbonFormCaptionHelper.WMSize(var Message: TWMSize);
begin
  Calculate;
  OriginalWndProc(Message);
end;

procedure TdxRibbonFormCaptionHelper.WMShowWindow(var Message: TMessage);
begin
  FHotBorderIcon := tbiNone;
  FPressedBorderIcon := tbiNone;
  if WordBool(Message.wParam) then
    Calculate;
  OriginalWndProc(Message);
end;

procedure TdxRibbonFormCaptionHelper.OriginalWndProc(var Message);
begin
  FOldWndProc(TMessage(Message));
end;

procedure TdxRibbonFormCaptionHelper.UpdateCaptionArea(ACanvas: TcxCanvas = nil);
begin
  if ACanvas = nil then
    DrawWindowCaption(nil, '')
  else
    BufferedDrawCaption(ACanvas, '');
end;

procedure TdxRibbonFormCaptionHelper.UpdateNonClientArea;
begin
  RibbonHelper.UpdateNonClientArea;
end;

procedure TdxRibbonFormCaptionHelper.UpdateWindowBorderIcons(const AIcons: TdxRibbonBorderIcons);
begin
  if FBorderIcons <> AIcons then
  begin
    FHotBorderIcon := tbiNone;
    FPressedBorderIcon := tbiNone;
    FBorderIcons := AIcons;
    Calculate;
  end;
end;

procedure TdxRibbonFormCaptionHelper.DestroyCaptionRegions;
var
  I: TdxRibbonFormRegion;
begin
  for I := Low(TdxRibbonFormRegion) to High(TdxRibbonFormRegion) do
    if FFormCaptionRegions[I] <> 0 then
    begin
      DeleteObject(FFormCaptionRegions[I]);
      FFormCaptionRegions[I] := 0;
    end;
end;

procedure TdxRibbonFormCaptionHelper.WndProc(var Message: TMessage);
begin
  if Control.IsDesigning then
    OriginalWndProc(Message)
  else
  begin
    case Message.Msg of
      WM_SIZE:
        WMSize(TWMSize(Message));
      WM_NCHITTEST:
        WMNCHitTest(TWMNCHitTest(Message));
      WM_ERASEBKGND:
        WMEraseBkgnd(TWMEraseBkgnd(Message));
      WM_PAINT:
        WMPaint(TWMPaint(Message));
      WM_SHOWWINDOW:
        WMShowWindow(Message);
      else
        OriginalWndProc(Message);
    end;
  end;
end;

function TdxRibbonFormCaptionHelper.CreateHintViewInfo(const AHintText, AShortCut: string): TdxBarCustomHintViewInfo;
begin
  Result := dxBarCreateScreenTipViewInfo(BarManager, AHintText, AShortCut, nil, RibbonHelper.GetBarPainter);
end;

function TdxRibbonFormCaptionHelper.DoHint(var ANeedDeactivate: Boolean; out AHintText, AShortCut: string): Boolean;
begin
  AHintText := '';
  AShortCut := '';
  ANeedDeactivate := False;

  case HotBorderIcon of
    tbiSystemMenu:
      AHintText := cxGetResourceString(@dxSBAR_RIBBONFORM_CLOSE);
    tbiHelp:
      AHintText := cxGetResourceString(@dxSBAR_RIBBONFORM_HELP);
    tbiAutoHide:
      AHintText := cxGetResourceString(@dxSBAR_RIBBONFORM_FULLSCREEN);

    tbiMaximize:
      if FormData.State = wsMaximized then
        AHintText := cxGetResourceString(@dxSBAR_RIBBONFORM_RESTOREDOWN)
      else
        AHintText := cxGetResourceString(@dxSBAR_RIBBONFORM_MAXIMIZE);

    tbiMinimize:
      if FormData.State = wsMinimized then
        AHintText := cxGetResourceString(@dxSBAR_RIBBONFORM_RESTOREUP)
      else
        AHintText := cxGetResourceString(@dxSBAR_RIBBONFORM_MINIMIZE);
  end;
  Result := AHintText <> '';
end;

function TdxRibbonFormCaptionHelper.GetEnabled: Boolean;
begin
  Result := True;
end;

function TdxRibbonFormCaptionHelper.GetHintPosition(const ACursorPos: TPoint; AHeight: Integer): TPoint;
begin
  Result := cxPoint(ACursorPos.X, ACursorPos.Y + dxRibbonHintOffset);
end;

procedure TdxRibbonFormCaptionHelper.SetHotBorderIcon(AValue: TdxRibbonTrackedBorderIcon);
begin
  if FHotBorderIcon <> AValue then
  begin
    FHotBorderIcon := AValue;
    if BarManager <> nil then
    begin
      if HotBorderIcon <> tbiNone then
        BarManager.ActivateHint(True, '', Self)
      else
        BarManager.HideHint;
    end;
    RepaintBorderIcons;
  end;
end;

procedure TdxRibbonFormCaptionHelper.SetPressedBorderIcon(AValue: TdxRibbonTrackedBorderIcon);
begin
  if FPressedBorderIcon <> AValue then
  begin
    FPressedBorderIcon := AValue;
    RepaintBorderIcons;
  end;
end;

end.
