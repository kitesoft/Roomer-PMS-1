{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{       ExpressCoreLibrary                                           }
{                                                                    }
{       Copyright (c) 1998-2014 Developer Express Inc.               }
{       ALL RIGHTS RESERVED                                          }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSCORELIBRARY AND ALL            }
{   ACCOMPANYING VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY. }
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

unit dxCoreGraphics;

{$I cxVer.inc}

interface

uses
  Windows;

function dxGetBitmapData(ABitmapHandle: HBITMAP; out ABitmapData: Windows.TBitmap): Boolean;
function dxGetBrushData(ABrushHandle: HBRUSH; out ALogBrush: TLogBrush): Boolean; overload;
function dxGetBrushData(ABrushHandle: HBRUSH): TLogBrush; overload;
function dxGetFontData(AFontHandle: HFONT; out ALogFont: TLogFont): Boolean; overload;
function dxGetFontData(AFontHandle: HFONT): TLogFont; overload;
function dxGetPenData(APenHandle: HPEN; out ALogPen: TLogPen): Boolean;

implementation

function dxGetBitmapData(ABitmapHandle: HBITMAP; out ABitmapData: Windows.TBitmap): Boolean;
begin
  Result := GetObject(ABitmapHandle, SizeOf(Windows.TBitmap), @ABitmapData) <> 0;
end;

function dxGetBrushData(ABrushHandle: HBRUSH; out ALogBrush: TLogBrush): Boolean;
begin
  Result := GetObject(ABrushHandle, SizeOf(TLogBrush), @ALogBrush) <> 0;
end;

function dxGetBrushData(ABrushHandle: HBRUSH): TLogBrush;
begin
  dxGetBrushData(ABrushHandle, Result);
end;

function dxGetFontData(AFontHandle: HFONT; out ALogFont: TLogFont): Boolean;
begin
  Result := GetObject(AFontHandle, SizeOf(TLogFont), @ALogFont) <> 0;
end;

function dxGetFontData(AFontHandle: HFONT): TLogFont;
begin
  dxGetFontData(AFontHandle, Result);
end;

function dxGetPenData(APenHandle: HPEN; out ALogPen: TLogPen): Boolean;
begin
  Result := GetObject(APenHandle, SizeOf(TLogPen), @ALogPen) <> 0;
end;

end.
