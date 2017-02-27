{********************************************************************}
{                                                                    }
{           Developer Express Visual Component Library               }
{           Express Cross Platform Library classes                   }
{                                                                    }
{           Copyright (c) 2000-2014 Developer Express Inc.           }
{           ALL RIGHTS RESERVED                                      }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSCROSSPLATFORMLIBRARY AND ALL   }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM       }
{   ONLY.                                                            }
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

unit dxDrawRichTextUtils;

{$I cxVer.inc}

interface

uses
  Windows, Controls, Types, Classes, Math, SysUtils, Graphics, RichEdit, ComCtrls;

type
  TdxRichTextHelper = class
  private
    FRichEdit: TRichEdit;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    procedure CalculateTextHeight(ACanvas: TCanvas; var ARect: TRect); virtual;
    procedure DrawText(ACanvas: TCanvas; const ARect: TRect); virtual;
    procedure Init(ACanvas: TCanvas; const AText: string); virtual;
  end;

procedure dxDrawRichEdit(ADC: HDC; const ARect: TRect; ARichHandle: HWND;
  AMinCharIndex, AMaxCharIndex: Integer; ACalculateHeight: Boolean; out AHeight: Integer); overload;
procedure dxDrawRichEdit(ACanvas: TCanvas; const ARect: TRect; ARichEdit: TRichEdit;
  AMinCharIndex, AMaxCharIndex: Integer; ACalculateHeight: Boolean; out AHeight: Integer); overload;
function dxIsRichText(const AText: string): Boolean;
function dxPixelsToTwips(AValue: Integer): Integer;
procedure dxRichLoadFromString(ALines: TStrings; const S: string);

implementation

uses
  cxGeometry, cxClasses, cxGraphics, cxControls;

procedure dxDrawRichEdit(ADC: HDC; const ARect: TRect; ARichHandle: HWND;
  AMinCharIndex, AMaxCharIndex: Integer; ACalculateHeight: Boolean; out AHeight: Integer);

const
  TwipsPerInch = 1440;

  function PrepareRect(const R: TRect): TRect;
  begin
    Result := cxRectSetSize(R,
      dxPixelsToTwips(cxRectWidth(R)),
      IfThen(ACalculateHeight, TwipsPerInch, dxPixelsToTwips(cxRectHeight(R) (*65535*))));
    Result := cxRectSetOrigin(Result, Point(dxPixelsToTwips(R.Left), dxPixelsToTwips(R.Top)));
  end;

var
  AFormatRange: TFormatRange;
  AStartIndex: Integer;
  R: TRect;
begin
  SendMessage(ARichHandle, EM_FORMATRANGE, 0, 0);
  try
    AHeight := 0;
    ZeroMemory(@AFormatRange, SizeOf(AFormatRange));
    AFormatRange.hdc := ADC;
    AFormatRange.hdcTarget := ADC;
    AFormatRange.chrg.cpMin := AMinCharIndex;
    AFormatRange.chrg.cpMax := AMaxCharIndex;
    repeat
      R := PrepareRect(ARect);
      AFormatRange.rc := R;
      AFormatRange.rcPage := cxRectSetNullOrigin(R);
      AStartIndex := AFormatRange.chrg.cpMin;
      AFormatRange.chrg.cpMin := cxSendStructMessage(ARichHandle,
        EM_FORMATRANGE, WPARAM(not ACalculateHeight), AFormatRange);
      if AFormatRange.chrg.cpMin <= AStartIndex then
        Break;
      if ACalculateHeight then
        Inc(AHeight, cxRectHeight(AFormatRange.rc));
    until not ACalculateHeight;
    if ACalculateHeight then
      AHeight := MulDiv(AHeight, GetDeviceCaps(ADC, LOGPIXELSY), TwipsPerInch);
  finally
    SendMessage(ARichHandle, EM_FORMATRANGE, 0, 0);
  end;
end;

procedure dxDrawRichEdit(ACanvas: TCanvas; const ARect: TRect; ARichEdit: TRichEdit;
  AMinCharIndex, AMaxCharIndex: Integer; ACalculateHeight: Boolean; out AHeight: Integer);
begin
  dxDrawRichEdit(ACanvas.Handle, ARect, ARichEdit.Handle,
    AMinCharIndex, AMaxCharIndex, ACalculateHeight, AHeight);
end;

function dxIsRichText(const AText: string): Boolean;
const
  ARichPrefix = '{\rtf';
begin
  Result := Copy(AText, 1, Length(ARichPrefix)) = ARichPrefix;
end;

function dxPixelsToTwips(AValue: Integer): Integer;
begin
  Result:= MulDiv(AValue, 1440, cxGetPixelsPerInch.cy);
end;

procedure dxRichLoadFromString(ALines: TStrings; const S: string);

  procedure PrepareStream(
    AStream: TStringStream);
  begin
  end;

var
  AStream: TStringStream;
{$IFDEF DELPHI12}
  AEncoding: TEncoding;
{$ENDIF}
begin
{$IFDEF DELPHI12}
  if dxIsRichText(S) then
    AEncoding := TEncoding.Default
  else
    AEncoding := TEncoding.Unicode;
{$ENDIF}
  AStream := TStringStream.Create(S{$IFDEF DELPHI12}, AEncoding{$ENDIF});
  try
    PrepareStream(AStream);
    ALines.LoadFromStream(AStream{$IFDEF DELPHI12}, AEncoding{$ENDIF});
  finally
    AStream.Free;
  end;
end;

{ TdxRichTextHelper }

constructor TdxRichTextHelper.Create;
begin
  inherited Create;
  FRichEdit := TRichEdit.Create(nil);
  FRichEdit.ParentWindow := cxMessageWindow.Handle;
  SendMessage(FRichEdit.Handle, EM_SETEVENTMASK, 0, 0);
end;

destructor TdxRichTextHelper.Destroy;
begin
  FreeAndNil(FRichEdit);
  inherited Destroy;
end;

procedure TdxRichTextHelper.CalculateTextHeight(ACanvas: TCanvas; var ARect: TRect);
var
  AHeight: Integer;
begin
  ACanvas.Lock;
  try
    dxDrawRichEdit(ACanvas.Handle, ARect, FRichEdit.Handle, 0, -1, True, AHeight);
    ARect.Bottom := ARect.Top + AHeight;
  finally
    ACanvas.Unlock;
  end;
end;

procedure TdxRichTextHelper.DrawText(ACanvas: TCanvas; const ARect: TRect);
var
  AHeight: Integer;
begin
  ACanvas.Lock;
  try
    dxDrawRichEdit(ACanvas.Handle, ARect, FRichEdit.Handle, 0, -1, False, AHeight);
  finally
    ACanvas.Unlock;
  end;
end;

procedure TdxRichTextHelper.Init(ACanvas: TCanvas; const AText: string);
begin
  FRichEdit.HandleNeeded;
  SetWindowLong(FRichEdit.Handle, GWL_EXSTYLE,
    GetWindowLong(FRichEdit.Handle, GWL_EXSTYLE) or WS_EX_TRANSPARENT);
  FRichEdit.DefAttributes.Assign(ACanvas.Font);
  FRichEdit.DefAttributes.Color := ACanvas.Font.Color;
  dxRichLoadFromString(FRichEdit.Lines, AText);
end;

end.
