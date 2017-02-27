// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxWizardControl.pas' rev: 24.00 (Win32)

#ifndef DxwizardcontrolHPP
#define DxwizardcontrolHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCustomWizardControl.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxwizardcontrol
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxWizardControlPage;
class PASCALIMPLEMENTATION TdxWizardControlPage : public Dxcustomwizardcontrol::TdxWizardControlCustomPage
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomPage inherited;
	
__published:
	__property DoubleBuffered;
	__property Font;
	__property Header;
	__property OptionsSize;
	__property PageIndex;
	__property PageVisible = {default=1};
	__property ParentDoubleBuffered = {default=1};
	__property ParentFont = {default=1};
	__property Watermark;
	__property OnClick;
	__property OnDblClick;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnResize;
public:
	/* TdxWizardControlCustomPage.Create */ inline __fastcall virtual TdxWizardControlPage(System::Classes::TComponent* AComponent) : Dxcustomwizardcontrol::TdxWizardControlCustomPage(AComponent) { }
	/* TdxWizardControlCustomPage.Destroy */ inline __fastcall virtual ~TdxWizardControlPage(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxWizardControlPage(HWND ParentWindow) : Dxcustomwizardcontrol::TdxWizardControlCustomPage(ParentWindow) { }
	
};


class DELPHICLASS TdxWizardControl;
class PASCALIMPLEMENTATION TdxWizardControl : public Dxcustomwizardcontrol::TdxCustomWizardControl
{
	typedef Dxcustomwizardcontrol::TdxCustomWizardControl inherited;
	
public:
	HIDESBASE TdxWizardControlPage* __fastcall AddPage(void)/* overload */;
	
__published:
	__property ActivePage = {stored=false};
	__property Align = {default=5};
	__property AutoSize = {default=0};
	__property Buttons;
	__property Font;
	__property Header;
	__property InfoPanel;
	__property LookAndFeel;
	__property OptionsAnimate;
	__property OptionsViewStyleAero;
	__property ParentFont = {default=1};
	__property ViewStyle = {default=0};
	__property Watermark;
	__property OnButtonClick;
	__property OnClick;
	__property OnDblClick;
	__property OnInfoPanelClick;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnMouseWheel;
	__property OnMouseWheelDown;
	__property OnMouseWheelUp;
	__property OnPageChanged;
	__property OnPageChanging;
	__property OnResize;
public:
	/* TdxCustomWizardControl.Create */ inline __fastcall virtual TdxWizardControl(System::Classes::TComponent* AComponent) : Dxcustomwizardcontrol::TdxCustomWizardControl(AComponent) { }
	/* TdxCustomWizardControl.Destroy */ inline __fastcall virtual ~TdxWizardControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxWizardControl(HWND ParentWindow) : Dxcustomwizardcontrol::TdxCustomWizardControl(ParentWindow) { }
	
/* Hoisted overloads: */
	
public:
	inline Dxcustomwizardcontrol::TdxWizardControlCustomPage* __fastcall  AddPage(Dxcustomwizardcontrol::TdxWizardControlCustomPageClass APageClass){ return Dxcustomwizardcontrol::TdxCustomWizardControl::AddPage(APageClass); }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxwizardcontrol */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXWIZARDCONTROL)
using namespace Dxwizardcontrol;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxwizardcontrolHPP
