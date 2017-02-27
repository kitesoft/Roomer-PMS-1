// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxdbtrel.pas' rev: 24.00 (Win32)

#ifndef DxdbtrelHPP
#define DxdbtrelHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Data.DB.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxdbtree.hpp>	// Pascal unit
#include <dxtree.hpp>	// Pascal unit
#include <Vcl.DBCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxCommon.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxdbtrel
{
//-- type declarations -------------------------------------------------------
enum TTVTextStyle : unsigned char { tvtsShort, tvtsFull };

typedef void __fastcall (__closure *TdxTreeViewCloseUp)(System::TObject* Sender, bool Accept);

class DELPHICLASS TCustomdxVTreeViewEdit;
class PASCALIMPLEMENTATION TCustomdxVTreeViewEdit : public Vcl::Controls::TCustomControl
{
	typedef Vcl::Controls::TCustomControl inherited;
	
private:
	bool FCanSelectParents;
	System::Classes::TAlignment FAlignment;
	bool FFocused;
	int FButtonWidth;
	System::WideChar FDividedChar;
	int FDropDownRows;
	bool FListVisible;
	System::Classes::TNotifyEvent FOnDropDown;
	TdxTreeViewCloseUp FOnCloseUp;
	System::UnicodeString FText;
	TTVTextStyle FTextStyle;
	Vcl::Comctrls::TTVExpandedEvent FOnGetSelectedIndex;
	Vcl::Comctrls::TTVExpandedEvent FOnGetImageIndex;
	int FDropDownWidth;
	bool FPressed;
	Vcl::Forms::TCustomForm* FOldParentForm;
	void __fastcall SetDividedChar(System::WideChar Value);
	HIDESBASE void __fastcall SetText(System::UnicodeString Value);
	bool __fastcall CanSelectTreeNode(Vcl::Comctrls::TTreeNode* ANode);
	Dxtree::TTreeViewCustomDraw __fastcall GetCustomDraw(void);
	System::Uitypes::TColor __fastcall GetTreeViewColor(void);
	System::Uitypes::TCursor __fastcall GetTreeViewCursor(void);
	Vcl::Graphics::TFont* __fastcall GetTreeViewFont(void);
	System::UnicodeString __fastcall GetTreeViewHint(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetTreeViewImages(void);
	int __fastcall GetTreeViewIndent(void);
	Vcl::Menus::TPopupMenu* __fastcall GetTreeViewPopupMenu(void);
	bool __fastcall GetTreeViewReadOnly(void);
	Vcl::Comctrls::TTreeNode* __fastcall GetSelectedTreeNode(void);
	bool __fastcall GetTreeViewShowButtons(void);
	bool __fastcall GetTreeViewShowHint(void);
	bool __fastcall GetTreeViewShowLines(void);
	bool __fastcall GetTreeViewShowRoot(void);
	Vcl::Comctrls::TSortType __fastcall GetTreeViewSortType(void);
	Vcl::Imglist::TCustomImageList* __fastcall GetTreeViewStateImages(void);
	void __fastcall SetCustomDraw(Dxtree::TTreeViewCustomDraw Value);
	void __fastcall SetTreeViewColor(System::Uitypes::TColor Value);
	void __fastcall SetTreeViewCursor(System::Uitypes::TCursor Value);
	void __fastcall SetTreeViewFont(Vcl::Graphics::TFont* Value);
	void __fastcall SetTreeViewHint(System::UnicodeString Value);
	void __fastcall SetTreeViewImages(Vcl::Imglist::TCustomImageList* Value);
	void __fastcall SetTreeViewIndent(int Value);
	void __fastcall SetTreeViewPopupMenu(Vcl::Menus::TPopupMenu* Value);
	void __fastcall SetTreeViewReadOnly(bool Value);
	void __fastcall SetTreeViewShowButtons(bool Value);
	void __fastcall SetTreeViewShowHint(bool Value);
	void __fastcall SetTreeViewShowLines(bool Value);
	void __fastcall SetTreeViewShowRoot(bool Value);
	void __fastcall SetTreeViewSortType(Vcl::Comctrls::TSortType Value);
	void __fastcall SetTreeViewStateImages(Vcl::Imglist::TCustomImageList* Value);
	HIDESBASE MESSAGE void __fastcall CMCtl3DChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMFontChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall CMMouseLeave(Winapi::Messages::TMessage &Message);
	MESSAGE void __fastcall WMGetDlgCode(Winapi::Messages::TWMNoParams &Message);
	HIDESBASE MESSAGE void __fastcall WMKillFocus(Winapi::Messages::TWMKillFocus &Message);
	HIDESBASE MESSAGE void __fastcall WMSetFocus(Winapi::Messages::TWMSetFocus &Message);
	int __fastcall GetBorderSize(void);
	int __fastcall GetTextHeight(void);
	void __fastcall AllowChangeTreeNode(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node, bool &AllowChange);
	void __fastcall ClickTreeView(System::TObject* Sender);
	void __fastcall DblClickTreeView(System::TObject* Sender);
	
protected:
	virtual Dxtree::TCustomdxTreeView* __fastcall VirtualTreeView(void) = 0 ;
	virtual bool __fastcall IsReadOnly(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual void __fastcall Paint(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	DYNAMIC void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	DYNAMIC void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall DropDownOk(void);
	virtual void __fastcall CreateVirtualTreeView(void);
	virtual void __fastcall PrepareDropDown(void);
	virtual System::UnicodeString __fastcall GetPaintedText(void);
	__property System::Classes::TAlignment Alignment = {read=FAlignment, write=FAlignment, nodefault};
	__property System::WideChar DividedChar = {read=FDividedChar, write=SetDividedChar, nodefault};
	__property TTVTextStyle TextStyle = {read=FTextStyle, write=FTextStyle, nodefault};
	__property Vcl::Comctrls::TTreeNode* Selected = {read=GetSelectedTreeNode};
	
public:
	__fastcall virtual TCustomdxVTreeViewEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxVTreeViewEdit(void);
	virtual void __fastcall SetBounds(int ALeft, int ATop, int AWidth, int AHeight);
	virtual void __fastcall CloseUp(bool Accept);
	virtual void __fastcall DropDown(void);
	
__published:
	__property bool CanSelectParents = {read=FCanSelectParents, write=FCanSelectParents, nodefault};
	__property Color = {default=-16777211};
	__property Ctl3D;
	__property DragCursor = {default=-12};
	__property DragMode = {default=0};
	__property int DropDownRows = {read=FDropDownRows, write=FDropDownRows, default=7};
	__property int DropDownWidth = {read=FDropDownWidth, write=FDropDownWidth, default=0};
	__property Enabled = {default=1};
	__property Font;
	__property ParentColor = {default=1};
	__property ParentCtl3D = {default=1};
	__property ParentFont = {default=1};
	__property ParentShowHint = {default=1};
	__property PopupMenu;
	__property ShowHint;
	__property TabOrder = {default=-1};
	__property TabStop = {default=0};
	__property System::UnicodeString Text = {read=FText, write=SetText};
	__property System::Uitypes::TColor TreeViewColor = {read=GetTreeViewColor, write=SetTreeViewColor, nodefault};
	__property System::Uitypes::TCursor TreeViewCursor = {read=GetTreeViewCursor, write=SetTreeViewCursor, nodefault};
	__property Vcl::Graphics::TFont* TreeViewFont = {read=GetTreeViewFont, write=SetTreeViewFont};
	__property System::UnicodeString TreeViewHint = {read=GetTreeViewHint, write=SetTreeViewHint};
	__property Vcl::Imglist::TCustomImageList* TreeViewImages = {read=GetTreeViewImages, write=SetTreeViewImages};
	__property int TreeViewIndent = {read=GetTreeViewIndent, write=SetTreeViewIndent, nodefault};
	__property Vcl::Menus::TPopupMenu* TreeViewPopupMenu = {read=GetTreeViewPopupMenu, write=SetTreeViewPopupMenu};
	__property bool TreeViewReadOnly = {read=GetTreeViewReadOnly, write=SetTreeViewReadOnly, nodefault};
	__property bool TreeViewShowButtons = {read=GetTreeViewShowButtons, write=SetTreeViewShowButtons, nodefault};
	__property bool TreeViewShowHint = {read=GetTreeViewShowHint, write=SetTreeViewShowHint, nodefault};
	__property bool TreeViewShowLines = {read=GetTreeViewShowLines, write=SetTreeViewShowLines, nodefault};
	__property bool TreeViewShowRoot = {read=GetTreeViewShowRoot, write=SetTreeViewShowRoot, nodefault};
	__property Vcl::Comctrls::TSortType TreeViewSortType = {read=GetTreeViewSortType, write=SetTreeViewSortType, nodefault};
	__property Vcl::Imglist::TCustomImageList* TreeViewStateImages = {read=GetTreeViewStateImages, write=SetTreeViewStateImages};
	__property Visible = {default=1};
	__property TdxTreeViewCloseUp OnCloseUp = {read=FOnCloseUp, write=FOnCloseUp};
	__property OnClick;
	__property Dxtree::TTreeViewCustomDraw OnCustomDraw = {read=GetCustomDraw, write=SetCustomDraw};
	__property OnDragDrop;
	__property OnDragOver;
	__property System::Classes::TNotifyEvent OnDropDown = {read=FOnDropDown, write=FOnDropDown};
	__property OnEndDrag;
	__property OnEnter;
	__property OnExit;
	__property Vcl::Comctrls::TTVExpandedEvent OnGetSelectedIndex = {read=FOnGetSelectedIndex, write=FOnGetSelectedIndex};
	__property Vcl::Comctrls::TTVExpandedEvent OnGetImageIndex = {read=FOnGetImageIndex, write=FOnGetImageIndex};
	__property OnKeyDown;
	__property OnKeyPress;
	__property OnKeyUp;
	__property OnMouseDown;
	__property OnMouseMove;
	__property OnMouseUp;
	__property OnStartDrag;
	__property Anchors = {default=3};
	__property Constraints;
	__property OnStartDock;
	__property OnEndDock;
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomdxVTreeViewEdit(HWND ParentWindow) : Vcl::Controls::TCustomControl(ParentWindow) { }
	
};


class DELPHICLASS TCustomdxTreeViewEdit;
class PASCALIMPLEMENTATION TCustomdxTreeViewEdit : public TCustomdxVTreeViewEdit
{
	typedef TCustomdxVTreeViewEdit inherited;
	
private:
	System::Classes::TMemoryStream* FMemStream;
	System::Classes::TMemoryStream* FImagesStream;
	Vcl::Comctrls::TTreeNode* FOldSelected;
	Dxtree::TdxTreeView* FTreeView;
	Vcl::Comctrls::TTreeNodes* __fastcall GetItems(void);
	void __fastcall SetItems(Vcl::Comctrls::TTreeNodes* Value);
	void __fastcall SaveNodesToStream(void);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual Dxtree::TCustomdxTreeView* __fastcall VirtualTreeView(void);
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall DestroyWnd(void);
	virtual void __fastcall DestroyWindowHandle(void);
	virtual void __fastcall PrepareDropDown(void);
	void __fastcall SearchTreeNode(void);
	
public:
	__fastcall virtual TCustomdxTreeViewEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxTreeViewEdit(void);
	virtual void __fastcall CloseUp(bool Accept);
	virtual void __fastcall DropDown(void);
	Vcl::Comctrls::TTreeNode* __fastcall GetTreeNodeByText(Vcl::Comctrls::TTreeNode* ParentTreeNode, System::UnicodeString Text, bool flag);
	__property Selected;
	
__published:
	__property DividedChar;
	__property Vcl::Comctrls::TTreeNodes* Items = {read=GetItems, write=SetItems};
	__property TextStyle;
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomdxTreeViewEdit(HWND ParentWindow) : TCustomdxVTreeViewEdit(ParentWindow) { }
	
};


class DELPHICLASS TdxTreeViewEdit;
class PASCALIMPLEMENTATION TdxTreeViewEdit : public TCustomdxTreeViewEdit
{
	typedef TCustomdxTreeViewEdit inherited;
	
__published:
	__property Alignment;
public:
	/* TCustomdxTreeViewEdit.Create */ inline __fastcall virtual TdxTreeViewEdit(System::Classes::TComponent* AOwner) : TCustomdxTreeViewEdit(AOwner) { }
	/* TCustomdxTreeViewEdit.Destroy */ inline __fastcall virtual ~TdxTreeViewEdit(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxTreeViewEdit(HWND ParentWindow) : TCustomdxTreeViewEdit(ParentWindow) { }
	
};


class DELPHICLASS TdxDBTreeViewEdit;
class PASCALIMPLEMENTATION TdxDBTreeViewEdit : public TCustomdxTreeViewEdit
{
	typedef TCustomdxTreeViewEdit inherited;
	
private:
	Vcl::Dbctrls::TFieldDataLink* FDataLink;
	Vcl::Controls::TControlCanvas* FCanvas;
	void __fastcall DataChange(System::TObject* Sender);
	System::UnicodeString __fastcall GetDataField(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	Data::Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const System::UnicodeString Value);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMExit(Winapi::Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	
protected:
	virtual void __fastcall DropDownOk(void);
	virtual System::UnicodeString __fastcall GetPaintedText(void);
	virtual bool __fastcall IsReadOnly(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	
public:
	__fastcall virtual TdxDBTreeViewEdit(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDBTreeViewEdit(void);
	virtual void __fastcall DropDown(void);
	__property Data::Db::TField* Field = {read=GetField};
	__property Text;
	
__published:
	__property System::UnicodeString DataField = {read=GetDataField, write=SetDataField};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDBTreeViewEdit(HWND ParentWindow) : TCustomdxTreeViewEdit(ParentWindow) { }
	
};


class DELPHICLASS TDataLinkLookupTreeView;
class DELPHICLASS TCustomdxLookupTreeView;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TDataLinkLookupTreeView : public Data::Db::TDataLink
{
	typedef Data::Db::TDataLink inherited;
	
private:
	TCustomdxLookupTreeView* LookupTreeView;
	
protected:
	virtual void __fastcall ActiveChanged(void);
public:
	/* TDataLink.Create */ inline __fastcall TDataLinkLookupTreeView(void) : Data::Db::TDataLink() { }
	/* TDataLink.Destroy */ inline __fastcall virtual ~TDataLinkLookupTreeView(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TCustomdxLookupTreeView : public TCustomdxVTreeViewEdit
{
	typedef TCustomdxVTreeViewEdit inherited;
	
private:
	Dxdbtree::TdxDBTreeView* DBTreeView;
	TDataLinkLookupTreeView* ListLink;
	System::Variant FKeyFieldValue;
	System::UnicodeString FAssignFieldName;
	System::UnicodeString FKeyFieldName;
	System::UnicodeString FParentFieldName;
	System::UnicodeString FListFieldName;
	System::UnicodeString FDisplayFieldName;
	System::UnicodeString FImageIndexFieldName;
	System::UnicodeString FStateIndexFieldName;
	System::Variant FDropDownKeyValue;
	Dxdbtree::TSetDisplayItemText FOnSetDisplayItemText;
	Dxdbtree::TAddNewDBTreeNodeEvent __fastcall GetAddNewItem(void);
	Data::Db::TDataSource* __fastcall GetListSource(void);
	Dxdbtree::TdxDBTreeViewOptions __fastcall GetOptions(void);
	System::Variant __fastcall GetRootValue(void);
	void __fastcall SetAddNewItem(Dxdbtree::TAddNewDBTreeNodeEvent Value);
	void __fastcall SetAssignField(System::UnicodeString Value);
	void __fastcall SetKeyField(System::UnicodeString Value);
	void __fastcall SetListField(System::UnicodeString Value);
	void __fastcall SetOptions(Dxdbtree::TdxDBTreeViewOptions Value);
	void __fastcall SetParentField(System::UnicodeString Value);
	void __fastcall SetRootValue(const System::Variant &Value);
	void __fastcall SetListSource(Data::Db::TDataSource* Value);
	
protected:
	Data::Db::TField* FAssignField;
	Data::Db::TField* FKeyField;
	Data::Db::TField* FListField;
	Data::Db::TField* FParentField;
	virtual Dxtree::TCustomdxTreeView* __fastcall VirtualTreeView(void);
	virtual void __fastcall DropDownOk(void);
	virtual void __fastcall DataLinkActiveChanged(void);
	virtual void __fastcall ResetDropDown(void);
	__property System::UnicodeString AssignField = {read=FAssignFieldName, write=SetAssignField};
	
public:
	__fastcall virtual TCustomdxLookupTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxLookupTreeView(void);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall CloseUp(bool Accept);
	
__published:
	__property System::UnicodeString DisplayField = {read=FDisplayFieldName, write=FDisplayFieldName};
	__property DividedChar;
	__property System::UnicodeString ImageIndexField = {read=FImageIndexFieldName, write=FImageIndexFieldName};
	__property Data::Db::TDataSource* ListSource = {read=GetListSource, write=SetListSource};
	__property System::UnicodeString KeyField = {read=FKeyFieldName, write=SetKeyField};
	__property System::UnicodeString ListField = {read=FListFieldName, write=SetListField};
	__property Dxdbtree::TdxDBTreeViewOptions Options = {read=GetOptions, write=SetOptions, default=0};
	__property System::UnicodeString ParentField = {read=FParentFieldName, write=SetParentField};
	__property System::Variant RootValue = {read=GetRootValue, write=SetRootValue};
	__property System::UnicodeString StateIndexField = {read=FStateIndexFieldName, write=FStateIndexFieldName};
	__property TextStyle;
	__property Dxdbtree::TAddNewDBTreeNodeEvent OnAddNewItem = {read=GetAddNewItem, write=SetAddNewItem};
	__property Dxdbtree::TSetDisplayItemText OnSetDisplayItemText = {read=FOnSetDisplayItemText, write=FOnSetDisplayItemText};
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomdxLookupTreeView(HWND ParentWindow) : TCustomdxVTreeViewEdit(ParentWindow) { }
	
};


class DELPHICLASS TdxLookupTreeView;
class PASCALIMPLEMENTATION TdxLookupTreeView : public TCustomdxLookupTreeView
{
	typedef TCustomdxLookupTreeView inherited;
	
__published:
	__property Alignment;
public:
	/* TCustomdxLookupTreeView.Create */ inline __fastcall virtual TdxLookupTreeView(System::Classes::TComponent* AOwner) : TCustomdxLookupTreeView(AOwner) { }
	/* TCustomdxLookupTreeView.Destroy */ inline __fastcall virtual ~TdxLookupTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxLookupTreeView(HWND ParentWindow) : TCustomdxLookupTreeView(ParentWindow) { }
	
};


class DELPHICLASS TdxDBLookupTreeView;
class PASCALIMPLEMENTATION TdxDBLookupTreeView : public TCustomdxLookupTreeView
{
	typedef TCustomdxLookupTreeView inherited;
	
private:
	Vcl::Dbctrls::TFieldDataLink* FDataLink;
	Vcl::Controls::TControlCanvas* FCanvas;
	bool FCloseUpFlag;
	bool FUpdateDataFlag;
	void __fastcall ActiveChange(System::TObject* Sender);
	void __fastcall DataChange(System::TObject* Sender);
	System::UnicodeString __fastcall GetDataField(void);
	Data::Db::TDataSource* __fastcall GetDataSource(void);
	Data::Db::TField* __fastcall GetField(void);
	bool __fastcall GetReadOnly(void);
	void __fastcall SetDataField(const System::UnicodeString Value);
	void __fastcall SetDataSource(Data::Db::TDataSource* Value);
	void __fastcall SetReadOnly(bool Value);
	void __fastcall UpdateData(System::TObject* Sender);
	HIDESBASE MESSAGE void __fastcall CMExit(Winapi::Messages::TWMNoParams &Message);
	MESSAGE void __fastcall CMGetDataLink(Winapi::Messages::TMessage &Message);
	void __fastcall CheckNotCircular(void);
	
protected:
	virtual void __fastcall DataLinkActiveChanged(void);
	virtual void __fastcall DropDownOk(void);
	virtual System::UnicodeString __fastcall GetPaintedText(void);
	virtual bool __fastcall IsReadOnly(void);
	System::UnicodeString __fastcall GetDisplayText(void);
	System::Variant __fastcall GetLookupValue(void);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual void __fastcall PrepareDropDown(void);
	void __fastcall SearchTreeNode(void);
	
public:
	__fastcall virtual TdxDBLookupTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxDBLookupTreeView(void);
	virtual void __fastcall DropDown(void);
	virtual void __fastcall CloseUp(bool Accept);
	__property Data::Db::TField* Field = {read=GetField};
	__property Text;
	
__published:
	__property AssignField = {default=0};
	__property System::UnicodeString DataField = {read=GetDataField, write=SetDataField};
	__property Data::Db::TDataSource* DataSource = {read=GetDataSource, write=SetDataSource};
	__property bool ReadOnly = {read=GetReadOnly, write=SetReadOnly, default=0};
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxDBLookupTreeView(HWND ParentWindow) : TCustomdxLookupTreeView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxdbtrel */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXDBTREL)
using namespace Dxdbtrel;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxdbtrelHPP
