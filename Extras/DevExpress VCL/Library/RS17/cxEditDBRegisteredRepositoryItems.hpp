// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditDBRegisteredRepositoryItems.pas' rev: 24.00 (Win32)

#ifndef CxeditdbregisteredrepositoryitemsHPP
#define CxeditdbregisteredrepositoryitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxDBEditRepository.hpp>	// Pascal unit
#include <cxEditRegisteredRepositoryItems.hpp>	// Pascal unit
#include <cxEditRepositoryItems.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditdbregisteredrepositoryitems
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxEditDBRegisteredRepositoryItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditDBRegisteredRepositoryItems : public Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItems
{
	typedef Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItems inherited;
	
private:
	Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItemsDataArray FCurrencyItems;
	Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItemsDataArray FLookupItems;
	int __fastcall GetCurrencyCount(void);
	int __fastcall GetLookupCount(void);
	
protected:
	virtual void __fastcall ItemRemoved(Cxedit::TcxEditRepositoryItem* Sender);
	HIDESBASE int __fastcall Add(Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItemsDataArray &AItems, Data::Db::TFieldType AFieldType, int AVersion, Cxedit::TcxEditRepositoryItem* ARepositoryItem);
	HIDESBASE void __fastcall Clear(void);
	__property int CurrencyCount = {read=GetCurrencyCount, nodefault};
	__property int LookupCount = {read=GetLookupCount, nodefault};
	
public:
	__fastcall virtual ~TcxEditDBRegisteredRepositoryItems(void);
	Cxedit::TcxEditRepositoryItem* __fastcall GetCurrencyItem(void);
	HIDESBASE Cxedit::TcxEditRepositoryItem* __fastcall GetItem(Data::Db::TFieldType AFieldType);
	Cxedit::TcxEditRepositoryItem* __fastcall GetItemByField(Data::Db::TField* AField);
	Cxedit::TcxEditRepositoryItem* __fastcall GetLookupItem(void);
	HIDESBASE void __fastcall RegisterItem(Data::Db::TFieldType AFieldType, int AVersion, Cxedit::TcxEditRepositoryItem* ARepositoryItem);
	void __fastcall RegisterCurrencyItem(int AVersion, Cxedit::TcxEditRepositoryItem* ARepositoryItem);
	void __fastcall RegisterLookupItem(int AVersion, Cxedit::TcxEditRepositoryItem* ARepositoryItem);
	HIDESBASE void __fastcall UnregisterItem(Data::Db::TFieldType AFieldType, int AVersion);
	void __fastcall UnregisterCurrencyItem(int AVersion);
	void __fastcall UnregisterLookupItem(int AVersion);
public:
	/* TcxInterfacedPersistent.Create */ inline __fastcall virtual TcxEditDBRegisteredRepositoryItems(System::Classes::TPersistent* AOwner) : Cxeditregisteredrepositoryitems::TcxEditRegisteredRepositoryItems(AOwner) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxEditDBRegisteredRepositoryItems* __fastcall GetDefaultEditDBRepositoryItems(void);
}	/* namespace Cxeditdbregisteredrepositoryitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITDBREGISTEREDREPOSITORYITEMS)
using namespace Cxeditdbregisteredrepositoryitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditdbregisteredrepositoryitemsHPP
