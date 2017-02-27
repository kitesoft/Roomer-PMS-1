{********************************************************************}
{                                                                    }
{       Developer Express Visual Component Library                   }
{                   ExpressTileControl                               }
{                                                                    }
{       Copyright (c) 2011-2014 Developer Express Inc.               }
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
{   LICENSED TO DISTRIBUTE THE EXPRESSTILECONTROL AND ALL            }
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

unit dxCustomTileControl;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Windows, Messages, Forms, SysUtils, Classes, Controls, StdCtrls, Graphics, Math,
  Dialogs, Types, Menus, dxCoreClasses, dxCore, cxGeometry, cxClasses, cxGraphics,
  cxControls, cxLookAndFeels, cxLookAndFeelPainters, dxGDIPlusClasses, dxGDIPlusAPI,
  cxInplaceContainer, cxStorage, dxSkinsCore, cxDrawTextUtils, dxSkinInfo,
  cxLibraryConsts, dxHooks, dxAnimation;


const
  //appearances
  dxTileControlDefaultActionBarsIndentHorz = 24;
  dxTileControlDefaultActionBarsIndentVert = 14;
  dxTileControlDefaultActionBarsItemIndent = 30;
  dxTileControlDefaultAnimateText = True;
  dxTileControlDefaultIndentHorz = 74;
  dxTileControlDefaultIndentVert = 40;
  dxTileControlDefaultItemIndent = 8;
  dxTileControlDefaultItemSize = 120;
  dxTileControlDefaultGroupIndent = 56;
  dxTileControlDefaultRowCount = 4;
  dxTileControlDefaultItemRowCount = 1;
  dxTileControlItemMaxRowCount = 10;
  dxTileContolSizeGroupBorder = 1;

  dxTileFocusItemFrameSize = 3;
  dxTileItemObjectDefaultIndent = 6;

  dxTileControlInvisiblePosition = 15000;

  dxTileControlDefaultTabFontSize = 12;
  dxTileControlDefaultTitleFontSize = 32;
  dxTileControlDefaultGroupCaptionFontSize = 16;

  dxTileDefaultActionBarColor = $D2D2D2;
  dxTileDefaultActionBarTextColor = clBlack;
  dxTileControlDropArrowColor = $00FF00;
  dxTileItemLightColor = $30A965;
  dxTileItemShadowColor = $17934B;
  dxTileVirtualGroupBackgroundColor = $444444;
  dxTileItemPlaceColor = $444444;

  dxTileCheckedItemCheckMarkAreaSize = 45;
  dxTileCheckedItemCheckMarkPenSize = dxTileCheckedItemCheckMarkAreaSize div 15;
  dxTileCheckedItemFrameBorderSize = 4;

  // customizing
  dxTileControlAutoScrollWidth = 20;
  dxTileControlResizeDelta = 20;
  dxTileControlScrollStep = 20;

  dxTileControlDefaultScrollSync = 15;

  // animation
  dxTileControlInflateAnimationStepsCount = 7;
  dxTileControlDefaultAnimationInterval = 3000;
  dxTileControlDefaultAnimationMode = amScrollUp;
  dxTileDropAnimationStepCount = 10000;
  //
  dxTileControlActionBarsAnimationTime = 200;
  dxTileControlActivateDetailAnimationTime = 500;
  dxTileControlHotTrackItemAnimationTime = 500;
  dxTileControlInflateAnimationTime = 150;
  dxTileControlCenterContentAnimationTime = 150;
  dxTileControlFramesAnimationTime = 1000;
  dxTileControlRubberAnimationTime = 400;

  // base index for hit test bits
  tchtGroup        = 1;
  tchtItem         = 2;
  tchtPageTab      = 3;
  tchtBackButton   = 4;
  tchtActionBar    = 5;
  tchtActionButton = 6;
  tchtScrollButton = 7;
  tchtScrollButtonArea = 8;
  tchtTitle = 9;
  tchtGroupCaption = 10;
  tchtActionBarTop    = 11;
  tchtActionBarBottom    = 12;

  dxTileControlStoringVersion = 2;

type
  TdxCustomTileControl = class;
  TdxTileControlActionBarController = class;
  TdxTileControlActionBarItem = class;
  TdxTileControlActionBars = class;
  TdxTileControlCustomActionBar = class;
  TdxTileControlViewInfo = class;
  TdxTileControlGroupCollection = class;
  TdxTileControlGroup = class;
  TdxTileControlItemCollection = class;
  TdxTileControlCustomItem = class;
  TdxTileControlItem = class;
  TdxTileControlItemFrame = class;
  TdxTileControlHintController = class;
  TdxTileControlController = class;
  TdxTileControlHitTest = class;
  TdxTileControlCustomActionBarViewInfo = class;
  TdxTileControlCustomCellViewInfo = class;
  TdxTileControlCustomItemViewData = class;
  TdxTileControlPainter = class;
  TdxTileControlItemNavigator = class;
  TdxTileControlTitle = class;
  TdxTileControlDetailSite = class;
  TdxTileControlDetailSiteTitleViewInfo = class;
  TdxTileControlDragAndDropChanges = class;
  TdxTileControlDragDropCustomObject = class;
  TdxTileControlHandScroll = class;
  TdxTileControlScrollButtonViewInfo = class;
  TdxTileControlGroupCaption = class;

  TdxTileControlAutoScrollSide = (sLeft, sRight, sTop, sBottom);
  TdxTileControlAutoScrollSides = set of TdxTileControlAutoScrollSide;

  TdxTileControlRectIntersectedBounds = (rcNone, rcFull,
    rcFullLeft, rcFullTop, rcFullRight, rcFullBottom, rcLeft, rcRight);

  TdxTileControlItemCheckMode = (tcicmNone, tcicmMultiple);
  TdxTileControlGroupLayout = (glHorizontal, glVertical);
  TdxTileControlScrollMode = (smDefault, smScrollbars, smScrollButtons);

  TdxTileControlVirtualGroupState = (vgsNoVisible, vgsVisible);

  TdxTileControlDesignTimeWhatSelected = (tcdtwsNone, tcdtwsItem, tcdtwsItems, tcdtwsGroup, tcdtwsGroups, tcdtwsMixed);

  TdxLayoutItemPosition = class
  private
    FRow: Integer;
    FColumn: Integer;
  protected
    procedure Assign(ASource: TdxLayoutItemPosition);
    function IsEqual(APosition: TdxLayoutItemPosition): Boolean;
  public
    property Row: Integer read FRow write FRow;
    property Column: Integer read FColumn write FColumn;
  end;

  { TdxTileControlCells }

  TdxTileControlCells = class(TcxObjectList)
  private
    function GetItem(AIndex: Integer): TdxTileControlCustomCellViewInfo;
  protected
    procedure DrawWithoutClipping(ACanvas: TcxCanvas);
  public
    function CalculateHitTest(AHitTest: TdxTileControlHitTest): Boolean;
    procedure Draw(ACanvas: TcxCanvas); virtual;
    procedure RefreshState; virtual;

    property Items[Index: Integer]: TdxTileControlCustomCellViewInfo read GetItem; default;
  end;

  { TdxTileControlCustomViewInfo }

  TdxTileControlCustomViewInfo = class(TcxIUnknownObject)
  private
    FBounds: TRect;
  protected
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; virtual; abstract;
    function IsEqual(ACompare: TdxTileControlCustomViewInfo): Boolean; virtual;
  public
    procedure Draw(ACanvas: TcxCanvas); virtual; abstract;
    procedure RefreshState; virtual;
    //
    property Bounds: TRect read FBounds write FBounds;
  end;

  { TdxTileControlCustomCellViewInfo }

  TdxTileControlCustomCellViewInfo = class(TdxTileControlCustomViewInfo)
  private
    FCalculated: Boolean;
    FClipRect: TRect;
    FVisibleBounds: TRect;
    FVisible: Boolean;
    procedure SetCalculate(AValue: Boolean);
  protected
    procedure CalculateClipping; virtual;
    procedure DoCalculate; virtual;
    procedure DoDraw(ACanvas: TcxCanvas); virtual;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetVisibleBounds: TRect; virtual;
    procedure Offset(const DX, DY: Integer); virtual;
    procedure Scroll(const DX, DY: Integer); virtual;
  public
    procedure Calculate;
    procedure Draw(ACanvas: TcxCanvas); override;
    procedure Recalculate;
    //
    property Calculated: Boolean read FCalculated write SetCalculate;
    property ClipRect: TRect read FClipRect;
    property Visible: Boolean read FVisible;
    property VisibleBounds: TRect read FVisibleBounds write FVisibleBounds;
  end;

  { TdxTileControlAnimatedDragAndDropCustomCellViewInfo }

  TdxTileControlAnimatedDragAndDropCustomCellViewInfo = class(TdxTileControlCustomCellViewInfo)
  protected
    procedure DrawContent(ACanvas: TcxCanvas; const ADrawRect: TRect); virtual;
    function GetBaseDrawBounds: TRect; virtual;
    function GetDrawBounds(AAbsolutePosition: Boolean = False): TRect;
    function GetIsAnimatedOnDragDrop: Boolean; virtual;
    function GetTileControl: TdxCustomTileControl; virtual;

    property IsAnimatedOnDragDrop: Boolean read GetIsAnimatedOnDragDrop;
    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlItemViewInfo }

  TdxTileControlItemViewInfo = class(TdxTileControlAnimatedDragAndDropCustomCellViewInfo)
  private
    FAnimation: TdxImageAnimationTransition;
    FCache: TcxBitmap;
    FHottrackValue: Integer;
    FInflateDelta: Integer;
    FIsDirty: Boolean;
    FItem: TdxTileControlItem;
    FPosition: TdxLayoutItemPosition;
    FViewData: TdxTileControlCustomItemViewData;
    function GetController: TdxTileControlController;
    function GetDragItemPlaceBounds: TRect;
    function GetFocused: Boolean;
    function GetGroup: TdxTileControlGroup;
    function GetHottracked: Boolean;
    function GetNeedDrawDragItemPlace: Boolean;
    function GetPainter: TdxTileControlPainter;
    function GetSelected: Boolean;
    function GetViewData: TdxTileControlCustomItemViewData;
    procedure SetHottrackValue(AValue: Integer);
    procedure SetInflateDelta(AValue: Integer);
    procedure SetIsDirty(AValue: Boolean);
    procedure SetViewData(AValue: TdxTileControlCustomItemViewData);
  protected
    procedure CalculateBounds; virtual;
    procedure DoCalculate; override;
    procedure DoDraw(ACanvas: TcxCanvas); override;
    procedure DirtyChanged; virtual;
    procedure DrawChecked(ACanvas: TcxCanvas); virtual;
    procedure DrawContent(ACanvas: TcxCanvas; const ADrawRect: TRect); override;
    procedure DrawFocusRect(ACanvas: TcxCanvas); virtual;
    procedure DrawHottrackRect(ACanvas: TcxCanvas); virtual;
    procedure DrawSelection(ACanvas: TcxCanvas); virtual;
    function GetActualVisualBounds: TRect; virtual;
    function GetBaseDrawBounds: TRect; override;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetTileControl: TdxCustomTileControl; override;
    function GetVisibleBounds: TRect; override;
    procedure ValidateCache(const ADrawRect: TRect); virtual;
    procedure ValidateImage; virtual;

    property Animation: TdxImageAnimationTransition read FAnimation;
    property Cache: TcxBitmap read FCache;
    property Controller: TdxTileControlController read GetController;
    property DragItemPlaceBounds: TRect read GetDragItemPlaceBounds;
    property HottrackValue: Integer read FHottrackValue write SetHottrackValue;
    property InflateDelta: Integer read FInflateDelta write SetInflateDelta;
    property IsDirty: Boolean read FIsDirty write SetIsDirty;
    property NeedDrawDragItemPlace: Boolean read GetNeedDrawDragItemPlace;
  public
    constructor Create(AOwner: TdxTileControlItem); virtual;
    destructor Destroy; override;

    property Focused: Boolean read GetFocused;
    property Group: TdxTileControlGroup read GetGroup;
    property Hottracked: Boolean read GetHottracked;
    property Item: TdxTileControlItem read FItem;
    property Painter: TdxTileControlPainter read GetPainter;
    property Position: TdxLayoutItemPosition read FPosition write FPosition;
    property Selected: Boolean read GetSelected;
    property ViewData: TdxTileControlCustomItemViewData read GetViewData write SetViewData;
  end;

  { TdxTileControlCustomGroupViewInfo }

  TdxTileControlCustomGroupViewInfo = class(TdxTileControlCustomCellViewInfo)
  private
    FGroup: TdxTileControlGroup;
    function GetTileControl: TdxCustomTileControl;
    function GetPainter: TdxTileControlPainter;
  protected
    procedure CalculateBounds; virtual;
    procedure CalculateSize(var AWidth, AHeight: Integer); virtual;
    function GetLeftPos: Integer; virtual;
    function GetTopPos: Integer; virtual;
    function GetVisibleBounds: TRect; override;
    procedure Offset(const DX, DY: Integer); override;
  public
    constructor Create(AOwner: TdxTileControlGroup); virtual;

    property Group: TdxTileControlGroup read FGroup;
    property Painter: TdxTileControlPainter read GetPainter;
    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlVirtualGroupViewInfo }

  TdxTileControlVirtualGroupViewInfo = class(TdxTileControlCustomGroupViewInfo)
  private
    FAreaBounds: TRect;
    FBasisWidth: Integer;
    FSizeMustFromDragItem: Boolean;
    FState: TdxTileControlVirtualGroupState;
    procedure SetState(const AValue: TdxTileControlVirtualGroupState);

    procedure CalculateSizeAtHorizontalGroupLayout(var AWidth, AHeight: Integer);
    procedure CalculateSizeAtVerticalGroupLayout(var AWidth, AHeight: Integer);
    function GetGroupLayout: TdxTileControlGroupLayout;

    property GroupLayout: TdxTileControlGroupLayout read GetGroupLayout;
  protected
    procedure CalculateAreaBounds; virtual;
    procedure CalculateSize(var AWidth, AHeight: Integer); override;
    procedure DoCalculate; override;
    procedure ExpandBounds(const DW, DH: Integer);
    function GetLeftPos: Integer; override;
    function GetTopPos: Integer; override;
    procedure Scroll(const DX, DY: Integer); override;
  public
    procedure DoDraw(ACanvas: TcxCanvas); override;
    procedure Invalidate; virtual;
    procedure RecalculateAreaBounds;

    property AreaBounds: TRect read FAreaBounds write FAreaBounds;
    property BasisWidth: Integer read FBasisWidth;
    property State: TdxTileControlVirtualGroupState read FState write SetState;
    property SizeMustFromDragItem: Boolean read FSizeMustFromDragItem write FSizeMustFromDragItem;
  end;

  { TdxTileControlGroupViewInfo }

  TdxTileControlGroupViewInfo = class(TdxTileControlCustomGroupViewInfo)
  private
    FColumnCount: Integer;
    FExpandedBounds: TRect;
    FMaximizedAreaBounds: TRect;
    FNewGroupAreaBounds: TRect;
    FRowCount: Integer;
    function GetSelected: Boolean;
    // used in calculations
    procedure CalculateRowAndColumnLargeItem(AItem, AItemPrev: TdxTileControlItem;
      var ARow, AColumn: Integer);
    procedure CalculateRowAndColumnNoLargeItem(AItem, AItemPrev: TdxTileControlItem;
      var ARow, AColumn: Integer);
    procedure DoCorrectColumnAndRow(var AColumn, ARow: Integer; const AItemRowCount: Integer);
    procedure DoCorrectColumnAndRowIfOccupiedForNoLargeItem(ACurrentItem: TdxTileControlItem;
      var AColumn, ARow: Integer);
    procedure DoCorrectRowIfOccupiedForLargeItem(ACurrentItem: TdxTileControlItem;
      const AColumn: Integer; var ARow: Integer);
    procedure ExpandBoundsToBottomControl(var ABounds: TRect);
    procedure ExpandBoundsToLeftControl(var ABounds: TRect);
    procedure ExpandBoundsToRightControl(var ABounds: TRect);
    procedure ExpandBoundsToTopControl(var ABounds: TRect);
    function GetGroupLayout: TdxTileControlGroupLayout;
    function GetTilesMaximizedAreaHeght: Integer;
    function GetTilesMaximizedAreaWidth: Integer;
    function IsItemOccupyPosition(AItem: TdxTileControlItem;
      APosition: TdxLayoutItemPosition; var AOccupiedRow: Integer): Boolean;
    function IsOccupiedByPriorItems(APosition: TdxLayoutItemPosition;
      ACurrentItem: TdxTileControlItem): Boolean;

    property GroupLayout: TdxTileControlGroupLayout read GetGroupLayout;
  protected
    procedure CalculateExpandedBounds; virtual;
    procedure CalculateMaximizedAreaBounds; virtual;
    procedure CalculateDimensionAndItemsPositions;
    procedure CalculateItemPosition(AItem: TdxTileControlItem; AItemPrev: TdxTileControlItem);
    procedure CalculateSize(var AWidth, AHeight: Integer); override;
    procedure DoCalculate; override;
    procedure DoDraw(ACanvas: TcxCanvas); override;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetLeftPos: Integer; override;
    function GetTopPos: Integer; override;
    function GetZIndex(APosition: TdxLayoutItemPosition): Integer;
    procedure InitializeNextPosition(APosition: TdxLayoutItemPosition;
      var FNextPosition: TdxLayoutItemPosition; const AItemRowCount: Integer);
    procedure Scroll(const DX, DY: Integer); override;
  public
    function GetContentRect: TRect;

    property ColumnCount: Integer read FColumnCount;
    property ExpandedBounds: TRect read FExpandedBounds;
    property MaximizedAreaBounds: TRect read FMaximizedAreaBounds;
    property RowCount: Integer read FRowCount;
    property Selected: Boolean read GetSelected;
  end;

  { TdxTileControlTitleViewInfo }

  TdxTileControlTitleViewInfo = class(TdxTileControlCustomCellViewInfo)
  private
    FFont: TFont;
    FGlyphBounds: TRect;
    FTextBounds: TRect;
    FTextOffset: Integer;
    FTitle: TdxTileControlTitle;
    function GetPainter: TdxTileControlPainter;
    function GetTileControl: TdxCustomTileControl;
  protected
    procedure DoCalculate; override;
    procedure DoDraw(ACanvas: TcxCanvas); override;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetLeftOffset: Integer; virtual;
    function GetTextColor: TColor;
    function GetTextLeftOffset: Integer; virtual;
    function GetTextOutFlags: Integer;
    function GetVisibleBounds: TRect; override;
    function MeasureTextBounds(const AVisibleBounds: TRect): TRect;
    procedure Scroll(const DX, DY: Integer); override;

    property TileControl: TdxCustomTileControl read GetTileControl;
  public
    constructor Create;
    destructor Destroy; override;

    property Font: TFont read FFont;
    property GlyphBounds: TRect read FGlyphBounds;
    property Painter: TdxTileControlPainter read GetPainter;
    property TextBounds: TRect read FTextBounds;
    property TextColor: TColor read GetTextColor;
    property TextOffset: Integer read FTextOffset;
    property Title: TdxTileControlTitle read FTitle;
  end;

  { TdxTileControlCustomDesignHelper }

  TdxTileControlCustomDesignHelper = class(TPersistent)
  protected
    function GetControl: TdxCustomTileControl; virtual;
  public
    constructor Create(AControl: TdxCustomTileControl); virtual;
    procedure CreateItemClickHandler(AItem: TdxTileControlItem); virtual; abstract;
    function IsObjectSelected(AObject: TPersistent): Boolean; virtual; abstract;
    procedure Select(AObject: TPersistent; AShift: TShiftState); virtual; abstract;
    procedure SetSelection(AList: TList); virtual; abstract;
    procedure UnselectObject(AObject: TPersistent); virtual; abstract;

    property Control: TdxCustomTileControl read GetControl;
  end;

  TdxTileControlCustomDesignHelperClass = class of TdxTileControlCustomDesignHelper;

  { TdxTileControlHintController }

  TdxTileControlHintController = class
  private
    FOwner: TdxTileControlController;
    function GetTileControl: TdxCustomTileControl;
  protected
  public
    constructor Create(AOwner: TdxTileControlController); virtual;

    property Owner: TdxTileControlController read FOwner;
    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlInflateItemAnimation }

  TdxTileControlInflateItemAnimation = class(TdxAnimationTransition)
  private
    FDelta: Integer;
    FItem: TdxTileControlItem;
    FTileControl: TdxCustomTileControl;
  protected
    procedure DoAnimate; override;
    procedure InflateItem(AItem: TdxTileControlItem; const AData: Pointer);
  public
    constructor Create(ATileControl: TdxCustomTileControl;
      AItem: TdxTileControlItem; const ADelta, ACount: Integer); reintroduce;
    destructor Destroy; override; 
    //
    property Item: TdxTileControlItem read FItem;
    property TileControl: TdxCustomTileControl read FTileControl;
  end;

  { TdxTileControlFramesAnimation }

  TdxTileControlFramesAnimation = class(TdxImageAnimationTransition)
  private
    FDestViewData: TdxTileControlCustomItemViewData;
    FItem: TdxTileControlItem;
    FSourceViewData: TdxTileControlCustomItemViewData;
  protected
    procedure InitializeViewData; virtual;
    //
    property DestViewData: TdxTileControlCustomItemViewData read FDestViewData;
    property SourceViewData: TdxTileControlCustomItemViewData read FSourceViewData;
  public
    constructor Create(AItem: TdxTileControlItem); reintroduce; virtual;
    destructor Destroy; override;

    property Item: TdxTileControlItem read FItem; 
  end;

  { TdxTileControlDragAndDropAnimation }

  TdxTileControlDragAndDropAnimation = class(TdxAnimationTransition)
  private
    FChanges: TdxTileControlDragAndDropChanges;
    FDragImageOrigin: TPoint;
    function GetTileControl: TdxCustomTileControl;
  protected
    function AnimationLength: Integer;
    procedure DoAnimate; override;
  public
    constructor Create(AChanges: TdxTileControlDragAndDropChanges); reintroduce;

    property Changes: TdxTileControlDragAndDropChanges read FChanges;
    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlHottrackItemAnimation }

  TdxTileControlHottrackItemAnimation = class(TdxAnimationTransition)
  private
    FItem: TdxTileControlItem;
    FShowFrame: Boolean;
  protected
    procedure DoAnimate; override;
    function IsCompatible(AAnimation: TdxAnimationTransition): Boolean; override;
  public
    constructor Create(AItem: TdxTileControlItem; AShowFrame: Boolean = True); reintroduce;
    destructor Destroy; override;

    property Item: TdxTileControlItem read FItem;
    property ShowFrame: Boolean read FShowFrame;
  end;

  { TdxTileControlActionBarsAnimation }

  TdxTileControlActionBarsAnimationMode = (tcabamShow, tcabamHide);

  TdxTileControlActionBarsAnimation = class(TdxAnimationTransition)
  private
    FTileControl: TdxCustomTileControl;
    FMode: TdxTileControlActionBarsAnimationMode;
    FPrevPosition: Integer;
    function GetActionBarTop: TdxTileControlCustomActionBar;
    function GetActionBarBottom: TdxTileControlCustomActionBar;
  protected
    function CalculateActionBarBottomBounds: TRect; virtual;
    function CalculateActionBarTopBounds: TRect; virtual;
    procedure DoAnimate; override;
    function IsCompatible(Animation: TdxAnimationTransition): Boolean; override;
  public
    constructor Create(ATileControl: TdxCustomTileControl; AMode: TdxTileControlActionBarsAnimationMode); reintroduce; virtual;
    //
    property ActionBarBottom: TdxTileControlCustomActionBar read GetActionBarBottom;
    property ActionBarTop: TdxTileControlCustomActionBar read GetActionBarTop;
    property Mode: TdxTileControlActionBarsAnimationMode read FMode;
    property PrevPosition: Integer read FPrevPosition;
    property TileControl: TdxCustomTileControl read FTileControl;
  end;

  { TdxTileControlContentAnimation }

  TdxTileControlContentAnimation  = class(TdxAnimationTransition)
  private
    FLengthX: Integer;
    FLengthY: Integer;
    FPrevPositionX: Integer;
    FPrevPositionY: Integer;
    FTileControl: TdxCustomTileControl;
    function GetPositionX: Integer;
    function GetPositionY: Integer;
    function GetViewInfo: TdxTileControlViewInfo;
  protected
    procedure DoAnimate; override;
    procedure DoMoveContent(const ADeltaX, ADeltaY: Integer); virtual;

    property LengthX: Integer read FLengthX;
    property LengthY: Integer read FLengthY;
    property PrevPositionX: Integer read FPrevPositionX write FPrevPositionX;
    property PrevPositionY: Integer read FPrevPositionY write FPrevPositionY;
  public
    constructor Create(ATileControl: TdxCustomTileControl;
      ATime: Cardinal; const ALengthX, ALenghtY: Integer); reintroduce; virtual;

    property TileControl: TdxCustomTileControl read FTileControl;
    property ViewInfo: TdxTileControlViewInfo read GetViewInfo;
  end;

  { TdxTileControlRubberAnimation }

  TdxTileControlRubberAnimation  = class(TdxTileControlContentAnimation)
  private
    FHandScrollObject: TdxTileControlHandScroll;
    function GetController: TdxTileControlController;
  protected
    procedure DoMoveContent(const ADeltaX, ADeltaY: Integer); override;
  public
    constructor Create(ATileControl: TdxCustomTileControl;
      AHandScrollObject: TdxTileControlHandScroll); reintroduce; virtual;
    destructor Destroy; override;

    property HandScrollObject: TdxTileControlHandScroll read FHandScrollObject;
    property Controller: TdxTileControlController read GetController;
  end;

  { TdxTileControlDragAndDropChanges }

  TdxTileControlDragAndDropChangesCellInfo = class
  private
    function GetTileControl: TdxCustomTileControl;
    function GetViewInfo: TdxTileControlViewInfo;
  protected
    AreaSize: Integer;
    BeforeUpdate: Boolean;
    Bounds: TRect;
    Cell: TdxTileControlAnimatedDragAndDropCustomCellViewInfo;
    ClipRgn: TcxRegion;
    ColumnIndex, IndexInGroup: Integer;
    GroupCaption: TdxTileControlGroupCaption;
    GroupOrigin: TPoint;
    Item: TdxTileControlItem;
    IsItemMovedToNeighborPosition: Boolean;
    procedure CalculateComplexDrawingAreaBounds(var R, R1: TRect; const AOffset: Integer);
    procedure CalculateSimpleDrawingAreaBounds(var R: TRect; const AOffset: Integer);
    function CompareTileControlGroupCaptions(AInfo: TdxTileControlDragAndDropChangesCellInfo): Integer;
    function CompareTileControlItems(AInfo: TdxTileControlDragAndDropChangesCellInfo): Integer;
    function IsEqualGroupCaptions(AInfo: TdxTileControlDragAndDropChangesCellInfo): Boolean;
    function IsEqualItems(AInfo: TdxTileControlDragAndDropChangesCellInfo): Boolean;
  public
    constructor Create(ACell: TdxTileControlAnimatedDragAndDropCustomCellViewInfo; ABeforeUpdate: Boolean);
    destructor Destroy; override;
    function Compare(AInfo: TdxTileControlDragAndDropChangesCellInfo): Integer;
    procedure Draw(ACanvas: TcxCanvas; const AProgress: Integer);
    procedure InvalidateAnimatedArea;
    function IsEqual(AInfo: TdxTileControlDragAndDropChangesCellInfo): Boolean;
    function Merge(AInfo: TdxTileControlDragAndDropChangesCellInfo): Boolean;

    property TileControl: TdxCustomTileControl read GetTileControl;
    property ViewInfo: TdxTileControlViewInfo read GetViewInfo;
  end;

  TdxTileControlDragAndDropChanges = class
  private
    FDragFinished: Boolean;
    FDragObject: TdxTileControlCustomCellViewInfo;
    FDragImageBounds: TRect;
    FDragImagePosition: TPoint;
    FItemsInfo: TcxObjectList;
    FLock: Integer;
    FProgress: Integer;
    FViewInfo: TdxTileControlViewInfo;
    function GetCount: Integer;
    function GetDragAndDropObject: TdxTileControlDragDropCustomObject;
    function GetDragObjectFinished: Boolean;
    function GetItem(AIndex: Integer): TdxTileControlDragAndDropChangesCellInfo;
    function GetTileControl: TdxCustomTileControl;
  protected
    procedure AnimateDragFinished(const AProgress: Integer); virtual;
    procedure DrawItems(ACanvas: TcxCanvas); virtual;
    procedure PopulateItemsInfo(ABeforeUpdate: Boolean);
    procedure SetAnimationProgress(const AProgress: Integer);

    property DragFinished: Boolean read FDragFinished write FDragFinished;
    property ItemsInfo: TcxObjectList read FItemsInfo;
    property Progress: Integer read FProgress;
  public
    constructor Create(AViewInfo: TdxTileControlViewInfo);
    destructor Destroy; override;

    procedure AfterUpdate; virtual;
    procedure BeforeUpdate; virtual;
    function IndexOf(ACell: TdxTileControlAnimatedDragAndDropCustomCellViewInfo): Integer;

    property Count: Integer read GetCount;
    property DragAndDropObject: TdxTileControlDragDropCustomObject read GetDragAndDropObject;
    property DragObject: TdxTileControlCustomCellViewInfo read FDragObject;
    property DragObjectFinished: Boolean read GetDragObjectFinished;
    property Items[Index: Integer]: TdxTileControlDragAndDropChangesCellInfo read GetItem;
    property TileControl: TdxCustomTileControl read GetTileControl;
    property ViewInfo: TdxTileControlViewInfo read FViewInfo;
  end;

  { TdxTileControlAutoScrollingObject }

  TdxTileControlAutoScrollingObject = class(TcxCustomAutoScrollingObject)
  protected
    function GetControl: TcxControl; override;
    function GetHasScrollBar: Boolean; override;
    procedure GetScrollBarParams(var AMin, AMax, APos: Integer); override;
    function GetTileControl: TdxCustomTileControl;
    procedure Scroll(AKind: TScrollBarKind; ACode: TScrollCode; var APosition: Integer); override;

    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlHandScroll }

  TdxTileControlHandScroll = class(TcxDragAndDropObject)
  private
    FFinishAnimationPosX: Integer;
    FFinishAnimationPosY: Integer;
    FStartAnimationPosX: Integer;
    FStartAnimationPosY: Integer;

    procedure DoScrollHorizontally;
    procedure DoScrollVertically;
    function GetSlowdownScrollFactor(APos, AContentSize, ADelta: Integer): Integer;
    function GetTileControl: TdxCustomTileControl;
    function GetViewInfo: TdxTileControlViewInfo;
  protected
    procedure DragAndDrop(const P: TPoint; var Accepted: Boolean); override;
    procedure EndDragAndDrop(Accepted: Boolean); override;
    function GetDragAndDropCursor(Accepted: Boolean): TCursor; override;
    function GetImmediateStart: Boolean; override;

    property FinishAnimationPosX: Integer read FFinishAnimationPosX;
    property FinishAnimationPosY: Integer read FFinishAnimationPosY;
    property StartAnimationPosX: Integer read FStartAnimationPosX;
    property StartAnimationPosY: Integer read FStartAnimationPosY;
    property TileControl: TdxCustomTileControl read GetTileControl;
    property ViewInfo: TdxTileControlViewInfo read GetViewInfo;
  end;

  { TdxTileControlDragDropCustomObject }

  TdxTileControlDragDropState = (tcddsPulling, tcddsMoving);

  TdxTileControlDragDropCustomObject = class(TcxDragAndDropObject)
  private
    FBeginGroup: TdxTileControlGroup;
    FBeginIndex: Integer;
    FDragCell: TdxTileControlCustomCellViewInfo;
    FDragCellIsHided: Boolean;
    FHotSpot: TPoint;
    FHotSpotCalculated: Boolean;
    FIsTouching: Boolean;
    FPrevAccepted: Boolean;
    FPullProgress: Integer;
    FState: TdxTileControlDragDropState;
    procedure CalculateHotSpot;
    function CreateAutoScrollObject(Kind: TScrollBarKind; const ARect: TRect;
      ACode: TScrollCode): TdxTileControlAutoScrollingObject;
    procedure CreateAutoScrollObjects;
    procedure DestroyAutoScrollObjects;
    function GetController: TdxTileControlController;
    function GetDragBounds: TRect;
    function GetDragCellAsGroup: TdxTileControlGroup;
    function GetDragCellAsItem: TdxTileControlItem;
    function GetDragCellIsItem: Boolean;
    function GetDragDropChanges: TdxTileControlDragAndDropChanges;
    function GetHitTest: TdxTileControlHitTest;
    function GetIsPullDownGesture: Boolean;
    function GetMaxPullSize: Integer;
    function GetTileControl: TdxCustomTileControl;
    function GetViewInfo: TdxTileControlViewInfo;
    procedure SetPullProgress(AValue: Integer);
    procedure HideOriginalDragCell;
    function IsRectInControl(const ARect: TRect): Boolean;
    function MouseClientToScreen(const P: TPoint): TPoint;
  protected
    DragImage: TcxDragImage;
    ScrollControllers: array [TdxTileControlAutoScrollSide] of TdxTileControlAutoScrollingObject;
    procedure BeginDragAndDrop; override;
    procedure BeginDragAndDropGroup; virtual;
    procedure BeginDragAndDropItem; virtual;
    procedure BeginDragMoving; virtual;
    function CheckAutoScrolling: Boolean; virtual;
    procedure DoAnimateContent(const AStart, AFinish: TPoint);
    procedure DragAndDrop(const P: TPoint; var Accepted: Boolean); override;
    procedure DragAndDropGroup(var Accepted: Boolean); virtual;
    procedure DragAndDropItem(var Accepted: Boolean); virtual;
    procedure DragMoving(const P: TPoint; var Accepted: Boolean); virtual;
    procedure EndDragAndDrop(Accepted: Boolean); override;
    procedure EndDragAndDropGroup(Accepted: Boolean); virtual;
    procedure EndDragAndDropItem(Accepted: Boolean; var ANewGroup: TdxTileControlGroup); virtual;
    procedure EndDragMoving(Accepted: Boolean); virtual;
    procedure InitializeDragImage; virtual;
    function GetDragAndDropCursor(Accepted: Boolean): TCursor; override;
    function GetImmediateStart: Boolean; override;
    procedure PullDown(Accepted: Boolean); virtual;
    procedure Pulling(const P: TPoint); virtual;
    procedure ShowDragImage(APos: TPoint); virtual; // virtual only for debug!!!
    procedure StopAutoScrollingTimers;

    property Controller: TdxTileControlController read GetController;
    property DragBounds: TRect read GetDragBounds;
    property DragCell: TdxTileControlCustomCellViewInfo read FDragCell;
    property DragCellAsGroup: TdxTileControlGroup read GetDragCellAsGroup;
    property DragCellAsItem: TdxTileControlItem read GetDragCellAsItem;
    property DragCellIsItem: Boolean read GetDragCellIsItem;
    property DragDropChanges: TdxTileControlDragAndDropChanges read GetDragDropChanges;
    property HitTest: TdxTileControlHitTest read GetHitTest;
    property IsPullDownGesture: Boolean read GetIsPullDownGesture;
    property IsTouching: Boolean read FIsTouching;
    property MaxPullSize: Integer read GetMaxPullSize;
    property PullProgress: Integer read FPullProgress write SetPullProgress;
    property State: TdxTileControlDragDropState read FState;
    property TileControl: TdxCustomTileControl read GetTileControl;
    property ViewInfo: TdxTileControlViewInfo read GetViewInfo;
  public
    constructor Create(AControl: TcxControl); override;
    destructor Destroy; override;
  end;

  { TdxTileControlDragDropGroup }

  TdxTileControlDragDropGroup = class(TdxTileControlDragDropCustomObject)
  private
    FDragGroup: TdxTileControlGroup;
    FPrevIndex: Integer;
    function GetPotentialIndexForDraggedGroup: Integer;
    function GetPotentialIndexForNewlyInsertedGroup: Integer;
    function GetPotentialIndexForMovedGroup: Integer;
    function GetGroupLayout: TdxTileControlGroupLayout;
    function GetGroups: TdxTileControlGroupCollection;

    property GroupLayout: TdxTileControlGroupLayout read GetGroupLayout;
    property Groups: TdxTileControlGroupCollection read GetGroups;
  protected
    procedure BeginDragAndDropGroup; override;
    procedure DragAndDropGroup(var Accepted: Boolean); override;
    procedure EndDragAndDropGroup(Accepted: Boolean); override;
  public
    property DragGroup: TdxTileControlGroup read FDragGroup;
  end;

  { TdxDragItemInfo }

  TdxTileControlDragItemInfo = class
  private
    FItem: TdxTileControlItem;
    FGroup: TdxTileControlGroup;
    FSourceGroup: TdxTileControlGroup;
  protected
    procedure SetGroup(AGroup: TdxTileControlGroup);
  public
    property Item: TdxTileControlItem read FItem;
    property Group: TdxTileControlGroup read FGroup;
    property SourceGroup: TdxTileControlGroup read FSourceGroup;
  end;

  { TdxTileControlDragItemPlace }

  TdxTileControlDragItemPlace = class
  private
    FGroup: TdxTileControlGroupViewInfo;
    FPosition: TdxLayoutItemPosition;
    FVirtualGroup: TdxTileControlVirtualGroupViewInfo;
  public
    constructor Create;
    destructor Destroy; override;
    procedure Assign(ASource: TdxTileControlDragItemPlace);
    function GetGroup: TdxTileControlGroup;
    function IsEqual(APlace: TdxTileControlDragItemPlace): Boolean;

    property Group: TdxTileControlGroupViewInfo read FGroup write FGroup;
    property Position: TdxLayoutItemPosition read FPosition write FPosition;
    property VirtualGroup: TdxTileControlVirtualGroupViewInfo read FVirtualGroup write FVirtualGroup;
  end;

  { TdxTileControlDragDropItem }

  TdxTileControlDragDropItem = class(TdxTileControlDragDropCustomObject)
  private
    FDragOverIsAccepted: Boolean;
    FDragItem: TdxTileControlItem;
    FWasTryDecreaseBeginGroup: Boolean;
    FGroupItemsPositions: TcxObjectList;
    FNextPosition: TdxLayoutItemPosition;
    FPrevPlace, FPlace: TdxTileControlDragItemPlace;
    FTemporaryGroup: TdxTileControlGroup;
    procedure CalculateDragAndDropItemInGroup;
    procedure CalculateDragAndDropItemInAnotherGroup;
    procedure CalculateDragAndDropItemInPrevGroup;
    procedure CalculateDragAndDropItemInVirtualGroup(var AAccepted: Boolean);
    procedure CheckGroupDragItem;
    procedure CheckPlaceDragItem(var AAccepted: Boolean);
    procedure CheckPositionDragItem;
    procedure CheckPositionDragPoint(ADragPoint: TPoint);
    function CreateNewGroupAndMoveDragItemTo(AVirtualGroup: TdxTileControlVirtualGroupViewInfo): TdxTileControlGroup;
    procedure DoCollapseBeginGroupWhenItemIsLast;
    procedure DoItemDragOver(var AAccepted: Boolean);
    procedure DoRestoreDragItemSourcePosition;
    procedure FindGroupOccupiedCenterOfDragItem;
    procedure FindVirtualGroupOccupiedCenterOfDragItem;
    procedure FindSomethingOccupiedPartiallyOfDragItem;
    function GetDragItemInfo: TdxTileControlDragItemInfo;
    function GetDragPoint: TPoint;
    function GetGroupCrossedOnTheRight: TdxTileControlGroup;
    function GetGroupLayout: TdxTileControlGroupLayout;
    function GetNewIndexOfDragItem(AGroup: TdxTileControlGroup): Integer;
    function GetSecondaryDragPoint(ABounds: TRect): TPoint;
    function GetSpecialPointX: Integer;
    function GetSpecialPointY: Integer;
    function GetStayInPlaceVirtualGroup: Boolean;
    function GetVirtualGroups: TcxObjectList;
    function HasValidGroup: Boolean;
    procedure InitializePrevPlace;
    function IsBoundsAreasItemsChanged(AGroup: TdxTileControlGroup): Boolean;
    function IsDoDecreaseBeginGroup: Boolean;
    function IsDragBoundsCrossesOnTheRight(AGroup: TdxTileControlGroup): Boolean;
    function IsDragItemsGroupHasMaxExpanded: Boolean;
    function IsDragItemsGroupStayMoreRight: Boolean;
    function IsExitFromVirtualGroup: Boolean;
    function IsPossibleIncreaseGroup(AGroup: TdxTileControlGroup; var AAccepted: Boolean): Boolean;
    procedure MoveDragItemFromControl;
    procedure MoveDragItemToGroup(AGroup: TdxTileControlGroup; AIndexInGroup: Integer);
    procedure RecalculateGroup(AGroup: TdxTileControlGroup);
    procedure RestoreDragItemSourcePosition;
    procedure RestoreGroupItemsPositions(AGroup: TdxTileControlGroup);
    procedure SetNoVisibleAllVirtualGroups;
    procedure SwitchOff(AVirtualGroup: TdxTileControlVirtualGroupViewInfo);
    procedure StoreGroupItemsPositions(AGroup: TdxTileControlGroup);
    procedure TryDecreaseBeginGroup;
  protected
    procedure BeginDragAndDropItem; override;
    procedure BeginDragMoving; override;
    procedure DragAndDropItem(var Accepted: Boolean); override;
    procedure EndDragAndDropItem(Accepted: Boolean; var ANewGroup: TdxTileControlGroup); override;
    procedure PullDown(Accepted: Boolean); override;

    property DragItemInfo: TdxTileControlDragItemInfo read GetDragItemInfo;
  public
    constructor Create(AControl: TcxControl); override;
    destructor Destroy; override;

    property GroupLayout: TdxTileControlGroupLayout read GetGroupLayout;
    property Place: TdxTileControlDragItemPlace read FPlace;
    property VirtualGroups: TcxObjectList read GetVirtualGroups;
    property DragItem: TdxTileControlItem read FDragItem;
  end;

  { TdxTileControlCheckedItems }

  TdxTileControlCheckedItems = class(TList)
  private
    function GetItem(Index: Integer): TdxTileControlItem;
  public
    property Items[Index: Integer]: TdxTileControlItem read GetItem; default;
  end;

  { TdxTileControlController }

  TdxTileControlDesignTimeMenuItemCheckedCondition = function(AItem: TdxTileControlItem): Boolean of object;

  TdxTileControlController = class(TcxIUnknownObject, IdxAnimationListener, IcxMouseTrackingCaller, IcxMouseTrackingCaller2)
  private
    FAnimationItems: TList;
    FAnimations: TList;
    FCanItemDrawing: Boolean;
    FContextMenuHandled: Boolean;
    FDragCell: TObject;
    FDesignHelper: TdxTileControlCustomDesignHelper;
    FDesignPopupMenu: TPopupMenu;
    FDesignPopupMenuCaller: TcxComponentCollectionItem;
    FDesignWhatObjectsSelected: TdxTileControlDesignTimeWhatSelected;
    FFocusedItem: TdxTileControlItem;
    FFramesAnimationLockCount: Integer;
    FHasRubberAnimation: Boolean;
    FHintController: TdxTileControlHintController;
    FHottrackedItem: TdxTileControlItem;
    FMouseDownItem: TdxTileControlItem;
    FMouseDownWasHandled: Boolean; 
    FNavigator: TdxTileControlItemNavigator;
    FPressedScrollButton: TdxTileControlScrollButtonViewInfo;
    FStartDragPos: TPoint;
    FTileControl: TdxCustomTileControl;
    function GetCanGroupMoving: Boolean;
    function GetCanItemMoving: Boolean;
    function GetCheckedItems: TdxTileControlCheckedItems;
    function GetHasAnimation_: Boolean;
    function GetHitTest: TdxTileControlHitTest;
    function GetItemCheckMode: TdxTileControlItemCheckMode;
    function GetViewInfo: TdxTileControlViewInfo;
    procedure RestoreItemBounds(AItem: TdxTileControlItem; const AData: Pointer);
    procedure SetFocusedItem(AValue: TdxTileControlItem);
    procedure SetHottrackedItem(AValue: TdxTileControlItem);
    procedure SetPressedScrollButton(AValue: TdxTileControlScrollButtonViewInfo);
    //design PopupMenu
    function AddPopupMenuItem(ACaption: string; const ATag: Integer; const AGroupIndex: Byte;
      const AChecked, ARadioItem: Boolean; AOnClick: TNotifyEvent): TMenuItem;
    function CheckDesignPopupMenu(AShift: TShiftState): Boolean;
    procedure CreateTileControlItem(Sender: TObject);
    procedure DeleteSelectedObjects(Sender: TObject);
    procedure DeleteTileControlGroups;
    procedure DeleteTileControlItems(const ASelectNextObjectAfterDelete: Boolean);
    procedure DeleteTileControlSelectedItems;
    function GetIsExtraLargeItem(AItem: TdxTileControlItem): Boolean;
    function GetIsLargeItem(AItem: TdxTileControlItem): Boolean;
    function GetIsSmallItem(AItem: TdxTileControlItem): Boolean;
    function GetDesignerMenuItemChecked(const ATag: Integer; AItem: TdxTileControlItem): Boolean; overload;
    function GetDesignerMenuItemChecked(AItem: TdxTileControlItem;
      AFunc: TdxTileControlDesignTimeMenuItemCheckedCondition): Boolean; overload;
    function GetDesignTimeWhatSelected: TdxTileControlDesignTimeWhatSelected;
    function GetNextObject(ADeletedGroupIndex: Integer): TPersistent; overload;
    function GetNextObject(ADeletedItemIndex: Integer; ADeletedItemGroup: TdxTileControlGroup): TPersistent; overload;
    procedure PopulateDesignPopupMenu;
    procedure PopulateOneGroupDesignPopupMenu;
    procedure PopulateOneItemDesignPopupMenu;
    procedure ProcessDesignPopupMenu(ACaller: TcxComponentCollectionItem;
      AShift: TShiftState; APopupPoint: TPoint);
    procedure SwitchItemsProperty(Sender: TObject);
  protected
    procedure AddAnimation(Animation: TdxAnimationTransition);
    procedure AnimateItem(AItem: TdxTileControlItem);
    // IdxAnimationListener
    procedure AfterAnimation(Sender: TdxAnimationController);
    procedure BeforeAnimation(Sender: TdxAnimationController);
    procedure DestroyAnimation(Animation: TdxAnimationTransition);
    //
    function CanShowActionBarsOnRightClick: Boolean; virtual;
    function CanToggleItemCheckOnRightClick: Boolean; virtual;
    procedure ChangePressedScrollButtonState;
    procedure CheckActionBarsState(ACheckingItem: TdxTileControlItem);
    procedure FrameDestroyed(AFrame: TdxTileControlItemFrame);
    function HitAtGroup: Boolean;
    function HitAtItem: Boolean;
    function HitAtItemOrGroup: Boolean;
    procedure ImmediateAnimation(Animation: TdxAnimationTransition);
    function IsEnableDrawDragItemPlace: Boolean;
    function IsHandScrolling(ACheckedKind: TScrollBarKind): Boolean;
    procedure ItemChecked(AItem: TdxTileControlItem);
    procedure ItemDestroyed(AItem: TdxTileControlItem);
    procedure RefreshItems;
    procedure RestoreItemsBounds;
    procedure TerminateAnimations(ATerminateFrames: Boolean);
    procedure UncheckAllItems;
    // design selection
    function CanCreateSelectionHelper: Boolean;
    procedure CheckCreateDesignHelper;
    procedure DestroyDesignHelper;
    function IsObjectSelected(AObject: TPersistent): Boolean; virtual;
    procedure SelectObject(AObject: TPersistent; AShift: TShiftState); virtual;
    procedure UnselectObject(AObject: TPersistent); virtual;
    // mouse
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); virtual;
    procedure MouseLeave; virtual; // IcxMouseTrackingCaller
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); virtual;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); virtual;
    //
    // IcxMouseTrackingCaller2
    function PtInCaller(const P: TPoint): Boolean;
    // action bars
    procedure HideActionBars;
    procedure HideScrollButtons;
    procedure ShowActionBars;
    procedure ToggleActionBars;
    //
    procedure KeyDown(var Key: Word; Shift: TShiftState); virtual;
    //
    property AnimationItems: TList read FAnimationItems;
    property Animations: TList read FAnimations;
    property CanGroupMoving: Boolean read GetCanGroupMoving;
    property CanItemMoving: Boolean read GetCanItemMoving;
    property CanItemDrawing: Boolean read FCanItemDrawing write FCanItemDrawing;
    property CheckedItems: TdxTileControlCheckedItems read GetCheckedItems;
    property ContextMenuHandled: Boolean read FContextMenuHandled;
    property DesignHelper: TdxTileControlCustomDesignHelper read FDesignHelper;
    property DragCell: TObject read FDragCell write FDragCell;
    property FramesAnimationLockCount: Integer read FFramesAnimationLockCount write FFramesAnimationLockCount;
    property HasAnimation_: Boolean read GetHasAnimation_;
    property HasRubberAnimation: Boolean read FHasRubberAnimation;
    property HintController: TdxTileControlHintController read FHintController;
    property HitTest: TdxTileControlHitTest read GetHitTest;
    property ItemCheckMode: TdxTileControlItemCheckMode read GetItemCheckMode;
    property MouseDownWasHandled: Boolean read FMouseDownWasHandled write FMouseDownWasHandled;
    property Navigator: TdxTileControlItemNavigator read FNavigator;
    property StartDragPos: TPoint read FStartDragPos write FStartDragPos;
    property TileControl: TdxCustomTileControl read FTileControl;
    property ViewInfo: TdxTileControlViewInfo read GetViewInfo;
  public
    constructor Create(AOwner: TdxCustomTileControl); virtual;
    destructor Destroy; override;
    procedure PrepareToDragAndDrop;
    procedure ProcessContextMenuMessage(var Message: TWMContextMenu); virtual;
    procedure StartAnimations;
    procedure StartFramesAnimation;
    procedure StopAnimations;
    procedure StopFramesAnimation;

    property FocusedItem: TdxTileControlItem read FFocusedItem write SetFocusedItem;
    property HottrackedItem: TdxTileControlItem read FHottrackedItem write SetHottrackedItem;
    property PressedScrollButton: TdxTileControlScrollButtonViewInfo read FPressedScrollButton write SetPressedScrollButton;
  end;

  { TdxTileControlHitTest }

  TdxTileControlHitTest = class
  private
    FHitObject: TObject;
    FHitPoint: TPoint;
    FOwner: TdxCustomTileControl;
    function GetController: TdxTileControlController;
    function GetGroup: TdxTileControlGroup;
    function GetItem: TdxTileControlItem;
    function GetPosValue(const AIndex: Integer): Integer;
    function GetScrollButton: TdxTileControlScrollButtonViewInfo;
    procedure SetBitState(AIndex: Integer; AValue: Boolean);
    procedure SetHitObject(AValue: TObject);
    procedure SetHitPoint(const AValue: TPoint);
    procedure SetPosValue(const AIndex, AValue: Integer);
  protected
    Flags: Int64;
    function GetActiveViewInfo: TdxTileControlCustomViewInfo; virtual;
    function GetBitState(AIndex: Integer): Boolean;

    property ActiveViewInfo: TdxTileControlCustomViewInfo read GetActiveViewInfo;
    property BitState[AIndex: Integer]: Boolean read GetBitState write SetBitState;
    property Controller: TdxTileControlController read GetController;
    property ScrollButton: TdxTileControlScrollButtonViewInfo read GetScrollButton;
  public
    constructor Create(AOwner: TdxCustomTileControl);
    procedure Calculate(const X, Y: Integer);
    procedure Clear;
    procedure Recalculate; virtual;

    property Group: TdxTileControlGroup read GetGroup;
    property HitAtActionBarBottom: Boolean index tchtActionBarBottom read GetBitState;
    property HitAtActionBarTop: Boolean index tchtActionBarTop read GetBitState;
    property HitAtActionButton: Boolean index tchtActionButton read GetBitState;
    property HitAtBackButton: Boolean index tchtBackButton read GetBitState;
    property HitAtGroup: Boolean index tchtGroup read GetBitState;
    property HitAtGroupCaption: Boolean index tchtGroupCaption read GetBitState;
    property HitAtItem: Boolean index tchtItem read GetBitState;
    property HitAtPageTab: Boolean index tchtPageTab read GetBitState;
    property HitAtScrollButton: Boolean index tchtScrollButton read GetBitState;
    property HitAtScrollButtonArea: Boolean index tchtScrollButtonArea read GetBitState;
    property HitAtTitle: Boolean index tchtTitle read GetBitState;
    property HitPoint: TPoint read FHitPoint write SetHitPoint;
    property HitObject: TObject read FHitObject write SetHitObject;
    property HitX: Integer index 0 read GetPosValue write SetPosValue;
    property HitY: Integer index 1 read GetPosValue write SetPosValue;
    property Item: TdxTileControlItem read GetItem;
    property TileControl: TdxCustomTileControl read FOwner;
  end;

  { TdxTileControlItemNavigator }

  TdxTileControlItemNavigator = class
  private
    FController: TdxTileControlController;
    FCurrentNavigationItemOccupiedRow: Integer;
    FFocusItemOnCycle: Boolean;
    FPosition: TdxLayoutItemPosition;
    function GetCurrentNavigationItem: TdxTileControlItem;
    function GetCurrentNavigationItemColumn: Integer;
    function GetCurrentNavigationItemRow: Integer;
    function GetGroupLayout: TdxTileControlGroupLayout;
    function GetGroups: TdxTileControlGroupCollection;
    function GetItemByBackSearchOnColumns(AGroup: TdxTileControlGroup; AOriginalPosition: TdxLayoutItemPosition; const AEndColumn: Integer): TdxTileControlItem;
    function GetItemByBackSearchOnRows(AGroup: TdxTileControlGroup; AOriginalPosition: TdxLayoutItemPosition; const AEndRow: Integer): TdxTileControlItem;
    function GetItemByForwardSearchOnColumns(AGroup: TdxTileControlGroup; AOriginalPosition: TdxLayoutItemPosition; const AEndColumn: Integer): TdxTileControlItem;
    function GetItemByForwardSearchOnRows(AGroup: TdxTileControlGroup; AOriginalPosition: TdxLayoutItemPosition; const AEndRow: Integer): TdxTileControlItem;
    function GetNextItemInColumnAboveTheCurrentWhenHorizontalLayout(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetNextItemInColumnAboveTheCurrentWhenVerticalLayout(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetNextItemInColumnBelowTheCurrent(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetNextItemInNextRowWhenHorizontalLayout(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetNextItemInNextRowWhenVerticalLayout(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetNextItemInRowToRightHand(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetOccupiedItem(APosition: TdxLayoutItemPosition; AGroup: TdxTileControlGroup): TdxTileControlItem;
    function GetPrevItemInColumnBelowTheCurrentWhenHorizontalLayout(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetPrevItemInColumnBelowTheCurrentWhenVerticalLayout(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetPrevItemInColumnAboveTheCurrent(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetPrevItemInPrevRowWhenHorizontalLayout(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetPrevItemInPrevRowWhenVerticalLayout(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    function GetPrevItemInRowToLeftHand(APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
    procedure SetCurrentNavigationItem(AValue: TdxTileControlItem);
  protected
    function GetFirstItem: TdxTileControlItem; virtual;
    function GetFirstItemInRow: TdxTileControlItem; virtual;
    function GetLastItem: TdxTileControlItem; virtual;
    function GetLastItemInRow: TdxTileControlItem; virtual;
    function GetNextItemInColumn: TdxTileControlItem; virtual;
    function GetNextItemInRow: TdxTileControlItem; virtual;
    function GetPrevItemInColumn: TdxTileControlItem; virtual;
    function GetPrevItemInRow: TdxTileControlItem; virtual;

    property Controller: TdxTileControlController read FController;
    property CurrentNavigationItem: TdxTileControlItem read GetCurrentNavigationItem write SetCurrentNavigationItem;
    property CurrentNavigationItemColumn: Integer read GetCurrentNavigationItemColumn;
    property CurrentNavigationItemRow: Integer read GetCurrentNavigationItemRow;
    property GroupLayout: TdxTileControlGroupLayout read GetGroupLayout;
    property Groups: TdxTileControlGroupCollection read GetGroups;
  public
    constructor Create(AController: TdxTileControlController);
    destructor Destroy; override;
    function IsAcceptedKey(Key: Word): Boolean;
    procedure KeyDown(var Key: Word; Shift: TShiftState); virtual;
    procedure SaveCurrentNavigationItem;
  end;

  TdxTileItemInnerObjectAlignment = (oaDefault, oaTopLeft, oaTopCenter, oaTopRight, oaMiddleLeft,
    oaMiddleCenter, oaMiddleRight, oaBottomLeft, oaBottomCenter, oaBottomRight);
  TdxTileControlImageWithTextAlignment = (itaNone, itaLeft, itaTop, itaRight, itaBottom);

  { TdxTileControlItemPersistent }

  TdxTileControlItemPersistent = class(TcxOwnedPersistent)
  private
    function GetOwnerItem: TdxTileControlCustomItem;
  protected
    procedure Changed; virtual;
    function IsChanged: Boolean; virtual;
    //
    property Owner: TdxTileControlCustomItem read GetOwnerItem;
  end;

  { TdxTileControlItemText }

  TdxTileItemTextAssignedValue = (avColor, avTextColor, avFont);
  TdxTileItemTextAssignedValues = set of TdxTileItemTextAssignedValue;

  TdxTileControlItemText = class(TdxTileControlItemPersistent)
  private
    FAlign: TdxTileItemInnerObjectAlignment;
    FAlignment: TAlignment;
    FAssignedValues: TdxTileItemTextAssignedValues;
    FColor: TColor;
    FFont: TFont;
    FIndentHorz: Integer;
    FIndentVert: Integer;
    FTextColor: TColor;
    FTransparent: Boolean;
    FValue: string;
    FWordWrap: Boolean;
    function IsFontStored: Boolean;
    procedure SetAlign(AValue: TdxTileItemInnerObjectAlignment);
    procedure SetAlignment(AValue: TAlignment);
    procedure SetAssignedValues(AValue: TdxTileItemTextAssignedValues);
    procedure SetColor(AValue: TColor);
    procedure SetFont(AValue: TFont);
    procedure SetIndentHorz(AValue: Integer);
    procedure SetIndentVert(AValue: Integer);
    procedure SetTextColor(AValue: TColor);
    procedure SetTransparent(AValue: Boolean);
    procedure SetValue(const AValue: string);
    procedure SetWordWrap(AValue: Boolean);
  protected
    FDefaultAlign: TdxTileItemInnerObjectAlignment;
    procedure CalculateBounds(var ABounds: TRect);
    procedure FontChanged(Sender: TObject);
    function GetActualAlign: TdxTileItemInnerObjectAlignment;
    function GetActualColor: TColor;
    function GetActualFont: TFont;
    function GetActualFontColor: TColor;
    function GetActualValue: string;
    function GetTextOutFlags: Integer;
    function HasValue: Boolean;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;
  published
    property Align: TdxTileItemInnerObjectAlignment read FAlign write SetAlign default oaDefault;
    property Alignment: TAlignment read FAlignment write SetAlignment default taLeftJustify;
    property AssignedValues: TdxTileItemTextAssignedValues read FAssignedValues write SetAssignedValues;
    property Color: TColor read FColor write SetColor default clDefault;
    property Font: TFont read FFont write SetFont stored IsFontStored;
    property IndentHorz: Integer read FIndentHorz write SetIndentHorz default dxTileItemObjectDefaultIndent;
    property IndentVert: Integer read FIndentVert write SetIndentVert default dxTileItemObjectDefaultIndent;
    property Value: string read FValue write SetValue;
    property TextColor: TColor read FTextColor write SetTextColor default clDefault;
    property Transparent: Boolean read FTransparent write SetTransparent default True;
    property WordWrap: Boolean read FWordWrap write SetWordWrap default False;
  end;

  { TdxTileControlItemGlyph }

  TdxTileControlItemGlyph = class(TdxTileControlItemPersistent)
  private
    FAlign: TdxTileItemInnerObjectAlignment;
    FAlignWithText: TdxTileControlImageWithTextAlignment;
    FImage: TdxSmartImage;
    FIndentHorz: Integer;
    FIndentVert: Integer;
    FMode: TcxImageFitMode;
    procedure ImageChanged(Sender: TObject);
    procedure SetAlign(AValue: TdxTileItemInnerObjectAlignment);
    procedure SetAlignWithText(AValue: TdxTileControlImageWithTextAlignment);
    procedure SetImage(AValue: TdxSmartImage);
    procedure SetIndentHorz(AValue: Integer);
    procedure SetIndentVert(AValue: Integer);
    procedure SetMode(AValue: TcxImageFitMode);
  protected
    function GetActualAlign: TdxTileItemInnerObjectAlignment;
    function GetClientRect(const ABounds: TRect): TRect;
    function IsChanged: Boolean; override;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;
  published
    property Align: TdxTileItemInnerObjectAlignment read FAlign write SetAlign default oaDefault;
    property AlignWithText: TdxTileControlImageWithTextAlignment read FAlignWithText write SetAlignWithText default itaNone;
    property Image: TdxSmartImage read FImage write SetImage;
    property IndentHorz: Integer read FIndentHorz write SetIndentHorz default dxTileItemObjectDefaultIndent;
    property IndentVert: Integer read FIndentVert write SetIndentVert default dxTileItemObjectDefaultIndent;
    property Mode: TcxImageFitMode read FMode write SetMode default ifmNormal;
  end;

  { TdxTileControlCustomStyle }

  TdxTileControlCustomStyle = class(TcxOwnedPersistent)
  private
    FBorderColor: TColor;
    FFont: TFont;
    FFontChanged: Boolean;
    FGradient: TdxSkinGradientMode;
    FGradientBeginColor: TColor;
    FGradientEndColor: TColor;
    FStretch: TdxSkinStretchMode;
    FTexture: TdxSmartImage;
    FOnChange: TNotifyEvent;
    procedure ImageChanged(Sender: TObject);
    function IsFontStored: Boolean;
    procedure SetBorderColor(AValue: TColor);
    procedure SetFont(AValue: TFont);
    procedure SetGradientBeginColor(AValue: TColor);
    procedure SetGradientEndColor(AValue: TColor);
    procedure SetGradientMode(AValue: TdxSkinGradientMode);
    procedure SetStretch(AValue: TdxSkinStretchMode);
    procedure SetTexture(AValue: TdxSmartImage);
  protected
    procedure Changed; virtual;
    procedure FontChanged(Sender: TObject);
    function IsChanged: Boolean; virtual;
    function IsEmpty: Boolean; virtual;

    property OnChange: TNotifyEvent read FOnChange write FOnChange;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;
  published
    property BorderColor: TColor read FBorderColor write SetBorderColor default clDefault;
    property Font: TFont read FFont write SetFont stored IsFontStored;
    property Gradient: TdxSkinGradientMode read FGradient write SetGradientMode default gmHorizontal;
    property GradientBeginColor: TColor read FGradientBeginColor write SetGradientBeginColor default clDefault;
    property GradientEndColor: TColor read FGradientEndColor write SetGradientEndColor default clDefault;
    property Stretch: TdxSkinStretchMode read FStretch write SetStretch default smStretch;
    property Texture: TdxSmartImage read FTexture write SetTexture;
  end;

  { TdxTileControlCustomItemOptionsAnimate }

  TdxTileControlItemOptionsAnimateAssignedValue = (ioaavAnimateText);
  TdxTileControlItemOptionsAnimateAssignedValues = set of TdxTileControlItemOptionsAnimateAssignedValue;

  TdxTileControlCustomItemOptionsAnimate = class(TcxOwnedPersistent)
  private
    FAnimateText: Boolean;
    FAssignedValues: TdxTileControlItemOptionsAnimateAssignedValues;
    function GetAnimateText: Boolean;
    function IsAnimateTextStored: Boolean;
    procedure SetAnimateText(AValue: Boolean);
  protected
    procedure DoAssign(Source: TPersistent); override;
    function GetParentOptionsAnimate: TdxTileControlCustomItemOptionsAnimate; virtual;
    //
    property AssignedValues: TdxTileControlItemOptionsAnimateAssignedValues read FAssignedValues write FAssignedValues stored False;
    property ParentOptionsAnimate: TdxTileControlCustomItemOptionsAnimate read GetParentOptionsAnimate;
  public
    constructor Create(AOwner: TPersistent); override;
  published
    property AnimateText: Boolean read GetAnimateText write SetAnimateText stored IsAnimateTextStored;
  end;

  { TdxTileControlCustomItemViewData }

  TdxTileControlCustomItemViewData = class
  private
    FClientRect: TRect;
    FImage: TdxGPImage;
    FImageBounds: TRect;
    FIsDirty: Boolean;
    FItem: TdxTileControlCustomItem;
    FNeedDrawTextOnImage: Boolean;
    FTextBounds: array[0..3] of TRect;
    function GetBounds: TRect;
    function GetImage: TdxGPImage;
    function GetIsActive: Boolean;
    function GetPainter: TdxTileControlPainter;
    function GetTextBounds(AIndex: Integer): TRect;
    function GetTileItem: TdxTileControlItem;
    procedure SetIsDirty(AValue: Boolean);
    procedure SetNeedDrawTextOnImage(AValue: Boolean);
  protected
    procedure AdjustObjectBounds(const ABounds: TRect; var AObjectBounds: TRect;
      AAlign: TdxTileItemInnerObjectAlignment; AIndentHorz, AIndentVert: Integer);
    procedure AdjustImageBoundsWithText(const ABounds: TRect; AText: TdxTileControlItemText; var AImageBounds, ATextBounds: TRect);
    procedure CalculateImageAndTextLayout(const ABounds: TRect);
    procedure DrawItemBackground(const ACanvas: TcxCanvas); virtual;
    procedure DrawItemGlyph(const ACanvas: TcxCanvas); virtual;
    procedure DrawItemText(const ACanvas: TcxCanvas; const AIndex: Integer); virtual;
    procedure DrawItemTexts(const ACanvas: TcxCanvas); virtual;
    procedure PrepareViewData; virtual;
  public
    constructor Create(AItem: TdxTileControlCustomItem); virtual;
    destructor Destroy; override;
    procedure ValidateViewData;
    //
    property Bounds: TRect read GetBounds;
    property ClientRect: TRect read FClientRect;
    property Image: TdxGPImage read GetImage;
    property ImageBounds: TRect read FImageBounds;
    property IsActive: Boolean read GetIsActive;
    property IsDirty: Boolean read FIsDirty write SetIsDirty;
    property Item: TdxTileControlCustomItem read FItem;
    property NeedDrawTextOnImage: Boolean read FNeedDrawTextOnImage write SetNeedDrawTextOnImage;
    property Painter: TdxTileControlPainter read GetPainter;
    property TextBounds[Index: Integer]: TRect read GetTextBounds;
    property TileItem: TdxTileControlItem read GetTileItem;
  end;

  { TdxTileControlItemOptionsAnimate }

  TdxTileControlItemOptionsAnimate = class(TdxTileControlCustomItemOptionsAnimate)
  protected
    function GetParentOptionsAnimate: TdxTileControlCustomItemOptionsAnimate; override;
  published
    property AssignedValues;
  end;

  { TdxTileControlCustomItem }

  TdxTileControlCustomItem = class(TcxComponentCollectionItem)
  private
    FGlyph: TdxTileControlItemGlyph;
    FMargins: TcxMargin;
    FOptionsAnimate: TdxTileControlItemOptionsAnimate;
    FParentStyle: Boolean;
    FStyle: TdxTileControlCustomStyle;
    FTexts: array [0 .. 3] of TdxTileControlItemText;
    FViewData: TdxTileControlCustomItemViewData;
    FVisible: Boolean;
    function GetText(Index: Integer): TdxTileControlItemText;
    function IsGlyphStored: Boolean;
    function IsMarginsStored: Boolean;
    function IsStyleStored: Boolean;
    procedure MarginsChangeHandler(Sender: TObject);
    procedure SetGlyph(AValue: TdxTileControlItemGlyph);
    procedure SetMargins(AValue: TcxMargin);
    procedure SetOptionsAnimate(AValue: TdxTileControlItemOptionsAnimate);
    procedure SetParentStyle(AValue: Boolean);
    procedure SetStyle(AValue: TdxTileControlCustomStyle);
    procedure SetText(AIndex: Integer; AValue: TdxTileControlItemText);
    procedure SetVisible(AValue: Boolean);
  protected
    procedure Changed; virtual;
    function CreateOptionsAnimate: TdxTileControlItemOptionsAnimate; virtual; abstract;
    function CreateText(const AAlign: TdxTileItemInnerObjectAlignment): TdxTileControlItemText; virtual;
    function CreateViewData: TdxTileControlCustomItemViewData; virtual;
    function GetTileItem: TdxTileControlItem; virtual;
    procedure StyleChanged(Sender: TObject);
    //
    property OptionsAnimate: TdxTileControlItemOptionsAnimate read FOptionsAnimate write SetOptionsAnimate;
    property ParentStyle: Boolean read FParentStyle write SetParentStyle default True;
    property ViewData: TdxTileControlCustomItemViewData read FViewData;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;
    //
    property Glyph: TdxTileControlItemGlyph read FGlyph write SetGlyph stored IsGlyphStored;
    property Margins: TcxMargin read FMargins write SetMargins stored IsMarginsStored;
    property Style: TdxTileControlCustomStyle read FStyle write SetStyle stored IsStyleStored;
    property Text1: TdxTileControlItemText index 0 read GetText write SetText;
    property Text2: TdxTileControlItemText index 1 read GetText write SetText;
    property Text3: TdxTileControlItemText index 2 read GetText write SetText;
    property Text4: TdxTileControlItemText index 3 read GetText write SetText;
    property TileItem: TdxTileControlItem read GetTileItem;
    property Visible: Boolean read FVisible write SetVisible default True;
  end;

  { TdxTileControlItemFrameOptionsAnimate }

  TdxTileControlItemFrameOptionsAnimate = class(TdxTileControlItemOptionsAnimate)
  protected
    function GetParentOptionsAnimate: TdxTileControlCustomItemOptionsAnimate; override;
  end;

  { TdxTileControlItemFrame }

  TdxTileControlItemFrame = class(TdxTileControlCustomItem)
  private
    FData: Pointer;
  protected
    procedure Changed; override;
    function CreateOptionsAnimate: TdxTileControlItemOptionsAnimate; override;
    function GetCollectionFromParent(AParent: TComponent): TcxComponentCollection; override;
    function GetTileItem: TdxTileControlItem; override;
  public
    destructor Destroy; override;
    property Data: Pointer read FData write FData;
  published
    property ParentStyle;
    property Style;
    property Glyph;
    property Margins;
    property OptionsAnimate;
    property Text1;
    property Text2;
    property Text3;
    property Text4;
    property Visible;
  end;

  { TdxTileControlItemFrames }

  TdxTileControlForEachItemFrameProc = procedure(AItem: TdxTileControlItemFrame; const AData: Pointer) of object;

  TdxTileControlItemFrames = class(TcxComponentCollection)
  private
    function GetItem(AIndex: Integer): TdxTileControlItemFrame;
    function GetOwnerItem: TdxTileControlItem;
    procedure SetItem(AIndex: Integer; const AValue: TdxTileControlItemFrame);
  protected
    procedure ForEach(AProc: TdxTileControlForEachItemFrameProc; const AData: Pointer);
  public
    function Add: TdxTileControlItemFrame;
    //
    property Owner: TdxTileControlItem read GetOwnerItem;
    property Items[Index: Integer]: TdxTileControlItemFrame read GetItem write SetItem; default;
  end;

  { TdxTileControlItemDetailOptions }

  TdxTileControlItemDetailOptions = class(TcxOwnedPersistent)
  private
    FCaption: string;
    FDetailControl: TWinControl;
    FDetailSite: TdxTileControlDetailSite;
    FShowTab: Boolean;
    function GetHasDetail: Boolean;
    function GetDetailSite: TdxTileControlDetailSite;
    function GetTileControl: TdxCustomTileControl;
    function GetTileItem: TdxTileControlItem;
    procedure SetCaption(AValue: string);
    procedure SetDetailControl(AValue: TWinControl);
  protected
    procedure Changed; virtual;
    function IsChanged: Boolean; virtual;
  public
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;

    property HasDetail: Boolean read GetHasDetail;
    property DetailSite: TdxTileControlDetailSite read GetDetailSite;
    property TileControl: TdxCustomTileControl read GetTileControl; 
    property TileItem: TdxTileControlItem read GetTileItem;
  published
    property Caption: string read FCaption write SetCaption;
    property DetailControl: TWinControl read FDetailControl write SetDetailControl;
    property ShowTab: Boolean read FShowTab write FShowTab default False;
  end;

  { TdxTileControlItem }

  TdxTileControlItemFrameEvent = procedure(Sender: TdxTileControlItemFrame) of object;
  TdxTileControlItemEvent = procedure(Sender: TdxTileControlItem) of object;

  TdxTileControlItem = class(TdxTileControlCustomItem, IcxStoredObject)
  private
    FActiveFrameIndex: Integer;
    FActiveTransitions: TcxObjectList;
    FAnimationInterval: Integer;
    FAnimationMode: TdxDrawAnimationMode;
    FAnimationTimer: TcxTimer;
    FChecked: Boolean;
    FDetailOptions: TdxTileControlItemDetailOptions;
    FFrames: TdxTileControlItemFrames;
    FGroup: TdxTileControlGroup;
    FIndexInGroupAtLoaded: Integer;
    FIsActive: Boolean;
    FIsLarge: Boolean;
    FRowCount: Integer;
    FViewInfo: TdxTileControlItemViewInfo;
    FOnActivateDetail: TdxTileControlItemEvent;
    FOnActiveFrameChanged: TdxTileControlItemEvent;
    FOnDeactivateDetail: TdxTileControlItemEvent;
    FOnClick: TdxTileControlItemEvent;
    FOnFrameDestroy: TdxTileControlItemFrameEvent;
    FOnFrameInitialize: TdxTileControlItemFrameEvent;
    // IcxStoredObject events
    FOnGetStoredProperties: TcxGetStoredPropertiesEvent;
    FOnGetStoredPropertyValue: TcxGetStoredPropertyValueEvent;
    FOnSetStoredPropertyValue: TcxSetStoredPropertyValueEvent;

    function GetActiveFrame: TdxTileControlItemFrame;
    function GetActuallyVisible: Boolean;
    function GetController: TdxTileControlController;
    function GetGroupIndex: Integer;
    function GetGroupLayout: TdxTileControlGroupLayout;
    function GetIndexInGroup: Integer;
    function GetIsAnimationActive: Boolean;
    function GetIsMostLeft: Boolean;
    function GetIsMostRight: Boolean;
    function GetTileControl: TdxCustomTileControl;
    function GetVisibleFramesCount: Integer;
    function IsDetailOptionsStored: Boolean;
    procedure RefreshFrame(AItem: TdxTileControlItemFrame; const AData: Pointer);
    procedure SetActiveFrame(AValue: TdxTileControlItemFrame);
    procedure SetActiveFrameIndex(AValue: Integer);
    procedure SetAnimationInterval(AValue: Integer);
    procedure SetChecked(AValue: Boolean);
    procedure SetDetailOptions(AValue: TdxTileControlItemDetailOptions);
    procedure SetFrames(AValue: TdxTileControlItemFrames);
    procedure SetGroup(AValue: TdxTileControlGroup);
    procedure SetGroupIndex(AValue: Integer);
    procedure SetIndexInGroup(AValue: Integer);
    procedure SetIsLarge(AValue: Boolean);
    procedure SetRowCount(AValue: Integer);
    procedure SetOnActivateDetail(AValue: TdxTileControlItemEvent);

    property GroupLayout: TdxTileControlGroupLayout read GetGroupLayout;
  protected
    procedure ActiveFrameChanged; virtual;
    procedure AddTransition(ATransition: TdxAnimationTransition);
    procedure AnimationTimerHandler(Sender: TObject);
    procedure Changed; override;
    procedure CheckTimerEnabled;
    function CheckViewDataInitialized(AViewData: TdxTileControlCustomItemViewData): TdxTileControlCustomItemViewData;
    function CreateDetailOptions: TdxTileControlItemDetailOptions; virtual;
    function CreateDetailSite: TdxTileControlDetailSite; virtual;
    function CreateFrames: TdxTileControlItemFrames; virtual;
    function CreateOptionsAnimate: TdxTileControlItemOptionsAnimate; override;
    function CreateViewInfo: TdxTileControlItemViewInfo; virtual;
    procedure DoActivateDetail; virtual;
    procedure DoActiveFrameChanged; virtual;
    procedure DoClick; virtual;
    procedure DoDeactivateDetail; virtual;
    procedure DoFrameDestroy(AFrame: TdxTileControlItemFrame); virtual;
    procedure DoFrameInitialize(AFrame: TdxTileControlItemFrame); virtual;
    procedure FrameChanged(AFrame: TdxTileControlCustomItem); virtual;
    function GetActualViewData: TdxTileControlCustomItemViewData;
    function GetClientBounds: TRect;
    function GetCollectionFromParent(AParent: TComponent): TcxComponentCollection; override;
    function GetTileItem: TdxTileControlItem; override;
    procedure Invalidate;
    function IsDragged: Boolean;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure Refresh;
    procedure RemoveTransition(ATransition: TdxAnimationTransition);
    procedure SetName(const NewName: TComponentName); override;
    procedure StopTransitions;
    procedure ToggleChecked;
    // IcxStoredObject
    function GetObjectName: string;
    function GetProperties(AProperties: TStrings): Boolean; virtual;
    function GetPropertyIndex(const AName: string): Integer;
    procedure GetPropertyValue(const AName: string; var AValue: Variant); virtual;
    procedure SetPropertyValue(const AName: string; const AValue: Variant); virtual;

    property ActiveTransitions: TcxObjectList read FActiveTransitions;
    property AnimationTimer: TcxTimer read FAnimationTimer;
    property Controller: TdxTileControlController read GetController;
    property IsAnimationActive: Boolean read GetIsAnimationActive;
    property IsActive: Boolean read FIsActive write FIsActive;
    property VisibleFramesCount: Integer read GetVisibleFramesCount;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;
    procedure ActivateDetail;
    procedure Click;
    procedure DeactivateDetail;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    procedure MakeVisible;
    procedure Move(AGroupDest: TdxTileControlGroup; AIndexDest: Integer);
    procedure RemoveFromGroup;

    property ActiveFrame: TdxTileControlItemFrame read GetActiveFrame write SetActiveFrame;
    property ActiveFrameIndex: Integer read FActiveFrameIndex write SetActiveFrameIndex;
    property ActuallyVisible: Boolean read GetActuallyVisible;
    property Checked: Boolean read FChecked write SetChecked default False;
    property Group: TdxTileControlGroup read FGroup write SetGroup;
    property IsMostLeft: Boolean read GetIsMostLeft;
    property IsMostRight: Boolean read GetIsMostRight;
    property TileControl: TdxCustomTileControl read GetTileControl;
    property ViewInfo: TdxTileControlItemViewInfo read FViewInfo;
  published
    property AnimationInterval: Integer read FAnimationInterval write SetAnimationInterval default dxTileControlDefaultAnimationInterval;
    property AnimationMode: TdxDrawAnimationMode read FAnimationMode write FAnimationMode default dxTileControlDefaultAnimationMode;
    property DetailOptions: TdxTileControlItemDetailOptions read FDetailOptions write SetDetailOptions stored IsDetailOptionsStored;
    property GroupIndex: Integer read GetGroupIndex write SetGroupIndex;
    property IndexInGroup: Integer read GetIndexInGroup write SetIndexInGroup;
    property IsLarge: Boolean read FIsLarge write SetIsLarge default False;
    property Frames: TdxTileControlItemFrames read FFrames write SetFrames;
    property RowCount: Integer read FRowCount write SetRowCount default dxTileControlDefaultItemRowCount;

    property Style;
    property Glyph;
    property Margins;
    property OptionsAnimate;
    property Text1;
    property Text2;
    property Text3;
    property Text4;
    property Visible;
    // Events
    property OnActivateDetail: TdxTileControlItemEvent read FOnActivateDetail write SetOnActivateDetail;
    property OnActiveFrameChanged: TdxTileControlItemEvent read FOnActiveFrameChanged write FOnActiveFrameChanged;
    property OnClick: TdxTileControlItemEvent read FOnClick write FOnClick;
    property OnDeactivateDetail: TdxTileControlItemEvent read FOnDeactivateDetail write FOnDeactivateDetail;
    property OnFrameDestroy: TdxTileControlItemFrameEvent read FOnFrameDestroy write FOnFrameDestroy;
    property OnFrameInitialize: TdxTileControlItemFrameEvent read FOnFrameInitialize write FOnFrameInitialize;
    // IcxStoredObject events
    property OnGetStoredProperties: TcxGetStoredPropertiesEvent read FOnGetStoredProperties write FOnGetStoredProperties;
    property OnGetStoredPropertyValue: TcxGetStoredPropertyValueEvent read FOnGetStoredPropertyValue write FOnGetStoredPropertyValue;
    property OnSetStoredPropertyValue: TcxSetStoredPropertyValueEvent read FOnSetStoredPropertyValue write FOnSetStoredPropertyValue;
  end;

  { TdxTileControlCustomStoredCollection }

  TdxTileControlCustomStoredCollection = class(TcxComponentCollection,
    IcxStoredObject, IcxStoredParent)
  private
    function GetTileControl: TdxCustomTileControl;
    // IcxStoredParent
    function IcxStoredParent.CreateChild = StoredCreateChild;
    procedure IcxStoredParent.DeleteChild = StoredDeleteChild;
    procedure IcxStoredParent.GetChildren = StoredChildren;
  protected
    function GetItemPrefixName: string; override;
    // IInterface
    function QueryInterface(const IID: TGUID; out Obj): HResult; stdcall;
    function _AddRef: Integer; stdcall;
    function _Release: Integer; stdcall;
    // IcxStoredObject }
    function GetObjectName: string; virtual;
    function GetProperties(AProperties: TStrings): Boolean; virtual;
    procedure GetPropertyValue(const AName: string; var AValue: Variant); virtual;
    procedure SetPropertyValue(const AName: string; const AValue: Variant); virtual;
    // IcxStoredParent implementation
    function StoredCreateChild(const AObjectName, AClassName: string): TObject; virtual;
    procedure StoredDeleteChild(const AObjectName: string; AObject: TObject); virtual;
    procedure StoredChildren(AChildren: TStringList); virtual;
  public
    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlItemCollection }

  TdxTileControlItemChangeEvent = procedure(AItem: TcxComponentCollectionItem) of object;
  TdxTileControlForEachItemProc = procedure(AItem: TdxTileControlItem; const AData: Pointer) of object;

  TdxTileControlItemCollection = class(TdxTileControlCustomStoredCollection)
  private
    function GetItem(AIndex: Integer): TdxTileControlItem;
    procedure SetItem(AIndex: Integer; const AValue: TdxTileControlItem);
  protected
    procedure ForEach(AProc: TdxTileControlForEachItemProc; const AData: Pointer; AVisibleOnly: Boolean = True);
    // IcxStoredObject
    function GetObjectName: string; override;
    // IcxStoredParent implementation
    function StoredCreateChild(const AObjectName, AClassName: string): TObject; override;
    procedure StoredChildren(AChildren: TStringList); override;
  public
    function Add: TdxTileControlItem;

    property Items[Index: Integer]: TdxTileControlItem read GetItem write SetItem; default;
  end;

  TdxTileControlItemCollectionClass = class of TdxTileControlItemCollection;

  { TdxTileControlGroup }

  TdxTileControlGroup = class(TcxComponentCollectionItem, IcxStoredObject, IcxStoredParent)
  private
    FCaption: TdxTileControlGroupCaption;
    FItems: TcxObjectList;
    FViewInfo: TdxTileControlGroupViewInfo;
    FVirtualGroupBefore: TdxTileControlVirtualGroupViewInfo;
    FVirtualGroupAfter: TdxTileControlVirtualGroupViewInfo;
    FVisible: Boolean;
    FTileControl: TdxCustomTileControl;
    // IcxStoredObject events
    FOnGetStoredProperties: TcxGetStoredPropertiesEvent;
    FOnGetStoredPropertyValue: TcxGetStoredPropertyValueEvent;
    FOnSetStoredPropertyValue: TcxSetStoredPropertyValueEvent;

    procedure AssignFrom(AGroup: TdxTileControlGroup; AExcludeItem: TdxTileControlItem = nil);
    function GetBounds: TRect;
    function GetExpandedBounds: TRect;
    function GetGroupLayout: TdxTileControlGroupLayout;
    function GetGroups: TdxTileControlGroupCollection;
    function GetItem(AIndex: Integer): TdxTileControlItem;
    function GetItemCount: Integer;
    function GetIsMostLeft: Boolean;
    function GetIsMostRight: Boolean;
    function GetMaximizedAreaBounds: TRect;
    function GetRealColumnCount: Integer;
    function GetRealRowCount: Integer;
    function IsCaptionStored: Boolean;
    procedure SetCaption(AValue: TdxTileControlGroupCaption);
    procedure SetVisible(AValue: Boolean);
    // IcxStoredParent
    function IcxStoredParent.CreateChild = StoredCreateChild;
    procedure IcxStoredParent.DeleteChild = StoredDeleteChild;
    procedure IcxStoredParent.GetChildren = StoredChildren;

    property GroupLayout: TdxTileControlGroupLayout read GetGroupLayout;
  protected
    procedure GroupChanged; virtual;
    function GetCollectionFromParent(AParent: TComponent): TcxComponentCollection; override;
    procedure Invalidate;
    function IsDragged: Boolean;
    procedure SetCollection(AValue: TcxComponentCollection); override;
    procedure SetIndex(AValue: Integer); override;
    procedure SetIndexForHorzLayout(AValue: Integer);
    procedure SetIndexForVertLayout(AValue: Integer);
    procedure UpdateTileControlLink;
    // IcxStoredObject
    function GetObjectName: string;
    function GetProperties(AProperties: TStrings): Boolean; virtual;
    procedure GetPropertyValue(const AName: string; var AValue: Variant); virtual;
    procedure SetPropertyValue(const AName: string; const AValue: Variant); virtual;
    // IcxStoredParent implementation
    function StoredCreateChild(const AObjectName, AClassName: string): TObject; virtual;
    procedure StoredDeleteChild(const AObjectName: string; AObject: TObject); virtual;
    procedure StoredChildren(AChildren: TStringList); virtual;

    property Bounds: TRect read GetBounds;
    property ExpandedBounds: TRect read GetExpandedBounds;
    property MaximizedAreaBounds: TRect read GetMaximizedAreaBounds;
    property ItemsList: TcxObjectList read FItems;
    property IsMostLeft: Boolean read GetIsMostLeft;
    property IsMostRight: Boolean read GetIsMostRight;
    property RealColumnCount: Integer read GetRealColumnCount;
    property RealRowCount: Integer read GetRealRowCount;
    property ViewInfo: TdxTileControlGroupViewInfo read FViewInfo;
    property VirtualGroupBefore: TdxTileControlVirtualGroupViewInfo read FVirtualGroupBefore;
    property VirtualGroupAfter: TdxTileControlVirtualGroupViewInfo read FVirtualGroupAfter;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Add(AItem: TdxTileControlItem);
    procedure DeleteItem(AItem: TdxTileControlItem);
    procedure DeleteItems;
    function IndexOfItem(AItem: TdxTileControlItem): Integer;
    procedure MakeVisible;
    procedure MoveItem(AItem: TdxTileControlItem; AIndexDest: Integer);
    procedure RemoveItem(AItem: TdxTileControlItem);
    procedure RemoveItems;

    property Groups: TdxTileControlGroupCollection read GetGroups;
    property ItemCount: Integer read GetItemCount;
    property Items[Index: Integer]: TdxTileControlItem read GetItem;
    property TileControl: TdxCustomTileControl read FTileControl;
  published
    property Caption: TdxTileControlGroupCaption read FCaption write SetCaption stored IsCaptionStored;
    property Visible: Boolean read FVisible write SetVisible default True;
    property Index;
    // IcxStoredObject events
    property OnGetStoredProperties: TcxGetStoredPropertiesEvent
      read FOnGetStoredProperties write FOnGetStoredProperties;
    property OnGetStoredPropertyValue: TcxGetStoredPropertyValueEvent
      read FOnGetStoredPropertyValue write FOnGetStoredPropertyValue;
    property OnSetStoredPropertyValue: TcxSetStoredPropertyValueEvent
      read FOnSetStoredPropertyValue write FOnSetStoredPropertyValue;
  end;

  { TdxTileControlGroupCaptionViewInfo }

  TdxTileControlGroupCaptionViewInfo = class(TdxTileControlAnimatedDragAndDropCustomCellViewInfo)
  private
    FCaption: TdxTileControlGroupCaption;
    FFont: TFont;
    FHeight: Integer;
    FIndent: Integer;
    FTextBounds: TRect;
    function GetGroup: TdxTileControlGroup;
    function GetHeight: Integer;
    function GetPainter: TdxTileControlPainter;
    procedure SetHeight(AValue: Integer);
  protected
    procedure CalculateBounds; virtual;
    procedure DoCalculate; override;
    procedure DoDraw(ACanvas: TcxCanvas); override;
    procedure DrawContent(ACanvas: TcxCanvas; const ADrawRect: TRect); override;
    function GetBaseDrawBounds: TRect; override;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetTextBounds(ABounds: TRect): TRect;
    function GetTextColor: TColor;
    function GetTextOutFlags: Integer;
    function GetTileControl: TdxCustomTileControl; override;
    function GetVisibleBounds: TRect; override;
    procedure MeasureHeight; virtual;
    procedure Offset(const DX, DY: Integer);  override;
    procedure Scroll(const DX, DY: Integer); override;

    property Caption: TdxTileControlGroupCaption read FCaption;
    property Height: Integer read GetHeight write SetHeight;
    property Painter: TdxTileControlPainter read GetPainter;
  public
    constructor Create(AOwner: TdxTileControlGroupCaption); virtual;
    destructor Destroy; override;

    property Font: TFont read FFont;
    property Group: TdxTileControlGroup read GetGroup;
    property TextColor: TColor read GetTextColor;
  end;

  { TdxTileControlGroupCaption }

  TdxTileControlGroupCaption = class(TcxOwnedPersistent)
  private
    FAlignment: TAlignment;
    FColor: TColor;
    FFont: TFont;
    FFontChanged: Boolean;
    FGroup: TdxTileControlGroup;
    FText: string;
    FViewInfo: TdxTileControlGroupCaptionViewInfo;
    function GetBounds: TRect;
    function GetHeight: Integer;
    function GetTileControl: TdxCustomTileControl;
    function IsFontStored: Boolean;
    procedure MeasureHeight;
    procedure SetAlignment(AValue: TAlignment);
    procedure SetColor(AValue: TColor);
    procedure SetFont(AValue: TFont);
    procedure SetHeight(AHeight: Integer);
    procedure SetText(AValue: string);
  protected
    procedure Changed; virtual;
    procedure FontChanged(Sender: TObject); virtual;
    function IsChanged: Boolean; virtual;

    property Bounds: TRect read GetBounds;
    property Group: TdxTileControlGroup read FGroup;
    property Height: Integer read GetHeight;
    property TileControl: TdxCustomTileControl read GetTileControl;
    property ViewInfo: TdxTileControlGroupCaptionViewInfo read FViewInfo;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;
  published
    property Color: TColor read FColor write SetColor default clDefault;
    property Alignment: TAlignment read FAlignment write SetAlignment default taLeftJustify;
    property Font: TFont read FFont write SetFont stored IsFontStored;
    property Text: string read FText write SetText;
  end;

  { TdxTileControlGroupCollection }

  TdxTileControlGroupCollection = class(TdxTileControlCustomStoredCollection)
  private
    function GetItem(AIndex: Integer): TdxTileControlGroup;
    procedure SetItem(AIndex: Integer; const AValue: TdxTileControlGroup);
  protected
    function GetNextVisibleGroup(AGroup: TdxTileControlGroup): TdxTileControlGroup;
    function GetPrevVisibleGroup(AGroup: TdxTileControlGroup): TdxTileControlGroup;

    procedure Loaded; virtual;
    procedure Update(AItem: TcxComponentCollectionItem;
      AAction: TcxComponentCollectionNotification); override;
    // IcxStoredObject }
    function GetObjectName: string; override;
    // IcxStoredParent implementation
    function StoredCreateChild(const AObjectName, AClassName: string): TObject; override;
    procedure StoredDeleteChild(const AObjectName: string; AObject: TObject); override;
  public
    function Add: TdxTileControlGroup;
    function Insert(AIndex: Integer): TdxTileControlGroup;

    property Items[Index: Integer]: TdxTileControlGroup read GetItem write SetItem; default;
  end;

  TdxTileControlGroupCollectionClass = class of TdxTileControlGroupCollection;

  { TdxTileControlStyle }

  TdxTileControlStyle = class(TdxTileControlCustomStyle)
  private
    FCheckedItemCheckMarkColor: TColor;
    FCheckedItemFrameColor: TColor;
    FFocusedColor: TColor;
    procedure SetCheckedItemCheckMarkColor(AValue: TColor);
    procedure SetCheckedItemFrameColor(AValue: TColor);
    procedure SetFocusedColor(AValue: TColor);
  public
    constructor Create(AOwner: TPersistent); override;
    procedure Assign(ASource: TPersistent); override;
  published
    property CheckedItemCheckMarkColor: TColor read FCheckedItemCheckMarkColor write SetCheckedItemCheckMarkColor default clDefault;
    property CheckedItemFrameColor: TColor read FCheckedItemFrameColor write SetCheckedItemFrameColor default clDefault;
    property FocusedColor: TColor read FFocusedColor write SetFocusedColor default clDefault;
  end;

  { TdxTileControlOptionsBehavior }

  TdxTileControlOptionsBehavior = class(TcxOwnedPersistent)
  private
    FBackgroundScrollSync: Byte;
    FFocusItemOnCycle: Boolean;
    FGroupMoving: Boolean;
    FHideFocusOnItemHotTrack: Boolean;
    FItemCheckMode: TdxTileControlItemCheckMode;
    FItemHotTrack: Boolean;
    FItemMoving: Boolean;
    FScrollMode: TdxTileControlScrollMode;
    function GetTileControl: TdxCustomTileControl;
    procedure SetBackgroundScrollSync(AValue: Byte);
    procedure SetItemCheckMode(AValue: TdxTileControlItemCheckMode);
    procedure SetScrollMode(AValue: TdxTileControlScrollMode);
  protected
    procedure Changed; virtual;
    property TileControl: TdxCustomTileControl read GetTileControl;
  public
    constructor Create(AOwner: TPersistent); override;
    procedure Assign(ASource: TPersistent); override;
  published
    property BackgroundScrollSync: Byte read FBackgroundScrollSync write SetBackgroundScrollSync default dxTileControlDefaultScrollSync;
    property FocusItemOnCycle: Boolean read FFocusItemOnCycle write FFocusItemOnCycle default True;
    property GroupMoving: Boolean read FGroupMoving write FGroupMoving default False;
    property HideFocusOnItemHotTrack: Boolean read FHideFocusOnItemHotTrack write FHideFocusOnItemHotTrack default False;
    property ItemCheckMode: TdxTileControlItemCheckMode read FItemCheckMode write SetItemCheckMode default tcicmMultiple;
    property ItemHotTrack: Boolean read FItemHotTrack write FItemHotTrack default True;
    property ItemMoving: Boolean read FItemMoving write FItemMoving default True;
    property ScrollMode: TdxTileControlScrollMode read FScrollMode write SetScrollMode default smScrollbars;
  end;

  { TdxTileControlOptionsView }

  TdxTileControlOptionsView = class(TcxOwnedPersistent)
  private
    FCenterContentHorz: Boolean;
    FCenterContentVert: Boolean;
    FGroupIndent: Integer;
    FIndentHorz: Integer;
    FIndentVert: Integer;
    FItemIndent: Integer;
    FItemSize: Integer;
    FGroupLayout: TdxTileControlGroupLayout;
    FGroupMaxRowCount: Integer;
    FVirtualGroupWidth: Integer;
    function GetMaxItemRowCount: Integer;
    function GetVirtualGroupWidth(const AGroupIndent, AItemIndent: Integer): Integer;
    function GetTileControl: TdxCustomTileControl;
    procedure SetCenterContentHorz(AValue: Boolean);
    procedure SetCenterContentVert(AValue: Boolean);
    procedure SetGroupIndent(AValue: Integer);
    procedure SetIndentHorz(AValue: Integer);
    procedure SetIndentVert(AValue: Integer);
    procedure SetItemIndent(AValue: Integer);
    procedure SetItemSize(AValue: Integer);
    procedure SetGroupLayout(AValue: TdxTileControlGroupLayout);
    procedure SetGroupMaxRowCount(AValue: Integer);
  protected
    procedure Changed; virtual;

    property TileControl: TdxCustomTileControl read GetTileControl;
    property VirtualGroupWidth: Integer read FVirtualGroupWidth;
  public
    constructor Create(AOwner: TPersistent); override;
    procedure Assign(ASource: TPersistent); override;
  published
    property CenterContentHorz: Boolean read FCenterContentHorz write SetCenterContentHorz default False;
    property CenterContentVert: Boolean read FCenterContentVert write SetCenterContentVert default False;
    property GroupIndent: Integer read FGroupIndent write SetGroupIndent default dxTileControlDefaultGroupIndent;
    property IndentHorz: Integer read FIndentHorz write SetIndentHorz default dxTileControlDefaultIndentHorz;
    property IndentVert: Integer read FIndentVert write SetIndentVert default dxTileControlDefaultIndentVert;
    property ItemIndent: Integer read FItemIndent write SetItemIndent default dxTileControlDefaultItemIndent;
    property ItemSize: Integer read FItemSize write SetItemSize default dxTileControlDefaultItemSize;
    property GroupLayout: TdxTileControlGroupLayout read FGroupLayout write SetGroupLayout default glHorizontal;
    property GroupMaxRowCount: Integer read FGroupMaxRowCount write SetGroupMaxRowCount default dxTileControlDefaultRowCount;
  end;

  { TdxTileControlViewInfo }

  TdxTileControlViewInfo = class(TdxTileControlCustomViewInfo)
  private
    FCells: TdxTileControlCells;
    FClientBounds: TRect;
    FContentBottom: Integer;
    FContentHeight: Integer;
    FContentRight: Integer;
    FContentWidth: Integer;
    FFixedGroupsOrigin: Boolean;
    FItemHalfIndent: Integer;
    FItemLargeWidth: Integer;
    FRealContentWidth: Integer;
    FTilesArea: TRect;
    FRowCount: Integer;
    FLeftScrollPos: Integer;
    FScrollButtonViewInfo: array[TcxArrowDirection] of TdxTileControlScrollButtonViewInfo;
    FTileControl: TdxCustomTileControl;
    FTopScrollPos: Integer;
    FVisibleGroupsOrigin: TPoint;
    procedure CalculateDerivedItemSizes;
    function GetGroupCount: Integer;
    function GetGroupLayout: TdxTileControlGroupLayout;
    function GetGroups: TdxTileControlGroupCollection;
    function GetItems: TdxTileControlItemCollection;
    function GetPainter: TdxTileControlPainter;
    function GetHorzScrollPage: Integer;
    function GetSubColumnSize: Integer;
    function GetTitle: TdxTileControlTitle;

    procedure CalculateClientBounds;
    procedure CalculateTilesArea;
    procedure CreateScrollButtonsViewInfo;
    procedure DestroyScrollButtonsViewInfo;
    procedure DoCenterContent;
    procedure DoCenterContentHorz;
    procedure DoCenterContentHorzAtHorizontalGroupLayout(const AShift, AAreaRight: Integer);
    procedure DoCenterContentHorzAtVerticalGroupLayout(const AShift: Integer);
    procedure DoCenterContentVert;
    procedure DoCenterContentVertAtHorizontalGroupLayout(const AShift: Integer);
    procedure DoCenterContentVertAtVerticalGroupLayout(const AShift, AAreaBottom: Integer);
    function GetContentBounds: TRect;
    function GetGroupsCaptionsMaxHeight: Integer;
    function GetTitleHeight: Integer;
    function GetVertScrollPage: Integer;
    function GetVisibleGroupsBounds: TRect;
    function IsFixedContentLeftSide: Boolean;
    function IsFixedContentTopSide: Boolean;
    function IsScrollBarsParametersWasChanged: Boolean;
    procedure MakeVisibleOnHorz(const ABounds: TRect; AIsLeftMost, AIsRightMost: Boolean);
    procedure MakeVisibleOnVert(const ABounds: TRect; AIsLeftMost, AIsRightMost: Boolean);
    procedure MeasureGroupsCaptionsHeights;
    procedure SetLeftScrollPos(AValue: Integer);
    procedure SetTopScrollPos(AValue: Integer);
  protected
    DragDropChanges: TdxTileControlDragAndDropChanges;
    FVirtualGroups: TcxObjectList;
    procedure AddGroup(AGroup: TdxTileControlGroup);
    procedure AddGroups; virtual;
    procedure AddItem(AItem: TdxTileControlItem);
    procedure AddItems; virtual;
    procedure AddScrollButtons;
    procedure AddVirtualGroupAfter(AGroup: TdxTileControlGroup);
    procedure AddVirtualGroupBefore(AGroup: TdxTileControlGroup);
    procedure CalculateRowCount;
    procedure CalculateTitle;
    procedure ClearGroupsOrigin;
    procedure DoCalculate; virtual;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    procedure HideScrollButtons;
    function IsContentCentredHorz: Boolean;
    function IsContentCentredVert: Boolean;
    function IsContentNotCentredHorz: Boolean;
    function IsContentNotCentredVert: Boolean;
    function IsScrollAvailable: Boolean; overload;
    function IsScrollAvailable(ADirection: TcxArrowDirection): Boolean; overload;
    procedure MakeVisible(const ABounds: TRect; AIsLeftMost, AIsRightMost: Boolean);
    procedure Scroll(const DX, DY: Integer); virtual;
    procedure StoreGroupsOrigin;
  public
    constructor Create(AOwner: TdxCustomTileControl); virtual;
    destructor Destroy; override;
    procedure Calculate;
    procedure Clear;
    procedure Draw(ACanvas: TcxCanvas); override;
    function GetItemWidth(AIsLarge: Boolean = False): Integer;
    procedure RefreshState; override;

    property Cells: TdxTileControlCells read FCells write FCells;
    property ClientBounds: TRect read FClientBounds;
    property ContentHeight: Integer read FContentHeight write FContentHeight;
    property ContentWidth: Integer read FContentWidth write FContentWidth;
    property Groups: TdxTileControlGroupCollection read GetGroups;
    property GroupLayout: TdxTileControlGroupLayout read GetGroupLayout;
    property GroupsCount: Integer read GetGroupCount;
    property ItemHalfIndent: Integer read FItemHalfIndent;
    property ItemLargeWidth: Integer read FItemLargeWidth;
    property Items: TdxTileControlItemCollection read GetItems;
    property Painter: TdxTileControlPainter read GetPainter;
    property RowCount: Integer read FRowCount;
    property HorzScrollPage: Integer read GetHorzScrollPage;
    property LeftScrollPos: Integer read FLeftScrollPos write SetLeftScrollPos;
    property SubColumnSize: Integer read GetSubColumnSize;
    property TileControl: TdxCustomTileControl read FTileControl;
    property TilesArea: TRect read FTilesArea;
    property Title: TdxTileControlTitle read GetTitle;
    property TitleHeight: Integer read GetTitleHeight;
    property TopScrollPos: Integer read FTopScrollPos write SetTopScrollPos;
    property VertScrollPage: Integer read GetVertScrollPage;
    property VirtualGroups: TcxObjectList read FVirtualGroups;
    property VisibleGroupsOrigin: TPoint read FVisibleGroupsOrigin;
  end;

  { TdxTileControlAssets }

  TdxTileControlAssets = class(TObject)
  private
    FBackButton: TdxSkinImage;
    FCustomButton: TdxSkinImage;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    //
    property BackButton: TdxSkinImage read FBackButton;
    property CustomButton: TdxSkinImage read FCustomButton;
  end;

  { TdxTileControlPainter }

  TdxTileControlPainter = class(TcxIUnknownObject)
  private
    FSkinInfo: TdxSkinInfo;
    FTileControl: TdxCustomTileControl;
    function GetLookAndFeelPainter: TcxCustomLookAndFeelPainter;
    function GetUserSkins: Boolean;
  protected
    procedure DrawDefaultItemBackground(ACanvas: TcxCanvas; const R: TRect); virtual;
    procedure DrawDefaultItemCheck(ACanvas: TcxCanvas; const R: TRect); overload; virtual;
    procedure DrawDefaultItemCheck(ACanvas: TcxCanvas; const R: TRect;
      ABackgroundColor, ACheckMarkColor: TColor; AAlpha: Byte = MaxByte); overload; virtual;
    procedure DrawItemCheck(ACanvas: TcxCanvas; const R: TRect); virtual;
    procedure DrawStyleRect(ACanvas: TcxCanvas; const R: TRect; AStyle: TdxTileControlCustomStyle;
      const ATextureOffsetX, ATextureOffsetY: Integer; ABorders: TcxBorders);
    function GetActionBarDefaultBackgroundColor: TColor; virtual;
    function GetActionBarDefaultTextColor: TColor; virtual;
    function GetCheckedItemCheckMarkColor: TColor; virtual;
    function GetCheckedItemFrameColor: TColor; virtual;
    function GetDefaultItemTextBackgroundColor: TColor; virtual;
    function GetDefaultItemTextColor: TColor; virtual;
    function GetGroupCaptionDefaultFontSize: Integer; virtual;
    function GetGroupCaptionDefaultTextColor: TColor; virtual;
    function GetPageTabContentOffset: TRect; virtual;
    function GetPageTabDefaultFontSize: Integer; virtual;
    function GetPageTabTextColor(AState: TcxButtonState): TColor; virtual;
    function GetSelectionFocusedColor: TColor; virtual;
    function GetSelectionHottrackedColor: TColor; virtual;
    function GetSelectionSelectedColor: TColor; virtual;
    function GetTitleDefaultFontSize: Integer; virtual;
    function GetTitleDefaultTextColor: TColor; virtual;
  public
    constructor Create(ATileControl: TdxCustomTileControl); virtual;
    procedure DrawBackground(ACanvas: TcxCanvas; const R: TRect); virtual;
    procedure DrawColoredGlyph(ACanvas: TcxCanvas; const R: TRect;
      AState: TcxButtonState; AGlyph: TdxSkinImage; AColor: TColor); virtual;
    procedure DrawItemBackground(ACanvas: TcxCanvas; const R: TRect; AStyle: TdxTileControlCustomStyle); virtual;
    procedure DrawItemPlace(ACanvas: TcxCanvas; const R: TRect); virtual;
    procedure DrawPageTab(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); virtual;
    procedure DrawVirtualGroup(ACanvas: TcxCanvas; const R: TRect); virtual;
    procedure ValidatePainterData; virtual;
    //
    property ActionBarDefaultBackgroundColor: TColor read GetActionBarDefaultBackgroundColor;
    property ActionBarDefaultTextColor: TColor read GetActionBarDefaultTextColor;
    property CheckedItemCheckMarkColor: TColor read GetCheckedItemCheckMarkColor;
    property CheckedItemFrameColor: TColor read GetCheckedItemFrameColor;
    property DefaultItemTextBackgroundColor: TColor read GetDefaultItemTextBackgroundColor;
    property DefaultItemTextColor: TColor read GetDefaultItemTextColor;
    property GroupCaptionDefaultFontSize: Integer read GetGroupCaptionDefaultFontSize;
    property GroupCaptionDefaultTextColor: TColor read GetGroupCaptionDefaultTextColor;
    property LookAndFeelPainter: TcxCustomLookAndFeelPainter read GetLookAndFeelPainter;
    property PageTabContentOffset: TRect read GetPageTabContentOffset;
    property PageTabDefaultFontSize: Integer read GetPageTabDefaultFontSize;
    property PageTabTextColor[AState: TcxButtonState]: TColor read GetPageTabTextColor;
    property SelectionFocusedColor: TColor read GetSelectionFocusedColor;
    property SelectionHottrackedColor: TColor read GetSelectionHottrackedColor;
    property SelectionSelectedColor: TColor read GetSelectionSelectedColor;
    property SkinInfo: TdxSkinInfo read FSkinInfo;
    property TileControl: TdxCustomTileControl read FTileControl;
    property TitleDefaultFontSize: Integer read GetTitleDefaultFontSize;
    property TitleDefaultTextColor: TColor read GetTitleDefaultTextColor;
    property UseSkins: Boolean read GetUserSkins;
  end;

  { TdxTileControlTitle }

  TdxTileControlTitle = class(TcxOwnedPersistent)
  private
    FColor: TColor;
    FFont: TFont;
    FFontChanged: Boolean;
    FGlyph: TdxSmartImage;
    FGlyphAlignHorz: TAlignment;
    FGlyphAlignVert: TcxAlignmentVert;
    FIndentHorz: Integer;
    FIndentVert: Integer;
    FTabsActiveTextColor: TColor;
    FTabsFontSize: Integer;
    FTabsHotTextColor: TColor;
    FTabsTextColor: TColor;
    FText: string;
    FTextAlignHorz: TAlignment;
    FTextAlignVert: TcxAlignmentVert;
    FViewInfo: TdxTileControlTitleViewInfo;
    FWordWrap: Boolean;
    function GetTileControl: TdxCustomTileControl;
    function IsFontStored: Boolean;
    procedure SetColor(AValue: TColor);
    procedure SetFont(AValue: TFont);
    procedure SetGlyph(AValue: TdxSmartImage);
    procedure SetGlyphAlignHorz(AValue: TAlignment);
    procedure SetGlyphAlignVert(AValue: TcxAlignmentVert);
    procedure SetIndentHorz(AValue: Integer);
    procedure SetIndentVert(AValue: Integer);
    procedure SetTabsFontSize(AValue: Integer);
    procedure SetTabsActiveTextColor(AValue: TColor);
    procedure SetTabsHotTextColor(AValue: TColor);
    procedure SetTabsTextColor(AValue: TColor);
    procedure SetText(AValue: string);
    procedure SetTextAlignHorz(AValue: TAlignment);
    procedure SetTextAlignVert(AValue: TcxAlignmentVert);
    procedure SetWordWrap(AValue: Boolean);
  protected
    procedure Changed; virtual;
    function CreateViewInfo: TdxTileControlTitleViewInfo; virtual;
    procedure FontChanged(Sender: TObject);
    function IsChanged: Boolean; virtual;

    property GlyphAlignHorz: TAlignment read FGlyphAlignHorz write SetGlyphAlignHorz default taRightJustify;
    property GlyphAlignVert: TcxAlignmentVert read FGlyphAlignVert write SetGlyphAlignVert default vaBottom;
    property TextAlignHorz: TAlignment read FTextAlignHorz write SetTextAlignHorz default taLeftJustify;
    property TextAlignVert: TcxAlignmentVert read FTextAlignVert write SetTextAlignVert default vaBottom;
    property TileControl: TdxCustomTileControl read GetTileControl;
    property ViewInfo: TdxTileControlTitleViewInfo read FViewInfo;
    property WordWrap: Boolean read FWordWrap write SetWordWrap default False;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    procedure Assign(ASource: TPersistent); override;
  published
    property Color: TColor read FColor write SetColor default clDefault;
    property Font: TFont read FFont write SetFont stored IsFontStored;
    property Glyph: TdxSmartImage read FGlyph write SetGlyph;
    property IndentHorz: Integer read FIndentHorz write SetIndentHorz default dxTileItemObjectDefaultIndent;
    property IndentVert: Integer read FIndentVert write SetIndentVert default dxTileItemObjectDefaultIndent;
    property TabsActiveTextColor: TColor read FTabsActiveTextColor write SetTabsActiveTextColor default clDefault;
    property TabsFontSize: Integer read FTabsFontSize write SetTabsFontSize default dxTileControlDefaultTabFontSize;
    property TabsHotTextColor: TColor read FTabsHotTextColor write SetTabsHotTextColor default clDefault;
    property TabsTextColor: TColor read FTabsTextColor write SetTabsTextColor default clDefault;
    property Text: string read FText write SetText;
  end;

  { TdxTileControlPageTabCellViewInfo }

  TdxTileControlPageTabCellViewInfo = class(TdxTileControlCustomCellViewInfo)
  private
    FItem: TdxTileControlItem;
    FOwner: TdxTileControlDetailSiteTitleViewInfo;
    FState: TcxButtonState;
    function GetActive: Boolean;
    function GetCaption: string;
    function GetFont: TFont;
    function GetPainter: TdxTileControlPainter;
    procedure SetState(AValue: TcxButtonState);
  protected
    procedure DoDraw(ACanvas: TcxCanvas); override;
    function GetContentOffsets: TRect; virtual;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    procedure SetBounds(const ABounds, AVisibleBounds: TRect);
  public
    constructor Create(AOwner: TdxTileControlDetailSiteTitleViewInfo; AItem: TdxTileControlItem);
    function MeasureHeight: Integer; virtual;
    function MeasureWidth: Integer; virtual;
    procedure RefreshState; override;

    property Active: Boolean read GetActive;
    property Caption: string read GetCaption;
    property Font: TFont read GetFont;
    property Item: TdxTileControlItem read FItem;
    property Owner: TdxTileControlDetailSiteTitleViewInfo read FOwner;
    property Painter: TdxTileControlPainter read GetPainter;
    property State: TcxButtonState read FState write SetState;
  end;

  { TdxTileControlCustomButtonViewInfo }

  TdxTileControlCustomButtonViewInfo = class(TdxTileControlCustomCellViewInfo)
  private
    FState: TcxButtonState;
    procedure SetState(const Value: TcxButtonState);
  protected
    function GetTexture: TdxSkinImage; virtual; abstract;
  public
    procedure Invalidate; virtual; abstract;
    function MeasureHeight: Integer; virtual;
    function MeasureWidth: Integer; virtual;
    procedure SetBounds(const ABounds, AVisibleBounds: TRect);
    //
    property State: TcxButtonState read FState write SetState;
    property Texture: TdxSkinImage read GetTexture;
  end;

  { TdxTileControlDetailSiteBackButtonViewInfo }

  TdxTileControlDetailSiteBackButtonViewInfo = class(TdxTileControlCustomButtonViewInfo)
  private
    FOwner: TdxTileControlDetailSite;
  protected
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetTexture: TdxSkinImage; override;
  public
    constructor Create(AOwner: TdxTileControlDetailSite); virtual;
    procedure Draw(ACanvas: TcxCanvas); override;
    procedure Invalidate; override;
    procedure RefreshState; override;

    property Owner: TdxTileControlDetailSite read FOwner;
  end;

  { TdxTileControlScrollButtonViewInfo }

  TdxTileControlScrollButtonViewInfo = class(TdxTileControlCustomCellViewInfo,
    IcxMouseTrackingCaller, IcxMouseTrackingCaller2)
  private
    FDirection: TcxArrowDirection;
    FOwner: TdxCustomTileControl;
    FState: TcxButtonState;
    FTimer: TcxTimer;
    function GetController: TdxTileControlController;
    function GetViewInfo: TdxTileControlViewInfo;
    procedure SetState(const AValue: TcxButtonState);
    procedure TimerHandler(Sender: TObject);
  protected
    procedure DoCalculate; override;
    procedure DoDraw(ACanvas: TcxCanvas); override;
    procedure DoScrollContent; virtual;
    function GetArea: TRect; virtual;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetVisibleBounds: TRect; override;
    procedure Scroll(const DX, DY: Integer); override;
    // IcxMouseTrackingCaller
    procedure MouseLeave; virtual;
    // IcxMouseTrackingCaller2
    function PtInCaller(const P: TPoint): Boolean;

    property Timer: TcxTimer read FTimer;
  public
    constructor Create(AOwner: TdxCustomTileControl; ADirection: TcxArrowDirection); virtual;
    destructor Destroy; override;
    procedure Invalidate; virtual;
    procedure RefreshState; override;

    property Area: TRect read GetArea;
    property Controller: TdxTileControlController read GetController;
    property Direction: TcxArrowDirection read FDirection;
    property Owner: TdxCustomTileControl read FOwner;
    property State: TcxButtonState read FState write SetState;
    property ViewInfo: TdxTileControlViewInfo read GetViewInfo;
  end;

  { TdxTileControlDetailSiteTitleViewInfo }

  TdxTileControlDetailSiteTitleViewInfo = class(TdxTileControlTitleViewInfo)
  private
    FBackButtonViewInfo: TdxTileControlDetailSiteBackButtonViewInfo;
    FOwner: TdxTileControlDetailSite;
    FTabs: TdxTileControlCells;
    FTabsFont: TFont;
    function GetItem: TdxTileControlItem;
    function GetTileControl: TdxCustomTileControl;
  protected
    procedure CalculateBackButton; virtual;
    procedure CalculateTabs; virtual;
    function CreateBackButtonViewInfo: TdxTileControlDetailSiteBackButtonViewInfo; virtual;
    function CreateTabCellViewInfo(AItem: TdxTileControlItem): TdxTileControlPageTabCellViewInfo; virtual;
    procedure DoCalculate; override;
    procedure DoDraw(ACanvas: TcxCanvas); override;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetTextLeftOffset: Integer; override;
    function GetVisibleBounds: TRect; override;
  public
    constructor Create(AOwner: TdxTileControlDetailSite); virtual;
    destructor Destroy; override;
    procedure RefreshState; override;

    property BackButtonViewInfo: TdxTileControlDetailSiteBackButtonViewInfo read FBackButtonViewInfo;
    property Item: TdxTileControlItem read GetItem;
    property Owner: TdxTileControlDetailSite read FOwner;
    property Tabs: TdxTileControlCells read FTabs;
    property TabsFont: TFont read FTabsFont;
    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlDetailSite }

  TdxTileControlDetailSite = class(TcxControl, IcxMouseTrackingCaller, IcxMouseTrackingCaller2)
  private
    FPressedCell: TdxTileControlCustomCellViewInfo;
    FTitleViewInfo: TdxTileControlDetailSiteTitleViewInfo;
    function GetActiveControl: TWinControl;
    function GetHitTest: TdxTileControlHitTest;
    function GetIndex: Integer;
    function GetTileControl: TdxCustomTileControl;
    function GetTileItem: TdxTileControlItem;
    procedure SetPressedCell(AValue: TdxTileControlCustomCellViewInfo);
  protected
    procedure CreateParams(var Params: TCreateParams); override;
    procedure BoundsChanged; override;
    procedure DoPaint; override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    // IcxMouseTrackingCaller2
    function PtInCaller(const P: TPoint): Boolean;
    // IcxMouseTrackingCaller
    procedure IcxMouseTrackingCaller.MouseLeave = ReallyMouseLeave;
    procedure IcxMouseTrackingCaller2.MouseLeave = ReallyMouseLeave;
    procedure ReallyMouseLeave; virtual;

    function CreateTitleViewInfo: TdxTileControlDetailSiteTitleViewInfo; virtual;
    procedure DoActivateDetail; virtual;
    procedure DoDeactivateDetail; virtual;
    procedure InitializeSite(ALeft: Integer);
    //
    property PressedCell: TdxTileControlCustomCellViewInfo read FPressedCell write SetPressedCell;
    property TitleViewInfo: TdxTileControlDetailSiteTitleViewInfo read FTitleViewInfo;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;

    property ActiveControl: TWinControl read GetActiveControl;
    property HitTest: TdxTileControlHitTest read GetHitTest;
    property Index: Integer read GetIndex;
    property TileControl: TdxCustomTileControl read GetTileControl;
    property TileItem: TdxTileControlItem read GetTileItem;
  end;

  { TdxTileControlActionBarItem }

  TdxTileControlActionBarItemAlignment = (abiaLeft, abiaRight);
  TdxTileControlActionBarItemPosition = (abipTopBar, abipBottomBar);
  TdxTileControlActionBarItemEvent = procedure (Sender: TdxTileControlActionBarItem) of object;

  TdxTileControlActionBarItem = class(TcxComponentCollectionItem)
  private
    FAlign: TdxTileControlActionBarItemAlignment;
    FCaption: string;
    FImage: TdxSkinImage;
    FPosition: TdxTileControlActionBarItemPosition;
    FVisible: Boolean;
    FOnClick: TdxTileControlActionBarItemEvent;
    function GetGlyph: TdxSmartImage;
    function GetGlyphFrameCount: Integer;
    procedure GlyphChanged(Sender: TObject);
    procedure SetAlign(AValue: TdxTileControlActionBarItemAlignment);
    procedure SetCaption(const AValue: string);
    procedure SetGlyph(AValue: TdxSmartImage);
    procedure SetGlyphFrameCount(AValue: Integer);
    procedure SetPosition(AValue: TdxTileControlActionBarItemPosition);
    procedure SetVisible(AValue: Boolean);
  protected
    function GetCollectionFromParent(AParent: TComponent): TcxComponentCollection; override;
    //
    property Image: TdxSkinImage read FImage;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
    procedure Click;
  published
    property Align: TdxTileControlActionBarItemAlignment read FAlign write SetAlign default abiaLeft;
    property Caption: string read FCaption write SetCaption;
    property Glyph: TdxSmartImage read GetGlyph write SetGlyph;
    property GlyphFrameCount: Integer read GetGlyphFrameCount write SetGlyphFrameCount default 1;
    property Position: TdxTileControlActionBarItemPosition read FPosition write SetPosition default abipBottomBar;
    property Visible: Boolean read FVisible write SetVisible default True;
    //
    property OnClick: TdxTileControlActionBarItemEvent read FOnClick write FOnClick;
  end;

  { TdxTileControlActionBarItems }

  TdxTileControlActionBarItems = class(TcxComponentCollection)
  private
    function GetItem(AIndex: Integer): TdxTileControlActionBarItem;
    procedure SetItem(AIndex: Integer; AValue: TdxTileControlActionBarItem);
  protected
    function GetItemPrefixName: string; override;
  public
    function Add: TdxTileControlActionBarItem;
    //
    property Items[Index: Integer]: TdxTileControlActionBarItem read GetItem write SetItem; default;
  end;

  { TdxTileControlActionBarCustomItemViewInfo }

  TdxTileControlActionBarCustomItemViewInfo = class(TdxTileControlCustomButtonViewInfo)
  private
    FOwner: TdxTileControlCustomActionBarViewInfo;
    function GetController: TdxTileControlActionBarController;
    function GetPainter: TdxTileControlPainter;
  protected
    FGlyphBounds: TRect;
    function GetFont: TFont; virtual;
    function GetText: string; virtual;
    function GetTextBounds: TRect; virtual;
    function GetTextColor: TColor; virtual;
    procedure DoCalculate; override;
  public
    constructor Create(AOwner: TdxTileControlCustomActionBarViewInfo);
    function MeasureHeight: Integer; override;
    function MeasureWidth: Integer; override;
    procedure Draw(ACanvas: TcxCanvas); override;
    procedure Invalidate; override;
    procedure RefreshState; override;
    //
    property Controller: TdxTileControlActionBarController read GetController;
    property Font: TFont read GetFont;
    property Owner: TdxTileControlCustomActionBarViewInfo read FOwner;
    property Painter: TdxTileControlPainter read GetPainter;
    property Text: string read GetText;
    property TextBounds: TRect read GetTextBounds;
    property TextColor: TColor read GetTextColor;
  end;

  { TdxTileControlCustomActionBarViewInfo }

  TdxTileControlCustomActionBarViewInfo = class(TdxTileControlCustomViewInfo)
  private
    FCells: TdxTileControlCells;
    FOwner: TdxTileControlCustomActionBar;
    function GetActionBars: TdxTileControlActionBars;
    function GetItems: TdxTileControlActionBarItems;
    function GetPainter: TdxTileControlPainter;
  protected
    procedure CalculateItems(ABounds: TRect); virtual;
    function CreateItemViewInfo(AItem: TdxTileControlActionBarItem): TdxTileControlActionBarCustomItemViewInfo; virtual;
    function GetCanDisplayItem(AItem: TdxTileControlActionBarItem): Boolean; virtual;
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
  public
    constructor Create(AOwner: TdxTileControlCustomActionBar); virtual;
    destructor Destroy; override;
    procedure Calculate; virtual;
    procedure Clear; virtual;
    procedure Draw(ACanvas: TcxCanvas); override;
    procedure DrawBackground(ACanvas: TcxCanvas); virtual;
    function MeasureHeight: Integer; virtual;
    procedure RefreshState; override;
    //
    property ActionBars: TdxTileControlActionBars read GetActionBars;
    property Cells: TdxTileControlCells read FCells;
    property Items: TdxTileControlActionBarItems read GetItems;
    property Owner: TdxTileControlCustomActionBar read FOwner;
    property Painter: TdxTileControlPainter read GetPainter;
  end;

  { TdxTileControlActionBarItemViewInfo }

  TdxTileControlActionBarItemViewInfo = class(TdxTileControlActionBarCustomItemViewInfo)
  private
    FItem: TdxTileControlActionBarItem;
  protected
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetText: string; override;
    function GetTexture: TdxSkinImage; override;
  public
    constructor Create(AOwner: TdxTileControlCustomActionBarViewInfo; AItem: TdxTileControlActionBarItem);
    //
    property Item: TdxTileControlActionBarItem read FItem;
  end;

  { TdxTileControlActionBarHitTest }

  TdxTileControlActionBarHitTest = class(TdxTileControlHitTest)
  private
    FOwner: TdxTileControlCustomActionBar;
  protected
    function GetActiveViewInfo: TdxTileControlCustomViewInfo; override;
  public
    constructor Create(AOwner: TdxTileControlCustomActionBar);
    //
    property Owner: TdxTileControlCustomActionBar read FOwner;
  end;

  { TdxTileControlActionBarController }

  TdxTileControlActionBarController = class(TcxIUnknownObject, IcxMouseTrackingCaller, IcxMouseTrackingCaller2)
  private
    FHotCell: TObject;
    FOwner: TdxTileControlCustomActionBar;
    FPressedCell: TObject;
    function GetHitTest: TdxTileControlActionBarHitTest;
    function GetTileControl: TdxCustomTileControl;
    procedure SetHotCell(AValue: TObject);
    procedure SetPressedCell(AValue: TObject);
  protected
    procedure ProcessMouseLeftButtonClick; virtual;
    procedure UncheckAllItems;
  public
    constructor Create(AOwner: TdxTileControlCustomActionBar); virtual;
    destructor Destroy; override;
    procedure HideActionBars;
    procedure RefreshStates;
    // Mouse
    procedure MouseDown(AButton: TMouseButton; AShift: TShiftState; X, Y: Integer); virtual;
    procedure MouseLeave; virtual; // IcxMouseTrackingCaller
    procedure MouseMove(AShift: TShiftState; X, Y: Integer); virtual;
    procedure MouseUp(AButton: TMouseButton; AShift: TShiftState; X, Y: Integer); virtual;
    function PtInCaller(const P: TPoint): Boolean;  // IcxMouseTrackingCaller2
    //
    property HitTest: TdxTileControlActionBarHitTest read GetHitTest;
    property HotCell: TObject read FHotCell write SetHotCell;
    property Owner: TdxTileControlCustomActionBar read FOwner;
    property PressedCell: TObject read FPressedCell write SetPressedCell;
    property TileControl: TdxCustomTileControl read GetTileControl;
  end;

  { TdxTileControlCustomActionBar }

  TdxTileControlCustomActionBar = class(TcxControl)
  private
    FController: TdxTileControlActionBarController;
    FHitTest: TdxTileControlActionBarHitTest;
    FTileControl: TdxCustomTileControl;
    FViewInfo: TdxTileControlCustomActionBarViewInfo;
  protected
    procedure BoundsChanged; override;
    function CreateController: TdxTileControlActionBarController; virtual;
    function CreateHitTest: TdxTileControlActionBarHitTest; virtual;
    function CreateViewInfo: TdxTileControlCustomActionBarViewInfo; virtual; abstract;
    procedure DoPaint; override;
    procedure Recalculate;
    // Mouse
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
  public
    constructor Create(ATileControl: TdxCustomTileControl); reintroduce; virtual;
    destructor Destroy; override;
    //
    property Controller: TdxTileControlActionBarController read FController;
    property HitTest: TdxTileControlActionBarHitTest read FHitTest;
    property TileControl: TdxCustomTileControl read FTileControl;
    property ViewInfo: TdxTileControlCustomActionBarViewInfo read FViewInfo;
  end;

  { TdxTileControlBottomActionBar }

  TdxTileControlBottomActionBar = class(TdxTileControlCustomActionBar)
  protected
    function CreateViewInfo: TdxTileControlCustomActionBarViewInfo; override;
  end;

  { TdxTileControlBottomActionBarViewInfo }

  TdxTileControlBottomActionBarViewInfo = class(TdxTileControlCustomActionBarViewInfo)
  protected
    function GetCanDisplayItem(AItem: TdxTileControlActionBarItem): Boolean; override;
  end;

  { TdxTileControlTopActionBar }

  TdxTileControlTopActionBar = class(TdxTileControlCustomActionBar)
  protected
    function CreateViewInfo: TdxTileControlCustomActionBarViewInfo; override;
  end;

  { TdxTileControlTopActionBarViewInfo }

  TdxTileControlTopActionBarViewInfo = class(TdxTileControlCustomActionBarViewInfo)
  protected
    function CreateBackButtonViewInfo: TdxTileControlActionBarCustomItemViewInfo; virtual;
    function GetCanDisplayItem(AItem: TdxTileControlActionBarItem): Boolean; override;
    procedure CalculateItems(ABounds: TRect); override;
  end;

  { TdxTileControlTopActionBarBackButtonViewInfo }

  TdxTileControlTopActionBarBackButtonViewInfo = class(TdxTileControlActionBarCustomItemViewInfo)
  protected
    function GetHitTest(AHitTest: TdxTileControlHitTest): Boolean; override;
    function GetTexture: TdxSkinImage; override;
  end;

  { TdxTileControlActionBars }

  TdxTileControlActionBars = class(TcxOwnedPersistent)
  private
    FColor: TColor;
    FFont: TFont;
    FFontChanged: Boolean;
    FIndentHorz: Integer;
    FIndentVert: Integer;
    FItemIndent: Integer;
    FItems: TdxTileControlActionBarItems;
    function GetTileControl: TdxCustomTileControl;
    function IsFontStored: Boolean;
    procedure FontChanged(Sender: TObject);
    procedure SetColor(AValue: TColor);
    procedure SetFont(AValue: TFont);
    procedure SetIndentHorz(AValue: Integer);
    procedure SetIndentVert(AValue: Integer);
    procedure SetItemIndent(AValue: Integer);
    procedure SetItems(AValue: TdxTileControlActionBarItems);
  protected
    function CreateItems: TdxTileControlActionBarItems; virtual;
    procedure Changed; virtual;
    procedure ItemsChangeHandler(Sender: TObject; AItem: TcxComponentCollectionItem;
      AAction: TcxComponentCollectionNotification); virtual;
    //
    property TileControl: TdxCustomTileControl read GetTileControl;
  public
    constructor Create(AOwner: TPersistent); override;
    destructor Destroy; override;
    procedure Assign(Source: TPersistent); override;
  published
    property Color: TColor read FColor write SetColor default clDefault;
    property Font: TFont read FFont write SetFont stored IsFontStored;
    property IndentHorz: Integer read FIndentHorz write SetIndentHorz default dxTileControlDefaultActionBarsIndentHorz;
    property IndentVert: Integer read FIndentVert write SetIndentVert default dxTileControlDefaultActionBarsIndentVert;
    property ItemIndent: Integer read FItemIndent write SetItemIndent default dxTileControlDefaultActionBarsItemIndent;
    property Items: TdxTileControlActionBarItems read FItems write SetItems;
  end;

  { TdxCustomTileControl }

  TdxTileControlChange = (tccLayout, tccSelection, tccItems);
  TdxTileControlChanges = set of TdxTileControlChange;
  TdxTileControlItemBeforeCheckEvent = procedure(Sender: TdxCustomTileControl; AItem: TdxTileControlItem; var AAllow: Boolean) of object;
  TdxTileControlItemCheckEvent = procedure(Sender: TdxCustomTileControl; AItem: TdxTileControlItem) of object;

  TdxTileControlItemDragBeginEvent = procedure(Sender: TdxCustomTileControl; AInfo: TdxTileControlDragItemInfo; var AAllow: Boolean) of object;
  TdxTileControlItemDragEndEvent = procedure(Sender: TdxCustomTileControl; AInfo: TdxTileControlDragItemInfo) of object;
  TdxTileControlItemDragOverEvent = procedure(Sender: TdxCustomTileControl; AInfo: TdxTileControlDragItemInfo; var AAccept: Boolean) of object;

  TdxCustomTileControl = class(TcxControl, IcxStoredParent, IcxStoredObject, IdxSkinSupport)
  private
    FActionBarBottom: TdxTileControlCustomActionBar;
    FActionBars: TdxTileControlActionBars;
    FActionBarTop: TdxTileControlCustomActionBar;
    FActiveDetail: TdxTileControlDetailSite;
    FAnimation: TdxImageAnimationTransition;
    FAssets: TdxTileControlAssets;
    FChanges: TdxTileControlChanges;
    FController: TdxTileControlController;
    FDetailsAnimationInProcess: Boolean;
    FDragDropInProcess: Boolean;
    FDragItemInfo: TdxTileControlDragItemInfo;
    FForceCalculate: Boolean;
    FGroups: TdxTileControlGroupCollection;
    FHitTest: TdxTileControlHitTest;
    FIsRestoring: Boolean;
    FItems: TdxTileControlItemCollection;
    FLockCount: Integer;
    FOptionsBehavior: TdxTileControlOptionsBehavior;
    FOptionsItemAnimate: TdxTileControlCustomItemOptionsAnimate;
    FOptionsView: TdxTileControlOptionsView;
    FPainter: TdxTileControlPainter;
    FRightButtonPressed: Boolean;
    FStoredVersion: Integer;
    FStoringName: string;
    FStyle: TdxTileControlStyle;
    FTitle: TdxTileControlTitle;
    FViewInfo: TdxTileControlViewInfo;

    FOnItemBeforeCheck: TdxTileControlItemBeforeCheckEvent;
    FOnItemCheck: TdxTileControlItemCheckEvent;
    FOnItemDragBegin: TdxTileControlItemDragBeginEvent;
    FOnItemDragEnd: TdxTileControlItemDragEndEvent;
    FOnItemDragOver: TdxTileControlItemDragOverEvent;
    // IcxStoredObject events
    FOnGetStoredProperties: TcxGetStoredPropertiesEvent;
    FOnGetStoredPropertyValue: TcxGetStoredPropertyValueEvent;
    FOnInitStoredObject: TcxInitStoredObjectEvent;
    FOnSetStoredPropertyValue: TcxSetStoredPropertyValueEvent;

    procedure AfterActiveDetailChangingAnimation(AActiveDetail, ANewDetail: TdxTileControlDetailSite);
    procedure AnimationHandler(Sender: TdxAnimationTransition; var APosition: Integer; var AFinished: Boolean);
    procedure BeforeActiveDetailChangingAnimation(AActiveDetail, ANewDetail: TdxTileControlDetailSite);
    function GetActiveHitTest: TdxTileControlHitTest;
    function GetCheckedItem(Index: Integer): TdxTileControlItem;
    function GetCheckedItemCount: Integer;
    function GetDraggedGroup: TdxTileControlGroup;
    function GetDraggedItem: TdxTileControlItem;
    function GetIsLocked: Boolean;
    procedure InitializeDragItemInfo;
    function IsGroupDragged: Boolean;
    function IsItemDragged: Boolean;
    function IsStyleStored: Boolean;
    function IsTitleStored: Boolean;
    procedure RefreshItem(AItem: TdxTileControlItem; const AData: Pointer);
    procedure SetActionBars(AValue: TdxTileControlActionBars);
    procedure SetActiveDetail(AValue: TdxTileControlDetailSite);
    procedure SetOptionsBehavior(AValue: TdxTileControlOptionsBehavior);
    procedure SetOptionsItemAnimate(AValue: TdxTileControlCustomItemOptionsAnimate);
    procedure SetOptionsView(AValue: TdxTileControlOptionsView);
    procedure SetStyle(AValue: TdxTileControlStyle);
    procedure SetTitle(AValue: TdxTileControlTitle);
    // scroll
    procedure ScrollHorz(AScrollBarKind: TScrollBarKind; AScrollCode: TScrollCode;
      var AScrollPos: Integer);
    procedure ScrollVert(AScrollBarKind: TScrollBarKind; AScrollCode: TScrollCode;
      var AScrollPos: Integer);
    // IcxStoredObject
    function GetObjectName: string;
    function GetProperties(AProperties: TStrings): Boolean;
    procedure GetPropertyValue(const AName: string; var AValue: Variant);
    procedure SetPropertyValue(const AName: string; const AValue: Variant);
    // IcxStoredParent
    function IcxStoredParent.CreateChild = StoredCreateChild;
    procedure IcxStoredParent.DeleteChild = StoredDeleteChild;
    procedure IcxStoredParent.GetChildren = GetStoredChildren;
    // Messages
    procedure WMContextMenu(var Message: TWMContextMenu); message WM_CONTEXTMENU;
  protected
    FCheckedItems: TdxTileControlCheckedItems;
    procedure AddChanges(AChanges: TdxTileControlChanges);
    procedure BoundsChanged; override;
    procedure BringInternalControlsToFront; override;
    function CanAutoSize(var NewWidth, NewHeight: Integer): Boolean; override;
    procedure CheckChanges;
    function CreateActionBarBottom: TdxTileControlCustomActionBar; virtual;
    function CreateActionBars: TdxTileControlActionBars; virtual;
    function CreateActionBarTop: TdxTileControlCustomActionBar; virtual;
    function CreateAssets: TdxTileControlAssets; virtual;
    function CreateController: TdxTileControlController; virtual;
    function CreateGroupsCollection: TdxTileControlGroupCollection; virtual;
    function CreateHitTest: TdxTileControlHitTest; virtual;
    function CreateItemsCollection: TdxTileControlItemCollection; virtual;
    function CreatePainter: TdxTileControlPainter; virtual;
    function CreateStyle: TdxTileControlStyle; virtual;
    procedure CreateSubClasses; virtual;
    function CreateTitle: TdxTileControlTitle; virtual;
    function CreateViewInfo: TdxTileControlViewInfo; virtual;
    procedure CreateWnd; override;
    procedure DestroySubClasses; virtual;
    procedure DblClick; override;
    procedure DoActivateDetail(ADetail: TdxTileControlDetailSite); virtual;
    procedure DoCancelMode; override;
    procedure DoDeactivateDetail(ADetail: TdxTileControlDetailSite); virtual;
    procedure DoInitStoredObject(AObject: TObject); virtual;
    function DoItemBeforeCheck(AItem: TdxTileControlItem): Boolean; dynamic;
    procedure DoItemCheck(AItem: TdxTileControlItem); dynamic;
    procedure DoItemDragBegin(var AAllow: Boolean); dynamic;
    procedure DoItemDragEnd; dynamic;
    procedure DoItemDragOver(var AAccept: Boolean); dynamic;
    procedure DoPaint; override;
    procedure DrawScrollBars(ACanvas: TcxCanvas); override;
    function FindGroup(const AName: string): TdxTileControlGroup;
    procedure FocusChanged; override;
    procedure ForceUpdate(AUpdateAll: Boolean = False);
    function GetActionBarBottomBounds: TRect; virtual;
    function GetActionBarTopBounds: TRect; virtual;
    function GetDesignHitTest(X, Y: Integer; Shift: TShiftState): Boolean; override;
    function GetDragAndDropObjectClass: TcxDragAndDropObjectClass; override;
    function GetMainScrollBarsClass: TcxControlCustomScrollBarsClass; override;
    function GetMouseWheelScrollingKind: TcxMouseWheelScrollingKind; override;
    function GetVScrollBarBounds: TRect; override;
    function IsActionBarTopVisible: Boolean; virtual;
    function IsActionBarBottomVisible: Boolean; virtual;
    function IsDestroying: Boolean;
    function IsDoubleBufferedNeeded: Boolean; override;
    function IsLoading: Boolean;
    procedure InitScrollBarsParameters; override;
    function InsertGroup(AIndex: Integer): TdxTileControlGroup;
    procedure KeyDown(var Key: Word; Shift: TShiftState); override;
    procedure Loaded; override;
    procedure LockTimers;
    procedure LookAndFeelChanged(Sender: TcxLookAndFeel; AChangedValues: TcxLookAndFeelValues); override;
    procedure MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure MouseLeave(AControl: TControl); override;
    procedure MouseMove(Shift: TShiftState; X, Y: Integer); override;
    procedure MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer); override;
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure ReCreateViewInfo;
    procedure RefreshActionBars;
    procedure RefreshItems;
    procedure RemoveGroupIfEmpty(AGroup: TdxTileControlGroup);
    procedure Scroll(AScrollBarKind: TScrollBarKind; AScrollCode: TScrollCode;
      var AScrollPos: Integer); override;
    procedure SetAutoSize(Value: Boolean); override;
    function StartDragAndDrop(const P: TPoint): Boolean; override;
    procedure StyleChanged(Sender: TObject);
    procedure UnlockTimers;
    procedure ValidateChanges;
    // used classes
    function GetGroupsClass: TdxTileControlGroupCollectionClass;
    function GetItemsClass: TdxTileControlItemCollectionClass;
    // store-restore layout
    procedure RestoreFrom(AStorageType: TcxStorageType;
      const AStorageName: string; AStorageStream: TStream;
      ACreateChildren, ADeleteChildren: Boolean; const ARestoreName: string);
    procedure StoreTo(AStorageType: TcxStorageType; const AStorageName: string;
      AStorageStream: TStream; AReCreate: Boolean; const ASaveName: string);
    // cxStorage implementation
    procedure GetStoredChildren(AChildren: TStringList); virtual;
    function GetStoredObjectName: string; virtual;
    function GetStoredObjectProperties(AProperties: TStrings): Boolean; virtual;
    procedure GetStoredPropertyValue(const AName: string; var AValue: Variant); virtual;
    procedure SetStoredPropertyValue(const AName: string; const AValue: Variant); virtual;
    function StoredCreateChild(const AObjectName, AClassName: string): TObject; virtual;
    procedure StoredDeleteChild(const AObjectName: string; AObject: TObject); virtual;

    property ActionBarBottom: TdxTileControlCustomActionBar read FActionBarBottom;
    property ActionBarTop: TdxTileControlCustomActionBar read FActionBarTop;
    property Animation: TdxImageAnimationTransition read FAnimation;
    property Assets: TdxTileControlAssets read FAssets;
    property Changes: TdxTileControlChanges read FChanges write FChanges;
    property DetailsAnimationInProcess: Boolean read FDetailsAnimationInProcess;
    property DragDropInProcess: Boolean read FDragDropInProcess write FDragDropInProcess;
    property DraggedGroup: TdxTileControlGroup read GetDraggedGroup;
    property DraggedItem: TdxTileControlItem read GetDraggedItem;
    property ForceCalculate: Boolean read FForceCalculate;
    property HitTest: TdxTileControlHitTest read FHitTest;
    property IsLocked: Boolean read GetIsLocked;
    property IsRestoring: Boolean read FIsRestoring write FIsRestoring;
    property LockCount: Integer read FLockCount write FLockCount;
    property Painter: TdxTileControlPainter read FPainter;
    property StoringName: string read FStoringName write FStoringName;
    property ViewInfo: TdxTileControlViewInfo read FViewInfo;
    // IcxStoredObject events
    property OnGetStoredProperties: TcxGetStoredPropertiesEvent read FOnGetStoredProperties write FOnGetStoredProperties;
    property OnGetStoredPropertyValue: TcxGetStoredPropertyValueEvent read FOnGetStoredPropertyValue write FOnGetStoredPropertyValue;
    property OnInitStoredObject: TcxInitStoredObjectEvent read FOnInitStoredObject write FOnInitStoredObject;
    property OnSetStoredPropertyValue: TcxSetStoredPropertyValueEvent read FOnSetStoredPropertyValue write FOnSetStoredPropertyValue;

    property OnItemBeforeCheck: TdxTileControlItemBeforeCheckEvent read FOnItemBeforeCheck write FOnItemBeforeCheck;
    property OnItemCheck: TdxTileControlItemCheckEvent read FOnItemCheck write FOnItemCheck;
    property OnItemDragBegin: TdxTileControlItemDragBeginEvent read FOnItemDragBegin write FOnItemDragBegin;
    property OnItemDragEnd: TdxTileControlItemDragEndEvent read FOnItemDragEnd write FOnItemDragEnd;
    property OnItemDragOver: TdxTileControlItemDragOverEvent read FOnItemDragOver write FOnItemDragOver;

    property StoredVersion: Integer read FStoredVersion;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    procedure BeginUpdate;
    procedure CancelUpdate;
    function CreateGroup: TdxTileControlGroup;
    function CreateItem(AIsLarge: Boolean = False; AGroup: TdxTileControlGroup = nil): TdxTileControlItem;
    procedure DeleteItem(AItem: TdxTileControlItem);
    procedure EndUpdate;
    procedure GetChildren(Proc: TGetChildProc; Root: TComponent); override;
    function IsMouseInPressedArea(X, Y: Integer): Boolean; override;
    procedure LayoutChanged; virtual;
    procedure RemoveGroup(AGroup: TdxTileControlGroup);
    // ActionBars
    function IsAnyActionBarVisible: Boolean; virtual;
    procedure HideActionBars; virtual;
    procedure ShowActionBars; virtual;
    // storing layout
    procedure RestoreFromIniFile(const AStorageName: string; AChildrenCreating: Boolean = False;
      AChildrenDeleting: Boolean = False; const ARestoreName: string = '');
    procedure RestoreFromRegistry(const AStorageName: string; AChildrenCreating: Boolean = False;
      AChildrenDeleting: Boolean = False; const ARestoreName: string = '');
    procedure RestoreFromStream(AStream: TStream; AChildrenCreating: Boolean = False;
      AChildrenDeleting: Boolean = False; const ARestoreName: string = '');
    procedure StoreToIniFile(AStorageName: string; AReCreate: Boolean = True;
      const ASaveName: string = '');
    procedure StoreToRegistry(AStorageName: string; AReCreate: Boolean = True;
      const ASaveName: string = '');
    procedure StoreToStream(AStream: TStream; const ASaveName: string = '');

    property ActionBars: TdxTileControlActionBars read FActionBars write SetActionBars;
    property ActiveDetail: TdxTileControlDetailSite read FActiveDetail write SetActiveDetail;
    property ActiveHitTest: TdxTileControlHitTest read GetActiveHitTest;
    property CheckedItems[Index: Integer]: TdxTileControlItem read GetCheckedItem;
    property CheckedItemCount: Integer read GetCheckedItemCount;
    property Controller: TdxTileControlController read FController;
    property Groups: TdxTileControlGroupCollection read FGroups;
    property Items: TdxTileControlItemCollection read FItems;
    property OptionsBehavior: TdxTileControlOptionsBehavior read FOptionsBehavior write SetOptionsBehavior;
    property OptionsItemAnimate: TdxTileControlCustomItemOptionsAnimate read FOptionsItemAnimate write SetOptionsItemAnimate;
    property OptionsView: TdxTileControlOptionsView read FOptionsView write SetOptionsView;
    property Style: TdxTileControlStyle read FStyle write SetStyle stored IsStyleStored;
    property Title: TdxTileControlTitle read FTitle write SetTitle stored IsTitleStored;
  end;

var
  dxDesignHelperClass: TdxTileControlCustomDesignHelperClass = nil;

implementation

uses
  dxOffice11, RTLConsts;

{$R dxTileControl.res}

const
  dxTileControlActionBarsAnimationMaxStepCount = 100;
  dxTileControlPullDownThreshold = 35;

const
  DefaultFontName: string = 'Segoe UI';

  SubColumnSizes: array [Boolean] of Integer = (1, 2);

  DefaultTextAlignment: array [0 .. 3] of TdxTileItemInnerObjectAlignment =
    (oaTopLeft, oaTopRight, oaBottomLeft, oaBottomRight);

  dxTileControlStoredItemPropertiesNames: array [0 .. 4] of string =
    ('Visible', 'IsLarge', 'GroupIndex', 'IndexInGroup', 'RowCount');

  dxTileControlStoredGroupPropertiesNames: array [0 .. 1] of string = ('Visible', 'Index');

type
  TdxSmartImageAccess = class(TdxSmartImage);

  { TdxDetailControlInfo }

  TdxDetailControlInfo = class
  public
    Align: TAlign;
    Bounds: TRect;
    Control: TWinControl;
    Parent: TWinControl;
    RefCount: Integer;
  end;

  { TdxDetailControlsInfo }

  TdxDetailControlsInfo = class(TcxObjectList)
  private
    function GetItem(AIndex: Integer): TdxDetailControlInfo;
  public
    procedure AddInfo(AControl: TWinControl; ATileItem: TdxTileControlItem);
    function FindByControl(AControl: TWinControl): TdxDetailControlInfo;
    procedure RemoveInfo(AControl: TWinControl; ATileItem: TdxTileControlItem);

    property Items[AIndex: Integer]: TdxDetailControlInfo read GetItem;
  end;

  { TdxTileControlActionsBarHelper }

  TdxTileControlActionsBarHelper = class(TObject)
  private
    FTileControls: TList;
  public
    constructor Create; virtual;
    destructor Destroy; override;
    procedure ProcessClickOnControl(AControl: TWinControl);
    class procedure Register(ATileControl: TdxCustomTileControl);
    class procedure Unregister(ATileControl: TdxCustomTileControl);
    //
    property TileControls: TList read FTileControls;
  end;

var
  DetailsInfo: TdxDetailControlsInfo;
  FActionsBarHelper: TdxTileControlActionsBarHelper = nil;

function GetDetailsInfo: TdxDetailControlsInfo;
begin
  if DetailsInfo = nil then
    DetailsInfo := TdxDetailControlsInfo.Create();
  Result := DetailsInfo;
end;

function IsTouchEvent: Boolean;
const
  MouseOriginMask  = $FFFFFF80;
  MouseOriginTouch = $FF515780;
begin
  Result := GetMessageExtraInfo and MouseOriginMask = MouseOriginTouch;
end;

procedure dxTileControlMouseHook(ACode: Integer; wParam: WPARAM; lParam: LPARAM; var AHookResult: LRESULT);
begin
  case wParam of
    WM_LBUTTONDOWN, WM_RBUTTONDOWN, WM_MBUTTONDOWN:
      if FActionsBarHelper <> nil then
        FActionsBarHelper.ProcessClickOnControl(FindControl(PMouseHookStruct(lParam).hwnd));
  end;
end;

{ TdxTileControlActionsBarHelper }

constructor TdxTileControlActionsBarHelper.Create;
begin
  inherited Create;
  FTileControls := TList.Create;
  dxSetHook(htMouse, dxTileControlMouseHook);
end;

destructor TdxTileControlActionsBarHelper.Destroy;
begin
  FreeAndNil(FTileControls);
  dxReleaseHook(dxTileControlMouseHook);
  inherited Destroy;
end;

procedure TdxTileControlActionsBarHelper.ProcessClickOnControl(AControl: TWinControl);

  function GetCurrentTileControl: TdxCustomTileControl;
  begin
    Result := nil;
    if AControl is TdxTileControlDetailSite then
      Result := TdxTileControlDetailSite(AControl).TileControl;
    if AControl is TdxCustomTileControl then
      Result := TdxCustomTileControl(AControl);
  end;

  procedure HideActionBarsForAnotherTileControls(ACurrentTileControl: TdxCustomTileControl);
  var
    I: Integer;
  begin
    for I := FTileControls.Count - 1 downto 0 do
    begin
      if FTileControls[I] <> ACurrentTileControl then
        TdxCustomTileControl(FTileControls[I]).HideActionBars;
    end;
  end;

begin
  if not (AControl is TdxTileControlCustomActionBar) then
    HideActionBarsForAnotherTileControls(GetCurrentTileControl);
end;

class procedure TdxTileControlActionsBarHelper.Register(ATileControl: TdxCustomTileControl);
begin
  if FActionsBarHelper = nil then
    FActionsBarHelper := TdxTileControlActionsBarHelper.Create;
  FActionsBarHelper.TileControls.Add(ATileControl);
end;

class procedure TdxTileControlActionsBarHelper.Unregister(ATileControl: TdxCustomTileControl);
begin
  if FActionsBarHelper <> nil then
  begin
    FActionsBarHelper.TileControls.Remove(ATileControl);
    if FActionsBarHelper.TileControls.Count = 0 then
      FreeAndNil(FActionsBarHelper);
  end;
end;


{ TdxDetailControlsInfo }

procedure TdxDetailControlsInfo.AddInfo(
  AControl: TWinControl; ATileItem: TdxTileControlItem);
var
  AInfo: TdxDetailControlInfo;
begin
  AControl.FreeNotification(ATileItem);
  AInfo := FindByControl(AControl);
  try
    if AInfo = nil then
    begin
      AInfo := TdxDetailControlInfo.Create;
      Add(AInfo);
      AInfo.Control := AControl;
      AInfo.Align := AControl.Align;
      AInfo.Parent := AControl.Parent;
      AInfo.Bounds := AControl.BoundsRect;
    end;
  finally
    Inc(AInfo.RefCount);
  end;
end;

function TdxDetailControlsInfo.FindByControl(
  AControl: TWinControl): TdxDetailControlInfo;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Count - 1 do
  begin
    if Items[I].Control = AControl then
    begin
      Result := Items[I];
      Break;
    end;
  end;
end;

procedure TdxDetailControlsInfo.RemoveInfo(
  AControl: TWinControl; ATileItem: TdxTileControlItem);
var
  AInfo: TdxDetailControlInfo;
begin
  AControl.RemoveFreeNotification(ATileItem);
  AInfo := FindByControl(AControl);
  if AInfo = nil then Exit;
  Dec(AInfo.RefCount);
  if AInfo.RefCount = 0 then
  try
    Remove(AInfo);
    if not (csDestroying in AControl.ComponentState) then
    begin
      AControl.Parent := AInfo.Parent;
      AControl.Align := AInfo.Align;
      AControl.BoundsRect := AInfo.Bounds;
    end;
  finally
    AInfo.Free;
  end;
end;

function TdxDetailControlsInfo.GetItem(AIndex: Integer): TdxDetailControlInfo;
begin
  Result := TdxDetailControlInfo(inherited Items[AIndex]);
end;

{ TdxLayoutItemPosition }

procedure TdxLayoutItemPosition.Assign(ASource: TdxLayoutItemPosition);
begin
  Row := ASource.Row;
  Column := ASource.Column;
end;

function TdxLayoutItemPosition.IsEqual(APosition: TdxLayoutItemPosition): Boolean;
begin
  Result := (APosition <> nil) and (Row = APosition.Row) and (Column = APosition.Column);
end;

{ TdxTileControlCells }

function TdxTileControlCells.CalculateHitTest(AHitTest: TdxTileControlHitTest): Boolean;
var
  I: Integer;
begin
  Result := False;
  for I := 0 to Count - 1 do
    if (Items[I] is TdxTileControlTitleViewInfo) and Items[I].GetHitTest(AHitTest) then
    begin
      Result := True;
      Break;
    end;
  if not Result then
    for I := Count - 1 downto 0 do
      if Items[I].GetHitTest(AHitTest) then
      begin
        Result := True;
        Break;
      end;
end;

function TdxTileControlCells.GetItem(AIndex: Integer): TdxTileControlCustomCellViewInfo;
begin
  Result := TdxTileControlCustomCellViewInfo(List[AIndex]);
end;

procedure TdxTileControlCells.Draw(ACanvas: TcxCanvas);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].Draw(ACanvas);
end;

procedure TdxTileControlCells.RefreshState;
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].RefreshState;
end;

procedure TdxTileControlCells.DrawWithoutClipping(ACanvas: TcxCanvas);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].DoDraw(ACanvas);
end;

{ TdxTileControlCustomViewInfo }

procedure TdxTileControlCustomViewInfo.RefreshState;
begin
end;

function TdxTileControlCustomViewInfo.IsEqual(ACompare: TdxTileControlCustomViewInfo): Boolean;
begin
  Result := (Self <> nil) and (Self = ACompare);
end;

{ TdxTileControlCustomCellViewInfo }

procedure TdxTileControlCustomCellViewInfo.Calculate;
begin
  if not Calculated then
  begin
    DoCalculate;
    FCalculated := True;
  end;
end;

procedure TdxTileControlCustomCellViewInfo.CalculateClipping;
begin
  FVisibleBounds := GetVisibleBounds;
  FVisible := cxRectIntersect(FClipRect, FVisibleBounds, FBounds);
end;

procedure TdxTileControlCustomCellViewInfo.DoCalculate;
begin
  CalculateClipping;
  RefreshState;
end;

procedure TdxTileControlCustomCellViewInfo.DoDraw(ACanvas: TcxCanvas);
begin
end;

procedure TdxTileControlCustomCellViewInfo.Draw(ACanvas: TcxCanvas);
begin
  if Visible then
    DoDraw(ACanvas);
end;

function TdxTileControlCustomCellViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := Visible and PtInRect(Bounds, AHitTest.HitPoint);
  if Result then
    AHitTest.HitObject := Self;
end;

function TdxTileControlCustomCellViewInfo.GetVisibleBounds: TRect;
begin
  Result := FVisibleBounds;
end;

procedure TdxTileControlCustomCellViewInfo.Recalculate;
begin
  Calculated := False;
  Calculate;
end;

procedure TdxTileControlCustomCellViewInfo.Offset(const DX, DY: Integer);
begin
end;

procedure TdxTileControlCustomCellViewInfo.Scroll(const DX, DY: Integer);
begin
  FBounds := cxRectOffset(FBounds, DX, DY);
  CalculateClipping;
end;

procedure TdxTileControlCustomCellViewInfo.SetCalculate(AValue: Boolean);
begin
  if FCalculated <> AValue then
  begin
    if AValue then
      Calculate
    else
      FCalculated := AValue;
  end;
end;

{ TdxTileControlAnimatedDragAndDropCustomCellViewInfo }

procedure TdxTileControlAnimatedDragAndDropCustomCellViewInfo.DrawContent(
  ACanvas: TcxCanvas; const ADrawRect: TRect);
begin
end;

function TdxTileControlAnimatedDragAndDropCustomCellViewInfo.GetBaseDrawBounds: TRect;
begin
  Result := Bounds;
end;

function TdxTileControlAnimatedDragAndDropCustomCellViewInfo.GetDrawBounds(
  AAbsolutePosition: Boolean = False): TRect;
begin
  Result := GetBaseDrawBounds;
  if AAbsolutePosition then
    OffsetRect(Result, -TileControl.ViewInfo.LeftScrollPos, -TileControl.ViewInfo.TopScrollPos);
end;

function TdxTileControlAnimatedDragAndDropCustomCellViewInfo.GetIsAnimatedOnDragDrop: Boolean;
begin
  with TileControl.ViewInfo do
    Result := (DragDropChanges <> nil) and (DragDropChanges.IndexOf(Self) >= 0);
end;

function TdxTileControlAnimatedDragAndDropCustomCellViewInfo.GetTileControl: TdxCustomTileControl;
begin
  Result := nil;
end;

{ TdxTileControlItemViewInfo }

constructor TdxTileControlItemViewInfo.Create(AOwner: TdxTileControlItem);
begin
  inherited Create;
  FItem := AOwner;
  FPosition := TdxLayoutItemPosition.Create;
  FIsDirty := True;
end;

destructor TdxTileControlItemViewInfo.Destroy;
begin
  FreeAndNil(FCache);
  FreeAndNil(FPosition);
  inherited Destroy;
end;

procedure TdxTileControlItemViewInfo.CalculateBounds;
var
  ABounds: TRect;
  AItemSize, AItemIndent, AHeight: Integer;
  ATop: Integer;
begin
  AItemSize := TileControl.OptionsView.ItemSize;
  AItemIndent := TileControl.OptionsView.ItemIndent;
  if FPosition.Column > 0 then
    ABounds.Left := Item.Group.Bounds.Left + FPosition.Column * (AItemSize + AItemIndent)
  else
    ABounds.Left := Item.Group.Bounds.Left;
  ATop := Item.Group.Bounds.Top + Item.Group.Caption.Height;
  if FPosition.Row > 0 then
    ABounds.Top := ATop + FPosition.Row * (AItemSize + AItemIndent)
  else
    ABounds.Top := ATop;
  ABounds.Right := ABounds.Left + TileControl.ViewInfo.GetItemWidth(Item.IsLarge);
  AHeight := Item.RowCount * (AItemSize + AItemIndent) - AItemIndent;
  ABounds.Bottom := ABounds.Top + AHeight;
  Bounds := cxRectOffset(ABounds, 1, 1);
end;

procedure TdxTileControlItemViewInfo.DoCalculate;
begin
  if FItem.Visible then
  begin
    CalculateBounds;
    inherited DoCalculate;
  end;
end;

procedure TdxTileControlItemViewInfo.DoDraw(ACanvas: TcxCanvas);

  function CalculateCheckMarkAlpha: Byte;
  begin
    if TdxTileControlDragDropItem(TileControl.DragAndDropObject).IsPullDownGesture then
      Result := MaxByte
    else
      Result := MulDiv(150, TdxTileControlDragDropItem(TileControl.DragAndDropObject).PullProgress, 100);
  end;

begin
  if (Group = nil) or Group.IsDragged or not ACanvas.RectVisible(GetActualVisualBounds) then Exit;

  Calculated := True;

  if Item.IsDragged or (not Controller.CanItemDrawing and (Controller.DragCell = Self)) then
  begin
    if NeedDrawDragItemPlace then
      Painter.DrawItemPlace(ACanvas, DragItemPlaceBounds);
    if TdxTileControlDragDropItem(TileControl.DragAndDropObject).State = tcddsPulling then
    begin
      Painter.DrawDefaultItemCheck(ACanvas, Bounds, clNone,
        Painter.GroupCaptionDefaultTextColor, CalculateCheckMarkAlpha);
    end;
    Exit;
  end;
  if IsAnimatedOnDragDrop then Exit;

  if ACanvas.RectVisible(Bounds) then
  begin
    DrawContent(ACanvas, GetDrawBounds);
    if Selected then
      DrawSelection(ACanvas);
    if Item.Checked then
      DrawChecked(ACanvas);
  end;

  if Focused then
    DrawFocusRect(ACanvas)
  else
    if Hottracked then
      DrawHottrackRect(ACanvas)
end;

procedure TdxTileControlItemViewInfo.DirtyChanged;
begin
  FreeAndNil(FCache);
  ValidateImage;
end;

procedure TdxTileControlItemViewInfo.DrawChecked(ACanvas: TcxCanvas);
begin
  Painter.DrawItemCheck(ACanvas, Bounds);
end;

procedure TdxTileControlItemViewInfo.DrawContent(ACanvas: TcxCanvas; const ADrawRect: TRect);
begin
  ValidateCache(ADrawRect);
  cxBitBlt(ACanvas.Handle, Cache.Canvas.Handle, ADrawRect, cxNullPoint, SRCCOPY);
end;

procedure TdxTileControlItemViewInfo.DrawFocusRect(ACanvas: TcxCanvas);
begin
  ACanvas.FrameRect(GetActualVisualBounds, Painter.SelectionFocusedColor, dxTileFocusItemFrameSize);
end;

procedure TdxTileControlItemViewInfo.DrawHottrackRect(ACanvas: TcxCanvas);
var
  R: TRect;
begin
  R := GetActualVisualBounds;
  ACanvas.SaveClipRegion;
  try
    ACanvas.ExcludeClipRect(cxRectInflate(R, -dxTileFocusItemFrameSize, -dxTileFocusItemFrameSize));
    with TdxSkinCanvas.Create do
    try
      BeginPaint(ACanvas.Handle, R);
      FillRectByColor(R, Painter.SelectionHottrackedColor, HottrackValue);
      EndPaint;
    finally
      Free;
    end;
  finally
    ACanvas.RestoreClipRegion;
  end;
end;

procedure TdxTileControlItemViewInfo.DrawSelection(ACanvas: TcxCanvas);
var
  R: TRect;
begin
  R := cxRectInflate(Bounds, InflateDelta, InflateDelta);
  with TdxSkinCanvas.Create do
  try
    BeginPaint(ACanvas.Handle, R);
    FillRectByColor(R, Painter.SelectionSelectedColor, 127);
    EndPaint;
  finally
    Free;
    ACanvas.Pen.Width := 1;
    ACanvas.Pen.Color := clRed;
    ACanvas.Pen.Style := psDashDot;
    ACanvas.Brush.Style := bsClear;
    ACanvas.Rectangle(R);
  end;
end;

function TdxTileControlItemViewInfo.GetActualVisualBounds: TRect;
begin
  Result := Bounds;
  if (Item = Controller.FocusedItem) or Hottracked then
    InflateRect(Result, dxTileFocusItemFrameSize, dxTileFocusItemFrameSize);
end;

function TdxTileControlItemViewInfo.GetDragItemPlaceBounds: TRect;
begin
  Result := cxRectInflate(Bounds,
    -dxTileControlInflateAnimationStepsCount,
    -dxTileControlInflateAnimationStepsCount);
end;

function TdxTileControlItemViewInfo.GetBaseDrawBounds: TRect;
begin
  Result := cxRectInflate(inherited GetBaseDrawBounds, InflateDelta, InflateDelta);
end;

function TdxTileControlItemViewInfo.GetTileControl: TdxCustomTileControl;
begin
  Result := Item.TileControl;
end;

function TdxTileControlItemViewInfo.GetVisibleBounds: TRect;
begin
  if Group = nil then
    Result := cxNullRect
  else
    Result := Group.ViewInfo.ClipRect;
end;

procedure TdxTileControlItemViewInfo.ValidateCache(const ADrawRect: TRect);

  function CheckCacheSize(const ADrawRect: TRect): Boolean;
  begin
    Result := (Cache <> nil) and
      (Cache.Width = cxRectWidth(ADrawRect)) and
      (Cache.Height = cxRectHeight(ADrawRect));
  end;

  procedure InternalDraw(ACanvas: TcxCanvas; const R: TRect);
  begin
    if Animation <> nil then
      Animation.Draw(ACanvas.Canvas, R)
    else
      ViewData.Image.StretchDraw(ACanvas.Handle, R);

    if not ViewData.NeedDrawTextOnImage then
    begin
      ACanvas.SaveDC;
      try
        ACanvas.IntersectClipRect(R);
        MoveWindowOrg(ACanvas.Handle, R.Left, R.Top);
        ViewData.DrawItemTexts(ACanvas);
      finally
        ACanvas.RestoreDC;
      end;
    end;
  end;

var
  AGraphic: GpGraphics;
  ATempImage: TdxGPImage;
  ATempImageDC: HDC;
begin
  IsDirty := False;
  if not CheckCacheSize(ADrawRect) then
  begin
    FreeAndNil(FCache);
    FCache := TcxBitmap.CreateSize(ADrawRect);
    if (cxRectWidth(Bounds) = Cache.Width) and (cxRectHeight(Bounds) = Cache.Height) then
      InternalDraw(Cache.cxCanvas, Cache.ClientRect)
    else
      if (Animation <> nil) or not ViewData.NeedDrawTextOnImage then
      begin
        ATempImage := TdxGPImage.CreateSize(ViewData.Bounds, 0);
        try
          GdipCheck(GdipGetImageGraphicsContext(ATempImage.Handle, AGraphic));
          GdipCheck(GdipGetDC(AGraphic, ATempImageDC));
          try
            cxPaintCanvas.BeginPaint(ATempImageDC);
            InternalDraw(cxPaintCanvas, ATempImage.ClientRect);
            cxPaintCanvas.EndPaint;
          finally
            GdipCheck(GdipReleaseDC(AGraphic, ATempImageDC));
            GdipCheck(GdipDeleteGraphics(AGraphic));
          end;
          ATempImage.StretchDraw(Cache.Canvas.Handle, Cache.ClientRect);
        finally
          ATempImage.Free;
        end;
      end
      else
        ViewData.Image.StretchDraw(Cache.Canvas.Handle, Cache.ClientRect);
  end;
end;

procedure TdxTileControlItemViewInfo.ValidateImage;
begin
  ViewData.ValidateViewData;
end;

function TdxTileControlItemViewInfo.GetController: TdxTileControlController;
begin
  Result := TileControl.Controller;
end;

function TdxTileControlItemViewInfo.GetFocused: Boolean;
begin
  Result := not TileControl.IsDesigning and (InflateDelta = 0) and
    (Controller.FocusedItem = Item) and ((Controller.HottrackedItem = nil) or
    not TileControl.OptionsBehavior.HideFocusOnItemHotTrack);
end;

function TdxTileControlItemViewInfo.GetGroup: TdxTileControlGroup;
begin
  Result := Item.Group;
end;

function TdxTileControlItemViewInfo.GetHottracked: Boolean;
begin
  Result := not TileControl.IsDesigning and
    TileControl.OptionsBehavior.ItemHotTrack and (InflateDelta = 0) and
    not Focused and ((HottrackValue <> 0) or (Controller.HottrackedItem = Item));
end;

function TdxTileControlItemViewInfo.GetNeedDrawDragItemPlace: Boolean;
begin
  Result := Controller.IsEnableDrawDragItemPlace;
end;

function TdxTileControlItemViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
    AHitTest.BitState[tchtItem] := True;
end;

function TdxTileControlItemViewInfo.GetSelected: Boolean;
var
  I: Integer;
begin
  Result := Controller.IsObjectSelected(FItem);
  if not Result then
    for I := 0 to FItem.Frames.Count - 1 do 
      if Controller.IsObjectSelected(FItem.Frames[I]) then
      begin
        Result := True;
        Break;
      end;
end;

function TdxTileControlItemViewInfo.GetPainter: TdxTileControlPainter;
begin
  Result := TileControl.Painter;
end;

function TdxTileControlItemViewInfo.GetViewData: TdxTileControlCustomItemViewData;
begin
  if FViewData = nil then
    FViewData := Item.GetActualViewData;
  Result := FViewData;
end;

procedure TdxTileControlItemViewInfo.SetHottrackValue(AValue: Integer);
begin
  if AValue <> FHottrackValue then
  begin
    if Visible then
      Item.Invalidate;
    FHottrackValue := AValue;
  end;
end;

procedure TdxTileControlItemViewInfo.SetInflateDelta(AValue: Integer);
begin
  if AValue <> FInflateDelta then
  begin
    if (AValue <> 0) and (HottrackValue <> 0) then
    begin
      FHottrackValue := 0;
      Item.Invalidate;
    end;
    FInflateDelta := AValue;
    if Visible then
      Item.Invalidate;
  end;
end;

procedure TdxTileControlItemViewInfo.SetIsDirty(AValue: Boolean);
begin
  if AValue <> FIsDirty then
  begin
    FIsDirty := AValue;
    if not IsDirty then
      DirtyChanged;
  end;
end;

procedure TdxTileControlItemViewInfo.SetViewData(AValue: TdxTileControlCustomItemViewData);
begin
  if Animation <> nil then
    Animation.Terminate;
  FViewData := AValue;
  IsDirty := True;
  Calculated := False; 
  Item.Invalidate;
end;

{ TdxTileControlCustomGroupViewInfo }

constructor TdxTileControlCustomGroupViewInfo.Create(AOwner: TdxTileControlGroup);
begin
  inherited Create;
  FGroup := AOwner;
end;

procedure TdxTileControlCustomGroupViewInfo.CalculateBounds;
var
  AWidth, AHeight: Integer;
begin
  CalculateSize(AWidth, AHeight);
  Bounds := cxRectBounds(GetLeftPos, GetTopPos, AWidth, AHeight);
end;

procedure TdxTileControlCustomGroupViewInfo.CalculateSize(var AWidth, AHeight: Integer);
begin
  AWidth := 0;
  AHeight := 0;
end;

function TdxTileControlCustomGroupViewInfo.GetLeftPos: Integer;
begin
  Result := 0;
end;

function TdxTileControlCustomGroupViewInfo.GetTopPos: Integer;
begin
  Result := 0;
end;

function TdxTileControlCustomGroupViewInfo.GetVisibleBounds: TRect;
begin
  Result := TileControl.ViewInfo.TilesArea;
end;

function TdxTileControlCustomGroupViewInfo.GetPainter: TdxTileControlPainter;
begin
  Result := TileControl.Painter;
end;

function TdxTileControlCustomGroupViewInfo.GetTileControl: TdxCustomTileControl;
begin
  Result := Group.TileControl;
end;

procedure TdxTileControlCustomGroupViewInfo.Offset(const DX, DY: Integer);
begin
  Scroll(DX, DY);
end;

{ TdxTileControlVirtualGroupViewInfo }

procedure TdxTileControlVirtualGroupViewInfo.CalculateAreaBounds;
var
  ABounds, ATilesArea: TRect;
  AItemIndent, AGroupIndent: Integer;
  ASize, AWidth, AHeight, ALeft, ATop: Integer;
begin
  if not SizeMustFromDragItem then Exit;
  AItemIndent := TileControl.OptionsView.ItemIndent;
  AGroupIndent := TileControl.OptionsView.GroupIndent;
  ASize := AGroupIndent;
  ATilesArea := TileControl.ViewInfo.TilesArea;
  if GroupLayout = glHorizontal then
  begin
    ABounds := Group.MaximizedAreaBounds;
    ATop := ABounds.Top;
    AWidth := ASize;
    AHeight := cxRectHeight(ABounds);
    if (ATop + AHeight) > (ATilesArea.Bottom - AItemIndent) then
      AHeight := ATilesArea.Bottom - AItemIndent - ATop;

    if Self = Group.VirtualGroupBefore then
      ALeft := Bounds.Right - AItemIndent - AGroupIndent - AWidth
    else
      if Group.IsMostRight then
        ALeft := Bounds.Left + AItemIndent + AGroupIndent
      else
        ALeft := cxRectCenter(Bounds).X - AWidth div 2;
  end
  else
  begin
    AHeight := ASize;
    ABounds := Group.ExpandedBounds;
    ALeft := Max(AItemIndent, TileControl.OptionsView.IndentHorz - AItemIndent);
    AWidth := TileControl.ViewInfo.ContentWidth - 2 * ALeft;
    ALeft := ALeft - TileControl.ViewInfo.LeftScrollPos;
    if Self = Group.VirtualGroupBefore then
      ATop := (ATilesArea.Top + Bounds.Bottom - AHeight) div 2
    else
      if Group.IsMostRight then
        ATop := Bounds.Top + AItemIndent + AGroupIndent
      else
        ATop := cxRectCenter(Bounds).Y - AHeight div 2;
  end;
  FAreaBounds := cxRectBounds(ALeft, ATop, AWidth, AHeight);
end;

procedure TdxTileControlVirtualGroupViewInfo.CalculateSize(var AWidth, AHeight: Integer);
begin
  inherited CalculateSize(AWidth, AHeight);
  if not Group.Visible then Exit;
  if GroupLayout = glHorizontal then
    CalculateSizeAtHorizontalGroupLayout(AWidth, AHeight)
  else
    CalculateSizeAtVerticalGroupLayout(AWidth, AHeight);
end;

procedure TdxTileControlVirtualGroupViewInfo.CalculateSizeAtHorizontalGroupLayout(
  var AWidth, AHeight: Integer);

  function WeightOutermostGroup(const AAdvanceWidth: Integer): Integer;
  begin
    if not TileControl.IsItemDragged then
      Result := AAdvanceWidth
    else
      Result := Max(TileControl.ViewInfo.ItemHalfIndent + 1, AAdvanceWidth);
  end;

var
  AGroupIndent: Integer;
begin
  AGroupIndent := TileControl.OptionsView.GroupIndent;
  AWidth := AGroupIndent;
  if ((Self = Group.VirtualGroupBefore) and Group.IsMostLeft) or
     ((Self = Group.VirtualGroupAfter) and Group.IsMostRight) then
    AWidth := WeightOutermostGroup(TileControl.OptionsView.IndentHorz);
  if SizeMustFromDragItem then
    AWidth := AWidth + AGroupIndent + dxTileContolSizeGroupBorder * 2 +
      cxRectWidth(TdxTileControlDragDropItem(TileControl.DragAndDropObject).FDragItem.ViewInfo.Bounds);
  FBasisWidth := AWidth;
  if TileControl.ViewInfo.IsFixedContentLeftSide and (Self = Group.VirtualGroupBefore) and Group.IsMostLeft then
    AWidth := Max(AWidth, TileControl.ViewInfo.VisibleGroupsOrigin.X - TileControl.ViewInfo.TilesArea.Left);
  if (not TileControl.OptionsView.CenterContentHorz or TileControl.ViewInfo.IsFixedContentLeftSide) and
    (Self = Group.VirtualGroupAfter) and Group.IsMostRight then
    AWidth := Max(AWidth, TileControl.ViewInfo.ClientBounds.Right - Group.Bounds.Right);
  AHeight := Max(TileControl.ViewInfo.ContentHeight, TileControl.ClientBounds.Bottom);
end;

procedure TdxTileControlVirtualGroupViewInfo.CalculateSizeAtVerticalGroupLayout(
  var AWidth, AHeight: Integer);

  function HeightOutermostGroup(const AAdvanceHeight: Integer): Integer;
  begin
    if not TileControl.IsItemDragged then
      Result := AAdvanceHeight
    else
      Result := Max(TileControl.ViewInfo.ItemHalfIndent + 1, AAdvanceHeight);
  end;

var
  AGroupIndent: Integer;
begin
  AGroupIndent := TileControl.OptionsView.GroupIndent;
  AWidth := Max(TileControl.ViewInfo.ContentWidth, TileControl.ClientBounds.Right);
  AHeight := AGroupIndent;
  if ((Self = Group.VirtualGroupBefore) and Group.IsMostLeft) or
     ((Self = Group.VirtualGroupAfter) and Group.IsMostRight) then
    AHeight := HeightOutermostGroup(TileControl.OptionsView.IndentVert);
  if SizeMustFromDragItem then
    AHeight := AHeight + AGroupIndent + dxTileContolSizeGroupBorder * 2 +
      cxRectHeight(TdxTileControlDragDropItem(TileControl.DragAndDropObject).FDragItem.ViewInfo.Bounds);
  if TileControl.ViewInfo.IsFixedContentTopSide and (Self = Group.VirtualGroupBefore) and Group.IsMostLeft then
    AHeight := Max(AHeight, TileControl.ViewInfo.VisibleGroupsOrigin.Y - TileControl.ViewInfo.TilesArea.Top);
  if (not TileControl.OptionsView.CenterContentVert or TileControl.ViewInfo.IsFixedContentTopSide) and
    (Self = Group.VirtualGroupAfter) and Group.IsMostRight then
    AHeight := Max(AHeight, TileControl.ViewInfo.ClientBounds.Bottom - Group.Bounds.Bottom);
end;

procedure TdxTileControlVirtualGroupViewInfo.DoCalculate;
begin
  CalculateBounds;
  CalculateAreaBounds;
  inherited DoCalculate;
end;

procedure TdxTileControlVirtualGroupViewInfo.DoDraw(ACanvas: TcxCanvas);
begin
  if State = vgsVisible then
    Painter.DrawVirtualGroup(ACanvas, FAreaBounds)
end;

procedure TdxTileControlVirtualGroupViewInfo.ExpandBounds(const DW, DH: Integer);
begin
  Bounds := cxRectSetWidth(Bounds, Bounds.Right + DW);
  Bounds := cxRectSetHeight(Bounds,  Bounds.Bottom + DH);
  RecalculateAreaBounds;
end;

function TdxTileControlVirtualGroupViewInfo.GetGroupLayout: TdxTileControlGroupLayout;
begin
  Result := TileControl.OptionsView.GroupLayout;
end;

function TdxTileControlVirtualGroupViewInfo.GetLeftPos: Integer;
begin
  Result := inherited GetLeftPos;
  if Group.Visible then
    if (Self = Group.VirtualGroupAfter) and (GroupLayout = glHorizontal) then
      Result := Group.Bounds.Right
    else
      Result := TileControl.ViewInfo.TilesArea.Left - TileControl.ViewInfo.LeftScrollPos;
end;

function TdxTileControlVirtualGroupViewInfo.GetTopPos: Integer;
begin
  Result := inherited GetTopPos;
  if Group.Visible and (GroupLayout = glVertical) then
    if Self = Group.VirtualGroupBefore then
      Result := TileControl.ViewInfo.TilesArea.Top - TileControl.ViewInfo.TopScrollPos
    else
      Result := Group.Bounds.Bottom;
end;

procedure TdxTileControlVirtualGroupViewInfo.Invalidate;
begin
  if Visible then
    TileControl.InvalidateRect(Bounds, False);
end;

procedure TdxTileControlVirtualGroupViewInfo.RecalculateAreaBounds;
begin
  CalculateClipping;
  CalculateAreaBounds;
end;

procedure TdxTileControlVirtualGroupViewInfo.Scroll(const DX, DY: Integer);
begin
  inherited Scroll(DX, DY);
  FAreaBounds := cxRectOffset(FAreaBounds, DX, DY);
end;

procedure TdxTileControlVirtualGroupViewInfo.SetState(const AValue: TdxTileControlVirtualGroupState);
begin
  if FState <> AValue then
  begin
    FState := AValue;
    Invalidate;
    if AValue <> vgsVisible then
      SizeMustFromDragItem := False;
  end;
end;

{ TdxTileControlGroupViewInfo }

procedure TdxTileControlGroupViewInfo.CalculateExpandedBounds;
begin
  if not Group.Visible then
    FExpandedBounds := cxNullRect
  else
  begin
    FExpandedBounds := FMaximizedAreaBounds;
    if GroupLayout = glHorizontal then
    begin
      ExpandBoundsToTopControl(FExpandedBounds);
      ExpandBoundsToBottomControl(FExpandedBounds);
    end
    else
    begin
      ExpandBoundsToLeftControl(FExpandedBounds);
      ExpandBoundsToRightControl(FExpandedBounds);
    end;
  end;
end;

procedure TdxTileControlGroupViewInfo.CalculateMaximizedAreaBounds;
var
  AItemHalfIndent: Integer;
begin
  if not Group.Visible then
    FMaximizedAreaBounds := cxNullRect
  else
  begin
    AItemHalfIndent := TileControl.ViewInfo.ItemHalfIndent;
    FMaximizedAreaBounds := cxRectOffset(Bounds, -AItemHalfIndent, -AItemHalfIndent + Group.Caption.Height);
    FMaximizedAreaBounds.Bottom := FMaximizedAreaBounds.Top + GetTilesMaximizedAreaHeght;
    FMaximizedAreaBounds.Right := FMaximizedAreaBounds.Left + GetTilesMaximizedAreaWidth;
  end;
end;

procedure TdxTileControlGroupViewInfo.CalculateDimensionAndItemsPositions;
var
  I: Integer;
  AItem, AItemPrev: TdxTileControlItem;
begin
  AItemPrev := nil;
  FRowCount := 0;
  FColumnCount := 0;
  for I := 0 to Group.ItemCount - 1 do
  begin
    AItem := Group.Items[I];
    if not AItem.Visible then
      Continue;
    CalculateItemPosition(AItem, AItemPrev);
    if AItem.ViewInfo.Position.Row + AItem.RowCount > FRowCount then
      FRowCount := AItem.ViewInfo.Position.Row + AItem.RowCount;
    if AItem.ViewInfo.Position.Column >= FColumnCount - 1 then
      FColumnCount := AItem.ViewInfo.Position.Column + 1 + Ord(AItem.IsLarge);
    AItemPrev := AItem;
  end;
end;

procedure TdxTileControlGroupViewInfo.CalculateRowAndColumnLargeItem(
  AItem, AItemPrev: TdxTileControlItem; var ARow, AColumn: Integer);
var
  APrevPosition: TdxLayoutItemPosition;
  ASubColumnSize: Integer;
begin
  APrevPosition := AItemPrev.ViewInfo.Position;
  ARow := APrevPosition.Row + AItemPrev.RowCount;
  ASubColumnSize := TileControl.ViewInfo.SubColumnSize;
  AColumn := (APrevPosition.Column div ASubColumnSize) * ASubColumnSize;
  DoCorrectRowIfOccupiedForLargeItem(AItem, AColumn, ARow);
end;

procedure TdxTileControlGroupViewInfo.CalculateRowAndColumnNoLargeItem(
  AItem, AItemPrev: TdxTileControlItem; var ARow, AColumn: Integer);
var
  APrevPosition: TdxLayoutItemPosition;
  APrevItemRowCount: Integer;
begin
  AColumn := 0;
  ARow := 0;
  APrevPosition := AItemPrev.ViewInfo.Position;
  APrevItemRowCount := AItemPrev.RowCount;
  if AItemPrev.IsLarge then
  begin
    AColumn := APrevPosition.Column;
    ARow := APrevPosition.Row + APrevItemRowCount;
  end
  else
    if Odd(APrevPosition.Column) then
    begin
      AColumn := APrevPosition.Column - 1;
      ARow := APrevPosition.Row + 1;
    end
    else
    begin
      AColumn := APrevPosition.Column + 1;
      ARow := APrevPosition.Row;
    end;
  DoCorrectColumnAndRowIfOccupiedForNoLargeItem(AItem, AColumn, ARow);
end;

procedure TdxTileControlGroupViewInfo.CalculateItemPosition(AItem, AItemPrev: TdxTileControlItem);
var
  AColumn, ARow: Integer;
  APrevPosition: TdxLayoutItemPosition;
begin
  AColumn := 0;
  ARow := 0;
  if AItemPrev <> nil then
  begin
    APrevPosition := AItemPrev.ViewInfo.Position;
    if TileControl.ViewInfo.SubColumnSize = 1 then
      AColumn := APrevPosition.Column + 1 + Ord(AItemPrev.IsLarge)
    else
      if AItem.IsLarge then
        CalculateRowAndColumnLargeItem(AItem, AItemPrev, ARow, AColumn)
      else
        CalculateRowAndColumnNoLargeItem(AItem, AItemPrev, ARow, AColumn);
    DoCorrectColumnAndRow(AColumn, ARow, AItem.RowCount);
  end;
  AItem.ViewInfo.Position.Column := AColumn;
  AItem.ViewInfo.Position.Row := ARow;
end;

procedure TdxTileControlGroupViewInfo.CalculateSize(var AWidth, AHeight: Integer);
var
  AItemSize, AItemIndent: Integer;
begin
  inherited CalculateSize(AWidth, AHeight);
  if not Group.Visible then Exit;
  AItemSize := TileControl.OptionsView.ItemSize;
  AItemIndent := TileControl.OptionsView.ItemIndent;
  if FRowCount = 0 then
  begin
    AHeight := AItemSize;
    AWidth := AItemSize;
  end
  else
  begin
    AItemSize := AItemSize + AItemIndent;
    AHeight := AItemSize * FRowCount - AItemIndent;
    AWidth := AItemSize * FColumnCount - AItemIndent;
  end;
  AWidth := AWidth + 2 * dxTileContolSizeGroupBorder;
  AHeight := AHeight + Group.Caption.Height + 2 * dxTileContolSizeGroupBorder;
end;

procedure TdxTileControlGroupViewInfo.DoCalculate;
var
  I: Integer;
begin
  CalculateDimensionAndItemsPositions;
  CalculateBounds;
  CalculateMaximizedAreaBounds;
  CalculateExpandedBounds;
  inherited DoCalculate;
  Group.Caption.ViewInfo.Recalculate;
  for I := 0 to FGroup.ItemCount - 1 do
    FGroup.Items[I].ViewInfo.Calculated := False;
end;

procedure TdxTileControlGroupViewInfo.DoCorrectColumnAndRow(var AColumn, ARow: Integer;
  const AItemRowCount: Integer);
var
  ASubColumnSize: Integer;
begin
  ASubColumnSize := TileControl.ViewInfo.SubColumnSize;
  if (ARow > 0) and (ARow > TileControl.ViewInfo.RowCount - AItemRowCount) then
  begin
    ARow := 0;
    AColumn := (AColumn div ASubColumnSize + 1) * ASubColumnSize;
  end;
end;

procedure TdxTileControlGroupViewInfo.DoCorrectColumnAndRowIfOccupiedForNoLargeItem(
  ACurrentItem: TdxTileControlItem; var AColumn, ARow: Integer);
var
  APosition: TdxLayoutItemPosition;
begin
  APosition := TdxLayoutItemPosition.Create;
  try
    APosition.Row := ARow;
    APosition.Column := AColumn;
    while IsOccupiedByPriorItems(APosition, ACurrentItem) do
      if TileControl.ViewInfo.SubColumnSize = 1 then
      begin
        APosition.Column := APosition.Column + 1;
        APosition.Row := 0;
      end
      else
        if not Odd(APosition.Column) then
          APosition.Column := APosition.Column + 1
        else
        begin
          APosition.Row := APosition.Row + 1;
          APosition.Column := APosition.Column - 1;
        end;
    ARow := APosition.Row;
    AColumn := APosition.Column;
  finally
    APosition.Free;
  end;
end;

procedure TdxTileControlGroupViewInfo.DoCorrectRowIfOccupiedForLargeItem(
  ACurrentItem: TdxTileControlItem; const AColumn: Integer; var ARow: Integer);
var
  APosition: TdxLayoutItemPosition;
  I: Integer;
  AIsOccupied: Boolean;
begin
  APosition := TdxLayoutItemPosition.Create;
  try
    APosition.Row := ARow;
    AIsOccupied := True;
    while AIsOccupied do
    begin
      AIsOccupied := False;
      for I := 0 to TileControl.ViewInfo.SubColumnSize - 1 do
      begin
        APosition.Column := AColumn + I;
        AIsOccupied := IsOccupiedByPriorItems(APosition, ACurrentItem);
        if AIsOccupied then
          Break;
      end;
      if AIsOccupied then
        APosition.Row := APosition.Row + 1;
    end;
    ARow := APosition.Row;
  finally
    APosition.Free;
  end;
end;

procedure TdxTileControlGroupViewInfo.DoDraw(ACanvas: TcxCanvas);
const
  Styles: array [Boolean] of TPenStyle = (psDash, psDashDot);
  Colors: array [Boolean] of TColor = (dxTileVirtualGroupBackgroundColor, clBlue);
var
  ABounds: TRect;
begin
  if not cxRectIsNull(FNewGroupAreaBounds) then
  begin
    Painter.DrawVirtualGroup(ACanvas, FNewGroupAreaBounds);
    Exit;
  end;
  if Group.IsDragged then
  begin
    if (Group.Collection <> nil) and ((TileControl.ViewInfo.DragDropChanges = nil) or
      not TileControl.ViewInfo.DragDropChanges.DragObjectFinished) then
      Painter.DrawItemPlace(ACanvas, Bounds);
    Exit;
  end;
  if not TileControl.IsDesigning then Exit;
  ACanvas.Pen.Width := dxTileContolSizeGroupBorder;
  ACanvas.Pen.Style := Styles[Selected];
  ACanvas.Pen.Color := Colors[Selected];
  ACanvas.Brush.Style := bsClear;
  ABounds := cxRectInflate(Bounds, -1, -1);
  ABounds := Bounds;
  ACanvas.Rectangle(ABounds);
end;

procedure TdxTileControlGroupViewInfo.ExpandBoundsToBottomControl(var ABounds: TRect);
begin
  if ABounds.Bottom < TileControl.ViewInfo.ClientBounds.Bottom then
    ABounds.Bottom := TileControl.ViewInfo.ClientBounds.Bottom;
end;

procedure TdxTileControlGroupViewInfo.ExpandBoundsToLeftControl(var ABounds: TRect);
begin
  if ABounds.Left > TileControl.ViewInfo.ClientBounds.Left then
    ABounds.Left := TileControl.ViewInfo.ClientBounds.Left;
end;

procedure TdxTileControlGroupViewInfo.ExpandBoundsToRightControl(var ABounds: TRect);
begin
  if ABounds.Right < TileControl.ViewInfo.ClientBounds.Right then
    ABounds.Right := TileControl.ViewInfo.ClientBounds.Right;
end;

procedure TdxTileControlGroupViewInfo.ExpandBoundsToTopControl(var ABounds: TRect);
begin
  if ABounds.Top > TileControl.ViewInfo.ClientBounds.Top then
    ABounds.Top := TileControl.ViewInfo.ClientBounds.Top;
end;

function TdxTileControlGroupViewInfo.GetContentRect: TRect;
var
  I: Integer;
  ABounds: TRect;
begin
  if Group.ItemCount > 0 then
  begin
    Result.Left := Group.Items[0].ViewInfo.Bounds.Left;
    Result.Right := Group.Items[0].ViewInfo.Bounds.Right;
    Result.Top := Group.Items[0].ViewInfo.Bounds.Top;
    Result.Bottom := Group.Items[0].ViewInfo.Bounds.Bottom;
  end
  else
  begin
    Result.Left := Bounds.Left;
    Result.Right := Bounds.Right;
    Result.Bottom := Bounds.Bottom;
    Result.Top := Bounds.Top;
  end;
  for I := 1 to Group.ItemCount - 1 do
  begin      // left and top can't any more to change!
    ABounds := Group.Items[I].ViewInfo.Bounds;
    if ABounds.Right > Result.Right then
      Result.Right := ABounds.Right;
    if ABounds.Bottom > Result.Bottom then
      Result.Bottom := ABounds.Bottom;
  end;

end;

function TdxTileControlGroupViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
    AHitTest.BitState[tchtGroup] := True;
end;

function TdxTileControlGroupViewInfo.GetGroupLayout: TdxTileControlGroupLayout;
begin
  Result := TileControl.OptionsView.GroupLayout;
end;

function TdxTileControlGroupViewInfo.GetLeftPos: Integer;
var
  APrevGroup: TdxTileControlGroup;
begin
  Result := Bounds.Left;
  if Group.Groups = nil then Exit;
  Result := inherited GetLeftPos;
  if not Group.Visible then Exit;
  if GroupLayout = glHorizontal then
  begin
    APrevGroup := Group.Groups.GetPrevVisibleGroup(Group);
    if APrevGroup <> nil then
      Result := APrevGroup.VirtualGroupAfter.Bounds.Right
    else
      Result := Group.VirtualGroupBefore.Bounds.Right;
  end
  else
  begin
    Result := TileControl.OptionsView.IndentHorz - TileControl.ViewInfo.LeftScrollPos;
    if TileControl.ViewInfo.IsFixedContentLeftSide then
      Result := Max(Result, TileControl.ViewInfo.VisibleGroupsOrigin.X);
  end;
end;

function TdxTileControlGroupViewInfo.GetTilesMaximizedAreaHeght: Integer;
var
  AItemSize, AItemIndent: Integer;
begin
  AItemSize := TileControl.OptionsView.ItemSize;
  AItemIndent := TileControl.OptionsView.ItemIndent;
  if GroupLayout = glHorizontal then
    Result := (AItemSize + AItemIndent) * TileControl.ViewInfo.RowCount
  else
  begin
    Result := AItemSize + AItemIndent;
    if FRowCount > 0 then
      Result := Result * FRowCount;
  end;
end;

function TdxTileControlGroupViewInfo.GetTilesMaximizedAreaWidth: Integer;
begin
  Result := TileControl.OptionsView.ItemSize + TileControl.OptionsView.ItemIndent;
  if FColumnCount > 0 then
    Result := Result * FColumnCount;
end;

function TdxTileControlGroupViewInfo.GetTopPos: Integer;
var
  APrevGroup: TdxTileControlGroup;
begin
  Result := Bounds.Top;
  if not Group.Visible or (Group.Groups = nil) then Exit;
  if GroupLayout = glHorizontal then
  begin
    Result := TileControl.ViewInfo.TilesArea.Top + TileControl.OptionsView.IndentVert -
      TileControl.ViewInfo.TopScrollPos;
    if TileControl.ViewInfo.IsFixedContentTopSide then
      Result := Max(Result, TileControl.ViewInfo.VisibleGroupsOrigin.Y);
  end
  else
  begin
    APrevGroup := Group.Groups.GetPrevVisibleGroup(Group);
    if APrevGroup <> nil then
      Result := APrevGroup.VirtualGroupAfter.Bounds.Bottom
    else
      Result := Group.VirtualGroupBefore.Bounds.Bottom;
  end;
end;

function TdxTileControlGroupViewInfo.GetSelected: Boolean;
begin
  Result := TileControl.Controller.IsObjectSelected(FGroup);
end;

function TdxTileControlGroupViewInfo.GetZIndex(APosition: TdxLayoutItemPosition): Integer;
var
  ASubColumn, ASubColumnSize: Integer;
begin
  ASubColumnSize := TileControl.ViewInfo.SubColumnSize;
  if ASubColumnSize = 1 then
  begin
    Result := APosition.Column;
    Exit;
  end;
  ASubColumn := APosition.Column div ASubColumnSize;
  if ASubColumn > 0 then
    Result := RowCount * ASubColumnSize * ASubColumn - 1
  else
    Result := 0;
  if Odd(ColumnCount) and (APosition.Column = ColumnCount - 1) then
    Result := Result + APosition.Row + Ord(ColumnCount > 1)
  else
    Result := Result + APosition.Row * ASubColumnSize + Ord(ASubColumn > 0) +
      Ord(Odd(APosition.Column));
end;

procedure TdxTileControlGroupViewInfo.InitializeNextPosition(
  APosition: TdxLayoutItemPosition; var FNextPosition: TdxLayoutItemPosition;
  const AItemRowCount: Integer);
var
  ASubColumnSize: Integer;
  AColumn, ARow: Integer;
begin
  ASubColumnSize := TileControl.ViewInfo.SubColumnSize;
  if ASubColumnSize = 1 then
  begin
    ARow := APosition.Row;
    AColumn := APosition.Column + 1;
  end
  else
  begin
    if Odd(APosition.Column) then
    begin
     ARow := APosition.Row + 1;
     AColumn := APosition.Column - 1;
    end
    else
      if APosition.Column < ColumnCount - 1 then
      begin
        ARow := APosition.Row;
        AColumn := APosition.Column + 1;
      end
      else
      begin
        ARow := APosition.Row + 1;
        AColumn := APosition.Column;
      end;
    DoCorrectColumnAndRow(AColumn, ARow, AItemRowCount);
  end;
  FNextPosition.Column := AColumn;
  FNextPosition.Row := ARow;
end;

function TdxTileControlGroupViewInfo.IsItemOccupyPosition(AItem: TdxTileControlItem;
  APosition: TdxLayoutItemPosition; var AOccupiedRow: Integer): Boolean;
var
  AItemPosition: TdxLayoutItemPosition;
  AItemRowCount, AItemColumnCount: Integer;
begin
  Result := AItem.Visible;
  AOccupiedRow := 0;
  if not Result then Exit;
  AItemPosition := AItem.ViewInfo.Position;
  AItemRowCount := AItem.RowCount;
  AItemColumnCount := 1 + Ord(AItem.IsLarge);
  Result := (APosition.Row >= AItemPosition.Row) and
    (APosition.Row <= AItemPosition.Row + AItemRowCount - 1) and
    (APosition.Column >= AItemPosition.Column) and
    (APosition.Column <= AItemPosition.Column + AItemColumnCount - 1);
  if Result then
    AOccupiedRow := APosition.Row - AItemPosition.Row;
end;

function TdxTileControlGroupViewInfo.IsOccupiedByPriorItems(APosition: TdxLayoutItemPosition;
  ACurrentItem: TdxTileControlItem): Boolean;
var
  I: Integer;
  AOccupiedRow: Integer;
begin
  Result := False;
  for I := 0 to Group.FItems.IndexOf(ACurrentItem) - 1 do
    if IsItemOccupyPosition(Group.Items[I], APosition, AOccupiedRow) then
    begin
      Result := True;
      Break;
    end;
end;

procedure TdxTileControlGroupViewInfo.Scroll(const DX, DY: Integer);
begin
  inherited Scroll(DX, DY);
  FMaximizedAreaBounds := cxRectOffset(FMaximizedAreaBounds, DX, DY);
  FExpandedBounds := cxRectOffset(FExpandedBounds, DX, DY);
  if not cxRectIsEqual(FNewGroupAreaBounds, cxNullRect) then
    FNewGroupAreaBounds := cxRectOffset(FNewGroupAreaBounds, DX, DY);
end;

{ TdxTileControlTitleViewInfo }

constructor TdxTileControlTitleViewInfo.Create;
begin
  inherited Create;
  FFont := TFont.Create;
end;

destructor TdxTileControlTitleViewInfo.Destroy;
begin
  FreeAndNil(FFont);
  inherited Destroy;
end;

procedure TdxTileControlTitleViewInfo.DoCalculate;
begin
  TileControl.Painter.ValidatePainterData;
  Font.Assign(Title.Font);
  if Font.Size = dxTileControlDefaultTitleFontSize then
    Font.Size := Painter.TitleDefaultFontSize;
  FTextOffset := cxTextWidth(Font, ' ');
  FVisibleBounds := GetVisibleBounds;
  FBounds := FVisibleBounds;
  FClipRect := FBounds;
  FVisible := not cxRectIsEmpty(FBounds);
end;

procedure TdxTileControlTitleViewInfo.DoDraw(ACanvas: TcxCanvas);
begin
  if Title.Color <> clDefault then
    ACanvas.FillRect(Bounds, Title.Color);
  if Title.Text <> '' then
    cxTextOut(ACanvas.Canvas, Title.Text, FTextBounds,
      GetTextOutFlags, 0, 0, Font, clNone, clNone, 0, 0, 0, TextColor);
  if not Title.Glyph.Empty then
    ACanvas.Draw(GlyphBounds.Left, GlyphBounds.Top, Title.Glyph);
  ACanvas.ExcludeClipRect(Bounds);
end;

function TdxTileControlTitleViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
    AHitTest.BitState[tchtTitle] := True;
end;

function TdxTileControlTitleViewInfo.GetLeftOffset: Integer;
begin
  Result := TileControl.OptionsView.IndentHorz;
end;

function TdxTileControlTitleViewInfo.GetPainter: TdxTileControlPainter;
begin
  Result := TileControl.Painter;
end;

function TdxTileControlTitleViewInfo.GetTextColor: TColor;
begin
  Result := cxGetActualColor(Font.Color, Painter.TitleDefaultTextColor);
end;

function TdxTileControlTitleViewInfo.GetTextLeftOffset: Integer;
begin
  Result := GetLeftOffset;
end;

function TdxTileControlTitleViewInfo.GetTextOutFlags: Integer;
const
  HorzAlign: array[TAlignment] of TcxTextAlignX =
    (taLeft, taRight, taCenterX);
  VertAlign: array[TcxAlignmentVert] of TcxTextAlignY =
    (taTop, taBottom, taCenterY);
begin
  Result := cxMakeFormat(HorzAlign[Title.TextAlignHorz], VertAlign[Title.TextAlignVert]);
  if Title.WordWrap then
    Result := Result or CXTO_WORDBREAK;
end;

function TdxTileControlTitleViewInfo.GetVisibleBounds: TRect;
var
  R: TRect;
  AIndentVert: Integer;
begin
  R := TileControl.ClientBounds;
  if TileControl.VScrollBarVisible then
    Inc(R.Right, TileControl.VScrollBar.Width);
  Result := cxRectSetHeight(R, 0);
  AIndentVert := Title.IndentVert;
  if not Title.Glyph.Empty then
  begin
    Result.Bottom := Result.Top + cxRectHeight(Title.Glyph.ClientRect) + AIndentVert * 2;
    Dec(R.Right, Title.Glyph.ClientRect.Right + TextOffset * 2);
  end;
  FTextBounds.Right := GetLeftOffset;
  FGlyphBounds.Left := R.Right;
  if Title.Text <> '' then
  begin
    R.Left := GetTextLeftOffset;
    FTextBounds := MeasureTextBounds(R);
    Result.Bottom := Max(Result.Bottom, Result.Top + cxRectHeight(FTextBounds) + AIndentVert * 2);
    OffsetRect(FTextBounds, 0, AIndentVert);
  end;
  if Self is TdxTileControlDetailSiteTitleViewInfo then
  begin
    R := TdxTileControlDetailSiteTitleViewInfo(Self).Bounds;
    Result.Bottom := Max(Result.Bottom, Result.Top + cxRectHeight(R));
  end;
  if Title.Text <> '' then
    FTextBounds := cxRectSetTop(FTextBounds, Result.Top + (cxRectHeight(Result) - cxRectHeight(FTextBounds)) div 2);
  if not Title.Glyph.Empty then
  begin
    FGlyphBounds := Rect(Result.Right - Title.Glyph.Width,
      Result.Bottom - Title.Glyph.Height, Result.Right, Result.Bottom);
    OffsetRect(FGlyphBounds, -Title.IndentHorz, -FGlyphBounds.Top div 2);
  end;
end;

function TdxTileControlTitleViewInfo.MeasureTextBounds(const AVisibleBounds: TRect): TRect;
var
  DC: HDC;
  AFontHandle: HFONT;
  ATextRows: TcxTextRows;
  ATextParams: TcxTextParams;
  ALineCount: Integer;
const
  CalcFlags = CXTO_CALCROWCOUNT or CXTO_AUTOINDENTS or CXTO_CHARBREAK;
begin
  Result := AVisibleBounds;
  if Title.Text = '' then
  begin
    Result.Bottom := Result.Top;
    Exit;
  end;
  DC := GetDC(0);
  AFontHandle := SelectObject(DC, Font.Handle);
  try
    ATextParams := cxCalcTextParams(DC, GetTextOutFlags or CalcFlags);
    cxMakeTextRows(DC, PChar(Title.Text), Length(Title.Text), Result,
      ATextParams, ATextRows, ALineCount);
    Result := cxRectSetSize(Result, cxGetLongestTextRowWidth(ATextRows, ALineCount),
      ALineCount * ATextParams.FullRowHeight);
    cxResetTextRows(ATextRows);
  finally
    SelectObject(DC, AFontHandle);
    ReleaseDC(0, DC)
  end;
end;

procedure TdxTileControlTitleViewInfo.Scroll(const DX, DY: Integer);
begin
end;

function TdxTileControlTitleViewInfo.GetTileControl: TdxCustomTileControl;
begin
  Result := Title.TileControl;
end;

{ TdxTileControlItemText }

constructor TdxTileControlItemText.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FColor := clDefault;
  FFont := TFont.Create;
  FFont.Name := DefaultFontName;
  FFont.Size := 10;
  Font.Color := clDefault;
  FFont.OnChange := FontChanged;
  FTextColor := clDefault;
  FDefaultAlign := oaTopLeft;
  FTransparent := True;
  FIndentHorz := dxTileItemObjectDefaultIndent;
  FIndentVert := dxTileItemObjectDefaultIndent;
end;

destructor TdxTileControlItemText.Destroy;
begin
  FreeAndNil(FFont);
  inherited Destroy;
end;

procedure TdxTileControlItemText.Assign(ASource: TPersistent);
var
  ASourceText: TdxTileControlItemText;
begin
  if ASource is TdxTileControlItemText then
  begin
    ASourceText := TdxTileControlItemText(ASource);
    Align := ASourceText.Align;
    IndentHorz := ASourceText.IndentHorz;
    IndentVert := ASourceText.IndentVert;
    Value := ASourceText.Value;
    Font := ASourceText.Font;
    Transparent := ASourceText.Transparent;
    TextColor := ASourceText.TextColor;
    Color := ASourceText.Color;
    AssignedValues := ASourceText.AssignedValues;
  end
  else
    inherited Assign(ASource);
end;

procedure TdxTileControlItemText.CalculateBounds(var ABounds: TRect);
var
  DC: HDC;
  AFontHandle: HFONT;
  ATextRows: TcxTextRows;
  ATextParams: TcxTextParams;
  ALineCount: Integer;
begin
  if not HasValue then
  begin
    ABounds := cxNullRect;
    Exit;
  end;
  DC := GetDC(0);
  try
    AFontHandle := SelectObject(DC, GetActualFont.Handle);
    InflateRect(ABounds, -cxTextSpace, -cxTextSpace);
    ATextParams := cxCalcTextParams(DC, GetTextOutFlags or CXTO_CALCROWCOUNT);
    cxMakeTextRows(DC, PChar(GetActualValue), Length(GetActualValue), ABounds, ATextParams, ATextRows, ALineCount);
    SelectObject(DC, AFontHandle);
    ALineCount := Min(ALineCount, (ABounds.Bottom - ABounds.Top) div ATextParams.FullRowHeight);
    ABounds.Bottom := ABounds.Top + ALineCount * ATextParams.FullRowHeight;
    ABounds.Right := Min(ABounds.Right, ABounds.Left + cxGetLongestTextRowWidth(ATextRows, ALineCount));
    cxResetTextRows(ATextRows);
  finally
    ReleaseDC(0, DC);
  end;
end;

procedure TdxTileControlItemText.FontChanged(Sender: TObject);
begin
  FAssignedValues := FAssignedValues + [avFont];
  Changed;
end;

function TdxTileControlItemText.GetActualAlign: TdxTileItemInnerObjectAlignment;
begin
  Result := Align;
  if Result = oaDefault then
    Result := FDefaultAlign;
end;

function TdxTileControlItemText.GetActualColor: TColor;
begin
  Result := Color;
  if not (avColor in AssignedValues) then
    Result := Owner.TileItem.TileControl.Painter.DefaultItemTextBackgroundColor;
end;

function TdxTileControlItemText.GetActualFont: TFont;
begin
  if avFont in AssignedValues then
    Result := Font
  else
    Result := Owner.Style.Font;
end;

function TdxTileControlItemText.GetActualFontColor: TColor;
begin
  Result := TextColor;
  if not (avTextColor in AssignedValues) then
    Result := GetActualFont.Color;
end;

function TdxTileControlItemText.GetActualValue: string;
begin
  Result := Value;
  if (Result = '') and Owner.TileItem.TileControl.IsDesigning and (FDefaultAlign = oaTopLeft) then
    Result := Owner.TileItem.Name;
end;

function TdxTileControlItemText.GetTextOutFlags: Integer;
const
  AFlags: array[TAlignment] of Integer =
   (CXTO_LEFT or CXTO_TOP,
    CXTO_RIGHT or CXTO_TOP,
    CXTO_CENTER_HORIZONTALLY or CXTO_TOP);
begin
  Result := AFlags[Alignment] or CXTO_EXCELSTYLE or CXTO_END_ELLIPSIS;
  if WordWrap then
    Result := Result or CXTO_WORDBREAK;
end;

function TdxTileControlItemText.HasValue: Boolean;
begin
  Result := (GetActualValue <> '') and (GetActualValue[1] <> #0);
end;

function TdxTileControlItemText.IsFontStored: Boolean;
begin
  Result := avFont in AssignedValues;
end;

procedure TdxTileControlItemText.SetAlign(AValue: TdxTileItemInnerObjectAlignment);
begin
  if FAlign <> AValue then
  begin
    FAlign := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemText.SetAlignment(AValue: TAlignment);
begin
  if FAlignment <> AValue then
  begin
    FAlignment := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemText.SetAssignedValues(AValue: TdxTileItemTextAssignedValues);
begin
  if FAssignedValues <> AValue then
  begin
    FAssignedValues := AValue;
    if not (avColor in FAssignedValues) then
      FColor := clDefault;
    if not (avTextColor in FAssignedValues) then
      FTextColor := clDefault;
    if not (avFont in FAssignedValues) then
    begin
      FFont.OnChange := nil;
      FFont.Name := DefaultFontName;
      FFont.Size := 10;
      Font.Color := clDefault;
      FFont.OnChange := FontChanged;
    end;
    Changed;
  end;
end;

procedure TdxTileControlItemText.SetColor(AValue: TColor);
begin
  if FColor <> AValue then
  begin
    FColor := AValue;
    FAssignedValues := FAssignedValues + [avColor];
    Changed;
  end;
end;

procedure TdxTileControlItemText.SetFont(AValue: TFont);
begin
  FFont.Assign(AValue);
end;

procedure TdxTileControlItemText.SetIndentHorz(AValue: Integer);
begin
  if FIndentHorz <> AValue then
  begin
    FIndentHorz := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemText.SetIndentVert(AValue: Integer);
begin
  if FIndentVert <> AValue then
  begin
    FIndentVert := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemText.SetTextColor(AValue: TColor);
begin
  if FTextColor <> AValue then
  begin
    FTextColor := AValue;
    FAssignedValues := FAssignedValues + [avTextColor];
    Changed;
  end;
end;

procedure TdxTileControlItemText.SetValue(const AValue: string);
begin
  if FValue <> AValue then
  begin
    FValue := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemText.SetTransparent(AValue: Boolean);
begin
  if FTransparent <> AValue then
  begin
    FTransparent := AValue;
    Changed; 
  end;
end;

procedure TdxTileControlItemText.SetWordWrap(AValue: Boolean);
begin
  if FWordWrap <> AValue then
  begin
    FWordWrap := AValue;
    Changed;
  end;
end;

{ TdxTileControlItemGlyph }

constructor TdxTileControlItemGlyph.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FImage := TdxSmartImage.Create;
  FImage.OnChange := ImageChanged;
  FIndentHorz := dxTileItemObjectDefaultIndent;
  FIndentVert := dxTileItemObjectDefaultIndent;
  FMode := ifmNormal;
end;

destructor TdxTileControlItemGlyph.Destroy;
begin
  FreeAndNil(FImage);
  inherited Destroy;
end;

procedure TdxTileControlItemGlyph.Assign(ASource: TPersistent);
var
  ASourceImage: TdxTileControlItemGlyph;
begin
  if ASource is TdxTileControlItemGlyph then
  begin
    ASourceImage := TdxTileControlItemGlyph(ASource);
    Align := ASourceImage.Align;
    Image := ASourceImage.Image;
    IndentHorz := ASourceImage.IndentHorz;
    IndentVert := ASourceImage.IndentVert;
    AlignWithText := ASourceImage.AlignWithText;
    Mode := ASourceImage.Mode;
  end
  else
    inherited Assign(ASource);
end;

function TdxTileControlItemGlyph.GetClientRect(const ABounds: TRect): TRect;
var
  AImageSize, ARectSize, AGlyphSize: TSize;
  K: double;
begin
  AImageSize := cxSize(Image.ClientRect);
  AGlyphSize := AImageSize;
  if not Image.Empty then
  begin
    ARectSize := cxSize(ABounds);
    K := Min(ARectSize.cx / AImageSize.cx, ARectSize.cy / AImageSize.cy);
    case Mode of
      ifmStretch:
        AGlyphSize := ARectSize;
      ifmProportionalStretch:
        AGlyphSize := cxSize(Trunc(AImageSize.cx * K), Trunc(AImageSize.cy * K));
      ifmFit:
        if K < 1 then
          AGlyphSize := cxSize(Trunc(AImageSize.cx * K), Trunc(AImageSize.cy * K));
    end; 
  end;
  Result := cxRectCenter(ABounds, AGlyphSize);
end;

function TdxTileControlItemGlyph.GetActualAlign: TdxTileItemInnerObjectAlignment;
begin
  Result := Align;
  if Result = oaDefault then
    Result := oaMiddleCenter; 
end;

function TdxTileControlItemGlyph.IsChanged: Boolean;
begin
 Result := (Align <> oaDefault) or not Image.Empty or
   (IndentHorz <> 0) or (IndentVert <> 0);
end;

procedure TdxTileControlItemGlyph.ImageChanged(Sender: TObject);
begin
  Changed;
end;

procedure TdxTileControlItemGlyph.SetAlign(AValue: TdxTileItemInnerObjectAlignment);
begin
  if FAlign <> AValue then
  begin
    FAlign := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemGlyph.SetAlignWithText(AValue: TdxTileControlImageWithTextAlignment);
begin
  if FAlignWithText <> AValue then
  begin
    FAlignWithText := AValue;
    Changed; 
  end;
end;

procedure TdxTileControlItemGlyph.SetImage(AValue: TdxSmartImage);
begin
  FImage.Assign(AValue);
  Changed;
end;

procedure TdxTileControlItemGlyph.SetIndentHorz(AValue: Integer);
begin
  if FIndentHorz <> AValue then
  begin
    FIndentHorz := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemGlyph.SetIndentVert(AValue: Integer);
begin
  if FIndentVert <> AValue then
  begin
    FIndentVert := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemGlyph.SetMode(AValue: TcxImageFitMode);
begin
  if FMode <> AValue then
  begin
    FMode := AValue;
    Changed;
  end;
end;

{ TdxTileControlCustomStyle }

constructor TdxTileControlCustomStyle.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FFont := TFont.Create;
  FFont.Name := DefaultFontName;
  Font.Color := clDefault;
  FFont.OnChange := FontChanged;
  FBorderColor := clDefault;
  FTexture := TdxSmartImage.Create;
  FTexture.OnChange := ImageChanged;
  FGradientBeginColor := clDefault;
  FGradientEndColor := clDefault;
end;

destructor TdxTileControlCustomStyle.Destroy;
begin
  FreeAndNil(FFont);
  FreeAndNil(FTexture);
  inherited Destroy;
end;

procedure TdxTileControlCustomStyle.Assign(ASource: TPersistent);
var
  ASourceStyle: TdxTileControlCustomStyle;
begin
  if ASource is TdxTileControlCustomStyle then
  begin
    ASourceStyle := TdxTileControlCustomStyle(ASource);
    Font := ASourceStyle.Font;
    FBorderColor := ASourceStyle.FBorderColor;
    Gradient := ASourceStyle.Gradient;
    GradientBeginColor := ASourceStyle.GradientBeginColor;
    GradientEndColor := ASourceStyle.GradientEndColor;
    Stretch := ASourceStyle.Stretch;
    Texture := ASourceStyle.Texture;
  end
  else
    inherited Assign(ASource);
end;

procedure TdxTileControlCustomStyle.Changed;
begin
  if Assigned(FOnChange) then
    FOnChange(Self);
end;

procedure TdxTileControlCustomStyle.FontChanged(Sender: TObject);
begin
  FFontChanged := True;
  Changed;
end;

function TdxTileControlCustomStyle.IsChanged: Boolean;
begin
  Result := (Gradient <> gmHorizontal) or (GradientBeginColor <> clNone) or
    (GradientEndColor <> clNone) or (Stretch <> smStretch) or not Texture.Empty or
    (BorderColor <> clDefault) or FFontChanged;
end;

function TdxTileControlCustomStyle.IsEmpty: Boolean;
begin
  Result := (GradientBeginColor = clDefault) and
    (GradientEndColor = clDefault) and Texture.Empty;
end;

procedure TdxTileControlCustomStyle.ImageChanged(Sender: TObject);
begin
  Changed;
end;

function TdxTileControlCustomStyle.IsFontStored: Boolean;
begin
  Result := FFontChanged;
end;

procedure TdxTileControlCustomStyle.SetBorderColor(AValue: TColor);
begin
  if FBorderColor <> AValue then
  begin
    FBorderColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlCustomStyle.SetFont(AValue: TFont);
begin
  FFont.Assign(AValue);
end;

procedure TdxTileControlCustomStyle.SetGradientBeginColor(AValue: TColor);
begin
  if FGradientBeginColor <> AValue then
  begin
    FGradientBeginColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlCustomStyle.SetGradientEndColor(AValue: TColor);
begin
  if FGradientEndColor <> AValue then
  begin
    FGradientEndColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlCustomStyle.SetGradientMode(AValue: TdxSkinGradientMode);
begin
  if FGradient <> AValue then
  begin
    FGradient := AValue;
    Changed;
  end;
end;

procedure TdxTileControlCustomStyle.SetStretch(AValue: TdxSkinStretchMode);
begin
  if FStretch <> AValue then
  begin
    FStretch := AValue;
    Changed;
  end;
end;

procedure TdxTileControlCustomStyle.SetTexture(AValue: TdxSmartImage);
begin
  if AValue <> nil then
    FTexture.Assign(AValue)
  else
    FTexture.Clear;
  Changed;
end;

{ TdxTileControlCustomItemViewData }

constructor TdxTileControlCustomItemViewData.Create(AItem: TdxTileControlCustomItem);
begin
  inherited Create;
  FItem := AItem;
  FNeedDrawTextOnImage := True;
  IsDirty := True;
end;

destructor TdxTileControlCustomItemViewData.Destroy;
begin
  FreeAndNil(FImage);
  inherited Destroy;
end;

procedure TdxTileControlCustomItemViewData.AdjustObjectBounds(const ABounds: TRect;
  var AObjectBounds: TRect; AAlign: TdxTileItemInnerObjectAlignment;
  AIndentHorz, AIndentVert: Integer);
begin
  if AAlign in [oaTopCenter, oaMiddleCenter, oaBottomCenter] then
  begin
    AObjectBounds := cxRectSetLeft(AObjectBounds, (ABounds.Left + ABounds.Right - cxRectWidth(AObjectBounds)) div 2);
    AIndentHorz := 0;
  end
  else
    if AAlign in [oaTopRight, oaMiddleRight, oaBottomRight] then
    begin
      AObjectBounds := cxRectSetRight(AObjectBounds, ABounds.Right);
      AIndentHorz  := -AIndentHorz;
    end
    else
      AObjectBounds := cxRectSetLeft(AObjectBounds, ABounds.Left);
  if AAlign in [oaTopLeft, oaTopCenter, oaTopRight] then
    AObjectBounds := cxRectSetTop(AObjectBounds, ABounds.Top)
  else
    if AAlign in [oaMiddleLeft..oaMiddleRight] then
    begin
      AObjectBounds := cxRectSetTop(AObjectBounds,
        (ABounds.Top + ABounds.Bottom - cxRectHeight(AObjectBounds)) div 2);
       AIndentVert := 0;
    end
    else
    begin
      AObjectBounds := cxRectSetBottom(AObjectBounds, ABounds.Bottom);
      AIndentVert := -AIndentVert
    end;
  OffsetRect(AObjectBounds, AIndentHorz, AIndentVert);
end;

procedure TdxTileControlCustomItemViewData.AdjustImageBoundsWithText(const ABounds: TRect; 
  AText: TdxTileControlItemText; var AImageBounds, ATextBounds: TRect);
var
  R: TRect;
  DW, DH: Integer;
  AGlyph: TdxTileControlItemGlyph;
  AAlign: TdxTileControlImageWithTextAlignment;
  AImageAlign: TdxTileItemInnerObjectAlignment;
begin
  AGlyph := Item.Glyph;
  AAlign := AGlyph.AlignWithText;
  AImageAlign := AGlyph.GetActualAlign;
  R := cxRect(cxRectSize(AImageBounds));
  if AAlign in [itaLeft, itaRight] then
    Inc(R.Right, cxRectWidth(ATextBounds) + AText.IndentHorz)
  else
    Inc(R.Bottom, cxRectHeight(ATextBounds) + AText.IndentVert);
  AdjustObjectBounds(ABounds, R, AImageAlign, AGlyph.IndentHorz, AGlyph.IndentVert);
  //
  case AAlign of
    itaLeft:
    begin
      AImageBounds := cxRectSetLeft(AImageBounds, R.Left);
      ATextBounds := cxRectSetLeft(ATextBounds,  AImageBounds.Right + AText.IndentHorz);
    end;
    itaTop:
    begin
      AImageBounds := cxRectSetTop(AImageBounds, R.Top);
      ATextBounds := cxRectSetTop(ATextBounds,  AImageBounds.Bottom + AText.IndentVert);
    end;
    itaRight:
    begin
      AImageBounds := cxRectSetRight(AImageBounds, R.Right);
      ATextBounds := cxRectSetRight(ATextBounds,  AImageBounds.Left - AText.IndentHorz);
    end;
    itaBottom:
    begin
      AImageBounds := cxRectSetBottom(AImageBounds, R.Bottom);
      ATextBounds := cxRectSetBottom(ATextBounds,  AImageBounds.Top - AText.IndentVert);
    end;
  end;
   // correct image bounds for long text and center text with image bounds
  if not (AImageAlign in [oaTopCenter, oaMiddleCenter, oaBottomCenter]) then
  begin
    DW := 0;
    if cxRectWidth(ATextBounds) <= cxRectWidth(AImageBounds) then
      DW := (cxRectWidth(ATextBounds) - cxRectWidth(AImageBounds)) div 2;
    DH := 0;
    if cxRectHeight(ATextBounds) <= cxRectHeight(AImageBounds) then
      DH := (cxRectHeight(ATextBounds) - cxRectHeight(AImageBounds)) div 2;
    if (AAlign in [itaTop, itaBottom]) and (DW > 0) then
      OffsetRect(AImageBounds, DW * (Ord(AImageAlign in [oaTopLeft, oaMiddleLeft, oaBottomLeft]) * 2 - 1), 0)
    else
      if (AAlign in [itaLeft, itaRight]) and (DH > 0) then
        OffsetRect(AImageBounds, 0, DH * (Ord(AImageAlign in [oaTopLeft, oaTopCenter, oaTopRight]) * 2 - 1));
  end;
  if (AAlign in [itaTop, itaBottom]) then
  begin
    if cxRectWidth(ATextBounds) <= cxRectWidth(AImageBounds) then
      ATextBounds := cxRectSetLeft(ATextBounds, (AImageBounds.Left + AImageBounds.Right - cxRectWidth(ATextBounds)) div 2)
  end
  else
    if cxRectHeight(ATextBounds) <= cxRectHeight(AImageBounds) then
      ATextBounds := cxRectSetTop(ATextBounds, (AImageBounds.Top + AImageBounds.Bottom - cxRectHeight(ATextBounds)) div 2);
  // check clipping
  cxRectIntersect(AImageBounds, AImageBounds, ABounds);          // to do
  cxRectIntersect(ATextBounds, ATextBounds, ABounds);            // to do
end;

procedure TdxTileControlCustomItemViewData.CalculateImageAndTextLayout(const ABounds: TRect);
var
  I: Integer;
  AText: TdxTileControlItemText;
  AGlyph: TdxTileControlItemGlyph;

  function GetTextBounds(ANum: Integer): TRect;
  var
    AImageSize: TSize;
    AImageAlign: TdxTileControlImageWithTextAlignment;
  begin
    Result := ABounds;
    Result.BottomRight := cxPointOffset(Result.BottomRight, -AText.IndentHorz, -AText.IndentVert);
    AImageAlign := AGlyph.AlignWithText;
    if (ANum = 0) and (not Item.Glyph.Image.Empty) and (AImageAlign <> itaNone) then
    begin
      AImageSize := cxSize(FImageBounds);
      if AImageAlign in [itaLeft, itaRight] then
        Dec(Result.Right, AImageSize.cx + AGlyph.IndentHorz)
      else
        Dec(Result.Bottom, AImageSize.cy + AGlyph.IndentVert);
    end;
  end;

begin
  AGlyph := Item.Glyph;
  FImageBounds := AGlyph.GetClientRect(ABounds);
  if not Item.Glyph.Image.Empty and (cxRectWidth(ABounds) - cxRectWidth(FImageBounds) > 3) then
    FImageBounds := AGlyph.GetClientRect(ABounds);
  for I := 0 to 3 do
  begin
    AText := Item.GetText(I);
    if AText.GetActualValue = '' then Continue;
    FTextBounds[I] := GetTextBounds(I);
    AText.CalculateBounds(FTextBounds[I]);
    AdjustObjectBounds(ABounds, FTextBounds[I], AText.GetActualAlign, AText.IndentHorz, AText.IndentVert);
  end;
  if not cxRectIsEmpty(FImageBounds) then
  begin
    AdjustObjectBounds(ABounds, FImageBounds, AGlyph.GetActualAlign, AGlyph.IndentHorz, AGlyph.IndentVert);
    if (AGlyph.AlignWithText <> itaNone) and Item.GetText(0).HasValue then
      AdjustImageBoundsWithText(ABounds, Item.GetText(0), FImageBounds, FTextBounds[0]);
  end;
end;

procedure TdxTileControlCustomItemViewData.DrawItemBackground(const ACanvas: TcxCanvas);
var
  Style: TdxTileControlCustomStyle;
begin
  Style := Item.Style;
  if Item.ParentStyle then
    Style := TileItem.Style;
  Painter.DrawItemBackground(ACanvas, Bounds, Style);
end;

procedure TdxTileControlCustomItemViewData.DrawItemGlyph(const ACanvas: TcxCanvas);
begin
  if not Item.Glyph.Image.Empty then
  begin
    dxGPPaintCanvas.BeginPaint(ACanvas.Handle, ImageBounds);
    dxGPPaintCanvas.Draw(Item.Glyph.Image, ImageBounds);
    dxGPPaintCanvas.EndPaint;
  end;
end;

procedure TdxTileControlCustomItemViewData.DrawItemText(const ACanvas: TcxCanvas; const AIndex: Integer);
var
  R: TRect;
  AText: TdxTileControlItemText;
  ATextColor: TColor;
begin                                                        
  AText := Item.GetText(AIndex);
  if (Length(AText.GetActualValue) = 0) or not cxRectIntersect(R, FClientRect, FTextBounds[AIndex]) then
    Exit;

  ACanvas.SaveClipRegion;
  try
    if not cxRectIsEqual(R, FTextBounds[AIndex]) then
      ACanvas.SetClipRegion(TcxRegion.Create(R), roSet);
    ATextColor := cxGetActualColor(AText.GetActualFontColor, Painter.DefaultItemTextColor);
    if not AText.Transparent then
    begin
      ACanvas.FillRect(FTextBounds[AIndex],
        cxGetActualColor(AText.GetActualColor, Painter.DefaultItemTextBackgroundColor));
    end;
    cxTextOut(ACanvas.Canvas, AText.GetActualValue, FTextBounds[AIndex],
      AText.GetTextOutFlags, 0, 0, AText.GetActualFont, clNone, clNone, 0, 0, 0, ATextColor);
  finally
    ACanvas.RestoreClipRegion;
  end; 
end;

procedure TdxTileControlCustomItemViewData.DrawItemTexts(const ACanvas: TcxCanvas);
var
  I: Integer;
begin
  for I := 0 to 3 do
    DrawItemText(ACanvas, I);
end;

procedure TdxTileControlCustomItemViewData.PrepareViewData;
var
  ADestBitmap: TcxBitmap;
begin
  FClientRect := cxRectInflate(Bounds, cxRectInvert(Item.Margins.Margin));
  CalculateImageAndTextLayout(FClientRect);
  ADestBitmap := TcxBitmap.CreateSize(Bounds, pf24bit);
  try
    DrawItemBackground(ADestBitmap.cxCanvas);
    DrawItemGlyph(ADestBitmap.cxCanvas);
    if NeedDrawTextOnImage then
      DrawItemTexts(ADestBitmap.cxCanvas);
    if FImage = nil then
      FImage := TdxGPImage.CreateFromBitmap(ADestBitmap)
    else
      FImage.Assign(ADestBitmap);
  finally
    ADestBitmap.Free;
  end;
end;

procedure TdxTileControlCustomItemViewData.ValidateViewData;
begin
  if IsDirty then
  begin
    IsDirty := False;
    if IsActive then
      TileItem.ViewInfo.Calculated := False;
  end;
end;

function TdxTileControlCustomItemViewData.GetBounds: TRect;
begin
  Result := TileItem.GetClientBounds;
end;

function TdxTileControlCustomItemViewData.GetImage: TdxGPImage;
begin
  ValidateViewData;
  Result := FImage;
end;

function TdxTileControlCustomItemViewData.GetIsActive: Boolean;
begin
  Result := TileItem.ViewInfo.ViewData = Self;
end;

function TdxTileControlCustomItemViewData.GetPainter: TdxTileControlPainter;
begin
  Result := TileItem.TileControl.Painter;
end;

function TdxTileControlCustomItemViewData.GetTextBounds(AIndex: Integer): TRect;
begin
  Result := FTextBounds[AIndex]
end;

function TdxTileControlCustomItemViewData.GetTileItem: TdxTileControlItem;
begin
  Result := Item.GetTileItem;
end;

procedure TdxTileControlCustomItemViewData.SetIsDirty(AValue: Boolean);
begin
  if FIsDirty <> AValue then
  begin
    FIsDirty := AValue;
    if not IsDirty then
      PrepareViewData;
  end;
end;

procedure TdxTileControlCustomItemViewData.SetNeedDrawTextOnImage(AValue: Boolean);
begin
  if NeedDrawTextOnImage <> AValue then
  begin
    FNeedDrawTextOnImage := AValue;
    IsDirty := True;
    if IsActive then
      TileItem.ViewInfo.IsDirty := True;
  end;
end;

{ TdxTileControlCustomItemOptionsAnimate }

constructor TdxTileControlCustomItemOptionsAnimate.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FAnimateText := dxTileControlDefaultAnimateText;
end;

procedure TdxTileControlCustomItemOptionsAnimate.DoAssign(Source: TPersistent);
begin
  inherited DoAssign(Source);
  if Source is TdxTileControlCustomItemOptionsAnimate then
  begin
    AnimateText := TdxTileControlCustomItemOptionsAnimate(Source).AnimateText;
    AssignedValues := TdxTileControlCustomItemOptionsAnimate(Source).AssignedValues;
  end;
end;

function TdxTileControlCustomItemOptionsAnimate.IsAnimateTextStored: Boolean;
begin
  if ParentOptionsAnimate = nil then
    Result := FAnimateText <> dxTileControlDefaultAnimateText
  else
    Result := ioaavAnimateText in AssignedValues;
end;

function TdxTileControlCustomItemOptionsAnimate.GetAnimateText: Boolean;
begin
  if (ioaavAnimateText in AssignedValues) or (ParentOptionsAnimate = nil) then
    Result := FAnimateText
  else
    Result := ParentOptionsAnimate.AnimateText;
end;

function TdxTileControlCustomItemOptionsAnimate.GetParentOptionsAnimate: TdxTileControlCustomItemOptionsAnimate;
begin
  Result := nil;
end;

procedure TdxTileControlCustomItemOptionsAnimate.SetAnimateText(AValue: Boolean);
begin
  AssignedValues := AssignedValues + [ioaavAnimateText];
  FAnimateText := AValue;
end;

{ TdxTileControlItemOptionsAnimate }

function TdxTileControlItemOptionsAnimate.GetParentOptionsAnimate: TdxTileControlCustomItemOptionsAnimate;
begin
  if Owner is TdxTileControlItem then
    Result := TdxTileControlItem(Owner).TileControl.OptionsItemAnimate
  else
    Result := nil;
end;

{ TdxTileControlItemFrameOptionsAnimate }

function TdxTileControlItemFrameOptionsAnimate.GetParentOptionsAnimate: TdxTileControlCustomItemOptionsAnimate;
begin
  if Owner is TdxTileControlItemFrame then
    Result := TdxTileControlItemFrame(Owner).TileItem.OptionsAnimate
  else
    Result := nil;
end;

{ TdxTileControlCustomItem }

constructor TdxTileControlCustomItem.Create(AOwner: TComponent);
var
  I: Integer;
begin
  inherited Create(AOwner);
  FViewData := CreateViewData;
  FVisible := True;
  FGlyph := TdxTileControlItemGlyph.Create(Self);
  FStyle := TdxTileControlCustomStyle.Create(Self);
  FStyle.OnChange := StyleChanged;
  FOptionsAnimate := CreateOptionsAnimate;
  FMargins := TcxMargin.Create(Self, 1);
  FMargins.Margin := cxSimpleRect;
  FMargins.OnChange := MarginsChangeHandler;
  FParentStyle := True;
  for I := 0 to 3 do
    FTexts[I] := CreateText(DefaultTextAlignment[I]);
  FVisible := True;
end;

destructor TdxTileControlCustomItem.Destroy;
begin
  FreeAndNil(FStyle);
  FreeAndNil(FGlyph);
  FreeAndNil(FMargins);
  FreeAndNil(FTexts[0]);
  FreeAndNil(FTexts[1]);
  FreeAndNil(FTexts[2]);
  FreeAndNil(FTexts[3]);
  FreeAndNil(FOptionsAnimate);
  FreeAndNil(FViewData);
  inherited Destroy;
end;

procedure TdxTileControlCustomItem.Assign(ASource: TPersistent);
var
  ASourceFrame: TdxTileControlCustomItem;
begin
  if ASource is TdxTileControlCustomItem then
  begin
    ASourceFrame := TdxTileControlCustomItem(ASource);
    Style := ASourceFrame.Style;
    Glyph := ASourceFrame.Glyph;
    Text1 := ASourceFrame.Text1;
    Text2 := ASourceFrame.Text2;
    Text3 := ASourceFrame.Text3;
    Text4 := ASourceFrame.Text4;
    Margins := ASourceFrame.Margins;
    OptionsAnimate := ASourceFrame.OptionsAnimate;
    ParentStyle := ASourceFrame.ParentStyle;
    Visible := ASourceFrame.Visible;
  end
  else
    inherited Assign(ASource);
end;

procedure TdxTileControlCustomItem.Changed;
begin
  TileItem.Invalidate();
end;

function TdxTileControlCustomItem.CreateText(
  const AAlign: TdxTileItemInnerObjectAlignment): TdxTileControlItemText;
begin
  Result := TdxTileControlItemText.Create(Self);
  Result.FDefaultAlign := AAlign;
end;

function TdxTileControlCustomItem.CreateViewData: TdxTileControlCustomItemViewData;
begin
  Result := TdxTileControlCustomItemViewData.Create(Self);
end;

function TdxTileControlCustomItem.GetTileItem: TdxTileControlItem; 
begin
  Result := nil;
end;

procedure TdxTileControlCustomItem.StyleChanged(Sender: TObject);
begin
  Changed;
end;

function TdxTileControlCustomItem.GetText(Index: Integer): TdxTileControlItemText;
begin
  Result := FTexts[Index];
end;

function TdxTileControlCustomItem.IsGlyphStored: Boolean;
begin
  Result := Glyph.IsChanged;
end;

function TdxTileControlCustomItem.IsMarginsStored: Boolean;
begin
  Result := not cxRectIsEqual(Margins.Margin, cxSimpleRect);
end;

function TdxTileControlCustomItem.IsStyleStored: Boolean;
begin
  Result := Style.IsChanged;
end;

procedure TdxTileControlCustomItem.MarginsChangeHandler(Sender: TObject);
begin
  Changed;
end;

procedure TdxTileControlCustomItem.SetStyle(AValue: TdxTileControlCustomStyle);
begin
  FStyle.Assign(AValue);
  Changed;
end;

procedure TdxTileControlCustomItem.SetGlyph(AValue: TdxTileControlItemGlyph);
begin
  FGlyph.Assign(AValue);
  Changed;
end;

procedure TdxTileControlCustomItem.SetMargins(AValue: TcxMargin);
begin
  FMargins.Assign(AValue);
  Changed;
end;

procedure TdxTileControlCustomItem.SetOptionsAnimate(AValue: TdxTileControlItemOptionsAnimate);
begin
  FOptionsAnimate.Assign(AValue);
end;

procedure TdxTileControlCustomItem.SetParentStyle(AValue: Boolean);
begin
  if FParentStyle <> AValue then
  begin
    FParentStyle := AValue;
    Changed;
  end;
end;

procedure TdxTileControlCustomItem.SetText(AIndex: Integer; AValue: TdxTileControlItemText);
begin
  GetText(AIndex).Assign(AValue);
end;

procedure TdxTileControlCustomItem.SetVisible(AValue: Boolean);
begin
  if FVisible <> AValue then
  begin
    FVisible := AValue;
    Changed;
    TileItem.TileControl.LayoutChanged;
  end;
end;

{ TdxTileControlItemFrame }

destructor TdxTileControlItemFrame.Destroy;
begin
  TileItem.DoFrameDestroy(Self);
  TileItem.Controller.FrameDestroyed(Self);
  inherited Destroy;
end;

procedure TdxTileControlItemFrame.Changed;
begin
  TileItem.ViewInfo.IsDirty := True;
  ViewData.IsDirty := True;
  TileItem.FrameChanged(Self);
end;

function TdxTileControlItemFrame.CreateOptionsAnimate: TdxTileControlItemOptionsAnimate;
begin
  Result := TdxTileControlItemFrameOptionsAnimate.Create(Self);
end;

function TdxTileControlItemFrame.GetCollectionFromParent(AParent: TComponent): TcxComponentCollection;
begin
  Result := TdxTileControlItem(AParent).Frames;
end;

function TdxTileControlItemFrame.GetTileItem: TdxTileControlItem; 
begin
  Result := TdxTileControlItem(Collection.ParentComponent);
end;

{ TdxTileControlItemFrames }

function TdxTileControlItemFrames.Add: TdxTileControlItemFrame;
begin
  Result := TdxTileControlItemFrame(inherited Add);
end;

procedure TdxTileControlItemFrames.ForEach(
  AProc: TdxTileControlForEachItemFrameProc; const AData: Pointer);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    AProc(Items[I], AData);
end;

function TdxTileControlItemFrames.GetItem(AIndex: Integer): TdxTileControlItemFrame;
begin
  Result := TdxTileControlItemFrame(inherited Items[AIndex]);
end;

function TdxTileControlItemFrames.GetOwnerItem: TdxTileControlItem;
begin
  Result := TdxTileControlItem(ParentComponent);
end;

procedure TdxTileControlItemFrames.SetItem(
  AIndex: Integer; const AValue: TdxTileControlItemFrame);
begin
  GetItem(AIndex).Assign(AValue);
end;

{ TdxTileControlItemDetailOptions }

destructor TdxTileControlItemDetailOptions.Destroy;
begin
  DetailControl := nil;
  FreeAndNil(FDetailSite);
  inherited Destroy;
end;

procedure TdxTileControlItemDetailOptions.Assign(ASource: TPersistent);
begin
  if ASource is TdxTileControlItemDetailOptions then
  begin
    Caption := TdxTileControlItemDetailOptions(ASource).Caption;
    DetailControl := TdxTileControlItemDetailOptions(ASource).DetailControl;
  end;
end;

procedure TdxTileControlItemDetailOptions.Changed;
begin
  TileItem.TileControl.LayoutChanged;
end;

function TdxTileControlItemDetailOptions.IsChanged: Boolean;
begin
  Result := (Caption <> '') or (DetailControl <> nil)
end;

function TdxTileControlItemDetailOptions.GetHasDetail: Boolean;
begin
  Result := (DetailControl <> nil) or Assigned(TileItem.OnActivateDetail) or ShowTab;
end;

function TdxTileControlItemDetailOptions.GetDetailSite: TdxTileControlDetailSite;
begin
  if FDetailSite = nil then
    FDetailSite := TileItem.CreateDetailSite;
  Result := FDetailSite;
  if not FDetailSite.HandleAllocated then
  begin
    FDetailSite.Left := dxTileControlInvisiblePosition;
    FDetailSite.Parent := TileItem.TileControl;
  end;
end;

function TdxTileControlItemDetailOptions.GetTileControl: TdxCustomTileControl;
begin
  Result := TileItem.TileControl;
end;

function TdxTileControlItemDetailOptions.GetTileItem: TdxTileControlItem;
begin
  Result := TdxTileControlItem(GetOwner);
end;

procedure TdxTileControlItemDetailOptions.SetCaption(AValue: string);
begin
  if FCaption <> AValue then
  begin
    FCaption := AValue;
    Changed;
  end;
end;

procedure TdxTileControlItemDetailOptions.SetDetailControl(AValue: TWinControl);
begin
  if AValue = TileItem.TileControl then
    AValue := nil;
  if FDetailControl = AValue then Exit;
  if not TileControl.IsDesigning then
  begin
    if FDetailControl <> nil then
      GetDetailsInfo.RemoveInfo(FDetailControl, TileItem);
    FDetailControl := AValue;
    if FDetailControl <> nil then
    begin
      GetDetailsInfo.AddInfo(FDetailControl, TileItem);
      FDetailControl.Parent := DetailSite;
    end;
  end
  else
    FDetailControl := AValue;
end;

{ TdxTileControlItem }

constructor TdxTileControlItem.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FActiveTransitions := TcxObjectList.Create;
  FFrames := CreateFrames;
  FViewInfo := CreateViewInfo;
  FAnimationTimer := TcxTimer.Create(Self);
  FAnimationMode := dxTileControlDefaultAnimationMode;
  FRowCount := dxTileControlDefaultItemRowCount;
  FActiveFrameIndex := -1;
  AnimationInterval := dxTileControlDefaultAnimationInterval;
  FAnimationTimer.Enabled := False;
  FAnimationTimer.OnTimer := AnimationTimerHandler;
  FDetailOptions := CreateDetailOptions;
end;

destructor TdxTileControlItem.Destroy;
begin
  StopTransitions;
  Controller.ItemDestroyed(Self);
  Group := nil;
  FreeAndNil(FDetailOptions);
  FreeAndNil(FFrames);
  FreeAndNil(FAnimationTimer);
  FreeAndNil(FViewInfo);
  FreeAndNil(FActiveTransitions);
  inherited Destroy;
end;

procedure TdxTileControlItem.Assign(ASource: TPersistent);
begin
  inherited Assign(ASource);
  if ASource is TdxTileControlItem then
  begin
    AnimationInterval := TdxTileControlItem(ASource).AnimationInterval;
    AnimationMode := TdxTileControlItem(ASource).AnimationMode;
    DetailOptions := TdxTileControlItem(ASource).DetailOptions;
    IsLarge := TdxTileControlItem(ASource).IsLarge;
    GroupIndex := TdxTileControlItem(ASource).GroupIndex;
    IndexInGroup := TdxTileControlItem(ASource).IndexInGroup;
  end;
end;

procedure TdxTileControlItem.ActivateDetail;
begin
  DetailOptions.DetailSite.DoActivateDetail;
end;

procedure TdxTileControlItem.ActiveFrameChanged;
begin
  if ActiveFrame = nil then Exit;
  if not IsAnimationActive then
    ViewInfo.ViewData := CheckViewDataInitialized(ActiveFrame.ViewData)
  else
    Controller.AnimateItem(Self);
  DoActiveFrameChanged;
end;

procedure TdxTileControlItem.AddTransition(ATransition: TdxAnimationTransition);
begin
  ActiveTransitions.Add(ATransition);
end;

procedure TdxTileControlItem.AnimationTimerHandler(Sender: TObject);
begin
  if not IsAnimationActive or (VisibleFramesCount < 1) then Exit;
  FActiveFrameIndex := Max(-1, Min(VisibleFramesCount - 1, FActiveFrameIndex));
  if FActiveFrameIndex = VisibleFramesCount - 1 then
    ActiveFrameIndex := 0
  else
    ActiveFrameIndex := ActiveFrameIndex + 1;
end;

procedure TdxTileControlItem.Changed;
begin
  ViewInfo.Calculated := False;
  ViewInfo.IsDirty := True;
  ViewData.IsDirty := True;
  Frames.ForEach(RefreshFrame, nil);
  inherited Changed;
end;

procedure TdxTileControlItem.CheckTimerEnabled;
begin
  FAnimationTimer.Enabled := (AnimationInterval > 0) and (TileControl <> nil) and
    not TileControl.IsDesigning and
    (Controller.AnimationItems.IndexOf(Self) < 0) and not TileControl.IsLocked;
end;

function TdxTileControlItem.CheckViewDataInitialized(
  AViewData: TdxTileControlCustomItemViewData): TdxTileControlCustomItemViewData;
begin
  if (AViewData <> ViewData) and (AViewData <> nil) then
    DoFrameInitialize(TdxTileControlItemFrame(AViewData.Item));
  Result := AViewData; 
end; 

function TdxTileControlItem.CreateDetailOptions: TdxTileControlItemDetailOptions; 
begin
  Result := TdxTileControlItemDetailOptions.Create(Self);
end;

function TdxTileControlItem.CreateDetailSite: TdxTileControlDetailSite; 
begin
  Result := TdxTileControlDetailSite.Create(Self);
end;

function TdxTileControlItem.CreateFrames: TdxTileControlItemFrames;
begin
  Result := TdxTileControlItemFrames.Create(Self, TdxTileControlItemFrame);
end;

function TdxTileControlItem.CreateOptionsAnimate: TdxTileControlItemOptionsAnimate;
begin
  Result := TdxTileControlItemOptionsAnimate.Create(Self);
end;

function TdxTileControlItem.CreateViewInfo: TdxTileControlItemViewInfo;
begin
  Result := TdxTileControlItemViewInfo.Create(Self);
end;

procedure TdxTileControlItem.DoActivateDetail;
begin
  if Assigned(FOnActivateDetail) then
    FOnActivateDetail(Self);
end;

procedure TdxTileControlItem.DoActiveFrameChanged;
begin
  if Assigned(FOnActiveFrameChanged) then
    FOnActiveFrameChanged(Self);
end;

procedure TdxTileControlItem.DoClick;
begin
  if Assigned(FOnClick) then
    FOnClick(Self);
  if DetailOptions.HasDetail then
    ActivateDetail;
end;

procedure TdxTileControlItem.DoDeactivateDetail;
begin
  if Assigned(FOnDeactivateDetail) then
    FOnDeactivateDetail(Self);
end;

procedure TdxTileControlItem.DoFrameDestroy(AFrame: TdxTileControlItemFrame);
begin
  StopTransitions;
  if (ViewInfo <> nil) and (ViewInfo.ViewData = AFrame.ViewData) then
    ViewInfo.ViewData := nil;
  if Assigned(FOnFrameDestroy) then
    FOnFrameDestroy(AFrame);
end;

procedure TdxTileControlItem.DoFrameInitialize(AFrame: TdxTileControlItemFrame);
begin
  if Assigned(FOnFrameInitialize) then
    FOnFrameInitialize(AFrame);
end;

procedure TdxTileControlItem.FrameChanged(AFrame: TdxTileControlCustomItem);
begin
  if AFrame = ActiveFrame then
    Invalidate;
end;

function TdxTileControlItem.GetActualViewData: TdxTileControlCustomItemViewData;
begin
  Result := ViewData;
  if TileControl.IsDesigning or (ActiveFrame = nil) then Exit;
  FActiveFrameIndex := ActiveFrame.Index;
  Result := CheckViewDataInitialized(ActiveFrame.ViewData);
end;

function TdxTileControlItem.GetClientBounds: TRect;
begin
  Result := cxRectOffset(ViewInfo.Bounds, ViewInfo.Bounds.TopLeft, False);
end;

function TdxTileControlItem.GetCollectionFromParent(AParent: TComponent): TcxComponentCollection;
begin
  Result := TdxCustomTileControl(AParent).Items;
end;

function TdxTileControlItem.GetTileItem: TdxTileControlItem;
begin
  Result := Self;
end;

procedure TdxTileControlItem.Invalidate;
begin
  if ViewInfo.Visible then
    TileControl.InvalidateRect(cxRectInflate(ViewInfo.GetActualVisualBounds, 1, 1), False);
end;

function TdxTileControlItem.IsDragged: Boolean;
begin
  if (TileControl.DragAndDropState = ddsInProcess) and
    (TileControl.IsItemDragged or (TileControl.ViewInfo.DragDropChanges <> nil)) then
    Result := ViewInfo = TdxTileControlDragDropCustomObject(TileControl.DragAndDropObject).DragCell
  else
    Result := False;
end;

procedure TdxTileControlItem.Notification(AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (DetailOptions <> nil) and (Operation = opRemove) and (DetailOptions.DetailControl = AComponent) then
    DetailOptions.DetailControl := nil;
end;

procedure TdxTileControlItem.Refresh;
begin
  ViewInfo.IsDirty := True;
  Invalidate; 
end;

procedure TdxTileControlItem.RemoveTransition(ATransition: TdxAnimationTransition);
begin
  ActiveTransitions.Remove(ATransition);
end;

procedure TdxTileControlItem.Click;
begin
  Controller.FocusedItem := Self;
  DoClick;
end;

procedure TdxTileControlItem.DeactivateDetail;
begin
  DetailOptions.DetailSite.DoDeactivateDetail;
end;

procedure TdxTileControlItem.GetChildren(Proc: TGetChildProc; Root: TComponent);
var
  I: Integer;
begin
  inherited GetChildren(Proc, Root);
  for I := 0 to Frames.Count - 1 do
    if Frames[I].Owner = Root then
      Proc(Frames[I]);
end;

procedure TdxTileControlItem.MakeVisible;
begin
  if not Visible or TileControl.IsLocked then Exit;
  TileControl.ViewInfo.MakeVisible(ViewInfo.GetActualVisualBounds, IsMostLeft, IsMostRight);
  Invalidate;
end;

procedure TdxTileControlItem.Move(AGroupDest: TdxTileControlGroup; AIndexDest: Integer);
begin
  TileControl.BeginUpdate;
  try
    if Group <> AGroupDest then
    begin
      Group.RemoveItem(Self);
      AGroupDest.Add(Self);
    end;
    AGroupDest.MoveItem(Self, AIndexDest);
  finally
    TileControl.EndUpdate;
  end;
end;

function TdxTileControlItem.GetActiveFrame: TdxTileControlItemFrame;
var
  I, AIndex: Integer;
begin
  Result := nil;
  AIndex := Min(VisibleFramesCount - 1, Max(0, FActiveFrameIndex));
  if AIndex < 0 then Exit;
  for I := 0 to Frames.Count - 1 do
    if Frames[I].Visible then
    begin
      Result := Frames[I];
      Dec(AIndex);
      if AIndex < 0 then Break;
    end;
end;

function TdxTileControlItem.GetActuallyVisible: Boolean;
begin
  Result := FVisible and (Group <> nil) and Group.Visible;
end;

function TdxTileControlItem.GetController: TdxTileControlController;
begin
  if TileControl = nil then
    Result := nil
  else
    Result := TileControl.Controller;
end;

function TdxTileControlItem.GetGroupIndex: Integer;
begin
  Result := -1;
  if Group <> nil then
    Result := Group.Index;
end;

function TdxTileControlItem.GetGroupLayout: TdxTileControlGroupLayout;
begin
  Result := TileControl.OptionsView.GroupLayout;
end;

function TdxTileControlItem.GetIndexInGroup: Integer;
begin
  if TileControl.IsLoading then
    Result := FIndexInGroupAtLoaded
  else
  begin
    Result := -1;
    if Group <> nil then
      Result := Group.IndexOfItem(Self);
  end;
end;

function TdxTileControlItem.GetIsAnimationActive: Boolean;
begin
  Result := Controller.FramesAnimationLockCount = 0;
end;

function TdxTileControlItem.GetIsMostLeft: Boolean;
begin
  Result := (Group <> nil) and Group.IsMostLeft;
  if Result then
    if GroupLayout = glHorizontal then
      Result := Result and (ViewInfo.Position.Column = 0)
    else
      Result := Result and (ViewInfo.Position.Row = 0);
end;

function TdxTileControlItem.GetIsMostRight: Boolean;
begin
  Result := (Group <> nil) and Group.IsMostRight;
  if Result then
    if GroupLayout = glHorizontal then
      Result := Result and (ViewInfo.Position.Column + Ord(IsLarge) = Group.RealColumnCount - 1)
    else
      Result := Result and (ViewInfo.Position.Row + Self.RowCount - 1 = Group.RealRowCount - 1);
end;

function TdxTileControlItem.GetTileControl: TdxCustomTileControl;
begin
  if Collection = nil then
    Result := nil
  else
    Result := TdxCustomTileControl(Collection.ParentComponent);
end;

function TdxTileControlItem.GetVisibleFramesCount: Integer;
var
  I: Integer;
begin
  Result := 0;
  if Frames = nil then Exit; 
  for I := 0 to Frames.Count - 1 do
    if Frames[I].Visible then
      Inc(Result);
end;

function TdxTileControlItem.IsDetailOptionsStored: Boolean;
begin
  Result := DetailOptions.IsChanged; 
end;

procedure TdxTileControlItem.RemoveFromGroup;
begin
  if Group <> nil then
    Group.RemoveItem(Self);
end;

procedure TdxTileControlItem.RefreshFrame(AItem: TdxTileControlItemFrame; const AData: Pointer);
begin
  AItem.Changed;
end;

procedure TdxTileControlItem.SetActiveFrame(AValue: TdxTileControlItemFrame);
begin
  if AValue <> nil then
    ActiveFrameIndex := AValue.Index
  else
    ActiveFrameIndex := -1;
end;

procedure TdxTileControlItem.SetActiveFrameIndex(AValue: Integer);
begin
  AValue := Max(-1, Min(VisibleFramesCount - 1, AValue));
  if AValue <> FActiveFrameIndex then
    FActiveFrameIndex := AValue;
  ActiveFrameChanged;
end;

procedure TdxTileControlItem.SetAnimationInterval(AValue: Integer);
begin
  AnimationTimer.Enabled := False;
  FAnimationInterval := AValue;
  AnimationTimer.Interval := AValue;
  CheckTimerEnabled;
end;

procedure TdxTileControlItem.SetChecked(AValue: Boolean);
begin
  if Controller.ItemCheckMode = tcicmNone then
    AValue := False;
  if FChecked <> AValue then
  begin
    if TileControl.DoItemBeforeCheck(Self) then
    begin
      FChecked := AValue;
      Controller.ItemChecked(Self);
    end;
  end;
end;

procedure TdxTileControlItem.SetDetailOptions(AValue: TdxTileControlItemDetailOptions);
begin
  DetailOptions.Assign(AValue);
end; 

procedure TdxTileControlItem.SetFrames(AValue: TdxTileControlItemFrames);
begin
  Frames.Assign(AValue);
end;

procedure TdxTileControlItem.SetGroup(AValue: TdxTileControlGroup);
begin
  if FGroup <> AValue then
  begin
    TileControl.BeginUpdate;
    try
      if Group <> nil then
        Group.RemoveItem(Self);
      if AValue <> nil then
        AValue.Add(Self);
    finally
      TileControl.EndUpdate;
    end;
  end;
end;

procedure TdxTileControlItem.SetGroupIndex(AValue: Integer);
begin
  AValue := Min(Max(-1, AValue), TileControl.Groups.Count - 1);
  if AValue < 0 then
    SetGroup(nil)
  else
    SetGroup(TileControl.Groups[AValue]);
end;

procedure TdxTileControlItem.SetIndexInGroup(AValue: Integer);
begin
  if TileControl.IsLoading then
    FIndexInGroupAtLoaded := AValue
  else
    if Group <> nil then
    begin
      AValue := Min(Max(AValue, 0), Group.ItemCount - 1);
      if IndexInGroup <> AValue then
      begin
        TileControl.BeginUpdate;
        try
          Move(Group, AValue);
        finally
          TileControl.EndUpdate;
        end;
      end;
    end;
end;

procedure TdxTileControlItem.SetIsLarge(AValue: Boolean);
begin
  if FIsLarge <> AValue then
  begin
    FIsLarge := AValue;
    TileControl.LayoutChanged;
    Changed;
  end;
end;

procedure TdxTileControlItem.SetRowCount(AValue: Integer);
begin
  AValue := Min(Max(AValue, 1), dxTileControlItemMaxRowCount);
  if FRowCount <> AValue then
  begin
    FRowCount := AValue;
    TileControl.LayoutChanged;
    Changed;
  end;
end;

procedure TdxTileControlItem.SetName(const NewName: TComponentName);
begin
  inherited SetName(NewName);
  if TileControl.IsDesigning then
    Changed;
end;

procedure TdxTileControlItem.StopTransitions;
var
  I: Integer;
begin
  for I := ActiveTransitions.Count - 1 downto 0 do
    TdxAnimationTransition(FActiveTransitions[I]).Terminate;
  ActiveTransitions.Clear;
end;

procedure TdxTileControlItem.ToggleChecked;
begin
  Checked := not Checked;
end;

procedure TdxTileControlItem.SetOnActivateDetail(AValue: TdxTileControlItemEvent);
begin
  FOnActivateDetail := AValue;
  if Assigned(AValue) then
    DetailOptions.ShowTab := True;
end;

// IcxStoredObject

function TdxTileControlItem.GetObjectName: string;
begin
  if TileControl.StoringName = '' then
  begin
    Result := Name;
    if Result = '' then
      Result := ClassName + IntToStr(IndexInGroup);
  end
  else
    Result := 'Item' + IntToStr(IndexInGroup);
end;

function TdxTileControlItem.GetProperties(AProperties: TStrings): Boolean;
var
  I: Integer;
begin
  for I := Low(dxTileControlStoredItemPropertiesNames) to High(dxTileControlStoredItemPropertiesNames) do
    AProperties.Add(dxTileControlStoredItemPropertiesNames[I]);
  if Assigned(OnGetStoredProperties) then
    OnGetStoredProperties(Self, AProperties);
  Result := True;
end;

function TdxTileControlItem.GetPropertyIndex(const AName: string): Integer;
var
  I: Integer;
begin
  Result := -1;
  for I := Low(dxTileControlStoredItemPropertiesNames) to High(dxTileControlStoredItemPropertiesNames) do
  begin
    if AnsiCompareText(dxTileControlStoredItemPropertiesNames[I], AName) = 0 then
    begin
      Result := I;
      Break;
    end;
  end;
end;

procedure TdxTileControlItem.GetPropertyValue(const AName: string; var AValue: Variant);
begin
  if Assigned(OnGetStoredPropertyValue) then
    OnGetStoredPropertyValue(Self, AName, AValue);
end;

procedure TdxTileControlItem.SetPropertyValue(const AName: string; const AValue: Variant);
var
  AGroup: TdxTileControlGroup;
begin
  if AName = 'IndexGroup' then
  begin
    AGroup := TileControl.FindGroup(AValue);
    if AGroup <> nil then
      GroupIndex := AGroup.Index;
  end
  else
    if Assigned(OnSetStoredPropertyValue) then
      OnSetStoredPropertyValue(Self, AName, AValue);
end;

{ TdxTileControlCustomStoredCollection }

function TdxTileControlCustomStoredCollection.GetItemPrefixName: string;
begin
  Result := 'TdxTileControl';
end;

function TdxTileControlCustomStoredCollection.GetTileControl: TdxCustomTileControl;
begin
  Result := TdxCustomTileControl(ParentComponent);
end;

// IInterface
function TdxTileControlCustomStoredCollection.QueryInterface(const IID: TGUID; out Obj): HResult;
begin
  if GetInterface(IID, Obj) then
    Result := 0
  else
    Result := cxE_NOINTERFACE;
end;

function TdxTileControlCustomStoredCollection._AddRef: Integer;
begin
  Result := -1;
end;

function TdxTileControlCustomStoredCollection._Release: Integer;
begin
  Result := -1;
end;

// IcxStoredObject }

function TdxTileControlCustomStoredCollection.GetObjectName: string;
begin
  Result := '';
end;

function TdxTileControlCustomStoredCollection.GetProperties(
  AProperties: TStrings): Boolean;
begin
  Result := True;
end;

procedure TdxTileControlCustomStoredCollection.GetPropertyValue
  (const AName: string; var AValue: Variant);
begin
end;

procedure TdxTileControlCustomStoredCollection.SetPropertyValue
  (const AName: string; const AValue: Variant);
begin
end;

// IcxStoredParent
function TdxTileControlCustomStoredCollection.StoredCreateChild
  (const AObjectName, AClassName: string): TObject;
begin
  Result := nil;
end;

procedure TdxTileControlCustomStoredCollection.StoredDeleteChild
  (const AObjectName: string; AObject: TObject);
begin
  Remove(TcxComponentCollectionItem(AObject));
end;

procedure TdxTileControlCustomStoredCollection.StoredChildren(AChildren: TStringList);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    AChildren.AddObject('', Items[I]);
end;

{ TdxTileControlItemCollection }

function TdxTileControlItemCollection.Add: TdxTileControlItem;
begin
  Result := TdxTileControlItem(inherited Add);
end;

procedure TdxTileControlItemCollection.ForEach(AProc: TdxTileControlForEachItemProc;
  const AData: Pointer; AVisibleOnly: Boolean = True);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    if Items[I].ActuallyVisible or not AVisibleOnly then
      AProc(Items[I], AData);
end;

function TdxTileControlItemCollection.GetItem(AIndex: Integer): TdxTileControlItem;
begin
  Result := TdxTileControlItem( inherited GetItem(AIndex));
end;

procedure TdxTileControlItemCollection.SetItem(AIndex: Integer; const AValue: TdxTileControlItem);
begin
  inherited SetItem(AIndex, AValue);
end;

// IcxStoredObject }
function TdxTileControlItemCollection.GetObjectName: string;
begin
  Result := 'Items';
end;

// IcxStoredParent implementation
function TdxTileControlItemCollection.StoredCreateChild(const AObjectName,
  AClassName: string): TObject;
var
  AItem: TdxTileControlItem;
begin
  if AClassName = 'TdxTileControlItem' then
  begin
    AItem := TdxCustomTileControl(ParentComponent).Items.Add;
    AItem.Group := nil;
    Result := AItem;
    TileControl.DoInitStoredObject(Result);
  end
  else
    Result := inherited StoredCreateChild(AObjectName, AClassName);
end;

procedure TdxTileControlItemCollection.StoredChildren(AChildren: TStringList);
var
  I: Integer;
begin
  if TileControl.StoredVersion > 0 then
    inherited StoredChildren(AChildren)
  else
    for I := 0 to Count - 1 do
      if Items[I].Group = nil then
        AChildren.AddObject('', Items[I]);
end;

{ TdxTileControlGroup }

constructor TdxTileControlGroup.Create(AOwner: TComponent);
begin
  if AOwner is TdxCustomTileControl then
  begin
    inherited Create(nil);
    FTileControl := AOwner as TdxCustomTileControl;
  end
  else
    inherited Create(AOwner);
  FViewInfo := TdxTileControlGroupViewInfo.Create(Self);
  FVirtualGroupBefore := TdxTileControlVirtualGroupViewInfo.Create(Self);
  FVirtualGroupAfter := TdxTileControlVirtualGroupViewInfo.Create(Self);
  FItems := TcxObjectList.Create(False);
  FCaption := TdxTileControlGroupCaption.Create(Self);
  FVisible := True;
end;

destructor TdxTileControlGroup.Destroy;
begin
  RemoveItems;
  FreeAndNil(FCaption);
  FreeAndNil(FItems);
  FreeAndNil(FVirtualGroupAfter);
  FreeAndNil(FVirtualGroupBefore);
  FreeAndNil(FViewInfo);
  inherited Destroy;
end;

procedure TdxTileControlGroup.Add(AItem: TdxTileControlItem);
begin
  if AItem.Group = Self then Exit;
  FItems.Add(AItem);
  AItem.FGroup := Self;
  GroupChanged;
end;

procedure TdxTileControlGroup.AssignFrom(AGroup: TdxTileControlGroup; AExcludeItem: TdxTileControlItem = nil);
var
  I: Integer;
begin
  ViewInfo.FBounds := AGroup.ViewInfo.FBounds;
  ViewInfo.FMaximizedAreaBounds := AGroup.ViewInfo.FMaximizedAreaBounds;
  ViewInfo.FExpandedBounds := AGroup.ViewInfo.FExpandedBounds;
  ViewInfo.FColumnCount := AGroup.ViewInfo.FColumnCount;
  ViewInfo.FRowCount := AGroup.ViewInfo.FRowCount;
  FItems.Clear;
  for I := 0 to AGroup.ItemCount - 1 do
    if AGroup.Items[I] <> AExcludeItem then
      FItems.Add(AGroup.Items[I]);
end;

function TdxTileControlGroup.IndexOfItem(AItem: TdxTileControlItem): Integer;
begin
  Result := FItems.IndexOf(AItem);
end;

procedure TdxTileControlGroup.DeleteItem(AItem: TdxTileControlItem);
var
  AIndex: Integer;
begin
  AIndex := IndexOfItem(AItem);
  if AIndex >= 0 then
  begin
    FItems.Items[AIndex].Free;
    GroupChanged;
  end;
end;

procedure TdxTileControlGroup.DeleteItems;
var
  I: Integer;
begin
  for I := FItems.Count - 1 downto 0 do
    FItems.Items[I].Free;
end;

procedure TdxTileControlGroup.RemoveItem(AItem: TdxTileControlItem);
begin
  if Self = nil then Exit;
  TileControl.BeginUpdate;
  try
    if FItems.Remove(AItem) >= 0 then
    begin
      AItem.FGroup := nil;
        GroupChanged;
    end;
  finally
    TileControl.EndUpdate;
  end;
end;

procedure TdxTileControlGroup.RemoveItems;
var
  I: Integer;
begin
  if Owner = nil then
    for I := FItems.Count - 1 downto 0 do
      FItems.Remove(FItems[I])
  else
  begin
    TileControl.BeginUpdate;
    try
      for I := FItems.Count - 1 downto 0 do
        RemoveItem(FItems.Items[I] as TdxTileControlItem);
      GroupChanged;
    finally
      TileControl.EndUpdate;
    end;
  end;
end;

procedure TdxTileControlGroup.GroupChanged;
begin
  FViewInfo.Calculated := False;
  Changed(True);
end;

procedure TdxTileControlGroup.MakeVisible;
begin
  if not Visible or TileControl.IsLocked then Exit;
  TileControl.ViewInfo.MakeVisible(ViewInfo.Bounds, IsMostLeft, IsMostRight);
  Invalidate;
end;

procedure TdxTileControlGroup.MoveItem(AItem: TdxTileControlItem; AIndexDest: Integer);
var
  ANowIndex: Integer;
begin
  ANowIndex := IndexOfItem(AItem);
  if AIndexDest > ItemCount - 1 then
    AIndexDest := ItemCount - 1;
  if ANowIndex <> AIndexDest then
    FItems.Move(ANowIndex, AIndexDest);
end;

function TdxTileControlGroup.GetCollectionFromParent(AParent: TComponent): TcxComponentCollection;
begin
  Result := TdxCustomTileControl(AParent).Groups;
end;

procedure TdxTileControlGroup.Invalidate;
begin
  if FViewInfo.Visible then
    TileControl.InvalidateRect(FViewInfo.Bounds, False);
end;

function TdxTileControlGroup.GetBounds: TRect;
begin
  Result := ViewInfo.Bounds;
end;

function TdxTileControlGroup.GetExpandedBounds: TRect;
begin
  Result := ViewInfo.ExpandedBounds;
end;

function TdxTileControlGroup.GetGroupLayout: TdxTileControlGroupLayout;
begin
  Result := TileControl.OptionsView.GroupLayout;
end;

function TdxTileControlGroup.GetGroups: TdxTileControlGroupCollection;
begin
  Result := TdxTileControlGroupCollection(Collection);
end;

function TdxTileControlGroup.GetItem(AIndex: Integer): TdxTileControlItem;
begin
  Result := TdxTileControlItem(FItems[AIndex]);
end;

function TdxTileControlGroup.GetItemCount: Integer;
begin
  Result := FItems.Count;
end;

function TdxTileControlGroup.GetIsMostLeft: Boolean;
begin
  Result := Groups.GetPrevVisibleGroup(Self) = nil;
end;

function TdxTileControlGroup.GetIsMostRight: Boolean;
begin
  Result := Groups.GetNextVisibleGroup(Self) = nil;
end;

function TdxTileControlGroup.GetMaximizedAreaBounds: TRect;
begin
  Result := ViewInfo.MaximizedAreaBounds;
end;

function TdxTileControlGroup.GetRealColumnCount: Integer;
begin
  Result := ViewInfo.ColumnCount;
end;

function TdxTileControlGroup.GetRealRowCount: Integer;
begin
  Result := ViewInfo.RowCount;
end;

function TdxTileControlGroup.IsCaptionStored: Boolean;
begin
  Result := FCaption.IsChanged;
end;

function TdxTileControlGroup.IsDragged: Boolean;
begin
  if TileControl.IsGroupDragged then
    Result := ViewInfo = TdxTileControlDragDropCustomObject(TileControl.DragAndDropObject).DragCell
  else
    Result := False;
end;

procedure TdxTileControlGroup.SetCollection(AValue: TcxComponentCollection);
begin
  if AValue <> nil then
    FTileControl := TdxTileControlGroupCollection(AValue).TileControl;
  inherited SetCollection(AValue);
  UpdateTileControlLink;
end;

procedure TdxTileControlGroup.SetIndex(AValue: Integer);
begin
  AValue := Min(Max(AValue, 0), Collection.Count - 1);
  if Index <> AValue then
    if GroupLayout = glHorizontal then
      SetIndexForHorzLayout(AValue)
    else
      SetIndexForVertLayout(AValue);
end;

procedure TdxTileControlGroup.SetIndexForHorzLayout(AValue: Integer);
var
  ALeftOfFirstGroup: Integer;
  ANewFirstGroup: TdxTileControlGroupViewInfo;
begin
  ALeftOfFirstGroup := 0;
  if ((Index = 0) or (AValue = 0)) and (Collection.Items[0] <> nil) then
    ALeftOfFirstGroup := TdxTileControlGroup(Collection.Items[0]).ViewInfo.Bounds.Left;
  TileControl.BeginUpdate;
  try
    inherited SetIndex(AValue);
    if ALeftOfFirstGroup <> 0 then
    begin
      ANewFirstGroup := TdxTileControlGroup(Collection.Items[0]).ViewInfo;
      ANewFirstGroup.Scroll(ALeftOfFirstGroup - ANewFirstGroup.Bounds.Left, 0);
    end;
  finally
    TileControl.EndUpdate;
  end;
end;

procedure TdxTileControlGroup.SetIndexForVertLayout(AValue: Integer);
var
  ATopOfFirstGroup: Integer;
  ANewFirstGroup: TdxTileControlGroupViewInfo;
begin
  ATopOfFirstGroup := 0;
  if ((Index = 0) or (AValue = 0)) and (Collection.Items[0] <> nil) then
    ATopOfFirstGroup := TdxTileControlGroup(Collection.Items[0]).ViewInfo.Bounds.Top;
  TileControl.BeginUpdate;
  try
    inherited SetIndex(AValue);
    if ATopOfFirstGroup <> 0 then
    begin
      ANewFirstGroup := TdxTileControlGroup(Collection.Items[0]).ViewInfo;
      ANewFirstGroup.Scroll(0, ATopOfFirstGroup - ANewFirstGroup.Bounds.Top);
    end;
  finally
    TileControl.EndUpdate;
  end;
end;

procedure TdxTileControlGroup.UpdateTileControlLink;
begin
  if Groups <> nil then
    FTileControl := Groups.TileControl;
end;

procedure TdxTileControlGroup.SetCaption(AValue: TdxTileControlGroupCaption);
begin
  FCaption.Assign(AValue);
end;

procedure TdxTileControlGroup.SetVisible(AValue: Boolean);
begin
  if FVisible <> AValue then
  begin
    FVisible := AValue;
    GroupChanged;
  end;
end;

// IcxStoredObject

function TdxTileControlGroup.GetObjectName: string;
begin
  if TileControl.StoringName = '' then
  begin
    Result := Name;
    if Result = '' then
      Result := ClassName + IntToStr(ID);
  end
  else
    Result := 'Group' + IntToStr(ID);
end;

function TdxTileControlGroup.GetProperties(AProperties: TStrings): Boolean;
var
  I: Integer;
begin
  for I := Low(dxTileControlStoredGroupPropertiesNames) to High(dxTileControlStoredGroupPropertiesNames) do
    AProperties.Add(dxTileControlStoredGroupPropertiesNames[I]);
  if Assigned(OnGetStoredProperties) then
    OnGetStoredProperties(Self, AProperties);
  Result := True;
end;

procedure TdxTileControlGroup.GetPropertyValue(const AName: string; var AValue: Variant);
begin
  if Assigned(OnGetStoredPropertyValue) then
    OnGetStoredPropertyValue(Self, AName, AValue);
end;

procedure TdxTileControlGroup.SetPropertyValue(const AName: string; const AValue: Variant);
begin
  if Assigned(OnSetStoredPropertyValue) then
    OnSetStoredPropertyValue(Self, AName, AValue);
end;

// IcxStoredParent
function TdxTileControlGroup.StoredCreateChild(const AObjectName, AClassName: string): TObject;
var
  AItem: TdxTileControlItem;
begin
  if AClassName = 'TdxTileControlItem' then  
  begin
    AItem := TileControl.Items.Add;
    FItems.Add(AItem);
    AItem.FGroup := Self;
    Result := AItem;
    TileControl.DoInitStoredObject(Result);
  end
  else
    Result := nil;
end;

procedure TdxTileControlGroup.StoredDeleteChild(const AObjectName: string; AObject: TObject);
begin
  DeleteItem(TdxTileControlItem(AObject));  
end;

procedure TdxTileControlGroup.StoredChildren(AChildren: TStringList);
var
  I: Integer;
begin
  if TileControl.StoredVersion = 0 then
    for I := 0 to TileControl.Items.Count - 1 do
      if TileControl.IsRestoring or (TileControl.Items[I].Group = Self) then
        AChildren.AddObject('', TileControl.Items[I])
end;

{ TdxTileControlGroupCaptionViewInfo }

constructor TdxTileControlGroupCaptionViewInfo.Create(AOwner: TdxTileControlGroupCaption);
begin
  inherited Create;
  FCaption := AOwner;
  FFont := TFont.Create;
end;

destructor TdxTileControlGroupCaptionViewInfo.Destroy;
begin
  FreeAndNil(FFont);
  inherited Destroy;
end;

procedure TdxTileControlGroupCaptionViewInfo.CalculateBounds;
begin
  Bounds := cxRectInflate(Group.Bounds, -1, -1);
  FBounds.Bottom := Bounds.Top + Height;
  if Height = 0 then Exit;
  FTextBounds := GetTextBounds(Bounds);
end;

procedure TdxTileControlGroupCaptionViewInfo.DoCalculate;
begin
  CalculateBounds;
  CalculateClipping;
end;

procedure TdxTileControlGroupCaptionViewInfo.DoDraw(ACanvas: TcxCanvas);
begin
  if not Group.Visible or (Group = TileControl.DraggedGroup) or IsAnimatedOnDragDrop then Exit;
  DrawContent(ACanvas, FTextBounds);
end;

procedure TdxTileControlGroupCaptionViewInfo.DrawContent(ACanvas: TcxCanvas; const ADrawRect: TRect);
var
  ABounds: TRect;
begin
  ABounds := ADrawRect;
  if Caption.Color <> clDefault then
    ACanvas.FillRect(ABounds, Caption.Color);
  if Caption.Text <> '' then
    cxTextOut(ACanvas.Canvas, Caption.Text, ABounds,
      GetTextOutFlags, 0, 0, Font, clNone, clNone, 0, 0, 0, TextColor);
end;

function TdxTileControlGroupCaptionViewInfo.GetGroup: TdxTileControlGroup;
begin
  Result := Caption.Group;
end;

function TdxTileControlGroupCaptionViewInfo.GetHeight: Integer;
begin
  Result := FHeight;
end;

function TdxTileControlGroupCaptionViewInfo.GetBaseDrawBounds: TRect;
begin
  Result := GetTextBounds(inherited GetBaseDrawBounds);
end;

function TdxTileControlGroupCaptionViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
    AHitTest.BitState[tchtGroupCaption] := True;
end;

function TdxTileControlGroupCaptionViewInfo.GetPainter: TdxTileControlPainter;
begin
  Result := TileControl.Painter;
end;

function TdxTileControlGroupCaptionViewInfo.GetTextBounds(ABounds: TRect): TRect;
begin
  Result := ABounds;
  Result.Bottom := Result.Bottom - FIndent;
end;

function TdxTileControlGroupCaptionViewInfo.GetTextColor: TColor;
begin
  Result := cxGetActualColor(Font.Color, Painter.GroupCaptionDefaultTextColor);
end;

function TdxTileControlGroupCaptionViewInfo.GetTextOutFlags: Integer;
const
  AHorzAlign: array[TAlignment] of TcxTextAlignX =
    (taLeft, taRight, taCenterX);
begin
  Result := cxMakeFormat(AHorzAlign[Caption.Alignment], taBottom) or CXTO_PREVENT_TOP_EXCEED;
end;

function TdxTileControlGroupCaptionViewInfo.GetTileControl: TdxCustomTileControl;
begin
  Result := Caption.TileControl;
end;

function TdxTileControlGroupCaptionViewInfo.GetVisibleBounds: TRect;
begin
  Result := TileControl.ViewInfo.TilesArea;
end;

procedure TdxTileControlGroupCaptionViewInfo.MeasureHeight;
var
  ATextHeight: Integer;
begin
  FIndent := TileControl.OptionsView.ItemIndent;
  TileControl.Painter.ValidatePainterData;
  Font.Assign(Caption.Font);
  if Font.Size = dxTileControlDefaultGroupCaptionFontSize then
    Font.Size := Painter.GroupCaptionDefaultFontSize;
  ATextHeight := cxTextHeight(Font, Caption.Text);
  if ATextHeight > 0 then
    Height := FIndent + cxTextHeight(Font, Caption.Text)
  else
    FHeight := 0;
end;

procedure TdxTileControlGroupCaptionViewInfo.Offset(const DX, DY: Integer);
begin
  Scroll(DX, DY);
end;

procedure TdxTileControlGroupCaptionViewInfo.Scroll(const DX, DY: Integer);
begin
  FTextBounds := cxRectOffset(FTextBounds, DX, DY);
  inherited Scroll(DX, DY);
end;

procedure TdxTileControlGroupCaptionViewInfo.SetHeight(AValue: Integer);
begin
  FHeight := Max(FHeight, AValue);
end;

{ TdxTileControlGroupCaption }

constructor TdxTileControlGroupCaption.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FGroup := TdxTileControlGroup(AOwner);
  FAlignment := taLeftJustify;
  FColor := clDefault;
  FFont := TFont.Create;
  FFont.Color := clDefault;
  FFont.Name := DefaultFontName;
  FFont.Size := dxTileControlDefaultGroupCaptionFontSize;
  FFont.OnChange := FontChanged;
  FViewInfo := TdxTileControlGroupCaptionViewInfo.Create(Self);
end;

destructor TdxTileControlGroupCaption.Destroy;
begin
  FreeAndNil(FFont);
  FreeAndNil(FViewInfo);
  inherited Destroy;
end;

procedure TdxTileControlGroupCaption.Assign(ASource: TPersistent);
var
  ACaption: TdxTileControlGroupCaption;
begin
  if ASource is TdxTileControlGroupCaption then
  begin
    ACaption := TdxTileControlGroupCaption(ASource);
    FAlignment := ACaption.Alignment;
    Font := ACaption.Font;
    FText := ACaption.Text;
  end
  else
    inherited Assign(ASource);
end;

procedure TdxTileControlGroupCaption.Changed;
begin
  TileControl.LayoutChanged;
end;

procedure TdxTileControlGroupCaption.FontChanged(Sender: TObject);
begin
  FFontChanged := True;
  Changed;
end;

function TdxTileControlGroupCaption.GetBounds: TRect;
begin
  Result := ViewInfo.Bounds;
end;

function TdxTileControlGroupCaption.GetHeight: Integer;
begin
  Result := ViewInfo.Height;
end;

function TdxTileControlGroupCaption.GetTileControl: TdxCustomTileControl;
begin
  Result := FGroup.TileControl;
end;

function TdxTileControlGroupCaption.IsChanged: Boolean;
begin
  Result := IsFontStored or (Alignment <> taLeftJustify) or (Text <> '') or (Color <> clDefault);
end;

function TdxTileControlGroupCaption.IsFontStored: Boolean;
begin
  Result := FFontChanged;
end;

procedure TdxTileControlGroupCaption.MeasureHeight;
begin
  ViewInfo.MeasureHeight;
end;

procedure TdxTileControlGroupCaption.SetAlignment(AValue: TAlignment);
begin
  if AValue <> FAlignment then
  begin
    FAlignment := AValue;
    Changed;
  end;
end;

procedure TdxTileControlGroupCaption.SetColor(AValue: TColor);
begin
  if AValue <> FColor then
  begin
    FColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlGroupCaption.SetFont(AValue: TFont);
begin
  FFont.Assign(AValue)
end;

procedure TdxTileControlGroupCaption.SetHeight(AHeight: Integer);
begin
  ViewInfo.Height := AHeight;
end;

procedure TdxTileControlGroupCaption.SetText(AValue: string);
begin
  if AValue <> FText then
  begin
    FText := AValue;
    Changed;
  end;
end;

{ TdxTileControlGroupCollection }

function TdxTileControlGroupCollection.Add: TdxTileControlGroup;
begin
  Result := TdxTileControlGroup(inherited Add);
end;

function TdxTileControlGroupCollection.GetPrevVisibleGroup(AGroup: TdxTileControlGroup): TdxTileControlGroup;
var
  I: Integer;
begin
  Result := nil;
  for I := AGroup.Index - 1 downto 0 do
    if Items[I].Visible then
    begin
      Result := Items[I];
      Break;
    end;
end;

function TdxTileControlGroupCollection.GetNextVisibleGroup(AGroup: TdxTileControlGroup): TdxTileControlGroup;
var
  I: Integer;
begin
  Result := nil;
  for I := AGroup.Index + 1 to Count - 1 do
    if Items[I].Visible then
    begin
      Result := Items[I];
      Break;
    end;
end;

function TdxTileControlGroupCollection.Insert(AIndex: Integer): TdxTileControlGroup;
begin
  Result := TdxTileControlGroup(inherited Insert(AIndex));
end;

function TdxTileControlGroupCollection.GetItem(AIndex: Integer): TdxTileControlGroup;
begin
  Result := TdxTileControlGroup(inherited GetItem(AIndex));
end;

function dxCompareItemsByIndexInGroup(AItem1, AItem2: TdxTileControlItem): Integer;
begin
  Result := AItem1.FIndexInGroupAtLoaded - AItem2.FIndexInGroupAtLoaded;
end;

procedure TdxTileControlGroupCollection.Loaded;
var
  I: Integer;
begin
  // sort and reindex after loaded
  for I := 0 to Count - 1 do
    with Items[I] do
      FItems.Sort(@dxCompareItemsByIndexInGroup);
end;

procedure TdxTileControlGroupCollection.SetItem(AIndex: Integer;
  const AValue: TdxTileControlGroup);
begin
  inherited SetItem(AIndex, AValue);
end;

procedure TdxTileControlGroupCollection.Update(AItem: TcxComponentCollectionItem;
  AAction: TcxComponentCollectionNotification);
begin
  inherited Update(AItem, AAction);
  TileControl.AddChanges([tccLayout]);
end;

// IcxStoredObject }

function TdxTileControlGroupCollection.GetObjectName: string;
begin
  Result := 'Groups';
end;

// IcxStoredParent
function TdxTileControlGroupCollection.StoredCreateChild(const AObjectName,
  AClassName: string): TObject;
begin
  if AClassName = 'TdxTileControlGroup' then
  begin
    Result := Add;
    TileControl.DoInitStoredObject(Result);
  end
  else
    Result := inherited StoredCreateChild(AObjectName, AClassName);
end;

procedure TdxTileControlGroupCollection.StoredDeleteChild(const AObjectName: string;
  AObject: TObject);
begin
  AObject.Free;
end;

{ TdxTileControlStyle }

constructor TdxTileControlStyle.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FFocusedColor := clDefault;
  FCheckedItemCheckMarkColor := clDefault;
  FCheckedItemFrameColor := clDefault;
end;

procedure TdxTileControlStyle.Assign(ASource: TPersistent);
begin
  if ASource is TdxTileControlStyle then
  begin
    FocusedColor := TdxTileControlStyle(ASource).FocusedColor;
    CheckedItemCheckMarkColor := TdxTileControlStyle(ASource).CheckedItemCheckMarkColor;
    CheckedItemFrameColor := TdxTileControlStyle(ASource).CheckedItemFrameColor;
  end;
  inherited Assign(ASource);
end;

procedure TdxTileControlStyle.SetCheckedItemCheckMarkColor(AValue: TColor);
begin
  if AValue <> FCheckedItemCheckMarkColor then
  begin
    FCheckedItemCheckMarkColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlStyle.SetCheckedItemFrameColor(AValue: TColor);
begin
  if AValue <> FCheckedItemFrameColor then
  begin
    FCheckedItemFrameColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlStyle.SetFocusedColor(AValue: TColor);
begin
  if FFocusedColor <> AValue then
  begin
    FFocusedColor := AValue;
    Changed;
  end;
end;

{ TdxTileControlCustomDesignHelper }

constructor TdxTileControlCustomDesignHelper.Create(
  AControl: TdxCustomTileControl);
begin
  inherited Create;
end;

function TdxTileControlCustomDesignHelper.GetControl: TdxCustomTileControl;
begin
  Result := nil;
end;

{ TdxTileControlHintController }

constructor TdxTileControlHintController.Create(AOwner: TdxTileControlController);
begin
  FOwner := AOwner;
end;

function TdxTileControlHintController.GetTileControl: TdxCustomTileControl;
begin
  Result := FOwner.TileControl;
end;

{ TdxTileControlInflateItemAnimation }

constructor TdxTileControlInflateItemAnimation.Create(ATileControl: TdxCustomTileControl; AItem: TdxTileControlItem;
  const ADelta, ACount: Integer);
begin
  inherited Create(dxTileControlInflateAnimationTime, ateLinear, ACount);
  FTileControl := ATileControl;
  FItem := AItem;
  FDelta := ADelta;
  if Item <> nil then
    Item.AddTransition(Self);
end;

destructor TdxTileControlInflateItemAnimation.Destroy;
begin
  if Item <> nil then
    Item.RemoveTransition(Self);
  inherited Destroy;
end;

procedure TdxTileControlInflateItemAnimation.InflateItem(AItem: TdxTileControlItem;
  const AData: Pointer);
begin
  AItem.ViewInfo.InflateDelta := Integer(AData);
end;

procedure TdxTileControlInflateItemAnimation.DoAnimate;
begin
  if Item = nil then
    TileControl.Items.ForEach(InflateItem, Pointer(Position * FDelta))
  else
    InflateItem(Item, Pointer(Position * FDelta));
  TileControl.Update;
end;

{ TdxTileControlFramesAnimation }

constructor TdxTileControlFramesAnimation.Create(AItem: TdxTileControlItem);
begin
  FItem := AItem;
  InitializeViewData;
  inherited Create(SourceViewData.Image, DestViewData.Image,
    dxTileControlFramesAnimationTime, Item.AnimationMode, ateAccelerateDecelerate);
  Item.ViewInfo.ViewData := DestViewData;
  Item.ViewInfo.FAnimation := Self;
  Item.AddTransition(Self);
end;

destructor TdxTileControlFramesAnimation.Destroy;
begin
  Item.ViewInfo.FAnimation := nil;
  Item.ViewInfo.ViewData.NeedDrawTextOnImage := True;
  Item.Controller.AnimationItems.Remove(Item);
  Item.CheckTimerEnabled;
  Item.RemoveTransition(Self);
  inherited Destroy;
end;

procedure TdxTileControlFramesAnimation.InitializeViewData;
begin
  FDestViewData := Item.CheckViewDataInitialized(Item.ActiveFrame.ViewData);
  FDestViewData.NeedDrawTextOnImage := DestViewData.Item.OptionsAnimate.AnimateText;
  FSourceViewData := Item.CheckViewDataInitialized(Item.ViewInfo.ViewData);
  FSourceViewData.NeedDrawTextOnImage := DestViewData.NeedDrawTextOnImage;
end;

{ TdxTileControlDragAndDropAnimation }

constructor TdxTileControlDragAndDropAnimation.Create(
  AChanges: TdxTileControlDragAndDropChanges);
begin
  FChanges := AChanges;
  with FChanges.DragAndDropObject.DragImage do
    FDragImageOrigin := cxPointOffset(BoundsRect.TopLeft, PositionOffset);
  inherited Create(200, ateAccelerateDecelerate, AnimationLength);
end;

function TdxTileControlDragAndDropAnimation.GetTileControl: TdxCustomTileControl;
begin
  Result := Changes.TileControl;
end;

function TdxTileControlDragAndDropAnimation.AnimationLength: Integer;
begin
  Result := dxTileDropAnimationStepCount;
end;

procedure TdxTileControlDragAndDropAnimation.DoAnimate;
begin
  if ((Changes.ItemsInfo.Count = 0) and not Changes.DragObjectFinished) then
    Finished := True
  else
  begin
    Changes.SetAnimationProgress(Position div 100);
    if not Changes.DragObjectFinished and
        not cxPointIsEqual(GetMouseCursorPos, Changes.DragAndDropObject.PrevMousePos) then
      Changes.DragAndDropObject.ShowDragImage(GetMouseCursorPos);
    TileControl.ForceUpdate();
  end;
end;

{ TdxTileControlHottrackItemAnimation }

constructor TdxTileControlHottrackItemAnimation.Create(
  AItem: TdxTileControlItem; AShowFrame: Boolean = True);
begin
  FShowFrame := AShowFrame;
  FItem := AItem;
  AItem.AddTransition(Self);
  inherited Create(dxTileControlHotTrackItemAnimationTime, ateLinear, 255);
  AItem.Invalidate;
end;

destructor TdxTileControlHottrackItemAnimation.Destroy;
begin
  Item.RemoveTransition(Self);
  inherited Destroy;
end;

procedure TdxTileControlHottrackItemAnimation.DoAnimate;
begin
  if ShowFrame then
    Item.ViewInfo.HottrackValue := Position
  else
    Item.ViewInfo.HottrackValue := 255 - Position;
end;

function TdxTileControlHottrackItemAnimation.IsCompatible(AAnimation: TdxAnimationTransition): Boolean;
begin
  Result := (AAnimation.ClassType <> ClassType) or
    (TdxTileControlHottrackItemAnimation(AAnimation).Item <> Item);
end;

{ TdxTileControlHandScroll }

procedure TdxTileControlHandScroll.DoScrollHorizontally;
var
  dX: Integer;
begin
  dX := PrevMousePos.X - CurMousePos.X;
  dX := dX div GetSlowdownScrollFactor(ViewInfo.LeftScrollPos, ViewInfo.ContentWidth, dX);
  if dX <> 0 then
    ViewInfo.LeftScrollPos := ViewInfo.LeftScrollPos + dX;
end;

procedure TdxTileControlHandScroll.DoScrollVertically;
var
  dY: Integer;
begin
  dY := PrevMousePos.Y - CurMousePos.Y;
  dY := dY div GetSlowdownScrollFactor(ViewInfo.TopScrollPos, ViewInfo.ContentHeight, dY);
  if dY <> 0 then
    ViewInfo.TopScrollPos := ViewInfo.TopScrollPos + dY;
end;

procedure TdxTileControlHandScroll.DragAndDrop(const P: TPoint; var Accepted: Boolean);
var
  ALeftPos, ATopPos: Integer;
begin
  Accepted := True;
  ALeftPos := ViewInfo.LeftScrollPos;
  ATopPos := ViewInfo.TopScrollPos;
  DoScrollHorizontally;
  DoScrollVertically;
  if (ALeftPos <> ViewInfo.LeftScrollPos) or (ATopPos <> ViewInfo.TopScrollPos) then
    TileControl.Update;
  inherited DragAndDrop(P, Accepted);
end;

procedure TdxTileControlHandScroll.EndDragAndDrop(Accepted: Boolean);
begin
  FStartAnimationPosX := ViewInfo.LeftScrollPos;
  FFinishAnimationPosX := Max(0, Min(StartAnimationPosX, ViewInfo.ContentWidth - ViewInfo.HorzScrollPage));
  FStartAnimationPosY := ViewInfo.TopScrollPos;
  FFinishAnimationPosY := Max(0, Min(FStartAnimationPosY, ViewInfo.ContentHeight - ViewInfo.VertScrollPage));
  if (StartAnimationPosX <> FinishAnimationPosX) or (StartAnimationPosY <> FinishAnimationPosY) then
    TileControl.Controller.ImmediateAnimation(TdxTileControlRubberAnimation.Create(TileControl, Self));
  inherited EndDragAndDrop(Accepted);
end;

function TdxTileControlHandScroll.GetDragAndDropCursor(Accepted: Boolean): TCursor;
const
  Cursors: array[Boolean] of TCursor = (crDefault, crcxHandDrag);
begin
  Result := Cursors[Accepted];
end;

function TdxTileControlHandScroll.GetImmediateStart: Boolean;
begin
  Result := False;
end;

function TdxTileControlHandScroll.GetSlowdownScrollFactor(APos, AContentSize, ADelta: Integer): Integer;
var
  ARange: Integer;
begin
  Result := 1;
  ARange := AContentSize div 4;
  if ((APos < -ARange) and (ADelta < 0)) or ((APos > ARange) and (ADelta > 0)) then
  begin
    Result := 2;
    if (APos < -2 * ARange) or (APos > 2 * ARange) then
      Result := 3;
  end;
end;

function TdxTileControlHandScroll.GetTileControl: TdxCustomTileControl;
begin
  Result := TdxCustomTileControl(Control);
end;

function TdxTileControlHandScroll.GetViewInfo: TdxTileControlViewInfo;
begin
  Result := TileControl.ViewInfo;
end;

{ TdxTileControlDragDropCustomObject }

constructor TdxTileControlDragDropCustomObject.Create(AControl: TcxControl);
begin
  inherited Create(AControl);
  ViewInfo.DragDropChanges := TdxTileControlDragAndDropChanges.Create(ViewInfo);
  FDragCell := TdxTileControlCustomCellViewInfo(Controller.DragCell);
end;

destructor TdxTileControlDragDropCustomObject.Destroy;
begin
  FreeAndNil(DragImage);
  FreeAndNil(ViewInfo.DragDropChanges);
  inherited Destroy;
end;

procedure TdxTileControlDragDropCustomObject.BeginDragAndDrop;
begin
  inherited BeginDragAndDrop;
  CreateAutoScrollObjects;
  FIsTouching := IsTouchEvent;
  Controller.PrepareToDragAndDrop;
  if DragCell is TdxTileControlGroupCaptionViewInfo then
    FDragCell := TdxTileControlGroupCaptionViewInfo(DragCell).Group.ViewInfo;
  if IsTouching and (Controller.ItemCheckMode <> tcicmNone) and DragCellIsItem then
  begin
    FState := tcddsPulling;
    InitializeDragImage;
  end
  else
    BeginDragMoving;
end;

procedure TdxTileControlDragDropCustomObject.BeginDragAndDropGroup;
begin
end;

procedure TdxTileControlDragDropCustomObject.BeginDragAndDropItem;
begin
  Controller.CanItemDrawing := False;
end;

procedure TdxTileControlDragDropCustomObject.BeginDragMoving;
begin
  Controller.UncheckAllItems;
  FState := tcddsMoving;
  FPrevAccepted := True;
  ViewInfo.StoreGroupsOrigin;
  InitializeDragImage;
  if DragCellIsItem then
    BeginDragAndDropItem
  else
    BeginDragAndDropGroup;
end;

procedure TdxTileControlDragDropCustomObject.CalculateHotSpot;
var
  P: TPoint;
begin
  P := Controller.StartDragPos;
  if DragCell.Visible or TileControl.IsDesigning then
    FHotSpot := Point(P.X - DragCell.Bounds.Left, P.Y - DragCell.Bounds.Top)
  else
    FHotSpot := cxPointInvert(P);
end;

function TdxTileControlDragDropCustomObject.CheckAutoScrolling: Boolean;
var
  R: TRect;
begin
  R := DragBounds;
  Result := ScrollControllers[sLeft].Check(R.TopLeft) or
    ScrollControllers[sLeft].Check(cxRectLeftBottom(R));
  if ScrollControllers[sLeft].Timer.Enabled then
    ScrollControllers[sRight].Stop
  else
    Result := ScrollControllers[sRight].Check(R.BottomRight) or
      ScrollControllers[sRight].Check(cxRectRightTop(R));
  Result := Result or ScrollControllers[sTop].Check(R.TopLeft) or
    ScrollControllers[sTop].Check(cxRectRightTop(R));
  if ScrollControllers[sTop].Timer.Enabled then
    ScrollControllers[sBottom].Stop
  else
    Result := Result or ScrollControllers[sBottom].Check(R.BottomRight) or
      ScrollControllers[sBottom].Check(cxRectLeftBottom(R));
end;

function TdxTileControlDragDropCustomObject.CreateAutoScrollObject(Kind: TScrollBarKind;
  const ARect: TRect; ACode: TScrollCode): TdxTileControlAutoScrollingObject;
begin
  Result := TdxTileControlAutoScrollingObject.Create(Self);
  Result.SetParams(ARect, Kind, ACode, dxTileControlScrollStep);
end;

procedure TdxTileControlDragDropCustomObject.CreateAutoScrollObjects;
var
  R, AScrollRect: TRect;
begin
  R := ViewInfo.TilesArea;
  AScrollRect := cxRectSetWidth(R, dxTileControlAutoScrollWidth);
  AScrollRect.Left := AScrollRect.Left - Screen.Width;
  ScrollControllers[sLeft] := CreateAutoScrollObject(sbHorizontal, AScrollRect, scLineUp);

  AScrollRect := R;
  AScrollRect.Left := AScrollRect.Right - dxTileControlAutoScrollWidth;
  AScrollRect := cxRectSetWidth(AScrollRect, Screen.Width);
  ScrollControllers[sRight] := CreateAutoScrollObject(sbHorizontal, AScrollRect, scLineDown);

  AScrollRect := R;
  AScrollRect.Bottom := AScrollRect.Top + dxTileControlAutoScrollWidth;
  AScrollRect.Top := AScrollRect.Top - Screen.Height;
  ScrollControllers[sTop] := CreateAutoScrollObject(sbVertical, AScrollRect, scLineUp);

  AScrollRect := R;
  AScrollRect.Top := AScrollRect.Bottom - dxTileControlAutoScrollWidth;
  AScrollRect := cxRectSetHeight(AScrollRect, Screen.Height);
  ScrollControllers[sBottom] := CreateAutoScrollObject(sbVertical, AScrollRect, scLineDown);
end;

procedure TdxTileControlDragDropCustomObject.DestroyAutoScrollObjects;
begin
  FreeAndNil(ScrollControllers[sLeft]);
  FreeAndNil(ScrollControllers[sRight]);
  FreeAndNil(ScrollControllers[sTop]);
  FreeAndNil(ScrollControllers[sBottom]);
end;

procedure TdxTileControlDragDropCustomObject.InitializeDragImage;
var
  AWinOrg: TPoint;
begin
  AWinOrg := DragCell.Bounds.TopLeft;
  if DragImage = nil then
  begin
    DragImage := TcxDragImage.Create;
    DragImage.BoundsRect := DragCell.Bounds;
    DragImage.MoveTo(TileControl.ClientToScreen(AWinOrg));
  end;

  DragImage.Canvas.WindowOrg := AWinOrg;
  if DragCellIsItem then
  begin
    DragCellAsItem.ViewInfo.DrawContent(DragImage.Canvas, DragCell.Bounds);
    if State = tcddsPulling then
    begin
      if DragCellAsItem.Checked <> IsPullDownGesture then
        DragCellAsItem.ViewInfo.DrawChecked(DragImage.Canvas);
    end;
  end
  else
  begin
    ViewInfo.Painter.DrawBackground(DragImage.Canvas, DragImage.BoundsRect);
    ViewInfo.Cells.DrawWithoutClipping(DragImage.Canvas);
  end;
end;

function TdxTileControlDragDropCustomObject.GetController: TdxTileControlController;
begin
  Result := TileControl.Controller;
end;

function TdxTileControlDragDropCustomObject.GetDragBounds: TRect;
begin
  Result.TopLeft := TileControl.ScreenToClient(DragImage.BoundsRect.TopLeft);
  Result := cxRectSetSize(Result, DragImage.Width, DragImage.Height);
end;

function TdxTileControlDragDropCustomObject.GetDragCellAsGroup: TdxTileControlGroup;
begin
  Result := TdxTileControlGroupViewInfo(DragCell).Group;
end;

function TdxTileControlDragDropCustomObject.GetDragCellAsItem: TdxTileControlItem;
begin
  Result := TdxTileControlItemViewInfo(DragCell).Item;
end;

function TdxTileControlDragDropCustomObject.GetDragCellIsItem: Boolean;
begin
  Result := DragCell is TdxTileControlItemViewInfo;
end;

procedure TdxTileControlDragDropCustomObject.DoAnimateContent(const AStart, AFinish: TPoint);
var
  I: Integer;
begin
  if TileControl.IsDesigning or cxPointIsEqual(AStart, AFinish) then Exit;
  for I := 0 to ViewInfo.Cells.Count - 1 do
    ViewInfo.Cells[I].Scroll(AStart.X - AFinish.X, AStart.Y - AFinish.Y);
  TileControl.Controller.ImmediateAnimation(TdxTileControlContentAnimation.Create(
    TileControl, dxTileControlCenterContentAnimationTime, AFinish.X - AStart.X, AFinish.Y - AStart.Y));
end;

procedure TdxTileControlDragDropCustomObject.DragAndDrop(const P: TPoint; var Accepted: Boolean);
begin
  if not cxPointIsEqual(P, PrevMousePos) then
  begin
    HideOriginalDragCell;
    if not FHotSpotCalculated then
    begin
      CalculateHotSpot;
      FHotSpotCalculated := True;
    end;

    case State of
      tcddsPulling:
        Pulling(P);
      tcddsMoving:
        DragMoving(P, Accepted);
    end;
    inherited DragAndDrop(P, Accepted);
  end;
end;

procedure TdxTileControlDragDropCustomObject.DragAndDropGroup(var Accepted: Boolean);
begin
end;

procedure TdxTileControlDragDropCustomObject.DragAndDropItem(var Accepted: Boolean);
begin
end;

procedure TdxTileControlDragDropCustomObject.DragMoving(const P: TPoint; var Accepted: Boolean);
begin
  ShowDragImage(TileControl.ClientToScreen(P));
  if DragCellIsItem then
    DragAndDropItem(Accepted)
  else
    DragAndDropGroup(Accepted);
  StopAutoScrollingTimers;
  CheckAutoScrolling;
  FPrevAccepted := Accepted;
end;

procedure TdxTileControlDragDropCustomObject.EndDragAndDrop(Accepted: Boolean);
begin
  DestroyAutoScrollObjects;
  inherited EndDragAndDrop(Accepted);
  if DragCell <> nil then
  begin
    DragImage.Hide;
    case State of
      tcddsMoving:
        EndDragMoving(Accepted);
      tcddsPulling:
        if IsPullDownGesture then
          PullDown(Accepted);
    end;
    TileControl.Invalidate;
  end;
end;

procedure TdxTileControlDragDropCustomObject.EndDragAndDropGroup(Accepted: Boolean);
begin
end;

procedure TdxTileControlDragDropCustomObject.EndDragAndDropItem(Accepted: Boolean; var ANewGroup: TdxTileControlGroup);
begin
end;

procedure TdxTileControlDragDropCustomObject.EndDragMoving(Accepted: Boolean);
var
  ANewGroup: TdxTileControlGroup;
  AStart, AFinish: TPoint;
begin
  ANewGroup := nil;
  DragDropChanges.BeforeUpdate;
  try
    DragDropChanges.DragFinished := True;
    if DragCellIsItem then
      EndDragAndDropItem(Accepted, ANewGroup)
    else
      EndDragAndDropGroup(Accepted);
  finally
    DragDropChanges.AfterUpdate;
  end;
  if ANewGroup <> nil then
    ANewGroup.ViewInfo.FNewGroupAreaBounds := cxNullRect;
  Controller.RestoreItemsBounds;
  if TileControl.IsDesigning then
    SetDesignerModified(TileControl);
  TileControl.ForceUpdate(True);
  ViewInfo.ClearGroupsOrigin;
  if DragCellIsItem then
  begin
    Controller.CanItemDrawing := True;
    DragCellAsItem.MakeVisible;
    DragImage.Hide;
    TileControl.Refresh;
    AStart := DragCellAsItem.ViewInfo.Bounds.TopLeft;
    ViewInfo.Calculate;
    AFinish := DragCellAsItem.ViewInfo.Bounds.TopLeft;
    DoAnimateContent(AStart, AFinish);
    TileControl.DoItemDragEnd;
  end
  else
    DragCellAsGroup.MakeVisible;
  Controller.DragCell := nil;  
end;

procedure TdxTileControlDragDropCustomObject.PullDown(Accepted: Boolean);
begin
  //nothing
end;

procedure TdxTileControlDragDropCustomObject.Pulling(const P: TPoint);
var
  ADragImagePos: TPoint;
begin
  ADragImagePos := Controller.StartDragPos;
  ADragImagePos.Y := ADragImagePos.Y + Min(MulDiv(Max(P.Y - ADragImagePos.Y, 0), 2, 5), MaxPullSize);
  PullProgress := MulDiv(100, ADragImagePos.Y - Controller.StartDragPos.Y, MaxPullSize);
  ShowDragImage(TileControl.ClientToScreen(ADragImagePos));
  if not PtInRect(cxRectInflate(DragBounds, MaxPullSize div 2, MaxPullSize div 2), P) then
    BeginDragMoving;
end;

function TdxTileControlDragDropCustomObject.GetDragAndDropCursor(Accepted: Boolean): TCursor;
const
  Cursors: array [Boolean] of TCursor = (crNoDrop, crArrow);
begin
  if State = tcddsPulling then
    Result := crDefault
  else
    Result := Cursors[Accepted];
end;

function TdxTileControlDragDropCustomObject.GetDragDropChanges: TdxTileControlDragAndDropChanges;
begin
  Result := ViewInfo.DragDropChanges;
end;

function TdxTileControlDragDropCustomObject.GetHitTest: TdxTileControlHitTest;
begin
  Result := TileControl.HitTest;
end;

function TdxTileControlDragDropCustomObject.GetImmediateStart: Boolean;
begin
  Result := False;
end;

function TdxTileControlDragDropCustomObject.GetIsPullDownGesture: Boolean;
begin
  Result := PullProgress >= dxTileControlPullDownThreshold;
end;

function TdxTileControlDragDropCustomObject.GetMaxPullSize: Integer;
begin
  Result := DragImage.Height div 2;
end;

function TdxTileControlDragDropCustomObject.GetTileControl: TdxCustomTileControl;
begin
  Result := TdxCustomTileControl(Control);
end;

function TdxTileControlDragDropCustomObject.GetViewInfo: TdxTileControlViewInfo;
begin
  Result := TileControl.ViewInfo;
end;

procedure TdxTileControlDragDropCustomObject.HideOriginalDragCell;
begin
  if FDragCellIsHided then Exit;
  FDragCellIsHided := True;
  TileControl.ForceUpdate(True);
end;

function TdxTileControlDragDropCustomObject.IsRectInControl(const ARect: TRect): Boolean;
begin
  Result := cxRectIntersect(TileControl.Bounds, ARect);
end;

function TdxTileControlDragDropCustomObject.MouseClientToScreen(const P: TPoint): TPoint;
begin
  Result.X := P.X - FHotSpot.X;
  Result.Y := P.Y - FHotSpot.Y;
end;

procedure TdxTileControlDragDropCustomObject.ShowDragImage(APos: TPoint);
begin
  DragImage.MoveTo(MouseClientToScreen(APos));
  DragImage.Visible := True;
  DragImage.Refresh;
end;

procedure TdxTileControlDragDropCustomObject.SetPullProgress(AValue: Integer);
var
  APrevIsPullDownGesture: Boolean;
begin
  if FPullProgress <> AValue then
  begin
    APrevIsPullDownGesture := IsPullDownGesture;
    FPullProgress := AValue;
    if DragCellIsItem then
    begin
      if IsPullDownGesture <> APrevIsPullDownGesture then
        InitializeDragImage;
      DragCellAsItem.Invalidate;
    end;
  end;
end;

procedure TdxTileControlDragDropCustomObject.StopAutoScrollingTimers;
var
  ASide: TdxTileControlAutoScrollSide;
begin
  for ASide := Low(TdxTileControlAutoScrollSide) to High(TdxTileControlAutoScrollSide) do
    ScrollControllers[ASide].Stop;
end;

{ TdxTileControlDragDropGroup }

procedure TdxTileControlDragDropGroup.BeginDragAndDropGroup;
begin
  if FDragCell is TdxTileControlGroupViewInfo then
    FDragGroup := TdxTileControlGroupViewInfo(DragCell).Group
  else
    FDragGroup := TdxTileControlGroupCaptionViewInfo(DragCell).Group;
  FBeginIndex := FDragGroup.Index;
  FPrevIndex := FBeginIndex;
end;

procedure TdxTileControlDragDropGroup.DragAndDropGroup(var Accepted: Boolean);
var
  AIndex: Integer;
begin
  DragDropChanges.BeforeUpdate;
  try
    AIndex := GetPotentialIndexForDraggedGroup;
    Accepted := AIndex >= 0;
    if Accepted then
    begin
      if DragGroup.Collection = nil then
        DragGroup.AddToCollection(Groups);
      DragGroup.Index := AIndex;
      if AIndex <> FPrevIndex then
        ViewInfo.Calculate;
      if FPrevIndex = -1 then
      begin
        FPrevIndex := DragGroup.Index;
        FPrevAccepted := Accepted;
        DragAndDropGroup(Accepted);
      end;
    end
    else
      if FDragGroup.Collection <> nil then
      begin
        FDragGroup.RemoveFromCollection(Groups);
        ViewInfo.Calculate;
      end;
  finally
    DragDropChanges.AfterUpdate;
  end;
  FPrevIndex := DragGroup.Index;
end;

procedure TdxTileControlDragDropGroup.EndDragAndDropGroup(Accepted: Boolean);
begin
  if DragGroup.Collection = nil then
    DragGroup.AddToCollection(Groups);
  if not Accepted then
    DragGroup.Index := FBeginIndex;
end;

function TdxTileControlDragDropGroup.GetPotentialIndexForDraggedGroup: Integer;
begin
  if not IsRectInControl(DragBounds) then
    Result := -1
  else
    if DragGroup.Collection = nil then
      Result := GetPotentialIndexForNewlyInsertedGroup
    else
      Result := GetPotentialIndexForMovedGroup;
end;

function TdxTileControlDragDropGroup.GetPotentialIndexForNewlyInsertedGroup: Integer;
var
  ADragCenter, AGroupCenter: TPoint;
  I: Integer;
  AGroup: TdxTileControlGroup;
  ASuccess: Boolean;
begin
  Result := Groups.Count;
  ADragCenter := cxRectCenter(DragBounds);
  for I := 0 to Groups.Count - 1 do
  begin
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    AGroupCenter := cxRectCenter(AGroup.ViewInfo.FExpandedBounds);
    if GroupLayout = glHorizontal then
      ASuccess := ADragCenter.X <= AGroupCenter.X
    else
      ASuccess := ADragCenter.Y <= AGroupCenter.Y;
    if ASuccess then
    begin
      Result := I;
      Break;
    end;
  end;
end;

function TdxTileControlDragDropGroup.GetPotentialIndexForMovedGroup: Integer;

  function GetIndex(const ACurrentGroupIndex, ACurrentGroupCenter, ADragLeft, ADragRight: Integer): Integer;
  begin
    Result := -1;
    if ADragRight < ACurrentGroupCenter then
      Result := Max(0, ACurrentGroupIndex - 1 + Ord(ACurrentGroupIndex = FPrevIndex))
    else
      if (ADragLeft < ACurrentGroupCenter) and (ACurrentGroupCenter <= ADragRight) then
        Result := ACurrentGroupIndex;
  end;

var
  AGroupCenter: TPoint;
  AGroup: TdxTileControlGroup;
  I, AIndex: Integer;
begin
  Result := FPrevIndex;
  for I := 0 to Groups.Count - 1 do
  begin
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    AGroupCenter := cxRectCenter(AGroup.ViewInfo.FExpandedBounds);
    if GroupLayout = glHorizontal then
      AIndex := GetIndex(I, AGroupCenter.X, DragBounds.Left, DragBounds.Right)
    else
      AIndex := GetIndex(I, AGroupCenter.Y, DragBounds.Top, DragBounds.Bottom);
    if AIndex >= 0 then
    begin
      Result := AIndex;
      Break;
    end;
  end;
end;

function TdxTileControlDragDropGroup.GetGroupLayout: TdxTileControlGroupLayout;
begin
  Result := TileControl.OptionsView.GroupLayout;
end;

function TdxTileControlDragDropGroup.GetGroups: TdxTileControlGroupCollection;
begin
  Result := TileControl.Groups;
end;


  { TdxDragItemInfo }

procedure TdxTileControlDragItemInfo.SetGroup(AGroup: TdxTileControlGroup);
begin
  FGroup := AGroup;
end;

{ TdxTileControlDragItemPlace }

constructor TdxTileControlDragItemPlace.Create;
begin
  FPosition := TdxLayoutItemPosition.Create;
end;

destructor TdxTileControlDragItemPlace.Destroy;
begin
  FreeAndNil(FPosition);
  inherited Destroy;
end;

procedure TdxTileControlDragItemPlace.Assign(ASource: TdxTileControlDragItemPlace);
begin
  FGroup := ASource.Group;
  FVirtualGroup := ASource.VirtualGroup;
  FPosition.Assign(ASource.Position);
end;

function TdxTileControlDragItemPlace.GetGroup: TdxTileControlGroup;
begin
  if FGroup = nil then
    Result := nil
  else
    Result := FGroup.Group;
end;

function TdxTileControlDragItemPlace.IsEqual(APlace: TdxTileControlDragItemPlace): Boolean;
begin
  Result := (FGroup = APlace.Group) and (FVirtualGroup = APlace.FVirtualGroup) and
    FPosition.IsEqual(APlace.Position);
end;

{ TdxTileControlDragDropItem }

constructor TdxTileControlDragDropItem.Create(AControl: TcxControl);
begin
  inherited Create(AControl);
  FGroupItemsPositions := TcxObjectList.Create(True);
  FPrevPlace := TdxTileControlDragItemPlace.Create;
  FPlace := TdxTileControlDragItemPlace.Create;
  FTemporaryGroup := TdxTileControlGroup.Create(TileControl);
  FNextPosition := TdxLayoutItemPosition.Create;
end;

destructor TdxTileControlDragDropItem.Destroy;
begin
  FreeAndNil(FPlace);
  FreeAndNil(FPrevPlace);
  FGroupItemsPositions.Clear;
  FreeAndNil(FGroupItemsPositions);
  FreeAndNil(FTemporaryGroup);
  FreeAndNil(FNextPosition);
  inherited Destroy;
end;

procedure TdxTileControlDragDropItem.BeginDragAndDropItem;
begin
  inherited BeginDragAndDropItem;
  if not TileControl.IsDesigning then
    Controller.ImmediateAnimation(TdxTileControlInflateItemAnimation.Create(
      TileControl, nil, -1, dxTileControlInflateAnimationStepsCount));
  FBeginGroup := FDragItem.Group;
  FBeginIndex := FDragItem.IndexInGroup;
  FWasTryDecreaseBeginGroup := False;
  InitializePrevPlace;
end;

procedure TdxTileControlDragDropItem.BeginDragMoving;
begin
  FDragItem := TdxTileControlItemViewInfo(DragCell).Item;
  inherited BeginDragMoving;
end;

procedure TdxTileControlDragDropItem.DoCollapseBeginGroupWhenItemIsLast;
begin
  FBeginGroup.Visible := False;
  ViewInfo.Calculate;
end;

procedure TdxTileControlDragDropItem.DoItemDragOver(var AAccepted: Boolean);
begin
  TileControl.DoItemDragOver(AAccepted);
  FDragOverIsAccepted := AAccepted;
end;

procedure TdxTileControlDragDropItem.DoRestoreDragItemSourcePosition;
begin
  FDragItem.Move(FBeginGroup, FBeginIndex);
  FPlace.Group := FBeginGroup.ViewInfo;
  FDragItem.ViewInfo.Recalculate;
  if not FBeginGroup.Visible then
    FBeginGroup.Visible := True;
   ViewInfo.Calculate;
end;

procedure TdxTileControlDragDropItem.DragAndDropItem(var Accepted: Boolean);
begin
  Accepted := True;
  DragDropChanges.BeforeUpdate;
  try
    TryDecreaseBeginGroup;
    CheckPlaceDragItem(Accepted);
    if Accepted then
    begin
      Accepted := HasValidGroup;
      if not Accepted then
        MoveDragItemFromControl
      else
        if FPlace.Group <> nil then
          CalculateDragAndDropItemInGroup
        else
          CalculateDragAndDropItemInVirtualGroup(Accepted);
      if FPlace.VirtualGroup <> nil then
      begin
        if not FPlace.VirtualGroup.SizeMustFromDragItem  then
        begin
          FPlace.VirtualGroup.SizeMustFromDragItem := True;
          ViewInfo.Calculate;
        end;
        FPlace.VirtualGroup.State := vgsVisible;
      end;
      FPrevPlace.Assign(FPlace);
    end;
  finally
    DragDropChanges.AfterUpdate;
  end;
end;

procedure TdxTileControlDragDropItem.EndDragAndDropItem(Accepted: Boolean; var ANewGroup: TdxTileControlGroup);
begin
  if not Accepted or ((FPrevPlace.Group = nil) and (FPrevPlace.VirtualGroup = nil)) then
    RestoreDragItemSourcePosition
  else
    if FPrevPlace.VirtualGroup <> nil then
    begin
      FPrevPlace.VirtualGroup.State := vgsNoVisible;
      ANewGroup := CreateNewGroupAndMoveDragItemTo(FPrevPlace.VirtualGroup);
      TileControl.RemoveGroupIfEmpty(FBeginGroup);
    end
    else
    if not FBeginGroup.Visible then
      TileControl.RemoveGroupIfEmpty(FBeginGroup);
end;

procedure TdxTileControlDragDropItem.CalculateDragAndDropItemInGroup;
begin
  if FPlace.Group = FPrevPlace.Group then
    CalculateDragAndDropItemInPrevGroup
  else
    CalculateDragAndDropItemInAnotherGroup
end;

procedure TdxTileControlDragDropItem.CalculateDragAndDropItemInAnotherGroup;
var
  AGroup: TdxTileControlGroup;
  I: Integer;
begin
  AGroup := FPlace.Group.Group;
  MoveDragItemToGroup(AGroup, GetNewIndexOfDragItem(AGroup));
  for I := 0 to TileControl.Groups.Count - 1 do
  begin
    AGroup := TileControl.Groups[I];
    if IsBoundsAreasItemsChanged(AGroup) then
    begin
      ViewInfo.Calculate;
      Break;
    end;
  end;
end;

procedure TdxTileControlDragDropItem.CalculateDragAndDropItemInPrevGroup;
var
  AOldIndex, ANewIndex: Integer;
  APrevGroup: TdxTileControlGroup;
begin
  APrevGroup := FPrevPlace.Group.Group;
  AOldIndex := FDragItem.IndexInGroup;
  FTemporaryGroup.AssignFrom(APrevGroup, FDragItem);
  StoreGroupItemsPositions(APrevGroup);
  try
    FTemporaryGroup.ViewInfo.CalculateDimensionAndItemsPositions;
    ANewIndex := GetNewIndexOfDragItem(FTemporaryGroup);
  finally
    RestoreGroupItemsPositions(APrevGroup);
  end;
  if ANewIndex <> AOldIndex then
  begin
    FDragItem.Move(APrevGroup, ANewIndex);
    if IsBoundsAreasItemsChanged(APrevGroup) then
      ViewInfo.Calculate;
  end;
end;

procedure TdxTileControlDragDropItem.CalculateDragAndDropItemInVirtualGroup(var AAccepted: Boolean);
var
  AGroup, ATemporaryGroup: TdxTileControlGroup;
begin
  if GetStayInPlaceVirtualGroup then Exit;
  AGroup := GetGroupCrossedOnTheRight;
  ATemporaryGroup := DragItemInfo.Group;
  DragItemInfo.SetGroup(AGroup);
  if IsPossibleIncreaseGroup(AGroup, AAccepted) then
  begin
    MoveDragItemToGroup(AGroup, AGroup.ItemCount);
    ViewInfo.Calculate;
    CheckPlaceDragItem(AAccepted);
    CalculateDragAndDropItemInGroup;
  end
  else
    DragItemInfo.SetGroup(ATemporaryGroup);
end;

procedure TdxTileControlDragDropItem.CheckGroupDragItem;
begin
  FPlace.Group := nil;
  FPlace.VirtualGroup := nil;
  if not IsRectInControl(DragBounds) then Exit;
  FindGroupOccupiedCenterOfDragItem;
  if FPlace.Group = nil then
  begin
    FindVirtualGroupOccupiedCenterOfDragItem;
    if FPlace.VirtualGroup = nil then
      FindSomethingOccupiedPartiallyOfDragItem;
  end;
end;

procedure TdxTileControlDragDropItem.CheckPlaceDragItem(var AAccepted: Boolean);
begin
  CheckGroupDragItem;
  if FPlace.Group <> nil then
    CheckPositionDragItem
  else
  begin
    FPlace.Position.Row := -1;
    FPlace.Position.Column := -1;
  end;
  DragItemInfo.FGroup := FPlace.GetGroup;
  DoItemDragOver(AAccepted);
  if AAccepted and IsExitFromVirtualGroup then
  begin
    SwitchOff(FPrevPlace.VirtualGroup);
    FPrevPlace.Assign(FPlace);
    CheckPlaceDragItem(AAccepted);
  end;
end;

procedure TdxTileControlDragDropItem.CheckPositionDragItem;
var
  ACheckedBounds: TRect;
  ADragPoint: TPoint;
begin
  ADragPoint := GetDragPoint;
  ACheckedBounds := FPlace.Group.ExpandedBounds;
  if PtInRect(ACheckedBounds, ADragPoint) then
    CheckPositionDragPoint(ADragPoint)
  else
    CheckPositionDragPoint(GetSecondaryDragPoint(ACheckedBounds));
end;

procedure TdxTileControlDragDropItem.CheckPositionDragPoint(ADragPoint: TPoint);
var
  ABounds: TRect;
  AOffset: TPoint;
  ASize: Integer;
  AColumn: Integer;
begin
  AOffset := FPlace.Group.MaximizedAreaBounds.TopLeft;
  ABounds := cxRectOffset(FPlace.Group.MaximizedAreaBounds, AOffset, False);
  ADragPoint := cxPointOffset(ADragPoint, AOffset, False);
  ASize := TileControl.OptionsView.ItemSize + TileControl.OptionsView.ItemIndent;
  FPlace.Position.Row := Min(Max(0, ADragPoint.Y div ASize), ViewInfo.RowCount - 1);
  AColumn := Min(Max(0, ADragPoint.X div ASize), FPlace.Group.ColumnCount - 1);
  FPlace.Position.Column := AColumn - Ord(FDragItem.IsLarge and Odd(AColumn));
end;

function TdxTileControlDragDropItem.CreateNewGroupAndMoveDragItemTo(
  AVirtualGroup: TdxTileControlVirtualGroupViewInfo): TdxTileControlGroup;
var
  AIndex: Integer;
begin
  AIndex := AVirtualGroup.Group.Index + Ord(AVirtualGroup = AVirtualGroup.Group.VirtualGroupAfter);
  Result := TileControl.InsertGroup(AIndex);
  Result.ViewInfo.FNewGroupAreaBounds := AVirtualGroup.AreaBounds;
  MoveDragItemToGroup(Result, 0);
end;

procedure TdxTileControlDragDropItem.InitializePrevPlace;
begin
  FPrevPlace.Group := FBeginGroup.ViewInfo;
  FPrevPlace.VirtualGroup := nil;
  FPrevPlace.Position.Assign(FDragItem.ViewInfo.Position);
end;

function TdxTileControlDragDropItem.IsDragItemsGroupHasMaxExpanded: Boolean;
var
  AGroup: TdxTileControlGroup;
begin
  AGroup := FDragItem.Group;
  Result := False;
  if AGroup = nil then Exit;
  Result := True;
  if not IsDragBoundsCrossesOnTheRight(AGroup) then Exit;
  FTemporaryGroup.AssignFrom(AGroup, FDragItem);
  FTemporaryGroup.FItems.Add(FDragItem);
  FTemporaryGroup.ViewInfo.Recalculate;
  if GroupLayout = glHorizontal then
    Result := cxRectWidth(AGroup.ExpandedBounds) = cxRectWidth(FTemporaryGroup.ExpandedBounds)
  else
    Result := cxRectHeight(AGroup.ExpandedBounds) = cxRectHeight(FTemporaryGroup.ExpandedBounds);
end;

function TdxTileControlDragDropItem.IsDragItemsGroupStayMoreRight: Boolean;
var
  AGroup: TdxTileControlGroup;
begin
  AGroup := FDragItem.Group;
  Result := (AGroup <> nil) and (AGroup.Bounds.Left > FPlace.VirtualGroup.Bounds.Left);
end;

procedure TdxTileControlDragDropItem.FindGroupOccupiedCenterOfDragItem;
var
  I: Integer;
  AGroup: TdxTileControlGroupViewInfo;
  ADragPoint: TPoint;
begin
  ADragPoint := GetDragPoint;
  for I := 0 to TileControl.Groups.Count - 1 do
    if TileControl.Groups[I].Visible then
    begin
      AGroup := TileControl.Groups[I].ViewInfo;
      if PtInRect(AGroup.ExpandedBounds, ADragPoint) then
      begin
        FPlace.Group := AGroup;
        Break;
      end;
    end;
end;

procedure TdxTileControlDragDropItem.FindVirtualGroupOccupiedCenterOfDragItem;
var
  I: Integer;
  AVirtualGroup: TdxTileControlVirtualGroupViewInfo;
  ADragPoint: TPoint;
begin
  ADragPoint := GetDragPoint;
  for I := 0 to VirtualGroups.Count - 1 do
  begin
    AVirtualGroup := TdxTileControlVirtualGroupViewInfo(VirtualGroups[I]);
    if PtInRect(AVirtualGroup.Bounds, ADragPoint) then
    begin
      FPlace.VirtualGroup := AVirtualGroup;
      Break;
    end;
  end;
end;

procedure TdxTileControlDragDropItem.FindSomethingOccupiedPartiallyOfDragItem;
var
  I: Integer;
  AGroup: TdxTileControlGroupViewInfo;
  AVirtualGroup: TdxTileControlVirtualGroupViewInfo;
  R: TRect;
  ASquare, AMaxSquare: Integer;
  AResult: TdxTileControlCustomGroupViewInfo;
begin
  AMaxSquare := 0;
  AResult := nil;
  for I := 0 to TileControl.Groups.Count - 1 do
  begin
    AGroup := TileControl.Groups[I].ViewInfo;
    if AGroup.Group.Visible and cxRectIntersect(R, DragBounds, AGroup.ExpandedBounds) then
    begin
      ASquare := cxRectSquare(R);
      if ASquare > AMaxSquare then
      begin
        AMaxSquare := ASquare;
        AResult := AGroup;
      end;
    end;
  end;
  for I := 0 to VirtualGroups.Count - 1 do
  begin
    AVirtualGroup := VirtualGroups[I] as TdxTileControlVirtualGroupViewInfo;
    if cxRectIntersect(R, DragBounds, AVirtualGroup.Bounds) then
    begin
      ASquare := cxRectSquare(R);
      if ASquare > AMaxSquare then
      begin
        AMaxSquare := ASquare;
        AResult := AVirtualGroup;
      end;
    end;
  end;
  if AResult is TdxTileControlGroupViewInfo then
    FPlace.Group := AResult as TdxTileControlGroupViewInfo
  else
    if AResult is TdxTileControlVirtualGroupViewInfo then
      FPlace.VirtualGroup := AResult as TdxTileControlVirtualGroupViewInfo;
end;

function TdxTileControlDragDropItem.GetGroupCrossedOnTheRight: TdxTileControlGroup;
var
  I: Integer;
  AGroup: TdxTileControlGroup;
begin
  Result := nil;
  for I := 0 to TileControl.Groups.Count - 1 do
  begin
    AGroup := TileControl.Groups[I];
    if IsDragBoundsCrossesOnTheRight(AGroup) then
    begin
      Result := AGroup;
      Break;
    end;
  end;
end;

function TdxTileControlDragDropItem.GetGroupLayout: TdxTileControlGroupLayout;
begin
  Result := TileControl.OptionsView.GroupLayout;
end;

function TdxTileControlDragDropItem.GetDragItemInfo: TdxTileControlDragItemInfo;
begin
  Result := TileControl.FDragItemInfo;
end;

function TdxTileControlDragDropItem.GetDragPoint: TPoint;
var
  ABounds: TRect;
begin
  ABounds := DragBounds;
  if FDragItem.RowCount > 1 then
    ABounds.Bottom := ABounds.Top + TileControl.OptionsView.ItemSize;
  Result := cxRectCenter(ABounds);
end;

function TdxTileControlDragDropItem.GetNewIndexOfDragItem(AGroup: TdxTileControlGroup): Integer;
var
  AItem: TdxTileControlItem;
  I, AIndex, ADirtyIndex: Integer;
begin
    ADirtyIndex := AGroup.ViewInfo.GetZIndex(FPlace.Position);
    Result := 0;
    for I := AGroup.ItemCount - 1 downto 0 do
    begin
      AItem := AGroup.Items[I];
      AIndex := AGroup.ViewInfo.GetZIndex(AItem.ViewInfo.Position);
      if AIndex + Ord(AItem.IsLarge) < ADirtyIndex then
      begin
        Result := I + 1;
        Break;
      end;
    end;
end;

function TdxTileControlDragDropItem.GetSecondaryDragPoint(ABounds: TRect): TPoint;
begin
  if PtInRect(ABounds, DragBounds.TopLeft) then
    Result := DragBounds.TopLeft
  else
    if PtInRect(ABounds, cxRectRightTop(DragBounds)) then
      Result := cxRectRightTop(DragBounds)
    else
      if PtInRect(ABounds, DragBounds.BottomRight) then
        Result := DragBounds.BottomRight
      else
        Result := cxRectLeftBottom(DragBounds);
end;

function TdxTileControlDragDropItem.GetSpecialPointX: Integer;
begin
  Result := cxRectCenter(DragBounds).X - TileControl.OptionsView.ItemSize div 4;
end;

function TdxTileControlDragDropItem.GetSpecialPointY: Integer;
begin
  Result := DragBounds.Top + TileControl.OptionsView.ItemSize div 4;
end;

function TdxTileControlDragDropItem.GetStayInPlaceVirtualGroup: Boolean;
begin
  Result := False;
  if not FPrevAccepted or IsDragItemsGroupStayMoreRight or IsDragItemsGroupHasMaxExpanded then
  begin
    FDragItem.RemoveFromGroup;
    FPlace.VirtualGroup.SizeMustFromDragItem := True;
    ViewInfo.Calculate;
    Result := True;
  end;
end;

function TdxTileControlDragDropItem.GetVirtualGroups: TcxObjectList;
begin
  Result := ViewInfo.VirtualGroups;
end;

function TdxTileControlDragDropItem.HasValidGroup: Boolean;
begin
  Result := (FPlace.Group <> nil) or (FPlace.VirtualGroup <> nil);
end;

function TdxTileControlDragDropItem.IsBoundsAreasItemsChanged(AGroup: TdxTileControlGroup): Boolean;
var
  AMaximizedAreaBounds: TRect;
begin
  AMaximizedAreaBounds := AGroup.MaximizedAreaBounds;
  RecalculateGroup(AGroup);
  Result := not cxRectIsEqual(AMaximizedAreaBounds, AGroup.MaximizedAreaBounds);
end;

function TdxTileControlDragDropItem.IsDoDecreaseBeginGroup: Boolean;
var
  I, ARow, AColumn: Integer;
  AItem: TdxTileControlItem;
begin
  ARow := FDragItem.ViewInfo.Position.Row;
  AColumn := FDragItem.ViewInfo.Position.Column;
  if GroupLayout = glVertical then
    Result := ARow = FBeginGroup.RealRowCount - 1
  else
    Result := AColumn + Ord(FDragItem.IsLarge) = FBeginGroup.RealColumnCount - 1;
  if Result then
    for I := 0 to FBeginGroup.ItemCount - 1 do
    begin
      AItem := FBeginGroup.Items[I];
      if AItem.Visible and (AItem <> FDragItem) then
        if GroupLayout = glVertical then
          Result := ARow > AItem.ViewInfo.Position.Row
        else
        begin
          Result := AColumn > AItem.ViewInfo.Position.Column;
          if (not FDragItem.IsLarge) and (Odd(AColumn)) then
            Result := AColumn > AItem.ViewInfo.Position.Column + Ord(AItem.IsLarge);
        end;
      if not Result then Break;
    end;
  if Result then
  begin
    FDragItem.RemoveFromGroup;
    FPrevPlace.Group := nil;
  end;
end;

function TdxTileControlDragDropItem.IsDragBoundsCrossesOnTheRight(AGroup: TdxTileControlGroup): Boolean;
var
  ABounds: TRect;
begin
  Result := False;
  if not AGroup.Visible then Exit;
  ABounds := AGroup.MaximizedAreaBounds;
  if GroupLayout = glHorizontal then
    Result := (PtInRect(ABounds, DragBounds.TopLeft) or PtInRect(ABounds, cxRectLeftBottom(DragBounds))) and
     (GetSpecialPointX <= ABounds.Right)
  else
    Result := (PtInRect(ABounds, DragBounds.TopLeft) or PtInRect(ABounds, cxRectRightTop(DragBounds))) and
     (GetSpecialPointY <= ABounds.Bottom);
end;

function TdxTileControlDragDropItem.IsExitFromVirtualGroup: Boolean;
begin
  Result := (FPrevPlace.VirtualGroup <> nil) and
    not FPrevPlace.VirtualGroup.IsEqual(FPlace.VirtualGroup);
end;

function TdxTileControlDragDropItem.IsPossibleIncreaseGroup(AGroup: TdxTileControlGroup;
  var AAccepted: Boolean): Boolean;
var
  ARowCountBefore, AColumnCountBefore: Integer;
begin
  DoItemDragOver(AAccepted);
  Result := (AGroup <> nil) and AAccepted and (AGroup.ItemCount > 0) and
    (FPlace.VirtualGroup.IsEqual(FPrevPlace.VirtualGroup) or (AGroup.ViewInfo = FPrevPlace.Group));
  if not Result then Exit;
  FTemporaryGroup.AssignFrom(AGroup, FDragItem);
  StoreGroupItemsPositions(AGroup);
  try
    FTemporaryGroup.ViewInfo.CalculateDimensionAndItemsPositions;
    ARowCountBefore := FTemporaryGroup.RealRowCount;
    AColumnCountBefore := FTemporaryGroup.RealColumnCount;
    FTemporaryGroup.FItems.Add(FDragItem);
    FTemporaryGroup.ViewInfo.CalculateDimensionAndItemsPositions;
    if GroupLayout = glHorizontal then
      Result := AColumnCountBefore < FTemporaryGroup.RealColumnCount
    else
      Result := ARowCountBefore < FTemporaryGroup.RealRowCount;
  finally
    RestoreGroupItemsPositions(AGroup);
  end;
end;

procedure TdxTileControlDragDropItem.MoveDragItemFromControl;
var
  AGroup: TdxTileControlGroup;
  AOldBounds: TRect;
begin
  if FPrevPlace.Group <> nil then
  begin
    AGroup := FPrevPlace.Group.Group;
    AOldBounds := AGroup.MaximizedAreaBounds;
    FDragItem.RemoveFromGroup;
    RecalculateGroup(AGroup);
    if not cxRectIsEqual(AOldBounds, AGroup.MaximizedAreaBounds) then
      ViewInfo.Calculate;
  end;
end;

procedure TdxTileControlDragDropItem.MoveDragItemToGroup(AGroup: TdxTileControlGroup; AIndexInGroup: Integer);
begin
  if AIndexInGroup < 0 then Exit;
  FDragItem.Move(AGroup, AIndexInGroup);
  if (FBeginGroup <> AGroup) and (FBeginGroup.ItemCount = 0) and FBeginGroup.Visible then
    DoCollapseBeginGroupWhenItemIsLast
  else
    RecalculateGroup(AGroup);
end;

procedure TdxTileControlDragDropItem.PullDown(Accepted: Boolean);
begin
  if Accepted then
    TdxTileControlItemViewInfo(DragCell).Item.ToggleChecked;
end;

procedure TdxTileControlDragDropItem.RestoreGroupItemsPositions(AGroup: TdxTileControlGroup);
var
  I: Integer;
begin
  for I := 0 to FGroupItemsPositions.Count - 1 do
    AGroup.Items[I].ViewInfo.Position.Assign(TdxLayoutItemPosition(FGroupItemsPositions[I]));
end;

procedure TdxTileControlDragDropItem.RecalculateGroup(AGroup: TdxTileControlGroup);
begin
  AGroup.ViewInfo.Recalculate;
end;

procedure TdxTileControlDragDropItem.RestoreDragItemSourcePosition;

  function IsLayoutChanged: Boolean;
  begin
    Result := (FDragItem.Group = nil) or
      (FDragItem.Group <> FBeginGroup) or (FDragItem.IndexInGroup <> FBeginIndex)
  end;

begin
  if IsLayoutChanged then
    DoRestoreDragItemSourcePosition;
  SetNoVisibleAllVirtualGroups;
end;

procedure TdxTileControlDragDropItem.SetNoVisibleAllVirtualGroups;
var
  I: Integer;
begin
  for I := 0 to VirtualGroups.Count - 1 do
    TdxTileControlVirtualGroupViewInfo(VirtualGroups[I]).State := vgsNoVisible;
end;

procedure TdxTileControlDragDropItem.SwitchOff(AVirtualGroup: TdxTileControlVirtualGroupViewInfo);
begin
  AVirtualGroup.State := vgsNoVisible;
  if FPlace.Group = nil then
    ViewInfo.Calculate;
end;

procedure TdxTileControlDragDropItem.StoreGroupItemsPositions(AGroup: TdxTileControlGroup);
var
  APosition: TdxLayoutItemPosition;
  I: Integer;
begin
  FGroupItemsPositions.Clear;
  for I := 0 to AGroup.ItemCount - 1 do
  begin
    APosition := TdxLayoutItemPosition.Create;
    APosition.Assign(AGroup.Items[I].ViewInfo.Position);
    FGroupItemsPositions.Add(APosition);
  end;
end;

procedure TdxTileControlDragDropItem.TryDecreaseBeginGroup;
var
  AAccepted: Boolean;
begin
  if FWasTryDecreaseBeginGroup then
    Exit;
  ViewInfo.Calculate;
  FWasTryDecreaseBeginGroup := True;
  if FBeginGroup.ItemCount = 1 then
  begin
    DoCollapseBeginGroupWhenItemIsLast;
    AAccepted := True;
    CheckPlaceDragItem(AAccepted);
    if not AAccepted then
    begin
      DoRestoreDragItemSourcePosition;
      SetNoVisibleAllVirtualGroups;
    end;
  end
  else
    if IsDoDecreaseBeginGroup then
      ViewInfo.Calculate;
end;

{ TdxTileControlDragAndDropChanges }

function dxCompareAnimationInfoCells(
  AInfo1, AInfo2: TdxTileControlDragAndDropChangesCellInfo): Integer;
begin
  Result := AInfo1.Compare(AInfo2);
end;

constructor TdxTileControlDragAndDropChanges.Create(
  AViewInfo: TdxTileControlViewInfo);
begin
  FViewInfo := AViewInfo;
  FItemsInfo := TcxObjectList.Create;
end;

destructor TdxTileControlDragAndDropChanges.Destroy;
begin
  FreeAndNil(FItemsInfo);
  inherited Destroy;
end;


procedure TdxTileControlDragAndDropChanges.AfterUpdate;
var
  I: Integer;
  AInfo: TdxTileControlDragAndDropChangesCellInfo;
begin
  Dec(FLock);
  if FLock > 0 then Exit;
  TileControl.CancelUpdate;
  PopulateItemsInfo(False);
  ItemsInfo.Sort(@dxCompareAnimationInfoCells);
  I := 0;
  while I < Count do
  begin
    if I + 1 < ItemsInfo.Count then
      AInfo := Items[I + 1]
    else
      AInfo := nil;
    if Items[I].IsEqual(AInfo) then
    begin
      ItemsInfo.FreeAndDelete(I);
      ItemsInfo.FreeAndDelete(I);
    end
    else
      if (AInfo = nil) or (Items[I].Item <> AInfo.Item) or
        (Items[I].GroupCaption <> AInfo.GroupCaption) then
        ItemsInfo.FreeAndDelete(I)
      else
      begin
        if not Items[I].Merge(AInfo) then
          ItemsInfo.FreeAndDelete(I)
        else
          Inc(I);
        ItemsInfo.FreeAndDelete(I);
      end;
  end;
  if not TileControl.IsDestroying then
  begin
    if DragObjectFinished then
      FDragImageBounds := dxMapWindowRect(DragAndDropObject.DragImage.Handle, TileControl.Handle, DragAndDropObject.DragImage.ClientRect);
    if not TileControl.IsDesigning then
    begin
      if (ItemsInfo.Count > 0) or DragObjectFinished or DragFinished then
        TileControl.Controller.ImmediateAnimation(TdxTileControlDragAndDropAnimation.Create(Self));
      dxMessagesController.KillMessages(TileControl.Handle, WM_MOUSEMOVE);
    end
    else
      TileControl.Invalidate;
  end;
  ItemsInfo.Clear;
end;

procedure TdxTileControlDragAndDropChanges.BeforeUpdate;
begin
  Inc(FLock);
  if FLock = 1 then
  begin
    FDragImagePosition := cxInvisiblePoint;
    TileControl.BeginUpdate;
    FDragObject := nil;
    ItemsInfo.Clear;
    PopulateItemsInfo(True);
  end;
end;

function TdxTileControlDragAndDropChanges.IndexOf(ACell: TdxTileControlAnimatedDragAndDropCustomCellViewInfo): Integer;
begin
  for Result := 0 to Count - 1 do
    if Items[Result].Cell = ACell then Exit;
  Result := -1;
end;

procedure TdxTileControlDragAndDropChanges.AnimateDragFinished(const AProgress: Integer);
var
  APos: TPoint;
  R: TRect;
begin
  R := DragAndDropObject.DragCell.Bounds;
  APos := DragAndDropObject.DragCell.Bounds.TopLeft;
  APos.X := FDragImageBounds.Left + MulDiv(APos.X - FDragImageBounds.Left,  AProgress, dxTileDropAnimationStepCount);
  APos.Y := FDragImageBounds.Top + MulDiv(APos.Y - FDragImageBounds.Top, AProgress, dxTileDropAnimationStepCount);
  if not cxPointIsEqual(APos, DragAndDropObject.DragImage.BoundsRect.TopLeft) then
  begin
    if not cxPointIsEqual(FDragImagePosition, cxInvisiblePoint) then
      TileControl.InvalidateRect(cxRectSetOrigin(R, FDragImagePosition), False);
    FDragImagePosition := APos;
    TileControl.InvalidateRect(cxRectSetOrigin(R, FDragImagePosition), False);
    TileControl.ForceUpdate();
  end;
  if AProgress = dxTileDropAnimationStepCount then
    FDragObject := nil;
end;

procedure TdxTileControlDragAndDropChanges.DrawItems(ACanvas: TcxCanvas);
var
  I: Integer;
begin
  for I := 0 to Count - 1 do
    Items[I].Draw(ACanvas, FProgress);
  if FDragFinished and (DragAndDropObject is TdxTileControlDragDropItem) then
    DragAndDropObject.DragCellAsItem.ViewInfo.DrawContent(ACanvas, cxRectSetOrigin(FDragImageBounds, FDragImagePosition));
end;

procedure TdxTileControlDragAndDropChanges.PopulateItemsInfo(
  ABeforeUpdate: Boolean);
var
  I: Integer;
  ACell: TdxTileControlAnimatedDragAndDropCustomCellViewInfo;
  AItem: TdxTileControlItem;
  AGroupCaption: TdxTileControlGroupCaption;
begin
  if TileControl.Changes * [tccItems, tccLayout] <> [] then
    ViewInfo.Calculate;
  if ABeforeUpdate then
    ItemsInfo.Capacity := ViewInfo.Cells.Count * 2;
  for I := 0 to ViewInfo.Cells.Count - 1 do
  begin
    if ViewInfo.Cells[I] is TdxTileControlGroupViewInfo then
    begin
      if TdxTileControlGroupViewInfo(ViewInfo.Cells[I]).Group.IsDragged then
        FDragObject := TdxTileControlGroupViewInfo(ViewInfo.Cells[I]);
    end;
    if (ViewInfo.Cells[I] is TdxTileControlItemViewInfo) or
      (ViewInfo.Cells[I] is TdxTileControlGroupCaptionViewInfo) then
    begin
      ACell := TdxTileControlAnimatedDragAndDropCustomCellViewInfo(ViewInfo.Cells[I]);
      if ViewInfo.Cells[I] is TdxTileControlGroupCaptionViewInfo then
      begin
        AGroupCaption := TdxTileControlGroupCaptionViewInfo(ACell).Caption;
        if not ((AGroupCaption.Group = nil) or AGroupCaption.Group.IsDragged or (Trim(AGroupCaption.Text) = '')) then
          ItemsInfo.Add(TdxTileControlDragAndDropChangesCellInfo.Create(ACell, ABeforeUpdate));
      end
      else
      begin
        AItem := TdxTileControlItemViewInfo(ACell).Item;
        if AItem.IsDragged then
          FDragObject := AItem.ViewInfo;
        if not (AItem.IsDragged or (AItem.Group = nil) or AItem.Group.IsDragged) then
          ItemsInfo.Add(TdxTileControlDragAndDropChangesCellInfo.Create(ACell, ABeforeUpdate));
      end;
    end;
  end;
end;

procedure TdxTileControlDragAndDropChanges.SetAnimationProgress(
  const AProgress: Integer);
var
  I: Integer;
begin
  FProgress := AProgress;
  for I := 0 to Count - 1 do
    Items[I].InvalidateAnimatedArea;
  if DragObjectFinished then
  begin
    if FDragObject is TdxTileControlItemViewInfo then
      TdxTileControlItemViewInfo(FDragObject).Item.Invalidate;
    if FDragObject is TdxTileControlGroupViewInfo then
      TdxTileControlGroupViewInfo(FDragObject).Group.Invalidate;
    AnimateDragFinished(Min(AProgress * 100, dxTileDropAnimationStepCount));
  end;
end;

function TdxTileControlDragAndDropChanges.GetCount: Integer;
begin
  Result := ItemsInfo.Count;
end;

function TdxTileControlDragAndDropChanges.GetDragAndDropObject: TdxTileControlDragDropCustomObject;
begin
  Result := TdxTileControlDragDropCustomObject(TileControl.DragAndDropObject);
end;

function TdxTileControlDragAndDropChanges.GetDragObjectFinished: Boolean;
begin
  Result := ((TileControl.DragAndDropState = ddsNone) and
    (DragObject <> nil)) or DragFinished;
end;

function TdxTileControlDragAndDropChanges.GetItem(
  AIndex: Integer): TdxTileControlDragAndDropChangesCellInfo;
begin
  Result := TdxTileControlDragAndDropChangesCellInfo(ItemsInfo.List[AIndex])
end;

function TdxTileControlDragAndDropChanges.GetTileControl: TdxCustomTileControl;
begin
  Result := ViewInfo.TileControl;
end;

{ TdxTileControlDragAndDropChangesCellInfo }

constructor TdxTileControlDragAndDropChangesCellInfo.Create(
  ACell: TdxTileControlAnimatedDragAndDropCustomCellViewInfo; ABeforeUpdate: Boolean);
begin
  GroupCaption := nil;
  Item := nil;
  Cell := ACell;
  if Cell is TdxTileControlGroupCaptionViewInfo then
  begin
    GroupCaption := TdxTileControlGroupCaptionViewInfo(ACell).Caption;
    GroupOrigin := GroupCaption.Group.Bounds.TopLeft;
  end
  else
  begin
    Item := TdxTileControlItemViewInfo(ACell).Item;
    GroupOrigin := Item.Group.Bounds.TopLeft;
    ColumnIndex := Item.ViewInfo.Position.Column mod 2;
    IndexInGroup := Item.IndexInGroup;
  end;
  BeforeUpdate := ABeforeUpdate;
  Bounds := Cell.GetDrawBounds(True);
end;

destructor TdxTileControlDragAndDropChangesCellInfo.Destroy;
begin
  FreeAndNil(ClipRgn);
  inherited Destroy;
end;

function TdxTileControlDragAndDropChangesCellInfo.Compare(
  AInfo: TdxTileControlDragAndDropChangesCellInfo): Integer;
begin
  if (Item <> nil) and (AInfo.Item <> nil) then
    Result := CompareTileControlItems(AInfo)
  else
    if (GroupCaption <> nil) and (AInfo.GroupCaption <> nil) then
      Result := CompareTileControlGroupCaptions(AInfo)
    else
      if Item <> nil then
        Result := 1
      else
        Result := -1;
end;

function TdxTileControlDragAndDropChangesCellInfo.CompareTileControlGroupCaptions(
  AInfo: TdxTileControlDragAndDropChangesCellInfo): Integer;
begin
  if GroupCaption = AInfo.GroupCaption then
    Result := Ord(AInfo.BeforeUpdate) - Ord(BeforeUpdate)
  else
    Result := TdxNativeInt(GroupCaption) - TdxNativeInt(AInfo.GroupCaption);
end;

function TdxTileControlDragAndDropChangesCellInfo.CompareTileControlItems(
  AInfo: TdxTileControlDragAndDropChangesCellInfo): Integer;
begin
  if Item = AInfo.Item then
    Result := Ord(AInfo.BeforeUpdate) - Ord(BeforeUpdate)
  else
    Result := TdxNativeInt(Item) - TdxNativeInt(AInfo.Item);
end;

procedure TdxTileControlDragAndDropChangesCellInfo.Draw(
  ACanvas: TcxCanvas; const AProgress: Integer);
var
  R, R1: TRect;
  AOffset: Integer;
begin
  R1 := cxNullRect;
  R := Cell.GetDrawBounds;

  ACanvas.SaveClipRegion;
  try
    ACanvas.SetClipRegion(ClipRgn, roSet, False);

    AOffset := MulDiv(AreaSize, AProgress, 100);
    if (Bounds.Left = R.Left) or (Bounds.Top = R.Top) then
      CalculateSimpleDrawingAreaBounds(R, AOffset)
    else
      CalculateComplexDrawingAreaBounds(R, R1, AOffset);

    Cell.DrawContent(ACanvas, R);
    if not cxRectIsNull(R1) then
      Cell.DrawContent(ACanvas, R1);
  finally
    ACanvas.RestoreClipRegion;
  end;
end;

procedure TdxTileControlDragAndDropChangesCellInfo.InvalidateAnimatedArea;
begin
  TileControl.InvalidateRgn(ClipRgn, False);
end;

function TdxTileControlDragAndDropChangesCellInfo.IsEqual(
  AInfo: TdxTileControlDragAndDropChangesCellInfo): Boolean;
begin
  Result := (AInfo <> nil) and cxRectIsEqual(Bounds, AInfo.Bounds);
  if Result then
    if Item <> nil then
      Result := IsEqualItems(AInfo)
    else
      Result := IsEqualGroupCaptions(AInfo);
end;

function TdxTileControlDragAndDropChangesCellInfo.IsEqualGroupCaptions(
  AInfo: TdxTileControlDragAndDropChangesCellInfo): Boolean;
begin
  Result := GroupCaption = AInfo.GroupCaption;
end;

function TdxTileControlDragAndDropChangesCellInfo.IsEqualItems(
  AInfo: TdxTileControlDragAndDropChangesCellInfo): Boolean;
begin
  Result := Item = AInfo.Item;
end;

function TdxTileControlDragAndDropChangesCellInfo.Merge(
  AInfo: TdxTileControlDragAndDropChangesCellInfo): Boolean;
var
  R: TRect;
  AInfoGroup: TdxTileControlGroup;
begin
  if AInfo.Item <> nil then
    AInfoGroup := AInfo.Item.Group
  else
    AInfoGroup := AInfo.GroupCaption.Group;
  GroupOrigin := cxPointOffset(AInfoGroup.Bounds.TopLeft, GroupOrigin, False);
  Bounds := cxRectOffset(Bounds,                               // to do
    ViewInfo.LeftScrollPos, ViewInfo.TopScrollPos);
  Result := cxRectIntersect(Bounds, ViewInfo.TilesArea) or Cell.Visible;
  R := Cell.GetDrawBounds;

  if (R.Left = Bounds.Left) or (R.Top = Bounds.Top) then
    ClipRgn := TcxRegion.Create(cxRectUnion(Bounds, R))
  else
  begin
    ClipRgn := TcxRegion.Create(Bounds);
    ClipRgn.Combine(R, roAdd);
  end;
  ClipRgn.Combine(ViewInfo.TilesArea, roIntersect);
  AreaSize := cxRectHeight(R);
  if GroupCaption <> nil then
    if Bounds.Left = R.Left then
      AreaSize := R.Top - Bounds.Top
    else
       AreaSize := R.Left - Bounds.Left
  else
  begin
    IsItemMovedToNeighborPosition :=  not Item.IsLarge and
      (ColumnIndex <> Item.ViewInfo.Position.Column mod 2) and
      (Abs(IndexInGroup - Item.IndexInGroup) = 1);
    if Bounds.Left = R.Left then
      AreaSize := R.Top - Bounds.Top
    else
     if Bounds.Top = R.Top then
       AreaSize := R.Left - Bounds.Left
    else
      if IsItemMovedToNeighborPosition then
        AreaSize := cxRectWidth(R);
  end;
end;

procedure TdxTileControlDragAndDropChangesCellInfo.CalculateComplexDrawingAreaBounds(
  var R, R1: TRect; const AOffset: Integer);
begin
  if GroupCaption <> nil then Exit;
  if IsItemMovedToNeighborPosition then
  begin
    if IndexInGroup < Item.IndexInGroup then
    begin
      R := cxRectSetRight(R, R.Left + AOffset);
      R1 := cxRectSetLeft(Bounds, Bounds.Left + AOffset);
    end
    else
    begin
      R := cxRectSetLeft(R, R.Right - AOffset);
      R1 := cxRectSetLeft(Bounds, Bounds.Left - AOffset);
    end
  end
  else
  begin
    if Bounds.Top > R.Bottom then
    begin
      R := cxRectSetBottom(R, R.Top + AOffset);
      R1 := cxRectSetTop(Bounds, Bounds.Top + AOffset);
    end
    else
    begin
      R := cxRectSetTop(R, R.Bottom - AOffset);
      R1 := cxRectSetTop(Bounds, Bounds.Top - AOffset);
    end;
  end;
end;

procedure TdxTileControlDragAndDropChangesCellInfo.CalculateSimpleDrawingAreaBounds(
  var R: TRect; const AOffset: Integer);
begin
  if Bounds.Left = R.Left then
    R := cxRectSetTop(R, Bounds.Top + AOffset)
  else
    R := cxRectSetLeft(R, Bounds.Left + AOffset)
end;

function TdxTileControlDragAndDropChangesCellInfo.GetTileControl: TdxCustomTileControl;
begin
  Result := Cell.TileControl;
end;

function TdxTileControlDragAndDropChangesCellInfo.GetViewInfo: TdxTileControlViewInfo;
begin
  Result := TileControl.ViewInfo;
end;

{ TdxTileControlAutoScrollingObject }

function TdxTileControlAutoScrollingObject.GetControl: TcxControl;
begin
  Result := TdxTileControlDragDropCustomObject(Owner).TileControl;
end;

function TdxTileControlAutoScrollingObject.GetHasScrollBar: Boolean;
begin
  if TileControl.OptionsBehavior.ScrollMode = smScrollbars then
    Result := inherited GetHasScrollBar
  else
    Result := TileControl.OptionsBehavior.ScrollMode = smScrollButtons;
end;

procedure TdxTileControlAutoScrollingObject.GetScrollBarParams(var AMin, AMax, APos: Integer);
var
  AViewInfo: TdxTileControlViewInfo;
begin
  AViewInfo := TdxCustomTileControl(GetControl).ViewInfo;
  AMin := 0;
  if Kind = sbHorizontal then
  begin
    APos := AViewInfo.LeftScrollPos;
    AMax := AViewInfo.ContentWidth - AViewInfo.HorzScrollPage;
  end
  else
  begin
    APos := AViewInfo.TopScrollPos;
    AMax := AViewInfo.ContentHeight - AViewInfo.VertScrollPage;
  end;
end;

function TdxTileControlAutoScrollingObject.GetTileControl: TdxCustomTileControl;
begin
  Result := TdxCustomTileControl(GetControl);
end;

procedure TdxTileControlAutoScrollingObject.Scroll(AKind: TScrollBarKind;
  ACode: TScrollCode; var APosition: Integer);
const
  ALayouts: array [TScrollBarKind] of TdxTileControlGroupLayout = (glHorizontal, glVertical);
var
  P: TPoint;
  AAccepted: Boolean;
begin
  if ACode <> scEndScroll then
    TileControl.Scroll(AKind, ACode, APosition)
  else
    if TileControl.OptionsView.GroupLayout = ALayouts[AKind] then
    begin
      P := TileControl.ScreenToClient(GetMouseCursorPos);
      TileControl.HitTest.HitPoint := P;
      TileControl.DragAndDropObject.PrevMousePos := cxNullPoint;
      TdxTileControlDragDropCustomObject(TileControl.DragAndDropObject).DragAndDrop(P, AAccepted);
    end;
end;

{ TdxTileControlController }

constructor TdxTileControlController.Create(AOwner: TdxCustomTileControl);
begin
  FTileControl := AOwner;
  FCanItemDrawing := True;
  FFramesAnimationLockCount := 1;
  dxAnimationController.AddListener(Self);
  FAnimationItems := TList.Create;
  FAnimations := TList.Create;
  FHintController := TdxTileControlHintController.Create(Self);
  FNavigator := TdxTileControlItemNavigator.Create(Self);
end;

destructor TdxTileControlController.Destroy;
begin
  EndMouseTracking(Self);
  FreeAndNil(FAnimations);
  FreeAndNil(FHintController);
  FreeAndNil(FAnimationItems);
  FreeAndNil(FNavigator);
  DestroyDesignHelper;
  dxAnimationController.RemoveListener(Self);
  inherited Destroy;
end;

procedure TdxTileControlController.ChangePressedScrollButtonState;
const
  AState: array[Boolean] of TcxButtonState = (cxbsDisabled, cxbsDefault);
begin
  if PressedScrollButton = nil then Exit;
  PressedScrollButton.State := AState[(PressedScrollButton.State = cxbsPressed) and
    ViewInfo.IsScrollAvailable(PressedScrollButton.Direction)];
  PressedScrollButton := nil;
end;

procedure TdxTileControlController.KeyDown(var Key: Word; Shift: TShiftState);
begin
  if not TileControl.IsDesigning and FNavigator.IsAcceptedKey(Key) then
    FNavigator.KeyDown(Key, Shift);

  case Key of
    VK_RETURN:
      if FocusedItem <> nil then
        FocusedItem.Click;
    VK_SPACE:
      if FocusedItem <> nil then
        FocusedItem.ToggleChecked;
    VK_ESCAPE:
      UncheckAllItems;
  end;
end;

procedure TdxTileControlController.PrepareToDragAndDrop;
begin
  HideActionBars;
  HideScrollButtons;
  FHottrackedItem := nil;
  RestoreItemsBounds;
  FMouseDownItem := nil;
end;

procedure TdxTileControlController.ProcessContextMenuMessage(var Message: TWMContextMenu);
begin
  if Message.Result = 1 then
    FContextMenuHandled := True;
end;

procedure TdxTileControlController.StartAnimations;
begin
  StartFramesAnimation;
end;

procedure TdxTileControlController.StartFramesAnimation;
begin
  Dec(FFramesAnimationLockCount);
{$IFDEF CXTEXT}
  Assert(FFramesAnimationLockCount >= 0, 'Invalid lock counter');
{$ENDIF}
  if FFramesAnimationLockCount = 0 then
    TileControl.UnlockTimers;
end;

procedure TdxTileControlController.StopAnimations;
begin
  StopFramesAnimation;
  TerminateAnimations(False);
end;

procedure TdxTileControlController.StopFramesAnimation;
begin
  Inc(FFramesAnimationLockCount);
  if FFramesAnimationLockCount = 1 then
  begin
    if FAnimationItems.Count > 0 then
    begin
      TerminateAnimations(True);
      TileControl.Update;
    end;
    TileControl.LockTimers;
  end;
end;

procedure TdxTileControlController.ToggleActionBars;
begin
  if TileControl.IsAnyActionBarVisible then
    HideActionBars
  else
    ShowActionBars;
end;

procedure TdxTileControlController.RestoreItemBounds(
  AItem: TdxTileControlItem; const AData: Pointer);
begin
  AItem.ViewInfo.InflateDelta := 0;
end;

procedure TdxTileControlController.SetFocusedItem(AValue: TdxTileControlItem);
begin
  if FFocusedItem <> AValue then
  begin
    if FFocusedItem <> nil then
      FFocusedItem.Invalidate;
    FFocusedItem := AValue;
    if FFocusedItem <> nil then
    begin
      FFocusedItem.Invalidate;
      RefreshItems;
    end;
  end;
end;

procedure TdxTileControlController.SetHottrackedItem(AValue: TdxTileControlItem);
begin
  if FHottrackedItem = AValue then Exit;
  if not TileControl.Focused then
    AValue := nil;
  if AValue = FHottrackedItem then Exit;
  if FHottrackedItem <> nil then
    AddAnimation(TdxTileControlHottrackItemAnimation.Create(FHottrackedItem, False));
  FHottrackedItem := AValue;
  if FHottrackedItem <> nil then
    AddAnimation(TdxTileControlHottrackItemAnimation.Create(FHottrackedItem, True));
  if (FocusedItem <> nil) and TileControl.OptionsBehavior.HideFocusOnItemHotTrack then
    FocusedItem.Invalidate;
end;

procedure TdxTileControlController.SetPressedScrollButton(AValue: TdxTileControlScrollButtonViewInfo);
begin
  if FPressedScrollButton <> AValue then
  begin
    if FPressedScrollButton <> nil then
      FPressedScrollButton.Invalidate;
    FPressedScrollButton := AValue;
    if FPressedScrollButton <> nil then
      FPressedScrollButton.Invalidate;
  end;
end;

procedure TdxTileControlController.ShowActionBars;
begin
  TileControl.ShowActionBars;
end;

// design PopupMenu
function TdxTileControlController.AddPopupMenuItem(ACaption: string; const ATag: Integer; const AGroupIndex: Byte;
  const AChecked, ARadioItem: Boolean; AOnClick: TNotifyEvent): TMenuItem;
begin
  Result := TMenuItem.Create(nil);
  Result.Caption := ACaption;
  Result.Checked := AChecked;
  Result.RadioItem := ARadioItem;
  Result.GroupIndex := AGroupIndex;
  Result.Tag := ATag;
  Result.OnClick := AOnClick;
end;

function TdxTileControlController.CheckDesignPopupMenu(AShift: TShiftState): Boolean;
var
  ACaller: TcxComponentCollectionItem;
begin
  if HitAtItem then
    ACaller := HitTest.Item
  else
    if HitAtGroup then
      ACaller := HitTest.Group
    else
      ACaller := nil;
  Result := ACaller <> nil;
  if Result then
    ProcessDesignPopupMenu(ACaller, AShift, GetMouseCursorPos);
end;

procedure TdxTileControlController.CreateTileControlItem(Sender: TObject);
const
  ARowCount: array[Boolean] of Integer = (1, 2);
var
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
  AMenuItem: TMenuItem;
begin
  if FDesignPopupMenuCaller is TdxTileControlGroup then
    AGroup := TdxTileControlGroup(FDesignPopupMenuCaller)
  else
    AGroup := TdxTileControlItem(FDesignPopupMenuCaller).Group;
  AMenuItem := TMenuItem(Sender);
  AItem := TileControl.CreateItem(AMenuItem.Tag > 0, AGroup);
  AItem.RowCount := ARowCount[AMenuItem.Tag = 2];
  SelectObject(AItem, []);
end;

procedure TdxTileControlController.DeleteSelectedObjects(Sender: TObject);
begin
  case FDesignWhatObjectsSelected of
    tcdtwsItem, tcdtwsItems:
      DeleteTileControlItems(True);
    tcdtwsGroup, tcdtwsGroups:
      DeleteTileControlGroups;
    tcdtwsMixed:
      begin
        DeleteTileControlItems(False);
        DeleteTileControlGroups;
      end;
  end;
end;

procedure TdxTileControlController.DeleteTileControlGroups;
var
  AIndex: Integer;
  AGroup: TdxTileControlGroup;
  I: Integer;
begin
  AGroup := TdxTileControlGroup(FDesignPopupMenuCaller);
  AIndex := AGroup.Index;
  for I := TileControl.Groups.Count - 1 downto 0 do
  begin
    AGroup := TileControl.Groups[I];
    if IsObjectSelected(AGroup) then
      AGroup.Free;
  end;
  SelectObject(GetNextObject(AIndex), []);
end;

procedure TdxTileControlController.DeleteTileControlItems(const ASelectNextObjectAfterDelete: Boolean);
var
  AItemIndex: Integer;
  AOwnerGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  if not ASelectNextObjectAfterDelete then
  begin
    DeleteTileControlSelectedItems;
    Exit;
  end;
  AItem := TdxTileControlItem(FDesignPopupMenuCaller);
  AItemIndex := AItem.IndexInGroup;
  AOwnerGroup := AItem.Group;
  DeleteTileControlSelectedItems;
  SelectObject(GetNextObject(AItemIndex, AOwnerGroup), []);
end;

procedure TdxTileControlController.DeleteTileControlSelectedItems;
var
  AItem: TdxTileControlItem;
  I: Integer;
begin
  for I := TileControl.Items.Count - 1 downto 0 do
  begin
    AItem := TileControl.Items[I];
    if IsObjectSelected(AItem) then
      AItem.Free;
  end;
end;

function TdxTileControlController.GetIsExtraLargeItem(AItem: TdxTileControlItem): Boolean;
begin
  Result := AItem.IsLarge and (AItem.RowCount = 2);
end;

function TdxTileControlController.GetIsLargeItem(AItem: TdxTileControlItem): Boolean;
begin
  Result := AItem.IsLarge and (AItem.RowCount = 1);
end;

function TdxTileControlController.GetIsSmallItem(AItem: TdxTileControlItem): Boolean;
begin
  Result := not AItem.IsLarge and (AItem.RowCount = 1);
end;

function TdxTileControlController.GetDesignerMenuItemChecked(const ATag: Integer; AItem: TdxTileControlItem): Boolean;
begin
  case ATag of
    0:
      Result := GetDesignerMenuItemChecked(AItem, GetIsSmallItem);
    1:
      Result := GetDesignerMenuItemChecked(AItem, GetIsLargeItem);
  else
    Result := GetDesignerMenuItemChecked(AItem, GetIsExtraLargeItem);
  end;
end;

function TdxTileControlController.GetDesignerMenuItemChecked(AItem: TdxTileControlItem;
  AFunc: TdxTileControlDesignTimeMenuItemCheckedCondition): Boolean;
var
  I: Integer;
begin
  Result := AFunc(AItem);
  if FDesignWhatObjectsSelected = tcdtwsItem then Exit;
  for I := 0 to TileControl.Items.Count - 1 do
  begin
    AItem := TileControl.Items[I];
    if IsObjectSelected(AItem) then
      if Result <> AFunc(AItem) then
      begin
        Result := False;
        Break;
      end;
  end;
end;

function TdxTileControlController.GetDesignTimeWhatSelected: TdxTileControlDesignTimeWhatSelected;
var
  I: Integer;
begin
  Result := tcdtwsNone;
  for I := 0 to TileControl.Items.Count - 1 do
    if IsObjectSelected(TileControl.Items[I]) then
      if Result = tcdtwsItem then
      begin
        Result := tcdtwsItems;
        Break;
      end
      else
        Result := tcdtwsItem;
  for I := 0 to TileControl.Groups.Count - 1 do
    if IsObjectSelected(TileControl.Groups[I]) then
      if Result in [tcdtwsItem, tcdtwsItems] then
      begin
        Result := tcdtwsMixed;
        Break;
      end
      else
      if Result = tcdtwsGroup then
      begin
        Result := tcdtwsGroups;
        Break;
      end
      else
        Result := tcdtwsGroup;
end;

function TdxTileControlController.GetNextObject(ADeletedGroupIndex: Integer): TPersistent;
var
  I: Integer;
begin
  Result := TileControl;
  ADeletedGroupIndex := Min(ADeletedGroupIndex, TileControl.Groups.Count - 1);
  for I := 0 to TileControl.Groups.Count - 1 do
    if TileControl.Groups[I].Visible then
    begin
      Result := TileControl.Groups[I];
      if I >= ADeletedGroupIndex then
        Break;
    end;
end;

function TdxTileControlController.GetNextObject(ADeletedItemIndex: Integer; ADeletedItemGroup: TdxTileControlGroup): TPersistent;
var
  I: Integer;
begin
  Result := TileControl;
  if ADeletedItemGroup = nil then Exit;
  Result := ADeletedItemGroup;
  ADeletedItemIndex := Min(ADeletedItemIndex, ADeletedItemGroup.ItemCount - 1);
  for I := 0 to ADeletedItemGroup.ItemCount - 1 do
    if ADeletedItemGroup.Items[I].Visible then
    begin
      Result := ADeletedItemGroup.Items[I];
      if I >= ADeletedItemIndex then
        Break;
    end;
end;

procedure TdxTileControlController.PopulateDesignPopupMenu;
begin
  FDesignWhatObjectsSelected := GetDesignTimeWhatSelected;
  case FDesignWhatObjectsSelected of
    tcdtwsItem, tcdtwsItems:
      begin
        PopulateOneItemDesignPopupMenu;
        FDesignPopupMenu.Items.Add(NewLine);
        if FDesignWhatObjectsSelected = tcdtwsItem then
        begin
          PopulateOneGroupDesignPopupMenu;
          FDesignPopupMenu.Items.Add(NewLine);
        end;
      end;
    tcdtwsGroup:
      begin
        PopulateOneGroupDesignPopupMenu;
        FDesignPopupMenu.Items.Add(NewLine);
      end;
  end;
  FDesignPopupMenu.Items.Add(AddPopupMenuItem('Delete', 0, 0, False, False, DeleteSelectedObjects));
end;

procedure TdxTileControlController.PopulateOneGroupDesignPopupMenu;
const
  AMenuItemCount = 3;
  AMenuItemCaption: array[0..AMenuItemCount - 1] of string =
    ('Add Regular Item', 'Add Large Item', 'Add Extra-Large Item');
var
  I: Integer;
begin
  for I := 0 to AMenuItemCount - 1 do
    FDesignPopupMenu.Items.Add(AddPopupMenuItem(AMenuItemCaption[I], I, 0, False, False, CreateTileControlItem));
end;

procedure TdxTileControlController.PopulateOneItemDesignPopupMenu;
const
  AMenuItemCount = 3;
  AMenuItemCaption: array[0..AMenuItemCount - 1] of string = ('Regular', 'Large', 'Extra-Large');
var
  I: Integer;
  AItem: TdxTileControlItem;
begin
  AItem := TdxTileControlItem(FDesignPopupMenuCaller);
  for I := 0 to AMenuItemCount - 1 do
    FDesignPopupMenu.Items.Add(AddPopupMenuItem(AMenuItemCaption[I], I, 1,
      GetDesignerMenuItemChecked(I, AItem), True, SwitchItemsProperty));
end;

procedure TdxTileControlController.ProcessDesignPopupMenu(ACaller: TcxComponentCollectionItem;
  AShift: TShiftState; APopupPoint: TPoint);
begin
  FreeAndNil(FDesignPopupMenu);
  if ssCtrl in AShift then
    AShift := AShift - [ssCtrl];
  if not IsObjectSelected(ACaller) then
    SelectObject(ACaller, AShift);
  if IsObjectSelected(ACaller) then
  begin
    FDesignPopupMenuCaller := ACaller;
    FDesignPopupMenu := TPopupMenu.Create(nil);
    try
      PopulateDesignPopupMenu;
      FDesignPopupMenu.Popup(APopupPoint.X, APopupPoint.Y);
      Application.ProcessMessages;
    finally
      FreeAndNil(FDesignPopupMenu);
    end;
  end;
end;

procedure TdxTileControlController.SwitchItemsProperty(Sender: TObject);
const
  ARowCount: array[Boolean] of Integer = (1, 2);
var
  AItem: TdxTileControlItem;
  AMenuItem: TMenuItem;
  I: Integer;
  AOldIsLarge, AHasChanges: Boolean;
  AOldRowCount: Integer;
begin
  AMenuItem := TMenuItem(Sender);
  TileControl.BeginUpdate;
  AHasChanges := False;
  try
    for I := 0 to TileControl.Items.Count - 1 do
    begin
      AItem := TileControl.Items[I];
      if IsObjectSelected(AItem) then
      begin
        AOldIsLarge := AItem.IsLarge;
        AOldRowCount := AItem.RowCount;
        AItem.IsLarge := AMenuItem.Tag in [1, 2];
        AItem.RowCount := ARowCount[AMenuItem.Tag = 2];
        AHasChanges := AHasChanges or
          (AOldIsLarge <> AItem.IsLarge) or (AOldRowCount <> AItem.RowCount);
      end;
    end;
  finally
    TileControl.EndUpdate;
  end;
  if AHasChanges then
    SetDesignerModified(TileControl);
end;

//
procedure TdxTileControlController.AddAnimation(Animation: TdxAnimationTransition);
begin
  FAnimations.Add(Animation);
  Animation.Resume;
end;

procedure TdxTileControlController.AfterAnimation(Sender: TdxAnimationController);

  procedure InvalidateItem(AItem: TdxTileControlItem);
  begin
    if not AItem.ViewInfo.Visible or not AItem.ViewInfo.Animation.PositionChanged then Exit;
    AItem.Refresh;
  end;

var
  I: Integer;
begin
  for I := 0 to AnimationItems.Count - 1 do
    InvalidateItem(TdxTileControlItem(AnimationItems[I]));
end;

procedure TdxTileControlController.AnimateItem(AItem: TdxTileControlItem);
begin
  if (AItem.ViewInfo.ViewData <> AItem.ActiveFrame.ViewData) and (AnimationItems.IndexOf(AItem) < 0) then
  begin
    AnimationItems.Add(AItem);
    AItem.CheckTimerEnabled;
    AItem.ViewInfo.ViewData.IsDirty := False;
    AItem.ActiveFrame.ViewData.IsDirty := False;
    AddAnimation(TdxTileControlFramesAnimation.Create(AItem));
  end;
end;

procedure TdxTileControlController.BeforeAnimation(Sender: TdxAnimationController);
begin
end;

procedure TdxTileControlController.DestroyAnimation(Animation: TdxAnimationTransition);
begin
  FAnimations.Remove(Animation);
end;

procedure TdxTileControlController.FrameDestroyed(AFrame: TdxTileControlItemFrame);
var
  AItem: TdxTileControlItem;
begin
  AItem := AFrame.TileItem;
  if AnimationItems.IndexOf(AItem) < 0 then Exit;
  StopFramesAnimation;
  if AItem.ViewInfo.ViewData = AFrame.ViewData then
    AItem.ViewInfo.ViewData := nil;
  AnimationItems.Remove(AItem);
  StartFramesAnimation;
end;

function TdxTileControlController.HitAtGroup: Boolean;
begin
  Result := HitTest.HitAtGroup or HitTest.HitAtGroupCaption;
end;

function TdxTileControlController.HitAtItem: Boolean;
begin
  Result := HitTest.HitAtItem;
end;

function TdxTileControlController.HitAtItemOrGroup: Boolean;
begin
  Result := HitAtItem or HitAtGroup;
end;

function TdxTileControlController.GetCanGroupMoving: Boolean;
begin
  Result := HitAtGroup and TileControl.OptionsBehavior.GroupMoving and (TileControl.Groups.Count > 1);
end;

function TdxTileControlController.GetCanItemMoving: Boolean;
var
  AAllow: Boolean;
begin
  Result := HitAtItem and TileControl.OptionsBehavior.ItemMoving and (TileControl.Items.Count > 1);
  if Result then
  begin
    AAllow := True;
    TileControl.DoItemDragBegin(AAllow);
    Result := AAllow;
  end;
end;

function TdxTileControlController.GetCheckedItems: TdxTileControlCheckedItems;
begin
  Result := TileControl.FCheckedItems;
end;

function TdxTileControlController.GetItemCheckMode: TdxTileControlItemCheckMode;
begin
  Result := TileControl.OptionsBehavior.ItemCheckMode;
end;

procedure TdxTileControlController.ImmediateAnimation(Animation: TdxAnimationTransition);
begin
  Animation.ImmediateAnimation;
end;

function TdxTileControlController.IsEnableDrawDragItemPlace: Boolean;
begin
  Result := ((TileControl.DraggedItem <> nil) or (ViewInfo.DragDropChanges <> nil)) and
    ((TdxTileControlDragDropItem(TileControl.DragAndDropObject).Place.Group <> nil) or
      not TdxTileControlDragDropItem(TileControl.DragAndDropObject).FDragOverIsAccepted);
end;

function TdxTileControlController.IsHandScrolling(ACheckedKind: TScrollBarKind): Boolean;
begin
  Result := TileControl.GetScrollBar(ACheckedKind).Visible and
    (TileControl.DragAndDropState = ddsInProcess) and
    (TileControl.DragAndDropObject is TdxTileControlHandScroll);
end;

procedure TdxTileControlController.ItemChecked(AItem: TdxTileControlItem);
begin
  if AItem.Checked then
    CheckedItems.Add(AItem)
  else
    CheckedItems.Remove(AItem);

  TileControl.DoItemCheck(AItem);
  AItem.Invalidate;

  CheckActionBarsState(AItem); 
end;

procedure TdxTileControlController.ItemDestroyed(AItem: TdxTileControlItem);
begin
  AnimationItems.Remove(AItem);
  CheckedItems.Remove(AItem);
  CheckActionBarsState(AItem);
  if FFocusedItem = AItem then
    FocusedItem := nil;
  if FHottrackedItem = AItem then
    FHottrackedItem := nil;
end;

procedure TdxTileControlController.RefreshItems;
begin
  HitTest.HitPoint := TileControl.ScreenToClient(GetMouseCursorPos);
  HottrackedItem := HitTest.Item;
end;

procedure TdxTileControlController.RestoreItemsBounds;
begin
  TerminateAnimations(False);
  TileControl.Items.ForEach(RestoreItemBounds, nil);
end;

procedure TdxTileControlController.TerminateAnimations(ATerminateFrames: Boolean);
var
  I: Integer;
  AAnimation: TdxAnimationTransition;
begin
  for I := Animations.Count - 1 downto 0 do
  begin
    AAnimation := TdxAnimationTransition(Animations[I]);
    if (AAnimation is TdxTileControlFramesAnimation) <> ATerminateFrames then Continue;
    if ATerminateFrames then
      TdxTileControlFramesAnimation(AAnimation).Item.Refresh;
    AAnimation.Terminate;
  end;
end;

function TdxTileControlController.GetHasAnimation_: Boolean;
begin
  Result := Animations.Count > 0;
end;

function TdxTileControlController.GetHitTest: TdxTileControlHitTest;
begin
  Result := FTileControl.HitTest;
end;

function TdxTileControlController.GetViewInfo: TdxTileControlViewInfo;
begin
  Result := TileControl.ViewInfo;
end;

procedure TdxTileControlController.HideActionBars;
begin
  TileControl.HideActionBars;
end;

procedure TdxTileControlController.HideScrollButtons;
begin
  ViewInfo.HideScrollButtons;
end;

// design selection
function TdxTileControlController.CanCreateSelectionHelper: Boolean;
begin
  Result := TileControl.IsDesigning and not TileControl.IsDestroying and
    not TileControl.IsLoading and (dxDesignHelperClass <> nil) and TileControl.HandleAllocated;
end;

function TdxTileControlController.CanShowActionBarsOnRightClick: Boolean;
begin
  Result := not ContextMenuHandled and (not HitAtItem or (ItemCheckMode = tcicmNone));
end;

function TdxTileControlController.CanToggleItemCheckOnRightClick: Boolean;
begin
  Result := not ContextMenuHandled;
end;

procedure TdxTileControlController.CheckActionBarsState(ACheckingItem: TdxTileControlItem);
begin
  if not (TileControl.IsDesigning or TileControl.IsDestroying) then
  begin
    if CheckedItems.IndexOf(ACheckingItem) >= 0 then  
      ShowActionBars
    else
      if CheckedItems.Count = 0 then  
        HideActionBars;    
  end;
end;

procedure TdxTileControlController.CheckCreateDesignHelper;
begin
  if CanCreateSelectionHelper then
    FDesignHelper := dxDesignHelperClass.Create(TileControl);
end;

procedure TdxTileControlController.DestroyDesignHelper;
begin
  FreeAndNil(FDesignHelper);
end;

function TdxTileControlController.IsObjectSelected(AObject: TPersistent): Boolean;
begin
  Result := (DesignHelper <> nil) and DesignHelper.IsObjectSelected(AObject);
end;

procedure TdxTileControlController.SelectObject(AObject: TPersistent; AShift: TShiftState);
begin
  if DesignHelper <> nil then
    DesignHelper.Select(AObject, AShift);
end;

procedure TdxTileControlController.UncheckAllItems;
var
  I: Integer;
begin
  for I := TileControl.CheckedItemCount - 1 downto 0 do
    TileControl.CheckedItems[I].Checked := False;
end;

procedure TdxTileControlController.UnselectObject(AObject: TPersistent);
begin
  if DesignHelper <> nil then
    DesignHelper.UnselectObject(AObject);
end;

procedure TdxTileControlController.MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  MouseDownWasHandled := True;
  HitTest.Calculate(X, Y);
  FContextMenuHandled := False;
  if FramesAnimationLockCount = 0 then
    StopFramesAnimation;
  FMouseDownItem := HitTest.Item;
  HottrackedItem := FMouseDownItem;
  if TileControl.IsDesigning and TileControl.FRightButtonPressed then
    CheckDesignPopupMenu(Shift)
  else
    if Button = mbLeft then
    begin
      if HitAtGroup then
        SelectObject(HitTest.Group, Shift)
      else
        if HitAtItem then
        begin
          if not (TileControl.IsDesigning or IsTouchEvent) then
            TdxTileControlInflateItemAnimation.Create(TileControl, HitTest.Item, -1, 3).ImmediateAnimation;
          SelectObject(HitTest.Item, Shift);
        end;

      if HitTest.Item <> nil then
        FocusedItem := HitTest.Item;
      if HitTest.HitAtScrollButton then
        PressedScrollButton := HitTest.ScrollButton;
    end;
end;

procedure TdxTileControlController.MouseLeave;
begin
  EndMouseTracking(Self);
end;

procedure TdxTileControlController.MouseMove(Shift: TShiftState; X, Y: Integer);
var
  APrevPoint: TPoint;
begin
  if TileControl.DragAndDropState = ddsNone then
  begin
    APrevPoint := HitTest.HitPoint;
    HitTest.Calculate(X, Y);
    if (FocusedItem = nil) or not cxPointIsEqual(APrevPoint, Point(X, Y)) then
      HottrackedItem := HitTest.Item;
    BeginMouseTracking(TileControl, TileControl.ClientBounds, Self);
  end;
end;

procedure TdxTileControlController.MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  if not MouseDownWasHandled then Exit;
  HitTest.Calculate(X, Y);
  RestoreItemsBounds;
  if HitAtItem and (HitTest.Item = FMouseDownItem) then
  begin
    if Button = mbLeft then
      HitTest.Item.Click;
    if (Button = mbRight) and CanToggleItemCheckOnRightClick then
      HitTest.Item.ToggleChecked;
  end;

  if CheckedItems.Count = 0 then
  begin
    if (Button = mbRight) and CanShowActionBarsOnRightClick then
      ToggleActionBars
    else
      HideActionBars;
  end;

  if Button = mbLeft  then
    ChangePressedScrollButtonState;
  if FramesAnimationLockCount <> 0 then
    StartFramesAnimation;
  MouseDownWasHandled := False;
end;

function TdxTileControlController.PtInCaller(const P: TPoint): Boolean;
begin
  Result := PtInRect(TileControl.ClientBounds, P);
end;

{ TdxTileControlHitTest }

constructor TdxTileControlHitTest.Create(AOwner: TdxCustomTileControl);
begin
  inherited Create;
  FOwner := AOwner;
end;

procedure TdxTileControlHitTest.Calculate(const X, Y: Integer);
begin
  HitPoint := Point(X, Y);
end;

procedure TdxTileControlHitTest.Clear;
begin
  HitObject := nil;
  Flags := 0;
end;

function TdxTileControlHitTest.GetActiveViewInfo: TdxTileControlCustomViewInfo;
begin
  if TileControl.ActiveDetail <> nil then
    Result := TileControl.ActiveDetail.TitleViewInfo
  else
    Result := TileControl.ViewInfo;
end;

function TdxTileControlHitTest.GetBitState(AIndex: Integer): Boolean;
begin
  Result := (Flags and (1 shl AIndex)) <> 0;
end;

function TdxTileControlHitTest.GetController: TdxTileControlController;
begin
  Result := TileControl.Controller;
end;

function TdxTileControlHitTest.GetGroup: TdxTileControlGroup;
begin
  if (HitObject is TdxTileControlGroupViewInfo) or (HitObject is TdxTileControlGroupCaptionViewInfo) then
    if HitObject is TdxTileControlGroupViewInfo then
      Result := TdxTileControlGroupViewInfo(HitObject).Group
    else
      Result := TdxTileControlGroupCaptionViewInfo(HitObject).Group
  else
    if Item <> nil then
      Result := Item.Group
    else
      Result := nil;
end;

function TdxTileControlHitTest.GetItem: TdxTileControlItem;
begin
  if HitObject is TdxTileControlItemViewInfo then
    Result := TdxTileControlItemViewInfo(HitObject).Item
  else
    Result := nil;
end;

function TdxTileControlHitTest.GetPosValue(const AIndex: Integer): Integer;
begin
  if AIndex = 0 then
    Result := FHitPoint.X
  else
    Result := FHitPoint.Y
end;

function TdxTileControlHitTest.GetScrollButton: TdxTileControlScrollButtonViewInfo;
begin
  if HitObject is TdxTileControlScrollButtonViewInfo then
    Result := TdxTileControlScrollButtonViewInfo(HitObject)
  else
    Result := nil;
end;

procedure TdxTileControlHitTest.SetBitState(AIndex: Integer; AValue: Boolean);
begin
  if AValue then
    Flags := Flags or (1 shl AIndex)
  else
    Flags := Flags and not (1 shl AIndex);
end;

procedure TdxTileControlHitTest.SetHitObject(AValue: TObject);
begin
  if FHitObject <> AValue then
  begin
    Flags := 0;
    FHitObject := AValue;
  end;
end;

procedure TdxTileControlHitTest.Recalculate;
var
  APrevHitObject: TObject;
begin
  APrevHitObject := HitObject;
  Clear;
  ActiveViewInfo.GetHitTest(Self);
  if APrevHitObject <> HitObject then
    ActiveViewInfo.RefreshState;
end;

procedure TdxTileControlHitTest.SetHitPoint(const AValue: TPoint);
begin
  FHitPoint := AValue;
  Recalculate;
end;

procedure TdxTileControlHitTest.SetPosValue(const AIndex, AValue: Integer);
begin
  if AIndex = 0 then
    FHitPoint.X := AValue
  else
    FHitPoint.Y := AValue;
  Recalculate;
end;

{ TdxTileControlCellNavigator }

constructor TdxTileControlItemNavigator.Create(AController: TdxTileControlController);
begin
  FController := AController;
  FPosition := TdxLayoutItemPosition.Create;
end;

destructor TdxTileControlItemNavigator.Destroy;
begin
  FreeAndNil(FPosition);
  inherited Destroy;
end;

function TdxTileControlItemNavigator.GetCurrentNavigationItem: TdxTileControlItem;
begin
  Result := Controller.FocusedItem;
end;

function TdxTileControlItemNavigator.GetCurrentNavigationItemColumn: Integer;
begin
  Result := CurrentNavigationItem.ViewInfo.Position.Column;
end;

function TdxTileControlItemNavigator.GetCurrentNavigationItemRow: Integer;
begin
  Result := CurrentNavigationItem.ViewInfo.Position.Row;
end;

function TdxTileControlItemNavigator.GetFirstItem: TdxTileControlItem;
var
  I, J: Integer;
  AItem: TdxTileControlItem;
  AGroup: TdxTileControlGroup;
begin
  Result := CurrentNavigationItem;
  for I := 0 to Groups.Count - 1 do
  begin
    AGroup := Groups[I];
    if AGroup.Visible then
      for J := 0 to AGroup.ItemCount - 1 do
      begin
        AItem := AGroup.Items[J];
        if AItem.Visible then
        begin
          Result := AItem;
          Break;
        end;
      end;
    if Result <> CurrentNavigationItem then Break;
  end;
end;

function TdxTileControlItemNavigator.GetFirstItemInRow: TdxTileControlItem;
var
  I, AEndColumn: Integer;
  AGroup, ACurrentGroup: TdxTileControlGroup;
  APosition: TdxLayoutItemPosition;
  AItem: TdxTileControlItem;
begin
  Result := CurrentNavigationItem;
  APosition := TdxLayoutItemPosition.Create;
  try
    APosition.Row := CurrentNavigationItemRow;
    APosition.Column := 0;
    ACurrentGroup := CurrentNavigationItem.Group;
    if GroupLayout = glVertical then
    begin
      AItem := GetItemByForwardSearchOnColumns(ACurrentGroup, APosition, CurrentNavigationItemColumn - 1);
      if AItem <> nil then
        Result := AItem;
    end
    else
      for I := 0 to ACurrentGroup.Index do
      begin
        AGroup := Groups[I];
        if AGroup.Visible then
        begin
          if I = ACurrentGroup.Index then
            AEndColumn := CurrentNavigationItemColumn - 1
          else
            AEndColumn := AGroup.RealColumnCount - 1;
          AItem := GetItemByForwardSearchOnColumns(AGroup, APosition, AEndColumn);
          if AItem <> nil then
          begin
            Result := AItem;
            Break;
          end;
        end;
      end;
  finally
    APosition.Free;
  end;
end;

function TdxTileControlItemNavigator.GetItemByBackSearchOnColumns(
  AGroup: TdxTileControlGroup; AOriginalPosition: TdxLayoutItemPosition;
  const AEndColumn: Integer): TdxTileControlItem;
var
  AItem: TdxTileControlItem;
  AColumn: Integer;
begin
  Result := nil;
  for AColumn := AOriginalPosition.Column downto AEndColumn do
  begin
    AOriginalPosition.Column := AColumn;
    AItem := GetOccupiedItem(AOriginalPosition, AGroup);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
end;

function TdxTileControlItemNavigator.GetItemByBackSearchOnRows(
  AGroup: TdxTileControlGroup; AOriginalPosition: TdxLayoutItemPosition;
  const AEndRow: Integer): TdxTileControlItem;
var
  AItem: TdxTileControlItem;
  ARow : Integer;
begin
  Result := nil;
  for ARow := AOriginalPosition.Row downto AEndRow do
  begin
    AOriginalPosition.Row := ARow;
    AItem := GetOccupiedItem(AOriginalPosition, AGroup);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
end;

function TdxTileControlItemNavigator.GetItemByForwardSearchOnColumns(
  AGroup: TdxTileControlGroup; AOriginalPosition: TdxLayoutItemPosition;
  const AEndColumn: Integer): TdxTileControlItem;
var
  AItem: TdxTileControlItem;
  AColumn, AInputColumn : Integer;
begin
  Result := nil;
  AInputColumn := AOriginalPosition.Column;
  for AColumn := AOriginalPosition.Column to AEndColumn do
  begin
    AOriginalPosition.Column := AColumn;
    AItem := GetOccupiedItem(AOriginalPosition, AGroup);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
  AOriginalPosition.Column := AInputColumn;
end;

function TdxTileControlItemNavigator.GetItemByForwardSearchOnRows(
  AGroup: TdxTileControlGroup; AOriginalPosition: TdxLayoutItemPosition;
  const AEndRow: Integer): TdxTileControlItem;
var
  AItem: TdxTileControlItem;
  ARow, AInputRow : Integer;
begin
  Result := nil;
  AInputRow := AOriginalPosition.Row;
  for ARow := AOriginalPosition.Row to AEndRow do
  begin
    AOriginalPosition.Row := ARow;
    AItem := GetOccupiedItem(AOriginalPosition, AGroup);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
  AOriginalPosition.Row := AInputRow;
end;

function TdxTileControlItemNavigator.GetLastItem: TdxTileControlItem;
var
  I, J: Integer;
  AItem: TdxTileControlItem;
  AGroup: TdxTileControlGroup;
begin
  Result := CurrentNavigationItem;
  for I := Groups.Count - 1 downto 0 do
  begin
    AGroup := Groups[I];
    if AGroup.Visible then
      for J := AGroup.ItemCount - 1 downto 0 do
      begin
        AItem := AGroup.Items[J];
        if AItem.Visible then
        begin
          Result := AItem;
          Break;
        end;
      end;
    if Result <> CurrentNavigationItem then Break;
  end;
end;

function TdxTileControlItemNavigator.GetLastItemInRow: TdxTileControlItem;
var
  I, AEndColumn: Integer;
  AGroup, ACurrentGroup: TdxTileControlGroup;
  APosition: TdxLayoutItemPosition;
  AItem: TdxTileControlItem;
begin
  Result := CurrentNavigationItem;
  APosition := TdxLayoutItemPosition.Create;
  try
    APosition.Row := CurrentNavigationItemRow;
    ACurrentGroup := CurrentNavigationItem.Group;
    if GroupLayout = glVertical then
    begin
      APosition.Column := ACurrentGroup.ViewInfo.ColumnCount - 1;
      AItem := GetItemByBackSearchOnColumns(ACurrentGroup, APosition,
        CurrentNavigationItemColumn + 1 + Ord(CurrentNavigationItem.IsLarge));
      if AItem <> nil then
        Result := AItem;
    end
    else
      for I := Groups.Count - 1 downto ACurrentGroup.Index do
      begin
        AGroup := Groups[I];
        if AGroup.Visible then
        begin
          if I = ACurrentGroup.Index then
            AEndColumn := CurrentNavigationItemColumn + 1 + Ord(CurrentNavigationItem.IsLarge)
          else
            AEndColumn := 0;
          APosition.Column := AGroup.RealColumnCount - 1;
          AItem := GetItemByBackSearchOnColumns(AGroup, APosition, AEndColumn);
          if AItem <> nil then
          begin
            Result := AItem;
            Break;
          end;
        end;
      end;
  finally
    APosition.Free;
  end;
end;

function TdxTileControlItemNavigator.GetNextItemInColumnAboveTheCurrentWhenHorizontalLayout(
  APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  AItem: TdxTileControlItem;
begin
  Result := nil;
  AItem := GetItemByForwardSearchOnRows(Groups[ACurrentGroupIndex], APosition, CurrentNavigationItemRow - 1);
  if AItem <> nil then
    Result := AItem;
end;

function TdxTileControlItemNavigator.GetNextItemInColumnAboveTheCurrentWhenVerticalLayout(APosition: TdxLayoutItemPosition;
  ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I, AEndRow: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  for I := 0 to ACurrentGroupIndex do
  begin
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    if I = ACurrentGroupIndex then
      AEndRow := CurrentNavigationItemRow - 1
    else
      AEndRow := AGroup.RealRowCount - 1;
    AItem := GetItemByForwardSearchOnRows(AGroup, APosition, AEndRow);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
end;

function TdxTileControlItemNavigator.GetNextItemInColumnBelowTheCurrent(APosition: TdxLayoutItemPosition;
  ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  for I := ACurrentGroupIndex to Groups.Count - 1 do
  begin
    if (GroupLayout = glHorizontal) and (I <> ACurrentGroupIndex) then Break;
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    AItem := GetItemByForwardSearchOnRows(AGroup, APosition, AGroup.RealRowCount - 1);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
    APosition.Row := 0;
  end;
end;

function TdxTileControlItemNavigator.GetNextItemInColumn: TdxTileControlItem;
var
  ACurrentGroupIndex: Integer;
  AStartPosition: TdxLayoutItemPosition;
  AItem: TdxTileControlItem;
begin
  Result := CurrentNavigationItem;
  AStartPosition := TdxLayoutItemPosition.Create;
  try
    AStartPosition.Column := CurrentNavigationItemColumn;
    AStartPosition.Row := CurrentNavigationItemRow + CurrentNavigationItem.RowCount;
    ACurrentGroupIndex := CurrentNavigationItem.Group.Index;
    AItem := GetNextItemInColumnBelowTheCurrent(AStartPosition, ACurrentGroupIndex);
    if AItem <> nil then
      Result := AItem;
    if (Result = CurrentNavigationItem) and FFocusItemOnCycle then
    begin
      AStartPosition.Row := 0;
      if GroupLayout = glHorizontal then
        AItem := GetNextItemInColumnAboveTheCurrentWhenHorizontalLayout(AStartPosition, ACurrentGroupIndex)
      else
        AItem := GetNextItemInColumnAboveTheCurrentWhenVerticalLayout(AStartPosition, ACurrentGroupIndex);
      if AItem <> nil then
        Result := AItem;
    end;
  finally
    AStartPosition.Free;
  end;
end;

function TdxTileControlItemNavigator.GetNextItemInNextRowWhenHorizontalLayout(APosition: TdxLayoutItemPosition;
  ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I: Integer;
  AEndColumn: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  for I := 0 to ACurrentGroupIndex do
  begin
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    if I = ACurrentGroupIndex then
      AEndColumn := CurrentNavigationItemColumn - 1
    else
      AEndColumn := AGroup.RealColumnCount - 1;
    AItem := GetItemByForwardSearchOnColumns(AGroup, APosition, AEndColumn);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
end;

function TdxTileControlItemNavigator.GetNextItemInNextRowWhenVerticalLayout(APosition: TdxLayoutItemPosition;
  ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I, ARow, AStartRow: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  AStartRow := APosition.Row;
  for I := ACurrentGroupIndex to Groups.Count - 1 do
  begin
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    for ARow := 0 to AGroup.RealRowCount - 1 do
    begin
      if (ARow < AStartRow) and (I = ACurrentGroupIndex) then Continue;
      AItem := GetItemByForwardSearchOnColumns(AGroup, APosition, AGroup.RealColumnCount - 1);
      if AItem <> nil then
      begin
        Result := AItem;
        Break;
      end;
    end;
    if Result <> nil then Break;
    APosition.Row := 0;
    APosition.Column := 0;
  end;
end;

function TdxTileControlItemNavigator.GetNextItemInRow: TdxTileControlItem;
var
  ACurrentGroupIndex: Integer;
  AStartPosition: TdxLayoutItemPosition;
  AItem: TdxTileControlItem;
begin
  Result := CurrentNavigationItem;
  AStartPosition := TdxLayoutItemPosition.Create;
  try
    AStartPosition.Row := CurrentNavigationItemRow + FCurrentNavigationItemOccupiedRow;
    AStartPosition.Column := CurrentNavigationItemColumn + 1 + Ord(CurrentNavigationItem.IsLarge);
    ACurrentGroupIndex := CurrentNavigationItem.Group.Index;
    AItem := GetNextItemInRowToRightHand(AStartPosition, ACurrentGroupIndex);
    if AItem <> nil then
      Result := AItem;
    if (Result = CurrentNavigationItem) and FFocusItemOnCycle then
    begin
      AStartPosition.Column := 0;
      AStartPosition.Row := AStartPosition.Row + 1;
      if GroupLayout = glHorizontal then
        AItem := GetNextItemInNextRowWhenHorizontalLayout(AStartPosition, ACurrentGroupIndex)
      else
        AItem := GetNextItemInNextRowWhenVerticalLayout(AStartPosition, ACurrentGroupIndex);
      if AItem <> nil then
        Result := AItem;
    end;
  finally
    AStartPosition.Free;
  end;
end;

function TdxTileControlItemNavigator.GetNextItemInRowToRightHand(APosition: TdxLayoutItemPosition;
  ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I: Integer;
  AEndColumn: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  for I := ACurrentGroupIndex to Groups.Count - 1 do
  begin
    if (GroupLayout = glVertical) and (I <> ACurrentGroupIndex) then Break;
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    AEndColumn := AGroup.RealColumnCount - 1;
    AItem := GetItemByForwardSearchOnColumns(AGroup, APosition, AEndColumn);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
    APosition.Column := 0;
  end;
end;

function TdxTileControlItemNavigator.GetOccupiedItem(APosition: TdxLayoutItemPosition;
  AGroup: TdxTileControlGroup): TdxTileControlItem;
var
  I: Integer;
  AOccupiedRow: Integer;
begin
  Result := nil;
  for I := 0 to AGroup.ItemCount - 1 do
    if AGroup.ViewInfo.IsItemOccupyPosition(AGroup.Items[I], APosition, AOccupiedRow) then
    begin
      Result := AGroup.Items[I];
      FCurrentNavigationItemOccupiedRow := AOccupiedRow;
      Break;
    end;
end;

function TdxTileControlItemNavigator.GetPrevItemInColumn: TdxTileControlItem;
var
  ACurrentGroupIndex: Integer;
  AStartPosition: TdxLayoutItemPosition;
  AItem: TdxTileControlItem;
begin
  Result := CurrentNavigationItem;
  AStartPosition := TdxLayoutItemPosition.Create;
  try
    AStartPosition.Column := CurrentNavigationItemColumn;
    ACurrentGroupIndex := CurrentNavigationItem.Group.Index;
    AItem := GetPrevItemInColumnAboveTheCurrent(AStartPosition, ACurrentGroupIndex);
    if AItem <> nil then
      Result := AItem;
    if (Result = CurrentNavigationItem) and FFocusItemOnCycle then
    begin
      if GroupLayout = glHorizontal then
        AItem := GetPrevItemInColumnBelowTheCurrentWhenHorizontalLayout(AStartPosition, ACurrentGroupIndex)
      else
        AItem := GetPrevItemInColumnBelowTheCurrentWhenVerticalLayout(AStartPosition, ACurrentGroupIndex);
      if AItem <> nil then
        Result := AItem;
    end;
  finally
    AStartPosition.Free;
  end;
end;

function TdxTileControlItemNavigator.GetPrevItemInColumnBelowTheCurrentWhenHorizontalLayout(
  APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  AItem: TdxTileControlItem;
  AGroup: TdxTileControlGroup;
begin
  Result := nil;
  AGroup := Groups[ACurrentGroupIndex];
  APosition.Row := AGroup.RealRowCount;
  AItem := GetItemByBackSearchOnRows(AGroup, APosition, CurrentNavigationItemRow + 1);
  if AItem <> nil then
    Result := AItem;
end;

function TdxTileControlItemNavigator.GetPrevItemInColumnBelowTheCurrentWhenVerticalLayout(
  APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I, AEndRow: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  for I := Groups.Count - 1 downto ACurrentGroupIndex do
  begin
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    APosition.Row := AGroup.RealRowCount - 1;
    if I = ACurrentGroupIndex then
      AEndRow := CurrentNavigationItemRow + CurrentNavigationItem.RowCount
    else
      AEndRow := 0;
    AItem := GetItemByBackSearchOnRows(AGroup, APosition, AEndRow);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
end;

function TdxTileControlItemNavigator.GetPrevItemInColumnAboveTheCurrent(
  APosition: TdxLayoutItemPosition; ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  for I := ACurrentGroupIndex downto 0 do
  begin
    if (GroupLayout = glHorizontal) and (I <> ACurrentGroupIndex) then Break;
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    if I = ACurrentGroupIndex then
      APosition.Row := CurrentNavigationItemRow - 1
    else
      APosition.Row := AGroup.RealColumnCount - 1;
    AItem := GetItemByBackSearchOnRows(AGroup, APosition, 0);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
end;

function TdxTileControlItemNavigator.GetPrevItemInPrevRowWhenHorizontalLayout(APosition: TdxLayoutItemPosition;
  ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I: Integer;
  AEndColumn: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  for I := Groups.Count - 1 downto ACurrentGroupIndex do
  begin
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    APosition.Column := AGroup.RealColumnCount - 1;
    if I = ACurrentGroupIndex then
      AEndColumn := CurrentNavigationItemColumn + 1 + Ord(CurrentNavigationItem.IsLarge)
    else
      AEndColumn := 0;
    AItem := GetItemByBackSearchOnColumns(AGroup, APosition, AEndColumn);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
end;

function TdxTileControlItemNavigator.GetPrevItemInPrevRowWhenVerticalLayout(APosition: TdxLayoutItemPosition;
  ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I, ARow, AStartRow: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  AStartRow := APosition.Row;
  for I := ACurrentGroupIndex downto 0 do
  begin
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    for ARow := AGroup.RealRowCount - 1 downto 0 do
    begin
      if (ARow > AStartRow) and (I = ACurrentGroupIndex) then Continue;
      APosition.Row := ARow;
      APosition.Column := AGroup.RealColumnCount - 1;
      AItem := GetItemByBackSearchOnColumns(AGroup, APosition, 0);
      if AItem <> nil then
      begin
        Result := AItem;
        Break;
      end;
    end;
    if Result <> nil then Break;
  end;
end;

function TdxTileControlItemNavigator.GetPrevItemInRow: TdxTileControlItem;
var
  ACurrentGroupIndex: Integer;
  AStartPosition: TdxLayoutItemPosition;
  AItem: TdxTileControlItem;
begin
  Result := CurrentNavigationItem;
  AStartPosition := TdxLayoutItemPosition.Create;
  try
    AStartPosition.Row := CurrentNavigationItemRow + FCurrentNavigationItemOccupiedRow;
    ACurrentGroupIndex := CurrentNavigationItem.Group.Index;
    AItem := GetPrevItemInRowToLeftHand(AStartPosition, ACurrentGroupIndex);
    if AItem <> nil then
      Result := AItem;
    if (Result = CurrentNavigationItem) and FFocusItemOnCycle then
    begin
      AStartPosition.Row := AStartPosition.Row - 1;
      if GroupLayout = glHorizontal then
        AItem := GetPrevItemInPrevRowWhenHorizontalLayout(AStartPosition, ACurrentGroupIndex)
      else
        AItem := GetPrevItemInPrevRowWhenVerticalLayout(AStartPosition, ACurrentGroupIndex);
      if AItem <> nil then
        Result := AItem;
    end;
  finally
    AStartPosition.Free;
  end;
end;

function TdxTileControlItemNavigator.GetPrevItemInRowToLeftHand(APosition: TdxLayoutItemPosition;
  ACurrentGroupIndex: Integer): TdxTileControlItem;
var
  I: Integer;
  AGroup: TdxTileControlGroup;
  AItem: TdxTileControlItem;
begin
  Result := nil;
  for I := ACurrentGroupIndex downto 0 do
  begin
    if (GroupLayout = glVertical) and (I <> ACurrentGroupIndex) then Break;
    AGroup := Groups[I];
    if not AGroup.Visible then Continue;
    if I = ACurrentGroupIndex then
      APosition.Column := CurrentNavigationItemColumn - 1
    else
      APosition.Column := AGroup.RealColumnCount - 1;
    AItem := GetItemByBackSearchOnColumns(AGroup, APosition, 0);
    if AItem <> nil then
    begin
      Result := AItem;
      Break;
    end;
  end;
end;

function TdxTileControlItemNavigator.GetGroupLayout: TdxTileControlGroupLayout;
begin
  Result := Controller.TileControl.OptionsView.GroupLayout;
end;

function TdxTileControlItemNavigator.GetGroups: TdxTileControlGroupCollection;
begin
  Result := Controller.TileControl.Groups;
end;

function TdxTileControlItemNavigator.IsAcceptedKey(Key: Word): Boolean;
begin
  Result := Key in [VK_END, VK_HOME, VK_LEFT, VK_UP, VK_RIGHT, VK_DOWN];
end;

procedure TdxTileControlItemNavigator.KeyDown(var Key: Word; Shift: TShiftState);
begin
  FFocusItemOnCycle := Controller.TileControl.OptionsBehavior.FocusItemOnCycle;
  if CurrentNavigationItem = nil then
    SaveCurrentNavigationItem;
  if CurrentNavigationItem <> nil then
  case Key of
    VK_HOME:
      if [ssCtrl] * Shift <> [] then
        CurrentNavigationItem := GetFirstItem
      else
        CurrentNavigationItem := GetFirstItemInRow;
    VK_LEFT:
      CurrentNavigationItem := GetPrevItemInRow;
    VK_UP:
      CurrentNavigationItem := GetPrevItemInColumn;
    VK_RIGHT:
      CurrentNavigationItem := GetNextItemInRow;
    VK_DOWN:
      CurrentNavigationItem := GetNextItemInColumn;
  else
    if [ssCtrl] * Shift <> [] then
      CurrentNavigationItem := GetLastItem
    else
      CurrentNavigationItem := GetLastItemInRow;
  end;
  Key := 0;
  CurrentNavigationItem.MakeVisible;
end;

procedure TdxTileControlItemNavigator.SaveCurrentNavigationItem;
var
  I, J:  Integer;
  AGroup: TdxTileControlGroup;
begin
  if Controller.TileControl.IsDesigning then Exit;
  if CurrentNavigationItem =  nil then
    for I := 0 to Groups.Count - 1 do
    begin
      AGroup := Groups[I];
      if AGroup.Visible then
      for J := 0 to AGroup.ItemCount - 1 do
        if AGroup.Items[J].Visible then
        begin
          CurrentNavigationItem := AGroup.Items[J];
          Break;
        end;
      if CurrentNavigationItem <> nil then Break;
    end;
  FCurrentNavigationItemOccupiedRow := 0;
end;

procedure TdxTileControlItemNavigator.SetCurrentNavigationItem(AValue: TdxTileControlItem);
begin
  Controller.FocusedItem := AValue;
end;

{ TdxTileControlOptionsBehavior }

constructor TdxTileControlOptionsBehavior.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FGroupMoving := False;
  FFocusItemOnCycle := True;
  FItemMoving := True;
  FBackgroundScrollSync := dxTileControlDefaultScrollSync;
  FItemHotTrack := True;
  FScrollMode := smScrollbars;
  FItemCheckMode := tcicmMultiple;
end;

procedure TdxTileControlOptionsBehavior.Assign(ASource: TPersistent);
var
  ASourceOptionsBehavior: TdxTileControlOptionsBehavior;
begin
  if ASource is TdxTileControlOptionsBehavior then
  begin
    ASourceOptionsBehavior := TdxTileControlOptionsBehavior(ASource);
    FBackgroundScrollSync := ASourceOptionsBehavior.FBackgroundScrollSync;
    FItemCheckMode := ASourceOptionsBehavior.ItemCheckMode;
    FFocusItemOnCycle := ASourceOptionsBehavior.FFocusItemOnCycle;
    FGroupMoving := ASourceOptionsBehavior.FGroupMoving;
    FHideFocusOnItemHotTrack := ASourceOptionsBehavior.HideFocusOnItemHotTrack;
    FItemHotTrack := ASourceOptionsBehavior.ItemHotTrack;
    FItemMoving := ASourceOptionsBehavior.FItemMoving;
  end
  else
    inherited Assign(ASource);
end;

procedure TdxTileControlOptionsBehavior.Changed;
begin
  TileControl.AddChanges([tccLayout]);
  TileControl.LayoutChanged;
end;

function TdxTileControlOptionsBehavior.GetTileControl: TdxCustomTileControl;
begin
  Result := TdxCustomTileControl(GetOwner);
end;

procedure TdxTileControlOptionsBehavior.SetBackgroundScrollSync(AValue: Byte);
begin
  AValue := Min(100, Max(0, AValue));
  if AValue <> FBackgroundScrollSync then
  begin
    FBackgroundScrollSync := AValue;
    TileControl.Invalidate;
  end;
end;

procedure TdxTileControlOptionsBehavior.SetItemCheckMode(AValue: TdxTileControlItemCheckMode);
begin
  if FItemCheckMode <> AValue then
  begin
    FItemCheckMode := AValue;
    TileControl.Controller.UncheckAllItems;
  end;
end;

procedure TdxTileControlOptionsBehavior.SetScrollMode(AValue: TdxTileControlScrollMode);
begin
  if FScrollMode <> AValue then
  begin
    FScrollMode := AValue;
    Changed;
  end;
end;

{ TdxTileControlOptionsView }

constructor TdxTileControlOptionsView.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FGroupIndent := dxTileControlDefaultGroupIndent;
  FIndentHorz := dxTileControlDefaultIndentHorz;
  FIndentVert := dxTileControlDefaultIndentVert;
  FItemIndent := dxTileControlDefaultItemIndent;
  FItemSize := dxTileControlDefaultItemSize;
  FGroupLayout := glHorizontal;
  FGroupMaxRowCount := dxTileControlDefaultRowCount;
  FVirtualGroupWidth := GetVirtualGroupWidth(FGroupIndent, FItemIndent);
end;

procedure TdxTileControlOptionsView.Assign(ASource: TPersistent);
var
  ASourceOptionsView: TdxTileControlOptionsView;
begin
  if ASource is TdxTileControlOptionsView then
  begin
    ASourceOptionsView := TdxTileControlOptionsView(ASource);
    FIndentHorz := ASourceOptionsView.IndentHorz;
    FIndentVert := ASourceOptionsView.IndentVert;
    FItemIndent := ASourceOptionsView.FItemIndent;
    FItemSize := ASourceOptionsView.FItemSize;
    FGroupLayout := ASourceOptionsView.FGroupLayout;
    FGroupMaxRowCount := ASourceOptionsView.FGroupMaxRowCount;
  end
  else
    inherited Assign(ASource);
end;

procedure TdxTileControlOptionsView.Changed;
begin
  TileControl.AddChanges([tccLayout]);
end;

function TdxTileControlOptionsView.GetMaxItemRowCount: Integer;
var
  I: Integer;
begin
  Result := 1;
  for I := 0 to TileControl.Items.Count - 1 do
    if TileControl.Items[I].RowCount > Result then
      Result := TileControl.Items[I].RowCount;
end;

function TdxTileControlOptionsView.GetVirtualGroupWidth(const AGroupIndent, AItemIndent: Integer): Integer;
begin
  Result := AGroupIndent - 2 * AItemIndent;
end;

function TdxTileControlOptionsView.GetTileControl: TdxCustomTileControl;
begin
  Result := TdxCustomTileControl(Owner);
end;

procedure TdxTileControlOptionsView.SetCenterContentHorz(AValue: Boolean);
begin
  if FCenterContentHorz <> AValue then
  begin
    FCenterContentHorz := AValue;
    Changed;
  end;
end;

procedure TdxTileControlOptionsView.SetCenterContentVert(AValue: Boolean);
begin
  if FCenterContentVert <> AValue then
  begin
    FCenterContentVert := AValue;
    Changed;
  end;
end;

procedure TdxTileControlOptionsView.SetGroupIndent(AValue: Integer);
begin
  if (FGroupIndent <> AValue) and (GetVirtualGroupWidth(AValue, FItemIndent) > FItemIndent) then
  begin
    FGroupIndent := AValue;
    FVirtualGroupWidth := GetVirtualGroupWidth(FGroupIndent, FItemIndent);
    Changed;
  end;
end;

procedure TdxTileControlOptionsView.SetIndentHorz(AValue: Integer);
begin
  if FIndentHorz <> AValue then
  begin
    FIndentHorz := AValue;
    Changed;
  end;
end;

procedure TdxTileControlOptionsView.SetIndentVert(AValue: Integer);
begin
  if FIndentVert <> AValue then
  begin
    FIndentVert := AValue;
    Changed;
  end;
end;

procedure TdxTileControlOptionsView.SetItemIndent(AValue: Integer);
begin
  if (FItemIndent <> AValue) and (GetVirtualGroupWidth(FGroupIndent, AValue) > AValue) then
  begin
    FItemIndent := AValue;
    FVirtualGroupWidth := GetVirtualGroupWidth(FGroupIndent, FItemIndent);
    TileControl.AddChanges([tccLayout, tccItems]);
  end;
end;

procedure TdxTileControlOptionsView.SetItemSize(AValue: Integer);
begin
  if FItemSize <> AValue then
  begin
    FItemSize := AValue;
    TileControl.AddChanges([tccLayout, tccItems]);
  end;
end;

procedure TdxTileControlOptionsView.SetGroupLayout(AValue: TdxTileControlGroupLayout);
begin
  if FGroupLayout <> AValue then
  begin
    FGroupLayout := AValue;
    Changed;
  end;
end;

procedure TdxTileControlOptionsView.SetGroupMaxRowCount(AValue: Integer);
begin
  AValue := Max(AValue, GetMaxItemRowCount);
  if FGroupMaxRowCount <> AValue then
  begin
    FGroupMaxRowCount := AValue;
    Changed;
  end;
end;

{ TdxTileControlTitle }

constructor TdxTileControlTitle.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FFont := TFont.Create;
  FFont.Color := clDefault;
  FFont.Name := DefaultFontName;
  FFont.Size := dxTileControlDefaultTitleFontSize;
  FFont.OnChange := FontChanged;
  FTabsFontSize := dxTileControlDefaultTabFontSize;
  FTabsActiveTextColor := clDefault;
  FTabsHotTextColor := clDefault;
  FTabsTextColor := clDefault;
  FTextAlignVert := vaBottom;
  FGlyphAlignHorz := taRightJustify;
  FGlyphAlignVert := vaBottom;
  FGlyph := TdxSmartImage.Create;
  FIndentHorz := dxTileItemObjectDefaultIndent;
  FIndentVert := dxTileItemObjectDefaultIndent;
  FColor := clDefault;
  FViewInfo := CreateViewInfo;
  FViewInfo.FTitle := Self;
end;

destructor TdxTileControlTitle.Destroy;
begin
  FreeAndNil(FGlyph);
  FreeAndNil(FFont);
  FreeAndNil(FViewInfo);
  inherited Destroy;
end;

procedure TdxTileControlTitle.Assign(ASource: TPersistent);
var
  ATitle: TdxTileControlTitle;
begin
  if ASource is TdxTileControlTitle then
  begin
    ATitle := TdxTileControlTitle(ASource);
    FColor := ATitle.Color;
    FIndentHorz := ATitle.IndentHorz;
    FIndentVert := ATitle.IndentVert;
    FText := ATitle.Text;
    FTextAlignHorz := ATitle.TextAlignHorz;
    FTextAlignVert := ATitle.TextAlignVert;
    FWordWrap := ATitle.WordWrap;
    FGlyphAlignHorz  := ATitle.GlyphAlignHorz;
    FGlyphAlignVert := ATitle.GlyphAlignVert;
    Glyph := ATitle.Glyph;
    Font := ATitle.Font;
    FTabsActiveTextColor := ATitle.TabsActiveTextColor;
    FTabsFontSize := ATitle.TabsFontSize;
    FTabsHotTextColor := ATitle.TabsHotTextColor;
    FTabsTextColor := ATitle.TabsTextColor;
  end
  else
    inherited Assign(ASource);
end;

procedure TdxTileControlTitle.Changed;
begin
  TileControl.LayoutChanged;
end;

function TdxTileControlTitle.CreateViewInfo: TdxTileControlTitleViewInfo;
begin
  Result := TdxTileControlTitleViewInfo.Create;
end;

procedure TdxTileControlTitle.FontChanged(Sender: TObject);
begin
  FFontChanged := True;
  Changed;
end;

function TdxTileControlTitle.IsChanged: Boolean;
begin
  Result := IsFontStored or (TextAlignHorz <> taLeftJustify) or (TextAlignVert <>  vaBottom) or
    (Color <> clDefault) or (IndentHorz <> dxTileItemObjectDefaultIndent) or
    (IndentVert <> dxTileItemObjectDefaultIndent) or (Text <> '') or WordWrap or
    not Glyph.Empty or (GlyphAlignHorz <> taRightJustify) or (GlyphAlignVert <> vaBottom) or
    (TabsFontSize <> dxTileControlDefaultTabFontSize) or (TabsActiveTextColor <> clDefault) or
    (TabsHotTextColor <> clDefault) or (TabsTextColor <> clDefault);
end;

function TdxTileControlTitle.GetTileControl: TdxCustomTileControl;
begin
  Result := TdxCustomTileControl(GetOwner);
end;

function TdxTileControlTitle.IsFontStored: Boolean;
begin
  Result := FFontChanged;
end;

procedure TdxTileControlTitle.SetColor(AValue: TColor);
begin
  if AValue <> FColor then
  begin
    FColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetFont(AValue: TFont);
begin
  FFont.Assign(AValue)
end;

procedure TdxTileControlTitle.SetGlyph(AValue: TdxSmartImage);
begin
  if AValue <> nil then
    FGlyph.Assign(AValue)
  else
    FGlyph.Clear;
  Changed;
end;

procedure TdxTileControlTitle.SetGlyphAlignHorz(AValue: TAlignment);
begin
  if AValue <> FGlyphAlignHorz then
  begin
    FGlyphAlignHorz := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetGlyphAlignVert(AValue: TcxAlignmentVert);
begin
  if AValue <> FGlyphAlignVert then
  begin
    FGlyphAlignVert := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetIndentHorz(AValue: Integer);
begin
  if AValue <> FIndentHorz then
  begin
    FIndentHorz := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetIndentVert(AValue: Integer);
begin
  if AValue <> FIndentVert then
  begin
    FIndentVert := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetTabsFontSize(AValue: Integer);
begin
  if FTabsFontSize <> AValue then
  begin
    FTabsFontSize := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetTabsActiveTextColor(AValue: TColor);
begin
  if FTabsActiveTextColor <> AValue then
  begin
    FTabsActiveTextColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetTabsHotTextColor(AValue: TColor);
begin
  if FTabsHotTextColor <> AValue then
  begin
    FTabsHotTextColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetTabsTextColor(AValue: TColor);
begin
  if FTabsTextColor <> AValue then
  begin
    FTabsTextColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetText(AValue: string);
begin
  if AValue <> FText then
  begin
    FText := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetTextAlignHorz(AValue: TAlignment);
begin
  if AValue <> FTextAlignHorz then
  begin
    FTextAlignHorz := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetTextAlignVert(AValue: TcxAlignmentVert);
begin
  if AValue <> FTextAlignVert then
  begin
    FTextAlignVert := AValue;
    Changed;
  end;
end;

procedure TdxTileControlTitle.SetWordWrap(AValue: Boolean);
begin
  if AValue <> FWordWrap then
  begin
    FWordWrap := AValue;
    Changed;
  end;
end;

{ TdxTileControlActionBars }

constructor TdxTileControlActionBars.Create(AOwner: TPersistent);
begin
  inherited Create(AOwner);
  FColor := clDefault;
  FFont := TFont.Create;
  FFont.Color := clDefault;
  FFont.OnChange := FontChanged;
  FItems := CreateItems;
  FItems.OnChange := ItemsChangeHandler;
  FIndentHorz := dxTileControlDefaultActionBarsIndentHorz;
  FIndentVert := dxTileControlDefaultActionBarsIndentVert;
  FItemIndent := dxTileControlDefaultActionBarsItemIndent;
end;

destructor TdxTileControlActionBars.Destroy;
begin
  FreeAndNil(FItems);
  FreeAndNil(FFont);
  inherited Destroy;
end;

procedure TdxTileControlActionBars.Assign(Source: TPersistent);
begin
  if Source is TdxTileControlActionBars then
  begin
    Font := TdxTileControlActionBars(Source).Font;
    Color := TdxTileControlActionBars(Source).Color;
    Items := TdxTileControlActionBars(Source).Items;
    IndentHorz := TdxTileControlActionBars(Source).IndentHorz;
    IndentVert := TdxTileControlActionBars(Source).IndentVert;
    ItemIndent := TdxTileControlActionBars(Source).ItemIndent;
  end;
end;

procedure TdxTileControlActionBars.Changed;
begin
  TileControl.RefreshActionBars;
end;

function TdxTileControlActionBars.CreateItems: TdxTileControlActionBarItems;
begin
  Result := TdxTileControlActionBarItems.Create(TileControl, TdxTileControlActionBarItem);
end;

procedure TdxTileControlActionBars.FontChanged(Sender: TObject);
begin
  FFontChanged := True;
  Changed;
end;

function TdxTileControlActionBars.IsFontStored: Boolean;
begin
  Result := FFontChanged;
end;

procedure TdxTileControlActionBars.ItemsChangeHandler(Sender: TObject;
  AItem: TcxComponentCollectionItem; AAction: TcxComponentCollectionNotification);
begin
  Changed;
end;

function TdxTileControlActionBars.GetTileControl: TdxCustomTileControl;
begin
  Result := Owner as TdxCustomTileControl;
end;

procedure TdxTileControlActionBars.SetColor(AValue: TColor);
begin
  if AValue <> FColor then
  begin
    FColor := AValue;
    Changed;
  end;
end;

procedure TdxTileControlActionBars.SetFont(AValue: TFont);
begin
  FFont.Assign(AValue);
end;

procedure TdxTileControlActionBars.SetIndentHorz(AValue: Integer);
begin
  if AValue <> FIndentHorz then
  begin
    FIndentHorz := AValue;
    Changed;
  end;
end;

procedure TdxTileControlActionBars.SetIndentVert(AValue: Integer);
begin
  if AValue <> FIndentVert then
  begin
    FIndentVert := AValue;
    Changed;
  end;
end;

procedure TdxTileControlActionBars.SetItemIndent(AValue: Integer);
begin
  if AValue <> FItemIndent then
  begin
    FItemIndent := AValue;
    Changed;
  end;
end;

procedure TdxTileControlActionBars.SetItems(AValue: TdxTileControlActionBarItems);
begin
  FItems.Assign(AValue);
end;

{ TdxTileControlViewInfo }

constructor TdxTileControlViewInfo.Create(AOwner: TdxCustomTileControl);
begin
  inherited Create;
  FTileControl := AOwner;
  FCells := TdxTileControlCells.Create(False);
  FVirtualGroups := TcxObjectList.Create(False);
  CreateScrollButtonsViewInfo;
end;

destructor TdxTileControlViewInfo.Destroy;
begin
  DestroyScrollButtonsViewInfo;
  FreeAndNil(FVirtualGroups);
  FreeAndNil(FCells);
  Inherited Destroy;
end;

procedure TdxTileControlViewInfo.Calculate;
begin
  FBounds := TileControl.ClientBounds;
  DoCalculate;
end;

function TdxTileControlViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := Cells.CalculateHitTest(AHitTest);
end;

procedure TdxTileControlViewInfo.AddGroup(AGroup: TdxTileControlGroup);
begin
  AddVirtualGroupBefore(AGroup);
  AGroup.ViewInfo.Recalculate;
  FCells.Add(AGroup.ViewInfo);
  FCells.Add(AGroup.Caption.ViewInfo);
  AddVirtualGroupAfter(AGroup);
end;

procedure TdxTileControlViewInfo.AddGroups;
var
  I: Integer;
begin
  MeasureGroupsCaptionsHeights;
  VirtualGroups.Clear;
  for I := 0 to GroupsCount - 1 do
    AddGroup(Groups.Items[I]);
end;

procedure TdxTileControlViewInfo.AddItem(AItem: TdxTileControlItem);
begin
  if not AItem.ActuallyVisible then Exit;
  AItem.ViewInfo.Calculate;
  FCells.Add(AItem.ViewInfo);
end;

procedure TdxTileControlViewInfo.AddItems;
var
  I: Integer;
begin
  for I := 0 to Items.Count - 1 do
    AddItem(Items[I]);
end;

procedure TdxTileControlViewInfo.AddScrollButtons;
var
  I: TcxArrowDirection;
begin
  if TileControl.OptionsBehavior.ScrollMode <> smScrollButtons then Exit;
  for I := Low(TcxArrowDirection) to High(TcxArrowDirection) do
  begin
    FScrollButtonViewInfo[I].Recalculate;
    FCells.Add(FScrollButtonViewInfo[I]);
  end;
end;

procedure TdxTileControlViewInfo.AddVirtualGroupAfter(AGroup: TdxTileControlGroup);
begin
  if AGroup.Visible then
  begin
    AGroup.VirtualGroupAfter.Recalculate;
    FCells.Add(AGroup.VirtualGroupAfter);
    FVirtualGroups.Add(AGroup.VirtualGroupAfter);
  end;
end;

procedure TdxTileControlViewInfo.AddVirtualGroupBefore(AGroup: TdxTileControlGroup);
begin
  if AGroup.Visible and AGroup.IsMostLeft then
  begin
    AGroup.VirtualGroupBefore.Recalculate;
    FCells.Add(AGroup.VirtualGroupBefore);
    FVirtualGroups.Add(AGroup.VirtualGroupBefore);
  end;
end;

procedure TdxTileControlViewInfo.CalculateClientBounds;
begin
  FClientBounds := TileControl.ClientBounds;
end;

procedure TdxTileControlViewInfo.CalculateDerivedItemSizes;
begin
  FItemHalfIndent := TileControl.OptionsView.ItemIndent div 2;
  FItemLargeWidth := 2 * TileControl.OptionsView.ItemSize + TileControl.OptionsView.ItemIndent;
end;

procedure TdxTileControlViewInfo.CalculateTilesArea;
begin
  FTilesArea := FClientBounds;
  FTilesArea.Top := FTilesArea.Top + TitleHeight;
end;

procedure TdxTileControlViewInfo.CalculateTitle;
begin
  Title.ViewInfo.Recalculate;
  if Title.ViewInfo.Visible then
    Cells.Add(Title.ViewInfo);
end;

procedure TdxTileControlViewInfo.CalculateRowCount;
var
  AUsefulHeight: Integer;
  AItemSize, AItemIndent: Integer;
begin
  if GroupLayout = glVertical then
    FRowCount := TileControl.OptionsView.GroupMaxRowCount
  else
  begin
    AUsefulHeight := cxRectHeight(TilesArea) - 2 * TileControl.OptionsView.IndentVert -
      GetGroupsCaptionsMaxHeight - 1;
    AItemIndent := TileControl.OptionsView.ItemIndent;
    AItemSize := TileControl.OptionsView.ItemSize + AItemIndent;
    FRowCount := AUsefulHeight div AItemSize;
    Inc(FRowCount, Ord(AUsefulHeight > (FRowCount + 1) * AItemSize - AItemIndent));
    FRowCount := Min(FRowCount, TileControl.OptionsView.GroupMaxRowCount);
    Inc(FRowCount, Ord(FRowCount = 0));
  end;
end;

procedure TdxTileControlViewInfo.Clear;
begin
  Cells.Clear;
end;

procedure TdxTileControlViewInfo.ClearGroupsOrigin;
begin
  FFixedGroupsOrigin := False;
end;

procedure TdxTileControlViewInfo.CreateScrollButtonsViewInfo;
var
  I: TcxArrowDirection;
begin
  for I := Low(TcxArrowDirection) to High(TcxArrowDirection) do
    FScrollButtonViewInfo[I] := TdxTileControlScrollButtonViewInfo.Create(TileControl, I);
end;

procedure TdxTileControlViewInfo.DestroyScrollButtonsViewInfo;
var
  I: TcxArrowDirection;
begin
  for I := Low(TcxArrowDirection) to High(TcxArrowDirection) do
    FreeAndNil(FScrollButtonViewInfo[I]);
end;

procedure TdxTileControlViewInfo.DoCalculate;
begin
  Clear;
  CalculateTitle;
  CalculateDerivedItemSizes;
  CalculateClientBounds;
  CalculateTilesArea;
  if (TileControl.ActiveDetail <> nil) and not TileControl.ForceCalculate then Exit;
  CalculateRowCount;
  AddGroups;
  if IsScrollBarsParametersWasChanged then
  begin
    DoCalculate;
    Exit;
  end;
  DoCenterContent;
  AddItems;
  AddScrollButtons;
  if not TileControl.UpdatingScrollBars then
    TileControl.UpdateScrollBars;
end;

procedure TdxTileControlViewInfo.DoCenterContent;
begin
  DoCenterContentHorz;
  DoCenterContentVert;
end;

procedure TdxTileControlViewInfo.DoCenterContentHorz;
var
  AShift, AAreaRight: Integer;
begin
  AAreaRight := TilesArea.Right;
  if IsContentNotCentredHorz or (VirtualGroups.Count = 0) or (FContentRight > AAreaRight) then Exit;
  AShift := (AAreaRight - FContentRight) div 2;
  if GroupLayout = glHorizontal then
    DoCenterContentHorzAtHorizontalGroupLayout(AShift, AAreaRight)
  else
    DoCenterContentHorzAtVerticalGroupLayout(AShift);
end;

procedure TdxTileControlViewInfo.DoCenterContentHorzAtHorizontalGroupLayout(
  const AShift, AAreaRight: Integer);
var
  I: Integer;
  AVirtualGroup: TdxTileControlVirtualGroupViewInfo;
begin
  AVirtualGroup := TdxTileControlVirtualGroupViewInfo(VirtualGroups[0]);
  AVirtualGroup.ExpandBounds(AShift, 0);
  for I := 0 to Cells.Count - 1 do
    if Cells[I] <> AVirtualGroup then
      Cells[I].Offset(AShift, 0);
  AVirtualGroup := TdxTileControlVirtualGroupViewInfo(VirtualGroups[VirtualGroups.Count - 1]);
  AVirtualGroup.ExpandBounds(AAreaRight - AVirtualGroup.Bounds.Right, 0);
end;

procedure TdxTileControlViewInfo.DoCenterContentHorzAtVerticalGroupLayout(
  const AShift: Integer);
var
  I: Integer;
begin
  for I := 0 to Cells.Count - 1 do
    if not(Cells[I] is TdxTileControlVirtualGroupViewInfo) then
      Cells[I].Offset(AShift, 0);
end;

procedure TdxTileControlViewInfo.DoCenterContentVert;
var
  AShift, AControlBottom: Integer;
  R: TRect;
begin
  AControlBottom := TilesArea.Bottom;
  if IsContentNotCentredVert or (VirtualGroups.Count = 0) or (FContentBottom > AControlBottom) then Exit;
  R := GetVisibleGroupsBounds;
  AShift := (AControlBottom - R.Bottom - R.Top + TilesArea.Top) div 2;
  if AShift > 0 then
    if GroupLayout = glHorizontal then
      DoCenterContentVertAtHorizontalGroupLayout(AShift)
    else
      DoCenterContentVertAtVerticalGroupLayout(AShift, AControlBottom);
end;

procedure TdxTileControlViewInfo.DoCenterContentVertAtHorizontalGroupLayout(
  const AShift: Integer);
var
  I: Integer;
begin
  for I := 0 to Cells.Count - 1 do
    if not(Cells[I] is TdxTileControlVirtualGroupViewInfo) then
      Cells[I].Offset(0, AShift);
  for I := 0 to Cells.Count - 1 do
    if Cells[I] is TdxTileControlVirtualGroupViewInfo then
      TdxTileControlVirtualGroupViewInfo(Cells[I]).RecalculateAreaBounds;
end;

procedure TdxTileControlViewInfo.DoCenterContentVertAtVerticalGroupLayout(
  const AShift, AAreaBottom: Integer);
var
  I: Integer;
  AVirtualGroup: TdxTileControlVirtualGroupViewInfo;
begin
  AVirtualGroup := TdxTileControlVirtualGroupViewInfo(VirtualGroups[0]);
  AVirtualGroup.ExpandBounds(0, AShift);
  for I := 0 to Cells.Count - 1 do
    if Cells[I] <> AVirtualGroup then
      Cells[I].Offset(0, AShift);
  AVirtualGroup := TdxTileControlVirtualGroupViewInfo(VirtualGroups[VirtualGroups.Count - 1]);
  AVirtualGroup.ExpandBounds(0, AAreaBottom - AVirtualGroup.Bounds.Bottom);
end;

function TdxTileControlViewInfo.GetContentBounds: TRect;
var
  I: Integer;
  AVirtualGroup: TdxTileControlVirtualGroupViewInfo;
  AGroup: TdxTileControlGroup;
  ABounds: TRect;
  ARealContentRight: Integer;
begin
  Result.Left := MaxInt;
  Result.Right := 0;
  Result.Top := MaxInt;
  Result.Bottom := 0;
  ARealContentRight := 0;
  for I := 0 to VirtualGroups.Count - 1 do
  begin
    AVirtualGroup := TdxTileControlVirtualGroupViewInfo(VirtualGroups[I]);
    AGroup := AVirtualGroup.Group;
    ABounds := AVirtualGroup.Bounds;
    ARealContentRight := Max(Result.Right, AGroup.Bounds.Right + TileControl.OptionsView.IndentHorz);
    Result.Left := Min(Result.Left, ABounds.Left);
    Result.Bottom := Max(Result.Bottom, AGroup.Bounds.Bottom + TileControl.OptionsView.IndentVert);
    if GroupLayout = glHorizontal then
    begin
      Result.Top := Min(Result.Top, AGroup.Caption.Bounds.Top - TileControl.OptionsView.IndentVert);
      if TileControl.IsItemDragged and (AVirtualGroup = AGroup.VirtualGroupAfter) then
        ARealContentRight := Max(ARealContentRight, AGroup.Bounds.Right + AVirtualGroup.BasisWidth);
    end
    else
    begin
      Result.Top := Min(Result.Top, ABounds.Top);
      if TileControl.IsItemDragged then
        Result.Bottom := Max(Result.Bottom, ABounds.Bottom);
    end;
    Result.Right := Max(Result.Right, ARealContentRight);
  end;
  FRealContentWidth := ARealContentRight - Result.Left;
end;

function TdxTileControlViewInfo.GetGroupsCaptionsMaxHeight: Integer;
var
  I: Integer;
  AGroup: TdxTileControlGroup;
begin
  Result := 0;
  for I := 0 to Groups.Count - 1 do
  begin
    AGroup := Groups[I];
    if AGroup.Visible then
      Result := Max(Result, cxRectHeight(AGroup.Caption.Bounds));
  end;
end;

function TdxTileControlViewInfo.GetTitleHeight: Integer;
begin
  Result := 0;
  if Title.ViewInfo.Visible then
    Result := Title.ViewInfo.Bounds.Bottom;
end;

function TdxTileControlViewInfo.GetVertScrollPage: Integer;
begin
  Result := cxRectHeight(TilesArea);
end;

function TdxTileControlViewInfo.GetVisibleGroupsBounds: TRect;
var
  I: Integer;
  AGroup: TdxTileControlGroup;
  ABounds: TRect;
begin
  Result := cxNullRect;
  Result.Left := MaxInt;
  Result.Top := MaxInt;
  for I := 0 to TileControl.Groups.Count - 1 do
  begin
    AGroup := TileControl.Groups[I];
    if AGroup.Visible then
      begin
        ABounds := AGroup.Bounds;
        Result.Left := Min(Result.Left, ABounds.Left);
        Result.Top := Min(Result.Top, AGroup.Caption.Bounds.Top);
        Result.Right := Max(Result.Right, ABounds.Right);
        Result.Bottom := Max(Result.Bottom, ABounds.Bottom);
      end;
  end;
end;

function TdxTileControlViewInfo.IsFixedContentLeftSide: Boolean;
begin
  Result := TileControl.OptionsView.CenterContentHorz and FFixedGroupsOrigin;
end;

function TdxTileControlViewInfo.IsFixedContentTopSide: Boolean;
begin
  Result := TileControl.OptionsView.CenterContentVert and FFixedGroupsOrigin;
end;

function TdxTileControlViewInfo.IsScrollBarsParametersWasChanged: Boolean;
var
  ABounds: TRect;
  APos: Integer;
begin
  ABounds := GetContentBounds;
  FContentHeight := Max(ABounds.Bottom - ABounds.Top, VertScrollPage);
  FContentWidth := Max(ABounds.Right - ABounds.Left, HorzScrollPage);
  FContentRight := ABounds.Right;
  FContentBottom := ABounds.Bottom;
  Result := False;
  if VertScrollPage + TopScrollPos > FContentHeight then
  begin
    APos := TopScrollPos;
    TopScrollPos := Max(0, FContentHeight - VertScrollPage);
    Result := TopScrollPos <> APos;
  end;
  if HorzScrollPage + LeftScrollPos > FRealContentWidth then
  begin
    APos := LeftScrollPos;
    LeftScrollPos := Max(0, FRealContentWidth - HorzScrollPage);
    Result := LeftScrollPos <> APos;
  end;
end;

procedure TdxTileControlViewInfo.MakeVisible(
  const ABounds: TRect; AIsLeftMost, AIsRightMost: Boolean);
begin
  if GroupLayout = glHorizontal then
    MakeVisibleOnHorz(ABounds, AIsLeftMost, AIsRightMost)
  else
    MakeVisibleOnVert(ABounds, AIsLeftMost, AIsRightMost);
end;

procedure TdxTileControlViewInfo.MakeVisibleOnHorz(
  const ABounds: TRect; AIsLeftMost, AIsRightMost: Boolean);
var
  APos, AGap: Integer;
begin
  APos := LeftScrollPos;
  AGap := ItemHalfIndent + TileControl.GetBorderSize * 2;
  if AIsLeftMost then
    APos := 0
  else
    if AIsRightMost then
      APos := FContentWidth - HorzScrollPage
    else
      if ABounds.Left < TilesArea.Left then
        Dec(APos, TilesArea.Left - ABounds.Left + AGap)
      else
        if ABounds.Right > TilesArea.Right then
          Inc(APos, ABounds.Right - TilesArea.Right + AGap);
  if LeftScrollPos <> APos then
    Scroll(APos - LeftScrollPos, 0);
end;

procedure TdxTileControlViewInfo.MakeVisibleOnVert(
  const ABounds: TRect; AIsLeftMost, AIsRightMost: Boolean);
var
  APos, AGap: Integer;
begin
  APos := TopScrollPos;
  AGap := ItemHalfIndent + TileControl.GetBorderSize * 2;
  if AIsLeftMost then
    APos := 0
  else
    if AIsRightMost then
      APos := FContentHeight - VertScrollPage
    else
      if ABounds.Top < TilesArea.Top then
        Dec(APos, TilesArea.Top - ABounds.Top + AGap)
      else
        if ABounds.Bottom > TilesArea.Bottom then
          Inc(APos, ABounds.Bottom - TilesArea.Bottom + AGap);
  if TopScrollPos <> APos then
    Scroll(0, APos - TopScrollPos);
end;

procedure TdxTileControlViewInfo.MeasureGroupsCaptionsHeights;
var
  I, AMaxHeight: Integer;
  ACaption: TdxTileControlGroupCaption;
begin
  AMaxHeight := 0;
  for I := 0 to Groups.Count - 1 do
    if Groups[I].Visible then
    begin
      ACaption := Groups[I].Caption;
      ACaption.MeasureHeight;
      AMaxHeight := Max(AMaxHeight, ACaption.Height);
    end;
  if (AMaxHeight > 0) and (TileControl.OptionsView.GroupLayout = glHorizontal) then
    for I := 0 to Groups.Count - 1 do
      if Groups[I].Visible then
        Groups[I].Caption.SetHeight(AMaxHeight);
end;

procedure TdxTileControlViewInfo.StoreGroupsOrigin;
var
  I: Integer;
  AGroup: TdxTileControlGroup;
begin
  FFixedGroupsOrigin := True;
  FVisibleGroupsOrigin.X := 0;
  FVisibleGroupsOrigin.Y := 0;
  for I := 0 to TileControl.Groups.Count - 1 do
  begin
    AGroup := TileControl.Groups[I];
    if AGroup.Visible then
    begin
      FVisibleGroupsOrigin.X := AGroup.Bounds.Left;
      FVisibleGroupsOrigin.Y := AGroup.Bounds.Top;
      Break;
    end;
  end;
end;

procedure TdxTileControlViewInfo.Scroll(const DX, DY: Integer);
var
  I: Integer;
begin
  Inc(FLeftScrollPos, DX);
  Inc(FTopScrollPos, DY);
  for I := 0 to Cells.Count - 1 do
    Cells[I].Scroll(-DX, -DY);
  TileControl.HitTest.HitPoint := TileControl.ScreenToClient(GetMouseCursorPos);
  TileControl.Controller.HottrackedItem := TileControl.HitTest.Item;
  TileControl.Invalidate;
  if not TileControl.Controller.HasRubberAnimation then
    TileControl.UpdateScrollBars;
end;

procedure TdxTileControlViewInfo.Draw(ACanvas: TcxCanvas);
begin
  Painter.DrawBackground(ACanvas, TileControl.ClientRect);
  Cells.Draw(ACanvas);
  if DragDropChanges <> nil then
    DragDropChanges.DrawItems(ACanvas);
end;

function TdxTileControlViewInfo.GetGroupLayout: TdxTileControlGroupLayout;
begin
  Result := TileControl.OptionsView.GroupLayout;
end;

function TdxTileControlViewInfo.GetGroups: TdxTileControlGroupCollection;
begin
  Result := TileControl.Groups;
end;

function TdxTileControlViewInfo.GetGroupCount: Integer;
begin
  Result := TileControl.Groups.Count;
end;

function TdxTileControlViewInfo.GetItemWidth(AIsLarge: Boolean = False): Integer;
begin
  if AIsLarge then
    Result := FItemLargeWidth
  else
    Result := TileControl.OptionsView.ItemSize;
end;

function TdxTileControlViewInfo.GetHorzScrollPage: Integer;
begin
  Result := cxRectWidth(TilesArea);
end;

function TdxTileControlViewInfo.GetSubColumnSize: Integer;
begin
  Result := SubColumnSizes[RowCount > 1];
end;

function TdxTileControlViewInfo.GetTitle: TdxTileControlTitle;
begin
  Result := TileControl.Title;
end;

function TdxTileControlViewInfo.GetItems: TdxTileControlItemCollection;
begin
  Result := TileControl.Items;
end;

function TdxTileControlViewInfo.GetPainter: TdxTileControlPainter;
begin
  Result := TileControl.Painter;
end;

procedure TdxTileControlViewInfo.HideScrollButtons;
var
  I: TcxArrowDirection;
begin
  for I := Low(TcxArrowDirection) to High(TcxArrowDirection) do
    FScrollButtonViewInfo[I].State := cxbsDisabled;
end;

function TdxTileControlViewInfo.IsContentCentredHorz: Boolean;
begin
  Result := TileControl.OptionsView.CenterContentHorz and
    (ContentWidth <= HorzScrollPage) and (VirtualGroups.Count > 0);
end;

function TdxTileControlViewInfo.IsContentCentredVert: Boolean;
begin
  Result := TileControl.OptionsView.CenterContentVert and
    (ContentHeight <= VertScrollPage) and (VirtualGroups.Count > 0);
end;

function TdxTileControlViewInfo.IsContentNotCentredHorz: Boolean;
begin
  Result := not IsContentCentredHorz or IsFixedContentLeftSide;
end;

function TdxTileControlViewInfo.IsContentNotCentredVert: Boolean;
begin
  Result := not IsContentCentredVert or IsFixedContentTopSide;
end;

function TdxTileControlViewInfo.IsScrollAvailable: Boolean;
begin
  Result := IsScrollAvailable(adUp) or IsScrollAvailable(adDown) or
    IsScrollAvailable(adLeft) or IsScrollAvailable(adRight);
end;

function TdxTileControlViewInfo.IsScrollAvailable(ADirection: TcxArrowDirection): Boolean;
begin
  case ADirection of
    adUp:
      Result := TopScrollPos <> 0;
    adDown:
      Result := TopScrollPos < ContentHeight - 1 - VertScrollPage;
    adLeft:
      Result := LeftScrollPos <> 0;
  else
    Result := LeftScrollPos < ContentWidth - 1 - HorzScrollPage;
  end;
end;

procedure TdxTileControlViewInfo.RefreshState;
begin
  inherited RefreshState;
  Cells.RefreshState;
end;

procedure TdxTileControlViewInfo.SetLeftScrollPos(AValue: Integer);
begin
  if not TileControl.Controller.IsHandScrolling(sbHorizontal) then
    AValue := Max(0, Min(AValue, ContentWidth - HorzScrollPage));
  if AValue <> FLeftScrollPos then
    Scroll(AValue - FLeftScrollPos, 0);
end;

procedure TdxTileControlViewInfo.SetTopScrollPos(AValue: Integer);
begin
  if not TileControl.Controller.IsHandScrolling(sbVertical) then
    AValue := Max(0, Min(AValue, ContentHeight - VertScrollPage));
  if AValue <> FTopScrollPos then
    Scroll(0, AValue - FTopScrollPos);
end;

{ TdxTileControlItemPersistent }

procedure TdxTileControlItemPersistent.Changed;
begin
  if Owner <> nil then
    Owner.Changed;
end;

function TdxTileControlItemPersistent.IsChanged: Boolean;
begin
  Result := False;
end;

function TdxTileControlItemPersistent.GetOwnerItem: TdxTileControlCustomItem;
begin
  Result := TdxTileControlCustomItem(GetOwner);
end;

{ TdxTileControlPainter }

constructor TdxTileControlPainter.Create(ATileControl: TdxCustomTileControl);
begin
  inherited Create;
  FTileControl := ATileControl;
end;

procedure TdxTileControlPainter.DrawBackground(ACanvas: TcxCanvas; const R: TRect);
begin
  if UseSkins then
  begin
    SkinInfo.TileControlBackground.UseCache := True;
    SkinInfo.TileControlBackground.Draw(ACanvas.Handle, R)
  end
  else
  begin
    if TileControl.Style.IsEmpty then
      LookAndFeelPainter.DrawPanelContent(ACanvas, R, False);
    DrawStyleRect(ACanvas, R, TileControl.Style,
      MulDiv(TileControl.ViewInfo.LeftScrollPos, TileControl.OptionsBehavior.BackgroundScrollSync, 100),
      MulDiv(TileControl.ViewInfo.TopScrollPos, TileControl.OptionsBehavior.BackgroundScrollSync, 100), []);
  end;
end;

procedure TdxTileControlPainter.DrawColoredGlyph(ACanvas: TcxCanvas;
  const R: TRect; AState: TcxButtonState; AGlyph: TdxSkinImage; AColor: TColor);
const
  StateMap: array[TcxButtonState] of Integer = (0, 0, 1, 2, 3);
var
  ASkinImage: TdxSkinImage;
begin
  ASkinImage := TdxSkinImage.Create(nil);
  try
    ASkinImage.Assign(AGlyph);
    ASkinImage.Texture.ChangeColor(AColor);
    ASkinImage.Draw(ACanvas.Handle, R, StateMap[AState]);
  finally
    ASkinImage.Free;
  end;
end;

procedure TdxTileControlPainter.DrawDefaultItemBackground(ACanvas: TcxCanvas; const R: TRect);
begin
  if UseSkins then
    SkinInfo.TileControlItem.Draw(ACanvas.Handle, R)
  else
    with TdxSkinCanvas.Create do
    try
      BeginPaint(ACanvas.Handle, R);
      FillRectByGradient(R, dxTileItemShadowColor, dxTileItemLightColor, gmForwardDiagonal);
      EndPaint;
    finally
      Free;
    end;
end;

procedure TdxTileControlPainter.DrawDefaultItemCheck(ACanvas: TcxCanvas; const R: TRect);
begin
  DrawDefaultItemCheck(ACanvas, R, CheckedItemFrameColor, CheckedItemCheckMarkColor);
end;

procedure TdxTileControlPainter.DrawDefaultItemCheck(ACanvas: TcxCanvas;
  const R: TRect; ABackgroundColor, ACheckMarkColor: TColor; AAlpha: Byte = MaxByte);

  function CreateRegion: TcxRegion;
  var
    APoints: array[0..2] of TPoint;
  begin
    APoints[0] := cxPoint(R.Right - dxTileCheckedItemCheckMarkAreaSize, R.Top);
    APoints[1] := cxPoint(R.Right, R.Top);
    APoints[2] := cxPoint(R.Right, R.Top + dxTileCheckedItemCheckMarkAreaSize);

    Result := TcxRegion.Create(R);
    Result.Combine(cxRectInflate(R, -dxTileCheckedItemFrameBorderSize, -dxTileCheckedItemFrameBorderSize), roSubtract);
    Result.Combine(TcxRegion.Create(CreatePolygonRgn(APoints[0], Length(APoints), ALTERNATE)), roAdd);
  end;

  function CalculateCheckMarkArea(const R: TRect): TRect;
  const
    CheckMarkAreaSize = dxTileCheckedItemCheckMarkAreaSize div 2;
  begin
    Result := cxRectSetHeight(R, MulDiv(CheckMarkAreaSize, 8, 9));
    Result := cxRectSetRight(Result, Result.Right, CheckMarkAreaSize);
    Result := cxRectInflate(Result, 0,
      -2 * dxTileCheckedItemFrameBorderSize,
      -2 * dxTileCheckedItemFrameBorderSize, 0);
  end;

  procedure DrawCheckMark(AGraphics: TdxGPGraphics; AColor: TColor);
  var
    ACheckMarkArea: TRect;
    APoints: array[0..2] of TPoint;              
    APrevSmoothingMode: TdxGPSmoothingMode;
  begin
    ACheckMarkArea := CalculateCheckMarkArea(R);
    APoints[0] := cxPoint(ACheckMarkArea.Right, ACheckMarkArea.Top);
    APoints[1] := cxPoint((ACheckMarkArea.Left + ACheckMarkArea.Right) div 2, ACheckMarkArea.Bottom);
    APoints[2] := cxPoint(ACheckMarkArea.Left, (ACheckMarkArea.Bottom + ACheckMarkArea.Top) div 2);

    APrevSmoothingMode := dxGPPaintCanvas.SmoothingMode;
    try
      dxGPPaintCanvas.SmoothingMode := smAntiAlias;
      dxGPPaintCanvas.Polyline(APoints, AColor, dxTileCheckedItemCheckMarkPenSize, psSolid, AAlpha);
    finally
      dxGPPaintCanvas.SmoothingMode := APrevSmoothingMode;
    end;
  end;

begin
  ACanvas.SaveClipRegion;
  try
    ACanvas.SetClipRegion(CreateRegion, roIntersect);
    dxGPPaintCanvas.BeginPaint(ACanvas.Handle, R);
    try
      if ABackgroundColor <> clNone then
        dxGpFillRect(dxGPPaintCanvas.Handle, R, dxGpColorToARGB(ABackgroundColor, AAlpha));
      if ACheckMarkColor <> clNone then
        DrawCheckMark(dxGPPaintCanvas, ACheckMarkColor);
    finally
      dxGPPaintCanvas.EndPaint;
    end;
  finally
    ACanvas.RestoreClipRegion;
  end;
end;

procedure TdxTileControlPainter.DrawItemCheck(ACanvas: TcxCanvas; const R: TRect);
begin
  if UseSkins then
    SkinInfo.TileControlItemCheck.Draw(ACanvas.Handle, R)
  else
    DrawDefaultItemCheck(ACanvas, R);
end;

procedure TdxTileControlPainter.DrawStyleRect(ACanvas: TcxCanvas;
  const R: TRect; AStyle: TdxTileControlCustomStyle;
  const ATextureOffsetX, ATextureOffsetY: Integer; ABorders: TcxBorders);
var
  ASkinCanvas: TdxSkinCanvas;
  ATextureRect: TRect;
begin
  ASkinCanvas := TdxSkinCanvas.Create;
  try
    ASkinCanvas.BeginPaint(ACanvas.Handle, R);
    try
      ASkinCanvas.FillRectByGradient(R,
        cxGetActualColor(AStyle.GradientBeginColor, LookAndFeelPainter.DefaultContentColor),
        AStyle.GradientEndColor, AStyle.Gradient);
        
      if not AStyle.Texture.Empty then
      begin
        ATextureRect := R;
        if AStyle.Stretch <> smStretch then
        begin
          Dec(ATextureRect.Left, ATextureOffsetX);
          Dec(ATextureRect.Top, ATextureOffsetY);
        end;
        ASkinCanvas.Graphics.InterpolationMode := imHighQualityBicubic;
        ASkinCanvas.DrawTexture(AStyle.Texture, ATextureRect, AStyle.Stretch);
      end;

      if (AStyle.BorderColor <> clNone) and (ABorders <> []) then
        ASkinCanvas.DrawFrame(R, cxGetActualColor(AStyle.BorderColor, clBtnShadow), 1, ABorders);
    finally
      ASkinCanvas.EndPaint;
    end;
  finally
    ASkinCanvas.Free;
  end;
end;

procedure TdxTileControlPainter.DrawItemBackground(
  ACanvas: TcxCanvas; const R: TRect; AStyle: TdxTileControlCustomStyle);
begin
  if AStyle.IsEmpty then
    DrawDefaultItemBackground(ACanvas, R)
  else
    DrawStyleRect(ACanvas, R, AStyle, 0, 0, cxBordersAll)
end;

procedure TdxTileControlPainter.DrawItemPlace(ACanvas: TcxCanvas; const R: TRect);
begin
  if UseSkins then
    SkinInfo.TileControlVirtualGroup.Draw(ACanvas.Handle, R)
  else
    ACanvas.FillRect(R, dxTileItemPlaceColor);
end;

procedure TdxTileControlPainter.DrawPageTab(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
const
  ButtonStateToSkinState: array[TcxButtonState] of TdxSkinElementState = (
    esNormal, esNormal, esHot, esPressed, esDisabled
  );
begin
  if UseSkins then
    SkinInfo.TileControlTabHeader.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
end;

procedure TdxTileControlPainter.DrawVirtualGroup(ACanvas: TcxCanvas; const R: TRect);
begin
  if UseSkins then
    SkinInfo.TileControlVirtualGroup.Draw(ACanvas.Handle, R)
  else
    ACanvas.FillRect(R, dxTileVirtualGroupBackgroundColor);
end;

function TdxTileControlPainter.GetActionBarDefaultBackgroundColor: TColor;
begin
  Result := clDefault;
  if UseSkins then
    Result := SkinInfo.TileControlActionBar.Color;
  if Result = clDefault then
    Result := dxTileDefaultActionBarColor;
end;

function TdxTileControlPainter.GetActionBarDefaultTextColor: TColor;
begin
  Result := clDefault;
  if UseSkins then
    Result := SkinInfo.TileControlActionBar.TextColor;
  if Result = clDefault then
    Result := dxTileDefaultActionBarTextColor;
end;

function TdxTileControlPainter.GetCheckedItemCheckMarkColor: TColor;
begin
  Result := cxGetActualColor(TileControl.Style.CheckedItemCheckMarkColor, clHighlightText);
end;

function TdxTileControlPainter.GetCheckedItemFrameColor: TColor;
begin
  Result := cxGetActualColor(TileControl.Style.CheckedItemFrameColor, clHighlight);
end;

function TdxTileControlPainter.GetDefaultItemTextBackgroundColor: TColor;
begin
  Result := clDefault;
  if UseSkins then
    Result := SkinInfo.TileControlItem.Color;
  if Result = clDefault then
    Result := clBlack;
end;

function TdxTileControlPainter.GetDefaultItemTextColor: TColor;
begin
  Result := clDefault;
  if UseSkins then
    Result := SkinInfo.TileControlItem.TextColor;
  if Result = clDefault then
    Result := clWhite;
end;

function TdxTileControlPainter.GetGroupCaptionDefaultTextColor: TColor;
begin
  Result := clDefault;
  if UseSkins then
    Result := SkinInfo.TileControlGroupCaption.TextColor;
  if Result = clDefault then
    Result := clWindowText;
end;

function TdxTileControlPainter.GetGroupCaptionDefaultFontSize: Integer;
begin
  Result := dxTileControlDefaultGroupCaptionFontSize;
  if UseSkins then
    Inc(Result, SkinInfo.TileControlGroupCaptionFontDelta);
end;

function TdxTileControlPainter.GetLookAndFeelPainter: TcxCustomLookAndFeelPainter;
begin
  Result := TileControl.LookAndFeelPainter;
end;

function TdxTileControlPainter.GetPageTabContentOffset: TRect;
begin
  if UseSkins then
    Result := SkinInfo.TileControlTabHeader.ContentOffset.Rect
  else
    Result := cxRect(15, cxTextOffset, 15, cxTextOffset);
end;

function TdxTileControlPainter.GetPageTabDefaultFontSize: Integer;
begin
  if UseSkins then
    Result := 8 + SkinInfo.TileControlTabHeaderFontDelta
  else
    Result := dxTileControlDefaultTabFontSize;
end;

function TdxTileControlPainter.GetPageTabTextColor(AState: TcxButtonState): TColor;
begin
  case AState of
    cxbsHot:
      Result := TileControl.Title.TabsHotTextColor;
    cxbsPressed:
      Result := TileControl.Title.TabsActiveTextColor;
    else
      Result := TileControl.Title.TabsTextColor;
  end;

  if (Result = clDefault) and UseSkins then
    Result := SkinInfo.TileControlTabHeader.GetTextColor(AState);

  case AState of
    cxbsHot, cxbsPressed:
      Result := cxGetActualColor(Result, clHighlightText);
    else
      Result := cxGetActualColor(Result, clWindowText);
  end;
end;

function TdxTileControlPainter.GetSelectionFocusedColor: TColor;
begin
  Result := TileControl.Style.FocusedColor;
  if (Result = clDefault) and UseSkins then
    Result := SkinInfo.TileControlSelectionFocusedColor;
  if (Result = clDefault) then
    Result := Light(clHighlight, 70);
end;

function TdxTileControlPainter.GetSelectionHottrackedColor: TColor;
begin
  Result := TileControl.Style.FocusedColor;
  if (Result = clDefault) and UseSkins then
    Result := SkinInfo.TileControlSelectionHotColor;
  if (Result = clDefault) then
    Result := Light(clHighlight, 70);
end;

function TdxTileControlPainter.GetSelectionSelectedColor: TColor;
begin
  if UseSkins then
    Result := SkinInfo.TileControlSelectionFocusedColor
  else
    Result := clDefault;
  if Result = clDefault then
    Result := ColorToRgb(Light(clHighlight, 70));
end;

function TdxTileControlPainter.GetTitleDefaultFontSize: Integer;
begin
  if UseSkins then
    Result := 8 + SkinInfo.TileControlTitleFontDelta
  else
    Result := dxTileControlDefaultTitleFontSize;
end;

function TdxTileControlPainter.GetTitleDefaultTextColor: TColor;
begin
  Result := clDefault;
  if UseSkins then
    Result := SkinInfo.TileControlTitle.TextColor;
  if Result = clDefault then
    Result := clWindowText;
end;

function TdxTileControlPainter.GetUserSkins: Boolean;
begin
  Result := SkinInfo <> nil;
end;

procedure TdxTileControlPainter.ValidatePainterData;
begin
  if not LookAndFeelPainter.GetPainterData(FSkinInfo) then
    FSkinInfo := nil;
end;

{ TdxTileControlPageTabCellViewInfo }

constructor TdxTileControlPageTabCellViewInfo.Create(
  AOwner: TdxTileControlDetailSiteTitleViewInfo; AItem: TdxTileControlItem);
begin
  FOwner := AOwner;
  FItem := AItem; 
end;

function TdxTileControlPageTabCellViewInfo.MeasureHeight: Integer;
begin
  Result := cxTextHeight(Font, Caption) + cxMarginsHeight(GetContentOffsets);
end;

function TdxTileControlPageTabCellViewInfo.MeasureWidth: Integer;
begin
  Result := cxTextWidth(Font, Caption) + cxMarginsWidth(GetContentOffsets);
end;

procedure TdxTileControlPageTabCellViewInfo.DoDraw(ACanvas: TcxCanvas);
var
  ATextRect: TRect;
begin
  Painter.DrawPageTab(ACanvas, Bounds, State);
  ATextRect := cxRectContent(Bounds, GetContentOffsets);
  cxTextOut(ACanvas.Canvas, Caption, ATextRect, CXTO_CENTER_HORIZONTALLY or CXTO_BOTTOM,
    0, 0, Font, clNone, clNone, 0, 0, 0, Painter.PageTabTextColor[State]);
end;

function TdxTileControlPageTabCellViewInfo.GetContentOffsets: TRect;
begin
  Result := Painter.PageTabContentOffset;
end;

function TdxTileControlPageTabCellViewInfo.GetHitTest(
  AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
    AHitTest.BitState[tchtPageTab] := True;
end;

function TdxTileControlPageTabCellViewInfo.GetPainter: TdxTileControlPainter;
begin
  Result := Owner.TileControl.Painter;
end;

procedure TdxTileControlPageTabCellViewInfo.RefreshState;
begin
  if Item.IsActive then
    State := cxbsPressed
  else
    if Owner.TileControl.HitTest.HitObject = Self then
      State := cxbsHot
    else
      State := cxbsNormal;
end;

procedure TdxTileControlPageTabCellViewInfo.SetBounds(
  const ABounds, AVisibleBounds: TRect);
begin
  FBounds := ABounds;
  FVisibleBounds := AVisibleBounds;
  Recalculate;
end;

function TdxTileControlPageTabCellViewInfo.GetActive: Boolean;
begin
  Result := False;
end;

function TdxTileControlPageTabCellViewInfo.GetCaption: string;
var
  I: Integer;
begin
  Result := Item.DetailOptions.Caption;
  if Result <> '' then Exit;
  for I := 0 to 3 do
    if Item.GetText(I).HasValue then
    begin
      Result := Item.GetText(I).GetActualValue;
      Break;
    end;
  if Result = '' then
    Result := Item.Name; 
end;

function TdxTileControlPageTabCellViewInfo.GetFont: TFont;
begin
  Result := Owner.TabsFont;
end;

procedure TdxTileControlPageTabCellViewInfo.SetState(AValue: TcxButtonState);
begin
  if AValue <> FState then
  begin
    FState := AValue;
    Owner.FOwner.InvalidateRect(Bounds, False);
  end;
end;

{ TdxTileControlCustomButtonViewInfo }

function TdxTileControlCustomButtonViewInfo.MeasureHeight: Integer;
begin
  Result := Texture.Size.cy;
end;

function TdxTileControlCustomButtonViewInfo.MeasureWidth: Integer;
begin
  Result := Texture.Size.cx;
end;

procedure TdxTileControlCustomButtonViewInfo.SetBounds(
  const ABounds, AVisibleBounds: TRect);
begin
  Bounds := ABounds;
  VisibleBounds := AVisibleBounds;
  Recalculate;
end;

procedure TdxTileControlCustomButtonViewInfo.SetState(const Value: TcxButtonState);
begin
  if Value <> FState then
  begin
    FState := Value;
    Invalidate;
  end;
end;

{ TdxTileControlDetailSiteBackButtonViewInfo }

constructor TdxTileControlDetailSiteBackButtonViewInfo.Create(
  AOwner: TdxTileControlDetailSite);
begin
  inherited Create;
  FOwner := AOwner;
end;

procedure TdxTileControlDetailSiteBackButtonViewInfo.Invalidate;
begin
  if Visible then
    Owner.InvalidateRect(Bounds, False);
end;

procedure TdxTileControlDetailSiteBackButtonViewInfo.RefreshState;
begin
  if (Owner.PressedCell = Self) and (Owner.HitTest.HitObject = Self) then
    State := cxbsPressed
  else
    if (Owner.HitTest.HitObject = Self) and (Owner.PressedCell = nil) then
      State := cxbsHot
    else
      State := cxbsNormal;
end;

procedure TdxTileControlDetailSiteBackButtonViewInfo.Draw(ACanvas: TcxCanvas);
begin
  Owner.TileControl.Painter.DrawColoredGlyph(
    ACanvas, Bounds, State, Texture, Owner.TitleViewInfo.TextColor);
end;

function TdxTileControlDetailSiteBackButtonViewInfo.GetHitTest(
  AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
    AHitTest.BitState[tchtBackButton] := True;
end;

function TdxTileControlDetailSiteBackButtonViewInfo.GetTexture: TdxSkinImage;
begin
  Result := Owner.TileControl.Assets.BackButton;
end;

{ TdxTileControlScrollButtonViewInfo }

constructor TdxTileControlScrollButtonViewInfo.Create(
  AOwner: TdxCustomTileControl; ADirection: TcxArrowDirection);
begin
  inherited Create;
  FOwner := AOwner;
  FDirection := ADirection;
  FState := cxbsDisabled;
  FTimer := TcxTimer.Create(nil);
  FTimer.Enabled := False;
  FTimer.Interval := 50;
  FTimer.OnTimer := TimerHandler;
end;

destructor TdxTileControlScrollButtonViewInfo.Destroy;
begin
  EndMouseTracking(Self);
  FreeAndNil(FTimer);
  inherited Destroy;
end;

procedure TdxTileControlScrollButtonViewInfo.DoCalculate;
var
  AButtonSizeX, AButtonSizeY: Integer;
  AOffsetX, AOffsetY: Integer;
  AWidth, AHeight: Integer;
  R: TRect;
begin
  R := ViewInfo.TilesArea;
  AWidth := cxRectWidth(R);
  AHeight := cxRectHeight(R);
  AButtonSizeX := Owner.LookAndFeelPainter.SliderButtonSize(FDirection).cx;
  AButtonSizeY := Owner.LookAndFeelPainter.SliderButtonSize(FDirection).cy;
  AOffsetX := AButtonSizeX div 2;
  AOffsetY := AButtonSizeY div 2;
  case FDirection of
    adUp:
      Bounds := cxRectBounds((AWidth - AButtonSizeX) div 2, R.Top + AOffsetY,
        AButtonSizeX, AButtonSizeY);
    adDown:
      Bounds := cxRectBounds((AWidth - AButtonSizeX) div 2, R.Bottom - AButtonSizeY - AOffsetY,
        AButtonSizeX, AButtonSizeY);
    adLeft:
      Bounds := cxRectBounds(AOffsetX, R.Top + (AHeight - AButtonSizeY) div 2,
        AButtonSizeX, AButtonSizeY);
  else
    Bounds := cxRectBounds(AWidth - AButtonSizeX - AOffsetX, R.Top + (AHeight - AButtonSizeY) div 2,
      AButtonSizeX, AButtonSizeY);
  end;
  inherited DoCalculate;
end;

procedure TdxTileControlScrollButtonViewInfo.DoDraw(ACanvas: TcxCanvas);
begin
  if State <> cxbsDisabled then
    Owner.LookAndFeelPainter.DrawSliderButton(ACanvas, Bounds, FDirection, State);
end;

procedure TdxTileControlScrollButtonViewInfo.DoScrollContent;
const
  AScrollBarKind: array[TcxArrowDirection] of TScrollBarKind =
    (sbVertical, sbVertical, sbHorizontal, sbHorizontal);
  AScrollCode: array[TcxArrowDirection] of TScrollCode =
    (scLineUp, scLineDown, scLineUp, scLineDown);
var
  AScrollPos: Integer;
begin
  if FDirection in [adUp, adDown] then
    AScrollPos := ViewInfo.TopScrollPos
  else
    AScrollPos := ViewInfo.LeftScrollPos;
  Owner.Scroll(AScrollBarKind[FDirection], AScrollCode[FDirection], AScrollPos);
end;

function TdxTileControlScrollButtonViewInfo.GetArea: TRect;
begin
  Result := cxRectInflate(Bounds, 100, 100);
end;

function TdxTileControlScrollButtonViewInfo.GetController: TdxTileControlController;
begin
  Result := Owner.Controller;
end;

function TdxTileControlScrollButtonViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := False;
  if (Owner.DragAndDropState <> ddsNone) or
    not ViewInfo.IsScrollAvailable(FDirection) then Exit;
  Result := PtInRect(Bounds, AHitTest.HitPoint);
  if Result then
  begin
    AHitTest.HitObject := Self;
    AHitTest.BitState[tchtScrollButton] := True;
    if Controller.PressedScrollButton = Self then
      State := cxbsPressed
    else
      State := cxbsHot;
  end
  else
    if PtInCaller(AHitTest.HitPoint) then
    begin
      AHitTest.HitObject := Self;
      AHitTest.BitState[tchtScrollButtonArea] := True;
      State := cxbsNormal;
    end;
  if AHitTest.HitObject = Self then
    BeginMouseTracking(Owner, Area, Self);
end;

function TdxTileControlScrollButtonViewInfo.GetViewInfo: TdxTileControlViewInfo;
begin
  Result := Owner.ViewInfo;
end;

function TdxTileControlScrollButtonViewInfo.GetVisibleBounds: TRect;
begin
  Result := ViewInfo.TilesArea;
end;

procedure TdxTileControlScrollButtonViewInfo.Invalidate;
begin
  if Visible then
    if Owner.LookAndFeelPainter is TcxStandardLookAndFeelPainter then
      Owner.InvalidateRect(cxRectInflate(Bounds, 1, 1), False)
    else
      Owner.InvalidateRect(Bounds, False);
end;

procedure TdxTileControlScrollButtonViewInfo.RefreshState;
begin
end;

procedure TdxTileControlScrollButtonViewInfo.Scroll(const DX, DY: Integer);
begin
end;

procedure TdxTileControlScrollButtonViewInfo.SetState(const AValue: TcxButtonState);
begin
  if FState <> AValue then
  begin
    FState := AValue;
    Invalidate;
    FTimer.Enabled := FState = cxbsPressed;
  end;
end;

procedure TdxTileControlScrollButtonViewInfo.TimerHandler(Sender: TObject);
begin
  if Controller.PressedScrollButton = Self then
    DoScrollContent;
end;

// IcxMouseTrackingCaller2
procedure TdxTileControlScrollButtonViewInfo.MouseLeave;
begin
  EndMouseTracking(Self);
  State := cxbsDisabled;
end;

function TdxTileControlScrollButtonViewInfo.PtInCaller(const P: TPoint): Boolean;
begin
  Result := PtInRect(Area, P);
end;

{ TdxTileControlDetailSiteTitleViewInfo }

constructor TdxTileControlDetailSiteTitleViewInfo.Create(AOwner: TdxTileControlDetailSite);
begin
  inherited Create;
  FOwner := AOwner;
  FTabs := TdxTileControlCells.Create;
  FTabsFont := TFont.Create;
  FBackButtonViewInfo := CreateBackButtonViewInfo;
end;

destructor TdxTileControlDetailSiteTitleViewInfo.Destroy;
begin
  FreeAndNil(FBackButtonViewInfo);
  FreeAndNil(FTabsFont);
  FreeAndNil(FTabs);
  inherited Destroy;
end;

function TdxTileControlDetailSiteTitleViewInfo.CreateBackButtonViewInfo: TdxTileControlDetailSiteBackButtonViewInfo;
begin
  Result := TdxTileControlDetailSiteBackButtonViewInfo.Create(FOwner);
end;

procedure TdxTileControlDetailSiteTitleViewInfo.CalculateBackButton;
var
  ABounds: TRect;
begin
  ABounds := cxRect(0, 0, BackButtonViewInfo.MeasureWidth, BackButtonViewInfo.MeasureHeight);
  ABounds := cxRectSetRight(ABounds, Max(Bounds.Left + ABounds.Right + TextOffset, GetLeftOffset - TextOffset));
  ABounds := cxRectSetTop(ABounds, (VisibleBounds.Top + VisibleBounds.Bottom - cxRectHeight(ABounds)) div 2);
  BackButtonViewInfo.SetBounds(ABounds, VisibleBounds);
end;

procedure TdxTileControlDetailSiteTitleViewInfo.CalculateTabs;

  procedure CreateTabsViewInfo(out AActiveIndex: Integer);
  var
    AItem: TdxTileControlItem;
    I: Integer;
  begin
    AActiveIndex := -1;
    for I := 0 to TileControl.Items.Count - 1 do
    begin
      AItem := TileControl.Items[I];
      if AItem.ActuallyVisible and AItem.DetailOptions.ShowTab then
      begin
        FTabs.Add(CreateTabCellViewInfo(AItem));
        if AItem.IsActive then
          AActiveIndex := FTabs.Count - 1;
      end;
    end;
  end;

  procedure PlaceTabs(const R: TRect);
  var
    ABounds: TRect;
    ACell: TdxTileControlPageTabCellViewInfo;
    AOffset: Integer;
    I: Integer;
  begin
    AOffset := R.Left + TextOffset;
    for I := 0 to Tabs.Count - 1 do
    begin
      ACell := TdxTileControlPageTabCellViewInfo(Tabs[I]);
      ABounds := cxRectSetBottom(R, R.Bottom, Min(cxRectHeight(R), ACell.MeasureHeight));
      ABounds := cxRectSetWidth(ABounds, AOffset, ACell.MeasureWidth);
      ACell.SetBounds(ABounds, R);
      AOffset := ABounds.Right + cxTextOffset;
    end;
  end;

var
  AActiveIndex: Integer;
  ATabsBounds: TRect;
  I: Integer;
begin
  Tabs.Clear;
  CreateTabsViewInfo(AActiveIndex);

  ATabsBounds := cxRectSetXPos(Bounds, FTextBounds.Right, FGlyphBounds.Left);
  Dec(ATabsBounds.Right, TileControl.OptionsView.IndentHorz);

  PlaceTabs(ATabsBounds);
  while (Tabs.Count > 0) and (AActiveIndex > 0) and (Tabs[AActiveIndex].Bounds.Right > ATabsBounds.Right) do
  begin
    Tabs.FreeAndDelete(0);
    PlaceTabs(ATabsBounds);
  end;

  for I := Tabs.Count - 1 downto 0 do
  begin
    if Tabs[I].Bounds.Right > ATabsBounds.Right then
      Tabs.FreeAndDelete(I);
  end;

  if Tabs.Count > 0 then
  begin
    Inc(ATabsBounds.Left, ATabsBounds.Right - Tabs[Tabs.Count - 1].Bounds.Right);
    PlaceTabs(ATabsBounds);
  end;
end;

function TdxTileControlDetailSiteTitleViewInfo.CreateTabCellViewInfo(
  AItem: TdxTileControlItem): TdxTileControlPageTabCellViewInfo;
begin
  Result := TdxTileControlPageTabCellViewInfo.Create(Self, AItem);
end;

procedure TdxTileControlDetailSiteTitleViewInfo.DoCalculate;
begin
  CalculateBackButton;
  inherited DoCalculate;
  TabsFont.Assign(Title.Font);
  if Title.TabsFontSize = dxTileControlDefaultTabFontSize then
    TabsFont.Size := Painter.PageTabDefaultFontSize
  else
    TabsFont.Size := Title.TabsFontSize;
  CalculateTabs;
end;

procedure TdxTileControlDetailSiteTitleViewInfo.DoDraw(ACanvas: TcxCanvas);
var
  I: Integer;
begin
  ACanvas.SaveClipRegion;
  inherited DoDraw(ACanvas);
  ACanvas.RestoreClipRegion;
  BackButtonViewInfo.Draw(ACanvas);
  for I := 0 to Tabs.Count - 1 do
    Tabs[I].Draw(ACanvas);
  ACanvas.ExcludeClipRect(GetVisibleBounds);
end;

function TdxTileControlDetailSiteTitleViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
  begin
    if not BackButtonViewInfo.GetHitTest(AHitTest) then
      Tabs.CalculateHitTest(AHitTest);
  end;
end;

function TdxTileControlDetailSiteTitleViewInfo.GetVisibleBounds: TRect;
begin
  Result := inherited GetVisibleBounds;
  Result.Bottom := Max(Result.Bottom,
    Result.Top + BackButtonViewInfo.MeasureHeight + Title.IndentVert * 2);
end;

procedure TdxTileControlDetailSiteTitleViewInfo.RefreshState;
begin
  inherited RefreshState;
  BackButtonViewInfo.RefreshState;
  Tabs.RefreshState;
end;

function TdxTileControlDetailSiteTitleViewInfo.GetItem: TdxTileControlItem;
begin
  Result := FOwner.TileItem; 
end;

function TdxTileControlDetailSiteTitleViewInfo.GetTextLeftOffset: Integer;
begin
  Result := BackButtonViewInfo.Bounds.Right + TextOffset;
end;

function TdxTileControlDetailSiteTitleViewInfo.GetTileControl: TdxCustomTileControl;
begin
  Result := Item.TileControl;
end;

{ TdxTileControlDetailSite }

constructor TdxTileControlDetailSite.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FTitleViewInfo := CreateTitleViewInfo;
  FTitleViewInfo.FTitle := TileControl.Title;
  LookAndFeel.MasterLookAndFeel := TileControl.LookAndFeel;
  ControlStyle := ControlStyle + [csAcceptsControls, csNoDesignVisible];
  Visible := False;
  TabStop := False;
end;

destructor TdxTileControlDetailSite.Destroy;
begin
  EndMouseTracking(Self);
  FreeAndNil(FTitleViewInfo);
  inherited Destroy;
end;

procedure TdxTileControlDetailSite.CreateParams(var Params: TCreateParams);
begin
  inherited CreateParams(Params);
  with Params do
  begin
    Style := WS_CHILD or WS_CLIPCHILDREN or WS_CLIPSIBLINGS;
    ExStyle := WS_EX_CONTROLPARENT;
    WindowClass.Style := CS_DBLCLKS;
  end;
end;

procedure TdxTileControlDetailSite.BoundsChanged;
begin
  inherited BoundsChanged;
  TitleViewInfo.Recalculate;
  if ActiveControl <> nil then
    ActiveControl.Realign;
end;

procedure TdxTileControlDetailSite.DoPaint;
begin
  inherited DoPaint;
  TileControl.Painter.DrawBackground(Canvas, ClientBounds);
  if TitleViewInfo.Visible then
    TitleViewInfo.Draw(Canvas);
end;

procedure TdxTileControlDetailSite.MouseDown(
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseDown(Button, Shift, X, Y);
  HitTest.Calculate(X, Y);
  if HitTest.HitObject is TdxTileControlCustomCellViewInfo then
    PressedCell := TdxTileControlCustomCellViewInfo(HitTest.HitObject)
  else
    PressedCell := nil;
end;

procedure TdxTileControlDetailSite.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseMove(Shift, X, Y);
  BeginMouseTracking(Self, ClientBounds, Self);
  HitTest.Calculate(X, Y);
end;

procedure TdxTileControlDetailSite.MouseUp(
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  HitTest.Calculate(X, Y);
  if Button = mbRight then
    TileControl.Controller.ToggleActionBars
  else
    TileControl.Controller.HideActionBars;

  if (PressedCell = HitTest.HitObject) and (Button = mbLeft) then
  begin
    if HitTest.HitAtPageTab then
      TdxTileControlPageTabCellViewInfo(HitTest.HitObject).Item.Click
    else
      if HitTest.HitAtBackButton then
        TileControl.DoDeactivateDetail(Self);
    HitTest.HitObject := nil;
  end;
  PressedCell := nil;
end;

function TdxTileControlDetailSite.PtInCaller(const P: TPoint): Boolean;
begin
  Result := PtInRect(ClientRect, P);
  if Result and (ActiveControl <> nil) then
    Result := not PtInRect(ActiveControl.BoundsRect, P);
end;

procedure TdxTileControlDetailSite.ReallyMouseLeave;
var
  P: TPoint;
begin
  EndMouseTracking(Self);
  P := TileControl.ScreenToClient(GetMouseCursorPos);
  HitTest.Calculate(P.X, P.Y);
end;

function TdxTileControlDetailSite.CreateTitleViewInfo: TdxTileControlDetailSiteTitleViewInfo;
begin
  Result := TdxTileControlDetailSiteTitleViewInfo.Create(Self)
end;

procedure TdxTileControlDetailSite.DoActivateDetail;
begin
  TileItem.DoActivateDetail;
  TileControl.DoActivateDetail(Self);
end;

procedure TdxTileControlDetailSite.DoDeactivateDetail; 
begin
  TileControl.DoDeactivateDetail(Self);
  TileItem.DoDeactivateDetail;
end;

procedure TdxTileControlDetailSite.InitializeSite(ALeft: Integer);
var
  R: TRect;
  AIndentHorz, AIndentVert: Integer;
begin
  Align := alNone;
  Parent := TileControl;
  SetBounds(0, 0, 0, 0);
  SetBounds(ALeft, 0, TileControl.Width, TileControl.Height);
  TitleViewInfo.Recalculate;
  if ActiveControl <> nil then
  begin
    ActiveControl.Parent := Self;
    ActiveControl.Align := alNone;
    ActiveControl.Anchors := [akLeft..akBottom];
  end;
  AIndentHorz := TileControl.OptionsView.IndentHorz;
  AIndentVert := TileControl.OptionsView.IndentVert;
  R := cxRectInflate(TileControl.ViewInfo.ClientBounds,
    -AIndentHorz, -TitleViewInfo.Bounds.Bottom -AIndentVert, -AIndentHorz, -AIndentVert);
  if ActiveControl <> nil then
  begin
    ActiveControl.BoundsRect := R;
    ActiveControl.Visible := True;
  end;
  Visible := True;
  BringToFront;
  Realign;
end;

function TdxTileControlDetailSite.GetActiveControl: TWinControl;
begin
  Result := TileItem.DetailOptions.DetailControl
end;

function TdxTileControlDetailSite.GetHitTest: TdxTileControlHitTest;
begin
  Result := TileControl.HitTest;
end;

function TdxTileControlDetailSite.GetIndex: Integer;
begin
  Result := TileItem.Index;
end;

function TdxTileControlDetailSite.GetTileControl: TdxCustomTileControl;
begin
  Result := TileItem.TileControl;
end;

function TdxTileControlDetailSite.GetTileItem: TdxTileControlItem;
begin
  Result := TdxTileControlItem(GetOwner);
end;

procedure TdxTileControlDetailSite.SetPressedCell(AValue: TdxTileControlCustomCellViewInfo);
begin
  if AValue <> FPressedCell then
  begin
    FPressedCell := AValue;
    TitleViewInfo.RefreshState;
  end;
end;

{ TdxTileControlCheckedItems }

function TdxTileControlCheckedItems.GetItem(Index: Integer): TdxTileControlItem;
begin
  Result := TdxTileControlItem(inherited Items[Index]); 
end;

{ TdxCustomTileControl }

constructor TdxCustomTileControl.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  Keys := [kArrows, kChars];
  FLockCount := 0;
  FChanges := [];
  Height := 300;
  Width := 400;
  Align := alClient; // by design must accept all content area
  CreateSubClasses;
end;

destructor TdxCustomTileControl.Destroy;
begin
  CancelMouseOperations;
  ActiveDetail := nil;
  DestroySubClasses;
  inherited Destroy;
end;

procedure TdxCustomTileControl.BeginUpdate;
begin
  Inc(FLockCount);
end;

procedure TdxCustomTileControl.CancelUpdate;
begin
  Dec(FLockCount);
  if FLockCount = 0 then
    CheckChanges;
end;

function TdxCustomTileControl.CreateGroup: TdxTileControlGroup;
begin
  BeginUpdate;
  try
    Result := Groups.Add;
  finally
    EndUpdate;
  end;
  Result.MakeVisible;
end;

function TdxCustomTileControl.CreateItem(AIsLarge: Boolean = False;
  AGroup: TdxTileControlGroup = nil): TdxTileControlItem;
begin
  BeginUpdate;
  try
    Result := Items.Add;
    Result.IsLarge := AIsLarge;
    if AGroup = nil then
    begin
      if Groups.Count > 0 then
        AGroup := Groups.Items[Groups.Count - 1]
      else
        AGroup := CreateGroup;
    end;
    Result.Group := AGroup;
  finally
    EndUpdate;
  end;
  Result.MakeVisible;
end;

procedure TdxCustomTileControl.DblClick;
begin
  if (Controller.DesignHelper <> nil) and Controller.HitAtItem then
    Controller.DesignHelper.CreateItemClickHandler(HitTest.Item)
  else
    inherited DblClick;
end;

procedure TdxCustomTileControl.DeleteItem(AItem: TdxTileControlItem);
var
  AGroup: TdxTileControlGroup;
begin
  if AItem = nil then Exit;
  BeginUpdate;
  try
    AGroup := AItem.Group;
    if AGroup <> nil then
    begin
      AGroup.DeleteItem(AItem);
      RemoveGroupIfEmpty(AGroup);
    end
    else
      FreeAndNil(AItem);
  finally
    EndUpdate;
  end;
end;

procedure TdxCustomTileControl.EndUpdate;
begin
  Dec(FLockCount);
  LayoutChanged;
end;

function TdxCustomTileControl.GetActionBarBottomBounds: TRect;
begin
  Result := cxRectSetBottom(ClientRect, ClientRect.Bottom, ActionBarBottom.ViewInfo.MeasureHeight);
end;

function TdxCustomTileControl.GetActionBarTopBounds: TRect;
begin
  Result := cxRectSetHeight(ClientRect, ActionBarTop.ViewInfo.MeasureHeight);
end;

function TdxCustomTileControl.GetCheckedItem(Index: Integer): TdxTileControlItem;
begin
  Result := TdxTileControlItem(FCheckedItems[Index]);
end;

function TdxCustomTileControl.GetCheckedItemCount: Integer;
begin
  Result := FCheckedItems.Count;
end;

procedure TdxCustomTileControl.GetChildren(Proc: TGetChildProc; Root: TComponent);

  procedure ProcessCollection(ACollection: TcxComponentCollection);
  var
    I: Integer;
  begin
    for I := 0 to ACollection.Count - 1 do
    begin
      if ACollection[I].Owner = Root then
        Proc(ACollection[I]);
    end;
  end;

begin
  inherited GetChildren(Proc, Root);
  ProcessCollection(ActionBars.Items);
  ProcessCollection(Groups);
  ProcessCollection(Items);
end;

function TdxCustomTileControl.IsMouseInPressedArea(X, Y: Integer): Boolean;
begin
  Result :=(Abs(X - MouseDownPos.X) < 2) and (Abs(Y - MouseDownPos.Y) < 2);
end;

procedure TdxCustomTileControl.AfterActiveDetailChangingAnimation(
  AActiveDetail, ANewDetail: TdxTileControlDetailSite);
begin
  if AActiveDetail <> nil then
  begin
    AActiveDetail.Parent := nil;
    AActiveDetail.RemoveFreeNotification(Self);
  end;
  FActiveDetail := ANewDetail;
  if ANewDetail <> nil then
  begin
    ANewDetail.FreeNotification(Self);
//    SendMessage(Handle, WM_SETREDRAW, 0, 0);
    ANewDetail.Align := alClient;
    ANewDetail.BringToFront;
    if ANewDetail.ActiveControl <> nil then
      ANewDetail.ActiveControl.SetFocus
    else
      ANewDetail.SetFocus;
//    SendMessage(Handle, WM_SETREDRAW, 1, 0);
    ANewDetail.InvalidateWithChildren;
  end
  else
  begin
    LayoutChanged;
    Controller.StartFramesAnimation;
    SetFocus;
  end;
  Controller.RefreshItems;
end;

procedure TdxCustomTileControl.AnimationHandler(Sender: TdxAnimationTransition;
  var APosition: Integer; var AFinished: Boolean);
begin
  Refresh;
  if AFinished then
  begin
    FAnimation := nil;
    FDetailsAnimationInProcess := False;
  end;
end;

procedure TdxCustomTileControl.BeforeActiveDetailChangingAnimation(
  AActiveDetail, ANewDetail: TdxTileControlDetailSite);

  function GetIndex(AValue: TdxTileControlDetailSite): Integer;
  begin
    Result := -1;
    if AValue <> nil then
      Result := AValue.Index;
  end;

  function CreateImage(AValue: TdxTileControlDetailSite): TcxBitmap32;
  begin
    Result := TcxBitmap32.CreateSize(ClientRect);
    if AValue <> nil then
      cxPaintTo(AValue, Result.cxCanvas, cxNullPoint, Rect(0, 0, AValue.Width, AValue.Height))
    else
      ViewInfo.Draw(Result.cxCanvas);
    Result.MakeOpaque; 
  end;

var
  AStartImage, AFinishImage: TcxBitmap32;
begin
  FDetailsAnimationInProcess := True;
  if AActiveDetail = nil then
    Controller.StopAnimations;
  HitTest.Clear;
  Repaint; 
  if AActiveDetail <> nil then
  begin
    AActiveDetail.TileItem.FIsActive := False;
    AActiveDetail.TitleViewInfo.Recalculate;
  end;
  if ANewDetail <> nil then
  begin
    ANewDetail.TileItem.FIsActive := True;
    ANewDetail.InitializeSite(Width);
    ANewDetail.TitleViewInfo.Recalculate;
  end;
  AStartImage := CreateImage(AActiveDetail);
  try
    AFinishImage := CreateImage(ANewDetail);
    try
      if AActiveDetail <> nil then
        AActiveDetail.Align := alNone;
      FAnimation := TdxImageAnimationTransition.Create(AStartImage, AFinishImage,
        dxTileControlActivateDetailAnimationTime,
        TdxDrawAnimationMode(Sign(GetIndex(AActiveDetail) - GetIndex(ANewDetail)) + 1));
      FAnimation.OnAnimate := AnimationHandler;
    finally
      AFinishImage.Free;
    end;
  finally
    AStartImage.Free;
  end;
end;

function TdxCustomTileControl.GetActiveHitTest: TdxTileControlHitTest;
var
  APos: TPoint;

  function CheckActionBarHitTest(AActionBar: TdxTileControlCustomActionBar): TdxTileControlHitTest;
  const
    AIndex: array[Boolean] of Integer = (tchtActionBarBottom, tchtActionBarTop);
  begin
    Result := HitTest;
    AActionBar.HitTest.HitPoint := AActionBar.ScreenToClient(APos);
    if AActionBar.HitTest.HitObject <> nil then
    begin
      Result := AActionBar.HitTest;
      Result.BitState[AIndex[AActionBar = ActionBarTop]] := True;
    end;
  end;

begin
  APos := GetMouseCursorPos;
  Result := HitTest;
  if IsActionBarTopVisible then
    Result := CheckActionBarHitTest(ActionBarTop);
  if (Result = HitTest) and IsActionBarBottomVisible then
    Result := CheckActionBarHitTest(ActionBarBottom);
  if (Result = HitTest) and (ActiveDetail <> nil) then
    Result := ActiveDetail.HitTest;
end;

function TdxCustomTileControl.GetDraggedGroup: TdxTileControlGroup;
begin
  if IsGroupDragged then
    Result := TdxTileControlDragDropGroup(DragAndDropObject).DragGroup
  else
    Result := nil;
end;

function TdxCustomTileControl.GetDraggedItem: TdxTileControlItem;
begin
  if IsItemDragged then
    Result := TdxTileControlDragDropItem(DragAndDropObject).DragItem
  else
    Result := nil;
end;

function TdxCustomTileControl.GetIsLocked: Boolean;
begin
  Result := IsLoading or IsDestroying;
  if not Result then
    Result := FLockCount <> 0;
end;

procedure TdxCustomTileControl.InitScrollBarsParameters;
var
  AMin: Integer;
begin
  if ([csLoading, csDestroying, csUpdating, csReading] * ComponentState <> []) or
    (ViewInfo = nil) then Exit;
  AMin := 0;
  if Controller.IsHandScrolling(sbHorizontal) then
    AMin := Min(0, ViewInfo.LeftScrollPos);
  SetScrollBarInfo(sbHorizontal, AMin, ViewInfo.ContentWidth - 1 + AMin,
    dxTileControlScrollStep, ViewInfo.HorzScrollPage, ViewInfo.LeftScrollPos,
   (OptionsBehavior.ScrollMode = smScrollbars), True);

  AMin := 0;
  if Controller.IsHandScrolling(sbVertical) then
    AMin := Min(0, ViewInfo.TopScrollPos);
  SetScrollBarInfo(sbVertical, AMin, ViewInfo.ContentHeight - 1 + AMin,
    dxTileControlScrollStep, ViewInfo.VertScrollPage, ViewInfo.TopScrollPos,
   (OptionsBehavior.ScrollMode = smScrollbars), True);
end;

function TdxCustomTileControl.InsertGroup(AIndex: Integer): TdxTileControlGroup;
begin
  BeginUpdate;
  try
    Result := Groups.Insert(AIndex);                                        
  finally
    EndUpdate;
  end;
end;

function TdxCustomTileControl.IsActionBarTopVisible: Boolean;
begin
  Result := (ActionBarTop <> nil) and ActionBarTop.Visible;
end;

function TdxCustomTileControl.IsActionBarBottomVisible: Boolean;
begin
  Result := (ActionBarBottom <> nil) and ActionBarBottom.Visible;
end;

function TdxCustomTileControl.IsAnyActionBarVisible: Boolean;
begin
  Result := IsActionBarTopVisible or IsActionBarBottomVisible;
end;

function TdxCustomTileControl.IsDestroying: Boolean;
begin
  Result := csDestroying in ComponentState;
end;

function TdxCustomTileControl.IsDoubleBufferedNeeded: Boolean;
begin
  Result := True;
end;

function TdxCustomTileControl.IsLoading: Boolean;
begin
  Result := csLoading in ComponentState;
end;

procedure TdxCustomTileControl.DoActivateDetail(
  ADetail: TdxTileControlDetailSite);
begin
  ActiveDetail := ADetail;
end;

procedure TdxCustomTileControl.DoItemCheck(AItem: TdxTileControlItem);
begin
  if Assigned(OnItemCheck) then
    OnItemCheck(Self, AItem);
end;

function TdxCustomTileControl.DoItemBeforeCheck(AItem: TdxTileControlItem): Boolean;
begin
  Result := True;
  if Assigned(OnItemBeforeCheck) then
    OnItemBeforeCheck(Self, AItem, Result);
end;

procedure TdxCustomTileControl.DoCancelMode;
begin
  inherited DoCancelMode;
  Controller.RefreshItems;
end;

procedure TdxCustomTileControl.DoDeactivateDetail(
  ADetail: TdxTileControlDetailSite);
begin
  ActiveDetail := nil;
end;


procedure TdxCustomTileControl.DoInitStoredObject(AObject: TObject);
begin
  if (AObject <> nil) and Assigned(OnInitStoredObject) then
    FOnInitStoredObject(Self, AObject);
end;

procedure TdxCustomTileControl.DoItemDragBegin(var AAllow: Boolean);
begin
  InitializeDragItemInfo;
  if Assigned(FOnItemDragBegin) then
    FOnItemDragBegin(Self, FDragItemInfo, AAllow);
end;

procedure TdxCustomTileControl.DoItemDragEnd;
begin
  if Assigned(FOnItemDragEnd) then
    FOnItemDragEnd(Self, FDragItemInfo);
end;

procedure TdxCustomTileControl.DoItemDragOver(var AAccept: Boolean);
begin
  if Assigned(FOnItemDragOver) then
    FOnItemDragOver(Self, FDragItemInfo, AAccept);
end;

procedure TdxCustomTileControl.DoPaint;
begin
  inherited DoPaint;
  if Animation <> nil then
    Animation.Draw(Canvas.Canvas, ClientRect)
  else
    if ActiveDetail = nil then
      ViewInfo.Draw(Canvas);
end;

procedure TdxCustomTileControl.DrawScrollBars(ACanvas: TcxCanvas);
begin
  if not DetailsAnimationInProcess then 
    inherited DrawScrollBars(ACanvas);
end;

function TdxCustomTileControl.FindGroup(const AName: string): TdxTileControlGroup;
var
  I: Integer;
begin
  Result := nil;
  for I := 0 to Groups.Count - 1 do
    if Groups[I].Name = AName then
    begin
      Result := Groups[I];
      Break;
    end;
end;

procedure TdxCustomTileControl.FocusChanged;
begin
  inherited FocusChanged;
  Controller.RefreshItems;
end;

procedure TdxCustomTileControl.ForceUpdate(AUpdateAll: Boolean = False);
begin
  dxAnimationController.Update;
  if AUpdateAll then
    Invalidate;
  Update;
end;

function TdxCustomTileControl.GetDesignHitTest(X, Y: Integer; Shift: TShiftState): Boolean;
begin
  Result := (DragAndDropState <> ddsNone);
  if not Result then
    HitTest.Calculate(X, Y);
  FRightButtonPressed := (ssRight in Shift) and Controller.HitAtItemOrGroup and
    (DragAndDropState = ddsNone);
  if FRightButtonPressed then
    Result := True
  else
    Result := False or (DragAndDropState <> ddsNone);
  if not Result and (ssLeft in Shift) then
    Result := not FRightButtonPressed and
      (Controller.HitAtItemOrGroup or HitTest.HitAtScrollButton or (DragAndDropState <> ddsNone));
end;

function TdxCustomTileControl.GetDragAndDropObjectClass: TcxDragAndDropObjectClass;
begin
  if Controller.HitAtItem and OptionsBehavior.ItemMoving then
    Result := TdxTileControlDragDropItem
  else
    if Controller.HitAtGroup and OptionsBehavior.GroupMoving then
      Result := TdxTileControlDragDropGroup
    else
      Result := TdxTileControlHandScroll;
end;

function TdxCustomTileControl.GetMainScrollBarsClass: TcxControlCustomScrollBarsClass;
begin
  Result := TcxControlScrollBars;
end;

function TdxCustomTileControl.GetMouseWheelScrollingKind: TcxMouseWheelScrollingKind;
begin
  Result := inherited GetMouseWheelScrollingKind;
  if OptionsView.GroupLayout = glHorizontal then
  begin
    if (Result =  mwskNone) and (HScrollBarVisible or (OptionsBehavior.ScrollMode = smScrollButtons)) then
      Result := mwskHorizontal
  end
  else
    if (Result =  mwskNone) and (VScrollBarVisible or (OptionsBehavior.ScrollMode = smScrollButtons)) then
      Result := mwskVertical
end;

function TdxCustomTileControl.GetVScrollBarBounds: TRect;
begin
  Result := inherited GetVScrollBarBounds;
  Result.Top := Title.ViewInfo.Bounds.Bottom;
end;

procedure TdxCustomTileControl.AddChanges(AChanges: TdxTileControlChanges);
begin
  FChanges := FChanges + AChanges;
  CheckChanges;
end;

procedure TdxCustomTileControl.BoundsChanged;
begin
  FForceCalculate := True;
  try
    inherited BoundsChanged;
    AddChanges([tccLayout]);
    RefreshActionBars;
  finally
    FForceCalculate := False; 
  end;
end;

procedure TdxCustomTileControl.BringInternalControlsToFront;
begin
  inherited BringInternalControlsToFront;
  if ActionBarBottom <> nil then
    ActionBarBottom.BringToFront;
  if ActionBarTop <> nil then
    ActionBarTop.BringToFront;
end;

function TdxCustomTileControl.CanAutoSize(var NewWidth, NewHeight: Integer): Boolean;
begin
  NewWidth := Width;
  NewHeight := Height;
  Result := AutoSize and (OptionsView.GroupLayout = glVertical) and
    (ViewInfo.ContentWidth > cxRectWidth(ClientBounds));
  if Result then
  begin
    NewWidth := ViewInfo.ContentWidth + BorderSize * 2;
    if VScrollBarVisible then
      Inc(NewWidth, VScrollBar.Width);
  end;
end;

procedure TdxCustomTileControl.CheckChanges;
begin
  if IsLocked or (Changes = []) then Exit;
  ValidateChanges;
end;

function TdxCustomTileControl.CreateGroupsCollection: TdxTileControlGroupCollection;
begin
  Result := TdxTileControlGroupCollection.Create(Self, TdxTileControlGroup);
end;

function TdxCustomTileControl.CreateItemsCollection: TdxTileControlItemCollection;
begin
  Result := TdxTileControlItemCollection.Create(Self, TdxTileControlItem);
end;

function TdxCustomTileControl.CreatePainter: TdxTileControlPainter;
begin
  Result := TdxTileControlPainter.Create(Self);
end;

function TdxCustomTileControl.CreateStyle: TdxTileControlStyle;
begin
  Result := TdxTileControlStyle.Create(Self);
  Result.OnChange := StyleChanged;
end;

function TdxCustomTileControl.CreateTitle: TdxTileControlTitle;
begin
  Result := TdxTileControlTitle.Create(Self);
end;

procedure TdxCustomTileControl.CreateSubClasses;
begin
  FCheckedItems := TdxTileControlCheckedItems.Create;
  FStyle := CreateStyle;
  FGroups := CreateGroupsCollection;
  FItems := CreateItemsCollection;
  FViewInfo := CreateViewInfo;
  FHitTest := CreateHitTest;
  FAssets := CreateAssets;
  FActionBars := CreateActionBars;
  FOptionsView := TdxTileControlOptionsView.Create(Self);
  FOptionsBehavior := TdxTileControlOptionsBehavior.Create(Self);
  FOptionsItemAnimate := TdxTileControlCustomItemOptionsAnimate.Create(Self);
  FController := CreateController;
  FPainter := CreatePainter;
  FTitle := CreateTitle;
  FDragItemInfo := TdxTileControlDragItemInfo.Create;
end;

function TdxCustomTileControl.CreateActionBarBottom: TdxTileControlCustomActionBar;
begin
  Result := TdxTileControlBottomActionBar.Create(Self);
end;

function TdxCustomTileControl.CreateActionBars: TdxTileControlActionBars;
begin
  Result := TdxTileControlActionBars.Create(Self);
end;

function TdxCustomTileControl.CreateActionBarTop: TdxTileControlCustomActionBar;
begin
  Result := TdxTileControlTopActionBar.Create(Self);
end;

function TdxCustomTileControl.CreateAssets: TdxTileControlAssets;
begin
  Result := TdxTileControlAssets.Create;
end;

function TdxCustomTileControl.CreateController: TdxTileControlController;
begin
  Result := TdxTileControlController.Create(Self);
end;

function TdxCustomTileControl.CreateHitTest: TdxTileControlHitTest;
begin
  Result := TdxTileControlHitTest.Create(Self);
end;

function TdxCustomTileControl.CreateViewInfo: TdxTileControlViewInfo;
begin
  Result := TdxTileControlViewInfo.Create(Self);
end;

procedure TdxCustomTileControl.CreateWnd;
begin
  Controller.DestroyDesignHelper;
  inherited CreateWnd;
  Controller.CheckCreateDesignHelper;
end;

procedure TdxCustomTileControl.DestroySubClasses;
begin
  FController.StopAnimations;
  TdxTileControlActionsBarHelper.Unregister(Self);
  FreeAndNil(FItems);
  FreeAndNil(FGroups);
  FreeAndNil(FHitTest);
  FreeAndNil(FViewInfo);
  FreeAndNil(FController);
  FreeAndNil(FActionBars);
  FreeAndNil(FPainter);
  FreeAndNil(FStyle);
  FreeAndNil(FAssets);
  FreeAndNil(FActionBarTop);
  FreeAndNil(FActionBarBottom);
  FreeAndNil(FOptionsBehavior);
  FreeAndNil(FOptionsItemAnimate);
  FreeAndNil(FOptionsView);
  FreeAndNil(FCheckedItems);
  FreeAndNil(FTitle);
  FreeAndNil(FDragItemInfo);
end;

procedure TdxCustomTileControl.LayoutChanged;
begin
  Changes := Changes + [tccLayout];
  if IsLocked then Exit;
  CheckChanges;
  if AutoSize then
    AdjustSize;
end;

procedure TdxCustomTileControl.KeyDown(var Key: Word; Shift: TShiftState);
begin
  inherited KeyDown(Key, Shift);
  Controller.KeyDown(Key, Shift);
end;

procedure TdxCustomTileControl.Loaded;
begin
  inherited Loaded;
  Groups.Loaded;
  LayoutChanged;
  Controller.StartAnimations;
  Controller.CheckCreateDesignHelper;
end;

procedure TdxCustomTileControl.LockTimers;
var
  I: Integer;
begin
  if Items = nil then Exit;
  for I := 0 to Items.Count - 1 do
    Items[I].FAnimationTimer.Enabled := False;
end;

procedure TdxCustomTileControl.LookAndFeelChanged(Sender: TcxLookAndFeel; 
  AChangedValues: TcxLookAndFeelValues);
begin
  inherited LookAndFeelChanged(Sender, AChangedValues);
  AddChanges([tccItems]);
  Painter.ValidatePainterData;
  if ActiveDetail <> nil then
    ActiveDetail.Invalidate;
  Invalidate;
end;

procedure TdxCustomTileControl.MouseDown(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  Controller.MouseDown(Button, Shift, X, Y);
  inherited MouseDown(Button, Shift, X, Y);
end;

procedure TdxCustomTileControl.MouseLeave(AControl: TControl);
begin
  if AControl = Self then
    Controller.MouseLeave;
  inherited MouseLeave(AControl);
end;

procedure TdxCustomTileControl.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  Controller.MouseMove(Shift, X, Y);
  inherited MouseMove(Shift, X, Y);
end;

procedure TdxCustomTileControl.MouseUp(Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  Controller.MouseUp(Button, Shift, X, Y);
end;

procedure TdxCustomTileControl.Notification(
  AComponent: TComponent; Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if not IsDestroying and (Operation = opRemove) and (AComponent = ActiveDetail) then
  begin
    FActiveDetail := nil;
    Repaint;
  end;
end;

procedure TdxCustomTileControl.ReCreateViewInfo;
begin
  FreeAndNil(FViewInfo);
  FViewInfo := CreateViewInfo;
  LayoutChanged;
end;

procedure TdxCustomTileControl.RemoveGroup(AGroup: TdxTileControlGroup);
begin
  if AGroup = nil then Exit;
  FGroups.Remove(AGroup);
end;

procedure TdxCustomTileControl.RemoveGroupIfEmpty(AGroup: TdxTileControlGroup);
begin
  if (AGroup = nil) or (AGroup.ItemCount > 0) then Exit;
  BeginUpdate;
  try
    RemoveGroup(AGroup);
  finally
    EndUpdate;
  end;
end;

procedure TdxCustomTileControl.RefreshItems;
begin
  Controller.StopAnimations;
  try
    Items.ForEach(RefreshItem, nil, False);
  finally
    Controller.StartAnimations;
  end;
end;

procedure TdxCustomTileControl.HideActionBars;
begin
  TdxTileControlActionsBarHelper.Unregister(Self);
  if IsAnyActionBarVisible then
    TdxTileControlActionBarsAnimation.Create(Self, tcabamHide).ImmediateAnimation;
end;

procedure TdxCustomTileControl.ShowActionBars;
begin
  if not IsAnyActionBarVisible then
  begin
    if ActionBarTop = nil then
    begin
      FActionBarTop := CreateActionBarTop;
      FActionBarTop.Parent := Self;
    end;
    if ActionBarBottom = nil then
    begin
      FActionBarBottom := CreateActionBarBottom;
      FActionBarBottom.Parent := Self;
    end;
    BringInternalControlsToFront;
    TdxTileControlActionBarsAnimation.Create(Self, tcabamShow).ImmediateAnimation;
    TdxTileControlActionsBarHelper.Register(Self);
  end;
end;

procedure TdxCustomTileControl.Scroll(AScrollBarKind: TScrollBarKind;
  AScrollCode: TScrollCode; var AScrollPos: Integer);
begin
  if AScrollCode = scEndScroll then Exit;
  if AScrollBarKind = sbHorizontal then
    ScrollHorz(AScrollBarKind, AScrollCode, AScrollPos)
  else
    ScrollVert(AScrollBarKind, AScrollCode, AScrollPos);
  ForceUpdate;
end;

procedure TdxCustomTileControl.ScrollHorz(AScrollBarKind: TScrollBarKind;
  AScrollCode: TScrollCode; var AScrollPos: Integer);
begin
  if not (AScrollCode in [scTrack, scPosition]) then
    AScrollPos := ViewInfo.LeftScrollPos;
  case AScrollCode of
    scLineUp:
      Dec(AScrollPos, dxTileControlScrollStep);
    scLineDown:
      Inc(AScrollPos, dxTileControlScrollStep);
    scPageUp:
      Dec(AScrollPos, ViewInfo.HorzScrollPage);
    scPageDown:
      Inc(AScrollPos, ViewInfo.HorzScrollPage);
    scTop:
      AScrollPos := 0;
    scBottom:
      AScrollPos := ViewInfo.ContentWidth;
  end;
  ViewInfo.LeftScrollPos := AScrollPos;
end;

procedure TdxCustomTileControl.ScrollVert(AScrollBarKind: TScrollBarKind;
  AScrollCode: TScrollCode; var AScrollPos: Integer);
var
  AGroupLayout: TdxTileControlGroupLayout;
begin
  if not (AScrollCode in [scTrack, scPosition]) then
    AScrollPos := ViewInfo.TopScrollPos;
  AGroupLayout := OptionsView.GroupLayout;
  case AScrollCode of
    scLineUp:
      Dec(AScrollPos, dxTileControlScrollStep);
    scLineDown:
      Inc(AScrollPos, dxTileControlScrollStep);
    scPageUp:
      begin
        if AGroupLayout = glHorizontal then
          Dec(AScrollPos, ViewInfo.HorzScrollPage)
        else
          Dec(AScrollPos, ViewInfo.VertScrollPage);
      end;
    scPageDown:
      begin
        if AGroupLayout = glHorizontal then
          Inc(AScrollPos, ViewInfo.HorzScrollPage)
        else
          Inc(AScrollPos, ViewInfo.VertScrollPage);
      end;
    scTop:
      AScrollPos := 0;
    scBottom:
      begin
        if AGroupLayout = glHorizontal then
          AScrollPos := ViewInfo.ContentWidth
        else
          AScrollPos := ViewInfo.ContentHeight;
      end;
  end;
  ViewInfo.TopScrollPos := AScrollPos;
end;

procedure TdxCustomTileControl.StyleChanged(Sender: TObject);
begin
  LayoutChanged;
end;

procedure TdxCustomTileControl.UnlockTimers;
var
  I: Integer;
begin
  if Items = nil then Exit;
  for I := 0 to Items.Count - 1 do
    Items[I].CheckTimerEnabled;
end;

procedure TdxCustomTileControl.ValidateChanges;
begin
  LockTimers;
  try
    if tccItems in Changes then
    begin
      Include(FChanges, tccLayout);
      RefreshItems;
    end;
    if tccLayout in Changes then
    begin
      ViewInfo.Calculate;
      if ActiveDetail <> nil then
        ActiveDetail.TitleViewInfo.Recalculate;
    end;
    if ActiveDetail <> nil then
      ActiveDetail.Invalidate
    else
      Invalidate;
  finally
    Changes := [];
    UnlockTimers;
  end;
end;

procedure TdxCustomTileControl.WMContextMenu(var Message: TWMContextMenu);
begin
  inherited;
  Controller.ProcessContextMenuMessage(Message);
end;

procedure TdxCustomTileControl.InitializeDragItemInfo;
var
  ADragItem: TdxTileControlItem;
begin
  ADragItem := HitTest.Item;
  FDragItemInfo.FItem := ADragItem;
  FDragItemInfo.FSourceGroup := ADragItem.Group;
  FDragItemInfo.FGroup := FDragItemInfo.SourceGroup;
end;

function TdxCustomTileControl.IsGroupDragged: Boolean;
begin
  Result := (DragAndDropState = ddsInProcess) and
    (DragAndDropObject is TdxTileControlDragDropGroup);
end;

function TdxCustomTileControl.IsItemDragged: Boolean;
begin
  Result := (DragAndDropState = ddsInProcess) and
    (DragAndDropObject is TdxTileControlDragDropItem);
end;

function TdxCustomTileControl.IsStyleStored: Boolean;
begin
  Result := Style.IsChanged;
end;

function TdxCustomTileControl.IsTitleStored: Boolean;
begin
  Result := FTitle.IsChanged;
end;

procedure TdxCustomTileControl.RefreshActionBars;
begin
  if (ActionBarTop <> nil) and (ActionBarBottom <> nil) then
  begin
    ActionBarBottom.BoundsRect := GetActionBarBottomBounds;
    ActionBarTop.BoundsRect := GetActionBarTopBounds;
    BringInternalControlsToFront;
    ActionBarBottom.Recalculate;
    ActionBarTop.Recalculate;
  end;
end;

procedure TdxCustomTileControl.RefreshItem(AItem: TdxTileControlItem; const AData: Pointer);
begin
  AItem.Changed;
end;

procedure TdxCustomTileControl.SetActionBars(AValue: TdxTileControlActionBars);
begin
  FActionBars.Assign(AValue);
end;

procedure TdxCustomTileControl.SetActiveDetail(AValue: TdxTileControlDetailSite);
begin
  if IsDesigning then
    AValue := nil;
  if ActiveDetail <> nil then
    ActiveDetail.TileItem.DoDeactivateDetail;
  if IsDestroying then
  begin
    FActiveDetail := nil;
    Exit;
  end;
  if FActiveDetail <> AValue then
  begin
    Controller.HideActionBars;
    Controller.UncheckAllItems;
    BeforeActiveDetailChangingAnimation(FActiveDetail, AValue);
    try
      if ActiveDetail <> nil then
      begin
        SendMessage(Handle, WM_SETREDRAW, 0, 0);
        ActiveDetail.Parent := nil;
        SendMessage(Handle, WM_SETREDRAW, 1, 0);
      end;
      if IsLoading or IsDestroying then
        FreeAndNil(FAnimation)
      else
        FAnimation.ImmediateAnimation;
    finally
      AfterActiveDetailChangingAnimation(FActiveDetail, AValue);
    end;
  end;
end;

procedure TdxCustomTileControl.SetAutoSize(Value: Boolean);
begin
  inherited SetAutoSize(Value);
  LayoutChanged;
end;

procedure TdxCustomTileControl.SetOptionsItemAnimate(AValue: TdxTileControlCustomItemOptionsAnimate);
begin
  FOptionsItemAnimate.Assign(AValue);
end;

procedure TdxCustomTileControl.SetOptionsBehavior(AValue: TdxTileControlOptionsBehavior);
begin
  FOptionsBehavior.Assign(AValue);
end;

procedure TdxCustomTileControl.SetOptionsView(AValue: TdxTileControlOptionsView);
begin
  FOptionsView.Assign(AValue);
end;

procedure TdxCustomTileControl.SetStyle(AValue: TdxTileControlStyle);
begin
  FStyle.Assign(AValue);
end;

procedure TdxCustomTileControl.SetTitle(AValue: TdxTileControlTitle);
begin
  FTitle.Assign(AValue);
end;

function TdxCustomTileControl.StartDragAndDrop(const P: TPoint): Boolean;
begin
  if ViewInfo.DragDropChanges <> nil then
  begin
    Result := False;
    Exit;
  end;    
  HitTest.HitPoint := P;
  Result := not FRightButtonPressed and not HitTest.HitAtScrollButton and
    not HitTest.HitAtTitle and
    (Controller.CanItemMoving or Controller.CanGroupMoving or
     (ViewInfo.IsScrollAvailable and not IsDesigning));
  DragDropInProcess := Result;
  Controller.DragCell := HitTest.HitObject;
  Controller.StartDragPos := P;
end;

// IcxStoredObject

function TdxCustomTileControl.GetObjectName: string;
begin
  Result := GetStoredObjectName;
end;

function TdxCustomTileControl.GetProperties(AProperties: TStrings): Boolean;
begin
  Result := GetStoredObjectProperties(AProperties);
end;

procedure TdxCustomTileControl.GetPropertyValue(const AName: string; var AValue: Variant);
begin
  GetStoredPropertyValue(AName, AValue);
end;

procedure TdxCustomTileControl.SetPropertyValue(const AName: string; const AValue: Variant);
begin
  SetStoredPropertyValue(AName, AValue);
end;

// used classes

function TdxCustomTileControl.GetGroupsClass: TdxTileControlGroupCollectionClass;
begin
  Result := TdxTileControlGroupCollection;
end;

function TdxCustomTileControl.GetItemsClass: TdxTileControlItemCollectionClass;
begin
  Result := TdxTileControlItemCollection;
end;

// store-restore layout

procedure TdxCustomTileControl.RestoreFrom(AStorageType: TcxStorageType;
  const AStorageName: string; AStorageStream: TStream;
  ACreateChildren, ADeleteChildren: Boolean; const ARestoreName: string);
var
  AStorage: TcxStorage;
  AModes: TcxStorageModes;
begin
  FStoringName := ARestoreName;
  AStorage := TcxStorage.Create(AStorageName, AStorageStream);
  try
    AModes := [];
    if ACreateChildren then
      Include(AModes, smChildrenCreating);
    if ADeleteChildren then
      Include(AModes, smChildrenDeleting);
    AStorage.Modes := AModes;
    AStorage.UseInterfaceOnly := True;
    if ARestoreName = '' then
      AStorage.NamePrefix := Owner.Name;
    BeginUpdate;
    try
      IsRestoring := True;
      try
        case AStorageType of
          stIniFile:
            AStorage.RestoreFromIni(Self);
          stRegistry:
            AStorage.RestoreFromRegistry(Self);
          stStream:
            AStorage.RestoreFromStream(Self);
        end;
      finally
        IsRestoring := False;
      end;
    finally
      EndUpdate;
    end;
  finally
    AStorage.Free;
  end;
end;

procedure TdxCustomTileControl.StoreTo(AStorageType: TcxStorageType; const AStorageName: string;
  AStorageStream: TStream; AReCreate: Boolean; const ASaveName: string);
var
  AStorage: TcxStorage;
begin
  FStoringName := ASaveName;
  AStorage := TcxStorage.Create(AStorageName, AStorageStream);
  try
    AStorage.UseInterfaceOnly := True;
    if ASaveName = '' then
      AStorage.NamePrefix := Owner.Name;
    AStorage.ReCreate := AReCreate;
    case AStorageType of
      stIniFile:
        AStorage.StoreToIni(Self);
      stRegistry:
        AStorage.StoreToRegistry(Self);
      stStream:
        AStorage.StoreToStream(Self);
    end;
    AStorage.ReCreate := False;
  finally
    AStorage.Free;
  end;
end;

// cxStorage implementation

procedure TdxCustomTileControl.GetStoredChildren(AChildren: TStringList);
begin
  if StoredVersion > 0 then
  begin
    if Groups <> nil then
      AChildren.AddObject('', Groups);
    if Items <> nil then
      AChildren.AddObject('', Items);
  end
  else
  begin
    if Items <> nil then
      AChildren.AddObject('', Items);
    if Groups <> nil then
      AChildren.AddObject('', Groups);
  end
end;

function TdxCustomTileControl.GetStoredObjectName: string;
begin
  if FStoringName = '' then
    Result := Name
  else
    Result := FStoringName;
end;

function TdxCustomTileControl.GetStoredObjectProperties(AProperties: TStrings): Boolean;
begin
  AProperties.Add('Version');
  if Assigned(OnGetStoredProperties) then
    OnGetStoredProperties(Self, AProperties);
  Result := True;
end;

procedure TdxCustomTileControl.GetStoredPropertyValue(const AName: string; var AValue: Variant);
begin
  if AName = 'Version' then
  begin
    AValue := dxTileControlStoringVersion;
    FStoredVersion := AValue;
  end
  else
    FStoredVersion := 0;
  if Assigned(OnGetStoredPropertyValue) then
    OnGetStoredPropertyValue(Self, AName, AValue);
end;

procedure TdxCustomTileControl.SetStoredPropertyValue(const AName: string; const AValue: Variant);
begin
  if AName = 'Version' then
    FStoredVersion := AValue;
  if Assigned(OnSetStoredPropertyValue) then
    OnSetStoredPropertyValue(Self, AName, AValue);
end;

function TdxCustomTileControl.StoredCreateChild(const AObjectName, AClassName: string): TObject;
begin
  if (AClassName = GetGroupsClass.ClassName) or (AClassName = GetItemsClass.ClassName) then
  begin
    if AClassName = GetGroupsClass.ClassName then
      Result := CreateGroupsCollection
    else
      Result := CreateItemsCollection;
    DoInitStoredObject(Result);
  end
  else
    Result := nil;
end;

procedure TdxCustomTileControl.StoredDeleteChild(const AObjectName: string; AObject: TObject);
begin
  AObject.Free;
end;

// storing layout

procedure TdxCustomTileControl.RestoreFromIniFile(const AStorageName: string;
  AChildrenCreating: Boolean = False; AChildrenDeleting: Boolean = False;
  const ARestoreName: string = '');
begin
  RestoreFrom(stIniFile, AStorageName, nil, AChildrenCreating, AChildrenDeleting, ARestoreName);
end;

procedure TdxCustomTileControl.RestoreFromRegistry(const AStorageName: string;
  AChildrenCreating: Boolean = False; AChildrenDeleting: Boolean = False;
  const ARestoreName: string = '');
begin
  RestoreFrom(stRegistry, AStorageName, nil, AChildrenCreating, AChildrenDeleting, ARestoreName);
end;

procedure TdxCustomTileControl.RestoreFromStream(AStream: TStream;
  AChildrenCreating: Boolean = False; AChildrenDeleting: Boolean = False;
  const ARestoreName: string = '');
begin
  RestoreFrom(stStream, '', AStream, AChildrenCreating, AChildrenDeleting, ARestoreName);
end;

procedure TdxCustomTileControl.StoreToIniFile(AStorageName: string;
  AReCreate: Boolean = True; const ASaveName: string = '');
begin
  StoreTo(stIniFile, AStorageName, nil, AReCreate, ASaveName);
end;

procedure TdxCustomTileControl.StoreToRegistry(AStorageName: string;
  AReCreate: Boolean = True; const ASaveName: string = '');
begin
  StoreTo(stRegistry, AStorageName, nil, AReCreate, ASaveName);
end;

procedure TdxCustomTileControl.StoreToStream(AStream: TStream; const ASaveName: string = '');
begin
  StoreTo(stStream, '', AStream, True, ASaveName);
end;

{ TdxTileControlAssets }

constructor TdxTileControlAssets.Create;
begin
  inherited Create;
  FBackButton := TdxSkinImage.Create(nil);
  FBackButton.LoadFromResource(HInstance, 'dxTileControlBackButton', RT_RCDATA);
  FBackButton.ImageCount := 3;

  FCustomButton := TdxSkinImage.Create(nil);
  FCustomButton.LoadFromResource(HInstance, 'dxTileControlCustomButton', RT_RCDATA);
  FCustomButton.ImageCount := 3;
end;

destructor TdxTileControlAssets.Destroy;
begin
  FreeAndNil(FCustomButton);
  FreeAndNil(FBackButton);
  inherited Destroy;
end;

{ TdxTileControlCustomActionBar }

constructor TdxTileControlCustomActionBar.Create(ATileControl: TdxCustomTileControl);
begin
  inherited Create(nil);
  FTileControl := ATileControl;
  FHitTest := CreateHitTest;
  FController := CreateController;
  FViewInfo := CreateViewInfo;
end;

destructor TdxTileControlCustomActionBar.Destroy;
begin
  FreeAndNil(FController);
  FreeAndNil(FViewInfo);
  FreeAndNil(FHitTest);
  inherited Destroy;
end;

procedure TdxTileControlCustomActionBar.BoundsChanged;
begin
  inherited BoundsChanged;
  Recalculate;
end;

function TdxTileControlCustomActionBar.CreateController: TdxTileControlActionBarController;
begin
  Result := TdxTileControlActionBarController.Create(Self);
end;

function TdxTileControlCustomActionBar.CreateHitTest: TdxTileControlActionBarHitTest;
begin
  Result := TdxTileControlActionBarHitTest.Create(Self);
end;

procedure TdxTileControlCustomActionBar.DoPaint;
begin
  ViewInfo.Draw(Canvas);
end;

procedure TdxTileControlCustomActionBar.MouseDown(
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseDown(Button, Shift, X, Y);
  Controller.MouseDown(Button, Shift, X, Y);
end;

procedure TdxTileControlCustomActionBar.MouseLeave(AControl: TControl);
begin
  inherited MouseLeave(AControl);
  Controller.MouseLeave;
end;

procedure TdxTileControlCustomActionBar.MouseMove(Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseMove(Shift, X, Y);
  Controller.MouseMove(Shift, X, Y);
end;

procedure TdxTileControlCustomActionBar.MouseUp(
  Button: TMouseButton; Shift: TShiftState; X, Y: Integer);
begin
  inherited MouseUp(Button, Shift, X, Y);
  Controller.MouseUp(Button, Shift, X, Y);
end;

procedure TdxTileControlCustomActionBar.Recalculate;
begin
  ViewInfo.Bounds := ClientRect;
  ViewInfo.Calculate;
  Invalidate;
end;

{ TdxTileControlActionBarsAnimation }

constructor TdxTileControlActionBarsAnimation.Create(
  ATileControl: TdxCustomTileControl; AMode: TdxTileControlActionBarsAnimationMode);
begin
  FTileControl := ATileControl;
  FTileControl.RefreshActionBars;
  inherited Create(dxTileControlActionBarsAnimationTime, ateAccelerateDecelerate,
    Max(ActionBarBottom.ViewInfo.MeasureHeight, ActionBarTop.ViewInfo.MeasureHeight));
  FMode := AMode;
end;

function TdxTileControlActionBarsAnimation.CalculateActionBarBottomBounds: TRect;
var
  ADelta: Integer;
begin
  Result := TileControl.GetActionBarBottomBounds;
  ADelta := MulDiv(cxRectHeight(Result), Position, Length);
  if Mode = tcabamShow then
    ADelta := cxRectHeight(Result) - ADelta;
  Result := cxRectOffset(Result, 0, ADelta);
end;

function TdxTileControlActionBarsAnimation.CalculateActionBarTopBounds: TRect;
var
  ADelta: Integer;
begin
  Result := TileControl.GetActionBarTopBounds;
  ADelta := MulDiv(cxRectHeight(Result), Position, Length);
  if Mode = tcabamShow then
    Dec(ADelta, cxRectHeight(Result))
  else
    ADelta := -ADelta;
  Result := cxRectOffset(Result, 0, ADelta);
end;

procedure TdxTileControlActionBarsAnimation.DoAnimate;

  procedure DeferWindowPosition(AInfoHandle: HDWP; AWindow: TWinControl; const R: TRect);
  begin
    DeferWindowPos(AInfoHandle, AWindow.Handle, 0,
      R.Left, R.Top, cxRectWidth(R), cxRectHeight(R), SWP_NOZORDER)
  end;

  procedure UpdateVisibility(AValue: Boolean);
  begin
    ActionBarTop.Visible := AValue;
    ActionBarBottom.Visible := AValue;
  end;
  
var
  ADeferHandle: HDWP;
begin
  if Position <> FPrevPosition then
  begin
    ADeferHandle := BeginDeferWindowPos(2);
    try
      DeferWindowPosition(ADeferHandle, ActionBarTop, CalculateActionBarTopBounds);
      DeferWindowPosition(ADeferHandle, ActionBarBottom, CalculateActionBarBottomBounds);
    finally
      EndDeferWindowPos(ADeferHandle);
    end;

    if Finished then
      UpdateVisibility(Mode = tcabamShow)
    else
      UpdateVisibility(True);

    TileControl.ForceUpdate;
  end;
end;

function TdxTileControlActionBarsAnimation.GetActionBarBottom: TdxTileControlCustomActionBar;
begin
  Result := TileControl.ActionBarBottom;
end;

function TdxTileControlActionBarsAnimation.GetActionBarTop: TdxTileControlCustomActionBar;
begin
  Result := TileControl.ActionBarTop;
end;

function TdxTileControlActionBarsAnimation.IsCompatible(Animation: TdxAnimationTransition): Boolean;
begin
  Result := not (Animation is TdxTileControlActionBarsAnimation);
end;

{ TdxTileControlContentAnimation }

constructor TdxTileControlContentAnimation.Create(ATileControl: TdxCustomTileControl;
  ATime: Cardinal; const ALengthX, ALenghtY: Integer);
begin
  FTileControl := ATileControl;
  FLengthX := ALengthX;
  FLengthY := ALenghtY;
  inherited Create(ATime, ateAccelerateDecelerate, Max(Abs(LengthX), Abs(LengthY)));
end;

procedure TdxTileControlContentAnimation.DoAnimate;
var
  ADeltaX, ADeltaY: Integer;
  APositionX, APositionY: Integer;
begin
  APositionX := GetPositionX;
  APositionY := GetPositionY;
  ADeltaX := (APositionX - PrevPositionX) * Sign(LengthX);
  ADeltaY := (APositionY - PrevPositionY) * Sign(LengthY);
  DoMoveContent(ADeltaX, ADeltaY);
  FPrevPositionX := APositionX;
  FPrevPositionY := APositionY;
  TileControl.ForceUpdate();
end;

procedure TdxTileControlContentAnimation.DoMoveContent(const ADeltaX, ADeltaY: Integer);
var
  I: Integer;
begin
  for I := 0 to ViewInfo.Cells.Count - 1 do
    ViewInfo.Cells[I].Scroll(ADeltaX, ADeltaY);
end;

function TdxTileControlContentAnimation.GetPositionX: Integer;
begin
  Result := MulDiv(Abs(LengthX), Position, Length);
end;

function TdxTileControlContentAnimation.GetPositionY: Integer;
begin
  Result := MulDiv(Abs(LengthY), Position, Length);
end;

function TdxTileControlContentAnimation.GetViewInfo: TdxTileControlViewInfo;
begin
  Result := TileControl.ViewInfo;
end;

{ TdxTileControlRubberAnimation }

constructor TdxTileControlRubberAnimation.Create(ATileControl: TdxCustomTileControl;
  AHandScrollObject: TdxTileControlHandScroll);
begin
  FHandScrollObject := AHandScrollObject;
  inherited Create(ATileControl, dxTileControlRubberAnimationTime,
    HandScrollObject.FinishAnimationPosX - HandScrollObject.StartAnimationPosX,
    HandScrollObject.FinishAnimationPosY - HandScrollObject.StartAnimationPosY);
  Controller.FHasRubberAnimation := True;
end;

destructor TdxTileControlRubberAnimation.Destroy;
begin
  Controller.FHasRubberAnimation := False;
  TileControl.UpdateScrollBars;
  inherited Destroy;
end;

procedure TdxTileControlRubberAnimation.DoMoveContent(const ADeltaX, ADeltaY: Integer);
begin
  if (ADeltaX <> 0) or (ADeltaY <> 0) then
    TileControl.ViewInfo.Scroll(ADeltaX, ADeltaY);
end;

function TdxTileControlRubberAnimation.GetController: TdxTileControlController;
begin
  Result := TileControl.Controller;
end;

{ TdxTileControlActionBarController }

constructor TdxTileControlActionBarController.Create(AOwner: TdxTileControlCustomActionBar);
begin
  inherited Create;
  FOwner := AOwner;
end;

destructor TdxTileControlActionBarController.Destroy;
begin
  EndMouseTracking(Self);
  inherited Destroy;
end;

procedure TdxTileControlActionBarController.HideActionBars;
begin
  TileControl.HideActionBars;
end;

procedure TdxTileControlActionBarController.MouseDown(
  AButton: TMouseButton; AShift: TShiftState; X, Y: Integer);
begin
  HitTest.Calculate(X, Y);
  if AButton = mbLeft then
    PressedCell := HitTest.HitObject;
end;

procedure TdxTileControlActionBarController.MouseLeave;
begin
  MouseMove([], -1, -1);
  EndMouseTracking(Self);
end;

procedure TdxTileControlActionBarController.MouseMove(AShift: TShiftState; X, Y: Integer);
begin
  HitTest.Calculate(X, Y);
  HotCell := HitTest.HitObject;
  BeginMouseTracking(Owner, Owner.Bounds, Self);
end;

procedure TdxTileControlActionBarController.MouseUp(
  AButton: TMouseButton; AShift: TShiftState; X, Y: Integer);
begin
  HitTest.Calculate(X, Y);
  case AButton of
    mbLeft:
      ProcessMouseLeftButtonClick;
    mbRight:
      begin
        UncheckAllItems;
        HideActionBars;
      end;
  end;
  PressedCell := nil;
end;

function TdxTileControlActionBarController.PtInCaller(const P: TPoint): Boolean;
begin
  Result := PtInRect(Owner.Bounds, P);
end;

procedure TdxTileControlActionBarController.ProcessMouseLeftButtonClick;
var
  AItem: TdxTileControlActionBarItem;
begin
  if HitTest.HitObject = PressedCell then
  begin
    if HitTest.HitAtBackButton then
    begin
      UncheckAllItems;
      HideActionBars;
      if TileControl.ActiveDetail <> nil then
        TileControl.ActiveDetail.TileItem.DeactivateDetail;
    end;
    if HitTest.HitAtActionButton then
    begin
      AItem := TdxTileControlActionBarItemViewInfo(HitTest.HitObject).Item;
      HideActionBars;
      AItem.Click;
      UncheckAllItems;
    end;
  end;
end;

procedure TdxTileControlActionBarController.RefreshStates;
begin
  Owner.ViewInfo.RefreshState;
end;

procedure TdxTileControlActionBarController.SetHotCell(AValue: TObject);
begin
  if FHotCell <> AValue then
  begin
    FHotCell := AValue;
    RefreshStates;
  end;
end;

procedure TdxTileControlActionBarController.SetPressedCell(AValue: TObject);
begin
  if FPressedCell <> AValue then
  begin
    FPressedCell := AValue;
    RefreshStates;
  end;
end;

procedure TdxTileControlActionBarController.UncheckAllItems;
begin
  TileControl.Controller.UncheckAllItems;
end;

function TdxTileControlActionBarController.GetHitTest: TdxTileControlActionBarHitTest;
begin
  Result := Owner.HitTest;
end;

function TdxTileControlActionBarController.GetTileControl: TdxCustomTileControl;
begin
  Result := Owner.TileControl;
end;

{ TdxTileControlCustomActionBarViewInfo }

constructor TdxTileControlCustomActionBarViewInfo.Create(AOwner: TdxTileControlCustomActionBar);
begin
  inherited Create;
  FOwner := AOwner;
  FCells := TdxTileControlCells.Create;
end;

destructor TdxTileControlCustomActionBarViewInfo.Destroy;
begin
  FreeAndNil(FCells);
  inherited Destroy;
end;

procedure TdxTileControlCustomActionBarViewInfo.Calculate;
begin
  Clear;
  CalculateItems(Bounds);
end;

procedure TdxTileControlCustomActionBarViewInfo.CalculateItems(ABounds: TRect);
var
  AItem: TdxTileControlActionBarItem;
  AItemViewInfo: TdxTileControlActionBarCustomItemViewInfo;
  AItemWidth: Integer;
  I: Integer;
begin
  ABounds := cxRectInflate(ABounds, -ActionBars.IndentHorz, -ActionBars.IndentVert);

  for I := 0 to Items.Count - 1 do
  begin
    AItem := Items[I];
    if GetCanDisplayItem(AItem) and (AItem.Align = abiaLeft) then
    begin
      AItemViewInfo := CreateItemViewInfo(AItem);
      AItemWidth := AItemViewInfo.MeasureWidth;
      if AItemWidth > cxRectWidth(ABounds) then
      begin
        AItemViewInfo.Free;
        Break;
      end;
      Cells.Add(AItemViewInfo);
      AItemViewInfo.SetBounds(cxRectSetWidth(ABounds, AItemWidth), Bounds);
      ABounds.Left := AItemViewInfo.Bounds.Right + ActionBars.ItemIndent;
    end;
  end;

  for I := 0 to Items.Count - 1 do
  begin
    AItem := Items[I];
    if GetCanDisplayItem(AItem) and (AItem.Align = abiaRight) then
    begin
      AItemViewInfo := CreateItemViewInfo(AItem);
      AItemWidth := AItemViewInfo.MeasureWidth;
      if AItemWidth > cxRectWidth(ABounds) then
      begin
        AItemViewInfo.Free;
        Break;
      end;
      Cells.Add(AItemViewInfo);
      AItemViewInfo.SetBounds(cxRectSetRight(ABounds, ABounds.Right, AItemWidth), Bounds);
      ABounds.Right := AItemViewInfo.Bounds.Left - ActionBars.ItemIndent;
    end;
  end;
end;

procedure TdxTileControlCustomActionBarViewInfo.Clear;
begin
  Cells.Clear;
end;

function TdxTileControlCustomActionBarViewInfo.CreateItemViewInfo(
  AItem: TdxTileControlActionBarItem): TdxTileControlActionBarCustomItemViewInfo;
begin
  Result := TdxTileControlActionBarItemViewInfo.Create(Self, AItem);
end;

procedure TdxTileControlCustomActionBarViewInfo.Draw(ACanvas: TcxCanvas);
begin
  DrawBackground(ACanvas);
  Cells.Draw(ACanvas);
end;

procedure TdxTileControlCustomActionBarViewInfo.DrawBackground(ACanvas: TcxCanvas);
begin
  ACanvas.FillRect(Bounds, cxGetActualColor(
    ActionBars.Color, Painter.ActionBarDefaultBackgroundColor));
end;

function TdxTileControlCustomActionBarViewInfo.MeasureHeight: Integer;
var
  I: Integer;
begin
  Result := 0;
  for I := 0 to Cells.Count - 1 do
    Result := Max(Result, TdxTileControlCustomButtonViewInfo(Cells[I]).MeasureHeight);
  if Result > 0 then
    Inc(Result, 2 * ActionBars.IndentVert);
end;

procedure TdxTileControlCustomActionBarViewInfo.RefreshState;
begin
  inherited RefreshState;
  Cells.RefreshState;
end;

function TdxTileControlCustomActionBarViewInfo.GetActionBars: TdxTileControlActionBars;
begin
  Result := Owner.TileControl.ActionBars;
end;

function TdxTileControlCustomActionBarViewInfo.GetCanDisplayItem(AItem: TdxTileControlActionBarItem): Boolean;
begin
  Result := AItem.Visible;
end;

function TdxTileControlCustomActionBarViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := PtInRect(Bounds, AHitTest.HitPoint);
  if Result then
  begin
    AHitTest.BitState[tchtActionBar] := True;
    AHitTest.HitObject := Self;
    Cells.CalculateHitTest(AHitTest);
  end;
end;

function TdxTileControlCustomActionBarViewInfo.GetItems: TdxTileControlActionBarItems;
begin
  Result := ActionBars.Items;
end;

function TdxTileControlCustomActionBarViewInfo.GetPainter: TdxTileControlPainter;
begin
  Result := Owner.TileControl.Painter;
end;

{ TdxTileControlActionBarItem }

constructor TdxTileControlActionBarItem.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FImage := TdxSkinImage.Create(nil);
  FImage.OnChange := GlyphChanged;
  FPosition := abipBottomBar;
  FVisible := True;
end;

destructor TdxTileControlActionBarItem.Destroy;
begin
  FreeAndNil(FImage);
  inherited Destroy;
end;

procedure TdxTileControlActionBarItem.Assign(Source: TPersistent);
begin
  if Source is TdxTileControlActionBarItem then
  begin
    Align := TdxTileControlActionBarItem(Source).Align;
    Caption := TdxTileControlActionBarItem(Source).Caption;
    Glyph := TdxTileControlActionBarItem(Source).Glyph;
    GlyphFrameCount := TdxTileControlActionBarItem(Source).GlyphFrameCount;
    Position := TdxTileControlActionBarItem(Source).Position;
    Visible := TdxTileControlActionBarItem(Source).Visible;
  end
  else
    inherited Assign(Source);
end;

procedure TdxTileControlActionBarItem.Click;
begin
  if Assigned(OnClick) then OnClick(Self);
end;

procedure TdxTileControlActionBarItem.GlyphChanged(Sender: TObject);
begin
  Changed(True);
end;

function TdxTileControlActionBarItem.GetCollectionFromParent(AParent: TComponent): TcxComponentCollection;
begin
  Result := TdxCustomTileControl(AParent).ActionBars.Items;
end;

function TdxTileControlActionBarItem.GetGlyph: TdxSmartImage;
begin
  Result := Image.Texture;
end;

function TdxTileControlActionBarItem.GetGlyphFrameCount: Integer;
begin
  Result := Image.ImageCount;
end;

procedure TdxTileControlActionBarItem.SetAlign(AValue: TdxTileControlActionBarItemAlignment);
begin
  if AValue <> Align then
  begin
    FAlign := AValue;
    Changed(True);
  end;
end;

procedure TdxTileControlActionBarItem.SetCaption(const AValue: string);
begin
  if AValue <> Caption then
  begin
    FCaption := AValue;
    Changed(True);
  end;
end;

procedure TdxTileControlActionBarItem.SetGlyph(AValue: TdxSmartImage);
begin
  Image.Texture.Assign(AValue);
  Changed(True);
end;

procedure TdxTileControlActionBarItem.SetGlyphFrameCount(AValue: Integer);
begin
  Image.ImageCount := Min(AValue, 3);
end;

procedure TdxTileControlActionBarItem.SetPosition(AValue: TdxTileControlActionBarItemPosition);
begin
  if AValue <> FPosition then
  begin
    FPosition := AValue;
    Changed(True);
  end;
end;

procedure TdxTileControlActionBarItem.SetVisible(AValue: Boolean);
begin
  if FVisible <> AValue then
  begin
    FVisible := AValue;
    Changed(True);
  end;
end;

{ TdxTileControlActionBarItems }

function TdxTileControlActionBarItems.Add: TdxTileControlActionBarItem;
begin
  Result := TdxTileControlActionBarItem(inherited Add);
end;

function TdxTileControlActionBarItems.GetItem(AIndex: Integer): TdxTileControlActionBarItem;
begin
  Result := TdxTileControlActionBarItem(inherited Items[AIndex]);
end;

function TdxTileControlActionBarItems.GetItemPrefixName: string;
begin
  Result := 'TdxTileControl';
end;

procedure TdxTileControlActionBarItems.SetItem(AIndex: Integer; AValue: TdxTileControlActionBarItem);
begin
  inherited Items[AIndex] := AValue;
end;

{ TdxTileControlActionBarCustomItemViewInfo }

constructor TdxTileControlActionBarCustomItemViewInfo.Create(
  AOwner: TdxTileControlCustomActionBarViewInfo);
begin
  inherited Create;
  FOwner := AOwner;
end;

procedure TdxTileControlActionBarCustomItemViewInfo.DoCalculate;
begin
  inherited DoCalculate;
 FGlyphBounds := cxRectSetHeight(cxRectCenterHorizontally(Bounds, Texture.Size.cx), Texture.Size.cy);
end;

procedure TdxTileControlActionBarCustomItemViewInfo.Draw(ACanvas: TcxCanvas);
var
  R: TRect;
begin
//  ACanvas.StretchDraw(FGlyphBounds, Texture.Texture);
  Painter.DrawColoredGlyph(ACanvas, FGlyphBounds, State, Texture, TextColor);
  if Text <> '' then
  begin
    R := TextBounds;
    cxTextOut(ACanvas.Handle, Text, R,
      CXTO_CENTER_HORIZONTALLY or CXTO_CENTER_VERTICALLY, Font, 0, 0, 0, TextColor);
  end;
end;

procedure TdxTileControlActionBarCustomItemViewInfo.Invalidate;
begin
  if Visible then
    Owner.Owner.InvalidateRect(Bounds, False);
end;

function TdxTileControlActionBarCustomItemViewInfo.MeasureHeight: Integer;
begin
  Result := Texture.Size.cy;
  if Text <> '' then
    Inc(Result, cxTextHeight(Font, Text) + 2 * cxTextOffset);
end;

function TdxTileControlActionBarCustomItemViewInfo.MeasureWidth: Integer;
begin
  Result := Texture.Size.cx;
  if Text <> '' then
    Result := Max(Result, cxTextWidth(Font, Text));
end;

procedure TdxTileControlActionBarCustomItemViewInfo.RefreshState;
begin
  if (Controller.PressedCell = Self) and (Controller.HotCell = Self) then
    State := cxbsPressed
  else
    if (Controller.HotCell = Self) and (Controller.PressedCell = nil) then
      State := cxbsHot
    else
      State := cxbsNormal;
end;

function TdxTileControlActionBarCustomItemViewInfo.GetController: TdxTileControlActionBarController;
begin
  Result := Owner.Owner.Controller;
end;

function TdxTileControlActionBarCustomItemViewInfo.GetFont: TFont;
begin
  Result := Owner.ActionBars.Font;
end;

function TdxTileControlActionBarCustomItemViewInfo.GetPainter: TdxTileControlPainter;
begin
  Result := Owner.Owner.TileControl.Painter;
end;

function TdxTileControlActionBarCustomItemViewInfo.GetText: string;
begin
  Result := '';
end;

function TdxTileControlActionBarCustomItemViewInfo.GetTextBounds: TRect;
begin
  Result := Bounds;
  Result.Top := FGlyphBounds.Bottom;
end;

function TdxTileControlActionBarCustomItemViewInfo.GetTextColor: TColor;
begin
  Result := cxGetActualColor(Font.Color, Painter.ActionBarDefaultTextColor);
end;

{ TdxTileControlActionBarItemViewInfo }

constructor TdxTileControlActionBarItemViewInfo.Create(
  AOwner: TdxTileControlCustomActionBarViewInfo; AItem: TdxTileControlActionBarItem);
begin
  inherited Create(AOwner);
  FItem := AItem;
end;

function TdxTileControlActionBarItemViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
    AHitTest.BitState[tchtActionButton] := True;
end;

function TdxTileControlActionBarItemViewInfo.GetText: string;
begin
  Result := Item.Caption;
end;

function TdxTileControlActionBarItemViewInfo.GetTexture: TdxSkinImage;
begin
  if Item.Image.Empty then
    Result := Owner.Owner.TileControl.Assets.CustomButton
  else
    Result := Item.Image;
end;

{ TdxTileControlTopActionBarBackButtonViewInfo }

function TdxTileControlTopActionBarBackButtonViewInfo.GetHitTest(AHitTest: TdxTileControlHitTest): Boolean;
begin
  Result := inherited GetHitTest(AHitTest);
  if Result then
    AHitTest.BitState[tchtBackButton] := True;
end;

function TdxTileControlTopActionBarBackButtonViewInfo.GetTexture: TdxSkinImage;
begin
  Result := Owner.Owner.TileControl.Assets.BackButton;
end;

{ TdxTileControlBottomActionBar }

function TdxTileControlBottomActionBar.CreateViewInfo: TdxTileControlCustomActionBarViewInfo;
begin
  Result := TdxTileControlBottomActionBarViewInfo.Create(Self);
end;

{ TdxTileControlBottomActionBarViewInfo }

function TdxTileControlBottomActionBarViewInfo.GetCanDisplayItem(
  AItem: TdxTileControlActionBarItem): Boolean;
begin
  Result := inherited GetCanDisplayItem(AItem) and (AItem.Position = abipBottomBar);
end;

{ TdxTileControlTopActionBar }

function TdxTileControlTopActionBar.CreateViewInfo: TdxTileControlCustomActionBarViewInfo;
begin
  Result := TdxTileControlTopActionBarViewInfo.Create(Self);
end;

{ TdxTileControlTopActionBarViewInfo }

procedure TdxTileControlTopActionBarViewInfo.CalculateItems(ABounds: TRect);
var
  ABackButtonBounds: TRect;
  ABackButtonViewInfo: TdxTileControlActionBarCustomItemViewInfo;
begin
  if Owner.TileControl.ActiveDetail <> nil then
  begin
    ABackButtonViewInfo := CreateBackButtonViewInfo;
    ABackButtonBounds := cxRectInflate(ABounds, -ActionBars.IndentHorz, -ActionBars.IndentVert);
    ABackButtonBounds := cxRectSetWidth(ABackButtonBounds, ABackButtonViewInfo.MeasureWidth);
    ABackButtonViewInfo.SetBounds(ABackButtonBounds, ABounds);
    Cells.Add(ABackButtonViewInfo);
    ABounds.Left := ABackButtonBounds.Right;
  end;
  inherited CalculateItems(ABounds);
end;

function TdxTileControlTopActionBarViewInfo.CreateBackButtonViewInfo: TdxTileControlActionBarCustomItemViewInfo;
begin
  Result := TdxTileControlTopActionBarBackButtonViewInfo.Create(Self);
end;

function TdxTileControlTopActionBarViewInfo.GetCanDisplayItem(
  AItem: TdxTileControlActionBarItem): Boolean;
begin
  Result := inherited GetCanDisplayItem(AItem) and (AItem.Position = abipTopBar);
end;
                                                                            
{ TdxTileControlActionBarHitTest }

constructor TdxTileControlActionBarHitTest.Create(AOwner: TdxTileControlCustomActionBar);
begin
  inherited Create(AOwner.TileControl);
  FOwner := AOwner;
end;

function TdxTileControlActionBarHitTest.GetActiveViewInfo: TdxTileControlCustomViewInfo;
begin
  Result := Owner.ViewInfo;
end;

initialization

finalization
  FreeAndNil(DetailsInfo);

end.

