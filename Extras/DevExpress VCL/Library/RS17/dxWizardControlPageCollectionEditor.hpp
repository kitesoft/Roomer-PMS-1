// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxWizardControlPageCollectionEditor.pas' rev: 24.00 (Win32)

#ifndef DxwizardcontrolpagecollectioneditorHPP
#define DxwizardcontrolpagecollectioneditorHPP

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
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <dxWizardControl.hpp>	// Pascal unit
#include <dxCustomWizardControl.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxPropEditors.hpp>	// Pascal unit
#include <dxWizardControlStrs.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxwizardcontrolpagecollectioneditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxWizardControlPageCollectionEditorForm;
class PASCALIMPLEMENTATION TdxWizardControlPageCollectionEditorForm : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Actnlist::TAction* acAdd;
	Vcl::Actnlist::TAction* acDelete;
	Vcl::Actnlist::TAction* acMoveDown;
	Vcl::Actnlist::TAction* acMoveUp;
	Vcl::Actnlist::TActionList* alActions;
	Vcl::Stdctrls::TButton* btnAdd;
	Vcl::Stdctrls::TButton* btnCancel;
	Vcl::Stdctrls::TButton* btnDelete;
	Vcl::Stdctrls::TButton* btnMoveDown;
	Vcl::Stdctrls::TButton* btnMoveUp;
	Vcl::Stdctrls::TButton* btnOK;
	Vcl::Stdctrls::TListBox* lbPages;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* miMoveDown;
	Vcl::Menus::TMenuItem* miMoveUp;
	Vcl::Menus::TMenuItem* miSeparator;
	Vcl::Menus::TPopupMenu* pmPagesMenu;
	void __fastcall acAddExecute(System::TObject* Sender);
	void __fastcall acDeleteExecute(System::TObject* Sender);
	void __fastcall acMoveDownExecute(System::TObject* Sender);
	void __fastcall acMoveUpExecute(System::TObject* Sender);
	void __fastcall lbPagesClick(System::TObject* Sender);
	
private:
	Designintf::_di_IDesigner FDesigner;
	Dxcustomwizardcontrol::TdxCustomWizardControl* FWizardControl;
	System::UnicodeString __fastcall GetPageName(Dxcustomwizardcontrol::TdxWizardControlCustomPage* APage);
	void __fastcall UpdateActionsState(void);
	
public:
	void __fastcall LoadParams(void);
	void __fastcall SaveParams(void);
	__property Dxcustomwizardcontrol::TdxCustomWizardControl* WizardControl = {read=FWizardControl};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxWizardControlPageCollectionEditorForm(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxWizardControlPageCollectionEditorForm(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxWizardControlPageCollectionEditorForm(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxWizardControlPageCollectionEditorForm(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall ExecutePageCollectionEditor(Dxcustomwizardcontrol::TdxCustomWizardControl* AWizardControl, Designintf::_di_IDesigner ADesigner);
}	/* namespace Dxwizardcontrolpagecollectioneditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXWIZARDCONTROLPAGECOLLECTIONEDITOR)
using namespace Dxwizardcontrolpagecollectioneditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxwizardcontrolpagecollectioneditorHPP
