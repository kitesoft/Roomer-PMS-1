// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxRibbonMiniToolbar.pas' rev: 24.00 (Win64)

#ifndef DxribbonminitoolbarHPP
#define DxribbonminitoolbarHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarSkinConsts.hpp>	// Pascal unit
#include <dxRibbon.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxribbonminitoolbar
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxRibbonCustomMiniToolbar;
class DELPHICLASS TdxRibbonMiniToolbarPainter;
class DELPHICLASS TdxRibbonMiniToolbarControl;
class PASCALIMPLEMENTATION TdxRibbonCustomMiniToolbar : public Dxribbon::TdxRibbonCustomPopupComponent
{
	typedef Dxribbon::TdxRibbonCustomPopupComponent inherited;
	
private:
	Dxbar::TdxBar* FBar;
	TdxRibbonMiniToolbarPainter* FPainter;
	System::Classes::TNotifyEvent FOnCloseUp;
	TdxRibbonMiniToolbarControl* __fastcall GetMiniToolbarControl(void);
	void __fastcall MiniToolbarDestroy(System::TObject* Sender);
	void __fastcall MiniToolbarCloseUp(System::TObject* Sender);
	
protected:
	virtual Dxbar::TCustomdxBarControl* __fastcall CreateBarControl(void);
	virtual Dxbar::TCustomdxBarControlClass __fastcall GetControlClass(void);
	virtual Dxbar::TdxBarItemLinksClass __fastcall GetItemLinksClass(void);
	__property System::Classes::TNotifyEvent OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	
public:
	void __fastcall Popup(Dxbar::TdxBarCustomPopupMenu* AContextMenu = (Dxbar::TdxBarCustomPopupMenu*)(0x0))/* overload */;
	void __fastcall Popup(System::Types::TPoint P, Dxbar::TdxBarCustomPopupMenu* AContextMenu = (Dxbar::TdxBarCustomPopupMenu*)(0x0))/* overload */;
public:
	/* TdxRibbonCustomPopupComponent.Create */ inline __fastcall virtual TdxRibbonCustomMiniToolbar(System::Classes::TComponent* AOwner) : Dxribbon::TdxRibbonCustomPopupComponent(AOwner) { }
	/* TdxRibbonCustomPopupComponent.Destroy */ inline __fastcall virtual ~TdxRibbonCustomMiniToolbar(void) { }
	
};


class DELPHICLASS TdxRibbonMiniToolbar;
class PASCALIMPLEMENTATION TdxRibbonMiniToolbar : public TdxRibbonCustomMiniToolbar
{
	typedef TdxRibbonCustomMiniToolbar inherited;
	
__published:
	__property Images;
	__property ItemLinks;
	__property Ribbon;
public:
	/* TdxRibbonCustomPopupComponent.Create */ inline __fastcall virtual TdxRibbonMiniToolbar(System::Classes::TComponent* AOwner) : TdxRibbonCustomMiniToolbar(AOwner) { }
	/* TdxRibbonCustomPopupComponent.Destroy */ inline __fastcall virtual ~TdxRibbonMiniToolbar(void) { }
	
};


class PASCALIMPLEMENTATION TdxRibbonMiniToolbarControl : public Dxbar::TdxBarPopupControl
{
	typedef Dxbar::TdxBarPopupControl inherited;
	
private:
	bool FWasMouseOver;
	Dxbar::TdxBarCustomPopupMenu* FContextMenu;
	HIDESBASE int __fastcall GetAlphaBlendValue(void);
	Dxbar::TdxBarSubMenuControl* __fastcall GetContextPopup(void);
	void __fastcall DropContextMenu(void);
	void __fastcall OnContextMenuClose(System::TObject* Sender, Dxbar::TdxBarCloseUpReason AReason);
	
protected:
	virtual bool __fastcall AllowFade(void);
	virtual bool __fastcall AllowSeparators(void);
	virtual bool __fastcall CanProcessMouseMessage(void);
	virtual bool __fastcall CanShowPopupMenuOnMouseClick(bool AMousePressed);
	virtual void __fastcall DoHideAll(Dxbar::TdxBarCloseUpReason AReason);
	virtual void __fastcall DrawContentBackground(void);
	virtual void __fastcall FillBackground(HDC ADC, const System::Types::TRect &ARect, HBRUSH ABrush, System::Uitypes::TColor AColor, bool AIsClientArea);
	virtual Dxbar::TdxBarItemViewLevel __fastcall GetItemControlDefaultViewLevel(Dxbar::TdxBarItemControl* AItemControl);
	virtual Dxbar::TdxBarPaintType __fastcall GetPaintType(void);
	virtual bool __fastcall IsChildWindow(HWND AWnd);
	virtual bool __fastcall NeedHideOnKeyPress(void);
	virtual void __fastcall SetLayeredAttributes(void);
	virtual void __fastcall DoNCPaint(HDC DC);
	virtual System::Types::TPoint __fastcall GetPopupPosition(const System::Types::TSize ASize, const System::Types::TRect &AOwnerRect, Dxbar::TXDirection APopupDirection);
	virtual System::Types::TSize __fastcall GetPopupSize(void);
	virtual bool __fastcall AlwaisTrackMouse(void);
	virtual void __fastcall TrackMouse(void);
	
public:
	__fastcall virtual TdxRibbonMiniToolbarControl(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxRibbonMiniToolbarControl(void);
	virtual void __fastcall CloseUp(void);
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxRibbonMiniToolbarControl(HWND ParentWindow) : Dxbar::TdxBarPopupControl(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TdxRibbonMiniToolbarPainter : public Dxribbon::TdxRibbonBarPainter
{
	typedef Dxribbon::TdxRibbonBarPainter inherited;
	
protected:
	virtual void __fastcall DrawToolbarContentPart(Dxbar::TdxBarControl* ABarControl, Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall DrawToolbarNonContentPart(Dxbar::TdxBarControl* ABarControl, HDC DC);
	
public:
	virtual System::Types::TRect __fastcall GetToolbarContentOffsets(Dxbar::TdxBar* ABar, Dxbar::TdxBarDockingStyle ADockingStyle, bool AHasSizeGrip);
public:
	/* TdxRibbonBarPainter.Create */ inline __fastcall virtual TdxRibbonMiniToolbarPainter(NativeUInt AData) : Dxribbon::TdxRibbonBarPainter(AData) { }
	/* TdxRibbonBarPainter.Destroy */ inline __fastcall virtual ~TdxRibbonMiniToolbarPainter(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxribbonminitoolbar */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXRIBBONMINITOOLBAR)
using namespace Dxribbonminitoolbar;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxribbonminitoolbarHPP
