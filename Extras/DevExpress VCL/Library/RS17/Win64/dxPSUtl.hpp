// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSUtl.pas' rev: 24.00 (Win64)

#ifndef DxpsutlHPP
#define DxpsutlHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.Themes.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPrnDev.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsutl
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
static const System::Int8 CheckMarkIndex = System::Int8(0x62);
static const System::Int8 CheckTopLeftArcOuterIndex = System::Int8(0x63);
static const System::Int8 CheckBottomRightArcOuterIndex = System::Int8(0x64);
static const System::Int8 CheckTopLeftArcInnerIndex = System::Int8(0x65);
static const System::Int8 CheckBottomRightArcInnerIndex = System::Int8(0x66);
static const System::Int8 CheckInteriorIndex = System::Int8(0x67);
static const System::Int8 RadioBeanIndex = System::Int8(0x69);
static const System::Int8 RadioTopLeftArcOuterIndex = System::Int8(0x6a);
static const System::Int8 RadioBottomRightArcOuterIndex = System::Int8(0x6b);
static const System::Int8 RadioTopLeftArcInnerIndex = System::Int8(0x6c);
static const System::Int8 RadioBottomRightArcInnerIndex = System::Int8(0x6d);
static const System::Int8 RadioInteriorIndex = System::Int8(0x6e);
static const System::Int8 SortUpMarkIndex = System::Int8(0x74);
static const System::Int8 SortDownMarkIndex = System::Int8(0x75);
static const System::Int8 PlusSignIndex = System::Int8(0x2b);
static const System::Int8 MinusSignIndex = System::Int8(0x2d);
#define InvalidFileNameChars L"<>:\"|/\\"
extern PACKAGE System::UnicodeString __fastcall dxPSFixInvalidFileNameChars(const System::UnicodeString S);
extern PACKAGE void __fastcall ActivateComboBoxControl(Vcl::Forms::TCustomForm* AForm, Vcl::Controls::TWinControl* AComboBoxControl);
extern PACKAGE void __fastcall CheckDialogFormHelpContext(Vcl::Forms::TCustomForm* AForm, Vcl::Controls::TControl* AHelpBtn, Vcl::Controls::TControl* ACancelBtn, Vcl::Controls::TControl* AOkBtn);
extern PACKAGE int __fastcall MinMax(int A, int B, int C);
extern PACKAGE int __fastcall SetLoWord(int AValue, System::Word ALoWord);
extern PACKAGE int __fastcall SetHiWord(int AValue, System::Word AHiWord);
extern PACKAGE int __fastcall SetLoHiWords(int AValue, System::Word ALoWord, System::Word AHiWord);
extern PACKAGE System::Types::TPoint __fastcall ScalePoint(const System::Types::TPoint Pt, int Numerator, int Denominator);
extern PACKAGE bool __fastcall ArePointsEqual(const System::Types::TPoint Pt1, const System::Types::TPoint Pt2);
extern PACKAGE int __fastcall GetRgnData(HRGN ARgn, /* out */ _RGNDATAHEADER &ARgnDataHeader, /* out */ Dxcore::TRects &ARects);
extern PACKAGE HRGN __fastcall ExcludeClipRect(HDC DC, const System::Types::TRect &R)/* overload */;
extern PACKAGE HRGN __fastcall ExcludeClipRect(HDC DC, int ALeft, int ATop, int ARight, int ABottom)/* overload */;
extern PACKAGE HRGN __fastcall IntersectClipRect(HDC DC, const System::Types::TRect &R, bool AlwaysClip = false)/* overload */;
extern PACKAGE HRGN __fastcall IntersectClipRect(HDC DC, int ALeft, int ATop, int ARight, int ABottom, bool AlwaysClip = false)/* overload */;
extern PACKAGE bool __fastcall RectVisible(HDC DC, const System::Types::TRect &ARect);
extern PACKAGE void __fastcall RestoreClipRgn(HDC DC, HRGN &ARgn);
extern PACKAGE System::UnicodeString __fastcall dxBoolToStr(bool AValue);
extern PACKAGE bool __fastcall dxSameStr(const System::UnicodeString S1, const System::UnicodeString S2);
extern PACKAGE bool __fastcall dxSameText(const System::UnicodeString S1, const System::UnicodeString S2);
extern PACKAGE bool __fastcall dxAreBitmapsEqual(Vcl::Graphics::TBitmap* ABitmap1, Vcl::Graphics::TBitmap* ABitmap2);
extern PACKAGE bool __fastcall dxAreBrushesEqual(Vcl::Graphics::TBrush* ABrush1, Vcl::Graphics::TBrush* ABrush2);
extern PACKAGE bool __fastcall dxAreFontsEqual(Vcl::Graphics::TFont* AFont1, Vcl::Graphics::TFont* AFont2);
extern PACKAGE bool __fastcall dxAreGraphicsEqual(Vcl::Graphics::TGraphic* AGraphic1, Vcl::Graphics::TGraphic* AGraphic2);
extern PACKAGE bool __fastcall dxArePensEqual(Vcl::Graphics::TPen* APen1, Vcl::Graphics::TPen* APen2);
extern PACKAGE System::UnicodeString __fastcall FormatFontInfo(Vcl::Graphics::TFont* AFont);
extern PACKAGE void __fastcall FontInfoToText(Vcl::Graphics::TFont* AFont, Cxtextedit::TcxTextEdit* AEdit);
extern PACKAGE bool __fastcall dxIsTrueTypeFont(Vcl::Graphics::TFont* AFont);
extern PACKAGE System::Uitypes::TColor __fastcall FindNearestColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall InvertColor(System::Uitypes::TColor AColor);
extern PACKAGE System::Uitypes::TColor __fastcall OffsetColor(System::Uitypes::TColor AColor, System::Byte ARed, System::Byte AGreen, System::Byte ABlue);
extern PACKAGE bool __fastcall IsDisplayDC(HDC DC);
extern PACKAGE bool __fastcall IsMetafileDC(HDC DC);
extern PACKAGE bool __fastcall IsPrinterDC(HDC DC);
extern PACKAGE HBRUSH __fastcall PatternBrush(void);
extern PACKAGE void __fastcall ForcePictureToBitmap(Vcl::Graphics::TPicture* APicture);
extern PACKAGE Vcl::Graphics::TGraphic* __fastcall CreateGraphic(Vcl::Graphics::TGraphicClass AGraphicClass);
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall IconToBitmap(Vcl::Graphics::TIcon* AnIcon);
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall CreateArrowBitmap(Dxpsglbl::TdxUpDownGlyph AUpDownGlyph, int AWidth = 0x10, int AHeight = 0x10, int AFontSize = 0xc);
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall CreateDoubleArrowBitmap(Dxpsglbl::TdxUpDownGlyph AUpDownGlyph, int AWidth = 0x10, int AHeight = 0x10, int AFontSize = 0x8);
extern PACKAGE Vcl::Graphics::TBitmap* __fastcall CreateGlyphBitmap(int AGlyphIndex, int AWidth = 0x10, int AHeight = 0x10, int AFontSize = 0xc);
extern PACKAGE void __fastcall DrawBlendedText(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, const System::UnicodeString AText, Vcl::Graphics::TFont* AFont);
extern PACKAGE void __fastcall DrawGlyph(HDC DC, const System::Types::TRect &R, System::Byte AGlyph, bool ACenter = false);
extern PACKAGE void __fastcall DrawSizeGrip(HDC DC, System::Types::TRect &R);
extern PACKAGE void __fastcall TransparentDraw(HDC DrawDC, HBRUSH Brush, const System::Types::TRect &R, Vcl::Graphics::TBitmap* ABitmap);
extern PACKAGE void __fastcall dxDrawThemeEdge(HDC ADC, Vcl::Themes::TThemedElementDetails &ADetails, const System::Types::TRect &R, unsigned AEdge, unsigned AFlags, System::Types::PRect AContentRect = (System::Types::PRect)(0x0));
extern PACKAGE NativeUInt __fastcall CopyDeviceMode(NativeUInt Src);
extern PACKAGE System::Types::TRect __fastcall GetDesktopWorkArea(void)/* overload */;
extern PACKAGE System::Types::TRect __fastcall GetDesktopWorkArea(const System::Types::TPoint P)/* overload */;
extern PACKAGE System::UnicodeString __fastcall GetLongFileName(const System::UnicodeString Source);
extern PACKAGE System::UnicodeString __fastcall GetMachineName(void);
extern PACKAGE System::UnicodeString __fastcall GetUserName(void);
extern PACKAGE System::UnicodeString __fastcall GetVolumeName(const System::UnicodeString APath);
extern PACKAGE bool __fastcall IsIntelliMousePresent(void);
extern PACKAGE bool __fastcall IsNetworkPresent(void);
extern PACKAGE bool __fastcall IsVolume(const System::UnicodeString APath);
extern PACKAGE bool __fastcall IsWin32Version(int AMajor, int AMinor = 0x0);
extern PACKAGE bool __fastcall PopulateShellImages(bool FullInit);
extern PACKAGE Vcl::Controls::TImageList* __fastcall ShellLargeImages(void);
extern PACKAGE Vcl::Controls::TImageList* __fastcall ShellSmallImages(void);
extern PACKAGE bool __fastcall ShowSystemSelectFolderDlg(System::UnicodeString &ADirPath);
extern PACKAGE System::UnicodeString __fastcall FormatFileSize(const __int64 AFileSize);
extern PACKAGE bool __fastcall ValidateFileName(const System::UnicodeString FileName);
extern PACKAGE void __fastcall Delay(unsigned Value);
extern PACKAGE System::UnicodeString __fastcall dxValidatePath(const System::UnicodeString S);
extern PACKAGE System::UnicodeString __fastcall ReplaceSubStr(const System::UnicodeString Source, const System::UnicodeString OldChars, const System::UnicodeString NewChars);
extern PACKAGE System::UnicodeString __fastcall ReplicateChar(const System::UnicodeString S, int ACount);
extern PACKAGE bool __fastcall DecodePageIndexes(const System::UnicodeString Source, /* out */ Dxpsglbl::TIntegers &AOutput);
extern PACKAGE System::UnicodeString __fastcall EncodePageIndexes(const Dxpsglbl::TIntegers ASource);
extern PACKAGE System::UnicodeString __fastcall Int2Roman(int AValue, bool AnUpperCase);
extern PACKAGE int __fastcall Roman2Int(System::UnicodeString AText, bool AnUpperCase);
extern PACKAGE int __fastcall Chars2Int(const System::UnicodeString AText, bool AnUpperCase);
extern PACKAGE System::UnicodeString __fastcall Int2Chars(int AValue, bool AnUpperCase);
extern PACKAGE System::UnicodeString __fastcall AddColon(const System::UnicodeString Source);
extern PACKAGE System::UnicodeString __fastcall AddEndEllipsis(const System::UnicodeString Source);
extern PACKAGE System::UnicodeString __fastcall DropAmpersand(const System::UnicodeString Source);
extern PACKAGE System::UnicodeString __fastcall DropColon(const System::UnicodeString Source);
extern PACKAGE System::UnicodeString __fastcall DropEndEllipsis(const System::UnicodeString Source);
extern PACKAGE void __fastcall MessageError(const System::UnicodeString AMessage);
extern PACKAGE void __fastcall MessageWarning(const System::UnicodeString AMessage);
extern PACKAGE bool __fastcall MessageQuestion(const System::UnicodeString AMessage);
extern PACKAGE System::UnicodeString __fastcall DropT(const System::UnicodeString Source);
extern PACKAGE bool __fastcall HasPropertyEx(System::TClass AClass, const System::UnicodeString AName, System::Typinfo::TTypeKinds ATypeKinds)/* overload */;
extern PACKAGE bool __fastcall HasPropertyEx(System::TObject* AnObject, const System::UnicodeString AName, System::Typinfo::TTypeKinds ATypeKinds)/* overload */;
extern PACKAGE bool __fastcall HasProperty(System::TClass AClass, const System::UnicodeString AName)/* overload */;
extern PACKAGE bool __fastcall HasProperty(System::TObject* AnObject, const System::UnicodeString AName)/* overload */;
extern PACKAGE System::Variant __fastcall GetProperty(System::TObject* AnObject, const System::UnicodeString AName);
extern PACKAGE void __fastcall SetProperty(System::TObject* AnObject, const System::UnicodeString AName, const System::Variant &AValue);
extern PACKAGE System::UnicodeString __fastcall dxGetStoringSectionName(System::Classes::TComponent* AComponent);
extern PACKAGE void __fastcall dxDrawComboBoxItem(Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &R, const System::UnicodeString AText, Vcl::Imglist::TCustomImageList* AnImageList, int AnImageIndex, Winapi::Windows::TOwnerDrawState AState);
extern PACKAGE void __fastcall dxLoadStrings(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName, System::Classes::TStrings* AStrings);
extern PACKAGE void __fastcall dxSaveStrings(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName, System::Classes::TStrings* AStrings);
extern PACKAGE void __fastcall dxLoadListViewColumns(System::Inifiles::TCustomIniFile* AIniFile, System::UnicodeString ASectionName, Vcl::Comctrls::TListView* AListView);
extern PACKAGE void __fastcall dxSaveListViewColumns(System::Inifiles::TCustomIniFile* AIniFile, System::UnicodeString ASectionName, Vcl::Comctrls::TListView* AListView);
extern PACKAGE void __fastcall dxSaveListViewSelection(Vcl::Comctrls::TListView* AListView, System::Classes::TList* ASelection);
extern PACKAGE void __fastcall dxRestoreListViewSelection(Vcl::Comctrls::TListView* AListView, System::Classes::TList* ASelection);
extern PACKAGE void __fastcall CopyImages(NativeUInt ASourceHandle, Vcl::Imglist::TCustomImageList* ADest);
extern PACKAGE void __fastcall PlaceButtons(Cxbuttons::TcxButton* const *AButtons, const int AButtons_Size, int ABtnOffsetX, int ARightOrigin, int ATopOrigin);
extern PACKAGE void __fastcall dxShiftIntegerListValues(System::Classes::TList* AList, int AValue);
extern PACKAGE int __fastcall dxCheckStateImageIndexMap(Vcl::Stdctrls::TCheckBoxState AState);
extern PACKAGE void __fastcall dxCreateCheckMarkImages(Cxgraphics::TcxImageList* AnImageList);
extern PACKAGE void __fastcall dxSetupPreviewControlLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, Cxlookandfeels::TcxLookAndFeelKind AKind, Cxcontrols::TcxControl* AControl);
extern PACKAGE Vcl::Imglist::TCustomImageList* __fastcall dxPSDrawModeImages(void);
extern PACKAGE HWND __fastcall dxAllocatehWnd(System::Classes::TWndMethod AMethod);
extern PACKAGE void __fastcall dxDeallocatehWnd(HWND AWnd);
extern PACKAGE NativeInt __fastcall TTagToInt(NativeInt AValue);
extern PACKAGE System::TObject* __fastcall TTagToObj(NativeInt AValue);
extern PACKAGE System::TClass __fastcall TTagToClass(NativeInt AValue);
extern PACKAGE NativeInt __fastcall MakeTTag(NativeInt AValue)/* overload */;
extern PACKAGE NativeInt __fastcall MakeTTag(System::TObject* AValue)/* overload */;
extern PACKAGE NativeInt __fastcall MakeTTag(System::TClass AValue)/* overload */;
extern PACKAGE System::Uitypes::TColor __fastcall Control_GetColor(Vcl::Controls::TControl* AControl);
extern PACKAGE Vcl::Controls::TControlStyle __fastcall Control_GetControlStyle(Vcl::Controls::TControl* AControl);
extern PACKAGE bool __fastcall Control_GetCtl3D(Vcl::Controls::TWinControl* AControl);
extern PACKAGE Vcl::Graphics::TFont* __fastcall Control_GetFont(Vcl::Controls::TControl* AControl);
extern PACKAGE Vcl::Menus::TPopupMenu* __fastcall Control_GetPopupMenu(Vcl::Controls::TControl* AControl);
extern PACKAGE System::UnicodeString __fastcall Control_GetText(Vcl::Controls::TControl* AControl);
extern PACKAGE void __fastcall Control_SetParentBackground(Vcl::Controls::TWinControl* AControl, bool Value);
extern PACKAGE void __fastcall Control_DoContextPopup(Vcl::Controls::TControl* AControl, const System::Types::TPoint Pt, bool &AHandled);
extern PACKAGE void __fastcall Control_PaintWindow(Vcl::Controls::TWinControl* AControl, HDC DC);
extern PACKAGE void __fastcall Control_SendCancelMode(Vcl::Controls::TControl* AControl, Vcl::Controls::TControl* ASender);
extern PACKAGE void __fastcall Control_UpdateBoundsRect(Vcl::Controls::TControl* AControl, const System::Types::TRect &R)/* overload */;
extern PACKAGE void __fastcall Control_UpdateBoundsRect(Vcl::Controls::TControl* AControl, int ALeft, int ARight, int AWidth, int AHeight)/* overload */;
extern PACKAGE void __fastcall PopupMenu_DoPopup(Vcl::Menus::TPopupMenu* APopupMenu);
extern PACKAGE Vcl::Forms::TBorderStyle __fastcall RichEdit_GetBorderStyle(Vcl::Comctrls::TCustomRichEdit* AControl);
extern PACKAGE System::Classes::TStrings* __fastcall RichEdit_GetLines(Vcl::Comctrls::TCustomRichEdit* AControl);
extern PACKAGE void __fastcall dxLoadImageListFromResources(Cxgraphics::TcxImageList* AImageList, const System::UnicodeString AResourceName, NativeUInt AInstance = (NativeUInt)(0ULL));
extern PACKAGE void __fastcall dxLoadBitmapFromResource(Vcl::Graphics::TBitmap* ABitmap, const System::UnicodeString AResName);
extern PACKAGE void __fastcall dxLoadIconFromResource(Vcl::Graphics::TIcon* AIcon, const System::UnicodeString AResName);
extern PACKAGE void __fastcall dxLoadIconFromResourceEx(Vcl::Extctrls::TImage* AImage, const System::UnicodeString AResName);
extern PACKAGE bool __fastcall IsDelphiObject(NativeUInt AData);
}	/* namespace Dxpsutl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSUTL)
using namespace Dxpsutl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsutlHPP
