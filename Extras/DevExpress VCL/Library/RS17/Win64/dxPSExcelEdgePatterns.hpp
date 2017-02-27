// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSExcelEdgePatterns.pas' rev: 24.00 (Win64)

#ifndef DxpsexceledgepatternsHPP
#define DxpsexceledgepatternsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSEdgePatterns.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsexceledgepatterns
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSMediumSolidEdgePattern;
class PASCALIMPLEMENTATION TdxPSMediumSolidEdgePattern : public Dxpsedgepatterns::TdxPSSolidEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSSolidEdgePattern inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSMediumSolidEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSMediumSolidEdgePattern(void) : Dxpsedgepatterns::TdxPSSolidEdgePattern() { }
	
};


class DELPHICLASS TdxPSThickSolidEdgePattern;
class PASCALIMPLEMENTATION TdxPSThickSolidEdgePattern : public Dxpsedgepatterns::TdxPSSolidEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSSolidEdgePattern inherited;
	
public:
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSThickSolidEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSThickSolidEdgePattern(void) : Dxpsedgepatterns::TdxPSSolidEdgePattern() { }
	
};


class DELPHICLASS TdxPSDottedEdgePattern;
class PASCALIMPLEMENTATION TdxPSDottedEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSDottedEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSDottedEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSDashedEdgePattern;
class PASCALIMPLEMENTATION TdxPSDashedEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSDashedEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSDashedEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSDashDotDotEdgePattern;
class PASCALIMPLEMENTATION TdxPSDashDotDotEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSDashDotDotEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSDashDotDotEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSDashDotEdgePattern;
class PASCALIMPLEMENTATION TdxPSDashDotEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSDashDotEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSDashDotEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSSlantedDashDotEdgePattern;
class PASCALIMPLEMENTATION TdxPSSlantedDashDotEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSSlantedDashDotEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSSlantedDashDotEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSMediumDashDotDotEdgePattern;
class PASCALIMPLEMENTATION TdxPSMediumDashDotDotEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSMediumDashDotDotEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSMediumDashDotDotEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSHairEdgePattern;
class PASCALIMPLEMENTATION TdxPSHairEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSHairEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSHairEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSMediumDashDotEdgePattern;
class PASCALIMPLEMENTATION TdxPSMediumDashDotEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSMediumDashDotEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSMediumDashDotEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSMediumDashedEdgePattern;
class PASCALIMPLEMENTATION TdxPSMediumDashedEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSMediumDashedEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSMediumDashedEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


class DELPHICLASS TdxPSDoubleLineSolidEdgePattern;
class PASCALIMPLEMENTATION TdxPSDoubleLineSolidEdgePattern : public Dxpsedgepatterns::TdxPSEdgePattern
{
	typedef Dxpsedgepatterns::TdxPSEdgePattern inherited;
	
public:
	__classmethod virtual unsigned __fastcall Bits(int Index);
	__classmethod virtual System::UnicodeString __fastcall Name();
	__classmethod virtual int __fastcall SignificantBitCount();
	__classmethod virtual int __fastcall Thickness();
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxPSDoubleLineSolidEdgePattern(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPSDoubleLineSolidEdgePattern(void) : Dxpsedgepatterns::TdxPSEdgePattern() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsexceledgepatterns */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSEXCELEDGEPATTERNS)
using namespace Dxpsexceledgepatterns;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsexceledgepatternsHPP
