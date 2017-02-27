// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxFading.pas' rev: 24.00 (Win32)

#ifndef DxfadingHPP
#define DxfadingHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <dxGDIPlusAPI.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfading
{
//-- type declarations -------------------------------------------------------
enum TdxFadingObjectState : unsigned char { fosNone, fosGetParams, fosFading };

class DELPHICLASS TdxFadingOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FFadeInFrameCount;
	int FFadeInFrameDelay;
	int FFadeOutFrameCount;
	int FFadeOutFrameDelay;
	void __fastcall SetFadeInFrameCount(int AValue);
	void __fastcall SetFadeInFrameDelay(int AValue);
	void __fastcall SetFadeOutFrameCount(int AValue);
	void __fastcall SetFadeOutFrameDelay(int AValue);
	
public:
	__fastcall TdxFadingOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int FadeInFrameCount = {read=FFadeInFrameCount, write=SetFadeInFrameCount, default=4};
	__property int FadeInFrameDelay = {read=FFadeInFrameDelay, write=SetFadeInFrameDelay, default=15};
	__property int FadeOutFrameCount = {read=FFadeOutFrameCount, write=SetFadeOutFrameCount, default=12};
	__property int FadeOutFrameDelay = {read=FFadeOutFrameDelay, write=SetFadeOutFrameDelay, default=20};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxFadingOptions(void) { }
	
};

#pragma pack(pop)

__interface IdxFadingObject;
typedef System::DelphiInterface<IdxFadingObject> _di_IdxFadingObject;
__interface  INTERFACE_UUID("{73AB2A92-CDD9-4F13-965A-DC799DE837F9}") IdxFadingObject  : public System::IInterface 
{
	
public:
	virtual bool __fastcall CanFade(void) = 0 ;
	virtual void __fastcall DrawFadeImage(void) = 0 ;
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage) = 0 ;
};

__interface IdxFadingObjectFadingOptions;
typedef System::DelphiInterface<IdxFadingObjectFadingOptions> _di_IdxFadingObjectFadingOptions;
__interface  INTERFACE_UUID("{FAAAF4F8-7F10-42CD-9368-2BB5A1F1482B}") IdxFadingObjectFadingOptions  : public System::IInterface 
{
	
public:
	virtual TdxFadingOptions* __fastcall GetFadingOptions(void) = 0 ;
};

enum TdxFadingState : unsigned char { fsFadeIn, fsFadeOut };

class DELPHICLASS TdxFadingElement;
class DELPHICLASS TdxFader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingElement : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	int FAnimationFrameCount;
	int FAnimationFrameDelay;
	int FDelayCount;
	int FDelayIndex;
	System::TObject* FElement;
	_di_IdxFadingObject FFadingObject;
	System::Types::TSize FImageSize;
	TdxFader* FOwner;
	int FStage;
	Dxgdiplusclasses::TdxGPImage* FWorkImage;
	void __fastcall SetWorkImage(Dxgdiplusclasses::TdxGPImage* AImage);
	
protected:
	Dxcore::TRGBColors FImage1Colors;
	Dxcore::TRGBColors FImage2Colors;
	void __fastcall BuildWorkImage(void);
	void __fastcall CorrectAlphaChannel(Dxcore::TRGBColors &AColors);
	void __fastcall ProcessFadeStep(void);
	void __fastcall SetAnimationParams(int AAnimationFrameCount, int AAnimationFrameDelay);
	void __fastcall SetImages(Vcl::Graphics::TBitmap* AImage1, Vcl::Graphics::TBitmap* AImage2);
	__property System::Types::TSize ImageSize = {read=FImageSize};
	__property TdxFader* Owner = {read=FOwner};
	
public:
	__fastcall TdxFadingElement(TdxFader* AOwner, System::TObject* AElement);
	__fastcall virtual ~TdxFadingElement(void);
	bool __fastcall DrawImage(HDC DC, const System::Types::TRect &R);
	void __fastcall Finalize(void);
	__property int AnimationFrameCount = {read=FAnimationFrameCount, nodefault};
	__property int AnimationFrameDelay = {read=FAnimationFrameDelay, nodefault};
	__property System::TObject* Element = {read=FElement};
	__property Dxgdiplusclasses::TdxGPImage* WorkImage = {read=FWorkImage, write=SetWorkImage};
	__property int Stage = {read=FStage, write=FStage, nodefault};
};

#pragma pack(pop)

class DELPHICLASS TdxFadingObjectHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingObjectHelper : public Dxcoreclasses::TcxIUnknownObject
{
	typedef Dxcoreclasses::TcxIUnknownObject inherited;
	
private:
	bool __fastcall GetActive(void);
	
protected:
	virtual bool __fastcall CanFade(void);
	virtual void __fastcall DrawFadeImage(void);
	virtual void __fastcall GetFadingImages(/* out */ Cxgraphics::TcxBitmap* &AFadeOutImage, /* out */ Cxgraphics::TcxBitmap* &AFadeInImage);
	
public:
	__fastcall virtual ~TdxFadingObjectHelper(void);
	void __fastcall CheckStartFading(Cxlookandfeelpainters::TcxButtonState APrevState, Cxlookandfeelpainters::TcxButtonState AState);
	bool __fastcall DrawImage(HDC DC, const System::Types::TRect &R);
	void __fastcall FadeIn(void);
	void __fastcall FadeOut(void);
	void __fastcall StopFading(void);
	__property bool Active = {read=GetActive, nodefault};
public:
	/* TObject.Create */ inline __fastcall TdxFadingObjectHelper(void) : Dxcoreclasses::TcxIUnknownObject() { }
	
private:
	void *__IdxFadingObject;	/* IdxFadingObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73AB2A92-CDD9-4F13-965A-DC799DE837F9}
	operator _di_IdxFadingObject()
	{
		_di_IdxFadingObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxFadingObject*(void) { return (IdxFadingObject*)&__IdxFadingObject; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TdxFadingList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFadingList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TdxFadingElement* operator[](int Index) { return Items[Index]; }
	
private:
	TdxFadingElement* __fastcall GetItems(int Index);
	
public:
	virtual void __fastcall Clear(void);
	__property TdxFadingElement* Items[int Index] = {read=GetItems/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxFadingList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxFadingList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

enum TdxFaderAnimationState : unsigned char { fasDefault, fasEnabled, fasDisabled };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFader : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxFadingList* FList;
	int FMaxAnimationCount;
	TdxFaderAnimationState FState;
	Vcl::Extctrls::TTimer* FTimer;
	bool __fastcall GetActive(void);
	bool __fastcall GetIsReady(void);
	BOOL __fastcall GetSystemAnimationState(void);
	void __fastcall SetMaxAnimationCount(int Value);
	void __fastcall ValidateQueue(void);
	
protected:
	bool __fastcall CanFade(System::TObject* AObject)/* overload */;
	bool __fastcall CanFade(System::TObject* AObject, /* out */ _di_IdxFadingObject &AFadingObject)/* overload */;
	void __fastcall DoTimer(System::TObject* Sender);
	void __fastcall AddFadingElement(TdxFadingElement* AElement);
	void __fastcall RemoveFadingElement(TdxFadingElement* AElement);
	
public:
	__fastcall TdxFader(void);
	__fastcall virtual ~TdxFader(void);
	void __fastcall Clear(void);
	bool __fastcall Contains(System::TObject* AObject);
	bool __fastcall DrawFadeImage(System::TObject* AObject, HDC DC, const System::Types::TRect &R);
	bool __fastcall Find(System::TObject* AObject, /* out */ TdxFadingElement* &AFadingElement);
	void __fastcall Remove(System::TObject* AObject, bool ADestroying = true);
	void __fastcall Fade(System::TObject* AObject, TdxFadingState AState)/* overload */;
	void __fastcall Fade(System::TObject* AObject, Vcl::Graphics::TBitmap* AImage1, Vcl::Graphics::TBitmap* AImage2, int AAnimationFrameCount, int AAnimationFrameDelay)/* overload */;
	void __fastcall FadeIn(System::TObject* AObject);
	void __fastcall FadeOut(System::TObject* AObject);
	__property bool Active = {read=GetActive, nodefault};
	__property bool IsReady = {read=GetIsReady, nodefault};
	__property int MaxAnimationCount = {read=FMaxAnimationCount, write=SetMaxAnimationCount, nodefault};
	__property TdxFaderAnimationState State = {read=FState, write=FState, nodefault};
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxFadeInDefaultAnimationFrameCount = System::Int8(0x4);
static const System::Int8 dxFadeInDefaultAnimationFrameDelay = System::Int8(0xf);
static const System::Int8 dxFadeOutDefaultAnimationFrameCount = System::Int8(0xc);
static const System::Int8 dxFadeOutDefaultAnimationFrameDelay = System::Int8(0x14);
static const System::Byte dxFadeMaxAlpha = System::Byte(0xff);
static const System::Int8 dxFadeMaxAnimationCount = System::Int8(0x14);
static const System::Int8 dxFadeMaxAnimationFrameCount = System::Int8(0x20);
static const System::Word dxFadeMaxAnimationFrameDelay = System::Word(0x12c);
static const System::Int8 dxFadeTimerInterval = System::Int8(0xa);
extern PACKAGE TdxFader* __fastcall dxFader(void);
}	/* namespace Dxfading */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFADING)
using namespace Dxfading;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfadingHPP
