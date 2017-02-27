{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{       ExpressEditors                                               }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSEDITORS AND ALL                }
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

unit dxImageSlider;

interface

uses
  SysUtils, Windows, Classes, Controls, Graphics, Forms, ImgList, Messages,
  dxCore, dxCoreClasses, cxControls, cxGraphics, dxTouch,
  dxGDIPlusClasses, dxGDIPlusApi, dxAnimation, cxLookAndFeels;

type
  TdxImageSliderTransitionEffect = (isteNone, isteSlide, isteFade, isteSegmentedFade, isteRandomSegmentedFade);

  { TdxCustomImageSlider }

  TdxCustomImageSlider = class(TcxControl, IdxSkinSupport, IcxImageCollectionListener, IcxMouseTrackingCaller)
  private
    FAnimation: TdxImageAnimationTransition;
    FImageFitMode: TcxImageFitMode;
    FImages: TcxImageCollection;
    FItemIndex: Integer;
    FScrollNeeded: Boolean;
    FTransitionEffect: TdxImageSliderTransitionEffect;
    FTransparent: Boolean;

    FLeftArrowRect: TRect;
    FRightArrowRect: TRect;

    FPrevMousePos: TPoint;
    FLeftMouseButtonPressed: Boolean;

    FOnChange: TNotifyEvent;

    function GetCount: Integer;
    function IsValidItemIndex(AIndex: Integer): Boolean;
    procedure SetItemIndex(Value: Integer);
    procedure SetImages(Value: TcxImageCollection);
    procedure SetImageFitMode(Value: TcxImageFitMode);
    procedure SetTransparent(Value: Boolean);

    // IcxMouseTrackingCaller
    procedure IcxMouseTrackingCaller.MouseLeave = TrackingCallerMouseLeave;
    procedure TrackingCallerMouseLeave;

    procedure Changed;
  protected
    function AllowPan(AScrollKind: TScrollBarKind): Boolean; override;
    procedure BeginGestureScroll(APos: TPoint); override;
    procedure GestureScroll(ADeltaX, ADeltaY: Integer); override;
    procedure Loaded; override;
    function NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean; override;

    //mouse
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseEnter(AControl: TControl); override;
    procedure MouseLeave(AControl: TControl); override;

    //paint
    procedure EraseBackground(ACanvas: TcxCanvas; const ARect: TRect); override;
    procedure Paint; override;

    function NeedRedrawOnResize: Boolean; override;

    procedure Animate(AStartIndex, AFinishIndex: Integer); overload;
    procedure Animate(AStartPicture, AFinishPicture: TPicture;
      AAnimationMode: TdxDrawAnimationMode; ATransition: TdxAnimationTransitionEffect); overload;
    procedure AnimationHandler(Sender: TdxAnimationTransition; var APosition: Integer; var AFinished: Boolean);
    procedure StopAnimation;

    //IcxImageCollectionListener
    procedure ImageCollectionChanged;
    procedure ImageCollectionDestroyed;

    property Animation: TdxImageAnimationTransition read FAnimation;
    property Count: Integer read GetCount;
    property ImageFitMode: TcxImageFitMode read FImageFitMode write SetImageFitMode;
    property Images: TcxImageCollection read FImages write SetImages;
    property ItemIndex: Integer read FItemIndex write SetItemIndex;
    property TransitionEffect: TdxImageSliderTransitionEffect read FTransitionEffect write FTransitionEffect;
    property Transparent: Boolean read FTransparent write SetTransparent;

    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    function CanGoToNextImage: Boolean; virtual;
    function CanGoToPrevImage: Boolean; virtual;
    procedure GoToImage(ATargetItemIndex: Integer); virtual;
    procedure GoToNextImage; virtual;
    procedure GoToPrevImage; virtual;
  end;

  { TdxImageSlider }

  TdxImageSlider = class(TdxCustomImageSlider)
  published
    property Align;
    property Anchors;
    property BorderStyle default cxcbsDefault;
    property Color;
    property Enabled;
    property ImageFitMode default ifmProportionalStretch;
    property Images;
    property ItemIndex default 0;
    property LookAndFeel;
    property ParentColor;
    property TransitionEffect default isteSlide;
    property Transparent default True;
    property Visible;

    property OnContextPopup;
    property OnChange;
  end;

implementation

uses
  Math, Types, cxGeometry, cxLookAndFeelPainters;

{ TdxImageSlider }

constructor TdxCustomImageSlider.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);

  TransitionEffect := isteSlide;
  BorderStyle := cxcbsDefault;
  Width := 150;
  Height := 100;

  FImageFitMode := ifmProportionalStretch;
  FItemIndex := -1;
  FTransparent := True;
  DoubleBuffered := True;
end;

destructor TdxCustomImageSlider.Destroy;
begin
  EndMouseTracking(Self);
  StopAnimation;
  Images := nil;
  inherited Destroy;
end;

procedure TdxCustomImageSlider.Animate(AStartIndex, AFinishIndex: Integer);

  function GetDrawAnimationMode(AStartIndex, AFinishIndex: Integer): TdxDrawAnimationMode;
  const
    DrawAnimationModeMap: array[TdxImageSliderTransitionEffect] of TdxDrawAnimationMode = (
      amFade, amFade, amFade, amSegmentedFade, amRandomSegmentedFade
    );
  begin
    if TransitionEffect <> isteSlide then
      Result := DrawAnimationModeMap[TransitionEffect]
    else
      if AStartIndex > AFinishIndex then
        Result := amScrollRight
      else
        Result := amScrollLeft;
  end;


const
  TransitionMap: array[TdxDrawAnimationMode] of TdxAnimationTransitionEffect = (
    ateAccelerateDecelerate, ateAccelerateDecelerate, ateAccelerateDecelerate,
    ateAccelerateDecelerate, ateLinear, ateLinear, ateLinear);
    
var
  ADrawAnimationMode: TdxDrawAnimationMode;
begin
  if (TransitionEffect <> isteNone) and IsValidItemIndex(AStartIndex) and IsValidItemIndex(AFinishIndex) then
  begin
    ADrawAnimationMode := GetDrawAnimationMode(AStartIndex, AFinishIndex);
    Animate(Images.Items[AStartIndex].Picture, Images.Items[AFinishIndex].Picture,
      ADrawAnimationMode, TransitionMap[ADrawAnimationMode]);
  end
  else
    Invalidate;
end;

procedure TdxCustomImageSlider.Animate(AStartPicture, AFinishPicture: TPicture;
  AAnimationMode: TdxDrawAnimationMode; ATransition: TdxAnimationTransitionEffect);
var
  ARect: TRect;
  AStartBitmap, AFinishBitmap: TcxBitmap;
begin
  StopAnimation;
  ARect := ClientBounds;
  AStartBitmap := TcxBitmap.CreateSize(ARect);
  AFinishBitmap := TcxBitmap.CreateSize(ARect);
  EraseBackground(AStartBitmap.cxCanvas, AStartBitmap.ClientRect);
  cxCopyImage(AStartBitmap, AFinishBitmap, cxNullPoint, cxNullPoint, AStartBitmap.ClientRect);
  cxDrawPicture(AStartBitmap.cxCanvas, AStartBitmap.ClientRect, AStartPicture, ImageFitMode);
  cxDrawPicture(AFinishBitmap.cxCanvas, AFinishBitmap.ClientRect, AFinishPicture, ImageFitMode);
  FAnimation := TdxImageAnimationTransition.Create(AStartBitmap, AFinishBitmap, 800, AAnimationMode, ATransition, -1, True);
  FAnimation.OnAnimate := AnimationHandler;
  FAnimation.Resume;
end;

procedure TdxCustomImageSlider.AnimationHandler(
  Sender: TdxAnimationTransition; var APosition: Integer; var AFinished: Boolean);
begin
  if AFinished then
    FAnimation := nil;
  Refresh;
end;

function TdxCustomImageSlider.CanGoToNextImage: Boolean;
begin
  Result := IsValidItemIndex(ItemIndex + 1);
end;

function TdxCustomImageSlider.CanGoToPrevImage: Boolean;
begin
  Result := IsValidItemIndex(ItemIndex - 1);
end;

procedure TdxCustomImageSlider.Changed;
begin
  ItemIndex := ItemIndex;
  Invalidate;
end;

procedure TdxCustomImageSlider.EraseBackground(ACanvas: TcxCanvas; const ARect: TRect);
begin
  if Transparent then
    cxDrawTransparentControlBackground(Self, ACanvas, ARect, False)
  else
    ACanvas.FillRect(ARect, Color);
end;

procedure TdxCustomImageSlider.ImageCollectionChanged;
begin
  Changed;
end;

procedure TdxCustomImageSlider.ImageCollectionDestroyed;
begin
  Images := nil;
end;

function TdxCustomImageSlider.IsValidItemIndex(AIndex: Integer): Boolean;
begin
  Result := (AIndex >= 0) and (AIndex < Count);
end;

procedure TdxCustomImageSlider.GoToNextImage;
begin
  if CanGoToNextImage then
    GoToImage(ItemIndex + 1);
end;

procedure TdxCustomImageSlider.GoToPrevImage;
begin
  if CanGoToPrevImage then
    GoToImage(ItemIndex - 1);
end;

procedure TdxCustomImageSlider.GoToImage(ATargetItemIndex: Integer);
var
  APrevItemIndex: Integer;
begin
  APrevItemIndex := ItemIndex;
  ItemIndex := ATargetItemIndex;
  if ItemIndex <> APrevItemIndex then
  begin
    dxCallNotify(OnChange, Self);
    Animate(APrevItemIndex, ItemIndex);
  end;
end;

function TdxCustomImageSlider.AllowPan(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := AScrollKind = sbHorizontal;
end;

procedure TdxCustomImageSlider.BeginGestureScroll(APos: TPoint);
begin
  FScrollNeeded := True;
end;

procedure TdxCustomImageSlider.GestureScroll(ADeltaX, ADeltaY: Integer);
begin
  if FScrollNeeded then
  begin
    if ADeltaX > 0 then
      GoToPrevImage
    else
      GoToNextImage;
    FScrollNeeded := False;
  end;
end;

procedure TdxCustomImageSlider.Loaded;
begin
  inherited Loaded;
  ItemIndex := ItemIndex;
end;

function TdxCustomImageSlider.NeedPanningFeedback(AScrollKind: TScrollBarKind): Boolean;
begin
  Result := False;
end;

procedure TdxCustomImageSlider.MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseDown(Button, Shift, X, Y);
  FLeftMouseButtonPressed := Button = mbLeft;
  Invalidate;
end;

procedure TdxCustomImageSlider.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseMove(Shift, X, Y);

  if PtInRect(FLeftArrowRect, Point(X, Y)) xor PtInRect(FLeftArrowRect, FPrevMousePos) or
     PtInRect(FRightArrowRect, Point(X, Y)) xor PtInRect(FRightArrowRect, FPrevMousePos)
  then
    Invalidate;

  FPrevMousePos := Point(X, Y);
end;

procedure TdxCustomImageSlider.MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);

  if not IsDesigning and (Button = mbLeft) and (Animation = nil) then
  begin
    FLeftMouseButtonPressed := False;

    if PtInRect(FLeftArrowRect, Point(X, Y)) and PtInRect(FLeftArrowRect, MouseDownPos) then
      GotoPrevImage
    else
      if PtInRect(FRightArrowRect, Point(X, Y)) and PtInRect(FRightArrowRect, MouseDownPos) then
        GotoNextImage;
  end;
end;

procedure TdxCustomImageSlider.MouseEnter(AControl: TControl);
var
  AButtonSize, AOffset: TSize;
begin
  AButtonSize := LookAndFeelPainter.SliderButtonSize(adLeft);
  AOffset := cxSize(AButtonSize.cx div 2, AButtonSize.cy div 2);
  FLeftArrowRect := cxRectBounds(AOffset.cx, (Height - AButtonSize.cy) div 2, AButtonSize.cx, AButtonSize.cy);
  FRightArrowRect := cxRectBounds(Width - AButtonSize.cx - AOffset.cx, (Height - AButtonSize.cy) div 2, AButtonSize.cx, AButtonSize.cy);

  BeginMouseTracking(Self, Bounds, Self);
  Invalidate;
end;

procedure TdxCustomImageSlider.MouseLeave(AControl: TControl);
begin
  EndMouseTracking(Self);
  Invalidate;
end;

function TdxCustomImageSlider.NeedRedrawOnResize: Boolean;
begin
  Result := True;
end;

procedure TdxCustomImageSlider.Paint;

  procedure DrawButtons(const AMousePos: TPoint);

    function GetArrowState(const AArrowRect: TRect): TcxButtonState;
    begin
      if not PtInRect(AArrowRect, AMousePos) then
        Result := cxbsNormal
      else
      begin
        if FLeftMouseButtonPressed then
          Result := cxbsPressed
        else
          Result := cxbsHot;
      end;
    end;
    
  begin
    if not IsDesigning and PtInRect(ClientRect, AMousePos) and IsMouseTracking(Self) then
    begin
      if CanGoToPrevImage then
        LookAndFeelPainter.DrawSliderButton(Canvas, FLeftArrowRect, adLeft, GetArrowState(FLeftArrowRect));
      if CanGoToNextImage then
        LookAndFeelPainter.DrawSliderButton(Canvas, FRightArrowRect, adRight, GetArrowState(FRightArrowRect));
    end;
  end;

var
  AContentRect: TRect;
begin
  inherited Paint;

  AContentRect := ClientBounds;
  if IsValidItemIndex(ItemIndex) then
  begin
    if Animation <> nil then
      Animation.Draw(Canvas.Canvas, AContentRect)
    else
    begin
      cxDrawPicture(Canvas, AContentRect, Images.Items[ItemIndex].Picture, ImageFitMode);
      DrawButtons(ScreenToClient(GetMouseCursorPos));
    end;
  end;
end;

procedure TdxCustomImageSlider.TrackingCallerMouseLeave;
begin
  MouseLeave(nil);
end;

procedure TdxCustomImageSlider.StopAnimation;
begin
  if FAnimation <> nil then
  begin
    FAnimation.Terminate;
    FAnimation := nil;
  end;
end;

function TdxCustomImageSlider.GetCount: Integer;
begin
  if Images <> nil then
    Result := Images.Count
  else
    Result := 0;
end;

procedure TdxCustomImageSlider.SetItemIndex(Value: Integer);
begin
  if csLoading in ComponentState then
    FItemIndex := Value
  else
  begin
    Value := Min(Max(Value, 0), Count - 1);
    if ItemIndex <> Value then
    begin
      FItemIndex := Value;
      Changed;
    end;
  end;
end;

procedure TdxCustomImageSlider.SetImages(Value: TcxImageCollection);
begin
  if Images <> Value then
  begin
    if Images <> nil then
      Images.RemoveListener(Self);
    FImages := Value;
    if Images <> nil then
      Images.AddListener(Self);
    Changed;
  end;
end;

procedure TdxCustomImageSlider.SetImageFitMode(Value: TcxImageFitMode);
begin
  if ImageFitMode <> Value then
  begin
    FImageFitMode := Value;
    Changed;
  end;
end;

procedure TdxCustomImageSlider.SetTransparent(Value: Boolean);
begin
  if Transparent <> Value then
  begin
    FTransparent := Value;
    InvalidateRect(ClientRect, True);
  end;
end;

end.
