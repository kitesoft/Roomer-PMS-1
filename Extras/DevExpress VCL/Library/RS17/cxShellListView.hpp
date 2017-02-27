// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellListView.pas' rev: 24.00 (Win32)

#ifndef CxshelllistviewHPP
#define CxshelllistviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.ShlObj.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxScrollBar.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxShellCommon.hpp>	// Pascal unit
#include <cxShellControls.hpp>	// Pascal unit
#include <cxHeader.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxshelllistview
{
//-- type declarations -------------------------------------------------------
enum TcxShellObjectPathType : unsigned char { sptAbsolutePhysical, sptRelativePhysical, sptUNC, sptVirtual, sptInternalAbsoluteVirtual, sptInternalRelativeVirtual, sptIncorrect };

enum TcxShellViewOption : unsigned char { svoShowFiles, svoShowFolders, svoShowHidden };

typedef System::Set<TcxShellViewOption, TcxShellViewOption::svoShowFiles, TcxShellViewOption::svoShowHidden>  TcxShellViewOptions;

class DELPHICLASS TcxCustomShellListView;
typedef void __fastcall (__closure *TcxBeforeNavigationEvent)(TcxCustomShellListView* Sender, Winapi::Shlobj::PItemIDList ANewAbsolutePIDL);

typedef void __fastcall (__closure *TcxCurrentFolderChangedEvent)(TcxCustomShellListView* Sender);

class DELPHICLASS TcxShellIconOptions;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxShellIconOptions : public Cxlistview::TcxIconOptions
{
	typedef Cxlistview::TcxIconOptions inherited;
	
private:
	Cxshellcontrols::TcxShellIconSize __fastcall GetSize(void);
	void __fastcall SetSize(const Cxshellcontrols::TcxShellIconSize Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Cxshellcontrols::TcxShellIconSize Size = {read=GetSize, write=SetSize, default=0};
public:
	/* TcxIconOptions.Create */ inline __fastcall TcxShellIconOptions(Cxlistview::TcxListViewContainer* AOwner) : Cxlistview::TcxIconOptions(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxShellIconOptions(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxInnerShellListView;
class PASCALIMPLEMENTATION TcxInnerShellListView : public Cxshellcontrols::TcxCustomInnerShellListView
{
	typedef Cxshellcontrols::TcxCustomInnerShellListView inherited;
	
private:
	_ITEMIDLIST *FAbsolutePIDL;
	Vcl::Comctrls::TLVChangeEvent FOnChange;
	Winapi::Shlobj::PItemIDList __fastcall GetAbsolutePIDL(void);
	TcxCustomShellListView* __fastcall GetContainer(void);
	System::UnicodeString __fastcall GetPath(void);
	void __fastcall SaveAbsolutePIDL(Winapi::Shlobj::PItemIDList AValue);
	void __fastcall SetAbsolutePIDL(Winapi::Shlobj::PItemIDList AValue);
	void __fastcall SetPath(System::UnicodeString AValue);
	HIDESBASE MESSAGE void __fastcall DSMShellChangeNotify(Winapi::Messages::TMessage &Message);
	__property Winapi::Shlobj::PItemIDList AbsolutePIDL = {read=GetAbsolutePIDL, write=SetAbsolutePIDL};
	__property System::UnicodeString Path = {read=GetPath, write=SetPath};
	
protected:
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual bool __fastcall DoCompare(Cxshellcommon::TcxShellFolder* AItem1, Cxshellcommon::TcxShellFolder* AItem2, /* out */ int &ACompare);
	virtual void __fastcall Navigate(Winapi::Shlobj::PItemIDList APIDL);
	virtual bool __fastcall NeedCheckScrollBars(Winapi::Messages::TMessage &Message);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	virtual void __fastcall ChangeHandler(System::TObject* Sender, Vcl::Comctrls::TListItem* AItem, Vcl::Comctrls::TItemChange AChange);
	__property TcxCustomShellListView* Container = {read=GetContainer};
	__property Vcl::Comctrls::TLVChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	
public:
	__fastcall virtual TcxInnerShellListView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxInnerShellListView(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	__property Anchors = {default=3};
	__property BorderStyle = {default=1};
	__property Color = {default=-16777211};
	__property DragDropSettings;
	__property HotTrack = {default=0};
	__property IconOptions;
	__property Items;
	__property ListViewStyle;
	__property MultiSelect = {default=0};
	__property Options;
	__property Root;
	__property Visible = {default=1};
	__property AfterNavigation;
	__property BeforeNavigation;
	__property OnAddFolder;
	__property OnCompare;
	__property OnRootChanged;
	__property OnSelectItem;
	__property OnShellChange;
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxInnerShellListView(HWND ParentWindow) : Cxshellcontrols::TcxCustomInnerShellListView(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomShellListView : public Cxlistview::TcxListViewContainer
{
	typedef Cxlistview::TcxListViewContainer inherited;
	
private:
	bool FIsExitProcessing;
	Cxshellcontrols::TcxShellAddFolderEvent FOnAddFolder;
	TcxBeforeNavigationEvent FOnBeforeNavigation;
	Vcl::Comctrls::TLVChangeEvent FOnChange;
	TcxCurrentFolderChangedEvent FOnCurrentFolderChanged;
	Cxshellcontrols::TcxShellCompareEvent FOnCompare;
	Vcl::Comctrls::TLVEditedEvent FOnEdited;
	Vcl::Comctrls::TLVEditingEvent FOnEditing;
	Cxshellcontrols::TcxShellExecuteItemEvent FOnExecuteItem;
	Vcl::Comctrls::TLVSelectItemEvent FOnSelectItem;
	Cxshellcontrols::TcxShellChangeEvent FOnShellChange;
	void __fastcall AddFolderHandler(System::TObject* Sender, Cxshellcommon::TcxShellFolder* AFolder, bool &ACanAdd);
	void __fastcall BeforeNavigationHandler(Cxshellcontrols::TcxCustomInnerShellListView* Sender, Winapi::Shlobj::PItemIDList APItemIDList, System::WideString AFolderPath);
	void __fastcall ChangeHandler(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemChange Change);
	void __fastcall EditedHandler(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, System::UnicodeString &S);
	void __fastcall EditingHandler(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, bool &AllowEdit);
	void __fastcall ExecuteItemHandler(System::TObject* Sender, Winapi::Shlobj::PItemIDList APIDL, bool &AHandled);
	void __fastcall SelectItemHandler(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, bool Selected);
	void __fastcall ShellChangeHandler(System::TObject* Sender, unsigned AEventID, Winapi::Shlobj::PItemIDList APIDL1, Winapi::Shlobj::PItemIDList APIDL2);
	bool __fastcall DoCompare(Cxshellcommon::TcxShellFolder* AItem1, Cxshellcommon::TcxShellFolder* AItem2, /* out */ int &ACompare);
	Winapi::Shlobj::PItemIDList __fastcall GetAbsolutePIDL(void);
	Cxshellcommon::TcxDragDropSettings* __fastcall GetDragDropSettings(void);
	Cxshellcommon::TcxShellFolder* __fastcall GetFolder(int AIndex);
	int __fastcall GetFolderCount(void);
	TcxShellIconOptions* __fastcall GetIconOptions(void);
	TcxInnerShellListView* __fastcall GetInnerListView(void);
	bool __fastcall GetListHotTrack(void);
	Cxshellcontrols::TcxShellListViewOptions* __fastcall GetOptions(void);
	System::UnicodeString __fastcall GetPath(void);
	Cxshellcontrols::TcxShellListRoot* __fastcall GetRoot(void);
	bool __fastcall GetSorting(void);
	Cxshellcommon::TcxShellThumbnailOptions* __fastcall GetThumbnailOptions(void);
	void __fastcall SetAbsolutePIDL(Winapi::Shlobj::PItemIDList Value);
	void __fastcall SetDragDropSettings(Cxshellcommon::TcxDragDropSettings* Value);
	HIDESBASE void __fastcall SetIconOptions(TcxShellIconOptions* Value);
	void __fastcall SetListHotTrack(bool Value);
	void __fastcall SetOptions(Cxshellcontrols::TcxShellListViewOptions* Value);
	void __fastcall SetPath(System::UnicodeString Value);
	void __fastcall SetRoot(Cxshellcontrols::TcxShellListRoot* Value);
	void __fastcall SetSorting(const bool Value);
	void __fastcall SetThumbnailOptions(Cxshellcommon::TcxShellThumbnailOptions* const Value);
	
protected:
	Cxdatautils::TcxCustomDataBinding* FDataBinding;
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall CurrentFolderChangedHandler(System::TObject* Sender, Cxshellcommon::TcxCustomShellRoot* Root);
	virtual Cxdatautils::TcxCustomDataBindingClass __fastcall GetDataBindingClass(void);
	virtual Cxlistview::TcxIconOptionsClass __fastcall GetIconOptionsClass(void);
	virtual Cxlistview::TcxInnerListViewClass __fastcall GetInnerListViewClass(void);
	virtual void __fastcall InitializeInnerListView(void);
	Cxshellcontrols::TcxShellDependedControls* __fastcall GetDependedControls(void);
	Cxshellcommon::TcxCustomShellRoot* __fastcall GetShellRoot(void);
	TcxShellViewOptions __fastcall GetViewOptions(bool AForNavigation = false);
	virtual void __fastcall SetViewStyle(Vcl::Comctrls::TViewStyle Value);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	__property Cxdatautils::TcxCustomDataBinding* DataBinding = {read=FDataBinding};
	__property Cxshellcommon::TcxDragDropSettings* DragDropSettings = {read=GetDragDropSettings, write=SetDragDropSettings};
	__property TcxShellIconOptions* IconOptions = {read=GetIconOptions, write=SetIconOptions};
	__property bool ListHotTrack = {read=GetListHotTrack, write=SetListHotTrack, default=0};
	__property Cxshellcontrols::TcxShellListViewOptions* Options = {read=GetOptions, write=SetOptions};
	__property Cxshellcontrols::TcxShellListRoot* Root = {read=GetRoot, write=SetRoot};
	__property bool Sorting = {read=GetSorting, write=SetSorting, nodefault};
	__property Cxshellcommon::TcxShellThumbnailOptions* ThumbnailOptions = {read=GetThumbnailOptions, write=SetThumbnailOptions};
	__property Cxshellcontrols::TcxShellAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
	__property TcxBeforeNavigationEvent OnBeforeNavigation = {read=FOnBeforeNavigation, write=FOnBeforeNavigation};
	__property Vcl::Comctrls::TLVChangeEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Cxshellcontrols::TcxShellCompareEvent OnCompare = {read=FOnCompare, write=FOnCompare};
	__property TcxCurrentFolderChangedEvent OnCurrentFolderChanged = {read=FOnCurrentFolderChanged, write=FOnCurrentFolderChanged};
	__property Vcl::Comctrls::TLVEditedEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property Vcl::Comctrls::TLVEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property Cxshellcontrols::TcxShellExecuteItemEvent OnExecuteItem = {read=FOnExecuteItem, write=FOnExecuteItem};
	__property Vcl::Comctrls::TLVSelectItemEvent OnSelectItem = {read=FOnSelectItem, write=FOnSelectItem};
	__property Cxshellcontrols::TcxShellChangeEvent OnShellChange = {read=FOnShellChange, write=FOnShellChange};
	
public:
	__fastcall virtual TcxCustomShellListView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomShellListView(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall SetFocus(void);
	void __fastcall BrowseParent(void);
	Winapi::Shlobj::PItemIDList __fastcall GetItemAbsolutePIDL(int AIndex);
	void __fastcall ProcessTreeViewNavigate(Winapi::Shlobj::PItemIDList APidl);
	void __fastcall Sort(void);
	void __fastcall UpdateContent(void);
	__property System::UnicodeString AbsolutePath = {read=GetPath, write=SetPath};
	__property Winapi::Shlobj::PItemIDList AbsolutePIDL = {read=GetAbsolutePIDL, write=SetAbsolutePIDL};
	__property int FolderCount = {read=GetFolderCount, nodefault};
	__property Cxshellcommon::TcxShellFolder* Folders[int AIndex] = {read=GetFolder};
	__property TcxInnerShellListView* InnerListView = {read=GetInnerListView};
	__property System::UnicodeString Path = {read=GetPath, write=SetPath};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomShellListView(HWND ParentWindow) : Cxlistview::TcxListViewContainer(ParentWindow) { }
	
private:
	void *__IcxShellRoot;	/* Cxshellcontrols::IcxShellRoot */
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


class DELPHICLASS TcxShellListView;
class PASCALIMPLEMENTATION TcxShellListView : public TcxCustomShellListView
{
	typedef TcxCustomShellListView inherited;
	
__published:
	__property Anchors = {default=3};
	__property Constraints;
	__property DragDropSettings;
	__property Enabled = {default=1};
	__property IconOptions;
	__property ListHotTrack = {default=0};
	__property MultiSelect = {default=0};
	__property Options;
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property Root;
	__property ShowColumnHeaders = {default=1};
	__property ShowHint;
	__property Sorting;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property ThumbnailOptions;
	__property ViewStyle = {default=0};
	__property Visible = {default=1};
	__property OnAddFolder;
	__property OnBeforeNavigation;
	__property OnChange;
	__property OnClick;
	__property OnCompare;
	__property OnContextPopup;
	__property OnCurrentFolderChanged;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEdited;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExecuteItem;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnSelectItem;
	__property OnShellChange;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomShellListView.Create */ inline __fastcall virtual TcxShellListView(System::Classes::TComponent* AOwner) : TcxCustomShellListView(AOwner) { }
	/* TcxCustomShellListView.Destroy */ inline __fastcall virtual ~TcxShellListView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxShellListView(HWND ParentWindow) : TcxCustomShellListView(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TcxShellSpecialFolderInfoTableItem
{
public:
	unsigned Attributes;
	_ITEMIDLIST *PIDL;
	System::UnicodeString PIDLDisplayName;
	System::UnicodeString PIDLName;
	System::UnicodeString PIDLUpperCaseDisplayName;
};


typedef System::StaticArray<TcxShellSpecialFolderInfoTableItem, 35> Cxshelllistview__5;

//-- var, const, procedure ---------------------------------------------------
static const System::Int8 cxShellSpecialFolderInfoTableLength = System::Int8(0x23);
extern PACKAGE Cxshelllistview__5 cxShellSpecialFolderInfoTable;
extern PACKAGE bool __fastcall CheckAbsolutePIDL(Winapi::Shlobj::PItemIDList &APIDL, Cxshellcommon::TcxCustomShellRoot* ARoot, bool ACheckObjectExistence, bool ACheckIsSubPath = true);
extern PACKAGE bool __fastcall CheckShellObjectExistence(Winapi::Shlobj::PItemIDList APIDL);
extern PACKAGE TcxShellObjectPathType __fastcall CheckShellObjectPath(System::UnicodeString &APath, System::UnicodeString ACurrentPath, bool AIsDisplayText);
extern PACKAGE bool __fastcall CheckViewOptions(TcxShellViewOptions AViewOptions, unsigned AShellObjectAttributes);
extern PACKAGE System::UnicodeString __fastcall GetPIDLDisplayName(Winapi::Shlobj::PItemIDList APIDL, bool AShowFullPath = false);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall InternalParseDisplayName(_di_IShellFolder AParentIFolder, System::UnicodeString ADisplayName, TcxShellViewOptions AViewOptions);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall PathToAbsolutePIDL(System::UnicodeString APath, Cxshellcommon::TcxCustomShellRoot* ARoot, TcxShellViewOptions AViewOptions, bool ACheckIsSubPath = true);
extern PACKAGE Winapi::Shlobj::PItemIDList __fastcall ShellObjectInternalVirtualPathToPIDL(System::UnicodeString APath, Cxshellcommon::TcxCustomShellRoot* ARoot, TcxShellViewOptions AViewOptions);
}	/* namespace Cxshelllistview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLLISTVIEW)
using namespace Cxshelllistview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshelllistviewHPP
