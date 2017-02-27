// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTLEditor.pas' rev: 24.00 (Win32)

#ifndef CxtleditorHPP
#define CxtleditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <ComponentDesigner.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxTLStrs.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxTL.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.Math.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtleditor
{
//-- type declarations -------------------------------------------------------
typedef void __fastcall (__closure *TcxTreeListSetIndexProc)(System::TObject* AItem, int AIndex);

typedef void __fastcall (__closure *TcxTreeListAddItemProc)(Vcl::Stdctrls::TListBox* AListBox, int AIndex);

enum TcxTreeListDesignerChange : unsigned char { tldsgStructure, tldsgSelection };

typedef System::Set<TcxTreeListDesignerChange, TcxTreeListDesignerChange::tldsgStructure, TcxTreeListDesignerChange::tldsgSelection>  TcxTreeListDesignerChanges;

class DELPHICLASS TcxTreeListBandColumnDesigner;
class PASCALIMPLEMENTATION TcxTreeListBandColumnDesigner : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Comctrls::TPageControl* PageControl;
	Vcl::Comctrls::TTabSheet* tsBands;
	Vcl::Extctrls::TPanel* Panel12;
	Vcl::Stdctrls::TListBox* lbxBands;
	Vcl::Comctrls::TTabSheet* tsColumns;
	Vcl::Extctrls::TPanel* pnButtons;
	Vcl::Stdctrls::TListBox* lbxColumns;
	Vcl::Menus::TPopupMenu* pmColumns;
	Vcl::Menus::TPopupMenu* pmBands;
	Cxbuttons::TcxButton* btnBAdd;
	Cxbuttons::TcxButton* btnCreateAllFields;
	Cxbuttons::TcxButton* btnBDel;
	Cxbuttons::TcxButton* btnBMoveU;
	Cxbuttons::TcxButton* btnBMoveD;
	Cxbuttons::TcxButton* btnBResD;
	Cxbuttons::TcxButton* btnBResW;
	Cxbuttons::TcxButton* btnCAdd;
	Cxbuttons::TcxButton* btnCDel;
	Cxbuttons::TcxButton* btnCMoveU;
	Cxbuttons::TcxButton* btnCMoveD;
	Cxbuttons::TcxButton* btnCResD;
	Cxbuttons::TcxButton* btnCResW;
	Vcl::Menus::TMenuItem* mnuBAdd;
	Vcl::Menus::TMenuItem* mnuCSelectAll;
	Vcl::Menus::TMenuItem* mnuBDel;
	Vcl::Menus::TMenuItem* mnuCAdd;
	Vcl::Menus::TMenuItem* mnuBMoveU;
	Vcl::Menus::TMenuItem* mnuBMoveD;
	Vcl::Menus::TMenuItem* mnuBResD;
	Vcl::Menus::TMenuItem* mnuBResW;
	Vcl::Menus::TMenuItem* mnuCDel;
	Vcl::Menus::TMenuItem* mnuCMoveU;
	Vcl::Menus::TMenuItem* mnuCMoveD;
	Vcl::Menus::TMenuItem* mnuCResD;
	Vcl::Menus::TMenuItem* mnuCResW;
	Vcl::Menus::TMenuItem* mnuCreateAllFields;
	Vcl::Menus::TMenuItem* mnuBSelectAll;
	void __fastcall BandTabButtonsClick(System::TObject* Sender);
	void __fastcall ColumnsListClick(System::TObject* Sender);
	void __fastcall ColumnsEventHandle(System::TObject* Sender);
	void __fastcall BandsListClick(System::TObject* Sender);
	void __fastcall lbxKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall PageControlChange(System::TObject* Sender);
	void __fastcall lbxColumnsDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall lbxBandsDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	
private:
	TcxTreeListDesignerChanges FChanges;
	int FLockCount;
	void __fastcall AddBand(Vcl::Stdctrls::TListBox* AListBox, int AIndex);
	void __fastcall AddColumn(Vcl::Stdctrls::TListBox* AListBox, int AIndex);
	Cxtl::_di_IcxTreeListDesignTimeOperations __fastcall GetOperations(void);
	Cxtl::TcxCustomTreeList* __fastcall GetTreeList(void);
	
protected:
	virtual void __fastcall Loaded(void);
	void __fastcall DeleteSelection(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall InitControls(void);
	void __fastcall SyncEnabled(void);
	void __fastcall SelectAllItems(Vcl::Stdctrls::TListBox* AListBox, System::Classes::TPersistent* ADefaultComponent);
	void __fastcall UpdateItems(Vcl::Stdctrls::TListBox* AListBox, int AItemCount, TcxTreeListAddItemProc AAddItemProc);
	void __fastcall UpdateLists(bool ARecreate);
	void __fastcall CalculateListBoxItemHeight(Vcl::Stdctrls::TListBox* AListBox);
	void __fastcall DrawListBoxItem(Vcl::Stdctrls::TListBox* AListBox, int AIndex, const System::Types::TRect &R, Cxtl::TcxTreeListBand* AParentBand);
	void __fastcall MoveBy(Vcl::Stdctrls::TListBox* AListBox, int AIncrement, TcxTreeListSetIndexProc ASetIndex);
	void __fastcall SetBandIndex(System::TObject* AItem, int AIndex);
	void __fastcall SetColumnIndex(System::TObject* AItem, int AIndex);
	void __fastcall ComponentRemoved(System::TObject* Sender);
	void __fastcall ComponentModified(void);
	__property Cxtl::_di_IcxTreeListDesignTimeOperations Operations = {read=GetOperations};
	__property Cxtl::TcxCustomTreeList* TreeList = {read=GetTreeList};
	
public:
	__fastcall virtual ~TcxTreeListBandColumnDesigner(void);
	DYNAMIC void __fastcall Activate(void);
	HIDESBASE void __fastcall BeginUpdate(void);
	HIDESBASE void __fastcall EndUpdate(void);
	virtual void __fastcall InitFormEditor(void);
	virtual void __fastcall DoItemDeleted(System::Classes::TPersistent* AItem);
	virtual void __fastcall DoItemsModified(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	void __fastcall SetVisiblePageIndex(int AIndex);
public:
	/* TcxDesignWindow.Create */ inline __fastcall virtual TcxTreeListBandColumnDesigner(System::Classes::TComponent* AOwner) : Cxdesignwindows::TcxDesignFormEditor(AOwner) { }
	
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxTreeListBandColumnDesigner(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxTreeListBandColumnDesigner(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
private:
	void *__IcxTreeListDesigner;	/* Cxtl::IcxTreeListDesigner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {1F4D4387-57E1-4756-9093-1124077A0F54}
	operator Cxtl::_di_IcxTreeListDesigner()
	{
		Cxtl::_di_IcxTreeListDesigner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxtl::IcxTreeListDesigner*(void) { return (Cxtl::IcxTreeListDesigner*)&__IcxTreeListDesigner; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxtleditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTLEDITOR)
using namespace Cxtleditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtleditorHPP
