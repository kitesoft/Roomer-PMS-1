// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxfmNavBarDsgnEditor.pas' rev: 24.00 (Win32)

#ifndef DxfmnavbardsgneditorHPP
#define DxfmnavbardsgneditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignEditors.hpp>	// Pascal unit
#include <dxNavBar.hpp>	// Pascal unit
#include <dxNavBarBase.hpp>	// Pascal unit
#include <dxNavBarCollns.hpp>	// Pascal unit
#include <dxNavBarStyles.hpp>	// Pascal unit
#include <dxNavBarDsgnUtils.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxfmnavbardsgneditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TToolButton;
class PASCALIMPLEMENTATION TToolButton : public Vcl::Comctrls::TToolButton
{
	typedef Vcl::Comctrls::TToolButton inherited;
	
private:
	HIDESBASE MESSAGE void __fastcall CMEnabledChanged(Winapi::Messages::TMessage &Message);
public:
	/* TToolButton.Create */ inline __fastcall virtual TToolButton(System::Classes::TComponent* AOwner) : Vcl::Comctrls::TToolButton(AOwner) { }
	
public:
	/* TGraphicControl.Destroy */ inline __fastcall virtual ~TToolButton(void) { }
	
};


class DELPHICLASS TdxNavBarDsgnWindowPageHandler;
class DELPHICLASS TdxfmNavBarDesignWindow;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarDsgnWindowPageHandler : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	int FLockCount;
	TdxfmNavBarDesignWindow* FDsgnWindow;
	Dxnavbar::TdxCustomNavBar* __fastcall GetNavBar(void);
	
protected:
	virtual System::UnicodeString __fastcall DesignerCaptionPostfix(void);
	virtual System::UnicodeString __fastcall ItemNamePrefix(void);
	virtual bool __fastcall CanAdd(void);
	virtual bool __fastcall CanCopy(void);
	virtual bool __fastcall CanCut(void);
	virtual bool __fastcall CanDelete(void);
	virtual bool __fastcall CanSelectAll(void);
	virtual bool __fastcall CanMoveUp(void);
	virtual bool __fastcall CanMoveDown(void);
	virtual bool __fastcall CanPaste(void);
	
public:
	__fastcall TdxNavBarDsgnWindowPageHandler(TdxfmNavBarDesignWindow* ADsgnWindow);
	__fastcall virtual ~TdxNavBarDsgnWindowPageHandler(void);
	void __fastcall Activate(void);
	virtual void __fastcall Add(System::TClass AItemClass);
	virtual void __fastcall Copy(void);
	virtual void __fastcall Cut(void);
	virtual void __fastcall Delete(void);
	virtual void __fastcall ItemDeleted(System::Classes::TPersistent* AItem);
	virtual void __fastcall GetSelections(const Designintf::_di_IDesignerSelections ASelections);
	virtual void __fastcall MoveSelection(int ADelta);
	virtual void __fastcall Paste(void);
	virtual void __fastcall SelectAll(void);
	virtual void __fastcall UpdateContent(void);
	virtual void __fastcall UpdateScrollBar(void);
	virtual void __fastcall UpdateSelections(const Designintf::_di_IDesignerSelections ASelections);
	bool __fastcall IsLocked(void);
	void __fastcall Lock(void);
	void __fastcall UnLock(void);
	__property TdxfmNavBarDesignWindow* DsgnWindow = {read=FDsgnWindow};
	__property Dxnavbar::TdxCustomNavBar* NavBar = {read=GetNavBar};
};

#pragma pack(pop)

__interface IdxNavBarDesignEditor;
typedef System::DelphiInterface<IdxNavBarDesignEditor> _di_IdxNavBarDesignEditor;
__interface  INTERFACE_UUID("{1A11AE34-8BF4-40A6-8B0E-F37399A236CC}") IdxNavBarDesignEditor  : public System::IInterface 
{
	
public:
	virtual void __fastcall Activate(void) = 0 ;
};

class DELPHICLASS TdxNavBarDesigner;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxNavBarDesigner : public Cxdesignwindows::TcxDesignHelper
{
	typedef Cxdesignwindows::TcxDesignHelper inherited;
	
private:
	TdxfmNavBarDesignWindow* FDesignWindow;
	bool FIsBeingModified;
	void __fastcall Activate(void);
	TdxfmNavBarDesignWindow* __fastcall GetDesignWindow(void);
	
public:
	__fastcall virtual TdxNavBarDesigner(System::Classes::TComponent* AComponent);
	__fastcall virtual ~TdxNavBarDesigner(void);
	virtual void __fastcall Modified(void);
	__property TdxfmNavBarDesignWindow* DesignWindow = {read=GetDesignWindow};
private:
	void *__IdxNavBarDesignEditor;	/* IdxNavBarDesignEditor */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1A11AE34-8BF4-40A6-8B0E-F37399A236CC}
	operator _di_IdxNavBarDesignEditor()
	{
		_di_IdxNavBarDesignEditor intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator IdxNavBarDesignEditor*(void) { return (IdxNavBarDesignEditor*)&__IdxNavBarDesignEditor; }
	#endif
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TdxfmNavBarDesignWindow : public Designwindows::TDesignWindow
{
	typedef Designwindows::TDesignWindow inherited;
	
__published:
	Cxgraphics::TcxImageList* ilActions;
	Vcl::Menus::TPopupMenu* pmMain;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* miEdit;
	Vcl::Menus::TMenuItem* miCut;
	Vcl::Menus::TMenuItem* miCopy;
	Vcl::Menus::TMenuItem* miPaste;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* N3;
	Vcl::Menus::TMenuItem* miSelectAll;
	Vcl::Menus::TMenuItem* N4;
	Vcl::Menus::TMenuItem* miMoveUp;
	Vcl::Menus::TMenuItem* miMoveDown;
	Dxnavbar::TdxNavBar* nbMain;
	Dxnavbarcollns::TdxNavBarGroup* bgMain;
	Dxnavbarcollns::TdxNavBarGroup* bgStyles;
	Dxnavbarcollns::TdxNavBarItem* biGroups;
	Dxnavbarcollns::TdxNavBarItem* biLinks;
	Dxnavbarcollns::TdxNavBarItem* biViews;
	Dxnavbarcollns::TdxNavBarItem* biDefaultStyles;
	Dxnavbarcollns::TdxNavBarItem* biCustomStyles;
	Vcl::Extctrls::TPanel* pnCommonButtons;
	Vcl::Stdctrls::TButton* btCancel;
	Vcl::Comctrls::TPageControl* pcMain;
	Vcl::Comctrls::TTabSheet* tsGroups;
	Vcl::Stdctrls::TListBox* lbxGroups;
	Vcl::Comctrls::TTabSheet* tsLinks;
	Vcl::Extctrls::TSplitter* Splitter1;
	Vcl::Comctrls::TTabSheet* tsViews;
	Vcl::Stdctrls::TLabel* Label3;
	Vcl::Stdctrls::TLabel* Label4;
	Dxnavbar::TdxNavBar* nbPreview;
	Dxnavbarcollns::TdxNavBarGroup* bgLocal;
	Dxnavbarcollns::TdxNavBarGroup* bgContacts;
	Dxnavbarcollns::TdxNavBarItem* biInbox;
	Dxnavbarcollns::TdxNavBarItem* biOutbox;
	Dxnavbarcollns::TdxNavBarItem* biSentItems;
	Dxnavbarcollns::TdxNavBarItem* biDeletedItems;
	Dxnavbarcollns::TdxNavBarItem* biReport;
	Vcl::Stdctrls::TListBox* lbxViewStyles;
	Vcl::Comctrls::TTabSheet* tsDefaultStyles;
	Vcl::Stdctrls::TListBox* lbxDefaultStyles;
	Vcl::Comctrls::TTabSheet* tsCustomStyles;
	Vcl::Stdctrls::TListBox* lbxCustomStyles;
	Vcl::Actnlist::TActionList* actlCommands;
	Vcl::Actnlist::TAction* actAdd;
	Vcl::Actnlist::TAction* actMoveUp;
	Vcl::Actnlist::TAction* actMoveDown;
	Vcl::Extctrls::TPanel* pnButtons;
	Vcl::Comctrls::TToolBar* tlbGroups;
	TToolButton* ToolButton3;
	TToolButton* ToolButton6;
	TToolButton* ToolButton1;
	TToolButton* ToolButton2;
	TToolButton* ToolButton7;
	TToolButton* ToolButton5;
	TToolButton* ToolButton12;
	Vcl::Extctrls::TPanel* Panel6;
	Vcl::Comctrls::TToolBar* tlbCustomStyles;
	TToolButton* ToolButton15;
	TToolButton* ToolButton16;
	TToolButton* ToolButton17;
	TToolButton* ToolButton18;
	TToolButton* ToolButton19;
	TToolButton* ToolButton20;
	TToolButton* ToolButton21;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Comctrls::TToolBar* tlbLinkDesigner;
	TToolButton* ToolButton22;
	TToolButton* ToolButton23;
	TToolButton* ToolButton24;
	TToolButton* ToolButton25;
	TToolButton* ToolButton26;
	Dxnavbarcollns::TdxNavBarItem* biItems;
	Vcl::Comctrls::TTabSheet* tsItems;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Comctrls::TToolBar* tlbItems;
	TToolButton* ToolButton4;
	TToolButton* ToolButton8;
	TToolButton* ToolButton9;
	TToolButton* ToolButton10;
	TToolButton* ToolButton11;
	TToolButton* ToolButton13;
	TToolButton* ToolButton14;
	Vcl::Stdctrls::TListBox* lbxItems;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Comctrls::TListView* lbxLinkDesignerItems;
	Vcl::Extctrls::TPanel* Panel4;
	Vcl::Comctrls::TTreeView* tvLinkDesignerGroups;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Extctrls::TPanel* Panel7;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Extctrls::TPanel* Panel8;
	Vcl::Comctrls::TToolBar* tlbDefaultStyles;
	TToolButton* ToolButton27;
	Vcl::Actnlist::TAction* actDefaultSettings;
	Vcl::Actnlist::TAction* actDelete;
	Vcl::Actnlist::TAction* actCut;
	Vcl::Actnlist::TAction* actCopy;
	Vcl::Actnlist::TAction* actPaste;
	Vcl::Actnlist::TAction* actSelectAll;
	Cxgraphics::TcxImageList* ilNavBarLarge;
	Cxgraphics::TcxImageList* ilNavBarSmall;
	Cxgraphics::TcxImageList* ilLinkDesigner;
	Cxgraphics::TcxImageList* ilToolBar;
	Cxgraphics::TcxImageList* ilTreeView;
	Cxgraphics::TcxImageList* ilToolBarDisabled;
	Vcl::Menus::TPopupMenu* pmGroupItemClasses;
	Vcl::Menus::TMenuItem* msiAdd;
	Vcl::Stdctrls::TComboBox* cbColorScheme;
	Vcl::Stdctrls::TLabel* lblColorScheme;
	Cxgraphics::TcxImageList* ilPreviewSmall;
	Cxgraphics::TcxImageList* ilPreviewLarge;
	Dxnavbarcollns::TdxNavBarItem* nbCalendar;
	Dxnavbarcollns::TdxNavBarItem* nbTask;
	Vcl::Comctrls::TTabSheet* TabSheet1;
	Dxnavbarcollns::TdxNavBarItem* biLookAndFeelViews;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Stdctrls::TComboBox* cbCategories;
	Vcl::Stdctrls::TLabel* Label6;
	Vcl::Stdctrls::TComboBox* cbFlat;
	Vcl::Stdctrls::TLabel* Label7;
	Vcl::Stdctrls::TComboBox* cbStandard;
	Vcl::Stdctrls::TLabel* Label8;
	Vcl::Stdctrls::TComboBox* cbUltraFlat;
	Vcl::Stdctrls::TLabel* Label9;
	Vcl::Stdctrls::TComboBox* cbOffice11;
	Vcl::Stdctrls::TLabel* Label10;
	Vcl::Stdctrls::TComboBox* cbNative;
	Vcl::Stdctrls::TLabel* Label11;
	Vcl::Stdctrls::TComboBox* cbSkin;
	Vcl::Stdctrls::TLabel* Label12;
	Vcl::Stdctrls::TComboBox* cbLookAndFeelSchemes;
	Vcl::Stdctrls::TCheckBox* chSortViews;
	void __fastcall ListBoxClick(System::TObject* Sender);
	void __fastcall AddClick(System::TObject* Sender);
	void __fastcall ActionClick(System::TObject* Sender);
	void __fastcall MoveUpClick(System::TObject* Sender);
	void __fastcall MoveDownClick(System::TObject* Sender);
	void __fastcall tvLinkDesignerGroupsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall tvLinkDesignerGroupsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall tvLinkDesignerGroupsStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall lbxLinkDesignerItemsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbxLinkDesignerItemsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall lbxLinkDesignerItemsStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall tvLinkDesignerGroupsExit(System::TObject* Sender);
	void __fastcall tvLinkDesignerGroupsEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall lbxLinkDesignerItemsEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall nbMainLinkClick(System::TObject* Sender, Dxnavbarcollns::TdxNavBarItemLink* ALink);
	void __fastcall DefaultSettingsClick(System::TObject* Sender);
	void __fastcall lbxViewStylesChange(System::TObject* Sender);
	void __fastcall btCancelClick(System::TObject* Sender);
	void __fastcall lbxItemsContextPopup(System::TObject* Sender, const System::Types::TPoint &MousePos, bool &Handled);
	void __fastcall lbxContextPopup(System::TObject* Sender, const System::Types::TPoint &MousePos, bool &Handled);
	void __fastcall cbColorSchemeChange(System::TObject* Sender);
	void __fastcall cbCategoriesChange(System::TObject* Sender);
	void __fastcall cbFlatChange(System::TObject* Sender);
	void __fastcall cbLookAndFeelSchemesChange(System::TObject* Sender);
	void __fastcall chSortViewsClick(System::TObject* Sender);
	void __fastcall actlCommandsUpdate(System::Classes::TBasicAction* Action, bool &Handled);
	
private:
	Dxnavbar::TdxCustomNavBar* FNavBar;
	System::Classes::TList* FHandlers;
	TdxNavBarDsgnWindowPageHandler* FCurrentHandler;
	System::Uitypes::TCursor FSaveCursor;
	Cxclasses::_di_IcxDesignHelper __fastcall GetNavBarDesigner(void);
	void __fastcall SetNavBar(Dxnavbar::TdxCustomNavBar* Value);
	void __fastcall ActivatePage(int APageIndex);
	bool __fastcall CanAdd(void);
	bool __fastcall CanCopy(void);
	bool __fastcall CanCut(void);
	bool __fastcall CanDelete(void);
	bool __fastcall CanMoveDown(void);
	bool __fastcall CanMoveUp(void);
	bool __fastcall CanPaste(void);
	bool __fastcall CanSelectAll(void);
	void __fastcall Copy(void);
	void __fastcall Cut(void);
	void __fastcall Delete(void);
	void __fastcall HandleException(void);
	System::UnicodeString __fastcall GetRegistryPath(void);
	void __fastcall Paste(void);
	void __fastcall RestoreLayout(void);
	void __fastcall SafeChangeLookAndFeelScheme(Cxlookandfeelpainters::TcxLookAndFeelStyle ALookAndFeelStyle, int ANavBarID);
	void __fastcall Select(System::Classes::TComponent* AComponent, bool AddToSelection);
	void __fastcall SelectAll(void);
	void __fastcall SelectNavBar(void);
	void __fastcall StartWait(void);
	void __fastcall StopWait(void);
	void __fastcall StoreLayout(void);
	void __fastcall UpdateCaption(void);
	void __fastcall UpdateSelections(const Designintf::_di_IDesignerSelections ASelections);
	Dxnavbar::TdxNavBarViewCategories __fastcall GetCategories(int AIndex);
	TdxNavBarDsgnWindowPageHandler* __fastcall GetHandler(int Index);
	int __fastcall GetHandlerCount(void);
	
protected:
	DYNAMIC void __fastcall Activated(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	virtual System::UnicodeString __fastcall UniqueName(System::Classes::TComponent* Component);
	void __fastcall ActiveDesignerPageChanged(void);
	void __fastcall CheckViewCategories(void);
	void __fastcall InitializeHandlers(void);
	void __fastcall InitializeViewStyles(void);
	bool __fastcall IsCategoriesSuitable(Dxnavbar::TdxNavBarViewCategories ACategories);
	void __fastcall FinalizeHandlers(void);
	void __fastcall SynchronizeViewStyleSelection(void);
	Vcl::Stdctrls::TComboBox* __fastcall GetSchemeComboByLookAndFeelStyle(Cxlookandfeelpainters::TcxLookAndFeelStyle ALookAndFeelStyle);
	Cxlookandfeelpainters::TcxLookAndFeelStyle __fastcall GetLookAndFeelBySchemeCombo(Vcl::Stdctrls::TComboBox* ACombo);
	void __fastcall UpdateNavBarLookAndFeelScheme(void);
	
public:
	__fastcall virtual TdxfmNavBarDesignWindow(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmNavBarDesignWindow(void);
	HIDESBASE bool __fastcall ClipboardComponents(void);
	virtual bool __fastcall EditAction(Designintf::TEditAction Action);
	virtual Designintf::TEditState __fastcall GetEditState(void);
	virtual void __fastcall ItemDeleted(const Designintf::_di_IDesigner ADesigner, System::Classes::TPersistent* Item);
	virtual void __fastcall ItemsModified(const Designintf::_di_IDesigner Designer);
	virtual void __fastcall SelectionChanged(const Designintf::_di_IDesigner ADesigner, const Designintf::_di_IDesignerSelections ASelection);
	__property TdxNavBarDsgnWindowPageHandler* CurrentHandler = {read=FCurrentHandler, write=FCurrentHandler};
	__property int HandlerCount = {read=GetHandlerCount, nodefault};
	__property TdxNavBarDsgnWindowPageHandler* Handlers[int Index] = {read=GetHandler};
	__property Dxnavbar::TdxCustomNavBar* NavBar = {read=FNavBar, write=SetNavBar};
	__property Cxclasses::_di_IcxDesignHelper NavBarDesigner = {read=GetNavBarDesigner};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmNavBarDesignWindow(System::Classes::TComponent* AOwner, int Dummy) : Designwindows::TDesignWindow(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmNavBarDesignWindow(HWND ParentWindow) : Designwindows::TDesignWindow(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxNavBarViewStyleHasColorSchemes(Dxnavbar::TdxNavBarPainter* AViewStyle);
extern PACKAGE void __fastcall dxShowNavBarDesigner(Dxnavbar::TdxCustomNavBar* ANavBar);
}	/* namespace Dxfmnavbardsgneditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXFMNAVBARDSGNEDITOR)
using namespace Dxfmnavbardsgneditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxfmnavbardsgneditorHPP
