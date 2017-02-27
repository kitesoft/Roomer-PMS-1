// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditDataRegisteredRepositoryItems.pas' rev: 24.00 (Win64)

#ifndef CxeditdataregisteredrepositoryitemsHPP
#define CxeditdataregisteredrepositoryitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxEditRegisteredRepositoryItems.hpp>	// Pascal unit
#include <cxEditRepositoryItems.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditdataregisteredrepositoryitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxEditDataRegisteredRepositoryItems;
class PASCALIMPLEMENTATION TcxEditDataRegisteredRepositoryItems : public Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItems
{
	typedef Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItems inherited;
	
public:
	HIDESBASE Cxedit::TcxEditRepositoryItem* __fastcall GetItem(Cxdatastorage::TcxValueTypeClass AValueTypeClass);
	HIDESBASE void __fastcall RegisterItem(Cxdatastorage::TcxValueTypeClass AValueTypeClass, int AVersion, Cxedit::TcxEditRepositoryItem* ARepositoryItem);
	HIDESBASE void __fastcall UnregisterItem(Cxdatastorage::TcxValueTypeClass AValueTypeClass, int AVersion);
public:
	/* TcxEditRegisteredRepositoryItems.Destroy */ inline __fastcall virtual ~TcxEditDataRegisteredRepositoryItems(void) { }
	
public:
	/* TcxInterfacedPersistent.Create */ inline __fastcall virtual TcxEditDataRegisteredRepositoryItems(System::Classes::TPersistent* AOwner) : Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItems(AOwner) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxEditDataRegisteredRepositoryItems* __fastcall GetDefaultEditDataRepositoryItems(void);
}	/* namespace Cxeditdataregisteredrepositoryitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITDATAREGISTEREDREPOSITORYITEMS)
using namespace Cxeditdataregisteredrepositoryitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditdataregisteredrepositoryitemsHPP
