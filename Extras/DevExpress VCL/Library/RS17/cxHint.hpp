// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxHint.pas' rev: 24.00 (Win32)

#ifndef CxhintHPP
#define CxhintHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxCustomHint.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxhint
{
//-- type declarations -------------------------------------------------------
typedef System::Word TcxHintAnimationDelay;

enum TcxCallOutPosition : unsigned char { cxbpNone, cxbpAuto, cxbpLeftBottom, cxbpLeftTop, cxbpTopLeft, cxbpTopRight, cxbpRightBottom, cxbpRightTop, cxbpBottomRight, cxbpBottomLeft };

enum TcxHintIconType : unsigned char { cxhiNone, cxhiApplication, cxhiInformation, cxhiWarning, cxhiError, cxhiQuestion, cxhiWinLogo, cxhiCurrentApplication, cxhiCustom };

typedef Dxcustomhint::TcxHintAnimationStyle TcxHintAnimate;

enum TcxHintIconSize : unsigned char { cxisDefault, cxisLarge, cxisSmall };

__interface IcxHint;
typedef System::DelphiInterface<IcxHint> _di_IcxHint;
__interface  INTERFACE_UUID("{0680CE5D-391B-45A1-B55D-AFCAE92F2DA6}") IcxHint  : public System::IInterface 
{
	
public:
	virtual Dxcustomhint::TcxHintAnimationStyle __fastcall GetAnimate(void) = 0 ;
	virtual TcxHintAnimationDelay __fastcall GetAnimationDelay(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetBorderColor(void) = 0 ;
	virtual TcxCallOutPosition __fastcall GetCallOutPosition(void) = 0 ;
	virtual System::Uitypes::TColor __fastcall GetColor(void) = 0 ;
	virtual TcxHintIconSize __fastcall GetIconSize(void) = 0 ;
	virtual TcxHintIconType __fastcall GetIconType(void) = 0 ;
	virtual System::UnicodeString __fastcall GetHintCaption(void) = 0 ;
	virtual bool __fastcall GetRounded(void) = 0 ;
	virtual int __fastcall GetRoundRadius(void) = 0 ;
	virtual bool __fastcall GetStandard(void) = 0 ;
	virtual Vcl::Graphics::TFont* __fastcall GetHintFont(void) = 0 ;
	virtual Vcl::Graphics::TFont* __fastcall GetHintCaptionFont(void) = 0 ;
	virtual Vcl::Graphics::TIcon* __fastcall GetHintIcon(void) = 0 ;
	virtual void __fastcall SetHintCaption(System::UnicodeString Value) = 0 ;
	__property System::UnicodeString HintCaption = {read=GetHintCaption, write=SetHintCaption};
};

class DELPHICLASS TcxHintStyle;
class PASCALIMPLEMENTATION TcxHintStyle : public Dxcustomhint::TcxCustomHintStyle
{
	typedef Dxcustomhint::TcxCustomHintStyle inherited;
	
private:
	Dxcustomhint::TcxHintAnimationStyle FAnimate;
	TcxHintAnimationDelay FAnimationDelay;
	TcxCallOutPosition FCallOutPosition;
	System::Uitypes::TColor FBorderColor;
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FFont;
	Vcl::Graphics::TFont* FCaptionFont;
	Vcl::Graphics::TIcon* FIcon;
	TcxHintIconSize FIconSize;
	TcxHintIconType FIconType;
	bool FRounded;
	int FRoundRadius;
	bool FStandard;
	bool FIsDestroying;
	bool FModified;
	int FUpdateCount;
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	void __fastcall SetAnimate(Dxcustomhint::TcxHintAnimationStyle Value);
	void __fastcall SetAnimationDelay(TcxHintAnimationDelay Value);
	void __fastcall SetCallOutPosition(TcxCallOutPosition Value);
	void __fastcall SetBorderColor(System::Uitypes::TColor Value);
	void __fastcall SetCaptionFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetIcon(Vcl::Graphics::TIcon* Value);
	void __fastcall SetIconSize(TcxHintIconSize Value);
	void __fastcall SetIconType(TcxHintIconType Value);
	void __fastcall SetRounded(bool Value);
	void __fastcall SetRoundRadius(int Value);
	void __fastcall SetStandard(bool Value);
	void __fastcall IconChangeHandler(System::TObject* Sender);
	void __fastcall InternalRestoreDefault(void);
	
protected:
	Dxcustomhint::TcxCustomHintStyleController* FHintStyleController;
	Dxcustomhint::TcxCustomHintStyleController* __fastcall BaseGetHintStyleController(void);
	void __fastcall BaseSetHintStyleController(Dxcustomhint::TcxCustomHintStyleController* Value);
	virtual void __fastcall Changed(void);
	virtual void __fastcall ControllerChangedNotification(Dxcustomhint::TcxCustomHintStyleController* AStyleController);
	virtual void __fastcall ControllerFreeNotification(Dxcustomhint::TcxCustomHintStyleController* AHintStyleController);
	virtual void __fastcall HintStyleControllerChanged(void);
	Dxcustomhint::TcxHintAnimationStyle __fastcall GetAnimate(void);
	TcxHintAnimationDelay __fastcall GetAnimationDelay(void);
	System::Uitypes::TColor __fastcall GetBorderColor(void);
	TcxCallOutPosition __fastcall GetCallOutPosition(void);
	System::Uitypes::TColor __fastcall GetColor(void);
	TcxHintIconSize __fastcall GetIconSize(void);
	TcxHintIconType __fastcall GetIconType(void);
	System::UnicodeString __fastcall GetHintCaption(void);
	bool __fastcall GetRounded(void);
	int __fastcall GetRoundRadius(void);
	bool __fastcall GetStandard(void);
	Vcl::Graphics::TFont* __fastcall GetHintFont(void);
	Vcl::Graphics::TFont* __fastcall GetHintCaptionFont(void);
	Vcl::Graphics::TIcon* __fastcall GetHintIcon(void);
	void __fastcall SetHintCaption(System::UnicodeString Value);
	__property Dxcustomhint::TcxCustomHintStyleController* HintStyleController = {read=BaseGetHintStyleController, write=BaseSetHintStyleController};
	__property bool IsDestroying = {read=FIsDestroying, write=FIsDestroying, nodefault};
	
public:
	__fastcall virtual TcxHintStyle(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxHintStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	__classmethod virtual Dxcustomhint::TcxCustomHintStyleController* __fastcall GetDefaultHintStyleController();
	virtual Dxcustomhint::TcxCustomHintWindowClass __fastcall GetHintWindowClass(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Dxcustomhint::TcxHintAnimationStyle Animate = {read=FAnimate, write=SetAnimate, default=8};
	__property TcxHintAnimationDelay AnimationDelay = {read=FAnimationDelay, write=SetAnimationDelay, default=100};
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=SetBorderColor, default=-16777210};
	__property TcxCallOutPosition CallOutPosition = {read=FCallOutPosition, write=SetCallOutPosition, default=0};
	__property Vcl::Graphics::TFont* CaptionFont = {read=FCaptionFont, write=SetCaptionFont};
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=-16777192};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont};
	__property Vcl::Graphics::TIcon* Icon = {read=FIcon, write=SetIcon};
	__property TcxHintIconSize IconSize = {read=FIconSize, write=SetIconSize, default=0};
	__property TcxHintIconType IconType = {read=FIconType, write=SetIconType, default=0};
	__property bool Rounded = {read=FRounded, write=SetRounded, default=0};
	__property int RoundRadius = {read=FRoundRadius, write=SetRoundRadius, default=11};
	__property bool Standard = {read=FStandard, write=SetStandard, default=0};
private:
	void *__IcxHint;	/* IcxHint */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {0680CE5D-391B-45A1-B55D-AFCAE92F2DA6}
	operator _di_IcxHint()
	{
		_di_IcxHint intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxHint*(void) { return (IcxHint*)&__IcxHint; }
	#endif
	
};


class DELPHICLASS TcxHintStyleController;
class PASCALIMPLEMENTATION TcxHintStyleController : public Dxcustomhint::TcxCustomHintStyleController
{
	typedef Dxcustomhint::TcxCustomHintStyleController inherited;
	
protected:
	virtual Dxcustomhint::TcxHintStyleClass __fastcall GetHintStyleClass(void);
	
public:
	int __fastcall GetHintWidth(System::UnicodeString AHint);
	int __fastcall GetHintHeight(System::UnicodeString AHint);
	
__published:
	__property Global = {default=1};
	__property HintStyleClassName = {default=0};
	__property HintStyle;
	__property HintShortPause = {default=50};
	__property HintPause = {default=500};
	__property HintHidePause = {default=2500};
	__property LookAndFeel;
	__property UseHintControlLookAndFeel = {default=0};
	__property OnHintStyleChanged;
	__property OnShowHint;
	__property OnShowHintEx;
public:
	/* TcxCustomHintStyleController.Create */ inline __fastcall virtual TcxHintStyleController(System::Classes::TComponent* AOwner) : Dxcustomhint::TcxCustomHintStyleController(AOwner) { }
	/* TcxCustomHintStyleController.Destroy */ inline __fastcall virtual ~TcxHintStyleController(void) { }
	
};


class DELPHICLASS TcxHintViewInfo;
class DELPHICLASS TcxHintWindow;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxHintViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxCallOutPosition FCalculatedCallOutPos;
	System::Types::TPoint FCalculatedCallOutOffset;
	System::Byte FCallOutSize;
	TcxHintWindow* FOwner;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* FPainter;
	System::Types::TPoint FContentOffset;
	bool FWasAdjust;
	void __fastcall CheckActivateRectSize(System::Types::TRect &ARect);
	System::Uitypes::TColor __fastcall GetBorderColor(void);
	System::UnicodeString __fastcall GetCaption(void);
	Vcl::Graphics::TFont* __fastcall GetCaptionFont(void);
	System::UnicodeString __fastcall GetHint(void);
	System::Uitypes::TColor __fastcall GetHintColor(void);
	Vcl::Graphics::TFont* __fastcall GetHintFont(void);
	int __fastcall GetIconHorzOffset(void);
	int __fastcall GetMaxCaptionWidth(bool AIsCaption = true);
	int __fastcall GetRoundRadius(void);
	void __fastcall GetTextBounds(System::Types::TRect &ARect, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont);
	
protected:
	System::StaticArray<System::Types::TPoint, 3> FCallOutTops;
	System::Types::TPoint FCallOutOrigin;
	System::Types::TRect FCaptionBounds;
	System::Types::TRect FHintBounds;
	System::Types::TRect FHintWindowRect;
	System::Types::TPoint FIconOrigin;
	int FIconSize;
	int FIndentDelta;
	System::Types::TPoint FMargins;
	int FMaxWidth;
	virtual void __fastcall AdjustHintPositionByHintBounds(System::Types::TRect &ARect);
	virtual void __fastcall AdjustHintPositionByPoint(const System::Types::TPoint &APoint, System::Types::TRect &ARect);
	void __fastcall CalculateCallOutPoints(void);
	void __fastcall CalculateCaption(void);
	void __fastcall CalculateHintBoundsOffset(void);
	virtual void __fastcall CalculateIcon(void);
	virtual void __fastcall CalculateMargins(void);
	void __fastcall CalculateTextsBounds(void);
	void __fastcall CalculateWindowRect(void);
	void __fastcall CheckWindowRectSize(void);
	HRGN __fastcall CreateCallOutRegion(System::Types::TRect &R);
	void __fastcall NCPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual TcxCallOutPosition __fastcall GetAutoCallOutPosition(const System::Types::TRect &ARect);
	bool __fastcall NeedCorrectByCursorSize(void);
	void __fastcall OffsetContent(void);
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, nodefault};
	__property System::Byte CallOutSize = {read=FCallOutSize, write=FCallOutSize, nodefault};
	__property System::Types::TPoint CalculatedCallOutOffset = {read=FCalculatedCallOutOffset};
	__property TcxCallOutPosition CalculatedCallOutPos = {read=FCalculatedCallOutPos, nodefault};
	__property System::Uitypes::TColor HintColor = {read=GetHintColor, nodefault};
	__property System::Types::TRect HintWindowRect = {read=FHintWindowRect};
	__property TcxHintWindow* Owner = {read=FOwner};
	__property int RoundRadius = {read=GetRoundRadius, nodefault};
	
public:
	__fastcall TcxHintViewInfo(TcxHintWindow* AOwner);
	void __fastcall AdjustHintRect(System::Types::TRect &ARect);
	virtual System::Types::TRect __fastcall Calculate(int AMaxWidth);
	void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	void __fastcall SetWindowRegion(void);
	__property System::UnicodeString Caption = {read=GetCaption};
	__property System::Types::TRect CaptionBounds = {read=FCaptionBounds};
	__property Vcl::Graphics::TFont* CaptionFont = {read=GetCaptionFont};
	__property System::UnicodeString Hint = {read=GetHint};
	__property System::Types::TRect HintBounds = {read=FHintBounds};
	__property Vcl::Graphics::TFont* HintFont = {read=GetHintFont};
	__property System::Types::TPoint IconOrigin = {read=FIconOrigin};
	__property int IconSize = {read=FIconSize, nodefault};
	__property System::Types::TPoint Margins = {read=FMargins};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxHintViewInfo(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxHintWindow : public Dxcustomhint::TcxCustomHintWindow
{
	typedef Dxcustomhint::TcxCustomHintWindow inherited;
	
private:
	bool FAbsolutePosition;
	TcxCallOutPosition FCallOutPosition;
	System::Uitypes::TColor FBorderColor;
	int FBorderWidth;
	System::Uitypes::TColor FHintColor;
	System::UnicodeString FHint;
	Vcl::Graphics::TFont* FCaptionFont;
	Vcl::Graphics::TIcon* FIcon;
	TcxHintIconSize FIconSize;
	TcxHintIconType FIconType;
	bool FRounded;
	int FRoundRadius;
	bool FWordWrap;
	TcxHintViewInfo* FViewInfo;
	Dxcustomhint::TcxHintAnimationStyle __fastcall GetAnimate(void);
	void __fastcall SetAnimate(Dxcustomhint::TcxHintAnimationStyle AValue);
	void __fastcall SetIcon(Vcl::Graphics::TIcon* Value);
	MESSAGE void __fastcall WMShowWindow(Winapi::Messages::TWMShowWindow &Message);
	
protected:
	virtual void __fastcall AdjustActivateRect(System::Types::TRect &ARect);
	virtual void __fastcall EnableRegion(void);
	virtual void __fastcall CreateBalloonForm(void);
	virtual void __fastcall NCPaint(HDC DC);
	virtual void __fastcall Paint(void);
	virtual void __fastcall CalculateController(void);
	virtual void __fastcall CalculateIcon(void);
	virtual TcxHintViewInfo* __fastcall CreateViewInfo(void);
	virtual bool __fastcall HasWindowRegion(void);
	void __fastcall LoadHintStyleData(const _di_IcxHint AHintData);
	virtual void __fastcall ShowHint(int X, int Y, System::UnicodeString ACaption, System::UnicodeString AHint, int AMaxWidth = 0x0);
	__property bool AbsolutePosition = {read=FAbsolutePosition, write=FAbsolutePosition, nodefault};
	__property System::UnicodeString Hint = {read=FHint};
	__property TcxHintViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxHintWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxHintWindow(void);
	virtual System::Types::TRect __fastcall CalcHintRect(int MaxWidth, const System::UnicodeString AHint, void * AData);
	__property Dxcustomhint::TcxHintAnimationStyle Animate = {read=GetAnimate, write=SetAnimate, nodefault};
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=FBorderColor, nodefault};
	__property TcxCallOutPosition CallOutPosition = {read=FCallOutPosition, write=FCallOutPosition, nodefault};
	__property Vcl::Graphics::TFont* CaptionFont = {read=FCaptionFont, write=FCaptionFont};
	__property Vcl::Graphics::TIcon* Icon = {read=FIcon, write=SetIcon};
	__property TcxHintIconSize IconSize = {read=FIconSize, write=FIconSize, nodefault};
	__property TcxHintIconType IconType = {read=FIconType, write=FIconType, nodefault};
	__property bool Rounded = {read=FRounded, write=FRounded, nodefault};
	__property int RoundRadius = {read=FRoundRadius, write=FRoundRadius, nodefault};
	__property bool WordWrap = {read=FWordWrap, write=FWordWrap, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxHintWindow(HWND ParentWindow) : Dxcustomhint::TcxCustomHintWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxhint */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXHINT)
using namespace Cxhint;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxhintHPP
