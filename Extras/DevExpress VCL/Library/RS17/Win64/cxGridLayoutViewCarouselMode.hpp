// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridLayoutViewCarouselMode.pas' rev: 24.00 (Win64)

#ifndef CxgridlayoutviewcarouselmodeHPP
#define CxgridlayoutviewcarouselmodeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridCustomLayoutView.hpp>	// Pascal unit
#include <cxGridLayoutView.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridlayoutviewcarouselmode
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridLayoutViewCarouselModeRecordPainter;
class DELPHICLASS TcxGridLayoutViewCarouselModeRecordViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewCarouselModeRecordPainter : public Cxgridlayoutview::TcxGridLayoutViewRecordPainter
{
	typedef Cxgridlayoutview::TcxGridLayoutViewRecordPainter inherited;
	
private:
	HIDESBASE TcxGridLayoutViewCarouselModeRecordViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall IsPaintBitmap(void);
	
protected:
	virtual void __fastcall Paint(void);
	virtual bool __fastcall CanDrawBackground(void);
	virtual bool __fastcall CanDrawExpandButton(void);
	__property TcxGridLayoutViewCarouselModeRecordViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridLayoutViewCarouselModeRecordPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridlayoutview::TcxGridLayoutViewRecordPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewCarouselModeRecordPainter(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewCarouselModeRecordsPainter;
class DELPHICLASS TcxGridLayoutViewCarouselModeRecordsViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewCarouselModeRecordsPainter : public Cxgridcustomtableview::TcxCustomGridRecordsPainter
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordsPainter inherited;
	
private:
	TcxGridLayoutViewCarouselModeRecordsViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridLayoutViewCarouselModeRecordsViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridRecordsPainter.Create */ inline __fastcall virtual TcxGridLayoutViewCarouselModeRecordsPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* AViewInfo) : Cxgridcustomtableview::TcxCustomGridRecordsPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewCarouselModeRecordsPainter(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewCarouselModeRecordViewInfoCacheItem;
class PASCALIMPLEMENTATION TcxGridLayoutViewCarouselModeRecordViewInfoCacheItem : public Cxgridlayoutview::TcxGridLayoutViewRecordViewInfoCacheItem
{
	typedef Cxgridlayoutview::TcxGridLayoutViewRecordViewInfoCacheItem inherited;
	
private:
	Dxgdiplusclasses::TdxGPImage* FBitmap;
	bool FSelected;
	bool FIsSelectedAssigned;
	void __fastcall SetBitmap(Dxgdiplusclasses::TdxGPImage* const Value);
	void __fastcall SetSelected(const bool Value);
	
public:
	__fastcall virtual TcxGridLayoutViewCarouselModeRecordViewInfoCacheItem(Cxgridcustomview::TcxCustomGridViewInfoCache* AOwner, int AIndex);
	__fastcall virtual ~TcxGridLayoutViewCarouselModeRecordViewInfoCacheItem(void);
	virtual void __fastcall UnassignValues(bool AKeepMaster);
	__property Dxgdiplusclasses::TdxGPImage* Bitmap = {read=FBitmap, write=SetBitmap};
	__property bool Selected = {read=FSelected, write=SetSelected, nodefault};
	__property bool IsSelectedAssigned = {read=FIsSelectedAssigned, nodefault};
};


class PASCALIMPLEMENTATION TcxGridLayoutViewCarouselModeRecordViewInfo : public Cxgridlayoutview::TcxGridLayoutViewRecordViewInfo
{
	typedef Cxgridlayoutview::TcxGridLayoutViewRecordViewInfo inherited;
	
private:
	int FAlpha;
	double FAngle;
	System::Types::TRect FCalculatedBounds;
	bool FIsInternalPainting;
	HIDESBASE TcxGridLayoutViewCarouselModeRecordViewInfoCacheItem* __fastcall GetCacheItem(void);
	Dxgdiplusclasses::TdxGPImage* __fastcall GetCachedBitmap(void);
	bool __fastcall GetCachedSelected(void);
	int __fastcall GetCarouselIndex(void);
	HIDESBASE TcxGridLayoutViewCarouselModeRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	void __fastcall SetCachedSelected(const bool Value);
	
protected:
	virtual System::Types::TRect __fastcall GetBackgroundBounds(void);
	virtual System::Types::TRect __fastcall GetEditViewDataBounds(Cxgridlayoutview::TcxGridLayoutViewItemViewInfo* AItem);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual int __fastcall GetPixelScrollSize(void);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall CanGetHitTest(void);
	void __fastcall CheckCachedBitmap(void);
	void __fastcall DrawCachedBitmap(void);
	virtual bool __fastcall HasItemFocusRect(Cxgridlayoutview::TcxGridLayoutViewItemViewInfo* AItem);
	virtual bool __fastcall IsExpanded(void);
	bool __fastcall IsTopRecord(void);
	__property double Angle = {read=FAngle, write=FAngle};
	__property int Alpha = {read=FAlpha, write=FAlpha, nodefault};
	__property TcxGridLayoutViewCarouselModeRecordViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property System::Types::TRect CalculatedBounds = {read=FCalculatedBounds, write=FCalculatedBounds};
	__property Dxgdiplusclasses::TdxGPImage* CachedBitmap = {read=GetCachedBitmap};
	__property bool CachedSelected = {read=GetCachedSelected, write=SetCachedSelected, nodefault};
	__property int CarouselIndex = {read=GetCarouselIndex, nodefault};
	__property bool IsInternalPainting = {read=FIsInternalPainting, nodefault};
	
public:
	virtual bool __fastcall HasPoint(const System::Types::TPoint P);
	__property TcxGridLayoutViewCarouselModeRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
public:
	/* TcxGridLayoutViewRecordViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewCarouselModeRecordViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord) : Cxgridlayoutview::TcxGridLayoutViewRecordViewInfo(ARecordsViewInfo, ARecord) { }
	/* TcxGridLayoutViewRecordViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewCarouselModeRecordViewInfo(void) { }
	
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxTouchPointData
{
public:
	double X;
	double Y;
	double Z;
	int ASignZ;
};
#pragma pack(pop)


class DELPHICLASS TcxGridLayoutViewInfoCarouselModeCalculator;
class DELPHICLASS TcxGridLayoutViewControllerCarouselHelper;
class PASCALIMPLEMENTATION TcxGridLayoutViewCarouselModeRecordsViewInfo : public Cxgridlayoutview::TcxGridLayoutViewRecordsViewInfo
{
	typedef Cxgridlayoutview::TcxGridLayoutViewRecordsViewInfo inherited;
	
public:
	TcxGridLayoutViewCarouselModeRecordViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	bool FIsRadiusCalculating;
	bool FIsPitchAngleCalculated;
	double FOffsetAngle;
	System::Extended FPitchAngle;
	double FRadius;
	System::Types::TSize __fastcall GetAdjustedContentSize(void);
	System::Types::TSize __fastcall GetRotatedContentSize(void);
	TcxGridLayoutViewInfoCarouselModeCalculator* __fastcall GetCalculator(void);
	HIDESBASE Cxgridlayoutview::TcxGridLayoutViewController* __fastcall GetController(void);
	HIDESBASE TcxGridLayoutViewControllerCarouselHelper* __fastcall GetControllerHelper(void);
	HIDESBASE TcxGridLayoutViewCarouselModeRecordViewInfo* __fastcall GetItem(int Index);
	Cxgridlayoutview::TcxGridLayoutViewCarouselMode* __fastcall GetOptions(void);
	System::Extended __fastcall GetPitchAngle(void);
	System::Extended __fastcall GetRollAngle(void);
	TcxTouchPointData __fastcall PointToTouchPointData(const System::Types::TPoint APoint, int ASignZ);
	void __fastcall SetOffsetAngle(const double Value);
	
protected:
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall CalculateVisibleCount(void);
	virtual void __fastcall CalculateVisibleRecordsBound(/* out */ int &AFirstRecordIndex, /* out */ int &ALastRecordIndex);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfoBasedCalculatorClass __fastcall GetCalculatorClass(void);
	System::Classes::TList* __fastcall GetCarouselViewInfos(void);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutRecordViewInfoClass __fastcall GetItemViewInfoClass(void);
	System::Types::TPoint __fastcall GetContentCenter(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordsPainterClass __fastcall GetPainterClass(void);
	System::Types::TSize __fastcall GetRecordSize(void);
	TcxGridLayoutViewCarouselModeRecordViewInfo* __fastcall GetRecordViewInfoByRecordIndex(int ARecordIndex);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsForEdit(void);
	void __fastcall InternalSetOffsetAngle(const double Value);
	bool __fastcall IsAutoPitchAngle(void);
	virtual bool __fastcall IsCarouselMode(void);
	bool __fastcall IsRecordVisible(Cxgridlayoutview::TcxGridLayoutViewRecord* ARecord);
	unsigned __fastcall CalculateAnimationInterval(double Angle);
	void __fastcall CalculateRadius(void);
	double __fastcall CalculateTouchScrollingAngle(const TcxTouchPointData &APrevPoint, const TcxTouchPointData &APoint);
	void __fastcall EndTouchScrolling(void);
	void __fastcall Recalculate(void);
	Dxgdiplusclasses::TdxGPCanvas* __fastcall CreateGPCanvas(Cxgraphics::TcxCanvas* ACanvas);
	__property TcxGridLayoutViewInfoCarouselModeCalculator* Calculator = {read=GetCalculator};
	__property Cxgridlayoutview::TcxGridLayoutViewController* Controller = {read=GetController};
	__property TcxGridLayoutViewControllerCarouselHelper* ControllerHelper = {read=GetControllerHelper};
	__property bool IsRadiusCalculating = {read=FIsRadiusCalculating, nodefault};
	__property TcxGridLayoutViewCarouselModeRecordViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property double OffsetAngle = {read=FOffsetAngle, write=SetOffsetAngle};
	__property Cxgridlayoutview::TcxGridLayoutViewCarouselMode* Options = {read=GetOptions};
	__property System::Extended PitchAngle = {read=GetPitchAngle};
	__property double Radius = {read=FRadius};
	__property System::Extended RollAngle = {read=GetRollAngle};
	
public:
	virtual bool __fastcall CanOffset(int AItemCountDelta);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	virtual void __fastcall OffsetRecords(int AItemCountDelta, int APixelScrollRecordOffsetDelta);
public:
	/* TcxGridCustomLayoutRecordsViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewCarouselModeRecordsViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo) : Cxgridlayoutview::TcxGridLayoutViewRecordsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutRecordsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewCarouselModeRecordsViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridLayoutViewInfoCarouselModeCalculator : public Cxgridlayoutview::TcxGridLayoutViewInfoHorizontalCalculator
{
	typedef Cxgridlayoutview::TcxGridLayoutViewInfoHorizontalCalculator inherited;
	
private:
	int __fastcall CalculateAlpha(TcxGridLayoutViewCarouselModeRecordViewInfo* AViewInfo);
	double __fastcall CalculateAngle(TcxGridLayoutViewCarouselModeRecordViewInfo* AViewInfo);
	System::Types::TRect __fastcall CalculateRecordBounds(const System::Types::TRect &AContentBounds, TcxGridLayoutViewCarouselModeRecordViewInfo* AViewInfo);
	double __fastcall CalculateScale(TcxGridLayoutViewCarouselModeRecordViewInfo* AViewInfo);
	Cxgridlayoutview::TcxGridLayoutViewCarouselMode* __fastcall GetOptions(void);
	double __fastcall GetInterpolatedValue(TcxGridLayoutViewCarouselModeRecordViewInfo* AViewInfo, double ABeginValue, double AEndValue, bool AUseRecordScale);
	HIDESBASE TcxGridLayoutViewCarouselModeRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	
protected:
	virtual void __fastcall BeforeCalculate(void);
	virtual void __fastcall DoCalculate(const System::Types::TRect &AContentBounds);
	__property Cxgridlayoutview::TcxGridLayoutViewCarouselMode* Options = {read=GetOptions};
	
public:
	__property TcxGridLayoutViewCarouselModeRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridLayoutViewInfoCarouselModeCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : Cxgridlayoutview::TcxGridLayoutViewInfoHorizontalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewInfoCarouselModeCalculator(void) { }
	
};


class DELPHICLASS TcxGridCarouselModeAnimationTransition;
class PASCALIMPLEMENTATION TcxGridCarouselModeAnimationTransition : public Dxanimation::TdxAnimationTransition
{
	typedef Dxanimation::TdxAnimationTransition inherited;
	
private:
	double FAngle;
	bool FIsStop;
	TcxGridLayoutViewControllerCarouselHelper* FControllerHelper;
	double FScale;
	double FStartAngle;
	TcxGridLayoutViewCarouselModeRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	
protected:
	virtual void __fastcall DoAnimate(void);
	bool __fastcall NeedSkipCards(void);
	virtual double __fastcall PositionToAngle(int APosition);
	__property double Angle = {read=FAngle};
	__property TcxGridLayoutViewControllerCarouselHelper* ControllerHelper = {read=FControllerHelper};
	__property bool IsStop = {read=FIsStop, write=FIsStop, nodefault};
	__property TcxGridLayoutViewCarouselModeRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	__property double Scale = {read=FScale};
	__property double StartAngle = {read=FStartAngle, write=FStartAngle};
	
public:
	__fastcall virtual TcxGridCarouselModeAnimationTransition(TcxGridLayoutViewControllerCarouselHelper* AControllerHelper, double Angle, unsigned ATime, Dxanimation::TdxAnimationTransitionEffect AEffect);
	__fastcall virtual ~TcxGridCarouselModeAnimationTransition(void);
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxKineticDataPoint
{
public:
	double Angle;
	unsigned Time;
};
#pragma pack(pop)


typedef System::DynamicArray<TcxKineticDataPoint> TcxKineticDataPoints;

class PASCALIMPLEMENTATION TcxGridLayoutViewControllerCarouselHelper : public Cxgridlayoutview::TcxGridLayoutViewControllerHorizontalHelper
{
	typedef Cxgridlayoutview::TcxGridLayoutViewControllerHorizontalHelper inherited;
	
private:
	TcxGridCarouselModeAnimationTransition* FAnimationTransition;
	bool FIsInternalTopRecordIndexChanging;
	TcxKineticDataPoints FKineticDataPoints;
	int FPrevStartRecordIndex;
	TcxTouchPointData FTouchPoint;
	void __fastcall AddKineticDataPoint(double Angle);
	int __fastcall GetInternalTopRecordIndex(void);
	TcxGridLayoutViewCarouselModeRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	void __fastcall SetInternalTopRecordIndex(int Value);
	void __fastcall SetTouchPoint(const TcxTouchPointData &Value);
	
protected:
	virtual int __fastcall GetPageRecordCount(int AVisibleRecordCount);
	bool __fastcall IsForegroundRecord(int AIndex);
	void __fastcall UpdatePrevStartRecordIndex(void);
	void __fastcall BeginTouchScrolling(System::Classes::TShiftState Shift, const System::Types::TPoint P);
	bool __fastcall IsTouchScrolling(System::Classes::TShiftState Shift);
	void __fastcall EndTouchScrolling(void);
	void __fastcall TouchScrolling(const System::Types::TPoint P);
	void __fastcall StartAnimation(Dxanimation::TdxAnimationTransitionEffect AEffect, double Angle, int ATime);
	void __fastcall StartCarouselAnimation(int AItemCountDelta);
	void __fastcall StartKinematicAnimation(void);
	void __fastcall StopAnimation(void);
	__property TcxGridCarouselModeAnimationTransition* AnimationTransition = {read=FAnimationTransition};
	__property int InternalTopRecordIndex = {read=GetInternalTopRecordIndex, write=SetInternalTopRecordIndex, nodefault};
	__property bool IsInternalTopRecordIndexChanging = {read=FIsInternalTopRecordIndexChanging, nodefault};
	__property int PrevStartRecordIndex = {read=FPrevStartRecordIndex, write=FPrevStartRecordIndex, nodefault};
	__property TcxGridLayoutViewCarouselModeRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
	__property TcxTouchPointData TouchPoint = {read=FTouchPoint, write=SetTouchPoint};
	__property TcxKineticDataPoints KineticDataPoints = {read=FKineticDataPoints};
	
public:
	__fastcall virtual TcxGridLayoutViewControllerCarouselHelper(Cxgridcustomlayoutview::TcxGridCustomLayoutViewController* AController);
	__fastcall virtual ~TcxGridLayoutViewControllerCarouselHelper(void);
	virtual int __fastcall GetScrollDelta(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridlayoutviewcarouselmode */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDLAYOUTVIEWCAROUSELMODE)
using namespace Cxgridlayoutviewcarouselmode;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridlayoutviewcarouselmodeHPP
