// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPScxSchedulerLnk.pas' rev: 24.00 (Win64)

#ifndef DxpscxschedulerlnkHPP
#define DxpscxschedulerlnkHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxTimeEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxScheduler.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxSchedulerCustomControls.hpp>	// Pascal unit
#include <cxSchedulerCustomResourceView.hpp>	// Pascal unit
#include <cxSchedulerDayView.hpp>	// Pascal unit
#include <cxSchedulerDateNavigator.hpp>	// Pascal unit
#include <cxSchedulerWeekView.hpp>	// Pascal unit
#include <cxSchedulerTimeGridView.hpp>	// Pascal unit
#include <cxSchedulerYearView.hpp>	// Pascal unit
#include <cxSchedulerGanttView.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxExtCtrls.hpp>	// Pascal unit
#include <dxPScxCommon.hpp>	// Pascal unit
#include <dxPreVw.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit
#include <dxPrnPg.hpp>	// Pascal unit
#include <dxPSReportRenderCanvas.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscxschedulerlnk
{
//-- type declarations -------------------------------------------------------
enum TcxSchedulerReportItemsType : unsigned char { srSchedulingArea, srHeader, srDateNavigator, srNotesBlank, srNotesLined, srTaskPad, srUnknownItem };

enum TcxSchedulerReportEventPartType : unsigned char { epCaption, epStart, epFinish, epIcons, epMessage, epTimeLine };

typedef System::TMetaClass* TcxCustomSchedulerReportLinkPrintStyleClass;

typedef System::TMetaClass* TcxSchedulerReportCustomCellClass;

typedef System::TMetaClass* TcxSchedulerReportDetailsEventCellClass;

class DELPHICLASS TcxCustomSchedulerReportLinkOptions;
class DELPHICLASS TcxSchedulerReportLink;
class PASCALIMPLEMENTATION TcxCustomSchedulerReportLinkOptions : public Dxpscxcommon::TdxCustomReportLinkOptions
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptions inherited;
	
private:
	TcxSchedulerReportLink* __fastcall GetReportLink(void);
	Cxscheduler::TcxScheduler* __fastcall GetScheduler(void);
	
public:
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
	__property Cxscheduler::TcxScheduler* Scheduler = {read=GetScheduler};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxCustomSchedulerReportLinkOptions(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxCustomSchedulerReportLinkOptions(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkPrintRange;
class DELPHICLASS TcxCustomSchedulerReportLinkPrintStyle;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkPrintRange : public TcxCustomSchedulerReportLinkOptions
{
	typedef TcxCustomSchedulerReportLinkOptions inherited;
	
private:
	System::StaticArray<System::TDate, 2> FDatePrint;
	System::StaticArray<System::TTime, 2> FTimePrint;
	TcxCustomSchedulerReportLinkPrintStyle* __fastcall GetActiveStyle(void);
	int __fastcall GetDayCount(void);
	int __fastcall GetMonthCount(void);
	System::TDate __fastcall GetPrintDate(int AIndex);
	System::TTime __fastcall GetPrintTime(int AIndex);
	Cxdateutils::TDay __fastcall GetStartOfWeek(void);
	int __fastcall GetWeekCount(void);
	int __fastcall GetYearCount(void);
	void __fastcall SetPrintDate(int AIndex, const System::TDate Value);
	void __fastcall SetPrintTime(int AIndex, const System::TTime Value);
	bool __fastcall IsDateStored(int AIndex);
	bool __fastcall IsTimeStored(int AIndex);
	
protected:
	virtual void __fastcall CheckTimeRange(void);
	System::TDateTime __fastcall GetDateTimeIF(const System::TDateTime AValue, const System::TDateTime ADefaultValue);
	virtual int __fastcall DesignerTabIndex(void);
	__property TcxCustomSchedulerReportLinkPrintStyle* ActiveStyle = {read=GetActiveStyle};
	__property Cxdateutils::TDay StartOfWeek = {read=GetStartOfWeek, nodefault};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	virtual System::TDate __fastcall DefaultDatePrintFrom(void);
	virtual System::TDate __fastcall DefaultDatePrintTo(void);
	virtual System::TTime __fastcall DefaultTimePrintFrom(void);
	virtual System::TTime __fastcall DefaultTimePrintTo(void);
	__property int DayCount = {read=GetDayCount, nodefault};
	__property int MonthCount = {read=GetMonthCount, nodefault};
	__property int WeekCount = {read=GetWeekCount, nodefault};
	__property int YearCount = {read=GetYearCount, nodefault};
	
__published:
	__property System::TDate PrintFrom = {read=GetPrintDate, write=SetPrintDate, stored=IsDateStored, index=0};
	__property System::TDate PrintTo = {read=GetPrintDate, write=SetPrintDate, stored=IsDateStored, index=1};
	__property System::TTime TimePrintFrom = {read=GetPrintTime, write=SetPrintTime, stored=IsTimeStored, index=0};
	__property System::TTime TimePrintTo = {read=GetPrintTime, write=SetPrintTime, stored=IsTimeStored, index=1};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxSchedulerReportLinkPrintRange(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : TcxCustomSchedulerReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkPrintRange(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkOptionsFormatting;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkOptionsFormatting : public Dxpscxcommon::TdxCustomReportLinkOptionsFormatting
{
	typedef Dxpscxcommon::TdxCustomReportLinkOptionsFormatting inherited;
	
private:
	bool FSuppressContentColoration;
	TcxSchedulerReportLink* __fastcall GetReportLink(void);
	void __fastcall SetSuppressContentColoration(bool Value);
	
protected:
	virtual int __fastcall DesignerTabIndex(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property bool SuppressContentColoration = {read=FSuppressContentColoration, write=SetSuppressContentColoration, default=0};
	__property UseLookAndFeelColors = {default=0};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxSchedulerReportLinkOptionsFormatting(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : Dxpscxcommon::TdxCustomReportLinkOptionsFormatting(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkOptionsFormatting(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkStyles;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkStyles : public Dxpscxcommon::TdxCustomReportLinkStyles
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyles inherited;
	
private:
	Cxschedulercustomcontrols::TcxSchedulerStyles* __fastcall GetExtStyles(void);
	HIDESBASE TcxSchedulerReportLink* __fastcall GetReportLink(void);
	bool __fastcall GetUseSchedulerStyles(void);
	
protected:
	TcxSchedulerReportLink* FReportLink;
	virtual int __fastcall DesignerTabIndex(void);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	__classmethod virtual System::UnicodeString __fastcall GetStyleCaption(int AnIndex);
	virtual int __fastcall GetStyleIndexByCaption(const System::UnicodeString Caption);
	Cxstyles::TcxStyle* __fastcall GetDayHeaderStyle(void);
	Cxstyles::TcxStyle* __fastcall GetResourceHeaderStyle(void);
	__property Cxschedulercustomcontrols::TcxSchedulerStyles* ExtStyles = {read=GetExtStyles};
	
public:
	__fastcall virtual TcxSchedulerReportLinkStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual Cxgraphics::TcxViewParams __fastcall GetSchedulerHeaderParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ADateTime, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource)/* overload */;
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ADateTime, bool ALightColor, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource)/* overload */;
	virtual Cxgraphics::TcxViewParams __fastcall GetDateNavigatorContentParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetDateNavigatorHeaderParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetDayHeaderParams(const System::TDateTime ADateTime);
	virtual Cxgraphics::TcxViewParams __fastcall GetEventParams(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual Cxgraphics::TcxViewParams __fastcall GetNotesAreaBlankParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetNotesAreaLinedParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetResourceHeaderParams(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual Cxgraphics::TcxViewParams __fastcall GetTaskPadParams(void);
	virtual Cxgraphics::TcxViewParams __fastcall GetTimeRulerParams(void);
	__property bool UseSchedulerStyles = {read=GetUseSchedulerStyles, nodefault};
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
	
__published:
	__property Cxstyles::TcxStyle* SchedulerHeader = {read=GetValue, write=SetValue, index=7};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* DateNavigatorContent = {read=GetValue, write=SetValue, index=5};
	__property Cxstyles::TcxStyle* DateNavigatorHeader = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* DayHeader = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* Event = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* ResourceHeader = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* NotesAreaBlank = {read=GetValue, write=SetValue, index=8};
	__property Cxstyles::TcxStyle* NotesAreaLined = {read=GetValue, write=SetValue, index=9};
	__property Cxstyles::TcxStyle* TaskPad = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* TimeRuler = {read=GetValue, write=SetValue, index=4};
	__property StyleSheet;
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkStyles(void) { }
	
private:
	void *__IcxSchedulerTimeRulerParams;	/* Cxschedulerdayview::IcxSchedulerTimeRulerParams */
	void *__IcxSchedulerStylesAdapter;	/* Cxschedulercustomcontrols::IcxSchedulerStylesAdapter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FEAA09ED-8FE1-4968-9BCB-0FC26B13A391}
	operator Cxschedulerdayview::_di_IcxSchedulerTimeRulerParams()
	{
		Cxschedulerdayview::_di_IcxSchedulerTimeRulerParams intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulerdayview::IcxSchedulerTimeRulerParams*(void) { return (Cxschedulerdayview::IcxSchedulerTimeRulerParams*)&__IcxSchedulerTimeRulerParams; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0BFEA90D-0CE8-4ED1-88E8-71A3396186F3}
	operator Cxschedulercustomcontrols::_di_IcxSchedulerStylesAdapter()
	{
		Cxschedulercustomcontrols::_di_IcxSchedulerStylesAdapter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulercustomcontrols::IcxSchedulerStylesAdapter*(void) { return (Cxschedulercustomcontrols::IcxSchedulerStylesAdapter*)&__IcxSchedulerStylesAdapter; }
	#endif
	
};


class DELPHICLASS TcxSchedulerReportLinkStyleSheet;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkStyleSheet : public Dxpscxcommon::TdxCustomReportLinkStyleSheet
{
	typedef Dxpscxcommon::TdxCustomReportLinkStyleSheet inherited;
	
private:
	TcxSchedulerReportLinkStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxSchedulerReportLinkStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxSchedulerReportLinkStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxSchedulerReportLinkStyleSheet(System::Classes::TComponent* AOwner) : Dxpscxcommon::TdxCustomReportLinkStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkStyleSheet(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkRenderInfo;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkRenderInfo : public Dxpscore::TdxPSReportRenderInfo
{
	typedef Dxpscore::TdxPSReportRenderInfo inherited;
	
private:
	TcxSchedulerReportLink* __fastcall GetReportLink(void);
	
protected:
	bool Rendering;
	int FPageColCount;
	int FPageRowCount;
	virtual void __fastcall DoCalculate(void);
	virtual int __fastcall GetPageColCount(void);
	virtual int __fastcall GetPageRowCount(void);
	bool __fastcall IsLoading(void);
	
public:
	virtual bool __fastcall IsDrawPageFootnotesOnPage(int APageIndex);
	virtual bool __fastcall IsDrawPageTitleOnPage(int APageIndex);
	bool __fastcall IsDrawReportFootnotesOnPage(int APageIndex);
	bool __fastcall IsDrawReportTitleOnPage(int APageIndex);
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
public:
	/* TdxPSReportRenderInfo.Create */ inline __fastcall virtual TcxSchedulerReportLinkRenderInfo(Dxpscore::TBasedxReportLink* AReportLink) : Dxpscore::TdxPSReportRenderInfo(AReportLink) { }
	/* TdxPSReportRenderInfo.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkRenderInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerReportRenderer;
class PASCALIMPLEMENTATION TcxSchedulerReportRenderer : public Dxpscore::TdxPSReportRenderer
{
	typedef Dxpscore::TdxPSReportRenderer inherited;
	
public:
	virtual void __fastcall PrepareRenderPage(void);
	virtual void __fastcall UnprepareRenderPage(void);
public:
	/* TdxPSReportRenderer.Create */ inline __fastcall virtual TcxSchedulerReportRenderer(Dxpscore::TBasedxReportLink* AReportLink) : Dxpscore::TdxPSReportRenderer(AReportLink) { }
	/* TdxPSReportRenderer.Destroy */ inline __fastcall virtual ~TcxSchedulerReportRenderer(void) { }
	
};


typedef void __fastcall (__closure *TcxSchedulerReportLinkCanPrintEventEvent)(TcxSchedulerReportLink* Sender, Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool &AllowPrint);

class DELPHICLASS TcxSchedulerReportSchedulerHeaderCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkInitializeSchedulerHeaderEvent)(TcxSchedulerReportLink* Sender, TcxSchedulerReportSchedulerHeaderCell* AItem);

class DELPHICLASS TcxSchedulerReportSchedulingAreaCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkInitializeSchedulingAreaEvent)(TcxSchedulerReportLink* Sender, TcxSchedulerReportSchedulingAreaCell* AItem);

class DELPHICLASS TcxSchedulerReportNotesAreaCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkInitializeNotesEvent)(TcxSchedulerReportLink* Sender, TcxSchedulerReportNotesAreaCell* AItem);

class DELPHICLASS TcxSchedulerReportTaskPadCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkInitializeTaskPadEvent)(TcxSchedulerReportLink* Sender, TcxSchedulerReportTaskPadCell* AItem);

class DELPHICLASS TcxSchedulerReportCustomEventCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkInitializeEventCellEvent)(TcxSchedulerReportLink* Sender, TcxSchedulerReportCustomEventCell* AItem);

class DELPHICLASS TcxSchedulerReportSchedulerHeaderDataCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawSchedulerHeaderCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportSchedulerHeaderDataCell* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerReportDateNavigatorHeader;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawDateNavigatorHeaderCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDateNavigatorHeader* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerReportDateNavigatorDay;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawDateNavigatorDayCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDateNavigatorDay* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerReportDateNavigatorDayCaption;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawDateNavigatorDayCaptionCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDateNavigatorDayCaption* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerReportDateNavigatorWeekNumber;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawDateNavigatorWeekNumberCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDateNavigatorWeekNumber* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerReportDailyTimeRulerCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawTimeRulerCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDailyTimeRulerCell* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerReportNotesDataCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawNotesCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportNotesDataCell* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerReportContentCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawContentCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportContentCell* AItem, bool &ADone);

class DELPHICLASS TcxSchedulerReportHeaderItemCell;
typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawHeaderCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportHeaderItemCell* AItem, bool &ADone);

typedef void __fastcall (__closure *TcxSchedulerReportLinkCustomDrawEventPartCellEvent)(TcxSchedulerReportLink* Sender, Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TAbstractdxReportCellData* AItem, TcxSchedulerReportEventPartType APart, bool &ADone);

class DELPHICLASS TcxSchedulerReportLinkPrintStyles;
class DELPHICLASS TcxfmSchedulerReportLinkDesignWindow;
class DELPHICLASS TcxSchedulerReportPageSite;
class PASCALIMPLEMENTATION TcxSchedulerReportLink : public Dxpscxcommon::TdxCustomcxControlReportLink
{
	typedef Dxpscxcommon::TdxCustomcxControlReportLink inherited;
	
private:
	bool FLinkInPreviewMode;
	System::Classes::TList* FLookAndFeelItems;
	System::Classes::TList* FPageSites;
	TcxSchedulerReportLinkPrintRange* FPrintRange;
	TcxSchedulerReportLinkPrintStyles* FPrintStyles;
	Dxpscore::TBasedxReportLink* FTaskPadReportLink;
	bool FSupportImages;
	System::Classes::TNotifyEvent FOnActivePrintStyleChanged;
	TcxSchedulerReportLinkCanPrintEventEvent FOnCanPrintEvent;
	TcxSchedulerReportLinkCustomDrawSchedulerHeaderCellEvent FOnCustomDrawSchedulerHeaderCell;
	TcxSchedulerReportLinkCustomDrawDateNavigatorHeaderCellEvent FOnCustomDrawDateNavigatorHeaderCell;
	TcxSchedulerReportLinkCustomDrawDateNavigatorDayCellEvent FOnCustomDrawDateNavigatorDayCell;
	TcxSchedulerReportLinkCustomDrawDateNavigatorDayCaptionCellEvent FOnCustomDrawDateNavigatorDayCaptionCell;
	TcxSchedulerReportLinkCustomDrawDateNavigatorWeekNumberCellEvent FOnCustomDrawDateNavigatorWeekNumberCell;
	TcxSchedulerReportLinkCustomDrawTimeRulerCellEvent FOnCustomDrawTimeRulerCell;
	TcxSchedulerReportLinkCustomDrawContentCellEvent FOnCustomDrawContentCell;
	TcxSchedulerReportLinkCustomDrawHeaderCellEvent FOnCustomDrawHeaderCell;
	TcxSchedulerReportLinkCustomDrawEventPartCellEvent FOnCustomDrawEventPartCell;
	TcxSchedulerReportLinkCustomDrawNotesCellEvent FOnCustomDrawNotesCell;
	TcxSchedulerReportLinkCustomDrawNotesCellEvent FOnCustomDrawTaskPadCell;
	TcxSchedulerReportLinkInitializeSchedulingAreaEvent FOnInitializeSchedulingAreaCell;
	TcxSchedulerReportLinkInitializeEventCellEvent FOnInitializeEventCell;
	TcxSchedulerReportLinkInitializeSchedulerHeaderEvent FOnInitializeHeaderPrimaryCell;
	TcxSchedulerReportLinkInitializeSchedulerHeaderEvent FOnInitializeHeaderSecondaryCell;
	TcxSchedulerReportLinkInitializeNotesEvent FOnInitializeNotesAreaCell;
	TcxSchedulerReportLinkInitializeTaskPadEvent FOnInitializeTaskPadCell;
	HIDESBASE TcxSchedulerReportLinkStyles* __fastcall GetActiveStyles(void);
	HIDESBASE TcxfmSchedulerReportLinkDesignWindow* __fastcall GetDesignWindow(void);
	Dxpscore::TdxCellEdgeMode __fastcall GetEdgeMode(void);
	Dxpscore::TdxReportVisualItem* __fastcall GetLookAndFeelItem(int Index);
	int __fastcall GetLookAndFeelItemCount(void);
	TcxSchedulerReportLinkOptionsFormatting* __fastcall GetOptionsFormatting(void);
	TcxSchedulerReportLinkPrintStyles* __fastcall GetPrintStyles(void);
	HIDESBASE TcxSchedulerReportLinkRenderInfo* __fastcall GetRenderInfo(void);
	Cxscheduler::TcxScheduler* __fastcall GetScheduler(void);
	TcxSchedulerReportLinkStyles* __fastcall GetStyles(void);
	HIDESBASE void __fastcall SetOptionsFormatting(TcxSchedulerReportLinkOptionsFormatting* Value);
	void __fastcall SetPrintRange(TcxSchedulerReportLinkPrintRange* Value);
	void __fastcall SetPrintStyles(TcxSchedulerReportLinkPrintStyles* Value);
	HIDESBASE void __fastcall SetStyles(TcxSchedulerReportLinkStyles* Value);
	void __fastcall SetTaskPadReportLink(Dxpscore::TBasedxReportLink* Value);
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual System::Types::TRect __fastcall GetControlSiteBounds(Vcl::Controls::TControl* AControl);
	virtual void __fastcall ConstructReport(Dxpscore::TdxReportCells* AReportCells);
	virtual void __fastcall DoCreateReport(void);
	virtual void __fastcall CustomDraw(Dxpscore::TAbstractdxReportCellData* AItem, Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABoundsRect, System::Types::TRect &AClientRect, bool &ADone);
	virtual void __fastcall DoCanPrintEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool &AllowPrint);
	virtual void __fastcall DoCustomDrawSchedulerHeaderCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportSchedulerHeaderDataCell* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawDateNavigatorHeaderCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDateNavigatorHeader* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawDateNavigatorDayCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDateNavigatorDay* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawDateNavigatorDayCaptionCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDateNavigatorDayCaption* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawDateNavigatorWeekNumberCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDateNavigatorWeekNumber* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawTimeRulerCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportDailyTimeRulerCell* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawContentCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportContentCell* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawHeaderCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportHeaderItemCell* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawEventPartCell(Vcl::Graphics::TCanvas* ACanvas, Dxpscore::TAbstractdxReportCellData* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawNotesCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportNotesDataCell* AItem, bool &ADone);
	virtual void __fastcall DoCustomDrawTaskPadCell(Vcl::Graphics::TCanvas* ACanvas, TcxSchedulerReportNotesDataCell* AItem, bool &ADone);
	virtual void __fastcall GetImageLists(Dxpscore::TdxPSGetImageListProc AProc);
	virtual int __fastcall GetRealScaleFactor(void);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AUpdateCodes);
	virtual Dxpscore::TdxPSReportRendererClass __fastcall GetRendererClass(void);
	virtual Dxpscore::TdxPSReportRenderInfoClass __fastcall GetRenderInfoClass(void);
	virtual void __fastcall InternalRestoreDefaults(void);
	virtual void __fastcall PrepareConstruct(void);
	virtual void __fastcall UnprepareConstruct(void);
	virtual void __fastcall CreateOptions(void);
	virtual void __fastcall DestroyOptions(void);
	virtual Dxpscxcommon::TdxCustomReportLinkOptionsFormattingClass __fastcall GetOptionsFormattingClass(void);
	virtual TcxSchedulerReportLinkPrintRange* __fastcall CreatePrintRange(void);
	virtual TcxSchedulerReportLinkPrintStyles* __fastcall CreatePrintStyles(void);
	bool __fastcall HasEventImages(void);
	bool __fastcall HasResourceImages(void);
	virtual bool __fastcall GetAreNativeStylesAvailable(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStylesClass __fastcall GetStylesClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheetClass __fastcall GetStyleSheetClass(void);
	virtual Dxpscxcommon::TdxCustomReportLinkStyleSheet* __fastcall GetStyleSheetPrototype(void);
	virtual void __fastcall ActivePrintStyleChanged(void);
	virtual void __fastcall DoActivePrintStyleChanged(void);
	void __fastcall FormatLookAndFeelItems(void);
	void __fastcall RegisterLookAndFeelItem(Dxpscore::TdxReportVisualItem* AItem, Dxpscore::TdxCellEdgeStyle AEdgeStyle);
	virtual void __fastcall DoInitializeSchedulingAreaCell(TcxSchedulerReportSchedulingAreaCell* AItem);
	virtual void __fastcall DoInitializeEventCell(TcxSchedulerReportCustomEventCell* AItem);
	virtual void __fastcall DoInitializeHeaderPrimaryCell(TcxSchedulerReportSchedulerHeaderCell* AItem);
	virtual void __fastcall DoInitializeHeaderSecondaryCell(TcxSchedulerReportSchedulerHeaderCell* AItem);
	virtual void __fastcall DoInitializeNotesAreaCell(TcxSchedulerReportNotesAreaCell* AItem);
	virtual void __fastcall DoInitializeTaskPadCell(TcxSchedulerReportTaskPadCell* AItem);
	void __fastcall AssignTaskPadData(TcxSchedulerReportTaskPadCell* ATaskPad);
	virtual void __fastcall InitializeTaskPadCell(TcxSchedulerReportTaskPadCell* ATaskPad);
	void __fastcall SetCellViewParams(Dxpscore::TdxReportVisualItem* ACell, const Cxgraphics::TcxViewParams &AParams)/* overload */;
	void __fastcall SetCellViewParams(Dxpscore::TdxReportVisualItem* ACell, const Dxpscxcommon::TdxReportItemViewParams &AParams)/* overload */;
	TcxSchedulerReportPageSite* __fastcall AddPageSite(const System::Types::TRect &ABounds);
	virtual void __fastcall BuildStyle(void);
	__property TcxSchedulerReportLinkStyles* ActiveStyles = {read=GetActiveStyles};
	__property Dxpscore::TdxCellEdgeMode EdgeMode = {read=GetEdgeMode, nodefault};
	__property bool LinkInPreviewMode = {read=FLinkInPreviewMode, write=FLinkInPreviewMode, nodefault};
	__property int LookAndFeelItemCount = {read=GetLookAndFeelItemCount, nodefault};
	__property Dxpscore::TdxReportVisualItem* LookAndFeelItems[int Index] = {read=GetLookAndFeelItem};
	__property System::Classes::TList* PageSites = {read=FPageSites};
	__property TcxSchedulerReportLinkRenderInfo* RenderInfo = {read=GetRenderInfo};
	__property bool SupportImages = {read=FSupportImages, nodefault};
	
public:
	__fastcall virtual TcxSchedulerReportLink(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxSchedulerReportLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__classmethod virtual bool __fastcall Aggregable();
	virtual void __fastcall LoadDataFromStream(System::Classes::TStream* AStream);
	virtual void __fastcall RebuildReport(void);
	__property TcxfmSchedulerReportLinkDesignWindow* DesignWindow = {read=GetDesignWindow};
	__property Cxscheduler::TcxScheduler* Scheduler = {read=GetScheduler};
	
__published:
	__property Color = {default=16777215};
	__property Font;
	__property TcxSchedulerReportLinkOptionsFormatting* OptionsFormatting = {read=GetOptionsFormatting, write=SetOptionsFormatting};
	__property TcxSchedulerReportLinkPrintRange* PrintRange = {read=FPrintRange, write=SetPrintRange};
	__property TcxSchedulerReportLinkPrintStyles* PrintStyles = {read=GetPrintStyles, write=SetPrintStyles};
	__property ScaleFonts = {default=1};
	__property StyleRepository;
	__property TcxSchedulerReportLinkStyles* Styles = {read=GetStyles, write=SetStyles};
	__property SupportedCustomDraw = {default=0};
	__property Dxpscore::TBasedxReportLink* TaskPadReportLink = {read=FTaskPadReportLink, write=SetTaskPadReportLink};
	__property System::Classes::TNotifyEvent OnActivePrintStyleChanged = {read=FOnActivePrintStyleChanged, write=FOnActivePrintStyleChanged};
	__property TcxSchedulerReportLinkCanPrintEventEvent OnCanPrintEvent = {read=FOnCanPrintEvent, write=FOnCanPrintEvent};
	__property TcxSchedulerReportLinkCustomDrawSchedulerHeaderCellEvent OnCustomDrawSchedulerHeaderCell = {read=FOnCustomDrawSchedulerHeaderCell, write=FOnCustomDrawSchedulerHeaderCell};
	__property TcxSchedulerReportLinkCustomDrawDateNavigatorHeaderCellEvent OnCustomDrawDateNavigatorHeaderCell = {read=FOnCustomDrawDateNavigatorHeaderCell, write=FOnCustomDrawDateNavigatorHeaderCell};
	__property TcxSchedulerReportLinkCustomDrawDateNavigatorDayCellEvent OnCustomDrawDateNavigatorDayCell = {read=FOnCustomDrawDateNavigatorDayCell, write=FOnCustomDrawDateNavigatorDayCell};
	__property TcxSchedulerReportLinkCustomDrawDateNavigatorDayCaptionCellEvent OnCustomDrawDateNavigatorDayCaptionCell = {read=FOnCustomDrawDateNavigatorDayCaptionCell, write=FOnCustomDrawDateNavigatorDayCaptionCell};
	__property TcxSchedulerReportLinkCustomDrawDateNavigatorWeekNumberCellEvent OnCustomDrawDateNavigatorWeekNumberCell = {read=FOnCustomDrawDateNavigatorWeekNumberCell, write=FOnCustomDrawDateNavigatorWeekNumberCell};
	__property TcxSchedulerReportLinkCustomDrawTimeRulerCellEvent OnCustomDrawTimeRulerCell = {read=FOnCustomDrawTimeRulerCell, write=FOnCustomDrawTimeRulerCell};
	__property TcxSchedulerReportLinkCustomDrawContentCellEvent OnCustomDrawContentCell = {read=FOnCustomDrawContentCell, write=FOnCustomDrawContentCell};
	__property TcxSchedulerReportLinkCustomDrawHeaderCellEvent OnCustomDrawHeaderCell = {read=FOnCustomDrawHeaderCell, write=FOnCustomDrawHeaderCell};
	__property TcxSchedulerReportLinkCustomDrawEventPartCellEvent OnCustomDrawEventPartCell = {read=FOnCustomDrawEventPartCell, write=FOnCustomDrawEventPartCell};
	__property TcxSchedulerReportLinkCustomDrawNotesCellEvent OnCustomDrawNotesCell = {read=FOnCustomDrawNotesCell, write=FOnCustomDrawNotesCell};
	__property TcxSchedulerReportLinkCustomDrawNotesCellEvent OnCustomDrawTaskPadCell = {read=FOnCustomDrawTaskPadCell, write=FOnCustomDrawTaskPadCell};
	__property TcxSchedulerReportLinkInitializeSchedulingAreaEvent OnInitializeSchedulingAreaCell = {read=FOnInitializeSchedulingAreaCell, write=FOnInitializeSchedulingAreaCell};
	__property TcxSchedulerReportLinkInitializeEventCellEvent OnInitializeEventCell = {read=FOnInitializeEventCell, write=FOnInitializeEventCell};
	__property TcxSchedulerReportLinkInitializeSchedulerHeaderEvent OnInitializeHeaderPrimaryCell = {read=FOnInitializeHeaderPrimaryCell, write=FOnInitializeHeaderPrimaryCell};
	__property TcxSchedulerReportLinkInitializeSchedulerHeaderEvent OnInitializeHeaderSecondaryCell = {read=FOnInitializeHeaderSecondaryCell, write=FOnInitializeHeaderSecondaryCell};
	__property TcxSchedulerReportLinkInitializeNotesEvent OnInitializeNotesAreaCell = {read=FOnInitializeNotesAreaCell, write=FOnInitializeNotesAreaCell};
	__property TcxSchedulerReportLinkInitializeTaskPadEvent OnInitializeTaskPadCell = {read=FOnInitializeTaskPadCell, write=FOnInitializeTaskPadCell};
private:
	void *__IdxReportLinkController;	/* Dxpscore::IdxReportLinkController */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {120F53E4-1B09-46EF-B42D-04AB8BBCC374}
	operator Dxpscore::_di_IdxReportLinkController()
	{
		Dxpscore::_di_IdxReportLinkController intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscore::IdxReportLinkController*(void) { return (Dxpscore::IdxReportLinkController*)&__IdxReportLinkController; }
	#endif
	
};


enum TcxSchedulerReportLinkPeriodicPrintStyleLayout : unsigned char { pslOnePage, pslTwoPages };

class DELPHICLASS TcxSchedulerReportDateNavigatorCell;
class DELPHICLASS TcxSchedulerReportCommonCellsProducer;
class PASCALIMPLEMENTATION TcxCustomSchedulerReportLinkPrintStyle : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Cxschedulerutils::TcxSchedulerDateList* FBoldedDays;
	System::UnicodeString FCaption;
	bool FCompressWeekends;
	bool FDontPrintWeekends;
	Cxschedulerstorage::TcxSchedulerCachedEventList* FEvents;
	TcxSchedulerReportLinkPeriodicPrintStyleLayout FLayout;
	int FPagesPerPeriod;
	int FResourceCountPerPage;
	bool FShowNotesAreaBlank;
	bool FShowNotesAreaLined;
	bool FShowTaskPad;
	TcxSchedulerReportLinkPrintStyles* FStyles;
	Cxschedulerutils::TcxSchedulerDateList* FUsedDays;
	bool FShowEventImages;
	bool FShowResourceImages;
	bool __fastcall GetActive(void);
	bool __fastcall GetHasAdditionalArea(void);
	int __fastcall GetIndex(void);
	TcxSchedulerReportPageSite* __fastcall GetPageSite(int AIndex);
	int __fastcall GetPeriodCount(void);
	TcxSchedulerReportLinkPrintRange* __fastcall GetPrintRange(void);
	TcxSchedulerReportLink* __fastcall GetReportLink(void);
	int __fastcall GetResourceCount(void);
	Cxscheduler::TcxScheduler* __fastcall GetScheduler(void);
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	System::TTime __fastcall GetTimePrintFrom(void);
	System::TTime __fastcall GetTimePrintTo(void);
	TcxSchedulerReportLinkStyles* __fastcall GetVisualStyles(void);
	bool __fastcall IsCaptionStored(void);
	bool __fastcall IsLayoutStored(void);
	bool __fastcall IsShowNotesAreaBlankStored(void);
	bool __fastcall IsActiveStored(void);
	void __fastcall SetActive(bool Value);
	void __fastcall SetCaption(const System::UnicodeString Value);
	void __fastcall SetCompressWeekends(bool Value);
	void __fastcall SetDontPrintWeekends(bool Value);
	void __fastcall SetLayout(TcxSchedulerReportLinkPeriodicPrintStyleLayout Value);
	void __fastcall SetResourceCountPerPage(int Value);
	void __fastcall SetShowEventImages(bool Value);
	void __fastcall SetShowNotesAreaBlank(bool Value);
	void __fastcall SetShowNotesAreaLined(bool Value);
	void __fastcall SetShowResourceImages(bool Value);
	void __fastcall SetShowTaskPad(bool Value);
	void __fastcall SetTimePrintFrom(System::TTime Value);
	void __fastcall SetTimePrintTo(System::TTime Value);
	
protected:
	System::TDateTime CurrentDate;
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual System::Types::TRect __fastcall GetControlSiteBounds(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall IdxPSCellParams_GetAutoHeight(void);
	virtual Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* __fastcall IdxPSCellParams_GetCanvas(void);
	virtual bool __fastcall IdxPSCellParams_GetDisplayGraphicsAsText(void);
	virtual bool __fastcall IdxPSCellParams_GetEndEllipsis(void);
	virtual bool __fastcall IdxPSCellParams_GetFlatCheckMarks(void);
	virtual System::UnicodeString __fastcall IdxPSCellParams_GetGraphicsText(void);
	virtual bool __fastcall IdxPSCellParams_GetMultiline(void);
	virtual bool __fastcall IdxPSCellParams_GetTransparentGraphics(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMarginLeft(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMarginRight(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMaxHeight(void);
	virtual int __fastcall IdxPSCellParams2_GetPreviewMaxLineCount(void);
	virtual Vcl::Graphics::TGraphicClass __fastcall IdxPSCellParams2_GetRichEditGraphicClass(void);
	virtual bool __fastcall IdxPSCellParams2_GetRichEditTransparent(void);
	virtual void __fastcall ActiveStyleChanged(void);
	virtual TcxSchedulerReportPageSite* __fastcall AddPageSite(const System::Types::TRect &ABounds);
	virtual void __fastcall AfterBuild(void);
	virtual void __fastcall BeforeBuild(void);
	virtual void __fastcall Build(void);
	virtual void __fastcall BuildPages(void);
	virtual void __fastcall BuildSchedulerCells(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual void __fastcall Progress(double APercentDone);
	virtual void __fastcall PrepareEvents(void);
	virtual void __fastcall DoCanPrintEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool &AllowPrint);
	virtual void __fastcall Changed(void);
	virtual void __fastcall CreateObjects(void);
	virtual void __fastcall DestroyObjects(void);
	virtual int __fastcall GetPageCount(void);
	virtual bool __fastcall GetRebuildOnPageParamsChange(Dxprnpg::TdxPrinterPageUpdateCodes AnUpdateCodes);
	virtual System::TDateTime __fastcall CheckPrintRangeDate(const System::TDateTime ADate, int AIndex);
	virtual System::TDateTime __fastcall CheckPrintRangeTime(const System::TDateTime ATime, int AIndex);
	virtual System::TDate __fastcall GetActualDatePrintFrom(void);
	virtual System::TDate __fastcall GetActualDatePrintTo(void);
	virtual Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* __fastcall GetCorrespondedView(void);
	virtual int __fastcall GetPagesPerPeriod(void);
	virtual int __fastcall GetGlyphIndex(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetSchedulerHeaderParams(void);
	void __fastcall DrawDesignWindowPreview(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual int __fastcall GetResourcePageCount(void);
	virtual bool __fastcall GetShowDateNavigator(int APageIndex);
	virtual bool __fastcall GetShowNotesAreaBlank(void);
	void __fastcall SetBoolOption(bool &AOption, bool Value);
	virtual bool __fastcall SupportTimeRange(void);
	virtual bool __fastcall SupportMessage(void);
	virtual bool __fastcall SupportMessageEditProperties(void);
	virtual TcxSchedulerReportDateNavigatorCell* __fastcall CreateDateNavigatorCell(Dxpscore::TdxReportCell* ASite, System::Word AYear, System::Word AMonth);
	virtual TcxSchedulerReportSchedulerHeaderCell* __fastcall CreateHeaderCell(Dxpscore::TdxReportCell* ASite);
	virtual TcxSchedulerReportNotesAreaCell* __fastcall CreateNotesCell(Dxpscore::TdxReportCell* ASite);
	virtual TcxSchedulerReportNotesAreaCell* __fastcall CreateNotesLinedCell(Dxpscore::TdxReportCell* ASite);
	virtual TcxSchedulerReportSchedulingAreaCell* __fastcall CreateSchedulingAreaCell(Dxpscore::TdxReportCell* ASite);
	virtual TcxSchedulerReportCommonCellsProducer* __fastcall CreateSchedulingCellsProducer(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual TcxSchedulerReportTaskPadCell* __fastcall CreateTaskPadCell(Dxpscore::TdxReportCell* ASite);
	virtual void __fastcall InitHeaderCell(TcxSchedulerReportSchedulerHeaderCell* ACell);
	Dxpscore::TdxReportCell* __fastcall InitReportCell(Dxpscore::TdxReportCell* ACell, const System::Types::TRect &ABounds);
	void __fastcall CorrectBoundsWithHeader(TcxSchedulerReportSchedulerHeaderCell* AHeader, System::Types::TRect &ABounds);
	virtual void __fastcall CreateAdditionalControls(Dxpscore::TdxReportCell* ASite, bool AHasCalendar, bool AHasTaskPad, bool AHasNotes, bool AHasNotesLined, bool ARightSide, System::Types::TRect &ABounds);
	virtual void __fastcall CreateControlsOnFirstPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual void __fastcall CreateControlsOnSecondPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual void __fastcall CreateHeaderDateNavigator(TcxSchedulerReportSchedulerHeaderCell* AHeader, int APageIndex, /* out */ System::Types::TRect &ABounds);
	virtual void __fastcall CreateLayoutForPeriod(int APeriodIndex);
	void __fastcall CreatePageSiteWithHeader(int APageIndex, /* out */ TcxSchedulerReportPageSite* &ASite, /* out */ TcxSchedulerReportSchedulerHeaderCell* &AHeader, /* out */ System::Types::TRect &ABounds, bool AIsPrimary = true);
	virtual bool __fastcall CanSplitSchedulingOnTwoPages(void);
	virtual bool __fastcall GetHasPageHeader(int APageIndex);
	virtual bool __fastcall GetHasPageReportFootnotes(int APageIndex);
	virtual bool __fastcall GetHasPageReportTitle(int APageIndex);
	int __fastcall GetPageHeaderHeight(const System::Types::TRect &ASiteBounds, int APageIndex);
	int __fastcall GetPageIndex(int APeriodIndex, int AIndex);
	void __fastcall GetPagePeriodAndIndex(int APageIndex, int &APeriodIndex, int &ASubIndex);
	virtual System::Types::TRect __fastcall GetPageSiteBounds(int APageIndex);
	virtual int __fastcall GetStartOfWeekOffset(void);
	virtual void __fastcall GetPageDateNavigatorInfo(int APageIndex, /* out */ System::Word &AYear, /* out */ System::Word &AMonth);
	virtual int __fastcall GetDaysPerPeriod(void);
	virtual void __fastcall FillDatesForPage(Cxschedulerutils::TcxSchedulerDateList* ADateList, int APageIndex, int APeriodIndex, int ASubIndex);
	__property bool CompressWeekends = {read=FCompressWeekends, write=SetCompressWeekends, default=1};
	__property bool DontPrintWeekends = {read=FDontPrintWeekends, write=SetDontPrintWeekends, default=0};
	__property Cxschedulerstorage::TcxSchedulerCachedEventList* Events = {read=FEvents};
	__property int GlyphIndex = {read=GetGlyphIndex, nodefault};
	__property TcxSchedulerReportLinkPeriodicPrintStyleLayout Layout = {read=FLayout, write=SetLayout, stored=IsLayoutStored, nodefault};
	__property int PagesPerPeriod = {read=FPagesPerPeriod, nodefault};
	__property TcxSchedulerReportPageSite* PageSites[int Index] = {read=GetPageSite};
	__property int PreviewGlyphIndex = {read=GetPreviewGlyphIndex, nodefault};
	__property TcxSchedulerReportLinkPrintRange* PrintRange = {read=GetPrintRange};
	__property int ResourceCount = {read=GetResourceCount, nodefault};
	__property int ResourceCountPerPage = {read=FResourceCountPerPage, write=SetResourceCountPerPage, default=0};
	__property bool ShowEventImages = {read=FShowEventImages, write=SetShowEventImages, nodefault};
	__property bool ShowNotesAreaBlank = {read=GetShowNotesAreaBlank, write=SetShowNotesAreaBlank, stored=IsShowNotesAreaBlankStored, nodefault};
	__property bool ShowNotesAreaLined = {read=FShowNotesAreaLined, write=SetShowNotesAreaLined, default=0};
	__property bool ShowResourceImages = {read=FShowResourceImages, write=SetShowResourceImages, nodefault};
	__property bool ShowTaskPad = {read=FShowTaskPad, write=SetShowTaskPad, default=0};
	__property int StartOfWeekOffset = {read=GetStartOfWeekOffset, nodefault};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=GetStorage};
	__property System::TTime TimePrintFrom = {read=GetTimePrintFrom, write=SetTimePrintFrom, stored=false};
	__property System::TTime TimePrintTo = {read=GetTimePrintTo, write=SetTimePrintTo, stored=false};
	__property Cxschedulerutils::TcxSchedulerDateList* UsedDays = {read=FUsedDays};
	
public:
	__fastcall virtual TcxCustomSchedulerReportLinkPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles);
	__fastcall virtual ~TcxCustomSchedulerReportLinkPrintStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual bool __fastcall IsCompatibleWith(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	virtual void __fastcall RestoreDefaults(void);
	__property System::TDate ActualDatePrintFrom = {read=GetActualDatePrintFrom};
	__property System::TDate ActualDatePrintTo = {read=GetActualDatePrintTo};
	__property Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* CorrespondedView = {read=GetCorrespondedView};
	__property bool HasAdditionalArea = {read=GetHasAdditionalArea, nodefault};
	__property int Index = {read=GetIndex, nodefault};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property int PeriodCount = {read=GetPeriodCount, nodefault};
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
	__property Cxscheduler::TcxScheduler* Scheduler = {read=GetScheduler};
	__property TcxSchedulerReportLinkPrintStyles* Styles = {read=FStyles};
	__property TcxSchedulerReportLinkStyles* VisualStyles = {read=GetVisualStyles};
	
__published:
	__property bool Active = {read=GetActive, write=SetActive, stored=IsActiveStored, nodefault};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption, stored=IsCaptionStored};
private:
	void *__IdxPSCellParams2;	/* Dxpscxcommon::IdxPSCellParams2 */
	void *__IdxPSCellParams;	/* Dxpscxcommon::IdxPSCellParams */
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {09EAB051-1AC2-46FB-A7F4-D6BFA883D015}
	operator Dxpscxcommon::_di_IdxPSCellParams2()
	{
		Dxpscxcommon::_di_IdxPSCellParams2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscxcommon::IdxPSCellParams2*(void) { return (Dxpscxcommon::IdxPSCellParams2*)&__IdxPSCellParams2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F0A495A1-1F0F-4245-A437-16E21ACF9FED}
	operator Dxpscxcommon::_di_IdxPSCellParams()
	{
		Dxpscxcommon::_di_IdxPSCellParams intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxpscxcommon::IdxPSCellParams*(void) { return (Dxpscxcommon::IdxPSCellParams*)&__IdxPSCellParams; }
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
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};


class DELPHICLASS TcxSchedulerReportLinkDailyPrintStyle;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkDailyPrintStyle : public TcxCustomSchedulerReportLinkPrintStyle
{
	typedef TcxCustomSchedulerReportLinkPrintStyle inherited;
	
private:
	int FCurrentPagePerDate;
	
protected:
	virtual void __fastcall BeforeBuild(void);
	virtual bool __fastcall CanSplitSchedulingOnTwoPages(void);
	virtual void __fastcall CreateControlsOnFirstPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual void __fastcall CreateControlsOnSecondPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual TcxSchedulerReportCommonCellsProducer* __fastcall CreateSchedulingCellsProducer(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual void __fastcall FillDatesForPage(Cxschedulerutils::TcxSchedulerDateList* ADateList, int APageIndex, int APeriodIndex, int ASubIndex);
	virtual Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* __fastcall GetCorrespondedView(void);
	virtual int __fastcall GetGlyphIndex(void);
	virtual int __fastcall GetPageCount(void);
	virtual int __fastcall GetPagesPerPeriod(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	virtual bool __fastcall GetShowNotesAreaBlank(void);
	virtual void __fastcall InitHeaderCell(TcxSchedulerReportSchedulerHeaderCell* ACell);
	virtual bool __fastcall SupportMessage(void);
	virtual bool __fastcall SupportTimeRange(void);
	
public:
	__fastcall virtual TcxSchedulerReportLinkDailyPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual bool __fastcall IsCompatibleWith(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	
__published:
	__property Active;
	__property Caption = {default=0};
	__property Layout;
	__property ResourceCountPerPage = {default=0};
	__property ShowEventImages = {default=1};
	__property ShowNotesAreaBlank;
	__property ShowNotesAreaLined = {default=0};
	__property ShowResourceImages = {default=1};
	__property ShowTaskPad = {default=0};
public:
	/* TcxCustomSchedulerReportLinkPrintStyle.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkDailyPrintStyle(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkCustomDetailsPrintStyle;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkCustomDetailsPrintStyle : public TcxCustomSchedulerReportLinkPrintStyle
{
	typedef TcxCustomSchedulerReportLinkPrintStyle inherited;
	
private:
	int FTimeWidth;
	int __fastcall GetPageWidth(void);
	
protected:
	int BuildedPageCount;
	int CellsOnPage;
	TcxSchedulerReportPageSite* CurrentPage;
	virtual TcxSchedulerReportPageSite* __fastcall AddPageSite(const System::Types::TRect &ABounds);
	virtual void __fastcall BeforeBuild(void);
	TcxSchedulerReportPageSite* __fastcall GetNextPage(TcxSchedulerReportPageSite* APrevPage, /* out */ System::Types::TRect &ABounds);
	virtual int __fastcall GetPageCount(void);
	virtual int __fastcall MeasureTimeWidth(void);
	virtual bool __fastcall SupportMessage(void);
	__property int PageWidth = {read=GetPageWidth, nodefault};
	__property int TimeWidth = {read=FTimeWidth, nodefault};
public:
	/* TcxCustomSchedulerReportLinkPrintStyle.Create */ inline __fastcall virtual TcxSchedulerReportLinkCustomDetailsPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles) : TcxCustomSchedulerReportLinkPrintStyle(AStyles) { }
	/* TcxCustomSchedulerReportLinkPrintStyle.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkCustomDetailsPrintStyle(void) { }
	
};


enum TcxSchedulerReportLinkDetailsPrintStylePaginationMode : unsigned char { dpmByDay, dpmByWeek, dpmByMonth };

class DELPHICLASS TcxSchedulerReportLinkDetailsPrintStyle;
class DELPHICLASS TcxSchedulerReportDetailsEventCell;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkDetailsPrintStyle : public TcxSchedulerReportLinkCustomDetailsPrintStyle
{
	typedef TcxSchedulerReportLinkCustomDetailsPrintStyle inherited;
	
private:
	TcxSchedulerReportLinkDetailsPrintStylePaginationMode FPaginationMode;
	bool FUsePagination;
	void __fastcall SetPaginationMode(TcxSchedulerReportLinkDetailsPrintStylePaginationMode Value);
	void __fastcall SetUsePagination(bool Value);
	
protected:
	int EventIndex;
	int DayIndex;
	TcxSchedulerReportDetailsEventCell* CurrentCell;
	System::Types::TRect CurrentPageBounds;
	TcxSchedulerReportSchedulerHeaderCell* PreviousHeader;
	TcxSchedulerReportPageSite* Site;
	TcxSchedulerReportSchedulerHeaderCell* __fastcall AddDayHeader(System::TDateTime ADate, bool AContinue, System::Types::TRect &ABounds);
	virtual void __fastcall BeforeBuild(void);
	virtual void __fastcall BuildPages(void);
	virtual int __fastcall GetDayHeaderHeight(void);
	virtual System::UnicodeString __fastcall GetDayHeaderText(bool AContinue);
	virtual int __fastcall GetGlyphIndex(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	virtual Dxpscxcommon::TdxReportItemViewParams __fastcall GetSchedulerHeaderParams(void);
	virtual TcxSchedulerReportDetailsEventCell* __fastcall AddEventCell(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	void __fastcall CheckPagination(void);
	virtual void __fastcall HeaderNeeded(void);
	bool __fastcall NeedAddDayHeader(void);
	virtual System::Types::TRect __fastcall MeasureCellBounds(void);
	void __fastcall PrepareNextPage(void);
	void __fastcall SetCellPlace(void);
	__property int DayHeaderHeight = {read=GetDayHeaderHeight, nodefault};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Active;
	__property Caption = {default=0};
	__property TcxSchedulerReportLinkDetailsPrintStylePaginationMode PaginationMode = {read=FPaginationMode, write=SetPaginationMode, default=0};
	__property bool UsePagination = {read=FUsePagination, write=SetUsePagination, default=0};
public:
	/* TcxCustomSchedulerReportLinkPrintStyle.Create */ inline __fastcall virtual TcxSchedulerReportLinkDetailsPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles) : TcxSchedulerReportLinkCustomDetailsPrintStyle(AStyles) { }
	/* TcxCustomSchedulerReportLinkPrintStyle.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkDetailsPrintStyle(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkMemoPrintStyle;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkMemoPrintStyle : public TcxSchedulerReportLinkCustomDetailsPrintStyle
{
	typedef TcxSchedulerReportLinkCustomDetailsPrintStyle inherited;
	
private:
	bool FSelectedEventsOnly;
	bool FStartEachItemOnNewPage;
	
protected:
	Dxpscore::TdxReportCell* Site;
	virtual TcxSchedulerReportDetailsEventCell* __fastcall AddEventCell(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	virtual void __fastcall BuildPages(void);
	virtual void __fastcall DoCanPrintEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool &AllowPrint);
	virtual int __fastcall GetGlyphIndex(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	virtual int __fastcall MeasureTimeWidth(void);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Active;
	__property Caption = {default=0};
	__property bool SelectedEventsOnly = {read=FSelectedEventsOnly, write=FSelectedEventsOnly, default=1};
	__property bool StartEachItemOnNewPage = {read=FStartEachItemOnNewPage, write=FStartEachItemOnNewPage, default=1};
public:
	/* TcxCustomSchedulerReportLinkPrintStyle.Create */ inline __fastcall virtual TcxSchedulerReportLinkMemoPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles) : TcxSchedulerReportLinkCustomDetailsPrintStyle(AStyles) { }
	/* TcxCustomSchedulerReportLinkPrintStyle.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkMemoPrintStyle(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkMonthlyPrintStyle;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkMonthlyPrintStyle : public TcxCustomSchedulerReportLinkPrintStyle
{
	typedef TcxCustomSchedulerReportLinkPrintStyle inherited;
	
private:
	bool FPrintExactlyOneMonthPerPage;
	void __fastcall SetPrintExactlyOneMonthPerPage(bool Value);
	
protected:
	virtual System::TDate __fastcall GetActualDatePrintFrom(void);
	virtual System::TDate __fastcall GetActualDatePrintTo(void);
	virtual void __fastcall CreateControlsOnFirstPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual void __fastcall CreateControlsOnSecondPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual void __fastcall FillDatesForPage(Cxschedulerutils::TcxSchedulerDateList* ADateList, int APageIndex, int APeriodIndex, int ASubIndex);
	virtual Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* __fastcall GetCorrespondedView(void);
	System::TDateTime __fastcall GetDateForPage(int APageIndex);
	virtual int __fastcall GetDaysPerPeriod(void);
	virtual int __fastcall GetGlyphIndex(void);
	virtual int __fastcall GetPageCount(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	virtual void __fastcall InitHeaderCell(TcxSchedulerReportSchedulerHeaderCell* ACell);
	
public:
	__fastcall virtual TcxSchedulerReportLinkMonthlyPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual bool __fastcall IsCompatibleWith(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Active;
	__property Caption = {default=0};
	__property DontPrintWeekends = {default=0};
	__property Layout;
	__property bool PrintExactlyOneMonthPerPage = {read=FPrintExactlyOneMonthPerPage, write=SetPrintExactlyOneMonthPerPage, default=0};
	__property ResourceCountPerPage = {default=0};
	__property ShowEventImages = {default=0};
	__property ShowNotesAreaBlank;
	__property ShowNotesAreaLined = {default=0};
	__property ShowResourceImages = {default=1};
	__property ShowTaskPad = {default=0};
public:
	/* TcxCustomSchedulerReportLinkPrintStyle.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkMonthlyPrintStyle(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkTimeLinePrintStyle;
class DELPHICLASS TcxSchedulerReportTimeLineLayoutBuilder;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkTimeLinePrintStyle : public TcxCustomSchedulerReportLinkPrintStyle
{
	typedef TcxCustomSchedulerReportLinkPrintStyle inherited;
	
private:
	TcxSchedulerReportTimeLineLayoutBuilder* FLayoutBuilder;
	bool FPrimaryPageScalesOnly;
	bool FPrimaryPageHeadersOnly;
	bool FShowLinks;
	int FStoredResPerPage;
	int FStoredTopIndex;
	bool FWorkTimeOnly;
	int __fastcall GetPageHeight(void);
	int __fastcall GetPageWidth(int AColumn);
	int __fastcall GetPanelWidth(void);
	System::TDateTime __fastcall GetPrintFrom(void);
	System::TDateTime __fastcall GetPrintTo(void);
	Cxschedulertimegridview::TcxSchedulerTimeGridView* __fastcall GetTimeGridView(void);
	void __fastcall SetPrimaryPageHeadersOnly(bool AValue);
	void __fastcall SetPrimaryPageScalesOnly(bool AValue);
	void __fastcall SetShowLinks(bool AValue);
	void __fastcall SetWorkTimeOnly(bool AValue);
	
protected:
	virtual void __fastcall AfterBuild(void);
	virtual void __fastcall BeforeBuild(void);
	virtual void __fastcall BuildSchedulerCells(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual bool __fastcall CanDontPrintWeekends(void);
	virtual System::TDateTime __fastcall CheckPrintRangeDate(const System::TDateTime ADate, int AIndex);
	virtual System::TDateTime __fastcall CheckPrintRangeTime(const System::TDateTime ATime, int AIndex);
	virtual TcxSchedulerReportCommonCellsProducer* __fastcall CreateSchedulingCellsProducer(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual void __fastcall CreateControlsOnFirstPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* __fastcall GetCorrespondedView(void);
	virtual int __fastcall GetGlyphIndex(void);
	virtual bool __fastcall GetHasPageHeader(int APageIndex);
	virtual int __fastcall GetPageCount(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	bool __fastcall IsFirstColumn(int APageIndex);
	void __fastcall RestoreLayout(void);
	void __fastcall SaveLayout(void);
	virtual bool __fastcall SupportMessage(void);
	__property TcxSchedulerReportTimeLineLayoutBuilder* LayoutBuilder = {read=FLayoutBuilder};
	__property int PageHeight = {read=GetPageHeight, nodefault};
	__property int PageWidth[int Column] = {read=GetPageWidth};
	__property int PanelWidth = {read=GetPanelWidth, nodefault};
	__property System::TDateTime PrintFrom = {read=GetPrintFrom};
	__property System::TDateTime PrintTo = {read=GetPrintTo};
	
public:
	__fastcall virtual TcxSchedulerReportLinkTimeLinePrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles);
	__fastcall virtual ~TcxSchedulerReportLinkTimeLinePrintStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual bool __fastcall IsCompatibleWith(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	virtual void __fastcall RestoreDefaults(void);
	__property Cxschedulertimegridview::TcxSchedulerTimeGridView* CorrespondedView = {read=GetTimeGridView};
	
__published:
	__property Active;
	__property DontPrintWeekends = {default=0};
	__property bool PrimaryPageScalesOnly = {read=FPrimaryPageScalesOnly, write=SetPrimaryPageScalesOnly, default=0};
	__property bool PrimaryPageHeadersOnly = {read=FPrimaryPageHeadersOnly, write=SetPrimaryPageHeadersOnly, default=0};
	__property ResourceCountPerPage = {default=0};
	__property ShowEventImages = {default=1};
	__property bool ShowLinks = {read=FShowLinks, write=SetShowLinks, default=1};
	__property ShowNotesAreaBlank;
	__property ShowNotesAreaLined = {default=0};
	__property ShowResourceImages = {default=1};
	__property ShowTaskPad = {default=0};
	__property bool WorkTimeOnly = {read=FWorkTimeOnly, write=SetWorkTimeOnly, default=0};
};


enum TcxSchedulerReportLinkTrifoldPrintStyleSectionMode : unsigned char { smDailyCalendar, smWeeklyCalendar, smMonthlyCalendar, smTaskPad, smNotesAreaBlank, smNotesAreaLined };

class DELPHICLASS TcxSchedulerReportLinkTrifoldPrintStyle;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkTrifoldPrintStyle : public TcxCustomSchedulerReportLinkPrintStyle
{
	typedef TcxCustomSchedulerReportLinkPrintStyle inherited;
	
private:
	System::StaticArray<TcxSchedulerReportLinkTrifoldPrintStyleSectionMode, 3> FSections;
	bool __fastcall GetHasDailySection(void);
	TcxSchedulerReportLinkTrifoldPrintStyleSectionMode __fastcall GetSection(int Index);
	void __fastcall SetSection(int Index, TcxSchedulerReportLinkTrifoldPrintStyleSectionMode AValue);
	bool __fastcall IsSectionStored(int Index);
	
protected:
	TcxSchedulerReportLinkTrifoldPrintStyleSectionMode FCurrentSection;
	TcxSchedulerReportSchedulingAreaCell* FCurrentSchedulingArea;
	System::Byte FPageRange;
	virtual void __fastcall CreateLayoutForPeriod(int APeriodIndex);
	virtual void __fastcall CreateLayoutForSection(Dxpscore::TdxReportCell* ASite, int APeriodIndex, const System::Types::TRect &ABounds, TcxSchedulerReportLinkTrifoldPrintStyleSectionMode ASection);
	virtual void __fastcall CreateSchedulingAreaWithHeader(Dxpscore::TdxReportCell* ASite, System::Types::TRect &ABounds);
	virtual TcxSchedulerReportCommonCellsProducer* __fastcall CreateSchedulingCellsProducer(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual void __fastcall FillDatesForPage(Cxschedulerutils::TcxSchedulerDateList* ADateList, int APageIndex, int APeriodIndex, int ASubIndex);
	virtual Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* __fastcall GetCorrespondedView(void);
	virtual int __fastcall GetGlyphIndex(void);
	virtual int __fastcall GetPageCount(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	virtual void __fastcall InitHeaderCell(TcxSchedulerReportSchedulerHeaderCell* ACell);
	__property bool HasDailySection = {read=GetHasDailySection, nodefault};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Active;
	__property Caption = {default=0};
	__property TcxSchedulerReportLinkTrifoldPrintStyleSectionMode LeftSection = {read=GetSection, write=SetSection, stored=IsSectionStored, index=0, nodefault};
	__property TcxSchedulerReportLinkTrifoldPrintStyleSectionMode MiddleSection = {read=GetSection, write=SetSection, stored=IsSectionStored, index=1, nodefault};
	__property TcxSchedulerReportLinkTrifoldPrintStyleSectionMode RightSection = {read=GetSection, write=SetSection, stored=IsSectionStored, index=2, nodefault};
public:
	/* TcxCustomSchedulerReportLinkPrintStyle.Create */ inline __fastcall virtual TcxSchedulerReportLinkTrifoldPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles) : TcxCustomSchedulerReportLinkPrintStyle(AStyles) { }
	/* TcxCustomSchedulerReportLinkPrintStyle.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkTrifoldPrintStyle(void) { }
	
};


enum TcxSchedulerReportLinkWeeklyPrintStyleArrange : unsigned char { wsaTopToBottom, wsaLeftToRight };

class DELPHICLASS TcxSchedulerReportLinkWeeklyPrintStyle;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkWeeklyPrintStyle : public TcxCustomSchedulerReportLinkPrintStyle
{
	typedef TcxCustomSchedulerReportLinkPrintStyle inherited;
	
private:
	TcxSchedulerReportLinkWeeklyPrintStyleArrange FArrange;
	Cxschedulerweekview::TcxSchedulerWeekViewDaysLayout FDaysLayout;
	bool FDaysLayoutAssigned;
	Cxschedulerweekview::TcxSchedulerWeekViewDaysLayout __fastcall GetDaysLayout(void);
	bool __fastcall IsArrangeStored(void);
	bool __fastcall IsDaysLayoutStored(void);
	void __fastcall SetArrange(TcxSchedulerReportLinkWeeklyPrintStyleArrange Value);
	void __fastcall SetDaysLayout(Cxschedulerweekview::TcxSchedulerWeekViewDaysLayout Value);
	
protected:
	virtual void __fastcall Build(void);
	virtual void __fastcall CreateControlsOnFirstPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual void __fastcall CreateControlsOnSecondPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual TcxSchedulerReportCommonCellsProducer* __fastcall CreateSchedulingCellsProducer(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual void __fastcall FillDatesForPage(Cxschedulerutils::TcxSchedulerDateList* ADateList, int APageIndex, int APeriodIndex, int ASubIndex);
	virtual Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* __fastcall GetCorrespondedView(void);
	virtual int __fastcall GetGlyphIndex(void);
	System::TDateTime __fastcall GetDateForPage(int APageIndex);
	virtual int __fastcall GetDaysPerPeriod(void);
	virtual int __fastcall GetPageCount(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	virtual int __fastcall GetStartOfWeekOffset(void);
	virtual void __fastcall InitHeaderCell(TcxSchedulerReportSchedulerHeaderCell* ACell);
	virtual bool __fastcall CanDontPrintWeekends(void);
	virtual bool __fastcall SupportMessage(void);
	virtual bool __fastcall SupportTimeRange(void);
	
public:
	__fastcall virtual TcxSchedulerReportLinkWeeklyPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual bool __fastcall IsCompatibleWith(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	virtual void __fastcall RestoreDefaults(void);
	__property bool DaysLayoutAssigned = {read=FDaysLayoutAssigned, write=FDaysLayoutAssigned, nodefault};
	
__published:
	__property Active;
	__property TcxSchedulerReportLinkWeeklyPrintStyleArrange Arrange = {read=FArrange, write=SetArrange, stored=IsArrangeStored, nodefault};
	__property Caption = {default=0};
	__property Cxschedulerweekview::TcxSchedulerWeekViewDaysLayout DaysLayout = {read=GetDaysLayout, write=SetDaysLayout, stored=IsDaysLayoutStored, nodefault};
	__property DontPrintWeekends = {default=0};
	__property Layout;
	__property ResourceCountPerPage = {default=0};
	__property ShowEventImages = {default=0};
	__property ShowNotesAreaBlank;
	__property ShowNotesAreaLined = {default=0};
	__property ShowResourceImages = {default=1};
	__property ShowTaskPad = {default=0};
public:
	/* TcxCustomSchedulerReportLinkPrintStyle.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkWeeklyPrintStyle(void) { }
	
};


class DELPHICLASS TcxSchedulerReportLinkYearlyPrintStyle;
class PASCALIMPLEMENTATION TcxSchedulerReportLinkYearlyPrintStyle : public TcxCustomSchedulerReportLinkPrintStyle
{
	typedef TcxCustomSchedulerReportLinkPrintStyle inherited;
	
private:
	int FMonthCountPerPage;
	bool FPrimaryPageHeadersOnly;
	int __fastcall GetPeriodPageCount(void);
	void __fastcall SetMonthCountPerPage(int AValue);
	void __fastcall SetPrimaryPageHeadersOnly(bool AValue);
	
protected:
	virtual void __fastcall BuildSchedulerCells(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual void __fastcall CreateControlsOnFirstPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual void __fastcall CreateControlsOnSecondPage(int APageIndex, Dxpscore::TdxReportCell* ASite, Dxpscore::TdxReportCell* AHeader, System::Types::TRect &ABounds);
	virtual TcxSchedulerReportCommonCellsProducer* __fastcall CreateSchedulingCellsProducer(TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual void __fastcall FillDatesForPage(Cxschedulerutils::TcxSchedulerDateList* ADateList, int APageIndex, int APeriodIndex, int ASubIndex);
	virtual Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* __fastcall GetCorrespondedView(void);
	virtual bool __fastcall GetHasPageHeader(int APageIndex);
	virtual int __fastcall GetGlyphIndex(void);
	virtual int __fastcall GetPreviewGlyphIndex(void);
	virtual int __fastcall GetPageCount(void);
	virtual bool __fastcall GetShowDateNavigator(int APageIndex);
	virtual void __fastcall InitHeaderCell(TcxSchedulerReportSchedulerHeaderCell* ACell);
	__property int PeriodPageCount = {read=GetPeriodPageCount, nodefault};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall DefaultCaption(void);
	virtual bool __fastcall IsCompatibleWith(Cxschedulercustomcontrols::TcxSchedulerCustomView* AView);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Active;
	__property Caption = {default=0};
	__property Layout;
	__property int MonthCountPerPage = {read=FMonthCountPerPage, write=SetMonthCountPerPage, default=12};
	__property bool PrimaryPageHeadersOnly = {read=FPrimaryPageHeadersOnly, write=SetPrimaryPageHeadersOnly, default=0};
	__property ShowEventImages = {default=0};
	__property ShowNotesAreaBlank;
	__property ShowNotesAreaLined = {default=0};
	__property ShowTaskPad = {default=0};
public:
	/* TcxCustomSchedulerReportLinkPrintStyle.Create */ inline __fastcall virtual TcxSchedulerReportLinkYearlyPrintStyle(TcxSchedulerReportLinkPrintStyles* AStyles) : TcxCustomSchedulerReportLinkPrintStyle(AStyles) { }
	/* TcxCustomSchedulerReportLinkPrintStyle.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkYearlyPrintStyle(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportLinkPrintStyles : public TcxCustomSchedulerReportLinkOptions
{
	typedef TcxCustomSchedulerReportLinkOptions inherited;
	
public:
	TcxCustomSchedulerReportLinkPrintStyle* operator[](int Index) { return Items[Index]; }
	
private:
	TcxCustomSchedulerReportLinkPrintStyle* FActiveStyle;
	bool FActiveStyleAssigned;
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxCustomSchedulerReportLinkPrintStyle* __fastcall GetItem(int Index);
	TcxSchedulerReportLinkDailyPrintStyle* __fastcall GetStyleDaily(void);
	TcxSchedulerReportLinkDetailsPrintStyle* __fastcall GetStyleDetails(void);
	TcxSchedulerReportLinkMemoPrintStyle* __fastcall GetStyleMemo(void);
	TcxSchedulerReportLinkMonthlyPrintStyle* __fastcall GetStyleMonthly(void);
	TcxSchedulerReportLinkTimeLinePrintStyle* __fastcall GetStyleTimeLine(void);
	TcxSchedulerReportLinkTrifoldPrintStyle* __fastcall GetStyleTrifold(void);
	TcxSchedulerReportLinkWeeklyPrintStyle* __fastcall GetStyleWeekly(void);
	TcxSchedulerReportLinkYearlyPrintStyle* __fastcall GetStyleYearly(void);
	void __fastcall SetActiveStyle(TcxCustomSchedulerReportLinkPrintStyle* Value);
	void __fastcall SetActiveStyleAssigned(bool Value);
	void __fastcall SetItem(int Index, TcxCustomSchedulerReportLinkPrintStyle* Value);
	void __fastcall SetStyleDaily(TcxSchedulerReportLinkDailyPrintStyle* Value);
	void __fastcall SetStyleDetails(TcxSchedulerReportLinkDetailsPrintStyle* Value);
	void __fastcall SetStyleMemo(TcxSchedulerReportLinkMemoPrintStyle* Value);
	void __fastcall SetStyleMonthly(TcxSchedulerReportLinkMonthlyPrintStyle* Value);
	void __fastcall SetStyleTimeLine(TcxSchedulerReportLinkTimeLinePrintStyle* Value);
	void __fastcall SetStyleTrifold(TcxSchedulerReportLinkTrifoldPrintStyle* Value);
	void __fastcall SetStyleWeekly(TcxSchedulerReportLinkWeeklyPrintStyle* Value);
	void __fastcall SetStyleYearly(TcxSchedulerReportLinkYearlyPrintStyle* Value);
	
protected:
	virtual void __fastcall CreateObjects(void);
	virtual void __fastcall DestroyObjects(void);
	virtual int __fastcall DesignerTabIndex(void);
	virtual void __fastcall ActiveStyleChanged(void);
	virtual TcxCustomSchedulerReportLinkPrintStyle* __fastcall CreateStyle(TcxCustomSchedulerReportLinkPrintStyleClass AStyleClass);
	virtual void __fastcall CreateStyles(void);
	virtual void __fastcall DestroyStyles(void);
	void __fastcall GetStyleByClassEx(TcxCustomSchedulerReportLinkPrintStyleClass AClass, void *AInstance);
	void __fastcall SetActiveStyleEx(TcxCustomSchedulerReportLinkPrintStyle* Value);
	virtual void __fastcall StyleChanged(TcxCustomSchedulerReportLinkPrintStyle* AStyle);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	virtual TcxCustomSchedulerReportLinkPrintStyle* __fastcall GetCorrespondingStyle(void);
	TcxCustomSchedulerReportLinkPrintStyle* __fastcall GetStyleByClass(TcxCustomSchedulerReportLinkPrintStyleClass AClass);
	TcxCustomSchedulerReportLinkPrintStyle* __fastcall GetStyleByName(const System::UnicodeString Name);
	TcxCustomSchedulerReportLinkPrintStyle* __fastcall GetStyleByView(Cxschedulercustomcontrols::TcxSchedulerCustomView* View);
	int __fastcall IndexOf(TcxCustomSchedulerReportLinkPrintStyle* AItem);
	__property TcxCustomSchedulerReportLinkPrintStyle* ActiveStyle = {read=FActiveStyle, write=SetActiveStyle, stored=false};
	__property bool ActiveStyleAssigned = {read=FActiveStyleAssigned, write=SetActiveStyleAssigned, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TcxCustomSchedulerReportLinkPrintStyle* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	
__published:
	__property TcxSchedulerReportLinkDailyPrintStyle* Daily = {read=GetStyleDaily, write=SetStyleDaily};
	__property TcxSchedulerReportLinkDetailsPrintStyle* Details = {read=GetStyleDetails, write=SetStyleDetails};
	__property TcxSchedulerReportLinkMemoPrintStyle* Memo = {read=GetStyleMemo, write=SetStyleMemo};
	__property TcxSchedulerReportLinkMonthlyPrintStyle* Monthly = {read=GetStyleMonthly, write=SetStyleMonthly};
	__property TcxSchedulerReportLinkTrifoldPrintStyle* Trifold = {read=GetStyleTrifold, write=SetStyleTrifold};
	__property TcxSchedulerReportLinkTimeLinePrintStyle* TimeLine = {read=GetStyleTimeLine, write=SetStyleTimeLine};
	__property TcxSchedulerReportLinkWeeklyPrintStyle* Weekly = {read=GetStyleWeekly, write=SetStyleWeekly};
	__property TcxSchedulerReportLinkYearlyPrintStyle* Yearly = {read=GetStyleYearly, write=SetStyleYearly};
public:
	/* TdxCustomReportLinkOptions.Create */ inline __fastcall virtual TcxSchedulerReportLinkPrintStyles(Dxpscxcommon::TdxCustomcxControlReportLink* AReportLink) : TcxCustomSchedulerReportLinkOptions(AReportLink) { }
	/* TdxCustomReportLinkOptions.Destroy */ inline __fastcall virtual ~TcxSchedulerReportLinkPrintStyles(void) { }
	
};


class PASCALIMPLEMENTATION TcxfmSchedulerReportLinkDesignWindow : public Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow
{
	typedef Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow inherited;
	
__published:
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tshPrintStyles;
	Cxpc::TcxTabSheet* tshStyles;
	Vcl::Extctrls::TBevel* bvlStylesHost;
	Cxdropdownedit::TcxComboBox* cbxStyleSheets;
	Cxcheckbox::TcxCheckBox* chbxUseNativeStyles;
	Vcl::Menus::TPopupMenu* pmStyles;
	Vcl::Menus::TMenuItem* miStyleFont;
	Vcl::Menus::TMenuItem* miStyleColor;
	Vcl::Menus::TMenuItem* miLine3;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmap;
	Vcl::Menus::TMenuItem* miStyleBackgroundBitmapClear;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miStyleRestoreDefaults;
	Vcl::Menus::TMenuItem* milLine;
	Vcl::Menus::TMenuItem* miStylesSelectAll;
	Vcl::Menus::TMenuItem* miLine4;
	Vcl::Menus::TMenuItem* miStylesSaveAs;
	Cximagecombobox::TcxImageComboBox* cbxPrintStyles;
	Cxpc::TcxPageControl* pcPrintStyleOptions;
	Cxpc::TcxTabSheet* tshWeekly;
	Cxpc::TcxTabSheet* tshMonthly;
	Cxpc::TcxTabSheet* tshTrifold;
	Cxpc::TcxTabSheet* tshDetails;
	Cxpc::TcxTabSheet* tshMemo;
	Vcl::Stdctrls::TLabel* lblPrintStyleTrifoldSectionLeft;
	Vcl::Stdctrls::TLabel* lblPrintStyleTrifoldSectionMiddle;
	Vcl::Stdctrls::TLabel* lblPrintStyleTrifoldSectionRight;
	Vcl::Stdctrls::TLabel* lblPrintStyleWeeklyPrintTo;
	Vcl::Stdctrls::TLabel* lblPrintStyleWeeklyPrintFrom;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleWeeklyNotesAreaLined;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleWeeklyNotesAreaBlank;
	Vcl::Stdctrls::TLabel* lblPrintStyleWeeklyInclude;
	Vcl::Stdctrls::TLabel* lblPrintStyleWeeklyLayout;
	Vcl::Stdctrls::TLabel* lblPrintStyleWeeklyArrange;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleWeeklyArrange;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleWeeklyLayout;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleWeeklyTaskPad;
	Cxtimeedit::TcxTimeEdit* tePrintStyleWeeklyPrintFrom;
	Cxtimeedit::TcxTimeEdit* tePrintStyleWeeklyPrintTo;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleMonthlyLayout;
	Vcl::Stdctrls::TLabel* lblPrintStyleMonthlyLayout;
	Vcl::Stdctrls::TLabel* lblPrintStyleMonthlyInclude;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMonthlyTaskPad;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMonthlyNotesAreaBlank;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMonthlyNotesAreaLined;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMonthlyDontPrintWeekends;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMonthlyPrintExactlyOneMonthPerPage;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleWeeklyDontPrintWeekends;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleDetailsUsePagination;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleDetailsPagination;
	Cxpc::TcxTabSheet* tshFormatting;
	Vcl::Extctrls::TImage* imgLookAndFeel;
	Cxdropdownedit::TcxComboBox* cbxLookAndFeel;
	Vcl::Extctrls::TImage* imgRefinements;
	Cxcheckbox::TcxCheckBox* chbxSuppressBackgroundBitmaps;
	Cxpc::TcxTabSheet* tshPrintRange;
	Vcl::Stdctrls::TLabel* lblPrintRangeStart;
	Vcl::Stdctrls::TLabel* lblPrintRangeEnd;
	Cxcalendar::TcxDateEdit* dePrintRangeStart;
	Cxcalendar::TcxDateEdit* dePrintRangeEnd;
	Cxcheckbox::TcxCheckBox* chbxHideDetailsOfPrivateAppointments;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleTrifoldSectionLeft;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleTrifoldSectionMiddle;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleTrifoldSectionRight;
	Cxspinedit::TcxSpinEdit* sePrintStyleMonthlyResourceCountPerPage;
	Vcl::Stdctrls::TLabel* lblPrintStyleMonthlyResourceCountPerPage;
	Vcl::Stdctrls::TLabel* lblPrintStyleWeeklyResourceCountPerPage;
	Cxspinedit::TcxSpinEdit* sePrintStyleWeeklyResourceCountPerPage;
	Cxpc::TcxTabSheet* tshDaily;
	Vcl::Stdctrls::TLabel* lblPrintStyleDailyLayout;
	Vcl::Stdctrls::TLabel* lblPrintStyleDailyInclude;
	Vcl::Stdctrls::TLabel* lblPrintStyleDailyPrintFrom;
	Vcl::Stdctrls::TLabel* lblPrintStyleDailyPrintTo;
	Vcl::Stdctrls::TLabel* lblPrintStyleDailyResourceCountPerPage;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleDailyLayout;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleDailyTaskPad;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleDailyNotesAreaBlank;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleDailyNotesAreaLined;
	Cxtimeedit::TcxTimeEdit* tePrintStyleDailyPrintFrom;
	Cxtimeedit::TcxTimeEdit* tePrintStyleDailyPrintTo;
	Cxspinedit::TcxSpinEdit* sePrintStyleDailyResourceCountPerPage;
	Cxedit::TcxEditStyleController* cxEditStyleController1;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMemoStartEachItemOnNewPage;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMemoPrintOnlySelectedEvents;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleWeeklyDaysLayout;
	Vcl::Stdctrls::TLabel* lblPrintStyleWeeklyDaysLayout;
	Cxpc::TcxTabSheet* tshYearly;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleYearlyMonthPerPage;
	Vcl::Stdctrls::TLabel* lblPrintStyleYearlyMonthPerPage;
	Vcl::Stdctrls::TLabel* lblPrintStyleYearlyResourceCountPerPage;
	Cxspinedit::TcxSpinEdit* sePrintStyleYearlyResourceCountPerPage;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleYearlyTaskPad;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleYearlyNotesAreaBlank;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleYearlyNotesAreaLined;
	Vcl::Stdctrls::TLabel* lblPrintStyleYearlyInclude;
	Cxdropdownedit::TcxComboBox* cbxPrintStyleYearlyLayout;
	Vcl::Stdctrls::TLabel* lblPrintStyleYearlyLayout;
	Cxcheckbox::TcxCheckBox* chbxPrimaryPageHeadersOnly;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleDailyShowResourceImages;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleDailyShowEventImages;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleWeeklyShowEventImages;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleWeeklyShowResourceImages;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMonthlyShowEventImages;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleMonthlyShowResourceImages;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleYearlyShowEventImages;
	Cxpc::TcxTabSheet* tshTimeLine;
	Vcl::Stdctrls::TLabel* lblPrintStyleTimeLineResourceCountPerPage;
	Cxspinedit::TcxSpinEdit* sePrintStyleTimeLineResourceCountPerPage;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLineTaskPad;
	Vcl::Stdctrls::TLabel* lblPrintStyleTimeLineInclude;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLineNotesAreaBlank;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLineNotesAreaLined;
	Cxtimeedit::TcxTimeEdit* tePrintStyleTimeLinePrintFrom;
	Vcl::Stdctrls::TLabel* lblPrintStyleTimeLinePrintFrom;
	Vcl::Stdctrls::TLabel* lblPrintStyleTimeLinePrintTo;
	Cxtimeedit::TcxTimeEdit* tePrintStyleTimeLinePrintTo;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLineShowEventImages;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLinePrimaryPageScalesOnly;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLineDontPrintWeekends;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLineWorkTimeOnly;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLineShowResourceImages;
	Cxcheckbox::TcxCheckBox* chbxPrintStyleTimeLinePrimaryPageHeadersOnly;
	Cxcheckbox::TcxCheckBox* chbxSuppressContentColoration;
	Cxlabel::TcxLabel* lblPrintRangesMiscellaneous;
	Cxlabel::TcxLabel* Label2;
	Cxlabel::TcxLabel* lbTimeLineImages;
	Cxlabel::TcxLabel* lblLookAndFeel;
	Cxlabel::TcxLabel* lblRefinements;
	Cxlabel::TcxLabel* lblUseNativeStyles;
	Cxlabel::TcxLabel* Label1;
	Cxlabel::TcxLabel* lblStyleSheets;
	Cxbuttons::TcxButton* btnStyleColor;
	Cxbuttons::TcxButton* btnStyleFont;
	Cxbuttons::TcxButton* btnStyleBackgroundBitmap;
	Cxbuttons::TcxButton* btnStyleSheetNew;
	Cxbuttons::TcxButton* btnStyleSheetCopy;
	Cxbuttons::TcxButton* btnStyleSheetDelete;
	Cxbuttons::TcxButton* btnStylesSaveAs;
	Cxbuttons::TcxButton* btnStyleSheetRename;
	Cxbuttons::TcxButton* btnStyleBackgroundBitmapClear;
	Cxbuttons::TcxButton* btnStyleRestoreDefaults;
	Cxlabel::TcxLabel* lbViewDaily;
	Cxlabel::TcxLabel* lbImagesDaily;
	Cxlabel::TcxLabel* Label5;
	Cxlabel::TcxLabel* Label6;
	Cxlabel::TcxLabel* Label7;
	Cxlabel::TcxLabel* Label8;
	Cxlabel::TcxLabel* Label9;
	Cxlabel::TcxLabel* Label10;
	Cxlabel::TcxLabel* lblPreviewWindow;
	Vcl::Extctrls::TPanel* pnlPreview;
	Vcl::Extctrls::TPaintBox* pbPreview;
	Cxgroupbox::TcxGroupBox* gbPreview;
	Cxgroupbox::TcxGroupBox* pnlPrintStylesPreview;
	Vcl::Extctrls::TPaintBox* pbxPrintStylesPreview;
	Vcl::Extctrls::TPanel* pnlPrintStylesPreviewContainer;
	Cxgraphics::TcxImageList* ilStylesPopup;
	Cxlabel::TcxLabel* lbOptionsDaily;
	Cxlabel::TcxLabel* lbOptionsDetails;
	Cxlabel::TcxLabel* lbOptionsMemo;
	Cxlabel::TcxLabel* lbOptionsMonthly;
	Cxlabel::TcxLabel* lbOptionsTimeLine;
	Cxlabel::TcxLabel* lbOptionsTrifold;
	Cxlabel::TcxLabel* lbOptionsWeekly;
	Cxlabel::TcxLabel* lbOptionsYear;
	void __fastcall PageControl1Change(System::TObject* Sender);
	void __fastcall lbxStylesClick(System::TObject* Sender);
	void __fastcall btnStyleFontClick(System::TObject* Sender);
	void __fastcall btnStyleColorClick(System::TObject* Sender);
	void __fastcall btnStyleBackgroundBitmapClick(System::TObject* Sender);
	void __fastcall btnStyleBackgroundBitmapClearClick(System::TObject* Sender);
	void __fastcall btnStyleRestoreDefaultsClick(System::TObject* Sender);
	void __fastcall btnStylesSaveAsClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsClick(System::TObject* Sender);
	void __fastcall miStylesSelectAllClick(System::TObject* Sender);
	void __fastcall cbxStyleSheetsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall btnStyleSheetNewClick(System::TObject* Sender);
	void __fastcall btnStyleSheetCopyClick(System::TObject* Sender);
	void __fastcall btnStyleSheetDeleteClick(System::TObject* Sender);
	void __fastcall btnStyleSheetRenameClick(System::TObject* Sender);
	void __fastcall lblUseNativeStylesClick(System::TObject* Sender);
	void __fastcall OptionsFormattingClick(System::TObject* Sender);
	void __fastcall pmStylesPopup(System::TObject* Sender);
	void __fastcall cbxPrintStylesClick(System::TObject* Sender);
	void __fastcall pbxPrintStylesPreviewPaint(System::TObject* Sender);
	void __fastcall cbxPrintStyleDailyLayoutClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleOptionsViewClick(System::TObject* Sender);
	void __fastcall cbxPrintStyleWeeklyArrangeClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleWeeklyDontPrintWeekendsClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleDontPrintWeekEndsClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleMonthlyPrintExactlyOneMonthPerPageClick(System::TObject* Sender);
	void __fastcall cbxPrintStyleTrifoldSectionModeClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleDetailsUsePaginationClick(System::TObject* Sender);
	void __fastcall cbxPrintStyleDetailsPaginationClick(System::TObject* Sender);
	void __fastcall cbxPrintStyleWeeklyLayoutClick(System::TObject* Sender);
	void __fastcall cbxPrintStyleMonthlyLayoutClick(System::TObject* Sender);
	void __fastcall dePrintRangeStartEditValueChanged(System::TObject* Sender);
	void __fastcall dePrintRangeEndEditValueChanged(System::TObject* Sender);
	void __fastcall cbxStyleSheetsPropertiesDrawItem(Cxdropdownedit::TcxCustomComboBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall tePrintStylePrintRangePropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall LookAndFeelChange(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall sePrintStyleResourceCountPerPagePropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall tePrintStylePrintRangePropertiesChange(System::TObject* Sender);
	void __fastcall sePrintStyleResourceCountPerPagePropertiesChanged(System::TObject* Sender);
	void __fastcall StyleController1StyleChanged(System::TObject* Sender);
	void __fastcall pbPreviewPaint(System::TObject* Sender);
	void __fastcall cbxLookAndFeelPropertiesChange(System::TObject* Sender);
	void __fastcall chbxPrintStyleMemoStartEachItemOnNewPageClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleMemoPrintOnlySelectedEventsClick(System::TObject* Sender);
	void __fastcall cbxPrintStyleWeeklyDaysLayoutClick(System::TObject* Sender);
	void __fastcall cbxPrintStyleYearlyLayoutClick(System::TObject* Sender);
	void __fastcall cbxPrintStyleYearlyMonthPagesPerYearClick(System::TObject* Sender);
	void __fastcall chbxPrimaryPageHeadersOnlyClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleShowResourceImagesClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleShowEventImagesClick(System::TObject* Sender);
	void __fastcall chbxPrimaryPageScalesOnlyClick(System::TObject* Sender);
	void __fastcall chbxPrintStyleWorkTimeOnlyClick(System::TObject* Sender);
	
private:
	TcxCustomSchedulerReportLinkPrintStyle* FActiveStyle;
	bool FActiveStyleAssigned;
	bool FIsFormClosing;
	Dxpscxcommon::TdxStylesListBox* lbxStyles;
	System::Classes::TList* wpPrintStyles;
	TcxCustomSchedulerReportLinkPrintStyle* __fastcall GetActivePrintStyle(void);
	Cxstyles::TcxStyle* __fastcall GetActiveStyle(void);
	HIDESBASE Cxscheduler::TcxScheduler* __fastcall GetComponent(void);
	bool __fastcall GetHasSelectedStyles(void);
	bool __fastcall GetHasSelectedStylesWithAssignedBitmap(void);
	HIDESBASE TcxSchedulerReportLink* __fastcall GetReportLink(void);
	bool __fastcall CanSelectAllStyles(void);
	void __fastcall CreateControls(void);
	void __fastcall RecreateStylesListBox(void);
	void __fastcall RestoreSelectedStyles(System::Classes::TList* AList);
	void __fastcall SaveSelectedStyles(System::Classes::TList* AList);
	void __fastcall SetActivePage(void);
	void __fastcall SetOptionsFormattingByIndex(int AnIndex, bool AValue);
	void __fastcall SetPrintStyleOptionsViewByIndex(int AnIndex, bool AValue);
	void __fastcall SetPrintStyleRangeByIndex(int AnIndex, const System::TDateTime ATime);
	void __fastcall SetPrintStyleResourceCountPerPageByIndex(int AnIndex, System::Variant &AValue);
	void __fastcall SetShowImagesCheckBoxes(Cxcheckbox::TcxCheckBox* AEventImages, Cxcheckbox::TcxCheckBox* AResourceImages, TcxCustomSchedulerReportLinkPrintStyle* APrintStyle);
	MESSAGE void __fastcall WMDXCONTAINERSETFOCUS(Winapi::Messages::TMessage &AMessage);
	
protected:
	virtual void __fastcall AssignDailyTabObjects(void);
	virtual void __fastcall AssignDetailsTabObjects(void);
	virtual void __fastcall AssignMemoTabObjects(void);
	virtual void __fastcall AssignMonthlyTabObjects(void);
	virtual void __fastcall AssignTimeLineTabObjects(void);
	virtual void __fastcall AssignTrifoldTabObjects(void);
	virtual void __fastcall AssignWeeklyTabObjects(void);
	virtual void __fastcall AssignYearlyTabObjects(void);
	virtual bool __fastcall CanApply(void);
	virtual void __fastcall DoApply(void);
	virtual void __fastcall DoInitialize(void);
	virtual Vcl::Extctrls::TCustomPanel* __fastcall GetPreviewHost(void);
	virtual bool __fastcall CheckPrintRange(void);
	virtual bool __fastcall CheckPrintStyleSettings(void);
	virtual bool __fastcall IsValidConditions(void);
	void __fastcall HideOptionsButtons(void);
	void __fastcall LoadCaption(Vcl::Controls::TControl* AControl, void * StrPtr)/* overload */;
	void __fastcall LoadCaption(Vcl::Menus::TMenuItem* AItem, void * StrPtr)/* overload */;
	virtual void __fastcall LoadGroupsIcons(void);
	virtual void __fastcall LoadStrings(void);
	void __fastcall LoadStringsCombo(Cxdropdownedit::TcxComboBox* ACombo, void * *ACaptions, const int ACaptions_Size);
	virtual void __fastcall LoadStringsDaily(void);
	virtual void __fastcall LoadStringsDetails(void);
	virtual void __fastcall LoadStringsMemo(void);
	virtual void __fastcall LoadStringsMonthly(void);
	virtual void __fastcall LoadStringsOther(void);
	virtual void __fastcall LoadStringsTimeLineStyle(void);
	virtual void __fastcall LoadStringsTrifold(void);
	virtual void __fastcall LoadStringsWeekly(void);
	virtual void __fastcall LoadStringsYearly(void);
	virtual void __fastcall PreviewDrawPageContent(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ABounds);
	virtual void __fastcall UpdateControlsState(void);
	void __fastcall UpdateEnabled(Vcl::Controls::TControl* AControl, bool AEnabled)/* overload */;
	void __fastcall UpdateEnabled(Vcl::Menus::TMenuItem* AItem, bool AEnabled)/* overload */;
	void __fastcall UpdateEnabledControls(Vcl::Controls::TControl* *AControls, const int AControls_Size, bool AEnabled);
	virtual void __fastcall UpdatePreview(void);
	virtual int __fastcall GetDesignerTabIndex(void);
	virtual void __fastcall SetDesignerTabIndex(int Value);
	DYNAMIC void __fastcall DoActiveStyleSheetChanged(void);
	DYNAMIC void __fastcall DoFormActivated(bool AnActive);
	DYNAMIC void __fastcall DoRefreshStylesList(void);
	DYNAMIC void __fastcall DoStyleChanged(const System::UnicodeString ACaption, Cxstyles::TcxStyle* AStyle);
	DYNAMIC void __fastcall DoStylesChanged(System::Classes::TStrings* AStrings, bool ARecreate);
	virtual void __fastcall GetSelectedStyleNames(System::Classes::TStrings* AStrings);
	virtual void __fastcall GetStyleNames(/* out */ System::Classes::TStrings* &AStrings);
	virtual void __fastcall GetStyleSheetNames(/* out */ System::Classes::TStrings* &AStrings);
	virtual void __fastcall ActivatePrintStyleTab(void);
	virtual void __fastcall AssignTabSheetObjects(void);
	virtual int __fastcall FindTabIndexByPrintStyle(TcxCustomSchedulerReportLinkPrintStyle* APrintStyle);
	virtual void __fastcall RefreshPrintStyles(void);
	__property TcxCustomSchedulerReportLinkPrintStyle* ActivePrintStyle = {read=GetActivePrintStyle};
	__property Cxstyles::TcxStyle* ActiveStyle = {read=GetActiveStyle};
	__property bool HasSelectedStyles = {read=GetHasSelectedStyles, nodefault};
	__property bool HasSelectedStylesWithAssignedBitmap = {read=GetHasSelectedStylesWithAssignedBitmap, nodefault};
	
public:
	__fastcall virtual TcxfmSchedulerReportLinkDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxfmSchedulerReportLinkDesignWindow(void);
	virtual bool __fastcall Execute(void);
	__property Cxscheduler::TcxScheduler* Component = {read=GetComponent};
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxfmSchedulerReportLinkDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxfmSchedulerReportLinkDesignWindow(HWND ParentWindow) : Dxpscxcommon::TdxfmCustomcxControlReportLinkDesignWindow(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportPageSite : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
protected:
	int FPageIndex;
	bool FPrimaryPage;
	virtual void __fastcall ReadProperties(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteProperties(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__property int PageIndex = {read=FPageIndex, nodefault};
	__property bool PrimaryPage = {read=FPrimaryPage, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportPageSite(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TcxSchedulerReportPageSite(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCell(AParent) { }
	
};


class DELPHICLASS TcxSchedulerReportPageItemCell;
class PASCALIMPLEMENTATION TcxSchedulerReportPageItemCell : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
private:
	int __fastcall GetPageIndex(void);
	TcxSchedulerReportPageSite* __fastcall GetPageSite(void);
	bool __fastcall GetPrimaryPage(void);
	HIDESBASE TcxSchedulerReportLink* __fastcall GetReportLink(void);
	
protected:
	virtual TcxSchedulerReportItemsType __fastcall GetType(void);
	void __fastcall SetCellViewParams(Dxpscore::TdxReportVisualItem* AItem, const Cxgraphics::TcxViewParams &AParams)/* overload */;
	void __fastcall SetCellViewParams(Dxpscore::TdxReportVisualItem* AItem, const Dxpscxcommon::TdxReportItemViewParams &AParams)/* overload */;
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
	
public:
	__fastcall virtual TcxSchedulerReportPageItemCell(Dxpscore::TdxReportCell* AParent);
	__property TcxSchedulerReportPageSite* PageSite = {read=GetPageSite};
	__property bool PrimaryPage = {read=GetPrimaryPage, nodefault};
	__property int PageIndex = {read=GetPageIndex, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportPageItemCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportNotesDataCell : public Dxpscore::TAbstractdxReportCellData
{
	typedef Dxpscore::TAbstractdxReportCellData inherited;
	
private:
	System::UnicodeString FCaption;
	int FCaptionHeight;
	bool FLined;
	HIDESBASE bool __fastcall GetMultiLine(void);
	HIDESBASE Cxdrawtextutils::TcxTextAlignX __fastcall GetTextAlignX(void);
	HIDESBASE Cxdrawtextutils::TcxTextAlignY __fastcall GetTextAlignY(void);
	HIDESBASE void __fastcall SetMultiLine(bool Value);
	HIDESBASE void __fastcall SetTextAlignX(Cxdrawtextutils::TcxTextAlignX Value);
	HIDESBASE void __fastcall SetTextAlignY(Cxdrawtextutils::TcxTextAlignY Value);
	
protected:
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportNotesDataCell(Dxpscore::TdxReportCell* AParent);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property int CaptionHeight = {read=FCaptionHeight, write=FCaptionHeight, nodefault};
	__property bool Lined = {read=FLined, write=FLined, nodefault};
	__property bool MultiLine = {read=GetMultiLine, write=SetMultiLine, nodefault};
	__property Cxdrawtextutils::TcxTextAlignX TextAlignX = {read=GetTextAlignX, write=SetTextAlignX, nodefault};
	__property Cxdrawtextutils::TcxTextAlignY TextAlignY = {read=GetTextAlignY, write=SetTextAlignY, nodefault};
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportNotesDataCell(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerReportNotesDataCellClass;

class PASCALIMPLEMENTATION TcxSchedulerReportNotesAreaCell : public TcxSchedulerReportPageItemCell
{
	typedef TcxSchedulerReportPageItemCell inherited;
	
private:
	bool FLined;
	TcxSchedulerReportNotesDataCell* __fastcall GetDataCell(void);
	
protected:
	virtual void __fastcall BoundsChanged(void);
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual TcxSchedulerReportItemsType __fastcall GetType(void);
	virtual TcxSchedulerReportNotesDataCellClass __fastcall GetDataCellClass(void);
	virtual void __fastcall SetFontIndex(int Value);
	
public:
	__fastcall virtual TcxSchedulerReportNotesAreaCell(Dxpscore::TdxReportCell* AParent);
	__fastcall virtual TcxSchedulerReportNotesAreaCell(Dxpscore::TdxReportCell* AParent, bool ALined);
	__property TcxSchedulerReportNotesDataCell* DataCell = {read=GetDataCell};
	__property bool Lined = {read=FLined, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportNotesAreaCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportTaskPadCell : public TcxSchedulerReportNotesAreaCell
{
	typedef TcxSchedulerReportNotesAreaCell inherited;
	
private:
	Dxpscore::TdxReportCell* __fastcall GetTaskPadDataSite(void);
	
protected:
	virtual void __fastcall BoundsChanged(void);
	virtual System::Types::TRect __fastcall CalculateTaskPadDataSiteBounds(void);
	virtual TcxSchedulerReportItemsType __fastcall GetType(void);
	
public:
	__fastcall virtual TcxSchedulerReportTaskPadCell(Dxpscore::TdxReportCell* AParent, bool ALined);
	__property Dxpscore::TdxReportCell* TaskPadDataSite = {read=GetTaskPadDataSite};
public:
	/* TcxSchedulerReportNotesAreaCell.Create */ inline __fastcall virtual TcxSchedulerReportTaskPadCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportNotesAreaCell(AParent) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportTaskPadCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportSchedulerHeaderDataCell : public Dxpscore::TAbstractdxReportCellData
{
	typedef Dxpscore::TAbstractdxReportCellData inherited;
	
public:
	__fastcall virtual TcxSchedulerReportSchedulerHeaderDataCell(Dxpscore::TdxReportCell* AParent);
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportSchedulerHeaderDataCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportSchedulerHeaderCell : public TcxSchedulerReportPageItemCell
{
	typedef TcxSchedulerReportPageItemCell inherited;
	
private:
	TcxSchedulerReportSchedulerHeaderDataCell* FContent;
	System::TDateTime FDate;
	System::UnicodeString FPrimaryText;
	System::UnicodeString FSecondaryText;
	Dxpscore::TdxReportCellString* FPrimaryTextCell;
	Dxpscore::TdxReportCellString* FSecondaryTextCell;
	
protected:
	virtual TcxSchedulerReportSchedulerHeaderDataCell* __fastcall AddContentCell(void);
	Dxpscore::TdxReportCellString* __fastcall AddTextCell(System::UnicodeString AText, const System::Types::TRect &ABounds, bool AMultiLine);
	virtual TcxSchedulerReportItemsType __fastcall GetType(void);
	__property System::TDateTime Date = {read=FDate, write=FDate};
	__property System::UnicodeString PrimaryText = {read=FPrimaryText, write=FPrimaryText};
	__property System::UnicodeString SecondaryText = {read=FSecondaryText, write=FSecondaryText};
	
public:
	__fastcall virtual TcxSchedulerReportSchedulerHeaderCell(Dxpscore::TdxReportCell* AParent);
	void __fastcall AdjustTextSize(void);
	__property TcxSchedulerReportSchedulerHeaderDataCell* Content = {read=FContent};
	__property Dxpscore::TdxReportCellString* PrimaryTextCell = {read=FPrimaryTextCell};
	__property Dxpscore::TdxReportCellString* SecondaryTextCell = {read=FSecondaryTextCell};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportSchedulerHeaderCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportDateNavigatorItem;
class PASCALIMPLEMENTATION TcxSchedulerReportDateNavigatorItem : public Dxpscxcommon::TdxReportCellPreviewText
{
	typedef Dxpscxcommon::TdxReportCellPreviewText inherited;
	
private:
	TcxSchedulerReportDateNavigatorCell* __fastcall GetDateNavigator(void);
	
protected:
	virtual unsigned __fastcall GetDefaultDTFormat(void);
	virtual void __fastcall SetText(const System::UnicodeString Value);
	
public:
	__fastcall virtual TcxSchedulerReportDateNavigatorItem(Dxpscore::TdxReportCell* AParent);
	__property TcxSchedulerReportDateNavigatorCell* DateNavigator = {read=GetDateNavigator};
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDateNavigatorItem(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportDateNavigatorHeader : public TcxSchedulerReportDateNavigatorItem
{
	typedef TcxSchedulerReportDateNavigatorItem inherited;
	
private:
	System::Word FMonth;
	System::Word FYear;
	
protected:
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall TcxSchedulerReportDateNavigatorHeader(Dxpscore::TdxReportCell* AParent, System::Word AYear, System::Word AMonth);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::Word Month = {read=FMonth, nodefault};
	__property System::Word Year = {read=FYear, nodefault};
public:
	/* TcxSchedulerReportDateNavigatorItem.Create */ inline __fastcall virtual TcxSchedulerReportDateNavigatorHeader(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportDateNavigatorItem(AParent) { }
	
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDateNavigatorHeader(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportDateNavigatorDay : public TcxSchedulerReportDateNavigatorItem
{
	typedef TcxSchedulerReportDateNavigatorItem inherited;
	
private:
	int FDay;
	int FCol;
	int FRow;
	bool __fastcall GetBold(void);
	System::TDate __fastcall GetDate(void);
	System::Word __fastcall GetMonth(void);
	System::Word __fastcall GetYear(void);
	void __fastcall SetBold(bool Value);
	
protected:
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportDateNavigatorDay(Dxpscore::TdxReportCell* AParent, int ADay, int ACol, int ARow, bool ABold);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int Col = {read=FCol, nodefault};
	__property System::TDate Date = {read=GetDate};
	__property int Day = {read=FDay, write=FDay, nodefault};
	__property bool Bold = {read=GetBold, write=SetBold, nodefault};
	__property System::Word Month = {read=GetMonth, nodefault};
	__property int Row = {read=FRow, nodefault};
	__property System::Word Year = {read=GetYear, nodefault};
public:
	/* TcxSchedulerReportDateNavigatorItem.Create */ inline __fastcall virtual TcxSchedulerReportDateNavigatorDay(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportDateNavigatorItem(AParent) { }
	
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDateNavigatorDay(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportDateNavigatorDayCaption : public TcxSchedulerReportDateNavigatorItem
{
	typedef TcxSchedulerReportDateNavigatorItem inherited;
	
private:
	int FCol;
	Cxdateutils::TDay FDayOfWeek;
	System::UnicodeString FDayText;
	
protected:
	virtual System::UnicodeString __fastcall GetText(void);
	virtual System::UnicodeString __fastcall GetDayText(void);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportDateNavigatorDayCaption(Dxpscore::TdxReportCell* AParent, Cxdateutils::TDay ADayOfWeek, int ACol);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int Col = {read=FCol, nodefault};
	__property Cxdateutils::TDay DayOfWeek = {read=FDayOfWeek, nodefault};
public:
	/* TcxSchedulerReportDateNavigatorItem.Create */ inline __fastcall virtual TcxSchedulerReportDateNavigatorDayCaption(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportDateNavigatorItem(AParent) { }
	
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDateNavigatorDayCaption(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportDateNavigatorWeekNumber : public TcxSchedulerReportDateNavigatorItem
{
	typedef TcxSchedulerReportDateNavigatorItem inherited;
	
private:
	int FWeekNumber;
	int FRow;
	
protected:
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportDateNavigatorWeekNumber(Dxpscore::TdxReportCell* AParent, int AWeekNumber, int ARow);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int Row = {read=FRow, nodefault};
	__property int WeekNumber = {read=FWeekNumber, write=FWeekNumber, nodefault};
public:
	/* TcxSchedulerReportDateNavigatorItem.Create */ inline __fastcall virtual TcxSchedulerReportDateNavigatorWeekNumber(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportDateNavigatorItem(AParent) { }
	
public:
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDateNavigatorWeekNumber(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportDateNavigatorCell : public TcxSchedulerReportPageItemCell
{
	typedef TcxSchedulerReportPageItemCell inherited;
	
private:
	Cxschedulerutils::TcxSchedulerDateList* FBoldedDays;
	Cxdateutils::TcxFirstWeekOfYear FFirstWeekOfYear;
	System::Word FMonth;
	bool FShowDatesContainingEventsInBold;
	bool FShowWeekNumbers;
	Cxdateutils::TDay FStartOfWeek;
	System::Word FYear;
	int FColWidth;
	int FDayCaptionsHeight;
	int FHeaderHeight;
	System::Types::TSize FMonthSize;
	int FRowHeight;
	int FVertOffset;
	Dxpscxcommon::TdxReportItemViewParams FContentParams;
	Dxpscxcommon::TdxReportItemViewParams FHeaderParams;
	int FDayCaptionCount;
	int FDayCount;
	int FWeekNumberCount;
	__classmethod int __fastcall GetMonthHeight(int AHeaderHeight, int ADayCaptionsHeight, int ARowHeight);
	TcxSchedulerReportDateNavigatorDay* __fastcall GetDay(int Index);
	TcxSchedulerReportDateNavigatorDayCaption* __fastcall GetDayCaption(int Index);
	TcxSchedulerReportDateNavigatorHeader* __fastcall GetHeader(void);
	TcxSchedulerReportDateNavigatorWeekNumber* __fastcall GetWeekNumber(int Index);
	
protected:
	void __fastcall AdjustItemsVertical(void);
	int __fastcall ColOfDate(System::TDateTime ADate);
	virtual void __fastcall CreateDayCaptions(void);
	virtual void __fastcall CreateDay(const System::Types::TRect &ABounds, System::TDateTime ADate, int ACol, int ARow);
	void __fastcall CreateItems(void);
	virtual void __fastcall CreateLines(void);
	virtual void __fastcall CreateMonth(void);
	virtual void __fastcall CreateMonthHeader(void);
	virtual void __fastcall CreateWeekNumber(const System::Types::TRect &ABounds, System::TDateTime ADate, int ARow);
	__classmethod virtual void __fastcall GetContentPartSizes(Vcl::Graphics::TFont* AFont, int &AColWidth, int &ARowHeight, int &ADayCaptionsHeight, int AFontSize = 0x0);
	virtual System::Types::TRect __fastcall GetDayBoundsFromColAndRow(int ACol, int ARow);
	virtual bool __fastcall GetDayIsBold(System::TDateTime ADate);
	virtual System::Types::TRect __fastcall GetHeaderBounds(void);
	__classmethod virtual void __fastcall GetHeaderPartSizes(Vcl::Graphics::TFont* AFont, int &AHeaderHeight, int AFontSize = 0x0);
	System::Types::TSize __fastcall GetMonthSize(const Dxpscxcommon::TdxReportItemViewParams &AContentParams, const Dxpscxcommon::TdxReportItemViewParams &AHeaderParams);
	virtual TcxSchedulerReportItemsType __fastcall GetType(void);
	virtual void __fastcall SetViewParams(const Dxpscxcommon::TdxReportItemViewParams &AContentParams, const Dxpscxcommon::TdxReportItemViewParams &AHeaderParams);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	__property int ColWidth = {read=FColWidth, nodefault};
	__property int DayCaptionsHeight = {read=FDayCaptionsHeight, nodefault};
	__property int HeaderHeight = {read=FHeaderHeight, nodefault};
	__property System::Types::TSize MonthSize = {read=FMonthSize};
	__property int RowHeight = {read=FRowHeight, nodefault};
	__property Dxpscxcommon::TdxReportItemViewParams ContentParams = {read=FContentParams};
	__property Dxpscxcommon::TdxReportItemViewParams HeaderParams = {read=FHeaderParams};
	
public:
	__fastcall virtual TcxSchedulerReportDateNavigatorCell(Dxpscore::TdxReportCell* AParent);
	__fastcall virtual TcxSchedulerReportDateNavigatorCell(Dxpscore::TdxReportCell* AParent, Cxdateutils::TcxFirstWeekOfYear AFirstWeekOfYear, System::Word AYear, System::Word AMonth, bool AShowDatesContainingEventsInBold, bool AShowWeekNumbers);
	virtual void __fastcall AdjustSize(Dxpscxcommon::TdxReportItemViewParams &AContentParams, Dxpscxcommon::TdxReportItemViewParams &AHeaderParams, int AHeight, int AMaxHeight);
	System::Types::TSize __fastcall CalculateSize(const Dxpscxcommon::TdxReportItemViewParams &AContentParams, const Dxpscxcommon::TdxReportItemViewParams &AHeaderParams);
	__classmethod virtual int __fastcall MeasureDateNavigatorHeight(const Cxgraphics::TcxViewParams &AContentParams, const Cxgraphics::TcxViewParams &AHeaderParams);
	__property Cxdateutils::TcxFirstWeekOfYear FirstWeekOfYear = {read=FFirstWeekOfYear, write=FFirstWeekOfYear, nodefault};
	__property System::Word Month = {read=FMonth, write=FMonth, nodefault};
	__property bool ShowDatesContainingEventsInBold = {read=FShowDatesContainingEventsInBold, write=FShowDatesContainingEventsInBold, nodefault};
	__property bool ShowWeekNumbers = {read=FShowWeekNumbers, write=FShowWeekNumbers, nodefault};
	__property Cxdateutils::TDay StartOfWeek = {read=FStartOfWeek, nodefault};
	__property System::Word Year = {read=FYear, write=FYear, nodefault};
	__property int DayCaptionCount = {read=FDayCaptionCount, nodefault};
	__property TcxSchedulerReportDateNavigatorDayCaption* DayCaptions[int Index] = {read=GetDayCaption};
	__property int DayCount = {read=FDayCount, nodefault};
	__property TcxSchedulerReportDateNavigatorDay* Days[int Index] = {read=GetDay};
	__property TcxSchedulerReportDateNavigatorHeader* Header = {read=GetHeader};
	__property int WeekNumberCount = {read=FWeekNumberCount, nodefault};
	__property TcxSchedulerReportDateNavigatorWeekNumber* WeekNumbers[int Index] = {read=GetWeekNumber};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDateNavigatorCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportSchedulingAreaCell : public TcxSchedulerReportPageItemCell
{
	typedef TcxSchedulerReportPageItemCell inherited;
	
private:
	Cxschedulerutils::TcxSchedulerDateList* FVisibleDays;
	System::Classes::TStringList* FDaysList;
	
protected:
	virtual TcxSchedulerReportItemsType __fastcall GetType(void);
	__property Cxschedulerutils::TcxSchedulerDateList* VisibleDays = {read=FVisibleDays};
	
public:
	__fastcall virtual TcxSchedulerReportSchedulingAreaCell(Dxpscore::TdxReportCell* AParent);
	__fastcall virtual ~TcxSchedulerReportSchedulingAreaCell(void);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &DrawRect, const System::Types::TRect &OriginRect, Dxpscore::TdxPSRenderStages AStage);
	virtual void __fastcall DrawItself(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
};


class DELPHICLASS TcxSchedulerReportCustomCell;
class PASCALIMPLEMENTATION TcxSchedulerReportCustomCell : public Dxpscore::TAbstractdxReportCellData
{
	typedef Dxpscore::TAbstractdxReportCellData inherited;
	
private:
	HIDESBASE TcxSchedulerReportLink* __fastcall GetReportLink(void);
	
protected:
	System::TDateTime FDateTime;
	System::Uitypes::TColor FDayBorderColor;
	bool FNoClip;
	void __fastcall DrawCellFrame(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ALineWidth = 0x1);
	void __fastcall DrawCellRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x20000000), int ALineWidth = 0x1, System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000));
	void __fastcall DrawCellText(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &ARect, const System::UnicodeString AText, Cxdrawtextutils::TcxTextAlignX AlignHorz, Cxdrawtextutils::TcxTextAlignY AlignVert, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), System::Uitypes::TColor AColor = (System::Uitypes::TColor)(0x20000000), bool AMultiLine = false);
	void __fastcall DrawCellTextVert(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &ARect, const System::UnicodeString AText, Cxdrawtextutils::TcxTextAlignX AlignHorz, Cxdrawtextutils::TcxTextAlignY AlignVert, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0), bool AMultiLine = true);
	void __fastcall DrawCellState(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &R, int AState, Cxgraphics::TcxBorders ABorders = Cxgraphics::TcxBorders() , System::Uitypes::TColor ABorderColor = (System::Uitypes::TColor)(0x0));
	System::Types::TRect __fastcall AdjustTextRect(const System::Types::TRect &ARect);
	System::Types::TRect __fastcall ExcludeBorders(const System::Types::TRect &ARect, Cxgraphics::TcxBorders ABorders, int ABorderWidth = 0x1);
	int __fastcall FixupWidth(int AWidth);
	System::Types::TRect __fastcall GetFixupRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &ARect);
	System::Types::TRect __fastcall InflateRect(const System::Types::TRect &ARect, int dX, int dY);
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
	
public:
	__fastcall virtual TcxSchedulerReportCustomCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__classmethod virtual void __fastcall RegisterMirrorClass();
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
	virtual void __fastcall SuppressColoration(void);
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportCustomCell(Dxpscore::TdxReportCell* AParent) : Dxpscore::TAbstractdxReportCellData(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportCustomCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportContentCell : public TcxSchedulerReportCustomCell
{
	typedef TcxSchedulerReportCustomCell inherited;
	
protected:
	System::Uitypes::TColor FBorderColor;
	bool FShowTimeLine;
	int FState;
	Cxgraphics::TcxBorders FTimeLineBorders;
	virtual bool __fastcall HasBorderColoration(void);
	
public:
	__fastcall virtual TcxSchedulerReportContentCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
	virtual void __fastcall SuppressColoration(void);
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportContentCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportContentCell(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportHeaderItemCell : public TcxSchedulerReportCustomCell
{
	typedef TcxSchedulerReportCustomCell inherited;
	
private:
	System::UnicodeString FCaption;
	System::TDateTime FDate;
	bool FIsResourceHeader;
	System::Variant FResourceID;
	bool FRotateText;
	int FImageIndex;
	Vcl::Imglist::TCustomImageList* FImages;
	System::Types::TRect FImageRect;
	System::Types::TRect FTextRect;
	HIDESBASE Cxdrawtextutils::TcxTextAlignX __fastcall GetTextAlignX(void);
	HIDESBASE Cxdrawtextutils::TcxTextAlignY __fastcall GetTextAlignY(void);
	HIDESBASE void __fastcall SetTextAlignX(Cxdrawtextutils::TcxTextAlignX Value);
	HIDESBASE void __fastcall SetTextAlignY(Cxdrawtextutils::TcxTextAlignY Value);
	
protected:
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual bool __fastcall HasImage(void);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportHeaderItemCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	void __fastcall DrawImage(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
	__property Cxdrawtextutils::TcxTextAlignX TextAlignX = {read=GetTextAlignX, write=SetTextAlignX, nodefault};
	__property Cxdrawtextutils::TcxTextAlignY TextAlignY = {read=GetTextAlignY, write=SetTextAlignY, nodefault};
	__property System::Types::TRect TextRect = {read=FTextRect};
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
	__property System::TDateTime Date = {read=FDate};
	__property int ImageIndex = {read=FImageIndex, nodefault};
	__property System::Types::TRect ImageRect = {read=FImageRect};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages};
	__property bool IsResourceHeader = {read=FIsResourceHeader, nodefault};
	__property System::Variant ResourceID = {read=FResourceID};
	__property bool RotateText = {read=FRotateText, nodefault};
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportHeaderItemCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportHeaderItemCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportGroupSeparatorCell;
class PASCALIMPLEMENTATION TcxSchedulerReportGroupSeparatorCell : public TcxSchedulerReportCustomCell
{
	typedef TcxSchedulerReportCustomCell inherited;
	
public:
	__fastcall virtual TcxSchedulerReportGroupSeparatorCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportGroupSeparatorCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportGroupSeparatorCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportContainerCell;
class PASCALIMPLEMENTATION TcxSchedulerReportContainerCell : public TcxSchedulerReportCustomCell
{
	typedef TcxSchedulerReportCustomCell inherited;
	
public:
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
public:
	/* TcxSchedulerReportCustomCell.CreateFrom */ inline __fastcall virtual TcxSchedulerReportContainerCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo) : TcxSchedulerReportCustomCell(AParent, AViewInfo) { }
	
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportContainerCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportContainerCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportTextCell;
class PASCALIMPLEMENTATION TcxSchedulerReportTextCell : public TcxSchedulerReportCustomCell
{
	typedef TcxSchedulerReportCustomCell inherited;
	
protected:
	System::UnicodeString FDisplayText;
	System::Types::TRect FTextRect;
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportTextCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=FDisplayText};
	__property System::Types::TRect TextRect = {read=FTextRect, write=FTextRect};
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportTextCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportTextCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportBackgroundSlotCell;
class PASCALIMPLEMENTATION TcxSchedulerReportBackgroundSlotCell : public TcxSchedulerReportTextCell
{
	typedef TcxSchedulerReportTextCell inherited;
	
public:
	__fastcall virtual TcxSchedulerReportBackgroundSlotCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportBackgroundSlotCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportTextCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportBackgroundSlotCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportTimeLineMinorScaleCell;
class PASCALIMPLEMENTATION TcxSchedulerReportTimeLineMinorScaleCell : public TcxSchedulerReportBackgroundSlotCell
{
	typedef TcxSchedulerReportBackgroundSlotCell inherited;
	
public:
	__fastcall virtual TcxSchedulerReportTimeLineMinorScaleCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportTimeLineMinorScaleCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportBackgroundSlotCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportTimeLineMinorScaleCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportTimeLineMajorScaleCell;
class PASCALIMPLEMENTATION TcxSchedulerReportTimeLineMajorScaleCell : public TcxSchedulerReportBackgroundSlotCell
{
	typedef TcxSchedulerReportBackgroundSlotCell inherited;
	
public:
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
public:
	/* TcxSchedulerReportBackgroundSlotCell.CreateFrom */ inline __fastcall virtual TcxSchedulerReportTimeLineMajorScaleCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo) : TcxSchedulerReportBackgroundSlotCell(AParent, AViewInfo) { }
	
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportTimeLineMajorScaleCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportBackgroundSlotCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportTimeLineMajorScaleCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportDailyTimeRulerCellsSite;
class PASCALIMPLEMENTATION TcxSchedulerReportDailyTimeRulerCellsSite : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
private:
	Vcl::Graphics::TFont* FLargeFont;
	int FLargeFontIndex;
	Vcl::Graphics::TFont* __fastcall GetLargeFont(void);
	
protected:
	virtual void __fastcall SetFontIndex(int Index);
	virtual void __fastcall ReadProperties(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteProperties(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportDailyTimeRulerCellsSite(Dxpscore::TdxReportCell* AParent);
	__fastcall virtual ~TcxSchedulerReportDailyTimeRulerCellsSite(void);
	__property Vcl::Graphics::TFont* LargeFont = {read=GetLargeFont};
};


class PASCALIMPLEMENTATION TcxSchedulerReportDailyTimeRulerCell : public TcxSchedulerReportCustomCell
{
	typedef TcxSchedulerReportCustomCell inherited;
	
private:
	typedef System::StaticArray<System::UnicodeString, 2> _TcxSchedulerReportDailyTimeRulerCell__1;
	
	
private:
	System::Types::TRect __fastcall GetBoundsRect(bool AType);
	System::UnicodeString __fastcall GetDisplayText(bool AType);
	Vcl::Graphics::TFont* __fastcall GetLargeFont(void);
	TcxSchedulerReportDailyTimeRulerCellsSite* __fastcall GetTimeRulerSite(void);
	
protected:
	System::StaticArray<System::Types::TRect, 2> FBounds;
	_TcxSchedulerReportDailyTimeRulerCell__1 FDisplayTexts;
	bool FHasAdditionalTimeZone;
	int FHour;
	System::Uitypes::TColor FLineColor;
	int FLineCount;
	bool FShowMinutes;
	void __fastcall CalculateDisplayInfo(void);
	virtual void __fastcall DrawTimeZone(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, bool AIsCurrent);
	virtual void __fastcall DrawTimeZoneLabel(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString AText, Cxgraphics::TcxBorders ABorders);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	__property Vcl::Graphics::TFont* LargeFont = {read=GetLargeFont};
	
public:
	__fastcall virtual TcxSchedulerReportDailyTimeRulerCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
	virtual void __fastcall SuppressColoration(void);
	__property System::Types::TRect Bounds[bool ACurrentTimeZone] = {read=GetBoundsRect};
	__property System::UnicodeString DisplayTexts[bool ACurrentTimeZone] = {read=GetDisplayText};
	__property bool HasAdditionalTimeZone = {read=FHasAdditionalTimeZone, nodefault};
	__property int Hour = {read=FHour, nodefault};
	__property int LineCount = {read=FLineCount, nodefault};
	__property bool ShowMinutes = {read=FShowMinutes, nodefault};
	__property TcxSchedulerReportDailyTimeRulerCellsSite* TimeRulerSite = {read=GetTimeRulerSite};
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportDailyTimeRulerCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDailyTimeRulerCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportMonthDayCell;
class PASCALIMPLEMENTATION TcxSchedulerReportMonthDayCell : public TcxSchedulerReportContentCell
{
	typedef TcxSchedulerReportContentCell inherited;
	
private:
	bool FSmallFont;
	System::UnicodeString FDisplayText;
	bool FDontPrint;
	
protected:
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportMonthDayCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
	__property System::UnicodeString DisplayText = {read=FDisplayText, write=FDisplayText};
	__property bool SmallFont = {read=FSmallFont, write=FSmallFont, nodefault};
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportMonthDayCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportContentCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportMonthDayCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportTimeLinePart;
class PASCALIMPLEMENTATION TcxSchedulerReportTimeLinePart : public Dxpscore::TdxReportCellBox
{
	typedef Dxpscore::TdxReportCellBox inherited;
	
private:
	int FState;
	bool FTriangle;
	
protected:
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	__property int State = {read=FState, write=FState, nodefault};
	
public:
	__fastcall TcxSchedulerReportTimeLinePart(Dxpscore::TdxReportCell* AParent, bool ATriangle, int AState);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportTimeLinePart(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCellBox(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportTimeLinePart(void) { }
	
};


class DELPHICLASS TcxSchedulerReportTimeLineCell;
class PASCALIMPLEMENTATION TcxSchedulerReportTimeLineCell : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
private:
	Dxpscore::TAbstractdxReportCellData* FCurrentValue;
	
public:
	__fastcall virtual TcxSchedulerReportTimeLineCell(Dxpscore::TdxReportCell* AParent);
	void __fastcall SetTimeRect(const System::Types::TRect &ABounds, int AState);
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportTimeLineCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportCellString;
class PASCALIMPLEMENTATION TcxSchedulerReportCellString : public Dxpscore::TdxReportCellString
{
	typedef Dxpscore::TdxReportCellString inherited;
	
protected:
	virtual unsigned __fastcall GetDefaultDTFormat(void);
public:
	/* TdxReportCellText.Create */ inline __fastcall virtual TcxSchedulerReportCellString(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCellString(AParent) { }
	/* TdxReportCellText.Destroy */ inline __fastcall virtual ~TcxSchedulerReportCellString(void) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportCustomEventCell : public Dxpscore::TdxReportCell
{
	typedef Dxpscore::TdxReportCell inherited;
	
private:
	TcxCustomSchedulerReportLinkPrintStyle* __fastcall GetPrintStyle(void);
	HIDESBASE TcxSchedulerReportLink* __fastcall GetReportLink(void);
	bool __fastcall GetSuppressColoration(void);
	
protected:
	Dxpscore::TdxReportCellString* FCaptionCell;
	Dxpscore::TAbstractdxReportCellData* FMessageCell;
	Dxpscore::TdxReportCellString* FStartCell;
	Dxpscore::TdxReportCellString* FFinishCell;
	TcxSchedulerReportTimeLineCell* FTimeLineCell;
	virtual void __fastcall CreateMessageCell(Cxedit::TcxCustomEditProperties* AProperties);
	virtual System::Variant __fastcall GetMessage(void);
	virtual Dxpscore::TdxReportCellDataClass __fastcall GetMessageClass(Cxedit::TcxCustomEditProperties* AProperties);
	virtual System::Variant __fastcall GetValidMessage(const System::Variant &AMessage, Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall InitializeMessageCell(Cxedit::TcxCustomEditProperties* AProperties, const Cxgraphics::TcxViewParams &AViewParams);
	virtual bool __fastcall NeedExtractPlainTextForMessage(Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall SetViewParams(const Cxgraphics::TcxViewParams &AViewParams);
	
public:
	virtual Dxpscore::TdxReportCellString* __fastcall CreateStringCell(const System::UnicodeString AText, bool AMultiline = true, int AData = 0x0);
	__property Dxpscore::TdxReportCellString* CaptionCell = {read=FCaptionCell};
	__property Dxpscore::TdxReportCellString* StartCell = {read=FStartCell};
	__property Dxpscore::TdxReportCellString* FinishCell = {read=FFinishCell};
	__property Dxpscore::TAbstractdxReportCellData* MessageCell = {read=FMessageCell};
	__property TcxCustomSchedulerReportLinkPrintStyle* PrintStyle = {read=GetPrintStyle};
	__property TcxSchedulerReportLink* ReportLink = {read=GetReportLink};
	__property TcxSchedulerReportTimeLineCell* TimeLineCell = {read=FTimeLineCell};
	__property bool SuppressColoration = {read=GetSuppressColoration, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportCustomEventCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TcxSchedulerReportCustomEventCell(Dxpscore::TdxReportCell* AParent) : Dxpscore::TdxReportCell(AParent) { }
	
};


class DELPHICLASS TcxSchedulerReportEventCell;
class PASCALIMPLEMENTATION TcxSchedulerReportEventCell : public TcxSchedulerReportCustomEventCell
{
	typedef TcxSchedulerReportCustomEventCell inherited;
	
private:
	int FCaptionLeft;
	System::Types::TRect FContentBounds;
	Cxedit::TcxCustomEditProperties* FEditProperties;
	Cxedit::TcxCustomEditViewInfo* FEditViewInfo;
	Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* FEventViewInfo;
	bool FHasDetailInfo;
	bool FHasImages;
	bool FHasMessage;
	bool FIsHeaderEvent;
	bool FIsNeedCreateTimeCells;
	System::Types::TPoint FOrigin;
	void __fastcall CheckBounds(System::Types::TRect &ABounds);
	Cxschedulerstorage::TcxSchedulerControlEvent* __fastcall GetEvent(void);
	
protected:
	virtual void __fastcall AdjustItemsHeight(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual void __fastcall CalculateLayout(void);
	virtual void __fastcall CalculateTimeLine(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual Dxpscore::TdxReportCellString* __fastcall CreateCaptionCell(void);
	virtual void __fastcall CreateDataItems(void);
	virtual void __fastcall CreateEventImageCells(void);
	virtual TcxSchedulerReportTimeLineCell* __fastcall CreateTimeLineCell(void);
	virtual Dxpscore::TdxReportCellString* __fastcall CreateTimeTextCell(const System::UnicodeString ATimeText, int AData = 0x0);
	virtual void __fastcall DoInitializeFromViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo);
	virtual System::Types::TRect __fastcall GetCaptionRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual System::Types::TRect __fastcall GetContentBounds(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	virtual bool __fastcall GetHasImages(void);
	virtual bool __fastcall GetHasMessage(void);
	virtual System::Variant __fastcall GetMessage(void);
	virtual System::Types::TRect __fastcall GetMessageRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	System::Types::TRect __fastcall GetRelativeRect(const System::Types::TRect &R);
	virtual System::Types::TRect __fastcall GetTimeLineRect(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas);
	void __fastcall InitializeFromViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo);
	virtual void __fastcall InitializeMessageCell(Cxedit::TcxCustomEditProperties* AProperties, const Cxgraphics::TcxViewParams &AViewParams);
	virtual void __fastcall SetViewParams(const Cxgraphics::TcxViewParams &AViewParams);
	__property System::Types::TRect ContentBounds = {read=FContentBounds};
	__property Cxedit::TcxCustomEditProperties* EditProperties = {read=FEditProperties};
	__property Cxschedulerstorage::TcxSchedulerControlEvent* Event = {read=GetEvent};
	__property Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* EventViewInfo = {read=FEventViewInfo};
	__property bool HasDetailInfo = {read=FHasDetailInfo, nodefault};
	__property bool HasImages = {read=FHasImages, nodefault};
	__property bool IsHeaderEvent = {read=FIsHeaderEvent, nodefault};
	__property bool IsNeedCreateTimeCells = {read=FIsNeedCreateTimeCells, nodefault};
	
public:
	__fastcall virtual TcxSchedulerReportEventCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo);
	__property Dxpscore::TdxReportCellString* CaptionCell = {read=FCaptionCell};
	__property bool HasMessage = {read=FHasMessage, nodefault};
	__property System::Variant Message = {read=GetMessage};
	__property MessageCell;
	__property TimeLineCell;
	__property StartCell;
	__property FinishCell;
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportEventCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TcxSchedulerReportEventCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomEventCell(AParent) { }
	
};


typedef System::TMetaClass* TcxSchedulerReportEventCellClass;

class PASCALIMPLEMENTATION TcxSchedulerReportDetailsEventCell : public TcxSchedulerReportCustomEventCell
{
	typedef TcxSchedulerReportCustomEventCell inherited;
	
protected:
	bool FContinued;
	System::TDateTime FDate;
	Cxedit::TcxCustomEditProperties* FEditProperties;
	Cxschedulerstorage::TcxSchedulerEvent* FEvent;
	int FLineHeight;
	Cxgraphics::TcxViewParams FViewParams;
	virtual void __fastcall CreateCaptionCell(void);
	virtual void __fastcall CreateDataItems(void);
	virtual void __fastcall CreateMessageCell(Cxedit::TcxCustomEditProperties* AProperties);
	virtual void __fastcall CreateTimeCell(void);
	virtual System::UnicodeString __fastcall GetCaptionCellText(void);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetEditProperties(void);
	virtual System::Variant __fastcall GetMessage(void);
	virtual System::UnicodeString __fastcall GetTimeCellText(void);
	virtual void __fastcall SetViewParams(const Cxgraphics::TcxViewParams &AViewParams);
	__property Cxedit::TcxCustomEditProperties* EditProperties = {read=FEditProperties};
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams};
	
public:
	__fastcall TcxSchedulerReportDetailsEventCell(Dxpscore::TdxReportCell* AParent, Cxschedulerstorage::TcxSchedulerEvent* AEvent, System::TDateTime ADate, const Cxgraphics::TcxViewParams &AParams, bool AContinued);
	virtual int __fastcall CalculateHeight(void);
	virtual void __fastcall CalculateLayout(int AWidth, int ATimeWidth);
	__property System::TDateTime Date = {read=FDate};
	__property Cxschedulerstorage::TcxSchedulerEvent* Event = {read=FEvent};
	__property bool Continued = {read=FContinued, nodefault};
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDetailsEventCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TcxSchedulerReportDetailsEventCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomEventCell(AParent) { }
	
};


class DELPHICLASS TcxSchedulerReportMemoEventCell;
class PASCALIMPLEMENTATION TcxSchedulerReportMemoEventCell : public TcxSchedulerReportDetailsEventCell
{
	typedef TcxSchedulerReportDetailsEventCell inherited;
	
protected:
	Dxpscore::TdxReportCellString* FCaptionLabelCell;
	Dxpscore::TdxReportCellString* FHeaderCell;
	Dxpscore::TdxReportCellString* FLocationCell;
	Dxpscore::TdxReportCellString* FLocationLabelCell;
	Dxpscore::TdxReportCellString* FShowTimeAsCell;
	Dxpscore::TdxReportCellString* FShowTimeAsLabelCell;
	Dxpscore::TdxReportCellString* FStartLabelCell;
	Dxpscore::TdxReportCellString* FFinishLabelCell;
	Dxpscore::TdxReportCellString* FRecurrenceCell;
	Dxpscore::TdxReportCellString* FRecurrenceLabelCell;
	Dxpscore::TdxReportCellString* FRecurrencePatternCell;
	Dxpscore::TdxReportCellString* FRecurrencePatternLabelCell;
	virtual void __fastcall CreateDataItems(void);
	virtual System::UnicodeString __fastcall GetCaptionCellText(void);
	virtual System::UnicodeString __fastcall GetTimeCellText(void);
	virtual void __fastcall SetViewParams(const Cxgraphics::TcxViewParams &AViewParams);
	virtual void __fastcall CalculateLabelAndData(Dxpscore::TAbstractdxReportCellData* ALabelCell, Dxpscore::TAbstractdxReportCellData* ADataCell, Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, int ATimeWidth, int AWidth, int &ATop);
	virtual void __fastcall CreateHeader(void);
	virtual void __fastcall CreateFinish(void);
	virtual void __fastcall CreateFinishCell(void);
	virtual void __fastcall CreateFinishLabelCell(void);
	virtual void __fastcall CreateLocation(void);
	virtual void __fastcall CreateLocationCell(void);
	virtual void __fastcall CreateLocationLabelCell(void);
	virtual void __fastcall CreateMessage(void);
	virtual void __fastcall CreateRecurrence(void);
	virtual void __fastcall CreateRecurrenceCell(void);
	virtual void __fastcall CreateRecurrenceLabelCell(void);
	virtual void __fastcall CreateRecurrencePattern(void);
	virtual void __fastcall CreateRecurrencePatternCell(void);
	virtual void __fastcall CreateRecurrencePatternLabelCell(void);
	virtual void __fastcall CreateShowTimeAs(void);
	virtual void __fastcall CreateShowTimeAsCell(void);
	virtual void __fastcall CreateShowTimeAsLabelCell(void);
	virtual void __fastcall CreateStart(void);
	virtual void __fastcall CreateStartLabelCell(void);
	virtual void __fastcall CreateSubject(void);
	virtual void __fastcall CreateSubjectLabelCell(void);
	virtual System::UnicodeString __fastcall GetHeaderCellText(void);
	virtual System::UnicodeString __fastcall GetRecurrenceCellText(void);
	virtual System::UnicodeString __fastcall GetRecurrencePatternCellText(void);
	virtual System::UnicodeString __fastcall GetShowTimeAsCellText(void);
	
public:
	virtual void __fastcall CalculateLayout(int AWidth, int ATimeWidth);
	__property Dxpscore::TdxReportCellString* CaptionLabelCell = {read=FCaptionLabelCell};
	__property Dxpscore::TdxReportCellString* HeaderCell = {read=FHeaderCell};
	__property Dxpscore::TdxReportCellString* LocationCell = {read=FLocationCell};
	__property Dxpscore::TdxReportCellString* LocationLabelCell = {read=FLocationLabelCell};
	__property Dxpscore::TdxReportCellString* ShowTimeAsCell = {read=FShowTimeAsCell};
	__property Dxpscore::TdxReportCellString* ShowTimeAsLabelCell = {read=FShowTimeAsLabelCell};
	__property Dxpscore::TdxReportCellString* StartLabelCell = {read=FStartLabelCell};
	__property Dxpscore::TdxReportCellString* FinishLabelCell = {read=FFinishLabelCell};
	__property Dxpscore::TdxReportCellString* RecurrenceCell = {read=FRecurrenceCell};
	__property Dxpscore::TdxReportCellString* RecurrenceLabelCell = {read=FRecurrenceLabelCell};
	__property Dxpscore::TdxReportCellString* RecurrencePatternCell = {read=FRecurrencePatternCell};
	__property Dxpscore::TdxReportCellString* RecurrencePatternLabelCell = {read=FRecurrencePatternLabelCell};
public:
	/* TcxSchedulerReportDetailsEventCell.CreateEx */ inline __fastcall TcxSchedulerReportMemoEventCell(Dxpscore::TdxReportCell* AParent, Cxschedulerstorage::TcxSchedulerEvent* AEvent, System::TDateTime ADate, const Cxgraphics::TcxViewParams &AParams, bool AContinued) : TcxSchedulerReportDetailsEventCell(AParent, AEvent, ADate, AParams, AContinued) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportMemoEventCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TcxSchedulerReportMemoEventCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportDetailsEventCell(AParent) { }
	
};


class DELPHICLASS TcxSchedulerReportGanttLinkCell;
class PASCALIMPLEMENTATION TcxSchedulerReportGanttLinkCell : public TcxSchedulerReportCustomCell
{
	typedef TcxSchedulerReportCustomCell inherited;
	
protected:
	Cxlookandfeelpainters::TcxArrowDirection FArrowDirection;
	System::Types::TRect FArrowRect;
	Cxschedulerganttview::TcxSchedulerGanttViewLinkLines FLines;
	void __fastcall AssignInfo(const Cxschedulerganttview::TcxSchedulerGanttViewLinkLines ALines, Cxlookandfeelpainters::TcxArrowDirection AArrowDirection, const System::Types::TRect &AArrowRect);
	virtual void __fastcall ConvertCoords(int APixelsNumerator, int APixelsDenominator);
	virtual void __fastcall ReadData(Dxpscore::TdxPSDataReader* AReader);
	virtual void __fastcall WriteData(Dxpscore::TdxPSDataWriter* AWriter);
	
public:
	__fastcall virtual TcxSchedulerReportGanttLinkCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AViewInfo);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall DrawArrow(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, Dxpscore::TdxPSRenderStages AStage);
	__classmethod virtual Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItemClass __fastcall SchedulerCellClass();
	__property Cxlookandfeelpainters::TcxArrowDirection ArrowDirection = {read=FArrowDirection, nodefault};
	__property System::Types::TRect ArrowRect = {read=FArrowRect};
	__property Cxschedulerganttview::TcxSchedulerGanttViewLinkLines Lines = {read=FLines};
public:
	/* TAbstractdxReportCellData.Create */ inline __fastcall virtual TcxSchedulerReportGanttLinkCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportCustomCell(AParent) { }
	
public:
	/* TdxReportItem.Destroy */ inline __fastcall virtual ~TcxSchedulerReportGanttLinkCell(void) { }
	
};


class DELPHICLASS TcxSchedulerReportGanttMilestoneCell;
class PASCALIMPLEMENTATION TcxSchedulerReportGanttMilestoneCell : public TcxSchedulerReportEventCell
{
	typedef TcxSchedulerReportEventCell inherited;
	
protected:
	virtual void __fastcall CalculateLayout(void);
	virtual void __fastcall CreateDataItems(void);
	virtual void __fastcall DoInitializeFromViewInfo(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo);
	virtual Cxgraphics::TPointArray __fastcall GetPolygone(System::Types::TRect &ABounds);
	
public:
	virtual void __fastcall DrawContent(Dxpsreportrendercanvas::TdxPSReportRenderCustomCanvas* ACanvas, System::Types::TRect &DrawRect, const System::Types::TRect &OriginRect, Dxpscore::TdxPSRenderStages AStage);
public:
	/* TcxSchedulerReportEventCell.CreateFrom */ inline __fastcall virtual TcxSchedulerReportGanttMilestoneCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo) : TcxSchedulerReportEventCell(AParent, AEventViewInfo) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportGanttMilestoneCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TcxSchedulerReportGanttMilestoneCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportEventCell(AParent) { }
	
};


class DELPHICLASS TcxSchedulerReportGanttGroupCell;
class PASCALIMPLEMENTATION TcxSchedulerReportGanttGroupCell : public TcxSchedulerReportGanttMilestoneCell
{
	typedef TcxSchedulerReportGanttMilestoneCell inherited;
	
protected:
	virtual Cxgraphics::TPointArray __fastcall GetPolygone(System::Types::TRect &ABounds);
public:
	/* TcxSchedulerReportEventCell.CreateFrom */ inline __fastcall virtual TcxSchedulerReportGanttGroupCell(Dxpscore::TdxReportCell* AParent, Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo) : TcxSchedulerReportGanttMilestoneCell(AParent, AEventViewInfo) { }
	
public:
	/* TdxReportCell.Destroy */ inline __fastcall virtual ~TcxSchedulerReportGanttGroupCell(void) { }
	
public:
	/* TdxReportVisualItem.Create */ inline __fastcall virtual TcxSchedulerReportGanttGroupCell(Dxpscore::TdxReportCell* AParent) : TcxSchedulerReportGanttMilestoneCell(AParent) { }
	
};


class PASCALIMPLEMENTATION TcxSchedulerReportCommonCellsProducer : public Cxschedulercustomresourceview::TcxCustomResourceViewAdapter
{
	typedef Cxschedulercustomresourceview::TcxCustomResourceViewAdapter inherited;
	
private:
	TcxSchedulerReportSchedulingAreaCell* FSite;
	TcxCustomSchedulerReportLinkPrintStyle* FStyle;
	TcxSchedulerReportLinkStyles* __fastcall GetStyles(void);
	
protected:
	System::Types::TRect FBounds;
	virtual void __fastcall AfterCalculatePage(void);
	virtual bool __fastcall CanCalculate(void);
	virtual void __fastcall ConvertSchedulerCellToPSCells(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AItem, TcxSchedulerReportCustomCellClass AReportItemClass);
	virtual TcxSchedulerReportEventCell* __fastcall CreateEventCell(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo);
	virtual void __fastcall DoInitialize(Cxschedulerutils::TcxSchedulerDateList* &ASelectedDays, Cxschedulerstorage::TcxSchedulerCachedEventList* &AEvents);
	virtual bool __fastcall GetCompressWeekends(void);
	virtual bool __fastcall GetDontPrintWeekEnds(void);
	virtual TcxSchedulerReportEventCellClass __fastcall GetEventCellClass(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo);
	virtual bool __fastcall GetHideSelection(void);
	virtual bool __fastcall GetIsPrinting(void);
	virtual System::Types::TRect __fastcall GetPageBounds(void);
	virtual System::Byte __fastcall GetPagesPerWeek(void);
	virtual bool __fastcall GetPrintExactlyOneMonth(void);
	virtual System::TDateTime __fastcall GetPrintRange(int Index);
	virtual bool __fastcall GetPrimaryPage(void);
	virtual Cxschedulercustomcontrols::_di_IcxSchedulerStylesAdapter __fastcall GetStylesAdapter(void);
	virtual void __fastcall SetCellViewParams(Dxpscore::TdxReportVisualItem* ACell, const Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxSchedulerReportCommonCellsProducer(TcxCustomSchedulerReportLinkPrintStyle* AStyle, TcxSchedulerReportSchedulingAreaCell* ASite);
	virtual void __fastcall GetPageResources(Cxclasses::TcxObjectList* AResources);
	virtual void __fastcall Produce(void);
	__property TcxSchedulerReportSchedulingAreaCell* Site = {read=FSite};
	__property TcxCustomSchedulerReportLinkPrintStyle* Style = {read=FStyle};
	__property TcxSchedulerReportLinkStyles* Styles = {read=GetStyles};
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerReportCommonCellsProducer(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : Cxschedulercustomresourceview::TcxCustomResourceViewAdapter(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerReportCommonCellsProducer(void) { }
	
};


typedef System::TMetaClass* TcxSchedulerReportCommonCellsProducerClass;

class DELPHICLASS TcxSchedulerReportWeeksCellsProducer;
class PASCALIMPLEMENTATION TcxSchedulerReportWeeksCellsProducer : public TcxSchedulerReportCommonCellsProducer
{
	typedef TcxSchedulerReportCommonCellsProducer inherited;
	
public:
	/* TcxSchedulerReportCommonCellsProducer.CreateEx */ inline __fastcall virtual TcxSchedulerReportWeeksCellsProducer(TcxCustomSchedulerReportLinkPrintStyle* AStyle, TcxSchedulerReportSchedulingAreaCell* ASite) : TcxSchedulerReportCommonCellsProducer(AStyle, ASite) { }
	
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerReportWeeksCellsProducer(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : TcxSchedulerReportCommonCellsProducer(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerReportWeeksCellsProducer(void) { }
	
};


class DELPHICLASS TcxSchedulerReportDailyCellsProducer;
class PASCALIMPLEMENTATION TcxSchedulerReportDailyCellsProducer : public TcxSchedulerReportCommonCellsProducer
{
	typedef TcxSchedulerReportCommonCellsProducer inherited;
	
private:
	TcxSchedulerReportDailyTimeRulerCellsSite* FRulerSite;
	
protected:
	virtual void __fastcall AfterCalculatePage(void);
	virtual void __fastcall BeforeCalculatePage(void);
	virtual TcxSchedulerReportDailyTimeRulerCellsSite* __fastcall CreateTimeRulerSite(void);
	virtual void __fastcall ConvertSchedulerCellToPSCells(Cxschedulercustomresourceview::TcxSchedulerCustomViewInfoItem* AItem, TcxSchedulerReportCustomCellClass AReportItemClass);
public:
	/* TcxSchedulerReportCommonCellsProducer.CreateEx */ inline __fastcall virtual TcxSchedulerReportDailyCellsProducer(TcxCustomSchedulerReportLinkPrintStyle* AStyle, TcxSchedulerReportSchedulingAreaCell* ASite) : TcxSchedulerReportCommonCellsProducer(AStyle, ASite) { }
	
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerReportDailyCellsProducer(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : TcxSchedulerReportCommonCellsProducer(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerReportDailyCellsProducer(void) { }
	
};


class DELPHICLASS TcxSchedulerReportYearlyCellsProducer;
class PASCALIMPLEMENTATION TcxSchedulerReportYearlyCellsProducer : public TcxSchedulerReportCommonCellsProducer
{
	typedef TcxSchedulerReportCommonCellsProducer inherited;
	
private:
	bool __fastcall GetIsPrimaryPage(void);
	TcxSchedulerReportLinkYearlyPrintStyle* __fastcall GetStyle(void);
	
protected:
	int FFirstMonth;
	virtual int __fastcall GetDayCountPerPage(void);
	virtual int __fastcall GetMonthCount(void);
	virtual int __fastcall GetFirstMonth(void);
	virtual bool __fastcall GetShowMonthHeaders(void);
	virtual bool __fastcall GetShowWeekDayHeaders(void);
	virtual int __fastcall GetStartDayIndex(void);
	__property bool IsPrimaryPage = {read=GetIsPrimaryPage, nodefault};
	__property TcxSchedulerReportLinkYearlyPrintStyle* Style = {read=GetStyle};
	
public:
	virtual void __fastcall Produce(void);
public:
	/* TcxSchedulerReportCommonCellsProducer.CreateEx */ inline __fastcall virtual TcxSchedulerReportYearlyCellsProducer(TcxCustomSchedulerReportLinkPrintStyle* AStyle, TcxSchedulerReportSchedulingAreaCell* ASite) : TcxSchedulerReportCommonCellsProducer(AStyle, ASite) { }
	
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerReportYearlyCellsProducer(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : TcxSchedulerReportCommonCellsProducer(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerReportYearlyCellsProducer(void) { }
	
private:
	void *__IcxSchedulerYearViewAdapter;	/* Cxscheduleryearview::IcxSchedulerYearViewAdapter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {7B39CB3C-256E-4269-9B24-5A59BC3D868D}
	operator Cxscheduleryearview::_di_IcxSchedulerYearViewAdapter()
	{
		Cxscheduleryearview::_di_IcxSchedulerYearViewAdapter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxscheduleryearview::IcxSchedulerYearViewAdapter*(void) { return (Cxscheduleryearview::IcxSchedulerYearViewAdapter*)&__IcxSchedulerYearViewAdapter; }
	#endif
	
};


class DELPHICLASS TcxTimeLinePageInfo;
class PASCALIMPLEMENTATION TcxTimeLinePageInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::Classes::TList* PageResources;
	System::Types::TRect ContentBounds;
	System::TDateTime Finish;
	bool Headers;
	int LineStart;
	System::Types::TRect PageBounds;
	bool Scales;
	System::TDateTime Start;
	__fastcall virtual TcxTimeLinePageInfo(void);
	__fastcall virtual ~TcxTimeLinePageInfo(void);
};


class PASCALIMPLEMENTATION TcxSchedulerReportTimeLineLayoutBuilder : public Cxschedulertimegridview::TcxSchedulerTimeGridViewAdapter
{
	typedef Cxschedulertimegridview::TcxSchedulerTimeGridViewAdapter inherited;
	
private:
	int FColCount;
	int FCurrentPageIndex;
	Cxclasses::TcxObjectList* FPagesInfo;
	int FRowCount;
	TcxSchedulerReportLinkTimeLinePrintStyle* FStyle;
	int __fastcall GetPageCount(void);
	TcxTimeLinePageInfo* __fastcall GetPageInfo(int Index);
	HIDESBASE Cxschedulertimegridview::TcxSchedulerTimeGridViewViewInfo* __fastcall GetViewInfo(void);
	
public:
	TcxTimeLinePageInfo* __fastcall AddPageInfo(int ARow, int AColumn, const System::TDateTime AStart, const System::TDateTime AFinish);
	void __fastcall AddRow(int AStartIndex, int AFinishIndex, int AStartLine);
	virtual void __fastcall AfterCalculatePage(void);
	void __fastcall CalculateTimeRanges(void);
	void __fastcall CalculatePagination(void);
	virtual bool __fastcall CanCalculate(void);
	virtual System::TDateTime __fastcall GetActualStart(void);
	virtual System::TDateTime __fastcall GetActualFinish(void);
	virtual bool __fastcall GetDontPrintWeekEnds(void);
	virtual bool __fastcall GetHideSelection(void);
	virtual bool __fastcall GetIsPrinting(void);
	virtual System::Types::TRect __fastcall GetPageBounds(void);
	System::Types::TRect __fastcall GetPageContentBounds(int ARow, int AColumn);
	int __fastcall GetPageLineCount(int ARow);
	virtual System::TDateTime __fastcall GetPrintRange(int Index);
	virtual Cxschedulercustomcontrols::_di_IcxSchedulerStylesAdapter __fastcall GetStylesAdapter(void);
	__fastcall virtual TcxSchedulerReportTimeLineLayoutBuilder(TcxSchedulerReportLinkTimeLinePrintStyle* AStyle);
	__fastcall virtual ~TcxSchedulerReportTimeLineLayoutBuilder(void);
	void __fastcall CalculateLayout(void);
	virtual void __fastcall GetPageResources(Cxclasses::TcxObjectList* AResources);
	__property int ColCount = {read=FColCount, nodefault};
	__property int PageCount = {read=GetPageCount, nodefault};
	__property TcxTimeLinePageInfo* PageInfo[int Index] = {read=GetPageInfo};
	__property int RowCount = {read=FRowCount, nodefault};
	__property TcxSchedulerReportLinkTimeLinePrintStyle* Style = {read=FStyle};
	__property Cxschedulertimegridview::TcxSchedulerTimeGridViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerReportTimeLineLayoutBuilder(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : Cxschedulertimegridview::TcxSchedulerTimeGridViewAdapter(AView) { }
	
};


class DELPHICLASS TcxSchedulerReportTimeLineCellsProducer;
class PASCALIMPLEMENTATION TcxSchedulerReportTimeLineCellsProducer : public TcxSchedulerReportCommonCellsProducer
{
	typedef TcxSchedulerReportCommonCellsProducer inherited;
	
private:
	int __fastcall GetPageIndex(void);
	TcxTimeLinePageInfo* __fastcall GetPageInfo(void);
	TcxSchedulerReportLinkTimeLinePrintStyle* __fastcall GetStyle(void);
	
protected:
	virtual TcxSchedulerReportEventCell* __fastcall CreateEventCell(Cxschedulercustomresourceview::TcxSchedulerEventCellViewInfo* AEventViewInfo);
	virtual System::TDateTime __fastcall GetActualStart(void);
	virtual System::TDateTime __fastcall GetActualFinish(void);
	virtual int __fastcall GetLineOffset(void);
	virtual System::TDateTime __fastcall GetPrintRange(int Index);
	bool __fastcall GetShowLinks(void);
	bool __fastcall GetShowResourceHeaders(void);
	bool __fastcall GetShowScales(void);
	bool __fastcall GetWorkDaysOnly(void);
	bool __fastcall GetWorkTimeOnly(void);
	
public:
	virtual void __fastcall GetPageResources(Cxclasses::TcxObjectList* AResources);
	__property int PageIndex = {read=GetPageIndex, nodefault};
	__property TcxTimeLinePageInfo* PageInfo = {read=GetPageInfo};
	__property TcxSchedulerReportLinkTimeLinePrintStyle* Style = {read=GetStyle};
public:
	/* TcxSchedulerReportCommonCellsProducer.CreateEx */ inline __fastcall virtual TcxSchedulerReportTimeLineCellsProducer(TcxCustomSchedulerReportLinkPrintStyle* AStyle, TcxSchedulerReportSchedulingAreaCell* ASite) : TcxSchedulerReportCommonCellsProducer(AStyle, ASite) { }
	
public:
	/* TcxCustomResourceViewAdapter.Create */ inline __fastcall virtual TcxSchedulerReportTimeLineCellsProducer(Cxschedulercustomresourceview::TcxSchedulerCustomResourceView* AView) : TcxSchedulerReportCommonCellsProducer(AView) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerReportTimeLineCellsProducer(void) { }
	
private:
	void *__IcxSchedulerTimeGridViewAdapter;	/* Cxschedulertimegridview::IcxSchedulerTimeGridViewAdapter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A1808B72-237C-41D0-B864-BE8E24894F22}
	operator Cxschedulertimegridview::_di_IcxSchedulerTimeGridViewAdapter()
	{
		Cxschedulertimegridview::_di_IcxSchedulerTimeGridViewAdapter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxschedulertimegridview::IcxSchedulerTimeGridViewAdapter*(void) { return (Cxschedulertimegridview::IcxSchedulerTimeGridViewAdapter*)&__IcxSchedulerTimeGridViewAdapter; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 vspsSchedulerFirst = System::Int8(0x0);
static const System::Int8 vspsSchedulerControlFirst = System::Int8(0x0);
static const System::Int8 vspsSchedulerContent = System::Int8(0x0);
static const System::Int8 vspsSchedulerDayHeader = System::Int8(0x1);
static const System::Int8 vspsSchedulerEvent = System::Int8(0x2);
static const System::Int8 vspsSchedulerResourceHeader = System::Int8(0x3);
static const System::Int8 vspsSchedulerControlLast = System::Int8(0x3);
static const System::Int8 vspsSchedulerViewDayFirst = System::Int8(0x4);
static const System::Int8 vspsSchedulerTimeRuler = System::Int8(0x4);
static const System::Int8 vspsSchedulerViewDayLast = System::Int8(0x4);
static const System::Int8 vspsSchedulerDateNavigatorFirst = System::Int8(0x5);
static const System::Int8 vspsSchedulerDateNavigatorContent = System::Int8(0x5);
static const System::Int8 vspsSchedulerDateNavigatorHeader = System::Int8(0x6);
static const System::Int8 vspsSchedulerDateNavigatorLast = System::Int8(0x6);
static const System::Int8 vspsSchedulerNativeFirst = System::Int8(0x7);
static const System::Int8 vspsSchedulerSchedulerHeader = System::Int8(0x7);
static const System::Int8 vspsSchedulerNotesAreaBlank = System::Int8(0x8);
static const System::Int8 vspsSchedulerNotesAreaLined = System::Int8(0x9);
static const System::Int8 vspsSchedulerTaskPad = System::Int8(0xa);
static const System::Int8 vspsSchedulerNativeLast = System::Int8(0xa);
static const System::Int8 vspsSchedulerLast = System::Int8(0xa);
static const System::Int8 cdidSchedulerFirst = System::Int8(0x1);
static const System::Int8 cdidSchedulerSchedulerHeader = System::Int8(0x1);
static const System::Int8 cdidSchedulerDateNavigatorHeader = System::Int8(0x2);
static const System::Int8 cdidSchedulerDateNavigatorDay = System::Int8(0x3);
static const System::Int8 cdidSchedulerDateNavigatorDayCaption = System::Int8(0x4);
static const System::Int8 cdidSchedulerDateNavigatorWeekNumber = System::Int8(0x5);
static const System::Int8 cdidSchedulerTimeRuler = System::Int8(0x6);
static const System::Int8 cdidSchedulerNotesArea = System::Int8(0x7);
static const System::Int8 cdidSchedulerTaskPad = System::Int8(0x8);
static const System::Int8 cdidSchedulerContent = System::Int8(0x9);
static const System::Int8 cdidSchedulerHeader = System::Int8(0xa);
static const System::Int8 cdidSchedulerEventCaption = System::Int8(0xb);
static const System::Int8 cdidSchedulerEventStart = System::Int8(0xc);
static const System::Int8 cdidSchedulerEventFinish = System::Int8(0xd);
static const System::Int8 cdidSchedulerEventIcons = System::Int8(0xe);
static const System::Int8 cdidSchedulerEventMessage = System::Int8(0xf);
static const System::Int8 cdidSchedulerEventTimeLine = System::Int8(0x10);
static const System::Int8 InterAreaSpace = System::Int8(0x5);
static const double NotesAreaWidth = 3.333333E-01;
static const double SchedulerHeaderMinHeight = 1.000000E-01;
static const double SchedulerHeaderMaxHeight = 2.500000E-01;
static const double SchedulerHeaderSmallHeight = 5.555556E-02;
extern PACKAGE Vcl::Graphics::TFont* SpecialSymbolFont;
}	/* namespace Dxpscxschedulerlnk */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCXSCHEDULERLNK)
using namespace Dxpscxschedulerlnk;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscxschedulerlnkHPP
