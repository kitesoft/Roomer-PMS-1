{********************************************************************}
{                                                                    }
{           Developer Express Visual Component Library               }
{           Express Cross Platform Library graphics classes          }
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

unit dxAnimation;

{$I cxVer.inc}

interface

uses
  Windows, Types, SysUtils, Classes, Graphics, Math, dxCore, cxClasses,
  dxGDIPlusAPI, dxGdiPlusClasses, cxGeometry, cxGraphics, Forms;

type
  TdxAnimationTransition = class;
  TdxAnimationController = class;
  TdxDrawAnimationMode = (amScrollLeft, amScrollUp, amScrollRight,
    amScrollDown, amFade, amSegmentedFade, amRandomSegmentedFade);

  TdxAnimationTransitionEffect = (ateLinear, ateAccelerateDecelerate, ateCubic,
    ateTanh, ateCustom);

  TdxAnimationEvent = procedure(Sender: TdxAnimationTransition;
    var APosition: Integer; var AFinished: Boolean) of object;

  TdxAnimationTransitionEffectProc = function(Sender: TdxAnimationTransition;
    const AValue, AMaxValue: Int64; const ALength: Integer): Integer;

  IdxAnimationListener = interface
  ['{0CAAD87B-8A4B-464B-A738-1340BD80C3D8}']
    procedure AfterAnimation(Sender: TdxAnimationController);
    procedure BeforeAnimation(Sender: TdxAnimationController);
    procedure DestroyAnimation(Animation: TdxAnimationTransition);
  end;

  { TdxAnimationController }

  TdxAnimationController = class
  private
    FAnimations: TcxObjectList;
    FActiveAnimations: Integer;
    FListenerList: IInterfaceList;
    FTimer: TcxTimer;
    function GetAnimation(AIndex: Integer): TdxAnimationTransition;
    function GetCount: Integer;
  protected
    procedure CheckTimer;
    procedure Resume(Animation: TdxAnimationTransition);
    procedure Suspend(Animation: TdxAnimationTransition);
    procedure TimerHandler(Sender: TObject); virtual;
    procedure Terminate(Animation: TdxAnimationTransition);

    property Animations[Index: Integer]: TdxAnimationTransition read GetAnimation;
    property ActiveAnimations: Integer read FActiveAnimations write FActiveAnimations;
    property Count: Integer read GetCount;
    property ListenerList: IInterfaceList read FListenerList;
    property Timer: TcxTimer read FTimer write FTimer;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    procedure Add(Animation: TdxAnimationTransition);
    procedure AddListener(AListener: IdxAnimationListener);
    procedure Remove(Animation: TdxAnimationTransition);
    procedure RemoveListener(AListener: IdxAnimationListener);
    procedure Update;
  end;

  { TdxAnimationTransition }

  TdxAnimationTransition = class
  private
    FCurrent: Int64;
    FFinish: Int64;
    FFinished: Boolean;
    FFreeOnTerminate: Boolean;
    FInfo: TObject;
    FLength: Cardinal;
    FLockCount: Integer;
    FPosition: Integer;
    FPositionChanged: Boolean;
    FStart: Int64;
    FTime: Cardinal;
    FTimerInterval: Cardinal;
    FTransitionEffect: TdxAnimationTransitionEffect;
    FTransitionEffectProc: TdxAnimationTransitionEffectProc;
    FOnAfterAnimate: TdxAnimationEvent;
    FOnAnimate: TdxAnimationEvent;
    FOnBeforeAnimate: TdxAnimationEvent;
    FOnTerminate: TNotifyEvent;    
    function GetFinished: Boolean;
    function GetSuspended: Boolean;
    procedure SetFinished(AValue: Boolean);
  protected
    procedure Animate;
    procedure InitializeTime;
    function IsCompatible(Animation: TdxAnimationTransition): Boolean; virtual;
    procedure DoAfterAnimate; virtual;
    procedure DoAnimate; virtual;
    procedure DoBeforeAnimate; virtual;
    procedure TryAnimate;

    property Current: Int64 read FCurrent write FCurrent;
    property Finish: Int64 read FFinish write FFinish;
    property Length: Cardinal read FLength;
    property Start: Int64 read FStart write FStart;
    property TimerInterval: Cardinal read FTimerInterval write FTimerInterval;
  public
    constructor Create(ATime: Cardinal; ATransitionEffect: TdxAnimationTransitionEffect = ateLinear; ALength: Integer = -1); virtual;
    destructor Destroy; override;
    procedure ImmediateAnimation;
    procedure Resume;
    procedure Suspend(AFinished: Boolean = False);
    procedure Terminate;

    property TransitionEffect: TdxAnimationTransitionEffect read FTransitionEffect;
    property TransitionEffectProc: TdxAnimationTransitionEffectProc read FTransitionEffectProc;
    property Finished: Boolean read GetFinished write SetFinished;
    property FreeOnTerminate: Boolean read FFreeOnTerminate write FFreeOnTerminate;
    property Info: TObject read FInfo write FInfo;
    property Position: Integer read FPosition;
    property PositionChanged: Boolean read FPositionChanged write FPositionChanged;
    property Suspended: Boolean read GetSuspended;
    property Time: Cardinal read FTime;

    property OnAfterAnimate: TdxAnimationEvent read FOnAfterAnimate write FOnAfterAnimate;
    property OnAnimate: TdxAnimationEvent read FOnAnimate write FOnAnimate;
    property OnBeforeAnimate: TdxAnimationEvent read FOnBeforeAnimate write FOnBeforeAnimate;
    property OnTerminate: TNotifyEvent read FOnTerminate write FOnTerminate;    
  end;

  { TdxImageAnimationTransition }

  TdxImageAnimationTransition = class(TdxAnimationTransition)
  private
    FMode: TdxDrawAnimationMode;
  public
    constructor Create(const AStartImage, AFinishImage: TGraphic; ATime: Cardinal;
      AMode: TdxDrawAnimationMode; ATransition: TdxAnimationTransitionEffect = ateLinear;
      ALength: Integer = -1; AFreeImagesOnTerminate: Boolean = False); reintroduce; virtual;
    procedure Draw(ACanvas: TCanvas; const ADestRect: TRect); overload;
    procedure Draw(AGraphics: GpGraphics; const ADestRect: TRect); overload;
    procedure DrawTransparent(ACanvas: TCanvas; const ADestRect: TRect);

    property Mode: TdxDrawAnimationMode read FMode;
  end;

function dxAnimationController: TdxAnimationController;
function dxGetExactTickCount: Int64;
function dxGetExactTime(const AExactTickCount: Int64): Cardinal;
function dxMulDiv64(const nNumber, nNumerator, nDenominator: Int64): Int64;
function dxTimeToTickCount(const ATime: Cardinal): Int64;

implementation

type
  { TdxAnimationInfoSegments }

  TdxAnimationInfoSegments = class
  private
    FDelay: array of array of Integer;
    FDest, FSource: array of array of TRect;
    FLeft, FTop, FRowCount, FColCount: Integer;
    FAnimationLengthPerSegment: Integer;
    function GetCount(var ASize, AItemSize: Integer): Integer;
  public
    constructor Create(const ALeft, ATop, AWidth, AHeight, ASegmentWidth, ASegmentHeight: Integer);
    destructor Destroy; override;
    procedure DrawImage(AGraphics: GpGraphics; const ALeft, ATop, AWidth, AHeight: Integer;
      AStartImage, AFinishImage: TdxGPImage; AProgress: Byte);
    procedure InitializeItems(AWidth, AHeight, ASegmentWidth, ASegmentHeight: Integer);
    procedure InitializeRandomAlpha;
    procedure PrepareDestItems(const ALeft, ATop: Integer);
  end;

  { TdxAnimationInfo }

  TdxAnimationInfo = class
  protected
    Destination: TcxBitmap32;
    FreeOriginalImages: Boolean;
    SegmentsInfo: TdxAnimationInfoSegments;
    StartImage, FinishImage: TdxGPImage;
    StartImageOriginal, FinishImageOriginal: TGraphic;
    StartImageWasCreated, FinishImageWasCreated: Boolean;
    function CheckImage(ASourceImage: TGraphic; var ACheckedImage: TdxGPImage): Boolean;
    procedure DrawFade(AGraphics: GpGraphics; const ALeft, ATop, AWidth, AHeight: Integer; AProgress: Byte);
    procedure DrawRandomSegmentedFade(AGraphics: GpGraphics; const ALeft, ATop, AWidth, AHeight: Integer; AProgress: Byte);
    procedure DrawScrollDown(AGraphics: GpGraphics; const ALeft, ATop, AWidth, AHeight, AOffset: Integer);
    procedure DrawScrollLeft(AGraphics: GpGraphics; const ALeft, ATop, AWidth, AHeight, AOffset: Integer);
    procedure DrawScrollRight(AGraphics: GpGraphics; const ALeft, ATop, AWidth, AHeight, AOffset: Integer);
    procedure DrawScrollUp(AGraphics: GpGraphics; const ALeft, ATop, AWidth, AHeight, AOffset: Integer);
    procedure DrawSegmentedFade(AGraphics: GpGraphics; const ALeft, ATop, AWidth, AHeight: Integer; AProgress: Byte);
    function GetSegmentsInfo(const ALeft, ATop, AWidth, AHeight: Integer): TdxAnimationInfoSegments;
  public
    constructor Create(const AStartImage, AFinishImage: TGraphic; AFreeOriginalImages: Boolean = False);
    constructor CreateEx(const AStartImage, AFinishImage: TdxGPImage; AFreeOriginalImages: Boolean = False);
    destructor Destroy; override;
  end;

var
  AnimationController: TdxAnimationController;

function dxAnimationController: TdxAnimationController;
begin
  if AnimationController = nil then
    AnimationController := TdxAnimationController.Create;
  Result := AnimationController;
end;

function dxMulDiv64(const nNumber, nNumerator, nDenominator: Int64): Int64;
var
  A: Integer;
begin
  A := nNumber;
  Result := Trunc(A * nNumerator / nDenominator);
end;

function dxGetExactTickCount: Int64;
begin
  if not QueryPerformanceCounter(Result) then
    Result := GetTickCount;
end;

function dxGetExactTime(const AExactTickCount: Int64): Cardinal; // in milliseconds
var
  AFreq: Int64;
begin
  if QueryPerformanceFrequency(AFreq) then
    Result := dxMulDiv64(1000, AExactTickCount, AFreq)
  else
    Result := AExactTickCount;
end;

function dxTimeToTickCount(const ATime: Cardinal): Int64;
var
  AFreq: Int64;
begin
  if QueryPerformanceFrequency(AFreq) then
    Result := dxMulDiv64(ATime, AFreq, 1000)
  else
    Result := ATime;
end;

function dxLinearTransitionEffectProc(Sender: TdxAnimationTransition;
  const AValue, AMaxValue: Int64; const ALength: Integer): Integer;
begin
  Result := dxMulDiv64(ALength, AValue, AMaxValue);
end;

function dxAccelerateDecelerateTransitionEffectProc(Sender: TdxAnimationTransition;
  const AValue, AMaxValue: Int64; const ALength: Integer): Integer;
begin
  Result := Round(ALength * (-Power(AValue / AMaxValue - 1, 6) + 1));
end;

function dxCubicTransitionEffectProc(Sender: TdxAnimationTransition;
  const AValue, AMaxValue: Int64; const ALength: Integer): Integer;
var
  A: Double;
begin
  A := (Power((ALength - 1), 3) + 1) / AMaxValue;
  Result := Trunc(Power(A * AValue - 1, 1 / 3) + 1 + 0.5);
end;

function dxTanhTransitionEffectProc(Sender: TdxAnimationTransition;
  const AValue, AMaxValue: Int64; const ALength: Integer): Integer;
const
  AExactitude = 3;
var
  ATanh: Double;
begin
  ATanh := Tanh(AValue / AMaxValue * (2 * AExactitude) - AExactitude);
  Result := Trunc(ALength / (2 * Tanh(AExactitude)) * (ATanh - Tanh(-AExactitude)) + 0.5);
end;

{ TdxAnimationController }

constructor TdxAnimationController.Create;
begin
  FListenerList := TInterfaceList.Create;
  FAnimations := TcxObjectList.Create;
  FTimer := TcxTimer.Create(nil);
  FTimer.Interval := 1;
  FTimer.Enabled := False;
  FTimer.OnTimer := TimerHandler;
end;

destructor TdxAnimationController.Destroy;
begin
  FListenerList := nil; 
  FTimer.Free;
  FAnimations.Free;
  AnimationController := nil;
  inherited Destroy;
end;

procedure TdxAnimationController.Add(Animation: TdxAnimationTransition);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    if not Animations[I].IsCompatible(Animation) then
      Animations[I].Finished := True;
  FAnimations.Add(Animation);
end;

procedure TdxAnimationController.AddListener(AListener: IdxAnimationListener);
begin
  if FListenerList.IndexOf(AListener) = -1 then
    FListenerList.Add(AListener);
end;

procedure TdxAnimationController.Remove(Animation: TdxAnimationTransition);
var
  I: Integer;
begin
  for I := 0 to ListenerList.Count - 1 do
    (ListenerList[I] as IdxAnimationListener).DestroyAnimation(Animation);
  FAnimations.Remove(Animation);
end;

procedure TdxAnimationController.RemoveListener(
  AListener: IdxAnimationListener);
begin
  FListenerList.Remove(AListener);
end;

procedure TdxAnimationController.Update;
begin
  TimerHandler(nil);
end;

procedure TdxAnimationController.CheckTimer;
begin
  Timer.Enabled := ActiveAnimations > 0; 
end;

procedure TdxAnimationController.Resume(Animation: TdxAnimationTransition);
begin
  Inc(FActiveAnimations);
  CheckTimer;
end;

procedure TdxAnimationController.Suspend(Animation: TdxAnimationTransition);
begin
  Dec(FActiveAnimations);
  CheckTimer;
end;

procedure TdxAnimationController.TimerHandler(Sender: TObject);
var
  I: Integer;
begin
  for I := 0 to ListenerList.Count - 1 do
    (ListenerList[I] as IdxAnimationListener).BeforeAnimation(Self);
  try
    for I := Count - 1 downto 0 do
      Animations[I].TryAnimate;
  finally
    for I := 0 to ListenerList.Count - 1 do
      (ListenerList[I] as IdxAnimationListener).AfterAnimation(Self);
  end;
  for I := Count - 1 downto 0 do
    Animations[I].PositionChanged := False;
end;

procedure TdxAnimationController.Terminate(Animation: TdxAnimationTransition);
begin
  Dec(FActiveAnimations);
  CheckTimer;
end;

function TdxAnimationController.GetAnimation(AIndex: Integer): TdxAnimationTransition;
begin
  Result := TdxAnimationTransition(FAnimations.List[AIndex]);
end;

function TdxAnimationController.GetCount: Integer;
begin
  Result := FAnimations.Count;
end;

{ TdxAnimationInfoSegments }

constructor TdxAnimationInfoSegments.Create(
  const ALeft, ATop, AWidth, AHeight, ASegmentWidth, ASegmentHeight: Integer);
begin
  inherited Create;
  FTop := ATop;
  FLeft := ALeft;
  InitializeItems(AWidth, AHeight, ASegmentWidth, ASegmentHeight);
end;

function TdxAnimationInfoSegments.GetCount(var ASize, AItemSize: Integer): Integer;
begin
  while (AItemSize > 1) and (ASize div AItemSize < 5) do
    Dec(AItemSize);
  Result := ASize div AItemSize;
  if ASize mod AItemSize <> 0 then
    Inc(Result);
end;

destructor TdxAnimationInfoSegments.Destroy;
begin
  Finalize(FDest);
  Finalize(FSource);
  Finalize(FDelay);
  inherited Destroy;
end;

procedure TdxAnimationInfoSegments.DrawImage(AGraphics: GpGraphics; const ALeft,
  ATop, AWidth, AHeight: Integer; AStartImage, AFinishImage: TdxGPImage; AProgress: Byte);
var
  ACellAlpha: Integer;
  ARow, ACol: Integer;
begin
  PrepareDestItems(ALeft, ATop);
  for ARow := 0 to FRowCount - 1 do
    for ACol := 0 to FColCount - 1 do
    begin
      ACellAlpha := MulDiv(MaxByte, AProgress - FDelay[ARow, ACol], FAnimationLengthPerSegment);
      ACellAlpha := Max(0, Min(MaxByte, ACellAlpha));
      if ACellAlpha < 255 then
        dxGpDrawImage(AGraphics, FDest[ARow, ACol], FSource[ARow, ACol], AStartImage.Handle);
      if ACellAlpha > 0 then
        dxGpDrawImage(AGraphics, FDest[ARow, ACol], FSource[ARow, ACol], AFinishImage.Handle, ACellAlpha);
    end;
end;

procedure TdxAnimationInfoSegments.InitializeItems(
  AWidth, AHeight, ASegmentWidth, ASegmentHeight: Integer);
var
  ARow, ACol: Integer;
begin
  FColCount := GetCount(AWidth, ASegmentWidth);
  FRowCount := GetCount(AHeight, ASegmentHeight);
  FAnimationLengthPerSegment := Max(1, 100 div Min(FRowCount, FColCount));

  SetLength(FDest, FRowCount, FColCount);
  SetLength(FSource, FRowCount, FColCount);
  SetLength(FDelay, FRowCount, FColCount);

  for ARow := 0 to FRowCount - 1 do
    for ACol := 0 to FColCount - 1 do
    begin
      FSource[ARow, ACol] := Rect(ACol * ASegmentWidth, ARow * ASegmentHeight,
        Min((ACol + 1) * ASegmentWidth, AWidth), Min((ARow + 1) * ASegmentHeight, AHeight));
      FDest[ARow, ACol] := cxRectOffset(FSource[ARow, ACol], FLeft, FTop);
      FDelay[ARow, ACol] := MulDiv(100 - FAnimationLengthPerSegment, ACol + ARow + 2, FRowCount + FColCount);
    end;
end;

procedure TdxAnimationInfoSegments.InitializeRandomAlpha;
var
  ARow, ACol: Integer;
begin
  for ARow := 0 to FRowCount - 1 do
    for ACol := 0 to FColCount - 1 do
      FDelay[ARow, ACol] := Random(100 - FAnimationLengthPerSegment + 1);
end;

procedure TdxAnimationInfoSegments.PrepareDestItems(const ALeft, ATop: Integer);
var
  ARow, ACol: Integer;
begin
  if (FLeft <> ALeft) or (FTop <> ATop) then
  begin
    FLeft := ALeft;
    FTop := ATop;
    for ARow := 0 to FRowCount - 1 do
      for ACol := 0 to FColCount - 1 do
        FDest[ARow, ACol] := cxRectOffset(FSource[ARow, ACol], ALeft, ATop);
  end;
end;

{ TdxAnimationInfo }

constructor TdxAnimationInfo.Create(const AStartImage: TGraphic;
  const AFinishImage: TGraphic; AFreeOriginalImages: Boolean = False);
begin
  StartImageOriginal := AStartImage;
  FinishImageOriginal := AFinishImage;
  StartImageWasCreated := CheckImage(AStartImage, StartImage);
  FinishImageWasCreated := CheckImage(AFinishImage, FinishImage);
  Destination := TcxBitmap32.CreateSize(AStartImage.Width, AStartImage.Height);
  FreeOriginalImages := AFreeOriginalImages;
end;

constructor TdxAnimationInfo.CreateEx(const AStartImage: TdxGPImage;
  const AFinishImage: TdxGPImage; AFreeOriginalImages: Boolean = False);
begin
  FinishImage := AFinishImage;
  FinishImageOriginal := AFinishImage;
  StartImage := AStartImage;
  StartImageOriginal := AStartImage;
  FreeOriginalImages := AFreeOriginalImages;
end;

destructor TdxAnimationInfo.Destroy;
begin
  FreeAndNil(SegmentsInfo);
  FreeAndNil(Destination);
  if FreeOriginalImages then
  begin
    FreeAndNil(FinishImageOriginal);
    FreeAndNil(StartImageOriginal);
  end;
  if StartImageWasCreated then
    FreeAndNil(StartImage);
  if FinishImageWasCreated then
    FreeAndNil(FinishImage);
  inherited Destroy;
end;

function TdxAnimationInfo.CheckImage(ASourceImage: TGraphic; var ACheckedImage: TdxGPImage): Boolean;
var
  B: TcxBitmap32;
begin
  Result := not ((ASourceImage is TdxGPImage) and
    (TdxGPImage(ASourceImage).ImageDataFormat = dxImageBitmap));

  if not Result then
    ACheckedImage := TdxGPImage(ASourceImage)
  else
  begin
    if ASourceImage is TBitmap then
      ACheckedImage := TdxGPImage.CreateFromBitmap(TBitmap(ASourceImage))
    else
    begin
      B := TcxBitmap32.CreateSize(ASourceImage.Width, ASourceImage.Height);
      try
         B.Canvas.Draw(0, 0, ASourceImage);
         ACheckedImage := TdxGPImage.CreateFromHBitmap(B.Handle);
      finally
        B.Free;
      end;
    end;
  end;
  if Result and dxGPIsDoubleBufferedNeeded(cxScreenCanvas.Handle) then
    ACheckedImage.ImageDataFormat := dxImagePng;
end;

procedure TdxAnimationInfo.DrawFade(AGraphics: GpGraphics;
  const ALeft, ATop, AWidth, AHeight: Integer; AProgress: Byte);
begin
  dxGpDrawImage(AGraphics, cxRectBounds(ALeft, ATop, AWidth, AHeight),
    Rect(0, 0, AWidth, AHeight), StartImage.Handle);
  dxGpDrawImage(AGraphics, cxRectBounds(ALeft, ATop, AWidth, AHeight),
    Rect(0, 0, AWidth, AHeight), FinishImage.Handle, MulDiv(255, AProgress, 100));
end;

procedure TdxAnimationInfo.DrawRandomSegmentedFade(AGraphics: GpGraphics;
  const ALeft, ATop, AWidth, AHeight: Integer; AProgress: Byte);
var
  AWasInitialized: Boolean;
begin
  AWasInitialized := SegmentsInfo <> nil;
  with GetSegmentsInfo(ALeft, ATop, AWidth, AHeight) do
  begin
    if not AWasInitialized then
      InitializeRandomAlpha;
    DrawImage(AGraphics, ALeft, ATop, AWidth, AHeight, StartImage, FinishImage, AProgress);
  end;
end;

procedure TdxAnimationInfo.DrawScrollDown(AGraphics: GpGraphics;
  const ALeft, ATop, AWidth, AHeight, AOffset: Integer);
begin
  GdipCheck(GdipDrawImageRectI(AGraphics, StartImage.Handle,
    ALeft, ATop + AOffset, AWidth, AHeight));
  GdipCheck(GdipDrawImageRectI(AGraphics, FinishImage.Handle, ALeft,
    ATop - AHeight + AOffset, AWidth, AHeight));
end;

procedure TdxAnimationInfo.DrawScrollLeft(AGraphics: GpGraphics;
  const ALeft, ATop, AWidth, AHeight, AOffset: Integer);
begin
  GdipCheck(GdipDrawImageRectI(AGraphics, StartImage.Handle, ALeft -
    AOffset, ATop, AWidth, AHeight));
  GdipCheck(GdipDrawImageRectI(AGraphics, FinishImage.Handle, ALeft + AWidth -
    AOffset, ATop, AWidth, AHeight));
end;

procedure TdxAnimationInfo.DrawScrollRight(AGraphics: GpGraphics;
  const ALeft, ATop, AWidth, AHeight, AOffset: Integer);
begin
  GdipCheck(GdipDrawImageRectI(AGraphics, StartImage.Handle, ALeft +
    AOffset, ATop, AWidth, AHeight));
  GdipCheck(GdipDrawImageRectI(AGraphics, FinishImage.Handle, ALeft - AWidth +
    AOffset, ATop, AWidth, AHeight));
end;

procedure TdxAnimationInfo.DrawScrollUp(AGraphics: GpGraphics;
  const ALeft, ATop, AWidth, AHeight, AOffset: Integer);
begin
  GdipCheck(GdipDrawImageRectI(AGraphics, StartImage.Handle, ALeft,
    ATop - AOffset, AWidth, AHeight));
  GdipCheck(GdipDrawImageRectI(AGraphics, FinishImage.Handle, ALeft,
    ATop + AHeight - AOffset, AWidth, AHeight));
end;

procedure TdxAnimationInfo.DrawSegmentedFade(AGraphics: GpGraphics;
  const ALeft, ATop, AWidth, AHeight: Integer; AProgress: Byte);
begin
  GetSegmentsInfo(ALeft, ATop, AWidth, AHeight).DrawImage(
    AGraphics, ALeft, ATop, AWidth, AHeight, StartImage, FinishImage, AProgress);
end;

function TdxAnimationInfo.GetSegmentsInfo(const ALeft, ATop, AWidth, AHeight: Integer): TdxAnimationInfoSegments;
const
  MaxSegmentSize = 100;
begin
  if SegmentsInfo = nil then
    SegmentsInfo := TdxAnimationInfoSegments.Create(ALeft, ATop, AWidth, AHeight,
      Min(MaxSegmentSize, Max(1, AWidth div 10)), Min(MaxSegmentSize, Max(1, AHeight div 10)));
  Result := SegmentsInfo;
end;

{ TdxAnimationTransition }

constructor TdxAnimationTransition.Create(ATime: Cardinal;
  ATransitionEffect: TdxAnimationTransitionEffect = ateLinear; ALength: Integer = -1);
begin
  inherited Create;
  FLength := ALength;
  FTime := ATime;
  FTransitionEffect := ATransitionEffect;
  case FTransitionEffect of
    ateAccelerateDecelerate:
      FTransitionEffectProc := dxAccelerateDecelerateTransitionEffectProc;
    ateCubic:
      FTransitionEffectProc := dxCubicTransitionEffectProc;
    ateTanh:
      FTransitionEffectProc := dxTanhTransitionEffectProc;
  else
    FTransitionEffectProc := dxLinearTransitionEffectProc;
  end;
  FLockCount := 1;
  FFreeOnTerminate := True;
  dxAnimationController.Add(Self);
end;

destructor TdxAnimationTransition.Destroy;
begin
  if AnimationController <> nil then
    AnimationController.Remove(Self);
  FreeAndNil(FInfo);
  inherited Destroy;
end;

procedure TdxAnimationTransition.Animate;
var
  APosition: Integer;
begin
  FCurrent := Min(FFinish, dxGetExactTickCount);
  FFinished := FFinished or (FCurrent >= FFinish);
  if FFinished then
  begin
    FCurrent := FFinish;
    APosition := FLength;
  end
  else
    APosition := TransitionEffectProc(Self, FCurrent - FStart, FFinish - FStart, FLength);
  if (APosition <> FPosition) or (FPosition = 0) or Finished then
  begin
    PositionChanged := True;
    FPosition := APosition;
    DoBeforeAnimate;
    DoAnimate;
    DoAfterAnimate;
  end;
end;

procedure TdxAnimationTransition.DoAfterAnimate;
var
  AFinished: Boolean;
begin
  AFinished := Finished;
  if Assigned(FOnAfterAnimate) then
    FOnAfterAnimate(Self, FPosition, AFinished);
  FFinished := AFinished;
  if Finished then
    CallNotify(FOnTerminate, Self);
end;

procedure TdxAnimationTransition.DoAnimate;
var
  AFinished: Boolean;
begin
  AFinished := Finished;
  if Assigned(FOnAnimate) then
    FOnAnimate(Self, FPosition, AFinished);
  Finished := AFinished;
end;

procedure TdxAnimationTransition.DoBeforeAnimate;
var
  AFinished: Boolean;
begin
  AFinished := Finished;
  if Assigned(FOnBeforeAnimate) then
    FOnBeforeAnimate(Self, FPosition, AFinished);
  Finished := AFinished;
end;

procedure TdxAnimationTransition.ImmediateAnimation;
begin
  InitializeTime;
  while not Finished do
    Animate;
  if Finished and FreeOnTerminate then
    Free;
end;

procedure TdxAnimationTransition.InitializeTime;
begin
  if FCurrent <> 0 then
  begin
    FCurrent := FCurrent - FStart;
    FStart := dxGetExactTickCount - FCurrent;
    FCurrent := FStart + FCurrent;
  end
  else
    FStart := dxGetExactTickCount;
  FFinish := FStart + dxTimeToTickCount(FTime);
end;

function TdxAnimationTransition.IsCompatible(Animation: TdxAnimationTransition): Boolean;
begin
  Result := True;
end;

procedure TdxAnimationTransition.Resume;
begin
  Dec(FLockCount);
  if FLockCount = 0 then
  begin
    InitializeTime;
    dxAnimationController.Resume(Self);
  end;
end;

procedure TdxAnimationTransition.Suspend(AFinished: Boolean = False);
begin
  Inc(FLockCount);
  if (FLockCount = 1) and AFinished then
  begin
    dxAnimationController.Suspend(Self);
    Terminate;
  end;
end;

procedure TdxAnimationTransition.Terminate;
begin
  Finished := True;
  if FreeOnTerminate then
    Free;
end;

procedure TdxAnimationTransition.TryAnimate;
begin
  if Suspended then Exit;
  if not Finished and (dxGetExactTickCount < FFinish) then
    Animate
  else
    Finished := True;
  if Finished and FreeOnTerminate then
    Free;
end;

function TdxAnimationTransition.GetFinished: Boolean;
begin
  Result := FFinished;
end;

function TdxAnimationTransition.GetSuspended: Boolean;
begin
  Result := FLockCount > 0;
end;

procedure TdxAnimationTransition.SetFinished(AValue: Boolean);
begin
  if AValue <> FFinished then
  begin
    FCurrent := FFinish;
    FFinished := AValue;
    if not FFinished then
    begin
      FCurrent := 0;
      InitializeTime;
    end;
    Animate;
  end;
end;

{ TdxImageAnimationTransition }

constructor TdxImageAnimationTransition.Create(
  const AStartImage, AFinishImage: TGraphic; ATime: Cardinal;
  AMode: TdxDrawAnimationMode; ATransition: TdxAnimationTransitionEffect = ateLinear;
  ALength: Integer = -1; AFreeImagesOnTerminate: Boolean = False); 
begin
  FMode := AMode;
  if FMode in [amFade, amSegmentedFade, amRandomSegmentedFade] then
    ALength := 100
  else
    if ALength = -1 then
    begin
      if FMode in [amScrollLeft, amScrollRight] then
        ALength := AStartImage.Width
      else
        ALength := AStartImage.Height;
    end;
  FInfo := TdxAnimationInfo.Create(AStartImage, AFinishImage, AFreeImagesOnTerminate);
  inherited Create(ATime, ATransition, ALength);
end;

procedure TdxImageAnimationTransition.Draw(ACanvas: TCanvas; const ADestRect: TRect);
var
  AGraphics: GpGraphics;
  AInfo: TdxAnimationInfo;
begin
  AInfo := TdxAnimationInfo(FInfo);
  GdipCheck(GdipCreateFromHDC(AInfo.Destination.Canvas.Handle, AGraphics));
  try
    Draw(AGraphics, cxRect(cxRectSize(ADestRect)));
    BitBlt(ACanvas.Handle, ADestRect.Left, ADestRect.Top,
      cxRectWidth(ADestRect), cxRectHeight(ADestRect),
      AInfo.Destination.Canvas.Handle, 0, 0, SRCCOPY);
  finally
    GdipCheck(GdipDeleteGraphics(AGraphics));
  end;
end;

procedure TdxImageAnimationTransition.Draw(AGraphics: GpGraphics; const ADestRect: TRect);
var
  AInfo: TdxAnimationInfo;
  AWidth, AHeight: Integer;
begin
  AInfo := TdxAnimationInfo(Info);
  AWidth := ADestRect.Right - ADestRect.Left;
  AHeight := ADestRect.Bottom - ADestRect.Top;
  case Mode of
    amScrollRight:
      AInfo.DrawScrollRight(AGraphics, ADestRect.Left, ADestRect.Top, AWidth, AHeight, Position);
    amScrollUp:
      AInfo.DrawScrollUp(AGraphics, ADestRect.Left, ADestRect.Top, AWidth, AHeight, Position);
    amScrollLeft:
      AInfo.DrawScrollLeft(AGraphics, ADestRect.Left, ADestRect.Top, AWidth, AHeight, Position);
    amScrollDown:
      AInfo.DrawScrollDown(AGraphics, ADestRect.Left, ADestRect.Top, AWidth, AHeight, Position);
    amFade:
      AInfo.DrawFade(AGraphics, ADestRect.Left, ADestRect.Top, AWidth, AHeight, Position);
    amSegmentedFade:
      AInfo.DrawSegmentedFade(AGraphics, ADestRect.Left, ADestRect.Top, AWidth, AHeight, Position);
    amRandomSegmentedFade:
      AInfo.DrawRandomSegmentedFade(AGraphics, ADestRect.Left, ADestRect.Top, AWidth, AHeight, Position);
  end;
end;

procedure TdxImageAnimationTransition.DrawTransparent(ACanvas: TCanvas; const ADestRect: TRect);
var
  AGraphics: GpGraphics;
  AInfo: TdxAnimationInfo;
begin
  AInfo := TdxAnimationInfo(FInfo);
  GdipCheck(GdipCreateFromHDC(AInfo.Destination.Canvas.Handle, AGraphics));
  try
    AInfo.Destination.Clear;
    Draw(AGraphics, cxRect(cxRectSize(ADestRect)));
    cxAlphaBlend(ACanvas.Handle, AInfo.Destination, ADestRect, AInfo.Destination.ClientRect);
  finally
    GdipCheck(GdipDeleteGraphics(AGraphics));
  end;
end;

initialization

finalization
  FreeAndNil(AnimationController);

end.
