// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarCustomCustomizationForm.pas' rev: 24.00 (Win64)

#ifndef DxbarcustomcustomizationformHPP
#define DxbarcustomcustomizationformHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarcustomcustomizationform
{
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TdxBarPermissiveProc)(System::Classes::TComponent* Sender);

class DELPHICLASS TdxBarCustomizationFormPainter;
class PASCALIMPLEMENTATION TdxBarCustomizationFormPainter : public System::TObject
{
	typedef System::TObject inherited;
	
protected:
	__classmethod System::Types::TSize __fastcall GetGlyphSize(Dxbar::TdxBarItem* AItem);
	__classmethod bool __fastcall GetIsGlyphItem(Dxbar::TdxBarItem* AItem);
	__classmethod bool __fastcall GetIsNeedDrawSubItemArrow(Dxbar::TdxBarItem* AItem);
	__classmethod virtual void __fastcall DrawCaption(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &AItemRect, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall DrawEditEdge(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &AItemRect, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall DrawEditContent(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &AItemRect, Dxbar::TdxCustomBarEdit* AItem, bool ASelected, bool ADrawArrowButton);
	__classmethod virtual void __fastcall InternalDrawCaption(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ATextRect, const System::UnicodeString AText, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall InternalDrawEditContent(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &AItemRect, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall CalcButtonOrSubItemRects(Dxbar::TdxBarItem* AItem, const System::Types::TRect &R, /* out */ System::Types::TRect &ASideStripRect, /* out */ System::Types::TRect &ATextRect, /* out */ System::Types::TRect &AArrowRect);
	__classmethod virtual void __fastcall DrawButtonOrSubItemArrowBackground(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, bool Selected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemBackground(Vcl::Graphics::TCanvas* ACanvas, Dxbar::TdxBarItem* AItem, const System::Types::TRect &ABounds, const System::Types::TRect &ASideStripRect, const System::Types::TRect &AArrowRect, bool ASelected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemGlyph(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, bool ASelected);
	__classmethod void __fastcall DrawButtonOrSubItemText(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, const System::UnicodeString ACaption, bool Selected);
	__classmethod virtual void __fastcall DrawSubItemArrow(Vcl::Graphics::TCanvas* ACanvas, int X, int Y, bool ASelected);
	
public:
	__classmethod virtual void __fastcall DrawButtonOrSubItem(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxbar::TdxBarItem* AItem, System::UnicodeString ACaption, bool Selected);
	__classmethod virtual void __fastcall DrawCheckBox(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, bool AChecked, bool AEnabled);
	__classmethod virtual void __fastcall DrawComboBoxButton(Vcl::Graphics::TCanvas* ACanvas, Dxbar::TdxBarItem* AItem, System::Types::TRect &ARect, bool ASelected);
	__classmethod virtual void __fastcall DrawEdit(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxbar::TdxCustomBarEdit* AItem, bool Selected, bool ADrawArrowButton);
	__classmethod virtual void __fastcall DrawFocusedRect(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxbar::TdxBarItem* AItem);
	__classmethod virtual System::Uitypes::TColor __fastcall BrushColors(bool Selected, Dxbar::TdxBarItem* AItem);
	__classmethod virtual System::Uitypes::TColor __fastcall FontColors(bool Selected);
	__classmethod virtual int __fastcall GetButtonColor(Dxbar::TdxBarItem* AItem, bool ASelected);
	__classmethod virtual System::Uitypes::TColor __fastcall SideStripColor(bool Selected, Dxbar::TdxBarItem* AItem);
	__classmethod virtual int __fastcall GetBarButtonHeight();
	__classmethod virtual int __fastcall GetComboBoxButtonWidth();
public:
	/* TObject.Create */ inline __fastcall TdxBarCustomizationFormPainter(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarCustomizationFormPainter(void) { }
	
};


typedef System::TMetaClass* TdxBarCustomizationFormPainterClass;

class DELPHICLASS TdxBarCustomizationFormStandardPainter;
class PASCALIMPLEMENTATION TdxBarCustomizationFormStandardPainter : public TdxBarCustomizationFormPainter
{
	typedef TdxBarCustomizationFormPainter inherited;
	
public:
	__classmethod virtual void __fastcall DrawFocusedRect(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxbar::TdxBarItem* AItem);
public:
	/* TObject.Create */ inline __fastcall TdxBarCustomizationFormStandardPainter(void) : TdxBarCustomizationFormPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarCustomizationFormStandardPainter(void) { }
	
};


class DELPHICLASS TdxBarCustomizationFormFlatPainter;
class PASCALIMPLEMENTATION TdxBarCustomizationFormFlatPainter : public TdxBarCustomizationFormPainter
{
	typedef TdxBarCustomizationFormPainter inherited;
	
protected:
	__classmethod virtual void __fastcall DrawEditEdge(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &AItemRect, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall InternalDrawCaption(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ATextRect, const System::UnicodeString AText, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemArrowBackground(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, bool Selected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemGlyph(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, bool ASelected);
	
public:
	__classmethod virtual System::Uitypes::TColor __fastcall BrushColors(bool Selected, Dxbar::TdxBarItem* AItem);
	__classmethod virtual void __fastcall DrawButtonOrSubItem(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxbar::TdxBarItem* AItem, System::UnicodeString ACaption, bool Selected);
	__classmethod virtual void __fastcall DrawComboBoxButton(Vcl::Graphics::TCanvas* ACanvas, Dxbar::TdxBarItem* AItem, System::Types::TRect &ARect, bool ASelected);
	__classmethod virtual void __fastcall DrawFocusedRect(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxbar::TdxBarItem* AItem);
	__classmethod virtual System::Uitypes::TColor __fastcall FontColors(bool Selected);
	__classmethod virtual System::Uitypes::TColor __fastcall SideStripColor(bool Selected, Dxbar::TdxBarItem* AItem);
public:
	/* TObject.Create */ inline __fastcall TdxBarCustomizationFormFlatPainter(void) : TdxBarCustomizationFormPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarCustomizationFormFlatPainter(void) { }
	
};


class DELPHICLASS TdxBarCustomizationFormOffice11Painter;
class PASCALIMPLEMENTATION TdxBarCustomizationFormOffice11Painter : public TdxBarCustomizationFormFlatPainter
{
	typedef TdxBarCustomizationFormFlatPainter inherited;
	
protected:
	__classmethod virtual void __fastcall DrawEditEdge(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &AItemRect, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall InternalDrawCaption(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ATextRect, const System::UnicodeString AText, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemArrowBackground(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, bool Selected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemBackground(Vcl::Graphics::TCanvas* ACanvas, Dxbar::TdxBarItem* AItem, const System::Types::TRect &ABounds, const System::Types::TRect &ASideStripRect, const System::Types::TRect &AArrowRect, bool ASelected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemGlyph(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, bool ASelected);
	
public:
	__classmethod virtual System::Uitypes::TColor __fastcall BrushColors(bool Selected, Dxbar::TdxBarItem* AItem);
	__classmethod virtual void __fastcall DrawButtonOrSubItem(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxbar::TdxBarItem* AItem, System::UnicodeString ACaption, bool Selected);
	__classmethod virtual void __fastcall DrawComboBoxButton(Vcl::Graphics::TCanvas* ACanvas, Dxbar::TdxBarItem* AItem, System::Types::TRect &ARect, bool ASelected);
	__classmethod virtual System::Uitypes::TColor __fastcall FontColors(bool Selected);
	__classmethod virtual int __fastcall GetButtonColor(Dxbar::TdxBarItem* AItem, bool ASelected);
public:
	/* TObject.Create */ inline __fastcall TdxBarCustomizationFormOffice11Painter(void) : TdxBarCustomizationFormFlatPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarCustomizationFormOffice11Painter(void) { }
	
};


class DELPHICLASS TdxBarCustomizationFormXPPainter;
class PASCALIMPLEMENTATION TdxBarCustomizationFormXPPainter : public TdxBarCustomizationFormPainter
{
	typedef TdxBarCustomizationFormPainter inherited;
	
protected:
	__classmethod virtual void __fastcall DrawEditEdge(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &AItemRect, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall InternalDrawEditContent(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &AItemRect, Dxbar::TdxCustomBarEdit* AItem, bool ASelected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemArrowBackground(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, bool Selected);
	__classmethod virtual void __fastcall DrawButtonOrSubItemGlyph(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &R, Dxbar::TdxBarItem* AItem, bool ASelected);
	
public:
	__classmethod virtual void __fastcall DrawComboBoxButton(Vcl::Graphics::TCanvas* ACanvas, Dxbar::TdxBarItem* AItem, System::Types::TRect &ARect, bool ASelected);
	__classmethod virtual void __fastcall DrawFocusedRect(Vcl::Graphics::TCanvas* ACanvas, System::Types::TRect &ARect, Dxbar::TdxBarItem* AItem);
	__classmethod virtual int __fastcall GetComboBoxButtonWidth();
public:
	/* TObject.Create */ inline __fastcall TdxBarCustomizationFormXPPainter(void) : TdxBarCustomizationFormPainter() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TdxBarCustomizationFormXPPainter(void) { }
	
};


class DELPHICLASS TdxBarRunTimeSelectionController;
class PASCALIMPLEMENTATION TdxBarRunTimeSelectionController : public System::TInterfacedObject
{
	typedef System::TInterfacedObject inherited;
	
private:
	Cxclasses::TcxComponentList* FSelectionList;
	System::Classes::TNotifyEvent FOnSelectionChanged;
	void __fastcall AddSelection(System::Classes::TComponent* AComponent);
	void __fastcall SelectionListNotify(System::TObject* Sender, System::Classes::TComponent* AComponent, System::Classes::TListNotification AAction);
	void __fastcall SelectionListChanged(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	
public:
	__fastcall TdxBarRunTimeSelectionController(void);
	__fastcall virtual ~TdxBarRunTimeSelectionController(void);
	bool __fastcall CanDeleteComponent(System::Classes::TComponent* AComponent);
	void __fastcall GetSelection(System::Classes::TList* AList);
	Dxbar::TdxBarSelectionStatus __fastcall GetSelectionStatus(System::Classes::TPersistent* AComponent);
	bool __fastcall IsComponentSelected(System::Classes::TPersistent* AComponent);
	void __fastcall SelectComponent(System::Classes::TPersistent* AComponent, Dxbar::TdxBarSelectionOperation ASelectionOperation = (Dxbar::TdxBarSelectionOperation)(0x2));
	void __fastcall SetSelection(System::Classes::TList* AList);
	void __fastcall ShowDefaultEventHandler(Dxbar::TdxBarItem* AItem);
	System::UnicodeString __fastcall UniqueName(const System::UnicodeString BaseName);
	__property System::Classes::TNotifyEvent OnSelectionChanged = {read=FOnSelectionChanged, write=FOnSelectionChanged};
private:
	void *__IdxBarDesigner;	/* Dxbar::IdxBarDesigner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {B364658F-B4CE-46C3-83D5-D537F34B9482}
	operator Dxbar::_di_IdxBarDesigner()
	{
		Dxbar::_di_IdxBarDesigner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxbar::IdxBarDesigner*(void) { return (Dxbar::IdxBarDesigner*)&__IdxBarDesigner; }
	#endif
	
};


class DELPHICLASS TdxBarCustomizationFormListBoxHelper;
class DELPHICLASS TdxBarCustomCustomizationForm;
class PASCALIMPLEMENTATION TdxBarCustomizationFormListBoxHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Stdctrls::TListBox* FListBox;
	System::Classes::TWndMethod FOldWndProc;
	TdxBarCustomCustomizationForm* FOwner;
	Dxbar::TdxBarManager* __fastcall GetBarManager(void);
	TdxBarCustomizationFormPainterClass __fastcall GetPainterClass(void);
	
protected:
	virtual void __fastcall WndProc(Winapi::Messages::TMessage &Message);
	
public:
	__fastcall virtual TdxBarCustomizationFormListBoxHelper(TdxBarCustomCustomizationForm* AOwner, Vcl::Stdctrls::TListBox* AListBox);
	__fastcall virtual ~TdxBarCustomizationFormListBoxHelper(void);
	__property Dxbar::TdxBarManager* BarManager = {read=GetBarManager};
	__property Vcl::Stdctrls::TListBox* ListBox = {read=FListBox};
	__property System::Classes::TWndMethod OldWndProc = {read=FOldWndProc};
	__property TdxBarCustomCustomizationForm* Owner = {read=FOwner};
	__property TdxBarCustomizationFormPainterClass PainterClass = {read=GetPainterClass};
};


class PASCALIMPLEMENTATION TdxBarCustomCustomizationForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Actnlist::TAction* aAddItem;
	Vcl::Actnlist::TAction* aClearItemList;
	Vcl::Actnlist::TAction* aDeleteItem;
	Vcl::Actnlist::TAction* aDeleteToolBar;
	Vcl::Actnlist::TActionList* alCustomize;
	Vcl::Actnlist::TAction* aMoveDownItem;
	Vcl::Actnlist::TAction* aMoveUpItem;
	Vcl::Actnlist::TAction* aNewToolBar;
	Vcl::Actnlist::TAction* aRenameToolBar;
	Vcl::Actnlist::TAction* aResetToolBar;
	Vcl::Actnlist::TAction* aSubMenuEditor;
	Dxbar::TdxBarManager* BarManager1;
	Dxbar::TdxBarButton* CategoriesAdd;
	Dxbar::TdxBarButton* CategoriesDelete;
	Dxbar::TdxBarButton* CategoriesInsert;
	Dxbar::TdxBarCombo* CategoriesItemsVisible;
	Dxbar::TdxBarPopupMenu* CategoriesPopupMenu;
	Dxbar::TdxBarButton* CategoriesRename;
	Dxbar::TdxBarButton* CategoriesVisible;
	Dxbar::TdxBarButton* CommandsAdd;
	Dxbar::TdxBarButton* CommandsClear;
	Dxbar::TdxBarButton* CommandsDelete;
	Dxbar::TdxBarButton* CommandsMoveDown;
	Dxbar::TdxBarButton* CommandsMoveUp;
	Dxbar::TdxBarPopupMenu* CommandsPopupMenu;
	Dxbar::TdxBarButton* CommandsSubMenuEditor;
	Vcl::Controls::TImageList* imgGroups;
	void __fastcall aAddItemExecute(System::TObject* Sender);
	void __fastcall aClearItemListExecute(System::TObject* Sender);
	void __fastcall aDeleteItemExecute(System::TObject* Sender);
	void __fastcall aDeleteToolBarExecute(System::TObject* Sender);
	void __fastcall aMoveItemExecute(System::TObject* Sender);
	void __fastcall aNewToolBarExecute(System::TObject* Sender);
	void __fastcall aRenameToolBarExecute(System::TObject* Sender);
	void __fastcall aResetToolBarExecute(System::TObject* Sender);
	void __fastcall aSubMenuEditorExecute(System::TObject* Sender);
	void __fastcall CategoriesAddClick(System::TObject* Sender);
	void __fastcall CategoriesDeleteClick(System::TObject* Sender);
	void __fastcall CategoriesInsertClick(System::TObject* Sender);
	void __fastcall CategoriesItemsVisibleChange(System::TObject* Sender);
	void __fastcall CategoriesPopupMenuPopup(System::TObject* Sender);
	void __fastcall CategoriesRenameClick(System::TObject* Sender);
	void __fastcall CategoriesVisibleClick(System::TObject* Sender);
	void __fastcall CommandsAddClick(System::TObject* Sender);
	void __fastcall CommandsClearClick(System::TObject* Sender);
	void __fastcall CommandsDeleteClick(System::TObject* Sender);
	void __fastcall CommandsMoveDownClick(System::TObject* Sender);
	void __fastcall CommandsMoveUpClick(System::TObject* Sender);
	void __fastcall CommandsPopupMenuPopup(System::TObject* Sender);
	void __fastcall CommandsSubMenuEditorClick(System::TObject* Sender);
	
private:
	Vcl::Stdctrls::TListBox* FAlreadySynchronous;
	TdxBarCustomizationFormListBoxHelper* FBarListBoxHelper;
	Cxclasses::TcxComponentCollectionChangeEvent FBarsOldChangeEvent;
	TdxBarCustomizationFormListBoxHelper* FCategoryListBoxHelper;
	System::Classes::TList* FDisabledWindows;
	TdxBarCustomizationFormListBoxHelper* FItemsListBoxHelper;
	Cxclasses::TcxComponentListChangeEvent FItemsOldChangeEvent;
	Cxclasses::TcxComponentList* FSelectionList;
	bool __fastcall CanDeleteSelectedCategory(void);
	bool __fastcall CanDeleteSelectedCategoryCommands(void);
	bool __fastcall GetIsLookAndFeelUsed(void);
	Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* __fastcall GetLookAndFeelPainter(void);
	Dxbar::TdxBar* __fastcall GetSelectedBar(void);
	void __fastcall FormCloseEvent(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall FormDestroyEvent(System::TObject* Sender);
	void __fastcall FormHideEvent(System::TObject* Sender);
	void __fastcall FormShowEvent(System::TObject* Sender);
	MESSAGE void __fastcall WMDeferredCallSynchronizationListBox(Winapi::Messages::TMessage &Message);
	
protected:
	void __fastcall BarListToggleCheck(int AIndex);
	void __fastcall BarsChange(System::TObject* Sender, Cxclasses::TcxComponentCollectionItem* AItem, Cxclasses::TcxComponentCollectionNotification AAction);
	bool __fastcall CanDeleteBar(System::Classes::TComponent* ABar);
	Cxclasses::TcxComponentList* __fastcall CreateSelectionList(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	void __fastcall DeleteSelectedObjects(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TNotifyEvent ADeleteProc = 0x0, bool ASynchronizeDesigner = true);
	virtual void __fastcall DestroyWindowHandle(void);
	virtual void __fastcall DoShowHelp(void);
	virtual System::Uitypes::TColor __fastcall GetBarItemsBackgroundColor(void);
	virtual Dxbar::TdxBar* __fastcall GetBarList(int Index);
	virtual Vcl::Stdctrls::TListBox* __fastcall GetBarListBox(void) = 0 ;
	virtual Vcl::Stdctrls::TListBox* __fastcall GetCategoriesList(void) = 0 ;
	bool __fastcall GetDisableParent(Dxbar::TdxBarManager* ABarManager, /* out */ Vcl::Controls::TWinControl* &AParent);
	System::Uitypes::TColor __fastcall GetEditBackgroundColor(void);
	System::Uitypes::TColor __fastcall GetEditTextColor(void);
	System::TObject* __fastcall GetExclusiveObject(Vcl::Stdctrls::TListBox* AListBox);
	virtual Vcl::Stdctrls::TListBox* __fastcall GetItemsListBox(void) = 0 ;
	System::TObject* __fastcall GetNextSelectedObject(Vcl::Stdctrls::TListBox* AListBox);
	System::TObject* __fastcall GetObjectFromListBox(Vcl::Stdctrls::TListBox* AListBox, int AIndex);
	virtual TdxBarCustomizationFormPainterClass __fastcall GetPainterClass(void);
	int __fastcall GetSelCount(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall GetSelection(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TList* AList);
	int __fastcall GetVisibleItemsCount(Vcl::Stdctrls::TListBox* AListBox);
	virtual void __fastcall ItemsChange(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	bool __fastcall IsBarPredefined(Dxbar::TdxBar* ABar);
	void __fastcall MoveItems(Vcl::Stdctrls::TListBox* AListBox, Dxbar::TdxBarComponentList* ABarComponentList, int ADirection);
	void __fastcall SetSelection(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TList* AList)/* overload */;
	void __fastcall SetSelection(Vcl::Stdctrls::TListBox* AListBox, System::TObject* AObject)/* overload */;
	void __fastcall DeferredCallSynchronizationListBox(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall SynchronizeListBox(Vcl::Stdctrls::TListBox* AListBox, System::TObject* AChangedObject = (System::TObject*)(0x0), Cxclasses::TcxComponentCollectionNotification AAction = (Cxclasses::TcxComponentCollectionNotification)(0x1));
	virtual void __fastcall SynchronizeListBoxes(void) = 0 ;
	void __fastcall SynchronizeListBoxSelection(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall UpdateTopIndex(Vcl::Stdctrls::TListBox* AListBox);
	int __fastcall PrepareMenuAnimationsComboBox(Vcl::Graphics::TFont* AComboBoxFont, System::Classes::TStrings* AComboBoxStrings);
	Dxbar::TdxBarItem* __fastcall GetItemList(int Index);
	Dxbar::TdxBarItem* __fastcall GetSelectedItem(void);
	void __fastcall MoveItem(int Delta);
	void __fastcall EnableWindows(bool AEnable);
	void __fastcall FreeSelectionList(void);
	virtual void __fastcall PrepareControls(void);
	void __fastcall ReplaceByCheckableButton(const System::UnicodeString ACaption, Vcl::Controls::TControl* ASource, Vcl::Controls::TControl* AAdjustWithControl, Dxbar::TdxBarPopupMenu* APopupMenu);
	virtual void __fastcall RestoreOldEvents(void);
	void __fastcall SelectBarManager(void);
	void __fastcall SetNewWindowProc(Vcl::Controls::TControl* AControl, System::Classes::TWndMethod ANewWindowProc, /* out */ System::Classes::TWndMethod &AOldWindowProc);
	void __fastcall ShowCategoryPopupMenu(const System::Types::TPoint APoint);
	void __fastcall SynchronizeDesigner(Dxbar::_di_IdxBarSelectableItem ANewSelection)/* overload */;
	void __fastcall SynchronizeDesigner(Vcl::Stdctrls::TListBox* AListBox)/* overload */;
	void __fastcall UpdateCommonEvents(Vcl::Stdctrls::TListBox* AListBox, Vcl::Actnlist::TAction* AAddAction, Vcl::Actnlist::TAction* ADeleteAction, Vcl::Actnlist::TAction* AMoveUpAction, Vcl::Actnlist::TAction* AMoveDownAction, TdxBarPermissiveProc ADeletePermissiveProc = 0x0);
	virtual void __fastcall UpdateItemDesciption(const System::UnicodeString AText);
	void __fastcall UpdateItemsListEvents(void);
	void __fastcall UpdateToolBarsEvents(void);
	HIDESBASE MESSAGE void __fastcall WMActivate(Winapi::Messages::TMessage &Message);
	HIDESBASE MESSAGE void __fastcall WMNCHitTest(Winapi::Messages::TMessage &Message);
	__property Vcl::Stdctrls::TListBox* AlreadySynchronous = {read=FAlreadySynchronous};
	__property System::Uitypes::TColor BarItemsBackgroundColor = {read=GetBarItemsBackgroundColor, nodefault};
	__property Dxbar::TdxBar* BarList[int Index] = {read=GetBarList};
	__property Vcl::Stdctrls::TListBox* BarListBox = {read=GetBarListBox};
	__property TdxBarCustomizationFormListBoxHelper* BarListBoxHelper = {read=FBarListBoxHelper};
	__property TdxBarCustomizationFormListBoxHelper* CategoryListBoxHelper = {read=FCategoryListBoxHelper};
	__property System::Uitypes::TColor EditBackgroundColor = {read=GetEditBackgroundColor, nodefault};
	__property System::Uitypes::TColor EditTextColor = {read=GetEditTextColor, nodefault};
	__property bool IsLookAndFeelUsed = {read=GetIsLookAndFeelUsed, nodefault};
	__property Dxbar::TdxBarItem* ItemList[int Index] = {read=GetItemList};
	__property Vcl::Stdctrls::TListBox* ItemsListBox = {read=GetItemsListBox};
	__property TdxBarCustomizationFormListBoxHelper* ItemsListBoxHelper = {read=FItemsListBoxHelper};
	__property Dxbar::TdxBarItem* SelectedItem = {read=GetSelectedItem};
	
public:
	Dxbar::TdxBarManager* BarManager;
	__fastcall virtual TdxBarCustomCustomizationForm(Dxbar::TdxBarManager* ABarManager);
	__fastcall virtual ~TdxBarCustomCustomizationForm(void);
	virtual void __fastcall BarManagerStyleChanged(void);
	virtual void __fastcall DesignSelectionChanged(System::TObject* Sender) = 0 ;
	DYNAMIC void __fastcall MouseWheelHandler(Winapi::Messages::TMessage &Message);
	virtual void __fastcall SelectPage(int APageIndex) = 0 ;
	virtual void __fastcall SwitchToItemsPage(void) = 0 ;
	virtual void __fastcall UpdateHelpButton(void) = 0 ;
	virtual void __fastcall UpdateOptions(void) = 0 ;
	void __fastcall UpdateVisibility(const tagWINDOWPOS &AWindowPos);
	__property Vcl::Stdctrls::TListBox* CategoriesList = {read=GetCategoriesList};
	__property Cxlookandfeelpainters::TcxCustomLookAndFeelPainter* LookAndFeelPainter = {read=GetLookAndFeelPainter};
	__property TdxBarCustomizationFormPainterClass PainterClass = {read=GetPainterClass};
	__property Dxbar::TdxBar* SelectedBar = {read=GetSelectedBar};
	__property Cxclasses::TcxComponentList* SelectionList = {read=FSelectionList};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxBarCustomCustomizationForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBarCustomCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarCustomCustomizationForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


typedef System::TMetaClass* TdxBarCustomCustomizationFormClass;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TdxBarCustomCustomizationFormClass dxBarCustomizationFormClass;
extern PACKAGE TdxBarCustomCustomizationForm* __fastcall dxBarCustomizingForm(void);
extern PACKAGE bool __fastcall IsCustomizing(void);
extern PACKAGE void __fastcall dxBarCustomizing(Dxbar::TdxBarManager* ABarManager, bool AShow);
extern PACKAGE void __fastcall PrepareCustomizationFormFont(Vcl::Forms::TCustomForm* AForm, Dxbar::TdxBarManager* ABarManager);
extern PACKAGE void __fastcall HostBarManagerStyleChanged(void);
extern PACKAGE void __fastcall UpdateHelpButton(void);
extern PACKAGE void __fastcall UpdateBarManagerOptions(void);
}	/* namespace Dxbarcustomcustomizationform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARCUSTOMCUSTOMIZATIONFORM)
using namespace Dxbarcustomcustomizationform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarcustomcustomizationformHPP
