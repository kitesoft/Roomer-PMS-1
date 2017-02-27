// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarGroupItems.pas' rev: 24.00 (Win64)

#ifndef DxnavbargroupitemsHPP
#define DxnavbargroupitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbargroupitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarSeparator;
class PASCALIMPLEMENTATION TdxNavBarSeparator : public Dxnavbarcollns::TdxNavBarItem
{
	typedef Dxnavbarcollns::TdxNavBarItem inherited;
	
protected:
	virtual bool __fastcall CanSelect(void);
	__classmethod virtual Dxnavbarcollns::TdxNavBarCustomGroupItemCalculatorClass __fastcall GetCalculatorClass();
	
public:
	virtual void __fastcall Draw(const void *APainter, const void *ALinkViewInfo);
public:
	/* TdxNavBarItem.Create */ inline __fastcall virtual TdxNavBarSeparator(System::Classes::TComponent* AOwner) : Dxnavbarcollns::TdxNavBarItem(AOwner) { }
	/* TdxNavBarItem.Destroy */ inline __fastcall virtual ~TdxNavBarSeparator(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxnavbargroupitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARGROUPITEMS)
using namespace Dxnavbargroupitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbargroupitemsHPP
