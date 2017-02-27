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

unit AdvGraphicsStyles;

{$I TMSDEFS.INC}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

{$IFDEF VCLLIB}
{$HINTS OFF}
{$IF COMPILERVERSION > 22}
{$DEFINE VCLSTYLESENABLED}
{$IFEND}
{$ENDIF}

interface

uses
  Classes, Graphics, AdvGraphics
  {$IFDEF FMXLIB}
  ,FMX.Types, Controls, UITypes
  {$ENDIF}
  {$IFDEF VCLSTYLESENABLED}
  ,VCL.Themes
  {$ENDIF}
  ;

type
  IAdvAdaptToStyleEx = interface
  ['{3EFF288D-3927-4E86-8E9D-EF684B501C9E}']
    function GetAdaptToStyle: Boolean;
    procedure SetAdaptToStyle(const Value: Boolean);
    property AdaptToStyle: Boolean read GetAdaptToStyle write SetAdaptToStyle;
  end;

  TAdvGraphicsStyles = class
  private class var
    {$IFDEF FMXLIB}
    FScene: IScene;
    {$ENDIF}
  protected
    {$IFDEF FMXLIB}
    class function ExtractColor(ABitmap: TBitmap): TAdvGraphicsColor; virtual;
    class function ExtractColorTo(ABitmap: TBitmap): TAdvGraphicsColor; virtual;
    {$ENDIF}
    {$IFDEF VCLSTYLESENABLED}
    class function ExtractColor(AElement: TThemedElementDetails): TAdvGraphicsColor; virtual;
    class function ExtractColorTo(AElement: TThemedElementDetails): TAdvGraphicsColor; virtual;
    {$ENDIF}
    {$IFDEF FMXLIB}
    class function ParseBrush(ABrush: TBrush; ASecondColor: Boolean): TAdvGraphicsColor; virtual;
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
    class function GetStyleLineFillColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleBackgroundFillColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleBackgroundFillColorTo(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleAlternativeBackgroundFillColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleAlternativeBackgroundFillColorTo(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleBackgroundStrokeColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleHeaderFillColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleHeaderFillColorTo(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleHeaderStrokeColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleSelectionFillColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleSelectionFillColorTo(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleTextFontColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleAlternativeTextFontColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleDefaultButtonFillColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
    class function GetStyleDefaultButtonStrokeColor(var {%H-}AColor: TAdvGraphicsColor): Boolean; virtual;
  end;

implementation

{$IFDEF FMXLIB}
uses
  UIConsts, FMX.Objects, FMX.Styles, FMX.Styles.Objects, Types, SysUtils, Forms;
{$ENDIF}

{$IFDEF FMXLIB}

class function TAdvGraphicsStyles.ParseBrush(ABrush: TBrush; ASecondColor: Boolean): TAdvGraphicsColor;
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

class function TAdvGraphicsStyles.GetStyleSceneObject: TFmxObject;
var
  frm: TCommonCustomForm;
begin
  if Assigned(TAdvGraphicsStyles.FScene) then
  begin
    if Assigned(TAdvGraphicsStyles.FScene.StyleBook) then
      Result := TAdvGraphicsStyles.FScene.StyleBook.Style
    else
      Result := TStyleManager.ActiveStyleForScene(TAdvGraphicsStyles.FScene);
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

class function TAdvGraphicsStyles.IsTransparentStyle(
  AStyle: TFmxObject): Boolean;
var
  st: TStyleDescription;
begin
  Result := False;
  st := TStyleManager.FindStyleDescriptor(AStyle);
  if Assigned(st) then
    Result := LowerCase(st.Title) = 'transparent';
end;

class function TAdvGraphicsStyles.GetStyleAlternateBackgroundFill(
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

class function TAdvGraphicsStyles.GetStyleAlternativeSelectionFill(
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

class function TAdvGraphicsStyles.GetStyleDefaultButtonFill(
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

class function TAdvGraphicsStyles.GetStyleBackgroundFill(
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

class function TAdvGraphicsStyles.GetStyleDefaultButtonStroke(
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

class function TAdvGraphicsStyles.GetStyleBackgroundStroke(
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

class function TAdvGraphicsStyles.GetStyleAlternativeBackgroundFill(
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

class function TAdvGraphicsStyles.GetStyleAlternativeBackgroundStroke(
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

class function TAdvGraphicsStyles.GetStyleEditTextColor(AStyle: TFmxObject): TAlphaColor;
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

class function TAdvGraphicsStyles.GetStyleEditFill(
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

class function TAdvGraphicsStyles.GetStyleEditStroke(
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

class function TAdvGraphicsStyles.GetStyleFocusFill(AStyle: TFmxObject): TBrush;
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

class function TAdvGraphicsStyles.GetStyleHeaderFill(
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

class function TAdvGraphicsStyles.GetStyleHeaderStroke(
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

class function TAdvGraphicsStyles.GetStyleLineFill(AStyle: TFmxObject): TBrush;
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

class function TAdvGraphicsStyles.GetStyleSelectionFill(
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

class function TAdvGraphicsStyles.GetStyleTextColor(
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

class function TAdvGraphicsStyles.GetStyleTextFont(AStyle: TFmxObject): TFont;
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

{ TAdvGraphicsStyles }
{$IFDEF FMXLIB}
class function TAdvGraphicsStyles.ExtractColor(
  ABitmap: TBitmap): TAdvGraphicsColor;
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

class function TAdvGraphicsStyles.ExtractColorTo(
  ABitmap: TBitmap): TAdvGraphicsColor;
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

{$IFDEF VCLSTYLESENABLED}
class function TAdvGraphicsStyles.ExtractColor(AElement: TThemedElementDetails): TAdvGraphicsColor;
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

class function TAdvGraphicsStyles.ExtractColorTo(AElement: TThemedElementDetails): TAdvGraphicsColor;
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

class function TAdvGraphicsStyles.GetStyleBackgroundFillColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
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

class function TAdvGraphicsStyles.GetStyleBackgroundFillColorTo(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
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

class function TAdvGraphicsStyles.GetStyleAlternativeBackgroundFillColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(teBackgroundNormal);
    c := ExtractColor(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleAlternativeBackgroundFillColorTo(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(teBackgroundNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecGradientColor1, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleBackgroundStrokeColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  s: TStrokeBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tgCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecBorderColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleDefaultButtonFillColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tcbButtonNormal);
    c := ExtractColor(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleDefaultButtonStrokeColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  s: TStrokeBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tcbButtonNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecBorderColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleHeaderFillColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tgFixedCellNormal);
    c := ExtractColor(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleHeaderFillColorTo(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tgFixedCellNormal);
    c := ExtractColorTo(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleHeaderStrokeColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  s: TStrokeBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLLIBVCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tgFixedCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecBorderColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleLineFillColor(
  var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tgCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecBorderColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleSelectionFillColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tgCellSelected);
    c := clNone;
    StyleServices.GetElementColor(l, ecFillColor, c);
    c := ExtractColor(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleSelectionFillColorTo(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF FMXLIB}
var
  f: TBrush;
{$ENDIF}
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    l := StyleServices.GetElementDetails(tgCellSelected);
    c := clNone;
    StyleServices.GetElementColor(l, ecFillColor, c);
    c := ExtractColorTo(l);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleTextFontColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
    AColor := gcBlack;
    l := StyleServices.GetElementDetails(tgCellNormal);
    c := clNone;
    StyleServices.GetElementColor(l, ecTextColor, c);
    AColor := c;
    Result := c <> clNone;
    {$ENDIF}
  end;
end;

class function TAdvGraphicsStyles.GetStyleAlternativeTextFontColor(var AColor: TAdvGraphicsColor): Boolean;
{$IFDEF VCLSTYLESENABLED}
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
    {$IFDEF VCLSTYLESENABLED}
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
class procedure TAdvGraphicsStyles.SetActiveScene(AScene: IScene);
begin
  FScene := AScene;
end;
{$ENDIF}

class function TAdvGraphicsStyles.StyleServicesEnabled: Boolean;
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
  {$IFDEF VCLSTYLESENABLED}
  Result := (StyleServices.Enabled) and (StyleServices.Name <> 'Windows');
  {$ENDIF}
  {$IFNDEF VCLSTYLESENABLED}
  Result := False;
  {$ENDIF}
  {$ENDIF}
end;

end.
