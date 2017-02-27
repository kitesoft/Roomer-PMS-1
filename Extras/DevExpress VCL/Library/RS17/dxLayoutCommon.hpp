// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutCommon.pas' rev: 24.00 (Win32)

#ifndef DxlayoutcommonHPP
#define DxlayoutcommonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutcommon
{
//-- type declarations -------------------------------------------------------
enum TdxLayoutSide : unsigned char { sdLeft, sdRight, sdTop, sdBottom };

__interface IdxLayoutComponent;
typedef System::DelphiInterface<IdxLayoutComponent> _di_IdxLayoutComponent;
__interface  INTERFACE_UUID("{F31C9078-5732-44D8-9347-3EA7B93837E3}") IdxLayoutComponent  : public System::IInterface 
{
	
public:
	virtual void __stdcall SelectionChanged(void) = 0 ;
};

__interface IdxLayoutDesignTimeHelper;
typedef System::DelphiInterface<IdxLayoutDesignTimeHelper> _di_IdxLayoutDesignTimeHelper;
__interface  INTERFACE_UUID("{9A1C2CD3-7CD9-4A7D-8E51-9305994B2F2E}") IdxLayoutDesignTimeHelper  : public System::IInterface 
{
	
public:
	virtual bool __fastcall IsToolSelected(void) = 0 ;
};

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE _di_IdxLayoutDesignTimeHelper dxLayoutDesignTimeHelper;
extern PACKAGE System::Uitypes::TColor __fastcall GetHotTrackColor(void);
extern PACKAGE System::UnicodeString __fastcall GetPlainString(const System::UnicodeString S);
extern PACKAGE void __fastcall SetComponentName(System::Classes::TComponent* AComponent, const System::UnicodeString ABaseName, bool AIsDesigning, bool AIsLoading);
}	/* namespace Dxlayoutcommon */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTCOMMON)
using namespace Dxlayoutcommon;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutcommonHPP
