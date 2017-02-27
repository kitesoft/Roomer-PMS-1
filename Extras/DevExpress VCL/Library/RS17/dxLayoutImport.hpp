// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dxLayoutImport.pas' rev: 24.00 (Win32)

#ifndef DxlayoutimportHPP
#define DxlayoutimportHPP

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
#include <System.Variants.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <dxLayoutControl.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <Vcl.ExtCtrls.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxLabel.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGroupBox.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxSplitter.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxDropDownEdit.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxRadioGroup.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <cxTextEdit.hpp>	// Pascal unit
#include <cxMaskEdit.hpp>	// Pascal unit
#include <cxSpinEdit.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <cxPC.hpp>	// Pascal unit
#include <dxLayoutcxEditAdapters.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <dxLayoutControlAdapters.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Dxlayoutimport
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TdxAutoLayoutItem;
class DELPHICLASS TdxAutoLayout;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAutoLayoutItem : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Vcl::Controls::TAlign FAlign;
	System::Uitypes::TAnchors FAnchors;
	TdxAutoLayout* FAutoLayout;
	System::Types::TRect FBoundsRect;
	System::UnicodeString FCaption;
	Dxlayoutcontainer::TdxCaptionLayout FCaptionLayout;
	Vcl::Controls::TControl* FControl;
	bool FLabeled;
	System::Types::TRect FLabeledBoundsRect;
	Dxlayoutcontainer::TdxCustomLayoutItem* FLayoutControlItem;
	int FLayoutHorizontalCenter;
	void __fastcall SetAligns(void);
	
public:
	__fastcall TdxAutoLayoutItem(TdxAutoLayout* AAutoLayout, Vcl::Controls::TControl* AControl);
	void __fastcall Apply(bool ANeedSetAligns = true);
	void __fastcall Assign(TdxAutoLayoutItem* Source);
	void __fastcall CreateLayoutControlItem(Dxlayoutcontainer::TdxLayoutGroup* AGroup);
	bool __fastcall CanResize(void);
	Dxlayoutcontainer::TdxLayoutGroup* __fastcall CreateGroup(Dxlayoutcontainer::TdxLayoutGroup* AGroup);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall CreateItem(Dxlayoutcontainer::TdxLayoutGroup* AGroup);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall CreateSeparator(Dxlayoutcontainer::TdxLayoutGroup* AGroup);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall CreateSplitter(Dxlayoutcontainer::TdxLayoutGroup* AGroup);
	Dxlayoutcontainer::TdxCustomLayoutItem* __fastcall CreateTabbedGroup(Dxlayoutcontainer::TdxLayoutGroup* AGroup);
	System::UnicodeString __fastcall GetGroupCaption(void);
	System::UnicodeString __fastcall GetLabelCaption(void);
	bool __fastcall IsAligned(void);
	bool __fastcall IsButton(void);
	bool __fastcall IsGroup(void);
	bool __fastcall IsHiddenGroup(void);
	bool __fastcall IsLabel(void);
	bool __fastcall IsSeparator(void);
	bool __fastcall IsSplitter(void);
	bool __fastcall IsPageControl(void);
	bool __fastcall IsStandaloneLabel(void);
	Vcl::Controls::TWinControl* __fastcall GetFocusControl(void);
	void __fastcall SetLabelInfo(Vcl::Controls::TControl* ALabel);
	__property System::Types::TRect BoundsRect = {read=FBoundsRect};
	__property System::UnicodeString Caption = {read=FCaption};
	__property Dxlayoutcontainer::TdxCaptionLayout CaptionLayout = {read=FCaptionLayout, nodefault};
	__property Vcl::Controls::TControl* Control = {read=FControl};
	__property bool Labeled = {read=FLabeled, nodefault};
	__property System::Types::TRect LabeledBoundsRect = {read=FLabeledBoundsRect};
	__property Dxlayoutcontainer::TdxCustomLayoutItem* LayoutControlItem = {read=FLayoutControlItem};
	__property int LayoutHorizontalCenter = {read=FLayoutHorizontalCenter, write=FLayoutHorizontalCenter, nodefault};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoLayoutItem(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAutoLayoutItemList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAutoLayoutItemList : public System::Classes::TList
{
	typedef System::Classes::TList inherited;
	
public:
	TdxAutoLayoutItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxAutoLayoutItem* __fastcall GetItem(int Index);
	
public:
	bool __fastcall CanConvert(Cxgraphics::TcxBorder ASide);
	HIDESBASE TdxAutoLayoutItem* __fastcall First(void);
	void __fastcall FreeItems(void);
	bool __fastcall IsButtons(void);
	HIDESBASE TdxAutoLayoutItem* __fastcall Last(void);
	__property TdxAutoLayoutItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAutoLayoutItemList(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TdxAutoLayoutItemList(void) : System::Classes::TList() { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAutoLayoutOwnedItemList;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAutoLayoutOwnedItemList : public Cxclasses::TcxObjectList
{
	typedef Cxclasses::TcxObjectList inherited;
	
public:
	TdxAutoLayoutItem* operator[](int Index) { return Items[Index]; }
	
private:
	TdxAutoLayout* FAutoLayout;
	HIDESBASE TdxAutoLayoutItem* __fastcall GetItem(int Index);
	
public:
	__fastcall TdxAutoLayoutOwnedItemList(TdxAutoLayout* AAutoLayout);
	HIDESBASE TdxAutoLayoutItem* __fastcall Add(Vcl::Controls::TControl* AControl);
	TdxAutoLayoutItem* __fastcall AddAlignedItems(TdxAutoLayoutItem* AItem);
	void __fastcall DeleteItems(TdxAutoLayoutItemList* AItems);
	HIDESBASE void __fastcall Extract(int AIndex);
	TdxAutoLayoutItem* __fastcall Find(Vcl::Controls::TControl* AControl);
	HIDESBASE bool __fastcall Remove(Vcl::Controls::TControl* AControl);
	void __fastcall RemoveItems(TdxAutoLayoutItemList* AItems);
	__property TdxAutoLayoutItem* Items[int Index] = {read=GetItem/*, default*/};
public:
	/* TList.Destroy */ inline __fastcall virtual ~TdxAutoLayoutOwnedItemList(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TdxAutoLayoutHelper;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAutoLayoutHelper : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TdxAutoLayoutOwnedItemList* FAlignedItems;
	System::Set<Vcl::Controls::TAlign, Vcl::Controls::TAlign::alNone, Vcl::Controls::TAlign::alCustom>  FAligns;
	TdxAutoLayoutItem* FBottommostItem;
	Vcl::Controls::TWinControl* FContainer;
	TdxAutoLayoutOwnedItemList* FItems;
	TdxAutoLayoutItem* FLeftmostItem;
	System::Types::TRect FNonAlignedBoundsRect;
	TdxAutoLayout* FOwner;
	TdxAutoLayoutItem* FRightmostItem;
	Dxlayoutcontainer::TdxLayoutGroup* FRoot;
	TdxAutoLayoutItem* FTopmostItem;
	bool __fastcall CanExport(Vcl::Controls::TControl* AControl);
	TdxAutoLayoutItem* __fastcall FindBottommostItem(void);
	TdxAutoLayoutItem* __fastcall FindLeftmostItem(void);
	TdxAutoLayoutItem* __fastcall FindRightmostItem(void);
	TdxAutoLayoutItem* __fastcall FindTopmostItem(void);
	Vcl::Controls::TControl* __fastcall GetControlAtPos(int X, int Y);
	Vcl::Controls::TWinControl* __fastcall GetFocusControl(TdxAutoLayoutItem* AItem);
	int __fastcall GetItemCount(void);
	bool __fastcall HasItemsAtRect(const System::Types::TRect &R);
	void __fastcall MakeNewRoot(void);
	Dxlayoutcontainer::TdxLayoutGroup* __fastcall NewGroup(TdxAutoLayoutItemList* AItems);
	void __fastcall ProcessAnchors(TdxAutoLayoutItemList* AItems, /* out */ Dxlayoutcontainer::TdxLayoutAlignHorz &AAlignHorz, /* out */ Dxlayoutcontainer::TdxLayoutAlignVert &AAlignVert);
	void __fastcall PopulateItems(void);
	void __fastcall PopulateItemsAtRect(TdxAutoLayoutItemList* AItems, const System::Types::TRect &R);
	void __fastcall ProcessLabels(void);
	System::Types::TRect __fastcall UpdateUtmostItems(void);
	
protected:
	void __fastcall CheckRootDirection(TdxAutoLayoutItemList* AItems, Dxlayoutcontainer::TdxLayoutDirection ADirection);
	void __fastcall ConvertGroup(TdxAutoLayoutItemList* AItems, Cxgraphics::TcxBorder ASide, const System::Types::TRect &APreviousGroupBounds, /* out */ System::Types::TRect &AGroupBounds);
	void __fastcall DoNonAlignedControls(void);
	virtual void __fastcall DoExecute(void);
	void __fastcall GenerateAligned(Vcl::Controls::TAlign AAlign);
	virtual void __fastcall GenerateLayout(void);
	virtual void __fastcall GenerateNonAlignedLayout(void);
	void __fastcall GetSideItemGroup(TdxAutoLayoutItemList* AItems, Cxgraphics::TcxBorder ASide);
	virtual void __fastcall Initialize(Vcl::Controls::TWinControl* AContainer, Dxlayoutcontainer::TdxLayoutGroup* ARoot);
	__property TdxAutoLayout* Owner = {read=FOwner};
	__property Dxlayoutcontainer::TdxLayoutGroup* Root = {read=FRoot};
	
public:
	__fastcall TdxAutoLayoutHelper(TdxAutoLayout* AOwner);
	__fastcall virtual ~TdxAutoLayoutHelper(void);
	void __fastcall Execute(Vcl::Controls::TWinControl* AContainer, Dxlayoutcontainer::TdxLayoutGroup* ARoot);
	__property Vcl::Controls::TWinControl* Container = {read=FContainer};
	__property int ItemCount = {read=GetItemCount, nodefault};
	__property TdxAutoLayoutOwnedItemList* Items = {read=FItems};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TdxAutoLayout : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::Byte FFocusControlDistanceX;
	System::Byte FFocusControlDistanceY;
	Dxlayoutcontrol::TdxCustomLayoutControl* FControl;
	bool FConvertPageControls;
	bool FRecursive;
	bool FSmartFindFocusControl;
	bool FUseLabeledItems;
	
protected:
	void __fastcall CorrectAlign(Dxlayoutcontainer::TdxLayoutGroup* AGroup);
	virtual void __fastcall DoExecute(Vcl::Controls::TWinControl* AContainer, bool ARecursive = true);
	__property Dxlayoutcontrol::TdxCustomLayoutControl* Control = {read=FControl};
	__property bool Recursive = {read=FRecursive, nodefault};
	
public:
	__fastcall TdxAutoLayout(Dxlayoutcontrol::TdxCustomLayoutControl* AControl);
	void __fastcall Execute(Vcl::Controls::TWinControl* AContainer, bool ARecursive = true);
	__property bool ConvertPageControls = {read=FConvertPageControls, write=FConvertPageControls, default=1};
	__property System::Byte FocusControlDistanceX = {read=FFocusControlDistanceX, write=FFocusControlDistanceX, default=48};
	__property System::Byte FocusControlDistanceY = {read=FFocusControlDistanceY, write=FFocusControlDistanceY, default=16};
	__property bool SmartFindFocusControl = {read=FSmartFindFocusControl, write=FSmartFindFocusControl, default=1};
	__property bool UseLabeledItems = {read=FUseLabeledItems, write=FUseLabeledItems, default=1};
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TdxAutoLayout(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TfmImport;
class PASCALIMPLEMENTATION TfmImport : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Cxspinedit::TcxSpinEdit* seDeltaX;
	Cxspinedit::TcxSpinEdit* seDeltaY;
	Cxbuttons::TcxButton* btnImport;
	Cxbuttons::TcxButton* btnCancel;
	Cxdropdownedit::TcxComboBox* cbContainers;
	Cxcheckbox::TcxCheckBox* cbUseLabeledItems;
	Cxcheckbox::TcxCheckBox* cbAssociate;
	Cxcheckbox::TcxCheckBox* cbConvertPageControls;
	Dxlayoutcontainer::TdxLayoutGroup* dxLayoutControl1Group_Root;
	Dxlayoutcontrol::TdxLayoutControl* dxLayoutControl1;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item1;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item2;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item3;
	Dxlayoutcontainer::TdxLayoutGroup* dxLayoutControl1Group2;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item4;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item5;
	Dxlayoutcontainer::TdxLayoutGroup* dxLayoutControl1Group4;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item6;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item7;
	Dxlayoutcontainer::TdxLayoutItem* dxLayoutControl1Item8;
	Dxlayoutcontainer::TdxLayoutLabeledItem* dxLayoutControl1LabeledItem1;
	Dxlayoutcontainer::TdxLayoutLabeledItem* dxLayoutControl1LabeledItem2;
	Dxlayoutcontainer::TdxLayoutGroup* dxLayoutControl1Group5;
	Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* dxLayoutLookAndFeelList1;
	Dxlayoutlookandfeels::TdxLayoutCxLookAndFeel* dxLayoutCxLookAndFeel2;
	void __fastcall cbAssociateClick(System::TObject* Sender);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfmImport(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfmImport(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfmImport(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfmImport(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


//-- var, const, procedure ---------------------------------------------------
extern PACKAGE void __fastcall ImportLayout(Dxlayoutcontrol::TdxLayoutControl* ALayoutControl, bool ADefaultImport = false);
}	/* namespace Dxlayoutimport */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DXLAYOUTIMPORT)
using namespace Dxlayoutimport;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// DxlayoutimportHPP
