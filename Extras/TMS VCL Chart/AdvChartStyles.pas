{********************************************************************}
{                                                                    }
{ written by TMS Software                                            }
{            copyright © 2016                                        }
{            Email : info@tmssoftware.com                            }
{            Web : http://www.tmssoftware.com                        }
{                                                                    }
{ The source code is given as is. The author is not responsible      }
{ for any possible damage done due to the use of this code.          }
{ The complete source code remains property of the author and may    }
{ not be distributed, published, given or sold in any form as such.  }
{ No parts of the source code can be included in any other component }
{ or application without written authorization of the author.        }
{********************************************************************}

unit AdvChartStyles;

{$I TMSDEFS.inc}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

interface

uses
  Classes, AdvChartGraphics, Graphics
  {$IFDEF FMXLIB}
  ,FMX.Types, Controls, UITypes
  {$ENDIF}
  {$IFDEF VCLLIB}
  ,VCL.Themes
  {$ENDIF}
  ;

type
  IAdvAdaptToStyle = interface
  ['{3EFF288D-3927-4E86-8E9D-EF684B501C9E}']
    function GetAdaptToStyle: Boolean;
    procedure SetAdaptToStyle(const Value: Boolean);
    property AdaptToStyle: Boolean read GetAdaptToStyle write SetAdaptToStyle;
  end;

  TAdvChartStyles = class
  private class var
    {$IFDEF FMXLIB}
    FScene: IScene;
    {$ENDIF}
  protected
    {$IFDEF FMXLIB}
    class function ExtractColor(ABitmap: TBitmap): TAdvChartGraphicsColor; virtual;
    class function ExtractColorTo(ABitmap: TBitmap): TAdvChartGraphicsColor; virtual;
    {$ENDIF}
    {$IFDEF VCLLIB}
    class function ExtractColor(AElement: TThemedElementDetails): TAdvChartGraphicsColor; virtual;
    class function ExtractColorTo(AElement: TThemedElementDetails): TAdvChartGraphicsColor; virtual;
    {$ENDIF}
    {$IFDEF FMXLIB}
    class function ParseBrush(ABrush: TBrush; ASecondColor: Boolean): TAdvChartGraphicsColor; virtual;
    class function GetStyleSceneObject: TFmxObject; virtual;
    class function GetStyleBackgroundFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleBackgroundStroke(AStyle: TFmxObject): TStrokeBrush; virtual;
    class function GetStyleDefaultButtonFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleDefaultButtonStroke(AStyle: TFmxObject): TStrokeBrush; virtual;
    class function GetStyleEditTextColor(AStyle: TFmxObject): TAlphaColor; virtual;
    class function GetStyleEditFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleEditStroke(AStyle: TFmxObject): TStrokeBrush; virtual;
    class function GetStyleHeaderFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleHeaderStroke(AStyle: TFmxObject): TStrokeBrush; virtual;
    class function GetStyleSelectionFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleAlternativeSelectionFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleAlternativeBackgroundFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleAlternativeBackgroundStroke(AStyle: TFmxObject): TStrokeBrush; virtual;
    class function GetStyleFocusFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleLineFill(AStyle: TFmxObject): TBrush; virtual;
    class function GetStyleTextFont(AStyle: TFmxObject): TFont; virtual;
    class function GetStyleTextColor(AStyle: TFmxObject): TAlphaColor; virtual;
    class function GetStyleAlternateBackgroundFill(AStyle: TFmxObject): TBrush; virtual;
    class function IsTransparentStyle(AStyle: TFmxObject): Boolean; virtual;
    {$ENDIF}
  public
    {$IFDEF FMXLIB}
    class procedure SetActiveScene(AScene: IScene); virtual;
    {$ENDIF}
    class function StyleServicesEnabled: Boolean; virtual;
    class function GetStyleLineFillColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleBackgroundFillColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleBackgroundFillColorTo(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleAlternativeBackgroundFillColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleAlternativeBackgroundFillColorTo(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleBackgroundStrokeColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleHeaderFillColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleHeaderFillColorTo(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleHeaderStrokeColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleSelectionFillColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleSelectionFillColorTo(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleTextFontColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleAlternativeTextFontColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleDefaultButtonFillColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
    class function GetStyleDefaultButtonStrokeColor(var {%H-}AColor: TAdvChartGraphicsColor): Boolean; virtual;
  end;

implementation

{$IFDEF FMXLIB}
uses
  UIConsts, FMX.Objects, FMX.Styles, FMX.Styles.Objects, Types, SysUtils, Forms;
{$ENDIF}

{$IFDEF FMXLIB}

class function TAdvChartStyles.ParseBrush(ABrush: TBrush; ASecondColor: Boolean): TAdvChartGraphicsColor;
begin
  Result := gcNull;
  case ABrush.Kind of
    TBrushKind.None, TBrushKind.Resource: Result := gcNull;
    TBrushKind.Solid: Result := ABrush.Color;
    TBrushKind.Gradient:
    begin
      if ABrush.Gradient.Points.Count > 0 then
      begin
        if ASecondColor then
          Result := ABrush.Gradient.Points[1].Color
        else
          Result := ABrush.Gradient.Points[0].Color;
      end
      else
        Result := ABrush.Color;
    end;
    TBrushKind.Bitmap:
    begin
      if ASecondColor then
        Result := ExtractColorTo(ABrush.Bitmap.Bitmap)
      else
        Result := ExtractColor(ABrush.Bitmap.Bitmap);
    end;
  end;
end;

class function TAdvChartStyles.GetStyleSceneObject: TFmxObject;
var
  frm: TCommonCustomForm;
begin
  if Assigned(TAdvChartStyles.FScene) then
  begin
    if Assigned(TAdvChartStyles.FScene.StyleBook) then
      Result := TAdvChartStyles.FScene.StyleBook.Style
    else
      Result := TStyleManager.ActiveStyleForScene(TAdvChartStyles.FScene);
  end
  else
  begin
    frm := Screen.ActiveForm;
    if not Assigned(frm) then
      frm := Application.MainForm;

    if Assigned(frm) and Assigned(frm.StyleBook) then
      Result := frm.StyleBook.Style
    else
      Result := TStyleManager.ActiveStyle(nil);
  end;
end;

class function TAdvChartStyles.IsTransparentStyle(
  AStyle: TFmxObject): Boolean;
var
  st: TStyleDescription;
begin
  Result := False;
  st := TStyleManager.FindStyleDescriptor(AStyle);
  if Assigned(st) then
    Result := LowerCase(st.Title) = 'transparent';
end;

class function TAdvChartStyles.GetStyleAlternateBackgroundFill(
  AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('gridstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('alternatingrowbackground');
      if (Assigned(stobj) and (stobj is TBrushObject)) then
        f.Assign((stobj as TBrushObject).Brush);
    end;
  end;
end;

class function TAdvChartStyles.GetStyleAlternativeSelectionFill(
  AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('memostyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('selection');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          f.Assign((stobj as TRectangle).Fill)
        else if (stobj is TBrushObject) then
          f.Assign((stobj as TBrushObject).Brush)
        else if stobj is TCustomStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TCustomStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleDefaultButtonFill(
  AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('buttonstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          f.Assign((stobj as TRectangle).Fill)
        else if stobj is TCustomStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TCustomStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleBackgroundFill(
  AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('gridstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          f.Assign((stobj as TRectangle).Fill)
        else if stobj is TCustomStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TCustomStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleDefaultButtonStroke(
  AStyle: TFmxObject): TStrokeBrush;
var
  st, stobj: TFmxObject;
  s: TStrokeBrush;
begin
  s := TStrokeBrush.Create(TBrushKind.Solid, claDarkGray);
  Result := s;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('buttonstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          s.Assign((stobj as TRectangle).Stroke);
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleBackgroundStroke(
  AStyle: TFmxObject): TStrokeBrush;
var
  st, stobj: TFmxObject;
  s: TStrokeBrush;
begin
  s := TStrokeBrush.Create(TBrushKind.Solid, claDarkGray);
  Result := s;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('gridstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          s.Assign((stobj as TRectangle).Stroke);
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleAlternativeBackgroundFill(
  AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('memostyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          f.Assign((stobj as TRectangle).Fill)
        else if stobj is TCustomStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TCustomStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleAlternativeBackgroundStroke(
  AStyle: TFmxObject): TStrokeBrush;
var
  st, stobj: TFmxObject;
  s: TStrokeBrush;
begin
  s := TStrokeBrush.Create(TBrushKind.Solid, claDarkGray);
  Result := s;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('memostyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('foreground');
      if Assigned(stobj) then
      begin
        if (stobj is TBrushObject) then
          s.Assign((stobj as TBrushObject).Brush);
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleEditTextColor(AStyle: TFmxObject): TAlphaColor;
var
  st, stobj: TFMXObject;
begin
  Result := claBlack;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('editstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('foreground');
      if (Assigned(stobj) and (stobj is TBrushObject)) then
      begin
        if (Assigned(stobj) and (stobj is TBrushObject)) then
          Result := (stobj as TBrushObject).Brush.Color;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleEditFill(
  AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('editstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          f.Assign((stobj as TRectangle).Fill)
        else if stobj is TCustomStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TCustomStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleEditStroke(
  AStyle: TFmxObject): TStrokeBrush;
var
  st, stobj: TFmxObject;
  s: TStrokeBrush;
begin
  s := TStrokeBrush.Create(TBrushKind.Solid, claDarkGray);
  Result := s;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('editstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          s.Assign((stobj as TRectangle).Stroke);
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleFocusFill(AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('gridstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('focus');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          f.Assign((stobj as TRectangle).Fill)
        else if stobj is TCustomStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TCustomStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleHeaderFill(
  AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('headeritemstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          f.Assign((stobj as TRectangle).Fill)
        else if stobj is TButtonStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TButtonStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleHeaderStroke(
  AStyle: TFmxObject): TStrokeBrush;
var
  st, stobj: TFmxObject;
  s: TStrokeBrush;
begin
  s := TStrokeBrush.Create(TBrushKind.Solid, claDarkGray);
  Result := s;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('headeritemstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('background');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          s.Assign((stobj as TRectangle).Stroke);
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleLineFill(AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('gridstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('linefill');
      if Assigned(stobj) then
      begin
        if (stobj is TBrushObject) then
          f.Assign((stobj as TBrushObject).Brush)
        else if stobj is TCustomStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TCustomStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleSelectionFill(
  AStyle: TFmxObject): TBrush;
var
  st, stobj: TFmxObject;
  f: TBrush;
  bmp: TBitmap;
begin
  f := TBrush.Create(TBrushKind.Solid, claNull);
  Result := f;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('gridstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('selection');
      if Assigned(stobj) then
      begin
        if (stobj is TRectangle) then
          f.Assign((stobj as TRectangle).Fill)
        else if (stobj is TBrushObject) then
          f.Assign((stobj as TBrushObject).Brush)
        else if stobj is TCustomStyleObject then
        begin
          f.Kind := TBrushKind.Bitmap;
          f.Bitmap.WrapMode := TWrapMode.TileStretch;
          bmp := TBitmap.Create(Round(200), Round(200));
          if bmp.Canvas.BeginScene then
          begin
            (stobj as TCustomStyleObject).DrawToCanvas(bmp.Canvas, RectF(-10, -10, bmp.Width + 10, bmp.Height + 10));
            bmp.Canvas.EndScene;
          end;
          f.Bitmap.Bitmap.Assign(bmp);
          bmp.Free;
        end;
      end;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleTextColor(
  AStyle: TFmxObject): TAlphaColor;
var
  st, stobj: TFmxObject;
begin
  Result := claBlack;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('headeritemstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('text');
      if (Assigned(stobj) and (stobj is TText)) then
        Result := (stobj as TText).TextSettings.FontColor;
    end;
  end;
end;

class function TAdvChartStyles.GetStyleTextFont(AStyle: TFmxObject): TFont;
var
  st, stobj: TFmxObject;
begin
  Result := TFont.Create;
  if Assigned(AStyle) then
  begin
    st := AStyle.FindStyleResource('headeritemstyle');
    if Assigned(st) then
    begin
      stobj := st.FindStyleResource('text');
      if (Assigned(stobj) and (stobj is TText)) then
        Result.Assign((stobj as TText).TextSettings.Font);
    end;
  end;
end;
{$ENDIF}

{ TAdvChartStyles }
{$IFDEF FMXLIB}
class function TAdvChartStyles.ExtractColor(
  ABitmap: TBitmap): TAdvChartGraphicsColor;
var
  dt: TBitmapData;
begin
  Result := gcNull;
  if not Assigned(ABitmap) then
    Exit;
  if ABitmap.Map(TMapAccess.Read, dt) then
  begin
    Result := dt.GetPixel(dt.Width div 2, 0);
    ABitmap.Unmap(dt);
  end;
end;

class function TAdvChartStyles.ExtractColorTo(
  ABitmap: TBitmap): TAdvChartGraphicsColor;
var
  dt: TBitmapData;
begin
  Result := gcNull;
  if not Assigned(ABitmap) then
    Exit;
  if ABitmap.Map(TMapAccess.Read, dt) then
  begin
    Result := dt.GetPixel(dt.Width div 2, dt.Height);
    ABitmap.Unmap(dt);
  end;
end;
{$ENDIF}

{$IFDEF VCLLIB}
class function TAdvChartStyles.ExtractColor(AElement: TThemedElementDetails): TAdvChartGraphicsColor;
var
  bmp: TBitmap;
begin
  bmp := TBitmap.Create;
  try
    bmp.SetSize(200, 200);
    StyleServices.DrawElement(bmp.Canvas.Handle, AElement, Rect(0, 0, 200, 200));
    Result := bmp.Canvas.Pixels[bmp.Width div 2, 2];
  finally
    bmp.Free;
  end;
end;

class function TAdvChartStyles.ExtractColorTo(AElement: TThemedElementDetails): TAdvChartGraphicsColor;
var
  bmp: TBitmap;
begin
  bmp := TBitmap.Create;
  try
    bmp.SetSize(200, 200);
    StyleServices.DrawElement(bmp.Canvas.Handle, AElement, Rect(0, 0, 200, 200));
    Result := bmp.Canvas.Pixels[bmp.Width div 2, bmp.Height - 2];
  finally
    bmp.Free;
  end;
end;
{$ENDIF}

class function TAdvChartStyles.GetStyleBackgroundFillColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleBackgroundFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, False);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecFillColor, c);
    if c = clNone then
      c := ExtractColor(l);

    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleBackgroundFillColorTo(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleBackgroundFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, True);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgGradientCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecFillColor, c);
    if c = clNone then
      c := ExtractColorTo(l);

    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleAlternativeBackgroundFillColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleAlternativeBackgroundFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, False);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(teBackgroundNormal);
    c := ExtractColor(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleAlternativeBackgroundFillColorTo(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleAlternativeBackgroundFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, True);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(teBackgroundNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecGradientColor1, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleBackgroundStrokeColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  s: TStrokeBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    s := GetStyleBackgroundStroke(GetStyleSceneObject);
    if Assigned(s) then
    begin
      AColor := ParseBrush(s, False);
      Result := AColor <> claNull;
      s.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecBorderColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleDefaultButtonFillColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleDefaultButtonFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, False);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tcbButtonNormal);
    c := ExtractColor(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleDefaultButtonStrokeColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  s: TStrokeBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    s := GetStyleDefaultButtonStroke(GetStyleSceneObject);
    if Assigned(s) then
    begin
      AColor := ParseBrush(s, False);
      Result := AColor <> claNull;
      s.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tcbButtonNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecBorderColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleHeaderFillColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleHeaderFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, False);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgFixedCellNormal);
    c := ExtractColor(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleHeaderFillColorTo(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleHeaderFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, True);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgFixedCellNormal);
    c := ExtractColorTo(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleHeaderStrokeColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  s: TStrokeBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    s := GetStyleHeaderStroke(GetStyleSceneObject);
    if Assigned(s) then
    begin
      AColor := ParseBrush(s, False);
      Result := AColor <> claNull;
      s.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgFixedCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecBorderColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleLineFillColor(
  var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleLineFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, False);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecBorderColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleSelectionFillColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleSelectionFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, False);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgCellSelected);
    c := clNone;
    StyleServices.GetElementColor(l, ecFillColor, c);
    c := ExtractColor(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleSelectionFillColorTo(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    f := GetStyleSelectionFill(GetStyleSceneObject);
    if Assigned(f) then
    begin
      AColor := ParseBrush(f, True);
      Result := AColor <> claNull;
      f.Free;
    end;
    {$ENDIF}
    {$IFDEF VCLLIB}
    l := StyleServices.GetElementDetails(tgCellSelected);
    c := clNone;
    StyleServices.GetElementColor(l, ecFillColor, c);
    c := ExtractColorTo(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleTextFontColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    AColor := GetStyleTextColor(GetStyleSceneObject);
    Result := AColor <> claNull;
    {$ENDIF}
    {$IFDEF VCLLIB}
    AColor := gcBlack;
    l := StyleServices.GetElementDetails(tgCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecTextColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvChartStyles.GetStyleAlternativeTextFontColor(var AColor: TAdvChartGraphicsColor): Boolean;
{$IFDEF VCLLIB}
var
  l: TThemedElementDetails;
  c: TColor;
{$ENDIF}
begin
  Result := False;
  if StyleServicesEnabled then
  begin
    {$IFDEF FMXLIB}
    AColor := GetStyleEditTextColor(GetStyleSceneObject);
    Result := AColor <> claNull;
    {$ENDIF}
    {$IFDEF VCLLIB}
    AColor := gcBlack;
    l := StyleServices.GetElementDetails(tgCellSelected);
    c := clNone;
    StyleServices.GetElementColor(l, ecTextColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

{$IFDEF FMXLIB}
class procedure TAdvChartStyles.SetActiveScene(AScene: IScene);
begin
  FScene := AScene;
end;
{$ENDIF}

class function TAdvChartStyles.StyleServicesEnabled: Boolean;
{$IFDEF FMXLIB}
var
  s: TFmxObject;
{$ENDIF}
begin
  {$IFDEF LCLLIB}
  Result := False;
  {$ENDIF}
  {$IFDEF FMXLIB}
  s := GetStyleSceneObject;
  Result := Assigned(s);
  {$ENDIF}
  {$IFDEF VCLLIB}
  Result := (StyleServices.Enabled) and (StyleServices.Name <> 'Windows');
  {$ENDIF}
end;

end.
