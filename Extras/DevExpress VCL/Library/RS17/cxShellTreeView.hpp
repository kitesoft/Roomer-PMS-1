// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellTreeView.pas' rev: 24.00 (Win32)

#ifndef CxshelltreeviewHPP
#define CxshelltreeviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Winapi.ShlObj.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxShellListView.hpp>	// Pascal unit
#include <cxShellCommon.hpp>	// Pascal unit
#include <cxShellControls.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxshelltreeview
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxInnerShellTreeView;
class DELPHICLASS TcxCustomShellTreeView;
class PASCALIMPLEMENTATION TcxInnerShellTreeView : public Cxshellcontrols::TcxCustomInnerShellTreeView
{
	typedef Cxshellcontrols::TcxCustomInnerShellTreeView inherited;
	
private:
	_ITEMIDLIST *FAbsolutePIDL;
	int FIndent;
	Winapi::Shlobj::PItemIDList __fastcall GetAbsolutePIDL(void);
	TcxCustomShellTreeView* __fastcall GetContainer(void);
	HIDESBASE int __fastcall GetIndent(void);
	System::UnicodeString __fastcall GetPath(void);
	void __fastcall SaveAbsolutePIDL(Winapi::Shlobj::PItemIDList AValue);
	void __fastcall SetAbsolutePIDL(Winapi::Shlobj::PItemIDList AValue);
	HIDESBASE void __fastcall SetIndent(const int Value);
	void __fastcall SetPath(System::UnicodeString AValue);
	HIDESBASE MESSAGE void __fastcall DSMShellChangeNotify(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall TVMEnsureVisible(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual bool __fastcall IsDragDropEnabled(void);
	virtual bool __fastcall IsLoading(void);
	virtual void __fastcall CreateWindowHandle(const Vcl::Controls::TCreateParams &Params);
	__property Winapi::Shlobj::PItemIDList AbsolutePIDL = {read=GetAbsolutePIDL, write=SetAbsolutePIDL};
	__property TcxCustomShellTreeView* Container = {read=GetContainer};
	__property System::UnicodeString Path = {read=GetPath, write=SetPath};
	
public:
	__fastcall virtual TcxInnerShellTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxInnerShellTreeView(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	__property Cursor = {default=0};
	__property DragDropSettings;
	__property ListView;
	__property Options;
	__property Root;
	__property OnAddFolder;
	__property OnRootChanged;
	__property OnShellChange;
	
__published:
	__property int Indent = {read=GetIndent, write=SetIndent, nodefault};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxInnerShellTreeView(HWND ParentWindow) : Cxshellcontrols::TcxCustomInnerShellTreeView(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomShellTreeView : public Cxtreeview::TcxTreeViewContainer
{
	typedef Cxtreeview::TcxTreeViewContainer inherited;
	
private:
	bool FIsExitProcessing;
	Cxshellcontrols::TcxShellAddFolderEvent FOnAddFolder;
	Vcl::Comctrls::TTVChangedEvent FOnChange;
	Vcl::Comctrls::TTVChangingEvent FOnChanging;
	Vcl::Comctrls::TTVExpandedEvent FOnCollapsed;
	Vcl::Comctrls::TTVCollapsingEvent FOnCollapsing;
	Vcl::Comctrls::TTVEditedEvent FOnEdited;
	Vcl::Comctrls::TTVEditingEvent FOnEditing;
	Vcl::Comctrls::TTVExpandedEvent FOnExpanded;
	Vcl::Comctrls::TTVExpandingEvent FOnExpanding;
	Cxshellcontrols::TcxShellChangeEvent FOnShellChange;
	void __fastcall AddFolderHandler(System::TObject* Sender, Cxshellcommon::TcxShellFolder* AFolder, bool &ACanAdd);
	void __fastcall ChangeHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall ChangingHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowChange);
	void __fastcall CollapsedHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall CollapsingHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowCollapse);
	void __fastcall EditedHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, System::UnicodeString &S);
	void __fastcall EditingHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowEdit);
	void __fastcall ExpandedHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall ExpandingHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowExpansion);
	void __fastcall ShellChangeHandler(System::TObject* Sender, unsigned AEventID, Winapi::Shlobj::PItemIDList APIDL1, Winapi::Shlobj::PItemIDList APIDL2);
	Winapi::Shlobj::PItemIDList __fastcall GetAbsolutePIDL(void);
	Cxshellcommon::TcxDragDropSettings* __fastcall GetDragDropSettings(void);
	Cxshellcommon::TcxShellFolder* __fastcall GetFolder(int AIndex);
	int __fastcall GetFolderCount(void);
	int __fastcall GetIndent(void);
	TcxInnerShellTreeView* __fastcall GetInnerTreeView(void);
	Cxshellcontrols::TcxShellTreeViewOptions* __fastcall GetOptions(void);
	System::UnicodeString __fastcall GetPath(void);
	Cxshellcontrols::TcxShellTreeRoot* __fastcall GetRoot(void);
	Cxshelllistview::TcxCustomShellListView* __fastcall GetShellListView(void);
	bool __fastcall GetShowInfoTips(void);
	bool __fastcall GetTreeHotTrack(void);
	void __fastcall SetAbsolutePIDL(Winapi::Shlobj::PItemIDList Value);
	void __fastcall SetDragDropSettings(Cxshellcommon::TcxDragDropSettings* Value);
	void __fastcall SetIndent(int Value);
	void __fastcall SetOptions(Cxshellcontrols::TcxShellTreeViewOptions* Value);
	void __fastcall SetPath(const System::UnicodeString Value);
	void __fastcall SetRoot(Cxshellcontrols::TcxShellTreeRoot* Value);
	void __fastcall SetShellListView(Cxshelllistview::TcxCustomShellListView* Value);
	void __fastcall SetShowInfoTips(bool Value);
	void __fastcall SetTreeHotTrack(bool Value);
	
protected:
	Cxdatautils::TcxCustomDataBinding* FDataBinding;
	DYNAMIC void __fastcall DoExit(void);
	virtual void __fastcall Loaded(void);
	virtual void __fastcall Scroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual void __fastcall CurrentFolderChangedHandler(System::TObject* Sender, Cxshellcommon::TcxCustomShellRoot* Root);
	virtual Cxdatautils::TcxCustomDataBindingClass __fastcall GetDataBindingClass(void);
	virtual Cxtreeview::TcxInnerTreeViewClass __fastcall GetInnerTreeViewClass(void);
	virtual void __fastcall InitializeInternalTreeView(void);
	Cxshelllistview::TcxShellViewOptions __fastcall GetViewOptions(bool AForNavigation = false);
	virtual bool __fastcall IsDragAndDropSupported(void);
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	Cxshellcontrols::TcxShellDependedControls* __fastcall GetDependedControls(void);
	Cxshellcommon::TcxCustomShellRoot* __fastcall GetShellRoot(void);
	__property Cxdatautils::TcxCustomDataBinding* DataBinding = {read=FDataBinding};
	__property Cxshellcommon::TcxDragDropSettings* DragDropSettings = {read=GetDragDropSettings, write=SetDragDropSettings};
	__property int Indent = {read=GetIndent, write=SetIndent, nodefault};
	__property Cxshellcontrols::TcxShellTreeViewOptions* Options = {read=GetOptions, write=SetOptions};
	__property Cxshellcontrols::TcxShellTreeRoot* Root = {read=GetRoot, write=SetRoot};
	__property Cxshelllistview::TcxCustomShellListView* ShellListView = {read=GetShellListView, write=SetShellListView};
	__property bool ShowInfoTips = {read=GetShowInfoTips, write=SetShowInfoTips, default=0};
	__property bool TreeHotTrack = {read=GetTreeHotTrack, write=SetTreeHotTrack, default=0};
	__property Cxshellcontrols::TcxShellAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
	__property Vcl::Comctrls::TTVChangedEvent OnChange = {read=FOnChange, write=FOnChange};
	__property Vcl::Comctrls::TTVChangingEvent OnChanging = {read=FOnChanging, write=FOnChanging};
	__property Vcl::Comctrls::TTVExpandedEvent OnCollapsed = {read=FOnCollapsed, write=FOnCollapsed};
	__property Vcl::Comctrls::TTVCollapsingEvent OnCollapsing = {read=FOnCollapsing, write=FOnCollapsing};
	__property Vcl::Comctrls::TTVEditedEvent OnEdited = {read=FOnEdited, write=FOnEdited};
	__property Vcl::Comctrls::TTVEditingEvent OnEditing = {read=FOnEditing, write=FOnEditing};
	__property Vcl::Comctrls::TTVExpandedEvent OnExpanded = {read=FOnExpanded, write=FOnExpanded};
	__property Vcl::Comctrls::TTVExpandingEvent OnExpanding = {read=FOnExpanding, write=FOnExpanding};
	__property Cxshellcontrols::TcxShellChangeEvent OnShellChange = {read=FOnShellChange, write=FOnShellChange};
	
public:
	__fastcall virtual TcxCustomShellTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxCustomShellTreeView(void);
	DYNAMIC bool __fastcall ExecuteAction(System::Classes::TBasicAction* Action);
	virtual void __fastcall SetFocus(void);
	virtual bool __fastcall UpdateAction(System::Classes::TBasicAction* Action);
	Winapi::Shlobj::PItemIDList __fastcall GetNodeAbsolutePIDL(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall UpdateContent(void);
	__property System::UnicodeString AbsolutePath = {read=GetPath, write=SetPath};
	__property Winapi::Shlobj::PItemIDList AbsolutePIDL = {read=GetAbsolutePIDL, write=SetAbsolutePIDL};
	__property int FolderCount = {read=GetFolderCount, nodefault};
	__property Cxshellcommon::TcxShellFolder* Folders[int AIndex] = {read=GetFolder};
	__property TcxInnerShellTreeView* InnerTreeView = {read=GetInnerTreeView};
	__property System::UnicodeString Path = {read=GetPath, write=SetPath};
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomShellTreeView(HWND ParentWindow) : Cxtreeview::TcxTreeViewContainer(ParentWindow) { }
	
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


class DELPHICLASS TcxShellTreeView;
class PASCALIMPLEMENTATION TcxShellTreeView : public TcxCustomShellTreeView
{
	typedef TcxCustomShellTreeView inherited;
	
__published:
	__property Anchors = {default=3};
	__property AutoExpand = {default=0};
	__property ChangeDelay = {default=0};
	__property Constraints;
	__property DragDropSettings;
	__property Enabled = {default=1};
	__property HideSelection = {default=1};
	__property Indent;
	__property Options;
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property RightClickSelect = {default=0};
	__property Root;
	__property ShellListView;
	__property ShowButtons = {default=1};
	__property ShowHint;
	__property ShowInfoTips = {default=0};
	__property ShowLines = {default=1};
	__property ShowRoot = {default=1};
	__property StateImages;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property TreeHotTrack = {default=0};
	__property Visible = {default=1};
	__property OnAddFolder;
	__property OnChange;
	__property OnChanging;
	__property OnClick;
	__property OnCollapsed;
	__property OnCollapsing;
	__property OnDblClick;
	__property OnEdited;
	__property OnEditing;
	__property OnEnter;
	__property OnExit;
	__property OnExpanded;
	__property OnExpanding;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnShellChange;
public:
	/* TcxCustomShellTreeView.Create */ inline __fastcall virtual TcxShellTreeView(System::Classes::TComponent* AOwner) : TcxCustomShellTreeView(AOwner) { }
	/* TcxCustomShellTreeView.Destroy */ inline __fastcall virtual ~TcxShellTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxShellTreeView(HWND ParentWindow) : TcxCustomShellTreeView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxshelltreeview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLTREEVIEW)
using namespace Cxshelltreeview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshelltreeviewHPP
