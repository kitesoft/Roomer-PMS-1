{***************************************************************************}
{ TAdvChartUtil                                                             }
{ for Delphi & C++Builder                                                   }
{                                                                           }
{ written by TMS Software                                                   }
{            copyright © 2013                                               }
{            Email : info@tmssoftware.com                                   }
{            Web : http://www.tmssoftware.com                               }
{                                                                           }
{ The source code is given as is. The author is not responsible             }
{ for any possible damage done due to the use of this code.                 }
{ The component can be freely used in any application. The complete         }
{ source code remains property of the author and may not be distributed,    }
{ published, given or sold in any form as such. No parts of the source      }
{ code can be included in any other component or application without        }
{ written authorization of the author.                                      }
{***************************************************************************}

unit AdvChartUtil;

interface

uses
  Classes, Types, AdvChartGDIP, Graphics, AdvChartGDIPicture;

type
  TChartGradientType = (gtSolid, gtVertical, gtHorizontal, gtForwardDiagonal, gtBackwardDiagonal, gtAngle, gtHatch, gtPath, gtTexture, gtNone);

  TGDIPFillParameters = record
    Graphics: TGPGraphics;
    Path: TGPGraphicsPath;
    Fillpath: boolean;
    R: TGPRectF;
    GT: TChartGradientType;
    ColorFrom: TColor;
    ColorTo: TColor;
    OpacityFrom: integer;
    OpacityTo: integer;
    HatchStyle: THatchStyle;
    Angle: integer;
    Image: TChartGDIPPicture;
    BorderColor: TColor;
    BorderWidth: integer;
    BorderStyle: TDashStyle;
  end;

procedure ShadowGDIP(graphics: TGPGraphics; Rect: TGPRectF);
procedure FillGDIP(Params: TGDIPFillParameters);
procedure ArrowGDIP(graphics: TGPGraphics; origin, target : TPoint; ArrowSize: integer; ArrowColor: TColor; ScaleX, ScaleY: Double);


implementation


procedure ShadowGDIP(graphics: TGPGraphics; Rect: TGPRectF);
var
  path: TGPGraphicsPath;
  pthGrbrush: TGPPathGradientBrush;
  colors:array[0..2] of TGPColor;
  positions: array[0..2] of single;

begin
  path := TGPGraphicsPath.Create;
  path.AddRectangle(Rect);

  pthGrbrush := TGPPathGradientBrush.Create(path);
  pthGrbrush.SetWrapMode(WrapModeClamp);

  colors[0] := MakeColor(0,0,0,0);
  colors[1] := MakeColor(180, clGray);
  colors[2] := MakeColor(180, clGray);

  positions[0] := 0;
  positions[1] := 0.1;
  positions[2] := 1;

  pthGrBrush.SetInterpolationColors(@colors, @positions, 3);

  graphics.FillPath(pthGrBrush, path);

  pthGrBrush.Free;
  path.Free;
end;

procedure FillGDIP(Params: TGDIPFillParameters);
var
  sb: TGPSolidBrush;
  lb: TGPLinearGradientBrush;
  hb: TGPHatchBrush;
  mode: TLinearGradientMode;
  pen: TGPPen;
begin
 case Params.GT of
 gtSolid:
   begin
     sb := TGPSolidBrush.Create(MakeColor(Params.OpacityFrom, Params.ColorFrom));
     if Params.FillPath then
       Params.Graphics.FillPath(sb, Params.Path)
     else
       Params.Graphics.FillRectangle(sb, Params.R);
     sb.Free;
   end;
 gtVertical, gtHorizontal, gtForwardDiagonal, gtBackwardDiagonal:
   begin
     mode := LinearGradientModeVertical;
     if Params.GT = gtHorizontal then
        mode := LinearGradientModeHorizontal;
     if Params.GT = gtForwardDiagonal then
        mode := LinearGradientModeForwardDiagonal;
     if Params.GT = gtBackwardDiagonal then
        mode := LinearGradientModeBackwardDiagonal;

     lb := TGPLinearGradientBrush.Create(Params.R, MakeColor(Params.OpacityFrom, Params.ColorFrom),
        MakeColor(Params.OpacityTo, Params.ColorTo),mode);

     lb.SetGammaCorrection(true);

     if Params.FillPath then
       Params.Graphics.FillPath(lb, Params.Path)
     else
       Params.Graphics.FillRectangle(lb, Params.R);

     lb.Free;
   end;
 gtAngle:
   begin
     lb := TGPLinearGradientBrush.Create(Params.R, MakeColor(Params.OpacityFrom, Params.ColorFrom),
        MakeColor(Params.OpacityTo, Params.ColorTo), Params.Angle, true);
     lb.SetGammaCorrection(true);
     
     if Params.FillPath then
       Params.Graphics.FillPath(lb, Params.Path)
     else
       Params.Graphics.FillRectangle(lb, Params.R);

     lb.Free;
   end;
 gtHatch:
   begin
     hb := TGPHatchBrush.Create(Params.HatchStyle, MakeColor(Params.OpacityFrom, Params.ColorFrom),
        MakeColor(Params.OpacityTo, Params.ColorTo));
     if Params.FillPath then
       Params.Graphics.FillPath(hb, Params.Path)
     else
       Params.Graphics.FillRectangle(hb, Params.R);

     hb.Free;
   end;
 gtPath:
   begin

   end;
 gtTexture:
   begin
     if Assigned(Params.Image) then
     begin
       if Params.FillPath then
         Params.Image.FillPath(Params.Graphics, Params.Path)
       else
         Params.Image.FillRect(Params.Graphics, Params.R);
     end;
   end;
 end;

 if Params.BorderColor <> clNone then
 begin
   pen := TGPPen.Create(MakeColor(Params.OpacityFrom, Params.BorderColor), Params.BorderWidth);

   pen.SetDashStyle(Params.BorderStyle);

   if Params.FillPath then
     Params.Graphics.DrawPath(pen, Params.Path)
   else
     Params.Graphics.DrawRectangle(pen, Params.R);

   pen.Free;
 end;
end;

procedure ArrowGDIP(graphics: TGPGraphics; origin, target : TPoint; ArrowSize: integer; ArrowColor: TColor; ScaleX, ScaleY: Double);
var
  quarter: byte;             // quadrant (tl, tr, br, bl) ?
  fx, px: Integer;
  fy, py: Integer;
  x, y: integer;
  arrowpts: array[0..3] of TGPPointF;
  p: tpoint;
  ar: TPoint;
  h: Integer;
  arx, ary: integer;
  path: TGPGraphicsPath;
  brush: TGPBrush;

begin
  arx := Round(ArrowSize * ScaleX);
  ary := Round(ArrowSize * ScaleY);

  arrowpts[0].x := target.X;
  arrowpts[0].y := target.Y;

  x := target.x - origin.x;
  y := target.y - origin.y;
  h := round(sqrt(sqr(x) + sqr(y)));

  if h = 0 then
    h := 1;

  // quarter?
  if origin.x < target.x then
  begin
    if origin.y < target.y then
      quarter := 1
    else
      quarter := 3;
  end
  else
  begin
    if origin.y < target.y then
      quarter := 2
    else
      quarter := 4;
  end;

  // calculate the actual P position using the adjustments px and py.
  px := x * arx div h;
  py := y * ary div h;
  case quarter of
    1 :
      begin
        p.x := target.x - px;
        p.y := target.y - py;
        ar.x := target.x - (x * arx div h);
        ar.y := target.y - (y * ary div h);
      end;
    2 :
      begin
        p.x := target.x - px;
        p.y := target.y - py;
        ar.x := target.x - (x * arx div h);
        ar.y := target.y - (y * ary div h);
      end;
    3 :
      begin
        p.x := target.x - px;
        p.y := target.y - py;
        ar.x := target.x - (x * arx div h);
        ar.y := target.y - (y * ary div h);
      end;
    4 :
      begin
        p.x := Target.x - px;
        p.y := Target.y - py;
        ar.x := target.x - (x * arx div h);
        ar.y := target.y - (y * ary div h);
      end;
  end;

  //calculate pts[1] and pts[2] from the P position to give us the back of the arrow.
  fx := y * (arx div 2) div h;
  fy := x * (ary div 2) div h;
  case quarter of
    1 :
      begin
        arrowpts[1].x := p.x - fx;
        arrowpts[1].y := p.y + fy;
        arrowpts[3].x := p.x + fx;
        arrowpts[3].y := p.y - fy;
      end;
    2 :
      begin
        arrowpts[1].x := p.x + fx;
        arrowpts[1].y := p.y - fy;
        arrowpts[3].x := p.x - fx;
        arrowpts[3].y := p.y + fy;
      end;
    3 :
      begin
        arrowpts[1].x := p.x + fx;
        arrowpts[1].y := p.y - fy;
        arrowpts[3].x := p.x - fx;
        arrowpts[3].y := p.y + fy;
      end;
    4 :
      begin
        arrowpts[1].x := p.x + fx;
        arrowpts[1].y := p.y - fy;
        arrowpts[3].x := p.x - fx;
        arrowpts[3].y := p.y + fy;
      end;
  end;

  arrowpts[2].x := ar.X;
  arrowpts[2].y := ar.Y;

  path := TGPGraphicsPath.Create;
  path.AddPolygon(PGPPointF(@arrowpts),4);

  brush := TGPSolidBrush.Create(MakeColor(255,ArrowColor));

  graphics.FillPath(brush,path);

  path.Free;
  brush.Free;
end;


end.
