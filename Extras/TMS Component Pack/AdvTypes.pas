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

unit AdvTypes;

{$I TMSDEFS.INC}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

{$HINTS OFF}
{$IFDEF LCLLIB}
{$DEFINE USETRECTF}
{$ENDIF}
{$IFDEF VCLLIB}
{$IF COMPILERVERSION < 23}
{$DEFINE USETRECTF}
{$IFEND}
{$ENDIF}
{$HINTS ON}

interface

uses
  {$IFDEF MSWINDOWS}
  Windows,
  {$ENDIF}
  {$IFNDEF LCLLIB}
  {$HINTS OFF}
  {$IF COMPILERVERSION > 22}
  UITypes,
  {$IFEND}
  {$HINTS ON}
  {$ENDIF}
  {$IFDEF LCLLIB}
  LCLType,
  {$ENDIF}
  Types, Classes, Graphics
  ,SysUtils, Controls
  ;

const
  {$IFDEF FMXLIB}
  TMSPlatformsDesktop = pidWin32 or pidWin64 or pidOSX32;
  {$HINTS OFF}
  TMSPlatforms = pidWin32 or pidWin64 or pidOSX32 or pidiOSSimulator or {$IF COMPILERVERSION > 28}pidiOSDevice32 or pidiOSDevice64{$ELSE}pidiOSDevice{$IFEND} or pidAndroid;
  {$HINTS ON}
  KEY_CANCEL = VKCANCEL;
  KEY_CONTROL = VKCONTROL;
  KEY_SHIFT = VKSHIFT;
  KEY_ESCAPE = VKESCAPE;
  KEY_INSERT = VKINSERT;
  KEY_DELETE = VKDELETE;
  KEY_TAB = VKTAB;
  KEY_PRIOR = VKPRIOR;
  KEY_NEXT = VKNEXT;
  KEY_UP = VKUP;
  KEY_DOWN = VKDOWN;
  KEY_RIGHT = VKRIGHT;
  KEY_LEFT = VKLEFT;
  KEY_HOME = VKHOME;
  KEY_END = VKEND;
  KEY_RETURN = VKRETURN;
  KEY_SPACE = VKSPACE;
  KEY_MENU = VKMENU;
  KEY_BACK = VKBACK;
  KEY_F1 = VKF1;
  KEY_F2 = VKF2;
  KEY_F3 = VKF3;
  KEY_F4 = VKF4;
  KEY_F5 = VKF5;
  KEY_F6 = VKF6;
  KEY_F7 = VKF7;
  KEY_F8 = VKF8;
  KEY_F9 = VKF9;
  KEY_F10 = VKF10;
  KEY_F11 = VKF11;
  KEY_F12 = VKF12;
  {$ENDIF}
  {$IFDEF CMNLIB}
  {$IFNDEF LCLLIB}
  {$HINTS OFF}
  {$IF COMPILERVERSION > 22}
  TMSPlatformsDesktop = pidWin32 or pidWin64;
  TMSPlatforms = pidWin32 or pidWin64;
  {$ELSE}
  ssCommand = ssCtrl;
  TMSPlatformsDesktop = 0;
  TMSPlatforms = 0;
  {$IFEND}
  {$HINTS ON}
  {$ENDIF}
  {$IFDEF LCLLIB}
  ssCommand = ssCtrl;
  {$ENDIF}
  KEY_CANCEL = VK_CANCEL;
  KEY_CONTROL = VK_CONTROL;
  KEY_SHIFT = VK_SHIFT;
  KEY_ESCAPE = VK_ESCAPE;
  KEY_INSERT = VK_INSERT;
  KEY_DELETE = VK_DELETE;
  KEY_TAB = VK_TAB;
  KEY_PRIOR = VK_PRIOR;
  KEY_NEXT = VK_NEXT;
  KEY_UP = VK_UP;
  KEY_DOWN = VK_DOWN;
  KEY_RIGHT = VK_RIGHT;
  KEY_LEFT = VK_LEFT;
  KEY_HOME = VK_HOME;
  KEY_END = VK_END;
  KEY_RETURN = VK_RETURN;
  KEY_SPACE = VK_SPACE;
  KEY_MENU = VK_MENU;
  KEY_BACK = VK_BACK;
  KEY_F1 = VK_F1;
  KEY_F2 = VK_F2;
  KEY_F3 = VK_F3;
  KEY_F4 = VK_F4;
  KEY_F5 = VK_F5;
  KEY_F6 = VK_F6;
  KEY_F7 = VK_F7;
  KEY_F8 = VK_F8;
  KEY_F9 = VK_F9;
  KEY_F10 = VK_F10;
  KEY_F11 = VK_F11;
  KEY_F12 = VK_F12;
  {$ENDIF}

type
  TAdvMouseButton = TMouseButton;

  {$IFDEF USETRECTF}

  PSizeF = ^TSizeF;
  TSizeF = record
    cx: Single;
    cy: Single;
  public
    property Width: Single read cx write cx;
    property Height: Single read cy write cy;
  end;

  TPointFType = array [0..1] of Single;

  PPointF = ^TPointF;
  TPointF = record
    function Length: Single;
    procedure Offset(const ADeltaX, ADeltaY: Single);
    case Integer of
      0: (V: TPointFType;);
      1: (X: Single;
          Y: Single;);
  end;

  PRectF = ^TRectF;
  TRectF = record
  private
    function GetWidth: Single;
    procedure SetWidth(const Value: Single);
    function GetHeight: Single;
    procedure SetHeight(const Value: Single);
    function GetSize: TSizeF;
    procedure SetSize(const Value: TSizeF);
  public
    procedure Offset(const DX, DY: Single);
    procedure Inflate(const DX, DY: Single);
    function IsEmpty: Boolean;
    function IntersectsWith(const R: TRectF): Boolean;
    function CenterPoint: TPointF;
    function Empty: TRectF;
    property Width: Single read GetWidth write SetWidth;
    property Height: Single read GetHeight write SetHeight;
    property Size: TSizeF read GetSize write SetSize;
  case Integer of
    0: (Left, Top, Right, Bottom: Single);
    1: (TopLeft, BottomRight: TPointF);
  end;
  {$ENDIF}

  {$IFDEF FMXLIB}
  TAdvBitmap = TBitmap;
  TAdvDrawBitmap = TBitmap;
  {$ENDIF}
  {$IFDEF CMNLIB}
  TAdvBitmap = TPicture;
  TAdvDrawBitmap = TGraphic;
  {$ENDIF}

  TAdvBitmapHelper = class helper for TAdvBitmap
    {$IFDEF VCLLIB}
    procedure LoadFromStream(AStream: TCustomMemoryStream);
    procedure SaveToStream(AStream: TCustomMemoryStream);
    {$ENDIF}
    procedure LoadFromResource(AResourceName: String);
    class function CreateFromResource(AResourceName: String): TAdvBitmap;
  end;

  TAdvMargins = class(TPersistent)
  private
    FRight: Single;
    FBottom: Single;
    FTop: Single;
    FLeft: Single;
    FOnChange: TNotifyEvent;
    procedure SetBottom(const Value: Single);
    procedure SetLeft(const Value: Single);
    procedure SetRight(const Value: Single);
    procedure SetTop(const Value: Single);
    function IsLeftStored: Boolean;
    function IsTopStored: Boolean;
    function IsRightStored: Boolean;
    function IsBottomStored: Boolean;
  protected
    procedure Changed;
  public
    constructor Create; overload;
    constructor Create(const ARect: TRectF); overload;
    procedure Assign(Source: TPersistent); override;
    function Empty: Boolean;
    function Rect: TRectF;
    function PaddingRect(const R: TRectF): TRectF;
  published
    property Left: Single read FLeft write SetLeft stored IsLeftStored nodefault;
    property Top: Single read FTop write SetTop stored IsTopStored nodefault;
    property Right: Single read FRight write SetRight stored IsRightStored nodefault;
    property Bottom: Single read FBottom write SetBottom stored IsBottomStored nodefault;
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  end;

  {$IFNDEF LIMITEDGRAPHICSMODE}
  TAdvScaledBitmap = class(TCollectionItem)
  private
    FBitmap: TAdvBitmap;
    FScale: Single;
    FBitmapName: string;
    function IsScaleStored: Boolean;
    procedure SetBitmap(const Value: TAdvBitmap);
    procedure SetScale(const Value: Single);
    procedure SetBitmapName(const Value: string);
  protected
    procedure BitmapChanged(Sender: TObject);
  public
    constructor Create(Collection: TCollection); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    property Bitmap: TAdvBitmap read FBitmap write SetBitmap;
    property BitmapName: string read FBitmapName write SetBitmapName;
    property Scale: Single read FScale write SetScale stored IsScaleStored nodefault;
  end;

  TAdvScaledBitmaps = class(TOwnedCollection)
  private
    FOnChange: TNotifyEvent;
    function GetItems(Index: Integer): TAdvScaledBitmap;
    procedure SetItems(Index: Integer; const Value: TAdvScaledBitmap);
    function GetBitmap(Scale: Single): TAdvBitmap;
    procedure SetBitmap(Scale: Single; const Value: TAdvBitmap);
  protected
    procedure Update(Item: TCollectionItem); override;
  public
    constructor Create(AOwner: TComponent);
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
    function Add(Scale: Single = 1.0): TAdvScaledBitmap; overload;
    function AddBitmapFromFile(FileName: string; Scale: Single = 1.0): TAdvScaledBitmap;
    function AddBitmapFromResource(ResourceName: String; Scale: Single = 1.0): TAdvScaledBitmap;
    function AddBitmap(Bitmap: TAdvBitmap; Scale: Single = 1.0): TAdvScaledBitmap;
    function AddBitmapName(BitmapName: string; Scale: Single = 1.0): TAdvScaledBitmap;
    function AddDrawBitmap(Bitmap: TAdvDrawBitmap; Scale: Single = 1.0): TAdvScaledBitmap;
    function Insert(Index: Integer): TAdvScaledBitmap; overload;
    function Insert(Index: Integer; Scale: Single): TAdvScaledBitmap; overload;
    function GetBitmapByScale(Scale: Single): TAdvBitmap;
    function GetItemByScale(Scale: Single): TAdvScaledBitmap;
    property Items[Index: Integer]: TAdvScaledBitmap read GetItems write SetItems; default;
    property Bitmaps[Scale: Single]: TAdvBitmap read GetBitmap write SetBitmap;
  end;
  {$ENDIF}

  TAdvPictureFormat = (pfBMP, pfGIF, pfJPG, pfPNG, pfICO, pfTiff, pfMetaFile, pfNone);

  IAdvCustomEditor = interface
    ['{CC0C60B7-75F3-47CE-8A7F-8005A19F12E8}']
    procedure SetText(AValue: String);
    procedure SetSelStart(AValue: Integer);
    procedure SetSelLength(AValue: Integer);
    function GetTextLength: Integer;
  end;

procedure InflateRectEx(var R: TRectF; DX, DY: Single);
function ConvertToRectF(const Rect: TRect): TRectF; overload;
function ConvertToRectF(const Rect: TRectF): TRectF; overload;
function ConvertToRect(const Rect: TRectF): TRect; overload;
function ConvertToRect(const Rect: TRect): TRect; overload;
function ConvertToSizeF(const Size: TSize): TSizeF; overload;
function ConvertToSizeF(const Size: TSizeF): TSizeF; overload;
function ConvertToSize(const Size: TSizeF): TSize; overload;
function ConvertToSize(const Size: TSize): TSize; overload;
function ConvertToPointF(const Point: TPoint): TPointF; overload;
function ConvertToPointF(const Point: TPointF): TPointF; overload;
function ConvertToPoint(const Point: TPointF): TPoint; overload;
function ConvertToPoint(const Point: TPoint): TPoint; overload;
function OffsetRectEx(var R: TRectF; DX, DY: Single): Boolean;
function PtInRectEx(const Rect: TRectF; const P: TPointF): Boolean;
function IntersectRectEx(const Rect1: TRectF; const Rect2: TRectF): Boolean;
function EqualRectEx(const R1, R2: TRectF): Boolean; overload;
function EqualRectEx(const R1, R2: TRect): Boolean; overload;
function GetPointLength(const Point: TPointF): Single;
function MakeRectF(Left, Top, Width, Height: Single): TRectF;
{$IFDEF USETRECTF}
function RectF(Left, Top, Right, Bottom: Single): TRectF; inline; overload;
function PointF(X, Y: Single): TPointF; inline; overload;
{$ENDIF}
function BitmapToDrawBitmap(ABitmap: TAdvBitmap): TAdvDrawBitmap;
function IsBitmapEmpty(ABitmap: TAdvBitmap): Boolean;
function CharInArray(AChar: Char; ACharArray: array of char): Boolean;
function CharIsNumber(AChar: Char): Boolean;
function CharIsLetter(AChar: Char): Boolean;
function CharIsHex(AChar: Char): Boolean;
function CharIsLetterOrNumber(AChar: Char): Boolean;

implementation

uses
  AdvUtils,
  {$IFDEF VCLLIB}
  AnsiStrings,
  {$ENDIF}
  Math
  {$IFDEF VCLLIB}
  ,PNGImage, JPEG, GifImg
  {$ENDIF}
  {$IFNDEF LCLLIB}
  {$HINTS OFF}
  {$IF COMPILERVERSION > 24}
  ,Character
  {$IFEND}
  {$HINTS ON}
  {$ENDIF}
  ;

function CharIsHex(AChar: Char): Boolean;
begin
  {$IFNDEF LCLLIB}
  {$HINTS OFF}
  {$WARNINGS OFF}
  {$IF COMPILERVERSION > 24}
  Result := AChar.IsNumber or AChar.IsInArray(['a', 'b', 'c', 'd', 'e', 'f']) or AChar.IsInArray(['A', 'B', 'C', 'D', 'E', 'F']);
  {$ELSE}
  Result := (AChar in ['0'..'9']) or (AChar in ['a'..'f']) or (AChar in ['A'..'F']);
  {$IFEND}
  {$WARNINGS ON}
  {$HINTS ON}
  {$ENDIF}
  {$IFDEF LCLLIB}
  Result := (AChar in ['0'..'9']) or (AChar in ['a'..'f']) or (AChar in ['A'..'F']);
  {$ENDIF}
end;

function CharIsLetter(AChar: Char): Boolean;
begin
  {$IFNDEF LCLLIB}
  {$HINTS OFF}
  {$WARNINGS OFF}
  {$IF COMPILERVERSION > 24}
  Result := AChar.IsLetter;
  {$ELSE}
  Result := (AChar in ['a'..'z']) or (AChar in ['A'..'Z']);
  {$IFEND}
  {$WARNINGS ON}
  {$HINTS ON}
  {$ENDIF}
  {$IFDEF LCLLIB}
  Result := (AChar in ['a'..'z']) or (AChar in ['A'..'Z']);
  {$ENDIF}
end;

function CharIsNumber(AChar: Char): Boolean;
begin
  {$IFNDEF LCLLIB}
  {$HINTS OFF}
  {$WARNINGS OFF}
  {$IF COMPILERVERSION > 24}
  Result := AChar.IsNumber;
  {$ELSE}
  Result := (AChar in ['0'..'9']);
  {$IFEND}
  {$WARNINGS ON}
  {$HINTS ON}
  {$ENDIF}
  {$IFDEF LCLLIB}
  Result := (AChar in ['0'..'9']);
  {$ENDIF}
end;

function CharIsLetterOrNumber(AChar: Char): Boolean;
begin
  Result := CharIsLetter(AChar) or CharIsNumber(AChar);
end;

function CharInArray(AChar: Char; ACharArray: array of char): Boolean;
var
  ch: Char;
begin
  Result := False;
  for ch in ACharArray do
  begin
    if ch = AChar then
    begin
      Result := True;
      Exit;
    end;
  end;
end;

function IsBitmapEmpty(ABitmap: TAdvBitmap): Boolean;
var
  b: TAdvDrawBitmap;
begin
  Result := True;
  if Assigned(ABitmap) then
  begin
    b := BitmapToDrawBitmap(ABitmap);
    if Assigned(b) then
    begin
      {$IFDEF CMNLIB}
      Result := b.Empty;
      {$ENDIF}
      {$IFDEF FMXLIB}
      Result := b.IsEmpty
      {$ENDIF}
    end;
  end;
end;

function BitmapToDrawBitmap(ABitmap: TAdvBitmap): TAdvDrawBitmap;
begin
  Result := nil;
  if Assigned(ABitmap) then
  begin
    {$IFDEF CMNLIB}
    Result := ABitmap.Graphic;
    {$ENDIF}
    {$IFDEF FMXLIB}
    Result := ABitmap;
    {$ENDIF}
  end;
end;

{ TAdvBitmapHelper }

class function TAdvBitmapHelper.CreateFromResource(
  AResourceName: String): TAdvBitmap;
begin
  Result := TAdvBitmap.Create;
  Result.LoadFromResource(AResourceName);
end;

{$IFDEF VCLLIB}
procedure TAdvBitmapHelper.SaveToStream(AStream: TCustomMemoryStream);
begin
  if Assigned(AStream) then
  begin
    if Assigned(Graphic) then
      Graphic.SaveToStream(AStream);
  end;
end;

procedure TAdvBitmapHelper.LoadFromStream(AStream: TCustomMemoryStream);
var
  pic: TGraphic;
  gcc: TGraphicClass;
begin
  if Assigned(AStream) then
  begin
    pic := nil;
    if TAdvUtils.FindGraphicClass(AStream.Memory^, AStream.Size, gcc) then
      pic := gcc.Create;

    if Assigned(pic) then
    begin
      try
        AStream.Position := 0;
        pic.LoadFromStream(AStream);
        Self.Assign(pic);
      finally
        pic.Free;
      end;
    end;
  end;
end;
{$ENDIF}

procedure TAdvBitmapHelper.LoadFromResource(AResourceName: String);
var
  r: TResourceStream;
  function FindRCData(ModuleHandle: HMODULE; Name: string): boolean;
  begin
    {$IFDEF LCLLIB}
    {$IFDEF MSWINDOWS}
    Result := FindResource(ModuleHandle, PChar(Name), PChar(Windows.RT_RCDATA)) <> 0;
    {$ELSE}
    Result := FindResource(ModuleHandle, PChar(Name), PChar(RT_RCDATA)) <> 0;
    {$ENDIF}
    {$ELSE}
    Result := FindResource(ModuleHandle, PChar(Name), PChar(RT_RCDATA)) <> 0;
    {$ENDIF}
  end;

  function GetResourceStream(AResourceName: string): TResourceStream;
  var
   hst: NativeUInt;
  begin
    Result := nil;
    hst := HInstance;
    if FindRCData(hst, AResourceName) then
    begin
      {$IFDEF LCLLIB}
      {$IFDEF MSWINDOWS}
      Result := TResourceStream.Create(hst, AResourceName, Windows.RT_RCDATA);
      {$ELSE}
      Result := TResourceStream.Create(hst, AResourceName, RT_RCDATA);
      {$ENDIF}
      {$ELSE}
      Result := TResourceStream.Create(hst, AResourceName, RT_RCDATA);
      {$ENDIF}
    end;
  end;
begin
  r := nil;
  try
    r := GetResourceStream(AResourceName);
    if Assigned(r) then
      Self.LoadFromStream(r);
  finally
    if Assigned(r) then
      r.Free;
  end;
end;

{$IFDEF USETRECTF}

{ TRectF }

function TRectF.GetSize: TSizeF;
begin
  Result.cx := Width;
  Result.cy := Height;
end;

procedure TRectF.SetSize(const Value: TSizeF);
begin
  Width := Value.cx;
  Height := Value.cy;
end;

function TRectF.GetHeight: Single;
begin
  Result := Self.Bottom - Self.Top;
end;

procedure TRectF.SetHeight(const Value: Single);
begin
  Self.Bottom := Self.Top + Value;
end;

function TRectF.GetWidth: Single;
begin
  Result := Self.Right - Self.Left;
end;

procedure TRectF.SetWidth(const Value: Single);
begin
  Self.Right := Self.Left + Value;
end;

function TRectF.CenterPoint: TPointF;
begin
  Result.X := (Right - Left) / 2.0 + Left;
  Result.Y := (Bottom - Top) / 2.0 + Top;
end;

function TRectF.IntersectsWith(const R: TRectF): Boolean;
begin
  Result := not ( (Self.BottomRight.X < R.TopLeft.X) or
                  (Self.BottomRight.Y < R.TopLeft.Y) or
                  (R.BottomRight.X < Self.TopLeft.X) or
                  (R.BottomRight.Y < Self.TopLeft.Y) );
end;

procedure TRectF.Offset(const DX, DY: Single);
begin
  TopLeft.Offset(DX, DY);
  BottomRight.Offset(DX, DY);
end;

procedure TRectF.Inflate(const DX, DY: Single);
begin
  TopLeft.Offset(-DX, -DY);
  BottomRight.Offset(DX, DY);
end;

function TRectF.Empty: TRectF;
begin
  Result.Left := 0;
  Result.Top := 0;
  Result.Right := 0;
  Result.Bottom := 0;
end;

function TRectF.IsEmpty: Boolean;
begin
  Result := (Right < Left) or SameValue(Right, Left)
         or (Bottom < Top) or SameValue(Bottom, Top);
end;

procedure TPointF.Offset(const ADeltaX, ADeltaY: Single);
begin
  Self.X := Self.X + ADeltaX;
  Self.Y := Self.Y + ADeltaY;
end;

function TPointF.Length: Single;
begin
  Result := Sqrt(Sqr(X) + Sqr(Y));
end;

function PtInRectEx(const Rect: TRectF; const P: TPointF): Boolean;
begin
  Result := (P.X >= Rect.Left) and (P.X < Rect.Right) and (P.Y >= Rect.Top)
    and (P.Y < Rect.Bottom);
end;

function PointF(X, Y: Single): TPointF;
begin
  Result.X := X;
  Result.Y := Y;
end;

function OffsetRectEx(var R: TRectF; DX, DY: Single): Boolean;
begin
  if @R <> nil then
  begin
    R.Left := R.Left + DX;
    R.Right := R.Right + DX;
    R.Top := R.Top + DY;
    R.Bottom := R.Bottom + DY;
    Result := True;
  end
  else
    Result := False;
end;

function RectF(Left, Top, Right, Bottom: Single): TRectF;
begin
  Result.Left := Left;
  Result.Top := Top;
  Result.Bottom := Bottom;
  Result.Right := Right;
end;

procedure InflateRectEx(var R: TRectF; DX, DY: Single);
begin
  R.Left := R.Left - DX;
  R.Right := R.Right + DX;
  R.Top := R.Top - DY;
  R.Bottom := R.Bottom + DY;
end;

function IntersectRectEx(const Rect1: TRectF; const Rect2: TRectF): Boolean;
begin
  Result := (Rect1.Left < Rect2.Right)
        and (Rect1.Right > Rect2.Left)
        and (Rect1.Top < Rect2.Bottom)
        and (Rect1.Bottom > Rect2.Top);
end;

function EqualRectEx(const R1, R2: TRect): Boolean;
begin
  Result := (R1.Left = R2.Left) and (R1.Right = R2.Right) and
    (R1.Top = R2.Top) and (R1.Bottom = R2.Bottom);
end;

function EqualRectEx(const R1, R2: TRectF): Boolean;
begin
  Result := (R1.Left = R2.Left) and (R1.Right = R2.Right) and
    (R1.Top = R2.Top) and (R1.Bottom = R2.Bottom);
end;

{$ELSE}

function EqualRectEx(const R1, R2: TRect): Boolean;
begin
  Result := EqualRect(R1, R2);
end;

function EqualRectEx(const R1, R2: TRectF): Boolean;
begin
  Result := EqualRect(R1, R2);
end;

function IntersectRectEx(const Rect1: TRectF; const Rect2: TRectF): Boolean;
begin
  Result := IntersectRect(Rect1, Rect2);
end;

function OffsetRectEx(var R: TRectF; DX, DY: Single): Boolean;
begin
  Result := OffsetRect(R, DX, DY);
end;

procedure InflateRectEx(var R: TRectF; DX, DY: Single);
begin
  InflateRect(R, DX, DY);
end;

function PtInRectEx(const Rect: TRectF; const P: TPointF): Boolean;
begin
  Result := PtInRect(Rect, P);
end;

{$ENDIF}

function MakeRectF(Left, Top, Width, Height: Single): TRectF;
begin
  Result.Left := Left;
  Result.Top := Top;
  Result.Width := Width;
  Result.Height := Height;
end;

function GetPointLength(const Point: TPointF): Single;
begin
  Result := Sqrt(Sqr(Point.X) + Sqr(Point.Y));
end;

function ConvertToRect(const Rect: TRect): TRect;
begin
  Result := Rect;
end;

function ConvertToRect(const Rect: TRectF): TRect;
begin
  Result.Left := Round(Rect.Left);
  Result.Top := Round(Rect.Top);
  Result.Right := Round(Rect.Right);
  Result.Bottom := Round(Rect.Bottom);
end;

function ConvertToRectF(const Rect: TRectF): TRectF;
begin
  Result := Rect;
end;

function ConvertToRectF(const Rect: TRect): TRectF;
begin
  Result.Left := Rect.Left;
  Result.Top := Rect.Top;
  Result.Right := Rect.Right;
  Result.Bottom := Rect.Bottom;
end;

function ConvertToPoint(const Point: TPoint): TPoint;
begin
  Result := Point;
end;

function ConvertToPoint(const Point: TPointF): TPoint;
begin
  Result.X := Round(Point.X);
  Result.Y := Round(Point.Y);
end;

function ConvertToPointF(const Point: TPointF): TPointF;
begin
  Result := Point;
end;

function ConvertToPointF(const Point: TPoint): TPointF;
begin
  Result.X := Point.X;
  Result.Y := Point.Y;
end;

function ConvertToSize(const Size: TSize): TSize;
begin
  Result := Size;
end;

function ConvertToSize(const Size: TSizeF): TSize;
begin
  Result.cx := Round(Size.cx);
  Result.cy := Round(Size.cy);
end;

function ConvertToSizeF(const Size: TSizeF): TSizeF;
begin
  Result := Size;
end;

function ConvertToSizeF(const Size: TSize): TSizeF;
begin
  Result.cx := Size.cx;
  Result.cy := Size.cy;
end;

{ TAdvMargins }

procedure TAdvMargins.Assign(Source: TPersistent);
begin
  if Source is TAdvMargins then
  begin
    FLeft := (Source as TAdvMargins).Left;
    FTop := (Source as TAdvMargins).Top;
    FRight := (Source as TAdvMargins).Right;
    FBottom := (Source as TAdvMargins).Bottom;
  end;
end;

procedure TAdvMargins.Changed;
begin
  if Assigned(OnChange) then
    OnChange(Self);
end;

constructor TAdvMargins.Create(const ARect: TRectF);
begin
  FLeft := ARect.Left;
  FBottom := ARect.Bottom;
  FRight := ARect.Right;
  FTop := ARect.Top;
end;

constructor TAdvMargins.Create;
begin
  FLeft := 0;
  FBottom := 0;
  FRight := 0;
  FTop := 0;
end;

function TAdvMargins.Empty: Boolean;
var
  r: TRectF;
begin
  r := RectF(Left, Top, Right, Bottom);
  Result := R.IsEmpty;
end;

procedure TAdvMargins.SetBottom(const Value: Single);
begin
  if FBottom <> Value then
  begin
    FBottom := Value;
    Changed;
  end;
end;

procedure TAdvMargins.SetLeft(const Value: Single);
begin
  if FLeft <> Value then
  begin
    FLeft := Value;
    Changed;
  end;
end;

procedure TAdvMargins.SetRight(const Value: Single);
begin
  if FRight <> Value then
  begin
    FRight := Value;
    Changed;
  end;
end;

procedure TAdvMargins.SetTop(const Value: Single);
begin
  if FTop <> Value then
  begin
    FTop := Value;
    Changed;
  end;
end;

function TAdvMargins.IsLeftStored: Boolean;
begin
  Result := Left <> 0;
end;

function TAdvMargins.IsTopStored: Boolean;
begin
  Result := Top <> 0;
end;

function TAdvMargins.PaddingRect(const R: TRectF): TRectF;
begin
  Result := RectF(R.Left + FLeft, R.Top + FTop, R.Right - FRight, R.Bottom - FBottom);
end;

function TAdvMargins.Rect: TRectF;
begin
  Result := RectF(Left, Top, Right, Bottom);
end;

function TAdvMargins.IsBottomStored: Boolean;
begin
  Result := Bottom <> 0;
end;

function TAdvMargins.IsRightStored: Boolean;
begin
  Result := Right <> 0;
end;

{$IFNDEF LIMITEDGRAPHICSMODE}

{ TAdvScaledBitmap }

procedure TAdvScaledBitmap.Assign(Source: TPersistent);
begin
  if Source is TAdvScaledBitmap then
  begin
    FBitmap.Assign((Source as TAdvScaledBitmap).Bitmap);
    FBitmapName := (Source as TAdvScaledBitmap).BitmapName;
    FScale := (Source as TAdvScaledBitmap).Scale;
  end;
end;

procedure TAdvScaledBitmap.BitmapChanged(Sender: TObject);
begin
  Changed(False);
end;

constructor TAdvScaledBitmap.Create(Collection: TCollection);
begin
  inherited;
  FBitmap := TAdvBitmap.Create;
  FBitmap.OnChange := BitmapChanged;
  FScale := 1.0;
end;

destructor TAdvScaledBitmap.Destroy;
begin
  FBitmap.Free;
  inherited;
end;

function TAdvScaledBitmap.IsScaleStored: Boolean;
begin
  Result := Scale <> 1.0;
end;

procedure TAdvScaledBitmap.SetBitmap(const Value: TAdvBitmap);
begin
  if FBitmap <> Value then
  begin
    FBitmap.Assign(Value);
    Changed(False);
  end;
end;

procedure TAdvScaledBitmap.SetBitmapName(const Value: string);
begin
  if FBitmapName <> Value then
  begin
    FBitmapName := Value;
    Changed(False);
  end;
end;

procedure TAdvScaledBitmap.SetScale(const Value: Single);
begin
  if FScale <> Value then
  begin
    FScale := Value;
    Changed(False);
  end;
end;

{ TAdvScaledBitmaps }

function TAdvScaledBitmaps.Add(Scale: Single = 1.0): TAdvScaledBitmap;
begin
  Result := TAdvScaledBitmap(inherited Add);
  Result.Scale := Scale;
end;

function TAdvScaledBitmaps.AddBitmap(Bitmap: TAdvBitmap; Scale: Single = 1.0): TAdvScaledBitmap;
begin
  Result := Add(Scale);
  Result.Bitmap.Assign(Bitmap);
end;

function TAdvScaledBitmaps.AddBitmapFromFile(FileName: string;
  Scale: Single): TAdvScaledBitmap;
begin
  Result := Add(Scale);
  Result.Bitmap.LoadFromFile(FileName);
end;

function TAdvScaledBitmaps.AddBitmapFromResource(ResourceName: String; Scale: Single = 1.0): TAdvScaledBitmap;
begin
  Result := Add(Scale);
  Result.Bitmap.LoadFromResource(ResourceName);
end;

function TAdvScaledBitmaps.AddBitmapName(BitmapName: string; Scale: Single = 1.0): TAdvScaledBitmap;
begin
  Result := Add(Scale);
  Result.BitmapName := BitmapName;
end;

function TAdvScaledBitmaps.AddDrawBitmap(Bitmap: TAdvDrawBitmap;
  Scale: Single): TAdvScaledBitmap;
begin
  Result := Add(Scale);
  Result.Bitmap.Assign(Bitmap);
end;

constructor TAdvScaledBitmaps.Create(AOwner: TComponent);
begin
  inherited Create(AOwner, TAdvScaledBitmap);
end;

function TAdvScaledBitmaps.GetBitmap(Scale: Single): TAdvBitmap;
begin
  Result := GetBitmapByScale(Scale);
end;

function TAdvScaledBitmaps.GetBitmapByScale(
  Scale: Single): TAdvBitmap;
var
  it: TAdvScaledBitmap;
begin
  Result := nil;
  it := GetItemByScale(Scale);
  if Assigned(it) then
    Result := it.Bitmap;
end;

function TAdvScaledBitmaps.GetItemByScale(Scale: Single): TAdvScaledBitmap;
var
  I: Integer;
  cl: TAdvScaledBitmap;
  it: TAdvScaledBitmap;
  mx: Single;
begin
  Result := nil;
  cl := nil;
  mx := 0;
  for I := 0 to Count - 1 do
  begin
    it := Items[I];
    if it.Scale = Scale then
    begin
      Result := it;
      Break;
    end
    else if (it.Scale <> Scale) and (it.Scale > mx) then
    begin
      cl := it;
      mx := it.Scale;
    end;
  end;

  if Result = nil then
    Result := cl;
end;

function TAdvScaledBitmaps.GetItems(Index: Integer): TAdvScaledBitmap;
begin
  Result := TAdvScaledBitmap(inherited Items[Index]);
end;

function TAdvScaledBitmaps.Insert(Index: Integer;
  Scale: Single): TAdvScaledBitmap;
begin
  Result := TAdvScaledBitmap(inherited Insert(Index));
  Result.Scale := Scale;
end;

function TAdvScaledBitmaps.Insert(Index: integer): TAdvScaledBitmap;
begin
  Result := TAdvScaledBitmap(inherited Insert(Index));
end;

procedure TAdvScaledBitmaps.SetBitmap(Scale: Single;
  const Value: TAdvBitmap);
var
  b: TAdvScaledBitmap;
begin
  b := GetItemByScale(Scale);
  if not Assigned(b) then
    b := Add(Scale);

  b.Bitmap.Assign(Value);
end;

procedure TAdvScaledBitmaps.SetItems(Index: Integer; const Value: TAdvScaledBitmap);
begin
  inherited Items[Index] := Value;
end;

procedure TAdvScaledBitmaps.Update(Item: TCollectionItem);
begin
  inherited;
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

{$ENDIF}

end.

