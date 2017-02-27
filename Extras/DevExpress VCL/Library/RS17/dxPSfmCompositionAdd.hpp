// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxPSfmCompositionAdd.pas' rev: 24.00 (Win32)

#ifndef DxpsfmcompositionaddHPP
#define DxpsfmcompositionaddHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Winapi.Messages.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <dxPSForm.hpp>	// Pascal unit
#include <dxPSCore.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxListView.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <System.IniFiles.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxpsfmcompositionadd
{
//-- type declarations -------------------------------------------------------
enum TdxCompositionAddItemsDlgOption : unsigned char { caiShowDescription };

typedef System::Set<TdxCompositionAddItemsDlgOption, TdxCompositionAddItemsDlgOption::caiShowDescription, TdxCompositionAddItemsDlgOption::caiShowDescription>  TdxCompositionAddItemsDlgOptions;

class DELPHICLASS TdxfmCompositionAddItems;
class PASCALIMPLEMENTATION TdxfmCompositionAddItems : public Dxpsform::TCustomdxPSForm
{
	typedef Dxpsform::TCustomdxPSForm inherited;
	
__published:
	Cxbuttons::TcxButton* btnOK;
	Cxbuttons::TcxButton* btnCancel;
	Cxbuttons::TcxButton* btnHelp;
	Cxpc::TcxPageControl* pgctrlItems;
	Cxpc::TcxTabSheet* tshItems;
	Cxcheckbox::TcxCheckBox* chbxHideIncludedItems;
	Cxlistview::TcxListView* lvItems;
	Cxlabel::TcxLabel* pnlNoItems;
	Cxgroupbox::TcxGroupBox* gpOptions;
	void __fastcall chbxHideIncludedItemsClick(System::TObject* Sender);
	void __fastcall lvItemsDblClick(System::TObject* Sender);
	void __fastcall FormResize(System::TObject* Sender);
	
private:
	Dxpscore::TdxCompositionReportLink* FComposition;
	TdxCompositionAddItemsDlgOptions FOptions;
	bool FNoItemsState;
	bool FSavedHideIncludedItems;
	Dxpscore::TBasedxReportLink* __fastcall GetActiveItem(void);
	Dxpscore::TBasedxReportLink* __fastcall GetItem(int Index);
	int __fastcall GetItemCount(void);
	bool __fastcall GetSelected(int Index);
	int __fastcall GetSelectedCount(void);
	void __fastcall SetSelected(int Index, bool Value);
	void __fastcall GetSelection(System::Classes::TList* AList);
	void __fastcall Initialize(void);
	void __fastcall LoadStrings(void);
	void __fastcall RefreshColumns(void);
	void __fastcall RefreshList(void);
	void __fastcall UpdateNoItems(void);
	HIDESBASE MESSAGE void __fastcall CMDialogChar(Winapi::Messages::TWMKey &Msg);
	
protected:
	virtual void __fastcall BeforeConstruction(void);
	
public:
	__fastcall virtual TdxfmCompositionAddItems(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxfmCompositionAddItems(void);
	bool __fastcall Execute(void);
	virtual void __fastcall LoadFromIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	virtual void __fastcall SaveToIniFile(System::Inifiles::TCustomIniFile* AIniFile, const System::UnicodeString ASectionName);
	__property Dxpscore::TBasedxReportLink* ActiveItem = {read=GetActiveItem};
	__property Dxpscore::TdxCompositionReportLink* Composition = {read=FComposition, write=FComposition};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property Dxpscore::TBasedxReportLink* Items[int Index] = {read=GetItem};
	__property bool Selected[int Index] = {read=GetSelected, write=SetSelected};
	__property int SelectedCount = {read=GetSelectedCount, nodefault};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxfmCompositionAddItems(System::Classes::TComponent* AOwner, int Dummy) : Dxpsform::TCustomdxPSForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxfmCompositionAddItems(HWND ParentWindow) : Dxpsform::TCustomdxPSForm(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TdxAddItemsToCompositionDlgData
{
public:
	Dxpscore::TdxCompositionReportLink* Composition;
	System::Classes::TList* Items;
	TdxCompositionAddItemsDlgOptions Options;
};


typedef TdxAddItemsToCompositionDlgData *PdxAddItemsToCompositionDlgData;

//-- var, const, procedure ---------------------------------------------------
extern PACKAGE bool __fastcall dxShowAddItemsToCompositionDlg(TdxAddItemsToCompositionDlgData &AData);
}	/* namespace Dxpsfmcompositionadd */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXPSFMCOMPOSITIONADD)
using namespace Dxpsfmcompositionadd;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxpsfmcompositionaddHPP
