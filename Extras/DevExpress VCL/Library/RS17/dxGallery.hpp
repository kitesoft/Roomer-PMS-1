// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxGallery.pas' rev: 24.00 (Win32)

#ifndef DxgalleryHPP
#define DxgalleryHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxgallery
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TdxGalleryItemClass;

typedef System::TMetaClass* TdxGalleryItemsClass;

typedef System::TMetaClass* TdxGalleryGroupClass;

typedef System::TMetaClass* TdxGalleryGroupsClass;

class DELPHICLASS TdxGalleryItem;
typedef void __fastcall (__closure *TdxGalleryItemEvent)(System::TObject* Sender, TdxGalleryItem* AItem);

enum TdxGalleryItemCheckMode : unsigned char { icmNone, icmSingleCheck, icmSingleRadio, icmMultiple };

enum TdxGalleryChangeType : unsigned char { gctLight, gctHard };

typedef void __fastcall (__closure *TdxGalleryChangeEvent)(System::TObject* Sender, TdxGalleryChangeType AChangeType);

__interface IdxGallery;
typedef System::DelphiInterface<IdxGallery> _di_IdxGallery;
class DELPHICLASS TdxGalleryGroups;
__interface  INTERFACE_UUID("{418FD781-56A7-4EA6-8720-1D0D479EBC2E}") IdxGallery  : public System::IInterface 
{
	
public:
	virtual TdxGalleryItemCheckMode __fastcall GetItemCheckMode(void) = 0 ;
	virtual void __fastcall SetItemCheckMode(TdxGalleryItemCheckMode AValue) = 0 ;
	virtual TdxGalleryGroups* __fastcall GetGroups(void) = 0 ;
	virtual void __fastcall SetGroups(TdxGalleryGroups* AValue) = 0 ;
	virtual TdxGalleryItemEvent __fastcall GetOnItemClick(void) = 0 ;
	virtual void __fastcall SetOnItemClick(TdxGalleryItemEvent AValue) = 0 ;
	virtual System::TObject* __fastcall GetInstance(void) = 0 ;
	virtual System::Classes::TComponent* __fastcall GetParentComponent(void) = 0 ;
	virtual void __fastcall ClickItem(TdxGalleryItem* AItem) = 0 ;
	virtual TdxGalleryItem* __fastcall GetCheckedItem(void) = 0 ;
	virtual void __fastcall GetCheckedItems(System::Classes::TList* AList) = 0 ;
	virtual void __fastcall UncheckAll(void) = 0 ;
	__property TdxGalleryItemCheckMode ItemCheckMode = {read=GetItemCheckMode, write=SetItemCheckMode};
	__property TdxGalleryGroups* Groups = {read=GetGroups, write=SetGroups};
	__property TdxGalleryItemEvent OnItemClick = {read=GetOnItemClick, write=SetOnItemClick};
};

__interface IdxGalleryOwner;
typedef System::DelphiInterface<IdxGalleryOwner> _di_IdxGalleryOwner;
__interface  INTERFACE_UUID("{9E2F64DD-D370-4B24-8FF3-7E4FE08A15F1}") IdxGalleryOwner  : public System::IInterface 
{
	
public:
	virtual _di_IdxGallery __fastcall GetGallery(void) = 0 ;
};

class DELPHICLASS TdxGalleryGroup;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryItem : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	System::UnicodeString FCaption;
	bool FChecked;
	System::UnicodeString FDescription;
	bool FEnabled;
	Vcl::Graphics::TBitmap* FGlyph;
	System::UnicodeString FHint;
	System::Uitypes::TImageIndex FImageIndex;
	void __fastcall GlyphChangeHandler(System::TObject* Sender);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetChecked(bool AValue);
	void __fastcall SetDescription(const System::UnicodeString AValue);
	void __fastcall SetEnabled(bool AValue);
	void __fastcall SetGlyph(Vcl::Graphics::TBitmap* AValue);
	void __fastcall SetImageIndex(System::Uitypes::TImageIndex Value);
	
protected:
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	virtual _di_IdxGallery __fastcall GetGallery(void);
	TdxGalleryGroup* __fastcall GetGroup(void);
	__property _di_IdxGallery Gallery = {read=GetGallery};
	__property TdxGalleryGroup* Group = {read=GetGroup};
	
public:
	__fastcall virtual TdxGalleryItem(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxGalleryItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property bool Checked = {read=FChecked, write=SetChecked, default=0};
	__property System::UnicodeString Description = {read=FDescription, write=SetDescription};
	__property bool Enabled = {read=FEnabled, write=SetEnabled, default=1};
	__property Vcl::Graphics::TBitmap* Glyph = {read=FGlyph, write=SetGlyph};
	__property System::UnicodeString Hint = {read=FHint, write=FHint};
	__property System::Uitypes::TImageIndex ImageIndex = {read=FImageIndex, write=SetImageIndex, default=-1};
};

#pragma pack(pop)

class DELPHICLASS TdxGalleryItems;
class PASCALIMPLEMENTATION TdxGalleryItems : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TdxGalleryItem* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	HIDESBASE TdxGalleryItem* __fastcall GetItem(int AIndex);
	HIDESBASE void __fastcall SetItem(int AIndex, TdxGalleryItem* AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetItemPrefixName(void);
	
public:
	HIDESBASE TdxGalleryItem* __fastcall Add(void);
	__property TdxGalleryItem* Items[int AIndex] = {read=GetItem, write=SetItem/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxGalleryItems(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Cxclasses::TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxGalleryItems(void) { }
	
};


class DELPHICLASS TdxGalleryGroupHeader;
class PASCALIMPLEMENTATION TdxGalleryGroupHeader : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	System::Classes::TAlignment FAlignment;
	System::UnicodeString FCaption;
	bool FVisible;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall SetAlignment(System::Classes::TAlignment AValue);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetVisible(bool AValue);
	
protected:
	virtual void __fastcall DoAssign(System::Classes::TPersistent* Source);
	void __fastcall Changed(void);
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=SetAlignment, nodefault};
	__property System::UnicodeString Caption = {read=FCaption, write=SetCaption};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TdxGalleryGroupHeader(System::Classes::TPersistent* AOwner);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TdxGalleryGroupHeader(void) { }
	
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxGalleryGroup : public Cxclasses::TcxComponentCollectionItem
{
	typedef Cxclasses::TcxComponentCollectionItem inherited;
	
private:
	TdxGalleryGroupHeader* FHeader;
	TdxGalleryItems* FItems;
	bool FVisible;
	System::UnicodeString __fastcall GetCaption(void);
	int __fastcall GetItemCount(void);
	bool __fastcall GetShowCaption(void);
	void __fastcall SetCaption(const System::UnicodeString AValue);
	void __fastcall SetItems(TdxGalleryItems* AValue);
	void __fastcall SetShowCaption(bool AValue);
	void __fastcall SetVisible(bool AValue);
	void __fastcall ItemsChangeHandler(System::TObject* Sender, Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall HeaderChangeHandler(System::TObject* ASender);
	
protected:
	virtual Cxclasses::TcxComponentCollection* __fastcall GetCollectionFromParent(System::Classes::TComponent* AParent);
	virtual _di_IdxGallery __fastcall GetGallery(void);
	virtual TdxGalleryItemClass __fastcall GetGalleryItemClass(void);
	virtual TdxGalleryItemsClass __fastcall GetGalleryItemsClass(void);
	__property _di_IdxGallery Gallery = {read=GetGallery};
	
public:
	__fastcall virtual TdxGalleryGroup(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxGalleryGroup(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	__property System::UnicodeString Caption = {read=GetCaption, write=SetCaption};
	__property bool ShowCaption = {read=GetShowCaption, write=SetShowCaption, nodefault};
	__property bool Visible = {read=FVisible, write=SetVisible, nodefault};
	__property TdxGalleryItems* Items = {read=FItems, write=SetItems};
	__property int ItemCount = {read=GetItemCount, nodefault};
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxGalleryGroups : public Cxclasses::TcxComponentCollection
{
	typedef Cxclasses::TcxComponentCollection inherited;
	
public:
	TdxGalleryGroup* operator[](int AIndex) { return Groups[AIndex]; }
	
private:
	TdxGalleryGroup* __fastcall GetGroup(int AIndex);
	void __fastcall SetGroup(int AIndex, TdxGalleryGroup* AValue);
	
protected:
	virtual System::UnicodeString __fastcall GetItemPrefixName(void);
	
public:
	HIDESBASE TdxGalleryGroup* __fastcall Add(void);
	bool __fastcall FindByCaption(const System::UnicodeString ACaption, /* out */ TdxGalleryGroup* &AGroup);
	__property TdxGalleryGroup* Groups[int AIndex] = {read=GetGroup, write=SetGroup/*, default*/};
public:
	/* TcxComponentCollection.Create */ inline __fastcall virtual TdxGalleryGroups(System::Classes::TComponent* AParentComponent, Cxclasses::TcxComponentCollectionItemClass AItemClass) : Cxclasses::TcxComponentCollection(AParentComponent, AItemClass) { }
	/* TcxComponentCollection.Destroy */ inline __fastcall virtual ~TdxGalleryGroups(void) { }
	
};


class DELPHICLASS TdxCustomGallery;
class PASCALIMPLEMENTATION TdxCustomGallery : public Dxcoreclasses::TcxOwnedInterfacedPersistent
{
	typedef Dxcoreclasses::TcxOwnedInterfacedPersistent inherited;
	
private:
	TdxGalleryGroups* FGroups;
	TdxGalleryChangeEvent FOnChange;
	TdxGalleryItemEvent FOnItemClick;
	TdxGalleryItemCheckMode FItemCheckMode;
	TdxGalleryItemCheckMode __fastcall GetItemCheckMode(void);
	void __fastcall SetItemCheckMode(TdxGalleryItemCheckMode AValue);
	TdxGalleryGroups* __fastcall GetGroups(void);
	void __fastcall SetGroups(TdxGalleryGroups* AValue);
	TdxGalleryChangeEvent __fastcall GetOnChange(void);
	void __fastcall SetOnChange(TdxGalleryChangeEvent AValue);
	TdxGalleryItemEvent __fastcall GetOnItemClick(void);
	void __fastcall SetOnItemClick(TdxGalleryItemEvent AValue);
	void __fastcall GroupsChangeHandler(System::TObject* Sender, Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	
protected:
	virtual TdxGalleryGroupClass __fastcall GetGroupClass(void);
	virtual TdxGalleryGroupsClass __fastcall GetGroupsClass(void);
	void __fastcall CheckItem(TdxGalleryItem* AItem, bool AValue);
	void __fastcall Changed(TdxGalleryChangeType AType);
	void __fastcall DoClickItem(TdxGalleryItem* AItem);
	System::TObject* __fastcall GetInstance(void);
	System::Classes::TComponent* __fastcall GetParentComponent(void);
	__property TdxGalleryChangeEvent OnChange = {read=GetOnChange, write=SetOnChange};
	__property TdxGalleryItemEvent OnItemClick = {read=GetOnItemClick, write=SetOnItemClick};
	
public:
	__fastcall virtual TdxCustomGallery(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxCustomGallery(void);
	void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	void __fastcall ClickItem(TdxGalleryItem* AItem);
	void __fastcall GetAllItems(System::Classes::TList* AList);
	TdxGalleryItem* __fastcall GetCheckedItem(void);
	TdxGalleryItem* __fastcall GetFirstItem(void);
	void __fastcall GetCheckedItems(System::Classes::TList* AList);
	void __fastcall UncheckAll(void);
	TdxGalleryItem* __fastcall FindItemByTag(NativeInt ATag);
	__property TdxGalleryItemCheckMode ItemCheckMode = {read=GetItemCheckMode, write=SetItemCheckMode, default=0};
	__property TdxGalleryGroups* Groups = {read=GetGroups, write=SetGroups};
private:
	void *__IdxGallery;	/* IdxGallery */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {418FD781-56A7-4EA6-8720-1D0D479EBC2E}
	operator _di_IdxGallery()
	{
		_di_IdxGallery intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxGallery*(void) { return (IdxGallery*)&__IdxGallery; }
	#endif
	
};


class DELPHICLASS TdxGallery;
class PASCALIMPLEMENTATION TdxGallery : public TdxCustomGallery
{
	typedef TdxCustomGallery inherited;
	
public:
	/* TdxCustomGallery.Create */ inline __fastcall virtual TdxGallery(System::Classes::TPersistent* AOwner) : TdxCustomGallery(AOwner) { }
	/* TdxCustomGallery.Destroy */ inline __fastcall virtual ~TdxGallery(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxgallery */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXGALLERY)
using namespace Dxgallery;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxgalleryHPP
