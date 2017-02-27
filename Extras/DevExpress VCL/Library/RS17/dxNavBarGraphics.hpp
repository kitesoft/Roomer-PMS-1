// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarGraphics.pas' rev: 24.00 (Win32)

#ifndef DxnavbargraphicsHPP
#define DxnavbargraphicsHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarCustomPainters.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbargraphics
{
//-- type declarations -------------------------------------------------------
enum TXPScheme : unsigned char { schUnknown, schNormalColor, schHomestead, schMetallic };

typedef TXPScheme TXPSchemeColor;

typedef unsigned *PARGB;

typedef unsigned *PdxGPColor;

typedef unsigned TdxGPColor;

typedef System::DynamicArray<unsigned> TdxGPColorDynArray;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Vcl::Graphics::TBitmap* dxAdvExplorerBarGroupCaptionCollapseSignBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxAdvExplorerBarGroupCaptionExpandSignBitmap;
extern PACKAGE unsigned dxAdvExplorerBarBackgroundColor1;
extern PACKAGE unsigned dxAdvExplorerBarBackgroundColor2;
extern PACKAGE unsigned dxAdvExplorerBarFontColor;
extern PACKAGE unsigned dxAdvExplorerBarFontHotColor;
extern PACKAGE unsigned dxAdvExplorerBarGroupBackgroundColor;
extern PACKAGE unsigned dxAdvExplorerBarGroupCaptionColor1;
extern PACKAGE unsigned dxAdvExplorerBarGroupCaptionColor2;
extern PACKAGE unsigned dxAdvExplorerBarGroupCaptionSignColor;
extern PACKAGE unsigned dxAdvExplorerBarGroupCaptionSignHotColor;
extern PACKAGE unsigned dxAdvExplorerBarGroupFontColor;
extern PACKAGE unsigned dxAdvExplorerBarGroupFontHotColor;
extern PACKAGE unsigned dxAdvExplorerBarSpecialGroupCaptionColor1;
extern PACKAGE unsigned dxAdvExplorerBarSpecialGroupCaptionColor2;
extern PACKAGE unsigned dxAdvExplorerBarSpecialGroupCaptionSignColor;
extern PACKAGE unsigned dxAdvExplorerBarSpecialGroupCaptionSignHotColor;
extern PACKAGE unsigned dxAdvExplorerBarSpecialGroupFontColor;
extern PACKAGE unsigned dxAdvExplorerBarSpecialGroupFontHotColor;
extern PACKAGE unsigned dxOffice11BackgroundColor1;
extern PACKAGE unsigned dxOffice11BackgroundColor2;
extern PACKAGE unsigned dxOffice11GroupBackgroundColor1;
extern PACKAGE unsigned dxOffice11GroupBackgroundColor2;
extern PACKAGE unsigned dxOffice11GroupCaptionColor1;
extern PACKAGE unsigned dxOffice11GroupCaptionColor2;
extern PACKAGE unsigned dxOffice11GroupBorderColor;
extern PACKAGE unsigned dxOffice11GroupFontColor;
extern PACKAGE unsigned dxOffice11LinkFontColor;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11CaptionExpandSignBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11CaptionCollapseSignBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11NavPaneOverflowPanelBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11NavPaneSplitterBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11NavPaneArrowUpBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11NavPaneArrowDownBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11NavPaneDefaultLargeBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11NavPaneDefaultSmallBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarSpecialGroupHeader;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarNormalGroupHeader;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarSpecialGroupCollapseHot;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarNormalGroupCollapseHot;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarSpecialGroupCollapse;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarNormalGroupCollapse;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarSpecialGroupExpandHot;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarNormalGroupExpandHot;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarSpecialGroupExpand;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarNormalGroupExpand;
extern PACKAGE Vcl::Graphics::TBitmap* dxXPExplorerBarBackground;
extern PACKAGE Vcl::Graphics::TFont* dxXPExplorerBarItemFont;
extern PACKAGE Vcl::Graphics::TFont* dxXPExplorerBarItemFontHot;
extern PACKAGE Vcl::Graphics::TFont* dxXPExplorerBarGroupHeaderFont;
extern PACKAGE Vcl::Graphics::TFont* dxXPExplorerBarGroupHeaderFontHot;
extern PACKAGE System::Uitypes::TColor dxXPExplorerBarBackgroundColor1;
extern PACKAGE System::Uitypes::TColor dxXPExplorerBarBackgroundColor2;
extern PACKAGE System::Uitypes::TColor dxXPExplorerBarGroupBackgroundColor1;
extern PACKAGE System::Uitypes::TColor dxXPExplorerBarGroupBackgroundColor2;
extern PACKAGE System::Uitypes::TColor dxXPExplorerBarGroupBorderColor;
extern PACKAGE void __fastcall CreateAdvExplorerBarColors(void);
extern PACKAGE void __fastcall RefreshAdvExplorerBarColors(void);
extern PACKAGE void __fastcall ReleaseAdvExplorerBarColors(void);
extern PACKAGE void __fastcall CreateOffice11Colors(void);
extern PACKAGE void __fastcall RefreshOffice11Colors(void);
extern PACKAGE void __fastcall ReleaseOffice11Colors(void);
extern PACKAGE void __fastcall CreateOffice11NavPaneColors(void);
extern PACKAGE void __fastcall RefreshOffice11NavPaneColors(void);
extern PACKAGE void __fastcall ReleaseOffice11NavPaneColors(void);
extern PACKAGE bool __fastcall CheckShellInstance(void);
extern PACKAGE void __fastcall CreateXPExplorerBarColors(void);
extern PACKAGE void __fastcall RefreshXPExplorerBarColors(void);
extern PACKAGE void __fastcall ReleaseXPExplorerBarColors(void);
extern PACKAGE TXPScheme __fastcall XPScheme(void);
extern PACKAGE System::Uitypes::TColor __fastcall LightColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall LightLightColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall DarkColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall DarkDarkColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall LightBorderColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall LightLightBorderColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall DarkBorderColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall DarkDarkBorderColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall CalcColor(int d);
extern PACKAGE System::Uitypes::TColor __fastcall CalcTextColor(System::Uitypes::TColor AColor, Dxnavbar::TdxNavBarObjectStates AState);
extern PACKAGE int __fastcall GetFontHeight(Vcl::Graphics::TFont* AFont);
extern PACKAGE void __fastcall GetSystemFont(Vcl::Graphics::TFont* AFont);
extern PACKAGE void __fastcall dxNavBarDrawSelectedFrame(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, System::Uitypes::TColor ATopLeftOuterColor, System::Uitypes::TColor ABottomRightOuterColor, System::Uitypes::TColor ATopLeftInnerColor, System::Uitypes::TColor ABottomRightInnerColor);
extern PACKAGE void __fastcall RGBQuadToColorRef(tagRGBQUAD AColor, /* out */ unsigned &ARevertedColor);
extern PACKAGE void __fastcall ColorRefToRGBQuad(unsigned AColor, /* out */ tagRGBQUAD &ARevertedColor);
extern PACKAGE bool __fastcall IsGdiPlusAvailable(void);
extern PACKAGE unsigned __fastcall MakeColor(System::Byte r, System::Byte g, System::Byte b)/* overload */;
extern PACKAGE unsigned __fastcall MakeColor(System::Byte a, System::Byte r, System::Byte g, System::Byte b)/* overload */;
extern PACKAGE unsigned __fastcall MakeColor(System::Uitypes::TColor color, System::Byte alpha)/* overload */;
extern PACKAGE System::Byte __fastcall GetAlpha(unsigned color);
extern PACKAGE System::Byte __fastcall GetRed(unsigned color);
extern PACKAGE System::Byte __fastcall GetGreen(unsigned color);
extern PACKAGE System::Byte __fastcall GetBlue(unsigned color);
extern PACKAGE unsigned __fastcall ColorRefToARGB(unsigned rgb);
extern PACKAGE unsigned __fastcall ARGBToColorRef(unsigned Color);
extern PACKAGE void __fastcall GdipFillGradientRect(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, System::Byte AAlphaBlend1, System::Byte AAlphaBlend2, Dxnavbarstyles::TdxBarStyleGradientMode AGradientMode);
}	/* namespace Dxnavbargraphics */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARGRAPHICS)
using namespace Dxnavbargraphics;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbargraphicsHPP
