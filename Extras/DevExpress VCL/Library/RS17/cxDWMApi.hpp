// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxDWMApi.pas' rev: 24.00 (Win32)

#ifndef CxdwmapiHPP
#define CxdwmapiHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdwmapi
{
//-- type declarations -------------------------------------------------------
#pragma pack(push,1)
struct DECLSPEC_DRECORD _DWM_BLURBEHIND
{
public:
	unsigned dwFlags;
	BOOL fEnable;
	HRGN hRgnBlur;
	BOOL fTransitionOnMaximized;
};
#pragma pack(pop)


typedef _DWM_BLURBEHIND DWM_BLURBEHIND;

typedef _DWM_BLURBEHIND *PDWM_BLURBEHIND;

enum TDWMNCRENDERINGPOLICY : unsigned int { DWMNCRP_USEWINDOWSTYLE, DWMNCRP_DISABLED, DWMNCRP_ENABLED, DWMNCRP_LAST };

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE HRESULT __stdcall (*DwmDefWindowProc)(HWND wnd, unsigned msg, NativeUInt wParam, NativeInt lParam, NativeInt plResult);
extern PACKAGE HRESULT __stdcall (*DwmEnableBlurBehindWindow)(HWND wnd, PDWM_BLURBEHIND pBlurBehind);
extern PACKAGE HRESULT __stdcall (*DwmEnableComposition)(bool uCompositionAction);
extern PACKAGE HRESULT __stdcall (*DwmEnableMMCSS)(bool fEnableMMCSS);
extern PACKAGE HRESULT __stdcall (*DwmExtendFrameIntoClientArea)(HWND wnd, Dxuxtheme::PdxMargins pMarInset);
extern PACKAGE HRESULT __stdcall (*DwmGetColorizationColor)(/* out */ unsigned &pcrColorization, /* out */ BOOL &pfOpaqueBlend);
extern PACKAGE HRESULT __stdcall (*DwmGetWindowAttribute)(HWND hwnd, unsigned dwAttribute, void * pvAttribute, unsigned cbAttribute);
extern PACKAGE HRESULT __stdcall (*DwmIsCompositionEnabled)(/* out */ BOOL &pfEnabled);
extern PACKAGE HRESULT __stdcall (*DwmSetWindowAttribute)(HWND hwnd, unsigned dwAttribute, void * pvAttribute, unsigned cbAttribute);
extern PACKAGE HRESULT __fastcall (*DwmSetIconicThumbnail)(HWND hwnd, HBITMAP hbmp, unsigned dwSITFlags);
extern PACKAGE HRESULT __fastcall (*DwmSetIconicLivePreviewBitmap)(HWND hwnd, HBITMAP hbmp, System::Types::TPoint &pptClient, unsigned dwSITFlags);
extern PACKAGE HRESULT __fastcall (*DwmInvalidateIconicBitmaps)(HWND hwnd);
extern PACKAGE bool __fastcall IsDwmPresent(void);
extern PACKAGE bool __fastcall IsCompositionEnabled(void);
}	/* namespace Cxdwmapi */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDWMAPI)
using namespace Cxdwmapi;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdwmapiHPP
