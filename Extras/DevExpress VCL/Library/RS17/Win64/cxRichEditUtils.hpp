// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxRichEditUtils.pas' rev: 24.00 (Win64)

#ifndef CxricheditutilsHPP
#define CxricheditutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.RichEdit.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <dxDrawRichTextUtils.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <RichEdit.h>

namespace Cxricheditutils
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxRichCustomAttributes;
class PASCALIMPLEMENTATION TcxRichCustomAttributes : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	Cxedit::TcxCustomEdit* FRichEdit;
	Vcl::Controls::TWinControl* __fastcall GetInnerRich(void);
	
protected:
	__property Vcl::Controls::TWinControl* InnerRich = {read=GetInnerRich};
	
public:
	__fastcall virtual TcxRichCustomAttributes(Cxedit::TcxCustomEdit* ARichEdit);
	__property Cxedit::TcxCustomEdit* RichEdit = {read=FRichEdit};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxRichCustomAttributes(void) { }
	
};


enum TcxRichEditColor : unsigned char { recBlack, recBlue, recCyan, recGreen, recMagenta, recRed, recYellow, recWhite, recDarkBlue, recDarkCyan, recDarkGreen, recDarkMagenta, recDarkRed, recDarkYellow, recDarkGray, recLightGray };

enum TcxParaFormat2Alignment : unsigned char { pfaLeft, pfaRight, pfaCenter, pfaJustify };

enum TcxParaFormat2NumberingStyle : unsigned short { pfnsRightParenthesis, pfnsParenthesis = 256, pfnsPeriod = 512, pfnsNumberOnly = 768, pfnsContinuesList = 1024, pfnsStartNew = 32768 };

enum TcxParaFormat2NumberingType : unsigned char { pfnNone, pfnSymbols, pfnNumber, pfnLCLetter, pfnUCLetter, pfnLCRoman, pfnUCRoman, pfnSequence };

enum TcxParaFormat2LineSpacingRule : unsigned char { pfsrSingle, pfsrOneAndHalf, pfsrDouble, pfsrRule3, pfsrRule4, pfsrRule5 };

enum TcxParaFormat2ShadingStyle : unsigned char { pfsNone, pfsDarkHorizontal, pfsDarkVertical, pfsDarkDownDiagonal, pfsDarkUpDiagonal, pfsDarkGrid, pfsDarkTrellis, pfsLightHorizontal, pfsLightVertical, pfsLightDownDiagonal, pfsLightUpDiagonal, pfsLightGrid, pfsLightTrellis };

enum TcxParaFormat2BorderLocation : unsigned char { pfblLeft, pfblRight, pfblTop, pfblBottom, pfblInside, pfblOutside, pfblAutocolor };

typedef System::Set<TcxParaFormat2BorderLocation, TcxParaFormat2BorderLocation::pfblLeft, TcxParaFormat2BorderLocation::pfblAutocolor>  TcxParaFormat2BorderLocations;

enum TcxParaFormat2BorderStyle : unsigned char { pfbsNone, pfbs3Per4, pfbs11Per2, pfbs21Per4, pfbs3, pfbs41Per2, pfbs6, pfbs3Per4Double, pfbs11Per2Double, pfbs21Per4Double, pfbs3Per4Gray, pfbs3Per4GrayDashed };

enum TcxParaFormat2TableStyle : unsigned char { pftsNone, pftsCell, pftsRowDelimiter };

enum TcxParaFormat2TabAlignment : unsigned char { pftaLeft, pftaCenter, pftaRight, pftaDecimal, pftaWordBar };

enum TcxParaFormat2TabLeader : unsigned char { pftlNone, pftlDotted, pftlDashed, pftlUnderlined, pftlThick, pftlDouble };

class DELPHICLASS TcxParaAttributes2;
class PASCALIMPLEMENTATION TcxParaAttributes2 : public TcxRichCustomAttributes
{
	typedef TcxRichCustomAttributes inherited;
	
private:
	TcxParaFormat2Alignment __fastcall GetAlignment(void);
	int __fastcall GetIndent(const int Index);
	TcxParaFormat2LineSpacingRule __fastcall GetLineSpacingRule(void);
	System::Word __fastcall GetNumberingStart(void);
	TcxParaFormat2NumberingStyle __fastcall GetNumberingStyle(void);
	System::Word __fastcall GetNumberingTab(void);
	TcxParaFormat2NumberingType __fastcall GetNumberingType(void);
	bool __fastcall GetPageBreakBefore(void);
	short __fastcall GetStyle(void);
	int __fastcall GetTab(System::Byte Index);
	TcxParaFormat2TabAlignment __fastcall GetTabAlignment(int Index);
	int __fastcall GetTabCount(void);
	TcxParaFormat2TabLeader __fastcall GetTabLeader(int Index);
	TcxParaFormat2TableStyle __fastcall GetTableStyle(void);
	int __fastcall GetYSpace(const int Index);
	void __fastcall SetAlignment(TcxParaFormat2Alignment Value);
	void __fastcall SetIndent(const int Index, const int Value);
	void __fastcall SetLineSpacingRule(TcxParaFormat2LineSpacingRule Value);
	void __fastcall SetNumberingStart(System::Word Value);
	void __fastcall SetNumberingStyle(TcxParaFormat2NumberingStyle Value);
	void __fastcall SetNumberingTab(System::Word Value);
	void __fastcall SetNumberingType(TcxParaFormat2NumberingType Value);
	void __fastcall SetPageBreakBefore(bool Value);
	void __fastcall SetStyle(short Value);
	void __fastcall SetTab(System::Byte Index, int Value);
	void __fastcall SetTabAlignment(int Index, const TcxParaFormat2TabAlignment Value);
	void __fastcall SetTabCount(int Value);
	void __fastcall SetTabLeader(int Index, const TcxParaFormat2TabLeader Value);
	void __fastcall SetTabValues(int Index, int AWidth, TcxParaFormat2TabAlignment AAlignment, TcxParaFormat2TabLeader ALeader);
	void __fastcall SetYSpace(const int Index, const int Value);
	
protected:
	virtual void __fastcall GetAttributes(PARAFORMAT2 &AParagraph);
	virtual void __fastcall InitParagraph(PARAFORMAT2 &AParagraph);
	virtual void __fastcall SetAttributes(PARAFORMAT2 &AParagraph);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxParaFormat2Alignment Alignment = {read=GetAlignment, write=SetAlignment, nodefault};
	__property System::Word NumberingStart = {read=GetNumberingStart, write=SetNumberingStart, nodefault};
	__property TcxParaFormat2NumberingStyle NumberingStyle = {read=GetNumberingStyle, write=SetNumberingStyle, nodefault};
	__property System::Word NumberingTab = {read=GetNumberingTab, write=SetNumberingTab, nodefault};
	__property TcxParaFormat2NumberingType NumberingType = {read=GetNumberingType, write=SetNumberingType, nodefault};
	__property int AbsoluteIndent = {read=GetIndent, write=SetIndent, index=3, nodefault};
	__property int FirstIndent = {read=GetIndent, write=SetIndent, index=0, nodefault};
	__property int OffsetIndent = {read=GetIndent, write=SetIndent, index=2, nodefault};
	__property int RightIndent = {read=GetIndent, write=SetIndent, index=1, nodefault};
	__property int Tab[System::Byte Index] = {read=GetTab, write=SetTab};
	__property TcxParaFormat2TabAlignment TabAlignment[int Index] = {read=GetTabAlignment, write=SetTabAlignment};
	__property int TabCount = {read=GetTabCount, write=SetTabCount, nodefault};
	__property TcxParaFormat2TabLeader TabLeader[int Index] = {read=GetTabLeader, write=SetTabLeader};
	__property int LineSpacing = {read=GetYSpace, write=SetYSpace, index=2, nodefault};
	__property TcxParaFormat2LineSpacingRule LineSpacingRule = {read=GetLineSpacingRule, write=SetLineSpacingRule, nodefault};
	__property int SpaceAfter = {read=GetYSpace, write=SetYSpace, index=1, nodefault};
	__property int SpaceBefore = {read=GetYSpace, write=SetYSpace, index=0, nodefault};
	__property short Style = {read=GetStyle, write=SetStyle, nodefault};
	__property TcxParaFormat2TableStyle TableStyle = {read=GetTableStyle, nodefault};
	__property bool PageBreakBefore = {read=GetPageBreakBefore, write=SetPageBreakBefore, nodefault};
public:
	/* TcxRichCustomAttributes.Create */ inline __fastcall virtual TcxParaAttributes2(Cxedit::TcxCustomEdit* ARichEdit) : TcxRichCustomAttributes(ARichEdit) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxParaAttributes2(void) { }
	
};


enum TcxCharFormat2UnderlineType : unsigned char { cfutNone, cfutSolid, cfutDotted, cfutDouble, cfutWordOnly };

enum TcxCharFormat2Weight : unsigned char { cfwDontCare, cfwThin, cfwUltraLight, cfwLight, cfwNormal, cfwMedium, cfwSemiBold, cfwBold, cfwUltraBold, cfwHeavy };

enum TcxCharFormat2FontStyleEx : unsigned char { cffsAllCaps, cffsDisabled, cffsEmboss, cffsHidden, cffsImprint, cffsOutline, cffsRevised, cffsShadow, cffsSmallCaps, cffsSubscript, cffsSuperscript };

typedef System::Set<TcxCharFormat2FontStyleEx, TcxCharFormat2FontStyleEx::cffsAllCaps, TcxCharFormat2FontStyleEx::cffsSuperscript>  TcxCharFormat2FontStylesEx;

class DELPHICLASS TcxTextAttributes2;
class PASCALIMPLEMENTATION TcxTextAttributes2 : public TcxRichCustomAttributes
{
	typedef TcxRichCustomAttributes inherited;
	
private:
	Vcl::Comctrls::TAttributeType FType;
	unsigned __fastcall GetEffects(void);
	void __fastcall SetEffects(unsigned AMask, unsigned AEffects);
	System::Uitypes::TFontCharset __fastcall GetCharset(void);
	System::Uitypes::TColor __fastcall GetColor(int Index);
	Vcl::Comctrls::TConsistentAttributes __fastcall GetConsistentAttributes(void);
	int __fastcall GetHeight(void);
	System::Uitypes::TFontName __fastcall GetName(void);
	int __fastcall GetOffset(void);
	System::Uitypes::TFontPitch __fastcall GetPitch(void);
	bool __fastcall GetProtected(void);
	int __fastcall GetSize(void);
	System::Uitypes::TFontStyles __fastcall GetStyle(void);
	TcxCharFormat2FontStylesEx __fastcall GetStyleEx(void);
	TcxCharFormat2UnderlineType __fastcall GetUnderlineType(void);
	TcxCharFormat2Weight __fastcall GetWeight(void);
	void __fastcall SetCharset(const System::Uitypes::TFontCharset Value);
	void __fastcall SetColor(int Index, const System::Uitypes::TColor Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetName(const System::Uitypes::TFontName Value);
	void __fastcall SetOffset(int Value);
	void __fastcall SetPitch(const System::Uitypes::TFontPitch Value);
	void __fastcall SetProtected(bool Value);
	void __fastcall SetSize(int Value);
	void __fastcall SetStyle(const System::Uitypes::TFontStyles Value);
	void __fastcall SetStyleEx(const TcxCharFormat2FontStylesEx Value);
	void __fastcall SetUnderlineType(const TcxCharFormat2UnderlineType Value);
	void __fastcall SetWeight(const TcxCharFormat2Weight Value);
	
protected:
	virtual void __fastcall GetAttributes(Winapi::Richedit::_CHARFORMAT2W &AFormat);
	virtual void __fastcall InitFormat(Winapi::Richedit::_CHARFORMAT2W &AFormat);
	virtual void __fastcall SetAttributes(Winapi::Richedit::_CHARFORMAT2W &AFormat);
	NativeUInt __fastcall GetFlag(void);
	
public:
	__fastcall virtual TcxTextAttributes2(Cxedit::TcxCustomEdit* ARichEdit, Vcl::Comctrls::TAttributeType AType);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::Uitypes::TColor BackgroundColor = {read=GetColor, write=SetColor, index=0, nodefault};
	__property System::Uitypes::TFontCharset Charset = {read=GetCharset, write=SetCharset, nodefault};
	__property System::Uitypes::TColor Color = {read=GetColor, write=SetColor, index=1, nodefault};
	__property Vcl::Comctrls::TConsistentAttributes ConsistentAttributes = {read=GetConsistentAttributes, nodefault};
	__property int Height = {read=GetHeight, write=SetHeight, nodefault};
	__property System::Uitypes::TFontName Name = {read=GetName, write=SetName};
	__property int Offset = {read=GetOffset, write=SetOffset, nodefault};
	__property System::Uitypes::TFontPitch Pitch = {read=GetPitch, write=SetPitch, nodefault};
	__property bool Protected = {read=GetProtected, write=SetProtected, nodefault};
	__property int Size = {read=GetSize, write=SetSize, nodefault};
	__property System::Uitypes::TFontStyles Style = {read=GetStyle, write=SetStyle, nodefault};
	__property TcxCharFormat2FontStylesEx StyleEx = {read=GetStyleEx, write=SetStyleEx, nodefault};
	__property TcxCharFormat2UnderlineType UnderlineType = {read=GetUnderlineType, write=SetUnderlineType, nodefault};
	__property TcxCharFormat2Weight Weight = {read=GetWeight, write=SetWeight, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxTextAttributes2(void) { }
	
};


struct DECLSPEC_DRECORD TcxRichEditTableRowParams
{
public:
	System::Byte cbSize;
	System::Byte cbCellSize;
	System::Byte cCell;
	System::Byte cRow;
	int dxCellMargin;
	int dxIndent;
	int dyHeight;
	unsigned nParams;
};


typedef TcxRichEditTableRowParams *PcxRichEditTableRowParams;

struct DECLSPEC_DRECORD TcxRichEditTableRowWinSevenParams
{
public:
	System::Byte cbSize;
	System::Byte cbCellSize;
	System::Byte cCell;
	System::Byte cRow;
	int dxCellMargin;
	int dxIndent;
	int dyHeight;
	unsigned nParams;
	int cpStartRow;
	System::Byte bTableLevel;
	System::Byte iCell;
};


struct DECLSPEC_DRECORD TcxRichEditTableCellParams
{
public:
	unsigned dxWidth;
	System::Word nParams;
	System::Word wShading;
	short dxBrdrLeft;
	short dyBrdrTop;
	short dxBrdrRight;
	short dyBrdrBottom;
	unsigned crBrdrLeft;
	unsigned crBrdrTop;
	unsigned crBrdrRight;
	unsigned crBrdrBottom;
	unsigned crBackPat;
	unsigned crForePat;
};


struct DECLSPEC_DRECORD TcxRichEditTableBorderColor
{
public:
	TcxRichEditColor Left;
	TcxRichEditColor Top;
	TcxRichEditColor Right;
	TcxRichEditColor Bottom;
};


struct DECLSPEC_DRECORD TcxRichEditTableColumnParams
{
public:
	TcxRichEditColor BackgroundColor;
	TcxRichEditTableBorderColor BorderColor;
	System::Types::TRect BorderWidth;
	TcxRichEditColor ForegroundColor;
	Cxedit::TcxEditVertAlignment VerticalAlignment;
	unsigned Width;
};


typedef System::DynamicArray<TcxRichEditTableColumnParams> TcxRichEditTableColumnParamsList;

class DELPHICLASS TcxRichEditTableParams;
class PASCALIMPLEMENTATION TcxRichEditTableParams : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	unsigned FCellMargins;
	unsigned FRowHeight;
	unsigned FRowIndent;
	TcxRichEditTableColumnParamsList FColumnParams;
	int __fastcall GetColumnParamsCount(void);
	
protected:
	virtual TcxRichEditTableColumnParams __fastcall GetDefaultColumnParams(void);
	
public:
	__fastcall virtual ~TcxRichEditTableParams(void);
	int __fastcall AddColumnParams(void)/* overload */;
	int __fastcall AddColumnParams(const TcxRichEditTableColumnParams &AParams)/* overload */;
	void __fastcall ClearColumnParams(void);
	void __fastcall InsertTable(Cxedit::TcxCustomEdit* ARichEdit, int AColumnCount, int ARowCount);
	__property TcxRichEditTableColumnParamsList ColumnParams = {read=FColumnParams};
	__property int ColumnParamsCount = {read=GetColumnParamsCount, nodefault};
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=FAlignment, nodefault};
	__property unsigned CellMargins = {read=FCellMargins, write=FCellMargins, nodefault};
	__property unsigned RowHeight = {read=FRowHeight, write=FRowHeight, nodefault};
	__property unsigned RowIndent = {read=FRowIndent, write=FRowIndent, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxRichEditTableParams(void) : System::Classes::TPersistent() { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxParaFormat2BorderLocations __fastcall cxIntegerToParaFormat2BorderLocations(int AValue);
extern PACKAGE int __fastcall cxParaFormat2BorderLocationsToInteger(TcxParaFormat2BorderLocations AValue);
extern PACKAGE System::Uitypes::TColor __fastcall cxRichEditColorToColor(TcxRichEditColor AValue);
extern PACKAGE int __fastcall cxPixelsToTwips(int AValue);
}	/* namespace Cxricheditutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXRICHEDITUTILS)
using namespace Cxricheditutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxricheditutilsHPP
