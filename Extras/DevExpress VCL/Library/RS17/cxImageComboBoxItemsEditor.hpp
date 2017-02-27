// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxImageComboBoxItemsEditor.pas' rev: 24.00 (Win32)

#ifndef CximagecomboboxitemseditorHPP
#define CximagecomboboxitemseditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxData.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxImageComboBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxGridTableView.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCalendar.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cximagecomboboxitemseditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TfmImageComboBoxItemsEditor;
class PASCALIMPLEMENTATION TfmImageComboBoxItemsEditor : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel1;
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnDelete;
	Cxbuttons::TcxButton* btnInsert;
	Vcl::Menus::TPopupMenu* mnuValueTypes;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miInsert;
	Vcl::Menus::TMenuItem* miDelete;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* miHelp;
	Vcl::Extctrls::TPanel* Panel3;
	Cxgrid::TcxGrid* cxgImageComboBoxItems;
	Cxgridtableview::TcxGridTableView* tvImageComboBoxItems;
	Cxgridtableview::TcxGridColumn* clnImage;
	Cxgridtableview::TcxGridColumn* clnValue;
	Cxgridtableview::TcxGridColumn* clnDescription;
	Cxgridtableview::TcxGridColumn* clnTag;
	Cxgridlevel::TcxGridLevel* lvImageComboBoxItems;
	Vcl::Extctrls::TBevel* Bevel1;
	Cxbuttons::TcxButton* btnOk;
	Cxbuttons::TcxButton* btnCancel;
	Cxgridtableview::TcxGridColumn* clnValueType;
	Cxbuttons::TcxButton* btnSelectAll;
	Cxbuttons::TcxButton* btnValueType;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall btnAddClick(System::TObject* Sender);
	void __fastcall btnDeleteClick(System::TObject* Sender);
	void __fastcall btnInsertClick(System::TObject* Sender);
	void __fastcall btnOkClick(System::TObject* Sender);
	void __fastcall btnSelectAllClick(System::TObject* Sender);
	void __fastcall clnValueTypePropertiesEditValueChanged(System::TObject* Sender);
	void __fastcall miValueTypeClick(System::TObject* Sender);
	void __fastcall tvImageComboBoxItemsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall tvImageComboBoxItemsDataControllerRecordChanged(Cxcustomdata::TcxCustomDataController* ADataController, int ARecordIndex, int AItemIndex);
	void __fastcall tvImageComboBoxItemsEditKeyDown(Cxgridcustomtableview::TcxCustomGridTableView* Sender, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, Cxedit::TcxCustomEdit* AEdit, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	Cximagecombobox::TcxImageComboBoxItems* FImageComboBoxItems;
	Vcl::Imglist::TCustomImageList* FImages;
	Vcl::Imglist::TCustomImageList* FLargeImages;
	void __fastcall FillGridViewRecords(Cximagecombobox::TcxImageComboBoxItems* AImageComboBoxItems);
	void __fastcall FocusAndSelectRecord(int ARecordIndex);
	System::UnicodeString __fastcall GetVarTypeName(System::Word AVarType);
	System::Word __fastcall GetVarTypeByName(System::UnicodeString AVarTypeName);
	void __fastcall InitNewRecord(int ARecordIndex);
	void __fastcall PopulateImages(Vcl::Imglist::TCustomImageList* AImages, Vcl::Imglist::TCustomImageList* ALargeImages);
	void __fastcall PopulateValueTypeNames(void);
	void __fastcall SetItemValueType(int ARecordIndex, System::Word AValueType);
	void __fastcall SetSelectionValueType(System::Word AValueType);
	bool __fastcall ValueToValueType(System::Variant &AValue, System::Word AValueType);
	
public:
	__fastcall TfmImageComboBoxItemsEditor(Cximagecombobox::TcxImageComboBoxItems* AItems, Vcl::Imglist::TCustomImageList* AImages, Vcl::Imglist::TCustomImageList* ALargeImages)/* overload */;
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmImageComboBoxItemsEditor(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmImageComboBoxItemsEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmImageComboBoxItemsEditor(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cximagecomboboxitemseditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXIMAGECOMBOBOXITEMSEDITOR)
using namespace Cximagecomboboxitemseditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CximagecomboboxitemseditorHPP
