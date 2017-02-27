// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxCoreClasses.pas' rev: 24.00 (Win32)

#ifndef DxcoreclassesHPP
#define DxcoreclassesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxcoreclasses
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxIUnknownObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxIUnknownObject : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
public:
	/* TObject.Create */ inline __fastcall TcxIUnknownObject(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxIUnknownObject(void) { }
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxInterfacedPersistentClass;

class DELPHICLASS TcxInterfacedPersistent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxInterfacedPersistent : public System::Classes::TInterfacedPersistent
{
	typedef System::Classes::TInterfacedPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxInterfacedPersistent(System::Classes::TPersistent* AOwner);
	__property System::Classes::TPersistent* Owner = {read=FOwner};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxInterfacedPersistent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxOwnedPersistent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxOwnedPersistent : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TPersistent* FOwner;
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	__property System::Classes::TPersistent* Owner = {read=FOwner, write=FOwner};
	
public:
	__fastcall virtual TcxOwnedPersistent(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxOwnedPersistent(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxOwnedInterfacedPersistent;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxOwnedInterfacedPersistent : public TcxOwnedPersistent
{
	typedef TcxOwnedPersistent inherited;
	
protected:
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
public:
	/* TcxOwnedPersistent.Create */ inline __fastcall virtual TcxOwnedInterfacedPersistent(System::Classes::TPersistent* AOwner) : TcxOwnedPersistent(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxOwnedInterfacedPersistent(void) { }
	
private:
	void *__IInterface;	/* System::IInterface */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {00000000-0000-0000-C000-000000000046}
	operator System::_di_IInterface()
	{
		System::_di_IInterface intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator System::IInterface*(void) { return (System::IInterface*)&__IInterface; }
	#endif
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TcxFreeNotificationEvent)(System::Classes::TComponent* Sender);

class DELPHICLASS TcxFreeNotificator;
class PASCALIMPLEMENTATION TcxFreeNotificator : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TcxFreeNotificationEvent FOnFreeNotification;
	
protected:
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	void __fastcall AddSender(System::Classes::TComponent* ASender);
	void __fastcall RemoveSender(System::Classes::TComponent* ASender);
	__property TcxFreeNotificationEvent OnFreeNotification = {read=FOnFreeNotification, write=FOnFreeNotification};
public:
	/* TComponent.Create */ inline __fastcall virtual TcxFreeNotificator(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TcxFreeNotificator(void) { }
	
};


class DELPHICLASS TcxCollection;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCollection : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
public:
	/* TCollection.Create */ inline __fastcall TcxCollection(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TcxCollection(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDoublyLinkedObject;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedObject : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxDoublyLinkedObject* FPrev;
	TcxDoublyLinkedObject* FNext;
	
public:
	__property TcxDoublyLinkedObject* Prev = {read=FPrev, write=FPrev};
	__property TcxDoublyLinkedObject* Next = {read=FNext, write=FNext};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedObject(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedObject(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TcxDoublyLinkedObjectClass;

class DELPHICLASS TcxDoublyLinkedObjectList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedObjectList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int __fastcall GetCount(void);
	TcxDoublyLinkedObject* __fastcall GetFirst(void);
	
protected:
	TcxDoublyLinkedObject* FLast;
	virtual TcxDoublyLinkedObject* __fastcall CreateLinkedObject(void);
	virtual TcxDoublyLinkedObjectClass __fastcall GetLinkedObjectClass(void);
	
public:
	__fastcall virtual ~TcxDoublyLinkedObjectList(void);
	virtual TcxDoublyLinkedObject* __fastcall Add(void);
	void __fastcall Clear(void);
	void __fastcall InsertBefore(TcxDoublyLinkedObject* ADestination, TcxDoublyLinkedObject* ASource);
	void __fastcall InsertAfter(TcxDoublyLinkedObject* ADestination, TcxDoublyLinkedObject* ASource);
	virtual void __fastcall Delete(TcxDoublyLinkedObject* ALinkedObject);
	virtual void __fastcall Remove(TcxDoublyLinkedObject* &ALinkedObject);
	__property TcxDoublyLinkedObject* Last = {read=FLast};
	__property TcxDoublyLinkedObject* First = {read=GetFirst};
	__property int Count = {read=GetCount, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedObjectList(void) : System::TObject() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDoublyLinkedData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedData : public TcxDoublyLinkedObject
{
	typedef TcxDoublyLinkedObject inherited;
	
private:
	void *FData;
	TcxDoublyLinkedData* FNextSorted;
	TcxDoublyLinkedData* FPrevSorted;
	
public:
	__property void * Data = {read=FData, write=FData};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedData(void) : TcxDoublyLinkedObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedData(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDoublyLinkedDataList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedDataList : public TcxDoublyLinkedObjectList
{
	typedef TcxDoublyLinkedObjectList inherited;
	
public:
	HIDESBASE TcxDoublyLinkedData* __fastcall Add(void * AData);
	virtual TcxDoublyLinkedObjectClass __fastcall GetLinkedObjectClass(void);
	virtual void __fastcall PopulateFromList(System::Classes::TList* AList);
	virtual void __fastcall PopulateToList(System::Classes::TList* AList);
	void __fastcall Sort(System::Classes::TListSortCompare ACompareProc);
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedDataList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedDataList(void) : TcxDoublyLinkedObjectList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDoublyLinkedIndexedData;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedIndexedData : public TcxDoublyLinkedData
{
	typedef TcxDoublyLinkedData inherited;
	
private:
	int FIndex;
	
public:
	__property int Index = {read=FIndex, write=FIndex, nodefault};
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedIndexedData(void) : TcxDoublyLinkedData() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedIndexedData(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxDoublyLinkedDataIndexedList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDoublyLinkedDataIndexedList : public TcxDoublyLinkedDataList
{
	typedef TcxDoublyLinkedDataList inherited;
	
public:
	HIDESBASE TcxDoublyLinkedIndexedData* __fastcall Add(void * AData, int AIndex);
	virtual TcxDoublyLinkedObjectClass __fastcall GetLinkedObjectClass(void);
	virtual void __fastcall PopulateFromList(System::Classes::TList* AList);
public:
	/* TcxDoublyLinkedObjectList.Destroy */ inline __fastcall virtual ~TcxDoublyLinkedDataIndexedList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxDoublyLinkedDataIndexedList(void) : TcxDoublyLinkedDataList() { }
	
};

#pragma pack(pop)

typedef System::StaticArray<void *, 1> TdxPointerList;

typedef TdxPointerList *PdxPointerList;

typedef int __fastcall (__closure *TCompareItems)(void * AItem1, void * AItem2);

enum TdxListDirection : unsigned char { ldFromBeginning, ldFromEnd };

class DELPHICLASS TdxFastList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFastList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	void * operator[](int Index) { return Items[Index]; }
	
private:
	int FCapacity;
	int FCount;
	TdxPointerList *FList;
	void __fastcall DoDelete(int AIndex);
	
protected:
	void * __fastcall GetItem(int AIndex);
	void __fastcall Grow(void);
	void __fastcall SetCapacity(int AValue);
	void __fastcall SetCount(int AValue);
	void __fastcall SetItem(int AIndex, void * AItem);
	
public:
	__fastcall TdxFastList(int ACapacity);
	__fastcall virtual ~TdxFastList(void);
	int __fastcall Add(void * AItem);
	void __fastcall Assign(TdxFastList* ASource)/* overload */;
	void __fastcall Assign(System::Classes::TList* ASource)/* overload */;
	virtual void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	bool __fastcall Empty(void);
	void __fastcall Exchange(int AIndex1, int AIndex2);
	TdxFastList* __fastcall Expand(void);
	void * __fastcall Extract(void * AItem, TdxListDirection ADirection = (TdxListDirection)(0x0));
	void * __fastcall ExtractByIndex(int AIndex);
	void * __fastcall First(void);
	System::Classes::TList* __fastcall GetTList(void);
	int __fastcall IndexOf(void * AItem, TdxListDirection ADirection = (TdxListDirection)(0x0));
	void __fastcall Insert(int AIndex, void * AItem)/* overload */;
	void __fastcall Insert(int AIndex, TdxFastList* AList)/* overload */;
	void * __fastcall Last(void);
	void __fastcall Move(int ACurrentIndex, int ANewIndex);
	void __fastcall Pack(void * APattern = (void *)(0x0));
	int __fastcall Remove(void * AItem);
	void __fastcall Reverse(void);
	void __fastcall Sort(TCompareItems ACompare, bool AMultiThreaded = false)/* overload */;
	void __fastcall Sort(System::Classes::TListSortCompare ACompare, bool AMultiThreaded = false)/* overload */;
	__property int Capacity = {read=FCapacity, write=SetCapacity, nodefault};
	__property int Count = {read=FCount, write=SetCount, nodefault};
	__property void * Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property PdxPointerList List = {read=FList};
};

#pragma pack(pop)

class DELPHICLASS TdxFastObjectList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxFastObjectList : public TdxFastList
{
	typedef TdxFastList inherited;
	
public:
	System::TObject* operator[](int Index) { return Items[Index]; }
	
private:
	bool FOwnsObjects;
	
protected:
	HIDESBASE System::TObject* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, System::TObject* AObject);
	
public:
	__fastcall TdxFastObjectList(bool AOwnsObjects, int ACapacity);
	HIDESBASE int __fastcall Add(System::TObject* AObject);
	virtual void __fastcall Clear(void);
	HIDESBASE void __fastcall Delete(int AIndex);
	HIDESBASE System::TObject* __fastcall Extract(System::TObject* AItem);
	HIDESBASE int __fastcall Remove(System::TObject* AObject);
	HIDESBASE int __fastcall IndexOf(System::TObject* AObject, TdxListDirection ADirection = (TdxListDirection)(0x0));
	HIDESBASE void __fastcall Insert(int AIndex, System::TObject* AObject);
	HIDESBASE System::TObject* __fastcall First(void);
	HIDESBASE System::TObject* __fastcall Last(void);
	__property bool OwnsObjects = {read=FOwnsObjects, write=FOwnsObjects, nodefault};
	__property System::TObject* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TdxFastList.Destroy */ inline __fastcall virtual ~TdxFastObjectList(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
static const HRESULT cxE_NOINTERFACE = HRESULT(-2147467262);
extern PACKAGE void __fastcall dxQuickSortList(System::Classes::TList* AList, TCompareItems ACompareFunc, bool AMultiThreaded = false)/* overload */;
extern PACKAGE void __fastcall dxQuickSortList(PdxPointerList ASortList, int ACount, TCompareItems ACompareFunc, bool AMultiThreaded = false)/* overload */;
extern PACKAGE void __fastcall dxInternalQuickSortList(PdxPointerList ASortList, int ACount, TCompareItems ACompareFunc)/* overload */;
extern PACKAGE void __fastcall dxQuickSortList(System::Classes::TList* AList, System::Classes::TListSortCompare ACompareFunc, bool AMultiThreaded = false)/* overload */;
extern PACKAGE void __fastcall dxQuickSortList(PdxPointerList ASortList, int ACount, System::Classes::TListSortCompare ACompareFunc, bool AMultiThreaded = false)/* overload */;
extern PACKAGE void __fastcall dxInternalQuickSortList(PdxPointerList ASortList, int ACount, System::Classes::TListSortCompare ACompareFunc)/* overload */;
extern PACKAGE void __fastcall dxLiaisonSort(System::Classes::TList* AList, System::Classes::TListSortCompare ACompareProc = 0x0);
}	/* namespace Dxcoreclasses */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXCORECLASSES)
using namespace Dxcoreclasses;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxcoreclassesHPP
