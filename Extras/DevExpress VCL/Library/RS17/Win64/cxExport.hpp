// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxExport.pas' rev: 24.00 (Win64)

#ifndef CxexportHPP
#define CxexportHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Data.FmtBcd.hpp>	// Pascal unit
#include <Data.SqlTimSt.hpp>	// Pascal unit
#include <cxExportStrs.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxexport
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EcxExportData;
class PASCALIMPLEMENTATION EcxExportData : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EcxExportData(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EcxExportData(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EcxExportData(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EcxExportData(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxExportData(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EcxExportData(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EcxExportData(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EcxExportData(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxExportData(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EcxExportData(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxExportData(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EcxExportData(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EcxExportData(void) { }
	
};


typedef System::TMetaClass* TcxExportProviderClass;

typedef System::Word *PWord;

typedef int *PInteger;

typedef System::StaticArray<int, 536870911> TIntArray;

typedef TIntArray *PIntArray;

enum TcxAlignText : unsigned char { catLeft, catCenter, catRight };

enum TcxBrushStyle : unsigned char { cbsClear, cbsSolid };

enum TcxFontStyle : unsigned char { cfsBold, cfsItalic, cfsUnderline, cfsStrikeOut };

typedef System::Set<TcxFontStyle, TcxFontStyle::cfsBold, TcxFontStyle::cfsStrikeOut>  TcxFontStyles;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxCellBorders
{
public:
	bool IsDefault;
	int Width;
	int Color;
};
#pragma pack(pop)


struct TcxCacheCellStyle;
typedef TcxCacheCellStyle *PcxCacheCellStyle;

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxCacheCellStyle
{
public:
	TcxAlignText AlignText;
	System::StaticArray<System::Byte, 64> FontName;
	TcxFontStyles FontStyle;
	int FontColor;
	int FontSize;
	int FontCharset;
	System::StaticArray<TcxCellBorders, 4> Borders;
	TcxBrushStyle BrushStyle;
	int BrushBkColor;
	int BrushFgColor;
	NativeInt Format;
	bool SingleLine;
	int HashCode;
};
#pragma pack(pop)


__interface IcxCellInternalCache;
typedef System::DelphiInterface<IcxCellInternalCache> _di_IcxCellInternalCache;
struct DECLSPEC_DRECORD TcxCellInternalCache
{
public:
	_di_IcxCellInternalCache Cache;
	int Index;
};


struct DECLSPEC_DRECORD TcxCacheItem
{
public:
	TcxCellInternalCache InternalCache;
	void *Data;
	int DataSize;
	int DataType;
	int StyleIndex;
	bool IsHidden;
	#pragma pack(push,1)
	
public:
	bool IsUnion;
	union
	{
		struct 
		{
			unsigned:16;
			int Width;
			int Height;
		};
		
	};
	#pragma pack(pop)
};


typedef void __fastcall (*TcxEnumExportTypes)(const int AExportType, const System::UnicodeString AExportName);

typedef void __fastcall (*TcxEnumTypes)(const int AExportType);

__interface  INTERFACE_UUID("{DEF62C25-0B11-4BD0-AE25-BABF7EDD7883}") IcxCellInternalCache  : public System::IInterface 
{
	
public:
	virtual void __fastcall CommitCache(System::Classes::TStream* AStream, void * AParam) = 0 ;
	virtual void __fastcall CommitStyle(System::Classes::TStream* AStream, void * AParam) = 0 ;
	virtual void __fastcall DeleteCacheFromCell(const int ACol, const int ARow) = 0 ;
	virtual void __fastcall SetCacheIntoCell(const int ACol, const int ARow, _di_IcxCellInternalCache ACache) = 0 ;
};

__interface IcxExportProvider;
typedef System::DelphiInterface<IcxExportProvider> _di_IcxExportProvider;
__interface  INTERFACE_UUID("{442A08A8-CDDA-4FD6-8E15-9D8BD34554F6}") IcxExportProvider  : public System::IInterface 
{
	
public:
	virtual void __fastcall Commit(void) = 0 ;
	virtual PcxCacheCellStyle __fastcall GetCellStyle(const int ACol, const int ARow) = 0 ;
	virtual PcxCacheCellStyle __fastcall GetStyle(int AStyleIndex) = 0 ;
	virtual int __fastcall RegisterStyle(const TcxCacheCellStyle &AStyle) = 0 ;
	virtual void __fastcall SetCellDataBoolean(const int ACol, const int ARow, const bool AValue) = 0 ;
	virtual void __fastcall SetCellDataCurrency(const int ACol, const int ARow, const System::Currency AValue) = 0 ;
	virtual void __fastcall SetCellDataDouble(const int ACol, const int ARow, const double AValue) = 0 ;
	virtual void __fastcall SetCellDataDateTime(const int ACol, const int ARow, const System::TDateTime AValue) = 0 ;
	virtual void __fastcall SetCellDataInteger(const int ACol, const int ARow, const int AValue) = 0 ;
	virtual void __fastcall SetCellDataString(const int ACol, const int ARow, const System::UnicodeString AText) = 0 ;
	virtual void __fastcall SetCellDataWideString(const int ACol, const int ARow, const System::WideString AText) = 0 ;
	virtual void __fastcall SetCellStyle(const int ACol, const int ARow, const int AStyleIndex) = 0 /* overload */;
	virtual void __fastcall SetCellStyle(const int ACol, const int ARow, const int AExampleCol, const int AExampleRow) = 0 /* overload */;
	virtual void __fastcall SetCellStyle(const int ACol, const int ARow, const TcxCacheCellStyle &AStyle) = 0 /* overload */;
	virtual void __fastcall SetCellStyleEx(const int ACol, const int ARow, const int H, const int W, const int AStyleIndex) = 0 ;
	virtual void __fastcall SetCellUnion(const int ACol, const int ARow, int H, int W) = 0 ;
	virtual void __fastcall SetCellValue(const int ACol, const int ARow, const System::Variant &AValue) = 0 ;
	virtual void __fastcall SetColumnWidth(const int ACol, const int AWidth) = 0 ;
	virtual void __fastcall SetDefaultStyle(const TcxCacheCellStyle &AStyle) = 0 ;
	virtual void __fastcall SetRange(const int AColCount, const int ARowCount, bool IsVisible = true) = 0 ;
	virtual void __fastcall SetRowHeight(const int ARow, const int AHeight) = 0 ;
	virtual void __fastcall SetCellDataGraphic(const int ACol, const int ARow, Vcl::Graphics::TGraphic* &AGraphic) = 0 ;
	virtual void __fastcall SetCellPNGImage(const int ACol, const int ARow, System::TObject* APNGImage) = 0 ;
	virtual bool __fastcall SupportGraphic(void) = 0 ;
};

__interface IcxExportWithSeparators;
typedef System::DelphiInterface<IcxExportWithSeparators> _di_IcxExportWithSeparators;
__interface  INTERFACE_UUID("{0E2919A6-8B49-49D7-B55B-B44B6DECF2E5}") IcxExportWithSeparators  : public System::IInterface 
{
	
public:
	virtual void __fastcall AddSeparator(const System::UnicodeString ASeparator) = 0 ;
};

__interface IcxNameExportProvider;
typedef System::DelphiInterface<IcxNameExportProvider> _di_IcxNameExportProvider;
__interface  INTERFACE_UUID("{FC69194E-E3C7-41F4-98AE-5948813210AE}") IcxNameExportProvider  : public System::IInterface 
{
	
public:
	virtual void __fastcall SetName(const System::UnicodeString AName) = 0 ;
	virtual void __fastcall SetRangeName(const System::AnsiString AName, const System::Types::TRect &ARange) = 0 ;
};

class DELPHICLASS TcxCustomExportProvider;
class PASCALIMPLEMENTATION TcxCustomExportProvider : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	System::WideString FFileName;
	
protected:
	DYNAMIC void __fastcall Clear(void);
	__property System::WideString FileName = {read=FFileName};
	
public:
	__fastcall virtual TcxCustomExportProvider(const System::UnicodeString AFileName);
	virtual void __fastcall BeforeDestruction(void);
	__classmethod virtual int __fastcall ExportType();
	__classmethod virtual System::UnicodeString __fastcall ExportName();
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomExportProvider(void) { }
	
};


class DELPHICLASS TcxExport;
class PASCALIMPLEMENTATION TcxExport : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod virtual TcxExportProviderClass __fastcall GetExportClassByType(int AExportType);
	
public:
	__classmethod TcxCustomExportProvider* __fastcall Provider(int AExportType, const System::UnicodeString AFileName);
	__classmethod void __fastcall SupportExportTypes(TcxEnumExportTypes EnumSupportTypes);
	__classmethod void __fastcall SupportTypes(TcxEnumTypes EnumFunc);
	__classmethod bool __fastcall RegisterProviderClass(TcxExportProviderClass AProviderClass);
public:
	/* TObject.Create */ inline __fastcall TcxExport(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxExport(void) { }
	
};


class DELPHICLASS TcxExportStyleManager;
class PASCALIMPLEMENTATION TcxExportStyleManager : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxCacheCellStyle operator[](int AIndex) { return Items[AIndex]; }
	
private:
	int FRefCount;
	System::Classes::TList* FStyles;
	System::UnicodeString FFileName;
	
protected:
	__fastcall TcxExportStyleManager(const System::UnicodeString AFileName);
	
private:
	int __fastcall GetCount(void);
	TcxCacheCellStyle __fastcall GetItem(int AIndex);
	bool __fastcall StyleCompare(const PcxCacheCellStyle AStyle1, const PcxCacheCellStyle AStyle2);
	
public:
	__fastcall TcxExportStyleManager(void);
	__fastcall virtual ~TcxExportStyleManager(void);
	void __fastcall Clear(void);
	__classmethod TcxExportStyleManager* __fastcall GetInstance(const System::UnicodeString AFileName);
	PcxCacheCellStyle __fastcall GetStyle(const int AIndex);
	int __fastcall RegisterStyle(const TcxCacheCellStyle &AStyle);
	__property TcxCacheCellStyle Items[int AIndex] = {read=GetItem/*, default*/};
	__property int Count = {read=GetCount, nodefault};
};


class DELPHICLASS TFileStreamEx;
class PASCALIMPLEMENTATION TFileStreamEx : public System::Classes::TFileStream
{
	typedef System::Classes::TFileStream inherited;
	
public:
	__fastcall TFileStreamEx(const System::UnicodeString FileName, System::Word Mode)/* overload */;
public:
	/* TFileStream.Create */ inline __fastcall TFileStreamEx(const System::UnicodeString AFileName, System::Word Mode, unsigned Rights)/* overload */ : System::Classes::TFileStream(AFileName, Mode, Rights) { }
	/* TFileStream.Destroy */ inline __fastcall virtual ~TFileStreamEx(void) { }
	
};


typedef System::TMetaClass* TFileStreamClass;

class DELPHICLASS TcxExportIntList;
class PASCALIMPLEMENTATION TcxExportIntList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	NativeInt operator[](int Index) { return Items[Index]; }
	
private:
	NativeInt __fastcall GetItem(int AIndex);
	void __fastcall SetItem(int AIndex, NativeInt AValue);
	
public:
	HIDESBASE void __fastcall Add(NativeInt AValue);
	void __fastcall AddPairs(NativeInt AValue1, NativeInt AValue2);
	HIDESBASE NativeInt __fastcall Last(void);
	HIDESBASE NativeInt __fastcall First(void);
	__property NativeInt Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxExportIntList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxExportIntList(void) : System::Classes::TList() { }
	
};


class DELPHICLASS TcxExportScale;
class PASCALIMPLEMENTATION TcxExportScale : public TcxExportIntList
{
	typedef TcxExportIntList inherited;
	
private:
	int __fastcall GetVisibleCount(void);
	int __fastcall GetDelta(int AIndex);
	
public:
	void __fastcall Arrange(void);
	HIDESBASE int __fastcall IndexOf(int AItem);
	int __fastcall IndexOfEx(int AValue, int AFirstIndex, int ALastIndex);
	void __fastcall GetPosition(int AValue1, int AValue2, /* out */ int &AIndex1, /* out */ int &AIndex2);
	void __fastcall GetPositionEx(int AValue1, int AValue2, int AFirstIndex, int ALastIndex, /* out */ int &AIndex1, /* out */ int &AIndex2);
	__property int Delta[int Index] = {read=GetDelta};
	__property int VisibleCount = {read=GetVisibleCount, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxExportScale(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxExportScale(void) : TcxExportIntList() { }
	
};


typedef int __fastcall (*TcxColorToRgbProc)(int AColor);

typedef System::UnicodeString __fastcall (*TcxGetResourceStringProc)(const void * ResString);

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxCacheCellStyle DefaultCellStyle;
extern PACKAGE TFileStreamClass cxFileStreamClass;
extern PACKAGE int cxBlackColor;
extern PACKAGE int cxWindowColor;
extern PACKAGE int cxBtnTextColor;
extern PACKAGE int cxBtnShadowColor;
extern PACKAGE int cxBtnFaceColor;
extern PACKAGE TcxGetResourceStringProc cxGetResString;
extern PACKAGE bool cxUnicodeSupported;
extern PACKAGE Vcl::Graphics::TGraphicClass cxExportGraphicClass;
static const int cxExportToBinary = int(-1);
static const int cxExportToHtml = int(2);
static const int cxExportToXml = int(3);
static const int cxExportToText = int(4);
static const int cxExportToExcel = int(1);
static const int cxExportToXlsx = int(8);
extern PACKAGE System::UnicodeString cxExportCurrencyFormat;
static const int cxDataTypeAnsiString = int(1);
static const int cxDataTypeWideString = int(2);
static const int cxDataTypeDouble = int(3);
static const int cxDataTypeInteger = int(4);
static const int cxDataTypeGraphic = int(5);
static const int cxDataTypeString = int(1);
extern PACKAGE bool cxCheckForDuplicateImages;
extern PACKAGE System::ResourceString _cxExportListIndexError;
#define Cxexport_cxExportListIndexError System::LoadResourceString(&Cxexport::_cxExportListIndexError)
extern PACKAGE System::WideString __fastcall cxChangeFileExtExW(const System::WideString AFileName, const System::UnicodeString ANewExt);
extern PACKAGE System::WideString __fastcall cxExtractFileNameEx(const System::UnicodeString AFileName);
extern PACKAGE System::WideString __fastcall cxExtractFileNameExW(const System::WideString AFileName);
extern PACKAGE System::WideString __fastcall cxExtractFilePathExW(const System::WideString AFileName);
extern PACKAGE System::WideString __fastcall cxValidateFileName(const System::UnicodeString AFileName);
extern PACKAGE System::WideString __fastcall cxValidateFileNameW(const System::WideString AFileName);
extern PACKAGE void __fastcall UseGraphicImages(bool AUse);
extern PACKAGE int __fastcall cxColorToRGB(const int AColor);
extern PACKAGE System::UnicodeString __fastcall cxValidateStr(const System::UnicodeString AValue);
extern PACKAGE void __fastcall cxSetCellNativeValue(const int ACol, const int ARow, const System::Variant &AValue, _di_IcxExportProvider AProvider);
extern PACKAGE System::UnicodeString __fastcall cxUnicodeToStr(const System::WideString AText, int ACharset = 0x0);
extern PACKAGE System::WideString __fastcall cxStrToUnicode(const System::UnicodeString AText, int ACharset = 0x0);
extern PACKAGE bool __fastcall cxStrUnicodeNeeded(const System::UnicodeString AText, bool ACheckNormal = false);
extern PACKAGE int __fastcall GetHashCode(const void *Buffer, int Count);
extern PACKAGE bool __fastcall SupportGraphic(Vcl::Graphics::TGraphic* AGraphic)/* overload */;
extern PACKAGE bool __fastcall SupportGraphic(Vcl::Graphics::TGraphicClass AGraphicClass)/* overload */;
extern PACKAGE Dxgdiplusclasses::TdxPNGImage* __fastcall GraphicToPNGImage(const System::Types::TRect &AClientRect, const System::Types::TRect &ADrawRect, Vcl::Graphics::TGraphic* AGraphic);
extern PACKAGE void __fastcall GetGraphicAsText(const System::UnicodeString AFileName, Vcl::Graphics::TGraphic* &AGraphic, System::AnsiString &AGraphicText);
extern PACKAGE void __fastcall GetTextAsGraphicStream(const System::AnsiString AText, System::UnicodeString &AFileName, System::AnsiString &AStream);
extern PACKAGE void __fastcall cxExportInit(TcxGetResourceStringProc AGetResString, void * AColorProc, bool AIsNativeColor);
}	/* namespace Cxexport */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEXPORT)
using namespace Cxexport;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxexportHPP
