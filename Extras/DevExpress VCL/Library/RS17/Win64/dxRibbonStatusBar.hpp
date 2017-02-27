// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonStatusBar.pas' rev: 24.00 (Win64)

#ifndef DxribbonstatusbarHPP
#define DxribbonstatusbarHPP

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
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxStatusBar.hpp>	// Pascal unit
#include <dxRibbonSkins.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <dxRibbonFormCaptionHelper.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonstatusbar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxRibbonStatusBarBarControlPainter;
class DELPHICLASS TdxRibbonStatusBar;
class PASCALIMPLEMENTATION TdxRibbonStatusBarBarControlPainter : public Dxbar::TdxBarSkinnedPainter
{
	typedef Dxbar::TdxBarSkinnedPainter inherited;
	
protected:
	virtual void __fastcall DrawToolbarContentPart(Dxbar::TdxBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawToolbarNonContentPart(Dxbar::TdxBarControl* ABarControl, HDC DC);
	
public:
	virtual int __fastcall BarBeginGroupSize(void);
	virtual void __fastcall BarDrawBeginGroup(Dxbar::TCustomdxBarControl* ABarControl, HDC DC, System::Types::TRect &ABeginGroupRect, HBRUSH AToolbarBrush, bool AHorz);
	virtual int __fastcall GetButtonBorderHeight(void);
	virtual System::Uitypes::TColor __fastcall GetEnabledTextColor(Dxbar::TdxBarItemControl* ABarItemControl, bool ASelected, bool AFlat);
	virtual void __fastcall GetDisabledTextColors(Dxbar::TdxBarItemControl* ABarItemControl, bool ASelected, bool AFlat, System::Uitypes::TColor &AColor1, System::Uitypes::TColor &AColor2);
	virtual System::Types::TRect __fastcall GetToolbarContentOffsets(Dxbar::TdxBar* ABar, Dxbar::TdxBarDockingStyle ADockingStyle, bool AHasSizeGrip);
	virtual int __fastcall MarkButtonOffset(void);
	virtual int __fastcall MarkSizeX(Dxbar::TdxBarControl* ABarControl);
	bool __fastcall GetColorScheme(Dxbar::TCustomdxBarControl* ABarControl, /* out */ Dxribbonskins::TdxCustomRibbonSkin* &AColorScheme, /* out */ Dxribbonskins::TdxRibbonColorSchemeAccent &AColorSchemeAccent);
	bool __fastcall GetIsPanelLowered(Dxbar::TCustomdxBarControl* ABarControl);
	TdxRibbonStatusBar* __fastcall GetStatusBar(Dxbar::TCustomdxBarControl* ABarControl);
public:
	/* TdxBarSkinnedPainter.Create */ inline __fastcall virtual TdxRibbonStatusBarBarControlPainter(NativeUInt AData) : Dxbar::TdxBarSkinnedPainter(AData) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonStatusBarBarControlPainter(void) { }
	
};


class DELPHICLASS TdxDefaultRibbonStatusBarBarControlPainter;
class PASCALIMPLEMENTATION TdxDefaultRibbonStatusBarBarControlPainter : public Dxbar::TdxBarFlatPainter
{
	typedef Dxbar::TdxBarFlatPainter inherited;
	
public:
	virtual int __fastcall GetButtonBorderHeight(void);
	virtual System::Types::TRect __fastcall GetToolbarContentOffsets(Dxbar::TdxBar* ABar, Dxbar::TdxBarDockingStyle ADockingStyle, bool AHasSizeGrip);
	virtual int __fastcall MarkButtonOffset(void);
	virtual int __fastcall MarkSizeX(Dxbar::TdxBarControl* ABarControl);
public:
	/* TdxBarPainter.Create */ inline __fastcall virtual TdxDefaultRibbonStatusBarBarControlPainter(NativeUInt AData) : Dxbar::TdxBarFlatPainter(AData) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxDefaultRibbonStatusBarBarControlPainter(void) { }
	
};


class DELPHICLASS TdxRibbonStatusBarBarControlViewInfo;
class PASCALIMPLEMENTATION TdxRibbonStatusBarBarControlViewInfo : public Dxribbon::TdxRibbonQuickAccessBarControlViewInfo
{
	typedef Dxribbon::TdxRibbonQuickAccessBarControlViewInfo inherited;
	
protected:
	virtual bool __fastcall CanShowButtonGroups(void);
	virtual bool __fastcall CanShowSeparators(void);
public:
	/* TCustomdxBarControlViewInfo.Create */ inline __fastcall virtual TdxRibbonStatusBarBarControlViewInfo(Dxbar::TCustomdxBarControl* ABarControl) : Dxribbon::TdxRibbonQuickAccessBarControlViewInfo(ABarControl) { }
	/* TCustomdxBarControlViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonStatusBarBarControlViewInfo(void) { }
	
};


class DELPHICLASS TdxRibbonStatusBarBarControl;
class PASCALIMPLEMENTATION TdxRibbonStatusBarBarControl : public Dxribbon::TdxRibbonQuickAccessBarControl
{
	typedef Dxribbon::TdxRibbonQuickAccessBarControl inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	TdxRibbonStatusBar* __fastcall GetStatusBar(void);
	
protected:
	virtual void __fastcall DoPaintItem(Dxbar::TdxBarItemControl* AControl, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &AItemRect);
	virtual Dxbar::TdxBarBehaviorOptions __fastcall GetBehaviorOptions(void);
	virtual Vcl::Graphics::TBitmap* __fastcall GetDefaultItemGlyph(void);
	virtual Dxbar::TdxBarItemViewLevel __fastcall GetItemControlDefaultViewLevel(Dxbar::TdxBarItemControl* AItemControl);
	virtual int __fastcall GetMinHeight(Dxbar::TdxBarDockingStyle AStyle);
	virtual Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	virtual Dxbar::TCustomdxBarControlViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall InitCustomizationPopup(Dxbar::TdxBarItemLinks* AItemLinks);
	bool __fastcall IsValid(void);
	virtual bool __fastcall MarkExists(void);
	virtual void __fastcall UpdateDoubleBuffered(void);
	__property TdxRibbonStatusBar* StatusBar = {read=GetStatusBar};
public:
	/* TdxRibbonQuickAccessBarControl.Create */ inline __fastcall virtual TdxRibbonStatusBarBarControl(System::Classes::TComponent* AOwner) : Dxribbon::TdxRibbonQuickAccessBarControl(AOwner) { }
	/* TdxRibbonQuickAccessBarControl.Destroy */ inline __fastcall virtual ~TdxRibbonStatusBarBarControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonStatusBarBarControl(HWND ParentWindow) : Dxribbon::TdxRibbonQuickAccessBarControl(ParentWindow) { }
	
};


class DELPHICLASS TdxRibbonStatusBarBarControlDesignHelper;
class PASCALIMPLEMENTATION TdxRibbonStatusBarBarControlDesignHelper : public Dxbar::TCustomdxBarControlDesignHelper
{
	typedef Dxbar::TCustomdxBarControlDesignHelper inherited;
	
public:
	__classmethod virtual Dxbar::TdxBarCustomizationActions __fastcall GetForbiddenActions();
public:
	/* TObject.Create */ inline __fastcall TdxRibbonStatusBarBarControlDesignHelper(void) : Dxbar::TCustomdxBarControlDesignHelper() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonStatusBarBarControlDesignHelper(void) { }
	
};


class DELPHICLASS TdxRibbonStatusBarDockControl;
class DELPHICLASS TdxStatusBarToolbarPanelStyle;
class PASCALIMPLEMENTATION TdxRibbonStatusBarDockControl : public Dxribbon::TdxCustomRibbonDockControl
{
	typedef Dxribbon::TdxCustomRibbonDockControl inherited;
	
private:
	TdxRibbonStatusBar* FStatusBar;
	Dxbar::TdxBarPainter* FPainter;
	Dxstatusbar::TdxStatusBarPanel* FPanel;
	TdxRibbonStatusBarBarControl* __fastcall GetBarControl(void);
	Dxribbonskins::TdxCustomRibbonSkin* __fastcall GetColorScheme(void);
	Dxribbon::TdxCustomRibbon* __fastcall GetRibbon(void);
	
protected:
	virtual void __fastcall CalcLayout(void);
	virtual void __fastcall FreePainter(void);
	virtual void __fastcall UpdateDoubleBuffered(void);
	virtual void __fastcall FillBackground(HDC DC, const System::Types::TRect &ADestR, const System::Types::TRect &ASourceR, HBRUSH ABrush, System::Uitypes::TColor AColor);
	virtual Dxbar::TdxBarControlClass __fastcall GetDockedBarControlClass(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	virtual Dxbar::TdxBarPainter* __fastcall GetPainter(void);
	virtual void __fastcall ShowCustomizePopup(void);
	virtual void __fastcall VisibleChanged(void);
	__property TdxRibbonStatusBarBarControl* BarControl = {read=GetBarControl};
	
public:
	__fastcall virtual TdxRibbonStatusBarDockControl(TdxStatusBarToolbarPanelStyle* AOwner);
	__fastcall virtual ~TdxRibbonStatusBarDockControl(void);
	__property Dxribbonskins::TdxCustomRibbonSkin* ColorScheme = {read=GetColorScheme};
	__property Dxstatusbar::TdxStatusBarPanel* Panel = {read=FPanel};
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=GetRibbon};
	__property TdxRibbonStatusBar* StatusBar = {read=FStatusBar};
public:
	/* TdxDockControl.CreateEx */ inline __fastcall TdxRibbonStatusBarDockControl(System::Classes::TComponent* AOwner, Dxbar::TdxBarManager* ABarManager, Dxbar::TdxBarDockingStyle ADockStyle) : Dxribbon::TdxCustomRibbonDockControl(AOwner, ABarManager, ADockStyle) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonStatusBarDockControl(HWND ParentWindow) : Dxribbon::TdxCustomRibbonDockControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TdxStatusBarToolbarPanelStyle : public Dxstatusbar::TdxStatusBarPanelStyle
{
	typedef Dxstatusbar::TdxStatusBarPanelStyle inherited;
	
private:
	TdxRibbonStatusBarDockControl* FDockControl;
	System::UnicodeString FLoadedToolbarName;
	Dxbar::TdxBar* FToolbar;
	Dxbar::TdxBar* __fastcall GetToolbar(void);
	void __fastcall ReadToolbarName(System::Classes::TReader* AReader);
	void __fastcall SetToolbar(Dxbar::TdxBar* Value);
	void __fastcall UpdateToolbarValue(void);
	void __fastcall WriteToolbarName(System::Classes::TWriter* AWriter);
	
protected:
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanSizing(void);
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R, Dxstatusbar::TdxStatusBarPainterClass APainter);
	virtual int __fastcall GetMinWidth(void);
	__classmethod virtual int __fastcall GetVersion();
	virtual void __fastcall Loaded(void);
	virtual void __fastcall UpdateSubControlsVisibility(void);
	virtual void __fastcall UpdateToolbarPainter(void);
	Dxbar::TdxBarManager* __fastcall FindBarManager(void);
	virtual void __fastcall UpdateByRibbon(Dxribbon::TdxCustomRibbon* ARibbon);
	
public:
	__fastcall virtual TdxStatusBarToolbarPanelStyle(Dxstatusbar::TdxStatusBarPanel* AOwner);
	__fastcall virtual ~TdxStatusBarToolbarPanelStyle(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxRibbonStatusBarDockControl* DockControl = {read=FDockControl};
	
__published:
	__property Dxbar::TdxBar* Toolbar = {read=GetToolbar, write=SetToolbar, stored=false};
};


class DELPHICLASS TdxStatusBarToolbarPanelViewInfo;
class PASCALIMPLEMENTATION TdxStatusBarToolbarPanelViewInfo : public Dxstatusbar::TdxStatusBarPanelViewInfo
{
	typedef Dxstatusbar::TdxStatusBarPanelViewInfo inherited;
	
private:
	TdxStatusBarToolbarPanelStyle* __fastcall GetPanelStyle(void);
	
public:
	virtual int __fastcall CalculateAutoHeight(void);
	__property TdxStatusBarToolbarPanelStyle* PanelStyle = {read=GetPanelStyle};
public:
	/* TdxStatusBarPanelViewInfo.Create */ inline __fastcall TdxStatusBarToolbarPanelViewInfo(Dxstatusbar::TdxStatusBarPanel* APanel) : Dxstatusbar::TdxStatusBarPanelViewInfo(APanel) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStatusBarToolbarPanelViewInfo(void) { }
	
};


class DELPHICLASS TdxRibbonStatusBarPainter;
class PASCALIMPLEMENTATION TdxRibbonStatusBarPainter : public Dxstatusbar::TdxStatusBarPainter
{
	typedef Dxstatusbar::TdxStatusBarPainter inherited;
	
public:
	__classmethod virtual System::Types::TRect __fastcall ContentExtents(Dxstatusbar::TdxCustomStatusBar* AStatusBar);
	__classmethod virtual System::Types::TSize __fastcall GripAreaSize();
	__classmethod virtual int __fastcall SeparatorSizeEx(Dxstatusbar::TdxCustomStatusBar* AStatusBar);
	__classmethod virtual System::Types::TRect __fastcall SizeGripMargins(Dxstatusbar::TdxCustomStatusBar* AStatusBar);
	__classmethod virtual void __fastcall DrawBorder(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelBorder(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Dxstatusbar::TdxStatusBarPanelBevel ABevel, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawPanelSeparator(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	__classmethod virtual void __fastcall DrawSizeGrip(Dxstatusbar::TdxCustomStatusBar* AStatusBar, Cxgraphics::TcxCanvas* ACanvas, System::Types::TRect &R);
	__classmethod virtual Dxstatusbar::TdxStatusBarPanelBevel __fastcall GetPanelBevel(Dxstatusbar::TdxStatusBarPanel* APanel);
	__classmethod virtual int __fastcall TopBorderSize();
public:
	/* TObject.Create */ inline __fastcall TdxRibbonStatusBarPainter(void) : Dxstatusbar::TdxStatusBarPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxRibbonStatusBarPainter(void) { }
	
};


class DELPHICLASS TdxRibbonStatusBarViewInfo;
class PASCALIMPLEMENTATION TdxRibbonStatusBarViewInfo : public Dxstatusbar::TdxStatusBarViewInfo
{
	typedef Dxstatusbar::TdxStatusBarViewInfo inherited;
	
private:
	TdxRibbonStatusBar* __fastcall GetStatusBar(void);
	
protected:
	bool __fastcall CanUpdateDockControls(void);
	virtual Dxstatusbar::TdxStatusBarPanelViewInfo* __fastcall CreatePanelViewInfo(Dxstatusbar::TdxStatusBarPanel* APanel);
	virtual bool __fastcall IsSizeGripInPanelArea(void);
	void __fastcall UpdateDockControls(const System::Types::TRect &ABounds);
	
public:
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds);
	__property TdxRibbonStatusBar* StatusBar = {read=GetStatusBar};
public:
	/* TdxStatusBarViewInfo.Create */ inline __fastcall virtual TdxRibbonStatusBarViewInfo(Dxstatusbar::TdxCustomStatusBar* AOwner) : Dxstatusbar::TdxStatusBarViewInfo(AOwner) { }
	/* TdxStatusBarViewInfo.Destroy */ inline __fastcall virtual ~TdxRibbonStatusBarViewInfo(void) { }
	
};


class PASCALIMPLEMENTATION TdxRibbonStatusBar : public Dxstatusbar::TdxCustomStatusBar
{
	typedef Dxstatusbar::TdxCustomStatusBar inherited;
	
private:
	System::Uitypes::TColor FColor;
	bool FCreating;
	Dxbar::TdxBarPainter* FDefaultBarPainter;
	Dxribbon::TdxCustomRibbon* FRibbon;
	void __fastcall CheckAssignRibbon(void);
	void __fastcall CheckRemoveToolbar(Dxbar::TdxBar* ABar);
	HIDESBASE void __fastcall SetColor(const System::Uitypes::TColor Value);
	void __fastcall SetRibbon(Dxribbon::TdxCustomRibbon* const Value);
	void __fastcall UpdateToolbarPainters(void);
	void __fastcall UpdateToolbars(void);
	
protected:
	bool FNeedSizeGripSeparator;
	System::StaticArray<bool, 2> FRisedSideStates;
	bool __fastcall FormDrawGetActive(Vcl::Forms::TCustomForm* AForm);
	int __fastcall FormDrawGetHeight(void);
	bool __fastcall FormDrawGetIsRaised(bool ALeft);
	virtual void __fastcall AdjustTextColor(System::Uitypes::TColor &AColor, bool Active);
	virtual void __fastcall Calculate(void);
	void __fastcall CalculateFormSidesAndSizeGrip(void);
	virtual void __fastcall ColorSchemeChanged(System::TObject* Sender, const void *AEventArgs);
	virtual Dxstatusbar::TdxStatusBarViewInfo* __fastcall CreateViewInfo(void);
	virtual int __fastcall GetMinHeight(void);
	virtual Dxstatusbar::TdxStatusBarPainterClass __fastcall GetPainterClass(void);
	virtual Dxstatusbar::TdxStatusBarPaintStyle __fastcall GetPaintStyle(void);
	bool __fastcall IsRibbonValid(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall PaintStyleChanged(void);
	virtual void __fastcall SetParent(Vcl::Controls::TWinControl* AParent);
	DYNAMIC void __fastcall VisibleChanged(void);
	virtual void __fastcall UpdatePanels(void);
	__property Dxbar::TdxBarPainter* DefaultBarPainter = {read=FDefaultBarPainter};
	
public:
	__fastcall virtual TdxRibbonStatusBar(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonStatusBar(void);
	virtual bool __fastcall CanAcceptPanelStyle(Dxstatusbar::TdxStatusBarPanelStyleClass Value);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	
__published:
	__property Images;
	__property Panels;
	__property Dxribbon::TdxCustomRibbon* Ribbon = {read=FRibbon, write=SetRibbon};
	__property SimplePanelStyle;
	__property SizeGrip = {default=1};
	__property LookAndFeel;
	__property OnHint;
	__property BorderWidth = {default=0};
	__property Anchors = {default=3};
	__property BiDiMode;
	__property System::Uitypes::TColor Color = {read=FColor, write=SetColor, default=536870912};
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property Font;
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
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonStatusBar(HWND ParentWindow) : Dxstatusbar::TdxCustomStatusBar(ParentWindow) { }
	
private:
	void *__IdxRibbonFormStatusBar;	/* Dxribbon::IdxRibbonFormStatusBar */
	void *__IdxRibbonFormNonClientPart;	/* Dxribbonformcaptionhelper::IdxRibbonFormNonClientPart */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {E6AA56DF-B87A-4D98-98CF-B41BA751594D}
	operator Dxribbon::_di_IdxRibbonFormStatusBar()
	{
		Dxribbon::_di_IdxRibbonFormStatusBar intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbon::IdxRibbonFormStatusBar*(void) { return (Dxribbon::IdxRibbonFormStatusBar*)&__IdxRibbonFormStatusBar; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {9266F6BD-0C9A-402A-A49F-D6405A2DDAF0}
	operator Dxribbonformcaptionhelper::_di_IdxRibbonFormNonClientPart()
	{
		Dxribbonformcaptionhelper::_di_IdxRibbonFormNonClientPart intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxribbonformcaptionhelper::IdxRibbonFormNonClientPart*(void) { return (Dxribbonformcaptionhelper::IdxRibbonFormNonClientPart*)&__IdxRibbonFormNonClientPart; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxribbonstatusbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONSTATUSBAR)
using namespace Dxribbonstatusbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonstatusbarHPP
