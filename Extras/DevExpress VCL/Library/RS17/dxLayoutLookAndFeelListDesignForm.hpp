// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutLookAndFeelListDesignForm.pas' rev: 24.00 (Win32)

#ifndef DxlayoutlookandfeellistdesignformHPP
#define DxlayoutlookandfeellistdesignformHPP

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
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <DesignIntf.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <dxLayoutControl.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <cxDesignWindows.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <dxLayoutControlAdapters.hpp>	// Pascal unit
#include <cxMemo.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxRichEdit.hpp>	// Pascal unit
#include <dxLayoutcxEditAdapters.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <DesignWindows.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutlookandfeellistdesignform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxLayoutLookAndFeelListDesignForm;
class PASCALIMPLEMENTATION TdxLayoutLookAndFeelListDesignForm : public Cxdesignwindows::TcxDesignFormEditor
{
	typedef Cxdesignwindows::TcxDesignFormEditor inherited;
	
__published:
	Dxlayoutcontrol::TdxLayoutControl* lcMain;
	Vcl::Stdctrls::TListBox* lbItems;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem1;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainGroup3;
	Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* lflMain;
	Dxlayoutcontrol::TdxLayoutControl* lcPreview;
	Dxlayoutcontainer::TdxLayoutGroup* dxLayoutGroup1;
	Dxlayoutcontainer::TdxLayoutGroup* dxLayoutControl1Group2;
	Dxlayoutcontainer::TdxLayoutGroup* dxLayoutControl1Group3;
	Vcl::Actnlist::TActionList* alMain;
	Vcl::Actnlist::TAction* acAdd;
	Vcl::Actnlist::TAction* acDelete;
	Vcl::Actnlist::TAction* acClose;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem5;
	Vcl::Comctrls::TToolBar* tlbGroups;
	Vcl::Comctrls::TToolButton* tbAddItem;
	Vcl::Comctrls::TToolButton* tbDelete;
	Vcl::Menus::TPopupMenu* PopupMenu1;
	Cxgraphics::TcxImageList* ilMain;
	Cxgraphics::TcxImageList* ilMainDisabled;
	Cxtextedit::TcxTextEdit* cxTextEdit1;
	Dxlayoutcontainer::TdxLayoutItem* lcPreviewItem1;
	Cxmemo::TcxMemo* cxMemo1;
	Dxlayoutcontainer::TdxLayoutItem* lcPreviewItem5;
	Cxcheckbox::TcxCheckBox* cxCheckBox3;
	Dxlayoutcontainer::TdxLayoutItem* lcPreviewItem2;
	Cxtextedit::TcxTextEdit* cxTextEdit2;
	Dxlayoutcontainer::TdxLayoutItem* lcPreviewItem8;
	Cxrichedit::TcxRichEdit* cxRichEdit1;
	Dxlayoutcontainer::TdxLayoutItem* lcPreviewItem3;
	Cxbuttons::TcxButton* cxButton1;
	Dxlayoutcontainer::TdxLayoutItem* lcPreviewItem4;
	Cxbuttons::TcxButton* cxButton2;
	Dxlayoutcontainer::TdxLayoutItem* lcPreviewItem6;
	Cxbuttons::TcxButton* cxButton3;
	Dxlayoutcontainer::TdxLayoutItem* lcPreviewItem9;
	Dxlayoutcontainer::TdxLayoutGroup* lcPreviewGroup2;
	Dxlayoutcontainer::TdxLayoutItem* liWarning;
	Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* dxLayoutLookAndFeelList1;
	Dxlayoutcontainer::TdxLayoutGroup* lcPreviewGroup4;
	Dxlayoutcontainer::TdxLayoutItem* liPreview;
	Dxlayoutcontainer::TdxLayoutGroup* lcPreviewGroup3;
	Dxlayoutcontainer::TdxLayoutGroup* lcPreviewGroup5;
	Dxlayoutlookandfeels::TdxLayoutWebLookAndFeel* dxLayoutWebLookAndFeel1;
	Dxlayoutcontainer::TdxLayoutGroup* lcPreview_Root;
	Dxlayoutcontainer::TdxLayoutGroup* lgRoot;
	void __fastcall btnAddClick(System::TObject* Sender);
	void __fastcall lbItemsClick(System::TObject* Sender);
	void __fastcall acDeleteExecute(System::TObject* Sender);
	void __fastcall lbItemsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	HIDESBASE void __fastcall FormCreate(System::TObject* Sender);
	
private:
	bool __fastcall CanModify(void);
	int __fastcall GetListBoxItemHeight(void);
	Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* __fastcall GetList(void);
	void __fastcall SynchronizeListBoxSelection(void);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void __fastcall SetComponent(System::Classes::TComponent* AValue);
	virtual void __fastcall UpdateCaption(void);
	virtual void __fastcall UpdateContent(void);
	void __fastcall DeleteItems(void);
	HIDESBASE void __fastcall Refresh(bool ARefreshSelection = false);
	void __fastcall RefreshEnableds(void);
	void __fastcall RefreshListBox(void);
	void __fastcall SetAddItemsActionEnabled(bool AEnabled);
	void __fastcall SetDeleteItemsActionEnabled(bool AEnabled);
	void __fastcall SynchronizeControlsSelection(System::Classes::TList* AList);
	void __fastcall SynchronizeSelection(System::Classes::TList* AList);
	void __fastcall ComponentNameChanged(Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* ALookAndFeelList);
	void __fastcall ItemsChanged(Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* ALookAndFeelList);
	void __fastcall Edit(Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* ALookAndFeelList);
	
public:
	__fastcall virtual TdxLayoutLookAndFeelListDesignForm(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TdxLayoutLookAndFeelListDesignForm(void);
	virtual void __fastcall AfterConstruction(void);
	virtual void __fastcall SelectionsChanged(const Designintf::_di_IDesignerSelections ASelection);
	__property Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* List = {read=GetList};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxLayoutLookAndFeelListDesignForm(System::Classes::TComponent* AOwner, int Dummy) : Cxdesignwindows::TcxDesignFormEditor(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxLayoutLookAndFeelListDesignForm(HWND ParentWindow) : Cxdesignwindows::TcxDesignFormEditor(ParentWindow) { }
	
private:
	void *__IdxLayoutLookAndFeelsDesigner;	/* Dxlayoutlookandfeels::IdxLayoutLookAndFeelsDesigner */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {EA24F329-D483-4D4F-A72C-1F67EC4F7E21}
	operator Dxlayoutlookandfeels::_di_IdxLayoutLookAndFeelsDesigner()
	{
		Dxlayoutlookandfeels::_di_IdxLayoutLookAndFeelsDesigner intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutlookandfeels::IdxLayoutLookAndFeelsDesigner*(void) { return (Dxlayoutlookandfeels::IdxLayoutLookAndFeelsDesigner*)&__IdxLayoutLookAndFeelsDesigner; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxlayoutlookandfeellistdesignform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTLOOKANDFEELLISTDESIGNFORM)
using namespace Dxlayoutlookandfeellistdesignform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutlookandfeellistdesignformHPP
