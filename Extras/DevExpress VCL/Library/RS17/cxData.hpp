// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxData.pas' rev: 24.00 (Win32)

#ifndef CxdataHPP
#define CxdataHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxdata
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxDataController;
class PASCALIMPLEMENTATION TcxDataController : public Cxcustomdata::TcxCustomDataController
{
	typedef Cxcustomdata::TcxCustomDataController inherited;
	
public:
	__fastcall virtual TcxDataController(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxDataController(void);
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxdata */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXDATA)
using namespace Cxdata;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxdataHPP
