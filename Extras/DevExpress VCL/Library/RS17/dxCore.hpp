// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCore.pas' rev: 24.00 (Win32)

#ifndef DxcoreHPP
#define DxcoreHPP

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
#include <System.Variants.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcore
{
//-- type declarations -------------------------------------------------------
typedef System::DynamicArray<System::Uitypes::TColor> TColors;

typedef System::DynamicArray<System::Types::TPoint> TPoints;

typedef System::DynamicArray<System::Types::TRect> TRects;

typedef System::DynamicArray<tagRGBQUAD> TRGBColors;

typedef NativeInt *PdxNativeInt;

typedef NativeInt TdxNativeInt;

typedef NativeUInt *PdxNativeUInt;

typedef NativeUInt TdxNativeUInt;

enum TdxDefaultBoolean : unsigned char { bFalse, bTrue, bDefault };

enum TdxCorner : unsigned char { coTopLeft, coTopRight, coBottomLeft, coBottomRight };

enum TdxOrientation : unsigned char { orHorizontal, orVertical };

enum TdxSortOrder : unsigned char { soNone, soAscending, soDescending };

__interface IdxLocalizerListener;
typedef System::DelphiInterface<IdxLocalizerListener> _di_IdxLocalizerListener;
__interface  INTERFACE_UUID("{2E926681-1A56-4599-E8E0-B02D62740E56}") IdxLocalizerListener  : public System::IInterface 
{
	
public:
	virtual void __fastcall TranslationChanged(void) = 0 ;
};

typedef System::Set<char, 0, 255>  TdxAnsiCharSet;

class DELPHICLASS TdxStream;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxStream : public System::Classes::TStream
{
	typedef System::Classes::TStream inherited;
	
private:
	bool FIsUnicode;
	System::Classes::TStream* FStream;
	
protected:
	virtual __int64 __fastcall GetSize(void);
	
public:
	__fastcall virtual TdxStream(System::Classes::TStream* AStream);
	virtual int __fastcall Read(void *Buffer, int Count)/* overload */;
	virtual int __fastcall Seek(int Offset, System::Word Origin)/* overload */;
	virtual int __fastcall Write(const void *Buffer, int Count)/* overload */;
	__property bool IsUnicode = {read=FIsUnicode, nodefault};
	__property System::Classes::TStream* Stream = {read=FStream};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxStream(void) { }
	
/* Hoisted overloads: */
	
public:
	inline int __fastcall  Read(System::DynamicArray<System::Byte> Buffer, int Offset, int Count){ return System::Classes::TStream::Read(Buffer, Offset, Count); }
	inline int __fastcall  Read(System::DynamicArray<System::Byte> &Buffer, int Count){ return System::Classes::TStream::Read(Buffer, Count); }
	inline __int64 __fastcall  Seek(const __int64 Offset, System::Classes::TSeekOrigin Origin){ return System::Classes::TStream::Seek(Offset, Origin); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Offset, int Count){ return System::Classes::TStream::Write(Buffer, Offset, Count); }
	inline int __fastcall  Write(const System::DynamicArray<System::Byte> Buffer, int Count){ return System::Classes::TStream::Write(Buffer, Count); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxProductResourceStrings;
typedef void __fastcall (*TdxAddResourceStringsProcedure)(TdxProductResourceStrings* AProduct);

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxProductResourceStrings : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FName;
	TdxAddResourceStringsProcedure FInitializeProc;
	System::Classes::TStrings* FResStringNames;
	System::UnicodeString __fastcall GetNames(int AIndex);
	int __fastcall GetResStringsCount(void);
	void __fastcall SetTranslation(int AIndex);
	System::UnicodeString __fastcall GetValues(int AIndex);
	void __fastcall InitializeResStringNames(void);
	
protected:
	void __fastcall Translate(void);
	
public:
	__fastcall virtual TdxProductResourceStrings(const System::UnicodeString AName, TdxAddResourceStringsProcedure AInitializeProc);
	__fastcall virtual ~TdxProductResourceStrings(void);
	void __fastcall Add(const System::UnicodeString AResStringName, void * AResStringAddr);
	void __fastcall Clear(void);
	int __fastcall GetIndexByName(const System::UnicodeString AName);
	__property System::UnicodeString Name = {read=FName};
	__property System::UnicodeString Names[int AIndex] = {read=GetNames};
	__property int ResStringsCount = {read=GetResStringsCount, nodefault};
	__property System::UnicodeString Values[int AIndex] = {read=GetValues};
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxLocalizationTranslateResStringEvent)(const System::UnicodeString AResStringName, void * AResString);

class DELPHICLASS TdxResourceStringsRepository;
class PASCALIMPLEMENTATION TdxResourceStringsRepository : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FListeners;
	System::Contnrs::TObjectList* FProducts;
	TdxLocalizationTranslateResStringEvent FOnTranslateResString;
	TdxProductResourceStrings* __fastcall GetProducts(int AIndex);
	int __fastcall GetProductsCount(void);
	
public:
	__fastcall virtual TdxResourceStringsRepository(void);
	__fastcall virtual ~TdxResourceStringsRepository(void);
	void __fastcall AddListener(_di_IdxLocalizerListener AListener);
	void __fastcall RemoveListener(_di_IdxLocalizerListener AListener);
	void __fastcall NotifyListeners(void);
	void __fastcall RegisterProduct(const System::UnicodeString AProductName, TdxAddResourceStringsProcedure AAddStringsProc);
	int __fastcall GetProductIndexByName(const System::UnicodeString AName);
	System::UnicodeString __fastcall GetOriginalValue(const System::UnicodeString AName);
	void __fastcall Translate(void);
	void __fastcall UnRegisterProduct(const System::UnicodeString AProductName);
	__property TdxProductResourceStrings* Products[int Index] = {read=GetProducts};
	__property int ProductsCount = {read=GetProductsCount, nodefault};
	__property TdxLocalizationTranslateResStringEvent OnTranslateResString = {read=FOnTranslateResString, write=FOnTranslateResString};
};


typedef void __fastcall (*TdxProc)(void);

class DELPHICLASS TdxUnitsLoader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxUnitsLoader : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	System::Classes::TList* FinalizeList;
	System::Classes::TList* InitializeList;
	void __fastcall CallProc(TdxProc AProc);
	
public:
	__fastcall TdxUnitsLoader(void);
	__fastcall virtual ~TdxUnitsLoader(void);
	void __fastcall AddUnit(const void * AInitializeProc, const void * AFinalizeProc);
	void __fastcall RemoveUnit(const void * AFinalizeProc);
	void __fastcall Finalize(void);
	void __fastcall Initialize(void);
};

#pragma pack(pop)

class DELPHICLASS EdxException;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxException : public System::Sysutils::Exception
{
	typedef System::Sysutils::Exception inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxException(const System::UnicodeString Msg) : System::Sysutils::Exception(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : System::Sysutils::Exception(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxException(NativeUInt Ident)/* overload */ : System::Sysutils::Exception(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxException(System::PResStringRec ResStringRec)/* overload */ : System::Sysutils::Exception(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxException(const System::UnicodeString Msg, int AHelpContext) : System::Sysutils::Exception(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : System::Sysutils::Exception(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxException(NativeUInt Ident, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : System::Sysutils::Exception(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : System::Sysutils::Exception(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxException(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS EdxTestException;
#pragma pack(push,4)
class PASCALIMPLEMENTATION EdxTestException : public EdxException
{
	typedef EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EdxTestException(const System::UnicodeString Msg) : EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EdxTestException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EdxTestException(NativeUInt Ident)/* overload */ : EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EdxTestException(System::PResStringRec ResStringRec)/* overload */ : EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxTestException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EdxTestException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EdxTestException(const System::UnicodeString Msg, int AHelpContext) : EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EdxTestException(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxTestException(NativeUInt Ident, int AHelpContext)/* overload */ : EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EdxTestException(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxTestException(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EdxTestException(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EdxTestException(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE unsigned dxBuildNumber;
extern PACKAGE System::Word dxUnicodePrefix;
#define dxCRLF L"\r\n"
extern PACKAGE bool IsWin9X;
extern PACKAGE bool IsWin95;
extern PACKAGE bool IsWin98;
extern PACKAGE bool IsWinMe;
extern PACKAGE bool IsWinNT;
extern PACKAGE bool IsWin2K;
extern PACKAGE bool IsWin2KOrLater;
extern PACKAGE bool IsWinXP;
extern PACKAGE bool IsWinXPOrLater;
extern PACKAGE bool IsWin2KOrXP;
extern PACKAGE bool IsWinVista;
extern PACKAGE bool IsWinVistaOrLater;
extern PACKAGE bool IsWinSeven;
extern PACKAGE bool IsWinSevenOrLater;
extern PACKAGE bool IsWin8;
extern PACKAGE bool IsWin8OrLater;
extern PACKAGE bool IsWin64Bit;
extern PACKAGE bool __fastcall dxVarIsBlob(const System::Variant &V);
extern PACKAGE System::UnicodeString __fastcall dxShortStringToString(const System::ShortString &S);
extern PACKAGE System::ShortString __fastcall dxStringToShortString(const System::UnicodeString S);
extern PACKAGE tagRGBQUAD __fastcall dxColorToRGBQuad(System::Uitypes::TColor AColor, System::Byte AReserved = (System::Byte)(0x0));
extern PACKAGE System::Uitypes::TColor __fastcall dxRGBQuadToColor(const tagRGBQUAD ARGB);
extern PACKAGE int __fastcall cxGetBitmapPixelFormat(Vcl::Graphics::TBitmap* ABitmap);
extern PACKAGE void __fastcall dxFillBitmapInfoHeader(/* out */ tagBITMAPINFOHEADER &AHeader, int AWidth, int AHeight, System::WordBool ATopDownDIB)/* overload */;
extern PACKAGE void __fastcall dxFillBitmapInfoHeader(/* out */ tagBITMAPINFOHEADER &AHeader, Vcl::Graphics::TBitmap* ABitmap, System::WordBool ATopDownDIB)/* overload */;
extern PACKAGE bool __fastcall GetBitmapBits(Vcl::Graphics::TBitmap* ABitmap, TRGBColors &AColors, bool ATopDownDIB);
extern PACKAGE void __fastcall GetBitmapBitsByScanLine(Vcl::Graphics::TBitmap* ABitmap, TRGBColors &AColors);
extern PACKAGE void __fastcall SetBitmapBits(Vcl::Graphics::TBitmap* ABitmap, const TRGBColors AColors, bool ATopDownDIB);
extern PACKAGE bool __fastcall dxIsAlphaUsed(Vcl::Graphics::TBitmap* ABitmap);
extern PACKAGE int __fastcall WriteBufferToStream(System::Classes::TStream* AStream, void * ABuffer, int ACount);
extern PACKAGE int __fastcall WriteCharToStream(System::Classes::TStream* AStream, char AValue);
extern PACKAGE int __fastcall WriteDoubleToStream(System::Classes::TStream* AStream, double AValue);
extern PACKAGE int __fastcall WriteIntegerToStream(System::Classes::TStream* AStream, int AValue);
extern PACKAGE int __fastcall WriteSmallIntToStream(System::Classes::TStream* AStream, short AValue);
extern PACKAGE int __fastcall WriteStringToStream(System::Classes::TStream* AStream, const System::AnsiString AValue);
extern PACKAGE bool __fastcall ReadBufferFromStream(System::Classes::TStream* AStream, void * ABuffer, int Count);
extern PACKAGE int __fastcall ReadStringFromStream(System::Classes::TStream* AStream, /* out */ System::AnsiString &AValue);
extern PACKAGE void __fastcall WriteBoolean(void * ADestination, System::WordBool AValue, int AOffset = 0x0);
extern PACKAGE void __fastcall WriteByte(void * ADestination, System::Byte AValue, int AOffset = 0x0);
extern PACKAGE void __fastcall WriteInteger(void * ADestination, int AValue, int AOffset = 0x0);
extern PACKAGE void __fastcall WritePointer(void * ADestination, void * AValue);
extern PACKAGE void __fastcall WriteWord(void * ADestination, System::Word AValue, int AOffset = 0x0);
extern PACKAGE void * __fastcall ShiftPointer(void * P, int AOffset);
extern PACKAGE NativeInt __fastcall dxPointToLParam(const System::Types::TPoint &P);
extern PACKAGE System::Types::TPoint __fastcall dxLParamToPoint(NativeInt AParam);
extern PACKAGE void __fastcall dxCompressStream(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream, System::Byte ACompressMethod, int ASize = 0x0);
extern PACKAGE void __fastcall dxDecompressStream(System::Classes::TStream* ASourceStream, System::Classes::TStream* ADestStream);
extern PACKAGE System::Word __fastcall dxGetAnsiCharCType1(char Ch);
extern PACKAGE System::Word __fastcall dxGetWideCharCType1(System::WideChar Ch);
extern PACKAGE void __fastcall ExchangeLongWords(void *AValue1, void *AValue2);
extern PACKAGE void __fastcall ExchangePointers(void *AValue1, void *AValue2);
extern PACKAGE void __fastcall dxAbstractError(void);
extern PACKAGE void __fastcall dxTestCheck(System::WordBool AValue, const System::UnicodeString AMessage);
extern PACKAGE void __fastcall dxCheckOrientation(TdxOrientation &AValue, TdxOrientation ADefaultOrientation);
extern PACKAGE int __fastcall dxElfHash(const System::AnsiString S, unsigned ALangID = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall dxElfHash(const System::WideString S, unsigned ALangID = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall dxElfHash(System::WideChar * P, int ALength, unsigned ALangID = (unsigned)(0x0))/* overload */;
extern PACKAGE int __fastcall dxElfHash(System::WideChar * P, int ALength, System::WideChar * AUpperCaseBuffer, int AUpperCaseBufferLength, unsigned ALangID = (unsigned)(0x0))/* overload */;
extern PACKAGE System::UnicodeString __fastcall dxGetLocaleInfo(int ALocale, int ALocaleType, const System::UnicodeString ADefaultValue = System::UnicodeString());
extern PACKAGE void __fastcall dxCallNotify(System::Classes::TNotifyEvent ANotifyEvent, System::TObject* ASender);
extern PACKAGE __int64 __fastcall dxGetTickCount(void);
extern PACKAGE bool __fastcall dxSameMethods(const void *Method1, const void *Method2);
extern PACKAGE System::AnsiString __fastcall dxBinToHex(const System::AnsiString ABuffer)/* overload */;
extern PACKAGE System::AnsiString __fastcall dxBinToHex(const char * ABuffer, int ABufSize)/* overload */;
extern PACKAGE System::AnsiString __fastcall dxHexToBin(const System::AnsiString AText)/* overload */;
extern PACKAGE System::AnsiString __fastcall dxHexToBin(const char * AText)/* overload */;
extern PACKAGE System::Byte __fastcall dxHexToByte(const System::UnicodeString AHex);
extern PACKAGE int __fastcall dxCharCount(const System::UnicodeString S);
extern PACKAGE bool __fastcall dxIsUnicodeStream(System::Classes::TStream* AStream);
extern PACKAGE int __fastcall dxCompareValues(int A, int B)/* overload */;
extern PACKAGE int __fastcall dxCompareValues(void * A, void * B)/* overload */;
extern PACKAGE System::UnicodeString __fastcall dxGetBuildNumberAsString(void);
extern PACKAGE System::UnicodeString __fastcall dxGetShortBuildNumberAsString(void);
extern PACKAGE void __fastcall dxFactorizeBuildNumber(unsigned ABuildNumber, /* out */ int &AMajor, /* out */ int &AMinor, /* out */ int &ABuild);
extern PACKAGE void __fastcall dxWriteStreamType(System::Classes::TStream* AStream);
extern PACKAGE bool __fastcall dxCharInSet(System::WideChar C, const TdxAnsiCharSet &ACharSet);
extern PACKAGE int __fastcall dxStringSize(const System::UnicodeString S);
extern PACKAGE BOOL __fastcall dxGetStringTypeA(unsigned Locale, unsigned dwInfoType, const char * lpSrcStr, int cchSrc, void *lpCharType);
extern PACKAGE BOOL __fastcall dxGetStringTypeW(unsigned dwInfoType, const System::WideChar * lpSrcStr, int cchSrc, void *lpCharType);
extern PACKAGE TdxResourceStringsRepository* __fastcall dxResourceStringsRepository(void);
extern PACKAGE System::UnicodeString __fastcall dxAnsiStringToString(const System::AnsiString S, int ACodePage = 0x0);
extern PACKAGE System::AnsiString __fastcall dxStringToAnsiString(const System::UnicodeString S, int ACodePage = 0x0);
extern PACKAGE System::UnicodeString __fastcall dxVariantToString(const System::Variant &V);
extern PACKAGE System::AnsiString __fastcall dxVariantToAnsiString(const System::Variant &V);
extern PACKAGE System::WideString __fastcall dxVariantToWideString(const System::Variant &V);
extern PACKAGE bool __fastcall dxAnsiIsAlpha(char Ch);
extern PACKAGE bool __fastcall dxCharIsAlpha(System::WideChar Ch);
extern PACKAGE bool __fastcall dxWideIsAlpha(System::WideChar Ch);
extern PACKAGE bool __fastcall dxAnsiIsNumeric(char Ch);
extern PACKAGE bool __fastcall dxCharIsNumeric(System::WideChar Ch);
extern PACKAGE bool __fastcall dxWideIsNumeric(System::WideChar Ch);
extern PACKAGE int __fastcall dxStrComp(const char * Str1, const char * Str2);
extern PACKAGE char * __fastcall dxStrCopy(char * ADest, const char * ASource);
extern PACKAGE char * __fastcall dxStrLCopy(char * ADest, const char * ASource, unsigned AMaxLen);
extern PACKAGE unsigned __fastcall dxStrLen(const char * AStr);
extern PACKAGE int __fastcall dxGetCodePageFromCharset(int ACharset);
extern PACKAGE System::WideString __fastcall dxAnsiStringToWideString(const System::AnsiString ASource, unsigned ACodePage = (unsigned)(0x0), int ASrcLength = 0xffffffff);
extern PACKAGE System::AnsiString __fastcall dxWideStringToAnsiString(const System::WideString ASource, unsigned ACodePage = (unsigned)(0x0), int ASrcLength = 0xffffffff);
extern PACKAGE System::WideString __fastcall dxStringToWideString(const System::UnicodeString S, int ACodePage = 0x0);
extern PACKAGE System::UnicodeString __fastcall dxWideStringToString(const System::WideString S, int ACodePage = 0x0);
extern PACKAGE System::UnicodeString __fastcall dxConcatenateStrings(System::WideChar * const *AStrings, const int AStrings_Size);
extern PACKAGE void __fastcall dxStringToBytes(const System::UnicodeString S, void *Buf);
extern PACKAGE System::AnsiString __fastcall dxUTF8StringToAnsiString(const System::UTF8String S);
extern PACKAGE System::UnicodeString __fastcall dxUTF8StringToString(const System::UTF8String S);
extern PACKAGE System::WideString __fastcall dxUTF8StringToWideString(const System::UTF8String S);
extern PACKAGE System::UTF8String __fastcall dxAnsiStringToUTF8String(const System::AnsiString S);
extern PACKAGE System::UTF8String __fastcall dxStringToUTF8String(const System::UnicodeString S);
extern PACKAGE System::UTF8String __fastcall dxWideStringToUTF8String(const System::WideString S);
extern PACKAGE void __fastcall dxWriteStr(System::Classes::TStream* Stream, const System::UnicodeString S);
extern PACKAGE void __fastcall dxWriteStandardEncodingSignature(System::Classes::TStream* AStream);
extern PACKAGE System::UnicodeString __fastcall dxReadStr(System::Classes::TStream* Stream, bool AIsUnicode);
extern PACKAGE void __fastcall cxZeroMemory(void * ADestination, int ACount);
extern PACKAGE void * __fastcall cxAllocMem(unsigned Size);
extern PACKAGE void __fastcall cxFreeMem(void * P);
extern PACKAGE void __fastcall dxFillChar(void *ADest, int Count, const System::WideChar APattern);
extern PACKAGE void __fastcall dxFreeAndNil(void *AObject);
extern PACKAGE void __fastcall dxAppendList(System::Classes::TList* ASource, System::Classes::TList* ADestination);
extern PACKAGE void __fastcall dxCopyList(System::Classes::TList* ASource, System::Classes::TList* ADestination);
extern PACKAGE void __fastcall cxCopyData(void * ASource, void * ADestination, int ACount)/* overload */;
extern PACKAGE void __fastcall cxCopyData(void * ASource, void * ADestination, int ASourceOffSet, int ADestinationOffSet, int ACount)/* overload */;
extern PACKAGE System::WordBool __fastcall ReadBoolean(void * ASource, int AOffset = 0x0);
extern PACKAGE System::Byte __fastcall ReadByte(void * ASource, int AOffset = 0x0);
extern PACKAGE int __fastcall ReadInteger(void * ASource, int AOffset = 0x0);
extern PACKAGE void * __fastcall ReadPointer(void * ASource);
extern PACKAGE System::Word __fastcall ReadWord(void * ASource, int AOffset = 0x0);
extern PACKAGE TdxUnitsLoader* __fastcall dxUnitsLoader(void);
extern PACKAGE void __stdcall dxInitialize(void);
extern PACKAGE void __stdcall dxFinalize(void);
}	/* namespace Dxcore */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCORE)
using namespace Dxcore;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcoreHPP
