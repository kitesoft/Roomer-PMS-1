// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSFileBasedXplorer.pas' rev: 24.00 (Win32)

#ifndef DxpsfilebasedxplorerHPP
#define DxpsfilebasedxplorerHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxPSGlbl.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfilebasedxplorer
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxPSFileBasedExplorerFolder;
class DELPHICLASS TdxPSFileBasedExplorerItem;
class DELPHICLASS TdxPSFileBasedExplorer;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFileBasedExplorerFolder : public Dxpscore::TdxPSExplorerFolder
{
	typedef Dxpscore::TdxPSExplorerFolder inherited;
	
public:
	TdxPSFileBasedExplorerFolder* operator[](int Index) { return Folders[Index]; }
	
private:
	HIDESBASE TdxPSFileBasedExplorerFolder* __fastcall GetFolder(int Index);
	System::UnicodeString __fastcall GetFullQualifiedDirName(void);
	System::UnicodeString __fastcall GetFullQualifiedDirPath(void);
	bool __fastcall GetIsVolume(void);
	HIDESBASE TdxPSFileBasedExplorerItem* __fastcall GetItem(int Index);
	
protected:
	virtual bool __fastcall DoDelete(void);
	virtual bool __fastcall DoMove(Dxpscore::TdxPSExplorerFolder* AParent);
	virtual bool __fastcall DoRename(System::UnicodeString &ANewName);
	virtual System::UnicodeString __fastcall GetDirName(void);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	
public:
	virtual System::UnicodeString __fastcall CannotRenameMessageText(const System::UnicodeString AOldName, const System::UnicodeString ANewName);
	virtual bool __fastcall CanMoveTo(Dxpscore::TCustomdxPSExplorerItem* AParent)/* overload */;
	virtual bool __fastcall CanRenameTo(const System::UnicodeString AName);
	HIDESBASE TdxPSFileBasedExplorer* __fastcall Explorer(void)/* overload */;
	virtual int __fastcall GetUniqueID(/* out */ System::DynamicArray<System::Byte> &AnUniqueID);
	virtual Dxpscore::TdxPSExplorerItem* __fastcall ItemByName(const System::UnicodeString AName);
	TdxPSFileBasedExplorerFolder* __fastcall FindFolderByFullQualifiedDirName(const System::UnicodeString AFullQualifiedDirName);
	TdxPSFileBasedExplorerItem* __fastcall FindItemByFullQualifiedFileName(const System::UnicodeString AFullQualifiedName);
	__property System::UnicodeString DirName = {read=GetDirName};
	__property TdxPSFileBasedExplorerFolder* Folders[int Index] = {read=GetFolder/*, default*/};
	__property System::UnicodeString FullQualifiedDirName = {read=GetFullQualifiedDirName};
	__property System::UnicodeString FullQualifiedDirPath = {read=GetFullQualifiedDirPath};
	__property bool IsVolume = {read=GetIsVolume, nodefault};
	__property TdxPSFileBasedExplorerItem* Items[int Index] = {read=GetItem};
public:
	/* TdxPSExplorerFolder.Create */ inline __fastcall virtual TdxPSFileBasedExplorerFolder(Dxpscore::TCustomdxPSExplorer* AnExplorer, Dxpscore::TdxPSExplorerFolder* AParent) : Dxpscore::TdxPSExplorerFolder(AnExplorer, AParent) { }
	/* TdxPSExplorerFolder.Destroy */ inline __fastcall virtual ~TdxPSFileBasedExplorerFolder(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSFileBasedExplorerRootFolder;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFileBasedExplorerRootFolder : public TdxPSFileBasedExplorerFolder
{
	typedef TdxPSFileBasedExplorerFolder inherited;
	
private:
	Dxpsglbl::TdxDriveType __fastcall GetDriveType(void);
	System::UnicodeString __fastcall GetVolumeLabel(void);
	
protected:
	virtual int __fastcall GetImageIndex(void);
	virtual int __fastcall GetSelectedIndex(void);
	
public:
	__property System::UnicodeString VolumeLabel = {read=GetVolumeLabel};
	__property Dxpsglbl::TdxDriveType DriveType = {read=GetDriveType, nodefault};
public:
	/* TdxPSExplorerFolder.Create */ inline __fastcall virtual TdxPSFileBasedExplorerRootFolder(Dxpscore::TCustomdxPSExplorer* AnExplorer, Dxpscore::TdxPSExplorerFolder* AParent) : TdxPSFileBasedExplorerFolder(AnExplorer, AParent) { }
	/* TdxPSExplorerFolder.Destroy */ inline __fastcall virtual ~TdxPSFileBasedExplorerRootFolder(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFileBasedExplorerItem : public Dxpscore::TdxPSExplorerItem
{
	typedef Dxpscore::TdxPSExplorerItem inherited;
	
private:
	bool FIsIOOutwardlyControlled;
	System::UnicodeString __fastcall GetFullQualifiedFileName(void);
	System::UnicodeString __fastcall GetFullQualifiedFilePath(void);
	
protected:
	System::UnicodeString __fastcall AcquireExtension(const System::UnicodeString AName);
	System::UnicodeString __fastcall SuppressExtension(const System::UnicodeString AName);
	virtual bool __fastcall DoDelete(void);
	virtual bool __fastcall DoMove(Dxpscore::TdxPSExplorerFolder* AParent);
	virtual bool __fastcall DoRename(System::UnicodeString &ANewName);
	virtual System::UnicodeString __fastcall GetDisplayName(void);
	virtual System::UnicodeString __fastcall GetFileName(void);
	virtual __int64 __fastcall GetFileSize(void);
	virtual System::UnicodeString __fastcall GetFormCaption(void);
	virtual System::UnicodeString __fastcall GetInfoTip(void);
	virtual System::UnicodeString __fastcall GetNewName(Dxpscore::TBasedxReportLink* AReportLink);
	virtual void __fastcall SetName(const System::UnicodeString Value);
	__property bool IsIOOutwardlyControlled = {read=FIsIOOutwardlyControlled, write=FIsIOOutwardlyControlled, nodefault};
	
public:
	virtual System::UnicodeString __fastcall CannotRenameMessageText(const System::UnicodeString AOldName, const System::UnicodeString ANewName);
	virtual bool __fastcall CanMoveTo(Dxpscore::TCustomdxPSExplorerItem* AParent)/* overload */;
	virtual bool __fastcall CanRenameTo(const System::UnicodeString AName);
	virtual System::UnicodeString __fastcall DataLoadErrorText(void);
	HIDESBASE TdxPSFileBasedExplorer* __fastcall Explorer(void)/* overload */;
	virtual int __fastcall GetUniqueID(/* out */ System::DynamicArray<System::Byte> &AnUniqueID);
	virtual bool __fastcall IsNameChanged(const System::UnicodeString ANewName);
	__property System::UnicodeString FileName = {read=GetFileName};
	__property __int64 FileSize = {read=GetFileSize};
	__property System::UnicodeString FullQualifiedFileName = {read=GetFullQualifiedFileName};
	__property System::UnicodeString FullQualifiedFilePath = {read=GetFullQualifiedFilePath};
public:
	/* TdxPSExplorerItem.Create */ inline __fastcall virtual TdxPSFileBasedExplorerItem(Dxpscore::TCustomdxPSExplorer* AnExplorer, Dxpscore::TdxPSExplorerFolder* AParent) : Dxpscore::TdxPSExplorerItem(AnExplorer, AParent) { }
	/* TdxPSExplorerItem.Destroy */ inline __fastcall virtual ~TdxPSFileBasedExplorerItem(void) { }
	
};

#pragma pack(pop)

typedef System::TMetaClass* TdxPSFileBasedExplorerContextCommandClass;

class DELPHICLASS TdxPSFileBasedExplorerContextCommand;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFileBasedExplorerContextCommand : public Dxpscore::TCustomdxPSExplorerContextCommand
{
	typedef Dxpscore::TCustomdxPSExplorerContextCommand inherited;
	
public:
	HIDESBASE TdxPSFileBasedExplorer* __fastcall Explorer(void)/* overload */;
public:
	/* TCustomdxPSExplorerContextCommand.Create */ inline __fastcall virtual TdxPSFileBasedExplorerContextCommand(Dxpscore::TCustomdxPSExplorer* AnExplorer) : Dxpscore::TCustomdxPSExplorerContextCommand(AnExplorer) { }
	/* TCustomdxPSExplorerContextCommand.Destroy */ inline __fastcall virtual ~TdxPSFileBasedExplorerContextCommand(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSFileBasedExplorerSetAsRootContextCommand;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFileBasedExplorerSetAsRootContextCommand : public TdxPSFileBasedExplorerContextCommand
{
	typedef TdxPSFileBasedExplorerContextCommand inherited;
	
public:
	__fastcall virtual TdxPSFileBasedExplorerSetAsRootContextCommand(Dxpscore::TCustomdxPSExplorer* AnExplorer);
	virtual bool __fastcall Enabled(void);
	virtual void __fastcall Execute(void);
public:
	/* TCustomdxPSExplorerContextCommand.Destroy */ inline __fastcall virtual ~TdxPSFileBasedExplorerSetAsRootContextCommand(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSFileBasedExplorerChangeRootContextCommand;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFileBasedExplorerChangeRootContextCommand : public TdxPSFileBasedExplorerContextCommand
{
	typedef TdxPSFileBasedExplorerContextCommand inherited;
	
public:
	__fastcall virtual TdxPSFileBasedExplorerChangeRootContextCommand(Dxpscore::TCustomdxPSExplorer* AnExplorer);
	virtual bool __fastcall Enabled(void);
	virtual void __fastcall Execute(void);
public:
	/* TCustomdxPSExplorerContextCommand.Destroy */ inline __fastcall virtual ~TdxPSFileBasedExplorerChangeRootContextCommand(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxPSFileBasedExplorerGoToUpOneLevelContextCommand;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxPSFileBasedExplorerGoToUpOneLevelContextCommand : public TdxPSFileBasedExplorerContextCommand
{
	typedef TdxPSFileBasedExplorerContextCommand inherited;
	
public:
	__fastcall virtual TdxPSFileBasedExplorerGoToUpOneLevelContextCommand(Dxpscore::TCustomdxPSExplorer* AnExplorer);
	virtual bool __fastcall Enabled(void);
	virtual void __fastcall Execute(void);
public:
	/* TCustomdxPSExplorerContextCommand.Destroy */ inline __fastcall virtual ~TdxPSFileBasedExplorerGoToUpOneLevelContextCommand(void) { }
	
};

#pragma pack(pop)

typedef void __fastcall (__closure *TdxPSFileBasedExplorerLoadErrorEvent)(TdxPSFileBasedExplorer* Sender, const System::UnicodeString AName);

enum TdxPSFileBasedExplorerOption : unsigned char { eoLoadAll, eoShowIOErrors, eoStoreToRegistry };

typedef System::Set<TdxPSFileBasedExplorerOption, TdxPSFileBasedExplorerOption::eoLoadAll, TdxPSFileBasedExplorerOption::eoStoreToRegistry>  TdxPSFileBasedExplorerOptions;

class PASCALIMPLEMENTATION TdxPSFileBasedExplorer : public Dxpscore::TCustomdxPSExplorer
{
	typedef Dxpscore::TCustomdxPSExplorer inherited;
	
private:
	int FIOLockCounter;
	System::Word FIOStatus;
	System::UnicodeString FLastLoadedFileName;
	TdxPSFileBasedExplorerOptions FOptions;
	System::UnicodeString FRootPath;
	TdxPSFileBasedExplorerLoadErrorEvent FOnLoadError;
	TdxPSFileBasedExplorerFolder* __fastcall GetActiveFolder(void);
	System::UnicodeString __fastcall GetActiveFolderPath(void);
	System::UnicodeString __fastcall GetRealRootPath(void);
	HIDESBASE TdxPSFileBasedExplorerRootFolder* __fastcall GetRoot(void);
	void __fastcall SetActiveFolder(TdxPSFileBasedExplorerFolder* Value);
	void __fastcall SetOptions(TdxPSFileBasedExplorerOptions Value);
	void __fastcall SetRootPath(const System::UnicodeString Value);
	
protected:
	virtual void __fastcall Loaded(void);
	void __fastcall LoadDefaultRegistry(void);
	void __fastcall SaveDefaultRegistry(void);
	virtual void __fastcall BuildCommandSet(Dxpscore::_di_IdxPSExplorerContextCommandBuilder ABuilder);
	virtual void __fastcall FinalizeCommand(Dxpscore::TCustomdxPSExplorerContextCommand* ACommand);
	virtual void __fastcall InitializeCommand(Dxpscore::TCustomdxPSExplorerContextCommand* ACommand);
	__classmethod virtual bool __fastcall AcceptItemNameChar(Dxpscore::TCustomdxPSExplorerItem* AnItem, System::WideChar Ch);
	System::UnicodeString __fastcall AcquireExtension(const System::UnicodeString AName);
	System::UnicodeString __fastcall SuppressExtension(const System::UnicodeString AName);
	void __fastcall CreateAndCloseFile(const System::UnicodeString AName);
	System::Classes::TStream* __fastcall CreateDataStream(const System::UnicodeString AFileName, Dxpscore::TdxPSStreamMode AMode);
	virtual System::Classes::TStream* __fastcall CreateItemDataStream(Dxpscore::TdxPSExplorerItem* AnItem, Dxpscore::TdxPSStreamMode AMode);
	virtual void __fastcall DoLoadData(Dxpscore::TdxPSExplorerFolder* AFolder);
	DYNAMIC void __fastcall DoLoadError(const System::UnicodeString AName);
	virtual void __fastcall RestoreLoadedItem(void);
	virtual void __fastcall SaveLoadedItem(void);
	__classmethod virtual Dxpscore::TdxPSExplorerFolderClass __fastcall GetFolderClass();
	__classmethod virtual Dxpscore::TdxPSExplorerItemClass __fastcall GetItemClass();
	__classmethod virtual Dxpscore::TdxPSExplorerFolderClass __fastcall GetRootFolderClass();
	virtual System::UnicodeString __fastcall GetRootDisplayName(void);
	virtual void __fastcall MoveTo(Dxpscore::TCustomdxPSExplorerItem* AnItem, Dxpscore::TdxPSExplorerFolder* AParent);
	void __fastcall BeginIO(void);
	void __fastcall EndIO(void);
	void __fastcall CheckIOError(bool AnIOResult);
	virtual void __fastcall ProcessIOError(bool AnUnconditionalRaiseException = false);
	__property System::Word IOStatus = {read=FIOStatus, write=FIOStatus, nodefault};
	
public:
	__fastcall virtual TdxPSFileBasedExplorer(System::Classes::TComponent* AOwner);
	virtual void __fastcall BeforeDestruction(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection)/* overload */;
	void __fastcall LoadFromIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall LoadFromRegistry(const System::UnicodeString APath);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASection)/* overload */;
	void __fastcall SaveToIniFile(const System::UnicodeString AFileName)/* overload */;
	void __fastcall SaveToRegistry(const System::UnicodeString APath);
	__classmethod virtual System::UnicodeString __fastcall FileExtension();
	void __fastcall PopulatePath(System::UnicodeString APath);
	virtual Dxpscore::TdxPSExplorerFolder* __fastcall CreateNewFolder(Dxpscore::TdxPSExplorerFolder* AParent);
	virtual Dxpscore::TdxPSExplorerItem* __fastcall CreateNewItem(Dxpscore::TdxPSExplorerFolder* AParent, Dxpscore::TBasedxReportLink* AReportLink);
	virtual Dxpscore::TCustomdxPSExplorerItem* __fastcall FindCustomItemByUniqueID(const System::DynamicArray<System::Byte> AnUniqueID);
	TdxPSFileBasedExplorerFolder* __fastcall FindFolderByFullQualifiedDirName(const System::UnicodeString AFullQualifiedDirName);
	TdxPSFileBasedExplorerItem* __fastcall FindItemByFullQualifiedFileName(const System::UnicodeString AFullQualifiedName);
	HIDESBASE TdxPSFileBasedExplorerItem* __fastcall LoadedItem(void)/* overload */;
	HIDESBASE void __fastcall LoadItemData(const System::UnicodeString AFullQualifiedFileName, Dxpscore::TBasedxReportLink* AReportLink)/* overload */;
	HIDESBASE void __fastcall UnloadItemData(const System::UnicodeString AFullQualifiedFileName)/* overload */;
	virtual bool __fastcall CanGoToUpOneLevel(void);
	bool __fastcall ShowChangeRootPathDlg(void);
	void __fastcall GoToUpOneLevel(void);
	virtual bool __fastcall CanSetActiveFolderAsRoot(void);
	void __fastcall SetActiveFolderAsRoot(void);
	__property TdxPSFileBasedExplorerFolder* ActiveFolder = {read=GetActiveFolder, write=SetActiveFolder};
	__property System::UnicodeString ActiveFolderPath = {read=GetActiveFolderPath};
	__property System::UnicodeString RealRootPath = {read=GetRealRootPath};
	__property TdxPSFileBasedExplorerRootFolder* Root = {read=GetRoot};
	
__published:
	__property TdxPSFileBasedExplorerOptions Options = {read=FOptions, write=SetOptions, default=2};
	__property System::UnicodeString RootPath = {read=FRootPath, write=SetRootPath};
	__property TdxPSFileBasedExplorerLoadErrorEvent OnLoadError = {read=FOnLoadError, write=FOnLoadError};
public:
	/* TCustomdxPSExplorer.Destroy */ inline __fastcall virtual ~TdxPSFileBasedExplorer(void) { }
	
/* Hoisted overloads: */
	
public:
	inline void __fastcall  LoadItemData(Dxpscore::TdxPSExplorerItem* AnItem, Dxpscore::TBasedxReportLink* AReportLink){ Dxpscore::TCustomdxPSExplorer::LoadItemData(AnItem, AReportLink); }
	inline void __fastcall  UnloadItemData(Dxpscore::TdxPSExplorerItem* AnItem){ Dxpscore::TCustomdxPSExplorer::UnloadItemData(AnItem); }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsfilebasedxplorer */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFILEBASEDXPLORER)
using namespace Dxpsfilebasedxplorer;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfilebasedxplorerHPP
