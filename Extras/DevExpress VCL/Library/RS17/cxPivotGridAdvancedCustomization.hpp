// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxPivotGridAdvancedCustomization.pas' rev: 24.00 (Win32)

#ifndef CxpivotgridadvancedcustomizationHPP
#define CxpivotgridadvancedcustomizationHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <cxCustomPivotGrid.hpp>	// Pascal unit
#include <cxPivotGridCustomization.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxSplitter.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxpivotgridadvancedcustomization
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxPivotGridCustomizationFormLayoutChooser;
class DELPHICLASS TcxPivotGridAdvancedCustomizationForm;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomizationFormLayoutChooser : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TcxPivotGridAdvancedCustomizationForm* FFieldChooser;
	System::Classes::TComponent* FPopupMenu;
	
protected:
	virtual void __fastcall CreateItem(Vcl::Actnlist::TAction* Action) = 0 ;
	void __fastcall CreateItems(void);
	virtual System::Classes::TComponentClass __fastcall GetPopupMenuClass(void) = 0 ;
	virtual void __fastcall InitializePopupMenu(void);
	
public:
	__fastcall virtual TcxPivotGridCustomizationFormLayoutChooser(TcxPivotGridAdvancedCustomizationForm* AFieldChooser);
	__fastcall virtual ~TcxPivotGridCustomizationFormLayoutChooser(void);
	void __fastcall Popup(int X, int Y);
	__property TcxPivotGridAdvancedCustomizationForm* FieldChooser = {read=FFieldChooser};
	__property System::Classes::TComponent* PopupMenu = {read=FPopupMenu};
};

#pragma pack(pop)

typedef System::TMetaClass* TcxPivotGridCustomizationFormLayoutChooserClass;

class DELPHICLASS TcxPivotGridCustomizationFormStandardLayoutChooser;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxPivotGridCustomizationFormStandardLayoutChooser : public TcxPivotGridCustomizationFormLayoutChooser
{
	typedef TcxPivotGridCustomizationFormLayoutChooser inherited;
	
private:
	void __fastcall DrawItem(System::TObject* Sender, Vcl::Graphics::TCanvas* ACanvas, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState State);
	Vcl::Menus::TPopupMenu* __fastcall GetPopupMenu(void);
	
protected:
	virtual void __fastcall CreateItem(Vcl::Actnlist::TAction* Action);
	virtual System::Classes::TComponentClass __fastcall GetPopupMenuClass(void);
	virtual void __fastcall InitializePopupMenu(void);
	
public:
	__property Vcl::Menus::TPopupMenu* PopupMenu = {read=GetPopupMenu};
public:
	/* TcxPivotGridCustomizationFormLayoutChooser.Create */ inline __fastcall virtual TcxPivotGridCustomizationFormStandardLayoutChooser(TcxPivotGridAdvancedCustomizationForm* AFieldChooser) : TcxPivotGridCustomizationFormLayoutChooser(AFieldChooser) { }
	/* TcxPivotGridCustomizationFormLayoutChooser.Destroy */ inline __fastcall virtual ~TcxPivotGridCustomizationFormStandardLayoutChooser(void) { }
	
};

#pragma pack(pop)

enum TcxPivotGridCustomizationFormLayout : unsigned char { cflBottomPanelOnly1by4, cflBottomPanelOnly2by2, cflStackedDefault, cflStackedSideBySide, cflTopPanelOnly };

typedef System::Set<TcxPivotGridCustomizationFormLayout, TcxPivotGridCustomizationFormLayout::cflBottomPanelOnly1by4, TcxPivotGridCustomizationFormLayout::cflTopPanelOnly>  TcxPivotGridCustomizationFormLayouts;

class PASCALIMPLEMENTATION TcxPivotGridAdvancedCustomizationForm : public Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm
{
	typedef Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm inherited;
	
__published:
	Cxgroupbox::TcxGroupBox* gbTop;
	Cxgroupbox::TcxGroupBox* gbMainBottom;
	Cxgroupbox::TcxGroupBox* gbMainVisibleFields;
	Cxbuttons::TcxButton* btnLayoutMode;
	Cxbuttons::TcxButton* btnUpdate;
	Cxcheckbox::TcxCheckBox* cbDeferLayoutUpdate;
	Vcl::Stdctrls::TLabel* lbMain;
	Vcl::Stdctrls::TLabel* lbTopMain;
	Cxgroupbox::TcxGroupBox* gbFilterArea;
	Vcl::Extctrls::TImage* imgFilterArea;
	Vcl::Stdctrls::TLabel* lbFilterArea;
	Cxgroupbox::TcxGroupBox* gbRowArea;
	Vcl::Extctrls::TImage* imgRowArea;
	Vcl::Stdctrls::TLabel* lbRowArea;
	Cxgroupbox::TcxGroupBox* gbColumnArea;
	Vcl::Extctrls::TImage* imgColumnArea;
	Vcl::Stdctrls::TLabel* lbColumnArea;
	Cxgroupbox::TcxGroupBox* gbDataArea;
	Vcl::Extctrls::TImage* imgDataAdea;
	Vcl::Stdctrls::TLabel* lbDataArea;
	Cxgroupbox::TcxGroupBox* gbMainCenter;
	Cxgroupbox::TcxGroupBox* gbMain;
	Cxgroupbox::TcxGroupBox* gbFields;
	Cxsplitter::TcxSplitter* splBottom;
	Cxgraphics::TcxImageList* ilLayoutChooser;
	Vcl::Actnlist::TActionList* alLayoutChooser;
	Vcl::Actnlist::TAction* acBottomPanelOnly1by4;
	Vcl::Actnlist::TAction* acBottomPanelOnly2by2;
	Vcl::Actnlist::TAction* acStackedDefault;
	Vcl::Actnlist::TAction* acStackedSideBySide;
	Vcl::Actnlist::TAction* acTopPanelOnly;
	Cxsplitter::TcxSplitter* splRight;
	Vcl::Stdctrls::TLabel* lbEmpty;
	void __fastcall gbMainResize(System::TObject* Sender);
	void __fastcall LayoutChooserExecute(System::TObject* Sender);
	void __fastcall btnLayoutModeClick(System::TObject* Sender);
	void __fastcall cbDeferLayoutUpdateClick(System::TObject* Sender);
	void __fastcall btnUpdateClick(System::TObject* Sender);
	void __fastcall gbFieldsResize(System::TObject* Sender);
	
private:
	System::UnicodeString FMainCaption;
	Cxpivotgridcustomization::TcxFieldListListBox* FAvailableFieldList;
	Cxpivotgridcustomization::TcxFieldListListBox* FColumnAreaFieldList;
	Cxpivotgridcustomization::TcxFieldListListBox* FDataAreaFieldList;
	Cxpivotgridcustomization::TcxFieldListListBox* FFilterAreaFieldList;
	TcxPivotGridCustomizationFormLayouts FAllowedLayouts;
	TcxPivotGridCustomizationFormLayout FLayout;
	Cxpivotgridcustomization::TcxFieldListListBox* FRowAreaFieldList;
	TcxPivotGridCustomizationFormLayoutChooser* FLayoutChooser;
	int FMainFieldsHeight;
	int FMainFieldsWidth;
	void __fastcall AlignChildren(Cxgroupbox::TcxGroupBox* AGroup, int AColumnCount, int ARowCount);
	void __fastcall CalculateTabOrders(void);
	Cxpivotgridcustomization::TcxFieldListListBox* __fastcall CreateFieldListBox(Vcl::Controls::TWinControl* AParent, Cxcustompivotgrid::TcxPivotGridCustomizationFormFieldListType AFieldsType);
	void __fastcall ListBoxDblClick(System::TObject* Sender);
	void __fastcall SetAllowedLayouts(const TcxPivotGridCustomizationFormLayouts AValue);
	void __fastcall SetLayout(TcxPivotGridCustomizationFormLayout AValue);
	
protected:
	virtual bool __fastcall CanChangeFieldSortOrder(void);
	virtual bool __fastcall CanChangeFieldFilter(void);
	virtual void __fastcall DoCreateControls(void);
	virtual void __fastcall DoUpdateSelection(void);
	virtual System::TObject* __fastcall GetFieldListByType(Cxcustompivotgrid::TcxPivotGridCustomizationFormFieldListType AListType);
	virtual bool __fastcall GetImmediateUpdate(void);
	bool __fastcall HasDeferredLayoutChanges(void);
	virtual void __fastcall Init(void);
	virtual void __fastcall Localize(void);
	virtual void __fastcall LookAndFeelChanged(void);
	virtual void __fastcall SynchronizeFields(void);
	void __fastcall BottomPanelOnly1by4FormCalculator(void);
	void __fastcall BottomPanelOnly2by2FormCalculator(void);
	virtual void __fastcall SetIsLayoutChanged(bool AValue);
	void __fastcall StackedDefaultFormCalculator(void);
	void __fastcall StackedSideBySideFormCalculator(void);
	void __fastcall TopPanelOnlyFormCalculator(void);
	virtual void __fastcall UpdateButtonState(void);
	void __fastcall InternalDisableAlign(Vcl::Controls::TWinControl* AControl);
	void __fastcall InternalEnableAlign(Vcl::Controls::TWinControl* AControl);
	__property TcxPivotGridCustomizationFormLayoutChooser* LayoutChooser = {read=FLayoutChooser};
	virtual void __fastcall PopulateFieldLists(void);
	
public:
	__fastcall virtual TcxPivotGridAdvancedCustomizationForm(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxPivotGridAdvancedCustomizationForm(void);
	virtual void __fastcall CalculateFormLayout(void);
	virtual void __fastcall RefreshList(void);
	__property TcxPivotGridCustomizationFormLayouts AllowedLayouts = {read=FAllowedLayouts, write=SetAllowedLayouts, nodefault};
	__property Cxpivotgridcustomization::TcxFieldListListBox* AvailableFieldList = {read=FAvailableFieldList};
	__property TcxPivotGridCustomizationFormLayout Layout = {read=FLayout, write=SetLayout, nodefault};
	__property Cxpivotgridcustomization::TcxFieldListListBox* ColumnAreaFieldList = {read=FColumnAreaFieldList};
	__property Cxpivotgridcustomization::TcxFieldListListBox* DataAreaFieldList = {read=FDataAreaFieldList};
	__property Cxpivotgridcustomization::TcxFieldListListBox* FilterAreaFieldList = {read=FFilterAreaFieldList};
	__property Cxpivotgridcustomization::TcxFieldListListBox* RowAreaFieldList = {read=FRowAreaFieldList};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxPivotGridAdvancedCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxPivotGridAdvancedCustomizationForm(HWND ParentWindow) : Cxcustompivotgrid::TcxPivotGridCustomCustomizationForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE TcxPivotGridCustomizationFormLayoutChooserClass cxPivotGridCustomizationFormLayoutChooserClass;
}	/* namespace Cxpivotgridadvancedcustomization */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXPIVOTGRIDADVANCEDCUSTOMIZATION)
using namespace Cxpivotgridadvancedcustomization;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxpivotgridadvancedcustomizationHPP
