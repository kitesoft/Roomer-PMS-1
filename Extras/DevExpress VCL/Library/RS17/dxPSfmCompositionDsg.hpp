// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmCompositionDsg.pas' rev: 24.00 (Win32)

#ifndef DxpsfmcompositiondsgHPP
#define DxpsfmcompositiondsgHPP

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
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmcompositiondsg
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmCompositionDesignWindow;
class PASCALIMPLEMENTATION TdxfmCompositionDesignWindow : public Dxpscore::TAbstractdxReportLinkDesignWindow
{
	typedef Dxpscore::TAbstractdxReportLinkDesignWindow inherited;
	
__published:
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnClose;
	Cxbuttons::TcxButton* btnDelete;
	Cxbuttons::TcxButton* btnDesign;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnMoveDown;
	Cxbuttons::TcxButton* btnMoveUp;
	Vcl::Extctrls::TBevel* bvlSpacer;
	Cxcheckbox::TcxCheckBox* cbStartEachItemFromNewPage;
	Cxgroupbox::TcxGroupBox* gpButtons;
	Cxgraphics::TcxImageList* ilItems;
	Cxlistview::TcxListView* lvItems;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miDesign;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miMoveDown;
	Vcl::Menus::TMenuItem* miMoveUp;
	Vcl::Menus::TMenuItem* miRename;
	Vcl::Menus::TMenuItem* miSelectAll;
	Vcl::Menus::TMenuItem* N1;
	Cxpc::TcxPageControl* pcItems;
	Vcl::Menus::TPopupMenu* pmItems;
	Cxlabel::TcxLabel* pnlNoItems;
	Cxpc::TcxTabSheet* tbsItems;
	void __fastcall AddClick(System::TObject* Sender);
	void __fastcall cbStartEachItemFromNewPageClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall DesignerClick(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall MoveDownClick(System::TObject* Sender);
	void __fastcall MoveUpClick(System::TObject* Sender);
	void __fastcall lvItemsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall lvItemsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lvItemsStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall lvItemsChange(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemChange Change);
	void __fastcall lvItemsEdited(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, System::UnicodeString &S);
	void __fastcall lvItemsEditing(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, bool &AllowEdit);
	void __fastcall pmItemsPopup(System::TObject* Sender);
	void __fastcall RenameClick(System::TObject* Sender);
	void __fastcall SelectAllClick(System::TObject* Sender);
	void __fastcall tbsItemsResize(System::TObject* Sender);
	
private:
	bool FIsRefreshing;
	System::Classes::TWndMethod FListViewWndProc;
	int FSaveDragIndex;
	Dxpscore::TdxCompositionLinkItem* __fastcall GetActiveItem(void);
	Dxpscore::TdxCompositionReportLink* __fastcall GetComposition(void);
	bool __fastcall GetHasOnlyBuiltInsAreInSelection(void);
	bool __fastcall GetIsSelected(int Index);
	Dxpscore::TdxCompositionLinkItem* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	int __fastcall GetSelectedCount(void);
	bool __fastcall GetShowDescription(void);
	void __fastcall SetActiveItem(Dxpscore::TdxCompositionLinkItem* Value);
	void __fastcall SetIsSelected(int Index, bool Value);
	bool __fastcall CanAdd(void);
	bool __fastcall CanDelete(void);
	bool __fastcall CanDesign(void);
	bool __fastcall CanEdit(void);
	bool __fastcall CanMoveDown(void);
	bool __fastcall CanMoveUp(void);
	bool __fastcall CanRename(void);
	bool __fastcall CanSelectAll(void);
	void __fastcall DeleteSelection(void);
	System::UnicodeString __fastcall GetSelectedItemsAsString(void);
	void __fastcall MoveSelection(int ADelta);
	void __fastcall RefreshColumns(void);
	void __fastcall RefreshList(void);
	void __fastcall ListViewWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall SubClassListView(void);
	void __fastcall UnsubClassListView(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall BeforeConstruction(void);
	virtual void __fastcall Initialize(void);
	virtual void __fastcall LoadStrings(void);
	virtual void __fastcall UpdateControlsState(void);
	
public:
	__fastcall virtual TdxfmCompositionDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmCompositionDesignWindow(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property Dxpscore::TdxCompositionLinkItem* ActiveItem = {read=GetActiveItem, write=SetActiveItem};
	__property Dxpscore::TdxCompositionReportLink* Composition = {read=GetComposition};
	__property bool HasOnlyBuiltInsAreInSelection = {read=GetHasOnlyBuiltInsAreInSelection, nodefault};
	__property bool IsSelected[int Index] = {read=GetIsSelected, write=SetIsSelected};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property Dxpscore::TdxCompositionLinkItem* Items[int Index] = {read=GetItem};
	__property int SelectedCount = {read=GetSelectedCount, nodefault};
	__property bool ShowDescription = {read=GetShowDescription, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmCompositionDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Dxpscore::TAbstractdxReportLinkDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmCompositionDesignWindow(HWND ParentWindow) : Dxpscore::TAbstractdxReportLinkDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxpsfmcompositiondsg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMCOMPOSITIONDSG)
using namespace Dxpsfmcompositiondsg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmcompositiondsgHPP
