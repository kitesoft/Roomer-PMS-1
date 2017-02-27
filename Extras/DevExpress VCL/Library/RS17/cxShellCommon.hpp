// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellCommon.pas' rev: 24.00 (Win32)

#ifndef CxshellcommonHPP
#define CxshellcommonHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.MaskUtils.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.Win.ComObj.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Winapi.ShellAPI.hpp>	// Pascal unit
#include <Winapi.ShlObj.hpp>	// Pascal unit
#include <System.SyncObjs.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------
#include <OleIdl.h>

namespace Cxshellcommon
{
//-- type declarations -------------------------------------------------------
typedef System::StaticArray<Winapi::Shlobj::PItemIDList, 536870911> ITEMIDLISTARRAY;

typedef ITEMIDLISTARRAY *PITEMIDLISTARRAY;

enum TcxBrowseFolder : unsigned char { bfCustomPath, bfAltStartup, bfBitBucket, bfCommonDesktopDirectory, bfCommonDocuments, bfCommonFavorites, bfCommonPrograms, bfCommonStartMenu, bfCommonStartup, bfCommonTemplates, bfControls, bfDesktop, bfDesktopDirectory, bfDrives, bfPrinters, bfFavorites, bfFonts, bfHistory, bfMyMusic, bfMyPictures, bfNetHood, bfProfile, bfProgramFiles, bfPrograms, bfRecent, bfStartMenu, bfStartUp, bfTemplates, bfMyDocuments, bfNetwork };

enum TcxDropEffect : unsigned char { deCopy, deMove, deLink };

typedef System::Set<TcxDropEffect, TcxDropEffect::deCopy, TcxDropEffect::deLink>  TcxDropEffectSet;

__interface IExtractImage;
typedef System::DelphiInterface<IExtractImage> _di_IExtractImage;
__interface  INTERFACE_UUID("{BB2E617C-0920-11D1-9A0B-00C04FC2D6C1}") IExtractImage  : public System::IInterface 
{
	
public:
	virtual HRESULT __stdcall GetLocation(System::WideChar * pszPathBuffer, unsigned cch, unsigned &pdwPriority, System::Types::TSize &prgSize, unsigned dwRecClrDepth, unsigned &pdwFlags) = 0 ;
	virtual HRESULT __stdcall Extract(HBITMAP &phBmpThumbnail) = 0 ;
};

__interface IShellItemImageFactory;
typedef System::DelphiInterface<IShellItemImageFactory> _di_IShellItemImageFactory;
__interface  INTERFACE_UUID("{BCC18B79-BA16-442F-80C4-8A59C30C463B}") IShellItemImageFactory  : public System::IInterface 
{
	
public:
	virtual HRESULT __stdcall GetImage(const System::Types::TSize size, unsigned flags, /* out */ HBITMAP &phbm) = 0 ;
};

__interface IcxDropSource;
typedef System::DelphiInterface<IcxDropSource> _di_IcxDropSource;
__interface  INTERFACE_UUID("{FCCB8EC5-ABB4-4256-B34C-25E3805EA046}") IcxDropSource  : public IDropSource 
{
	
};

class DELPHICLASS TcxDropSource;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxDropSource : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	Vcl::Controls::TWinControl* FOwner;
	
protected:
	HRESULT __stdcall QueryContinueDrag(BOOL fEscapePressed, int grfKeyState);
	HRESULT __stdcall GiveFeedback(int dwEffect);
	
public:
	__fastcall virtual TcxDropSource(Vcl::Controls::TWinControl* AOwner);
	__property Vcl::Controls::TWinControl* Owner = {read=FOwner};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxDropSource(void) { }
	
private:
	void *__IcxDropSource;	/* IcxDropSource */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {FCCB8EC5-ABB4-4256-B34C-25E3805EA046}
	operator _di_IcxDropSource()
	{
		_di_IcxDropSource intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxDropSource*(void) { return (IcxDropSource*)&__IcxDropSource; }
	#endif
	
};

#pragma pack(pop)

class DELPHICLASS TcxShellOptions;
class PASCALIMPLEMENTATION TcxShellOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FContextMenus;
	System::UnicodeString FFileMask;
	int FLock;
	System::Classes::TStringList* FMasks;
	Vcl::Controls::TWinControl* FOwner;
	bool FShowFolders;
	bool FShowToolTip;
	bool FShowNonFolders;
	bool FShowHidden;
	bool FTrackShellChanges;
	System::Classes::TNotifyEvent FOnShowToolTipChanged;
	void __fastcall NotifyUpdateContents(void);
	void __fastcall SetFileMask(const System::UnicodeString Value);
	void __fastcall SetShowFolders(bool Value);
	void __fastcall SetShowHidden(bool Value);
	void __fastcall SetShowNonFolders(bool Value);
	void __fastcall SetShowToolTip(bool Value);
	void __fastcall UpdateMasks(void);
	
protected:
	virtual void __fastcall DoNotifyUpdateContents(void);
	__property System::Classes::TNotifyEvent OnShowToolTipChanged = {read=FOnShowToolTipChanged, write=FOnShowToolTipChanged};
	
public:
	__fastcall virtual TcxShellOptions(Vcl::Controls::TWinControl* AOwner);
	__fastcall virtual ~TcxShellOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	unsigned __fastcall GetEnumFlags(void);
	bool __fastcall IsFileNameValid(const System::UnicodeString AName);
	__property System::UnicodeString FileMask = {read=FFileMask, write=SetFileMask};
	__property Vcl::Controls::TWinControl* Owner = {read=FOwner};
	
__published:
	__property bool ShowFolders = {read=FShowFolders, write=SetShowFolders, default=1};
	__property bool ShowNonFolders = {read=FShowNonFolders, write=SetShowNonFolders, default=1};
	__property bool ShowHidden = {read=FShowHidden, write=SetShowHidden, default=0};
	__property bool ContextMenus = {read=FContextMenus, write=FContextMenus, default=1};
	__property bool TrackShellChanges = {read=FTrackShellChanges, write=FTrackShellChanges, default=1};
	__property bool ShowToolTip = {read=FShowToolTip, write=SetShowToolTip, default=1};
};


class DELPHICLASS TcxShellThumbnailOptions;
class PASCALIMPLEMENTATION TcxShellThumbnailOptions : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	int FHeight;
	int FLock;
	System::Classes::TPersistent* FOwner;
	bool FShowThumbnails;
	int FWidth;
	System::Classes::TNotifyEvent FOnChange;
	void __fastcall SetHeight(const int Value);
	void __fastcall SetShowThumbnails(const bool Value);
	void __fastcall SetWidth(const int Value);
	
protected:
	void __fastcall Changed(void);
	void __fastcall DoChange(void);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TcxShellThumbnailOptions(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	
__published:
	__property int Height = {read=FHeight, write=SetHeight, default=96};
	__property bool ShowThumbnails = {read=FShowThumbnails, write=SetShowThumbnails, default=0};
	__property int Width = {read=FWidth, write=SetWidth, default=96};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxShellThumbnailOptions(void) { }
	
};


struct DECLSPEC_DRECORD TcxDetailItem
{
public:
	System::UnicodeString Text;
	int Width;
	System::Classes::TAlignment Alignment;
	int ID;
};


typedef TcxDetailItem *PcxDetailItem;

class DELPHICLASS TcxShellDetails;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxShellDetails : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	PcxDetailItem operator[](int Index) { return Item[Index]; }
	
private:
	System::Classes::TList* FItems;
	PcxDetailItem __fastcall GetItems(int Index);
	int __fastcall GetCount(void);
	
protected:
	__property System::Classes::TList* Items = {read=FItems};
	
public:
	__fastcall TcxShellDetails(void);
	__fastcall virtual ~TcxShellDetails(void);
	void __fastcall ProcessDetails(int ACharWidth, _di_IShellFolder AShellFolder, bool AFileSystem);
	void __fastcall Clear(void);
	PcxDetailItem __fastcall Add(void);
	void __fastcall Remove(PcxDetailItem Item);
	__property PcxDetailItem Item[int Index] = {read=GetItems/*, default*/};
	__property int Count = {read=GetCount, nodefault};
};

#pragma pack(pop)

enum TcxShellFolderAttribute : unsigned char { sfaGhosted, sfaHidden, sfaIsSlow, sfaLink, sfaReadOnly, sfaShare };

typedef System::Set<TcxShellFolderAttribute, TcxShellFolderAttribute::sfaGhosted, TcxShellFolderAttribute::sfaShare>  TcxShellFolderAttributes;

enum TcxShellFolderCapability : unsigned char { sfcCanCopy, sfcCanDelete, sfcCanLink, sfcCanMove, sfcCanRename, sfcDropTarget, sfcHasPropSheet };

typedef System::Set<TcxShellFolderCapability, TcxShellFolderCapability::sfcCanCopy, TcxShellFolderCapability::sfcHasPropSheet>  TcxShellFolderCapabilities;

enum TcxShellFolderProperty : unsigned char { sfpBrowsable, sfpCompressed, sfpEncrypted, sfpNewContent, sfpNonEnumerated, sfpRemovable };

typedef System::Set<TcxShellFolderProperty, TcxShellFolderProperty::sfpBrowsable, TcxShellFolderProperty::sfpRemovable>  TcxShellFolderProperties;

enum TcxShellFolderStorageCapability : unsigned char { sfscFileSysAncestor, sfscFileSystem, sfscFolder, sfscLink, sfscReadOnly, sfscStorage, sfscStorageAncestor, sfscStream };

typedef System::Set<TcxShellFolderStorageCapability, TcxShellFolderStorageCapability::sfscFileSysAncestor, TcxShellFolderStorageCapability::sfscStream>  TcxShellFolderStorageCapabilities;

class DELPHICLASS TcxShellFolder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxShellFolder : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	_ITEMIDLIST *FAbsolutePIDL;
	_di_IShellFolder FParentShellFolder;
	_ITEMIDLIST *FRelativePIDL;
	TcxShellFolderAttributes __fastcall GetAttributes(void);
	TcxShellFolderCapabilities __fastcall GetCapabilities(void);
	System::UnicodeString __fastcall GetDisplayName(void);
	bool __fastcall GetIsFolder(void);
	System::UnicodeString __fastcall GetPathName(void);
	TcxShellFolderProperties __fastcall GetProperties(void);
	unsigned __fastcall GetShellAttributes(unsigned ARequestedAttributes);
	_di_IShellFolder __fastcall GetShellFolder(void);
	TcxShellFolderStorageCapabilities __fastcall GetStorageCapabilities(void);
	bool __fastcall GetSubFolders(void);
	bool __fastcall HasShellAttribute(unsigned AAttribute)/* overload */;
	bool __fastcall HasShellAttribute(unsigned AAttributes, unsigned AAttribute)/* overload */;
	System::UnicodeString __fastcall InternalGetDisplayName(_di_IShellFolder AFolder, Winapi::Shlobj::PItemIDList APIDL, unsigned ANameType);
	
public:
	__fastcall TcxShellFolder(Winapi::Shlobj::PItemIDList AAbsolutePIDL);
	__fastcall virtual ~TcxShellFolder(void);
	__property TcxShellFolderAttributes Attributes = {read=GetAttributes, nodefault};
	__property TcxShellFolderCapabilities Capabilities = {read=GetCapabilities, nodefault};
	__property bool IsFolder = {read=GetIsFolder, nodefault};
	__property TcxShellFolderProperties Properties = {read=GetProperties, nodefault};
	__property TcxShellFolderStorageCapabilities StorageCapabilities = {read=GetStorageCapabilities, nodefault};
	__property bool SubFolders = {read=GetSubFolders, nodefault};
	__property Winapi::Shlobj::PItemIDList AbsolutePIDL = {read=FAbsolutePIDL};
	__property System::UnicodeString DisplayName = {read=GetDisplayName};
	__property _di_IShellFolder ParentShellFolder = {read=FParentShellFolder};
	__property System::UnicodeString PathName = {read=GetPathName};
	__property Winapi::Shlobj::PItemIDList RelativePIDL = {read=FRelativePIDL};
	__property _di_IShellFolder ShellFolder = {read=GetShellFolder};
};

#pragma pack(pop)

class DELPHICLASS TcxCustomShellRoot;
typedef void __fastcall (__closure *TcxRootChangedEvent)(System::TObject* Sender, TcxCustomShellRoot* Root);

class PASCALIMPLEMENTATION TcxCustomShellRoot : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	unsigned FAttributes;
	TcxBrowseFolder FBrowseFolder;
	System::WideString FCustomPath;
	TcxShellFolder* FFolder;
	bool FIsRootChecking;
	System::Classes::TPersistent* FOwner;
	HWND FParentWindow;
	_ITEMIDLIST *FPidl;
	int FRootChangingCount;
	_di_IShellFolder FShellFolder;
	bool FUpdating;
	bool FValid;
	TcxRootChangedEvent FOnFolderChanged;
	System::Classes::TNotifyEvent FOnSettingsChanged;
	void __fastcall SetBrowseFolder(TcxBrowseFolder Value);
	void __fastcall SetCustomPath(const System::WideString Value);
	void __fastcall SetPidl(const Winapi::Shlobj::PItemIDList Value);
	System::WideString __fastcall GetCurrentPath(void);
	void __fastcall UpdateFolder(void);
	
protected:
	virtual void __fastcall CheckRoot(void);
	void __fastcall DoSettingsChanged(void);
	virtual void __fastcall RootUpdated(void);
	__property System::Classes::TPersistent* Owner = {read=FOwner};
	__property HWND ParentWindow = {read=FParentWindow, nodefault};
	
public:
	__fastcall virtual TcxCustomShellRoot(System::Classes::TPersistent* AOwner, HWND AParentWindow);
	__fastcall virtual ~TcxCustomShellRoot(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	void __fastcall Update(TcxCustomShellRoot* ARoot);
	__property unsigned Attributes = {read=FAttributes, nodefault};
	__property System::WideString CurrentPath = {read=GetCurrentPath};
	__property TcxShellFolder* Folder = {read=FFolder};
	__property bool IsValid = {read=FValid, nodefault};
	__property Winapi::Shlobj::PItemIDList Pidl = {read=FPidl, write=SetPidl};
	__property _di_IShellFolder ShellFolder = {read=FShellFolder};
	__property TcxRootChangedEvent OnFolderChanged = {read=FOnFolderChanged, write=FOnFolderChanged};
	__property System::Classes::TNotifyEvent OnSettingsChanged = {read=FOnSettingsChanged, write=FOnSettingsChanged};
	
__published:
	__property TcxBrowseFolder BrowseFolder = {read=FBrowseFolder, write=SetBrowseFolder, default=11};
	__property System::WideString CustomPath = {read=FCustomPath, write=SetCustomPath};
};


class DELPHICLASS TcxShellItemInfo;
class DELPHICLASS TcxCustomItemProducer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxShellItemInfo : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FCanRename;
	void *FData;
	System::Classes::TStrings* FDetails;
	TcxShellFolder* FFolder;
	_ITEMIDLIST *FFullPIDL;
	bool FHasSubfolder;
	int FIconIndex;
	System::WideString FInfoTip;
	bool FInitialized;
	bool FIsDropTarget;
	bool FIsFilesystem;
	bool FIsFolder;
	bool FIsGhosted;
	bool FIsLink;
	bool FIsRemovable;
	bool FIsShare;
	TcxCustomItemProducer* FItemProducer;
	System::WideString FName;
	int FOpenIconIndex;
	int FOverlayIndex;
	_ITEMIDLIST *Fpidl;
	bool FProcessed;
	int FThumbnailIndex;
	bool FThumbnailUpdated;
	bool FThumbnailUpdating;
	bool FUpdated;
	bool FUpdating;
	int __fastcall GetItemIndex(void);
	
protected:
	__property bool Updating = {read=FUpdating, write=FUpdating, nodefault};
	
public:
	__fastcall virtual TcxShellItemInfo(TcxCustomItemProducer* AItemProducer, _di_IShellFolder AParentIFolder, Winapi::Shlobj::PItemIDList AParentPIDL, Winapi::Shlobj::PItemIDList APIDL, bool AFast);
	__fastcall virtual ~TcxShellItemInfo(void);
	void __fastcall CheckUpdate(_di_IShellFolder AShellFolder, Winapi::Shlobj::PItemIDList AFolderPidl, bool AFast);
	void __fastcall CheckInitialize(_di_IShellFolder AIFolder, Winapi::Shlobj::PItemIDList APIDL);
	void __fastcall FetchDetails(HWND wnd, _di_IShellFolder ShellFolder, TcxShellDetails* DetailsMap);
	void __fastcall CheckSubitems(_di_IShellFolder AParentIFolder, unsigned AEnumSettings);
	int __fastcall GetOverlayIndex(void);
	bool __fastcall HasThumbnail(void);
	void __fastcall SetNewPidl(_di_IShellFolder pFolder, Winapi::Shlobj::PItemIDList AFolderPidl, Winapi::Shlobj::PItemIDList APidl);
	void __fastcall UpdateThumbnail(void);
	__property bool CanRename = {read=FCanRename, nodefault};
	__property void * Data = {read=FData, write=FData};
	__property System::Classes::TStrings* Details = {read=FDetails};
	__property TcxShellFolder* Folder = {read=FFolder};
	__property Winapi::Shlobj::PItemIDList FullPIDL = {read=FFullPIDL};
	__property bool HasSubfolder = {read=FHasSubfolder, nodefault};
	__property int IconIndex = {read=FIconIndex, nodefault};
	__property System::WideString InfoTip = {read=FInfoTip};
	__property bool Initialized = {read=FInitialized, nodefault};
	__property bool IsDropTarget = {read=FIsDropTarget, nodefault};
	__property bool IsFilesystem = {read=FIsFilesystem, nodefault};
	__property bool IsFolder = {read=FIsFolder, nodefault};
	__property bool IsGhosted = {read=FIsGhosted, nodefault};
	__property bool IsLink = {read=FIsLink, nodefault};
	__property bool IsRemovable = {read=FIsRemovable, nodefault};
	__property bool IsShare = {read=FIsShare, nodefault};
	__property int ItemIndex = {read=GetItemIndex, nodefault};
	__property TcxCustomItemProducer* ItemProducer = {read=FItemProducer};
	__property System::WideString Name = {read=FName};
	__property int OpenIconIndex = {read=FOpenIconIndex, nodefault};
	__property int OverlayIndex = {read=FOverlayIndex, nodefault};
	__property Winapi::Shlobj::PItemIDList pidl = {read=Fpidl};
	__property bool Processed = {read=FProcessed, write=FProcessed, nodefault};
	__property int ThumbnailIndex = {read=FThumbnailIndex, nodefault};
	__property bool ThumbnailUpdated = {read=FThumbnailUpdated, nodefault};
	__property bool Updated = {read=FUpdated, write=FUpdated, nodefault};
};

#pragma pack(pop)

typedef TcxShellItemInfo PcxShellItemInfo;

class DELPHICLASS TFetchThread;
class DELPHICLASS TcxShellItemsInfoGatherer;
class PASCALIMPLEMENTATION TFetchThread : public Cxclasses::TcxCustomThread
{
	typedef Cxclasses::TcxCustomThread inherited;
	
private:
	TcxShellItemsInfoGatherer* FInfoGatherer;
	void __fastcall LockStopFetch(void);
	void __fastcall UnlockStopFetch(void);
	
protected:
	virtual void __fastcall Execute(void);
	
public:
	__fastcall TFetchThread(TcxShellItemsInfoGatherer* AInfoGatherer);
	__fastcall virtual ~TFetchThread(void);
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxShellItemsInfoGatherer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Cxclasses::TcxEvent* FQueuePopulated;
	System::Classes::TThreadList* FFetchQueue;
	TFetchThread* FFetchThread;
	bool FIsFetchQueueClearing;
	_RTL_CRITICAL_SECTION FLockFetchThread;
	Vcl::Controls::TWinControl* FOwner;
	System::Classes::TThreadList* FProcessedItems;
	int FStopFetchCount;
	void __fastcall CreateFetchThread(void);
	void __fastcall StartRequest(void);
	
protected:
	void __fastcall DestroyFetchThread(void);
	void __fastcall LockFetchThread(void);
	void __fastcall UnlockFetchThread(void);
	void __fastcall WaitForRequest(void);
	__property System::Classes::TThreadList* FetchQueue = {read=FFetchQueue};
	
public:
	__fastcall TcxShellItemsInfoGatherer(Vcl::Controls::TWinControl* AOwner);
	__fastcall virtual ~TcxShellItemsInfoGatherer(void);
	void __fastcall ClearFetchQueue(TcxCustomItemProducer* AItemProducer);
	void __fastcall ClearVisibleItems(void);
	void __fastcall RequestItemInfo(TcxShellItemInfo* AItem);
	void __fastcall RequestItems(System::Classes::TList* AItems);
	void __fastcall ResumeFetch(void);
	void __fastcall StopFetch(void);
	__property System::Classes::TThreadList* ProcessedItems = {read=FProcessedItems};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxCustomItemProducer : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxShellDetails* FDetails;
	_ITEMIDLIST *FFolderPidl;
	System::Classes::TList* FItems;
	System::Sysutils::TMultiReadExclusiveWriteSynchronizer* FItemsLock;
	Vcl::Controls::TWinControl* FOwner;
	_di_IShellFolder FShellFolder;
	int FSortColumn;
	bool FSortDescending;
	Winapi::Shlobj::PItemIDList __fastcall GetFolderPidl(void);
	void __fastcall SetFolderPidl(Winapi::Shlobj::PItemIDList AValue);
	
protected:
	virtual bool __fastcall CanAddFolder(TcxShellFolder* AFolder);
	TcxShellItemInfo* __fastcall CreateShellItemInfo(Winapi::Shlobj::PItemIDList APidl, bool AFast);
	virtual void __fastcall DoSlowInitialization(TcxShellItemInfo* AItem) = 0 ;
	virtual bool __fastcall DoCompareItems(TcxShellFolder* AItem1, TcxShellFolder* AItem2, /* out */ int &ACompare);
	virtual void __fastcall DoDestroy(void);
	virtual void __fastcall DoSort(void);
	bool __fastcall EnumerateItems(void);
	void __fastcall FetchItems(int APreloadItems);
	bool __fastcall GetEnumerator(/* out */ _di_IEnumIDList &pEnum);
	virtual unsigned __fastcall GetEnumFlags(void) = 0 ;
	virtual TcxShellItemsInfoGatherer* __fastcall GetItemsInfoGatherer(void);
	virtual bool __fastcall GetShowToolTip(void) = 0 ;
	virtual int __fastcall GetThumbnailIndex(TcxShellItemInfo* AItem);
	void __fastcall Initialize(_di_IShellFolder AIFolder, Winapi::Shlobj::PItemIDList AFolderPIDL);
	virtual void __fastcall InitializeItem(TcxShellItemInfo* AItem);
	TcxShellItemInfo* __fastcall InternalAddItem(Winapi::Shlobj::PItemIDList APidl);
	virtual void __fastcall CheckForSubitems(TcxShellItemInfo* AItem);
	void __fastcall ClearFetchQueue(void);
	void __fastcall PopulateItems(_di_IEnumIDList pEnum);
	virtual bool __fastcall SlowInitializationDone(TcxShellItemInfo* AItem) = 0 ;
	__property System::Sysutils::TMultiReadExclusiveWriteSynchronizer* ItemsLock = {read=FItemsLock};
	__property _di_IShellFolder ShellFolder = {read=FShellFolder};
	__property int SortColumn = {read=FSortColumn, write=FSortColumn, nodefault};
	__property bool SortDescending = {read=FSortDescending, write=FSortDescending, nodefault};
	__property Winapi::Shlobj::PItemIDList FolderPidl = {read=GetFolderPidl, write=SetFolderPidl};
	__property Vcl::Controls::TWinControl* Owner = {read=FOwner};
	
public:
	__fastcall virtual TcxCustomItemProducer(Vcl::Controls::TWinControl* AOwner);
	__fastcall virtual ~TcxCustomItemProducer(void);
	virtual void __fastcall ProcessItems(_di_IShellFolder AIFolder, Winapi::Shlobj::PItemIDList AFolderPIDL, int APreloadItemCount);
	virtual void __fastcall ProcessDetails(_di_IShellFolder ShellFolder, int CharWidth);
	void __fastcall FetchRequest(TcxShellItemInfo* AItem);
	void __fastcall ClearItems(void);
	void __fastcall LockRead(void);
	void __fastcall LockWrite(void);
	void __fastcall UnlockRead(void);
	void __fastcall UnlockWrite(void);
	virtual void __fastcall SetItemsCount(int Count);
	virtual void __fastcall NotifyRemoveItem(int Index);
	virtual void __fastcall NotifyAddItem(int Index);
	void __fastcall DoGetInfoTip(HWND Handle, int ItemIndex, System::WideChar * InfoTip, int cch);
	TcxShellItemInfo* __fastcall GetItemByPidl(Winapi::Shlobj::PItemIDList APidl);
	int __fastcall GetItemIndexByPidl(Winapi::Shlobj::PItemIDList APidl);
	void __fastcall Sort(void);
	__property TcxShellDetails* Details = {read=FDetails};
	__property System::Classes::TList* Items = {read=FItems};
	__property TcxShellItemsInfoGatherer* ItemsInfoGatherer = {read=GetItemsInfoGatherer};
};

#pragma pack(pop)

class DELPHICLASS TcxDragDropSettings;
class PASCALIMPLEMENTATION TcxDragDropSettings : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	bool FAllowDragObjects;
	TcxDropEffect FDefaultDropEffect;
	TcxDropEffectSet FDropEffect;
	bool FScroll;
	System::Classes::TNotifyEvent FOnChange;
	int __fastcall GetDefaultDropEffectAPI(void);
	unsigned __fastcall GetDropEffectAPI(void);
	void __fastcall SetAllowDragObjects(bool Value);
	
protected:
	void __fastcall Changed(void);
	
public:
	__property unsigned DropEffectAPI = {read=GetDropEffectAPI, nodefault};
	__property int DefaultDropEffectAPI = {read=GetDefaultDropEffectAPI, nodefault};
	__fastcall TcxDragDropSettings(void);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
	
__published:
	__property bool AllowDragObjects = {read=FAllowDragObjects, write=SetAllowDragObjects, default=1};
	__property TcxDropEffect DefaultDropEffect = {read=FDefaultDropEffect, write=FDefaultDropEffect, default=1};
	__property TcxDropEffectSet DropEffect = {read=FDropEffect, write=FDropEffect, default=7};
	__property bool Scroll = {read=FScroll, write=FScroll, stored=false, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxDragDropSettings(void) { }
	
};


#pragma pack(push,1)
struct DECLSPEC_DRECORD TShChangeNotifyEntry
{
public:
	_ITEMIDLIST *pidlPath;
	BOOL bWatchSubtree;
};
#pragma pack(pop)


struct DECLSPEC_DRECORD DWORDITEMID
{
public:
	short cb;
	unsigned dwItem1;
	unsigned dwItem2;
};


typedef DWORDITEMID *PDWORDITEMID;

typedef TShChangeNotifyEntry *PShChangeNotifyEntry;

typedef System::StaticArray<Winapi::Shlobj::PItemIDList, 2> TPidlList;

typedef TPidlList *PPidlList;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _SShellDefaultNameStr;
#define Cxshellcommon_SShellDefaultNameStr System::LoadResourceString(&Cxshellcommon::_SShellDefaultNameStr)
extern PACKAGE System::ResourceString _SShellDefaultSizeStr;
#define Cxshellcommon_SShellDefaultSizeStr System::LoadResourceString(&Cxshellcommon::_SShellDefaultSizeStr)
extern PACKAGE System::ResourceString _SShellDefaultTypeStr;
#define Cxshellcommon_SShellDefaultTypeStr System::LoadResourceString(&Cxshellcommon::_SShellDefaultTypeStr)
extern PACKAGE System::ResourceString _SShellDefaultModifiedStr;
#define Cxshellcommon_SShellDefaultModifiedStr System::LoadResourceString(&Cxshellcommon::_SShellDefaultModifiedStr)
#define cxShellObjectInternalAbsoluteVirtualPathPrefix L"::{9C211B58-E6F1-456A-9F22-7B3B418A7BB1}"
#define cxShellObjectInternalRelativeVirtualPathPrefix L"::{63BE9ADB-E4B5-4623-96AA-57440B4EF5A8}"
static const System::Int8 cxShellObjectInternalVirtualPathPrefixLength = System::Int8(0x28);
static const System::Int8 cxShellNormalItemOverlayIndex = System::Int8(-1);
static const System::Int8 cxShellSharedItemOverlayIndex = System::Int8(0x0);
static const System::Int8 cxShellShortcutItemOverlayIndex = System::Int8(0x1);
#define SID_IImageList L"{46EB5926-582E-4017-9FDF-E8998DAA0950}"
extern PACKAGE GUID IID_IImageList;
extern PACKAGE GUID CLSID_ShellItem;
static const System::Word cxSFGAO_GHOSTED = System::Word(0x8000);
static const System::Word DSM_SETCOUNT = System::Word(0xb13b);
static const System::Word DSM_NOTIFYUPDATE = System::Word(0xb13c);
static const System::Word DSM_NOTIFYREMOVEITEM = System::Word(0xb13e);
static const System::Word DSM_NOTIFYADDITEM = System::Word(0xb13f);
static const System::Word DSM_NOTIFYUPDATECONTENTS = System::Word(0xb140);
static const System::Word DSM_SHELLCHANGENOTIFY = System::Word(0xb141);
static const System::Word DSM_DONAVIGATE = System::Word(0xb142);
static const System::Word DSM_SYNCHRONIZEROOT = System::Word(0xb143);
static const System::Word DSM_SHELLTREECHANGENOTIFY = System::Word(0xb144);
static const System::Word DSM_SHELLTREERESTORECURRENTPATH = System::Word(0xb145);
static const System::Word DSM_SYSTEMSHELLCHANGENOTIFY = System::Word(0xb146);
static const System::Word DSM_FIRST = System::Word(0xb13b);
static const System::Word DSM_LAST = System::Word(0xb146);
static const System::Int8 PRELOAD_ITEMS_COUNT = System::Int8(0xa);
static const System::Int8 SHCNF_ACCEPT_INTERRUPTS = System::Int8(0x1);
static const System::Int8 SHCNF_ACCEPT_NON_INTERRUPTS = System::Int8(0x2);
static const System::Word SHCNF_NO_PROXY = System::Word(0x8000);
extern PACKAGE unsigned __stdcall (*SHChangeNotifyRegister)(HWND hwnd, unsigned dwFlags, unsigned wEventMask, unsigned uMsg, unsigned cItems, PShChangeNotifyEntry lpItems);
extern PACKAGE bool __stdcall (*SHChangeNotifyUnregister)(unsigned hNotify);
extern PACKAGE unsigned __stdcall (*SHChangeNotification_Lock)(unsigned hChange, unsigned dwProcId, PPidlList &PPidls, int &plEvent);
extern PACKAGE BOOL __stdcall (*SHChangeNotification_UnLock)(unsigned hLock);
extern PACKAGE HRESULT __stdcall (*SHGetImageList)(int iImageList, const GUID &riid, /* out */ void *ppv);
extern PACKAGE void __fastcall CheckShellRoot(TcxCustomShellRoot* ARoot);
extern PACKAGE System::WideString __fastcall GetShellItemDisplayName(_di_IShellFolder AIFolder, Winapi::Shlobj::PItemIDList APIDL, bool ACheckIsFolder);
extern PACKAGE unsigned __stdcall cxShellGetThreadSafeFileInfo(System::WideChar * pszPath, unsigned dwFileAttributes, _SHFILEINFOW &psfi, unsigned cbFileInfo, unsigned uFlags);
extern PACKAGE bool __fastcall HasSubItems(_di_IShellFolder AParentIFolder, Winapi::Shlobj::PItemIDList AFullPIDL, unsigned AEnumSettings);
extern PACKAGE _di_IShellFolder __fastcall GetDesktopIShellFolder(void);
extern PACKAGE System::WideString __fastcall GetTextFromStrRet(_STRRET &AStrRet, Winapi::Shlobj::PItemIDList APIDL);
extern PACKAGE HRESULT __fastcall GetShellDetails(_di_IShellFolder pFolder, Winapi::Shlobj::PItemIDList pidl, /* out */ _di_IShellDetails &sd);
extern PACKAGE HRESULT __fastcall cxGetFolderLocation(HWND AWnd, int ACSIDL, NativeUInt AToken, unsigned AReserwed, Winapi::Shlobj::PItemIDList &APIDL);
extern PACKAGE System::TDateTime __fastcall cxFileTimeToDateTime(const _FILETIME &fTime);
extern PACKAGE _di_IMalloc __fastcall cxMalloc(void);
extern PACKAGE void __fastcall DisplayContextMenu(HWND AWnd, _di_IShellFolder AIFolder, System::Classes::TList* AItemPIDLList, const System::Types::TPoint &APos);
extern PACKAGE System::WideString __fastcall UpperCaseW(System::WideString Source);
extern PACKAGE System::WideString __fastcall LowerCaseW(System::WideString Source);
extern PACKAGE unsigned __fastcall StrLenW(System::WideChar * Source);
extern PACKAGE System::WideString __fastcall StrPasW(System::WideChar * Source);
extern PACKAGE void __fastcall StrPLCopyW(System::WideChar * Dest, System::WideString Source, unsigned MaxLen);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall GetPidlParent(Winapi::Shlobj::PItemIDList APidl);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall CreateEmptyPidl(void);
extern PACKAGE PITEMIDLISTARRAY __fastcall CreatePidlArrayFromList(System::Classes::TList* AList);
extern PACKAGE void __fastcall DisposePidlArray(PITEMIDLISTARRAY APidls);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall ExtractParticularPidl(Winapi::Shlobj::PItemIDList APidl);
extern PACKAGE bool __fastcall EqualPIDLs(Winapi::Shlobj::PItemIDList APIDL1, Winapi::Shlobj::PItemIDList APIDL2);
extern PACKAGE bool __fastcall IsSubPath(Winapi::Shlobj::PItemIDList APIDL1, Winapi::Shlobj::PItemIDList APIDL2);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall ConcatenatePidls(Winapi::Shlobj::PItemIDList APidl1, Winapi::Shlobj::PItemIDList APidl2);
extern PACKAGE System::WideString __fastcall GetPidlName(Winapi::Shlobj::PItemIDList APIDL);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall GetLastPidlItem(Winapi::Shlobj::PItemIDList APidl);
extern PACKAGE void __fastcall DisposePidl(Winapi::Shlobj::PItemIDList APidl);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall GetPidlCopy(Winapi::Shlobj::PItemIDList APidl);
extern PACKAGE int __fastcall GetPidlItemsCount(Winapi::Shlobj::PItemIDList APidl);
extern PACKAGE int __fastcall GetPidlSize(Winapi::Shlobj::PItemIDList APidl);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall GetNextItemID(Winapi::Shlobj::PItemIDList APidl);
}	/* namespace Cxshellcommon */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLCOMMON)
using namespace Cxshellcommon;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshellcommonHPP
