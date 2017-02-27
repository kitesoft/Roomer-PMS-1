// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxWizardControlViewStyleWizard97.pas' rev: 24.00 (Win32)

#ifndef Dxwizardcontrolviewstylewizard97HPP
#define Dxwizardcontrolviewstylewizard97HPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCustomWizardControl.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxwizardcontrolviewstylewizard97
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxWizardControlViewStyleWizard97Painter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleWizard97Painter : public Dxcustomwizardcontrol::TdxWizardControlCustomPainter
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomPainter inherited;
	
protected:
	virtual void __fastcall InitializeFonts(void);
	
public:
	virtual void __fastcall DrawHeaderBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
public:
	/* TdxWizardControlCustomPainter.Create */ inline __fastcall virtual TdxWizardControlViewStyleWizard97Painter(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlCustomPainter(AWizardControl) { }
	/* TdxWizardControlCustomPainter.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleWizard97Painter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleWizard97HeaderViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleWizard97HeaderViewInfo : public Dxcustomwizardcontrol::TdxWizardControlCustomHeaderViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomHeaderViewInfo inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetContentMargins(void);
	virtual bool __fastcall GetDescriptionIsVisible(void);
	virtual bool __fastcall GetGlyphIsVisible(void);
	virtual int __fastcall GetIndentBetweenElemenets(void);
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlViewStyleWizard97HeaderViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlCustomHeaderViewInfo(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleWizard97HeaderViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleWizard97CommandAreaViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleWizard97CommandAreaViewInfo : public Dxcustomwizardcontrol::TdxWizardControlCustomCommandAreaViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomCommandAreaViewInfo inherited;
	
private:
	Dxcustomwizardcontrol::TdxWizardControlButtonViewInfo* FBackButtonViewInfo;
	
protected:
	virtual void __fastcall CalculateButtons(System::Types::TRect &ABounds);
	virtual void __fastcall CalculateButtonsMaxMeasureHeight(void);
	virtual System::Types::TRect __fastcall GetContentMargins(void);
	virtual int __fastcall GetIndentBetweenElementsInGroup(void);
	virtual int __fastcall GetIndentBetweenGroups(void);
	__property Dxcustomwizardcontrol::TdxWizardControlButtonViewInfo* BackButtonViewInfo = {read=FBackButtonViewInfo};
	
public:
	__fastcall virtual TdxWizardControlViewStyleWizard97CommandAreaViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl);
	virtual int __fastcall MeasureWidth(void);
public:
	/* TdxWizardControlContainerCellViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleWizard97CommandAreaViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleWizard97WatermarkViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleWizard97WatermarkViewInfo : public Dxcustomwizardcontrol::TdxWizardControlWatermarkViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlWatermarkViewInfo inherited;
	
protected:
	virtual bool __fastcall GetIsImageVisible(void);
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlViewStyleWizard97WatermarkViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlWatermarkViewInfo(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleWizard97WatermarkViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleWizard97ViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleWizard97ViewInfo : public Dxcustomwizardcontrol::TdxWizardControlViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlViewInfo inherited;
	
protected:
	virtual Dxcustomwizardcontrol::TdxWizardControlCustomCommandAreaViewInfo* __fastcall CreateCommandAreaViewInfo(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlCustomHeaderViewInfo* __fastcall CreateHeaderViewInfo(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlCustomPainter* __fastcall CreatePainter(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlWatermarkViewInfo* __fastcall CreateWatermarkViewInfo(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlResizeAnimation __fastcall GetDefaultResizeAnimation(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlTransitionEffect __fastcall GetDefaultTransitionEffect(void);
	
public:
	virtual void __fastcall Calculate(void);
	virtual void __fastcall GetTabOrderList(Dxcustomwizardcontrol::TdxWizardControlCellViewInfoList* AList);
public:
	/* TdxWizardControlViewInfo.Create */ inline __fastcall virtual TdxWizardControlViewStyleWizard97ViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlViewInfo(AWizardControl) { }
	/* TdxWizardControlViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleWizard97ViewInfo(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxwizardcontrolviewstylewizard97 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXWIZARDCONTROLVIEWSTYLEWIZARD97)
using namespace Dxwizardcontrolviewstylewizard97;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxwizardcontrolviewstylewizard97HPP
