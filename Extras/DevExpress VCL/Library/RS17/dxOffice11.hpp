// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxOffice11.pas' rev: 24.00 (Win32)

#ifndef Dxoffice11HPP
#define Dxoffice11HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxoffice11
{
//-- type declarations -------------------------------------------------------
enum TOffice11Scheme : unsigned char { schUnknown, schNormalColor, schHomestead, schMetallic };

typedef TOffice11Scheme TOffice11SchemeColor;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE unsigned dxOffice11DockColor1;
extern PACKAGE unsigned dxOffice11DockColor2;
extern PACKAGE unsigned dxOffice11ToolbarsColor1;
extern PACKAGE unsigned dxOffice11ToolbarsColor2;
extern PACKAGE System::StaticArray<unsigned, 3> dxOffice11BarMarkColors1;
extern PACKAGE System::StaticArray<unsigned, 3> dxOffice11BarMarkColors2;
extern PACKAGE System::StaticArray<unsigned, 2> dxOffice11BarBorderColors;
extern PACKAGE System::StaticArray<System::StaticArray<unsigned, 3>, 2> dxOffice11BarBorderMarkColors;
extern PACKAGE unsigned dxOffice11BarFingerColor1;
extern PACKAGE unsigned dxOffice11BarFingerColor2;
extern PACKAGE unsigned dxOffice11BarSeparatorColor1;
extern PACKAGE unsigned dxOffice11BarSeparatorColor2;
extern PACKAGE unsigned dxOffice11BarMarkArrowColor1;
extern PACKAGE unsigned dxOffice11BarMarkArrowColor2;
extern PACKAGE unsigned dxOffice11BarFloatingBorderColor1;
extern PACKAGE unsigned dxOffice11BarFloatingBorderColor2;
extern PACKAGE unsigned dxOffice11BarFloatingBorderColor3;
extern PACKAGE unsigned dxOffice11BarFloatingCaptionColor;
extern PACKAGE unsigned dxOffice11BarFloatingCaptionTextColor1;
extern PACKAGE unsigned dxOffice11BarFloatingCaptionTextColor2;
extern PACKAGE unsigned dxOffice11BarFloatingCaptionTextColor3;
extern PACKAGE unsigned dxOffice11MenuColor;
extern PACKAGE unsigned dxOffice11MenuDownedColor1;
extern PACKAGE unsigned dxOffice11MenuDownedColor2;
extern PACKAGE unsigned dxOffice11MenuIndentColor1;
extern PACKAGE unsigned dxOffice11MenuIndentColor2;
extern PACKAGE unsigned dxOffice11MenuNonRecentIndentColor1;
extern PACKAGE unsigned dxOffice11MenuNonRecentIndentColor2;
extern PACKAGE unsigned dxOffice11DropDownBorderColor1;
extern PACKAGE unsigned dxOffice11DropDownBorderColor2;
extern PACKAGE unsigned dxOffice11ToolbarSelectedColor;
extern PACKAGE unsigned dxOffice11SelectedBorderColor;
extern PACKAGE unsigned dxOffice11SelectedColor1;
extern PACKAGE unsigned dxOffice11SelectedColor2;
extern PACKAGE unsigned dxOffice11SelectedDownColor1;
extern PACKAGE unsigned dxOffice11SelectedDownColor2;
extern PACKAGE unsigned dxOffice11OwnerControlDownedColor;
extern PACKAGE unsigned dxOffice11DownedColor;
extern PACKAGE unsigned dxOffice11DownedSelectedColor;
extern PACKAGE unsigned dxOffice11DetachableColor;
extern PACKAGE unsigned dxOffice11DetachableSelectedColor;
extern PACKAGE unsigned dxOffice11TextEnabledColor;
extern PACKAGE unsigned dxOffice11TextDisabledColor;
extern PACKAGE unsigned dxOffice11StaticBorderColor;
extern PACKAGE unsigned dxOffice11DateHeaderColor;
extern PACKAGE unsigned dxOffice11InPlaceSubItemColor;
extern PACKAGE unsigned dxOffice11InPlaceSubItemTextColor;
extern PACKAGE unsigned dxOffice11ControlBorderColor;
extern PACKAGE unsigned dxOffice11GroupColor;
extern PACKAGE unsigned dxOffice11DayNavigatorSelectedColor;
extern PACKAGE unsigned dxOffice11OutlookBorderColor;
extern PACKAGE unsigned dxOffice11OutlookControlColor;
extern PACKAGE unsigned dxOffice11GroupIndentColor;
extern PACKAGE unsigned dxOffice11GroupRowTextColor;
extern PACKAGE unsigned dxOffice11GroupRowSeparatorColor;
extern PACKAGE unsigned dxOffice11NavPaneBorder;
extern PACKAGE unsigned dxOffice11NavPaneGroupCaptionColor1;
extern PACKAGE unsigned dxOffice11NavPaneGroupCaptionColor2;
extern PACKAGE unsigned dxOffice11NavPaneGroupCaptionHotColor1;
extern PACKAGE unsigned dxOffice11NavPaneGroupCaptionHotColor2;
extern PACKAGE unsigned dxOffice11NavPaneGroupCaptionPressedColor1;
extern PACKAGE unsigned dxOffice11NavPaneGroupCaptionPressedColor2;
extern PACKAGE unsigned dxOffice11NavPaneGroupCaptionPressedHotColor1;
extern PACKAGE unsigned dxOffice11NavPaneGroupCaptionPressedHotColor2;
extern PACKAGE unsigned dxOffice11NavPaneHeaderColor1;
extern PACKAGE unsigned dxOffice11NavPaneHeaderColor2;
extern PACKAGE unsigned dxOffice11NavPaneHeaderFontColor;
extern PACKAGE unsigned dxOffice11NavPaneSplitterColor1;
extern PACKAGE unsigned dxOffice11NavPaneSplitterColor2;
extern PACKAGE unsigned dxOffice11ExpandButtonColor1;
extern PACKAGE unsigned dxOffice11ExpandButtonColor2;
extern PACKAGE HBRUSH dxOffice11BarFingerBrush1;
extern PACKAGE HBRUSH dxOffice11BarFingerBrush2;
extern PACKAGE HBRUSH dxOffice11BarSeparatorBrush1;
extern PACKAGE HBRUSH dxOffice11BarSeparatorBrush2;
extern PACKAGE HBRUSH dxOffice11MenuBrush;
extern PACKAGE HBRUSH dxOffice11SelectedBorderBrush;
extern PACKAGE HBRUSH dxOffice11ToolbarSelectedBrush;
extern PACKAGE HBRUSH dxOffice11OwnerControlDownedBrush;
extern PACKAGE HBRUSH dxOffice11DownedBrush;
extern PACKAGE HBRUSH dxOffice11DownedSelectedBrush;
extern PACKAGE HBRUSH dxOffice11DropDownBorderBrush1;
extern PACKAGE HBRUSH dxOffice11DropDownBorderBrush2;
extern PACKAGE HBRUSH dxOffice11DetachableBrush;
extern PACKAGE HBRUSH dxOffice11DetachableSelectedBrush;
extern PACKAGE HBRUSH dxOffice11StaticBorderBrush;
extern PACKAGE HBRUSH dxOffice11InPlaceSubItemBrush;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11SubMenuExpandBitmap;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11ExpandButtonBitmap1;
extern PACKAGE Vcl::Graphics::TBitmap* dxOffice11ExpandButtonBitmap2;
extern PACKAGE TOffice11Scheme __fastcall GetOffice11Scheme(void);
extern PACKAGE System::Uitypes::TColor __fastcall Dark(System::Uitypes::TColor Col, System::Byte Percentage);
extern PACKAGE unsigned __fastcall GetLightColor(int ABtnFaceColorPart, int AHighlightColorPart, int AWindowColorPart);
extern PACKAGE unsigned __fastcall GetMiddleRGB(System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, int APercent);
extern PACKAGE unsigned __fastcall GetRealColor(unsigned AColor);
extern PACKAGE System::Uitypes::TColor __fastcall Light(System::Uitypes::TColor Col, System::Byte Percentage);
extern PACKAGE void __fastcall Office11FrameSelectedRect(HDC DC, const System::Types::TRect &R);
extern PACKAGE void __fastcall Office11DrawFingerElements(HDC DC, const System::Types::TRect &ARect, bool AHorizontal, HBRUSH ABrush1 = (HBRUSH)(0x0), HBRUSH ABrush2 = (HBRUSH)(0x0));
extern PACKAGE void __fastcall FillTubeGradientRect(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AHorizontal);
extern PACKAGE void __fastcall CreateOffice11Colors(void);
extern PACKAGE void __fastcall Office11DrawSizeGrip(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1 = (System::Uitypes::TColor)(0x20000000), System::Uitypes::TColor AColor2 = (System::Uitypes::TColor)(0x20000000));
extern PACKAGE void __fastcall RefreshOffice11Colors(void);
extern PACKAGE void __fastcall ReleaseOffice11Colors(void);
extern PACKAGE bool __fastcall IsHighContrastBlack(void);
extern PACKAGE void __fastcall Office11DrawItemArrow(HDC DC, const System::Types::TRect &R, bool ADownArrow, bool Enabled, bool Selected, bool Flat);
extern PACKAGE void __fastcall FillGradientRect(HDC DC, const System::Types::TRect &ARect, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AHorizontal);
extern PACKAGE void __fastcall Office11DrawLargeItemArrow(HDC ADC, const System::Types::TRect &R, bool ADownArrow, int ASize, bool ASelected, bool AEnabled, bool AFlat);
extern PACKAGE bool __fastcall IsHighContrastWhite(void);
extern PACKAGE bool __fastcall IsHighContrast2(void);
extern PACKAGE bool __fastcall IsXPStandardScheme(void);
extern PACKAGE void __fastcall FillRectByColor(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
extern PACKAGE void __fastcall FrameRectByColor(HDC DC, const System::Types::TRect &R, System::Uitypes::TColor AColor);
extern PACKAGE unsigned __fastcall GetGradientColorRect(const System::Types::TRect &ARect, int X, System::Uitypes::TColor AColor1, System::Uitypes::TColor AColor2, bool AHorizontal);
}	/* namespace Dxoffice11 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXOFFICE11)
using namespace Dxoffice11;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dxoffice11HPP
