// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSplitter.pas' rev: 24.00 (Win64)

#ifndef CxsplitterHPP
#define CxsplitterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxExtEditConsts.hpp>	// Pascal unit
#include <cxExtEditUtils.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxsplitter
{
//-- type declarations -------------------------------------------------------
typedef int TcxPositionAfterOpen;

enum TcxSplitterAlign : unsigned char { salBottom, salLeft, salRight, salTop };

enum TcxSplitterDragState : unsigned char { sstNormal, sstResizing, sstHotZoneClick };

enum TcxSplitterMouseState : unsigned char { smsClicked, smsInHotZone };

typedef System::Set<TcxSplitterMouseState, TcxSplitterMouseState::smsClicked, TcxSplitterMouseState::smsInHotZone>  TcxSplitterMouseStates;

enum TcxSplitterState : unsigned char { ssOpened, ssClosed };

enum TcxSplitterDirection : unsigned char { cxsdLeftToRight, cxsdRightToLeft, cxsdTopToBottom, cxsdBottomToTop };

typedef void __fastcall (__closure *TCanResizeEvent)(System::TObject* Sender, int &NewSize, bool &Accept);

typedef void __fastcall (__closure *TBeforeOpenHotZoneEvent)(System::TObject* Sender, int &NewSize, bool &AllowOpen);

typedef void __fastcall (__closure *TBeforeCloseHotZoneEvent)(System::TObject* Sender, bool &AllowClose);

class DELPHICLASS TcxHotZoneStyle;
class DELPHICLASS TcxCustomSplitter;
class PASCALIMPLEMENTATION TcxHotZoneStyle : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxCustomSplitter* FOwner;
	Cxexteditconsts::TcxNaturalNumber FSizePercent;
	bool FVisible;
	System::Types::TRect FHotZoneRect;
	void __fastcall SetSizePercent(Cxexteditconsts::TcxNaturalNumber Value);
	void __fastcall SetVisible(bool Value);
	
protected:
	virtual void __fastcall Changed(void);
	virtual TcxSplitterDirection __fastcall SplitterDirection(void);
	virtual System::Types::TRect __fastcall CalculateHotZoneRect(const System::Types::TRect &ABounds);
	virtual Cxexteditconsts::TcxNaturalNumber __fastcall GetMinSize(void);
	virtual Cxexteditconsts::TcxNaturalNumber __fastcall GetMaxSize(void);
	virtual System::Types::TRect __fastcall DrawHotZone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	
public:
	__fastcall virtual TcxHotZoneStyle(TcxCustomSplitter* AOwner);
	__fastcall virtual ~TcxHotZoneStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property Cxexteditconsts::TcxNaturalNumber SizePercent = {read=FSizePercent, write=SetSizePercent, default=30};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property System::Types::TRect HotZoneRect = {read=FHotZoneRect, write=FHotZoneRect};
	__property TcxCustomSplitter* Owner = {read=FOwner};
};


typedef System::TMetaClass* TcxHotZoneStyleClass;

class DELPHICLASS TcxMediaPlayer9Style;
class PASCALIMPLEMENTATION TcxMediaPlayer9Style : public TcxHotZoneStyle
{
	typedef TcxHotZoneStyle inherited;
	
private:
	System::Types::TRect FArrowRect;
	System::Uitypes::TColor FArrowColor;
	System::Uitypes::TColor FArrowHighlightColor;
	System::Uitypes::TColor FLightColor;
	System::Uitypes::TColor FBorderColor;
	System::Uitypes::TColor FShadowStartColor;
	System::Uitypes::TColor FShadowHighlightStartColor;
	void __fastcall SetArrowColor(System::Uitypes::TColor Value);
	void __fastcall SetArrowHighlightColor(System::Uitypes::TColor Value);
	void __fastcall SetLightColor(System::Uitypes::TColor Value);
	void __fastcall SetBorderColor(System::Uitypes::TColor Value);
	void __fastcall SetShadowStartColor(System::Uitypes::TColor Value);
	void __fastcall SetShadowHighlightStartColor(System::Uitypes::TColor Value);
	
protected:
	virtual System::Types::TRect __fastcall CalculateHotZoneRect(const System::Types::TRect &ABounds);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	virtual System::Types::TRect __fastcall DrawHotZone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	
public:
	__fastcall virtual TcxMediaPlayer9Style(TcxCustomSplitter* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property SizePercent = {default=30};
	__property Visible = {default=1};
	__property System::Uitypes::TColor ArrowColor = {read=FArrowColor, write=SetArrowColor, default=-16777208};
	__property System::Uitypes::TColor ArrowHighlightColor = {read=FArrowHighlightColor, write=SetArrowHighlightColor, default=16711680};
	__property System::Uitypes::TColor LightColor = {read=FLightColor, write=SetLightColor, default=-16777211};
	__property System::Uitypes::TColor BorderColor = {read=FBorderColor, write=SetBorderColor, default=-16777200};
	__property System::Uitypes::TColor ShadowStartColor = {read=FShadowStartColor, write=SetShadowStartColor, default=16115405};
	__property System::Uitypes::TColor ShadowHighlightStartColor = {read=FShadowHighlightStartColor, write=SetShadowHighlightStartColor, default=11531715};
public:
	/* TcxHotZoneStyle.Destroy */ inline __fastcall virtual ~TcxMediaPlayer9Style(void) { }
	
};


class DELPHICLASS TcxMediaPlayer8Style;
class PASCALIMPLEMENTATION TcxMediaPlayer8Style : public TcxHotZoneStyle
{
	typedef TcxHotZoneStyle inherited;
	
private:
	System::Uitypes::TColor FArrowColor;
	System::Uitypes::TColor FArrowHighlightColor;
	System::Types::TRect FArrowRect;
	System::Uitypes::TColor FLightColor;
	System::Types::TRect FLTPointsRect;
	System::Types::TRect FRBPointsRect;
	System::Uitypes::TColor FShadowColor;
	void __fastcall SetArrowColor(System::Uitypes::TColor Value);
	void __fastcall SetArrowHighlightColor(System::Uitypes::TColor Value);
	void __fastcall SetLightColor(System::Uitypes::TColor Value);
	void __fastcall SetShadowColor(System::Uitypes::TColor Value);
	void __fastcall DrawArrowRect(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	
protected:
	virtual System::Types::TRect __fastcall CalculateHotZoneRect(const System::Types::TRect &ABounds);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	virtual System::Types::TRect __fastcall DrawHotZone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	
public:
	__fastcall virtual TcxMediaPlayer8Style(TcxCustomSplitter* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property SizePercent = {default=30};
	__property Visible = {default=1};
	__property System::Uitypes::TColor ArrowColor = {read=FArrowColor, write=SetArrowColor, default=-16777208};
	__property System::Uitypes::TColor ArrowHighlightColor = {read=FArrowHighlightColor, write=SetArrowHighlightColor, default=-16777211};
	__property System::Uitypes::TColor LightColor = {read=FLightColor, write=SetLightColor, default=-16777211};
	__property System::Uitypes::TColor ShadowColor = {read=FShadowColor, write=SetShadowColor, default=-16777200};
public:
	/* TcxHotZoneStyle.Destroy */ inline __fastcall virtual ~TcxMediaPlayer8Style(void) { }
	
};


class DELPHICLASS TcxXPTaskBarStyle;
class PASCALIMPLEMENTATION TcxXPTaskBarStyle : public TcxHotZoneStyle
{
	typedef TcxHotZoneStyle inherited;
	
private:
	System::Uitypes::TColor FLightColor;
	System::Types::TRect FLTPointsRect;
	System::Types::TRect FRBPointsRect;
	System::Uitypes::TColor FShadowColor;
	void __fastcall SetLightColor(System::Uitypes::TColor Value);
	void __fastcall SetShadowColor(System::Uitypes::TColor Value);
	
protected:
	virtual System::Types::TRect __fastcall CalculateHotZoneRect(const System::Types::TRect &ABounds);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	virtual System::Types::TRect __fastcall DrawHotZone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	
public:
	__fastcall virtual TcxXPTaskBarStyle(TcxCustomSplitter* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property SizePercent = {default=30};
	__property Visible = {default=1};
	__property System::Uitypes::TColor LightColor = {read=FLightColor, write=SetLightColor, default=-16777211};
	__property System::Uitypes::TColor ShadowColor = {read=FShadowColor, write=SetShadowColor, default=-16777200};
public:
	/* TcxHotZoneStyle.Destroy */ inline __fastcall virtual ~TcxXPTaskBarStyle(void) { }
	
};


class DELPHICLASS TcxSimpleStyle;
class PASCALIMPLEMENTATION TcxSimpleStyle : public TcxHotZoneStyle
{
	typedef TcxHotZoneStyle inherited;
	
private:
	System::Uitypes::TColor FArrowColor;
	System::Uitypes::TColor FArrowHighlightColor;
	System::Uitypes::TColor FDotsColor;
	System::Uitypes::TColor FDotsShadowColor;
	System::Uitypes::TColor FLightColor;
	System::Types::TRect FLTArrowRect;
	System::Types::TRect FRBArrowRect;
	System::Uitypes::TColor FShadowColor;
	void __fastcall SetArrowColor(System::Uitypes::TColor Value);
	void __fastcall SetArrowHighlightColor(System::Uitypes::TColor Value);
	void __fastcall SetDotsColor(System::Uitypes::TColor Value);
	void __fastcall SetDotsShadowColor(System::Uitypes::TColor Value);
	void __fastcall SetLightColor(System::Uitypes::TColor Value);
	void __fastcall SetShadowColor(System::Uitypes::TColor Value);
	
protected:
	virtual System::Types::TRect __fastcall CalculateHotZoneRect(const System::Types::TRect &ABounds);
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	virtual System::Types::TRect __fastcall DrawHotZone(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, const bool AHighlighted, const bool AClicked);
	
public:
	__fastcall virtual TcxSimpleStyle(TcxCustomSplitter* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property SizePercent = {default=30};
	__property Visible = {default=1};
	__property System::Uitypes::TColor ArrowColor = {read=FArrowColor, write=SetArrowColor, default=-16777208};
	__property System::Uitypes::TColor ArrowHighlightColor = {read=FArrowHighlightColor, write=SetArrowHighlightColor, default=-16777211};
	__property System::Uitypes::TColor LightColor = {read=FLightColor, write=SetLightColor, default=-16777211};
	__property System::Uitypes::TColor ShadowColor = {read=FShadowColor, write=SetShadowColor, default=-16777200};
	__property System::Uitypes::TColor DotsColor = {read=FDotsColor, write=SetDotsColor, default=-16777203};
	__property System::Uitypes::TColor DotsShadowColor = {read=FDotsShadowColor, write=SetDotsShadowColor, default=-16777211};
public:
	/* TcxHotZoneStyle.Destroy */ inline __fastcall virtual ~TcxSimpleStyle(void) { }
	
};


class DELPHICLASS TdxSplitterDragImage;
class PASCALIMPLEMENTATION TdxSplitterDragImage : public Cxcontrols::TcxCustomDragImage
{
	typedef Cxcontrols::TcxCustomDragImage inherited;
	
protected:
	DYNAMIC void __fastcall Paint(void);
public:
	/* TcxCustomDragImage.Create */ inline __fastcall virtual TdxSplitterDragImage(void) : Cxcontrols::TcxCustomDragImage() { }
	/* TcxCustomDragImage.Destroy */ inline __fastcall virtual ~TdxSplitterDragImage(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxSplitterDragImage(System::Classes::TComponent* AOwner, int Dummy) : Cxcontrols::TcxCustomDragImage(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxSplitterDragImage(HWND ParentWindow) : Cxcontrols::TcxCustomDragImage(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomSplitter : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	Vcl::Controls::TWinControl* FActiveControl;
	TcxSplitterAlign FAlignSplitter;
	bool FAllowHotZoneDrag;
	bool FAutoPosition;
	bool FAutoSnap;
	Vcl::Controls::TControl* FControl;
	TdxSplitterDragImage* FDragImage;
	Cxexteditconsts::TcxNaturalNumber FDragThreshold;
	TcxHotZoneStyle* FHotZone;
	System::Types::TPoint FHotZoneClickPoint;
	System::Classes::TNotifyEvent FHotZoneEvents;
	TcxHotZoneStyleClass FHotZoneStyleClass;
	bool FInvertDirection;
	int FLastPatternDrawPosition;
	System::Word FMaxSize;
	Cxexteditconsts::TcxNaturalNumber FMinSize;
	TcxSplitterMouseStates FMouseStates;
	bool FNativeBackground;
	int FNewSize;
	int FOldSize;
	TcxPositionAfterOpen FPositionAfterOpen;
	bool FResizeIgnoreSnap;
	bool FResizeUpdate;
	bool FSavedParentShowHint;
	bool FSavedShowHint;
	int FSplit;
	System::Types::TPoint FSplitterClickPoint;
	TcxSplitterDragState FSplitterState;
	TcxSplitterState FState;
	System::Classes::TNotifyEvent FOnAfterClose;
	System::Classes::TNotifyEvent FOnAfterOpen;
	TBeforeCloseHotZoneEvent FOnBeforeClose;
	TBeforeOpenHotZoneEvent FOnBeforeOpen;
	TCanResizeEvent FOnCanResize;
	System::Classes::TNotifyEvent FOnMoved;
	Vcl::Controls::TKeyEvent FPrevKeyDown;
	void __fastcall CalcSplitSize(int X, int Y, int &ANewSize, int &ASplit, bool ACorrectWithMaxMin = true);
	void __fastcall ClearConstraints(void);
	void __fastcall ControlResizing(int X, int Y);
	void __fastcall CorrectSelfPosition(void);
	Vcl::Controls::TControl* __fastcall FindControl(void);
	void __fastcall FocusKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	int __fastcall GetMaxControlSize(void);
	bool __fastcall IsAllControlHotZoneStyle(void);
	void __fastcall UpdateControlSize(void);
	void __fastcall UpdateSize(int X, int Y);
	System::Types::TPoint __fastcall GetDragImageTopLeft(void);
	void __fastcall InitDragImage(void);
	void __fastcall MoveDragImage(void);
	void __fastcall ReleaseDragImage(void);
	void __fastcall SetAlignSplitter(TcxSplitterAlign Value);
	void __fastcall SetAllowHotZoneDrag(bool Value);
	void __fastcall SetControl(Vcl::Controls::TControl* Value);
	void __fastcall SetSplitterState(TcxSplitterState Value);
	void __fastcall SetInvertDirection(bool Value);
	void __fastcall SetHotZone(TcxHotZoneStyle* Value);
	void __fastcall SetNativeBackground(bool Value);
	void __fastcall SetDefaultStates(void);
	void __fastcall RecalcLastPosition(void);
	void __fastcall NormalizeSplitterSize(void);
	void __fastcall SetHotZoneStyleClass(TcxHotZoneStyleClass Value);
	System::UnicodeString __fastcall GetHotZoneClassName(void);
	void __fastcall SetHotZoneClassName(System::UnicodeString Value);
	void __fastcall InitResize(int X, int Y);
	void __fastcall InternalOpenSplitter(int ANewSize = 0x0);
	void __fastcall InternalCloseSplitter(void);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMCancelMode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	
protected:
	Cxgraphics::TcxBitmap* FDrawBitmap;
	int FPositionBeforeClose;
	virtual void __fastcall Notification(System::Classes::TComponent* ACOmponent, System::Classes::TOperation Operation);
	virtual void __fastcall Loaded(void);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall Paint(void);
	HIDESBASE virtual bool __fastcall CanResize(int &NewSize);
	HIDESBASE virtual bool __fastcall DoCanResize(int &NewSize);
	virtual void __fastcall HotZoneStyleChanged(void);
	virtual void __fastcall DrawHotZone(void);
	virtual void __fastcall StopSizing(void);
	virtual Cxexteditconsts::TcxNaturalNumber __fastcall GetSplitterMinSize(void);
	virtual Cxexteditconsts::TcxNaturalNumber __fastcall GetSplitterMaxSize(void);
	virtual void __fastcall CreateHotZone(void);
	virtual void __fastcall DestroyHotZone(void);
	virtual void __fastcall DoEventBeforeOpen(int &ANewSize, bool &AllowOpenHotZone);
	virtual void __fastcall DoEventAfterOpen(void);
	virtual void __fastcall DoEventBeforeClose(bool &AllowCloseHotZone);
	virtual void __fastcall DoEventAfterClose(void);
	virtual void __fastcall DoEventMoved(void);
	int __fastcall InternalGetMinSize(void);
	virtual TcxSplitterDirection __fastcall CalculateSplitterDirection(void);
	virtual void __fastcall UpdateMouseStates(int X, int Y);
	__property TcxSplitterAlign AlignSplitter = {read=FAlignSplitter, write=SetAlignSplitter, default=1};
	__property bool AutoPosition = {read=FAutoPosition, write=FAutoPosition, default=1};
	__property bool AutoSnap = {read=FAutoSnap, write=FAutoSnap, default=0};
	__property bool AllowHotZoneDrag = {read=FAllowHotZoneDrag, write=SetAllowHotZoneDrag, default=1};
	__property Vcl::Controls::TControl* Control = {read=FControl, write=SetControl};
	__property Cxexteditconsts::TcxNaturalNumber DragThreshold = {read=FDragThreshold, write=FDragThreshold, default=3};
	__property bool InvertDirection = {read=FInvertDirection, write=SetInvertDirection, default=0};
	__property Cxexteditconsts::TcxNaturalNumber MinSize = {read=FMinSize, write=FMinSize, default=30};
	__property bool NativeBackground = {read=FNativeBackground, write=SetNativeBackground, default=1};
	__property TcxPositionAfterOpen PositionAfterOpen = {read=FPositionAfterOpen, write=FPositionAfterOpen, default=30};
	__property bool ResizeUpdate = {read=FResizeUpdate, write=FResizeUpdate, default=0};
	__property bool ResizeIgnoreSnap = {read=FResizeIgnoreSnap, write=FResizeIgnoreSnap, stored=false, nodefault};
	__property TCanResizeEvent OnCanResize = {read=FOnCanResize, write=FOnCanResize};
	__property System::Classes::TNotifyEvent OnMoved = {read=FOnMoved, write=FOnMoved};
	__property TBeforeOpenHotZoneEvent OnBeforeOpen = {read=FOnBeforeOpen, write=FOnBeforeOpen};
	__property System::Classes::TNotifyEvent OnAfterOpen = {read=FOnAfterOpen, write=FOnAfterOpen};
	__property TBeforeCloseHotZoneEvent OnBeforeClose = {read=FOnBeforeClose, write=FOnBeforeClose};
	__property System::Classes::TNotifyEvent OnAfterClose = {read=FOnAfterClose, write=FOnAfterClose};
	
public:
	__fastcall virtual TcxCustomSplitter(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomSplitter(void);
	void __fastcall OpenSplitter(void);
	void __fastcall CloseSplitter(void);
	bool __fastcall IsPointInHotZone(const int X, const int Y);
	bool __fastcall IsPointInSplitter(const int X, const int Y);
	__property TcxSplitterState State = {read=FState, write=SetSplitterState, nodefault};
	__property TcxHotZoneStyleClass HotZoneStyleClass = {read=FHotZoneStyleClass, write=SetHotZoneStyleClass};
	__property TcxSplitterDirection Direction = {read=CalculateSplitterDirection, nodefault};
	
__published:
	__property System::UnicodeString HotZoneClassName = {read=GetHotZoneClassName, write=SetHotZoneClassName};
	__property TcxHotZoneStyle* HotZone = {read=FHotZone, write=SetHotZone};
	__property System::Classes::TNotifyEvent HotZoneEvents = {read=FHotZoneEvents, write=FHotZoneEvents};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomSplitter(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
};


class DELPHICLASS TcxSplitter;
class PASCALIMPLEMENTATION TcxSplitter : public TcxCustomSplitter
{
	typedef TcxCustomSplitter inherited;
	
__published:
	__property AlignSplitter = {default=1};
	__property AllowHotZoneDrag = {default=1};
	__property AutoPosition = {default=1};
	__property DragThreshold = {default=3};
	__property NativeBackground = {default=1};
	__property PositionAfterOpen = {default=30};
	__property AutoSnap = {default=0};
	__property InvertDirection = {default=0};
	__property MinSize = {default=30};
	__property ResizeUpdate = {default=0};
	__property ResizeIgnoreSnap;
	__property Control;
	__property OnCanResize;
	__property OnMoved;
	__property OnBeforeOpen;
	__property OnAfterOpen;
	__property OnBeforeClose;
	__property OnAfterClose;
	__property Color = {default=-16777211};
	__property ShowHint;
	__property ParentColor = {default=1};
	__property ParentShowHint = {default=1};
	__property Visible = {default=1};
public:
	/* TcxCustomSplitter.Create */ inline __fastcall virtual TcxSplitter(System::Classes::TComponent* AOwner) : TcxCustomSplitter(AOwner) { }
	/* TcxCustomSplitter.Destroy */ inline __fastcall virtual ~TcxSplitter(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxSplitter(HWND ParentWindow) : TcxCustomSplitter(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Cxclasses::TcxRegisteredClasses* __fastcall GetRegisteredHotZoneStyles(void);
}	/* namespace Cxsplitter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSPLITTER)
using namespace Cxsplitter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxsplitterHPP
