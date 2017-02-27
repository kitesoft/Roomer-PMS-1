// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPCPainters.pas' rev: 24.00 (Win32)

#ifndef CxpcpaintersHPP
#define CxpcpaintersHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpcpainters
{
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TcxPCTabsDelimiterOffsets
{
public:
	int Top;
	int Bottom;
};


enum TcxPCArrow : unsigned char { aTop, aBottom, aLeft, aRight };

struct DECLSPEC_DRECORD TcxPCNavigatorButtonContentParameters
{
public:
	System::Uitypes::TColor BrushColor;
	System::Uitypes::TColor Color;
	bool Enabled;
	bool LiteStyle;
};


enum TLinePosition : unsigned char { lpL, lpLT, lpT, lpRT, lpR, lpRB, lpB, lpLB };

typedef System::DynamicArray<TLinePosition> TLinePositions;

class DELPHICLASS TcxPCStandardPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCStandardPainter : public Cxpc::TcxPCCustomPainter
{
	typedef Cxpc::TcxPCCustomPainter inherited;
	
private:
	System::Types::TRect FButtonsRect;
	int __fastcall GetButtonsWidth(void);
	
protected:
	virtual int __fastcall CalculateTabNormalWidth(Cxpc::TcxTabViewInfo* ATabViewInfo);
	virtual void __fastcall CorrectTabNormalWidth(int &AValue);
	virtual void __fastcall DoDrawTabButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState);
	virtual void __fastcall DoDrawTabCloseButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState);
	virtual void __fastcall DrawButtonFrameAndBackround(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState);
	virtual System::Types::TSize __fastcall GetCloseButtonSize(void);
	virtual System::Types::TRect __fastcall GetDrawImageOffset(int TabVisibleIndex);
	virtual Cxpc::TcxPCWOffset __fastcall GetDrawImageWithoutTextWOffset(int TabVisibleIndex);
	virtual System::Types::TRect __fastcall GetDrawTextHOffset(int TabVisibleIndex);
	virtual int __fastcall GetFrameWidth(void);
	virtual System::Types::TPoint __fastcall GetGoDialogPosition(const System::Types::TSize &ASize);
	int __fastcall GetHeaderButtonHeightCorrection(void);
	virtual int __fastcall GetImageTextDistance(int ATabVisibleIndex);
	virtual int __fastcall GetMinTabNormalWidth(int ATabVisibleIndex);
	virtual Cxpc::TcxPCDistance __fastcall GetMinTabSelectionDistance(void);
	virtual Cxpc::TcxPCWOffset __fastcall GetTabContentWOffset(int ATabVisibleIndex);
	virtual Cxpc::TcxPCDistance __fastcall GetTabsNormalDistance(void);
	virtual Cxpc::TcxPCTabsPosition __fastcall GetTabsPosition(void);
	virtual Cxpc::TcxPCWOffset __fastcall GetTooNarrowTabContentWOffset(int ATabVisibleIndex);
	virtual int __fastcall InternalCalculateTabNormalWidth(int ATabVisibleIndex);
	virtual bool __fastcall IsTabBorderThick(int ATabVisibleIndex);
	virtual void __fastcall PaintButtonsRegion(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintTab(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall PaintTabsRegion(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall RepaintButtonsRegion(void);
	virtual void __fastcall RepaintTab(int TabVisibleIndex, Cxpc::TcxPCTabPropertyChanged TabPropertyChanged);
	virtual void __fastcall CalculateButtonContentParameters(Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState, /* out */ TcxPCNavigatorButtonContentParameters &AParameters);
	virtual void __fastcall CalculateButtonsRect(void);
	virtual void __fastcall CalculateButtonsRegion(void);
	virtual int __fastcall CalculateButtonsRegionWidth(void);
	void __fastcall CorrectTabHeightForImage(int &AHeight);
	virtual void __fastcall DoPaintButton(Cxgraphics::TcxCanvas* ACanvas, Cxpc::TcxPCCustomHeaderButtonViewInfo* AButtonInfo);
	void __fastcall DrawButtonContent(Cxgraphics::TcxCanvas* ACanvas, Cxpc::TcxPCNavigatorButton AButton, const TcxPCNavigatorButtonContentParameters &AParameters, const System::Types::TPoint &AContentRectLeftTopCorner);
	System::Types::TPoint __fastcall Get3DButtonContentPosition(Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState);
	TcxPCArrow __fastcall GetButtonArrow(Cxpc::TcxPCNavigatorButton AButton);
	System::Types::TPoint __fastcall GetButtonCenteredContentPosition(const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState);
	virtual System::Uitypes::TColor __fastcall GetButtonColor(Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual System::Uitypes::TColor __fastcall GetButtonContentColor(Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual System::Types::TPoint __fastcall GetButtonContentPosition(const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState);
	virtual int __fastcall GetButtonHeight(void);
	virtual int __fastcall GetButtonWidth(Cxpc::TcxPCNavigatorButton Button);
	virtual int __fastcall GetDefaultTabNormalHeight(void);
	virtual int __fastcall GetDefaultTabNormalHTextOffset(void);
	virtual int __fastcall GetDefaultTabNormalWidth(void);
	virtual System::Types::TRect __fastcall GetDrawFrameRect(void);
	virtual System::Types::TRect __fastcall GetPageFrameRect(void);
	virtual int __fastcall GetMinFrameRectSize(void);
	virtual int __fastcall GetTabNormalContentOffset(int ATabVisibleIndex);
	virtual int __fastcall GetTabNormalImageAreaWidth(int ATabVisibleIndex);
	virtual int __fastcall GetTabNormalWidth(int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetTabsRectOffset(void);
	virtual int __fastcall GetTabTextNormalWidth(int ATabVisibleIndex);
	virtual int __fastcall InternalCalculateTabNormalHeight(void);
	void __fastcall InternalDrawEdge(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool ASunken, bool AThinFrame = false);
	virtual void __fastcall InternalDrawFocusRect(Cxgraphics::TcxCanvas* ACanvas, int TabVisibleIndex, const System::Types::TRect &R);
	virtual void __fastcall InternalPaintDragImage(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall InternalPaintTab(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall PaintButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState, Cxpc::TcxPCNavigatorButton AType);
	virtual void __fastcall PaintButtonBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState);
	virtual void __fastcall PaintButtonFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual void __fastcall PaintHeaderButton(Cxgraphics::TcxCanvas* ACanvas, Cxpc::TcxPCHeaderButtonViewInfo* AButtonInfo);
	virtual void __fastcall DoPaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintFrameBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall PaintTabShape(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex) = 0 ;
	__property System::Types::TRect ButtonsRect = {read=FButtonsRect};
	
public:
	virtual int __fastcall CalculateTabNormalHeight(void);
	__classmethod virtual bool __fastcall IsMainTabBoundWithClient();
	__classmethod virtual bool __fastcall IsMultiSelectionAccepted();
	__classmethod virtual bool __fastcall IsStandardStyle();
	__classmethod virtual bool __fastcall IsTabPressable();
public:
	/* TcxPCCustomPainter.Create */ inline __fastcall virtual TcxPCStandardPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : Cxpc::TcxPCCustomPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCStandardPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCButtonedPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCButtonedPainter : public TcxPCStandardPainter
{
	typedef TcxPCStandardPainter inherited;
	
private:
	Vcl::Graphics::TBitmap* MainTabBrushBitmap;
	void __fastcall CorrectContentWOffset(int ATabVisibleIndex, Cxpc::TcxPCWOffset &AOffset);
	
protected:
	virtual System::Types::TPoint __fastcall GetButtonContentPosition(const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState);
	virtual int __fastcall GetButtonsRegionHOffset(void);
	virtual int __fastcall GetButtonsRegionWOffset(void);
	virtual Cxpc::TcxPCWOffset __fastcall GetDrawImageWithoutTextWOffset(int TabVisibleIndex);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	virtual System::Uitypes::TColor __fastcall GetTabBodyColor(int TabVisibleIndex);
	virtual Cxpc::TcxPCWOffset __fastcall GetTabContentWOffset(int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetTabsContainerOffsets(void);
	virtual Cxpc::TcxPCWOffset __fastcall GetTooNarrowTabContentWOffset(int ATabVisibleIndex);
	virtual void __fastcall DrawFocusRect(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall InternalGetPageFrameRectOffset(void);
	virtual bool __fastcall IsTabBorderThick(int ATabVisibleIndex);
	virtual bool __fastcall UseLookAndFeelTabButton(void);
	
public:
	__fastcall virtual TcxPCButtonedPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo);
	__fastcall virtual ~TcxPCButtonedPainter(void);
};

#pragma pack(pop)

class DELPHICLASS TcxPCTabsPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCTabsPainter : public TcxPCStandardPainter
{
	typedef TcxPCStandardPainter inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetTabCorrection(int ATabVisibleIndex);
	virtual void __fastcall DrawNativeTabBackground(HDC DC, Cxpc::TcxTabSheet* ATab);
	virtual System::Types::TRect __fastcall GetBorderWidths(void);
	virtual System::Types::TPoint __fastcall GetButtonContentPosition(const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState);
	virtual int __fastcall GetButtonHeight(void);
	void __fastcall GetButtonNativePartAndState(Cxpc::TcxPCNavigatorButtonState AState, Cxpc::TcxPCNavigatorButton AType, /* out */ int &APartId, /* out */ int &AStateId, /* out */ Dxthememanager::TdxThemedObjectType &AThemeObjectType);
	virtual int __fastcall GetButtonsRegionHOffset(void);
	virtual int __fastcall GetButtonsRegionWOffset(void);
	virtual int __fastcall GetButtonWidth(Cxpc::TcxPCNavigatorButton Button);
	virtual System::Types::TRect __fastcall GetCloseButtonOffset(int ATabVisibleIndex);
	virtual int __fastcall GetNativeButtonHeight(void);
	virtual System::Types::TRect __fastcall GetPageClientRectOffset(void);
	virtual System::Types::TRect __fastcall GetDrawImageOffset(int TabVisibleIndex);
	virtual Cxpc::TcxPCWOffset __fastcall GetDrawImageWithoutTextWOffset(int TabVisibleIndex);
	virtual System::Types::TRect __fastcall GetDrawTextHOffset(int TabVisibleIndex);
	virtual System::Types::TRect __fastcall GetHeaderButtonGlyphOffset(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	virtual System::Uitypes::TColor __fastcall GetTabBodyColor(int TabVisibleIndex);
	virtual Cxgraphics::TcxRegion* __fastcall GetTabClipRgn(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual Cxpc::TcxPCWOffset __fastcall GetTabContentWOffset(int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetTabFocusRect(const System::Types::TRect &ATabBounds);
	virtual void __fastcall GetTabNativePartAndState(int ATabVisibleIndex, /* out */ int &PartId, /* out */ int &StateId);
	virtual System::Types::TRect __fastcall GetTabsContainerOffsets(void);
	virtual Cxpc::TcxPCTabsPosition __fastcall GetTabsPosition(void);
	virtual Cxpc::TcxPCWOffset __fastcall GetTooNarrowTabContentWOffset(int ATabVisibleIndex);
	virtual void __fastcall DrawFocusRect(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual int __fastcall InternalCalculateTabNormalHeight(void);
	virtual System::Types::TRect __fastcall InternalGetPageFrameRectOffset(void);
	virtual void __fastcall InternalPaintTab(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall InvalidateTabRect(int ATabVisibleIndex);
	virtual bool __fastcall IsNativePainting(void);
	virtual bool __fastcall PtInTab(int TabVisibleIndex, int X, int Y);
	virtual bool __fastcall NeedShowFrame(void);
	virtual void __fastcall PaintButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState, Cxpc::TcxPCNavigatorButton AType);
	virtual void __fastcall PaintHeaderButton(Cxgraphics::TcxCanvas* ACanvas, Cxpc::TcxPCHeaderButtonViewInfo* AButtonInfo);
	void __fastcall PaintNativeButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState, Cxpc::TcxPCNavigatorButton AType, bool ADrawBackground);
	virtual void __fastcall DoPaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintTabShape(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall PaintTabsRegion(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintNativeTabBackground(HDC DC, int ATabVisibleIndex, const System::Types::TRect &ABounds);
	virtual void __fastcall PrepareTabBackground(Cxgraphics::TcxBitmap* ABitmap, int ATabVisibleIndex);
	virtual void __fastcall PrepareTabBitmapBackground(Cxgraphics::TcxBitmap* ABitmap, const System::Types::TRect &ARect, Cxpc::TcxTabViewInfo* ATabViewInfo);
	virtual void __fastcall RepaintTab(int TabVisibleIndex, Cxpc::TcxPCTabPropertyChanged TabPropertyChanged);
	virtual int __fastcall GetButtonsDistance(Cxpc::TcxPCNavigatorButton AButton1, Cxpc::TcxPCNavigatorButton AButton2);
	virtual int __fastcall GetMinFrameRectSize(void);
	virtual int __fastcall GetNativeButtonsDistance(Cxpc::TcxPCNavigatorButton AButton1, Cxpc::TcxPCNavigatorButton AButton2);
	virtual void __fastcall GetTabCornersColor(int ATabVisibleIndex, /* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	virtual void __fastcall PaintTabCorners(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall PaintTabFrame(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall InternalPaintFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual bool __fastcall UseLookAndFeelTabButton(void);
	
public:
	virtual void __fastcall PaintPageClientArea(Cxgraphics::TcxCanvas* ACanvas);
	__classmethod virtual Cxpc::TcxPCStandardStyle __fastcall GetStandardStyle();
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	__classmethod virtual bool __fastcall IsDefault(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TcxPCCustomPainter.Create */ inline __fastcall virtual TcxPCTabsPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCStandardPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCTabsPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCButtonsPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCButtonsPainter : public TcxPCButtonedPainter
{
	typedef TcxPCButtonedPainter inherited;
	
protected:
	virtual bool __fastcall IsTabBorderThick(int ATabVisibleIndex);
	virtual void __fastcall PaintTabShape(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	
public:
	__classmethod virtual Cxpc::TcxPCStandardStyle __fastcall GetStandardStyle();
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TcxPCButtonedPainter.Create */ inline __fastcall virtual TcxPCButtonsPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCButtonedPainter(AViewInfo) { }
	/* TcxPCButtonedPainter.Destroy */ inline __fastcall virtual ~TcxPCButtonsPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCFlatButtonsPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCFlatButtonsPainter : public TcxPCButtonedPainter
{
	typedef TcxPCButtonedPainter inherited;
	
protected:
	virtual void __fastcall PaintTab(Cxgraphics::TcxCanvas* ACanvas, int TabVisibleIndex);
	virtual void __fastcall PaintTabShape(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	
public:
	__classmethod virtual Cxpc::TcxPCStandardStyle __fastcall GetStandardStyle();
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TcxPCButtonedPainter.Create */ inline __fastcall virtual TcxPCFlatButtonsPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCButtonedPainter(AViewInfo) { }
	/* TcxPCButtonedPainter.Destroy */ inline __fastcall virtual ~TcxPCFlatButtonsPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCExtraFlatPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCExtraFlatPainter : public TcxPCStandardPainter
{
	typedef TcxPCStandardPainter inherited;
	
protected:
	virtual void __fastcall CalculateButtonContentParameters(Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState, /* out */ TcxPCNavigatorButtonContentParameters &AParameters);
	virtual int __fastcall CalculateTabNormalWidth(Cxpc::TcxTabViewInfo* ATabViewInfo);
	virtual void __fastcall CorrectTabNormalWidth(int &AValue);
	virtual System::Types::TRect __fastcall GetTabCorrection(int ATabVisibleIndex);
	virtual System::Uitypes::TColor __fastcall GetButtonColor(Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual System::Uitypes::TColor __fastcall GetButtonContentColor(Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual System::Types::TPoint __fastcall GetButtonContentPosition(const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState);
	virtual int __fastcall GetButtonHeight(void);
	virtual int __fastcall GetButtonWidth(Cxpc::TcxPCNavigatorButton Button);
	virtual System::Types::TRect __fastcall GetCloseButtonOffset(int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetPageClientRectOffset(void);
	virtual System::Uitypes::TColor __fastcall GetDefaultClientColor(void);
	virtual int __fastcall GetDefaultTabNormalHeight(void);
	virtual int __fastcall GetDefaultTabNormalHTextOffset(void);
	virtual System::Types::TRect __fastcall GetDrawImageOffset(int TabVisibleIndex);
	virtual System::Types::TRect __fastcall GetDrawTextHOffset(int TabVisibleIndex);
	virtual int __fastcall GetFrameWidth(void);
	virtual System::Uitypes::TColor __fastcall GetFreeSpaceColor(void);
	virtual int __fastcall GetMinTabNormalWidth(int ATabVisibleIndex);
	virtual System::Uitypes::TColor __fastcall GetTabBodyColor(int TabVisibleIndex);
	virtual Cxpc::TcxPCWOffset __fastcall GetTabContentWOffset(int ATabVisibleIndex);
	virtual int __fastcall GetTabNormalContentOffset(int ATabVisibleIndex);
	virtual int __fastcall GetTabNormalImageAreaWidth(int ATabVisibleIndex);
	virtual int __fastcall GetTabsRowsDelimiterWidth(void);
	virtual Cxpc::TcxPCDistance __fastcall GetTabsNormalDistance(void);
	virtual Cxpc::TcxPCTabsPosition __fastcall GetTabsPosition(void);
	virtual int __fastcall GetTabTextNormalWidth(int ATabVisibleIndex);
	virtual Cxpc::TcxPCWOffset __fastcall GetTooNarrowTabContentWOffset(int ATabVisibleIndex);
	virtual int __fastcall InternalCalculateTabNormalHeight(void);
	virtual System::Types::TRect __fastcall InternalGetPageFrameRectOffset(void);
	virtual bool __fastcall IsPaintHeadersAreaFirst(void);
	virtual bool __fastcall IsTabsRectVisible(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintButtonFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual void __fastcall DoPaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintTabShape(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall PaintTabsRegion(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall RepaintTab(int TabVisibleIndex, Cxpc::TcxPCTabPropertyChanged TabPropertyChanged);
	virtual int __fastcall GetButtonsDistance(Cxpc::TcxPCNavigatorButton AButton1, Cxpc::TcxPCNavigatorButton AButton2);
	virtual int __fastcall GetButtonsRegionHOffset(void);
	virtual int __fastcall GetButtonsRegionWOffset(void);
	virtual System::Types::TRect __fastcall GetFocusRect(void);
	virtual TcxPCTabsDelimiterOffsets __fastcall GetTabsDelimiterOffsets(void);
	virtual void __fastcall DrawTabBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, int ATabVisibleIndex);
	virtual void __fastcall DrawFocusRect(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall ExcludeUnderLine(System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall GetMainTabRowUnderlineColor(void);
	virtual System::Types::TRect __fastcall GetMainTabRowUnderlineRect(void);
	virtual System::Types::TRect __fastcall GetTabBackgroundRect(int ATabVisibleIndex, bool AForNormalState);
	virtual int __fastcall GetTabsDelimiterWidth(void);
	virtual System::Uitypes::TColor __fastcall GetTabsRowColor(void);
	System::Types::TRect __fastcall GetTabsRowRect(int ARowIndex);
	void __fastcall InternalPaintFrame(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor ALeftTopColor, System::Uitypes::TColor ARightBottomColor);
	void __fastcall InternalPaintMainTabFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, System::Uitypes::TColor ALightColor, System::Uitypes::TColor ADarkColor);
	void __fastcall InternalPaintTabsRowsDelimiter(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARowRect, System::Uitypes::TColor *AColors, const int AColors_Size);
	bool __fastcall IsMainTabRow(int AVisibleRow);
	virtual bool __fastcall NeedShowTabsRegionFrame(void);
	virtual void __fastcall PaintMainTabFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	void __fastcall PaintMainTabRowUnderline(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintTabsDelimiter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall PaintTabsRowsDelimiter(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARowRect, int ARowIndex);
	
public:
	virtual int __fastcall CalculateTabNormalHeight(void);
	virtual void __fastcall PaintPageClientArea(Cxgraphics::TcxCanvas* ACanvas);
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	__classmethod virtual bool __fastcall IsMainTabBoundWithClient();
	__classmethod virtual bool __fastcall IsMultiSelectionAccepted();
	__classmethod virtual bool __fastcall IsTabPressable();
public:
	/* TcxPCCustomPainter.Create */ inline __fastcall virtual TcxPCExtraFlatPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCStandardPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCExtraFlatPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCUltraFlatPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCUltraFlatPainter : public TcxPCExtraFlatPainter
{
	typedef TcxPCExtraFlatPainter inherited;
	
protected:
	virtual void __fastcall CalculateButtonContentParameters(Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState, /* out */ TcxPCNavigatorButtonContentParameters &AParameters);
	virtual System::Uitypes::TColor __fastcall GetButtonColor(Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual System::Types::TPoint __fastcall GetButtonContentPosition(const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState);
	virtual int __fastcall GetButtonHeight(void);
	virtual int __fastcall GetButtonsDistance(Cxpc::TcxPCNavigatorButton AButton1, Cxpc::TcxPCNavigatorButton AButton2);
	virtual int __fastcall GetButtonsRegionHOffset(void);
	virtual int __fastcall GetButtonWidth(Cxpc::TcxPCNavigatorButton Button);
	virtual System::Types::TRect __fastcall GetFocusRect(void);
	virtual void __fastcall PaintButtonFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual void __fastcall DoPaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintMainTabFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall PaintTabsRowsDelimiter(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARowRect, int ARowIndex);
	
public:
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TcxPCCustomPainter.Create */ inline __fastcall virtual TcxPCUltraFlatPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCExtraFlatPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCUltraFlatPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCFlatPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCFlatPainter : public TcxPCTabsPainter
{
	typedef TcxPCTabsPainter inherited;
	
protected:
	virtual System::Types::TPoint __fastcall GetButtonContentPosition(const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState);
	virtual int __fastcall GetButtonHeight(void);
	virtual int __fastcall GetButtonWidth(Cxpc::TcxPCNavigatorButton Button);
	virtual int __fastcall GetFrameWidth(void);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	virtual Cxgraphics::TcxRegion* __fastcall GetTabClipRgn(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual bool __fastcall IsNativePainting(void);
	virtual bool __fastcall NeedShowFrame(void);
	virtual void __fastcall PaintButtonFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual void __fastcall PaintFrameBorder(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall PaintTabFrame(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	
public:
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TcxPCCustomPainter.Create */ inline __fastcall virtual TcxPCFlatPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCTabsPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCFlatPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCOffice11Painter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCOffice11Painter : public TcxPCUltraFlatPainter
{
	typedef TcxPCUltraFlatPainter inherited;
	
private:
	System::Uitypes::TColor __fastcall GetSelectedColor1(void);
	System::Uitypes::TColor __fastcall GetSelectedColor2(void);
	bool __fastcall IsGradientClientArea(void);
	bool __fastcall NeedShowMainTabOppositeRowLine(void);
	void __fastcall PaintMainTabOppositeRowLine(Cxgraphics::TcxCanvas* ACanvas);
	
protected:
	__classmethod virtual System::Uitypes::TColor __fastcall GetFrameColor();
	virtual void __fastcall DrawTabBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, int ATabVisibleIndex);
	virtual void __fastcall ExcludeUnderLine(System::Types::TRect &R);
	virtual void __fastcall FillPageClientRect(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Uitypes::TColor __fastcall GetButtonContentColor(Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual System::Uitypes::TColor __fastcall GetDefaultClientColor(void);
	virtual System::Types::TRect __fastcall GetPageClientRectOffset(void);
	virtual System::Types::TRect __fastcall GetFocusRect(void);
	virtual System::Uitypes::TColor __fastcall GetFreeSpaceColor(void);
	virtual System::Uitypes::TColor __fastcall GetMainTabRowUnderlineColor(void);
	virtual System::Types::TRect __fastcall GetMainTabRowUnderlineRect(void);
	virtual System::Uitypes::TColor __fastcall GetTabBodyColor(int TabVisibleIndex);
	virtual TcxPCTabsDelimiterOffsets __fastcall GetTabsDelimiterOffsets(void);
	virtual int __fastcall GetTabsDelimiterWidth(void);
	virtual int __fastcall GetTabsRowsDelimiterWidth(void);
	virtual bool __fastcall IsTabTransparent(int ATabVisibleIndex);
	virtual bool __fastcall NeedRedrawOnResize(void);
	virtual bool __fastcall NeedShowTabsRegionFrame(void);
	virtual void __fastcall PaintButtonBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AState);
	virtual void __fastcall PaintButtonFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual void __fastcall DoPaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintMainTabFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual void __fastcall PaintTabsDelimiter(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
	virtual void __fastcall PaintTabsRowsDelimiter(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARowRect, int ARowIndex);
	virtual void __fastcall PrepareDrawTabContentBitmapBackground(Cxgraphics::TcxBitmap* ABitmap, const System::Types::TPoint &ABitmapPos, int ATabVisibleIndex);
	virtual void __fastcall DrawTabContentBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor ABackgroundColor, int ATabVisibleIndex);
	void __fastcall DrawGradientBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, int ATabVisibleIndex, bool AHorizontal, bool AInverse);
	virtual Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	virtual bool __fastcall UseLookAndFeelTabButton(void);
	
public:
	virtual void __fastcall PaintPageClientArea(Cxgraphics::TcxCanvas* ACanvas);
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TcxPCCustomPainter.Create */ inline __fastcall virtual TcxPCOffice11Painter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCUltraFlatPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCOffice11Painter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCSlantedPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCSlantedPainter : public TcxPCStandardPainter
{
	typedef TcxPCStandardPainter inherited;
	
private:
	int FCutValue;
	System::Types::TRect __fastcall GetTabsLineRect(const Cxpc::TcxPCIndexInterval &ATabIndexInterval, bool AFullRect);
	System::Types::TRect __fastcall GetTabUnderlineRect(Cxpc::TcxTabViewInfo* ATabViewInfo);
	
protected:
	virtual bool __fastcall AlwaysColoredTabs(void);
	virtual void __fastcall CalculateButtonContentParameters(Cxpc::TcxPCNavigatorButton AButton, Cxpc::TcxPCNavigatorButtonState AState, /* out */ TcxPCNavigatorButtonContentParameters &AParameters);
	virtual int __fastcall CalculateTabNormalWidth(Cxpc::TcxTabViewInfo* ATabViewInfo);
	virtual void __fastcall CorrectTabNormalWidth(int &AValue);
	virtual System::Uitypes::TColor __fastcall GetButtonColor(Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual System::Uitypes::TColor __fastcall GetButtonContentColor(Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual int __fastcall GetButtonHeight(void);
	virtual int __fastcall GetButtonsDistance(Cxpc::TcxPCNavigatorButton AButton1, Cxpc::TcxPCNavigatorButton AButton2);
	virtual int __fastcall GetButtonsRegionFromTabsOffset(void);
	virtual int __fastcall GetButtonsRegionHOffset(void);
	virtual int __fastcall GetButtonsRegionWOffset(void);
	virtual int __fastcall GetButtonWidth(Cxpc::TcxPCNavigatorButton Button);
	virtual System::Uitypes::TColor __fastcall GetClientColor(void);
	virtual System::Types::TSize __fastcall GetCloseButtonSize(void);
	int __fastcall GetCutSideOffset(void);
	virtual System::Types::TRect __fastcall GetPageClientRectOffset(void);
	virtual int __fastcall GetDefaultTabNormalHeight(void);
	virtual System::Types::TRect __fastcall GetDrawImageOffset(int TabVisibleIndex);
	virtual System::Types::TRect __fastcall GetDrawTextHOffset(int TabVisibleIndex);
	virtual System::Types::TRect __fastcall GetFillClientRect(void);
	virtual int __fastcall GetFrameWidth(void);
	virtual int __fastcall GetImageTextDistance(int ATabVisibleIndex);
	virtual int __fastcall GetMinTabNormalWidth(int ATabVisibleIndex);
	virtual System::Uitypes::TColor __fastcall GetTabBodyColor(int TabVisibleIndex);
	virtual Cxgraphics::TcxRegion* __fastcall GetTabClipRgn(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual Cxpc::TcxPCWOffset __fastcall GetTabContentWOffset(int ATabVisibleIndex);
	virtual int __fastcall GetTabNormalContentOffset(int ATabVisibleIndex);
	virtual int __fastcall GetTabNormalImageAreaWidth(int ATabVisibleIndex);
	virtual int __fastcall GetTabNormalWidth(int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetTabsContainerOffsets(void);
	virtual Cxpc::TcxPCDistance __fastcall GetTabsNormalDistance(void);
	virtual System::Types::TRect __fastcall GetTabsRectOffset(void);
	virtual int __fastcall GetTabTextNormalWidth(int ATabVisibleIndex);
	virtual Cxpc::TcxPCWOffset __fastcall GetTooNarrowTabContentWOffset(int ATabVisibleIndex);
	virtual void __fastcall DrawFocusRect(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall Init(void);
	virtual int __fastcall InternalCalculateTabNormalHeight(void);
	virtual bool __fastcall PtInTab(int TabVisibleIndex, int X, int Y);
	virtual bool __fastcall IsTabBorderThick(int ATabVisibleIndex);
	virtual bool __fastcall IsCloseButtonOnSlantedSide(int ATabVisibleIndex);
	virtual void __fastcall PaintButtonFrame(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, Cxpc::TcxPCNavigatorButtonState AButtonState);
	virtual void __fastcall DoPaintPageFrame(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PaintTabShape(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall PaintTabsRegion(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall PrepareDrawTabContentBitmapBackground(Cxgraphics::TcxBitmap* ABitmap, const System::Types::TPoint &ABitmapPos, int ATabVisibleIndex);
	virtual void __fastcall DrawTabContentBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, System::Uitypes::TColor ABackgroundColor, int ATabVisibleIndex);
	virtual bool __fastcall CanLightMainTab(void);
	Cxgraphics::TcxRegion* __fastcall DirectionalGetFigureRegion(const System::Types::TRect &R, System::Types::TPoint *APoints, const int APoints_Size, TLinePosition *ALinePositions, const int ALinePositions_Size, Cxpc::TcxTabPosition ATabPositon, bool AForContent);
	HIDESBASE virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int ATabVisibleIndex, bool AHorizontalGradient, bool AInverseGradient);
	virtual void __fastcall DrawTabUnderline(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall GetBackgroundGradientColors(int ATabVisibleIndex, /* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	int __fastcall GetCutValue(void);
	virtual int __fastcall GetGeometricalMinTabWidth(void);
	virtual System::Uitypes::TColor __fastcall GetFrameColor(void);
	virtual Cxpc::TcxTabSlantPositions __fastcall GetSlantedSides(void);
	void __fastcall GetTabFramePolyline(int ATabVisibleIndex, /* out */ Dxcore::TPoints &APoints, /* out */ TLinePositions &ALinePositions);
	virtual System::Types::TSize __fastcall GetTabImageSize(void);
	virtual int __fastcall GetVerticalTextIndent(void);
	virtual int __fastcall InternalGetCutValue(void);
	virtual Cxgraphics::TcxRegion* __fastcall InternalGetTabClipRegion(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex, bool AForContent);
	virtual void __fastcall PaintTabFrame(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex, const System::Types::TRect &R);
	virtual void __fastcall PaintTabStateMark(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	__property Cxpc::TcxTabSlantPositions SlantedSides = {read=GetSlantedSides, nodefault};
	
public:
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TcxPCCustomPainter.Create */ inline __fastcall virtual TcxPCSlantedPainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCStandardPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCSlantedPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxPCOneNotePainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPCOneNotePainter : public TcxPCSlantedPainter
{
	typedef TcxPCSlantedPainter inherited;
	
protected:
	__classmethod virtual bool __fastcall AllowRotate();
	virtual bool __fastcall CanLightMainTab(void);
	virtual void __fastcall DrawTabUnderline(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	virtual void __fastcall GetBackgroundGradientColors(int ATabVisibleIndex, /* out */ System::Uitypes::TColor &AColor1, /* out */ System::Uitypes::TColor &AColor2);
	virtual int __fastcall GetButtonsRegionHOffset(void);
	virtual System::Types::TRect __fastcall GetDrawImageOffset(int TabVisibleIndex);
	virtual System::Types::TRect __fastcall GetDrawTextHOffset(int TabVisibleIndex);
	virtual System::Uitypes::TColor __fastcall GetFrameColor(void);
	virtual int __fastcall GetGeometricalMinTabWidth(void);
	virtual Cxpc::TcxTabSlantPositions __fastcall GetSlantedSides(void);
	virtual Cxpc::TcxPCWOffset __fastcall GetTabContentWOffset(int ATabVisibleIndex);
	virtual System::Types::TRect __fastcall GetTabsContainerOffsets(void);
	virtual Cxpc::TcxPCDistance __fastcall GetTabsNormalDistance(void);
	virtual System::Types::TRect __fastcall GetTabsRectOffset(void);
	virtual int __fastcall InternalGetCutValue(void);
	virtual Cxgraphics::TcxRegion* __fastcall InternalGetTabClipRegion(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex, bool AForContent);
	virtual bool __fastcall IsCloseButtonOnSlantedSide(int ATabVisibleIndex);
	virtual void __fastcall PaintTabFrame(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex, const System::Types::TRect &R);
	virtual void __fastcall PaintTabStateMark(Cxgraphics::TcxCanvas* ACanvas, int ATabVisibleIndex);
	
public:
	__classmethod virtual Cxpc::TcxPCStyleID __fastcall GetStyleID();
	__classmethod virtual Vcl::Controls::TCaption __fastcall GetStyleName();
	__classmethod virtual bool __fastcall HasLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
public:
	/* TcxPCCustomPainter.Create */ inline __fastcall virtual TcxPCOneNotePainter(Cxpc::TcxCustomTabControlViewInfo* AViewInfo) : TcxPCSlantedPainter(AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxPCOneNotePainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxpc::TcxPCWOffset cxPCEmptyWOffset;
static const System::Int8 cxPCTabsStyle = System::Int8(0x1);
static const System::Int8 cxPCButtonsStyle = System::Int8(0x2);
static const System::Int8 cxPCFlatButtonsStyle = System::Int8(0x3);
static const System::Int8 cxPCExtraFlatStyle = System::Int8(0x5);
static const System::Int8 cxPCUltraFlatStyle = System::Int8(0x6);
static const System::Int8 cxPCFlatStyle = System::Int8(0x7);
static const System::Int8 cxPCOffice11Style = System::Int8(0x8);
static const System::Int8 cxPCSlantedStyle = System::Int8(0x9);
static const System::Int8 cxPCOneNoteStyle = System::Int8(0xa);
static const System::Int8 cxPCSkinStyle = System::Int8(0xb);
static const System::Int8 StandardPainterTabControlFrameBorderWidth = System::Int8(0x2);
extern PACKAGE System::Uitypes::TColor cxPCLightBrushColor;
extern PACKAGE void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &ARect, Cxgraphics::TcxBorder *ASides, const int ASides_Size, System::Uitypes::TColor *AColors, const int AColors_Size, bool AExcludeBorder = false);
extern PACKAGE void __fastcall GetRectSize(const System::Types::TRect &R, bool AIsHorizontal, /* out */ int &ARWidth, /* out */ int &ARHeight);
extern PACKAGE void __fastcall RotateTabsDistance(Cxpc::TcxPCDistance &ADistance);
}	/* namespace Cxpcpainters */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPCPAINTERS)
using namespace Cxpcpainters;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpcpaintersHPP
