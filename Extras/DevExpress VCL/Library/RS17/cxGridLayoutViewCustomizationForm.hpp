// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridLayoutViewCustomizationForm.pas' rev: 24.00 (Win32)

#ifndef CxgridlayoutviewcustomizationformHPP
#define CxgridlayoutviewcustomizationformHPP

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
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <Vcl.ComCtrls.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.ActnList.hpp>	// Pascal unit
#include <Vcl.Dialogs.hpp>	// Pascal unit
#include <Vcl.Menus.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxLookAndFeels.hpp>	// Pascal unit
#include <cxCheckBox.hpp>	// Pascal unit
#include <cxButtons.hpp>	// Pascal unit
#include <cxTreeView.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxContainer.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <dxLayoutPainters.hpp>	// Pascal unit
#include <dxLayoutCommon.hpp>	// Pascal unit
#include <dxLayoutCustomizeForm.hpp>	// Pascal unit
#include <dxLayoutControlAdapters.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <dxLayoutcxEditAdapters.hpp>	// Pascal unit
#include <dxLayoutControl.hpp>	// Pascal unit
#include <cxGridLayoutView.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGridLevel.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridlayoutviewcustomizationform
{
//-- type declarations -------------------------------------------------------
class DELPHICLASS TcxGridLayoutViewCustomizationFormGroupViewInfo;
class DELPHICLASS TcxGridLayoutViewCustomizationFormLayoutLookAndFeel;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLayoutViewCustomizationFormGroupViewInfo : public Dxlayoutpainters::TdxLayoutGroupCxLookAndFeelViewInfo
{
	typedef Dxlayoutpainters::TdxLayoutGroupCxLookAndFeelViewInfo inherited;
	
private:
	TcxGridLayoutViewCustomizationFormLayoutLookAndFeel* __fastcall GetGridLayoutViewLayoutLookAndFeel(void);
	int __fastcall GetRootOffset(void);
	
protected:
	virtual int __fastcall CalculateOffset(Dxlayoutcommon::TdxLayoutSide ASide);
	virtual System::Types::TRect __fastcall CalculatePadding(void);
	virtual int __fastcall GetSelectionBoundsOffset(void);
	virtual bool __fastcall HasCaption(void);
	__property TcxGridLayoutViewCustomizationFormLayoutLookAndFeel* LayoutLookAndFeel = {read=GetGridLayoutViewLayoutLookAndFeel};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewCustomizationFormGroupViewInfo(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AContainerViewInfo, Dxlayoutcontainer::TdxLayoutGroupViewInfo* AParentViewInfo, Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : Dxlayoutpainters::TdxLayoutGroupCxLookAndFeelViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewCustomizationFormGroupViewInfo(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridLayoutViewCustomizationFormGroupPainter;
#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLayoutViewCustomizationFormGroupPainter : public Dxlayoutpainters::TdxLayoutGroupCxLookAndFeelPainter
{
	typedef Dxlayoutpainters::TdxLayoutGroupCxLookAndFeelPainter inherited;
	
protected:
	virtual bool __fastcall CanDrawBorders(void);
	virtual bool __fastcall CanDrawCaption(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TcxGridLayoutViewCustomizationFormGroupPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : Dxlayoutpainters::TdxLayoutGroupCxLookAndFeelPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewCustomizationFormGroupPainter(void) { }
	
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TcxGridLayoutViewCustomizationFormLayoutLookAndFeel : public Cxgridlayoutview::TcxGridLayoutLookAndFeel
{
	typedef Cxgridlayoutview::TcxGridLayoutLookAndFeel inherited;
	
public:
	virtual System::TClass __fastcall GetGroupPainterClass(void);
	virtual System::TClass __fastcall GetGroupViewInfoClass(void);
public:
	/* TcxGridLayoutLookAndFeel.Create */ inline __fastcall virtual TcxGridLayoutViewCustomizationFormLayoutLookAndFeel(Cxgridlayoutview::TcxGridLayoutView* AGridView) : Cxgridlayoutview::TcxGridLayoutLookAndFeel(AGridView) { }
	
public:
	/* TdxCustomLayoutLookAndFeel.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewCustomizationFormLayoutLookAndFeel(void) { }
	
};

#pragma pack(pop)

class DELPHICLASS TcxGridViewLayoutContainer;
class PASCALIMPLEMENTATION TcxGridViewLayoutContainer : public Dxlayoutcontrol::TdxLayoutControlContainer
{
	typedef Dxlayoutcontrol::TdxLayoutControlContainer inherited;
	
protected:
	virtual System::Types::TRect __fastcall CalculateCustomizeFormBounds(const System::Types::TRect &AFormBounds);
	virtual void __fastcall CreateCustomizeForm(void);
	virtual Dxlayoutcontainer::TdxLayoutControlCustomCustomizeForm* __fastcall GetCustomizeForm(void);
	virtual Dxlayoutcontainer::TdxLayoutContainerViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall DestroyCustomizeForm(void);
	virtual void __fastcall ShowCustomizeForm(void);
public:
	/* TdxLayoutControlContainer.Create */ inline __fastcall virtual TcxGridViewLayoutContainer(Dxlayoutcontrol::TdxCustomLayoutControl* AControl) : Dxlayoutcontrol::TdxLayoutControlContainer(AControl) { }
	
public:
	/* TdxLayoutContainer.Destroy */ inline __fastcall virtual ~TcxGridViewLayoutContainer(void) { }
	
};


class DELPHICLASS TcxGridViewLayoutControl;
class PASCALIMPLEMENTATION TcxGridViewLayoutControl : public Dxlayoutcontrol::TdxLayoutControl
{
	typedef Dxlayoutcontrol::TdxLayoutControl inherited;
	
private:
	HIDESBASE TcxGridViewLayoutContainer* __fastcall GetContainer(void);
	HIDESBASE Cxgridlayoutview::TcxGridLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	HIDESBASE void __fastcall SetLayoutLookAndFeel(Cxgridlayoutview::TcxGridLayoutLookAndFeel* Value);
	
protected:
	virtual Dxlayoutcontrol::TdxLayoutControlContainerClass __fastcall GetContainerClass(void);
	
public:
	__fastcall virtual TcxGridViewLayoutControl(System::Classes::TComponent* AOwner);
	__property TcxGridViewLayoutContainer* Container = {read=GetContainer};
	
__published:
	__property Cxgridlayoutview::TcxGridLayoutLookAndFeel* LayoutLookAndFeel = {read=GetLayoutLookAndFeel, write=SetLayoutLookAndFeel};
public:
	/* TdxCustomLayoutControl.Destroy */ inline __fastcall virtual ~TcxGridViewLayoutControl(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridViewLayoutControl(HWND ParentWindow) : Dxlayoutcontrol::TdxLayoutControl(ParentWindow) { }
	
};


class DELPHICLASS TcxGridLayoutViewCustomizationForm;
class PASCALIMPLEMENTATION TcxGridLayoutViewCustomizationForm : public Dxlayoutcustomizeform::TdxLayoutControlCustomizeForm
{
	typedef Dxlayoutcustomizeform::TdxLayoutControlCustomizeForm inherited;
	
__published:
	Dxlayoutcontainer::TdxLayoutItem* liGridViewContainer;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainGroup5;
	Dxlayoutcontainer::TdxLayoutSplitterItem* lcMainSplitterItem1;
	Dxlayoutlookandfeels::TdxLayoutLookAndFeelList* dxLayoutLookAndFeelList1;
	Dxlayoutlookandfeels::TdxLayoutCxLookAndFeel* llfMain;
	Vcl::Actnlist::TAction* acCancel;
	Vcl::Actnlist::TAction* acOk;
	Cxbuttons::TcxButton* btnOk;
	Dxlayoutcontainer::TdxLayoutItem* liOk;
	Cxbuttons::TcxButton* btnCancel;
	Dxlayoutcontainer::TdxLayoutItem* liCancel;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainTemplateCardGroup;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainTabbedGroup;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainViewLayoutGroup;
	Cxgrid::TcxGrid* gMain;
	Dxlayoutcontainer::TdxLayoutItem* lcMainItem16;
	Cxcheckbox::TcxCheckBox* cbSaveData;
	Dxlayoutcontainer::TdxLayoutItem* liSaveData;
	Dxlayoutcontainer::TdxLayoutGroup* lcMainGroup4;
	Cxcheckbox::TcxCheckBox* cbSaveLayout;
	Dxlayoutcontainer::TdxLayoutItem* liSaveLayout;
	void __fastcall acOkExecute(System::TObject* Sender);
	void __fastcall acCancelExecute(System::TObject* Sender);
	void __fastcall FormCloseQuery(System::TObject* Sender, bool &CanClose);
	void __fastcall lcMainTabbedGroupTabChanged(System::TObject* Sender);
	HIDESBASE void __fastcall FormShortCut(Winapi::Messages::TWMKey &Msg, bool &Handled);
	HIDESBASE void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	
private:
	Cxgridlayoutview::TcxGridLayoutViewController* FController;
	TcxGridViewLayoutControl* FGridViewLayoutControl;
	TcxGridLayoutViewCustomizationFormLayoutLookAndFeel* FLayoutLookAndFeel;
	int FTreeViewWidth;
	Cxgridlayoutview::TcxGridLayoutView* FPreviewView;
	Cxgridcustomview::_di_IcxCustomGridDataController __fastcall GetDataControllerSupport(void);
	Cxgridlayoutview::TcxGridLayoutView* __fastcall GetGridView(void);
	Cxgridcustomview::_di_IcxGridViewLayoutEditorSupport __fastcall GetViewSupport(void);
	
protected:
	virtual void __fastcall Loaded(void);
	virtual void * __fastcall GetInfoData(void);
	virtual int __fastcall GetInfoDataSize(void);
	virtual void __fastcall SetInfoData(void * AData);
	virtual NativeUInt __fastcall GetWndParent(void);
	virtual void __fastcall Localize(void);
	virtual void __fastcall RefreshLayoutLookAndFeel(void);
	virtual void __fastcall CalculateTreeViewPopupActionVisibilities(void);
	void __fastcall Load(void);
	void __fastcall Save(void);
	void __fastcall GridViewChanged(void);
	Cxgridcustomview::TcxCustomGridController* __fastcall GetController(void);
	void __fastcall Initialize(Cxgridcustomview::TcxCustomGridController* AController);
	void __fastcall RefreshData(void);
	virtual void __fastcall CreateControls(void);
	virtual void __fastcall DoInitializeControl(void);
	bool __fastcall HasChanges(void);
	virtual void __fastcall InitializeGridViewLayout(void);
	bool __fastcall IsDataChangeable(void);
	bool __fastcall IsLayoutChangeable(void);
	virtual void __fastcall RefreshStoring(void);
	__property Cxgridlayoutview::TcxGridLayoutView* PreviewView = {read=FPreviewView};
	
public:
	__fastcall virtual TcxGridLayoutViewCustomizationForm(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TcxGridLayoutViewCustomizationForm(void);
	void __fastcall ApplyChanges(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutHitTest* __fastcall GetHitTest(const System::Types::TPoint &P);
	__property Cxgridlayoutview::TcxGridLayoutViewController* Controller = {read=FController};
	__property Cxgridcustomview::_di_IcxCustomGridDataController DataControllerSupport = {read=GetDataControllerSupport};
	__property Cxgridlayoutview::TcxGridLayoutView* GridView = {read=GetGridView};
	__property Cxgridcustomview::_di_IcxGridViewLayoutEditorSupport ViewSupport = {read=GetViewSupport};
public:
	/* TCustomForm.CreateNew */ inline __fastcall virtual TcxGridLayoutViewCustomizationForm(System::Classes::TComponent* AOwner, int Dummy) : Dxlayoutcustomizeform::TdxLayoutControlCustomizeForm(AOwner, Dummy) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridLayoutViewCustomizationForm(HWND ParentWindow) : Dxlayoutcustomizeform::TdxLayoutControlCustomizeForm(ParentWindow) { }
	
private:
	void *__IcxDialogMetricsInfoData;	/* Cxclasses::IcxDialogMetricsInfoData */
	void *__IcxGridCustomizationForm;	/* Cxgridcustomview::IcxGridCustomizationForm */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {DBFB3040-4677-4C9D-913C-45A1EE41E35A}
	operator Cxclasses::_di_IcxDialogMetricsInfoData()
	{
		Cxclasses::_di_IcxDialogMetricsInfoData intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxclasses::IcxDialogMetricsInfoData*(void) { return (Cxclasses::IcxDialogMetricsInfoData*)&__IcxDialogMetricsInfoData; }
	#endif
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {D702C868-B1BC-41B6-BDD0-5CF5030E03C3}
	operator Cxgridcustomview::_di_IcxGridCustomizationForm()
	{
		Cxgridcustomview::_di_IcxGridCustomizationForm intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Cxgridcustomview::IcxGridCustomizationForm*(void) { return (Cxgridcustomview::IcxGridCustomizationForm*)&__IcxGridCustomizationForm; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Cxgridlayoutviewcustomizationform */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDLAYOUTVIEWCUSTOMIZATIONFORM)
using namespace Cxgridlayoutviewcustomizationform;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridlayoutviewcustomizationformHPP
