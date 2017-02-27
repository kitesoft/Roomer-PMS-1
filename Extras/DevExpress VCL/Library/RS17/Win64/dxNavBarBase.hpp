// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxNavBarBase.pas' rev: 24.00 (Win64)

#ifndef DxnavbarbaseHPP
#define DxnavbarbaseHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <cxAccessibility.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxnavbarbase
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxNavBarNexusPersistent;
class PASCALIMPLEMENTATION TdxNavBarNexusPersistent : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
protected:
	Dxcoreclasses::TcxFreeNotificator* FNotifyComponent;
	virtual void __fastcall FreeNotification(System::Classes::TComponent* AComponent);
	
public:
	__fastcall virtual TdxNavBarNexusPersistent(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxNavBarNexusPersistent(void);
};


enum TdxNavBarChangeType : unsigned char { doRecreate, doRecalc, doRedraw };

typedef void __fastcall (__closure *TdxNavBarChangeEvent)(System::TObject* Sender, TdxNavBarChangeType AType);

class DELPHICLASS TdxNavBarComponentCollectionItem;
class DELPHICLASS TdxNavBarComponentCollection;
class PASCALIMPLEMENTATION TdxNavBarComponentCollectionItem : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	TdxNavBarComponentCollection* __fastcall InternalGetCollection(void);
	void __fastcall InternalSetCollection(TdxNavBarComponentCollection* Value);
	
protected:
	virtual void __fastcall InitiateActions(void);
	virtual void __fastcall SetIndex(int Value);
	
public:
	__property TdxNavBarComponentCollection* Collection = {read=InternalGetCollection, write=InternalSetCollection};
public:
	/* TcxComponentCollectionItem.Destroy */ inline __fastcall virtual ~TdxNavBarComponentCollectionItem(void) { }
	
public:
	/* TComponent.Create */ inline __fastcall virtual TdxNavBarComponentCollectionItem(System::Classes::TComponent* AOwner) : Cxclasses::TcxComponentCollectionItem(AOwner) { }
	
};


typedef System::TMetaClass* TdxNavBarComponentCollectionItemClass;

class PASCALIMPLEMENTATION TdxNavBarComponentCollection : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
private:
	System::Classes::TComponent* __fastcall InternalGetOwner(void);
	
protected:
	virtual void __fastcall InitiateActions(void);
	
public:
	HIDESBASE TdxNavBarComponentCollectionItem* __fastcall Add(void);
	TdxNavBarComponentCollectionItem* __fastcall ItemByName(const System::UnicodeString AName);
	__property System::Classes::TComponent* Owner = {read=InternalGetOwner};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxNavBarComponentCollection(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Cxclasses::TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxNavBarComponentCollection(void) { }
	
};


__interface IdxNavBarAccessibilityHelper;
typedef System::DelphiInterface<IdxNavBarAccessibilityHelper> _di_IdxNavBarAccessibilityHelper;
class DELPHICLASS TdxNavBarCustomAccessibilityHelper;
__interface  INTERFACE_UUID("{C8DF0BFA-B9C6-4BB8-B377-8E3FAE529855}") IdxNavBarAccessibilityHelper  : public Cxaccessibility::IcxAccessibilityHelper 
{
	
public:
	virtual void __fastcall AttachChild(_di_IdxNavBarAccessibilityHelper AChild) = 0 ;
	virtual bool __fastcall CanFocus(bool AFocusingByDefault) = 0 ;
	virtual void __fastcall DetachChild(_di_IdxNavBarAccessibilityHelper AChild) = 0 ;
	virtual void __fastcall FocusedChanged(bool AMakeVisible) = 0 ;
	virtual TdxNavBarCustomAccessibilityHelper* __fastcall GetNavBarHelper(void) = 0 ;
	virtual _di_IdxNavBarAccessibilityHelper __fastcall GetNextObjectForNavigation(Cxclasses::TcxDirection ADirection) = 0 ;
	virtual bool __fastcall IsFocused(void) = 0 ;
	virtual bool __fastcall IsPressed(void) = 0 ;
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift) = 0 ;
	virtual void __fastcall KeyPress(System::WideChar &Key) = 0 ;
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift) = 0 ;
	virtual void __fastcall RemoveFocus(void) = 0 ;
};

class PASCALIMPLEMENTATION TdxNavBarCustomAccessibilityHelper : public Cxaccessibility::TcxAccessibilityHelper
{
	typedef Cxaccessibility::TcxAccessibilityHelper inherited;
	
private:
	System::Classes::TInterfaceList* FAttachedChildList;
	Vcl::Controls::TWinControl* FOwnerObjectControl;
	bool FIsPressed;
	int FTag;
	TdxNavBarCustomAccessibilityHelper* __fastcall InternalGetChild(int AIndex);
	TdxNavBarCustomAccessibilityHelper* __fastcall InternalGetParent(void);
	
protected:
	virtual void __fastcall OwnerObjectDestroyed(void);
	virtual Cxaccessibility::TcxAccessibilityHelper* __fastcall GetChild(int AIndex);
	virtual int __fastcall GetChildCount(void);
	virtual HWND __fastcall GetOwnerObjectWindow(void);
	virtual int __fastcall GetState(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	void __fastcall AttachChild(_di_IdxNavBarAccessibilityHelper AChild);
	virtual bool __fastcall CanFocus(bool AFocusingByDefault);
	void __fastcall DetachChild(_di_IdxNavBarAccessibilityHelper AChild);
	virtual void __fastcall FocusedChanged(bool AMakeVisible);
	TdxNavBarCustomAccessibilityHelper* __fastcall GetNavBarHelper(void);
	_di_IdxNavBarAccessibilityHelper __fastcall GetNextObjectForNavigation(Cxclasses::TcxDirection ADirection);
	bool __fastcall IsFocused(void);
	bool __fastcall IsPressed(void);
	virtual void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall KeyPress(System::WideChar &Key);
	virtual void __fastcall KeyUp(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall RemoveFocus(void);
	virtual bool __fastcall CanBeFocusedByDefault(void);
	virtual void __fastcall Click(System::Word AKey);
	virtual TdxNavBarCustomAccessibilityHelper* __fastcall GetAssociatedObject(void);
	virtual System::Types::TRect __fastcall GetBounds(void) = 0 ;
	virtual _di_IdxNavBarAccessibilityHelper __fastcall InternalGetNextObjectForNavigation(Cxclasses::TcxDirection ADirection);
	bool __fastcall IsChild(TdxNavBarCustomAccessibilityHelper* AChild);
	virtual bool __fastcall IsClickKey(System::Word AKey);
	virtual bool __fastcall IsContainer(void) = 0 ;
	virtual bool __fastcall IsScrollable(/* out */ int &AInvisiblePartHeight, /* out */ int &AChildMinTopScreenBound);
	virtual void __fastcall MakeVisible(void);
	void __fastcall SetIsPressed(bool Value);
	__property TdxNavBarCustomAccessibilityHelper* AssociatedObject = {read=GetAssociatedObject};
	__property Vcl::Controls::TWinControl* OwnerObjectControl = {read=FOwnerObjectControl};
	__property int Tag = {read=FTag, write=FTag, nodefault};
	
public:
	__fastcall virtual TdxNavBarCustomAccessibilityHelper(System::TObject* AOwnerObject, Vcl::Controls::TWinControl* AOwnerObjectControl);
	__fastcall virtual ~TdxNavBarCustomAccessibilityHelper(void);
	virtual System::Types::TRect __fastcall GetScreenBounds(Cxaccessibility::TcxAccessibleSimpleChildElementID AChildID);
	__property TdxNavBarCustomAccessibilityHelper* Childs[int AIndex] = {read=InternalGetChild};
	__property TdxNavBarCustomAccessibilityHelper* Parent = {read=InternalGetParent};
private:
	void *__IdxNavBarAccessibilityHelper;	/* IdxNavBarAccessibilityHelper */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C8DF0BFA-B9C6-4BB8-B377-8E3FAE529855}
	operator _di_IdxNavBarAccessibilityHelper()
	{
		_di_IdxNavBarAccessibilityHelper intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxNavBarAccessibilityHelper*(void) { return (IdxNavBarAccessibilityHelper*)&__IdxNavBarAccessibilityHelper; }
	#endif
	
};


typedef System::TMetaClass* TdxNavBarCustomAccessibilityHelperClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall NavBarAccessibleObjectOwnerObjectDestroyed(_di_IdxNavBarAccessibilityHelper &AAccessibleObject);
extern PACKAGE _di_IdxNavBarAccessibilityHelper __fastcall NavBarGetAccessibilityHelper(System::TObject* AObject);
extern PACKAGE _di_IdxNavBarAccessibilityHelper __fastcall NavBarGetFocusableAccessibleObjectAtPos(_di_IdxNavBarAccessibilityHelper ARootAccessibleObject, const System::Types::TPoint P);
}	/* namespace Dxnavbarbase */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXNAVBARBASE)
using namespace Dxnavbarbase;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxnavbarbaseHPP
