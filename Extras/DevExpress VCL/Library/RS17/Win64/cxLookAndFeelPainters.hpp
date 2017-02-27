// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxLookAndFeelPainters.pas' rev: 24.00 (Win64)

#ifndef CxlookandfeelpaintersHPP
#define CxlookandfeelpaintersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCoreGraphics.hpp>	// Pascal unit
#include <dxOffice11.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxlookandfeelpainters
{
//-- type declarations -------------------------------------------------------
enum TcxLookAndFeelStyle : unsigned char { lfsFlat, lfsStandard, lfsUltraFlat, lfsNative, lfsOffice11, lfsSkin };

typedef System::Set<TcxLookAndFeelStyle, TcxLookAndFeelStyle::lfsFlat, TcxLookAndFeelStyle::lfsSkin>  TcxLookAndFeelStyles;

enum TcxArrowDirection : unsigned char { adUp, adDown, adLeft, adRight };

typedef System::Set<TcxArrowDirection, TcxArrowDirection::adUp, TcxArrowDirection::adRight>  TcxArrowDirections;

typedef System::StaticArray<System::Types::TPoint, 3> TcxArrowPoints;

enum TcxEditBtnPosition : unsigned char { cxbpLeft, cxbpRight };

enum TcxGroupBoxCaptionPosition : unsigned char { cxgpTop, cxgpBottom, cxgpLeft, cxgpRight, cxgpCenter };

enum TcxNeighbor : unsigned char { nLeft, nTop, nRight, nBottom };

typedef System::Set<TcxNeighbor, TcxNeighbor::nLeft, TcxNeighbor::nBottom>  TcxNeighbors;

enum TcxScrollBarPart : unsigned char { sbpNone, sbpLineUp, sbpLineDown, sbpThumbnail, sbpPageUp, sbpPageDown };

enum TcxTrackBarTicksAlign : unsigned char { tbtaUp, tbtaDown, tbtaBoth };

enum TcxLayoutElement : unsigned char { leGroup, leGroupWithoutBorders, leTabbedGroup, leRootGroup, leRootGroupWithoutBorders, leItem };

enum TdxBevelShape : unsigned char { dxbsNone, dxbsBox, dxbsFrame, dxbsLineTop, dxbsLineBottom, dxbsLineLeft, dxbsLineRight, dxbsLineCenteredHorz, dxbsLineCenteredVert };

enum TdxBevelStyle : unsigned char { dxbsLowered, dxbsRaised };

enum TdxBreadcrumbEditButtonState : unsigned char { dxbcbsNormal, dxbcbsFocused, dxbcbsHot, dxbcbsPressed, dxbcbsDisabled };

enum TdxBreadcrumbEditState : unsigned char { dxbcsNormal, dxbcsFocused, dxbcsHot, dxbcsDisabled };

enum TcxEditCheckState : unsigned char { ecsNormal, ecsHot, ecsPressed, ecsDisabled };

enum TcxButtonState : unsigned char { cxbsDefault, cxbsNormal, cxbsHot, cxbsPressed, cxbsDisabled };

enum TcxCheckBoxState : unsigned char { cbsUnchecked, cbsChecked, cbsGrayed };

struct DECLSPEC_DRECORD TdxGalleryItemViewState
{
public:
	bool Enabled;
	bool Checked;
	bool Hover;
	bool Pressed;
	bool Focused;
};


enum TcxEditBtnKind : unsigned char { cxbkCloseBtn, cxbkComboBtn, cxbkEditorBtn, cxbkEllipsisBtn, cxbkSpinUpBtn, cxbkSpinDownBtn, cxbkSpinLeftBtn, cxbkSpinRightBtn };

enum TcxEditStateColorKind : unsigned char { esckNormal, esckDisabled, esckInactive, esckReadOnly };

enum TcxCalcButtonKind : unsigned char { cbBack, cbCancel, cbClear, cbMC, cbMR, cbMS, cbMP, cbNum0, cbNum1, cbNum2, cbNum3, cbNum4, cbNum5, cbNum6, cbNum7, cbNum8, cbNum9, cbSign, cbDecimal, cbDiv, cbMul, cbSub, cbAdd, cbSqrt, cbPercent, cbRev, cbEqual, cbNone };

enum TcxIndicatorKind : unsigned char { ikNone, ikArrow, ikEdit, ikInsert, ikMultiDot, ikMultiArrow, ikFilter };

enum TdxAlertWindowButtonKind : unsigned char { awbkClose, awbkPin, awbkDropdown, awbkPrevious, awbkNext, awbkCustom };

enum TcxFilterSmartTagState : unsigned char { fstsNormal, fstsHot, fstsPressed, fstsParentHot };

enum TcxContainerBorderStyle : unsigned char { cbsNone, cbsSingle, cbsThick, cbsFlat, cbs3D, cbsUltraFlat, cbsOffice11 };

enum TcxEditPopupBorderStyle : unsigned char { epbsDefault, epbsSingle, epbsFrame3D, epbsFlat };

enum TcxPopupBorderStyle : unsigned char { pbsNone, pbsUltraFlat, pbsFlat, pbs3D };

typedef bool __fastcall (__closure *TcxDrawBackgroundEvent)(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);

typedef void __fastcall (__closure *TdxDrawEvent)(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);

__interface IcxLookAndFeelPainterListener;
typedef System::DelphiInterface<IcxLookAndFeelPainterListener> _di_IcxLookAndFeelPainterListener;
class DELPHICLASS TcxCustomLookAndFeelPainter;
__interface  INTERFACE_UUID("{766FE270-2C4B-48B9-C9C7-882A62128A0C}") IcxLookAndFeelPainterListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall PainterAdded(TcxCustomLookAndFeelPainter* APainter) = 0 ;
	virtual void __fastcall PainterRemoved(TcxCustomLookAndFeelPainter* APainter) = 0 ;
};

class PASCALIMPLEMENTATION TcxCustomLookAndFeelPainter : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Dxgdiplusclasses::TdxSmartImage* FBackButton;
	Dxgdiplusclasses::TdxSmartImage* __fastcall GetBackButton(void);
	
protected:
	System::TObject* FLookAndFeelPainterDetailsCache;
	virtual System::TObject* __fastcall CreateLookAndFeelPainterDetails(void);
	virtual System::TObject* __fastcall GetLookAndFeelPainterDetails(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderHighlightTextColor(void);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TBitmap* const ABackgroundBitmap);
	virtual void __fastcall DrawButtonArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, int AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsFooter = false);
	void __fastcall DrawExpandButtonCross(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawFilterSmartTagGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxFilterSmartTagState AState, bool AIsFilterActive);
	void __fastcall DrawGroupExpandButtonMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, TcxButtonState AState);
	void __fastcall DrawMonthHeaderArrows(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxArrowDirections AArrows, int ASideWidth, System::Uitypes::TColor AColor);
	void __fastcall DrawSortingArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AAscendingSorting);
	void __fastcall DrawSummarySortingArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AAscendingSorting);
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, TcxButtonState AState);
	virtual System::Types::TRect __fastcall FooterCellContentBounds(const System::Types::TRect &ABounds);
	virtual System::Types::TRect __fastcall FooterCellTextAreaBounds(const System::Types::TRect &ABounds);
	TcxArrowDirection __fastcall GetArrowDirection(bool AHorizontal, TcxScrollBarPart APart);
	virtual System::Uitypes::TColor __fastcall GetFilterSmartTagColor(TcxFilterSmartTagState AState, bool AIsFilterActive);
	virtual System::Types::TRect __fastcall GetSeparatorBounds(const System::Types::TRect &R, int AWidth, bool AIsVertical);
	__property Dxgdiplusclasses::TdxSmartImage* BackButton = {read=GetBackButton};
	
public:
	__fastcall virtual ~TcxCustomLookAndFeelPainter(void);
	virtual bool __fastcall GetPainterData(void *AData);
	virtual bool __fastcall GetPainterDetails(void *ADetails);
	virtual bool __fastcall IsInternalPainter(void);
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual System::Uitypes::TColor __fastcall DefaultContentColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultContentEvenColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultContentOddColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultContentTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultEditorBackgroundColor(bool AIsDisabled);
	virtual System::Uitypes::TColor __fastcall DefaultEditorBackgroundColorEx(TcxEditStateColorKind AKind);
	virtual System::Uitypes::TColor __fastcall DefaultEditorTextColor(bool AIsDisabled);
	virtual System::Uitypes::TColor __fastcall DefaultEditorTextColorEx(TcxEditStateColorKind AKind);
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFixedSeparatorColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFooterColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFooterTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGridDetailsSiteColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGridLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGroupColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGroupTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultHeaderBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultHeaderBackgroundTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultHeaderTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultHyperlinkTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultInactiveColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultInactiveTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultPreviewTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultRecordSeparatorColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSizeGripAreaColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTreeListGridLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTreeListTreeLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridBandLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridCategoryColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridCategoryTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridHeaderTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorContentColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderTextColor(bool AIsHighlight);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHolydayTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorInactiveTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSelectionColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSelectionTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSeparator1Color(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSeparator2Color(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorTodayFrameColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorTodayTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerContentColor(int AResourceIndex);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerControlColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerEventColor(bool AIsAllDayEvent);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerNavigatorColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewSelectedTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerYearViewUnusedContentColor(bool AIsWorkTime);
	virtual System::Uitypes::TColor __fastcall DefaultSelectionColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSelectionTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSeparatorColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTabColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTabTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTabsBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultRootTabsBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMajorScaleColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMajorScaleTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMinorScaleColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMinorScaleTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridSelectionBarColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartDiagramValueBorderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartDiagramValueCaptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartHistogramAxisColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartHistogramGridLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartHistogramPlotColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartPieDiagramSeriesSiteBorderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartPieDiagramSeriesSiteCaptionColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartPieDiagramSeriesSiteCaptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartToolBoxDataLevelInfoBorderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartToolBoxItemSeparatorColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewCaptionTextColor(TcxGroupBoxCaptionPosition ACaptionPosition, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewContentColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewContentTextColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultGridOptionsTreeViewCategoryColor(bool ASelected);
	virtual System::Uitypes::TColor __fastcall DefaultGridOptionsTreeViewCategoryTextColor(bool ASelected);
	void __fastcall CalculateArrowPoints(System::Types::TRect &R, System::Types::TPoint *P, TcxArrowDirection AArrowDirection, bool AProportional, int AArrowSize = 0x0);
	virtual void __fastcall DrawArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxArrowDirection AArrowDirection, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall DrawArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxArrowDirection AArrowDirection, bool ADrawBorder = true)/* overload */;
	virtual void __fastcall DrawArrowBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawCollapseArrow(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, System::Uitypes::TColor AColor, int ALineWidth = 0x1);
	virtual void __fastcall DrawScrollBarArrow(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, TcxArrowDirection AArrowDirection);
	virtual int __fastcall BorderSize(void);
	virtual int __fastcall SeparatorSize(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DrawContainerBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxContainerBorderStyle AStyle, int AWidth, System::Uitypes::TColor AColor, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DoDrawSeparator(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AIsVertical);
	void __fastcall DrawSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AIsVertical);
	void __fastcall DrawPin(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor AColor, bool APinned);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Uitypes::TColor __fastcall ButtonColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall ButtonDescriptionTextColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual System::Types::TRect __fastcall ButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ButtonTextOffset(void);
	virtual int __fastcall ButtonTextShift(void);
	virtual TcxButtonState __fastcall ButtonSymbolState(TcxButtonState AState);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const System::UnicodeString ACaption, TcxButtonState AState, bool ADrawBorder = true, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), bool AWordWrap = false, bool AIsToolButton = false);
	virtual System::Uitypes::TColor __fastcall DefaultCommandLinkTextColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawCommandLinkBackground(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawCommandLinkGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint AGlyphPos, TcxButtonState AState);
	virtual System::Types::TSize __fastcall GetCommandLinkGlyphSize(void);
	virtual System::Types::TRect __fastcall GetCommandLinkMargins(void);
	void __fastcall DrawButtonCross(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor, TcxButtonState AState);
	virtual void __fastcall DrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawExpandButtonEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxgraphics::TcxRotationAngle ARotationAngle = (Cxgraphics::TcxRotationAngle)(0x0));
	virtual bool __fastcall DrawExpandButtonFirst(void);
	virtual void __fastcall DrawGroupExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, TcxButtonState AState);
	virtual void __fastcall DrawSmallExpandButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ExpandButtonAreaSize(void);
	virtual int __fastcall ExpandButtonSize(void);
	virtual int __fastcall GroupExpandButtonSize(void);
	virtual bool __fastcall IsButtonHotTrack(void);
	virtual bool __fastcall IsPointOverGroupExpandButton(const System::Types::TRect &R, const System::Types::TPoint P);
	virtual int __fastcall SmallExpandButtonSize(void);
	virtual void __fastcall DrawHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AIsGroup = false);
	virtual void __fastcall DrawHeaderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawHeaderBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawHeaderPressed(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawHeaderControlSection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawHeaderControlSectionBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, TcxButtonState AState);
	virtual void __fastcall DrawHeaderControlSectionContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawHeaderControlSectionText(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ATextAreaBounds, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor);
	virtual void __fastcall DrawHeaderSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, int AIndentSize, System::Uitypes::TColor AColor, Cxgraphics::TcxViewParams &AViewParams);
	virtual void __fastcall DrawSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual void __fastcall DrawSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual Cxgraphics::TcxBorders __fastcall HeaderBorders(TcxNeighbors ANeighbors);
	virtual int __fastcall HeaderBorderSize(void);
	virtual System::Types::TRect __fastcall HeaderBounds(const System::Types::TRect &ABounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual System::Types::TRect __fastcall HeaderContentBounds(const System::Types::TRect &ABounds, Cxgraphics::TcxBorders ABorders);
	virtual bool __fastcall HeaderDrawCellsFirst(void);
	virtual int __fastcall HeaderHeight(int AFontHeight);
	virtual int __fastcall HeaderControlSectionBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Types::TRect __fastcall HeaderControlSectionTextAreaBounds(System::Types::TRect &ABounds, TcxButtonState AState);
	virtual System::Types::TRect __fastcall HeaderControlSectionContentBounds(const System::Types::TRect &ABounds, TcxButtonState AState);
	virtual int __fastcall HeaderWidth(Cxgraphics::TcxCanvas* ACanvas, Cxgraphics::TcxBorders ABorders, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont);
	virtual bool __fastcall IsHeaderHotTrack(void);
	virtual System::Types::TPoint __fastcall SortingMarkAreaSize(void);
	virtual System::Types::TPoint __fastcall SortingMarkSize(void);
	virtual System::Types::TPoint __fastcall SummarySortingMarkSize(void);
	virtual void __fastcall DrawGroupByBox(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TBitmap* const ABackgroundBitmap);
	virtual int __fastcall GridBordersOverlapSize(void);
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11ContentColor(bool AHasData);
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11SeparatorColor(void);
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11TextColor(void);
	virtual bool __fastcall GridDrawHeaderCellsFirst(void);
	virtual System::Uitypes::TColor __fastcall PivotGridHeadersAreaColor(void);
	virtual System::Uitypes::TColor __fastcall PivotGridHeadersAreaTextColor(void);
	virtual void __fastcall LayoutViewDrawItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() );
	virtual void __fastcall LayoutViewDrawRecordCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition APosition, TcxButtonState AState);
	virtual void __fastcall LayoutViewDrawRecordBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() );
	virtual void __fastcall LayoutViewDrawRecordContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxGroupBoxCaptionPosition ACaptionPosition, TcxButtonState AState, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall LayoutViewDrawRecordExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, bool AExpanded);
	virtual System::Types::TRect __fastcall LayoutViewGetPadding(TcxLayoutElement AElement);
	virtual System::Types::TRect __fastcall LayoutViewGetSpacing(TcxLayoutElement AElement);
	virtual int __fastcall LayoutViewRecordCaptionTailSize(TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual int __fastcall ChartToolBoxDataLevelInfoBorderSize(void);
	virtual Cxgraphics::TcxBorders __fastcall FooterBorders(void);
	virtual int __fastcall FooterBorderSize(void);
	virtual int __fastcall FooterCellBorderSize(void);
	virtual int __fastcall FooterCellOffset(void);
	virtual bool __fastcall FooterDrawCellsFirst(void);
	virtual System::Uitypes::TColor __fastcall FooterSeparatorColor(void);
	virtual int __fastcall FooterSeparatorSize(void);
	void __fastcall DrawFooterPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawFooterCell(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawFooterCellContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFooterBorderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFooterContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const Cxgraphics::TcxViewParams &AViewParams);
	virtual void __fastcall DrawFooterSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFilterActivateButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, bool AChecked);
	virtual void __fastcall DrawFilterCloseButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive);
	virtual void __fastcall DrawFilterPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TBitmap* const ABackgroundBitmap);
	virtual void __fastcall DrawFilterSmartTag(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxFilterSmartTagState AState, bool AIsFilterActive);
	virtual System::Types::TPoint __fastcall FilterActivateButtonSize(void);
	virtual System::Types::TPoint __fastcall FilterCloseButtonSize(void);
	virtual System::Types::TPoint __fastcall FilterDropDownButtonSize(void);
	virtual System::Types::TSize __fastcall FilterSmartTagSize(void);
	virtual System::Uitypes::TColor __fastcall GetWindowContentTextColor(void);
	virtual void __fastcall DrawWindowContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawEditPopupWindowBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxEditPopupBorderStyle ABorderStyle, bool AClientEdge);
	virtual int __fastcall GetEditPopupWindowBorderWidth(TcxEditPopupBorderStyle AStyle);
	virtual int __fastcall GetEditPopupWindowClientEdgeWidth(TcxEditPopupBorderStyle AStyle);
	virtual TcxPopupBorderStyle __fastcall PopupBorderStyle(void);
	virtual System::Uitypes::TColor __fastcall GetHintBorderColor(void);
	virtual void __fastcall DrawHintBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual System::Uitypes::TColor __fastcall ScreenTipGetDescriptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall ScreenTipGetTitleTextColor(void);
	virtual int __fastcall ScreenTipGetFooterLineSize(void);
	virtual void __fastcall ScreenTipDrawBackground(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect);
	virtual void __fastcall ScreenTipDrawFooterLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTab(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, const System::UnicodeString AText, TcxButtonState AState, bool AVertical, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, bool AShowPrefix = false);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgraphics::TcxBorder ABorder, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual bool __fastcall IsDrawTabImplemented(bool AVertical);
	virtual bool __fastcall IsTabHotTrack(bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual void __fastcall DrawIndicatorCustomizationMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawIndicatorImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind);
	virtual void __fastcall DrawIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawIndicatorItemEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual bool __fastcall IndicatorDrawItemsFirst(void);
	virtual int __fastcall ScrollBarMinimalThumbSize(bool AVertical);
	virtual void __fastcall DrawScrollBarBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, bool AHorizontal, System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState);
	int __fastcall PopupPanelSize(void);
	void __fastcall CalculatePopupPanelClientRect(System::Types::TRect &AClientRect, System::Types::TRect &APanelRect, System::Types::TRect &AGripRect, System::Types::TRect &ACloseButtonRect, Dxcore::TdxCorner ACorner, const System::Types::TRect &ABorders, const System::Types::TRect &APanelBorders, int APanelHeight = 0x0, bool AShowCloseButton = true, bool AShowGripSize = true);
	void __fastcall DrawPopupNCPanel(HWND AHandle, bool AMouseAboveCloseButton, bool ACloseButtonIsTracking, Dxcore::TdxCorner ACorner, System::Types::TRect &ACloseButtonRect, System::Types::TRect &AGripRect, System::Uitypes::TColor ABorderColor);
	void __fastcall DrawPopupPanelBand(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AGripRect, const System::Types::TRect &ACloseButtonRect, Dxcore::TdxCorner AGripCorner, TcxButtonState ACloseButtonState, System::Types::TRect &ABorders, System::Uitypes::TColor ABorderColor, bool AShowGripSize = true, bool AShowCloseButton = true);
	virtual System::Types::TSize __fastcall SizeGripSize(void);
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackgroundColor = (System::Uitypes::TColor)(0x20000000), Dxcore::TdxCorner ACorner = (Dxcore::TdxCorner)(0x3));
	virtual System::Types::TSize __fastcall SliderButtonSize(TcxArrowDirection ADirection);
	virtual void __fastcall DrawSliderButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxArrowDirection ADirection, TcxButtonState AState);
	virtual System::Types::TSize __fastcall SmallCloseButtonSize(void);
	virtual void __fastcall DrawSmallButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawSmallCloseButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall CalculateSchedulerNavigationButtonRects(bool AIsNextButton, bool ACollapsed, System::Types::TSize APrevButtonTextSize, System::Types::TSize ANextButtonTextSize, System::Types::TRect &ABounds, /* out */ System::Types::TRect &ATextRect, /* out */ System::Types::TRect &AArrowRect);
	virtual void __fastcall DrawMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, TcxArrowDirections AArrows, int ASideWidth, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DrawSchedulerEventProgress(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AProgress, Cxgraphics::TcxViewParams &AViewParams, bool ATransparent);
	virtual void __fastcall DrawSchedulerGroup(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawSchedulerGroupSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor ABackgroundColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerMilestone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawSchedulerNavigationButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsNextButton, TcxButtonState AState, const System::UnicodeString AText, const System::Types::TRect &ATextRect, const System::Types::TRect &AArrowRect);
	virtual void __fastcall DrawSchedulerNavigationButtonArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AIsNextButton, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawSchedulerNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual System::Types::TRect __fastcall SchedulerEventProgressOffsets(void);
	virtual System::Uitypes::TColor __fastcall SchedulerNavigationButtonTextColor(bool AIsNextButton, TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall SchedulerNavigationButtonSizes(bool AIsNextButton, System::Types::TRect &ABorders, System::Types::TSize &AArrowSize, bool &AHasTextArea);
	virtual void __fastcall DrawEditorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxEditBtnKind AButtonKind, TcxButtonState AState, TcxEditBtnPosition APosition = (TcxEditBtnPosition)(0x1));
	virtual void __fastcall DrawEditorButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxEditBtnKind AButtonKind, TcxButtonState AState, TcxEditBtnPosition APosition = (TcxEditBtnPosition)(0x1));
	virtual int __fastcall EditButtonTextOffset(void);
	virtual System::Types::TSize __fastcall EditButtonSize(void);
	virtual System::Uitypes::TColor __fastcall EditButtonTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetContainerBorderColor(bool AIsHighlightBorder);
	virtual int __fastcall GetContainerBorderWidth(TcxContainerBorderStyle ABorderStyle);
	virtual System::Types::TSize __fastcall ClockSize(void);
	virtual void __fastcall DrawClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor ABackgroundColor);
	virtual System::Types::TSize __fastcall GetZoomInButtonSize(void);
	virtual System::Types::TSize __fastcall GetZoomOutButtonSize(void);
	virtual void __fastcall DrawZoomInButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawZoomOutButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual System::Types::TSize __fastcall GetBackButtonSize(void);
	virtual void __fastcall DrawBackButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DrawNavigatorBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool ASelected);
	virtual void __fastcall DrawNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor ABackgroundColor);
	virtual void __fastcall DrawNavigatorButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImageList, System::Uitypes::TImageIndex AImageIndex, const System::Types::TRect &AGlyphRect, bool AEnabled, bool AUserGlyphs);
	virtual bool __fastcall NavigatorBorderOverlap(void);
	virtual int __fastcall NavigatorBorderSize(void);
	virtual System::Types::TRect __fastcall NavigatorButtonGlyphPadding(void);
	virtual System::Types::TSize __fastcall NavigatorButtonGlyphSize(void);
	virtual System::Types::TPoint __fastcall NavigatorButtonPressedGlyphOffset(void);
	virtual System::Types::TSize __fastcall NavigatorButtonMinSize(void);
	virtual void __fastcall DrawProgressBarBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AVertical);
	virtual void __fastcall DrawProgressBarChunk(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AVertical);
	virtual void __fastcall DrawProgressBarText(Cxgraphics::TcxCanvas* ACanvas, bool AVertical, bool ASolid, const System::UnicodeString AText, const System::Types::TRect &ATextRect, const System::Types::TRect &AProgressBarRect, const System::Types::TRect &AProgressChunkRect, System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000));
	virtual System::Types::TRect __fastcall ProgressBarBorderSize(bool AVertical);
	virtual System::Uitypes::TColor __fastcall ProgressBarTextColor(void);
	virtual System::Uitypes::TColor __fastcall ProgressBarTextColorEx(bool AIsFilledArea);
	virtual void __fastcall DrawGroupBoxBackground(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ABounds, System::Types::TRect &ARect);
	virtual void __fastcall DrawGroupBoxCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawGroupBoxContent(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ABorderRect, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall DrawGroupBoxExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AExpanded, Cxgraphics::TcxRotationAngle ARotationAngle = (Cxgraphics::TcxRotationAngle)(0x0));
	virtual void __fastcall DrawGroupBoxFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual System::Types::TRect __fastcall GroupBoxBorderSize(bool ACaption, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual int __fastcall GroupBoxCaptionTailSize(TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual System::Uitypes::TColor __fastcall GroupBoxTextColor(bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual bool __fastcall IsGroupBoxCaptionTextDrawnOverBorder(TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual bool __fastcall IsGroupBoxTransparent(bool AIsCaption, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual System::Types::TSize __fastcall CheckButtonAreaSize(void);
	virtual int __fastcall CheckBorderSize(void);
	virtual System::Uitypes::TColor __fastcall CheckButtonColor(TcxButtonState AState, TcxCheckBoxState ACheckState);
	virtual System::Types::TSize __fastcall CheckButtonSize(void);
	virtual void __fastcall DrawCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall DrawCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall DrawCheckBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawCheckButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, bool AChecked)/* overload */;
	virtual void __fastcall DrawCheckButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState)/* overload */;
	virtual void __fastcall DrawRadioButton(Cxgraphics::TcxCanvas* ACanvas, int X, int Y, TcxButtonState AButtonState, bool AChecked, bool AFocused, System::Uitypes::TColor ABrushColor, bool AIsDesigning = false);
	virtual System::Uitypes::TColor __fastcall RadioButtonBodyColor(TcxButtonState AState);
	virtual System::Types::TSize __fastcall RadioButtonSize(void);
	virtual void __fastcall DrawLabelLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AOuterColor, System::Uitypes::TColor AInnerColor, bool AIsVertical);
	virtual int __fastcall LabelLineHeight(void);
	virtual void __fastcall DrawPanelBackground(Cxgraphics::TcxCanvas* ACanvas, Vcl::Controls::TWinControl* AControl, System::Types::TRect &ABounds, System::Uitypes::TColor AColorFrom = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor AColorTo = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawPanelBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect);
	virtual void __fastcall DrawPanelCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawPanelContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, bool ABorder);
	virtual System::Types::TRect __fastcall PanelBorderSize(void);
	virtual System::Uitypes::TColor __fastcall PanelTextColor(void);
	virtual void __fastcall CorrectThumbRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AHorizontal, TcxTrackBarTicksAlign ATicks);
	virtual void __fastcall DrawTrackBarTrack(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &ASelection, bool AShowSelection, bool AEnabled, bool AHorizontal, System::Uitypes::TColor ATrackColor);
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Cxgraphics::TPointArray ALightPolyLine, const Cxgraphics::TPointArray AShadowPolyLine, const Cxgraphics::TPointArray ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual System::Types::TSize __fastcall TrackBarThumbSize(bool AHorizontal);
	virtual System::Uitypes::TColor __fastcall TrackBarTicksColor(bool AText);
	virtual int __fastcall TrackBarTrackSize(void);
	virtual System::Uitypes::TColor __fastcall GetSplitterInnerColor(bool AHighlighted);
	virtual System::Uitypes::TColor __fastcall GetSplitterOuterColor(bool AHighlighted);
	virtual void __fastcall DrawSplitter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHighlighted, bool AClicked, bool AHorizontal);
	virtual System::Types::TSize __fastcall GetSplitterSize(bool AHorizontal);
	virtual System::Uitypes::TColor __fastcall LayoutControlEmptyAreaColor(void);
	virtual void __fastcall DrawLayoutControlBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawScrollBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual System::Types::TRect __fastcall PrintPreviewPageBordersWidth(void);
	virtual void __fastcall DrawPrintPreviewBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawPrintPreviewPageBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, const System::Types::TRect &AContentRect, bool ASelected, bool ADrawContent);
	virtual System::Uitypes::TColor __fastcall CalcEditButtonTextColor(TcxCalcButtonKind AButtonKind);
	virtual System::Uitypes::TColor __fastcall GetCustomizationFormListBackgroundColor(void);
	virtual void __fastcall DrawMessageBox(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AMessage, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x1fffffff));
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditBackgroundColor(TdxBreadcrumbEditState AState);
	virtual System::Types::TRect __fastcall BreadcrumbEditBordersSize(void);
	virtual int __fastcall BreadcrumbEditButtonAreaSeparatorSize(void);
	virtual System::Types::TRect __fastcall BreadcrumbEditButtonContentOffsets(bool AIsFirst, bool AIsLast);
	virtual int __fastcall BreadcrumbEditDropDownButtonOriginalWidth(void);
	virtual int __fastcall BreadcrumbEditDropDownButtonWidth(void);
	virtual bool __fastcall BreadcrumbEditIsFadingSupports(void);
	virtual int __fastcall BreadcrumbEditNodeDelimiterSize(void);
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditNodeTextColor(TdxBreadcrumbEditButtonState AState);
	virtual System::Types::TRect __fastcall BreadcrumbEditNodeTextOffsets(void);
	virtual System::Types::TSize __fastcall BreadcrumbEditProgressChunkOverlaySize(void);
	virtual System::Types::TRect __fastcall BreadcrumbEditProgressChunkPadding(void);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditButtonAreaSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast);
	virtual void __fastcall DrawBreadcrumbEditDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor);
	virtual void __fastcall DrawBreadcrumbEditDropDownButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor);
	virtual void __fastcall DrawBreadcrumbEditNode(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, bool AHasDelimiter);
	virtual void __fastcall DrawBreadcrumbEditNodeDelimiter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditNodeDelimiterGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditNodeMoreButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditProgressChunk(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawBreadcrumbEditProgressChunkOverlay(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	virtual void __fastcall DrawDropDownListBoxGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawDropDownListBoxSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual void __fastcall DrawDropDownListBoxSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual int __fastcall DropDownListBoxBordersSize(void);
	virtual System::Types::TRect __fastcall DropDownListBoxItemImageOffsets(void);
	virtual System::Uitypes::TColor __fastcall DropDownListBoxItemTextColor(bool ASelected);
	virtual System::Types::TRect __fastcall DropDownListBoxItemTextOffsets(void);
	virtual int __fastcall DropDownListBoxSeparatorSize(void);
	virtual System::Types::TRect __fastcall AlertWindowButtonContentOffsets(TdxAlertWindowButtonKind AKind);
	virtual System::Types::TSize __fastcall AlertWindowButtonGlyphSize(TdxAlertWindowButtonKind AKind);
	virtual System::Types::TRect __fastcall AlertWindowContentOffsets(void);
	virtual int __fastcall AlertWindowCornerRadius(void);
	virtual System::Uitypes::TColor __fastcall AlertWindowNavigationPanelTextColor(void);
	virtual System::Uitypes::TColor __fastcall AlertWindowTextColor(void);
	virtual void __fastcall DrawAlertWindowBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawAlertWindowButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, TdxAlertWindowButtonKind AKind, bool ADown = false);
	virtual void __fastcall DrawAlertWindowNavigationPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual System::Types::TRect __fastcall GetGalleryGroupHeaderContentOffsets(void);
	virtual System::Uitypes::TColor __fastcall GetGalleryGroupTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetGalleryItemCaptionTextColor(const TdxGalleryItemViewState AState);
	virtual System::Uitypes::TColor __fastcall GetGalleryItemDescriptionTextColor(const TdxGalleryItemViewState AState);
	virtual System::Uitypes::TColor __fastcall GetGalleryItemImageFrameColor(void);
	virtual void __fastcall DrawGalleryBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawGalleryGroupHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual bool __fastcall DrawGalleryItemSelectionFirst(void);
	virtual void __fastcall DrawGalleryItemSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxGalleryItemViewState AViewState);
	virtual void __fastcall DrawGalleryItemImageFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetColorGalleryGlyphFrameColor(void);
	virtual void __fastcall DrawColorGalleryItemSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxGalleryItemViewState AViewState);
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(TdxBevelShape AShape);
	virtual void __fastcall GetBevelShapeColors(/* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	virtual void __fastcall DrawBevelFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool ABoxStyle);
	virtual void __fastcall DrawBevelLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AIsVertical);
	virtual void __fastcall DrawBevelShape(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBevelShape AShape, TdxBevelStyle AStyle);
public:
	/* TObject.Create */ inline __fastcall TcxCustomLookAndFeelPainter(void) : System::Classes::TPersistent() { }
	
};


typedef System::TMetaClass* TcxCustomLookAndFeelPainterClass;

class DELPHICLASS TcxStandardLookAndFeelPainter;
class PASCALIMPLEMENTATION TcxStandardLookAndFeelPainter : public TcxCustomLookAndFeelPainter
{
	typedef TcxCustomLookAndFeelPainter inherited;
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle(void);
	virtual int __fastcall BorderSize(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual int __fastcall ButtonTextOffset(void);
	virtual int __fastcall ButtonTextShift(void);
	virtual void __fastcall DrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawGroupExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, TcxButtonState AState);
	virtual int __fastcall ExpandButtonSize(void);
	virtual void __fastcall DrawExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual bool __fastcall IsButtonHotTrack(void);
	virtual void __fastcall DrawCheckBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawHeaderBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawHeaderControlSectionBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, TcxButtonState AState);
	virtual void __fastcall DrawSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual void __fastcall DrawSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual int __fastcall HeaderBorderSize(void);
	virtual int __fastcall HeaderControlSectionBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Types::TPoint __fastcall SortingMarkSize(void);
	virtual System::Types::TPoint __fastcall SummarySortingMarkSize(void);
	virtual int __fastcall FooterBorderSize(void);
	virtual int __fastcall FooterCellBorderSize(void);
	virtual int __fastcall FooterCellOffset(void);
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgraphics::TcxBorder ABorder, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, bool AHorizontal, System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColor(void);
	virtual void __fastcall DrawMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, TcxArrowDirections AArrows, int ASideWidth, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual void __fastcall DrawGroupBoxFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Cxgraphics::TPointArray ALightPolyLine, const Cxgraphics::TPointArray AShadowPolyLine, const Cxgraphics::TPointArray ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawBreadcrumbEditButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast);
public:
	/* TcxCustomLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TcxStandardLookAndFeelPainter(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxStandardLookAndFeelPainter(void) : TcxCustomLookAndFeelPainter() { }
	
};


class DELPHICLASS TcxFlatLookAndFeelPainter;
class PASCALIMPLEMENTATION TcxFlatLookAndFeelPainter : public TcxCustomLookAndFeelPainter
{
	typedef TcxCustomLookAndFeelPainter inherited;
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle(void);
	virtual int __fastcall BorderSize(void);
	virtual int __fastcall SeparatorSize(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual int __fastcall ButtonTextOffset(void);
	virtual int __fastcall ButtonTextShift(void);
	virtual void __fastcall DrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ExpandButtonSize(void);
	virtual bool __fastcall IsButtonHotTrack(void);
	virtual void __fastcall DrawCheckBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawHeaderBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawHeaderControlSectionBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, TcxButtonState AState);
	virtual void __fastcall DrawSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual void __fastcall DrawSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual int __fastcall HeaderBorderSize(void);
	virtual System::Types::TPoint __fastcall SortingMarkSize(void);
	virtual System::Types::TPoint __fastcall SummarySortingMarkSize(void);
	virtual int __fastcall FooterBorderSize(void);
	virtual int __fastcall FooterCellBorderSize(void);
	virtual int __fastcall FooterCellOffset(void);
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgraphics::TcxBorder ABorder, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, bool AHorizontal, System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual void __fastcall DrawGroupBoxFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Cxgraphics::TPointArray ALightPolyLine, const Cxgraphics::TPointArray AShadowPolyLine, const Cxgraphics::TPointArray ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetSplitterOuterColor(bool AHighlighted);
public:
	/* TcxCustomLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TcxFlatLookAndFeelPainter(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxFlatLookAndFeelPainter(void) : TcxCustomLookAndFeelPainter() { }
	
};


class DELPHICLASS TcxUltraFlatLookAndFeelPainter;
class PASCALIMPLEMENTATION TcxUltraFlatLookAndFeelPainter : public TcxCustomLookAndFeelPainter
{
	typedef TcxCustomLookAndFeelPainter inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall FilterDropDownButtonBorderColor(TcxButtonState AState);
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, TcxButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditCustomButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgraphics::TcxBorders ABorders);
	virtual System::Uitypes::TColor __fastcall TabBorderHighlightColor(void);
	virtual System::Uitypes::TColor __fastcall TabBorderDarkColor(void);
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor(void);
	virtual System::Uitypes::TColor __fastcall BorderHighlightColor(void);
	virtual int __fastcall BorderSize(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DoDrawSeparator(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AIsVertical);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Uitypes::TColor __fastcall ButtonColor(TcxButtonState AState);
	virtual System::Types::TRect __fastcall ButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual TcxButtonState __fastcall ButtonSymbolState(TcxButtonState AState);
	virtual int __fastcall ButtonTextOffset(void);
	virtual int __fastcall ButtonTextShift(void);
	virtual void __fastcall DrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawHeaderControlSectionBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, TcxButtonState AState);
	virtual void __fastcall DrawHeaderControlSectionContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual int __fastcall ExpandButtonSize(void);
	virtual bool __fastcall IsButtonHotTrack(void);
	virtual void __fastcall DrawCheckBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall RadioButtonBodyColor(TcxButtonState AState);
	virtual void __fastcall DrawHeaderBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawHeaderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual void __fastcall DrawSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual Cxgraphics::TcxBorders __fastcall HeaderBorders(TcxNeighbors ANeighbors);
	virtual int __fastcall HeaderBorderSize(void);
	virtual System::Types::TPoint __fastcall SortingMarkSize(void);
	virtual System::Types::TPoint __fastcall SummarySortingMarkSize(void);
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFooterBorderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual Cxgraphics::TcxBorders __fastcall FooterBorders(void);
	virtual int __fastcall FooterBorderSize(void);
	virtual int __fastcall FooterCellBorderSize(void);
	virtual int __fastcall FooterCellOffset(void);
	virtual void __fastcall DrawFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive);
	virtual System::Types::TPoint __fastcall FilterCloseButtonSize(void);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgraphics::TcxBorder ABorder, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, bool AHorizontal, System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState);
	virtual void __fastcall DrawSchedulerNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual void __fastcall DrawGroupBoxFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Cxgraphics::TPointArray ALightPolyLine, const Cxgraphics::TPointArray AShadowPolyLine, const Cxgraphics::TPointArray ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawPrintPreviewBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetSplitterOuterColor(bool AHighlighted);
	virtual System::Types::TSize __fastcall GetSplitterSize(bool AHorizontal);
	virtual void __fastcall DrawNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor ABackgroundColor);
	virtual void __fastcall DrawNavigatorBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool ASelected);
	virtual bool __fastcall NavigatorBorderOverlap(void);
	virtual int __fastcall NavigatorBorderSize(void);
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	virtual void __fastcall DrawDropDownListBoxGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawDropDownListBoxSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual void __fastcall DrawDropDownListBoxSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual System::Uitypes::TColor __fastcall DropDownListBoxItemTextColor(bool ASelected);
	virtual int __fastcall BreadcrumbEditButtonAreaSeparatorSize(void);
	virtual System::Types::TRect __fastcall BreadcrumbEditButtonContentOffsets(bool AIsFirst, bool AIsLast);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditButtonAreaSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast);
	virtual void __fastcall DrawBreadcrumbEditDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor);
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(TdxBevelShape AShape);
	virtual void __fastcall GetBevelShapeColors(/* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	virtual int __fastcall GridBordersOverlapSize(void);
public:
	/* TcxCustomLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TcxUltraFlatLookAndFeelPainter(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxUltraFlatLookAndFeelPainter(void) : TcxCustomLookAndFeelPainter() { }
	
};


class DELPHICLASS TcxOffice11LookAndFeelPainter;
class PASCALIMPLEMENTATION TcxOffice11LookAndFeelPainter : public TcxUltraFlatLookAndFeelPainter
{
	typedef TcxUltraFlatLookAndFeelPainter inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderHighlightTextColor(void);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, int AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsFooter = false);
	virtual System::Uitypes::TColor __fastcall HeaderBottomColor(void);
	virtual System::Uitypes::TColor __fastcall HeaderDarkEdgeColor(void);
	virtual System::Uitypes::TColor __fastcall HeaderHighlightEdgeColor(void);
	virtual System::Uitypes::TColor __fastcall HeaderTopColor(void);
	virtual System::Uitypes::TColor __fastcall FilterDropDownButtonBorderColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall TabBorderHighlightColor(void);
	virtual System::Uitypes::TColor __fastcall TabBorderDarkColor(void);
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, TcxButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditCustomButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgraphics::TcxBorders ABorders);
	
public:
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSelectionColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultDateNavigatorSelectionTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFooterColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFooterTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGroupColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGroupByBoxTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultHeaderBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerControlColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTabColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTabsBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMinorScaleColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridSelectionBarColor(void);
	virtual int __fastcall SeparatorSize(void);
	virtual System::Uitypes::TColor __fastcall BorderHighlightColor(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DoDrawSeparator(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AIsVertical);
	virtual System::Uitypes::TColor __fastcall ButtonColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawButtonBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual bool __fastcall DrawExpandButtonFirst(void);
	virtual void __fastcall DrawSmallExpandButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ExpandButtonSize(void);
	virtual int __fastcall SmallExpandButtonSize(void);
	virtual System::Uitypes::TColor __fastcall CheckButtonColor(TcxButtonState AState, TcxCheckBoxState ACheckState);
	virtual System::Uitypes::TColor __fastcall RadioButtonBodyColor(TcxButtonState AState);
	virtual void __fastcall DrawFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive);
	virtual void __fastcall DrawHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AInGroupByBox = false);
	virtual void __fastcall DrawHeaderBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawHeaderControlSection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual void __fastcall DrawSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual Cxgraphics::TcxBorders __fastcall HeaderBorders(TcxNeighbors ANeighbors);
	virtual int __fastcall HeaderBorderSize(void);
	virtual bool __fastcall IsHeaderHotTrack(void);
	virtual System::Uitypes::TColor __fastcall FooterSeparatorColor(void);
	virtual int __fastcall GridBordersOverlapSize(void);
	virtual void __fastcall LayoutViewDrawRecordCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition APosition, TcxButtonState AState);
	virtual int __fastcall ScrollBarMinimalThumbSize(bool AVertical);
	virtual void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, bool AHorizontal, System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState);
	virtual void __fastcall DrawMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, TcxArrowDirections AArrows, int ASideWidth, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawSchedulerBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawGroupBoxFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual System::Uitypes::TColor __fastcall GroupBoxTextColor(bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawTrackBarTrackBounds(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawTrackBarThumbBorderUpDown(Cxgraphics::TcxCanvas* ACanvas, const Cxgraphics::TPointArray ALightPolyLine, const Cxgraphics::TPointArray AShadowPolyLine, const Cxgraphics::TPointArray ADarkPolyLine);
	virtual void __fastcall DrawTrackBarThumbBorderBoth(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawPanelBackground(Cxgraphics::TcxCanvas* ACanvas, Vcl::Controls::TWinControl* AControl, System::Types::TRect &ABounds, System::Uitypes::TColor AColorFrom = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor AColorTo = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawLayoutControlBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetSplitterInnerColor(bool AHighlighted);
	virtual System::Uitypes::TColor __fastcall GetSplitterOuterColor(bool AHighlighted);
	virtual int __fastcall NavigatorBorderSize(void);
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditBackgroundColor(TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	virtual void __fastcall DrawDropDownListBoxGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawDropDownListBoxSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual void __fastcall DrawDropDownListBoxSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual void __fastcall DrawAlertWindowBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(TdxBevelShape AShape);
	virtual void __fastcall GetBevelShapeColors(/* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
public:
	/* TcxCustomLookAndFeelPainter.Destroy */ inline __fastcall virtual ~TcxOffice11LookAndFeelPainter(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxOffice11LookAndFeelPainter(void) : TcxUltraFlatLookAndFeelPainter() { }
	
};


class DELPHICLASS TcxWinXPLookAndFeelPainter;
class PASCALIMPLEMENTATION TcxWinXPLookAndFeelPainter : public TcxStandardLookAndFeelPainter
{
	typedef TcxStandardLookAndFeelPainter inherited;
	
private:
	Cxgraphics::TcxBitmap32* FZoomInButtonGlyph;
	Cxgraphics::TcxBitmap32* FZoomOutButtonGlyph;
	
protected:
	virtual void __fastcall DrawBreadcrumbEditNodePart(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, Cxgraphics::TcxBorders ABorders);
	HIDESBASE virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, NativeUInt ATheme, int APartId, int AStateId, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, bool AShowPrefix, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, TcxButtonState AState);
	void __fastcall DrawThemedTab(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, const System::UnicodeString AText, NativeUInt ATheme, int AState, bool AVertical, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, bool AShowPrefix = false);
	bool __fastcall NativeZoomButtonDraw(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, Vcl::Graphics::TBitmap* AGlyph);
	bool __fastcall NativeZoomButtonGetMinSize(Vcl::Graphics::TBitmap* AGlyph, /* out */ System::Types::TSize &ASize);
	__property Cxgraphics::TcxBitmap32* ZoomInButtonGlyph = {read=FZoomInButtonGlyph};
	__property Cxgraphics::TcxBitmap32* ZoomOutButtonGlyph = {read=FZoomOutButtonGlyph};
	
public:
	__fastcall virtual ~TcxWinXPLookAndFeelPainter(void);
	virtual void __fastcall AfterConstruction(void);
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
	virtual TcxLookAndFeelStyle __fastcall LookAndFeelStyle(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor(void);
	virtual void __fastcall DrawArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxArrowDirection AArrowDirection, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall DrawArrow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxArrowDirection AArrowDirection, bool ADrawBorder = true)/* overload */;
	virtual void __fastcall DrawArrowBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual int __fastcall BorderSize(void);
	virtual int __fastcall SeparatorSize(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DoDrawSeparator(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AIsVertical);
	virtual int __fastcall ButtonBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Uitypes::TColor __fastcall ButtonColor(TcxButtonState AState);
	virtual System::Types::TRect __fastcall ButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ButtonTextOffset(void);
	virtual int __fastcall ButtonTextShift(void);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const System::UnicodeString ACaption, TcxButtonState AState, bool ADrawBorder = true, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), bool AWordWrap = false, bool AIsToolButton = false);
	virtual System::Uitypes::TColor __fastcall DefaultCommandLinkTextColor(TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawCommandLinkBackground(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawCommandLinkGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TPoint AGlyphPos, TcxButtonState AState);
	virtual System::Types::TSize __fastcall GetCommandLinkGlyphSize(void);
	virtual System::Types::TRect __fastcall GetCommandLinkMargins(void);
	virtual void __fastcall DrawExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual bool __fastcall DrawExpandButtonFirst(void);
	virtual void __fastcall DrawGroupExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, TcxButtonState AState);
	virtual void __fastcall DrawSmallButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawSmallExpandButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ExpandButtonSize(void);
	virtual int __fastcall GroupExpandButtonSize(void);
	virtual int __fastcall SmallExpandButtonSize(void);
	virtual bool __fastcall IsButtonHotTrack(void);
	virtual bool __fastcall IsPointOverGroupExpandButton(const System::Types::TRect &R, const System::Types::TPoint P);
	virtual int __fastcall CheckBorderSize(void);
	virtual System::Types::TSize __fastcall CheckButtonSize(void);
	virtual void __fastcall DrawCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, TcxCheckBoxState ACheckState, System::Uitypes::TColor AColor)/* overload */;
	virtual void __fastcall DrawCheckBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawRadioButton(Cxgraphics::TcxCanvas* ACanvas, int X, int Y, TcxButtonState AButtonState, bool AChecked, bool AFocused, System::Uitypes::TColor ABrushColor, bool AIsDesigning = false);
	virtual System::Types::TSize __fastcall RadioButtonSize(void);
	virtual System::Types::TSize __fastcall GetBackButtonSize(void);
	virtual void __fastcall DrawBackButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual System::Types::TSize __fastcall GetZoomInButtonSize(void);
	virtual System::Types::TSize __fastcall GetZoomOutButtonSize(void);
	virtual void __fastcall DrawZoomInButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawZoomOutButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AInGroupByBox = false);
	virtual void __fastcall DrawHeaderPressed(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawHeaderControlSection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual void __fastcall DrawSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual int __fastcall HeaderBorderSize(void);
	virtual int __fastcall HeaderControlSectionBorderSize(TcxButtonState AState = (TcxButtonState)(0x1));
	virtual System::Types::TRect __fastcall HeaderControlSectionContentBounds(const System::Types::TRect &ABounds, TcxButtonState AState);
	virtual bool __fastcall IsHeaderHotTrack(void);
	virtual System::Types::TPoint __fastcall SortingMarkSize(void);
	virtual void __fastcall DrawFooterBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFooterCell(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual int __fastcall FooterBorderSize(void);
	virtual int __fastcall FooterCellBorderSize(void);
	virtual int __fastcall FooterCellOffset(void);
	virtual bool __fastcall FooterDrawCellsFirst(void);
	virtual void __fastcall DrawFilterCloseButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState, bool AIsFilterActive);
	virtual System::Types::TPoint __fastcall FilterActivateButtonSize(void);
	virtual System::Types::TPoint __fastcall FilterCloseButtonSize(void);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewContentTextColor(TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewCaptionTextColor(TcxGroupBoxCaptionPosition ACaptionPosition, TcxButtonState AState);
	virtual void __fastcall LayoutViewDrawRecordCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextRect, TcxGroupBoxCaptionPosition APosition, TcxButtonState AState);
	virtual void __fastcall LayoutViewDrawItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, TcxButtonState AState, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() );
	virtual void __fastcall DrawTab(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, const System::UnicodeString AText, TcxButtonState AState, bool AVertical, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, bool AShowPrefix = false);
	virtual void __fastcall DrawTabBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxgraphics::TcxBorder ABorder, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual void __fastcall DrawTabsRoot(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders, bool AVertical);
	virtual bool __fastcall IsDrawTabImplemented(bool AVertical);
	virtual bool __fastcall IsTabHotTrack(bool AVertical);
	virtual int __fastcall TabBorderSize(bool AVertical);
	virtual void __fastcall DrawSplitter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHighlighted, bool AClicked, bool AHorizontal);
	virtual void __fastcall DrawIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxIndicatorKind AKind, System::Uitypes::TColor AColor, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual int __fastcall ScrollBarMinimalThumbSize(bool AVertical);
	virtual void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, bool AHorizontal, System::Types::TRect &R, TcxScrollBarPart APart, TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColor(void);
	virtual void __fastcall DrawMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, TcxArrowDirections AArrows, int ASideWidth, TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawSchedulerEventProgress(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AProgressChunk, Cxgraphics::TcxViewParams &AViewParams, bool ATransparent);
	virtual void __fastcall DrawSchedulerNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxButtonState AState);
	virtual void __fastcall DrawSchedulerSplitterBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const Cxgraphics::TcxViewParams &AViewParams, bool AIsHorizontal);
	virtual System::Types::TRect __fastcall SchedulerEventProgressOffsets(void);
	virtual System::Types::TSize __fastcall SizeGripSize(void);
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual System::Types::TSize __fastcall SmallCloseButtonSize(void);
	virtual void __fastcall DrawGroupBoxFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual System::Uitypes::TColor __fastcall GroupBoxTextColor(bool AEnabled, TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawPanelBackground(Cxgraphics::TcxCanvas* ACanvas, Vcl::Controls::TWinControl* AControl, System::Types::TRect &ABounds, System::Uitypes::TColor AColorFrom = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor AColorTo = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawEditPopupWindowBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TcxEditPopupBorderStyle ABorderStyle, bool AClientEdge);
	virtual int __fastcall GetEditPopupWindowBorderWidth(TcxEditPopupBorderStyle AStyle);
	virtual int __fastcall GetEditPopupWindowClientEdgeWidth(TcxEditPopupBorderStyle AStyle);
	virtual System::Uitypes::TColor __fastcall GetHintBorderColor(void);
	virtual void __fastcall DrawHintBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual System::Uitypes::TColor __fastcall ScreenTipGetDescriptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall ScreenTipGetTitleTextColor(void);
	virtual void __fastcall CorrectThumbRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AHorizontal, TcxTrackBarTicksAlign ATicks);
	virtual void __fastcall DrawTrackBarTrack(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &ASelection, bool AShowSelection, bool AEnabled, bool AHorizontal, System::Uitypes::TColor ATrackColor);
	virtual void __fastcall DrawTrackBarThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TcxButtonState AState, bool AHorizontal, TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Types::TPoint __fastcall NavigatorButtonPressedGlyphOffset(void);
	virtual System::Types::TSize __fastcall NavigatorButtonMinSize(void);
	virtual System::Uitypes::TColor __fastcall DropDownListBoxItemTextColor(bool ASelected);
	virtual int __fastcall DropDownListBoxSeparatorSize(void);
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	virtual void __fastcall DrawDropDownListBoxGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawDropDownListBoxSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual void __fastcall DrawDropDownListBoxSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditBackgroundColor(TdxBreadcrumbEditState AState);
	virtual System::Types::TRect __fastcall BreadcrumbEditBordersSize(void);
	virtual System::Types::TRect __fastcall BreadcrumbEditButtonContentOffsets(bool AIsFirst, bool AIsLast);
	virtual bool __fastcall BreadcrumbEditIsFadingSupports(void);
	virtual System::Types::TSize __fastcall BreadcrumbEditProgressChunkOverlaySize(void);
	virtual System::Types::TRect __fastcall BreadcrumbEditProgressChunkPadding(void);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditButtonAreaSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast);
	virtual void __fastcall DrawBreadcrumbEditDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, TdxBreadcrumbEditButtonState AState, bool AIsInEditor);
	virtual void __fastcall DrawBreadcrumbEditNode(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState, bool AHasDelimiter);
	virtual void __fastcall DrawBreadcrumbEditNodeDelimiter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditNodeDelimiterGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditNodeMoreButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditProgressChunk(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawBreadcrumbEditProgressChunkOverlay(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual int __fastcall AlertWindowCornerRadius(void);
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(TdxBevelShape AShape);
	virtual void __fastcall DrawBevelFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool ABoxStyle);
	virtual void __fastcall DrawBevelLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AIsVertical);
public:
	/* TObject.Create */ inline __fastcall TcxWinXPLookAndFeelPainter(void) : TcxStandardLookAndFeelPainter() { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawCheck(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, TcxButtonState AState, bool AChecked, System::Uitypes::TColor AColor){ TcxCustomLookAndFeelPainter::DrawCheck(ACanvas, R, AState, AChecked, AColor); }
	
};


class DELPHICLASS TcxLookAndFeelPaintersManager;
class PASCALIMPLEMENTATION TcxLookAndFeelPaintersManager : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCustomLookAndFeelPainter* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TInterfaceList* FListeners;
	Cxclasses::TcxObjectList* FPainters;
	int __fastcall GetCount(void);
	TcxCustomLookAndFeelPainter* __fastcall GetItem(int AIndex);
	
protected:
	void __fastcall DoPainterAdded(TcxCustomLookAndFeelPainter* APainter);
	void __fastcall DoPainterRemoved(TcxCustomLookAndFeelPainter* APainter);
	void __fastcall DoRootLookAndFeelChanged(void);
	void __fastcall SortPainters(void);
	__property System::Classes::TInterfaceList* Listeners = {read=FListeners};
	
public:
	__fastcall virtual TcxLookAndFeelPaintersManager(void);
	__fastcall virtual ~TcxLookAndFeelPaintersManager(void);
	void __fastcall AddListener(const _di_IcxLookAndFeelPainterListener AListener);
	void __fastcall RemoveListener(const _di_IcxLookAndFeelPainterListener AListener);
	bool __fastcall GetPainter(TcxLookAndFeelStyle AStyle, /* out */ TcxCustomLookAndFeelPainter* &APainter)/* overload */;
	bool __fastcall GetPainter(const System::UnicodeString AName, /* out */ TcxCustomLookAndFeelPainter* &APainter)/* overload */;
	TcxCustomLookAndFeelPainter* __fastcall GetPainter(TcxLookAndFeelStyle AStyle)/* overload */;
	TcxCustomLookAndFeelPainter* __fastcall GetPainter(const System::UnicodeString AName)/* overload */;
	bool __fastcall Register(TcxCustomLookAndFeelPainter* APainter);
	bool __fastcall Unregister(const System::UnicodeString AName);
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomLookAndFeelPainter* Items[int Index] = {read=GetItem/*, default*/};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxContainerMaxBorderWidth = System::Int8(0x2);
static const System::Int8 cxTextOffset = System::Int8(0x2);
static const System::Int8 cxHeaderTextOffset = System::Int8(0x2);
static const System::Int8 cxArrowLeftBasePointIndex = System::Int8(0x0);
static const System::Int8 cxArrowTopPointIndex = System::Int8(0x1);
static const System::Int8 cxArrowRightBasePointIndex = System::Int8(0x2);
static const System::Int8 cxStdThumbnailMinimalSize = System::Int8(0x8);
static const System::Int8 cxInplaceNavigatorDefaultOffset = System::Int8(0x32);
static const System::Int8 cxTouchElementMinSize = System::Int8(0x1b);
extern PACKAGE System::StaticArray<TcxEditStateColorKind, 2> cxEditStateColorKindMap;
extern PACKAGE Vcl::Controls::TImageList* cxIndicatorImages;
extern PACKAGE TcxLookAndFeelPaintersManager* cxLookAndFeelPaintersManager;
extern PACKAGE void __fastcall dxAdjustToTouchableSize(int &AElementSizeDimension)/* overload */;
extern PACKAGE void __fastcall dxAdjustToTouchableSize(System::Types::TSize &AElementSize)/* overload */;
extern PACKAGE bool __fastcall dxElementSizeFitsForTouch(int AElementSizeDimension);
extern PACKAGE System::Types::TRect __fastcall cxTextRect(const System::Types::TRect &R);
extern PACKAGE Cxgraphics::TPointArray __fastcall cxGetSchedulerGroupPolygon(const System::Types::TRect &R);
extern PACKAGE Cxgraphics::TPointArray __fastcall cxGetSchedulerMilestonePolygon(const System::Types::TRect &R);
extern PACKAGE void __fastcall UpdateScrollBarBitmaps(void);
extern PACKAGE int __fastcall BtnStateToXPBtnState(TcxButtonState AState);
extern PACKAGE void __fastcall PrepareRadioButtonImageList(void);
extern PACKAGE void __fastcall dxRotateSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABackgroundColor, Dxcore::TdxCorner ACorner, TdxDrawEvent AOnDrawSizeGrip);
}	/* namespace Cxlookandfeelpainters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXLOOKANDFEELPAINTERS)
using namespace Cxlookandfeelpainters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxlookandfeelpaintersHPP
