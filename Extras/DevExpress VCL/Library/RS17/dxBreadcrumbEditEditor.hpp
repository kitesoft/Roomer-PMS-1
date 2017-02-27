// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBreadcrumbEditEditor.pas' rev: 24.00 (Win32)

#ifndef DxbreadcrumbediteditorHPP
#define DxbreadcrumbediteditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <dxBreadcrumbEdit.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <dxBevel.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbreadcrumbediteditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxBreadcrumbEditEditorForm;
class PASCALIMPLEMENTATION TdxBreadcrumbEditEditorForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnDeleteItem;
	Cxbuttons::TcxButton* btnNewItem;
	Cxbuttons::TcxButton* btnNewSubItem;
	Dxbevel::TdxBevel* bvlLine;
	Cxcheckbox::TcxCheckBox* cbSaveSelection;
	Cxbuttons::TcxButton* cxBtnCancel;
	Cxbuttons::TcxButton* cxBtnOK;
	Cxgroupbox::TcxGroupBox* gbItemOptions;
	Cxlabel::TcxLabel* lbItemImageIndex;
	Cxlabel::TcxLabel* lbItemText;
	Cxspinedit::TcxSpinEdit* seItemImageIndex;
	Cxtextedit::TcxTextEdit* teItemText;
	Cxtreeview::TcxTreeView* tvStruct;
	void __fastcall tvStructChange(System::TObject* Sender, Vcl::Comctrls::TTreeNode* Node);
	void __fastcall teItemOptionsChange(System::TObject* Sender);
	void __fastcall btnDeleteItemClick(System::TObject* Sender);
	void __fastcall btnNewItemClick(System::TObject* Sender);
	void __fastcall btnNewSubItemClick(System::TObject* Sender);
	
protected:
	bool FUpdatingItemOptionsData;
	System::UnicodeString __fastcall GenerateSubItemName(Vcl::Comctrls::TTreeNode* ANode);
	bool __fastcall GetHasSelection(void);
	System::UnicodeString __fastcall GetSelectedPath(void);
	bool __fastcall IsTreeRoot(Vcl::Comctrls::TTreeNode* ANode);
	void __fastcall EnableContainerControls(Vcl::Controls::TWinControl* AContainer, bool AEnabled);
	
public:
	void __fastcall Load(Dxbreadcrumbedit::TdxBreadcrumbEdit* ABreadcrumbEdit);
	void __fastcall Save(Dxbreadcrumbedit::TdxBreadcrumbEdit* ABreadcrumbEdit);
	void __fastcall UpdateCaption(System::Classes::TComponent* AComponent);
	void __fastcall UpdateControlsState(void);
	void __fastcall UpdateItemOptionsData(void);
	__property bool HasSelection = {read=GetHasSelection, nodefault};
	__property System::UnicodeString SelectedPath = {read=GetSelectedPath};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxBreadcrumbEditEditorForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBreadcrumbEditEditorForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxBreadcrumbEditEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBreadcrumbEditEditorForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxBreadcrumbEditShowEditor(Dxbreadcrumbedit::TdxBreadcrumbEdit* ABreadcrumbEdit);
}	/* namespace Dxbreadcrumbediteditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBREADCRUMBEDITEDITOR)
using namespace Dxbreadcrumbediteditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbreadcrumbediteditorHPP
