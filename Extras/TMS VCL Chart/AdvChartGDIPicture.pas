{***************************************************************************}
{ TChartGDIPPicture class                                                   }
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

unit AdvChartGDIPicture;

interface

uses
  Windows, Classes, Graphics, Controls , SysUtils, AdvChartGDIP, ComObj, ActiveX;

{$I TMSDEFS.INC}

type

  TChartGDIPPicture = class(TGraphic)
  private
    { Private declarations }
    FDatastream: TMemoryStream;
    FIsEmpty: Boolean;
    FWidth, FHeight: Integer;
    FDoubleBuffered: Boolean;
    FOnClear: TNotifyEvent;
    FBitmapTransparentMode: TTransparentMode;
    FBitmapTransparentColor: TColor;
  protected
    { Protected declarations }
    function GetEmpty: Boolean; override;
    function GetHeight: Integer; override;
    function GetWidth: Integer; override;
    procedure SetHeight(Value: Integer); override;
    procedure SetWidth(Value: Integer); override;
    procedure ReadData(Stream: TStream); override;
    procedure WriteData(Stream: TStream); override;
  public
    { Public declarations }
    constructor Create; override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    function GetImageSizes: boolean;
    procedure Draw(ACanvas: TCanvas; const Rect: TRect); override;
    procedure GDIPDraw(Graphics: TGPGraphics; const Rect: TRect); overload;
    procedure FillRect(graphics: TGPGraphics; R: TGPRectf);
    procedure FillPath(graphics: TGPGraphics; Path: TGPGraphicsPath);
    procedure LoadFromFile(const FileName: string); override;
    procedure LoadFromStream(Stream: TStream); override;
    procedure SaveToStream(Stream: TStream); override;
    procedure LoadFromResourceName(Instance: THandle; const ResName: String);
    procedure LoadFromResourceID(Instance: THandle; ResID: Integer);
    procedure LoadFromURL(url:string);
    procedure LoadFromClipboardFormat(AFormat: Word; AData: THandle;
      APalette: HPALETTE); override;
    procedure SaveToClipboardFormat(var AFormat: Word; var AData: THandle;
      var APalette: HPALETTE); override;
    property DoubleBuffered: Boolean read FDoubleBuffered write FDoubleBuffered;
    property TransparentColor: TColor read FBitmapTransparentColor write FBitmapTransparentColor;
    property TransparentMode: TTransparentMode read FBitmapTransparentMode write FBitmapTransparentMode;
  published
    { Published declarations }
    property OnClear: TNotifyEvent read FOnClear write FOnClear;
  end;




implementation


{ TChartGDIPPicture }

procedure TChartGDIPPicture.Assign(Source: TPersistent);
var
  st: TMemoryStream;
begin
  FIsEmpty := True;
  if Source = nil then
  begin
    FDataStream.Clear;
    FIsEmpty := true;
    if Assigned(OnChange) then
      OnChange(Self);
    if Assigned(OnClear) then
      OnClear(self);
  end
  else
  begin
    if Source is TChartGDIPPicture then
    begin
      FDataStream.LoadFromStream(TChartGDIPPicture(Source).FDataStream);
      FIsEmpty := False;
      if Assigned(OnChange) then
        OnChange(self);
    end
    else
      if Source is TBitmap then
      begin
        st := TMemoryStream.Create;
        (Source as TBitmap).SaveToStream(st);
        st.Position := 0;
        FDataStream.LoadFromStream(st);
        st.Free;
        FIsEmpty := false;
        if Assigned(OnChange) then
          OnChange(self);
      end
      else
        if (Source is TPicture) then
        begin
          st := TMemoryStream.Create;
          (Source as TPicture).Graphic.SaveToStream(st);
          st.Position := 0;
          FDataStream.LoadFromStream(st);
          st.Free;
          FIsEmpty := false;
          if Assigned(OnChange) then
            OnChange(self);
        end;

    GetImageSizes;
  end;
end;

constructor TChartGDIPPicture.Create;
begin
  inherited;
  FDataStream := TMemoryStream.Create;
  FIsEmpty := True;

  Transparent := False;
  FBitmapTransparentMode := tmAuto;
  FBitmapTransparentColor := clWhite;
end;

destructor TChartGDIPPicture.Destroy;
begin
  FDataStream.Free;
  inherited;
end;

procedure TChartGDIPPicture.Draw(ACanvas: TCanvas; const Rect: TRect);
var
  dc: HDC;
  multi: TGPImage;
  graphic: TGPgraphics;
  pstm: IStream;
  hGlobal: THandle;
  pcbWrite: Longint;
  bmp: tbitmap;

begin
  if Empty then
    Exit;

  if FDataStream.Size = 0 then
    Exit;

  hGlobal := GlobalAlloc(GMEM_MOVEABLE, FDataStream.Size);
  if (hGlobal = 0) then
    raise Exception.Create('Could not allocate memory for image');

  try
    pstm := nil;

    // Create IStream* from global memory
    CreateStreamOnHGlobal(hGlobal, TRUE, pstm);
    pstm.Write(FDataStream.Memory, FDataStream.Size,@pcbWrite);

    dc := ACanvas.Handle;
    graphic:= TGPgraphics.Create(dc);
    multi := TGPImage.Create(pstm);

    if multi.GetFormat = ifBMP then
    begin // use this alternative for easy bitmap auto transparent drawing
      bmp := TBitmap.Create;
      FDataStream.Position := 0;
      bmp.LoadFromStream(FDataStream);
      bmp.TransparentMode := tmAuto;
      bmp.Transparent := true;
      ACanvas.Draw(Rect.Left,Rect.Top, bmp);
      bmp.Free;
    end
    else
    begin
      FWidth := multi.GetWidth;
      FHeight := multi.GetHeight;
      graphic.DrawImageRect(multi, Rect.Left, Rect.Top, Rect.Right - Rect.Left, Rect.Bottom - Rect.Top);
    end;

    multi.Free;
    graphic.Free;
  finally
    GlobalFree(hGlobal);
  end;

end;

function TChartGDIPPicture.GetImageSizes: boolean;
var
  multi: TGPImage;
  pstm: IStream;
  hGlobal: THandle;
  pcbWrite: Longint;

begin
  Result := false;

  if Empty then
    Exit;

  if FDataStream.Size = 0 then
    Exit;

  hGlobal := GlobalAlloc(GMEM_MOVEABLE, FDataStream.Size);
  if (hGlobal = 0) then
    raise Exception.Create('Could not allocate memory for image');

  try
    pstm := nil;
    // Create IStream* from global memory
    CreateStreamOnHGlobal(hGlobal, TRUE, pstm);
    pstm.Write(FDataStream.Memory, FDataStream.Size,@pcbWrite);
    multi := TGPImage.Create(pstm);

    FWidth := multi.GetWidth;
    FHeight := multi.GetHeight;

    Result := true;

    multi.Free;
  finally
    GlobalFree(hGlobal);
  end;

end;

procedure TChartGDIPPicture.GDIPDraw(Graphics: TGPGraphics; const Rect: TRect);
var
  multi: TGPImage;
  pstm: IStream;
  hGlobal: THandle;
  pcbWrite: Longint;
  ia: TGPImageAttributes;
  gpColor: TGPColor;
  bmp: TGPBitmap;

begin
  if Empty then
    Exit;

  if FDataStream.Size = 0 then
    Exit;

  hGlobal := GlobalAlloc(GMEM_MOVEABLE, FDataStream.Size);

  if (hGlobal = 0) then
    raise Exception.Create('Could not allocate memory for image');
  try
    pstm := nil;
    // Create IStream* from global memory
    CreateStreamOnHGlobal(hGlobal, TRUE, pstm);
    pstm.Write(FDataStream.Memory, FDataStream.Size,@pcbWrite);
    multi := TGPImage.Create(pstm);

    FWidth := multi.GetWidth;
    FHeight := multi.GetHeight;
    FWidth := multi.GetWidth;
    FHeight := multi.GetHeight;

    if (multi.GetFormat = ifBMP) and (Transparent) then
    begin // use this alternative for easy bitmap auto transparent drawing

      ia := TGPImageAttributes.Create;

      if (FBitmapTransparentMode = tmAuto) then
      begin
        bmp := TGPBitmap.Create(pstm);
        bmp.GetPixel(0,FHeight - 1, gpColor);
        bmp.Free;
      end
      else
        gpColor := MakeColor(255, FBitmapTransparentColor);

      ia.SetColorKey(gpColor, gpColor);

      Graphics.DrawImage(multi,MakeRect(Rect.Left,Rect.Top,FWidth,FHeight),0,0,FWidth,FHeight,UnitPixel,ia);
      ia.Free;

    end
    else
      Graphics.DrawImageRect(multi, Rect.Left, Rect.Top, Rect.Right - Rect.Left, Rect.Bottom - Rect.Top);

    multi.Free;
  finally
    GlobalFree(hGlobal);
  end;
end;

function TChartGDIPPicture.GetEmpty: Boolean;
begin
  Result := FIsEmpty;
end;

procedure TChartGDIPPicture.FillPath(graphics: TGPGraphics; Path: TGPGraphicsPath);
var
  multi: TGPImage;
  pstm: IStream;
  hGlobal: THandle;
  pcbWrite: Longint;
  tb: TGPTextureBrush;
begin
  if Empty then
    Exit;

  if FDataStream.Size = 0 then
    Exit;

  hGlobal := GlobalAlloc(GMEM_MOVEABLE, FDataStream.Size);

  if (hGlobal = 0) then
    raise Exception.Create('Could not allocate memory for image');
  try
    pstm := nil;
    // Create IStream* from global memory
    CreateStreamOnHGlobal(hGlobal, TRUE, pstm);
    pstm.Write(FDataStream.Memory, FDataStream.Size,@pcbWrite);
    multi := TGPImage.Create(pstm);

    tb := TGPTextureBrush.Create(multi);

    Graphics.FillPath(tb,path);

    tb.Free;

    multi.Free;
  finally
    GlobalFree(hGlobal);
  end;
end;


procedure TChartGDIPPicture.FillRect(graphics: TGPGraphics; R: TGPRectf);
var
  multi: TGPImage;
  pstm: IStream;
  hGlobal: THandle;
  pcbWrite: Longint;
  tb: TGPTextureBrush;
begin

  if Empty then
    Exit;

  if FDataStream.Size = 0 then
    Exit;

  hGlobal := GlobalAlloc(GMEM_MOVEABLE, FDataStream.Size);

  if (hGlobal = 0) then
    raise Exception.Create('Could not allocate memory for image');
  try
    pstm := nil;
    // Create IStream* from global memory
    CreateStreamOnHGlobal(hGlobal, TRUE, pstm);
    pstm.Write(FDataStream.Memory, FDataStream.Size,@pcbWrite);
    multi := TGPImage.Create(pstm);

    tb := TGPTextureBrush.Create(multi);

    Graphics.FillRectangle(tb, R);

    tb.Free;

    multi.Free;
  finally
    GlobalFree(hGlobal);
  end;
end;

function TChartGDIPPicture.GetHeight: Integer;
begin
  Result := FHeight;
end;

function TChartGDIPPicture.GetWidth: Integer;
begin
  Result := FWidth;
end;

procedure TChartGDIPPicture.LoadFromFile(const FileName: string);
begin
  try
    FDataStream.LoadFromFile(Filename);

    FIsEmpty := False;

    if Assigned(OnClear) then
      OnClear(self);

    GetImageSizes;

    if Assigned(OnChange) then
      OnChange(self);


  except
    FIsEmpty:=true;
  end;
end;

procedure TChartGDIPPicture.LoadFromStream(Stream: TStream);
begin
  if Assigned(Stream) then
  begin
    FDataStream.LoadFromStream(Stream);
    FIsEmpty := False;

    GetImageSizes;
        
    if Assigned(OnChange) then
      OnChange(self);
  end;
end;

procedure TChartGDIPPicture.ReadData(Stream: TStream);
begin
  if Assigned(Stream) then
  begin
    FDataStream.LoadFromStream(stream);
    FIsEmpty := False;
  end;
end;

procedure TChartGDIPPicture.SaveToStream(Stream: TStream);
begin
  if Assigned(Stream) then
    FDataStream.SaveToStream(Stream);
end;


procedure TChartGDIPPicture.SetHeight(Value: Integer);
begin
  {$IFDEF DELPHI6_LVL}
  inherited;
  {$ENDIF}
end;

procedure TChartGDIPPicture.SetWidth(Value: Integer);
begin
  {$IFDEF DELPHI6_LVL}
  inherited;
  {$ENDIF}
end;

procedure TChartGDIPPicture.LoadFromResourceName(Instance: THandle; const ResName: string);
var
  Stream: TCustomMemoryStream;
begin
  if FindResource(Instance,PChar(ResName),RT_RCDATA) <> 0 then
  begin
    Stream := TResourceStream.Create(Instance, ResName, RT_RCDATA);
    try
      LoadFromStream(Stream);
    finally
      Stream.Free;
    end;
  end;
end;

procedure TChartGDIPPicture.LoadFromResourceID(Instance: THandle; ResID: Integer);
var
  Stream: TCustomMemoryStream;
begin
  Stream := TResourceStream.CreateFromID(Instance, ResID, RT_RCDATA);
  try
    LoadFromStream(Stream);
  finally
    Stream.Free;
  end;
end;

procedure TChartGDIPPicture.WriteData(Stream: TStream);
begin
  if Assigned(Stream) then
  begin
    FDataStream.SaveToStream(stream);
  end;
end;

procedure TChartGDIPPicture.LoadFromURL(url: string);
begin
  if (pos('RES://',UpperCase(url))=1) then
  begin
    Delete(url,1,6);
    if (url<>'') then
      LoadFromResourceName(hinstance,url);
    Exit;
  end;

  if (pos('FILE://',uppercase(url))=1) then
  begin
    Delete(url,1,7);
    if (url<>'')
      then LoadFromFile(url);
  end;
end;

procedure TChartGDIPPicture.LoadFromClipboardFormat(AFormat: Word;
  AData: THandle; APalette: HPALETTE);
begin
end;

procedure TChartGDIPPicture.SaveToClipboardFormat(var AFormat: Word;
  var AData: THandle; var APalette: HPALETTE);
begin
end;


end.
