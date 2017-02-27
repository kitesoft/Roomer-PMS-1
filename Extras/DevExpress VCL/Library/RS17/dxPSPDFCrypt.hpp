// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSPDFCrypt.pas' rev: 24.00 (Win32)

#ifndef DxpspdfcryptHPP
#define DxpspdfcryptHPP

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
#include <System.Math.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpspdfcrypt
{
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<System::Byte, 256> TdxRC4Key;

typedef System::StaticArray<System::Byte, 16> TdxMD5Byte16;

typedef System::StaticArray<System::Byte, 64> TdxMD5Byte64;

typedef TdxMD5Byte64 *PdxMD5Byte64;

typedef System::StaticArray<unsigned, 2> TdxMD5Int2;

typedef System::StaticArray<unsigned, 4> TdxMD5Int4;

typedef System::StaticArray<unsigned, 16> TdxMD5Int16;

typedef TdxMD5Int16 *PdxMD5Int16;

struct DECLSPEC_DRECORD TdxMD5Context
{
public:
	TdxMD5Int4 State;
	TdxMD5Int2 Count;
	TdxMD5Byte64 Buffer;
	unsigned BufferLen;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxMD5Init(TdxMD5Context &AContext);
extern PACKAGE void __fastcall dxMD5Update(TdxMD5Context &AContext, const System::AnsiString S)/* overload */;
extern PACKAGE void __fastcall dxMD5Update(TdxMD5Context &AContext, System::Sysutils::PByteArray AInput, int AInputLength)/* overload */;
extern PACKAGE void __fastcall dxMD5Final(TdxMD5Context &AContext, System::Byte *ADigits);
extern PACKAGE void __fastcall dxMD5Calc(System::Sysutils::PByteArray AInput, int AInputLength, System::Byte *ADigits);
extern PACKAGE System::UnicodeString __fastcall dxMD5CalcStr(const System::UnicodeString S);
extern PACKAGE bool __fastcall dxMD5Compare(System::Byte const *ADigits1, System::Byte const *ADigits2);
extern PACKAGE System::UnicodeString __fastcall dxMD5DigestToString(System::Byte const *ADigits);
extern PACKAGE void __fastcall dxRC4Initialize(/* out */ System::Byte *AKey, System::Sysutils::PByteArray APassword, int APasswordLength);
extern PACKAGE void __fastcall dxRC4Crypt(System::Byte *AKey, System::Sysutils::PByteArray AInData, System::Sysutils::PByteArray AOutData, int ADataSize);
}	/* namespace Dxpspdfcrypt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSPDFCRYPT)
using namespace Dxpspdfcrypt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpspdfcryptHPP
