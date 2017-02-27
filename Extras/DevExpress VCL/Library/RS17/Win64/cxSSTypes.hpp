// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxSSTypes.pas' rev: 24.00 (Win64)

#ifndef CxsstypesHPP
#define CxsstypesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxsstypes
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS ESpreadSheetError;
class PASCALIMPLEMENTATION ESpreadSheetError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall ESpreadSheetError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall ESpreadSheetError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall ESpreadSheetError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall ESpreadSheetError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall ESpreadSheetError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall ESpreadSheetError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall ESpreadSheetError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall ESpreadSheetError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ESpreadSheetError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall ESpreadSheetError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ESpreadSheetError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall ESpreadSheetError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~ESpreadSheetError(void) { }
	
};


typedef System::Byte *PByte;

typedef System::Word *PWord;

typedef double *PDouble;

typedef bool *PBoolean;

typedef int *PInteger;

typedef short *PSmallInt;

typedef System::StaticArray<System::Byte, 2147483647> TByteArray;

typedef TByteArray *PByteArray;

typedef System::StaticArray<bool, 2147483647> TBoolArray;

typedef TBoolArray *PBoolArray;

typedef System::StaticArray<int, 536870911> TIntArray;

typedef TIntArray *PIntArray;

typedef __int64 *PInt64;

typedef System::StaticArray<System::Types::TRect, 134217727> TRectArray;

typedef TRectArray *PRectArray;

typedef System::DynamicArray<System::Types::TRect> TcxSSRectsArray;

typedef System::UnicodeString TcxString;

typedef System::WideChar * PcxString;

enum TcxSortType : unsigned char { stAscending, stDescending };

enum TcxSSHeaderType : unsigned char { htCol, htRow };

enum TcxSSNavigatorBtn : unsigned char { nbStart, nbPrev, nbNext, nbEnd };

enum TcxSSPainterType : unsigned char { ptOffice97Style, ptOfficeXPStyle, ptCustom };

enum TcxSSCellsModify : unsigned char { msShiftCol, msShiftRow, msAllCol, msAllRow };

enum TcxSSModifyType : unsigned char { mtDelete, mtInsert };

enum TcxSSEdgeBorder : unsigned char { eLeft, eTop, eRight, eBottom };

typedef System::Set<TcxSSEdgeBorder, TcxSSEdgeBorder::eLeft, TcxSSEdgeBorder::eBottom>  TcxSSEdgeBorders;

enum TcxSSEdgeLineStyle : unsigned char { lsDefault, lsThin, lsMedium, lsDashed, lsDotted, lsThick, lsDouble, lsHair, lsMediumDashed, lsDashDot, lsMediumDashDot, lsDashDotDot, lsMediumDashDotDot, lsSlantedDashDot, lsNone };

enum TcxSSHitType : unsigned char { htSheetCell, htSheetColumn, htSheetRow, htSheetCaption, htCaptionButton };

struct DECLSPEC_DRECORD TcxSSHitTestInfo
{
	#pragma pack(push,1)
	
public:
	TcxSSHitType HitType;
	union
	{
		struct 
		{
			unsigned:24;
			TcxSSNavigatorBtn Button;
		};
		struct 
		{
			unsigned:24;
			int Page;
		};
		struct 
		{
			unsigned:24;
			int Row;
		};
		struct 
		{
			unsigned:24;
			int Col;
		};
		struct 
		{
			unsigned:24;
			int CellCol;
			int CellRow;
		};
		
	};
	#pragma pack(pop)
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TRange
{
	union
	{
		struct 
		{
			__int64 TopLeft;
			__int64 BottomRight;
		};
		struct 
		{
			int Left;
			int Top;
			int Right;
			int Bottom;
		};
		
	};
};
#pragma pack(pop)


enum TcxSSFillStyle : unsigned char { fsSolid, fsGray75, fsGray50, fsGray25, fsGray12, fsGray6, fsHorzStrip, fsVertStrip, fsRevDiagonalStrip, fsDiagonalStrip, fsDiagCrossHatch, fsThickCrossHatch, fsThinHorzStrip, fsThinVertStrip, fsThinRevDiagonalStrip, fsThinDiagonalStrip, fsThinDiagCrossHatch, fsThinThickCrossHatch };

struct TcxSSFuncRec;
typedef TcxSSFuncRec *PcxSSFuncRec;

enum TcxSSCellState : unsigned char { cLocked, cReadOnly, cMerge, cShrinkToFit };

typedef System::Set<TcxSSCellState, TcxSSCellState::cLocked, TcxSSCellState::cShrinkToFit>  TcxSSCellStates;

struct TcxSSFontRec;
typedef TcxSSFontRec *PcxSSFontRec;

struct DECLSPEC_DRECORD TcxSSFontRec
{
public:
	System::UnicodeString Name;
	System::Word FontColor;
	System::Uitypes::TFontStyles Style;
	System::Uitypes::TFontCharset Charset;
	System::Int8 Size;
	HFONT FontHandle;
	System::Types::TSize Extents;
};


typedef HBRUSH TcxFillBrushHandle;

typedef HFONT TcxFontHandle;

typedef HDC TcxPainterHandle;

typedef HRGN TcxRegionHandle;

enum TcxHorzTextAlign : unsigned char { haGENERAL, haLEFT, haCENTER, haRIGHT, haFILL, haJUSTIFY };

enum TcxVertTextAlign : unsigned char { vaTOP, vaCENTER, vaBOTTOM, vaJUSTIFY };

enum TcxDisplayTextAlignment : unsigned char { dtaLEFT, dtaCENTER, dtaRIGHT, dtaFILL, dtaJUSTIFY };

struct DECLSPEC_DRECORD TcxTextBrick
{
public:
	int YPos;
	System::UnicodeString Text;
	int BreakExtra;
	int BreakCount;
};


typedef System::DynamicArray<TcxTextBrick> TWordExtents;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxTextParameters
{
public:
	TcxHorzTextAlign HorzAlign;
	TcxVertTextAlign VertAlign;
	bool WordBreak;
	int XPos;
	System::Word FontColor;
	HFONT FontHandle;
	TWordExtents TextBricks;
};
#pragma pack(pop)


#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSSEdgeStyleRec
{
public:
	TcxSSEdgeLineStyle Style;
	System::Word Color;
};
#pragma pack(pop)


typedef System::StaticArray<TcxSSEdgeStyleRec, 4> TcxSSBordersStyle;

struct TcxSSCellStyleRec;
typedef TcxSSCellStyleRec *PcxSSCellStyleRec;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSSCellStyleRec
{
public:
	System::Word FormatIndex;
	TcxHorzTextAlign HorzAlign;
	TcxVertTextAlign VertAlign;
	bool WordBreak;
	bool ShrinkToFit;
	TcxSSCellStates CellState;
	TcxSSFontRec *FontPtr;
	TcxSSFillStyle BrushStyle;
	System::Word BrushFgColor;
	System::Word BrushBkColor;
	TcxSSBordersStyle Borders;
	int RefCount;
};
#pragma pack(pop)


typedef System::Word TcxSSColor;

typedef System::Word TxlsDataFormat;

enum TcxSSDataType : unsigned char { dtText, dtFunction, dtDateTime, dtControl };

struct TcxSSCellRec;
typedef TcxSSCellRec *PcxSSCellRec;

struct DECLSPEC_DRECORD TcxSSCellRec
{
public:
	System::UnicodeString Text;
	TcxSSCellStyleRec *StylePtr;
	#pragma pack(push,1)
	
public:
	TcxSSDataType DataType;
	union
	{
		struct 
		{
			unsigned:32;
			unsigned:24;
			System::TObject* Control;
		};
		struct 
		{
			unsigned:32;
			unsigned:24;
			double DateTime;
		};
		struct 
		{
			unsigned:32;
			unsigned:24;
			TcxSSFuncRec *FuncRecPtr;
		};
		
	};
	#pragma pack(pop)
};


typedef System::StaticArray<PcxSSCellRec, 67108863> TcxSSCellsArray;

typedef TcxSSCellsArray *PcxSSCellsArray;

struct TcxSSColumn;
typedef TcxSSColumn *PcxSSColumn;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSSColumn
{
public:
	int CellsCount;
	TcxSSCellsArray *Cells;
};
#pragma pack(pop)


typedef System::StaticArray<TcxSSColumn, 178956970> TcxSSColumns;

typedef TcxSSColumns *PcxSSColumns;

#pragma pack(push,1)
struct DECLSPEC_DRECORD Tcx3DArea
{
public:
	System::Byte Page;
	TRange Area;
};
#pragma pack(pop)


struct TcxSSNameDefinition;
typedef TcxSSNameDefinition *PcxSSNameDefinition;

struct DECLSPEC_DRECORD TcxSSNameDefinition
{
public:
	System::UnicodeString Name;
	Tcx3DArea Definition;
	bool IsDeleted;
};


typedef System::DynamicArray<TcxSSNameDefinition> TcxSSNamesDef;

struct DECLSPEC_DRECORD TcxSSSheetDef
{
public:
	System::UnicodeString SheetName;
	System::Word SheetIndex;
};


typedef System::DynamicArray<TcxSSSheetDef> TcxSSSheetsDef;

struct TcxStackItem;
typedef TcxStackItem *PcxStackItem;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxStackItem
{
public:
	System::Word Size;
	TByteArray *Tokens;
};
#pragma pack(pop)


enum TcxSSFuncStates : unsigned char { fsError, fsBool, fsSource };

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxSSFuncRec
{
public:
	int Page;
	int Col;
	int Row;
	TcxStackItem FuncTree;
	TcxStackItem CalcResult;
	int IterationCount;
	TcxSSFuncStates States;
	int IsBusy;
	bool IsBadFunction;
};
#pragma pack(pop)


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::StaticArray<System::Byte, 15> cxLineWidth;
extern PACKAGE int EmptyHandle;
static const int cxMaxViewCoord = int(0x6666666);
extern PACKAGE System::Types::TRect cxMaxViewRect;
#define cxDefaultFontName L"Tahoma"
}	/* namespace Cxsstypes */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSSTYPES)
using namespace Cxsstypes;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxsstypesHPP
