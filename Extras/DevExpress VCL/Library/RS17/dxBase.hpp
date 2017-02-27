// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBase.pas' rev: 24.00 (Win32)

#ifndef DxbaseHPP
#define DxbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxPSSngltn.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbase
{
//-- type declarations -------------------------------------------------------
enum TdxLockState : unsigned char { lsUnlock, lsLock };

class DELPHICLASS TdxBaseObject;
typedef void __fastcall (__closure *TdxLockUpdateEvent)(TdxBaseObject* Sender, TdxLockState ALockState);

typedef System::TMetaClass* TdxBaseObjectClass;

class PASCALIMPLEMENTATION TdxBaseObject : public System::Classes::TInterfacedPersistent
{
	typedef System::Classes::TInterfacedPersistent inherited;
	
private:
	int FUpdateCount;
	TdxLockUpdateEvent FOnLockUpdate;
	
protected:
	virtual void __fastcall DoAssign(TdxBaseObject* Source);
	virtual void __fastcall DoRestoreDefaults(void);
	bool __fastcall IsLocked(void);
	DYNAMIC void __fastcall LockUpdate(TdxLockState ALockState);
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	__property TdxLockUpdateEvent OnLockUpdate = {read=FOnLockUpdate, write=FOnLockUpdate};
	
public:
	__fastcall virtual TdxBaseObject(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	virtual TdxBaseObject* __fastcall Clone(void);
	virtual bool __fastcall IsEmpty(void);
	virtual bool __fastcall IsEqual(TdxBaseObject* ABaseObject);
	void __fastcall RestoreDefaults(void);
	DYNAMIC void __fastcall LoadFromFile(const System::UnicodeString AFileName);
	DYNAMIC void __fastcall LoadFromStream(System::Classes::TStream* AStream);
	DYNAMIC void __fastcall SaveToFile(const System::UnicodeString AFileName);
	DYNAMIC void __fastcall SaveToStream(System::Classes::TStream* AStream);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxBaseObject(void) { }
	
};


class DELPHICLASS TdxClassList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxClassList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	System::TClass operator[](int Index) { return Items[Index]; }
	
private:
	System::TClass __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, System::TClass Value);
	
public:
	HIDESBASE int __fastcall Add(System::TClass AClass, bool ACheckExistence = true);
	bool __fastcall Find(System::TClass AClass, /* out */ int &AnIndex)/* overload */;
	bool __fastcall Find(System::TClass AClass)/* overload */;
	HIDESBASE int __fastcall IndexOf(System::TClass AClass);
	HIDESBASE void __fastcall Insert(int Index, System::TClass AClass, bool ACheckExistence = true);
	HIDESBASE int __fastcall Remove(System::TClass AClass);
	HIDESBASE System::TClass __fastcall Extract(System::TClass AClass);
	HIDESBASE System::TClass __fastcall First(void);
	HIDESBASE System::TClass __fastcall Last(void);
	__property System::TClass Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxClassList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxClassList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPersistentClassList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPersistentClassList : public TdxClassList
{
	typedef TdxClassList inherited;
	
public:
	System::Classes::TPersistentClass operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE System::Classes::TPersistentClass __fastcall GetItem(int Index);
	HIDESBASE void __fastcall SetItem(int Index, System::Classes::TPersistentClass Value);
	
protected:
	virtual void __fastcall UnregisterAll(void);
	
public:
	virtual void __fastcall Clear(void);
	HIDESBASE System::Classes::TPersistentClass __fastcall Extract(System::Classes::TPersistentClass AClass);
	HIDESBASE System::Classes::TPersistentClass __fastcall First(void);
	HIDESBASE System::Classes::TPersistentClass __fastcall Last(void);
	virtual int __fastcall Register(System::Classes::TPersistentClass AClass)/* overload */;
	virtual void __fastcall Register(int AnIndex, System::Classes::TPersistentClass AClass)/* overload */;
	virtual void __fastcall Unregister(System::Classes::TPersistentClass AClass);
	__property System::Classes::TPersistentClass Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxPersistentClassList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxPersistentClassList(void) : TdxClassList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomCache;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomCache : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	System::TObject* __fastcall GetItem(int Index);
	
protected:
	int __fastcall Add(System::TObject* AnObject);
	void __fastcall FreeAndNilItems(void);
	int __fastcall IndexOfByClass(System::TClass AClass);
	__property int Count = {read=GetCount, nodefault};
	__property System::TObject* Items[int Index] = {read=GetItem};
	
public:
	__fastcall TdxCustomCache(void);
	__fastcall virtual ~TdxCustomCache(void);
	virtual void __fastcall Clear(void);
};

#pragma pack(pop)

class DELPHICLASS TdxCustomClassFactory;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomClassFactory : public Dxpssngltn::TBasedxPSSingleton
{
	typedef Dxpssngltn::TBasedxPSSingleton inherited;
	
private:
	TdxClassList* FItems;
	int __fastcall GetCount(void);
	System::TClass __fastcall GetItem(int Index);
	
protected:
	virtual void __fastcall FinalizeInstance(void);
	virtual void __fastcall InitializeInstance(void);
	__property System::TClass Items[int Index] = {read=GetItem};
	
public:
	HIDESBASE int __fastcall IndexOf(System::TClass AClass);
	HIDESBASE virtual void __fastcall Register(System::TClass AClass);
	HIDESBASE virtual void __fastcall Unregister(System::TClass AClass);
	virtual void __fastcall UnregisterAll(void);
	__property int Count = {read=GetCount, nodefault};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxCustomClassFactory(int Dummy) : Dxpssngltn::TBasedxPSSingleton(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxCustomClassFactory(void) : Dxpssngltn::TBasedxPSSingleton() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxCustomClassFactory(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxCustomClassMapItemClass;

class DELPHICLASS TdxCustomClassMapItem;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomClassMapItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	__classmethod virtual System::TClass __fastcall PairClass();
public:
	/* TObject.Create */ inline __fastcall TdxCustomClassMapItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxCustomClassMapItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomClassMaps;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxCustomClassMaps : public TdxCustomClassFactory
{
	typedef TdxCustomClassFactory inherited;
	
private:
	HIDESBASE TdxCustomClassMapItemClass __fastcall GetItem(int Index);
	
protected:
	virtual TdxCustomClassMapItemClass __fastcall GetPairClass(System::TClass AClass);
	__property TdxCustomClassMapItemClass Items[int Index] = {read=GetItem};
	__property TdxCustomClassMapItemClass PairClasses[System::TClass AClass] = {read=GetPairClass};
protected:
	/* TBasedxPSSingleton.CreateInstance */ inline __fastcall TdxCustomClassMaps(int Dummy) : TdxCustomClassFactory(Dummy) { }
	
public:
	/* TBasedxPSSingleton.Create */ inline __fastcall virtual TdxCustomClassMaps(void) : TdxCustomClassFactory() { }
	/* TBasedxPSSingleton.Destroy */ inline __fastcall virtual ~TdxCustomClassMaps(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxSavePersistent(System::Classes::TStream* AStream, System::Classes::TPersistent* APersistent);
extern PACKAGE void __fastcall dxLoadPersistent(System::Classes::TStream* AStream, System::Classes::TPersistent* APersistent);
}	/* namespace Dxbase */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBASE)
using namespace Dxbase;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbaseHPP
