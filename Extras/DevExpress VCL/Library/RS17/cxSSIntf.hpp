// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSIntf.pas' rev: 24.00 (Win32)

#ifndef CxssintfHPP
#define CxssintfHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxExcelConst.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssintf
{
//-- type declarations -------------------------------------------------------
__interface IcxSpreadSheetListener;
typedef System::DelphiInterface<IcxSpreadSheetListener> _di_IcxSpreadSheetListener;
__interface  INTERFACE_UUID("{87FE7288-8326-40ED-9102-D54A6D27AE18}") IcxSpreadSheetListener  : public System::IInterface 
{
	
public:
	virtual int __fastcall BeginUpdate(void) = 0 ;
	virtual int __fastcall EndUpdate(void) = 0 ;
};

__interface IcxSpreadSheetCellStyle;
typedef System::DelphiInterface<IcxSpreadSheetCellStyle> _di_IcxSpreadSheetCellStyle;
__interface  INTERFACE_UUID("{3A381E00-4311-49A2-816B-C79F4690AF96}") IcxSpreadSheetCellStyle  : public System::IInterface 
{
	
public:
	virtual Cxsstypes::TxlsDataFormat __fastcall GetFormat(void) = 0 ;
	virtual void __fastcall SetBorderStyle(const Cxsstypes::TcxSSEdgeBorder ASide, Cxsstypes::TcxSSEdgeLineStyle AStyle, System::Byte AColor) = 0 ;
	virtual void __fastcall SetFillStyle(const Cxsstypes::TcxSSFillStyle AStyle, System::Byte AFgColor, System::Byte ABkColor) = 0 ;
	virtual void __fastcall SetFormatStyle(const Cxsstypes::TxlsDataFormat AFormat) = 0 ;
	virtual void __fastcall SetFont(const Cxsstypes::TcxSSFontRec &AFont) = 0 ;
	virtual void __fastcall SetCellStyle(const Cxsstypes::PcxSSCellStyleRec AStyle, bool ASetDefaultBorders = false) = 0 ;
};

__interface IcxSpreadSheetCell;
typedef System::DelphiInterface<IcxSpreadSheetCell> _di_IcxSpreadSheetCell;
__interface  INTERFACE_UUID("{4D22A8C2-F327-4080-B3B6-D8526CE00F0E}") IcxSpreadSheetCell  : public System::IInterface 
{
	
public:
	virtual _di_IcxSpreadSheetCellStyle __fastcall GetCellStyle(void) = 0 ;
	virtual void __fastcall SetText(const System::UnicodeString AValue) = 0 ;
	virtual System::UnicodeString __fastcall GetText(void) = 0 ;
	virtual void __fastcall SetTextEx(const System::UnicodeString Value, bool IsFormula = false, bool Analyze = true) = 0 ;
};

__interface IcxBookSheet;
typedef System::DelphiInterface<IcxBookSheet> _di_IcxBookSheet;
__interface  INTERFACE_UUID("{6EA75673-9538-4626-97C8-08A5A818FCB4}") IcxBookSheet  : public System::IInterface 
{
	
public:
	virtual void __fastcall SetColRowSize(const Cxsstypes::TcxSSHeaderType AKind, const int AColumn, const int ASize, const int AOriginalSize, bool ALocked, bool AVisible = true) = 0 ;
	virtual void __fastcall SetDefaultSize(const Cxsstypes::TcxSSHeaderType AKind, int ASize) = 0 ;
	virtual void __fastcall SetMergedCells(const System::Types::TRect &ARect, bool IsMerge) = 0 ;
	virtual void __fastcall SetPageDimension(const int HorzCount, const int VertCount) = 0 ;
	virtual void __fastcall SetProtection(bool Value) = 0 ;
	virtual void __fastcall SetViewInformation(const System::Types::TRect &ASelectionRect, bool AViewFormulas, bool AViewGrid, bool AViewHeaders, bool AScrollBars) = 0 ;
	virtual _di_IcxSpreadSheetCell __fastcall GetCell(const int ACol, const int ARow) = 0 ;
};

__interface IcxSpreadSheetBook;
typedef System::DelphiInterface<IcxSpreadSheetBook> _di_IcxSpreadSheetBook;
__interface  INTERFACE_UUID("{BD273CEA-BD42-43E1-9E05-2CE37DE710F6}") IcxSpreadSheetBook  : public System::IInterface 
{
	
public:
	virtual _di_IcxBookSheet __fastcall AddSheet(const System::UnicodeString AName, bool AVisible) = 0 ;
	virtual int __fastcall BeginUpdate(void) = 0 ;
	virtual int __fastcall DefineName(const System::UnicodeString AName, System::Word APage, const System::Types::TRect &ARect) = 0 ;
	virtual int __fastcall EndUpdate(void) = 0 ;
	virtual _di_IcxSpreadSheetCell __fastcall GetCell(System::Word APage, int ACol, int ARow) = 0 ;
	virtual _di_IcxBookSheet __fastcall GetSheet(System::Word APage) = 0 ;
	virtual System::Word __fastcall GetPageCount(void) = 0 ;
	virtual void __fastcall SetProtection(bool Value) = 0 ;
	virtual void __fastcall SetDefaultStyle(const Cxsstypes::PcxSSCellStyleRec AStyle) = 0 ;
	virtual void __fastcall SetPalette(const Cxexcelconst::PcxExcelPalette APalette) = 0 ;
	virtual void __fastcall SetPageVisible(System::Word APage, const bool AValue) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxssintf */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSINTF)
using namespace Cxssintf;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssintfHPP
