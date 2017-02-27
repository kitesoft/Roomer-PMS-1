// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerYearView.pas' rev: 24.00 (Win64)

#ifndef CxscheduleryearviewHPP
#define CxscheduleryearviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxscheduleryearview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSchedulerYearViewController;
class PASCALIMPLEMENTATION TcxSchedulerYearViewController : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController inherited;
	
protected:
	virtual Cxschedulercustomcontrols::TcxDragEventHelper* __fastcall CreateDragEventHelper(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual Cxschedulercustomcontrols::TcxEventSizingHelper* __fastcall CreateResizeEventHelper(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TcxSchedulerViewController.Create */ inline __fastcall virtual TcxSchedulerYearViewController(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController(AOwner) { }
	/* TcxSchedulerViewController.Destroy */ inline __fastcall virtual ~TcxSchedulerYearViewController(void) { }
	
};


class DELPHICLASS TcxSchedulerYearViewHitTest;
class PASCALIMPLEMENTATION TcxSchedulerYearViewHitTest : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest inherited;
	
public:
	__property bool HitAtYear = {read=GetBitState, index=17, nodefault};
	__property bool HitAtMonth = {read=GetBitState, index=18, nodefault};
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerYearViewHitTest(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerYearViewHitTest(void) { }
	
};


__interface IcxSchedulerYearViewAdapter;
typedef System::DelphiInterface<IcxSchedulerYearViewAdapter> _di_IcxSchedulerYearViewAdapter;
__interface  INTERFACE_UUID("{7B39CB3C-256E-4269-9B24-5A59BC3D868D}") IcxSchedulerYearViewAdapter  : public System::IInterface 
{
	
public:
	virtual int __fastcall GetMonthCount(void) = 0 ;
	virtual int __fastcall GetFirstMonth(void) = 0 ;
	virtual bool __fastcall GetShowMonthHeaders(void) = 0 ;
	virtual bool __fastcall GetShowWeekDayHeaders(void) = 0 ;
	virtual int __fastcall GetStartDayIndex(void) = 0 ;
	virtual int __fastcall GetDayCountPerPage(void) = 0 ;
};

class DELPHICLASS TcxSchedulerYearViewPainter;
class DELPHICLASS TcxSchedulerYearViewViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerYearViewPainter : public Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter inherited;
	
private:
	HIDESBASE TcxSchedulerYearViewViewInfo* __fastcall GetViewInfo(void);
	
public:
	virtual void __fastcall Paint(void);
	__property TcxSchedulerYearViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerCustomViewPainter.Create */ inline __fastcall virtual TcxSchedulerYearViewPainter(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerYearViewPainter(void) { }
	
};


class DELPHICLASS TcxSchedulerYearViewEventCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerYearViewEventCellViewInfo : public Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo inherited;
	
protected:
	virtual void __fastcall CalculateBorders(void);
	virtual void __fastcall CalculateCaptions(void);
	virtual void __fastcall CalculateEventTimeVisibility(void);
	virtual bool __fastcall CanAutoHideStandardImages(void);
	virtual bool __fastcall GetForceShowClockInHeaderEvent(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
public:
	/* TcxSchedulerEventCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerYearViewEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData) : Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo(AViewData) { }
	/* TcxSchedulerEventCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerYearViewEventCellViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerYearViewContentCellViewInfo;
class DELPHICLASS TcxSchedulerYearView;
class DELPHICLASS TcxSchedulerMonthHeaderCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerYearViewViewInfo : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewViewInfo inherited;
	
private:
	int FAdapterFirstMonth;
	int FAdapterMonthCount;
	int __fastcall GetAdapterFirstMonth(void);
	int __fastcall GetAdapterMonthCount(void);
	TcxSchedulerYearViewContentCellViewInfo* __fastcall GetDaysCell(int AIndex);
	int __fastcall GetDaysCellCount(void);
	System::Types::TRect __fastcall GetMonthBounds(int AIndex);
	TcxSchedulerYearView* __fastcall GetYearView(void);
	
protected:
	Vcl::Graphics::TFont* FContentFont;
	Vcl::Graphics::TFont* FContentSmallFont;
	System::Classes::TList* FDayCells;
	int FDayTextHeight;
	Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* FMonthHeaderCells;
	int FMonthHeaderWidth;
	bool FShowMonthHeaders;
	int FStartDayIndex;
	int FMaxYearViewWeekDays;
	int FMaxEventsCount;
	System::Word FYear;
	_di_IcxSchedulerYearViewAdapter FYearViewExtraAdapter;
	int FRangeStart;
	int FRangeFinish;
	void __fastcall AddEventButtons(Cxschedulercustomresourceview::TcxSchedulerEventPlace* APlace);
	void __fastcall AddEventForCalculation(Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder* ABuilder, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall AddEventToYearView(Cxschedulercustomresourceview::TcxSchedulerEventPlace* APlace);
	TcxSchedulerMonthHeaderCellViewInfo* __fastcall AddMonthHeader(int AYear, int AMonth, const System::Types::TRect &ARect, int AFirstMonth = 0x0, int AMonthCount = 0xc);
	Cxschedulercustomresourceview::TcxSchedulerWeekDayHeaderCellViewInfo* __fastcall AddWeekDayHeader(int AWeekDay, System::Types::TRect &ARect);
	TcxSchedulerYearViewContentCellViewInfo* __fastcall AddYearViewContentCell(System::Types::TRect &ARect, System::TDate ADate, bool ASelected, Cxgraphics::TcxViewParams &AParams, int AColIndex);
	void __fastcall CalculateContentCellMonthParams(int AMonth, /* out */ System::Types::TRect &AMonthBounds, /* out */ System::TDate &AStartOfMonth, /* out */ int &AStartMonthColumn, /* out */ int &ADaysPerMonth);
	virtual void __fastcall CalculateContentCells(void);
	virtual void __fastcall CalculateContentNavigationButtons(void);
	virtual void __fastcall CalculateDaysHeader(void);
	virtual void __fastcall CalculateEventsViewInfo(void);
	virtual void __fastcall CalculateMetrics(void);
	void __fastcall CalculateMonthHeaderWidth(void);
	virtual void __fastcall CalculateMonthsHeader(void);
	void __fastcall CheckLayout(System::TDateTime ADate);
	virtual void __fastcall Clear(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfoClass __fastcall ContentCellClass(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* __fastcall CreateEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData);
	System::Word __fastcall GetPartOfTheYear(System::TDateTime ADate);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoContentNavigationButtonClick(Cxschedulercustomresourceview::TcxSchedulerContentNavigationButtonViewInfo* Sender);
	System::TDateTime __fastcall GetMonthColumnDate(System::TDateTime AStartOfMonth, int ADaysPerMonth, int AStartMonthColumn, int AColumn);
	Vcl::Graphics::TFont* __fastcall GetSmallFont(const Cxgraphics::TcxViewParams &AParams);
	bool __fastcall IsEventVisible(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall PrepareSmallContentFont(void);
	virtual int __fastcall GetFirstMonth(void);
	virtual int __fastcall GetMonthCountPerPage(void);
	__property int AdapterFirstMonth = {read=GetAdapterFirstMonth, write=FAdapterFirstMonth, nodefault};
	__property int AdapterMonthCount = {read=GetAdapterMonthCount, write=FAdapterMonthCount, nodefault};
	__property int FirstMonth = {read=GetFirstMonth, nodefault};
	__property int MonthCountPerPage = {read=GetMonthCountPerPage, nodefault};
	
public:
	__fastcall virtual TcxSchedulerYearViewViewInfo(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerYearViewViewInfo(void);
	virtual void __fastcall CalculateHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	void __fastcall UpdateSelection(void);
	__property int DaysCellCount = {read=GetDaysCellCount, nodefault};
	__property TcxSchedulerYearViewContentCellViewInfo* DaysCells[int AIndex] = {read=GetDaysCell};
	__property System::Types::TRect MonthBounds[int AIndex] = {read=GetMonthBounds};
	__property Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* MonthHeaderCells = {read=FMonthHeaderCells};
	__property TcxSchedulerYearView* View = {read=GetYearView};
	__property System::Word Year = {read=FYear, nodefault};
};


class DELPHICLASS TcxSchedulerYearViewNavigation;
class PASCALIMPLEMENTATION TcxSchedulerYearViewNavigation : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation inherited;
	
private:
	bool FCanChangeSelection;
	System::TDateTime FSaveSelFinish;
	System::TDateTime FSaveSelStart;
	TcxSchedulerYearView* __fastcall GetYearView(void);
	TcxSchedulerYearViewViewInfo* __fastcall GetYearViewInfo(void);
	
protected:
	TcxSchedulerYearViewContentCellViewInfo* __fastcall ContentCell(int AIndex);
	void __fastcall CorrectCurrentAnchor(void);
	virtual void __fastcall DoKeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall GotoCornerCell(bool AGotoEnd);
	virtual void __fastcall GotoNextCellHorz(bool AGotoNext);
	virtual void __fastcall GotoNextCellVert(bool AGoForward);
	virtual void __fastcall GotoNextPage(bool AGotoForward);
	
public:
	virtual void __fastcall KeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall ValidateSelection(System::TDateTime &ASelStart, System::TDateTime &ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	__property TcxSchedulerYearView* View = {read=GetYearView};
	__property TcxSchedulerYearViewViewInfo* ViewInfo = {read=GetYearViewInfo};
public:
	/* TcxSchedulerViewNavigation.Create */ inline __fastcall TcxSchedulerYearViewNavigation(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerYearViewNavigation(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerMonthHeaderCellViewInfo : public Cxschedulercustomresourceview::TcxSchedulerDayHeaderCellViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerDayHeaderCellViewInfo inherited;
	
private:
	int FFirstMonth;
	int FMonth;
	int FMonthCount;
	int FYear;
	void __fastcall SetFirstMonth(int AValue);
	void __fastcall SetMonth(int AValue);
	void __fastcall SetMonthCount(int AValue);
	void __fastcall SetYear(int AValue);
	
protected:
	int FColStart;
	virtual void __fastcall CalculateDisplayText(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	__property int FirstMonth = {read=FFirstMonth, write=SetFirstMonth, nodefault};
	__property int Month = {read=FMonth, write=SetMonth, nodefault};
	__property int MonthCount = {read=FMonthCount, write=SetMonthCount, nodefault};
	__property int Year = {read=FYear, write=SetYear, nodefault};
public:
	/* TcxSchedulerHeaderCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerMonthHeaderCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : Cxschedulercustomresourceview::TcxSchedulerDayHeaderCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerHeaderCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerMonthHeaderCellViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerYearViewContentCellViewInfo : public Cxschedulercustomresourceview::TcxSchedulerMonthDayContentCellViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerMonthDayContentCellViewInfo inherited;
	
protected:
	int FColIndex;
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
public:
	/* TcxSchedulerMonthDayContentCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerYearViewContentCellViewInfo(void) { }
	
public:
	/* TcxSchedulerContentCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerYearViewContentCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : Cxschedulercustomresourceview::TcxSchedulerMonthDayContentCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	
};


class DELPHICLASS TcxYearViewDragEventHelper;
class PASCALIMPLEMENTATION TcxYearViewDragEventHelper : public Cxschedulercustomcontrols::TcxDragEventHelper
{
	typedef Cxschedulercustomcontrols::TcxDragEventHelper inherited;
	
protected:
	virtual void __fastcall UpdateViewClonesTime(void);
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxYearViewDragEventHelper(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulercustomcontrols::TcxDragEventHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxYearViewDragEventHelper(void) { }
	
};


class DELPHICLASS TcxYearViewEventSizing;
class PASCALIMPLEMENTATION TcxYearViewEventSizing : public Cxschedulercustomcontrols::TcxEventSizingHelper
{
	typedef Cxschedulercustomcontrols::TcxEventSizingHelper inherited;
	
protected:
	virtual void __fastcall UpdateEventBounds(void);
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxYearViewEventSizing(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulercustomcontrols::TcxEventSizingHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxYearViewEventSizing(void) { }
	
};


typedef void __fastcall (__closure *TcxSchedulerYearViewGetUnusedContentStyleEvent)(TcxSchedulerYearView* Sender, int AYear, int AMonth, int ADayOfWeek, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxSchedulerYearViewGetMonthHeaderStyleEvent)(TcxSchedulerYearView* Sender, int AYear, int AMonth, Cxstyles::TcxStyle* &AStyle);

class DELPHICLASS TcxSchedulerYearViewStyles;
class PASCALIMPLEMENTATION TcxSchedulerYearViewStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	Cxschedulercustomcontrols::TcxCustomScheduler* FScheduler;
	TcxSchedulerYearView* FYearView;
	TcxSchedulerYearViewGetMonthHeaderStyleEvent FOnGetMonthHeaderStyle;
	TcxSchedulerYearViewGetUnusedContentStyleEvent FOnGetUnusedContentStyle;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual TcxSchedulerYearViewStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetMonthHeaderParams(int AYear, int AMonth);
	Cxgraphics::TcxViewParams __fastcall GetUnusedContentParams(int AYear, int AMonth, int ADayOfWeek);
	__property Cxschedulercustomcontrols::TcxCustomScheduler* Scheduler = {read=FScheduler};
	__property TcxSchedulerYearView* YearView = {read=FYearView};
	
__published:
	__property Cxstyles::TcxStyle* MonthHeader = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* UnusedContent = {read=GetValue, write=SetValue, index=1};
	__property TcxSchedulerYearViewGetMonthHeaderStyleEvent OnGetMonthHeaderStyle = {read=FOnGetMonthHeaderStyle, write=FOnGetMonthHeaderStyle};
	__property TcxSchedulerYearViewGetUnusedContentStyleEvent OnGetUnusedContentStyle = {read=FOnGetUnusedContentStyle, write=FOnGetUnusedContentStyle};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxSchedulerYearViewStyles(void) { }
	
};


class DELPHICLASS TcxSchedulerMonthHeaderPopupMenu;
class PASCALIMPLEMENTATION TcxSchedulerYearView : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceView
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceView inherited;
	
private:
	bool FAllDayEventsOnly;
	int FMaxSelectedDaysCount;
	TcxSchedulerMonthHeaderPopupMenu* FMonthHeaderPopupMenu;
	TcxSchedulerYearViewStyles* FStyles;
	int FScale;
	HIDESBASE TcxSchedulerYearViewHitTest* __fastcall GetHitTest(void);
	TcxSchedulerYearViewNavigation* __fastcall GetNavigation(void);
	HIDESBASE TcxSchedulerYearViewViewInfo* __fastcall GetViewInfo(void);
	System::Word __fastcall GetYear(void);
	void __fastcall SetAllDayEventsOnly(bool AValue);
	void __fastcall SetMaxSelectedDaysCount(int AValue);
	void __fastcall SetMonthHeaderPopupMenu(TcxSchedulerMonthHeaderPopupMenu* AValue);
	void __fastcall SetScale(int AValue);
	void __fastcall SetStyles(TcxSchedulerYearViewStyles* AValue);
	
protected:
	virtual void __fastcall CreateSubClasses(void);
	virtual Cxschedulercustomresourceview::TcxCustomResourceViewAdapter* __fastcall CreateViewAdapter(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual bool __fastcall CanDeactivateOnDateNavigatorSelectionChange(void);
	virtual bool __fastcall CanSelectPeriod(void);
	void __fastcall ChangeLayout(System::TDateTime ACurrentAnchor);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual TcxSchedulerMonthHeaderPopupMenu* __fastcall CreateMonthHeaderPopupMenu(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlPainter* __fastcall CreatePainter(void);
	virtual TcxSchedulerYearViewStyles* __fastcall CreateStyles(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo* __fastcall CreateViewInfo(void);
	virtual bool __fastcall DoShowPopupMenu(int X, int Y);
	virtual bool __fastcall GetCompressWeekEnd(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerGroupingKind __fastcall GetGroupingKind(void);
	virtual System::TDateTime __fastcall GetFirstVisibleDate(void);
	virtual System::TDateTime __fastcall GetLastVisibleDate(void);
	virtual int __fastcall GetScrollPos(void);
	virtual int __fastcall GetVisibleDaysRange(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual void __fastcall MakeEventVisible(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SelectedDaysChanged(void);
	virtual void __fastcall SetGroupingKind(Cxschedulercustomcontrols::TcxSchedulerGroupingKind AValue);
	__property TcxSchedulerYearViewNavigation* Navigation = {read=GetNavigation};
	__property TcxSchedulerYearViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerYearView(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxSchedulerYearViewHitTest* HitTest = {read=GetHitTest};
	__property System::Word Year = {read=GetYear, nodefault};
	
__published:
	__property Active = {default=0};
	__property bool AllDayEventsOnly = {read=FAllDayEventsOnly, write=SetAllDayEventsOnly, default=0};
	__property int MaxSelectedDaysCount = {read=FMaxSelectedDaysCount, write=SetMaxSelectedDaysCount, default=0};
	__property TcxSchedulerMonthHeaderPopupMenu* MonthHeaderPopupMenu = {read=FMonthHeaderPopupMenu, write=SetMonthHeaderPopupMenu};
	__property int Scale = {read=FScale, write=SetScale, default=12};
	__property TcxSchedulerYearViewStyles* Styles = {read=FStyles, write=SetStyles};
public:
	/* TcxSchedulerCustomResourceView.Destroy */ inline __fastcall virtual ~TcxSchedulerYearView(void) { }
	
};


class DELPHICLASS TcxSchedulerYearViewAdapter;
class PASCALIMPLEMENTATION TcxSchedulerYearViewAdapter : public Cxschedulercustomresourceview::TcxCustomResourceViewAdapter
{
	typedef Cxschedulercustomresourceview::TcxCustomResourceViewAdapter inherited;
	
private:
	System::TDateTime FPredefinedCurrentAnchor;
	
protected:
	HIDESBASE HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	HIDESBASE int __stdcall _AddRef(void);
	HIDESBASE int __stdcall _Release(void);
	virtual int __fastcall GetDayCountPerPage(void);
	virtual int __fastcall GetFirstMonth(void);
	virtual int __fastcall GetMonthCount(void);
	virtual bool __fastcall GetShowMonthHeaders(void);
	virtual bool __fastcall GetShowWeekDayHeaders(void);
	virtual int __fastcall GetStartDayIndex(void);
	__property System::TDateTime PredefinedCurrentAnchor = {read=FPredefinedCurrentAnchor, write=FPredefinedCurrentAnchor};
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerYearViewAdapter(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : Cxschedulercustomresourceview::TcxCustomResourceViewAdapter(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerYearViewAdapter(void) { }
	
private:
	void *__IcxSchedulerYearViewAdapter;	/* IcxSchedulerYearViewAdapter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7B39CB3C-256E-4269-9B24-5A59BC3D868D}
	operator _di_IcxSchedulerYearViewAdapter()
	{
		_di_IcxSchedulerYearViewAdapter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxSchedulerYearViewAdapter*(void) { return (IcxSchedulerYearViewAdapter*)&__IcxSchedulerYearViewAdapter; }
	#endif
	
};


enum TcxSchedulerMonthHeaderPopupMenuItem : unsigned char { mhpmiNewEvent, mhpmiNewAllDayEvent, mhpmiNewReccuringEvent, mhpmiFullYear, mhpmiHalfYear, mhpmiQuarter };

typedef System::Set<TcxSchedulerMonthHeaderPopupMenuItem, TcxSchedulerMonthHeaderPopupMenuItem::mhpmiNewEvent, TcxSchedulerMonthHeaderPopupMenuItem::mhpmiQuarter>  TcxSchedulerMonthHeaderPopupMenuItems;

typedef void __fastcall (__closure *TcxSchedulerMonthHeaderPopupMenuPopupEvent)(TcxSchedulerMonthHeaderPopupMenu* Sender, Vcl::Menus::TPopupMenu* ABuiltInMenu, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerMonthHeaderPopupMenuClickEvent)(TcxSchedulerMonthHeaderPopupMenu* Sender, TcxSchedulerMonthHeaderPopupMenuItem AItem, bool &AHandled);

class PASCALIMPLEMENTATION TcxSchedulerMonthHeaderPopupMenu : public Cxschedulercustomcontrols::TcxSchedulerCustomContentPopupMenu
{
	typedef Cxschedulercustomcontrols::TcxSchedulerCustomContentPopupMenu inherited;
	
private:
	TcxSchedulerMonthHeaderPopupMenuItems FItems;
	TcxSchedulerMonthHeaderPopupMenuPopupEvent FOnPopup;
	TcxSchedulerMonthHeaderPopupMenuClickEvent FOnClick;
	TcxSchedulerYearView* __fastcall GetYearView(void);
	
protected:
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	virtual bool __fastcall DoOnClick(int ACommand);
	virtual bool __fastcall DoOnPopup(void);
	virtual bool __fastcall IsValidCommand(int ACommand);
	__property TcxSchedulerYearView* YearView = {read=GetYearView};
	
public:
	__fastcall virtual TcxSchedulerMonthHeaderPopupMenu(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Execute(TcxSchedulerMonthHeaderPopupMenuItem AItem);
	Vcl::Menus::TMenuItem* __fastcall GetMenuItem(TcxSchedulerMonthHeaderPopupMenuItem AItem);
	
__published:
	__property TcxSchedulerMonthHeaderPopupMenuItems Items = {read=FItems, write=FItems, default=63};
	__property PopupMenu;
	__property UseBuiltInPopupMenu = {default=1};
	__property TcxSchedulerMonthHeaderPopupMenuClickEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TcxSchedulerMonthHeaderPopupMenuPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
public:
	/* TcxSchedulerPopupMenu.Destroy */ inline __fastcall virtual ~TcxSchedulerMonthHeaderPopupMenu(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxMaxSelectedDaysCount = System::Int8(0x14);
static const System::Int8 MaxYearViewWeekDays = System::Int8(0x25);
static const System::Int8 cxYearViewScrollCurrentYearPos = System::Int8(0xa);
static const System::Int8 cxYearViewScrollMaxPos = System::Int8(0x15);
static const System::Int8 cxYearViewScrollMinPos = System::Int8(0x0);
static const System::Int8 cxcsMonthHeader = System::Int8(0x0);
static const System::Int8 cxcsUnusedContent = System::Int8(0x1);
static const System::Int8 cxcsMaxYearViewStyle = System::Int8(0x1);
static const System::Int8 htcYear = System::Int8(0x11);
static const System::Int8 htcMonth = System::Int8(0x12);
}	/* namespace Cxscheduleryearview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERYEARVIEW)
using namespace Cxscheduleryearview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxscheduleryearviewHPP
