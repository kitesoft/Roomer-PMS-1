// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxScheduler.pas' rev: 24.00 (Win32)

#ifndef CxschedulerHPP
#define CxschedulerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <cxSchedulerDayView.hpp>	// Pascal unit
#include <cxSchedulerWeekView.hpp>	// Pascal unit
#include <cxSchedulerDateNavigator.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxSchedulerGanttView.hpp>	// Pascal unit
#include <cxSchedulerTimeGridView.hpp>	// Pascal unit
#include <cxSchedulerYearView.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxscheduler
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TcxSchedulerInitEventImages)(Cxschedulercustomcontrols::TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxschedulercustomresourceview::TcxSchedulerEventImages* AImages);

class DELPHICLASS TcxScheduler;
class PASCALIMPLEMENTATION TcxScheduler : public Cxschedulercustomcontrols::TcxCustomScheduler
{
	typedef Cxschedulercustomcontrols::TcxCustomScheduler inherited;
	
private:
	System::Classes::TNotifyEvent FDateNavigatorEvents;
	bool FIsSelectionValidated;
	Cxschedulerdayview::TcxSchedulerDayView* FViewDay;
	Cxschedulerganttview::TcxSchedulerGanttView* FViewGantt;
	Cxschedulertimegridview::TcxSchedulerTimeGridView* FViewTimeGrid;
	Cxschedulerweekview::TcxSchedulerWeekView* FViewWeek;
	Cxschedulerweekview::TcxSchedulerWeeksView* FViewWeeks;
	Cxscheduleryearview::TcxSchedulerYearView* FViewYear;
	Cxschedulercustomresourceview::TcxSchedulerCustomDrawBackgroundEvent FOnCustomDrawBackground;
	Cxschedulercustomresourceview::TcxSchedulerCustomDrawButtonEvent FOnCustomDrawButton;
	Cxschedulercustomresourceview::TcxSchedulerCustomDrawContentEvent FOnCustomDrawContent;
	Cxschedulercustomresourceview::TcxSchedulerCustomDrawDayHeaderEvent FOnCustomDrawDayHeader;
	Cxschedulercustomresourceview::TcxSchedulerCustomDrawEventEvent FOnCustomDrawEvent;
	Cxschedulercustomresourceview::TcxSchedulerCustomDrawGroupSeparatorEvent FOnCustomDrawGroupSeparator;
	Cxschedulercustomresourceview::TcxSchedulerCustomDrawNavigationButtonEvent FOnCustomDrawNavigationButton;
	Cxschedulercustomresourceview::TcxSchedulerCustomDrawResourceHeaderEvent FOnCustomDrawResourceHeader;
	TcxSchedulerInitEventImages FOnInitEventImages;
	System::Classes::TNotifyEvent FViewDayEvents;
	System::Classes::TNotifyEvent FViewGanttEvents;
	System::Classes::TNotifyEvent FViewTimeGridEvents;
	System::Classes::TNotifyEvent FViewYearEvents;
	Cxschedulerdatenavigator::TcxSchedulerDateNavigator* __fastcall GetDateNavigator(void);
	void __fastcall SetDateNavigator(Cxschedulerdatenavigator::TcxSchedulerDateNavigator* AValue);
	void __fastcall SetViewDay(Cxschedulerdayview::TcxSchedulerDayView* AValue);
	void __fastcall SetViewGantt(Cxschedulerganttview::TcxSchedulerGanttView* AValue);
	void __fastcall SetViewTimeGrid(Cxschedulertimegridview::TcxSchedulerTimeGridView* AValue);
	void __fastcall SetViewWeek(Cxschedulerweekview::TcxSchedulerWeekView* AValue);
	void __fastcall SetViewWeeks(Cxschedulerweekview::TcxSchedulerWeeksView* AValue);
	void __fastcall SetViewYear(Cxscheduleryearview::TcxSchedulerYearView* AValue);
	void __fastcall ReadSplittersData(System::Classes::TStream* AStream);
	void __fastcall WriteSplittersData(System::Classes::TStream* AStream);
	void __fastcall ReadStoredClientBounds(System::Classes::TStream* AStream);
	void __fastcall WriteStoredClientBounds(System::Classes::TStream* AStream);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DoCustomDrawBackground(Cxschedulercustomresourceview::TcxSchedulerBackgroundCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawButton(Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawContent(Cxschedulercustomresourceview::TcxSchedulerContentCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawDayHeader(Cxschedulercustomresourceview::TcxSchedulerDayHeaderCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawEvent(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawGroupSeparator(Cxschedulercustomresourceview::TcxSchedulerGroupSeparatorCellViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawNavigationButton(Cxschedulercustomresourceview::TcxSchedulerContentNavigationButtonViewInfo* AViewInfo, bool &ADone);
	virtual void __fastcall DoCustomDrawResourceHeader(Cxschedulercustomresourceview::TcxSchedulerHeaderCellViewInfo* AViewInfo, bool &ADone);
	bool __fastcall HasCustomDrawGroupSeparator(void);
	bool __fastcall HasCustomDrawResourceHeader(void);
	virtual void __fastcall DoInitEventImages(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxschedulercustomresourceview::TcxSchedulerEventImages* AImages);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	virtual bool __fastcall SupportEventImages(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual Cxschedulercustomcontrols::TcxSchedulerCustomDateNavigator* __fastcall CreateDateNavigator(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerCustomView* __fastcall CreateDefaultView(void);
	virtual Cxschedulerdayview::TcxSchedulerDayView* __fastcall CreateViewDay(void);
	virtual Cxschedulerganttview::TcxSchedulerGanttView* __fastcall CreateViewGantt(void);
	virtual Cxschedulertimegridview::TcxSchedulerTimeGridView* __fastcall CreateViewTimeGrid(void);
	virtual Cxschedulerweekview::TcxSchedulerWeekView* __fastcall CreateViewWeek(void);
	virtual Cxschedulerweekview::TcxSchedulerWeeksView* __fastcall CreateViewWeeks(void);
	virtual Cxscheduleryearview::TcxSchedulerYearView* __fastcall CreateViewYear(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DateNavigatorSelectionChanged(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerCustomView* __fastcall GetNextView(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	virtual void __fastcall SetCurrentView(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	virtual void __fastcall SynchronizeVisibleDays(void);
	virtual void __fastcall UpdateEventsCache(bool ACheckDaysInterval);
	bool __fastcall UpdateView(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	virtual void __fastcall ValidateSelection(Cxschedulerutils::TcxSchedulerDateList* ASelection);
	void __fastcall ValidateWeekDays(bool ASaveWeekCount = false);
	
public:
	virtual bool __fastcall GoToDate(System::TDateTime ADate)/* overload */;
	virtual bool __fastcall GoToDate(System::TDateTime ADate, Cxschedulercustomcontrols::TcxSchedulerViewMode AViewMode)/* overload */;
	virtual void __fastcall SelectDays(const System::TDateTime AStartDay, const System::TDateTime AFinishDay, bool AsDays = false)/* overload */;
	virtual void __fastcall SelectDays(Cxschedulerutils::TcxSchedulerDateList* ASelection, bool AsDays = false)/* overload */;
	virtual void __fastcall SelectDays(System::TDateTime const *ASelection, const int ASelection_Size, bool AsDays = false)/* overload */;
	void __fastcall SelectWorkDays(const System::TDateTime ADate);
	
__published:
	__property Cxschedulerdatenavigator::TcxSchedulerDateNavigator* DateNavigator = {read=GetDateNavigator, write=SetDateNavigator};
	__property Cxschedulerdayview::TcxSchedulerDayView* ViewDay = {read=FViewDay, write=SetViewDay};
	__property Cxschedulerganttview::TcxSchedulerGanttView* ViewGantt = {read=FViewGantt, write=SetViewGantt};
	__property Cxschedulertimegridview::TcxSchedulerTimeGridView* ViewTimeGrid = {read=FViewTimeGrid, write=SetViewTimeGrid};
	__property Cxschedulerweekview::TcxSchedulerWeekView* ViewWeek = {read=FViewWeek, write=SetViewWeek};
	__property Cxschedulerweekview::TcxSchedulerWeeksView* ViewWeeks = {read=FViewWeeks, write=SetViewWeeks};
	__property Cxscheduleryearview::TcxSchedulerYearView* ViewYear = {read=FViewYear, write=SetViewYear};
	__property Cxschedulercustomresourceview::TcxSchedulerCustomDrawBackgroundEvent OnCustomDrawBackground = {read=FOnCustomDrawBackground, write=FOnCustomDrawBackground};
	__property Cxschedulercustomresourceview::TcxSchedulerCustomDrawButtonEvent OnCustomDrawButton = {read=FOnCustomDrawButton, write=FOnCustomDrawButton};
	__property Cxschedulercustomresourceview::TcxSchedulerCustomDrawContentEvent OnCustomDrawContent = {read=FOnCustomDrawContent, write=FOnCustomDrawContent};
	__property Cxschedulercustomresourceview::TcxSchedulerCustomDrawDayHeaderEvent OnCustomDrawDayHeader = {read=FOnCustomDrawDayHeader, write=FOnCustomDrawDayHeader};
	__property Cxschedulercustomresourceview::TcxSchedulerCustomDrawEventEvent OnCustomDrawEvent = {read=FOnCustomDrawEvent, write=FOnCustomDrawEvent};
	__property Cxschedulercustomresourceview::TcxSchedulerCustomDrawGroupSeparatorEvent OnCustomDrawGroupSeparator = {read=FOnCustomDrawGroupSeparator, write=FOnCustomDrawGroupSeparator};
	__property Cxschedulercustomresourceview::TcxSchedulerCustomDrawResourceHeaderEvent OnCustomDrawResourceHeader = {read=FOnCustomDrawResourceHeader, write=FOnCustomDrawResourceHeader};
	__property TcxSchedulerInitEventImages OnInitEventImages = {read=FOnInitEventImages, write=FOnInitEventImages};
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BevelEdges = {default=15};
	__property BevelInner = {index=0, default=2};
	__property BevelOuter = {index=1, default=1};
	__property BevelKind = {default=0};
	__property BevelWidth = {default=1};
	__property BorderWidth = {default=0};
	__property BorderStyle = {default=1};
	__property ContentPopupMenu;
	__property Constraints;
	__property ControlBox;
	__property DialogsLookAndFeel;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=1};
	__property Enabled = {default=1};
	__property EventImages;
	__property EventOperations;
	__property EventPopupMenu;
	__property Font;
	__property LookAndFeel;
	__property OptionsBehavior;
	__property OptionsCustomize;
	__property OptionsView;
	__property ParentFont = {default=0};
	__property PopupMenu;
	__property ResourceNavigator;
	__property ShowHint;
	__property Storage;
	__property Styles;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnAfterDragEvent;
	__property OnAfterEditing;
	__property OnAfterSizingEvent;
	__property OnBeforeDeleting;
	__property OnBeforeDragEvent;
	__property OnBeforeEditing;
	__property OnBeforeSizingEvent;
	__property OnCanShowView;
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnEventSelectionChanged;
	__property OnFirstVisibleResourceChanged;
	__property OnGetEventDisplayText;
	__property OnGetEventEditProperties;
	__property OnGetEventHintText;
	__property OnInitEdit;
	__property OnIsWorkTime;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnLayoutChanged;
	__property OnMoreEventsButtonClick;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnNavigationButtonClick;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
	__property OnSelectionChanged;
	__property OnScaleScroll;
	__property OnShowDateHint;
	__property OnViewTypeChanged;
	__property System::Classes::TNotifyEvent DateNavigatorEvents = {read=FDateNavigatorEvents, write=FDateNavigatorEvents};
	__property System::Classes::TNotifyEvent ViewDayEvents = {read=FViewDayEvents, write=FViewDayEvents};
	__property System::Classes::TNotifyEvent ViewGanttEvents = {read=FViewGanttEvents, write=FViewGanttEvents};
	__property System::Classes::TNotifyEvent ViewTimeGridEvents = {read=FViewTimeGridEvents, write=FViewTimeGridEvents};
	__property System::Classes::TNotifyEvent ViewYearEvents = {read=FViewYearEvents, write=FViewYearEvents};
public:
	/* TcxCustomScheduler.Create */ inline __fastcall virtual TcxScheduler(System::Classes::TComponent* AOwner) : Cxschedulercustomcontrols::TcxCustomScheduler(AOwner) { }
	/* TcxCustomScheduler.Destroy */ inline __fastcall virtual ~TcxScheduler(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxScheduler(HWND ParentWindow) : Cxschedulercustomcontrols::TcxCustomScheduler(ParentWindow) { }
	
private:
	void *__IcxSchedulerEventImages;	/* Cxschedulercustomresourceview::IcxSchedulerEventImages */
	void *__IcxSchedulerCommonViewItemsPainter;	/* Cxschedulercustomresourceview::IcxSchedulerCommonViewItemsPainter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4C5A8F8B-5356-4D2B-9972-507A7D60954A}
	operator Cxschedulercustomresourceview::_di_IcxSchedulerEventImages()
	{
		Cxschedulercustomresourceview::_di_IcxSchedulerEventImages intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulercustomresourceview::IcxSchedulerEventImages*(void) { return (Cxschedulercustomresourceview::IcxSchedulerEventImages*)&__IcxSchedulerEventImages; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0702AB17-C2F1-479D-B809-C3B972F8A334}
	operator Cxschedulercustomresourceview::_di_IcxSchedulerCommonViewItemsPainter()
	{
		Cxschedulercustomresourceview::_di_IcxSchedulerCommonViewItemsPainter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulercustomresourceview::IcxSchedulerCommonViewItemsPainter*(void) { return (Cxschedulercustomresourceview::IcxSchedulerCommonViewItemsPainter*)&__IcxSchedulerCommonViewItemsPainter; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxSchedulerEventImages; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxscheduler */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULER)
using namespace Cxscheduler;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerHPP
