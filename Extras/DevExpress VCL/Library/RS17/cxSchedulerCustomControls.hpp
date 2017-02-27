// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSchedulerCustomControls.pas' rev: 24.00 (Win32)

#ifndef CxschedulercustomcontrolsHPP
#define CxschedulercustomcontrolsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Clipbrd.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <cxFormats.hpp>	// Pascal unit
#include <cxSchedulerUtils.hpp>	// Pascal unit
#include <cxSchedulerStorage.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDateUtils.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <cxVariants.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxschedulercustomcontrols
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxSchedulerCustomViewClass;

enum TcxControlFlag : unsigned char { cfInvalidLayout, cfLocked, cfViewValid };

typedef System::Set<TcxControlFlag, TcxControlFlag::cfInvalidLayout, TcxControlFlag::cfViewValid>  TcxControlFlags;

enum TcxSchedulerSplitterKind : unsigned char { skHorizontal, skVertical };

enum TcxSchedulerViewPosition : unsigned char { vpRight, vpLeft, vpTop, vpBottom };

enum TcxSchedulerGroupingKind : unsigned char { gkDefault, gkNone, gkByDate, gkByResource };

enum TcxSchedulerViewMode : unsigned char { vmDay, vmWeek, vmMonth, vmWorkWeek };

typedef bool __fastcall (__closure *TcxOnDeleteEventFunc)(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);

enum TcxSchedulerContentPopupMenuItem : unsigned char { cpmiNewEvent, cpmiNewAllDayEvent, cpmiNewReccuringEvent, cpmiToday, cpmiGoToDate, cpmiGoToThisDay, cpmiResourcesLayout };

typedef System::Set<TcxSchedulerContentPopupMenuItem, TcxSchedulerContentPopupMenuItem::cpmiNewEvent, TcxSchedulerContentPopupMenuItem::cpmiResourcesLayout>  TcxSchedulerContentPopupMenuItems;

class DELPHICLASS TcxSchedulerEventEditInfo;
class PASCALIMPLEMENTATION TcxSchedulerEventEditInfo : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	bool AllowDelete;
	bool AllowHiddenEvents;
	System::TDateTime BiasTime;
	bool DisableShare;
	bool Intersection;
	Cxschedulerstorage::TcxSchedulerControlEvent* Event;
	bool ForcePatternEditing;
	Cxlookandfeels::TcxLookAndFeel* LookAndFeel;
	TcxOnDeleteEventFunc OnDeleteFunc;
	bool ReadOnly;
	bool Recurrence;
	bool RecurrenceButton;
	bool ShowResources;
	bool ShowTaskComplete;
public:
	/* TObject.Create */ inline __fastcall TcxSchedulerEventEditInfo(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerEventEditInfo(void) { }
	
};


class DELPHICLASS TcxSchedulerSubControl;
class DELPHICLASS TcxSchedulerSubControlController;
class DELPHICLASS TcxSchedulerSubControlHitTest;
class DELPHICLASS TcxSchedulerSubControlPainter;
class DELPHICLASS TcxCustomScheduler;
class DELPHICLASS TcxSchedulerSubControlViewInfo;
class DELPHICLASS TcxSchedulerStyles;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerSubControl : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxSchedulerSubControlController* FController;
	System::Uitypes::TCursor FCursor;
	int FHeight;
	TcxSchedulerSubControlHitTest* FHitTest;
	int FLeft;
	TcxSchedulerSubControlPainter* FPainter;
	TcxCustomScheduler* FScheduler;
	int FTop;
	TcxSchedulerSubControlViewInfo* FViewInfo;
	bool FVisible;
	int FWidth;
	int __fastcall GetBottom(void);
	System::Types::TRect __fastcall GetBounds(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	Cxschedulerutils::TcxSchedulerDateTimeHelperClass __fastcall GetDateTimeHelperClass(void);
	bool __fastcall GetIsGestureScrolling(void);
	bool __fastcall GetIsScrollingContent(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	Cxschedulerutils::TcxSchedulerPainterHelperClass __fastcall GetPainterHelperClass(void);
	int __fastcall GetRight(void);
	TcxSchedulerStyles* __fastcall GetStyles(void);
	void __fastcall InternalSetBounds(const System::Types::TRect &AValue);
	void __fastcall SetBottom(const int Value);
	void __fastcall SetHeight(int AValue);
	void __fastcall SetLeft(int AValue);
	void __fastcall SetRight(int Value);
	void __fastcall SetTop(int AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall SetWidth(int AValue);
	
protected:
	virtual void __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual bool __fastcall AllowDesignHitTest(int X, int Y, System::Classes::TShiftState AShift);
	virtual void __fastcall BoundsChanged(void);
	virtual void __fastcall CalculateViewInfo(void);
	virtual bool __fastcall CanCapture(const System::Types::TPoint &APoint);
	virtual void __fastcall Changed(void);
	virtual void __fastcall ClearCachedData(void);
	virtual TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual TcxSchedulerSubControlPainter* __fastcall CreatePainter(void);
	virtual TcxSchedulerSubControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall BoundsChanging(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DestroySubClasses(void);
	void __fastcall DoBeforeMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall DoLayoutChanged(void);
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	void __fastcall DoMouseMove(System::Classes::TShiftState AShift, int X, int Y);
	void __fastcall DoMouseUp(System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall DoScaleScroll(void);
	virtual void __fastcall FormatChanged(void);
	virtual System::Types::TRect __fastcall GetClientRect(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual System::Types::TRect __fastcall GetHScrollBarBounds(void);
	Cxcontrols::_di_IcxControlScrollBar __fastcall GetScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual System::Types::TRect __fastcall GetSizeGripBounds(void);
	virtual Cxdateutils::TDay __fastcall GetStartOfWeek(void);
	virtual System::Types::TRect __fastcall GetVScrollBarBounds(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	virtual bool __fastcall IsSpecialPaint(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall MousePositionChanged(int &X, int &Y);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall Paint(void);
	virtual void __fastcall PeriodChanged(void);
	void __fastcall SetScrollBarInfo(Vcl::Forms::TScrollBarKind AScrollBarKind, int AMin, int AMax, int AStep, int APage, int APos, bool AAllowShow, bool AAllowHide);
	virtual void __fastcall VisibleChanged(void);
	__property int Bottom = {read=GetBottom, write=SetBottom, nodefault};
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property TcxSchedulerSubControlController* Controller = {read=FController};
	__property System::Uitypes::TCursor Cursor = {read=FCursor, write=FCursor, nodefault};
	__property Cxschedulerutils::TcxSchedulerDateTimeHelperClass DateTimeHelper = {read=GetDateTimeHelperClass};
	__property TcxSchedulerSubControlHitTest* HitTest = {read=FHitTest};
	__property bool IsGestureScrolling = {read=GetIsGestureScrolling, nodefault};
	__property bool IsScrollingContent = {read=GetIsScrollingContent, nodefault};
	__property int Left = {read=FLeft, write=SetLeft, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TcxSchedulerSubControlPainter* Painter = {read=FPainter};
	__property Cxschedulerutils::TcxSchedulerPainterHelperClass PainterHelper = {read=GetPainterHelperClass};
	__property int Right = {read=GetRight, write=SetRight, nodefault};
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
	__property Cxdateutils::TDay StartOfWeek = {read=GetStartOfWeek, nodefault};
	__property TcxSchedulerStyles* Styles = {read=GetStyles};
	__property int Top = {read=FTop, write=SetTop, nodefault};
	__property TcxSchedulerSubControlViewInfo* ViewInfo = {read=FViewInfo};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
	
public:
	__fastcall virtual TcxSchedulerSubControl(TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerSubControl(void);
	void __fastcall Invalidate(void);
	void __fastcall InvalidateRect(const System::Types::TRect &ARect);
	void __fastcall LayoutChanged(void);
	void __fastcall Refresh(void);
	void __fastcall Repaint(void);
	void __fastcall RepaintRect(const System::Types::TRect &ARect);
	System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint &APos);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property System::Types::TRect Bounds = {read=GetBounds, write=InternalSetBounds};
	__property int Height = {read=FHeight, write=SetHeight, nodefault};
	__property int Width = {read=FWidth, write=SetWidth, nodefault};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerSubControlController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool FCanProcessMouseMove;
	TcxSchedulerSubControl* FOwner;
	TcxSchedulerSubControlHitTest* __fastcall GetHitTest(void);
	Cxdateutils::TDay __fastcall GetStartOfWeek(void);
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual bool __fastcall CanDrag(int X, int Y);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	virtual void __fastcall StartDrag(Vcl::Controls::TDragObject* &DragObject);
	virtual bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoCancelMode(void);
	virtual System::Uitypes::TCursor __fastcall GetCursor(int X, int Y);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseEnter(void);
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Reset(void);
	__property bool CanProcessMouseMove = {read=FCanProcessMouseMove, nodefault};
	
public:
	__fastcall virtual TcxSchedulerSubControlController(TcxSchedulerSubControl* AOwner);
	__property TcxSchedulerSubControlHitTest* HitTest = {read=GetHitTest};
	__property TcxSchedulerSubControl* Owner = {read=FOwner};
	__property Cxdateutils::TDay StartOfWeek = {read=GetStartOfWeek, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerSubControlController(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxSchedulerSubControlHitTest : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerSubControl* FOwner;
	System::Types::TPoint FHitPoint;
	int __fastcall GetPosValue(int AIndex);
	TcxCustomScheduler* __fastcall GetScheduler(void);
	void __fastcall SetHitPoint(const System::Types::TPoint &APoint);
	void __fastcall SetPosValue(int AIndex, int AValue);
	
protected:
	System::TDateTime FTime;
	__int64 Flags;
	virtual void __fastcall Clear(void);
	virtual void __fastcall DoCalculate(void);
	bool __fastcall GetBitState(int AIndex);
	bool __fastcall GetMaskState(int AMask);
	bool __fastcall GetMaskStateEx(int AMask);
	void __fastcall SetBitState(int AIndex, bool AValue);
	void __fastcall SetMaskState(int AMask, bool AValue);
	__property TcxSchedulerSubControl* Owner = {read=FOwner};
	__property TcxCustomScheduler* Scheduler = {read=GetScheduler};
	
public:
	__fastcall virtual TcxSchedulerSubControlHitTest(TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerSubControlHitTest(void);
	void __fastcall Recalculate(void);
	__property System::Types::TPoint HitPoint = {read=FHitPoint, write=SetHitPoint};
	__property int HitX = {read=GetPosValue, write=SetPosValue, index=0, nodefault};
	__property int HitY = {read=GetPosValue, write=SetPosValue, index=1, nodefault};
	__property bool HitAtControl = {read=GetBitState, index=0, nodefault};
	__property bool HitAtTime = {read=GetBitState, index=1, nodefault};
	__property System::TDateTime Time = {read=FTime};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerSubControlPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerSubControl* FOwner;
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	TcxSchedulerSubControlViewInfo* __fastcall GetViewInfo(void);
	
protected:
	__property TcxSchedulerSubControl* Owner = {read=FOwner};
	__property TcxSchedulerSubControlViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxSchedulerSubControlPainter(TcxSchedulerSubControl* AOwner);
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeforePaint(void);
	virtual void __fastcall InitializePainter(void);
	virtual void __fastcall Paint(void);
	__property Cxgraphics::TcxCanvas* Canvas = {read=GetCanvas};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerSubControlPainter(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerSubControlViewInfo : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	TcxSchedulerSubControl* FOwner;
	Cxschedulerutils::TcxSchedulerDateTimeHelperClass __fastcall GetDateTimeHelperClass(void);
	Vcl::Graphics::TFont* __fastcall GetDefaultFont(void);
	bool __fastcall GetIsSchedulerCreated(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	Cxschedulerutils::TcxSchedulerPainterHelperClass __fastcall GetPainterHelperClass(void);
	TcxSchedulerStyles* __fastcall GetStyles(void);
	
protected:
	System::Types::TRect FBounds;
	virtual void __fastcall AfterCalculate(void);
	virtual void __fastcall Clear(void);
	virtual void __fastcall DoCalculate(void);
	virtual System::Types::TRect __fastcall GetBounds(void);
	__property Cxschedulerutils::TcxSchedulerDateTimeHelperClass DateTimeHelper = {read=GetDateTimeHelperClass};
	__property Vcl::Graphics::TFont* DefaultFont = {read=GetDefaultFont};
	__property bool IsSchedulerCreated = {read=GetIsSchedulerCreated, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TcxSchedulerSubControl* Owner = {read=FOwner};
	__property Cxschedulerutils::TcxSchedulerPainterHelperClass PainterHelper = {read=GetPainterHelperClass};
	__property TcxSchedulerStyles* Styles = {read=GetStyles};
	
public:
	__fastcall virtual TcxSchedulerSubControlViewInfo(TcxSchedulerSubControl* AOwner);
	virtual void __fastcall Calculate(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerSubControlViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerBackground;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerBackground : public TcxSchedulerSubControl
{
	typedef TcxSchedulerSubControl inherited;
	
protected:
	virtual bool __fastcall IsSpecialPaint(void);
public:
	/* TcxSchedulerSubControl.Create */ inline __fastcall virtual TcxSchedulerBackground(TcxCustomScheduler* AOwner) : TcxSchedulerSubControl(AOwner) { }
	/* TcxSchedulerSubControl.Destroy */ inline __fastcall virtual ~TcxSchedulerBackground(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerControlBox;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerControlBox : public TcxSchedulerSubControl
{
	typedef TcxSchedulerSubControl inherited;
	
private:
	Vcl::Controls::TWinControl* FContainer;
	Vcl::Controls::TAlign FControlAlign;
	Vcl::Controls::TWinControl* FControlParent;
	System::Types::TRect FControlRect;
	Vcl::Controls::TControl* FControl;
	Cxgraphics::TcxViewParams FViewParams;
	void __fastcall RestorePosition(void);
	void __fastcall SetControl(Vcl::Controls::TControl* AValue);
	void __fastcall StorePosition(void);
	
protected:
	virtual void __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall BoundsChanged(void);
	virtual Vcl::Controls::TWinControl* __fastcall CreateWndContainerControl(void);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall DoLayoutChanged(void);
	bool __fastcall HasAsParent(Vcl::Controls::TControl* AValue);
	virtual void __fastcall VisibleChanged(void);
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams};
	
public:
	__fastcall virtual TcxSchedulerControlBox(TcxCustomScheduler* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Vcl::Controls::TWinControl* Container = {read=FContainer};
	__property Height;
	__property Width;
	
__published:
	__property Vcl::Controls::TControl* Control = {read=FControl, write=SetControl};
	__property Visible = {default=1};
public:
	/* TcxSchedulerSubControl.Destroy */ inline __fastcall virtual ~TcxSchedulerControlBox(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerSplitterController;
class DELPHICLASS TcxSchedulerSplitter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerSplitterController : public TcxSchedulerSubControlController
{
	typedef TcxSchedulerSubControlController inherited;
	
private:
	System::Types::TPoint FHitPoint;
	System::Types::TRect FPrevInvertRect;
	System::Types::TRect FPrevRect;
	TcxSchedulerSubControl* FSaveKeyboardListener;
	System::Types::TRect FSizingBoundsRect;
	System::Types::TRect FStartBounds;
	System::Types::TRect FScreenCanvasClipRect;
	System::Types::TRect __fastcall GetDrawClipRect(void);
	System::Types::TRect __fastcall GetHorzSizingRect(const System::Types::TPoint &P);
	TcxCustomScheduler* __fastcall GetScheduler(void);
	System::Types::TPoint __fastcall GetScreenOffset(void);
	TcxSchedulerSplitter* __fastcall GetSplitter(void);
	System::Types::TRect __fastcall GetVertSizingRect(const System::Types::TPoint &P);
	void __fastcall SetHorzBounds(System::Types::TRect &R);
	void __fastcall SetHorzDelta(int ADelta);
	void __fastcall SetVertBounds(System::Types::TRect &R);
	void __fastcall SetVertDelta(int ADelta);
	
protected:
	virtual void __fastcall DoCancelMode(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall DrawInvertRect(const System::Types::TRect &R);
	void __fastcall EraseInvertRect(void);
	System::Types::TSize __fastcall GetMonthSize(void);
	System::Types::TPoint __fastcall GetOwnerMousePos(int X, int Y);
	System::Types::TRect __fastcall GetSizingBoundsRect(void);
	int __fastcall GetSizingIncrement(void);
	System::Types::TRect __fastcall GetSizingRect(const System::Types::TPoint &P);
	void __fastcall InvertRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual bool __fastcall IsIntegralSizing(void);
	bool __fastcall IsDynamicUpdate(void);
	void __fastcall Modified(void);
	virtual void __fastcall SetSizeDelta(int ADelta);
	void __fastcall UpdateSizing(const System::Types::TRect &R);
	__property TcxCustomScheduler* Scheduler = {read=GetScheduler};
	__property System::Types::TRect ScreenCanvasClipRect = {read=FScreenCanvasClipRect};
	__property System::Types::TPoint ScreenOffset = {read=GetScreenOffset};
	__property System::Types::TRect SizingBoundsRect = {read=FSizingBoundsRect};
	__property TcxSchedulerSplitter* Splitter = {read=GetSplitter};
public:
	/* TcxSchedulerSubControlController.Create */ inline __fastcall virtual TcxSchedulerSplitterController(TcxSchedulerSubControl* AOwner) : TcxSchedulerSubControlController(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerSplitterController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerSplitterHitTest;
class PASCALIMPLEMENTATION TcxSchedulerSplitterHitTest : public TcxSchedulerSubControlHitTest
{
	typedef TcxSchedulerSubControlHitTest inherited;
	
private:
	TcxSchedulerSplitter* __fastcall GetSplitter(void);
	
public:
	__property TcxSchedulerSplitter* Splitter = {read=GetSplitter};
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerSplitterHitTest(TcxSchedulerSubControl* AOwner) : TcxSchedulerSubControlHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerSplitterHitTest(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerSplitter : public TcxSchedulerBackground
{
	typedef TcxSchedulerBackground inherited;
	
private:
	TcxSchedulerSplitterKind FKind;
	Cxgraphics::TcxViewParams FViewParams;
	TcxSchedulerSplitterHitTest* __fastcall GetHitTest(void);
	
protected:
	virtual bool __fastcall AllowDesignHitTest(int X, int Y, System::Classes::TShiftState AShift);
	virtual TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual void __fastcall DoLayoutChanged(void);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall SetKind(TcxSchedulerSplitterKind AKind);
	void __fastcall UpdateCursor(void);
	__property TcxSchedulerSplitterHitTest* HitTest = {read=GetHitTest};
	__property Cxgraphics::TcxViewParams ViewParams = {read=FViewParams};
	
public:
	__property TcxSchedulerSplitterKind Kind = {read=FKind, nodefault};
public:
	/* TcxSchedulerSubControl.Create */ inline __fastcall virtual TcxSchedulerSplitter(TcxCustomScheduler* AOwner) : TcxSchedulerBackground(AOwner) { }
	/* TcxSchedulerSubControl.Destroy */ inline __fastcall virtual ~TcxSchedulerSplitter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerResourceNavigator;
class DELPHICLASS TcxSchedulerNavigatorButton;
typedef void __fastcall (__closure *TcxSchedulerNavigatorButtonClickEvent)(TcxSchedulerResourceNavigator* Sender, TcxSchedulerNavigatorButton* AButton, bool &AHandled);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerNavigatorButton : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	int FCommand;
	bool FEnabled;
	System::UnicodeString FHint;
	int FImageIndex;
	bool FVisible;
	TcxCustomScheduler* __fastcall GetScheduler(void);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetImageIndex(int AValue);
	void __fastcall SetVisible(bool AValue);
	bool __fastcall IsHintStored(void);
	bool __fastcall IsEnabledStored(void);
	bool __fastcall IsVisibleStored(void);
	
protected:
	System::Types::TRect FBounds;
	bool FRotated;
	Cxlookandfeelpainters::TcxButtonState FState;
	int FVisibleIndex;
	HIDESBASE virtual void __fastcall Changed(void);
	virtual void __fastcall Click(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	System::UnicodeString __fastcall GetHintText(void);
	virtual void __fastcall Draw(Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* APainter, Cxgraphics::TcxCanvas* ACanvas);
	virtual int __fastcall GetActualImageIndex(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetActualImageList(void);
	Cxlookandfeelpainters::TcxButtonState __fastcall GetState(bool ACanDisabled = true);
	virtual bool __fastcall GetIsStandard(void);
	__property int Command = {read=FCommand, write=FCommand, nodefault};
	
public:
	__fastcall virtual TcxSchedulerNavigatorButton(System::Classes::TCollection* Collection);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property int ActualImageIndex = {read=GetActualImageIndex, nodefault};
	__property Vcl::Imglist::TCustomImageList* ActualImageList = {read=GetActualImageList};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, stored=IsEnabledStored, nodefault};
	__property bool Rotated = {read=FRotated, nodefault};
	__property TcxCustomScheduler* Scheduler = {read=GetScheduler};
	__property bool IsStandard = {read=GetIsStandard, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, nodefault};
	__property int VisibleIndex = {read=FVisibleIndex, nodefault};
	
__published:
	__property System::UnicodeString Hint = {read=FHint, write=FHint, stored=IsHintStored};
	__property int ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property bool Visible = {read=FVisible, write=SetVisible, stored=IsVisibleStored, nodefault};
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxSchedulerNavigatorButton(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerNavigatorCustomButton;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerNavigatorCustomButton : public TcxSchedulerNavigatorButton
{
	typedef TcxSchedulerNavigatorButton inherited;
	
__published:
	__property Enabled;
public:
	/* TcxSchedulerNavigatorButton.Create */ inline __fastcall virtual TcxSchedulerNavigatorCustomButton(System::Classes::TCollection* Collection) : TcxSchedulerNavigatorButton(Collection) { }
	
public:
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxSchedulerNavigatorCustomButton(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxSchedulerNavigatorButtonClass;

class DELPHICLASS TcxSchedulerNavigatorCustomButtons;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerNavigatorCustomButtons : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TcxSchedulerNavigatorCustomButton* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	System::Classes::TPersistent* FOwner;
	TcxCustomScheduler* FScheduler;
	HIDESBASE TcxSchedulerNavigatorCustomButton* __fastcall GetItem(int AIndex);
	int __fastcall GetVisibleCount(void);
	HIDESBASE void __fastcall SetItem(int AIndex, TcxSchedulerNavigatorCustomButton* AValue);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
	
public:
	__fastcall virtual TcxSchedulerNavigatorCustomButtons(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass AItemClass);
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
	__property TcxSchedulerNavigatorCustomButton* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Create */ inline __fastcall TcxSchedulerNavigatorCustomButtons(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxSchedulerNavigatorCustomButtons(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerNavigatorButtons;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerNavigatorButtons : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxSchedulerNavigatorCustomButtons* FButtons;
	TcxSchedulerResourceNavigator* FOwner;
	TcxSchedulerNavigatorButton* __fastcall GetButtonByIndex(int AIndex);
	void __fastcall SetButtonByIndex(int AIndex, TcxSchedulerNavigatorButton* AValue);
	
protected:
	TcxSchedulerNavigatorButton* __fastcall AddButton(int ACommand, bool AVisible = true);
	virtual void __fastcall CreateButtons(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxSchedulerNavigatorButtons(TcxSchedulerResourceNavigator* AOwner);
	__fastcall virtual ~TcxSchedulerNavigatorButtons(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxSchedulerNavigatorCustomButtons* Buttons = {read=FButtons};
	__property TcxSchedulerResourceNavigator* ResourceNavigator = {read=FOwner};
	
__published:
	__property TcxSchedulerNavigatorButton* First = {read=GetButtonByIndex, write=SetButtonByIndex, index=0};
	__property TcxSchedulerNavigatorButton* PrevPage = {read=GetButtonByIndex, write=SetButtonByIndex, index=1};
	__property TcxSchedulerNavigatorButton* Prev = {read=GetButtonByIndex, write=SetButtonByIndex, index=2};
	__property TcxSchedulerNavigatorButton* Next = {read=GetButtonByIndex, write=SetButtonByIndex, index=3};
	__property TcxSchedulerNavigatorButton* NextPage = {read=GetButtonByIndex, write=SetButtonByIndex, index=4};
	__property TcxSchedulerNavigatorButton* Last = {read=GetButtonByIndex, write=SetButtonByIndex, index=5};
	__property TcxSchedulerNavigatorButton* ShowFewerResources = {read=GetButtonByIndex, write=SetButtonByIndex, index=7};
	__property TcxSchedulerNavigatorButton* ShowMoreResources = {read=GetButtonByIndex, write=SetButtonByIndex, index=6};
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerResourceNavigatorController;
class DELPHICLASS TcxSchedulerHintController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerResourceNavigatorController : public TcxSchedulerSubControlController
{
	typedef TcxSchedulerSubControlController inherited;
	
private:
	TcxSchedulerNavigatorButton* FHotTrackButton;
	TcxSchedulerHintController* __fastcall GetHintController(void);
	TcxSchedulerResourceNavigator* __fastcall GetResourceNavigator(void);
	void __fastcall SetHotTrackButton(TcxSchedulerNavigatorButton* Value);
	
protected:
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall CheckButtonDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift);
	TcxSchedulerNavigatorButton* __fastcall GetHotTrackButton(bool ACanDisabled = true);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState AShift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseEnter(void);
	virtual void __fastcall MouseLeave(void);
	__property TcxSchedulerHintController* HintController = {read=GetHintController};
	__property TcxSchedulerNavigatorButton* HotTrackButton = {read=FHotTrackButton, write=SetHotTrackButton};
	__property TcxSchedulerResourceNavigator* ResourceNavigator = {read=GetResourceNavigator};
public:
	/* TcxSchedulerSubControlController.Create */ inline __fastcall virtual TcxSchedulerResourceNavigatorController(TcxSchedulerSubControl* AOwner) : TcxSchedulerSubControlController(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerResourceNavigatorController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerResourceNavigatorHitTest;
class PASCALIMPLEMENTATION TcxSchedulerResourceNavigatorHitTest : public TcxSchedulerSubControlHitTest
{
	typedef TcxSchedulerSubControlHitTest inherited;
	
private:
	TcxSchedulerNavigatorButton* __fastcall GetCurrentButton(TcxSchedulerNavigatorCustomButtons* AButtons);
	bool __fastcall GetHitAtButton(void);
	TcxSchedulerNavigatorButton* __fastcall GetHitButton(void);
	TcxSchedulerResourceNavigator* __fastcall GetResourceNavigator(void);
	
public:
	__property bool HitAtButton = {read=GetHitAtButton, nodefault};
	__property TcxSchedulerNavigatorButton* HitButton = {read=GetHitButton};
	__property TcxSchedulerResourceNavigator* ResourceNavigator = {read=GetResourceNavigator};
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerResourceNavigatorHitTest(TcxSchedulerSubControl* AOwner) : TcxSchedulerSubControlHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerResourceNavigatorHitTest(void) { }
	
};


typedef void __fastcall (__closure *TcxSchedulerNavigatorCustomDrawButtonEvent)(TcxSchedulerResourceNavigator* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxSchedulerNavigatorButton* AButton, bool &ADone);

enum TcxSchedulerNavigatorVisibilityMode : unsigned char { snvNever, snvAlways, snvAuto };

class PASCALIMPLEMENTATION TcxSchedulerResourceNavigator : public TcxSchedulerSubControl
{
	typedef TcxSchedulerSubControl inherited;
	
private:
	TcxSchedulerNavigatorButtons* FButtons;
	Vcl::Imglist::TCustomImageList* FButtonImages;
	TcxSchedulerNavigatorCustomButtons* FCustomButtons;
	bool FShowButtons;
	Vcl::Extctrls::TTimer* FTimer;
	Vcl::Forms::TScrollBarKind FScrollBarKind;
	TcxSchedulerNavigatorVisibilityMode FVisibility;
	TcxSchedulerNavigatorButtonClickEvent FOnButtonClick;
	TcxSchedulerNavigatorCustomDrawButtonEvent FOnCustomDrawButton;
	int __fastcall GetFirstVisibleResourceIndex(void);
	TcxSchedulerResourceNavigatorHitTest* __fastcall GetHitTest(void);
	TcxSchedulerNavigatorButton* __fastcall GetItem(int AIndex);
	int __fastcall GetItemCount(void);
	int __fastcall GetResourceCount(void);
	int __fastcall GetResourcesPerPage(void);
	int __fastcall GetVisibleButtonCount(void);
	void __fastcall SetButtonImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetButtons(TcxSchedulerNavigatorButtons* Value);
	void __fastcall SetCustomButtons(TcxSchedulerNavigatorCustomButtons* Value);
	void __fastcall SetFirstVisibleResourceIndex(int AValue);
	void __fastcall SetResourcesPerPage(int AValue);
	void __fastcall SetShowButtons(bool AValue);
	void __fastcall SetVisibility(TcxSchedulerNavigatorVisibilityMode AValue);
	bool __fastcall IsCustomButtonsStored(void);
	
protected:
	TcxSchedulerNavigatorButton* FPressedButton;
	int FVisibleButtonCount;
	virtual void __fastcall BoundsChanged(void);
	virtual void __fastcall ButtonClickHandler(TcxSchedulerNavigatorButton* AButton);
	virtual void __fastcall CalculateBounds(void);
	virtual void __fastcall CheckButtonsState(void);
	void __fastcall Click(TcxSchedulerNavigatorButton* Sender);
	virtual TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual TcxSchedulerNavigatorCustomButtons* __fastcall CreateButtons(void);
	virtual TcxSchedulerNavigatorButtons* __fastcall CreateStandardButtons(void);
	virtual bool __fastcall DoCustomDrawButton(TcxSchedulerNavigatorButton* AButton);
	virtual bool __fastcall DoOnClick(TcxSchedulerNavigatorButton* Sender);
	virtual void __fastcall DoPaint(void);
	void __fastcall FirstVisibleResourceChanged(void);
	virtual TcxSchedulerNavigatorButtonClass __fastcall GetCustomButtonClass(void);
	System::UnicodeString __fastcall GetScrollerHint(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	void __fastcall InvalidateButton(TcxSchedulerNavigatorButton* AButton);
	virtual void __fastcall Scroll(System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	int __fastcall ActualCountPerPage(void);
	int __fastcall ActualFirstResourceIndex(void);
	System::Types::TSize __fastcall ButtonSize(void);
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	__property int FirstVisibleResourceIndex = {read=GetFirstVisibleResourceIndex, write=SetFirstVisibleResourceIndex, nodefault};
	__property TcxSchedulerResourceNavigatorHitTest* HitTest = {read=GetHitTest};
	__property int ResourcesPerPage = {read=GetResourcesPerPage, write=SetResourcesPerPage, nodefault};
	__property Vcl::Extctrls::TTimer* Timer = {read=FTimer};
	
public:
	__fastcall virtual TcxSchedulerResourceNavigator(TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerResourceNavigator(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall NeedScrollBar(void);
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxSchedulerNavigatorButton* Items[int Index] = {read=GetItem};
	__property int ResourceCount = {read=GetResourceCount, nodefault};
	__property Scheduler;
	__property Vcl::Forms::TScrollBarKind ScrollBarKind = {read=FScrollBarKind, nodefault};
	__property int VisibleButtonCount = {read=FVisibleButtonCount, nodefault};
	
__published:
	__property Vcl::Imglist::TCustomImageList* ButtonImages = {read=FButtonImages, write=SetButtonImages};
	__property TcxSchedulerNavigatorButtons* Buttons = {read=FButtons, write=SetButtons};
	__property TcxSchedulerNavigatorCustomButtons* CustomButtons = {read=FCustomButtons, write=SetCustomButtons, stored=IsCustomButtonsStored};
	__property bool ShowButtons = {read=FShowButtons, write=SetShowButtons, default=1};
	__property TcxSchedulerNavigatorVisibilityMode Visibility = {read=FVisibility, write=SetVisibility, default=2};
	__property TcxSchedulerNavigatorButtonClickEvent OnButtonClick = {read=FOnButtonClick, write=FOnButtonClick};
	__property TcxSchedulerNavigatorCustomDrawButtonEvent OnCustomDrawButton = {read=FOnCustomDrawButton, write=FOnCustomDrawButton};
};


class DELPHICLASS TcxSchedulerEventOperations;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerEventOperations : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomScheduler* FScheduler;
	bool FCreating;
	bool FDeleting;
	bool FDialogEditing;
	bool FDialogShowing;
	bool FInplaceEditing;
	bool FIntersection;
	bool FMoving;
	bool FMovingBetweenResources;
	bool FReadOnly;
	bool FRecurrence;
	bool FSharingBetweenResources;
	bool FSizing;
	bool __fastcall GetCreating(void);
	bool __fastcall GetCreatingStored(void);
	bool __fastcall GetDeleting(void);
	bool __fastcall GetDeletingStored(void);
	bool __fastcall GetDialogEditing(void);
	bool __fastcall GetDialogEditingStored(void);
	bool __fastcall GetInplaceEditing(void);
	bool __fastcall GetInplaceEditingStored(void);
	bool __fastcall GetMoving(void);
	bool __fastcall GetMovingBetweenResources(void);
	bool __fastcall GetMovingBetweenResourcesStored(void);
	bool __fastcall GetMovingStored(void);
	bool __fastcall GetSizing(void);
	bool __fastcall GetSizingStored(void);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
	
public:
	__fastcall virtual TcxSchedulerEventOperations(TcxCustomScheduler* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Creating = {read=GetCreating, write=FCreating, stored=GetCreatingStored, nodefault};
	__property bool Deleting = {read=GetDeleting, write=FDeleting, stored=GetDeletingStored, nodefault};
	__property bool DialogEditing = {read=GetDialogEditing, write=FDialogEditing, stored=GetDialogEditingStored, nodefault};
	__property bool DialogShowing = {read=FDialogShowing, write=FDialogShowing, default=1};
	__property bool InplaceEditing = {read=GetInplaceEditing, write=FInplaceEditing, stored=GetInplaceEditingStored, nodefault};
	__property bool Intersection = {read=FIntersection, write=FIntersection, default=1};
	__property bool MovingBetweenResources = {read=GetMovingBetweenResources, write=FMovingBetweenResources, stored=GetMovingBetweenResourcesStored, nodefault};
	__property bool Moving = {read=GetMoving, write=FMoving, stored=GetMovingStored, nodefault};
	__property bool ReadOnly = {read=FReadOnly, write=FReadOnly, default=0};
	__property bool Recurrence = {read=FRecurrence, write=FRecurrence, default=1};
	__property bool SharingBetweenResources = {read=FSharingBetweenResources, write=FSharingBetweenResources, default=0};
	__property bool Sizing = {read=GetSizing, write=FSizing, stored=GetSizingStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerEventOperations(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerOptionsCustomize;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerOptionsCustomize : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FControlsSizing;
	bool FDynamicSizing;
	bool FIntegralSizing;
	TcxCustomScheduler* FScheduler;
	void __fastcall SetControlsSizing(bool AValue);
	void __fastcall SetIntegralSizing(bool AValue);
	
protected:
	virtual void __fastcall Changed(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxSchedulerOptionsCustomize(TcxCustomScheduler* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
	
__published:
	__property bool ControlsSizing = {read=FControlsSizing, write=SetControlsSizing, default=1};
	__property bool DynamicSizing = {read=FDynamicSizing, write=FDynamicSizing, default=0};
	__property bool IntegralSizing = {read=FIntegralSizing, write=SetIntegralSizing, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerOptionsCustomize(void) { }
	
};

#pragma pack(pop)

enum TcxSchedulerHeaderImagePosition : unsigned char { ipLeft, ipTop, ipRight, ipBottom };

class DELPHICLASS TcxSchedulerResourceHeaders;
class DELPHICLASS TcxSchedulerOptionsView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerResourceHeaders : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FHeight;
	TcxSchedulerHeaderImagePosition FImagePosition;
	bool FMultilineCaptions;
	TcxSchedulerOptionsView* FOwner;
	bool FRotateCaptions;
	void __fastcall SetHeight(int AValue);
	void __fastcall SetImagePosition(TcxSchedulerHeaderImagePosition AValue);
	void __fastcall SetMultilineCaptions(bool AValue);
	void __fastcall SetRotateCations(bool AValue);
	bool __fastcall IsImagePositionStored(void);
	
protected:
	void __fastcall Changed(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	__property TcxSchedulerOptionsView* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxSchedulerResourceHeaders(TcxSchedulerOptionsView* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int Height = {read=FHeight, write=SetHeight, default=0};
	__property bool MultilineCaptions = {read=FMultilineCaptions, write=SetMultilineCaptions, default=0};
	__property TcxSchedulerHeaderImagePosition ImagePosition = {read=FImagePosition, write=SetImagePosition, stored=IsImagePositionStored, nodefault};
	__property bool RotateCaptions = {read=FRotateCaptions, write=SetRotateCations, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerResourceHeaders(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxSchedulerOptionsView : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	typedef System::StaticArray<System::UnicodeString, 2> _TcxSchedulerOptionsView__1;
	
	
private:
	Cxdateutils::TDay FActualStartOfWeek;
	bool FAdditionalTimeZoneDaylightSaving;
	bool FCurrentTimeZoneDaylightSaving;
	System::Uitypes::TColor FDayBorderColor;
	System::Uitypes::TColor FEventBorderColor;
	int FEventHeight;
	TcxSchedulerGroupingKind FGroupingKind;
	int FGroupSeparatorWidth;
	bool FHideSelection;
	int FHorzSplitterWidth;
	bool FHotTrack;
	TcxSchedulerResourceHeaders* FResourceHeaders;
	int FResourcesPerPage;
	TcxCustomScheduler* FScheduler;
	bool FShowAdditionalTimeZone;
	bool FShowEventsWithoutResource;
	bool FShowHints;
	bool FShowNavigationButtons;
	Cxschedulerutils::TcxStartOfWeek FStartOfWeek;
	_TcxSchedulerOptionsView__1 FTimeZoneLabels;
	System::StaticArray<int, 2> FTimeZones;
	int FVertSplitterWidth;
	TcxSchedulerViewPosition FViewPosition;
	Cxdateutils::TDays FWorkDays;
	System::TTime FWorkFinish;
	bool FWorkFinishAssigned;
	System::TTime FWorkStart;
	bool FWorkStartAssigned;
	Cxschedulerutils::TcxSchedulerDateTimeHelperClass __fastcall GetDateTimeHelperClass(void);
	bool __fastcall GetRotateResourceCaptions(void);
	int __fastcall GetTimeZone(int AIndex);
	System::UnicodeString __fastcall GetTimeZoneLabel(int AIndex);
	bool __fastcall IsTimeZoneLabelStored(int AIndex);
	void __fastcall SetATZDaylightSaving(bool AValue);
	void __fastcall SetCTZDaylightSaving(bool AValue);
	void __fastcall SetDayBorderColor(System::Uitypes::TColor AValue);
	void __fastcall SetEventBorderColor(System::Uitypes::TColor AValue);
	void __fastcall SetEventHeight(int AValue);
	void __fastcall SetGroupingKind(TcxSchedulerGroupingKind AValue);
	void __fastcall SetGroupSeparatorWidth(int AValue);
	void __fastcall SetHideSelection(bool AValue);
	void __fastcall SetHorzSplitterWidth(int AValue);
	void __fastcall SetResourceHeaders(TcxSchedulerResourceHeaders* AValue);
	void __fastcall SetResourcesPerPage(int AValue);
	void __fastcall SetRotateResourceCaptions(bool AValue);
	void __fastcall SetShowAdditionalTimeZone(bool AValue);
	void __fastcall SetShowEventsWithoutResource(bool AValue);
	void __fastcall SetShowNavigationButtons(bool AValue);
	void __fastcall SetSplitterWidth(int AValue, int &AWidth);
	void __fastcall SetStartOfWeek(Cxschedulerutils::TcxStartOfWeek AValue);
	void __fastcall SetTimeZone(int AIndex, int AValue);
	void __fastcall SetTimeZoneLabel(int AIndex, const System::UnicodeString AValue);
	void __fastcall SetVertSplitterWidth(int AValue);
	void __fastcall SetViewPosition(TcxSchedulerViewPosition AValue);
	void __fastcall SetWorkDays(Cxdateutils::TDays AValue);
	void __fastcall SetWorkFinish(System::TTime AValue);
	void __fastcall SetWorkStart(System::TTime AValue);
	void __fastcall ReadWorkFinish(System::Classes::TReader* AReader);
	void __fastcall ReadWorkStart(System::Classes::TReader* AReader);
	void __fastcall WriteWorkFinish(System::Classes::TWriter* AWriter);
	void __fastcall WriteWorkStart(System::Classes::TWriter* AWriter);
	
protected:
	void __fastcall CalculateActualStartOfWeek(void);
	virtual void __fastcall Changed(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	bool __fastcall IsWorkDaysStored(void);
	bool __fastcall IsWorkTime(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResourceItem, const System::TDateTime ADateTime);
	__property Cxschedulerutils::TcxSchedulerDateTimeHelperClass DateTimeHelper = {read=GetDateTimeHelperClass};
	__property bool HotTrack = {read=FHotTrack, write=FHotTrack, default=0};
	
public:
	__fastcall virtual TcxSchedulerOptionsView(TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerOptionsView(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Cxdateutils::TDay ActualStartOfWeek = {read=FActualStartOfWeek, nodefault};
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
	
__published:
	__property int AdditionalTimeZone = {read=GetTimeZone, write=SetTimeZone, index=0, default=-1};
	__property bool AdditionalTimeZoneDaylightSaving = {read=FAdditionalTimeZoneDaylightSaving, write=SetATZDaylightSaving, default=0};
	__property System::UnicodeString AdditionalTimeZoneLabel = {read=GetTimeZoneLabel, write=SetTimeZoneLabel, stored=IsTimeZoneLabelStored, index=0};
	__property int CurrentTimeZone = {read=GetTimeZone, write=SetTimeZone, index=1, default=-1};
	__property bool CurrentTimeZoneDaylightSaving = {read=FCurrentTimeZoneDaylightSaving, write=SetCTZDaylightSaving, default=0};
	__property System::UnicodeString CurrentTimeZoneLabel = {read=GetTimeZoneLabel, write=SetTimeZoneLabel, stored=IsTimeZoneLabelStored, index=1};
	__property System::Uitypes::TColor DayBorderColor = {read=FDayBorderColor, write=SetDayBorderColor, default=536870912};
	__property System::Uitypes::TColor EventBorderColor = {read=FEventBorderColor, write=SetEventBorderColor, default=0};
	__property int EventHeight = {read=FEventHeight, write=SetEventHeight, default=0};
	__property TcxSchedulerGroupingKind GroupingKind = {read=FGroupingKind, write=SetGroupingKind, default=0};
	__property int GroupSeparatorWidth = {read=FGroupSeparatorWidth, write=SetGroupSeparatorWidth, default=11};
	__property bool HideSelection = {read=FHideSelection, write=SetHideSelection, default=0};
	__property int HorzSplitterWidth = {read=FHorzSplitterWidth, write=SetHorzSplitterWidth, default=5};
	__property TcxSchedulerResourceHeaders* ResourceHeaders = {read=FResourceHeaders, write=SetResourceHeaders};
	__property int ResourcesPerPage = {read=FResourcesPerPage, write=SetResourcesPerPage, default=0};
	__property bool RotateResourceCaptions = {read=GetRotateResourceCaptions, write=SetRotateResourceCaptions, default=1};
	__property bool ShowAdditionalTimeZone = {read=FShowAdditionalTimeZone, write=SetShowAdditionalTimeZone, default=0};
	__property bool ShowEventsWithoutResource = {read=FShowEventsWithoutResource, write=SetShowEventsWithoutResource, default=0};
	__property bool ShowHints = {read=FShowHints, write=FShowHints, default=1};
	__property bool ShowNavigationButtons = {read=FShowNavigationButtons, write=SetShowNavigationButtons, default=1};
	__property Cxschedulerutils::TcxStartOfWeek StartOfWeek = {read=FStartOfWeek, write=SetStartOfWeek, default=0};
	__property int VertSplitterWidth = {read=FVertSplitterWidth, write=SetVertSplitterWidth, default=5};
	__property TcxSchedulerViewPosition ViewPosition = {read=FViewPosition, write=SetViewPosition, default=1};
	__property Cxdateutils::TDays WorkDays = {read=FWorkDays, write=SetWorkDays, stored=IsWorkDaysStored, nodefault};
	__property System::TTime WorkFinish = {read=FWorkFinish, write=SetWorkFinish, stored=false};
	__property System::TTime WorkStart = {read=FWorkStart, write=SetWorkStart, stored=false};
};


enum TcxEventDragKind : unsigned char { edkNone, edkEventDragRect, edkMoveEvent, edkResizeStart, edkResizeEnd };

class DELPHICLASS TcxSchedulerViewHitTest;
class PASCALIMPLEMENTATION TcxSchedulerViewHitTest : public TcxSchedulerSubControlHitTest
{
	typedef TcxSchedulerSubControlHitTest inherited;
	
private:
	bool __fastcall GetHitAtEvent(void);
	bool __fastcall GetNeedShowHint(void);
	
protected:
	bool FNeedShowHint;
	System::Types::TRect FEventBounds;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FResource;
	virtual void __fastcall Clear(void);
	virtual Cxschedulerstorage::TcxSchedulerControlEvent* __fastcall GetHitEvent(void);
	__property bool NeedShowHint = {read=GetNeedShowHint, nodefault};
	
public:
	virtual TcxEventDragKind __fastcall GetDragKind(void);
	__property bool HitAtEvent = {read=GetHitAtEvent, nodefault};
	__property bool HitAtResource = {read=GetBitState, index=2, nodefault};
	__property Cxschedulerstorage::TcxSchedulerControlEvent* Event = {read=GetHitEvent};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItem* Resource = {read=FResource};
public:
	/* TcxSchedulerSubControlHitTest.Create */ inline __fastcall virtual TcxSchedulerViewHitTest(TcxSchedulerSubControl* AOwner) : TcxSchedulerSubControlHitTest(AOwner) { }
	/* TcxSchedulerSubControlHitTest.Destroy */ inline __fastcall virtual ~TcxSchedulerViewHitTest(void) { }
	
};


class DELPHICLASS TcxSchedulerEditController;
class DELPHICLASS TcxSchedulerViewController;
class DELPHICLASS TcxSchedulerCustomView;
class PASCALIMPLEMENTATION TcxSchedulerEditController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxedit::TcxCustomEdit* FEdit;
	Cxedit::TcxCustomEditData* FEditData;
	System::TDateTime FEditDate;
	Cxedit::TcxInplaceEditList* FEditList;
	Cxedit::TcxCustomEditProperties* FEditProperties;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FEditResource;
	Cxschedulerstorage::TcxSchedulerControlEvent* FEvent;
	bool FFocused;
	bool FIsEditing;
	bool FIsNewEvent;
	TcxCustomScheduler* FOwner;
	bool __fastcall CanAccept(void);
	TcxSchedulerViewController* __fastcall GetController(void);
	bool __fastcall GetEditVisible(void);
	TcxSchedulerCustomView* __fastcall GetView(void);
	void __fastcall SetEditVisible(bool Value);
	
protected:
	virtual bool __fastcall GetEditRect(System::Types::TRect &R, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, bool AMakeVisible = false);
	virtual void __fastcall EditAfterKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditExit(System::TObject* Sender);
	virtual void __fastcall EditKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditKeyPress(System::TObject* Sender, System::WideChar &Key);
	virtual void __fastcall EditKeyUp(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall EditPostEditValue(System::TObject* Sender);
	virtual bool __fastcall InitEdit(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall IsKeyForControl(System::Word &AKey, System::Classes::TShiftState Shift);
	virtual void __fastcall PrepareEdit(Cxedit::TcxCustomEdit* AEdit);
	__property Cxedit::TcxCustomEditProperties* EditProperties = {read=FEditProperties};
	__property Cxedit::TcxCustomEditData* EditData = {read=FEditData};
	__property Cxschedulerstorage::TcxSchedulerControlEvent* Event = {read=FEvent};
	
public:
	__fastcall virtual TcxSchedulerEditController(TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerEditController(void);
	void __fastcall Activate(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent)/* overload */;
	void __fastcall Activate(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::Types::TPoint &APos, System::Classes::TShiftState AShift)/* overload */;
	void __fastcall Activate(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, System::WideChar Key)/* overload */;
	virtual void __fastcall CloseEdit(bool Accepted);
	void __fastcall DeleteEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall Init(const System::TDateTime AEditDate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, bool AIsNewEvent = false);
	virtual void __fastcall UpdateEdit(void);
	virtual void __fastcall UpdateValue(void);
	__property TcxSchedulerViewController* Controller = {read=GetController};
	__property Cxedit::TcxCustomEdit* Edit = {read=FEdit};
	__property bool EditVisible = {read=GetEditVisible, write=SetEditVisible, nodefault};
	__property bool Focused = {read=FFocused, write=FFocused, nodefault};
	__property bool IsEditing = {read=FIsEditing, nodefault};
	__property TcxCustomScheduler* Scheduler = {read=FOwner};
	__property TcxSchedulerCustomView* View = {read=GetView};
};


class DELPHICLASS TcxSchedulerViewNavigation;
class PASCALIMPLEMENTATION TcxSchedulerViewNavigation : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerCustomView* FView;
	TcxSchedulerResourceNavigator* __fastcall GetResourceNavigator(void);
	TcxCustomScheduler* __fastcall GetScheduler(void);
	System::TDateTime __fastcall GetSelAnchor(void);
	System::TDateTime __fastcall GetSelRealStart(void);
	System::TDateTime __fastcall GetSelFinish(void);
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetSelResource(void);
	System::TDateTime __fastcall GetSelStart(void);
	System::TDateTime __fastcall GetTimeIncrement(void);
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetVisibleResource(int AIndex);
	int __fastcall GetVisibleResourceCount(void);
	
protected:
	System::TDateTime FCurrentAnchor;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FCurrentResource;
	System::Classes::TShiftState FShift;
	virtual void __fastcall DoKeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	virtual bool __fastcall IsKeyNavigation(System::Word &AKey, System::Classes::TShiftState AShift);
	bool __fastcall IsSingleLine(void);
	virtual Cxschedulerstorage::TcxSchedulerStorageResourceItem* __fastcall GetResourceItem(void);
	virtual void __fastcall KeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	void __fastcall ReplaceDate(System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource = (Cxschedulerstorage::TcxSchedulerStorageResourceItem*)(0x0));
	
public:
	__fastcall TcxSchedulerViewNavigation(TcxSchedulerCustomView* AView);
	void __fastcall CheckSelection(void);
	void __fastcall ReplaceSelParams(const System::TDateTime ASelStart, const System::TDateTime ASelFinish)/* overload */;
	void __fastcall ReplaceSelParams(const System::TDateTime ASelStart, const System::TDateTime ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource)/* overload */;
	void __fastcall ReplaceSelParams(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource)/* overload */;
	bool __fastcall ScrollResources(bool AGoForward);
	bool __fastcall ScrollResourcesCycled(bool AGoForward, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	virtual bool __fastcall ScrollResourcesEx(bool AGoForward, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	void __fastcall SetSelAnchor(const System::TDateTime Anchor, System::Classes::TShiftState AShift)/* overload */;
	void __fastcall SetSelAnchor(const System::TDateTime Anchor, System::Classes::TShiftState AShift, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource)/* overload */;
	virtual void __fastcall ValidateSelection(System::TDateTime &ASelStart, System::TDateTime &ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* &AResource);
	__property TcxSchedulerResourceNavigator* ResourceNavigator = {read=GetResourceNavigator};
	__property System::TDateTime SelAnchor = {read=GetSelAnchor};
	__property System::TDateTime SelFinish = {read=GetSelFinish};
	__property System::TDateTime SelRealStart = {read=GetSelRealStart};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItem* SelResource = {read=GetSelResource};
	__property System::TDateTime SelStart = {read=GetSelStart};
	__property TcxCustomScheduler* Scheduler = {read=GetScheduler};
	__property System::TDateTime TimeIncrement = {read=GetTimeIncrement};
	__property TcxSchedulerCustomView* View = {read=FView};
	__property int VisibleResourceCount = {read=GetVisibleResourceCount, nodefault};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItem* VisibleResources[int AIndex] = {read=GetVisibleResource};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerViewNavigation(void) { }
	
};


class DELPHICLASS TcxDragEventHelper;
class DELPHICLASS TcxSchedulerDragAndDropObject;
class DELPHICLASS TcxEventSizingHelper;
class PASCALIMPLEMENTATION TcxSchedulerViewController : public TcxSchedulerSubControlController
{
	typedef TcxSchedulerSubControlController inherited;
	
private:
	Vcl::Extctrls::TTimer* FEditShowingTimer;
	Cxschedulerstorage::TcxSchedulerControlEvent* FEditShowingTimerItem;
	TcxDragEventHelper* FDragEventHelper;
	Cxschedulerstorage::TcxSchedulerControlEvent* FDragEvent;
	TcxEventDragKind FDragKind;
	TcxSchedulerViewNavigation* FNavigation;
	__int64 FStartDragFlags;
	System::TDateTime FStartDragHitTime;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FStartDragResource;
	void __fastcall EditShowingTimerHandler(System::TObject* Sender);
	TcxSchedulerEditController* __fastcall GetEditController(void);
	HIDESBASE TcxSchedulerViewHitTest* __fastcall GetHitTest(void);
	bool __fastcall GetIsEditing(void);
	Vcl::Extctrls::TTimer* __fastcall GetNavigatorTimer(void);
	TcxCustomScheduler* __fastcall GetScheduler(void);
	TcxSchedulerCustomView* __fastcall GetView(void);
	void __fastcall ShowEventEditor(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall StartEditShowingTimer(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall StopEditShowingTimer(void);
	
protected:
	TcxSchedulerDragAndDropObject* DragAndDropObject;
	System::Types::TRect FDownScrollArea;
	Cxschedulerstorage::TcxSchedulerControlEvent* FBeforeFocusedEvent;
	System::TDateTime FStartSelAnchor;
	System::Types::TRect FUpScrollArea;
	virtual void __fastcall BeforeMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall CancelScroll(void);
	virtual bool __fastcall CanDrag(int X, int Y);
	virtual void __fastcall CheckOpenInplaceEditorOnMouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall CheckScrolling(const System::Types::TPoint &APos);
	void __fastcall CheckScrollOnDragOver(const System::Types::TPoint &P, System::Uitypes::TDragState State);
	void __fastcall CheckUpdateEventBounds(void);
	void __fastcall CloseInplaceEdit(void);
	virtual bool __fastcall ConsiderHiddenEvents(void);
	virtual TcxDragEventHelper* __fastcall CreateDragEventHelper(void);
	virtual TcxSchedulerViewNavigation* __fastcall CreateNavigation(void);
	virtual TcxEventSizingHelper* __fastcall CreateResizeEventHelper(void);
	void __fastcall DoSchedulerDragOver(const System::Types::TPoint &P, System::Uitypes::TDragState AState, bool &AAccept);
	virtual void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	virtual void __fastcall EndDrag(System::TObject* Target, int X, int Y);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	bool __fastcall GetResourceReadOnly(void);
	bool __fastcall IsCaptionAvailable(void);
	bool __fastcall IsCopyDragDrop(void);
	bool __fastcall IsDragOperation(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall RecreateNavigation(void);
	virtual void __fastcall SelectNextEvent(bool AForward);
	virtual void __fastcall StartDrag(Vcl::Controls::TDragObject* &DragObject);
	virtual bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	virtual void __fastcall SyncEventSelection(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall UnselectEvents(void);
	void __fastcall UpdateEventSelection(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift);
	virtual void __fastcall CheckNavigatorScrollArea(const System::Types::TPoint &APoint);
	virtual void __fastcall DoneNavigatorScrollArea(void);
	virtual void __fastcall InitNavigatorScrollArea(void);
	virtual void __fastcall NavigatorTimerHandler(System::TObject* Sender);
	bool __fastcall PtInArea(const System::Types::TRect &ARect, const System::Types::TPoint &P, bool IsUpArea);
	__property TcxSchedulerEditController* EditController = {read=GetEditController};
	__property TcxDragEventHelper* DragEventHelper = {read=FDragEventHelper};
	__property TcxSchedulerViewHitTest* HitTest = {read=GetHitTest};
	__property Vcl::Extctrls::TTimer* NavigatorTimer = {read=GetNavigatorTimer};
	__property TcxSchedulerCustomView* View = {read=GetView};
	
public:
	__fastcall virtual TcxSchedulerViewController(TcxSchedulerSubControl* AOwner);
	__fastcall virtual ~TcxSchedulerViewController(void);
	virtual bool __fastcall CanCreateEventUsingDialog(void);
	virtual bool __fastcall CanCreateEventUsingInplaceEdit(void);
	virtual bool __fastcall CanEditEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool AInplace);
	virtual bool __fastcall CanShowEventDialog(void);
	void __fastcall DeleteSelectedEvents(void);
	bool __fastcall IsEventEditing(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	void __fastcall SelectSingleEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, System::TDateTime ADate, bool AMakeVisible = true);
	__property Cxschedulerstorage::TcxSchedulerControlEvent* DragEvent = {read=FDragEvent};
	__property TcxEventDragKind DragKind = {read=FDragKind, nodefault};
	__property bool IsEditing = {read=GetIsEditing, nodefault};
	__property TcxSchedulerViewNavigation* Navigation = {read=FNavigation};
	__property TcxCustomScheduler* Scheduler = {read=GetScheduler};
	__property __int64 StartDragFlags = {read=FStartDragFlags};
	__property System::TDateTime StartDragHitTime = {read=FStartDragHitTime};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItem* StartDragResource = {read=FStartDragResource};
};


enum TcxSchedulerDragOverDestination : unsigned char { dodView, dodControlBox, dodDateNavigator, dodOther };

class DELPHICLASS TcxDragHelper;
class DELPHICLASS TcxSchedulerCustomDateNavigator;
class PASCALIMPLEMENTATION TcxDragHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::TDateTime FActualHitTime;
	bool FAcceptedChanged;
	TcxSchedulerDragOverDestination FDestination;
	System::Uitypes::TCursor FSaveCursor;
	TcxCustomScheduler* FScheduler;
	System::TDateTime __fastcall GetActualHitTime(void);
	TcxSchedulerViewController* __fastcall GetController(void);
	TcxSchedulerCustomDateNavigator* __fastcall GetDateNavigator(void);
	Cxschedulerstorage::TcxSchedulerCachedEventList* __fastcall GetEvents(void);
	TcxSchedulerViewHitTest* __fastcall GetHitTest(void);
	
protected:
	bool FHasConflicts;
	bool FPrevAccepted;
	__int64 FPrevHitFlags;
	System::TDateTime FPrevHitTime;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FPrevHitResource;
	System::TDateTime FStartHitTime;
	__int64 FStartHitFlags;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FStartResource;
	virtual void __fastcall BeginDrag(void);
	void __fastcall CalculateConflicts(void);
	void __fastcall CalculateDestination(void);
	bool __fastcall CanUpdateEventState(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall CheckAccepted(bool &Accepted);
	void __fastcall CheckEventState(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall DragOver(const System::Types::TPoint &P, System::Uitypes::TDragState State, bool &Accepted);
	virtual void __fastcall EndDrag(bool Accepted);
	virtual __int64 __fastcall GetOriginHitTestMask(void);
	virtual void __fastcall GetOriginState(void);
	virtual bool __fastcall HasChangedState(void);
	virtual bool __fastcall IsAtOrigin(void);
	bool __fastcall IsShowResources(void);
	virtual bool __fastcall IsValidTime(void);
	virtual void __fastcall RefreshCurrentView(void);
	virtual void __fastcall SetSelection(void);
	virtual void __fastcall UpdateHelperState(bool Accepted);
	__property System::Uitypes::TCursor SaveCursor = {read=FSaveCursor, nodefault};
	
public:
	__fastcall virtual TcxDragHelper(TcxCustomScheduler* AScheduler);
	__property System::TDateTime ActualHitTime = {read=FActualHitTime};
	__property TcxSchedulerViewController* Controller = {read=GetController};
	__property TcxSchedulerCustomDateNavigator* DateNavigator = {read=GetDateNavigator};
	__property TcxSchedulerDragOverDestination Destination = {read=FDestination, nodefault};
	__property Cxschedulerstorage::TcxSchedulerCachedEventList* Events = {read=GetEvents};
	__property bool HasConflicts = {read=FHasConflicts, nodefault};
	__property TcxSchedulerViewHitTest* HitTest = {read=GetHitTest};
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDragHelper(void) { }
	
};


class DELPHICLASS TcxSchedulerDragObject;
class PASCALIMPLEMENTATION TcxSchedulerDragObject : public Cxcontrols::TcxDragControlObject
{
	typedef Cxcontrols::TcxDragControlObject inherited;
	
private:
	bool FUseInternalCursors;
	TcxDragEventHelper* __fastcall GetDragEventHelper(void);
	Cxschedulerstorage::TcxSchedulerFilteredEventList* __fastcall GetDragEvents(void);
	bool __fastcall GetHasConflicts(void);
	TcxCustomScheduler* __fastcall GetScheduler(void);
	
protected:
	virtual void __fastcall Finished(System::TObject* Target, int X, int Y, bool Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragCursor(bool Accepted, int X, int Y);
	
public:
	__fastcall virtual TcxSchedulerDragObject(Vcl::Controls::TControl* AControl);
	void __fastcall CalculateConflictsForDateNavigator(TcxSchedulerCustomDateNavigator* ADateNavigator);
	void __fastcall DropToDateNavigator(TcxSchedulerCustomDateNavigator* ADateNavigator);
	__property TcxDragEventHelper* DragEventHelper = {read=GetDragEventHelper};
	__property Cxschedulerstorage::TcxSchedulerFilteredEventList* DragEvents = {read=GetDragEvents};
	__property bool HasConflicts = {read=GetHasConflicts, nodefault};
	__property TcxCustomScheduler* Scheduler = {read=GetScheduler};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerDragObject(void) { }
	
};


class DELPHICLASS TcxSchedulerCustomViewViewInfo;
class PASCALIMPLEMENTATION TcxDragEventHelper : public TcxDragHelper
{
	typedef TcxDragHelper inherited;
	
private:
	Vcl::Controls::TDragObject* FDragObject;
	Cxschedulerstorage::TcxSchedulerFilteredEventList* __fastcall GetClones(void);
	TcxSchedulerCustomViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	bool FPrevIsDragCopy;
	System::TObject* FTarget;
	virtual void __fastcall ApplyChanges(void);
	virtual void __fastcall BeginDrag(void);
	virtual void __fastcall CheckAccepted(bool &Accepted);
	void __fastcall CheckVisibility(bool Accepted);
	virtual void __fastcall DragOver(const System::Types::TPoint &P, System::Uitypes::TDragState State, bool &Accepted);
	virtual void __fastcall EndDrag(bool Accepted);
	void __fastcall DateNavigatorEndDrag(void);
	virtual bool __fastcall GetClonesVisible(bool Accepted);
	virtual bool __fastcall GetIsDragCopy(void);
	virtual void __fastcall GetOriginState(void);
	virtual bool __fastcall GetSourcesVisible(bool Accepted);
	virtual bool __fastcall HasChangedState(void);
	virtual bool __fastcall IsValidNavigatorDate(void);
	virtual bool __fastcall IsValidTime(void);
	void __fastcall PrepareClones(void);
	void __fastcall ProcessDateNavigator(TcxSchedulerCustomDateNavigator* ADateNavigator);
	virtual void __fastcall SetSelection(void);
	void __fastcall Update(bool Accepted = true);
	void __fastcall UpdateClones(void);
	virtual void __fastcall UpdateHelperState(bool Accepted);
	virtual void __fastcall UpdateDateNavigatorClones(TcxSchedulerCustomDateNavigator* ADateNavigator);
	virtual void __fastcall UpdateDateNavigator(bool &Accepted);
	virtual void __fastcall UpdateViewClones(void);
	void __fastcall UpdateViewClonesResources(void);
	virtual void __fastcall UpdateViewClonesTime(void);
	__property Cxschedulerstorage::TcxSchedulerFilteredEventList* Clones = {read=GetClones};
	__property Vcl::Controls::TDragObject* DragObject = {read=FDragObject};
	__property bool IsDragCopy = {read=GetIsDragCopy, nodefault};
	__property TcxSchedulerCustomViewViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxDragEventHelper(TcxCustomScheduler* AScheduler) : TcxDragHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDragEventHelper(void) { }
	
};


class PASCALIMPLEMENTATION TcxEventSizingHelper : public TcxDragHelper
{
	typedef TcxDragHelper inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerControlEvent* __fastcall GetEvent(void);
	HIDESBASE TcxSchedulerViewHitTest* __fastcall GetHitTest(void);
	
protected:
	virtual void __fastcall BeginDrag(void);
	virtual void __fastcall DragOver(const System::Types::TPoint &P, System::Uitypes::TDragState State, bool &Accepted);
	virtual void __fastcall EndDrag(bool Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragCursor(bool Accepted);
	virtual bool __fastcall IsValidTime(void);
	virtual void __fastcall CalcAllDayEvent(void);
	virtual System::TDateTime __fastcall GetFinishTime(void);
	virtual System::TDateTime __fastcall GetStartTime(void);
	virtual void __fastcall UpdateEventBounds(void);
	__property Cxschedulerstorage::TcxSchedulerControlEvent* Event = {read=GetEvent};
	__property TcxSchedulerViewHitTest* HitTest = {read=GetHitTest};
public:
	/* TcxDragHelper.Create */ inline __fastcall virtual TcxEventSizingHelper(TcxCustomScheduler* AScheduler) : TcxDragHelper(AScheduler) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEventSizingHelper(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerDragAndDropObject : public Cxcontrols::TcxDragAndDropObject
{
	typedef Cxcontrols::TcxDragAndDropObject inherited;
	
private:
	TcxEventSizingHelper* FSizingHelper;
	TcxCustomScheduler* FScheduler;
	TcxSchedulerViewController* __fastcall GetController(void);
	TcxSchedulerViewHitTest* __fastcall GetHitTest(void);
	
protected:
	virtual void __fastcall BeginDragAndDrop(void);
	virtual void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	virtual void __fastcall EndDragAndDrop(bool Accepted);
	virtual System::Uitypes::TCursor __fastcall GetDragAndDropCursor(bool Accepted);
	
public:
	__fastcall virtual TcxSchedulerDragAndDropObject(Cxcontrols::TcxControl* AControl);
	__fastcall virtual ~TcxSchedulerDragAndDropObject(void);
	__property TcxSchedulerViewController* Controller = {read=GetController};
	__property TcxEventSizingHelper* SizingHelper = {read=FSizingHelper};
	__property TcxSchedulerViewHitTest* HitTest = {read=GetHitTest};
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerHintController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
protected:
	bool FAutoHide;
	Vcl::Controls::THintWindow* FHintWindow;
	TcxCustomScheduler* FOwner;
	int FHintFlags;
	System::Types::TRect FHintRect;
	System::UnicodeString FHintText;
	bool FLockHint;
	bool FShowing;
	Vcl::Extctrls::TTimer* FTimer;
	bool FViewMode;
	void __fastcall MouseLeave(void);
	virtual bool __fastcall CanShowHint(void);
	void __fastcall CheckHintClass(void);
	virtual void __fastcall HideHint(void);
	virtual void __fastcall ShowHint(void);
	void __fastcall StartHideHintTimer(void);
	void __fastcall StartShowHintTimer(void);
	void __fastcall StopTimer(void);
	void __fastcall TimerHandler(System::TObject* Sender);
	int HintWindowAnchor;
	
public:
	__fastcall virtual TcxSchedulerHintController(TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerHintController(void);
	virtual void __fastcall Activate(const System::Types::TRect &AHintRect, const System::UnicodeString AHintText, bool AImmediateHint = false, bool AAutoHide = true);
	System::Types::TRect __fastcall CalcHintRect(int AMaxWidth, const System::UnicodeString AHintText, int AFlags);
	void __fastcall Hide(void);
	void __fastcall Reset(void);
	__property TcxCustomScheduler* Scheduler = {read=FOwner};
	__property bool ViewMode = {read=FViewMode, write=FViewMode, nodefault};
	__property bool Showing = {read=FShowing, nodefault};
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxMouseTrackingCaller; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerEventHitTestController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerEventHitTestController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxSchedulerHintController* __fastcall GetHintController(void);
	TcxSchedulerViewHitTest* __fastcall GetHitTest(void);
	
protected:
	TcxCustomScheduler* FOwner;
	Cxschedulerstorage::TcxSchedulerControlEvent* FPrevHintEvent;
	
public:
	__fastcall virtual TcxSchedulerEventHitTestController(TcxCustomScheduler* AOwner);
	void __fastcall HideEventHint(void);
	virtual void __fastcall MouseMove(int X, int Y, System::Classes::TShiftState AShift);
	__property TcxSchedulerViewHitTest* HitTest = {read=GetHitTest};
	__property TcxSchedulerHintController* HintController = {read=GetHintController};
	__property TcxCustomScheduler* Scheduler = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerEventHitTestController(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerCustomView : public TcxSchedulerSubControl
{
	typedef TcxSchedulerSubControl inherited;
	
private:
	bool FCalculatedHintBounds;
	bool FCanShow;
	bool __fastcall GetActive(void);
	bool __fastcall GetCanShow(void);
	TcxSchedulerViewController* __fastcall GetController(void);
	Cxschedulerstorage::TcxSchedulerFilteredEventList* __fastcall GetDragCloneEventList(void);
	Cxschedulerstorage::TcxSchedulerCachedEventList* __fastcall GetEventList(void);
	TcxSchedulerViewHitTest* __fastcall GetHitTest(void);
	TcxSchedulerOptionsView* __fastcall GetOptionsView(void);
	Cxschedulerstorage::TcxSchedulerStorageResourceItems* __fastcall GetResources(void);
	Cxschedulerutils::TcxSchedulerDateList* __fastcall GetSelectedDays(void);
	Cxdateutils::TDays __fastcall GetWorkDays(void);
	System::TDateTime __fastcall GetWorkFinish(void);
	System::TDateTime __fastcall GetWorkStart(void);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetCanShow(bool AValue);
	
protected:
	virtual bool __fastcall CanDeactivateOnDateNavigatorSelectionChange(void);
	virtual bool __fastcall CanEventEdit(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool AInplace);
	virtual bool __fastcall CanSelectPeriod(void);
	virtual bool __fastcall CheckEventsVisibility(void);
	virtual TcxSchedulerSubControlController* __fastcall CreateController(void);
	virtual TcxSchedulerSubControlHitTest* __fastcall CreateHitTest(void);
	virtual void __fastcall DateChanged(void);
	virtual void __fastcall DeactivateView(void);
	virtual void __fastcall DoLayoutChanged(void);
	virtual bool __fastcall DoShowPopupMenu(int X, int Y);
	virtual bool __fastcall EventContentSelected(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall EventsListChanged(void);
	virtual System::Types::TRect __fastcall GetClientRect(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetControlCanvas(void);
	int __fastcall GetDateOffset(void);
	virtual Cxcontrols::TDragControlObjectClass __fastcall GetDragObjectClass(void);
	virtual Dxtouch::_di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint &APoint);
	virtual TcxSchedulerGroupingKind __fastcall GetGroupingKind(void);
	virtual System::Types::TRect __fastcall GetHScrollBarBounds(void);
	virtual System::Types::TRect __fastcall GetEditRectForEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual Cxedit::TcxCustomEditStyle* __fastcall GetEditStyle(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual Cxedit::TcxCustomEditProperties* __fastcall GetEditProperties(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall GetEditWithSingleLineEditor(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual System::UnicodeString __fastcall GetEventHintText(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall GetEventVisibility(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual System::TDateTime __fastcall GetFirstVisibleDate(void);
	virtual System::TDateTime __fastcall GetFirstVisibleTime(void);
	virtual System::TDateTime __fastcall GetLastVisibleDate(void);
	virtual System::TDateTime __fastcall GetLastVisibleTime(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetSchedulerLookAndFeel(bool ADialogs = false);
	virtual System::UnicodeString __fastcall GetScrollTimeHint(void);
	virtual bool __fastcall GetShowEventsWithoutResource(void);
	virtual System::Types::TRect __fastcall GetSizeGripBounds(void);
	virtual System::TDateTime __fastcall GetTimeIncrement(void);
	virtual System::Types::TRect __fastcall GetVScrollBarBounds(void);
	virtual System::Types::TRect __fastcall GetViewContentRect(void);
	virtual int __fastcall GetVisibleDaysRange(void);
	virtual void __fastcall InitEventBySelectedTime(Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool AllDay, bool ARecurrence, bool AInplaceEditing);
	bool __fastcall IsAllDaySelection(void);
	virtual bool __fastcall IsDayView(void);
	virtual bool __fastcall IsInplaceEditingEnabled(void);
	virtual bool __fastcall IsShowResources(void);
	bool __fastcall IsWorkTime(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResourceItem, const System::TDateTime ADateTime);
	virtual void __fastcall MakeEventVisible(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::TDateTime ADate, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall PeriodChanged(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall ScrollSelectedDays(int AScrollDelta)/* overload */;
	virtual void __fastcall ScrollSelectedDays(bool AForward, System::TDateTime ANeedDate, bool AIsByPage)/* overload */;
	virtual void __fastcall ScrollVisibleDays(bool AScrollUp);
	virtual void __fastcall SelectedDaysChanged(void);
	virtual bool __fastcall ShowTaskComplete(void);
	virtual void __fastcall TimeChanged(void);
	void __fastcall UpdateDateNavigatorSelection(void);
	virtual void __fastcall ValidateContentPopupMenuItems(TcxSchedulerContentPopupMenuItems &AItems);
	virtual void __fastcall ValidateSelectionFinishTime(System::TDateTime &ADateTime);
	virtual void __fastcall VisibleChanged(void);
	virtual void __fastcall HideHintOnScroll(System::Uitypes::TScrollCode AScrollCode);
	virtual void __fastcall ShowHintOnScroll(const System::TDateTime ADate)/* overload */;
	virtual void __fastcall ShowHintOnScroll(const System::UnicodeString AHintText, Vcl::Forms::TScrollBarKind AScrollBarKind)/* overload */;
	__property bool CalculatedHintBounds = {read=FCalculatedHintBounds, nodefault};
	__property TcxSchedulerViewController* Controller = {read=GetController};
	__property Cxschedulerstorage::TcxSchedulerCachedEventList* EventList = {read=GetEventList};
	__property System::TDateTime FirstVisibleTime = {read=GetFirstVisibleTime};
	__property System::TDateTime LastVisibleTime = {read=GetLastVisibleTime};
	__property TcxSchedulerOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItems* Resources = {read=GetResources};
	__property Cxdateutils::TDays WorkDays = {read=GetWorkDays, nodefault};
	__property System::TDateTime WorkStart = {read=GetWorkStart};
	__property System::TDateTime WorkFinish = {read=GetWorkFinish};
	
public:
	__fastcall virtual TcxSchedulerCustomView(TcxCustomScheduler* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property bool Active = {read=GetActive, write=SetActive, default=0};
	__property bool CanShow = {read=GetCanShow, write=SetCanShow, default=1};
	__property Cxschedulerstorage::TcxSchedulerFilteredEventList* DragCloneEventList = {read=GetDragCloneEventList};
	__property System::TDateTime FirstVisibleDate = {read=GetFirstVisibleDate};
	__property TcxSchedulerViewHitTest* HitTest = {read=GetHitTest};
	__property System::TDateTime LastVisibleDate = {read=GetLastVisibleDate};
	__property Cxschedulerutils::TcxSchedulerDateList* SelectedDays = {read=GetSelectedDays};
	__property StartOfWeek;
public:
	/* TcxSchedulerSubControl.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomView(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerCustomViewViewInfo : public TcxSchedulerSubControlViewInfo
{
	typedef TcxSchedulerSubControlViewInfo inherited;
	
private:
	TcxSchedulerResourceNavigator* __fastcall GetResourceNavigator(void);
	TcxCustomScheduler* __fastcall GetScheduler(void);
	
protected:
	Cxschedulerstorage::TcxSchedulerCachedEventList* FEvents;
	Cxschedulerutils::TcxSchedulerDateList* FSelectedDays;
	virtual void __fastcall CheckResourceNavigator(void);
	virtual System::UnicodeString __fastcall DoGetEventDisplayText(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	bool __fastcall DoSchedulerMoreEventsButtonClick(void);
	bool __fastcall DoSchedulerNavigationButtonClick(System::TDateTime AnInterval, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	System::UnicodeString __fastcall GetEventHint(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual Vcl::Forms::TScrollBarKind __fastcall GetResourceScrollBarKind(void);
	Cxschedulerstorage::TcxSchedulerCachedEventList* __fastcall GetSchedulerEventsList(void);
	virtual void __fastcall SetEventsVisibility(bool AShowSources, bool AShowClones, bool AForceRepaint = false);
	__property Cxschedulerstorage::TcxSchedulerCachedEventList* Events = {read=FEvents};
	__property TcxSchedulerResourceNavigator* ResourceNavigator = {read=GetResourceNavigator};
	__property TcxCustomScheduler* Scheduler = {read=GetScheduler};
	__property Cxschedulerutils::TcxSchedulerDateList* SelectedDays = {read=FSelectedDays};
public:
	/* TcxSchedulerSubControlViewInfo.Create */ inline __fastcall virtual TcxSchedulerCustomViewViewInfo(TcxSchedulerSubControl* AOwner) : TcxSchedulerSubControlViewInfo(AOwner) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomViewViewInfo(void) { }
	
};

#pragma pack(pop)

__interface IcxExternalDateNavigatorListener;
typedef System::DelphiInterface<IcxExternalDateNavigatorListener> _di_IcxExternalDateNavigatorListener;
__interface  INTERFACE_UUID("{32293211-4D89-4383-A95C-23B95C3A783D}") IcxExternalDateNavigatorListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall StorageChanged(void) = 0 ;
	virtual void __fastcall SchedulerChanged(void) = 0 ;
	virtual void __fastcall SchedulerRemoved(void) = 0 ;
};

class PASCALIMPLEMENTATION TcxSchedulerCustomDateNavigator : public TcxSchedulerSubControl
{
	typedef TcxSchedulerSubControl inherited;
	
private:
	int FLockCount;
	int FPrevColCount;
	int FPrevRowCount;
	System::TDateTime FSaveRealFirstDate;
	System::TDateTime FSaveRealLastDate;
	Cxschedulerutils::TcxSchedulerDateList* FSaveSelectionList;
	Cxschedulerutils::TcxSchedulerDateList* __fastcall GetEventDays(void);
	TcxSchedulerHintController* __fastcall GetHintController(void);
	Cxschedulerutils::TcxSchedulerDateList* __fastcall GetHolidayDays(void);
	
protected:
	System::Types::TSize FSavedSize;
	virtual void __fastcall BoundsChanging(void);
	virtual void __fastcall BoundsChanged(void);
	virtual bool __fastcall CanMultiSelect(void);
	virtual void __fastcall CheckSizes(void) = 0 ;
	virtual void __fastcall CheckChanges(void);
	virtual void __fastcall CheckCurrentDate(void);
	virtual void __fastcall ClearDragging(void) = 0 ;
	virtual void __fastcall DoPeriodChangedEvent(void) = 0 ;
	virtual void __fastcall DoSelectionChangedEvent(void) = 0 ;
	virtual void __fastcall DoScrollSelection(bool AForward, System::TDateTime ANeedDate, bool AIsByPage) = 0 /* overload */;
	virtual void __fastcall DoScrollSelection(int AScrollDelta) = 0 /* overload */;
	virtual void __fastcall GetCalendarDimension(/* out */ int &AColCount, /* out */ int &ARowCount) = 0 ;
	virtual System::Types::TSize __fastcall GetMonthSize(void);
	virtual Cxschedulerutils::TcxSchedulerDateList* __fastcall GetSelection(void);
	virtual bool __fastcall GetShowDatesContainingEventsInBold(void) = 0 ;
	virtual bool __fastcall GetShowDatesContainingHolidaysInColor(void) = 0 ;
	virtual System::TDateTime __fastcall GetRealFirstDate(void) = 0 ;
	virtual System::TDateTime __fastcall GetRealLastDate(void) = 0 ;
	bool __fastcall IsSchedulerLocked(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall MakeSelectionVisible(void) = 0 ;
	virtual void __fastcall PeriodChanged(void);
	virtual void __fastcall RefreshDays(void) = 0 ;
	void __fastcall SaveSize(void);
	virtual void __fastcall SaveState(void);
	void __fastcall ScrollSelection(bool AForward, System::TDateTime ANeedDate, bool AIsByPage)/* overload */;
	void __fastcall ScrollSelection(int AScrollDelta)/* overload */;
	virtual void __fastcall SetIntegralSizes(void) = 0 ;
	virtual void __fastcall UpdateDragging(void) = 0 ;
	virtual void __fastcall UpdateSelection(void) = 0 ;
	__property Cxschedulerutils::TcxSchedulerDateList* EventDays = {read=GetEventDays};
	__property TcxSchedulerHintController* HintController = {read=GetHintController};
	__property Cxschedulerutils::TcxSchedulerDateList* HolidayDays = {read=GetHolidayDays};
	
public:
	__fastcall virtual TcxSchedulerCustomDateNavigator(TcxCustomScheduler* AOwner);
	__fastcall virtual ~TcxSchedulerCustomDateNavigator(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdates(void);
	void __fastcall EndUpdate(void);
};


class DELPHICLASS TcxSchedulerClipboardController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerClipboardController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCustomScheduler* FScheduler;
	System::Classes::TMemoryStream* FStream;
	Cxvariants::TcxReader* FStreamReader;
	Cxvariants::TcxWriter* FStreamWriter;
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall GetStorage(void);
	void __fastcall RegisterClipboardFormat(void);
	
protected:
	void __fastcall CalculateAnchorForResource(Cxschedulerstorage::TcxSchedulerFilteredEventList* AEvents, const System::Variant &AResourceID, System::TDateTime &Anchor);
	virtual void __fastcall DeleteSelectedEvents(void);
	virtual Vcl::Clipbrd::TClipboard* __fastcall GetClipboard(void);
	bool __fastcall GetClipboardToStream(void);
	bool __fastcall GetSelectionAsStream(void);
	bool __fastcall GetStreamAsEvents(Cxschedulerstorage::TcxSchedulerFilteredEventList* AEvents, System::TDateTime &Anchor);
	bool __fastcall IsClipboardBusy(void);
	void __fastcall InsertEvents(Cxschedulerstorage::TcxSchedulerFilteredEventList* AEvents, System::TDateTime Anchor);
	bool __fastcall KeyDown(System::Word &AKey, System::Classes::TShiftState AShift);
	bool __fastcall KeyPress(System::WideChar &AKey);
	void __fastcall RestoreEvent(Cxschedulerstorage::TcxSchedulerControlEvent* &AEvent);
	void __fastcall SaveEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall SetStreamToClipboard(void);
	bool __fastcall ValidateStream(void);
	__property System::Classes::TMemoryStream* Stream = {read=FStream};
	__property Cxvariants::TcxReader* StreamReader = {read=FStreamReader};
	__property Cxvariants::TcxWriter* StreamWriter = {read=FStreamWriter};
	
public:
	__fastcall virtual TcxSchedulerClipboardController(TcxCustomScheduler* AScheduler);
	__fastcall virtual ~TcxSchedulerClipboardController(void);
	virtual bool __fastcall CanCopy(void);
	virtual bool __fastcall CanPaste(void);
	void __fastcall Copy(void);
	void __fastcall Cut(void);
	void __fastcall Paste(void);
	__property Vcl::Clipbrd::TClipboard* Clipboard = {read=GetClipboard};
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=GetStorage};
};

#pragma pack(pop)

__interface IcxSchedulerStylesAdapter;
typedef System::DelphiInterface<IcxSchedulerStylesAdapter> _di_IcxSchedulerStylesAdapter;
__interface  INTERFACE_UUID("{0BFEA90D-0CE8-4ED1-88E8-71A3396186F3}") IcxSchedulerStylesAdapter  : public System::IInterface 
{
	
public:
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ADateTime, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource) = 0 /* overload */;
	virtual Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ADateTime, bool ALightColor, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource) = 0 /* overload */;
	virtual Cxgraphics::TcxViewParams __fastcall GetDayHeaderParams(const System::TDateTime ADateTime) = 0 ;
	virtual Cxgraphics::TcxViewParams __fastcall GetEventParams(Cxschedulerstorage::TcxSchedulerEvent* AEvent) = 0 ;
	virtual Cxgraphics::TcxViewParams __fastcall GetResourceHeaderParams(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource) = 0 ;
	virtual Cxstyles::TcxStyle* __fastcall GetDayHeaderStyle(void) = 0 ;
	virtual Cxstyles::TcxStyle* __fastcall GetResourceHeaderStyle(void) = 0 ;
};

typedef void __fastcall (__closure *TcxSchedulerOnGetDayHeaderStyleEvent)(System::TObject* Sender, const System::TDateTime ADate, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxSchedulerOnGetResourceHeaderStyleEvent)(System::TObject* Sender, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxSchedulerOnGetContentStyleEvent)(System::TObject* Sender, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, const System::TDateTime ADateTime, Cxstyles::TcxStyle* &AStyle);

typedef void __fastcall (__closure *TcxSchedulerOnGetEventStyleEvent)(System::TObject* Sender, Cxschedulerstorage::TcxSchedulerEvent* AEvent, Cxstyles::TcxStyle* &AStyle);

class PASCALIMPLEMENTATION TcxSchedulerStyles : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
private:
	TcxCustomScheduler* FScheduler;
	TcxSchedulerOnGetContentStyleEvent FOnGetContentStyle;
	TcxSchedulerOnGetDayHeaderStyleEvent FOnGetDayHeaderStyle;
	TcxSchedulerOnGetEventStyleEvent FOnGetEventStyle;
	TcxSchedulerOnGetResourceHeaderStyleEvent FOnGetResourceHeaderStyle;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	Cxschedulerutils::TcxSchedulerPainterHelperClass __fastcall GetPainterHelperClass(void);
	Cxschedulerstorage::TcxSchedulerStorageResourceItems* __fastcall GetResources(void);
	
protected:
	virtual void __fastcall Changed(int AIndex);
	bool __fastcall EventContentSelected(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	System::Uitypes::TColor __fastcall GetDefaultContentColor(int AResourceIndex);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	Cxstyles::TcxStyle* __fastcall GetDayHeaderStyle(void);
	Cxgraphics::TcxViewParams __fastcall GetEventParams(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	Cxstyles::TcxStyle* __fastcall GetResourceHeaderStyle(void);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property Cxschedulerutils::TcxSchedulerPainterHelperClass PainterHelper = {read=GetPainterHelperClass};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItems* Resources = {read=GetResources};
	
public:
	__fastcall virtual TcxSchedulerStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Cxgraphics::TcxViewParams __fastcall GetBackgroundParams(void);
	Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ADateTime, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource = (Cxschedulerstorage::TcxSchedulerStorageResourceItem*)(0x0))/* overload */;
	Cxgraphics::TcxViewParams __fastcall GetContentParams(const System::TDateTime ADateTime, bool ALightColor, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource = (Cxschedulerstorage::TcxSchedulerStorageResourceItem*)(0x0))/* overload */;
	Cxgraphics::TcxViewParams __fastcall GetDayHeaderParams(const System::TDateTime ADate);
	Cxgraphics::TcxViewParams __fastcall GetGroupSeparatorParams(void);
	Cxgraphics::TcxViewParams __fastcall GetResourceHeaderParams(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	Cxgraphics::TcxViewParams __fastcall GetSelectionParams(void);
	Cxgraphics::TcxViewParams __fastcall GetSplitterParams(TcxSchedulerSplitterKind AKind);
	Cxgraphics::TcxViewParams __fastcall GetEventContentParams(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	bool __fastcall IsEventStyleAssigned(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
	
__published:
	__property Cxstyles::TcxStyle* Background = {read=GetValue, write=SetValue, index=0};
	__property Cxstyles::TcxStyle* Content = {read=GetValue, write=SetValue, index=1};
	__property Cxstyles::TcxStyle* Event = {read=GetValue, write=SetValue, index=2};
	__property Cxstyles::TcxStyle* GroupSeparator = {read=GetValue, write=SetValue, index=3};
	__property Cxstyles::TcxStyle* DayHeader = {read=GetValue, write=SetValue, index=4};
	__property Cxstyles::TcxStyle* HorzSplitter = {read=GetValue, write=SetValue, index=6};
	__property Cxstyles::TcxStyle* ResourceHeader = {read=GetValue, write=SetValue, index=8};
	__property Cxstyles::TcxStyle* Selection = {read=GetValue, write=SetValue, index=5};
	__property Cxstyles::TcxStyle* VertSplitter = {read=GetValue, write=SetValue, index=7};
	__property TcxSchedulerOnGetContentStyleEvent OnGetContentStyle = {read=FOnGetContentStyle, write=FOnGetContentStyle};
	__property TcxSchedulerOnGetDayHeaderStyleEvent OnGetDayHeaderStyle = {read=FOnGetDayHeaderStyle, write=FOnGetDayHeaderStyle};
	__property TcxSchedulerOnGetEventStyleEvent OnGetEventStyle = {read=FOnGetEventStyle, write=FOnGetEventStyle};
	__property TcxSchedulerOnGetResourceHeaderStyleEvent OnGetResourceHeaderStyle = {read=FOnGetResourceHeaderStyle, write=FOnGetResourceHeaderStyle};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxSchedulerStyles(void) { }
	
private:
	void *__IcxSchedulerStylesAdapter;	/* IcxSchedulerStylesAdapter */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0BFEA90D-0CE8-4ED1-88E8-71A3396186F3}
	operator _di_IcxSchedulerStylesAdapter()
	{
		_di_IcxSchedulerStylesAdapter intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxSchedulerStylesAdapter*(void) { return (IcxSchedulerStylesAdapter*)&__IcxSchedulerStylesAdapter; }
	#endif
	
};


class DELPHICLASS TcxSchedulerOptionsBehavior;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerOptionsBehavior : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FHotTrack;
	TcxCustomScheduler* FOwner;
	bool FSelectOnRightClick;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall TcxSchedulerOptionsBehavior(TcxCustomScheduler* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool SelectOnRightClick = {read=FSelectOnRightClick, write=FSelectOnRightClick, default=0};
	__property bool HotTrack = {read=FHotTrack, write=FHotTrack, default=1};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxSchedulerOptionsBehavior(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxSchedulerCanShowViewEvent)(System::TObject* Sender, TcxSchedulerCustomView* AView, bool &Allow);

typedef void __fastcall (__closure *TcxSchedulerGetEventEditPropertiesEvent)(System::TObject* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxedit::TcxCustomEditProperties* &AProperties);

typedef void __fastcall (__closure *TcxSchedulerGetEventText)(System::TObject* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, System::UnicodeString &AText);

typedef void __fastcall (__closure *TcxSchedulerInitEditEvent)(System::TObject* Sender, Cxedit::TcxCustomEdit* AEdit);

typedef void __fastcall (__closure *TcxSchedulerViewTypeChangedEvent)(System::TObject* Sender, TcxSchedulerCustomView* APrevView, TcxSchedulerCustomView* ANewView);

typedef void __fastcall (__closure *TcxSchedulerIsWorkTimeEvent)(System::TObject* Sender, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, const System::TDateTime ATime, bool &AIsWork);

typedef void __fastcall (__closure *TcxSchedulerBeforeDeleting)(TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool &Allow);

typedef void __fastcall (__closure *TcxSchedulerBeforeDragEvent)(TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int X, int Y, bool &Allow);

typedef void __fastcall (__closure *TcxSchedulerBeforeEditing)(TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool AInplace, bool &Allow);

typedef void __fastcall (__closure *TcxSchedulerAfterDragEvent)(TcxCustomScheduler* Sender, System::TObject* Target, int X, int Y, bool &Accept);

typedef void __fastcall (__closure *TcxSchedulerBeforeSizingEvent)(TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int X, int Y, bool &Allow);

typedef void __fastcall (__closure *TcxSchedulerAfterSizingEvent)(TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int X, int Y, bool &Accept);

typedef void __fastcall (__closure *TcxSchedulerAfterEditing)(TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);

typedef void __fastcall (__closure *TcxSchedulerMoreEventsButtonClickEvent)(TcxCustomScheduler* Sender, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerNavigationButtonClickEvent)(TcxCustomScheduler* Sender, System::TDateTime AnInterval, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerScaleScrollEvent)(TcxCustomScheduler* Sender, System::TDateTime AStartDateTime, System::TDateTime AFinishDateTime);

typedef void __fastcall (__closure *TcxSchedulerEventSelectionChangedEvent)(TcxCustomScheduler* Sender, Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);

typedef void __fastcall (__closure *TcxSchedulerShowDateHintEvent)(System::TObject* Sender, const System::TDateTime ADate, System::UnicodeString &AHintText, bool &AAllow);

class DELPHICLASS TcxSchedulerContentPopupMenu;
class DELPHICLASS TcxSchedulerEventPopupMenu;
class PASCALIMPLEMENTATION TcxCustomScheduler : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TcxSchedulerSubControl* FActiveControl;
	bool FAligningSubControls;
	TcxSchedulerSubControl* FBackground;
	bool FBoundsChanging;
	bool FCanModified;
	TcxSchedulerSubControl* FCaptureControl;
	TcxSchedulerClipboardController* FClipboardController;
	TcxSchedulerContentPopupMenu* FContentPopupMenu;
	System::Classes::TNotifyEvent FContentPopupMenuEvents;
	TcxSchedulerControlBox* FControlBox;
	TcxControlFlags FControlFlags;
	TcxSchedulerCustomView* FCurrentView;
	TcxSchedulerCustomDateNavigator* FDateNavigator;
	Cxedit::TcxCustomEditProperties* FDefaultProperties;
	Cxlookandfeels::TcxLookAndFeel* FDialogsLookAndFeel;
	TcxSchedulerEditController* FEditController;
	Cxedit::TcxCustomEditStyle* FEditStyle;
	Cxschedulerutils::TcxSchedulerDateList* FEventDays;
	TcxSchedulerEventEditInfo* FEventEditInfo;
	TcxSchedulerEventHitTestController* FEventHitTestController;
	Vcl::Imglist::TCustomImageList* FEventImages;
	Cxschedulerstorage::TcxSchedulerCachedEventList* FEventList;
	TcxSchedulerEventOperations* FEventOperations;
	TcxSchedulerEventPopupMenu* FEventPopupMenu;
	System::Classes::TNotifyEvent FEventPopupMenuEvents;
	int FFirstVisibleResourceIndex;
	TcxSchedulerHintController* FHintController;
	Cxschedulerutils::TcxSchedulerDateList* FHolidayDays;
	TcxSchedulerSplitter* FHorzSplitter;
	bool FHorzSplitterShowing;
	bool FIsDragCanceled;
	TcxSchedulerSubControl* FKeyboardListener;
	System::Classes::TInterfaceList* FListeners;
	int FLockCount;
	int FLockRefresh;
	TcxSchedulerInitEditEvent FOnInitEdit;
	TcxSchedulerOptionsBehavior* FOptionsBehavior;
	TcxSchedulerOptionsCustomize* FOptionsCustomize;
	TcxSchedulerOptionsView* FOptionsView;
	System::Types::TRect FPrevBounds;
	bool FPrevCopyDragDrop;
	System::Types::TPoint FPrevMousePos;
	TcxSchedulerResourceNavigator* FResourceNavigator;
	System::Classes::TNotifyEvent FResourceNavigatorEvents;
	Cxschedulerutils::TcxSchedulerDateList* FSelectedDays;
	System::TDateTime FSelFinish;
	Cxschedulerstorage::TcxSchedulerStorageResourceItem* FSelResource;
	System::TDateTime FSelStart;
	Cxschedulerstorage::TcxCustomSchedulerStorage* FStorage;
	System::UnicodeString FStoringName;
	TcxSchedulerStyles* FStyles;
	System::Classes::TNotifyEvent FStylesEvents;
	System::Classes::TList* FSubControls;
	bool FSubControlsCreated;
	Cxschedulerstorage::TcxSchedulerEventList* FTabOrdersList;
	Cxtextedit::TcxTextEditProperties* FTextEditProperties;
	TcxSchedulerSplitter* FVertSplitter;
	bool FVertSplitterShowing;
	int FVisibleChangedCount;
	Vcl::Extctrls::TTimer* FUpdateTimeTimer;
	TcxSchedulerAfterDragEvent FOnAfterDragEvent;
	TcxSchedulerAfterEditing FOnAfterEditing;
	TcxSchedulerAfterSizingEvent FOnAfterSizingEvent;
	TcxSchedulerBeforeDeleting FOnBeforeDeleting;
	TcxSchedulerBeforeDragEvent FOnBeforeDragEvent;
	TcxSchedulerBeforeEditing FOnBeforeEditing;
	TcxSchedulerBeforeSizingEvent FOnBeforeSizingEvent;
	TcxSchedulerCanShowViewEvent FOnCanShowView;
	TcxSchedulerEventSelectionChangedEvent FOnEventSelectionChanged;
	System::Classes::TNotifyEvent FOnFirstVisibleResourceChanged;
	TcxSchedulerGetEventText FOnGetEventDisplayText;
	TcxSchedulerGetEventEditPropertiesEvent FOnGetEventEditProperties;
	TcxSchedulerGetEventText FOnGetEventHintText;
	TcxSchedulerIsWorkTimeEvent FOnIsWorkTime;
	System::Classes::TNotifyEvent FOnLayoutChanged;
	TcxSchedulerMoreEventsButtonClickEvent FOnMoreEventsButtonClick;
	TcxSchedulerNavigationButtonClickEvent FOnNavigationButtonClick;
	System::Classes::TNotifyEvent FOnSelectionChanged;
	TcxSchedulerScaleScrollEvent FOnScaleScroll;
	TcxSchedulerShowDateHintEvent FOnShowDateHint;
	TcxSchedulerViewTypeChangedEvent FOnViewTypeChanged;
	void __fastcall CreateUpdateTimeTimer(void);
	TcxSchedulerSubControlHitTest* __fastcall GetActiveHitTest(void);
	TcxSchedulerSubControl* __fastcall GetCaptureControl(void);
	TcxSchedulerSubControlController* __fastcall GetCaptureController(void);
	int __fastcall GetSelectedEventCount(void);
	Cxschedulerstorage::TcxSchedulerControlEvent* __fastcall GetSelectedEvent(int AIndex);
	System::TDateTime __fastcall GetSelFinish(void);
	System::TDateTime __fastcall GetSelStart(void);
	bool __fastcall GetIsDynamicUpdate(void);
	Cxdateutils::TDay __fastcall GetStartOfWeek(void);
	bool __fastcall GetStorageActive(void);
	bool __fastcall GetStorageValid(void);
	TcxSchedulerSubControl* __fastcall GetSubControl(int AIndex);
	int __fastcall GetSubControlCount(void);
	int __fastcall GetVisibleEventCount(void);
	Cxschedulerstorage::TcxSchedulerControlEvent* __fastcall GetVisibleEvent(int AIndex);
	void __fastcall InitEventBySelection(Cxschedulerstorage::TcxSchedulerEvent* AEvent, bool AllDay, bool ARecurrence, bool AInplaceEditing);
	void __fastcall SetCaptureControl(TcxSchedulerSubControl* AValue);
	void __fastcall SetContentPopupMenu(TcxSchedulerContentPopupMenu* AValue);
	void __fastcall SetControlBox(TcxSchedulerControlBox* AValue);
	void __fastcall SetDialogsLookAndFeel(Cxlookandfeels::TcxLookAndFeel* AValue);
	void __fastcall SetEventImages(Vcl::Imglist::TCustomImageList* AValue);
	void __fastcall SetEventOperations(TcxSchedulerEventOperations* AValue);
	void __fastcall SetEventPopupMenu(TcxSchedulerEventPopupMenu* AValue);
	void __fastcall SetFirstVisibleResourceIndex(int AValue);
	void __fastcall SetOptionsBehavior(TcxSchedulerOptionsBehavior* AValue);
	void __fastcall SetOptionsCustomize(TcxSchedulerOptionsCustomize* AValue);
	void __fastcall SetOptionsView(TcxSchedulerOptionsView* AValue);
	void __fastcall SetResourceNavigator(TcxSchedulerResourceNavigator* AValue);
	void __fastcall SetStyles(TcxSchedulerStyles* AValue);
	void __fastcall SetStorage(Cxschedulerstorage::TcxCustomSchedulerStorage* AValue);
	void __fastcall UpdateTimeHandler(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMTimeChange(Winapi::Messages::TWMNoParams &Message);
	void __fastcall ReadSelectionData(System::Classes::TReader* AReader);
	void __fastcall WriteSelectionData(System::Classes::TWriter* AWriter);
	
protected:
	System::Types::TRect FStoredClientBounds;
	void __fastcall StorageChanged(System::TObject* Sender);
	void __fastcall StorageRemoved(System::TObject* Sender);
	virtual void __fastcall DoStartOfWeekChanged(Cxdateutils::TDay AOldStartOfWeek, Cxdateutils::TDay ANewStartOfWeek);
	virtual void __fastcall FormatChanged(void);
	void __fastcall TimeChanged(void);
	virtual System::UnicodeString __fastcall GetObjectName(void);
	virtual bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall AddListener(_di_IcxExternalDateNavigatorListener AListener);
	void __fastcall NotififySchedulerChanged(void);
	void __fastcall NotififySchedulerRemoved(void);
	void __fastcall NotififyStorageChanged(void);
	void __fastcall RemoveListener(_di_IcxExternalDateNavigatorListener AListener);
	virtual bool __fastcall AllowCompositionPainting(void);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	virtual void __fastcall AlignSubControls(TcxSchedulerSubControl* Sender = (TcxSchedulerSubControl*)(0x0));
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall CalcHorizontalSplitterBounds(void);
	virtual void __fastcall CalcVerticalSplitterBounds(void);
	virtual void __fastcall CalcLayout(void);
	virtual void __fastcall CalcLayoutViewRight(void);
	virtual void __fastcall CalcLayoutViewLeft(void);
	virtual void __fastcall CalcLayoutViewTop(void);
	virtual void __fastcall CalcLayoutViewBottom(void);
	void __fastcall CalcSplittersBounds(void);
	void __fastcall CheckHorzSplitterBounds(void);
	virtual void __fastcall CheckSplittersVisibilityChanging(void);
	virtual void __fastcall ClearAllCachedData(void);
	virtual bool __fastcall IsHorzSplitterVisible(void);
	virtual bool __fastcall IsVertSplitterVisible(void);
	void __fastcall UpdateControlsBoundsOnHorzSplitterShowing(void);
	void __fastcall UpdateControlsBoundsOnVertSplitterShowing(void);
	virtual bool __fastcall CanDeactivateOnSelectionChanged(TcxSchedulerCustomView* AView);
	virtual bool __fastcall CanIntersect(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall CanModified(void);
	virtual bool __fastcall CanSelectPeriod(void);
	bool __fastcall CanShowEventDialog(void);
	virtual TcxSchedulerSubControl* __fastcall CreateBackground(void);
	virtual TcxSchedulerClipboardController* __fastcall CreateClipboardController(void);
	virtual TcxSchedulerContentPopupMenu* __fastcall CreateContentPopupMenu(void);
	virtual TcxSchedulerControlBox* __fastcall CreateControlBox(void);
	virtual TcxSchedulerCustomDateNavigator* __fastcall CreateDateNavigator(void);
	virtual TcxSchedulerCustomView* __fastcall CreateDefaultView(void);
	virtual Cxedit::TcxCustomEditProperties* __fastcall CreateDefaultEditProperties(void);
	virtual TcxSchedulerEditController* __fastcall CreateEditController(void);
	virtual TcxSchedulerEventHitTestController* __fastcall CreateEventHitTestController(void);
	virtual Cxschedulerstorage::TcxSchedulerCachedEventList* __fastcall CreateEventList(void);
	virtual TcxSchedulerEventOperations* __fastcall CreateEventOperations(void);
	virtual TcxSchedulerEventPopupMenu* __fastcall CreateEventPopupMenu(void);
	virtual TcxSchedulerHintController* __fastcall CreateHintController(void);
	virtual TcxSchedulerOptionsCustomize* __fastcall CreateOptionsCustomize(void);
	virtual TcxSchedulerOptionsView* __fastcall CreateOptionsView(void);
	virtual TcxSchedulerResourceNavigator* __fastcall CreateResourceNavigator(void);
	virtual TcxSchedulerSplitter* __fastcall CreateSplitter(TcxSchedulerSplitterKind AKind);
	virtual TcxSchedulerStyles* __fastcall CreateStyles(void);
	virtual void __fastcall CreateSubClasses(void);
	virtual void __fastcall DateNavigatorSelectionChanged(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DestroySubClasses(void);
	virtual void __fastcall DoAfterDragEvent(System::TObject* Target, int X, int Y, bool &Accept);
	virtual void __fastcall DoAfterEditing(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall DoAfterSizingEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int X, int Y, bool &Accept);
	virtual bool __fastcall DoBeforeDeleting(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall DoBeforeDragEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int X, int Y);
	virtual bool __fastcall DoBeforeEditing(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool AInplace);
	virtual bool __fastcall DoBeforeSizingEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, int X, int Y);
	virtual void __fastcall DoCalculateLayout(TcxSchedulerSubControl* AControl);
	DYNAMIC void __fastcall DoCancelMode(void);
	virtual void __fastcall DoControllerReset(TcxSchedulerSubControl* AControl);
	virtual void __fastcall DoCreateEventUsingInplaceEdit(System::WideChar AKey = (System::WideChar)(0x0));
	void __fastcall DoEventSelectionChanged(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual void __fastcall DoFirstVisibleResourceChanged(void);
	virtual void __fastcall DoGestureScroll(Vcl::Forms::TScrollBarKind AScrollKind, int ANewScrollPos);
	virtual void __fastcall DoGetEventDisplayText(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, System::UnicodeString &AText);
	virtual void __fastcall DoGetEventEditProperties(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, Cxedit::TcxCustomEditProperties* &AProperties);
	virtual void __fastcall DoHitTestRecalculate(TcxSchedulerSubControl* AControl);
	virtual void __fastcall DoInitEdit(Cxedit::TcxCustomEdit* AEdit);
	bool __fastcall DoIsWorkTime(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResourceItem, const System::TDateTime ADateTime);
	virtual void __fastcall DoCanShowView(TcxSchedulerCustomView* AView, bool &Allow);
	virtual void __fastcall DoLayoutChanged(void);
	virtual void __fastcall DoLayoutChangedEvent(void);
	virtual bool __fastcall DoMoreEventsButtonClick(void);
	virtual bool __fastcall DoNavigationButtonClick(System::TDateTime AnInterval, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual void __fastcall DoSelectionChanged(void);
	virtual void __fastcall DoScaleScroll(void);
	virtual bool __fastcall DoShowDateHint(const System::TDateTime ADate, System::UnicodeString &AHintText);
	virtual bool __fastcall DoShowPopupMenu(System::Classes::TComponent* AMenu, int X, int Y);
	virtual void __fastcall DoViewTypeChanged(TcxSchedulerCustomView* ANewView);
	virtual void __fastcall DoUpdateTime(void);
	DYNAMIC void __fastcall DragCanceled(void);
	virtual void __fastcall DrawSplitters(void);
	virtual void __fastcall FirstVisibleResourceChanged(void);
	DYNAMIC void __fastcall FontChanged(void);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual TcxSchedulerSubControl* __fastcall GetControlFromPoint(const System::Types::TPoint &APoint);
	virtual System::Uitypes::TCursor __fastcall GetCurrentCursor(int X, int Y);
	virtual Cxschedulerutils::TcxSchedulerDateTimeHelperClass __fastcall GetDateTimeHelper(void);
	System::Types::TSize __fastcall GetDateNavigatorLoadedSize(void);
	DYNAMIC bool __fastcall GetDesignHitTest(int X, int Y, System::Classes::TShiftState Shift);
	TcxSchedulerEventEditInfo* __fastcall GetEventEditInfo(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool ARecurrence = false, bool AReadOnly = false);
	virtual System::UnicodeString __fastcall GetEventHintText(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	virtual bool __fastcall GetEventUserHintText(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, System::UnicodeString &AText);
	virtual System::Types::TRect __fastcall GetHScrollBarBounds(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetInternalCanvas(void);
	virtual bool __fastcall GetIsLocked(void);
	virtual Cxcontrols::TcxControlCustomScrollBarsClass __fastcall GetMainScrollBarsClass(void);
	virtual TcxSchedulerCustomView* __fastcall GetNextView(TcxSchedulerCustomView* AView);
	virtual TcxSchedulerShowDateHintEvent __fastcall GetOnShowDateHint(void);
	virtual Cxschedulerutils::TcxSchedulerPainterHelperClass __fastcall GetPainterHelper(void);
	virtual System::Types::TRect __fastcall GetSizeGripBounds(void);
	virtual double __fastcall GetTimeBias(System::TDateTime AStart);
	virtual System::Types::TRect __fastcall GetVScrollBarBounds(void);
	bool __fastcall HasConflict(bool AStartDrag);
	bool __fastcall HasResources(void);
	virtual void __fastcall InitControl(void);
	virtual void __fastcall InitScrollBarsParameters(void);
	void __fastcall InternalDeleteEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool AIgnoreRecurring);
	void __fastcall InternalDeleteSelectedEvents(bool AForceDelete, bool ACheckReadOnly);
	bool __fastcall IsDaysIntervalChanged(System::TDateTime &AStart, System::TDateTime &AFinish);
	bool __fastcall IsViewAtLeft(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall LockUpdateChanged(bool ALocking);
	virtual void __fastcall Modified(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual bool __fastcall NeedShowHint(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, System::UnicodeString &AHintText, bool AllowShow);
	virtual void __fastcall DoPaint(void);
	virtual void __fastcall PaintControl(TcxSchedulerSubControl* AControl, bool ASpecialPaint = false);
	virtual void __fastcall PeriodChanged(void);
	void __fastcall RemoveSubControl(TcxSchedulerSubControl* AControl);
	virtual void __fastcall ReplaceSelParams(System::TDateTime ASelStart, System::TDateTime ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	void __fastcall SelectedDaysChanged(TcxSchedulerCustomView* AView);
	virtual void __fastcall SetCurrentView(TcxSchedulerCustomView* AView);
	void __fastcall SubControlAdd(TcxSchedulerSubControl* AControl);
	void __fastcall SubControlRemove(TcxSchedulerSubControl* AControl);
	virtual void __fastcall SynchronizeVisibleDays(void);
	void __fastcall UpdateDateNavigatorDragging(bool Accept);
	void __fastcall UpdateHolidayDays(System::TDate ABegin, System::TDate AEnd);
	virtual void __fastcall UpdateEventsCache(bool ACheckDaysInterval);
	virtual void __fastcall ValidateSelection(Cxschedulerutils::TcxSchedulerDateList* ASelection);
	void __fastcall ValidateState(void);
	virtual void __fastcall ViewVisibleChanged(TcxSchedulerCustomView* AView);
	TcxSchedulerGroupingKind __fastcall VisibleGroupingKind(void);
	DYNAMIC bool __fastcall CanDrag(int X, int Y);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DragAndDrop(const System::Types::TPoint &P, bool &Accepted);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	DYNAMIC void __fastcall EndDragAndDrop(bool Accepted);
	virtual Cxcontrols::TcxDragAndDropObjectClass __fastcall GetDragAndDropObjectClass(void);
	DYNAMIC Cxcontrols::TDragControlObjectClass __fastcall GetDragObjectClass(void);
	DYNAMIC bool __fastcall StartDragAndDrop(const System::Types::TPoint &P);
	virtual Dxtouch::_di_IdxGestureClient __fastcall GetGestureClient(const System::Types::TPoint &APoint);
	__property TcxSchedulerSubControl* Background = {read=FBackground};
	__property bool AligningSubControls = {read=FAligningSubControls, nodefault};
	__property bool BoundsChanging = {read=FBoundsChanging, nodefault};
	__property TcxSchedulerSubControl* Capture = {read=GetCaptureControl, write=SetCaptureControl};
	__property TcxSchedulerSubControlController* CaptureController = {read=GetCaptureController};
	__property TcxSchedulerClipboardController* ClipboardController = {read=FClipboardController};
	__property TcxControlFlags ControlFlags = {read=FControlFlags, write=FControlFlags, nodefault};
	__property Cxedit::TcxCustomEditProperties* DefaultProperties = {read=FDefaultProperties};
	__property TcxSchedulerEditController* EditController = {read=FEditController};
	__property Cxedit::TcxCustomEditStyle* EditStyle = {read=FEditStyle};
	__property TcxSchedulerEventHitTestController* EventHitTestController = {read=FEventHitTestController, write=FEventHitTestController};
	__property Cxschedulerstorage::TcxSchedulerCachedEventList* EventList = {read=FEventList};
	__property TcxSchedulerHintController* HintController = {read=FHintController};
	__property TcxSchedulerSplitter* HorzSplitter = {read=FHorzSplitter};
	__property bool IsDragCanceled = {read=FIsDragCanceled, nodefault};
	__property bool IsDynamicUpdate = {read=GetIsDynamicUpdate, nodefault};
	__property bool IsLocked = {read=GetIsLocked, nodefault};
	__property TcxSchedulerSubControl* KeyboardListener = {read=FKeyboardListener, write=FKeyboardListener};
	__property int LockCount = {read=FLockCount, nodefault};
	__property Cxschedulerutils::TcxSchedulerPainterHelperClass PainterHelper = {read=GetPainterHelper};
	__property ParentFont = {default=0};
	__property Cxdateutils::TDay StartOfWeek = {read=GetStartOfWeek, nodefault};
	__property bool StorageActive = {read=GetStorageActive, nodefault};
	__property bool StorageValid = {read=GetStorageValid, nodefault};
	__property int SubControlCount = {read=GetSubControlCount, nodefault};
	__property bool SubControlsCreated = {read=FSubControlsCreated, nodefault};
	__property TcxSchedulerSubControl* SubControls[int Index] = {read=GetSubControl};
	__property Cxschedulerstorage::TcxSchedulerEventList* TabOrdersList = {read=FTabOrdersList};
	__property TcxSchedulerSplitter* VertSplitter = {read=FVertSplitter};
	__property DragMode = {default=1};
	__property BorderStyle = {default=1};
	__property TcxSchedulerAfterDragEvent OnAfterDragEvent = {read=FOnAfterDragEvent, write=FOnAfterDragEvent};
	__property TcxSchedulerAfterEditing OnAfterEditing = {read=FOnAfterEditing, write=FOnAfterEditing};
	__property TcxSchedulerAfterSizingEvent OnAfterSizingEvent = {read=FOnAfterSizingEvent, write=FOnAfterSizingEvent};
	__property TcxSchedulerBeforeDeleting OnBeforeDeleting = {read=FOnBeforeDeleting, write=FOnBeforeDeleting};
	__property TcxSchedulerBeforeDragEvent OnBeforeDragEvent = {read=FOnBeforeDragEvent, write=FOnBeforeDragEvent};
	__property TcxSchedulerBeforeEditing OnBeforeEditing = {read=FOnBeforeEditing, write=FOnBeforeEditing};
	__property TcxSchedulerBeforeSizingEvent OnBeforeSizingEvent = {read=FOnBeforeSizingEvent, write=FOnBeforeSizingEvent};
	__property TcxSchedulerCanShowViewEvent OnCanShowView = {read=FOnCanShowView, write=FOnCanShowView};
	__property TcxSchedulerEventSelectionChangedEvent OnEventSelectionChanged = {read=FOnEventSelectionChanged, write=FOnEventSelectionChanged};
	__property System::Classes::TNotifyEvent OnFirstVisibleResourceChanged = {read=FOnFirstVisibleResourceChanged, write=FOnFirstVisibleResourceChanged};
	__property TcxSchedulerGetEventText OnGetEventDisplayText = {read=FOnGetEventDisplayText, write=FOnGetEventDisplayText};
	__property TcxSchedulerGetEventText OnGetEventHintText = {read=FOnGetEventHintText, write=FOnGetEventHintText};
	__property TcxSchedulerGetEventEditPropertiesEvent OnGetEventEditProperties = {read=FOnGetEventEditProperties, write=FOnGetEventEditProperties};
	__property TcxSchedulerInitEditEvent OnInitEdit = {read=FOnInitEdit, write=FOnInitEdit};
	__property TcxSchedulerIsWorkTimeEvent OnIsWorkTime = {read=FOnIsWorkTime, write=FOnIsWorkTime};
	__property System::Classes::TNotifyEvent OnLayoutChanged = {read=FOnLayoutChanged, write=FOnLayoutChanged};
	__property TcxSchedulerMoreEventsButtonClickEvent OnMoreEventsButtonClick = {read=FOnMoreEventsButtonClick, write=FOnMoreEventsButtonClick};
	__property TcxSchedulerNavigationButtonClickEvent OnNavigationButtonClick = {read=FOnNavigationButtonClick, write=FOnNavigationButtonClick};
	__property TcxSchedulerScaleScrollEvent OnScaleScroll = {read=FOnScaleScroll, write=FOnScaleScroll};
	__property System::Classes::TNotifyEvent OnSelectionChanged = {read=FOnSelectionChanged, write=FOnSelectionChanged};
	__property TcxSchedulerShowDateHintEvent OnShowDateHint = {read=GetOnShowDateHint, write=FOnShowDateHint};
	__property TcxSchedulerViewTypeChangedEvent OnViewTypeChanged = {read=FOnViewTypeChanged, write=FOnViewTypeChanged};
	
public:
	__fastcall virtual TcxCustomScheduler(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomScheduler(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CopyToClipboard(void);
	virtual void __fastcall CreateEventUsingDialog(bool AllDay = false, bool ARecurrence = false);
	void __fastcall CreateEventUsingInplaceEdit(void);
	void __fastcall CutToClipboard(void);
	virtual void __fastcall DeleteEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall DeleteSelectedEvents(bool ACheckReadOnly = true);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	void __fastcall EditEventUsingDialog(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, bool ACheckReadOnly = true, bool AForcePatternEditing = false);
	void __fastcall EditEventUsingInplaceEdit(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent);
	void __fastcall EndUpdate(void);
	virtual void __fastcall FullRefresh(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	virtual bool __fastcall GoToDate(System::TDateTime ADate)/* overload */;
	virtual bool __fastcall GoToDate(System::TDateTime ADate, TcxSchedulerViewMode AViewMode)/* overload */;
	void __fastcall LayoutChanged(void);
	void __fastcall MakeEventVisible(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, const System::TDateTime ADate = -7.000000E+05, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource = (Cxschedulerstorage::TcxSchedulerStorageResourceItem*)(0x0));
	void __fastcall MakeResourceVisible(Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	void __fastcall PasteFromClipboard(void);
	void __fastcall SelectEvent(Cxschedulerstorage::TcxSchedulerControlEvent* AEvent, System::Classes::TShiftState AShift = System::Classes::TShiftState() );
	void __fastcall SelectTime(const System::TDateTime ASelStart, const System::TDateTime ASelFinish, Cxschedulerstorage::TcxSchedulerStorageResourceItem* AResource);
	void __fastcall UnselectEvents(void);
	void __fastcall ValidateFirstVisibleResourceIndex(void);
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName, bool ARestoreResources = true);
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName, bool ARestoreResources = true);
	void __fastcall RestoreFromStream(System::Classes::TStream* AStream, bool ARestoreResources = true);
	void __fastcall StoreToIniFile(const System::UnicodeString AStorageName, bool AReCreate = true, bool AStoreResources = true);
	void __fastcall StoreToRegistry(const System::UnicodeString AStorageName, bool AReCreate = true, bool AStoreResources = true);
	void __fastcall StoreToStream(System::Classes::TStream* AStream, bool AStoreResources = true);
	virtual void __fastcall TranslationChanged(void);
	__property TcxSchedulerSubControlHitTest* ActiveHitTest = {read=GetActiveHitTest};
	__property Color = {default=-16777211};
	__property TcxSchedulerContentPopupMenu* ContentPopupMenu = {read=FContentPopupMenu, write=SetContentPopupMenu};
	__property TcxSchedulerControlBox* ControlBox = {read=FControlBox, write=SetControlBox};
	__property TcxSchedulerCustomView* CurrentView = {read=FCurrentView, write=SetCurrentView};
	__property TcxSchedulerCustomDateNavigator* DateNavigator = {read=FDateNavigator};
	__property Cxschedulerutils::TcxSchedulerDateTimeHelperClass DateTimeHelper = {read=GetDateTimeHelper};
	__property Cxlookandfeels::TcxLookAndFeel* DialogsLookAndFeel = {read=FDialogsLookAndFeel, write=SetDialogsLookAndFeel};
	__property Cxschedulerutils::TcxSchedulerDateList* EventDays = {read=FEventDays};
	__property Vcl::Imglist::TCustomImageList* EventImages = {read=FEventImages, write=SetEventImages};
	__property TcxSchedulerEventOperations* EventOperations = {read=FEventOperations, write=SetEventOperations};
	__property TcxSchedulerEventPopupMenu* EventPopupMenu = {read=FEventPopupMenu, write=SetEventPopupMenu};
	__property int FirstVisibleResourceIndex = {read=FFirstVisibleResourceIndex, write=SetFirstVisibleResourceIndex, default=0};
	__property Cxschedulerutils::TcxSchedulerDateList* HolidayDays = {read=FHolidayDays};
	__property TcxSchedulerOptionsBehavior* OptionsBehavior = {read=FOptionsBehavior, write=SetOptionsBehavior};
	__property TcxSchedulerOptionsCustomize* OptionsCustomize = {read=FOptionsCustomize, write=SetOptionsCustomize};
	__property TcxSchedulerOptionsView* OptionsView = {read=FOptionsView, write=SetOptionsView};
	__property TcxSchedulerResourceNavigator* ResourceNavigator = {read=FResourceNavigator, write=SetResourceNavigator};
	__property Cxschedulerutils::TcxSchedulerDateList* SelectedDays = {read=FSelectedDays};
	__property int SelectedEventCount = {read=GetSelectedEventCount, nodefault};
	__property Cxschedulerstorage::TcxSchedulerControlEvent* SelectedEvents[int Index] = {read=GetSelectedEvent};
	__property System::TDateTime SelFinish = {read=GetSelFinish};
	__property Cxschedulerstorage::TcxSchedulerStorageResourceItem* SelResource = {read=FSelResource};
	__property System::TDateTime SelStart = {read=GetSelStart};
	__property Cxschedulerstorage::TcxCustomSchedulerStorage* Storage = {read=FStorage, write=SetStorage};
	__property System::UnicodeString StoringName = {read=FStoringName, write=FStoringName};
	__property TcxSchedulerStyles* Styles = {read=FStyles, write=SetStyles};
	__property int VisibleEventCount = {read=GetVisibleEventCount, nodefault};
	__property Cxschedulerstorage::TcxSchedulerControlEvent* VisibleEvents[int AIndex] = {read=GetVisibleEvent};
	__property TabStop = {default=1};
	__property Font;
	
__published:
	__property System::Classes::TNotifyEvent StylesEvents = {read=FStylesEvents, write=FStylesEvents};
	__property System::Classes::TNotifyEvent ResourceNavigatorEvents = {read=FResourceNavigatorEvents, write=FResourceNavigatorEvents};
	__property System::Classes::TNotifyEvent ContentPopupMenuEvents = {read=FContentPopupMenuEvents, write=FContentPopupMenuEvents};
	__property System::Classes::TNotifyEvent EventPopupMenuEvents = {read=FEventPopupMenuEvents, write=FEventPopupMenuEvents};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomScheduler(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	void *__IcxFormatControllerListener2;	/* Cxformats::IcxFormatControllerListener2 */
	void *__IcxFormatControllerListener;	/* Cxformats::IcxFormatControllerListener */
	void *__IcxSchedulerStorageListener;	/* Cxschedulerstorage::IcxSchedulerStorageListener */
	
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
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {5E33A2A7-0C77-415F-A359-112103E54937}
	operator Cxformats::_di_IcxFormatControllerListener2()
	{
		Cxformats::_di_IcxFormatControllerListener2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener2*(void) { return (Cxformats::IcxFormatControllerListener2*)&__IcxFormatControllerListener2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {A7F2F6D3-1A7D-4295-A6E6-9297BD83D0DE}
	operator Cxformats::_di_IcxFormatControllerListener()
	{
		Cxformats::_di_IcxFormatControllerListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxformats::IcxFormatControllerListener*(void) { return (Cxformats::IcxFormatControllerListener*)&__IcxFormatControllerListener; }
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
	
};


class DELPHICLASS TcxSchedulerPopupMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerPopupMenu : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomScheduler* FScheduler;
	System::Classes::TComponent* FPopupMenu;
	Vcl::Menus::TPopupMenu* FInternalMenu;
	bool FUseBuiltInPopupMenu;
	Vcl::Menus::TMenuItem* __fastcall GetRoot(void);
	void __fastcall SetPopupMenu(System::Classes::TComponent* const Value);
	
protected:
	Vcl::Menus::TMenuItem* __fastcall AddValidSeparator(Vcl::Menus::TMenuItem* AOwner);
	void __fastcall CreateInternalMenu(void);
	virtual void __fastcall CreateItems(void);
	Vcl::Menus::TMenuItem* __fastcall CreateSeparator(Vcl::Menus::TMenuItem* AOwner);
	Vcl::Menus::TMenuItem* __fastcall CreateSubItem(Vcl::Menus::TMenuItem* AOwner, const System::UnicodeString ACaption, int ACommand = 0xffffffff, int AImageIndex = 0xffffffff, bool AEnabled = true, bool AChecked = false);
	virtual void __fastcall DoExecute(int ACommand);
	virtual bool __fastcall DoOnClick(int ACommand);
	virtual bool __fastcall DoOnPopup(void);
	void __fastcall ExecuteCommand(int ACommand);
	Vcl::Menus::TMenuItem* __fastcall FindItemByCommand(Vcl::Menus::TMenuItem* AOwnerItem, int ACommand);
	virtual bool __fastcall IsValidCommand(int ACommand);
	void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall OnItemClickHandler(System::TObject* Sender);
	Cxschedulerstorage::TcxCustomSchedulerStorage* __fastcall Storage(void);
	__property Vcl::Menus::TPopupMenu* InternalMenu = {read=FInternalMenu};
	__property Vcl::Menus::TMenuItem* Root = {read=GetRoot};
	
public:
	__fastcall virtual TcxSchedulerPopupMenu(TcxCustomScheduler* AScheduler);
	__fastcall virtual ~TcxSchedulerPopupMenu(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall Popup(int X, int Y);
	__property TcxCustomScheduler* Scheduler = {read=FScheduler};
	
__published:
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu, write=SetPopupMenu};
	__property bool UseBuiltInPopupMenu = {read=FUseBuiltInPopupMenu, write=FUseBuiltInPopupMenu, default=1};
};

#pragma pack(pop)

class DELPHICLASS TcxSchedulerCustomContentPopupMenu;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSchedulerCustomContentPopupMenu : public TcxSchedulerPopupMenu
{
	typedef TcxSchedulerPopupMenu inherited;
	
private:
	int FNewID;
	int FAllDayID;
	int FReccurenceID;
	
protected:
	bool __fastcall CanCreateEvent(void);
	void __fastcall CreateNewEventItems(bool ANew, bool AllDay, bool AReccurence, int ANewID, int AllDayID, int AReccurenceID);
	virtual void __fastcall DoExecute(int ACommand);
	
public:
	__fastcall virtual TcxSchedulerCustomContentPopupMenu(TcxCustomScheduler* AScheduler);
public:
	/* TcxSchedulerPopupMenu.Destroy */ inline __fastcall virtual ~TcxSchedulerCustomContentPopupMenu(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxSchedulerContentPopupMenuPopupEvent)(TcxSchedulerContentPopupMenu* Sender, Vcl::Menus::TPopupMenu* ABuiltInMenu, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerContentPopupMenuClickEvent)(TcxSchedulerContentPopupMenu* Sender, TcxSchedulerContentPopupMenuItem AItem, bool &AHandled);

class PASCALIMPLEMENTATION TcxSchedulerContentPopupMenu : public TcxSchedulerCustomContentPopupMenu
{
	typedef TcxSchedulerCustomContentPopupMenu inherited;
	
private:
	TcxSchedulerContentPopupMenuItems FActualItems;
	TcxSchedulerContentPopupMenuItems FItems;
	System::TDateTime FSavedDate;
	TcxSchedulerContentPopupMenuPopupEvent FOnPopup;
	TcxSchedulerContentPopupMenuClickEvent FOnClick;
	void __fastcall CreateGoToThisDayItem(void);
	
protected:
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	virtual bool __fastcall DoOnClick(int ACommand);
	virtual bool __fastcall DoOnPopup(void);
	virtual bool __fastcall IsValidCommand(int ACommand);
	__property TcxSchedulerContentPopupMenuItems ActualItems = {read=FActualItems, nodefault};
	
public:
	__fastcall virtual TcxSchedulerContentPopupMenu(TcxCustomScheduler* AScheduler);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Execute(TcxSchedulerContentPopupMenuItem AItem);
	Vcl::Menus::TMenuItem* __fastcall GetMenuItem(TcxSchedulerContentPopupMenuItem AItem);
	
__published:
	__property TcxSchedulerContentPopupMenuItems Items = {read=FItems, write=FItems, default=127};
	__property PopupMenu;
	__property UseBuiltInPopupMenu = {default=1};
	__property TcxSchedulerContentPopupMenuClickEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TcxSchedulerContentPopupMenuPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
public:
	/* TcxSchedulerPopupMenu.Destroy */ inline __fastcall virtual ~TcxSchedulerContentPopupMenu(void) { }
	
};


enum TcxSchedulerEventPopupMenuItem : unsigned char { epmiOpen, epmiEditSeries, epmiShowTimeAs, epmiLabel, epmiDelete };

typedef System::Set<TcxSchedulerEventPopupMenuItem, TcxSchedulerEventPopupMenuItem::epmiOpen, TcxSchedulerEventPopupMenuItem::epmiDelete>  TcxSchedulerEventPopupMenuItems;

typedef void __fastcall (__closure *TcxSchedulerEventPopupMenuPopupEvent)(TcxSchedulerEventPopupMenu* Sender, Vcl::Menus::TPopupMenu* ABuiltInMenu, bool &AHandled);

typedef void __fastcall (__closure *TcxSchedulerEventPopupMenuClickEvent)(TcxSchedulerEventPopupMenu* Sender, TcxSchedulerEventPopupMenuItem AItem, int ASubItemIndex, bool &AHandled);

class PASCALIMPLEMENTATION TcxSchedulerEventPopupMenu : public TcxSchedulerPopupMenu
{
	typedef TcxSchedulerPopupMenu inherited;
	
private:
	Cxschedulerstorage::TcxSchedulerControlEvent* FEvent;
	TcxSchedulerEventPopupMenuItems FItems;
	TcxSchedulerEventPopupMenuPopupEvent FOnPopup;
	TcxSchedulerEventPopupMenuClickEvent FOnClick;
	void __fastcall CreateDeleteItem(void);
	void __fastcall CreateLabelItems(void);
	void __fastcall CreateTimeItems(void);
	int __fastcall GetCommand(TcxSchedulerEventPopupMenuItem AItem, int ASubItemIndex);
	bool __fastcall CanEdit(void);
	Cxschedulerstorage::TcxSchedulerControlEvent* __fastcall GetEvent(void);
	void __fastcall UnpackCommand(int ACommand, /* out */ TcxSchedulerEventPopupMenuItem &AItem, /* out */ int &ASubItemIndex);
	
protected:
	virtual void __fastcall CreateItems(void);
	virtual void __fastcall DoExecute(int ACommand);
	virtual bool __fastcall DoOnClick(int ACommand);
	virtual bool __fastcall DoOnPopup(void);
	virtual bool __fastcall IsValidCommand(int ACommand);
	void __fastcall SetEventLabelColor(int AColor);
	void __fastcall SetEventState(int AState);
	
public:
	__fastcall virtual TcxSchedulerEventPopupMenu(TcxCustomScheduler* AScheduler);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	Vcl::Menus::TMenuItem* __fastcall GetMenuItem(TcxSchedulerEventPopupMenuItem AItem, int ASubItemIndex = 0xffffffff);
	__property Cxschedulerstorage::TcxSchedulerControlEvent* Event = {read=FEvent};
	
__published:
	__property TcxSchedulerEventPopupMenuItems Items = {read=FItems, write=FItems, default=31};
	__property PopupMenu;
	__property UseBuiltInPopupMenu = {default=1};
	__property TcxSchedulerEventPopupMenuClickEvent OnClick = {read=FOnClick, write=FOnClick};
	__property TcxSchedulerEventPopupMenuPopupEvent OnPopup = {read=FOnPopup, write=FOnPopup};
public:
	/* TcxSchedulerPopupMenu.Destroy */ inline __fastcall virtual ~TcxSchedulerEventPopupMenu(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const int LastAvailableDate = int(0x2d2462);
static const System::Int8 cxDefaultTimeScale = System::Int8(0x1e);
static const System::Int8 htcControl = System::Int8(0x0);
static const System::Int8 htcTime = System::Int8(0x1);
static const System::Int8 htcResource = System::Int8(0x2);
static const System::Int8 cxcsBackground = System::Int8(0x0);
static const System::Int8 cxcsContent = System::Int8(0x1);
static const System::Int8 cxcsEvent = System::Int8(0x2);
static const System::Int8 cxcsGroupSeparator = System::Int8(0x3);
static const System::Int8 cxcsDayHeader = System::Int8(0x4);
static const System::Int8 cxcsSelection = System::Int8(0x5);
static const System::Int8 cxcsHSplitter = System::Int8(0x6);
static const System::Int8 cxcsVSplitter = System::Int8(0x7);
static const System::Int8 cxcsResourceHeader = System::Int8(0x8);
static const System::Int8 cxcsMaxValue = System::Int8(0x8);
static const System::Int8 cxcsSchedulerStyleFirst = System::Int8(0x0);
static const System::Int8 cxcsSchedulerStyleLast = System::Int8(0x8);
static const System::Byte cxDefaultSchedulerHeight = System::Byte(0xfa);
static const System::Word cxDefaultSchedulerWidth = System::Word(0x15e);
static const System::Int8 cxDefaultSplitterWidth = System::Int8(0x5);
static const System::Int8 cxDefaultGroupSeparatorWidth = System::Int8(0xb);
static const System::Int8 cxDefaultResourcesPerPage = System::Int8(0x0);
static const System::Int8 cxMinSplitterWidth = System::Int8(0x3);
extern PACKAGE int cxscMinHintWidth;
extern PACKAGE int cxscMaxHintWidth;
static const System::Int8 cxScrollInterval = System::Int8(0x19);
static const System::Int8 cxScrollZoneSize = System::Int8(0xa);
static const System::Word cxNavigatorStartTimer = System::Word(0x12c);
static const System::Int8 cxSchedulerFirstButton = System::Int8(0x0);
static const System::Int8 cxSchedulerPrevPageButton = System::Int8(0x1);
static const System::Int8 cxSchedulerPrevButton = System::Int8(0x2);
static const System::Int8 cxSchedulerNextButton = System::Int8(0x3);
static const System::Int8 cxSchedulerNextPageButton = System::Int8(0x4);
static const System::Int8 cxSchedulerLastButton = System::Int8(0x5);
static const System::Int8 cxSchedulerShowMoreResourcesButton = System::Int8(0x6);
static const System::Int8 cxSchedulerShowFewerResourcesButton = System::Int8(0x7);
extern PACKAGE System::StaticArray<bool, 8> cxSchedulerNavigatorVisibility;
#define SCF_SCHEDULERCLIPBOARDFORMAT L"ExpressScheduler 2.0"
extern PACKAGE int CF_SCHEDULERDATA;
extern PACKAGE bool __fastcall IsHeaderEvent(Cxschedulerstorage::TcxSchedulerEvent* AEvent);
}	/* namespace Cxschedulercustomcontrols */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCHEDULERCUSTOMCONTROLS)
using namespace Cxschedulercustomcontrols;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxschedulercustomcontrolsHPP
