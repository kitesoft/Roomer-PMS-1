// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxScrollBar.pas' rev: 24.00 (Win64)

#ifndef CxscrollbarHPP
#define CxscrollbarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxFading.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxscrollbar
{
//-- type declarations -------------------------------------------------------
__interface IcxScrollBarOwner;
typedef System::DelphiInterface<IcxScrollBarOwner> _di_IcxScrollBarOwner;
__interface  INTERFACE_UUID("{56771164-C253-40FF-B6D4-2A29D0C90236}") IcxScrollBarOwner  : public System::IInterface 
{
	
public:
	virtual Vcl::Controls::TWinControl* __fastcall GetControl(void) = 0 ;
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void) = 0 ;
};

class DELPHICLASS TcxScrollBarPartFadingHelper;
class DELPHICLASS TcxScrollBarPartViewInfo;
class PASCALIMPLEMENTATION TcxScrollBarPartFadingHelper : public Dxfading::TdxFadingObjectHelper
{
	typedef Dxfading::TdxFadingObjectHelper inherited;
	
private:
	TcxScrollBarPartViewInfo* FOwner;
	Cxlookandfeelpainters::TcxButtonState FState;
	
protected:
	virtual bool __fastcall CanFade(void);
	virtual void __fastcall DrawFadeImage(void);
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	
public:
	__fastcall TcxScrollBarPartFadingHelper(TcxScrollBarPartViewInfo* AOwner);
	void __fastcall UpdateState(void);
	__property TcxScrollBarPartViewInfo* Owner = {read=FOwner};
public:
	/* TdxFadingObjectHelper.Destroy */ inline __fastcall virtual ~TcxScrollBarPartFadingHelper(void) { }
	
};


class DELPHICLASS TcxScrollBarViewInfo;
class DELPHICLASS TcxScrollBarPainter;
class PASCALIMPLEMENTATION TcxScrollBarPartViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxScrollBarViewInfo* FOwner;
	System::Types::TRect FBounds;
	TcxScrollBarPartFadingHelper* FFadingHelper;
	Cxlookandfeelpainters::TcxScrollBarPart FPart;
	Cxlookandfeelpainters::TcxButtonState FState;
	TcxScrollBarPainter* __fastcall GetPainter(void);
	Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AValue);
	
protected:
	bool __fastcall CanFade(void);
	void __fastcall Invalidate(void);
	void __fastcall UpdateFadingHelperState(void);
	__property TcxScrollBarPartFadingHelper* FadingHelper = {read=FFadingHelper};
	__property TcxScrollBarViewInfo* Owner = {read=FOwner};
	__property TcxScrollBarPainter* Painter = {read=GetPainter};
	
public:
	__fastcall TcxScrollBarPartViewInfo(TcxScrollBarViewInfo* AOwner, Cxlookandfeelpainters::TcxScrollBarPart APart);
	__fastcall virtual ~TcxScrollBarPartViewInfo(void);
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property Cxlookandfeelpainters::TcxScrollBarPart Part = {read=FPart, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=GetState, write=SetState, nodefault};
};


class DELPHICLASS TcxScrollBarHelper;
class PASCALIMPLEMENTATION TcxScrollBarViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FArrowButtonLength;
	Vcl::Forms::TScrollBarKind FKind;
	int FLength;
	Cxlookandfeelpainters::TcxScrollBarPart FHotPart;
	int FMinThumbnailSize;
	System::StaticArray<TcxScrollBarPartViewInfo*, 5> FPartInfos;
	Cxlookandfeelpainters::TcxScrollBarPart FPressedPart;
	TcxScrollBarHelper* FScrollBar;
	void __fastcall CheckKind(void);
	int __fastcall GetLength(void);
	int __fastcall GetHeight(void);
	TcxScrollBarPartViewInfo* __fastcall GetPartInfo(Cxlookandfeelpainters::TcxScrollBarPart APartType);
	void __fastcall SetHotPart(Cxlookandfeelpainters::TcxScrollBarPart AValue);
	void __fastcall SetPressedPart(Cxlookandfeelpainters::TcxScrollBarPart AValue);
	System::Types::TRect __fastcall GetBounds(void);
	Vcl::Forms::TScrollBarKind __fastcall GetKind(void);
	int __fastcall GetMax(void);
	int __fastcall GetMin(void);
	int __fastcall GetMinThumbnailSize(void);
	int __fastcall GetPageSize(void);
	int __fastcall GetPosition(void);
	bool __fastcall IsEnabled(void);
	
protected:
	void __fastcall CreatePartInfos(void);
	void __fastcall DestroyPartInfos(void);
	virtual int __fastcall GetArrowButtonLength(void);
	Cxlookandfeelpainters::TcxScrollBarPart __fastcall GetPart(const System::Types::TPoint P);
	void __fastcall UpdateFadingHelperStates(void);
	__property TcxScrollBarHelper* ScrollBar = {read=FScrollBar};
	
public:
	__fastcall virtual TcxScrollBarViewInfo(TcxScrollBarHelper* AScrollBar);
	__fastcall virtual ~TcxScrollBarViewInfo(void);
	void __fastcall AdjustPageRects(void);
	virtual void __fastcall Calculate(void);
	void __fastcall CalculateThumbnailRect(void);
	void __fastcall SetThumbnailPos(int APos);
	__property System::Types::TRect Bounds = {read=GetBounds};
	__property Cxlookandfeelpainters::TcxScrollBarPart HotPart = {read=FHotPart, write=SetHotPart, nodefault};
	__property TcxScrollBarPartViewInfo* PartInfo[Cxlookandfeelpainters::TcxScrollBarPart APartType] = {read=GetPartInfo};
	__property Cxlookandfeelpainters::TcxScrollBarPart PressedPart = {read=FPressedPart, write=SetPressedPart, nodefault};
};


typedef System::TMetaClass* TcxScrollBarViewInfoClass;

class DELPHICLASS TcxScrollBarController;
class PASCALIMPLEMENTATION TcxScrollBarController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TPoint FDownMousePos;
	System::Types::TPoint FLastMousePos;
	int FSavePosition;
	System::Types::TPoint FSaveThumbnailPos;
	TcxScrollBarHelper* FScrollBar;
	Cxclasses::TcxTimer* FTimer;
	void __fastcall DoScroll(Cxlookandfeelpainters::TcxScrollBarPart APart);
	void __fastcall FinishScrolling(Cxlookandfeelpainters::TcxScrollBarPart AHotPart = (Cxlookandfeelpainters::TcxScrollBarPart)(0x0));
	int __fastcall GetPositionFromThumbnail(void);
	TcxScrollBarViewInfo* __fastcall GetViewInfo(void);
	void __fastcall InternalScroll(System::Uitypes::TScrollCode AScrollCode);
	bool __fastcall IsButtonHotTrack(void);
	void __fastcall OnTimer(System::TObject* Sender);
	
protected:
	virtual void __fastcall DoMouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseEnter(Vcl::Controls::TControl* AControl);
	virtual void __fastcall DoMouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall DoMouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoMouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__property TcxScrollBarHelper* ScrollBar = {read=FScrollBar};
	__property TcxScrollBarViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxScrollBarController(TcxScrollBarHelper* AScrollBar);
	__fastcall virtual ~TcxScrollBarController(void);
	void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
};


typedef System::TMetaClass* TcxScrollBarControllerClass;

class PASCALIMPLEMENTATION TcxScrollBarPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxScrollBarHelper* FScrollBar;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	TcxScrollBarViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DoDrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxScrollBarPart APart, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawScrollBarBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawScrollBarPart(Cxgraphics::TcxCanvas* ACanvas, Cxlookandfeelpainters::TcxScrollBarPart APart);
	virtual bool __fastcall FadingAvailable(void);
	virtual int __fastcall GetMinThumbnailSize(void);
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TcxScrollBarHelper* ScrollBar = {read=FScrollBar};
	__property TcxScrollBarViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxScrollBarPainter(TcxScrollBarHelper* AScrollBar);
	__fastcall virtual ~TcxScrollBarPainter(void);
	virtual bool __fastcall IsButtonHotTrack(void);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
};


typedef System::TMetaClass* TcxScrollBarPainterClass;

class PASCALIMPLEMENTATION TcxScrollBarHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::Types::TRect FBoundsRect;
	TcxScrollBarController* FController;
	bool FEnabled;
	bool FIsNonClient;
	Vcl::Forms::TScrollBarKind FKind;
	Vcl::Forms::TScrollBarInc FLargeChange;
	int FMax;
	int FMin;
	_di_IcxScrollBarOwner FOwner;
	int FPageSize;
	TcxScrollBarPainter* FPainter;
	int FPosition;
	Vcl::Forms::TScrollBarInc FSmallChange;
	bool FUnlimitedTracking;
	TcxScrollBarViewInfo* FViewInfo;
	System::Classes::TNotifyEvent FOnChange;
	Vcl::Stdctrls::TScrollEvent FOnScroll;
	bool FVisible;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	void __fastcall RefreshNCPart(const System::Types::TRect &ARect);
	
protected:
	System::Types::TRect __fastcall GetBoundsRect(void);
	bool __fastcall GetEnabled(void);
	Vcl::Forms::TScrollBarKind __fastcall GetKind(void);
	Vcl::Forms::TScrollBarInc __fastcall GetLargeChange(void);
	int __fastcall GetMax(void);
	int __fastcall GetMin(void);
	int __fastcall GetPageSize(void);
	int __fastcall GetPosition(void);
	Vcl::Forms::TScrollBarInc __fastcall GetSmallChange(void);
	bool __fastcall GetUnlimitedTracking(void);
	bool __fastcall GetVisible(void);
	void __fastcall SetBoundsRect(const System::Types::TRect &AValue);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetKind(Vcl::Forms::TScrollBarKind Value);
	void __fastcall SetLargeChange(Vcl::Forms::TScrollBarInc Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetMin(int Value);
	void __fastcall SetPageSize(int Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetVisible(bool AValue);
	void __fastcall SetSmallChange(Vcl::Forms::TScrollBarInc Value);
	void __fastcall SetUnlimitedTracking(bool Value);
	virtual void __fastcall Change(void);
	virtual void __fastcall DoPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxScrollBarControllerClass __fastcall GetControllerClass(void);
	virtual TcxScrollBarPainterClass __fastcall GetPainterClass(void);
	virtual TcxScrollBarViewInfoClass __fastcall GetViewInfoClass(void);
	NativeUInt __fastcall Handle(void);
	bool __fastcall HandleAllocated(void);
	virtual void __fastcall Invalidate(void);
	virtual void __fastcall InvalidateRect(const System::Types::TRect &ARect, bool AEraseBackground = false);
	virtual bool __fastcall IsOwnerControlCapture(void);
	virtual System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint APoint);
	virtual void __fastcall Scroll(System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	__property TcxScrollBarController* Controller = {read=FController};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property _di_IcxScrollBarOwner Owner = {read=FOwner};
	__property TcxScrollBarPainter* Painter = {read=FPainter};
	__property TcxScrollBarViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxScrollBarHelper(_di_IcxScrollBarOwner AOwner);
	__fastcall virtual ~TcxScrollBarHelper(void);
	virtual void __fastcall Calculate(void);
	virtual void __fastcall CancelMode(void);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	virtual void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas)/* overload */;
	virtual void __fastcall Paint(HDC ADC)/* overload */;
	virtual void __fastcall Repaint(void);
	void __fastcall SetScrollParams(int AMin, int AMax, int APosition, int APageSize, bool ARedraw = true);
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect, write=SetBoundsRect};
	__property bool Enabled = {read=GetEnabled, write=SetEnabled, nodefault};
	__property bool IsNonClient = {read=FIsNonClient, write=FIsNonClient, nodefault};
	__property Vcl::Forms::TScrollBarKind Kind = {read=GetKind, write=SetKind, nodefault};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=GetLargeChange, write=SetLargeChange, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
	__property int Max = {read=GetMax, write=SetMax, nodefault};
	__property int Min = {read=GetMin, write=SetMin, nodefault};
	__property int PageSize = {read=GetPageSize, write=SetPageSize, nodefault};
	__property int Position = {read=GetPosition, write=SetPosition, nodefault};
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=GetSmallChange, write=SetSmallChange, nodefault};
	__property bool UnlimitedTracking = {read=GetUnlimitedTracking, write=SetUnlimitedTracking, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Vcl::Stdctrls::TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
};


typedef System::TMetaClass* TcxScrollBarHelperClass;

class DELPHICLASS TcxScrollBar;
class PASCALIMPLEMENTATION TcxScrollBar : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	TcxScrollBarHelper* FHelper;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	bool FRealCtl3D;
	Dxthememanager::TdxThemeChangedNotificator* FThemeChangedNotificator;
	System::Classes::TNotifyEvent FOnChange;
	System::Classes::TNotifyEvent FOnMouseEnter;
	System::Classes::TNotifyEvent FOnMouseLeave;
	Vcl::Stdctrls::TScrollEvent FOnScroll;
	bool __fastcall GetCtl3D(void);
	bool __fastcall GetInternalCtl3D(void);
	HIDESBASE bool __fastcall IsCtl3DStored(void);
	HIDESBASE void __fastcall SetCtl3D(bool Value);
	void __fastcall SetInternalCtl3D(bool Value);
	void __fastcall ThemeChanged(void);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CNHScroll(Winapi::Messages::TWMScroll &Message);
	MESSAGE void __fastcall CNVScroll(Winapi::Messages::TWMScroll &Message);
	MESSAGE void __fastcall CNCtlColorScrollBar(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMGestureNotify(Dxtouch::TWMGestureNotify &Message);
	
protected:
	void __fastcall DoChange(System::TObject* Sender);
	void __fastcall DoScrollEvent(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	virtual void __fastcall Change(void);
	virtual TcxScrollBarHelperClass __fastcall GetHelperClass(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	Vcl::Forms::TScrollBarKind __fastcall GetKind(void);
	Vcl::Forms::TScrollBarInc __fastcall GetLargeChange(void);
	int __fastcall GetMax(void);
	int __fastcall GetMin(void);
	int __fastcall GetPageSize(void);
	int __fastcall GetPosition(void);
	Vcl::Forms::TScrollBarInc __fastcall GetSmallChange(void);
	bool __fastcall GetUnlimitedTracking(void);
	void __fastcall SetKind(Vcl::Forms::TScrollBarKind Value);
	void __fastcall SetLargeChange(Vcl::Forms::TScrollBarInc AValue);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetMax(int Value);
	void __fastcall SetMin(int Value);
	void __fastcall SetPageSize(int Value);
	void __fastcall SetPosition(int Value);
	void __fastcall SetSmallChange(Vcl::Forms::TScrollBarInc AValue);
	void __fastcall SetUnlimitedTracking(bool AValue);
	virtual void __fastcall DoPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall Scroll(System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	__property TcxScrollBarHelper* Helper = {read=FHelper};
	__property bool InternalCtl3D = {read=GetInternalCtl3D, write=SetInternalCtl3D, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	
public:
	__fastcall virtual TcxScrollBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxScrollBar(void);
	void __fastcall SetScrollParams(int AMin, int AMax, int APosition, int APageSize, bool ARedraw = true);
	void __fastcall SetParams(int APosition, int AMin, int AMax);
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property Constraints;
	__property Ctl3D = {read=GetCtl3D, write=SetCtl3D, stored=IsCtl3DStored};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Vcl::Forms::TScrollBarKind Kind = {read=GetKind, write=SetKind, default=0};
	__property Vcl::Forms::TScrollBarInc LargeChange = {read=GetLargeChange, write=SetLargeChange, default=1};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property int Max = {read=GetMax, write=SetMax, default=100};
	__property int Min = {read=GetMin, write=SetMin, default=0};
	__property int PageSize = {read=GetPageSize, write=SetPageSize, nodefault};
	__property ParentCtl3D = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property int Position = {read=GetPosition, write=SetPosition, default=0};
	__property ShowHint;
	__property Vcl::Forms::TScrollBarInc SmallChange = {read=GetSmallChange, write=SetSmallChange, default=1};
	__property bool UnlimitedTracking = {read=GetUnlimitedTracking, write=SetUnlimitedTracking, default=0};
	__property Visible = {default=1};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	__property OnContextPopup;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property System::Classes::TNotifyEvent OnMouseEnter = {read=FOnMouseEnter, write=FOnMouseEnter};
	__property System::Classes::TNotifyEvent OnMouseLeave = {read=FOnMouseLeave, write=FOnMouseLeave};
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property Vcl::Stdctrls::TScrollEvent OnScroll = {read=FOnScroll, write=FOnScroll};
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxScrollBar(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxScrollBarOwner;	/* IcxScrollBarOwner */
	
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
	// {56771164-C253-40FF-B6D4-2A29D0C90236}
	operator _di_IcxScrollBarOwner()
	{
		_di_IcxScrollBarOwner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxScrollBarOwner*(void) { return (IcxScrollBarOwner*)&__IcxScrollBarOwner; }
	#endif
	
};


typedef System::TMetaClass* TcxScrollBarClass;

//-- var, const, procedure ---------------------------------------------------
static const System::Word cxScrollInitialInterval = System::Word(0x190);
static const System::Int8 cxScrollInterval = System::Int8(0x3c);
extern PACKAGE int cxScrollMinDistance;
extern PACKAGE int cxScrollMaxDistance;
extern PACKAGE System::Types::TSize __fastcall GetScrollBarSize(void);
}	/* namespace Cxscrollbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSCROLLBAR)
using namespace Cxscrollbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxscrollbarHPP
