// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxShadowWindow.pas' rev: 24.00 (Win64)

#ifndef DxshadowwindowHPP
#define DxshadowwindowHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxshadowwindow
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxCustomShadowWindow;
class PASCALIMPLEMENTATION TdxCustomShadowWindow : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	Vcl::Controls::TWinControl* FOwnerWindow;
	Dxskinscore::TdxSkinImage* FShadowMask;
	bool FTransparent;
	System::Uitypes::TColor FShadowColor;
	bool __fastcall GetVisible(void);
	void __fastcall SetShadowColor(System::Uitypes::TColor AValue);
	void __fastcall SetTransparent(bool AValue);
	HIDESBASE void __fastcall SetVisible(bool AValue);
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall DrawShadowImage(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall Resize(void);
	void __fastcall UpdateLayer(void);
	HIDESBASE MESSAGE void __fastcall WMEraseBkgnd(Winapi::Messages::TWMEraseBkgnd &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	HIDESBASE MESSAGE void __fastcall WMPaint(Winapi::Messages::TWMPaint &Message);
	
public:
	__fastcall virtual TdxCustomShadowWindow(Vcl::Controls::TWinControl* AOwnerWindow);
	__fastcall virtual ~TdxCustomShadowWindow(void);
	HIDESBASE virtual void __fastcall Hide(void);
	HIDESBASE void __fastcall Refresh(void);
	HIDESBASE virtual void __fastcall Show(void);
	__property Vcl::Controls::TWinControl* OwnerWindow = {read=FOwnerWindow};
	__property System::Uitypes::TColor ShadowColor = {read=FShadowColor, write=SetShadowColor, nodefault};
	__property bool Transparent = {read=FTransparent, write=SetTransparent, nodefault};
	__property bool Visible = {read=GetVisible, write=SetVisible, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomShadowWindow(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TdxShadowWindow;
class PASCALIMPLEMENTATION TdxShadowWindow : public TdxCustomShadowWindow
{
	typedef TdxCustomShadowWindow inherited;
	
private:
	bool FActivating;
	bool FAllowResizeOwnerWindowViaShadow;
	bool FOwnerWindowIsActive;
	Cxcontrols::TcxWindowProcLinkedObject* FOwnerWindowWndProcObject;
	System::Types::TRect FShadowOffsets;
	void __fastcall SetAllowResizeOwnerWindowViaShadow(const bool AValue);
	void __fastcall SetShadowOffsets(const System::Types::TRect &AValue);
	
protected:
	virtual bool __fastcall CalculateVisibility(void);
	virtual void __fastcall DrawShadowImage(Cxgraphics::TcxCanvas* ACanvas);
	virtual void __fastcall OwnerWindowWndProc(Winapi::Messages::TMessage &AMessage);
	MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMMouseActivate(Winapi::Messages::TWMMouseActivate &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TWMNCHitTest &Message);
	MESSAGE void __fastcall WMSizing(Winapi::Messages::TMessage &Message);
	__property bool OwnerWindowIsActive = {read=FOwnerWindowIsActive, nodefault};
	__property Cxcontrols::TcxWindowProcLinkedObject* OwnerWindowWndProcObject = {read=FOwnerWindowWndProcObject};
	
public:
	__fastcall virtual TdxShadowWindow(Vcl::Controls::TWinControl* AOwnerWindow);
	__fastcall virtual ~TdxShadowWindow(void);
	virtual void __fastcall Show(void);
	HIDESBASE void __fastcall UpdateBounds(void);
	void __fastcall UpdateVisibility(void);
	__property bool AllowResizeOwnerWindowViaShadow = {read=FAllowResizeOwnerWindowViaShadow, write=SetAllowResizeOwnerWindowViaShadow, nodefault};
	__property System::Types::TRect ShadowOffsets = {read=FShadowOffsets, write=SetShadowOffsets};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxShadowWindow(HWND ParentWindow) : TdxCustomShadowWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxCanUseShadows(void);
extern PACKAGE bool __fastcall dxCanUseTransparentShadows(void);
extern PACKAGE void __fastcall UpdateWindowLayer(NativeUInt AHandle, Vcl::Graphics::TBitmap* ABitmap, int AAlpha = 0xff);
}	/* namespace Dxshadowwindow */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSHADOWWINDOW)
using namespace Dxshadowwindow;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxshadowwindowHPP
