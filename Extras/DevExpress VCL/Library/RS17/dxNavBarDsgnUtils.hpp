// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarDsgnUtils.pas' rev: 24.00 (Win32)

#ifndef DxnavbardsgnutilsHPP
#define DxnavbardsgnutilsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <ComponentDesigner.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbardsgnutils
{
//-- type declarations -------------------------------------------------------
typedef Designintf::_di_IDesigner IDelphiDesigner;

typedef Componentdesigner::_di_IDesignEnvironment IDelphiIDE;

typedef Componentdesigner::_di_IComponentDesigner ILibrary;

typedef System::Classes::TPersistent IPersistent;

typedef System::Classes::TComponent IComponent;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::Classes::TComponent* __fastcall MakeIComponent(System::Classes::TComponent* Component);
extern PACKAGE System::Classes::TPersistent* __fastcall MakeIPersistent(System::Classes::TPersistent* Persistent);
extern PACKAGE System::Classes::TComponent* __fastcall TryExtractComponent(System::Classes::TPersistent* Component);
extern PACKAGE System::Classes::TPersistent* __fastcall TryExtractPersistent(System::Classes::TPersistent* Persistent);
}	/* namespace Dxnavbardsgnutils */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARDSGNUTILS)
using namespace Dxnavbardsgnutils;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbardsgnutilsHPP
