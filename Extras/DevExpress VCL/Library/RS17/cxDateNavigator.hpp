// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDateNavigator.pas' rev: 24.00 (Win32)

#ifndef CxdatenavigatorHPP
#define CxdatenavigatorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerDateNavigator.hpp>	// Pascal unit
#include <cxSchedulerDayView.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdatenavigator
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxInnerDateNavigator;
class DELPHICLASS TcxCustomDateNavigator;
class PASCALIMPLEMENTATION TcxInnerDateNavigator : public Cxschedulercustomcontrols::TcxCustomScheduler
{
	typedef Cxschedulercustomcontrols::TcxCustomScheduler inherited;
	
private:
	System::TDateTime FPrevDate;
	bool FPrevCopyDragDrop;
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxcontainer::TcxContainer* __fastcall GetControlContainer(void);
	HIDESBASE MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	
protected:
	int FSelAnchor;
	int FSelStart;
	TcxCustomDateNavigator* FContainer;
	virtual void __fastcall CalcLayout(void);
	DYNAMIC bool __fastcall CanDrag(int X, int Y);
	virtual bool __fastcall CanSelectPeriod(void);
	virtual void __fastcall CheckSplittersVisibilityChanging(void);
	DYNAMIC void __fastcall Click(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerCustomView* __fastcall CreateDefaultView(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerCustomDateNavigator* __fastcall CreateDateNavigator(void);
	virtual void __fastcall DateNavigatorSelectionChanged(void);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, const System::Types::TPoint &MousePos);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DragCanceled(void);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual Cxschedulercustomcontrols::TcxSchedulerShowDateHintEvent __fastcall GetOnShowDateHint(void);
	bool __fastcall HitAtDate(int X, int Y);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall SetSelection(int ADelta);
	void __fastcall SetSelectionDays(int ADate, bool ACheckEnd);
	__property TcxCustomDateNavigator* Container = {read=FContainer};
	
public:
	__fastcall virtual TcxInnerDateNavigator(System::Classes::TComponent* AOwner);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	DYNAMIC bool __fastcall CanFocus(void);
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property Cursor = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=0};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnEnter;
	__property OnExit;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnDblClick;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
public:
	/* TcxCustomScheduler.Destroy */ inline __fastcall virtual ~TcxInnerDateNavigator(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxInnerDateNavigator(HWND ParentWindow) : Cxschedulercustomcontrols::TcxCustomScheduler(ParentWindow) { }
	
private:
	void *__IcxContainerInnerControl;	/* Cxcontainer::IcxContainerInnerControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator Cxcontainer::_di_IcxContainerInnerControl()
	{
		Cxcontainer::_di_IcxContainerInnerControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontainer::IcxContainerInnerControl*(void) { return (Cxcontainer::IcxContainerInnerControl*)&__IcxContainerInnerControl; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxContainerInnerControl; }
	#endif
	
};


class PASCALIMPLEMENTATION TcxCustomDateNavigator : public Cxcontainer::TcxContainer
{
	typedef Cxcontainer::TcxContainer inherited;
	
private:
	TcxInnerDateNavigator* FInnerDateNavigator;
	bool FIsExitProcessing;
	int FLockUpdate;
	Cxschedulercustomcontrols::TcxCustomScheduler* FScheduler;
	Cxschedulercustomcontrols::TcxSchedulerShowDateHintEvent FOnShowDateHint;
	Cxschedulerstorage::TcxCustomSchedulerStorage* FStorage;
	bool FUnlimitedSelection;
	Cxdateutils::TDay __fastcall GetActualStartOfWeek(void);
	Cxcontrols::TcxControlBorderStyle __fastcall GetBorderStyle(void);
	int __fastcall GetColCount(void);
	Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawBackgroundEvent __fastcall GetCustomDrawBackground(void);
	Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawDayCaptionEvent __fastcall GetCustomDrawDayCaption(void);
	Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawDayNumberEvent __fastcall GetCustomDrawDayNumber(void);
	Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawContentEvent __fastcall GetCustomDrawContent(void);
	Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawHeaderEvent __fastcall GetCustomDrawHeader(void);
	System::TDateTime __fastcall GetDate(void);
	Cxschedulerdatenavigator::TcxSchedulerDateNavigator* __fastcall GetDateNavigator(void);
	Cxschedulerutils::TcxSchedulerDateList* __fastcall GetEventDays(void);
	System::TDateTime __fastcall GetFirstDate(void);
	Cxdateutils::TcxFirstWeekOfYear __fastcall GetFirstWeekOfYear(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	Cxschedulerdatenavigator::TcxSchedulerDateNavigatorHitTest* __fastcall GetHitTest(void);
	System::Uitypes::TColor __fastcall GetHolidayColor(void);
	System::TDateTime __fastcall GetLastDate(void);
	Cxschedulerdatenavigator::TcxSchedulerPeriodChangedEvent __fastcall GetPeriodChanged(void);
	System::TDateTime __fastcall GetRealFirstDate(void);
	System::TDateTime __fastcall GetRealLastDate(void);
	int __fastcall GetRowCount(void);
	Cxschedulerutils::TcxSchedulerDateList* __fastcall GetSelectedDays(void);
	Cxschedulerdatenavigator::TcxSchedulerPeriodChangedEvent __fastcall GetSelectionChanged(void);
	bool __fastcall GetSelectionIsWeeks(void);
	bool __fastcall GetSelectPeriod(void);
	bool __fastcall GetShowDatesContainingEventsInBold(void);
	bool __fastcall GetShowDatesContainingHolidaysInColor(void);
	bool __fastcall GetShowWeekNumbers(void);
	Cxschedulerutils::TcxStartOfWeek __fastcall GetStartOfWeek(void);
	Cxschedulerdatenavigator::TcxSchedulerDateNavigatorStyles* __fastcall GetStyles(void);
	HIDESBASE void __fastcall SetBorderStyle(Cxcontrols::TcxControlBorderStyle AValue);
	void __fastcall SetColCount(int AValue);
	void __fastcall SetCustomDrawBackground(Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawBackgroundEvent AValue);
	void __fastcall SetCustomDrawDayCaption(Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawDayCaptionEvent AValue);
	void __fastcall SetCustomDrawDayNumber(Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawDayNumberEvent AValue);
	void __fastcall SetCustomDrawContent(Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawContentEvent AValue);
	void __fastcall SetCustomDrawHeader(Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawHeaderEvent AValue);
	void __fastcall SetDate(System::TDateTime AValue);
	void __fastcall SetFirstDate(System::TDateTime AValue);
	void __fastcall SetFirstWeekOfYear(Cxdateutils::TcxFirstWeekOfYear AValue);
	HIDESBASE void __fastcall SetFont(Vcl::Graphics::TFont* AValue);
	void __fastcall SetHolidayColor(System::Uitypes::TColor AValue);
	void __fastcall SetPeriodChanged(Cxschedulerdatenavigator::TcxSchedulerPeriodChangedEvent AValue);
	void __fastcall SetRowCount(int AValue);
	void __fastcall SetScheduler(Cxschedulercustomcontrols::TcxCustomScheduler* AValue);
	void __fastcall SetSelectionChanged(Cxschedulerdatenavigator::TcxSchedulerPeriodChangedEvent AValue);
	void __fastcall SetSelectionIsWeeks(bool AValue);
	void __fastcall SetSelectPeriod(bool AValue);
	void __fastcall SetShowDatesContainingEventsInBold(bool AValue);
	void __fastcall SetShowDatesContainingHolidaysInColor(bool AValue);
	void __fastcall SetShowWeekNumbers(bool AValue);
	void __fastcall SetStartOfWeek(Cxschedulerutils::TcxStartOfWeek AValue);
	void __fastcall SetStorage(Cxschedulerstorage::TcxCustomSchedulerStorage* AValue);
	void __fastcall SetStyles(Cxschedulerdatenavigator::TcxSchedulerDateNavigatorStyles* AValue);
	void __fastcall SetUnlimitedSelection(bool AValue);
	
protected:
	DYNAMIC bool __fastcall CanDrag(int X, int Y);
	bool __fastcall CanSelectPeriod(void);
	virtual TcxInnerDateNavigator* __fastcall CreateInnerDateNavigator(void);
	virtual void __fastcall DateNavigatorSelectionChanged(void);
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetActualStorage(void);
	virtual void __fastcall Loaded(void);
	virtual bool __fastcall NeedsScrollBars(void);
	void __fastcall UpdateStorage(void);
	void __fastcall SchedulerStorageChanged(void);
	void __fastcall SchedulerChanged(void);
	void __fastcall SchedulerRemoved(void);
	virtual void __fastcall StorageChanged(System::TObject* Sender);
	virtual void __fastcall StorageRemoved(System::TObject* Sender);
	__property Cxcontrols::TcxControlBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, default=1};
	__property int ColCount = {read=GetColCount, write=SetColCount, default=1};
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigator* DateNavigator = {read=GetDateNavigator};
	__property DragMode = {default=1};
	__property Cxschedulerutils::TcxSchedulerDateList* EventDays = {read=GetEventDays};
	__property Cxdateutils::TcxFirstWeekOfYear FirstWeekOfYear = {read=GetFirstWeekOfYear, write=SetFirstWeekOfYear, default=0};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont};
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigatorHitTest* HitTest = {read=GetHitTest};
	__property System::Uitypes::TColor HolidayColor = {read=GetHolidayColor, write=SetHolidayColor, default=255};
	__property ParentFont = {default=0};
	__property int RowCount = {read=GetRowCount, write=SetRowCount, default=1};
	__property Cxschedulercustomcontrols::TcxCustomScheduler* Scheduler = {read=FScheduler, write=SetScheduler};
	__property Cxschedulerutils::TcxSchedulerDateList* SelectedDays = {read=GetSelectedDays};
	__property bool ShowDatesContainingEventsInBold = {read=GetShowDatesContainingEventsInBold, write=SetShowDatesContainingEventsInBold, default=1};
	__property bool ShowDatesContainingHolidaysInColor = {read=GetShowDatesContainingHolidaysInColor, write=SetShowDatesContainingHolidaysInColor, default=0};
	__property bool ShowWeekNumbers = {read=GetShowWeekNumbers, write=SetShowWeekNumbers, default=1};
	__property Cxschedulerutils::TcxStartOfWeek StartOfWeek = {read=GetStartOfWeek, write=SetStartOfWeek, default=0};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=FStorage, write=SetStorage};
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigatorStyles* Styles = {read=GetStyles, write=SetStyles};
	__property Cxschedulerdatenavigator::TcxSchedulerPeriodChangedEvent OnPeriodChanged = {read=GetPeriodChanged, write=SetPeriodChanged};
	__property Cxschedulerdatenavigator::TcxSchedulerPeriodChangedEvent OnSelectionChanged = {read=GetSelectionChanged, write=SetSelectionChanged};
	__property Cxschedulercustomcontrols::TcxSchedulerShowDateHintEvent OnShowDateHint = {read=FOnShowDateHint, write=FOnShowDateHint};
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawBackgroundEvent OnCustomDrawBackground = {read=GetCustomDrawBackground, write=SetCustomDrawBackground};
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawContentEvent OnCustomDrawContent = {read=GetCustomDrawContent, write=SetCustomDrawContent};
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawDayNumberEvent OnCustomDrawDayNumber = {read=GetCustomDrawDayNumber, write=SetCustomDrawDayNumber};
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawDayCaptionEvent OnCustomDrawDayCaption = {read=GetCustomDrawDayCaption, write=SetCustomDrawDayCaption};
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigatorCustomDrawHeaderEvent OnCustomDrawHeader = {read=GetCustomDrawHeader, write=SetCustomDrawHeader};
	
public:
	__fastcall virtual TcxCustomDateNavigator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomDateNavigator(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	System::Types::TRect __fastcall CalcSize(int AColCount, int ARowCount);
	void __fastcall LayoutChanged(void);
	virtual void __fastcall SetFocus(void);
	__property Cxdateutils::TDay ActualStartOfWeek = {read=GetActualStartOfWeek, nodefault};
	__property System::TDateTime Date = {read=GetDate, write=SetDate};
	__property System::TDateTime FirstDate = {read=GetFirstDate, write=SetFirstDate};
	__property TcxInnerDateNavigator* InnerDateNavigator = {read=FInnerDateNavigator};
	__property System::TDateTime LastDate = {read=GetLastDate};
	__property System::TDateTime RealFirstDate = {read=GetRealFirstDate};
	__property System::TDateTime RealLastDate = {read=GetRealLastDate};
	__property bool SelectionIsWeeks = {read=GetSelectionIsWeeks, write=SetSelectionIsWeeks, nodefault};
	__property bool SelectPeriod = {read=GetSelectPeriod, write=SetSelectPeriod, default=1};
	__property bool UnlimitedSelection = {read=FUnlimitedSelection, write=SetUnlimitedSelection, default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDateNavigator(HWND ParentWindow) : Cxcontainer::TcxContainer(ParentWindow) { }
	
private:
	void *__IcxExternalDateNavigatorListener;	/* Cxschedulercustomcontrols::IcxExternalDateNavigatorListener */
	void *__IcxSchedulerStorageListener;	/* Cxschedulerstorage::IcxSchedulerStorageListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {32293211-4D89-4383-A95C-23B95C3A783D}
	operator Cxschedulercustomcontrols::_di_IcxExternalDateNavigatorListener()
	{
		Cxschedulercustomcontrols::_di_IcxExternalDateNavigatorListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulercustomcontrols::IcxExternalDateNavigatorListener*(void) { return (Cxschedulercustomcontrols::IcxExternalDateNavigatorListener*)&__IcxExternalDateNavigatorListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {87E0EBF3-F68A-4A51-8EA3-850D3819FBAB}
	operator Cxschedulerstorage::_di_IcxSchedulerStorageListener()
	{
		Cxschedulerstorage::_di_IcxSchedulerStorageListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulerstorage::IcxSchedulerStorageListener*(void) { return (Cxschedulerstorage::IcxSchedulerStorageListener*)&__IcxSchedulerStorageListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxSchedulerStorageListener; }
	#endif
	
};


class DELPHICLASS TcxDateNavigator;
class PASCALIMPLEMENTATION TcxDateNavigator : public TcxCustomDateNavigator
{
	typedef TcxCustomDateNavigator inherited;
	
public:
	__property ColCount = {default=1};
	__property EventDays;
	__property HitTest;
	__property RowCount = {default=1};
	__property SelectedDays;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BorderStyle = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=1};
	__property Enabled = {default=1};
	__property FirstWeekOfYear = {default=0};
	__property Font;
	__property HolidayColor = {default=255};
	__property LookAndFeel;
	__property ParentFont = {default=0};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Scheduler;
	__property SelectPeriod = {default=1};
	__property ShowDatesContainingEventsInBold = {default=1};
	__property ShowDatesContainingHolidaysInColor = {default=0};
	__property ShowWeekNumbers = {default=1};
	__property StartOfWeek = {default=0};
	__property Storage;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property UnlimitedSelection = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnCustomDrawBackground;
	__property OnCustomDrawContent;
	__property OnCustomDrawDayCaption;
	__property OnCustomDrawDayNumber;
	__property OnCustomDrawHeader;
	__property OnPeriodChanged;
	__property OnSelectionChanged;
	__property OnShowDateHint;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomDateNavigator.Create */ inline __fastcall virtual TcxDateNavigator(System::Classes::TComponent* AOwner) : TcxCustomDateNavigator(AOwner) { }
	/* TcxCustomDateNavigator.Destroy */ inline __fastcall virtual ~TcxDateNavigator(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDateNavigator(HWND ParentWindow) : TcxCustomDateNavigator(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdatenavigator */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDATENAVIGATOR)
using namespace Cxdatenavigator;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdatenavigatorHPP
