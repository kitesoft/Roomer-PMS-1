// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxSkinsForm.pas' rev: 24.00 (Win64)

#ifndef DxskinsformHPP
#define DxskinsformHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.MultiMon.hpp>	// Pascal unit
#include <Winapi.ShellAPI.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDWMApi.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <dxSkinsLookAndFeelPainter.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <dxSkinInfo.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxskinsform
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxSkinWinControllerClass;

class DELPHICLASS TdxSkinWinController;
class PASCALIMPLEMENTATION TdxSkinWinController : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool FCanUseSkin;
	HWND FHandle;
	Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* FLookAndFeelPainter;
	TdxSkinWinController* FMaster;
	Vcl::Controls::TWinControl* FWinControl;
	Cxcontrols::TcxWindowProcLinkedObject* FWindowProcObject;
	bool __fastcall GetHasGraphicChildren(void);
	bool __fastcall GetIsHooked(void);
	Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	void __fastcall SetHandle(HWND AHandle);
	
protected:
	virtual bool __fastcall CanFinalizeEngine(void);
	virtual Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* __fastcall FindLookAndFeelPainter(void);
	virtual TdxSkinWinController* __fastcall FindMasterController(void);
	virtual bool __fastcall GetCanUseSkin(void);
	virtual bool __fastcall GetUseSkin(void);
	virtual bool __fastcall IsHookAvailable(void);
	virtual void __fastcall DefWndProc(void *AMessage);
	virtual void __fastcall MasterDestroyed(void);
	void __fastcall RedrawWindow(bool AUpdateNow);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &AMessage);
	virtual void __fastcall HookWndProc(void);
	virtual void __fastcall UnHookWndProc(void);
	virtual void __fastcall MouseLeave(void);
	
public:
	__fastcall virtual TdxSkinWinController(HWND AHandle);
	__fastcall virtual ~TdxSkinWinController(void);
	__classmethod virtual bool __fastcall IsMDIChildWindow(HWND AHandle);
	__classmethod virtual bool __fastcall IsMDIClientWindow(HWND AHandle);
	__classmethod virtual bool __fastcall IsMessageDlgWindow(HWND AHandle);
	__classmethod bool __fastcall IsSkinActive(HWND AHandle);
	__classmethod void __fastcall FinalizeEngine(HWND AHandle);
	__classmethod void __fastcall InitializeEngine(HWND AHandle);
	virtual void __fastcall InvalidateNC(void);
	virtual void __fastcall Refresh(void);
	virtual void __fastcall RefreshController(void);
	void __fastcall RefreshControllerAndUpdate(void);
	virtual void __fastcall Update(void);
	__property HWND Handle = {read=FHandle, write=SetHandle};
	__property bool HasGraphicChildren = {read=GetHasGraphicChildren, nodefault};
	__property bool IsHooked = {read=GetIsHooked, nodefault};
	__property Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TdxSkinWinController* Master = {read=FMaster};
	__property bool UseSkin = {read=GetUseSkin, nodefault};
	__property Vcl::Controls::TWinControl* WinControl = {read=FWinControl};
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


class DELPHICLASS TdxSkinWinControllerList;
class PASCALIMPLEMENTATION TdxSkinWinControllerList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSkinWinController* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TdxSkinWinController* __fastcall GetItem(int Index);
	
public:
	TdxSkinWinController* __fastcall GetControllerByControl(Vcl::Controls::TWinControl* AControl);
	TdxSkinWinController* __fastcall GetControllerByHandle(HWND AHandle);
	void __fastcall Refresh(void);
	__property TdxSkinWinController* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TcxObjectList.Create */ inline __fastcall TdxSkinWinControllerList(bool AOwnObjects) : Cxclasses::TcxObjectList(AOwnObjects) { }
	
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinWinControllerList(void) { }
	
};


enum TdxSkinFormCorner : unsigned char { sfcLeftTop, sfcRightTop, sfcLeftBottom, sfcRightBottom };

enum TdxSkinFormScrollBar : unsigned char { saeHorzScroll, saeVertScroll };

class DELPHICLASS TdxSkinCustomFormController;
class DELPHICLASS TdxSkinFormPainter;
class DELPHICLASS TdxSkinFormScrollBarsController;
class DELPHICLASS TdxSkinForm;
class DELPHICLASS TdxSkinFormNonClientAreaInfo;
class DELPHICLASS TdxSkinFormIconInfoList;
class PASCALIMPLEMENTATION TdxSkinCustomFormController : public TdxSkinWinController
{
	typedef TdxSkinWinController inherited;
	
private:
	bool FForceRedraw;
	bool FHasRegion;
	int FLockRedrawCount;
	TdxSkinFormPainter* FPainter;
	TdxSkinFormScrollBarsController* FScrollBarsController;
	TdxSkinForm* FSkinForm;
	TdxSkinFormNonClientAreaInfo* FViewInfo;
	Vcl::Forms::TCustomForm* __fastcall GetForm(void);
	TdxSkinFormIconInfoList* __fastcall GetIconsInfo(void);
	
protected:
	virtual bool __fastcall GetUseSkin(void);
	virtual bool __fastcall IsHookAvailable(void);
	virtual void __fastcall CalculateViewInfo(void);
	virtual void __fastcall CheckWindowRgn(void);
	virtual void __fastcall DrawWindowBackground(HDC DC);
	virtual void __fastcall DrawWindowBorder(HDC DC = (HDC)(0ULL));
	virtual void __fastcall DrawWindowScrollArea(HDC DC = (HDC)(0ULL));
	virtual void __fastcall FlushWindowRgn(bool ARedraw = true);
	virtual void __fastcall InitializeMessageForm(void);
	void __fastcall InvalidateBorders(void);
	virtual bool __fastcall HandleInternalMessages(Winapi::Messages::TMessage &AMessage);
	virtual bool __fastcall HandleWindowMessage(Winapi::Messages::TMessage &AMessage);
	bool __fastcall RefreshOnMouseEvent(bool AForceRefresh = false);
	virtual void __fastcall MouseLeave(void);
	void __fastcall RefreshOnSystemMenuShown(void);
	virtual void __fastcall UnHookWndProc(void);
	void __fastcall UpdateViewInfoState(void);
	void __fastcall AfterWndProc(Winapi::Messages::TMessage &AMessage);
	void __fastcall BeforeWndProc(Winapi::Messages::TMessage &AMessage);
	virtual void __fastcall DefWndProc(void *AMessage);
	virtual bool __fastcall NCMouseDown(const System::Types::TPoint P);
	virtual bool __fastcall NCMouseUp(const System::Types::TPoint P);
	void __fastcall LockRedraw(void);
	void __fastcall PostRedraw(void);
	void __fastcall UnlockRedraw(void);
	void __fastcall DoPopupSystemMenu(Vcl::Forms::TCustomForm* AForm, HMENU ASysMenu);
	void __fastcall ShowSystemMenu(const System::Types::TPoint P)/* overload */;
	void __fastcall ShowSystemMenu(const System::Types::TPoint P, const System::Types::TRect &AExcludeRect, bool ABottomAlign = false)/* overload */;
	void __fastcall ShowSystemMenu(void)/* overload */;
	virtual void __fastcall WMActivate(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall WMContextMenu(Winapi::Messages::TWMContextMenu &Message);
	virtual void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	virtual void __fastcall WMInitMenu(Winapi::Messages::TWMInitMenu &Message);
	virtual void __fastcall WMNCActivate(Winapi::Messages::TWMNCActivate &Message);
	virtual void __fastcall WMNCButtonDown(Winapi::Messages::TWMNCHitMessage &Message);
	virtual void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	virtual bool __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	void __fastcall WMNCMouseMove(Winapi::Messages::TWMNCHitMessage &Message);
	virtual void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	virtual void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	virtual void __fastcall WMPrint(Winapi::Messages::TWMPrint &Message);
	virtual void __fastcall WMSetText(Winapi::Messages::TWMSetText &Message);
	virtual void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	virtual void __fastcall WMSysCommand(Winapi::Messages::TWMSysCommand &Message);
	virtual void __fastcall WMSysMenu(Winapi::Messages::TMessage &Message);
	virtual void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &AMessage);
	
public:
	__fastcall virtual TdxSkinCustomFormController(HWND AHandle);
	__fastcall TdxSkinCustomFormController(TdxSkinForm* ASkinForm);
	__fastcall virtual ~TdxSkinCustomFormController(void);
	virtual void __fastcall Refresh(void);
	virtual void __fastcall RefreshController(void);
	__property bool ForceRedraw = {read=FForceRedraw, write=FForceRedraw, nodefault};
	__property Vcl::Forms::TCustomForm* Form = {read=GetForm};
	__property bool HasRegion = {read=FHasRegion, write=FHasRegion, nodefault};
	__property TdxSkinFormIconInfoList* IconsInfo = {read=GetIconsInfo};
	__property TdxSkinFormPainter* Painter = {read=FPainter};
	__property TdxSkinFormScrollBarsController* ScrollBarsController = {read=FScrollBarsController};
	__property TdxSkinForm* SkinForm = {read=FSkinForm};
	__property TdxSkinFormNonClientAreaInfo* ViewInfo = {read=FViewInfo};
};


class DELPHICLASS TdxSkinFormIconInfo;
class PASCALIMPLEMENTATION TdxSkinFormIconInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	System::Types::TRect FHitBounds;
	Dxskininfo::TdxSkinFormIcon FIconType;
	TdxSkinFormIconInfoList* FOwner;
	Dxskinscore::TdxSkinElementState FState;
	int __fastcall GetCommand(void);
	bool __fastcall GetEnabled(void);
	int __fastcall GetHitTest(void);
	TdxSkinFormNonClientAreaInfo* __fastcall GetNonClientAreaInfo(void);
	
public:
	__fastcall virtual TdxSkinFormIconInfo(Dxskininfo::TdxSkinFormIcon AType, TdxSkinFormIconInfoList* AOwner);
	Dxskinscore::TdxSkinElementState __fastcall CalculateState(void);
	__property System::Types::TRect Bounds = {read=FBounds, write=FBounds};
	__property int Command = {read=GetCommand, nodefault};
	__property bool Enabled = {read=GetEnabled, nodefault};
	__property System::Types::TRect HitBounds = {read=FHitBounds, write=FHitBounds};
	__property int HitTest = {read=GetHitTest, nodefault};
	__property Dxskininfo::TdxSkinFormIcon IconType = {read=FIconType, nodefault};
	__property TdxSkinFormNonClientAreaInfo* NonClientAreaInfo = {read=GetNonClientAreaInfo};
	__property TdxSkinFormIconInfoList* Owner = {read=FOwner};
	__property Dxskinscore::TdxSkinElementState State = {read=FState, write=FState, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinFormIconInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxSkinFormIconInfoList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxSkinFormIconInfo* operator[](int Index) { return Items[Index]; }
	
private:
	TdxSkinFormIconInfo* FIconHot;
	TdxSkinFormIconInfo* FIconPressed;
	TdxSkinFormNonClientAreaInfo* FNonClientAreaInfo;
	HIDESBASE TdxSkinFormIconInfo* __fastcall GetItem(int Index);
	
public:
	__fastcall virtual TdxSkinFormIconInfoList(TdxSkinFormNonClientAreaInfo* ANonClientInfo);
	HIDESBASE TdxSkinFormIconInfo* __fastcall Add(Dxskininfo::TdxSkinFormIcon AIcon);
	bool __fastcall CalculateStates(const System::Types::TPoint P);
	bool __fastcall Find(Dxskininfo::TdxSkinFormIcon AIcon, /* out */ TdxSkinFormIconInfo* &AInfo);
	TdxSkinFormIconInfo* __fastcall HitTest(const System::Types::TPoint P)/* overload */;
	bool __fastcall HitTest(const System::Types::TPoint P, /* out */ TdxSkinFormIconInfo* &AInfo)/* overload */;
	void __fastcall MouseDown(const System::Types::TPoint P);
	void __fastcall MouseUp(const System::Types::TPoint P, /* out */ TdxSkinFormIconInfo* &AIcon);
	void __fastcall Validate(const Dxskininfo::TdxSkinFormIcons AIcons);
	__property TdxSkinFormIconInfo* IconHot = {read=FIconHot};
	__property TdxSkinFormIconInfo* IconPressed = {read=FIconPressed};
	__property TdxSkinFormIconInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TdxSkinFormNonClientAreaInfo* NonClientAreaInfo = {read=FNonClientAreaInfo};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinFormIconInfoList(void) { }
	
};


class DELPHICLASS TdxSkinFormScrollBarPartViewInfo;
class DELPHICLASS TdxSkinFormScrollBarViewInfo;
class PASCALIMPLEMENTATION TdxSkinFormScrollBarPartViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	Cxlookandfeelpainters::TcxScrollBarPart FKind;
	TdxSkinFormScrollBarViewInfo* FOwner;
	Cxlookandfeelpainters::TcxButtonState FState;
	bool FVisible;
	
public:
	__fastcall virtual TdxSkinFormScrollBarPartViewInfo(TdxSkinFormScrollBarViewInfo* AOwner, Cxlookandfeelpainters::TcxScrollBarPart AKind);
	void __fastcall Calculate(int APos1, int APos2, int AState);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property Cxlookandfeelpainters::TcxScrollBarPart Kind = {read=FKind, nodefault};
	__property TdxSkinFormScrollBarViewInfo* Owner = {read=FOwner};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, nodefault};
	__property bool Visible = {read=FVisible, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinFormScrollBarPartViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxSkinFormScrollBarViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxSkinFormScrollBarsController* FController;
	tagSCROLLBARINFO FInfo;
	TdxSkinFormScrollBar FKind;
	System::StaticArray<TdxSkinFormScrollBarPartViewInfo*, 6> FParts;
	bool FVisible;
	TdxSkinFormScrollBarPartViewInfo* __fastcall GetPartViewInfo(Cxlookandfeelpainters::TcxScrollBarPart APart);
	
public:
	__fastcall TdxSkinFormScrollBarViewInfo(TdxSkinFormScrollBar AKind, TdxSkinFormScrollBarsController* AController);
	__fastcall virtual ~TdxSkinFormScrollBarViewInfo(void);
	void __fastcall CalculatePart(int APos1, int APos2, Cxlookandfeelpainters::TcxScrollBarPart APart);
	void __fastcall CalculateParts(void);
	bool __fastcall HitTest(const System::Types::TPoint P, /* out */ TdxSkinFormScrollBarPartViewInfo* &APart);
	__property System::Types::TRect Bounds = {read=FBounds};
	__property TdxSkinFormScrollBarsController* Controller = {read=FController};
	__property tagSCROLLBARINFO Info = {read=FInfo};
	__property TdxSkinFormScrollBar Kind = {read=FKind, nodefault};
	__property TdxSkinFormScrollBarPartViewInfo* PartViewInfo[Cxlookandfeelpainters::TcxScrollBarPart APart] = {read=GetPartViewInfo};
	__property bool Visible = {read=FVisible, nodefault};
};


class PASCALIMPLEMENTATION TdxSkinFormScrollBarsController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxSkinCustomFormController* FController;
	TdxSkinFormScrollBarPartViewInfo* FHotPart;
	bool FIsTracking;
	TdxSkinFormScrollBarPartViewInfo* FPressedPart;
	System::StaticArray<TdxSkinFormScrollBarViewInfo*, 2> FScrollBarViewInfo;
	bool FScrolling;
	Cxclasses::TcxTimer* FScrollTimer;
	System::Types::TRect FSizeGripBounds;
	tagSCROLLINFO FTrackingAreaInfo;
	System::Types::TPoint FTrackingLastPoint;
	float FTrackingScale;
	float FTrackPosition;
	bool __fastcall CanScrollPage(void);
	TdxSkinFormScrollBarViewInfo* __fastcall GetScrollBarViewInfo(TdxSkinFormScrollBar AScrollBar);
	bool __fastcall GetSizeGripVisible(void);
	TdxSkinFormScrollBar __fastcall GetTrackingScrollBarKind(void);
	TdxSkinFormNonClientAreaInfo* __fastcall GetViewInfo(void);
	void __fastcall SetHotPart(TdxSkinFormScrollBarPartViewInfo* AValue);
	void __fastcall SetPressedPart(TdxSkinFormScrollBarPartViewInfo* AValue);
	
protected:
	virtual void __fastcall Click(void);
	void __fastcall ScrollTimer(System::TObject* Sender);
	void __fastcall SendScrollMessage(NativeUInt AParam);
	void __fastcall StartScrollTimer(void);
	void __fastcall StopScrollTimer(void);
	void __fastcall Tracking(const System::Types::TPoint P);
	void __fastcall TrackingBegin(const System::Types::TPoint P);
	void __fastcall TrackingEnd(const System::Types::TPoint P);
	void __fastcall TrackingSetThumbPosition(int APosition);
	__property TdxSkinFormScrollBarPartViewInfo* HotPart = {read=FHotPart, write=SetHotPart};
	__property bool IsTracking = {read=FIsTracking, nodefault};
	__property TdxSkinFormScrollBarPartViewInfo* PressedPart = {read=FPressedPart, write=SetPressedPart};
	__property bool Scrolling = {read=FScrolling, nodefault};
	__property tagSCROLLINFO TrackingAreaInfo = {read=FTrackingAreaInfo};
	__property float TrackingScale = {read=FTrackingScale};
	__property TdxSkinFormScrollBar TrackingScrollBarKind = {read=GetTrackingScrollBarKind, nodefault};
	
public:
	__fastcall virtual TdxSkinFormScrollBarsController(TdxSkinCustomFormController* AController);
	__fastcall virtual ~TdxSkinFormScrollBarsController(void);
	TdxSkinFormScrollBarPartViewInfo* __fastcall HitTest(const System::Types::TPoint P)/* overload */;
	bool __fastcall HitTest(const System::Types::TPoint P, /* out */ TdxSkinFormScrollBarPartViewInfo* &AScrollBarPart)/* overload */;
	void __fastcall CalculateDrawRegion(HRGN ARegion);
	virtual void __fastcall CalculateScrollArea(void);
	void __fastcall MouseDown(const System::Types::TPoint P);
	void __fastcall MouseMove(const System::Types::TPoint P);
	void __fastcall MouseUp(const System::Types::TPoint P);
	__property TdxSkinCustomFormController* Controller = {read=FController};
	__property TdxSkinFormScrollBarViewInfo* ScrollBarViewInfo[TdxSkinFormScrollBar AScrollBar] = {read=GetScrollBarViewInfo};
	__property System::Types::TRect SizeGripBounds = {read=FSizeGripBounds};
	__property bool SizeGripVisible = {read=GetSizeGripVisible, nodefault};
	__property TdxSkinFormNonClientAreaInfo* ViewInfo = {read=GetViewInfo};
};


class PASCALIMPLEMENTATION TdxSkinFormNonClientAreaInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FClientOffset;
	System::Types::TRect FClientRect;
	TdxSkinCustomFormController* FController;
	int FExStyle;
	TdxSkinFormIconInfoList* FIconInfoList;
	int FSizeType;
	int FStyle;
	bool FSupressed;
	HMENU FSystemMenu;
	bool FThemeActive;
	bool FThemeActiveAssigned;
	System::Types::TRect FWindowRect;
	System::Types::TRect __fastcall GetBorderBounds(Cxgraphics::TcxBorder ASide);
	bool __fastcall GetButtonPressed(void);
	System::Types::TRect __fastcall GetCaptionBounds(void);
	System::Types::TRect __fastcall GetCaptionContentOffset(void);
	Dxskinscore::TdxSkinElement* __fastcall GetCaptionElement(void);
	System::Types::TSize __fastcall GetCaptionIconSize(Dxskininfo::TdxSkinFormIcon AIcon);
	System::Types::TRect __fastcall GetCaptionTextAreaOffset(void);
	System::Uitypes::TColor __fastcall GetCaptionTextColor(void);
	System::Types::TPoint __fastcall GetClientCursorPos(void);
	System::Types::TRect __fastcall GetClientRectOnClient(void);
	System::Types::TRect __fastcall GetContentRect(void);
	HWND __fastcall GetHandle(void);
	bool __fastcall GetHasBorder(void);
	bool __fastcall GetHasCaption(void);
	bool __fastcall GetHasCaptionTextShadow(void);
	bool __fastcall GetHasClientEdge(void);
	bool __fastcall GetHasMenu(void);
	bool __fastcall GetHasParent(void);
	bool __fastcall GetHasScrollsArea(void);
	bool __fastcall GetHasSizeConstraints(void);
	bool __fastcall GetIsAlphaBlendUsed(void);
	bool __fastcall GetIsChild(void);
	bool __fastcall GetIsDialog(void);
	bool __fastcall GetIsIconic(void);
	bool __fastcall GetIsSizeBox(void);
	bool __fastcall GetIsZoomed(void);
	bool __fastcall GetNeedCheckNonClientSize(void);
	tagNONCLIENTMETRICSW __fastcall GetNonClientMetrics(void);
	System::Types::TRect __fastcall GetScreenRect(void);
	TdxSkinFormScrollBarsController* __fastcall GetScrollBarsController(void);
	System::Types::TRect __fastcall GetSizeArea(Cxgraphics::TcxBorder ASide);
	System::Types::TRect __fastcall GetSizeCorners(TdxSkinFormCorner ACorner);
	int __fastcall GetSkinBorderWidth(Cxgraphics::TcxBorder ASide);
	float __fastcall GetSuppressFactor(void);
	System::Types::TRect __fastcall GetSystemBorderWidths(void);
	System::Types::TSize __fastcall GetSystemSizeFrame(void);
	bool __fastcall GetThemeActive(void);
	bool __fastcall GetToolWindow(void);
	System::Uitypes::TWindowState __fastcall GetWindowState(void);
	void __fastcall SetActive(bool AActive);
	void __fastcall SetSizeType(int AValue);
	void __fastcall SetUpdateRgn(HRGN ARgn);
	
protected:
	bool FActive;
	System::StaticArray<System::Types::TRect, 4> FBorderBounds;
	System::Types::TRect FBorderWidths;
	System::UnicodeString FCaption;
	Vcl::Graphics::TFont* FCaptionFont;
	System::Types::TRect FCaptionTextBounds;
	System::StaticArray<System::Uitypes::TColor, 2> FCaptionTextColor;
	System::Uitypes::TColor FCaptionTextShadowColor;
	System::Types::TRect FClientBounds;
	System::Types::TSize FClientEdgeSize;
	bool FHasMenu;
	bool FIsMDIChild;
	bool FIsMDIClient;
	int FMenuBarHeight;
	System::Types::TRect FMenuSeparatorBounds;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* FPainterInfo;
	System::Types::TSize FSizeFrame;
	HICON FSysMenuIcon;
	HRGN FUpdateRgn;
	System::Types::TRect FWindowBounds;
	virtual void __fastcall CalculateBordersInfo(void);
	virtual void __fastcall CalculateBorderWidths(void);
	virtual void __fastcall CalculateCaptionIconsInfo(void);
	virtual System::Types::TSize __fastcall CalculateCaptionButtonSize(const System::Types::TRect &ACaptionRect, Dxskinscore::TdxSkinElement* AElement);
	virtual int __fastcall CalculateCaptionContentHeight(void);
	virtual int __fastcall CalculateCaptionHeight(void);
	virtual int __fastcall CalculateCaptionIconsHeight(void);
	virtual int __fastcall CalculateCaptionTextHeight(void);
	void __fastcall CalculateFontInfo(void);
	virtual void __fastcall CalculateFrameSizes(void);
	virtual System::Types::TRect __fastcall CalculateMargins(void);
	virtual int __fastcall CalculateMenuBarHeight(void);
	virtual System::Types::TSize __fastcall CalculateMenuIconSize(bool AToolWindow);
	virtual void __fastcall CalculateScrollArea(void);
	virtual void __fastcall CalculateWindowInfo(void);
	void __fastcall CombineRectWithRegion(HRGN ADest, const System::Types::TRect &R);
	System::Types::TRect __fastcall GetBorderRect(Cxgraphics::TcxBorder ASide, const System::Types::TRect &ABounds, const System::Types::TRect &AWidths);
	virtual Dxskininfo::TdxSkinFormIcons __fastcall GetIcons(void);
	bool __fastcall GetIsMenuCommandEnabled(int AMenuCommandId);
	virtual HRGN __fastcall GetMDIClientDrawRgn(void);
	virtual HICON __fastcall GetSysMenuIcon(void);
	bool __fastcall IsNativeBorderWidth(bool ACheckZoomed = true);
	bool __fastcall UpdateCaptionIconStates(void);
	void __fastcall UpdateCaption(const System::UnicodeString ANewText);
	void __fastcall BuildSystemMenu(NativeUInt ASysMenu);
	void __fastcall DestroyStandardMenu(void);
	void __fastcall LoadStandardMenu(void);
	void __fastcall ModifySystemMenu(NativeUInt ASysMenu);
	void __fastcall ResetSystemMenu(void);
	
public:
	__fastcall virtual TdxSkinFormNonClientAreaInfo(TdxSkinCustomFormController* AController);
	__fastcall virtual ~TdxSkinFormNonClientAreaInfo(void);
	virtual void __fastcall Calculate(HRGN AUpdateRgn);
	System::Types::TPoint __fastcall ClientToScreen(const System::Types::TPoint P)/* overload */;
	System::Types::TRect __fastcall ClientToScreen(const System::Types::TRect &R)/* overload */;
	virtual HRGN __fastcall CreateDrawRgn(void);
	int __fastcall GetHitTest(System::Types::TPoint AHitPoint, int AHitTest = 0x0);
	System::Types::TPoint __fastcall ScreenToClient(const System::Types::TSmallPoint P)/* overload */;
	System::Types::TPoint __fastcall ScreenToClient(const System::Types::TPoint P)/* overload */;
	System::Types::TRect __fastcall ScreenToClient(const System::Types::TRect &R)/* overload */;
	void __fastcall UpdateFormCaption(void);
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property System::Types::TRect BorderBounds[Cxgraphics::TcxBorder ASide] = {read=GetBorderBounds};
	__property System::Types::TRect BorderWidths = {read=FBorderWidths};
	__property bool ButtonPressed = {read=GetButtonPressed, nodefault};
	__property System::UnicodeString Caption = {read=FCaption};
	__property Dxskinscore::TdxSkinElement* CaptionElement = {read=GetCaptionElement};
	__property Vcl::Graphics::TFont* CaptionFont = {read=FCaptionFont};
	__property System::Types::TRect CaptionTextBounds = {read=FCaptionTextBounds};
	__property System::Uitypes::TColor CaptionTextColor = {read=GetCaptionTextColor, nodefault};
	__property System::Uitypes::TColor CaptionTextShadowColor = {read=FCaptionTextShadowColor, write=FCaptionTextShadowColor, nodefault};
	__property System::Types::TRect ClientBounds = {read=FClientBounds};
	__property System::Types::TSize ClientEdgeSize = {read=FClientEdgeSize};
	__property int ClientOffset = {read=FClientOffset, nodefault};
	__property System::Types::TRect ClientRect = {read=FClientRect};
	__property System::Types::TPoint ClientCursorPos = {read=GetClientCursorPos};
	__property System::Types::TRect ClientRectOnClient = {read=GetClientRectOnClient};
	__property System::Types::TRect ContentRect = {read=GetContentRect};
	__property TdxSkinCustomFormController* Controller = {read=FController};
	__property int ExStyle = {read=FExStyle, nodefault};
	__property HWND Handle = {read=GetHandle};
	__property bool HasBorder = {read=GetHasBorder, nodefault};
	__property bool HasCaption = {read=GetHasCaption, nodefault};
	__property bool HasCaptionTextShadow = {read=GetHasCaptionTextShadow, nodefault};
	__property bool HasClientEdge = {read=GetHasClientEdge, nodefault};
	__property bool HasMenu = {read=GetHasMenu, nodefault};
	__property bool HasParent = {read=GetHasParent, nodefault};
	__property bool HasScrollsArea = {read=GetHasScrollsArea, nodefault};
	__property bool HasSizeConstraints = {read=GetHasSizeConstraints, nodefault};
	__property TdxSkinFormIconInfoList* IconInfoList = {read=FIconInfoList};
	__property Dxskininfo::TdxSkinFormIcons Icons = {read=GetIcons, nodefault};
	__property bool IsAlphaBlendUsed = {read=GetIsAlphaBlendUsed, nodefault};
	__property bool IsChild = {read=GetIsChild, nodefault};
	__property bool IsDialog = {read=GetIsDialog, nodefault};
	__property bool IsIconic = {read=GetIsIconic, nodefault};
	__property bool IsMDIChild = {read=FIsMDIChild, nodefault};
	__property bool IsMDIClient = {read=FIsMDIClient, nodefault};
	__property bool IsSizebox = {read=GetIsSizeBox, nodefault};
	__property bool IsZoomed = {read=GetIsZoomed, nodefault};
	__property int MenuBarHeight = {read=FMenuBarHeight, nodefault};
	__property System::Types::TRect MenuSeparatorBounds = {read=FMenuSeparatorBounds};
	__property bool NeedCheckNonClientSize = {read=GetNeedCheckNonClientSize, nodefault};
	__property tagNONCLIENTMETRICSW NonClientMetrics = {read=GetNonClientMetrics};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=FPainter};
	__property Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* PainterInfo = {read=FPainterInfo};
	__property System::Types::TRect ScreenRect = {read=GetScreenRect};
	__property TdxSkinFormScrollBarsController* ScrollBarsController = {read=GetScrollBarsController};
	__property System::Types::TRect SizeArea[Cxgraphics::TcxBorder ASide] = {read=GetSizeArea};
	__property System::Types::TRect SizeCorners[TdxSkinFormCorner ACorner] = {read=GetSizeCorners};
	__property System::Types::TSize SizeFrame = {read=FSizeFrame};
	__property int SizeType = {read=FSizeType, write=SetSizeType, nodefault};
	__property int SkinBorderWidth[Cxgraphics::TcxBorder ASide] = {read=GetSkinBorderWidth};
	__property int Style = {read=FStyle, nodefault};
	__property float SuppressFactor = {read=GetSuppressFactor};
	__property bool Supressed = {read=FSupressed, nodefault};
	__property HICON SysMenuIcon = {read=FSysMenuIcon};
	__property System::Types::TRect SystemBorderWidths = {read=GetSystemBorderWidths};
	__property HMENU SystemMenu = {read=FSystemMenu};
	__property System::Types::TSize SystemSizeFrame = {read=GetSystemSizeFrame};
	__property bool ThemeActive = {read=GetThemeActive, nodefault};
	__property bool ThemeActiveAssigned = {read=FThemeActiveAssigned, write=FThemeActiveAssigned, nodefault};
	__property bool ToolWindow = {read=GetToolWindow, nodefault};
	__property HRGN UpdateRgn = {read=FUpdateRgn, write=SetUpdateRgn};
	__property System::Types::TRect WindowBounds = {read=FWindowBounds};
	__property System::Types::TRect WindowRect = {read=FWindowRect};
	__property System::Uitypes::TWindowState WindowState = {read=GetWindowState, nodefault};
};


class PASCALIMPLEMENTATION TdxSkinFormPainter : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxskinscore::TdxSkinElementCache* FBackgroundCache;
	System::StaticArray<Dxskinscore::TdxSkinElementCache*, 4> FBordersCache;
	HDC FDC;
	System::StaticArray<Dxskinscore::TdxSkinElementCache*, 6> FIconsCache;
	bool FNeedRelease;
	TdxSkinFormNonClientAreaInfo* FViewInfo;
	bool __fastcall GetActive(void);
	Dxskinscore::TdxSkinElement* __fastcall GetFormContent(void);
	System::Uitypes::TColor __fastcall GetFormContentTextColor(void);
	Dxskinscore::TdxSkinElement* __fastcall GetIconElement(Dxskininfo::TdxSkinFormIcon AIcon);
	bool __fastcall GetIsBordersThin(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* __fastcall GetPainterInfo(void);
	TdxSkinFormScrollBarsController* __fastcall GetScrollBars(void);
	
protected:
	void __fastcall CreateCacheInfos(void);
	virtual void __fastcall DrawBackground(HDC DC, const System::Types::TRect &R);
	virtual void __fastcall DrawCaptionText(HDC DC, System::Types::TRect &R, const System::UnicodeString AText);
	virtual void __fastcall DrawScrollAreaElements(void);
	virtual void __fastcall DrawScrollBar(TdxSkinFormScrollBarViewInfo* AScrollBar);
	void __fastcall DrawSizeGrip(const System::Types::TRect &R);
	virtual void __fastcall DrawWindowCaption(HDC DC, const System::Types::TRect &R, Dxskinscore::TdxSkinElement* AElement);
	virtual void __fastcall DrawWindowCaptionBackground(HDC DC, const System::Types::TRect &R, Dxskinscore::TdxSkinElement* AElement);
	virtual void __fastcall DrawWindowCaptionText(HDC DC, System::Types::TRect &R);
	void __fastcall DrawWindowIcon(HDC DC, TdxSkinFormIconInfo* AIconInfo)/* overload */;
	virtual void __fastcall DrawWindowIcon(HDC DC, const System::Types::TRect &R, Dxskininfo::TdxSkinFormIcon AIcon, Dxskinscore::TdxSkinElement* AElement, Dxskinscore::TdxSkinElementState AElementState)/* overload */;
	void __fastcall FreeCacheInfos(void);
	void __fastcall InternalDrawBorder(HDC DC, const System::Types::TRect &R, Cxgraphics::TcxBorder ASide, bool AFillBackground);
	void __fastcall InternalDrawBorders(void);
	void __fastcall InternalDrawCaption(const System::Types::TRect &R, Dxskinscore::TdxSkinElement* AElement);
	void __fastcall InternalDrawThinBorders(void);
	
public:
	__fastcall virtual TdxSkinFormPainter(TdxSkinFormNonClientAreaInfo* AViewInfo);
	__fastcall virtual ~TdxSkinFormPainter(void);
	void __fastcall BeginPaint(HDC ADestDC = (HDC)(0ULL));
	virtual void __fastcall DrawClientOffsetArea(void);
	virtual void __fastcall DrawMDIClientEdgeArea(void);
	virtual void __fastcall DrawMenuSeparator(void);
	virtual void __fastcall DrawWindowBackground(void);
	virtual void __fastcall DrawWindowBorder(void);
	virtual void __fastcall DrawWindowScrollArea(void);
	void __fastcall EndPaint(void);
	void __fastcall FlushCache(void);
	bool __fastcall IsRectVisible(const System::Types::TRect &R);
	__property bool Active = {read=GetActive, nodefault};
	__property Dxskinscore::TdxSkinElement* FormContent = {read=GetFormContent};
	__property System::Uitypes::TColor FormContentTextColor = {read=GetFormContentTextColor, nodefault};
	__property Dxskinscore::TdxSkinElement* IconElements[Dxskininfo::TdxSkinFormIcon AIcon] = {read=GetIconElement};
	__property bool IsBordersThin = {read=GetIsBordersThin, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter = {read=GetPainter};
	__property Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainterInfo* PainterInfo = {read=GetPainterInfo};
	__property TdxSkinFormScrollBarsController* ScrollBars = {read=GetScrollBars};
	__property TdxSkinFormNonClientAreaInfo* ViewInfo = {read=FViewInfo};
};


class DELPHICLASS TdxSkinFormController;
class PASCALIMPLEMENTATION TdxSkinFormController : public TdxSkinCustomFormController
{
	typedef TdxSkinCustomFormController inherited;
	
protected:
	virtual bool __fastcall CanFinalizeEngine(void);
	virtual Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* __fastcall FindLookAndFeelPainter(void);
	virtual TdxSkinWinController* __fastcall FindMasterController(void);
	virtual bool __fastcall GetCanUseSkin(void);
public:
	/* TdxSkinCustomFormController.Create */ inline __fastcall virtual TdxSkinFormController(HWND AHandle) : TdxSkinCustomFormController(AHandle) { }
	/* TdxSkinCustomFormController.CreateEx */ inline __fastcall TdxSkinFormController(TdxSkinForm* ASkinForm) : TdxSkinCustomFormController(ASkinForm) { }
	/* TdxSkinCustomFormController.Destroy */ inline __fastcall virtual ~TdxSkinFormController(void) { }
	
};


class DELPHICLASS TdxSkinFormMDIClientController;
class PASCALIMPLEMENTATION TdxSkinFormMDIClientController : public TdxSkinCustomFormController
{
	typedef TdxSkinCustomFormController inherited;
	
protected:
	virtual TdxSkinWinController* __fastcall FindMasterController(void);
	virtual bool __fastcall GetCanUseSkin(void);
	virtual bool __fastcall GetUseSkin(void);
public:
	/* TdxSkinCustomFormController.Create */ inline __fastcall virtual TdxSkinFormMDIClientController(HWND AHandle) : TdxSkinCustomFormController(AHandle) { }
	/* TdxSkinCustomFormController.CreateEx */ inline __fastcall TdxSkinFormMDIClientController(TdxSkinForm* ASkinForm) : TdxSkinCustomFormController(ASkinForm) { }
	/* TdxSkinCustomFormController.Destroy */ inline __fastcall virtual ~TdxSkinFormMDIClientController(void) { }
	
};


class PASCALIMPLEMENTATION TdxSkinForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	TdxSkinFormController* FController;
	
protected:
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	void __fastcall DefaultWndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall DestroyWindowHandle(void);
	void __fastcall FinalizeController(void);
	void __fastcall InitializeController(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property TdxSkinFormController* Controller = {read=FController};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxSkinForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxSkinForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxSkinForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxSkinForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class DELPHICLASS TdxSkinFormHelper;
class PASCALIMPLEMENTATION TdxSkinFormHelper : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod bool __fastcall CanUseSkin(Vcl::Forms::TCustomForm* AForm);
	__classmethod Vcl::Forms::TCustomForm* __fastcall GetActiveMDIChild(HWND AHandle);
	__classmethod int __fastcall GetClientOffset(HWND AHandle);
	__classmethod Vcl::Forms::TCustomForm* __fastcall GetForm(HWND AHandle);
	__classmethod Vcl::Forms::TCustomForm* __fastcall GetZoomedMDIChild(HWND AHandle);
	__classmethod bool __fastcall HasClientEdge(HWND AHandle);
	__classmethod bool __fastcall IsAlphaBlendUsed(HWND AHandle);
public:
	/* TObject.Create */ inline __fastcall TdxSkinFormHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinFormHelper(void) { }
	
};


class DELPHICLASS TdxSkinFrameController;
class PASCALIMPLEMENTATION TdxSkinFrameController : public TdxSkinCustomFormController
{
	typedef TdxSkinCustomFormController inherited;
	
private:
	bool __fastcall GetIsTransparent(void);
	
protected:
	virtual void __fastcall DrawWindowBackground(HDC DC);
	virtual void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	__property bool IsTransparent = {read=GetIsTransparent, nodefault};
public:
	/* TdxSkinCustomFormController.Create */ inline __fastcall virtual TdxSkinFrameController(HWND AHandle) : TdxSkinCustomFormController(AHandle) { }
	/* TdxSkinCustomFormController.CreateEx */ inline __fastcall TdxSkinFrameController(TdxSkinForm* ASkinForm) : TdxSkinCustomFormController(ASkinForm) { }
	/* TdxSkinCustomFormController.Destroy */ inline __fastcall virtual ~TdxSkinFrameController(void) { }
	
};


class DELPHICLASS TdxSkinCustomControlViewInfo;
class PASCALIMPLEMENTATION TdxSkinCustomControlViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxSkinWinController* FController;
	int __fastcall GetClientHeight(void);
	System::Types::TRect __fastcall GetClientRect(void);
	int __fastcall GetClientWidth(void);
	bool __fastcall GetIsEnabled(void);
	bool __fastcall GetIsFocused(void);
	bool __fastcall GetIsMouseAtControl(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	
public:
	__fastcall virtual TdxSkinCustomControlViewInfo(TdxSkinWinController* AController);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	__property int ClientHeight = {read=GetClientHeight, nodefault};
	__property System::Types::TRect ClientRect = {read=GetClientRect};
	__property int ClientWidth = {read=GetClientWidth, nodefault};
	__property TdxSkinWinController* Controller = {read=FController};
	__property bool IsEnabled = {read=GetIsEnabled, nodefault};
	__property bool IsFocused = {read=GetIsFocused, nodefault};
	__property bool IsMouseAtControl = {read=GetIsMouseAtControl, nodefault};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinCustomControlViewInfo(void) { }
	
};


class DELPHICLASS TdxSkinCustomControlController;
class PASCALIMPLEMENTATION TdxSkinCustomControlController : public TdxSkinWinController
{
	typedef TdxSkinWinController inherited;
	
private:
	bool FDoubleBuffered;
	TdxSkinCustomControlViewInfo* FViewInfo;
	void __fastcall DoDraw(HDC DC);
	
protected:
	virtual TdxSkinCustomControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &AMessage);
	virtual bool __fastcall WMEraseBk(Winapi::Messages::TWMEraseBkgnd &AMessage);
	virtual bool __fastcall WMPaint(Winapi::Messages::TWMPaint &AMessage);
	
public:
	__fastcall virtual TdxSkinCustomControlController(HWND AHandle);
	__fastcall virtual ~TdxSkinCustomControlController(void);
	virtual void __fastcall Draw(HDC DC = (HDC)(0ULL));
	__property bool DoubleBuffered = {read=FDoubleBuffered, write=FDoubleBuffered, nodefault};
	__property TdxSkinCustomControlViewInfo* ViewInfo = {read=FViewInfo};
};


class DELPHICLASS TdxSkinCustonButtonViewInfo;
class PASCALIMPLEMENTATION TdxSkinCustonButtonViewInfo : public TdxSkinCustomControlViewInfo
{
	typedef TdxSkinCustomControlViewInfo inherited;
	
private:
	Cxlookandfeelpainters::TcxButtonState FState;
	System::UnicodeString __fastcall GetCaption(void);
	bool __fastcall GetIsPressed(void);
	bool __fastcall GetWordWrap(void);
	void __fastcall SetState(Cxlookandfeelpainters::TcxButtonState AState);
	
protected:
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall CalculateButtonState(void);
	void __fastcall UpdateButtonState(void);
	
public:
	virtual void __fastcall AfterConstruction(void);
	__property System::UnicodeString Caption = {read=GetCaption};
	__property bool IsPressed = {read=GetIsPressed, nodefault};
	__property Cxlookandfeelpainters::TcxButtonState State = {read=FState, write=SetState, nodefault};
	__property bool WordWrap = {read=GetWordWrap, nodefault};
public:
	/* TdxSkinCustomControlViewInfo.Create */ inline __fastcall virtual TdxSkinCustonButtonViewInfo(TdxSkinWinController* AController) : TdxSkinCustomControlViewInfo(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinCustonButtonViewInfo(void) { }
	
};


class DELPHICLASS TdxSkinCustonButtonController;
class PASCALIMPLEMENTATION TdxSkinCustonButtonController : public TdxSkinCustomControlController
{
	typedef TdxSkinCustomControlController inherited;
	
private:
	TdxSkinCustonButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall MouseLeave(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &AMessage);
	
public:
	__fastcall virtual TdxSkinCustonButtonController(HWND AHandle);
	__property TdxSkinCustonButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxSkinCustomControlController.Destroy */ inline __fastcall virtual ~TdxSkinCustonButtonController(void) { }
	
};


class DELPHICLASS TdxSkinButtonViewInfo;
class PASCALIMPLEMENTATION TdxSkinButtonViewInfo : public TdxSkinCustonButtonViewInfo
{
	typedef TdxSkinCustonButtonViewInfo inherited;
	
private:
	bool FActive;
	bool __fastcall GetIsDefault(void);
	void __fastcall SetActive(bool AActive);
	
protected:
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall CalculateButtonState(void);
	void __fastcall CMFocusChanged(Vcl::Controls::TCMFocusChanged &Message);
	
public:
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property bool IsDefault = {read=GetIsDefault, nodefault};
public:
	/* TdxSkinCustomControlViewInfo.Create */ inline __fastcall virtual TdxSkinButtonViewInfo(TdxSkinWinController* AController) : TdxSkinCustonButtonViewInfo(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinButtonViewInfo(void) { }
	
};


class DELPHICLASS TdxSkinButtonController;
class PASCALIMPLEMENTATION TdxSkinButtonController : public TdxSkinCustonButtonController
{
	typedef TdxSkinCustonButtonController inherited;
	
protected:
	virtual TdxSkinCustomControlViewInfo* __fastcall CreateViewInfo(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &AMessage);
public:
	/* TdxSkinCustonButtonController.Create */ inline __fastcall virtual TdxSkinButtonController(HWND AHandle) : TdxSkinCustonButtonController(AHandle) { }
	
public:
	/* TdxSkinCustomControlController.Destroy */ inline __fastcall virtual ~TdxSkinButtonController(void) { }
	
};


class DELPHICLASS TdxSkinPanelViewInfo;
class PASCALIMPLEMENTATION TdxSkinPanelViewInfo : public TdxSkinCustomControlViewInfo
{
	typedef TdxSkinCustomControlViewInfo inherited;
	
public:
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TdxSkinCustomControlViewInfo.Create */ inline __fastcall virtual TdxSkinPanelViewInfo(TdxSkinWinController* AController) : TdxSkinCustomControlViewInfo(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxSkinPanelViewInfo(void) { }
	
};


class DELPHICLASS TdxSkinPanelController;
class PASCALIMPLEMENTATION TdxSkinPanelController : public TdxSkinCustomControlController
{
	typedef TdxSkinCustomControlController inherited;
	
private:
	bool FPainting;
	
protected:
	virtual TdxSkinCustomControlViewInfo* __fastcall CreateViewInfo(void);
	virtual bool __fastcall WMEraseBk(Winapi::Messages::TWMEraseBkgnd &AMessage);
	virtual bool __fastcall WMPaint(Winapi::Messages::TWMPaint &AMessage);
	virtual bool __fastcall WMPrintClient(Winapi::Messages::TWMPrint &AMessage);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &AMessage);
public:
	/* TdxSkinCustomControlController.Create */ inline __fastcall virtual TdxSkinPanelController(HWND AHandle) : TdxSkinCustomControlController(AHandle) { }
	/* TdxSkinCustomControlController.Destroy */ inline __fastcall virtual ~TdxSkinPanelController(void) { }
	
};


typedef void __fastcall (__closure *TdxSkinControlEvent)(System::TObject* Sender, Vcl::Controls::TWinControl* AControl, bool &UseSkin);

typedef void __fastcall (__closure *TdxSkinFormEvent)(System::TObject* Sender, Vcl::Forms::TCustomForm* AForm, System::UnicodeString &ASkinName, bool &UseSkin);

typedef void __fastcall (__closure *TdxSkinPopupSysMenuEvent)(System::TObject* Sender, Vcl::Forms::TCustomForm* AForm, HMENU ASysMenu);

typedef TdxSkinWinControllerClass __fastcall (*TdxSkinGetControllerClassForWindowProc)(HWND AWnd);

class DELPHICLASS TdxSkinController;
class PASCALIMPLEMENTATION TdxSkinController : public Cxlookandfeels::TcxLookAndFeelController
{
	typedef Cxlookandfeels::TcxLookAndFeelController inherited;
	
private:
	TdxSkinPopupSysMenuEvent FOnPopupSysMenu;
	TdxSkinControlEvent FOnSkinControl;
	TdxSkinFormEvent FOnSkinForm;
	Dxskinscore::TdxSkinImageSet __fastcall GetUseImageSet(void);
	bool __fastcall GetUseSkins(void);
	void __fastcall SetUseImageSet(Dxskinscore::TdxSkinImageSet AValue);
	void __fastcall SetUseSkins(bool Value);
	
protected:
	void __fastcall FullRefresh(void);
	virtual void __fastcall DoPopupSystemMenu(Vcl::Forms::TCustomForm* AForm, HMENU ASysMenu);
	virtual void __fastcall DoSkinControl(Vcl::Controls::TWinControl* AControl, bool &AUseSkin);
	virtual void __fastcall DoSkinForm(Vcl::Forms::TCustomForm* AForm, System::UnicodeString &ASkinName, bool &AUseSkin);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall MasterLookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	virtual void __fastcall MasterLookAndFeelDestroying(Cxlookandfeels::TcxLookAndFeel* Sender);
	
public:
	__fastcall virtual TdxSkinController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxSkinController(void);
	void __fastcall Refresh(Vcl::Controls::TWinControl* AControl = (Vcl::Controls::TWinControl*)(0x0));
	__classmethod bool __fastcall GetFormSkin(Vcl::Forms::TCustomForm* AForm, System::UnicodeString &ASkinName);
	
__published:
	__property Kind = {default=2};
	__property NativeStyle = {default=1};
	__property SkinName = {default=0};
	__property Dxskinscore::TdxSkinImageSet UseImageSet = {read=GetUseImageSet, write=SetUseImageSet, default=0};
	__property bool UseSkins = {read=GetUseSkins, write=SetUseSkins, default=1};
	__property TdxSkinPopupSysMenuEvent OnPopupSysMenu = {read=FOnPopupSysMenu, write=FOnPopupSysMenu};
	__property TdxSkinControlEvent OnSkinControl = {read=FOnSkinControl, write=FOnSkinControl};
	__property TdxSkinFormEvent OnSkinForm = {read=FOnSkinForm, write=FOnSkinForm};
};


class DELPHICLASS TdxSkinControllersList;
class PASCALIMPLEMENTATION TdxSkinControllersList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TdxSkinController* operator[](int Index) { return Items[Index]; }
	
private:
	System::UnicodeString __fastcall GetDefaultSkinName(void);
	bool __fastcall GetDefaultUseSkins(void);
	TdxSkinController* __fastcall GetItem(int Index);
	
public:
	bool __fastcall CanSkinControl(Vcl::Controls::TWinControl* AControl);
	Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* __fastcall CanSkinForm(Vcl::Forms::TCustomForm* AForm);
	bool __fastcall GetSkinPainter(const System::UnicodeString AName, /* out */ Dxskinslookandfeelpainter::TdxSkinLookAndFeelPainter* &APainter);
	__property TdxSkinController* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxSkinControllersList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxSkinControllersList(void) : System::Classes::TList() { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxSkinFormTextOffset = System::Int8(0x5);
static const System::Int8 dxSkinIconSpacing = System::Int8(0x2);
extern PACKAGE bool IsDesigning;
extern PACKAGE TdxSkinControllersList* dxSkinControllersList;
extern PACKAGE TdxSkinGetControllerClassForWindowProc dxSkinGetControllerClassForWindowProc;
extern PACKAGE TdxSkinWinControllerClass __fastcall dxSkinGetControllerClassForWindow(HWND AWnd);
}	/* namespace Dxskinsform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSKINSFORM)
using namespace Dxskinsform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxskinsformHPP
