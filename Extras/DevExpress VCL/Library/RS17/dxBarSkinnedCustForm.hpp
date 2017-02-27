// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarSkinnedCustForm.pas' rev: 24.00 (Win32)

#ifndef DxbarskinnedcustformHPP
#define DxbarskinnedcustformHPP

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
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <Vcl.Buttons.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxBarCustomCustomizationForm.hpp>	// Pascal unit
#include <dxSkinsCore.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxListBox.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <cxCheckListBox.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <dxSkinsDefaultPainters.hpp>	// Pascal unit
#include <dxSkinsdxBarPainter.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarskinnedcustform
{
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TdxBarPermissiveProc)(System::Classes::TComponent* Sender);

class DELPHICLASS TdxBarSkinnedCustomizationForm;
class PASCALIMPLEMENTATION TdxBarSkinnedCustomizationForm : public Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm
{
	typedef Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm inherited;
	
__published:
	Cxbuttons::TcxButton* BBarDelete;
	Cxbuttons::TcxButton* BBarNew;
	Cxbuttons::TcxButton* BBarRename;
	Cxbuttons::TcxButton* BBarReset;
	Cxbuttons::TcxButton* BClose;
	Cxbuttons::TcxButton* BHelp;
	Cxbuttons::TcxButton* BResetUsageData;
	Cxbuttons::TcxButton* CategoriesPopupButtonPlace;
	Cxcheckbox::TcxCheckBox* CBHint1Ex;
	Cxcheckbox::TcxCheckBox* CBHint2;
	Cxcheckbox::TcxCheckBox* CBHint2Ex;
	Cxcheckbox::TcxCheckBox* CBLargeIcons;
	Cxcheckbox::TcxCheckBox* CBLargeIconsEx;
	Cxcheckbox::TcxCheckBox* CBMenusShowRecentItemsFirst;
	Cxcheckbox::TcxCheckBox* CBShowFullMenusAfterDelay;
	Cxdropdownedit::TcxComboBox* ComboBoxMenuAnimations;
	Cxdropdownedit::TcxComboBox* ComboBoxMenuAnimationsEx;
	Cxbuttons::TcxButton* CommandsPopupButtonPlace;
	Cxlabel::TcxLabel* DescriptionLabel;
	Cxgroupbox::TcxGroupBox* EnhancedOptionsPanel;
	Cxlabel::TcxLabel* Label1;
	Cxlabel::TcxLabel* Label2;
	Cxlabel::TcxLabel* Label3;
	Cxlabel::TcxLabel* LabelCategories;
	Cxlabel::TcxLabel* LabelCommands;
	Cxlabel::TcxLabel* LabelDescription;
	Cxlabel::TcxLabel* LabelMenuAnimations;
	Cxlabel::TcxLabel* LabelToobars;
	Cxlistbox::TcxListBox* lbCategories;
	Cxlistbox::TcxListBox* lbItems;
	Vcl::Extctrls::TBevel* LeftBevel;
	Cxpc::TcxPageControl* PageControl;
	Cxgroupbox::TcxGroupBox* Panel1;
	Cxgroupbox::TcxGroupBox* Panel6;
	Cxgroupbox::TcxGroupBox* Panel7;
	Cxgroupbox::TcxGroupBox* Panel9;
	Vcl::Extctrls::TBevel* RightBevel;
	Cxgroupbox::TcxGroupBox* StandardOptionsPanel;
	Cxpc::TcxTabSheet* TabSheet1;
	Vcl::Extctrls::TBevel* TopBevel;
	Cxpc::TcxTabSheet* tsItems;
	Cxpc::TcxTabSheet* tsOptions;
	Cxpc::TcxTabSheet* tsToolbars;
	Vcl::Comctrls::TTreeView* tvKeyTips;
	Cxlistbox::TcxListBox* lbBarsList;
	Cxcheckbox::TcxCheckBox* CBHint1;
	Vcl::Extctrls::TBevel* Bevel4;
	Vcl::Extctrls::TBevel* Bevel5;
	Cxgroupbox::TcxGroupBox* Panel2;
	bool __fastcall GetIsSkinUsed(void);
	void __fastcall BResetUsageDataClick(System::TObject* Sender);
	void __fastcall CBHint1Click(System::TObject* Sender);
	void __fastcall CBHint1ExClick(System::TObject* Sender);
	void __fastcall CBHint2Click(System::TObject* Sender);
	void __fastcall CBLargeIconsClick(System::TObject* Sender);
	void __fastcall CBMenusShowRecentItemsFirstClick(System::TObject* Sender);
	void __fastcall CBShowFullMenusAfterDelayClick(System::TObject* Sender);
	void __fastcall ComboBoxMenuAnimationsClick(System::TObject* Sender);
	void __fastcall lbItemsDrawItem(Cxlistbox::TcxListBox* AControl, Cxgraphics::TcxCanvas* ACanvas, int AIndex, const System::Types::TRect &ARect, Winapi::Windows::TOwnerDrawState AState);
	void __fastcall BCloseClick(System::TObject* Sender);
	void __fastcall BHelpClick(System::TObject* Sender);
	
private:
	Cxlookandfeels::TcxLookAndFeel* FLookAndFeel;
	
protected:
	virtual System::Uitypes::TColor __fastcall GetBarItemsBackgroundColor(void);
	virtual Vcl::Stdctrls::TListBox* __fastcall GetBarListBox(void);
	virtual Vcl::Stdctrls::TListBox* __fastcall GetCategoriesList(void);
	virtual Vcl::Stdctrls::TListBox* __fastcall GetItemsListBox(void);
	virtual Dxbarcustomcustomizationform::TdxBarCustomizationFormPainterClass __fastcall GetPainterClass(void);
	virtual void __fastcall PrepareControls(void);
	virtual void __fastcall SynchronizeListBoxes(void);
	virtual void __fastcall UpdateItemDesciption(const System::UnicodeString AText);
	__property bool IsSkinUsed = {read=GetIsSkinUsed, nodefault};
	__property Cxlookandfeels::TcxLookAndFeel* LookAndFeel = {read=FLookAndFeel};
	
public:
	__fastcall virtual TdxBarSkinnedCustomizationForm(Dxbar::TdxBarManager* ABarManager);
	__fastcall virtual ~TdxBarSkinnedCustomizationForm(void);
	virtual void __fastcall BarManagerStyleChanged(void);
	virtual void __fastcall DesignSelectionChanged(System::TObject* Sender);
	virtual void __fastcall SelectPage(int APageIndex);
	virtual void __fastcall SwitchToItemsPage(void);
	virtual void __fastcall UpdateHelpButton(void);
	virtual void __fastcall UpdateOptions(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxBarSkinnedCustomizationForm(System::Classes::TComponent* AOwner) : Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBarSkinnedCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarSkinnedCustomizationForm(HWND ParentWindow) : Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxbarskinnedcustform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARSKINNEDCUSTFORM)
using namespace Dxbarskinnedcustform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarskinnedcustformHPP
