{********************************************************************}
{                                                                    }
{           Developer Express Visual Component Library               }
{                    ExpressSkins Library                            }
{                                                                    }
{           Copyright (c) 2006-2014 Developer Express Inc.           }
{                     ALL RIGHTS RESERVED                            }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSSKINS AND ALL ACCOMPANYING     }
{   VCL CONTROLS AS PART OF AN EXECUTABLE PROGRAM ONLY.              }
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

unit dxSkinsForm;

interface

{$I cxVer.inc}

uses
  Types, Windows, Classes, SysUtils, Messages, Forms, Graphics, Controls, MultiMon, ShellApi, StdCtrls, ExtCtrls,
  cxLookAndFeelPainters, cxClasses, cxDWMAPI, dxCore, dxCoreClasses, dxMessages, cxGraphics, cxControls, cxGeometry,
  cxContainer, dxSkinsLookAndFeelPainter, dxSkinsCore, cxScrollBar, cxLookAndFeels, dxUxTheme, dxSkinInfo;

const
  dxSkinFormTextOffset = 5;
  dxSkinIconSpacing = 2;
  IsDesigning: Boolean = False;

type
  TdxSkinCustomFormController = class;
  TdxSkinForm = class;
  TdxSkinFormController = class;
  TdxSkinFormIconInfo = class;
  TdxSkinFormIconInfoList = class;
  TdxSkinFormNonClientAreaInfo = class;
  TdxSkinFormPainter = class;
  TdxSkinFormScrollBarsController = class;
  TdxSkinFormScrollBarViewInfo = class;

  { TdxSkinWinController }

  TdxSkinWinControllerClass = class of TdxSkinWinController;
  TdxSkinWinController = class(TcxIUnknownObject, IcxMouseTrackingCaller)
  private
    FCanUseSkin: Boolean;
    FHandle: HWND;
    FLookAndFeelPainter: TdxSkinLookAndFeelPainter;
    FMaster: TdxSkinWinController;
    FWinControl: TWinControl;
    FWindowProcObject: TcxWindowProcLinkedObject;
    function GetHasGraphicChildren: Boolean;
    function GetIsHooked: Boolean;
    function GetLookAndFeelPainter: TdxSkinLookAndFeelPainter;
    procedure SetHandle(AHandle: HWND);
  protected
    function CanFinalizeEngine: Boolean; virtual;
    function FindLookAndFeelPainter: TdxSkinLookAndFeelPainter; virtual;
    function FindMasterController: TdxSkinWinController; virtual;
    function GetCanUseSkin: Boolean; virtual;
    function GetUseSkin: Boolean; virtual;
    function IsHookAvailable: Boolean; virtual;
    procedure DefWndProc(var AMessage); virtual;
    procedure MasterDestroyed; virtual;
    procedure RedrawWindow(AUpdateNow: Boolean);
    procedure WndProc(var AMessage: TMessage); virtual;

    procedure HookWndProc; virtual;
    procedure UnHookWndProc; virtual;
    // IcxMouseTrackingCaller
    procedure MouseLeave; virtual;
  public
    constructor Create(AHandle: HWND); virtual;
    destructor Destroy; override;

    class function IsMDIChildWindow(AHandle: HWND): Boolean; virtual;
    class function IsMDIClientWindow(AHandle: HWND): Boolean; virtual;
    class function IsMessageDlgWindow(AHandle: HWND): Boolean; virtual;
    class function IsSkinActive(AHandle: HWND): Boolean;
    class procedure FinalizeEngine(AHandle: HWND);
    class procedure InitializeEngine(AHandle: HWND);

    procedure InvalidateNC; virtual;
    procedure Refresh; virtual;
    procedure RefreshController; virtual;
    procedure RefreshControllerAndUpdate;
    procedure Update; virtual;

    property Handle: HWND read FHandle write SetHandle;
    property HasGraphicChildren: Boolean read GetHasGraphicChildren;
    property IsHooked: Boolean read GetIsHooked;
    property LookAndFeelPainter: TdxSkinLookAndFeelPainter read GetLookAndFeelPainter;
    property Master: TdxSkinWinController read FMaster;
    property UseSkin: Boolean read GetUseSkin;
    property WinControl: TWinControl read FWinControl;
  end;

  { TdxSkinWinControllerList }

  TdxSkinWinControllerList = class(TcxObjectList)
  private
    function GetItem(Index: Integer): TdxSkinWinController;
  public
    function GetControllerByControl(AControl: TWinControl): TdxSkinWinController;
    function GetControllerByHandle(AHandle: HWND): TdxSkinWinController;
    procedure Refresh;
    //
    property Items[Index: Integer]: TdxSkinWinController read GetItem; default;
  end;

  { TdxSkinCustomFormController }

  TdxSkinFormCorner = (sfcLeftTop, sfcRightTop, sfcLeftBottom, sfcRightBottom);
  TdxSkinFormScrollBar = (saeHorzScroll, saeVertScroll);

  TdxSkinCustomFormController = class(TdxSkinWinController)
  private
    FForceRedraw: Boolean;
    FHasRegion: Boolean;
    FLockRedrawCount: Integer;
    FPainter: TdxSkinFormPainter;
    FScrollBarsController: TdxSkinFormScrollBarsController;
    FSkinForm: TdxSkinForm;
    FViewInfo: TdxSkinFormNonClientAreaInfo;
    function GetForm: TCustomForm;
    function GetIconsInfo: TdxSkinFormIconInfoList;
  protected
    function GetUseSkin: Boolean; override;
    function IsHookAvailable: Boolean; override;
    procedure CalculateViewInfo; virtual;
    procedure CheckWindowRgn; virtual;
    procedure DrawWindowBackground(DC: HDC); virtual;
    procedure DrawWindowBorder(DC: HDC = 0); virtual;
    procedure DrawWindowScrollArea(DC: HDC = 0); virtual;
    procedure FlushWindowRgn(ARedraw: Boolean = True); virtual;
    procedure InitializeMessageForm; virtual;
    procedure InvalidateBorders;
    function HandleInternalMessages(var AMessage: TMessage): Boolean; virtual;
    function HandleWindowMessage(var AMessage: TMessage): Boolean; virtual;
    function RefreshOnMouseEvent(AForceRefresh: Boolean = False): Boolean;
    procedure MouseLeave; override;
    procedure RefreshOnSystemMenuShown;
    procedure UnHookWndProc; override;
    procedure UpdateViewInfoState;
    //
    procedure AfterWndProc(var AMessage: TMessage);
    procedure BeforeWndProc(var AMessage: TMessage);
    procedure DefWndProc(var AMessage); override;
    //
    function NCMouseDown(const P: TPoint): Boolean; virtual;
    function NCMouseUp(const P: TPoint): Boolean; virtual;
    // Redraw
    procedure LockRedraw;
    procedure PostRedraw;
    procedure UnlockRedraw;
    // Menu
    procedure DoPopupSystemMenu(AForm: TCustomForm; ASysMenu: HMENU);
    procedure ShowSystemMenu(const P: TPoint); overload;
    procedure ShowSystemMenu(const P: TPoint; const AExcludeRect: TRect; ABottomAlign: Boolean = False); overload;
    procedure ShowSystemMenu; overload;
    //
    procedure WMActivate(var Message: TMessage); virtual;
    function WMContextMenu(var Message: TWMContextMenu): Boolean; virtual;
    procedure WMEraseBkgnd(var Message: TWMEraseBkgnd); virtual;
    procedure WMInitMenu(var Message: TWMInitMenu); virtual;
    procedure WMNCActivate(var Message: TWMNCActivate); virtual;
    procedure WMNCButtonDown(var Message: TWMNCHitMessage); virtual;
    procedure WMNCCalcSize(var Message: TWMNCCALCSIZE); virtual;
    function WMNCHitTest(var Message: TWMNCHitTest): Boolean; virtual;
    procedure WMNCMouseMove(var Message: TWMNCHitMessage);
    procedure WMNCPaint(var Message: TWMNCPaint); virtual;
    procedure WMPaint(var Message: TWMPaint); virtual;
    procedure WMPrint(var Message: TWMPrint); virtual;
    procedure WMSetText(var Message: TWMSetText); virtual;
    procedure WMSize(var Message: TWMSize); virtual;
    procedure WMSysCommand(var Message: TWMSysCommand); virtual;
    procedure WMSysMenu(var Message: TMessage); virtual;
    procedure WMWindowPosChanged(var Message: TWMWindowPosChanged); virtual;
    procedure WndProc(var AMessage: TMessage); override;
  public
    constructor Create(AHandle: HWND); override;
    constructor CreateEx(ASkinForm: TdxSkinForm);
    destructor Destroy; override;
    procedure Refresh; override;
    procedure RefreshController; override;

    property ForceRedraw: Boolean read FForceRedraw write FForceRedraw;
    property Form: TCustomForm read GetForm;
    property HasRegion: Boolean read FHasRegion write FHasRegion;
    property IconsInfo: TdxSkinFormIconInfoList read GetIconsInfo;
    property Painter: TdxSkinFormPainter read FPainter;
    property ScrollBarsController: TdxSkinFormScrollBarsController read FScrollBarsController;
    property SkinForm: TdxSkinForm read FSkinForm;
    property ViewInfo: TdxSkinFormNonClientAreaInfo read FViewInfo;
  end;

  { TdxSkinFormIconInfo }

  TdxSkinFormIconInfo = class(TObject)
  private
    FBounds: TRect;
    FHitBounds: TRect;
    FIconType: TdxSkinFormIcon;
    FOwner: TdxSkinFormIconInfoList;
    FState: TdxSkinElementState;
    function GetCommand: Integer;
    function GetEnabled: Boolean;
    function GetHitTest: Integer;
    function GetNonClientAreaInfo: TdxSkinFormNonClientAreaInfo;
  public
    constructor Create(AType: TdxSkinFormIcon; AOwner: TdxSkinFormIconInfoList); virtual;
    function CalculateState: TdxSkinElementState;
    //
    property Bounds: TRect read FBounds write FBounds;
    property Command: Integer read GetCommand;
    property Enabled: Boolean read GetEnabled;
    property HitBounds: TRect read FHitBounds write FHitBounds;
    property HitTest: Integer read GetHitTest;
    property IconType: TdxSkinFormIcon read FIconType;
    property NonClientAreaInfo: TdxSkinFormNonClientAreaInfo read GetNonClientAreaInfo;
    property Owner: TdxSkinFormIconInfoList read FOwner;
    property State: TdxSkinElementState read FState write FState;
  end;

  { TdxSkinFormIconInfoList }

  TdxSkinFormIconInfoList = class(TcxObjectList)
  private
    FIconHot: TdxSkinFormIconInfo;
    FIconPressed: TdxSkinFormIconInfo;
    FNonClientAreaInfo: TdxSkinFormNonClientAreaInfo;
    function GetItem(Index: Integer): TdxSkinFormIconInfo;
  public
    constructor Create(ANonClientInfo: TdxSkinFormNonClientAreaInfo); virtual;
    function Add(AIcon: TdxSkinFormIcon): TdxSkinFormIconInfo;
    function CalculateStates(const P: TPoint): Boolean;
    function Find(AIcon: TdxSkinFormIcon; out AInfo: TdxSkinFormIconInfo): Boolean;
    function HitTest(const P: TPoint): TdxSkinFormIconInfo; overload;
    function HitTest(const P: TPoint; out AInfo: TdxSkinFormIconInfo): Boolean; overload;
    procedure MouseDown(const P: TPoint);
    procedure MouseUp(const P: TPoint; out AIcon: TdxSkinFormIconInfo);
    procedure Validate(const AIcons: TdxSkinFormIcons);
    //
    property IconHot: TdxSkinFormIconInfo read FIconHot;
    property IconPressed: TdxSkinFormIconInfo read FIconPressed;
    property Items[Index: Integer]: TdxSkinFormIconInfo read GetItem; default;
    property NonClientAreaInfo: TdxSkinFormNonClientAreaInfo read FNonClientAreaInfo;
  end;

  { TdxSkinFormScrollBarPartViewInfo }

  TdxSkinFormScrollBarPartViewInfo = class(TObject)
  private
    FBounds: TRect;
    FKind: TcxScrollBarPart;
    FOwner: TdxSkinFormScrollBarViewInfo;
    FState: TcxButtonState;
    FVisible: Boolean;
  public
    constructor Create(AOwner: TdxSkinFormScrollBarViewInfo; AKind: TcxScrollBarPart); virtual;
    procedure Calculate(APos1, APos2: Integer; AState: Integer);
    //
    property Bounds: TRect read FBounds;
    property Kind: TcxScrollBarPart read FKind;
    property Owner: TdxSkinFormScrollBarViewInfo read FOwner;
    property State: TcxButtonState read FState;
    property Visible: Boolean read FVisible;
  end;

  { TdxSkinFormScrollBarViewInfo }

  TdxSkinFormScrollBarViewInfo = class(TObject)
  private
    FBounds: TRect;
    FController: TdxSkinFormScrollBarsController;
    FInfo: TScrollBarInfo;
    FKind: TdxSkinFormScrollBar;
    FParts: array[TcxScrollBarPart] of TdxSkinFormScrollBarPartViewInfo;
    FVisible: Boolean;
    function GetPartViewInfo(APart: TcxScrollBarPart): TdxSkinFormScrollBarPartViewInfo;
  public
    constructor Create(AKind: TdxSkinFormScrollBar; AController: TdxSkinFormScrollBarsController);
    destructor Destroy; override;
    procedure CalculatePart(APos1, APos2: Integer; APart: TcxScrollBarPart);
    procedure CalculateParts;
    function HitTest(const P: TPoint; out APart: TdxSkinFormScrollBarPartViewInfo): Boolean;
    //
    property Bounds: TRect read FBounds;
    property Controller: TdxSkinFormScrollBarsController read FController;
    property Info: TScrollBarInfo read FInfo;
    property Kind: TdxSkinFormScrollBar read FKind;
    property PartViewInfo[APart: TcxScrollBarPart]: TdxSkinFormScrollBarPartViewInfo read GetPartViewInfo;
    property Visible: Boolean read FVisible;
  end;

  { TdxSkinFormScrollBarsController }

  TdxSkinFormScrollBarsController = class(TObject)
  private
    FController: TdxSkinCustomFormController;
    FHotPart: TdxSkinFormScrollBarPartViewInfo;
    FIsTracking: Boolean;
    FPressedPart: TdxSkinFormScrollBarPartViewInfo;
    FScrollBarViewInfo: array[TdxSkinFormScrollBar] of TdxSkinFormScrollBarViewInfo;
    FScrolling: Boolean;
    FScrollTimer: TcxTimer;
    FSizeGripBounds: TRect;
    FTrackingAreaInfo: TScrollInfo;
    FTrackingLastPoint: TPoint;
    FTrackingScale: Single;
    FTrackPosition: Single;
    function CanScrollPage: Boolean;
    function GetScrollBarViewInfo(AScrollBar: TdxSkinFormScrollBar): TdxSkinFormScrollBarViewInfo;
    function GetSizeGripVisible: Boolean;
    function GetTrackingScrollBarKind: TdxSkinFormScrollBar;
    function GetViewInfo: TdxSkinFormNonClientAreaInfo;
    procedure SetHotPart(AValue: TdxSkinFormScrollBarPartViewInfo);
    procedure SetPressedPart(AValue: TdxSkinFormScrollBarPartViewInfo);
  protected
    procedure Click; virtual;
    procedure ScrollTimer(Sender: TObject);
    procedure SendScrollMessage(AParam: WPARAM);
    procedure StartScrollTimer;
    procedure StopScrollTimer;
    procedure Tracking(const P: TPoint);
    procedure TrackingBegin(const P: TPoint);
    procedure TrackingEnd(const P: TPoint);
    procedure TrackingSetThumbPosition(APosition: Integer);
    //
    property HotPart: TdxSkinFormScrollBarPartViewInfo read FHotPart write SetHotPart;
    property IsTracking: Boolean read FIsTracking;
    property PressedPart: TdxSkinFormScrollBarPartViewInfo read FPressedPart write SetPressedPart;
    property Scrolling: Boolean read FScrolling;
    property TrackingAreaInfo: TScrollInfo read FTrackingAreaInfo;
    property TrackingScale: Single read FTrackingScale;
    property TrackingScrollBarKind: TdxSkinFormScrollBar read GetTrackingScrollBarKind;
  public
    constructor Create(AController: TdxSkinCustomFormController); virtual;
    destructor Destroy; override;
    function HitTest(const P: TPoint): TdxSkinFormScrollBarPartViewInfo; overload;
    function HitTest(const P: TPoint; out AScrollBarPart: TdxSkinFormScrollBarPartViewInfo): Boolean; overload;
    procedure CalculateDrawRegion(ARegion: HRGN);
    procedure CalculateScrollArea; virtual;
    procedure MouseDown(const P: TPoint);
    procedure MouseMove(const P: TPoint);
    procedure MouseUp(const P: TPoint);
    //
    property Controller: TdxSkinCustomFormController read FController;
    property ScrollBarViewInfo[AScrollBar: TdxSkinFormScrollBar]: TdxSkinFormScrollBarViewInfo read GetScrollBarViewInfo;
    property SizeGripBounds: TRect read FSizeGripBounds;
    property SizeGripVisible: Boolean read GetSizeGripVisible;
    property ViewInfo: TdxSkinFormNonClientAreaInfo read GetViewInfo;
  end;

  { TdxSkinFormNonClientAreaInfo }

  TdxSkinFormNonClientAreaInfo = class(TObject)
  private
    FClientOffset: Integer;
    FClientRect: TRect;
    FController: TdxSkinCustomFormController;
    FExStyle: Integer;
    FIconInfoList: TdxSkinFormIconInfoList;
    FSizeType: Integer;
    FStyle: Integer;
    FSupressed: Boolean;
    FSystemMenu: HMENU;
    FThemeActive: Boolean;
    FThemeActiveAssigned: Boolean;
    FWindowRect: TRect;
    function GetBorderBounds(ASide: TcxBorder): TRect;
    function GetButtonPressed: Boolean;
    function GetCaptionBounds: TRect;
    function GetCaptionContentOffset: TRect;
    function GetCaptionElement: TdxSkinElement;
    function GetCaptionIconSize(AIcon: TdxSkinFormIcon): TSize;
    function GetCaptionTextAreaOffset: TRect;
    function GetCaptionTextColor: TColor;
    function GetClientCursorPos: TPoint;
    function GetClientRectOnClient: TRect;
    function GetContentRect: TRect;
    function GetHandle: HWND;
    function GetHasBorder: Boolean;
    function GetHasCaption: Boolean;
    function GetHasCaptionTextShadow: Boolean;
    function GetHasClientEdge: Boolean;
    function GetHasMenu: Boolean;
    function GetHasParent: Boolean;
    function GetHasScrollsArea: Boolean;
    function GetHasSizeConstraints: Boolean;
    function GetIsAlphaBlendUsed: Boolean;
    function GetIsChild: Boolean;
    function GetIsDialog: Boolean;
    function GetIsIconic: Boolean;
    function GetIsSizeBox: Boolean;
    function GetIsZoomed: Boolean;
    function GetNeedCheckNonClientSize: Boolean;
    function GetNonClientMetrics: TNonClientMetrics;
    function GetScreenRect: TRect;
    function GetScrollBarsController: TdxSkinFormScrollBarsController;
    function GetSizeArea(ASide: TcxBorder): TRect;
    function GetSizeCorners(ACorner: TdxSkinFormCorner): TRect;
    function GetSkinBorderWidth(ASide: TcxBorder): Integer;
    function GetSuppressFactor: Single;
    function GetSystemBorderWidths: TRect;
    function GetSystemSizeFrame: TSize;
    function GetThemeActive: Boolean;
    function GetToolWindow: Boolean;
    function GetWindowState: TWindowState;
    procedure SetActive(AActive: Boolean);
    procedure SetSizeType(AValue: Integer);
    procedure SetUpdateRgn(ARgn: HRGN);
  protected
    FActive: Boolean;
    FBorderBounds: array[TcxBorder] of TRect;
    FBorderWidths: TRect;
    FCaption: string;
    FCaptionFont: TFont;
    FCaptionTextBounds: TRect;
    FCaptionTextColor: array[Boolean] of TColor;
    FCaptionTextShadowColor: TColor;
    FClientBounds: TRect;
    FClientEdgeSize: TSize;
    FHasMenu: Boolean;
    FIsMDIChild: Boolean;
    FIsMDIClient: Boolean;
    FMenuBarHeight: Integer;
    FMenuSeparatorBounds: TRect;
    FPainter: TcxCustomLookAndFeelPainter;
    FPainterInfo: TdxSkinLookAndFeelPainterInfo;
    FSizeFrame: TSize;
    FSysMenuIcon: HICON;
    FUpdateRgn: HRGN;
    FWindowBounds: TRect;
    procedure CalculateBordersInfo; virtual;
    procedure CalculateBorderWidths; virtual;
    procedure CalculateCaptionIconsInfo; virtual;
    function CalculateCaptionButtonSize(const ACaptionRect: TRect; AElement: TdxSkinElement): TSize; virtual;
    function CalculateCaptionContentHeight: Integer; virtual;
    function CalculateCaptionHeight: Integer; virtual;
    function CalculateCaptionIconsHeight: Integer; virtual;
    function CalculateCaptionTextHeight: Integer; virtual;
    procedure CalculateFontInfo;
    procedure CalculateFrameSizes; virtual;
    function CalculateMargins: TRect; virtual;
    function CalculateMenuBarHeight: Integer; virtual;
    function CalculateMenuIconSize(AToolWindow: Boolean): TSize; virtual;
    procedure CalculateScrollArea; virtual;
    procedure CalculateWindowInfo; virtual;
    procedure CombineRectWithRegion(ADest: HRGN; const R: TRect);
    function GetBorderRect(ASide: TcxBorder; const ABounds, AWidths: TRect): TRect;
    function GetIcons: TdxSkinFormIcons; virtual;
    function GetIsMenuCommandEnabled(AMenuCommandId: Integer): Boolean;
    function GetMDIClientDrawRgn: HRGN; virtual;
    function GetSysMenuIcon: HICON; virtual;
    function IsNativeBorderWidth(ACheckZoomed: Boolean = True): Boolean;
    function UpdateCaptionIconStates: Boolean;
    procedure UpdateCaption(const ANewText: string);
    // System Menu
    procedure BuildSystemMenu(ASysMenu: THandle);
    procedure DestroyStandardMenu;
    procedure LoadStandardMenu;
    procedure ModifySystemMenu(ASysMenu: THandle);
    procedure ResetSystemMenu;
  public
    constructor Create(AController: TdxSkinCustomFormController); virtual;
    destructor Destroy; override;
    procedure Calculate(AUpdateRgn: HRGN); virtual;
    function ClientToScreen(const P: TPoint): TPoint; overload;
    function ClientToScreen(const R: TRect): TRect; overload;
    function CreateDrawRgn: HRGN; virtual;
    function GetHitTest(AHitPoint: TPoint; AHitTest: Integer = 0): Integer;
    function ScreenToClient(const P: TSmallPoint): TPoint; overload;
    function ScreenToClient(const P: TPoint): TPoint; overload;
    function ScreenToClient(const R: TRect): TRect; overload;
    procedure UpdateFormCaption;

    property Active: Boolean read FActive write SetActive;
    property BorderBounds[ASide: TcxBorder]: TRect read GetBorderBounds;
    property BorderWidths: TRect read FBorderWidths;
    property ButtonPressed: Boolean read GetButtonPressed;
    property Caption: string read FCaption;
    property CaptionElement: TdxSkinElement read GetCaptionElement;
    property CaptionFont: TFont read FCaptionFont;
    property CaptionTextBounds: TRect read FCaptionTextBounds;
    property CaptionTextColor: TColor read GetCaptionTextColor;
    property CaptionTextShadowColor: TColor read FCaptionTextShadowColor write FCaptionTextShadowColor;
    property ClientBounds: TRect read FClientBounds;
    property ClientEdgeSize: TSize read FClientEdgeSize;
    property ClientOffset: Integer read FClientOffset;
    property ClientRect: TRect read FClientRect;
    property ClientCursorPos: TPoint read GetClientCursorPos;
    property ClientRectOnClient: TRect read GetClientRectOnClient;
    property ContentRect: TRect read GetContentRect;
    property Controller: TdxSkinCustomFormController read FController;
    property ExStyle: Integer read FExStyle;
    property Handle: HWND read GetHandle;
    property HasBorder: Boolean read GetHasBorder;
    property HasCaption: Boolean read GetHasCaption;
    property HasCaptionTextShadow: Boolean read GetHasCaptionTextShadow;
    property HasClientEdge: Boolean read GetHasClientEdge;
    property HasMenu: Boolean read GetHasMenu;
    property HasParent: Boolean read GetHasParent;
    property HasScrollsArea: Boolean read GetHasScrollsArea;
    property HasSizeConstraints: Boolean read GetHasSizeConstraints;
    property IconInfoList: TdxSkinFormIconInfoList read FIconInfoList;
    property Icons: TdxSkinFormIcons read GetIcons;
    property IsAlphaBlendUsed: Boolean read GetIsAlphaBlendUsed;
    property IsChild: Boolean read GetIsChild;
    property IsDialog: Boolean read GetIsDialog;
    property IsIconic: Boolean read GetIsIconic;
    property IsMDIChild: Boolean read FIsMDIChild;
    property IsMDIClient: Boolean read FIsMDIClient;
    property IsSizebox: Boolean read GetIsSizeBox;
    property IsZoomed: Boolean read GetIsZoomed;
    property MenuBarHeight: Integer read FMenuBarHeight;
    property MenuSeparatorBounds: TRect read FMenuSeparatorBounds;
    property NeedCheckNonClientSize: Boolean read GetNeedCheckNonClientSize;
    property NonClientMetrics: TNonClientMetrics read GetNonClientMetrics;
    property Painter: TcxCustomLookAndFeelPainter read FPainter;
    property PainterInfo: TdxSkinLookAndFeelPainterInfo read FPainterInfo;
    property ScreenRect: TRect read GetScreenRect;
    property ScrollBarsController: TdxSkinFormScrollBarsController read GetScrollBarsController;
    property SizeArea[ASide: TcxBorder]: TRect read GetSizeArea;
    property SizeCorners[ACorner: TdxSkinFormCorner]: TRect read GetSizeCorners;
    property SizeFrame: TSize read FSizeFrame;
    property SizeType: Integer read FSizeType write SetSizeType;
    property SkinBorderWidth[ASide: TcxBorder]: Integer read GetSkinBorderWidth;
    property Style: Integer read FStyle;
    property SuppressFactor: Single read GetSuppressFactor;
    property Supressed: Boolean read FSupressed;
    property SysMenuIcon: HICON read FSysMenuIcon;
    property SystemBorderWidths: TRect read GetSystemBorderWidths;
    property SystemMenu: HMENU read FSystemMenu;
    property SystemSizeFrame: TSize read GetSystemSizeFrame;
    property ThemeActive: Boolean read GetThemeActive;
    property ThemeActiveAssigned: Boolean read FThemeActiveAssigned write FThemeActiveAssigned;
    property ToolWindow: Boolean read GetToolWindow;
    property UpdateRgn: HRGN read FUpdateRgn write SetUpdateRgn;
    property WindowBounds: TRect read FWindowBounds;
    property WindowRect: TRect read FWindowRect;
    property WindowState: TWindowState read GetWindowState;
  end;

  { TdxSkinFormPainter }

  TdxSkinFormPainter = class(TObject)
  private
    FBackgroundCache: TdxSkinElementCache;
    FBordersCache: array[TcxBorder] of TdxSkinElementCache;
    FDC: HDC;
    FIconsCache: array[TdxSkinFormIcon] of TdxSkinElementCache;
    FNeedRelease: Boolean;
    FViewInfo: TdxSkinFormNonClientAreaInfo;
    function GetActive: Boolean;
    function GetFormContent: TdxSkinElement;
    function GetFormContentTextColor: TColor;
    function GetIconElement(AIcon: TdxSkinFormIcon): TdxSkinElement;
    function GetIsBordersThin: Boolean;
    function GetPainter: TcxCustomLookAndFeelPainter;
    function GetPainterInfo: TdxSkinLookAndFeelPainterInfo;
    function GetScrollBars: TdxSkinFormScrollBarsController;
  protected
    procedure CreateCacheInfos;
    procedure DrawBackground(DC: HDC; const R: TRect); virtual;
    procedure DrawCaptionText(DC: HDC; R: TRect; const AText: string); virtual;
    procedure DrawScrollAreaElements; virtual;
    procedure DrawScrollBar(AScrollBar: TdxSkinFormScrollBarViewInfo); virtual;
    procedure DrawSizeGrip(const R: TRect);
    procedure DrawWindowCaption(DC: HDC; const R: TRect; AElement: TdxSkinElement); virtual;
    procedure DrawWindowCaptionBackground(DC: HDC; const R: TRect; AElement: TdxSkinElement); virtual;
    procedure DrawWindowCaptionText(DC: HDC; R: TRect); virtual;
    procedure DrawWindowIcon(DC: HDC; AIconInfo: TdxSkinFormIconInfo); overload;
    procedure DrawWindowIcon(DC: HDC; const R: TRect; AIcon: TdxSkinFormIcon;
      AElement: TdxSkinElement; AElementState: TdxSkinElementState); overload; virtual;
    procedure FreeCacheInfos;
    procedure InternalDrawBorder(DC: HDC; const R: TRect; ASide: TcxBorder; AFillBackground: Boolean);
    procedure InternalDrawBorders;
    procedure InternalDrawCaption(const R: TRect; AElement: TdxSkinElement);
    procedure InternalDrawThinBorders;
  public
    constructor Create(AViewInfo: TdxSkinFormNonClientAreaInfo); virtual;
    destructor Destroy; override;
    procedure BeginPaint(ADestDC: HDC = 0);
    procedure DrawClientOffsetArea; virtual;
    procedure DrawMDIClientEdgeArea; virtual;
    procedure DrawMenuSeparator; virtual;
    procedure DrawWindowBackground; virtual;
    procedure DrawWindowBorder; virtual;
    procedure DrawWindowScrollArea; virtual;
    procedure EndPaint;
    procedure FlushCache;
    function IsRectVisible(const R: TRect): Boolean;

    property Active: Boolean read GetActive;
    property FormContent: TdxSkinElement read GetFormContent;
    property FormContentTextColor: TColor read GetFormContentTextColor;
    property IconElements[AIcon: TdxSkinFormIcon]: TdxSkinElement read GetIconElement;
    property IsBordersThin: Boolean read GetIsBordersThin;
    property Painter: TcxCustomLookAndFeelPainter read GetPainter;
    property PainterInfo: TdxSkinLookAndFeelPainterInfo read GetPainterInfo;
    property ScrollBars: TdxSkinFormScrollBarsController read GetScrollBars;
    property ViewInfo: TdxSkinFormNonClientAreaInfo read FViewInfo;
  end;

  { TdxSkinFormController }

  TdxSkinFormController = class(TdxSkinCustomFormController)
  protected
    function CanFinalizeEngine: Boolean; override;
    function FindLookAndFeelPainter: TdxSkinLookAndFeelPainter; override;
    function FindMasterController: TdxSkinWinController; override;
    function GetCanUseSkin: Boolean; override;
  end;

  { TdxSkinFormMDIClientController }

  TdxSkinFormMDIClientController = class(TdxSkinCustomFormController)
  protected
    function FindMasterController: TdxSkinWinController; override;
    function GetCanUseSkin: Boolean; override;
    function GetUseSkin: Boolean; override;
  end;

  { TdxSkinForm }

  TdxSkinForm = class(TForm)
  private
    FController: TdxSkinFormController;
  protected
    procedure CreateWindowHandle(const Params: TCreateParams); override;
    procedure DefaultWndProc(var Message: TMessage);
    procedure DestroyWindowHandle; override;
    procedure FinalizeController;
    procedure InitializeController;
    procedure WndProc(var Message: TMessage); override;

    property Controller: TdxSkinFormController read FController;
  end;

  { TdxSkinFormHelper }

  TdxSkinFormHelper = class(TObject)
  public
    class function CanUseSkin(AForm: TCustomForm): Boolean;
    class function GetActiveMDIChild(AHandle: HWND): TCustomForm;
    class function GetClientOffset(AHandle: HWND): Integer;
    class function GetForm(AHandle: HWND): TCustomForm;
    class function GetZoomedMDIChild(AHandle: HWND): TCustomForm;
    class function HasClientEdge(AHandle: HWND): Boolean;
    class function IsAlphaBlendUsed(AHandle: HWND): Boolean;
  end;

  { TdxSkinFrameController }

  TdxSkinFrameController = class(TdxSkinCustomFormController)
  private
    function GetIsTransparent: Boolean;
  protected
    procedure DrawWindowBackground(DC: HDC); override;
    procedure WMWindowPosChanged(var Message: TWMWindowPosMsg); override;
    //
    property IsTransparent: Boolean read GetIsTransparent;
  end;

  { TdxSkinCustomControlViewInfo }

  TdxSkinCustomControlViewInfo = class(TObject)
  private
    FController: TdxSkinWinController;
    function GetClientHeight: Integer;
    function GetClientRect: TRect;
    function GetClientWidth: Integer;
    function GetIsEnabled: Boolean;
    function GetIsFocused: Boolean;
    function GetIsMouseAtControl: Boolean;
    function GetLookAndFeelPainter: TcxCustomLookAndFeelPainter;
  public
    constructor Create(AController: TdxSkinWinController); virtual;
    procedure DrawBackground(ACanvas: TcxCanvas); virtual;
    procedure DrawContent(ACanvas: TcxCanvas); virtual; 
    //
    property ClientHeight: Integer read GetClientHeight;
    property ClientRect: TRect read GetClientRect;
    property ClientWidth: Integer read GetClientWidth;
    property Controller: TdxSkinWinController read FController;
    property IsEnabled: Boolean read GetIsEnabled;
    property IsFocused: Boolean read GetIsFocused;
    property IsMouseAtControl: Boolean read GetIsMouseAtControl;
    property LookAndFeelPainter: TcxCustomLookAndFeelPainter read GetLookAndFeelPainter;
  end;

  { TdxSkinCustomControlController }

  TdxSkinCustomControlController = class(TdxSkinWinController)
  private
    FDoubleBuffered: Boolean;
    FViewInfo: TdxSkinCustomControlViewInfo;
    procedure DoDraw(DC: HDC);
  protected
    function CreateViewInfo: TdxSkinCustomControlViewInfo; virtual;
    procedure WndProc(var AMessage: TMessage); override;
    // Messages
    function WMEraseBk(var AMessage: TWMEraseBkgnd): Boolean; virtual;
    function WMPaint(var AMessage: TWMPaint): Boolean; virtual;
  public
    constructor Create(AHandle: HWND); override;
    destructor Destroy; override;
    procedure Draw(DC: HDC = 0); virtual;

    property DoubleBuffered: Boolean read FDoubleBuffered write FDoubleBuffered;
    property ViewInfo: TdxSkinCustomControlViewInfo read FViewInfo;
  end;

  { TdxSkinCustonButtonViewInfo }

  TdxSkinCustonButtonViewInfo = class(TdxSkinCustomControlViewInfo)
  private
    FState: TcxButtonState;
    function GetCaption: string;
    function GetIsPressed: Boolean;
    function GetWordWrap: Boolean;
    procedure SetState(AState: TcxButtonState);
  protected
    function CalculateButtonState: TcxButtonState; virtual; 
    procedure UpdateButtonState; 
  public
    procedure AfterConstruction; override;
    //
    property Caption: string read GetCaption;
    property IsPressed: Boolean read GetIsPressed;
    property State: TcxButtonState read FState write SetState;
    property WordWrap: Boolean read GetWordWrap;
  end;

  { TdxSkinCustonButtonController }

  TdxSkinCustonButtonController = class(TdxSkinCustomControlController)
  private
    function GetViewInfo: TdxSkinCustonButtonViewInfo;
  protected
    procedure MouseLeave; override;
    procedure WndProc(var AMessage: TMessage); override;
  public
    constructor Create(AHandle: HWND); override;
    //
    property ViewInfo: TdxSkinCustonButtonViewInfo read GetViewInfo;
  end;

  { TdxSkinButtonViewInfo }

  TdxSkinButtonViewInfo = class(TdxSkinCustonButtonViewInfo)
  private
    FActive: Boolean;
    function GetIsDefault: Boolean;
    procedure SetActive(AActive: Boolean);
  protected
    function CalculateButtonState: TcxButtonState; override;
    procedure CMFocusChanged(var Message: TCMFocusChanged);
  public
    procedure DrawContent(ACanvas: TcxCanvas); override;

    property Active: Boolean read FActive write SetActive;
    property IsDefault: Boolean read GetIsDefault;
  end;

  { TdxSkinButtonController }

  TdxSkinButtonController = class(TdxSkinCustonButtonController)
  protected
    function CreateViewInfo: TdxSkinCustomControlViewInfo; override;
    procedure WndProc(var AMessage: TMessage); override;
  end;

  { TdxSkinPanelViewInfo }

  TdxSkinPanelViewInfo = class(TdxSkinCustomControlViewInfo)
  public
    procedure DrawBackground(ACanvas: TcxCanvas); override;
    procedure DrawContent(ACanvas: TcxCanvas); override;
  end;

  { TdxSkinPanelController }

  TdxSkinPanelController = class(TdxSkinCustomControlController)
  private
    FPainting: Boolean;
  protected
    function CreateViewInfo: TdxSkinCustomControlViewInfo; override;
    function WMEraseBk(var AMessage: TWMEraseBkgnd): Boolean; override;
    function WMPaint(var AMessage: TWMPaint): Boolean; override;
    function WMPrintClient(var AMessage: TWMPrintClient): Boolean; virtual;
    procedure WndProc(var AMessage: TMessage); override;
  end;

  { TdxSkinController }

  TdxSkinControlEvent = procedure(Sender: TObject; AControl: TWinControl; var UseSkin: Boolean) of object;
  TdxSkinFormEvent = procedure(Sender: TObject; AForm: TCustomForm; var ASkinName: string; var UseSkin: Boolean) of object;
  TdxSkinPopupSysMenuEvent = procedure (Sender: TObject; AForm: TCustomForm; ASysMenu: HMENU) of object;

  TdxSkinGetControllerClassForWindowProc = function (AWnd: HWND): TdxSkinWinControllerClass;

  TdxSkinController = class(TcxLookAndFeelController)
  private
    FOnPopupSysMenu: TdxSkinPopupSysMenuEvent;
    FOnSkinControl: TdxSkinControlEvent;
    FOnSkinForm: TdxSkinFormEvent;
    function GetUseImageSet: TdxSkinImageSet;
    function GetUseSkins: Boolean;
    procedure SetUseImageSet(AValue: TdxSkinImageSet);
    procedure SetUseSkins(Value: Boolean);
  protected
    procedure FullRefresh;
    procedure DoPopupSystemMenu(AForm: TCustomForm; ASysMenu: HMENU); virtual;
    procedure DoSkinControl(AControl: TWinControl; var AUseSkin: Boolean); virtual;
    procedure DoSkinForm(AForm: TCustomForm; var ASkinName: string; var AUseSkin: Boolean); virtual;
    procedure Loaded; override;
    procedure MasterLookAndFeelChanged(Sender: TcxLookAndFeel; AChangedValues: TcxLookAndFeelValues); override;
    procedure MasterLookAndFeelDestroying(Sender: TcxLookAndFeel); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Refresh(AControl: TWinControl = nil);
    class function GetFormSkin(AForm: TCustomForm; var ASkinName: string): Boolean;
  published
    property Kind;
    property NativeStyle;
    property SkinName;
    property UseImageSet: TdxSkinImageSet read GetUseImageSet write SetUseImageSet default imsDefault;
    property UseSkins: Boolean read GetUseSkins write SetUseSkins default True;
    property OnPopupSysMenu: TdxSkinPopupSysMenuEvent read FOnPopupSysMenu write FOnPopupSysMenu;
    property OnSkinControl: TdxSkinControlEvent read FOnSkinControl write FOnSkinControl;
    property OnSkinForm: TdxSkinFormEvent read FOnSkinForm write FOnSkinForm;
  end;

  { TdxSkinControllersList }

  TdxSkinControllersList = class(TList)
  private
    function GetDefaultSkinName: string;
    function GetDefaultUseSkins: Boolean;
    function GetItem(Index: Integer): TdxSkinController;
  public
    function CanSkinControl(AControl: TWinControl): Boolean;
    function CanSkinForm(AForm: TCustomForm): TdxSkinLookAndFeelPainter;
    function GetSkinPainter(const AName: string; out APainter: TdxSkinLookAndFeelPainter): Boolean;
    //
    property Items[Index: Integer]: TdxSkinController read GetItem; default;
  end;

var
  dxSkinControllersList: TdxSkinControllersList;
  dxSkinGetControllerClassForWindowProc: TdxSkinGetControllerClassForWindowProc;

function dxSkinGetControllerClassForWindow(AWnd: HWND): TdxSkinWinControllerClass;
implementation

uses
  FlatSB, Math, dxHooks;

const
  SC_TITLEDBLCLICK = 61490;
  WM_NCUAHDRAWCAPTION = $00AE;
  WM_NCUAHDRAWFRAME   = $00AF;
  WM_SYNCPAINT        = $0088;
  WM_SYSMENU          = $313;

  dxScrollInitialInterval = 400;
  dxScrollInterval = 60;

  // hittests
  CornerHitTests: array[TdxSkinFormCorner] of DWORD = (HTTOPLEFT, HTTOPRIGHT, HTBOTTOMLEFT, HTBOTTOMRIGHT);
  ResizeHitTests: array[TcxBorder] of DWORD = (HTLEFT, HTTOP, HTRIGHT, HTBOTTOM);

const
  CaptionFlags = DT_VCENTER or DT_SINGLELINE or DT_EDITCONTROL or DT_END_ELLIPSIS or DT_NOPREFIX;
  FrameStates: array[Boolean] of TdxSkinElementState = (esActiveDisabled, esActive);

type
  TControlAccess = class(TControl);
  TCustomFormAccess = class(TCustomForm);
  TCustomFrameAccess = class(TCustomFrame);
  TCustomLabelAccess = class(TCustomLabel);
  TCustomPanelAccess = class(TCustomPanel);
  TWinControlAccess = class(TWinControl);

type

  { TdxSkinWinControllerHelper }

  TdxSkinWinControllerHelper = class(TObject)
  private
    FHandle: HWND;
  protected
    procedure InternalInitializeEngine(AHandle: HWND);
    procedure WndProc(var AMsg: TMessage);
  public
    constructor Create;
    destructor Destroy; override;
    procedure ChildChanged(AHandle: HWND);
    procedure FinalizeEngine(AHandle: HWND);
    procedure InitializeEngine(AHandle: HWND);
    //
    property Handle: HWND read FHandle;
  end;

  { TdxSkinSkinnedControlsControllers }

  TdxSkinSkinnedControlsControllers = class(TdxSkinWinControllerList)
  public
    procedure NotifyMasterDestroying(AMaster: TdxSkinWinController);
    procedure Refresh(AControl: TWinControl); overload;
    procedure Refresh(AHandle: HWND); overload;
    procedure Refresh(AMaster: TdxSkinWinController); overload;
  end;

var
  SkinHelper: TdxSkinWinControllerHelper;
  SkinnedControlsControllers: TdxSkinSkinnedControlsControllers;

function GetWindowCaption(AWnd: HWND): string;
var
  AControl: TControl;
begin
  AControl := FindControl(AWnd);
  if AControl <> nil then 
    Result := TControlAccess(AControl).Caption
  else
    Result := cxGetWindowText(AWnd);
end;

procedure RefreshControllers(AControl: TWinControl = nil);
begin
  if not (csDestroying in Application.ComponentState) then
  begin
    if SkinnedControlsControllers <> nil then
    begin
      if AControl = nil then
        SkinnedControlsControllers.Refresh
      else
        SkinnedControlsControllers.Refresh(AControl);
    end;
  end;
end;

procedure ExcludeOpaqueChildren(AControl: TWinControl; DC: HDC);
var
  AChildControl: TControl;
  I: Integer;
begin
  if AControl <> nil then
    for I := 0 to AControl.ControlCount - 1 do
    begin
      AChildControl := AControl.Controls[I];
      if AChildControl.Visible and (csOpaque in AChildControl.ControlStyle) then
      begin
        with AChildControl.BoundsRect do
          ExcludeClipRect(DC, Left, Top, Right, Bottom);
      end;
    end;
end;

{ TdxSkinFormController }

function TdxSkinFormController.CanFinalizeEngine: Boolean;
begin
  Result := not (Form is TdxSkinForm);
end;

function TdxSkinFormController.FindLookAndFeelPainter: TdxSkinLookAndFeelPainter;
begin
  Result := dxSkinControllersList.CanSkinForm(Form);
end;

function TdxSkinFormController.FindMasterController: TdxSkinWinController;
begin
  Result := nil;
end;

function TdxSkinFormController.GetCanUseSkin: Boolean;
begin
  Result := TdxSkinFormHelper.CanUseSkin(Form);
end;

{ TdxSkinFormMDIClientController }

function TdxSkinFormMDIClientController.FindMasterController: TdxSkinWinController;
begin
  Result := SkinnedControlsControllers.GetControllerByHandle(GetParent(Handle));
end;

function TdxSkinFormMDIClientController.GetCanUseSkin: Boolean;
begin
  Result := True;
end;

function TdxSkinFormMDIClientController.GetUseSkin: Boolean;
begin
  Result := inherited GetUseSkin and (Master <> nil) and Master.UseSkin;
end;

{ TdxSkinForm }

procedure TdxSkinForm.CreateWindowHandle(const Params: TCreateParams);
begin
  inherited CreateWindowHandle(Params);
  InitializeController;
end;

procedure TdxSkinForm.DestroyWindowHandle;
begin
  FinalizeController;
  inherited DestroyWindowHandle;
end;

procedure TdxSkinForm.DefaultWndProc(var Message: TMessage);
begin
  inherited WndProc(Message);
end;

procedure TdxSkinForm.FinalizeController;
begin
  if Controller <> nil then
  begin
    SkinnedControlsControllers.Remove(Controller);
    FreeAndNil(FController);
  end;
end;

procedure TdxSkinForm.InitializeController;
begin
  FController := TdxSkinFormController.CreateEx(Self);
  SkinnedControlsControllers.Add(Controller);
  Controller.RefreshControllerAndUpdate;
  PostMessage(Handle, DXM_SKINS_POSTCHECKRGN, 0, 0);
end;

procedure TdxSkinForm.WndProc(var Message: TMessage);
begin
  if Message.Msg = DXM_SKINS_HASOWNSKINENGINE then
    Message.Result := 1
  else
    if (Controller = nil) or (Controller.Handle = 0) then
      DefaultWndProc(Message)
    else
      Controller.WndProc(Message);
end;

{ TdxSkinFormHelper }

class function TdxSkinFormHelper.CanUseSkin(AForm: TCustomForm): Boolean;
begin
  Result := Assigned(AForm) and (SendMessage(AForm.Handle, DXM_SKINS_GETISSKINNED, 0, 0) = 0);
end;

class function TdxSkinFormHelper.GetActiveMDIChild(AHandle: HWND): TCustomForm;
var
  ACustomForm: TCustomFormAccess;
begin
  Result := nil;
  ACustomForm := TCustomFormAccess(GetForm(AHandle));
  if (ACustomForm <> nil) and (ACustomForm.FormStyle = fsMDIForm) then
    if ACustomForm.ActiveMDIChild <> nil then
      Result := ACustomForm.ActiveMDIChild;
end;

class function TdxSkinFormHelper.GetClientOffset(AHandle: HWND): Integer;
var
  ACustomForm: TCustomFormAccess;
begin
  ACustomForm := TCustomFormAccess(GetForm(AHandle));
  if ACustomForm = nil then
    Result := 0
  else
    Result := ACustomForm.BorderWidth;
end;

class function TdxSkinFormHelper.GetForm(AHandle: HWND): TCustomForm;
var
  AControl: TWinControl;
begin
  AControl := FindControl(AHandle);
  if AControl is TCustomForm then
    Result := TCustomForm(AControl)
  else
    Result := nil;
end;

class function TdxSkinFormHelper.GetZoomedMDIChild(AHandle: HWND): TCustomForm;
var
  AActiveChild: TCustomForm;
begin
  AActiveChild := GetActiveMDIChild(AHandle);
  if Assigned(AActiveChild) and IsZoomed(AActiveChild.Handle) then
    Result := AActiveChild
  else
    Result := nil;
end;

class function TdxSkinFormHelper.HasClientEdge(AHandle: HWND): Boolean;
begin
  Result := GetWindowLong(AHandle, GWL_EXSTYLE) and WS_EX_CLIENTEDGE <> 0;
end;

class function TdxSkinFormHelper.IsAlphaBlendUsed(AHandle: HWND): Boolean;
begin
  Result := GetWindowLong(AHandle, GWL_EXSTYLE) and WS_EX_LAYERED <> 0;
  AHandle := GetParent(AHandle);
  if TdxSkinWinController.IsMDIClientWindow(AHandle) then
    Result := GetWindowLong(GetParent(AHandle), GWL_EXSTYLE) and WS_EX_LAYERED <> 0;
end;

{ TdxSkinFormNonClientAreaInfo }

constructor TdxSkinFormNonClientAreaInfo.Create(AController: TdxSkinCustomFormController);
begin
  inherited Create;
  FController := AController;
  FCaptionFont := TFont.Create;
  FIconInfoList := TdxSkinFormIconInfoList.Create(Self);
  UpdateFormCaption;
  FActive := True;
end;

destructor TdxSkinFormNonClientAreaInfo.Destroy;
begin
  DestroyStandardMenu;
  UpdateRgn := 0;
  FreeAndNil(FCaptionFont);
  FreeAndNil(FIconInfoList);
  inherited Destroy;
end;

procedure TdxSkinFormNonClientAreaInfo.Calculate(AUpdateRgn: HRGN);
begin
  FIsMDIChild := TdxSkinWinController.IsMDIChildWindow(Handle);
  FIsMDIClient := TdxSkinWinController.IsMDIClientWindow(Handle);
  FHasMenu := IsMenu(GetMenu(Handle)) and not FIsMDIChild;
  FPainter := Controller.LookAndFeelPainter;
  FPainterInfo := Controller.LookAndFeelPainter.SkinInfo;
  CalculateFrameSizes;
  CalculateWindowInfo;
  CalculateFontInfo;
  CalculateBorderWidths;
  CalculateBordersInfo;
  CalculateCaptionIconsInfo;
  CalculateScrollArea;
end;

function TdxSkinFormNonClientAreaInfo.ClientToScreen(const P: TPoint): TPoint;
begin
  Result := cxPointOffset(P, WindowRect.TopLeft);
end;

function TdxSkinFormNonClientAreaInfo.ClientToScreen(const R: TRect): TRect;
begin
  Result := cxRectOffset(R, WindowRect.TopLeft);
end;

procedure TdxSkinFormNonClientAreaInfo.CombineRectWithRegion(ADest: HRGN; const R: TRect);
var
  ARgn: HRGN;
begin
  ARgn := CreateRectRgnIndirect(ClientToScreen(R));
  CombineRgn(ADest, ADest, ARgn, RGN_OR);
  DeleteObject(ARgn);
end;

function TdxSkinFormNonClientAreaInfo.CreateDrawRgn: HRGN;
var
  ARgn: HRGN;
  ASide: TcxBorder;
begin
  Result := CreateRectRgnIndirect(cxNullRect);
  for ASide := Low(TcxBorder) to High(TcxBorder) do
  begin
    if not cxRectIsEmpty(BorderBounds[ASide]) then
      CombineRectWithRegion(Result, BorderBounds[ASide]);
  end;
  if IsMDIClient then
  begin
    ARgn := GetMDIClientDrawRgn;
    CombineRgn(Result, Result, ARgn, RGN_OR);
    DeleteObject(ARgn);
  end;
  if HasMenu then
    CombineRectWithRegion(Result, MenuSeparatorBounds);
  Controller.ScrollBarsController.CalculateDrawRegion(Result);
end;

function TdxSkinFormNonClientAreaInfo.GetHitTest(AHitPoint: TPoint; AHitTest: Integer = 0): Integer;
var
  ASide: TcxBorder;
  AIconInfo: TdxSkinFormIconInfo;
  ACorner: TdxSkinFormCorner;
begin
  Result := AHitTest;
  AHitPoint := ScreenToClient(AHitPoint);
  if IsSizebox and not IsZoomed then
  begin
    for ACorner := sfcLeftTop to sfcRightBottom do
      if (Result = HTNOWHERE) and PtInRect(SizeCorners[ACorner], AHitPoint) then
        Result := CornerHitTests[ACorner];
    for ASide := bLeft to bBottom do
      if (Result = HTNOWHERE) and PtInRect(SizeArea[ASide], AHitPoint) then
        Result := ResizeHitTests[ASide];
  end;
  if (Result = HTNOWHERE) and PtInRect(BorderBounds[bTop], AHitPoint) then
  begin
    if IconInfoList.HitTest(AHitPoint, AIconInfo) then
      Result := AIconInfo.HitTest
    else
      Result := HTCAPTION;
  end;
end;

function TdxSkinFormNonClientAreaInfo.ScreenToClient(const P: TSmallPoint): TPoint;
begin
  Result := ScreenToClient(SmallPointToPoint(P));
end;

function TdxSkinFormNonClientAreaInfo.ScreenToClient(const P: TPoint): TPoint;
begin
  Result := cxPointOffset(P, cxPointInvert(WindowRect.TopLeft));
end;

function TdxSkinFormNonClientAreaInfo.ScreenToClient(const R: TRect): TRect;
begin
  Result := cxRectOffset(R, cxPointInvert(WindowRect.TopLeft));
end;

procedure TdxSkinFormNonClientAreaInfo.CalculateBordersInfo;
var
  ASide: TcxBorder;
begin
  for ASide := Low(TcxBorder) to High(TcxBorder) do
    FBorderBounds[ASide] := GetBorderRect(ASide, WindowBounds, BorderWidths);
end;

procedure TdxSkinFormNonClientAreaInfo.CalculateBorderWidths;
begin
  FBorderWidths := cxNullRect;
  if IsIconic then
    FBorderWidths.Top := cxRectHeight(WindowBounds)
  else
  begin
    if HasBorder then
    begin
      FBorderWidths := PainterInfo.FormBorderWidths[not ToolWindow];
      if IsNativeBorderWidth then
      begin
        FBorderWidths.Left := Min(FBorderWidths.Left, SystemBorderWidths.Left);
        FBorderWidths.Right := Min(FBorderWidths.Right, SystemBorderWidths.Right);
        FBorderWidths.Bottom := Min(FBorderWidths.Bottom, SystemBorderWidths.Bottom);
      end;
    end;
    FBorderWidths.Top := CalculateCaptionHeight;
    if HasMenu then
    begin
      FMenuSeparatorBounds := cxRectContent(WindowBounds, BorderWidths);
      FMenuSeparatorBounds := cxRectSetHeight(FMenuSeparatorBounds, 1);
    end;
  end;
end;

function TdxSkinFormNonClientAreaInfo.CalculateCaptionButtonSize(
  const ACaptionRect: TRect; AElement: TdxSkinElement): TSize;
begin
  Result := TdxSkinElementHelper.CalculateCaptionButtonSize(cxRectHeight(ACaptionRect), AElement);
end;

function TdxSkinFormNonClientAreaInfo.CalculateCaptionContentHeight: Integer;
begin
  Result := Max(CalculateCaptionTextHeight, CalculateCaptionIconsHeight);
end;

function TdxSkinFormNonClientAreaInfo.CalculateCaptionHeight: Integer;
begin
  if not HasCaption then
    Result := IfThen(HasBorder, BorderWidths.Bottom)
  else
    if IsNativeBorderWidth(False) then
      Result := SystemBorderWidths.Top - WindowBounds.Top
    else
    begin
      Result := cxMarginsHeight(CaptionElement.ContentOffset.Rect) + CalculateCaptionContentHeight;
      if IsZoomed then
        Result := Max(Result, SystemBorderWidths.Top - WindowBounds.Top);
    end;
end;

function TdxSkinFormNonClientAreaInfo.CalculateCaptionIconsHeight: Integer;
var
  AElement: TdxSkinElement;
  AIcon: TdxSkinFormIcon;
  AIcons: TdxSkinFormIcons;
begin
  Result := 0;
  AIcons := Icons;
  for AIcon := Low(TdxSkinFormIcon) to High(TdxSkinFormIcon) do
  begin
    if AIcon in AIcons then
    begin
      if AIcon = sfiMenu then
        Result := Max(Result, CalculateMenuIconSize(ToolWindow).cy)
      else
      begin
        AElement := PainterInfo.FormIcons[not ToolWindow, AIcon];
        if Assigned(AElement) then
          Result := Max(Result, AElement.MinSize.Height);
      end;
    end;
  end;
end;

function TdxSkinFormNonClientAreaInfo.CalculateCaptionTextHeight: Integer;
begin
  Result := cxTextHeight(FCaptionFont);
end;

function TdxSkinFormNonClientAreaInfo.CalculateMenuBarHeight: Integer;
var
  AMenu: HMENU;
  R: TRect;
begin
  Result := 0;
  AMenu := GetMenu(Handle);
  if (AMenu <> 0) and (GetMenuItemCount(AMenu) > 0) then
  begin
    GetMenuItemRect(Handle, AMenu, 0, R);
    Result := R.Top;
    GetMenuItemRect(Handle, AMenu, GetMenuItemCount(AMenu) - 1, R);
    Result := R.Bottom - Result;
  end;
end;

function TdxSkinFormNonClientAreaInfo.CalculateMenuIconSize(AToolWindow: Boolean): TSize;
var
  ASysIconSize: Integer;
begin
  if AToolWindow then
    ASysIconSize := GetSystemMetrics(SM_CYSMCAPTION) - 2 * GetSystemMetrics(SM_CYEDGE)
  else
    ASysIconSize := GetSystemMetrics(SM_CYSMICON);

  Result := cxSize(ASysIconSize, ASysIconSize);
end;

procedure TdxSkinFormNonClientAreaInfo.CalculateCaptionIconsInfo;

  function CalculateCaptionIconBounds(AIcon: TdxSkinFormIcon; var R: TRect): TRect;
  begin
    Result := R;
    if AIcon = sfiMenu then
    begin
      Result.Right := Result.Left + GetCaptionIconSize(AIcon).cx;
      R.Left := Result.Right;
    end
    else
    begin
      Result.Left := Result.Right - GetCaptionIconSize(AIcon).cx;
      R.Right := Result.Left - dxSkinIconSpacing;
    end;
  end;

  function CalculateCaptionTextAreaBounds(const R: TRect): TRect;
  begin
    if HasCaption then
    begin
      Result := cxRectContent(R, GetCaptionTextAreaOffset);
      Result := cxRectCenterVertically(Result, CalculateCaptionTextHeight)
    end
    else
      Result := cxNullRect;
  end;

  procedure AddCaptionIcon(AIcon: TdxSkinFormIcon; var R: TRect);
  var
    AInfo: TdxSkinFormIconInfo;
  begin
    if AIcon in Icons then
    begin
      AInfo := IconInfoList.Add(AIcon);
      AInfo.HitBounds := CalculateCaptionIconBounds(AIcon, R);
      AInfo.Bounds := cxRectCenter(AInfo.HitBounds, GetCaptionIconSize(AIcon));
      if IsZoomed then
      begin
        AInfo.FHitBounds.Top := Min(AInfo.HitBounds.Top, SystemSizeFrame.cy);
        if AIcon = sfiMenu then
          AInfo.FHitBounds.Left := Min(AInfo.HitBounds.Left, SystemSizeFrame.cx);
      end;
    end;
  end;

var
  R: TRect;
begin
  R := GetCaptionBounds;
  IconInfoList.Validate(Icons);
  // Don't change order
  AddCaptionIcon(sfiMenu, R);
  AddCaptionIcon(sfiClose, R);
  AddCaptionIcon(sfiMaximize, R);
  AddCaptionIcon(sfiRestore, R);
  AddCaptionIcon(sfiMinimize, R);
  AddCaptionIcon(sfiHelp, R);
  FCaptionTextBounds := CalculateCaptionTextAreaBounds(R);
  UpdateCaptionIconStates;
end;

procedure TdxSkinFormNonClientAreaInfo.CalculateFontInfo;
begin
  if ToolWindow then
    FCaptionFont.Handle := CreateFontIndirect(NonClientMetrics.lfSmCaptionFont)
  else
  begin
    FCaptionFont.Handle := CreateFontIndirect(NonClientMetrics.lfCaptionFont);
    if PainterInfo <> nil then
      FCaptionFont.Size := FCaptionFont.Size + (PainterInfo.FormCaptionDelta - 1);
  end;
  FCaptionTextShadowColor := clBtnShadow;
  FCaptionTextColor[True] := GetSysColor(COLOR_CAPTIONTEXT);
  FCaptionTextColor[False] := GetSysColor(COLOR_INACTIVECAPTIONTEXT);
  if PainterInfo <> nil then
  begin
    FCaptionTextColor[True] := PainterInfo.FormFrames[True, bTop].TextColor;
    if PainterInfo.FormTextShadowColor <> nil then
      FCaptionTextShadowColor := PainterInfo.FormTextShadowColor.Value;
    if PainterInfo.FormInactiveColor <> nil then
      FCaptionTextColor[False] := PainterInfo.FormInactiveColor.Value
    else
      FCaptionTextColor[False] := FCaptionTextColor[True];
  end;
end;

procedure TdxSkinFormNonClientAreaInfo.CalculateFrameSizes;
begin
  if HasClientEdge then
    FClientEdgeSize := Size(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE))
  else
    FClientEdgeSize := cxNullSize;

  if HasBorder then
    FSizeFrame := Size(
      PainterInfo.FormBorderWidths[not ToolWindow].Bottom,
      PainterInfo.FormBorderWidths[not ToolWindow].Right)
  else
    FSizeFrame := cxNullSize;

  FSupressed := IsNativeBorderWidth;
  if Supressed then
  begin
    FSizeFrame.cx := Min(SizeFrame.cx, SystemSizeFrame.cx);
    FSizeFrame.cy := Min(SizeFrame.cy, SystemSizeFrame.cy);
  end;
end;

function TdxSkinFormNonClientAreaInfo.CalculateMargins: TRect;
begin
  Result := BorderWidths;
  Inc(Result.Bottom, ClientOffset);
  Inc(Result.Left, ClientOffset);
  Inc(Result.Right, ClientOffset);
  Inc(Result.Top, ClientOffset);
  if ScrollBarsController.ScrollBarViewInfo[saeVertScroll].Visible then
    Inc(Result.Right, GetSystemMetrics(SM_CXVSCROLL));
  if ScrollBarsController.ScrollBarViewInfo[saeHorzScroll].Visible then
    Inc(Result.Bottom, GetSystemMetrics(SM_CYHSCROLL));
  if IsZoomed and IsSizebox then
  begin
    Inc(Result.Top, SystemSizeFrame.cy - SizeFrame.cy);
    Inc(Result.Left, SystemSizeFrame.cx - SizeFrame.cx);
    Inc(Result.Right, SystemSizeFrame.cx - SizeFrame.cx);
    Inc(Result.Bottom, SystemSizeFrame.cy - SizeFrame.cy);
  end;
end;

procedure TdxSkinFormNonClientAreaInfo.CalculateScrollArea;
begin
  ScrollBarsController.CalculateScrollArea;
end;

procedure TdxSkinFormNonClientAreaInfo.CalculateWindowInfo;
var
  APoint: TPoint;
begin
  APoint := cxNullPoint;
  FStyle := GetWindowLong(Handle, GWL_STYLE);
  FExStyle := GetWindowLong(Handle, GWL_EXSTYLE);
  FClientRect := cxGetClientRect(Handle);
  FWindowRect := cxGetWindowRect(Handle);
  Windows.ClientToScreen(Handle, APoint);
  OffsetRect(FClientRect, APoint.X, APoint.Y);
  FClientOffset := TdxSkinFormHelper.GetClientOffset(Handle);
  FClientBounds := cxRectOffset(ClientRect, WindowRect.TopLeft, False);
  FWindowBounds := cxRectOffset(WindowRect, WindowRect.TopLeft, False);
  if IsNativeBorderWidth then
    InflateRect(FWindowBounds,
      Min(0, SizeFrame.cx - SystemSizeFrame.cx),
      Min(0, SizeFrame.cy - SystemSizeFrame.cy));
  FSysMenuIcon := GetSysMenuIcon;
  FMenuBarHeight := CalculateMenuBarHeight;
end;

function TdxSkinFormNonClientAreaInfo.GetBorderRect(
  ASide: TcxBorder; const ABounds, AWidths: TRect): TRect;
begin
  Result := ABounds;
  case ASide of
    bLeft:
      Result.Right := Result.Left + AWidths.Left;
    bTop:
      Result.Bottom := Result.Top + AWidths.Top;
    bRight:
      Result.Left := Result.Right - AWidths.Right;
    bBottom:
      Result.Top := Result.Bottom - AWidths.Bottom;
  end;
end;

function TdxSkinFormNonClientAreaInfo.GetIcons: TdxSkinFormIcons;
const
  MaximizeMenuIcons: array[Boolean] of TdxSkinFormIcon = (sfiMaximize, sfiRestore);
  MimizeMenuIcons: array[Boolean] of TdxSkinFormIcon = (sfiMinimize, sfiRestore);
  SysMenuIcons: array[Boolean] of TdxSkinFormIcons = ([sfiMenu, sfiClose], [sfiClose]);
begin
  Result := [];
  if HasCaption then
  begin
    if Style and WS_SYSMENU = WS_SYSMENU then
      Result := SysMenuIcons[ToolWindow or IsDialog];
    if Style and WS_MINIMIZEBOX = WS_MINIMIZEBOX then
      Include(Result, MimizeMenuIcons[IsIconic]);
    if Style and WS_MAXIMIZEBOX = WS_MAXIMIZEBOX then
      Include(Result, MaximizeMenuIcons[IsZoomed]);
    if ExStyle and WS_EX_CONTEXTHELP = WS_EX_CONTEXTHELP then
    begin
      if IsDialog or ([sfiMinimize, sfiMaximize] * Result = []) then
        Include(Result, sfiHelp);
    end;
  end;
end;

function TdxSkinFormNonClientAreaInfo.GetIsMenuCommandEnabled(AMenuCommandId: Integer): Boolean;
var
  AMenu: HMENU;
  AMenuItemInfo: TMenuItemInfo;
begin
  AMenu := GetSystemMenu(Handle, False);
  ZeroMemory(@AMenuItemInfo, SizeOf(AMenuItemInfo));
  AMenuItemInfo.cbSize := SizeOf(AMenuItemInfo);
  AMenuItemInfo.fMask := MIIM_STATE;
  if GetMenuItemInfo(AMenu, AMenuCommandId, False, AMenuItemInfo) then
    Result := AMenuItemInfo.fState and MF_GRAYED = 0
  else
    Result := True;
end;

function TdxSkinFormNonClientAreaInfo.GetMDIClientDrawRgn: HRGN;
var
  ARgn: HRGN;
  R: TRect;
begin
  R := WindowRect;
  Result := CreateRectRgnIndirect(R);
  InflateRect(R, -ClientEdgeSize.cx, -ClientEdgeSize.cy);
  ARgn := CreateRectRgnIndirect(R);
  CombineRgn(Result, Result, ARgn, RGN_XOR);
  DeleteObject(ARgn);
end;

function TdxSkinFormNonClientAreaInfo.GetSysMenuIcon: HIcon;
var
  wParam: Integer;
begin
  wParam := Byte(not ToolWindow);
  if IsWinXPOrLater then
    wParam := ICON_SMALL2;
  Result := DefWindowProc(Handle, WM_GETICON, wParam, 0);
end;

function TdxSkinFormNonClientAreaInfo.IsNativeBorderWidth(ACheckZoomed: Boolean = True): Boolean;
begin
  Result := IsZoomed and (ACheckZoomed or FIsMDIChild) or FHasMenu or FIsMDIClient or not ThemeActive;
end;

procedure TdxSkinFormNonClientAreaInfo.BuildSystemMenu(ASysMenu: THandle);
begin
  LoadStandardMenu;
  DeleteMenu(ASysMenu, 0, MF_BYPOSITION);
  cxMoveMenuItems(GetSubMenu(SystemMenu, 0), ASysMenu);
  ModifySystemMenu(ASysMenu);
end;

procedure TdxSkinFormNonClientAreaInfo.DestroyStandardMenu;
begin
  if FSystemMenu <> 0 then
  begin
    DestroyMenu(FSystemMenu);
    FSystemMenu := 0;
  end;
end;

procedure TdxSkinFormNonClientAreaInfo.LoadStandardMenu;
const
  SysMenuTypes: array[Boolean] of TcxSystemMenuType = (smSystem, smChild);
begin
  DestroyStandardMenu;
  FSystemMenu := cxLoadSysMenu(SysMenuTypes[IsMDIChild]);
end;

procedure TdxSkinFormNonClientAreaInfo.ModifySystemMenu(ASysMenu: THandle);
var
  ABorderIcons: TBorderIcons;
begin
  if HasBorder then
  begin
    ABorderIcons := [];
    if Style and WS_SYSMENU <> 0 then
      Include(ABorderIcons, biSystemMenu);
    if Style and WS_MAXIMIZEBOX <> 0 then
      Include(ABorderIcons, biMaximize);
    if Style and WS_MINIMIZEBOX <> 0 then
      Include(ABorderIcons, biMinimize);
    if ExStyle and WS_EX_CONTEXTHELP <> 0 then
      Include(ABorderIcons, biHelp);
    cxModifySystemMenu(ASysMenu, Handle, IsDialog, ABorderIcons, WindowState, False);
  end;
end;

procedure TdxSkinFormNonClientAreaInfo.ResetSystemMenu;
begin
  GetSystemMenu(Handle, True); // Win2k redrawing bug
  if IsMDIChild then // #AI: for correct mdi buttons drawing on main menu bar
    BuildSystemMenu(GetSystemMenu(Handle, False));
end;

procedure TdxSkinFormNonClientAreaInfo.UpdateCaption(const ANewText: string);
begin
  FCaption := ANewText;
  if IsMDIChild then
    SkinHelper.ChildChanged(Handle);
end;

function TdxSkinFormNonClientAreaInfo.UpdateCaptionIconStates: Boolean;
begin
  Result := IconInfoList.CalculateStates(ClientCursorPos);
end;

function TdxSkinFormNonClientAreaInfo.GetContentRect: TRect;
begin
  Result := cxRectContent(WindowBounds, BorderWidths);
end;

function TdxSkinFormNonClientAreaInfo.GetBorderBounds(ASide: TcxBorder): TRect;
begin
  Result := FBorderBounds[ASide];
end;

function TdxSkinFormNonClientAreaInfo.GetButtonPressed: Boolean;
begin
  Result := GetMouseKeys and MK_LBUTTON = MK_LBUTTON;
end;

function TdxSkinFormNonClientAreaInfo.GetCaptionBounds: TRect;
begin
  Result := GetCaptionContentOffset;
  Result.Left := SkinBorderWidth[bLeft] + dxSkinIconSpacing;
  Result := cxRectContent(BorderBounds[bTop], Result);
  Inc(Result.Top, Byte(ToolWindow));
end;

function TdxSkinFormNonClientAreaInfo.GetCaptionContentOffset: TRect;
var
  ATopMargin: Integer;
begin
  if CaptionElement = nil then
    Result := cxNullRect
  else
    Result := CaptionElement.ContentOffset.Rect;

  if Assigned(CaptionElement) and Supressed and HasCaption then
  begin
    Result.Top := Trunc(Result.Top / SuppressFactor);
    Result.Bottom := Trunc(Result.Bottom / SuppressFactor);
    Result.Left := Trunc(Result.Left / SuppressFactor);
    Result.Right := Trunc(Result.Right / SuppressFactor);
  end;

  if IsZoomed then
  begin
    ATopMargin := Max(Result.Top, SizeFrame.cy);
    Result.Left := Max(Result.Left, SizeFrame.cx);
    Result.Right := Max(Result.Right, SizeFrame.cx);
    Result.Bottom := Max(0, Result.Bottom - (ATopMargin - Result.Top));
    Result.Top := ATopMargin;
  end;
end;

function TdxSkinFormNonClientAreaInfo.GetCaptionTextAreaOffset: TRect;
begin
  Result := Rect(GetCaptionContentOffset.Left, 0, dxSkinFormTextOffset, 0);
end;

function TdxSkinFormNonClientAreaInfo.GetCaptionElement: TdxSkinElement;
begin
  Result := PainterInfo.FormFrames[not ToolWindow, bTop];
end;

function TdxSkinFormNonClientAreaInfo.GetCaptionIconSize(AIcon: TdxSkinFormIcon): TSize;
begin
  if AIcon = sfiMenu then
    Result := CalculateMenuIconSize(ToolWindow)
  else
    Result := CalculateCaptionButtonSize(GetCaptionBounds,
      PainterInfo.FormIcons[not ToolWindow, AIcon]);
end;

function TdxSkinFormNonClientAreaInfo.GetCaptionTextColor: TColor;
begin
  Result := FCaptionTextColor[Active];
end;

function TdxSkinFormNonClientAreaInfo.GetHandle: HWND;
begin
  Result := Controller.Handle;
end;

function TdxSkinFormNonClientAreaInfo.GetClientCursorPos: TPoint;
begin
  Result := ScreenToClient(GetMouseCursorPos);
end;

function TdxSkinFormNonClientAreaInfo.GetClientRectOnClient: TRect;
begin
  Result := cxRectOffset(ClientRect, cxPointInvert(ClientRect.TopLeft));
end;

function TdxSkinFormNonClientAreaInfo.GetHasBorder: Boolean;
begin
  Result := (Style and WS_BORDER = WS_BORDER) or IsMDIChild and
    (SendMessage(Handle, DXM_SKINS_SUPPRESSMDICHILDBORDERS, 0, 0) = 0);
end;

function TdxSkinFormNonClientAreaInfo.GetHasCaption: Boolean;
begin
  Result := Style and WS_CAPTION = WS_CAPTION;
end;

function TdxSkinFormNonClientAreaInfo.GetHasCaptionTextShadow: Boolean;
begin
  Result := Active and not ToolWindow and (CaptionTextShadowColor <> clNone) and
    (CaptionTextShadowColor <> clDefault);
end;

function TdxSkinFormNonClientAreaInfo.GetHasClientEdge: Boolean;
begin
  Result := TdxSkinFormHelper.HasClientEdge(Handle);
end;

function TdxSkinFormNonClientAreaInfo.GetHasMenu: Boolean;
begin
  Result := FHasMenu;
end;

function TdxSkinFormNonClientAreaInfo.GetHasParent: Boolean;
begin
  Result := GetParent(Handle) <> 0;
end;

function TdxSkinFormNonClientAreaInfo.GetHasScrollsArea: Boolean;
begin
  Result :=
    ScrollBarsController.ScrollBarViewInfo[saeHorzScroll].Visible or
    ScrollBarsController.ScrollBarViewInfo[saeVertScroll].Visible;
end;

function TdxSkinFormNonClientAreaInfo.GetHasSizeConstraints: Boolean;
begin
  Result := False;
  if Assigned(Controller.Form) then
  begin
    with Controller.Form.Constraints do
      Result := (MaxHeight <> 0) or (MaxWidth <> 0);
  end;
end;

function TdxSkinFormNonClientAreaInfo.GetIsAlphaBlendUsed: Boolean;
begin
  Result := TdxSkinFormHelper.IsAlphaBlendUsed(Handle);
end;

function TdxSkinFormNonClientAreaInfo.GetIsChild: Boolean;
begin
  Result := Style and WS_CHILD = WS_CHILD;
end;

function TdxSkinFormNonClientAreaInfo.GetIsDialog: Boolean;
begin
  Result := ExStyle and WS_EX_DLGMODALFRAME = WS_EX_DLGMODALFRAME;
end;

function TdxSkinFormNonClientAreaInfo.GetIsIconic: Boolean;
begin
  Result := Style and WS_ICONIC = WS_ICONIC;
end;

function TdxSkinFormNonClientAreaInfo.GetIsSizeBox: Boolean;
begin
  Result := Style and WS_SIZEBOX = WS_SIZEBOX;
end;

function TdxSkinFormNonClientAreaInfo.GetIsZoomed: Boolean;
begin
  Result := Style and WS_MAXIMIZE = WS_MAXIMIZE;
end;

function TdxSkinFormNonClientAreaInfo.GetNeedCheckNonClientSize: Boolean;
begin
  Result := HasBorder and not (IsNativeBorderWidth(False) or
    IsZoomed and TdxSkinCustomFormController.IsMDIChildWindow(Handle));
end;

function TdxSkinFormNonClientAreaInfo.GetNonClientMetrics: TNonClientMetrics;
begin
  Result := dxSystemInfo.NonClientMetrics;
end;

function TdxSkinFormNonClientAreaInfo.GetScreenRect: TRect;
var
  AMonitor: TMonitor;
begin
  AMonitor := Screen.MonitorFromWindow(Handle);
  if AMonitor = nil then
    Result := Screen.WorkAreaRect
  else
    Result := AMonitor.WorkareaRect;
end;

function TdxSkinFormNonClientAreaInfo.GetScrollBarsController: TdxSkinFormScrollBarsController;
begin
  Result := Controller.ScrollBarsController;
end;

function TdxSkinFormNonClientAreaInfo.GetSizeArea(ASide: TcxBorder): TRect;
begin
  Result := WindowBounds;
  if ASide in [bLeft, bRight] then
    Inc(Result.Top, BorderWidths.Top);
  with SizeFrame do
    Result := GetBorderRect(ASide, Result, Rect(cx, cy, cx, cy));
end;

function TdxSkinFormNonClientAreaInfo.GetSizeCorners(
  ACorner: TdxSkinFormCorner): TRect;
var
  ASize: TSize;
begin
  Result := WindowBounds;
  ASize := SizeFrame;
  if ACorner in [sfcLeftTop, sfcLeftBottom] then
    Result.Right := Result.Left + ASize.cx
  else
    Result.Left := Result.Right - ASize.cx;
  if ACorner in [sfcLeftTop, sfcRightTop] then
    Result.Bottom := Result.Top + BorderWidths.Top
  else
    Result.Top := Result.Bottom - ASize.cy;
end;

function TdxSkinFormNonClientAreaInfo.GetSkinBorderWidth(ASide: TcxBorder): Integer;
var
  AElement: TdxSkinElement;
begin
  Result := 0;
  AElement := PainterInfo.FormFrames[not ToolWindow, ASide];
  if Assigned(AElement) then
  begin
    if ASide in [bLeft, bRight] then
      Result := Max(AElement.Size.cx, AElement.MinSize.Width)
    else
      Result := Max(AElement.Size.cy, AElement.MinSize.Height);
  end;
end;

function TdxSkinFormNonClientAreaInfo.GetSuppressFactor: Single;
var
  ACaptionHeight: Integer;
begin
  ACaptionHeight := CalculateCaptionHeight - CalculateCaptionContentHeight;
  if not (HasCaption and Supressed) or (ACaptionHeight <= 0) then
    Result := 1
  else
    Result := Max(1, cxMarginsHeight(CaptionElement.ContentOffset.Rect)) / ACaptionHeight;
end;

function TdxSkinFormNonClientAreaInfo.GetSystemBorderWidths: TRect;
begin
  Result := cxRect(SystemSizeFrame.cx, SystemSizeFrame.cy, SystemSizeFrame.cx, SystemSizeFrame.cy);
  if HasCaption then
    Inc(Result.Top, GetSystemMetrics(IfThen(ToolWindow, SM_CYSMCAPTION, SM_CYCAPTION)));
end;

function TdxSkinFormNonClientAreaInfo.GetSystemSizeFrame: TSize;
begin
  Result := cxNullSize;
  if HasBorder then
  begin
    Result := cxSize(GetSystemMetrics(SM_CXSIZEFRAME), GetSystemMetrics(SM_CYSIZEFRAME));
    if not IsSizeBox then
    begin
      Dec(Result.cx, NonClientMetrics.iBorderWidth);
      Dec(Result.cy, NonClientMetrics.iBorderWidth);
    end;
  end;
end;

function TdxSkinFormNonClientAreaInfo.GetThemeActive: Boolean;
begin
  if not ThemeActiveAssigned then
  begin
    FThemeActive := IsThemeActive;
    ThemeActiveAssigned := True;
  end;
  Result := FThemeActive;
end;

function TdxSkinFormNonClientAreaInfo.GetToolWindow: Boolean;
begin
  Result := ExStyle and WS_EX_TOOLWINDOW = WS_EX_TOOLWINDOW;
end;

function TdxSkinFormNonClientAreaInfo.GetWindowState: TWindowState;
begin
  Result := wsNormal;
  if IsZoomed then
    Result := wsMaximized;
  if IsIconic then
    Result := wsMinimized;
end;

procedure TdxSkinFormNonClientAreaInfo.SetActive(AActive: Boolean);
begin
  if FActive <> AActive then
  begin
    FActive := AActive;
    UpdateCaptionIconStates;
  end;
end;

procedure TdxSkinFormNonClientAreaInfo.SetSizeType(AValue: Integer);
begin
  if FSizeType <> AValue then
  begin
    if SizeType = SIZE_MAXIMIZED then
    begin
      if IsMDIChild then
        ResetSystemMenu;
      Controller.CheckWindowRgn;
    end;
    FSizeType := AValue;
  end;
end;

procedure TdxSkinFormNonClientAreaInfo.SetUpdateRgn(ARgn: HRGN);
begin
  if FUpdateRgn <> 0 then
    DeleteObject(FUpdateRgn);
  FUpdateRgn := ARgn;
  if FUpdateRgn <> 0 then
    OffsetRgn(FUpdateRgn, -WindowRect.Left, -WindowRect.Top);
end;

procedure TdxSkinFormNonClientAreaInfo.UpdateFormCaption;
begin
  UpdateCaption(GetWindowCaption(Handle));
end;

{ TdxSkinFormScrollBarPartViewInfo }

constructor TdxSkinFormScrollBarPartViewInfo.Create(
  AOwner: TdxSkinFormScrollBarViewInfo; AKind: TcxScrollBarPart);
begin
  inherited Create;
  FKind := AKind;
  FOwner := AOwner;
  FVisible := True;
end;

procedure TdxSkinFormScrollBarPartViewInfo.Calculate(APos1, APos2: Integer; AState: Integer);

  function IsPartPressed: Boolean;
  begin
    Result := (AState and STATE_SYSTEM_PRESSED <> 0) or
      (Self = Owner.Controller.PressedPart) and
      (Owner.Controller.IsTracking or (Self = Owner.Controller.HotPart));
  end;

  function CalculatePartBounds: TRect;
  begin
    Result := Owner.Bounds;
    if (APos1 <> APos2) and (APos1 <> -1) then
    begin
      if Owner.Kind = saeHorzScroll then
        Result := cxRectSetXPos(Result, APos1, APos2)
      else
        Result := cxRectSetYPos(Result, APos1, APos2);
    end;
  end;

  function CalculatePartState: TcxButtonState;
  begin
    if IsPartPressed then
      Result := cxbsPressed
    else
      if AState and STATE_SYSTEM_UNAVAILABLE <> 0 then
        Result := cxbsDisabled
      else
        if (AState and STATE_SYSTEM_HOTTRACKED <> 0) or (Self = Owner.Controller.HotPart) then
          Result := cxbsHot
        else
          Result := cxbsNormal;
  end;

begin
  FVisible := AState and STATE_SYSTEM_INVISIBLE = 0;
  if Visible then
  begin
    FBounds := CalculatePartBounds;
    FState := CalculatePartState;
  end
  else
  begin
    FState := cxbsDefault;
    FBounds := cxNullRect;
  end;
end;

{ TdxSkinFormScrollBarViewInfo }

constructor TdxSkinFormScrollBarViewInfo.Create(
  AKind: TdxSkinFormScrollBar; AController: TdxSkinFormScrollBarsController);
var
  APart: TcxScrollBarPart;
begin
  inherited Create;
  FKind := AKind;
  FController := AController;
  for APart := Low(TcxScrollBarPart) to High(TcxScrollBarPart) do
    FParts[APart] := TdxSkinFormScrollBarPartViewInfo.Create(Self, APart);
end;

destructor TdxSkinFormScrollBarViewInfo.Destroy;
var
  APart: TcxScrollBarPart;
begin
  for APart := Low(TcxScrollBarPart) to High(TcxScrollBarPart) do
    FreeAndNil(FParts[APart]);
  inherited Destroy;
end;

procedure TdxSkinFormScrollBarViewInfo.CalculatePart(APos1, APos2: Integer; APart: TcxScrollBarPart);
const
  PartToStateIndex: array[TcxScrollBarPart] of Integer = (0, 1, 5, 3, 2, 4);
begin
  PartViewInfo[APart].Calculate(APos1, APos2, Info.rgState[PartToStateIndex[APart]]);
end;

procedure TdxSkinFormScrollBarViewInfo.CalculateParts;
var
  R: TRect;
begin
  if Visible then
  begin
    R := Bounds;
    if Kind = saeVertScroll then
      R := cxRectSetXPos(R, R.Top, R.Bottom);

    CalculatePart(R.Left, R.Left + Info.dxyLineButton, sbpLineUp);
    CalculatePart(R.Right - Info.dxyLineButton, R.Right, sbpLineDown);
    CalculatePart(R.Left + Info.xyThumbTop, R.Left + Info.xyThumbBottom, sbpThumbnail);
    CalculatePart(R.Left + Info.dxyLineButton, R.Left + Info.xyThumbTop, sbpPageUp);
    CalculatePart(R.Left + Info.xyThumbBottom, R.Right - Info.dxyLineButton, sbpPageDown);
  end;
end;

function TdxSkinFormScrollBarViewInfo.HitTest(
  const P: TPoint; out APart: TdxSkinFormScrollBarPartViewInfo): Boolean;
var
  APartItem: TcxScrollBarPart;
begin
  Result := Visible and PtInRect(Bounds, P);
  if Result then
  begin
    for APartItem := Low(TcxScrollBarPart) to High(TcxScrollBarPart) do
    begin
      Result := PartViewInfo[APartItem].Visible and PtInRect(PartViewInfo[APartItem].Bounds, P);
      if Result then
      begin
        APart := PartViewInfo[APartItem];
        Break;
      end;
    end;
  end;
end;

function TdxSkinFormScrollBarViewInfo.GetPartViewInfo(APart: TcxScrollBarPart): TdxSkinFormScrollBarPartViewInfo;
begin
  Result := FParts[APart];
end;

{ TdxSkinController }

constructor TdxSkinController.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  if dxSkinControllersList <> nil then
    dxSkinControllersList.Add(Self);
  Refresh;
end;

destructor TdxSkinController.Destroy;
begin
  Refresh;
  if dxSkinControllersList <> nil then
    dxSkinControllersList.Remove(Self);
  inherited Destroy;
end;

procedure TdxSkinController.Refresh(AControl: TWinControl = nil);
begin
  RefreshControllers(AControl);
end;

class function TdxSkinController.GetFormSkin(AForm: TCustomForm; var ASkinName: string): Boolean;
var
  AController: TdxSkinWinController;
begin
  AController := SkinnedControlsControllers.GetControllerByControl(AForm);
  Result := (AController <> nil) and (AController.LookAndFeelPainter <> nil);
  if Result then
    ASkinName := AController.LookAndFeelPainter.LookAndFeelName;
end;

procedure TdxSkinController.FullRefresh;
begin
  RootLookAndFeel.Refresh;
  Refresh;
end;

procedure TdxSkinController.DoPopupSystemMenu(AForm: TCustomForm; ASysMenu: HMENU);
begin
  if Assigned(AForm) then
  begin
    if Assigned(OnPopupSysMenu) then
      OnPopupSysMenu(Self, AForm, ASysMenu);
  end;
end;

procedure TdxSkinController.DoSkinControl(AControl: TWinControl; var AUseSkin: Boolean);
begin
  if Assigned(OnSkinControl) then
    OnSkinControl(Self, AControl, AUseSkin);
end;

procedure TdxSkinController.DoSkinForm(AForm: TCustomForm; var ASkinName: string; var AUseSkin: Boolean);
begin
  if Assigned(OnSkinForm) then
    OnSkinForm(Self, AForm, ASkinName, AUseSkin);
end;

procedure TdxSkinController.Loaded;
begin
  inherited Loaded;
  Refresh;
end;

procedure TdxSkinController.MasterLookAndFeelChanged(Sender: TcxLookAndFeel; AChangedValues: TcxLookAndFeelValues);
begin
  inherited MasterLookAndFeelChanged(Sender, AChangedValues);
  Refresh;
end;

procedure TdxSkinController.MasterLookAndFeelDestroying(Sender: TcxLookAndFeel);
begin
  inherited MasterLookAndFeelDestroying(Sender);
  Refresh;
end;

function TdxSkinController.GetUseImageSet: TdxSkinImageSet;
begin
  Result := dxSkinsUseImageSet;
end;

function TdxSkinController.GetUseSkins: Boolean;
begin
  Result := cxUseSkins;
end;

procedure TdxSkinController.SetUseImageSet(AValue: TdxSkinImageSet);
begin
  if AValue <> dxSkinsUseImageSet then
  begin
    dxSkinsUseImageSet := AValue;
    if UseSkins then
      FullRefresh;
  end;
end;

procedure TdxSkinController.SetUseSkins(Value: Boolean);
begin
  if Value <> UseSkins then
  begin
    cxUseSkins := Value;
    FullRefresh;
  end;
end;

{ TdxSkinCustomFormController }

constructor TdxSkinCustomFormController.Create(AHandle: HWND);
begin
  inherited Create(AHandle);
  FViewInfo := TdxSkinFormNonClientAreaInfo.Create(Self);
  FPainter := TdxSkinFormPainter.Create(FViewInfo);
  if IsMessageDlgWindow(AHandle) then
    PostMessage(AHandle, DXM_SKINS_POSTMSGFORMINIT, 0, 0);
  FScrollBarsController := TdxSkinFormScrollBarsController.Create(Self);
end;

constructor TdxSkinCustomFormController.CreateEx(ASkinForm: TdxSkinForm);
begin
  FSkinForm := ASkinForm;
  Create(ASkinForm.Handle);
end;

destructor TdxSkinCustomFormController.Destroy;
begin
  Handle := 0;
  cxClearObjectLinks(Self);
  FreeAndNil(FScrollBarsController);
  FreeAndNil(FPainter);
  FreeAndNil(FViewInfo);
  inherited Destroy;
end;

function TdxSkinCustomFormController.NCMouseDown(const P: TPoint): Boolean;
begin
  Result := True;
  IconsInfo.MouseDown(P);
  ScrollBarsController.MouseDown(P);
end;

function TdxSkinCustomFormController.NCMouseUp(const P: TPoint): Boolean;
var
  APressedIcon: TdxSkinFormIconInfo;
begin
  ScrollBarsController.MouseUp(P);
  IconsInfo.MouseUp(P, APressedIcon);
  RefreshOnMouseEvent(True);
  Result := Assigned(APressedIcon);
  if Result and APressedIcon.Enabled then
    SendMessage(Handle, WM_SYSCOMMAND, APressedIcon.Command, 0);
end;

procedure TdxSkinCustomFormController.RefreshController;
begin
  inherited RefreshController;
  ViewInfo.UpdateFormCaption;
end;

procedure TdxSkinCustomFormController.Refresh;
begin
  inherited Refresh;
  if Assigned(Painter) then
    Painter.FlushCache;
  if Handle <> 0 then
  begin
    if UseSkin then
    begin
      UpdateViewInfoState;
      CalculateViewInfo;
      CheckWindowRgn;
    end
    else
      FlushWindowRgn(False);
  end;
end;

procedure TdxSkinCustomFormController.UnHookWndProc;
begin
  if IsHooked then
    ViewInfo.BuildSystemMenu(GetSystemMenu(Handle, False));
  inherited UnHookWndProc;
end;

procedure TdxSkinCustomFormController.UpdateViewInfoState;
const
  WindowState: array[Boolean] of Integer = (0, SIZE_MAXIMIZED);
begin
  ViewInfo.SizeType := WindowState[ViewInfo.IsZoomed];
  ViewInfo.ResetSystemMenu;
  CheckWindowRgn;
end;

procedure TdxSkinCustomFormController.DefWndProc(var AMessage);
begin
  if SkinForm = nil then
    inherited DefWndProc(AMessage)
  else
    SkinForm.DefaultWndProc(TMessage(AMessage));
end;

procedure TdxSkinCustomFormController.DoPopupSystemMenu(AForm: TCustomForm; ASysMenu: HMENU);
var
  I: Integer;
begin
  for I := 0 to dxSkinControllersList.Count - 1 do
    dxSkinControllersList[I].DoPopupSystemMenu(AForm, ASysMenu);
end;

procedure TdxSkinCustomFormController.DrawWindowBackground(DC: HDC);
begin
  Painter.BeginPaint(DC);
  try
    Painter.DrawWindowBackground;
  finally
    Painter.EndPaint;
  end;
end;

procedure TdxSkinCustomFormController.DrawWindowBorder(DC: HDC = 0);
begin
  Painter.BeginPaint(DC);
  try
    Painter.DrawWindowBorder;
  finally
    Painter.EndPaint;
  end;
end;

procedure TdxSkinCustomFormController.DrawWindowScrollArea(DC: HDC = 0);
begin
  Painter.BeginPaint(DC);
  try
    Painter.DrawWindowScrollArea;
  finally
    Painter.EndPaint;
  end;
end;

procedure TdxSkinCustomFormController.CalculateViewInfo;
begin
  ViewInfo.Calculate(0);
end;

procedure TdxSkinCustomFormController.CheckWindowRgn;
var
  ARegion, AScreenRegion: HRGN;
begin
  if ViewInfo.HasBorder then
  begin
    ARegion := CreateRectRgnIndirect(ViewInfo.WindowBounds);
    if ViewInfo.IsZoomed and not (ViewInfo.HasSizeConstraints or ViewInfo.HasParent) then
    begin
      AScreenRegion := CreateRectRgnIndirect(
        cxRectOffset(ViewInfo.ScreenRect, ViewInfo.WindowRect.TopLeft, False));
      CombineRgn(ARegion, ARegion, AScreenRegion, RGN_AND);
      DeleteObject(AScreenRegion);
    end;
    SetWindowRgn(Handle, ARegion, True);
    HasRegion := True;
  end
  else
    FlushWindowRgn;
end;

procedure TdxSkinCustomFormController.FlushWindowRgn(ARedraw: Boolean = True);
begin
  if HasRegion then
  begin
    HasRegion := False;
    SetWindowRgn(Handle, 0, False);
    if ARedraw then
      PostRedraw;
  end;
end;

procedure TdxSkinCustomFormController.InitializeMessageForm;
var
  AForm: TCustomForm;
  AColor: TColor;
  I: Integer;
begin
  AForm := Form;
  AColor := Painter.FormContentTextColor;
  for I := AForm.ControlCount - 1 downto 0 do
    if AForm.Controls[I] is TCustomLabel then
    begin
      if AColor <> clDefault then
        TCustomLabelAccess(AForm.Controls[I]).Font.Color := AColor;
      TCustomLabelAccess(AForm.Controls[I]).Transparent := True;
    end;
end;

procedure TdxSkinCustomFormController.InvalidateBorders;
begin
  CalculateViewInfo;
  DrawWindowBorder;
end;

function TdxSkinCustomFormController.HandleInternalMessages(var AMessage: TMessage): Boolean;
begin
  Result := True;
  case AMessage.Msg of
    DXM_SKINS_CHILDCHANGED:
      begin
        ViewInfo.UpdateFormCaption;
        DrawWindowBorder;
      end;
    DXM_SKINS_POSTREDRAW:
      RedrawWindow(False);
    DXM_SKINS_POSTCHECKRGN:
      UpdateViewInfoState
  else
    Result := False;
  end;
end;

function TdxSkinCustomFormController.HandleWindowMessage(var AMessage: TMessage): Boolean;
begin
  Result := True;
  if ForceRedraw then
  begin
    DrawWindowBorder;
    ForceRedraw := False;
  end;
  case AMessage.Msg of
    WM_CONTEXTMENU:
      Result := WMContextMenu(TWMContextMenu(AMessage));
    WM_NCCALCSIZE:
      WMNCCalcSize(TWMNCCalcSize(AMessage));
    WM_NCMOUSEMOVE:
      WMNCMouseMove(TWMNCHitMessage(AMessage));
    WM_NCACTIVATE:
      WMNCActivate(TWMNCActivate(AMessage));
    WM_NCUAHDRAWFRAME, WM_NCUAHDRAWCAPTION, WM_SYNCPAINT:
      DrawWindowBorder;
    WM_NCLBUTTONDOWN, WM_NCLBUTTONDBLCLK:
      WMNCButtonDown(TWMNCHitMessage(AMessage));
    WM_NCLBUTTONUP:
      Result := NCMouseUp(ViewInfo.ClientCursorPos);
    WM_NCPAINT:
      WMNCPaint(TWMNCPaint(AMessage));
    WM_NCHITTEST:
      Result := WMNCHitTest(TWMNCHitTest(AMessage));
    WM_ERASEBKGND:
      WMEraseBkgnd(TWMEraseBkgnd(AMessage));
    WM_SYSMENU:
      WMSysMenu(AMessage);
    WM_SYSCOMMAND:
      WMSysCommand(TWMSysCommand(AMessage));
    WM_INITMENU:
      WMInitMenu(TWMInitMenu(AMessage));
    WM_ACTIVATE, WM_MOUSEACTIVATE:
      WMActivate(AMessage);
    WM_MOUSEMOVE:
      begin
        Result := ScrollBarsController.Scrolling;
        if Result then
          ScrollBarsController.MouseMove(ViewInfo.ClientCursorPos);
      end;
    WM_LBUTTONUP:
      begin
        Result := ScrollBarsController.Scrolling;
        if Result then
        begin
          ScrollBarsController.MouseUp(ViewInfo.ClientCursorPos);
          RefreshOnMouseEvent(True);
        end;
      end;
    $3F:
      begin
        DefWndProc(AMessage);
        Refresh;
      end;
    else
      Result := HandleInternalMessages(AMessage);
  end;
end;

function TdxSkinCustomFormController.IsHookAvailable: Boolean;
begin
  Result := inherited IsHookAvailable and (SkinForm = nil);
end;

procedure TdxSkinCustomFormController.LockRedraw;
begin
  Inc(FLockRedrawCount);
  if FLockRedrawCount = 1 then
    DefWindowProc(Handle, WM_SETREDRAW, 0, 0);
end;

procedure TdxSkinCustomFormController.UnlockRedraw;
begin
  Dec(FLockRedrawCount);
  if FLockRedrawCount = 0 then
    DefWindowProc(Handle, WM_SETREDRAW, 1, 0);
end;

procedure TdxSkinCustomFormController.PostRedraw;
begin
  PostMessage(Handle, DXM_SKINS_POSTREDRAW, 0, 0);
end;

function TdxSkinCustomFormController.RefreshOnMouseEvent(AForceRefresh: Boolean = False): Boolean;

  procedure DoBeginMouseTracking(const R: TRect);
  begin
    BeginMouseTracking(nil, ViewInfo.ClientToScreen(R), Self);
  end;

begin
  ScrollBarsController.MouseMove(ViewInfo.ClientCursorPos);
  Result := ViewInfo.UpdateCaptionIconStates;
  if Assigned(IconsInfo.IconHot) then
    DoBeginMouseTracking(IconsInfo.IconHot.Bounds)
  else
    if ScrollBarsController.HotPart <> nil then
    begin
      Result := not IsMouseTracking(Self);
      DoBeginMouseTracking(ScrollBarsController.HotPart.Bounds);
    end
    else
    begin
      Result := Result or IsMouseTracking(Self);
      EndMouseTracking(Self);
    end;

  if Result or AForceRefresh then
    InvalidateBorders;
end;

procedure TdxSkinCustomFormController.RefreshOnSystemMenuShown;
begin
  if IsWin2K or ViewInfo.IsNativeBorderWidth then
    PostRedraw;
end;

procedure TdxSkinCustomFormController.ShowSystemMenu(
  const P: TPoint; const AExcludeRect: TRect; ABottomAlign: Boolean);
const
  AlignMap: array[Boolean] of Integer = (TPM_TOPALIGN, TPM_BOTTOMALIGN);
var
  ACommand: LongWord;
  AParams: TTPMParams;
begin
  RefreshOnSystemMenuShown;
  ZeroMemory(@AParams, SizeOf(AParams));
  AParams.cbSize := SizeOf(AParams);
  AParams.rcExclude := AExcludeRect;
  ACommand := LongWord(TrackPopupMenuEx(GetSystemMenu(Handle, False),
    TPM_RETURNCMD or TPM_LEFTALIGN or AlignMap[ABottomAlign], P.X, P.Y, Handle, @AParams));
  PostMessage(Handle, WM_SYSCOMMAND, ACommand, 0);
end;

procedure TdxSkinCustomFormController.ShowSystemMenu(const P: TPoint);
begin
  ShowSystemMenu(P, cxNullRect);
end;

procedure TdxSkinCustomFormController.ShowSystemMenu;
var
  R: TRect;
begin
  if ViewInfo.IsIconic then
    R := ViewInfo.WindowRect
  else
  begin
    R := ViewInfo.ClientToScreen(ViewInfo.GetCaptionBounds);
    Inc(R.Bottom, ViewInfo.GetCaptionContentOffset.Bottom);
  end;
  ShowSystemMenu(Point(R.Left, R.Bottom),
    Rect(Screen.DesktopRect.Left, R.Top, Screen.DesktopRect.Right, R.Bottom),
    ViewInfo.IsIconic);
end;

procedure TdxSkinCustomFormController.AfterWndProc(var AMessage: TMessage);
begin
  case AMessage.Msg of
    WM_SETICON:
      InvalidateNC;
    WM_PRINT:
      WMPrint(TWMPrint(AMessage));
    WM_SIZE:
      WMSize(TWMSize(AMessage));
    WM_WINDOWPOSCHANGED:
      WMWindowPosChanged(TWMWindowPosMsg(AMessage));
    WM_VSCROLL, WM_HSCROLL:
      RedrawWindow(True);
    WM_DESTROY, WM_MDIDESTROY:
      if AMessage.WParam = 0 then
      begin
        FLookAndFeelPainter := nil;
        UnHookWndProc;
      end;
  end;
end;

procedure TdxSkinCustomFormController.BeforeWndProc(var AMessage: TMessage);
begin
  case AMessage.Msg of
    WM_PAINT:
      WMPaint(TWMPaint(AMessage));
    WM_EXITMENULOOP, WM_QUERYOPEN:
      ViewInfo.ResetSystemMenu;
    WM_SHOWWINDOW:
      PostRedraw;
    WM_NCCREATE:
      begin
        FlushWindowRgn;
        CalculateViewInfo;
      end;
  end;
end;

procedure TdxSkinCustomFormController.WMActivate(var Message: TMessage);
var
  AObjectLink: TcxObjectLink;
begin
  AObjectLink := cxAddObjectLink(Self);
  try
    DefWndProc(Message);
    if Assigned(AObjectLink.Ref) then
      DrawWindowBorder;
  finally
    cxRemoveObjectLink(AObjectLink);
  end;
end;

function TdxSkinCustomFormController.WMContextMenu(var Message: TWMContextMenu): Boolean;
begin
  case ViewInfo.GetHitTest(SmallPointToPoint(Message.Pos)) of
    HTCAPTION, HTSYSMENU:
      begin
        Result := True;
        ShowSystemMenu(SmallPointToPoint(Message.Pos));
        Message.Result := 0;
      end;
    else
      Result := False;
  end;
end;

procedure TdxSkinCustomFormController.WMEraseBkgnd(var Message: TWMEraseBkgnd);

  function NeedExcludeOpaqueChildren: Boolean;
  begin
    Result := not (cxIsDrawToMemory(Message) or
      (Form <> nil) and (csPaintCopy in Form.ControlState));
  end;

var
  ASaveIndex: Integer;
begin
  if Message.DC <> 0 then
  begin
    ASaveIndex := SaveDC(Message.DC);
    try
      if NeedExcludeOpaqueChildren then
        ExcludeOpaqueChildren(Form, Message.DC);
      DrawWindowBackground(Message.DC);
      Message.Result := 1;
    finally
      RestoreDC(Message.DC, ASaveIndex);
    end;
  end;
end;

procedure TdxSkinCustomFormController.WMInitMenu(var Message: TWMInitMenu);
var
  AStyles: Integer;
begin
  Message.Menu := GetSystemMenu(Handle, False);
  AStyles := dxSetWindowStyle(Handle, WS_VISIBLE, soSubtract);
  try
    ViewInfo.BuildSystemMenu(Message.Menu);
    DoPopupSystemMenu(Form, Message.Menu);
    DefWndProc(Message);
  finally
    dxSetWindowStyle(Handle, AStyles, soSet);
  end;
end;

procedure TdxSkinCustomFormController.WMNCActivate(var Message: TWMNCActivate);
var
  AChildForm: TCustomForm;
  AStyles: DWORD;
begin
  ViewInfo.Active := Message.Active;
  if ViewInfo.IsChild then
  begin
    AStyles := dxSetWindowStyle(Handle, WS_VISIBLE, soSubtract);
    Message.Result := DefWindowProc(Handle, WM_NCACTIVATE, TMessage(Message).WParam, 0);
    dxSetWindowStyle(Handle, AStyles, soSet);
  end
  else
    Message.Result := 1;

  AChildForm := TdxSkinFormHelper.GetActiveMDIChild(Handle);
  if Assigned(AChildForm) then
    AChildForm.Perform(WM_NCACTIVATE, TMessage(Message).WParam, 0);
  DrawWindowBorder;
end;

procedure TdxSkinCustomFormController.WMNCButtonDown(var Message: TWMNCHitMessage);
var
  ALink: TcxObjectLink;
begin
  ALink := cxAddObjectLink(Self);
  try
    ForceRedraw := True;
    NCMouseDown(ViewInfo.ClientCursorPos);

    if not (Message.HitTest in [HTHSCROLL, HTVSCROLL]) then
    begin
      if (IconsInfo.IconPressed = nil) or
         (IconsInfo.IconPressed.IconType = sfiMenu)
      then
        DefWndProc(Message);
    end;

    if Assigned(ALink.Ref) then
    begin
      RefreshOnMouseEvent(True);
      DrawWindowBorder;
    end;
  finally
    cxRemoveObjectLink(ALink);
  end;
  Message.Result := 0;
end;

procedure TdxSkinCustomFormController.WMNCMouseMove(var Message: TWMNCHitMessage);
begin
  if not RefreshOnMouseEvent then
  begin
    Message.HitTest := HTNOWHERE;
    DefWndProc(Message);
    DrawWindowBorder;
  end;
end;

procedure TdxSkinCustomFormController.WMNCCalcSize(var Message: TWMNCCalcSize);
var
  R: TRect;
begin
  R := Message.CalcSize_Params^.rgrc[0];
  DefWndProc(Message);
  CalculateViewInfo;
  if Message.CalcValidRects and ViewInfo.NeedCheckNonClientSize then
    Message.CalcSize_Params^.rgrc[0] := cxRectContent(R, ViewInfo.CalculateMargins);
end;

function TdxSkinCustomFormController.WMNCHitTest(var Message: TWMNCHitTest): Boolean;
begin
  Message.Result := ViewInfo.GetHitTest(SmallPointToPoint(Message.Pos), Message.Result);
  Result := (Message.Result <> HTNOWHERE) and (Message.Result <> HTSYSMENU);
end;

procedure TdxSkinCustomFormController.WMNCPaint(var Message: TWMNCPaint);
var
  AFrameRgn, AWindowRgn: HRgn;
begin
  InvalidateBorders;
  if ViewInfo.HasMenu or ViewInfo.IsMDIClient then
  begin
    AFrameRgn := ViewInfo.CreateDrawRgn;
    AWindowRgn := CreateRectRgnIndirect(ViewInfo.WindowRect);
    CombineRgn(AWindowRgn, AWindowRgn, AFrameRgn, RGN_XOR);
    DeleteObject(AFrameRgn);
    if Message.RGN <> 1 then
    begin
      CombineRgn(AWindowRgn, AWindowRgn, Message.RGN, RGN_AND);
      DeleteObject(Message.RGN);
    end;
    Message.RGN := AWindowRgn;
    DefWndProc(Message);
    DeleteObject(AWindowRgn);
  end;
  Message.RGN := 1;
  Message.Result := 0;
end;

procedure TdxSkinCustomFormController.WMPaint(var Message: TWMPaint);
begin
  ViewInfo.CalculateScrollArea;
  DrawWindowScrollArea;
end;

procedure TdxSkinCustomFormController.WMPrint(var Message: TWMPrint);
begin
  if (Message.Flags and PRF_CHECKVISIBLE = 0) or IsWindowVisible(Handle) then
  begin
    if Message.Flags and PRF_NONCLIENT <> 0 then
      DrawWindowBorder(Message.DC);
  end;
end;

procedure TdxSkinCustomFormController.WMSetText(var Message: TWMSetText);
begin
  DefWndProc(Message);
  ViewInfo.UpdateFormCaption;
  if UseSkin then
    InvalidateBorders;
end;

procedure TdxSkinCustomFormController.WMSize(var Message: TWMSize);
begin
  if ViewInfo.SizeType = SIZE_MAXIMIZED then
    PostRedraw;
  ViewInfo.SizeType := Message.SizeType;
end;

procedure TdxSkinCustomFormController.WMSysCommand(var Message: TWMSysCommand);
var
  ACommand: Integer;
  ALink: TcxObjectLink;
begin
  ALink := cxAddObjectLink(Self);
  try
    RefreshOnSystemMenuShown;
    ACommand := Message.CmdType and $FFF0;
    if (ACommand = SC_KEYMENU) and (Message.Key = $20) then
    begin
      LockWindowUpdate(Handle);
      DefWndProc(Message);
      LockWindowUpdate(0);
    end
    else
      DefWndProc(Message);
    if Assigned(ALink.Ref) then
      DrawWindowBorder;
  finally
    cxRemoveObjectLink(ALink);
  end;
end;

procedure TdxSkinCustomFormController.WMSysMenu(var Message: TMessage);
begin
  if IsWindowEnabled(Handle) then //B136020
  begin
    DoPopupSystemMenu(Form, Message.LParam);
    ShowSystemMenu(GetMouseCursorPos);
  end;
  Message.Result := 0;
end;

procedure TdxSkinCustomFormController.WMWindowPosChanged(var Message: TWMWindowPosChanged);
var
  AIsMoving: Boolean;
  AIsSizing: Boolean;
  ANeedRecalculateNC: Boolean;
begin
  AIsMoving := Message.WindowPos^.flags and SWP_NOMOVE = 0;
  AIsSizing := Message.WindowPos^.flags and SWP_NOSIZE = 0;
  ANeedRecalculateNC := AIsMoving and IsZoomed(Handle) and IsWindowVisible(Handle);
  if AIsSizing or ANeedRecalculateNC then
  begin
    if ANeedRecalculateNC then
      SetWindowPos(Handle, 0, 0, 0, 0, 0, SWP_FRAMECHANGED or SWP_NOSIZE or SWP_NOMOVE or SWP_NOZORDER);
    CalculateViewInfo;
    CheckWindowRgn;
  end;
end;

procedure TdxSkinCustomFormController.MouseLeave;
begin
  RefreshOnMouseEvent(True);
  UpdateWindow(Handle);
end;

function TdxSkinCustomFormController.GetForm: TCustomForm;
begin
  if SkinForm = nil then
    Result := TdxSkinFormHelper.GetForm(Handle)
  else
    Result := SkinForm;
end;

function TdxSkinCustomFormController.GetIconsInfo: TdxSkinFormIconInfoList;
begin
  Result := ViewInfo.IconInfoList;
end;

function TdxSkinCustomFormController.GetUseSkin: Boolean;
begin
  Result := inherited GetUseSkin and (ViewInfo <> nil);
end;

procedure TdxSkinCustomFormController.WndProc(var AMessage: TMessage);
begin
  case AMessage.Msg of
    WM_SETTEXT:
      WMSetText(TWMSetText(AMessage));
    WM_THEMECHANGED:
      ViewInfo.ThemeActiveAssigned := False;
    DXM_SKINS_POSTMSGFORMINIT:
      InitializeMessageForm;
  else
    if not UseSkin then
      DefWndProc(AMessage)
    else
      if not HandleWindowMessage(AMessage) then
      begin
        BeforeWndProc(AMessage);
        DefWndProc(AMessage);
        AfterWndProc(AMessage);
      end;
  end;
end;

{ TdxSkinFormIconInfo }

constructor TdxSkinFormIconInfo.Create(AType: TdxSkinFormIcon; AOwner: TdxSkinFormIconInfoList);
begin
  inherited Create;
  FOwner := AOwner;
  FIconType := AType;
end;

function TdxSkinFormIconInfo.CalculateState: TdxSkinElementState;
const
  PressedStateMap: array[Boolean] of TdxSkinElementState = (esHot, esPressed);
begin
  if (Owner.IconHot = Self) and Enabled then
    Result := PressedStateMap[(Owner.IconPressed = Self) and NonClientAreaInfo.ButtonPressed]
  else
    if NonClientAreaInfo.Active then
      Result := esNormal
    else
      Result := esActiveDisabled;
end;

function TdxSkinFormIconInfo.GetCommand: Integer;
const
  CommandMap: array[TdxSkinFormIcon] of Integer =
    (SC_DEFAULT, SC_CONTEXTHELP, SC_MINIMIZE, SC_MAXIMIZE, SC_RESTORE, SC_CLOSE);
begin
  Result := CommandMap[IconType];
end;

function TdxSkinFormIconInfo.GetEnabled: Boolean;
begin
  case IconType of
    sfiClose:
      Result := NonClientAreaInfo.GetIsMenuCommandEnabled(SC_CLOSE);
    sfiMinimize:
      Result := NonClientAreaInfo.Style and WS_MINIMIZEBOX = WS_MINIMIZEBOX;
    sfiMaximize:
      Result := NonClientAreaInfo.Style and WS_MAXIMIZEBOX = WS_MAXIMIZEBOX;
    else
      Result := True;
  end;
end;

function TdxSkinFormIconInfo.GetHitTest: Integer;
const
  HitTestMap: array[TdxSkinFormIcon] of Integer =
    (HTSYSMENU, HTHELP, HTMINBUTTON, HTMAXBUTTON, HTMAXBUTTON, HTCLOSE);
begin
  Result := HitTestMap[IconType];
end;

function TdxSkinFormIconInfo.GetNonClientAreaInfo: TdxSkinFormNonClientAreaInfo;
begin
  Result := Owner.NonClientAreaInfo;
end;

{ TdxSkinFormIconInfoList }

constructor TdxSkinFormIconInfoList.Create(ANonClientInfo: TdxSkinFormNonClientAreaInfo);
begin
  inherited Create;
  FNonClientAreaInfo := ANonClientInfo;
end;

function TdxSkinFormIconInfoList.Add(AIcon: TdxSkinFormIcon): TdxSkinFormIconInfo;
begin
  if not Find(AIcon, Result) then
  begin
    Result := TdxSkinFormIconInfo.Create(AIcon, Self);
    inherited Add(Result);
  end;
end;

function TdxSkinFormIconInfoList.CalculateStates(const P: TPoint): Boolean;
var
  AIconInfo: TdxSkinFormIconInfo;
  AState: TdxSkinElementState;
  I: Integer;
begin
  Result := False;
  FIconHot := HitTest(P);
  for I := 0 to Count - 1 do
  begin
    AIconInfo := Items[I];
    AState := AIconInfo.CalculateState;
    Result := Result or (AState <> AIconInfo.State);
    AIconInfo.State := AState;
  end;
end;

function TdxSkinFormIconInfoList.Find(
  AIcon: TdxSkinFormIcon; out AInfo: TdxSkinFormIconInfo): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count - 1 do
  begin
    Result := Items[I].IconType = AIcon;
    if Result then
    begin
      AInfo := Items[I];
      Break;
    end;
  end;
end;

function TdxSkinFormIconInfoList.HitTest(const P: TPoint): TdxSkinFormIconInfo;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
  begin
    if PtInRect(Items[I].HitBounds, P) then
    begin
      Result := Items[I];
      Break;
    end;
  end;
end;

function TdxSkinFormIconInfoList.HitTest(const P: TPoint; out AInfo: TdxSkinFormIconInfo): Boolean;
begin
  AInfo := HitTest(P);
  Result := Assigned(AInfo);
end;

procedure TdxSkinFormIconInfoList.MouseDown(const P: TPoint);
begin
  if not HitTest(P, FIconPressed) then
    FIconPressed := nil;
  CalculateStates(P);
end;

procedure TdxSkinFormIconInfoList.MouseUp(const P: TPoint; out AIcon: TdxSkinFormIconInfo);
begin
  if IconPressed = IconHot then
    AIcon := IconPressed
  else
    AIcon := nil;

  FIconPressed := nil;
  CalculateStates(P);
end;

procedure TdxSkinFormIconInfoList.Validate(const AIcons: TdxSkinFormIcons);
var
  I: Integer;
begin
  for I := Count - 1 downto 0 do
  begin
    if not (Items[I].IconType in AIcons) then
      FreeAndDelete(I);
  end;
end;

function TdxSkinFormIconInfoList.GetItem(Index: Integer): TdxSkinFormIconInfo;
begin
  Result := TdxSkinFormIconInfo(inherited Items[Index]);
end;

{ TdxSkinFrameController }

procedure TdxSkinFrameController.DrawWindowBackground(DC: HDC);
begin
  if not IsTransparent then
    inherited DrawWindowBackground(DC)
  else
  begin
    Painter.BeginPaint(DC);
    try
      cxDrawTransparentControlBackground(WinControl, cxPaintCanvas, ViewInfo.ClientBounds, False);
    finally
      Painter.EndPaint;
    end;
  end;
end;

function TdxSkinFrameController.GetIsTransparent: Boolean;
begin
  Result := Assigned(WinControl) and (csParentBackground in WinControl.ControlStyle);
end;

procedure TdxSkinFrameController.WMWindowPosChanged(var Message: TWMWindowPosMsg);
begin
  inherited WMWindowPosChanged(Message);
  if IsTransparent then
  begin
    if (Message.WindowPos^.flags and SWP_NOSIZE = 0) or
       (Message.WindowPos^.flags and SWP_NOMOVE = 0)
    then
      PostRedraw;
  end;
end;

{ TdxSkinFormScrollBarsController }

constructor TdxSkinFormScrollBarsController.Create(AController: TdxSkinCustomFormController);
var
  AScrollBar: TdxSkinFormScrollBar;
begin
  inherited Create;
  FController := AController;
  for AScrollBar := Low(TdxSkinFormScrollBar) to High(TdxSkinFormScrollBar) do
    FScrollBarViewInfo[AScrollBar] := TdxSkinFormScrollBarViewInfo.Create(AScrollBar, Self);
end;

destructor TdxSkinFormScrollBarsController.Destroy;
var
  AScrollBar: TdxSkinFormScrollBar;
begin
  FreeAndNil(FScrollTimer);
  for AScrollBar := Low(TdxSkinFormScrollBar) to High(TdxSkinFormScrollBar) do
    FreeAndNil(FScrollBarViewInfo[AScrollBar]);
  inherited Destroy;
end;

procedure TdxSkinFormScrollBarsController.CalculateDrawRegion(ARegion: HRGN);
begin
  if ScrollBarViewInfo[saeHorzScroll].Visible then
    ViewInfo.CombineRectWithRegion(ARegion, ScrollBarViewInfo[saeHorzScroll].Bounds);
  if ScrollBarViewInfo[saeVertScroll].Visible then
    ViewInfo.CombineRectWithRegion(ARegion, ScrollBarViewInfo[saeVertScroll].Bounds);
  if SizeGripVisible then
    ViewInfo.CombineRectWithRegion(ARegion, SizeGripBounds);
end;

procedure TdxSkinFormScrollBarsController.CalculateScrollArea;

  function DoGetScrollBarInfo(AScrollBar: TdxSkinFormScrollBar): TScrollBarInfo;
  const
    ScrollBarOBJIDs: array[TdxSkinFormScrollBar] of DWORD = (OBJID_HSCROLL, OBJID_VSCROLL);
  var
    AScrollInfo: TScrollInfo;
  begin
    ZeroMemory(@Result, SizeOf(TScrollBarInfo));
    Result.cbSize := SizeOf(TScrollBarInfo);
    if IsTracking and (ScrollBarViewInfo[AScrollBar] = PressedPart.Owner) then
    begin
      ZeroMemory(@AScrollInfo, SizeOf(AScrollInfo));
      AScrollInfo.cbSize := SizeOf(AScrollInfo);
      AScrollInfo.fMask := SIF_TRACKPOS or SIF_POS;
      GetScrollInfo(ViewInfo.Handle, Integer(AScrollBar), AScrollInfo);
      Controller.LockRedraw;
      try
        SetScrollPos(Controller.Handle, Integer(AScrollBar), AScrollInfo.nTrackPos, False);
        cxGetScrollBarInfo(Controller.Handle, Integer(ScrollBarOBJIDs[AScrollBar]), Result);
        SetScrollPos(Controller.Handle, Integer(AScrollBar), AScrollInfo.nPos, False);
      finally
        Controller.UnlockRedraw;
      end;
    end
    else
      cxGetScrollBarInfo(Controller.Handle, Integer(ScrollBarOBJIDs[AScrollBar]), Result);
  end;

  function GetScrollBarBounds(const R: TRect; AScrollBar: TdxSkinFormScrollBar): TRect;
  begin
    if AScrollBar = saeHorzScroll then
      Result := cxRectSetTop(R, R.Bottom, GetSystemMetrics(SM_CYHSCROLL))
    else
      Result := cxRectSetLeft(R, R.Right, GetSystemMetrics(SM_CXVSCROLL));
  end;

  function IsScrollBarVisible(AScrollBar: TdxSkinFormScrollBar): Boolean;
  const
    FlagsMap: array[TdxSkinFormScrollBar] of Integer = (WS_HSCROLL, WS_VSCROLL);
  begin
    Result := UsecxScrollBars and (ViewInfo.Style and FlagsMap[AScrollBar] <> 0) and
      not cxRectIsEmpty(ScrollBarViewInfo[AScrollBar].Info.rcScrollBar);
  end;

  procedure CalculaeScrollBarBounds(AScrollBar: TdxSkinFormScrollBar);
  begin
    ScrollBarViewInfo[AScrollBar].FInfo := DoGetScrollBarInfo(AScrollBar);
    ScrollBarViewInfo[AScrollBar].FVisible := IsScrollBarVisible(AScrollBar);
    ScrollBarViewInfo[AScrollBar].FBounds := GetScrollBarBounds(ViewInfo.ClientBounds, AScrollBar);
  end;

begin
  CalculaeScrollBarBounds(saeHorzScroll);
  CalculaeScrollBarBounds(saeVertScroll);
  if SizeGripVisible then
  begin
    ScrollBarViewInfo[saeHorzScroll].FBounds.Right := ScrollBarViewInfo[saeVertScroll].Bounds.Left;
    ScrollBarViewInfo[saeVertScroll].FBounds.Bottom := ScrollBarViewInfo[saeHorzScroll].Bounds.Top;
    FSizeGripBounds := cxRect(ViewInfo.ClientBounds.Right, ViewInfo.ClientBounds.Bottom,
      ScrollBarViewInfo[saeVertScroll].Bounds.Right, ScrollBarViewInfo[saeHorzScroll].Bounds.Bottom);
  end;
  ScrollBarViewInfo[saeHorzScroll].CalculateParts;
  ScrollBarViewInfo[saeVertScroll].CalculateParts;
end;

function TdxSkinFormScrollBarsController.CanScrollPage: Boolean;
begin
  Result := (PressedPart <> nil) and not
    PtInRect(PressedPart.Owner.PartViewInfo[sbpThumbnail].Bounds, ViewInfo.ClientCursorPos);
end;

procedure TdxSkinFormScrollBarsController.Click;
const
  PageCodes: array[Boolean] of Integer = (SB_PAGEUP, SB_PAGEDOWN);
begin
  Controller.LockRedraw;
  try
    case PressedPart.Kind of
      sbpLineDown:
        SendScrollMessage(SB_LINEDOWN);
      sbpLineUp:
        SendScrollMessage(SB_LINEUP);
      sbpPageDown, sbpPageUp:
        if CanScrollPage then
          SendScrollMessage(PageCodes[PressedPart.Kind = sbpPageDown]);
    end;
  finally
    Controller.UnlockRedraw;
    Controller.RedrawWindow(True);
  end;
end;

procedure TdxSkinFormScrollBarsController.MouseDown(const P: TPoint);
begin
  PressedPart := HitTest(P);
  if PressedPart <> nil then
  begin
    FScrolling := True;
    SetCapture(Controller.Handle);
    if PressedPart.Kind = sbpThumbnail then
      TrackingBegin(P)
    else
      StartScrollTimer;
    Click;
  end;
end;

procedure TdxSkinFormScrollBarsController.MouseMove(const P: TPoint);
begin
  if IsTracking then
    Tracking(P)
  else
    HotPart := HitTest(P);
end;

procedure TdxSkinFormScrollBarsController.MouseUp(const P: TPoint);
begin
  if Scrolling then
  begin
    StopScrollTimer;
    TrackingEnd(P);
    SendScrollMessage(SB_ENDSCROLL);
    ReleaseCapture;
    PressedPart := nil;
    FScrolling := False;
  end;
end;

function TdxSkinFormScrollBarsController.HitTest(const P: TPoint): TdxSkinFormScrollBarPartViewInfo;
begin
  if not HitTest(P, Result) then
    Result := nil;
end;

function TdxSkinFormScrollBarsController.HitTest(
  const P: TPoint; out AScrollBarPart: TdxSkinFormScrollBarPartViewInfo): Boolean;
var
  AItem: TdxSkinFormScrollBar;
begin
  for AItem := Low(AItem) to High(AItem) do
  begin
    Result := ScrollBarViewInfo[AItem].HitTest(P, AScrollBarPart);
    if Result then Break;
  end;
end;

procedure TdxSkinFormScrollBarsController.ScrollTimer(Sender: TObject);
begin
  if Scrolling then
  begin
    FScrollTimer.Interval := dxScrollInterval;
    if PtInRect(PressedPart.Bounds, ViewInfo.ClientCursorPos) then
      Click;
  end;
end;

procedure TdxSkinFormScrollBarsController.SendScrollMessage(AParam: WPARAM);
const
  MessageMap: array[TdxSkinFormScrollBar] of Integer = (WM_HSCROLL, WM_VSCROLL);
begin
  if PressedPart <> nil then
    SendMessage(Controller.Handle, MessageMap[PressedPart.Owner.Kind], AParam, 0);
end;

procedure TdxSkinFormScrollBarsController.StartScrollTimer;
begin
  if FScrollTimer = nil then
    FScrollTimer := TcxTimer.Create(nil);
  FScrollTimer.Interval := dxScrollInitialInterval;
  FScrollTimer.OnTimer := ScrollTimer;
end;

procedure TdxSkinFormScrollBarsController.StopScrollTimer;
begin
  FreeAndNil(FScrollTimer);
end;

procedure TdxSkinFormScrollBarsController.Tracking(const P: TPoint);

  function CalculateTrackDelta: Integer;
  begin
    if PressedPart.Owner.Kind = saeVertScroll then
      Result := P.Y - FTrackingLastPoint.Y
    else
      Result := P.X - FTrackingLastPoint.X;
  end;

begin
  FTrackPosition := FTrackPosition + CalculateTrackDelta * TrackingScale;
  FTrackPosition := Min(FTrackPosition, TrackingAreaInfo.nMax);
  FTrackPosition := Max(FTrackPosition, TrackingAreaInfo.nMin);
  TrackingSetThumbPosition(Trunc(FTrackPosition));
  Controller.InvalidateBorders;
  FTrackingLastPoint := P;
end;

procedure TdxSkinFormScrollBarsController.TrackingBegin(const P: TPoint);

  function GetFreeTrackBarSize: Integer;
  begin
    if TrackingScrollBarKind = saeVertScroll then
      Result :=
        cxRectHeight(PressedPart.Owner.PartViewInfo[sbpPageUp].Bounds) +
        cxRectHeight(PressedPart.Owner.PartViewInfo[sbpPageDown].Bounds)
    else
      Result :=
        cxRectWidth(PressedPart.Owner.PartViewInfo[sbpPageUp].Bounds) +
        cxRectWidth(PressedPart.Owner.PartViewInfo[sbpPageDown].Bounds);
  end;

begin
  FIsTracking := True;
  FTrackingLastPoint := P;

  ZeroMemory(@FTrackingAreaInfo, SizeOf(TScrollInfo));
  FTrackingAreaInfo.cbSize := SizeOf(TScrollInfo);
  FTrackingAreaInfo.fMask := SIF_ALL;
  GetScrollInfo(Controller.Handle, Integer(TrackingScrollBarKind), FTrackingAreaInfo);

  FTrackingScale := (TrackingAreaInfo.nMax - TrackingAreaInfo.nMin -
    Integer(TrackingAreaInfo.nPage)) / GetFreeTrackBarSize;
  FTrackPosition := TrackingAreaInfo.nPos;
end;

procedure TdxSkinFormScrollBarsController.TrackingEnd(const P: TPoint);
begin
  if IsTracking then
  begin
    Controller.LockRedraw;
    try
      TrackingSetThumbPosition(TrackingAreaInfo.nPos);
      SendScrollMessage(MakeLong(SB_THUMBPOSITION, Trunc(FTrackPosition)));
    finally
      Controller.UnlockRedraw;
    end;
    FIsTracking := False;
  end;
end;

procedure TdxSkinFormScrollBarsController.TrackingSetThumbPosition(APosition: Integer);
const
  ScrollBarsMap: array[TdxSkinFormScrollBar] of Integer = (SB_HORZ, SB_VERT);
begin
  SetScrollPos(Controller.Handle, ScrollBarsMap[TrackingScrollBarKind], APosition, False);
end;

function TdxSkinFormScrollBarsController.GetScrollBarViewInfo(
  AScrollBar: TdxSkinFormScrollBar): TdxSkinFormScrollBarViewInfo;
begin
  Result := FScrollBarViewInfo[AScrollBar];
end;

function TdxSkinFormScrollBarsController.GetSizeGripVisible: Boolean;
begin
  Result :=
    ScrollBarViewInfo[saeHorzScroll].Visible and
    ScrollBarViewInfo[saeVertScroll].Visible;
end;

function TdxSkinFormScrollBarsController.GetTrackingScrollBarKind: TdxSkinFormScrollBar;
begin
  if IsTracking then
    Result := PressedPart.Owner.Kind
  else
    raise EdxException.Create('GetTrackingScrollBarKind');
end;

function TdxSkinFormScrollBarsController.GetViewInfo: TdxSkinFormNonClientAreaInfo;
begin
  Result := Controller.ViewInfo;
end;

procedure TdxSkinFormScrollBarsController.SetHotPart(AValue: TdxSkinFormScrollBarPartViewInfo);
begin
  if FHotPart <> AValue then
  begin
    FHotPart := AValue;
    Controller.InvalidateBorders;
  end;
end;

procedure TdxSkinFormScrollBarsController.SetPressedPart(AValue: TdxSkinFormScrollBarPartViewInfo);
begin
  if FPressedPart <> AValue then
  begin
    FPressedPart := AValue;
    Controller.InvalidateBorders;
  end;
end;


function dxSkinCanSkinControl(AControl: TControl): Boolean;
var
  AHelper: IdxSkinSupport2;
begin
  if Supports(AControl, IdxSkinSupport2, AHelper) then
    Result := AHelper.IsSkinnable
  else
    Result := AControl <> nil;
end;

function dxSkinGetControllerClassForWindow(AWnd: HWND): TdxSkinWinControllerClass;
var
  AControl: TControl;
begin
  Result := nil;
  if TdxSkinWinController.IsMDIClientWindow(AWnd) then
    Result := TdxSkinFormMDIClientController
  else
  begin
    AControl := FindControl(AWnd);
    if dxSkinCanSkinControl(AControl) then
    begin
      if AControl is TCustomForm then
        Result := TdxSkinFormController;
      if AControl is TCustomFrame then
        Result := TdxSkinFrameController;
      if (AControl is TButton) and SameText(AControl.ClassName, 'TButton') then
        Result := TdxSkinButtonController;
      if (AControl is TPanel) and SameText(AControl.ClassName, 'TPanel') then
        Result := TdxSkinPanelController;
    end;
  end;
end;

procedure dxSkinsWndProcHook(ACode: Integer; wParam: WPARAM; lParam: LPARAM; var AHookResult: LRESULT);
var
  AMsg: PCWPStruct;
begin
  if IsDesigning then Exit;
  
  AMsg := PCWPStruct(lParam);
  case AMsg.message of
    WM_CHILDACTIVATE, WM_MDIACTIVATE:
      SkinHelper.ChildChanged(AMsg.hwnd);
    WM_CREATE, WM_MDICREATE:
      SkinHelper.InitializeEngine(AMsg.hwnd);
    DXM_SKINS_SETISSKINNED:
      SkinnedControlsControllers.Refresh(AMsg.hwnd);
    WM_DESTROY, WM_MDIDESTROY:
      if AMsg.wParam = 0 then
        SkinHelper.FinalizeEngine(AMsg.hwnd);
  end;
end;

var
  SetScrollInfo: function(hWnd: HWND; BarFlag: Integer;
    const ScrollInfo: TScrollInfo; Redraw: BOOL): Integer; stdcall;
  SetScrollPos: function (hWnd: HWND; nBar, nPos: Integer;
    bRedraw: BOOL): Integer stdcall;

function My_SetScrollPos(hWnd: HWND; nBar, nPos: Integer;
  bRedraw: BOOL): Integer; stdcall;
begin
  bRedraw := bRedraw and not TdxSkinWinController.IsSkinActive(hWnd);
  Result := SetScrollPos(hWnd, nBar, nPos, bRedraw);
end;

function My_SetScrollInfo(hWnd: HWND; BarFlag: Integer;
  const ScrollInfo: TScrollInfo; Redraw: BOOL): Integer; stdcall;
begin
  Redraw := Redraw and not TdxSkinWinController.IsSkinActive(hWnd);
  Result := SetScrollInfo(hWnd, BarFlag, ScrollInfo, Redraw);
end;

procedure RegisterAssistants;
begin
  SetScrollPos := FlatSB_SetScrollPos;
  SetScrollInfo := FlatSB_SetScrollInfo;
  FlatSB_SetScrollPos := My_SetScrollPos;
  FlatSB_SetScrollInfo := My_SetScrollInfo;
  dxSkinControllersList := TdxSkinControllersList.Create;
  SkinHelper := TdxSkinWinControllerHelper.Create;
  dxSetHook(htWndProc, dxSkinsWndProcHook);
  SkinnedControlsControllers := TdxSkinSkinnedControlsControllers.Create;
end;

procedure UnregisterAssistants;
begin
  FlatSB_SetScrollPos := SetScrollPos;
  FlatSB_SetScrollInfo := SetScrollInfo;
  dxReleaseHook(dxSkinsWndProcHook);
  SkinnedControlsControllers.Clear; // destroy all active controllers
  FreeAndNil(dxSkinControllersList);
  FreeAndNil(SkinnedControlsControllers);
  FreeAndNil(SkinHelper);
end;

{ TdxSkinControllersList }

function TdxSkinControllersList.CanSkinControl(AControl: TWinControl): Boolean;
var
  AController: TdxSkinController;
  I: Integer;
begin
  Result := AControl <> nil;
  if Result then
    for I := Count - 1 downto 0 do
    begin
      AController := Items[I];
      if not (csDestroying in AController.ComponentState) then
      begin
        AController.DoSkinControl(AControl, Result);
        if Result then Break;
      end;
    end;
end;

function TdxSkinControllersList.CanSkinForm(AForm: TCustomForm): TdxSkinLookAndFeelPainter;
var
  AController: TdxSkinController;
  ASkinName: string;
  AUseSkin: Boolean;
  I: Integer;
begin
  Result := nil;
  if AForm <> nil then
  begin
    AUseSkin := GetDefaultUseSkins;
    ASkinName := GetDefaultSkinName;
    for I := Count - 1 downto 0 do
    begin
      AController := Items[I];
      if not (csDestroying in AController.ComponentState) then
      begin
        AController.DoSkinForm(AForm, ASkinName, AUseSkin);
        if AUseSkin and GetSkinPainter(ASkinName, Result) then
          Break;
      end;
    end;
  end;
end;

function TdxSkinControllersList.GetSkinPainter(const AName: string; out APainter: TdxSkinLookAndFeelPainter): Boolean;
var
  ATempPainter: TcxCustomLookAndFeelPainter;
begin
  Result := cxLookAndFeelPaintersManager.GetPainter(AName, ATempPainter) and (ATempPainter is TdxSkinLookAndFeelPainter);
  if Result then
    APainter := TdxSkinLookAndFeelPainter(ATempPainter);
end;

function TdxSkinControllersList.GetDefaultSkinName: string;
begin
  Result := RootLookAndFeel.SkinName;
end;

function TdxSkinControllersList.GetDefaultUseSkins: Boolean;
begin
  Result := cxUseSkins and not RootLookAndFeel.NativeStyle;
end;

function TdxSkinControllersList.GetItem(Index: Integer): TdxSkinController;
begin
  Result := TdxSkinController(inherited Items[Index]);
end;

{ TdxSkinSkinnedControlsControllers }

procedure TdxSkinSkinnedControlsControllers.NotifyMasterDestroying(AMaster: TdxSkinWinController);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
  begin
    if Items[I].FMaster = AMaster then
      Items[I].FMaster := nil;
  end;
end;

procedure TdxSkinSkinnedControlsControllers.Refresh(AControl: TWinControl);
begin
  Refresh(GetControllerByControl(AControl));
end;

procedure TdxSkinSkinnedControlsControllers.Refresh(AHandle: HWND);
begin
  Refresh(GetControllerByHandle(AHandle));
end;

procedure TdxSkinSkinnedControlsControllers.Refresh(AMaster: TdxSkinWinController);
var
  AList: TdxSkinWinControllerList;
  I: Integer;
begin
  if AMaster <> nil then
  begin
    AList := TdxSkinWinControllerList.Create(False);
    try
      AList.Add(AMaster);
      for I := 0 to Count - 1 do
      begin
        if Items[I].Master = AMaster then
          AList.Add(Items[I]);
      end;
      AList.Refresh;
    finally
      AList.Free;
    end;
  end;
end;


{ TdxSkinWinController }

constructor TdxSkinWinController.Create(AHandle: HWND);
begin
  inherited Create;
  Handle := AHandle;
end;

destructor TdxSkinWinController.Destroy;
begin
  MasterDestroyed;
  EndMouseTracking(Self);
  Handle := 0;
  inherited Destroy;
end;

class function TdxSkinWinController.IsMDIChildWindow(AHandle: HWND): Boolean;
var
  AControl: TWinControl;
begin
  AControl := FindControl(AHandle);
  Result := (AControl is TCustomForm) and (TCustomFormAccess(AControl).FormStyle = fsMDIChild);
end;

class function TdxSkinWinController.IsMDIClientWindow(AHandle: HWND): Boolean;
begin
  Result := (AHandle <> 0) and AnsiSameText(cxGetClassName(AHandle), 'MDICLIENT');
end;

class function TdxSkinWinController.IsMessageDlgWindow(AHandle: HWND): Boolean;
var
  AWindowClass: string;
begin
  AWindowClass := cxGetClassName(AHandle);
  Result := SameText(AWindowClass, 'TMessageForm') or SameText(AWindowClass, 'TForm');
end;

class function TdxSkinWinController.IsSkinActive(AHandle: HWND): Boolean;
var
  AController: TdxSkinWinController;
begin
  AController := SkinnedControlsControllers.GetControllerByHandle(AHandle);
  Result := Assigned(AController) and AController.UseSkin;
end;

class procedure TdxSkinWinController.FinalizeEngine(AHandle: HWND);
var
  AController: TdxSkinWinController;
begin
  AController := SkinnedControlsControllers.GetControllerByHandle(AHandle);
  if (AController <> nil) and AController.CanFinalizeEngine then
    SkinnedControlsControllers.FreeAndRemove(AController);
end;

class procedure TdxSkinWinController.InitializeEngine(AHandle: HWND);
var
  AController: TdxSkinWinController;
begin
  AController := SkinnedControlsControllers.GetControllerByHandle(AHandle);
  if AController = nil then
  begin
    AController := SkinnedControlsControllers.GetControllerByControl(FindControl(AHandle));
    if AController <> nil then
      AController.Handle := AHandle
    else
    begin
      AController := Create(AHandle);
      SkinnedControlsControllers.Add(AController);
    end;
    AController.RefreshControllerAndUpdate;
  end;
end;

procedure TdxSkinWinController.InvalidateNC;
const
  Flags = SWP_FRAMECHANGED or SWP_NOACTIVATE or SWP_NOMOVE or SWP_NOSIZE or SWP_NOZORDER;
begin
  if Handle <> 0 then
    SetWindowPos(Handle, 0, 0, 0, 0, 0, Flags);
end;

procedure TdxSkinWinController.Refresh;
begin
  InvalidateNC;
end;

procedure TdxSkinWinController.RefreshController;
begin
  FMaster := FindMasterController;
  FLookAndFeelPainter := FindLookAndFeelPainter;
  FCanUseSkin := GetCanUseSkin;
end;

procedure TdxSkinWinController.RefreshControllerAndUpdate;
begin
  RefreshController;
  Update;
end;

procedure TdxSkinWinController.Update;
begin
  HookWndProc;
  Refresh;
  RedrawWindow(HasGraphicChildren);
end;

function TdxSkinWinController.CanFinalizeEngine: Boolean;
begin
  Result := True;
end;

function TdxSkinWinController.FindLookAndFeelPainter: TdxSkinLookAndFeelPainter;
begin
  Result := nil;
end;

function TdxSkinWinController.FindMasterController: TdxSkinWinController;
var
  AParentForm: TCustomForm;
begin
  Result := nil;
  if WinControl <> nil then
  begin
    AParentForm := GetParentForm(WinControl);
    if AParentForm <> nil then
      Result := SkinnedControlsControllers.GetControllerByHandle(AParentForm.Handle);
  end;
end;

function TdxSkinWinController.GetCanUseSkin: Boolean;
begin
  Result := dxSkinControllersList.CanSkinControl(WinControl);
end;

function TdxSkinWinController.GetUseSkin: Boolean;
begin
  Result := FCanUseSkin and (LookAndFeelPainter <> nil);
end;

function TdxSkinWinController.IsHookAvailable: Boolean;
begin
  Result := UseSkin;
end;

procedure TdxSkinWinController.DefWndProc(var AMessage);
begin
  if FWindowProcObject <> nil then
    FWindowProcObject.DefaultProc(TMessage(AMessage));
end;

procedure TdxSkinWinController.MasterDestroyed;
begin
  SkinnedControlsControllers.NotifyMasterDestroying(Self);
end;

procedure TdxSkinWinController.RedrawWindow(AUpdateNow: Boolean);
var
  AFlags: Integer;
const
  DefaultFlags = RDW_ERASE or RDW_INVALIDATE or RDW_FRAME or RDW_ALLCHILDREN;
begin
  if Handle = 0 then Exit;
  AFlags := DefaultFlags;
  if AUpdateNow then
    AFlags := AFlags or RDW_UPDATENOW;
  Windows.RedrawWindow(Handle, nil, 0, AFlags);
end;

procedure TdxSkinWinController.WndProc(var AMessage: TMessage);
begin
  DefWndProc(AMessage);
end;

procedure TdxSkinWinController.HookWndProc;
begin
  UnHookWndProc;
  if (Handle <> 0) and IsHookAvailable then
  begin
    if FWinControl = nil then
      FWindowProcObject := cxWindowProcController.Add(Handle, WndProc)
    else
      FWindowProcObject := cxWindowProcController.Add(FWinControl, WndProc);
  end;
end;

procedure TdxSkinWinController.UnHookWndProc;
begin
  if IsHooked then
    cxWindowProcController.Remove(FWindowProcObject);
end;

procedure TdxSkinWinController.MouseLeave;
begin
end;

function TdxSkinWinController.GetHasGraphicChildren: Boolean;
var
  I: Integer;
begin
  Result := False;
  if WinControl <> nil then
    for I := 0 to WinControl.ControlCount - 1 do
    begin
      Result := not (WinControl.Controls[I] is TWinControl);
      if Result then Break;
    end;
end;

function TdxSkinWinController.GetIsHooked: Boolean;
begin
  Result := (Handle <> 0) and Assigned(FWindowProcObject);
end;

function TdxSkinWinController.GetLookAndFeelPainter: TdxSkinLookAndFeelPainter;
begin
  Result := FLookAndFeelPainter;
  if Master <> nil then
    Result := Master.LookAndFeelPainter;
end;

procedure TdxSkinWinController.SetHandle(AHandle: HWND);
begin
  UnHookWndProc;
  FHandle := AHandle;
  FWinControl := FindControl(Handle);
  Update;
end;

{ TdxSkinWinControllerList }

function TdxSkinWinControllerList.GetControllerByControl(AControl: TWinControl): TdxSkinWinController;
var
  I: Integer;
begin
  Result := nil;
  if AControl <> nil then
  begin
    for I := 0 to Count - 1 do
      if Items[I].WinControl = AControl then
      begin
        Result := Items[I];
        Break;
      end;
  end;
end;

function TdxSkinWinControllerList.GetControllerByHandle(AHandle: HWND): TdxSkinWinController;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
    if Items[I].Handle = AHandle then
    begin
      Result := Items[I];
      Break;
    end;
end;

procedure TdxSkinWinControllerList.Refresh;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].RefreshController;
  for I := 0 to Count - 1 do
    Items[I].Update;
end;

function TdxSkinWinControllerList.GetItem(Index: Integer): TdxSkinWinController;
begin
  Result := TdxSkinWinController(inherited Items[Index]);
end;

{ TdxSkinWinControllerHelper }

constructor TdxSkinWinControllerHelper.Create;
begin
  FHandle := Classes.AllocateHWnd(WndProc);
end;

destructor TdxSkinWinControllerHelper.Destroy;
begin
  Classes.DeallocateHWnd(FHandle);
  inherited Destroy;
end;

procedure TdxSkinWinControllerHelper.ChildChanged(AHandle: HWND);
begin
  AHandle := GetParent(AHandle);
  if TdxSkinWinController.IsMDIClientWindow(AHandle) then
  begin
    AHandle := GetParent(AHandle);
    if AHandle <> 0 then
      PostMessage(AHandle, DXM_SKINS_CHILDCHANGED, 0, 0);
  end;
end;

procedure TdxSkinWinControllerHelper.FinalizeEngine(AHandle: HWND);
begin
  TdxSkinWinController.FinalizeEngine(AHandle);
  SkinHelper.ChildChanged(AHandle);
end;

procedure TdxSkinWinControllerHelper.InitializeEngine(AHandle: HWND);
begin
  if SendMessage(AHandle, DXM_SKINS_HASOWNSKINENGINE, 0, 0) = 0 then
  begin
    if {$IFNDEF DELPHI12} IsWindowUnicode(AHandle) or {$ENDIF} // note: try to detect TntControls
      TdxSkinWinController.IsMDIClientWindow(AHandle)
    then
      PostMessage(SkinHelper.Handle, DXM_SKINS_POSTCREATE, 0, AHandle)
    else
      InternalInitializeEngine(AHandle);
  end;
end;

procedure TdxSkinWinControllerHelper.InternalInitializeEngine(AHandle: HWND);

  function IsAnotherApplicatonWindow(AWnd: HWND): Boolean;
  var
    AProcessId: Cardinal;
  begin
    GetWindowThreadProcessId(AWnd, @AProcessId);
    Result := (AWnd = 0) or (AProcessId <> GetCurrentProcessId);
  end;

  function GetSkinClassForWindow(AWnd: HWND): TdxSkinWinControllerClass;
  begin
    Result := nil;
    if not IsAnotherApplicatonWindow(AWnd) then
      Result := dxSkinGetControllerClassForWindowProc(AWnd);
  end;

var
  ASkinClass: TdxSkinWinControllerClass;
begin
  ASkinClass := GetSkinClassForWindow(AHandle);
  if ASkinClass <> nil then
  begin
    ASkinClass.InitializeEngine(AHandle);
    PostMessage(AHandle, DXM_SKINS_POSTCHECKRGN, 0, 0);
  end;
end;

procedure TdxSkinWinControllerHelper.WndProc(var AMsg: TMessage);
begin
  if AMsg.Msg = DXM_SKINS_POSTCREATE then
    InternalInitializeEngine(AMsg.LParam)
  else
    AMsg.Result := DefWindowProc(Handle, AMsg.Msg, AMsg.WParam, AMsg.LParam);
end;

{ TdxSkinFormPainter }

constructor TdxSkinFormPainter.Create(AViewInfo: TdxSkinFormNonClientAreaInfo);
begin
  inherited Create;
  FViewInfo := AViewInfo;
  CreateCacheInfos;
end;

destructor TdxSkinFormPainter.Destroy;
begin
  FreeCacheInfos;
  inherited Destroy;
end;

procedure TdxSkinFormPainter.CreateCacheInfos;
var
  AIcon: TdxSkinFormIcon;
  ASide: TcxBorder;
begin
  for ASide := Low(TcxBorder) to High(TcxBorder) do
    FBordersCache[ASide] := TdxSkinElementCache.Create;
  for AIcon := Low(TdxSkinFormIcon) to High(TdxSkinFormIcon) do
    FIconsCache[AIcon] := TdxSkinElementCache.Create;
  FBackgroundCache := TdxSkinElementCache.Create;
end;

procedure TdxSkinFormPainter.FreeCacheInfos;
var
  AIcon: TdxSkinFormIcon;
  ASide: TcxBorder;
begin
  for ASide := Low(TcxBorder) to High(TcxBorder) do
    FreeAndNil(FBordersCache[ASide]);
  for AIcon := Low(TdxSkinFormIcon) to High(TdxSkinFormIcon) do
    FreeAndNil(FIconsCache[AIcon]);
  FreeAndNil(FBackgroundCache);
end;

procedure TdxSkinFormPainter.BeginPaint(ADestDC: HDC = 0);
const
  Flags = DCX_CACHE or DCX_CLIPSIBLINGS or DCX_WINDOW or DCX_VALIDATE;
begin
  FDC := ADestDC;
  FNeedRelease := ADestDC = 0;
  if FNeedRelease then
    FDC := GetDCEx(ViewInfo.Handle, 0, Flags);
  cxPaintCanvas.BeginPaint(FDC);
end;

procedure TdxSkinFormPainter.DrawClientOffsetArea;
var
  R: TRect;
begin
  if (ViewInfo.ClientOffset > 0) and not ViewInfo.IsIconic then
  begin
    cxPaintCanvas.SaveClipRegion;
    try
      R := ViewInfo.ContentRect;
      InflateRect(R, -ViewInfo.ClientOffset, -ViewInfo.ClientOffset);
      cxPaintCanvas.ExcludeClipRect(R);
      DrawBackground(cxPaintCanvas.Handle, ViewInfo.ContentRect);
    finally
      cxPaintCanvas.RestoreClipRegion;
    end;
  end;
end;

procedure TdxSkinFormPainter.DrawMDIClientEdgeArea;
begin
  if ViewInfo.IsMDIClient and ViewInfo.HasClientEdge then
  begin
    cxPaintCanvas.SaveClipRegion;
    try
      cxPaintCanvas.ExcludeClipRect(cxRectInflate(ViewInfo.WindowBounds,
        -ViewInfo.ClientEdgeSize.cx, -ViewInfo.ClientEdgeSize.cy));
      FormContent.Draw(cxPaintCanvas.Handle, ViewInfo.WindowBounds);
    finally
      cxPaintCanvas.RestoreClipRegion;
    end;
  end;
end;

procedure TdxSkinFormPainter.DrawMenuSeparator;
begin
  if ViewInfo.HasMenu and not ViewInfo.IsIconic then
    FillRect(cxPaintCanvas.Handle, ViewInfo.MenuSeparatorBounds, GetSysColorBrush(COLOR_MENU));
end;

procedure TdxSkinFormPainter.DrawWindowBackground;
var
  R: TRect;
begin
  if PainterInfo <> nil then
  begin
    cxPaintCanvas.SaveState;
    try
      R := cxRectOffset(ViewInfo.ClientRect, cxPointInvert(ViewInfo.WindowRect.TopLeft));
      MoveWindowOrg(cxPaintCanvas.Handle, -R.Left, -R.Top);
      DrawBackground(cxPaintCanvas.Handle, R);
    finally
      cxPaintCanvas.RestoreState;
    end;
  end;
end;

procedure TdxSkinFormPainter.DrawWindowBorder;
begin
  DrawMDIClientEdgeArea;
  DrawClientOffsetArea;
  InternalDrawCaption(ViewInfo.BorderBounds[bTop],
    PainterInfo.FormFrames[not ViewInfo.ToolWindow, bTop]);
  InternalDrawBorders;
  DrawMenuSeparator;
  DrawWindowScrollArea;
end;

procedure TdxSkinFormPainter.DrawWindowScrollArea;
begin
  if not ViewInfo.IsIconic and ViewInfo.HasScrollsArea then
    DrawScrollAreaElements;
end;

procedure TdxSkinFormPainter.EndPaint;
begin
  cxPaintCanvas.EndPaint;
  if FNeedRelease then
    ReleaseDC(ViewInfo.Handle, FDC);
end;

procedure TdxSkinFormPainter.DrawBackground(DC: HDC; const R: TRect);

  function DoIntersectClipRect(const R: TRect): Boolean;
  begin
    Result := IntersectClipRect(DC, R.Left, R.Top, R.Right, R.Bottom) <> NULLREGION;
  end;

var
  ASavedIndex: Integer;
begin
  ASavedIndex := SaveDC(DC);
  try
    if DoIntersectClipRect(ViewInfo.ContentRect) and DoIntersectClipRect(R) then
    begin
      if FormContent.Image.Empty then
        FormContent.Draw(DC, ViewInfo.ContentRect)
      else
        FBackgroundCache.DrawEx(DC, FormContent, ViewInfo.ContentRect);
    end;
  finally
    RestoreDC(DC, ASavedIndex);
  end;
end;

procedure TdxSkinFormPainter.DrawCaptionText(DC: HDC; R: TRect; const AText: string);
begin
{$IFDEF DELPHI12}
  cxDrawText(DC, AText, R, CaptionFlags);
{$ELSE}
  if not IsWinNT then
    cxDrawText(DC, AText, R, CaptionFlags)
  else
    DrawTextW(DC, PWideChar(dxStringToWideString(AText)), -1, R, CaptionFlags);
{$ENDIF}
end;

procedure TdxSkinFormPainter.DrawScrollAreaElements;
begin
  DrawScrollBar(ScrollBars.ScrollBarViewInfo[saeHorzScroll]);
  DrawScrollBar(ScrollBars.ScrollBarViewInfo[saeVertScroll]);
  if ScrollBars.SizeGripVisible then
    DrawSizeGrip(ScrollBars.SizeGripBounds);
end;

procedure TdxSkinFormPainter.DrawScrollBar(AScrollBar: TdxSkinFormScrollBarViewInfo);
var
  AMemBitmap: HBITMAP;
  AMemDC: HDC;
  APart: TcxScrollBarPart;
  R: TRect;
begin
  if AScrollBar.Visible then
  begin
    R := AScrollBar.Bounds;
    AMemDC := CreateCompatibleDC(0);
    try
      AMemBitmap := CreateCompatibleBitmap(cxPaintCanvas.Handle, cxRectWidth(R), cxRectHeight(R));
      AMemBitmap := SelectObject(AMemDC, AMemBitmap);
      SetWindowOrgEx(AMemDC, R.Left, R.Top, nil);
      cxPaintCanvas.BeginPaint(AMemDC);
      try
        DrawBackground(cxPaintCanvas.Handle, R);
        Painter.DrawScrollBarBackground(cxPaintCanvas, R, AScrollBar.Kind = saeHorzScroll);
        for APart := Low(TcxScrollBarPart) to High(TcxScrollBarPart) do
        begin
          if AScrollBar.PartViewInfo[APart].Visible then
            Painter.DrawScrollBarPart(cxPaintCanvas, AScrollBar.Kind = saeHorzScroll,
              AScrollBar.PartViewInfo[APart].Bounds, APart,
              AScrollBar.PartViewInfo[APart].State);
        end;
      finally
        cxPaintCanvas.EndPaint;
      end;
      cxBitBlt(cxPaintCanvas.Handle, AMemDC, R, R.TopLeft, SRCCOPY);
      AMemBitmap := SelectObject(AMemDC, AMemBitmap);
      DeleteObject(AMemBitmap);
    finally
      DeleteDC(AMemDC)
    end;
  end;
end;

procedure TdxSkinFormPainter.DrawSizeGrip(const R: TRect);
var
  B: TcxBitmap;
begin
  B := TcxBitmap.CreateSize(R);
  try
    B.cxCanvas.WindowOrg := R.TopLeft;
    DrawBackground(B.cxCanvas.Handle, R);
    Painter.DoDrawSizeGrip(B.cxCanvas, R);
    cxBitBlt(cxPaintCanvas.Handle, B.Canvas.Handle, R, R.TopLeft, SRCCOPY);
  finally
    B.Free;
  end;
end;

procedure TdxSkinFormPainter.DrawWindowCaption(
  DC: HDC; const R: TRect; AElement: TdxSkinElement);
var
  I: Integer;
begin
  DrawWindowCaptionBackground(DC, R, AElement);
  DrawWindowCaptionText(DC, ViewInfo.CaptionTextBounds);
  for I := 0 to ViewInfo.IconInfoList.Count - 1 do
    DrawWindowIcon(DC, ViewInfo.IconInfoList[I]);
end;

procedure TdxSkinFormPainter.DrawWindowCaptionBackground(DC: HDC;
  const R: TRect; AElement: TdxSkinElement);
var
  R1: TRect;
begin
  R1 := R;
  if ViewInfo.IsIconic then
  begin
    InternalDrawBorder(DC, R1, bBottom, ViewInfo.IsAlphaBlendUsed);
    Dec(R1.Bottom);
  end;
  FBordersCache[bTop].DrawEx(DC, dxSkinCheckSkinElement(AElement), R1,
    FrameStates[ViewInfo.Active]);
end;

procedure TdxSkinFormPainter.DrawWindowCaptionText(DC: HDC; R: TRect);
var
  APrevColor: TColor;
  APrevFont: HFONT;
  APrevTransparent: Integer;
begin
  if Length(ViewInfo.Caption) > 0 then
  begin
    APrevFont := SelectObject(DC, ViewInfo.CaptionFont.Handle);
    APrevTransparent := SetBkMode(DC, Transparent);
    if ViewInfo.HasCaptionTextShadow then
    begin
      APrevColor := SetTextColor(DC, ColorToRGB(ViewInfo.CaptionTextShadowColor));
      cxDrawText(DC, ViewInfo.Caption, R, CaptionFlags);
      SetTextColor(DC, APrevColor);
    end;
    OffsetRect(R, -1, -1);
    APrevColor := SetTextColor(DC, ColorToRGB(ViewInfo.CaptionTextColor));
    DrawCaptionText(DC, R, ViewInfo.Caption);
    SetBkMode(DC, APrevTransparent);
    SelectObject(DC, APrevFont);
    SetTextColor(DC, APrevColor);
  end;
end;

procedure TdxSkinFormPainter.DrawWindowIcon(DC: HDC; AIconInfo: TdxSkinFormIconInfo);
begin
  DrawWindowIcon(DC, AIconInfo.Bounds, AIconInfo.IconType,
    PainterInfo.FormIcons[not ViewInfo.ToolWindow, AIconInfo.IconType],
    AIconInfo.State);
end;

procedure TdxSkinFormPainter.DrawWindowIcon(DC: HDC; const R: TRect;
  AIcon: TdxSkinFormIcon; AElement: TdxSkinElement; AElementState: TdxSkinElementState);
begin
  if ((AIcon = sfiMenu) and (ViewInfo.SysMenuIcon = 0)) or
    ((AIcon <> sfiMenu) and (AElement = nil)) then Exit;

  if RectVisible(DC, R) then
  begin
    if AElement = nil then
      DrawIconEx(DC, R.Left, R.Top, ViewInfo.SysMenuIcon,
        R.Right - R.Left, R.Bottom - R.Top, 0, 0, DI_NORMAL)
    else
    begin
      FIconsCache[AIcon].CheckCacheState(AElement, R, AElementState, 0);
      FIconsCache[AIcon].Draw(DC, R);
    end;
  end;
end;

procedure TdxSkinFormPainter.FlushCache;
var
  AIcon: TdxSkinFormIcon;
  ASide: TcxBorder;
begin
  for ASide := Low(TcxBorder) to High(TcxBorder) do
    FBordersCache[ASide].Flush;
  for AIcon := Low(TdxSkinFormIcon) to High(TdxSkinFormIcon) do
    FIconsCache[AIcon].Flush;
  FBackgroundCache.Flush;
end;

procedure TdxSkinFormPainter.InternalDrawBorder(DC: HDC;
  const R: TRect; ASide: TcxBorder; AFillBackground: Boolean);

  function GetBorderRect(const R: TRect): TRect;
  begin
    Result := R;
    if IsBordersThin then
      case ASide of
        bLeft:
          Result.Right := Result.Left + ViewInfo.GetSkinBorderWidth(ASide);
        bRight:
          Result.Left := Result.Right - ViewInfo.GetSkinBorderWidth(ASide);
        bBottom:
          Result.Top := Result.Bottom - ViewInfo.GetSkinBorderWidth(ASide);
      end;
  end;

  procedure DrawBorderElement(DC: HDC; const R: TRect);
  begin
    FBordersCache[ASide].DrawEx(DC,
      PainterInfo.FormFrames[not ViewInfo.ToolWindow, ASide], R,
      FrameStates[Active]);
  end;

var
  ACachedDC: HDC;
  AMemBmp: HBitmap;
  R1: TRect;
begin
  if not AFillBackground then
    DrawBorderElement(DC, R)
  else
  begin
    R1 := R;
    OffsetRect(R1, -R1.Left, -R1.Top);
    ACachedDC := CreateCompatibleDC(DC);
    AMemBmp := CreateCompatibleBitmap(DC, R1.Right, R1.Bottom);
    AMemBmp := SelectObject(ACachedDC, AMemBmp);
    FormContent.Draw(ACachedDC, R1, 0, FrameStates[Active]);
    DrawBorderElement(ACachedDC, GetBorderRect(R1));
    BitBlt(DC, R.Left, R.Top, R1.Right, R1.Bottom, ACachedDC, 0, 0, SRCCOPY);
    AMemBMP := SelectObject(ACachedDC, AMemBmp);
    DeleteObject(AMemBmp);
    DeleteDC(ACachedDC);
  end;
end;

procedure TdxSkinFormPainter.InternalDrawBorders;
var
  AIsAlphaBlendUsed: Boolean;
  ASide: TcxBorder;
  R: TRect;
begin
  if IsBordersThin then
  begin
    InternalDrawThinBorders;
    Exit;
  end;

  AIsAlphaBlendUsed := ViewInfo.IsAlphaBlendUsed;
  for ASide := Low(TcxBorder) to High(TcxBorder) do
  begin
    R := ViewInfo.BorderBounds[ASide];
    if (ASide <> bTop) and IsRectVisible(R) and not cxRectIsEmpty(R) then
    begin
      if ASide in [bLeft, bRight] then
      begin
        R.Top := ViewInfo.BorderBounds[bTop].Bottom;
        R.Bottom := ViewInfo.BorderBounds[bBottom].Top;
      end;
      InternalDrawBorder(cxPaintCanvas.Handle, R, ASide, AIsAlphaBlendUsed);
    end;
  end;
end;

procedure TdxSkinFormPainter.InternalDrawCaption(const R: TRect; AElement: TdxSkinElement);
var
  ACachedDC: HDC;
  AMemBmp: HBitmap;
begin
  ACachedDC := CreateCompatibleDC(cxPaintCanvas.Handle);
  AMemBmp := CreateCompatibleBitmap(cxPaintCanvas.Handle, R.Right, R.Bottom);
  AMemBmp := SelectObject(ACachedDC, AMemBmp);
  DrawWindowCaption(ACachedDC, R, AElement);
  BitBlt(cxPaintCanvas.Handle, 0, 0, R.Right, R.Bottom, ACachedDC, 0, 0, SRCCOPY);
  AMemBMP := SelectObject(ACachedDC, AMemBmp);
  DeleteObject(AMemBmp);
  DeleteDC(ACachedDC);
end;

procedure TdxSkinFormPainter.InternalDrawThinBorders;
var
  ASide: TcxBorder;
  R: TRect;
begin
  InternalDrawBorder(cxPaintCanvas.Handle, ViewInfo.BorderBounds[bBottom], bBottom, True);
  for ASide := Low(TcxBorder) to High(TcxBorder) do
    if ASide in [bLeft, bRight] then
    begin
      R := ViewInfo.BorderBounds[ASide];
      if IsRectVisible(R) and not cxRectIsEmpty(R) then
      begin
        R.Top := ViewInfo.BorderBounds[bTop].Bottom;
        R.Bottom := ViewInfo.WindowBounds.Bottom - ViewInfo.SkinBorderWidth[bBottom];
        InternalDrawBorder(cxPaintCanvas.Handle, R, ASide, True);
      end;
    end;
end;

function TdxSkinFormPainter.IsRectVisible(const R: TRect): Boolean;
begin
  with FViewInfo do
    Result := (FUpdateRgn = 0) or RectInRegion(FUpdateRgn, R);
  if Result then
    Result := cxPaintCanvas.RectVisible(R);
end;

function TdxSkinFormPainter.GetActive: Boolean;
begin
  Result := ViewInfo.Active;
end;

function TdxSkinFormPainter.GetFormContent: TdxSkinElement;
begin
  Result := dxSkinCheckSkinElement(PainterInfo.FormContent);
end;

function TdxSkinFormPainter.GetFormContentTextColor: TColor;
begin
  if Painter <> nil then
    Result := Painter.DefaultContentTextColor
  else
    Result := clWindowText;
end;

function TdxSkinFormPainter.GetIconElement(AIcon: TdxSkinFormIcon): TdxSkinElement;
begin
  Result := PainterInfo.FormIcons[ViewInfo.ToolWindow, AIcon];
end;

function TdxSkinFormPainter.GetIsBordersThin: Boolean;
var
  ASide: TcxBorder;
begin
  Result := False;
  for ASide := Low(TcxBorder) to High(TcxBorder) do
    Result := Result or (ViewInfo.SkinBorderWidth[ASide] < 3);
end;

function TdxSkinFormPainter.GetPainter: TcxCustomLookAndFeelPainter;
begin
  Result := ViewInfo.Painter;
end;

function TdxSkinFormPainter.GetPainterInfo: TdxSkinLookAndFeelPainterInfo;
begin
  Result := ViewInfo.PainterInfo;
end;

function TdxSkinFormPainter.GetScrollBars: TdxSkinFormScrollBarsController;
begin
  Result := ViewInfo.ScrollBarsController;
end;

{ TdxSkinCustomControlViewInfo }

constructor TdxSkinCustomControlViewInfo.Create(AController: TdxSkinWinController);
begin
  FController := AController;
end;

procedure TdxSkinCustomControlViewInfo.DrawBackground(ACanvas: TcxCanvas);
var
  AControl: TWinControl;
begin
  AControl := Controller.WinControl;
  if AControl <> nil then
    cxDrawTransparentControlBackground(AControl, ACanvas, ClientRect);
end;

procedure TdxSkinCustomControlViewInfo.DrawContent(ACanvas: TcxCanvas);
begin
  // do nothing
end;

function TdxSkinCustomControlViewInfo.GetClientHeight: Integer;
begin
  Result := cxRectHeight(ClientRect);
end;

function TdxSkinCustomControlViewInfo.GetClientRect: TRect;
begin
  Result := cxGetWindowRect(Controller.Handle);
  OffsetRect(Result, -Result.Left, -Result.Top);
end;

function TdxSkinCustomControlViewInfo.GetClientWidth: Integer;
begin
  Result := cxRectWidth(ClientRect);
end;

function TdxSkinCustomControlViewInfo.GetIsEnabled: Boolean;
begin
  Result := IsWindowEnabled(Controller.Handle);
end;

function TdxSkinCustomControlViewInfo.GetIsFocused: Boolean;
begin
  Result := GetFocus = Controller.Handle;
end;

function TdxSkinCustomControlViewInfo.GetIsMouseAtControl: Boolean;
begin
  Result := Controller.Handle = WindowFromPoint(GetMouseCursorPos);
end;

function TdxSkinCustomControlViewInfo.GetLookAndFeelPainter: TcxCustomLookAndFeelPainter;
begin
  Result := Controller.LookAndFeelPainter;
end;

{ TdxSkinCustomControlController }

constructor TdxSkinCustomControlController.Create(AHandle: HWND);
begin
  inherited Create(AHandle);
  FViewInfo := CreateViewInfo;
end;

destructor TdxSkinCustomControlController.Destroy;
begin
  FreeAndNil(FViewInfo);
  inherited Destroy;
end;

procedure TdxSkinCustomControlController.Draw(DC: HDC = 0);
var
  AMemBmp: HBITMAP;
  AMemDC: HDC;
  ANeedReleaseDC: Boolean;
begin
  ANeedReleaseDC := DC = 0;
  if ANeedReleaseDC then
    DC := GetDCEx(Handle, 0, DCX_CACHE or DCX_CLIPSIBLINGS or DCX_WINDOW or DCX_VALIDATE);
  try
    if DoubleBuffered then
    begin
      AMemDC := CreateCompatibleDC(DC);
      AMemBmp := CreateCompatibleBitmap(DC, ViewInfo.ClientWidth, ViewInfo.ClientHeight);
      SelectObject(AMemDC, AMemBmp);
      try
        DoDraw(AMemDC);
      finally
        cxBitBlt(DC, AMemDC, ViewInfo.ClientRect, cxNullPoint, SRCCOPY);
        DeleteObject(AMemBmp);
        DeleteObject(AMemDC);
      end;
    end
    else
      DoDraw(DC);
  finally
    if ANeedReleaseDC then
      ReleaseDC(Handle, DC);
  end;
end;

function TdxSkinCustomControlController.CreateViewInfo: TdxSkinCustomControlViewInfo;
begin
  Result := TdxSkinCustomControlViewInfo.Create(Self);
end;

procedure TdxSkinCustomControlController.WndProc(var AMessage: TMessage);
var
  AHandled: Boolean;
begin
  AHandled := False;
  if UseSkin then
  begin
    case AMessage.Msg of
      WM_ERASEBKGND:
        AHandled := WMEraseBk(TWMEraseBkgnd(AMessage));
      WM_PAINT:
        AHandled := WMPaint(TWMPaint(AMessage));
    end;
  end;
  if not AHandled then
    inherited WndProc(AMessage);
end;

function TdxSkinCustomControlController.WMEraseBk(var AMessage: TWMEraseBkgnd): Boolean;
begin
  AMessage.Result := 1;
  Result := True;
end;

function TdxSkinCustomControlController.WMPaint(var AMessage: TWMPaint): Boolean;
var
  ADC: HDC;
  APaintStruct: TPaintStruct;
begin
  Result := True;
  if AMessage.DC = 0 then
  begin
    ADC := BeginPaint(Handle, APaintStruct);
    try
      Draw(ADC);
    finally
      EndPaint(Handle, APaintStruct);
    end;
  end
  else
    Draw(AMessage.DC);
end;

procedure TdxSkinCustomControlController.DoDraw(DC: HDC);
var
  AControl: TControl;
begin
  cxPaintCanvas.BeginPaint(DC);
  try
    cxPaintCanvas.SaveClipRegion;
    try
      ViewInfo.DrawBackground(cxPaintCanvas);
      ViewInfo.DrawContent(cxPaintCanvas);
    finally
      cxPaintCanvas.RestoreClipRegion;
    end;

    AControl := WinControl;
    if AControl <> nil then    
      TWinControlAccess(AControl).PaintControls(cxPaintCanvas.Handle, nil);
  finally
    cxPaintCanvas.EndPaint;
  end;
end;

{ TdxSkinCustonButtonViewInfo }

procedure TdxSkinCustonButtonViewInfo.AfterConstruction;
begin
  inherited AfterConstruction;
  UpdateButtonState;
end;

function TdxSkinCustonButtonViewInfo.CalculateButtonState: TcxButtonState;
begin
  Result := cxbsNormal;
  if IsMouseAtControl then
    Result := cxbsHot;
  if IsPressed then
    Result := cxbsPressed;
end;

procedure TdxSkinCustonButtonViewInfo.UpdateButtonState;
begin
  State := CalculateButtonState;
end;

function TdxSkinCustonButtonViewInfo.GetCaption: string;
begin
  Result := GetWindowCaption(Controller.Handle);
end;

function TdxSkinCustonButtonViewInfo.GetIsPressed: Boolean;
begin
  Result := SendMessage(Controller.Handle, BM_GETSTATE, 0, 0) and BST_PUSHED <> 0;
end;

function TdxSkinCustonButtonViewInfo.GetWordWrap: Boolean;
begin
  Result := GetWindowLong(Controller.Handle, GWL_STYLE) and BS_MULTILINE <> 0;
end;

procedure TdxSkinCustonButtonViewInfo.SetState(AState: TcxButtonState);
var
  ANewState: TcxButtonState;
begin
  if IsEnabled then
    ANewState := AState
  else
    ANewState := cxbsDisabled;

  if ANewState <> FState then
  begin
    FState := ANewState;
    if Controller.UseSkin then
      Controller.RedrawWindow(True);
  end;
end;

{ TdxSkinCustonButtonController }

constructor TdxSkinCustonButtonController.Create(AHandle: HWND);
begin
  inherited Create(AHandle);
  DoubleBuffered := True;
end;

procedure TdxSkinCustonButtonController.MouseLeave;
begin
  inherited MouseLeave;
  ViewInfo.UpdateButtonState;
end;

procedure TdxSkinCustonButtonController.WndProc(var AMessage: TMessage);
begin
  inherited WndProc(AMessage); 
  case AMessage.Msg of
    WM_ENABLE, BM_SETSTATE, WM_MOUSELEAVE, WM_MOUSEMOVE, CM_MOUSELEAVE, WM_MOUSEHOVER:
      ViewInfo.UpdateButtonState;
    WM_UPDATEUISTATE:
      if UseSkin and (AMessage.WParamLo in [UIS_SET, UIS_CLEAR]) then
        Draw;
    WM_SETTEXT:
      if UseSkin then
        Draw;
  end;
end;

function TdxSkinCustonButtonController.GetViewInfo: TdxSkinCustonButtonViewInfo;
begin
  Result := inherited ViewInfo as TdxSkinCustonButtonViewInfo; 
end;

{ TdxSkinButtonViewInfo }

procedure TdxSkinButtonViewInfo.DrawContent(ACanvas: TcxCanvas);

  procedure DrawButtonText(ATextColor: TColor);
  const
    TextAlignFlagsMap: array[Boolean] of Integer = (cxSingleLine, cxWordBreak);
  begin
    ACanvas.Font := TControlAccess(Controller.WinControl).Font;
    ACanvas.Font.Color := ATextColor;
    ACanvas.DrawText(Caption, ClientRect, cxAlignCenter or cxShowPrefix or TextAlignFlagsMap[WordWrap], True);
  end;

begin
  LookAndFeelPainter.DrawButton(ACanvas, ClientRect, '', State, False, clDefault, clDefault, False);

  if Length(Caption) > 0 then
  begin
    ACanvas.Brush.Style := bsClear;
    if State = cxbsDisabled then
      DrawButtonText(clBtnHighlight);
    DrawButtonText(LookAndFeelPainter.ButtonSymbolColor(State));
  end;

  if IsFocused then
  begin
    ACanvas.Brush.Style := bsSolid;
    ACanvas.DrawFocusRect(cxRectInflate(ClientRect, -4, -4));
  end;
end;

function TdxSkinButtonViewInfo.CalculateButtonState: TcxButtonState;
begin
  Result := inherited CalculateButtonState;
  if (Result = cxbsNormal) and Active then
    Result := cxbsDefault;  
end; 

procedure TdxSkinButtonViewInfo.CMFocusChanged(var Message: TCMFocusChanged);
begin
  if Message.Sender is TButton then
    Active := Message.Sender = Controller.WinControl
  else
    Active := IsDefault;
end;

function TdxSkinButtonViewInfo.GetIsDefault: Boolean;
begin
  Result := (Controller.WinControl as TButton).Default;
end;

procedure TdxSkinButtonViewInfo.SetActive(AActive: Boolean);
begin
  if AActive <> FActive then
  begin
    FActive := AActive;
    UpdateButtonState;
  end;
end;

{ TdxSkinButtonController }

function TdxSkinButtonController.CreateViewInfo: TdxSkinCustomControlViewInfo;
begin
  Result := TdxSkinButtonViewInfo.Create(Self);
end;

procedure TdxSkinButtonController.WndProc(var AMessage: TMessage);
begin
  if AMessage.Msg = CM_FOCUSCHANGED then
    (ViewInfo as TdxSkinButtonViewInfo).CMFocusChanged(TCMFocusChanged(AMessage));
  inherited WndProc(AMessage);
end;

{ TdxSkinPanelViewInfo }

procedure TdxSkinPanelViewInfo.DrawBackground(ACanvas: TcxCanvas);
var
  APanel: TCustomPanelAccess;
begin
  APanel := TCustomPanelAccess(Controller.WinControl);
  if not (csPaintCopy in APanel.ControlState) then
    ExcludeOpaqueChildren(APanel, ACanvas.Handle);

  if csParentBackground in APanel.ControlStyle then
    cxDrawTransparentControlBackground(APanel, ACanvas, ClientRect, False)
  else
    if APanel.Color = clBtnFace then
      LookAndFeelPainter.DrawPanelContent(ACanvas, ClientRect, False)
    else
      LookAndFeelPainter.DrawPanelBackground(ACanvas, APanel, ClientRect, APanel.Color);

  if (APanel.BevelOuter <> bvNone) or (APanel.BevelInner <> bvNone) then
    LookAndFeelPainter.DrawPanelBorders(ACanvas, ClientRect);
end;

procedure TdxSkinPanelViewInfo.DrawContent(ACanvas: TcxCanvas);
const
  Alignments: array[TAlignment] of Longint = (DT_LEFT, DT_RIGHT, DT_CENTER);
var
  APanel: TCustomPanelAccess;
  R: TRect;
begin
  APanel := TCustomPanelAccess(Controller.WinControl);
{$IFDEF DELPHI14}
  if not APanel.ShowCaption then Exit;
{$ENDIF}

  R := ClientRect;
  ACanvas.Brush.Style := bsClear;
  ACanvas.Font := APanel.Font;
  if (APanel.Font.Color = clWindowText) and (LookAndFeelPainter.PanelTextColor <> clDefault) then
    ACanvas.Font.Color := LookAndFeelPainter.PanelTextColor;
  cxDrawText(ACanvas.Handle, APanel.Caption, R, APanel.DrawTextBiDiModeFlags(
    DT_EXPANDTABS or DT_SINGLELINE or DT_VCENTER or Alignments[APanel.Alignment]));
  ACanvas.Brush.Style := bsSolid;
end;

{ TdxSkinPanelController }

function TdxSkinPanelController.CreateViewInfo: TdxSkinCustomControlViewInfo;
begin
  Result := TdxSkinPanelViewInfo.Create(Self);
end;

function TdxSkinPanelController.WMEraseBk(var AMessage: TWMEraseBkgnd): Boolean;
begin
  Result := False;
end;

function TdxSkinPanelController.WMPaint(var AMessage: TWMPaint): Boolean;
begin
  Result := False;
  if not FPainting then
  begin
    FPainting := True;
    try
      Result := inherited WMPaint(AMessage);
    finally
      FPainting := False;
    end;
  end;
end;

function TdxSkinPanelController.WMPrintClient(var AMessage: TWMPrintClient): Boolean;
begin
  Result := (AMessage.Result <> 1) and 
    ((AMessage.Flags and PRF_CHECKVISIBLE = 0) or IsWindowVisible(Handle)) and WMPaint(TWMPaint(AMessage));
end;

procedure TdxSkinPanelController.WndProc(var AMessage: TMessage);
var
  AHandled: Boolean;
begin
  AHandled := False;
  if UseSkin then
  begin
    case AMessage.Msg of
      CM_COLORCHANGED:
        RedrawWindow(False);
      WM_PRINTCLIENT:
        AHandled := WMPrintClient(TWMPrintClient(AMessage));
    end;
  end;
  if not AHandled then
    inherited WndProc(AMessage);
end;


initialization
  dxSkinGetControllerClassForWindowProc := dxSkinGetControllerClassForWindow;
  RegisterAssistants;

finalization
  UnregisterAssistants;
end.
