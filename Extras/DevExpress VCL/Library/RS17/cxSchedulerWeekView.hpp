// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerWeekView.pas' rev: 24.00 (Win32)

#ifndef CxschedulerweekviewHPP
#define CxschedulerweekviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerweekview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerCustomWeekViewController;
class DELPHICLASS TcxSchedulerCustomWeekViewNavigation;
class DELPHICLASS TcxSchedulerCustomWeekView;
class PASCALIMPLEMENTATION TcxSchedulerCustomWeekViewController : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController inherited;
	
private:
	TcxSchedulerCustomWeekViewNavigation* __fastcall GetNavigation(void);
	HIDESBASE TcxSchedulerCustomWeekView* __fastcall GetView(void);
	
protected:
	virtual Cxschedulercustomcontrols::TcxDragEventHelper* __fastcall CreateDragEventHelper(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual Cxschedulercustomcontrols::TcxEventSizingHelper* __fastcall CreateResizeEventHelper(void);
	virtual System::TDateTime __fastcall GetDayHeaderDate(void);
	virtual bool __fastcall NeedShowDayHeaderHint(void);
	__property TcxSchedulerCustomWeekView* View = {read=GetView};
	
public:
	__property TcxSchedulerCustomWeekViewNavigation* Navigation = {read=GetNavigation};
public:
	/* TcxSchedulerViewController.Create */ inline __fastcall virtual TcxSchedulerCustomWeekViewController(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController(AOwner) { }
	/* TcxSchedulerViewController.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomWeekViewController(void) { }
	
};


class DELPHICLASS TcxCustomWeekViewDragEventHelper;
class PASCALIMPLEMENTATION TcxCustomWeekViewDragEventHelper : public Cxschedulercustomcontrols::TcxDragEventHelper
{
	typedef Cxschedulercustomcontrols::TcxDragEventHelper inherited;
	
protected:
	virtual void __fastcall UpdateViewClonesTime(void);
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxCustomWeekViewDragEventHelper(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulercustomcontrols::TcxDragEventHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomWeekViewDragEventHelper(void) { }
	
};


class DELPHICLASS TcxCustomWeekViewEventSizing;
class PASCALIMPLEMENTATION TcxCustomWeekViewEventSizing : public Cxschedulercustomcontrols::TcxEventSizingHelper
{
	typedef Cxschedulercustomcontrols::TcxEventSizingHelper inherited;
	
protected:
	virtual void __fastcall UpdateEventBounds(void);
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxCustomWeekViewEventSizing(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulercustomcontrols::TcxEventSizingHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomWeekViewEventSizing(void) { }
	
};


enum TcxSchedulerWeekViewDaysLayout : unsigned char { wdlTwoColumns, wdlOneColumn };

class PASCALIMPLEMENTATION TcxSchedulerCustomWeekView : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceView
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceView inherited;
	
private:
	bool FCompressWeekEnd;
	TcxSchedulerWeekViewDaysLayout FDaysLayout;
	bool FHideWeekEnd;
	bool FForceShowWeekEnd;
	HIDESBASE TcxSchedulerCustomWeekViewController* __fastcall GetController(void);
	int __fastcall GetScrollPos(const System::TDateTime ADatePos, bool ACheckBounds = true);
	bool __fastcall GetHideWeekEnd(void);
	int __fastcall GetWeekDayCount(void);
	void __fastcall SetCompressWeekEnd(const bool AValue);
	void __fastcall SetDaysLayout(TcxSchedulerWeekViewDaysLayout Value);
	void __fastcall SetHideWeekEnd(bool Value);
	int __fastcall GetWorkWeekDayCount(void);
	
protected:
	Cxschedulerutils::TcxSchedulerDateList* FWeeks;
	int __fastcall CheckDate(const System::TDateTime ADate);
	void __fastcall CheckWorkDays(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlPainter* __fastcall CreatePainter(void);
	virtual bool __fastcall GetCompressWeekEnd(void);
	Vcl::Forms::TScrollBarKind __fastcall GetDateScrollBarKind(void);
	virtual System::TDateTime __fastcall GetFirstVisibleDate(void);
	virtual System::TDateTime __fastcall GetLastVisibleDate(void);
	virtual int __fastcall GetMaxScrollPos(void);
	virtual int __fastcall GetMinScrollPos(void);
	virtual System::UnicodeString __fastcall GetScrollTimeHint(void);
	int __fastcall GetWeekCount(void);
	virtual Cxdateutils::TDay __fastcall GetStartOfWeek(void);
	virtual System::Types::TRect __fastcall GetViewContentRect(void);
	virtual void __fastcall InitEventBySelectedTime(Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool AllDay, bool ARecurrence, bool AInplaceEditing);
	virtual void __fastcall InitScrollBarsParameters(void);
	bool __fastcall IsWeekStartOnMonday(void);
	bool __fastcall IsWholeWeekShown(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	__property TcxSchedulerCustomWeekViewController* Controller = {read=GetController};
	__property bool CompressWeekEnd = {read=FCompressWeekEnd, write=SetCompressWeekEnd, default=1};
	__property TcxSchedulerWeekViewDaysLayout DaysLayout = {read=FDaysLayout, write=SetDaysLayout, default=0};
	__property bool HideWeekEnd = {read=GetHideWeekEnd, write=SetHideWeekEnd, default=0};
	__property int WeekCount = {read=GetWeekCount, nodefault};
	__property int WeekDayCount = {read=GetWeekDayCount, nodefault};
	
public:
	__fastcall virtual TcxSchedulerCustomWeekView(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerCustomWeekView(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property FirstVisibleDate = {default=0};
	__property LastVisibleDate = {default=0};
	__property StartOfWeek;
};


class PASCALIMPLEMENTATION TcxSchedulerCustomWeekViewNavigation : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation inherited;
	
private:
	bool __fastcall GetCompress(void);
	System::TDateTime __fastcall GetFirstVisibleDate(void);
	System::TDateTime __fastcall GetLastVisibleDate(void);
	TcxSchedulerCustomWeekView* __fastcall GetView(void);
	Cxschedulerutils::TcxSchedulerDateList* __fastcall GetWeeks(void);
	bool __fastcall IsWholeWeekAnyway(void);
	System::TDateTime __fastcall VisibleDaysRangeFinish(void);
	System::TDateTime __fastcall VisibleDaysRangeStart(void);
	
protected:
	System::Word FYear;
	System::Word FWeekOfYear;
	int FWeekIndex;
	System::Word FDayOfWeek;
	bool IsFirstWeek;
	bool IsLastWeek;
	Vcl::Forms::TScrollBarKind __fastcall DateScrollBarKind(void);
	System::TDateTime __fastcall GetWeekFinish(int AWeekIndex);
	System::TDateTime __fastcall GetWeekStart(int AWeekIndex, bool ConsiderShowWeekEnd);
	virtual void __fastcall GotoCornerCell(bool AGotoEnd);
	virtual void __fastcall GotoNextCellHorz(bool AGotoNext);
	virtual void __fastcall GotoNextCellVert(bool AGotoDown);
	virtual void __fastcall GotoNextPage(bool AGotoForward);
	bool __fastcall IsResourceNavigation(bool AGoToDown);
	
public:
	virtual void __fastcall KeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall ValidateSelection(System::TDateTime &ASelStart, System::TDateTime &ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	__property bool Compress = {read=GetCompress, nodefault};
	__property System::TDateTime FirstVisibleDate = {read=GetFirstVisibleDate};
	__property System::TDateTime LastVisibleDate = {read=GetLastVisibleDate};
	__property TcxSchedulerCustomWeekView* View = {read=GetView};
	__property Cxschedulerutils::TcxSchedulerDateList* Weeks = {read=GetWeeks};
public:
	/* TcxSchedulerViewNavigation.Create */ inline __fastcall TcxSchedulerCustomWeekViewNavigation(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomWeekViewNavigation(void) { }
	
};


class DELPHICLASS TcxSchedulerWeekView;
class DELPHICLASS TcxSchedulerWeekViewViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerWeekView : public TcxSchedulerCustomWeekView
{
	typedef TcxSchedulerCustomWeekView inherited;
	
private:
	HIDESBASE TcxSchedulerWeekViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxschedulercustomcontrols::TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo* __fastcall CreateViewInfo(void);
	virtual bool __fastcall GetCompressWeekEnd(void);
	__property TcxSchedulerWeekViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__property SelectedDays;
	__property WorkDays;
	__property WorkFinish = {default=0};
	__property WorkStart = {default=0};
	
__published:
	__property CanShow = {default=1};
	__property Active = {default=0};
	__property CompressWeekEnd = {default=1};
	__property DaysLayout = {default=0};
	__property GroupingKind = {default=0};
	__property HideWeekEnd = {default=0};
	__property ShowEndTime = {default=1};
	__property ShowTimeAsClock = {default=0};
public:
	/* TcxSchedulerCustomWeekView.Create */ inline __fastcall virtual TcxSchedulerWeekView(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner) : TcxSchedulerCustomWeekView(AOwner) { }
	/* TcxSchedulerCustomWeekView.Destroy */ inline __fastcall virtual ~TcxSchedulerWeekView(void) { }
	
};


class DELPHICLASS TcxSchedulerWeekViewNavigation;
class PASCALIMPLEMENTATION TcxSchedulerWeekViewNavigation : public TcxSchedulerCustomWeekViewNavigation
{
	typedef TcxSchedulerCustomWeekViewNavigation inherited;
	
private:
	HIDESBASE TcxSchedulerWeekViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall GotoNextCellHorz(bool AGotoNext);
	virtual void __fastcall GotoNextCellVert(bool AGotoDown);
	
public:
	virtual bool __fastcall ScrollResourcesEx(bool AGoForward, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	__property TcxSchedulerWeekViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerViewNavigation.Create */ inline __fastcall TcxSchedulerWeekViewNavigation(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView) : TcxSchedulerCustomWeekViewNavigation(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerWeekViewNavigation(void) { }
	
};


class DELPHICLASS TcxSchedulerWeeksView;
class DELPHICLASS TcxSchedulerWeeksViewViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerWeeksView : public TcxSchedulerCustomWeekView
{
	typedef TcxSchedulerCustomWeekView inherited;
	
private:
	HIDESBASE TcxSchedulerWeeksViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual Cxschedulercustomcontrols::TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo* __fastcall CreateViewInfo(void);
	virtual int __fastcall GetMaxScrollPos(void);
	virtual int __fastcall GetMinScrollPos(void);
	__property TcxSchedulerWeeksViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__property SelectedDays;
	__property WeekCount;
	__property WorkDays;
	__property WorkFinish = {default=0};
	__property WorkStart = {default=0};
	
__published:
	__property CanShow = {default=1};
	__property Active = {default=0};
	__property CompressWeekEnd = {default=1};
	__property GroupingKind = {default=0};
	__property HideWeekEnd = {default=0};
	__property ShowEndTime = {default=1};
	__property ShowTimeAsClock = {default=0};
public:
	/* TcxSchedulerCustomWeekView.Create */ inline __fastcall virtual TcxSchedulerWeeksView(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner) : TcxSchedulerCustomWeekView(AOwner) { }
	/* TcxSchedulerCustomWeekView.Destroy */ inline __fastcall virtual ~TcxSchedulerWeeksView(void) { }
	
};


class DELPHICLASS TcxSchedulerWeeksViewNavigation;
class PASCALIMPLEMENTATION TcxSchedulerWeeksViewNavigation : public TcxSchedulerCustomWeekViewNavigation
{
	typedef TcxSchedulerCustomWeekViewNavigation inherited;
	
private:
	HIDESBASE TcxSchedulerWeeksViewViewInfo* __fastcall GetViewInfo(void);
	bool __fastcall IsFirstDayOfWeek(int ADayIndex);
	bool __fastcall IsLastDayOfWeek(int ADayIndex);
	
protected:
	virtual void __fastcall GotoNextCellHorz(bool AGotoNext);
	virtual void __fastcall GotoNextCellVert(bool AGotoDown);
	bool __fastcall IsScrollResource(bool AGotoNext);
	
public:
	__property TcxSchedulerWeeksViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerViewNavigation.Create */ inline __fastcall TcxSchedulerWeeksViewNavigation(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView) : TcxSchedulerCustomWeekViewNavigation(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerWeeksViewNavigation(void) { }
	
};


class DELPHICLASS TcxSchedulerWeekViewEventCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerWeekViewEventCellViewInfo : public Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo inherited;
	
protected:
	virtual void __fastcall CalculateBorders(void);
	virtual void __fastcall CalculateCaptions(void);
	virtual void __fastcall CalculateEventTimeVisibility(void);
	virtual void __fastcall CalculateItemsLayout(void);
	virtual System::Types::TRect __fastcall GetEditingRect(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
public:
	/* TcxSchedulerEventCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerWeekViewEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData) : Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo(AViewData) { }
	/* TcxSchedulerEventCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerWeekViewEventCellViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerWeekViewViewInfo : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewViewInfo inherited;
	
private:
	Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* __fastcall GetDayCell(int ADay);
	int __fastcall GetDayCellCount(void);
	bool __fastcall GetRotateCaptions(void);
	HIDESBASE TcxSchedulerWeekView* __fastcall GetView(void);
	Cxschedulerutils::TcxSchedulerDateList* __fastcall GetWeeks(void);
	
protected:
	Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder* Builder;
	int FDayHeaderOffsetTop;
	int FHeaderOffsetLeft;
	System::Word FPrintedMonth;
	bool FPrintExactlyOneMonth;
	int FResourceHeaderWidth;
	int FRowCols;
	int FRowColsStart;
	int FRowColsStartDateOffset;
	int FWeekEndCells;
	virtual Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* __fastcall AddContentCell(const System::Types::TRect &ARect, const System::TDateTime AStart, const System::TDateTime AFinish, int AResourceIndex);
	void __fastcall AddDayCellEvent(Cxschedulercustomresourceview::TcxSchedulerEventPlace* APlace);
	bool __fastcall AddDayCellEventPlace(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int &AIndex, Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* AStartDay);
	Cxschedulercustomresourceview::TcxSchedulerWeekDayHeaderCellViewInfo* __fastcall AddWeekDayHeader(int AWeekDay, int ALeft, int ARight);
	virtual void __fastcall CalculateDaysLayout(void);
	virtual void __fastcall CalculateDaysLayoutForResource(const System::Types::TRect &ABounds, int AResourceIndex);
	void __fastcall CalculateEventsOrder(void);
	virtual void __fastcall CalculateEventsViewInfo(void);
	virtual void __fastcall CalculateGroupByDateForResource(const System::Types::TRect &ABounds, int AResourceIndex);
	virtual void __fastcall CalculateHeaderViewInfo(void);
	virtual void __fastcall CalculateMetrics(void);
	virtual void __fastcall CalculatePrintRowCols(void);
	virtual void __fastcall CalculateResourceHeadersAutoHeight(int AWidth);
	void __fastcall CalculateWeekDates(void);
	virtual void __fastcall CalculateWeekDisplayRectsHorz(const System::TDateTime AStartDate, int AResourceID, const System::Types::TRect &ABounds, bool AIsTopWeek, bool AIsLastWeek);
	virtual void __fastcall CalculateWeekDisplayRectsVert(const System::TDateTime AStartDate, int AResourceID, const System::Types::TRect &ABounds, Cxgraphics::TcxBorders AddBorders = Cxgraphics::TcxBorders() );
	void __fastcall CalculateWeekDisplayRectsVertEx(const System::TDateTime AStartDate, int AResourceID, const System::Types::TRect &ABounds, Cxgraphics::TcxBorders AddBorders = Cxgraphics::TcxBorders() );
	bool __fastcall CanEventVisible(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	bool __fastcall CanVisibleNextLine(Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* ADay, int ALine = 0xffffffff);
	virtual void __fastcall CheckHeaderBorders(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfoClass __fastcall ContentCellClass(void);
	void __fastcall CorrectWeekDay(int &AWeekDay);
	virtual Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* __fastcall CreateEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoContentNavigationButtonClick(Cxschedulercustomresourceview::TcxSchedulerContentNavigationButtonViewInfo* Sender);
	virtual void __fastcall DoMoreEventsButtonClick(Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo* Sender);
	virtual bool __fastcall GetCompressWeekEnd(void);
	void __fastcall GetEventInfo(int AColStart, int AColFinish, int &ALeft, int &ARight, System::TDateTime &AStart, System::TDateTime &AFinish, System::Types::TRect &AVisibleRect, Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* &AResource);
	virtual int __fastcall GetResourcesContentWidth(void);
	virtual System::Types::TSize __fastcall GetResourceImagesSize(void);
	virtual Vcl::Forms::TScrollBarKind __fastcall GetResourceScrollBarKind(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ATime, Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* AResource);
	virtual int __fastcall GetDayCellContentHeight(Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* ADay);
	virtual int __fastcall GetDayCellHeaderHeight(void);
	virtual bool __fastcall GetHideWeekEnd(void);
	virtual System::TDateTime __fastcall GetStartDate(int Index);
	virtual bool __fastcall IsCalculateHeaderFirst(void);
	bool __fastcall IsCellEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* ACell);
	bool __fastcall IsSingleLine(Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* ADay1, Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* ADay2);
	virtual bool __fastcall IsTimeSelected(System::TDateTime ATime, System::TObject* AResource);
	virtual bool __fastcall IsWeekStartOnMonday(void);
	virtual void __fastcall ProcessGroupByDate(void);
	virtual void __fastcall ProcessGroupByNone(void);
	virtual void __fastcall ProcessGroupByResource(void);
	__property bool CompressWeekEnd = {read=GetCompressWeekEnd, nodefault};
	__property int DayCellCount = {read=GetDayCellCount, nodefault};
	__property Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* DayCells[int ADay] = {read=GetDayCell};
	__property bool HideWeekEnd = {read=GetHideWeekEnd, nodefault};
	__property int RowColsStart = {read=FRowColsStart, nodefault};
	__property Cxschedulerutils::TcxSchedulerDateList* Weeks = {read=GetWeeks};
	__property int WeekEndCells = {read=FWeekEndCells, nodefault};
	
public:
	__fastcall virtual TcxSchedulerWeekViewViewInfo(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerWeekViewViewInfo(void);
	virtual void __fastcall ScrollVertical(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	__property bool PrintExactlyOneMonth = {read=FPrintExactlyOneMonth, nodefault};
	__property System::Word PrintedMonth = {read=FPrintedMonth, nodefault};
	__property int ResourceHeaderWidth = {read=FResourceHeaderWidth, nodefault};
	__property bool RotateCaptions = {read=GetRotateCaptions, nodefault};
	__property StartDates;
	__property TcxSchedulerWeekView* View = {read=GetView};
};


class DELPHICLASS TcxSchedulerWeeksViewEventCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerWeeksViewEventCellViewInfo : public TcxSchedulerWeekViewEventCellViewInfo
{
	typedef TcxSchedulerWeekViewEventCellViewInfo inherited;
	
protected:
	virtual bool __fastcall CanAutoHideStandardImages(void);
public:
	/* TcxSchedulerEventCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerWeeksViewEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData) : TcxSchedulerWeekViewEventCellViewInfo(AViewData) { }
	/* TcxSchedulerEventCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerWeeksViewEventCellViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerWeeksViewViewInfo : public TcxSchedulerWeekViewViewInfo
{
	typedef TcxSchedulerWeekViewViewInfo inherited;
	
private:
	HIDESBASE TcxSchedulerWeeksView* __fastcall GetView(void);
	
protected:
	int FContentOffset;
	virtual void __fastcall CalculateDaysLayoutForResource(const System::Types::TRect &ABounds, int AResourceIndex);
	virtual void __fastcall CalculateGroupByDateForResource(const System::Types::TRect &ABounds, int AResourceIndex);
	virtual void __fastcall CalculateHeaderViewInfo(void);
	virtual void __fastcall CalculateMetrics(void);
	virtual void __fastcall CheckHeaderBorders(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfoClass __fastcall ContentCellClass(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* __fastcall CreateEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData);
	virtual bool __fastcall GetCompressWeekEnd(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ATime, Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* AResource);
	virtual int __fastcall GetDayCellHeaderHeight(void);
	virtual bool __fastcall IsCalculateHeaderFirst(void);
	virtual bool __fastcall IsWeekStartOnMonday(void);
	virtual void __fastcall ProcessGroupByNone(void);
	virtual void __fastcall ProcessGroupByResource(void);
	
public:
	__property TcxSchedulerWeeksView* View = {read=GetView};
public:
	/* TcxSchedulerWeekViewViewInfo.Create */ inline __fastcall virtual TcxSchedulerWeeksViewViewInfo(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : TcxSchedulerWeekViewViewInfo(AOwner) { }
	/* TcxSchedulerWeekViewViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerWeeksViewViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerWeekViewPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerWeekViewPainter : public Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter inherited;
	
private:
	HIDESBASE TcxSchedulerWeekViewViewInfo* __fastcall GetViewInfo(void);
	
public:
	virtual void __fastcall Paint(void);
	__property TcxSchedulerWeekViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerCustomViewPainter.Create */ inline __fastcall virtual TcxSchedulerWeekViewPainter(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerWeekViewPainter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxschedulerweekview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERWEEKVIEW)
using namespace Cxschedulerweekview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerweekviewHPP
