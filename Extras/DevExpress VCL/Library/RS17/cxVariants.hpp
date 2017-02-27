// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVariants.pas' rev: 24.00 (Win32)

#ifndef CxvariantsHPP
#define CxvariantsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvariants
{
//-- type declarations -------------------------------------------------------
typedef __int64 LargeInt;

typedef System::DynamicArray<System::Variant> TVariantArray;

class DELPHICLASS TcxFiler;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxFiler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsUnicode;
	System::Classes::TStream* FStream;
	
public:
	__fastcall TcxFiler(System::Classes::TStream* AStream);
	__property System::Classes::TStream* Stream = {read=FStream};
	__property bool IsUnicode = {read=FIsUnicode, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxFiler(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxReader;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxReader : public TcxFiler
{
	typedef TcxFiler inherited;
	
public:
	System::AnsiString __fastcall ReadAnsiString(void);
	bool __fastcall ReadBoolean(void);
	System::Byte __fastcall ReadByte(void);
	unsigned __fastcall ReadCardinal(void);
	System::WideChar __fastcall ReadChar(void);
	System::Currency __fastcall ReadCurrency(void);
	System::TDateTime __fastcall ReadDateTime(void);
	System::Extended __fastcall ReadFloat(void);
	int __fastcall ReadInteger(void);
	__int64 __fastcall ReadLargeInt(void);
	System::Int8 __fastcall ReadShortInt(void);
	float __fastcall ReadSingle(void);
	short __fastcall ReadSmallInt(void);
	System::UnicodeString __fastcall ReadString_(void);
	System::Variant __fastcall ReadVariant(void);
	System::WideString __fastcall ReadWideString(void);
	System::Word __fastcall ReadWord(void);
public:
	/* TcxFiler.Create */ inline __fastcall TcxReader(System::Classes::TStream* AStream) : TcxFiler(AStream) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxReader(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxWriter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxWriter : public TcxFiler
{
	typedef TcxFiler inherited;
	
public:
	void __fastcall WriteAnsiString(const System::AnsiString S);
	void __fastcall WriteBoolean(bool AValue);
	void __fastcall WriteByte(System::Byte AValue);
	void __fastcall WriteCardinal(unsigned AValue);
	void __fastcall WriteChar(System::WideChar AValue);
	void __fastcall WriteCurrency(System::Currency AValue);
	void __fastcall WriteDateTime(System::TDateTime AValue);
	void __fastcall WriteFloat(System::Extended AValue);
	void __fastcall WriteInteger(int AValue);
	void __fastcall WriteLargeInt(__int64 AValue);
	void __fastcall WriteShortInt(System::Int8 AValue);
	void __fastcall WriteSingle(float AValue);
	void __fastcall WriteSmallInt(short AValue);
	void __fastcall WriteVariant(const System::Variant &AValue);
	void __fastcall WriteWideString(const System::WideString S);
	void __fastcall WriteWord(System::Word AValue);
public:
	/* TcxFiler.Create */ inline __fastcall TcxWriter(System::Classes::TStream* AStream) : TcxFiler(AStream) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxWriter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE int __fastcall VarCompare(const System::Variant &V1, const System::Variant &V2);
extern PACKAGE bool __fastcall VarEquals(const System::Variant &V1, const System::Variant &V2);
extern PACKAGE bool __fastcall VarEqualsExact(const System::Variant &V1, const System::Variant &V2);
extern PACKAGE bool __fastcall VarEqualsSoft(const System::Variant &V1, const System::Variant &V2);
extern PACKAGE int __fastcall VarIndex(const TVariantArray AList, const System::Variant &AValue);
extern PACKAGE bool __fastcall VarIsDate(const System::Variant &AValue);
extern PACKAGE bool __fastcall VarIsNumericEx(const System::Variant &AValue);
extern PACKAGE bool __fastcall VarIsSoftNull(const System::Variant &AValue);
extern PACKAGE System::UnicodeString __fastcall VarToStrEx(const System::Variant &V);
extern PACKAGE bool __fastcall VarTypeIsCurrency(System::Word AVarType);
extern PACKAGE System::Variant __fastcall VarBetweenArrayCreate(const System::Variant &AValue1, const System::Variant &AValue2);
extern PACKAGE System::Variant __fastcall VarListArrayCreate(const System::Variant &AValue);
extern PACKAGE void __fastcall VarListArrayAddValue(System::Variant &Value, const System::Variant &AValue);
extern PACKAGE System::AnsiString __fastcall ReadAnsiStringFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadAnsiStringProc(System::Classes::TStream* AStream, System::AnsiString &S);
extern PACKAGE void __fastcall WriteAnsiStringProc(System::Classes::TStream* AStream, const System::AnsiString S);
extern PACKAGE System::WideString __fastcall ReadWideStringFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadWideStringProc(System::Classes::TStream* AStream, System::WideString &S);
extern PACKAGE void __fastcall WriteWideStringProc(System::Classes::TStream* AStream, const System::WideString S);
extern PACKAGE System::Variant __fastcall ReadVariantFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadVariantProc(System::Classes::TStream* AStream, System::Variant &Value);
extern PACKAGE void __fastcall WriteVariantProc(System::Classes::TStream* AStream, const System::Variant &AValue);
extern PACKAGE bool __fastcall ReadBooleanFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadBooleanProc(System::Classes::TStream* AStream, bool &Value);
extern PACKAGE void __fastcall WriteBooleanProc(System::Classes::TStream* AStream, bool AValue);
extern PACKAGE System::WideChar __fastcall ReadCharFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadCharProc(System::Classes::TStream* AStream, System::WideChar &Value);
extern PACKAGE void __fastcall WriteCharProc(System::Classes::TStream* AStream, System::WideChar AValue);
extern PACKAGE System::Extended __fastcall ReadFloatFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadFloatProc(System::Classes::TStream* AStream, System::Extended &Value);
extern PACKAGE void __fastcall WriteFloatProc(System::Classes::TStream* AStream, System::Extended AValue);
extern PACKAGE float __fastcall ReadSingleFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadSingleProc(System::Classes::TStream* AStream, float &Value);
extern PACKAGE void __fastcall WriteSingleProc(System::Classes::TStream* AStream, float AValue);
extern PACKAGE System::Currency __fastcall ReadCurrencyFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadCurrencyProc(System::Classes::TStream* AStream, System::Currency &Value);
extern PACKAGE void __fastcall WriteCurrencyProc(System::Classes::TStream* AStream, System::Currency AValue);
extern PACKAGE System::TDateTime __fastcall ReadDateTimeFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadDateTimeProc(System::Classes::TStream* AStream, System::TDateTime &Value);
extern PACKAGE void __fastcall WriteDateTimeProc(System::Classes::TStream* AStream, System::TDateTime AValue);
extern PACKAGE int __fastcall ReadIntegerFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadIntegerProc(System::Classes::TStream* AStream, int &Value);
extern PACKAGE void __fastcall WriteIntegerProc(System::Classes::TStream* AStream, int AValue);
extern PACKAGE __int64 __fastcall ReadLargeIntFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadLargeIntProc(System::Classes::TStream* AStream, __int64 &Value);
extern PACKAGE void __fastcall WriteLargeIntProc(System::Classes::TStream* AStream, __int64 AValue);
extern PACKAGE System::Byte __fastcall ReadByteFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadByteProc(System::Classes::TStream* AStream, System::Byte &Value);
extern PACKAGE void __fastcall WriteByteProc(System::Classes::TStream* AStream, System::Byte AValue);
extern PACKAGE short __fastcall ReadSmallIntFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadSmallIntProc(System::Classes::TStream* AStream, short &Value);
extern PACKAGE void __fastcall WriteSmallIntProc(System::Classes::TStream* AStream, short AValue);
extern PACKAGE unsigned __fastcall ReadCardinalFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadCardinalProc(System::Classes::TStream* AStream, unsigned &Value);
extern PACKAGE void __fastcall WriteCardinalProc(System::Classes::TStream* AStream, unsigned AValue);
extern PACKAGE System::Int8 __fastcall ReadShortIntFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadShortIntProc(System::Classes::TStream* AStream, System::Int8 &Value);
extern PACKAGE void __fastcall WriteShortIntProc(System::Classes::TStream* AStream, System::Int8 AValue);
extern PACKAGE System::Word __fastcall ReadWordFunc(System::Classes::TStream* AStream);
extern PACKAGE void __fastcall ReadWordProc(System::Classes::TStream* AStream, System::Word &Value);
extern PACKAGE void __fastcall WriteWordProc(System::Classes::TStream* AStream, System::Word AValue);
extern PACKAGE unsigned __fastcall GetVariantHash(const System::Variant &V);
}	/* namespace Cxvariants */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVARIANTS)
using namespace Cxvariants;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvariantsHPP
