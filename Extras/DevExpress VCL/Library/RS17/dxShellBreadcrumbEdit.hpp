// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxShellBreadcrumbEdit.pas' rev: 24.00 (Win32)

#ifndef DxshellbreadcrumbeditHPP
#define DxshellbreadcrumbeditHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.ActiveX.hpp>	// Pascal unit
#include <Winapi.ShlObj.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <dxCustomTree.hpp>	// Pascal unit
#include <dxBreadcrumbEdit.hpp>	// Pascal unit
#include <cxShellCommon.hpp>	// Pascal unit
#include <cxShellControls.hpp>	// Pascal unit
#include <cxShellListView.hpp>	// Pascal unit
#include <cxShellComboBox.hpp>	// Pascal unit
#include <cxShellTreeView.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxshellbreadcrumbedit
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxShellBreadcrumbEditRoot;
class PASCALIMPLEMENTATION TdxShellBreadcrumbEditRoot : public Cxshellcommon::TcxCustomShellRoot
{
	typedef Cxshellcommon::TcxCustomShellRoot inherited;
	
public:
	/* TcxCustomShellRoot.Create */ inline __fastcall virtual TdxShellBreadcrumbEditRoot(System::Classes::TPersistent* AOwner, HWND AParentWindow) : Cxshellcommon::TcxCustomShellRoot(AOwner, AParentWindow) { }
	/* TcxCustomShellRoot.Destroy */ inline __fastcall virtual ~TdxShellBreadcrumbEditRoot(void) { }
	
};


__interface IdxShellBreadcrumbEditEvents;
typedef System::DelphiInterface<IdxShellBreadcrumbEditEvents> _di_IdxShellBreadcrumbEditEvents;
__interface  INTERFACE_UUID("{73A3108B-0FC0-41D7-A885-B8F7C2431779}") IdxShellBreadcrumbEditEvents  : public Dxbreadcrumbedit::IdxBreadcrumbEditEvents 
{
	
public:
	virtual void __fastcall ShellChanged(unsigned AEventID, Winapi::Shlobj::PItemIDList APIDL1, Winapi::Shlobj::PItemIDList APIDL2) = 0 ;
};

enum TdxShellBreadcrumbEditShellOptionsChange : unsigned char { bcescContent, bcescRoot, bcescTracking };

typedef System::Set<TdxShellBreadcrumbEditShellOptionsChange, TdxShellBreadcrumbEditShellOptionsChange::bcescContent, TdxShellBreadcrumbEditShellOptionsChange::bcescTracking>  TdxShellBreadcrumbEditShellOptionsChanges;

typedef void __fastcall (__closure *TdxShellBreadcrumbEditShellOptionsChangeEvent)(System::TObject* Sender, const TdxShellBreadcrumbEditShellOptionsChanges AChanges);

class DELPHICLASS TdxShellBreadcrumbEditShellOptions;
class PASCALIMPLEMENTATION TdxShellBreadcrumbEditShellOptions : public Dxcoreclasses::TcxOwnedPersistent
{
	typedef Dxcoreclasses::TcxOwnedPersistent inherited;
	
private:
	TdxShellBreadcrumbEditRoot* FRoot;
	bool FShowHiddenFolders;
	bool FTrackShellChanges;
	TdxShellBreadcrumbEditShellOptionsChangeEvent FOnChange;
	void __fastcall DoFolderChanged(System::TObject* Sender, Cxshellcommon::TcxCustomShellRoot* Root);
	void __fastcall DoSettingsChanged(System::TObject* Sender);
	void __fastcall SetRoot(TdxShellBreadcrumbEditRoot* AValue);
	void __fastcall SetShowHiddenFolders(bool AValue);
	void __fastcall SetTrackShellChanges(bool AValue);
	
protected:
	virtual void __fastcall Changed(TdxShellBreadcrumbEditShellOptionsChanges AChanges);
	__property TdxShellBreadcrumbEditShellOptionsChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TdxShellBreadcrumbEditShellOptions(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxShellBreadcrumbEditShellOptions(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property TdxShellBreadcrumbEditRoot* Root = {read=FRoot, write=SetRoot};
	__property bool ShowHiddenFolders = {read=FShowHiddenFolders, write=SetShowHiddenFolders, default=0};
	__property bool TrackShellChanges = {read=FTrackShellChanges, write=SetTrackShellChanges, default=1};
};


class DELPHICLASS TdxShellBreadcrumbEditProperties;
class PASCALIMPLEMENTATION TdxShellBreadcrumbEditProperties : public Dxbreadcrumbedit::TdxCustomBreadcrumbEditProperties
{
	typedef Dxbreadcrumbedit::TdxCustomBreadcrumbEditProperties inherited;
	
private:
	Vcl::Imglist::TCustomImageList* FShellImageList;
	TdxShellBreadcrumbEditShellOptions* FShellOptions;
	TdxShellBreadcrumbEditShellOptionsChangeEvent FOnShellOptionsChanged;
	Vcl::Imglist::TCustomImageList* __fastcall CreateShellImageList(void);
	void __fastcall ShellOptionsChanged(System::TObject* Sender, const TdxShellBreadcrumbEditShellOptionsChanges AChanges);
	void __fastcall SetShellOptions(TdxShellBreadcrumbEditShellOptions* AValue);
	
protected:
	__property TdxShellBreadcrumbEditShellOptionsChangeEvent OnShellOptionsChanged = {read=FOnShellOptionsChanged, write=FOnShellOptionsChanged};
	
public:
	__fastcall virtual TdxShellBreadcrumbEditProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TdxShellBreadcrumbEditProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Borders = {default=15};
	__property Buttons;
	__property ButtonImages;
	__property DropDownRows = {default=18};
	__property PathEditor;
	__property ProgressBar;
	__property TdxShellBreadcrumbEditShellOptions* ShellOptions = {read=FShellOptions, write=SetShellOptions};
};


class DELPHICLASS TdxShellBreadcrumbEditProducer;
class DELPHICLASS TdxShellBreadcrumbEditNode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxShellBreadcrumbEditProducer : public Cxshellcommon::TcxCustomItemProducer
{
	typedef Cxshellcommon::TcxCustomItemProducer inherited;
	
private:
	TdxShellBreadcrumbEditNode* FNode;
	Cxshellcommon::TcxShellItemInfo* FShellItemInfo;
	bool __fastcall GetIsInitialized(void);
	
protected:
	virtual bool __fastcall CanAddFolder(Cxshellcommon::TcxShellFolder* AFolder);
	virtual unsigned __fastcall GetEnumFlags(void);
	virtual bool __fastcall GetShowToolTip(void);
	virtual bool __fastcall SlowInitializationDone(Cxshellcommon::TcxShellItemInfo* AItem);
	virtual void __fastcall DoSlowInitialization(Cxshellcommon::TcxShellItemInfo* AItem);
	
public:
	__fastcall virtual TdxShellBreadcrumbEditProducer(TdxShellBreadcrumbEditNode* ANode);
	void __fastcall CheckInitialized(void);
	virtual TdxShellBreadcrumbEditNode* __fastcall GetNodeByPidl(Winapi::Shlobj::PItemIDList APidl);
	HIDESBASE void __fastcall ProcessItems(void)/* overload */;
	virtual void __fastcall SetItemsCount(int Count);
	__property bool IsInitialized = {read=GetIsInitialized, nodefault};
	__property TdxShellBreadcrumbEditNode* Node = {read=FNode};
	__property Cxshellcommon::TcxShellItemInfo* ShellItemInfo = {read=FShellItemInfo, write=FShellItemInfo};
public:
	/* TcxCustomItemProducer.Destroy */ inline __fastcall virtual ~TdxShellBreadcrumbEditProducer(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxShellBreadcrumbEditNode : public Dxbreadcrumbedit::TdxBreadcrumbEditNode
{
	typedef Dxbreadcrumbedit::TdxBreadcrumbEditNode inherited;
	
public:
	TdxShellBreadcrumbEditNode* operator[](int AIndex) { return Items[AIndex]; }
	
private:
	_ITEMIDLIST *FAbsolutePidl;
	TdxShellBreadcrumbEditProducer* FProducer;
	_di_IShellFolder FShellFolder;
	void __fastcall FreeShellObjects(void);
	Winapi::Shlobj::PItemIDList __fastcall GetAbsolutePidl(void);
	Dxbreadcrumbedit::_di_IdxBreadcrumbEdit __fastcall GetEdit(void);
	System::UnicodeString __fastcall GetFolderName(void);
	HIDESBASE TdxShellBreadcrumbEditNode* __fastcall GetItem(int AIndex);
	TdxShellBreadcrumbEditShellOptions* __fastcall GetOptions(void);
	HIDESBASE TdxShellBreadcrumbEditNode* __fastcall GetParent(void);
	Winapi::Shlobj::PItemIDList __fastcall GetPidl(void);
	System::UnicodeString __fastcall GetRealPath(void);
	_di_IShellFolder __fastcall GetShellFolder(void);
	void __fastcall SetPidl(const Winapi::Shlobj::PItemIDList Value);
	
protected:
	virtual System::UnicodeString __fastcall GetPath(void);
	virtual void __fastcall Initialize(Cxshellcommon::TcxShellItemInfo* AItemInfo);
	__property Winapi::Shlobj::PItemIDList AbsolutePidl = {read=GetAbsolutePidl};
	__property Dxbreadcrumbedit::_di_IdxBreadcrumbEdit Edit = {read=GetEdit};
	__property TdxShellBreadcrumbEditShellOptions* Options = {read=GetOptions};
	__property Winapi::Shlobj::PItemIDList Pidl = {read=GetPidl, write=SetPidl};
	__property TdxShellBreadcrumbEditProducer* Producer = {read=FProducer};
	__property _di_IShellFolder ShellFolder = {read=GetShellFolder};
	
public:
	__fastcall virtual TdxShellBreadcrumbEditNode(Dxcustomtree::_di_IdxTreeOwner AOwner);
	__fastcall virtual ~TdxShellBreadcrumbEditNode(void);
	HIDESBASE TdxShellBreadcrumbEditNode* __fastcall AddChild(void)/* overload */;
	virtual bool __fastcall Compare(const System::UnicodeString AName);
	__property System::UnicodeString FolderName = {read=GetFolderName};
	__property TdxShellBreadcrumbEditNode* Items[int AIndex] = {read=GetItem/*, default*/};
	__property TdxShellBreadcrumbEditNode* Parent = {read=GetParent};
	__property System::UnicodeString RealPath = {read=GetRealPath};
/* Hoisted overloads: */
	
public:
	inline Dxbreadcrumbedit::TdxBreadcrumbEditNode* __fastcall  AddChild(const System::UnicodeString AName, System::Uitypes::TImageIndex AImageIndex = (System::Uitypes::TImageIndex)(0xffffffff), void * AData = (void *)(0x0)){ return Dxbreadcrumbedit::TdxBreadcrumbEditNode::AddChild(AName, AImageIndex, AData); }
	
};

#pragma pack(pop)

class DELPHICLASS TdxShellBreadcrumbEditController;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxShellBreadcrumbEditController : public Dxbreadcrumbedit::TdxBreadcrumbEditController
{
	typedef Dxbreadcrumbedit::TdxBreadcrumbEditController inherited;
	
private:
	Cxshellcontrols::TcxShellChangeNotifierData FShellChangeNotifierData;
	HIDESBASE TdxShellBreadcrumbEditNode* __fastcall GetRoot(void);
	TdxShellBreadcrumbEditNode* __fastcall GetSelected(void);
	Winapi::Shlobj::PItemIDList __fastcall GetSelectedPidl(void);
	System::UnicodeString __fastcall GetSelectedRealPath(void);
	TdxShellBreadcrumbEditShellOptions* __fastcall GetShellOptions(void);
	HIDESBASE void __fastcall SetSelected(TdxShellBreadcrumbEditNode* AValue);
	void __fastcall SetSelectedPidl(Winapi::Shlobj::PItemIDList AValue);
	void __fastcall ShellChangeNotify(int AEventID, Winapi::Shlobj::PItemIDList APidl1, Winapi::Shlobj::PItemIDList APidl2);
	
protected:
	virtual void __fastcall DoAfterSelect(void);
	virtual void __fastcall DoShellChangeNotify(int AEventID, Winapi::Shlobj::PItemIDList APidl1, Winapi::Shlobj::PItemIDList APidl2);
	virtual bool __fastcall GetPidlByPath(System::UnicodeString APath, /* out */ Winapi::Shlobj::PItemIDList &APidl);
	void __fastcall RemoveChangeNotification(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	virtual Dxbreadcrumbedit::TdxBreadcrumbEditNode* __fastcall FindNodeByPath(System::UnicodeString APath);
	TdxShellBreadcrumbEditNode* __fastcall FindNodeByPidl(Winapi::Shlobj::PItemIDList APidl, bool AIgnoreFile = false);
	void __fastcall CancelSelectionChanges(void);
	void __fastcall UpdateContent(void);
	void __fastcall UpdateTrackingSettings(void);
	__property TdxShellBreadcrumbEditNode* Root = {read=GetRoot};
	__property TdxShellBreadcrumbEditNode* Selected = {read=GetSelected, write=SetSelected};
	__property Winapi::Shlobj::PItemIDList SelectedPidl = {read=GetSelectedPidl, write=SetSelectedPidl};
	__property System::UnicodeString SelectedRealPath = {read=GetSelectedRealPath};
	__property TdxShellBreadcrumbEditShellOptions* ShellOptions = {read=GetShellOptions};
public:
	/* TdxBreadcrumbEditController.Create */ inline __fastcall virtual TdxShellBreadcrumbEditController(Dxbreadcrumbedit::TdxBreadcrumbEditViewInfo* AViewInfo) : Dxbreadcrumbedit::TdxBreadcrumbEditController(AViewInfo) { }
	/* TdxBreadcrumbEditController.Destroy */ inline __fastcall virtual ~TdxShellBreadcrumbEditController(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxCustomShellBreadcrumbEdit;
class PASCALIMPLEMENTATION TdxCustomShellBreadcrumbEdit : public Dxbreadcrumbedit::TdxCustomBreadcrumbEdit
{
	typedef Dxbreadcrumbedit::TdxCustomBreadcrumbEdit inherited;
	
private:
	Cxshellcontrols::TcxShellDependedControls* FDependedControls;
	int FNavigationLockCount;
	Cxshellcombobox::TcxCustomShellComboBox* FShellComboBox;
	Cxshelllistview::TcxCustomShellListView* FShellListView;
	Cxshelltreeview::TcxCustomShellTreeView* FShellTreeView;
	Cxshellcommon::TcxRootChangedEvent FOnRootChanged;
	Cxshellcontrols::TcxShellChangeEvent FOnShellChange;
	HIDESBASE TdxShellBreadcrumbEditController* __fastcall GetController(void);
	HIDESBASE TdxShellBreadcrumbEditProperties* __fastcall GetProperties(void);
	HIDESBASE TdxShellBreadcrumbEditNode* __fastcall GetRoot(void);
	Winapi::Shlobj::PItemIDList __fastcall GetSelectedPidl(void);
	bool __fastcall IsParentLoading(void);
	void __fastcall ShellOptionsChangeHandler(System::TObject* Sender, const TdxShellBreadcrumbEditShellOptionsChanges AChanges);
	HIDESBASE void __fastcall SetProperties(TdxShellBreadcrumbEditProperties* AValue);
	void __fastcall SetSelectedPidl(Winapi::Shlobj::PItemIDList AValue);
	void __fastcall SetShellComboBox(Cxshellcombobox::TcxCustomShellComboBox* AValue);
	void __fastcall SetShellListView(Cxshelllistview::TcxCustomShellListView* AValue);
	void __fastcall SetShellTreeView(Cxshelltreeview::TcxCustomShellTreeView* AValue);
	MESSAGE void __fastcall DSMNavigate(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DSMNotifyUpdateContents(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DSMSynchronizeRoot(Winapi::Messages::TMessage &Message);
	
protected:
	virtual Dxbreadcrumbedit::TdxBreadcrumbEditController* __fastcall CreateController(void);
	virtual Dxbreadcrumbedit::TdxCustomBreadcrumbEditProperties* __fastcall CreateProperties(void);
	virtual Dxbreadcrumbedit::TdxBreadcrumbEditNode* __fastcall CreateRoot(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall LoadChildren(Dxcustomtree::TdxTreeCustomNode* ASender);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall RootChanged(void);
	virtual void __fastcall SelectionChanged(void);
	virtual void __fastcall ShellOptionsChanged(const TdxShellBreadcrumbEditShellOptionsChanges AChanges);
	virtual void __fastcall SynchronizeDependedControls(void);
	virtual void __fastcall SynchronizeRoot(void);
	virtual System::UnicodeString __fastcall GetSelectedPath(void);
	void __fastcall ShellChanged(unsigned AEventID, Winapi::Shlobj::PItemIDList APIDL1, Winapi::Shlobj::PItemIDList APIDL2);
	Cxshellcontrols::TcxShellDependedControls* __fastcall GetDependedControls(void);
	Cxshellcommon::TcxCustomShellRoot* __fastcall GetShellRoot(void);
	__property TdxShellBreadcrumbEditController* Controller = {read=GetController};
	__property Cxshellcontrols::TcxShellDependedControls* DependedControls = {read=FDependedControls};
	__property TdxShellBreadcrumbEditNode* Root = {read=GetRoot};
	
public:
	__fastcall virtual TdxCustomShellBreadcrumbEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxCustomShellBreadcrumbEdit(void);
	void __fastcall UpdateContent(void);
	__property TdxShellBreadcrumbEditProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Winapi::Shlobj::PItemIDList SelectedPidl = {read=GetSelectedPidl, write=SetSelectedPidl};
	__property Cxshellcombobox::TcxCustomShellComboBox* ShellComboBox = {read=FShellComboBox, write=SetShellComboBox};
	__property Cxshelllistview::TcxCustomShellListView* ShellListView = {read=FShellListView, write=SetShellListView};
	__property Cxshelltreeview::TcxCustomShellTreeView* ShellTreeView = {read=FShellTreeView, write=SetShellTreeView};
	__property Cxshellcommon::TcxRootChangedEvent OnRootChanged = {read=FOnRootChanged, write=FOnRootChanged};
	__property Cxshellcontrols::TcxShellChangeEvent OnShellChange = {read=FOnShellChange, write=FOnShellChange};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxCustomShellBreadcrumbEdit(HWND ParentWindow) : Dxbreadcrumbedit::TdxCustomBreadcrumbEdit(ParentWindow) { }
	
private:
	void *__IcxShellRoot;	/* Cxshellcontrols::IcxShellRoot */
	void *__IdxShellBreadcrumbEditEvents;	/* IdxShellBreadcrumbEditEvents */
	void *__IcxShellDependedControls;	/* Cxshellcontrols::IcxShellDependedControls */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {C819D99E-4368-400C-B4C4-0021E6B5C260}
	operator Cxshellcontrols::_di_IcxShellRoot()
	{
		Cxshellcontrols::_di_IcxShellRoot intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxshellcontrols::IcxShellRoot*(void) { return (Cxshellcontrols::IcxShellRoot*)&__IcxShellRoot; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {73A3108B-0FC0-41D7-A885-B8F7C2431779}
	operator _di_IdxShellBreadcrumbEditEvents()
	{
		_di_IdxShellBreadcrumbEditEvents intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxShellBreadcrumbEditEvents*(void) { return (IdxShellBreadcrumbEditEvents*)&__IdxShellBreadcrumbEditEvents; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {93CE18BE-90F7-4CD1-B6DF-B578E2776DCA}
	operator Cxshellcontrols::_di_IcxShellDependedControls()
	{
		Cxshellcontrols::_di_IcxShellDependedControls intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxshellcontrols::IcxShellDependedControls*(void) { return (Cxshellcontrols::IcxShellDependedControls*)&__IcxShellDependedControls; }
	#endif
	
};


class DELPHICLASS TdxShellBreadcrumbEdit;
class PASCALIMPLEMENTATION TdxShellBreadcrumbEdit : public TdxCustomShellBreadcrumbEdit
{
	typedef TdxCustomShellBreadcrumbEdit inherited;
	
__published:
	__property Align = {default=0};
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property Color = {default=536870912};
	__property Enabled = {default=1};
	__property Font;
	__property LookAndFeel;
	__property ParentShowHint = {default=1};
	__property Properties;
	__property ShellComboBox;
	__property ShellListView;
	__property ShellTreeView;
	__property ShowHint;
	__property Transparent = {default=0};
	__property OnButtonClick;
	__property OnPathEntered;
	__property OnPathSelected;
	__property OnPathValidate;
	__property OnPopulateAutoCompleteSuggestions;
	__property OnRootChanged;
	__property OnShellChange;
public:
	/* TdxCustomShellBreadcrumbEdit.Create */ inline __fastcall virtual TdxShellBreadcrumbEdit(System::Classes::TComponent* AOwner) : TdxCustomShellBreadcrumbEdit(AOwner) { }
	/* TdxCustomShellBreadcrumbEdit.Destroy */ inline __fastcall virtual ~TdxShellBreadcrumbEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxShellBreadcrumbEdit(HWND ParentWindow) : TdxCustomShellBreadcrumbEdit(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxshellbreadcrumbedit */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXSHELLBREADCRUMBEDIT)
using namespace Dxshellbreadcrumbedit;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxshellbreadcrumbeditHPP
