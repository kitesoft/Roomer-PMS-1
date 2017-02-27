// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerDateNavigator.pas' rev: 24.00 (Win32)

#ifndef CxschedulerdatenavigatorHPP
#define CxschedulerdatenavigatorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulerdatenavigator
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxSchedulerDateNavigatorViewInfoClass;

class DELPHICLASS TcxCustomSchedulerAccess;
class PASCALIMPLEMENTATION TcxCustomSchedulerAccess : public Cxschedulercustomcontrols::TcxCustomScheduler
{
	typedef Cxschedulercustomcontrols::TcxCustomScheduler inherited;
	
public:
	/* TcxCustomScheduler.Create */ inline __fastcall virtual TcxCustomSchedulerAccess(System::Classes::TComponent* AOwner) : Cxschedulercustomcontrols::TcxCustomScheduler(AOwner) { }
	/* TcxCustomScheduler.Destroy */ inline __fastcall virtual ~TcxCustomSchedulerAccess(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomSchedulerAccess(HWND ParentWindow) : Cxschedulercustomcontrols::TcxCustomScheduler(ParentWindow) { }
	
};


class DELPHICLASS TcxSchedulerDateNavigatorPainter;
class DELPHICLASS TcxSchedulerDateNavigator;
class DELPHICLASS TcxSchedulerDateNavigatorDayNumberViewInfo;
class DELPHICLASS TcxSchedulerDateNavigatorMonthContentViewInfo;
class DELPHICLASS TcxSchedulerDateNavigatorMonthHeaderViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorPainter : public Cxschedulercustomcontrols::TcxSchedulerSubControlPainter
{
	typedef Cxschedulercustomcontrols::TcxSchedulerSubControlPainter inherited;
	
private:
	Cxgraphics::TcxViewParams FHeaderParams;
	TcxSchedulerDateNavigator* FDateNavigator;
	bool FHeaderTransparent;
	void __fastcall CheckDrawFrame(const System::Types::TRect &ABounds, System::TDateTime ADate);
	bool __fastcall DrawHeaderBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	System::Uitypes::TColor __fastcall GetHolidayTextColor(TcxSchedulerDateNavigatorDayNumberViewInfo* ADayInfo);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
protected:
	virtual void __fastcall DoDrawDayCaptions(TcxSchedulerDateNavigatorMonthContentViewInfo* AViewInfo);
	virtual void __fastcall DoDrawDayNumbers(TcxSchedulerDateNavigatorMonthContentViewInfo* AViewInfo);
	virtual void __fastcall DoDrawMonthContent(TcxSchedulerDateNavigatorMonthContentViewInfo* AViewInfo);
	virtual void __fastcall DoDrawMonthHeader(TcxSchedulerDateNavigatorMonthHeaderViewInfo* AViewInfo);
	virtual void __fastcall DrawBackground(void);
	void __fastcall DrawDayNumber(TcxSchedulerDateNavigatorDayNumberViewInfo* ADayInfo);
	virtual void __fastcall DrawMonthHeader(TcxSchedulerDateNavigatorMonthHeaderViewInfo* AViewInfo);
	virtual void __fastcall DrawSeparators(TcxSchedulerDateNavigatorMonthContentViewInfo* AViewInfo);
	virtual void __fastcall DrawWeekNumbers(TcxSchedulerDateNavigatorMonthContentViewInfo* AViewInfo);
	__property TcxSchedulerDateNavigator* DateNavigator = {read=FDateNavigator};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	
public:
	__fastcall virtual TcxSchedulerDateNavigatorPainter(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	virtual void __fastcall Paint(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDateNavigatorPainter(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSchedulerDateNavigatorPainterClass;

class DELPHICLASS TcxSchedulerDateNavigatorCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorCaptionViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	Cxgraphics::TcxViewParams FSaveParams;
	System::UnicodeString FText;
	bool FTransparent;
	Cxgraphics::TcxViewParams FViewParams;
	
protected:
	void __fastcall RestoreParams(void);
	void __fastcall SaveParams(bool ATransparent);
	__property System::UnicodeString Text = {read=FText, write=FText};
	__property bool Transparent = {read=FTransparent, write=FTransparent, nodefault};
	
public:
	__property System::Types::TRect Bounds = {read=FBounds};
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams, write=FViewParams};
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerDateNavigatorCaptionViewInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDateNavigatorCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorDayNumberViewInfo : public TcxSchedulerDateNavigatorCaptionViewInfo
{
	typedef TcxSchedulerDateNavigatorCaptionViewInfo inherited;
	
private:
	bool FBold;
	System::TDateTime FDate;
	bool FGrayed;
	bool FHoliday;
	bool FSelected;
	System::Types::TRect FSelectionSideBounds;
	
public:
	__property bool Bold = {read=FBold, write=FBold, nodefault};
	__property Bounds;
	__property System::TDateTime Date = {read=FDate};
	__property bool Grayed = {read=FGrayed, nodefault};
	__property bool Holiday = {read=FHoliday, nodefault};
	__property bool Selected = {read=FSelected, nodefault};
	__property System::Types::TRect SelectionSideBounds = {read=FSelectionSideBounds};
	__property Text = {default=0};
	__property Transparent;
	__property ViewParams;
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerDateNavigatorDayNumberViewInfo(void) : TcxSchedulerDateNavigatorCaptionViewInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDateNavigatorDayNumberViewInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerDateNavigatorDayCaptionViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorDayCaptionViewInfo : public TcxSchedulerDateNavigatorCaptionViewInfo
{
	typedef TcxSchedulerDateNavigatorCaptionViewInfo inherited;
	
private:
	System::Byte FIndex;
	
public:
	__property Bounds;
	__property System::Byte Index = {read=FIndex, nodefault};
	__property Text = {default=0};
	__property Transparent;
	__property ViewParams;
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerDateNavigatorDayCaptionViewInfo(void) : TcxSchedulerDateNavigatorCaptionViewInfo() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDateNavigatorDayCaptionViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerDateNavigatorMonthViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorMonthHeaderViewInfo : public TcxSchedulerDateNavigatorCaptionViewInfo
{
	typedef TcxSchedulerDateNavigatorCaptionViewInfo inherited;
	
private:
	Cxlookandfeelpainters::TcxArrowDirections FArrows;
	Cxlookandfeelpainters::TcxNeighbors FNeighbors;
	TcxSchedulerDateNavigatorMonthViewInfo* FOwner;
	System::Types::TRect FMonthNameBounds;
	Cxdateutils::TcxCustomCalendarTable* __fastcall GetCalendar(void);
	int __fastcall GetEra(void);
	int __fastcall GetMonth(void);
	System::Types::TRect __fastcall GetMonthNameBounds(void);
	int __fastcall GetYear(void);
	
protected:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	
public:
	__fastcall TcxSchedulerDateNavigatorMonthHeaderViewInfo(TcxSchedulerDateNavigatorMonthViewInfo* AOwner);
	__property Cxlookandfeelpainters::TcxArrowDirections Arrows = {read=FArrows, nodefault};
	__property Bounds;
	__property Cxdateutils::TcxCustomCalendarTable* Calendar = {read=GetCalendar};
	__property int Era = {read=GetEra, nodefault};
	__property int Month = {read=GetMonth, nodefault};
	__property Cxlookandfeelpainters::TcxNeighbors Neighbors = {read=FNeighbors, nodefault};
	__property System::Types::TRect MonthNameBounds = {read=FMonthNameBounds};
	__property TcxSchedulerDateNavigatorMonthViewInfo* Owner = {read=FOwner};
	__property Text = {default=0};
	__property Transparent;
	__property ViewParams;
	__property int Year = {read=GetYear, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDateNavigatorMonthHeaderViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerDateNavigatorViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorMonthContentViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::StaticArray<System::UnicodeString, 6> _TcxSchedulerDateNavigatorMonthContentViewInfo__1;
	
	
private:
	System::Types::TRect FBounds;
	int FCol;
	int FRow;
	Cxdateutils::TcxDateTime FDate;
	TcxSchedulerDateNavigator* FDateNavigator;
	System::StaticArray<TcxSchedulerDateNavigatorDayNumberViewInfo*, 42> FDays;
	int FDayCount;
	System::StaticArray<TcxSchedulerDateNavigatorDayCaptionViewInfo*, 7> FDayCaptions;
	Vcl::Graphics::TFont* FFont;
	System::Uitypes::TFontCharset FFontCharset;
	System::Types::TRect FHorzSeparatorBound;
	TcxSchedulerDateNavigatorMonthViewInfo* FOwner;
	Cxgraphics::TcxViewParams FSaveParams;
	Cxgraphics::TcxViewParams FSelectedParams;
	bool FTransparent;
	System::Types::TRect FVertSeparatorBound;
	TcxSchedulerDateNavigatorViewInfo* FViewInfo;
	Cxgraphics::TcxViewParams FViewParams;
	System::StaticArray<System::Types::TRect, 6> FWeekBounds;
	int FWeekCount;
	_TcxSchedulerDateNavigatorMonthContentViewInfo__1 FWeekTexts;
	System::Types::TRect FWeekSelectionBarBounds;
	void __fastcall CreateDayInfos(void);
	void __fastcall CreateDayCaptionInfos(void);
	void __fastcall DestroyDayInfos(void);
	void __fastcall DestroyDayCaptionInfos(void);
	Cxdateutils::TcxCustomCalendarTable* __fastcall GetCalendar(void);
	TcxSchedulerDateNavigatorDayCaptionViewInfo* __fastcall GetDayCaptionInfo(System::Byte Index);
	System::Types::TRect __fastcall GetDayRectFromColAndRow(int ACol, int ARow);
	TcxSchedulerDateNavigatorDayNumberViewInfo* __fastcall GetDayNumberViewInfo(System::Byte Index);
	int __fastcall GetEra(void);
	bool __fastcall GetGrayed(System::TDateTime ADate);
	int __fastcall GetMonth(void);
	System::Types::TRect __fastcall GetSelectionSideBounds(const System::Types::TRect &ADayBounds, int ACol);
	int __fastcall GetYear(void);
	bool __fastcall IsValidDayIndex(System::Byte Index);
	bool __fastcall IsValidDayCaptionIndex(System::Byte Index);
	bool __fastcall IsValidWeekIndex(System::Byte Index);
	void __fastcall SetWeekText(System::Byte Index, const System::UnicodeString Value);
	
protected:
	void __fastcall CalcAndAddDayInfo(System::TDateTime ADate, const System::Types::TRect &ABounds, const System::Types::TRect &ASelectionSideBounds);
	virtual void __fastcall Calculate(int ACol, int ARow, const Cxdateutils::TcxDateTime &ADate);
	virtual void __fastcall CalcDays(void);
	virtual void __fastcall CalcDayCaptions(void);
	virtual void __fastcall CalcParams(void);
	virtual void __fastcall CalcSeparatorsBound(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetDateViewParams(System::TDateTime ADate, bool ASelected);
	virtual System::UnicodeString __fastcall GetDayText(System::TDateTime ADate);
	virtual System::UnicodeString __fastcall GetDayCaptionText(Cxdateutils::TdxDayOfWeek ADay);
	virtual System::Types::TRect __fastcall GetWeekBound(System::Byte Index);
	virtual System::UnicodeString __fastcall GetWeekText(System::Byte Index);
	void __fastcall RestoreParams(void);
	void __fastcall SaveParams(void);
	void __fastcall UpdateElementsAfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	__property Cxdateutils::TcxCustomCalendarTable* Calendar = {read=GetCalendar};
	__property TcxSchedulerDateNavigator* DateNavigator = {read=FDateNavigator};
	__property Vcl::Graphics::TFont* Font = {read=FFont};
	__property System::Uitypes::TFontCharset FontCharset = {read=FFontCharset, nodefault};
	__property TcxSchedulerDateNavigatorMonthViewInfo* Owner = {read=FOwner};
	__property TcxSchedulerDateNavigatorViewInfo* ViewInfo = {read=FViewInfo};
	__property System::Types::TRect WeekSelectionBarBounds = {read=FWeekSelectionBarBounds};
	
public:
	__fastcall virtual TcxSchedulerDateNavigatorMonthContentViewInfo(TcxSchedulerDateNavigatorMonthViewInfo* AOwner);
	__fastcall virtual ~TcxSchedulerDateNavigatorMonthContentViewInfo(void);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property int Col = {read=FCol, nodefault};
	__property int DayCount = {read=FDayCount, nodefault};
	__property TcxSchedulerDateNavigatorDayNumberViewInfo* Days[System::Byte Index] = {read=GetDayNumberViewInfo};
	__property TcxSchedulerDateNavigatorDayCaptionViewInfo* DayCaptions[System::Byte Index] = {read=GetDayCaptionInfo};
	__property int Era = {read=GetEra, nodefault};
	__property System::Types::TRect HorzSeparatorBound = {read=FHorzSeparatorBound};
	__property int Month = {read=GetMonth, nodefault};
	__property int Row = {read=FRow, nodefault};
	__property Cxgraphics::TcxViewParams SelectedParams = {read=FSelectedParams};
	__property bool Transparent = {read=FTransparent, write=FTransparent, nodefault};
	__property System::Types::TRect VertSeparatorBound = {read=FVertSeparatorBound};
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams};
	__property int WeekCount = {read=FWeekCount, nodefault};
	__property System::Types::TRect WeekBounds[System::Byte Index] = {read=GetWeekBound};
	__property System::UnicodeString WeekTexts[System::Byte Index] = {read=GetWeekText, write=SetWeekText};
	__property int Year = {read=GetYear, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorMonthViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	int FCol;
	Cxdateutils::TcxDateTime FDate;
	int FRow;
	TcxSchedulerDateNavigatorMonthContentViewInfo* FContent;
	TcxSchedulerDateNavigatorMonthHeaderViewInfo* FHeader;
	TcxSchedulerDateNavigatorViewInfo* FOwner;
	int __fastcall GetEra(void);
	int __fastcall GetMonth(void);
	int __fastcall GetYear(void);
	
protected:
	virtual void __fastcall Calculate(int ACol, int ARow, const Cxdateutils::TcxDateTime &ADate);
	Cxlookandfeelpainters::TcxArrowDirections __fastcall GetHeaderArrows(void);
	Cxlookandfeelpainters::TcxNeighbors __fastcall GetHeaderNeighbors(void);
	__property TcxSchedulerDateNavigatorViewInfo* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxSchedulerDateNavigatorMonthViewInfo(TcxSchedulerDateNavigatorViewInfo* AOwner);
	__fastcall virtual ~TcxSchedulerDateNavigatorMonthViewInfo(void);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property int Col = {read=FCol, nodefault};
	__property TcxSchedulerDateNavigatorMonthContentViewInfo* Content = {read=FContent};
	__property int Era = {read=GetEra, nodefault};
	__property TcxSchedulerDateNavigatorMonthHeaderViewInfo* Header = {read=FHeader};
	__property int Month = {read=GetMonth, nodefault};
	__property int Row = {read=FRow, nodefault};
	__property int Year = {read=GetYear, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorViewInfo : public Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo
{
	typedef Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo inherited;
	
private:
	System::Types::TRect FCalendarBounds;
	int FColCount;
	int FColWidth;
	Cxgraphics::TcxViewParams FContentParams;
	int FDayCaptionsHeight;
	int FHeaderBorderSize;
	int FHeaderHeight;
	Cxgraphics::TcxViewParams FHeaderParams;
	System::Types::TSize FMonthSize;
	System::Classes::TList* FMonthViewInfoList;
	TcxSchedulerDateNavigator* FOwner;
	int FRowCount;
	int FRowHeight;
	Cxgraphics::TcxViewParams FSelectedParams;
	int FSideWidth;
	void __fastcall DestroyMonthViewInfoList(void);
	Cxdateutils::TcxCustomCalendarTable* __fastcall GetCalendar(void);
	TcxSchedulerDateNavigatorMonthViewInfo* __fastcall GetMonthViewInfo(int ACol, int ARow);
	
protected:
	virtual void __fastcall DoCalculate(void);
	void __fastcall CalculateCalendarBounds(void);
	void __fastcall CalculateInternalSizes(void);
	void __fastcall CalculateMonthViewInfos(void);
	void __fastcall CalculateViewParams(void);
	void __fastcall CheckMonthViewInfoCount(void);
	int __fastcall GetCol(int X);
	System::Types::TRect __fastcall GetHeaderRect(int ACol, int ARow);
	System::Types::TRect __fastcall GetInternalRect(int ACol, int ARow);
	System::Types::TRect __fastcall GetLeftArrowRect(void);
	System::Types::TRect __fastcall GetMonthRect(int ACol, int ARow);
	System::Types::TRect __fastcall GetRightArrowRect(void);
	int __fastcall GetRow(int Y);
	__property Cxdateutils::TcxCustomCalendarTable* Calendar = {read=GetCalendar};
	__property System::Types::TRect CalendarBounds = {read=FCalendarBounds};
	__property int ColCount = {read=FColCount, nodefault};
	__property int ColWidth = {read=FColWidth, nodefault};
	__property Cxgraphics::TcxViewParams ContentParams = {read=FContentParams};
	__property int DayCaptionsHeight = {read=FDayCaptionsHeight, nodefault};
	__property int HeaderBorderSize = {read=FHeaderBorderSize, nodefault};
	__property int HeaderHeight = {read=FHeaderHeight, nodefault};
	__property Cxgraphics::TcxViewParams HeaderParams = {read=FHeaderParams};
	__property TcxSchedulerDateNavigator* Owner = {read=FOwner};
	__property int RowCount = {read=FRowCount, nodefault};
	__property int RowHeight = {read=FRowHeight, nodefault};
	__property Cxgraphics::TcxViewParams SelectedParams = {read=FSelectedParams};
	__property int SideWidth = {read=FSideWidth, nodefault};
	
public:
	__fastcall virtual TcxSchedulerDateNavigatorViewInfo(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerDateNavigatorViewInfo(void);
	__property System::Types::TSize MonthSize = {read=FMonthSize};
	__property TcxSchedulerDateNavigatorMonthViewInfo* MonthViewInfo[int ACol][int ARow] = {read=GetMonthViewInfo};
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerDateNavigatorStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	TcxSchedulerDateNavigator* __fastcall GetDateNavigator(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxSchedulerDateNavigatorStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetBackgroundParams(void);
	Cxgraphics::TcxViewParams __fastcall GetContentParams(void);
	Cxgraphics::TcxViewParams __fastcall GetHeaderParams(void);
	Cxgraphics::TcxViewParams __fastcall GetSelectionParams(void);
	__property TcxSchedulerDateNavigator* DateNavigator = {read=GetDateNavigator};
	
__published:
	__property Cxstyles::TcxStyle* Background = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* Header = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* Selection = {read=GetValue, write=SetValue, index=3};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxSchedulerDateNavigatorStyles(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerDateNavigatorHitTest;
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorHitTest : public Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest
{
	typedef Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest inherited;
	
private:
	System::TDateTime FHitDate;
	TcxSchedulerDateNavigatorMonthViewInfo* FMonthViewInfo;
	System::Types::TRect __fastcall GetDatesBounds(void);
	System::TDateTime __fastcall GetFirstWeekSelectableDate(void);
	TcxSchedulerDateNavigator* __fastcall GetOwner(void);
	TcxSchedulerDateNavigatorViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Clear(void);
	virtual void __fastcall DoCalculate(void);
	virtual void __fastcall CalcMonth(void);
	bool __fastcall CheckDayCaptions(void);
	bool __fastcall CheckMonthHeader(void);
	bool __fastcall CheckWeekSelectionBar(void);
	__property TcxSchedulerDateNavigator* Owner = {read=GetOwner};
	__property TcxSchedulerDateNavigatorViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__property bool HitAtCalendar = {read=GetBitState, index=2, nodefault};
	__property bool HitAtDayCaptions = {read=GetBitState, index=3, nodefault};
	__property bool HitAtMonthName = {read=GetBitState, index=4, nodefault};
	__property bool HitAtNextMonth = {read=GetBitState, index=5, nodefault};
	__property bool HitAtPrevMonth = {read=GetBitState, index=6, nodefault};
	__property HitAtTime;
	__property bool HitAtWeekSelectionBar = {read=GetBitState, index=7, nodefault};
	__property System::TDateTime HitDate = {read=FHitDate};
	__property TcxSchedulerDateNavigatorMonthViewInfo* MonthViewInfo = {read=FMonthViewInfo};
	__property Time = {default=0};
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerDateNavigatorHitTest(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner) : Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerDateNavigatorHitTest(void) { }
	
};


class DELPHICLASS TcxSchedulerDateNavigatorController;
class PASCALIMPLEMENTATION TcxSchedulerDateNavigatorController : public Cxschedulercustomcontrols::TcxSchedulerSubControlController
{
	typedef Cxschedulercustomcontrols::TcxSchedulerSubControlController inherited;
	
private:
	bool FCalculatedHintBounds;
	System::TDateTime FDragDate;
	bool FExtSelect;
	System::UnicodeString FHintText;
	bool FIgnoreMouseMove;
	bool FSaveSelectionIsWeeks;
	Cxschedulerutils::TcxSchedulerDateList* FSaveSelectionList;
	System::TDateTime FSelFinish;
	System::TDateTime FSelStart;
	bool FSingleSelection;
	Vcl::Extctrls::TTimer* FTimer;
	bool FUnselect;
	HIDESBASE TcxSchedulerDateNavigatorHitTest* __fastcall GetHitTest(void);
	TcxSchedulerDateNavigator* __fastcall GetOwner(void);
	TcxSchedulerDateNavigatorViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetDragDate(const System::TDateTime Value);
	void __fastcall StartTimer(bool AFuture);
	void __fastcall StopTimer(void);
	void __fastcall TimerProc(System::TObject* Sender);
	
protected:
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall HideHint(void);
	virtual void __fastcall ShowHint(void);
	virtual void __fastcall CalculateSelection(bool AConcatenate);
	void __fastcall ProcessSelectionOnMouseDown(System::Classes::TShiftState AShift);
	void __fastcall ProcessSelectionOnMouseMove(System::Classes::TShiftState AShift);
	__property TcxSchedulerDateNavigatorHitTest* HitTest = {read=GetHitTest};
	__property TcxSchedulerDateNavigator* Owner = {read=GetOwner};
	__property TcxSchedulerDateNavigatorViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerDateNavigatorController(Cxschedulercustomcontrols::TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerDateNavigatorController(void);
	__property System::TDateTime DragDate = {read=FDragDate, write=SetDragDate};
};


typedef void __fastcall (__closure *TcxSchedulerPeriodChangedEvent)(System::TObject* Sender, const System::TDateTime AStart, const System::TDateTime AFinish);

typedef void __fastcall (__closure *TcxSchedulerDateNavigatorCustomDrawBackgroundEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxgraphics::TcxViewParams &AViewParams, bool &ADone);

typedef void __fastcall (__closure *TcxSchedulerDateNavigatorCustomDrawDayNumberEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDateNavigatorDayNumberViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxSchedulerDateNavigatorCustomDrawDayCaptionEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDateNavigatorDayCaptionViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxSchedulerDateNavigatorCustomDrawContentEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDateNavigatorMonthContentViewInfo* AViewInfo, bool &ADone);

typedef void __fastcall (__closure *TcxSchedulerDateNavigatorCustomDrawHeaderEvent)(System::TObject* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDateNavigatorMonthHeaderViewInfo* AViewInfo, bool &ADone);

class PASCALIMPLEMENTATION TcxSchedulerDateNavigator : public Cxschedulercustomcontrols::TcxSchedulerCustomDateNavigator
{
	typedef Cxschedulercustomcontrols::TcxSchedulerCustomDateNavigator inherited;
	
private:
	Cxdateutils::TcxFirstWeekOfYear FActualFirstWeekOfYear;
	System::TDateTime FFirstDate;
	Cxdateutils::TcxFirstWeekOfYear FFirstWeekOfYear;
	System::Uitypes::TColor FHolidayColor;
	bool FIsSelectionLocked;
	System::TDateTime FLastDate;
	Cxcontainer::TcxCustomPopupWindow* FListBox;
	int FListBoxDelta;
	System::TDateTime FRealFirstDate;
	System::TDateTime FRealLastDate;
	bool FSelectionIsWeeks;
	bool FSelectPeriod;
	bool FShowDatesContainingEventsInBold;
	bool FShowDatesContainingHolidaysInColor;
	bool FShowWeekNumbers;
	TcxSchedulerDateNavigatorStyles* FStyles;
	System::TDateTime FToday;
	bool FUnlimitedSelection;
	TcxSchedulerDateNavigatorCustomDrawBackgroundEvent FOnCustomDrawBackground;
	TcxSchedulerDateNavigatorCustomDrawContentEvent FOnCustomDrawContent;
	TcxSchedulerDateNavigatorCustomDrawDayCaptionEvent FOnCustomDrawDayCaption;
	TcxSchedulerDateNavigatorCustomDrawDayNumberEvent FOnCustomDrawDayNumber;
	TcxSchedulerDateNavigatorCustomDrawHeaderEvent FOnCustomDrawHeader;
	TcxSchedulerPeriodChangedEvent FOnPeriodChanged;
	TcxSchedulerPeriodChangedEvent FOnSelectionChanged;
	Cxdateutils::TcxFirstWeekOfYear __fastcall GetActualFirstWeekOfYear(void);
	Cxdateutils::TcxCustomCalendarTable* __fastcall GetCalendar(void);
	int __fastcall GetColCount(void);
	TcxSchedulerDateNavigatorController* __fastcall GetController(void);
	System::TDateTime __fastcall GetDate(void);
	TcxSchedulerDateNavigatorHitTest* __fastcall GetHitTest(void);
	System::TDateTime __fastcall GetLastDate(void);
	void __fastcall GetLimitDates(System::TDateTime &AFirstDate, System::TDateTime &ALastDate);
	int __fastcall GetRowCount(void);
	bool __fastcall GetSelectPeriod(void);
	TcxSchedulerDateNavigatorViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetColCount(int Value);
	void __fastcall SetDate(System::TDateTime Value);
	void __fastcall SetFirstWeekOfYear(Cxdateutils::TcxFirstWeekOfYear Value);
	void __fastcall SetHolidayColor(System::Uitypes::TColor AValue);
	void __fastcall SetRowCount(int Value);
	void __fastcall SetSelectPeriod(bool Value);
	void __fastcall SetShowDatesContainingEventsInBold(bool Value);
	void __fastcall SetShowDatesContainingHolidaysInColor(bool Value);
	void __fastcall SetShowWeekNumbers(bool Value);
	void __fastcall SetStyles(TcxSchedulerDateNavigatorStyles* const Value);
	void __fastcall SetUnlimitedSelection(bool Value);
	void __fastcall UpdateDimensions(int AColCount, int ARowCount);
	
protected:
	bool IsLocked;
	virtual void __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual bool __fastcall AllowDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	virtual void __fastcall BoundsChanged(void);
	bool __fastcall CanCalculateViewInfo(void);
	virtual void __fastcall CheckSizes(void);
	virtual void __fastcall CheckCurrentDate(void);
	virtual void __fastcall ClearDragging(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlPainter* __fastcall CreatePainter(void);
	virtual Cxschedulercustomcontrols::TcxSchedulerSubControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DoLayoutChanged(void);
	bool __fastcall CanDrawSelectionSide(void);
	virtual void __fastcall CheckSelectionBounds(void);
	virtual void __fastcall DoSelectionChanged(void);
	virtual void __fastcall DoPeriodChangedEvent(void);
	virtual void __fastcall DoSelectionChangedEvent(void);
	virtual void __fastcall DoScrollSelection(int AScrollDelta)/* overload */;
	virtual void __fastcall DoScrollSelection(bool AForward, System::TDateTime ANeedDate, bool AIsByPage)/* overload */;
	void __fastcall EnsureSelectionVisible(void);
	virtual void __fastcall GetCalendarDimension(/* out */ int &AColCount, /* out */ int &ARowCount);
	virtual bool __fastcall IsDateHasEvent(System::TDateTime ADate);
	virtual bool __fastcall IsDateHasHoliday(System::TDateTime ADate);
	virtual bool __fastcall IsDateSelected(System::TDateTime ADate);
	virtual bool __fastcall IsDateToday(System::TDateTime ADate);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall FormatChanged(void);
	virtual System::Types::TSize __fastcall GetMonthSize(void);
	virtual System::TDateTime __fastcall GetRealFirstDate(void);
	virtual System::TDateTime __fastcall GetRealLastDate(void);
	virtual bool __fastcall GetShowDatesContainingEventsInBold(void);
	virtual bool __fastcall GetShowDatesContainingHolidaysInColor(void);
	virtual void __fastcall MakeSelectionVisible(void);
	virtual void __fastcall RefreshDays(void);
	virtual void __fastcall SetFirstDate(System::TDateTime Value);
	virtual void __fastcall ShowMonthPopup(TcxSchedulerDateNavigatorMonthViewInfo* AMonthInfo);
	void __fastcall StepToPast(void);
	void __fastcall StepToFuture(void);
	virtual void __fastcall UpdateCalculatedValues(void);
	virtual void __fastcall UpdateDragging(void);
	void __fastcall UpdateLastDates(void);
	virtual void __fastcall UpdateSelection(void);
	virtual void __fastcall VisibleChanged(void);
	virtual void __fastcall AfterCustomDraw(Cxgraphics::TcxCanvas* ACanvas, Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall BeforeCustomDraw(Cxgraphics::TcxCanvas* ACanvas, const Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall DoCustomDrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Cxgraphics::TcxViewParams &AViewParams);
	virtual bool __fastcall DoCustomDrawDayNumber(Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDateNavigatorDayNumberViewInfo* ADayInfo);
	virtual bool __fastcall DoCustomDrawDayCaption(Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDateNavigatorDayCaptionViewInfo* ADayCaptionInfo);
	virtual bool __fastcall DoCustomDrawContent(Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDateNavigatorMonthContentViewInfo* AViewInfo);
	virtual bool __fastcall DoCustomDrawHeader(Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerDateNavigatorMonthHeaderViewInfo* AViewInfo);
	__property Cxdateutils::TcxCustomCalendarTable* Calendar = {read=GetCalendar};
	__property TcxSchedulerDateNavigatorController* Controller = {read=GetController};
	__property bool UnlimitedSelection = {read=FUnlimitedSelection, write=SetUnlimitedSelection, nodefault};
	__property TcxSchedulerDateNavigatorViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerDateNavigator(Cxschedulercustomcontrols::TcxCustomScheduler* AOwner);
	virtual void __fastcall AssignProperties(TcxSchedulerDateNavigator* ASource);
	virtual void __fastcall SetIntegralSizes(void);
	void __fastcall UpdateFirstDate(const System::TDateTime AValue);
	__property Cxdateutils::TcxFirstWeekOfYear ActualFirstWeekOfYear = {read=FActualFirstWeekOfYear, nodefault};
	__property System::TDateTime Date = {read=GetDate, write=SetDate};
	__property System::TDateTime FirstDate = {read=FFirstDate, write=SetFirstDate};
	__property TcxSchedulerDateNavigatorHitTest* HitTest = {read=GetHitTest};
	__property System::TDateTime LastDate = {read=FLastDate};
	__property System::TDateTime RealFirstDate = {read=FRealFirstDate};
	__property System::TDateTime RealLastDate = {read=FRealLastDate};
	__property bool SelectionIsWeeks = {read=FSelectionIsWeeks, write=FSelectionIsWeeks, nodefault};
	__property Cxschedulerutils::TcxSchedulerDateList* SelectionList = {read=GetSelection};
	__property bool SelectPeriod = {read=GetSelectPeriod, write=SetSelectPeriod, nodefault};
	
__published:
	__property int ColCount = {read=GetColCount, write=SetColCount, default=1};
	__property Cxdateutils::TcxFirstWeekOfYear FirstWeekOfYear = {read=FFirstWeekOfYear, write=SetFirstWeekOfYear, default=0};
	__property System::Uitypes::TColor HolidayColor = {read=FHolidayColor, write=SetHolidayColor, default=255};
	__property int RowCount = {read=GetRowCount, write=SetRowCount, default=1};
	__property bool ShowDatesContainingEventsInBold = {read=FShowDatesContainingEventsInBold, write=SetShowDatesContainingEventsInBold, default=1};
	__property bool ShowDatesContainingHolidaysInColor = {read=FShowDatesContainingHolidaysInColor, write=SetShowDatesContainingHolidaysInColor, default=0};
	__property bool ShowWeekNumbers = {read=FShowWeekNumbers, write=SetShowWeekNumbers, default=1};
	__property TcxSchedulerDateNavigatorStyles* Styles = {read=FStyles, write=SetStyles};
	__property Visible = {default=1};
	__property TcxSchedulerDateNavigatorCustomDrawBackgroundEvent OnCustomDrawBackground = {read=FOnCustomDrawBackground, write=FOnCustomDrawBackground};
	__property TcxSchedulerDateNavigatorCustomDrawDayCaptionEvent OnCustomDrawDayCaption = {read=FOnCustomDrawDayCaption, write=FOnCustomDrawDayCaption};
	__property TcxSchedulerDateNavigatorCustomDrawDayNumberEvent OnCustomDrawDayNumber = {read=FOnCustomDrawDayNumber, write=FOnCustomDrawDayNumber};
	__property TcxSchedulerDateNavigatorCustomDrawContentEvent OnCustomDrawContent = {read=FOnCustomDrawContent, write=FOnCustomDrawContent};
	__property TcxSchedulerDateNavigatorCustomDrawHeaderEvent OnCustomDrawHeader = {read=FOnCustomDrawHeader, write=FOnCustomDrawHeader};
	__property TcxSchedulerPeriodChangedEvent OnPeriodChanged = {read=FOnPeriodChanged, write=FOnPeriodChanged};
	__property TcxSchedulerPeriodChangedEvent OnSelectionChanged = {read=FOnSelectionChanged, write=FOnSelectionChanged};
public:
	/* TcxSchedulerCustomDateNavigator.Destroy */ inline __fastcall virtual ~TcxSchedulerDateNavigator(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 htcCalendar = System::Int8(0x2);
static const System::Int8 htcDayCaptions = System::Int8(0x3);
static const System::Int8 htcMonthName = System::Int8(0x4);
static const System::Int8 htcNextMonth = System::Int8(0x5);
static const System::Int8 htcPrevMonth = System::Int8(0x6);
static const System::Int8 htcWeekSelectionBar = System::Int8(0x7);
static const System::Int8 cxdnBackground = System::Int8(0x0);
static const System::Int8 cxdnContent = System::Int8(0x1);
static const System::Int8 cxdnHeader = System::Int8(0x2);
static const System::Int8 cxdnSelection = System::Int8(0x3);
static const System::Int8 cxcsDateNavigatorFirst = System::Int8(0x0);
static const System::Int8 cxcsDateNavigatorLast = System::Int8(0x3);
static const System::Int8 cxDaysCalendarMaxColCount = System::Int8(0x8);
static const System::Int8 cxMaxMonthViewInfoDays = System::Int8(0x2a);
static const System::Int8 cxMaxWeekCount = System::Int8(0x6);
static const int cxSchedulerDefaultHolidayColor = int(255);
}	/* namespace Cxschedulerdatenavigator */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERDATENAVIGATOR)
using namespace Cxschedulerdatenavigator;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulerdatenavigatorHPP
