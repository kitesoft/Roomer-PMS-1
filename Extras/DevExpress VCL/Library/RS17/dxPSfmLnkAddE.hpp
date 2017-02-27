// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmLnkAddE.pas' rev: 24.00 (Win32)

#ifndef DxpsfmlnkaddeHPP
#define DxpsfmlnkaddeHPP

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
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <System.Win.Registry.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmlnkadde
{
//-- type declarations -------------------------------------------------------
enum TSortOrder : unsigned char { soNone, soUp, soDown };

class DELPHICLASS TdxfmAddReportLinkClass;
class PASCALIMPLEMENTATION TdxfmAddReportLinkClass : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Vcl::Menus::TPopupMenu* pmLinks;
	Vcl::Menus::TMenuItem* miSelect;
	Vcl::Menus::TMenuItem* miDesign;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Controls::TImageList* ilColumns;
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxbuttons::TcxButton* btnDesign;
	Cxgroupbox::TcxGroupBox* pnlHost;
	Cxgroupbox::TcxGroupBox* pnlNameHost;
	Cxtextedit::TcxTextEdit* edName;
	Cxlabel::TcxLabel* lblName;
	Cxgroupbox::TcxGroupBox* pnlCaptionHost;
	Cxtextedit::TcxTextEdit* edCaption;
	Cxlabel::TcxLabel* lblCaption;
	Cxgroupbox::TcxGroupBox* pnlCreatorHost;
	Cxbuttons::TcxButton* btnDescription;
	Cxtextedit::TcxTextEdit* edCreator;
	Cxlabel::TcxLabel* lblCreator;
	Cxlabel::TcxLabel* bvlSeparator;
	Cxpc::TcxPageControl* pgctrlItems;
	Cxpc::TcxTabSheet* tbsItems;
	Cxlistview::TcxListView* lvItems;
	Cxgraphics::TcxImageList* ilLinks;
	void __fastcall btnHelpClick(System::TObject* Sender);
	void __fastcall lvItemsDblClick(System::TObject* Sender);
	void __fastcall lvItemsColumnClick(System::TObject* Sender, Vcl::Comctrls::TListColumn* Column);
	void __fastcall lvItemsCompare(System::TObject* Sender, Vcl::Comctrls::TListItem* Item1, Vcl::Comctrls::TListItem* Item2, int Data, int &Compare);
	void __fastcall FormResize(System::TObject* Sender);
	void __fastcall btnDesignClick(System::TObject* Sender);
	void __fastcall pmLinksPopup(System::TObject* Sender);
	void __fastcall lvItemsChange(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemChange Change);
	void __fastcall btnDescriptionClick(System::TObject* Sender);
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall FormDestroy(System::TObject* Sender);
	
private:
	bool FDesignBtnPressed;
	System::Classes::TWndMethod FPrevListViewWndProc;
	System::UnicodeString FReportLinkDescription;
	int FSortedColumnIndex;
	TSortOrder FSortOrder;
	HWND __fastcall GetListViewHeader(void);
	System::UnicodeString __fastcall GetReportLinkCaption(void);
	System::UnicodeString __fastcall GetReportLinkCreator(void);
	System::UnicodeString __fastcall GetReportLinkName(void);
	Dxpscore::TdxReportLinkClass __fastcall GetSelectedReportLinkClass(void);
	void __fastcall SetReportLinkCaption(const System::UnicodeString Value);
	void __fastcall SetReportLinkCreator(System::UnicodeString Value);
	void __fastcall SetReportLinkName(const System::UnicodeString Value);
	bool __fastcall CanEditCaption(void);
	bool __fastcall CanEditCreator(void);
	bool __fastcall CanEditDescription(void);
	bool __fastcall CanEditName(void);
	bool __fastcall CanDesign(void);
	bool __fastcall CanSelect(void);
	void __fastcall Initialize(void);
	void __fastcall RefreshList(void);
	HIDESBASE void __fastcall SetActiveControl(void);
	void __fastcall SetColumnSortMark(int AIndex, TSortOrder ASortOrder);
	void __fastcall SortColumn(Vcl::Comctrls::TListColumn* Column, TSortOrder ASortOrder);
	void __fastcall RefreshSorting(void);
	void __fastcall UpdateControlsState(void);
	void __fastcall AssignListViewHeaderImages(void);
	void __fastcall ListViewWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall RestoreListViewWndProc(void);
	void __fastcall SubstituteListViewWndProc(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Message);
	
protected:
	virtual void __fastcall CreateWnd(void);
	virtual void __fastcall BeforeConstruction(void);
	void __fastcall LoadSorting(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	void __fastcall SaveSorting(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property HWND ListViewHeader = {read=GetListViewHeader, nodefault};
	
public:
	bool __fastcall Execute(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property System::UnicodeString ReportLinkCaption = {read=GetReportLinkCaption, write=SetReportLinkCaption};
	__property System::UnicodeString ReportLinkCreator = {read=GetReportLinkCreator, write=SetReportLinkCreator};
	__property System::UnicodeString ReportLinkDescription = {read=FReportLinkDescription, write=FReportLinkDescription};
	__property System::UnicodeString ReportLinkName = {read=GetReportLinkName, write=SetReportLinkName};
	__property Dxpscore::TdxReportLinkClass SelectedReportLinkClass = {read=GetSelectedReportLinkClass};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxfmAddReportLinkClass(System::Classes::TComponent* AOwner) : Dxpsform::TCustomdxPSForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmAddReportLinkClass(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TdxfmAddReportLinkClass(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmAddReportLinkClass(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


struct TdxAddReportLinkClassDlgData;
typedef TdxAddReportLinkClassDlgData *PdxAddReportLinkClassDlgData;

struct DECLSPEC_DRECORD TdxAddReportLinkClassDlgData
{
public:
	Dxpscore::TdxReportLinkClass ReportLinkClass;
	System::UnicodeString ReportLinkName;
	System::UnicodeString ReportLinkCaption;
	System::UnicodeString ReportLinkCreator;
	System::UnicodeString ReportLinkDescription;
	bool DesignBtnPressed;
	System::Classes::THelpContext HelpContext;
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowAddReportLinkClassDlg(TdxAddReportLinkClassDlgData &AData);
}	/* namespace Dxpsfmlnkadde */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMLNKADDE)
using namespace Dxpsfmlnkadde;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmlnkaddeHPP
