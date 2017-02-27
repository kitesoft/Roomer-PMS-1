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

unit dxSkinsLookAndFeelPainter;

{$I cxVer.inc}

interface

uses
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  Types, Windows, Classes, Graphics, SysUtils, ImgList,
  cxLookAndFeels, cxLookAndFeelPainters,
  dxCore, cxGraphics, cxGeometry, cxClasses, dxGdiPlusApi,
  dxSkinsCore, dxSkinInfo, dxSkinsStrs;

type
  { TdxSkinLookAndFeelPainterInfo }

  TdxSkinLookAndFeelPainterInfo = class(TdxSkinInfo);
  TdxSkinLookAndFeelPainterInfoClass = class of TdxSkinLookAndFeelPainterInfo;

  { TcxSkinLookAndFeelPainter }

  TdxSkinLookAndFeelPainter = class(TcxOffice11LookAndFeelPainter)
  private
    FSkinInfo: TdxSkinLookAndFeelPainterInfo;
    FSkinResInstance: THandle;
    FSkinResName: string;
    function GetSkinElementBordersWidth(AElement: TdxSkinElement): TRect;
    function GetSkinDetails: TdxSkinDetails;
    function GetSkinInfo: TdxSkinLookAndFeelPainterInfo;
  protected
    function CreateLookAndFeelPainterDetails: TObject; override;
    function GetLookAndFeelPainterDetails: TObject; override;

    procedure DrawContent(ACanvas: TcxCanvas; const ABounds, ATextAreaBounds: TRect; AState: Integer;
      AAlignmentHorz: TAlignment; AAlignmentVert: TcxAlignmentVert; AMultiLine, AShowEndEllipsis: Boolean;
      const AText: string; AFont: TFont; ATextColor, ABkColor: TColor;
      AOnDrawBackground: TcxDrawBackgroundEvent = nil; AIsFooter: Boolean = False); override;
    procedure DrawGroupCaption(ACanvas: TcxCanvas; const ACaptionRect, ATextRect: TRect;
      AElement: TdxSkinElement; ATextPadding: TdxSkinIntegerProperty; AState: TdxSkinElementState); virtual;
    procedure DrawSchedulerNavigationButtonContent(ACanvas: TcxCanvas;
      const ARect: TRect; const AArrowRect: TRect; AIsNextButton: Boolean;
      AState: TcxButtonState); override;
    function GalleryStateToButtonState(const AState: TdxGalleryItemViewState): TcxButtonState;
    function GetSkinInfoClass: TdxSkinLookAndFeelPainterInfoClass; virtual;
    function IsColorPropertyAssigned(AColor: TdxSkinColor): Boolean;
  public
    constructor Create(const ASkinResName: string; ASkinResInstance: THandle); virtual;
    destructor Destroy; override;
    function GetPainterData(var AData): Boolean; override;
    function GetPainterDetails(var ADetails): Boolean; override;
    function LookAndFeelName: string; override;
    function LookAndFeelStyle: TcxLookAndFeelStyle; override;
    // colors
    function DefaultChartHistogramPlotColor: TColor; override;
    function DefaultContentColor: TColor; override;
    function DefaultContentEvenColor: TColor; override;
    function DefaultContentOddColor: TColor; override;
    function DefaultContentTextColor: TColor; override;
    function DefaultEditorBackgroundColorEx(AKind: TcxEditStateColorKind): TColor; override;
    function DefaultEditorTextColorEx(AKind: TcxEditStateColorKind): TColor; override;
    function DefaultFilterBoxTextColor: TColor; override;
    function DefaultFixedSeparatorColor: TColor; override;
    function DefaultFooterColor: TColor; override;
    function DefaultFooterTextColor: TColor; override;
    function DefaultGridDetailsSiteColor: TColor; override;
    function DefaultGridLineColor: TColor; override;
    function DefaultGroupByBoxTextColor: TColor; override;
    function DefaultGroupColor: TColor; override;
    function DefaultGroupTextColor: TColor; override;
    function DefaultHeaderBackgroundColor: TColor; override;
    function DefaultHeaderBackgroundTextColor: TColor; override;
    function DefaultHeaderColor: TColor; override;
    function DefaultHeaderTextColor: TColor; override;
    function DefaultHyperlinkTextColor: TColor; override;
    function DefaultInactiveColor: TColor; override;
    function DefaultInactiveTextColor: TColor; override;
    function DefaultPreviewTextColor: TColor; override;
    function DefaultRecordSeparatorColor: TColor; override;
    function DefaultSelectionColor: TColor; override;
    function DefaultSelectionTextColor: TColor; override;
    function DefaultSeparatorColor: TColor; override;
    function DefaultSizeGripAreaColor: TColor; override;
    function DefaultTimeGridMajorScaleTextColor: TColor; override;
    function DefaultTimeGridMinorScaleTextColor: TColor; override;

    function DefaultGridOptionsTreeViewCategoryColor(ASelected: Boolean): TColor; override;
    function DefaultGridOptionsTreeViewCategoryTextColor(ASelected: Boolean): TColor; override;

    function DefaultSchedulerBackgroundColor: TColor; override;
    function DefaultSchedulerBorderColor: TColor; override;
    function DefaultSchedulerContentColor(AResourceIndex: Integer): TColor; override;
    function DefaultSchedulerControlColor: TColor; override;
    function DefaultSchedulerEventColor(AIsAllDayEvent: Boolean): TColor; override;
    function DefaultSchedulerNavigatorColor: TColor; override;
    function DefaultSchedulerTimeRulerColor: TColor; override;
    function DefaultSchedulerTimeRulerTextColor: TColor; override;
    function DefaultSchedulerViewContentColor: TColor; override;
    function DefaultSchedulerViewSelectedTextColor: TColor; override;
    function DefaultSchedulerViewTextColor: TColor; override;
    function DefaultSchedulerYearViewUnusedContentColor(AIsWorkTime: Boolean): TColor; override;

    function DefaultTreeListGridLineColor: TColor; override;
    function DefaultTreeListTreeLineColor: TColor; override;

    function DefaultLayoutViewCaptionTextColor(ACaptionPosition: TcxGroupBoxCaptionPosition; AState: TcxButtonState): TColor; override;
    function DefaultLayoutViewContentTextColor(AState: TcxButtonState): TColor; override;

    function DefaultDateNavigatorHeaderColor: TColor; override;
    function DefaultDateNavigatorHeaderTextColor(AIsHighlight: Boolean): TColor; override;
    function DefaultDateNavigatorHolydayTextColor: TColor; override;
    function DefaultDateNavigatorInactiveTextColor: TColor; override;
    function DefaultDateNavigatorSelectionColor: TColor; override;
    function DefaultDateNavigatorSelectionTextColor: TColor; override;
    function DefaultDateNavigatorSeparator1Color: TColor; override;
    function DefaultDateNavigatorSeparator2Color: TColor; override;
    function DefaultDateNavigatorTextColor: TColor; override;
    function DefaultDateNavigatorTodayFrameColor: TColor; override;
    function DefaultDateNavigatorTodayTextColor: TColor; override;

    function DefaultVGridBandLineColor: TColor; override;
    function DefaultVGridCategoryColor: TColor; override;
    function DefaultVGridCategoryTextColor: TColor; override;
    function DefaultVGridHeaderColor: TColor; override;
    function DefaultVGridHeaderTextColor: TColor; override;
    function DefaultVGridLineColor: TColor; override;
    // borders
    function SeparatorSize: Integer; override;
    procedure DrawBorder(ACanvas: TcxCanvas; R: TRect); override;
    procedure DrawContainerBorder(ACanvas: TcxCanvas; const R: TRect; AStyle: TcxContainerBorderStyle;
      AWidth: Integer; AColor: TColor; ABorders: TcxBorders); override;
    procedure DoDrawSeparator(ACanvas: TcxCanvas; R: TRect; AIsVertical: Boolean); override;
    // buttons
    function ButtonBorderSize(AState: TcxButtonState = cxbsNormal): Integer; override;
    function ButtonDescriptionTextColor(AState: TcxButtonState; ADefaultColor: TColor = clDefault): TColor; override;
    function ButtonFocusRect(ACanvas: TcxCanvas; R: TRect): TRect; override;
    function ButtonSymbolColor(AState: TcxButtonState; ADefaultColor: TColor = clDefault): TColor; override;
    function ButtonTextOffset: Integer; override;
    function ButtonTextShift: Integer; override;
    procedure DrawButton(ACanvas: TcxCanvas; R: TRect; const ACaption: string;
      AState: TcxButtonState; ADrawBorder: Boolean = True;
      AColor: TColor = clDefault; ATextColor: TColor = clDefault;
      AWordWrap: Boolean = False; AIsToolButton: Boolean = False); override;
    procedure DrawExpandButton(ACanvas: TcxCanvas; const R: TRect;
      AExpanded: Boolean; AColor: TColor = clDefault); override;
    procedure DrawExpandButtonEx(ACanvas: TcxCanvas; const R: TRect;
      AState: TcxButtonState; AExpanded: Boolean; ARotationAngle: TcxRotationAngle = ra0); override;
    function DrawExpandButtonFirst: Boolean; override;
    procedure DrawGroupExpandButton(ACanvas: TcxCanvas; const R: TRect;
      AExpanded: Boolean; AState: TcxButtonState); override;
    procedure DrawSmallExpandButton(ACanvas: TcxCanvas; R: TRect; AExpanded: Boolean;
      ABorderColor: TColor; AColor: TColor = clDefault); override;
    function ExpandButtonSize: Integer; override;
    function GroupExpandButtonSize: Integer; override;
    function SmallExpandButtonSize: Integer; override;
    function IsButtonHotTrack: Boolean; override;
    function IsPointOverGroupExpandButton(const R: TRect; const P: TPoint): Boolean; override;
    // scroll bars
    function ScrollBarMinimalThumbSize(AVertical: Boolean): Integer; override;
    procedure DrawScrollBarBackground(ACanvas: TcxCanvas; const R: TRect;
      AHorizontal: Boolean); override;
    procedure DrawScrollBarPart(ACanvas: TcxCanvas; AHorizontal: Boolean;
      R: TRect; APart: TcxScrollBarPart; AState: TcxButtonState); override;
    // label line
    procedure DrawLabelLine(ACanvas: TcxCanvas; const R: TRect;
      AOuterColor, AInnerColor: TColor; AIsVertical: Boolean); override;
    function LabelLineHeight: Integer; override;
    // size grip
    function SizeGripSize: TSize; override;
    procedure DoDrawSizeGrip(ACanvas: TcxCanvas; const ARect: TRect); override;
    // Slider
    function SliderButtonSize(ADirection: TcxArrowDirection): TSize; override;
    procedure DrawSliderButton(ACanvas: TcxCanvas; const ARect: TRect;
      ADirection: TcxArrowDirection; AState: TcxButtonState); override;
    // SmallCloseButton
    function SmallCloseButtonSize: TSize; override;
    procedure DrawSmallButton(ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState); override;
    procedure DrawSmallCloseButton(ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState); override;
    // RadioGroup
    procedure DrawRadioButton(ACanvas: TcxCanvas; X, Y: Integer;
      AButtonState: TcxButtonState; AChecked, AFocused: Boolean;
      ABrushColor: TColor;  AIsDesigning: Boolean = False); override;
    function RadioButtonSize: TSize; override;
    // Checkbox
    function CheckButtonSize: TSize; override;
    procedure DrawCheckButton(ACanvas: TcxCanvas; R: TRect;
      AState: TcxButtonState; ACheckState: TcxCheckBoxState); override;
    // Editors
    procedure DrawEditorButton(ACanvas: TcxCanvas; const ARect: TRect;
      AButtonKind: TcxEditBtnKind; AState: TcxButtonState; APosition: TcxEditBtnPosition = cxbpRight); override;
    procedure DrawEditorButtonGlyph(ACanvas: TcxCanvas; const ARect: TRect;
      AButtonKind: TcxEditBtnKind; AState: TcxButtonState; APosition: TcxEditBtnPosition = cxbpRight); override;
    procedure EditButtonAdjustRect(var R: TRect; APosition: TcxEditBtnPosition = cxbpRight); virtual;
    function EditButtonSize: TSize; override;
    function EditButtonTextColor: TColor; override;
    function EditButtonTextOffset: Integer; override;
    function GetContainerBorderColor(AIsHighlightBorder: Boolean): TColor; override;
    function GetContainerBorderWidth(ABorderStyle: TcxContainerBorderStyle): Integer; override;
    // Image
    function GetZoomInButtonSize: TSize; override;
    function GetZoomOutButtonSize: TSize; override;
    procedure DrawZoomInButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    procedure DrawZoomOutButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    // Clock
    function ClockSize: TSize; override;
    procedure DrawClock(ACanvas: TcxCanvas; const ARect: TRect;
      ADateTime: TDateTime; ABackgroundColor: TColor); override;
    // Navigator
    procedure DrawNavigatorBorder(ACanvas: TcxCanvas; R: TRect; ASelected: Boolean); override;
    procedure DrawNavigatorButton(ACanvas: TcxCanvas; R: TRect;
      AState: TcxButtonState; ABackgroundColor: TColor); override;
    procedure DrawNavigatorButtonGlyph(ACanvas: TcxCanvas; AImageList: TCustomImageList;
      AImageIndex: TcxImageIndex; const AGlyphRect: TRect;
      AEnabled: Boolean; AUserGlyphs: Boolean); override;
    function NavigatorBorderOverlap: Boolean; override;
    function NavigatorButtonGlyphPadding: TRect; override;
    function NavigatorButtonGlyphSize: TSize; override;
    function NavigatorButtonPressedGlyphOffset: TPoint; override;
    // ProgressBar
    procedure DrawProgressBarBorder(ACanvas: TcxCanvas; ARect: TRect; AVertical: Boolean); override;
    procedure DrawProgressBarChunk(ACanvas: TcxCanvas; ARect: TRect; AVertical: Boolean); override;
    function ProgressBarBorderSize(AVertical: Boolean): TRect; override;
    function ProgressBarTextColorEx(AIsFilledArea: Boolean): TColor; override;
    // GroupBox
    procedure DrawGroupBoxBackground(ACanvas: TcxCanvas; ABounds: TRect;
      ARect: TRect); override;
    procedure DrawGroupBoxCaption(ACanvas: TcxCanvas; const ACaptionRect, ATextRect: TRect;
      ACaptionPosition: TcxGroupBoxCaptionPosition); override;
    procedure DrawGroupBoxContent(ACanvas: TcxCanvas; ABorderRect: TRect;
      ACaptionPosition: TcxGroupBoxCaptionPosition; ABorders: TcxBorders = cxBordersAll); override;
    procedure DrawGroupBoxExpandButton(ACanvas: TcxCanvas;
      const R: TRect; AState: TcxButtonState; AExpanded: Boolean; ARotationAngle: TcxRotationAngle = ra0); override;
    function GroupBoxBorderSize(ACaption: Boolean;
      ACaptionPosition: TcxGroupBoxCaptionPosition): TRect; override;
    procedure DrawGroupBoxFrame(ACanvas: TcxCanvas; R: TRect; AEnabled: Boolean;
      ACaptionPosition: TcxGroupBoxCaptionPosition; ABorders: TcxBorders = cxBordersAll); override;
    function GroupBoxCaptionTailSize(ACaptionPosition: TcxGroupBoxCaptionPosition): Integer; override;
    function GroupBoxTextColor(AEnabled: Boolean; ACaptionPosition: TcxGroupBoxCaptionPosition): TColor; override;
    function IsGroupBoxCaptionTextDrawnOverBorder(ACaptionPosition: TcxGroupBoxCaptionPosition): Boolean; override;
    function IsGroupBoxTransparent(AIsCaption: Boolean; ACaptionPosition: TcxGroupBoxCaptionPosition): Boolean; override;
    function PanelTextColor: TColor; override;

    // Header
    procedure DrawHeader(ACanvas: TcxCanvas; const ABounds, ATextAreaBounds: TRect;
      ANeighbors: TcxNeighbors; ABorders: TcxBorders; AState: TcxButtonState;
      AAlignmentHorz: TAlignment; AAlignmentVert: TcxAlignmentVert; AMultiLine, AShowEndEllipsis: Boolean;
      const AText: string; AFont: TFont; ATextColor, ABkColor: TColor;
      AOnDrawBackground: TcxDrawBackgroundEvent = nil; AIsLast: Boolean = False;
      AIsGroup: Boolean = False); override;
    procedure DrawHeaderEx(ACanvas: TcxCanvas; const ABounds, ATextAreaBounds: TRect;
      ANeighbors: TcxNeighbors; ABorders: TcxBorders; AState: TcxButtonState;
      AAlignmentHorz: TAlignment; AAlignmentVert: TcxAlignmentVert; AMultiLine, AShowEndEllipsis: Boolean;
      const AText: string; AFont: TFont; ATextColor, ABkColor: TColor;
      AOnDrawBackground: TcxDrawBackgroundEvent = nil); override;
    procedure DrawHeaderControlSection(ACanvas: TcxCanvas; const ABounds, ATextAreaBounds: TRect; ANeighbors: TcxNeighbors;
      ABorders: TcxBorders; AState: TcxButtonState; AAlignmentHorz: TAlignment; AAlignmentVert: TcxAlignmentVert;
      AMultiLine, AShowEndEllipsis: Boolean; const AText: string; AFont: TFont; ATextColor, ABkColor: TColor); override;
    procedure DrawHeaderSeparator(ACanvas: TcxCanvas; const ABounds: TRect;
      AIndentSize: Integer; AColor: TColor; AViewParams: TcxViewParams); override;
    procedure DrawHeaderPressed(ACanvas: TcxCanvas; const ABounds: TRect); override;
    procedure DrawSortingMark(ACanvas: TcxCanvas; const R: TRect; AAscendingSorting: Boolean); override;
    procedure DrawSummarySortingMark(ACanvas: TcxCanvas; const R: TRect; AAscendingSorting: Boolean); override;
    function HeaderBorders(ANeighbors: TcxNeighbors): TcxBorders; override;
    function HeaderDrawCellsFirst: Boolean; override;
    function SummarySortingMarkSize: TPoint; override;
    // Grid
    procedure DrawGroupByBox(ACanvas: TcxCanvas; const ARect: TRect;
      ATransparent: Boolean; ABackgroundColor: TColor; const ABackgroundBitmap: TBitmap); override;
    function GridBordersOverlapSize: Integer; override;
    function GridDrawHeaderCellsFirst: Boolean; override;
    function GridGroupRowStyleOffice11ContentColor(AHasData: Boolean): TColor; override;
    function GridGroupRowStyleOffice11SeparatorColor: TColor; override;
    function GridGroupRowStyleOffice11TextColor: TColor; override;
    function PivotGridHeadersAreaColor: TColor; override;
    function PivotGridHeadersAreaTextColor: TColor; override;
    // Layout View
    procedure LayoutViewDrawRecordCaption(ACanvas: TcxCanvas; const ABounds, ATextRect: TRect;
      APosition: TcxGroupBoxCaptionPosition; AState: TcxButtonState); override;
    procedure LayoutViewDrawRecordContent(ACanvas: TcxCanvas; const ABounds: TRect;
      ACaptionPosition: TcxGroupBoxCaptionPosition; AState: TcxButtonState;
      ABorders: TcxBorders = cxBordersAll); override;
    procedure LayoutViewDrawRecordExpandButton(ACanvas: TcxCanvas;
      const ABounds: TRect; AState: TcxButtonState; AExpanded: Boolean); override;
    procedure LayoutViewDrawItem(ACanvas: TcxCanvas; const ABounds: TRect;
      AState: TcxButtonState; ABorders: TcxBorders = []); override;
    function LayoutViewGetPadding(AElement: TcxLayoutElement): TRect; override;
    function LayoutViewGetSpacing(AElement: TcxLayoutElement): TRect; override;
    function LayoutViewRecordCaptionTailSize(ACaptionPosition: TcxGroupBoxCaptionPosition): Integer; override;
    // Footer
    procedure DrawFooterBorderEx(ACanvas: TcxCanvas; const R: TRect; ABorders: TcxBorders); override;
    procedure DrawFooterCellBorder(ACanvas: TcxCanvas; const R: TRect); override;
    procedure DrawFooterCellContent(ACanvas: TcxCanvas; const ABounds: TRect;
      AAlignmentHorz: TAlignment; AAlignmentVert: TcxAlignmentVert; AMultiLine: Boolean;
      const AText: string; AFont: TFont; ATextColor, ABkColor: TColor;
      AOnDrawBackground: TcxDrawBackgroundEvent = nil); override;
    procedure DrawFooterContent(ACanvas: TcxCanvas; const ARect: TRect;
      const AViewParams: TcxViewParams); override;
    function FooterCellBorderSize: Integer; override;
    function FooterDrawCellsFirst: Boolean; override;
    function FooterSeparatorColor: TColor; override;
    // filter
    function FilterCloseButtonSize: TPoint; override;
    function FilterSmartTagSize: TSize; override;
    procedure DrawFilterCloseButton(ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState); override;
    procedure DrawFilterDropDownButton(ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState; AIsFilterActive: Boolean); override;
    procedure DrawFilterPanel(ACanvas: TcxCanvas; const ARect: TRect;
      ATransparent: Boolean; ABackgroundColor: TColor; const ABackgroundBitmap: TBitmap); override;
    procedure DrawFilterSmartTag(ACanvas: TcxCanvas; R: TRect;
      AState: TcxFilterSmartTagState; AIsFilterActive: Boolean); override;
    // Panel
    procedure DrawPanelBorders(ACanvas: TcxCanvas; const ABorderRect: TRect); override;
    procedure DrawPanelContent(ACanvas: TcxCanvas; const ABorderRect: TRect; ABorder: Boolean); override;
    // TrackBar
    procedure DrawTrackBarTrack(ACanvas: TcxCanvas; const ARect, ASelection: TRect;
      AShowSelection, AEnabled, AHorizontal: Boolean; ATrackColor: TColor); override;
    procedure DrawTrackBarThumb(ACanvas: TcxCanvas; const ARect: TRect;
      AState: TcxButtonState; AHorizontal: Boolean;
      ATicks: TcxTrackBarTicksAlign; AThumbColor: TColor); override;
    function TrackBarThumbSize(AHorizontal: Boolean): TSize; override;
    function TrackBarTicksColor(AText: Boolean): TColor; override;
    function TrackBarTrackSize: Integer; override;
    // Splitter
    procedure DrawSplitter(ACanvas: TcxCanvas; const ARect: TRect;
      AHighlighted: Boolean; AClicked: Boolean; AHorizontal: Boolean); override;
    function GetSplitterSize(AHorizontal: Boolean): TSize; override;
    // Hints
      // Attributes
    function GetHintBorderColor: TColor; override;
      // Draw
    procedure DrawHintBackground(ACanvas: TcxCanvas; const ARect: TRect;
      AColor: TColor = clDefault); override;
    // ScreenTips
      // Attributes
    function ScreenTipGetDescriptionTextColor: TColor; override;
    function ScreenTipGetTitleTextColor: TColor; override;
      // Size
    function ScreenTipGetFooterLineSize: Integer; override;
      // Draw
    procedure ScreenTipDrawBackground(ACanvas: TcxCanvas; ARect: TRect); override;
    procedure ScreenTipDrawFooterLine(ACanvas: TcxCanvas; const ARect: TRect); override;
    // Indicator
    procedure DrawIndicatorCustomizationMark(ACanvas: TcxCanvas;
      const R: TRect; AColor: TColor); override;
    procedure DrawIndicatorImage(ACanvas: TcxCanvas; const R: TRect; AKind: TcxIndicatorKind); override;
    procedure DrawIndicatorItem(ACanvas: TcxCanvas; const R: TRect;
      AKind: TcxIndicatorKind; AColor: TColor; AOnDrawBackground: TcxDrawBackgroundEvent = nil); override;
    procedure DrawIndicatorItemEx(ACanvas: TcxCanvas; const R: TRect;
      AKind: TcxIndicatorKind; AColor: TColor; AOnDrawBackground: TcxDrawBackgroundEvent = nil); override;
    function IndicatorDrawItemsFirst: Boolean; override;
    // ms outlook
    procedure DrawMonthHeader(ACanvas: TcxCanvas; const ABounds: TRect;
      const AText: string; ANeighbors: TcxNeighbors; const AViewParams: TcxViewParams;
      AArrows: TcxArrowDirections; ASideWidth: Integer; AOnDrawBackground: TcxDrawBackgroundEvent = nil); override;
    // Scheduler
    procedure CalculateSchedulerNavigationButtonRects(AIsNextButton: Boolean;
      ACollapsed: Boolean; APrevButtonTextSize: TSize; ANextButtonTextSize: TSize;
      var ABounds: TRect; out ATextRect: TRect; out AArrowRect: TRect); override;
    procedure DrawSchedulerEventProgress(ACanvas: TcxCanvas;
      const ABounds, AProgress: TRect; AViewParams: TcxViewParams; ATransparent: Boolean); override;
    procedure DrawSchedulerGroup(ACanvas: TcxCanvas; const R: TRect; AColor: TColor = clDefault); override;
    procedure DrawSchedulerGroupSeparator(ACanvas: TcxCanvas; const ABounds: TRect;
      ABackgroundColor: TColor; AOnDrawBackground: TcxDrawBackgroundEvent); override;
    procedure DrawSchedulerMilestone(ACanvas: TcxCanvas; const R: TRect); override;
    procedure DrawSchedulerNavigatorButton(ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState); override;
    function SchedulerEventProgressOffsets: TRect; override;
    function SchedulerNavigationButtonTextColor(AIsNextButton: Boolean;
      AState: TcxButtonState; ADefaultColor: TColor = clDefault): TColor; override;
    procedure SchedulerNavigationButtonSizes(AIsNextButton: Boolean;
      var ABorders: TRect; var AArrowSize: TSize; var AHasTextArea: Boolean); override;
    // Layout Control
    function LayoutControlEmptyAreaColor: TColor; override;
    procedure DrawLayoutControlBackground(ACanvas: TcxCanvas; const R: TRect); override;
    // ScrollBox
    procedure DrawScrollBoxBackground(ACanvas: TcxCanvas; const R: TRect; AColor: TColor); override;
    // Popup
    procedure DrawEditPopupWindowBorder(ACanvas: TcxCanvas; var R: TRect;
      ABorderStyle: TcxEditPopupBorderStyle; AClientEdge: Boolean); override;
    function GetEditPopupWindowBorderWidth(AStyle: TcxEditPopupBorderStyle): Integer; override;
    function GetEditPopupWindowClientEdgeWidth(AStyle: TcxEditPopupBorderStyle): Integer; override;
    // Window
    function GetWindowContentTextColor: TColor; override;
    procedure DrawWindowContent(ACanvas: TcxCanvas; const ARect: TRect); override;
    // Printing System
    function PrintPreviewPageBordersWidth: TRect; override;
    procedure DrawPrintPreviewBackground(ACanvas: TcxCanvas; const R: TRect); override;
    procedure DrawPrintPreviewPageBackground(ACanvas: TcxCanvas;
      const ABorderRect, AContentRect: TRect; ASelected, ADrawContent: Boolean); override;
    // DateNavigator
    procedure DrawDateNavigatorDateHeader(ACanvas: TcxCanvas; var R: TRect); override;
    // CalcEdit
    function CalcEditButtonTextColor(AButtonKind: TcxCalcButtonKind): TColor; override;
    // Customization Form
    function GetCustomizationFormListBackgroundColor: TColor; override;
    // BreadcrumbEdit
    function BreadcrumbEditBackgroundColor(AState: TdxBreadcrumbEditState): TColor; override;
    function BreadcrumbEditBordersColor(AState: TdxBreadcrumbEditState): TColor; virtual;
    function BreadcrumbEditButtonAreaSeparatorSize: Integer; override;
    function BreadcrumbEditButtonContentOffsets(AIsFirst, AIsLast: Boolean): TRect; override;
    function BreadcrumbEditDropDownButtonOriginalWidth: Integer; override;
    function BreadcrumbEditIsFadingSupports: Boolean; override;
    function BreadcrumbEditNodeTextColor(AState: TdxBreadcrumbEditButtonState): TColor; override;
    function BreadcrumbEditNodeTextOffsets: TRect; override;
    function BreadcrumbEditProgressChunkOverlaySize: TSize; override;
    function BreadcrumbEditProgressChunkPadding: TRect; override;
    procedure DrawBreadcrumbEditBorders(ACanvas: TcxCanvas; const ARect: TRect;
      ABorders: TcxBorders; AState: TdxBreadcrumbEditState); override;
    procedure DrawBreadcrumbEditButton(ACanvas: TcxCanvas; const ARect: TRect;
      AState: TdxBreadcrumbEditButtonState; AIsFirst, AIsLast: Boolean); override;
    procedure DrawBreadcrumbEditButtonAreaSeparator(ACanvas: TcxCanvas;
      const ARect: TRect; AState: TdxBreadcrumbEditState); override;
    procedure DrawBreadcrumbEditDropDownButton(ACanvas: TcxCanvas;
      const ARect: TRect; AState: TdxBreadcrumbEditButtonState; AIsInEditor: Boolean); override;
    procedure DrawBreadcrumbEditDropDownButtonGlyph(ACanvas: TcxCanvas;
      const ARect: TRect; AState: TdxBreadcrumbEditButtonState; AIsInEditor: Boolean); override;
    procedure DrawBreadcrumbEditNode(ACanvas: TcxCanvas;
      const R: TRect; AState: TdxBreadcrumbEditButtonState; AHasDelimiter: Boolean); override;
    procedure DrawBreadcrumbEditNodeDelimiter(ACanvas: TcxCanvas;
      const R: TRect; AState: TdxBreadcrumbEditButtonState); override;
    procedure DrawBreadcrumbEditNodeMoreButtonGlyph(ACanvas: TcxCanvas;
      const R: TRect; AState: TdxBreadcrumbEditButtonState); override;
    procedure DrawBreadcrumbEditNodeDelimiterGlyph(ACanvas: TcxCanvas;
      const R: TRect; AState: TdxBreadcrumbEditButtonState); override;
    procedure DrawBreadcrumbEditProgressChunk(ACanvas: TcxCanvas; const R: TRect); override;
    procedure DrawBreadcrumbEditProgressChunkOverlay(ACanvas: TcxCanvas; const R: TRect); override;
    // DropDownList
    function DropDownListBoxBordersSize: Integer; override;
    function DropDownListBoxItemImageOffsets: TRect; override;
    function DropDownListBoxItemTextColor(ASelected: Boolean): TColor; override;
    function DropDownListBoxItemTextOffsets: TRect; override;
    function DropDownListBoxSeparatorSize: Integer; override;
    procedure DrawDropDownListBoxBackground(ACanvas: TcxCanvas; const ARect: TRect; AHasBorders: Boolean); override;
    procedure DrawDropDownListBoxGutterBackground(ACanvas: TcxCanvas; const ARect: TRect); override;
    procedure DrawDropDownListBoxSelection(ACanvas: TcxCanvas; const ARect, AGutterRect: TRect); override;
    procedure DrawDropDownListBoxSeparator(ACanvas: TcxCanvas; const ARect, AGutterRect: TRect); override;
    // AlertWindow
    function AlertWindowButtonContentOffsets(AKind: TdxAlertWindowButtonKind): TRect; override;
    function AlertWindowButtonElement(AKind: TdxAlertWindowButtonKind): TdxSkinElement;
    function AlertWindowContentOffsets: TRect; override;
    function AlertWindowCornerRadius: Integer; override;
    function AlertWindowNavigationPanelTextColor: TColor; override;
    function AlertWindowTextColor: TColor; override;
    procedure DrawAlertWindowBackground(ACanvas: TcxCanvas; const ABounds: TRect); override;
    procedure DrawAlertWindowButton(ACanvas: TcxCanvas; const ABounds: TRect;
      AState: TcxButtonState; AKind: TdxAlertWindowButtonKind; ADown: Boolean); override;
    procedure DrawAlertWindowNavigationPanel(ACanvas: TcxCanvas; const ABounds: TRect); override;
    // Bevel
    function GetBevelMinimalShapeSize(AShape: TdxBevelShape): TSize; override;
    procedure GetBevelShapeColors(out AColor1, AColor2: TColor); override;
    // Gallery
    function GetGalleryGroupHeaderContentOffsets: TRect; override;
    function GetGalleryGroupTextColor: TColor; override;
    function GetGalleryItemCaptionTextColor(const AState: TdxGalleryItemViewState): TColor; override;
    function GetGalleryItemDescriptionTextColor(const AState: TdxGalleryItemViewState): TColor; override;
    procedure DrawGalleryBackground(ACanvas: TcxCanvas; const ABounds: TRect); override;
    procedure DrawGalleryGroupHeader(ACanvas: TcxCanvas; const ABounds: TRect); override;
    procedure DrawGalleryItemImageFrame(ACanvas: TcxCanvas; const R: TRect); override;
    function DrawGalleryItemSelectionFirst: Boolean; override;
    procedure DrawGalleryItemSelection(ACanvas: TcxCanvas;
      const R: TRect; AViewState: TdxGalleryItemViewState); override;
    // ColorGallery
    function GetColorGalleryGlyphFrameColor: TColor; override;
    // BackButton
    function GetBackButtonSize: TSize; override;
    procedure DrawBackButton(ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState); override;
    //
    property SkinDetails: TdxSkinDetails read GetSkinDetails;
    property SkinInfo: TdxSkinLookAndFeelPainterInfo read GetSkinInfo;
  end;

  TdxSkinLookAndFeelPainterClass = class of TdxSkinLookAndFeelPainter;

const
  ButtonStateToSkinState: array[TcxButtonState] of TdxSkinElementState = (
    esActive, esNormal, esHot, esPressed, esDisabled
  );

implementation

uses
  Math, dxOffice11;

const
  BreadcrumbButtonStateToElementState: array[TdxBreadcrumbEditButtonState] of TdxSkinElementState =
    (esNormal, esFocused, esHot, esPressed, esDisabled);

function cxRectExclude(const R, ABordersWidth: TRect; ABorders: TcxBorders): TRect;
begin
  Result := R;
  if not (bLeft in ABorders) then
    Dec(Result.Left, ABordersWidth.Left);
  if not (bTop in ABorders) then
    Dec(Result.Top, ABordersWidth.Top);
  if not (bRight in ABorders) then
    Inc(Result.Right, ABordersWidth.Right);
  if not (bBottom in ABorders) then
    Inc(Result.Bottom, ABordersWidth.Bottom);
end;

procedure dxSkinElementMakeDisable(ABitmap: TcxBitmap32);
var
  AColor: TRGBQuad;
  AColors: TRGBColors;
  I, AGray: Integer;
begin
  ABitmap.GetBitmapColors(AColors);
  try
    for I := 0 to Length(AColors) - 1 do
    begin
      AColor := AColors[I];
      AGray := (2 * AColor.rgbReserved + AColor.rgbBlue + AColor.rgbGreen + AColor.rgbRed) div 5;
      AColor.rgbBlue := AGray;
      AColor.rgbGreen := AGray;
      AColor.rgbRed := AGray;
      AColors[I] := AColor;
    end;
  finally
    ABitmap.SetBitmapColors(AColors);
  end;
end;

{ TdxSkinLookAndFeelPainter }

constructor TdxSkinLookAndFeelPainter.Create(const ASkinResName: string; ASkinResInstance: THandle);
begin
  inherited Create;
  FSkinResName := ASkinResName;
  FSkinResInstance := ASkinResInstance;
end;

destructor TdxSkinLookAndFeelPainter.Destroy;
begin
  FreeAndNil(FSkinInfo);
  inherited Destroy;
end;

function TdxSkinLookAndFeelPainter.GetPainterData(var AData): Boolean;
begin
  TObject(AData) := SkinInfo;
  Result := True;
end;

function TdxSkinLookAndFeelPainter.GetPainterDetails(var ADetails): Boolean;
begin
  Result := SkinDetails <> nil;
  if Result then
    TObject(ADetails) := SkinDetails;
end;

function TdxSkinLookAndFeelPainter.LookAndFeelName: string;
begin
  Result := SkinInfo.Skin.Name;
end;

function TdxSkinLookAndFeelPainter.LookAndFeelStyle: TcxLookAndFeelStyle;
begin
  Result := lfsSkin;
end;

function TdxSkinLookAndFeelPainter.CreateLookAndFeelPainterDetails: TObject;
var
  ASkinDetails: TdxSkinDetails;
  AStream: TStream;
begin
  Result := nil;
  if FSkinResName <> '' then
  begin
    AStream := TResourceStream.Create(FSkinResInstance, FSkinResName, sdxResourceType);
    try
      ASkinDetails := TdxSkinDetails.Create;
      ASkinDetails.LoadFromStream(AStream);
      Result := ASkinDetails;
    finally
      AStream.Free;
    end;
  end;
end;

function TdxSkinLookAndFeelPainter.GetLookAndFeelPainterDetails: TObject;
begin
  if (FSkinInfo <> nil) and (FSkinInfo.Skin <> nil) then
    Result := FSkinInfo.Skin.Details
  else
    Result := inherited GetLookAndFeelPainterDetails;
end;

function TdxSkinLookAndFeelPainter.DefaultChartHistogramPlotColor: TColor;
begin
  Result := DefaultContentColor;
end;

function TdxSkinLookAndFeelPainter.DefaultContentColor: TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.ContentColor) then
    Result := SkinInfo.ContentColor.Value
  else
    Result := inherited DefaultContentColor;
end;

function TdxSkinLookAndFeelPainter.DefaultContentEvenColor: TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.ContentEvenColor) then
    Result := SkinInfo.ContentEvenColor.Value
  else
    Result := inherited DefaultContentEvenColor
end;

function TdxSkinLookAndFeelPainter.DefaultContentOddColor: TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.ContentOddColor) then
    Result := SkinInfo.ContentOddColor.Value
  else
    Result := inherited DefaultContentOddColor;
end;

function TdxSkinLookAndFeelPainter.DefaultContentTextColor: TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.ContentTextColor) then
    Result := SkinInfo.ContentTextColor.Value
  else
    Result := inherited DefaultContentTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultEditorBackgroundColorEx(
  AKind: TcxEditStateColorKind): TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.EditorBackgroundColors[AKind]) then
    Result := SkinInfo.EditorBackgroundColors[AKind].Value
  else
    if AKind in [esckReadOnly, esckInactive] then
      Result := DefaultEditorBackgroundColorEx(esckNormal)
    else
      Result := inherited DefaultEditorBackgroundColorEx(AKind);
end;

function TdxSkinLookAndFeelPainter.DefaultEditorTextColorEx(
  AKind: TcxEditStateColorKind): TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.EditorTextColors[AKind]) then
    Result := SkinInfo.EditorTextColors[AKind].Value
  else
    if AKind in [esckReadOnly, esckInactive] then
      Result := DefaultEditorTextColorEx(esckNormal)
    else
      Result := inherited DefaultEditorTextColorEx(AKind);
end;

function TdxSkinLookAndFeelPainter.DefaultFilterBoxTextColor: TColor;
begin
  if SkinInfo.FilterPanel = nil then
    Result := inherited DefaultFilterBoxTextColor
  else
    Result := SkinInfo.FilterPanel.TextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultFixedSeparatorColor: TColor;
begin
  if SkinInfo.GridFixedLine = nil then
    Result := inherited DefaultFixedSeparatorColor
  else
    Result := SkinInfo.GridFixedLine.Color;
end;

function TdxSkinLookAndFeelPainter.DefaultFooterColor: TColor;
begin
  if SkinInfo.FooterPanel = nil then
    Result := inherited DefaultFooterColor
  else
    Result := SkinInfo.FooterPanel.Color
end;

function TdxSkinLookAndFeelPainter.DefaultFooterTextColor: TColor;
begin
  if SkinInfo.FooterPanel = nil then
    Result := inherited DefaultFooterTextColor
  else
    Result := SkinInfo.FooterPanel.TextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultGridDetailsSiteColor: TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.ContentColor) then
    Result := SkinInfo.ContentColor.Value
  else
    Result := inherited DefaultGridDetailsSiteColor
end;

function TdxSkinLookAndFeelPainter.DefaultGridLineColor: TColor;
begin
  if SkinInfo.GridLine = nil then
    Result := inherited DefaultGridLineColor
  else
    Result := SkinInfo.GridLine.Color;
end;

function TdxSkinLookAndFeelPainter.DefaultGroupColor: TColor;
begin
  if SkinInfo.GridGroupRow = nil then
    Result := inherited DefaultGroupColor
  else
    Result := SkinInfo.GridGroupRow.Color;
end;

function TdxSkinLookAndFeelPainter.DefaultGroupByBoxTextColor: TColor;
begin
  if SkinInfo.GridGroupByBox = nil then
    Result := inherited DefaultGroupByBoxTextColor
  else
    Result := SkinInfo.GridGroupByBox.TextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultGroupTextColor: TColor;
begin
  if SkinInfo.GridGroupRow = nil then
    Result := inherited DefaultGroupTextColor
  else
    Result := SkinInfo.GridGroupRow.TextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultHeaderBackgroundColor: TColor;
begin
  if SkinInfo.HeaderBackgroundColor = nil then
    Result := inherited DefaultHeaderBackgroundColor
  else
    Result := SkinInfo.HeaderBackgroundColor.Value;
end;

function TdxSkinLookAndFeelPainter.DefaultHeaderBackgroundTextColor: TColor;
begin
  if SkinInfo.HeaderBackgroundTextColor = nil then
    Result := inherited DefaultHeaderBackgroundTextColor
  else
    Result := SkinInfo.HeaderBackgroundTextColor.Value;
end;

function TdxSkinLookAndFeelPainter.DefaultHeaderColor: TColor;
begin
  if SkinInfo.Header = nil then
    Result := inherited DefaultHeaderColor
  else
    Result := SkinInfo.Header.Color;
end;

function TdxSkinLookAndFeelPainter.DefaultHeaderTextColor: TColor;
begin
  if SkinInfo.Header = nil then
    Result := inherited DefaultHeaderTextColor
  else
    Result := SkinInfo.Header.TextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultHyperlinkTextColor: TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.HyperLinkTextColor) then
    Result := SkinInfo.HyperLinkTextColor.Value
  else
    Result := inherited DefaultHyperlinkTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultInactiveColor: TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.InactiveColor) then
    Result := SkinInfo.InactiveColor.Value
  else
    Result := inherited DefaultInactiveColor;
end;

function TdxSkinLookAndFeelPainter.DefaultInactiveTextColor: TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.InactiveTextColor) then
    Result := SkinInfo.InactiveTextColor.Value
  else
    Result := inherited DefaultInactiveTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultPreviewTextColor: TColor;
begin
  Result := DefaultHyperlinkTextColor;
end;

function TdxSkinLookAndFeelPainter.LayoutControlEmptyAreaColor: TColor;
begin
  if SkinInfo.LayoutControlColor = nil then
    Result := inherited LayoutControlEmptyAreaColor
  else
    Result := SkinInfo.LayoutControlColor.Value;
end;

procedure TdxSkinLookAndFeelPainter.DrawLayoutControlBackground(ACanvas: TcxCanvas; const R: TRect);
begin
  ACanvas.FillRect(R, LayoutControlEmptyAreaColor);
end;

procedure TdxSkinLookAndFeelPainter.DrawScrollBoxBackground(ACanvas: TcxCanvas; const R: TRect; AColor: TColor);
begin
  ACanvas.FillRect(R, DefaultContentColor);
end;

procedure TdxSkinLookAndFeelPainter.DrawEditPopupWindowBorder(ACanvas: TcxCanvas; var R: TRect;
  ABorderStyle: TcxEditPopupBorderStyle; AClientEdge: Boolean);
begin
  ACanvas.FrameRect(R, GetContainerBorderColor(False));
  InflateRect(R, -1, -1);
end;

function TdxSkinLookAndFeelPainter.GetEditPopupWindowBorderWidth(AStyle: TcxEditPopupBorderStyle): Integer;
begin
  Result := 1;
end;

function TdxSkinLookAndFeelPainter.GetEditPopupWindowClientEdgeWidth(AStyle: TcxEditPopupBorderStyle): Integer;
begin
  Result := 2;
end;

function TdxSkinLookAndFeelPainter.GetGalleryGroupHeaderContentOffsets: TRect;
begin
  if SkinInfo.GalleryGroup <> nil then
    Result := SkinInfo.GalleryGroup.ContentOffset.Rect
  else
    Result := inherited GetGalleryGroupHeaderContentOffsets;
end;

function TdxSkinLookAndFeelPainter.GetGalleryGroupTextColor: TColor;
begin
  if SkinInfo.GalleryGroup <> nil then
    Result := SkinInfo.GalleryGroup.TextColor
  else
    Result := clDefault;

  if not cxColorIsValid(Result) then
  begin
    if SkinInfo.GalleryItem <> nil then
      Result := SkinInfo.GalleryItem.TextColor
    else
      Result := inherited GetGalleryGroupTextColor;
  end;
end;

function TdxSkinLookAndFeelPainter.GetGalleryItemCaptionTextColor(const AState: TdxGalleryItemViewState): TColor;
begin
  if SkinInfo.GalleryItem <> nil then
    Result := SkinInfo.GalleryItem.GetTextColor(GalleryStateToButtonState(AState))
  else
    Result := inherited GetGalleryItemCaptionTextColor(AState);
end;

function TdxSkinLookAndFeelPainter.GetGalleryItemDescriptionTextColor(const AState: TdxGalleryItemViewState): TColor;
begin
  if SkinInfo.GalleryItem <> nil then
    Result := SkinInfo.GalleryItem.GetTextColor(GalleryStateToButtonState(AState), sdxDescriptionTextColorPrefix)
  else
    Result := inherited GetGalleryItemDescriptionTextColor(AState);
end;

function TdxSkinLookAndFeelPainter.DefaultSelectionColor: TColor;
begin
  with SkinInfo do
    if SelectionColor = nil then
      Result := inherited DefaultSelectionColor
    else
      Result := SelectionColor.Value;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerTimeRulerColor: TColor;
begin
  with SkinInfo do
    if Assigned(SchedulerTimeRuler) and cxColorIsValid(SchedulerTimeRuler.Color) then
      Result := SchedulerTimeRuler.Color
    else
      Result := inherited DefaultSchedulerTimeRulerColor;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerTimeRulerTextColor: TColor;
begin
  with SkinInfo do
    if Assigned(SchedulerTimeRuler) and cxColorIsValid(SchedulerTimeRuler.TextColor) then
      Result := SchedulerTimeRuler.TextColor
    else
      Result := inherited DefaultSchedulerTimeRulerTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultSelectionTextColor: TColor;
begin
  with SkinInfo do
    if SelectionTextColor = nil then
      Result := inherited DefaultSelectionTextColor
    else
      Result := SelectionTextColor.Value;  
end;

function TdxSkinLookAndFeelPainter.DefaultSeparatorColor: TColor;
begin
  with SkinInfo do
    if CardViewSeparator = nil then
      Result := inherited DefaultSeparatorColor
    else
      Result := CardViewSeparator.Color;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerBackgroundColor: TColor;
begin
  with SkinInfo do
    if ContentColor = nil then
      Result := inherited DefaultSchedulerBackgroundColor
    else
      Result := ContentColor.Value;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerBorderColor: TColor;
begin
  with SkinInfo do
    if ContainerBorderColor = nil then
      Result := inherited DefaultSchedulerBorderColor
    else
      Result := ContainerBorderColor.Value;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerContentColor(AResourceIndex: Integer): TColor;
var
  AColorProperty: TdxSkinColor;
begin
  AColorProperty := SkinInfo.SchedulerResourceColors[AResourceIndex mod dxSkinsSchedulerResourceColorsCount];
  if AColorProperty <> nil then
    Result := AColorProperty.Value
  else
    Result := inherited DefaultSchedulerContentColor(AResourceIndex);
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerControlColor: TColor;
begin
  with SkinInfo do
    if ContentColor = nil then
      Result := inherited DefaultSchedulerControlColor
    else
      Result := ContentColor.Value;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerEventColor(AIsAllDayEvent: Boolean): TColor;
begin
  if SkinInfo.SchedulerAppointment[True] <> nil then
    Result := clWindow
  else
    Result := inherited DefaultSchedulerEventColor(AIsAllDayEvent);
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerNavigatorColor: TColor;
begin
  with SkinInfo do
    if SchedulerNavigatorColor = nil then
      Result := inherited DefaultSchedulerNavigatorColor
    else
      Result := SchedulerNavigatorColor.Value;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerViewContentColor: TColor;
begin
  Result := DefaultSchedulerContentColor(0);
  if Result = clDefault then
    Result := inherited DefaultSchedulerViewContentColor;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerViewSelectedTextColor: TColor;
begin
  Result := DefaultSchedulerViewTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerViewTextColor: TColor;
begin
  with SkinInfo do
    if SchedulerAppointment[True] = nil then
      Result := inherited DefaultSchedulerViewTextColor
    else
      Result := SchedulerAppointment[True].TextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultSchedulerYearViewUnusedContentColor(
  AIsWorkTime: Boolean): TColor;
const
  IntensityMap: array[Boolean] of Integer = (80, 85);
begin
  Result := DefaultSchedulerContentColor(0);
  if cxColorIsValid(Result) then
    Result := Dark(Result, IntensityMap[AIsWorkTime]);
end;

function TdxSkinLookAndFeelPainter.DefaultSizeGripAreaColor: TColor;
begin
  Result := clDefault;
  if SkinInfo.FormContent <> nil then
    Result := SkinInfo.FormContent.Color;
  if Result = clDefault then
    Result := inherited DefaultSizeGripAreaColor; 
end;

function TdxSkinLookAndFeelPainter.DefaultTimeGridMajorScaleTextColor: TColor;
begin
  with SkinInfo do
    if (SchedulerTimeGridHeader[False] <> nil) and
      cxColorIsValid(SchedulerTimeGridHeader[False].TextColor)
    then
      Result := SchedulerTimeGridHeader[False].TextColor
    else
      Result := inherited DefaultTimeGridMajorScaleTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultTimeGridMinorScaleTextColor: TColor;
begin
  Result := DefaultTimeGridMajorScaleTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultGridOptionsTreeViewCategoryColor(ASelected: Boolean): TColor;
begin
  if ASelected then
    Result := DefaultSelectionColor
  else
    Result := DefaultGroupColor;
end;

function TdxSkinLookAndFeelPainter.DefaultGridOptionsTreeViewCategoryTextColor(ASelected: Boolean): TColor;
begin
  if ASelected then
    Result := DefaultSelectionTextColor
  else
    Result := DefaultGroupTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultTreeListGridLineColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(TreeListGridLineColor) then
      Result := TreeListGridLineColor.Value
    else
      Result := inherited DefaultTreeListGridLineColor
end;

function TdxSkinLookAndFeelPainter.DefaultTreeListTreeLineColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(TreeListTreeLineColor) then
      Result := TreeListTreeLineColor.Value
    else
      Result := inherited DefaultTreeListTreeLineColor
end;

function TdxSkinLookAndFeelPainter.DefaultLayoutViewCaptionTextColor(
  ACaptionPosition: TcxGroupBoxCaptionPosition; AState: TcxButtonState): TColor;
const
  PropertiesMap: array[TcxButtonState] of string = (
    '', '', sdxTextColorHot, sdxTextColorSelected, sdxTextColorInactive
  );
var
  AElement: TdxSkinElement;
  AProperty: TdxSkinProperty;
begin
  AElement := SkinInfo.LayoutViewRecordCaptionElements[cxgpTop];
  if AElement = nil then
    Result := clDefault
  else
    if AElement.GetPropertyByName(PropertiesMap[AState], AProperty) then
      Result := (AProperty as TdxSkinColor).Value
    else
      Result := AElement.TextColor;

  if Result = clDefault then
    Result := DefaultContentTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultLayoutViewContentTextColor(AState: TcxButtonState): TColor;
begin
  Result := clDefault;
  if SkinInfo.LayoutViewItem <> nil then
    Result := SkinInfo.LayoutViewItem.GetTextColor(AState);
  if Result = clDefault then
    Result := DefaultContentTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultRecordSeparatorColor: TColor;
begin
  with SkinInfo do
    if GridFixedLine = nil then
      Result := inherited DefaultRecordSeparatorColor
    else
      Result := GridFixedLine.Color;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorHeaderColor: TColor;
begin
  Result := DefaultHeaderColor;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorHeaderTextColor(
  AIsHighlight: Boolean): TColor;
begin
  Result := DefaultHeaderTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorTextColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalendarDayTextColor) then
      Result := CalendarDayTextColor.Value
    else
      Result := inherited DefaultDateNavigatorTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorHolydayTextColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalendarHolidayTextColor) then
      Result := CalendarHolidayTextColor.Value
    else
      Result := inherited DefaultDateNavigatorHolydayTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorInactiveTextColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalendarInactiveDayTextColor) then
      Result := CalendarInactiveDayTextColor.Value
    else
      Result := inherited DefaultDateNavigatorInactiveTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorSelectionColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalendarSelectedDayColor) then
      Result := CalendarSelectedDayColor.Value
    else
      Result := inherited DefaultDateNavigatorSelectionColor;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorSelectionTextColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalendarSelectedDayTextColor) then
      Result := CalendarSelectedDayTextColor.Value
    else
      Result := inherited DefaultDateNavigatorSelectionTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorSeparator1Color: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalendarSeparatorColor) then
      Result := CalendarSeparatorColor.Value
    else
      Result := inherited DefaultDateNavigatorSeparator1Color;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorSeparator2Color: TColor;
begin
  Result := clNone;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorTodayFrameColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalendarTodayFrameColor) then
      Result := CalendarTodayFrameColor.Value
    else
      Result := inherited DefaultDateNavigatorTodayFrameColor;
end;

function TdxSkinLookAndFeelPainter.DefaultDateNavigatorTodayTextColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalendarTodayTextColor) then
      Result := CalendarTodayTextColor.Value
    else
      Result := inherited DefaultDateNavigatorTodayTextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultVGridBandLineColor: TColor;
begin
  with SkinInfo do
  begin
    if VGridLine[True] = nil then
      Result := inherited DefaultVGridBandLineColor
    else
      Result := VGridLine[True].Color;
  end;
end;

function TdxSkinLookAndFeelPainter.DefaultVGridCategoryColor: TColor;
begin
  with SkinInfo do
    if VGridCategory = nil then
      Result := inherited DefaultVGridCategoryColor
    else
      Result := VGridCategory.Color;
end;

function TdxSkinLookAndFeelPainter.DefaultVGridCategoryTextColor: TColor;
begin
  with SkinInfo do
    if VGridCategory = nil then
      Result := inherited DefaultVGridCategoryTextColor
    else
      Result := VGridCategory.TextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultVGridHeaderColor: TColor;
begin
  with SkinInfo do
    if VGridRowHeader = nil then
      Result := inherited DefaultVGridHeaderColor
    else
      Result := VGridRowHeader.Color;
end;

function TdxSkinLookAndFeelPainter.DefaultVGridHeaderTextColor: TColor;
begin
  with SkinInfo do
    if VGridRowHeader = nil then
      Result := inherited DefaultVGridHeaderTextColor
    else
      Result := VGridRowHeader.TextColor;
end;

function TdxSkinLookAndFeelPainter.DefaultVGridLineColor: TColor;
begin
  with SkinInfo do
  begin
    if VGridLine[False] = nil then
      Result := inherited DefaultVGridLineColor
    else
      Result := VGridLine[False].Color;
  end;
end;

function TdxSkinLookAndFeelPainter.SeparatorSize: Integer;
begin
  Result := LabelLineHeight;
end;

procedure TdxSkinLookAndFeelPainter.DrawBackButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  if SkinInfo.BackButton = nil then
    inherited DrawBackButton(ACanvas, R, AState)
  else
    SkinInfo.BackButton.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawBorder(ACanvas: TcxCanvas; R: TRect);
begin
  if SkinInfo.ContainerBorderColor = nil then
    inherited DrawBorder(ACanvas, R)
  else
    ACanvas.FrameRect(R, SkinInfo.ContainerBorderColor.Value);
end;

procedure TdxSkinLookAndFeelPainter.DrawContainerBorder(ACanvas: TcxCanvas; const R: TRect; AStyle: TcxContainerBorderStyle;
  AWidth: Integer; AColor: TColor; ABorders: TcxBorders);
begin
  inherited DrawContainerBorder(ACanvas, R, cbsSingle, AWidth, AColor, ABorders);
end;

procedure TdxSkinLookAndFeelPainter.DoDrawSeparator(ACanvas: TcxCanvas; R: TRect; AIsVertical: Boolean);
begin
  DrawLabelLine(ACanvas, R, clDefault, clDefault, AIsVertical);
end;

function TdxSkinLookAndFeelPainter.ButtonBorderSize(
  AState: TcxButtonState = cxbsNormal): Integer;
begin
  if SkinInfo.ButtonElements <> nil then
    Result := 0
  else
    Result := inherited ButtonBorderSize(AState);
end;

function TdxSkinLookAndFeelPainter.ButtonDescriptionTextColor(
  AState: TcxButtonState; ADefaultColor: TColor): TColor;
begin
  if SkinInfo.ButtonElements <> nil then
    Result := SkinInfo.ButtonElements.GetTextColor(AState, sdxDescriptionTextColorPrefix)
  else
    Result := clDefault;

  if not cxColorIsValid(Result) then
    Result := ADefaultColor;
end;

function TdxSkinLookAndFeelPainter.ButtonFocusRect(
  ACanvas: TcxCanvas; R: TRect): TRect;
begin
  Result := inherited ButtonFocusRect(ACanvas, R);
end;

function TdxSkinLookAndFeelPainter.ButtonSymbolColor(
  AState: TcxButtonState; ADefaultColor: TColor = clDefault): TColor;
begin
  with SkinInfo do
    if ButtonElements = nil then
      Result := inherited ButtonSymbolColor(AState, ADefaultColor)
    else
      if (AState = cxbsDisabled) and (ButtonDisabled <> nil) then
        Result := ButtonDisabled.Value
      else
        Result := ButtonElements.GetTextColor(AState);
end;

function TdxSkinLookAndFeelPainter.ButtonTextOffset: Integer;
begin
  Result := inherited ButtonTextOffset;
end;

function TdxSkinLookAndFeelPainter.ButtonTextShift: Integer;
begin
  Result := inherited ButtonTextShift;
end;

procedure TdxSkinLookAndFeelPainter.DrawButton(ACanvas: TcxCanvas;
  R: TRect; const ACaption: string; AState: TcxButtonState; ADrawBorder: Boolean = True;
  AColor: TColor = clDefault; ATextColor: TColor = clDefault;
  AWordWrap: Boolean = False; AIsToolButton: Boolean = False);
var
  AFlags: Integer;
begin
  with ACanvas, SkinInfo do
    if ButtonElements <> nil then
    begin
      ButtonElements.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
      R := cxRectContent(R, ButtonElements.ContentOffset.Rect);
      if ATextColor = clDefault then
        Font.Color := ButtonSymbolColor(AState)
      else
        Font.Color := ATextColor;
      Brush.Style := bsClear;
      with R do // for compatible with standard buttons
      begin
        Dec(Bottom, Ord(Odd(Bottom - Top)));
        if (Bottom - Top) < 18 then Dec(Top);
      end;
      if AState = cxbsPressed then
        OffsetRect(R, ButtonTextShift, ButtonTextShift);
      if Length(ACaption) > 0 then
      begin
        AFlags := cxAlignVCenter or cxShowPrefix or cxAlignHCenter;
        if AWordWrap then
          AFlags := AFlags or cxWordBreak
        else
          AFlags := AFlags or cxSingleLine;
        DrawText(ACaption, R, AFlags, AState <> cxbsDisabled);
      end;
      Brush.Style := bsSolid;
    end
    else
      inherited DrawButton(ACanvas, R, ACaption, AState, ADrawBorder, AColor,
        ATextColor, AWordWrap);
end;

procedure TdxSkinLookAndFeelPainter.DrawExpandButton(ACanvas: TcxCanvas;
  const R: TRect; AExpanded: Boolean; AColor: TColor = clDefault);
begin
  with SkinInfo do
  begin
    if ExpandButton = nil then
      inherited DrawExpandButton(ACanvas, R, AExpanded, AColor)
    else
      ExpandButton.Draw(ACanvas.Handle, R, Byte(AExpanded));
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawExpandButtonEx(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState; AExpanded: Boolean; ARotationAngle: TcxRotationAngle = ra0);
begin
  DrawExpandButton(ACanvas, R, AExpanded);
end;

function TdxSkinLookAndFeelPainter.DrawExpandButtonFirst: Boolean;
begin
  Result := inherited DrawExpandButtonFirst;
end;

procedure TdxSkinLookAndFeelPainter.DrawGroupExpandButton(
  ACanvas: TcxCanvas; const R: TRect; AExpanded: Boolean; AState: TcxButtonState);
begin
  inherited DrawGroupExpandButton(ACanvas,R, AExpanded, AState);
end;

procedure TdxSkinLookAndFeelPainter.DrawSmallExpandButton(
  ACanvas: TcxCanvas; R: TRect; AExpanded: Boolean;
  ABorderColor: TColor; AColor: TColor = clDefault);
begin
  with SkinInfo do
  begin
    if ExpandButton = nil then
      inherited DrawSmallExpandButton(ACanvas, R, AExpanded, ABorderColor, AColor)
    else
      ExpandButton.Draw(ACanvas.Handle, R, Byte(AExpanded));
  end; 
end;

function TdxSkinLookAndFeelPainter.ExpandButtonSize: Integer;
begin
  with SkinInfo do
  begin
    if ExpandButton = nil then
      Result := inherited ExpandButtonSize
    else
      Result := ExpandButton.Size.cy;  
  end;
end;

function TdxSkinLookAndFeelPainter.GroupExpandButtonSize: Integer;
begin
  Result := inherited GroupExpandButtonSize;
end;

function TdxSkinLookAndFeelPainter.SmallExpandButtonSize: Integer;
begin
  Result := inherited SmallExpandButtonSize;
end;

function TdxSkinLookAndFeelPainter.IsButtonHotTrack: Boolean;
begin
  Result := inherited IsButtonHotTrack;
end;

function TdxSkinLookAndFeelPainter.IsPointOverGroupExpandButton(
  const R: TRect; const P: TPoint): Boolean;
begin
  Result := inherited IsPointOverGroupExpandButton(R, P);
end;

function TdxSkinLookAndFeelPainter.ScrollBarMinimalThumbSize(AVertical: Boolean): Integer;
var
  AInfo: TdxSkinScrollInfo;
begin
  AInfo := SkinInfo.ScrollBar_Elements[not AVertical, sbpThumbnail];
  if (AInfo = nil) or (AInfo.Element = nil) then
    Result := inherited ScrollBarMinimalThumbSize(AVertical)
  else
    if AVertical then
      Result := AInfo.Element.Size.cy
    else
      Result := AInfo.Element.Size.cx;
end;

procedure TdxSkinLookAndFeelPainter.DrawScrollBarBackground(
  ACanvas: TcxCanvas; const R: TRect; AHorizontal: Boolean);
var
  AScrollInfoElement: TdxSkinScrollInfo;
begin
  AScrollInfoElement := SkinInfo.ScrollBar_Elements[AHorizontal, sbpPageUp];
  if (AScrollInfoElement = nil) or (AScrollInfoElement.Element = nil) then
    inherited DrawScrollBarBackground(ACanvas, R, AHorizontal)
  else
  begin
    AScrollInfoElement.Element.UseCache := True;
    AScrollInfoElement.Element.Draw(ACanvas.Handle, R);
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawScrollBarPart(ACanvas: TcxCanvas;
  AHorizontal: Boolean; R: TRect; APart: TcxScrollBarPart; AState: TcxButtonState);
var
  AScrollPartInfo: TdxSkinScrollInfo;
begin
  AScrollPartInfo := SkinInfo.ScrollBar_Elements[AHorizontal, APart];
  if (AScrollPartInfo = nil) or (AScrollPartInfo.Element = nil) then
    inherited DrawScrollBarPart(ACanvas, AHorizontal, R, APart, AState)
  else
    if not ((APart in [sbpPageUp, sbpPageDown]) and (AState = cxbsNormal)) then
      AScrollPartInfo.Draw(ACanvas.Handle, R, ButtonStateToSkinState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawLabelLine(ACanvas: TcxCanvas;
  const R: TRect; AOuterColor, AInnerColor: TColor; AIsVertical: Boolean);
begin
  with SkinInfo do
    if LabelLine[AIsVertical] = nil then
      inherited DrawLabelLine(ACanvas, R, AOuterColor, AInnerColor, AIsVertical)
    else
      LabelLine[AIsVertical].Draw(ACanvas.Handle, R);
end;

function TdxSkinLookAndFeelPainter.LabelLineHeight: Integer;
begin
  with SkinInfo do
    if LabelLine[False] = nil then
      Result := inherited LabelLineHeight
    else
      Result := LabelLine[False].MinSize.Height;
end;

function TdxSkinLookAndFeelPainter.SizeGripSize: TSize;
begin
  with SkinInfo do
    if SizeGrip = nil then
      Result := inherited SizeGripSize
    else
      Result := SizeGrip.Size
end;

procedure TdxSkinLookAndFeelPainter.DoDrawSizeGrip(ACanvas: TcxCanvas; const ARect: TRect);
begin
  with SkinInfo do
    if SizeGrip = nil then
      inherited DoDrawSizeGrip(ACanvas, ARect)
    else
      SizeGrip.Draw(ACanvas.Handle, ARect);
end;

function TdxSkinLookAndFeelPainter.SliderButtonSize(ADirection: TcxArrowDirection): TSize;
begin
  with SkinInfo do
    if SliderArrow[ADirection] = nil then
      Result := inherited SliderButtonSize(ADirection)
    else
      Result := SliderArrow[ADirection].Size
end;

procedure TdxSkinLookAndFeelPainter.DrawSliderButton(ACanvas: TcxCanvas;
  const ARect: TRect; ADirection: TcxArrowDirection; AState: TcxButtonState);
begin
  with SkinInfo do
    if SliderArrow[ADirection] = nil then
      inherited DrawSliderButton(ACanvas, ARect, ADirection, AState)
    else
      SliderArrow[ADirection].Draw(ACanvas.Handle, ARect, 0, ButtonStateToSkinState[AState])
end;

function TdxSkinLookAndFeelPainter.SmallCloseButtonSize: TSize;
begin
  with SkinInfo do
    if PageControlCloseButton = nil then
      Result := inherited SmallCloseButtonSize
    else
      Result := PageControlCloseButton.MinSize.Size;
end;

procedure TdxSkinLookAndFeelPainter.DrawSmallButton(ACanvas: TcxCanvas;
  R: TRect; AState: TcxButtonState);
begin
  with SkinInfo do
    if PageControlHeaderButton = nil then
      inherited DrawSmallButton(ACanvas, R, AState)
    else
      PageControlHeaderButton.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawSmallCloseButton(ACanvas: TcxCanvas;
  R: TRect; AState: TcxButtonState);
begin
  with SkinInfo do
    if PageControlCloseButton = nil then
      inherited DrawSmallCloseButton(ACanvas, R, AState)
    else
      PageControlCloseButton.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawRadioButton(ACanvas: TcxCanvas;
  X, Y: Integer; AButtonState: TcxButtonState; AChecked, AFocused: Boolean;
  ABrushColor: TColor;  AIsDesigning: Boolean = False);
var
  ADestRect: TRect;
begin
  with SkinInfo do
  begin
    if RadioGroupButton <> nil then
    begin
      ADestRect := Rect(X, Y, X + RadioGroupButton.Size.cX, Y + RadioGroupButton.Size.cy);
      if ABrushColor <> clDefault then
        ACanvas.FillRect(ADestRect, ABrushColor);
      RadioGroupButton.Draw(ACanvas.Handle, ADestRect, Byte(AChecked),
        ButtonStateToSkinState[AButtonState]);
    end
    else
      inherited DrawRadioButton(ACanvas, X, Y, AButtonState, AChecked, AFocused,
        ABrushColor, AIsDesigning);
  end;      
end;

function TdxSkinLookAndFeelPainter.RadioButtonSize: TSize;
begin
  with SkinInfo do
    if RadioGroupButton <> nil then
      Result := RadioGroupButton.Size
    else
      Result := inherited RadioButtonSize;
end;

function TdxSkinLookAndFeelPainter.CheckButtonSize: TSize;
begin
  with SkinInfo do
    if CheckboxElement <> nil then
      Result := CheckboxElement.Size
    else
      Result := inherited CheckButtonSize;
end;

function TdxSkinLookAndFeelPainter.CalcEditButtonTextColor(
  AButtonKind: TcxCalcButtonKind): TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(CalcEditButtonTextColors[AButtonKind]) then
      Result := CalcEditButtonTextColors[AButtonKind].Value
    else
      Result := inherited CalcEditButtonTextColor(AButtonKind);
end;

function TdxSkinLookAndFeelPainter.GetCustomizationFormListBackgroundColor: TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(ContentColor) then
      Result := ContentColor.Value
    else
      Result := inherited GetCustomizationFormListBackgroundColor;
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditBackgroundColor(AState: TdxBreadcrumbEditState): TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.BreadcrumbEditBackgroundColors[AState]) then
    Result := SkinInfo.BreadcrumbEditBackgroundColors[AState].Value
  else
    if IsColorPropertyAssigned(SkinInfo.BreadcrumbEditBackgroundColors[dxbcsNormal]) then
      Result := SkinInfo.BreadcrumbEditBackgroundColors[dxbcsNormal].Value
    else
      Result := inherited BreadcrumbEditBackgroundColor(AState);
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditBordersColor(AState: TdxBreadcrumbEditState): TColor;
begin
  if IsColorPropertyAssigned(SkinInfo.BreadcrumbEditBordersColors[AState]) then
    Result := SkinInfo.BreadcrumbEditBordersColors[AState].Value
  else
    if IsColorPropertyAssigned(SkinInfo.BreadcrumbEditBordersColors[dxbcsNormal]) then
      Result := SkinInfo.BreadcrumbEditBordersColors[dxbcsNormal].Value
    else
      Result := clDefault;
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditButtonAreaSeparatorSize: Integer;
begin
  if SkinInfo.BreadcrumbEditButtonsAreaSeparator <> nil then
    Result := SkinInfo.BreadcrumbEditButtonsAreaSeparator.MinSize.Width
  else
    Result := inherited BreadcrumbEditButtonAreaSeparatorSize;
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditButtonContentOffsets(AIsFirst, AIsLast: Boolean): TRect;
begin
  if SkinInfo.BreadcrumbEditButton <> nil then
  begin
    Result := SkinInfo.BreadcrumbEditButton.ContentOffset.Rect;
    if SkinInfo.BreadcrumbEditButtonMergeBorders then
    begin
      if AIsFirst and (BreadcrumbEditButtonAreaSeparatorSize > 0) then
        Result.Left := 1;
      Result.Right := 1;
    end;
  end
  else
    Result := inherited BreadcrumbEditButtonContentOffsets(AIsFirst, AIsLast);
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditDropDownButtonOriginalWidth: Integer;
begin
  if SkinInfo.BreadcrumbEditDropDownButton <> nil then
    Result := SkinInfo.BreadcrumbEditDropDownButton.MinSize.Width
  else
    Result := inherited BreadcrumbEditDropDownButtonOriginalWidth;
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditIsFadingSupports: Boolean;
begin
  Result := True;
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditNodeTextColor(
  AState: TdxBreadcrumbEditButtonState): TColor;
const
  TextColorMap: array[TdxBreadcrumbEditButtonState] of string = ('',
    sdxTextColorSelected, sdxTextColorHot, sdxTextColorPressed, sdxTextColorDisabled
  );
var
  AProperty: TdxSkinProperty;
begin
  if SkinInfo.BreadcrumbEditNodeButton <> nil then
  begin
    Result := clDefault;
    if SkinInfo.BreadcrumbEditNodeButton.GetPropertyByName(TextColorMap[AState], AProperty) then
    begin
      if AProperty is TdxSkinColor then
        Result := TdxSkinColor(AProperty).Value;
    end;
    if Result = clDefault then
      Result := SkinInfo.BreadcrumbEditNodeButton.TextColor;
  end
  else
    Result := inherited BreadcrumbEditNodeTextColor(AState)
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditNodeTextOffsets: TRect;
begin
  if SkinInfo.BreadcrumbEditNodeButton <> nil then
    Result := SkinInfo.BreadcrumbEditNodeButton.ContentOffset.Rect
  else
    Result := inherited BreadcrumbEditNodeTextOffsets;
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditProgressChunkPadding: TRect;
begin
  if SkinInfo.BreadcrumbEditProgressChunkPadding <> nil then
    Result := SkinInfo.BreadcrumbEditProgressChunkPadding.Value.Rect
  else
    Result := inherited BreadcrumbEditProgressChunkPadding;
end;

function TdxSkinLookAndFeelPainter.BreadcrumbEditProgressChunkOverlaySize: TSize;
begin
  if SkinInfo.BreadcrumbEditProgressChunkOverlay <> nil then
    Result := SkinInfo.BreadcrumbEditProgressChunkOverlay.MinSize.Size
  else
    Result := inherited BreadcrumbEditProgressChunkOverlaySize;
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditBorders(ACanvas: TcxCanvas;
  const ARect: TRect; ABorders: TcxBorders; AState: TdxBreadcrumbEditState);
var
  AColor: TColor;
begin
  AColor := BreadcrumbEditBordersColor(AState);
  if cxColorIsValid(AColor) then
    ACanvas.FrameRect(ARect, AColor, 1, ABorders)
  else
    inherited DrawBreadcrumbEditBorders(ACanvas, ARect, ABorders, AState);
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditButton(
  ACanvas: TcxCanvas; const ARect: TRect; AState: TdxBreadcrumbEditButtonState;
  AIsFirst, AIsLast: Boolean);

  procedure DoDrawBreadcrumbEditButton(AElement: TdxSkinElement; const R: TRect);
  begin
    AElement.Draw(ACanvas.Handle, R, 0, BreadcrumbButtonStateToElementState[AState]);
  end;

var
  AElement: TdxSkinElement;
  R: TRect;
begin
  AElement := SkinInfo.BreadcrumbEditButton;
  if AElement = nil then
    inherited DrawBreadcrumbEditButton(ACanvas, ARect, AState, AIsFirst, AIsLast)
  else
    if SkinInfo.BreadcrumbEditButtonMergeBorders then
    begin
      ACanvas.SaveClipRegion;
      try
        ACanvas.IntersectClipRect(ARect);
        R := ARect;
        Inc(R.Right, AElement.ContentOffset.Right - 1);
        if AIsFirst and (BreadcrumbEditButtonAreaSeparatorSize > 0) then
          Dec(R.Left, AElement.ContentOffset.Left - 1);
        DoDrawBreadcrumbEditButton(AElement, R);
      finally
        ACanvas.RestoreClipRegion;
      end;
    end
    else
      DoDrawBreadcrumbEditButton(AElement, ARect);
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditButtonAreaSeparator(
  ACanvas: TcxCanvas; const ARect: TRect; AState: TdxBreadcrumbEditState);
begin
  if SkinInfo.BreadcrumbEditButtonsAreaSeparator <> nil then
    SkinInfo.BreadcrumbEditButtonsAreaSeparator.Draw(ACanvas.Handle, ARect)
  else
    inherited DrawBreadcrumbEditButtonAreaSeparator(ACanvas, ARect, AState);
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditDropDownButton(
  ACanvas: TcxCanvas; const ARect: TRect; AState: TdxBreadcrumbEditButtonState;
  AIsInEditor: Boolean);
begin
  if SkinInfo.BreadcrumbEditDropDownButton = nil then
    inherited DrawBreadcrumbEditDropDownButton(ACanvas, ARect, AState, AIsInEditor)
  else
    SkinInfo.BreadcrumbEditDropDownButton.Draw(
      ACanvas.Handle, ARect, 0, BreadcrumbButtonStateToElementState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditDropDownButtonGlyph(
  ACanvas: TcxCanvas; const ARect: TRect; AState: TdxBreadcrumbEditButtonState;
  AIsInEditor: Boolean);
begin
  if SkinInfo.BreadcrumbEditDropDownButton = nil then
    inherited DrawBreadcrumbEditDropDownButtonGlyph(ACanvas, ARect, AState, AIsInEditor);
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditNode(ACanvas: TcxCanvas;
  const R: TRect; AState: TdxBreadcrumbEditButtonState; AHasDelimiter: Boolean);
var
  AElement: TdxSkinElement;
begin
  if AHasDelimiter then
    AElement := SkinInfo.BreadcrumbEditNodeSplitButtonLeft
  else
    AElement := SkinInfo.BreadcrumbEditNodeButton;

  if AElement = nil then
    inherited DrawBreadcrumbEditNode(ACanvas, R, AState, AHasDelimiter)
  else
    AElement.Draw(ACanvas.Handle, R, 0, BreadcrumbButtonStateToElementState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditNodeDelimiter(
  ACanvas: TcxCanvas; const R: TRect; AState: TdxBreadcrumbEditButtonState);
begin
  if SkinInfo.BreadcrumbEditNodeSplitButtonRight = nil then
    inherited DrawBreadcrumbEditNodeDelimiter(ACanvas, R, AState)
  else
    SkinInfo.BreadcrumbEditNodeSplitButtonRight.Draw(
      ACanvas.Handle, R, 0, BreadcrumbButtonStateToElementState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditNodeMoreButtonGlyph(
  ACanvas: TcxCanvas; const R: TRect; AState: TdxBreadcrumbEditButtonState);
begin
  DrawCollapseArrow(ACanvas, R, BreadcrumbEditNodeTextColor(AState), cxGetValueCurrentDPI(2));
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditNodeDelimiterGlyph(
  ACanvas: TcxCanvas; const R: TRect; AState: TdxBreadcrumbEditButtonState);
const
  ArrowDirections: array[Boolean] of TcxArrowDirection = (adRight, adDown);
begin
  DrawArrow(ACanvas, cxRectInflate(R, -1, -1),
    ArrowDirections[AState = dxbcbsPressed],
    BreadcrumbEditNodeTextColor(AState));
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditProgressChunk(
  ACanvas: TcxCanvas; const R: TRect);
begin
  if SkinInfo.BreadcrumbEditProgressChunk <> nil then
    SkinInfo.BreadcrumbEditProgressChunk.Draw(ACanvas.Handle, R)
  else
    inherited DrawBreadcrumbEditProgressChunk(ACanvas, R);
end;

procedure TdxSkinLookAndFeelPainter.DrawBreadcrumbEditProgressChunkOverlay(
  ACanvas: TcxCanvas; const R: TRect);
begin
  if SkinInfo.BreadcrumbEditProgressChunkOverlay <> nil then
    SkinInfo.BreadcrumbEditProgressChunkOverlay.Draw(ACanvas.Handle, R)
  else
    inherited DrawBreadcrumbEditProgressChunkOverlay(ACanvas, R);
end;

function TdxSkinLookAndFeelPainter.DropDownListBoxBordersSize: Integer;
begin
  Result := 2;
end;

function TdxSkinLookAndFeelPainter.DropDownListBoxItemImageOffsets: TRect;
begin
  Result := DropDownListBoxItemTextOffsets;
  if SkinInfo.PopupMenuSideStrip <> nil then
  begin
    Result.Left := Max(Result.Left, SkinInfo.PopupMenuSideStrip.ContentOffset.Left);
    Result.Right := Max(Result.Right, SkinInfo.PopupMenuSideStrip.ContentOffset.Right);
  end;
end;

function TdxSkinLookAndFeelPainter.DropDownListBoxItemTextColor(ASelected: Boolean): TColor;
const
  StatesMap: array[Boolean] of TcxButtonState = (cxbsNormal, cxbsHot);
begin
  if SkinInfo.PopupMenu = nil then
    Result := inherited DropDownListBoxItemTextColor(ASelected)
  else
    Result := SkinInfo.PopupMenu.GetTextColor(StatesMap[ASelected]);
end;

function TdxSkinLookAndFeelPainter.DropDownListBoxItemTextOffsets: TRect;
begin
  Result := inherited DropDownListBoxItemTextOffsets;
  if SkinInfo.PopupMenuLinkSelected <> nil then
  begin
    Result.Top := Max(Result.Top, SkinInfo.PopupMenuLinkSelected.ContentOffset.Top);
    Result.Bottom := Max(Result.Bottom, SkinInfo.PopupMenuLinkSelected.ContentOffset.Bottom);
  end;
end;

function TdxSkinLookAndFeelPainter.DropDownListBoxSeparatorSize: Integer;
begin
  if SkinInfo.PopupMenuSeparator = nil then
    Result := inherited DropDownListBoxSeparatorSize
  else
    Result := SkinInfo.PopupMenuSeparator.MinSize.Height;
end;

procedure TdxSkinLookAndFeelPainter.DrawDropDownListBoxBackground(
  ACanvas: TcxCanvas; const ARect: TRect; AHasBorders: Boolean);
begin
  if SkinInfo.PopupMenu = nil then
    inherited DrawDropDownListBoxBackground(ACanvas, ARect, AHasBorders)
  else
    if AHasBorders then
      SkinInfo.PopupMenu.Draw(ACanvas.Handle, ARect)
    else
    begin
      ACanvas.SaveClipRegion;
      try
        ACanvas.IntersectClipRect(ARect);
        SkinInfo.PopupMenu.Draw(ACanvas.Handle,
          cxRectInflate(ARect, GetSkinElementBordersWidth(SkinInfo.PopupMenu)));
      finally
        ACanvas.RestoreClipRegion;
      end;
    end;
end;

procedure TdxSkinLookAndFeelPainter.DrawDropDownListBoxGutterBackground(
  ACanvas: TcxCanvas; const ARect: TRect);
begin
  if SkinInfo.PopupMenuSideStrip = nil then
    inherited DrawDropDownListBoxGutterBackground(ACanvas, ARect)
  else
    SkinInfo.PopupMenuSideStrip.Draw(ACanvas.Handle, ARect);
end;

procedure TdxSkinLookAndFeelPainter.DrawDropDownListBoxSelection(
  ACanvas: TcxCanvas; const ARect, AGutterRect: TRect);
begin
  if SkinInfo.PopupMenuLinkSelected = nil then
    inherited DrawDropDownListBoxSelection(ACanvas, ARect, AGutterRect)
  else
    SkinInfo.PopupMenuLinkSelected.Draw(ACanvas.Handle, ARect);
end;

procedure TdxSkinLookAndFeelPainter.DrawDropDownListBoxSeparator(
  ACanvas: TcxCanvas; const ARect, AGutterRect: TRect);
begin
  if SkinInfo.PopupMenuSeparator = nil then
    inherited DrawDropDownListBoxSeparator(ACanvas, ARect, AGutterRect)
  else
    SkinInfo.PopupMenuSeparator.Draw(ACanvas.Handle,
      cxRect(AGutterRect.Right + cxTextOffset, ARect.Top, ARect.Right, ARect.Bottom));
end;

function TdxSkinLookAndFeelPainter.AlertWindowButtonContentOffsets(
  AKind: TdxAlertWindowButtonKind): TRect;
var
  AElement: TdxSkinElement;
begin
  AElement := AlertWindowButtonElement(AKind);
  if AElement <> nil then
    Result := AElement.ContentOffset.Rect
  else
    Result := inherited AlertWindowButtonContentOffsets(AKind);
end;

function TdxSkinLookAndFeelPainter.AlertWindowButtonElement(
  AKind: TdxAlertWindowButtonKind): TdxSkinElement;
begin
  if AKind in [awbkPrevious, awbkNext] then
    Result := SkinInfo.AlertWindowNavigationPanelButton
  else
    Result := SkinInfo.AlertWindowButton;
end;

function TdxSkinLookAndFeelPainter.AlertWindowContentOffsets: TRect;
begin
  if SkinInfo.AlertWindow <> nil then
    Result := SkinInfo.AlertWindow.ContentOffset.Rect
  else
    Result := inherited AlertWindowContentOffsets;
end;

function TdxSkinLookAndFeelPainter.AlertWindowCornerRadius: Integer;
begin
  if SkinInfo.AlertWindow = nil then
    Result := inherited AlertWindowCornerRadius
  else
    if TdxSkinElementHelper.IsAlternateImageSetUsed(SkinInfo.AlertWindow, 0, esNormal) then
      Result := 0
    else
      Result := SkinInfo.AlertWindowCornerRadius;
end;

function TdxSkinLookAndFeelPainter.AlertWindowNavigationPanelTextColor: TColor;
begin
  if SkinInfo.AlertWindowNavigationPanel <> nil  then
    Result := SkinInfo.AlertWindowNavigationPanel.TextColor
  else
    Result := clDefault;

  if Result = clDefault then
    Result := inherited AlertWindowNavigationPanelTextColor;
end;

function TdxSkinLookAndFeelPainter.AlertWindowTextColor: TColor;
begin
  if SkinInfo.AlertWindow <> nil then
  begin
    Result := SkinInfo.AlertWindow.TextColor;
    if Result = clDefault then
      Result := DefaultContentTextColor;
  end
  else
    Result := inherited AlertWindowTextColor;
end;

procedure TdxSkinLookAndFeelPainter.DrawAlertWindowBackground(
  ACanvas: TcxCanvas; const ABounds: TRect);
var
  ACaptionElement: TdxSkinElement;
  ACaptionSize: Integer;
  AWindowElement: TdxSkinElement;
begin
  AWindowElement := SkinInfo.AlertWindow;
  ACaptionElement := SkinInfo.AlertWindowCaption;
  if (AWindowElement <> nil) and (ACaptionElement <> nil) then
  begin
    AWindowElement.Draw(ACanvas.Handle, ABounds);
    ACaptionSize := ACaptionElement.MinSize.Height;
    if ACaptionSize = 0 then
      ACaptionSize := cxMarginsHeight(ACaptionElement.ContentOffset.Rect) + ACaptionElement.Glyph.Size.cy;
    ACaptionElement.Draw(ACanvas.Handle, cxRectSetHeight(ABounds, ACaptionSize));
  end
  else
    inherited DrawAlertWindowBackground(ACanvas, ABounds);
end;

procedure TdxSkinLookAndFeelPainter.DrawAlertWindowButton(ACanvas: TcxCanvas;
  const ABounds: TRect; AState: TcxButtonState; AKind: TdxAlertWindowButtonKind;
  ADown: Boolean);
const
  GlyphsMap: array[TdxAlertWindowButtonKind] of Integer = (0, 1, 3, 4, 5, -1);
  StatesMap: array[Boolean, TcxButtonState] of TdxSkinElementState = (
    (esNormal, esNormal, esHot, esPressed, esDisabled),
    (esChecked, esChecked, esHotCheck, esCheckPressed, esDisabled)
  );

  procedure DoDrawGlyph(AGlyphIndex: Integer);
  begin
    if AGlyphIndex >= 0 then
    begin
      if SkinInfo.AlertWindowButtonGlyphs <> nil then
        SkinInfo.AlertWindowButtonGlyphs.Draw(
          ACanvas.Handle, ABounds, AGlyphIndex, StatesMap[False, AState]);
    end;
  end;

var
  AElement: TdxSkinElement;
  AElementState: TdxSkinElementState;
begin
  AElement := AlertWindowButtonElement(AKind);
  if AElement = nil then
    inherited DrawAlertWindowButton(ACanvas, ABounds, AState, AKind, ADown)
  else
  begin
    AElementState := StatesMap[ADown, AState];
    if AElementState in AElement.Image.States then
      AElement.Draw(ACanvas.Handle, ABounds, 0, AElementState);
    case AKind of
      awbkPin:
        DoDrawGlyph(1 + Ord(ADown));
      else
        DoDrawGlyph(GlyphsMap[AKind]);
    end;
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawAlertWindowNavigationPanel(ACanvas: TcxCanvas; const ABounds: TRect);
begin
  if SkinInfo.AlertWindowNavigationPanel = nil then
    inherited DrawAlertWindowNavigationPanel(ACanvas, ABounds)
  else
    SkinInfo.AlertWindowNavigationPanel.Draw(ACanvas.Handle, ABounds);
end;

function TdxSkinLookAndFeelPainter.GetBackButtonSize: TSize;
begin
  if SkinInfo.BackButton = nil then
    Result := inherited GetBackButtonSize
  else
    Result := SkinInfo.BackButton.MinSize.Size;
end;

function TdxSkinLookAndFeelPainter.GetBevelMinimalShapeSize(AShape: TdxBevelShape): TSize;
var
  AShapeSize: Integer;
  AColor1, AColor2: TColor;
begin
  GetBevelShapeColors(AColor1, AColor2);
  AShapeSize := Integer(cxColorIsValid(AColor1)) + Integer(cxColorIsValid(AColor2));
  Result := cxSize(AShapeSize, AShapeSize);
end;

procedure TdxSkinLookAndFeelPainter.GetBevelShapeColors(out AColor1, AColor2: TColor);
begin
  inherited GetBevelShapeColors(AColor1, AColor2);
  if (SkinInfo.BevelShapeColor1 <> nil) and (SkinInfo.BevelShapeColor1.Value <> clDefault) then
    AColor1 := SkinInfo.BevelShapeColor1.Value;
  if (SkinInfo.BevelShapeColor2 <> nil) and (SkinInfo.BevelShapeColor2.Value <> clDefault) then
    AColor2 := SkinInfo.BevelShapeColor2.Value;
end;

procedure TdxSkinLookAndFeelPainter.DrawCheckButton(ACanvas: TcxCanvas;
  R: TRect; AState: TcxButtonState; ACheckState: TcxCheckBoxState);
const
  ImageIndexMap: array[TcxCheckBoxState] of Integer = (0, 1, 2);
begin
  with SkinInfo do
    if CheckboxElement = nil then
      inherited DrawCheckButton(ACanvas, R, AState, ACheckState)
    else
      CheckboxElement.Draw(ACanvas.Handle, R, ImageIndexMap[ACheckState],
        ButtonStateToSkinState[AState]);
end;

function TdxSkinLookAndFeelPainter.ClockSize: TSize;
var
  AElement: TdxSkinElement;
begin
  AElement := SkinInfo.ClockElements[False];
  if AElement <> nil then
  begin
    Result := AElement.Size;
    Result.cx := Max(Result.cx, AElement.MinSize.Width);
    Result.cy := Max(Result.cy, AElement.MinSize.Height);
  end
  else
    Result := inherited ClockSize;
end;

procedure TdxSkinLookAndFeelPainter.DrawClock(ACanvas: TcxCanvas;
  const ARect: TRect; ADateTime: TDateTime; ABackgroundColor: TColor);

  procedure DrawHand(ACanvas: TCanvas; ACenter: TPoint;
    AAngle, L1X, L1Y, L2X, L2Y, L3: Extended; AHandColor: TColor);
  begin
    with ACanvas do
    begin
      Brush.Color := AHandColor;
      BeginPath(Handle);
      Pixels[Round(ACenter.X + L1X * cos(AAngle)),
        Round(ACenter.Y + L1Y * sin(AAngle))] := clTeal;
      Pen.Color := clTeal;
      MoveTo(Round(ACenter.X + L1X * cos(AAngle)),
        Round(ACenter.Y + L1Y * sin(AAngle)));
      LineTo(Round(ACenter.X + L3 / 2 * cos(AAngle + Pi / 2)),
        Round(ACenter.Y + L3 / 2 * sin(AAngle + Pi / 2)));
      LineTo(Round(ACenter.X + L2X * cos(AAngle + Pi)),
        Round(ACenter.Y + L2Y * sin(AAngle + Pi)));
      LineTo(Round(ACenter.X + L3 / 2 * cos(AAngle + Pi * 3 / 2)),
        Round(ACenter.Y + L3 / 2 * sin(AAngle + Pi * 3 / 2)));
      LineTo(Round(ACenter.X + L1X * cos(AAngle)),
        Round(ACenter.Y + L1Y * sin(AAngle)));
      EndPath(Handle);
      FillPath(Handle);
    end;
  end;

  procedure DrawHands(ACanvas: TCanvas; AHandColor: TColor);
  var
    AAngle: Extended;
    ACenter: TPoint;
    AHandRadiusX, AHandRadiusY: Extended;
    AHour, AMin, AMSec, ASec: Word;
  begin
    DecodeTime(ADateTime, AHour, AMin, ASec, AMSec);
    ACenter.X := (ARect.Right + ARect.Left) div 2;
    ACenter.Y := (ARect.Bottom + ARect.Top) div 2;
    AHandRadiusX := (ARect.Right - ARect.Left) / 2 - 2;
    AHandRadiusY := (ARect.Bottom - ARect.Top) / 2 - 2;
    with ACanvas do
    begin
      AAngle := Pi * 2 * ((AHour mod 12) * 60 * 60 + AMin * 60 + ASec - 3 * 60 * 60) / 12 / 60 / 60;
      DrawHand(ACanvas, ACenter, AAngle, AHandRadiusX * 0.75, AHandRadiusY * 0.75,
        AHandRadiusX * 0.15, AHandRadiusY * 0.15, 9, AHandColor);

      AAngle := Pi * 2 * (AMin * 60 + ASec - 15 * 60) / 60 / 60;
      DrawHand(ACanvas, ACenter, AAngle, AHandRadiusX * 0.85, AHandRadiusY * 0.85,
        AHandRadiusX * 0.2, AHandRadiusY * 0.2, 7, AHandColor);

      Pen.Color := AHandColor;
      MoveTo(ACenter.X, ACenter.Y);
      AAngle := Pi * 2 * (ASec - 15) / 60;
      LineTo(Round(ACenter.X + AHandRadiusX * 0.9 * cos(AAngle)),
        Round(ACenter.Y + AHandRadiusY * 0.9 * sin(AAngle)));
    end;
  end;

var
  ABitmap: TcxBitmap;
begin
  with SkinInfo do
    if (ClockElements[False] = nil) or (ClockElements[True] = nil) then
      inherited DrawClock(ACanvas, ARect, ADateTime, ABackgroundColor)
    else
    begin
      ABitmap := TcxBitmap.CreateSize(ARect);
      try
        if ABackgroundColor = clNone then
          cxBitBlt(ABitmap.cxCanvas.Handle, ACanvas.Handle, ARect, cxNullPoint, SRCCOPY)
        else
          ABitmap.cxCanvas.FillRect(ARect, ABackgroundColor);
        ClockElements[False].Draw(ABitmap.Canvas.Handle, ARect);
        DrawHands(ABitmap.Canvas, ClockElements[False].TextColor);
        ClockElements[True].Draw(ABitmap.Canvas.Handle, ARect);
        cxBitBlt(ACanvas.Handle, ABitmap.cxCanvas.Handle, ARect, cxNullPoint, SRCCOPY)
      finally
        ABitmap.Free;
      end;
    end;
end;

procedure TdxSkinLookAndFeelPainter.DrawEditorButton(
  ACanvas: TcxCanvas; const ARect: TRect; AButtonKind: TcxEditBtnKind;
  AState: TcxButtonState; APosition: TcxEditBtnPosition = cxbpRight);
var
  AElement: TdxSkinElement;
  R: TRect;
begin
  AElement := SkinInfo.EditButtonElements[AButtonKind = cxbkCloseBtn];
  if AElement = nil then
    inherited DrawEditorButton(ACanvas, ARect, AButtonKind, AState, APosition)
  else
  begin
    ACanvas.SaveClipRegion;
    try
      R := ARect;
      ACanvas.IntersectClipRect(ARect);
      EditButtonAdjustRect(R, APosition);
      AElement.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
   finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawEditorButtonGlyph(
  ACanvas: TcxCanvas; const ARect: TRect; AButtonKind: TcxEditBtnKind;
  AState: TcxButtonState; APosition: TcxEditBtnPosition = cxbpRight);

  procedure DrawEllipsis(R: TRect; ASize: Integer);
  var
    AColor: TColor;
  begin
    R := cxRectCenter(R, 3 * ASize + 4, ASize);
    AColor := SkinInfo.EditButtonElements[False].TextColor;
    ACanvas.FillRect(Rect(R.Left, R.Top, R.Left + ASize, R.Top + ASize), AColor);
    ACanvas.FillRect(Rect(R.Left + ASize + 2, R.Top, R.Left + ASize * 2 + 2, R.Top + ASize), AColor);
    ACanvas.FillRect(Rect(R.Left + ASize * 2 + 4, R.Top, R.Left + ASize * 3 + 4, R.Top + ASize), AColor);
  end;

  function GetGlyphRect(const R: TRect; AElement: TdxSkinElement): TRect;
  begin
    Result := cxRectContent(R, AElement.ContentOffset.Rect);
    if SkinInfo.EditButtonMergeBorders then
    begin
      if APosition = cxbpLeft then
        Dec(Result.Left, AElement.ContentOffset.Left - 1)
      else
        Inc(Result.Right, AElement.ContentOffset.Right - 1);
    end;
  end;

const
  EllipseSizeMap: array[Boolean] of Integer = (1, 2);
var
  AElement: TdxSkinElement;
  R: TRect;
begin
  AElement := SkinInfo.EditButtonElements[AButtonKind = cxbkCloseBtn];
  if AElement = nil then
    inherited DrawEditorButton(ACanvas, ARect, AButtonKind, AState, APosition)
  else
  begin
    ACanvas.SaveClipRegion;
    try
      R := ARect;
      ACanvas.IntersectClipRect(ARect);
      EditButtonAdjustRect(R, APosition);
      R := GetGlyphRect(R, AElement);
      if AButtonKind = cxbkEllipsisBtn then
        DrawEllipsis(R, EllipseSizeMap[cxRectWidth(R) >= 12])
      else
        if SkinInfo.EditButtonGlyphs[AButtonKind] <> nil then
          SkinInfo.EditButtonGlyphs[AButtonKind].Glyph.Draw(ACanvas.Handle, R);
   finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

function TdxSkinLookAndFeelPainter.EditButtonTextOffset: Integer;
begin
  Result := 1;
end;

procedure TdxSkinLookAndFeelPainter.EditButtonAdjustRect(var R: TRect; APosition: TcxEditBtnPosition);
begin
  if SkinInfo.EditButtonMergeBorders then
  begin
    InflateRect(R, 0, 1);
    if APosition = cxbpLeft then
      Dec(R.Left)
    else
      Inc(R.Right);
  end;
end;

function TdxSkinLookAndFeelPainter.EditButtonSize: TSize;
begin
  if SkinInfo.EditButtonElements[False] = nil then
    Result := inherited EditButtonSize
  else
    Result := SkinInfo.EditButtonElements[False].Size;
end;

function TdxSkinLookAndFeelPainter.EditButtonTextColor: TColor;
begin
  with SkinInfo do
    if EditButtonElements[False] = nil then
      Result := inherited EditButtonTextColor
    else
      Result := EditButtonElements[False].TextColor;
end;

function TdxSkinLookAndFeelPainter.GetContainerBorderColor(
  AIsHighlightBorder: Boolean): TColor;
var
  ASkinColor: TdxSkinColor;
begin
  with SkinInfo do
  begin
    if AIsHighlightBorder then
      ASkinColor := ContainerHighlightBorderColor
    else
      ASkinColor := ContainerBorderColor;
    if ASkinColor = nil then
      Result := inherited GetContainerBorderColor(AIsHighlightBorder)
    else
      Result := ASkinColor.Value;
  end;
end;

function TdxSkinLookAndFeelPainter.GetContainerBorderWidth(ABorderStyle: TcxContainerBorderStyle): Integer;
const
  BordersWidthMap: array [Boolean] of Integer = (1, cxContainerMaxBorderWidth);
begin
  if ABorderStyle = cbsNone then
    Result := inherited GetContainerBorderWidth(ABorderStyle)
  else
    Result := BordersWidthMap[ABorderStyle = cbsThick];
end;

procedure TdxSkinLookAndFeelPainter.DrawNavigatorBorder(
  ACanvas: TcxCanvas; R: TRect; ASelected: Boolean);
begin
  DrawBorder(ACanvas, R);
end;

procedure TdxSkinLookAndFeelPainter.DrawNavigatorButton(
  ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState; ABackgroundColor: TColor);
begin
  with SkinInfo do
    if NavigatorButton = nil then
      inherited DrawNavigatorButton(ACanvas, R, AState, ABackgroundColor)
    else
      NavigatorButton.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawNavigatorButtonGlyph(
  ACanvas: TcxCanvas; AImageList: TCustomImageList; AImageIndex: TcxImageIndex;
  const AGlyphRect: TRect; AEnabled, AUserGlyphs: Boolean);
var
  ABitmap: TcxAlphaBitmap;
  AElement: TdxSkinElement;
begin
  with SkinInfo do
    if (NavigatorGlyphs = nil) or (NavigatorGlyphsVert = nil) or AUserGlyphs then
      inherited DrawNavigatorButtonGlyph(ACanvas, AImageList, AImageIndex,
        AGlyphRect, AEnabled, AUserGlyphs)
    else
      if not IsRectEmpty(AGlyphRect) then
      begin
        AElement := NavigatorGlyphs;
        if NavigatorGlyphs.ImageCount <= AImageIndex then
        begin
          AElement := NavigatorGlyphsVert;
          Dec(AImageIndex, NavigatorGlyphs.ImageCount);
        end;

        if AEnabled then
          AElement.Draw(ACanvas.Handle, AGlyphRect, AImageIndex)
        else
        begin
          ABitmap := TcxAlphaBitmap.CreateSize(AGlyphRect, True);
          try
            AElement.Draw(ABitmap.Canvas.Handle, ABitmap.ClientRect, AImageIndex);
            dxSkinElementMakeDisable(ABitmap);
            cxAlphaBlend(ACanvas.Handle, ABitmap, AGlyphRect, ABitmap.ClientRect);
          finally
            ABitmap.Free;
          end;
        end;
      end;
end;

function TdxSkinLookAndFeelPainter.NavigatorBorderOverlap: Boolean;
begin
  Result := False;
end;

function TdxSkinLookAndFeelPainter.NavigatorButtonGlyphPadding: TRect;
begin
  with SkinInfo do
    if NavigatorButton <> nil then
      Result := NavigatorButton.ContentOffset.Rect
    else
      Result := inherited NavigatorButtonGlyphPadding;
end;

function TdxSkinLookAndFeelPainter.NavigatorButtonGlyphSize: TSize;
begin
  with SkinInfo do
    if NavigatorGlyphs = nil then
      Result := inherited NavigatorButtonGlyphSize
    else
      Result := NavigatorGlyphs.Size;
end;

function TdxSkinLookAndFeelPainter.NavigatorButtonPressedGlyphOffset: TPoint;
begin
  Result := cxNullPoint;
end;

procedure TdxSkinLookAndFeelPainter.DrawProgressBarBorder(ACanvas: TcxCanvas;
  ARect: TRect; AVertical: Boolean);
begin
  with SkinInfo do
    if ProgressBarElements[False, AVertical] <> nil then
      ProgressBarElements[False, AVertical].Draw(ACanvas.Handle, ARect)
    else
      inherited DrawProgressBarBorder(ACanvas, ARect, AVertical);
end;

procedure TdxSkinLookAndFeelPainter.DrawProgressBarChunk(
  ACanvas: TcxCanvas; ARect: TRect; AVertical: Boolean);
begin
  with SkinInfo do
    if ProgressBarElements[True, AVertical] <> nil then
      ProgressBarElements[True, AVertical].Draw(ACanvas.Handle, ARect)
    else
      inherited DrawProgressBarChunk(ACanvas, ARect, AVertical);
end;

function TdxSkinLookAndFeelPainter.ProgressBarBorderSize(AVertical: Boolean): TRect;
begin
  with SkinInfo do
    if ProgressBarElements[False, AVertical] <> nil then
      Result := ProgressBarElements[False, AVertical].ContentOffset.Rect
    else
      Result := inherited ProgressBarBorderSize(AVertical);
end;

function TdxSkinLookAndFeelPainter.ProgressBarTextColorEx(AIsFilledArea: Boolean): TColor;
begin
  with SkinInfo do
    if IsColorPropertyAssigned(ProgressBarTextColors[AIsFilledArea]) then
      Result := ProgressBarTextColors[AIsFilledArea].Value
    else
      Result := inherited ProgressBarTextColorEx(AIsFilledArea);
end;

function TdxSkinLookAndFeelPainter.GroupBoxBorderSize(
  ACaption: Boolean; ACaptionPosition: TcxGroupBoxCaptionPosition): TRect;
var
  AGroupBoxInfo: TdxSkinElement;
begin
  with SkinInfo do
    if ACaption then
      AGroupBoxInfo := GroupBoxCaptionElements[ACaptionPosition]
    else
      AGroupBoxInfo := GroupBoxElements[ACaptionPosition];

  if AGroupBoxInfo = nil then
    Result := inherited GroupBoxBorderSize(ACaption, ACaptionPosition)
  else
    Result := AGroupBoxInfo.ContentOffset.Rect;
end;

procedure TdxSkinLookAndFeelPainter.DrawGroupBoxFrame(ACanvas: TcxCanvas;
  R: TRect; AEnabled: Boolean; ACaptionPosition: TcxGroupBoxCaptionPosition;
  ABorders: TcxBorders = cxBordersAll); 
begin
  DrawGroupBoxContent(ACanvas, R, ACaptionPosition, ABorders);
end;

function TdxSkinLookAndFeelPainter.GroupBoxCaptionTailSize(
  ACaptionPosition: TcxGroupBoxCaptionPosition): Integer;
begin
  if SkinInfo.GroupBoxCaptionTailSizes[ACaptionPosition] = nil then
    Result := inherited GroupBoxCaptionTailSize(ACaptionPosition)
  else
    Result := SkinInfo.GroupBoxCaptionTailSizes[ACaptionPosition].Value;
end;

function TdxSkinLookAndFeelPainter.GroupBoxTextColor(
  AEnabled: Boolean; ACaptionPosition: TcxGroupBoxCaptionPosition): TColor;
var
  AGroupBoxCaption: TdxSkinElement;
begin
  if ACaptionPosition = cxgpCenter then
    Result := PanelTextColor
  else
  begin
    AGroupBoxCaption := SkinInfo.GroupBoxCaptionElements[ACaptionPosition];
    if AGroupBoxCaption = nil then
      Result := inherited GroupBoxTextColor(AEnabled, ACaptionPosition)
    else
      Result := AGroupBoxCaption.TextColor;
  end;
end;

function TdxSkinLookAndFeelPainter.PanelTextColor: TColor;
begin
  with SkinInfo do
    if GroupBoxClient = nil then
      Result := inherited PanelTextColor
    else
      Result := GroupBoxClient.TextColor;
end;

function TdxSkinLookAndFeelPainter.IsGroupBoxCaptionTextDrawnOverBorder(ACaptionPosition: TcxGroupBoxCaptionPosition): Boolean;
begin
  if SkinInfo.GroupBoxCaptionElements[ACaptionPosition] <> nil then
    Result := cxColorIsValid(SkinInfo.GroupBoxCaptionElements[ACaptionPosition].Color)
  else
    Result := inherited IsGroupBoxCaptionTextDrawnOverBorder(ACaptionPosition);
end;

function TdxSkinLookAndFeelPainter.IsGroupBoxTransparent(
  AIsCaption: Boolean; ACaptionPosition: TcxGroupBoxCaptionPosition): Boolean;
var
  AGroupBoxInfo: TdxSkinElement;
begin
  with SkinInfo do
    if AIsCaption then
      AGroupBoxInfo := GroupBoxCaptionElements[ACaptionPosition]
    else
      AGroupBoxInfo := GroupBoxElements[ACaptionPosition];

  if AGroupBoxInfo = nil then
    Result := inherited IsGroupBoxTransparent(AIsCaption, ACaptionPosition)
  else
    Result := AGroupBoxInfo.IsAlphaUsed;
end;

procedure TdxSkinLookAndFeelPainter.DrawGroupBoxCaption(ACanvas: TcxCanvas;
  const ACaptionRect, ATextRect: TRect; ACaptionPosition: TcxGroupBoxCaptionPosition);
begin
  if SkinInfo.GroupBoxCaptionElements[ACaptionPosition] = nil then
    inherited DrawGroupBoxCaption(ACanvas, ACaptionRect, ATextRect, ACaptionPosition)
  else
    DrawGroupCaption(ACanvas, ACaptionRect, ATextRect,
      SkinInfo.GroupBoxCaptionElements[ACaptionPosition],
      SkinInfo.GroupBoxCaptionTextPadding[ACaptionPosition], esNormal);
end;

procedure TdxSkinLookAndFeelPainter.DrawGroupBoxContent(ACanvas: TcxCanvas;
  ABorderRect: TRect; ACaptionPosition: TcxGroupBoxCaptionPosition;
  ABorders: TcxBorders = cxBordersAll);
var
  ARect: TRect;
begin
  with SkinInfo do
    if (GroupBoxElements[ACaptionPosition] = nil) or (GroupBoxClient = nil) then
      inherited DrawGroupBoxContent(ACanvas, ABorderRect, ACaptionPosition)
    else
      if not IsRectEmpty(ABorderRect) then
      begin
        ARect := ABorderRect;
        ACanvas.SaveClipRegion;
        try
          ACanvas.IntersectClipRect(ABorderRect);
          with GetSkinElementBordersWidth(GroupBoxElements[ACaptionPosition]) do
          begin
            if bLeft in ABorders then
              Inc(ARect.Left, Left);
            if bTop in ABorders then
              Inc(ARect.Top, Top);
            if bRight in ABorders then
              Dec(ARect.Right, Right);
            if bBottom in ABorders then
              Dec(ARect.Bottom, Bottom);
          end;
          GroupBoxClient.Draw(ACanvas.Handle, ARect);
          ACanvas.ExcludeClipRect(ARect);
          GroupBoxElements[ACaptionPosition].Draw(ACanvas.Handle, ABorderRect);
        finally
          ACanvas.RestoreClipRegion;
        end;
      end;
end;

procedure TdxSkinLookAndFeelPainter.DrawGroupBoxExpandButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState; AExpanded: Boolean;
  ARotationAngle: TcxRotationAngle = ra0);

  procedure DoDrawGroupBoxExpandButton(ACanvas: TcxCanvas; const R: TRect);
  begin
    with SkinInfo do
      if GroupExpandButton = nil then
        inherited DrawGroupBoxExpandButton(ACanvas, R, AState, AExpanded)
      else
        GroupExpandButton.Draw(ACanvas.Handle, R, Ord(not AExpanded), ButtonStateToSkinState[AState]);
  end;

var
  ABitmap: TcxAlphaBitmap;
  ARect: TRect;
begin
  if ARotationAngle = ra0 then
    DoDrawGroupBoxExpandButton(ACanvas, R)
  else
  begin
    if ARotationAngle in [raPlus90, raMinus90] then
      ARect := cxRectRotate(R)
    else
      ARect := R;
    ABitmap := TcxAlphaBitmap.CreateSize(ARect);
    try
      ABitmap.Clear;
      DoDrawGroupBoxExpandButton(ABitmap.cxCanvas, ABitmap.ClientRect);
      ACanvas.RotateBitmap(ABitmap, ARotationAngle);
      cxDrawImage(ACanvas.Handle, R, R, ABitmap, nil, -1, idmNormal);
    finally
      ABitmap.Free;
    end;
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawGroupBoxBackground(ACanvas: TcxCanvas;
  ABounds: TRect; ARect: TRect);
begin
  with SkinInfo do
    if GroupBoxClient = nil then
      inherited DrawGroupBoxBackground(ACanvas, ABounds, ARect)
    else
      GroupBoxClient.Draw(ACanvas.Handle, ARect);
end;

procedure TdxSkinLookAndFeelPainter.DrawHeader(ACanvas: TcxCanvas;
  const ABounds, ATextAreaBounds: TRect; ANeighbors: TcxNeighbors; ABorders: TcxBorders;
  AState: TcxButtonState;  AAlignmentHorz: TAlignment; AAlignmentVert: TcxAlignmentVert;
  AMultiLine, AShowEndEllipsis: Boolean; const AText: string; AFont: TFont; ATextColor,
  ABkColor: TColor; AOnDrawBackground: TcxDrawBackgroundEvent = nil; AIsLast: Boolean = False;
  AIsGroup: Boolean = False);

  function AdjustHeaderBounds(const ABounds: TRect; ABorders: TcxBorders): TRect;
  begin
    Result := cxRectExclude(ABounds, cxRect(1, 1, 1, 1), ABorders);
  end;

var
  AHeader: TdxSkinElement;
begin
  with SkinInfo do
    if AIsGroup then
      AHeader := HeaderSpecial
    else
      AHeader := Header;

  if AHeader = nil then
    inherited DrawHeader(ACanvas, ABounds, ATextAreaBounds, ANeighbors, ABorders,
      AState, AAlignmentHorz, AAlignmentVert, AMultiLine, AShowEndEllipsis, AText,
      AFont, ATextColor, ABkColor, AOnDrawBackGround, AIsLast, AIsGroup)
  else
  begin
    ACanvas.SaveClipRegion;
    try
      ACanvas.SetClipRegion(TcxRegion.Create(ABounds), roIntersect);
      AHeader.Draw(ACanvas.Handle, AdjustHeaderBounds(ABounds, ABorders), 0,
        ButtonStateToSkinState[AState]);
      DrawContent(ACanvas, HeaderContentBounds(ABounds, ABorders), ATextAreaBounds,
        Integer(AState), AAlignmentHorz, AAlignmentVert, AMultiLine, AShowEndEllipsis,
        AText, AFont, ATextColor, ABkColor, AOnDrawBackground);
    finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawHeaderEx(ACanvas: TcxCanvas;
  const ABounds, ATextAreaBounds: TRect; ANeighbors: TcxNeighbors;
  ABorders: TcxBorders; AState: TcxButtonState;  AAlignmentHorz: TAlignment;
  AAlignmentVert: TcxAlignmentVert; AMultiLine, AShowEndEllipsis: Boolean;
  const AText: string; AFont: TFont; ATextColor, ABkColor: TColor;
  AOnDrawBackground: TcxDrawBackgroundEvent = nil);
begin
  DrawHeader(ACanvas, ABounds, ATextAreaBounds, ANeighbors, ABorders, AState,
    AAlignmentHorz, AAlignmentVert, AMultiLine, AShowEndEllipsis, AText, AFont,
    ATextColor, ABkColor, AOnDrawBackground);
end;

procedure TdxSkinLookAndFeelPainter.DrawHeaderPressed(ACanvas: TcxCanvas; const ABounds: TRect);
begin
  // do nothing
end;

procedure TdxSkinLookAndFeelPainter.DrawHeaderControlSection(ACanvas: TcxCanvas;
  const ABounds, ATextAreaBounds: TRect; ANeighbors: TcxNeighbors; ABorders: TcxBorders; AState: TcxButtonState;
  AAlignmentHorz: TAlignment; AAlignmentVert: TcxAlignmentVert; AMultiLine, AShowEndEllipsis: Boolean;
  const AText: string; AFont: TFont; ATextColor, ABkColor: TColor);
begin
  ABorders := [bLeft, bTop, bBottom, bRight];
  if nLeft in ANeighbors then
    Exclude(ABorders, bLeft);
  DrawHeader(ACanvas, ABounds, ATextAreaBounds, ANeighbors, ABorders, AState,
    AAlignmentHorz, AAlignmentVert, AMultiLine, AShowEndEllipsis, AText, AFont, ATextColor, ABkColor);
end;

procedure TdxSkinLookAndFeelPainter.DrawHeaderSeparator(ACanvas: TcxCanvas;
  const ABounds: TRect; AIndentSize: Integer; AColor: TColor; AViewParams: TcxViewParams);
begin
  with SkinInfo do
    if HeaderBackgroundColor = nil then
      inherited DrawHeaderSeparator(ACanvas, ABounds, AIndentSize, AColor, AViewParams)
    else
      ACanvas.FillRect(cxRectInflate(ABounds, -AIndentSize, 0), HeaderBackgroundColor.Value);
end;

procedure TdxSkinLookAndFeelPainter.DrawSortingMark(
  ACanvas: TcxCanvas; const R: TRect; AAscendingSorting: Boolean);
begin
  if SkinInfo.SortGlyphs <> nil then
    SkinInfo.SortGlyphs.Draw(ACanvas.Handle, R, Integer(AAscendingSorting))
  else
    inherited DrawSortingMark(ACanvas, R, AAscendingSorting);
end;

procedure TdxSkinLookAndFeelPainter.DrawSummarySortingMark(
  ACanvas: TcxCanvas; const R: TRect; AAscendingSorting: Boolean);
begin
  if SkinInfo.SortGlyphs <> nil then
    SkinInfo.SortGlyphs.Draw(ACanvas.Handle, R, 2 + Integer(AAscendingSorting))
  else
    inherited DrawSortingMark(ACanvas, R, AAscendingSorting);
end;

function TdxSkinLookAndFeelPainter.HeaderBorders(ANeighbors: TcxNeighbors): TcxBorders;
begin
  Result := inherited HeaderBorders(ANeighbors);
  if nLeft in ANeighbors then Exclude(Result, bLeft);
  if nTop in ANeighbors then Exclude(Result, bTop);
end;

function TdxSkinLookAndFeelPainter.HeaderDrawCellsFirst: Boolean;
begin
  Result := False;
end;

function TdxSkinLookAndFeelPainter.SummarySortingMarkSize: TPoint;
begin
  Result := SortingMarkSize;
end;

procedure TdxSkinLookAndFeelPainter.DrawGroupByBox(ACanvas: TcxCanvas;
  const ARect: TRect; ATransparent: Boolean; ABackgroundColor: TColor;
  const ABackgroundBitmap: TBitmap);
begin
  if SkinInfo.GridGroupByBox = nil then
    inherited DrawGroupByBox(ACanvas, ARect, ATransparent, ABackgroundColor, ABackgroundBitmap)
  else
    SkinInfo.GridGroupByBox.Draw(ACanvas.Handle, ARect);
end;

procedure TdxSkinLookAndFeelPainter.DrawGroupCaption(ACanvas: TcxCanvas;
  const ACaptionRect, ATextRect: TRect; AElement: TdxSkinElement;
  ATextPadding: TdxSkinIntegerProperty; AState: TdxSkinElementState);
var
  R: TRect;
begin
  AElement.Draw(ACanvas.Handle, ACaptionRect, 0, AState);
  if cxColorIsValid(AElement.Color) and not cxRectIsEmpty(ATextRect) then
  begin
    R := ATextRect;
    if ATextPadding <> nil then
      InflateRect(R, ATextPadding.Value, ATextPadding.Value);
    ACanvas.SaveClipRegion;
    try
      ACanvas.IntersectClipRect(ACaptionRect);
      ACanvas.FillRect(R, AElement.Color);
    finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

function TdxSkinLookAndFeelPainter.GridBordersOverlapSize: Integer;
begin
  Result := BorderSize;
end;

function TdxSkinLookAndFeelPainter.GridDrawHeaderCellsFirst: Boolean;
begin
  with SkinInfo do
  begin
    if Header = nil then
      Result := inherited GridDrawHeaderCellsFirst
    else
      Result := not Header.IsAlphaUsed;
  end;
end;

function TdxSkinLookAndFeelPainter.GridGroupRowStyleOffice11ContentColor(AHasData: Boolean): TColor;
begin
  if SkinInfo.GridGroupRowStyleOffice11ContentColor = nil then
    Result := inherited GridGroupRowStyleOffice11ContentColor(AHasData)
  else
    Result := SkinInfo.GridGroupRowStyleOffice11ContentColor.Value;
end;

function TdxSkinLookAndFeelPainter.GridGroupRowStyleOffice11SeparatorColor: TColor;
begin
  if SkinInfo.GridGroupRowStyleOffice11SeparatorColor = nil then
    Result := inherited GridGroupRowStyleOffice11SeparatorColor
  else
    Result := SkinInfo.GridGroupRowStyleOffice11SeparatorColor.Value;
end;

function TdxSkinLookAndFeelPainter.GridGroupRowStyleOffice11TextColor: TColor;
begin
  if SkinInfo.GridGroupRowStyleOffice11TextColor = nil then
    Result := inherited GridGroupRowStyleOffice11TextColor
  else
    Result := SkinInfo.GridGroupRowStyleOffice11TextColor.Value;
end;

procedure TdxSkinLookAndFeelPainter.LayoutViewDrawRecordCaption(
  ACanvas: TcxCanvas; const ABounds, ATextRect: TRect;
  APosition: TcxGroupBoxCaptionPosition; AState: TcxButtonState);
const
  LayoutViewRecordState: array[TcxButtonState] of TdxSkinElementState =
    (esNormal, esNormal, esActive, esActive, esActiveDisabled);
begin
  if SkinInfo.LayoutViewRecordCaptionElements[APosition] = nil then
    inherited LayoutViewDrawRecordCaption(ACanvas, ABounds, ATextRect, APosition, AState)
  else
    DrawGroupCaption(ACanvas, ABounds, ATextRect,
      SkinInfo.LayoutViewRecordCaptionElements[APosition],
      SkinInfo.LayoutViewRecordCaptionTextPadding[APosition],
      LayoutViewRecordState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.LayoutViewDrawRecordContent(
  ACanvas: TcxCanvas; const ABounds: TRect; ACaptionPosition: TcxGroupBoxCaptionPosition;
  AState: TcxButtonState; ABorders: TcxBorders = cxBordersAll);
begin
  with SkinInfo do
    if LayoutViewRecordElements[ACaptionPosition] = nil then
      inherited LayoutViewDrawRecordContent(ACanvas, ABounds, ACaptionPosition, AState, ABorders)
    else
      LayoutViewRecordElements[ACaptionPosition].Draw(ACanvas.Handle, ABounds);
end;

procedure TdxSkinLookAndFeelPainter.LayoutViewDrawRecordExpandButton(
  ACanvas: TcxCanvas; const ABounds: TRect; AState: TcxButtonState; AExpanded: Boolean);
begin
  with SkinInfo do
    if LayoutViewRecordExpandButton = nil then
      inherited LayoutViewDrawRecordExpandButton(ACanvas, ABounds, AState, AExpanded)
    else
      LayoutViewRecordExpandButton.Draw(ACanvas.Handle,
        ABounds, Ord(not AExpanded), ButtonStateToSkinState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.LayoutViewDrawItem(
  ACanvas: TcxCanvas; const ABounds: TRect; AState: TcxButtonState; ABorders: TcxBorders = []);
begin
  if SkinInfo.LayoutViewItem = nil then
    inherited LayoutViewDrawItem(ACanvas, ABounds, AState, ABorders)
  else
    if AState <> cxbsNormal then
      SkinInfo.LayoutViewItem.Draw(ACanvas.Handle, ABounds, 0, ButtonStateToSkinState[AState])
    else
      if ABorders <> [] then
      begin
        ACanvas.SaveClipRegion;
        try
          ACanvas.IntersectClipRect(ABounds);
          SkinInfo.LayoutViewItem.Draw(ACanvas.Handle,
            cxRectExclude(ABounds, SkinInfo.LayoutViewItem.Image.Margins.Margin, ABorders), 0,
            ButtonStateToSkinState[AState]);
        finally
          ACanvas.RestoreClipRegion;
        end;
      end;
end;

function TdxSkinLookAndFeelPainter.LayoutViewGetPadding(AElement: TcxLayoutElement): TRect;
begin
  if SkinInfo.LayoutViewElementPadding[AElement] = nil then
    Result := inherited LayoutViewGetPadding(AElement)
  else
    Result := SkinInfo.LayoutViewElementPadding[AElement].Value.Rect;
end;

function TdxSkinLookAndFeelPainter.LayoutViewGetSpacing(AElement: TcxLayoutElement): TRect;
begin
  if SkinInfo.LayoutViewElementSpacing[AElement] = nil then
    Result := inherited LayoutViewGetSpacing(AElement)
  else
    Result := SkinInfo.LayoutViewElementSpacing[AElement].Value.Rect;
end;

function TdxSkinLookAndFeelPainter.LayoutViewRecordCaptionTailSize(
  ACaptionPosition: TcxGroupBoxCaptionPosition): Integer;
var
  AProperty: TdxSkinIntegerProperty;
begin
  AProperty := SkinInfo.LayoutViewRecordCaptionTailSizes[ACaptionPosition];
  if AProperty = nil then
    Result := inherited LayoutViewRecordCaptionTailSize(ACaptionPosition)
  else
    Result := AProperty.Value;
end;

function TdxSkinLookAndFeelPainter.PivotGridHeadersAreaColor: TColor;
begin
  with SkinInfo do
    if (GridGroupByBox = nil) or not cxColorIsValid(GridGroupByBox.Color) then
      Result := inherited PivotGridHeadersAreaColor
    else
      Result := GridGroupByBox.Color;
end;

function TdxSkinLookAndFeelPainter.PivotGridHeadersAreaTextColor: TColor;
begin
  with SkinInfo do
    if (GridGroupByBox = nil) or not cxColorIsValid(GridGroupByBox.TextColor) then
      Result := inherited PivotGridHeadersAreaColor
    else
      Result := GridGroupByBox.TextColor;
end;

procedure TdxSkinLookAndFeelPainter.DrawFooterCellBorder(ACanvas: TcxCanvas; const R: TRect);
begin
  if SkinInfo.FooterCell = nil then
    inherited DrawFooterCellBorder(ACanvas, R);
end;

procedure TdxSkinLookAndFeelPainter.DrawFooterCellContent(ACanvas: TcxCanvas;
  const ABounds: TRect; AAlignmentHorz: TAlignment; AAlignmentVert: TcxAlignmentVert;
  AMultiLine: Boolean; const AText: string; AFont: TFont; ATextColor, ABkColor: TColor;
  AOnDrawBackground: TcxDrawBackgroundEvent = nil);
begin
  if SkinInfo.FooterCell <> nil then
    SkinInfo.FooterCell.Draw(ACanvas.Handle, ABounds);
  inherited DrawFooterCellContent(ACanvas, ABounds, AAlignmentHorz, AAlignmentVert,
    AMultiLine, AText, AFont, ATextColor, ABkColor, AOnDrawBackground);
end;

procedure TdxSkinLookAndFeelPainter.DrawFooterContent(
  ACanvas: TcxCanvas; const ARect: TRect; const AViewParams: TcxViewParams);
begin
  with SkinInfo do
    if (FooterPanel = nil) or (AViewParams.Bitmap <> nil) and not AViewParams.Bitmap.Empty then
      inherited DrawFooterContent(ACanvas, ARect, AViewParams)
    else
    begin
      ACanvas.SaveClipRegion;
      try
        ACanvas.IntersectClipRect(ARect);
        FooterPanel.Draw(ACanvas.Handle, cxRectInflate(ARect,
          FooterBorderSize, FooterSeparatorSize, FooterBorderSize, FooterBorderSize));
      finally
        ACanvas.RestoreClipRegion;
      end;
    end;
end;

function TdxSkinLookAndFeelPainter.FooterCellBorderSize: Integer;
begin
  with SkinInfo do
    if FooterCell = nil then
      Result := inherited FooterCellBorderSize
    else
      with FooterCell.ContentOffset do
        Result := Max(Max(Left, Top), Max(Right, Bottom));
end;

function TdxSkinLookAndFeelPainter.FooterDrawCellsFirst: Boolean;
begin
  Result := False;
end;

function TdxSkinLookAndFeelPainter.FooterSeparatorColor: TColor;
begin
  Result := DefaultGridLineColor;
end;

procedure TdxSkinLookAndFeelPainter.DrawFilterDropDownButton(
  ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState; AIsFilterActive: Boolean);
begin
  with SkinInfo do
    if FilterButtons[AIsFilterActive] <> nil then
      FilterButtons[AIsFilterActive].Draw(ACanvas.Handle, R, 0,
        ButtonStateToSkinState[AState])
    else
      inherited DrawFilterDropDownButton(ACanvas, R, AState, AIsFilterActive);
end;

procedure TdxSkinLookAndFeelPainter.DrawFilterCloseButton(
  ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState);
begin
  with SkinInfo do
  begin
    if EditButtonElements[True] = nil then
      inherited DrawFilterCloseButton(ACanvas, R, AState)
    else
      EditButtonElements[True].Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawFilterPanel(ACanvas: TcxCanvas;
  const ARect: TRect; ATransparent: Boolean; ABackgroundColor: TColor;
  const ABackgroundBitmap: TBitmap);
begin
  with SkinInfo do
  begin
    if FilterPanel = nil then
      inherited DrawFilterPanel(ACanvas, ARect, ATransparent, ABackgroundColor,
        ABackgroundBitmap)
    else
      FilterPanel.Draw(ACanvas.Handle, ARect);
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawPanelBorders(ACanvas: TcxCanvas;
  const ABorderRect: TRect);
var
  AElement: TdxSkinElement;
begin
  AElement := SkinInfo.GroupBoxElements[cxgpCenter];
  if AElement = nil then
    DrawPanelBorders(ACanvas, ABorderRect)
  else
  begin
    ACanvas.SaveClipRegion;
    try
      ACanvas.ExcludeClipRect(cxRectContent(ABorderRect, AElement.ContentOffset.Rect));
      AElement.Draw(ACanvas.Handle, ABorderRect);
    finally
      ACanvas.RestoreClipRegion;
    end;
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawPanelContent(ACanvas: TcxCanvas;
  const ABorderRect: TRect; ABorder: Boolean);
begin
  with SkinInfo do
    if (GroupBoxClient = nil) then
      inherited DrawPanelContent(ACanvas, ABorderRect, ABorder)
    else
    begin
      GroupBoxClient.Draw(ACanvas.Handle, ABorderRect);
      if ABorder then
        DrawPanelBorders(ACanvas, ABorderRect);
    end;
end;

function TdxSkinLookAndFeelPainter.FilterCloseButtonSize: TPoint;
begin
  with SkinInfo do
    if EditButtonElements[True] = nil then
      Result := inherited FilterCloseButtonSize
    else
      Result := cxPoint(EditButtonElements[True].MinSize.Size);
end;

function TdxSkinLookAndFeelPainter.FilterSmartTagSize: TSize;
begin
  if SkinInfo.SmartFilterButton <> nil then
    Result := SkinInfo.SmartFilterButton.MinSize.Size
  else
    Result := inherited FilterSmartTagSize;
end;

procedure TdxSkinLookAndFeelPainter.DrawFilterSmartTag(
  ACanvas: TcxCanvas; R: TRect; AState: TcxFilterSmartTagState; AIsFilterActive: Boolean);
const
  StatesMap: array[Boolean, TcxFilterSmartTagState] of TdxSkinElementState = (
    (esNormal, esHot, esPressed, esNormal),
    (esChecked, esHot, esPressed, esActive)
  );
begin
  if SkinInfo.SmartFilterButton = nil then
    inherited DrawFilterSmartTag(ACanvas, R, AState, AIsFilterActive)
  else
    SkinInfo.SmartFilterButton.Draw(ACanvas.Handle, R, 0, StatesMap[AIsFilterActive, AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawTrackBarTrack(ACanvas: TcxCanvas;
  const ARect, ASelection: TRect; AShowSelection, AEnabled, AHorizontal: Boolean; ATrackColor: TColor);
begin
  with SkinInfo do
    if TrackBarTrack[AHorizontal] = nil then
      inherited
    else
    begin
      TrackBarTrack[AHorizontal].Draw(ACanvas.Handle, ARect, 2 * Byte(not AEnabled));
      if AShowSelection then
        TrackBarTrack[AHorizontal].Draw(ACanvas.Handle, ASelection, 2 * Byte(not AEnabled) + 1);
    end;
end;

procedure TdxSkinLookAndFeelPainter.DrawTrackBarThumb(ACanvas: TcxCanvas;
  const ARect: TRect; AState: TcxButtonState; AHorizontal: Boolean;
  ATicks: TcxTrackBarTicksAlign; AThumbColor: TColor);
begin
  with SkinInfo do
  begin
    if TrackBarThumb[AHorizontal, ATicks] <> nil then
      TrackBarThumb[AHorizontal, ATicks].Draw(
        ACanvas.Handle, ARect, 0, ButtonStateToSkinState[AState])
    else
      inherited
  end;
end;

function TdxSkinLookAndFeelPainter.TrackBarThumbSize(AHorizontal: Boolean): TSize;
begin
  with SkinInfo do
  begin
    if TrackBarThumb[AHorizontal, tbtaDown] <> nil then
      Result := TrackBarThumb[AHorizontal, tbtaDown].Size
    else
      Result := inherited TrackBarThumbSize(AHorizontal);
  end;
end;

function TdxSkinLookAndFeelPainter.TrackBarTicksColor(AText: Boolean): TColor;
begin
  if SkinInfo.TrackBarTickColor <> nil then
    Result := SkinInfo.TrackBarTickColor.Value
  else
    Result := inherited TrackBarTicksColor(AText);
end;

function TdxSkinLookAndFeelPainter.TrackBarTrackSize: Integer;
begin
  with SkinInfo do
  begin
    if TrackBarTrack[True] <> nil then
      Result := TrackBarTrack[True].Size.cy
    else
      Result := inherited TrackBarTrackSize;
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawContent(ACanvas: TcxCanvas;
  const ABounds, ATextAreaBounds: TRect; AState: Integer; AAlignmentHorz: TAlignment;
  AAlignmentVert: TcxAlignmentVert; AMultiLine, AShowEndEllipsis: Boolean;
  const AText: string; AFont: TFont; ATextColor, ABkColor: TColor;
  AOnDrawBackground: TcxDrawBackgroundEvent = nil; AIsFooter: Boolean = False);
const
  AlignmentsHorz: array[TAlignment] of Integer =
    (cxAlignLeft, cxAlignRight, cxAlignHCenter);
  AlignmentsVert: array[TcxAlignmentVert] of Integer =
    (cxAlignTop, cxAlignBottom, cxAlignVCenter);
  MultiLines: array[Boolean] of Integer = (cxSingleLine, cxWordBreak);
  ShowEndEllipsises: array[Boolean] of Integer = (0, cxShowEndEllipsis);
begin
  with ACanvas do
  begin
    if AText <> '' then
    begin
      Brush.Style := bsClear;
      Font := AFont;
      Font.Color := ATextColor;
      DrawText(AText, ATextAreaBounds, AlignmentsHorz[AAlignmentHorz] or
        AlignmentsVert[AAlignmentVert] or MultiLines[AMultiLine] or
        ShowEndEllipsises[AShowEndEllipsis]);
      Brush.Style := bsSolid;
    end;
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawSplitter(ACanvas: TcxCanvas;
  const ARect: TRect; AHighlighted: Boolean; AClicked: Boolean; AHorizontal: Boolean);
const
  StateMap: array[Boolean] of TdxSkinElementState = (esNormal, esHot);
begin
  with SkinInfo do
  begin
    if Splitter[AHorizontal] = nil then
      inherited DrawSplitter(ACanvas, ARect, AHighlighted, AClicked, AHorizontal)
    else
      Splitter[AHorizontal].Draw(ACanvas.Handle , ARect, 0, StateMap[AHighlighted]);
  end;
end;

function TdxSkinLookAndFeelPainter.GetSplitterSize(AHorizontal: Boolean): TSize;
var
  AElement: TdxSkinElement;
begin
  AElement := SkinInfo.Splitter[AHorizontal];
  if AElement = nil then
    Result := inherited GetSplitterSize(AHorizontal)
  else
    Result := AElement.MinSize.Size;
end;

function TdxSkinLookAndFeelPainter.GetZoomInButtonSize: TSize;
begin
  if SkinInfo.ZoomInButton <> nil then
    Result := SkinInfo.ZoomInButton.Size
  else
    Result := inherited GetZoomInButtonSize;
end;

function TdxSkinLookAndFeelPainter.GetZoomOutButtonSize: TSize;
begin
  if SkinInfo.ZoomOutButton <> nil then
    Result := SkinInfo.ZoomOutButton.Size
  else
    Result := inherited GetZoomOutButtonSize;
end;

function TdxSkinLookAndFeelPainter.GetHintBorderColor: TColor;
begin
  with SkinInfo do
    if ScreenTipWindow <> nil then
      Result := ScreenTipWindow.Borders.Left.Color
    else
      Result := inherited GetHintBorderColor;
end;

procedure TdxSkinLookAndFeelPainter.DrawHintBackground(ACanvas: TcxCanvas;
  const ARect: TRect; AColor: TColor = clDefault);
begin
  with SkinInfo do
    if ScreenTipWindow <> nil then
      ScreenTipWindow.Draw(ACanvas.Handle, cxRectInflate(ARect,
        ScreenTipWindow.ContentOffset.Rect))
    else
      inherited DrawHintBackground(ACanvas, ARect, AColor);
end;

function TdxSkinLookAndFeelPainter.ScreenTipGetDescriptionTextColor: TColor;
begin
  with SkinInfo do
    if ScreenTipItem <> nil then
      Result := ScreenTipItem.Value
    else
      Result := inherited ScreenTipGetDescriptionTextColor;
end;

function TdxSkinLookAndFeelPainter.ScreenTipGetTitleTextColor: TColor;
begin
  with SkinInfo do
    if ScreenTipTitleItem <> nil then
      Result := ScreenTipTitleItem.Value
    else
      Result := inherited ScreenTipGetTitleTextColor;
end;

function TdxSkinLookAndFeelPainter.ScreenTipGetFooterLineSize: Integer;
begin
  with SkinInfo do
    if ScreenTipSeparator <> nil then
      Result := ScreenTipSeparator.Size.cy
    else
      Result := inherited ScreenTipGetFooterLineSize;
end;

procedure TdxSkinLookAndFeelPainter.ScreenTipDrawBackground(ACanvas: TcxCanvas; ARect: TRect);
begin
  with SkinInfo do
    if ScreenTipWindow <> nil then
      ScreenTipWindow.Draw(ACanvas.Handle, ARect)
    else
      inherited ScreenTipDrawBackground(ACanvas, ARect);
end;

procedure TdxSkinLookAndFeelPainter.ScreenTipDrawFooterLine(ACanvas: TcxCanvas; const ARect: TRect);
begin
  with SkinInfo do
    if ScreenTipSeparator <> nil then
      ScreenTipSeparator.Draw(ACanvas.Handle, ARect)
    else
      inherited ScreenTipDrawFooterLine(ACanvas, ARect);
end;

procedure TdxSkinLookAndFeelPainter.DrawIndicatorCustomizationMark(
  ACanvas: TcxCanvas; const R: TRect; AColor: TColor);
const
  AIndicatorCustomizationMarkID = 2;
var
  ARect: TRect;  
begin
  with SkinInfo do
    if IndicatorImages = nil then
      inherited DrawIndicatorCustomizationMark(ACanvas, R, AColor)
    else
    begin
      with IndicatorImages.Image.Size, R do
      begin
        ARect := Rect(0, 0, cx, cy);
        OffsetRect(ARect, (Left + Right - cx) div 2, (Top + Bottom - cy) div 2);
      end;
      IndicatorImages.Draw(ACanvas.Handle, ARect, AIndicatorCustomizationMarkID);
    end;
end;

procedure TdxSkinLookAndFeelPainter.DrawIndicatorImage(ACanvas: TcxCanvas;
  const R: TRect; AKind: TcxIndicatorKind);
const
  AIndicatorImagesMap: array[TcxIndicatorKind] of integer = (0, 0, 1, 2, 0, 0, 8);
var
  ARect: TRect;
begin
  with SkinInfo do
    if IndicatorImages = nil then
      inherited DrawIndicatorImage(ACanvas, R, AKind)
    else
      if AKind <> ikNone then
      begin
        with IndicatorImages.Image.Size, R do
        begin
          ARect := Rect(0, 0, cx, cy);
          OffsetRect(ARect, (Left + Right - cx) div 2, (Top + Bottom - cy) div 2);
        end;  
        IndicatorImages.Draw(ACanvas.Handle, ARect, AIndicatorImagesMap[AKind]);
      end;
end;

procedure TdxSkinLookAndFeelPainter.DrawIndicatorItem(ACanvas: TcxCanvas;
  const R: TRect; AKind: TcxIndicatorKind; AColor: TColor;
  AOnDrawBackground: TcxDrawBackgroundEvent = nil);
var
  ARect: TRect;
begin
  with R do
    ARect := Rect(Left, Top - HeaderBorderSize, Right, Bottom);
  DrawHeader(ACanvas, ARect, ARect, [], HeaderBorders([nTop, nBottom]), cxbsNormal,
    taLeftJustify, vaTop, False, False, '', nil, clNone, AColor, AOnDrawBackground);
  DrawIndicatorImage(ACanvas, R, AKind);
end;

procedure TdxSkinLookAndFeelPainter.DrawIndicatorItemEx(ACanvas: TcxCanvas;
  const R: TRect; AKind: TcxIndicatorKind; AColor: TColor;
  AOnDrawBackground: TcxDrawBackgroundEvent = nil);
begin
  DrawIndicatorItem(ACanvas, R, AKind, AColor, AOnDrawBackground);
end;

procedure TdxSkinLookAndFeelPainter.DrawMonthHeader(ACanvas: TcxCanvas;
  const ABounds: TRect; const AText: string; ANeighbors: TcxNeighbors;
  const AViewParams: TcxViewParams; AArrows: TcxArrowDirections; ASideWidth: Integer;
  AOnDrawBackground: TcxDrawBackgroundEvent = nil);
begin
  DrawHeader(ACanvas, ABounds, ABounds, ANeighbors, HeaderBorders(ANeighbors),
    cxbsNormal, taCenter, vaCenter, False, False, AText, AViewParams.Font,
    AViewParams.TextColor, AViewParams.Color, AOnDrawBackground);
  DrawMonthHeaderArrows(ACanvas, ABounds, AArrows, ASideWidth,
    DefaultDateNavigatorHeaderTextColor(False));
end;

procedure TdxSkinLookAndFeelPainter.DrawSchedulerEventProgress(
  ACanvas: TcxCanvas; const ABounds, AProgress: TRect;
  AViewParams: TcxViewParams; ATransparent: Boolean);
var
  AProgressBar: TdxSkinElement;
  AProgressChunk: TdxSkinElement;
begin
  with SkinInfo do
  begin
    AProgressBar := ProgressBarElements[False, False];
    AProgressChunk := ProgressBarElements[True, False];
  end;
  if (AProgressBar = nil) or (AProgressChunk = nil) then
    inherited DrawSchedulerEventProgress(ACanvas, ABounds, AProgress, AViewParams,
      ATransparent)
  else
  begin
    AProgressBar.Draw(ACanvas.Handle, ABounds);
    AProgressChunk.Draw(ACanvas.Handle, AProgress);
  end;
end;

function TdxSkinLookAndFeelPainter.SchedulerEventProgressOffsets: TRect;
var
  AProgressBar: TdxSkinElement;
begin
  with SkinInfo do
    AProgressBar := ProgressBarElements[False, False];
  if AProgressBar = nil then
    Result := SchedulerEventProgressOffsets
  else
    Result := AProgressBar.ContentOffset.Rect
end;

function TdxSkinLookAndFeelPainter.SchedulerNavigationButtonTextColor(
  AIsNextButton: Boolean; AState: TcxButtonState;
  ADefaultColor: TColor = clDefault): TColor;
var
  AElement: TdxSkinElement;
begin
  AElement := SkinInfo.SchedulerNavigationButtons[AIsNextButton];
  if AElement = nil then
    Result := inherited SchedulerNavigationButtonTextColor(AIsNextButton, AState, ADefaultColor)
  else
  begin
    Result := AElement.GetTextColor(AState);
    if Result = clDefault then
      Result := ADefaultColor;
  end;
end;

procedure TdxSkinLookAndFeelPainter.CalculateSchedulerNavigationButtonRects(
  AIsNextButton: Boolean; ACollapsed: Boolean; APrevButtonTextSize: TSize;
  ANextButtonTextSize: TSize; var ABounds: TRect; out ATextRect: TRect;
  out AArrowRect: TRect);
var
  AMinSize: TSize;
begin
  with SkinInfo do
    if SchedulerNavigationButtons[AIsNextButton] = nil then
      AMinSize := cxNullSize
    else
      AMinSize := SchedulerNavigationButtons[AIsNextButton].MinSize.Size;

  if (AMinSize.cx > 0) and (ABounds.Right - ABounds.Left < AMinSize.cx) then
    if AIsNextButton then
      ABounds.Left := ABounds.Right - AMinSize.cx
    else
      ABounds.Right := ABounds.Left + AMinSize.cx;
                                              
  inherited CalculateSchedulerNavigationButtonRects(AIsNextButton, ACollapsed,
    APrevButtonTextSize, ANextButtonTextSize, ABounds, ATextRect, AArrowRect);
end;

procedure TdxSkinLookAndFeelPainter.DrawFooterBorderEx(
  ACanvas: TcxCanvas; const R: TRect; ABorders: TcxBorders);

  function GetContentMargins: TRect;
  begin
    Result := SkinInfo.FooterPanel.ContentOffset.Rect;
    Result.Top := FooterSeparatorSize;
  end;

begin
  with SkinInfo do
    if FooterPanel = nil then
      inherited DrawFooterBorder(ACanvas, R)
    else
    begin
      ACanvas.SaveClipRegion;
      try
        ACanvas.ExcludeClipRect(cxRectContent(R, GetContentMargins));
        FooterPanel.Draw(ACanvas.Handle, cxRectExclude(R, GetContentMargins, ABorders));
      finally
        ACanvas.RestoreClipRegion;
      end;
    end;
end;

procedure TdxSkinLookAndFeelPainter.DrawSchedulerNavigationButtonContent(
  ACanvas: TcxCanvas; const ARect: TRect; const AArrowRect: TRect;
  AIsNextButton: Boolean; AState: TcxButtonState);
var
  R: TRect;
begin
  with SkinInfo do
    if SchedulerNavigationButtons[AIsNextButton] = nil then
      inherited DrawSchedulerNavigationButtonContent(ACanvas, ARect, AArrowRect,
        AIsNextButton, AState)
    else
    begin
      R := ARect;
      if AIsNextButton then
        Inc(R.Right)
      else
        Dec(R.Left);

      ACanvas.SaveClipRegion;
      try
        ACanvas.SetClipRegion(TcxRegion.Create(ARect), roIntersect);
        SchedulerNavigationButtons[AIsNextButton].Draw(ACanvas.Handle, R, 0,
          ButtonStateToSkinState[AState]);
        if SchedulerNavigationButtonsArrow[AIsNextButton] <> nil then
          SchedulerNavigationButtonsArrow[AIsNextButton].Draw(ACanvas.Handle,
            AArrowRect, 0, ButtonStateToSkinState[AState]);
      finally
        ACanvas.RestoreClipRegion;
      end;
    end;
end;

function TdxSkinLookAndFeelPainter.IsColorPropertyAssigned(AColor: TdxSkinColor): Boolean;
begin
  Result := Assigned(AColor) and cxColorIsValid(AColor.Value);
end;

function TdxSkinLookAndFeelPainter.GalleryStateToButtonState(const AState: TdxGalleryItemViewState): TcxButtonState;
begin
  if AState.Enabled then
    Result := cxbsDisabled
  else
    if AState.Pressed then
      Result := cxbsPressed
    else
      if AState.Hover or AState.Focused then
        Result := cxbsHot
      else
        Result := cxbsNormal;
end;

function TdxSkinLookAndFeelPainter.GetSkinInfoClass: TdxSkinLookAndFeelPainterInfoClass;
begin
  Result := TdxSkinLookAndFeelPainterInfo;
end;

procedure TdxSkinLookAndFeelPainter.SchedulerNavigationButtonSizes(
  AIsNextButton: Boolean; var ABorders: TRect; var AArrowSize: TSize;
  var AHasTextArea: Boolean);
begin
  with SkinInfo do
    if (SchedulerNavigationButtons[AIsNextButton] = nil) or
       (SchedulerNavigationButtonsArrow[AIsNextButton] = nil)
    then
      inherited SchedulerNavigationButtonSizes(
        AIsNextButton, ABorders, AArrowSize, AHasTextArea)
    else
    begin
      ABorders := SchedulerNavigationButtons[AIsNextButton].ContentOffset.Rect;
      AArrowSize := SchedulerNavigationButtonsArrow[AIsNextButton].Size;
      AHasTextArea := not SchedulerNavigationButtons[AIsNextButton].Image.Empty;
    end;
end;

procedure TdxSkinLookAndFeelPainter.DrawSchedulerGroup(
  ACanvas: TcxCanvas; const R: TRect; AColor: TColor = clDefault);
var
  AMask: TcxBitmap;
  ARegion: HRGN;
begin
  if SkinInfo.SchedulerGroup = nil then
    inherited DrawSchedulerGroup(ACanvas, R)
  else
  begin
    SkinInfo.SchedulerGroup.Draw(ACanvas.Handle, R);
    if cxColorIsValid(AColor) and (AColor <> clWindow) then
    begin
      AMask := TcxBitmap.CreateSize(R);
      try
        SkinInfo.SchedulerGroup.Draw(AMask.Canvas.Handle, AMask.ClientRect, 1);
        AMask.Monochrome := True;
        ARegion := cxCreateRegionFromBitmap(AMask, clBlack);
        try
          OffsetRgn(ARegion, R.Left, R.Top);
          ACanvas.FillRegion(ARegion, AColor);
        finally
          DeleteObject(ARegion);
        end;
      finally
        AMask.Free;
      end;
    end;
  end;
end;

procedure TdxSkinLookAndFeelPainter.DrawSchedulerGroupSeparator(ACanvas: TcxCanvas;
  const ABounds: TRect; ABackgroundColor: TColor; AOnDrawBackground: TcxDrawBackgroundEvent);
begin
  ACanvas.FrameRect(ABounds, GetContainerBorderColor(False), 1, [bLeft, bRight]);
  ACanvas.FillRect(cxRectInflate(ABounds, -1, 0), DefaultContentColor);
end;

procedure TdxSkinLookAndFeelPainter.DrawSchedulerMilestone(ACanvas: TcxCanvas; const R: TRect);
var
  ASize: TSize;
begin
  if SkinInfo.SchedulerMilestone <> nil then
  begin
    ASize := cxSize(cxRectProportionalStretch(R, SkinInfo.SchedulerMilestone.Size));
    SkinInfo.SchedulerMilestone.Draw(ACanvas.Handle, cxRectCenter(R, ASize));
  end
  else
    inherited DrawSchedulerMilestone(ACanvas, R);
end;

procedure TdxSkinLookAndFeelPainter.DrawSchedulerNavigatorButton(
  ACanvas: TcxCanvas; R: TRect; AState: TcxButtonState);
begin
  if SkinInfo.EditButtonElements[False] = nil then
    inherited DrawSchedulerNavigatorButton(ACanvas, R, AState)
  else
    SkinInfo.EditButtonElements[False].Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
end;

function TdxSkinLookAndFeelPainter.GetWindowContentTextColor: TColor;
begin
  Result := clDefault;
  if SkinInfo.FormContent <> nil then
    Result := SkinInfo.FormContent.TextColor;
  Result := cxGetActualColor(Result, inherited GetWindowContentTextColor);
end;

procedure TdxSkinLookAndFeelPainter.DrawWindowContent(ACanvas: TcxCanvas; const ARect: TRect);
begin
  if SkinInfo.FormContent = nil then
    inherited DrawWindowContent(ACanvas, ARect)
  else
    ACanvas.FillRect(ARect, SkinInfo.FormContent.Color);
end;

procedure TdxSkinLookAndFeelPainter.DrawZoomInButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  if SkinInfo.ZoomInButton = nil then
    inherited DrawZoomInButton(ACanvas, R, AState)
  else
    SkinInfo.ZoomInButton.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
end;

procedure TdxSkinLookAndFeelPainter.DrawZoomOutButton(
  ACanvas: TcxCanvas; const R: TRect; AState: TcxButtonState);
begin
  if SkinInfo.ZoomOutButton = nil then
    inherited DrawZoomOutButton(ACanvas, R, AState)
  else
    SkinInfo.ZoomOutButton.Draw(ACanvas.Handle, R, 0, ButtonStateToSkinState[AState]);
end;

function TdxSkinLookAndFeelPainter.PrintPreviewPageBordersWidth: TRect;
begin
  with SkinInfo do
    if PrintingPageBorder =  nil then
      Result := inherited PrintPreviewPageBordersWidth
    else
      Result := PrintingPageBorder.ContentOffset.Rect;
end;

procedure TdxSkinLookAndFeelPainter.DrawPrintPreviewBackground(
  ACanvas: TcxCanvas; const R: TRect);
begin
  with SkinInfo do
    if PrintingPreviewBackground =  nil then
      inherited DrawPrintPreviewBackground(ACanvas, R)
    else
    begin
      PrintingPreviewBackground.UseCache := True;
      PrintingPreviewBackground.Draw(ACanvas.Handle, R);
    end;
end;

procedure TdxSkinLookAndFeelPainter.DrawPrintPreviewPageBackground(
  ACanvas: TcxCanvas; const ABorderRect, AContentRect: TRect;
  ASelected, ADrawContent: Boolean);
const
  StateMap: array[Boolean] of TdxSkinElementState = (esNormal, esActive);
begin
  with SkinInfo do
    if PrintingPageBorder =  nil then
      inherited DrawPrintPreviewPageBackground(
        ACanvas, ABorderRect, AContentRect, ASelected, ADrawContent)
    else
    begin
      ACanvas.SaveClipRegion;
      try
        if ADrawContent then
          ACanvas.FillRect(AContentRect, clWhite);
        ACanvas.ExcludeClipRect(AContentRect);
        PrintingPageBorder.Draw(ACanvas.Handle, ABorderRect, 0, StateMap[ASelected]);
      finally
        ACanvas.RestoreClipRegion;
      end;
    end;
end;

procedure TdxSkinLookAndFeelPainter.DrawDateNavigatorDateHeader(
  ACanvas: TcxCanvas; var R: TRect);
begin
  InflateRect(R, 1, 0);
  DrawHeader(ACanvas, R, cxEmptyRect, [], [], cxbsNormal,
    taCenter, vaCenter, False, False, '', nil, 0, 0);
end;

function TdxSkinLookAndFeelPainter.IndicatorDrawItemsFirst: Boolean;
begin
  Result := True;
end;

function TdxSkinLookAndFeelPainter.GetColorGalleryGlyphFrameColor: TColor;
begin
  Result := GetContainerBorderColor(True);
end;

procedure TdxSkinLookAndFeelPainter.DrawGalleryBackground(ACanvas: TcxCanvas; const ABounds: TRect);
begin
  if SkinInfo.GalleryBackground <> nil then
    SkinInfo.GalleryBackground.Draw(ACanvas.Handle, ABounds)
  else
    inherited DrawGalleryBackground(ACanvas, ABounds);
end;

procedure TdxSkinLookAndFeelPainter.DrawGalleryGroupHeader(ACanvas: TcxCanvas; const ABounds: TRect);
begin
  if SkinInfo.GalleryGroup <> nil then
    SkinInfo.GalleryGroup.Draw(ACanvas.Handle, ABounds)
  else
    inherited DrawGalleryGroupHeader(ACanvas, ABounds);
end;

procedure TdxSkinLookAndFeelPainter.DrawGalleryItemImageFrame(ACanvas: TcxCanvas; const R: TRect);
begin
  if SkinInfo.GalleryItemGlyphFrame <> nil then
    SkinInfo.GalleryItemGlyphFrame.Draw(ACanvas.Handle, R)
  else
    inherited DrawGalleryItemImageFrame(ACanvas, R);
end;

procedure TdxSkinLookAndFeelPainter.DrawGalleryItemSelection(
  ACanvas: TcxCanvas; const R: TRect; AViewState: TdxGalleryItemViewState);

  function GetElementState: TdxSkinElementState;
  const
    CheckedMap: array[Boolean] of TdxSkinElementState = (esNormal, esChecked);
    HoverMap: array[Boolean] of TdxSkinElementState = (esHot, esHotCheck);
  begin
    if not AViewState.Enabled then
      Result := esDisabled
    else
      if AViewState.Pressed then
        Result := esPressed
      else
        if AViewState.Hover or AViewState.Focused then
          Result := HoverMap[AViewState.Checked]
        else
          Result := CheckedMap[AViewState.Checked];
  end;

begin
  if SkinInfo.GalleryItem <> nil then
    SkinInfo.GalleryItem.Draw(ACanvas.Handle, R, 0, GetElementState)
  else
    inherited DrawGalleryItemSelection(ACanvas, R, AViewState);
end;

function TdxSkinLookAndFeelPainter.DrawGalleryItemSelectionFirst: Boolean;
begin
  Result := True;
end;

function TdxSkinLookAndFeelPainter.GetSkinElementBordersWidth(AElement: TdxSkinElement): TRect;
begin
  Result := AElement.ContentOffset.Rect;
  Inc(Result.Bottom, AElement.Borders[bBottom].Thin);
  Inc(Result.Left, AElement.Borders[bLeft].Thin);
  Inc(Result.Right, AElement.Borders[bRight].Thin);
  Inc(Result.Top, AElement.Borders[bTop].Thin);
end;

function TdxSkinLookAndFeelPainter.GetSkinDetails: TdxSkinDetails;
begin
  Result := GetLookAndFeelPainterDetails as TdxSkinDetails;
end;

function TdxSkinLookAndFeelPainter.GetSkinInfo: TdxSkinLookAndFeelPainterInfo;
begin
  if FSkinInfo = nil then
  begin
    FSkinInfo := GetSkinInfoClass.Create;
    if FSkinResName <> '' then
    begin
      FSkinInfo.Skin := TdxSkin.Create(FSkinResName, True, FSkinResInstance);
      FreeAndNil(FLookAndFeelPainterDetailsCache);
    end;
  end;
  Result := FSkinInfo;
end;

end.
