// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmLnkAdd.pas' rev: 24.00 (Win64)

#ifndef DxpsfmlnkaddHPP
#define DxpsfmlnkaddHPP

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
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPSCompsProvider.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmlnkadd
{
//-- type declarations -------------------------------------------------------
enum TSortOrder : unsigned char { soNone, soUp, soDown };

enum TdxAddReportLinkDlgDataOption : unsigned char { adoShowDesignButton, adoShowDescriptionColumn, adoShowOnlyComponentsWOLinks, adoShowOnlyComponentsInActiveForm, adoAllowMultiSelect, adoShowNameEdit, adoShowCaptionEdit, adoShowHideCustomContainers, adoShowCreatorEdit };

typedef System::Set<TdxAddReportLinkDlgDataOption, TdxAddReportLinkDlgDataOption::adoShowDesignButton, TdxAddReportLinkDlgDataOption::adoShowCreatorEdit>  TdxAddReportLinkDlgDataOptions;

class DELPHICLASS TdxfmAddComponent;
class PASCALIMPLEMENTATION TdxfmAddComponent : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Vcl::Menus::TPopupMenu* pmItems;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Menus::TMenuItem* miDesign;
	Vcl::Extctrls::TPanel* pnlHost;
	Vcl::Controls::TImageList* ilColumns;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnDesign;
	Cxpc::TcxPageControl* pgctrlItems;
	Cxpc::TcxTabSheet* tbsItems;
	Cxlabel::TcxLabel* pnlNoItems;
	Cxlistview::TcxListView* lvItems;
	Cxlabel::TcxLabel* bvlSeparator;
	Cxgroupbox::TcxGroupBox* pnlBottomHost;
	Vcl::Extctrls::TBevel* bvlOnlyUnLinked;
	Vcl::Extctrls::TBevel* bvlHideCustomContainers;
	Vcl::Extctrls::TBevel* bvlOnlyInCurrentModule;
	Cxcheckbox::TcxCheckBox* chbxOnlyUnLinked;
	Cxcheckbox::TcxCheckBox* chbxOnlyInCurrentModule;
	Cxcheckbox::TcxCheckBox* chbxHideCustomContainers;
	Vcl::Extctrls::TPanel* pnlNameHost;
	Cxlabel::TcxLabel* lblName;
	Cxtextedit::TcxTextEdit* edName;
	Vcl::Extctrls::TPanel* pnlCreatorHost;
	Cxlabel::TcxLabel* lblCreator;
	Cxbuttons::TcxButton* btnDescription;
	Cxtextedit::TcxTextEdit* edCreator;
	Vcl::Extctrls::TPanel* pnlCaptionHost;
	Cxlabel::TcxLabel* lblCaption;
	Cxtextedit::TcxTextEdit* edCaption;
	Cxgraphics::TcxImageList* ilItems;
	void __fastcall chbxClick(System::TObject* Sender);
	void __fastcall btnDesignClick(System::TObject* Sender);
	void __fastcall lvItemsDblClick(System::TObject* Sender);
	void __fastcall pmItemsPopup(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall lvItemsChange(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemChange Change);
	void __fastcall btnDescriptionClick(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall lvItemsColumnClick(System::TObject* Sender, Vcl::Comctrls::TListColumn* Column);
	void __fastcall lvItemsCompare(System::TObject* Sender, Vcl::Comctrls::TListItem* Item1, Vcl::Comctrls::TListItem* Item2, int Data, int &Compare);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	Dxpscore::TdxComponentPrinter* FComponentPrinter;
	bool FDesignBtnPressed;
	TdxAddReportLinkDlgDataOptions FOptions;
	System::UnicodeString FOriginalReportLinkName;
	Dxpscore::TBasedxReportLink* FReportLink;
	System::Classes::TWndMethod FPrevListViewWndProc;
	System::UnicodeString FReportLinkDescription;
	int FSortedColumnIndex;
	TSortOrder FSortOrder;
	int __fastcall GetItemCount(void);
	HWND __fastcall GetListViewHeader(void);
	System::UnicodeString __fastcall GetReportLinkCaption(void);
	System::UnicodeString __fastcall GetReportLinkCreator(void);
	System::UnicodeString __fastcall GetReportLinkName(void);
	System::Classes::TComponent* __fastcall GetSelectedComponent(void);
	void __fastcall GetSelection(System::Classes::TList* AList);
	void __fastcall SetReportLinkCaption(const System::UnicodeString Value);
	void __fastcall SetReportLinkCreator(const System::UnicodeString Value);
	void __fastcall SetReportLinkName(const System::UnicodeString Value);
	void __fastcall AssignListViewHeaderImages(void);
	void __fastcall ListViewWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall RestoreListViewWndProc(void);
	void __fastcall SubstituteListViewWndProc(void);
	bool __fastcall CanEditName(void);
	bool __fastcall CanDesign(void);
	bool __fastcall CanSelect(void);
	bool __fastcall CheckUserInput(void);
	void __fastcall ClearList(void);
	void __fastcall Initialize(void);
	void __fastcall LoadStrings(void);
	Dxpscompsprovider::TdxPSGetComponentOptions __fastcall PreparedOptions(void);
	void __fastcall RefreshColumns(void);
	void __fastcall RefreshList(void);
	void __fastcall RefreshSorting(void);
	HIDESBASE void __fastcall SetActiveControl(void);
	void __fastcall SetColumnSortMark(int AIndex, TSortOrder ASortOrder);
	void __fastcall SortColumn(Vcl::Comctrls::TListColumn* Column, TSortOrder ASortOrder);
	void __fastcall UpdateControlsState(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall BeforeConstruction(void);
	void __fastcall LoadComponentState(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall LoadListViewSorting(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SaveComponentState(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SaveListViewSorting(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property HWND ListViewHeader = {read=GetListViewHeader};
	
public:
	bool __fastcall Execute(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property System::UnicodeString OriginalReportLinkName = {read=FOriginalReportLinkName, write=FOriginalReportLinkName};
	__property System::UnicodeString ReportLinkCaption = {read=GetReportLinkCaption, write=SetReportLinkCaption};
	__property System::UnicodeString ReportLinkCreator = {read=GetReportLinkCreator, write=SetReportLinkCreator};
	__property System::UnicodeString ReportLinkDescription = {read=FReportLinkDescription, write=FReportLinkDescription};
	__property System::UnicodeString ReportLinkName = {read=GetReportLinkName, write=SetReportLinkName};
	__property System::Classes::TComponent* SelectedComponent = {read=GetSelectedComponent};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxfmAddComponent(System::Classes::TComponent* AOwner) : Dxpsform::TCustomdxPSForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmAddComponent(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxfmAddComponent(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmAddComponent(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


struct TdxAddReportLinkDlgData;
typedef TdxAddReportLinkDlgData *PdxAddReportLinkDlgData;

struct DECLSPEC_DRECORD TdxAddReportLinkDlgData
{
public:
	System::Classes::TList* Components;
	Dxpscore::TdxComponentPrinter* ComponentPrinter;
	Dxpscore::TBasedxReportLink* ReportLink;
	System::UnicodeString ReportLinkName;
	System::UnicodeString ReportLinkCaption;
	System::UnicodeString ReportLinkCreator;
	System::UnicodeString ReportLinkDescription;
	TdxAddReportLinkDlgDataOptions Options;
	bool DesignBtnPressed;
	System::UnicodeString Title;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowAddComponentsDlg(TdxAddReportLinkDlgData &AData);
}	/* namespace Dxpsfmlnkadd */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMLNKADD)
using namespace Dxpsfmlnkadd;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmlnkaddHPP
