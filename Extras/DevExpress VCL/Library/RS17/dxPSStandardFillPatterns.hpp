// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSStandardFillPatterns.pas' rev: 24.00 (Win32)

#ifndef DxpsstandardfillpatternsHPP
#define DxpsstandardfillpatternsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <dxPSFillPatterns.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsstandardfillpatterns
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSHorizontalFillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSHorizontalFillPattern : public Dxpsfillpatterns::TdxPSFillPattern
{
	typedef Dxpsfillpatterns::TdxPSFillPattern inherited;
	
public:
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSHorizontalFillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSHorizontalFillPattern(void) : Dxpsfillpatterns::TdxPSFillPattern() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSVerticalFillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSVerticalFillPattern : public Dxpsfillpatterns::TdxPSFillPattern
{
	typedef Dxpsfillpatterns::TdxPSFillPattern inherited;
	
public:
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSVerticalFillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSVerticalFillPattern(void) : Dxpsfillpatterns::TdxPSFillPattern() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSFDiagonalFillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFDiagonalFillPattern : public Dxpsfillpatterns::TdxPSFillPattern
{
	typedef Dxpsfillpatterns::TdxPSFillPattern inherited;
	
public:
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSFDiagonalFillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSFDiagonalFillPattern(void) : Dxpsfillpatterns::TdxPSFillPattern() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSBDiagonalFillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSBDiagonalFillPattern : public Dxpsfillpatterns::TdxPSFillPattern
{
	typedef Dxpsfillpatterns::TdxPSFillPattern inherited;
	
public:
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSBDiagonalFillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSBDiagonalFillPattern(void) : Dxpsfillpatterns::TdxPSFillPattern() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSCrossFillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSCrossFillPattern : public Dxpsfillpatterns::TdxPSFillPattern
{
	typedef Dxpsfillpatterns::TdxPSFillPattern inherited;
	
public:
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSCrossFillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSCrossFillPattern(void) : Dxpsfillpatterns::TdxPSFillPattern() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSDiagCrossFillPattern;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSDiagCrossFillPattern : public Dxpsfillpatterns::TdxPSFillPattern
{
	typedef Dxpsfillpatterns::TdxPSFillPattern inherited;
	
public:
	__classmethod virtual void __fastcall Bits(System::Word *APattern);
	__classmethod virtual System::UnicodeString __fastcall Name();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSDiagCrossFillPattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSDiagCrossFillPattern(void) : Dxpsfillpatterns::TdxPSFillPattern() { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsstandardfillpatterns */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSSTANDARDFILLPATTERNS)
using namespace Dxpsstandardfillpatterns;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsstandardfillpatternsHPP
