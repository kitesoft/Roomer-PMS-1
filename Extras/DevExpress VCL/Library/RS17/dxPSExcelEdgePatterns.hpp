// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSExcelEdgePatterns.pas' rev: 24.00 (Win32)

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
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSThickSolidEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSDottedEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSDashedEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSDashDotDotEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSDashDotEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSSlantedDashDotEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSMediumDashDotDotEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSHairEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSMediumDashDotEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSMediumDashedEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

class DELPHICLASS TdxPSDoubleLineSolidEdgePattern;
#pragma pack(push,4)
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

#pragma pack(pop)

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
