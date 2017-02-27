// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerDayView.pas' rev: 24.00 (Win64)

#ifndef CxschedulerdayviewHPP
#define CxschedulerdayviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerdayview
{
//-- type declarations -------------------------------------------------------
enum TcxSchedulerAllDayAreaScrollBar : unsigned char { adsbDefault, adsbNever, adsbAlways };

__interface IcxSchedulerTimeRulerParams;
typedef System::DelphiInterface<IcxSchedulerTimeRulerParams> _di_IcxSchedulerTimeRulerParams;
__interface  INTERFACE_UUID("{FEAA09ED-8FE1-4968-9BCB-0FC26B13A391}") IcxSchedulerTimeRulerParams  : public System::IInterface 
{
	
public:
	virtual Cxgraphics::TcxViewParams __fastcall GetTimeRulerParams(void) = 0 ;
};

class DELPHICLASS TcxSchedulerDayViewStyles;
class PASCALIMPLEMENTATION TcxSchedulerDayViewStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	Cxschedulercustomcontrols::TcxCustomScheduler* FScheduler;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual TcxSchedulerDayViewStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetHeaderContainerParams(const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, bool ASelected);
	Cxgraphics::TcxViewParams __fastcall GetTimeRulerParams(void);
	Cxgraphics::TcxViewParams __fastcall GetTimeLineParams(void);
	__property Cxschedulercustomcontrols::TcxCustomScheduler* Scheduler = {read=FScheduler};
	
__published:
	__property Cxstyles::TcxStyle* HeaderContainer = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* SelectedHeaderContainer = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* TimeLine = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* TimeRuler = {read=GetValue, write=SetValue, index=3};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxSchedulerDayViewStyles(void) { }
	
};


typedef void __fastcall (__closure *TcxSchedulerCustomDrawContainerEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxschedulercustomresourceview::TcxSchedulerContainerCellViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxSchedulerCustomDrawTimeRulerEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, Cxschedulercustomresourceview::TcxSchedulerTimeRulerCellViewInfo* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerDayView;
class DELPHICLASS TcxSchedulerAllDayContainerGestureScrollHelper;
class DELPHICLASS TcxSchedulerTimeRulerPopupMenu;
class DELPHICLASS TcxSchedulerDayViewHitTest;
class DELPHICLASS TcxSchedulerDayViewViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerDayView : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceView
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceView inherited;
	
private:
	TcxSchedulerAllDayAreaScrollBar FAllDayAreaScrollBar;
	TcxSchedulerAllDayContainerGestureScrollHelper* FAllDayContainerGestureScrollHelper;
	Cxcontrols::TcxControlScrollBarHelper* FAllDayScrollBar;
	bool FAlwaysShowEventTime;
	bool FAutoContentHeight;
	bool FDayHeaderArea;
	bool FEventShadows;
	bool FHeaderContainer;
	bool FShowAllDayEventsInContentArea;
	TcxSchedulerDayViewStyles* FStyles;
	bool FTimeRulerMinutes;
	TcxSchedulerTimeRulerPopupMenu* FTimeRulerPopupMenu;
	int FTimeScale;
	bool FWorkTimeOnly;
	TcxSchedulerCustomDrawContainerEvent FOnCustomDrawContainer;
	TcxSchedulerCustomDrawTimeRulerEvent FOnCustomDrawTimeRuler;
	void __fastcall DoAllDayScroll(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	HIDESBASE TcxSchedulerDayViewHitTest* __fastcall GetHitTest(void);
	HIDESBASE TcxSchedulerDayViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall InitAllDayScrollBar(void);
	void __fastcall SetAlwaysShowEventTime(bool AValue);
	void __fastcall SetAutoContentHeight(bool AValue);
	void __fastcall SetEventShadows(bool AValue);
	void __fastcall SetHeaderContainer(bool AValue);
	void __fastcall SetAllDayAreaScrollBar(TcxSchedulerAllDayAreaScrollBar AValue);
	void __fastcall SetDayHeaderArea(bool AValue);
	void __fastcall SetShowAllDayEventsInContentArea(bool AValue);
	void __fastcall SetStyles(TcxSchedulerDayViewStyles* AValue);
	void __fastcall SetTimeRulerMinutes(bool AValue);
	void __fastcall SetTimeRulerPopupMenu(TcxSchedulerTimeRulerPopupMenu* AValue);
	void __fastcall SetTimeScale(int AValue);
	void __fastcall SetWorkTimeOnly(bool AValue);
	
protected:
	virtual void __fastcall DeactivateView(void);
	virtual void __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlPainter* __fastcall CreatePainter(void);
	virtual TcxSchedulerDayViewStyles* __fastcall CreateStyles(void);
	virtual TcxSchedulerTimeRulerPopupMenu* __fastcall CreateTimeRulerPopupMenu(void);
	virtual Cxschedulercustomresourceview::TcxCustomResourceViewAdapter* __fastcall CreateViewAdapter(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall DoCustomDrawContainer(Cxschedulercustomresourceview::TcxSchedulerContainerCellViewInfo* ACell, bool &ADone);
	virtual void __fastcall DoCustomDrawTimeRuler(Cxschedulercustomresourceview::TcxSchedulerTimeRulerCellViewInfo* ACell, bool &ADone);
	virtual bool __fastcall DoShowPopupMenu(int X, int Y);
	virtual bool __fastcall EventContentSelected(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall GetEditWithSingleLineEditor(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual System::TDateTime __fastcall GetFirstVisibleTime(void);
	virtual Dxtouch::_di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint APoint);
	virtual System::TDateTime __fastcall GetLastVisibleTime(void);
	virtual System::TDateTime __fastcall GetTimeIncrement(void);
	virtual System::Types::TRect __fastcall GetViewContentRect(void);
	virtual bool __fastcall IsDayView(void);
	virtual void __fastcall MakeEventVisible(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall ScrollVisibleDays(bool AScrollUp);
	virtual void __fastcall TimeChanged(void);
	virtual void __fastcall VisibleChanged(void);
	__property Cxcontrols::TcxControlScrollBarHelper* AllDayScrollBar = {read=FAllDayScrollBar};
	__property TcxSchedulerDayViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerDayView(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerDayView(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall MakeWorkTimeVisible(void);
	__property TcxSchedulerDayViewHitTest* HitTest = {read=GetHitTest};
	__property Scheduler;
	__property WorkDays;
	__property WorkStart = {default=0};
	__property WorkFinish = {default=0};
	
__published:
	__property CanShow = {default=1};
	__property Active = {default=0};
	__property TcxSchedulerAllDayAreaScrollBar AllDayAreaScrollBar = {read=FAllDayAreaScrollBar, write=SetAllDayAreaScrollBar, default=0};
	__property bool AlwaysShowEventTime = {read=FAlwaysShowEventTime, write=SetAlwaysShowEventTime, default=0};
	__property bool AutoContentHeight = {read=FAutoContentHeight, write=SetAutoContentHeight, default=0};
	__property bool DayHeaderArea = {read=FDayHeaderArea, write=SetDayHeaderArea, default=1};
	__property EventImagesLayout = {default=0};
	__property bool EventShadows = {read=FEventShadows, write=SetEventShadows, default=1};
	__property GroupingKind = {default=0};
	__property bool HeaderContainer = {read=FHeaderContainer, write=SetHeaderContainer, default=1};
	__property bool ShowAllDayEventsInContentArea = {read=FShowAllDayEventsInContentArea, write=SetShowAllDayEventsInContentArea, default=0};
	__property TcxSchedulerDayViewStyles* Styles = {read=FStyles, write=SetStyles};
	__property bool TimeRulerMinutes = {read=FTimeRulerMinutes, write=SetTimeRulerMinutes, default=0};
	__property TcxSchedulerTimeRulerPopupMenu* TimeRulerPopupMenu = {read=FTimeRulerPopupMenu, write=SetTimeRulerPopupMenu};
	__property int TimeScale = {read=FTimeScale, write=SetTimeScale, default=30};
	__property bool WorkTimeOnly = {read=FWorkTimeOnly, write=SetWorkTimeOnly, default=0};
	__property TcxSchedulerCustomDrawContainerEvent OnCustomDrawContainer = {read=FOnCustomDrawContainer, write=FOnCustomDrawContainer};
	__property TcxSchedulerCustomDrawTimeRulerEvent OnCustomDrawTimeRuler = {read=FOnCustomDrawTimeRuler, write=FOnCustomDrawTimeRuler};
};


class PASCALIMPLEMENTATION TcxSchedulerAllDayContainerGestureScrollHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxSchedulerDayView* FView;
	
protected:
	bool __fastcall AllowGesture(int AGestureId);
	bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	void __fastcall BeginGestureScroll(System::Types::TPoint APos);
	void __fastcall EndGestureScroll(void);
	void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	int __fastcall GetPanOptions(void);
	bool __fastcall IsPanArea(const System::Types::TPoint APoint);
	bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	
public:
	__fastcall TcxSchedulerAllDayContainerGestureScrollHelper(TcxSchedulerDayView* AView);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerAllDayContainerGestureScrollHelper(void) { }
	
private:
	void *__IdxGestureClient;	/* Dxtouch::IdxGestureClient */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {652B8A09-DAC8-4332-9206-C8905AEE7791}
	operator Dxtouch::_di_IdxGestureClient()
	{
		Dxtouch::_di_IdxGestureClient intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxtouch::IdxGestureClient*(void) { return (Dxtouch::IdxGestureClient*)&__IdxGestureClient; }
	#endif
	
};


class DELPHICLASS TcxSchedulerDayViewAdapter;
class PASCALIMPLEMENTATION TcxSchedulerDayViewAdapter : public Cxschedulercustomresourceview::TcxCustomResourceViewAdapter
{
	typedef Cxschedulercustomresourceview::TcxCustomResourceViewAdapter inherited;
	
protected:
	int FTopIndex;
	virtual System::TDateTime __fastcall GetPrintRange(int Index);
	virtual void __fastcall Store(void);
	virtual void __fastcall Restore(void);
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerDayViewAdapter(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : Cxschedulercustomresourceview::TcxCustomResourceViewAdapter(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDayViewAdapter(void) { }
	
};


class DELPHICLASS TcxSchedulerDayViewEventCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerDayViewEventCellViewInfo : public Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo inherited;
	
protected:
	virtual void __fastcall AfterDraw(void);
	virtual void __fastcall BeforeDraw(void);
	virtual void __fastcall CalculateCaptions(void);
	virtual void __fastcall CalculateEventTimeVisibility(void);
	virtual void __fastcall CalculateDetailInfo(void);
	virtual void __fastcall CalculateShowTimeAsClock(void);
	virtual void __fastcall CalculateItemsLayout(void);
	virtual void __fastcall CalculateNonDetailEventTimeVisibility(void);
	void __fastcall CalculateTimeLineParams(void);
	virtual bool __fastcall CanShowHint(void);
	virtual void __fastcall DrawContent(void);
	void __fastcall DrawSelection(void);
	void __fastcall DrawShadow(void);
	HIDESBASE void __fastcall DrawState(void)/* overload */;
	virtual System::Types::TRect __fastcall GetBoundsForHitTest(void);
	virtual System::Types::TRect __fastcall GetEditingRect(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	virtual bool __fastcall IsDrawShadowFirst(void);
	virtual bool __fastcall IsHorzSizing(void);
	virtual bool __fastcall IsNeedDrawTime(void);
	bool __fastcall IsShowHeaderEventsInContentArea(void);
	virtual bool __fastcall IsTimeLineVisible(void);
public:
	/* TcxSchedulerEventCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerDayViewEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData) : Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo(AViewData) { }
	/* TcxSchedulerEventCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerDayViewEventCellViewInfo(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  DrawState(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, System::Uitypes::TColor ABorderColor){ Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo::DrawState(ACanvas, ARect, ABorders, ABorderColor); }
	
};


class DELPHICLASS TcxSchedulerDayViewController;
class DELPHICLASS TcxCalculateEventLayout;
class DELPHICLASS TcxEventLayoutInfo;
class PASCALIMPLEMENTATION TcxSchedulerDayViewViewInfo : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewViewInfo inherited;
	
private:
	int __fastcall GetAllDayEventMaxCount(void);
	bool __fastcall GetAutoHeight(void);
	int __fastcall GetColumnInGroup(void);
	int __fastcall GetContentHeight(void);
	TcxSchedulerDayViewController* __fastcall GetController(void);
	TcxSchedulerDayView* __fastcall GetDayView(void);
	int __fastcall GetGroupCount(void);
	bool __fastcall GetHeaderContainer(void);
	int __fastcall GetPrintRowCount(void);
	int __fastcall GetLinePerHour(void);
	bool __fastcall NeedAllDayScrollBar(void);
	void __fastcall SetLargeFont(Vcl::Graphics::TFont* AFont);
	
protected:
	Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder* Builder;
	int FAdditionalTimeZone;
	int FAdditionalTimeZoneBiasDelta;
	System::Types::TRect FAllDayAreaBounds;
	Cxschedulercustomresourceview::TcxSchedulerBackgroundCellViewInfo* FBackground;
	int FColCount;
	int FContentOffset;
	int FCurrentTimeZone;
	int FDayRowCount;
	TcxCalculateEventLayout* FEventLayout;
	int FHeaderLineCount;
	int FHeaderLineHeight;
	int FHeaderOffsetLeft;
	int FAllDayTopIndex;
	bool FIsContainerSelected;
	Vcl::Graphics::TFont* FLargeFont;
	int FPrintStartRow;
	int FPrintFinishRow;
	int FRowCount;
	Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* FTimeRulerCells;
	int FTopIndex;
	int FTimeScale;
	int FUnusedRowCount;
	int FVisibleRowCount;
	virtual Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* __fastcall AddContentCell(const System::Types::TRect &ARect, const System::TDateTime AStart, const System::TDateTime AFinish, int AResourceIndex);
	void __fastcall AddContainerCell(int AColumn, const System::Types::TRect &ABounds);
	void __fastcall AddHeaderContainerEvent(Cxschedulercustomresourceview::TcxSchedulerEventPlace* APlace);
	void __fastcall AddHeaderContainerEventPlace(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int &AColIndex);
	void __fastcall AddMoreEventsButton(const int ARowIndex, bool AIsTop, Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall CalculateAllDayAreaBounds(void);
	void __fastcall CalculateAllDayScrollBar(void);
	virtual void __fastcall CalculateBackground(void);
	virtual void __fastcall CalculateContent(void);
	virtual void __fastcall CalculateContentNavigationButtons(void);
	virtual void __fastcall CalculateEvents(void);
	virtual void __fastcall CalculateEventsForColumn(int AIndex, Cxschedulercustomresourceview::TcxSchedulerContainerCellViewInfo* AContainer, Cxschedulerstorage::TcxSchedulerEventList* AEvents);
	virtual void __fastcall CalculateHeaderEvents(void);
	void __fastcall CalculateHeaderEventsPlace(void);
	void __fastcall CalculateHeaderLineCount(void);
	virtual void __fastcall CalculateHeaders(void);
	virtual void __fastcall CalculateMetrics(void);
	void __fastcall CalculateMetricsForPrinting(void);
	void __fastcall CalculateDisplayRows(void);
	virtual void __fastcall CalculateTimeLine(void);
	void __fastcall CalculateTimeZoneBiasDelta(void);
	void __fastcall CalculateVisibleRows(void);
	void __fastcall CalculateUnusedRowCount(void);
	bool __fastcall CheckDisplayRows(int &AStartRow, int &AFinishRow);
	void __fastcall CheckEventRowsVisibility(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int AStartRow, int AFinishRow);
	virtual void __fastcall Clear(void);
	Cxschedulercustomresourceview::TcxSchedulerEventViewData* __fastcall CreateContentEventViewData(TcxEventLayoutInfo* AEventInfo, Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* AResource);
	Cxschedulercustomresourceview::TcxSchedulerEventViewData* __fastcall CreateHeaderEventViewData(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::Types::TRect &ABounds, const System::TDateTime AStart, const System::TDateTime AFinish, Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* AResource);
	virtual Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* __fastcall CreateEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData);
	virtual TcxCalculateEventLayout* __fastcall CreateEventLayout(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoContentNavigationButtonClick(Cxschedulercustomresourceview::TcxSchedulerContentNavigationButtonViewInfo* Sender);
	virtual void __fastcall DoMoreEventsButtonClick(Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo* Sender);
	void __fastcall ExtractEvents(Cxschedulerstorage::TcxSchedulerEventList* ASource, Cxschedulerstorage::TcxSchedulerEventList* ADest, int AIndex);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ATime, Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* AResource);
	int __fastcall GetColumnDate(int AIndex);
	Cxschedulercustomresourceview::TcxSchedulerColumnPositionInResource __fastcall GetColumnPositionInResource(int AColumnIndex, int AResourceIndex);
	Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* __fastcall GetColumnResource(int AIndex);
	int __fastcall GetColumnResourceIndex(int AIndex);
	virtual Cxschedulercustomresourceview::TcxSchedulerContainerCellViewInfo* __fastcall GetContainer(int AIndex);
	virtual int __fastcall GetContainerCount(void);
	virtual int __fastcall GetDayHeaderHeight(void);
	void __fastcall GetHeaderEventInfo(int AColStart, int AColFinish, /* out */ int &ALeft, /* out */ int &ARight, /* out */ System::TDateTime &AStart, /* out */ System::TDateTime &AFinish);
	int __fastcall GetEventColumnRow(const System::TDateTime ATime, int AColIndex, bool AStart);
	System::UnicodeString __fastcall GetEventSlotDisplayText(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual Cxgraphics::TcxViewParams __fastcall GetTimeLineParams(void);
	Cxgraphics::TcxViewParams __fastcall GetTimeRulerParams(void);
	int __fastcall GetTimeRow(const System::TDateTime ATime, bool AIsStart);
	virtual int __fastcall GetResourcesContentWidth(void);
	System::TDateTime __fastcall GetRowTime(int AColumn, int ARow);
	virtual int __fastcall GetSeparatorCount(void);
	bool __fastcall IsColumnEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, int AIndex, bool IsHeaderEvent);
	bool __fastcall IsContainerSelected(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, System::TDateTime ADate);
	bool __fastcall IsEventVisible(Cxschedulerstorage::TcxSchedulerEvent* AEvent)/* overload */;
	bool __fastcall IsEventVisible(int &AStartRow, int &AStopRow)/* overload */;
	bool __fastcall IsHourVisible(int AIndex);
	bool __fastcall IsRowVisible(int AIndex);
	virtual void __fastcall MakeTimeVisible(const System::TDateTime ATime);
	virtual int __fastcall NavigationButtonOffset(Cxschedulercustomresourceview::TcxSchedulerContentNavigationButtonKind AKind, int AResourceIndex);
	void __fastcall SetColumnTimeLineStyle(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AViewInfo, int AColIndex);
	__property int ColCount = {read=FColCount, nodefault};
	__property int ColumnInGroup = {read=GetColumnInGroup, nodefault};
	__property int ContainerCount = {read=GetContainerCount, nodefault};
	__property Cxschedulercustomresourceview::TcxSchedulerContainerCellViewInfo* Containers[int AIndex] = {read=GetContainer};
	__property TcxSchedulerDayViewController* Controller = {read=GetController};
	__property int GroupCount = {read=GetGroupCount, nodefault};
	
public:
	__fastcall virtual TcxSchedulerDayViewViewInfo(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerDayViewViewInfo(void);
	virtual void __fastcall CalculateHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall ScrollVertical(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall AllDayScroll(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	__property int AllDayTopIndex = {read=FAllDayTopIndex, nodefault};
	__property bool AutoHeight = {read=GetAutoHeight, nodefault};
	__property Cxschedulercustomresourceview::TcxSchedulerBackgroundCellViewInfo* Background = {read=FBackground};
	__property int ContentHeight = {read=GetContentHeight, nodefault};
	__property TcxSchedulerDayView* DayView = {read=GetDayView};
	__property bool HeaderContainer = {read=GetHeaderContainer, nodefault};
	__property Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* HeaderContainerCells = {read=FHeaderContainerCells};
	__property int HeaderLineHeight = {read=FHeaderLineHeight, nodefault};
	__property Vcl::Graphics::TFont* LargeFont = {read=FLargeFont, write=SetLargeFont};
	__property int LinePerHour = {read=GetLinePerHour, nodefault};
	__property int PrintRowCount = {read=GetPrintRowCount, nodefault};
	__property int PrintFinishRow = {read=FPrintFinishRow, nodefault};
	__property int PrintStartRow = {read=FPrintStartRow, nodefault};
	__property int TimeScale = {read=FTimeScale, nodefault};
	__property Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* TimeRulerCells = {read=FTimeRulerCells};
	__property int TopIndex = {read=FTopIndex, nodefault};
	__property int UnusedRowCount = {read=FUnusedRowCount, nodefault};
	__property int VisibleRowCount = {read=FVisibleRowCount, nodefault};
};


class PASCALIMPLEMENTATION TcxSchedulerDayViewHitTest : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest inherited;
	
private:
	Cxschedulercustomresourceview::TcxSchedulerContainerCellViewInfo* __fastcall GetContainerCell(void);
	Cxschedulercustomresourceview::TcxSchedulerTimeRulerCellViewInfo* __fastcall GetTimeRulerCell(void);
	
public:
	__property Cxschedulercustomresourceview::TcxSchedulerContainerCellViewInfo* ContainerCell = {read=GetContainerCell};
	__property bool HitAtContainer = {read=GetBitState, index=4, nodefault};
	__property bool HitAtTimeRuler = {read=GetBitState, index=5, nodefault};
	__property Cxschedulercustomresourceview::TcxSchedulerTimeRulerCellViewInfo* TimeRulerCell = {read=GetTimeRulerCell};
	__property HitAtTimeZoneLabel;
	__property TimeZone;
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerDayViewHitTest(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerDayViewHitTest(void) { }
	
};


class DELPHICLASS TcxDayViewDragEventHelper;
class PASCALIMPLEMENTATION TcxDayViewDragEventHelper : public Cxschedulercustomcontrols::TcxDragEventHelper
{
	typedef Cxschedulercustomcontrols::TcxDragEventHelper inherited;
	
private:
	bool FStartInHeader;
	HIDESBASE TcxSchedulerDayViewController* __fastcall GetController(void);
	HIDESBASE TcxSchedulerDayViewHitTest* __fastcall GetHitTest(void);
	bool __fastcall GetShowHeaderContainer(void);
	
protected:
	virtual __int64 __fastcall GetOriginHitTestMask(void);
	virtual void __fastcall GetOriginState(void);
	virtual bool __fastcall IsAtOrigin(void);
	virtual bool __fastcall InHeader(void);
	void __fastcall SetCloneEventsTimeDelta(System::TDateTime AStart, System::TDateTime ACurrent, bool AInHeader);
	virtual void __fastcall UpdateViewClonesTime(void);
	void __fastcall UpdateEventStates(void);
	__property TcxSchedulerDayViewController* Controller = {read=GetController};
	__property TcxSchedulerDayViewHitTest* HitTest = {read=GetHitTest};
	__property bool ShowHeaderContainer = {read=GetShowHeaderContainer, nodefault};
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxDayViewDragEventHelper(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulercustomcontrols::TcxDragEventHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDayViewDragEventHelper(void) { }
	
};


class DELPHICLASS TcxDayViewEventSizing;
class PASCALIMPLEMENTATION TcxDayViewEventSizing : public Cxschedulercustomcontrols::TcxEventSizingHelper
{
	typedef Cxschedulercustomcontrols::TcxEventSizingHelper inherited;
	
private:
	System::TDateTime FFixedBoundTime;
	HIDESBASE TcxSchedulerDayViewController* __fastcall GetController(void);
	HIDESBASE TcxSchedulerDayViewHitTest* __fastcall GetHitTest(void);
	
protected:
	virtual System::Uitypes::TCursor __fastcall GetDragCursor(bool Accepted);
	virtual __int64 __fastcall GetOriginHitTestMask(void);
	virtual void __fastcall CalcAllDayEvent(void);
	virtual System::TDateTime __fastcall GetFinishTime(void);
	virtual void __fastcall GetOriginState(void);
	System::TDateTime __fastcall GetSizingTime(void);
	virtual System::TDateTime __fastcall GetStartTime(void);
	__property TcxSchedulerDayViewController* Controller = {read=GetController};
	__property TcxSchedulerDayViewHitTest* HitTest = {read=GetHitTest};
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxDayViewEventSizing(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulercustomcontrols::TcxEventSizingHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDayViewEventSizing(void) { }
	
};


class DELPHICLASS TcxSchedulerDayNavigation;
class PASCALIMPLEMENTATION TcxSchedulerDayNavigation : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation inherited;
	
private:
	TcxSchedulerDayView* __fastcall GetDayView(void);
	Cxschedulerutils::TcxSchedulerDateList* __fastcall GetSelectedDays(void);
	HIDESBASE TcxSchedulerDayViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	int FSelRow;
	int __fastcall ColCount(void);
	virtual void __fastcall DoNextColumn(bool AGoToNext, int AColumn, const System::TDateTime ATime, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual bool __fastcall DoNextPage(bool AGoForward, System::TDateTime &ATime, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	int __fastcall GetColumnByDate(const System::TDateTime ADate, System::TObject* AResource);
	System::TDateTime __fastcall GetColumnDate(int AColumn);
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetColumnResource(int AColumn);
	System::TDateTime __fastcall GetRowTime(const int ARow, bool AFinish = false);
	int __fastcall GetTimeRow(const System::TDateTime ATime);
	bool __fastcall IsResourceNavigation(bool AGoToNext, int AColumn, const System::TDateTime ATime);
	
public:
	virtual void __fastcall KeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall ValidateSelection(System::TDateTime &ASelStart, System::TDateTime &ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	System::TDateTime __fastcall ValidateTimeVisibility(System::TDateTime &ADateTime);
	__property TcxSchedulerDayView* DayView = {read=GetDayView};
	__property Cxschedulerutils::TcxSchedulerDateList* SelectedDays = {read=GetSelectedDays};
	__property TcxSchedulerDayViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerViewNavigation.Create */ inline __fastcall TcxSchedulerDayNavigation(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDayNavigation(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerDayViewController : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController inherited;
	
private:
	bool FLockScrolling;
	Vcl::Extctrls::TTimer* FTimer;
	TcxDayViewDragEventHelper* __fastcall GetDragEventHelper(void);
	HIDESBASE TcxSchedulerDayViewHitTest* __fastcall GetHitTest(void);
	System::TDateTime __fastcall GetTimeRulerTime(void);
	HIDESBASE TcxSchedulerDayView* __fastcall GetView(void);
	TcxSchedulerDayViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	bool FIsEditingBeforeMouseDown;
	System::Classes::TList* FScrollAreaRects;
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall CancelScroll(void);
	void __fastcall CheckDragDropScrolling(const System::Types::TPoint P);
	virtual void __fastcall CheckScrolling(const System::Types::TPoint APos);
	void __fastcall CheckTimeRulerTime(void);
	virtual Cxschedulercustomcontrols::TcxDragEventHelper* __fastcall CreateDragEventHelper(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual Cxschedulercustomcontrols::TcxEventSizingHelper* __fastcall CreateResizeEventHelper(void);
	virtual void __fastcall InitTimer(bool AllowStart, System::Uitypes::TScrollCode AScrollCode);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall OnTimer(System::TObject* Sender);
	virtual void __fastcall SelectNextEvent(bool AForward);
	virtual void __fastcall CheckNavigatorScrollArea(const System::Types::TPoint APoint);
	virtual void __fastcall DoneNavigatorScrollArea(void);
	virtual void __fastcall InitNavigatorScrollArea(void);
	__property TcxDayViewDragEventHelper* DragEventHelper = {read=GetDragEventHelper};
	__property TcxSchedulerDayViewHitTest* HitTest = {read=GetHitTest};
	__property TcxSchedulerDayView* View = {read=GetView};
	__property TcxSchedulerDayViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerDayViewController(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerDayViewController(void);
};


class DELPHICLASS TcxSchedulerDayViewPainter;
class PASCALIMPLEMENTATION TcxSchedulerDayViewPainter : public Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter inherited;
	
private:
	HIDESBASE TcxSchedulerDayView* __fastcall GetView(void);
	HIDESBASE TcxSchedulerDayViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawContainerCell(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	virtual void __fastcall DrawDayViewEventCell(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	virtual void __fastcall DrawTimeRulerCell(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	
public:
	virtual void __fastcall Paint(void);
	__property TcxSchedulerDayView* View = {read=GetView};
	__property TcxSchedulerDayViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerCustomViewPainter.Create */ inline __fastcall virtual TcxSchedulerDayViewPainter(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDayViewPainter(void) { }
	
};


class PASCALIMPLEMENTATION TcxEventLayoutInfo : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	int ColStart;
	int ColEnd;
	int ColCount;
	Cxschedulerstorage::TcxSchedulerControlEvent* Event;
	System::Types::TRect FDisplayRect;
	System::TDateTime FFinishTime;
	System::TDateTime FStartTime;
	bool IsBreakEvent;
	int RowCount;
	int StartRow;
	int StopRow;
	int __fastcall ShadowSize(void);
	void __fastcall CalculateDisplayRect(int AWidth, int ARowHeight);
	void __fastcall CalculateTimes(const System::TDateTime ADate, int AScale, int AOfs);
	
public:
	__fastcall virtual TcxEventLayoutInfo(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::TDateTime ADate, int AScale);
	__property System::Types::TRect DisplayRect = {read=FDisplayRect};
	__property System::TDateTime Finish = {read=FFinishTime};
	__property System::TDateTime Start = {read=FStartTime};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEventLayoutInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxCalculateEventLayout : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
private:
	System::TDateTime FDate;
	int FLeft;
	int FRowHeight;
	int FTimeScale;
	int FTop;
	int FWidth;
	TcxEventLayoutInfo* __fastcall GetInfo(int AIndex);
	
protected:
	TcxSchedulerDayViewViewInfo* FViewInfo;
	virtual void __fastcall CalculateColCount(TcxEventLayoutInfo* AInfo);
	virtual void __fastcall CalculateColEnd(TcxEventLayoutInfo* AInfo);
	virtual void __fastcall CalculateColStart(TcxEventLayoutInfo* AInfo, int AIndex);
	TcxEventLayoutInfo* __fastcall CreateEventInfo(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	bool __fastcall Intersect(TcxEventLayoutInfo* AInfo1, TcxEventLayoutInfo* AInfo2);
	void __fastcall SetColCount(TcxEventLayoutInfo* AInfo);
	
public:
	HIDESBASE void __fastcall Add(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall Calculate(void);
	virtual void __fastcall Clear(void);
	void __fastcall SetParams(const System::TDateTime ADate, int ATimeScale, int ARowHeight, int ALeft, int ATop, int AWidth);
	__property System::TDateTime Date = {read=FDate, write=FDate};
	__property TcxEventLayoutInfo* Infos[int Index] = {read=GetInfo};
	__property int Left = {read=FLeft, nodefault};
	__property int RowHeight = {read=FRowHeight, nodefault};
	__property int TimeScale = {read=FTimeScale, nodefault};
	__property int Top = {read=FTop, nodefault};
	__property int Width = {read=FWidth, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxCalculateEventLayout(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxCalculateEventLayout(void) : System::Classes::TList() { }
	
};


enum TcxSchedulerTimeRulerPopupMenuItem : unsigned char { rpmiNewEvent, rpmiNewAllDayEvent, rpmiNewReccuringEvent, rpmi60min, rpmi30min, rpmi15min, rpmi10min, rpmi6min, rpmi5min };

typedef System::Set<TcxSchedulerTimeRulerPopupMenuItem, TcxSchedulerTimeRulerPopupMenuItem::rpmiNewEvent, TcxSchedulerTimeRulerPopupMenuItem::rpmi5min>  TcxSchedulerTimeRulerPopupMenuItems;

typedef void __fastcall (__closure *TcxSchedulerTimeRulerPopupMenuPopupEvent)(TcxSchedulerTimeRulerPopupMenu* Sender, Vcl::Menus::TPopupMenu* ABuiltInMenu, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerTimeRulerPopupMenuClickEvent)(TcxSchedulerTimeRulerPopupMenu* Sender, TcxSchedulerTimeRulerPopupMenuItem AItem, bool &AHandled);

class PASCALIMPLEMENTATION TcxSchedulerTimeRulerPopupMenu : public Cxschedulercustomcontrols::TcxSchedulerCustomContentPopupMenu
{
	typedef Cxschedulercustomcontrols::TcxSchedulerCustomContentPopupMenu inherited;
	
private:
	TcxSchedulerTimeRulerPopupMenuItems FItems;
	TcxSchedulerTimeRulerPopupMenuPopupEvent FOnPopup;
	TcxSchedulerTimeRulerPopupMenuClickEvent FOnClick;
	TcxSchedulerDayView* __fastcall GetDayView(void);
	
protected:
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	virtual bool __fastcall DoOnClick(int ACommand);
	virtual bool __fastcall DoOnPopup(void);
	virtual bool __fastcall IsValidCommand(int ACommand);
	__property TcxSchedulerDayView* DayView = {read=GetDayView};
	
public:
	__fastcall virtual TcxSchedulerTimeRulerPopupMenu(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Execute(TcxSchedulerTimeRulerPopupMenuItem AItem);
	Vcl::Menus::TMenuItem* __fastcall GetMenuItem(TcxSchedulerTimeRulerPopupMenuItem AItem);
	
__published:
	__property TcxSchedulerTimeRulerPopupMenuItems Items = {read=FItems, write=FItems, default=511};
	__property PopupMenu;
	__property UseBuiltInPopupMenu = {default=1};
	__property TcxSchedulerTimeRulerPopupMenuClickEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TcxSchedulerTimeRulerPopupMenuPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
public:
	/* TcxSchedulerPopupMenu.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeRulerPopupMenu(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxcsHeaderContainer = System::Int8(0x0);
static const System::Int8 cxcsSelectedHeaderContainer = System::Int8(0x1);
static const System::Int8 cxcsTimeLine = System::Int8(0x2);
static const System::Int8 cxcsTimeRuler = System::Int8(0x3);
static const System::Int8 cxcsMaxDayViewValue = System::Int8(0x3);
static const System::Int8 cxcsDayViewStyleFirst = System::Int8(0x0);
static const System::Int8 cxcsDayViewStyleLast = System::Int8(0x3);
extern PACKAGE int cxSchedulerAllDayEventContainerMaxLineCount;
}	/* namespace Cxschedulerdayview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERDAYVIEW)
using namespace Cxschedulerdayview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerdayviewHPP
