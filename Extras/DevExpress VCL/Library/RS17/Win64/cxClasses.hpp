// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxClasses.pas' rev: 24.00 (Win64)

#ifndef CxclassesHPP
#define CxclassesHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.ShellAPI.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <System.SyncObjs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxclasses
{
//-- type declarations -------------------------------------------------------
enum TcxAlignmentVert : unsigned char { vaTop, vaBottom, vaCenter };

typedef TcxAlignmentVert TcxTopBottom;

enum TcxCollectionOperation : unsigned char { copAdd, copDelete, copChanged };

enum TcxDirection : unsigned char { dirNone, dirLeft, dirRight, dirUp, dirDown };

typedef System::Classes::TComponent* __fastcall (*TcxGetComponent)(System::Classes::TComponent* ACaller, int Index);

typedef System::UnicodeString __fastcall (*TcxGetCaptionForIntegerItemFunc)(int AItem);

enum TcxPosition : unsigned char { posNone, posLeft, posRight, posTop, posBottom };

typedef System::UnicodeString TdxSkinName;

typedef int TcxTag;

typedef void * TcxResourceStringID;

__interface IcxDesignSelectionChanged;
typedef System::DelphiInterface<IcxDesignSelectionChanged> _di_IcxDesignSelectionChanged;
__interface  INTERFACE_UUID("{66B3AA59-1EBD-4135-AB18-E980F9C970F3}") IcxDesignSelectionChanged  : public System::IInterface 
{
	
public:
	virtual void __fastcall DesignSelectionChanged(System::Classes::TList* ASelection) = 0 ;
};

__interface IcxDesignHelper;
typedef System::DelphiInterface<IcxDesignHelper> _di_IcxDesignHelper;
__interface  INTERFACE_UUID("{4C78CC4F-699B-43BD-94AC-E3BD2233F7A1}") IcxDesignHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall AddSelectionChangedListener(System::Classes::TPersistent* AObject) = 0 ;
	virtual bool __fastcall CanAddComponent(System::Classes::TComponent* AOwner) = 0 ;
	virtual bool __fastcall CanDeleteComponent(System::Classes::TComponent* AOwner, System::Classes::TComponent* AComponent) = 0 ;
	virtual void __fastcall ChangeSelection(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject) = 0 ;
	virtual bool __fastcall IsObjectSelected(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject) = 0 ;
	virtual void __fastcall Modified(void) = 0 ;
	virtual void __fastcall RemoveSelectionChangedListener(System::Classes::TPersistent* AObject) = 0 ;
	virtual void __fastcall SelectObject(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject, bool AClearSelection = true, bool AActivateOwner = true) = 0 ;
	virtual void __fastcall ShowComponentDefaultEventHandler(System::Classes::TComponent* AComponent) = 0 ;
	virtual System::UnicodeString __fastcall UniqueName(const System::UnicodeString ABaseName) = 0 ;
	virtual void __fastcall UnselectObject(System::Classes::TComponent* AOwner, System::Classes::TPersistent* AObject) = 0 ;
};

__interface IdxManager;
typedef System::DelphiInterface<IdxManager> _di_IdxManager;
__interface  INTERFACE_UUID("{E82263AF-4C67-44BE-AD3E-3F8CEF246A3B}") IdxManager  : public System::IInterface 
{
	
public:
	virtual Vcl::Forms::TCustomForm* __fastcall GetParentForm(void) = 0 ;
};

__interface IdxManagedObject;
typedef System::DelphiInterface<IdxManagedObject> _di_IdxManagedObject;
__interface  INTERFACE_UUID("{AB78C3D2-400B-407F-A988-C015DDCEFED3}") IdxManagedObject  : public System::IInterface 
{
	
public:
	virtual _di_IdxManager __fastcall GetManager(void) = 0 ;
};

class DELPHICLASS TcxCustomComponent;
class PASCALIMPLEMENTATION TcxCustomComponent : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
public:
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall BeforeDestruction(void);
public:
	/* TComponent.Create */ inline __fastcall virtual TcxCustomComponent(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	/* TComponent.Destroy */ inline __fastcall virtual ~TcxCustomComponent(void) { }
	
};


class DELPHICLASS TcxComponent;
class PASCALIMPLEMENTATION TcxComponent : public TcxCustomComponent
{
	typedef TcxCustomComponent inherited;
	
private:
	System::Classes::TComponent* FFakeComponentLink1;
	System::Classes::TComponent* FFakeComponentLink2;
	System::Classes::TComponent* FFakeComponentLink3;
	int __fastcall GetFakeComponentLinkCount(void);
	bool __fastcall GetIsDesigning(void);
	bool __fastcall GetIsDestroying(void);
	void __fastcall SetFakeComponentLink(int Index, System::Classes::TComponent* Value);
	
protected:
	virtual void __fastcall GetFakeComponentLinks(System::Classes::TList* AList);
	virtual void __fastcall Loaded(void);
	void __fastcall UpdateFakeLinks(void);
	
public:
	__fastcall virtual ~TcxComponent(void);
	virtual void __fastcall BeforeDestruction(void);
	__property bool IsDesigning = {read=GetIsDesigning, nodefault};
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	
__published:
	__property System::Classes::TComponent* FakeComponentLink1 = {read=FFakeComponentLink1, write=FFakeComponentLink1, stored=false};
	__property System::Classes::TComponent* FakeComponentLink2 = {read=FFakeComponentLink2, write=FFakeComponentLink2, stored=false};
	__property System::Classes::TComponent* FakeComponentLink3 = {read=FFakeComponentLink3, write=FFakeComponentLink3, stored=false};
public:
	/* TComponent.Create */ inline __fastcall virtual TcxComponent(System::Classes::TComponent* AOwner) : TcxCustomComponent(AOwner) { }
	
};


class DELPHICLASS TcxComponentHolder;
class PASCALIMPLEMENTATION TcxComponentHolder : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	System::Classes::TComponent* FComponent;
	System::Classes::TNotifyEvent FOnAfterComponentChange;
	System::Classes::TNotifyEvent FOnBeforeComponentChange;
	void __fastcall SetComponent(System::Classes::TComponent* AValue);
	
protected:
	void __fastcall DoAfterComponentChange(void);
	void __fastcall DoBeforeComponentChange(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall TcxComponentHolder(void);
	__property System::Classes::TComponent* Component = {read=FComponent, write=SetComponent};
	__property System::Classes::TNotifyEvent OnAfterComponentChange = {read=FOnAfterComponentChange, write=FOnAfterComponentChange};
	__property System::Classes::TNotifyEvent OnBeforeComponentChange = {read=FOnBeforeComponentChange, write=FOnBeforeComponentChange};
public:
	/* TComponent.Destroy */ inline __fastcall virtual ~TcxComponentHolder(void) { }
	
};


class DELPHICLASS TcxTimer;
class PASCALIMPLEMENTATION TcxTimer : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	bool FEnabled;
	NativeUInt FEventID;
	unsigned FInterval;
	bool FTimerOn;
	System::Classes::TNotifyEvent FOnTimer;
	bool __fastcall CanSetTimer(void);
	void __fastcall KillTimer(void);
	void __fastcall SetEnabled(bool Value);
	void __fastcall SetInterval(unsigned Value);
	void __fastcall SetOnTimer(System::Classes::TNotifyEvent Value);
	void __fastcall SetTimer(void);
	void __fastcall SetTimerOn(bool Value);
	void __fastcall UpdateTimer(void);
	__property bool TimerOn = {read=FTimerOn, write=SetTimerOn, nodefault};
	
protected:
	DYNAMIC void __fastcall TimeOut(void);
	
public:
	__fastcall virtual TcxTimer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxTimer(void);
	
__published:
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property unsigned Interval = {read=FInterval, write=SetInterval, default=1000};
	__property System::Classes::TNotifyEvent OnTimer = {read=FOnTimer, write=SetOnTimer};
};


class DELPHICLASS TcxScalableComponent;
class PASCALIMPLEMENTATION TcxScalableComponent : public TcxComponent
{
	typedef TcxComponent inherited;
	
private:
	int FPixelsPerInch;
	bool FScalable;
	void __fastcall ReadPixelsPerInch(System::Classes::TReader* Reader);
	void __fastcall WritePixelsPerInch(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall ChangeScale(int M, int D);
	__property bool Scalable = {read=FScalable, write=FScalable, default=1};
	__property int PixelsPerInch = {read=FPixelsPerInch, write=FPixelsPerInch, nodefault};
	
public:
	__fastcall virtual TcxScalableComponent(System::Classes::TComponent* AOwner);
public:
	/* TcxComponent.Destroy */ inline __fastcall virtual ~TcxScalableComponent(void) { }
	
};


class DELPHICLASS TcxInterfacedCollectionItem;
class PASCALIMPLEMENTATION TcxInterfacedCollectionItem : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	System::_di_IInterface FOwnerInterface;
	
protected:
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	
public:
	virtual void __fastcall AfterConstruction(void);
public:
	/* TCollectionItem.Create */ inline __fastcall virtual TcxInterfacedCollectionItem(System::Classes::TCollection* Collection) : System::Classes::TCollectionItem(Collection) { }
	/* TCollectionItem.Destroy */ inline __fastcall virtual ~TcxInterfacedCollectionItem(void) { }
	
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


class DELPHICLASS TcxHashedStringList;
class PASCALIMPLEMENTATION TcxHashedStringList : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Classes::TStringList* FList;
	int __fastcall GetCount(void);
	int __fastcall GetHash(int Index);
	System::UnicodeString __fastcall GetString(int Index);
	void __fastcall SetString(int Index, const System::UnicodeString AValue);
	
public:
	__fastcall virtual TcxHashedStringList(void);
	__fastcall virtual ~TcxHashedStringList(void);
	virtual int __fastcall Add(const System::UnicodeString S);
	virtual int __fastcall IndexOf(const System::UnicodeString S);
	virtual void __fastcall Clear(void);
	__property int Count = {read=GetCount, nodefault};
	__property int Hash[int Index] = {read=GetHash};
	__property System::UnicodeString Strings[int Index] = {read=GetString, write=SetString};
};


typedef void __fastcall (__closure *TcxCollectionNotifyEvent)(System::TObject* Sender, System::Classes::TCollectionItem* AItem);

typedef int __fastcall (__closure *TcxCollectionCompareEvent)(System::TObject* ASender, System::Classes::TCollectionItem* AItem1, System::Classes::TCollectionItem* AItem2);

enum TcxCollectionInternalState : unsigned char { cisDestroying, cisUpdating, cisSorting };

typedef System::Set<TcxCollectionInternalState, TcxCollectionInternalState::cisDestroying, TcxCollectionInternalState::cisSorting>  TcxCollectionInternalStates;

class DELPHICLASS TcxOwnedInterfacedCollection;
class PASCALIMPLEMENTATION TcxOwnedInterfacedCollection : public System::Classes::TOwnedCollection
{
	typedef System::Classes::TOwnedCollection inherited;
	
private:
	TcxCollectionInternalStates FInternalState;
	bool FSorted;
	TcxCollectionNotifyEvent FOnChange;
	TcxCollectionCompareEvent FOnCompare;
	int __fastcall CompareItems(System::Classes::TStringList* AList, int AIndex1, int AIndex2);
	bool __fastcall GetIsDestroying(void);
	void __fastcall SetSorted(bool AValue);
	
protected:
	virtual void __fastcall Update(System::Classes::TCollectionItem* Item);
	virtual int __fastcall DoCompareItems(TcxInterfacedCollectionItem* AItem1, TcxInterfacedCollectionItem* AItem2);
	void __fastcall Sort(void);
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
	virtual HRESULT __stdcall QueryInterface(const GUID &IID, /* out */ void *Obj);
	int __stdcall _AddRef(void);
	int __stdcall _Release(void);
	__property bool IsDestroying = {read=GetIsDestroying, nodefault};
	__property TcxCollectionCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	
public:
	__fastcall virtual ~TcxOwnedInterfacedCollection(void);
	__property TcxCollectionNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TOwnedCollection.Create */ inline __fastcall TcxOwnedInterfacedCollection(System::Classes::TPersistent* AOwner, System::Classes::TCollectionItemClass ItemClass) : System::Classes::TOwnedCollection(AOwner, ItemClass) { }
	
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


class DELPHICLASS TcxObjectList;
class PASCALIMPLEMENTATION TcxObjectList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	System::TObject* operator[](int Index) { return Items[Index]; }
	
private:
	bool FOwnObjects;
	System::TObject* __fastcall GetItem(int Index);
	
public:
	__fastcall TcxObjectList(bool AOwnObjects);
	virtual void __fastcall Clear(void);
	void __fastcall FreeAndDelete(int Index);
	int __fastcall FreeAndRemove(System::TObject* AObject);
	__property System::TObject* Items[int Index] = {read=GetItem/*, default*/};
	__property bool OwnObjects = {read=FOwnObjects, nodefault};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxObjectList(void) { }
	
};


typedef void __fastcall (__closure *TcxEventHandler)(System::TObject* Sender, const void *AEventArgs);

class DELPHICLASS TcxEventHandlerCollection;
class PASCALIMPLEMENTATION TcxEventHandlerCollection : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<TcxEventHandler> _TcxEventHandlerCollection__1;
	
	
private:
	_TcxEventHandlerCollection__1 FEvents;
	void __fastcall Delete(int AIndex);
	int __fastcall IndexOf(TcxEventHandler AEvent);
	
public:
	void __fastcall Add(TcxEventHandler AEvent);
	void __fastcall CallEvents(System::TObject* Sender, const void *AEventArgs)/* overload */;
	void __fastcall CallEvents(System::TObject* Sender)/* overload */;
	void __fastcall Remove(TcxEventHandler AEvent);
public:
	/* TObject.Create */ inline __fastcall TcxEventHandlerCollection(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxEventHandlerCollection(void) { }
	
};


class DELPHICLASS TcxRegisteredClassListItemData;
class PASCALIMPLEMENTATION TcxRegisteredClassListItemData : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TClass ItemClass;
	System::TClass RegisteredClass;
public:
	/* TObject.Create */ inline __fastcall TcxRegisteredClassListItemData(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxRegisteredClassListItemData(void) { }
	
};


class DELPHICLASS TcxRegisteredClassList;
class PASCALIMPLEMENTATION TcxRegisteredClassList : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxRegisteredClassListItemData* operator[](int Index) { return Items[Index]; }
	
private:
	Dxcoreclasses::TdxFastList* FItems;
	int __fastcall GetCount(void);
	TcxRegisteredClassListItemData* __fastcall GetItem(int Index);
	
protected:
	virtual bool __fastcall Find(System::TClass AItemClass, int &AIndex);
	
public:
	__fastcall TcxRegisteredClassList(void);
	__fastcall virtual ~TcxRegisteredClassList(void);
	void __fastcall Clear(void);
	System::TClass __fastcall FindClass(System::TClass AItemClass);
	virtual void __fastcall Register(System::TClass AItemClass, System::TClass ARegisteredClass);
	virtual void __fastcall Unregister(System::TClass AItemClass, System::TClass ARegisteredClass);
	__property int Count = {read=GetCount, nodefault};
	__property TcxRegisteredClassListItemData* Items[int Index] = {read=GetItem/*, default*/};
};


class DELPHICLASS TcxRegisteredClasses;
class PASCALIMPLEMENTATION TcxRegisteredClasses : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TClass operator[](int Index) { return Items[Index]; }
	
private:
	System::Classes::TStringList* FItems;
	bool FRegisterClasses;
	bool FSorted;
	int __fastcall GetCount(void);
	System::UnicodeString __fastcall GetDescription(int Index);
	System::UnicodeString __fastcall GetHint(int Index);
	System::TClass __fastcall GetItem(int Index);
	void __fastcall SetSorted(bool Value);
	
protected:
	virtual int __fastcall CompareItems(int AIndex1, int AIndex2);
	virtual void __fastcall Sort(void);
	
public:
	__fastcall TcxRegisteredClasses(bool ARegisterClasses);
	__fastcall virtual ~TcxRegisteredClasses(void);
	void __fastcall Clear(void);
	System::TClass __fastcall FindByClassName(const System::UnicodeString AClassName);
	System::TClass __fastcall FindByDescription(const System::UnicodeString ADescription);
	System::UnicodeString __fastcall GetDescriptionByClass(System::TClass AClass);
	System::UnicodeString __fastcall GetHintByClass(System::TClass AClass);
	int __fastcall GetIndexByClass(System::TClass AClass);
	void __fastcall Register(System::TClass AClass, const System::UnicodeString ADescription);
	void __fastcall Unregister(System::TClass AClass);
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString Descriptions[int Index] = {read=GetDescription};
	__property System::UnicodeString Hints[int Index] = {read=GetHint};
	__property System::TClass Items[int Index] = {read=GetItem/*, default*/};
	__property bool RegisterClasses = {read=FRegisterClasses, write=FRegisterClasses, nodefault};
	__property bool Sorted = {read=FSorted, write=SetSorted, nodefault};
};


class DELPHICLASS TcxAutoWidthItem;
class PASCALIMPLEMENTATION TcxAutoWidthItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	int MinWidth;
	int Width;
	bool Fixed;
	int AutoWidth;
	__fastcall TcxAutoWidthItem(void);
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxAutoWidthItem(void) { }
	
};


class DELPHICLASS TcxAutoWidthObject;
class PASCALIMPLEMENTATION TcxAutoWidthObject : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxAutoWidthItem* operator[](int Index) { return Items[Index]; }
	
private:
	int FAvailableWidth;
	System::Classes::TList* FItems;
	int __fastcall GetCount(void);
	TcxAutoWidthItem* __fastcall GetItem(int Index);
	int __fastcall GetWidth(void);
	
protected:
	void __fastcall Clear(void);
	
public:
	__fastcall TcxAutoWidthObject(int ACount);
	__fastcall virtual ~TcxAutoWidthObject(void);
	TcxAutoWidthItem* __fastcall AddItem(void);
	void __fastcall Calculate(void);
	__property int AvailableWidth = {read=FAvailableWidth, write=FAvailableWidth, nodefault};
	__property int Count = {read=GetCount, nodefault};
	__property TcxAutoWidthItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int Width = {read=GetWidth, nodefault};
};


class DELPHICLASS TcxAlignment;
class PASCALIMPLEMENTATION TcxAlignment : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TAlignment FDefaultHorz;
	TcxAlignmentVert FDefaultVert;
	System::Classes::TAlignment FHorz;
	bool FIsHorzAssigned;
	bool FIsVertAssigned;
	System::Classes::TPersistent* FOwner;
	bool FUseAssignedValues;
	TcxAlignmentVert FVert;
	System::Classes::TNotifyEvent FOnChanged;
	bool __fastcall IsHorzStored(void);
	bool __fastcall IsVertStored(void);
	void __fastcall SetHorz(const System::Classes::TAlignment Value);
	void __fastcall SetVert(const TcxAlignmentVert Value);
	
protected:
	void __fastcall DoChanged(void);
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	__fastcall virtual TcxAlignment(System::Classes::TPersistent* AOwner, bool AUseAssignedValues, System::Classes::TAlignment ADefaultHorz, TcxAlignmentVert ADefaultVert);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Reset(void);
	__property System::Classes::TNotifyEvent OnChanged = {read=FOnChanged, write=FOnChanged};
	
__published:
	__property System::Classes::TAlignment Horz = {read=FHorz, write=SetHorz, stored=IsHorzStored, nodefault};
	__property TcxAlignmentVert Vert = {read=FVert, write=SetVert, stored=IsVertStored, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxAlignment(void) { }
	
};


class DELPHICLASS TcxObjectLink;
class PASCALIMPLEMENTATION TcxObjectLink : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::TObject* Ref;
public:
	/* TObject.Create */ inline __fastcall TcxObjectLink(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxObjectLink(void) { }
	
};


class DELPHICLASS TcxObjectLinkController;
class PASCALIMPLEMENTATION TcxObjectLinkController : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Dxcoreclasses::TdxFastList* FLinks;
	
public:
	__fastcall TcxObjectLinkController(void);
	__fastcall virtual ~TcxObjectLinkController(void);
	TcxObjectLink* __fastcall AddLink(System::TObject* AObject);
	void __fastcall RemoveLink(TcxObjectLink* ALink);
	void __fastcall ClearLinks(System::TObject* AObject);
};


typedef System::TMetaClass* TcxMRUItemClass;

class DELPHICLASS TcxMRUItem;
class PASCALIMPLEMENTATION TcxMRUItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	HIDESBASE virtual bool __fastcall Equals(TcxMRUItem* AItem) = 0 ;
public:
	/* TObject.Create */ inline __fastcall TcxMRUItem(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TcxMRUItem(void) { }
	
};


class DELPHICLASS TcxMRUItems;
class PASCALIMPLEMENTATION TcxMRUItems : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TcxMRUItem* operator[](int Index) { return Items[Index]; }
	
private:
	bool FAllowDuplicates;
	System::Classes::TList* FItems;
	int FMaxCount;
	int __fastcall GetCount(void);
	TcxMRUItem* __fastcall GetItem(int Index);
	void __fastcall SetCount(int Value);
	void __fastcall SetMaxCount(int Value);
	
protected:
	void __fastcall Delete(int AIndex);
	void __fastcall UpdateCount(void);
	__property bool AllowDuplicates = {read=FAllowDuplicates, write=FAllowDuplicates, nodefault};
	
public:
	__fastcall virtual TcxMRUItems(void);
	__fastcall virtual ~TcxMRUItems(void);
	void __fastcall Add(TcxMRUItem* AItem);
	void __fastcall ClearItems(void);
	int __fastcall IndexOf(TcxMRUItem* AItem);
	__property int Count = {read=GetCount, write=SetCount, nodefault};
	__property TcxMRUItem* Items[int Index] = {read=GetItem/*, default*/};
	__property int MaxCount = {read=FMaxCount, write=SetMaxCount, nodefault};
};


class DELPHICLASS TcxOpenList;
class PASCALIMPLEMENTATION TcxOpenList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	System::TObject* operator[](int Index) { return Items[Index]; }
	
private:
	System::TObject* __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, System::TObject* Value);
	
public:
	__property System::TObject* Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxOpenList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxOpenList(void) : System::Classes::TList() { }
	
};


class DELPHICLASS TcxComponentCollectionItem;
class DELPHICLASS TcxComponentCollection;
class PASCALIMPLEMENTATION TcxComponentCollectionItem : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	TcxComponentCollection* FCollection;
	int FID;
	int __fastcall GetIndex(void);
	
protected:
	void __fastcall AddToCollection(TcxComponentCollection* ACollection);
	void __fastcall Changed(bool AAllItems);
	virtual TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent) = 0 ;
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	void __fastcall RemoveFromCollection(TcxComponentCollection* ACollection);
	virtual void __fastcall SetCollection(TcxComponentCollection* AValue);
	virtual void __fastcall SetIndex(int AValue);
	
public:
	__fastcall virtual ~TcxComponentCollectionItem(void);
	DYNAMIC System::Classes::TComponent* __fastcall GetParentComponent(void);
	DYNAMIC bool __fastcall HasParent(void);
	DYNAMIC void __fastcall SetParentComponent(System::Classes::TComponent* Value);
	__property TcxComponentCollection* Collection = {read=FCollection, write=SetCollection};
	__property System::UnicodeString DisplayName = {read=GetDisplayName};
	__property int ID = {read=FID, nodefault};
	__property int Index = {read=GetIndex, write=SetIndex, nodefault};
public:
	/* TComponent.Create */ inline __fastcall virtual TcxComponentCollectionItem(System::Classes::TComponent* AOwner) : System::Classes::TComponent(AOwner) { }
	
};


typedef System::TMetaClass* TcxComponentCollectionItemClass;

enum TcxComponentCollectionNotification : unsigned char { ccnAdded, ccnChanged, ccnExtracting, ccnExtracted, ccnDeleting };

typedef void __fastcall (__closure *TcxComponentCollectionChangeEvent)(System::TObject* Sender, TcxComponentCollectionItem* AItem, TcxComponentCollectionNotification AAction);

class PASCALIMPLEMENTATION TcxComponentCollection : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	TcxComponentCollectionItem* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	TcxComponentCollectionItemClass FItemClass;
	System::Classes::TList* FItems;
	int FNextID;
	System::Classes::TComponent* FParentComponent;
	int FUpdateCount;
	TcxComponentCollectionChangeEvent FOnChange;
	int __fastcall GetCount(void);
	void __fastcall InsertItem(TcxComponentCollectionItem* AItem);
	void __fastcall RemoveItem(TcxComponentCollectionItem* AItem);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	TcxComponentCollectionItem* __fastcall AddItem(System::Classes::TComponent* AParentComponent, System::Classes::TComponent* AOwner);
	TcxComponentCollectionItem* __fastcall AddInternalItem(void);
	void __fastcall Changed(TcxComponentCollectionItem* AItem = (TcxComponentCollectionItem*)(0x0), TcxComponentCollectionNotification AAction = (TcxComponentCollectionNotification)(0x1));
	TcxComponentCollectionItem* __fastcall GetItem(int AIndex);
	virtual Vcl::Controls::TControl* __fastcall GetParentControl(void);
	virtual System::UnicodeString __fastcall GetItemPrefixName(void);
	virtual System::UnicodeString __fastcall GetItemSuffixName(void);
	virtual void __fastcall Notify(TcxComponentCollectionItem* AItem, TcxComponentCollectionNotification AAction);
	void __fastcall ReadOldCollection(System::Classes::TReader* AReader);
	void __fastcall SetItem(int AIndex, TcxComponentCollectionItem* Value);
	virtual void __fastcall SetItemName(TcxComponentCollectionItem* AItem);
	virtual void __fastcall Update(TcxComponentCollectionItem* AItem, TcxComponentCollectionNotification AAction);
	__property int NextID = {read=FNextID, nodefault};
	__property int UpdateCount = {read=FUpdateCount, nodefault};
	__property TcxComponentCollectionItemClass ItemClass = {read=FItemClass};
	
public:
	__fastcall virtual TcxComponentCollection(System::Classes::TComponent* AParentComponent, TcxComponentCollectionItemClass AItemClass);
	__fastcall virtual ~TcxComponentCollection(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	TcxComponentCollectionItem* __fastcall Add(void);
	virtual void __fastcall BeginUpdate(void);
	void __fastcall Clear(void);
	void __fastcall Delete(int AIndex);
	virtual void __fastcall EndUpdate(bool AForceUpdate = true);
	TcxComponentCollectionItem* __fastcall FindItemByID(int ID);
	int __fastcall IndexOf(TcxComponentCollectionItem* AItem);
	TcxComponentCollectionItem* __fastcall Insert(int AIndex);
	void __fastcall Remove(TcxComponentCollectionItem* AItem);
	__property int Count = {read=GetCount, nodefault};
	__property System::Classes::TComponent* ParentComponent = {read=FParentComponent};
	__property TcxComponentCollectionItem* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
	__property TcxComponentCollectionChangeEvent OnChange = {read=FOnChange, write=FOnChange};
};


__interface IcxDialogMetricsInfoData;
typedef System::DelphiInterface<IcxDialogMetricsInfoData> _di_IcxDialogMetricsInfoData;
__interface  INTERFACE_UUID("{DBFB3040-4677-4C9D-913C-45A1EE41E35A}") IcxDialogMetricsInfoData  : public System::IInterface 
{
	
public:
	virtual void * __fastcall GetInfoData(void) = 0 ;
	virtual int __fastcall GetInfoDataSize(void) = 0 ;
	virtual void __fastcall SetInfoData(void * AData) = 0 ;
};

class DELPHICLASS TcxDialogMetricsInfo;
class PASCALIMPLEMENTATION TcxDialogMetricsInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FClientHeight;
	int FClientWidth;
	void *FData;
	System::TClass FDialogClass;
	int FLeft;
	int FTop;
	bool FMaximized;
	void __fastcall FreeCustomData(void);
	
protected:
	void __fastcall Restore(Vcl::Forms::TForm* AForm);
	void __fastcall Store(Vcl::Forms::TForm* AForm);
	
public:
	__fastcall TcxDialogMetricsInfo(Vcl::Forms::TForm* AForm);
	__fastcall virtual ~TcxDialogMetricsInfo(void);
	__property int ClientHeight = {read=FClientHeight, nodefault};
	__property int ClientWidth = {read=FClientWidth, nodefault};
	__property void * Data = {read=FData};
	__property System::TClass DialogClass = {read=FDialogClass};
	__property int Left = {read=FLeft, nodefault};
	__property bool Maximized = {read=FMaximized, nodefault};
	__property int Top = {read=FTop, nodefault};
};


class DELPHICLASS TcxDialogsMetricsStore;
class PASCALIMPLEMENTATION TcxDialogsMetricsStore : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Forms::TPosition FDefaultPosition;
	TcxObjectList* FMetrics;
	
protected:
	TcxDialogMetricsInfo* __fastcall CreateMetrics(Vcl::Forms::TForm* AForm);
	int __fastcall FindMetrics(Vcl::Forms::TForm* AForm);
	__property TcxObjectList* Metrics = {read=FMetrics};
	
public:
	__fastcall virtual TcxDialogsMetricsStore(void);
	__fastcall virtual ~TcxDialogsMetricsStore(void);
	void __fastcall InitDialog(Vcl::Forms::TForm* AForm);
	void __fastcall StoreMetrics(Vcl::Forms::TForm* AForm);
	__property Vcl::Forms::TPosition DefaultPosition = {read=FDefaultPosition, write=FDefaultPosition, default=6};
};


class DELPHICLASS TcxEvent;
class PASCALIMPLEMENTATION TcxEvent : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	NativeUInt FHandle;
	unsigned __fastcall WaitForEvent(unsigned ATimeOut);
	
public:
	__fastcall TcxEvent(bool AManualReset, bool AInitialState);
	__fastcall virtual ~TcxEvent(void);
	System::Syncobjs::TWaitResult __fastcall WaitFor(unsigned TimeOut);
	void __fastcall ResetEvent(void);
	void __fastcall SetEvent(void);
	__property NativeUInt Handle = {read=FHandle};
};


class DELPHICLASS TcxCustomThread;
class PASCALIMPLEMENTATION TcxCustomThread : public System::Classes::TThread
{
	typedef System::Classes::TThread inherited;
	
private:
	System::Sysutils::Exception* FException;
	void __fastcall DoHandleException(void);
	
protected:
	virtual void __fastcall HandleException(void);
	void __fastcall ResetException(void);
public:
	/* TThread.Create */ inline __fastcall TcxCustomThread(void)/* overload */ : System::Classes::TThread() { }
	/* TThread.Create */ inline __fastcall TcxCustomThread(bool CreateSuspended)/* overload */ : System::Classes::TThread(CreateSuspended) { }
	/* TThread.Destroy */ inline __fastcall virtual ~TcxCustomThread(void) { }
	
};


class DELPHICLASS TcxThread;
class PASCALIMPLEMENTATION TcxThread : public TcxCustomThread
{
	typedef TcxCustomThread inherited;
	
private:
	bool FCheckingForPause;
	bool FDestroying;
	bool FPaused;
	TcxEvent* FPauseEvent;
	TcxEvent* FWaitForPauseEvent;
	bool __fastcall GetRunning(void);
	
protected:
	void __fastcall CheckForPause(void);
	__property bool Destroying = {read=FDestroying, nodefault};
	__property bool Paused = {read=FPaused, nodefault};
	__property bool Running = {read=GetRunning, nodefault};
	
public:
	__fastcall TcxThread(bool ACreateSuspended, bool ACreatePaused);
	__fastcall virtual ~TcxThread(void);
	virtual void __fastcall Pause(bool AWaitForPause = false);
	virtual void __fastcall Unpause(void);
};


typedef void __fastcall (__closure *TcxComponentListNotifyEvent)(System::TObject* Sender, System::Classes::TComponent* AComponent, System::Classes::TListNotification AAction);

typedef void __fastcall (__closure *TcxComponentListChangeEvent)(System::TObject* Sender, System::Classes::TComponent* AComponent, TcxComponentCollectionNotification AAction);

class DELPHICLASS TcxComponentList;
class PASCALIMPLEMENTATION TcxComponentList : public System::Contnrs::TComponentList
{
	typedef System::Contnrs::TComponentList inherited;
	
private:
	int FUpdateCount;
	TcxComponentListChangeEvent FOnComponentListChanged;
	TcxComponentListNotifyEvent FOnNotify;
	
protected:
	virtual void __fastcall DoNotify(System::Classes::TComponent* AItem, System::Classes::TListNotification AAction);
	virtual System::TClass __fastcall GetItemClass(void);
	virtual void __fastcall Notify(void * Ptr, System::Classes::TListNotification Action);
	void __fastcall Update(System::Classes::TComponent* AItem = (System::Classes::TComponent*)(0x0), TcxComponentCollectionNotification AAction = (TcxComponentCollectionNotification)(0x1));
	
public:
	__fastcall TcxComponentList(void)/* overload */;
	__fastcall virtual ~TcxComponentList(void);
	virtual void __fastcall Clear(void);
	void __fastcall BeginUpdate(void);
	void __fastcall CancelUpdate(void);
	void __fastcall EndUpdate(void);
	__property TcxComponentListChangeEvent OnComponentListChanged = {read=FOnComponentListChanged, write=FOnComponentListChanged};
	__property TcxComponentListNotifyEvent OnNotify = {read=FOnNotify, write=FOnNotify};
public:
	/* TComponentList.Create */ inline __fastcall TcxComponentList(bool AOwnsObjects)/* overload */ : System::Contnrs::TComponentList(AOwnsObjects) { }
	
};


typedef void __fastcall (*TcxNotifyProcedure)(System::TObject* Sender);

typedef void __fastcall (__closure *TcxNotifyEvent)(System::TObject* Sender, System::UnicodeString ANotificationText);

#pragma pack(push,1)
struct DECLSPEC_DRECORD TcxLangRec
{
public:
	System::UnicodeString FName;
	unsigned FLCID;
	System::UnicodeString FExt;
	System::UnicodeString FLocaleName;
};
#pragma pack(pop)


class DELPHICLASS TdxLanguages;
class PASCALIMPLEMENTATION TdxLanguages : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	typedef System::DynamicArray<TcxLangRec> _TdxLanguages__1;
	
	
private:
	_TdxLanguages__1 FSysLangs;
	int __stdcall LocalesCallback(System::WideChar * LocaleID);
	int __fastcall GetCount(void);
	System::UnicodeString __fastcall GetExt(int Index);
	System::UnicodeString __fastcall GetID(int Index);
	unsigned __fastcall GetLocaleID(int Index);
	System::UnicodeString __fastcall GetLocaleName(int Index);
	System::UnicodeString __fastcall GetName(int Index);
	System::UnicodeString __fastcall GetNameFromLocaleID(unsigned ID);
	System::UnicodeString __fastcall GetNameFromLCID(const System::UnicodeString ID);
	
public:
	__fastcall TdxLanguages(void);
	unsigned __fastcall GetDefaultLanguageLCID(void);
	unsigned __fastcall GetLCID(const System::UnicodeString AName);
	int __fastcall IndexOf(unsigned ID)/* overload */;
	int __fastcall IndexOf(const System::UnicodeString ALocaleName)/* overload */;
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString Name[int Index] = {read=GetName};
	__property System::UnicodeString NameFromLCID[const System::UnicodeString ID] = {read=GetNameFromLCID};
	__property System::UnicodeString NameFromLocaleID[unsigned ID] = {read=GetNameFromLocaleID};
	__property System::UnicodeString ID[int Index] = {read=GetID};
	__property unsigned LocaleID[int Index] = {read=GetLocaleID};
	__property System::UnicodeString LocaleName[int Index] = {read=GetLocaleName};
	__property System::UnicodeString Ext[int Index] = {read=GetExt};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxLanguages(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxAlignmentVert cxDefaultAlignmentVert;
extern PACKAGE System::UnicodeString __fastcall cxGetClassName(NativeUInt AWnd);
extern PACKAGE int __fastcall cxStrCharLength(const System::UnicodeString AStr, int AIndex = 0x1);
extern PACKAGE int __fastcall cxNextCharPos(const System::UnicodeString AStr, int AIndex);
extern PACKAGE int __fastcall cxPrevCharPos(const System::UnicodeString AStr, int AIndex);
extern PACKAGE TcxObjectLink* __fastcall cxAddObjectLink(System::TObject* AObject);
extern PACKAGE void __fastcall cxRemoveObjectLink(TcxObjectLink* ALink);
extern PACKAGE void __fastcall cxClearObjectLinks(System::TObject* AObject);
extern PACKAGE void __fastcall CallNotify(System::Classes::TNotifyEvent ANotifyEvent, System::TObject* ASender);
extern PACKAGE bool __fastcall ClassInheritsFrom(System::TClass AClass, const System::UnicodeString AParentClassName);
extern PACKAGE bool __fastcall EqualMethods(const System::TMethod &AMethod1, const System::TMethod &AMethod2);
extern PACKAGE void __fastcall FillStringsWithEnumTypeValues(System::Classes::TStrings* AStrings, System::Typinfo::PTypeInfo ATypeInfo, TcxGetCaptionForIntegerItemFunc AGetTypeItemCaption);
extern PACKAGE System::Classes::TPersistent* __fastcall GetPersistentOwner(System::Classes::TPersistent* APersistent);
extern PACKAGE System::UnicodeString __fastcall GetSubobjectName(System::Classes::TPersistent* AObject, System::Classes::TPersistent* ASubobject);
extern PACKAGE System::UnicodeString __fastcall GetValidName(System::Classes::TComponent* AComponent, const System::UnicodeString AName, bool AIsBaseName = false);
extern PACKAGE void __fastcall RenameComponents(System::Classes::TComponent* ACaller, System::Classes::TComponent* AOwner, System::Classes::TComponentName ANewName, const System::Classes::TComponentName AOldName, int AComponentCount, TcxGetComponent AGetComponent);
extern PACKAGE int __fastcall RoundDiv(int I1, int I2);
extern PACKAGE System::Types::TSize __fastcall Size(int cx, int cy);
extern PACKAGE void __fastcall SwapIntegers(int &I1, int &I2);
extern PACKAGE int __fastcall GetRangeCenter(int ABound1, int ABound2);
extern PACKAGE bool __fastcall StreamsEqual(System::Classes::TMemoryStream* AStream1, System::Classes::TMemoryStream* AStream2);
extern PACKAGE void __fastcall OpenWebPage(const System::UnicodeString AWebAddress);
extern PACKAGE System::UnicodeString __fastcall GetCorrectPath(const System::UnicodeString S);
extern PACKAGE System::UnicodeString __fastcall cxGetResourceString(void * AResString)/* overload */;
extern PACKAGE void __fastcall cxSetResourceString(void * AResString, const System::UnicodeString Value);
extern PACKAGE System::UnicodeString __fastcall cxGetResourceString _DEPRECATED_ATTRIBUTE0 (const System::UnicodeString AResString)/* overload */;
extern PACKAGE System::UnicodeString __fastcall cxGetResourceStringNet _DEPRECATED_ATTRIBUTE0 (const System::UnicodeString AResString);
extern PACKAGE void __fastcall cxSetResourceStringNet _DEPRECATED_ATTRIBUTE0 (const System::UnicodeString AResString, const System::UnicodeString Value);
extern PACKAGE void __fastcall cxClearResourceStrings(void);
extern PACKAGE TdxLanguages* __fastcall dxLanguages(void);
extern PACKAGE System::UnicodeString __fastcall cxGetUnitName(System::TClass AClass);
extern PACKAGE System::UnicodeString __fastcall CreateUniqueName(System::Classes::TComponent* AOwnerForm, System::Classes::TComponent* AOwnerComponent, System::Classes::TComponent* AComponent, const System::UnicodeString APrefixName, const System::UnicodeString ASuffixName, int ABaseIndex = 0xffffffff);
extern PACKAGE System::UnicodeString __fastcall cxGenerateComponentName(System::Classes::TComponent* AOwnerComponent, const System::UnicodeString AClassName, const System::UnicodeString APrefixName, const System::UnicodeString ASuffixName, int ANumber);
extern PACKAGE int __fastcall cxSign(const double AValue);
extern PACKAGE NativeInt __fastcall cxSendStructMessage(NativeUInt AHandle, unsigned AMsg, NativeUInt WParam, const void *LParam)/* overload */;
extern PACKAGE NativeInt __fastcall cxSendStructMessage(NativeUInt AHandle, unsigned AMsg, const void *WParam, NativeInt LParam)/* overload */;
extern PACKAGE TcxTimer* __fastcall cxCreateTimer(System::Classes::TNotifyEvent AOnTimer, int AInterval = 0x3e8, bool AEnabled = true);
extern PACKAGE TcxDialogsMetricsStore* __fastcall cxDialogsMetricsStore(void);
}	/* namespace Cxclasses */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCLASSES)
using namespace Cxclasses;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxclassesHPP
