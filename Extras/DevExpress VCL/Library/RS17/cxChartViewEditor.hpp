// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxChartViewEditor.pas' rev: 24.00 (Win32)

#ifndef CxchartvieweditorHPP
#define CxchartvieweditorHPP

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
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxViewEditor.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridChartView.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxchartvieweditor
{
//-- type declarations -------------------------------------------------------
enum TcxGridChartItemKind : unsigned char { ciSeries, ciDataGroup };

typedef System::StaticArray<int, 2> TcxGridChartItemListBoxParams;

class DELPHICLASS TcxChartViewEditor;
class PASCALIMPLEMENTATION TcxChartViewEditor : public Cxvieweditor::TcxViewEditor
{
	typedef Cxvieweditor::TcxViewEditor inherited;
	
__published:
	Vcl::Menus::TPopupMenu* pmItems;
	Vcl::Menus::TMenuItem* miItemAdd;
	Vcl::Menus::TMenuItem* miItemDelete;
	Vcl::Menus::TMenuItem* N2;
	Vcl::Menus::TMenuItem* miItemMoveUp;
	Vcl::Menus::TMenuItem* miItemMoveDown;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* miItemSelectAll;
	Vcl::Menus::TPopupMenu* pmItemsAdd;
	Cxpc::TcxTabControl* tcMain;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Stdctrls::TListBox* lbItems;
	Vcl::Extctrls::TPanel* Panel2;
	Cxbuttons::TcxButton* btnItemAdd;
	Cxbuttons::TcxButton* btnItemDelete;
	Cxbuttons::TcxButton* btnItemMoveUp;
	Cxbuttons::TcxButton* btnItemMoveDown;
	Cxbuttons::TcxButton* btnItemSelectAll;
	Vcl::Extctrls::TPanel* Panel9;
	void __fastcall tcMainChanging(System::TObject* Sender, bool &AllowChange);
	void __fastcall tcMainChange(System::TObject* Sender);
	void __fastcall lbItemsClick(System::TObject* Sender);
	void __fastcall btnItemAddClick(System::TObject* Sender);
	void __fastcall btnItemAddExClick(System::TObject* Sender);
	void __fastcall miItemAddExClick(System::TObject* Sender);
	void __fastcall btnItemDeleteClick(System::TObject* Sender);
	void __fastcall btnItemMoveUpClick(System::TObject* Sender);
	void __fastcall btnItemMoveDownClick(System::TObject* Sender);
	void __fastcall btnItemSelectAllClick(System::TObject* Sender);
	void __fastcall lbItemsStartDrag(System::TObject* Sender, Vcl::Controls::TDragObject* &DragObject);
	void __fastcall lbItemsDragOver(System::TObject* Sender, System::TObject* Source, int X, int Y, System::Uitypes::TDragState State, bool &Accept);
	void __fastcall lbItemsDragDrop(System::TObject* Sender, System::TObject* Source, int X, int Y);
	void __fastcall lbItemsEndDrag(System::TObject* Sender, System::TObject* Target, int X, int Y);
	void __fastcall lbItemsDrawItem(Vcl::Controls::TWinControl* Control, int Index, const System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall FormCreate(System::TObject* Sender);
	
private:
	int FItemPrevDragIndex;
	TcxGridChartItemListBoxParams FListBoxItemIndex;
	TcxGridChartItemListBoxParams FListBoxTopIndex;
	Cxgridchartview::TcxGridChartItemClass __fastcall GetItemClassValue(void);
	Cxgridchartview::TcxGridChartView* __fastcall GetView(void);
	void __fastcall ReindexItemsProc(System::Classes::TList* AList, int ANewIndex);
	
protected:
	bool IsActiveTabChanging;
	virtual void __fastcall Loaded(void);
	virtual Cxgridchartview::TcxGridChartItem* __fastcall GetItem(int Index);
	virtual Cxgridchartview::TcxGridChartItemClass __fastcall GetItemClass(TcxGridChartItemKind AItemKind);
	virtual int __fastcall GetItemCount(void);
	virtual TcxGridChartItemKind __fastcall GetItemKind(void);
	virtual System::UnicodeString __fastcall GetItemName(void);
	virtual void __fastcall SetItemKind(TcxGridChartItemKind Value);
	Cxgridchartview::TcxGridChartItem* __fastcall AddItem(void);
	virtual void __fastcall UpdateActiveTab(void);
	virtual void __fastcall UpdateButtons(void);
	virtual void __fastcall UpdateEditor(void);
	virtual void __fastcall UpdateSelection(void);
	virtual void __fastcall UpdateItemList(void);
	void __fastcall RestoreListBoxParams(void);
	void __fastcall SaveListBoxParams(void);
	__property Cxgridchartview::TcxGridChartItemClass ItemClass = {read=GetItemClassValue};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TcxGridChartItemKind ItemKind = {read=GetItemKind, write=SetItemKind, nodefault};
	__property System::UnicodeString ItemName = {read=GetItemName};
	__property Cxgridchartview::TcxGridChartItem* Items[int Index] = {read=GetItem};
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridView* __fastcall GetViewByObject(System::Classes::TPersistent* APersistent);
	__property Cxgridchartview::TcxGridChartView* View = {read=GetView};
public:
	/* TCustomForm.Create */ inline __fastcall virtual TcxChartViewEditor(System::Classes::TComponent* AOwner) : Cxvieweditor::TcxViewEditor(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxChartViewEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxvieweditor::TcxViewEditor(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TcxChartViewEditor(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxChartViewEditor(HWND ParentWindow) : Cxvieweditor::TcxViewEditor(ParentWindow) { }
	
};


class DELPHICLASS TcxGridChartViewStorage;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartViewStorage : public Cxvieweditor::TcxCustomGridViewStorage
{
	typedef Cxvieweditor::TcxCustomGridViewStorage inherited;
	
private:
	Cxgridchartview::TcxGridChartAreaDiagram* __fastcall GetDiagramArea(void);
	Cxgridchartview::TcxGridChartBarDiagram* __fastcall GetDiagramBar(void);
	Cxgridchartview::TcxGridChartColumnDiagram* __fastcall GetDiagramColumn(void);
	Cxgridchartview::TcxGridChartLineDiagram* __fastcall GetDiagramLine(void);
	Cxgridchartview::TcxGridChartPieDiagram* __fastcall GetDiagramPie(void);
	Cxgridchartview::TcxGridChartLegend* __fastcall GetLegend(void);
	Cxgridchartview::TcxGridChartOptionsBehavior* __fastcall GetOptionsBehavior(void);
	Cxgridchartview::TcxGridChartOptionsCustomize* __fastcall GetOptionsCustomize(void);
	Cxgridchartview::TcxGridChartOptionsView* __fastcall GetOptionsView(void);
	Cxgridchartview::TcxGridChartTitle* __fastcall GetTitle(void);
	Cxgridchartview::TcxGridChartToolBox* __fastcall GetToolBox(void);
	Cxgridchartview::TcxGridChartView* __fastcall GetView(void);
	
protected:
	__property Cxgridchartview::TcxGridChartView* View = {read=GetView};
	
public:
	__classmethod virtual Cxgridcustomview::TcxCustomGridViewClass __fastcall GetViewClass();
	
__published:
	__property Cxgridchartview::TcxGridChartAreaDiagram* DiagramArea = {read=GetDiagramArea};
	__property Cxgridchartview::TcxGridChartBarDiagram* DiagramBar = {read=GetDiagramBar};
	__property Cxgridchartview::TcxGridChartColumnDiagram* DiagramColumn = {read=GetDiagramColumn};
	__property Cxgridchartview::TcxGridChartLineDiagram* DiagramLine = {read=GetDiagramLine};
	__property Cxgridchartview::TcxGridChartPieDiagram* DiagramPie = {read=GetDiagramPie};
	__property Cxgridchartview::TcxGridChartLegend* Legend = {read=GetLegend};
	__property Cxgridchartview::TcxGridChartOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior};
	__property Cxgridchartview::TcxGridChartOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize};
	__property Cxgridchartview::TcxGridChartOptionsView* OptionsView = {read=GetOptionsView};
	__property Cxgridchartview::TcxGridChartTitle* Title = {read=GetTitle};
	__property Cxgridchartview::TcxGridChartToolBox* ToolBox = {read=GetToolBox};
public:
	/* TcxCustomGridViewStorage.Create */ inline __fastcall virtual TcxGridChartViewStorage(Cxgridcustomview::TcxCustomGridView* AView) : Cxvieweditor::TcxCustomGridViewStorage(AView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridChartViewStorage(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridChartViewMenuProvider;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridChartViewMenuProvider : public Cxvieweditor::TcxCustomGridViewMenuProvider
{
	typedef Cxvieweditor::TcxCustomGridViewMenuProvider inherited;
	
private:
	Cxgridchartview::TcxGridChartView* __fastcall GetGridView(void);
	
protected:
	void __fastcall ActivateDiagram(Cxvieweditor::TcxGridViewMenuItem* Sender);
	void __fastcall CreateDataGroup(Cxvieweditor::TcxGridViewMenuItem* Sender);
	void __fastcall CreateSeries(Cxvieweditor::TcxGridViewMenuItem* Sender);
	virtual void __fastcall InitLayoutItems(void);
	virtual void __fastcall InitStructureItems(void);
	
public:
	__property Cxgridchartview::TcxGridChartView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridViewMenuProvider.Create */ inline __fastcall virtual TcxGridChartViewMenuProvider(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxvieweditor::TcxCustomGridViewMenuProvider(AGridView) { }
	/* TcxCustomGridViewMenuProvider.Destroy */ inline __fastcall virtual ~TcxGridChartViewMenuProvider(void) { }
	
};

#pragma pack(pop)

//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxchartvieweditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXCHARTVIEWEDITOR)
using namespace Cxchartvieweditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxchartvieweditorHPP
