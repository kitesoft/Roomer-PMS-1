unit uVCLUtils;

interface

uses
{$IFDEF MSWINDOWS}
    Winapi.Windows
{$ELSE}
    Macapi.AppKit
{$ENDIF}
    , ComCtrls
    , vcl.Controls
    , System.Classes
    , Dialogs
    , Vcl.Graphics
    , GraphUtil
    , Variants
    , Registry
    , Jpeg
    , pngimage
    , GIFImg
    , IOUtils
    , Data.DB
    , ImgList
    , kbmMemTable
    , Vcl.Forms
    , TypInfo
    , Generics.Defaults
    ;

type
  TImageFileType = (IFT_BMP, IFT_PNG, IFT_JPG, IFT_GIF);


procedure SetCloseButtonEnabled(const form : TForm; const Value: Bool);
// Font value back in one line
function IIF(Condition : Boolean; Alfa, Beta : TFont) : TFont; overload;
function GetPixelColourAsColor(const PixelCoords: TPoint): TColor;
function GetCursorPosForControl(AControl: TWinControl): TPoint;

function ResizeImageToNewTempFile(filename : String; maxWidth, maxHeight : Integer; backColor : TColor) : String;
function DetectImage(const InputFileName: string; BM: TBitmap) : TImageFileType;
procedure ResizeBitmap(Bitmap: TBitmap; Width, Height: Integer; Background: TColor);

function GetHTMLColor(cl: TColor; IsBackColor: Boolean = false): string;
function InverseColor(color: TColor): TColor;
function TrueInverseColor(color: TColor): TColor;

procedure LoadBitmap (il : TImageList; Number : integer; bmp : TBitMap);
procedure LoadImageFromImageList (il : TImageList;
        Number : integer;
        canvas : TCanvas;
        Location : TPoint;
        bkColor : TColor;
        FFColorsToChange : Array of TPoint);
function HexToTColor(sColor: string): TColor;

procedure PlaceFormOnVisibleMonitor(Form : TForm);
procedure SetFormTopmostOn(Form : TForm);
procedure SetFormTopmostOff(Form : TForm);

function GetParentOfType(aControl: TControl; aClassType: TClass): TControl;
function IsChildOfParent(aControl: TControl; aParent: TControl): boolean;
function FindFirstChildControlOfType(aParent: TWinControl; aClassType: TClass): TControl;


implementation

uses
  uUtils
  , SysUtils
  ;

procedure SetCloseButtonEnabled(const form : TForm; const Value: Bool);
var
  hSysMenu: HMENU;
begin
  hSysMenu:= GetSystemMenu(form.Handle, False);
  if hSysMenu <> 0 then begin
    if Value then
      EnableMenuItem(hSysMenu, SC_CLOSE, MF_BYCOMMAND or MF_ENABLED)
    else
      EnableMenuItem(hSysMenu, SC_CLOSE, MF_BYCOMMAND or MF_GRAYED);
    DrawMenuBar(form.Handle);
  end;
end;

// Font value back in one line
function IIF(Condition : Boolean; Alfa, Beta : TFont) : TFont;
begin
  if Condition then
    Result := Alfa
  else
    Result := Beta;
end;

// Use this function in a GUI application to return the color
function GetPixelColourAsColor(const PixelCoords: TPoint): TColor;
var dc: HDC;
begin
  // Get Device Context of windows desktop
  dc := GetDC(0);
  // Read the color of the pixel at the given coordinates
  Result := GetPixel(dc,PixelCoords.X,PixelCoords.Y);
end;

function GetCursorPosForControl(AControl: TWinControl): TPoint;
var
  P: TPoint;
begin
  GetCursorPos(P);
  ScreenToClient(AControl.Handle, P );
  result := P;
end;

function ResizeImageToNewTempFile(filename : String; maxWidth, maxHeight : Integer; backColor : TColor) : String;
var Bmp : TBitmap;
    iWidth, iHeight : Integer;
    imgType : TImageFileType;
    oPNGDest: TPNGImage;
    oJPGDest : TJPegImage;
    oGIFDest : TGifImage;
begin
  Bmp := TBitmap.Create;
  try
    imgType := DetectImage(filename, Bmp);

    if maxHeight = -1 then
      iHeight := Round(Bmp.Height * (maxWidth / Bmp.Width))
    else
      iHeight := maxHeight;

    if maxWidth = -1 then
      iWidth := Round(Bmp.Width * (maxHeight / Bmp.Height))
    else
      iWidth := maxWidth;

    ResizeBitmap(Bmp, iWidth, iHeight, BackColor);
    result := ChangeFileExt(TPath.GetTempFileName, ExtractFileExt(filename));

    case imgType of
      IFT_BMP: begin
                   Bmp.SaveToFile(result);
      end;
      IFT_PNG: begin
                 oPNGDest := TPNGImage.Create;
                 try
                   oPNGDest.Assign(Bmp);
                   oPNGDest.SaveToFile(result);
                 finally
                   oPNGDest.Free;
                 end;
      end;
      IFT_JPG: begin
                 oJPGDest := TJPegImage.Create;
                 try
                   oJPGDest.Assign(Bmp);
                   oJPGDest.SaveToFile(result);
                 finally
                   oJPGDest.Free;
                 end;
      end;
      IFT_GIF: begin
                 oGIFDest := TGifImage.Create;
                 try
                   oGIFDest.Assign(Bmp);
                   oGIFDest.SaveToFile(result);
                 finally
                   oGIFDest.Free;
                 end;
      end;
    end;
  finally
    Bmp.Free;
  end;

end;

function LoadImageToBitmap(Filename : String) : TBitmap;
var
  Picture: TPicture;
begin
  Picture := TPicture.Create;
  try
    Picture.LoadFromFile(filename);
    result := TBitmap.Create;
    result.Width := Picture.Width;
    result.Height := Picture.Height;
    result.Canvas.Draw(0, 0, Picture.Graphic);
  finally
    Picture.Free;
  end;
end;

function DetectImage(const InputFileName: string; BM: TBitmap) : TImageFileType;
var
  FS: TFileStream;
  FirstBytes: AnsiString;
  Graphic: TGraphic;
begin
  Graphic := nil;
  Result := IFT_BMP;
  FS := TFileStream.Create(InputFileName, fmOpenRead);
  try
    SetLength(FirstBytes, 8);
    FS.Read(FirstBytes[1], 8);
    if Copy(FirstBytes, 1, 2) = 'BM' then
    begin
      Graphic := TBitmap.Create;
      result := IFT_BMP;
    end else
    if FirstBytes = #137'PNG'#13#10#26#10 then
    begin
      Graphic := TPngImage.Create;
      result := IFT_PNG;
    end else
    if Copy(FirstBytes, 1, 3) =  'GIF' then
    begin
      Graphic := TGIFImage.Create;
      result := IFT_GIF;
    end else
    if Copy(FirstBytes, 1, 2) = #$FF#$D8 then
    begin
      Graphic := TJPEGImage.Create;
      result := IFT_JPG;
    end;
    if Assigned(Graphic) then
    begin
      try
        FS.Seek(0, soFromBeginning);
        Graphic.LoadFromStream(FS);
        BM.Assign(Graphic);
      except
      end;
      Graphic.Free;
    end;
  finally
    FS.Free;
  end;
end;

procedure ResizeBitmap(Bitmap: TBitmap; Width, Height: Integer; Background: TColor);
var
  B: TBitmap;
begin
  if assigned(Bitmap) then
  begin
    B:= TBitmap.Create;
    try
      ScaleImage(Bitmap, B, Width / Bitmap.Width);
      Bitmap.Assign(B);
    finally
      B.Free;
    end;
  end;
end;

function GetHTMLColor(cl: TColor; IsBackColor: Boolean = false): string;
var
  rgbColor: TColorRef;
begin
  if IsBackColor then
    Result := 'bg'
  else
    Result := '';
  rgbColor := ColorToRGB(cl);
  Result := Result + 'color="#' + Format('%.2x%.2x%.2x',
    [GetRValue(rgbColor), GetGValue(rgbColor), GetBValue(rgbColor)]) + '"';
end;

function InverseColor(color: TColor): TColor;
var
  rgb_: TColorRef;
  Function Inv(b: Byte): Byte;
  Begin
    if b > 128 Then
      Result := 0
    else
      Result := 255;
  End;

begin
  rgb_ := ColorToRGB(color);
  rgb_ := RGB(Inv(GetRValue(rgb_)), Inv(GetGValue(rgb_)), Inv(GetBValue(rgb_)));
  Result := rgb_;
end;

function TrueInverseColor(color: TColor): TColor;
var
  rgb_: TColorRef;
  Function Inv(b: Byte): Byte;
  Begin
    Result := 255 - b;
  End;

begin
  rgb_ := ColorToRGB(color);
  rgb_ := RGB(Inv(GetRValue(rgb_)), Inv(GetGValue(rgb_)), Inv(GetBValue(rgb_)));
  Result := rgb_;
end;

procedure LoadBitmap (il : TImageList; Number : integer; bmp : TBitMap);
var
  ActiveBitmap : TBitMap;
begin
  ActiveBitmap := TBitMap.Create;
  try
    il.GetBitmap (Number, ActiveBitmap);
    bmp.Transparent := true;
    bmp.Height      := ActiveBitmap.Height;
    bmp.Width       := ActiveBitmap.Width;
    bmp.Canvas.Draw (0, 0, ActiveBitmap);
  finally
    ActiveBitmap.Free;
  end
end;

procedure ChangePixelcolorsOnCanvas(Canvas : TCanvas; Rect : TRect; FromColor, ToColor : TColor);
var
  x, y : integer;
begin
  for x := Rect.Left to Rect.Right do
    for y := Rect.Top to Rect.Bottom do
      if Canvas.Pixels[x, y] = FromColor then
        Canvas.Pixels[x, y] := ToColor
end;

procedure LoadImageFromImageList (il : TImageList;
                Number : integer;
                canvas : TCanvas;
                Location : TPoint;
                bkColor : TColor;
                FFColorsToChange : Array of TPoint);
var i : Integer;
    ARect : TRect;
begin
  il.BkColor := bkColor;
  il.DrawingStyle := dsNormal;
  il.Draw(Canvas, Location.X, Location.Y, Number);
  ARect := Rect(Location.X, Location.Y, Location.X + il.Width - 1, Location.Y + il.Height - 1);
  for i := Low(FFColorsToChange) to High(FFColorsToChange) do
    ChangePixelcolorsOnCanvas(Canvas, ARect, FFColorsToChange[i].X, FFColorsToChange[i].Y);
end;


procedure PlaceFormOnVisibleMonitor(Form : TForm);
var
  Monitor: TMonitor;
const
  MoveWinThreshold: Byte = 80;
begin
  // ...
  // 1. Some code to restore the last GUI position and dimension
  // ...

  // 2. Detect the relevant monitor object
  Monitor := Screen.MonitorFromWindow(Form.Handle);
  // 3. Now ensure the just positioned window is visible to the user
  // 3.a. Set minimal visible width
  if Form.Left > Monitor.Left + Monitor.Width - MoveWinThreshold then
    Form.Left := Monitor.Left + Monitor.Width - MoveWinThreshold;
  // 3.b. Set minimal visible height
  if Form.Top > Monitor.Top + Monitor.Height - MoveWinThreshold then
    Form.Top := Monitor.Top + Monitor.Height - MoveWinThreshold;
end;


procedure SetFormTopmostOn(Form : TForm);
begin
  SetWindowPos(Form.Handle, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE or SWP_NOSIZE); // or SWP_NOACTIVATE );
end;

procedure SetFormTopmostOff(Form : TForm);
begin
  SetWindowPos(Form.Handle, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE or SWP_NOSIZE or SWP_NOACTIVATE );
end;

function GetParentOfType(aControl: TControl; aClassType: TClass): TControl;
begin
  Result := aControl.Parent;
  while Assigned(Result) and (not result.ClassType.InheritsFrom(aClassType)) do
    Result := Result.parent;
end;

function IsChildOfParent(aControl: TControl; aParent: TControl): boolean;
var
  ctrl: TControl;
begin
  Result := false;
  ctrl := aControl;
  while not Result and assigned(ctrl.Parent) do
  begin
    Result := ctrl.Parent = aParent;
    ctrl := ctrl.Parent;
  end;
end;

function FindFirstChildControlOfType(aParent: TWinControl; aClassType: TClass): TControl;
var
  i: integer;
begin
  Result := nil;
  for i := 0 to aParent.ControlCount-1 do
  begin
    if aParent.Controls[i].InheritsFrom(aClassType) then
      result := aParent.Controls[i]
    else
      if aParent.Controls[i].InheritsFrom(TWinControl) then
        Result := FindFirstChildCOntrolOfType(TWinControl(aParent.Controls[i]), aClassType);

    if assigned(Result) then
      Break;
  end;
end;

function HexToTColor(sColor: string): TColor;
begin
  result := RGB(StrToInt('$' + copy(sColor, 1, 2)), StrToInt('$' + copy(sColor, 3, 2)), StrToInt('$' + copy(sColor, 5, 2)));
end;

end.
