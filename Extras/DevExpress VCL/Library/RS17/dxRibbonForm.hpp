// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonForm.pas' rev: 24.00 (Win32)

#ifndef DxribbonformHPP
#define DxribbonformHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxShadowWindow.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxRibbonFormCaptionHelper.hpp>	// Pascal unit
#include <cxDWMApi.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonform
{
//-- type declarations -------------------------------------------------------
__interface IdxRibbonFormClient;
typedef System::DelphiInterface<IdxRibbonFormClient> _di_IdxRibbonFormClient;
__interface  INTERFACE_UUID("{C409C9EF-4458-4133-AAA1-DCDCBFBC0B83}") IdxRibbonFormClient  : public System::IInterface 
{
	
public:
	virtual void __fastcall RibbonFormCaptionChanged(void) = 0 ;
	virtual void __fastcall RibbonFormResized(void) = 0 ;
};

__interface IdxRibbonFormControllerHelper;
typedef System::DelphiInterface<IdxRibbonFormControllerHelper> _di_IdxRibbonFormControllerHelper;
__interface  INTERFACE_UUID("{DEC82702-29ED-413B-852D-C2AA884FD99A}") IdxRibbonFormControllerHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall DoAfterApplicationMenuPopup(void) = 0 ;
	virtual void __fastcall DoBeforeApplicationMenuPopup(void) = 0 ;
	virtual void __fastcall DoBeforeShowKeyTips(void) = 0 ;
};

class DELPHICLASS TdxRibbonFormShadowWindow;
class DELPHICLASS TdxCustomRibbonForm;
class PASCALIMPLEMENTATION TdxRibbonFormShadowWindow : public Dxshadowwindow::TdxShadowWindow
{
	typedef Dxshadowwindow::TdxShadowWindow inherited;
	
private:
	TdxCustomRibbonForm* __fastcall GetOwnerWindow(void);
	
protected:
	virtual bool __fastcall CalculateVisibility(void);
	
public:
	__property TdxCustomRibbonForm* OwnerWindow = {read=GetOwnerWindow};
public:
	/* TdxShadowWindow.Create */ inline __fastcall virtual TdxRibbonFormShadowWindow(Vcl::Controls::TWinControl* AOwnerWindow) : Dxshadowwindow::TdxShadowWindow(AOwnerWindow) { }
	/* TdxShadowWindow.Destroy */ inline __fastcall virtual ~TdxRibbonFormShadowWindow(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonFormShadowWindow(HWND ParentWindow) : Dxshadowwindow::TdxShadowWindow(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonAutoHideMode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonAutoHideMode : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FActive;
	Dxanimation::TdxAnimationTransition* FAnimation;
	bool FEnabled;
	bool FIsUIShown;
	TdxCustomRibbonForm* FRibbonForm;
	Vcl::Controls::TWinControl* __fastcall GetRibbon(void);
	void __fastcall SetActive(bool AValue);
	void __fastcall SetEnabled(bool AValue);
	
protected:
	virtual void __fastcall AlignControls(const System::Types::TRect &R);
	virtual void __fastcall Finalize(void);
	virtual void __fastcall Initialize(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	bool __fastcall GetStatusBar(/* out */ Vcl::Controls::TWinControl* &AControl);
	void __fastcall UpdateUIVisibility(bool AVisible, bool AWithAnimation);
	__property Vcl::Controls::TWinControl* Ribbon = {read=GetRibbon};
	__property TdxCustomRibbonForm* RibbonForm = {read=FRibbonForm};
	
public:
	__fastcall virtual TdxRibbonAutoHideMode(TdxCustomRibbonForm* ARibbonForm);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	bool __fastcall IsAvailable(void);
	void __fastcall HideUI(bool AWithAnimation = true);
	void __fastcall ShowUI(bool AWithAnimation = true);
	__property bool Active = {read=FActive, write=SetActive, nodefault};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, nodefault};
	__property bool IsUIShown = {read=FIsUIShown, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxRibbonAutoHideMode(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxRibbonAutoHideModeAnimation;
class PASCALIMPLEMENTATION TdxRibbonAutoHideModeAnimation : public Dxanimation::TdxAnimationTransition
{
	typedef Dxanimation::TdxAnimationTransition inherited;
	
private:
	bool FActivating;
	TdxRibbonAutoHideMode* FAutoHideMode;
	Vcl::Controls::TWinControl* __fastcall GetRibbon(void);
	TdxCustomRibbonForm* __fastcall GetRibbonForm(void);
	
protected:
	virtual void __fastcall DoAnimate(void);
	
public:
	__fastcall TdxRibbonAutoHideModeAnimation(TdxRibbonAutoHideMode* AAutoHideMode, bool AActivating);
	__fastcall virtual ~TdxRibbonAutoHideModeAnimation(void);
	virtual void __fastcall AfterConstruction(void);
	__property bool Activating = {read=FActivating, nodefault};
	__property TdxRibbonAutoHideMode* AutoHideMode = {read=FAutoHideMode};
	__property Vcl::Controls::TWinControl* Ribbon = {read=GetRibbon};
	__property TdxCustomRibbonForm* RibbonForm = {read=GetRibbonForm};
};


class DELPHICLASS TdxRibbonAutoHideModeController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxRibbonAutoHideModeController : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TdxCustomRibbonForm* FActiveRibbonForm;
	bool __fastcall IsChildHandle(HWND AHandle);
	bool __fastcall IsInCaptionArea(const System::Types::TPoint &P);
	void __fastcall SetActiveRibbonForm(TdxCustomRibbonForm* const AValue);
	
protected:
	virtual void __fastcall HookKeyboard(System::Word AKey, NativeInt AData, NativeInt &AHookResult);
	virtual void __fastcall HookMouse(NativeUInt wParam, Winapi::Windows::PMouseHookStruct lParam, NativeInt &AHookResult);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation AOperation);
	void __fastcall UpdateHooksState(void);
	
public:
	__fastcall virtual ~TdxRibbonAutoHideModeController(void);
	__property TdxCustomRibbonForm* ActiveRibbonForm = {read=FActiveRibbonForm, write=SetActiveRibbonForm};
public:
	/* TComponent.Create */ inline __fastcall virtual TdxRibbonAutoHideModeController(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxCustomRibbonForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
private:
	bool FAdjustLayoutForNonClientDrawing;
	bool FAutoScroll;
	Vcl::Controls::TCaption FCaption;
	System::StaticArray<HRGN, 4> FCornerRegions;
	Dxribbonskins::TdxRibbonFormData FData;
	void *FDefClientProc;
	bool FDelayedActivate;
	bool FDisableAero;
	bool FDisableMDIClientScrollBars;
	int FExtendFrameAtTopHeight;
	HWND FFakeClientHandle;
	bool FHasRegion;
	bool FIsActive;
	HMENU FLoadedSystemMenu;
	bool FNeedCallActivate;
	void *FNewClientInstance;
	void *FOldClientProc;
	Vcl::Controls::TWinControl* FPrevActiveControl;
	int FRedrawCount;
	bool FResettingGlass;
	bool FRibbonAlwaysOnTop;
	TdxRibbonAutoHideMode* FRibbonAutoHideMode;
	Vcl::Controls::TWinControl* FRibbonControl;
	_di_IdxRibbonFormClient FRibbonFormClient;
	Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* FRibbonNonClientHelper;
	TdxRibbonFormShadowWindow* FShadow;
	System::Types::TSize FSizingBorders;
	bool FSizingLoop;
	bool FUseSkinColor;
	bool FVisibleChanging;
	System::Types::TRect FZoomedBoundsOffsets;
	void __fastcall AfterResize(bool APrevRibbonVisible, int APrevRibbonHeight, bool AIsZoomed);
	void __fastcall BeforeResize(/* out */ bool &ARibbonVisible, /* out */ int &ARibbonHeight);
	void __fastcall CalculateCornerRegions(void);
	void __fastcall CalculateZoomedOffsets(void);
	bool __fastcall CanSetWindowRegion(HRGN ARegion);
	void __fastcall CheckExtendFrame(bool AZoomed);
	void __fastcall CheckResizingNCHitTest(NativeInt &AHitTest, const System::Types::TPoint &P);
	void __fastcall CorrectWindowStyle(unsigned &AStyle);
	void __fastcall CorrectZoomedBounds(System::Types::TRect &R);
	void __fastcall CreateCornerRegions(void);
	void __fastcall DestroyCornerRegions(void);
	void __fastcall ExcludeRibbonPaintArea(HDC DC);
	void __fastcall ForceUpdateWindowSize(void);
	void __fastcall FullRedrawWithChildren(void);
	Dxribbonskins::TdxRibbonApplicationMenuState __fastcall GetApplicationMenuState(void);
	System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	System::Uitypes::TBorderIcons __fastcall GetBorderIcons(void);
	Vcl::Forms::TFormBorderStyle __fastcall GetBorderStyle(void);
	System::Types::TRect __fastcall GetCurrentBordersWidth(void);
	bool __fastcall GetIsDestroying(void);
	Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* __fastcall GetRibbonNonClientHelper(void);
	Dxribbonskins::TdxRibbonStyle __fastcall GetRibbonStyle(void);
	bool __fastcall GetUseSkin(void);
	void __fastcall FinalizeSkin(void);
	void __fastcall InitializeSkin(void);
	HIDESBASE void __fastcall InvalidateFrame(HWND AWnd, bool AUpdate = false);
	bool __fastcall IsNeedCorrectForAutoHideTaskBar(void);
	bool __fastcall IsNeedUpdateCornerRegions(void);
	bool __fastcall IsNormalWindowState(void);
	bool __fastcall IsRibbonHelpButtonPlacedOnCaption(void);
	void __fastcall DestroySystemMenu(void);
	void __fastcall LoadSystemMenu(void);
	void __fastcall NewClientWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall ResetStandardSystemMenu(void);
	HIDESBASE void __fastcall SetAutoScroll(const bool Value);
	HIDESBASE void __fastcall SetBorderIcons(const System::Uitypes::TBorderIcons Value);
	HIDESBASE void __fastcall SetBorderStyle(const Vcl::Forms::TFormBorderStyle Value);
	void __fastcall SetDisableAero(const bool Value);
	void __fastcall SetDisableMDIClientScrollBars(const bool Value);
	void __fastcall SetPrevActiveControl(Vcl::Controls::TWinControl* AValue);
	void __fastcall SetRegion(HRGN ARegion, bool ARedraw = false);
	void __fastcall SetRibbonControl(Vcl::Controls::TWinControl* AValue);
	void __fastcall SetRibbonAlwaysOnTop(const bool Value);
	void __fastcall SetRibbonAutoHideMode(TdxRibbonAutoHideMode* const AValue);
	void __fastcall SetRibbonNonClientHelper(Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* AValue);
	void __fastcall SetUseSkinColor(const bool Value);
	void __fastcall ShowSystemMenu(bool AFromMouse);
	void __fastcall ResetGlassFrame(void);
	HIDESBASE void __fastcall UpdateGlassFrame(void);
	HIDESBASE MESSAGE void __fastcall CMActionUpdate(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMActivate(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMShowingChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMVisibleChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMRibbonFormNCChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DXMRibbonFormSysCommand(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMDisplayChange(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMDWMCompositionChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	MESSAGE void __fastcall WMGetText(Winapi::Messages::TWMGetText &Message);
	MESSAGE void __fastcall WMGetTextLength(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonUp(Winapi::Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMNCActivate(Winapi::Messages::TWMNCActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMNCRButtonUp(Winapi::Messages::TWMNCHitMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	HIDESBASE MESSAGE void __fastcall WMRButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMRButtonUp(Winapi::Messages::TWMMouse &Message);
	MESSAGE void __fastcall WMSetText(Winapi::Messages::TWMSetText &Message);
	HIDESBASE MESSAGE void __fastcall WMShowWindow(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMSize(Winapi::Messages::TWMSize &Message);
	MESSAGE void __fastcall WMStyleChanging(Winapi::Messages::TWMStyleChange &Message);
	HIDESBASE MESSAGE void __fastcall WMSysCommand(Winapi::Messages::TWMSysCommand &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	
protected:
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual void __fastcall AdjustLayout(void);
	DYNAMIC void __fastcall AdjustSize(void);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual void __fastcall BuildSystemMenu(NativeUInt AMenu);
	void __fastcall CallDWMWindowProc(void *Message);
	virtual bool __fastcall CanAdjustLayout(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWindowHandle(void);
	virtual void __fastcall DoCreate(void);
	void __fastcall DrawNonClientArea(bool ADrawCaption, HRGN AUpdateRegion = (HRGN)(0x1));
	void __fastcall ExtendFrameIntoClientAreaAtTop(int AHeight);
	virtual Dxribbonskins::TdxRibbonBorderIcons __fastcall GetFormBorderIcons(void);
	TdxCustomRibbonForm* __fastcall GetMDIParent(void);
	virtual bool __fastcall HandleWithHelper(bool ADown, System::Uitypes::TMouseButton AButton);
	DYNAMIC void __fastcall InitializeNewForm(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall ModifySystemMenu(NativeUInt ASysMenu);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall RecalculateCaptionArea(void);
	void __fastcall RecalculateFormSizes(void);
	void __fastcall ResetSystemMenu(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall ShiftControlsVertically(int ADelta);
	void __fastcall UpdateBorderIcons(void);
	void __fastcall UpdateNonClientArea(void);
	void __fastcall UpdateSkins(void);
	void __fastcall UpdateSystemMenu(void);
	void __fastcall UpdateWindowRegion(bool AIsMaximized);
	void __fastcall UpdateWindowStates(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	void __fastcall DoAfterApplicationMenuPopup(void);
	void __fastcall DoBeforeApplicationMenuPopup(void);
	void __fastcall DoBeforeShowKeyTips(void);
	__property Dxribbonskins::TdxRibbonApplicationMenuState ApplicationMenuState = {read=GetApplicationMenuState, nodefault};
	__property bool DisableAero = {read=FDisableAero, write=SetDisableAero, default=0};
	__property bool DisableMDIClientScrollBars = {read=FDisableMDIClientScrollBars, write=SetDisableMDIClientScrollBars, default=1};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property _di_IdxRibbonFormClient RibbonFormClient = {read=FRibbonFormClient};
	__property Dxribbonskins::TdxRibbonStyle RibbonStyle = {read=GetRibbonStyle, nodefault};
	__property bool UseSkin = {read=GetUseSkin, nodefault};
	
public:
	__fastcall virtual TdxCustomRibbonForm(System::Classes::TComponent* AOwner);
	__fastcall virtual TdxCustomRibbonForm(System::Classes::TComponent* AOwner, int Dummy);
	__fastcall virtual ~TdxCustomRibbonForm(void);
	void __fastcall FullUpdate(void);
	virtual int __fastcall GetCaptionHeightDelta(bool AHasQuickAccessToolbar);
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual void __fastcall Invalidate(void);
	bool __fastcall IsUseAeroNCPaint(void);
	void __fastcall ResetWindowRegion(void);
	void __fastcall SetRedraw(bool ARedraw);
	void __fastcall UpdateBorders(void);
	void __fastcall UpdateColorScheme(void);
	__property bool IsActive = {read=FIsActive, nodefault};
	__property Vcl::Controls::TWinControl* PrevActiveControl = {read=FPrevActiveControl, write=SetPrevActiveControl};
	__property bool RibbonAlwaysOnTop = {read=FRibbonAlwaysOnTop, write=SetRibbonAlwaysOnTop, nodefault};
	__property TdxRibbonAutoHideMode* RibbonAutoHideMode = {read=FRibbonAutoHideMode, write=SetRibbonAutoHideMode};
	__property Vcl::Controls::TWinControl* RibbonControl = {read=FRibbonControl, write=SetRibbonControl};
	__property Dxribbonformcaptionhelper::TdxRibbonFormCaptionHelper* RibbonNonClientHelper = {read=GetRibbonNonClientHelper, write=SetRibbonNonClientHelper};
	
__published:
	__property bool AdjustLayoutForNonClientDrawing = {read=FAdjustLayoutForNonClientDrawing, write=FAdjustLayoutForNonClientDrawing, default=1};
	__property bool AutoScroll = {read=FAutoScroll, write=SetAutoScroll, default=0};
	__property System::Uitypes::TBorderIcons BorderIcons = {read=GetBorderIcons, write=SetBorderIcons, nodefault};
	__property Vcl::Forms::TFormBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, default=2};
	__property KeyPreview = {default=1};
	__property bool UseSkinColor = {read=FUseSkinColor, write=SetUseSkinColor, default=1};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomRibbonForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
private:
	void *__IdxRibbonFormControllerHelper;	/* IdxRibbonFormControllerHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {DEC82702-29ED-413B-852D-C2AA884FD99A}
	operator _di_IdxRibbonFormControllerHelper()
	{
		_di_IdxRibbonFormControllerHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxRibbonFormControllerHelper*(void) { return (IdxRibbonFormControllerHelper*)&__IdxRibbonFormControllerHelper; }
	#endif
	
};


class DELPHICLASS TdxRibbonForm;
class PASCALIMPLEMENTATION TdxRibbonForm : public TdxCustomRibbonForm
{
	typedef TdxCustomRibbonForm inherited;
	
public:
	/* TdxCustomRibbonForm.Create */ inline __fastcall virtual TdxRibbonForm(System::Classes::TComponent* AOwner) : TdxCustomRibbonForm(AOwner) { }
	/* TdxCustomRibbonForm.CreateNew */ inline __fastcall virtual TdxRibbonForm(System::Classes::TComponent* AOwner, int Dummy) : TdxCustomRibbonForm(AOwner, Dummy) { }
	/* TdxCustomRibbonForm.Destroy */ inline __fastcall virtual ~TdxRibbonForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonForm(HWND ParentWindow) : TdxCustomRibbonForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int dxRibbonAutoHideModeHideUIAnimationTime;
extern PACKAGE int dxRibbonAutoHideModeShowUIAnimationTime;
extern PACKAGE void __fastcall SetWindowTextWithoutRedraw(HWND AWnd, const System::UnicodeString AText);
}	/* namespace Dxribbonform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONFORM)
using namespace Dxribbonform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonformHPP
