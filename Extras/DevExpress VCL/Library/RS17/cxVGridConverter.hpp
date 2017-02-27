// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxVGridConverter.pas' rev: 24.00 (Win32)

#ifndef CxvgridconverterHPP
#define CxvgridconverterHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <cxConverterFactory.hpp>	// Pascal unit
#include <cxVGrid.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxCustomConverter.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxvgridconverter
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxCustomVerticalGridConverterClass;

class DELPHICLASS TcxStylesAccessor;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxStylesAccessor : public Cxstyles::TcxStyles
{
	typedef Cxstyles::TcxStyles inherited;
	
public:
	/* TcxCustomStyles.Create */ inline __fastcall virtual TcxStylesAccessor(System::Classes::TPersistent* AOwner) : Cxstyles::TcxStyles(AOwner) { }
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxStylesAccessor(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxCustomVerticalGridConverter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomVerticalGridConverter : public Cxconverterfactory::TcxCustomConverterWithStyles
{
	typedef Cxconverterfactory::TcxCustomConverterWithStyles inherited;
	
private:
	void __fastcall ClearStyles(void);
	void __fastcall ClearVerticalGrid(void);
	Cxvgrid::TcxCustomVerticalGrid* __fastcall GetDestination(void);
	
protected:
	virtual void __fastcall DoImport(void);
	virtual void __fastcall DoRealImport(void);
	void __fastcall SetVerticalGridRowUniqueName(Cxvgrid::TcxCustomVerticalGrid* AVerticalGrid, Cxvgrid::TcxCustomRow* ARow);
	
public:
	__property Cxvgrid::TcxCustomVerticalGrid* Destination = {read=GetDestination};
public:
	/* TcxCustomConverter.Create */ inline __fastcall virtual TcxCustomVerticalGridConverter(System::TObject* ADestination) : Cxconverterfactory::TcxCustomConverterWithStyles(ADestination) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxCustomVerticalGridConverter(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
#define cxVGGroupConverterName L"VerticalGrid Converters"
#define cxDBVGGroupConverterName L"DBVerticalGrid Converters"
#define cxRTTIVGGroupConverterName L"RTTI Inspector Converters"
}	/* namespace Cxvgridconverter */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXVGRIDCONVERTER)
using namespace Cxvgridconverter;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxvgridconverterHPP
