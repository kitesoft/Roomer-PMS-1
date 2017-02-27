// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxEditRegisteredRepositoryItems.pas' rev: 24.00 (Win32)

#ifndef CxeditregisteredrepositoryitemsHPP
#define CxeditregisteredrepositoryitemsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxeditregisteredrepositoryitems
{
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TcxEditRegisteredRepositoryItemsData
{
public:
	int DataType;
	int Version;
	Cxedit::TcxEditRepositoryItem* RepositoryItem;
};


typedef System::DynamicArray<TcxEditRegisteredRepositoryItemsData> TcxEditRegisteredRepositoryItemsDataArray;

class DELPHICLASS TcxEditRegisteredRepositoryItems;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxEditRegisteredRepositoryItems : public Dxcoreclasses::TcxInterfacedPersistent
{
	typedef Dxcoreclasses::TcxInterfacedPersistent inherited;
	
private:
	bool FDestroying;
	TcxEditRegisteredRepositoryItemsDataArray FDefaultItems;
	TcxEditRegisteredRepositoryItemsDataArray FItems;
	bool __fastcall Find(const TcxEditRegisteredRepositoryItemsDataArray AItems, int ADataType, int AVersion, bool AFindItemWithMaxVersion, /* out */ int &AIndex);
	int __fastcall GetCount(void);
	int __fastcall GetDefaultCount(void);
	
protected:
	virtual void __fastcall ItemRemoved(Cxedit::TcxEditRepositoryItem* Sender);
	virtual void __fastcall PropertiesChanged(Cxedit::TcxEditRepositoryItem* Sender);
	virtual int __fastcall Add(TcxEditRegisteredRepositoryItemsDataArray &AItems, int ADataType, int AVersion, Cxedit::TcxEditRepositoryItem* ARepositoryItem);
	virtual void __fastcall Changed(void);
	void __fastcall Clear(void);
	void __fastcall Delete(TcxEditRegisteredRepositoryItemsDataArray &AItems, int AIndex);
	bool __fastcall FindIndexForInsertion(const TcxEditRegisteredRepositoryItemsDataArray AItems, int ADataType, int AVersion, /* out */ int &AIndex);
	int __fastcall FindItemWithMaxVersion(const TcxEditRegisteredRepositoryItemsDataArray AItems, int ADataType);
	__property int Count = {read=GetCount, nodefault};
	__property int DefaultCount = {read=GetDefaultCount, nodefault};
	__property bool Destroying = {read=FDestroying, write=FDestroying, nodefault};
	
public:
	__fastcall virtual ~TcxEditRegisteredRepositoryItems(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall GetDefaultItem(void);
	virtual Cxedit::TcxEditRepositoryItem* __fastcall GetItem(int ADataType);
	virtual void __fastcall RegisterDefaultItem(int AVersion, Cxedit::TcxEditRepositoryItem* ARepositoryItem);
	virtual void __fastcall RegisterItem(int ADataType, int AVersion, Cxedit::TcxEditRepositoryItem* ARepositoryItem);
	virtual void __fastcall UnregisterDefaultItem(int AVersion);
	virtual void __fastcall UnregisterItem(int ADataType, int AVersion);
public:
	/* TcxInterfacedPersistent.Create */ inline __fastcall virtual TcxEditRegisteredRepositoryItems(System::Classes::TPersistent* AOwner) : Dxcoreclasses::TcxInterfacedPersistent(AOwner) { }
	
private:
	void *__IcxEditRepositoryItemListener;	/* Cxedit::IcxEditRepositoryItemListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {4E27D642-022B-4CD2-AB96-64C7CF9B3299}
	operator Cxedit::_di_IcxEditRepositoryItemListener()
	{
		Cxedit::_di_IcxEditRepositoryItemListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxedit::IcxEditRepositoryItemListener*(void) { return (Cxedit::IcxEditRepositoryItemListener*)&__IcxEditRepositoryItemListener; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IcxEditRepositoryItemListener; }
	#endif
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxEditRegisteredItemsStandardVersion = System::Int8(-1);
static const int cxEditRegisteredItemsDefaultVersion = int(2147483647);
}	/* namespace Cxeditregisteredrepositoryitems */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXEDITREGISTEREDREPOSITORYITEMS)
using namespace Cxeditregisteredrepositoryitems;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxeditregisteredrepositoryitemsHPP
