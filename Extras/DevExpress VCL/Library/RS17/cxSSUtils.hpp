// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSUtils.pas' rev: 24.00 (Win32)

#ifndef CxssutilsHPP
#define CxssutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <cxSSTypes.hpp>	// Pascal unit
#include <cxSSRes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxssutils
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxSSUtils;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxSSUtils : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod virtual int __fastcall CheckValue(int AValue, int AMin, int AMax);
	__classmethod virtual System::UnicodeString __fastcall ColumnNameByIndex(int ACol, bool IsRCReferenceStyle = false);
	__classmethod virtual int __fastcall ColumnIndexByName(const System::ShortString &AName);
	__classmethod virtual System::UnicodeString __fastcall FormatText(const double AValue, Cxsstypes::TxlsDataFormat AFormat, System::Byte APrecision, System::Word &ATextColor);
	__classmethod virtual bool __fastcall IntersectRange(Cxsstypes::TRange &AOutRect, const Cxsstypes::TRange &ARect1, const Cxsstypes::TRange &ARect2);
	__classmethod virtual bool __fastcall PointInRect(const System::Types::TRect &Rect, const System::Types::TPoint &P);
	__classmethod virtual System::UnicodeString __fastcall RowNameByIndex(int ARow, bool IsRCReferenceStyle = false);
	__classmethod virtual bool __fastcall ValueInRange(int AValue, int AFromValue, int AToValue);
public:
	/* TObject.Create */ inline __fastcall TcxSSUtils(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxSSUtils(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int cxBlankCharCode;
extern PACKAGE int cxThousandCharCode;
extern PACKAGE int cxDecimalCharCode;
extern PACKAGE System::UnicodeString __fastcall BoolToStr(const bool Value);
extern PACKAGE bool __fastcall cxTryDateTimeFromStr(const System::UnicodeString S, /* out */ System::TDateTime &ADateTime);
extern PACKAGE bool __fastcall cxTryStrToDate(const System::UnicodeString AStr, System::TDateTime &ADate);
extern PACKAGE bool __fastcall cxTryStrToTime(const System::UnicodeString AStr, System::TDateTime &ATime);
extern PACKAGE bool __fastcall cxTryStrToDateTime(const System::UnicodeString S, /* out */ System::TDateTime &ADateTime);
extern PACKAGE System::UnicodeString __fastcall XLSErrToStr(System::Byte ACode);
extern PACKAGE bool __fastcall cxTryStrToOrdinal(const System::UnicodeString AString);
extern PACKAGE bool __fastcall StrToBool(const System::UnicodeString Value);
extern PACKAGE bool __fastcall cxTryStrToBool(const System::UnicodeString AString, bool &Value)/* overload */;
extern PACKAGE bool __fastcall cxTryStrToBool(const System::UnicodeString AString)/* overload */;
extern PACKAGE bool __fastcall cxTryStrToCurr(System::UnicodeString S, System::Currency &Value);
extern PACKAGE bool __fastcall cxTryStrToFloat(const System::UnicodeString AString, double &Value)/* overload */;
extern PACKAGE bool __fastcall cxTryStrToFloat(const System::UnicodeString AString)/* overload */;
extern PACKAGE bool __fastcall cxTryStrToInt(const System::UnicodeString AString, int &Value)/* overload */;
extern PACKAGE bool __fastcall cxTryStrToInt(const System::UnicodeString AString)/* overload */;
extern PACKAGE System::Word __fastcall Get8087CW(void);
extern PACKAGE System::Byte __fastcall SetRoundMode(const System::Byte RoundMode);
extern PACKAGE System::Byte __fastcall SetPrecisionMode(const System::Byte Precision);
extern PACKAGE System::WideString __fastcall GetLocaleStrW(int Locale, int LocaleType);
extern PACKAGE void __fastcall SetControlCodes(void);
}	/* namespace Cxssutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSUTILS)
using namespace Cxssutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxssutilsHPP
