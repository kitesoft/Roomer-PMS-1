// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonFormCaptionHelper.pas' rev: 24.00 (Win32)

#ifndef DxribbonformcaptionhelperHPP
#define DxribbonformcaptionhelperHPP

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
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonformcaptionhelper
{
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<System::Types::TRect, 6> TdxRibbonBorderIconBounds;

enum TdxRibbonFormRegion : unsigned char { rfrWindow, rfrClient, rfrNCHitTest };

enum TdxRibbonTrackedBorderIcon : unsigned char { tbiNone, tbiSystemMenu, tbiMinimize, tbiMaximize, tbiHelp, tbiAutoHide, tbiAutoHideModeShowUI };

__interface IdxRibbonFormNonClientPart;
typedef System::DelphiInterface<IdxRibbonFormNonClientPart> _di_IdxRibbonFormNonClientPart;
__interface  INTERFACE_UUID("{9266F6BD-0C9A-402A-A49F-D6405A2DDAF0}") IdxRibbonFormNonClientPart  : public System::IInterface 
{
	
};

__interface IdxRibbonFormNonClientHelper;
typedef System::DelphiInterface<IdxRibbonFormNonClientHelper> _di_IdxRibbonFormNonClientHelper;
__interface  INTERFACE_UUID("{2F024903-3552-4859-961F-F778ED5E1DB6}") IdxRibbonFormNonClientHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall AdjustRibbonFormBorderIconSize(Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, bool AIsToolWindow, System::Types::TSize &ASize) = 0 ;
	virtual void __fastcall DoHelpButtonClick(void) = 0 ;
	virtual void __fastcall DrawRibbonFormBackground(HDC DC, const System::Types::TRect &ARect) = 0 ;
	virtual void __fastcall DrawRibbonFormBorders(Cxgraphics::TcxCanvas* ACanvas, const Dxribbonskins::TdxRibbonFormData &AData, const System::Types::TRect &ABordersWidth) = 0 ;
	virtual void __fastcall DrawRibbonFormBorderIcon(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Dxribbonskins::TdxRibbonBorderDrawIcon AIcon, Dxribbonskins::TdxRibbonBorderIconState AState) = 0 ;
	virtual void __fastcall DrawRibbonFormCaption(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::UnicodeString ACaption, const Dxribbonskins::TdxRibbonFormData &AData) = 0 ;
	virtual void __fastcall GetApplicationMenuTabOrderList(System::Classes::TList* List) = 0 ;
	virtual Dxribbonskins::TdxRibbonApplicationMenuState __fastcall GetApplicationMenuState(void) = 0 ;
	virtual Dxbar::TdxBarManager* __fastcall GetBarManager(void) = 0 ;
	virtual Dxbar::TdxBarPainter* __fastcall GetBarPainter(void) = 0 ;
	virtual int __fastcall GetRibbonFormCaptionAreaExtention(void) = 0 ;
	virtual int __fastcall GetRibbonFormCaptionHeight(void) = 0 ;
	virtual int __fastcall GetRibbonFormCaptionHeightForHiddenRibbon(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetRibbonFormColor(void) = 0 ;
	virtual HRGN __fastcall GetRibbonFormExtendedCaptionAreaRegion(void) = 0 ;
	virtual int __fastcall GetRibbonLoadedHeight(void) = 0 ;
	virtual HRGN __fastcall GetRibbonNonClientAreaObjectsRegion(void) = 0 ;
	virtual System::Types::TRect __fastcall GetRibbonQATNonClientAreaBounds(void) = 0 ;
	virtual Dxribbonskins::TdxRibbonStyle __fastcall GetRibbonStyle(void) = 0 ;
	virtual System::_di_IInterface __fastcall GetStatusBarInterface(void) = 0 ;
	virtual Vcl::Controls::TCaption __fastcall GetTaskbarCaption(void) = 0 ;
	virtual System::Types::TRect __fastcall GetWindowBordersWidth(void) = 0 ;
	virtual bool __fastcall HasExternalRibbonFormShadow(void) = 0 ;
	virtual bool __fastcall HasHelpButton(void) = 0 ;
	virtual bool __fastcall HasStatusBar(void) = 0 ;
	virtual bool __fastcall UseRoundedWindowCorners(void) = 0 ;
	virtual void __fastcall UpdateNonClientArea(void) = 0 ;
};

__interface IdxFormKeyPreviewListener;
typedef System::DelphiInterface<IdxFormKeyPreviewListener> _di_IdxFormKeyPreviewListener;
__interface  INTERFACE_UUID("{7192BF84-F80D-4DB0-A53B-06F6703B1A97}") IdxFormKeyPreviewListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall FormKeyDown(System::Word &Key, System::Classes::TShiftState Shift) = 0 ;
};

class DELPHICLASS TdxRibbonFormCaptionHelper;
class PASCALIMPLEMENTATION TdxRibbonFormCaptionHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	Cxgraphics::TcxBitmap32* FBitmap;
	Dxribbonskins::TdxRibbonBorderIcons FBorderIcons;
	System::Types::TRect FBorderIconsArea;
	System::Types::TRect FFormCaptionDrawBounds;
	System::StaticArray<HRGN, 3> FFormCaptionRegions;
	Dxribbonskins::TdxRibbonFormData FFormData;
	TdxRibbonTrackedBorderIcon FHotBorderIcon;
	bool FIsClientDrawing;
	Cxclasses::TcxTimer* FMouseTimer;
	System::Classes::TWndMethod FOldWndProc;
	Cxcontrols::TcxControl* FOwner;
	TdxRibbonTrackedBorderIcon FPressedBorderIcon;
	_di_IdxRibbonFormNonClientHelper FRibbonHelper;
	System::Types::TRect FSysMenuBounds;
	bool FWasCapture;
	void __fastcall CalculateFormCaption(void);
	bool __fastcall CanProcessFormCaptionHitTest(int X, int Y);
	void __fastcall DestroyCaptionRegions(void);
	void __fastcall DrawBorderIcons(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall ExcludeCaptionRgn(HDC DC);
	Dxribbonskins::TdxRibbonApplicationMenuState __fastcall GetApplicationMenuState(void);
	Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	Dxribbonskins::TdxRibbonBorderIcon __fastcall GetBorderIconAtPoint(const System::Types::TPoint &P);
	Dxribbonskins::TdxRibbonBorderIconState __fastcall GetBorderIconState(Dxribbonskins::TdxRibbonBorderIcon AIcon);
	System::Types::TRect __fastcall GetClientCaptionBounds(void);
	HRGN __fastcall GetClientCaptionRegion(void);
	System::Types::TRect __fastcall GetClientRect(void);
	Dxribbonskins::TdxRibbonBorderDrawIcon __fastcall GetDrawIconFromBorderIcon(Dxribbonskins::TdxRibbonBorderIcon AIcon);
	HRGN __fastcall GetExtentedCaptionAreaRegion(void);
	Vcl::Forms::TCustomForm* __fastcall GetForm(void);
	System::Types::TRect __fastcall GetFormCaptionDrawBounds(void);
	HRGN __fastcall GetFormCaptionRegionsForDC(HDC DC, TdxRibbonFormRegion ARegionKind);
	NativeUInt __fastcall GetHandle(void);
	bool __fastcall GetIsValid(void);
	HRGN __fastcall GetNCHitTestRegion(void);
	HRGN __fastcall GetNonClientAreaObjectsRegion(void);
	bool __fastcall HasSysMenu(void);
	bool __fastcall IsBorderIconMouseEvent(const System::Types::TPoint &P, /* out */ System::Types::TPoint &CP, bool ACheckComposition = true);
	void __fastcall MouseTimerHandler(System::TObject* Sender);
	void __fastcall RepaintBorderIcons(void);
	void __fastcall SetHotBorderIcon(TdxRibbonTrackedBorderIcon AValue);
	void __fastcall SetPressedBorderIcon(TdxRibbonTrackedBorderIcon AValue);
	void __fastcall StartMouseTimer(void);
	void __fastcall StopMouseTimer(void);
	void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	void __fastcall WMShowWindow(Winapi::Messages::TMessage &Message);
	
protected:
	TdxRibbonBorderIconBounds FBorderIconBounds;
	System::Types::TRect FSysMenuIconBounds;
	System::Types::TRect FTextBounds;
	void __fastcall BufferedDrawCaption(Cxgraphics::TcxCanvas* ADestCanvas, const Vcl::Controls::TCaption ACaption);
	System::Types::TSize __fastcall CalculateBorderIconSize(Dxribbonskins::TdxRibbonBorderIcon ABorderIcon);
	virtual void __fastcall CalculateBorderIcons(void);
	virtual void __fastcall CalculateBorderIconsForCustomSkinning(void);
	virtual void __fastcall CalculateSysMenuIconBounds(void);
	virtual void __fastcall CalculateTextBounds(void);
	bool __fastcall CanCalculate(void);
	void __fastcall DrawWindowBorderIcon(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, Dxribbonskins::TdxRibbonBorderIcon AIcon, Dxribbonskins::TdxRibbonBorderIconState AState);
	virtual System::Types::TRect __fastcall GetWindowCaptionBounds(void);
	virtual HRGN __fastcall GetWindowCaptionRegion(void);
	virtual void __fastcall InitializeHelpers(void);
	void __fastcall OriginalWndProc(void *Message);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	Dxbar::TdxBarCustomHintViewInfo* __fastcall CreateHintViewInfo(const System::UnicodeString AHintText, const System::UnicodeString AShortCut);
	bool __fastcall DoHint(bool &ANeedDeactivate, /* out */ System::UnicodeString &AHintText, /* out */ System::UnicodeString &AShortCut);
	bool __fastcall GetEnabled(void);
	System::Types::TPoint __fastcall GetHintPosition(const System::Types::TPoint &ACursorPos, int AHeight);
	__property Dxbar::TdxBarManager* BarManager = {read=GetBarManager};
	__property Vcl::Forms::TCustomForm* Form = {read=GetForm};
	__property NativeUInt Handle = {read=GetHandle, nodefault};
	__property TdxRibbonTrackedBorderIcon HotBorderIcon = {read=FHotBorderIcon, write=SetHotBorderIcon, nodefault};
	__property TdxRibbonTrackedBorderIcon PressedBorderIcon = {read=FPressedBorderIcon, write=SetPressedBorderIcon, nodefault};
	__property bool Valid = {read=GetIsValid, nodefault};
	
public:
	__fastcall TdxRibbonFormCaptionHelper(Cxcontrols::TcxControl* AOwner);
	__fastcall virtual ~TdxRibbonFormCaptionHelper(void);
	void __fastcall Calculate(void);
	virtual void __fastcall CalculateWindowCaptionHitTest(Winapi::Messages::TWMNCHitTest &Message);
	void __fastcall CancelMode(void);
	void __fastcall CheckWindowStates(const Dxribbonskins::TdxRibbonFormData &AFormData);
	void __fastcall DrawWindowBorders(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall DrawWindowCaption(Cxgraphics::TcxCanvas* ACanvas, const Vcl::Controls::TCaption ACaption);
	void __fastcall DrawRibbonFormBackground(HDC DC, const System::Types::TRect &ARect);
	void __fastcall GetDesignInfo(/* out */ int &ALoadedHeight, /* out */ int &ACurrentHeight);
	void __fastcall GetApplicationMenuTabOrderList(System::Classes::TList* AList);
	virtual int __fastcall GetCaptionAreaExtention(void);
	virtual Vcl::Controls::TCaption __fastcall GetTaskbarCaption(void);
	virtual System::Types::TRect __fastcall GetWindowBordersWidth(void);
	virtual int __fastcall GetWindowCaptionHeight(void);
	virtual int __fastcall GetWindowCaptionHeightForHiddenRibbon(void);
	System::Uitypes::TColor __fastcall GetWindowColor(void);
	virtual HRGN __fastcall GetWindowRegion(void);
	virtual System::Types::TRect __fastcall GetWindowSystemMenuBounds(void);
	virtual bool __fastcall IsInCaptionArea(const System::Types::TPoint &P);
	virtual bool __fastcall IsRibbonHelpButtonPlacedOnCaption(void);
	virtual bool __fastcall MouseDown(const System::Types::TPoint &P, System::Uitypes::TMouseButton AButton);
	virtual bool __fastcall MouseUp(const System::Types::TPoint &P, System::Uitypes::TMouseButton AButton);
	void __fastcall UpdateCaptionArea(Cxgraphics::TcxCanvas* ACanvas = (Cxgraphics::TcxCanvas*)(0x0));
	void __fastcall UpdateNonClientArea(void);
	void __fastcall UpdateWindowBorderIcons(const Dxribbonskins::TdxRibbonBorderIcons AIcons);
	bool __fastcall UseRoundedWindowCorners(void);
	__property Dxribbonskins::TdxRibbonApplicationMenuState ApplicationMenuState = {read=GetApplicationMenuState, nodefault};
	__property System::Types::TRect BorderIconsArea = {read=FBorderIconsArea};
	__property Cxcontrols::TcxControl* Control = {read=FOwner};
	__property System::Types::TRect FormCaptionDrawBounds = {read=FFormCaptionDrawBounds};
	__property Dxribbonskins::TdxRibbonFormData FormData = {read=FFormData};
	__property _di_IdxRibbonFormNonClientHelper RibbonHelper = {read=FRibbonHelper};
	__property System::Types::TRect SysMenuIconBounds = {read=FSysMenuIconBounds};
	__property System::Types::TRect TextBounds = {read=FTextBounds};
private:
	void *__IdxBarHintKeeper;	/* Dxbar::IdxBarHintKeeper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {587A00C4-A7E0-4032-98E5-4DB8F3918ADF}
	operator Dxbar::_di_IdxBarHintKeeper()
	{
		Dxbar::_di_IdxBarHintKeeper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarHintKeeper*(void) { return (Dxbar::IdxBarHintKeeper*)&__IdxBarHintKeeper; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxCombineRectRegion(HRGN &ARegion, const System::Types::TRect &R, int ACombineMode)/* overload */;
extern PACKAGE void __fastcall dxCombineRectRegion(HRGN &ARegion, int X0, int Y0, int X1, int Y1, int ACombineMode)/* overload */;
extern PACKAGE HRGN __fastcall GetClipRegion(HDC DC);
extern PACKAGE System::Types::TRect __fastcall GetDefaultWindowNCSize(NativeUInt H);
extern PACKAGE System::Types::TRect __fastcall GetDefaultWindowBordersWidth(NativeUInt H);
extern PACKAGE bool __fastcall IsShowMinimizedOnDesktop(NativeUInt H);
extern PACKAGE void __fastcall RecalculateNonClient(Vcl::Controls::TWinControl* AControl);
extern PACKAGE bool __fastcall UseAeroNCPaint(const Dxribbonskins::TdxRibbonFormData &AData);
extern PACKAGE void __fastcall WinControlFullInvalidate(Vcl::Controls::TWinControl* AControl, bool AIncludeChildren = false, bool AForceUpdate = false);
}	/* namespace Dxribbonformcaptionhelper */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONFORMCAPTIONHELPER)
using namespace Dxribbonformcaptionhelper;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonformcaptionhelperHPP
