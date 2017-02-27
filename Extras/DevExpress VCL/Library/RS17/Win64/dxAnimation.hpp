// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxAnimation.pas' rev: 24.00 (Win64)

#ifndef DxanimationHPP
#define DxanimationHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxanimation
{
//-- type declarations -------------------------------------------------------
enum TdxDrawAnimationMode : unsigned char { amScrollLeft, amScrollUp, amScrollRight, amScrollDown, amFade, amSegmentedFade, amRandomSegmentedFade };

enum TdxAnimationTransitionEffect : unsigned char { ateLinear, ateAccelerateDecelerate, ateCubic, ateTanh, ateCustom };

class DELPHICLASS TdxAnimationTransition;
typedef void __fastcall (__closure *TdxAnimationEvent)(TdxAnimationTransition* Sender, int &APosition, bool &AFinished);

typedef int __fastcall (*TdxAnimationTransitionEffectProc)(TdxAnimationTransition* Sender, const __int64 AValue, const __int64 AMaxValue, const int ALength);

__interface IdxAnimationListener;
typedef System::DelphiInterface<IdxAnimationListener> _di_IdxAnimationListener;
class DELPHICLASS TdxAnimationController;
__interface  INTERFACE_UUID("{0CAAD87B-8A4B-464B-A738-1340BD80C3D8}") IdxAnimationListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall AfterAnimation(TdxAnimationController* Sender) = 0 ;
	virtual void __fastcall BeforeAnimation(TdxAnimationController* Sender) = 0 ;
	virtual void __fastcall DestroyAnimation(TdxAnimationTransition* Animation) = 0 ;
};

class PASCALIMPLEMENTATION TdxAnimationController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FAnimations;
	int FActiveAnimations;
	System::Classes::_di_IInterfaceList FListenerList;
	Cxclasses::TcxTimer* FTimer;
	TdxAnimationTransition* __fastcall GetAnimation(int AIndex);
	int __fastcall GetCount(void);
	
protected:
	void __fastcall CheckTimer(void);
	void __fastcall Resume(TdxAnimationTransition* Animation);
	void __fastcall Suspend(TdxAnimationTransition* Animation);
	virtual void __fastcall TimerHandler(System::TObject* Sender);
	void __fastcall Terminate(TdxAnimationTransition* Animation);
	__property TdxAnimationTransition* Animations[int Index] = {read=GetAnimation};
	__property int ActiveAnimations = {read=FActiveAnimations, write=FActiveAnimations, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property System::Classes::_di_IInterfaceList ListenerList = {read=FListenerList};
	__property Cxclasses::TcxTimer* Timer = {read=FTimer, write=FTimer};
	
public:
	__fastcall virtual TdxAnimationController(void);
	__fastcall virtual ~TdxAnimationController(void);
	void __fastcall Add(TdxAnimationTransition* Animation);
	void __fastcall AddListener(_di_IdxAnimationListener AListener);
	void __fastcall Remove(TdxAnimationTransition* Animation);
	void __fastcall RemoveListener(_di_IdxAnimationListener AListener);
	void __fastcall Update(void);
};


class PASCALIMPLEMENTATION TdxAnimationTransition : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	__int64 FCurrent;
	__int64 FFinish;
	bool FFinished;
	bool FFreeOnTerminate;
	System::TObject* FInfo;
	unsigned FLength;
	int FLockCount;
	int FPosition;
	bool FPositionChanged;
	__int64 FStart;
	unsigned FTime;
	unsigned FTimerInterval;
	TdxAnimationTransitionEffect FTransitionEffect;
	TdxAnimationTransitionEffectProc FTransitionEffectProc;
	TdxAnimationEvent FOnAfterAnimate;
	TdxAnimationEvent FOnAnimate;
	TdxAnimationEvent FOnBeforeAnimate;
	System::Classes::TNotifyEvent FOnTerminate;
	bool __fastcall GetFinished(void);
	bool __fastcall GetSuspended(void);
	void __fastcall SetFinished(bool AValue);
	
protected:
	void __fastcall Animate(void);
	void __fastcall InitializeTime(void);
	virtual bool __fastcall IsCompatible(TdxAnimationTransition* Animation);
	virtual void __fastcall DoAfterAnimate(void);
	virtual void __fastcall DoAnimate(void);
	virtual void __fastcall DoBeforeAnimate(void);
	void __fastcall TryAnimate(void);
	__property __int64 Current = {read=FCurrent, write=FCurrent};
	__property __int64 Finish = {read=FFinish, write=FFinish};
	__property unsigned Length = {read=FLength, nodefault};
	__property __int64 Start = {read=FStart, write=FStart};
	__property unsigned TimerInterval = {read=FTimerInterval, write=FTimerInterval, nodefault};
	
public:
	__fastcall virtual TdxAnimationTransition(unsigned ATime, TdxAnimationTransitionEffect ATransitionEffect, int ALength);
	__fastcall virtual ~TdxAnimationTransition(void);
	void __fastcall ImmediateAnimation(void);
	void __fastcall Resume(void);
	void __fastcall Suspend(bool AFinished = false);
	void __fastcall Terminate(void);
	__property TdxAnimationTransitionEffect TransitionEffect = {read=FTransitionEffect, nodefault};
	__property TdxAnimationTransitionEffectProc TransitionEffectProc = {read=FTransitionEffectProc};
	__property bool Finished = {read=GetFinished, write=SetFinished, nodefault};
	__property bool FreeOnTerminate = {read=FFreeOnTerminate, write=FFreeOnTerminate, nodefault};
	__property System::TObject* Info = {read=FInfo, write=FInfo};
	__property int Position = {read=FPosition, nodefault};
	__property bool PositionChanged = {read=FPositionChanged, write=FPositionChanged, nodefault};
	__property bool Suspended = {read=GetSuspended, nodefault};
	__property unsigned Time = {read=FTime, nodefault};
	__property TdxAnimationEvent OnAfterAnimate = {read=FOnAfterAnimate, write=FOnAfterAnimate};
	__property TdxAnimationEvent OnAnimate = {read=FOnAnimate, write=FOnAnimate};
	__property TdxAnimationEvent OnBeforeAnimate = {read=FOnBeforeAnimate, write=FOnBeforeAnimate};
	__property System::Classes::TNotifyEvent OnTerminate = {read=FOnTerminate, write=FOnTerminate};
};


class DELPHICLASS TdxImageAnimationTransition;
class PASCALIMPLEMENTATION TdxImageAnimationTransition : public TdxAnimationTransition
{
	typedef TdxAnimationTransition inherited;
	
private:
	TdxDrawAnimationMode FMode;
	
public:
	__fastcall virtual TdxImageAnimationTransition(Vcl::Graphics::TGraphic* const AStartImage, Vcl::Graphics::TGraphic* const AFinishImage, unsigned ATime, TdxDrawAnimationMode AMode, TdxAnimationTransitionEffect ATransition, int ALength, bool AFreeImagesOnTerminate);
	void __fastcall Draw(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ADestRect)/* overload */;
	void __fastcall Draw(void * AGraphics, const System::Types::TRect &ADestRect)/* overload */;
	void __fastcall DrawTransparent(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ADestRect);
	__property TdxDrawAnimationMode Mode = {read=FMode, nodefault};
public:
	/* TdxAnimationTransition.Destroy */ inline __fastcall virtual ~TdxImageAnimationTransition(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxAnimationController* __fastcall dxAnimationController(void);
extern PACKAGE __int64 __fastcall dxMulDiv64(const __int64 nNumber, const __int64 nNumerator, const __int64 nDenominator);
extern PACKAGE __int64 __fastcall dxGetExactTickCount(void);
extern PACKAGE unsigned __fastcall dxGetExactTime(const __int64 AExactTickCount);
extern PACKAGE __int64 __fastcall dxTimeToTickCount(const unsigned ATime);
}	/* namespace Dxanimation */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXANIMATION)
using namespace Dxanimation;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxanimationHPP
