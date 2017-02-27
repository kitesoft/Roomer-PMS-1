// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxContainer.pas' rev: 24.00 (Win64)

#ifndef CxcontainerHPP
#define CxcontainerHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxTouch.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcontainer
{
//-- type declarations -------------------------------------------------------
enum TcxContainerHotState : unsigned char { chsNoHotTrack, chsNormal, chsSelected };

enum TcxContainerStateItem : unsigned char { csNormal, csActive, csDisabled, csHotTrack };

typedef System::Set<TcxContainerStateItem, TcxContainerStateItem::csNormal, TcxContainerStateItem::csHotTrack>  TcxContainerState;

enum TcxMouseButton : unsigned char { cxmbNone, cxmbLeft, cxmbRight, cxmbMiddle };

typedef System::Int8 TcxContainerStyleValue;

typedef System::Set<TcxContainerStyleValue, 0, 31>  TcxContainerStyleValues;

typedef System::StaticArray<System::UnicodeString, 10> Cxcontainer__1;

typedef System::TMetaClass* TcxContainerClass;

class DELPHICLASS TcxContainerViewInfo;
class DELPHICLASS TcxContainerStyle;
class PASCALIMPLEMENTATION TcxContainerViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Uitypes::TColor FBackgroundColor;
	
protected:
	bool FCalculated;
	virtual void __fastcall DrawBorder(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	virtual Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall GetContainerBorderStyle(void);
	virtual void __fastcall InternalPaint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall SetBackgroundColor(System::Uitypes::TColor Value);
	
public:
	System::Uitypes::TColor BorderColor;
	System::Types::TRect BorderRect;
	Cxlookandfeelpainters::TcxContainerBorderStyle BorderStyle;
	int BorderWidth;
	System::Types::TRect Bounds;
	System::Types::TRect ClientRect;
	TcxContainerState ContainerState;
	Cxgraphics::TcxBorders Edges;
	TcxContainerHotState HotState;
	int NativePart;
	int NativeState;
	bool NativeStyle;
	System::TObject* Owner;
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* Painter;
	bool Shadow;
	Dxthememanager::TdxThemedObjectType ThemedObjectType;
	bool UseSkins;
	__fastcall virtual TcxContainerViewInfo(void);
	virtual void __fastcall Assign(System::TObject* Source);
	virtual Cxgraphics::TcxRegion* __fastcall GetUpdateRegion(TcxContainerViewInfo* AViewInfo);
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall UpdateStyle(TcxContainerStyle* AStyle);
	__property System::Uitypes::TColor BackgroundColor = {read=FBackgroundColor, write=SetBackgroundColor, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxContainerViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxContainerViewInfoClass;

struct DECLSPEC_DRECORD TcxContainerStyleData
{
public:
	System::Uitypes::TColor Color;
	Vcl::Graphics::TFont* Font;
	System::Uitypes::TColor FontColor;
};


class DELPHICLASS TcxStyleController;
class DELPHICLASS TcxContainer;
class PASCALIMPLEMENTATION TcxContainerStyle : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	System::Uitypes::TColor FBorderColor;
	Cxlookandfeelpainters::TcxContainerBorderStyle FBorderStyle;
	Cxgraphics::TcxBorders FEdges;
	bool FHotTrack;
	bool FShadow;
	bool FTransparentBorder;
	bool FDirectAccessMode;
	int FFontAssignedValueLockCount;
	bool FIsDestroying;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	bool FModified;
	System::Classes::TPersistent* FOwner;
	TcxContainerStyle* FParentStyle;
	TcxContainerStateItem FState;
	System::Uitypes::TFontStyles FTextStyle;
	int FUpdateCount;
	Vcl::Graphics::TFont* FVisibleFont;
	System::Classes::TNotifyEvent FOnChanged;
	TcxContainerStyleValues __fastcall GetAssignedValues(void);
	System::Uitypes::TColor __fastcall GetBorderColor(void);
	Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall GetBorderStyle(void);
	Cxgraphics::TcxBorders __fastcall GetEdges(void);
	Vcl::Graphics::TFont* __fastcall GetFont(void);
	bool __fastcall GetHotTrack(void);
	bool __fastcall GetShadow(void);
	bool __fastcall GetTransparentBorder(void);
	bool __fastcall InternalGetBorderColor(System::Uitypes::TColor &BorderColor);
	bool __fastcall InternalGetBorderStyle(Cxlookandfeelpainters::TcxContainerBorderStyle &BorderStyle);
	bool __fastcall InternalGetEdges(Cxgraphics::TcxBorders &Edges);
	bool __fastcall InternalGetFont(Vcl::Graphics::TFont* &Font);
	bool __fastcall InternalGetHotTrack(bool &HotTrack);
	bool __fastcall InternalGetShadow(bool &Shadow);
	bool __fastcall InternalGetTextColor(System::Uitypes::TColor &TextColor);
	bool __fastcall InternalGetTextStyle(System::Uitypes::TFontStyles &TextStyle);
	bool __fastcall InternalGetTransparentBorder(bool &TransparentBorder);
	bool __fastcall IsBorderColorStored(void);
	bool __fastcall IsBorderStyleStored(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsEdgesStored(void);
	bool __fastcall IsFontStored(void);
	bool __fastcall IsHotTrackStored(void);
	bool __fastcall IsShadowStored(void);
	bool __fastcall IsStyleControllerStored(void);
	bool __fastcall IsTextColorStored(void);
	bool __fastcall IsTextStyleStored(void);
	bool __fastcall IsTransparentBorderStored(void);
	void __fastcall SetAssignedValues(TcxContainerStyleValues Value);
	void __fastcall SetBorderColor(System::Uitypes::TColor Value);
	void __fastcall SetBorderStyle(Cxlookandfeelpainters::TcxContainerBorderStyle Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetEdges(Cxgraphics::TcxBorders Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetHotTrack(bool Value);
	void __fastcall SetShadow(bool Value);
	void __fastcall SetTextColor(System::Uitypes::TColor Value);
	void __fastcall SetTextStyle(System::Uitypes::TFontStyles Value);
	void __fastcall SetTransparentBorder(bool Value);
	void __fastcall CheckChanges(void);
	void __fastcall CreateFont(void);
	TcxStyleController* __fastcall GetActiveStyleController(void);
	TcxContainerStyle* __fastcall GetBaseStyle(void);
	TcxContainer* __fastcall GetContainer(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	void __fastcall ReadIsFontAssigned(System::Classes::TReader* Reader);
	void __fastcall RestoreFont(Vcl::Graphics::TFont* AFont);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall UpdateVisibleFont(void);
	void __fastcall WriteIsFontAssigned(System::Classes::TWriter* Writer);
	
protected:
	TcxContainerStyleValues FAssignedValues;
	TcxStyleController* FStyleController;
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	TcxStyleController* __fastcall BaseGetStyleController(void);
	void __fastcall BaseSetStyleController(TcxStyleController* Value);
	virtual void __fastcall Changed(void);
	virtual void __fastcall ControllerChangedNotification(TcxStyleController* AStyleController);
	virtual void __fastcall ControllerFreeNotification(TcxStyleController* AStyleController);
	virtual System::Uitypes::TColor __fastcall DefaultBorderColor(void);
	virtual Cxlookandfeelpainters::TcxContainerBorderStyle __fastcall DefaultBorderStyle(void);
	virtual System::Uitypes::TColor __fastcall DefaultColor(void);
	virtual Cxgraphics::TcxBorders __fastcall DefaultEdges(void);
	virtual bool __fastcall DefaultHotTrack(void);
	virtual bool __fastcall DefaultShadow(void);
	virtual System::Uitypes::TColor __fastcall DefaultTextColor(void);
	virtual System::Uitypes::TFontStyles __fastcall DefaultTextStyle(void);
	virtual bool __fastcall DefaultTransparentBorder(void);
	virtual void __fastcall FontChanged(System::TObject* Sender);
	virtual System::Uitypes::TColor __fastcall GetColor(void);
	virtual TcxStyleController* __fastcall GetDefaultStyleController(void);
	virtual System::Uitypes::TColor __fastcall GetStyleColor(void);
	virtual System::Uitypes::TColor __fastcall GetTextColor(void);
	virtual System::Uitypes::TFontStyles __fastcall GetTextStyle(void);
	bool __fastcall InternalGetColor(System::Uitypes::TColor &Color);
	virtual TcxContainerStyleValues __fastcall InternalGetNotPublishedExtendedStyleValues(void);
	bool __fastcall IsBaseStyle(void);
	bool __fastcall IsDestroying(void);
	bool __fastcall IsFontAssignedValueLocked(void);
	void __fastcall LockFontAssignedValue(bool ALock);
	void __fastcall UpdateFont(void);
	__property TcxContainerStyle* ParentStyle = {read=FParentStyle};
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
public:
	TcxContainerStyleData StyleData;
	__fastcall virtual TcxContainerStyle(System::Classes::TPersistent* AOwner, bool ADirectAccessMode, TcxContainerStyle* AParentStyle, TcxContainerStateItem AState);
	__fastcall virtual ~TcxContainerStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	bool __fastcall GetStyleValue(const System::UnicodeString APropertyName, /* out */ TcxContainerStyleValue &StyleValue);
	virtual int __fastcall GetStyleValueCount(void);
	virtual bool __fastcall GetStyleValueName(TcxContainerStyleValue AStyleValue, /* out */ System::UnicodeString &StyleValueName);
	Vcl::Graphics::TFont* __fastcall GetVisibleFont(void);
	virtual bool __fastcall HasBorder(void);
	bool __fastcall IsExtendedStylePropertyPublished(const System::UnicodeString APropertyName);
	virtual bool __fastcall IsValueAssigned(TcxContainerStyleValue AValue);
	virtual void __fastcall RestoreDefaults(void);
	__property TcxStyleController* ActiveStyleController = {read=GetActiveStyleController};
	__property TcxContainerStyle* BaseStyle = {read=GetBaseStyle};
	__property TcxContainer* Container = {read=GetContainer};
	__property bool DirectAccessMode = {read=FDirectAccessMode, nodefault};
	__property TcxContainerStateItem State = {read=FState, nodefault};
	
__published:
	__property TcxContainerStyleValues AssignedValues = {read=GetAssignedValues, write=SetAssignedValues, stored=false, nodefault};
	__property System::Uitypes::TColor BorderColor = {read=GetBorderColor, write=SetBorderColor, stored=IsBorderColorStored, nodefault};
	__property Cxlookandfeelpainters::TcxContainerBorderStyle BorderStyle = {read=GetBorderStyle, write=SetBorderStyle, stored=IsBorderStyleStored, nodefault};
	__property System::Uitypes::TColor Color = {read=GetColor, write=SetColor, stored=IsColorStored, nodefault};
	__property Cxgraphics::TcxBorders Edges = {read=GetEdges, write=SetEdges, stored=IsEdgesStored, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=GetFont, write=SetFont, stored=IsFontStored};
	__property bool HotTrack = {read=GetHotTrack, write=SetHotTrack, stored=IsHotTrackStored, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel, write=SetLookAndFeel};
	__property bool Shadow = {read=GetShadow, write=SetShadow, stored=IsShadowStored, nodefault};
	__property TcxStyleController* StyleController = {read=BaseGetStyleController, write=BaseSetStyleController, stored=IsStyleControllerStored};
	__property System::Uitypes::TColor TextColor = {read=GetTextColor, write=SetTextColor, stored=IsTextColorStored, nodefault};
	__property System::Uitypes::TFontStyles TextStyle = {read=GetTextStyle, write=SetTextStyle, stored=IsTextStyleStored, nodefault};
	__property bool TransparentBorder = {read=GetTransparentBorder, write=SetTransparentBorder, stored=IsTransparentBorderStored, nodefault};
private:
	void *__IdxSkinSupport;	/* Cxlookandfeels::IdxSkinSupport */
	
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
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IdxSkinSupport; }
	#endif
	
};


typedef TcxContainerStyle TcxCustomContainerStyle;

typedef System::TMetaClass* TcxContainerStyleClass;

class DELPHICLASS TcxContainerStyles;
class PASCALIMPLEMENTATION TcxContainerStyles : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxContainerStyle* operator[](TcxContainerStateItem AState) { return Styles[AState]; }
	
private:
	System::StaticArray<TcxContainerStyle*, 4> FStyles;
	TcxContainerStyle* __fastcall GetStyle(TcxContainerStateItem AState);
	TcxContainerStyle* __fastcall GetStyleDisabled(void);
	TcxContainerStyle* __fastcall GetStyleFocused(void);
	TcxContainerStyle* __fastcall GetStyleHot(void);
	TcxContainerStyle* __fastcall GetStyleNormal(void);
	void __fastcall SetOnChanged(System::Classes::TNotifyEvent Value);
	void __fastcall SetStyle(TcxContainerStateItem AState, TcxContainerStyle* Value);
	void __fastcall SetStyleDisabled(TcxContainerStyle* Value);
	void __fastcall SetStyleFocused(TcxContainerStyle* Value);
	void __fastcall SetStyleHot(TcxContainerStyle* Value);
	void __fastcall SetStyleNormal(TcxContainerStyle* Value);
	
public:
	__fastcall virtual TcxContainerStyles(System::Classes::TPersistent* AOwner, TcxContainerStyleClass AStyleClass);
	__fastcall virtual ~TcxContainerStyles(void);
	void __fastcall RestoreDefaults(void);
	__property TcxContainerStyle* Style = {read=GetStyleNormal, write=SetStyleNormal};
	__property TcxContainerStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxContainerStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxContainerStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property TcxContainerStyle* Styles[TcxContainerStateItem AState] = {read=GetStyle, write=SetStyle/*, default*/};
	__property System::Classes::TNotifyEvent OnChanged = {write=SetOnChanged};
};


typedef System::TMetaClass* TcxContainerStylesClass;

class PASCALIMPLEMENTATION TcxStyleController : public Cxclasses::TcxScalableComponent
{
	typedef Cxclasses::TcxScalableComponent inherited;
	
private:
	bool FIsDestruction;
	System::Classes::TList* FListeners;
	System::Classes::TNotifyEvent FOnStyleChanged;
	TcxStyleController* __fastcall GetFakeStyleController(void);
	TcxContainerStyle* __fastcall GetStyle(void);
	TcxContainerStyle* __fastcall GetInternalStyle(TcxContainerStateItem AState);
	void __fastcall SetFakeStyleController(TcxStyleController* Value);
	void __fastcall SetInternalStyle(TcxContainerStateItem AState, TcxContainerStyle* Value);
	void __fastcall StyleChanged(System::TObject* Sender);
	
protected:
	TcxContainerStyles* FStyles;
	virtual void __fastcall Loaded(void);
	virtual void __fastcall ChangeScale(int M, int D);
	virtual void __fastcall AddListener(TcxContainerStyle* AListener);
	void __fastcall Changed(void);
	virtual TcxContainerStyleClass __fastcall GetStyleClass(void);
	virtual TcxContainerStylesClass __fastcall GetStylesClass(void);
	bool __fastcall IsDestruction(void);
	virtual void __fastcall RemoveListener(TcxContainerStyle* AListener);
	__property TcxContainerStyle* Style = {read=GetStyle};
	__property System::Classes::TList* Listeners = {read=FListeners};
	__property System::Classes::TNotifyEvent OnStyleChanged = {read=FOnStyleChanged, write=FOnStyleChanged};
	
public:
	__fastcall virtual TcxStyleController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxStyleController(void);
	void __fastcall RestoreStyles(void);
	__property TcxContainerStyle* Styles[TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	
__published:
	__property Scalable = {default=1};
	__property TcxStyleController* FakeStyleController = {read=GetFakeStyleController, write=SetFakeStyleController, stored=false};
};


__interface IcxContainerInnerControl;
typedef System::DelphiInterface<IcxContainerInnerControl> _di_IcxContainerInnerControl;
__interface  INTERFACE_UUID("{1B111318-D9C9-4C35-9EFF-5D95793C0106}") IcxContainerInnerControl  : public System::IInterface 
{
	
public:
	virtual Vcl::Controls::TWinControl* __fastcall GetControl(void) = 0 ;
	virtual TcxContainer* __fastcall GetControlContainer(void) = 0 ;
	__property Vcl::Controls::TWinControl* Control = {read=GetControl};
	__property TcxContainer* ControlContainer = {read=GetControlContainer};
};

typedef tagSCROLLBARINFO TcxScrollBarInfo;

struct DECLSPEC_DRECORD TcxContainerActiveStyleData
{
public:
	TcxContainerState ContainerState;
	TcxContainerStyle* ActiveStyle;
};


struct DECLSPEC_DRECORD TcxContainerInnerControlBounds
{
public:
	bool IsEmpty;
	System::Types::TRect Rect;
};


struct DECLSPEC_DRECORD TcxContainerSizeGripData
{
public:
	System::Types::TRect Bounds;
	bool Visible;
};


class PASCALIMPLEMENTATION TcxContainer : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TcxContainerActiveStyleData FActiveStyleData;
	bool FHasChanges;
	Vcl::Controls::TWinControl* FInnerControl;
	TcxContainerInnerControlBounds FInnerControlBounds;
	bool FInnerControlMouseDown;
	bool FIsViewInfoCalculated;
	int FLockAlignControlsCount;
	int FPopupMenuLockCount;
	int FProcessEventsLockCount;
	int FRefreshLockCount;
	System::Classes::TWndMethod FSaveInnerControlWndProc;
	bool FScrollBarsCalculating;
	TcxContainerSizeGripData FSizeGripData;
	TcxStyleController* __fastcall GetFakeStyleController(void);
	TcxContainerStyle* __fastcall GetInternalStyle(TcxContainerStateItem AState);
	HIDESBASE bool __fastcall GetIsDestroying(void);
	TcxContainerStyle* __fastcall GetStyle(void);
	TcxContainerStyle* __fastcall GetStyleDisabled(void);
	TcxContainerStyle* __fastcall GetStyleFocused(void);
	TcxContainerStyle* __fastcall GetStyleHot(void);
	Vcl::Graphics::TFont* __fastcall GetVisibleFont(void);
	void __fastcall SetFakeStyleController(TcxStyleController* Value);
	void __fastcall SetInnerControl(Vcl::Controls::TWinControl* Value);
	void __fastcall SetStyle(TcxContainerStyle* Value);
	void __fastcall SetStyleDisabled(TcxContainerStyle* Value);
	void __fastcall SetStyleFocused(TcxContainerStyle* Value);
	void __fastcall SetStyleHot(TcxContainerStyle* Value);
	void __fastcall SetInternalStyle(TcxContainerStateItem AState, TcxContainerStyle* Value);
	System::Uitypes::TDragKind __fastcall GetDragKind(void);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetCursor(Winapi::Messages::TWMSetCursor &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentColorChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMShortRefreshContainer(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMUpdateScrollBars(Winapi::Messages::TMessage &Message);
	
protected:
	bool FInternalSetting;
	bool FIsCreating;
	TcxContainerStyles* FStyles;
	TcxContainerViewInfo* FViewInfo;
	Vcl::Controls::TWinControl* __fastcall GetActiveControl(void);
	void __fastcall MouseTrackingCallerMouseLeave(void);
	virtual Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeelValue(void);
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	virtual void __fastcall AlignControls(Vcl::Controls::TControl* AControl, System::Types::TRect &Rect);
	virtual bool __fastcall AllowAutoDragAndDropAtDesignTime(int X, int Y, System::Classes::TShiftState Shift);
	virtual bool __fastcall CanFocusOnClick(void)/* overload */;
	DYNAMIC void __fastcall ChangeScale(int M, int D);
	DYNAMIC void __fastcall ColorChanged(void);
	DYNAMIC void __fastcall CursorChanged(void);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall DoContextPopup(System::Types::TPoint MousePos, bool &Handled);
	DYNAMIC void __fastcall DragCanceled(void);
	DYNAMIC void __fastcall FocusChanged(void);
	virtual bool __fastcall FocusWhenChildIsClicked(Vcl::Controls::TControl* AChild);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual bool __fastcall IsGestureTarget(NativeUInt AWnd);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall Loaded(void);
	DYNAMIC bool __fastcall MayFocus(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall SetDragMode(System::Uitypes::TDragMode Value);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall UpdateScrollBars(void);
	virtual bool __fastcall UseInnerControlScrollBarParameters(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall AdjustInnerControl(void);
	virtual void __fastcall AdjustScrollBarPosition(Cxcontrols::_di_IcxControlScrollBar AScrollBar);
	virtual void __fastcall CalculateViewInfo(const System::Types::TPoint P, bool AMouseTracking);
	virtual bool __fastcall CanContainerHandleTabs(void);
	virtual bool __fastcall CanHaveTransparentBorder(void);
	virtual bool __fastcall CanRefreshContainer(void);
	virtual bool __fastcall CanShowPopupMenu(const System::Types::TPoint P);
	void __fastcall CheckIsViewInfoCalculated(void);
	virtual void __fastcall ContainerStyleChanged(System::TObject* Sender);
	virtual HRGN __fastcall CreateWindowRegion(void);
	virtual void __fastcall DataChange(void);
	virtual void __fastcall DataSetChange(void);
	virtual bool __fastcall DefaultParentColor(void);
	virtual bool __fastcall DoInnerControlDefaultHandler(Winapi::Messages::TMessage &Message);
	virtual void __fastcall DoProcessEventsOnViewInfoChanging(void);
	virtual bool __fastcall DoRefreshContainer(const System::Types::TPoint P, TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	DYNAMIC void __fastcall EnabledChanged(void);
	virtual void __fastcall EndMouseTracking(void);
	virtual TcxContainerStyle* __fastcall GetActiveStyle(void);
	virtual System::Uitypes::TColor __fastcall GetBackgroundColor(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColor(void);
	virtual System::Uitypes::TColor __fastcall GetBorderColorByPainter(bool AIsHighlight);
	virtual System::Types::TRect __fastcall GetBorderExtent(void);
	virtual void __fastcall GetColorSettingsByPainter(/* out */ System::Uitypes::TColor &ABackground, /* out */ System::Uitypes::TColor &ATextColor);
	virtual Cxlookandfeelpainters::TcxEditStateColorKind __fastcall GetEditStateColorKind(void);
	virtual TcxContainerInnerControlBounds __fastcall GetInnerControlBounds(const System::Types::TRect &AInnerControlsRegion, Vcl::Controls::TControl* AInnerControl);
	NativeUInt __fastcall GetScrollBarHandle(Vcl::Forms::TScrollBarKind AKind);
	virtual System::Types::TRect __fastcall GetShadowBounds(void);
	virtual System::Types::TRect __fastcall GetShadowBoundsExtent(void);
	virtual TcxContainerStyleClass __fastcall GetStyleClass(void);
	virtual TcxContainerStylesClass __fastcall GetStylesClass(void);
	virtual TcxContainerViewInfoClass __fastcall GetViewInfoClass(void);
	virtual System::Types::TRect __fastcall GetWindowRegionAddon(void);
	virtual bool __fastcall HasShadow(void);
	virtual void __fastcall InnerControlWndProc(Winapi::Messages::TMessage &Message);
	virtual TcxContainerStyle* __fastcall InternalGetActiveStyle(void);
	virtual TcxContainerStyleValues __fastcall InternalGetNotPublishedStyleValues(void);
	virtual bool __fastcall HandleInnerContolGestures(void);
	virtual bool __fastcall IsAdjustingScrollBarPositionNeeded(const tagSCROLLBARINFO &AScrollBarInfo);
	bool __fastcall IsAlignControlsLocked(void);
	virtual bool __fastcall IsContainerFocused(void);
	bool __fastcall IsInnerControlBoundsChanged(Vcl::Controls::TWinControl* AControl, const TcxContainerInnerControlBounds &ABounds);
	virtual bool __fastcall IsContainerClass(void);
	virtual bool __fastcall IsMouseTracking(void);
	virtual bool __fastcall IsNativeStyle(void);
	bool __fastcall IsPopupMenuLocked(void);
	virtual bool __fastcall IsReadOnly(void);
	bool __fastcall IsStyleAssigned(TcxContainerStyleValue AValue);
	bool __fastcall RefreshContainer(const System::Types::TPoint P, TcxMouseButton Button, System::Classes::TShiftState Shift, bool AIsMouseEvent);
	void __fastcall SaveInnerControlBounds(Vcl::Controls::TWinControl* AControl, const TcxContainerInnerControlBounds &ABounds);
	virtual void __fastcall DoSetSize(void);
	void __fastcall SetSize(void);
	virtual void __fastcall SetVisibleBoundsClipRect(void);
	virtual void __fastcall UpdateData(void);
	virtual void __fastcall UpdateWindowRegion(void);
	virtual Dxthememanager::TdxThemedObjectType __fastcall GetBackgroundThemedObjectType(void);
	virtual int __fastcall GetBackgroundNativePart(void);
	virtual int __fastcall GetBackgroundNativeState(void);
	virtual System::Types::TRect __fastcall GetScrollBarBounds(const System::Types::TRect &AScrollBarRect);
	virtual bool __fastcall GetScrollBarEnabled(Cxcontrols::_di_IcxControlScrollBar AScrollBar, const tagSCROLLBARINFO &AScrollBarinfo);
	virtual bool __fastcall GetScrollBarInfo(tagSCROLLBARINFO &AScrollBarInfo, const Vcl::Forms::TScrollBarKind AKind);
	void __fastcall ProcessEventsOnViewInfoChanging(void);
	virtual void __fastcall SafeSelectionFocusInnerControl(void);
	virtual void __fastcall SetDragKind(System::Uitypes::TDragKind Value);
	virtual void __fastcall SetScrollBarVisible(Cxcontrols::_di_IcxControlScrollBar AScrollBar, bool AVisible);
	__property TcxContainerStyle* ActiveStyle = {read=GetActiveStyle};
	__property System::Uitypes::TDragKind DragKind = {read=GetDragKind, write=SetDragKind, default=0};
	__property bool HasChanges = {read=FHasChanges, write=FHasChanges, nodefault};
	__property bool IsViewInfoCalculated = {read=FIsViewInfoCalculated, write=FIsViewInfoCalculated, nodefault};
	__property bool ScrollBarsCalculating = {read=FScrollBarsCalculating, nodefault};
	__property TcxContainerStyle* Style = {read=GetStyle, write=SetStyle};
	__property TcxContainerStyle* StyleDisabled = {read=GetStyleDisabled, write=SetStyleDisabled};
	__property TcxContainerStyle* StyleFocused = {read=GetStyleFocused, write=SetStyleFocused};
	__property TcxContainerStyle* StyleHot = {read=GetStyleHot, write=SetStyleHot};
	__property TcxContainerViewInfo* ViewInfo = {read=FViewInfo};
	__property Vcl::Graphics::TFont* VisibleFont = {read=GetVisibleFont};
	
public:
	__fastcall virtual TcxContainer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxContainer(void);
	DYNAMIC bool __fastcall Focused(void);
	virtual Vcl::Controls::TDragImageList* __fastcall GetDragImages(void);
	DYNAMIC void __fastcall GetTabOrderList(System::Classes::TList* List);
	virtual void __fastcall SetFocus(void);
	virtual void __fastcall ClearSavedChildControlRegions(void);
	virtual System::Types::TRect __fastcall GetVisibleBounds(void);
	bool __fastcall HasInnerControl(void);
	bool __fastcall HasInnerControlHandle(void);
	virtual bool __fastcall HasPopupWindow(void);
	bool __fastcall InnerControlDefaultHandler(Winapi::Messages::TMessage &Message);
	virtual bool __fastcall InnerControlMenuHandler(Winapi::Messages::TMessage &Message);
	virtual void __fastcall Invalidate(void);
	virtual bool __fastcall IsInplace(void);
	bool __fastcall IsStylePropertyPublished(const System::UnicodeString APropertyName, bool AExtendedStyle);
	void __fastcall LockAlignControls(bool ALock);
	void __fastcall LockPopupMenu(bool ALock);
	void __fastcall RestoreStyles(void);
	virtual void __fastcall SetScrollBarsParameters(bool AIsScrolling = false);
	bool __fastcall ShortRefreshContainer(bool AIsMouseEvent);
	virtual void __fastcall Update(void);
	virtual void __fastcall TranslationChanged(void);
	void __fastcall UpdateScrollBarsParameters(void);
	__property Vcl::Controls::TWinControl* ActiveControl = {read=GetActiveControl};
	__property Vcl::Controls::TWinControl* InnerControl = {read=FInnerControl, write=SetInnerControl};
	__property bool InnerControlMouseDown = {read=FInnerControlMouseDown, write=FInnerControlMouseDown, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property ParentColor = {default=1};
	__property ParentFont = {default=1};
	__property TcxContainerStyle* Styles[TcxContainerStateItem AState] = {read=GetInternalStyle, write=SetInternalStyle};
	__property System::Types::TRect VisibleBounds = {read=GetVisibleBounds};
	
__published:
	__property TcxStyleController* FakeStyleController = {read=GetFakeStyleController, write=SetFakeStyleController, stored=false};
	__property TabStop = {default=1};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxContainer(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
protected:
	inline bool __fastcall  CanFocusOnClick(int X, int Y){ return Cxcontrols::TcxControl::CanFocusOnClick(X, Y); }
	
private:
	void *__IcxMouseTrackingCaller;	/* Cxcontrols::IcxMouseTrackingCaller */
	void *__IcxCompoundControl;	/* Cxcontrols::IcxCompoundControl */
	
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
	// {A4A77F28-1D03-425B-9A83-0B853B5D8DEF}
	operator Cxcontrols::_di_IcxCompoundControl()
	{
		Cxcontrols::_di_IcxCompoundControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IcxCompoundControl*(void) { return (Cxcontrols::IcxCompoundControl*)&__IcxCompoundControl; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxCompoundControl; }
	#endif
	
};


class DELPHICLASS TcxCustomPopupWindow;
class PASCALIMPLEMENTATION TcxCustomPopupWindow : public Cxcontrols::TcxPopupWindow
{
	typedef Cxcontrols::TcxPopupWindow inherited;
	
private:
	bool FCaptureFocus;
	int FDeactivateLockCount;
	bool FDeactivation;
	Vcl::Controls::TWinControl* FFocusedControl;
	bool FIsPopup;
	bool FIsTopMost;
	bool FJustClosed;
	bool FModalMode;
	bool FTerminateOnDestroy;
	Vcl::Controls::TWinControl* FOwnerControl;
	System::Classes::TNotifyEvent FOnClosed;
	System::Classes::TNotifyEvent FOnClosing;
	System::Classes::TNotifyEvent FOnShowed;
	System::Classes::TNotifyEvent FOnShowing;
	bool __fastcall GetJustClosed(void);
	void __fastcall SetCaptureFocus(bool Value);
	void __fastcall SetIsTopMost(bool Value);
	HIDESBASE MESSAGE void __fastcall WMActivateApp(Winapi::Messages::TWMActivateApp &Message);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanging(Winapi::Messages::TWMWindowPosMsg &Message);
	MESSAGE void __fastcall CMClosePopupWindow(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMRecreateWnd(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall CMShowPopupWindow(Winapi::Messages::TMessage &Message);
	
protected:
	TcxContainerStyle* FStyle;
	TcxContainerViewInfo* FViewInfo;
	virtual void __fastcall AdjustClientRect(System::Types::TRect &Rect);
	DYNAMIC void __fastcall Deactivate(void);
	virtual System::Types::TRect __fastcall GetOwnerScreenBounds(void);
	virtual void __fastcall InitPopup(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall Paint(void);
	DYNAMIC void __fastcall VisibleChanged(void);
	virtual void __fastcall CreateHandle(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual bool __fastcall AcceptsAnySize(void);
	virtual void __fastcall DoClosed(void);
	virtual void __fastcall DoClosing(void);
	virtual void __fastcall DoShowed(void);
	virtual void __fastcall DoShowing(void);
	Vcl::Controls::TWinControl* __fastcall GetFirstFocusControl(Vcl::Controls::TWinControl* AControl);
	Vcl::Controls::TWinControl* __fastcall GetOwnerControl(void);
	virtual bool __fastcall HasBackground(void);
	bool __fastcall IsDeactivateLocked(void);
	bool __fastcall IsOwnerControlVisible(void);
	virtual bool __fastcall IsSysKeyAccepted(System::Word Key);
	virtual void __fastcall ModalCloseUp(void);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	virtual bool __fastcall NeedIgnoreMouseMessageAfterCloseUp(NativeUInt AWnd, unsigned AMsg, System::Classes::TShiftState AShift, const System::Types::TPoint APos);
	virtual void __fastcall PopupWindowStyleChanged(System::TObject* Sender);
	void __fastcall RecreateWindow(void);
	__property TcxContainerStyle* Style = {read=FStyle};
	__property TcxContainerViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TcxCustomPopupWindow(Vcl::Controls::TWinControl* AOwnerControl);
	__fastcall virtual ~TcxCustomPopupWindow(void);
	DYNAMIC bool __fastcall Focused(void);
	DYNAMIC bool __fastcall CanFocus(void);
	void __fastcall ClosePopup(void);
	virtual void __fastcall CloseUp(void);
	virtual void __fastcall CorrectBoundsWithDesktopWorkArea(System::Types::TPoint &APosition);
	virtual TcxContainerStyleClass __fastcall GetStyleClass(void);
	virtual TcxContainerViewInfoClass __fastcall GetViewInfoClass(void);
	bool __fastcall HasCapture(void);
	DYNAMIC bool __fastcall IsShortCut(Winapi::Messages::TWMKey &Message);
	bool __fastcall IsVisible(void);
	void __fastcall LockDeactivate(bool ALock);
	HIDESBASE virtual void __fastcall Popup(Vcl::Controls::TWinControl* AFocusedControl);
	virtual bool __fastcall SetFocusedControl(Vcl::Controls::TWinControl* Control);
	__property bool CaptureFocus = {read=FCaptureFocus, write=SetCaptureFocus, default=1};
	__property Vcl::Controls::TWinControl* FocusedControl = {read=FFocusedControl, write=FFocusedControl};
	__property bool IsTopMost = {read=FIsTopMost, write=SetIsTopMost, nodefault};
	__property bool JustClosed = {read=GetJustClosed, nodefault};
	__property bool ModalMode = {read=FModalMode, write=FModalMode, default=1};
	__property Vcl::Controls::TWinControl* OwnerControl = {read=GetOwnerControl};
	__property bool TerminateOnDestroy = {read=FTerminateOnDestroy, write=FTerminateOnDestroy, nodefault};
	__property System::Classes::TNotifyEvent OnClosed = {read=FOnClosed, write=FOnClosed};
	__property System::Classes::TNotifyEvent OnClosing = {read=FOnClosing, write=FOnClosing};
	__property OnCloseQuery;
	__property System::Classes::TNotifyEvent OnShowed = {read=FOnShowed, write=FOnShowed};
	__property System::Classes::TNotifyEvent OnShowing = {read=FOnShowing, write=FOnShowing};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxCustomPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxcontrols::TcxPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomPopupWindow(HWND ParentWindow) : Cxcontrols::TcxPopupWindow(ParentWindow) { }
	
private:
	void *__IdxPopupControl;	/* Cxcontrols::IdxPopupControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {631D4C30-8543-4A08-A50E-9ABA2FA7EF33}
	operator Cxcontrols::_di_IdxPopupControl()
	{
		Cxcontrols::_di_IdxPopupControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxcontrols::IdxPopupControl*(void) { return (Cxcontrols::IdxPopupControl*)&__IdxPopupControl; }
	#endif
	
};


class DELPHICLASS TcxCustomInnerListBox;
class PASCALIMPLEMENTATION TcxCustomInnerListBox : public Vcl::Stdctrls::TListBox
{
	typedef Vcl::Stdctrls::TListBox inherited;
	
private:
	System::UnicodeString FAutoCompleteFilter;
	Cxgraphics::TcxCanvas* FCanvas;
	Cxscrollbar::TcxScrollBar* FHScrollBar;
	bool FIsRedrawLocked;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	System::Uitypes::TColor FPrevBrushColor;
	System::Uitypes::TColor FPrevFontColor;
	unsigned FPrevKeyPressTime;
	bool FScrollBarsCalculating;
	int FScrollBarsLockCount;
	Cxscrollbar::TcxScrollBar* FVScrollBar;
	void __fastcall CreateScrollBars(void);
	int __fastcall FindAutoCompleteString(const System::UnicodeString S);
	TcxContainer* __fastcall GetControlContainer(void);
	HIDESBASE Vcl::Controls::TWinControl* __fastcall GetControl(void);
	void __fastcall HScrollHandler(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall VScrollHandler(System::TObject* Sender, System::Uitypes::TScrollCode ScrollCode, int &ScrollPos);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMLButtonDown(Winapi::Messages::TWMMouse &Message);
	HIDESBASE MESSAGE void __fastcall WMNCCalcSize(Winapi::Messages::TWMNCCalcSize &Message);
	HIDESBASE MESSAGE void __fastcall WMNCPaint(Winapi::Messages::TWMNCPaint &Message);
	MESSAGE void __fastcall WMPrint(Winapi::Messages::TWMPrint &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	MESSAGE void __fastcall WMSetRedraw(Winapi::Messages::TWMSetRedraw &Message);
	HIDESBASE MESSAGE void __fastcall WMWindowPosChanged(Winapi::Messages::TWMWindowPosMsg &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseEnter(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNDrawItem(Winapi::Messages::TWMDrawItem &Message);
	
protected:
	TcxContainer* FContainer;
	DYNAMIC void __fastcall Click(void);
	DYNAMIC void __fastcall DblClick(void);
	virtual void __fastcall DestroyWindowHandle(void);
	virtual void __fastcall DoAutoComplete(System::WideChar &Key);
	DYNAMIC bool __fastcall DoMouseWheel(System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	DYNAMIC void __fastcall DragOver(System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	DYNAMIC Vcl::Menus::TPopupMenu* __fastcall GetPopupMenu(void);
	System::Types::TRect __fastcall GetSizeGripRect(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall KeyPress(System::WideChar &Key);
	DYNAMIC void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall LookAndFeelChanged(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseEnter(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseLeave(Vcl::Controls::TControl* AControl);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	void __fastcall DrawSizeGrip(HDC ADC);
	virtual bool __fastcall NeedDrawFocusRect(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall RestoreCanvasParametersForFocusRect(void);
	void __fastcall SaveCanvasParametersForFocusRect(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property TcxContainer* Container = {read=FContainer, write=FContainer};
	__property bool IsRedrawLocked = {read=FIsRedrawLocked, nodefault};
	
public:
	__fastcall virtual TcxCustomInnerListBox(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerListBox(void);
	virtual void __fastcall DefaultHandler(void *Message);
	DYNAMIC void __fastcall DragDrop(System::TObject* Source, int X, int Y);
	virtual void __fastcall SetExternalScrollBarsParameters(void);
	bool __fastcall ItemVisible(int Index);
	__property Cxgraphics::TcxCanvas* Canvas = {read=FCanvas};
	__property Cxscrollbar::TcxScrollBar* HScrollBar = {read=FHScrollBar};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property Cxscrollbar::TcxScrollBar* VScrollBar = {read=FVScrollBar};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerListBox(HWND ParentWindow) : Vcl::Stdctrls::TListBox(ParentWindow) { }
	
private:
	void *__IcxContainerInnerControl;	/* IcxContainerInnerControl */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1B111318-D9C9-4C35-9EFF-5D95793C0106}
	operator _di_IcxContainerInnerControl()
	{
		_di_IcxContainerInnerControl intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxContainerInnerControl*(void) { return (IcxContainerInnerControl*)&__IcxContainerInnerControl; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxContainerInnerControl; }
	#endif
	
};


typedef TcxCustomInnerListBox TcxCustomListBox;

class DELPHICLASS _TcxContainerAccess;
class PASCALIMPLEMENTATION _TcxContainerAccess : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod void __fastcall BeginAutoDrag(TcxContainer* AInstance);
	__classmethod void __fastcall Click(TcxContainer* AInstance);
	__classmethod void __fastcall DblClick(TcxContainer* AInstance);
	__classmethod bool __fastcall DoMouseWheel(TcxContainer* AInstance, System::Classes::TShiftState Shift, int WheelDelta, System::Types::TPoint MousePos);
	__classmethod void __fastcall DragOver(TcxContainer* AInstance, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	__classmethod void __fastcall KeyDown(TcxContainer* AInstance, System::Word &Key, System::Classes::TShiftState Shift);
	__classmethod void __fastcall KeyPress(TcxContainer* AInstance, System::WideChar &Key);
	__classmethod void __fastcall KeyUp(TcxContainer* AInstance, System::Word &Key, System::Classes::TShiftState Shift);
	__classmethod void __fastcall MouseDown(TcxContainer* AInstance, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	__classmethod void __fastcall MouseMove(TcxContainer* AInstance, System::Classes::TShiftState Shift, int X, int Y);
	__classmethod void __fastcall MouseUp(TcxContainer* AInstance, System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
public:
	/* TObject.Create */ inline __fastcall _TcxContainerAccess(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~_TcxContainerAccess(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Word cxDefaultAutoCompleteDelay = System::Word(0x1f4);
static const System::Int8 cxContainerShadowWidth = System::Int8(0x3);
extern PACKAGE HBRUSH cxEmptyBrush;
extern PACKAGE System::Types::TRect cxContainerDefaultBorderExtent;
static const System::Int8 csvBorderColor = System::Int8(0x0);
static const System::Int8 csvBorderStyle = System::Int8(0x1);
static const System::Int8 csvColor = System::Int8(0x2);
static const System::Int8 csvEdges = System::Int8(0x3);
static const System::Int8 csvFont = System::Int8(0x4);
static const System::Int8 csvHotTrack = System::Int8(0x5);
static const System::Int8 csvShadow = System::Int8(0x6);
static const System::Int8 csvTextColor = System::Int8(0x7);
static const System::Int8 csvTextStyle = System::Int8(0x8);
static const System::Int8 csvTransparentBorder = System::Int8(0x9);
static const System::Int8 cxContainerStyleValueCount = System::Int8(0xa);
extern PACKAGE Cxcontainer__1 cxContainerStyleValueNameA;
extern PACKAGE TcxStyleController* cxContainerDefaultStyleController;
extern PACKAGE System::Uitypes::TColor cxContainerShadowColor;
extern PACKAGE bool TopMostComboBoxes;
extern PACKAGE TcxMouseButton __fastcall ButtonTocxButton(System::Uitypes::TMouseButton Button);
extern PACKAGE bool __fastcall cxCanShowHint(Vcl::Controls::TWinControl* AControl);
extern PACKAGE bool __fastcall CheckParentsNativeHandle(Vcl::Controls::TWinControl* AControl, NativeUInt ANativeHandle);
extern PACKAGE BOOL __fastcall cxGetScrollBarInfo(HWND hwnd, int idObject, tagSCROLLBARINFO &psbi);
extern PACKAGE TcxStyleController* __fastcall DefaultContainerStyleController(void);
extern PACKAGE void __fastcall DrawContainerShadow(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect);
extern PACKAGE void __fastcall ExtendRectByBorders(System::Types::TRect &R, int ABorderWidth, Cxgraphics::TcxBorders AEdges);
extern PACKAGE HWND __fastcall FindFirstNonChildParentWindow(HWND AWnd);
extern PACKAGE System::Uitypes::TColor __fastcall GetContainerBorderColor(bool AIsHighlight, bool AIsOffice11Style);
extern PACKAGE int __fastcall GetContainerBorderWidth(Cxlookandfeelpainters::TcxContainerBorderStyle ABorderStyle)/* overload */;
extern PACKAGE int __fastcall GetContainerBorderWidth(Cxlookandfeels::TcxLookAndFeelKind ALookAndFeelKind)/* overload */;
extern PACKAGE System::Types::TRect __fastcall GetControlRect(Vcl::Controls::TControl* AControl);
extern PACKAGE TcxContainer* __fastcall GetcxContainer(Vcl::Controls::TWinControl* AControl);
extern PACKAGE Vcl::Controls::TWinControl* __fastcall GetInnerControlContainer(Vcl::Controls::TWinControl* AControl);
extern PACKAGE HWND __fastcall GetPopupOwnerControl(HWND AWnd);
extern PACKAGE bool __fastcall HasHandle(Vcl::Controls::TWinControl* AControl, NativeUInt AHandle);
extern PACKAGE bool __fastcall HasNativeHandle(Vcl::Controls::TWinControl* AControl, NativeUInt AHandle, bool ACheckChildren = false);
extern PACKAGE bool __fastcall HasOpenedPopupWindow(Vcl::Controls::TWinControl* AControl);
extern PACKAGE void __fastcall InflateRectByBorders(System::Types::TRect &R, int ABorderWidth, Cxgraphics::TcxBorders AEdges);
extern PACKAGE bool __fastcall InternalCompareString(const Vcl::Controls::TCaption S1, const Vcl::Controls::TCaption S2, bool ACaseSensitive);
extern PACKAGE void __fastcall InternalInvalidate(NativeUInt AHandle, const System::Types::TRect &AOuterRect, const System::Types::TRect &AInternalRect, bool AEraseBackground = false, bool ARedrawNC = false);
extern PACKAGE void __fastcall InternalInvalidateRect(Vcl::Controls::TWinControl* AControl, const System::Types::TRect &R, bool AEraseBackground);
extern PACKAGE bool __fastcall InternalIsWindowVisible(Vcl::Controls::TWinControl* AControl);
extern PACKAGE bool __fastcall IsChildWindow(Vcl::Controls::TWinControl* AParent, NativeUInt AChildHandle);
extern PACKAGE bool __fastcall IsRelatedWindow(NativeUInt AParentHandle, NativeUInt AChildHandle)/* overload */;
extern PACKAGE bool __fastcall IsRelatedWindow(Vcl::Controls::TWinControl* AParent, NativeUInt AChildHandle)/* overload */;
extern PACKAGE bool __fastcall IsFormActive(Vcl::Forms::TCustomForm* AForm);
extern PACKAGE bool __fastcall IsMouseDownMessage(NativeUInt AMsg);
extern PACKAGE bool __fastcall IsMessageInQueue _DEPRECATED_ATTRIBUTE0 (HWND AWnd, unsigned AMessage);
extern PACKAGE bool __fastcall KillMessages _DEPRECATED_ATTRIBUTE0 (HWND AWnd, unsigned AMsgFilterMin, unsigned AMsgFilterMax = (unsigned)(0x0), bool AKillAllMessages = true);
extern PACKAGE void __fastcall LockCMActivateMessages(bool ALock);
extern PACKAGE System::Classes::TShiftState __fastcall MouseButtonToShift(System::Uitypes::TMouseButton Button);
extern PACKAGE void __fastcall SetWindowRegion(Vcl::Controls::TWinControl* AControl, const TcxContainerInnerControlBounds &ABounds);
extern PACKAGE void __fastcall SetWindowShadowRegion(NativeUInt AWindowHandle, const System::Types::TRect &AShadowBounds, const System::Types::TRect &AShadowBoundsExtent, bool ANativeStyle, bool AShadow, const System::Types::TRect &AExcludeRect);
extern PACKAGE bool __fastcall UsecxScrollBars(void);
extern PACKAGE bool __fastcall AreVisualStylesMustBeUsed(bool ANativeStyle, Dxthememanager::TdxThemedObjectType AThemedObjectType);
extern PACKAGE System::Types::TRect __fastcall GetSizeGripRect(_di_IcxContainerInnerControl AControl)/* overload */;
extern PACKAGE System::Types::TRect __fastcall GetSizeGripRect(TcxContainer* AContainer)/* overload */;
extern PACKAGE void __fastcall cxFillSizeGrip(TcxContainer* AContainer, const System::Types::TRect &ARect)/* overload */;
extern PACKAGE void __fastcall cxFillSizeGrip(TcxContainer* AContainer)/* overload */;
extern PACKAGE void __fastcall SetHooksSettingMode(bool ASetHooksOnlyWhenPopupsAreVisible);
extern PACKAGE void __fastcall DisableWindow(System::Classes::TList* AWindowList, HWND AWnd);
extern PACKAGE void __fastcall EnableWindows(System::Classes::TList* AWindowList);
extern PACKAGE void __fastcall DisableAppWindows(bool ANeedDisable = true);
extern PACKAGE void __fastcall EnableAppWindows(void);
extern PACKAGE bool __fastcall IsInternalWindowsDisabled(void);
extern PACKAGE bool __fastcall IsInternalWindowsDisabling(void);
}	/* namespace Cxcontainer */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCONTAINER)
using namespace Cxcontainer;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcontainerHPP
