// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxBandedTableViewEditor.pas' rev: 24.00 (Win32)

#ifndef CxbandedtablevieweditorHPP
#define CxbandedtablevieweditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridBandedTableView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <cxViewEditor.hpp>	// Pascal unit
#include <cxCustomTableViewEditor.hpp>	// Pascal unit
#include <cxTableViewEditor.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxbandedtablevieweditor
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxBandedTableViewEditor;
class PASCALIMPLEMENTATION TcxBandedTableViewEditor : public Cxtablevieweditor::TcxTableViewEditor
{
	typedef Cxtablevieweditor::TcxTableViewEditor inherited;
	
__published:
	Cxpc::TcxTabSheet* TSBands;
	Vcl::Stdctrls::TListBox* LBBands;
	Vcl::Extctrls::TPanel* Panel22;
	Cxbuttons::TcxButton* BAddBand;
	Cxbuttons::TcxButton* BDeleteBand;
	Vcl::Menus::TPopupMenu* PMBands;
	Vcl::Menus::TMenuItem* MIBandsAdd;
	Vcl::Menus::TMenuItem* MIBandsDelete;
	Vcl::Menus::TMenuItem* MenuItem4;
	Vcl::Menus::TMenuItem* MIBandsMoveUp;
	Vcl::Menus::TMenuItem* MenuItem7;
	Vcl::Menus::TMenuItem* MIBandsSelectAll;
	Vcl::Menus::TMenuItem* MIBandsMoveDown;
	Cxbuttons::TcxButton* BBandMoveDown;
	Cxbuttons::TcxButton* BBandMoveUp;
	Vcl::Extctrls::TPanel* Panel20;
	void __fastcall BAddBandClick(System::TObject* Sender);
	void __fastcall BDeleteBandClick(System::TObject* Sender);
	void __fastcall LBBandsClick(System::TObject* Sender);
	void __fastcall LBBandsStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall LBBandsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall LBBandsEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall LBBandsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall BBandMoveUpClick(System::TObject* Sender);
	void __fastcall BBandMoveDownClick(System::TObject* Sender);
	void __fastcall MIBandsSelectAllClick(System::TObject* Sender);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall LBBandsDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	HIDESBASE void __fastcall LBColumnsDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	
private:
	int FBandsPrevDragIndex;
	Cxgridbandedtableview::TcxGridBands* __fastcall GetBands(void);
	void __fastcall ReindexBandsProc(System::Classes::TList* AList, int ANewIndex);
	void __fastcall UpdateBandList(void);
	
protected:
	HIDESBASE void __fastcall DrawListBoxItem(Vcl::Controls::TWinControl* AListBox, int AIndex, const System::Types::TRect &R, Cxgridbandedtableview::TcxGridBand* AParentBand);
	void __fastcall SelectAllBands(void);
	virtual void __fastcall UpdateButtons(void);
	virtual void __fastcall UpdateEditor(void);
	virtual void __fastcall UpdateSelection(void);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetViewByObject(System::Classes::TPersistent* APersistent);
	__property Cxgridbandedtableview::TcxGridBands* Bands = {read=GetBands};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxBandedTableViewEditor(System::Classes::TComponent* AOwner) : Cxtablevieweditor::TcxTableViewEditor(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxBandedTableViewEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxtablevieweditor::TcxTableViewEditor(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxBandedTableViewEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxBandedTableViewEditor(HWND ParentWindow) : Cxtablevieweditor::TcxTableViewEditor(ParentWindow) { }
	
};


class DELPHICLASS TcxGridBandedTableViewStorage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTableViewStorage : public Cxcustomtablevieweditor::TcxCustomGridTableViewStorage
{
	typedef Cxcustomtablevieweditor::TcxCustomGridTableViewStorage inherited;
	
private:
	Cxgridbandedtableview::TcxGridBandedTableOptionsCustomize* __fastcall GetOptionsCustomize(void);
	Cxgridbandedtableview::TcxGridBandedTableOptionsView* __fastcall GetOptionsView(void);
	
protected:
	Cxgridbandedtableview::TcxGridBandedTableView* __fastcall BandedTableView(void);
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
	
__published:
	__property Cxgridbandedtableview::TcxGridBandedTableOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize};
	__property Cxgridbandedtableview::TcxGridBandedTableOptionsView* OptionsView = {read=GetOptionsView};
public:
	/* TcxCustomGridViewStorage.Create */ inline __fastcall virtual TcxGridBandedTableViewStorage(Cxgridcustomview::TcxCustomGridView* AView) : Cxcustomtablevieweditor::TcxCustomGridTableViewStorage(AView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridBandedTableViewStorage(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridBandedTableViewMenuProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridBandedTableViewMenuProvider : public Cxcustomtablevieweditor::TcxCustomGridTableViewMenuProvider
{
	typedef Cxcustomtablevieweditor::TcxCustomGridTableViewMenuProvider inherited;
	
private:
	HIDESBASE Cxgridbandedtableview::TcxGridBandedTableView* __fastcall GetGridView(void);
	
protected:
	void __fastcall CreateBand(Cxvieweditor::TcxGridViewMenuItem* Sender);
	virtual void __fastcall InitStructureCreationItems(void);
	
public:
	__property Cxgridbandedtableview::TcxGridBandedTableView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridViewMenuProvider.Create */ inline __fastcall virtual TcxGridBandedTableViewMenuProvider(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxcustomtablevieweditor::TcxCustomGridTableViewMenuProvider(AGridView) { }
	/* TcxCustomGridViewMenuProvider.Destroy */ inline __fastcall virtual ~TcxGridBandedTableViewMenuProvider(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxbandedtablevieweditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXBANDEDTABLEVIEWEDITOR)
using namespace Cxbandedtablevieweditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxbandedtablevieweditorHPP
