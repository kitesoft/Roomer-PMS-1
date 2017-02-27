// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerCustomResourceView.pas' rev: 24.00 (Win64)

#ifndef CxschedulercustomresourceviewHPP
#define CxschedulercustomresourceviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxEditUtils.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulercustomresourceview
{
//-- type declarations -------------------------------------------------------
enum TcxSchedulerContentNavigationButtonKind : unsigned char { nbkPrevious, nbkNext };

enum TcxSchedulerColumnPositionInResource : unsigned char { cprIndefinite, cprFirst, cprLast, cprSingle };

class DELPHICLASS TcxSchedulerBackgroundCellViewInfo;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawBackgroundEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerBackgroundCellViewInfo* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerMoreEventsButtonViewInfo;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawButtonEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerMoreEventsButtonViewInfo* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerDayHeaderCellViewInfo;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawDayHeaderEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDayHeaderCellViewInfo* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerContentNavigationButtonViewInfo;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawNavigationButtonEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerContentNavigationButtonViewInfo* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerHeaderCellViewInfo;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawResourceHeaderEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerHeaderCellViewInfo* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerContentCellViewInfo;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawContentEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerContentCellViewInfo* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerEventCellViewInfo;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawEventEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerEventCellViewInfo* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerGroupSeparatorCellViewInfo;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawGroupSeparatorEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerGroupSeparatorCellViewInfo* AViewInfo, bool &ADone);

__interface IcxSchedulerCommonViewItemsPainter;
typedef System::DelphiInterface<IcxSchedulerCommonViewItemsPainter> _di_IcxSchedulerCommonViewItemsPainter;
__interface  INTERFACE_UUID("{0702AB17-C2F1-479D-B809-C3B972F8A334}") IcxSchedulerCommonViewItemsPainter  : public System::IInterface 
{
	
public:
	virtual void __fastcall DoCustomDrawBackground(TcxSchedulerBackgroundCellViewInfo* AViewInfo, bool &ADone) = 0 ;
	virtual void __fastcall DoCustomDrawButton(TcxSchedulerMoreEventsButtonViewInfo* AViewInfo, bool &ADone) = 0 ;
	virtual void __fastcall DoCustomDrawContent(TcxSchedulerContentCellViewInfo* AViewInfo, bool &ADone) = 0 ;
	virtual void __fastcall DoCustomDrawDayHeader(TcxSchedulerDayHeaderCellViewInfo* AViewInfo, bool &ADone) = 0 ;
	virtual void __fastcall DoCustomDrawEvent(TcxSchedulerEventCellViewInfo* AViewInfo, bool &ADone) = 0 ;
	virtual void __fastcall DoCustomDrawGroupSeparator(TcxSchedulerGroupSeparatorCellViewInfo* AViewInfo, bool &ADone) = 0 ;
	virtual void __fastcall DoCustomDrawNavigationButton(TcxSchedulerContentNavigationButtonViewInfo* AViewInfo, bool &ADone) = 0 ;
	virtual void __fastcall DoCustomDrawResourceHeader(TcxSchedulerHeaderCellViewInfo* AViewInfo, bool &ADone) = 0 ;
	virtual bool __fastcall HasCustomDrawGroupSeparator(void) = 0 ;
	virtual bool __fastcall HasCustomDrawResourceHeader(void) = 0 ;
};

__interface IcxSchedulerEventImages;
typedef System::DelphiInterface<IcxSchedulerEventImages> _di_IcxSchedulerEventImages;
class DELPHICLASS TcxSchedulerEventImages;
__interface  INTERFACE_UUID("{4C5A8F8B-5356-4D2B-9972-507A7D60954A}") IcxSchedulerEventImages  : public System::IInterface 
{
	
public:
	virtual void __fastcall DoInitEventImages(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, TcxSchedulerEventImages* AImages) = 0 ;
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void) = 0 ;
	virtual bool __fastcall SupportEventImages(void) = 0 ;
};

class DELPHICLASS TcxSchedulerCustomViewInfoItem;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawItemProc)(TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerViewInfoCellList;
class DELPHICLASS TcxSchedulerCustomResourceViewHitTest;
class PASCALIMPLEMENTATION TcxSchedulerViewInfoCellList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TcxSchedulerCustomViewInfoItem* operator[](int Index) { return Items[Index]; }
	
private:
	TcxSchedulerCustomViewInfoItem* __fastcall GetItem(int AIndex);
	
public:
	bool __fastcall CalculateHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	virtual void __fastcall Clear(void);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerCustomDrawItemProc ADrawItemProc);
	__property TcxSchedulerCustomViewInfoItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxSchedulerViewInfoCellList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerViewInfoCellList(void) : System::Classes::TList() { }
	
};


class DELPHICLASS TcxSchedulerCachedImage;
class DELPHICLASS TcxSchedulerExternalPainter;
class PASCALIMPLEMENTATION TcxSchedulerCustomViewInfoItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerCachedImage* FCache;
	Vcl::Graphics::TBitmap* __fastcall GetBitmap(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	Cxschedulerutils::TcxSchedulerDateTimeHelperClass __fastcall GetDateTimeHelper(void);
	int __fastcall GetHeight(void);
	Cxschedulerutils::TcxSchedulerPainterHelperClass __fastcall GetPainterHelper(void);
	System::Uitypes::TColor __fastcall GetTextColor(void);
	int __fastcall GetWidth(void);
	void __fastcall SetBitmap(Vcl::Graphics::TBitmap* AValue);
	void __fastcall SetColor(System::Uitypes::TColor AValue);
	void __fastcall SetTextColor(System::Uitypes::TColor AValue);
	
protected:
	bool FBackgroundDrawing;
	Cxgraphics::TcxBorders FBorders;
	System::Types::TRect FBounds;
	Cxgraphics::TcxCanvas* FCanvas;
	System::Types::TRect FClipRect;
	Cxgraphics::TcxRegion* FClipRgn;
	int FClipRef;
	System::TDateTime FDateTime;
	System::Uitypes::TColor FDayBorderColor;
	System::UnicodeString FDisplayText;
	TcxSchedulerExternalPainter* FExternalPainter;
	bool FHasClipping;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	Cxgraphics::TcxRegion* FSavedClipRgn;
	bool FTransparent;
	Cxgraphics::TcxViewParams FViewParams;
	bool FVisible;
	void __fastcall CalculateCellBounds(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect);
	virtual System::Types::TRect __fastcall CalculateClipRect(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect);
	virtual void __fastcall ClippingCreate(bool AHasClipping);
	void __fastcall ClippingRestore(void);
	virtual void __fastcall DoDraw(void) = 0 ;
	virtual bool __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	void __fastcall DrawFrame(const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ALineWidth = 0x1);
	void __fastcall DrawRect(const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ALineWidth = 0x1);
	void __fastcall DrawText(const System::Types::TRect &ARect, const System::UnicodeString AText, int AFlags, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	virtual System::Types::TRect __fastcall GetBoundsForHitTest(void);
	virtual Vcl::Graphics::TFont* __fastcall GetFont(void);
	virtual bool __fastcall GetHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest, bool &ABreak);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall BeforeCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall UpdateCachedImage(const Cxgraphics::TcxViewParams &AViewParams);
	__property TcxSchedulerCachedImage* Cache = {read=FCache, write=FCache};
	__property Cxschedulerutils::TcxSchedulerDateTimeHelperClass DateTimeHelper = {read=GetDateTimeHelper};
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=FDisplayText};
	__property Cxschedulerutils::TcxSchedulerPainterHelperClass PainterHelper = {read=GetPainterHelper};
	__property TcxSchedulerExternalPainter* ExternalPainter = {read=FExternalPainter};
	
public:
	__fastcall virtual TcxSchedulerCustomViewInfoItem(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams);
	__fastcall virtual ~TcxSchedulerCustomViewInfoItem(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property Cxgraphics::TcxBorders Borders = {read=FBorders, write=FBorders, nodefault};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property Vcl::Graphics::TBitmap* Bitmap = {read=GetBitmap, write=SetBitmap};
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property System::Types::TRect ClipRect = {read=FClipRect};
	__property System::Uitypes::TColor Color = {read=GetColor, write=SetColor, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont};
	__property int Height = {read=GetHeight, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=FPainter};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, write=SetTextColor, nodefault};
	__property bool Transparent = {read=FTransparent, write=FTransparent, nodefault};
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams};
	__property bool Visible = {read=FVisible, nodefault};
	__property int Width = {read=GetWidth, nodefault};
};


class PASCALIMPLEMENTATION TcxSchedulerBackgroundCellViewInfo : public TcxSchedulerCustomViewInfoItem
{
	typedef TcxSchedulerCustomViewInfoItem inherited;
	
protected:
	virtual void __fastcall DoDraw(void);
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerBackgroundCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerCustomViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerBackgroundCellViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerCustomViewInfoItemClass;

class DELPHICLASS TcxSchedulerCustomResourceViewInfoItem;
class DELPHICLASS TcxSchedulerResourceViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerCustomResourceViewInfoItem : public TcxSchedulerCustomViewInfoItem
{
	typedef TcxSchedulerCustomViewInfoItem inherited;
	
private:
	bool FIsResourceAssigned;
	System::TDateTime FTimeFinish;
	TcxSchedulerResourceViewInfo* FResource;
	
protected:
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	__property System::TDateTime DateTime = {read=FDateTime, write=FDateTime};
	__property bool IsResourceAssigned = {read=FIsResourceAssigned, nodefault};
	__property TcxSchedulerResourceViewInfo* Resource = {read=FResource, write=FResource};
	__property System::TDateTime TimeFinish = {read=FTimeFinish};
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerCustomResourceViewInfoItem(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerCustomViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomResourceViewInfoItem(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerHeaderCellViewInfo : public TcxSchedulerCustomResourceViewInfoItem
{
	typedef TcxSchedulerCustomResourceViewInfoItem inherited;
	
protected:
	System::Types::TRect DisplayBounds;
	System::Classes::TAlignment FAlignHorz;
	Cxclasses::TcxAlignmentVert FAlignVert;
	bool FAutoHeight;
	Cxlookandfeelpainters::TcxButtonState FButtonState;
	bool FDrawRotatedBackground;
	int FImageIndex;
	Cxschedulercustomcontrols::TcxSchedulerHeaderImagePosition FImagePosition;
	Vcl::Imglist::TCustomImageList* FImages;
	bool FImageRectAssigned;
	System::Types::TRect FImageRect;
	bool FIsResourceHeader;
	bool FMultiLine;
	Cxlookandfeelpainters::TcxNeighbors FNeighbors;
	Cxgraphics::TcxBitmap* FRotateBitmap;
	bool FRotateHeader;
	bool FRotateText;
	bool FSelected;
	Cxgraphics::TcxBitmap* FSelectionBitmap;
	System::Uitypes::TColor FSelectionColor;
	System::Types::TRect FSelectionRect;
	System::Uitypes::TColor FSelectionTextColor;
	bool FShowEndEllipsis;
	System::Types::TRect FTextRect;
	void __fastcall CheckNeighbor(TcxSchedulerHeaderCellViewInfo* APrevCell);
	virtual bool __fastcall CheckSelection(void);
	virtual void __fastcall DoDraw(void);
	void __fastcall DrawCaption(Cxgraphics::TcxCanvas* ACanvas = (Cxgraphics::TcxCanvas*)(0x0));
	virtual void __fastcall DrawHorizontalHeader(void);
	virtual bool __fastcall DrawRotateBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawSelection(void);
	virtual void __fastcall DrawVerticalHeader(void);
	int __fastcall GetTextOutcxFlags(void);
	int __fastcall GetTextOutFlags(void);
	bool __fastcall HasImage(void);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	void __fastcall TextOut(Cxgraphics::TcxCanvas* ACanvas, const System::UnicodeString AText, System::Types::TRect &R);
	void __fastcall ValidateSelection(void);
	
public:
	__fastcall virtual TcxSchedulerHeaderCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams);
	__fastcall virtual ~TcxSchedulerHeaderCellViewInfo(void);
	virtual void __fastcall Calculate(const System::UnicodeString AText);
	void __fastcall CalculateImageLayout(void);
	__property System::Classes::TAlignment AlignHorz = {read=FAlignHorz, write=FAlignHorz, nodefault};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=FAlignVert, write=FAlignVert, nodefault};
	__property bool AutoHeight = {read=FAutoHeight, nodefault};
	__property System::TDateTime DateTime = {read=FDateTime, write=FDateTime};
	__property int ImageIndex = {read=FImageIndex, nodefault};
	__property Cxschedulercustomcontrols::TcxSchedulerHeaderImagePosition ImagePosition = {read=FImagePosition, nodefault};
	__property System::Types::TRect ImageRect = {read=FImageRect};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages};
	__property bool IsResourceHeader = {read=FIsResourceHeader, nodefault};
	__property bool MultiLine = {read=FMultiLine, write=FMultiLine, nodefault};
	__property Cxlookandfeelpainters::TcxNeighbors Neighbors = {read=FNeighbors, write=FNeighbors, nodefault};
	__property bool RotateHeader = {read=FRotateHeader, write=FRotateHeader, nodefault};
	__property bool RotateText = {read=FRotateText, write=FRotateText, nodefault};
	__property bool Selected = {read=FSelected, write=FSelected, nodefault};
	__property System::Uitypes::TColor SelectionColor = {read=FSelectionColor, write=FSelectionColor, nodefault};
	__property System::Uitypes::TColor SelectionTextColor = {read=FSelectionTextColor, write=FSelectionTextColor, nodefault};
	__property bool ShowEndEllipsis = {read=FShowEndEllipsis, write=FShowEndEllipsis, nodefault};
	__property System::Types::TRect TextRect = {read=FTextRect};
	__property Bounds;
	__property DisplayText = {default=0};
	__property Painter;
	__property Resource;
};


class PASCALIMPLEMENTATION TcxSchedulerDayHeaderCellViewInfo : public TcxSchedulerHeaderCellViewInfo
{
	typedef TcxSchedulerHeaderCellViewInfo inherited;
	
private:
	bool FCompressed;
	
protected:
	virtual bool __fastcall CheckSelection(void);
	virtual bool __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawHorizontalHeader(void);
	
public:
	virtual int __fastcall ConvertDateToDisplayText(int AType = 0x0);
	__property bool Compressed = {read=FCompressed, write=FCompressed, nodefault};
public:
	/* TcxSchedulerHeaderCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerDayHeaderCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerHeaderCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerHeaderCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerDayHeaderCellViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerWeekDayHeaderCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerWeekDayHeaderCellViewInfo : public TcxSchedulerDayHeaderCellViewInfo
{
	typedef TcxSchedulerDayHeaderCellViewInfo inherited;
	
protected:
	System::UnicodeString __fastcall GetDayText(int AType);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	virtual int __fastcall ConvertDateToDisplayText(int AType = 0x0);
public:
	/* TcxSchedulerHeaderCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerWeekDayHeaderCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerDayHeaderCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerHeaderCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerWeekDayHeaderCellViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerContainerCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerContainerCellViewInfo : public TcxSchedulerCustomResourceViewInfoItem
{
	typedef TcxSchedulerCustomResourceViewInfoItem inherited;
	
protected:
	int FLineCount;
	bool FSelected;
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	__property int LineCount = {read=FLineCount, write=FLineCount, nodefault};
	__property DateTime = {default=0};
	__property Resource;
	__property bool Selected = {read=FSelected, write=FSelected, nodefault};
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerContainerCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerCustomResourceViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerContainerCellViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerTimeRulerCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerTimeRulerCellViewInfo : public TcxSchedulerCustomViewInfoItem
{
	typedef TcxSchedulerCustomViewInfoItem inherited;
	
private:
	typedef System::StaticArray<System::UnicodeString, 2> _TcxSchedulerTimeRulerCellViewInfo__1;
	
	
private:
	bool FLastVisibleHour;
	System::Types::TRect __fastcall GetBoundsRect(bool AType);
	System::UnicodeString __fastcall GetDisplayText(bool AType);
	bool __fastcall GetHasAdditionalTimeZone(void);
	
protected:
	int FAdditionalTimeZone;
	int FAdditionalTimeZoneBiasDelta;
	System::StaticArray<System::Types::TRect, 2> FBounds;
	_TcxSchedulerTimeRulerCellViewInfo__1 FDisplayTexts;
	int FHour;
	Vcl::Graphics::TFont* FLargeFont;
	int FLineCount;
	bool FShowMinutes;
	int FTimeZone;
	void __fastcall CalculateDisplayInfo(void);
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall DrawTimeZone(const System::Types::TRect &ABounds, const System::UnicodeString AText, bool AIsCurrent);
	virtual void __fastcall DrawTimeZoneLabel(const System::Types::TRect &ABounds, const System::UnicodeString AText, Cxgraphics::TcxBorders ABorders);
	void __fastcall DrawCurrentTime(const System::TDateTime AStart, System::Types::TRect &ABounds);
	System::TDateTime __fastcall GetAdditionalTime(void);
	System::UnicodeString __fastcall GetTimeDisplayText(const System::TDateTime ATime);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	__classmethod int __fastcall CalculateWidth(int ATimeZoneCount, int ALineCount, Vcl::Graphics::TFont* AFont1, Vcl::Graphics::TFont* AFont2);
	virtual void __fastcall Calculate(const System::UnicodeString ALabel1, const System::UnicodeString ALabel2, int ATimeZone, int AAdditionalTimeZone, int AAdditionalTimeZoneBiasDelta)/* overload */;
	virtual void __fastcall Calculate(int AHour, int ALineCount, int ATimeZone, int AAdditionalTimeZone, Vcl::Graphics::TFont* ALargeFont, int AAdditionalTimeZoneBiasDelta)/* overload */;
	void __fastcall SetBottom(int AValue);
	__property int AdditionalTimeZone = {read=FAdditionalTimeZone, nodefault};
	__property System::Types::TRect Bounds[bool ACurrentTimeZone] = {read=GetBoundsRect};
	__property System::UnicodeString DisplayTexts[bool ACurrentTimeZone] = {read=GetDisplayText};
	__property bool HasAdditionalTimeZone = {read=GetHasAdditionalTimeZone, nodefault};
	__property int Hour = {read=FHour, nodefault};
	__property Vcl::Graphics::TFont* LargeFont = {read=FLargeFont};
	__property bool LastVisibleHour = {read=FLastVisibleHour, write=FLastVisibleHour, nodefault};
	__property int LineCount = {read=FLineCount, nodefault};
	__property bool ShowMinutes = {read=FShowMinutes, write=FShowMinutes, nodefault};
	__property int TimeZone = {read=FTimeZone, nodefault};
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerTimeRulerCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerCustomViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeRulerCellViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerContentCellViewInfo : public TcxSchedulerCustomResourceViewInfoItem
{
	typedef TcxSchedulerCustomResourceViewInfoItem inherited;
	
protected:
	System::Uitypes::TColor FBorderColor;
	bool FDontPrint;
	int FLineCount;
	bool FShowTimeLine;
	TcxSchedulerEventCellViewInfo* FTimeEvent;
	Cxgraphics::TcxBorders FTimeLineBorders;
	Cxgraphics::TcxViewParams FTimeLineParams;
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	__fastcall virtual TcxSchedulerContentCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams);
	void __fastcall SetTime(const System::TDateTime ATimeStart, const System::TDateTime ATimeFinish);
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property bool DontPrint = {read=FDontPrint, write=FDontPrint, nodefault};
	__property int LineCount = {read=FLineCount, write=FLineCount, nodefault};
	__property bool ShowTimeLine = {read=FShowTimeLine, write=FShowTimeLine, nodefault};
	__property TcxSchedulerEventCellViewInfo* TimeEvent = {read=FTimeEvent, write=FTimeEvent};
	__property Cxgraphics::TcxBorders TimeLineBorders = {read=FTimeLineBorders, write=FTimeLineBorders, nodefault};
	__property Cxgraphics::TcxViewParams TimeLineParams = {read=FTimeLineParams, write=FTimeLineParams};
	__property System::TDateTime TimeStart = {read=FDateTime};
	__property TimeFinish = {default=0};
	__property Resource;
public:
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerContentCellViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerContentCellViewInfoClass;

class DELPHICLASS TcxSchedulerBackgroundSlotCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerBackgroundSlotCellViewInfo : public TcxSchedulerContentCellViewInfo
{
	typedef TcxSchedulerContentCellViewInfo inherited;
	
protected:
	virtual void __fastcall DoDraw(void);
	
public:
	__property DisplayText = {default=0};
public:
	/* TcxSchedulerContentCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerBackgroundSlotCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerContentCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	
public:
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerBackgroundSlotCellViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerMonthDayContentCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerMonthDayContentCellViewInfo : public TcxSchedulerContentCellViewInfo
{
	typedef TcxSchedulerContentCellViewInfo inherited;
	
private:
	bool FSelected;
	System::Uitypes::TColor FSelectionColor;
	System::Uitypes::TColor FSelectionTextColor;
	bool __fastcall GetIsToday(void);
	void __fastcall SetSmallTextFont(Vcl::Graphics::TFont* AFont);
	
protected:
	System::Types::TRect FTextRect;
	bool FSmallFont;
	bool FSmallFontCreated;
	Vcl::Graphics::TFont* FSmallTextFont;
	virtual void __fastcall DoDraw(void);
	virtual System::UnicodeString __fastcall GetLongDisplayText(void);
	__property bool IsToday = {read=GetIsToday, nodefault};
	
public:
	__fastcall virtual ~TcxSchedulerMonthDayContentCellViewInfo(void);
	void __fastcall SetContentState(bool AsDayOfMonth, bool ASelected, int ATextHeight, const Cxgraphics::TcxViewParams &ASelectionParams);
	bool __fastcall UpdateSelection(bool ASelected);
	__property DisplayText = {default=0};
	__property bool SmallFont = {read=FSmallFont, nodefault};
	__property Vcl::Graphics::TFont* SmallTextFont = {read=FSmallTextFont, write=SetSmallTextFont};
	__property bool Selected = {read=FSelected, nodefault};
	__property System::Uitypes::TColor SelectionColor = {read=FSelectionColor, write=FSelectionColor, nodefault};
	__property System::Uitypes::TColor SelectionTextColor = {read=FSelectionTextColor, write=FSelectionTextColor, nodefault};
public:
	/* TcxSchedulerContentCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerMonthDayContentCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerContentCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	
};


enum TcxSchedulerEventImagesLayout : unsigned char { eilAuto, eilHorizontal, eilVertical };

class DELPHICLASS TcxSchedulerEventViewData;
class PASCALIMPLEMENTATION TcxSchedulerEventViewData : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	bool AlwaysShowTime;
	bool AutoHeight;
	System::Uitypes::TColor BorderColor;
	System::Types::TRect Bounds;
	Cxgraphics::TcxCanvas* Canvas;
	System::UnicodeString Caption;
	System::TDateTime ContentFinish;
	System::TDateTime ContentStart;
	bool DrawAsProgress;
	bool DrawShadows;
	Cxedit::TcxCustomEditProperties* EditProperties;
	Cxedit::TcxCustomEditStyle* EditStyle;
	Cxschedulerstorage::TcxSchedulerControlEvent* Event;
	TcxSchedulerExternalPainter* ExternalPainter;
	System::UnicodeString __fastcall (__closure *GetEventHint)(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	TcxSchedulerEventImagesLayout ImagesLayout;
	bool IsGroup;
	bool IsMilestone;
	int LineHeight;
	int MaxHeight;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter;
	TcxSchedulerResourceViewInfo* Resource;
	bool ShowAllDayEventsInContentArea;
	bool ShowFinishTime;
	bool ShowStartTime;
	bool ShowTimeAsClock;
	bool ShowTimeLine;
	int StartLine;
	int TaskComplete;
	Cxschedulerstorage::TcxSchedulerEventTaskStatus TaskStatus;
	Cxgraphics::TcxViewParams TimeLineParams;
	Cxgraphics::TcxViewParams ViewParams;
	System::Types::TRect VisibleRect;
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerEventViewData(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerEventViewData(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerEventCellViewInfo : public TcxSchedulerCustomViewInfoItem
{
	typedef TcxSchedulerCustomViewInfoItem inherited;
	
private:
	System::TDateTime FEventFinish;
	System::TDateTime FEventStart;
	bool FIsHeaderEvent;
	int __fastcall CalculateMessageHeight(const System::Types::TRect &R);
	System::Uitypes::TColor __fastcall GetBorderColor(void);
	System::UnicodeString __fastcall GetCaption(void);
	System::Types::TRect __fastcall GetCaptionBounds(const System::Types::TRect &R);
	System::TDateTime __fastcall GetContentFinish(void);
	System::TDateTime __fastcall GetContentStart(void);
	Cxschedulerstorage::TcxSchedulerControlEvent* __fastcall GetEvent(void);
	System::UnicodeString __fastcall GetHint(void);
	bool __fastcall GetIsHeaderEvent(void);
	System::UnicodeString __fastcall GetMessage(void);
	TcxSchedulerResourceViewInfo* __fastcall GetResourceInfo(void);
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetResourceItem(void);
	bool __fastcall GetSelected(void);
	bool __fastcall GetShowingState(int AIndex);
	void __fastcall SetBorderColor(System::Uitypes::TColor AValue);
	
protected:
	System::Types::TRect FCaptionRect;
	Cxedit::TcxCustomEditViewInfo* FEditViewInfo;
	System::Types::TRect FFinishRect;
	System::UnicodeString FFinishText;
	bool FHidden;
	TcxSchedulerEventImages* FImages;
	System::Types::TRect FMessageRect;
	System::UnicodeString FHint;
	bool FHintAssigned;
	bool FHintNeeded;
	bool FHintNeededCalculated;
	System::Uitypes::TColor FSeparatorColor;
	bool FShowMessage;
	System::Types::TRect FStartRect;
	System::UnicodeString FStartText;
	System::Types::TRect FEventTimeRect;
	System::Types::TRect FTimeLineRect;
	bool FIsDetailCaption;
	bool FIsDetailInfo;
	TcxSchedulerEventViewData* ViewData;
	virtual void __fastcall AfterDraw(void);
	void __fastcall AssignEditStyle(Cxedit::TcxCustomEditStyle* AEditStyle);
	virtual void __fastcall BeforeDraw(void);
	virtual void __fastcall BeforeCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall Calculate(void);
	virtual void __fastcall CalculateBorders(void);
	virtual void __fastcall CalculateCaptions(void);
	virtual void __fastcall CalculateDetailInfo(void);
	void __fastcall CalculateNeedHint(void);
	void __fastcall CalculateEditViewInfo(void);
	virtual void __fastcall CalculateShowTimeAsClock(void);
	int __fastcall CalculateAutoLayoutImagesAutoHeight(System::Classes::TList* AVisibleImages);
	int __fastcall CalculateHorizontalImagesAutoHeight(void);
	void __fastcall CalculateMessageAutoLayout(int &AHeight);
	int __fastcall CalculateVerticalImagesAutoHeight(void);
	virtual System::Types::TRect __fastcall CalculateClipRect(const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect);
	virtual void __fastcall CalculateItemsLayout(void);
	void __fastcall CalculateDetailViewEventLayout(void);
	void __fastcall CalculateHeaderEventLayout(void);
	void __fastcall CalculateNonDetailEventLayout(void);
	virtual void __fastcall CalculateEventTimeAsClockLayout(const System::Types::TRect &ABounds, const int ACaptionWidth, const int AImagesWidth, int &ALeft);
	virtual void __fastcall CalculateEventTimeAsTextLayout(const System::Types::TRect &ABounds, const int ACaptionWidth, const int AImagesWidth, int &ALeft);
	virtual System::Types::TRect __fastcall CalculateNonDetailEventImages(const int ACaptionWidth, /* out */ int &AImagesWidth);
	int __fastcall CalculateSingleLineImages(const System::Types::TRect &ABounds, int ARightLimit = 0x0);
	System::Types::TRect __fastcall SetItemRect(bool AShowItem, const System::Types::TRect &ABounds, int AVertOffset, int &APos);
	virtual void __fastcall CalculateEventTimeVisibility(void);
	virtual void __fastcall CalculateDetailEventTimeVisibility(void);
	virtual void __fastcall CalculateNonDetailEventTimeVisibility(void);
	virtual void __fastcall CalculateVisibility(void);
	virtual bool __fastcall CanAutoHideStandardImages(void);
	virtual bool __fastcall CanShowHint(void);
	virtual void __fastcall DoDraw(void);
	void __fastcall DrawCaption(void);
	virtual void __fastcall DrawContent(void);
	void __fastcall DrawImages(void);
	void __fastcall DrawMessageSeparator(void);
	void __fastcall DrawTime(void);
	int __fastcall GetCaptionAutoHeight(const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall GetEditingRect(void);
	virtual bool __fastcall GetForceShowClockInHeaderEvent(void);
	virtual bool __fastcall GetHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest, bool &ABreak);
	System::Types::TRect __fastcall GetImagesBounds(void);
	int __fastcall GetImagesVerticalOffset(int AImageHeight, bool AIsAbsolute);
	System::Types::TRect __fastcall GetMessageRect(const System::Types::TRect &ACaptionRect, bool AHasImages);
	virtual bool __fastcall HasReminder(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	void __fastcall InitHitTestForHorzEvent(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	void __fastcall InitStandardEventImages(void);
	virtual bool __fastcall IsHorzSizing(void);
	virtual bool __fastcall IsNeedDrawTime(void);
	virtual bool __fastcall IsTimeLineVisible(void);
	System::TDateTime __fastcall TruncTime(const System::TDateTime ATime);
	__property System::TDateTime EventFinish = {read=FEventFinish};
	__property System::TDateTime EventStart = {read=FEventStart};
	__property bool IsHeaderEvent = {read=FIsHeaderEvent, nodefault};
	__property bool IsDetailCaption = {read=FIsDetailCaption, nodefault};
	
public:
	__fastcall virtual TcxSchedulerEventCellViewInfo(TcxSchedulerEventViewData* AViewData);
	__fastcall virtual ~TcxSchedulerEventCellViewInfo(void);
	void __fastcall DrawState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, System::Uitypes::TColor ABorderColor)/* overload */;
	virtual int __fastcall MeasureHeight(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall MoveTo(int X, int Y);
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, write=SetBorderColor, nodefault};
	__property System::UnicodeString Caption = {read=GetCaption};
	__property System::Types::TRect CaptionRect = {read=FCaptionRect};
	__property System::Types::TRect ClipRect = {read=FClipRect};
	__property Cxgraphics::TcxRegion* ClipRgn = {read=FClipRgn, write=FClipRgn};
	__property System::TDateTime ContentFinish = {read=GetContentFinish};
	__property System::TDateTime ContentStart = {read=GetContentStart};
	__property System::Types::TRect EditingRect = {read=GetEditingRect};
	__property Cxedit::TcxCustomEditViewInfo* EditViewInfo = {read=FEditViewInfo};
	__property Cxschedulerstorage::TcxSchedulerControlEvent* Event = {read=GetEvent};
	__property System::Types::TRect EventTimeRect = {read=FEventTimeRect};
	__property TcxSchedulerEventViewData* EventViewData = {read=ViewData};
	__property System::Types::TRect FinishRect = {read=FFinishRect};
	__property System::UnicodeString FinishText = {read=FFinishText};
	__property bool Hidden = {read=FHidden, write=FHidden, nodefault};
	__property System::UnicodeString Hint = {read=GetHint};
	__property TcxSchedulerEventImages* Images = {read=FImages};
	__property bool IsDetailInfo = {read=FIsDetailInfo, nodefault};
	__property System::UnicodeString Message = {read=GetMessage};
	__property System::Types::TRect MessageRect = {read=FMessageRect};
	__property TcxSchedulerResourceViewInfo* ResourceInfo = {read=GetResourceInfo};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItem* ResourceItem = {read=GetResourceItem};
	__property bool Selected = {read=GetSelected, nodefault};
	__property System::Uitypes::TColor SeparatorColor = {read=FSeparatorColor, write=FSeparatorColor, nodefault};
	__property bool ShowFinishTime = {read=GetShowingState, index=0, nodefault};
	__property bool ShowMessage = {read=FShowMessage, nodefault};
	__property bool ShowStartTime = {read=GetShowingState, index=1, nodefault};
	__property bool ShowTimeAsClock = {read=GetShowingState, index=2, nodefault};
	__property bool ShowTimeLine = {read=GetShowingState, index=3, nodefault};
	__property System::Types::TRect StartRect = {read=FStartRect};
	__property System::UnicodeString StartText = {read=FStartText};
	__property System::Types::TRect TimeLineRect = {read=FTimeLineRect, write=FTimeLineRect};
	__property bool Visible = {read=FVisible, nodefault};
};


typedef void __fastcall (__closure *TcxSchedulerMoreEventsButtonClick)(TcxSchedulerMoreEventsButtonViewInfo* Sender);

typedef System::TMetaClass* TcxSchedulerMoreEventsButtonViewInfoClass;

class PASCALIMPLEMENTATION TcxSchedulerMoreEventsButtonViewInfo : public TcxSchedulerCustomResourceViewInfoItem
{
	typedef TcxSchedulerCustomResourceViewInfoItem inherited;
	
protected:
	Cxschedulerstorage::TcxSchedulerEvent* FEvent;
	bool FIsDown;
	TcxSchedulerMoreEventsButtonClick FOnClick;
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	__property TcxSchedulerMoreEventsButtonClick OnClick = {read=FOnClick, write=FOnClick};
	
public:
	virtual void __fastcall Click(void);
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=FEvent, write=FEvent};
	__property bool IsDown = {read=FIsDown, nodefault};
	__property DateTime = {default=0};
	__property Resource;
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerMoreEventsButtonViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerCustomResourceViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerMoreEventsButtonViewInfo(void) { }
	
};


typedef void __fastcall (__closure *TcxSchedulerContentNavigationButtonClick)(TcxSchedulerContentNavigationButtonViewInfo* Sender);

class PASCALIMPLEMENTATION TcxSchedulerContentNavigationButtonViewInfo : public TcxSchedulerCustomResourceViewInfoItem
{
	typedef TcxSchedulerCustomResourceViewInfoItem inherited;
	
private:
	System::Types::TRect FArrowRect;
	System::UnicodeString FCaption;
	TcxSchedulerCustomResourceViewHitTest* FHitTest;
	System::TDateTime FInterval;
	TcxSchedulerContentNavigationButtonKind FKind;
	TcxSchedulerContentNavigationButtonClick FOnClick;
	System::Types::TRect FTextRect;
	bool __fastcall GetEnabled(void);
	
protected:
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property TcxSchedulerContentNavigationButtonClick OnClick = {read=FOnClick, write=FOnClick};
	
public:
	virtual void __fastcall Click(void);
	__property System::Types::TRect ArrowRect = {read=FArrowRect};
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property System::TDateTime Interval = {read=FInterval, write=FInterval};
	__property TcxSchedulerContentNavigationButtonKind Kind = {read=FKind, write=FKind, nodefault};
	__property System::Types::TRect TextRect = {read=FTextRect};
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerContentNavigationButtonViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerCustomResourceViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerContentNavigationButtonViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerGroupSeparatorCellViewInfo : public TcxSchedulerCustomViewInfoItem
{
	typedef TcxSchedulerCustomViewInfoItem inherited;
	
private:
	bool FDrawRotatedBackground;
	bool FRotated;
	bool __fastcall DrawRotateBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	
protected:
	Cxgraphics::TcxBitmap* FRotateBitmap;
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall InitHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	__fastcall virtual ~TcxSchedulerGroupSeparatorCellViewInfo(void);
	__property bool Rotated = {read=FRotated, write=FRotated, nodefault};
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerGroupSeparatorCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerCustomViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerResourceViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::UnicodeString FCaption;
	System::Uitypes::TColor FColor;
	int FImageIndex;
	Cxschedulercustomcontrols::TcxSchedulerHeaderImagePosition FImagePosition;
	Vcl::Imglist::TCustomImageList* FImages;
	System::Variant FResourceID;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FResourceItem;
	System::Types::TRect FTextRect;
	int FVisibleEventCount;
	
public:
	__fastcall virtual TcxSchedulerResourceViewInfo(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	__property System::UnicodeString Caption = {read=FCaption};
	__property System::Uitypes::TColor Color = {read=FColor, nodefault};
	__property int ImageIndex = {read=FImageIndex, nodefault};
	__property Cxschedulercustomcontrols::TcxSchedulerHeaderImagePosition ImagePosition = {read=FImagePosition, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages};
	__property System::Variant ResourceID = {read=FResourceID};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItem* ResourceItem = {read=FResourceItem};
	__property System::Types::TRect TextRect = {read=FTextRect, write=FTextRect};
	__property int VisibleEventCount = {read=FVisibleEventCount, write=FVisibleEventCount, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerResourceViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerExternalPainter : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	_di_IcxSchedulerCommonViewItemsPainter FCommonPainter;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	Cxschedulerutils::TcxSchedulerPainterHelperClass __fastcall GetPainterHelper(void);
	
protected:
	__property Cxschedulerutils::TcxSchedulerPainterHelperClass PainterHelper = {read=GetPainterHelper};
	
public:
	virtual void __fastcall DoCustomDrawBackground(TcxSchedulerBackgroundCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawButton(TcxSchedulerMoreEventsButtonViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawContent(TcxSchedulerContentCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawDayHeader(TcxSchedulerDayHeaderCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawEvent(TcxSchedulerEventCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawGroupSeparator(TcxSchedulerGroupSeparatorCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawNavigationButton(TcxSchedulerContentNavigationButtonViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawResourceHeader(TcxSchedulerHeaderCellViewInfo* AViewInfo, bool &ADone);
	bool __fastcall HasCustomDrawGroupSeparator(void);
	bool __fastcall HasCustomDrawResourceHeader(void);
	virtual void __fastcall DrawAllDayArea(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ABorderColor, Cxgraphics::TcxBorders ABorders, Cxgraphics::TcxViewParams &AViewParams, bool ASelected, bool ATransparent);
	virtual void __fastcall DrawCurrentTime(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor AColor, System::TDateTime AStart, System::Types::TRect &ABounds);
	virtual bool __fastcall DrawCurrentTimeFirst(void);
	virtual void __fastcall DrawEvent(TcxSchedulerEventCellViewInfo* AViewInfo);
	virtual void __fastcall DrawEventAsGroup(TcxSchedulerEventCellViewInfo* AViewInfo);
	virtual void __fastcall DrawEventAsMilestone(TcxSchedulerEventCellViewInfo* AViewInfo);
	virtual void __fastcall DrawEventAsProgress(TcxSchedulerEventCellViewInfo* AViewInfo);
	virtual void __fastcall DrawEventAsProgressText(TcxSchedulerEventCellViewInfo* AViewInfo, System::Types::TRect &AContent, System::Types::TRect &AProgressRect, const System::UnicodeString AText);
	virtual void __fastcall DrawTimeGridCurrentTime(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor AColor, const System::Types::TRect &ATimeLineRect);
	virtual void __fastcall DrawTimeGridHeader(Cxgraphics::TcxCanvas* ACanvas, System::Uitypes::TColor ABorderColor, TcxSchedulerCustomViewInfoItem* AViewInfo, Cxgraphics::TcxBorders ABorders, bool ASelected);
	virtual void __fastcall DrawTimeLine(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxViewParams &AViewParams, Cxgraphics::TcxBorders ABorders, System::Uitypes::TColor ABorderColor);
	virtual void __fastcall DrawTimeRulerBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, Cxgraphics::TcxViewParams &AViewParams, bool ATransparent);
	virtual void __fastcall DrawShadow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds);
	virtual bool __fastcall DrawShadowFirst(void);
	virtual System::Types::TRect __fastcall GetEventSelectionExtends(void);
	virtual System::Types::TSize __fastcall MoreButtonSize(System::Types::TSize ASize);
	virtual bool __fastcall NeedDrawSelection(void);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=FPainter, write=FPainter};
	__property _di_IcxSchedulerCommonViewItemsPainter CommonPainter = {read=FCommonPainter, write=FCommonPainter};
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerExternalPainter(void) : System::TInterfacedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerExternalPainter(void) { }
	
private:
	void *__IcxSchedulerCommonViewItemsPainter;	/* IcxSchedulerCommonViewItemsPainter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0702AB17-C2F1-479D-B809-C3B972F8A334}
	operator _di_IcxSchedulerCommonViewItemsPainter()
	{
		_di_IcxSchedulerCommonViewItemsPainter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxSchedulerCommonViewItemsPainter*(void) { return (IcxSchedulerCommonViewItemsPainter*)&__IcxSchedulerCommonViewItemsPainter; }
	#endif
	
};


typedef System::TMetaClass* TcxSchedulerExternalPainterClass;

class DELPHICLASS TcxSchedulerCustomResourceView;
class DELPHICLASS TcxCustomResourceViewAdapter;
class DELPHICLASS TcxSchedulerCustomResourceViewViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerCustomResourceView : public Cxschedulercustomcontrols::TcxSchedulerCustomView
{
	typedef Cxschedulercustomcontrols::TcxSchedulerCustomView inherited;
	
private:
	TcxCustomResourceViewAdapter* FAdapter;
	TcxSchedulerExternalPainter* FExternalPainter;
	Cxschedulercustomcontrols::TcxSchedulerGroupingKind FGroupingKind;
	TcxSchedulerEventImagesLayout FEventImagesLayout;
	bool FShowEndTime;
	bool FShowTimeAsClock;
	TcxSchedulerCustomDrawBackgroundEvent FOnCustomDrawBackground;
	TcxSchedulerCustomDrawButtonEvent FOnCustomDrawButton;
	TcxSchedulerCustomDrawContentEvent FOnCustomDrawContent;
	TcxSchedulerCustomDrawDayHeaderEvent FOnCustomDrawDayHeader;
	TcxSchedulerCustomDrawEventEvent FOnCustomDrawEvent;
	TcxSchedulerCustomDrawGroupSeparatorEvent FOnCustomDrawGroupSeparator;
	TcxSchedulerCustomDrawNavigationButtonEvent FOnCustomDrawNavigationButton;
	TcxSchedulerCustomDrawResourceHeaderEvent FOnCustomDrawResourceHeader;
	void __fastcall CheckSelectOnRightClick(void);
	TcxSchedulerCustomResourceViewViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall IsRelevantSelection(/* out */ System::TDateTime &ATime, /* out */ Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	void __fastcall SetEventImagesLayout(const TcxSchedulerEventImagesLayout AValue);
	void __fastcall SetShowEndTime(const bool AValue);
	void __fastcall SetShowTimeAsClock(const bool AValue);
	
protected:
	virtual void __fastcall CalculateViewInfo(void);
	virtual void __fastcall CheckGroupingKind(Cxschedulercustomcontrols::TcxSchedulerGroupingKind AStyle, Cxschedulercustomcontrols::TcxSchedulerGroupingKind &ActuallyStyle);
	virtual void __fastcall ClearCachedData(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual TcxCustomResourceViewAdapter* __fastcall CreateViewAdapter(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DoCustomDrawBackground(TcxSchedulerBackgroundCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawButton(TcxSchedulerMoreEventsButtonViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawContent(TcxSchedulerContentCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawDayHeader(TcxSchedulerDayHeaderCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawEvent(TcxSchedulerEventCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawGroupSeparator(TcxSchedulerGroupSeparatorCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawNavigationButton(TcxSchedulerContentNavigationButtonViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawResourceHeader(TcxSchedulerHeaderCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoLayoutChanged(void);
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	virtual bool __fastcall DoShowPopupMenu(int X, int Y);
	bool __fastcall FindEventViewInfo(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, TcxSchedulerEventCellViewInfo* &AViewInfo);
	virtual _di_IcxSchedulerCommonViewItemsPainter __fastcall GetCommonViewItemsPainter(void);
	virtual bool __fastcall GetCompressWeekEnd(void);
	virtual System::Types::TRect __fastcall GetEditRectForEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual System::UnicodeString __fastcall GetEventHintText(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall GetEventVisibility(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual Cxschedulercustomcontrols::TcxSchedulerGroupingKind __fastcall GetGroupingKind(void);
	bool __fastcall HasCustomDrawGroupSeparator(void);
	bool __fastcall HasCustomDrawResourceHeader(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall IsShowResources(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SetGroupingKind(Cxschedulercustomcontrols::TcxSchedulerGroupingKind AValue);
	__property TcxCustomResourceViewAdapter* Adapter = {read=FAdapter, write=FAdapter};
	__property TcxSchedulerEventImagesLayout EventImagesLayout = {read=FEventImagesLayout, write=SetEventImagesLayout, nodefault};
	__property TcxSchedulerExternalPainter* ExternalPainter = {read=FExternalPainter};
	__property bool ShowEndTime = {read=FShowEndTime, write=SetShowEndTime, default=1};
	__property bool ShowTimeAsClock = {read=FShowTimeAsClock, write=SetShowTimeAsClock, default=0};
	__property TcxSchedulerCustomResourceViewViewInfo* ViewInfo = {read=GetViewInfo};
	__property TcxSchedulerCustomDrawBackgroundEvent OnCustomDrawBackground = {read=FOnCustomDrawBackground, write=FOnCustomDrawBackground};
	__property TcxSchedulerCustomDrawButtonEvent OnCustomDrawButton = {read=FOnCustomDrawButton, write=FOnCustomDrawButton};
	__property TcxSchedulerCustomDrawContentEvent OnCustomDrawContent = {read=FOnCustomDrawContent, write=FOnCustomDrawContent};
	__property TcxSchedulerCustomDrawDayHeaderEvent OnCustomDrawDayHeader = {read=FOnCustomDrawDayHeader, write=FOnCustomDrawDayHeader};
	__property TcxSchedulerCustomDrawEventEvent OnCustomDrawEvent = {read=FOnCustomDrawEvent, write=FOnCustomDrawEvent};
	__property TcxSchedulerCustomDrawGroupSeparatorEvent OnCustomDrawGroupSeparator = {read=FOnCustomDrawGroupSeparator, write=FOnCustomDrawGroupSeparator};
	__property TcxSchedulerCustomDrawNavigationButtonEvent OnCustomDrawNavigationButton = {read=FOnCustomDrawNavigationButton, write=FOnCustomDrawNavigationButton};
	__property TcxSchedulerCustomDrawResourceHeaderEvent OnCustomDrawResourceHeader = {read=FOnCustomDrawResourceHeader, write=FOnCustomDrawResourceHeader};
	
public:
	__fastcall virtual TcxSchedulerCustomResourceView(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerCustomResourceView(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall InitializePainter(void);
	virtual void __fastcall FinilizePainter(void);
	__property Cxschedulercustomcontrols::TcxSchedulerGroupingKind GroupingKind = {read=FGroupingKind, write=SetGroupingKind, default=0};
};


class PASCALIMPLEMENTATION TcxCustomResourceViewAdapter : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxSchedulerCustomResourceView* FView;
	Cxclasses::TcxObjectList* __fastcall GetCells(void);
	int __fastcall GetContentLineHeight(void);
	Cxschedulerutils::TcxSchedulerPainterHelperClass __fastcall GetPainterHelper(void);
	Cxschedulercustomcontrols::TcxSchedulerResourceNavigator* __fastcall GetResourceNavigator(void);
	Cxschedulerstorage::TcxSchedulerStorageResourceItems* __fastcall GetResources(void);
	Cxschedulercustomcontrols::TcxCustomScheduler* __fastcall GetScheduler(void);
	TcxSchedulerCustomResourceViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall CanCalculate(void);
	virtual System::TDateTime __fastcall GetActualStart(void);
	virtual System::TDateTime __fastcall GetActualFinish(void);
	virtual bool __fastcall GetCompressWeekends(void);
	virtual bool __fastcall GetDontPrintFreeTime(void);
	virtual bool __fastcall GetDontPrintWeekEnds(void);
	virtual bool __fastcall GetHideSelection(void);
	virtual bool __fastcall GetIsPrinting(void);
	virtual System::Types::TRect __fastcall GetPageBounds(void);
	virtual System::Byte __fastcall GetPagesPerWeek(void);
	virtual bool __fastcall GetPrimaryPage(void);
	virtual bool __fastcall GetPrintExactlyOneMonth(void);
	virtual System::TDateTime __fastcall GetPrintRange(int Index);
	virtual Cxschedulercustomcontrols::_di_IcxSchedulerStylesAdapter __fastcall GetStylesAdapter(void);
	virtual TcxSchedulerCustomResourceView* __fastcall GetView(void);
	virtual void __fastcall AfterCalculatePage(void);
	virtual void __fastcall BeforeCalculatePage(void);
	virtual void __fastcall DoInitialize(Cxschedulerutils::TcxSchedulerDateList* &ASelectedDays, Cxschedulerstorage::TcxSchedulerCachedEventList* &AEvents);
	virtual System::UnicodeString __fastcall GetPageHeaderText(void);
	virtual void __fastcall Store(void);
	virtual void __fastcall Restore(void);
	__property Cxschedulercustomcontrols::TcxCustomScheduler* Scheduler = {read=GetScheduler};
	__property Cxschedulerutils::TcxSchedulerPainterHelperClass PainterHelper = {read=GetPainterHelper};
	__property Cxschedulercustomcontrols::TcxSchedulerResourceNavigator* ResourceNavigator = {read=GetResourceNavigator};
	__property TcxSchedulerCustomResourceViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomResourceViewAdapter(TcxSchedulerCustomResourceView* AView);
	void __fastcall Calculate(void)/* overload */;
	virtual void __fastcall GetPageResources(Cxclasses::TcxObjectList* AResources);
	void __fastcall GetPageDays(int APageIndex, Cxschedulerutils::TcxSchedulerDateList* ADays);
	virtual void __fastcall Invalidate(void);
	__property System::TDateTime ActualStart = {read=GetActualStart};
	__property System::TDateTime ActualFinish = {read=GetActualFinish};
	__property Cxclasses::TcxObjectList* Cells = {read=GetCells};
	__property int ContentLineHeight = {read=GetContentLineHeight, nodefault};
	__property bool DontPrintFreeTime = {read=GetDontPrintFreeTime, nodefault};
	__property bool DontPrintWeekEnd = {read=GetDontPrintWeekEnds, nodefault};
	__property bool IsPrinting = {read=GetIsPrinting, nodefault};
	__property System::Byte PagesPerWeek = {read=GetPagesPerWeek, nodefault};
	__property bool PrintExactlyOneMonth = {read=GetPrintExactlyOneMonth, nodefault};
	__property System::TDateTime PrintFrom = {read=GetPrintRange, index=0};
	__property System::TDateTime PrintTo = {read=GetPrintRange, index=1};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItems* Resources = {read=GetResources};
	__property Cxschedulercustomcontrols::_di_IcxSchedulerStylesAdapter StylesAdapter = {read=GetStylesAdapter};
	__property TcxSchedulerCustomResourceView* View = {read=GetView, write=FView};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomResourceViewAdapter(void) { }
	
};


typedef System::TMetaClass* TcxCustomResourceViewAdapterClass;

enum TcxSchedulerEventImageType : unsigned char { eitReminder, eitRecurrence, eitCustomOccurrence, eitCustom };

class DELPHICLASS TcxSchedulerEventImageItem;
class PASCALIMPLEMENTATION TcxSchedulerEventImageItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	bool FAutoHide;
	TcxSchedulerEventImageType FImageType;
	int FImageIndex;
	Vcl::Imglist::TCustomImageList* FImages;
	bool FVisible;
	int __fastcall GetHeight(void);
	int __fastcall GetWidth(void);
	
protected:
	System::Types::TRect FBounds;
	bool FHidden;
	
public:
	__fastcall virtual TcxSchedulerEventImageItem(System::Classes::TCollection* Collection);
	__property bool AutoHide = {read=FAutoHide, write=FAutoHide, nodefault};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property int Height = {read=GetHeight, nodefault};
	__property int ImageIndex = {read=FImageIndex, nodefault};
	__property TcxSchedulerEventImageType ImageType = {read=FImageType, nodefault};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages};
	__property bool Visible = {read=FVisible, write=FVisible, nodefault};
	__property int Width = {read=GetWidth, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxSchedulerEventImageItem(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerEventImages : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxSchedulerEventImageItem* operator[](int Index) { return Items[Index]; }
	
private:
	int FForceVisibleHeight;
	int FForceVisibleWidth;
	Vcl::Imglist::TCustomImageList* FImages;
	TcxSchedulerEventImagesLayout FLayout;
	int FItemHeight;
	int FItemWidth;
	int FTotalVisibleHeight;
	int FTotalVisibleWidth;
	int FTotalVisibleImageCount;
	int FVisibleImageCount;
	TcxSchedulerEventImageItem* __fastcall GetImageItem(int AIndex);
	
protected:
	int __fastcall Calculate(const System::Types::TRect &R);
	void __fastcall CalculateForCols(System::Classes::TList* AVisibleImages, const System::Types::TPoint ATopLeft, int AColCount);
	int __fastcall CalculateImages(const System::Types::TRect &R);
	int __fastcall CalculateSingleColumnImages(const System::Types::TRect &R);
	int __fastcall CalculateSingleLineImages(const System::Types::TRect &R, int ARightLimit = 0x0);
	int __fastcall Offset(int ADeltaX, int ADeltaY);
	System::Classes::TList* __fastcall CreateVisibleList(void);
	void __fastcall Init(Vcl::Imglist::TCustomImageList* AImages);
	void __fastcall SetItemBounds(TcxSchedulerEventImageItem* AItem, int ALeft, int ATop);
	__property int ItemHeight = {read=FItemHeight, nodefault};
	__property int ItemWidth = {read=FItemWidth, nodefault};
	__property int ForceVisibleHeight = {read=FForceVisibleHeight, nodefault};
	__property int ForceVisibleWidth = {read=FForceVisibleWidth, nodefault};
	__property int TotalVisibleHeight = {read=FTotalVisibleHeight, nodefault};
	__property int TotalVisibleWidth = {read=FTotalVisibleWidth, nodefault};
	__property int TotalVisibleImageCount = {read=FTotalVisibleImageCount, nodefault};
	__property int VisibleImageCount = {read=FVisibleImageCount, nodefault};
	
public:
	__fastcall TcxSchedulerEventImages(TcxSchedulerEventImagesLayout ALayout);
	HIDESBASE TcxSchedulerEventImageItem* __fastcall Add(int AImageIndex, bool AutoHide = true);
	TcxSchedulerEventImageItem* __fastcall AddStandardImage(TcxSchedulerEventImageType AImageType, bool AutoHide = true);
	__property TcxSchedulerEventImageItem* Items[int Index] = {read=GetImageItem/*, default*/};
	__property TcxSchedulerEventImagesLayout Layout = {read=FLayout, write=FLayout, nodefault};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxSchedulerEventImages(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerCachedImage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxBitmap* FImage;
	
public:
	__fastcall TcxSchedulerCachedImage(void);
	__fastcall virtual ~TcxSchedulerCachedImage(void);
	void __fastcall Invalidate(void);
	virtual bool __fastcall IsValid(TcxSchedulerCustomViewInfoItem* AItem);
	virtual void __fastcall Update(TcxSchedulerCustomViewInfoItem* AItem);
	__property Cxgraphics::TcxBitmap* Image = {read=FImage};
};


class DELPHICLASS TcxSchedulerResourceHeaderCachedImage;
class PASCALIMPLEMENTATION TcxSchedulerResourceHeaderCachedImage : public TcxSchedulerCachedImage
{
	typedef TcxSchedulerCachedImage inherited;
	
private:
	System::UnicodeString FDisplayText;
	System::TDateTime FDateTime;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FResourceItem;
	
public:
	virtual bool __fastcall IsValid(TcxSchedulerCustomViewInfoItem* AItem);
	virtual void __fastcall Update(TcxSchedulerCustomViewInfoItem* AItem);
public:
	/* TcxSchedulerCachedImage.Create */ inline __fastcall TcxSchedulerResourceHeaderCachedImage(void) : TcxSchedulerCachedImage() { }
	/* TcxSchedulerCachedImage.Destroy */ inline __fastcall virtual ~TcxSchedulerResourceHeaderCachedImage(void) { }
	
};


class DELPHICLASS TcxSchedulerResourceHeaderCachedImageList;
class PASCALIMPLEMENTATION TcxSchedulerResourceHeaderCachedImageList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	HIDESBASE TcxSchedulerResourceHeaderCachedImage* __fastcall Add(TcxSchedulerHeaderCellViewInfo* AItem);
	TcxSchedulerResourceHeaderCachedImage* __fastcall GetCacheForItem(TcxSchedulerHeaderCellViewInfo* AItem);
public:
	/* TcxObjectList.Create */ inline __fastcall TcxSchedulerResourceHeaderCachedImageList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxSchedulerResourceHeaderCachedImageList(void) { }
	
};


class DELPHICLASS TcxSchedulerImageCacheManager;
class PASCALIMPLEMENTATION TcxSchedulerImageCacheManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerResourceHeaderCachedImageList* FResourceHeaders;
	TcxSchedulerCachedImage* FSeparator;
	
public:
	__fastcall virtual TcxSchedulerImageCacheManager(void);
	__fastcall virtual ~TcxSchedulerImageCacheManager(void);
	virtual void __fastcall Invalidate(void);
	__property TcxSchedulerResourceHeaderCachedImageList* ResourceHeaders = {read=FResourceHeaders};
	__property TcxSchedulerCachedImage* Separator = {read=FSeparator};
};


class PASCALIMPLEMENTATION TcxSchedulerCustomResourceViewViewInfo : public Cxschedulercustomcontrols::TcxSchedulerCustomViewViewInfo
{
	typedef Cxschedulercustomcontrols::TcxSchedulerCustomViewViewInfo inherited;
	
private:
	typedef System::DynamicArray<System::Types::TRect> _TcxSchedulerCustomResourceViewViewInfo__1;
	
	
private:
	System::Types::TRect FButtonBounds;
	System::Types::TRect FButtonTextRect;
	System::Types::TRect FButtonArrowRect;
	System::Contnrs::TObjectList* FContentNavigationIntervals;
	bool FContentNavigationWithoutResources;
	int FEventWithoutResourceCount;
	TcxSchedulerImageCacheManager* FImageCacheManager;
	TcxSchedulerContentNavigationButtonViewInfo* FHotContentNavigationButton;
	void __fastcall AddContentNavigationIntervalItem(System::Variant &AResourceIndex);
	void __fastcall ClearContentNavigationIntervals(void);
	Cxschedulerstorage::TcxSchedulerEventList* __fastcall GetClones(void);
	int __fastcall GetCorrectColumnHeight(System::Types::TRect &AColumnRect);
	System::TDateTime __fastcall GetDay(int AIndex);
	int __fastcall GetDayCount(void);
	bool __fastcall GetGroupByDate(void);
	bool __fastcall GetGroupByResource(void);
	bool __fastcall GetHasSeparator(void);
	bool __fastcall GetHasVisibleBounds(void);
	bool __fastcall GetHiddenSelection(void);
	int __fastcall GetMinResourceHeight(void);
	int __fastcall GetMoreEventsButtonCount(int AResourceIndex);
	TcxSchedulerResourceViewInfo* __fastcall GetResource(int AIndex);
	System::UnicodeString __fastcall GetResourceCaption(int AIndex);
	int __fastcall GetResourceCount(void);
	Cxschedulercustomcontrols::TcxSchedulerResourceHeaders* __fastcall GetResourceHeaders(void);
	System::TDateTime __fastcall GetPrintRange(int Index);
	int __fastcall GetSeparatorWidth(void);
	TcxSchedulerCustomResourceView* __fastcall GetView(void);
	bool __fastcall IsDrawContentNavigationButtons(void);
	void __fastcall SetContentNavigationButtonsIntervals(void);
	void __fastcall SetHitContentNavigationButton(TcxSchedulerContentNavigationButtonViewInfo* AButton, TcxSchedulerCustomResourceViewHitTest* AHitTest);
	void __fastcall SetHotContentNavigationButton(TcxSchedulerContentNavigationButtonViewInfo* AButton);
	
protected:
	TcxCustomResourceViewAdapter* FAdapter;
	TcxSchedulerViewInfoCellList* FButtons;
	bool FCanSelected;
	Cxclasses::TcxObjectList* FCells;
	TcxSchedulerViewInfoCellList* FContentCells;
	int FContentFontHeight;
	int FContentLineHeight;
	System::Uitypes::TColor FDayBorderColor;
	TcxSchedulerViewInfoCellList* FDayHeaderCells;
	int FDayHeaderHeight;
	TcxSchedulerViewInfoCellList* FEventCells;
	_di_IcxSchedulerEventImages FEventImages;
	TcxSchedulerViewInfoCellList* FGroupSeparatorCells;
	Cxgraphics::TcxViewParams FGroupSeparatorParams;
	Cxschedulercustomcontrols::TcxSchedulerGroupingKind FGroupingKind;
	bool FHasVisibleBounds;
	TcxSchedulerViewInfoCellList* FHeaderContainerCells;
	bool FHideClones;
	bool FHideSelection;
	bool FHideSource;
	TcxSchedulerViewInfoCellList* FNavigationButtons;
	Cxclasses::TcxObjectList* FResources;
	_TcxSchedulerCustomResourceViewViewInfo__1 FResourceBounds;
	TcxSchedulerViewInfoCellList* FResourceHeaderCells;
	int FResourceHeaderHeight;
	Vcl::Imglist::TCustomImageList* FResourceImages;
	Cxgraphics::TcxViewParams FSelectionParams;
	System::TDateTime FSelStart;
	System::TDateTime FSelFinish;
	TcxSchedulerResourceViewInfo* FSelResource;
	Cxschedulercustomcontrols::_di_IcxSchedulerStylesAdapter FStylesAdapter;
	Cxgraphics::TcxViewParams FTimeLineParams;
	System::Types::TRect FPageBounds;
	System::Byte FPagesPerWeek;
	bool FPrimaryPage;
	bool FPrintWeekEnds;
	bool FUseResourceImages;
	Cxgraphics::TcxCanvas* ScreenCanvas;
	virtual void __fastcall MouseLeave(void);
	virtual TcxSchedulerBackgroundSlotCellViewInfo* __fastcall AddBackgroundSlot(const System::Types::TRect &ABounds, Cxgraphics::TcxBorders ABorders, const System::UnicodeString AText = System::UnicodeString());
	virtual TcxSchedulerMoreEventsButtonViewInfo* __fastcall AddButton(System::Types::TRect &ABounds, const System::TDateTime ADateTime, bool AIsDown, Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual TcxSchedulerContentCellViewInfo* __fastcall AddContentCell(const System::Types::TRect &ARect, const System::TDateTime AStart, const System::TDateTime AFinish, int AResourceIndex);
	void __fastcall AddContentNavigationButton(const System::Types::TRect &AColumnRect, int AResourceIndex, TcxSchedulerColumnPositionInResource AColumnPositionInResource);
	virtual TcxSchedulerDayHeaderCellViewInfo* __fastcall AddDayHeader(const System::TDateTime ADate, const System::Types::TRect &ABounds, int AResourceIndex)/* overload */;
	TcxSchedulerDayHeaderCellViewInfo* __fastcall AddDayHeader(const System::TDateTime ADate, int ATop, int ALeft, int ARight, int AResourceIndex)/* overload */;
	virtual TcxSchedulerEventCellViewInfo* __fastcall AddEventCell(TcxSchedulerEventViewData* AViewData, bool AImmediateCalculate = true);
	virtual TcxSchedulerGroupSeparatorCellViewInfo* __fastcall AddGroupHorzSeparator(int APos);
	virtual TcxSchedulerGroupSeparatorCellViewInfo* __fastcall AddGroupSeparator(const System::Types::TRect &ABounds);
	virtual TcxSchedulerGroupSeparatorCellViewInfo* __fastcall AddGroupVertSeparator(int APos);
	void __fastcall AddResourceBounds(int AResourceIndex, const System::Types::TRect &ABounds);
	virtual TcxSchedulerHeaderCellViewInfo* __fastcall AddResourceHeader(const int AIndex, const System::Types::TRect &ABounds);
	virtual void __fastcall AfterCalculate(void);
	bool __fastcall AreThereEventsInVisibleInterval(int AResourceIndex);
	void __fastcall AssignResourceID(TcxSchedulerCustomResourceViewInfoItem* ACell, int AIndex);
	virtual void __fastcall CalculateContentNavigationButtons(void);
	virtual void __fastcall CalculateMetrics(void);
	void __fastcall CalculateNavigationButtonParams(System::Types::TRect &AColumnRect, TcxSchedulerContentNavigationButtonKind AKind, /* out */ int &AButtonWidth);
	virtual void __fastcall CalculateResourceHeadersAutoHeight(int AWidth);
	virtual int __fastcall CalculateResourceHeaderWidth(void);
	virtual bool __fastcall CanCalculateNavigationButtons(void);
	virtual bool __fastcall CanCacheGroupSeparator(TcxSchedulerGroupSeparatorCellViewInfo* AItem);
	virtual bool __fastcall CanCacheResourceHeader(TcxSchedulerHeaderCellViewInfo* AItem);
	virtual void __fastcall Clear(void);
	void __fastcall ClearResourceBounds(void);
	virtual TcxSchedulerContentCellViewInfoClass __fastcall ContentCellClass(void);
	void __fastcall CreateCellInstance(TcxSchedulerCustomViewInfoItemClass AClass, const System::Types::TRect &ABounds, const Cxgraphics::TcxViewParams &AViewParams, void *Instance)/* overload */;
	void __fastcall CreateCellInstance(TcxSchedulerCustomViewInfoItemClass AClass, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleBounds, const Cxgraphics::TcxViewParams &AViewParams, void *Instance)/* overload */;
	virtual TcxSchedulerEventViewData* __fastcall CreateEventViewData(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::Types::TRect &ABounds, const System::TDateTime AStart, const System::TDateTime AFinish, TcxSchedulerResourceViewInfo* AResource);
	virtual TcxSchedulerEventCellViewInfo* __fastcall CreateEventCellViewInfo(TcxSchedulerEventViewData* AViewData);
	virtual TcxSchedulerImageCacheManager* __fastcall CreateImageCacheManager(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoContentNavigationButtonClick(TcxSchedulerContentNavigationButtonViewInfo* Sender);
	virtual void __fastcall DoMoreEventsButtonClick(TcxSchedulerMoreEventsButtonViewInfo* Sender);
	virtual void __fastcall ExtractResources(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	System::TDateTime __fastcall GetContentNavigationInterval(TcxSchedulerContentNavigationButtonViewInfo* AContentNavigationButton);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ATime, TcxSchedulerResourceViewInfo* AResource);
	virtual int __fastcall GetDayHeaderHeight(void);
	virtual int __fastcall GetEventForResourceCount(int AResourceIndex, /* out */ System::Variant &AResourceID);
	virtual int __fastcall GetEventWithoutResourceCount(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerGroupingKind __fastcall GetGroupingKind(void);
	virtual TcxSchedulerMoreEventsButtonViewInfoClass __fastcall GetMoreEventButtonClass(void);
	int __fastcall GetResourceHeaderWidth(void);
	virtual System::Types::TSize __fastcall GetResourceImagesSize(void);
	virtual int __fastcall GetResourcesContentWidth(void);
	virtual System::TDateTime __fastcall GetScaleUnit(void);
	Cxgraphics::TcxViewParams __fastcall GetSelectionParams(const Cxgraphics::TcxViewParams &AParams);
	virtual int __fastcall GetSeparatorCount(void);
	virtual bool __fastcall GetShowEventsWithoutResource(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetTimeLineParams(void);
	int __fastcall GetFontHeight(Cxstyles::TcxStyle* AStyle)/* overload */;
	int __fastcall GetFontHeight(const Cxgraphics::TcxViewParams &AParams)/* overload */;
	virtual System::UnicodeString __fastcall GetPageHeaderText(void);
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetResourceItemByIndex(int AIndex);
	TcxSchedulerResourceViewInfo* __fastcall GetResourceViewInfoByItem(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AItem, int &ResourceViewInfoIndex);
	virtual System::TDateTime __fastcall GetStartDate(int Index);
	bool __fastcall HasStorage(void);
	virtual bool __fastcall HasVisibleEvents(void);
	void __fastcall HideCloneEventsOnDragDrop(void);
	void __fastcall HideSourceEventsOnDragDrop(void);
	void __fastcall HotTrackNavigationButtons(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	virtual bool __fastcall IsTimeSelected(System::TDateTime ATime, System::TObject* AResource);
	bool __fastcall IsValidNavigationButtonsPlace(const System::Types::TRect &AResourceRect);
	virtual void __fastcall MakeTimeVisible(const System::TDateTime ATime);
	virtual int __fastcall NavigationButtonOffset(TcxSchedulerContentNavigationButtonKind AKind, int AResourceIndex);
	void __fastcall OnContentNavigationButtonClick(TcxSchedulerContentNavigationButtonViewInfo* Sender);
	void __fastcall OnMoreEventsButtonClick(TcxSchedulerMoreEventsButtonViewInfo* Sender);
	virtual void __fastcall ProcessDateToDisplayText(bool ArrangeByType = false);
	void __fastcall ProcessCheckBorders(TcxSchedulerViewInfoCellList* AList, bool AHasCommonArea, Cxlookandfeelpainters::TcxNeighbors ANeighbors = Cxlookandfeelpainters::TcxNeighbors() , Cxgraphics::TcxBorders AExcludeBorders = Cxgraphics::TcxBorders() , Cxgraphics::TcxBorders AAddBorders = Cxgraphics::TcxBorders() );
	virtual void __fastcall ReturnVisibleInterval(System::TDateTime &AStart, System::TDateTime &AEnd);
	TcxCustomResourceViewAdapter* __fastcall SetAdapter(TcxCustomResourceViewAdapter* Adapter);
	void __fastcall SetResourceHasVisibleEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall SetResourceTextRect(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, const System::Types::TRect &ARect);
	__property TcxSchedulerContentNavigationButtonViewInfo* HotContentNavigationButton = {read=FHotContentNavigationButton, write=SetHotContentNavigationButton};
	__property TcxSchedulerImageCacheManager* ImageCacheManager = {read=FImageCacheManager};
	__property System::TDateTime StartDates[int AnIndex] = {read=GetStartDate};
	__property TcxSchedulerCustomResourceView* View = {read=GetView};
	
public:
	__fastcall virtual TcxSchedulerCustomResourceViewViewInfo(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerCustomResourceViewViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateHitTest(TcxSchedulerCustomResourceViewHitTest* AHitTest);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall ScrollHorizontal(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall ScrollVertical(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SetEventsVisibility(bool AShowSources, bool AShowClones, bool AForceRepaint = false);
	__property TcxCustomResourceViewAdapter* Adapter = {read=FAdapter};
	__property TcxSchedulerViewInfoCellList* Buttons = {read=FButtons};
	__property bool CanSelected = {read=FCanSelected, nodefault};
	__property Cxschedulerstorage::TcxSchedulerEventList* Clones = {read=GetClones};
	__property TcxSchedulerViewInfoCellList* ContentCells = {read=FContentCells};
	__property int ContentLineHeight = {read=FContentLineHeight, nodefault};
	__property int DayCount = {read=GetDayCount, nodefault};
	__property TcxSchedulerViewInfoCellList* DayHeaderCells = {read=FDayHeaderCells};
	__property int DayHeaderHeight = {read=GetDayHeaderHeight, nodefault};
	__property System::TDateTime Days[int Index] = {read=GetDay};
	__property TcxSchedulerViewInfoCellList* EventCells = {read=FEventCells};
	__property bool ShowEventsWithoutResource = {read=GetShowEventsWithoutResource, nodefault};
	__property bool GroupByDate = {read=GetGroupByDate, nodefault};
	__property bool GroupByResource = {read=GetGroupByResource, nodefault};
	__property TcxSchedulerViewInfoCellList* GroupSeparatorCells = {read=FGroupSeparatorCells};
	__property Cxgraphics::TcxViewParams GroupSeparatorParams = {read=FGroupSeparatorParams};
	__property Cxschedulercustomcontrols::TcxSchedulerGroupingKind GroupingKind = {read=FGroupingKind, nodefault};
	__property bool HasSeparator = {read=GetHasSeparator, nodefault};
	__property bool HasVisibleBounds = {read=FHasVisibleBounds, nodefault};
	__property TcxSchedulerViewInfoCellList* HeaderContainerCells = {read=FHeaderContainerCells};
	__property bool HideSelection = {read=FHideSelection, nodefault};
	__property TcxSchedulerViewInfoCellList* NavigationButtons = {read=FNavigationButtons};
	__property System::Byte PagesPerWeek = {read=FPagesPerWeek, nodefault};
	__property bool PrimaryPage = {read=FPrimaryPage, nodefault};
	__property System::TDateTime PrintFrom = {read=GetPrintRange, index=0};
	__property System::TDateTime PrintTo = {read=GetPrintRange, index=1};
	__property bool PrintWeekEnds = {read=FPrintWeekEnds, nodefault};
	__property TcxSchedulerResourceViewInfo* Resources[int AIndex] = {read=GetResource};
	__property System::UnicodeString ResourceCaptions[int AIndex] = {read=GetResourceCaption};
	__property int ResourceCount = {read=GetResourceCount, nodefault};
	__property Cxschedulercustomcontrols::TcxSchedulerResourceHeaders* ResourceHeaders = {read=GetResourceHeaders};
	__property TcxSchedulerViewInfoCellList* ResourceHeaderCells = {read=FResourceHeaderCells};
	__property int ResourceHeaderHeight = {read=FResourceHeaderHeight, nodefault};
	__property Vcl::Imglist::TCustomImageList* ResourceImages = {read=FResourceImages};
	__property System::TDateTime SelFinish = {read=FSelFinish};
	__property TcxSchedulerResourceViewInfo* SelResource = {read=FSelResource};
	__property System::TDateTime SelStart = {read=FSelStart};
	__property int SeparatorWidth = {read=GetSeparatorWidth, nodefault};
	__property Cxschedulercustomcontrols::_di_IcxSchedulerStylesAdapter StylesAdapter = {read=FStylesAdapter};
	__property bool HiddenSelection = {read=GetHiddenSelection, nodefault};
	__property bool UseResourceImages = {read=FUseResourceImages, nodefault};
private:
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller; }
	#endif
	
};


class DELPHICLASS TcxSchedulerCustomResourceViewNavigation;
class PASCALIMPLEMENTATION TcxSchedulerCustomResourceViewNavigation : public Cxschedulercustomcontrols::TcxSchedulerViewNavigation
{
	typedef Cxschedulercustomcontrols::TcxSchedulerViewNavigation inherited;
	
private:
	bool __fastcall GetIsFirstResource(void);
	bool __fastcall GetIsLastResource(void);
	Cxschedulercustomcontrols::TcxSchedulerGroupingKind __fastcall GetGroupingKind(void);
	TcxSchedulerResourceViewInfo* __fastcall GetResourceObject(void);
	TcxSchedulerCustomResourceViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetNextResource(bool AGoToForward);
	virtual Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetResourceItem(void);
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetResourceFromViewInfo(TcxSchedulerResourceViewInfo* AInfo);
	System::TDateTime __fastcall RoundTime(const System::TDateTime ADateTime);
	
public:
	virtual void __fastcall ValidateSelection(System::TDateTime &ASelStart, System::TDateTime &ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	__property bool IsFirstResource = {read=GetIsFirstResource, nodefault};
	__property bool IsLastResource = {read=GetIsLastResource, nodefault};
	__property Cxschedulercustomcontrols::TcxSchedulerGroupingKind GroupingKind = {read=GetGroupingKind, nodefault};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItem* ResourceItem = {read=GetResourceItem};
	__property TcxSchedulerResourceViewInfo* ResourceObject = {read=GetResourceObject};
	__property TcxSchedulerCustomResourceViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerViewNavigation.Create */ inline __fastcall TcxSchedulerCustomResourceViewNavigation(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView) : Cxschedulercustomcontrols::TcxSchedulerViewNavigation(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomResourceViewNavigation(void) { }
	
};


class DELPHICLASS TcxSchedulerCustomResourceViewController;
class PASCALIMPLEMENTATION TcxSchedulerCustomResourceViewController : public Cxschedulercustomcontrols::TcxSchedulerViewController
{
	typedef Cxschedulercustomcontrols::TcxSchedulerViewController inherited;
	
private:
	bool FCalculatedHintBounds;
	System::UnicodeString FHintText;
	bool FNavigationButtonClicked;
	Cxschedulercustomcontrols::TcxSchedulerHintController* __fastcall GetHintController(void);
	HIDESBASE TcxSchedulerCustomResourceViewHitTest* __fastcall GetHitTest(void);
	HIDESBASE TcxSchedulerCustomResourceView* __fastcall GetView(void);
	
protected:
	virtual Cxschedulercustomcontrols::TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual System::TDateTime __fastcall GetDayHeaderDate(void);
	void __fastcall InternalHideHint(void);
	void __fastcall InternalShowHint(System::Types::TPoint P, const System::UnicodeString AHintText);
	virtual bool __fastcall NeedShowDayHeaderHint(void);
	virtual bool __fastcall ShowHint(void);
	virtual void __fastcall ShowDayHeaderHint(void);
	__property Cxschedulercustomcontrols::TcxSchedulerHintController* HintController = {read=GetHintController};
	__property TcxSchedulerCustomResourceViewHitTest* HitTest = {read=GetHitTest};
	__property bool NavigationButtonClicked = {read=FNavigationButtonClicked, write=FNavigationButtonClicked, nodefault};
	__property TcxSchedulerCustomResourceView* View = {read=GetView};
public:
	/* TcxSchedulerViewController.Create */ inline __fastcall virtual TcxSchedulerCustomResourceViewController(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomcontrols::TcxSchedulerViewController(AOwner) { }
	/* TcxSchedulerViewController.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomResourceViewController(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerCustomResourceViewHitTest : public Cxschedulercustomcontrols::TcxSchedulerViewHitTest
{
	typedef Cxschedulercustomcontrols::TcxSchedulerViewHitTest inherited;
	
private:
	TcxSchedulerContentCellViewInfo* __fastcall GetContentCell(void);
	TcxSchedulerContentNavigationButtonViewInfo* __fastcall GetHitContentNavigationButton(void);
	TcxSchedulerHeaderCellViewInfo* __fastcall GetHeaderCell(void);
	TcxSchedulerCustomResourceView* __fastcall GetView(void);
	
protected:
	TcxSchedulerMoreEventsButtonViewInfo* FButton;
	TcxSchedulerContentNavigationButtonViewInfo* FContentNavigationButton;
	Cxschedulercustomcontrols::TcxEventDragKind FDragKind;
	TcxSchedulerEventCellViewInfo* FEventCell;
	System::TObject* FHitObject;
	int FTimeZone;
	virtual bool __fastcall CanMoveEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall CanResizeEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall Clear(void);
	virtual void __fastcall DoCalculate(void);
	virtual Cxschedulerstorage::TcxSchedulerControlEvent* __fastcall GetHitEvent(void);
	virtual void __fastcall SetHitTime(int AItemFlag, const System::TDateTime ATime);
	void __fastcall SetResource(TcxSchedulerResourceViewInfo* AResource);
	virtual void __fastcall ValidateDragKind(void);
	__property TcxSchedulerCustomResourceView* View = {read=GetView};
	__property bool HitAtTimeZoneLabel = {read=GetBitState, index=6, nodefault};
	__property TcxSchedulerContentNavigationButtonViewInfo* HitContentNavigationButton = {read=GetHitContentNavigationButton};
	__property int TimeZone = {read=FTimeZone, nodefault};
	
public:
	virtual Cxschedulercustomcontrols::TcxEventDragKind __fastcall GetDragKind(void);
	void __fastcall SetDragKind(Cxschedulercustomcontrols::TcxEventDragKind AValue);
	__property TcxSchedulerMoreEventsButtonViewInfo* Button = {read=FButton};
	__property TcxSchedulerContentCellViewInfo* ContentCell = {read=GetContentCell};
	__property TcxSchedulerContentNavigationButtonViewInfo* ContentNavigationButton = {read=FContentNavigationButton};
	__property TcxSchedulerEventCellViewInfo* EventCell = {read=FEventCell};
	__property TcxSchedulerHeaderCellViewInfo* HeaderCell = {read=GetHeaderCell};
	__property bool HitAtButton = {read=GetBitState, index=3, nodefault};
	__property bool HitAtContent = {read=GetBitState, index=7, nodefault};
	__property bool HitAtContentNavigationButton = {read=GetBitState, index=22, nodefault};
	__property bool HitAtDayHeader = {read=GetBitState, index=8, nodefault};
	__property bool HitAtGroupSeparator = {read=GetBitState, index=9, nodefault};
	__property bool HitAtResourceHeader = {read=GetBitState, index=16, nodefault};
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerCustomResourceViewHitTest(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomcontrols::TcxSchedulerViewHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomResourceViewHitTest(void) { }
	
};


class DELPHICLASS TcxSchedulerCustomViewPainter;
class PASCALIMPLEMENTATION TcxSchedulerCustomViewPainter : public Cxschedulercustomcontrols::TcxSchedulerSubControlPainter
{
	typedef Cxschedulercustomcontrols::TcxSchedulerSubControlPainter inherited;
	
private:
	TcxSchedulerCustomResourceView* __fastcall GetView(void);
	
protected:
	_di_IcxSchedulerCommonViewItemsPainter FPainter;
	virtual void __fastcall DrawBackgroundCell(TcxSchedulerBackgroundCellViewInfo* AItem);
	virtual void __fastcall DrawButtonCell(TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	virtual void __fastcall DrawContentCell(TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	virtual void __fastcall DrawEventCell(TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	virtual void __fastcall DrawGroupSeparatorCell(TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	virtual void __fastcall DrawHeaderCell(TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	virtual void __fastcall DrawResourceHeaderCell(TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	
public:
	__fastcall virtual TcxSchedulerCustomViewPainter(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	virtual void __fastcall InitializePainter(void);
	virtual void __fastcall Paint(void);
	__property _di_IcxSchedulerCommonViewItemsPainter Painter = {read=FPainter};
	__property TcxSchedulerCustomResourceView* View = {read=GetView};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomViewPainter(void) { }
	
};


class DELPHICLASS TcxSchedulerEventPlace;
class PASCALIMPLEMENTATION TcxSchedulerEventPlace : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int ColFinish;
	int ColStart;
	System::TObject* Resource;
	System::TObject* Data;
	Cxschedulerstorage::TcxSchedulerEvent* Event;
	int LineFinish;
	int LineStart;
	void __fastcall AlignPosition(TcxSchedulerEventPlace* APlace);
	bool __fastcall IntersectHorz(TcxSchedulerEventPlace* APlace);
	bool __fastcall IntersectVert(TcxSchedulerEventPlace* APlace);
	void __fastcall LineStartToEvent(void);
	void __fastcall ResetPosition(void);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerEventPlace(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerEventPlace(void) { }
	
};


class DELPHICLASS TcxSchedulerEventLayoutBuilder;
typedef bool __fastcall (__closure *TcxSchedulerEventLayoutBuilderGetEventPlaceProc)(TcxSchedulerEventLayoutBuilder* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, /* out */ int &AStartCol, /* out */ int &AFinishCol, /* out */ int &ALineCount);

class PASCALIMPLEMENTATION TcxSchedulerEventLayoutBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FEventPlaces;
	TcxSchedulerEventPlace* __fastcall GetEventPlace(int AIndex);
	int __fastcall GetEventPlaceCount(void);
	
public:
	__fastcall virtual TcxSchedulerEventLayoutBuilder(void);
	__fastcall virtual ~TcxSchedulerEventLayoutBuilder(void);
	TcxSchedulerEventPlace* __fastcall AddEventPlace(Cxschedulerstorage::TcxSchedulerEvent* AEvent, int AStartCol, int AFinishCol, int ALineCount = 0x1, System::TObject* AResource = (System::TObject*)(0x0));
	void __fastcall Clear(void);
	virtual void __fastcall Calculate(void);
	void __fastcall CalculateEx(Cxschedulerstorage::TcxSchedulerFilteredEventList* AEventsList, TcxSchedulerEventLayoutBuilderGetEventPlaceProc APlaceInfoProc);
	__property int EventPlaceCount = {read=GetEventPlaceCount, nodefault};
	__property TcxSchedulerEventPlace* EventPlaces[int Index] = {read=GetEventPlace};
	__property Cxclasses::TcxObjectList* EventPlacesList = {read=FEventPlaces};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int cxTimeLineWidth;
static const System::Int8 cxEventImagesOffset = System::Int8(0x1);
static const System::Int8 cxEventBorderWidth = System::Int8(0x1);
extern PACKAGE int cxHitDelta;
static const System::Int8 htcButton = System::Int8(0x3);
static const System::Int8 htcContainer = System::Int8(0x4);
static const System::Int8 htcTimeRuler = System::Int8(0x5);
static const System::Int8 htcTimeZoneLabel = System::Int8(0x6);
static const System::Int8 htcContent = System::Int8(0x7);
static const System::Int8 htcDayHeader = System::Int8(0x8);
static const System::Int8 htcGroupSeparator = System::Int8(0x9);
static const System::Int8 htcResourceHeader = System::Int8(0x10);
static const System::Int8 htcNavigationButton = System::Int8(0x16);
extern PACKAGE TcxSchedulerExternalPainterClass ExternalPainterClass;
extern PACKAGE int __fastcall MakeTextOutcxFlags(System::Classes::TAlignment AlignHorz, Cxclasses::TcxAlignmentVert AlignVert, bool AMultiline = false);
}	/* namespace Cxschedulercustomresourceview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERCUSTOMRESOURCEVIEW)
using namespace Cxschedulercustomresourceview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulercustomresourceviewHPP
