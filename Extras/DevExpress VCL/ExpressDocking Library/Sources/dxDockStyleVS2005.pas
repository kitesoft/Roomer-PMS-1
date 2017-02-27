{*******************************************************************}
{                                                                   }
{       Developer Express Visual Component Library                  }
{       ExpressDocking                                              }
{                                                                   }
{       Copyright (c) 2002-2014 Developer Express Inc.              }
{       ALL RIGHTS RESERVED                                         }
{                                                                   }
{   The entire contents of this file is protected by U.S. and       }
{   International Copyright Laws. Unauthorized reproduction,        }
{   reverse-engineering, and distribution of all or any portion of  }
{   the code contained in this file is strictly prohibited and may  }
{   result in severe civil and criminal penalties and will be       }
{   prosecuted to the maximum extent possible under the law.        }
{                                                                   }
{   RESTRICTIONS                                                    }
{                                                                   }
{   THIS SOURCE CODE AND ALL RESULTING INTERMEDIATE FILES           }
{   (DCU, OBJ, DLL, ETC.) ARE CONFIDENTIAL AND PROPRIETARY TRADE    }
{   SECRETS OF DEVELOPER EXPRESS INC. THE REGISTERED DEVELOPER IS   }
{   LICENSED TO DISTRIBUTE THE EXPRESSDOCKING AND ALL ACCOMPANYING  }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.             }
{                                                                   }
{   THE SOURCE CODE CONTAINED WITHIN THIS FILE AND ALL RELATED      }
{   FILES OR ANY PORTION OF ITS CONTENTS SHALL AT NO TIME BE        }
{   COPIED, TRANSFERRED, SOLD, DISTRIBUTED, OR OTHERWISE MADE       }
{   AVAILABLE TO OTHER INDIVIDUALS WITHOUT EXPRESS WRITTEN CONSENT  }
{   AND PERMISSION FROM DEVELOPER EXPRESS INC.                      }
{                                                                   }
{   CONSULT THE END USER LICENSE AGREEMENT FOR INFORMATION ON       }
{   ADDITIONAL RESTRICTIONS.                                        }
{                                                                   }
{*******************************************************************}

unit dxDockStyleVS2005;

{$I cxVer.inc}

interface

uses
  Types, Windows, Classes, SysUtils, Graphics, Controls,
  dxCore, cxClasses, cxControls, cxGraphics, dxDockControl;

type
  TdxDockingTargetSelectorZoneKind = (tszLeft, tszRight, tszTop, tszBottom, tszClient,
    tszDockSiteLeft, tszDockSiteRight, tszDockSiteTop, tszDockSiteBottom);

  TdxDockingCustomTargetSelector = class;

  { TdxDockingTargetSelectorZoneViewInfo }

  TdxDockingTargetSelectorZoneViewInfo = class(TObject)
  private
    FBounds: TRect;
    FKind: TdxDockingTargetSelectorZoneKind;
    FOwner: TdxDockingCustomTargetSelector;
    FZone: TdxZone;
    function GetActive: Boolean;
    function GetEnabled: Boolean;
  public
    constructor Create(AOwner: TdxDockingCustomTargetSelector;
      AKind: TdxDockingTargetSelectorZoneKind; AZone: TdxZone); virtual;
    procedure Draw(ACanvas: TcxCanvas); virtual;
    //
    property Active: Boolean read GetActive;
    property Bounds: TRect read FBounds write FBounds;
    property Enabled: Boolean read GetEnabled;
    property Kind: TdxDockingTargetSelectorZoneKind read FKind;
    property Owner: TdxDockingCustomTargetSelector read FOwner;
    property Zone: TdxZone read FZone;
  end;

  { TdxDockingTargetSelectorCustomPainter }

  TdxDockingTargetSelectorCustomPainter = class(TObject)
  public
    // Client Target Selector
    function CalculateClientTargetSelectorRegion: TcxRegionHandle; virtual; abstract;
    procedure DrawClientTargetSelectorBackground(ACanvas: TcxCanvas; const R: TRect); virtual; abstract;
    function GetClientTargetSelectorContentOffsets: TRect; virtual; abstract;
    // Zones
    procedure DrawZone(ACanvas: TcxCanvas; const R: TRect; AActive: Boolean;
      AEnabled: Boolean; AKind: TdxDockingTargetSelectorZoneKind); virtual; abstract;
    function GetZoneSize(AKind: TdxDockingTargetSelectorZoneKind): TSize; virtual; abstract;
  end;

  { TdxDockingTargetSelectorPainter }

  TdxDockingTargetSelectorPainter = class(TdxDockingTargetSelectorCustomPainter)
  private
    FClientTargetSelectorBackground: TcxBitmap;
    FZonesBitmaps: array[TdxDockingTargetSelectorZoneKind] of TcxBitmap;
  protected
    procedure DoDrawZone(ACanvas: TcxCanvas; const R: TRect;
      AKind: TdxDockingTargetSelectorZoneKind; AState: Integer);
    function LoadBitmap(const AResourceName: string): TcxBitmap;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    // Client Target Selector
    function CalculateClientTargetSelectorRegion: TcxRegionHandle; override;
    procedure DrawClientTargetSelectorBackground(ACanvas: TcxCanvas; const R: TRect); override;
    function GetClientTargetSelectorContentOffsets: TRect; override;
    // Zones
    procedure DrawZone(ACanvas: TcxCanvas; const R: TRect; AActive: Boolean;
      AEnabled: Boolean; AKind: TdxDockingTargetSelectorZoneKind); override;
    function GetZoneSize(AKind: TdxDockingTargetSelectorZoneKind): TSize; override;
  end;

  { TdxDockingCustomTargetSelector }

  TdxDockingCustomTargetSelector = class(TcxCustomDragImage)
  private
    FActiveTargetZone: TdxDockingTargetSelectorZoneViewInfo;
    FPainter: TdxDockingTargetSelectorCustomPainter;
    FDockControl: TdxCustomDockControl;
    FTargetZones: TcxObjectList;
    function GetTargetZone: TdxZone;
    function GetTargetZoneSize(AKind: TdxDockingTargetSelectorZoneKind): TSize;
    function GetTargetZoneViewInfo(Index: Integer): TdxDockingTargetSelectorZoneViewInfo;
    function GetTargetZoneViewInfoCount: Integer;
    procedure SetActiveTargetZone(AValue: TdxDockingTargetSelectorZoneViewInfo);
    procedure SetDockControl(AValue: TdxCustomDockControl);
  protected
    function AddZoneViewInfo(AKind: TdxDockingTargetSelectorZoneKind): TdxDockingTargetSelectorZoneViewInfo;
    procedure Calculate; virtual;
    procedure CalculateTargetZones; virtual; abstract;
    procedure Paint; override;
    //
    property TargetZones: TcxObjectList read FTargetZones;
  public
    constructor Create(APainter: TdxDockingTargetSelectorCustomPainter); reintroduce; virtual;
    destructor Destroy; override;
    procedure CalculateHitTest(const AScreenPoint: TPoint); virtual;
    function GetTargetZoneAtPoint(const APoint: TPoint): TdxDockingTargetSelectorZoneViewInfo;
    //
    property ActiveTargetZone: TdxDockingTargetSelectorZoneViewInfo read FActiveTargetZone write SetActiveTargetZone;
    property DockControl: TdxCustomDockControl read FDockControl write SetDockControl;
    property Painter: TdxDockingTargetSelectorCustomPainter read FPainter;
    property TargetZone: TdxZone read GetTargetZone;
    property TargetZoneSize[AKind: TdxDockingTargetSelectorZoneKind]: TSize read GetTargetZoneSize;
    property TargetZoneViewInfo[Index: Integer]: TdxDockingTargetSelectorZoneViewInfo read GetTargetZoneViewInfo;
    property TargetZoneViewInfoCount: Integer read GetTargetZoneViewInfoCount;
  end;

  TdxDockingCustomTargetSelectorClass = class of TdxDockingCustomTargetSelector;

  { TdxDockingControllerVS2005Helper }

  TdxDockingControllerVS2005Helper = class(TdxDockingControllerHelper)
  private
    FPainter: TdxDockingTargetSelectorCustomPainter;
    FTargetSelectors: array[TdxDockingType] of TdxDockingCustomTargetSelector;
    function GetTargetSelector(AType: TdxDockingType): TdxDockingCustomTargetSelector;
  protected
    function CheckTargetDockControl(const APoint: TPoint;
      AControl, ATargetDockControl: TdxCustomDockControl): Boolean; virtual;
    function CreateTargetSelector(AType: TdxDockingType): TdxDockingCustomTargetSelector; virtual;
    function CreateTargetSelectorPainter: TdxDockingTargetSelectorCustomPainter; virtual;
    function GetDockingTargetControl(AControl: TdxCustomDockControl; const APoint: TPoint): TdxCustomDockControl; virtual;
    function GetDockSite(AControl: TWinControl): TdxCustomDockSite; virtual;
    function GetTargetZone(const APoint: TPoint): TdxZone; virtual;
    procedure SetDockingParams(AControl: TdxCustomDockControl; AZone: TdxZone; const APoint: TPoint);
    procedure UpdateTargetSelectors(ATargetDockControl, ATargetDockSite: TdxCustomDockControl); virtual;
  public
    procedure DockingFinish(AControl: TdxCustomDockControl; const APoint: TPoint); override;
    procedure DockingMove(AControl: TdxCustomDockControl; const APoint: TPoint); override;
    procedure DockingStart(AControl: TdxCustomDockControl; const APoint: TPoint); override;
    //
    property Painter: TdxDockingTargetSelectorCustomPainter read FPainter;
    property TargetSelector[AType: TdxDockingType]: TdxDockingCustomTargetSelector read GetTargetSelector;
  end;

  { TdxDockingClientTargetSelector }

  TdxDockingClientTargetSelector = class(TdxDockingCustomTargetSelector)
  private
    function CalculateClientRect: TRect;
    function CalculateHorizontalRowMaxSize: Integer;
    function CalculateVerticalRowMaxSize: Integer;
  protected
    procedure CalculateClientZone; virtual;
    procedure CalculateHorizontalZones; virtual;
    procedure CalculateTargetZones; override;
    procedure CalculateVerticalZones; virtual;
    procedure Paint; override;
  end;

  { TdxDockingParentTargetSelector }

  TdxDockingParentTargetSelector = class(TdxDockingCustomTargetSelector)
  protected
    procedure CalculateTargetZones; override;
    function GetZoneKind: TdxDockingTargetSelectorZoneKind; virtual; abstract;
    procedure PlaceTargetSelector(const ATargetWindowRect: TRect); virtual; abstract;
  public
    property ZoneKind: TdxDockingTargetSelectorZoneKind read GetZoneKind;
  end;

  { TdxDockingLeftTargetSelector }

  TdxDockingLeftTargetSelector = class(TdxDockingParentTargetSelector)
  protected
    function GetZoneKind: TdxDockingTargetSelectorZoneKind; override;
    procedure PlaceTargetSelector(const ATargetWindowRect: TRect); override;
  end;

  { TdxDockingRightTargetSelector }

  TdxDockingRightTargetSelector = class(TdxDockingParentTargetSelector)
  protected
    function GetZoneKind: TdxDockingTargetSelectorZoneKind; override;
    procedure PlaceTargetSelector(const ATargetWindowRect: TRect); override;
  end;

  { TdxDockingTopTargetSelector }

  TdxDockingTopTargetSelector = class(TdxDockingParentTargetSelector)
  protected
    function GetZoneKind: TdxDockingTargetSelectorZoneKind; override;
    procedure PlaceTargetSelector(const ATargetWindowRect: TRect); override;
  end;

  { TdxDockingBottomTargetSelector }

  TdxDockingBottomTargetSelector = class(TdxDockingParentTargetSelector)
  protected
    function GetZoneKind: TdxDockingTargetSelectorZoneKind; override;
    procedure PlaceTargetSelector(const ATargetWindowRect: TRect); override;
  end;

implementation

uses
  cxGeometry, Math, dxDockZones;

{$R dxDockStyleVS2005.res}

const
  sdxDockingVS2005DockSiteBottom = 'DXDOCKINGVS2005DOCKSITEBOTTOM';
  sdxDockingVS2005DockSiteLeft = 'DXDOCKINGVS2005DOCKSITELEFT';
  sdxDockingVS2005DockSiteRight = 'DXDOCKINGVS2005DOCKSITERIGHT';
  sdxDockingVS2005DockSiteTop = 'DXDOCKINGVS2005DOCKSITETOP';
  sdxDockingVS2005Target = 'DXDOCKINGVS2005TARGET';
  sdxDockingVS2005TargetBottom = 'DXDOCKINGVS2005TARGETBOTTOM';
  sdxDockingVS2005TargetClient = 'DXDOCKINGVS2005TARGETCLIENT';
  sdxDockingVS2005TargetLeft = 'DXDOCKINGVS2005TARGETLEFT';
  sdxDockingVS2005TargetRight = 'DXDOCKINGVS2005TARGETRIGHT';
  sdxDockingVS2005TargetTop = 'DXDOCKINGVS2005TARGETTOP';

  sdxDockingSelectorZoneStatesCount = 3;

type
  TdxCustomDockControlAccess = class(TdxCustomDockControl);

{ TdxDockingTargetSelectorZoneViewInfo }

constructor TdxDockingTargetSelectorZoneViewInfo.Create(
  AOwner: TdxDockingCustomTargetSelector;
  AKind: TdxDockingTargetSelectorZoneKind; AZone: TdxZone);
begin
  inherited Create;
  FOwner := AOwner;
  FKind := AKind;
  FZone := AZone;
end;

procedure TdxDockingTargetSelectorZoneViewInfo.Draw(ACanvas: TcxCanvas);
begin
  Owner.Painter.DrawZone(ACanvas, Bounds, Active, Enabled, Kind);
end;

function TdxDockingTargetSelectorZoneViewInfo.GetActive: Boolean;
begin
  Result := Self = Owner.ActiveTargetZone;
end;

function TdxDockingTargetSelectorZoneViewInfo.GetEnabled: Boolean;
begin
  Result := Zone <> nil;
end;

{ TdxDockingTargetSelectorPainter }

constructor TdxDockingTargetSelectorPainter.Create;
const
  ZonesBitmapsNames: array[TdxDockingTargetSelectorZoneKind] of string = (
    sdxDockingVS2005TargetLeft, sdxDockingVS2005TargetRight, sdxDockingVS2005TargetTop,
    sdxDockingVS2005TargetBottom, sdxDockingVS2005TargetClient, sdxDockingVS2005DockSiteLeft,
    sdxDockingVS2005DockSiteRight, sdxDockingVS2005DockSiteTop, sdxDockingVS2005DockSiteBottom
  );
var
  AZoneKind: TdxDockingTargetSelectorZoneKind;
begin
  inherited Create;
  FClientTargetSelectorBackground := LoadBitmap(sdxDockingVS2005Target);
  for AZoneKind := Low(AZoneKind) to High(AZoneKind) do
    FZonesBitmaps[AZoneKind] := LoadBitmap(ZonesBitmapsNames[AZoneKind]);
end;

destructor TdxDockingTargetSelectorPainter.Destroy;
var
  AZoneKind: TdxDockingTargetSelectorZoneKind;
begin
  FreeAndNil(FClientTargetSelectorBackground);
  for AZoneKind := Low(AZoneKind) to High(AZoneKind) do
    FreeAndNil(FZonesBitmaps[AZoneKind]);
  inherited Destroy;
end;

function TdxDockingTargetSelectorPainter.CalculateClientTargetSelectorRegion: TcxRegionHandle;
begin
  Result := cxCreateRegionFromBitmap(FClientTargetSelectorBackground, clFuchsia);
end;

procedure TdxDockingTargetSelectorPainter.DoDrawZone(ACanvas: TcxCanvas;
  const R: TRect; AKind: TdxDockingTargetSelectorZoneKind; AState: Integer);
var
  ASourceRect: TRect;
begin
  ASourceRect := cxRect(GetZoneSize(AKind));
  ASourceRect := cxRectOffset(ASourceRect, 0, AState * cxRectHeight(ASourceRect));
  cxStretchBlt(ACanvas.Handle, FZonesBitmaps[AKind].Canvas.Handle, R, ASourceRect, SRCCOPY);
end;

procedure TdxDockingTargetSelectorPainter.DrawClientTargetSelectorBackground(ACanvas: TcxCanvas; const R: TRect);
begin
  cxBitBlt(ACanvas.Handle, FClientTargetSelectorBackground.Canvas.Handle, R, cxNullPoint, SRCCOPY);
end;

procedure TdxDockingTargetSelectorPainter.DrawZone(ACanvas: TcxCanvas;
  const R: TRect; AActive, AEnabled: Boolean; AKind: TdxDockingTargetSelectorZoneKind);
const
  StatesMap: array[Boolean, Boolean] of Integer = ((2, 2), (0, 1));
begin
  DoDrawZone(ACanvas, R, AKind, StatesMap[AEnabled, AActive]);
end;

function TdxDockingTargetSelectorPainter.GetClientTargetSelectorContentOffsets: TRect;
begin
  Result := cxRect(1, 2, 1, 2);
end;

function TdxDockingTargetSelectorPainter.GetZoneSize(AKind: TdxDockingTargetSelectorZoneKind): TSize;
begin
  Result := cxSize(FZonesBitmaps[AKind].Width, FZonesBitmaps[AKind].Height div sdxDockingSelectorZoneStatesCount);
end;

function TdxDockingTargetSelectorPainter.LoadBitmap(const AResourceName: string): TcxBitmap;
begin
  Result := TcxBitmap.Create;
  Result.LoadFromResourceName(HInstance, AResourceName);
end;

{ TdxDockingCustomTargetSelector }

constructor TdxDockingCustomTargetSelector.Create(APainter: TdxDockingTargetSelectorCustomPainter);
begin
  inherited Create;
  FPainter := APainter;
  FTargetZones := TcxObjectList.Create;
end;

destructor TdxDockingCustomTargetSelector.Destroy;
begin
  FreeAndNil(FTargetZones);
  inherited Destroy;
end;

function TdxDockingCustomTargetSelector.AddZoneViewInfo(
  AKind: TdxDockingTargetSelectorZoneKind): TdxDockingTargetSelectorZoneViewInfo;

  function FindTargetZone(AOwnerControl: TdxCustomDockControl): TdxZone;
  const
    DockingTypeMap: array[TdxDockingTargetSelectorZoneKind] of TdxDockingType =
      (dtLeft, dtRight, dtTop, dtBottom, dtClient, dtLeft, dtRight, dtTop, dtBottom);
  begin
    Result := TdxCustomDockControlAccess(DockControl).DockZones.FindZone(
      AOwnerControl, DockingTypeMap[AKind]);
  end;

var
  AZone: TdxZone;
begin
  if DockControl.TabContainer <> nil then
    AZone := FindTargetZone(DockControl.TabContainer)
  else
    AZone := nil;

  if AZone = nil then
    AZone := FindTargetZone(DockControl);

  if (AZone <> nil) and not AZone.CanDock(dxDockingController.DockingDockControl) then
    AZone := nil;
  Result := TdxDockingTargetSelectorZoneViewInfo.Create(Self, AKind, AZone);
  TargetZones.Add(Result);
end;

procedure TdxDockingCustomTargetSelector.Calculate;
begin
  TargetZones.Clear;
  CalculateTargetZones;
  Invalidate;
end;

procedure TdxDockingCustomTargetSelector.CalculateHitTest(const AScreenPoint: TPoint);
begin
  if Visible then
    ActiveTargetZone := GetTargetZoneAtPoint(ScreenToClient(AScreenPoint))
  else
    ActiveTargetZone := nil;
end;

procedure TdxDockingCustomTargetSelector.Paint;
var
  I: Integer;
begin
  for I := 0 to TargetZoneViewInfoCount - 1 do
    TargetZoneViewInfo[I].Draw(Canvas);
end;

function TdxDockingCustomTargetSelector.GetTargetZone: TdxZone;
begin
  if ActiveTargetZone <> nil then
    Result := ActiveTargetZone.Zone
  else
    Result := nil;
end;

function TdxDockingCustomTargetSelector.GetTargetZoneAtPoint(
  const APoint: TPoint): TdxDockingTargetSelectorZoneViewInfo;
var
  AViewInfo: TdxDockingTargetSelectorZoneViewInfo;
  I: Integer;
begin
  Result := nil;
  for I := TargetZoneViewInfoCount - 1 downto 0 do
  begin
    AViewInfo := TargetZoneViewInfo[I];
    if AViewInfo.Enabled and PtInRect(AViewInfo.Bounds, APoint) then
    begin
      Result := AViewInfo;
      Break;
    end;
  end;
end;

function TdxDockingCustomTargetSelector.GetTargetZoneSize(AKind: TdxDockingTargetSelectorZoneKind): TSize;
begin
  if Painter <> nil then
    Result := Painter.GetZoneSize(AKind)
  else
    Result := cxNullSize;
end;

function TdxDockingCustomTargetSelector.GetTargetZoneViewInfo(Index: Integer): TdxDockingTargetSelectorZoneViewInfo;
begin
  Result := TdxDockingTargetSelectorZoneViewInfo(TargetZones[Index]);
end;

function TdxDockingCustomTargetSelector.GetTargetZoneViewInfoCount: Integer;
begin
  Result := TargetZones.Count;
end;

procedure TdxDockingCustomTargetSelector.SetActiveTargetZone(AValue: TdxDockingTargetSelectorZoneViewInfo);
begin
  if AValue <> FActiveTargetZone then
  begin
    FActiveTargetZone := AValue;
    Invalidate;
  end;
end;

procedure TdxDockingCustomTargetSelector.SetDockControl(AValue: TdxCustomDockControl);
begin
  if AValue <> DockControl then
  begin
    FActiveTargetZone := nil;
    FDockControl := AValue;
    if DockControl = nil then
      Hide
    else
    begin
      Calculate;
      Show;
    end;
  end;
end;

{ TdxDockingClientTargetSelector }

procedure TdxDockingClientTargetSelector.CalculateTargetZones;
begin
  CalculateClientZone;
  CalculateHorizontalZones;
  CalculateVerticalZones;
  Init(CalculateClientRect, cxNullPoint);
  SetWindowRgn(Handle, Painter.CalculateClientTargetSelectorRegion, False);
  MoveTo(cxRectCenter(cxGetWindowRect(DockControl), Width, Height).TopLeft);
end;

function TdxDockingClientTargetSelector.CalculateClientRect: TRect;
var
  I: Integer;
begin
  Result := cxNullRect;
  for I := 0 to TargetZoneViewInfoCount - 1 do
    Result := cxRectUnion(Result, TargetZoneViewInfo[I].Bounds);
  Result := cxRectInflate(Result, Painter.GetClientTargetSelectorContentOffsets);
end;

function TdxDockingClientTargetSelector.CalculateHorizontalRowMaxSize: Integer;
begin
  Result := Max(TargetZoneSize[tszLeft].cy, TargetZoneSize[tszClient].cy);
  Result := Max(TargetZoneSize[tszRight].cy, Result);
end;

function TdxDockingClientTargetSelector.CalculateVerticalRowMaxSize: Integer;
begin
  Result := Max(TargetZoneSize[tszTop].cx, TargetZoneSize[tszClient].cx);
  Result := Max(TargetZoneSize[tszBottom].cx, Result);
end;

procedure TdxDockingClientTargetSelector.CalculateClientZone;
var
  ARect: TRect;
begin
  ARect := cxRectBounds(TargetZoneSize[tszLeft].cx, TargetZoneSize[tszTop].cy,
    CalculateVerticalRowMaxSize, CalculateHorizontalRowMaxSize);
  ARect := cxRectOffset(ARect, Painter.GetClientTargetSelectorContentOffsets.TopLeft);
  AddZoneViewInfo(tszClient).Bounds := cxRectCenter(ARect, TargetZoneSize[tszClient]);
end;

procedure TdxDockingClientTargetSelector.CalculateHorizontalZones;

  function PlaceZone(const R: TRect; const AZoneSize: TSize): TRect;
  begin
    Result := cxRectCenterVertically(cxRectSetWidth(R, AZoneSize.cx), AZoneSize.cy);
  end;

var
  ARect: TRect;
  AZoneViewInfo: TdxDockingTargetSelectorZoneViewInfo;
begin
  ARect := cxRectBounds(0, TargetZoneSize[tszTop].cy, 0, CalculateHorizontalRowMaxSize);
  ARect := cxRectOffset(ARect, Painter.GetClientTargetSelectorContentOffsets.TopLeft);

  AZoneViewInfo := AddZoneViewInfo(tszLeft);
  AZoneViewInfo.Bounds := PlaceZone(ARect, TargetZoneSize[tszLeft]);
  ARect.Left := AZoneViewInfo.Bounds.Right + CalculateVerticalRowMaxSize;

  AZoneViewInfo := AddZoneViewInfo(tszRight);
  AZoneViewInfo.Bounds := PlaceZone(ARect, TargetZoneSize[tszRight]);
end;

procedure TdxDockingClientTargetSelector.CalculateVerticalZones;

  function PlaceZone(const R: TRect; const AZoneSize: TSize): TRect;
  begin
    Result := cxRectCenterHorizontally(cxRectSetHeight(R, AZoneSize.cy), AZoneSize.cx);
  end;

var
  ARect: TRect;
  AZoneViewInfo: TdxDockingTargetSelectorZoneViewInfo;
begin
  ARect := cxRectBounds(TargetZoneSize[tszLeft].cx, 0, CalculateVerticalRowMaxSize, 0);
  ARect := cxRectOffset(ARect, Painter.GetClientTargetSelectorContentOffsets.TopLeft);

  AZoneViewInfo := AddZoneViewInfo(tszTop);
  AZoneViewInfo.Bounds := PlaceZone(ARect, TargetZoneSize[tszTop]);
  ARect.Top := AZoneViewInfo.Bounds.Bottom + CalculateHorizontalRowMaxSize;

  AZoneViewInfo := AddZoneViewInfo(tszBottom);
  AZoneViewInfo.Bounds := PlaceZone(ARect, TargetZoneSize[tszBottom]);
end;

procedure TdxDockingClientTargetSelector.Paint;
begin
  Painter.DrawClientTargetSelectorBackground(Canvas, ClientRect);
  inherited Paint;
end;

{ TdxDockingParentTargetSelector }

procedure TdxDockingParentTargetSelector.CalculateTargetZones;
var
  AZoneViewInfo: TdxDockingTargetSelectorZoneViewInfo;
begin
  AZoneViewInfo := AddZoneViewInfo(ZoneKind);
  AZoneViewInfo.Bounds := cxRect(TargetZoneSize[ZoneKind]);
  Init(AZoneViewInfo.Bounds, cxNullPoint);
  PlaceTargetSelector(cxGetWindowRect(DockControl));
end;

{ TdxDockingLeftTargetSelector }

function TdxDockingLeftTargetSelector.GetZoneKind: TdxDockingTargetSelectorZoneKind;
begin
  Result := tszDockSiteLeft;
end;

procedure TdxDockingLeftTargetSelector.PlaceTargetSelector(const ATargetWindowRect: TRect);
begin
  MoveTo(Point(ATargetWindowRect.Left, cxRectCenterVertically(ATargetWindowRect, Height).Top));
end;

{ TdxDockingRightTargetSelector }

function TdxDockingRightTargetSelector.GetZoneKind: TdxDockingTargetSelectorZoneKind;
begin
  Result := tszDockSiteRight;
end;

procedure TdxDockingRightTargetSelector.PlaceTargetSelector(const ATargetWindowRect: TRect);
begin
  MoveTo(Point(ATargetWindowRect.Right - Width, cxRectCenterVertically(ATargetWindowRect, Height).Top));
end;

{ TdxDockingTopTargetSelector }

function TdxDockingTopTargetSelector.GetZoneKind: TdxDockingTargetSelectorZoneKind;
begin
  Result := tszDockSiteTop;
end;

procedure TdxDockingTopTargetSelector.PlaceTargetSelector(const ATargetWindowRect: TRect);
begin
  MoveTo(Point(cxRectCenterHorizontally(ATargetWindowRect, Width).Left, ATargetWindowRect.Top));
end;

{ TdxDockingBottomTargetSelector }

function TdxDockingBottomTargetSelector.GetZoneKind: TdxDockingTargetSelectorZoneKind;
begin
  Result := tszDockSiteBottom;
end;

procedure TdxDockingBottomTargetSelector.PlaceTargetSelector(const ATargetWindowRect: TRect);
begin
  MoveTo(Point(cxRectCenterHorizontally(ATargetWindowRect, Width).Left, ATargetWindowRect.Bottom - Height));
end;

{ TdxDockingControllerVS2005Helper }

function TdxDockingControllerVS2005Helper.CreateTargetSelectorPainter: TdxDockingTargetSelectorCustomPainter;
begin
  Result := TdxDockingTargetSelectorPainter.Create;
end;

function TdxDockingControllerVS2005Helper.CreateTargetSelector(
  AType: TdxDockingType): TdxDockingCustomTargetSelector;
const
  TargetSelectorsClasses: array[TdxDockingType] of TdxDockingCustomTargetSelectorClass = (
    TdxDockingClientTargetSelector, TdxDockingLeftTargetSelector,
    TdxDockingTopTargetSelector, TdxDockingRightTargetSelector,
    TdxDockingBottomTargetSelector
  );
begin
  Result := TargetSelectorsClasses[AType].Create(Painter);
end;

function TdxDockingControllerVS2005Helper.CheckTargetDockControl(
  const APoint: TPoint; AControl, ATargetDockControl: TdxCustomDockControl): Boolean;

  function IsTargetDockControlFullyVisible: Boolean;
  var
    R: TRect;
  begin
    if ATargetDockControl <> nil then
    begin
      R := ATargetDockControl.ClientRect;
      if cxRectIsEmpty(R) then
        Result := (ATargetDockControl is TdxDockSite) and TdxDockSite(ATargetDockControl).AutoSize
      else
        Result := ATargetDockControl = GetDockingTargetControl(AControl, ATargetDockControl.ClientToScreen(cxRectCenter(R)));
    end
    else
      Result := False;
  end;

begin
  if ATargetDockControl <> AControl then
    Result := IsTargetDockControlFullyVisible
  else
    Result := AControl.TabContainer <> nil;
end;

procedure TdxDockingControllerVS2005Helper.DockingStart(
  AControl: TdxCustomDockControl; const APoint: TPoint);
var
  ADockingType: TdxDockingType;
begin
  inherited DockingStart(AControl, APoint);
  FPainter := CreateTargetSelectorPainter;
  for ADockingType := Low(TdxDockingType) to High(TdxDockingType) do
    FTargetSelectors[ADockingType] := CreateTargetSelector(ADockingType);
end;

procedure TdxDockingControllerVS2005Helper.DockingMove(
  AControl: TdxCustomDockControl; const APoint: TPoint);

  function GetTabContainerZone(ATargetDockControl: TdxCustomDockControl; out AZone: TdxZone): Boolean;
  begin
    if ATargetDockControl <> nil then
      AZone := ATargetDockControl.GetDockZoneAtPos(AControl, APoint)
    else
      AZone := nil;

    Result := AZone is TdxTabContainerTabZone;
  end;

var
  ATargetDockControl: TdxCustomDockControl;
  ATargetDockSite: TdxCustomDockControl;
  ATargetZone: TdxZone;
begin
  ATargetDockControl := GetDockingTargetControl(AControl, APoint);
  ATargetDockSite := GetDockSite(ATargetDockControl);
  if GetTabContainerZone(ATargetDockControl, ATargetZone) then
  begin
    SetDockingParams(AControl, ATargetZone, APoint);
    UpdateTargetSelectors(nil, nil);
  end
  else
  begin
    if not CheckTargetDockControl(APoint, AControl, ATargetDockControl) then
      ATargetDockControl := nil;
    UpdateTargetSelectors(ATargetDockControl, ATargetDockSite);
    SetDockingParams(AControl, GetTargetZone(APoint), APoint);
  end;
end;

procedure TdxDockingControllerVS2005Helper.DockingFinish(
  AControl: TdxCustomDockControl; const APoint: TPoint);
var
  AType: TdxDockingType;
begin
  inherited DockingFinish(AControl, APoint);
  for AType := Low(TdxDockingType) to High(TdxDockingType) do
    FreeAndNil(FTargetSelectors[AType]);
  FreeAndNil(FPainter);
end;

procedure TdxDockingControllerVS2005Helper.UpdateTargetSelectors(
  ATargetDockControl, ATargetDockSite: TdxCustomDockControl);
var
  ADockingType: TdxDockingType;
begin
  for ADockingType := Low(TdxDockingType) to High(TdxDockingType) do
  begin
    if ADockingType <> dtClient then
      TargetSelector[ADockingType].DockControl := ATargetDockSite
    else
      TargetSelector[ADockingType].DockControl := ATargetDockControl;
  end;
end;

function TdxDockingControllerVS2005Helper.GetDockingTargetControl(
  AControl: TdxCustomDockControl; const APoint: TPoint): TdxCustomDockControl;
var
  AStyles: Cardinal;
begin
  if (AControl.FloatDockSite <> nil) and AControl.FloatFormVisible then
  begin
    AStyles := dxSetWindowStyle(AControl.FloatForm.Handle, WS_VISIBLE, soSubtract);
    Result := TdxCustomDockControlAccess(AControl).GetDockingTargetControlAtPos(APoint);
    dxSetWindowStyle(AControl.FloatForm.Handle, AStyles, soSet);
  end
  else
    Result := TdxCustomDockControlAccess(AControl).GetDockingTargetControlAtPos(APoint);
end;

function TdxDockingControllerVS2005Helper.GetDockSite(AControl: TWinControl): TdxCustomDockSite;
begin
  Result := nil;
  while AControl <> nil do
  begin
    if AControl is TdxDockSite then
    begin
      Result := TdxDockSite(AControl);
      Break;
    end;
    AControl := AControl.Parent;
  end;
end;

function TdxDockingControllerVS2005Helper.GetTargetSelector(
  AType: TdxDockingType): TdxDockingCustomTargetSelector;
begin
  Result := FTargetSelectors[AType];
end;

function TdxDockingControllerVS2005Helper.GetTargetZone(const APoint: TPoint): TdxZone;
var
  ADockingType: TdxDockingType;
begin
  for ADockingType := Low(ADockingType) to High(ADockingType) do
    TargetSelector[ADockingType].CalculateHitTest(APoint);
  for ADockingType := Low(ADockingType) to High(ADockingType) do
  begin
    Result := TargetSelector[ADockingType].TargetZone;
    if Result <> nil then Break;
  end;
end;

procedure TdxDockingControllerVS2005Helper.SetDockingParams(
  AControl: TdxCustomDockControl; AZone: TdxZone; const APoint: TPoint);
begin
  if AZone <> nil then
  begin
    if not CanDocking(AControl, AZone.Owner, AZone, APoint) then
      AZone := nil;
  end;
  TdxCustomDockControlAccess(AControl).SetDockingParams(AZone, APoint);
end;

end.
