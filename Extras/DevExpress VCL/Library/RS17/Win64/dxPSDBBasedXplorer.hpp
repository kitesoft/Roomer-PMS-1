// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSDBBasedXplorer.pas' rev: 24.00 (Win64)

#ifndef DxpsdbbasedxplorerHPP
#define DxpsdbbasedxplorerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsdbbasedxplorer
{
//-- type declarations -------------------------------------------------------
enum TdxDBBasedExplorerItemType : unsigned char { eitFolder, eitItem };

struct TdxDBBasedExplorerItemUniqueID;
typedef TdxDBBasedExplorerItemUniqueID *PdxDBBasedExplorerItemUniqueID;

struct DECLSPEC_DRECORD TdxDBBasedExplorerItemUniqueID
{
public:
	int ID;
	TdxDBBasedExplorerItemType ItemType;
};


class DELPHICLASS TdxPSDBBasedExplorerFolder;
class DELPHICLASS TdxPSDBBasedExplorerItem;
class DELPHICLASS TdxPSDBBasedExplorer;
class PASCALIMPLEMENTATION TdxPSDBBasedExplorerFolder : public Dxpscore::TdxPSExplorerFolder
{
	typedef Dxpscore::TdxPSExplorerFolder inherited;
	
public:
	TdxPSDBBasedExplorerFolder* operator[](int Index) { return Folders[Index]; }
	
private:
	int FID;
	int FParentID;
	HIDESBASE TdxPSDBBasedExplorerFolder* __fastcall GetFolder(int Index);
	HIDESBASE TdxPSDBBasedExplorerItem* __fastcall GetItem(int Index);
	void __fastcall SetParentID(int Value);
	
protected:
	virtual void __fastcall InternalMove(Dxpscore::TdxPSExplorerFolder* AParent);
	
public:
	__fastcall virtual TdxPSDBBasedExplorerFolder(Dxpscore::TCustomdxPSExplorer* AnExplorer, Dxpscore::TdxPSExplorerFolder* AParent);
	HIDESBASE virtual bool __fastcall CanMoveTo(int AParentID)/* overload */;
	HIDESBASE TdxPSDBBasedExplorer* __fastcall Explorer(void)/* overload */;
	virtual int __fastcall GetUniqueID(/* out */ System::DynamicArray<System::Byte> &AnUniqueID);
	__property TdxPSDBBasedExplorerFolder* Folders[int Index] = {read=GetFolder/*, default*/};
	__property int ID = {read=FID, nodefault};
	__property TdxPSDBBasedExplorerItem* Items[int Index] = {read=GetItem};
	__property int ParentID = {read=FParentID, write=SetParentID, nodefault};
public:
	/* TdxPSExplorerFolder.Destroy */ inline __fastcall virtual ~TdxPSDBBasedExplorerFolder(void) { }
	
/* Hoisted overloads: */
	
public:
	inline bool __fastcall  CanMoveTo(Dxpscore::TCustomdxPSExplorerItem* AParent){ return Dxpscore::TCustomdxPSExplorerItem::CanMoveTo(AParent); }
	
};


class PASCALIMPLEMENTATION TdxPSDBBasedExplorerItem : public Dxpscore::TdxPSExplorerItem
{
	typedef Dxpscore::TdxPSExplorerItem inherited;
	
private:
	int FID;
	int FParentID;
	void __fastcall SetParentID(int Value);
	
protected:
	virtual void __fastcall InternalMove(Dxpscore::TdxPSExplorerFolder* AParent);
	virtual void __fastcall SaveDocument(void);
	virtual void __fastcall SaveItem(void);
	
public:
	__fastcall virtual TdxPSDBBasedExplorerItem(Dxpscore::TCustomdxPSExplorer* AnExplorer, Dxpscore::TdxPSExplorerFolder* AParent);
	HIDESBASE virtual bool __fastcall CanMoveTo(int AParentID)/* overload */;
	virtual System::UnicodeString __fastcall DataLoadErrorText(void);
	HIDESBASE TdxPSDBBasedExplorer* __fastcall Explorer(void)/* overload */;
	virtual int __fastcall GetUniqueID(/* out */ System::DynamicArray<System::Byte> &AnUniqueID);
	__property int ID = {read=FID, nodefault};
	__property int ParentID = {read=FParentID, write=SetParentID, nodefault};
public:
	/* TdxPSExplorerItem.Destroy */ inline __fastcall virtual ~TdxPSDBBasedExplorerItem(void) { }
	
/* Hoisted overloads: */
	
public:
	inline bool __fastcall  CanMoveTo(Dxpscore::TCustomdxPSExplorerItem* AParent){ return Dxpscore::TCustomdxPSExplorerItem::CanMoveTo(AParent); }
	
};


class DELPHICLASS TCustomdxPSDBBasedExplorerFieldNamesMap;
class PASCALIMPLEMENTATION TCustomdxPSDBBasedExplorerFieldNamesMap : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
public:
	System::UnicodeString operator[](int Index) { return Items[Index]; }
	
private:
	TdxPSDBBasedExplorer* FExplorer;
	System::Classes::TStringList* FItems;
	int __fastcall GetCount(void);
	
protected:
	System::UnicodeString __fastcall GetItem(int Index);
	void __fastcall SetItem(int Index, const System::UnicodeString Value);
	DYNAMIC void __fastcall Changed(void);
	virtual int __fastcall GetMapCount(void);
	virtual void __fastcall InitializeItems(void);
	__property int Count = {read=GetCount, nodefault};
	__property System::UnicodeString Items[int Index] = {read=GetItem, write=SetItem/*, default*/};
	__property int MapCount = {read=GetMapCount, nodefault};
	
public:
	__fastcall virtual TCustomdxPSDBBasedExplorerFieldNamesMap(TdxPSDBBasedExplorer* AnExplorer);
	__fastcall virtual ~TCustomdxPSDBBasedExplorerFieldNamesMap(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TdxPSDBBasedExplorer* Explorer = {read=FExplorer};
};


typedef System::TMetaClass* TdxPSDBBasedExplorerFieldNamesMapClass;

class DELPHICLASS TdxPSDBBasedExplorerFieldNamesMap;
class PASCALIMPLEMENTATION TdxPSDBBasedExplorerFieldNamesMap : public TCustomdxPSDBBasedExplorerFieldNamesMap
{
	typedef TCustomdxPSDBBasedExplorerFieldNamesMap inherited;
	
protected:
	virtual int __fastcall GetMapCount(void);
	
__published:
	__property System::UnicodeString ID = {read=GetItem, write=SetItem, index=0};
	__property System::UnicodeString Name = {read=GetItem, write=SetItem, index=1};
	__property System::UnicodeString ParentID = {read=GetItem, write=SetItem, index=2};
public:
	/* TCustomdxPSDBBasedExplorerFieldNamesMap.Create */ inline __fastcall virtual TdxPSDBBasedExplorerFieldNamesMap(TdxPSDBBasedExplorer* AnExplorer) : TCustomdxPSDBBasedExplorerFieldNamesMap(AnExplorer) { }
	/* TCustomdxPSDBBasedExplorerFieldNamesMap.Destroy */ inline __fastcall virtual ~TdxPSDBBasedExplorerFieldNamesMap(void) { }
	
};


typedef System::TMetaClass* TdxPSDBBasedExplorerFoldersFieldNamesMapClass;

class DELPHICLASS TdxPSDBBasedExplorerFoldersFieldNamesMap;
class PASCALIMPLEMENTATION TdxPSDBBasedExplorerFoldersFieldNamesMap : public TdxPSDBBasedExplorerFieldNamesMap
{
	typedef TdxPSDBBasedExplorerFieldNamesMap inherited;
	
public:
	/* TCustomdxPSDBBasedExplorerFieldNamesMap.Create */ inline __fastcall virtual TdxPSDBBasedExplorerFoldersFieldNamesMap(TdxPSDBBasedExplorer* AnExplorer) : TdxPSDBBasedExplorerFieldNamesMap(AnExplorer) { }
	/* TCustomdxPSDBBasedExplorerFieldNamesMap.Destroy */ inline __fastcall virtual ~TdxPSDBBasedExplorerFoldersFieldNamesMap(void) { }
	
};


typedef System::TMetaClass* TdxPSDBBasedExplorerItemsFieldNamesMapClass;

class DELPHICLASS TdxPSDBBasedExplorerItemsFieldNamesMap;
class PASCALIMPLEMENTATION TdxPSDBBasedExplorerItemsFieldNamesMap : public TdxPSDBBasedExplorerFieldNamesMap
{
	typedef TdxPSDBBasedExplorerFieldNamesMap inherited;
	
protected:
	virtual int __fastcall GetMapCount(void);
	
__published:
	__property System::UnicodeString Data = {read=GetItem, write=SetItem, index=3};
public:
	/* TCustomdxPSDBBasedExplorerFieldNamesMap.Create */ inline __fastcall virtual TdxPSDBBasedExplorerItemsFieldNamesMap(TdxPSDBBasedExplorer* AnExplorer) : TdxPSDBBasedExplorerFieldNamesMap(AnExplorer) { }
	/* TCustomdxPSDBBasedExplorerFieldNamesMap.Destroy */ inline __fastcall virtual ~TdxPSDBBasedExplorerItemsFieldNamesMap(void) { }
	
};


typedef void __fastcall (__closure *TdxPSDBBasedExplorerLoadErrorEvent)(TdxPSDBBasedExplorer* Sender, Data::Db::TDataSet* ADataSet);

class PASCALIMPLEMENTATION TdxPSDBBasedExplorer : public Dxpscore::TCustomdxPSExplorer
{
	typedef Dxpscore::TCustomdxPSExplorer inherited;
	
private:
	System::Classes::TList* FFolderList;
	Data::Db::TDataSet* FFolders;
	TdxPSDBBasedExplorerFoldersFieldNamesMap* FFoldersFieldNamesMap;
	System::Classes::TList* FItemList;
	Data::Db::TDataSet* FItems;
	TdxPSDBBasedExplorerItemsFieldNamesMap* FItemsFieldNamesMap;
	TdxPSDBBasedExplorerLoadErrorEvent FOnLoadError;
	HIDESBASE TdxPSDBBasedExplorerFolder* __fastcall GetRoot(void);
	void __fastcall SetFolders(Data::Db::TDataSet* Value);
	void __fastcall SetFoldersFieldNamesMap(TdxPSDBBasedExplorerFoldersFieldNamesMap* Value);
	void __fastcall SetItems(Data::Db::TDataSet* Value);
	void __fastcall SetItemsFieldNamesMap(TdxPSDBBasedExplorerItemsFieldNamesMap* Value);
	
protected:
	virtual System::Classes::TStream* __fastcall CreateItemDataStream(Dxpscore::TdxPSExplorerItem* AnItem, Dxpscore::TdxPSStreamMode AMode);
	__classmethod virtual Dxpscore::TdxPSExplorerFolderClass __fastcall GetFolderClass();
	__classmethod virtual Dxpscore::TdxPSExplorerItemClass __fastcall GetItemClass();
	__classmethod virtual Dxpscore::TdxPSExplorerFolderClass __fastcall GetRootFolderClass();
	virtual void __fastcall DoLoadData(Dxpscore::TdxPSExplorerFolder* AFolder);
	virtual bool __fastcall CanDelete(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual bool __fastcall CanMoveTo(Dxpscore::TCustomdxPSExplorerItem* AnItem, Dxpscore::TCustomdxPSExplorerItem* AParent);
	virtual bool __fastcall CanRenameTo(Dxpscore::TCustomdxPSExplorerItem* AnItem, const System::UnicodeString AName);
	virtual void __fastcall Delete(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	virtual void __fastcall MoveTo(Dxpscore::TCustomdxPSExplorerItem* AnItem, Dxpscore::TdxPSExplorerFolder* AParent);
	virtual void __fastcall RenameTo(Dxpscore::TCustomdxPSExplorerItem* AnItem, System::UnicodeString AName);
	virtual void __fastcall DoRefresh(void);
	__classmethod virtual TdxPSDBBasedExplorerFoldersFieldNamesMapClass __fastcall GetFoldersFieldNamesMapClass();
	__classmethod virtual TdxPSDBBasedExplorerItemsFieldNamesMapClass __fastcall GetItemsFieldNamesMapClass();
	bool __fastcall AreIDsEqual(int AnID1, int AnID2);
	DYNAMIC void __fastcall Changed(void);
	virtual bool __fastcall CheckDataSets(void);
	virtual bool __fastcall CheckItemDataSet(Dxpscore::TCustomdxPSExplorerItem* AnItem)/* overload */;
	virtual bool __fastcall CheckItemDataSet(Dxpscore::TCustomdxPSExplorerItemClass AnItemClass)/* overload */;
	virtual System::Classes::TStream* __fastcall CreateDataStream(Data::Db::TBlobStreamMode AMode);
	virtual Data::Db::TDataSet* __fastcall GetItemDataSet(Dxpscore::TCustomdxPSExplorerItem* AnItem)/* overload */;
	virtual Data::Db::TDataSet* __fastcall GetItemDataSet(Dxpscore::TCustomdxPSExplorerItemClass AnItemClass)/* overload */;
	virtual TdxPSDBBasedExplorerFieldNamesMap* __fastcall GetItemFieldNamesMap(Dxpscore::TCustomdxPSExplorerItem* AnItem)/* overload */;
	virtual TdxPSDBBasedExplorerFieldNamesMap* __fastcall GetItemFieldNamesMap(Dxpscore::TCustomdxPSExplorerItemClass AnItemClass)/* overload */;
	virtual int __fastcall GetUniqueFolderID(void);
	virtual int __fastcall GetUniqueItemID(void);
	bool __fastcall IsFolderIDAutoIncField(void);
	bool __fastcall IsItemIDAutoIncField(void);
	virtual void __fastcall LoadFolderFromCurrentRecord(TdxPSDBBasedExplorerFolder* AFolder);
	virtual void __fastcall LoadItemFromCurrentRecord(TdxPSDBBasedExplorerItem* AnItem);
	virtual void __fastcall SaveFolderToCurrentRecord(TdxPSDBBasedExplorerFolder* AFolder);
	virtual void __fastcall SaveItemToCurrentRecord(TdxPSDBBasedExplorerItem* AnItem, Dxpscore::TBasedxReportLink* AReportLink);
	DYNAMIC void __fastcall DoLoadError(Data::Db::TDataSet* ADataSet);
	System::Variant __fastcall GetFieldValue(Data::Db::TDataSet* ADataSet, const System::UnicodeString AName);
	bool __fastcall IsFieldNameValid(Data::Db::TDataSet* ADataSet, const System::UnicodeString AName);
	void __fastcall SetFieldValue(Data::Db::TDataSet* ADataSet, const System::UnicodeString AName, const System::Variant &Value);
	bool __fastcall LocateItem(Dxpscore::TCustomdxPSExplorerItem* AnItem);
	void __fastcall PrepareIterate(Data::Db::TDataSet* ADataSet, /* out */ System::DynamicArray<System::Byte> &ABookmark);
	void __fastcall UnprepareIterate(Data::Db::TDataSet* ADataSet, System::DynamicArray<System::Byte> &ABookmark);
	__property System::Classes::TList* FolderList = {read=FFolderList};
	__property System::Classes::TList* ItemList = {read=FItemList};
	
public:
	__fastcall virtual TdxPSDBBasedExplorer(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxPSDBBasedExplorer(void);
	virtual bool __fastcall AreFieldNameMapsValid(void);
	virtual bool __fastcall CanCreateFolder(void);
	virtual bool __fastcall CanCreateItem(void);
	virtual Dxpscore::TdxPSExplorerFolder* __fastcall CreateNewFolder(Dxpscore::TdxPSExplorerFolder* AParent);
	virtual Dxpscore::TdxPSExplorerItem* __fastcall CreateNewItem(Dxpscore::TdxPSExplorerFolder* AParent, Dxpscore::TBasedxReportLink* AReportLink);
	virtual Dxpscore::TCustomdxPSExplorerItem* __fastcall FindCustomItemByUniqueID(const System::DynamicArray<System::Byte> AnUniqueID);
	virtual TdxPSDBBasedExplorerFolder* __fastcall FindFolderByID(int AnID);
	virtual TdxPSDBBasedExplorerItem* __fastcall FindItemByID(int AnID);
	HIDESBASE TdxPSDBBasedExplorerItem* __fastcall LoadedItem(void)/* overload */;
	__property TdxPSDBBasedExplorerFolder* Root = {read=GetRoot};
	
__published:
	__property Data::Db::TDataSet* Folders = {read=FFolders, write=SetFolders};
	__property TdxPSDBBasedExplorerFoldersFieldNamesMap* FoldersFieldNamesMap = {read=FFoldersFieldNamesMap, write=SetFoldersFieldNamesMap};
	__property Data::Db::TDataSet* Items = {read=FItems, write=SetItems};
	__property TdxPSDBBasedExplorerItemsFieldNamesMap* ItemsFieldNamesMap = {read=FItemsFieldNamesMap, write=SetItemsFieldNamesMap};
	__property TdxPSDBBasedExplorerLoadErrorEvent OnLoadError = {read=FOnLoadError, write=FOnLoadError};
};


//-- var, const, procedure ---------------------------------------------------
static const System::Int8 fnmBase = System::Int8(0x0);
static const System::Int8 fnmID = System::Int8(0x0);
static const System::Int8 fnmName = System::Int8(0x1);
static const System::Int8 fnmParentID = System::Int8(0x2);
static const System::Int8 fnmData = System::Int8(0x3);
}	/* namespace Dxpsdbbasedxplorer */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSDBBASEDXPLORER)
using namespace Dxpsdbbasedxplorer;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsdbbasedxplorerHPP
