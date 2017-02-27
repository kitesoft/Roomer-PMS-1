// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxtree.pas' rev: 24.00 (Win32)

#ifndef DxtreeHPP
#define DxtreeHPP

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
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Winapi.CommCtrl.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxtree
{
//-- type declarations -------------------------------------------------------
enum TdxTreeViewOption : unsigned char { trCanDelete, trConfirmDelete };

typedef System::Set<TdxTreeViewOption, TdxTreeViewOption::trCanDelete, TdxTreeViewOption::trConfirmDelete>  TdxTreeViewOptions;

typedef void __fastcall (__closure *TDragDropTreeNode)(Vcl::Comctrls::TTreeNode* Destination, Vcl::Comctrls::TTreeNode* Source, bool &Accept);

typedef void __fastcall (__closure *TEndDragTreeNode)(Vcl::Comctrls::TTreeNode* Destination, Vcl::Comctrls::TTreeNode* Source, Vcl::Comctrls::TNodeAttachMode &AttachMode);

typedef void __fastcall (__closure *TDragDropIsCopy)(Vcl::Comctrls::TTreeNode* Destination, Vcl::Comctrls::TTreeNode* Source, bool &IsCopy);

typedef void __fastcall (__closure *TTreeViewCustomDraw)(System::TObject* Sender, Vcl::Comctrls::TTreeNode* TreeNode, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, System::Uitypes::TColor &ABkColor);

class DELPHICLASS TdxTreeNode;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxTreeNode : public Vcl::Comctrls::TTreeNode
{
	typedef Vcl::Comctrls::TTreeNode inherited;
	
__published:
	virtual void __fastcall MoveTo(Vcl::Comctrls::TTreeNode* Destination, Vcl::Comctrls::TNodeAttachMode Mode);
public:
	/* TTreeNode.Create */ inline __fastcall virtual TdxTreeNode(Vcl::Comctrls::TTreeNodes* AOwner) : Vcl::Comctrls::TTreeNode(AOwner) { }
	/* TTreeNode.Destroy */ inline __fastcall virtual ~TdxTreeNode(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TCustomdxTreeView;
class PASCALIMPLEMENTATION TCustomdxTreeView : public Vcl::Comctrls::TCustomTreeView
{
	typedef Vcl::Comctrls::TCustomTreeView inherited;
	
private:
	TdxTreeViewOptions FOptions;
	int FSelectedIndex;
	bool FDragDropProcessingFlag;
	Vcl::Controls::TDragObject* FDragObject;
	System::UnicodeString FDeletingConfirmationMessage;
	bool FIsConfirmationAssigned;
	int FScrollTimerID;
	Vcl::Graphics::TFont* fntcd;
	Vcl::Controls::TControlCanvas* FCanvas;
	TDragDropTreeNode FOnDragDropTreeNode;
	TEndDragTreeNode FOnEndDragTreeNode;
	TDragDropIsCopy FOnDragDropIsCopy;
	TTreeViewCustomDraw FOnCustomDraw;
	Vcl::Comctrls::TTVEditedEvent FOnSetEditText;
	bool FShowNodeHint;
	Vcl::Controls::TDragObject* FInternalDragObject;
	Vcl::Comctrls::TTreeNode* __fastcall GetDragSourceTreeNode(void);
	System::UnicodeString __fastcall GetDeletingConfirmationMessage(void);
	void __fastcall SetSelectedIndex(int Value);
	void __fastcall SetDeletingConfirmationMessage(const System::UnicodeString AValue);
	HIDESBASE MESSAGE void __fastcall CMDrag(Vcl::Controls::TCMDrag &Message);
	bool __fastcall DoCNNotify(Winapi::Messages::TWMNotify &Message);
	bool __fastcall DoWMNotify(Winapi::Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall CNNotify(Winapi::Messages::TWMNotify &Message);
	HIDESBASE MESSAGE void __fastcall WMNotify(Winapi::Messages::TWMNotify &Message);
	void __fastcall ReadIsAssigned(System::Classes::TReader* AReader);
	void __fastcall WriteIsAssigned(System::Classes::TWriter* AWriter);
	
protected:
	bool CopyTreeNodeStructFlag;
	virtual void __fastcall DefineProperties(System::Classes::TFiler* AFiler);
	virtual void __fastcall DoCustomDraw(Vcl::Comctrls::TTreeNode* TreeNode, Vcl::Graphics::TFont* AFont, System::Uitypes::TColor &AColor, System::Uitypes::TColor &ABkColor);
	DYNAMIC void __fastcall DoStartDrag(Vcl::Controls::TDragObject* &DragObject);
	DYNAMIC void __fastcall DoEndDrag(System::TObject* Target, int X, int Y);
	HIDESBASE Vcl::Comctrls::TTreeNode* __fastcall GetNodeFromItem(const tagTVITEMW &Item);
	virtual System::UnicodeString __fastcall GetListItemText(Vcl::Comctrls::TTreeNode* TreeNode);
	virtual void __fastcall InsertTreeNodeStructure(System::Classes::TList* ListS, System::Classes::TList* ListD);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall DoDragDropTreeNode(Vcl::Comctrls::TTreeNode* Destination, Vcl::Comctrls::TTreeNode* Source, bool &Accept);
	virtual void __fastcall DoDragDropIsCopy(Vcl::Comctrls::TTreeNode* Destination, Vcl::Comctrls::TTreeNode* Source, bool &IsCopy);
	__property TdxTreeViewOptions Options = {read=FOptions, write=FOptions, default=3};
	__property int SelectedIndex = {read=FSelectedIndex, write=SetSelectedIndex, nodefault};
	
public:
	__fastcall virtual TCustomdxTreeView(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TCustomdxTreeView(void);
	virtual Vcl::Comctrls::TTreeNode* __fastcall CreateNode(void);
	virtual void __fastcall SetFocus(void);
	virtual void __fastcall GetNodeStructure(Vcl::Comctrls::TTreeNode* TreeNode, System::Classes::TList* List);
	virtual bool __fastcall IsCustomDraw(void);
	Vcl::Comctrls::TTreeNode* __fastcall MoveTreeNodeStructure(Vcl::Comctrls::TTreeNode* Source, Vcl::Comctrls::TTreeNode* Destination, bool IsCopy);
	virtual void __fastcall UpdateSizeGripCorner(void);
	__property Vcl::Comctrls::TTreeNode* DragSourceTreeNode = {read=GetDragSourceTreeNode};
	__property bool IsConfirmationAssigned = {read=FIsConfirmationAssigned, write=FIsConfirmationAssigned, nodefault};
	__property Vcl::Comctrls::TTVEditedEvent OnSetEditText = {read=FOnSetEditText, write=FOnSetEditText};
	__property Color = {default=-16777211};
	__property DragCursor = {default=-12};
	__property Font;
	__property Images;
	__property Items;
	__property Indent;
	__property PopupMenu;
	__property ReadOnly = {default=0};
	__property ShowButtons = {default=1};
	__property ShowLines = {default=1};
	__property ShowRoot = {default=1};
	__property SortType = {default=0};
	__property StateImages;
	__property OnClick;
	__property OnChanging;
	__property OnDblClick;
	__property OnGetImageIndex;
	__property OnGetSelectedIndex;
	
__published:
	__property ImeMode = {default=3};
	__property ImeName = {default=0};
	__property RightClickSelect = {default=0};
	__property bool ShowNodeHint = {read=FShowNodeHint, write=FShowNodeHint, nodefault};
	__property TTreeViewCustomDraw OnCustomDraw = {read=FOnCustomDraw, write=FOnCustomDraw};
	__property TDragDropIsCopy OnDragDropIsCopy = {read=FOnDragDropIsCopy, write=FOnDragDropIsCopy};
	__property TDragDropTreeNode OnDragDropTreeNode = {read=FOnDragDropTreeNode, write=FOnDragDropTreeNode};
	__property TEndDragTreeNode OnEndDragTreeNode = {read=FOnEndDragTreeNode, write=FOnEndDragTreeNode};
	__property Anchors = {default=3};
	__property AutoExpand = {default=0};
	__property BiDiMode;
	__property Constraints;
	__property System::UnicodeString DeletingConfirmationMessage = {read=GetDeletingConfirmationMessage, write=SetDeletingConfirmationMessage, stored=FIsConfirmationAssigned};
	__property DragKind = {default=0};
	__property HotTrack = {default=0};
	__property ParentBiDiMode = {default=1};
	__property RowSelect = {default=0};
	__property ToolTips = {default=1};
	__property OnCustomDrawItem;
	__property OnEndDock;
	__property OnStartDock;
	__property OnAdvancedCustomDraw;
public:
	/* TWinControl.CreateParented */ inline __fastcall TCustomdxTreeView(HWND ParentWindow) : Vcl::Comctrls::TCustomTreeView(ParentWindow) { }
	
};


class DELPHICLASS TdxTreeView;
class PASCALIMPLEMENTATION TdxTreeView : public TCustomdxTreeView
{
	typedef TCustomdxTreeView inherited;
	
__published:
	__property ShowButtons = {default=1};
	__property BorderStyle = {default=1};
	__property DragCursor = {default=-12};
	__property ShowLines = {default=1};
	__property ShowRoot = {default=1};
	__property ReadOnly = {default=0};
	__property DragMode = {default=0};
	__property HideSelection = {default=1};
	__property Indent;
	__property Items;
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
	__property Options = {default=3};
	__property SelectedIndex;
	__property SortType = {default=0};
	__property TabOrder = {default=-1};
	__property TabStop = {default=1};
	__property Visible = {default=1};
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
public:
	/* TCustomdxTreeView.Create */ inline __fastcall virtual TdxTreeView(System::Classes::TComponent* AOwner) : TCustomdxTreeView(AOwner) { }
	/* TCustomdxTreeView.Destroy */ inline __fastcall virtual ~TdxTreeView(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxTreeView(HWND ParentWindow) : TCustomdxTreeView(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE System::ResourceString _dxTreeViewDelConfirm;
#define Dxtree_dxTreeViewDelConfirm System::LoadResourceString(&Dxtree::_dxTreeViewDelConfirm)
extern PACKAGE System::ResourceString _dxDBTreeViewSmartLoadS;
#define Dxtree_dxDBTreeViewSmartLoadS System::LoadResourceString(&Dxtree::_dxDBTreeViewSmartLoadS)
}	/* namespace Dxtree */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXTREE)
using namespace Dxtree;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxtreeHPP
