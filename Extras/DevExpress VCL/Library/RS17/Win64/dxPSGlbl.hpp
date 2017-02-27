// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSGlbl.pas' rev: 24.00 (Win64)

#ifndef DxpsglblHPP
#define DxpsglblHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtDlgs.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <lmcons.h>

namespace Dxpsglbl
{
//-- type declarations -------------------------------------------------------
typedef System::Int8 TDWORDBits;

typedef System::StaticArray<bool, 1> TBooleanArray;

typedef TBooleanArray *PBooleanArray;

typedef System::StaticArray<int, 1> TIntArray;

typedef TIntArray *PIntArray;

typedef System::DynamicArray<System::Types::TRect> TRects;

typedef System::DynamicArray<int> TIntegers;

typedef TIntegers TdxPSPageIndexes;

enum TdxDriveType : unsigned char { dtUnknown, dtNoRootDir, dtRemovable, dtFixed, dtRemote, dtCDROM, dtRamDisk };

enum TdxPageOrder : unsigned char { poOverThenDown, poDownThenOver };

enum TdxPageNumberFormat : unsigned char { pnfNumeral, pnfChars, pnfUpperChars, pnfRoman, pnfUpperRoman };

enum TdxUpDownGlyph : unsigned char { udgUp, udgDown };

typedef System::UnicodeString TdxPSPreviewDialogStyle;

struct DECLSPEC_DRECORD TdxPSVersion
{
public:
	int Major;
	int Minor;
	int SubMinor;
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 NullDC = System::Int8(0x0);
static const System::WideChar cMenuSeparator = (System::WideChar)(0x2d);
static const System::WideChar cPageRangeSeparator = (System::WideChar)(0x2d);
static const System::WideChar cPageSeparator = (System::WideChar)(0x2c);
static const System::Word WMPS_PRINTSTYLELISTCHANGED = System::Word(0x8065);
static const System::Word WMPS_PRINTERLISTCHANGED = System::Word(0x8066);
static const System::Word WMPS_INITIALIZEPRINTER = System::Word(0x8067);
static const System::Int8 GLYPH_UPARROW = System::Int8(0x35);
static const System::Int8 GLYPH_DOWNARROW = System::Int8(0x36);
static const System::Int8 dxFormatLeftSide = System::Int8(0x1);
static const System::Int8 dxFormatTopSide = System::Int8(0x2);
static const System::Int8 dxFormatRightSide = System::Int8(0x4);
static const System::Int8 dxFormatBottomSide = System::Int8(0x8);
static const System::Int8 dxFormatRect = System::Int8(0xf);
static const System::Int8 dxFormatTextAlignXOffset = System::Int8(0x4);
static const System::Int8 dxFormatTextAlignXLeft = System::Int8(0x0);
static const System::Int8 dxFormatTextAlignXCenter = System::Int8(0x10);
static const System::Int8 dxFormatTextAlignXRight = System::Int8(0x20);
static const System::Int8 dxFormatTextAlignXJustify = System::Int8(0x30);
static const System::Int8 dxFormatTextAlignXDistribute = System::Int8(0x40);
static const System::Int8 dxFormatTextAlignXMask = System::Int8(0x70);
static const System::Int8 dxFormatTextAlignYOffset = System::Int8(0x7);
static const System::Int8 dxFormatTextAlignYTop = System::Int8(0x0);
static const System::Byte dxFormatTextAlignYCenter = System::Byte(0x80);
static const System::Word dxFormatTextAlignYBottom = System::Word(0x100);
static const System::Word dxFormatTextAlignYDistribute = System::Word(0x180);
static const System::Word dxFormatTextAlignYMask = System::Word(0x180);
static const System::Word dxFormatEndEllipsis = System::Word(0x200);
static const System::Word dxFormatMultiline = System::Word(0x400);
static const System::Word dxFormatTransparent = System::Word(0x800);
static const int dxFormatBreakByChars = int(0x40000000);
static const int dxFormatHidePrefix = int(0x80000);
static const System::Word dxFormatCheckChecked = System::Word(0x1000);
static const System::Word dxFormatCheckEnabled = System::Word(0x2000);
static const System::Int8 dxFormatCheckButtonEdgeStyleOffset = System::Int8(0xe);
static const System::Int8 dxFormatCheckEdgeStyleNone = System::Int8(0x0);
static const System::Word dxFormatCheckEdgeStyle3D = System::Word(0x4000);
static const System::Word dxFormatCheckEdgeStyleSoft3D = System::Word(0x8000);
static const System::Word dxFormatCheckEdgeStyleBoldFlat = System::Word(0xc000);
static const int dxFormatCheckEdgeStyleUltraFlat = int(0x10000);
static const int dxFormatCheckEdgeStyleSingle = int(0x14000);
static const int dxFormatCheckButtonEdgeStyleMask = int(0x1c000);
static const System::Word dxFormatCheckFlat = System::Word(0x4000);
static const System::Word dxFormatCheckBold = System::Word(0x8000);
static const int dxFormatPreventLeftTextExceed = int(0x100000);
static const int dxFormatPreventTopTextExceed = int(0x200000);
static const System::Int8 dxFormatSortOrderOffset = System::Int8(0x16);
static const System::Int8 dxFormatSortNo = System::Int8(0x0);
static const int dxFormatSortUp = int(0x400000);
static const int dxFormatSortDown = int(0x800000);
static const int dxFormatSortOrderMask = int(0xc00000);
static const int dxFormatMakeSpaceForEmptyImage = int(0x1000000);
static const int dxFormatImageTransparent = int(0x2000000);
static const int dxFormatIsTextDrawnForCenteredImage = int(0x10000000);
static const int dxFormatIsTextShiftedForHorizontallyCenteredImage = int(0x20000000);
static const System::Int8 dxFormatCheckPosOffset = System::Int8(0x1a);
static const System::Int8 dxFormatCheckPosLeft = System::Int8(0x0);
static const int dxFormatCheckPosCenter = int(0x4000000);
static const int dxFormatCheckPosRight = int(0x8000000);
static const int dxFormatCheckPosMask = int(0xc000000);
static const System::Int8 dxFormatCheckGlyphCountOffset = System::Int8(0x1c);
static const int dxFormatCheckGlyphCountMask = int(0x70000000);
static const int dxFormatShowShadow = int(0x20000);
static const int dxFormatExcludeFromClipRgn = int(0x40000);
static const unsigned dxFormatVisible = unsigned(0x80000000);
static const int dxFormatClipChildren = int(0x80000);
static const System::Word dxFormatOwnBorderClass = System::Word(0x200);
static const System::Int8 dxFormatImageLayoutOffset = System::Int8(0xc);
static const System::Int8 dxFormatImageLayoutTopLeft = System::Int8(0x0);
static const System::Word dxFormatImageLayoutTopCenter = System::Word(0x1000);
static const System::Word dxFormatImageLayoutTopRight = System::Word(0x2000);
static const System::Word dxFormatImageLayoutCenterLeft = System::Word(0x3000);
static const System::Word dxFormatImageLayoutCenterCenter = System::Word(0x4000);
static const System::Word dxFormatImageLayoutCenterRight = System::Word(0x5000);
static const System::Word dxFormatImageLayoutBottomLeft = System::Word(0x6000);
static const System::Word dxFormatImageLayoutBottomCenter = System::Word(0x7000);
static const System::Word dxFormatImageLayoutBottomRight = System::Word(0x8000);
static const System::Word dxFormatImageLayoutMask = System::Word(0xf000);
static const System::Int8 dxFormatGraphicDrawModeOffset = System::Int8(0x4);
static const System::Int8 dxFormatGraphicDrawModeNone = System::Int8(0x0);
static const System::Int8 dxFormatGraphicDrawModeCenter = System::Int8(0x10);
static const System::Int8 dxFormatGraphicDrawModeStretch = System::Int8(0x20);
static const System::Int8 dxFormatGraphicDrawModeStretchProportional = System::Int8(0x30);
static const System::Int8 dxFormatGraphicDrawModeCenterAndStretchProportional = System::Int8(0x40);
static const System::Int8 dxFormatGraphicDrawModeMask = System::Int8(0x70);
static const System::Int8 dxFormatGraphicBufferingOffset = System::Int8(0x7);
static const System::Int8 dxFormatGraphicBufferingDefault = System::Int8(0x0);
static const System::Byte dxFormatGraphicBufferingNone = System::Byte(0x80);
static const System::Word dxFormatGraphicBufferingAlways = System::Word(0x100);
static const System::Word dxFormatGraphicBufferingMask = System::Word(0x180);
static const System::Int8 dxFormatExpandButtonBorder3D = System::Int8(0x10);
static const System::Int8 dxFormatExpandButtonBorder3DSoft = System::Int8(0x20);
static const System::Int8 dxFormatExpandButtonBorderShadow = System::Int8(0x40);
static const System::Byte dxFormatExpandButtonExpanded = System::Byte(0x80);
static const System::Word dxFormatExpandButtonKeepOddSize = System::Word(0x100);
static const System::Word dxFormatExpandButtonTransparent = System::Word(0x200);
static const System::Word dxFormatExpandButtonShowBorder = System::Word(0x400);
static const System::Word dxFormatExpandButtonVisible = System::Word(0x1000);
static const System::Int8 dxFormatTreeLineModeOffset = System::Int8(0x16);
static const System::Int8 dxFormatTreeLineModeNone = System::Int8(0x0);
static const int dxFormatTreeLineModeVertical = int(0x400000);
static const int dxFormatTreeLineModeCross = int(0x800000);
static const int dxFormatTreeLineModeTopRightCorner = int(0xc00000);
static const int dxFormatTreeLineModeBottomRightCorner = int(0x1000000);
static const int dxFormatTreeLineModeMask = int(0x1c00000);
static const System::Int8 dxFormatExButtonAlignHorzOffset = System::Int8(0x0);
static const System::Int8 dxFormatExButtonAlignHorzLeft = System::Int8(0x0);
static const System::Int8 dxFormatExButtonAlignHorzCenter = System::Int8(0x1);
static const System::Int8 dxFormatExButtonAlignHorzRight = System::Int8(0x2);
static const System::Int8 dxFormatExButtonAlignHorzMask = System::Int8(0x3);
static const System::Int8 dxFormatExButtonAlignVertOffset = System::Int8(0x2);
static const System::Int8 dxFormatExButtonAlignVertTop = System::Int8(0x0);
static const System::Int8 dxFormatExButtonAlignVertCenter = System::Int8(0x4);
static const System::Int8 dxFormatExButtonAlignVertBottom = System::Int8(0x8);
static const System::Int8 dxFormatExButtonAlignVertMask = System::Int8(0xc);
static const int dxFormatShapeTransparent = int(0x10000000);
static const int dxFormatGroupShowCaption = int(0x10000000);
static const int dxFormatGroupCaptionTransparent = int(0x20000000);
#define sdxPSRegPath L"Software\\Developer Express\\PrintingSystem"
#define sdxPSRegPathCustomColors L"CustomColors"
#define sdxPSRegPathDesignTime L"Software\\Developer Express\\PrintingSystem\\DesignTime"
#define sdxPSRegPathRunTime L"Software\\Developer Express\\PrintingSystem\\RunTime"
#define sdxPSRegPathRunTimeFormLayouts L"\\Developer Express\\PrintingSystem\\FormLayouts"
extern PACKAGE int dxDefaultMinPrintableArea;
extern PACKAGE System::Types::TRect dxDefaultInitialMargins;
extern PACKAGE System::Types::TPoint dxDefaultPhysicalPaperOffsets;
extern PACKAGE int dxDefaultInitialHeader;
extern PACKAGE int dxDefaultInitialFooter;
extern PACKAGE System::Types::TPoint dxStyleGlyphSize;
extern PACKAGE System::Classes::THelpContext dxhcAddEmptyLinkDlg;
extern PACKAGE System::Classes::THelpContext dxhcAddLinkDlg;
extern PACKAGE System::Classes::THelpContext dxhcAddStyleDlg;
extern PACKAGE System::Classes::THelpContext dxhcEditDescriptionDlg;
extern PACKAGE System::Classes::THelpContext dxhcPrintStylesDesignWindow;
extern PACKAGE System::Classes::THelpContext dxhcReportLinkDesignWindow;
extern PACKAGE System::Classes::THelpContext dxhcCompositionReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcStringGridReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcDrawGridReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcListBoxReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcCheckListBoxReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcListViewReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcTextReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcTreeViewReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcTreeListReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcOrgChartReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcFlowChartReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcInspectorGridReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcMasterViewReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhccxMCListBoxReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhccxSpreadSheetReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhccxGridReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhccxTreeListReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhccxVerticalGridReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhccxSchedulerReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhccxPivotGridReportLinkDesigner;
extern PACKAGE System::Classes::THelpContext dxhcAddComponentsToComponentPrinterDlg;
extern PACKAGE System::Classes::THelpContext dxhcAddItemsToCompositionDlg;
extern PACKAGE System::Classes::THelpContext dxhcAutoHFTextEntriesDlg;
extern PACKAGE System::Classes::THelpContext dxhcDateTimeFormatDlg;
extern PACKAGE System::Classes::THelpContext dxhcDefinePrintStyleDlg;
extern PACKAGE System::Classes::THelpContext dxhcFEFDlg;
extern PACKAGE System::Classes::THelpContext dxhcFootnotesPropertiesDlg;
extern PACKAGE System::Classes::THelpContext dxhcPageNumberFormatDlg;
extern PACKAGE System::Classes::THelpContext dxhcPageSetupDlg;
extern PACKAGE System::Classes::THelpContext dxhcPreviewPreferencesDlg;
extern PACKAGE System::Classes::THelpContext dxhcPrintDlg;
extern PACKAGE System::Classes::THelpContext dxhcPrintSetupDlg;
extern PACKAGE System::Classes::THelpContext dxhcPSReportPropertiesDlg;
extern PACKAGE System::Classes::THelpContext dxhcSelectComponentsDlg;
extern PACKAGE System::Classes::THelpContext dxhcTitlePropertiesDlg;
extern PACKAGE System::Classes::THelpContext dxhcZoomDlg;
extern PACKAGE TdxPSVersion dxPSVersion;
extern PACKAGE int dxPSStorageVersion;
extern PACKAGE int dxPSInvalidStorageVersion;
#define sdxHelpButtonName L"btnHelp"
extern PACKAGE bool AskPrinterForSupportedFonts;
extern PACKAGE bool IsComCtrlVersion471;
extern PACKAGE bool IsComCtrlVersion500;
extern PACKAGE bool IsComCtrlVersion600;
extern PACKAGE bool IsDesignTime;
extern PACKAGE int CheckHeight;
extern PACKAGE int CheckWidth;
extern PACKAGE System::WideChar PathDelimiter;
extern PACKAGE System::WideChar PercentSymbol;
extern PACKAGE bool __fastcall (*PSCanShowHintFunc)(void);
extern PACKAGE bool __fastcall CanShowHints(void);
extern PACKAGE System::UnicodeString __fastcall GetPSRegRoot(void);
extern PACKAGE int __fastcall dxPSVer(void);
extern PACKAGE int __fastcall dxPSVerMajor(void);
extern PACKAGE int __fastcall dxPSVerMinor(void);
extern PACKAGE int __fastcall dxPSVerSubMinor(void);
extern PACKAGE System::UnicodeString __fastcall dxPSVersionString(void);
extern PACKAGE Vcl::Dialogs::TColorDialog* __fastcall ColorDialog(void);
extern PACKAGE Vcl::Dialogs::TFontDialog* __fastcall FontDialog(void);
extern PACKAGE Vcl::Dialogs::TFontDialogDevice __fastcall FontDialogDevice(void);
extern PACKAGE TdxPSVersion __fastcall StringToPSVersion(System::UnicodeString AVersion, const System::UnicodeString ASeparator = L".");
extern PACKAGE int __fastcall ComparePSVersions(TdxPSVersion &V1, TdxPSVersion &V2);
}	/* namespace Dxpsglbl */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSGLBL)
using namespace Dxpsglbl;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsglblHPP
