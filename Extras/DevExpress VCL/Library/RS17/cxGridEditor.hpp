// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridEditor.pas' rev: 24.00 (Win32)

#ifndef CxgrideditorHPP
#define CxgrideditorHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit
#include <ComponentDesigner.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxGridStructureNavigator.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxViewEditor.hpp>	// Pascal unit
#include <cxGridViewLayoutEditor.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgrideditor
{
//-- type declarations -------------------------------------------------------
struct DECLSPEC_DRECORD TSelectionInfo
{
public:
	Cxgridlevel::TcxGridLevel* Level;
	Cxgridcustomview::TcxCustomGridView* View;
	bool MultiSelect;
};


class DELPHICLASS TcxGridEditor;
class PASCALIMPLEMENTATION TcxGridEditor : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel3;
	Cxbuttons::TcxButton* BClose;
	Vcl::Extctrls::TPanel* Panel4;
	Vcl::Extctrls::TPanel* PLeft;
	Vcl::Extctrls::TSplitter* Splitter1;
	Vcl::Extctrls::TPanel* Panel7;
	Vcl::Extctrls::TPanel* Panel8;
	Vcl::Menus::TPopupMenu* PMGridStructureControl;
	Vcl::Menus::TPopupMenu* PMViews;
	Vcl::Extctrls::TPanel* Panel11;
	Vcl::Extctrls::TPanel* Panel10;
	Vcl::Menus::TPopupMenu* PMViewList;
	Vcl::Menus::TMenuItem* miDeleteView;
	Vcl::Menus::TMenuItem* N1;
	Vcl::Menus::TMenuItem* miEditLayout;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Extctrls::TPanel* Panel12;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* LSelectedView;
	Vcl::Extctrls::TPanel* Panel13;
	Vcl::Extctrls::TPanel* Panel14;
	Cxpc::TcxPageControl* PageControl1;
	Cxpc::TcxTabSheet* tsLevels;
	Vcl::Extctrls::TPanel* PLevels;
	Vcl::Extctrls::TPanel* Panel6;
	Cxbuttons::TcxButton* BAddLevel;
	Cxbuttons::TcxButton* BDeleteLevel;
	Cxpc::TcxTabSheet* TabSheet2;
	Vcl::Extctrls::TPanel* PViews;
	Vcl::Stdctrls::TListBox* LBViews;
	Vcl::Extctrls::TPanel* Panel9;
	Cxbuttons::TcxButton* BAddView;
	Cxbuttons::TcxButton* BDeleteView;
	Cxbuttons::TcxButton* BEditView;
	Vcl::Extctrls::TPanel* Panel15;
	Vcl::Extctrls::TPanel* PViewFrame;
	void __fastcall BCloseClick(System::TObject* Sender);
	void __fastcall BDeleteLevelClick(System::TObject* Sender);
	void __fastcall BAddLevelClick(System::TObject* Sender);
	void __fastcall LBViewsClick(System::TObject* Sender);
	void __fastcall BAddViewClick(System::TObject* Sender);
	void __fastcall BDeleteViewClick(System::TObject* Sender);
	void __fastcall GridStructureControlKeyPress(System::TObject* Sender, System::WideChar &Key);
	HIDESBASE void __fastcall FormClose(System::TObject* Sender, System::Uitypes::TCloseAction &Action);
	void __fastcall miEditLayoutClick(System::TObject* Sender);
	
private:
	Cxgridstructurenavigator::TcxGridStructureControl* FGridStructureControl;
	Cxgridstructurenavigator::TcxGridStructureHelper* FGridStructureHelper;
	Cxvieweditor::TcxViewEditor* FViewEditor;
	void __fastcall CreateViewClick(System::TObject* Sender);
	Cxgrid::TcxCustomGrid* __fastcall GetGrid(void);
	Cxgridcustomview::TcxCustomGridView* __fastcall GetView(int Index);
	int __fastcall GetViewCount(void);
	Cxgrid::TcxGridViewRepository* __fastcall GetViewRepository(void);
	void __fastcall GridStructureControlSelectionChanged(System::TObject* Sender);
	void __fastcall HideViewFrame(void);
	void __fastcall ShowViewFrame(Cxgridcustomview::TcxCustomGridView* AView, bool AMultiView, bool ARefreshNeeded);
	void __fastcall UpdateButtons(void);
	void __fastcall UpdateDesigner(System::TObject* Sender);
	void __fastcall UpdateGridStructureControl(void);
	void __fastcall UpdateGridStructureControlSelection(void);
	void __fastcall UpdateViewFrame(bool ARefreshNeeded);
	void __fastcall UpdateViewFrameCaption(void);
	void __fastcall UpdateViewList(void);
	
protected:
	TSelectionInfo __fastcall GetSelectionInfo(void);
	virtual Cxvieweditor::TcxViewEditorClass __fastcall GetViewEditorClass(Cxgridcustomview::TcxCustomGridView* AView);
	virtual void __fastcall InitFormEditor(void);
	virtual void __fastcall InitIDESelection(void);
	void __fastcall InitLookAndFeel(Vcl::Controls::TWinControl* AControl);
	void __fastcall LoadSettings(void);
	void __fastcall SaveSettings(void);
	virtual System::UnicodeString __fastcall UniqueName(System::Classes::TComponent* Component);
	virtual void __fastcall UpdateContent(void);
	
public:
	__fastcall virtual TcxGridEditor(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridEditor(void);
	virtual void __fastcall DoItemsModified(void);
	System::UnicodeString __fastcall GetRegKey(void);
	System::UnicodeString __fastcall GetRegSectionName(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	__property Cxgrid::TcxCustomGrid* Grid = {read=GetGrid};
	__property int ViewCount = {read=GetViewCount, nodefault};
	__property Cxgrid::TcxGridViewRepository* ViewRepository = {read=GetViewRepository};
	__property Cxgridcustomview::TcxCustomGridView* Views[int Index] = {read=GetView};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridEditor(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridEditor(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ShowGridEditor(Designintf::_di_IDesigner ADesigner, Cxgrid::TcxCustomGrid* AGrid);
extern PACKAGE void __fastcall ShowViewRepositoryEditor(Designintf::_di_IDesigner ADesigner, Cxgrid::TcxGridViewRepository* AViewRepository);
}	/* namespace Cxgrideditor */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDEDITOR)
using namespace Cxgrideditor;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgrideditorHPP
