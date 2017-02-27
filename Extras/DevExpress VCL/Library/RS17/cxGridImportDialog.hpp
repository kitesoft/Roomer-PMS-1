// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridImportDialog.pas' rev: 24.00 (Win32)

#ifndef CxgridimportdialogHPP
#define CxgridimportdialogHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxConverterFactory.hpp>	// Pascal unit
#include <cxGridConverter.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <System.TypInfo.hpp>	// Pascal unit
#include <cxGridStructureNavigator.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridimportdialog
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TImportDialog;
class PASCALIMPLEMENTATION TImportDialog : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel1;
	Cxbuttons::TcxButton* btnImport;
	Cxbuttons::TcxButton* btnClose;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel4;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Stdctrls::TListBox* lbComponentsForImport;
	Vcl::Extctrls::TPanel* Panel6;
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* TabSheet1;
	Cxcheckbox::TcxCheckBox* cbDeleteAllSublevels;
	Cxpc::TcxTabSheet* TabSheet2;
	Cxcheckbox::TcxCheckBox* cbImportStyles;
	Vcl::Extctrls::TPanel* Panel7;
	Vcl::Stdctrls::TLabel* lblLevelName;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Extctrls::TPanel* pnlStructureControlSite;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Extctrls::TPanel* Panel8;
	Cxradiogroup::TcxRadioButton* rbCreateNewStyleRepository;
	Cxradiogroup::TcxRadioButton* rbUseExistingStyleRepository;
	Cxtextedit::TcxTextEdit* edNewStyleRepository;
	Cxdropdownedit::TcxComboBox* cbStyleRepositories;
	void __fastcall btnCloseClick(System::TObject* Sender);
	void __fastcall FormShow(System::TObject* Sender);
	void __fastcall btnImportClick(System::TObject* Sender);
	void __fastcall lbComponentsForImportClick(System::TObject* Sender);
	void __fastcall lbComponentsForImportDblClick(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	void __fastcall cbImportStylesClick(System::TObject* Sender);
	void __fastcall rbStyleRepositoryClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall lbComponentsForImportMeasureItem(Vcl::Controls::TWinControl* Control, int Index, int &Height);
	
private:
	Cxgrid::TcxCustomGrid* FGrid;
	Designintf::_di_IDesigner FDesigner;
	Cxgridstructurenavigator::TcxGridStructureControl* FGridStructureControl;
	Cxgridstructurenavigator::TcxGridStructureHelper* FGridStructureHelper;
	System::Classes::TStringList* FIntermediaryList;
	Cxgridlevel::TcxGridLevel* FLevel;
	HIDESBASE System::Classes::TComponent* __fastcall GetComponent(void);
	void __fastcall SetGrid(Cxgrid::TcxCustomGrid* Value);
	void __fastcall SetLevel(Cxgridlevel::TcxGridLevel* Value);
	Cxgridconverter::TcxCustomGridConverterClass __fastcall GetConverterClass(System::TObject* ASource);
	void __fastcall LoadComponentForImport(const System::UnicodeString S);
	void __fastcall LoadIntermediary(const System::UnicodeString S);
	void __fastcall LoadStyleRepository(const System::UnicodeString S);
	void __fastcall DoImport(void);
	void __fastcall DisableStylesOptions(void);
	void __fastcall EnableStylesOptions(void);
	System::Classes::TComponent* __fastcall GetIntermediaryComponent(void);
	void __fastcall StructureControlSelectionChanged(System::TObject* Sender);
	void __fastcall UpdateDesigner(System::TObject* Sender);
	void __fastcall UpdateStyleRepositoryEdits(void);
	
protected:
	__property System::Classes::TComponent* Component = {read=GetComponent};
	__property Cxgridlevel::TcxGridLevel* Level = {read=FLevel, write=SetLevel};
	
public:
	__property Cxgrid::TcxCustomGrid* Grid = {read=FGrid, write=SetGrid};
	__property Designintf::_di_IDesigner Designer = {read=FDesigner, write=FDesigner};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TImportDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TImportDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TImportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TImportDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowGridImportDialog(Designintf::_di_IDesigner ADesigner, Cxgrid::TcxCustomGrid* AGrid);
}	/* namespace Cxgridimportdialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDIMPORTDIALOG)
using namespace Cxgridimportdialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridimportdialogHPP
