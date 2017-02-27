{********************************************************************}
{                                                                    }
{           Developer Express Visual Component Library               }
{                    ExpressSkins Library                            }
{                                                                    }
{           Copyright (c) 2006-2014 Developer Express Inc.           }
{                     ALL RIGHTS RESERVED                            }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSSKINS AND ALL ACCOMPANYING     }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.              }
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

unit dxSkinscxSchedulerPainter;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI17}
  UITypes,
{$ENDIF}
  Windows, SysUtils, Classes, cxSchedulerCustomResourceView, cxDateUtils,
  cxSchedulerCustomControls, dxSkinsCore, dxSkinsLookAndFeelPainter,
  cxLookAndFeels, cxLookAndFeelPainters, cxGraphics, Graphics, cxGeometry,
  cxSchedulerUtils, Math, cxScheduler, cxClasses;

type

  { TcxSchedulerSkinViewItemsPainter }

  TcxScheduler3SkinViewItemsPainter = class(TcxSchedulerExternalPainter)
  private
    procedure DrawClippedElement(ACanvas: TcxCanvas; AElement: TdxSkinElement; ABorders: TcxBorders; R: TRect);
    function GetEventSelectionOffsets(AHasTimeLine: Boolean): TRect;
    function IsSkinAvalaible: Boolean;
    function SkinInfo: TdxSkinLookAndFeelPainterInfo;
  protected
    function DoDrawEvent(AViewInfo: TcxSchedulerEventCellViewInfo): Boolean; virtual;
  public
    procedure DoCustomDrawButton(AViewInfo: TcxSchedulerMoreEventsButtonViewInfo; var ADone: Boolean); override;
    //
    procedure DrawAllDayArea(ACanvas: TcxCanvas; const ARect: TRect; ABorderColor: TColor;
      ABorders: TcxBorders; AViewParams: TcxViewParams; ASelected: Boolean; ATransparent: Boolean); override;
    procedure DrawCurrentTime(ACanvas: TcxCanvas; AColor: TColor; AStart: TDateTime; ABounds: TRect); override;
    function DrawCurrentTimeFirst: Boolean; override;
    procedure DrawEvent(AViewInfo: TcxSchedulerEventCellViewInfo); override;
    procedure DrawEventAsProgressText(AViewInfo: TcxSchedulerEventCellViewInfo;
      AContent: TRect; AProgressRect: TRect; const AText: string); override;
    procedure DrawTimeGridCurrentTime(ACanvas: TcxCanvas; AColor: TColor; const ATimeLineRect: TRect); override;
    procedure DrawTimeGridHeader(ACanvas: TcxCanvas; ABorderColor: TColor;
      AViewInfo: TcxSchedulerCustomViewInfoItem; ABorders: TcxBorders; ASelected: Boolean); override;
    procedure DrawTimeLine(ACanvas: TcxCanvas; const ARect: TRect;
      AViewParams: TcxViewParams; ABorders: TcxBorders; ABorderColor: TColor); override;
    procedure DrawTimeRulerBackground(ACanvas: TcxCanvas; const ARect: TRect;
      ABorders: TcxBorders; AViewParams: TcxViewParams; ATransparent: Boolean); override;
    procedure DrawShadow(ACanvas: TcxCanvas; const ARect, AVisibleRect: TRect); override;
    function DrawShadowFirst: Boolean; override;
    function GetEventSelectionExtends: TRect; override;
    function MoreButtonSize(ASize: TSize): TSize; override;
    function NeedDrawSelection: Boolean; override;
  end;

implementation

uses
  Types, cxSchedulerStorage;

const
  cxHeaderStateToButtonState: array[Boolean] of TcxButtonState = (cxbsNormal, cxbsHot);

{ TcxSchedulerSkinViewItemsPainter }

procedure TcxScheduler3SkinViewItemsPainter.DrawClippedElement(
  ACanvas: TcxCanvas; AElement: TdxSkinElement; ABorders: TcxBorders; R: TRect);
begin
  ACanvas.SaveClipRegion;
  try
    ACanvas.SetClipRegion(TcxRegion.Create(R), roIntersect);
    with AElement.Image.Margins.Margin do
    begin
      if not (bLeft in ABorders) then
        Dec(R.Left, Left);
      if not (bTop in ABorders) then
        Dec(R.Top, Top);
      if not (bRight in ABorders) then
        Inc(R.Right, Right);
      if not (bBottom in ABorders) then
        Inc(R.Bottom, Bottom);
    end;
    AElement.Draw(ACanvas.Handle, R);
  finally
    ACanvas.RestoreClipRegion;
  end;
end;

function TcxScheduler3SkinViewItemsPainter.IsSkinAvalaible: Boolean;
begin
  Result := Painter.InheritsFrom(TdxSkinLookAndFeelPainter);
end;

function TcxScheduler3SkinViewItemsPainter.SkinInfo: TdxSkinLookAndFeelPainterInfo;
begin
  if (Painter = nil) or not Painter.GetPainterData(Result) then
    Result := nil;
end;

function TcxScheduler3SkinViewItemsPainter.MoreButtonSize(ASize: TSize): TSize;
begin
  if IsSkinAvalaible and (SkinInfo.SchedulerMoreButton <> nil) then
    Result := SkinInfo.SchedulerMoreButton.Size
  else
    Result := ASize;
end;

procedure TcxScheduler3SkinViewItemsPainter.DoCustomDrawButton(
  AViewInfo: TcxSchedulerMoreEventsButtonViewInfo; var ADone: Boolean);
begin
  inherited DoCustomDrawButton(AViewInfo, ADone);
  if not ADone and IsSkinAvalaible then
  begin
    ADone := SkinInfo.SchedulerMoreButton <> nil;
    if ADone then
      SkinInfo.SchedulerMoreButton.Draw(AViewInfo.Canvas.Handle, AViewInfo.Bounds, Byte(AViewInfo.IsDown));
  end;
end;

procedure TcxScheduler3SkinViewItemsPainter.DrawAllDayArea(ACanvas: TcxCanvas;
  const ARect: TRect; ABorderColor: TColor; ABorders: TcxBorders;
  AViewParams: TcxViewParams; ASelected: Boolean; ATransparent: Boolean);  
var
  AElement: TdxSkinElement;
begin
  if IsSkinAvalaible then
    AElement := SkinInfo.SchedulerAllDayArea[ASelected]
  else
    AElement := nil;

  if AElement <> nil then
    DrawClippedElement(ACanvas, AElement, ABorders, ARect)
  else
    inherited DrawAllDayArea(ACanvas, ARect,
      ABorderColor, ABorders, AViewParams, ASelected, ATransparent);
end;  

procedure TcxScheduler3SkinViewItemsPainter.DrawCurrentTime(
  ACanvas: TcxCanvas; AColor: TColor; AStart: TDateTime; ABounds: TRect);
var
  AElement: TdxSkinElement;
  AIndicatorRect: TRect;
  Y, I: Integer;
begin
  if IsSkinAvalaible then
    AElement := SkinInfo.SchedulerCurrentTimeIndicator
  else
    AElement := nil;

  if AElement <> nil then
  begin
    Y := Trunc(ABounds.Top + ((dxTimeOf(Now) - dxTimeOf(AStart)) * cxRectHeight(ABounds)) / HourToTime);

    AIndicatorRect := cxRectSetTop(ABounds, Y, 0);
    AIndicatorRect := cxRectCenterVertically(AIndicatorRect, AElement.Image.Size.cy);
    Inc(AIndicatorRect.Left, 5);
    Dec(AIndicatorRect.Right);

    if cxRectIntersect(AIndicatorRect, ABounds) then
    begin
      for I := 0 to 1 do
        AElement.Draw(ACanvas.Handle, AIndicatorRect, I);
    end;
  end
  else
    inherited DrawCurrentTime(ACanvas, AColor, AStart, ABounds);
end;

function TcxScheduler3SkinViewItemsPainter.NeedDrawSelection: Boolean;
begin
  Result := not IsSkinAvalaible;
end;

function TcxScheduler3SkinViewItemsPainter.DrawCurrentTimeFirst: Boolean;
begin
  Result := True;
end;

procedure TcxScheduler3SkinViewItemsPainter.DrawEvent(AViewInfo: TcxSchedulerEventCellViewInfo);
begin
  if not DoDrawEvent(AViewInfo) then
    inherited DrawEvent(AViewInfo);
end;

function TcxScheduler3SkinViewItemsPainter.DoDrawEvent(AViewInfo: TcxSchedulerEventCellViewInfo): Boolean;

  function CheckRect(const ARect: TRect): TRect;
  begin
    if AViewInfo.Selected then
      Result := cxRectInflate(ARect, GetEventSelectionOffsets(not IsRectEmpty(AViewInfo.TimeLineRect)))
    else
      Result := ARect;
  end;

  function IsAllDayEvent(AEvent: TcxSchedulerControlEvent): Boolean;
  begin
    Result := AEvent.AllDayEvent or (AEvent.Duration > 1);
  end;

  function IsDefaultContentColor(AColor: TColor): Boolean;
  begin
    if AViewInfo.Selected then
      Result := AColor = Painter.DefaultSelectionColor
    else
      Result := AColor = Painter.DefaultSchedulerEventColor(IsAllDayEvent(AViewInfo.Event));
  end;

  procedure ColorizeContent(AColor: TColor; AMask: TdxSkinElement);
  const
    ImageIndexMap: array[Boolean] of Integer = (1, 0);
  var
    ABitmap, AMaskBmp, ASourceBmp: TcxBitmap;
    R: TRect;
  begin
    if (AMask <> nil) and cxColorIsValid(AColor) and not IsDefaultContentColor(AColor) then
    begin
      R := cxRectSetNullOrigin(AViewInfo.Bounds);
      AMaskBmp := TcxBitmap.CreateSize(R, pf32bit);
      ASourceBmp := TcxBitmap.CreateSize(R, pf32bit);
      try
        ASourceBmp.cxCanvas.FillRect(R, AColor);
        AMask.Draw(AMaskBmp.Canvas.Handle, R, ImageIndexMap[IsRectEmpty(AViewInfo.TimeLineRect)]);
        ABitmap := TcxBitmap.CreateSize(R, pf32bit);
        try
          cxBitBlt(AMaskBmp.Canvas.Handle, AMaskBmp.Canvas.Handle, AMaskBmp.ClientRect, cxNullPoint, NOTSRCCOPY);
          cxBitBlt(ABitmap.Canvas.Handle, AMaskBmp.Canvas.Handle, ABitmap.ClientRect, cxNullPoint, SRCCOPY);
          cxBitBlt(ABitmap.Canvas.Handle, ASourceBmp.Canvas.Handle, ABitmap.ClientRect, cxNullPoint, SRCERASE);
          cxBitBlt(AViewInfo.Canvas.Handle,  AMaskBmp.Canvas.Handle, AViewInfo.Bounds, cxNullPoint, SRCAND);
          cxBitBlt(AViewInfo.Canvas.Handle, ABitmap.Canvas.Handle, AViewInfo.Bounds, cxNullPoint, SRCINVERT);
        finally
          ABitmap.Free;
        end;
      finally
        AMaskBmp.Free;
        ASourceBmp.Free;
      end;
    end;
  end;

  function GetSeparatorColor(ABorderColor: TdxSkinColor): TColor;
  begin
    Result := clDefault;
    if ABorderColor <> nil then
      Result := ABorderColor.Value;
    if not cxColorIsValid(Result) then
      Result := AViewInfo.SeparatorColor;
  end;

const
  SelectedFlags: array[Boolean] of TdxSkinElementState = (esNormal, esHot);
var
  AElement: TdxSkinElement;
begin
  Result := False;
  if IsSkinAvalaible and not AViewInfo.Transparent then
  begin
    AElement := SkinInfo.SchedulerAppointment[IsRectEmpty(AViewInfo.TimeLineRect)];
    if AElement <> nil then
    begin
      AElement.Draw(AViewInfo.Canvas.Handle, CheckRect(AViewInfo.Bounds), 0, SelectedFlags[AViewInfo.Selected]);
      ColorizeContent(AViewInfo.ViewParams.Color, SkinInfo.SchedulerAppointmentMask);
      AViewInfo.SeparatorColor := GetSeparatorColor(SkinInfo.SchedulerAppointmentBorder);
      AViewInfo.Transparent := True;
      Result := True;
    end;
  end;
end;

procedure TcxScheduler3SkinViewItemsPainter.DrawEventAsProgressText(
  AViewInfo: TcxSchedulerEventCellViewInfo; AContent: TRect; AProgressRect: TRect;
  const AText: string);
begin
  if IsSkinAvalaible then
    cxDrawText(AViewInfo.Canvas.Handle, AText, AContent, DT_CENTER or DT_VCENTER or DT_SINGLELINE)
  else
    inherited DrawEventAsProgressText(AViewInfo, AContent, AProgressRect, AText);
end;

procedure TcxScheduler3SkinViewItemsPainter.DrawTimeGridCurrentTime(
  ACanvas: TcxCanvas; AColor: TColor; const ATimeLineRect: TRect);
var
  AElement: TdxSkinElement;
begin
  if IsSkinAvalaible then
    AElement := SkinInfo.SchedulerTimeGridCurrentTimeIndicator
  else
    AElement := nil;

  if AElement <> nil then
    AElement.Draw(ACanvas.Handle, ATimeLineRect)
  else
    inherited DrawTimeGridCurrentTime(ACanvas, AColor, ATimeLineRect);
end;

procedure TcxScheduler3SkinViewItemsPainter.DrawTimeGridHeader(
  ACanvas: TcxCanvas; ABorderColor: TColor; AViewInfo: TcxSchedulerCustomViewInfoItem;
  ABorders: TcxBorders; ASelected: Boolean);
var
  AElement: TdxSkinElement;
begin
  if IsSkinAvalaible then
    AElement := SkinInfo.SchedulerTimeGridHeader[ASelected]
  else
    AElement := nil;

  if AElement <> nil then
    DrawClippedElement(ACanvas, AElement, ABorders, AViewInfo.Bounds)
  else
    inherited DrawTimeGridHeader(ACanvas, ABorderColor, AViewInfo, ABorders, ASelected);
end;

procedure TcxScheduler3SkinViewItemsPainter.DrawTimeLine(ACanvas: TcxCanvas;
  const ARect: TRect; AViewParams: TcxViewParams; ABorders: TcxBorders; ABorderColor: TColor);
var
  AElement: TdxSkinElement;
begin
  if IsSkinAvalaible then
    AElement := SkinInfo.SchedulerTimeLine
  else
    AElement := nil;

  if AElement <> nil then
    DrawClippedElement(ACanvas, AElement, ABorders, ARect)
  else
    inherited DrawTimeLine(ACanvas, ARect, AViewParams, ABorders, ABorderColor); 
end;

procedure TcxScheduler3SkinViewItemsPainter.DrawTimeRulerBackground(ACanvas: TcxCanvas;
  const ARect: TRect; ABorders: TcxBorders; AViewParams: TcxViewParams; ATransparent: Boolean);
var
  AElement: TdxSkinElement;
begin
  if IsSkinAvalaible then
    AElement := SkinInfo.SchedulerTimeRuler
  else
    AElement := nil;

  if AElement <> nil then
    DrawClippedElement(ACanvas, AElement, ABorders, ARect)
  else
    inherited DrawTimeRulerBackground(ACanvas, ARect, ABorders, AViewParams, ATransparent);
end;

function TcxScheduler3SkinViewItemsPainter.GetEventSelectionExtends: TRect;
begin
  Result := GetEventSelectionOffsets(False);
end;

function TcxScheduler3SkinViewItemsPainter.GetEventSelectionOffsets(AHasTimeLine: Boolean): TRect;
var
  ABorderSize: Integer;
begin
  if IsSkinAvalaible and (SkinInfo.SchedulerAppointmentBorderSize <> nil) then
    ABorderSize := SkinInfo.SchedulerAppointmentBorderSize.Value
  else
    ABorderSize := 0;

  Result := cxRect(ABorderSize, ABorderSize, ABorderSize, ABorderSize);
  if AHasTimeLine then
    Result.Left := cxTimeLineWidth;
end;

procedure TcxScheduler3SkinViewItemsPainter.DrawShadow(
  ACanvas: TcxCanvas; const ARect, AVisibleRect: TRect);
const
  ShadowSize = 4;

  function GetBottomShadowRect(const R: TRect): TRect;
  begin
    Result := cxRect(R.Left + ShadowSize,
      R.Bottom - ShadowSize, R.Right + ShadowSize, R.Bottom + ShadowSize);
  end;

  function GetRightShadowRect(const R: TRect): TRect;
  begin
    Result := cxRect(R.Right - ShadowSize,
      R.Top + ShadowSize, R.Right + ShadowSize, R.Bottom - ShadowSize);
  end;

  procedure DrawShadowLine(AShadow: TdxSkinElement; const ARect: TRect);
  begin
    if AShadow <> nil then
      AShadow.Draw(ACanvas.Handle, ARect);
  end;

begin
  if IsSkinAvalaible then
  begin
    ACanvas.SaveClipRegion;
    try
      ACanvas.IntersectClipRect(AVisibleRect);
      DrawShadowLine(SkinInfo.SchedulerAppointmentShadow[False], GetBottomShadowRect(ARect));
      DrawShadowLine(SkinInfo.SchedulerAppointmentShadow[True], GetRightShadowRect(ARect));
    finally
      ACanvas.RestoreClipRegion;
    end;
  end
  else
    inherited DrawShadow(ACanvas, ARect, AVisibleRect);
end;

function TcxScheduler3SkinViewItemsPainter.DrawShadowFirst: Boolean;
begin
  Result := IsSkinAvalaible or inherited DrawShadowFirst;
end;

initialization
  ExternalPainterClass := TcxScheduler3SkinViewItemsPainter;
finalization
  ExternalPainterClass := TcxSchedulerExternalPainter;
end.
