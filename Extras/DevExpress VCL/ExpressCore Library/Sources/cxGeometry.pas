{********************************************************************}
{                                                                    }
{           Developer Express Visual Component Library               }
{           Express Cross Platform Common Editing Library            }
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
{   LICENSED TO DISTRIBUTE THE COMMONEDITINGLIBRARY AND ALL          }
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

unit cxGeometry;

{$I cxVer.inc}

interface

uses
  Windows, Classes, Types, Math,
  dxCore, dxCoreClasses;

type
  TcxPtInRectType = (ptrtNone, ptrtArea, ptrtLeft, ptrtTop, ptrtRight, ptrtBottom);

  TdxSector = record
    StartAngle: Single;
    SweepAngle: Single;
  end;

  TdxPointF = record
    X: Single;
    Y: Single;
  end;

  TdxSizeF = record
    cx: Single;
    cy: Single;
  end;

  { TcxGeometryObject }

  TcxGeometryObject = class(TcxOwnedPersistent)
  private
    FOnChange: TNotifyEvent;
  protected
    procedure DoChange; virtual;
  public
    procedure LoadFromStream(AStream: TStream); virtual;
    procedure SaveToStream(AStream: TStream); virtual;
    //
    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  end;

  { TcxRect }

  TcxRect = class(TcxGeometryObject)
  private
    FRect: TRect;
    function GetHeight: Integer;
    function GetVertex(AIndex: Integer): TPoint;
    function GetWidth: Integer;
    procedure SetHeight(AValue: Integer);
    procedure SetRect(AValue: TRect);
    procedure SetVertex(AIndex: Integer; const AValue: TPoint);
    procedure SetWidth(AValue: Integer);
  protected
    procedure DoAssign(Source: TPersistent); override;
    procedure ValidateRect(var R: TRect); virtual;
  public
    function GetValue(AIndex: Integer): Integer;
    procedure SetValue(AIndex, AValue: Integer);

    procedure LoadFromStream(AStream: TStream); override;
    procedure SaveToStream(AStream: TStream); override;

    function IsEmpty: Boolean;
    function IsEqual(const ARect: TRect): Boolean; overload;
    function IsEqual(ARect: TcxRect): Boolean; overload;

    property BottomLeft: TPoint index 2 read GetVertex write SetVertex;
    property BottomRight: TPoint index 3 read GetVertex write SetVertex;
    property Height: Integer read GetHeight write SetHeight;
    property Rect: TRect read FRect write SetRect;
    property TopLeft: TPoint index 0 read GetVertex write SetVertex;
    property TopRight: TPoint index 1 read GetVertex write SetVertex;
    property Width: Integer read GetWidth write SetWidth;
  published
    property Left: Integer index 0 read GetValue write SetValue default 0;
    property Top: Integer index 1 read GetValue write SetValue default 0;
    property Right: Integer index 2 read GetValue write SetValue default 0;
    property Bottom: Integer index 3 read GetValue write SetValue default 0;
    property OnChange;
  end;

  { TcxSize }

  TcxSize = class(TcxGeometryObject)
  private
    function GetSize: TSize;
    procedure SetValue(Index, Value: Integer);
  protected
    FSize: TSize;
    procedure DoAssign(Source: TPersistent); override;
    function GetValue(Index: Integer): Integer; virtual;
    function IsSizeStored(Index: Integer): Boolean; virtual;
    procedure SetSize(const Value: TSize); virtual;
  public
    procedure LoadFromStream(AStream: TStream); override;
    procedure SaveToStream(AStream: TStream); override;

    function IsEmpty: Boolean;
    function IsEqual(const ASize: TSize): Boolean; overload;
    function IsEqual(ASize: TcxSize): Boolean; overload;

    property Size: TSize read GetSize write SetSize;
  published
    property Height: Integer index 0 read GetValue write SetValue stored IsSizeStored;
    property Width: Integer index 1 read GetValue write SetValue stored IsSizeStored;
  end;

  { TcxMargin }

  TcxMargin = class(TcxGeometryObject)
  private
    FDefaultValue: Integer;
    FMargin: TRect;
    function GetValue(AIndex: Integer): Integer;
    function IsMarginStored(AIndex: Integer): Boolean;
    procedure SetMargin(const Value: TRect);
    procedure SetValue(AIndex, AValue: Integer);
  protected
    procedure DoAssign(Source: TPersistent); override;
  public
    constructor Create(AOwner: TPersistent; ADefaultValue: Integer = 0); reintroduce;
    procedure LoadFromStream(AStream: TStream); override;
    procedure SaveToStream(AStream: TStream); override;
    function IsEqual(AMargin: TcxMargin): Boolean;

    property Margin: TRect read FMargin write SetMargin;
  published
    property All: Integer index 0 read GetValue write SetValue stored IsMarginStored;
    property Left: Integer index 1 read GetValue write SetValue stored IsMarginStored;
    property Top: Integer index 2 read GetValue write SetValue stored IsMarginStored;
    property Right: Integer index 3 read GetValue write SetValue stored IsMarginStored;
    property Bottom: Integer index 4 read GetValue write SetValue stored IsMarginStored;
  end;


function cxMarginsHeight(const R: TRect): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxMarginsWidth(const R: TRect): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}

// rect helper routines
function cxHalfCoordinate(ASize: Integer): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectCompare(const R1, R2: TRect): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectCenter(const R: TRect): TPoint; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectCenter(const ABounds: TRect; const ASize: TSize): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectCenter(const ABounds: TRect; AWidth, AHeight: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectCenterHorizontally(const R: TRect; AWidth: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectCenterVertically(const R: TRect; AHeight: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectContain(const ABounds, AInner: TRect): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectContent(const R, AMargins: TRect): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectHeight(const R: TRect): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectIntersect(const R1, R2: TRect): Boolean; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectIntersect(out R: TRect; const R1, R2: TRect): Boolean; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectInflate(const R: TRect; DX, DY: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectInflate(const R: TRect; DX1, DY1, DX2, DY2: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectInflate(const R, AMargins: TRect): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectInvert(const R: TRect): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectIsEmpty(const R: TRect): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectIsEqual(const R, R1: TRect): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectIsInvalid(const R: TRect): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectIsNull(const R: TRect): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectGetItem(const ARect: TRect; AIndex: Integer): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectGetSize(const ARect: TRect; AIndex: Integer): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectLeftBottom(const R: TRect): TPoint; {$IFDEF DELPHI9} inline; {$ENDIF}
procedure cxRectMinMaxHeight(const R: TRect; var AMax, AMin: Integer); {$IFDEF DELPHI9} inline; {$ENDIF}
procedure cxRectMinMaxInit(var AMin, AMax: Integer); {$IFDEF DELPHI9} inline; {$ENDIF}
procedure cxRectMinMaxWidth(const R: TRect; var AMax, AMin: Integer); {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectOffset(const R: TRect; const P: TPoint; APositiveFactor: Boolean = True): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectOffset(const R: TRect; const Ps: array of TPoint; APositiveFactor: Boolean = True): TRect; overload;
function cxRectOffset(const R: TRect; DX, DY: Integer; APositiveFactor: Boolean = True): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectOffsetHorz(const R: TRect; DX: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectOffsetVert(const R: TRect; DY: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
procedure cxRectOverlapped(const ASrc, ADst: TRect; out ASrcH, ASrcV, ADstH, ADstV: TRect);
function cxRectPtIn(const R: TRect; const P: TPoint): Boolean; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectPtIn(const R: TRect; const X, Y: Integer): Boolean; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectPtInEx(const R: TRect; X, Y, ADelta: Integer): TcxPtInRectType; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectPtInEx(const R: TRect; X, Y, ADeltaX, ADeltaY: Integer): TcxPtInRectType; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectPtInEx(const R: TRect; const X, Y: Integer; DL, DT, DR, DB: Integer): TcxPtInRectType; overload;
function cxRectRotate(const R: TRect): TRect;
function cxRect(const ASize: TSize): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRect(const ALeft, ATop, ARight, ABottom: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRect(const ATopLeft, ABottomRight: TPoint): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectAdjust(const R: TRect): TRect; 
function cxRectBounds(ALeft, ATop, AWidth, AHeight: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectBounds(const P: TPoint; AWidth, AHeight: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectRightTop(const R: TRect): TPoint; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectScale(const R: TRect; ANumerator, ADenominator: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectScale(const R: TRect; ANumeratorX, ADenominatorX, ANumeratorY, ADenominatorY: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectScaleHeight(const R: TRect; Y1, Y2, H1, H2: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectScaleWidth(const R: TRect; X1, X2, W1, W2: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetBottom(const R: TRect; Y: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetBottom(const R: TRect; Y, H: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetHeight(const R: TRect; H: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetLeft(const R: TRect; X: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetLeft(const R: TRect; X, W: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetOrigin(const R: TRect; const APos: TPoint): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetNullOrigin(const R: TRect): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetTop(const R: TRect; Y: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetTop(const R: TRect; Y, H: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetRight(const R: TRect; X: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetRight(const R: TRect; X, W: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetSize(const R: TRect; W, H: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetSize(const R: TRect; const ASize: TSize): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetWidth(const R: TRect; W: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetWidth(const R: TRect; X, W: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetXPos(const R: TRect; X1, X2: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSetYPos(const R: TRect; Y1, Y2: Integer): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSize(const R: TRect): TSize; {$IFDEF DELPHI9} inline; {$ENDIF}
procedure cxRectSplitHorz(const ABounds: TRect; var ARect1, ARect2: TRect); {$IFDEF DELPHI9} inline; {$ENDIF}
procedure cxRectSplitVert(const ABounds: TRect; var ARect1, ARect2: TRect); {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectSquare(const R: TRect): Integer;
function cxRectTransform(const ARect: TRect; ALeftOffset, ATopOffset,
  ARightOffset, ABottomOffset: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectTransform(const ARect, AOffsets: TRect): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectUnion(const R1, R2: TRect): TRect; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectWidth(const R: TRect): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectProportionalStretch(const R: TRect; const ASize: TSize): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxRectProportionalStretch(const R: TRect; W, H: Integer): TRect; overload; {$IFDEF DELPHI9} inline; {$ENDIF}

// point helper routines
function cxPointInvert(const P: TPoint): TPoint; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPointIsEqual(const P1, P2: TPoint): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPointIsInvalid(const P: TPoint): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPointIsNull(const P: TPoint): Boolean; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPointGetItem(const P: TPoint; AIndex: Integer): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPoint(X, Y: Integer): TPoint; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPoint(const ASize: TSize): TPoint; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPointOffset(const P, DP: TPoint; APositiveFactor: Boolean = True): TPoint; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPointOffset(const P: TPoint; const Ps: array of TPoint; APositiveFactor: Boolean = True): TPoint; overload;
function cxPointOffset(const P: TPoint; X, Y: Integer; APositiveFactor: Boolean = True): TPoint; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPointReplaceItem(const P: TPoint; const AIndex, AValue: Integer): TPoint; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxPointSum(const Ps: array of TPoint): TPoint;
function cxPointsBox(const Ps: array of TPoint): TRect;
procedure cxPointsOffset(var Ps: array of TPoint; DX, DY: Integer); overload;
procedure cxPointsOffset(var Ps: array of TPoint; const AOffset: TPoint); overload;

function cxSize(DX, DY: Integer): TSize; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxSize(const P: TPoint): TSize; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxSize(const R: TRect): TSize; overload; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxSizeIsEmpty(const S1: TSize): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxSizeIsEqual(const S1, S2: TSize): Boolean; {$IFDEF DELPHI9} inline; {$ENDIF}
function cxSizeMax(const S1, S2: TSize): TSize; {$IFDEF DELPHI9} inline; {$ENDIF}

// float routines
function dxPointF(X, Y: Single): TdxPointF; overload;
function dxPointF(const P: TPoint): TdxPointF; overload;
function dxSizeF(DX, DY: Single): TdxSizeF;
function dxPointDistance(const P1, P2: TdxPointF): Single;
function dxPointOffset(const P, AOffset: TdxPointF): TdxPointF; overload;
procedure dxPointsOffset(var Ps: array of TdxPointF; const AOffset: TdxPointF); overload;

function dxRingPtIn(const ARingRect: TRect; const P: TPoint): Boolean;
function dxRingAngle(const ABase, APoint: TdxPointF): Single;
function dxRingPoint(const ABase: TdxPointF; ARadius, AAngle: Single): TdxPointF;
function dxRingRelativePoint(const ABase, APoint: TdxPointF): TdxPointF;
function dxRingRotatePoint(const ABase, APoint: TdxPointF; AAngle: Single): TdxPointF;
procedure dxRingRotatePoints(const ABase: TdxPointF; var APoints: array of TdxPointF; AAngle: Single);

const
  cxInvalidRect: TRect = (Left: -1; Top: -1; Right: -1; Bottom: -1);
  cxSimpleRect: TRect = (Left: 1; Top: 1; Right: 1; Bottom: 1);
  cxInvalidPoint: TPoint = (X: -1; Y: -1);
  cxSimplePoint: TPoint = (X: 1; Y: 1);
  cxInvisiblePoint: TPoint = (X: -10000; Y: -10000);

var
  cxNullRect: TRect;
  cxNullSize: TSize;
  cxNullPoint: TPoint;

implementation

function cxHalfCoordinate(ASize: Integer): Integer; {$IFDEF DELPHI9} inline; {$ENDIF}
begin
  Result := (ASize - Integer(Odd(ASize))) div 2;
end;

function cxRectHeight(const R: TRect): Integer;
begin
  Result := R.Bottom - R.Top;
end;

function cxRectIntersect(const R1, R2: TRect): Boolean;
var
  R: TRect;
begin
  Result := cxRectIntersect(R, R1, R2);
end;

function cxRectIntersect(out R: TRect; const R1,
  R2: TRect): Boolean;
begin
  R.Left := Max(R2.Left, R1.Left);
  R.Top := Max(R2.Top, R1.Top);
  R.Right := Min(R2.Right, R1.Right);
  R.Bottom := Min(R2.Bottom, R1.Bottom);
  Result := not ((R.Right <= R.Left) or (R.Bottom <= R.Top));
  if not Result then
    R := cxNullRect;
end;

function cxRectInflate(const R: TRect; DX, DY: Integer): TRect;
begin
  Result := cxRectInflate(R, DX, DY, DX, DY);
end;

function cxRectInflate(const R: TRect; DX1, DY1, DX2, DY2: Integer): TRect;
begin
  Result := R;
  with Result do
  begin
    Dec(Left, DX1);
    Dec(Top, DY1);
    Inc(Right, DX2);
    Inc(Bottom, DY2);
  end;
end;

function cxRectInflate(const R, AMargins: TRect): TRect;
begin
  with AMargins do
    Result := cxRectInflate(R, Left, Top, Right, Bottom);
end;

function cxRectInvert(const R: TRect): TRect;
begin
  Result.TopLeft := cxPointInvert(R.TopLeft);
  Result.BottomRight := cxPointInvert(R.BottomRight);
end;

function cxRectIsEmpty(const R: TRect): Boolean;
begin
  with R do
    Result := (Right <= Left) or (Bottom <= Top);
end;

function cxRectIsEqual(const R, R1: TRect): Boolean;
begin
  Result := (R.Left = R1.Left) and (R.Top = R1.Top) and
    (R.Right = R1.Right) and (R.Bottom = R1.Bottom);
end;

function cxRectIsInvalid(const R: TRect): Boolean;
begin
  Result := cxRectIsEqual(R, cxInvalidRect);
end;

function cxRectIsNull(const R: TRect): Boolean;
begin
  Result := (R.Left = 0) and (R.Top = 0) and (R.Right = 0) and (R.Bottom = 0);
end;

function cxRectGetItem(const ARect: TRect; AIndex: Integer): Integer;
begin
  case AIndex of
    0:
      Result := ARect.Left;
    1:
      Result := ARect.Top;
    2:
      Result := ARect.Right;
    3:
      Result := ARect.Bottom;
  else
    Result := 0
  end;
end;

function cxRectGetSize(const ARect: TRect; AIndex: Integer): Integer;
begin
  if AIndex = 0 then
    Result := ARect.Right - ARect.Left
  else
    Result := ARect.Bottom - ARect.Top;
end;

function cxRectLeftBottom(const R: TRect): TPoint;
begin
  Result := cxPoint(R.Left, R.Bottom);
end;

procedure cxRectMinMaxHeight(const R: TRect; var AMax, AMin: Integer);
begin
  with R do
  begin
    if AMax < Bottom then AMax := Bottom;
    if AMin > Top then AMin := Top;
  end;
end;

procedure cxRectMinMaxInit(var AMin, AMax: Integer);
begin
  AMin := MaxInt;
  AMax := -1;
end;

procedure cxRectMinMaxWidth(const R: TRect; var AMax, AMin: Integer);
begin
  with R do
  begin
    if AMax < Right then AMax := Right;
    if AMin > Left then AMin := Left;
  end;
end;

function cxRectOffset(const R: TRect; const P: TPoint; APositiveFactor: Boolean = True): TRect;
begin
  Result := cxRectOffset(R, P.X, P.Y, APositiveFactor);
end;

function cxRectOffset(const R: TRect; DX, DY: Integer; APositiveFactor: Boolean = True): TRect;
begin
  Result := cxRect(cxPointOffset(R.TopLeft, DX, DY, APositiveFactor), cxPointOffset(R.BottomRight, DX, DY, APositiveFactor));
end;

function cxRectOffset(const R: TRect; const Ps: array of TPoint; APositiveFactor: Boolean = True): TRect;
begin
  with cxPointSum(Ps) do
    Result := cxRectOffset(R, X, Y, APositiveFactor);
end;

function cxRectOffsetHorz(const R: TRect; DX: Integer): TRect;
begin
  Result := R;
  Inc(Result.Left, DX);
  Inc(Result.Right, DX);
end;

function cxRectOffsetVert(const R: TRect; DY: Integer): TRect;
begin
  Result := R;
  Inc(Result.Top, DY);
  Inc(Result.Bottom, DY);
end;

function GetRectCoordinate(const R: TRect; ABottomRight, AVertCoordinate: Boolean): Integer;
begin
  if ABottomRight then
    if AVertCoordinate then
      Result := R.Bottom
    else
      Result := R.Right
  else
    if AVertCoordinate then
      Result := R.Top
    else
      Result := R.Left;
end;

procedure SetRectCoordinate(var R: TRect; ABottomRight, AVertCoordinate: Boolean; AValue: Integer);
begin
  if ABottomRight then
    if AVertCoordinate then
      R.Bottom := AValue
    else
      R.Right := AValue
  else
    if AVertCoordinate then
      R.Top := AValue
    else
      R.Left := AValue;
end;

procedure cxRectOverlapped(const ASrc, ADst: TRect; out ASrcH, ASrcV, ADstH, ADstV: TRect);
var
  H, W: Integer;

  procedure IncV(const ARect: TRect; AVertCoordinate, ABottomRight: Boolean;
    Value: Integer; out AResult: TRect);
  begin
    if Value <> 0 then
    begin
      AResult := ARect;
      SetRectCoordinate(AResult, ABottomRight, AVertCoordinate,
        GetRectCoordinate(AResult, not ABottomRight, AVertCoordinate) + Value);
    end
    else
      AResult := cxNullRect;
  end;

begin
  H := ASrc.Bottom - ADst.Bottom;
  W := ASrc.Right - ADst.Right;
  IncV(ASrc, True, H < 0, -H, ASrcH);
  IncV(ADst, True, H > 0, H, ADstH);
  IncV(ASrc, False, W < 0, -W, ASrcV);
  IncV(ADst, False, W > 0, W, ADstV);
end;

function cxRectPtIn(const R: TRect; const P: TPoint): Boolean;
begin
  Result := cxRectPtIn(R, P.X, P.Y);
end;

function cxRectPtIn(const R: TRect; const X, Y: Integer): Boolean;
begin
  with R do
    Result := (X >= Left) and (X < Right) and (Y >= Top) and (Y < Bottom);
end;

function cxRectPtInEx(const R: TRect;
  const X, Y: Integer; DL, DT, DR, DB: Integer): TcxPtInRectType;

  function InRange(V, V1, V2: Integer): Boolean;
  begin
    V := V - V1;
    Result := (V >= -V2) and (V < V2);
  end;

begin
  if cxRectPtIn(R, X, Y) then
    Result := ptrtArea
  else
    if cxRectPtIn(cxRectInflate(R, DL, DT, DR, DB), X, Y) then
    begin
      with R do
      begin
        if InRange(X, Right, DR) then
          Result := ptrtRight
        else
          if InRange(Y, Bottom, DB) then
            Result := ptrtBottom
          else
            if InRange(X, Left, DL) then
              Result := ptrtLeft
            else
              Result := ptrtTop;
      end;
    end
    else
      Result := ptrtNone;
end;

function cxRectRotate(const R: TRect): TRect;
begin
  Result := Rect(R.Top, R.Left, R.Bottom, R.Right);
end;

function cxRectPtInEx(const R: TRect; X, Y, ADelta: Integer): TcxPtInRectType;
begin
  Result := cxRectPtInEx(R, X, Y, ADelta, ADelta, ADelta, ADelta);
end;

function cxRectPtInEx(const R: TRect;
  X, Y, ADeltaX, ADeltaY: Integer): TcxPtInRectType;
begin
  Result := cxRectPtInEx(R, X, Y, ADeltaX, ADeltaY, ADeltaX, ADeltaY);
end;

function cxRect(const ASize: TSize): TRect;
begin
  Result.Left := 0;
  Result.Top := 0;
  Result.Right := ASize.cx;
  Result.Bottom := ASize.cy;
end;

function cxRect(const ALeft, ATop, ARight, ABottom: Integer): TRect;
begin
  Result.Left := ALeft;
  Result.Top := ATop;
  Result.Right := ARight;
  Result.Bottom := ABottom;
end;

function cxRect(const ATopLeft, ABottomRight: TPoint): TRect;
begin
  Result.TopLeft := ATopLeft;
  Result.BottomRight := ABottomRight;
end;

function cxRectAdjust(const R: TRect): TRect;
begin
  with R do
    Result := Rect(Min(Left, Right), Min(Top, Bottom), Max(Left, Right), Max(Top, Bottom));
end;

function cxRectBounds(ALeft, ATop, AWidth, AHeight: Integer): TRect;
begin
  Result.Left := ALeft;
  Result.Top := ATop;
  Result.Right := ALeft + AWidth;
  Result.Bottom := ATop + AHeight;
end;

function cxRectBounds(const P: TPoint; AWidth, AHeight: Integer): TRect;
begin
  Result.Left := P.X;
  Result.Top := P.Y;
  Result.Right := P.X + AWidth;
  Result.Bottom := P.Y + AHeight;
end;

function cxRectRightTop(const R: TRect): TPoint;
begin
  Result := cxPoint(R.Right, R.Top);
end;

function cxRectScale(const R: TRect; ANumerator, ADenominator: Integer): TRect;
begin
  Result := cxRectScale(R, ANumerator, ADenominator, ANumerator, ADenominator);
end;

function cxRectScale(const R: TRect; ANumeratorX, ADenominatorX, ANumeratorY, ADenominatorY: Integer): TRect;
begin
  Result.Left := MulDiv(R.Left, ANumeratorX, ADenominatorX);
  Result.Top := MulDiv(R.Top, ANumeratorY, ADenominatorY);
  Result.Right := MulDiv(R.Right, ANumeratorX, ADenominatorX);
  Result.Bottom := MulDiv(R.Bottom, ANumeratorY, ADenominatorY);
end;

function cxRectScaleHeight(const R: TRect; Y1, Y2, H1, H2: Integer): TRect;
var
  H: Integer;
begin
  Result := R;
  with Result do
  begin
    H := MulDiv(Bottom - Top, H2, H1);
    Top := MulDiv(Y1 - Top, H2, H1) + Y2;
    Bottom := Top + H;
  end;
end;

function cxRectScaleWidth(const R: TRect; X1, X2, W1,
  W2: Integer): TRect;
var
  L: Integer;
begin
  Result := R;
  with Result do
  begin
    L := MulDiv(Right - Left, W2, W1);
    Left := MulDiv(X1 - Left, W2, W1) + X2;
    Right := Left + L;
  end;
end;

function cxRectSetBottom(const R: TRect; Y: Integer): TRect; 
begin
  Result := cxRectSetBottom(R, Y, R.Bottom - R.Top);
end;

function cxRectSetBottom(const R: TRect; Y, H: Integer): TRect;
begin
  Result := R;
  Result.Bottom := Y;
  Result.Top := Y - H;
end;

function cxRectSetHeight(const R: TRect; H: Integer): TRect;
begin
  Result := R;
  Result.Bottom := Result.Top + H;
end;

function cxRectSetLeft(const R: TRect; X: Integer): TRect;
begin
  Result := cxRectSetLeft(R, X, R.Right - R.Left);
end;

function cxRectSetLeft(const R: TRect; X, W: Integer): TRect;
begin
  Result := R;
  Result.Left := X;
  Result.Right := X + W;
end;

function cxRectSetOrigin(const R: TRect; const APos: TPoint): TRect;
begin
  Result := cxRectOffset(R, APos.X - R.Left, APos.Y - R.Top);
end;

function cxRectSetNullOrigin(const R: TRect): TRect;
begin
  Result := cxRectSetOrigin(R, cxNullPoint);
end;

function cxRectSetTop(const R: TRect; Y: Integer): TRect;
begin
  Result := cxRectSetTop(R, Y, R.Bottom - R.Top);
end;

function cxRectSetTop(const R: TRect; Y, H: Integer): TRect;
begin
  Result := R;
  Result.Top := Y;
  Result.Bottom := Y + H;
end;

function cxRectSetRight(const R: TRect; X: Integer): TRect;
begin
  Result := cxRectSetRight(R, X, R.Right - R.Left);
end;

function cxRectSetRight(const R: TRect; X, W: Integer): TRect;
begin
  Result := R;
  Result.Right := X;
  Result.Left := X - W;
end;

function cxRectSetSize(const R: TRect; W, H: Integer): TRect;
begin
  Result := R;
  with R do
  begin
    Result.Right := Left + W;
    Result.Bottom := Top + H;
  end;
end;

function cxRectSetSize(const R: TRect; const ASize: TSize): TRect;
begin
  Result := R;
  Result.Right := Result.Left + ASize.cx;
  Result.Bottom := Result.Top + ASize.cy;
end;

function cxRectSetWidth(const R: TRect; W: Integer): TRect;
begin
  Result := R;
  Result.Right := R.Left + W;
end;

function cxRectSetWidth(const R: TRect; X, W: Integer): TRect;
begin
  Result := R;
  Result.Left := X;
  Result.Right := X + W;
end;

function cxRectSetXPos(const R: TRect; X1, X2: Integer): TRect;
begin
  with R do
    Result := cxRect(X1, Top, X2, Bottom);
end;

function cxRectSetYPos(const R: TRect; Y1, Y2: Integer): TRect;
begin
  with R do
    Result := cxRect(Left, Y1, Right, Y2);
end;

function cxRectSize(const R: TRect): TSize;
begin
  with R do
  begin
    Result.cx := Right - Left;
    Result.cy := Bottom - Top;
  end;
end;

procedure cxRectSplitHorz(const ABounds: TRect; var ARect1, ARect2: TRect);
begin
  ARect1 := ABounds;
  ARect2 := ABounds;
  ARect1.Right := (ABounds.Right + ABounds.Left) div 2;
  ARect2.Left := ARect1.Right;
end;

function cxRectSquare(const R: TRect): Integer;
begin
  Result := (R.Right - R.Left) * (R.Bottom - R.Top);
end;

procedure cxRectSplitVert(const ABounds: TRect; var ARect1, ARect2: TRect);
begin
  ARect1 := ABounds;
  ARect2 := ABounds;
  ARect1.Bottom := (ABounds.Bottom + ABounds.Top) div 2;
  ARect2.Top := ARect1.Bottom;
end;

function cxRectTransform(const ARect: TRect; ALeftOffset, ATopOffset,
  ARightOffset, ABottomOffset: Integer): TRect;
begin
  Result := ARect;
  Inc(Result.Left, ALeftOffset);
  Inc(Result.Top, ATopOffset);
  Inc(Result.Right, ARightOffset);
  Inc(Result.Bottom, ABottomOffset);
end;

function cxRectTransform(const ARect, AOffsets: TRect): TRect;
begin
  with AOffsets do
    Result := cxRectTransform(ARect, Left, Top, Right, Bottom);
end;

function cxRectUnion(const R1, R2: TRect): TRect;
begin
  Result := R1;
  if (R2.Right - R2.Left <= 0) or (R2.Bottom - R2.Top <= 0) then Exit;
  if R2.Left < R1.Left then
    Result.Left := R2.Left;
  if R2.Top < R1.Top then
    Result.Top := R2.Top;
  if R2.Right > R1.Right then
    Result.Right := R2.Right;
  if R2.Bottom > R1.Bottom then
    Result.Bottom := R2.Bottom;
end;

function cxRectWidth(const R: TRect): Integer;
begin
  Result := R.Right - R.Left;
end;

function cxRectProportionalStretch(const R: TRect; const ASize: TSize): TRect;
begin
  Result := cxRectProportionalStretch(R, ASize.cx, ASize.cy);
end;

function cxRectProportionalStretch(const R: TRect; W, H: Integer): TRect;
var
  ARatio: Double;
  W1, H1: Integer;
begin
  Result := R;
  W1 := cxRectWidth(R);
  H1 := cxRectHeight(R);
  if (W1 > 0) and (H1 > 0) and (W > 0) and (H > 0) then
  begin
    ARatio := W / H; 
    if ARatio > W1 / H1 then
      Result.Bottom := Result.Top + Trunc(W1 / ARatio)
    else
      Result.Right := Result.Left + Trunc(H1 * ARatio);
  end;
end;

function cxMarginsHeight(const R: TRect): Integer;
begin
  Result := R.Top + R.Bottom;
end;

function cxMarginsWidth(const R: TRect): Integer;
begin
  Result := R.Left + R.Right;
end;

function cxRectCompare(const R1, R2: TRect): Boolean;
begin
  Result := cxRectIsEqual(R1, R2);
end;

function cxRectCenter(const R: TRect): TPoint;
begin
  Result := cxPoint(cxHalfCoordinate(R.Right + R.Left), cxHalfCoordinate(R.Bottom + R.Top));
end;

function cxRectCenter(const ABounds: TRect; const ASize: TSize): TRect;
begin
  Result := cxRectCenter(ABounds, ASize.cx, ASize.cy)
end;

function cxRectCenter(const ABounds: TRect; AWidth, AHeight: Integer): TRect;
begin
  Result.Left := cxHalfCoordinate(ABounds.Left + ABounds.Right - AWidth);
  Result.Top := cxHalfCoordinate(ABounds.Top + ABounds.Bottom - AHeight);
  Result.Right := Result.Left + AWidth;
  Result.Bottom := Result.Top + AHeight;
end;

function cxRectCenterHorizontally(const R: TRect; AWidth: Integer): TRect;
begin
  Result := R;
  Result.Left := cxHalfCoordinate(R.Left + R.Right - AWidth);
  Result.Right := Result.Left + AWidth;
end;

function cxRectCenterVertically(const R: TRect; AHeight: Integer): TRect;
begin
  Result := R;
  Result.Top := cxHalfCoordinate(R.Top + R.Bottom - AHeight);
  Result.Bottom := Result.Top + AHeight;
end;

function cxRectContain(const ABounds, AInner: TRect): Boolean;
begin
  with ABounds do
    Result := (Left <= AInner.Left) and (Right >= AInner.Right) and
      (Top <= AInner.Top) and (Bottom >= AInner.Bottom);
end;

function cxRectContent(const R, AMargins: TRect): TRect;
begin
  with Result do
  begin
    Left := R.Left + AMargins.Left;
    Top := R.Top + AMargins.Top;
    Right := R.Right - AMargins.Right;
    Bottom := R.Bottom - AMargins.Bottom;
  end;
end;

function cxPointInvert(const P: TPoint): TPoint;
begin
  Result.X := -P.X;
  Result.Y := -P.Y;
end;

function cxPointIsEqual(const P1, P2: TPoint): Boolean;
begin
  Result := (P1.X = P2.X) and (P1.Y = P2.Y);
end;

function cxPointIsInvalid(const P: TPoint): Boolean;
begin
  Result := cxPointIsEqual(P, cxInvalidPoint);
end;

function cxPointIsNull(const P: TPoint): Boolean;
begin
  Result := (P.X = cxNullPoint.X) and (P.Y = cxNullPoint.Y);
end;

function cxPointGetItem(const P: TPoint; AIndex: Integer): Integer;
begin
  if AIndex = 0 then
    Result := P.X
  else
    Result := P.Y;
end;

function cxPointOffset(const P: TPoint; const Ps: array of TPoint; APositiveFactor: Boolean = True): TPoint;
begin
  with cxPointSum(Ps) do
    Result := cxPointOffset(P, X, Y, APositiveFactor);
end;

function cxPointOffset(const P: TPoint; X, Y: Integer; APositiveFactor: Boolean = True): TPoint;
begin
  if APositiveFactor then
    Result := cxPoint(P.X + X, P.Y + Y)
  else
    Result := cxPoint(P.X - X, P.Y - Y);
end;

function cxPointOffset(const P, DP: TPoint; APositiveFactor: Boolean = True): TPoint;
begin
  Result := cxPointOffset(P, DP.X, DP.Y, APositiveFactor);
end;

function cxPointReplaceItem(const P: TPoint; const AIndex, AValue: Integer): TPoint;
begin
  if AIndex = 0 then
    Result.X := AValue
  else
    Result.Y := AValue;
end;

function cxPoint(X, Y: Integer): TPoint;
begin
  Result.X := X;
  Result.Y := Y;
end;

function cxPoint(const ASize: TSize): TPoint;
begin
  with Result do
  begin
    X := ASize.cx;
    Y := ASize.cy;
  end;
end;

function cxPointSum(const Ps: array of TPoint): TPoint;
var
  I: Integer;
begin
  if Length(Ps) >= 1 then
  begin
    Result := Ps[Low(Ps)];
    for I := Low(Ps) + 1 to High(Ps) do
      with Ps[I] do
      begin
        Inc(Result.X, X);
        Inc(Result.Y, Y);
      end;
  end
  else
    Result := cxNullPoint;
end;

function cxPointsBox(const Ps: array of TPoint): TRect;
var
  I: Integer;
begin
  if Length(Ps) > 0 then
  begin
    Result := cxRect(Ps[Low(Ps)], Ps[Low(Ps)]);
    for I := Low(Ps) + 1 to High(Ps) do
      with Ps[I] do
      begin
        Result.Bottom := Max(Result.Bottom, Y);
        Result.Left := Min(Result.Left, X);
        Result.Right := Max(Result.Right, X);
        Result.Top := Min(Result.Top, Y);
      end;
  end
  else
    Result := cxNullRect;
end;

procedure cxPointsOffset(var Ps: array of TPoint; DX, DY: Integer);
var
  I: Integer;
begin
  for I := Low(Ps) to High(Ps) do
    with Ps[I] do
    begin
      Inc(X, DX);
      Inc(Y, DY);
    end;
end;

procedure cxPointsOffset(var Ps: array of TPoint; const AOffset: TPoint);
begin
  cxPointsOffset(Ps, AOffset.X, AOffset.Y);
end;

function cxSize(DX, DY: Integer): TSize;
begin
  Result.cx := DX;
  Result.cy := DY;
end;

function cxSize(const P: TPoint): TSize;
begin
  Result.cx := P.X;
  Result.cy := P.Y;
end;

function cxSize(const R: TRect): TSize;
begin
  Result.cx := cxRectWidth(R);
  Result.cy := cxRectHeight(R);
end;

function cxSizeIsEmpty(const S1: TSize): Boolean;
begin
  Result := cxSizeIsEqual(S1, cxNullSize);
end;

function cxSizeIsEqual(const S1, S2: TSize): Boolean;
begin
  Result := (S1.cx = S2.cx) and (S1.cy = S2.cy);
end;

function cxSizeMax(const S1, S2: TSize): TSize;
begin
  Result := cxSize(Max(S1.cx, S2.cx), Max(S1.cy, S2.cy));
end;

function dxPointF(X, Y: Single): TdxPointF;
begin
  Result.X := X;
  Result.Y := Y;
end;

function dxPointF(const P: TPoint): TdxPointF;
begin
  Result.X := P.X;
  Result.Y := P.Y;
end;

function dxSizeF(DX, DY: Single): TdxSizeF;
begin
  Result.cx := DX;
  Result.cy := DY;
end;

function dxPointDistance(const P1, P2: TdxPointF): Single;
begin
  Result := Sqrt(Sqr(P1.X - P2.X) + Sqr(P1.Y - P2.Y));
end;

function dxPointOffset(const P, AOffset: TdxPointF): TdxPointF;
begin
  Result.X := P.X + AOffset.X;
  Result.Y := P.Y + AOffset.Y;
end;

procedure dxPointsOffset(var Ps: array of TdxPointF; const AOffset: TdxPointF);
var
  I: Integer;
begin
  for I := Low(Ps) to High(Ps) do
    Ps[I] := dxPointOffset(Ps[I], AOffset);
end;

function dxRingPtIn(const ARingRect: TRect; const P: TPoint): Boolean;
var
  ABase: TdxPointF;
  ARingRadius: Single;
begin
  ABase.X := (ARingRect.Left + ARingRect.Right) / 2;
  ABase.Y := (ARingRect.Top + ARingRect.Bottom) / 2;
  ARingRadius := Min(cxRectWidth(ARingRect), cxRectHeight(ARingRect)) / 2;
  Result := dxPointDistance(dxPointF(P), ABase) < ARingRadius;
end;

function dxRingAngle(const ABase, APoint: TdxPointF): Single;
var
  ASign: TPoint;
  PC: TdxPointF;
begin
  PC := dxRingRelativePoint(ABase, APoint);
  if PC.X = 0 then
    PC.X := 0.00001;
  if PC.Y = 0 then
    PC.Y := 0.00001;
  Result := ArcTan(Abs(PC.Y) / Abs(PC.X));
  ASign := Point(Sign(PC.X), Sign(PC.Y));
  if (ASign.X = -1) and (ASign.Y = 1) then
    Result := Pi - Result
  else
    if (ASign.X = -1) and (ASign.Y = -1) then
      Result := Pi + Result
    else
      if (ASign.X = 1) and (ASign.Y = -1) then
        Result := 2 * Pi - Result;
end;

function dxRingPoint(const ABase: TdxPointF; ARadius, AAngle: Single): TdxPointF;
begin
  Result := dxPointF(ABase.X + ARadius * Cos(AAngle), ABase.Y - ARadius * Sin(AAngle));
end;

function dxRingRelativePoint(const ABase, APoint: TdxPointF): TdxPointF;
begin
  Result := dxPointF(APoint.X - ABase.X, ABase.Y - APoint.Y);
end;

function dxRingRotatePoint(const ABase, APoint: TdxPointF; AAngle: Single): TdxPointF;
var
  A1, A2: Single;
begin
  A1 := dxRingAngle(ABase, APoint);
  A2 := A1 + AAngle;
  Result := dxRingPoint(ABase, dxPointDistance(ABase, APoint), A2);
end;

procedure dxRingRotatePoints(const ABase: TdxPointF; var APoints: array of TdxPointF; AAngle: Single);
var
  I: Integer;
begin
  for I := Low(APoints) to High(APoints) do
    APoints[I] := dxRingRotatePoint(ABase, APoints[I], AAngle);
end;

{ TcxGeometryObject }

procedure TcxGeometryObject.DoChange;
begin
  dxCallNotify(OnChange, Self);
end;

procedure TcxGeometryObject.LoadFromStream(AStream: TStream);
begin
end;

procedure TcxGeometryObject.SaveToStream(AStream: TStream);
begin
end;

{ TcxRect }

procedure TcxRect.DoAssign(Source: TPersistent);
begin
  Rect := TcxRect(Source).Rect;
end;

function TcxRect.IsEmpty: Boolean;
begin
  Result := cxRectIsEmpty(FRect);
end;

function TcxRect.IsEqual(const ARect: TRect): Boolean;
begin
  Result := cxRectIsEqual(ARect, FRect);
end;

function TcxRect.IsEqual(ARect: TcxRect): Boolean;
begin
  Result := IsEqual(ARect.Rect);
end;

procedure TcxRect.LoadFromStream(AStream: TStream);
var
  R: TRect;
begin
  AStream.ReadBuffer(R, SizeOf(TRect));
  Rect := R;
end;

procedure TcxRect.SaveToStream(AStream: TStream);
begin
  AStream.WriteBuffer(FRect, SizeOf(TRect));
end;

procedure TcxRect.ValidateRect(var R: TRect);
begin
end;

function TcxRect.GetHeight: Integer;
begin
  Result := FRect.Bottom - FRect.Top;
end;

function TcxRect.GetValue(AIndex: Integer): Integer;
begin
  case AIndex of
    0:
      Result := FRect.Left;
    1:
      Result := FRect.Top;
    2:
      Result := FRect.Right;
  else
    Result := FRect.Bottom;
  end;
end;

function TcxRect.GetVertex(AIndex: Integer): TPoint;
begin
  case AIndex of
    0:
      Result := FRect.TopLeft;
    1:
      Result := Point(FRect.Right, FRect.Top);
    2:
      Result := Point(FRect.Left, FRect.Bottom);
  else
    Result := FRect.BottomRight;
  end;
end;

function TcxRect.GetWidth: Integer;
begin
  Result := FRect.Right - FRect.Left;
end;

procedure TcxRect.SetHeight(AValue: Integer);
begin
  Bottom := Top + AValue;
end;

procedure TcxRect.SetRect(AValue: TRect);
begin
  ValidateRect(AValue);
  if not IsEqual(AValue) then
  begin
    FRect := AValue;
    DoChange;
  end;
end;

procedure TcxRect.SetValue(AIndex, AValue: Integer);
var
  ARect: TRect;
begin
  ARect := Rect;
  case AIndex of
    0:
      ARect.Left := AValue;
    1:
      ARect.Top := AValue;
    2:
      ARect.Right := AValue;
    3:
      ARect.Bottom := AValue;
  end;
  Rect := ARect;
end;

procedure TcxRect.SetVertex(AIndex: Integer; const AValue: TPoint);
var
  ARect: TRect;
begin
  ARect := Rect;
  case AIndex of
    0:
      ARect.TopLeft := AValue;
    1:
    begin
      ARect.Right := AValue.X;
      ARect.Top := AValue.Y;
    end;
    2:
    begin
      ARect.Left := AValue.X;
      ARect.Bottom := AValue.Y;
    end;
    3:
      ARect.BottomRight := AValue;
  end;
  Rect := ARect;
end;

procedure TcxRect.SetWidth(AValue: Integer);
begin
  Right := Left + AValue;
end;

{ TcxSize }

function TcxSize.IsEmpty: Boolean;
begin
  Result := cxSizeIsEmpty(FSize);
end;

function TcxSize.IsEqual(const ASize: TSize): Boolean;
begin
  Result := cxSizeIsEqual(ASize, FSize);
end;

function TcxSize.IsEqual(ASize: TcxSize): Boolean;
begin
  Result := IsEqual(ASize.Size);
end;

procedure TcxSize.DoAssign(Source: TPersistent);
begin
  Size := TcxSize(Source).Size;
end;

function TcxSize.IsSizeStored(Index: Integer): Boolean;
begin
  if Index = 0 then
    Result := FSize.cy <> 0
  else
    Result := FSize.cx <> 0;
end;

procedure TcxSize.LoadFromStream(AStream: TStream);
var
  ASize: TSize;
begin
  AStream.ReadBuffer(ASize, SizeOf(TSize));
  Size := ASize;
end;

procedure TcxSize.SaveToStream(AStream: TStream);
begin
  AStream.WriteBuffer(FSize, SizeOf(TSize));
end;

function TcxSize.GetSize: TSize;
begin
  Result := cxSize(Width, Height);
end;

function TcxSize.GetValue(Index: Integer): Integer;
begin
  if Index = 0 then
    Result := FSize.cy
  else
    Result := FSize.cx;
end;

procedure TcxSize.SetValue(Index, Value: Integer);
var
  ASize: TSize;
begin
  ASize := Size;
  if Index = 0 then
    ASize.cy := Value
  else
    ASize.cx := Value;
  Size := ASize;
end;

procedure TcxSize.SetSize(const Value: TSize);
var
  ASize: TSize;
begin
  ASize.cx := Max(0, Value.cx);
  ASize.cy := Max(0, Value.cy);
  if not IsEqual(ASize) then
  begin
    FSize := ASize;
    DoChange;
  end;
end;

{ TcxMargin }

constructor TcxMargin.Create(AOwner: TPersistent; ADefaultValue: Integer);
begin
  inherited Create(AOwner);
  FDefaultValue := ADefaultValue;
  All := ADefaultValue;
end;

procedure TcxMargin.DoAssign(Source: TPersistent);
begin
  Margin := TcxMargin(Source).Margin;
end;

procedure TcxMargin.LoadFromStream(AStream: TStream);
var
  R: TRect;
begin
  AStream.ReadBuffer(R, SizeOf(TRect));
  Margin := R;
end;

procedure TcxMargin.SaveToStream(AStream: TStream);
begin
  AStream.WriteBuffer(FMargin, SizeOf(TRect));
end;

function TcxMargin.GetValue(AIndex: Integer): Integer;
begin
  case AIndex of
    1: Result := FMargin.Left;
    2: Result := FMargin.Top;
    3: Result := FMargin.Right;
    4: Result := FMargin.Bottom;
  else // 0
    if (FMargin.Left = FMargin.Top) and (FMargin.Left = FMargin.Right) and (FMargin.Left = FMargin.Bottom) then
      Result := FMargin.Left
    else
      Result := -1;
  end;
end;

procedure TcxMargin.SetMargin(const Value: TRect);
begin
  if not cxRectIsEqual(Value, FMargin) then
  begin
    FMargin := Value;
    DoChange;
  end;
end;

procedure TcxMargin.SetValue(AIndex, AValue: Integer);
begin
  if GetValue(AIndex) <> AValue then
  begin
    case AIndex of
      1: FMargin.Left := AValue;
      2: FMargin.Top := AValue;
      3: FMargin.Right := AValue;
      4: FMargin.Bottom := AValue;
    else // 0
      FMargin := cxRect(AValue, AValue, AValue, AValue);
    end;

    DoChange;
  end;
end;

function TcxMargin.IsEqual(AMargin: TcxMargin): Boolean;
begin
  Result := cxRectIsEqual(Margin, AMargin.Margin);
end;

function TcxMargin.IsMarginStored(AIndex: Integer): Boolean;
begin
  case AIndex of
    1..4: Result := All = -1;
  else // 0
    Result := All <> FDefaultValue;
  end;
end;

initialization
  RegisterClasses([TcxRect]);

finalization
  UnregisterClasses([TcxRect]);

end.
