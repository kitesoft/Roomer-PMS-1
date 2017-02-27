// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxWizardControlViewStyleAero.pas' rev: 24.00 (Win32)

#ifndef DxwizardcontrolviewstyleaeroHPP
#define DxwizardcontrolviewstyleaeroHPP

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
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCustomWizardControl.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDrawTextUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxwizardcontrolviewstyleaero
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxWizardControlViewStyleAeroPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleAeroPainter : public Dxcustomwizardcontrol::TdxWizardControlCustomPainter
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomPainter inherited;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetHeaderDescriptionTextColor(void);
	virtual System::Uitypes::TColor __fastcall GetHeaderTitleTextColor(void);
	virtual int __fastcall GetSeparatorSize(void);
	virtual System::Uitypes::TColor __fastcall GetTitleTextColor(void);
	virtual void __fastcall InitializeFonts(void);
	
public:
	virtual void __fastcall DrawBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawCommandAreaBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds);
	virtual void __fastcall DrawSeparator(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual void __fastcall DrawTitleBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R);
	virtual System::Types::TSize __fastcall GetBackButtonSize(void);
	virtual void __fastcall DrawBackButton(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
public:
	/* TdxWizardControlCustomPainter.Create */ inline __fastcall virtual TdxWizardControlViewStyleAeroPainter(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlCustomPainter(AWizardControl) { }
	/* TdxWizardControlCustomPainter.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleAeroPainter(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleAeroBackButtonViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleAeroBackButtonViewInfo : public Dxcustomwizardcontrol::TdxWizardControlBackButtonViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlBackButtonViewInfo inherited;
	
private:
	HIDESBASE TdxWizardControlViewStyleAeroPainter* __fastcall GetPainter(void);
	
protected:
	virtual bool __fastcall CanDrawContent(void);
	virtual void __fastcall DrawButtonBackground(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &R, Cxlookandfeelpainters::TcxButtonState AState);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	
public:
	virtual int __fastcall MeasureHeight(void);
	virtual int __fastcall MeasureWidth(void);
	__property TdxWizardControlViewStyleAeroPainter* Painter = {read=GetPainter};
public:
	/* TdxWizardControlButtonViewInfo.Create */ inline __fastcall virtual TdxWizardControlViewStyleAeroBackButtonViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AControl, Dxcustomwizardcontrol::TdxWizardControlCustomButton* AButton) : Dxcustomwizardcontrol::TdxWizardControlBackButtonViewInfo(AControl, AButton) { }
	/* TdxWizardControlButtonViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleAeroBackButtonViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleAeroTitleTextOnGlassCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleAeroTitleTextOnGlassCache : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxgraphics::TcxBitmap32* FCache;
	int FFontHeight;
	System::Uitypes::TFontName FFontName;
	System::Uitypes::TFontStyles FFontStyle;
	System::UnicodeString FText;
	
protected:
	__property Cxgraphics::TcxBitmap32* Cache = {read=FCache};
	
public:
	__fastcall virtual ~TdxWizardControlViewStyleAeroTitleTextOnGlassCache(void);
	void __fastcall Draw(HDC DC, Vcl::Graphics::TFont* AFont, const System::Types::TRect &ATextRect, const System::UnicodeString AText);
	void __fastcall Flush(void);
public:
	/* TObject.Create */ inline __fastcall TdxWizardControlViewStyleAeroTitleTextOnGlassCache(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleAeroTitleViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleAeroTitleViewInfo : public Dxcustomwizardcontrol::TdxWizardControlCustomTitleViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomTitleViewInfo inherited;
	
private:
	TdxWizardControlViewStyleAeroTitleTextOnGlassCache* FCache;
	TdxWizardControlViewStyleAeroBackButtonViewInfo* FBackButtonViewInfo;
	System::Types::TSize __fastcall GetGlyphAreaSize(void);
	
protected:
	System::Types::TRect FGlyphRect;
	System::Types::TRect FTextRect;
	virtual void __fastcall CalculateBackButton(System::Types::TRect &R);
	virtual void __fastcall CalculateGlyph(System::Types::TRect &R);
	virtual void __fastcall CalculateTextRect(System::Types::TRect &R);
	virtual bool __fastcall CanDrawContent(void);
	virtual void __fastcall DrawContent(Cxgraphics::TcxCanvas* ACanvas);
	__property TdxWizardControlViewStyleAeroTitleTextOnGlassCache* Cache = {read=FCache};
	
public:
	__fastcall virtual TdxWizardControlViewStyleAeroTitleViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl);
	__fastcall virtual ~TdxWizardControlViewStyleAeroTitleViewInfo(void);
	virtual void __fastcall Calculate(void);
	virtual int __fastcall MeasureHeight(void);
	__property TdxWizardControlViewStyleAeroBackButtonViewInfo* BackButtonViewInfo = {read=FBackButtonViewInfo};
	__property System::Types::TSize GlyphAreaSize = {read=GetGlyphAreaSize};
	__property System::Types::TRect GlyphRect = {read=FGlyphRect};
	__property System::Types::TRect TextRect = {read=FTextRect};
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleAeroHeaderViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleAeroHeaderViewInfo : public Dxcustomwizardcontrol::TdxWizardControlCustomHeaderViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomHeaderViewInfo inherited;
	
protected:
	virtual System::Types::TRect __fastcall GetContentMargins(void);
	virtual bool __fastcall GetDescriptionIsVisible(void);
	virtual bool __fastcall GetGlyphIsVisible(void);
	virtual int __fastcall GetIndentBetweenElemenets(void);
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlViewStyleAeroHeaderViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlCustomHeaderViewInfo(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleAeroHeaderViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleAeroCommandAreaViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleAeroCommandAreaViewInfo : public Dxcustomwizardcontrol::TdxWizardControlCustomCommandAreaViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlCustomCommandAreaViewInfo inherited;
	
protected:
	virtual void __fastcall CalculateButtons(System::Types::TRect &ABounds);
	virtual System::Types::TRect __fastcall GetContentMargins(void);
	virtual int __fastcall GetIndentBetweenElementsInGroup(void);
	virtual int __fastcall GetIndentBetweenGroups(void);
public:
	/* TdxWizardControlCustomCommandAreaViewInfo.Create */ inline __fastcall virtual TdxWizardControlViewStyleAeroCommandAreaViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlCustomCommandAreaViewInfo(AWizardControl) { }
	
public:
	/* TdxWizardControlContainerCellViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleAeroCommandAreaViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleAeroWatermarkViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleAeroWatermarkViewInfo : public Dxcustomwizardcontrol::TdxWizardControlWatermarkViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlWatermarkViewInfo inherited;
	
protected:
	virtual bool __fastcall GetIsImageVisible(void);
public:
	/* TdxWizardControlCustomObject.Create */ inline __fastcall virtual TdxWizardControlViewStyleAeroWatermarkViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlWatermarkViewInfo(AWizardControl) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleAeroWatermarkViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxWizardControlViewStyleAeroViewInfo;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxWizardControlViewStyleAeroViewInfo : public Dxcustomwizardcontrol::TdxWizardControlViewInfo
{
	typedef Dxcustomwizardcontrol::TdxWizardControlViewInfo inherited;
	
private:
	TdxWizardControlViewStyleAeroTitleViewInfo* __fastcall GetTitleViewInfo(void);
	
protected:
	virtual Dxcustomwizardcontrol::TdxWizardControlCustomCommandAreaViewInfo* __fastcall CreateCommandAreaViewInfo(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlCustomHeaderViewInfo* __fastcall CreateHeaderViewInfo(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlCustomPainter* __fastcall CreatePainter(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlCustomTitleViewInfo* __fastcall CreateTitleViewInfo(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlWatermarkViewInfo* __fastcall CreateWatermarkViewInfo(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlResizeAnimation __fastcall GetDefaultResizeAnimation(void);
	virtual Dxcustomwizardcontrol::TdxWizardControlTransitionEffect __fastcall GetDefaultTransitionEffect(void);
	virtual System::Types::TRect __fastcall GetTransitionEffectAreaBounds(void);
	
public:
	virtual void __fastcall Calculate(void);
	virtual void __fastcall GetTabOrderList(Dxcustomwizardcontrol::TdxWizardControlCellViewInfoList* AList);
	__property TdxWizardControlViewStyleAeroTitleViewInfo* TitleViewInfo = {read=GetTitleViewInfo};
public:
	/* TdxWizardControlViewInfo.Create */ inline __fastcall virtual TdxWizardControlViewStyleAeroViewInfo(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl) : Dxcustomwizardcontrol::TdxWizardControlViewInfo(AWizardControl) { }
	/* TdxWizardControlViewInfo.Destroy */ inline __fastcall virtual ~TdxWizardControlViewStyleAeroViewInfo(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxwizardcontrolviewstyleaero */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXWIZARDCONTROLVIEWSTYLEAERO)
using namespace Dxwizardcontrolviewstyleaero;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxwizardcontrolviewstyleaeroHPP
