// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxShellComboBox.pas' rev: 24.00 (Win32)

#ifndef CxshellcomboboxHPP
#define CxshellcomboboxHPP

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
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Winapi.ShlObj.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxDataUtils.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxShellListView.hpp>	// Pascal unit
#include <cxShellTreeView.hpp>	// Pascal unit
#include <cxShellCommon.hpp>	// Pascal unit
#include <cxShellControls.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxshellcombobox
{
//-- type declarations -------------------------------------------------------
enum TcxShellComboBoxViewOption : unsigned char { scvoShowFiles, scvoShowHidden };

typedef System::Set<TcxShellComboBoxViewOption, TcxShellComboBoxViewOption::scvoShowFiles, TcxShellComboBoxViewOption::scvoShowHidden>  TcxShellComboBoxViewOptions;

enum TcxPopupShellTreeViewOption : unsigned char { tvoContextMenus, tvoHotTrack, tvoShowButtons, tvoShowInfoTips, tvoShowLines, tvoShowRoot, tvoShowToolTip, tvoRightClickSelect };

typedef System::Set<TcxPopupShellTreeViewOption, TcxPopupShellTreeViewOption::tvoContextMenus, TcxPopupShellTreeViewOption::tvoRightClickSelect>  TcxPopupShellTreeViewOptions;

enum TcxShellComboBoxShowFullPath : unsigned char { sfpNever, sfpAlways, sfpNotFocused };

class DELPHICLASS TcxShellComboBoxViewInfo;
class PASCALIMPLEMENTATION TcxShellComboBoxViewInfo : public Cxtextedit::TcxCustomTextEditViewInfo
{
	typedef Cxtextedit::TcxCustomTextEditViewInfo inherited;
	
public:
	System::Types::TPoint ShellIconPosition;
	int ShellSysIconIndex;
	int ShellSysIconOverlayIndex;
	virtual void __fastcall Offset(int DX, int DY);
	virtual void __fastcall Paint(Cxgraphics::TcxCanvas* ACanvas);
public:
	/* TcxCustomTextEditViewInfo.Destroy */ inline __fastcall virtual ~TcxShellComboBoxViewInfo(void) { }
	
public:
	/* TcxCustomEditViewInfo.Create */ inline __fastcall virtual TcxShellComboBoxViewInfo(void) : Cxtextedit::TcxCustomTextEditViewInfo() { }
	
};


class DELPHICLASS TcxShellComboBoxViewData;
class DELPHICLASS TcxCustomShellComboBoxProperties;
class PASCALIMPLEMENTATION TcxShellComboBoxViewData : public Cxdropdownedit::TcxCustomDropDownEditViewData
{
	typedef Cxdropdownedit::TcxCustomDropDownEditViewData inherited;
	
private:
	HIDESBASE TcxCustomShellComboBoxProperties* __fastcall GetProperties(void);
	
protected:
	virtual System::UnicodeString __fastcall InternalEditValueToDisplayText(const System::Variant &AEditValue);
	virtual System::Types::TSize __fastcall InternalGetEditConstantPartSize(Cxgraphics::TcxCanvas* ACanvas, bool AIsInplace, const Cxedit::TcxEditSizeProperties &AEditSizeProperties, System::Types::TSize &MinContentSize, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	
public:
	virtual void __fastcall Calculate(Cxgraphics::TcxCanvas* ACanvas, const System::Types::TRect &ABounds, const System::Types::TPoint &P, Cxcontainer::TcxMouseButton Button, System::Classes::TShiftState Shift, Cxedit::TcxCustomEditViewInfo* AViewInfo, bool AIsMouseEvent);
	virtual void __fastcall EditValueToDrawValue(const System::Variant &AEditValue, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	virtual System::Types::TRect __fastcall GetClientExtent(Cxgraphics::TcxCanvas* ACanvas, Cxedit::TcxCustomEditViewInfo* AViewInfo);
	__property TcxCustomShellComboBoxProperties* Properties = {read=GetProperties};
public:
	/* TcxCustomEditViewData.Create */ inline __fastcall virtual TcxShellComboBoxViewData(Cxedit::TcxCustomEditProperties* AProperties, Cxedit::TcxCustomEditStyle* AStyle, bool AIsInplace) : Cxdropdownedit::TcxCustomDropDownEditViewData(AProperties, AStyle, AIsInplace) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxShellComboBoxViewData(void) { }
	
};


class DELPHICLASS TcxShellComboBoxRoot;
class PASCALIMPLEMENTATION TcxShellComboBoxRoot : public Cxshellcommon::TcxCustomShellRoot
{
	typedef Cxshellcommon::TcxCustomShellRoot inherited;
	
private:
	System::Classes::TNotifyEvent FOnChange;
	
protected:
	virtual void __fastcall RootUpdated(void);
	__property System::Classes::TNotifyEvent OnChange = {read=FOnChange, write=FOnChange};
public:
	/* TcxCustomShellRoot.Create */ inline __fastcall virtual TcxShellComboBoxRoot(System::Classes::TPersistent* AOwner, HWND AParentWindow) : Cxshellcommon::TcxCustomShellRoot(AOwner, AParentWindow) { }
	/* TcxCustomShellRoot.Destroy */ inline __fastcall virtual ~TcxShellComboBoxRoot(void) { }
	
};


class DELPHICLASS TcxShellComboBoxLookupData;
class DELPHICLASS TcxCustomShellComboBox;
class PASCALIMPLEMENTATION TcxShellComboBoxLookupData : public Cxtextedit::TcxCustomTextEditLookupData
{
	typedef Cxtextedit::TcxCustomTextEditLookupData inherited;
	
private:
	HIDESBASE TcxCustomShellComboBox* __fastcall GetEdit(void);
	
protected:
	virtual System::UnicodeString __fastcall GetItem(int Index);
	virtual int __fastcall GetItemCount(void);
	virtual void __fastcall ListChanged(void);
	__property TcxCustomShellComboBox* Edit = {read=GetEdit};
public:
	/* TcxCustomTextEditLookupData.Create */ inline __fastcall virtual TcxShellComboBoxLookupData(System::Classes::TPersistent* AOwner) : Cxtextedit::TcxCustomTextEditLookupData(AOwner) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxShellComboBoxLookupData(void) { }
	
};


class PASCALIMPLEMENTATION TcxCustomShellComboBoxProperties : public Cxdropdownedit::TcxCustomPopupEditProperties
{
	typedef Cxdropdownedit::TcxCustomPopupEditProperties inherited;
	
private:
	bool FFastSearch;
	System::UnicodeString FFileMask;
	bool FIncrementalSearch;
	TcxShellComboBoxRoot* FRoot;
	TcxShellComboBoxShowFullPath FShowFullPath;
	bool FStoreRelativePath;
	TcxPopupShellTreeViewOptions FTreeViewOptions;
	TcxShellComboBoxViewOptions FViewOptions;
	Cxshellcontrols::TcxShellAddFolderEvent FOnAddFolder;
	System::Classes::TNotifyEvent FOnRootSettingsChanged;
	void __fastcall DoRootSettingsChanged(void);
	bool __fastcall GetDropDownSizeable(void);
	int __fastcall GetDropDownWidth(void);
	void __fastcall RootChangeHandler(System::TObject* Sender);
	void __fastcall RootSettingsChanged(System::TObject* Sender);
	void __fastcall SetDropDownSizeable(bool Value);
	void __fastcall SetDropDownWidth(int Value);
	void __fastcall SetFastSearch(bool Value);
	void __fastcall SetFileMask(const System::UnicodeString Value);
	HIDESBASE void __fastcall SetIncrementalSearch(bool Value);
	void __fastcall SetShowFullPath(TcxShellComboBoxShowFullPath Value);
	void __fastcall SetStoreRelativePath(bool Value);
	void __fastcall SetTreeViewOptions(TcxPopupShellTreeViewOptions Value);
	void __fastcall SetViewOptions(TcxShellComboBoxViewOptions Value);
	
protected:
	__classmethod virtual Cxdropdownedit::TcxCustomEditPopupWindowClass __fastcall GetPopupWindowClass();
	__classmethod virtual Cxedit::TcxCustomEditViewDataClass __fastcall GetViewDataClass();
	void __fastcall CheckRoot(void);
	virtual Winapi::Shlobj::PItemIDList __fastcall EditValueToPIDL(const System::Variant &AEditValue);
	Cxshelllistview::TcxShellViewOptions __fastcall GetShellViewOptions(void);
	virtual void __fastcall RootChanged(void);
	__property System::Classes::TNotifyEvent OnRootSettingsChanged = {read=FOnRootSettingsChanged, write=FOnRootSettingsChanged};
	
public:
	__fastcall virtual TcxCustomShellComboBoxProperties(System::Classes::TPersistent* AOwner);
	__fastcall virtual ~TcxCustomShellComboBoxProperties(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual bool __fastcall CompareDisplayValues(const System::Variant &AEditValue1, const System::Variant &AEditValue2);
	__classmethod virtual Cxcontainer::TcxContainerClass __fastcall GetContainerClass();
	virtual System::WideString __fastcall GetDisplayText(const System::Variant &AEditValue, bool AFullText = false, bool AIsInplace = true);
	virtual Cxdatautils::TcxDataEditValueSource __fastcall GetEditValueSource(bool AEditFocused);
	__classmethod virtual Dxcoreclasses::TcxInterfacedPersistentClass __fastcall GetLookupDataClass();
	void __fastcall GetShellDisplayValue(const System::Variant &AEditValue, bool AFocused, /* out */ System::UnicodeString &AText, /* out */ int &AShellSysIconIndex, /* out */ int &AShellSysIconOverlayIndex);
	__classmethod virtual Cxcontainer::TcxContainerViewInfoClass __fastcall GetViewInfoClass();
	virtual bool __fastcall IsEditValueValid(System::Variant &EditValue, bool AEditFocused);
	__property bool DropDownSizeable = {read=GetDropDownSizeable, write=SetDropDownSizeable, default=1};
	__property int DropDownWidth = {read=GetDropDownWidth, write=SetDropDownWidth, default=250};
	__property bool FastSearch = {read=FFastSearch, write=SetFastSearch, default=0};
	__property System::UnicodeString FileMask = {read=FFileMask, write=SetFileMask};
	__property ImmediateDropDownWhenKeyPressed = {default=0};
	__property bool IncrementalSearch = {read=FIncrementalSearch, write=SetIncrementalSearch, default=0};
	__property TcxShellComboBoxRoot* Root = {read=FRoot, write=FRoot};
	__property TcxShellComboBoxShowFullPath ShowFullPath = {read=FShowFullPath, write=SetShowFullPath, default=0};
	__property bool StoreRelativePath = {read=FStoreRelativePath, write=SetStoreRelativePath, default=1};
	__property TcxPopupShellTreeViewOptions TreeViewOptions = {read=FTreeViewOptions, write=SetTreeViewOptions, default=119};
	__property TcxShellComboBoxViewOptions ViewOptions = {read=FViewOptions, write=SetViewOptions, default=0};
	__property Cxshellcontrols::TcxShellAddFolderEvent OnAddFolder = {read=FOnAddFolder, write=FOnAddFolder};
};


class DELPHICLASS TcxShellComboBoxProperties;
class PASCALIMPLEMENTATION TcxShellComboBoxProperties : public TcxCustomShellComboBoxProperties
{
	typedef TcxCustomShellComboBoxProperties inherited;
	
__published:
	__property Alignment;
	__property AssignedValues;
	__property AutoSelect = {default=1};
	__property ButtonGlyph;
	__property ClearKey = {default=0};
	__property DropDownSizeable = {default=1};
	__property DropDownWidth = {default=250};
	__property FastSearch = {default=0};
	__property FileMask = {default=0};
	__property HideSelection = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ImmediateDropDownWhenActivated = {default=0};
	__property ImmediateDropDownWhenKeyPressed = {default=0};
	__property IncrementalSearch = {default=0};
	__property PopupAlignment = {default=0};
	__property ReadOnly;
	__property Root;
	__property ShowFullPath = {default=0};
	__property StoreRelativePath = {default=1};
	__property TreeViewOptions = {default=119};
	__property UseLeftAlignmentOnEditing;
	__property ValidateOnEnter = {default=1};
	__property ViewOptions = {default=0};
	__property OnAddFolder;
	__property OnChange;
	__property OnCloseUp;
	__property OnEditValueChanged;
	__property OnPopup;
public:
	/* TcxCustomShellComboBoxProperties.Create */ inline __fastcall virtual TcxShellComboBoxProperties(System::Classes::TPersistent* AOwner) : TcxCustomShellComboBoxProperties(AOwner) { }
	/* TcxCustomShellComboBoxProperties.Destroy */ inline __fastcall virtual ~TcxShellComboBoxProperties(void) { }
	
};


class DELPHICLASS TcxPopupShellTreeView;
class PASCALIMPLEMENTATION TcxPopupShellTreeView : public Cxshelltreeview::TcxShellTreeView
{
	typedef Cxshelltreeview::TcxShellTreeView inherited;
	
private:
	TcxCustomShellComboBox* __fastcall GetEdit(void);
	
protected:
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DoSelectNode(Cxedit::TcxEditCloseUpReason AClosePopupReason);
	virtual bool __fastcall IsDragAndDropSupported(void);
	__property TcxCustomShellComboBox* Edit = {read=GetEdit};
public:
	/* TcxCustomShellTreeView.Create */ inline __fastcall virtual TcxPopupShellTreeView(System::Classes::TComponent* AOwner) : Cxshelltreeview::TcxShellTreeView(AOwner) { }
	/* TcxCustomShellTreeView.Destroy */ inline __fastcall virtual ~TcxPopupShellTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPopupShellTreeView(HWND ParentWindow) : Cxshelltreeview::TcxShellTreeView(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxPopupShellTreeViewClass;

class DELPHICLASS TcxShellComboBoxPopupWindow;
class PASCALIMPLEMENTATION TcxShellComboBoxPopupWindow : public Cxdropdownedit::TcxPopupEditPopupWindow
{
	typedef Cxdropdownedit::TcxPopupEditPopupWindow inherited;
	
private:
	MESSAGE void __fastcall WMEnable(Winapi::Messages::TMessage &Message);
public:
	/* TcxCustomEditPopupWindow.Create */ inline __fastcall virtual TcxShellComboBoxPopupWindow(Vcl::Controls::TWinControl* AOwnerControl) : Cxdropdownedit::TcxPopupEditPopupWindow(AOwnerControl) { }
	/* TcxCustomEditPopupWindow.Destroy */ inline __fastcall virtual ~TcxShellComboBoxPopupWindow(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxShellComboBoxPopupWindow(System::Classes::TComponent* AOwner, int Dummy) : Cxdropdownedit::TcxPopupEditPopupWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxShellComboBoxPopupWindow(HWND ParentWindow) : Cxdropdownedit::TcxPopupEditPopupWindow(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxCustomShellComboBox : public Cxdropdownedit::TcxCustomPopupEdit
{
	typedef Cxdropdownedit::TcxCustomPopupEdit inherited;
	
private:
	_ITEMIDLIST *FAbsolutePIDL;
	Cxshellcontrols::TcxShellDependedControls* FDependedControls;
	bool FIsDependentShellControlsNotification;
	bool FNotificationFromDependentShellControls;
	bool FIsSelectedNodeChangeEventLocked;
	TcxPopupShellTreeView* FPopupShellTreeView;
	bool FPopupWindowShowing;
	Cxshelllistview::TcxCustomShellListView* FShellListView;
	Cxshelltreeview::TcxCustomShellTreeView* FShellTreeView;
	void __fastcall AddFolderHandler(System::TObject* Sender, Cxshellcommon::TcxShellFolder* AFolder, bool &ACanAdd);
	Winapi::Shlobj::PItemIDList __fastcall GetAbsolutePIDL(void);
	HIDESBASE TcxCustomShellComboBoxProperties* __fastcall GetActiveProperties(void);
	System::UnicodeString __fastcall GetPath(void);
	HIDESBASE TcxCustomShellComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE TcxShellComboBoxViewInfo* __fastcall GetViewInfo(void);
	void __fastcall RootChangeHandler(System::TObject* Sender);
	void __fastcall RootSettingsChanged(System::TObject* Sender);
	void __fastcall SetAbsolutePIDL(Winapi::Shlobj::PItemIDList Value);
	void __fastcall SetPath(const System::UnicodeString Value);
	HIDESBASE void __fastcall SetProperties(TcxCustomShellComboBoxProperties* Value);
	void __fastcall SetRelativePIDL(Winapi::Shlobj::PItemIDList Value);
	void __fastcall SetShellListView(Cxshelllistview::TcxCustomShellListView* Value);
	void __fastcall SetShellTreeView(Cxshelltreeview::TcxCustomShellTreeView* Value);
	MESSAGE void __fastcall DSMDoNavigate(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall DSMSynchronizeRoot(Winapi::Messages::TMessage &Message);
	
protected:
	virtual bool __fastcall CanDropDown(void);
	virtual void __fastcall CloseUp(Cxedit::TcxEditCloseUpReason AReason);
	virtual void __fastcall CreatePopupWindow(void);
	virtual void __fastcall DoInitPopup(void);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall HandleSelectItem(System::TObject* Sender);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall InitializePopupWindow(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	DYNAMIC void __fastcall PopupWindowShowed(System::TObject* Sender);
	DYNAMIC void __fastcall PopupWindowShowing(System::TObject* Sender);
	virtual void __fastcall PropertiesChanged(System::TObject* Sender);
	virtual void __fastcall SynchronizeDisplayValue(void);
	virtual void __fastcall SynchronizeEditValue(void);
	bool __fastcall CheckAbsolutePIDL(Winapi::Shlobj::PItemIDList &APIDL, bool ACheckObjectExistence);
	void __fastcall CheckPopupShellTreeView(void);
	Vcl::Comctrls::TTreeNode* __fastcall FindNodeAmongExpandedNodes(System::UnicodeString ANodeText);
	virtual TcxPopupShellTreeViewClass __fastcall GetPopupShellTreeViewClass(void);
	void __fastcall InternalSetAbsolutePIDL(Winapi::Shlobj::PItemIDList Value);
	virtual void __fastcall InternalSynchronizeEditValue(Winapi::Shlobj::PItemIDList APIDL, const System::UnicodeString ADisplayText = System::UnicodeString());
	void __fastcall InvalidateShellIconRect(void);
	virtual void __fastcall SelectedNodeChangeHandler(System::TObject* Sender, Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall SynchronizeDependentShellControls(void);
	void __fastcall SynchronizePopupShellTreeView(void);
	Vcl::Comctrls::TTreeNode* __fastcall TraverseAllVisibleNodes(int &ANodeIndex, Vcl::Comctrls::TTreeNode* ATreeNode = (Vcl::Comctrls::TTreeNode*)(0x0));
	Cxshellcontrols::TcxShellDependedControls* __fastcall GetDependedControls(void);
	Cxshellcommon::TcxCustomShellRoot* __fastcall GetRoot(void);
	__property Cxshellcontrols::TcxShellDependedControls* DependedControls = {read=FDependedControls};
	__property Cxshelllistview::TcxCustomShellListView* ShellListView = {read=FShellListView, write=SetShellListView};
	__property Cxshelltreeview::TcxCustomShellTreeView* ShellTreeView = {read=FShellTreeView, write=SetShellTreeView};
	__property TcxShellComboBoxViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__fastcall virtual TcxCustomShellComboBox(System::Classes::TComponent* AOwner)/* overload */;
	__fastcall virtual ~TcxCustomShellComboBox(void);
	virtual bool __fastcall CanHide(void);
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property Winapi::Shlobj::PItemIDList AbsolutePIDL = {read=GetAbsolutePIDL, write=SetAbsolutePIDL};
	__property System::UnicodeString AbsolutePath = {read=GetPath, write=SetPath};
	__property TcxCustomShellComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	__property System::UnicodeString Path = {read=GetPath, write=SetPath};
	__property TcxPopupShellTreeView* PopupShellTreeView = {read=FPopupShellTreeView};
	__property TcxCustomShellComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property Winapi::Shlobj::PItemIDList RelativePIDL = {write=SetRelativePIDL};
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxCustomShellComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : Cxdropdownedit::TcxCustomPopupEdit(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxCustomShellComboBox(HWND ParentWindow) : Cxdropdownedit::TcxCustomPopupEdit(ParentWindow) { }
	
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


class DELPHICLASS TcxShellComboBox;
class PASCALIMPLEMENTATION TcxShellComboBox : public TcxCustomShellComboBox
{
	typedef TcxCustomShellComboBox inherited;
	
private:
	HIDESBASE TcxShellComboBoxProperties* __fastcall GetActiveProperties(void);
	HIDESBASE TcxShellComboBoxProperties* __fastcall GetProperties(void);
	HIDESBASE void __fastcall SetProperties(TcxShellComboBoxProperties* Value);
	
public:
	__classmethod virtual Cxedit::TcxCustomEditPropertiesClass __fastcall GetPropertiesClass();
	__property TcxShellComboBoxProperties* ActiveProperties = {read=GetActiveProperties};
	
__published:
	__property Anchors = {default=3};
	__property AutoSize = {default=1};
	__property BeepOnEnter = {default=1};
	__property Constraints;
	__property DragCursor = {default=-12};
	__property DragKind = {default=0};
	__property DragMode = {default=0};
	__property Enabled = {default=1};
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property ParentColor = {default=0};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property TcxShellComboBoxProperties* Properties = {read=GetProperties, write=SetProperties};
	__property ShellListView;
	__property ShellTreeView;
	__property ShowHint;
	__property Style;
	__property StyleDisabled;
	__property StyleFocused;
	__property StyleHot;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property OnClick;
	__property OnContextPopup;
	__property OnDblClick;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnEditing;
	__property OnEndDock;
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseEnter;
	__property OnMouseLeave;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDock;
	__property OnStartDrag;
public:
	/* TcxCustomShellComboBox.Create */ inline __fastcall virtual TcxShellComboBox(System::Classes::TComponent* AOwner)/* overload */ : TcxCustomShellComboBox(AOwner) { }
	/* TcxCustomShellComboBox.Destroy */ inline __fastcall virtual ~TcxShellComboBox(void) { }
	
public:
	/* TcxCustomEdit.Create */ inline __fastcall virtual TcxShellComboBox(System::Classes::TComponent* AOwner, bool AIsInplace)/* overload */ : TcxCustomShellComboBox(AOwner, AIsInplace) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxShellComboBox(HWND ParentWindow) : TcxCustomShellComboBox(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE Vcl::Imglist::TCustomImageList* __fastcall cxShellComboBoxImageList(void);
}	/* namespace Cxshellcombobox */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXSHELLCOMBOBOX)
using namespace Cxshellcombobox;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxshellcomboboxHPP
