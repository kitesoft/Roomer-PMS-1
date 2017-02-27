// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerTimeGridView.pas' rev: 24.00 (Win32)

#ifndef CxschedulertimegridviewHPP
#define CxschedulertimegridviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerStrs.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <dxOffice11.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulertimegridview
{
//-- type declarations -------------------------------------------------------
enum TcxSchedulerTimeGridScaleUnit : unsigned char { suHour, suDay, suWeek, suMonth, suQuarter, suYear };

typedef System::Set<TcxSchedulerTimeGridScaleUnit, TcxSchedulerTimeGridScaleUnit::suHour, TcxSchedulerTimeGridScaleUnit::suYear>  TcxSchedulerTimeGridScaleUnits;

enum TcxSchedulerTimeGridScaleTextType : unsigned char { sttUnknown, sttShort, sttMiddle, sttLong };

class DELPHICLASS TcxTimeGridDragEventHelper;
class DELPHICLASS TcxSchedulerTimeGridViewHitTest;
class PASCALIMPLEMENTATION TcxTimeGridDragEventHelper : public Cxschedulercustomcontrols::TcxDragEventHelper
{
	typedef Cxschedulercustomcontrols::TcxDragEventHelper inherited;
	
private:
	HIDESBASE TcxSchedulerTimeGridViewHitTest* __fastcall GetHitTest(void);
	
protected:
	void __fastcall CorrectAllDayEventProperty(void);
	virtual bool __fastcall IsValidTime(void);
	virtual void __fastcall UpdateViewClonesTime(void);
	__property TcxSchedulerTimeGridViewHitTest* HitTest = {read=GetHitTest};
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxTimeGridDragEventHelper(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulercustomcontrols::TcxDragEventHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTimeGridDragEventHelper(void) { }
	
};


class DELPHICLASS TcxTimeGridEventSizing;
class DELPHICLASS TcxSchedulerTimeBuilder;
class PASCALIMPLEMENTATION TcxTimeGridEventSizing : public Cxschedulercustomcontrols::TcxEventSizingHelper
{
	typedef Cxschedulercustomcontrols::TcxEventSizingHelper inherited;
	
private:
	TcxSchedulerTimeBuilder* __fastcall GetTimeBuilder(void);
	HIDESBASE TcxSchedulerTimeGridViewHitTest* __fastcall GetHitTest(void);
	
protected:
	virtual bool __fastcall IsValidTime(void);
	virtual void __fastcall UpdateEventBounds(void);
	__property TcxSchedulerTimeGridViewHitTest* HitTest = {read=GetHitTest};
	__property TcxSchedulerTimeBuilder* TimeBuilder = {read=GetTimeBuilder};
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxTimeGridEventSizing(Cxschedulercustomcontrols::TcxCustomScheduler* AScheduler) : Cxschedulercustomcontrols::TcxEventSizingHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxTimeGridEventSizing(void) { }
	
};


class DELPHICLASS TcxSchedulerTimeGridViewController;
class DELPHICLASS TcxSchedulerTimeGridView;
class DELPHICLASS TcxSchedulerTimeGridViewViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewController : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewController inherited;
	
private:
	Vcl::Extctrls::TTimer* FTimer;
	HIDESBASE TcxSchedulerTimeGridViewHitTest* __fastcall GetHitTest(void);
	HIDESBASE TcxSchedulerTimeGridView* __fastcall GetView(void);
	TcxSchedulerTimeGridViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	System::Types::TPoint FPos;
	bool FIsEditingBeforeMouseDown;
	virtual Cxschedulercustomcontrols::TcxDragEventHelper* __fastcall CreateDragEventHelper(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual Cxschedulercustomcontrols::TcxEventSizingHelper* __fastcall CreateResizeEventHelper(void);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall CancelScroll(void);
	virtual void __fastcall CheckScrolling(const System::Types::TPoint &APos);
	virtual void __fastcall InitNavigatorScrollArea(void);
	virtual void __fastcall InitTimer(bool AllowStart, System::Uitypes::TScrollCode AScrollCode);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Scrolling(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SyncEventSelection(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall OnTimer(System::TObject* Sender);
	__property TcxSchedulerTimeGridViewHitTest* HitTest = {read=GetHitTest};
	__property Vcl::Extctrls::TTimer* Timer = {read=FTimer};
	__property TcxSchedulerTimeGridView* View = {read=GetView};
	__property TcxSchedulerTimeGridViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerTimeGridViewController(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerTimeGridViewController(void);
};


class DELPHICLASS TcxSchedulerTimeGridViewNavigation;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewNavigation : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation inherited;
	
private:
	TcxSchedulerTimeBuilder* __fastcall GetTimeBuilder(void);
	TcxSchedulerTimeGridView* __fastcall GetView(void);
	HIDESBASE TcxSchedulerTimeGridViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	__property TcxSchedulerTimeBuilder* TimeBuilder = {read=GetTimeBuilder};
	__property TcxSchedulerTimeGridView* View = {read=GetView};
	__property TcxSchedulerTimeGridViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual void __fastcall KeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	virtual void __fastcall ValidateSelection(System::TDateTime &ASelStart, System::TDateTime &ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
public:
	/* TcxSchedulerViewNavigation.Create */ inline __fastcall TcxSchedulerTimeGridViewNavigation(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewNavigation(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewNavigation(void) { }
	
};


typedef void __fastcall (__closure *TcxSchedulerGetScaleItemStyleEvent)(System::TObject* Sender, const System::TDateTime ADateTime, Cxstyles::TcxStyle* &AStyle);

class DELPHICLASS TcxSchedulerTimeGridViewStyles;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	Cxschedulercustomcontrols::TcxCustomScheduler* FScheduler;
	TcxSchedulerGetScaleItemStyleEvent FOnGetMajorScaleParams;
	TcxSchedulerGetScaleItemStyleEvent FOnGetMinorScaleParams;
	TcxSchedulerGetScaleItemStyleEvent FOnGetSelectionBarParams;
	TcxSchedulerTimeGridView* __fastcall GetTimeGrid(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual Cxgraphics::TcxViewParams __fastcall GetSelectionBarParamsEx(const System::TDateTime ADateTime, bool ASelected);
	bool __fastcall IsTimeSelected(const System::TDateTime ADateTime);
	
public:
	__fastcall virtual TcxSchedulerTimeGridViewStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetMajorScaleParams(const System::TDateTime ADateTime);
	Cxgraphics::TcxViewParams __fastcall GetMajorScaleUnitSeparatorParams(void);
	Cxgraphics::TcxViewParams __fastcall GetMinorScaleParams(const System::TDateTime ADateTime);
	Cxgraphics::TcxViewParams __fastcall GetSelectionBarParams(const System::TDateTime ADateTime);
	__property Cxschedulercustomcontrols::TcxCustomScheduler* Scheduler = {read=FScheduler};
	__property TcxSchedulerTimeGridView* TimeGrid = {read=GetTimeGrid};
	
__published:
	__property Cxstyles::TcxStyle* MajorScale = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* MajorScaleUnitSeparator = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* MinorScale = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* SelectionBar = {read=GetValue, write=SetValue, index=2};
	__property TcxSchedulerGetScaleItemStyleEvent OnGetMajorScaleParams = {read=FOnGetMajorScaleParams, write=FOnGetMajorScaleParams};
	__property TcxSchedulerGetScaleItemStyleEvent OnGetMinorScaleParams = {read=FOnGetMinorScaleParams, write=FOnGetMinorScaleParams};
	__property TcxSchedulerGetScaleItemStyleEvent OnGetSelectionBarParams = {read=FOnGetSelectionBarParams, write=FOnGetSelectionBarParams};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewStyles(void) { }
	
};


class DELPHICLASS TcxSchedulerTimeGridViewScales;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewScales : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FMajor;
	TcxSchedulerTimeGridScaleUnit FMajorUnit;
	int FMajorUnitSeparatorWidth;
	bool FMinor;
	TcxSchedulerTimeGridScaleUnit FMinorUnit;
	int FMinorUnitWidth;
	TcxSchedulerTimeGridView* FOwner;
	int FTimeStep;
	Cxschedulercustomcontrols::TcxCustomScheduler* __fastcall GetScheduler(void);
	void __fastcall SetMajor(bool AValue);
	void __fastcall SetMajorUnit(TcxSchedulerTimeGridScaleUnit AValue);
	void __fastcall SetMajorUnitSeparatorWidth(int AValue);
	void __fastcall SetMinor(bool AValue);
	void __fastcall SetMinorUnit(TcxSchedulerTimeGridScaleUnit AValue);
	void __fastcall SetMinorUnitWidth(int AValue);
	void __fastcall SetTimeStep(int AValue);
	
protected:
	virtual void __fastcall Changed(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxSchedulerTimeGridViewScales(TcxSchedulerTimeGridView* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Cxschedulercustomcontrols::TcxCustomScheduler* Scheduler = {read=GetScheduler};
	__property TcxSchedulerTimeGridView* TimeGrid = {read=FOwner};
	
__published:
	__property bool Major = {read=FMajor, write=SetMajor, default=1};
	__property TcxSchedulerTimeGridScaleUnit MajorUnit = {read=FMajorUnit, write=SetMajorUnit, default=1};
	__property int MajorUnitSeparatorWidth = {read=FMajorUnitSeparatorWidth, write=SetMajorUnitSeparatorWidth, default=5};
	__property bool Minor = {read=FMinor, write=SetMinor, default=1};
	__property TcxSchedulerTimeGridScaleUnit MinorUnit = {read=FMinorUnit, write=SetMinorUnit, default=0};
	__property int MinorUnitWidth = {read=FMinorUnitWidth, write=SetMinorUnitWidth, default=50};
	__property int TimeStep = {read=FTimeStep, write=SetTimeStep, default=30};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewScales(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewHitTest : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest inherited;
	
protected:
	bool __fastcall HitAtScale(void);
	
public:
	__property bool HitAtMajorScale = {read=GetBitState, index=17, nodefault};
	__property bool HitAtMajorSeparator = {read=GetBitState, index=18, nodefault};
	__property bool HitAtMinorScale = {read=GetBitState, index=19, nodefault};
	__property bool HitAtSelectionBar = {read=GetBitState, index=20, nodefault};
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerTimeGridViewHitTest(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewHitTest(void) { }
	
};


class DELPHICLASS TcxSchedulerTimeGridViewTreeBrowserSplitterController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewTreeBrowserSplitterController : public Cxschedulercustomcontrols::TcxSchedulerSplitterController
{
	typedef Cxschedulercustomcontrols::TcxSchedulerSplitterController inherited;
	
public:
	virtual bool __fastcall IsIntegralSizing(void);
	virtual void __fastcall SetSizeDelta(int ADelta);
public:
	/* TcxSchedulerSubControlController.Create */ inline __fastcall virtual TcxSchedulerTimeGridViewTreeBrowserSplitterController(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomcontrols::TcxSchedulerSplitterController(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewTreeBrowserSplitterController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerTimeGridViewTreeBrowserSplitter;
class DELPHICLASS TcxSchedulerTimeGridViewTreeBrowser;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewTreeBrowserSplitter : public Cxschedulercustomcontrols::TcxSchedulerSplitter
{
	typedef Cxschedulercustomcontrols::TcxSchedulerSplitter inherited;
	
private:
	TcxSchedulerTimeGridViewTreeBrowser* FBrowser;
	TcxSchedulerTimeGridView* __fastcall GetView(void);
	
protected:
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual void __fastcall DoPaint(void);
	virtual bool __fastcall IsSpecialPaint(void);
	
public:
	__property TcxSchedulerTimeGridViewTreeBrowser* Browser = {read=FBrowser};
	__property TcxSchedulerTimeGridView* View = {read=GetView};
public:
	/* TcxSchedulerSubControl.Create */ inline __fastcall virtual TcxSchedulerTimeGridViewTreeBrowserSplitter(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner) : Cxschedulercustomcontrols::TcxSchedulerSplitter(AOwner) { }
	/* TcxSchedulerSubControl.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewTreeBrowserSplitter(void) { }
	
};

#pragma pack(pop)

enum TcxSchedulerTreeBrowserDisplayMode : unsigned char { dmResources, dmEvents };

__interface IcxSchedulerTreeBrowserControl;
typedef System::DelphiInterface<IcxSchedulerTreeBrowserControl> _di_IcxSchedulerTreeBrowserControl;
__interface  INTERFACE_UUID("{192D59F3-FBB7-4097-B15C-B12C23921173}") IcxSchedulerTreeBrowserControl  : public System::IInterface 
{
	
public:
	virtual void __fastcall RefreshData(void) = 0 ;
	virtual void __fastcall SetContentLineHeight(int AHeight) = 0 ;
	virtual void __fastcall SetHeaderHeight(int AHeight) = 0 ;
	virtual void __fastcall SetMode(TcxSchedulerTreeBrowserDisplayMode AMode) = 0 ;
	virtual void __fastcall SetTopRecordIndex(int AIndex) = 0 ;
	virtual void __fastcall SetView(TcxSchedulerTimeGridView* AView) = 0 ;
};

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewTreeBrowser : public Cxschedulercustomcontrols::TcxSchedulerSubControl
{
	typedef Cxschedulercustomcontrols::TcxSchedulerSubControl inherited;
	
private:
	Cxcontrols::TcxControl* FInnerControl;
	TcxSchedulerTimeGridViewTreeBrowserSplitter* FSplitter;
	TcxSchedulerTimeGridView* FView;
	bool FVisible;
	bool __fastcall GetActuallyVisible(void);
	_di_IcxSchedulerTreeBrowserControl __fastcall GetBrowser(void);
	int __fastcall GetDisplayWidth(void);
	void __fastcall SetView(TcxSchedulerTimeGridView* AValue);
	HIDESBASE void __fastcall SetVisible(bool AValue);
	
protected:
	virtual void __fastcall BoundsChanged(void);
	virtual TcxSchedulerTimeGridViewTreeBrowserSplitter* __fastcall CreateSplitter(void);
	virtual void __fastcall CreateSubClasses(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall InitializeInnerControl(void);
	virtual void __fastcall Hide(void);
	virtual void __fastcall Show(void);
	void __fastcall SyncVisible(void);
	void __fastcall ValidateInnerControl(void);
	__property bool ActuallyVisible = {read=GetActuallyVisible, nodefault};
	__property _di_IcxSchedulerTreeBrowserControl Browser = {read=GetBrowser};
	
public:
	__property int DisplayWidth = {read=GetDisplayWidth, nodefault};
	__property Cxcontrols::TcxControl* InnerControl = {read=FInnerControl};
	__property TcxSchedulerTimeGridViewTreeBrowserSplitter* Splitter = {read=FSplitter};
	__property TcxSchedulerTimeGridView* View = {read=FView, write=SetView};
	
__published:
	__property bool Visible = {read=FVisible, write=SetVisible, default=0};
	__property Width = {default=250};
public:
	/* TcxSchedulerSubControl.Create */ inline __fastcall virtual TcxSchedulerTimeGridViewTreeBrowser(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner) : Cxschedulercustomcontrols::TcxSchedulerSubControl(AOwner) { }
	/* TcxSchedulerSubControl.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewTreeBrowser(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerTimeGridMajorScaleCell;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawMajorUnitEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerTimeGridMajorScaleCell* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerTimeGridMinorScaleCell;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawMinorUnitEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerTimeGridMinorScaleCell* AViewInfo, bool &ADone);

class DELPHICLASS TcxSchedulerTimeGridSelectionBarCell;
typedef void __fastcall (__closure *TcxSchedulerCustomDrawSelectionBarEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerTimeGridSelectionBarCell* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxSchedulerTimeGridViewGetUnitDisplayTextEvent)(TcxSchedulerTimeGridView* Sender, const System::TDateTime AStart, const System::TDateTime AFinish, TcxSchedulerTimeGridScaleTextType ATextType, System::UnicodeString &AText);

class PASCALIMPLEMENTATION TcxSchedulerTimeGridView : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceView
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceView inherited;
	
private:
	bool FEventDetailInfo;
	int FEventMaxLineCount;
	TcxSchedulerTimeGridViewScales* FScales;
	bool FShowMoreEventsButton;
	bool FShowResourceScrollBar;
	bool FSnapEventsToTimeSlots;
	TcxSchedulerTimeGridViewStyles* FStyles;
	TcxSchedulerTimeGridViewTreeBrowser* FTreeBrowser;
	System::TDateTime FVisibleFinish;
	System::TDateTime FVisibleStart;
	bool FWorkDaysOnly;
	bool FWorkTimeOnly;
	TcxSchedulerCustomDrawMajorUnitEvent FOnCustomDrawMajorUnit;
	TcxSchedulerCustomDrawMinorUnitEvent FOnCustomDrawMinorUnit;
	TcxSchedulerCustomDrawSelectionBarEvent FOnCustomDrawSelectionBar;
	TcxSchedulerTimeGridViewGetUnitDisplayTextEvent FOnGetMajorUnitDisplayText;
	TcxSchedulerTimeGridViewGetUnitDisplayTextEvent FOnGetMinorUnitDisplayText;
	HIDESBASE TcxSchedulerTimeGridViewHitTest* __fastcall GetHitTest(void);
	HIDESBASE TcxSchedulerTimeGridViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetEventDetailInfo(bool AValue);
	void __fastcall SetEventMaxLineCount(int AValue);
	void __fastcall SetScales(TcxSchedulerTimeGridViewScales* AValue);
	void __fastcall SetShowMoreEventsButton(bool AValue);
	void __fastcall SetShowResourceScrollBar(bool AValue);
	void __fastcall SetSnapEventsToTimeSlots(bool AValue);
	void __fastcall SetStyles(TcxSchedulerTimeGridViewStyles* AValue);
	void __fastcall SetTreeBrowser(TcxSchedulerTimeGridViewTreeBrowser* AValue);
	void __fastcall SetVisibleStart(System::TDateTime AValue);
	void __fastcall SetWorkDaysOnly(bool AValue);
	void __fastcall SetWorkTimeOnly(bool AValue);
	
protected:
	int FLockSelectionCounter;
	int FScrollPosition;
	bool FScrollUpdateLocked;
	TcxSchedulerTimeGridScaleTextType ScaleTextType;
	virtual bool __fastcall CanDeactivateOnDateNavigatorSelectionChange(void);
	virtual bool __fastcall CanSelectPeriod(void);
	virtual void __fastcall Changed(void);
	void __fastcall CheckRefresh(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlPainter* __fastcall CreatePainter(void);
	virtual TcxSchedulerTimeGridViewScales* __fastcall CreateScales(void);
	virtual TcxSchedulerTimeGridViewStyles* __fastcall CreateStyles(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual TcxSchedulerTimeGridViewTreeBrowser* __fastcall CreateTreeBrowser(void);
	virtual Cxschedulercustomresourceview::TcxCustomResourceViewAdapter* __fastcall CreateViewAdapter(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall DeactivateView(void);
	virtual void __fastcall DoDrawSelectionBarCell(TcxSchedulerTimeGridSelectionBarCell* AItem, bool &ADone);
	virtual void __fastcall DoDrawTimeLineCell(TcxSchedulerTimeGridMinorScaleCell* AItem, bool &ADone);
	virtual void __fastcall DoDrawTimeLineHeaderCell(TcxSchedulerTimeGridMajorScaleCell* AItem, bool &ADone);
	virtual void __fastcall DoGetMajorUnitDisplayText(const System::TDateTime AStart, const System::TDateTime AFinish, TcxSchedulerTimeGridScaleTextType ATextType, System::UnicodeString &AText);
	virtual void __fastcall DoGetMinorUnitDisplayText(const System::TDateTime AStart, const System::TDateTime AFinish, TcxSchedulerTimeGridScaleTextType ATextType, System::UnicodeString &AText);
	virtual void __fastcall DoLayoutChanged(void);
	virtual void __fastcall EventsListChanged(void);
	virtual bool __fastcall GetCompressWeekEnd(void);
	int __fastcall GetControlEventLineStart(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall GetEditWithSingleLineEditor(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual System::TDateTime __fastcall GetFirstVisibleDate(void);
	virtual System::TDateTime __fastcall GetFirstVisibleTime(void);
	virtual System::TDateTime __fastcall GetLastVisibleDate(void);
	virtual System::TDateTime __fastcall GetLastVisibleTime(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerGroupingKind __fastcall GetGroupingKind(void);
	virtual System::UnicodeString __fastcall GetScrollTimeHint(void);
	virtual bool __fastcall GetShowEventsWithoutResource(void);
	virtual System::TDateTime __fastcall GetTimeIncrement(void);
	virtual System::Types::TRect __fastcall GetViewContentRect(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	bool __fastcall IsSnapEventsToTimeSlots(void);
	virtual void __fastcall MakeEventVisible(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual void __fastcall MakeLineVisible(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall ScaleChanged(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall SelectedDaysChanged(void);
	HIDESBASE void __fastcall UpdateDateNavigatorSelection(void);
	virtual void __fastcall ValidateSelectionFinishTime(System::TDateTime &ADateTime);
	virtual void __fastcall VisibleChanged(void);
	__property TcxSchedulerTimeGridViewTreeBrowser* TreeBrowser = {read=FTreeBrowser, write=SetTreeBrowser};
	__property TcxSchedulerTimeGridViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerTimeGridView(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerTimeGridView(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	System::UnicodeString __fastcall GetMajorUnitDisplayText(const System::TDateTime AStart, const System::TDateTime AFinish, TcxSchedulerTimeGridScaleTextType ATextType);
	System::UnicodeString __fastcall GetMinorUnitDisplayText(const System::TDateTime AStart, const System::TDateTime AFinish, TcxSchedulerTimeGridScaleTextType ATextType);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TcxSchedulerTimeGridViewHitTest* HitTest = {read=GetHitTest};
	__property System::TDateTime VisibleFinish = {read=FVisibleFinish};
	__property System::TDateTime VisibleStart = {read=FVisibleStart, write=SetVisibleStart};
	
__published:
	__property Active = {default=0};
	__property EventImagesLayout = {default=0};
	__property int EventMaxLineCount = {read=FEventMaxLineCount, write=SetEventMaxLineCount, default=0};
	__property TcxSchedulerTimeGridViewScales* Scales = {read=FScales, write=SetScales};
	__property bool ShowMoreEventsButton = {read=FShowMoreEventsButton, write=SetShowMoreEventsButton, default=1};
	__property bool ShowResourceScrollBar = {read=FShowResourceScrollBar, write=SetShowResourceScrollBar, default=1};
	__property TcxSchedulerTimeGridViewStyles* Styles = {read=FStyles, write=SetStyles};
	__property bool EventDetailInfo = {read=FEventDetailInfo, write=SetEventDetailInfo, default=0};
	__property ShowTimeAsClock = {default=0};
	__property bool SnapEventsToTimeSlots = {read=FSnapEventsToTimeSlots, write=SetSnapEventsToTimeSlots, default=1};
	__property bool WorkDaysOnly = {read=FWorkDaysOnly, write=SetWorkDaysOnly, default=0};
	__property bool WorkTimeOnly = {read=FWorkTimeOnly, write=SetWorkTimeOnly, default=0};
	__property TcxSchedulerCustomDrawMajorUnitEvent OnCustomDrawMajorUnit = {read=FOnCustomDrawMajorUnit, write=FOnCustomDrawMajorUnit};
	__property TcxSchedulerCustomDrawMinorUnitEvent OnCustomDrawMinorUnit = {read=FOnCustomDrawMinorUnit, write=FOnCustomDrawMinorUnit};
	__property TcxSchedulerCustomDrawSelectionBarEvent OnCustomDrawSelectionBar = {read=FOnCustomDrawSelectionBar, write=FOnCustomDrawSelectionBar};
	__property TcxSchedulerTimeGridViewGetUnitDisplayTextEvent OnGetMajorUnitDisplayText = {read=FOnGetMajorUnitDisplayText, write=FOnGetMajorUnitDisplayText};
	__property TcxSchedulerTimeGridViewGetUnitDisplayTextEvent OnGetMinorUnitDisplayText = {read=FOnGetMinorUnitDisplayText, write=FOnGetMinorUnitDisplayText};
};


class PASCALIMPLEMENTATION TcxSchedulerTimeBuilder : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	bool CheckTime;
	bool CheckDays;
	bool CheckMidnight;
	TcxSchedulerTimeGridScaleUnit MajorUnit;
	TcxSchedulerTimeGridScaleUnit MinorUnit;
	int TimeScale;
	int TimeStep;
	System::TDateTime ScaleUnit;
	Cxdateutils::TDays WorkDays;
	System::TDateTime WorkFinish;
	System::TDateTime WorkStart;
	System::TDateTime __fastcall CalculateDateTime(const System::TDateTime ADateTime, int AInc);
	System::TDateTime __fastcall CalculateDateTimeDateTimeWithoutCheckWorkDays(const System::TDateTime ADateTime, int AInc);
	int __fastcall CalculateScaleUnit(const int AScaleUnit);
	void __fastcall CalculateWorkTime(bool AIsWorkTimeOnly, System::TDateTime &AWorkStart, System::TDateTime &AWorkFinish);
	void __fastcall CalculateWorkDays(bool AIsWorkDaysOnly, Cxdateutils::TDays &AWorkDays);
	System::TDateTime __fastcall GetScaleStep(void);
	System::TDateTime __fastcall RoundTime(const System::TDateTime ADateTime);
	void __fastcall ValidateMidnightForward(System::TDateTime &ADateTime);
	System::TDateTime __fastcall ValidateStartTime(const System::TDateTime ADateTime);
	bool __fastcall ValidateTime(System::TDateTime &ADateTime, bool AGoForward, int AInc = 0x1);
	void __fastcall ValidateUnits(TcxSchedulerTimeGridScaleUnit &AMajorUnit, TcxSchedulerTimeGridScaleUnit &AMinorUnit);
	
public:
	void __fastcall CalculateActualStart(System::TDateTime &ActualStart, System::TDateTime &AVisibleStart, int &AStartIndex);
	void __fastcall CheckWorkDays(System::TDateTime &ADateTime, bool AGoForward);
	System::TDateTime __fastcall Dec(const System::TDateTime ADateTime);
	System::TDateTime __fastcall Inc(const System::TDateTime ADateTime);
	void __fastcall Initialize(TcxSchedulerTimeGridView* AView, bool AWorkTimeOnly, bool AWorkDaysOnly);
	bool __fastcall IsPeriodChanged(const System::TDateTime AFirst, const System::TDateTime ANext);
	bool __fastcall TimeCorrected(System::TDateTime &AStart, System::TDateTime &AFinish, bool AGoForward = true);
	bool __fastcall TimeMode(void);
	void __fastcall ValidateVisibleStart(System::TDateTime &ADateTime);
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerTimeBuilder(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeBuilder(void) { }
	
};


class DELPHICLASS TcxSchedulerTimeGridViewEventCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewEventCellViewInfo : public Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo inherited;
	
protected:
	virtual void __fastcall CalculateCaptions(void);
	virtual void __fastcall CalculateDetailInfo(void);
	virtual void __fastcall CalculateEventTimeAsClockLayout(const System::Types::TRect &ABounds, const int ACaptionWidth, const int AImagesWidth, int &ALeft);
	virtual void __fastcall CalculateEventTimeVisibility(void);
	virtual System::Types::TRect __fastcall CalculateNonDetailEventImages(const int ACaptionWidth, /* out */ int &AImagesWidth);
	virtual void __fastcall CalculateItemsLayout(void);
	virtual void __fastcall CalculateShowTimeAsClock(void);
	virtual System::Types::TRect __fastcall GetEditingRect(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
public:
	/* TcxSchedulerEventCellViewInfo.Create */ inline __fastcall virtual TcxSchedulerTimeGridViewEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData) : Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo(AViewData) { }
	/* TcxSchedulerEventCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewEventCellViewInfo(void) { }
	
};


__interface IcxSchedulerTimeGridViewAdapter;
typedef System::DelphiInterface<IcxSchedulerTimeGridViewAdapter> _di_IcxSchedulerTimeGridViewAdapter;
__interface  INTERFACE_UUID("{A1808B72-237C-41D0-B864-BE8E24894F22}") IcxSchedulerTimeGridViewAdapter  : public System::IInterface 
{
	
public:
	virtual int __fastcall GetLineOffset(void) = 0 ;
	virtual bool __fastcall GetShowResourceHeaders(void) = 0 ;
	virtual bool __fastcall GetShowLinks(void) = 0 ;
	virtual bool __fastcall GetShowScales(void) = 0 ;
	virtual bool __fastcall GetWorkDaysOnly(void) = 0 ;
	virtual bool __fastcall GetWorkTimeOnly(void) = 0 ;
};

class DELPHICLASS TcxSchedulerTimeGridViewAdapter;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewAdapter : public Cxschedulercustomresourceview::TcxCustomResourceViewAdapter
{
	typedef Cxschedulercustomresourceview::TcxCustomResourceViewAdapter inherited;
	
protected:
	System::TDateTime FVisibleStart;
	int __fastcall GetLineOffset(void);
	virtual System::TDateTime __fastcall GetPrintRange(int Index);
	bool __fastcall GetShowLinks(void);
	bool __fastcall GetShowResourceHeaders(void);
	bool __fastcall GetShowScales(void);
	bool __fastcall GetWorkDaysOnly(void);
	bool __fastcall GetWorkTimeOnly(void);
	virtual void __fastcall Store(void);
	virtual void __fastcall Restore(void);
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerTimeGridViewAdapter(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : Cxschedulercustomresourceview::TcxCustomResourceViewAdapter(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewAdapter(void) { }
	
private:
	void *__IcxSchedulerTimeGridViewAdapter;	/* IcxSchedulerTimeGridViewAdapter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A1808B72-237C-41D0-B864-BE8E24894F22}
	operator _di_IcxSchedulerTimeGridViewAdapter()
	{
		_di_IcxSchedulerTimeGridViewAdapter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxSchedulerTimeGridViewAdapter*(void) { return (IcxSchedulerTimeGridViewAdapter*)&__IcxSchedulerTimeGridViewAdapter; }
	#endif
	
};


class DELPHICLASS TcxSchedulerTimeGridResourceScroll;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewViewInfo : public Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewViewInfo inherited;
	
private:
	Cxclasses::TcxObjectList* FResourceViewShift;
	void __fastcall CalculateResourceViewShifts(Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder* ABuilder);
	void __fastcall ClearMoreEventButtons(void);
	int __fastcall GetGroupCount(void);
	int __fastcall GetGroupLineCount(int AIndex);
	int __fastcall GetResourceHeight(void);
	TcxSchedulerTimeGridResourceScroll* __fastcall GetResourceViewShift(int Index);
	TcxSchedulerTimeGridView* __fastcall GetTimeGridView(void);
	int __fastcall GetVisibleLineCount(int AResourceIndex);
	void __fastcall PrepareMoreEventButtons(void);
	void __fastcall CalculateMajorScale(void);
	void __fastcall CalculateMinorScale(void);
	void __fastcall CalculateSelectionBar(void);
	
protected:
	System::TDateTime FActualStartTime;
	int FColumnCount;
	int FColumnWidth;
	int FEventMinSize;
	int FEventRowHeight;
	int FFirstVisibleIndex;
	System::TDateTime FLastVisibleTime;
	int FLineOffset;
	int FMajorScaleHeight;
	TcxSchedulerTimeGridScaleTextType FMajorTextType;
	int FMinorScaleHeight;
	TcxSchedulerTimeGridScaleTextType FMinorTextType;
	bool FPrintResourceHeaders;
	bool FPrintScales;
	int FResourceHeaderWidth;
	bool FResourceViewShiftChanged;
	TcxSchedulerTimeGridViewScales* FScales;
	System::Types::TRect FScalesBounds;
	int FScalesHeight;
	System::TDateTime FScaleUnit;
	int FSelectionBarHeight;
	int FSeparatorWidth;
	bool FShowLinks;
	TcxSchedulerTimeBuilder* FTimeBuilder;
	Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* FTimeLineCells;
	int FVisibleColumnCount;
	bool FWorkTimeOnly;
	bool FWorkDaysOnly;
	virtual void __fastcall AddEventForCalculation(Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder* ABuilder, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int AResourceIndex);
	Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* __fastcall AddEventViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventPlace* APlace, int AResourceIndex, const System::TDateTime AStart, const System::TDateTime AFinish);
	virtual void __fastcall AddMajorScaleCell(const System::Types::TRect &ABounds, const System::TDateTime AStart, const System::TDateTime AFinish);
	void __fastcall AddMajorSeparator(int &ALeft);
	virtual void __fastcall AddMinorScaleCell(const System::Types::TRect &ABounds, const System::TDateTime AStart, const System::TDateTime AFinish);
	virtual TcxSchedulerTimeGridSelectionBarCell* __fastcall AddSelectionBarCell(const System::Types::TRect &ABounds, const System::TDateTime AStart, const System::TDateTime AFinish);
	void __fastcall AddTimeLineItem(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass AClass, const System::Types::TRect &ABounds, System::Byte AType, const System::TDateTime AStart, const System::TDateTime AFinish, const Cxgraphics::TcxViewParams &AViewParams, void *Instance);
	void __fastcall AdjustTextType(void);
	virtual void __fastcall AfterCalculate(void);
	virtual void __fastcall CalculateContentCells(void);
	void __fastcall CalculateEventPosition(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int AColIndex, /* out */ int &AStartX, /* out */ int &AFinishX, /* out */ System::TDateTime &AStart, /* out */ System::TDateTime &AFinish);
	virtual void __fastcall CalculateEvents(void);
	virtual void __fastcall CalculateMetrics(void);
	void __fastcall CalculateResourceBounds(void);
	virtual void __fastcall CalculateResourceHeaderCells(void);
	virtual void __fastcall CalculateResourceHeadersAutoHeight(int AWidth);
	void __fastcall CalculateResourceTopBottom(int AResourceIndex, System::Types::TRect &ABounds);
	virtual void __fastcall CalculateScales(void);
	void __fastcall CalculateScalesHeight(void);
	virtual void __fastcall CheckEventVisibility(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* ACell, int AIndex);
	virtual System::TDateTime __fastcall CheckFinishTime(const System::TDateTime ATime, TcxSchedulerTimeGridScaleUnit AUnit);
	virtual void __fastcall Clear(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* __fastcall CreateEventCellViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventViewData* AViewData);
	virtual Cxschedulercustomresourceview::TcxSchedulerEventLayoutBuilder* __fastcall CreateLayoutBuilder(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall DoContentNavigationButtonClick(Cxschedulercustomresourceview::TcxSchedulerContentNavigationButtonViewInfo* Sender);
	void __fastcall DoResourceVerticalScroll(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall DoTimeGridMoreEventsButtonClick(Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo* Sender);
	void __fastcall InitializeBrowser(void);
	virtual bool __fastcall IsGroup(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	bool __fastcall IsColumnEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int AColumnIndex);
	virtual bool __fastcall IsEventVisible(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	bool __fastcall IsMinorUnitBreak(int AColumn);
	virtual bool __fastcall IsMilestone(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual int __fastcall GetActualPos(const int APos, const System::TDateTime ATime, const System::TDateTime AStart, const System::TDateTime AFinish);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ATime, Cxschedulercustomresourceview::TcxSchedulerResourceViewInfo* AResource);
	System::Types::TRect __fastcall GetEventClipRect(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo);
	virtual Cxschedulercustomcontrols::TcxSchedulerGroupingKind __fastcall GetGroupingKind(void);
	virtual int __fastcall GetIndentBetweenLines(void);
	void __fastcall GetItemInfo(int AIndex1, int AIndex2, int ATop, int AHeight, System::Types::TRect &ABounds, System::TDateTime &AStart, System::TDateTime &AFinish);
	virtual bool __fastcall GetNeedShowCurrentTime(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfoClass __fastcall GetMoreEventButtonClass(void);
	int __fastcall GetResourceScrollBarMax(int I);
	virtual System::Types::TSize __fastcall GetResourceImagesSize(void);
	virtual int __fastcall GetResourcesContentWidth(void);
	virtual Vcl::Forms::TScrollBarKind __fastcall GetResourceScrollBarKind(void);
	virtual System::TDateTime __fastcall GetScaleUnit(void);
	virtual bool __fastcall GetShowEventsWithoutResource(void);
	Vcl::Graphics::TFont* __fastcall GetStyleFont(Cxstyles::TcxStyle* AStyle);
	virtual Cxgraphics::TcxViewParams __fastcall GetTimeLineParams(void);
	virtual void __fastcall MakeTimeVisible(const System::TDateTime ATime);
	int __fastcall MeasureFontHeight(Cxstyles::TcxStyle* AStyle, int AHeight, Cxgraphics::TcxBorders Borders);
	void __fastcall Realign(Cxschedulercustomresourceview::TcxSchedulerEventPlace* APlace);
	virtual void __fastcall ReturnVisibleInterval(System::TDateTime &AStart, System::TDateTime &AEnd);
	void __fastcall RestoreScrollInfo(void);
	void __fastcall SetResourceScrollBarInfo(void);
	void __fastcall StoreScrollInfo(void);
	void __fastcall ValidateStartTime(void);
	
public:
	__fastcall virtual TcxSchedulerTimeGridViewViewInfo(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerTimeGridViewViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CalculateHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	void __fastcall ChangeResourceShift(int AResourceIndex, int ADelta);
	virtual bool __fastcall IsEventExpanded(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	__property System::TDateTime ActualStartTime = {read=FActualStartTime};
	__property int ColumnCount = {read=FColumnCount, nodefault};
	__property int ColumnWidth = {read=FColumnWidth, nodefault};
	__property int FirstVisibleIndex = {read=FFirstVisibleIndex, nodefault};
	__property int IndentBetweenLines = {read=GetIndentBetweenLines, nodefault};
	__property int GroupCount = {read=GetGroupCount, nodefault};
	__property int GroupLineCount[int Index] = {read=GetGroupLineCount};
	__property TcxSchedulerTimeGridScaleTextType MajorTextType = {read=FMajorTextType, nodefault};
	__property TcxSchedulerTimeGridScaleTextType MinorTextType = {read=FMinorTextType, nodefault};
	__property TcxSchedulerTimeGridViewScales* Scales = {read=FScales};
	__property int ScalesHeight = {read=FScalesHeight, nodefault};
	__property System::TDateTime ScaleUnit = {read=FScaleUnit};
	__property TcxSchedulerTimeBuilder* TimeBuilder = {read=FTimeBuilder};
	__property Cxschedulercustomresourceview::TcxSchedulerViewInfoCellList* TimeLineCells = {read=FTimeLineCells};
	__property int ResourceHeaderWidth = {read=FResourceHeaderWidth, nodefault};
	__property TcxSchedulerTimeGridResourceScroll* ResourceViewShift[int Index] = {read=GetResourceViewShift};
	__property Cxclasses::TcxObjectList* ResourceViewShiftList = {read=FResourceViewShift};
	__property TcxSchedulerTimeGridView* View = {read=GetTimeGridView};
	__property int VisibleColumnCount = {read=FVisibleColumnCount, nodefault};
	__property int VisibleLineCount[int Index] = {read=GetVisibleLineCount};
	__property bool WorkDaysOnly = {read=FWorkDaysOnly, nodefault};
	__property bool WorkTimeOnly = {read=FWorkTimeOnly, nodefault};
};


class DELPHICLASS TcxSchedulerTimeGridScaleCell;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridScaleCell : public Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem inherited;
	
private:
	System::Classes::TAlignment FAlignHorz;
	Cxclasses::TcxAlignmentVert FAlignVert;
	System::Uitypes::TColor FBorderColor;
	
protected:
	System::TDateTime FTimeFinish;
	int ItemType;
	__property System::Classes::TAlignment AlignHorz = {read=FAlignHorz, write=FAlignHorz, nodefault};
	__property Cxclasses::TcxAlignmentVert AlignVert = {read=FAlignVert, write=FAlignVert, nodefault};
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property System::TDateTime TimeFinish = {read=FTimeFinish};
	__property System::TDateTime TimeStart = {read=FDateTime};
	
public:
	__fastcall virtual TcxSchedulerTimeGridScaleCell(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams);
public:
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridScaleCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerTimeGridMinorScaleCell : public TcxSchedulerTimeGridScaleCell
{
	typedef TcxSchedulerTimeGridScaleCell inherited;
	
protected:
	bool FHideDisplayText;
	System::Types::TRect FTextBounds;
	virtual void __fastcall Calculate(void);
	virtual void __fastcall DoDraw(void);
	void __fastcall DrawContent(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	__property AlignHorz;
	__property AlignVert;
	__property BorderColor;
	__property DisplayText = {default=0};
	__property TimeFinish = {default=0};
	__property TimeStart = {default=0};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
public:
	/* TcxSchedulerTimeGridScaleCell.Create */ inline __fastcall virtual TcxSchedulerTimeGridMinorScaleCell(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerTimeGridScaleCell(APainter, ABounds, AVisibleRect, AViewParams) { }
	
public:
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridMinorScaleCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerTimeGridMajorScaleCell : public TcxSchedulerTimeGridMinorScaleCell
{
	typedef TcxSchedulerTimeGridMinorScaleCell inherited;
	
protected:
	int FRightIndent;
	virtual void __fastcall Calculate(void);
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	__property DisplayText = {default=0};
	__property bool HideDisplayText = {read=FHideDisplayText, write=FHideDisplayText, nodefault};
	__property int RightIndent = {read=FRightIndent, nodefault};
public:
	/* TcxSchedulerTimeGridScaleCell.Create */ inline __fastcall virtual TcxSchedulerTimeGridMajorScaleCell(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerTimeGridMinorScaleCell(APainter, ABounds, AVisibleRect, AViewParams) { }
	
public:
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridMajorScaleCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerTimeGridSelectionBarCell : public TcxSchedulerTimeGridMinorScaleCell
{
	typedef TcxSchedulerTimeGridMinorScaleCell inherited;
	
protected:
	bool FIsCurrentTimeCell;
	bool FSelected;
	bool FShowCurrentTime;
	System::Types::TRect FTimeLineRect;
	int FViewHeight;
	virtual void __fastcall Calculate(void);
	void __fastcall CalculateTimeLineParams(bool ANeedShowCurrentTime);
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	__property int ViewHeight = {read=FViewHeight, nodefault};
	
public:
	__property bool IsCurrentTimeCell = {read=FIsCurrentTimeCell, nodefault};
	__property bool Selected = {read=FSelected, nodefault};
	__property bool ShowCurrentTime = {read=FShowCurrentTime, nodefault};
	__property System::Types::TRect TimeLineRect = {read=FTimeLineRect};
public:
	/* TcxSchedulerTimeGridScaleCell.Create */ inline __fastcall virtual TcxSchedulerTimeGridSelectionBarCell(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : TcxSchedulerTimeGridMinorScaleCell(APainter, ABounds, AVisibleRect, AViewParams) { }
	
public:
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridSelectionBarCell(void) { }
	
};


class DELPHICLASS TcxSchedulerMajorSeparatorCellViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerMajorSeparatorCellViewInfo : public Cxschedulercustomresourceview::TcxSchedulerGroupSeparatorCellViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerGroupSeparatorCellViewInfo inherited;
	
protected:
	System::Types::TRect FContentBounds;
	virtual void __fastcall DoDraw(void);
	virtual void __fastcall InitHitTest(Cxschedulercustomresourceview::TcxSchedulerCustomResourceViewHitTest* AHitTest);
	
public:
	__property System::Types::TRect ContentBounds = {read=FContentBounds};
public:
	/* TcxSchedulerGroupSeparatorCellViewInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerMajorSeparatorCellViewInfo(void) { }
	
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerMajorSeparatorCellViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : Cxschedulercustomresourceview::TcxSchedulerGroupSeparatorCellViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	
};


class DELPHICLASS TcxSchedulerTimeGridViewPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTimeGridViewPainter : public Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter
{
	typedef Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter inherited;
	
private:
	TcxSchedulerTimeGridView* FView;
	HIDESBASE TcxSchedulerTimeGridViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawTimeLineCellItem(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AItem, bool &ADone);
	
public:
	virtual void __fastcall Paint(void);
	__property TcxSchedulerTimeGridView* View = {read=FView};
	__property TcxSchedulerTimeGridViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxSchedulerCustomViewPainter.Create */ inline __fastcall virtual TcxSchedulerTimeGridViewPainter(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomresourceview::TcxSchedulerCustomViewPainter(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridViewPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerTimeGridMoreEventsButtonViewInfo;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridMoreEventsButtonViewInfo : public Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo
{
	typedef Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo inherited;
	
private:
	int FDelta;
	int FResourceIndex;
	bool FValidDelta;
	
public:
	__property int Delta = {read=FDelta, write=FDelta, nodefault};
	__property int ResourceIndex = {read=FResourceIndex, write=FResourceIndex, nodefault};
	__property bool ValidDelta = {read=FValidDelta, write=FValidDelta, nodefault};
public:
	/* TcxSchedulerCustomViewInfoItem.Create */ inline __fastcall virtual TcxSchedulerTimeGridMoreEventsButtonViewInfo(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, const System::Types::TRect &ABounds, const System::Types::TRect &AVisibleRect, const Cxgraphics::TcxViewParams &AViewParams) : Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo(APainter, ABounds, AVisibleRect, AViewParams) { }
	/* TcxSchedulerCustomViewInfoItem.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridMoreEventsButtonViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerTimeGridScrollBar;
class PASCALIMPLEMENTATION TcxSchedulerTimeGridScrollBar : public Cxcontrols::TcxControlScrollBarHelper
{
	typedef Cxcontrols::TcxControlScrollBarHelper inherited;
	
private:
	int FResourceIndex;
	
public:
	__property int ResourceIndex = {read=FResourceIndex, nodefault};
public:
	/* TcxControlScrollBarHelper.Create */ inline __fastcall virtual TcxSchedulerTimeGridScrollBar(Cxscrollbar::_di_IcxScrollBarOwner AOwner) : Cxcontrols::TcxControlScrollBarHelper(AOwner) { }
	/* TcxControlScrollBarHelper.Destroy */ inline __fastcall virtual ~TcxSchedulerTimeGridScrollBar(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerTimeGridResourceScroll : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<Cxschedulercustomresourceview::TcxSchedulerMoreEventsButtonViewInfo*> _TcxSchedulerTimeGridResourceScroll__1;
	
	
private:
	TcxSchedulerTimeGridView* FView;
	int FData;
	int FEventMaxLine;
	_TcxSchedulerTimeGridResourceScroll__1 FMoreEventButtons;
	System::Types::TRect FResourceBounds;
	TcxSchedulerTimeGridScrollBar* FScrollBar;
	void __fastcall SetShift(int AValue);
	
protected:
	int FShift;
	void __fastcall ClearMoreEventButtons(void);
	void __fastcall SetEventMaxLine(int AValue);
	void __fastcall Store(bool AClear);
	void __fastcall Restore(void);
	
public:
	__fastcall TcxSchedulerTimeGridResourceScroll(TcxSchedulerTimeGridView* ATimeGridView, int AResourceIndex);
	__fastcall virtual ~TcxSchedulerTimeGridResourceScroll(void);
	void __fastcall HideScrollBar(void);
	void __fastcall SetScrollBarParams(TcxSchedulerTimeGridView* ATimeGridView, int AResourceIndex);
	void __fastcall DestroyScrollBar(void);
	__property System::Types::TRect ResourceBounds = {read=FResourceBounds, write=FResourceBounds};
	__property TcxSchedulerTimeGridScrollBar* ScrollBar = {read=FScrollBar};
	__property int Shift = {read=FShift, write=SetShift, nodefault};
};

#pragma pack(pop)

typedef System::StaticArray<System::UnicodeString, 4> Cxschedulertimegridview__52;

typedef System::StaticArray<System::UnicodeString, 4> Cxschedulertimegridview__62;

typedef System::StaticArray<System::StaticArray<System::UnicodeString, 4>, 4> Cxschedulertimegridview__72;

typedef System::StaticArray<System::UnicodeString, 2> Cxschedulertimegridview__82;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 htcMajorScale = System::Int8(0x11);
static const System::Int8 htcMajorSeparator = System::Int8(0x12);
static const System::Int8 htcMinorScale = System::Int8(0x13);
static const System::Int8 htcSelectionBar = System::Int8(0x14);
static const System::Int8 cxHorzEventIndent = System::Int8(0x2);
static const System::Word cxMinutesPerDay = System::Word(0x5a0);
static const System::Int8 cxMinHourScale = System::Int8(0x1);
static const System::Int8 cxMaxHourScale = System::Int8(0x3c);
static const System::Int8 cxMinColumnWidth = System::Int8(0xf);
static const System::Int8 cxDefaultMinorUnitWidth = System::Int8(0x32);
static const System::Int8 cxMinSelectionBarHeight = System::Int8(0x5);
static const System::Byte cxTimeGridViewTreeBrowserWidth = System::Byte(0xfa);
static const System::Int8 cxcsMajorScale = System::Int8(0x0);
static const System::Int8 cxcsMajorScaleUnitSeparator = System::Int8(0x1);
static const System::Int8 cxcsMinorScale = System::Int8(0x3);
static const System::Int8 cxcsSelectionBar = System::Int8(0x2);
static const System::Int8 cxcsMaxTimeGridStyle = System::Int8(0x2);
extern PACKAGE Cxcontrols::TcxControlClass SchedulerTreeBrowserClass;
extern PACKAGE System::StaticArray<TcxSchedulerTimeGridScaleUnits, 6> ValidMinorUnits;
extern PACKAGE Cxschedulertimegridview__52 WeekTextFormats;
extern PACKAGE Cxschedulertimegridview__62 MonthTextFormats;
extern PACKAGE Cxschedulertimegridview__72 QuarterTextFormats;
extern PACKAGE Cxschedulertimegridview__82 YearTextFormats;
}	/* namespace Cxschedulertimegridview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERTIMEGRIDVIEW)
using namespace Cxschedulertimegridview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulertimegridviewHPP
