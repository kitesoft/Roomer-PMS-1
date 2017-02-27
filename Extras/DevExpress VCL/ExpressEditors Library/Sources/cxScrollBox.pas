{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{       ExpressEditors                                               }
{                                                                    }
{       Copyright (c) 1998-2014 Developer Express Inc.               }
{       ALL RIGHTS RESERVED                                          }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSEDITORS AND ALL                }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY. }
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

unit cxScrollBox;

{$I cxVer.inc}

interface

uses
  Types, SysUtils, Windows, Messages, Classes, Controls, Forms, StdCtrls,
  cxClasses, cxControls, cxGraphics, cxLookAndFeels, cxLookAndFeelPainters,
  cxScrollBar, dxFading, dxCoreClasses;

type
  TcxCustomScrollBox = class;

  { TcxScrollBoxScrollBarOptions }

  TcxScrollBoxScrollBarOptions = class(TPersistent)
  private
    FIncrement: TScrollBarInc;
    FMargin: Word;
    FKind: TScrollBarKind;
    FPosition: Integer;
    FRange: Integer;
    FScrollBox: TcxCustomScrollBox;
    FTracking: Boolean;
    FVisible: Boolean;
    function GetAutoScroll: Boolean;
    function GetPageSize: Integer;
    function IsRangeStored: Boolean;
    procedure CheckPosition(var APosition: Integer);
    procedure SetIncrement(Value: TScrollBarInc);
    procedure SetMargin(Value: Word);
    procedure SetPosition(Value: Integer);
    procedure SetRange(Value: Integer);
    procedure SetVisible(Value: Boolean);
    procedure UpdateRange(ARange: Integer);
  protected
    procedure AdjustAutoRange(AControl: TControl; var ARange, AAlignMargin: Integer);
    procedure CalculateAutoRange;
    procedure Changed;
    function GetMaxPosition: Integer;
    procedure Scroll(ACode: TScrollCode; var APosition: Integer);

    function IsVisible: Boolean; virtual;

    property AutoScroll: Boolean read GetAutoScroll;
    property PageSize: Integer read GetPageSize;
    property ScrollBox: TcxCustomScrollBox read FScrollBox;
  public
    constructor Create(AScrollBox: TcxCustomScrollBox; AKind: TScrollBarKind); virtual;
    procedure Assign(Source: TPersistent); override;
    //
    property Kind: TScrollBarKind read FKind;
  published
    property Increment: TScrollBarInc read FIncrement write SetIncrement default 8;
    property Margin: Word read FMargin write SetMargin default 0;
    property Position: Integer read FPosition write SetPosition default 0;
    property Range: Integer read FRange write SetRange stored IsRangeStored;
    property Tracking: Boolean read FTracking write FTracking default False;
    property Visible: Boolean read FVisible write SetVisible default True;
  end;
  TcxScrollBoxScrollBarOptionsClass = class of TcxScrollBoxScrollBarOptions;

  { TcxCustomScrollBoxViewInfo }

  TcxCustomScrollBoxViewInfo = class
  private
    FClientRect: TRect;
    FScrollBox: TcxCustomScrollBox;
    function GetPainter: TcxCustomLookAndFeelPainter;
  public
    constructor Create(AScrollBox: TcxCustomScrollBox); virtual;
    procedure Calculate(const ABounds: TRect); virtual;
    procedure CalculateClientRect(const ABounds: TRect); virtual;

    procedure Paint(ACanvas: TcxCanvas); virtual;

    property ClientRect: TRect read FClientRect;
    property Painter: TcxCustomLookAndFeelPainter read GetPainter;
    property ScrollBox: TcxCustomScrollBox read FScrollBox;
  end;
  TcxCustomScrollBoxViewInfoClass = class of TcxCustomScrollBoxViewInfo;

  TcxControlNCScrollBars = class(TcxControlScrollBars)
  protected
    function CreateScrollBar(AKind: TScrollBarKind): TObject; override;
    function CreateSizeGrip: TObject; override;
  end;

  { TcxCustomScrollBox }

  TcxCustomScrollBox = class(TcxControl, IdxSkinSupport)
  private
    FAutoScroll: Boolean;
    FViewInfo: TcxCustomScrollBoxViewInfo;

    FHorzScrollBar: TcxScrollBoxScrollBarOptions;
    FVertScrollBar: TcxScrollBoxScrollBarOptions;

    FIsScrollBarsUpdating: Boolean;
    FTransparent: Boolean;

    procedure CalculateAutoRange;
    procedure SetAutoScroll(Value: Boolean);
    procedure SetHorzScrollBar(Value: TcxScrollBoxScrollBarOptions);
    procedure SetTransparent(const Value: Boolean);
    procedure SetVertScrollBar(Value: TcxScrollBoxScrollBarOptions);

    procedure CMEnabledChanged(var Message: TMessage); message CM_ENABLEDCHANGED;
    procedure CMFocusChanged(var Message: TCMFocusChanged); message CM_FOCUSCHANGED;
    procedure WMNCCalcSize(var Message: TWMNCCalcSize); message WM_NCCALCSIZE;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
  protected
    procedure AdjustClientRect(var Rect: TRect); override;
    procedure AlignControls(AControl: TControl; var Rect: TRect); override;
    function AllowPan(AScrollKind: TScrollBarKind): Boolean; override;
    function CanFocusOnClick: Boolean; override;
    function CreateScrollBarOptions(AKind: TScrollBarKind): TcxScrollBoxScrollBarOptions; virtual;
    procedure DoPaint; override;
    procedure DoUpdateScrollBars; override;
    procedure EraseBackground(ACanvas: TcxCanvas; const ARect: TRect); override;
    function GetBounds: TRect; override;
    function GetClientOffsets: TRect; override;
    function GetMainScrollBarsClass: TcxControlCustomScrollBarsClass; override;
    function GetMouseWheelScrollingKind: TcxMouseWheelScrollingKind; override;
    function HasNonClientArea: Boolean; override;
    procedure InitScrollBarsParameters; override;
    function IsTransparentBackground: Boolean; override;
    procedure LookAndFeelChanged(Sender: TcxLookAndFeel; AChangedValues: TcxLookAndFeelValues); override;
    procedure PaintNonClientArea(ACanvas: TcxCanvas); override;

    procedure Scroll(AScrollBarKind: TScrollBarKind; AScrollCode: TScrollCode; var AScrollPos: Integer); override;
    procedure AdvancedScrollBy(ADeltaX, ADeltaY: Integer);
    procedure WndProc(var Message: TMessage); override;

    function DoWndProc(var Message: TMessage): Boolean; virtual;
    function GetViewInfoClass: TcxCustomScrollBoxViewInfoClass; virtual;

    procedure RefreshNonClientArea;

    property BorderStyle default cxcbsDefault;
    property TabStop default False;
    property ViewInfo: TcxCustomScrollBoxViewInfo read FViewInfo;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    procedure MakeVisible(AControl: TWinControl);

    property AutoScroll: Boolean read FAutoScroll write SetAutoScroll default True;
    property HorzScrollBar: TcxScrollBoxScrollBarOptions read FHorzScrollBar write SetHorzScrollBar;
    property LookAndFeel;
    property Transparent: Boolean read FTransparent write SetTransparent default False;
    property VertScrollBar: TcxScrollBoxScrollBarOptions read FVertScrollBar write SetVertScrollBar;
  end;

  { TcxScrollBox }

  TcxScrollBox = class(TcxCustomScrollBox)
  published
    property Align;
    property Anchors;
    property AutoScroll;
    property BorderStyle;
    property Color;
    property Cursor;
    property Enabled;
    property Font;
    property HelpContext;
    property HelpKeyword;
    property HelpType;
    property HorzScrollBar;
    property LookAndFeel;
    property ParentColor;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property TabOrder;
    property TabStop;
    property Transparent;
    property VertScrollBar;
    property Visible;
    property OnCanResize;
    property OnClick;
    property OnConstrainedResize;
    property OnContextPopup;
    property OnDblClick;
    property OnEnter;
    property OnExit;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseWheel;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnResize;
  end;

implementation

uses
  Math, Graphics, cxGeometry, cxContainer;

function ScrollBarPartToScrolCode(APart: TcxScrollBarPart): TScrollCode;
const
  ResultMap: array[TcxScrollBarPart] of TScrollCode =
    (scPosition, scLineUp, scLineDown, scTrack, scPageUp, scPageDown);
begin
  Result := ResultMap[APart];
end;

{ TcxScrollBoxScrollBarOptions }

constructor TcxScrollBoxScrollBarOptions.Create(AScrollBox: TcxCustomScrollBox; AKind: TScrollBarKind);
begin
  inherited Create;
  FKind := AKind;
  FScrollBox := AScrollBox;
  FVisible := True;
  FIncrement := 8;
end;

procedure TcxScrollBoxScrollBarOptions.AdjustAutoRange(
  AControl: TControl; var ARange, AAlignMargin: Integer);

  procedure AdjustHorizontalAutoRange(
    AControl: TControl; var ARange, AAlignMargin: Integer);
  begin
    if AControl.Align = alRight then
      Inc(AAlignMargin, AControl.Width)
    else
      if (AControl.Align = alLeft) or (AControl.Align = alNone) and
         (AControl.Anchors * [akLeft, akRight] = [akLeft])
      then
        ARange := Max(ARange, Position + AControl.BoundsRect.Right);
  end;

  procedure AdjustVerticalAutoRange(
    AControl: TControl; var ARange, AAlignMargin: Integer);
  begin
    if AControl.Align = alBottom then
      Inc(AAlignMargin, AControl.Height)
    else
      if (AControl.Align = alTop) or (AControl.Align = alNone) and
         (AControl.Anchors * [akTop, akBottom] = [akTop])
      then
        ARange := Max(ARange, Position + AControl.BoundsRect.Bottom);
  end;

begin
  if AControl.Visible and not ScrollBox.IsInternalControl(AControl) then
  begin
    if Kind = sbHorizontal then
      AdjustHorizontalAutoRange(AControl, ARange, AAlignMargin)
    else
      AdjustVerticalAutoRange(AControl, ARange, AAlignMargin);
  end;
end;

procedure TcxScrollBoxScrollBarOptions.Assign(Source: TPersistent);
begin
  if Source is TcxScrollBoxScrollBarOptions then
  begin
    Range := TcxScrollBoxScrollBarOptions(Source).Range;
    Increment := TcxScrollBoxScrollBarOptions(Source).Increment;
    Position := TcxScrollBoxScrollBarOptions(Source).Position;
    Visible := TcxScrollBoxScrollBarOptions(Source).Visible;
  end;
end;

procedure TcxScrollBoxScrollBarOptions.CalculateAutoRange;
var
  ARange, AAlignMargin: Integer;
  I: Integer;
begin
  if AutoScroll then
  begin
    ARange := 0;
    AAlignMargin := 0;
    for I := 0 to ScrollBox.ControlCount - 1 do
      AdjustAutoRange(ScrollBox.Controls[I], ARange, AAlignMargin);
    UpdateRange(ARange + AAlignMargin + Margin);
  end;
end;

procedure TcxScrollBoxScrollBarOptions.Changed;
begin
  ScrollBox.UpdateScrollBars;
end;

function TcxScrollBoxScrollBarOptions.GetMaxPosition: Integer;
begin
  if IsVisible then
    Result := Max(0, Range - PageSize)
  else
    Result := 0;
end;

procedure TcxScrollBoxScrollBarOptions.CheckPosition(var APosition: Integer);
begin
  APosition := EnsureRange(APosition, 0, GetMaxPosition);
end;

function TcxScrollBoxScrollBarOptions.IsRangeStored: Boolean;
begin
  Result := not AutoScroll;
end;

procedure TcxScrollBoxScrollBarOptions.Scroll(ACode: TScrollCode; var APosition: Integer);
begin
  if Tracking or ScrollBox.IsGestureScrolling or (ACode <> scTrack) then
    Position := APosition;
  APosition := Position;
end;

function TcxScrollBoxScrollBarOptions.IsVisible: Boolean;
begin
  Result := Visible and (Range > PageSize);
end;

procedure TcxScrollBoxScrollBarOptions.UpdateRange(ARange: Integer);
begin
  FRange := Max(ARange, 0);
  Changed;
end;

function TcxScrollBoxScrollBarOptions.GetAutoScroll: Boolean;
begin
  Result := ScrollBox.AutoScroll;
end;

function TcxScrollBoxScrollBarOptions.GetPageSize: Integer;
begin
  if Kind = sbHorizontal then
    Result := cxRectWidth(ScrollBox.ViewInfo.ClientRect)
  else
    Result := cxRectHeight(ScrollBox.ViewInfo.ClientRect);
end;

procedure TcxScrollBoxScrollBarOptions.SetIncrement(Value: TScrollBarInc);
begin
  if FIncrement <> Value then
  begin
    FIncrement := Value;
    Changed;
  end;
end;

procedure TcxScrollBoxScrollBarOptions.SetMargin(Value: Word);
begin
  if FMargin <> Value then
  begin
    FMargin := Value;
    Changed;
  end;
end;

procedure TcxScrollBoxScrollBarOptions.SetPosition(Value: Integer);
var
  ADelta: Integer;
begin
  if csReading in ScrollBox.ComponentState then
    FPosition := Value
  else
  begin
    CheckPosition(Value);
    if Position <> Value then
    begin
      ScrollBox.LockScrollBars;
      ADelta := Position - Value;
      FPosition := Value;
      ScrollBox.AdvancedScrollBy(ADelta * Ord(Kind = sbHorizontal), ADelta * Ord(Kind <> sbHorizontal));
      ScrollBox.Modified;
      Changed;
      ScrollBox.UnlockScrollBars;
    end;
  end;
end;

procedure TcxScrollBoxScrollBarOptions.SetRange(Value: Integer);
begin
  ScrollBox.AutoScroll := False;
  UpdateRange(Value);
end;

procedure TcxScrollBoxScrollBarOptions.SetVisible(Value: Boolean);
begin
  if Visible <> Value then
  begin
    FVisible := Value;
    Changed;
  end;
end;

{ TcxCustomScrollBoxViewInfo }

constructor TcxCustomScrollBoxViewInfo.Create(AScrollBox: TcxCustomScrollBox);
begin
  inherited Create;
  FScrollBox := AScrollBox; 
end;

procedure TcxCustomScrollBoxViewInfo.Calculate(const ABounds: TRect);
begin
  CalculateClientRect(ABounds);
end;

procedure TcxCustomScrollBoxViewInfo.CalculateClientRect(const ABounds: TRect);
var
  ABorderSize: Integer;
  AHorzScrollBarVisible: Boolean;
begin
  FClientRect := ABounds;
  ABorderSize := ScrollBox.BorderSize;
  FClientRect := cxRectInflate(FClientRect, -ABorderSize, -ABorderSize);
  AHorzScrollBarVisible := ScrollBox.HorzScrollBar.IsVisible;
  if AHorzScrollBarVisible then
    Dec(FClientRect.Bottom, GetSystemMetrics(SM_CXVSCROLL));
  if ScrollBox.VertScrollBar.IsVisible then
  begin
    Dec(FClientRect.Right, GetSystemMetrics(SM_CYHSCROLL));
    if not AHorzScrollBarVisible and ScrollBox.HorzScrollBar.IsVisible then
      Dec(FClientRect.Bottom, GetSystemMetrics(SM_CXVSCROLL));
  end;
end;

procedure TcxCustomScrollBoxViewInfo.Paint(ACanvas: TcxCanvas);
begin
  if ScrollBox.Transparent then
    cxDrawTransparentControlBackground(ScrollBox, ACanvas, ClientRect, cxNullPoint)
  else
    Painter.DrawScrollBoxBackground(ACanvas, ScrollBox.ClientRect, ScrollBox.Color);
end;

function TcxCustomScrollBoxViewInfo.GetPainter: TcxCustomLookAndFeelPainter;
begin
  Result := ScrollBox.LookAndFeelPainter;
end;

{ TcxControlNCScrollBars }

function TcxControlNCScrollBars.CreateScrollBar(AKind: TScrollBarKind): TObject;
begin
  Result := inherited CreateScrollBar(AKind);
  (Result as TcxControlScrollBarHelper).IsNonClient := True;
end;

function TcxControlNCScrollBars.CreateSizeGrip: TObject;
begin
  Result := inherited CreateSizeGrip;
  (Result as TcxSizeGripHelper).IsNonClient := True;
end;

{ TcxCustomScrollBox }

constructor TcxCustomScrollBox.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  TabStop := False;
  ControlStyle := ControlStyle + [csAcceptsControls, csOpaque, csCaptureMouse, csClickEvents,
    csSetCaption, csDoubleClicks];
  FHorzScrollBar := CreateScrollBarOptions(sbHorizontal);
  FVertScrollBar := CreateScrollBarOptions(sbVertical);
  FViewInfo := GetViewInfoClass.Create(Self);
  Width := 185;
  Height := 41;
  BorderStyle := cxcbsDefault;
  FAutoScroll := True;
  DoubleBuffered := True;
end;

destructor TcxCustomScrollBox.Destroy;
begin
  FreeAndNil(FViewInfo);
  FreeAndNil(FHorzScrollBar);
  FreeAndNil(FVertScrollBar);
  inherited;
end;

procedure TcxCustomScrollBox.MakeVisible(AControl: TWinControl);
var
  ARect: TRect;
  AClientWidth, AClientHeight: Integer;
begin
  ARect := AControl.ClientRect;

  Dec(ARect.Left, HorzScrollBar.Margin);
  Inc(ARect.Right, HorzScrollBar.Margin);
  Dec(ARect.Top, VertScrollBar.Margin);
  Inc(ARect.Bottom, VertScrollBar.Margin);

  ARect.TopLeft := ScreenToClient(AControl.ClientToScreen(ARect.TopLeft));
  ARect.BottomRight := ScreenToClient(AControl.ClientToScreen(ARect.BottomRight));

  AClientWidth := ClientWidth;
  AClientHeight := ClientHeight;

  if ARect.Left < 0 then
    HorzScrollBar.Position := HorzScrollBar.Position + ARect.Left
  else
    if ARect.Right > AClientWidth then
    begin
      if ARect.Right - ARect.Left > AClientWidth then
        ARect.Right := ARect.Left + AClientWidth;
      HorzScrollBar.Position := HorzScrollBar.Position + ARect.Right - AClientWidth;
    end;
  if ARect.Top < 0 then
    VertScrollBar.Position := VertScrollBar.Position + ARect.Top
  else
    if ARect.Bottom > AClientHeight then
    begin
      if ARect.Bottom - ARect.Top > AClientHeight then
        ARect.Bottom := ARect.Top + AClientHeight;
      VertScrollBar.Position := VertScrollBar.Position + ARect.Bottom - AClientHeight;
    end;
end;

procedure TcxCustomScrollBox.LookAndFeelChanged(Sender: TcxLookAndFeel; AChangedValues: TcxLookAndFeelValues);
begin
  inherited;
  RefreshNonClientArea;
  Invalidate;
end;

procedure TcxCustomScrollBox.PaintNonClientArea(ACanvas: TcxCanvas);
begin
  DrawScrollBars(ACanvas);
  if BorderSize <> 0 then
    LookAndFeelPainter.DrawBorder(ACanvas, Bounds);
end;

procedure TcxCustomScrollBox.Scroll(AScrollBarKind: TScrollBarKind; AScrollCode: TScrollCode; var AScrollPos: Integer);

  function GetScrollBoxBarInfo: TcxScrollBoxScrollBarOptions;
  begin
    if AScrollBarKind = sbHorizontal then
      Result := HorzScrollBar
    else
      Result := VertScrollBar;
  end;

var
  AInfo: TcxScrollBoxScrollBarOptions;
begin
  inherited Scroll(AScrollBarKind, AScrollCode, AScrollPos);
  AInfo := GetScrollBoxBarInfo;
  AInfo.Scroll(AScrollCode, AScrollPos);
end;

procedure TcxCustomScrollBox.AdvancedScrollBy(ADeltaX, ADeltaY: Integer);
var
  I: Integer;
  ARect: PRect;
  AControl: TControl;
  AIsVisible: Boolean;
begin
  AIsVisible := HandleAllocated and IsWindowVisible(Handle);
  if AIsVisible then
  begin
    if Transparent then
      ARect := @cxNullRect
    else
      ARect := nil;
    Windows.ScrollWindow(Handle, ADeltaX, ADeltaY, nil, ARect);
  end;
  for I := 0 to ControlCount - 1 do
  begin
    AControl := Controls[I];
    if not (AControl is TWinControl) or not TWinControl(AControl).HandleAllocated then
    begin
      with AControl do
        SetBounds(Left + ADeltaX, Top + ADeltaY, Width, Height);
    end
    else
      if not AIsVisible then
        with TWinControl(AControl) do
          SetWindowPos(Handle, 0, Left + ADeltaX, Top + ADeltaY,
            Width, Height, SWP_NOZORDER + SWP_NOACTIVATE);
  end;
  Realign;
end;

procedure TcxCustomScrollBox.WndProc(var Message: TMessage);
begin
  if not DoWndProc(Message) then
    inherited WndProc(Message);
end;

function TcxCustomScrollBox.DoWndProc(var Message: TMessage): Boolean;
begin
  Result := False;
  case Message.Msg of
    WM_WINDOWPOSCHANGING:
      if Transparent then
        PWindowPos(Message.LParam).flags := PWindowPos(Message.LParam).flags or SWP_NOCOPYBITS;
  end;
end;

function TcxCustomScrollBox.GetViewInfoClass: TcxCustomScrollBoxViewInfoClass;
begin
  Result := TcxCustomScrollBoxViewInfo;
end;

procedure TcxCustomScrollBox.RefreshNonClientArea;
{$IFDEF DELPHI14}
var
  APrevAnchorMove: Boolean;
{$ENDIF}
begin
  if HandleAllocated then
  begin
  {$IFDEF DELPHI14}
    APrevAnchorMove := FAnchorMove;
    FAnchorMove := True; 
  {$ENDIF}
    SetWindowPos(Handle, 0, 0, 0, 0, 0,
      SWP_NOSIZE or SWP_NOMOVE or SWP_NOZORDER or SWP_NOACTIVATE or SWP_FRAMECHANGED);
    Update;
  {$IFDEF DELPHI14}
    FAnchorMove := APrevAnchorMove;
  {$ENDIF}
  end;
end;

procedure TcxCustomScrollBox.AdjustClientRect(var Rect: TRect);
begin
  with Rect do
  begin
    Rect := cxRectBounds(-HorzScrollBar.Position, -VertScrollBar.Position,
      Max(HorzScrollBar.Range, HorzScrollBar.PageSize),
      Max(VertScrollBar.Range, VertScrollBar.PageSize));
  end;
  inherited;
end;

procedure TcxCustomScrollBox.AlignControls(AControl: TControl; var Rect: TRect);
begin
  CalculateAutoRange;
  inherited;
end;

function TcxCustomScrollBox.AllowPan(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := HScrollBarVisible or VScrollBarVisible;
end;

function TcxCustomScrollBox.CanFocusOnClick: Boolean;
begin
  Result := False;
end;

function TcxCustomScrollBox.CreateScrollBarOptions(AKind: TScrollBarKind): TcxScrollBoxScrollBarOptions;
begin
  Result := TcxScrollBoxScrollBarOptions.Create(Self, AKind);
end;

procedure TcxCustomScrollBox.DoPaint;
begin
  ViewInfo.Paint(Canvas);
end;

procedure TcxCustomScrollBox.EraseBackground(ACanvas: TcxCanvas; const ARect: TRect);
begin
  ViewInfo.Paint(ACanvas);
end;

procedure TcxCustomScrollBox.DoUpdateScrollBars;
begin
  if FIsScrollBarsUpdating then
    Exit;
  FIsScrollBarsUpdating := True;
  try
    ViewInfo.Calculate(Bounds);
    InitScrollBarsParameters;
    HScrollBar.ApplyData;
    VScrollBar.ApplyData;
    VScrollBar.Visible := VertScrollBar.IsVisible;
    HScrollBar.Visible := HorzScrollBar.IsVisible;
    VScrollBar.Enabled := Enabled;
    HScrollBar.Enabled := Enabled;
    (MainScrollBars as TcxControlNCScrollBars).CheckSizeGripVisible(IsSizeGripVisible);
    SetInternalControlsBounds;

    HorzScrollBar.SetPosition(HorzScrollBar.Position);
    VertScrollBar.SetPosition(VertScrollBar.Position);
    RefreshNonClientArea;
  finally
    FIsScrollBarsUpdating := False;
  end;
end;

function TcxCustomScrollBox.GetBounds: TRect;
begin
  Result := Rect(0, 0, Width, Height);
end;

function TcxCustomScrollBox.GetClientOffsets: TRect;
var
  ABorderSize: Integer;
begin
  ABorderSize := BorderSize;
  Result := Rect(ABorderSize, ABorderSize,
    ABorderSize + IfThen(VertScrollBar.IsVisible, VScrollBar.Width),
    ABorderSize + IfThen(HorzScrollBar.IsVisible, HScrollBar.Height));
end;

function TcxCustomScrollBox.GetMainScrollBarsClass: TcxControlCustomScrollBarsClass;
begin
  Result := TcxControlNCScrollBars;
end;

function TcxCustomScrollBox.GetMouseWheelScrollingKind: TcxMouseWheelScrollingKind;
begin
  Result := mwskNone;
end;

function TcxCustomScrollBox.HasNonClientArea: Boolean;
begin
  Result := True;
end;

procedure TcxCustomScrollBox.InitScrollBarsParameters;
begin
  SetScrollBarInfo(sbHorizontal, 0, HorzScrollBar.Range - 1, HorzScrollBar.Increment,
    HorzScrollBar.PageSize, HorzScrollBar.Position, True, True);
  SetScrollBarInfo(sbVertical, 0, VertScrollBar.Range - 1, VertScrollBar.Increment,
    VertScrollBar.PageSize, VertScrollBar.Position, True, True);
end;

function TcxCustomScrollBox.IsTransparentBackground: Boolean;
begin
  Result := Transparent or inherited IsTransparentBackground;
end;

procedure TcxCustomScrollBox.CalculateAutoRange;
begin
  LockScrollBars;
  try
    HorzScrollBar.CalculateAutoRange;
    VertScrollBar.CalculateAutoRange;
  finally
    UnlockScrollBars;
  end;
end;

procedure TcxCustomScrollBox.SetAutoScroll(Value: Boolean);
begin
  if AutoScroll <> Value then
  begin
    FAutoScroll := Value;
    HorzScrollBar.Position := 0;
    VertScrollBar.Position := 0;
    UpdateScrollBars;
  end;
end;

procedure TcxCustomScrollBox.SetHorzScrollBar(Value: TcxScrollBoxScrollBarOptions);
begin
  HorzScrollBar.Assign(Value);
end;

procedure TcxCustomScrollBox.SetTransparent(const Value: Boolean);
begin
  if FTransparent <> Value then
  begin
    FTransparent := Value;
    if FTransparent then
      ControlStyle := ControlStyle - [csOpaque]
    else
      ControlStyle := ControlStyle + [csOpaque];
    InvalidateWithChildren;
  end;
end;

procedure TcxCustomScrollBox.SetVertScrollBar(Value: TcxScrollBoxScrollBarOptions);
begin
  VertScrollBar.Assign(Value);
end;

procedure TcxCustomScrollBox.CMEnabledChanged(var Message: TMessage);
begin
  inherited;
  UpdateScrollBars;
end;

procedure TcxCustomScrollBox.CMFocusChanged(var Message: TCMFocusChanged);
var
  AControl: TWinControl;
begin
  inherited;
  AControl := Message.Sender;
  if (AControl <> nil) and AControl.HandleAllocated and IsChildEx(Handle, AControl.Handle) then
    MakeVisible(AControl);
end;

procedure TcxCustomScrollBox.WMNCCalcSize(var Message: TWMNCCalcSize);
var
  R: TRect;
begin
  inherited;
  R := Message.CalcSize_Params^.rgrc[0];
  R := cxRectOffset(R, R.TopLeft, False);
  ViewInfo.Calculate(R);
  R := ViewInfo.ClientRect;
  R := cxRectOffset(R, Message.CalcSize_Params^.rgrc[0].TopLeft);
  Message.CalcSize_Params^.rgrc[0] := R;
end;

procedure TcxCustomScrollBox.WMNCHitTest(var Message: TWMNCHitTest);
begin
  if IsScrollBarsArea(ScreenToClient(Point(Message.XPos, Message.YPos))) then
    Message.Result := HTCLIENT
  else
    inherited;
end;

end.
