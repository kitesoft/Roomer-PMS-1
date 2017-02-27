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

unit AdvChartCustomControl;

{$I TMSDEFS.inc}

{$IFDEF LCLLIB}
{$mode objfpc}{$H+}{$modeswitch advancedrecords}
{$ENDIF}

{$IFDEF FMXLIB}
{$IFDEF IOS}
//{$DEFINE NATIVEIOSDRAWING}
{$ENDIF}
{$ENDIF}

interface

uses
  {$IFDEF MSWINDOWS}
  {%H-}Windows,
  {$ENDIF}
  Classes, Controls, AdvChartGraphics, AdvChartTypes, AdvChartStyles, Types
  {$IFDEF VCLLIB}
  ,Messages
  {$ENDIF}
  {$IFNDEF LCLLIB}
  ,UITypes
  {$ENDIF}
  {$IFDEF LCLLIB}
  ,LMessages
  {$ENDIF}
  {$IFDEF FMXLIB}
  ,FMX.Types, Messaging
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  ,iOSApi.UIKit, MacApi.ObjectiveC, MacApi.ObjcRuntime, TypInfo, iOSApi.Foundation, iOSApi.CoreGraphics
  {$ENDIF}
  ;

type
  TAdvChartCustomControl = class;

  {$IFDEF NATIVEIOSDRAWING}
  AdvChartCustomViewEx = interface(UIView)
    ['{D3989BF5-BE63-4077-82E8-B775B3325C23}']
    procedure drawRect(R: CGRect); cdecl;
    procedure touchesBegan(touches: NSSet; withEvent: UIEvent); cdecl;
    procedure touchesCancelled(touches: NSSet; withEvent: UIEvent); cdecl;
    procedure touchesEnded(touches: NSSet; withEvent: UIEvent); cdecl;
    procedure touchesMoved(touches: NSSet; withEvent: UIEvent); cdecl;
  end;

  TAdvChartCustomViewEx = class(TOCLocal)
  private
    FTap: Boolean;
    FView: TAdvChartCustomControl;
  public
    constructor Create;
    function GetTouchCoord(const touches: NSSet; const Window: UIView; var x, y: single): Boolean;
    function GetObjectiveCClass: PTypeInfo; override;
    procedure drawRect(R: CGRect); cdecl;
    procedure touchesBegan(touches: NSSet; withEvent: UIEvent); cdecl;
    procedure touchesCancelled(touches: NSSet; withEvent: UIEvent); cdecl;
    procedure touchesEnded(touches: NSSet; withEvent: UIEvent); cdecl;
    procedure touchesMoved(touches: NSSet; withEvent: UIEvent); cdecl;
  end;
  {$ENDIF}

  TAdvControlAlignment = (caNone, caTop, caBottom, caLeft, caRight, caClient);

  {$IFDEF FMXLIB}
  TAdvChartCustomControlBaseCommon = class(TControl, IAdvAdaptToStyle)
  {$ENDIF}
  {$IFDEF CMNLIB}
  TAdvChartCustomControlBaseCommon = class(TCustomControl, IAdvAdaptToStyle)
  {$ENDIF}
  private
    {$IFDEF CMNLIB}
    FAllowFocus: Boolean;
    {$ENDIF}
    FAdaptToStyle: Boolean;
    FAdaptedToStyle: Boolean;
    FTransparent: Boolean;
    function GetAllowFocus: Boolean;
    procedure SetAllowFocus(const Value: Boolean);
    procedure SetControlAlignment(const Value: TAdvControlAlignment);
  protected
    function GetClientMousePos: TPointF; virtual;
    function ConvertScreenToClient(APoint: TPointF): TPointF; virtual;
    function ConvertClientToScreen(APoint: TPointF): TPointF; virtual;
    function GetDragObjectScreenShot: TAdvChartBitmap; virtual;
    function GetAdaptToStyle: Boolean; virtual;
    procedure DestroyGraphicElements; virtual; abstract;
    procedure SetDefaultGraphicColors; virtual;
    procedure SetAdaptToStyle(const Value: Boolean); virtual;
    procedure CancelHint; virtual;
    procedure BeginDrag; virtual;
    procedure InitializeStyle;
    procedure ApplyStyle; virtual;
    procedure ResetToDefaultStyle; virtual;
    procedure HandleMouseLeave; virtual;
    procedure HandleMouseEnter; virtual;
    procedure HandleMouseDown({%H-}Button: TAdvMouseButton; {%H-}Shift: TShiftState; {%H-}X, {%H-}Y: Single); virtual;
    procedure HandleMouseMove({%H-}Shift: TShiftState; {%H-}X, {%H-}Y: Single); virtual;
    procedure HandleDblClick({%H-}X, {%H-}Y: Single); virtual;
    procedure HandleMouseUp({%H-}Button: TAdvMouseButton; {%H-}Shift: TShiftState; {%H-}X, {%H-}Y: Single); virtual;
    procedure HandleKeyPress(var {%H-}Key: Char); virtual;
    procedure HandleKeyDown(var {%H-}Key: Word; {%H-}Shift: TShiftState); virtual;
    procedure HandleDialogKey(var {%H-}Key: Word; {%H-}Shift: TShiftState); virtual;
    procedure HandleKeyUp(var {%H-}Key: Word; {%H-}Shift: TShiftState); virtual;
    procedure HandleMouseWheel({%H-}Shift: TShiftState; {%H-}WheelDelta: Integer; var {%H-}Handled: Boolean); virtual;
    procedure HandleDragOver(const {%H-}Source: TObject; const {%H-}Point: TPointF; var {%H-}Accept: Boolean); virtual;
    procedure HandleDragDrop(const {%H-}Source: TObject; const {%H-}Point: TPointF); virtual;
    property AdaptToStyle: Boolean read GetAdaptToStyle write SetAdaptToStyle default False;
    property Transparent: Boolean read FTransparent write FTransparent default False;
  public
    constructor Create(AOwner: TComponent); override;
    property AllowFocus: Boolean read GetAllowFocus write SetAllowFocus default True;
    property ControlAlignment: TAdvControlAlignment write SetControlAlignment default caNone;
  end;

  {$IFDEF FMXLIB}
  TAdvChartCustomControlBase = class(TAdvChartCustomControlBaseCommon)
  private
    FStyleChangedId: Integer;
    function GetL: Single;
    function GetT: Single;
    procedure SetTop(const Value: Single);
    procedure SetLeft(const Value: Single);
  protected
    procedure StyleChangedHandler(const Sender: TObject; const Msg: TMessage); virtual;
    procedure DoMouseEnter; override;
    procedure DoMouseLeave; override;
    procedure DragOver(const Data: TDragObject; const Point: TPointF; var Operation: TDragOperation); override;
    procedure DragDrop(const Data: TDragObject; const Point: TPointF); override;
    procedure MouseDown(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Single); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Single); override;
    procedure MouseUp(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Single); override;
    procedure KeyDown(var Key: Word; var KeyChar: WideChar; Shift: TShiftState); override;
    procedure KeyUp(var Key: Word; var KeyChar: WideChar; Shift: TShiftState); override;
    procedure DialogKey(var Key: Word; Shift: TShiftState); override;
    procedure MouseWheel(Shift: TShiftState; WheelDelta: Integer; var Handled: Boolean); override;
    procedure DblClick; override;
    {$WARNINGS OFF}
    {$HINTS OFF}
    {$IF COMPILERVERSION < 30}
    function GetHintString: String; virtual;
    function HasHint: Boolean; virtual;
    {$IFEND}
    {$IF COMPILERVERSION = 28}
    procedure BeginUpdate; virtual;
    procedure EndUpdate; virtual;
    {$IFEND}
    {$WARNINGS ON}
    {$HINTS ON}
  public
    property Left: Single read GetL write SetLeft;
    property Top: Single read GetT write SetTop;
    procedure Invalidate; virtual;
    procedure SetNewScene(AScene: IScene); override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
  end;
  {$ENDIF}

  {$IFDEF CMNLIB}
  TAdvChartCustomControlBase = class(TAdvChartCustomControlBaseCommon)
  private
    FStored: Boolean;
    FHitTest: Boolean;
    {$IFDEF VCLLIB}
    procedure WMGetDlgCode(var Message: TWMGetDlgCode); message WM_GETDLGCODE;
    procedure WMMouseWheel(var Message: TWMMouseWheel); message WM_MOUSEWHEEL;
    procedure WMEraseBkGnd(var Message: TWMEraseBkGnd); message WM_ERASEBKGND;
    procedure WMPaint(var Message: TWMPaint); message WM_PAINT;
    procedure CMMouseLeave(var Message: TMessage); message CM_MOUSELEAVE;
    procedure CMMouseEnter(var Message: TMessage); message CM_MOUSEENTER;
    procedure CMFocusChanged(var Message: TCMFocusChanged); message CM_FOCUSCHANGED;
    procedure CMHintShow(var Message: TMessage); message CM_HINTSHOW;
    procedure WMNCHitTest(var Message: TWMNCHitTest); message WM_NCHITTEST;
    procedure CMStyleChanged(var Message: TMessage); message CM_STYLECHANGED;
    {$ENDIF}
    {$IFDEF LCLLIB}
    procedure WMGetDlgCode(var {%H-}Message: TLMNoParams); message LM_GETDLGCODE;
    procedure WMEraseBkGnd(var {%H-}Message: TLMEraseBkGnd); message LM_ERASEBKGND;
    procedure WMPaint(var {%H-}Message: TLMPaint); message LM_PAINT;
    procedure WMMouseWheel(var {%H-}Message: TLMMouseEvent); message LM_MOUSEWHEEL;
    procedure CMMouseLeave(var {%H-}Message: TLMNoParams); message CM_MOUSELEAVE;
    procedure CMMouseEnter(var {%H-}Message: TLMNoParams); message CM_MOUSEENTER;
    procedure CMFocusChanged(var {%H-}Message: TLMessage); message CM_FOCUSCHANGED;
    procedure CMHintShow(var {%H-}Message: TLMessage); message CM_HINTSHOW;
    procedure WMNCHitTest(var Message: TLMessage) ; message LM_NCHITTEST;
    {$ENDIF}
  protected
    function GetHintString: String; virtual;
    function HasHint: Boolean; virtual;
    procedure MouseDown(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TAdvMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure DragOver(Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean); override;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure KeyPress(var Key: Char); override;
    procedure KeyUp(var Key: Word; Shift: TShiftState); override;
    procedure DblClick; override;
  public
    constructor Create(AOwner: TComponent); override;
    procedure BeginUpdate; virtual;
    procedure EndUpdate; virtual;
    procedure DragDrop(Source: TObject; X, Y: Integer); override;
    function CanFocus: Boolean; override;
    function LocalRect: TRectF; virtual;
    property Stored: Boolean read FStored write FStored default True;
    property HitTest: Boolean read FHitTest write FHitTest default True; 
  end;
  {$ENDIF}

  TAdvChartCustomControlBeforeDrawEvent = procedure(Sender: TObject; AGraphics: TAdvChartGraphics; ARect: TRectF; var ADefaultDraw: Boolean) of object;
  TAdvChartCustomControlAfterDrawEvent = procedure(Sender: TObject; AGraphics: TAdvChartGraphics; ARect: TRectF) of object;

  TAdvChartCustomControl = class(TAdvChartCustomControlBase, IAdvChartGraphicsExport)
  private
    FOnBeforeDraw: TAdvChartCustomControlBeforeDrawEvent;
    FOnAfterDraw: TAdvChartCustomControlAfterDrawEvent;
    {$IFDEF FMXLIB}
    FColor: TAdvChartGraphicsColor;
    {$ENDIF}
    {$IFDEF NATIVEIOSDRAWING}
    FCreated: Boolean;
    FView: UIView;
    FViewLocal: TAdvChartCustomViewEx;
    {$ENDIF}
    FCheckedChk, FUnCheckedChk, FCheckedFocusChk, FUnCheckedFocusChk, FCheckedDisabledChk, FUnCheckedDisabledChk: TAdvChartBitmap;
    FCheckedRd, FUnCheckedRd, FCheckedFocusRd, FUnCheckedFocusRd, FCheckedDisabledRd, FUnCheckedDisabledRd: TAdvChartBitmap;
    FDownBtn, FNormalBtn, FDownFocusBtn, FNormalFocusBtn, FNormalDisabledBtn: TAdvChartBitmap;
    FFill: TAdvChartGraphicsFill;
    FStroke: TAdvChartGraphicsStroke;
    procedure SetFill(const Value: TAdvChartGraphicsFill);
    procedure SetStroke(const Value: TAdvChartGraphicsStroke);
    {$IFDEF FMXLIB}
    procedure SetColor(const Value: TAdvChartGraphicsColor);
    {$ENDIF}
  protected
    function GetVersion: string; virtual;
    function LocalToScreenEx(APoint: TPointF): TPointF;
    function GetContentRect: TRectF; virtual;
    function GetControlRect: TRectF; virtual;
    procedure &Export({%H-}AGraphics: TAdvChartGraphics; {%H-}ARect: TRectF);
    procedure ApplyStyle; override;
    procedure ResetToDefaultStyle; override;
    procedure DestroyGraphicElements; override;
    {$IFDEF NATIVEIOSDRAWING}
    procedure Invalidate; reintroduce;
    procedure SetEnabled(const Value: Boolean); override;
    procedure SetVisible(const Value: Boolean); override;
    procedure SetParent(const Value: TFmxObject); override;
    {$ENDIF}
    {$IFDEF FMXLIB}
    procedure TurnOffAnimation(chk: TFmxObject); virtual;
    {$ENDIF}
    {$IFDEF LCLLIB}
    procedure DoSetBounds(ALeft, ATop, AWidth, AHeight: Integer); override;
    {$ENDIF}
    procedure UpdateControlAfterResize; virtual;
    procedure CreateCheckBoxBitmaps; virtual;
    procedure CreateRadioButtonBitmaps; virtual;
    procedure CreateButtonBitmaps(AWidth, AHeight: Single); virtual;
    procedure DoBeforeDraw(AGraphics: TAdvChartGraphics; ARect: TRectF; var ADefaultDraw: Boolean); virtual;
    procedure DoAfterDraw(AGraphics: TAdvChartGraphics; ARect: TRectF); virtual;
    procedure DrawBackground(AGraphics: TAdvChartGraphics; {%H-}ARect: TRectF); virtual;
    procedure StrokeChanged(Sender: TObject);
    procedure FillChanged(Sender: TObject);
    procedure Draw({%H-}AGraphics: TAdvChartGraphics; {%H-}ARect: TRectF); virtual;
    procedure DrawControl; virtual;
    {$IFDEF FMXMOBILE}
    {$IFDEF FREEWARE}
    procedure DrawTrial(AGraphics: TAdvChartGraphics; {%H-}ARect: TRectF); virtual;
    {$ENDIF}
    {$ENDIF}
    property Fill: TAdvChartGraphicsFill read FFill write SetFill;
    property Stroke: TAdvChartGraphicsStroke read FStroke write SetStroke;
    procedure CaptureEx; virtual;
    procedure ReleaseCaptureEx; virtual;
  public
    procedure Assign(Source: TPersistent); override;
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetCheckBoxBitmap(AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True): TAdvChartBitmap; virtual;
    function GetRadioButtonBitmap(AChecked: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True): TAdvChartBitmap; virtual;
    function GetButtonBitmap(AWidth, AHeight: Single; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True): TAdvChartBitmap; virtual;
    function IsDesignTime: Boolean; virtual;
    function IsLoading: Boolean; virtual;
    function IsReading: Boolean; virtual;
    function IsDesigning: Boolean; virtual;
    function IsDestroying: Boolean; virtual;
    {$IFDEF NATIVEIOSDRAWING}
    function GetRootView(AControl: TFMXObject): UIView;
    function GetRealPos(APos: TPointF; AControl: TControl): TPointF;
    procedure SetBounds(X, Y, AWidth, AHeight: Single); override;
    procedure UpdateFrame;
    procedure Initialize;
    procedure AddSubView(AParentView: UIView); virtual;
    procedure SetViewFrame(ARect: CGRect); virtual;
    {$ENDIF}
    procedure DisableBackground;
    procedure EnableBackground;
    procedure DisableFill;
    procedure EnableFill;
    procedure DisableStroke;
    procedure EnableStroke;
    procedure Resize; override;
    procedure Paint; override;
  published
    property AdaptToStyle;
    property Anchors;
    property AllowFocus default True;
    {$IFDEF FMXLIB}
    property Hint;
    property ShowHint;
    property Color: TAdvChartGraphicsColor read FColor write SetColor default gcWhite;
    property Align;
    property CanParentFocus;
    property ClipChildren default True;
    property ClipParent default False;
    property DisableFocusEffect default True;
    property DragMode default TDragMode.dmManual;
    property EnableDragHighlight default True;
    property Enabled default True;
    property Height;
    property HitTest default True;
    property Locked default False;
    property Padding;
    property Opacity;
    property Margins;
    property PopupMenu;
    property Position;
    property RotationAngle;
    property RotationCenter;
    property Scale;
    {$WARNINGS OFF}
    {$HINTS OFF}
    {$IF COMPILERVERSION > 27}
    property Size;
    {$IFEND}
    {$HINTS ON}
    {$WARNINGS ON}
    property TabOrder;
    property TabStop default True;
    property TouchTargetExpansion;
    property Visible default True;
    property Width;
    property OnApplyStyleLookup;
    property OnDragEnter;
    property OnDragLeave;
    property OnDragOver;
    property OnDragDrop;
    property OnDragEnd;
    property OnKeyDown;
    property OnKeyUp;
    property OnCanFocus;
    property OnClick;
    property OnDblClick;
    property OnEnter;
    property OnExit;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseWheel;
    property OnMouseEnter;
    property OnMouseLeave;
    property OnResize;
    {$ENDIF}

    {$IFDEF CMNLIB}
    property Align;
    {$IFDEF LCLLIB}
    property BorderSpacing;
    {$ENDIF}
    {$IFNDEF LCLLIB}
    property BevelEdges;
    property BevelInner;
    property BevelKind;
    property BevelOuter;
    property BevelWidth;
    property Ctl3D;
    property ParentCtl3D;
    property ParentDoubleBuffered;
    {$HINTS OFF}
    {$IF COMPILERVERSION > 23}
    property StyleElements;
    {$IFEND}
    {$HINTS ON}
    property Touch;
    property OnGesture;
    property OnMouseActivate;
    {$ENDIF}
    property BiDiMode;
    property Color default gcWhite;
    property Constraints;
    property DoubleBuffered;
    property DragCursor;
    property DragKind;
    property DragMode;
    property Enabled;
    property Font;
    property TabStop default True;
    property ParentBiDiMode;
    property ParentColor default False;
    property ParentFont;
    property ParentShowHint;
    property PopupMenu;
    property ShowHint;
    property Hint;
    property TabOrder;
    property Visible;
    property OnClick;
    property OnContextPopup;
    property OnDblClick;
    property OnDragDrop;
    property OnDragOver;
    property OnEndDock;
    property OnEndDrag;
    property OnEnter;
    property OnExit;
    property OnKeyDown;
    property OnKeyPress;
    property OnKeyUp;
    property OnMouseDown;
    property OnMouseEnter;
    property OnMouseLeave;
    property OnMouseMove;
    property OnMouseUp;
    property OnMouseWheelDown;
    property OnMouseWheelUp;
    property OnStartDock;
    property OnStartDrag;
    {$ENDIF}
    property OnBeforeDraw: TAdvChartCustomControlBeforeDrawEvent read FOnBeforeDraw write FOnBeforeDraw;
    property OnAfterDraw: TAdvChartCustomControlAfterDrawEvent read FOnAfterDraw write FOnAfterDraw;
  end;

implementation

uses
  AdvChartUtils, SysUtils, Graphics, Forms
  {$IFNDEF LCLLIB}
  ,StdCtrls
  {$ENDIF}
  {$IFDEF FMXLIB}
  ,FMX.Platform, FMX.Ani
  {$ENDIF}
  {$IFDEF LCLLIB}
  ,LCLType
  {$ENDIF}
  {$IFDEF VCLLIB}
  ,AdvChartXPVS
  {$ENDIF}
  {$IFDEF NATIVEIOSDRAWING}
  ,FMX.Platform.iOS
  {$ENDIF}
  {$IFNDEF FMXMOBILE}
  {$IFDEF FREEWARE}
  {$IFDEF MSWINDOWS}
  ,System.Win.Registry, WinApi.ShellApi
  {$ENDIF}
  {$IFDEF MACOS}
  ,MacApi.AppKit, MacApi.Foundation, MacApi.Helpers
  {$ENDIF}
  {$IFDEF FMXLIB}
  ,FMX.Objects, UIConsts
  {$ENDIF}
  {$IFDEF VCLLIB}
  ,VCL.ExtCtrls
  {$ENDIF}
  {$ENDIF}
  {$ENDIF}
  ;

{$IFDEF CMNLIB}
type
  TWinControlProtected = class(TWinControl);
{$ENDIF}

{ TAdvChartCustomControlBaseCommon }

procedure TAdvChartCustomControlBaseCommon.SetAdaptToStyle(const Value: Boolean);
begin
  FAdaptToStyle := Value;
  InitializeStyle;
end;

function TAdvChartCustomControlBaseCommon.GetAdaptToStyle: Boolean;
begin
  Result := FAdaptToStyle;
end;

procedure TAdvChartCustomControlBaseCommon.ApplyStyle;
begin

end;

procedure TAdvChartCustomControlBaseCommon.ResetToDefaultStyle;
begin

end;

procedure TAdvChartCustomControlBaseCommon.SetDefaultGraphicColors;
var
  c: TAdvChartGraphicsColor;
begin
  c := gcNull;
  if TAdvChartStyles.GetStyleBackgroundFillColor(c) then
    TAdvChartGraphics.DefaultPopupFillColor := c
  else
    TAdvChartGraphics.DefaultPopupFillColor := gcWhite;

  c := gcNull;
  if TAdvChartStyles.GetStyleBackgroundStrokeColor(c) then
    TAdvChartGraphics.DefaultPopupStrokeColor := c
  else
    TAdvChartGraphics.DefaultPopupStrokeColor := gcSilver;

  c := gcNull;
  if TAdvChartStyles.GetStyleDefaultButtonFillColor(c) then
    TAdvChartGraphics.DefaultButtonFillColor := c
  else
    TAdvChartGraphics.DefaultButtonFillColor := MakeGraphicsColor(225, 225, 225);

  c := gcNull;
  if TAdvChartStyles.GetStyleLineFillColor(c) then
    TAdvChartGraphics.DefaultButtonStrokeColor := c
  else
    TAdvChartGraphics.DefaultButtonStrokeColor := gcDarkgray;

  c := gcNull;
  if TAdvChartStyles.GetStyleTextFontColor(c) then
    TAdvChartGraphics.DefaultTextFontColor := c
  else
    TAdvChartGraphics.DefaultTextFontColor := gcBlack;

  c := gcNull;
  if TAdvChartStyles.GetStyleSelectionFillColor(c) then
  begin
    TAdvChartGraphics.DefaultSelectionFillColor := c;
    TAdvChartGraphics.DefaultButtonFillColorFocused := Blend(c, TAdvChartGraphics.DefaultButtonFillColor, 25);
    TAdvChartGraphics.DefaultButtonStrokeColorFocused := Blend(c, TAdvChartGraphics.DefaultButtonStrokeColor, 30);
  end
  else
  begin
    TAdvChartGraphics.DefaultSelectionFillColor := gcBlack;
    TAdvChartGraphics.DefaultButtonFillColorFocused := MakeGraphicsColor(229, 241, 251);
    TAdvChartGraphics.DefaultButtonStrokeColorFocused := MakeGraphicsColor(60, 127, 177);
  end;

  TAdvChartGraphics.DefaultButtonStrokeColorDisabled := gcDarkGray;
  TAdvChartGraphics.DefaultButtonFillColorDisabled := gcLightgray;
end;

procedure TAdvChartCustomControlBaseCommon.InitializeStyle;
begin
  {$IFDEF FMXLIB}
  TAdvChartStyles.SetActiveScene(Scene);
  {$ENDIF}
  SetDefaultGraphicColors;
  DestroyGraphicElements;
  if AdaptToStyle then
  begin
    FAdaptedToStyle := True;
    ApplyStyle;
  end
  else if FAdaptedToStyle then
  begin
    ResetToDefaultStyle;
    FAdaptedToStyle := False;
  end;

  Invalidate;
end;

function TAdvChartCustomControlBaseCommon.GetClientMousePos: TPointF;
begin
  Result := ConvertScreenToClient(TAdvChartUtils.GetMousePos);
end;

{$IFDEF CMNLIB}
function TAdvChartCustomControlBaseCommon.ConvertClientToScreen(APoint: TPointF): TPointF;
var
  p: TPoint;
begin
  p := ClientToScreen(Point(Round(APoint.X), Round(APoint.Y)));
  Result := PointF(p.X, p.Y);
end;
{$ENDIF}

{$IFDEF FMXLIB}
function TAdvChartCustomControlBaseCommon.ConvertClientToScreen(APoint: TPointF): TPointF;
begin
  Result := LocalToScreen(APoint);
end;
{$ENDIF}

{$IFDEF CMNLIB}
function TAdvChartCustomControlBaseCommon.ConvertScreenToClient(APoint: TPointF): TPointF;
var
  p: TPoint;
begin
  p := ScreenToClient(Point(Round(APoint.X), Round(APoint.Y)));
  Result := PointF(p.X, p.Y);
end;
{$ENDIF}

{$IFDEF FMXLIB}
function TAdvChartCustomControlBaseCommon.ConvertScreenToClient(APoint: TPointF): TPointF;
begin
  Result := ScreenToLocal(APoint);
end;
{$ENDIF}

constructor TAdvChartCustomControlBaseCommon.Create(AOwner: TComponent);
begin
  inherited;
  SetDefaultGraphicColors;
  FAdaptToStyle := False;
  FAdaptedToStyle := False;
  FTransparent := False;
  {$IFDEF CMNLIB}
  FAllowFocus := True;
  {$ENDIF}
end;

function TAdvChartCustomControlBaseCommon.GetAllowFocus: Boolean;
begin
  {$IFDEF FMXLIB}
  Result := CanFocus;
  {$ENDIF}
  {$IFDEF CMNLIB}
  Result := FAllowFocus;
  {$ENDIF}
end;

procedure TAdvChartCustomControlBaseCommon.SetAllowFocus(const Value: Boolean);
begin
  {$IFDEF FMXLIB}
  CanFocus := Value;
  {$ENDIF}
  {$IFDEF CMNLIB}
  FAllowFocus := Value;
  {$ENDIF}
end;

procedure TAdvChartCustomControlBaseCommon.SetControlAlignment(const Value: TAdvControlAlignment);
begin
  {$IFDEF FMXLIB}
  case Value of
    caNone: Align := TAlignLayout.None;
    caTop: Align := TAlignLayout.Top;
    caBottom: Align := TAlignLayout.Bottom;
    caLeft: Align := TAlignLayout.Left;
    caRight: Align := TAlignLayout.Right;
    caClient: Align := TAlignLayout.Client;
  end;
  {$ENDIF}
  {$IFDEF CMNLIB}
  case Value of
    caNone: Align := alNone;
    caTop: Align := alTop;
    caBottom: Align := alBottom;
    caLeft: Align := alLeft;
    caRight: Align := alRight;
    caClient: Align := alClient;
  end;
  {$ENDIF}
end;

procedure TAdvChartCustomControlBaseCommon.HandleMouseLeave;
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleMouseEnter;
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleMouseDown(Button: TAdvMouseButton; Shift: TShiftState; X: Single; Y: Single);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleMouseMove(Shift: TShiftState; X: Single; Y: Single);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleDblClick(X: Single; Y: Single);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleDragOver(const Source: TObject; const Point: TPointF; var Accept: Boolean);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleDragDrop(const Source: TObject; const Point: TPointF);
begin
end;

procedure TAdvChartCustomControlBaseCommon.HandleMouseUp(Button: TAdvMouseButton; Shift: TShiftState; X: Single; Y: Single);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleKeyPress(var Key: Char);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleKeyDown(var Key: Word; Shift: TShiftState);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleDialogKey(var Key: Word; Shift: TShiftState);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleKeyUp(var Key: Word; Shift: TShiftState);
begin

end;

procedure TAdvChartCustomControlBaseCommon.HandleMouseWheel(Shift: TShiftState; WheelDelta: Integer; var Handled: Boolean);
begin

end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomControlBase.StyleChangedHandler(const Sender: TObject; const Msg: TMessage);
begin
  InitializeStyle;
end;

constructor TAdvChartCustomControlBase.Create(AOwner: TComponent);
begin
  inherited;
  FStyleChangedId := TMessageManager.DefaultManager.SubscribeToMessage(TStyleChangedMessage, StyleChangedHandler);
end;

destructor TAdvChartCustomControlBase.Destroy;
begin
  TMessageManager.DefaultManager.Unsubscribe(TStyleChangedMessage, FStyleChangedId);
  inherited;
end;

procedure TAdvChartCustomControlBase.Invalidate;
begin
  Invalidate;
end;

{$WARNINGS OFF}
{$HINTS OFF}
{$IF COMPILERVERSION < 30}
function TAdvChartCustomControlBase.GetHintString: String;
begin
  Result := '';
end;

function TAdvChartCustomControlBase.HasHint: Boolean;
begin
  Result := False;
end;
{$IFEND}
{$HINTS ON}
{$WARNINGS ON}

function TAdvChartCustomControlBase.GetL: Single;
begin
  Result := Position.X;
end;

function TAdvChartCustomControlBase.GetT: Single;
begin
  Result := Position.Y;
end;

procedure TAdvChartCustomControlBase.SetTop(const Value: Single);
begin
  Position.Y := Value;
end;

procedure TAdvChartCustomControlBase.SetLeft(const Value: Single);
begin
  Position.X := Value;
end;

{$WARNINGS OFF}
{$HINTS OFF}
{$IF COMPILERVERSION = 28}
procedure TAdvChartCustomControlBase.BeginUpdate;
begin
end;

procedure TAdvChartCustomControlBase.EndUpdate;
begin
end;
{$IFEND}
{$HINTS ON}
{$WARNINGS ON}

procedure TAdvChartCustomControlBase.KeyDown(var Key: Word; var KeyChar: WideChar;
  Shift: TShiftState);
begin
  inherited;
  if KeyChar = ' ' then
    Key := KEY_SPACE;

  HandleKeyPress(KeyChar);
  HandleKeyDown(Key, Shift);
end;

procedure TAdvChartCustomControlBase.KeyUp(var Key: Word; var KeyChar: WideChar;
  Shift: TShiftState);
begin
  inherited;
  if KeyChar = ' ' then
    Key := KEY_SPACE;

  HandleKeyUp(Key, Shift);
end;

procedure TAdvChartCustomControlBase.DialogKey(var Key: Word; Shift: TShiftState);
begin
  inherited;
  HandleDialogKey(Key, Shift);
end;

procedure TAdvChartCustomControlBase.DragOver(const Data: TDragObject; const Point: TPointF; var Operation: TDragOperation);
var
  b: Boolean;
begin
  inherited;
  b := Operation = TDragOperation.Move;
  HandleDragOver(Data.Source, Point, b);
  if b then
    Operation := TDragOperation.Move;
end;

procedure TAdvChartCustomControlBase.DragDrop(const Data: TDragObject; const Point: TPointF);
begin
  inherited;
  HandleDragDrop(Data.Source, Point);
end;

procedure TAdvChartCustomControlBase.MouseDown(Button: TAdvMouseButton; Shift: TShiftState; X,
  Y: Single);
begin
  inherited;
  HandleMouseDown(Button, Shift, X, Y);
end;

procedure TAdvChartCustomControlBase.MouseMove(Shift: TShiftState; X, Y: Single);
begin
  inherited;
  HandleMouseMove(Shift, X, Y);
end;

procedure TAdvChartCustomControlBase.MouseUp(Button: TAdvMouseButton; Shift: TShiftState; X,
  Y: Single);
begin
  inherited;
  HandleMouseUp(Button, Shift, X, Y);
end;

procedure TAdvChartCustomControlBase.MouseWheel(Shift: TShiftState; WheelDelta: Integer;
  var Handled: Boolean);
begin
  inherited;
  HandleMouseWheel(Shift, WheelDelta, Handled);
end;

procedure TAdvChartCustomControlBase.DoMouseEnter;
begin
  inherited;
  HandleMouseEnter;
end;

procedure TAdvChartCustomControlBase.SetNewScene(AScene: IScene);
begin
  inherited;
  TAdvChartStyles.SetActiveScene(AScene);
end;

procedure TAdvChartCustomControlBase.DoMouseLeave;
begin
  inherited;
  HandleMouseLeave;
end;

{$ENDIF}

procedure TAdvChartCustomControlBase.DblClick;
var
  pf: TPointF;
begin
  inherited;
  pf := ConvertScreenToClient(TAdvChartUtils.GetMousePos);
  HandleDblClick(pf.X, pf.Y);
end;

{$IFDEF CMNLIB}
procedure TAdvChartCustomControlBase.KeyPress(var Key: Char);
begin
  inherited;
  HandleKeyPress(Key);
end;

procedure TAdvChartCustomControlBase.KeyDown(var Key: Word; Shift: TShiftState);
var
  Ctrl: TWinControl;
begin
  inherited;
  HandleDialogKey(Key, Shift);
  HandleKeyDown(Key, Shift);
  if Key = KEY_TAB then
  begin
    if ssShift in Shift then
      Ctrl := TWinControlProtected(Self.Parent).FindNextControl(Self, False, True, True)
    else
      Ctrl := TWinControlProtected(Self.Parent).FindNextControl(Self, True, True, True);

    if Assigned(Ctrl) and Ctrl.CanFocus then
      Ctrl.SetFocus;
  end;
end;

procedure TAdvChartCustomControlBase.KeyUp(var Key: Word; Shift: TShiftState);
begin
  inherited;
  HandleKeyUp(Key, Shift);
end;

procedure TAdvChartCustomControlBase.DragOver(Source: TObject; X, Y: Integer; State: TDragState; var Accept: Boolean);
begin
  inherited;
  HandleDragOver(Source, PointF(X, Y), Accept);
end;

procedure TAdvChartCustomControlBase.DragDrop(Source: TObject; X, Y: Integer);
begin
  inherited;
  HandleDragDrop(Source, PointF(X, Y));
end;

procedure TAdvChartCustomControlBase.MouseDown(Button: TAdvMouseButton; Shift: TShiftState; X,
  Y: Integer);
begin
  inherited;
  HandleMouseDown(Button, Shift, X, Y);
end;

procedure TAdvChartCustomControlBase.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited;
  HandleMouseMove(Shift, X, Y);
end;

procedure TAdvChartCustomControlBase.MouseUp(Button: TAdvMouseButton; Shift: TShiftState; X,
  Y: Integer);
begin
  inherited;
  HandleMouseUp(Button, Shift, X, Y);
end;

{$IFDEF VCLLIB}
procedure TAdvChartCustomControlBase.CMHintShow(var Message: TMessage);
var
  h: String;
begin
  with TCMHintShow(Message).HintInfo^ do
  begin
    if HasHint then
    begin
      h := GetHintString;
      HintStr := h;
      ReshowTimeout := 0;
    end;
  end;
end;

procedure TAdvChartCustomControlBase.CMStyleChanged(var Message: TMessage);
begin
  InitializeStyle;
end;

procedure TAdvChartCustomControlBase.WMNCHitTest(var Message: TWMNCHitTest);
begin
  if not HitTest then
    Message.Result := HTTRANSPARENT
  else
    inherited;
end;

procedure TAdvChartCustomControlBase.WMPaint(var Message: TWMPaint);
begin
  if Transparent then
    PaintHandler(Message)
  else
    inherited;
end;

procedure TAdvChartCustomControlBase.WMEraseBkGnd(var Message: TWMEraseBkGnd);
begin
  if Transparent then
    Message.Result := 1
  else
    inherited;
end;

procedure TAdvChartCustomControlBase.WMGetDlgCode(var Message: TWMGetDlgCode);
begin
  if TabStop then
    Message.result := DLGC_WANTALLKEYS or DLGC_WANTARROWS or DLGC_WANTTAB
  else
    Message.result := DLGC_WANTALLKEYS or DLGC_WANTARROWS;
end;

procedure TAdvChartCustomControlBase.WMMouseWheel(var Message: TWMMouseWheel);
var
  b: Boolean;
begin
  inherited;
  b := False;
  HandleMouseWheel([], Message.WheelDelta, b);
end;

procedure TAdvChartCustomControlBase.CMFocusChanged(var Message: TCMFocusChanged);
begin
  Invalidate;
end;

procedure TAdvChartCustomControlBase.CMMouseLeave(var Message: TMessage);
begin
  HandleMouseLeave;
end;

procedure TAdvChartCustomControlBase.CMMouseEnter(var Message: TMessage);
begin
  HandleMouseEnter;
end;
{$ENDIF}

{$IFDEF LCLLIB}
procedure TAdvChartCustomControlBase.CMFocusChanged(var Message: TLMessage);
begin
  Invalidate;
end;

procedure TAdvChartCustomControlBase.CMMouseLeave(var Message: TLMNoParams);
begin
  HandleMouseLeave;
end;

procedure TAdvChartCustomControlBase.CMMouseEnter(var Message: TLMNoParams);
begin
  HandleMouseEnter;
end;

procedure TAdvChartCustomControlBase.CMHintShow(var Message: TLMessage);
var
  h: String;
begin
  with TCMHintShow(Message).HintInfo^ do
  begin
    if HasHint then
    begin
      h := GetHintString;
      HintStr := h;
      ReshowTimeout := 0;
    end;
  end;
end;

procedure TAdvChartCustomControlBase.WMNCHitTest(var Message: TLMessage);
begin
  if not HitTest then
    Message.Result := HTTRANSPARENT
  else
    inherited;
end;

procedure TAdvChartCustomControlBase.WMPaint(var Message: TLMPaint);
begin
  if Transparent then
    PaintHandler(Message)
  else
    inherited;
end;

procedure TAdvChartCustomControlBase.WMEraseBkGnd(var Message: TLMEraseBkGnd);
begin
  if Transparent then
    Message.Result := 1
  else
    inherited;
end;

procedure TAdvChartCustomControlBase.WMGetDlgCode(var Message: TLMNoParams);
begin
  if TabStop then
    Message.result := DLGC_WANTALLKEYS or DLGC_WANTARROWS or DLGC_WANTTAB
  else
    Message.result := DLGC_WANTALLKEYS or DLGC_WANTARROWS;
end;

procedure TAdvChartCustomControlBase.WMMouseWheel(var Message: TLMMouseEvent);
var
  b: Boolean;
begin
  inherited;
  b := False;
  HandleMouseWheel([], Message.WheelDelta, b);
end;
{$ENDIF}

function TAdvChartCustomControlBase.CanFocus: Boolean;
begin
  Result := inherited CanFocus;
  Result := Result and AllowFocus;
end;

procedure TAdvChartCustomControlBase.BeginUpdate;
begin

end;

procedure TAdvChartCustomControlBase.EndUpdate;
begin

end;

function TAdvChartCustomControlBase.LocalRect: TRectF;
begin
  Result := RectF(0, 0, Width, Height);
end;

constructor TAdvChartCustomControlBase.Create(AOwner: TComponent);
begin
  inherited;
  FHitTest := True;
  FStored := True;
  DoubleBuffered := True;
  ControlStyle := ControlStyle + [csAcceptsControls];
end;
{$ENDIF}

procedure TAdvChartCustomControl.DisableBackground;
begin
  FFill.Kind := gfkNone;
  FStroke.Kind := gskNone;
  {$IFDEF CMNLIB}
  Color := clBtnFace;
  ParentColor := False;
  {$ENDIF}
end;

procedure TAdvChartCustomControl.EnableBackground;
begin
  FFill.Kind := gfkSolid;
  FStroke.Kind := gskSolid;
end;

procedure TAdvChartCustomControl.DisableStroke;
begin
  FStroke.Kind := gskNone;
end;

{$IFDEF LCLLIB}
procedure TAdvChartCustomControl.DoSetBounds(ALeft, ATop, AWidth,
  AHeight: Integer);
begin
  inherited DoSetBounds(ALeft, ATop, AWidth, AHeight);
  UpdateControlAfterResize;
end;
{$ENDIF}

{$IFDEF FMXLIB}
procedure TAdvChartCustomControl.SetColor(const Value: TAdvChartGraphicsColor);
begin
  if FColor <> Value then
  begin
    FColor := Value;
    Invalidate;
  end;
end;
{$ENDIF}

procedure TAdvChartCustomControl.Resize;
begin
  inherited;
  {$IFNDEF LCLLIB}
  UpdateControlAfterResize;
  {$ENDIF}
end;

procedure TAdvChartCustomControl.EnableStroke;
begin
  FStroke.Kind := gskSolid;
end;

procedure TAdvChartCustomControl.DisableFill;
begin
  FFill.Kind := gfkNone;
end;

procedure TAdvChartCustomControl.EnableFill;
begin
  FFill.Kind := gfkSolid;
end;

procedure TAdvChartCustomControl.Assign(Source: TPersistent);
begin
  if Source is TAdvChartCustomControl then
  begin
    FFill.Assign((Source as TAdvChartCustomControl).Fill);
    FStroke.Assign((Source as TAdvChartCustomControl).Stroke);
  end;
end;

constructor TAdvChartCustomControl.Create(AOwner: TComponent);
begin
  inherited;
  {$IFDEF NATIVEIOSDRAWING}
  FViewLocal := TAdvChartCustomViewEx.Create;
  FViewLocal.FView := Self;
  FView := UIView(FViewLocal.Super);
  {$ENDIF}
  {$IFDEF FMXLIB}
  FColor := gcWhite;
  CanFocus := True;
  ClipChildren := True;
  DisableFocusEffect := True;
  {$ENDIF}
  {$IFDEF CMNLIB}
  ParentColor := False;
  Color := gcWhite;
  {$ENDIF}
  TabStop := True;
  FFill := TAdvChartGraphicsFill.Create;
  FStroke := TAdvChartGraphicsStroke.Create;
  FFill.OnChanged := FillChanged;
  FStroke.OnChanged := StrokeChanged;
end;

destructor TAdvChartCustomControl.Destroy;
begin
  if Assigned(FDownBtn) then
  begin
    FDownBtn.Free;
    FDownBtn := nil;
  end;

  if Assigned(FNormalBtn) then
  begin
    FNormalBtn.Free;
    FNormalBtn := nil;
  end;

  if Assigned(FDownFocusBtn) then
  begin
    FDownFocusBtn.Free;
    FDownFocusBtn := nil;
  end;

  if Assigned(FNormalFocusBtn) then
  begin
    FNormalFocusBtn.Free;
    FNormalFocusBtn := nil;
  end;

  if Assigned(FNormalDisabledBtn) then
  begin
    FNormalDisabledBtn.Free;
    FNormalDisabledBtn := nil;
  end;

  if Assigned(FCheckedChk) then
  begin
    FCheckedChk.Free;
    FCheckedChk := nil;
  end;

  if Assigned(FCheckedFocusChk) then
  begin
    FCheckedFocusChk.Free;
    FCheckedFocusChk := nil;
  end;

  if Assigned(FUnCheckedDisabledChk) then
  begin
    FUnCheckedDisabledChk.Free;
    FUnCheckedDisabledChk := nil;
  end;

  if Assigned(FCheckedDisabledChk) then
  begin
    FCheckedDisabledChk.Free;
    FCheckedDisabledChk := nil;
  end;

  if Assigned(FUnCheckedChk) then
  begin
    FUnCheckedChk.Free;
    FUnCheckedChk := nil;
  end;

  if Assigned(FUnCheckedFocusChk) then
  begin
    FUnCheckedFocusChk.Free;
    FUnCheckedFocusChk := nil;
  end;

  if Assigned(FCheckedRd) then
  begin
    FCheckedRd.Free;
    FCheckedRd := nil;
  end;

  if Assigned(FCheckedFocusRd) then
  begin
    FCheckedFocusRd.Free;
    FCheckedFocusRd := nil;
  end;

  if Assigned(FUnCheckedRd) then
  begin
    FUnCheckedRd.Free;
    FUnCheckedRd := nil;
  end;

  if Assigned(FUnCheckedFocusRd) then
  begin
    FUnCheckedFocusRd.Free;
    FUnCheckedFocusRd := nil;
  end;

  if Assigned(FUnCheckedDisabledRd) then
  begin
    FUnCheckedDisabledRd.Free;
    FUnCheckedDisabledRd := nil;
  end;

  if Assigned(FCheckedDisabledRd) then
  begin
    FCheckedDisabledRd.Free;
    FCheckedDisabledRd := nil;
  end;

  FFill.Free;
  FStroke.Free;

  {$IFDEF NATIVEIOSDRAWING}
  if Assigned(FView) then
  begin
    FView.removeFromSuperview;
    FView.release;
    FView := nil;
  end;
  if Assigned(FViewLocal) then
  begin
    FViewLocal.Free;
    FViewLocal := nil;
  end;
  {$ENDIF}
  inherited;
end;

procedure TAdvChartCustomControl.SetFill(const Value: TAdvChartGraphicsFill);
begin
  FFill.Assign(Value);
end;

procedure TAdvChartCustomControl.SetStroke(const Value: TAdvChartGraphicsStroke);
begin
  FStroke.Assign(Value);
end;

procedure TAdvChartCustomControl.DoBeforeDraw(AGraphics: TAdvChartGraphics; ARect: TRectF; var ADefaultDraw: Boolean);
begin
  if Assigned(OnBeforeDraw) then
    OnBeforeDraw(Self, AGraphics, ARect, ADefaultDraw);
end;

procedure TAdvChartCustomControl.DoAfterDraw(AGraphics: TAdvChartGraphics; ARect: TRectF);
begin
  if Assigned(OnAfterDraw) then
    OnAfterDraw(Self, AGraphics, ARect);
end;

procedure TAdvChartCustomControl.DrawBackground(AGraphics: TAdvChartGraphics; ARect: TRectF);
begin
  AGraphics.Fill.Assign(Fill);
  AGraphics.Fill.Color := Color;
  AGraphics.Stroke.Assign(Stroke);
  AGraphics.DrawRectangle(ARect);
end;

{$IFDEF FMXMOBILE}
{$IFDEF FREEWARE}
procedure TAdvChartCustomControl.DrawTrial(AGraphics: TAdvChartGraphics; {%H-}ARect: TRectF);
var
  s: String;
begin
  if not (Parent is TAdvChartCustomControl) then
  begin
    InflateRectEx(ARect, -5, -5);
    AGraphics.Font.Color := gcRed;
    TAdvChartUtils.SetFontSize(AGraphics.Font, 10);
    s := ClassName + ' Trial ' + GetVersion;
    AGraphics.DrawText(ARect, s, False, gtaTrailing, gtaTrailing);
  end;
end;
{$ENDIF}
{$ENDIF}

procedure TAdvChartCustomControl.DrawControl;
var
  g: TAdvChartGraphics;
  r: TRectF;
  df: Boolean;
begin
  g := TAdvChartGraphics.Create(Canvas);
  try
    r := RectF(0, 0, Width, Height);
    df := True;
    DoBeforeDraw(g, r, df);
    if df then
    begin
      DrawBackground(g, r);
      Draw(g, r);
      DoAfterDraw(g, r);
    end;
    {$IFDEF FMXMOBILE}
    {$IFDEF FREEWARE}
    DrawTrial(g, r);
    {$ENDIF}
    {$ENDIF}
  finally
    g.Free;
  end;
end;

procedure TAdvChartCustomControl.Draw(AGraphics: TAdvChartGraphics; ARect: TRectF);
begin

end;

procedure TAdvChartCustomControl.Paint;
begin
  {$IFDEF NATIVEIOSDRAWING}
  if not FCreated then
  begin
    Initialize;
    FCreated := True;
  end;
  {$ENDIF}

  inherited;
  {$IFNDEF NATIVEIOSDRAWING}
  DrawControl;
  {$ENDIF}
end;

procedure TAdvChartCustomControl.StrokeChanged(Sender: TObject);
begin
  Invalidate;
end;

procedure TAdvChartCustomControl.FillChanged(Sender: TObject);
begin
  {$IFDEF FMXLIB}
  FColor := Fill.Color;
  {$ENDIF}
  {$IFDEF CMNLIB}
  if (Fill.Kind <> gfkNone) and (Fill.Color <> gcNull) then
    Color := Fill.Color
  else
    Color := clBtnFace;
  {$ENDIF}
  Invalidate;
end;

procedure TAdvChartCustomControl.UpdateControlAfterResize;
begin

end;

procedure TAdvChartCustomControl.CreateCheckBoxBitmaps;
var
{$IFDEF FMXLIB}
  chk: TCheckBox;
  f: TCommonCustomForm;
  fo: IControl;
{$ENDIF}
{$IFDEF CMNLIB}
  {$IFNDEF LCLLIB}
  rc: TRect;
  dChecked: Cardinal;
  hth: HTHEME;
  ThemeStyle: DWord;
  {$ENDIF}
  {$IFDEF LCLLIB}
  g: TAdvChartGraphics;
  {$ENDIF}
  bmp: TBitmap;
{$ENDIF}
begin
  if Assigned(FCheckedFocusChk) then
  begin
    FCheckedFocusChk.Free;
    FCheckedFocusChk := nil;
  end;

  if Assigned(FUnCheckedChk) then
  begin
    FUnCheckedChk.Free;
    FUnCheckedChk := nil;
  end;

  if Assigned(FCheckedChk) then
  begin
    FCheckedChk.Free;
    FCheckedChk := nil;
  end;

  if Assigned(FUnCheckedFocusChk) then
  begin
    FUnCheckedFocusChk.Free;
    FUnCheckedFocusChk := nil;
  end;

  if Assigned(FUnCheckedDisabledChk) then
  begin
    FUnCheckedDisabledChk.Free;
    FUnCheckedDisabledChk := nil;
  end;

  if Assigned(FCheckedDisabledChk) then
  begin
    FCheckedDisabledChk.Free;
    FCheckedDisabledChk := nil;
  end;

  {$IFDEF FMXLIB}
  chk := TCheckBox.Create(Self);
  chk.Width := chk.Height;
  chk.Text := '';
  chk.Parent := Self;
  chk.IsChecked := false;
  chk.NeedStyleLookup;
  chk.ApplyStyleLookup;

  {$IFDEF FMXMOBILE}
  chk.Width := 25;
  chk.Height := 25;
  {$ENDIF}

  TurnOffAnimation(chk);
  FUnCheckedChk := TAdvChartBitmap(chk.MakeScreenshot);
  chk.IsChecked := true;
  FCheckedChk := TAdvChartBitmap(chk.MakeScreenshot);
  chk.Enabled := False;
  chk.IsChecked := False;
  FUnCheckedDisabledChk := TAdvChartBitmap(chk.MakeScreenshot);
  chk.IsChecked := True;
  FCheckedDisabledChk := TAdvChartBitmap(chk.MakeScreenshot);
  chk.Enabled := True;

  f := TAdvChartUtils.GetParentForm(Self);
  fo := nil;
  if Assigned(f) then
    fo := f.Focused;

  chk.SetFocus;
  chk.IsChecked := false;
  FUnCheckedFocusChk := TAdvChartBitmap(chk.MakeScreenshot);
  chk.IsChecked := true;
  FCheckedFocusChk := TAdvChartBitmap(chk.MakeScreenshot);
  chk.Parent := nil;
  chk.Free;

  if Assigned(fo) then
    fo.SetFocus;
  {$ENDIF}

  {$IFDEF CMNLIB}
  bmp := TBitmap.Create;
  {$IFDEF VCLLIB}
  rc := Bounds(0, 0, 16, 16);
  {$ENDIF}
  {$IFDEF LCLLIB}
  g := TAdvChartGraphics.Create(bmp.Canvas);
  {$ENDIF}
  try
    bmp.PixelFormat := pf24bit;
    bmp.TransparentMode := tmFixed;
    bmp.Transparent := True;
    bmp.SetSize(16, 16);
    bmp.TransparentColor := gcWhite;

    FUnCheckedChk := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONCHECK;
    ThemeStyle := CBS_UNCHECKEDNORMAL;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_CHECKBOX, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawCheckBox(RectF(0, 0, bmp.Width, bmp.Height), False, False, True);
    {$ENDIF}

    FUnCheckedChk.Assign(bmp);

    FCheckedChk := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONCHECK or DFCS_CHECKED;
    ThemeStyle := CBS_CHECKEDNORMAL;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_CHECKBOX, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawCheckBox(RectF(0, 0, bmp.Width, bmp.Height), True, False, True);
    {$ENDIF}

    FCheckedChk.Assign(bmp);

    FUnCheckedFocusChk := TAdvChartBitmap.Create;
    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONCHECK or DFCS_HOT;
    ThemeStyle := CBS_UNCHECKEDHOT;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_CHECKBOX, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawCheckBox(RectF(0, 0, bmp.Width, bmp.Height), False, True, True);
    {$ENDIF}

    FUnCheckedFocusChk.Assign(bmp);

    FCheckedFocusChk := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONCHECK or DFCS_CHECKED or DFCS_HOT;
    ThemeStyle := CBS_CHECKEDHOT;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_CHECKBOX, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawCheckBox(RectF(0, 0, bmp.Width, bmp.Height), True, True, True);
    {$ENDIF}

    FCheckedFocusChk.Assign(bmp);

    FUnCheckedDisabledChk := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONCHECK or DFCS_INACTIVE;
    ThemeStyle := CBS_UNCHECKEDDISABLED;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_CHECKBOX, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawCheckBox(RectF(0, 0, bmp.Width, bmp.Height), False, False, False);
    {$ENDIF}

    FUnCheckedDisabledChk.Assign(bmp);

    FCheckedDisabledChk := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONCHECK or DFCS_CHECKED or DFCS_INACTIVE;
    ThemeStyle := CBS_CHECKEDDISABLED;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_CHECKBOX, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawCheckBox(RectF(0, 0, bmp.Width, bmp.Height), True, False, False);
    {$ENDIF}

    FCheckedDisabledChk.Assign(bmp);
  finally
    {$IFDEF LCLLIB}
    g.Free;
    {$ENDIF}
    bmp.Free;
  end;
  {$ENDIF}
end;

procedure TAdvChartCustomControl.CreateButtonBitmaps(AWidth, AHeight: Single);
var
{$IFDEF FMXLIB}
  btn: TButton;
  f: TCommonCustomForm;
  fo: IControl;
{$ENDIF}
{$IFDEF CMNLIB}
  {$IFNDEF LCLLIB}
  rc: TRect;
  dChecked: Cardinal;
  hth: HTHEME;
  ThemeStyle: DWord;
  {$ENDIF}
  {$IFDEF LCLLIB}
  g: TAdvChartGraphics;
  {$ENDIF}
  bmp: TBitmap;
{$ENDIF}
begin
  if Assigned(FDownBtn) then
  begin
    FDownBtn.Free;
    FDownBtn := nil;
  end;

  if Assigned(FNormalBtn) then
  begin
    FNormalBtn.Free;
    FNormalBtn := nil;
  end;

  if Assigned(FDownFocusBtn) then
  begin
    FDownFocusBtn.Free;
    FDownFocusBtn := nil;
  end;

  if Assigned(FNormalFocusBtn) then
  begin
    FNormalFocusBtn.Free;
    FNormalFocusBtn := nil;
  end;

  if Assigned(FNormalDisabledBtn) then
  begin
    FNormalDisabledBtn.Free;
    FNormalDisabledBtn := nil;
  end;

  {$IFDEF FMXLIB}
  btn := TButton.Create(Self);
  btn.Width := AWidth;
  btn.Height := AHeight;
  btn.Text := '';
  btn.Parent := Self;
  btn.StaysPressed := True;
  btn.IsPressed := False;
  btn.NeedStyleLookup;
  btn.ApplyStyleLookup;

  TurnOffAnimation(btn);
  FNormalBtn := TAdvChartBitmap(btn.MakeScreenshot);
  btn.IsPressed := true;
  FDownBtn := TAdvChartBitmap(btn.MakeScreenshot);
  btn.Enabled := False;
  btn.IsPressed := False;
  FNormalDisabledBtn := TAdvChartBitmap(btn.MakeScreenshot);
  btn.Enabled := True;

  f := TAdvChartUtils.GetParentForm(Self);
  fo := nil;
  if Assigned(f) then
    fo := f.Focused;

  btn.SetFocus;
  btn.IsPressed := false;
  FNormalFocusBtn := TAdvChartBitmap(btn.MakeScreenshot);
  btn.IsPressed := true;
  FDownFocusBtn := TAdvChartBitmap(btn.MakeScreenshot);
  btn.Parent := nil;
  btn.Free;

  if Assigned(fo) then
    fo.SetFocus;
  {$ENDIF}

  {$IFDEF CMNLIB}
  bmp := TBitmap.Create;
  {$IFDEF VCLLIB}
  rc := Bounds(0, 0, Round(AWidth), Round(AHeight));
  {$ENDIF}
  {$IFDEF LCLLIB}
  g := TAdvChartGraphics.Create(bmp.Canvas);
  {$ENDIF}
  try
    bmp.PixelFormat := pf24bit;
    bmp.TransparentMode := tmFixed;
    bmp.Transparent := True;
    bmp.SetSize(Round(AWidth), Round(AHeight));
    bmp.TransparentColor := gcWhite;

    FNormalBtn := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONPUSH;
    ThemeStyle := PBS_NORMAL;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_PUSHBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc, DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawButton(RectF(0, 0, bmp.Width, bmp.Height), False, False, True, AdaptToStyle);
    {$ENDIF}

    FNormalBtn.Assign(bmp);

    FDownBtn := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONPUSH or DFCS_PUSHED;
    ThemeStyle := PBS_PRESSED;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_PUSHBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc, DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawButton(RectF(0, 0, bmp.Width, bmp.Height), True, False, True, AdaptToStyle);
    {$ENDIF}

    FDownBtn.Assign(bmp);

    FNormalFocusBtn := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONPUSH or DFCS_HOT;
    ThemeStyle := PBS_HOT;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_PUSHBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc, DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawButton(RectF(0, 0, bmp.Width, bmp.Height), True, True, True, AdaptToStyle);
    {$ENDIF}

    FNormalFocusBtn.Assign(bmp);

    FDownFocusBtn := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONPUSH or DFCS_PUSHED or DFCS_HOT;
    ThemeStyle := PBS_HOT or PBS_PRESSED;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_PUSHBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc, DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawButton(RectF(0, 0, bmp.Width, bmp.Height), False, True, True, AdaptToStyle);
    {$ENDIF}

    FDownFocusBtn.Assign(bmp);

    FNormalDisabledBtn := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONPUSH or DFCS_INACTIVE;
    ThemeStyle := PBS_DISABLED;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_PUSHBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc, DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawButton(RectF(0, 0, bmp.Width, bmp.Height), False, False, False, AdaptToStyle);
    {$ENDIF}

    FNormalDisabledBtn.Assign(bmp);
  finally
    {$IFDEF LCLLIB}
    g.Free;
    {$ENDIF}
    bmp.Free;
  end;
  {$ENDIF}
end;

procedure TAdvChartCustomControl.CreateRadioButtonBitmaps;
var
{$IFDEF FMXLIB}
  Rd: TRadioButton;
  f: TCommonCustomForm;
  fo: IControl;
{$ENDIF}
{$IFDEF CMNLIB}
  {$IFNDEF LCLLIB}
  rc: TRect;
  dChecked: Cardinal;
  hth: HTHEME;
  ThemeStyle: DWord;
  {$ENDIF}
  {$IFDEF LCLLIB}
  g: TAdvChartGraphics;
  {$ENDIF}
  bmp: TBitmap;
{$ENDIF}
begin
  if Assigned(FCheckedFocusRd) then
  begin
    FCheckedFocusRd.Free;
    FCheckedFocusRd := nil;
  end;

  if Assigned(FUnCheckedRd) then
  begin
    FUnCheckedRd.Free;
    FUnCheckedRd := nil;
  end;

  if Assigned(FCheckedRd) then
  begin
    FCheckedRd.Free;
    FCheckedRd := nil;
  end;

  if Assigned(FUnCheckedFocusRd) then
  begin
    FUnCheckedFocusRd.Free;
    FUnCheckedFocusRd := nil;
  end;

  if Assigned(FUnCheckedDisabledRd) then
  begin
    FUnCheckedDisabledRd.Free;
    FUnCheckedDisabledRd := nil;
  end;

  if Assigned(FCheckedDisabledRd) then
  begin
    FCheckedDisabledRd.Free;
    FCheckedDisabledRd := nil;
  end;

  {$IFDEF FMXLIB}
  Rd := TRadioButton.Create(Self);
  Rd.Width := Rd.Height;
  Rd.Text := '';
  Rd.Parent := Self;
  Rd.IsChecked := false;
  Rd.NeedStyleLookup;
  Rd.ApplyStyleLookup;

  {$IFDEF FMXMOBILE}
  Rd.Width := 25;
  Rd.Height := 25;
  {$ENDIF}

  TurnOffAnimation(Rd);
  FUnCheckedRd := TAdvChartBitmap(Rd.MakeScreenshot);
  Rd.IsChecked := true;
  FCheckedRd := TAdvChartBitmap(Rd.MakeScreenshot);
  Rd.Enabled := False;
  Rd.IsChecked := False;
  FUnCheckedDisabledRd := TAdvChartBitmap(Rd.MakeScreenshot);
  Rd.IsChecked := true;
  FCheckedDisabledRd := TAdvChartBitmap(Rd.MakeScreenshot);
  Rd.Enabled := True;

  f := TAdvChartUtils.GetParentForm(Self);
  fo := nil;
  if Assigned(f) then
    fo := f.Focused;

  Rd.SetFocus;
  Rd.IsChecked := false;
  FUnCheckedFocusRd := TAdvChartBitmap(Rd.MakeScreenshot);
  Rd.IsChecked := true;
  FCheckedFocusRd := TAdvChartBitmap(Rd.MakeScreenshot);
  Rd.Parent := nil;
  Rd.Free;

  if Assigned(fo) then
    fo.SetFocus;
  {$ENDIF}

  {$IFDEF CMNLIB}
  bmp := TBitmap.Create;
  {$IFDEF VCLLIB}
  rc := Bounds(0, 0, 16, 16);
  {$ENDIF}
  {$IFDEF LCLLIB}
  g := TAdvChartGraphics.Create(bmp.Canvas);
  {$ENDIF}
  try
    bmp.PixelFormat := pf24bit;
    bmp.TransparentMode := tmFixed;
    bmp.Transparent := True;
    bmp.SetSize(16, 16);
    bmp.TransparentColor := gcWhite;
    FUnCheckedRd := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONRADIO;
    ThemeStyle := RBS_UNCHECKEDNORMAL;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_RADIOBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawRadioButton(RectF(0, 0, bmp.Width, bmp.Height), False, False, True);
    {$ENDIF}

    FUnCheckedRd.Assign(bmp);

    FCheckedRd := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONRADIO or DFCS_CHECKED;
    ThemeStyle := RBS_CHECKEDNORMAL;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_RADIOBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawRadioButton(RectF(0, 0, bmp.Width, bmp.Height), True, False, True);
    {$ENDIF}

    FCheckedRd.Assign(bmp);

    FUnCheckedFocusRd := TAdvChartBitmap.Create;
    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONRADIO or DFCS_HOT;
    ThemeStyle := RBS_UNCHECKEDHOT;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_RADIOBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawRadioButton(RectF(0, 0, bmp.Width, bmp.Height), False, True, True);
    {$ENDIF}

    FUnCheckedFocusRd.Assign(bmp);

    FCheckedFocusRd := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONRADIO or DFCS_CHECKED or DFCS_HOT;
    ThemeStyle := RBS_CHECKEDHOT;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_RADIOBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawRadioButton(RectF(0, 0, bmp.Width, bmp.Height), True, True, True);
    {$ENDIF}

    FCheckedFocusRd.Assign(bmp);

    FUnCheckedDisabledRd := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONRADIO or DFCS_INACTIVE;
    ThemeStyle := RBS_UNCHECKEDDISABLED;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_RADIOBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawRadioButton(RectF(0, 0, bmp.Width, bmp.Height), False, False, False);
    {$ENDIF}

    FUnCheckedDisabledRd.Assign(bmp);

    FCheckedDisabledRd := TAdvChartBitmap.Create;

    {$IFDEF VCLLIB}
    bmp.Canvas.Brush.Color := gcWhite;
    bmp.Canvas.Brush.Style := bsSolid;
    bmp.Canvas.FillRect(rc);

    DChecked := DFCS_BUTTONRADIO or DFCS_CHECKED or DFCS_INACTIVE;
    ThemeStyle := RBS_CHECKEDDISABLED;
    if IsThemeActive and not (csDesigning in ComponentState) then
    begin
      hth := OpenThemeData(Self.Handle,'button');
      DrawThemeBackground(hth, bmp.Canvas.Handle, BP_RADIOBUTTON, ThemeStyle,@rc,nil);
      CloseThemeData(hth);
    end
    else
      DrawFrameControl(bmp.Canvas.Handle,rc,DFC_BUTTON, DChecked);
    {$ENDIF}
    {$IFDEF LCLLIB}
    g.Fill.Kind := gfkSolid;
    g.Fill.Color := gcWhite;
    g.Stroke.Kind := gskSolid;
    g.Stroke.Color := gcWhite;
    g.DrawRectangle(RectF(0, 0, bmp.Width, bmp.Height));
    g.DrawRadioButton(RectF(0, 0, bmp.Width, bmp.Height), True, False, False);
    {$ENDIF}

    FCheckedDisabledRd.Assign(bmp);
  finally
    {$IFDEF LCLLIB}
    g.Free;
    {$ENDIF}
    bmp.Free;
  end;
  {$ENDIF}
end;

function TAdvChartCustomControl.GetButtonBitmap(AWidth, AHeight: Single; ADown: Boolean = False; AFocused: Boolean = False; AEnabled: Boolean = True): TAdvChartBitmap;
begin
  CreateButtonBitmaps(AWidth, AHeight);

  if ADown then
  begin
    if AEnabled then
    begin
      if AFocused then
        Result := FDownFocusBtn
      else
        Result := FDownBtn;
    end
    else
      Result := FNormalDisabledBtn;
  end
  else
  begin
    if AEnabled then
    begin
      if AFocused then
        Result := FNormalFocusBtn
      else
        Result := FNormalBtn;
    end
    else
      Result := FNormalDisabledBtn;
  end;
end;

function TAdvChartCustomControl.GetCheckBoxBitmap(AChecked: Boolean; AFocused: Boolean; AEnabled: Boolean): TAdvChartBitmap;
begin
  if (not Assigned(FCheckedChk) or not Assigned(FCheckedFocusChk) or not Assigned(FUnCheckedChk)
    or not Assigned(FUnCheckedFocusChk) or not Assigned(FCheckedDisabledChk) or not Assigned(FUnCheckedDisabledChk)) then
    CreateCheckBoxBitmaps;

  if AChecked then
  begin
    if AEnabled then
    begin
      if AFocused then
        Result := FCheckedFocusChk
      else
        Result := FCheckedChk;
    end
    else
      Result := FCheckedDisabledChk;
  end
  else
  begin
    if AEnabled then
    begin
      if AFocused then
        Result := FUnCheckedFocusChk
      else
        Result := FUnCheckedChk;
    end
    else
      Result := FUnCheckedDisabledChk;
  end;
end;

function TAdvChartCustomControl.GetRadioButtonBitmap(AChecked: Boolean; AFocused: Boolean; AEnabled: Boolean): TAdvChartBitmap;
begin
  if (not Assigned(FCheckedRd) or not Assigned(FCheckedFocusRd) or not Assigned(FUnCheckedRd)
    or not Assigned(FUnCheckedFocusRd) or not Assigned(FCheckedDisabledRd) or not Assigned(FUnCheckedDisabledRd)) then
    CreateRadioButtonBitmaps;

  if AChecked then
  begin
    if AEnabled then
    begin
      if AFocused then
        Result := FCheckedFocusRd
      else
        Result := FCheckedRd;
    end
    else
      Result := FCheckedDisabledRd;
  end
  else
  begin
    if AEnabled then
    begin
      if AFocused then
        Result := FUnCheckedFocusRd
      else
        Result := FUnCheckedRd;
    end
    else
      Result := FUnCheckedDisabledRd;
  end;
end;

function TAdvChartCustomControl.IsDesignTime: Boolean;
begin
  Result := (csDesigning in ComponentState) and not ((csReading in Owner.ComponentState) or (csLoading in Owner.ComponentState));
end;

function TAdvChartCustomControl.IsReading: Boolean;
begin
  Result := (csReading in Owner.ComponentState);
end;

function TAdvChartCustomControl.IsDesigning: Boolean;
begin
  Result := (csDesigning in ComponentState);
end;

function TAdvChartCustomControl.IsDestroying: Boolean;
begin
  Result := (csDestroying in ComponentState);
end;

function TAdvChartCustomControl.IsLoading: Boolean;
begin
  Result := (csLoading in Owner.ComponentState);
end;

procedure TAdvChartCustomControl.ResetToDefaultStyle;
begin
  inherited;
  Fill.Color := gcWhite;
  Stroke.Color := gcSilver;
end;

procedure TAdvChartCustomControl.&Export({%H-}AGraphics: TAdvChartGraphics; {%H-}ARect: TRectF);
begin
end;

procedure TAdvChartCustomControl.ApplyStyle;
var
  c: TAdvChartGraphicsColor;
begin
  inherited;
  c := gcNull;
  if TAdvChartStyles.GetStyleBackgroundFillColor(c) then
    Fill.Color := c;

  c := gcNull;
  if TAdvChartStyles.GetStyleLineFillColor(c) then
    Stroke.Color := c;
end;

procedure TAdvChartCustomControl.DestroyGraphicElements;
begin
  if Assigned(FDownBtn) then
  begin
    FDownBtn.Free;
    FDownBtn := nil;
  end;

  if Assigned(FNormalBtn) then
  begin
    FNormalBtn.Free;
    FNormalBtn := nil;
  end;

  if Assigned(FDownFocusBtn) then
  begin
    FDownFocusBtn.Free;
    FDownFocusBtn := nil;
  end;

  if Assigned(FNormalFocusBtn) then
  begin
    FNormalFocusBtn.Free;
    FNormalFocusBtn := nil;
  end;

  if Assigned(FNormalDisabledBtn) then
  begin
    FNormalDisabledBtn.Free;
    FNormalDisabledBtn := nil;
  end;

  if Assigned(FCheckedChk) then
  begin
    FCheckedChk.Free;
    FCheckedChk := nil;
  end;

  if Assigned(FCheckedFocusChk) then
  begin
    FCheckedFocusChk.Free;
    FCheckedFocusChk := nil;
  end;

  if Assigned(FUnCheckedDisabledChk) then
  begin
    FUnCheckedDisabledChk.Free;
    FUnCheckedDisabledChk := nil;
  end;

  if Assigned(FCheckedDisabledChk) then
  begin
    FCheckedDisabledChk.Free;
    FCheckedDisabledChk := nil;
  end;

  if Assigned(FUnCheckedChk) then
  begin
    FUnCheckedChk.Free;
    FUnCheckedChk := nil;
  end;

  if Assigned(FUnCheckedFocusChk) then
  begin
    FUnCheckedFocusChk.Free;
    FUnCheckedFocusChk := nil;
  end;

  if Assigned(FCheckedRd) then
  begin
    FCheckedRd.Free;
    FCheckedRd := nil;
  end;

  if Assigned(FCheckedFocusRd) then
  begin
    FCheckedFocusRd.Free;
    FCheckedFocusRd := nil;
  end;

  if Assigned(FUnCheckedRd) then
  begin
    FUnCheckedRd.Free;
    FUnCheckedRd := nil;
  end;

  if Assigned(FUnCheckedFocusRd) then
  begin
    FUnCheckedFocusRd.Free;
    FUnCheckedFocusRd := nil;
  end;

  if Assigned(FUnCheckedDisabledRd) then
  begin
    FUnCheckedDisabledRd.Free;
    FUnCheckedDisabledRd := nil;
  end;

  if Assigned(FCheckedDisabledRd) then
  begin
    FCheckedDisabledRd.Free;
    FCheckedDisabledRd := nil;
  end;
end;

function TAdvChartCustomControl.GetControlRect: TRectF;
begin
  Result := RectF(0, 0, Width, Height);
end;

function TAdvChartCustomControl.GetContentRect: TRectF;
begin
  Result := GetControlRect;
end;

function TAdvChartCustomControl.GetVersion: String;
begin
  Result := '';
end;

function TAdvChartCustomControl.LocalToScreenEx(APoint: TPointF): TPointF;
{$IFDEF CMNLIB}
var
  pt: TPoint;
{$ENDIF}
begin
  {$IFDEF FMXLIB}
  Result := LocalToScreen(APoint);
  {$ENDIF}
  {$IFDEF CMNLIB}
  pt := ClientToScreen(Point(Round(APoint.X), Round(APoint.Y)));
  Result := PointF(pt.X, pt.Y);
  {$ENDIF}
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomControl.TurnOffAnimation(chk: TFmxObject);
var
  I: Integer;
begin
  if Assigned(chk) then
  begin
    if chk is TAnimation then
      (chk as TAnimation).Duration := 0;

    for I := 0 to chk.ChildrenCount - 1 do
    begin
      TurnOffAnimation(chk.Children[I]);
    end;
  end;
end;
{$ENDIF}

procedure TAdvChartCustomControl.CaptureEx;
begin
  {$IFDEF FMXLIB}
  Capture;
  {$ENDIF}
  {$IFDEF VCLLIB}
  SetCapture(Self.Handle);
  {$ENDIF}
  {$IFDEF LCLLIB}
  MouseCapture := True;
  {$ENDIF}
end;

procedure TAdvChartCustomControl.ReleaseCaptureEx;
begin
  {$IFNDEF LCLLIB}
  ReleaseCapture;
  {$ENDIF}
  {$IFDEF LCLLIB}
  MouseCapture := False;
  {$ENDIF}
end;

procedure TAdvChartCustomControlBaseCommon.BeginDrag;
{$IFDEF FMXLIB}
{$HINTS OFF}
{$IF COMPILERVERSION > 27}
var
  Svc: IFMXDragDropService;
  DragData: TDragObject;
  DragImage: TAdvChartBitmap;
begin
  if TPlatformServices.Current.SupportsPlatformService(IFMXDragDropService, Svc) then
  begin
    DragData.Source := Self;
    DragImage := TAdvChartBitmap.Create;
    DragImage.Width := 1;
    DragImage.Height := 1;
    try
      DragData.Data := DragImage;
      Svc.BeginDragDrop(TAdvChartUtils.GetParentForm(Self), DragData, DragImage);
    finally
      DragImage.Free;
    end;
  end;
{$IFEND}
{$IF COMPILERVERSION <= 27}
begin
{$IFEND}
{$HINTS ON}
{$ENDIF}
{$IFDEF CMNLIB}
begin
  inherited BeginDrag(True);
{$ENDIF}
end;

{$IFDEF FMXLIB}
procedure TAdvChartCustomControlBaseCommon.CancelHint;
begin
  {$WARNINGS OFF}
  {$HINTS OFF}
  {$IF COMPILERVERSION > 29}
  Application.CancelHint;
  {$IFEND}
  {$HINTS ON}
  {$WARNINGS ON}
end;
{$ENDIF}

function TAdvChartCustomControlBaseCommon.GetDragObjectScreenShot: TAdvChartBitmap;
begin
  Result := nil;
end;

{$IFDEF CMNLIB}
procedure TAdvChartCustomControlBaseCommon.CancelHint;
begin
  Application.CancelHint;
end;

function TAdvChartCustomControlBase.GetHintString: string;
begin
  Result := '';
end;

function TAdvChartCustomControlBase.HasHint: Boolean;
begin
  Result := False;
end;
{$ENDIF}

{$IFDEF NATIVEIOSDRAWING}
procedure TAdvChartCustomControl.SetBounds(X, Y, AWidth, AHeight: Single);
begin
  inherited;
  UpdateFrame;
end;

procedure TAdvChartCustomControl.Invalidate;
begin
  inherited Invalidate;
  if Assigned(FView) then
    FView.setNeedsDisplay;
end;

procedure TAdvChartCustomControl.SetEnabled(const Value: Boolean);
var
  vw: UIView;
begin
  inherited;
  vw := FView;
  if Assigned(vw) then
    vw.setUserInteractionEnabled(Enabled);
end;

procedure TAdvChartCustomControl.SetParent(const Value: TFmxObject);
begin
  inherited;
  Initialize;
end;

procedure TAdvChartCustomControl.SetVisible(const Value: Boolean);
var
  vw: UIView;
begin
  inherited;
  vw := FView;
  if Assigned(vw) then
    vw.setHidden(not Visible);
end;

procedure TAdvChartCustomControl.Initialize;
var
  pr: UIView;
begin
  pr := GetRootView(Self);
  if Assigned(pr) then
    AddSubView(pr);

  UpdateFrame;
end;

function TAdvChartCustomControl.GetRootView(AControl: TFMXObject): UIView;
var
  app: UIApplication;
  wn: UIWindow;
  rv: UIViewController;
  h: TiOSWindowHandle;
  function GetSharedApplication: UIApplication;
  begin
    Result := TUIApplication.Wrap(TUIApplication.OCClass.sharedApplication);
  end;

begin
  Result := nil;
  if not Assigned(AControl) then
    Exit;

  if (AControl.Parent is TFrame) then
  begin
    app := GetSharedApplication;
    if Assigned(app) then
    begin
      wn := app.keyWindow;
      if Assigned(wn) then
      begin
        rv := wn.rootViewController;
        if Assigned(rv) then
          Result := rv.view;
      end;
    end;
  end
  else if (AControl.Parent is TCommonCustomForm) then
  begin
    h := WindowHandleToPlatform((AControl.Parent as TCommonCustomForm).Handle);
    Result := h.View;
  end
  else if Assigned(Parent) and (Parent is TAdvChartCustomControl) then
    Result := GetRootView(AControl.Parent);
end;

procedure TAdvChartCustomControl.UpdateFrame;
{$IFDEF IOS}
var
  frmr: CGRect;
  pos: TPointF;
  r: TRectF;
{$ENDIF}
begin
  {$IFDEF IOS}
  if (Parent is TFrame) then
  begin
    frmr.origin.x := (Parent as TFrame).Position.X + Self.Position.X;
    frmr.origin.y := (Parent as TFrame).Position.Y + Self.Position.Y;
  end
  else
  begin
    pos := Self.Position.Point;
    if Assigned(Parent) and not (Parent is TCommonCustomForm) then
      if not (Parent is TAdvChartCustomControl) then
        pos := GetRealPos(pos, Self);

    frmr.origin.x := pos.X;
    frmr.origin.y := pos.Y;
  end;

  r := GetContentRect;
  frmr.size.width := r.Width;
  frmr.size.height := r.Height;
  SetViewFrame(frmr);
  {$ENDIF}
end;

function TAdvChartCustomControl.GetRealPos(APos: TPointF; AControl: TControl): TPointF;
begin
  Result := APos;
  if not Assigned(AControl) then
    Exit;

  if Assigned(AControl.Parent) and (AControl.Parent is TControl) then
  begin
    Result.X := Result.X + (AControl.Parent as TControl).Position.X;
    Result.Y := Result.Y + (AControl.Parent as TControl).Position.Y;
    Result := GetRealPos(Result, (AControl.Parent as TControl));
  end;
end;

procedure TAdvChartCustomControl.AddSubView(AParentView: UIView);
var
  vw: UIView;
begin
  vw := FView;
  if Assigned(vw) and Assigned(AParentView) then
    AParentView.addSubview(vw);
end;

procedure TAdvChartCustomControl.SetViewFrame(ARect: CGRect);
var
  vw: UIView;
begin
  vw := FView;
  if Assigned(vw) then
    vw.setFrame(ARect);
end;

constructor TAdvChartCustomViewEx.Create;
var
  V: Pointer;
begin
  inherited Create;
  V := UIView(Super).init;
  if V <> GetObjectID then
    UpdateObjectID(V);
end;

procedure TAdvChartCustomViewEx.drawRect(R: CGRect);
begin
  if Assigned(FView) then
    FView.DrawControl;
end;

function TAdvChartCustomViewEx.GetObjectiveCClass: PTypeInfo;
begin
  Result := TypeInfo(AdvChartCustomViewEx);
end;

procedure TAdvChartCustomViewEx.touchesBegan(touches: NSSet; withEvent: UIEvent);
var
  X, Y : single;
  Touch: UITouch;
begin
  try
    if not Assigned(FView) then
      Exit;

    if not GetTouchCoord(touches, FView.FView, X, Y) then
      Exit;

    try
      FTap := True;
      FView.HandleMouseDown(TMouseButton.mbLeft, [ssLeft, ssTouch], X, Y);
      Touch := TUITouch.Wrap(touches.anyObject);
      if Touch.tapCount = 2 then
        iOSapi.Foundation.TNSObject.OCClass.cancelPreviousPerformRequestsWithTarget(Self.GetObjectID);
    finally
      UIView(Super).touchesBegan(touches, withEvent);
    end;
  except
  end;
end;

procedure TAdvChartCustomViewEx.touchesCancelled(touches: NSSet; withEvent: UIEvent);
var
  X, Y : single;
begin
  try
    if not Assigned(FView) then
      Exit;

    if not GetTouchCoord(touches, FView.FView, X, Y) then
      Exit;

    try
      FView.HandleMouseUp(TMouseButton.mbLeft, [ssLeft, ssTouch], X, Y);
    finally
      UIView(Super).touchesCancelled(touches, withEvent);
    end;
  except
  end;
end;

procedure TAdvChartCustomViewEx.touchesEnded(touches: NSSet; withEvent: UIEvent);
var
  X, Y : single;
  Touch: UITouch;
begin
  try
    if not Assigned(FView) then
      Exit;

    if not GetTouchCoord(touches, FView.FView, X, Y) then
      Exit;

    try
      FView.HandleMouseUp(TMouseButton.mbLeft, [ssLeft, ssTouch], X, Y);
      Touch := TUITouch.Wrap(touches.anyObject);
      if FTap then
      begin
        if Touch.tapCount = 2 then
          FView.HandleDblClick(X, Y)
      end;
    finally
      UIView(Super).touchesEnded(touches, withEvent);
    end;
  except
  end;
end;

procedure TAdvChartCustomViewEx.touchesMoved(touches: NSSet; withEvent: UIEvent);
var
  X, Y : single;
begin
  try
    if not Assigned(FView) then
      Exit;

    if not GetTouchCoord(touches, FView.FView, X, Y) then
      Exit;

    try
      FTap := False;
      FView.HandleMouseMove([ssLeft, ssTouch], X, Y);
    finally
      UIView(Super).touchesMoved(touches, withEvent);
    end;
  except
  end;
end;

function TAdvChartCustomViewEx.GetTouchCoord(const touches: NSSet; const Window: UIView; var x, y: single): Boolean;
var
  touch : UITouch;
  p     : CGPoint;
begin
  Result := False;
  if (touches <> nil) and (touches.count = 1) then
  begin
    touch := TUITouch.Wrap(touches.anyObject);
    p := touch.locationInView(FView.FView);
    x := p.x;
    y := p.y;
    Result := True;
  end;
end;

{$ENDIF}

{$IFNDEF FMXMOBILE}
{$IFDEF FREEWARE}
{$I TMSProductTrial.inc}
{$ENDIF}
{$ENDIF}

end.

