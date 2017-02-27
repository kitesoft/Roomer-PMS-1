// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxCalendar.pas' rev: 24.00 (Win64)

#ifndef CxcalendarHPP
#define CxcalendarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.DateUtils.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <dxCalendarUtils.hpp>	// Pascal unit
#include <cxEditConsts.hpp>	// Pascal unit
#include <cxFormats.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcalendar
{
//-- type declarations -------------------------------------------------------
enum TCalendarButton : unsigned char { btnClear, btnNow, btnToday, btnOk };

typedef TCalendarButton TDateButton;

typedef System::Set<TDateButton, TDateButton::btnClear, TDateButton::btnToday>  TDateButtons;

enum TcxCalendarArrow : unsigned char { caPrevMonth, caNextMonth, caPrevYear, caNextYear };

enum TcxCalendarHotTrackRegion : unsigned char { chrNone, chrMonth, chrYear };

enum TcxCalendarKind : unsigned char { ckDate, ckDateTime };

class DELPHICLASS TcxClock;
class PASCALIMPLEMENTATION TcxClock : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	System::TTime FTime;
	bool FTransparent;
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	void __fastcall SetTime(System::TTime Value);
	void __fastcall SetTransparent(bool Value);
	
protected:
	virtual bool __fastcall CanAutoSize(int &ANewWidth, int &ANewHeight);
	virtual void __fastcall Paint(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	
public:
	__fastcall virtual TcxClock(System::Classes::TComponent* AOwner);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	
__published:
	__property AutoSize = {default=0};
	__property Color = {default=-16777211};
	__property LookAndFeel;
	__property ParentColor = {default=1};
	__property System::TTime Time = {read=FTime, write=SetTime};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, default=0};
	__property OnClick;
	__property OnDblClick;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
public:
	/* TcxControl.Destroy */ inline __fastcall virtual ~TcxClock(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxClock(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EF3FF483-9B69-46DF-95A4-D3A3810F63A5}
	operator Cxlookandfeels::_di_IdxSkinSupport()
	{
		Cxlookandfeels::_di_IdxSkinSupport intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IdxSkinSupport*(void) { return (Cxlookandfeels::IdxSkinSupport*)&__IdxSkinSupport; }
	#endif
	
};


class DELPHICLASS TcxMonthListBox;
class DELPHICLASS TcxCustomCalendar;
class PASCALIMPLEMENTATION TcxMonthListBox : public Cxcontainer::TcxCustomPopupWindow
{
	typedef Cxcontainer::TcxCustomPopupWindow inherited;
	
private:
	Cxdateutils::TcxDateTime FCurrentDate;
	System::Types::TPoint FOrigin;
	int FTopMonthDelta;
	int FItemHeight;
	int FItemIndex;
	int FItemCount;
	Cxclasses::TcxTimer* FTimer;
	int FSign;
	void __fastcall DoTimer(System::TObject* Sender);
	TcxCustomCalendar* __fastcall GetCalendar(void);
	Cxdateutils::TcxCustomCalendarTable* __fastcall GetCalendarTable(void);
	System::TDateTime __fastcall GetDate(void);
	bool __fastcall GetShowYears(void);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetTopMonthDelta(int Value);
	
protected:
	virtual System::Types::TPoint __fastcall CalculatePosition(void);
	DYNAMIC void __fastcall Click(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DoShowed(void);
	HIDESBASE void __fastcall FontChanged(void);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall Paint(void);
	__property TcxCustomCalendar* Calendar = {read=GetCalendar};
	__property Cxdateutils::TcxCustomCalendarTable* CalendarTable = {read=GetCalendarTable};
	__property int ItemHeight = {read=FItemHeight, nodefault};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, nodefault};
	__property bool ShowYears = {read=GetShowYears, nodefault};
	__property int TopMonthDelta = {read=FTopMonthDelta, write=SetTopMonthDelta, nodefault};
	
public:
	__fastcall virtual TcxMonthListBox(Vcl::Controls::TWinControl* AOwnerControl);
	__fastcall virtual ~TcxMonthListBox(void);
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall Popup(Vcl::Controls::TWinControl* AFocusedControl);
	__property System::TDateTime Date = {read=GetDate};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxMonthListBox(System::Classes::TComponent* AOwner, int Dummy) : Cxcontainer::TcxCustomPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxMonthListBox(HWND ParentWindow) : Cxcontainer::TcxCustomPopupWindow(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TcxCalendarViewInfo
{
public:
	System::StaticArray<System::Types::TRect, 4> ArrowRects;
	System::Types::TRect CalendarRect;
	System::Types::TRect CurrentDateRegion;
	System::Types::TRect HeaderRegion;
	TcxCalendarArrow LastVisibleArrow;
	System::Types::TRect MonthRegion;
	System::Types::TRect YearRegion;
};


typedef void __fastcall (__closure *TcxCalendarGetDayOfWeekStateEvent)(System::TObject* Sender, Cxdateutils::TDay ADayOfWeek, Vcl::Comctrls::TCustomDrawState AState, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &ABackgroundColor);

typedef void __fastcall (__closure *TcxCalendarGetDayStateEvent)(System::TObject* Sender, System::TDateTime ADate, Vcl::Comctrls::TCustomDrawState AState, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &ABackgroundColor);

class PASCALIMPLEMENTATION TcxCustomCalendar : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	bool FArrowsForYear;
	int FButtonsHeight;
	int FButtonsOffset;
	int FButtonsRegionHeight;
	int FButtonWidth;
	TDateButtons FCalendarButtons;
	Cxbuttons::TcxButton* FClearButton;
	TcxClock* FClock;
	int FClockSize;
	int FColWidth;
	int FDateRegionWidth;
	int FDaysOfWeekHeight;
	double FFirstDate;
	bool FFlat;
	int FHeaderHeight;
	TcxCalendarHotTrackRegion FHotTrackRegion;
	TcxCalendarKind FKind;
	double FMaxDate;
	double FMinDate;
	TcxMonthListBox* FMonthListBox;
	Cxbuttons::TcxButton* FNowButton;
	Cxbuttons::TcxButton* FOKButton;
	System::Uitypes::TCursor FPrevCursor;
	int FRowHeight;
	double FSelectDate;
	int FSideWidth;
	int FSpaceWidth;
	bool FShowOnlyValidDates;
	Cxtimeedit::TcxTimeEdit* FTimeEdit;
	Cxclasses::TcxTimer* FTimer;
	Cxbuttons::TcxButton* FTodayButton;
	TcxCalendarViewInfo FViewInfo;
	bool FWeekNumbers;
	int FWeekNumberWidth;
	bool FYearsInMonthList;
	System::Classes::TNotifyEvent FOnDateTimeChanged;
	TcxCalendarGetDayOfWeekStateEvent FOnGetDayOfWeekState;
	TcxCalendarGetDayStateEvent FOnGetDayState;
	void __fastcall AdjustCalendarControlsPosition(void);
	void __fastcall ButtonClick(System::TObject* Sender);
	void __fastcall CalculateViewInfo(void);
	bool __fastcall CanShowDate(double ADate);
	bool __fastcall CanShowMonth(double ADate);
	bool __fastcall CanShowYear(double ADate);
	void __fastcall CreateButtons(void);
	void __fastcall CorrectHeaderTextRect(System::Types::TRect &R);
	void __fastcall DoDateTimeChanged(void);
	void __fastcall DoScrollArrow(System::TObject* Sender);
	void __fastcall DrawHeader(void);
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	Cxdateutils::TcxCustomCalendarTable* __fastcall GetCalendarTable(void);
	System::Uitypes::TColor __fastcall GetContainerBorderColor(void);
	double __fastcall GetDateFromCell(int X, int Y);
	System::Uitypes::TColor __fastcall GetDateHeaderFrameColor(void);
	System::Uitypes::TColor __fastcall GetDateTimeHeaderFrameColor(void);
	System::Uitypes::TColor __fastcall GetHeaderColor(void);
	System::Types::TRect __fastcall GetHeaderOffset(void);
	bool __fastcall GetShowButtonsRegion(void);
	int __fastcall GetTimeEditWidth(void);
	Cxtimeedit::TcxTimeEditTimeFormat __fastcall GetTimeFormat(void);
	bool __fastcall GetUse24HourFormat(void);
	int __fastcall GetWeekNumbersRegionWidth(void);
	bool __fastcall IsDateInRange(double ADate);
	bool __fastcall IsMonthInRange(double ADate);
	bool __fastcall IsMouseInMonthOrYearRegion(System::Types::TPoint AMousePos);
	bool __fastcall IsYearInRange(double ADate);
	void __fastcall GetVisibleButtonList(System::Classes::TList* AList);
	void __fastcall SetArrowsForYear(bool Value);
	void __fastcall SetButtonsEnabled(void);
	void __fastcall SetCalendarButtons(TDateButtons Value);
	void __fastcall SetFlat(bool Value);
	void __fastcall SetHotTrackRegion(TcxCalendarHotTrackRegion Value);
	void __fastcall SetKind(TcxCalendarKind Value);
	void __fastcall SetMaxDate(double Value);
	void __fastcall SetMinDate(double Value);
	void __fastcall SetTimeFormat(Cxtimeedit::TcxTimeEditTimeFormat Value);
	void __fastcall SetUse24HourFormat(bool Value);
	void __fastcall SetWeekNumbers(bool Value);
	void __fastcall TimeChanged(System::TObject* Sender);
	void __fastcall UpdateCalendarButtonCaptions(void);
	
protected:
	DYNAMIC void __fastcall DblClick(void);
	void __fastcall DrawButtons(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawDateRegion(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawDayNumbers(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawMonths(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawWeekNumbers(Cxgraphics::TcxCanvas* ACanvas);
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall HasBackground(void);
	virtual void __fastcall InitControl(void);
	virtual bool __fastcall InternalMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	virtual bool __fastcall IsMouseWheelHandleNeeded(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	bool __fastcall IsShowOnlyValidDates(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	virtual void __fastcall Calculate(void);
	virtual bool __fastcall CanResize(int &NewWidth, int &NewHeight);
	virtual void __fastcall CheckHotTrack(void);
	void __fastcall DoStep(TcxCalendarArrow AArrow);
	virtual int __fastcall GetButtonsRegionOffset(void);
	virtual double __fastcall GetLastDate(void);
	virtual System::Types::TPoint __fastcall GetMonthCalendarOffset(void);
	virtual double __fastcall GetRealFirstDate(void);
	virtual double __fastcall GetRealLastDate(void);
	virtual System::Types::TSize __fastcall GetSize(void);
	virtual void __fastcall HidePopup(Cxcontrols::TcxControl* Sender, Cxedit::TcxEditCloseUpReason AReason);
	void __fastcall InternalSetSelectDate(double Value, bool ARepositionVisibleDates);
	virtual double __fastcall PosToDateTime(System::Types::TPoint P);
	virtual void __fastcall SetFirstDate(double Value);
	virtual void __fastcall SetSelectDate(double Value);
	void __fastcall SetSize(void);
	void __fastcall StepToFuture(void);
	void __fastcall StepToPast(void);
	void __fastcall MouseTrackingMouseLeave(void);
	__property System::Uitypes::TColor BackgroundColor = {read=GetBackgroundColor, nodefault};
	__property System::Uitypes::TColor ContainerBorderColor = {read=GetContainerBorderColor, nodefault};
	__property Cxdateutils::TcxCustomCalendarTable* CalendarTable = {read=GetCalendarTable};
	__property TcxCalendarHotTrackRegion HotTrackRegion = {read=FHotTrackRegion, write=SetHotTrackRegion, nodefault};
	__property bool ShowButtonsRegion = {read=GetShowButtonsRegion, nodefault};
	__property bool ShowOnlyValidDates = {read=FShowOnlyValidDates, write=FShowOnlyValidDates, nodefault};
	__property double MaxDate = {read=FMaxDate, write=SetMaxDate};
	__property double MinDate = {read=FMinDate, write=SetMinDate};
	
public:
	__fastcall virtual TcxCustomCalendar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomCalendar(void);
	virtual void __fastcall TranslationChanged(void);
	__property bool ArrowsForYear = {read=FArrowsForYear, write=SetArrowsForYear, default=1};
	__property TDateButtons CalendarButtons = {read=FCalendarButtons, write=SetCalendarButtons, nodefault};
	__property double FirstDate = {read=FFirstDate, write=SetFirstDate};
	__property bool Flat = {read=FFlat, write=SetFlat, default=1};
	__property Font;
	__property TcxCalendarKind Kind = {read=FKind, write=SetKind, default=0};
	__property double SelectDate = {read=FSelectDate, write=SetSelectDate};
	__property Cxtimeedit::TcxTimeEditTimeFormat TimeFormat = {read=GetTimeFormat, write=SetTimeFormat, default=0};
	__property bool Use24HourFormat = {read=GetUse24HourFormat, write=SetUse24HourFormat, default=1};
	__property bool WeekNumbers = {read=FWeekNumbers, write=SetWeekNumbers, default=0};
	__property bool YearsInMonthList = {read=FYearsInMonthList, write=FYearsInMonthList, default=1};
	__property System::Classes::TNotifyEvent OnDateTimeChanged = {read=FOnDateTimeChanged, write=FOnDateTimeChanged};
	__property TcxCalendarGetDayOfWeekStateEvent OnGetDayOfWeekState = {read=FOnGetDayOfWeekState, write=FOnGetDayOfWeekState};
	__property TcxCalendarGetDayStateEvent OnGetDayState = {read=FOnGetDayState, write=FOnGetDayState};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomCalendar(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
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


class DELPHICLASS TcxPopupCalendar;
class DELPHICLASS TcxCustomDateEdit;
class PASCALIMPLEMENTATION TcxPopupCalendar : public TcxCustomCalendar
{
	typedef TcxCustomCalendar inherited;
	
private:
	TcxCustomDateEdit* FEdit;
	Cxedit::TcxEditClosePopupEvent FOnHidePopup;
	
protected:
	virtual void __fastcall CheckHotTrack(void);
	virtual void __fastcall HidePopup(Cxcontrols::TcxControl* Sender, Cxedit::TcxEditCloseUpReason AReason);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	
public:
	__property TcxCustomDateEdit* Edit = {read=FEdit, write=FEdit};
	__property Cxedit::TcxEditClosePopupEvent OnHidePopup = {read=FOnHidePopup, write=FOnHidePopup};
public:
	/* TcxCustomCalendar.Create */ inline __fastcall virtual TcxPopupCalendar(System::Classes::TComponent* AOwner) : TcxCustomCalendar(AOwner) { }
	/* TcxCustomCalendar.Destroy */ inline __fastcall virtual ~TcxPopupCalendar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPopupCalendar(HWND ParentWindow) : TcxCustomCalendar(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxPopupCalendarClass;

class DELPHICLASS TcxDateEditPropertiesValues;
class PASCALIMPLEMENTATION TcxDateEditPropertiesValues : public Cxtextedit::TcxTextEditPropertiesValues
{
	typedef Cxtextedit::TcxTextEditPropertiesValues inherited;
	
private:
	bool FDateButtons;
	bool FInputKind;
	bool __fastcall GetMaxDate(void);
	bool __fastcall GetMinDate(void);
	bool __fastcall IsMaxDateStored(void);
	bool __fastcall IsMinDateStored(void);
	void __fastcall SetDateButtons(bool Value);
	void __fastcall SetInputKind(bool Value);
	void __fastcall SetMaxDate(bool Value);
	void __fastcall SetMinDate(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool DateButtons = {read=FDateButtons, write=SetDateButtons, stored=false, nodefault};
	__property bool InputKind = {read=FInputKind, write=SetInputKind, stored=false, nodefault};
	__property bool MaxDate = {read=GetMaxDate, write=SetMaxDate, stored=IsMaxDateStored, nodefault};
	__property bool MinDate = {read=GetMinDate, write=SetMinDate, stored=IsMinDateStored, nodefault};
public:
	/* TcxCustomEditPropertiesValues.Create */ inline __fastcall virtual TcxDateEditPropertiesValues(System::Classes::TPersistent* AOwner) : Cxtextedit::TcxTextEditPropertiesValues(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDateEditPropertiesValues(void) { }
	
};


enum TDateOnError : unsigned char { deNoChange, deToday, deNull };

enum TcxInputKind : unsigned char { ikStandard, ikMask, ikRegExpr };

class DELPHICLASS TcxCustomDateEditProperties;
class PASCALIMPLEMENTATION TcxCustomDateEditProperties : public Cxdropdownedit::TcxCustomPopupEditProperties
{
	typedef Cxdropdownedit::TcxCustomPopupEditProperties inherited;
	
private:
	bool FArrowsForYear;
	TDateButtons FDateButtons;
	TDateOnError FDateOnError;
	TcxInputKind FInputKind;
	TcxCalendarKind FKind;
	bool FSaveTime;
	bool FShowOnlyValidDates;
	bool FShowTime;
	bool FWeekNumbers;
	bool FYearsInMonthList;
	TcxCalendarGetDayOfWeekStateEvent FOnGetDayOfWeekState;
	TcxCalendarGetDayStateEvent FOnGetDayState;
	void __fastcall BuildEditMask(void);
	HIDESBASE TcxDateEditPropertiesValues* __fastcall GetAssignedValues(void);
	TDateButtons __fastcall GetDateButtons(void);
	TDateButtons __fastcall GetDefaultDateButtons(void);
	TcxInputKind __fastcall GetDefaultInputKind(void);
	TcxInputKind __fastcall GetInputKind(void);
	System::TDateTime __fastcall GetMaxDate(void);
	System::TDateTime __fastcall GetMinDate(void);
	void __fastcall CalendarGetDayOfWeekStateEventHandler(System::TObject* Sender, Cxdateutils::TDay ADayOfWeek, Vcl::Comctrls::TCustomDrawState AState, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &ABackgroundColor);
	void __fastcall CalendarGetDayStateEventHandler(System::TObject* Sender, System::TDateTime ADate, Vcl::Comctrls::TCustomDrawState AState, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &ABackgroundColor);
	bool __fastcall IsDateButtonsStored(void);
	bool __fastcall IsInputKindStored(void);
	bool __fastcall NeedShowTime(System::TDateTime ADate, bool AIsFocused);
	void __fastcall SetArrowsForYear(bool Value);
	HIDESBASE void __fastcall SetAssignedValues(TcxDateEditPropertiesValues* Value);
	void __fastcall SetDateButtons(TDateButtons Value);
	void __fastcall SetDateOnError(TDateOnError Value);
	void __fastcall SetInputKind(TcxInputKind Value);
	void __fastcall SetKind(TcxCalendarKind Value);
	void __fastcall SetMaxDate(System::TDateTime Value);
	void __fastcall SetMinDate(System::TDateTime Value);
	void __fastcall SetSaveTime(bool Value);
	void __fastcall SetShowTime(bool Value);
	void __fastcall SetWeekNumbers(bool Value);
	void __fastcall SetYearsInMonthList(bool Value);
	
protected:
	virtual void __fastcall DoAssign(Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall DoChanged(void);
	virtual bool __fastcall GetAlwaysPostEditValue(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesValuesClass __fastcall GetAssignedValuesClass();
	virtual Cxedit::TcxEditDisplayFormatOptions __fastcall GetDisplayFormatOptions(void);
	virtual Cxmaskedit::TcxMaskEditCustomModeClass __fastcall GetModeClass(Cxmaskedit::TcxEditMaskKind AMaskKind);
	__classmethod virtual Cxdropdownedit::TcxCustomEditPopupWindowClass __fastcall GetPopupWindowClass();
	virtual bool __fastcall IsEditValueEmpty(const System::Variant &AEditValue);
	virtual bool __fastcall IsEditValueNumeric(void);
	virtual bool __fastcall IsValueBoundDefined(Cxtextedit::TcxEditValueBound ABound);
	virtual bool __fastcall IsValueBoundsDefined(void);
	virtual bool __fastcall PopupWindowAcceptsAnySize(void);
	System::UnicodeString __fastcall GetEmptyDisplayValue(bool AEditFocused);
	virtual System::WideChar __fastcall GetStandardMaskBlank(int APos);
	virtual bool __fastcall GetTimeZoneInfo(int APos, /* out */ Cxtimeedit::TcxTimeEditZoneInfo &AInfo);
	void __fastcall InternalPrepareEditValue(System::UnicodeString ADisplayValue, /* out */ System::Variant &EditValue);
	__property TcxDateEditPropertiesValues* AssignedValues = {read=GetAssignedValues, write=SetAssignedValues};
	
public:
	__fastcall virtual TcxCustomDateEditProperties(System::Classes::TPersistent* AOwner);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	virtual bool __fastcall IsDisplayValueValid(System::Variant &DisplayValue, bool AEditFocused);
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	virtual bool __fastcall IsValueFormattedByProperties(void);
	virtual void __fastcall DoPrepareDisplayValue(const System::Variant &AEditValue, System::Variant &ADisplayValue, bool AEditFocused);
	virtual void __fastcall ValidateDisplayValue(System::Variant &ADisplayValue, Vcl::Controls::TCaption &AErrorText, bool &AError, Cxedit::TcxCustomEdit* AEdit);
	__property bool ArrowsForYear = {read=FArrowsForYear, write=SetArrowsForYear, default=1};
	__property TDateButtons DateButtons = {read=GetDateButtons, write=SetDateButtons, stored=IsDateButtonsStored, nodefault};
	__property TDateOnError DateOnError = {read=FDateOnError, write=SetDateOnError, default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=0};
	__property TcxInputKind InputKind = {read=GetInputKind, write=SetInputKind, stored=IsInputKindStored, nodefault};
	__property TcxCalendarKind Kind = {read=FKind, write=SetKind, default=0};
	__property System::TDateTime MaxDate = {read=GetMaxDate, write=SetMaxDate};
	__property System::TDateTime MinDate = {read=GetMinDate, write=SetMinDate};
	__property bool SaveTime = {read=FSaveTime, write=SetSaveTime, default=1};
	__property bool ShowOnlyValidDates = {read=FShowOnlyValidDates, write=FShowOnlyValidDates, default=0};
	__property bool ShowTime = {read=FShowTime, write=SetShowTime, default=1};
	__property bool WeekNumbers = {read=FWeekNumbers, write=SetWeekNumbers, default=0};
	__property bool YearsInMonthList = {read=FYearsInMonthList, write=SetYearsInMonthList, default=1};
	__property TcxCalendarGetDayOfWeekStateEvent OnGetDayOfWeekState = {read=FOnGetDayOfWeekState, write=FOnGetDayOfWeekState};
	__property TcxCalendarGetDayStateEvent OnGetDayState = {read=FOnGetDayState, write=FOnGetDayState};
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TcxCustomDateEditProperties(void) { }
	
};


class DELPHICLASS TcxDateEditProperties;
class PASCALIMPLEMENTATION TcxDateEditProperties : public TcxCustomDateEditProperties
{
	typedef TcxCustomDateEditProperties inherited;
	
__published:
	__property Alignment;
	__property ArrowsForYear = {default=1};
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property ButtonGlyph;
	__property ClearKey = {default=0};
	__property DateButtons;
	__property DateOnError = {default=0};
	__property DisplayFormat = {default=0};
	__property EditFormat = {default=0};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=0};
	__property ImmediatePost = {default=0};
	__property InputKind;
	__property Kind = {default=0};
	__property MaxDate = {default=0};
	__property MinDate = {default=0};
	__property Nullstring = {default=0};
	__property PostPopupValueOnTab = {default=0};
	__property ReadOnly;
	__property SaveTime = {default=1};
	__property ShowOnlyValidDates = {default=0};
	__property ShowTime = {default=1};
	__property UseLeftAlignmentOnEditing;
	__property UseNullString = {default=0};
	__property ValidateOnEnter = {default=1};
	__property ValidationOptions = {default=1};
	__property WeekNumbers = {default=0};
	__property YearsInMonthList = {default=1};
	__property OnChange;
	__property OnCloseUp;
	__property OnEditValueChanged;
	__property OnGetDayOfWeekState;
	__property OnGetDayState;
	__property OnInitPopup;
	__property OnPopup;
	__property OnValidate;
public:
	/* TcxCustomDateEditProperties.Create */ inline __fastcall virtual TcxDateEditProperties(System::Classes::TPersistent* AOwner) : TcxCustomDateEditProperties(AOwner) { }
	
public:
	/* TcxCustomMaskEditProperties.Destroy */ inline __fastcall virtual ~TcxDateEditProperties(void) { }
	
};


class DELPHICLASS TcxDateEditPopupWindow;
class PASCALIMPLEMENTATION TcxDateEditPopupWindow : public Cxdropdownedit::TcxPopupEditPopupWindow
{
	typedef Cxdropdownedit::TcxPopupEditPopupWindow inherited;
	
protected:
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual bool __fastcall IsPopupCalendarKey(System::Word Key, System::Classes::TShiftState Shift);
	
public:
	__fastcall virtual TcxDateEditPopupWindow(Vcl::Controls::TWinControl* AOwnerControl);
public:
	/* TcxCustomEditPopupWindow.Destroy */ inline __fastcall virtual ~TcxDateEditPopupWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxDateEditPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxdropdownedit::TcxPopupEditPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDateEditPopupWindow(HWND ParentWindow) : Cxdropdownedit::TcxPopupEditPopupWindow(ParentWindow) { }
	
};


class DELPHICLASS TcxDateEditMaskStandardMode;
class PASCALIMPLEMENTATION TcxDateEditMaskStandardMode : public Cxmaskedit::TcxMaskEditStandardMode
{
	typedef Cxmaskedit::TcxMaskEditStandardMode inherited;
	
protected:
	virtual System::WideChar __fastcall GetBlank(int APos);
public:
	/* TcxMaskEditStandardMode.Create */ inline __fastcall virtual TcxDateEditMaskStandardMode(Cxmaskedit::TcxCustomMaskEdit* AEdit, Cxmaskedit::TcxCustomMaskEditProperties* AProperties) : Cxmaskedit::TcxMaskEditStandardMode(AEdit, AProperties) { }
	/* TcxMaskEditStandardMode.Destroy */ inline __fastcall virtual ~TcxDateEditMaskStandardMode(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomDateEdit : public Cxdropdownedit::TcxCustomPopupEdit
{
	typedef Cxdropdownedit::TcxCustomPopupEdit inherited;
	
private:
	System::TDateTime FDateDropDown;
	System::TDateTime FSavedTime;
	HIDESBASE TcxCustomDateEditProperties* __fastcall GetActiveProperties(void);
	System::TDateTime __fastcall GetCurrentDate(void);
	HIDESBASE TcxCustomDateEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxCustomDateEditProperties* Value);
	
protected:
	TcxPopupCalendar* FCalendar;
	virtual bool __fastcall CanSynchronizeModeText(void);
	virtual void __fastcall CheckEditorValueBounds(void);
	virtual void __fastcall CreatePopupWindow(void);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializePopupWindow(void);
	virtual System::Variant __fastcall InternalGetEditingValue(void);
	virtual System::UnicodeString __fastcall InternalGetText(void);
	virtual void __fastcall InternalSetEditValue(const System::Variant &Value, bool AValidateEditValue);
	virtual bool __fastcall InternalSetText(const System::UnicodeString Value);
	virtual void __fastcall InternalValidateDisplayValue(const System::Variant &ADisplayValue);
	virtual bool __fastcall IsCharValidForPos(System::WideChar &AChar, int APos);
	DYNAMIC void __fastcall PopupWindowClosed(System::TObject* Sender);
	DYNAMIC void __fastcall PopupWindowShowed(System::TObject* Sender);
	virtual void __fastcall SetupPopupWindow(void);
	virtual void __fastcall UpdateTextFormatting(void);
	virtual void __fastcall CreateCalendar(void);
	virtual void __fastcall DateChange(System::TObject* Sender);
	virtual TcxPopupCalendarClass __fastcall GetCalendarClass(void);
	virtual System::TDateTime __fastcall GetDate(void);
	System::TDateTime __fastcall GetDateFromStr(const System::UnicodeString S);
	virtual System::Variant __fastcall GetRecognizableDisplayValue(System::TDateTime ADate);
	virtual void __fastcall SetDate(System::TDateTime Value);
	__property TcxPopupCalendar* Calendar = {read=FCalendar};
	
public:
	__fastcall virtual ~TcxCustomDateEdit(void);
	virtual void __fastcall Clear(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	virtual void __fastcall PrepareEditValue(const System::Variant &ADisplayValue, /* out */ System::Variant &EditValue, bool AEditFocused);
	__property TcxCustomDateEditProperties* ActiveProperties = {read=GetActiveProperties};
	__property System::TDateTime CurrentDate = {read=GetCurrentDate};
	__property System::TDateTime Date = {read=GetDate, write=SetDate, stored=false};
	__property TcxCustomDateEditProperties* Properties = {read=GetProperties, write=SetProperties};
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxCustomDateEdit(System::Classes::TComponent* AOwner)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomDateEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomDateEdit(HWND ParentWindow) : Cxdropdownedit::TcxCustomPopupEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxDateEdit;
class PASCALIMPLEMENTATION TcxDateEdit : public TcxCustomDateEdit
{
	typedef TcxCustomDateEdit inherited;
	
private:
	HIDESBASE TcxDateEditProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxDateEditProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxDateEditProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxDateEditProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property BiDiMode;
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property Date = {default=0};
	__property DragMode = {default=0};
	__property EditValue = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentBiDiMode = {default=1};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxDateEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property TextHint = {default=0};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property OnStartDock;
public:
	/* TcxCustomDateEdit.Destroy */ inline __fastcall virtual ~TcxDateEdit(void) { }
	
public:
	/* TcxCustomMaskEdit.Create */ inline __fastcall virtual TcxDateEdit(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomDateEdit(AOwner) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxDateEdit(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomDateEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxDateEdit(HWND ParentWindow) : TcxCustomDateEdit(ParentWindow) { }
	
};


class DELPHICLASS TcxFilterDateEditHelper;
class PASCALIMPLEMENTATION TcxFilterDateEditHelper : public Cxdropdownedit::TcxFilterDropDownEditHelper
{
	typedef Cxdropdownedit::TcxFilterDropDownEditHelper inherited;
	
public:
	__classmethod virtual Cxedit::TcxCustomEditClass __fastcall GetFilterEditClass();
	__classmethod virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedFilterOperators(Cxedit::TcxCustomEditProperties* AProperties, Cxdatastorage::TcxValueTypeClass AValueTypeClass, bool AExtendedSet = false);
	__classmethod virtual void __fastcall InitializeProperties(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditProperties* AEditProperties, bool AHasButtons);
public:
	/* TObject.Create */ inline __fastcall TcxFilterDateEditHelper(void) : Cxdropdownedit::TcxFilterDropDownEditHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFilterDateEditHelper(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall VarIsNullDate(const System::Variant &AValue);
}	/* namespace Cxcalendar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCALENDAR)
using namespace Cxcalendar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcalendarHPP
