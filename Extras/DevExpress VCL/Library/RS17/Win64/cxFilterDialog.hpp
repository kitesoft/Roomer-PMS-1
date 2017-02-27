// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxFilterDialog.pas' rev: 24.00 (Win64)

#ifndef CxfilterdialogHPP
#define CxfilterdialogHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <cxButtonEdit.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxFilter.hpp>	// Pascal unit
#include <cxFilterConsts.hpp>	// Pascal unit
#include <cxFilterControlUtils.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxfilterdialog
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxFilterDialogClass;

class DELPHICLASS TcxFilterDialog;
class PASCALIMPLEMENTATION TcxFilterDialog : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxlabel::TcxLabel* lblTitle;
	Cxlabel::TcxLabel* lblColumnCaption;
	Cxlabel::TcxLabel* lblSingle;
	Cxlabel::TcxLabel* lblSeries;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxdropdownedit::TcxComboBox* cbOperator1;
	Cxdropdownedit::TcxComboBox* cbOperator2;
	Cxradiogroup::TcxRadioButton* rbAnd;
	Cxradiogroup::TcxRadioButton* rbOr;
	Vcl::Stdctrls::TLabel* lblEdit1PlaceHolder;
	Vcl::Stdctrls::TLabel* lblEdit2PlaceHolder;
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall cbOperator1Click(System::TObject* Sender);
	void __fastcall cbOperator2PropertiesChange(System::TObject* Sender);
	
private:
	Cxfilter::TcxFilterCriteria* FCriteria;
	Vcl::Controls::TCaption FDisplayValue1;
	Vcl::Controls::TCaption FDisplayValue2;
	Cxedit::TcxCustomEdit* FEdit1;
	Cxedit::TcxCustomEdit* FEdit2;
	Cxedit::TcxCustomEditProperties* FEditProperties;
	Cxfiltercontrolutils::TcxCustomFilterEditHelperClass FFilterEditHelper;
	System::TObject* FItemLink;
	System::Variant FValue1;
	System::Variant FValue2;
	Cxdatastorage::TcxValueTypeClass FValueTypeClass;
	
protected:
	void __fastcall AddFilterItem(Cxfilter::TcxFilterCriteriaItemList* AParent, Cxdropdownedit::TcxComboBox* AComboBox, System::Variant &AValue, System::UnicodeString ADisplayValue);
	void __fastcall CheckWildcardDescriptionVisibility(void);
	virtual void __fastcall CreateParams(Vcl::Controls::TCreateParams &Params);
	void __fastcall GetFilterValues(Cxedit::TcxCustomEdit* AEdit, System::Variant &AValue, Vcl::Controls::TCaption &ADisplayValue);
	virtual Cxdropdownedit::TcxComboBox* __fastcall GetOperatorComboBox(Cxedit::TcxCustomEdit* AEdit);
	virtual Cxfiltercontrolutils::TcxFilterControlOperators __fastcall GetSupportedOperators(void);
	virtual void __fastcall InitControls(const System::UnicodeString ACriteriaItemCaption);
	virtual void __fastcall InitControlValues(void);
	void __fastcall InitEdits(Cxdropdownedit::TcxComboBox* AComboBox, Cxedit::TcxCustomEdit* AEdit, Cxfilter::TcxFilterCriteriaItem* AItem);
	virtual void __fastcall InitLookAndFeel(Cxlookandfeels::TcxLookAndFeel* ALookAndFeel);
	void __fastcall SetEditValidChars(Cxedit::TcxCustomEdit* AEdit);
	void __fastcall ValidateValue(Cxedit::TcxCustomEdit* AEdit, System::Variant &AValue);
	__property Vcl::Controls::TCaption DisplayValue1 = {read=FDisplayValue1};
	__property Vcl::Controls::TCaption DisplayValue2 = {read=FDisplayValue2};
	__property Cxedit::TcxCustomEdit* Edit1 = {read=FEdit1};
	__property Cxedit::TcxCustomEdit* Edit2 = {read=FEdit2};
	__property Cxfiltercontrolutils::TcxCustomFilterEditHelperClass FilterEditHelper = {read=FFilterEditHelper};
	__property Cxfiltercontrolutils::TcxFilterControlOperators SupportedOperators = {read=GetSupportedOperators};
	__property System::Variant Value1 = {read=FValue1};
	__property System::Variant Value2 = {read=FValue2};
	
public:
	__fastcall virtual TcxFilterDialog(Cxfilter::TcxFilterCriteria* ACriteria, System::TObject* AItemLink, Cxedit::TcxCustomEditProperties* AEditProperties, const System::UnicodeString ACriteriaItemCaption, Cxdatastorage::TcxValueTypeClass AValueTypeClass, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel, Vcl::Graphics::TFont* AFont);
	virtual void __fastcall ApplyChanges(void);
	__classmethod Cxfiltercontrolutils::TcxCustomFilterEditHelperClass __fastcall GetFilterEditHelper(Cxedit::TcxCustomEditProperties* AEditProperties);
	__property Cxfilter::TcxFilterCriteria* Criteria = {read=FCriteria};
	__property Cxedit::TcxCustomEditProperties* EditProperties = {read=FEditProperties};
	__property System::TObject* ItemLink = {read=FItemLink};
	__property Cxdatastorage::TcxValueTypeClass ValueTypeClass = {read=FValueTypeClass};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxFilterDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxFilterDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxFilterDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxFilterDialogClass cxFilterDialogClass;
extern PACKAGE bool __fastcall IsFilterControlDialogNeeded(Cxfilter::TcxFilterCriteria* ACriteria);
extern PACKAGE bool __fastcall ShowFilterDialog(Cxfilter::TcxFilterCriteria* ACriteria, System::TObject* AItemLink, Cxedit::TcxCustomEditProperties* AEditProperties, const System::UnicodeString ACriteriaItemCaption, Cxdatastorage::TcxValueTypeClass AValueTypeClass, Cxlookandfeels::TcxLookAndFeel* ALookAndFeel = (Cxlookandfeels::TcxLookAndFeel*)(0x0), Vcl::Graphics::TFont* AFont = (Vcl::Graphics::TFont*)(0x0));
}	/* namespace Cxfilterdialog */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXFILTERDIALOG)
using namespace Cxfilterdialog;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxfilterdialogHPP
