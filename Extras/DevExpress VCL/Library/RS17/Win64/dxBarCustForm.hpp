// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxBarCustForm.pas' rev: 24.00 (Win64)

#ifndef DxbarcustformHPP
#define DxbarcustformHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit
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
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.ToolWin.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <dxMessages.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxBar.hpp>	// Pascal unit
#include <dxBarCustomCustomizationForm.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxbarcustform
{
//-- type declarations -------------------------------------------------------
typedef bool __fastcall (__closure *TdxBarPermissiveProc)(System::Classes::TComponent* Sender);

class DELPHICLASS TdxBarCustomizationForm;
class PASCALIMPLEMENTATION TdxBarCustomizationForm : public Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm
{
	typedef Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm inherited;
	
__published:
	Vcl::Actnlist::TAction* aAddGroup;
	Vcl::Actnlist::TAction* aAddGroupItem;
	Vcl::Actnlist::TAction* aDeleteGroup;
	Vcl::Actnlist::TAction* aDeleteGroupItem;
	Vcl::Actnlist::TActionList* alGroupCustomize;
	Vcl::Actnlist::TAction* aMoveDownGroup;
	Vcl::Actnlist::TAction* aMoveDownGroupItem;
	Vcl::Actnlist::TAction* aMoveUpGroup;
	Vcl::Actnlist::TAction* aMoveUpGroupItem;
	Vcl::Stdctrls::TButton* BBarDelete;
	Vcl::Stdctrls::TButton* BBarNew;
	Vcl::Stdctrls::TButton* BBarRename;
	Vcl::Stdctrls::TButton* BBarReset;
	Vcl::Stdctrls::TButton* BClose;
	Vcl::Extctrls::TBevel* Bevel1;
	Vcl::Extctrls::TBevel* Bevel2;
	Vcl::Extctrls::TBevel* Bevel3;
	Vcl::Extctrls::TBevel* Bevel4;
	Vcl::Buttons::TBitBtn* BHelp;
	Vcl::Stdctrls::TButton* BResetUsageData;
	Vcl::Comctrls::TToolButton* btnAddGroup;
	Vcl::Comctrls::TToolButton* btnAddGroupItem;
	Vcl::Comctrls::TToolButton* btnDeleteGroup;
	Vcl::Comctrls::TToolButton* btnDeleteGroupItem;
	Vcl::Comctrls::TToolButton* btnMoveDownGroup;
	Vcl::Comctrls::TToolButton* btnMoveDownGroupItem;
	Vcl::Comctrls::TToolButton* btnMoveUpGroup;
	Vcl::Comctrls::TToolButton* btnMoveUpGroupItem;
	Vcl::Buttons::TSpeedButton* CategoriesPopupButtonPlace;
	Vcl::Stdctrls::TCheckBox* CBHint1;
	Vcl::Stdctrls::TCheckBox* CBHint1Ex;
	Vcl::Stdctrls::TCheckBox* CBHint2;
	Vcl::Stdctrls::TCheckBox* CBHint2Ex;
	Vcl::Stdctrls::TCheckBox* CBLargeIcons;
	Vcl::Stdctrls::TCheckBox* CBLargeIconsEx;
	Vcl::Stdctrls::TCheckBox* CBMenusShowRecentItemsFirst;
	Vcl::Stdctrls::TCheckBox* CBShowCommandsWithShortCut;
	Vcl::Stdctrls::TCheckBox* CBShowFullMenusAfterDelay;
	Vcl::Stdctrls::TComboBox* ComboBoxMenuAnimations;
	Vcl::Stdctrls::TComboBox* ComboBoxMenuAnimationsEx;
	Vcl::Buttons::TSpeedButton* CommandsPopupButtonPlace;
	Vcl::Stdctrls::TLabel* DescriptionLabel;
	Vcl::Extctrls::TPanel* EnhancedOptionsPanel;
	Vcl::Stdctrls::TGroupBox* gbGroups;
	Vcl::Stdctrls::TGroupBox* gpGroupItems;
	Vcl::Stdctrls::TLabel* Label1;
	Vcl::Stdctrls::TLabel* Label2;
	Vcl::Stdctrls::TLabel* Label3;
	Vcl::Stdctrls::TLabel* LabelCategories;
	Vcl::Stdctrls::TLabel* LabelCommands;
	Vcl::Stdctrls::TLabel* LabelDescription;
	Vcl::Stdctrls::TLabel* LabelMenuAnimations;
	Vcl::Stdctrls::TLabel* LabelToobars;
	Vcl::Stdctrls::TListBox* LAllCommands;
	Vcl::Stdctrls::TListBox* lbBarsList;
	Vcl::Stdctrls::TListBox* lbCategories;
	Vcl::Stdctrls::TListBox* lbGroupItems;
	Vcl::Stdctrls::TListBox* lbGroups;
	Vcl::Stdctrls::TListBox* lbItems;
	Vcl::Comctrls::TPageControl* PageControl;
	Vcl::Extctrls::TPanel* Panel1;
	Vcl::Extctrls::TPanel* Panel2;
	Vcl::Extctrls::TPanel* Panel3;
	Vcl::Extctrls::TPanel* Panel4;
	Vcl::Extctrls::TPanel* Panel5;
	Vcl::Extctrls::TPanel* Panel6;
	Vcl::Extctrls::TPanel* Panel7;
	Vcl::Extctrls::TPanel* Panel8;
	Vcl::Extctrls::TPanel* Panel9;
	Vcl::Extctrls::TPanel* StandardOptionsPanel;
	Vcl::Comctrls::TTabSheet* TabSheet1;
	Vcl::Comctrls::TToolBar* tbGroupItems;
	Vcl::Comctrls::TToolBar* tbGroups;
	Vcl::Comctrls::TToolButton* ToolButton3;
	Vcl::Comctrls::TToolButton* ToolButton8;
	Vcl::Comctrls::TTabSheet* tsCommands;
	Vcl::Comctrls::TTabSheet* tsGroups;
	Vcl::Comctrls::TTabSheet* tsItems;
	Vcl::Comctrls::TTabSheet* tsOptions;
	Vcl::Comctrls::TTabSheet* tsToolbars;
	Vcl::Comctrls::TTreeView* tvKeyTips;
	void __fastcall aAddGroupExecute(System::TObject* Sender);
	void __fastcall aAddGroupItemExecute(System::TObject* Sender);
	void __fastcall aDeleteGroupExecute(System::TObject* Sender);
	void __fastcall aDeleteGroupItemExecute(System::TObject* Sender);
	void __fastcall aMoveGroupExecute(System::TObject* Sender);
	void __fastcall aMoveGroupItemExecute(System::TObject* Sender);
	void __fastcall BResetUsageDataClick(System::TObject* Sender);
	void __fastcall CBHint1Click(System::TObject* Sender);
	void __fastcall CBHint1ExClick(System::TObject* Sender);
	void __fastcall CBHint2Click(System::TObject* Sender);
	void __fastcall CBLargeIconsClick(System::TObject* Sender);
	void __fastcall CBMenusShowRecentItemsFirstClick(System::TObject* Sender);
	void __fastcall CBShowCommandsWithShortCutClick(System::TObject* Sender);
	void __fastcall CBShowFullMenusAfterDelayClick(System::TObject* Sender);
	void __fastcall ComboBoxMenuAnimationsClick(System::TObject* Sender);
	void __fastcall LAllCommandsClick(System::TObject* Sender);
	void __fastcall LAllCommandsDrawItem(Vcl::Controls::TWinControl* Control, int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall LAllCommandsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall lbGroupItemsClick(System::TObject* Sender);
	void __fastcall lbGroupItemsDrawItem(Vcl::Controls::TWinControl* Control, int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall lbGroupItemsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall lbGroupsClick(System::TObject* Sender);
	void __fastcall lbGroupsDrawItem(Vcl::Controls::TWinControl* Control, int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall lbGroupsKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall lbGroupsMeasureItem(Vcl::Controls::TWinControl* Control, int Index, int &Height);
	void __fastcall lbItemsDrawItem(Vcl::Controls::TWinControl* Control, int Index, System::Types::TRect &Rect, Winapi::Windows::TOwnerDrawState State);
	void __fastcall BCloseClick(System::TObject* Sender);
	void __fastcall BHelpClick(System::TObject* Sender);
	
private:
	int FAllCommandsCaptionWidth;
	int FAllCommandsNameWidth;
	int FAllCommandsLinksCountWidth;
	int FAllCommandsShortCutWidth;
	System::Classes::TWndMethod FAllCommandListBoxOldWndProc;
	System::Classes::TWndMethod FGroupItemListBoxOldWndProc;
	System::Classes::TWndMethod FGroupListBoxOldWndProc;
	Cxclasses::TcxComponentListChangeEvent FGroupsOldChangeEvent;
	Dxbar::TdxBarComponentList* FSelectedGroupItems;
	void __fastcall AllCommandListBoxWndProc(Winapi::Messages::TMessage &Message);
	Dxbar::TdxBarItem* __fastcall GetAllCommandList(int Index);
	void __fastcall RefreshAllCommandListBox(void);
	void __fastcall OnItemLinkChange(Dxbar::TdxBarManager* Sender, Dxbar::TdxBarItemLink* AItemLink);
	Dxbar::TdxBarGroup* __fastcall GetSelectedGroup(void);
	void __fastcall GroupListBoxWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall GroupsChange(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	void __fastcall MoveGroup(int ADirection);
	void __fastcall RememberSelectedList(void);
	void __fastcall GroupItemListBoxWndProc(Winapi::Messages::TMessage &Message);
	void __fastcall GroupStuctureChange(void);
	void __fastcall DeleteGroupItem(System::TObject* AGroupItem);
	void __fastcall MoveGroupItem(int ADirection);
	void __fastcall UpdateGroupItemEvents(void);
	__property Dxbar::TdxBarItem* AllCommandList[int Index] = {read=GetAllCommandList};
	__property Dxbar::TdxBarGroup* SelectedGroup = {read=GetSelectedGroup};
	
protected:
	virtual Vcl::Stdctrls::TListBox* __fastcall GetBarListBox(void);
	virtual Vcl::Stdctrls::TListBox* __fastcall GetCategoriesList(void);
	virtual Vcl::Stdctrls::TListBox* __fastcall GetItemsListBox(void);
	virtual void __fastcall ItemsChange(System::TObject* Sender, System::Classes::TComponent* AComponent, Cxclasses::TcxComponentCollectionNotification AAction);
	virtual void __fastcall PrepareControls(void);
	virtual void __fastcall RestoreOldEvents(void);
	virtual void __fastcall SynchronizeListBoxes(void);
	virtual void __fastcall UpdateItemDesciption(const System::UnicodeString AText);
	
public:
	__fastcall virtual TdxBarCustomizationForm(Dxbar::TdxBarManager* ABarManager);
	__fastcall virtual ~TdxBarCustomizationForm(void);
	virtual void __fastcall DesignSelectionChanged(System::TObject* Sender);
	virtual void __fastcall SelectPage(int APageIndex);
	virtual void __fastcall SwitchToItemsPage(void);
	virtual void __fastcall UpdateHelpButton(void);
	virtual void __fastcall UpdateOptions(void);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TdxBarCustomizationForm(System::Classes::TComponent* AOwner) : Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TdxBarCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TdxBarCustomizationForm(HWND ParentWindow) : Dxbarcustomcustomizationform::TdxBarCustomCustomizationForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dxbarcustform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXBARCUSTFORM)
using namespace Dxbarcustform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxbarcustformHPP
