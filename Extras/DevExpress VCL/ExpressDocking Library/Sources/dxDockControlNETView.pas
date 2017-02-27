{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       ExpressDocking                                              }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSDOCKING AND ALL ACCOMPANYING  }
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

unit dxDockControlNETView;

{$I cxVer.inc}

interface

uses
  Types, Menus, Windows, Graphics, Classes, Controls, ExtCtrls, Messages, Forms,
  dxDockControl, dxDockPanel, cxLookAndFeelPainters, cxGraphics;

type
  TdxDockControlNETPainter = class(TdxDockControlPainter)
  protected
    function GetNETBackColor: TColor; virtual;
    function GetCaptionColor(IsActive: Boolean): TColor; override;
    function GetCaptionFontColor(IsActive: Boolean): TColor; override;
    function GetHideBarColor: TColor; override;
  public
    class function HasLookAndFeelStyle(AStyle: TcxLookAndFeelStyle): Boolean; override;
    // CustomDockControl
    function CanVerticalCaption: Boolean; override;
    function GetCaptionHeight: Integer; override;

    procedure DrawBorder(ACanvas: TcxCanvas; ARect: TRect); override;
    procedure DrawCaption(ACanvas: TcxCanvas; ARect: TRect; IsActive: Boolean); override;
    procedure DrawCaptionText(ACanvas: TcxCanvas; ARect: TRect; IsActive: Boolean); override;
    procedure DrawCaptionButtonSelection(ACanvas: TcxCanvas;
      ARect: TRect; AIsActive: Boolean; AState: TcxButtonState); override;
    procedure DrawCaptionCloseButton(ACanvas: TcxCanvas; ARect: TRect;
      AIsActive: Boolean; AState: TcxButtonState); override;
    procedure DrawCaptionHideButton(ACanvas: TcxCanvas; ARect: TRect;
      IsActive, IsSwitched: Boolean; AState: TcxButtonState); override;
    procedure DrawCaptionMaximizeButton(ACanvas: TcxCanvas; ARect: TRect;
      IsActive, IsSwitched: Boolean; AState: TcxButtonState); override;
    // AutoHideContainer
    function GetHideBarHeight: Integer; override;
    function GetHideBarWidth: Integer; override;

    procedure DrawHideBar(ACanvas: TcxCanvas; ARect: TRect; APosition: TdxAutoHidePosition); override;
    procedure DrawHideBarButtonBackground(ACanvas: TcxCanvas;
      AButton: TdxDockSiteHideBarButton; APosition: TdxAutoHidePosition); override;
    procedure DrawHideBarScrollButton(ACanvas: TcxCanvas; const ARect: TRect;
      AState: TcxButtonState; AArrow: TcxArrowDirection); override;
  end;

implementation

uses
  Math, dxDockConsts, cxGeometry;

{ TdxDockControlNETPainter }

function TdxDockControlNETPainter.GetNETBackColor: TColor;
var
  r, g, b, m, d, md: Integer;
begin
  Result := ColorToRGB(GetColor);
  r := GetRValue(Result);
  g := GetGValue(Result);
  b := GetBValue(Result);
  m := Max(Max(r, g), b);
  d := $23;
  md := (255 - (m + d));
  if md > 0 then md := 0;
  Inc(r, d + md);
  Inc(g, d + md);
  Inc(b, d + md);
  Result := RGB(r, g, b);
end;

function TdxDockControlNETPainter.GetCaptionColor(IsActive: Boolean): TColor;
begin
  if IsActive then
    Result := clActiveCaption
  else Result := GetColor;
end;

function TdxDockControlNETPainter.GetCaptionFontColor(IsActive: Boolean): TColor;
begin
  if IsActive then
    Result := clCaptionText
  else Result := clBlack;
end;

function TdxDockControlNETPainter.GetHideBarColor: TColor;
begin
  Result := GetNETBackColor;
end;

procedure TdxDockControlNETPainter.DrawBorder(ACanvas: TcxCanvas; ARect: TRect);
var
  ABorderWidths: TRect;
begin
  ACanvas.Brush.Color := ColorToRGB(GetBorderColor);
  ACanvas.Brush.Style := bsSolid;
  with ARect do
  begin
    ABorderWidths := GetBorderWidths;
    ACanvas.FillRect(Rect(Left, Top, Left + ABorderWidths.Left, Bottom));
    ACanvas.FillRect(Rect(Left, Bottom - ABorderWidths.Bottom, Right, Bottom));
    ACanvas.FillRect(Rect(Right - ABorderWidths.Right, Top, Left + Right, Bottom));
    ACanvas.FillRect(Rect(Left, Top, Right, Top + ABorderWidths.Top));
  end;
  if DockControl.AutoHide then
  begin
    DrawColorEdge(ACanvas, ARect, GetColor, etSunkenInner, [epTopLeft]);
    DrawColorEdge(ACanvas, ARect, GetColor, etRaisedInner, [epBottomRight]);
  end;
end;

procedure TdxDockControlNETPainter.DrawCaption(
  ACanvas: TcxCanvas; ARect: TRect; IsActive: Boolean);
begin
  ACanvas.Brush.Style := bsSolid;
  if IsActive then
  begin
    ACanvas.Pen.Color := ColorToRGB(GetCaptionColor(IsActive));
    ACanvas.Brush.Color := ColorToRGB(GetCaptionColor(IsActive));
    ACanvas.FillRect(ARect);
  end
  else
  begin
    ACanvas.FillRect(ARect, ColorToRGB(GetCaptionColor(IsActive)));
    ACanvas.Brush.Style := bsClear;
    ACanvas.Pen.Color := DarkColor(GetCaptionColor(IsActive));
    ACanvas.Pen.Style := psSolid;
    ACanvas.Pen.Width := 1;
    ACanvas.ExcludeClipRect(cxRectSetSize(ARect, 1, 1));
    ACanvas.ExcludeClipRect(cxRect(ARect.Right - 1, ARect.Top, ARect.Right, ARect.Top + 1));
    ACanvas.ExcludeClipRect(cxRect(ARect.Right - 1, ARect.Bottom - 1, ARect.Right, ARect.Bottom));
    ACanvas.ExcludeClipRect(cxRect(ARect.Left, ARect.Bottom - 1, ARect.Left + 1, ARect.Bottom));
    ACanvas.Rectangle(ARect);
  end;
end;

procedure TdxDockControlNETPainter.DrawCaptionButtonSelection(
  ACanvas: TcxCanvas; ARect: TRect; AIsActive: Boolean; AState: TcxButtonState);
begin
  case AState of
    cxbsPressed:
      begin
        DrawColorEdge(ACanvas, ARect, GetCaptionColor(AIsActive), etSunkenInner, [epTopLeft]);
        DrawColorEdge(ACanvas, ARect, GetCaptionColor(AIsActive), etSunkenOuter, [epBottomRight]);
      end;

    cxbsHot:
      begin
        DrawColorEdge(ACanvas, ARect, GetCaptionColor(AIsActive), etRaisedOuter, [epTopLeft]);
        DrawColorEdge(ACanvas, ARect, GetCaptionColor(AIsActive), etRaisedInner, [epBottomRight]);
      end;
  end;
end;

procedure TdxDockControlNETPainter.DrawCaptionCloseButton(
  ACanvas: TcxCanvas; ARect: TRect; AIsActive: Boolean; AState: TcxButtonState);
begin
  DrawCaptionButtonSelection(ACanvas, ARect, AIsActive, AState);

  ACanvas.Pen.Style := psSolid;
  ACanvas.Pen.Width := 1;
  ACanvas.Pen.Color := ColorToRGB(GetCaptionSignColor(AIsActive, AState));

  ACanvas.MoveTo(ARect.Left + 3, ARect.Top + 3);
  ACanvas.LineTo(ARect.Right - 3 + 1, ARect.Bottom - 3 + 1);
  ACanvas.MoveTo(ARect.Right - 3, ARect.Top + 3);
  ACanvas.LineTo(ARect.Left + 3 - 1, ARect.Bottom - 3 + 1);
end;

procedure TdxDockControlNETPainter.DrawCaptionHideButton(ACanvas: TcxCanvas;
  ARect: TRect; IsActive, IsSwitched: Boolean; AState: TcxButtonState);
begin
  DrawCaptionButtonSelection(ACanvas, ARect, IsActive, AState);

  ACanvas.Brush.Style := bsClear;
  ACanvas.Pen.Style := psSolid;
  ACanvas.Pen.Width := 1;
  ACanvas.Pen.Color := ColorToRGB(GetCaptionSignColor(IsActive, AState));
  if IsSwitched then
  begin
    ACanvas.Rectangle(ARect.Left + 3, ARect.Top + 3, ARect.Right - 2, ARect.Bottom - 4);
    ACanvas.MoveTo(ARect.Left + 3, ARect.Top + 2);
    ACanvas.LineTo(ARect.Left + 3, ARect.Bottom - 3);
    ACanvas.MoveTo(ARect.Left + 3, ARect.Bottom - 6);
    ACanvas.LineTo(ARect.Right - 3, ARect.Bottom - 6);
    ACanvas.MoveTo(ARect.Left + 1, ARect.Top + 5);
    ACanvas.LineTo(ARect.Left + 3, ARect.Top + 5);
  end
  else
  begin
    ACanvas.Rectangle(ARect.Left + 4, ARect.Top + 2, ARect.Right - 3, ARect.Bottom - 3);
    ACanvas.MoveTo(ARect.Left + 3, ARect.Bottom - 4);
    ACanvas.LineTo(ARect.Right - 2, ARect.Bottom - 4);
    ACanvas.MoveTo(ARect.Right - 5, ARect.Top + 2);
    ACanvas.LineTo(ARect.Right - 5, ARect.Bottom - 3);
    ACanvas.MoveTo(ARect.Left + 6, ARect.Bottom - 3);
    ACanvas.LineTo(ARect.Left + 6, ARect.Bottom - 1);
  end;
end;

procedure TdxDockControlNETPainter.DrawCaptionMaximizeButton(ACanvas: TcxCanvas;
  ARect: TRect; IsActive, IsSwitched: Boolean; AState: TcxButtonState);
begin
  DrawCaptionButtonSelection(ACanvas, ARect, IsActive, AState);

  ACanvas.Brush.Style := bsClear;
  ACanvas.Pen.Style := psSolid;
  ACanvas.Pen.Width := (ARect.Right - ARect.Left) div 16 + 1;
  ACanvas.Pen.Color := ColorToRGB(GetCaptionSignColor(IsActive, AState));
  if IsSwitched then
  begin
    ACanvas.Rectangle(ARect.Left + 5, ARect.Top + 2, ARect.Right - 1, ARect.Bottom - 4);
    ACanvas.Rectangle(ARect.Left + 2, ARect.Top + 5, ARect.Right - 4, ARect.Bottom - 1);
  end
  else
    ACanvas.Rectangle(ARect.Left + 3, ARect.Top + 3, ARect.Right - 2, ARect.Bottom - 2);
end;

procedure TdxDockControlNETPainter.DrawCaptionText(
  ACanvas: TcxCanvas; ARect: TRect; IsActive: Boolean);
begin
  ACanvas.Brush.Style := bsClear;
  ACanvas.Font := GetFont;
  ACanvas.Font.Color := ColorToRGB(GetCaptionFontColor(IsActive));
  cxDrawText(ACanvas.Handle, DockControl.Caption, ARect,
    DT_SINGLELINE or DT_LEFT or DT_VCENTER or DT_END_ELLIPSIS);
end;

procedure TdxDockControlNETPainter.DrawHideBar(
  ACanvas: TcxCanvas; ARect: TRect; APosition: TdxAutoHidePosition);
begin
  ACanvas.FillRect(ARect, GetHideBarColor);
  case APosition of
    ahpLeft:
      ARect.Right := ARect.Left + GetHideBarVertInterval;
    ahpTop:
      ARect.Bottom := ARect.Top + GetHideBarVertInterval;
    ahpRight:
      ARect.Left := ARect.Right - GetHideBarVertInterval;
    ahpBottom:
      ARect.Top := ARect.Bottom - GetHideBarVertInterval;
  end;
  ACanvas.FillRect(ARect, ColorToRGB(GetHideBarButtonColor));
  ACanvas.ExcludeClipRect(ARect);
end;

procedure TdxDockControlNETPainter.DrawHideBarButtonBackground(
  ACanvas: TcxCanvas; AButton: TdxDockSiteHideBarButton; APosition: TdxAutoHidePosition);
const
  Edges: array[TdxAutoHidePosition] of TdxEdgePositions = ([epTop, epBottomRight],
    [epLeft, epBottomRight], [epTopLeft, epBottom], [epTopLeft, epRight], []);
begin
  ACanvas.FillRect(AButton.Bounds, ColorToRGB(GetHideBarButtonColor));
  DrawColorEdge(ACanvas, AButton.Bounds, GetHideBarButtonColor, etFlat, Edges[APosition]);
end;

procedure TdxDockControlNETPainter.DrawHideBarScrollButton(ACanvas: TcxCanvas;
  const ARect: TRect; AState: TcxButtonState; AArrow: TcxArrowDirection);
begin
  cxLookAndFeelPaintersManager.GetPainter(lfsUltraFlat).DrawArrow(ACanvas, ARect, AState, AArrow);
end;

function TdxDockControlNETPainter.CanVerticalCaption: Boolean;
begin
  Result := False;
end;

function TdxDockControlNETPainter.GetCaptionHeight: Integer;
begin
  Result := 5 + GetFont.Size + 5;
end;

function TdxDockControlNETPainter.GetHideBarHeight: Integer;
begin
  Result := 8 + GetFont.Size + 8;
  if Result < GetHideBarVertInterval + 2 + GetImageHeight + 2 + GetHideBarVertInterval then
    Result := GetHideBarVertInterval + 2 + GetImageHeight + 2 + GetHideBarVertInterval;
end;

function TdxDockControlNETPainter.GetHideBarWidth: Integer;
begin
  Result := 8 + GetFont.Size + 8;
  if Result < GetHideBarVertInterval + 2 + GetImageWidth + 2 + GetHideBarVertInterval then
    Result := GetHideBarVertInterval + 2 + GetImageWidth + 2 + GetHideBarVertInterval;
end;

class function TdxDockControlNETPainter.HasLookAndFeelStyle(AStyle: TcxLookAndFeelStyle): Boolean;
begin
  Result := (AStyle = lfsUltraFlat) or (AStyle = lfsFlat);
end;

initialization
  dxDockingPaintersManager.Register(TdxDockControlNETPainter);

finalization
  dxDockingPaintersManager.Unregister(TdxDockControlNETPainter);
end.
