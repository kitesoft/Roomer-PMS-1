// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxTLItemsEditor.pas' rev: 24.00 (Win32)

#ifndef CxtlitemseditorHPP
#define CxtlitemseditorHPP

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
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxInplaceContainer.hpp>	// Pascal unit
#include <cxTL.hpp>	// Pascal unit
#include <cxDBTL.hpp>	// Pascal unit
#include <cxTLStrs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxtlitemseditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfrmItemsEditor;
class PASCALIMPLEMENTATION TfrmItemsEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Menus::TPopupMenu* mnuEditItems;
	Vcl::Menus::TMenuItem* NewItem1;
	Vcl::Menus::TMenuItem* NewSubItem1;
	Vcl::Menus::TMenuItem* Delete1;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* Customize1;
	Vcl::Extctrls::TPanel* Panel2;
	Cxbuttons::TcxButton* btnCustomize;
	Vcl::Extctrls::TPanel* Panel3;
	Cxbuttons::TcxButton* btnNewItem;
	Cxbuttons::TcxButton* btnNewSubItem;
	Cxbuttons::TcxButton* btnDelete;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Stdctrls::TGroupBox* gbIndexes;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TLabel* Label3;
	Cxtextedit::TcxTextEdit* edtImage;
	Cxtextedit::TcxTextEdit* edtSelected;
	Cxtextedit::TcxTextEdit* edtState;
	Vcl::Extctrls::TPanel* Panel6;
	Vcl::Extctrls::TPanel* Panel7;
	Vcl::Extctrls::TPanel* Panel10;
	Cxtl::TcxTreeList* cxTLSite;
	Vcl::Extctrls::TPanel* Panel8;
	Cxtl::TcxTreeListColumn* cxTreeList1cxTreeListColumn1;
	Cxtextedit::TcxTextEdit* edtOverlay;
	Vcl::Stdctrls::TLabel* Label7;
	Cxtextedit::TcxTextEdit* edtOverlayState;
	Vcl::Stdctrls::TLabel* Label9;
	Cxtextedit::TcxTextEdit* edtDefImage;
	Cxtextedit::TcxTextEdit* edtDefSelected;
	Cxtextedit::TcxTextEdit* edtDefState;
	Cxtextedit::TcxTextEdit* edtDefOverlay;
	Cxtextedit::TcxTextEdit* edtDefOverlayState;
	Vcl::Stdctrls::TLabel* Label4;
	Vcl::Stdctrls::TLabel* Label5;
	Vcl::Stdctrls::TLabel* lbCheckType;
	Cxdropdownedit::TcxComboBox* cbCheckGroupType;
	Cxcheckbox::TcxCheckBox* cbEnabled;
	Vcl::Extctrls::TBevel* Bevel1;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	void __fastcall cxButtonPress(System::TObject* Sender);
	void __fastcall edtImageExit(System::TObject* Sender);
	void __fastcall edtImageKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall cxTLSiteDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall cbCheckGroupTypePropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall cxCheckBox1PropertiesEditValueChanged(System::TObject* Sender);
	
private:
	Cxtl::TcxCustomTreeList* FDBTLSite;
	Cxtl::TcxCustomTreeList* FEditControl;
	Cxtl::TcxTreeListNode* __fastcall GetFocusedNode(void);
	Cxtl::TcxCustomTreeList* __fastcall GetTreeList(void);
	void __fastcall SetEditControl(Cxtl::TcxCustomTreeList* AValue);
	
protected:
	void __fastcall CheckEditControl(void);
	virtual void __fastcall Loaded(void);
	void __fastcall DoOnChangeTreeList(System::TObject* Sender);
	void __fastcall DoSetImageIndex(Cxtextedit::TcxTextEdit* Sender);
	int __fastcall GetValue(Cxtextedit::TcxTextEdit* Sender);
	void __fastcall ComponentRemoved(System::TObject* Sender);
	void __fastcall ComponentModified(void);
	
public:
	__property Cxtl::TcxCustomTreeList* EditControl = {read=FEditControl, write=SetEditControl};
	__property Cxtl::TcxTreeListNode* FocusedNode = {read=GetFocusedNode};
	__property Cxtl::TcxCustomTreeList* TreeList = {read=GetTreeList};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrmItemsEditor(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrmItemsEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrmItemsEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrmItemsEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
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
extern PACKAGE bool __fastcall cxShowTreeListItemsEditor(Cxtl::TcxCustomTreeList* AControl);
}	/* namespace Cxtlitemseditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXTLITEMSEDITOR)
using namespace Cxtlitemseditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxtlitemseditorHPP
