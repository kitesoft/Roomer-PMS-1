// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellControls.pas' rev: 24.00 (Win64)

#ifndef CxshellcontrolsHPP
#define CxshellcontrolsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <System.Win.ComObj.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.AppEvnts.hpp>	// Pascal unit
#include <Winapi.ShellAPI.hpp>	// Pascal unit
#include <Winapi.ShlObj.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxShellCommon.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxThemeManager.hpp>	// Pascal unit
#include <dxUxTheme.hpp>	// Pascal unit
#include <dxThemeConsts.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxshellcontrols
{
//-- type declarations -------------------------------------------------------
enum TcxListViewStyle : unsigned char { lvsIcon, lvsSmallIcon, lvsList, lvsReport };

class DELPHICLASS TcxCustomInnerShellListView;
typedef void __fastcall (__closure *TcxNavigationEvent)(TcxCustomInnerShellListView* Sender, Winapi::Shlobj::PItemIDList APIDL, System::WideString ADisplayName);

typedef void __fastcall (__closure *TcxShellExecuteItemEvent)(System::TObject* Sender, Winapi::Shlobj::PItemIDList APIDL, bool &AHandled);

typedef void __fastcall (__closure *TcxShellAddFolderEvent)(System::TObject* Sender, Cxshellcommon::TcxShellFolder* AFolder, bool &ACanAdd);

typedef void __fastcall (__closure *TcxShellChangeEvent)(System::TObject* Sender, unsigned AEventID, Winapi::Shlobj::PItemIDList APIDL1, Winapi::Shlobj::PItemIDList APIDL2);

typedef void __fastcall (__closure *TcxShellCompareEvent)(System::TObject* Sender, Cxshellcommon::TcxShellFolder* AItem1, Cxshellcommon::TcxShellFolder* AItem2, int &ACompare);

class DELPHICLASS TcxShellListViewProducer;
class PASCALIMPLEMENTATION TcxShellListViewProducer : public Cxshellcommon::TcxCustomItemProducer
{
	typedef Cxshellcommon::TcxCustomItemProducer inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FThumbnails;
	void __fastcall CheckThumnals(void);
	TcxCustomInnerShellListView* __fastcall GetListView(void);
	
protected:
	virtual bool __fastcall CanAddFolder(Cxshellcommon::TcxShellFolder* AFolder);
	virtual bool __fastcall DoCompareItems(Cxshellcommon::TcxShellFolder* AItem1, Cxshellcommon::TcxShellFolder* AItem2, /* out */ int &ACompare);
	virtual void __fastcall DoDestroy(void);
	virtual void __fastcall DoSlowInitialization(Cxshellcommon::TcxShellItemInfo* AItem);
	virtual unsigned __fastcall GetEnumFlags(void);
	virtual Cxshellcommon::TcxShellItemsInfoGatherer* __fastcall GetItemsInfoGatherer(void);
	virtual int __fastcall GetThumbnailIndex(Cxshellcommon::TcxShellItemInfo* AItem);
	virtual bool __fastcall GetShowToolTip(void);
	virtual bool __fastcall SlowInitializationDone(Cxshellcommon::TcxShellItemInfo* AItem);
	__property TcxCustomInnerShellListView* ListView = {read=GetListView};
	
public:
	__fastcall virtual TcxShellListViewProducer(Vcl::Controls::TWinControl* AOwner);
	virtual void __fastcall ProcessItems(_di_IShellFolder AIFolder, Winapi::Shlobj::PItemIDList AFolderPIDL, int APreloadItemCount);
	virtual void __fastcall ProcessDetails(_di_IShellFolder ShellFolder, int CharWidth);
public:
	/* TcxCustomItemProducer.Destroy */ inline __fastcall virtual ~TcxShellListViewProducer(void) { }
	
};


class DELPHICLASS TcxShellListRoot;
class PASCALIMPLEMENTATION TcxShellListRoot : public Cxshellcommon::TcxCustomShellRoot
{
	typedef Cxshellcommon::TcxCustomShellRoot inherited;
	
public:
	/* TcxCustomShellRoot.Create */ inline __fastcall virtual TcxShellListRoot(System::Classes::TPersistent* AOwner, HWND AParentWindow) : Cxshellcommon::TcxCustomShellRoot(AOwner, AParentWindow) { }
	/* TcxCustomShellRoot.Destroy */ inline __fastcall virtual ~TcxShellListRoot(void) { }
	
};


enum TDropTargetType : unsigned char { dttNone, dttOpenFolder, dttItem };

__interface IcxDropTarget;
typedef System::DelphiInterface<IcxDropTarget> _di_IcxDropTarget;
__interface  INTERFACE_UUID("{F688E250-96A6-4222-AF9D-049EB6E7D05B}") IcxDropTarget  : public IDropTarget 
{
	
};

class DELPHICLASS TcxShellDependedControls;
class PASCALIMPLEMENTATION TcxShellDependedControls : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	Vcl::Controls::TWinControl* operator[](int Index) { return Items[Index]; }
	
private:
	Vcl::Controls::TWinControl* __fastcall GetItem(int Index);
	
protected:
	void __fastcall DoNavigate(Vcl::Controls::TWinControl* AControl, Winapi::Shlobj::PItemIDList AItem);
	void __fastcall DoSynchronizeRoot(Vcl::Controls::TWinControl* AControl, Cxshellcommon::TcxCustomShellRoot* ARoot);
	
public:
	HIDESBASE void __fastcall Add(Vcl::Controls::TWinControl* AControl);
	void __fastcall Navigate(Winapi::Shlobj::PItemIDList AItem);
	HIDESBASE void __fastcall Remove(Vcl::Controls::TWinControl* AControl);
	void __fastcall SynchronizeRoot(Cxshellcommon::TcxCustomShellRoot* ARoot);
	__property Vcl::Controls::TWinControl* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TcxShellDependedControls(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxShellDependedControls(void) : System::Classes::TList() { }
	
};


__interface IcxShellDependedControls;
typedef System::DelphiInterface<IcxShellDependedControls> _di_IcxShellDependedControls;
__interface  INTERFACE_UUID("{93CE18BE-90F7-4CD1-B6DF-B578E2776DCA}") IcxShellDependedControls  : public System::IInterface 
{
	
public:
	virtual TcxShellDependedControls* __fastcall GetDependedControls(void) = 0 ;
};

__interface IcxShellRoot;
typedef System::DelphiInterface<IcxShellRoot> _di_IcxShellRoot;
__interface  INTERFACE_UUID("{C819D99E-4368-400C-B4C4-0021E6B5C260}") IcxShellRoot  : public System::IInterface 
{
	
public:
	virtual Cxshellcommon::TcxCustomShellRoot* __fastcall GetRoot(void) = 0 ;
};

class DELPHICLASS TcxShellListViewOptions;
class PASCALIMPLEMENTATION TcxShellListViewOptions : public Cxshellcommon::TcxShellOptions
{
	typedef Cxshellcommon::TcxShellOptions inherited;
	
private:
	bool FAutoExecute;
	bool FAutoNavigate;
	
public:
	__fastcall virtual TcxShellListViewOptions(Vcl::Controls::TWinControl* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool AutoExecute = {read=FAutoExecute, write=FAutoExecute, default=1};
	__property bool AutoNavigate = {read=FAutoNavigate, write=FAutoNavigate, default=1};
	__property FileMask = {default=0};
public:
	/* TcxShellOptions.Destroy */ inline __fastcall virtual ~TcxShellListViewOptions(void) { }
	
};


__interface IcxDataObject;
typedef System::DelphiInterface<IcxDataObject> _di_IcxDataObject;
__interface  INTERFACE_UUID("{9A9CDB78-150E-4469-A551-608EFF415145}") IcxDataObject  : public IDataObject 
{
	
};

struct DECLSPEC_DRECORD TcxShellChangeNotifierData
{
public:
	NativeUInt Handle;
	_ITEMIDLIST *PIDL;
};


enum TcxShellIconSize : unsigned char { isDefault, isExtraLarge, isJumbo };

class PASCALIMPLEMENTATION TcxCustomInnerShellListView : public Cxlistview::TcxBaseInnerListView
{
	typedef Cxlistview::TcxBaseInnerListView inherited;
	
private:
	Vcl::Appevnts::TApplicationEvents* FAppEvents;
	_di_IcxDropTarget FCurrentDropTarget;
	TcxShellDependedControls* FDependedControls;
	Cxshellcommon::TcxDragDropSettings* FDragDropSettings;
	_di_IcxDataObject FDraggedObject;
	int FDropTargetItemIndex;
	Vcl::Imglist::TCustomImageList* FFakeThumbnailImages;
	int FFirstUpdateItem;
	NativeUInt FInternalSmallImages;
	bool FIsThumbnailView;
	TcxShellListViewProducer* FItemProducer;
	Cxshellcommon::TcxShellItemsInfoGatherer* FItemsInfoGatherer;
	TcxShellIconSize FLargeIconSize;
	Vcl::Imglist::TCustomImageList* FLargeImages;
	int FLastUpdateItem;
	TcxListViewStyle FListViewStyle;
	bool FNotificationLock;
	TcxShellListViewOptions* FOptions;
	TcxShellListRoot* FRoot;
	TcxShellChangeNotifierData FShellChangeNotifierData;
	bool FSorting;
	Cxshellcommon::TcxShellThumbnailOptions* FThumbnailOptions;
	bool FWasMouseRButtonPressed;
	TcxNavigationEvent FAfterNavigation;
	TcxNavigationEvent FBeforeNavigation;
	TcxShellAddFolderEvent FOnAddFolder;
	TcxShellCompareEvent FOnCompare;
	TcxShellExecuteItemEvent FOnExecuteItem;
	Cxshellcommon::TcxRootChangedEvent FOnRootChanged;
	TcxShellChangeEvent FOnShellChange;
	void __fastcall DestroySelectedPidlsList(System::Classes::TList* ASelectedPidls);
	Cxshellcommon::TcxShellFolder* __fastcall GetFolder(int AIndex);
	int __fastcall GetFolderCount(void);
	int __fastcall GetLargeImageListType(void);
	System::Classes::TList* __fastcall CreateSelectedPidlsList(void);
	bool __fastcall IsThumbnailView(void);
	void __fastcall RootFolderChanged(System::TObject* Sender, Cxshellcommon::TcxCustomShellRoot* Root);
	void __fastcall RootSettingsChanged(System::TObject* Sender);
	void __fastcall SetLargeIconSize(const TcxShellIconSize Value);
	void __fastcall SetListViewStyle(const TcxListViewStyle Value);
	void __fastcall SetDropTargetItemIndex(int Value);
	void __fastcall SetSorting(const bool Value);
	void __fastcall ShellChangeNotify(int AEventID, Winapi::Shlobj::PItemIDList APidl1, Winapi::Shlobj::PItemIDList APidl2);
	void __fastcall InitializeSorting(void);
	MESSAGE void __fastcall DSMSynchronizeRoot(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmSystemShellChangeNotify(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual bool __fastcall OwnerDataFetch(Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemRequest Request);
	virtual int __fastcall OwnerDataFind(Vcl::Comctrls::TItemFind Find, const System::UnicodeString FindString, const System::Types::TPoint FindPosition, void * FindData, int StartIndex, Vcl::Comctrls::TSearchDirection Direction, bool Wrap);
	DYNAMIC void __fastcall ColClick(Vcl::Comctrls::TListColumn* Column);
	DYNAMIC void __fastcall DblClick(void);
	DYNAMIC void __fastcall DoContextPopup(System::Types::TPoint MousePos, bool &Handled);
	DYNAMIC bool __fastcall CanEdit(Vcl::Comctrls::TListItem* Item);
	virtual void __fastcall Loaded(void);
	DYNAMIC void __fastcall Edit(const tagLVITEMW &Item);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall AdvancedDrawItem(Vcl::Comctrls::TCustomListView* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TCustomDrawState State, Vcl::Comctrls::TCustomDrawStage Stage, bool &DefaultDraw);
	void __fastcall CheckLargeImages(void);
	void __fastcall DisplayContextMenu(const System::Types::TPoint APos);
	bool __fastcall DoAddFolder(Cxshellcommon::TcxShellFolder* AFolder);
	void __fastcall DoAfterNavigation(void);
	void __fastcall DoBeforeNavigation(Winapi::Shlobj::PItemIDList fqPidl);
	void __fastcall DoBeginDrag(void);
	virtual bool __fastcall DoCompare(Cxshellcommon::TcxShellFolder* AItem1, Cxshellcommon::TcxShellFolder* AItem2, /* out */ int &ACompare);
	void __fastcall DoNavigateTreeView(void);
	void __fastcall DoOnIdle(System::TObject* Sender, bool &Done);
	virtual void __fastcall DoProcessDefaultCommand(Cxshellcommon::TcxShellItemInfo* Item);
	void __fastcall DoProcessNavigation(Cxshellcommon::TcxShellItemInfo* Item);
	bool __fastcall CheckFileMask(Cxshellcommon::TcxShellFolder* AFolder);
	void __fastcall UpdateThumbnails(void);
	void __fastcall CheckUpdateItems(void);
	void __fastcall CreateColumns(void);
	void __fastcall CreateDropTarget(void);
	void __fastcall CreateChangeNotification(void);
	HIDESBASE void __fastcall GetDropTarget(System::Types::TPoint pt, /* out */ bool &New);
	System::Types::TSize __fastcall GetLargeIconSize(void);
	virtual Dxcore::TdxSortOrder __fastcall GetSortOrder(int AColumnIndex);
	System::Types::TSize __fastcall GetThumbnailSize(void);
	virtual void __fastcall Navigate(Winapi::Shlobj::PItemIDList APIDL);
	void __fastcall RemoveChangeNotification(void);
	void __fastcall RemoveColumns(void);
	void __fastcall RemoveDropTarget(void);
	virtual void __fastcall SortColumnChanged(void);
	void __fastcall ThumbnailOptionsChanged(System::TObject* Sender);
	HRESULT __fastcall TryReleaseDropTarget(void);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	MESSAGE void __fastcall DsmDoNavigate(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmNotifyUpdateContents(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmNotifyUpdateItem(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmSetCount(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmShellChangeNotify(Winapi::Messages::TMessage &Message);
	HRESULT __stdcall DragEnter(const _di_IDataObject dataObj, int grfKeyState, System::Types::TPoint pt, int &dwEffect);
	HRESULT __stdcall IDropTargetDragOver(int grfKeyState, System::Types::TPoint pt, int &dwEffect);
	HRESULT __stdcall DragLeave(void);
	HRESULT __stdcall Drop(const _di_IDataObject dataObj, int grfKeyState, System::Types::TPoint pt, int &dwEffect);
	TcxShellDependedControls* __fastcall GetDependedControls(void);
	Cxshellcommon::TcxCustomShellRoot* __fastcall GetRoot(void);
	__property _di_IcxDropTarget CurrentDropTarget = {read=FCurrentDropTarget, write=FCurrentDropTarget};
	__property _di_IcxDataObject DraggedObject = {read=FDraggedObject, write=FDraggedObject};
	__property int DropTargetItemIndex = {read=FDropTargetItemIndex, write=SetDropTargetItemIndex, nodefault};
	__property int FirstUpdateItem = {read=FFirstUpdateItem, write=FFirstUpdateItem, nodefault};
	__property TcxShellListViewProducer* ItemProducer = {read=FItemProducer};
	__property Cxshellcommon::TcxShellItemsInfoGatherer* ItemsInfoGatherer = {read=FItemsInfoGatherer};
	__property int LastUpdateItem = {read=FLastUpdateItem, write=FLastUpdateItem, nodefault};
	__property bool Sorting = {read=FSorting, write=SetSorting, default=0};
	__property TcxShellAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
	__property TcxShellCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	__property TcxShellExecuteItemEvent OnExecuteItem = {read=FOnExecuteItem, write=FOnExecuteItem};
	__property TcxShellChangeEvent OnShellChange = {read=FOnShellChange, write=FOnShellChange};
	
public:
	__fastcall virtual TcxCustomInnerShellListView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerShellListView(void);
	void __fastcall BrowseParent(void);
	void __fastcall ProcessTreeViewNavigate(Winapi::Shlobj::PItemIDList APidl);
	void __fastcall Sort(void);
	void __fastcall UpdateContent(void);
	__property TcxShellDependedControls* DependedControls = {read=FDependedControls, write=FDependedControls};
	__property Cxshellcommon::TcxDragDropSettings* DragDropSettings = {read=FDragDropSettings, write=FDragDropSettings};
	__property int FolderCount = {read=GetFolderCount, nodefault};
	__property Cxshellcommon::TcxShellFolder* Folders[int AIndex] = {read=GetFolder};
	__property TcxShellIconSize LargeIconSize = {read=FLargeIconSize, write=SetLargeIconSize, nodefault};
	__property TcxListViewStyle ListViewStyle = {read=FListViewStyle, write=SetListViewStyle, nodefault};
	__property TcxShellListViewOptions* Options = {read=FOptions, write=FOptions};
	__property TcxShellListRoot* Root = {read=FRoot, write=FRoot};
	__property Cxshellcommon::TcxShellThumbnailOptions* ThumbnailOptions = {read=FThumbnailOptions, write=FThumbnailOptions};
	__property TcxNavigationEvent AfterNavigation = {read=FAfterNavigation, write=FAfterNavigation};
	__property TcxNavigationEvent BeforeNavigation = {read=FBeforeNavigation, write=FBeforeNavigation};
	__property Cxshellcommon::TcxRootChangedEvent OnRootChanged = {read=FOnRootChanged, write=FOnRootChanged};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerShellListView(HWND ParentWindow) : Cxlistview::TcxBaseInnerListView(ParentWindow) { }
	
private:
	void *__IcxShellRoot;	/* IcxShellRoot */
	void *__IcxShellDependedControls;	/* IcxShellDependedControls */
	void *__IcxDropTarget;	/* IcxDropTarget */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C819D99E-4368-400C-B4C4-0021E6B5C260}
	operator _di_IcxShellRoot()
	{
		_di_IcxShellRoot intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxShellRoot*(void) { return (IcxShellRoot*)&__IcxShellRoot; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {93CE18BE-90F7-4CD1-B6DF-B578E2776DCA}
	operator _di_IcxShellDependedControls()
	{
		_di_IcxShellDependedControls intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxShellDependedControls*(void) { return (IcxShellDependedControls*)&__IcxShellDependedControls; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F688E250-96A6-4222-AF9D-049EB6E7D05B}
	operator _di_IcxDropTarget()
	{
		_di_IcxDropTarget intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxDropTarget*(void) { return (IcxDropTarget*)&__IcxDropTarget; }
	#endif
	
};


class DELPHICLASS TcxShellTreeRoot;
class PASCALIMPLEMENTATION TcxShellTreeRoot : public Cxshellcommon::TcxCustomShellRoot
{
	typedef Cxshellcommon::TcxCustomShellRoot inherited;
	
public:
	/* TcxCustomShellRoot.Create */ inline __fastcall virtual TcxShellTreeRoot(System::Classes::TPersistent* AOwner, HWND AParentWindow) : Cxshellcommon::TcxCustomShellRoot(AOwner, AParentWindow) { }
	/* TcxCustomShellRoot.Destroy */ inline __fastcall virtual ~TcxShellTreeRoot(void) { }
	
};


class DELPHICLASS TcxShellTreeItemProducer;
class DELPHICLASS TcxCustomInnerShellTreeView;
class PASCALIMPLEMENTATION TcxShellTreeItemProducer : public Cxshellcommon::TcxCustomItemProducer
{
	typedef Cxshellcommon::TcxCustomItemProducer inherited;
	
private:
	Vcl::Comctrls::TTreeNode* FNode;
	Cxshellcommon::TcxShellItemInfo* FShellItemInfo;
	System::Classes::TNotifyEvent FOnDestroy;
	TcxCustomInnerShellTreeView* __fastcall GetTreeView(void);
	
protected:
	virtual bool __fastcall CanAddFolder(Cxshellcommon::TcxShellFolder* AFolder);
	virtual void __fastcall DoSlowInitialization(Cxshellcommon::TcxShellItemInfo* AItem);
	virtual unsigned __fastcall GetEnumFlags(void);
	virtual Cxshellcommon::TcxShellItemsInfoGatherer* __fastcall GetItemsInfoGatherer(void);
	virtual bool __fastcall GetShowToolTip(void);
	virtual void __fastcall InitializeItem(Cxshellcommon::TcxShellItemInfo* AItem);
	virtual void __fastcall CheckForSubitems(Cxshellcommon::TcxShellItemInfo* AItem);
	virtual bool __fastcall SlowInitializationDone(Cxshellcommon::TcxShellItemInfo* AItem);
	__property Vcl::Comctrls::TTreeNode* Node = {read=FNode, write=FNode};
	__property Cxshellcommon::TcxShellItemInfo* ShellItemInfo = {read=FShellItemInfo, write=FShellItemInfo};
	__property TcxCustomInnerShellTreeView* TreeView = {read=GetTreeView};
	
public:
	__fastcall virtual TcxShellTreeItemProducer(Vcl::Controls::TWinControl* AOwner);
	__fastcall virtual ~TcxShellTreeItemProducer(void);
	virtual void __fastcall SetItemsCount(int Count);
	virtual void __fastcall NotifyRemoveItem(int Index);
	virtual void __fastcall NotifyAddItem(int Index);
	HIDESBASE void __fastcall ProcessItems(_di_IShellFolder AIFolder, Winapi::Shlobj::PItemIDList APIDL, Vcl::Comctrls::TTreeNode* ANode, int APreloadItemCount)/* overload */;
	bool __fastcall CheckUpdates(void);
	__property System::Classes::TNotifyEvent OnDestroy = {read=FOnDestroy, write=FOnDestroy};
};


typedef TcxShellTreeItemProducer* *PcxShellTreeItemProducer;

class DELPHICLASS TcxShellTreeViewOptions;
class PASCALIMPLEMENTATION TcxShellTreeViewOptions : public Cxshellcommon::TcxShellOptions
{
	typedef Cxshellcommon::TcxShellOptions inherited;
	
protected:
	virtual void __fastcall DoNotifyUpdateContents(void);
	
__published:
	__property FileMask = {default=0};
public:
	/* TcxShellOptions.Create */ inline __fastcall virtual TcxShellTreeViewOptions(Vcl::Controls::TWinControl* AOwner) : Cxshellcommon::TcxShellOptions(AOwner) { }
	/* TcxShellOptions.Destroy */ inline __fastcall virtual ~TcxShellTreeViewOptions(void) { }
	
};


struct DECLSPEC_DRECORD TcxShellTreeViewStateData
{
public:
	_ITEMIDLIST *CurrentPath;
	System::Classes::TList* ExpandedNodeList;
	int TopItemIndex;
};


class PASCALIMPLEMENTATION TcxCustomInnerShellTreeView : public Cxtreeview::TcxBaseInnerTreeView
{
	typedef Cxtreeview::TcxBaseInnerTreeView inherited;
	
private:
	Vcl::Appevnts::TApplicationEvents* FAppEvents;
	TcxShellTreeItemProducer* FContextPopupItemProducer;
	_di_IcxDropTarget FCurrentDropTarget;
	TcxShellDependedControls* FDependedControls;
	Cxshellcommon::TcxDragDropSettings* FDragDropSettings;
	_di_IcxDataObject FDraggedObject;
	Vcl::Comctrls::TTreeNode* FDragSourceNode;
	Vcl::Comctrls::TTreeNode* FDragSourceNodeParent;
	NativeUInt FInternalSmallImages;
	bool FIsChangeNotificationCreationLocked;
	bool FIsDragging;
	bool FIsUpdating;
	System::Classes::TThreadList* FItemProducersList;
	Cxshellcommon::TcxShellItemsInfoGatherer* FItemsInfoGatherer;
	TcxCustomInnerShellListView* FListView;
	int FLockVisibleUpdate;
	int FMaxVisibleNodeCount;
	bool FNavigation;
	TcxShellTreeViewOptions* FOptions;
	Vcl::Comctrls::TTreeNode* FPrevTargetNode;
	TcxShellTreeRoot* FRoot;
	bool FShellChangeNotificationCreation;
	TcxShellChangeNotifierData FShellChangeNotifierData;
	bool FShowInfoTips;
	TcxShellTreeViewStateData FStateData;
	Vcl::Comctrls::TTreeNode* FTopNode;
	bool FWasMouseRButtonPressed;
	TcxShellAddFolderEvent FOnAddFolder;
	Cxshellcommon::TcxRootChangedEvent FOnRootChanged;
	TcxShellChangeEvent FOnShellChange;
	void __fastcall CheckUpdates(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall ContextPopupItemProducerDestroyHandler(System::TObject* Sender);
	Vcl::Comctrls::TTreeNode* __fastcall CreateShellNode(Vcl::Comctrls::TTreeNode* AParentNode, Cxshellcommon::TcxShellItemInfo* AShellItem);
	Cxshellcommon::TcxShellFolder* __fastcall GetFolder(int AIndex);
	int __fastcall GetFolderCount(void);
	HIDESBASE Vcl::Comctrls::TTreeNode* __fastcall GetNodeFromItem(const tagTVITEMW &Item);
	TcxShellTreeItemProducer* __fastcall GetItemProducer(Vcl::Comctrls::TTreeNode* ANode);
	Cxshellcommon::TcxShellItemInfo* __fastcall GetShellItemInfo(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall LockUpdateVisibleInfo(void);
	void __fastcall RestoreTreeState(void);
	void __fastcall RootFolderChanged(System::TObject* Sender, Cxshellcommon::TcxCustomShellRoot* Root);
	void __fastcall RootSettingsChanged(System::TObject* Sender);
	void __fastcall SaveTreeState(void);
	void __fastcall SetListView(TcxCustomInnerShellListView* Value);
	void __fastcall SetPrevTargetNode(Vcl::Comctrls::TTreeNode* const Value);
	void __fastcall SetShowInfoTips(bool Value);
	void __fastcall ShellChangeNotify(int AEventID, Winapi::Shlobj::PItemIDList APidl1, Winapi::Shlobj::PItemIDList APidl2);
	void __fastcall ShowToolTipChanged(System::TObject* Sender);
	void __fastcall UnlockUpdateVisibleInfo(void);
	HIDESBASE MESSAGE void __fastcall CMColorChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DSMShellTreeChangeNotify(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DSMShellTreeRestoreCurrentPath(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DSMSynchronizeRoot(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DSMSystemShellChangeNotify(Winapi::Messages::TMessage &Message);
	__property _di_IcxDropTarget CurrentDropTarget = {read=FCurrentDropTarget, write=FCurrentDropTarget};
	__property _di_IcxDataObject DraggedObject = {read=FDraggedObject, write=FDraggedObject};
	__property System::Classes::TThreadList* ItemProducersList = {read=FItemProducersList};
	__property bool Navigation = {read=FNavigation, write=FNavigation, nodefault};
	__property Vcl::Comctrls::TTreeNode* PrevTargetNode = {read=FPrevTargetNode, write=SetPrevTargetNode};
	
protected:
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	DYNAMIC void __fastcall Change(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC bool __fastcall CanEdit(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall Edit(const tagTVITEMW &Item);
	DYNAMIC bool __fastcall CanExpand(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall Delete(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC void __fastcall Expand(Vcl::Comctrls::TTreeNode* Node);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	DYNAMIC void __fastcall DoContextPopup(System::Types::TPoint MousePos, bool &Handled);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall Resize(void);
	TcxShellDependedControls* __fastcall GetDependedControls(void);
	Cxshellcommon::TcxCustomShellRoot* __fastcall GetRoot(void);
	void __fastcall AddItemProducer(TcxShellTreeItemProducer* Producer);
	void __fastcall AdjustControlParams(void);
	bool __fastcall CheckFileMask(Cxshellcommon::TcxShellFolder* AFolder);
	void __fastcall CreateChangeNotification(Vcl::Comctrls::TTreeNode* ANode = (Vcl::Comctrls::TTreeNode*)(0x0));
	void __fastcall CreateDropTarget(void);
	bool __fastcall DoAddFolder(Cxshellcommon::TcxShellFolder* AFolder);
	void __fastcall DoBeginDrag(void);
	void __fastcall DoNavigateListView(void);
	void __fastcall DoOnIdle(System::TObject* Sender, bool &Done);
	virtual void __fastcall DragDropSettingsChanged(System::TObject* Sender);
	HIDESBASE void __fastcall GetDropTarget(/* out */ bool &ANew, System::Types::TPoint APoint);
	Vcl::Comctrls::TTreeNode* __fastcall GetNodeByPIDL(Winapi::Shlobj::PItemIDList APIDL);
	virtual bool __fastcall IsDragDropEnabled(void);
	virtual bool __fastcall IsLoading(void);
	void __fastcall RemoveChangeNotification(void);
	void __fastcall RemoveDropTarget(void);
	void __fastcall RemoveItemProducer(TcxShellTreeItemProducer* AProducer);
	HRESULT __fastcall TryReleaseDropTarget(void);
	void __fastcall UpdateItem(Cxshellcommon::TcxShellItemInfo* AItem);
	void __fastcall UpdateVisibleItems(void);
	MESSAGE void __fastcall DsmSetCount(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmNotifyUpdateItem(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmNotifyRemoveItem(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmNotifyAddItem(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmNotifyUpdateContents(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmShellChangeNotify(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DsmDoNavigate(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	HRESULT __stdcall DragEnter(const _di_IDataObject dataObj, int grfKeyState, System::Types::TPoint pt, int &dwEffect);
	HRESULT __stdcall IDropTargetDragOver(int grfKeyState, System::Types::TPoint pt, int &dwEffect);
	HRESULT __stdcall DragLeave(void);
	HRESULT __stdcall Drop(const _di_IDataObject dataObj, int grfKeyState, System::Types::TPoint pt, int &dwEffect);
	__property Cxshellcommon::TcxShellItemsInfoGatherer* ItemsInfoGatherer = {read=FItemsInfoGatherer};
	__property TcxShellAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
	__property TcxShellChangeEvent OnShellChange = {read=FOnShellChange, write=FOnShellChange};
	
public:
	__fastcall virtual TcxCustomInnerShellTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomInnerShellTreeView(void);
	void __fastcall UpdateContent(void);
	void __fastcall UpdateNode(Vcl::Comctrls::TTreeNode* ANode, bool AFast);
	__property TcxShellDependedControls* DependedControls = {read=FDependedControls};
	__property Cxshellcommon::TcxDragDropSettings* DragDropSettings = {read=FDragDropSettings, write=FDragDropSettings};
	__property int FolderCount = {read=GetFolderCount, nodefault};
	__property Cxshellcommon::TcxShellFolder* Folders[int AIndex] = {read=GetFolder};
	__property TcxCustomInnerShellListView* ListView = {read=FListView, write=SetListView};
	__property TcxShellTreeViewOptions* Options = {read=FOptions, write=FOptions};
	__property TcxShellTreeRoot* Root = {read=FRoot, write=FRoot};
	__property bool ShowInfoTips = {read=FShowInfoTips, write=SetShowInfoTips, default=0};
	__property Cxshellcommon::TcxRootChangedEvent OnRootChanged = {read=FOnRootChanged, write=FOnRootChanged};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomInnerShellTreeView(HWND ParentWindow) : Cxtreeview::TcxBaseInnerTreeView(ParentWindow) { }
	
private:
	void *__IcxShellRoot;	/* IcxShellRoot */
	void *__IcxShellDependedControls;	/* IcxShellDependedControls */
	void *__IcxDropTarget;	/* IcxDropTarget */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C819D99E-4368-400C-B4C4-0021E6B5C260}
	operator _di_IcxShellRoot()
	{
		_di_IcxShellRoot intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxShellRoot*(void) { return (IcxShellRoot*)&__IcxShellRoot; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {93CE18BE-90F7-4CD1-B6DF-B578E2776DCA}
	operator _di_IcxShellDependedControls()
	{
		_di_IcxShellDependedControls intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxShellDependedControls*(void) { return (IcxShellDependedControls*)&__IcxShellDependedControls; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {F688E250-96A6-4222-AF9D-049EB6E7D05B}
	operator _di_IcxDropTarget()
	{
		_di_IcxDropTarget intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IcxDropTarget*(void) { return (IcxDropTarget*)&__IcxDropTarget; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall cxShellGetNotifyParams(Winapi::Messages::TMessage &Message, /* out */ int &AEventID, /* out */ Winapi::Shlobj::PItemIDList &APidl1, /* out */ Winapi::Shlobj::PItemIDList &APidl2);
extern PACKAGE void __fastcall cxShellRegisterChangeNotifier(Winapi::Shlobj::PItemIDList ANotifierPIDL, HWND AWnd, unsigned ANotificationMessage, bool AWatchSubtree, TcxShellChangeNotifierData &ANotifierData);
extern PACKAGE void __fastcall cxShellUnregisterChangeNotifier(TcxShellChangeNotifierData &ANotifierData);
extern PACKAGE bool __fastcall cxSetShellControl(Vcl::Controls::TWinControl* AControl, Vcl::Controls::TWinControl* AValue, Vcl::Controls::TWinControl* &AFieldValue);
}	/* namespace Cxshellcontrols */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLCONTROLS)
using namespace Cxshellcontrols;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshellcontrolsHPP
