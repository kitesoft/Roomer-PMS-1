// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSCPDsg.pas' rev: 24.00 (Win32)

#ifndef DxpscpdsgHPP
#define DxpscpdsgHPP

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
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpscpdsg
{
//-- type declarations -------------------------------------------------------
enum TdxfmCPDesignerOption : unsigned char { doShowDescription };

typedef System::Set<TdxfmCPDesignerOption, TdxfmCPDesignerOption::doShowDescription, TdxfmCPDesignerOption::doShowDescription>  TdxfmCPDesignerOptions;

class DELPHICLASS TdxfmCPDesigner;
class PASCALIMPLEMENTATION TdxfmCPDesigner : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Vcl::Menus::TPopupMenu* pmItems;
	Vcl::Menus::TMenuItem* miDesign;
	Vcl::Menus::TMenuItem* miLine2;
	Vcl::Menus::TMenuItem* miAdd;
	Vcl::Menus::TMenuItem* miDelete;
	Cxlistview::TcxListView* lvItems;
	Vcl::Menus::TMenuItem* miPageSetup;
	Vcl::Menus::TMenuItem* miPrintPreview;
	Vcl::Menus::TMenuItem* miPrint;
	Vcl::Menus::TMenuItem* miLine1;
	Vcl::Menus::TMenuItem* miRename;
	Vcl::Menus::TMenuItem* miAddComposition;
	Cxbuttons::TcxButton* btnClose;
	Cxbuttons::TcxButton* btnHelp;
	Cxpc::TcxPageControl* pcItems;
	Cxpc::TcxTabSheet* tbsItems;
	Cxgroupbox::TcxGroupBox* pnlButtons;
	Cxbuttons::TcxButton* btnDesign;
	Cxbuttons::TcxButton* btnAdd;
	Cxbuttons::TcxButton* btnDelete;
	Cxbuttons::TcxButton* btnPageSetup;
	Cxbuttons::TcxButton* btnPrintPreview;
	Cxbuttons::TcxButton* btnPrint;
	Cxbuttons::TcxButton* btnAddComposition;
	Cxlabel::TcxLabel* pnlNoItems;
	Cxgraphics::TcxImageList* ilItems;
	void __fastcall lvItemsChange(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, Vcl::Comctrls::TItemChange Change);
	void __fastcall AddClick(System::TObject* Sender);
	void __fastcall AddCompositionClick(System::TObject* Sender);
	void __fastcall DeleteClick(System::TObject* Sender);
	void __fastcall pmItemsPopup(System::TObject* Sender);
	void __fastcall DesignClick(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall lvItemsEdited(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, System::UnicodeString &S);
	void __fastcall lvItemsEditing(System::TObject* Sender, Vcl::Comctrls::TListItem* Item, bool &AllowEdit);
	void __fastcall lvItemsDblClick(System::TObject* Sender);
	void __fastcall PageSetupClick(System::TObject* Sender);
	void __fastcall PrintPreviewClick(System::TObject* Sender);
	void __fastcall PrintClick(System::TObject* Sender);
	void __fastcall RenameClick(System::TObject* Sender);
	void __fastcall tbsItemsResize(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	
private:
	Dxpscore::TdxComponentPrinter* FComponentPrinter;
	bool FIsRefreshing;
	System::Classes::TWndMethod FListViewWndProc;
	TdxfmCPDesignerOptions FOptions;
	Dxpscore::TBasedxReportLink* __fastcall GetCurrentLink(void);
	Dxpscore::TBasedxReportLink* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	bool __fastcall GetSelected(int Index);
	int __fastcall GetSelectedCount(void);
	void __fastcall SetCurrentLink(Dxpscore::TBasedxReportLink* Value);
	void __fastcall SetSelected(int Index, bool Value);
	bool __fastcall CanAdd(void);
	bool __fastcall CanAddComposition(void);
	bool __fastcall CanDelete(void);
	bool __fastcall CanDesign(void);
	bool __fastcall CanPageSetup(void);
	bool __fastcall CanPrint(void);
	bool __fastcall CanPrintPreview(void);
	bool __fastcall CanRename(void);
	void __fastcall DeleteSelection(void);
	System::UnicodeString __fastcall GetSelectedItemsAsString(void);
	bool __fastcall HasOnlyBuiltInsAreInSelection(void);
	void __fastcall Initialize(void);
	void __fastcall LoadStrings(void);
	void __fastcall RefreshColumns(void);
	void __fastcall RefreshList(void);
	void __fastcall UpdateControlsState(void);
	void __fastcall ListViewWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall SubClassListView(void);
	void __fastcall UnsubClassListView(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Msg);
	HIDESBASE MESSAGE void __fastcall WMShowWindow(Winapi::Messages::TWMShowWindow &Message);
	
protected:
	virtual void __fastcall BeforeConstruction(void);
	
public:
	__fastcall virtual TdxfmCPDesigner(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmCPDesigner(void);
	void __fastcall Execute(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property Dxpscore::TdxComponentPrinter* ComponentPrinter = {read=FComponentPrinter, write=FComponentPrinter};
	__property Dxpscore::TBasedxReportLink* CurrentLink = {read=GetCurrentLink, write=SetCurrentLink};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property Dxpscore::TBasedxReportLink* Items[int Index] = {read=GetItem};
	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	__property int SelectedCount = {read=GetSelectedCount, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmCPDesigner(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmCPDesigner(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TdxCPDesignerDlgData
{
public:
	Dxpscore::TdxComponentPrinter* ComponentPrinter;
	TdxfmCPDesignerOptions Options;
};


typedef TdxCPDesignerDlgData *PdxCPDesignerDlgData;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall dxShowCPDesignerDlg(const TdxCPDesignerDlgData &AData);
}	/* namespace Dxpscpdsg */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSCPDSG)
using namespace Dxpscpdsg;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpscpdsgHPP
