// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxStatusBar.pas' rev: 24.00 (Win64)

#ifndef DxstatusbarHPP
#define DxstatusbarHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxstatusbar
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxStatusBarPainterClass;

typedef System::TMetaClass* TdxStatusBarPanelClass;

class DELPHICLASS TdxStatusBarPanelStyle;
class DELPHICLASS TdxStatusBarPanel;
class DELPHICLASS TdxCustomStatusBar;
class PASCALIMPLEMENTATION TdxStatusBarPanelStyle : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	System::Uitypes::TColor FColor;
	Vcl::Graphics::TFont* FFont;
	bool FIsColorAssigned;
	TdxStatusBarPanel* FOwner;
	bool FParentFont;
	void __fastcall FontChanged(System::TObject* Sender);
	System::Uitypes::TColor __fastcall GetColor(void);
	TdxStatusBarPainterClass __fastcall GetPainter(void);
	TdxCustomStatusBar* __fastcall GetStatusBarControl(void);
	bool __fastcall IsColorStored(void);
	bool __fastcall IsFontStored(void);
	void __fastcall SetAlignment(System::Classes::TAlignment Value);
	void __fastcall SetColor(System::Uitypes::TColor Value);
	void __fastcall SetFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetParentFont(bool Value);
	
protected:
	virtual void __fastcall AdjustTextColor(System::Uitypes::TColor &AColor, bool Active);
	virtual void __fastcall BoundsChanged(const System::Types::TRect &ABounds);
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanSizing(void);
	virtual void __fastcall Changed(void);
	virtual void __fastcall CheckSizeGripRect(System::Types::TRect &R);
	virtual System::Uitypes::TColor __fastcall DefaultColor(void);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* ASource);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TdxStatusBarPainterClass APainter);
	virtual int __fastcall GetMinWidth(void);
	bool __fastcall GetPanelFixed(void);
	__classmethod virtual int __fastcall GetVersion();
	virtual bool __fastcall InternalBevel(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall ParentFontChanged(void);
	virtual void __fastcall UpdateSubControlsVisibility(void);
	
public:
	__fastcall virtual TdxStatusBarPanelStyle(TdxStatusBarPanel* AOwner);
	__fastcall virtual ~TdxStatusBarPanelStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	virtual void __fastcall RestoreDefaults(void);
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, default=0};
	__property System::Uitypes::TColor Color = {read=GetColor, write=SetColor, stored=IsColorStored, nodefault};
	__property Vcl::Graphics::TFont* Font = {read=FFont, write=SetFont, stored=IsFontStored};
	__property TdxStatusBarPanel* Owner = {read=FOwner};
	__property TdxStatusBarPainterClass Painter = {read=GetPainter};
	__property bool ParentFont = {read=FParentFont, write=SetParentFont, default=1};
	__property TdxCustomStatusBar* StatusBarControl = {read=GetStatusBarControl};
};


typedef System::TMetaClass* TdxStatusBarPanelStyleClass;

enum TdxStatusBarEllipsisType : unsigned char { dxetNone, dxetTruncate, dxetSmartPath };

typedef System::Set<TdxStatusBarEllipsisType, TdxStatusBarEllipsisType::dxetNone, TdxStatusBarEllipsisType::dxetSmartPath>  TdxStatusBarEllipsisTypes;

typedef void __fastcall (__closure *TdxStatusBarTextEvent)(System::TObject* Sender, const System::Types::TRect &R, System::UnicodeString &AText);

class DELPHICLASS TdxStatusBarTextPanelStyle;
class PASCALIMPLEMENTATION TdxStatusBarTextPanelStyle : public TdxStatusBarPanelStyle
{
	typedef TdxStatusBarPanelStyle inherited;
	
private:
	bool FAutoHint;
	TdxStatusBarEllipsisType FEllipsisType;
	System::Uitypes::TImageIndex FImageIndex;
	TdxStatusBarTextEvent FOnGetText;
	void __fastcall SetAutoHint(bool Value);
	void __fastcall SetEllipsisType(TdxStatusBarEllipsisType Value);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* ASource);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TdxStatusBarPainterClass APainter);
	
public:
	__fastcall virtual TdxStatusBarTextPanelStyle(TdxStatusBarPanel* AOwner);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Alignment = {default=0};
	__property bool AutoHint = {read=FAutoHint, write=SetAutoHint, default=0};
	__property Color;
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
	__property TdxStatusBarEllipsisType EllipsisType = {read=FEllipsisType, write=SetEllipsisType, default=0};
	__property Font;
	__property ParentFont = {default=1};
	__property TdxStatusBarTextEvent OnGetText = {read=FOnGetText, write=FOnGetText};
public:
	/* TdxStatusBarPanelStyle.Destroy */ inline __fastcall virtual ~TdxStatusBarTextPanelStyle(void) { }
	
};


enum TdxStatusBarStateIndicatorType : unsigned char { sitOff, sitYellow, sitBlue, sitGreen, sitRed, sitTeal, sitPurple };

class DELPHICLASS TdxStatusBarStateIndicatorItem;
class PASCALIMPLEMENTATION TdxStatusBarStateIndicatorItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	Vcl::Graphics::TBitmap* FIndicatorBitmap;
	TdxStatusBarStateIndicatorType FIndicatorType;
	bool FVisible;
	void __fastcall SetIndicatorType(TdxStatusBarStateIndicatorType Value);
	void __fastcall SetVisible(bool Value);
	
public:
	__fastcall virtual TdxStatusBarStateIndicatorItem(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxStatusBarStateIndicatorItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxStatusBarStateIndicatorType IndicatorType = {read=FIndicatorType, write=SetIndicatorType, default=0};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
};


class DELPHICLASS TdxStatusBarStateIndicators;
class PASCALIMPLEMENTATION TdxStatusBarStateIndicators : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxStatusBarStateIndicatorItem* operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TNotifyEvent FOnChange;
	HIDESBASE TdxStatusBarStateIndicatorItem* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxStatusBarStateIndicatorItem* Value);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	
public:
	__fastcall TdxStatusBarStateIndicators(void);
	HIDESBASE TdxStatusBarStateIndicatorItem* __fastcall Add(void);
	HIDESBASE TdxStatusBarStateIndicatorItem* __fastcall Insert(int AIndex);
	__property TdxStatusBarStateIndicatorItem* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxStatusBarStateIndicators(void) { }
	
};


class DELPHICLASS TdxStatusBarStateIndicatorPanelStyle;
class PASCALIMPLEMENTATION TdxStatusBarStateIndicatorPanelStyle : public TdxStatusBarPanelStyle
{
	typedef TdxStatusBarPanelStyle inherited;
	
private:
	int FSpacing;
	TdxStatusBarStateIndicators* FIndicators;
	TdxStatusBarStateIndicators* __fastcall GetIndicators(void);
	void __fastcall IndicatorChangeHandler(System::TObject* Sender);
	void __fastcall SetIndicators(TdxStatusBarStateIndicators* Value);
	void __fastcall SetSpacing(int Value);
	
protected:
	virtual bool __fastcall CanSizing(void);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* ASource);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TdxStatusBarPainterClass APainter);
	virtual int __fastcall GetMinWidth(void);
	
public:
	__fastcall virtual TdxStatusBarStateIndicatorPanelStyle(TdxStatusBarPanel* AOwner);
	__fastcall virtual ~TdxStatusBarStateIndicatorPanelStyle(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Color;
	__property TdxStatusBarStateIndicators* Indicators = {read=GetIndicators, write=SetIndicators};
	__property int Spacing = {read=FSpacing, write=SetSpacing, default=4};
};


class DELPHICLASS TdxStatusBarKeyboardStateWatchedKey;
class PASCALIMPLEMENTATION TdxStatusBarKeyboardStateWatchedKey : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FKeyCode;
	int FKeyState;
	void __fastcall SetKeyState(int Value);
	
public:
	__fastcall TdxStatusBarKeyboardStateWatchedKey(int AKeyCode);
	int __fastcall GetCurrentState(void);
	__property int KeyCode = {read=FKeyCode, nodefault};
	__property int KeyState = {read=FKeyState, write=SetKeyState, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarKeyboardStateWatchedKey(void) { }
	
};


class DELPHICLASS TdxStatusBarKeyboardStateNotifier;
class PASCALIMPLEMENTATION TdxStatusBarKeyboardStateNotifier : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<TdxStatusBarKeyboardStateWatchedKey*> _TdxStatusBarKeyboardStateNotifier__1;
	
	
private:
	_TdxStatusBarKeyboardStateNotifier__1 FKeys;
	TdxCustomStatusBar* FStatusBar;
	Vcl::Extctrls::TTimer* FTimer;
	
protected:
	void __fastcall Execute(System::TObject* Sender);
	
public:
	__fastcall TdxStatusBarKeyboardStateNotifier(TdxCustomStatusBar* AStatusBar);
	__fastcall virtual ~TdxStatusBarKeyboardStateNotifier(void);
	void __fastcall SubScribeKey(int AKeyCode);
	void __fastcall UnSubScribeKey(int AKeyCode);
};


enum TdxStatusBarKeyboardState : unsigned char { dxksCapsLock, dxksNumLock, dxksScrollLock, dxksInsert };

typedef System::Set<TdxStatusBarKeyboardState, TdxStatusBarKeyboardState::dxksCapsLock, TdxStatusBarKeyboardState::dxksInsert>  TdxStatusBarKeyboardStates;

class DELPHICLASS TdxStatusBarKeyStateAppearance;
class PASCALIMPLEMENTATION TdxStatusBarKeyStateAppearance : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TdxStatusBarKeyboardState FId;
	int FCode;
	System::Uitypes::TColor FActiveFontColor;
	System::Uitypes::TColor FInactiveFontColor;
	System::UnicodeString FActiveCaption;
	System::UnicodeString FInactiveCaption;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall SetActiveFontColor(System::Uitypes::TColor Value);
	void __fastcall SetInactiveFontColor(System::Uitypes::TColor Value);
	void __fastcall SetActiveCaption(const System::UnicodeString Value);
	void __fastcall SetInactiveCaption(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall Changed(void);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall TdxStatusBarKeyStateAppearance(TdxStatusBarKeyboardState AId, int ACode, const System::UnicodeString AActiveCaption, System::Uitypes::TColor AActiveFontColor, const System::UnicodeString AInactiveCaption, System::Uitypes::TColor AInactiveFontColor, System::Classes::TNotifyEvent AChangeHandler);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	int __fastcall GetRectWidth(Cxgraphics::TcxCanvas* ACanvas);
	__property int Code = {read=FCode, nodefault};
	__property TdxStatusBarKeyboardState Id = {read=FId, nodefault};
	
__published:
	__property System::Uitypes::TColor ActiveFontColor = {read=FActiveFontColor, write=SetActiveFontColor, default=-16777208};
	__property System::Uitypes::TColor InactiveFontColor = {read=FInactiveFontColor, write=SetInactiveFontColor, default=-16777200};
	__property System::UnicodeString ActiveCaption = {read=FActiveCaption, write=SetActiveCaption};
	__property System::UnicodeString InactiveCaption = {read=FInactiveCaption, write=SetInactiveCaption};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxStatusBarKeyStateAppearance(void) { }
	
};


class DELPHICLASS TdxStatusBarKeyboardStatePanelStyle;
class PASCALIMPLEMENTATION TdxStatusBarKeyboardStatePanelStyle : public TdxStatusBarPanelStyle
{
	typedef TdxStatusBarPanelStyle inherited;
	
private:
	bool FFullRect;
	TdxStatusBarKeyboardStates FKeyboardStates;
	System::StaticArray<TdxStatusBarKeyStateAppearance*, 4> FKeyInfos;
	TdxStatusBarKeyboardStateNotifier* FNotifier;
	TdxStatusBarKeyStateAppearance* __fastcall GetCapsLockAppearance(void);
	TdxStatusBarKeyStateAppearance* __fastcall GetInsertAppearance(void);
	TdxStatusBarKeyStateAppearance* __fastcall GetNumLockAppearance(void);
	TdxStatusBarKeyStateAppearance* __fastcall GetScrollLockAppearance(void);
	void __fastcall NamesChangeHandler(System::TObject* Sender);
	void __fastcall SetCapsLockAppearance(TdxStatusBarKeyStateAppearance* Value);
	void __fastcall SetFullRect(bool Value);
	void __fastcall SetInsertAppearance(TdxStatusBarKeyStateAppearance* Value);
	void __fastcall SetKeyboardStates(TdxStatusBarKeyboardStates Value);
	void __fastcall SetNumLockAppearance(TdxStatusBarKeyStateAppearance* Value);
	void __fastcall SetScrollLockAppearance(TdxStatusBarKeyStateAppearance* Value);
	
protected:
	virtual bool __fastcall CanSizing(void);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* ASource);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, TdxStatusBarPainterClass APainter);
	virtual int __fastcall GetMinWidth(void);
	virtual bool __fastcall InternalBevel(void);
	
public:
	__fastcall virtual TdxStatusBarKeyboardStatePanelStyle(TdxStatusBarPanel* AOwner);
	__fastcall virtual ~TdxStatusBarKeyboardStatePanelStyle(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property Color;
	__property Font;
	__property TdxStatusBarKeyboardStates KeyboardStates = {read=FKeyboardStates, write=SetKeyboardStates, default=15};
	__property bool FullRect = {read=FFullRect, write=SetFullRect, default=0};
	__property TdxStatusBarKeyStateAppearance* CapsLockKeyAppearance = {read=GetCapsLockAppearance, write=SetCapsLockAppearance};
	__property TdxStatusBarKeyStateAppearance* NumLockKeyAppearance = {read=GetNumLockAppearance, write=SetNumLockAppearance};
	__property TdxStatusBarKeyStateAppearance* ScrollLockKeyAppearance = {read=GetScrollLockAppearance, write=SetScrollLockAppearance};
	__property TdxStatusBarKeyStateAppearance* InsertKeyAppearance = {read=GetInsertAppearance, write=SetInsertAppearance};
	__property ParentFont = {default=1};
};


class DELPHICLASS TdxStatusBarContainerControl;
class DELPHICLASS TdxStatusBarContainerPanelStyle;
class PASCALIMPLEMENTATION TdxStatusBarContainerControl : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	TdxStatusBarContainerPanelStyle* FPanelStyle;
	
protected:
	virtual void __fastcall AlignChildren(void);
	DYNAMIC void __fastcall BoundsChanged(void);
	virtual void __fastcall Paint(void);
	DYNAMIC bool __fastcall MayFocus(void);
	virtual bool __fastcall NeedAlignChildren(void);
	virtual bool __fastcall NeedsScrollBars(void);
	MESSAGE void __fastcall CMControlChange(Vcl::Controls::TCMControlChange &Message);
	
public:
	__fastcall virtual TdxStatusBarContainerControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxStatusBarContainerControl(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxStatusBarContainerControl(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TdxStatusBarContainerPanelStyle : public TdxStatusBarPanelStyle
{
	typedef TdxStatusBarPanelStyle inherited;
	
private:
	bool FAlignControl;
	TdxStatusBarContainerControl* FContainer;
	void __fastcall SetContainer(TdxStatusBarContainerControl* Value);
	
protected:
	virtual void __fastcall BoundsChanged(const System::Types::TRect &ABounds);
	virtual bool __fastcall CanDelete(void);
	virtual void __fastcall DoAssign(System::Classes::TPersistent* ASource);
	void __fastcall DrawContainerControl(void);
	virtual void __fastcall UpdateSubControlsVisibility(void);
	
public:
	__fastcall virtual TdxStatusBarContainerPanelStyle(TdxStatusBarPanel* AOwner);
	__fastcall virtual ~TdxStatusBarContainerPanelStyle(void);
	virtual void __fastcall RestoreDefaults(void);
	
__published:
	__property bool AlignControl = {read=FAlignControl, write=FAlignControl, default=1};
	__property TdxStatusBarContainerControl* Container = {read=FContainer, write=SetContainer};
};


enum TdxStatusBarPanelBevel : unsigned char { dxpbNone, dxpbLowered, dxpbRaised };

typedef void __fastcall (__closure *TdxStatusBarDrawPanelEvent)(TdxStatusBarPanel* Sender, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ARect, bool &ADone);

class PASCALIMPLEMENTATION TdxStatusBarPanel : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TdxStatusBarPanelBevel FBevel;
	System::Classes::TBiDiMode FBiDiMode;
	bool FFixed;
	bool FIsMinWidthAssigned;
	bool FIsWidthAssigned;
	int FMinWidth;
	TdxStatusBarPanelStyle* FPanelStyle;
	TdxStatusBarPanelStyleClass FPanelStyleClass;
	System::Classes::TNotifyEvent FPanelStyleEvents;
	bool FParentBiDiMode;
	System::UnicodeString FText;
	bool FVisible;
	int FWidth;
	System::Classes::TNotifyEvent FOnClick;
	System::Classes::TNotifyEvent FOnDblClick;
	TdxStatusBarDrawPanelEvent FOnDrawPanel;
	bool __fastcall GetFixed(void);
	Cxlookandfeels::TcxLookAndFeel* __fastcall GetLookAndFeel(void);
	int __fastcall GetMinWidth(void);
	System::UnicodeString __fastcall GetPanelStyleClassName(void);
	TdxCustomStatusBar* __fastcall GetStatusBarControl(void);
	int __fastcall GetWidth(void);
	bool __fastcall IsBiDiModeStored(void);
	bool __fastcall IsMinWidthStored(void);
	bool __fastcall IsWidthStored(void);
	void __fastcall SetBevel(TdxStatusBarPanelBevel Value);
	void __fastcall SetBiDiMode(System::Classes::TBiDiMode Value);
	void __fastcall SetFixed(bool Value);
	void __fastcall SetMinWidth(int Value);
	void __fastcall SetPanelStyle(TdxStatusBarPanelStyle* Value);
	void __fastcall SetPanelStyleClass(const TdxStatusBarPanelStyleClass Value);
	void __fastcall SetPanelStyleClassName(System::UnicodeString Value);
	void __fastcall SetParentBiDiMode(bool Value);
	void __fastcall SetText(const System::UnicodeString Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetWidth(int Value);
	
protected:
	virtual void __fastcall Click(void);
	virtual void __fastcall CreatePanelStyle(void);
	virtual void __fastcall DblClick(void);
	virtual int __fastcall DefaultMinWidth(void);
	virtual int __fastcall DefaultWidth(void);
	virtual void __fastcall DestroyPanelStyle(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	void __fastcall Loaded(void);
	virtual int __fastcall PaintMinWidth(void);
	virtual int __fastcall PaintWidth(void);
	virtual void __fastcall PreparePaintWidth(int &AWidth);
	virtual void __fastcall StatusBarPanelStyleChanged(void);
	virtual void __fastcall UpdateSubControlsVisibility(void);
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=GetLookAndFeel};
	
public:
	__fastcall virtual TdxStatusBarPanel(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxStatusBarPanel(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall RestoreDefaults(void);
	void __fastcall ParentBiDiModeChanged(void);
	bool __fastcall UseRightToLeftAlignment(void);
	bool __fastcall UseRightToLeftReading(void);
	__property TdxStatusBarPanelStyleClass PanelStyleClass = {read=FPanelStyleClass, write=SetPanelStyleClass};
	__property TdxCustomStatusBar* StatusBarControl = {read=GetStatusBarControl};
	
__published:
	__property System::UnicodeString PanelStyleClassName = {read=GetPanelStyleClassName, write=SetPanelStyleClassName};
	__property TdxStatusBarPanelStyle* PanelStyle = {read=FPanelStyle, write=SetPanelStyle};
	__property System::Classes::TNotifyEvent PanelStyleEvents = {read=FPanelStyleEvents, write=FPanelStyleEvents};
	__property TdxStatusBarPanelBevel Bevel = {read=FBevel, write=SetBevel, default=1};
	__property System::Classes::TBiDiMode BiDiMode = {read=FBiDiMode, write=SetBiDiMode, stored=IsBiDiModeStored, nodefault};
	__property bool Fixed = {read=GetFixed, write=SetFixed, default=1};
	__property int MinWidth = {read=GetMinWidth, write=SetMinWidth, stored=IsMinWidthStored, nodefault};
	__property bool ParentBiDiMode = {read=FParentBiDiMode, write=SetParentBiDiMode, default=1};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
	__property int Width = {read=GetWidth, write=SetWidth, stored=IsWidthStored, nodefault};
	__property System::Classes::TNotifyEvent OnClick = {read=FOnClick, write=FOnClick};
	__property System::Classes::TNotifyEvent OnDblClick = {read=FOnDblClick, write=FOnDblClick};
	__property TdxStatusBarDrawPanelEvent OnDrawPanel = {read=FOnDrawPanel, write=FOnDrawPanel};
};


class DELPHICLASS TdxStatusBarPanels;
class PASCALIMPLEMENTATION TdxStatusBarPanels : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxStatusBarPanel* operator[](int Index) { return Items[Index]; }
	
private:
	TdxCustomStatusBar* FStatusBarControl;
	HIDESBASE TdxStatusBarPanel* __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, TdxStatusBarPanel* Value);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	void __fastcall Loaded(void);
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	void __fastcall UpdateSubControlsVisibility(void);
	
public:
	__fastcall TdxStatusBarPanels(TdxCustomStatusBar* AStatusBarControl);
	HIDESBASE TdxStatusBarPanel* __fastcall Add(void);
	HIDESBASE TdxStatusBarPanel* __fastcall Insert(int Index);
	__property TdxStatusBarPanel* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxStatusBarPanels(void) { }
	
};


class DELPHICLASS TdxStatusBarSimplePanelStyle;
class PASCALIMPLEMENTATION TdxStatusBarSimplePanelStyle : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FActive;
	bool FAutoHint;
	TdxCustomStatusBar* FStatusBar;
	System::UnicodeString FText;
	void __fastcall SetActive(const bool AValue);
	void __fastcall SetText(const System::UnicodeString AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* ASource);
	__property TdxCustomStatusBar* StatusBar = {read=FStatusBar};
	
public:
	__fastcall virtual TdxStatusBarSimplePanelStyle(TdxCustomStatusBar* AStatusBar);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool Active = {read=FActive, write=SetActive, default=0};
	__property bool AutoHint = {read=FAutoHint, write=FAutoHint, default=0};
	__property System::UnicodeString Text = {read=FText, write=SetText};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxStatusBarSimplePanelStyle(void) { }
	
};


typedef System::TMetaClass* TdxStatusBarSimplePanelStyleClass;

enum TdxStatusBarPaintStyle : unsigned char { stpsStandard, stpsFlat, stpsXP, stpsOffice11, stpsUseLookAndFeel };

class DELPHICLASS TdxStatusBarPainter;
class PASCALIMPLEMENTATION TdxStatusBarPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual void __fastcall DrawContainerControl(TdxStatusBarContainerPanelStyle* APanelStyle);
	
public:
	__classmethod virtual void __fastcall AdjustTextColor(TdxCustomStatusBar* AStatusBar, System::Uitypes::TColor &AColor, bool Active);
	__classmethod virtual System::Types::TRect __fastcall ContentExtents(TdxCustomStatusBar* AStatusBar);
	__classmethod virtual System::Types::TSize __fastcall GripAreaSize();
	__classmethod virtual System::Types::TSize __fastcall GripSize();
	__classmethod virtual bool __fastcall IsNativeBackground();
	__classmethod virtual bool __fastcall IsSizeGripInPanelArea(TdxCustomStatusBar* AStatusBar);
	__classmethod virtual System::Types::TRect __fastcall PanelBorderSizes(TdxStatusBarPanelBevel ABevel);
	__classmethod virtual System::Types::TRect __fastcall PanelContentExtents(TdxCustomStatusBar* AStatusBar, bool AHasBorders);
	__classmethod virtual int __fastcall SeparatorSize();
	__classmethod virtual int __fastcall SeparatorSizeEx(TdxCustomStatusBar* AStatusBar);
	__classmethod virtual System::Types::TRect __fastcall SizeGripMargins(TdxCustomStatusBar* AStatusBar);
	__classmethod virtual int __fastcall TopBorderSize();
	__classmethod virtual void __fastcall DrawBorder(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawEmptyPanel(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanel(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanel* APanel, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelBorder(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanelBevel ABevel, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelSeparator(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawSimplePanel(TdxCustomStatusBar* AStatusBar, const System::UnicodeString AText, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawSizeGrip(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawTopBorder(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall FillBackground(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanel* APanel, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual TdxStatusBarPanelBevel __fastcall GetPanelBevel(TdxStatusBarPanel* APanel);
	__classmethod virtual System::Uitypes::TColor __fastcall GetPanelColor(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanel* APanel);
	__classmethod virtual System::Types::TRect __fastcall ValidatePanelTextRect(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanel* APanel, const System::Types::TRect &R);
public:
	/* TObject.Create */ inline __fastcall TdxStatusBarPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarPainter(void) { }
	
};


class DELPHICLASS TdxStatusBarStandardPainter;
class PASCALIMPLEMENTATION TdxStatusBarStandardPainter : public TdxStatusBarPainter
{
	typedef TdxStatusBarPainter inherited;
	
public:
	__classmethod virtual void __fastcall DrawPanelBorder(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanelBevel ABevel, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelSeparator(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall FillBackground(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanel* APanel, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual System::Types::TRect __fastcall PanelBorderSizes(TdxStatusBarPanelBevel ABevel);
public:
	/* TObject.Create */ inline __fastcall TdxStatusBarStandardPainter(void) : TdxStatusBarPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarStandardPainter(void) { }
	
};


class DELPHICLASS TdxStatusBarFlatPainter;
class PASCALIMPLEMENTATION TdxStatusBarFlatPainter : public TdxStatusBarStandardPainter
{
	typedef TdxStatusBarStandardPainter inherited;
	
public:
	__classmethod virtual void __fastcall DrawPanelBorder(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanelBevel ABevel, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual System::Types::TRect __fastcall PanelBorderSizes(TdxStatusBarPanelBevel ABevel);
public:
	/* TObject.Create */ inline __fastcall TdxStatusBarFlatPainter(void) : TdxStatusBarStandardPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarFlatPainter(void) { }
	
};


class DELPHICLASS TdxStatusBarOffice11Painter;
class PASCALIMPLEMENTATION TdxStatusBarOffice11Painter : public TdxStatusBarPainter
{
	typedef TdxStatusBarPainter inherited;
	
public:
	__classmethod virtual System::Types::TRect __fastcall ContentExtents(TdxCustomStatusBar* AStatusBar);
	__classmethod virtual System::Types::TRect __fastcall SizeGripMargins(TdxCustomStatusBar* AStatusBar);
	__classmethod virtual void __fastcall DrawBorder(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelBorder(TdxCustomStatusBar* AStatusBar, TdxStatusBarPanelBevel ABevel, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelSeparator(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawSizeGrip(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual System::Types::TRect __fastcall PanelBorderSizes(TdxStatusBarPanelBevel ABevel);
public:
	/* TObject.Create */ inline __fastcall TdxStatusBarOffice11Painter(void) : TdxStatusBarPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarOffice11Painter(void) { }
	
};


class DELPHICLASS TdxStatusBarXPPainter;
class PASCALIMPLEMENTATION TdxStatusBarXPPainter : public TdxStatusBarPainter
{
	typedef TdxStatusBarPainter inherited;
	
public:
	__classmethod virtual System::Types::TRect __fastcall ContentExtents(TdxCustomStatusBar* AStatusBar);
	__classmethod virtual System::Types::TSize __fastcall GripAreaSize();
	__classmethod virtual int __fastcall SeparatorSize();
	__classmethod virtual System::Types::TRect __fastcall SizeGripMargins(TdxCustomStatusBar* AStatusBar);
	__classmethod virtual void __fastcall DrawBorder(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelSeparator(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawSizeGrip(TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
public:
	/* TObject.Create */ inline __fastcall TdxStatusBarXPPainter(void) : TdxStatusBarPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarXPPainter(void) { }
	
};


class DELPHICLASS TdxStatusBarCustomPanelViewInfo;
class PASCALIMPLEMENTATION TdxStatusBarCustomPanelViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Types::TRect FBounds;
	TdxCustomStatusBar* FStatusBar;
	TdxStatusBarPainterClass __fastcall GetPainter(void);
	
protected:
	virtual TdxStatusBarPanelBevel __fastcall GetPanelBevel(void) = 0 ;
	virtual Vcl::Graphics::TFont* __fastcall GetPanelFont(void);
	virtual void __fastcall SetBounds(const System::Types::TRect &AValue);
	
public:
	__fastcall virtual TdxStatusBarCustomPanelViewInfo(TdxCustomStatusBar* AStatusBar);
	virtual int __fastcall CalculateAutoHeight(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas) = 0 ;
	__property System::Types::TRect Bounds = {read=FBounds, write=SetBounds};
	__property TdxStatusBarPainterClass Painter = {read=GetPainter};
	__property TdxStatusBarPanelBevel PanelBevel = {read=GetPanelBevel, nodefault};
	__property Vcl::Graphics::TFont* PanelFont = {read=GetPanelFont};
	__property TdxCustomStatusBar* StatusBar = {read=FStatusBar};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarCustomPanelViewInfo(void) { }
	
};


class DELPHICLASS TdxStatusBarPanelViewInfo;
class PASCALIMPLEMENTATION TdxStatusBarPanelViewInfo : public TdxStatusBarCustomPanelViewInfo
{
	typedef TdxStatusBarCustomPanelViewInfo inherited;
	
private:
	TdxStatusBarPanel* FPanel;
	System::Types::TRect FSeparatorRect;
	bool __fastcall GetHasSeparator(void);
	
protected:
	virtual TdxStatusBarPanelBevel __fastcall GetPanelBevel(void);
	virtual Vcl::Graphics::TFont* __fastcall GetPanelFont(void);
	virtual void __fastcall SetBounds(const System::Types::TRect &AValue);
	
public:
	__fastcall TdxStatusBarPanelViewInfo(TdxStatusBarPanel* APanel);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property TdxStatusBarPanel* Panel = {read=FPanel};
	__property bool HasSeparator = {read=GetHasSeparator, nodefault};
	__property System::Types::TRect SeparatorRect = {read=FSeparatorRect, write=FSeparatorRect};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarPanelViewInfo(void) { }
	
};


class DELPHICLASS TdxStatusBarSimplePanelViewInfo;
class PASCALIMPLEMENTATION TdxStatusBarSimplePanelViewInfo : public TdxStatusBarCustomPanelViewInfo
{
	typedef TdxStatusBarCustomPanelViewInfo inherited;
	
protected:
	virtual TdxStatusBarPanelBevel __fastcall GetPanelBevel(void);
	
public:
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TdxStatusBarCustomPanelViewInfo.Create */ inline __fastcall virtual TdxStatusBarSimplePanelViewInfo(TdxCustomStatusBar* AStatusBar) : TdxStatusBarCustomPanelViewInfo(AStatusBar) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarSimplePanelViewInfo(void) { }
	
};


class DELPHICLASS TdxStatusBarViewInfo;
class PASCALIMPLEMENTATION TdxStatusBarViewInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxObjectList* FPanelsViewInfos;
	TdxStatusBarSimplePanelViewInfo* FSimplePanelViewInfo;
	System::Types::TRect FSizeGripRect;
	TdxCustomStatusBar* FStatusBar;
	TdxStatusBarPainterClass __fastcall GetPainter(void);
	TdxStatusBarPanel* __fastcall GetPanel(int Index);
	int __fastcall GetPanelCount(void);
	TdxStatusBarPanelViewInfo* __fastcall GetPanelViewInfo(int Index);
	System::Types::TRect __fastcall GetSizeGripAreaRect(void);
	
protected:
	void __fastcall AddCalculatedItems(Cxclasses::TcxAutoWidthObject* AAutoWidthObject);
	void __fastcall CalculatePanelsViewInfos(const System::Types::TRect &ABounds, Cxclasses::TcxAutoWidthObject* AAutoWidthObject);
	System::Types::TRect __fastcall CalculateSizeGripRect(const System::Types::TRect &ABounds);
	virtual TdxStatusBarPanelViewInfo* __fastcall CreatePanelViewInfo(TdxStatusBarPanel* APanel);
	virtual TdxStatusBarSimplePanelViewInfo* __fastcall CreateSimplePanelViewInfo(void);
	void __fastcall DrawPanels(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	void __fastcall DrawSizeGrip(Cxgraphics::TcxCanvas* ACanvas);
	int __fastcall GetCalculatedItemCount(void);
	TdxStatusBarPanel* __fastcall GetPanelAt(const System::Types::TPoint P);
	virtual bool __fastcall IsSizeGripInPanelArea(void);
	void __fastcall RecreateChildrenViewInfo(void);
	__property TdxStatusBarPainterClass Painter = {read=GetPainter};
	
public:
	__fastcall virtual TdxStatusBarViewInfo(TdxCustomStatusBar* AOwner);
	__fastcall virtual ~TdxStatusBarViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	virtual int __fastcall CalculateAutoHeight(void);
	virtual void __fastcall Draw(Cxgraphics::TcxCanvas* ACanvas);
	__property int PanelCount = {read=GetPanelCount, nodefault};
	__property TdxStatusBarPanel* Panels[int Index] = {read=GetPanel};
	__property TdxStatusBarPanelViewInfo* PanelViewInfo[int Index] = {read=GetPanelViewInfo};
	__property TdxStatusBarSimplePanelViewInfo* SimplePanelViewInfo = {read=FSimplePanelViewInfo};
	__property System::Types::TRect SizeGripAreaRect = {read=GetSizeGripAreaRect};
	__property System::Types::TRect SizeGripRect = {read=FSizeGripRect};
	__property TdxCustomStatusBar* StatusBar = {read=FStatusBar};
};


enum TdxStatusBarState : unsigned char { sbsCalculating };

typedef System::Set<TdxStatusBarState, TdxStatusBarState::sbsCalculating, TdxStatusBarState::sbsCalculating>  TdxStatusBarStates;

typedef void __fastcall (__closure *TdxStatusBarPanelCreateClassEvent)(TdxCustomStatusBar* Sender, TdxStatusBarPanelClass &AStatusPanelClass);

class PASCALIMPLEMENTATION TdxCustomStatusBar : public Cxcontrols::TcxControl
{
	typedef Cxcontrols::TcxControl inherited;
	
private:
	int FBorderWidth;
	Vcl::Imglist::TChangeLink* FImageChangeLink;
	Vcl::Imglist::TCustomImageList* FImages;
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	TdxStatusBarPainterClass FPainter;
	TdxStatusBarPaintStyle FPaintStyle;
	TdxStatusBarPanels* FPanels;
	TdxStatusBarSimplePanelStyle* FSimplePanelStyle;
	bool FSizeGrip;
	bool FThemeAvailable;
	Dxthememanager::TdxThemeChangedNotificator* FThemeChangedNotificator;
	TdxStatusBarViewInfo* FViewInfo;
	System::Classes::TNotifyEvent FOnHint;
	void __fastcall ImageListChange(System::TObject* Sender);
	HIDESBASE void __fastcall LookAndFeelChangeHandler(Cxlookandfeels::TcxLookAndFeel* Sender, Cxlookandfeels::TcxLookAndFeelValues AChangedValues);
	HIDESBASE void __fastcall SetBorderWidth(int Value);
	void __fastcall SetImages(Vcl::Imglist::TCustomImageList* const Value);
	HIDESBASE void __fastcall SetLookAndFeel(Cxlookandfeels::TcxLookAndFeel* Value);
	void __fastcall SetPanels(TdxStatusBarPanels* Value);
	void __fastcall SetPaintStyle(TdxStatusBarPaintStyle Value);
	void __fastcall SetSimplePanelStyle(TdxStatusBarSimplePanelStyle* Value);
	void __fastcall SetSizeGrip(bool Value);
	HIDESBASE MESSAGE void __fastcall CMBiDiModeChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMParentFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMSysColorChange(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMWinIniChange(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	
protected:
	TdxStatusBarStates FState;
	virtual void __fastcall AdjustTextColor(System::Uitypes::TColor &AColor, bool Active);
	virtual bool __fastcall CanAutoSize(int &NewWidth, int &NewHeight);
	void __fastcall CheckAutoSize(void);
	virtual TdxStatusBarViewInfo* __fastcall CreateViewInfo(void);
	DYNAMIC void __fastcall FontChanged(void);
	virtual bool __fastcall HasBackground(void);
	virtual void __fastcall Loaded(void);
	DYNAMIC bool __fastcall MayFocus(void);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual bool __fastcall NeedsScrollBars(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	virtual void __fastcall Calculate(void);
	virtual int __fastcall CalculateAutoHeight(void);
	TdxStatusBarContainerControl* __fastcall ContainerByName(const System::UnicodeString AName);
	virtual TdxStatusBarPanel* __fastcall CreatePanel(void);
	virtual TdxStatusBarPanels* __fastcall CreatePanels(void);
	virtual bool __fastcall DoHint(void);
	__classmethod virtual TdxStatusBarPanelStyleClass __fastcall GetDeafultPanelStyleClass();
	virtual TdxStatusBarPainterClass __fastcall GetPainterClass(void);
	virtual TdxStatusBarPaintStyle __fastcall GetPaintStyle(void);
	System::Types::TRect __fastcall GetPanelsBounds(void);
	virtual System::Types::TRect __fastcall GetPanelsOffsets(void);
	__classmethod virtual TdxStatusBarPanelClass __fastcall GetStatusPanelClass();
	virtual void __fastcall InitPainterClass(void);
	virtual void __fastcall PaintStyleChanged(void);
	void __fastcall Recalculate(void);
	virtual bool __fastcall SizeGripAllocated(void);
	virtual void __fastcall ThemeChanged(void);
	virtual void __fastcall UpdatePanels(void);
	__property int BorderWidth = {read=FBorderWidth, write=SetBorderWidth, default=0};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel, write=SetLookAndFeel};
	__property TdxStatusBarPainterClass Painter = {read=FPainter};
	__property TdxStatusBarPaintStyle PaintStyle = {read=FPaintStyle, write=SetPaintStyle, default=0};
	__property TdxStatusBarPanels* Panels = {read=FPanels, write=SetPanels};
	__property TdxStatusBarSimplePanelStyle* SimplePanelStyle = {read=FSimplePanelStyle, write=SetSimplePanelStyle};
	__property bool SizeGrip = {read=FSizeGrip, write=SetSizeGrip, default=1};
	__property TdxStatusBarViewInfo* ViewInfo = {read=FViewInfo};
	
public:
	__fastcall virtual TdxCustomStatusBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomStatusBar(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall CanAcceptPanelStyle(TdxStatusBarPanelStyleClass Value);
	virtual TdxStatusBarPanel* __fastcall GetPanelAt(int X, int Y);
	__property System::Classes::TNotifyEvent OnHint = {read=FOnHint, write=FOnHint};
	
__published:
	__property AutoSize = {default=0};
	__property Vcl::Imglist::TCustomImageList* Images = {read=FImages, write=SetImages};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomStatusBar(HWND ParentWindow) : Cxcontrols::TcxControl(ParentWindow) { }
	
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
	
};


class DELPHICLASS TdxStatusBar;
class PASCALIMPLEMENTATION TdxStatusBar : public TdxCustomStatusBar
{
	typedef TdxCustomStatusBar inherited;
	
__published:
	__property Images;
	__property Panels;
	__property PaintStyle = {default=0};
	__property SimplePanelStyle;
	__property SizeGrip = {default=1};
	__property LookAndFeel;
	__property OnHint;
	__property BorderWidth = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Color = {default=-16777201};
	__property Constraints;
	__property ShowHint;
	__property ParentBiDiMode = {default=1};
	__property ParentFont = {default=0};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property Visible = {default=1};
	__property OnContextPopup;
	__property OnClick;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnResize;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TdxCustomStatusBar.Create */ inline __fastcall virtual TdxStatusBar(System::Classes::TComponent* AOwner) : TdxCustomStatusBar(AOwner) { }
	/* TdxCustomStatusBar.Destroy */ inline __fastcall virtual ~TdxStatusBar(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxStatusBar(HWND ParentWindow) : TdxCustomStatusBar(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxStatusBarPainterClass dxStatusBarSkinPainterClass;
extern PACKAGE Cxclasses::TcxRegisteredClasses* __fastcall GetRegisteredStatusBarPanelStyles(void);
extern PACKAGE void __fastcall LoadIndicatorBitmap(Vcl::Graphics::TBitmap* ABitmap, TdxStatusBarStateIndicatorType AIndicatorType);
}	/* namespace Dxstatusbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSTATUSBAR)
using namespace Dxstatusbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxstatusbarHPP
