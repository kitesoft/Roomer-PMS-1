{********************************************************************}
{                                                                    }
{ written by TMS Software                                            }
{            copyright � 2016                                        }
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

unit AdvChartCustomComponent;

{$I TMSDEFS.inc}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

interface

uses
  Classes, Controls;

type
  {$IFDEF CMNLIB}
  TAdvChartCustomComponent = class(TCustomControl)
  private
    FStored: Boolean;
  {$ELSE}
  TAdvChartCustomComponent = class(TControl)
  {$ENDIF}
  private
    FAdaptToStyle: Boolean;
  protected
    procedure SetAdaptToStyle(const Value: Boolean); virtual;
    procedure Paint; override;
    procedure Loaded; override;
    property AdaptToStyle: Boolean read FAdaptToStyle write SetAdaptToStyle default False;
  public
    constructor Create(AOwner: TComponent); override;
    {$IFDEF FMXLIB}
    procedure SetBounds(X, Y, AWidth, AHeight: Single); override;
    {$ENDIF}
    {$IFDEF CMNLIB}
    procedure SetBounds(X, Y, {%H-}AWidth, {%H-}AHeight: Integer); override;
    property Stored: Boolean read FStored write FStored;
    {$ENDIF}
  published
    {$IFDEF FMXLIB}
    {$HINTS OFF}
    {$IF COMPILERVERSION > 27}
    property Size;
    {$IFEND}
    {$HINTS ON}
    property Position;
    {$ENDIF}
    property Visible {$IFNDEF FMXLIB}default False{$ENDIF};
    property Width;
    property Height;
  end;

implementation

uses
  AdvChartUtils, SysUtils, AdvChartTypes, AdvChartGraphics,
  Graphics
  {$IFNDEF LCLLIB}
  ,Types
  {$ENDIF}
  {$IFDEF VCLLIB}
  ,PngImage
  {$ENDIF}
  ;

{ TAdvChartCustomComponent }

constructor TAdvChartCustomComponent.Create(AOwner: TComponent);
begin
  inherited;
  Width := 26;
  Height := 26;
end;

procedure TAdvChartCustomComponent.Loaded;
begin
  inherited;
  if not (csDesigning in ComponentState) then
    Visible := False;
end;

procedure TAdvChartCustomComponent.Paint;
var
  {$IFDEF VCLLIB}
  png: TPngImage;
  {$ENDIF}
  pic: TAdvChartBitmap;
  g: TAdvChartGraphics;
  r: TResourceStream;
begin
  inherited;
  r := nil;
  pic := TAdvChartBitmap.Create;
  {$IFDEF VCLLIB}
  png := TPNGImage.Create;
  {$ENDIF}
  g := TAdvChartGraphics.Create(Canvas);
  try
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcBlack;
    g.DrawRectangle(RectF(0, 0, Width, Height));

    r := TAdvChartUtils.GetResourceStream(UpperCase(ClassName));
    if Assigned(r) then
    begin
      {$IFDEF VCLLIB}
      png.LoadFromStream(r);
      pic.Assign(png);
      {$ELSE}
      pic.LoadFromStream(r);
      {$ENDIF}
    end;

    g.DrawBitmap(0, 0, Width, Height, BitmapToDrawBitmap(pic));
  finally
    if Assigned(r) then
      r.Free;

    pic.Free;
    {$IFDEF VCLLIB}
    png.Free;
    {$ENDIF}
    g.Free;
  end;
end;

procedure TAdvChartCustomComponent.SetAdaptToStyle(const Value: Boolean);
begin
  FAdaptToStyle := Value;
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomComponent.SetBounds(X, Y, AWidth, AHeight: Single);
{$ENDIF}
{$IFDEF CMNLIB}
procedure TAdvChartCustomComponent.SetBounds(X, Y, AWidth, AHeight: Integer);
{$ENDIF}
begin
  inherited SetBounds(X, Y, 26, 26);
end;

end.
