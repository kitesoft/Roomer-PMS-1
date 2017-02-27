// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsLookAndFeelPainter.pas' rev: 24.00 (Win64)

#ifndef DxskinslookandfeelpainterHPP
#define DxskinslookandfeelpainterHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <dxSkinInfo.hpp>	// Pascal unit
#include <dxSkinsStrs.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinslookandfeelpainter
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxSkinLookAndFeelPainterInfo;
class PASCALIMPLEMENTATION TdxSkinLookAndFeelPainterInfo : public Dxskininfo::TdxSkinInfo
{
	typedef Dxskininfo::TdxSkinInfo inherited;
	
public:
	/* TdxSkinInfo.Create */ inline __fastcall virtual TdxSkinLookAndFeelPainterInfo(Dxskinscore::TdxSkin* ASkin)/* overload */ : Dxskininfo::TdxSkinInfo(ASkin) { }
	/* TdxSkinInfo.Destroy */ inline __fastcall virtual ~TdxSkinLookAndFeelPainterInfo(void) { }
	
};


typedef System::TMetaClass* TdxSkinLookAndFeelPainterInfoClass;

class DELPHICLASS TdxSkinLookAndFeelPainter;
class PASCALIMPLEMENTATION TdxSkinLookAndFeelPainter : public Cxlookandfeelpainters::TcxOffice11LookAndFeelPainter
{
	typedef Cxlookandfeelpainters::TcxOffice11LookAndFeelPainter inherited;
	
private:
	TdxSkinLookAndFeelPainterInfo* FSkinInfo;
	NativeUInt FSkinResInstance;
	System::UnicodeString FSkinResName;
	System::Types::TRect __fastcall GetSkinElementBordersWidth(Dxskinscore::TdxSkinElement* AElement);
	Dxskinscore::TdxSkinDetails* __fastcall GetSkinDetails(void);
	TdxSkinLookAndFeelPainterInfo* __fastcall GetSkinInfo(void);
	
protected:
	virtual System::TObject* __fastcall CreateLookAndFeelPainterDetails(void);
	virtual System::TObject* __fastcall GetLookAndFeelPainterDetails(void);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, int AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxlookandfeelpainters::TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsFooter = false);
	virtual void __fastcall DrawGroupCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect, const System::Types::TRect &ATextRect, Dxskinscore::TdxSkinElement* AElement, Dxskinscore::TdxSkinIntegerProperty* ATextPadding, Dxskinscore::TdxSkinElementState AState);
	virtual void __fastcall DrawSchedulerNavigationButtonContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AArrowRect, bool AIsNextButton, Cxlookandfeelpainters::TcxButtonState AState);
	Cxlookandfeelpainters::TcxButtonState __fastcall GalleryStateToButtonState(const Cxlookandfeelpainters::TdxGalleryItemViewState AState);
	virtual TdxSkinLookAndFeelPainterInfoClass __fastcall GetSkinInfoClass(void);
	bool __fastcall IsColorPropertyAssigned(Dxskinscore::TdxSkinColor* AColor);
	
public:
	__fastcall virtual TdxSkinLookAndFeelPainter(const System::UnicodeString ASkinResName, NativeUInt ASkinResInstance);
	__fastcall virtual ~TdxSkinLookAndFeelPainter(void);
	virtual bool __fastcall GetPainterData(void *AData);
	virtual bool __fastcall GetPainterDetails(void *ADetails);
	virtual System::UnicodeString __fastcall LookAndFeelName(void);
	virtual Cxlookandfeelpainters::TcxLookAndFeelStyle __fastcall LookAndFeelStyle(void);
	virtual System::Uitypes::TColor __fastcall DefaultChartHistogramPlotColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultContentColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultContentEvenColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultContentOddColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultContentTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultEditorBackgroundColorEx(Cxlookandfeelpainters::TcxEditStateColorKind AKind);
	virtual System::Uitypes::TColor __fastcall DefaultEditorTextColorEx(Cxlookandfeelpainters::TcxEditStateColorKind AKind);
	virtual System::Uitypes::TColor __fastcall DefaultFilterBoxTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFixedSeparatorColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFooterColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultFooterTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGridDetailsSiteColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGridLineColor(void);
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
	virtual System::Uitypes::TColor __fastcall DefaultSelectionColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSelectionTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSeparatorColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSizeGripAreaColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMajorScaleTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTimeGridMinorScaleTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultGridOptionsTreeViewCategoryColor(bool ASelected);
	virtual System::Uitypes::TColor __fastcall DefaultGridOptionsTreeViewCategoryTextColor(bool ASelected);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerBorderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerContentColor(int AResourceIndex);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerControlColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerEventColor(bool AIsAllDayEvent);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerNavigatorColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerTimeRulerTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewContentColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewSelectedTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerViewTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultSchedulerYearViewUnusedContentColor(bool AIsWorkTime);
	virtual System::Uitypes::TColor __fastcall DefaultTreeListGridLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultTreeListTreeLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewCaptionTextColor(Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Uitypes::TColor __fastcall DefaultLayoutViewContentTextColor(Cxlookandfeelpainters::TcxButtonState AState);
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
	virtual System::Uitypes::TColor __fastcall DefaultVGridBandLineColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridCategoryColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridCategoryTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridHeaderColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridHeaderTextColor(void);
	virtual System::Uitypes::TColor __fastcall DefaultVGridLineColor(void);
	virtual int __fastcall SeparatorSize(void);
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall DrawContainerBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxContainerBorderStyle AStyle, int AWidth, System::Uitypes::TColor AColor, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DoDrawSeparator(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AIsVertical);
	virtual int __fastcall ButtonBorderSize(Cxlookandfeelpainters::TcxButtonState AState = (Cxlookandfeelpainters::TcxButtonState)(0x1));
	virtual System::Uitypes::TColor __fastcall ButtonDescriptionTextColor(Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual System::Types::TRect __fastcall ButtonFocusRect(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall ButtonSymbolColor(Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ButtonTextOffset(void);
	virtual int __fastcall ButtonTextShift(void);
	virtual void __fastcall DrawButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, const System::UnicodeString ACaption, Cxlookandfeelpainters::TcxButtonState AState, bool ADrawBorder = true, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor ATextColor = (System::Uitypes::TColor)(0x20000000), bool AWordWrap = false, bool AIsToolButton = false);
	virtual void __fastcall DrawExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawExpandButtonEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, bool AExpanded, Cxgraphics::TcxRotationAngle ARotationAngle = (Cxgraphics::TcxRotationAngle)(0x0));
	virtual bool __fastcall DrawExpandButtonFirst(void);
	virtual void __fastcall DrawGroupExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AExpanded, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawSmallExpandButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AExpanded, System::Uitypes::TColor ABorderColor, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual int __fastcall ExpandButtonSize(void);
	virtual int __fastcall GroupExpandButtonSize(void);
	virtual int __fastcall SmallExpandButtonSize(void);
	virtual bool __fastcall IsButtonHotTrack(void);
	virtual bool __fastcall IsPointOverGroupExpandButton(const System::Types::TRect &R, const System::Types::TPoint P);
	virtual int __fastcall ScrollBarMinimalThumbSize(bool AVertical);
	virtual void __fastcall DrawScrollBarBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AHorizontal);
	virtual void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, bool AHorizontal, System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawLabelLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AOuterColor, System::Uitypes::TColor AInnerColor, bool AIsVertical);
	virtual int __fastcall LabelLineHeight(void);
	virtual System::Types::TSize __fastcall SizeGripSize(void);
	virtual void __fastcall DoDrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual System::Types::TSize __fastcall SliderButtonSize(Cxlookandfeelpainters::TcxArrowDirection ADirection);
	virtual void __fastcall DrawSliderButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TcxArrowDirection ADirection, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Types::TSize __fastcall SmallCloseButtonSize(void);
	virtual void __fastcall DrawSmallButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawSmallCloseButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawRadioButton(Cxgraphics::TcxCanvas* ACanvas, int X, int Y, Cxlookandfeelpainters::TcxButtonState AButtonState, bool AChecked, bool AFocused, System::Uitypes::TColor ABrushColor, bool AIsDesigning = false);
	virtual System::Types::TSize __fastcall RadioButtonSize(void);
	virtual System::Types::TSize __fastcall CheckButtonSize(void);
	virtual void __fastcall DrawCheckButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TcxCheckBoxState ACheckState)/* overload */;
	virtual void __fastcall DrawEditorButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TcxEditBtnKind AButtonKind, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TcxEditBtnPosition APosition = (Cxlookandfeelpainters::TcxEditBtnPosition)(0x1));
	virtual void __fastcall DrawEditorButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TcxEditBtnKind AButtonKind, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TcxEditBtnPosition APosition = (Cxlookandfeelpainters::TcxEditBtnPosition)(0x1));
	virtual void __fastcall EditButtonAdjustRect(System::Types::TRect &R, Cxlookandfeelpainters::TcxEditBtnPosition APosition = (Cxlookandfeelpainters::TcxEditBtnPosition)(0x1));
	virtual System::Types::TSize __fastcall EditButtonSize(void);
	virtual System::Uitypes::TColor __fastcall EditButtonTextColor(void);
	virtual int __fastcall EditButtonTextOffset(void);
	virtual System::Uitypes::TColor __fastcall GetContainerBorderColor(bool AIsHighlightBorder);
	virtual int __fastcall GetContainerBorderWidth(Cxlookandfeelpainters::TcxContainerBorderStyle ABorderStyle);
	virtual System::Types::TSize __fastcall GetZoomInButtonSize(void);
	virtual System::Types::TSize __fastcall GetZoomOutButtonSize(void);
	virtual void __fastcall DrawZoomInButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawZoomOutButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Types::TSize __fastcall ClockSize(void);
	virtual void __fastcall DrawClock(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::TDateTime ADateTime, System::Uitypes::TColor ABackgroundColor);
	virtual void __fastcall DrawNavigatorBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool ASelected);
	virtual void __fastcall DrawNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor ABackgroundColor);
	virtual void __fastcall DrawNavigatorButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, Vcl::Imglist::TCustomImageList* AImageList, System::Uitypes::TImageIndex AImageIndex, const System::Types::TRect &AGlyphRect, bool AEnabled, bool AUserGlyphs);
	virtual bool __fastcall NavigatorBorderOverlap(void);
	virtual System::Types::TRect __fastcall NavigatorButtonGlyphPadding(void);
	virtual System::Types::TSize __fastcall NavigatorButtonGlyphSize(void);
	virtual System::Types::TPoint __fastcall NavigatorButtonPressedGlyphOffset(void);
	virtual void __fastcall DrawProgressBarBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AVertical);
	virtual void __fastcall DrawProgressBarChunk(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, bool AVertical);
	virtual System::Types::TRect __fastcall ProgressBarBorderSize(bool AVertical);
	virtual System::Uitypes::TColor __fastcall ProgressBarTextColorEx(bool AIsFilledArea);
	virtual void __fastcall DrawGroupBoxBackground(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ABounds, System::Types::TRect &ARect);
	virtual void __fastcall DrawGroupBoxCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ACaptionRect, const System::Types::TRect &ATextRect, Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawGroupBoxContent(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ABorderRect, Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall DrawGroupBoxExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, bool AExpanded, Cxgraphics::TcxRotationAngle ARotationAngle = (Cxgraphics::TcxRotationAngle)(0x0));
	virtual System::Types::TRect __fastcall GroupBoxBorderSize(bool ACaption, Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawGroupBoxFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, bool AEnabled, Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual int __fastcall GroupBoxCaptionTailSize(Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual System::Uitypes::TColor __fastcall GroupBoxTextColor(bool AEnabled, Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual bool __fastcall IsGroupBoxCaptionTextDrawnOverBorder(Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual bool __fastcall IsGroupBoxTransparent(bool AIsCaption, Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual System::Uitypes::TColor __fastcall PanelTextColor(void);
	virtual void __fastcall DrawHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, Cxlookandfeelpainters::TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, Cxlookandfeelpainters::TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxlookandfeelpainters::TcxDrawBackgroundEvent AOnDrawBackground = 0x0, bool AIsLast = false, bool AIsGroup = false);
	virtual void __fastcall DrawHeaderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, Cxlookandfeelpainters::TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, Cxlookandfeelpainters::TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxlookandfeelpainters::TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawHeaderControlSection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextAreaBounds, Cxlookandfeelpainters::TcxNeighbors ANeighbors, Cxgraphics::TcxBorders ABorders, Cxlookandfeelpainters::TcxButtonState AState, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, bool AShowEndEllipsis, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor);
	virtual void __fastcall DrawHeaderSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, int AIndentSize, System::Uitypes::TColor AColor, Cxgraphics::TcxViewParams &AViewParams);
	virtual void __fastcall DrawHeaderPressed(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawSortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual void __fastcall DrawSummarySortingMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, bool AAscendingSorting);
	virtual Cxgraphics::TcxBorders __fastcall HeaderBorders(Cxlookandfeelpainters::TcxNeighbors ANeighbors);
	virtual bool __fastcall HeaderDrawCellsFirst(void);
	virtual System::Types::TPoint __fastcall SummarySortingMarkSize(void);
	virtual void __fastcall DrawGroupByBox(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TBitmap* const ABackgroundBitmap);
	virtual int __fastcall GridBordersOverlapSize(void);
	virtual bool __fastcall GridDrawHeaderCellsFirst(void);
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11ContentColor(bool AHasData);
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11SeparatorColor(void);
	virtual System::Uitypes::TColor __fastcall GridGroupRowStyleOffice11TextColor(void);
	virtual System::Uitypes::TColor __fastcall PivotGridHeadersAreaColor(void);
	virtual System::Uitypes::TColor __fastcall PivotGridHeadersAreaTextColor(void);
	virtual void __fastcall LayoutViewDrawRecordCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &ATextRect, Cxlookandfeelpainters::TcxGroupBoxCaptionPosition APosition, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall LayoutViewDrawRecordContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition, Cxlookandfeelpainters::TcxButtonState AState, Cxgraphics::TcxBorders ABorders = (Cxgraphics::TcxBorders() << Cxgraphics::TcxBorder::bLeft << Cxgraphics::TcxBorder::bTop << Cxgraphics::TcxBorder::bRight << Cxgraphics::TcxBorder::bBottom ));
	virtual void __fastcall LayoutViewDrawRecordExpandButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxButtonState AState, bool AExpanded);
	virtual void __fastcall LayoutViewDrawItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxButtonState AState, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() );
	virtual System::Types::TRect __fastcall LayoutViewGetPadding(Cxlookandfeelpainters::TcxLayoutElement AElement);
	virtual System::Types::TRect __fastcall LayoutViewGetSpacing(Cxlookandfeelpainters::TcxLayoutElement AElement);
	virtual int __fastcall LayoutViewRecordCaptionTailSize(Cxlookandfeelpainters::TcxGroupBoxCaptionPosition ACaptionPosition);
	virtual void __fastcall DrawFooterBorderEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall DrawFooterCellBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawFooterCellContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Classes::TAlignment AAlignmentHorz, Cxclasses::TcxAlignmentVert AAlignmentVert, bool AMultiLine, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor ATextColor, System::Uitypes::TColor ABkColor, Cxlookandfeelpainters::TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawFooterContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const Cxgraphics::TcxViewParams &AViewParams);
	virtual int __fastcall FooterCellBorderSize(void);
	virtual bool __fastcall FooterDrawCellsFirst(void);
	virtual System::Uitypes::TColor __fastcall FooterSeparatorColor(void);
	virtual System::Types::TPoint __fastcall FilterCloseButtonSize(void);
	virtual System::Types::TSize __fastcall FilterSmartTagSize(void);
	virtual void __fastcall DrawFilterCloseButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawFilterDropDownButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, bool AIsFilterActive);
	virtual void __fastcall DrawFilterPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ATransparent, System::Uitypes::TColor ABackgroundColor, Vcl::Graphics::TBitmap* const ABackgroundBitmap);
	virtual void __fastcall DrawFilterSmartTag(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxFilterSmartTagState AState, bool AIsFilterActive);
	virtual void __fastcall DrawPanelBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect);
	virtual void __fastcall DrawPanelContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, bool ABorder);
	virtual void __fastcall DrawTrackBarTrack(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &ASelection, bool AShowSelection, bool AEnabled, bool AHorizontal, System::Uitypes::TColor ATrackColor);
	virtual void __fastcall DrawTrackBarThumb(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TcxButtonState AState, bool AHorizontal, Cxlookandfeelpainters::TcxTrackBarTicksAlign ATicks, System::Uitypes::TColor AThumbColor);
	virtual System::Types::TSize __fastcall TrackBarThumbSize(bool AHorizontal);
	virtual System::Uitypes::TColor __fastcall TrackBarTicksColor(bool AText);
	virtual int __fastcall TrackBarTrackSize(void);
	virtual void __fastcall DrawSplitter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHighlighted, bool AClicked, bool AHorizontal);
	virtual System::Types::TSize __fastcall GetSplitterSize(bool AHorizontal);
	virtual System::Uitypes::TColor __fastcall GetHintBorderColor(void);
	virtual void __fastcall DrawHintBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual System::Uitypes::TColor __fastcall ScreenTipGetDescriptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall ScreenTipGetTitleTextColor(void);
	virtual int __fastcall ScreenTipGetFooterLineSize(void);
	virtual void __fastcall ScreenTipDrawBackground(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect);
	virtual void __fastcall ScreenTipDrawFooterLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawIndicatorCustomizationMark(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawIndicatorImage(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxIndicatorKind AKind);
	virtual void __fastcall DrawIndicatorItem(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxlookandfeelpainters::TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall DrawIndicatorItemEx(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxIndicatorKind AKind, System::Uitypes::TColor AColor, Cxlookandfeelpainters::TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual bool __fastcall IndicatorDrawItemsFirst(void);
	virtual void __fastcall DrawMonthHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, Cxlookandfeelpainters::TcxNeighbors ANeighbors, const Cxgraphics::TcxViewParams &AViewParams, Cxlookandfeelpainters::TcxArrowDirections AArrows, int ASideWidth, Cxlookandfeelpainters::TcxDrawBackgroundEvent AOnDrawBackground = 0x0);
	virtual void __fastcall CalculateSchedulerNavigationButtonRects(bool AIsNextButton, bool ACollapsed, System::Types::TSize APrevButtonTextSize, System::Types::TSize ANextButtonTextSize, System::Types::TRect &ABounds, /* out */ System::Types::TRect &ATextRect, /* out */ System::Types::TRect &AArrowRect);
	virtual void __fastcall DrawSchedulerEventProgress(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AProgress, Cxgraphics::TcxViewParams &AViewParams, bool ATransparent);
	virtual void __fastcall DrawSchedulerGroup(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall DrawSchedulerGroupSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor ABackgroundColor, Cxlookandfeelpainters::TcxDrawBackgroundEvent AOnDrawBackground);
	virtual void __fastcall DrawSchedulerMilestone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawSchedulerNavigatorButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual System::Types::TRect __fastcall SchedulerEventProgressOffsets(void);
	virtual System::Uitypes::TColor __fastcall SchedulerNavigationButtonTextColor(bool AIsNextButton, Cxlookandfeelpainters::TcxButtonState AState, System::Uitypes::TColor ADefaultColor = (System::Uitypes::TColor)(0x20000000));
	virtual void __fastcall SchedulerNavigationButtonSizes(bool AIsNextButton, System::Types::TRect &ABorders, System::Types::TSize &AArrowSize, bool &AHasTextArea);
	virtual System::Uitypes::TColor __fastcall LayoutControlEmptyAreaColor(void);
	virtual void __fastcall DrawLayoutControlBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawScrollBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, System::Uitypes::TColor AColor);
	virtual void __fastcall DrawEditPopupWindowBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxEditPopupBorderStyle ABorderStyle, bool AClientEdge);
	virtual int __fastcall GetEditPopupWindowBorderWidth(Cxlookandfeelpainters::TcxEditPopupBorderStyle AStyle);
	virtual int __fastcall GetEditPopupWindowClientEdgeWidth(Cxlookandfeelpainters::TcxEditPopupBorderStyle AStyle);
	virtual System::Uitypes::TColor __fastcall GetWindowContentTextColor(void);
	virtual void __fastcall DrawWindowContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual System::Types::TRect __fastcall PrintPreviewPageBordersWidth(void);
	virtual void __fastcall DrawPrintPreviewBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawPrintPreviewPageBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABorderRect, const System::Types::TRect &AContentRect, bool ASelected, bool ADrawContent);
	virtual void __fastcall DrawDateNavigatorDateHeader(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall CalcEditButtonTextColor(Cxlookandfeelpainters::TcxCalcButtonKind AButtonKind);
	virtual System::Uitypes::TColor __fastcall GetCustomizationFormListBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditBackgroundColor(Cxlookandfeelpainters::TdxBreadcrumbEditState AState);
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditBordersColor(Cxlookandfeelpainters::TdxBreadcrumbEditState AState);
	virtual int __fastcall BreadcrumbEditButtonAreaSeparatorSize(void);
	virtual System::Types::TRect __fastcall BreadcrumbEditButtonContentOffsets(bool AIsFirst, bool AIsLast);
	virtual int __fastcall BreadcrumbEditDropDownButtonOriginalWidth(void);
	virtual bool __fastcall BreadcrumbEditIsFadingSupports(void);
	virtual System::Uitypes::TColor __fastcall BreadcrumbEditNodeTextColor(Cxlookandfeelpainters::TdxBreadcrumbEditButtonState AState);
	virtual System::Types::TRect __fastcall BreadcrumbEditNodeTextOffsets(void);
	virtual System::Types::TSize __fastcall BreadcrumbEditProgressChunkOverlaySize(void);
	virtual System::Types::TRect __fastcall BreadcrumbEditProgressChunkPadding(void);
	virtual void __fastcall DrawBreadcrumbEditBorders(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, Cxlookandfeelpainters::TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TdxBreadcrumbEditButtonState AState, bool AIsFirst, bool AIsLast);
	virtual void __fastcall DrawBreadcrumbEditButtonAreaSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TdxBreadcrumbEditState AState);
	virtual void __fastcall DrawBreadcrumbEditDropDownButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TdxBreadcrumbEditButtonState AState, bool AIsInEditor);
	virtual void __fastcall DrawBreadcrumbEditDropDownButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxlookandfeelpainters::TdxBreadcrumbEditButtonState AState, bool AIsInEditor);
	virtual void __fastcall DrawBreadcrumbEditNode(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TdxBreadcrumbEditButtonState AState, bool AHasDelimiter);
	virtual void __fastcall DrawBreadcrumbEditNodeDelimiter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditNodeMoreButtonGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditNodeDelimiterGlyph(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TdxBreadcrumbEditButtonState AState);
	virtual void __fastcall DrawBreadcrumbEditProgressChunk(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawBreadcrumbEditProgressChunkOverlay(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual int __fastcall DropDownListBoxBordersSize(void);
	virtual System::Types::TRect __fastcall DropDownListBoxItemImageOffsets(void);
	virtual System::Uitypes::TColor __fastcall DropDownListBoxItemTextColor(bool ASelected);
	virtual System::Types::TRect __fastcall DropDownListBoxItemTextOffsets(void);
	virtual int __fastcall DropDownListBoxSeparatorSize(void);
	virtual void __fastcall DrawDropDownListBoxBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool AHasBorders);
	virtual void __fastcall DrawDropDownListBoxGutterBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall DrawDropDownListBoxSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual void __fastcall DrawDropDownListBoxSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const System::Types::TRect &AGutterRect);
	virtual System::Types::TRect __fastcall AlertWindowButtonContentOffsets(Cxlookandfeelpainters::TdxAlertWindowButtonKind AKind);
	Dxskinscore::TdxSkinElement* __fastcall AlertWindowButtonElement(Cxlookandfeelpainters::TdxAlertWindowButtonKind AKind);
	virtual System::Types::TRect __fastcall AlertWindowContentOffsets(void);
	virtual int __fastcall AlertWindowCornerRadius(void);
	virtual System::Uitypes::TColor __fastcall AlertWindowNavigationPanelTextColor(void);
	virtual System::Uitypes::TColor __fastcall AlertWindowTextColor(void);
	virtual void __fastcall DrawAlertWindowBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawAlertWindowButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxlookandfeelpainters::TcxButtonState AState, Cxlookandfeelpainters::TdxAlertWindowButtonKind AKind, bool ADown);
	virtual void __fastcall DrawAlertWindowNavigationPanel(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual System::Types::TSize __fastcall GetBevelMinimalShapeSize(Cxlookandfeelpainters::TdxBevelShape AShape);
	virtual void __fastcall GetBevelShapeColors(/* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	virtual System::Types::TRect __fastcall GetGalleryGroupHeaderContentOffsets(void);
	virtual System::Uitypes::TColor __fastcall GetGalleryGroupTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetGalleryItemCaptionTextColor(const Cxlookandfeelpainters::TdxGalleryItemViewState AState);
	virtual System::Uitypes::TColor __fastcall GetGalleryItemDescriptionTextColor(const Cxlookandfeelpainters::TdxGalleryItemViewState AState);
	virtual void __fastcall DrawGalleryBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawGalleryGroupHeader(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawGalleryItemImageFrame(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual bool __fastcall DrawGalleryItemSelectionFirst(void);
	virtual void __fastcall DrawGalleryItemSelection(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TdxGalleryItemViewState AViewState);
	virtual System::Uitypes::TColor __fastcall GetColorGalleryGlyphFrameColor(void);
	virtual System::Types::TSize __fastcall GetBackButtonSize(void);
	virtual void __fastcall DrawBackButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	__property Dxskinscore::TdxSkinDetails* SkinDetails = {read=GetSkinDetails};
	__property TdxSkinLookAndFeelPainterInfo* SkinInfo = {read=GetSkinInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawCheckButton(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState, bool AChecked){ Cxlookandfeelpainters::TcxCustomLookAndFeelPainter::DrawCheckButton(ACanvas, R, AState, AChecked); }
	
};


typedef System::TMetaClass* TdxSkinLookAndFeelPainterClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::StaticArray<Dxskinscore::TdxSkinElementState, 5> ButtonStateToSkinState;
}	/* namespace Dxskinslookandfeelpainter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSLOOKANDFEELPAINTER)
using namespace Dxskinslookandfeelpainter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinslookandfeelpainterHPP
