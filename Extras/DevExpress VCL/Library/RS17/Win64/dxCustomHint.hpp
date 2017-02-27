// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCustomHint.pas' rev: 24.00 (Win64)

#ifndef DxcustomhintHPP
#define DxcustomhintHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcustomhint
{
//-- type declarations -------------------------------------------------------
__interface IcxHintWindowHelper;
typedef System::DelphiInterface<IcxHintWindowHelper> _di_IcxHintWindowHelper;
__interface  INTERFACE_UUID("{BE228118-851E-4C8D-8A31-58E26AA4F88B}") IcxHintWindowHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall SetHintAreaBounds(const System::Types::TRect &ABounds, bool AUseMousePos) = 0 ;
};

__interface IcxHintableObject;
typedef System::DelphiInterface<IcxHintableObject> _di_IcxHintableObject;
__interface  INTERFACE_UUID("{228FF1F5-6D0C-40F0-9F7B-8C71CE12CEC8}") IcxHintableObject  : public System::IInterface 
{
	
public:
	virtual bool __fastcall HasHintPoint(const System::Types::TPoint P) = 0 ;
	virtual bool __fastcall IsHintAtMousePos(void) = 0 ;
	virtual bool __fastcall UseHintHidePause(void) = 0 ;
};

enum TcxHintAnimationStyle : unsigned char { cxhaSlideFromLeft, cxhaSlideFromRight, cxhaSlideDownward, cxhaSlideUpward, cxhaSlideFromCenter, cxhaHide, cxhaActivate, cxhaFadeIn, cxhaAuto, cxhaNone };

class DELPHICLASS TcxBaseHintWindow;
class PASCALIMPLEMENTATION TcxBaseHintWindow : public Vcl::Controls::THintWindow
{
	typedef Vcl::Controls::THintWindow inherited;
	
private:
	bool FActivating;
	TcxHintAnimationStyle FAnimationStyle;
	int FAnimationDelay;
	Vcl::Forms::TFormBorderStyle FBorderStyle;
	Cxgraphics::TcxCanvas* FcxCanvas;
	bool FHasAnimation;
	System::Types::TRect FHintAreaBounds;
	unsigned FLastActive;
	bool FNeedEraseBackground;
	bool FUseMousePos;
	HIDESBASE MESSAGE void __fastcall CMTextChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	
protected:
	bool FStandardHint;
	virtual void __fastcall AdjustActivateRect(System::Types::TRect &ARect);
	void __fastcall CheckExecuteAnimation(const System::UnicodeString AHint);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	TcxHintAnimationStyle __fastcall GetAnimationStyle(void);
	virtual void __fastcall DisableRegion(void);
	virtual void __fastcall EnableRegion(void);
	virtual bool __fastcall HasWindowRegion(void);
	virtual void __fastcall SetHintAreaBounds(const System::Types::TRect &ABounds, bool AUseMousePos);
	HIDESBASE virtual void __fastcall Show(void);
	__property System::Types::TRect HintAreaBounds = {read=FHintAreaBounds};
	__property bool UseMousePos = {read=FUseMousePos, nodefault};
	
public:
	__fastcall virtual TcxBaseHintWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxBaseHintWindow(void);
	virtual void __fastcall ActivateHint(System::Types::TRect &ARect, const System::UnicodeString AHint);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	__property TcxHintAnimationStyle AnimationStyle = {read=FAnimationStyle, write=FAnimationStyle, nodefault};
	__property int AnimationDelay = {read=FAnimationDelay, write=FAnimationDelay, nodefault};
	__property Vcl::Forms::TBorderStyle BorderStyle = {read=FBorderStyle, write=FBorderStyle, nodefault};
	__property Cxgraphics::TcxCanvas* cxCanvas = {read=FcxCanvas};
	__property bool NeedEraseBackground = {read=FNeedEraseBackground, write=FNeedEraseBackground, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxBaseHintWindow(HWND ParentWindow) : Vcl::Controls::THintWindow(ParentWindow) { }
	
private:
	void *__IcxHintWindowHelper;	/* IcxHintWindowHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {BE228118-851E-4C8D-8A31-58E26AA4F88B}
	operator _di_IcxHintWindowHelper()
	{
		_di_IcxHintWindowHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxHintWindowHelper*(void) { return (IcxHintWindowHelper*)&__IcxHintWindowHelper; }
	#endif
	
};


class DELPHICLASS TcxCustomHintWindow;
class PASCALIMPLEMENTATION TcxCustomHintWindow : public TcxBaseHintWindow
{
	typedef TcxBaseHintWindow inherited;
	
private:
	System::UnicodeString FCaption;
	void __fastcall SetStandardHint(const bool Value);
	
protected:
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetPainter(void);
	HIDESBASE virtual void __fastcall ShowHint(int X, int Y, System::UnicodeString ACaption, System::UnicodeString AHint, int AMaxWidth = 0x0);
	__property bool StandardHint = {read=FStandardHint, write=SetStandardHint, nodefault};
	
public:
	__property System::UnicodeString Caption = {read=FCaption, write=FCaption};
public:
	/* TcxBaseHintWindow.Create */ inline __fastcall virtual TcxCustomHintWindow(System::Classes::TComponent* AOwner) : TcxBaseHintWindow(AOwner) { }
	/* TcxBaseHintWindow.Destroy */ inline __fastcall virtual ~TcxCustomHintWindow(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomHintWindow(HWND ParentWindow) : TcxBaseHintWindow(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxCustomHintWindowClass;

class DELPHICLASS TcxCustomHintStyle;
class DELPHICLASS TcxCustomHintStyleController;
class PASCALIMPLEMENTATION TcxCustomHintStyle : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	System::Classes::TNotifyEvent FOnChanged;
	
protected:
	virtual void __fastcall ControllerChangedNotification(TcxCustomHintStyleController* AStyleController);
	virtual void __fastcall ControllerFreeNotification(TcxCustomHintStyleController* AHintStyleController);
	virtual void __fastcall DoShowHint(System::UnicodeString &AHintStr, bool &ACanShow, Vcl::Controls::THintInfo &AHintInfo);
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	__fastcall virtual TcxCustomHintStyle(System::Classes::TComponent* AComponent);
	virtual void __fastcall ComponentRemoved(System::Classes::TComponent* AComponent);
	virtual TcxCustomHintWindowClass __fastcall GetHintWindowClass(void) = 0 ;
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxCustomHintStyle(void) { }
	
};


typedef System::TMetaClass* TcxHintStyleClass;

typedef void __fastcall (__closure *TcxHintStyleChangedEvent)(System::TObject* Sender, TcxCustomHintStyle* AStyle);

typedef void __fastcall (__closure *TcxShowHintEvent)(System::TObject* Sender, System::UnicodeString &HintStr, bool &CanShow, Vcl::Controls::THintInfo &HintInfo);

typedef void __fastcall (__closure *TcxShowHintExEvent)(System::TObject* Sender, System::UnicodeString &Caption, System::UnicodeString &HintStr, bool &CanShow, Vcl::Controls::THintInfo &HintInfo);

class PASCALIMPLEMENTATION TcxCustomHintStyleController : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FGlobal;
	int FHintShortPause;
	int FHintPause;
	int FHintHidePause;
	TcxHintStyleClass FHintStyleClass;
	TcxCustomHintWindow* FHintWindow;
	System::Classes::TList* FListeners;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	int FUpdateCount;
	bool FUseHintControlLookAndFeel;
	TcxHintStyleChangedEvent FOnHintStyleChanged;
	TcxShowHintEvent FOnShowHint;
	TcxShowHintExEvent FOnShowHintEx;
	void __fastcall DoShowHint(System::UnicodeString &AHintStr, bool &ACanShow, Vcl::Controls::THintInfo &AHintInfo);
	void __fastcall DoShowHintEx(System::UnicodeString &AHintStr, System::UnicodeString &AHintCaption, bool &ACanShow, Vcl::Controls::THintInfo &AHintInfo);
	System::UnicodeString __fastcall GetHintStyleClassName(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	void __fastcall HintStyleChanged(System::TObject* Sender);
	void __fastcall SetGlobal(bool Value);
	void __fastcall SetHintStyle(TcxCustomHintStyle* Value);
	void __fastcall SetHintStyleClass(const TcxHintStyleClass Value);
	void __fastcall SetHintStyleClassName(const System::UnicodeString Value);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* const Value);
	void __fastcall SetHintShortPause(int Value);
	void __fastcall SetHintPause(int Value);
	void __fastcall SetHintHidePause(int Value);
	void __fastcall SetApplicationHintProperties(void);
	
protected:
	TcxCustomHintStyle* FHintStyle;
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual TcxHintStyleClass __fastcall GetHintStyleClass(void);
	virtual TcxCustomHintWindowClass __fastcall GetHintWindowClass(void);
	void __fastcall CreateHintStyle(void);
	void __fastcall DestroyHintStyle(void);
	virtual void __fastcall BeginUpdate(void);
	virtual void __fastcall EndUpdate(void);
	void __fastcall Changed(void);
	virtual void __fastcall DoHintStyleChanged(TcxCustomHintStyle* AStyle);
	__property bool Global = {read=FGlobal, write=SetGlobal, default=1};
	__property int HintHidePause = {read=FHintHidePause, write=SetHintHidePause, default=2500};
	__property int HintPause = {read=FHintPause, write=SetHintPause, default=500};
	__property int HintShortPause = {read=FHintShortPause, write=SetHintShortPause, default=50};
	__property TcxHintStyleClass HintStyleClass = {read=GetHintStyleClass, write=SetHintStyleClass};
	__property System::UnicodeString HintStyleClassName = {read=GetHintStyleClassName, write=SetHintStyleClassName};
	__property System::Classes::TList* Listeners = {read=FListeners};
	__property TcxHintStyleChangedEvent OnHintStyleChanged = {read=FOnHintStyleChanged, write=FOnHintStyleChanged};
	__property TcxShowHintEvent OnShowHint = {read=FOnShowHint, write=FOnShowHint};
	__property TcxShowHintExEvent OnShowHintEx = {read=FOnShowHintEx, write=FOnShowHintEx};
	
public:
	__fastcall virtual TcxCustomHintStyleController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomHintStyleController(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall AddListener(TcxCustomHintStyle* AListener);
	virtual void __fastcall RemoveListener(TcxCustomHintStyle* AListener);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeelValue(void);
	void __fastcall ShowHint(int X, int Y, System::UnicodeString ACaption, System::UnicodeString AHint, int AMaxWidth = 0x0);
	void __fastcall HideHint(void);
	__property TcxCustomHintStyle* HintStyle = {read=FHintStyle, write=SetHintStyle};
	__property TcxCustomHintWindow* HintWindow = {read=FHintWindow};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property bool UseHintControlLookAndFeel = {read=FUseHintControlLookAndFeel, write=FUseHintControlLookAndFeel, default=0};
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	void *__IcxLookAndFeelContainer;	/* Cxlookandfeels::IcxLookAndFeelContainer */
	
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
	// {6065B58B-C557-4464-A67D-64183FD13F25}
	operator Cxlookandfeels::_di_IcxLookAndFeelContainer()
	{
		Cxlookandfeels::_di_IcxLookAndFeelContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxlookandfeels::IcxLookAndFeelContainer*(void) { return (Cxlookandfeels::IcxLookAndFeelContainer*)&__IcxLookAndFeelContainer; }
	#endif
	
};


class DELPHICLASS TdxCustomHintViewInfoHelper;
class PASCALIMPLEMENTATION TdxCustomHintViewInfoHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBoundsRect;
	
public:
	virtual void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas) = 0 ;
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas) = 0 ;
	__property System::Types::TRect BoundsRect = {read=FBoundsRect, write=FBoundsRect};
public:
	/* TObject.Create */ inline __fastcall TdxCustomHintViewInfoHelper(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomHintViewInfoHelper(void) { }
	
};


class DELPHICLASS TdxCustomHintViewInfo;
class PASCALIMPLEMENTATION TdxCustomHintViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect __fastcall GetBoundsRect(void);
	
protected:
	TdxCustomHintViewInfoHelper* FHelper;
	virtual void __fastcall CreateHelper(void) = 0 ;
	virtual void __fastcall DestroyHelper(void);
	
public:
	__fastcall TdxCustomHintViewInfo(void);
	__fastcall virtual ~TdxCustomHintViewInfo(void);
	virtual void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas);
	__property System::Types::TRect BoundsRect = {read=GetBoundsRect};
};


class DELPHICLASS TdxHintViewInfoHelper;
class PASCALIMPLEMENTATION TdxHintViewInfoHelper : public TdxCustomHintViewInfoHelper
{
	typedef TdxCustomHintViewInfoHelper inherited;
	
private:
	System::UnicodeString FText;
	System::Types::TPoint FPos;
	System::Types::TSize __fastcall CalculateMinSize(Vcl::Graphics::TCanvas* ACanvas);
	
protected:
	virtual void __fastcall CorrectMinSize(System::Types::TSize &ASize);
	virtual System::Types::TRect __fastcall GetTextRect(void);
	virtual void __fastcall DrawText(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall PrepareCanvasFont(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall SetTextColor(Vcl::Graphics::TCanvas* ACanvas);
	__property System::UnicodeString Text = {read=FText, write=FText};
	__property System::Types::TPoint Pos = {read=FPos, write=FPos};
	
public:
	__fastcall TdxHintViewInfoHelper(const System::UnicodeString AHint, const System::UnicodeString AShortCut, const System::Types::TPoint ACursorPos);
	virtual void __fastcall Calculate(Vcl::Graphics::TCanvas* ACanvas);
	virtual void __fastcall Paint(Vcl::Graphics::TCanvas* ACanvas);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxHintViewInfoHelper(void) { }
	
};


class DELPHICLASS TcxCustomHintHelper;
class PASCALIMPLEMENTATION TcxCustomHintHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	System::TObject* FHintableObject;
	System::Types::TRect FHintAreaBounds;
	Cxclasses::TcxTimer* FHintCheckerTimer;
	Cxclasses::TcxTimer* FHintHideTimer;
	int FHintHidePause;
	System::TObject* FLastHintableObject;
	System::Types::TPoint FLastHintMousePos;
	System::UnicodeString FLastHintText;
	System::Types::TRect FHintTextRect;
	Vcl::Controls::THintWindow* FHintWindow;
	void __fastcall HintCheckerTimerHandler(System::TObject* Sender);
	void __fastcall HintHideTimerHandler(System::TObject* Sender);
	void __fastcall RestartHintHideTimer(void);
	void __fastcall RecreateHintWindow(void);
	
protected:
	bool __fastcall IsMouseButtonPressed(void);
	virtual void __fastcall MouseLeave(void);
	virtual bool __fastcall PtInCaller(const System::Types::TPoint P);
	virtual bool __fastcall CanShowHint(void);
	virtual void __fastcall CorrectHintWindowRect(System::Types::TRect &ARect);
	virtual Vcl::Controls::TWinControl* __fastcall GetHintWinControl(void);
	virtual System::Types::TRect __fastcall GetHintControlBounds(void);
	virtual int __fastcall GetHintHidePause(void);
	virtual Vcl::Controls::THintWindowClass __fastcall GetHintWindowClass(void);
	virtual System::Types::TRect __fastcall GetHintWindowRect(const System::Types::TRect &AHintAreaBounds, const System::Types::TRect &ATextRect, const System::UnicodeString AText, bool AIsHintMultiLine);
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerWinControl(void);
	virtual bool __fastcall IsHintAtMousePos(void);
	virtual bool __fastcall IsSuppressHintOnMouseDown(void);
	void __fastcall StartHintCheckerTimers(void);
	void __fastcall StopHintCheckerTimers(void);
	virtual bool __fastcall UseHintHidePause(void);
	
public:
	__fastcall virtual ~TcxCustomHintHelper(void);
	void __fastcall CancelHint(void);
	void __fastcall HideHint(void);
	virtual void __fastcall MouseDown(void);
	void __fastcall ResetLastHintElement(void);
	void __fastcall ShowHint(const System::Types::TRect &AHintAreaBounds, const System::Types::TRect &ATextRect, const System::UnicodeString AText, bool AIsHintMultiLine, System::TObject* AHintObject, Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0));
	__property System::TObject* HintableObject = {read=FHintableObject};
	__property Vcl::Controls::THintWindow* HintWindow = {read=FHintWindow};
public:
	/* TObject.Create */ inline __fastcall TcxCustomHintHelper(void) : Dxcoreclasses::TcxIUnknownObject() { }
	
private:
	void *__IcxMouseTrackingCaller2;	/* Cxcontrols::IcxMouseTrackingCaller2 */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {3A5D973B-F016-4F22-80B6-1D35668D7743}
	operator Cxcontrols::_di_IcxMouseTrackingCaller2()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller2 intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller2*(void) { return (Cxcontrols::IcxMouseTrackingCaller2*)&__IcxMouseTrackingCaller2; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {84A4BCBE-E001-4D60-B7A6-75E2B0DCD3E9}
	operator Cxcontrols::_di_IcxMouseTrackingCaller()
	{
		Cxcontrols::_di_IcxMouseTrackingCaller intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxMouseTrackingCaller*(void) { return (Cxcontrols::IcxMouseTrackingCaller*)&__IcxMouseTrackingCaller2; }
	#endif
	
};


class DELPHICLASS TcxControlHintHelper;
class PASCALIMPLEMENTATION TcxControlHintHelper : public TcxCustomHintHelper
{
	typedef TcxCustomHintHelper inherited;
	
protected:
	virtual Cxcontrols::TcxControl* __fastcall GetHintControl(void);
	virtual System::Types::TRect __fastcall GetHintControlBounds(void);
	virtual Vcl::Controls::TWinControl* __fastcall GetHintWinControl(void);
	virtual Cxcontrols::TcxControl* __fastcall GetOwnerControl(void) = 0 ;
	virtual Vcl::Controls::TWinControl* __fastcall GetOwnerWinControl(void);
public:
	/* TcxCustomHintHelper.Destroy */ inline __fastcall virtual ~TcxControlHintHelper(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxControlHintHelper(void) : TcxCustomHintHelper() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall cxActivateHint(Vcl::Controls::THintWindow* AHintWindow, const System::Types::TRect &ARect, const System::UnicodeString AHint);
extern PACKAGE void __fastcall cxActivateHintData(Vcl::Controls::THintWindow* AHintWindow, const System::Types::TRect &ARect, const System::UnicodeString AHint, void * AData);
extern PACKAGE bool __fastcall cxProcessControlHintInfo(/* out */ Vcl::Controls::THintInfo &AHintInfo, Vcl::Controls::THintWindow* &AHintWindow, Vcl::Controls::TControl* AControl, const System::UnicodeString AHint, System::Types::TRect &AHintWinRect, void * AData = (void *)(0x0), int AHintHidePause = 0x0);
extern PACKAGE Cxclasses::TcxRegisteredClasses* __fastcall cxRegisteredHintStyles(void);
extern PACKAGE TcxCustomHintStyleController* __fastcall cxGetHintStyleController(void);
extern PACKAGE TcxCustomHintStyle* __fastcall cxGetHintStyle(void);
extern PACKAGE Vcl::Controls::THintWindowClass __fastcall cxGetHintWindowClass(void);
extern PACKAGE Vcl::Controls::TControl* __fastcall cxGetHintedControl(void);
extern PACKAGE void __fastcall cxRemoveHintedControl(void);
}	/* namespace Dxcustomhint */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCUSTOMHINT)
using namespace Dxcustomhint;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcustomhintHPP
