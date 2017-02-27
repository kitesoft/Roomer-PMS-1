// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmAutoHFTextFmt.pas' rev: 24.00 (Win64)

#ifndef DxpsfmautohftextfmtHPP
#define DxpsfmautohftextfmtHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
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
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxPgsDlg.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxGeometry.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxPSHFToolBarBld.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmautohftextfmt
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxfmAutoText;
class PASCALIMPLEMENTATION TdxfmAutoText : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxgroupbox::TcxGroupBox* gbxEnterAutoTextEntriesHere;
	Vcl::Extctrls::TPaintBox* pbxPreview;
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnDelete;
	Cxlabel::TcxLabel* lblPreview;
	Cxtextedit::TcxTextEdit* cbxAutoEntries;
	Cxlistbox::TcxListBox* cbxAutoEntriesList;
	Cxgroupbox::TcxGroupBox* ToolBar;
	void __fastcall pbxPreviewPaint(System::TObject* Sender);
	void __fastcall NewAutoTextChange(System::TObject* Sender);
	void __fastcall NewAutoTextKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall btnAddClick(System::TObject* Sender);
	void __fastcall btnDeleteClick(System::TObject* Sender);
	void __fastcall cbxAutoEntriesExit(System::TObject* Sender);
	void __fastcall cbxAutoEntriesEnter(System::TObject* Sender);
	void __fastcall cbxAutoEntriesPropertiesChange(System::TObject* Sender);
	void __fastcall cbxAutoEntriesListClick(System::TObject* Sender);
	void __fastcall cbxAutoEntriesKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall cbxAutoEntriesListKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	System::Classes::TStringList* FFunctionList;
	int FSelectedEntryIndex;
	Dxpshftoolbarbld::TdxPSHFToolBarHelper* FToolBarHelper;
	Vcl::Controls::TImageList* FToolBarImages;
	System::Classes::TStrings* __fastcall GetEntries(void);
	void __fastcall DoInsertMacrosValue(System::TObject* Sender, const System::UnicodeString AMacrosValue);
	void __fastcall EnableToolbar(bool Value);
	void __fastcall LoadTranslations(void);
	void __fastcall SetEntries(System::Classes::TStrings* Value);
	void __fastcall SetSelectedEntryIndex(int AIndex);
	void __fastcall UpdateControlsState(void);
	__property System::Classes::TStringList* FunctionList = {read=FFunctionList};
	__property Vcl::Controls::TImageList* ToolBarImages = {read=FToolBarImages};
	
public:
	__fastcall virtual TdxfmAutoText(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmAutoText(void);
	bool __fastcall Execute(void);
	__property System::Classes::TStrings* Entries = {read=GetEntries, write=SetEntries};
	__property int SelectedEntryIndex = {read=FSelectedEntryIndex, write=SetSelectedEntryIndex, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmAutoText(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmAutoText(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowAutoTextDlg(System::Classes::TStrings* AStrings);
}	/* namespace Dxpsfmautohftextfmt */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMAUTOHFTEXTFMT)
using namespace Dxpsfmautohftextfmt;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmautohftextfmtHPP
