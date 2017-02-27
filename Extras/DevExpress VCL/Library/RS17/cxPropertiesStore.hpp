// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPropertiesStore.pas' rev: 24.00 (Win32)

#ifndef CxpropertiesstoreHPP
#define CxpropertiesstoreHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxStorage.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpropertiesstore
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPropertiesStoreComponent;
class DELPHICLASS TcxCustomPropertiesStore;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPropertiesStoreComponent : public Cxclasses::TcxInterfacedCollectionItem
{
	typedef Cxclasses::TcxInterfacedCollectionItem inherited;
	
private:
	System::Classes::TComponent* FComponent;
	System::Classes::TStrings* FProperties;
	System::Classes::TStrings* FPropertiesEx;
	void __fastcall ExtractProperties(void);
	System::Classes::TPersistent* __fastcall ExtractPersistentAndPropertyName(System::Classes::TPersistent* AStartPersistent, const System::UnicodeString AStartName, System::UnicodeString &AResultName);
	System::Classes::TCollectionItem* __fastcall GetCollectionItemByName(System::Classes::TCollection* ACollection, const System::UnicodeString AName);
	System::Classes::TPersistent* __fastcall GetPersistentAndPropertyName(const System::UnicodeString AStartName, System::UnicodeString &AResultName);
	Cxstorage::TcxStorageModes __fastcall GetStorageModes(void);
	System::Classes::TComponent* __fastcall GetComponentByName(const System::UnicodeString AName);
	bool __fastcall GetUseInterfaceOnly(void);
	void __fastcall InternalGetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall InternalSetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	void __fastcall SetComponent(System::Classes::TComponent* const Value);
	void __fastcall SetProperties(System::Classes::TStrings* const Value);
	bool __fastcall TestClassProperty(const System::UnicodeString AName, System::TObject* AObject);
	void __fastcall AssignStorageProperties(Cxstorage::TcxStorage* AStorage);
	
protected:
	System::TObject* __fastcall CreateChild(const System::UnicodeString AObjectName, const System::UnicodeString AClassName);
	void __fastcall DeleteChild(const System::UnicodeString AObjectName, System::TObject* AObject);
	void __fastcall GetChildren(System::Classes::TStringList* AChildren);
	System::UnicodeString __fastcall GetObjectName(void);
	bool __fastcall GetProperties(System::Classes::TStrings* AProperties);
	void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	TcxCustomPropertiesStore* __fastcall GetPropertiesStore(void);
	
public:
	__fastcall virtual TcxPropertiesStoreComponent(System::Classes::TCollection* Collection);
	__fastcall virtual ~TcxPropertiesStoreComponent(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall RestoreFrom(Cxstorage::TcxStorage* AStorage, Cxstorage::TcxCustomReader* AReader);
	void __fastcall RestoreFromIniFile(const System::UnicodeString AStorageName);
	void __fastcall RestoreFromRegistry(const System::UnicodeString AStorageName);
	void __fastcall RestoreFromStream(System::Classes::TStream* const AStream);
	void __fastcall StoreTo(Cxstorage::TcxStorage* AStorage, Cxstorage::TcxCustomWriter* AWriter);
	void __fastcall StoreToIniFile(const System::UnicodeString AStorageName, const bool AReCreate);
	void __fastcall StoreToRegistry(const System::UnicodeString AStorageName, const bool AReCreate);
	void __fastcall StoreToStream(System::Classes::TStream* const AStream, const bool AReCreate);
	
__published:
	__property System::Classes::TComponent* Component = {read=FComponent, write=SetComponent};
	__property System::Classes::TStrings* Properties = {read=FProperties, write=SetProperties};
private:
	void *__IcxStoredParent;	/* Cxstorage::IcxStoredParent */
	void *__IcxStoredObject;	/* Cxstorage::IcxStoredObject */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {6AF48CD0-3A0B-4BEC-AC88-5D323432A686}
	operator Cxstorage::_di_IcxStoredParent()
	{
		Cxstorage::_di_IcxStoredParent intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredParent*(void) { return (Cxstorage::IcxStoredParent*)&__IcxStoredParent; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {79A05009-CAC3-47E8-B454-F6F3D91F495D}
	operator Cxstorage::_di_IcxStoredObject()
	{
		Cxstorage::_di_IcxStoredObject intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxstorage::IcxStoredObject*(void) { return (Cxstorage::IcxStoredObject*)&__IcxStoredObject; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TcxPropertiesStoreComponents;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPropertiesStoreComponents : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
public:
	TcxPropertiesStoreComponent* operator[](int Index) { return ComponentItems[Index]; }
	
private:
	TcxPropertiesStoreComponent* __fastcall GetComponentItem(int Index);
	void __fastcall SetComponentItem(int Index, TcxPropertiesStoreComponent* const Value);
	
protected:
	TcxCustomPropertiesStore* __fastcall GetPropertiesStore(void);
	void __fastcall RemoveComponent(System::Classes::TComponent* const AComponent);
	
public:
	HIDESBASE TcxPropertiesStoreComponent* __fastcall Add(void);
	bool __fastcall FindComponentItemByComponent(System::Classes::TComponent* AComponent, /* out */ TcxPropertiesStoreComponent* &AComponentItem);
	__property TcxPropertiesStoreComponent* ComponentItems[int Index] = {read=GetComponentItem, write=SetComponentItem/*, default*/};
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxPropertiesStoreComponents(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
public:
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxPropertiesStoreComponents(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TcxCustomPropertiesStore : public Cxclasses::TcxCustomComponent
{
	typedef Cxclasses::TcxCustomComponent inherited;
	
private:
	bool FActive;
	TcxPropertiesStoreComponents* FComponents;
	System::UnicodeString FStorageName;
	System::Classes::TStream* FStorageStream;
	Cxstorage::TcxStorageType FStorageType;
	System::Classes::TNotifyEvent FOnCreateHandler;
	System::Classes::TNotifyEvent FOnDestroyHandler;
	System::UnicodeString __fastcall GetStorageName(void);
	void __fastcall SetComponents(TcxPropertiesStoreComponents* const Value);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	void __fastcall OwnerCreate(System::TObject* Sender);
	void __fastcall OwnerDestroy(System::TObject* Sender);
	Cxstorage::TcxCustomReader* __fastcall CreateReader(void);
	Cxstorage::TcxCustomWriter* __fastcall CreateWriter(bool AReCreate = true);
	Cxstorage::TcxStorage* __fastcall CreateStorage(void);
	__property bool Active = {read=FActive, write=FActive, default=1};
	__property TcxPropertiesStoreComponents* Components = {read=FComponents, write=SetComponents};
	__property System::UnicodeString StorageName = {read=GetStorageName, write=FStorageName};
	__property Cxstorage::TcxStorageType StorageType = {read=FStorageType, write=FStorageType, default=0};
	
public:
	__fastcall virtual TcxCustomPropertiesStore(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomPropertiesStore(void);
	virtual void __fastcall RestoreFrom(void);
	virtual void __fastcall StoreTo(const bool AReCreate = true);
	__property System::Classes::TStream* StorageStream = {read=FStorageStream, write=FStorageStream};
};


class DELPHICLASS TcxPropertiesStore;
class PASCALIMPLEMENTATION TcxPropertiesStore : public TcxCustomPropertiesStore
{
	typedef TcxCustomPropertiesStore inherited;
	
__published:
	__property Active = {default=1};
	__property Components;
	__property StorageName = {default=0};
	__property StorageType = {default=0};
public:
	/* TcxCustomPropertiesStore.Create */ inline __fastcall virtual TcxPropertiesStore(System::Classes::TComponent* AOwner) : TcxCustomPropertiesStore(AOwner) { }
	/* TcxCustomPropertiesStore.Destroy */ inline __fastcall virtual ~TcxPropertiesStore(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxpropertiesstore */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPROPERTIESSTORE)
using namespace Cxpropertiesstore;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpropertiesstoreHPP
