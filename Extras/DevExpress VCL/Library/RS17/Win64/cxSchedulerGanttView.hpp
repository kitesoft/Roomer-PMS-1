// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerGanttView.pas' rev: 24.00 (Win64)

#ifndef CxschedulerganttviewHPP
#define CxschedulerganttviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxSchedulerTimeGridView.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerganttview
{
//-- type declarations -------------------------------------------------------
enum TcxSchedulerGanttViewEventStyle : unsigned char { esDefault, esProgress };

class DELPHICLASS TcxSchedulerGanttViewEventLayoutBuilder;
class PASCALIMPLEMENTATION TcxSchedulerGanttViewEventLayoutBuilder : public Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder
{
	typedef Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder inherited;
	
public:
	virtual void __fastcall Calculate(void);
public:
	/* TcxSchedulerEventLayoutBuilder.Create */ inline __fastcall virtual TcxSchedulerGanttViewEventLayoutBuilder(void) : Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder() { }
	/* TcxSchedulerEventLayoutBuilder.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttViewEventLayoutBuilder(void) { }
	
};


typedef System::DynamicArray<System::Types::TRect> TcxSchedulerGanttViewLinkLines;

class DELPHICLASS TcxSchedulerGanttViewLinkViewInfo;
class DELPHICLASS TcxSchedulerGanttViewViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerGanttViewLinkViewInfo : public Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem inherited;
	
private:
	Cxlookandfeelpainters::TcxArrowDirection FArrowDirection;
	System::Types::TRect FArrowRect;
	System::Types::TRect FClipRect;
	Cxschedulerstorage::TcxSchedulerEventItemLink* FEventItemLink;
	Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* FFinishEventViewInfo;
	System::UnicodeString FHint;
	TcxSchedulerGanttViewLinkLines FLines;
	Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* FStartEventViewInfo;
	TcxSchedulerGanttViewViewInfo* FViewInfo;
	Cxlookandfeelpainters::TcxArrowDirection __fastcall GetArrowDirection(const System::Types::TPoint AArrowStart, const System::Types::TPoint AArrowFinish);
	bool __fastcall GetIsHot(void);
	Cxschedulerstorage::TcxSchedulerEventRelation __fastcall GetRelation(void);
	void __fastcall InitializeFinishParams(System::Types::TRect &AStartRect, System::Types::TRect &AFinishRect, /* out */ System::Types::TPoint &P1, /* out */ System::Types::TPoint &P2);
	void __fastcall InitializeStartParams(System::Types::TRect &AStartRect, /* out */ System::Types::TPoint &P1, /* out */ System::Types::TPoint &P2);
	
protected:
	virtual bool __fastcall GetHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest, bool &ABreak);
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall BeforeCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Calculate(System::Types::TRect &AStartRect, System::Types::TRect &AFinishRect);
	virtual void __fastcall CalculateArrowRect(const System::Types::TPoint AArrowStart, const System::Types::TPoint AArrowFinish);
	virtual void __fastcall CalculateBounds(void);
	void __fastcall SetClipRegion(Cxgraphics::TcxCanvas* ACanvas);
	__property Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* FinishEventViewInfo = {read=FFinishEventViewInfo};
	__property Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* StartEventViewInfo = {read=FStartEventViewInfo};
	__property System::Types::TRect ClipRect = {read=FClipRect};
	
public:
	virtual void __fastcall Initialize(TcxSchedulerGanttViewViewInfo* AViewInfo, Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AStartEventViewInfo, Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AFinishEventViewInfo, Cxschedulerstorage::TcxSchedulerEventItemLink* AEventItemLink);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property Cxlookandfeelpainters::TcxArrowDirection ArrowDirection = {read=FArrowDirection, nodefault};
	__property System::Types::TRect ArrowRect = {read=FArrowRect};
	__property Cxschedulerstorage::TcxSchedulerEventItemLink* EventItemLink = {read=FEventItemLink};
	__property System::UnicodeString Hint = {read=FHint};
	__property bool IsHot = {read=GetIsHot, nodefault};
	__property TcxSchedulerGanttViewLinkLines Lines = {read=FLines};
	__property Cxschedulerstorage::TcxSchedulerEventRelation Relation = {read=GetRelation, nodefault};
	__property TcxSchedulerGanttViewViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerGanttViewLinkViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttViewLinkViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerGanttViewExpandButtonViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerGanttViewExpandButtonViewInfo : public Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerControlEvent* FEvent;
	bool FExpanded;
	
protected:
	void __fastcall DoClick(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property Cxschedulerstorage::TcxSchedulerControlEvent* Event = {read=FEvent};
	__property bool Expanded = {read=FExpanded, nodefault};
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerGanttViewExpandButtonViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttViewExpandButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerGanttViewTotalProgressViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerGanttViewTotalProgressViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<System::Types::TPoint> _TcxSchedulerGanttViewTotalProgressViewInfo__1;
	
	typedef System::DynamicArray<System::Types::TPoint> _TcxSchedulerGanttViewTotalProgressViewInfo__2;
	
	
private:
	System::Types::TRect FContentArea;
	bool FDrawAsPolyline;
	System::Uitypes::TColor FLineColor;
	_TcxSchedulerGanttViewTotalProgressViewInfo__1 FPoints;
	_TcxSchedulerGanttViewTotalProgressViewInfo__2 FProgressNodes;
	System::Types::TRect FTimeLineRect;
	TcxSchedulerGanttViewViewInfo* FViewInfo;
	bool __fastcall FindUncompliteEventBeforeLine(const System::Types::TRect &ALine, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* &AViewInfo);
	System::Types::TRect __fastcall GetTimeLineApproximateRect(void);
	System::Types::TRect __fastcall GetTimeLineRect(void);
	bool __fastcall GetUncompliteEventPoint(const System::Types::TRect &ALine, System::Types::TPoint &P, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	
public:
	__fastcall virtual TcxSchedulerGanttViewTotalProgressViewInfo(TcxSchedulerGanttViewViewInfo* AViewInfo);
	virtual void __fastcall Calculate(void);
	void __fastcall CalculatePolyline(void);
	void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawProgressNodes(Cxgraphics::TcxCanvas* ACanvas);
	__property System::Types::TRect ContentArea = {read=FContentArea};
	__property bool DrawAsPolyline = {read=FDrawAsPolyline, nodefault};
	__property System::Uitypes::TColor LineColor = {read=FLineColor, nodefault};
	__property System::Types::TRect TimeLineRect = {read=FTimeLineRect};
	__property TcxSchedulerGanttViewViewInfo* ViewInfo = {read=FViewInfo};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttViewTotalProgressViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerGanttView;
class PASCALIMPLEMENTATION TcxSchedulerGanttViewViewInfo : public Cxschedulertimegridview::TcxSchedulerTimeGridViewViewInfo
{
	typedef Cxschedulertimegridview::TcxSchedulerTimeGridViewViewInfo inherited;
	
private:
	Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* FExpandButtons;
	TcxSchedulerGanttViewLinkViewInfo* FHotLink;
	Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* FLinks;
	TcxSchedulerGanttViewTotalProgressViewInfo* FTotalProgressViewInfo;
	Cxclasses::TcxObjectList* FVisibleEventEnumerationList;
	int FVisibleEventWithoutResourceCount;
	TcxSchedulerGanttView* __fastcall GetGanttView(void);
	bool __fastcall GetIsHotTrackEnabled(void);
	Cxgraphics::TcxViewParams __fastcall GetLinkViewParams(void);
	Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* __fastcall GetVisibleEventEnumeration(int AIndex);
	void __fastcall SetHotLink(TcxSchedulerGanttViewLinkViewInfo* AHotLink);
	
protected:
	virtual void __fastcall AddEventForCalculation(Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder* ABuilder, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int AResourceIndex);
	void __fastcall CalculateExpandButtonViewInfos(void);
	virtual void __fastcall CheckEventVisibility(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* ACell, int AIndex);
	virtual void __fastcall Clear(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerEventViewData* __fastcall CreateEventViewData(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::Types::TRect &ABounds, const System::TDateTime AStart, const System::TDateTime AFinish, Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* AResource);
	virtual Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder* __fastcall CreateLayoutBuilder(void);
	bool __fastcall CreateLinkItemViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo, Cxschedulerstorage::TcxSchedulerEventItemLink* AEventItemLink, /* out */ TcxSchedulerGanttViewLinkViewInfo* &ALinkItem);
	virtual void __fastcall DoCalculate(void);
	bool __fastcall FindEventViewInfoBySource(Cxschedulerstorage::TcxSchedulerEvent* AEvent, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* &AViewInfo);
	bool __fastcall GetEventBounds(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, /* out */ System::Types::TRect &AEventRect);
	virtual int __fastcall GetEventForResourceCount(int AResourceIndex, /* out */ System::Variant &AResourceID);
	virtual int __fastcall GetEventWithoutResourceCount(void);
	virtual int __fastcall GetIndentBetweenLines(void);
	virtual bool __fastcall GetNeedShowCurrentTime(void);
	virtual bool __fastcall HasVisibleEvents(void);
	virtual bool __fastcall IsGanttTaskVisible(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual bool __fastcall IsGroup(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall IsMilestone(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	bool __fastcall IsTaskLinksExpanded(Cxschedulerstorage::TcxSchedulerEventLinks* ATaskLinks);
	virtual int __fastcall NavigationButtonOffset(Cxschedulercustomresourceview::TcxSchedulerContentNavigationButtonKind AKind, int AResourceIndex);
	virtual void __fastcall CreateLinks(void);
	virtual void __fastcall RecreateLinks(void);
	__property Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* ExpandButtons = {read=FExpandButtons};
	
public:
	__fastcall virtual TcxSchedulerGanttViewViewInfo(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerGanttViewViewInfo(void);
	virtual void __fastcall CalculateHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	virtual bool __fastcall IsEventExpanded(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	__property TcxSchedulerGanttViewLinkViewInfo* HotLink = {read=FHotLink, write=SetHotLink};
	__property Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* Links = {read=FLinks};
	__property Cxgraphics::TcxViewParams LinkViewParams = {read=GetLinkViewParams};
	__property TcxSchedulerGanttViewTotalProgressViewInfo* TotalProgressViewInfo = {read=FTotalProgressViewInfo};
	__property TcxSchedulerGanttView* View = {read=GetGanttView};
	__property Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* VisibleEventEnumerationList[int AIndex] = {read=GetVisibleEventEnumeration};
};


class DELPHICLASS TcxSchedulerGanttViewPainter;
class PASCALIMPLEMENTATION TcxSchedulerGanttViewPainter : public Cxschedulertimegridview::TcxSchedulerTimeGridViewPainter
{
	typedef Cxschedulertimegridview::TcxSchedulerTimeGridViewPainter inherited;
	
private:
	HIDESBASE TcxSchedulerGanttView* __fastcall GetView(void);
	HIDESBASE TcxSchedulerGanttViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall DoDrawExpandButton(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	void __fastcall DoDrawLinkItem(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	
public:
	virtual void __fastcall Paint(void);
	__property TcxSchedulerGanttView* View = {read=GetView};
	__property TcxSchedulerGanttViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerCustomViewPainter.Create */ inline __fastcall virtual TcxSchedulerGanttViewPainter(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulertimegridview::TcxSchedulerTimeGridViewPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttViewPainter(void) { }
	
};


class DELPHICLASS TcxSchedulerGanttViewHitTest;
class PASCALIMPLEMENTATION TcxSchedulerGanttViewHitTest : public Cxschedulertimegridview::TcxSchedulerTimeGridViewHitTest
{
	typedef Cxschedulertimegridview::TcxSchedulerTimeGridViewHitTest inherited;
	
private:
	bool __fastcall GetHitAtEventDraggingArea(void);
	TcxSchedulerGanttViewExpandButtonViewInfo* __fastcall GetHitExpandButton(void);
	TcxSchedulerGanttViewLinkViewInfo* __fastcall GetHitLink(void);
	HIDESBASE TcxSchedulerGanttView* __fastcall GetView(void);
	
protected:
	bool FCalcEventDraggingArea;
	System::Types::TRect FEventDraggingArea;
	__property TcxSchedulerGanttView* View = {read=GetView};
	__property TcxSchedulerGanttViewExpandButtonViewInfo* HitExpandButton = {read=GetHitExpandButton};
	__property TcxSchedulerGanttViewLinkViewInfo* HitLink = {read=GetHitLink};
	
public:
	__property bool HitAtEventDraggingArea = {read=GetHitAtEventDraggingArea, nodefault};
	__property bool HitAtExpandButton = {read=GetBitState, index=23, nodefault};
	__property bool HitAtLink = {read=GetBitState, index=21, nodefault};
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerGanttViewHitTest(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulertimegridview::TcxSchedulerTimeGridViewHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttViewHitTest(void) { }
	
};


enum TcxSchedulerEventDragMode : unsigned char { sedmNone, sedmMoveTo, sedmTaskLinkTo };

class DELPHICLASS TcxSchedulerGanttDragObject;
class DELPHICLASS TcxSchedulerGanttViewController;
class PASCALIMPLEMENTATION TcxSchedulerGanttDragObject : public Cxschedulercustomcontrols::TcxSchedulerDragObject
{
	typedef Cxschedulercustomcontrols::TcxSchedulerDragObject inherited;
	
private:
	bool FDragGroupedTaskLinks;
	TcxSchedulerGanttViewController* __fastcall GetController(void);
	
protected:
	virtual System::Uitypes::TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	__property TcxSchedulerGanttViewController* Controller = {read=GetController};
	
public:
	__fastcall virtual TcxSchedulerGanttDragObject(Vcl::Controls::TControl* AControl);
	__property bool DragGroupedTaskLinks = {read=FDragGroupedTaskLinks, write=FDragGroupedTaskLinks, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttDragObject(void) { }
	
};


class DELPHICLASS TcxGanttDragEventHelper;
class PASCALIMPLEMENTATION TcxGanttDragEventHelper : public Cxschedulertimegridview::TcxTimeGridDragEventHelper
{
	typedef Cxschedulertimegridview::TcxTimeGridDragEventHelper inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerControlEvent* FHitEvent;
	HIDESBASE TcxSchedulerGanttViewController* __fastcall GetController(void);
	TcxSchedulerGanttDragObject* __fastcall GetDragObject(void);
	HIDESBASE TcxSchedulerGanttViewHitTest* __fastcall GetHitTest(void);
	HIDESBASE TcxSchedulerGanttViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall ApplyChanges(void);
	virtual void __fastcall ApplyTaskLinks(void);
	virtual bool __fastcall CanDragTo(System::TDateTime ADeltaTime);
	virtual void __fastcall DragOver(const System::Types::TPoint P, System::Uitypes::TDragState State, bool &Accepted);
	virtual void __fastcall EndDrag(bool Accepted);
	virtual void __fastcall InternalApplyTaskLink(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxschedulerstorage::TcxSchedulerEvent* ALinkedEvent);
	virtual bool __fastcall IsAtOrigin(void);
	virtual void __fastcall PrepareGroupedTaskLinks(void);
	virtual void __fastcall UpdateViewClonesTime(void);
	__property TcxSchedulerGanttViewController* Controller = {read=GetController};
	__property TcxSchedulerGanttDragObject* DragObject = {read=GetDragObject};
	__property TcxSchedulerGanttViewHitTest* HitTest = {read=GetHitTest};
	__property TcxSchedulerGanttViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxGanttDragEventHelper(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulertimegridview::TcxTimeGridDragEventHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGanttDragEventHelper(void) { }
	
};


class DELPHICLASS TcxGanttEventSizing;
class PASCALIMPLEMENTATION TcxGanttEventSizing : public Cxschedulertimegridview::TcxTimeGridEventSizing
{
	typedef Cxschedulertimegridview::TcxTimeGridEventSizing inherited;
	
protected:
	virtual bool __fastcall CanResize(void);
	virtual void __fastcall DragOver(const System::Types::TPoint P, System::Uitypes::TDragState State, bool &Accepted);
	virtual bool __fastcall IsValidTime(void);
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxGanttEventSizing(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulertimegridview::TcxTimeGridEventSizing(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGanttEventSizing(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerGanttViewController : public Cxschedulertimegridview::TcxSchedulerTimeGridViewController
{
	typedef Cxschedulertimegridview::TcxSchedulerTimeGridViewController inherited;
	
private:
	TcxSchedulerEventDragMode FEventDragMode;
	Vcl::Forms::TScrollBarKind FTimerScrollBarKind;
	System::Types::TRect FDragEventClipRect;
	void __fastcall CalcDragEventClipRect(void);
	TcxGanttDragEventHelper* __fastcall GetDragEventHelper(void);
	bool __fastcall GetEventHintData(System::UnicodeString &AHint);
	HIDESBASE TcxSchedulerGanttViewHitTest* __fastcall GetHitTest(void);
	bool __fastcall GetLinkHintData(System::UnicodeString &AHint);
	HIDESBASE TcxSchedulerGanttView* __fastcall GetView(void);
	HIDESBASE TcxSchedulerGanttViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall InternalPaintDraggingLink(const System::Types::TPoint AStart, const System::Types::TPoint AFinish);
	void __fastcall SetEventDragMode(TcxSchedulerEventDragMode AValue);
	
protected:
	System::Types::TPoint FPrevDragPoint;
	System::Types::TPoint FStartDragPoint;
	virtual void __fastcall CheckScrolling(const System::Types::TPoint APos);
	virtual void __fastcall CheckTaskLinkDrawOnScroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode);
	virtual bool __fastcall ConsiderHiddenEvents(void);
	virtual Cxschedulercustomcontrols::TcxDragEventHelper* __fastcall CreateDragEventHelper(void);
	virtual Cxschedulercustomcontrols::TcxEventSizingHelper* __fastcall CreateResizeEventHelper(void);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall EraseDraggingLink(void);
	virtual System::Types::TRect __fastcall GetDragEventClipRect(void);
	virtual void __fastcall InitTimer(bool AllowStart, System::Uitypes::TScrollCode AScrollCode);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall OnTimer(System::TObject* Sender);
	virtual void __fastcall PaintDraggingLink(const System::Types::TPoint P);
	virtual void __fastcall Scrolling(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual bool __fastcall ShowHint(void);
	virtual void __fastcall StartDrag(Vcl::Controls::TDragObject* &DragObject);
	virtual void __fastcall UpdateDraggingLink(const System::Types::TPoint P);
	void __fastcall UpdateEventDragMode(void);
	__property TcxGanttDragEventHelper* DragEventHelper = {read=GetDragEventHelper};
	__property TcxSchedulerEventDragMode EventDragMode = {read=FEventDragMode, write=SetEventDragMode, nodefault};
	__property TcxSchedulerGanttViewHitTest* HitTest = {read=GetHitTest};
	__property TcxSchedulerGanttView* View = {read=GetView};
	__property TcxSchedulerGanttViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerTimeGridViewController.Create */ inline __fastcall virtual TcxSchedulerGanttViewController(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulertimegridview::TcxSchedulerTimeGridViewController(AOwner) { }
	/* TcxSchedulerTimeGridViewController.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttViewController(void) { }
	
};


typedef void __fastcall (__closure *TcxSchedulerShowTaskDependencyEditorEvent)(Cxschedulercustomcontrols::TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerEventItemLink* ALink, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerStartLinkEventEvent)(Cxschedulercustomcontrols::TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool &AAllow);

typedef void __fastcall (__closure *TcxSchedulerEndLinkEventEvent)(Cxschedulercustomcontrols::TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* ALinkEvent, bool &AAllow);

class PASCALIMPLEMENTATION TcxSchedulerGanttView : public Cxschedulertimegridview::TcxSchedulerTimeGridView
{
	typedef Cxschedulertimegridview::TcxSchedulerTimeGridView inherited;
	
private:
	TcxSchedulerGanttViewEventStyle FEventsStyle;
	System::Uitypes::TColor FLinkLineColor;
	bool FShowExpandButtons;
	bool FShowTotalProgressLine;
	System::Uitypes::TColor FTotalProgressLineColor;
	TcxSchedulerEndLinkEventEvent FOnEndLinkEvent;
	TcxSchedulerShowTaskDependencyEditorEvent FOnShowTaskDependencyEditor;
	TcxSchedulerStartLinkEventEvent FOnStartLinkEvent;
	HIDESBASE TcxSchedulerGanttViewController* __fastcall GetController(void);
	HIDESBASE TcxSchedulerGanttViewHitTest* __fastcall GetHitTest(void);
	HIDESBASE TcxSchedulerGanttViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetEventsStyle(TcxSchedulerGanttViewEventStyle AValue);
	void __fastcall SetLinkLineColor(System::Uitypes::TColor AColor);
	void __fastcall SetShowExpandButtons(bool AValue);
	void __fastcall SetShowTotalProgressLine(bool AValue);
	void __fastcall SetTotalProgressLineColor(System::Uitypes::TColor AValue);
	
protected:
	virtual bool __fastcall CanEventEdit(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool AInplace);
	virtual bool __fastcall CheckEventsVisibility(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlPainter* __fastcall CreatePainter(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo* __fastcall CreateViewInfo(void);
	virtual bool __fastcall DoEndLinkEvent(Cxschedulerstorage::TcxSchedulerControlEvent* ALink);
	virtual bool __fastcall DoShowTaskDependencyEditor(Cxschedulerstorage::TcxSchedulerEventItemLink* ALink);
	virtual bool __fastcall DoStartLinkEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual Cxcontrols::TDragControlObjectClass __fastcall GetDragObjectClass(void);
	virtual System::UnicodeString __fastcall GetEventHintText(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall IsInplaceEditingEnabled(void);
	virtual bool __fastcall ShowTaskComplete(void);
	virtual void __fastcall ShowTaskDependencyEditor(Cxschedulerstorage::TcxSchedulerEventItemLink* ALink);
	virtual void __fastcall ValidateContentPopupMenuItems(Cxschedulercustomcontrols::TcxSchedulerContentPopupMenuItems &AItems);
	__property TcxSchedulerGanttViewController* Controller = {read=GetController};
	__property EventDetailInfo = {default=0};
	__property TcxSchedulerGanttViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerGanttView(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner);
	__property TcxSchedulerGanttViewHitTest* HitTest = {read=GetHitTest};
	
__published:
	__property TreeBrowser;
	__property TcxSchedulerGanttViewEventStyle EventsStyle = {read=FEventsStyle, write=SetEventsStyle, default=0};
	__property System::Uitypes::TColor LinkLineColor = {read=FLinkLineColor, write=SetLinkLineColor, default=8388608};
	__property bool ShowExpandButtons = {read=FShowExpandButtons, write=SetShowExpandButtons, default=0};
	__property bool ShowTotalProgressLine = {read=FShowTotalProgressLine, write=SetShowTotalProgressLine, default=0};
	__property System::Uitypes::TColor TotalProgressLineColor = {read=FTotalProgressLineColor, write=SetTotalProgressLineColor, default=255};
	__property TcxSchedulerEndLinkEventEvent OnEndLinkEvent = {read=FOnEndLinkEvent, write=FOnEndLinkEvent};
	__property TcxSchedulerShowTaskDependencyEditorEvent OnShowTaskDependencyEditor = {read=FOnShowTaskDependencyEditor, write=FOnShowTaskDependencyEditor};
	__property TcxSchedulerStartLinkEventEvent OnStartLinkEvent = {read=FOnStartLinkEvent, write=FOnStartLinkEvent};
public:
	/* TcxSchedulerTimeGridView.Destroy */ inline __fastcall virtual ~TcxSchedulerGanttView(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 htcLink = System::Int8(0x15);
static const System::Int8 htcExpandButton = System::Int8(0x17);
}	/* namespace Cxschedulerganttview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERGANTTVIEW)
using namespace Cxschedulerganttview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerganttviewHPP
