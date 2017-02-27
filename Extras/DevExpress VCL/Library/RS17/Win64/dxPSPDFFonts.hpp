// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPDFFonts.pas' rev: 24.00 (Win64)

#ifndef DxpspdffontsHPP
#define DxpspdffontsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxPSPDFExportCore.hpp>	// Pascal unit
#include <dxPSPDFStrings.hpp>	// Pascal unit
#include <dxPSTrueTypeFont.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpspdffonts
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSPDFFontInfo;
class PASCALIMPLEMENTATION TdxPSPDFFontInfo : public Dxpspdfexportcore::TdxPSPDFObject
{
	typedef Dxpspdfexportcore::TdxPSPDFObject inherited;
	
private:
	Dxpspdfexportcore::TdxPSPDFCustomFont* FOwner;
	
public:
	__fastcall virtual TdxPSPDFFontInfo(Dxpspdfexportcore::TdxPSPDFCustomFont* AOwner);
	__property Dxpspdfexportcore::TdxPSPDFCustomFont* Owner = {read=FOwner};
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFFontInfo(void) { }
	
};


class DELPHICLASS TdxPSPDFFontFile;
class PASCALIMPLEMENTATION TdxPSPDFFontFile : public TdxPSPDFFontInfo
{
	typedef TdxPSPDFFontInfo inherited;
	
private:
	System::Classes::TMemoryStream* FFontData;
	bool __fastcall GetFontDataValid(void);
	
protected:
	virtual void __fastcall FontDataNeeded(void);
	virtual Dxpspdfexportcore::TdxPSPDFStreamType __fastcall GetContentStreamType(void);
	virtual void __fastcall WriteContentStream(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteHeader(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual ~TdxPSPDFFontFile(void);
	__property System::Classes::TMemoryStream* FontData = {read=FFontData};
	__property bool FontDataValid = {read=GetFontDataValid, nodefault};
public:
	/* TdxPSPDFFontInfo.Create */ inline __fastcall virtual TdxPSPDFFontFile(Dxpspdfexportcore::TdxPSPDFCustomFont* AOwner) : TdxPSPDFFontInfo(AOwner) { }
	
};


class DELPHICLASS TdxPSPDFFontDescriptor;
class PASCALIMPLEMENTATION TdxPSPDFFontDescriptor : public TdxPSPDFFontInfo
{
	typedef TdxPSPDFFontInfo inherited;
	
private:
	int FAscent;
	int FAveCharWidth;
	int FCapHeight;
	System::StaticArray<System::Word, 256> FCharWidths;
	int FDescent;
	System::Byte FFirstChar;
	System::Types::TRect FFontBox;
	TdxPSPDFFontFile* FFontFile;
	unsigned FFontFlags;
	int FItalicAngle;
	System::Byte FLastChar;
	int FLeading;
	int FMaxCharWidth;
	bool FMetricValid;
	int FStemVertical;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetType();
	virtual int __fastcall CalculateFontFlags(const tagPANOSE &APanose);
	virtual TdxPSPDFFontFile* __fastcall CreateFontFile(void);
	System::Word __fastcall GetCharWidth(System::Byte AIndex);
	virtual void __fastcall CalculateMetric(HDC DC, const _OUTLINETEXTMETRICA &AMetric);
	virtual void __fastcall MetricNeeded(void);
	virtual void __fastcall WriteHeader(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual ~TdxPSPDFFontDescriptor(void);
	virtual void __fastcall PopulateExportList(Dxpspdfexportcore::TdxPSPDFObjectList* AList);
	__property int Ascent = {read=FAscent, nodefault};
	__property int AveCharWidth = {read=FAveCharWidth, nodefault};
	__property int CapHeight = {read=FCapHeight, nodefault};
	__property System::Word CharWidth[System::Byte Index] = {read=GetCharWidth};
	__property int Descent = {read=FDescent, nodefault};
	__property System::Byte FirstChar = {read=FFirstChar, nodefault};
	__property System::Types::TRect FontBox = {read=FFontBox};
	__property TdxPSPDFFontFile* FontFile = {read=FFontFile};
	__property unsigned FontFlags = {read=FFontFlags, nodefault};
	__property int ItalicAngle = {read=FItalicAngle, nodefault};
	__property System::Byte LastChar = {read=FLastChar, nodefault};
	__property int MaxCharWidth = {read=FMaxCharWidth, nodefault};
	__property bool MetricValid = {read=FMetricValid, nodefault};
	__property int StemVertical = {read=FStemVertical, nodefault};
public:
	/* TdxPSPDFFontInfo.Create */ inline __fastcall virtual TdxPSPDFFontDescriptor(Dxpspdfexportcore::TdxPSPDFCustomFont* AOwner) : TdxPSPDFFontInfo(AOwner) { }
	
};


class DELPHICLASS TdxPSPDFTrueTypeFontEncoding;
class PASCALIMPLEMENTATION TdxPSPDFTrueTypeFontEncoding : public TdxPSPDFFontInfo
{
	typedef TdxPSPDFFontInfo inherited;
	
private:
	int __fastcall GetCharset(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetType();
	void __fastcall WriteEncodingTable(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteHeader(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	
public:
	__property int Charset = {read=GetCharset, nodefault};
public:
	/* TdxPSPDFFontInfo.Create */ inline __fastcall virtual TdxPSPDFTrueTypeFontEncoding(Dxpspdfexportcore::TdxPSPDFCustomFont* AOwner) : TdxPSPDFFontInfo(AOwner) { }
	
public:
	/* TdxPSPDFCustomObject.Destroy */ inline __fastcall virtual ~TdxPSPDFTrueTypeFontEncoding(void) { }
	
};


class DELPHICLASS TdxPSPDFTrueTypeFont;
class PASCALIMPLEMENTATION TdxPSPDFTrueTypeFont : public Dxpspdfexportcore::TdxPSPDFCustomFont
{
	typedef Dxpspdfexportcore::TdxPSPDFCustomFont inherited;
	
private:
	TdxPSPDFFontDescriptor* FDescriptor;
	TdxPSPDFTrueTypeFontEncoding* FEncoding;
	
protected:
	System::AnsiString __fastcall ConvertToAnsiString(const System::WideString AText);
	__classmethod virtual System::UnicodeString __fastcall GetSubType();
	void __fastcall WriteCharWidths(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteHeader(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFTrueTypeFont(Dxpspdfexportcore::TdxPSPDFFontList* AOwner, bool AEmbed, Vcl::Graphics::TFont* AFont);
	__fastcall virtual ~TdxPSPDFTrueTypeFont(void);
	virtual bool __fastcall CanEncodeText(const System::WideString S);
	virtual System::AnsiString __fastcall EncodeText(const System::WideString S);
	virtual int __fastcall TextWidth(const System::WideString S);
	virtual void __fastcall PopulateExportList(Dxpspdfexportcore::TdxPSPDFObjectList* AList);
	__property TdxPSPDFFontDescriptor* Descriptor = {read=FDescriptor};
	__property TdxPSPDFTrueTypeFontEncoding* Encoding = {read=FEncoding};
};


class DELPHICLASS TdxPSPDFCIDSystemInfo;
class PASCALIMPLEMENTATION TdxPSPDFCIDSystemInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FOrdering;
	System::UnicodeString FRegistry;
	int FSupplement;
	
public:
	__fastcall virtual TdxPSPDFCIDSystemInfo(const System::UnicodeString AOrdering);
	virtual void __fastcall Write(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	__property System::UnicodeString Ordering = {read=FOrdering, write=FOrdering};
	__property System::UnicodeString Registry = {read=FRegistry, write=FRegistry};
	__property int Supplement = {read=FSupplement, write=FSupplement, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxPSPDFCIDSystemInfo(void) { }
	
};


class DELPHICLASS TdxPSPDFCIDFontInfo;
class DELPHICLASS TdxPSPDFCIDFont;
class PASCALIMPLEMENTATION TdxPSPDFCIDFontInfo : public TdxPSPDFFontInfo
{
	typedef TdxPSPDFFontInfo inherited;
	
private:
	TdxPSPDFFontDescriptor* FDescriptor;
	TdxPSPDFCIDSystemInfo* FSystemInfo;
	Dxpstruetypefont::TdxPSTTFCharCacheList* __fastcall GetCharCache(void);
	int __fastcall GetGlyphIndexWidth(System::Word Index);
	TdxPSPDFCIDFont* __fastcall GetOwner(void);
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetSubType();
	__classmethod virtual System::UnicodeString __fastcall GetType();
	virtual void __fastcall WriteCharWidths(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	virtual void __fastcall WriteHeader(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFCIDFontInfo(Dxpspdfexportcore::TdxPSPDFCustomFont* AOwner);
	__fastcall virtual ~TdxPSPDFCIDFontInfo(void);
	virtual void __fastcall PopulateExportList(Dxpspdfexportcore::TdxPSPDFObjectList* AList);
	__property Dxpstruetypefont::TdxPSTTFCharCacheList* CharCache = {read=GetCharCache};
	__property TdxPSPDFFontDescriptor* Descriptor = {read=FDescriptor};
	__property int GlyphIndexWidth[System::Word Index] = {read=GetGlyphIndexWidth};
	__property TdxPSPDFCIDFont* Owner = {read=GetOwner};
	__property TdxPSPDFCIDSystemInfo* SystemInfo = {read=FSystemInfo};
};


class DELPHICLASS TdxPSPDFCIDFontFile;
class PASCALIMPLEMENTATION TdxPSPDFCIDFontFile : public TdxPSPDFFontFile
{
	typedef TdxPSPDFFontFile inherited;
	
private:
	bool __fastcall CanRebuildFont(void);
	TdxPSPDFCIDFont* __fastcall GetOwner(void);
	Dxpstruetypefont::TdxPSTTFFile* __fastcall GetTTFFile(void);
	
protected:
	virtual void __fastcall FontDataNeeded(void);
	
public:
	__property TdxPSPDFCIDFont* Owner = {read=GetOwner};
	__property Dxpstruetypefont::TdxPSTTFFile* TTFFile = {read=GetTTFFile};
public:
	/* TdxPSPDFFontFile.Destroy */ inline __fastcall virtual ~TdxPSPDFCIDFontFile(void) { }
	
public:
	/* TdxPSPDFFontInfo.Create */ inline __fastcall virtual TdxPSPDFCIDFontFile(Dxpspdfexportcore::TdxPSPDFCustomFont* AOwner) : TdxPSPDFFontFile(AOwner) { }
	
};


class DELPHICLASS TdxPSPDFCIDFontDescriptor;
class PASCALIMPLEMENTATION TdxPSPDFCIDFontDescriptor : public TdxPSPDFFontDescriptor
{
	typedef TdxPSPDFFontDescriptor inherited;
	
protected:
	virtual TdxPSPDFFontFile* __fastcall CreateFontFile(void);
public:
	/* TdxPSPDFFontDescriptor.Destroy */ inline __fastcall virtual ~TdxPSPDFCIDFontDescriptor(void) { }
	
public:
	/* TdxPSPDFFontInfo.Create */ inline __fastcall virtual TdxPSPDFCIDFontDescriptor(Dxpspdfexportcore::TdxPSPDFCustomFont* AOwner) : TdxPSPDFFontDescriptor(AOwner) { }
	
};


class DELPHICLASS TdxPSPDFCIDFontConversionTable;
class PASCALIMPLEMENTATION TdxPSPDFCIDFont : public Dxpspdfexportcore::TdxPSPDFCustomFont
{
	typedef Dxpspdfexportcore::TdxPSPDFCustomFont inherited;
	
private:
	Dxpstruetypefont::TdxPSTTFCharCacheList* FCharCache;
	TdxPSPDFCIDFontConversionTable* FConversionTable;
	TdxPSPDFCIDFontInfo* FFontInfo;
	Dxpstruetypefont::TdxPSTTFFile* FTTFFile;
	
protected:
	__classmethod virtual System::UnicodeString __fastcall GetSubType();
	virtual void __fastcall WriteHeader(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFCIDFont(Dxpspdfexportcore::TdxPSPDFFontList* AOwner, bool AEmbed, Vcl::Graphics::TFont* AFont);
	__fastcall virtual ~TdxPSPDFCIDFont(void);
	virtual bool __fastcall CanEncodeText(const System::WideString S);
	virtual System::UnicodeString __fastcall EncodeFontName(void);
	virtual System::AnsiString __fastcall EncodeText(const System::WideString S);
	virtual int __fastcall TextWidth(const System::WideString S);
	virtual void __fastcall PopulateExportList(Dxpspdfexportcore::TdxPSPDFObjectList* AList);
	__property Dxpstruetypefont::TdxPSTTFCharCacheList* CharCache = {read=FCharCache};
	__property TdxPSPDFCIDFontConversionTable* ConversionTable = {read=FConversionTable};
	__property TdxPSPDFCIDFontInfo* FontInfo = {read=FFontInfo};
	__property Dxpstruetypefont::TdxPSTTFFile* TTFFile = {read=FTTFFile};
};


class PASCALIMPLEMENTATION TdxPSPDFCIDFontConversionTable : public TdxPSPDFFontInfo
{
	typedef TdxPSPDFFontInfo inherited;
	
private:
	TdxPSPDFCIDSystemInfo* FSystemInfo;
	Dxpstruetypefont::TdxPSTTFCharCacheList* __fastcall GetCharCache(void);
	System::UnicodeString __fastcall GetCMapName(void);
	int __fastcall GetGlyphIndex(System::Word ACharCode);
	TdxPSPDFCIDFont* __fastcall GetOwner(void);
	
protected:
	virtual Dxpspdfexportcore::TdxPSPDFStreamType __fastcall GetContentStreamType(void);
	virtual void __fastcall WriteContentStream(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	void __fastcall WriteConversionTable(Dxpspdfexportcore::TdxPSPDFWriter* AWriter);
	
public:
	__fastcall virtual TdxPSPDFCIDFontConversionTable(Dxpspdfexportcore::TdxPSPDFCustomFont* AOwner);
	__fastcall virtual ~TdxPSPDFCIDFontConversionTable(void);
	__property Dxpstruetypefont::TdxPSTTFCharCacheList* CharCache = {read=GetCharCache};
	__property System::UnicodeString CMapName = {read=GetCMapName};
	__property int GlyphIndex[System::Word CharCode] = {read=GetGlyphIndex};
	__property TdxPSPDFCIDFont* Owner = {read=GetOwner};
	__property TdxPSPDFCIDSystemInfo* SystemInfo = {read=FSystemInfo};
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TdxPSPDFFontGlyphsBand
{
public:
	System::Word StartIndex;
	System::Word FinishIndex;
};
#pragma pack(pop)


class DELPHICLASS TdxPSPDFFontGlyphsInfo;
class PASCALIMPLEMENTATION TdxPSPDFFontGlyphsInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<TdxPSPDFFontGlyphsBand> _TdxPSPDFFontGlyphsInfo__1;
	
	
private:
	System::UnicodeString FFontName;
	_TdxPSPDFFontGlyphsInfo__1 FGlyphsBands;
	void __fastcall Analyze(Vcl::Graphics::TFont* AFont);
	
public:
	__fastcall virtual TdxPSPDFFontGlyphsInfo(Vcl::Graphics::TFont* AFont);
	__fastcall virtual ~TdxPSPDFFontGlyphsInfo(void);
	bool __fastcall HasGlyph(const System::WideChar AChar);
	__property System::UnicodeString FontName = {read=FFontName};
};


class DELPHICLASS TdxPSPDFFontsManager;
class PASCALIMPLEMENTATION TdxPSPDFFontsManager : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FAllFontsProcessed;
	Vcl::Graphics::TFont* FCachedFont;
	Cxclasses::TcxObjectList* FCachedInfo;
	System::WideChar FSymbol;
	bool __fastcall CheckFont(const System::UnicodeString AFontName);
	TdxPSPDFFontGlyphsInfo* __fastcall GetCachedInfo(int Index);
	int __fastcall GetCachedInfoCount(void);
	
public:
	__fastcall virtual TdxPSPDFFontsManager(void);
	__fastcall virtual ~TdxPSPDFFontsManager(void);
	bool __fastcall Exists(const System::UnicodeString AFontName);
	Dxpspdfexportcore::TdxPSPDFCustomFont* __fastcall GetFontForSymbol(const System::WideChar ASymbol, Dxpspdfexportcore::TdxPSPDFCustomFont* ACurrentFont);
	bool __fastcall GetFontInfoForSymbol(const System::WideChar ASymbol, /* out */ TdxPSPDFFontGlyphsInfo* &AInfo);
	__property TdxPSPDFFontGlyphsInfo* CachedInfo[int Index] = {read=GetCachedInfo};
	__property int CachedInfoCount = {read=GetCachedInfoCount, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxPDFCanCreateCIDFont(Vcl::Graphics::TFont* AFont);
extern PACKAGE TdxPSPDFFontsManager* __fastcall dxPDFFontsManager(void);
extern PACKAGE bool __fastcall dxPDFCanEmbedFont(Vcl::Graphics::TFont* AFont);
}	/* namespace Dxpspdffonts */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPDFFONTS)
using namespace Dxpspdffonts;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpspdffontsHPP
