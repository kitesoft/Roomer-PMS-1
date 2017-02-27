// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxComponentCollectionEditor.pas' rev: 24.00 (Win32)

#ifndef CxcomponentcollectioneditorHPP
#define CxcomponentcollectioneditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <ComponentDesigner.hpp>	// Pascal unit
#include <DesignConst.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <ColnEdit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxcomponentcollectioneditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmComponentCollectionEditor;
class PASCALIMPLEMENTATION TfrmComponentCollectionEditor : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Vcl::Actnlist::TAction* acAdd;
	Vcl::Actnlist::TAction* acDelete;
	Vcl::Actnlist::TAction* acMoveDown;
	Vcl::Actnlist::TAction* acMoveUp;
	Vcl::Actnlist::TAction* acSelectAll;
	Vcl::Actnlist::TAction* acTextLabels;
	Vcl::Actnlist::TAction* acToolbar;
	Vcl::Controls::TImageList* ImageList;
	Vcl::Comctrls::TListView* ListView1;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miMoveDown;
	Vcl::Menus::TMenuItem* miMoveUp;
	Vcl::Menus::TMenuItem* miTextLabels;
	Vcl::Menus::TMenuItem* miToolbar;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Extctrls::TPanel* Panel;
	Vcl::Menus::TPopupMenu* PopupMenu1;
	Vcl::Menus::TPopupMenu* PopupMenu2;
	Vcl::Comctrls::TToolBar* Toolbar1;
	Vcl::Comctrls::TToolButton* ToolButton1;
	Vcl::Comctrls::TToolButton* ToolButton2;
	Vcl::Comctrls::TToolButton* ToolButton3;
	Vcl::Comctrls::TToolButton* ToolButton4;
	Vcl::Comctrls::TToolButton* ToolButton5;
	Vcl::Actnlist::TActionList* ActionList;
	Vcl::Menus::TMenuItem* SelectAll1;
	Vcl::Extctrls::TPanel* pnlItems;
	void __fastcall acAddExecute(System::TObject* Sender);
	void __fastcall acDeleteExecute(System::TObject* Sender);
	void __fastcall acMoveDownExecute(System::TObject* Sender);
	void __fastcall acMoveUpExecute(System::TObject* Sender);
	void __fastcall acSelectAllExecute(System::TObject* Sender);
	void __fastcall acTextLabelsExecute(System::TObject* Sender);
	void __fastcall acToolbarExecute(System::TObject* Sender);
	HIDESBASE void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	HIDESBASE void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall FormKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall ListView1Change(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemChange Change);
	void __fastcall ListView1DragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall ListView1DragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall ListView1KeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ListView1KeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall SelectAllCommandUpdate(System::TObject* Sender);
	void __fastcall SelectionUpdate(System::TObject* Sender);
	void __fastcall acToolbarUpdate(System::TObject* Sender);
	
private:
	System::Classes::TList* FAddedItemIDList;
	System::UnicodeString FCollectionClassName;
	bool FSelectionError;
	Colnedit::TColOptions FColOptions;
	MESSAGE void __fastcall AMDeferUpdate(void *Msg);
	Cxclasses::TcxComponentCollection* __fastcall GetCollection(void);
	System::UnicodeString __fastcall GetRegKey(void);
	void __fastcall SetColOptions(Colnedit::TColOptions Value);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TWMActivate &Message);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	virtual bool __fastcall CanAdd(int Index);
	virtual void __fastcall DoSelectionIfNoItemsSelected(void);
	virtual void __fastcall InitFormEditor(void);
	void __fastcall SelectAll(bool DoUpdate = true);
	void __fastcall SelectNone(bool DoUpdate = true);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall UpdateContent(void);
	
public:
	__fastcall virtual TfrmComponentCollectionEditor(System::Classes::TComponent* AOwner);
	virtual void __fastcall DoItemsModified(void);
	System::UnicodeString __fastcall GetItemName(int ItemIndex);
	void __fastcall GetSelection(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	HIDESBASE void __fastcall SetSelection(void);
	void __fastcall UpdateListbox(void);
	__property Cxclasses::TcxComponentCollection* Collection = {read=GetCollection};
	__property System::UnicodeString CollectionPropertyName = {read=ComponentPropertyName};
	__property Colnedit::TColOptions Options = {read=FColOptions, write=SetColOptions, default=7};
public:
	/* TDesignWindow.Destroy */ inline __fastcall virtual ~TfrmComponentCollectionEditor(void) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmComponentCollectionEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmComponentCollectionEditor(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
};


typedef System::TMetaClass* TcxComponentCollectionEditorClass;

class DELPHICLASS TcxComponentCollectionProperty;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxComponentCollectionProperty : public Designeditors::TClassProperty
{
	typedef Designeditors::TClassProperty inherited;
	
public:
	virtual void __fastcall Edit(void);
	virtual Designintf::TPropertyAttributes __fastcall GetAttributes(void);
	virtual TcxComponentCollectionEditorClass __fastcall GetEditorClass(void);
	virtual Colnedit::TColOptions __fastcall GetColOptions(void);
public:
	/* TPropertyEditor.Create */ inline __fastcall virtual TcxComponentCollectionProperty(const Designintf::_di_IDesigner ADesigner, int APropCount) : Designeditors::TClassProperty(ADesigner, APropCount) { }
	/* TPropertyEditor.Destroy */ inline __fastcall virtual ~TcxComponentCollectionProperty(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxcomponentcollectioneditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCOMPONENTCOLLECTIONEDITOR)
using namespace Cxcomponentcollectioneditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxcomponentcollectioneditorHPP
