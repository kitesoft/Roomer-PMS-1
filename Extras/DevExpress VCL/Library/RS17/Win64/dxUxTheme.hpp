// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxUxTheme.pas' rev: 24.00 (Win64)

#ifndef DxuxthemeHPP
#define DxuxthemeHPP

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
#include <Winapi.CommCtrl.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxuxtheme
{
//-- type declarations -------------------------------------------------------
typedef NativeUInt TdxTheme;

typedef int TdxThemeSize;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxMargins
{
public:
	int cxLeftWidth;
	int cxRightWidth;
	int cyTopHeight;
	int cyBottomHeight;
};
#pragma pack(pop)


typedef TdxMargins *PdxMargins;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxIntList
{
public:
	int iValueCount;
	System::StaticArray<int, 10> iValues;
};
#pragma pack(pop)


typedef TdxIntList *PdxIntList;

enum TdxPropertyOrigin : unsigned char { PO_STATE, PO_PART, PO_CLASS, PO_GLOBAL, PO_NOTFOUND };

typedef NativeUInt TdxPaintBuffer;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxDTTOpts
{
public:
	unsigned dwSize;
	unsigned dwFlags;
	unsigned crText;
	unsigned crBorder;
	unsigned crShadow;
	int iTextShadowType;
	System::Types::TPoint ptShadowOffset;
	int iBorderSize;
	int iFontPropId;
	int iColorPropId;
	int iStateId;
	BOOL fApplyOverlay;
	int iGlowSize;
	unsigned pfnDrawTextCallback;
	NativeInt lParam;
};
#pragma pack(pop)


typedef TdxDTTOpts *PdxDTTOpts;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxBPPaintParams
{
public:
	unsigned cbSize;
	unsigned dwFlags;
	System::Types::TRect *prcExclude;
	void *pBlendFunction;
};
#pragma pack(pop)


typedef TdxBPPaintParams *PdxBPPaintParams;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 dxMaxIntListCount = System::Int8(0xa);
extern PACKAGE NativeUInt __fastcall OpenThemeData(HWND hWnd, System::WideChar * pszClassList);
extern PACKAGE HRESULT __fastcall CloseThemeData(NativeUInt hTheme);
extern PACKAGE HRESULT __fastcall DrawThemeBackground(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::Types::PRect pRect, System::Types::PRect pClipRect = (System::Types::PRect)(0x0))/* overload */;
extern PACKAGE HRESULT __fastcall DrawThemeBackground(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, const System::Types::TRect &pRect, System::Types::PRect pClipRect = (System::Types::PRect)(0x0))/* overload */;
extern PACKAGE HRESULT __fastcall DrawThemeBackground(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, const System::Types::TRect &pRect, const System::Types::TRect &pClipRect)/* overload */;
extern PACKAGE HRESULT __fastcall DrawThemeText(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::WideChar * pszText, int iCharCount, unsigned dwTextFlags, unsigned dwTextFlags2, System::Types::PRect pRect)/* overload */;
extern PACKAGE HRESULT __fastcall DrawThemeText(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::UnicodeString pszText, int iCharCount, unsigned dwTextFlags, unsigned dwTextFlags2, const System::Types::TRect &pRect)/* overload */;
extern PACKAGE HRESULT __fastcall DrawThemeTextEx(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, const System::WideString pszText, int iCharCount, unsigned dwTextFlags, const System::Types::TRect &pRect, const TdxDTTOpts &pOptions);
extern PACKAGE HRESULT __fastcall GetThemeBackgroundContentRect(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, const System::Types::TRect &BoundingRect, /* out */ System::Types::TRect &ContentRect);
extern PACKAGE HRESULT __fastcall GetThemeBackgroundExtent(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::Types::PRect pContentRect, /* out */ System::Types::TRect &ExtentRect);
extern PACKAGE HRESULT __fastcall GetThemePartSize(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::Types::PRect prc, int eSize, System::Types::PSize psz)/* overload */;
extern PACKAGE HRESULT __fastcall GetThemePartSize(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, const System::Types::TRect &prc, int eSize, /* out */ System::Types::TSize &psz)/* overload */;
extern PACKAGE HRESULT __fastcall GetThemePartSize(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, int eSize, /* out */ System::Types::TSize &psz)/* overload */;
extern PACKAGE HRESULT __fastcall GetThemeTextExtent(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::WideChar * pszTextL, int iCharCount, unsigned dwTextFlags, System::Types::PRect pBoundingRect, /* out */ System::Types::TRect &ExtentRect);
extern PACKAGE HRESULT __fastcall GetThemeTextMetrics(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, /* out */ tagTEXTMETRICW &tm);
extern PACKAGE HRESULT __fastcall GetThemeBackgroundRegion(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::Types::PRect pRect, /* out */ HRGN &Region);
extern PACKAGE HRESULT __fastcall HitTestThemeBackground(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, unsigned dwOptions, System::Types::PRect pRect, HRGN hRgn, System::Types::TPoint ptTest, /* out */ System::Word &wHitTestCode);
extern PACKAGE HRESULT __fastcall DrawThemeEdge(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::Types::PRect pDestRect, unsigned uEdge, unsigned uFlags, System::Types::PRect pContentRect)/* overload */;
extern PACKAGE HRESULT __fastcall DrawThemeEdge(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, const System::Types::TRect &pDestRect, unsigned uEdge, unsigned uFlags, /* out */ System::Types::TRect &pContentRect)/* overload */;
extern PACKAGE HRESULT __fastcall DrawThemeEdge(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, const System::Types::TRect &pDestRect, unsigned uEdge, unsigned uFlags)/* overload */;
extern PACKAGE HRESULT __fastcall DrawThemeIcon(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, System::Types::PRect pRect, NativeUInt himl, int iImageIndex);
extern PACKAGE BOOL __fastcall IsThemePartDefined(NativeUInt hTheme, int iPartId, int iStateId);
extern PACKAGE BOOL __fastcall IsThemeBackgroundPartiallyTransparent(NativeUInt hTheme, int iPartId, int iStateId);
extern PACKAGE HRESULT __fastcall DrawThemeParentBackground(HWND hWnd, HDC DC, const System::Types::TRect &prc);
extern PACKAGE HRESULT __fastcall GetThemeColor(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, /* out */ unsigned &Color);
extern PACKAGE HRESULT __fastcall GetThemeMetric(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, int iPropId, /* out */ int &iVal);
extern PACKAGE HRESULT __fastcall GetThemeString(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, System::WideChar * pszBuff, int cchMaxBuffChars);
extern PACKAGE HRESULT __fastcall GetThemeBool(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, /* out */ BOOL &fVal);
extern PACKAGE HRESULT __fastcall GetThemeInt(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, /* out */ int &iVal);
extern PACKAGE HRESULT __fastcall GetThemeEnumValue(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, /* out */ int &iVal);
extern PACKAGE HRESULT __fastcall GetThemePosition(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, /* out */ System::Types::TPoint &Point);
extern PACKAGE HRESULT __fastcall GetThemeFont(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, int iPropId, /* out */ tagLOGFONTW &Font);
extern PACKAGE HRESULT __fastcall GetThemeRect(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, /* out */ System::Types::TRect &Rect);
extern PACKAGE HRESULT __fastcall GetThemeMargins(NativeUInt hTheme, HDC DC, int iPartId, int iStateId, int iPropId, System::Types::PRect prc, /* out */ TdxMargins &Margins);
extern PACKAGE HRESULT __fastcall GetThemeIntList(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, /* out */ TdxIntList &IntList);
extern PACKAGE HRESULT __fastcall GetThemePropertyOrigin(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, /* out */ TdxPropertyOrigin &Origin);
extern PACKAGE HRESULT __fastcall SetWindowTheme(HWND hWnd, System::WideChar * pszSubAppName, System::WideChar * pszSubIdList);
extern PACKAGE HRESULT __fastcall GetThemeFilename(NativeUInt hTheme, int iPartId, int iStateId, int iPropId, System::WideChar * pszThemeFileName, int cchMaxBuffChars);
extern PACKAGE unsigned __fastcall GetThemeSysColor(NativeUInt hTheme, int iColorId);
extern PACKAGE HBRUSH __fastcall GetThemeSysColorBrush(NativeUInt hTheme, int iColorId);
extern PACKAGE BOOL __fastcall GetThemeSysBool(NativeUInt hTheme, int iBoolId);
extern PACKAGE int __fastcall GetThemeSysSize(NativeUInt hTheme, int iSizeId);
extern PACKAGE HRESULT __fastcall GetThemeSysFont(NativeUInt hTheme, int iFontId, /* out */ tagLOGFONTW &lf);
extern PACKAGE HRESULT __fastcall GetThemeSysString(NativeUInt hTheme, int iStringId, System::WideChar * pszStringBuff, int cchMaxStringChars);
extern PACKAGE HRESULT __fastcall GetThemeSysInt(NativeUInt hTheme, int iIntId, int &iValue);
extern PACKAGE BOOL __fastcall IsThemeActive(void);
extern PACKAGE BOOL __fastcall IsAppThemed(void);
extern PACKAGE NativeUInt __fastcall GetWindowTheme(HWND hWnd);
extern PACKAGE HRESULT __fastcall EnableThemeDialogTexture(HWND hWnd, unsigned dwFlags);
extern PACKAGE BOOL __fastcall IsThemeDialogTextureEnabled(HWND hWnd);
extern PACKAGE unsigned __fastcall GetThemeAppProperties(void);
extern PACKAGE void __fastcall SetThemeAppProperties(unsigned dwFlags);
extern PACKAGE HRESULT __fastcall GetCurrentThemeName(System::WideChar * pszThemeFileName, int cchMaxNameChars, System::WideChar * pszColorBuff, int cchMaxColorChars, System::WideChar * pszSizeBuff, int cchMaxSizeChars);
extern PACKAGE HRESULT __fastcall GetThemeDocumentationProperty(System::WideChar * pszThemeName, System::WideChar * pszPropertyName, System::WideChar * pszValueBuff, int cchMaxValChars);
extern PACKAGE HRESULT __fastcall BufferedPaintInit(void);
extern PACKAGE HRESULT __fastcall BufferedPaintUnInit(void);
extern PACKAGE NativeUInt __fastcall BeginBufferedPaint(HDC hdcTarget, System::Types::PRect prcTarget, unsigned dwFormat, PdxBPPaintParams pPaintParams, /* out */ HDC &dc);
extern PACKAGE HRESULT __fastcall EndBufferedPaint(NativeUInt hBufferedPaint, BOOL fUpdateTarget);
extern PACKAGE HRESULT __fastcall BufferedPaintClear(NativeUInt hBufferedPaint, const System::Types::TRect &R);
extern PACKAGE HRESULT __fastcall BufferedPaintSetAlpha(NativeUInt hBufferedPaint, System::Types::PRect prc, System::Byte alpha);
extern PACKAGE bool __fastcall IsThemeLibraryLoaded(void);
extern PACKAGE bool __fastcall dxBeginPanningFeedback(NativeUInt AWindow);
extern PACKAGE bool __fastcall dxUpdatePanningFeedback(NativeUInt AWindow, System::Types::TPoint AOverpan, bool AIsInertia);
extern PACKAGE bool __fastcall dxEndPanningFeedback(NativeUInt AWindow, bool AAnimateBack);
}	/* namespace Dxuxtheme */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXUXTHEME)
using namespace Dxuxtheme;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxuxthemeHPP
