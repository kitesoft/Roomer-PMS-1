// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPreVw.pas' rev: 24.00 (Win64)

#ifndef DxprevwHPP
#define DxprevwHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Winapi.FlatSB.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <dxWrap.hpp>	// Pascal unit
#include <dxBkGnd.hpp>	// Pascal unit
#include <dxPSUtl.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <dxBase.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxprevw
{
//-- type declarations -------------------------------------------------------
enum TdxPreviewOptionBehavior : unsigned char { pobAllowDragMargins, pobHotTrack, pobKeyNavigation, pobStoreInRegistry, pobThumbTracking, pobAutoSwapMargins, pobNonCenterizePages };

typedef System::Set<TdxPreviewOptionBehavior, TdxPreviewOptionBehavior::pobAllowDragMargins, TdxPreviewOptionBehavior::pobNonCenterizePages>  TdxPreviewOptionsBehavior;

enum TdxPreviewOptionHint : unsigned char { pohShowForMargins, pohShowOnDrag, pohShowOnScroll };

typedef System::Set<TdxPreviewOptionHint, TdxPreviewOptionHint::pohShowForMargins, TdxPreviewOptionHint::pohShowOnScroll>  TdxPreviewOptionsHint;

enum TdxPreviewOptionStore : unsigned char { posZoom };

typedef System::Set<TdxPreviewOptionStore, TdxPreviewOptionStore::posZoom, TdxPreviewOptionStore::posZoom>  TdxPreviewOptionsStore;

enum TdxPreviewOptionView : unsigned char { povAutoHideScrollBars, povDefaultDrawPageBackground, povMargins, povPageSelection };

typedef System::Set<TdxPreviewOptionView, TdxPreviewOptionView::povAutoHideScrollBars, TdxPreviewOptionView::povPageSelection>  TdxPreviewOptionsView;

enum TdxPreviewOptionZoom : unsigned char { pozZoomOnClick, pozZoomOnMouseRoll };

typedef System::Set<TdxPreviewOptionZoom, TdxPreviewOptionZoom::pozZoomOnClick, TdxPreviewOptionZoom::pozZoomOnMouseRoll>  TdxPreviewOptionsZoom;

enum TdxPreviewDragStage : unsigned char { pdsAfter, pdsBefore, pdsDrag };

enum TdxPreviewMeasurementUnits : unsigned char { pmuDefault, pmuInches, pmuMillimeters, pmuCentimeters, pmuPoints, pmuPicas };

enum TdxPreviewPaperOrientation : unsigned char { ppoPortrait, ppoLandscape };

enum TdxPreviewScrollDirection : unsigned char { psdLeft, psdUp, psdRight, psdDown };

enum TdxPreviewZoomMode : unsigned char { pzmNone, pzmPageWidth, pzmPages };

typedef Winapi::Messages::TWMNoParams TCMHintHide;

typedef System::TMetaClass* TdxPreviewPageClass;

class DELPHICLASS TdxPreviewPage;
class DELPHICLASS TCustomdxPreview;
class PASCALIMPLEMENTATION TdxPreviewPage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TCustomdxPreview* FPreview;
	int __fastcall GetIndex(void);
	bool __fastcall GetPartVisible(void);
	bool __fastcall GetSelected(void);
	System::Types::TRect __fastcall GetSiteBounds(void);
	bool __fastcall GetVisible(void);
	bool __fastcall GetZoomed(void);
	void __fastcall SetSelected(bool Value);
	
public:
	__fastcall virtual TdxPreviewPage(TCustomdxPreview* APreview);
	__fastcall virtual ~TdxPreviewPage(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Uitypes::TCursor __fastcall GetCursor(void);
	bool __fastcall HasPoint(const System::Types::TPoint Pt)/* overload */;
	bool __fastcall HasPoint(int X, int Y)/* overload */;
	void __fastcall Invalidate(void);
	void __fastcall MakeVisible(void);
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property int Index = {read=GetIndex, nodefault};
	__property bool PartVisible = {read=GetPartVisible, nodefault};
	__property TCustomdxPreview* Preview = {read=FPreview};
	__property bool Selected = {read=GetSelected, write=SetSelected, nodefault};
	__property System::Types::TRect SiteBounds = {read=GetSiteBounds};
	__property bool Visible = {read=GetVisible, nodefault};
	__property bool Zoomed = {read=GetZoomed, nodefault};
};


class DELPHICLASS TdxPreviewPageContentCache;
class PASCALIMPLEMENTATION TdxPreviewPageContentCache : public Cxgraphics::TcxBitmap
{
	typedef Cxgraphics::TcxBitmap inherited;
	
private:
	bool FDirty;
	TdxPreviewPage* FPage;
	void __fastcall SetPage(TdxPreviewPage* AValue);
	
public:
	void __fastcall CheckSize(void);
	__property bool Dirty = {read=FDirty, write=FDirty, nodefault};
	__property TdxPreviewPage* Page = {read=FPage, write=SetPage};
public:
	/* TcxBitmap.Create */ inline __fastcall virtual TdxPreviewPageContentCache(void)/* overload */ : Cxgraphics::TcxBitmap() { }
	/* TcxBitmap.CreateSize */ inline __fastcall TdxPreviewPageContentCache(const System::Types::TRect &ARect)/* overload */ : Cxgraphics::TcxBitmap(ARect) { }
	/* TcxBitmap.CreateSize */ inline __fastcall virtual TdxPreviewPageContentCache(int AWidth, int AHeight)/* overload */ : Cxgraphics::TcxBitmap(AWidth, AHeight) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TdxPreviewPageContentCache(const System::Types::TRect &ARect, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : Cxgraphics::TcxBitmap(ARect, APixelFormat) { }
	/* TcxBitmap.CreateSize */ inline __fastcall TdxPreviewPageContentCache(int AWidth, int AHeight, Vcl::Graphics::TPixelFormat APixelFormat)/* overload */ : Cxgraphics::TcxBitmap(AWidth, AHeight, APixelFormat) { }
	/* TcxBitmap.Destroy */ inline __fastcall virtual ~TdxPreviewPageContentCache(void) { }
	
};


class DELPHICLASS TdxPreviewPageContentCachePool;
class PASCALIMPLEMENTATION TdxPreviewPageContentCachePool : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxPreviewPageContentCache* operator[](int Index) { return Items[Index]; }
	
private:
	int FCapacity;
	Cxclasses::TcxObjectList* FList;
	bool __fastcall Find(TdxPreviewPage* APage, /* out */ TdxPreviewPageContentCache* &AItem);
	bool __fastcall FindInvisible(TdxPreviewPage* APage, /* out */ TdxPreviewPageContentCache* &AItem);
	int __fastcall GetCount(void);
	TdxPreviewPageContentCache* __fastcall GetItem(int Index);
	
public:
	__fastcall virtual TdxPreviewPageContentCachePool(int ACapacity);
	__fastcall virtual ~TdxPreviewPageContentCachePool(void);
	TdxPreviewPageContentCache* __fastcall Add(TdxPreviewPage* APage);
	void __fastcall Invalidate(TdxPreviewPage* APage);
	void __fastcall InvalidateAll(void);
	void __fastcall Remove(TdxPreviewPage* APage);
	__property int Capacity = {read=FCapacity, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TdxPreviewPageContentCache* Items[int Index] = {read=GetItem/*, default*/};
};


enum TdxPreviewHitTest : unsigned char { phtNoWhere, phtPage, phtMarginLeft, phtMarginTop, phtMarginRight, phtMarginBottom, phtMarginHeader, phtMarginFooter };

typedef System::Set<TdxPreviewHitTest, TdxPreviewHitTest::phtNoWhere, TdxPreviewHitTest::phtMarginFooter>  TdxPreviewHitTests;

typedef System::TMetaClass* TdxPreviewPageMarginClass;

class DELPHICLASS TdxPreviewPageMargin;
class DELPHICLASS TdxPreviewPageMargins;
class PASCALIMPLEMENTATION TdxPreviewPageMargin : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::UnicodeString FCaption;
	int FDraggingPos;
	bool FEnabled;
	bool FIsCaptionAssigned;
	TdxPreviewPageMargins* FMargins;
	int FMaxValue;
	int FMinValue;
	HBITMAP FScreenBitmap;
	int FValue;
	bool FVisible;
	int __fastcall GetActualMaxValue(void);
	int __fastcall GetActualMinValue(void);
	int __fastcall GetActualValue(void);
	System::Types::TRect __fastcall GetBounds(void);
	System::UnicodeString __fastcall GetCaption(void);
	System::UnicodeString __fastcall GetDisplayText(void);
	int __fastcall GetDraggingValue(void);
	bool __fastcall GetIsDragging(void);
	bool __fastcall GetIsDraggingPosAssigned(void);
	int __fastcall GetMaxPos(void);
	int __fastcall GetMinPos(void);
	System::Types::TRect __fastcall GetPageBounds(void);
	TCustomdxPreview* __fastcall GetPreview(void);
	System::Types::TRect __fastcall GetSelectableBounds(void);
	int __fastcall GetVisibleValue(void);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsValueStored(void);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetDraggingPos(int Value);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetMaxValue(int AValue);
	void __fastcall SetMinValue(int AValue);
	void __fastcall SetValue(int AValue);
	void __fastcall SetVisible(bool Value);
	void __fastcall ReadIsCaptionAssigned(System::Classes::TReader* AReader);
	void __fastcall WriteIsCaptionAssigned(System::Classes::TWriter* AWriter);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual bool __fastcall GetIsForceRecalculatePageCount(void);
	virtual bool __fastcall GetIsForward(void);
	virtual bool __fastcall GetIsVertical(void);
	virtual int __fastcall DoGetActualMaxValue(void);
	virtual int __fastcall DoGetActualMinValue(void);
	virtual int __fastcall DoGetMaxMinValue(void);
	virtual int __fastcall DoPosFromValue(int AValue);
	virtual int __fastcall DoValueFromPos(int APos);
	virtual void __fastcall Changed(bool HardRefresh);
	virtual void __fastcall DoAssign(TdxPreviewPageMargin* Source);
	void __fastcall DoDragAfter(void);
	void __fastcall DoDragBefore(void);
	virtual void __fastcall DoRestoreDefaults(void);
	virtual void __fastcall Draw(HDC DC);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall Invert(HDC DC);
	int __fastcall CheckValue(int Value);
	int __fastcall PosFromValue(int AValue);
	int __fastcall ValueFromPos(int APos);
	__property int ActualMaxValue = {read=GetActualMaxValue, nodefault};
	__property int ActualMinValue = {read=GetActualMinValue, nodefault};
	__property int ActualValue = {read=GetActualValue, nodefault};
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property int DraggingPos = {read=FDraggingPos, write=SetDraggingPos, nodefault};
	__property bool IsForceRecalculatePageCount = {read=GetIsForceRecalculatePageCount, nodefault};
	__property int MaxPos = {read=GetMaxPos, nodefault};
	__property int MaxValue = {read=FMaxValue, write=SetMaxValue, nodefault};
	__property int MinPos = {read=GetMinPos, nodefault};
	__property System::Types::TRect PageBounds = {read=GetPageBounds};
	__property TCustomdxPreview* Preview = {read=GetPreview};
	__property System::Types::TRect SelectableBounds = {read=GetSelectableBounds};
	
public:
	__fastcall virtual TdxPreviewPageMargin(TdxPreviewPageMargins* AMargins);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall RestoreDefaults(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual int __fastcall DefaultValue(void);
	virtual TdxPreviewHitTest __fastcall GetHitTest(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(void);
	bool __fastcall HasPoint(const System::Types::TPoint Pt)/* overload */;
	bool __fastcall HasPoint(const System::Types::TSmallPoint Pt)/* overload */;
	bool __fastcall HasPoint(int X, int Y)/* overload */;
	__property System::UnicodeString DisplayText = {read=GetDisplayText};
	__property int DraggingValue = {read=GetDraggingValue, nodefault};
	__property bool IsDragging = {read=GetIsDragging, nodefault};
	__property bool IsDraggingPosAssigned = {read=GetIsDraggingPosAssigned, nodefault};
	__property bool IsForward = {read=GetIsForward, nodefault};
	__property bool IsVertical = {read=GetIsVertical, nodefault};
	__property TdxPreviewPageMargins* Margins = {read=FMargins};
	__property int VisibleValue = {read=GetVisibleValue, nodefault};
	
__published:
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption, stored=IsCaptionStored};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property int MinValue = {read=FMinValue, write=SetMinValue, default=0};
	__property int Value = {read=FValue, write=SetValue, stored=IsValueStored, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPreviewPageMargin(void) { }
	
};


class DELPHICLASS TdxPreviewPageMarginBottom;
class PASCALIMPLEMENTATION TdxPreviewPageMarginBottom : public TdxPreviewPageMargin
{
	typedef TdxPreviewPageMargin inherited;
	
protected:
	virtual bool __fastcall GetIsForceRecalculatePageCount(void);
	virtual bool __fastcall GetIsForward(void);
	virtual bool __fastcall GetIsVertical(void);
	virtual int __fastcall DoGetActualMaxValue(void);
	virtual int __fastcall DoGetActualMinValue(void);
	virtual int __fastcall DoGetMaxMinValue(void);
	virtual int __fastcall DoPosFromValue(int AValue);
	virtual int __fastcall DoValueFromPos(int APos);
	
public:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual int __fastcall DefaultValue(void);
	virtual TdxPreviewHitTest __fastcall GetHitTest(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(void);
public:
	/* TdxPreviewPageMargin.Create */ inline __fastcall virtual TdxPreviewPageMarginBottom(TdxPreviewPageMargins* AMargins) : TdxPreviewPageMargin(AMargins) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPreviewPageMarginBottom(void) { }
	
};


class DELPHICLASS TdxPreviewPageMarginFooter;
class PASCALIMPLEMENTATION TdxPreviewPageMarginFooter : public TdxPreviewPageMargin
{
	typedef TdxPreviewPageMargin inherited;
	
protected:
	virtual bool __fastcall GetIsForward(void);
	virtual bool __fastcall GetIsVertical(void);
	virtual int __fastcall DoGetActualMaxValue(void);
	virtual int __fastcall DoGetMaxMinValue(void);
	virtual int __fastcall DoPosFromValue(int AValue);
	virtual int __fastcall DoValueFromPos(int APos);
	
public:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual int __fastcall DefaultValue(void);
	virtual TdxPreviewHitTest __fastcall GetHitTest(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(void);
public:
	/* TdxPreviewPageMargin.Create */ inline __fastcall virtual TdxPreviewPageMarginFooter(TdxPreviewPageMargins* AMargins) : TdxPreviewPageMargin(AMargins) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPreviewPageMarginFooter(void) { }
	
};


class DELPHICLASS TdxPreviewPageMarginHeader;
class PASCALIMPLEMENTATION TdxPreviewPageMarginHeader : public TdxPreviewPageMargin
{
	typedef TdxPreviewPageMargin inherited;
	
protected:
	virtual bool __fastcall GetIsForward(void);
	virtual bool __fastcall GetIsVertical(void);
	virtual int __fastcall DoGetActualMaxValue(void);
	virtual int __fastcall DoGetMaxMinValue(void);
	virtual int __fastcall DoPosFromValue(int AValue);
	virtual int __fastcall DoValueFromPos(int APos);
	
public:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual int __fastcall DefaultValue(void);
	virtual TdxPreviewHitTest __fastcall GetHitTest(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(void);
public:
	/* TdxPreviewPageMargin.Create */ inline __fastcall virtual TdxPreviewPageMarginHeader(TdxPreviewPageMargins* AMargins) : TdxPreviewPageMargin(AMargins) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPreviewPageMarginHeader(void) { }
	
};


class DELPHICLASS TdxPreviewPageMarginLeft;
class PASCALIMPLEMENTATION TdxPreviewPageMarginLeft : public TdxPreviewPageMargin
{
	typedef TdxPreviewPageMargin inherited;
	
protected:
	virtual bool __fastcall GetIsForceRecalculatePageCount(void);
	virtual bool __fastcall GetIsForward(void);
	virtual bool __fastcall GetIsVertical(void);
	virtual int __fastcall DoGetActualMaxValue(void);
	virtual int __fastcall DoGetMaxMinValue(void);
	virtual int __fastcall DoPosFromValue(int AValue);
	virtual int __fastcall DoValueFromPos(int APos);
	
public:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual int __fastcall DefaultValue(void);
	virtual TdxPreviewHitTest __fastcall GetHitTest(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(void);
public:
	/* TdxPreviewPageMargin.Create */ inline __fastcall virtual TdxPreviewPageMarginLeft(TdxPreviewPageMargins* AMargins) : TdxPreviewPageMargin(AMargins) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPreviewPageMarginLeft(void) { }
	
};


class DELPHICLASS TdxPreviewPageMarginRight;
class PASCALIMPLEMENTATION TdxPreviewPageMarginRight : public TdxPreviewPageMargin
{
	typedef TdxPreviewPageMargin inherited;
	
protected:
	virtual bool __fastcall GetIsForceRecalculatePageCount(void);
	virtual bool __fastcall GetIsForward(void);
	virtual bool __fastcall GetIsVertical(void);
	virtual int __fastcall DoGetActualMaxValue(void);
	virtual int __fastcall DoGetMaxMinValue(void);
	virtual int __fastcall DoPosFromValue(int AValue);
	virtual int __fastcall DoValueFromPos(int APos);
	
public:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual int __fastcall DefaultValue(void);
	virtual TdxPreviewHitTest __fastcall GetHitTest(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(void);
public:
	/* TdxPreviewPageMargin.Create */ inline __fastcall virtual TdxPreviewPageMarginRight(TdxPreviewPageMargins* AMargins) : TdxPreviewPageMargin(AMargins) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPreviewPageMarginRight(void) { }
	
};


class DELPHICLASS TdxPreviewPageMarginTop;
class PASCALIMPLEMENTATION TdxPreviewPageMarginTop : public TdxPreviewPageMargin
{
	typedef TdxPreviewPageMargin inherited;
	
protected:
	virtual bool __fastcall GetIsForceRecalculatePageCount(void);
	virtual bool __fastcall GetIsForward(void);
	virtual bool __fastcall GetIsVertical(void);
	virtual int __fastcall DoGetActualMaxValue(void);
	virtual int __fastcall DoGetActualMinValue(void);
	virtual int __fastcall DoGetMaxMinValue(void);
	virtual int __fastcall DoPosFromValue(int AValue);
	virtual int __fastcall DoValueFromPos(int APos);
	
public:
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual int __fastcall DefaultValue(void);
	virtual TdxPreviewHitTest __fastcall GetHitTest(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(void);
public:
	/* TdxPreviewPageMargin.Create */ inline __fastcall virtual TdxPreviewPageMarginTop(TdxPreviewPageMargins* AMargins) : TdxPreviewPageMargin(AMargins) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPreviewPageMarginTop(void) { }
	
};


typedef System::TMetaClass* TdxPreviewPageMarginsClass;

class PASCALIMPLEMENTATION TdxPreviewPageMargins : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TdxPreviewPageMargin* operator[](int Index) { return Margins[Index]; }
	
private:
	System::Classes::TList* FMargins;
	TCustomdxPreview* FPreview;
	int FUpdateCount;
	int __fastcall GetCount(void);
	TdxPreviewPageMargin* __fastcall GetMargin(int Index);
	TdxPreviewPageMarginBottom* __fastcall GetMarginBottom(void);
	TdxPreviewPageMargin* __fastcall GetMarginByCaption(const System::UnicodeString Caption);
	TdxPreviewPageMargin* __fastcall GetMarginByClass(TdxPreviewPageMarginClass Index);
	TdxPreviewPageMarginFooter* __fastcall GetMarginFooter(void);
	TdxPreviewPageMarginHeader* __fastcall GetMarginHeader(void);
	TdxPreviewPageMarginLeft* __fastcall GetMarginLeft(void);
	TdxPreviewPageMarginRight* __fastcall GetMarginRight(void);
	TdxPreviewPageMarginTop* __fastcall GetMarginTop(void);
	void __fastcall SetMargin(int Index, TdxPreviewPageMargin* Value);
	void __fastcall SetMarginByClass(TdxPreviewPageMarginClass Index, TdxPreviewPageMargin* Value);
	void __fastcall SetMarginBottom(TdxPreviewPageMarginBottom* Value);
	void __fastcall SetMarginFooter(TdxPreviewPageMarginFooter* Value);
	void __fastcall SetMarginHeader(TdxPreviewPageMarginHeader* Value);
	void __fastcall SetMarginLeft(TdxPreviewPageMarginLeft* Value);
	void __fastcall SetMarginRight(TdxPreviewPageMarginRight* Value);
	void __fastcall SetMarginTop(TdxPreviewPageMarginTop* Value);
	
protected:
	virtual void __fastcall DoAssign(TdxPreviewPageMargins* Source);
	virtual void __fastcall DoRestoreDefaults(void);
	virtual TdxPreviewPageMargin* __fastcall AddMargin(TdxPreviewPageMarginClass AClass);
	virtual void __fastcall AddMargins(void);
	void __fastcall FreeAndNilMargins(void);
	virtual void __fastcall Update(TdxPreviewPageMargin* AMargin);
	
public:
	__fastcall virtual TdxPreviewPageMargins(TCustomdxPreview* APreview);
	__fastcall virtual ~TdxPreviewPageMargins(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall RestoreDefaults(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	__property int Count = {read=GetCount, nodefault};
	__property TdxPreviewPageMargin* Margins[int Index] = {read=GetMargin, write=SetMargin/*, default*/};
	__property TdxPreviewPageMargin* MarginsByCaption[const System::UnicodeString Caption] = {read=GetMarginByCaption};
	__property TdxPreviewPageMargin* MarginsByClass[TdxPreviewPageMarginClass Index] = {read=GetMarginByClass, write=SetMarginByClass};
	__property TCustomdxPreview* Preview = {read=FPreview};
	
__published:
	__property TdxPreviewPageMarginBottom* Bottom = {read=GetMarginBottom, write=SetMarginBottom};
	__property TdxPreviewPageMarginFooter* Footer = {read=GetMarginFooter, write=SetMarginFooter};
	__property TdxPreviewPageMarginHeader* Header = {read=GetMarginHeader, write=SetMarginHeader};
	__property TdxPreviewPageMarginLeft* Left = {read=GetMarginLeft, write=SetMarginLeft};
	__property TdxPreviewPageMarginRight* Right = {read=GetMarginRight, write=SetMarginRight};
	__property TdxPreviewPageMarginTop* Top = {read=GetMarginTop, write=SetMarginTop};
};


class DELPHICLASS TdxPreviewPageBackground;
class PASCALIMPLEMENTATION TdxPreviewPageBackground : public Dxbkgnd::TdxBackground
{
	typedef Dxbkgnd::TdxBackground inherited;
	
private:
	Vcl::Graphics::TBitmap* FBitmap;
	TCustomdxPreview* FPreview;
	
protected:
	DYNAMIC void __fastcall DoApply(void);
	DYNAMIC void __fastcall DoChange(Dxbkgnd::TdxBackgroundParams AChangeWhats);
	bool __fastcall HasPreview(void);
	
public:
	__fastcall virtual TdxPreviewPageBackground(void);
	__fastcall virtual ~TdxPreviewPageBackground(void);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R);
	__property TCustomdxPreview* Preview = {read=FPreview};
	__property OnApply;
};


typedef void __fastcall (__closure *TdxDrawPageContentEvent)(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, int APageIndex);

typedef void __fastcall (__closure *TdxGetPageNumberHintEvent)(System::TObject* Sender, int AStartPage, int AEndPage, System::UnicodeString &AHintString);

typedef void __fastcall (__closure *TdxCanShowMarginHintEvent)(System::TObject* Sender, bool &ACanShowHint);

typedef void __fastcall (__closure *TdxMarginEvent)(System::TObject* Sender, TdxPreviewPageMargin* AMargin);

typedef void __fastcall (__closure *TdxPreviewPageEvent)(System::TObject* Sender, int APageIndex);

typedef void __fastcall (__closure *TdxPageBackgroundDrawEvent)(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, int APageIndex);

typedef void __fastcall (__closure *TdxSelectingPageEvent)(System::TObject* Sender, int APagePage, bool &ACanSelect);

class PASCALIMPLEMENTATION TCustomdxPreview : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	int FAbsoluteIndentLeft;
	int FAbsoluteIndentRight;
	System::Types::TPoint FActualOriginalPageSize;
	int FBeforeDragPos;
	Vcl::Forms::TFormBorderStyle FBorderStyle;
	TdxPreviewPageMargin* FDraggingMargin;
	int FDragOffset;
	Vcl::Extctrls::TTimer* FHintHideLongTimer;
	Vcl::Extctrls::TTimer* FHintHideShortTimer;
	Vcl::Extctrls::TTimer* FHintShowTimer;
	Vcl::Controls::TCustomControl* FHintWindow;
	Vcl::Controls::TCustomControl* FHintWindowPageNumber;
	int FIndent;
	bool FIsMarginDropping;
	bool FIsNoPagesTextAssigned;
	System::Types::TPoint FLastMousePos;
	int FLeftPos;
	System::Uitypes::TColor FMarginColor;
	HPEN FMarginPen;
	TdxPreviewPageMargins* FMargins;
	int FMaxZoomFactor;
	TdxPreviewMeasurementUnits FMeasurementUnits;
	int FMinFooterSize;
	int FMinHeaderSize;
	System::Types::TPoint FMinUsefulSize;
	int FMinZoomFactor;
	System::UnicodeString FNoPagesText;
	TdxMarginEvent FOnAfterDragMargin;
	TdxMarginEvent FOnBeforeDragMargin;
	System::Classes::TNotifyEvent FOnCalcPageCount;
	TdxCanShowMarginHintEvent FOnCanShowMarginHint;
	System::Classes::TNotifyEvent FOnChangePageCount;
	TdxMarginEvent FOnDragMargin;
	TdxPageBackgroundDrawEvent FOnDrawPageBackground;
	TdxDrawPageContentEvent FOnDrawPageContent;
	TdxGetPageNumberHintEvent FOnGetPageNumberHint;
	TdxMarginEvent FOnMarginChanged;
	TdxDrawPageContentEvent FOnPostDrawPageContent;
	TdxPreviewPageEvent FOnSelectedPageChanged;
	TdxPreviewPageEvent FOnSelectedPageChanging;
	TdxSelectingPageEvent FOnSelectingPage;
	System::Classes::TNotifyEvent FOnZoomFactorChanged;
	System::Classes::TNotifyEvent FOnZoomModeChanged;
	TdxPreviewOptionsBehavior FOptionsBehavior;
	TdxPreviewOptionsHint FOptionsHint;
	TdxPreviewOptionsStore FOptionsStore;
	TdxPreviewOptionsView FOptionsView;
	TdxPreviewOptionsZoom FOptionsZoom;
	TdxPreviewPaperOrientation FOrientation;
	Dxwrap::TdxPointWrapper* FOriginalPageSize;
	Dxbkgnd::TdxBackground* FPageBackground;
	System::Classes::TList* FPages;
	TdxPreviewPageContentCachePool* FPagesContentCache;
	System::Types::TPoint FPageSize;
	int FPageXCount;
	int FPageYCount;
	System::UnicodeString FRegistryPath;
	System::Uitypes::TScrollStyle FScrollBars;
	Vcl::Forms::TScrollBarStyle FScrollBarStyle;
	int FSelPageIndex;
	int FTopPos;
	bool FTransparent;
	int FUnzoomedFactor;
	TdxPreviewZoomMode FUnzoomedMode;
	int FUpdateCount;
	bool FZoomed;
	bool FZoomedFixed;
	int FZoomFactor;
	bool FZooming;
	TdxPreviewZoomMode FZoomMode;
	bool FZoomModeFixed;
	int FZoomStep;
	int __fastcall GetAbsoluteIndent(void);
	TdxPreviewMeasurementUnits __fastcall GetActualMeasurementUnits(void);
	int __fastcall GetAllRowCount(void);
	HIDESBASE int __fastcall GetClientHeight(void);
	HIDESBASE int __fastcall GetClientWidth(void);
	int __fastcall GetColCount(void);
	int __fastcall GetContentHeight(void);
	int __fastcall GetContentWidth(void);
	System::UnicodeString __fastcall GetNoPagesText(void);
	TdxPreviewPage* __fastcall GetPage(int Index);
	System::Types::TRect __fastcall GetPageBorders(void);
	int __fastcall GetPageCount(void);
	int __fastcall GetRowCount(void);
	int __fastcall GetSelPageCol(void);
	int __fastcall GetSelPageRow(void);
	int __fastcall GetVirtualHeight(void);
	int __fastcall GetVirtualWidth(void);
	System::Types::TPoint __fastcall GetVisiblePageSize(void);
	bool __fastcall IsNoPagesTextStored(void);
	HIDESBASE void __fastcall SetBorderStyle(Vcl::Forms::TBorderStyle Value);
	void __fastcall SetLeftPos(int Value);
	void __fastcall SetMarginColor(System::Uitypes::TColor Value);
	HIDESBASE void __fastcall SetMargins(TdxPreviewPageMargins* Value);
	void __fastcall SetMaxZoomFactor(int Value);
	void __fastcall SetMinZoomFactor(int Value);
	void __fastcall SetMinFooterSize(int Value);
	void __fastcall SetMinHeaderSize(int Value);
	void __fastcall SetMinUsefulSize(const System::Types::TPoint Value);
	void __fastcall SetNoPagesText(const System::UnicodeString Value);
	void __fastcall SetOnCalcPageCount(System::Classes::TNotifyEvent Value);
	void __fastcall SetOptionsBehavior(TdxPreviewOptionsBehavior Value);
	void __fastcall SetOptionsHint(TdxPreviewOptionsHint Value);
	void __fastcall SetOptionsStore(TdxPreviewOptionsStore Value);
	void __fastcall SetOptionsView(TdxPreviewOptionsView Value);
	void __fastcall SetOptionsZoom(TdxPreviewOptionsZoom Value);
	void __fastcall SetOrientation(TdxPreviewPaperOrientation Value);
	void __fastcall SetOriginalPageSize(Dxwrap::TdxPointWrapper* Value);
	void __fastcall SetPageBackground(Dxbkgnd::TdxBackground* Value);
	void __fastcall SetPageCount(int Value);
	void __fastcall SetPageXCount(int Value);
	void __fastcall SetPageYCount(int Value);
	HIDESBASE void __fastcall SetScrollBars(System::Uitypes::TScrollStyle Value);
	void __fastcall SetScrollBarStyle(Vcl::Forms::TScrollBarStyle Value);
	void __fastcall SetSelPageIndex(int Value);
	void __fastcall SetTopPos(int Value);
	void __fastcall SetTransparent(bool AValue);
	void __fastcall SetZoomed(bool Value);
	void __fastcall SetZoomFactor(int Value);
	void __fastcall SetZoomMode(TdxPreviewZoomMode Value);
	void __fastcall SetZoomStep(int Value);
	void __fastcall AdjustOrientation(void);
	void __fastcall AdjustPagesBounds(void);
	void __fastcall PageParametersChanging(System::TObject* Sender, Dxwrap::TdxPointCoords Coords, int *Values, const int Values_Size);
	void __fastcall PageParametersChanged(System::TObject* Sender, Dxwrap::TdxPointCoords Coords);
	void __fastcall ResyncSelPageIndex(void);
	bool __fastcall CanAnyScrolling(void);
	bool __fastcall CanHorzScrollBarBeVisible(void);
	bool __fastcall CanHorzScrolling(void);
	bool __fastcall CanPageScrolling(TdxPreviewScrollDirection ADirection);
	bool __fastcall CanVertScrollBarBeVisible(void);
	bool __fastcall CanVertScrolling(void);
	void __fastcall ScrollPage(TdxPreviewScrollDirection ADirection);
	bool __fastcall CanChangeMargins(void);
	void __fastcall CancelDragMargin(void);
	void __fastcall ClearLastMousePos(void);
	void __fastcall FreeMarginPen(void);
	void __fastcall RecreateMarginPen(void);
	void __fastcall StopMarginDragging(void);
	void __fastcall ActivateHint(TdxPreviewPageMargin* AMargin);
	void __fastcall CancelHintHide(void);
	void __fastcall CancelHintShow(void);
	void __fastcall CreateHint(void);
	void __fastcall DestroyHint(void);
	void __fastcall ResetHintShowTimer(int X, int Y);
	void __fastcall StartHintShow(void);
	void __fastcall DestroyPageNumberHint(void);
	void __fastcall UpdatePageNumberHint(void);
	void __fastcall DesignerModified(void);
	HIDESBASE bool __fastcall IsDesigning(void);
	bool __fastcall IsParentFormActive(void);
	void __fastcall HintHideLongTimerHandler(System::TObject* Sender);
	void __fastcall HintHideShortTimerHandler(System::TObject* Sender);
	void __fastcall HintShowTimerHandler(System::TObject* Sender);
	void __fastcall ReadIsNoPagesTextAssigned(System::Classes::TReader* AReader);
	void __fastcall WriteIsNoPagesTextAssigned(System::Classes::TWriter* AWriter);
	MESSAGE void __fastcall CMCancelMode(Vcl::Controls::TCMCancelMode &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMDesignHitTest(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall CMHintShow(Vcl::Controls::TCMHintShow &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMCaptureChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMRButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseActivate(Winapi::Messages::TWMMouseActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseWheel(Winapi::Messages::TWMMouseWheel &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCDestroy(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	
protected:
	DYNAMIC void __fastcall AdjustSize(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC void __fastcall DblClick(void);
	virtual int __fastcall GetDefaultPanOptions(void);
	virtual Cxcontrols::TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall IsDefaultGesture(int AGestureID);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall ScrollHorizontal(System::Uitypes::TScrollCode AScrollCode, int AScrollPos);
	virtual void __fastcall ScrollVertical(System::Uitypes::TScrollCode AScrollCode, int AScrollPos);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual TdxPreviewPageMargins* __fastcall CreateMargins(void);
	virtual TdxPreviewPageMarginsClass __fastcall GetMarginsClass(void);
	virtual TdxPreviewPage* __fastcall CreatePage(void);
	virtual TdxPreviewPageClass __fastcall GetPageClass(void);
	void __fastcall ContentAreaChanged(void);
	int __fastcall CheckLeftPos(int Value);
	int __fastcall CheckTopPos(int Value);
	void __fastcall CheckLeftTopPosition(void);
	void __fastcall CheckMargins(void);
	void __fastcall CheckZoomFactor(void);
	void __fastcall UpdatePreviewIndents(void);
	int __fastcall CalculateIndent(void);
	DYNAMIC bool __fastcall CanSelectPage(int APageIndex);
	DYNAMIC bool __fastcall CanShowMarginHint(void);
	Cxgraphics::TcxRegion* __fastcall CreateBackgroundRegion(const System::Types::TRect &APageBounds);
	DYNAMIC void __fastcall DoAfterDragMargin(TdxPreviewPageMargin* AMargin);
	DYNAMIC void __fastcall DoBeforeDragMargin(TdxPreviewPageMargin* AMargin);
	DYNAMIC void __fastcall DoCalcPageCount(void);
	DYNAMIC void __fastcall DoChangePageCount(void);
	DYNAMIC void __fastcall DoDragMargin(TdxPreviewPageMargin* AMargin);
	DYNAMIC void __fastcall DoDrawPageContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, int APageIndex);
	DYNAMIC void __fastcall DoGetPageNumberHintText(/* out */ System::UnicodeString &AText);
	DYNAMIC void __fastcall DoMarginChanged(TdxPreviewPageMargin* AMargin);
	DYNAMIC void __fastcall DoZoomFactorChanged(void);
	DYNAMIC void __fastcall DoZoomModeChanged(void);
	DYNAMIC void __fastcall DoSelectedPageChanging(void);
	DYNAMIC void __fastcall DoSelectedPageChanged(void);
	void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawMargins(HDC DC);
	void __fastcall DrawNoPages(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawPage(Cxgraphics::TcxCanvas* ACanvas, TdxPreviewPage* APage, bool ASelected);
	virtual void __fastcall DrawPageBackground(Cxgraphics::TcxCanvas* ACanvas, TdxPreviewPage* APage, bool ASelected);
	void __fastcall DrawPages(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawPreviewBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall InvalidateMargins(void);
	__property int AbsoluteIndent = {read=GetAbsoluteIndent, nodefault};
	__property int AbsoluteIndentLeft = {read=FAbsoluteIndentLeft, nodefault};
	__property int AbsoluteIndentRight = {read=FAbsoluteIndentRight, nodefault};
	__property int ContentHeight = {read=GetContentHeight, nodefault};
	__property int ContentWidth = {read=GetContentWidth, nodefault};
	__property TdxPreviewPageContentCachePool* PagesContentCache = {read=FPagesContentCache};
	__property Vcl::Forms::TScrollBarStyle ScrollBarStyle = {read=FScrollBarStyle, write=SetScrollBarStyle, default=0};
	
public:
	__fastcall virtual TCustomdxPreview(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxPreview(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall LoadFromRegistry(const System::UnicodeString ARegistryPath);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToRegistry(const System::UnicodeString ARegistryPath);
	virtual System::UnicodeString __fastcall DefaultNoPagesText(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	bool __fastcall IsUpdateLocked(void);
	void __fastcall GetPartVisiblePageRanges(System::PInteger AStartIndex, System::PInteger AEndIndex)/* overload */;
	void __fastcall GetPartVisiblePageRanges(/* out */ int &AStartIndex, /* out */ int &AEndIndex)/* overload */;
	void __fastcall GetVisiblePageRanges(System::PInteger AStartIndex, System::PInteger AEndIndex)/* overload */;
	void __fastcall GetVisiblePageRanges(/* out */ int &AStartIndex, /* out */ int &AEndIndex)/* overload */;
	void __fastcall InvalidatePage(int APageIndex);
	void __fastcall InvalidatePages(void);
	void __fastcall InvalidatePagesContent(void);
	void __fastcall InvalidatePagesFooter(void);
	void __fastcall InvalidatePagesHeader(void);
	TdxPreviewHitTests __fastcall GetHitInfoAt(const System::Types::TPoint Pt)/* overload */;
	TdxPreviewHitTests __fastcall GetHitInfoAt(const System::Types::TSmallPoint Pt)/* overload */;
	TdxPreviewHitTests __fastcall GetHitInfoAt(int X, int Y)/* overload */;
	void __fastcall CalcPagesBounds(int ATopPos, int AWidth, int AHeight);
	void __fastcall FullRefresh(void);
	void __fastcall HideAllHints(void);
	void __fastcall MakeVisible(int APageIndex);
	void __fastcall SetPageXYCount(int XCount, int YCount);
	void __fastcall ZoomIn(void);
	void __fastcall ZoomOut(void);
	TdxPreviewPageMargin* __fastcall MarginFromPoint(const System::Types::TPoint Pt)/* overload */;
	TdxPreviewPageMargin* __fastcall MarginFromPoint(const System::Types::TSmallPoint Pt)/* overload */;
	TdxPreviewPageMargin* __fastcall MarginFromPoint(int X, int Y)/* overload */;
	System::UnicodeString __fastcall MarginValueToString(int Value);
	int __fastcall IndexOfPage(TdxPreviewPage* APage);
	int __fastcall PageIndexFromPoint(const System::Types::TPoint Pt)/* overload */;
	int __fastcall PageIndexFromPoint(const System::Types::TSmallPoint Pt)/* overload */;
	int __fastcall PageIndexFromPoint(int X, int Y)/* overload */;
	System::UnicodeString __fastcall PageSizeToString(void);
	void __fastcall SelectFirstPage(void);
	void __fastcall SelectLastPage(void);
	void __fastcall SelectNextPage(void);
	void __fastcall SelectPrevPage(void);
	__property TdxPreviewMeasurementUnits ActualMeasurementUnits = {read=GetActualMeasurementUnits, nodefault};
	__property System::Types::TPoint ActualOriginalPageSize = {read=FActualOriginalPageSize};
	__property int AllRowCount = {read=GetAllRowCount, nodefault};
	__property Vcl::Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=SetBorderStyle, default=1};
	__property int ClientHeight = {read=GetClientHeight, nodefault};
	__property int ClientWidth = {read=GetClientWidth, nodefault};
	__property int ColCount = {read=GetColCount, nodefault};
	__property TdxPreviewPageMargin* DraggingMargin = {read=FDraggingMargin};
	__property int Indent = {read=FIndent, nodefault};
	__property int LeftPos = {read=FLeftPos, write=SetLeftPos, nodefault};
	__property System::Uitypes::TColor MarginColor = {read=FMarginColor, write=SetMarginColor, default=-16777208};
	__property TdxPreviewPageMargins* Margins = {read=FMargins, write=SetMargins};
	__property int MaxZoomFactor = {read=FMaxZoomFactor, write=SetMaxZoomFactor, default=500};
	__property TdxPreviewMeasurementUnits MeasurementUnits = {read=FMeasurementUnits, write=FMeasurementUnits, default=0};
	__property int MinFooterSize = {read=FMinFooterSize, write=SetMinFooterSize, default=127};
	__property int MinHeaderSize = {read=FMinHeaderSize, write=SetMinHeaderSize, default=127};
	__property System::Types::TPoint MinUsefulSize = {read=FMinUsefulSize, write=SetMinUsefulSize};
	__property int MinZoomFactor = {read=FMinZoomFactor, write=SetMinZoomFactor, default=10};
	__property System::UnicodeString NoPagesText = {read=GetNoPagesText, write=SetNoPagesText, stored=IsNoPagesTextStored};
	__property TdxPreviewOptionsBehavior OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior, default=53};
	__property TdxPreviewOptionsHint OptionsHint = {read=FOptionsHint, write=SetOptionsHint, default=7};
	__property TdxPreviewOptionsStore OptionsStore = {read=FOptionsStore, write=SetOptionsStore, default=1};
	__property TdxPreviewOptionsView OptionsView = {read=FOptionsView, write=SetOptionsView, default=15};
	__property TdxPreviewOptionsZoom OptionsZoom = {read=FOptionsZoom, write=SetOptionsZoom, default=1};
	__property TdxPreviewPaperOrientation Orientation = {read=FOrientation, write=SetOrientation, default=0};
	__property Dxwrap::TdxPointWrapper* OriginalPageSize = {read=FOriginalPageSize, write=SetOriginalPageSize};
	__property Dxbkgnd::TdxBackground* PageBackground = {read=FPageBackground, write=SetPageBackground};
	__property System::Types::TRect PageBorders = {read=GetPageBorders};
	__property int PageCount = {read=GetPageCount, write=SetPageCount, nodefault};
	__property TdxPreviewPage* Pages[int Index] = {read=GetPage};
	__property System::Types::TPoint PageSize = {read=FPageSize};
	__property int PageXCount = {read=FPageXCount, write=SetPageXCount, default=1};
	__property int PageYCount = {read=FPageYCount, write=SetPageYCount, default=1};
	__property System::UnicodeString RegistryPath = {read=FRegistryPath, write=FRegistryPath};
	__property int RowCount = {read=GetRowCount, nodefault};
	__property System::Uitypes::TScrollStyle ScrollBars = {read=FScrollBars, write=SetScrollBars, default=3};
	__property int SelPageCol = {read=GetSelPageCol, nodefault};
	__property int SelPageIndex = {read=FSelPageIndex, write=SetSelPageIndex, nodefault};
	__property int SelPageRow = {read=GetSelPageRow, nodefault};
	__property int TopPos = {read=FTopPos, write=SetTopPos, nodefault};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, nodefault};
	__property int VirtualHeight = {read=GetVirtualHeight, nodefault};
	__property int VirtualWidth = {read=GetVirtualWidth, nodefault};
	__property System::Types::TPoint VisiblePageSize = {read=GetVisiblePageSize};
	__property bool Zoomed = {read=FZoomed, write=SetZoomed, nodefault};
	__property int ZoomFactor = {read=FZoomFactor, write=SetZoomFactor, stored=true, default=100};
	__property TdxPreviewZoomMode ZoomMode = {read=FZoomMode, write=SetZoomMode, default=0};
	__property int ZoomStep = {read=FZoomStep, write=SetZoomStep, default=10};
	__property TdxMarginEvent OnAfterDragMargin = {read=FOnAfterDragMargin, write=FOnAfterDragMargin};
	__property TdxMarginEvent OnBeforeDragMargin = {read=FOnBeforeDragMargin, write=FOnBeforeDragMargin};
	__property System::Classes::TNotifyEvent OnCalcPageCount = {read=FOnCalcPageCount, write=SetOnCalcPageCount};
	__property TdxPageBackgroundDrawEvent OnDrawPageBackground = {read=FOnDrawPageBackground, write=FOnDrawPageBackground};
	__property TdxMarginEvent OnDragMargin = {read=FOnDragMargin, write=FOnDragMargin};
	__property TdxDrawPageContentEvent OnDrawPageContent = {read=FOnDrawPageContent, write=FOnDrawPageContent};
	__property TdxGetPageNumberHintEvent OnGetPageNumberHint = {read=FOnGetPageNumberHint, write=FOnGetPageNumberHint};
	__property TdxCanShowMarginHintEvent OnCanShowMarginHint = {read=FOnCanShowMarginHint, write=FOnCanShowMarginHint};
	__property System::Classes::TNotifyEvent OnChangePageCount = {read=FOnChangePageCount, write=FOnChangePageCount};
	__property TdxMarginEvent OnMarginChanged = {read=FOnMarginChanged, write=FOnMarginChanged};
	__property TdxDrawPageContentEvent OnPostDrawPageContent = {read=FOnPostDrawPageContent, write=FOnPostDrawPageContent};
	__property TdxPreviewPageEvent OnSelectedPageChanged = {read=FOnSelectedPageChanged, write=FOnSelectedPageChanged};
	__property TdxPreviewPageEvent OnSelectedPageChanging = {read=FOnSelectedPageChanging, write=FOnSelectedPageChanging};
	__property TdxSelectingPageEvent OnSelectingPage = {read=FOnSelectingPage, write=FOnSelectingPage};
	__property System::Classes::TNotifyEvent OnZoomFactorChanged = {read=FOnZoomFactorChanged, write=FOnZoomFactorChanged};
	__property System::Classes::TNotifyEvent OnZoomModeChanged = {read=FOnZoomModeChanged, write=FOnZoomModeChanged};
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomdxPreview(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class DELPHICLASS TdxPreview;
class PASCALIMPLEMENTATION TdxPreview : public TCustomdxPreview
{
	typedef TCustomdxPreview inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BorderStyle = {default=1};
	__property Color = {default=-16777200};
	__property Constraints;
	__property Ctl3D;
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property LookAndFeel;
	__property MarginColor = {default=-16777208};
	__property Margins;
	__property MaxZoomFactor = {default=500};
	__property MeasurementUnits = {default=0};
	__property MinFooterSize = {default=127};
	__property MinHeaderSize = {default=127};
	__property MinZoomFactor = {default=10};
	__property OptionsBehavior = {default=53};
	__property OptionsHint = {default=7};
	__property OptionsStore = {default=1};
	__property OptionsView = {default=15};
	__property OptionsZoom = {default=1};
	__property Orientation = {default=0};
	__property OriginalPageSize;
	__property PageBackground;
	__property PageXCount = {default=1};
	__property PageYCount = {default=1};
	__property ParentBackground = {default=1};
	__property ParentColor = {default=0};
	__property ParentCtl3D = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ScrollBars = {default=3};
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Transparent;
	__property Visible = {default=1};
	__property ZoomFactor = {default=100};
	__property ZoomMode = {default=0};
	__property ZoomStep = {default=10};
	__property OnAfterDragMargin;
	__property OnBeforeDragMargin;
	__property OnCalcPageCount;
	__property OnCanResize;
	__property OnConstrainedResize;
	__property OnContextPopup;
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragMargin;
	__property OnDragOver;
	__property OnDrawPageBackground;
	__property OnDrawPageContent;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnGetPageNumberHint;
	__property OnCanShowMarginHint;
	__property OnMarginChanged;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnSelectedPageChanged;
	__property OnSelectedPageChanging;
	__property OnSelectingPage;
	__property OnStartDrag;
	__property OnZoomFactorChanged;
	__property OnZoomModeChanged;
public:
	/* TCustomdxPreview.Create */ inline __fastcall virtual TdxPreview(System::Classes::TComponent* AOwner) : TCustomdxPreview(AOwner) { }
	/* TCustomdxPreview.Destroy */ inline __fastcall virtual ~TdxPreview(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxPreview(HWND ParentWindow) : TCustomdxPreview(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int dxPreviewCachedPagesCount;
static const System::Int8 dxPreviewDragHintOffset = System::Int8(0x5);
static const System::Int8 dxPreviewMarginSelectDelta = System::Int8(0x3);
static const System::Int8 dxPreviewMinHeaderFooterSize = System::Int8(0x7f);
extern PACKAGE System::Types::TPoint dxPreviewMinUsefulSize;
static const System::Int8 dxPreviewMinZoomFactor = System::Int8(0x5);
static const System::Int8 dxPreviewScrollStep = System::Int8(0x1e);
#define dxPSPreviewDefaultBehaviorOptions (System::Set<TdxPreviewOptionBehavior, TdxPreviewOptionBehavior::pobAllowDragMargins, TdxPreviewOptionBehavior::pobNonCenterizePages> () << TdxPreviewOptionBehavior::pobAllowDragMargins << TdxPreviewOptionBehavior::pobKeyNavigation << TdxPreviewOptionBehavior::pobThumbTracking << TdxPreviewOptionBehavior::pobAutoSwapMargins )
#define dxPSPreviewDefaultOptionsView (System::Set<TdxPreviewOptionView, TdxPreviewOptionView::povAutoHideScrollBars, TdxPreviewOptionView::povPageSelection> () << TdxPreviewOptionView::povAutoHideScrollBars << TdxPreviewOptionView::povDefaultDrawPageBackground << TdxPreviewOptionView::povMargins << TdxPreviewOptionView::povPageSelection )
#define dxPSPreviewDefaultOptionsHint (System::Set<TdxPreviewOptionHint, TdxPreviewOptionHint::pohShowForMargins, TdxPreviewOptionHint::pohShowOnScroll> () << TdxPreviewOptionHint::pohShowForMargins << TdxPreviewOptionHint::pohShowOnDrag << TdxPreviewOptionHint::pohShowOnScroll )
extern PACKAGE TdxPreviewHitTests phtMargins;
extern PACKAGE TdxPreviewHitTests phtMarginsHorz;
extern PACKAGE TdxPreviewHitTests phtMarginsVert;
}	/* namespace Dxprevw */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPREVW)
using namespace Dxprevw;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxprevwHPP
