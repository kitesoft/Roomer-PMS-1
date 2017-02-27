// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarDBNav.pas' rev: 24.00 (Win64)

#ifndef DxbardbnavHPP
#define DxbardbnavHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbardbnav
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBarDBNavDataLink;
class DELPHICLASS TdxBarDBNavigator;
class PASCALIMPLEMENTATION TdxBarDBNavDataLink : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	TdxBarDBNavigator* FNavigator;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall EditingChanged(void);
public:
	/* TDataLink.Create */ inline __fastcall TdxBarDBNavDataLink(void) : Data::Db::TDataLink() { }
	/* TDataLink.Destroy */ inline __fastcall virtual ~TdxBarDBNavDataLink(void) { }
	
};


enum TdxBarDBEnableType : unsigned char { dxdbtCanModify, dxdbtNotEOF, dxdbtNotBOF, dxdbtHasRecords, dxdbtIsModified, dxdbtIsNotModified };

typedef System::Set<TdxBarDBEnableType, TdxBarDBEnableType::dxdbtCanModify, TdxBarDBEnableType::dxdbtIsNotModified>  TdxBarDBEnableTypes;

class DELPHICLASS TdxBarDBCheckLink;
class PASCALIMPLEMENTATION TdxBarDBCheckLink : public System::Classes::TCollectionItem
{
	typedef System::Classes::TCollectionItem inherited;
	
private:
	TdxBarDBEnableTypes FEnableTypes;
	Dxcoreclasses::TcxFreeNotificator* FFreeNotificator;
	Dxbar::TdxBarItem* FItem;
	void __fastcall FreeNotification(System::Classes::TComponent* Sender);
	TdxBarDBNavigator* __fastcall GetDBNavigator(void);
	void __fastcall SetEnableTypes(TdxBarDBEnableTypes Value);
	void __fastcall SetItem(Dxbar::TdxBarItem* Value);
	
public:
	__fastcall virtual TdxBarDBCheckLink(System::Classes::TCollection* Collection);
	__fastcall virtual ~TdxBarDBCheckLink(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Value);
	__property TdxBarDBNavigator* DBNavigator = {read=GetDBNavigator};
	
__published:
	__property Dxbar::TdxBarItem* Item = {read=FItem, write=SetItem};
	__property TdxBarDBEnableTypes EnableTypes = {read=FEnableTypes, write=SetEnableTypes, nodefault};
};


class DELPHICLASS TdxBarDBCheckLinks;
class PASCALIMPLEMENTATION TdxBarDBCheckLinks : public System::Classes::TCollection
{
	typedef System::Classes::TCollection inherited;
	
public:
	TdxBarDBCheckLink* operator[](int Index) { return Items[Index]; }
	
private:
	TdxBarDBNavigator* FDBNavigator;
	HIDESBASE TdxBarDBCheckLink* __fastcall GetItem(int Index);
	
protected:
	DYNAMIC System::Classes::TPersistent* __fastcall GetOwner(void);
	
public:
	HIDESBASE TdxBarDBCheckLink* __fastcall Add(void);
	__property TdxBarDBCheckLink* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TCollection.Create */ inline __fastcall TdxBarDBCheckLinks(System::Classes::TCollectionItemClass ItemClass) : System::Classes::TCollection(ItemClass) { }
	/* TCollection.Destroy */ inline __fastcall virtual ~TdxBarDBCheckLinks(void) { }
	
};


enum TdxBarDBNavButtonType : unsigned char { dxbnFirst, dxbnPrior, dxbnNext, dxbnLast, dxbnInsert, dxbnDelete, dxbnEdit, dxbnPost, dxbnCancel, dxbnRefresh };

typedef System::Set<TdxBarDBNavButtonType, TdxBarDBNavButtonType::dxbnFirst, TdxBarDBNavButtonType::dxbnRefresh>  TdxBarDBNavButtonTypes;

class DELPHICLASS TdxBarDBNavButton;
class PASCALIMPLEMENTATION TdxBarDBNavButton : public Dxbar::TdxBarButton
{
	typedef Dxbar::TdxBarButton inherited;
	
private:
	TdxBarDBNavigator* FBarDBNavigator;
	System::UnicodeString FLoadedCaption;
	TdxBarDBNavButtonType FNavButton;
	bool FIsCaptionAssigned;
	bool FIsHintAssigned;
	System::UnicodeString __fastcall DefaultCaption(void);
	void __fastcall ReadCaption(System::Classes::TReader* Reader);
	void __fastcall ReadHint(System::Classes::TReader* Reader);
	void __fastcall SetNavButton(TdxBarDBNavButtonType Value);
	void __fastcall WriteCaption(System::Classes::TWriter* Writer);
	void __fastcall WriteHint(System::Classes::TWriter* Writer);
	
protected:
	virtual void __fastcall DefineProperties(System::Classes::TFiler* Filer);
	virtual bool __fastcall IsCaptionStored(void);
	virtual bool __fastcall IsHintStored(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetCaption(const System::UnicodeString Value);
	virtual void __fastcall SetHint(System::UnicodeString Value);
	void __fastcall TranslationChanged(void);
	
public:
	__fastcall virtual ~TdxBarDBNavButton(void);
	DYNAMIC void __fastcall DoClick(void);
	
__published:
	__property TdxBarDBNavigator* BarDBNavigator = {read=FBarDBNavigator, write=FBarDBNavigator};
	__property Caption = {stored=false, default=0};
	__property Hint = {stored=false, default=0};
	__property TdxBarDBNavButtonType NavButton = {read=FNavButton, write=SetNavButton, nodefault};
public:
	/* TdxBarButton.Create */ inline __fastcall virtual TdxBarDBNavButton(System::Classes::TComponent* AOwner) : Dxbar::TdxBarButton(AOwner) { }
	
};


class PASCALIMPLEMENTATION TdxBarDBNavigator : public System::Classes::TComponent
{
	typedef System::Classes::TComponent inherited;
	
private:
	Dxbar::TdxBarManager* FBarManager;
	System::UnicodeString FCategoryName;
	bool FConfirmDelete;
	TdxBarDBNavDataLink* FDataLink;
	TdxBarDBCheckLinks* FDBCheckLinks;
	bool FSetVisFlag;
	TdxBarDBNavButtonTypes FVisibleButtons;
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	void __fastcall SetBarManager(Dxbar::TdxBarManager* Value);
	void __fastcall SetCategoryName(System::UnicodeString Value);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetDBNavItems(TdxBarDBCheckLinks* Value);
	void __fastcall SetVisibleButtons(TdxBarDBNavButtonTypes Value);
	void __fastcall AddButton(TdxBarDBNavButton* AButton);
	void __fastcall RemoveButton(TdxBarDBNavButton* AButton);
	void __fastcall CheckItemsEnable(void);
	
protected:
	System::StaticArray<TdxBarDBNavButton*, 10> Buttons;
	void __fastcall ActiveChanged(void);
	void __fastcall DataChanged(void);
	void __fastcall EditingChanged(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TdxBarDBNavigator(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxBarDBNavigator(void);
	void __fastcall TranslationChanged(void);
	
__published:
	__property Dxbar::TdxBarManager* BarManager = {read=FBarManager, write=SetBarManager};
	__property System::UnicodeString CategoryName = {read=FCategoryName, write=SetCategoryName};
	__property bool ConfirmDelete = {read=FConfirmDelete, write=FConfirmDelete, nodefault};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property TdxBarDBCheckLinks* DBCheckLinks = {read=FDBCheckLinks, write=SetDBNavItems};
	__property TdxBarDBNavButtonTypes VisibleButtons = {read=FVisibleButtons, write=SetVisibleButtons, default=0};
private:
	void *__IdxLocalizerListener;	/* Dxcore::IdxLocalizerListener */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {2E926681-1A56-4599-E8E0-B02D62740E56}
	operator Dxcore::_di_IdxLocalizerListener()
	{
		Dxcore::_di_IdxLocalizerListener intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxcore::IdxLocalizerListener*(void) { return (Dxcore::IdxLocalizerListener*)&__IdxLocalizerListener; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxbardbnav */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARDBNAV)
using namespace Dxbardbnav;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbardbnavHPP
