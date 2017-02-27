// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxdbtree.pas' rev: 24.00 (Win64)

#ifndef DxdbtreeHPP
#define DxdbtreeHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxtree.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdbtree
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS EDBTreeViewError;
class PASCALIMPLEMENTATION EDBTreeViewError : public Dxcore::EdxException
{
	typedef Dxcore::EdxException inherited;
	
public:
	/* Exception.Create */ inline __fastcall EDBTreeViewError(const System::UnicodeString Msg) : Dxcore::EdxException(Msg) { }
	/* Exception.CreateFmt */ inline __fastcall EDBTreeViewError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size) : Dxcore::EdxException(Msg, Args, Args_Size) { }
	/* Exception.CreateRes */ inline __fastcall EDBTreeViewError(NativeUInt Ident)/* overload */ : Dxcore::EdxException(Ident) { }
	/* Exception.CreateRes */ inline __fastcall EDBTreeViewError(System::PResStringRec ResStringRec)/* overload */ : Dxcore::EdxException(ResStringRec) { }
	/* Exception.CreateResFmt */ inline __fastcall EDBTreeViewError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size) { }
	/* Exception.CreateResFmt */ inline __fastcall EDBTreeViewError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size) { }
	/* Exception.CreateHelp */ inline __fastcall EDBTreeViewError(const System::UnicodeString Msg, int AHelpContext) : Dxcore::EdxException(Msg, AHelpContext) { }
	/* Exception.CreateFmtHelp */ inline __fastcall EDBTreeViewError(const System::UnicodeString Msg, System::TVarRec const *Args, const int Args_Size, int AHelpContext) : Dxcore::EdxException(Msg, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDBTreeViewError(NativeUInt Ident, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, AHelpContext) { }
	/* Exception.CreateResHelp */ inline __fastcall EDBTreeViewError(System::PResStringRec ResStringRec, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDBTreeViewError(System::PResStringRec ResStringRec, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(ResStringRec, Args, Args_Size, AHelpContext) { }
	/* Exception.CreateResFmtHelp */ inline __fastcall EDBTreeViewError(NativeUInt Ident, System::TVarRec const *Args, const int Args_Size, int AHelpContext)/* overload */ : Dxcore::EdxException(Ident, Args, Args_Size, AHelpContext) { }
	/* Exception.Destroy */ inline __fastcall virtual ~EDBTreeViewError(void) { }
	
};


class DELPHICLASS TDataLinkTreeView;
class DELPHICLASS TdxDBTreeView;
class PASCALIMPLEMENTATION TDataLinkTreeView : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	TdxDBTreeView* FDBTreeView;
	System::UnicodeString Filter;
	bool Filtered;
	
protected:
	virtual void __fastcall ActiveChanged(void);
	virtual void __fastcall DataSetChanged(void);
	virtual void __fastcall DataSetScrolled(int Distance);
	virtual void __fastcall RecordChanged(Data::Db::TField* Field);
	
public:
	__fastcall TDataLinkTreeView(void);
public:
	/* TDataLink.Destroy */ inline __fastcall virtual ~TDataLinkTreeView(void) { }
	
};


class DELPHICLASS TdxDBTreeNode;
class DELPHICLASS TdxDBTreeNodes;
class PASCALIMPLEMENTATION TdxDBTreeNode : public Dxtree::TdxTreeNode
{
	typedef Dxtree::TdxTreeNode inherited;
	
private:
	bool IsInserting;
	bool Refreshed;
	
protected:
	TdxDBTreeNodes* DBTreeNodes;
	System::Variant FKeyFieldValue;
	System::Variant FParentFieldValue;
	bool FChildLoaded;
	int FIndex;
	System::UnicodeString FListText;
	System::Uitypes::TColor FBkColor;
	System::Uitypes::TColor FColor;
	System::Uitypes::TFontStyles FFontStyle;
	System::Uitypes::TFontName FFontName;
	bool FIsCustomDraw;
	HIDESBASE TdxDBTreeNode* __fastcall GetParent(void);
	void __fastcall SetChildLoaded(bool Value);
	void __fastcall SetIsCustomDraw(bool Value);
	void __fastcall SetKeyFieldValue(System::Variant &Value);
	void __fastcall SetParentFieldValue(System::Variant &Value);
	void __fastcall UpdateImages(void);
	__property TdxDBTreeNode* Parent = {read=GetParent};
	
public:
	__fastcall TdxDBTreeNode(TdxDBTreeNodes* AOwner, System::Variant &Value)/* overload */;
	__fastcall virtual ~TdxDBTreeNode(void);
	void __fastcall LoadChildren(bool ARecursive);
	__property System::Uitypes::TColor BkColor = {read=FBkColor, write=FBkColor, nodefault};
	__property System::Uitypes::TColor Color = {read=FColor, write=FColor, nodefault};
	__property System::Uitypes::TFontStyles FontStyle = {read=FFontStyle, write=FFontStyle, nodefault};
	__property System::Uitypes::TFontName FontName = {read=FFontName, write=FFontName};
	__property bool IsCustomDraw = {read=FIsCustomDraw, write=SetIsCustomDraw, nodefault};
	__property bool ChildLoaded = {read=FChildLoaded, write=SetChildLoaded, nodefault};
	__property int Index = {read=FIndex, nodefault};
	__property System::Variant KeyFieldValue = {read=FKeyFieldValue};
	__property System::Variant ParentFieldValue = {read=FParentFieldValue};
};


class PASCALIMPLEMENTATION TdxDBTreeNodes : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	TdxDBTreeNode* operator[](int Index) { return Items[Index]; }
	
private:
	TdxDBTreeView* FDBTreeView;
	System::Classes::TList* FList;
	int FCustomDrawCount;
	bool Destroying;
	TdxDBTreeNode* __fastcall GetDBNodeFromIndex(int Index);
	System::Variant __fastcall GetMaxKeyFieldValue(void);
	
protected:
	void __fastcall BeginRefreshRecord(void);
	void __fastcall EndRefreshRecord(void);
	bool __fastcall FindNearest(System::Variant &Value, int &Index);
	void __fastcall Clear(void);
	void __fastcall Delete(TdxDBTreeNode* ADBTreeNode);
	void __fastcall NodeChangeParent(Vcl::Comctrls::TTreeNode* ATreeNode, System::Variant &Value);
	TdxDBTreeNode* __fastcall RefreshRecord(void);
	void __fastcall RefreshParents(void);
	
public:
	__fastcall TdxDBTreeNodes(TdxDBTreeView* ADBTreeView);
	__fastcall virtual ~TdxDBTreeNodes(void);
	int __fastcall Count(void);
	System::Variant __fastcall GetKeyFieldValue(Vcl::Comctrls::TTreeNode* Value);
	System::Variant __fastcall GetParentValue(Vcl::Comctrls::TTreeNode* Value);
	TdxDBTreeNode* __fastcall GetDBTreeNode(System::Variant &Value);
	Vcl::Comctrls::TTreeNode* __fastcall GetTreeNode(System::Variant &Value);
	int __fastcall IndexOf(Vcl::Comctrls::TTreeNode* Value);
	__property TdxDBTreeNode* Items[int Index] = {read=GetDBNodeFromIndex/*, default*/};
	__property System::Variant MaxKeyFieldValue = {read=GetMaxKeyFieldValue};
};


typedef void __fastcall (__closure *TAddNewDBTreeNodeEvent)(System::TObject* Sender, TdxDBTreeNode* &DBTreeNode);

typedef void __fastcall (__closure *TDBTreeRefreshNodeEvent)(System::TObject* Sender, TdxDBTreeNode* DBTreeNode);

typedef void __fastcall (__closure *TCreateNewKeyValue)(System::TObject* Sender, System::Variant &NewKeyValue);

typedef void __fastcall (__closure *TSetDisplayItemText)(System::TObject* Sender, System::UnicodeString &DisplayText);

enum TdxDBTreeViewOption : unsigned char { trDBCanDelete, trDBConfirmDelete, trCanDBNavigate, trSmartRecordLoad, trSmartRecordCopy, trCheckHasChildren };

typedef System::Set<TdxDBTreeViewOption, TdxDBTreeViewOption::trDBCanDelete, TdxDBTreeViewOption::trCheckHasChildren>  TdxDBTreeViewOptions;

enum TdxDBTreeViewAction : unsigned char { trDBInsert, trDBDelete, trDBChangeText, trDBChangeParent, trDBMove };

typedef void __fastcall (__closure *TdxDBTreeViewActionEvent)(System::TObject* Sender, TdxDBTreeNode* DBNode1, TdxDBTreeNode* DBNode2, TdxDBTreeViewAction Action, bool &Automatic);

class PASCALIMPLEMENTATION TdxDBTreeView : public Dxtree::TCustomdxTreeView
{
	typedef Dxtree::TCustomdxTreeView inherited;
	
private:
	bool FIsRecordEditing;
	int FLockCount;
	bool CNNotifyFlag;
	TDataLinkTreeView* FDataLink;
	TdxDBTreeNodes* FDBTreeNodes;
	TAddNewDBTreeNodeEvent FAddNewItem;
	TCreateNewKeyValue FCreateNewKeyValue;
	TSetDisplayItemText FOnSetDisplayItemText;
	System::Classes::TNotifyEvent FOnInsertNodeError;
	bool FRaiseOnError;
	TdxDBTreeViewActionEvent FOnDBAction;
	TDBTreeRefreshNodeEvent FOnRefreshNode;
	System::UnicodeString FKeyFieldName;
	System::UnicodeString FListFieldName;
	System::UnicodeString FParentFieldName;
	System::UnicodeString FDisplayFieldName;
	System::UnicodeString FImageIndexFieldName;
	System::UnicodeString FStateIndexFieldName;
	System::Variant FRootValue;
	System::UnicodeString FSeparatedSt;
	TdxDBTreeViewOptions FOptions;
	Data::Db::TField* FImageIndexField;
	Data::Db::TField* FKeyField;
	Data::Db::TField* FListField;
	System::Classes::TList* FDisplayFields;
	Data::Db::TField* FParentField;
	Data::Db::TField* FStateIndexField;
	void *FEditInstance;
	void *FDefEditProc;
	HWND FEditHandle;
	void __fastcall AssignFields(void);
	void __fastcall DataLinkActiveChanged(void);
	void __fastcall DataLinkRecordChanged(Data::Db::TField* Field);
	void __fastcall DataChanged(void);
	void __fastcall RecordEdit(Data::Db::TField* Field);
	void __fastcall RecordInsert(Data::Db::TField* Field);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	TdxDBTreeNode* __fastcall GetSeletectedDBTreeNode(void);
	void __fastcall Scroll(void);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetDisplayFieldName(const System::UnicodeString Value);
	void __fastcall SetImageIndexFieldName(const System::UnicodeString Value);
	void __fastcall SetKeyFieldName(const System::UnicodeString Value);
	void __fastcall SetListFieldName(const System::UnicodeString Value);
	void __fastcall SetRootValue(const System::Variant &Value);
	void __fastcall SetStateIndexFieldName(const System::UnicodeString Value);
	void __fastcall SetOptions(const TdxDBTreeViewOptions Value);
	void __fastcall SetParentFieldName(const System::UnicodeString Value);
	void __fastcall SetSeparatedSt(const System::UnicodeString Value);
	TdxDBTreeNode* __fastcall AddNode(TdxDBTreeNode* AParentNode, const System::UnicodeString AText);
	void __fastcall SetNodeParent(TdxDBTreeNode* ANode, TdxDBTreeNode* AParent);
	System::UnicodeString __fastcall GetDisplayText(void);
	HIDESBASE void __fastcall DoCNNotify(Winapi::Messages::TWMNotify &Message);
	void __fastcall DoWMPaint(Winapi::Messages::TMessage &Message);
	void __fastcall DoVMInsertItem(Winapi::Messages::TMessage &Message);
	void __fastcall DoVMSelectItem(Winapi::Messages::TMessage &Message);
	void __fastcall DoVMSetItem(Winapi::Messages::TMessage &Message);
	void __fastcall DoVMExpand(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	MESSAGE void __fastcall VM_INSERTITEM(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall VM_SELECTITEM(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall VM_SETITEM(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall VM_EXPAND(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMPAINT(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMUpdateImages(Winapi::Messages::TMessage &Message);
	HIDESBASE void __fastcall EditWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall FrameSelectedItem(void);
	void __fastcall DeleteDBNode(System::Variant &AKeyValue);
	void __fastcall InsertTreeNode(TdxDBTreeNode* ANode, TdxDBTreeNode* AParent);
	void __fastcall SetNewTreeNodeParent(TdxDBTreeNode* ANode, TdxDBTreeNode* ANewParent);
	
protected:
	DYNAMIC bool __fastcall CanExpand(Vcl::Comctrls::TTreeNode* Node);
	DYNAMIC bool __fastcall DoDBAction(TdxDBTreeNode* DBNode1, TdxDBTreeNode* DBNode2, TdxDBTreeViewAction Action);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall CreateHandle(void);
	DYNAMIC void __fastcall Change(Vcl::Comctrls::TTreeNode* ANode);
	virtual void __fastcall DoCustomDraw(Vcl::Comctrls::TTreeNode* TreeNode, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, System::Uitypes::TColor &ABkColor);
	virtual System::UnicodeString __fastcall GetListItemText(Vcl::Comctrls::TTreeNode* TreeNode);
	DYNAMIC void __fastcall Edit(const tagTVITEMW &Item);
	virtual void __fastcall InsertTreeNodeStructure(System::Classes::TList* ListS, System::Classes::TList* ListD);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	System::Variant __fastcall GetNextMaxKeyValue(void);
	bool __fastcall IsUpdateLocked(void);
	void __fastcall BeginUpdate(void);
	void __fastcall EndUpdate(void);
	bool __fastcall LockedLocate(const System::UnicodeString AFieldName, System::Variant &AValue, Data::Db::TLocateOptions AOptions);
	
public:
	__fastcall virtual TdxDBTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDBTreeView(void);
	virtual Vcl::Comctrls::TTreeNode* __fastcall CreateNode(void);
	virtual void __fastcall GetNodeStructure(Vcl::Comctrls::TTreeNode* TreeNode, System::Classes::TList* List);
	Data::Db::TField* __fastcall GetImageIndexField(void);
	Data::Db::TField* __fastcall GetKeyField(void);
	Data::Db::TField* __fastcall GetListField(void);
	Data::Db::TField* __fastcall GetParentField(void);
	Data::Db::TField* __fastcall GetStateIndexField(void);
	void __fastcall GotoKeyFieldValue(System::Variant &Value);
	virtual bool __fastcall IsCustomDraw(void);
	void __fastcall RefreshItems(void);
	__property TdxDBTreeNode* DBSelected = {read=GetSeletectedDBTreeNode};
	__property TdxDBTreeNodes* DBTreeNodes = {read=FDBTreeNodes};
	__property Items;
	__property Selected;
	
__published:
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property System::UnicodeString DisplayField = {read=FDisplayFieldName, write=SetDisplayFieldName};
	__property System::UnicodeString ImageIndexField = {read=FImageIndexFieldName, write=SetImageIndexFieldName};
	__property System::UnicodeString KeyField = {read=FKeyFieldName, write=SetKeyFieldName};
	__property System::UnicodeString ListField = {read=FListFieldName, write=SetListFieldName};
	__property System::UnicodeString ParentField = {read=FParentFieldName, write=SetParentFieldName};
	__property System::Variant RootValue = {read=FRootValue, write=SetRootValue};
	__property System::UnicodeString SeparatedSt = {read=FSeparatedSt, write=SetSeparatedSt};
	__property System::UnicodeString StateIndexField = {read=FStateIndexFieldName, write=SetStateIndexFieldName};
	__property bool RaiseOnError = {read=FRaiseOnError, write=FRaiseOnError, nodefault};
	__property ShowButtons = {default=1};
	__property BorderStyle = {default=1};
	__property DragCursor = {default=-12};
	__property ShowLines = {default=1};
	__property ShowRoot = {default=1};
	__property ReadOnly = {default=0};
	__property DragMode = {default=0};
	__property HideSelection = {default=1};
	__property Indent;
	__property OnEditing;
	__property OnEdited;
	__property OnExpanding;
	__property OnExpanded;
	__property OnCollapsing;
	__property OnCompare;
	__property OnCollapsed;
	__property OnChanging;
	__property OnChange;
	__property OnDeletion;
	__property OnGetImageIndex;
	__property OnGetSelectedIndex;
	__property Align = {default=0};
	__property Enabled = {default=1};
	__property Font;
	__property Color = {default=-16777211};
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property Ctl3D;
	__property TdxDBTreeViewOptions Options = {read=FOptions, write=SetOptions, default=0};
	__property SortType = {default=0};
	__property SelectedIndex;
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
	__property TAddNewDBTreeNodeEvent OnAddNewItem = {read=FAddNewItem, write=FAddNewItem};
	__property TCreateNewKeyValue OnCreateNewKeyValue = {read=FCreateNewKeyValue, write=FCreateNewKeyValue};
	__property TSetDisplayItemText OnSetDisplayItemText = {read=FOnSetDisplayItemText, write=FOnSetDisplayItemText};
	__property System::Classes::TNotifyEvent OnInsertNodeError = {read=FOnInsertNodeError, write=FOnInsertNodeError};
	__property TdxDBTreeViewActionEvent OnDBAction = {read=FOnDBAction, write=FOnDBAction};
	__property TDBTreeRefreshNodeEvent OnRefreshNode = {read=FOnRefreshNode, write=FOnRefreshNode};
	__property OnClick;
	__property OnEnter;
	__property OnExit;
	__property OnDragDrop;
	__property OnDragOver;
	__property OnStartDrag;
	__property OnEndDrag;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnDblClick;
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property PopupMenu;
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property ShowHint;
	__property Images;
	__property StateImages;
	__property OnContextPopup;
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDBTreeView(HWND ParentWindow) : Dxtree::TCustomdxTreeView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdbtree */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDBTREE)
using namespace Dxdbtree;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdbtreeHPP
