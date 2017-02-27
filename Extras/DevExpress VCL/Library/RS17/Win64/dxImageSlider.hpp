// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxImageSlider.pas' rev: 24.00 (Win64)

#ifndef DximagesliderHPP
#define DximagesliderHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxAnimation.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dximageslider
{
//-- type declarations -------------------------------------------------------
enum TdxImageSliderTransitionEffect : unsigned char { isteNone, isteSlide, isteFade, isteSegmentedFade, isteRandomSegmentedFade };

class DELPHICLASS TdxCustomImageSlider;
class PASCALIMPLEMENTATION TdxCustomImageSlider : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Dxanimation::TdxImageAnimationTransition* FAnimation;
	Cxgraphics::TcxImageFitMode FImageFitMode;
	Cxgraphics::TcxImageCollection* FImages;
	int FItemIndex;
	bool FScrollNeeded;
	TdxImageSliderTransitionEffect FTransitionEffect;
	bool FTransparent;
	System::Types::TRect FLeftArrowRect;
	System::Types::TRect FRightArrowRect;
	System::Types::TPoint FPrevMousePos;
	bool FLeftMouseButtonPressed;
	System::Classes::TNotifyEvent FOnChange;
	int __fastcall GetCount(void);
	bool __fastcall IsValidItemIndex(int AIndex);
	void __fastcall SetItemIndex(int Value);
	void __fastcall SetImages(Cxgraphics::TcxImageCollection* Value);
	void __fastcall SetImageFitMode(Cxgraphics::TcxImageFitMode Value);
	void __fastcall SetTransparent(bool Value);
	void __fastcall TrackingCallerMouseLeave(void);
	HIDESBASE void __fastcall Changed(void);
	
protected:
	virtual bool __fastcall AllowPan(Vcl::Forms::TScrollBarKind AScrollKind);
	virtual void __fastcall BeginGestureScroll(System::Types::TPoint APos);
	virtual void __fastcall GestureScroll(int ADeltaX, int ADeltaY);
	virtual void __fastcall Loaded(void);
	virtual bool __fastcall NeedPanningFeedback(Vcl::Forms::TScrollBarKind AScrollKind);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual void __fastcall EraseBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect)/* overload */;
	virtual void __fastcall Paint(void);
	virtual bool __fastcall NeedRedrawOnResize(void);
	void __fastcall Animate(int AStartIndex, int AFinishIndex)/* overload */;
	void __fastcall Animate(Vcl::Graphics::TPicture* AStartPicture, Vcl::Graphics::TPicture* AFinishPicture, Dxanimation::TdxDrawAnimationMode AAnimationMode, Dxanimation::TdxAnimationTransitionEffect ATransition)/* overload */;
	void __fastcall AnimationHandler(Dxanimation::TdxAnimationTransition* Sender, int &APosition, bool &AFinished);
	void __fastcall StopAnimation(void);
	void __fastcall ImageCollectionChanged(void);
	void __fastcall ImageCollectionDestroyed(void);
	__property Dxanimation::TdxImageAnimationTransition* Animation = {read=FAnimation};
	__property int Count = {read=GetCount, nodefault};
	__property Cxgraphics::TcxImageFitMode ImageFitMode = {read=FImageFitMode, write=SetImageFitMode, nodefault};
	__property Cxgraphics::TcxImageCollection* Images = {read=FImages, write=SetImages};
	__property int ItemIndex = {read=FItemIndex, write=SetItemIndex, nodefault};
	__property TdxImageSliderTransitionEffect TransitionEffect = {read=FTransitionEffect, write=FTransitionEffect, nodefault};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TdxCustomImageSlider(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomImageSlider(void);
	virtual bool __fastcall CanGoToNextImage(void);
	virtual bool __fastcall CanGoToPrevImage(void);
	virtual void __fastcall GoToImage(int ATargetItemIndex);
	virtual void __fastcall GoToNextImage(void);
	virtual void __fastcall GoToPrevImage(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomImageSlider(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  EraseBackground(HDC DC){ Cxcontrols::TcxControl::EraseBackground(DC); }
	
private:
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	void *__IcxImageCollectionListener;	/* Cxgraphics::IcxImageCollectionListener */
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
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
	// {FDFF372B-F49E-40C9-9E03-E0D6B110774A}
	operator Cxgraphics::_di_IcxImageCollectionListener()
	{
		Cxgraphics::_di_IcxImageCollectionListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgraphics::IcxImageCollectionListener*(void) { return (Cxgraphics::IcxImageCollectionListener*)&__IcxImageCollectionListener; }
	#endif
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


class DELPHICLASS TdxImageSlider;
class PASCALIMPLEMENTATION TdxImageSlider : public TdxCustomImageSlider
{
	typedef TdxCustomImageSlider inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property Enabled = {default=1};
	__property ImageFitMode = {default=2};
	__property Images;
	__property ItemIndex = {default=0};
	__property LookAndFeel;
	__property ParentColor = {default=1};
	__property TransitionEffect = {default=1};
	__property Transparent = {default=1};
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnChange;
public:
	/* TdxCustomImageSlider.Create */ inline __fastcall virtual TdxImageSlider(System::Classes::TComponent* AOwner) : TdxCustomImageSlider(AOwner) { }
	/* TdxCustomImageSlider.Destroy */ inline __fastcall virtual ~TdxImageSlider(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxImageSlider(HWND ParentWindow) : TdxCustomImageSlider(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dximageslider */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXIMAGESLIDER)
using namespace Dximageslider;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DximagesliderHPP
