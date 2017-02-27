// CodeGear C++Builder
// Copyright (c) 1995, 2012 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'cxGridLayoutView.pas' rev: 24.00 (Win64)

#ifndef CxgridlayoutviewHPP
#define CxgridlayoutviewHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <System.Variants.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit
#include <Vcl.Controls.hpp>	// Pascal unit
#include <System.Contnrs.hpp>	// Pascal unit
#include <Vcl.ImgList.hpp>	// Pascal unit
#include <Vcl.StdCtrls.hpp>	// Pascal unit
#include <dxCore.hpp>	// Pascal unit
#include <cxClasses.hpp>	// Pascal unit
#include <cxGraphics.hpp>	// Pascal unit
#include <cxControls.hpp>	// Pascal unit
#include <cxStyles.hpp>	// Pascal unit
#include <cxLookAndFeelPainters.hpp>	// Pascal unit
#include <cxGridCommon.hpp>	// Pascal unit
#include <cxGrid.hpp>	// Pascal unit
#include <dxCoreClasses.hpp>	// Pascal unit
#include <dxGDIPlusClasses.hpp>	// Pascal unit
#include <cxGridCustomView.hpp>	// Pascal unit
#include <cxGridCustomTableView.hpp>	// Pascal unit
#include <dxLayoutLookAndFeels.hpp>	// Pascal unit
#include <cxDataStorage.hpp>	// Pascal unit
#include <cxCustomData.hpp>	// Pascal unit
#include <cxEdit.hpp>	// Pascal unit
#include <dxLayoutContainer.hpp>	// Pascal unit
#include <cxGridCustomLayoutView.hpp>	// Pascal unit
#include <dxLayoutSelection.hpp>	// Pascal unit
#include <dxLayoutCommon.hpp>	// Pascal unit
#include <Vcl.Forms.hpp>	// Pascal unit
#include <cxNavigator.hpp>	// Pascal unit
#include <System.Types.hpp>	// Pascal unit
#include <System.UITypes.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Cxgridlayoutview
{
//-- type declarations -------------------------------------------------------
typedef System::TMetaClass* TcxGridLayoutItemEditPainterClass;

class DELPHICLASS TcxGridViewLayoutItemCaptionPainter;
class PASCALIMPLEMENTATION TcxGridViewLayoutItemCaptionPainter : public Dxlayoutcontainer::TdxCustomLayoutItemCaptionPainter
{
	typedef Dxlayoutcontainer::TdxCustomLayoutItemCaptionPainter inherited;
	
protected:
	virtual void __fastcall DrawBackground(void);
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TcxGridViewLayoutItemCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : Dxlayoutcontainer::TdxCustomLayoutItemCaptionPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridViewLayoutItemCaptionPainter(void) { }
	
};


class DELPHICLASS TcxGridLayoutItemEditPainter;
class DELPHICLASS TcxGridLayoutItemEditViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutItemEditPainter : public Dxlayoutcontainer::TdxLayoutControlItemControlPainter
{
	typedef Dxlayoutcontainer::TdxLayoutControlItemControlPainter inherited;
	
private:
	HIDESBASE TcxGridLayoutItemEditViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall CanDrawEdit(void);
	virtual void __fastcall DoDrawEdit(void);
	void __fastcall DrawEdit(void);
	
public:
	virtual void __fastcall Paint(void);
	__property TcxGridLayoutItemEditViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TcxGridLayoutItemEditPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : Dxlayoutcontainer::TdxLayoutControlItemControlPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutItemEditPainter(void) { }
	
};


class DELPHICLASS TcxGridLayoutItemPainter;
class DELPHICLASS TcxGridLayoutItemViewInfo;
class DELPHICLASS TcxGridLayoutViewItemViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutItemPainter : public Dxlayoutcontainer::TdxLayoutControlItemPainter
{
	typedef Dxlayoutcontainer::TdxLayoutControlItemPainter inherited;
	
private:
	HIDESBASE TcxGridLayoutItemViewInfo* __fastcall GetViewInfo(void);
	TcxGridLayoutViewItemViewInfo* __fastcall GetGridItemViewInfo(void);
	
protected:
	virtual bool __fastcall CanPaint(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionPainterClass __fastcall GetCaptionPainterClass(void);
	virtual Dxlayoutcontainer::TdxLayoutControlItemControlPainterClass __fastcall GetControlPainterClass(void);
	__property TcxGridLayoutViewItemViewInfo* GridItemViewInfo = {read=GetGridItemViewInfo};
	__property TcxGridLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TdxCustomLayoutElementPainter.Create */ inline __fastcall virtual TcxGridLayoutItemPainter(Cxgraphics::TcxCanvas* ACanvas, Dxlayoutcontainer::TdxCustomLayoutElementViewInfo* AViewInfo) : Dxlayoutcontainer::TdxLayoutControlItemPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutItemPainter(void) { }
	
};


class DELPHICLASS TcxGridLayoutItem;
class DELPHICLASS TcxGridLayoutView;
class PASCALIMPLEMENTATION TcxGridLayoutItemEditViewInfo : public Dxlayoutcontainer::TdxLayoutControlItemControlViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutControlItemControlViewInfo inherited;
	
private:
	int FDataHeight;
	TcxGridLayoutViewItemViewInfo* __fastcall GetDataViewInfo(void);
	HIDESBASE TcxGridLayoutItem* __fastcall GetItem(void);
	HIDESBASE TcxGridLayoutItemViewInfo* __fastcall GetItemViewInfo(void);
	TcxGridLayoutView* __fastcall GetGridView(void);
	
protected:
	int __fastcall GetDefaultValueHeight(void);
	int __fastcall GetValueHeight(void);
	virtual System::Types::TSize __fastcall GetOriginalControlSize(void);
	virtual bool __fastcall HasBorder(void);
	__property TcxGridLayoutViewItemViewInfo* DataViewInfo = {read=GetDataViewInfo};
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	__property TcxGridLayoutItemViewInfo* ItemViewInfo = {read=GetItemViewInfo};
	__property TcxGridLayoutItem* Item = {read=GetItem};
	
public:
	virtual int __fastcall CalculateMinHeight(void);
	virtual int __fastcall CalculateMinWidth(void);
	virtual void __fastcall CalculateInternalTabOrder(int &AAvailTabOrder);
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TcxGridLayoutItemEditViewInfo(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AItemViewInfo) : Dxlayoutcontainer::TdxLayoutControlItemControlViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutItemEditViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutItemCaptionViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutItemCaptionViewInfo : public Dxlayoutcontainer::TdxLayoutControlItemCaptionViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutControlItemCaptionViewInfo inherited;
	
private:
	HIDESBASE TcxGridLayoutItem* __fastcall GetItem(void);
	HIDESBASE TcxGridLayoutItemViewInfo* __fastcall GetItemViewInfo(void);
	
protected:
	virtual System::Types::TRect __fastcall CalculatePadding(void);
	virtual System::Uitypes::TColor __fastcall GetTextColor(void);
	__property TcxGridLayoutItem* Item = {read=GetItem};
	__property TcxGridLayoutItemViewInfo* ItemViewInfo = {read=GetItemViewInfo};
public:
	/* TdxCustomLayoutItemElementViewInfo.Create */ inline __fastcall virtual TcxGridLayoutItemCaptionViewInfo(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AItemViewInfo) : Dxlayoutcontainer::TdxLayoutControlItemCaptionViewInfo(AItemViewInfo) { }
	/* TdxCustomLayoutItemElementViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutItemCaptionViewInfo(void) { }
	
};


class DELPHICLASS TcxGridCustomLayoutContainerViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutItemViewInfo : public Dxlayoutcontainer::TdxLayoutControlItemViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutControlItemViewInfo inherited;
	
private:
	TcxGridLayoutViewItemViewInfo* FGridItemViewInfo;
	TcxGridLayoutItemEditViewInfo* __fastcall GetControlViewInfo(void);
	HIDESBASE TcxGridLayoutItem* __fastcall GetItem(void);
	TcxGridCustomLayoutContainerViewInfo* __fastcall GetContainerViewInfo(void);
	TcxGridLayoutViewItemViewInfo* __fastcall GetGridItemViewInfo(void);
	
protected:
	virtual bool __fastcall GetActuallyVisible(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionViewInfoClass __fastcall GetCaptionViewInfoClass(void);
	virtual Dxlayoutcontainer::TdxLayoutControlItemControlViewInfoClass __fastcall GetControlViewInfoClass(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemPainterClass __fastcall GetPainterClass(void);
	void __fastcall SetGridItemViewInfo(void);
	__property TcxGridLayoutItem* Item = {read=GetItem};
	
public:
	__property TcxGridCustomLayoutContainerViewInfo* ContainerViewInfo = {read=GetContainerViewInfo};
	__property TcxGridLayoutItemEditViewInfo* ControlViewInfo = {read=GetControlViewInfo};
	__property TcxGridLayoutViewItemViewInfo* GridItemViewInfo = {read=GetGridItemViewInfo};
public:
	/* TdxCustomLayoutItemViewInfo.Create */ inline __fastcall virtual TcxGridLayoutItemViewInfo(Dxlayoutcontainer::TdxLayoutContainerViewInfo* AContainerViewInfo, Dxlayoutcontainer::TdxLayoutGroupViewInfo* AParentViewInfo, Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : Dxlayoutcontainer::TdxLayoutControlItemViewInfo(AContainerViewInfo, AParentViewInfo, AItem) { }
	/* TdxCustomLayoutItemViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutItemViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutItemCaptionOptions;
class PASCALIMPLEMENTATION TcxGridLayoutItemCaptionOptions : public Dxlayoutcontainer::TdxLayoutLabeledItemCustomCaptionOptions
{
	typedef Dxlayoutcontainer::TdxLayoutLabeledItemCustomCaptionOptions inherited;
	
private:
	System::UnicodeString FGridItemCaption;
	TcxGridLayoutItem* __fastcall GetItem(void);
	
protected:
	virtual bool __fastcall IsTextStored(void);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall SetText(const System::UnicodeString Value);
	__property System::UnicodeString GridItemCaption = {read=FGridItemCaption, write=FGridItemCaption};
	
public:
	__property TcxGridLayoutItem* Item = {read=GetItem};
	
__published:
	__property AlignHorz = {default=0};
	__property AlignVert = {default=1};
	__property Glyph;
	__property ImageIndex = {default=-1};
	__property Layout = {default=0};
	__property Visible = {default=1};
	__property VisibleElements = {default=3};
	__property Width = {default=0};
public:
	/* TdxLayoutLabeledItemCustomCaptionOptions.Create */ inline __fastcall virtual TcxGridLayoutItemCaptionOptions(Dxlayoutcontainer::TdxCustomLayoutItem* AItem) : Dxlayoutcontainer::TdxLayoutLabeledItemCustomCaptionOptions(AItem) { }
	
public:
	/* TdxCustomLayoutItemCaptionOptions.Destroy */ inline __fastcall virtual ~TcxGridLayoutItemCaptionOptions(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewItem;
class DELPHICLASS TcxGridLayoutContainer;
class PASCALIMPLEMENTATION TcxGridLayoutItem : public Dxlayoutcontainer::TdxLayoutControlItem
{
	typedef Dxlayoutcontainer::TdxLayoutControlItem inherited;
	
private:
	TcxGridLayoutViewItem* FGridViewItem;
	System::UnicodeString FLoadedGridViewItemName;
	TcxGridLayoutContainer* __fastcall GetContainer(void);
	HIDESBASE TcxGridLayoutItemCaptionOptions* __fastcall GetCaptionOptions(void);
	HIDESBASE TcxGridLayoutItemViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE void __fastcall SetContainer(TcxGridLayoutContainer* Value);
	HIDESBASE void __fastcall SetCaptionOptions(TcxGridLayoutItemCaptionOptions* Value);
	void __fastcall SetGridViewItem(TcxGridLayoutViewItem* Value);
	
protected:
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetStoredPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetStoredPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual bool __fastcall CanDelete(void);
	virtual void __fastcall CustomizationChanged(void);
	__classmethod virtual Dxlayoutcontainer::TdxCustomLayoutItemCaptionOptionsClass __fastcall GetCaptionOptionsClass();
	virtual System::UnicodeString __fastcall GetBaseName(void);
	virtual System::UnicodeString __fastcall GetInplaceRenameCaption(void);
	TcxGridLayoutItem* __fastcall GetObjectForSelect(void);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall HasControl(void);
	virtual bool __fastcall IsVisibleForCustomization(void);
	virtual void __fastcall SetInplaceRenameCaption(const System::UnicodeString ACaption);
	__property System::UnicodeString LoadedGridViewItemName = {read=FLoadedGridViewItemName};
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall BeforeDestruction(void);
	__property TcxGridLayoutContainer* Container = {read=GetContainer, write=SetContainer};
	__property TcxGridLayoutViewItem* GridViewItem = {read=FGridViewItem, write=SetGridViewItem};
	__property TcxGridLayoutItemViewInfo* ViewInfo = {read=GetViewInfo};
	
__published:
	__property TcxGridLayoutItemCaptionOptions* CaptionOptions = {read=GetCaptionOptions, write=SetCaptionOptions};
public:
	/* TdxCustomLayoutItem.Create */ inline __fastcall virtual TcxGridLayoutItem(System::Classes::TComponent* AOwner) : Dxlayoutcontainer::TdxLayoutControlItem(AOwner) { }
	/* TdxCustomLayoutItem.Destroy */ inline __fastcall virtual ~TcxGridLayoutItem(void) { }
	
};


class DELPHICLASS TcxLayoutViewLookAndFeelItemPadding;
class PASCALIMPLEMENTATION TcxLayoutViewLookAndFeelItemPadding : public Dxlayoutlookandfeels::TdxLayoutLookAndFeelPadding
{
	typedef Dxlayoutlookandfeels::TdxLayoutLookAndFeelPadding inherited;
	
protected:
	virtual int __fastcall GetDefaultValue(int Index);
public:
	/* TdxCustomLayoutLookAndFeelPart.Create */ inline __fastcall virtual TcxLayoutViewLookAndFeelItemPadding(Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* ALookAndFeel) : Dxlayoutlookandfeels::TdxLayoutLookAndFeelPadding(ALookAndFeel) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxLayoutViewLookAndFeelItemPadding(void) { }
	
};


class DELPHICLASS TcxLayoutLayoutViewLookAndFeelItemOptions;
class PASCALIMPLEMENTATION TcxLayoutLayoutViewLookAndFeelItemOptions : public Dxlayoutlookandfeels::TdxLayoutLookAndFeelItemOptions
{
	typedef Dxlayoutlookandfeels::TdxLayoutLookAndFeelItemOptions inherited;
	
protected:
	virtual Dxlayoutlookandfeels::TdxLayoutLookAndFeelPaddingClass __fastcall GetPaddingClass(void);
public:
	/* TdxLayoutLookAndFeelItemOptions.Create */ inline __fastcall virtual TcxLayoutLayoutViewLookAndFeelItemOptions(Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* ALookAndFeel) : Dxlayoutlookandfeels::TdxLayoutLookAndFeelItemOptions(ALookAndFeel) { }
	
public:
	/* TdxCustomLayoutLookAndFeelOptions.Destroy */ inline __fastcall virtual ~TcxLayoutLayoutViewLookAndFeelItemOptions(void) { }
	
};


class DELPHICLASS TcxGridLayoutLookAndFeel;
class PASCALIMPLEMENTATION TcxGridLayoutLookAndFeel : public Dxlayoutlookandfeels::TdxLayoutCxLookAndFeel
{
	typedef Dxlayoutlookandfeels::TdxLayoutCxLookAndFeel inherited;
	
private:
	TcxGridLayoutView* FGridView;
	
protected:
	virtual Dxlayoutlookandfeels::TdxLayoutLookAndFeelItemOptionsClass __fastcall GetItemOptionsClass(void);
	
public:
	__fastcall virtual TcxGridLayoutLookAndFeel(TcxGridLayoutView* AGridView);
	__property TcxGridLayoutView* GridView = {read=FGridView};
public:
	/* TdxCustomLayoutLookAndFeel.Destroy */ inline __fastcall virtual ~TcxGridLayoutLookAndFeel(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridCustomLayoutContainerViewInfo : public Dxlayoutcontainer::TdxLayoutContainerViewInfo
{
	typedef Dxlayoutcontainer::TdxLayoutContainerViewInfo inherited;
	
protected:
	virtual bool __fastcall CanUseCachedInfo(void);
	virtual TcxGridLayoutViewItemViewInfo* __fastcall GetGridItemViewInfo(TcxGridLayoutItemViewInfo* AViewInfo);
	void __fastcall PopulateTabOrderList(System::Classes::TList* AList);
public:
	/* TdxLayoutContainerViewInfo.Create */ inline __fastcall virtual TcxGridCustomLayoutContainerViewInfo(Dxlayoutcontainer::TdxLayoutContainer* AContainer) : Dxlayoutcontainer::TdxLayoutContainerViewInfo(AContainer) { }
	/* TdxLayoutContainerViewInfo.Destroy */ inline __fastcall virtual ~TcxGridCustomLayoutContainerViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutContainerViewInfo;
class DELPHICLASS TcxGridLayoutViewRecordViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutContainerViewInfo : public TcxGridCustomLayoutContainerViewInfo
{
	typedef TcxGridCustomLayoutContainerViewInfo inherited;
	
private:
	TcxGridLayoutViewRecordViewInfo* FRecordViewInfo;
	
protected:
	virtual void __fastcall DestroyViewInfos(void);
	virtual TcxGridLayoutViewItemViewInfo* __fastcall GetGridItemViewInfo(TcxGridLayoutItemViewInfo* AViewInfo);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetItemLayoutLookAndFeel(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeelOptions* __fastcall GetItemOptions(Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* AViewInfo);
	virtual Dxlayoutlookandfeels::TdxCustomLayoutLookAndFeel* __fastcall GetLayoutLookAndFeel(void);
	virtual bool __fastcall IsClone(void);
	
public:
	__fastcall virtual TcxGridLayoutContainerViewInfo(Dxlayoutcontainer::TdxLayoutContainer* AContainer, TcxGridLayoutViewRecordViewInfo* ARecordViewInfo);
	virtual Dxlayoutcontainer::TdxCustomLayoutItemViewInfo* __fastcall GetItemViewInfo(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
	__property TcxGridLayoutViewRecordViewInfo* RecordViewInfo = {read=FRecordViewInfo};
public:
	/* TdxLayoutContainerViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutContainerViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutContainerFocusController;
class PASCALIMPLEMENTATION TcxGridLayoutContainerFocusController : public Dxlayoutcontainer::TdxLayoutContainerFocusController
{
	typedef Dxlayoutcontainer::TdxLayoutContainerFocusController inherited;
	
protected:
	virtual bool __fastcall IsFocused(Dxlayoutcontainer::TdxCustomLayoutItem* AItem);
public:
	/* TdxLayoutContainerFocusController.Create */ inline __fastcall virtual TcxGridLayoutContainerFocusController(Dxlayoutcontainer::TdxLayoutContainer* AContainer) : Dxlayoutcontainer::TdxLayoutContainerFocusController(AContainer) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridLayoutContainerFocusController(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridLayoutContainer : public Dxlayoutcontainer::TdxLayoutContainer
{
	typedef Dxlayoutcontainer::TdxLayoutContainer inherited;
	
private:
	TcxGridLayoutView* __fastcall GetGridView(void);
	TcxGridLayoutContainerViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AfterRestoring(void);
	virtual void __fastcall CalculateRootAlignment(void);
	virtual void __fastcall DoCalculateRoot(bool ANeedPack);
	virtual void __fastcall DoInitialize(void);
	virtual Dxlayoutcontainer::TdxLayoutContainerFocusControllerClass __fastcall GetFocusControllerClass(void);
	virtual Vcl::Imglist::TCustomImageList* __fastcall GetImages(void);
	virtual Dxlayoutcontainer::TdxLayoutContainerViewInfoClass __fastcall GetViewInfoClass(void);
	virtual bool __fastcall IsCustomization(void);
	virtual Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	virtual System::Types::TRect __fastcall GetClientBounds(void);
	virtual System::Types::TRect __fastcall GetClientRect(void);
	virtual Vcl::Graphics::TFont* __fastcall GetDefaultFont(void);
	virtual System::Classes::TComponent* __fastcall GetItemsOwner(void);
	virtual Cxcontrols::TcxControl* __fastcall GetItemsParent(void);
	virtual System::Classes::TComponent* __fastcall GetItemsParentComponent(void);
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	__property TcxGridLayoutContainerViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	__property MenuItems;
public:
	/* TdxLayoutContainer.Create */ inline __fastcall virtual TcxGridLayoutContainer(System::Classes::TComponent* AOwner) : Dxlayoutcontainer::TdxLayoutContainer(AOwner) { }
	/* TdxLayoutContainer.Destroy */ inline __fastcall virtual ~TcxGridLayoutContainer(void) { }
	
};


typedef System::TMetaClass* TcxGridLayoutContainerClass;

enum TcxGridLayoutViewRecordExpandButtonAlignment : unsigned char { rebaLeft, rebaRight };

class DELPHICLASS TcxGridLayoutViewItemFilterButtonHitTest;
class PASCALIMPLEMENTATION TcxGridLayoutViewItemFilterButtonHitTest : public Cxgridcustomtableview::TcxGridRecordCellHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordCellHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
	
public:
	__classmethod virtual bool __fastcall CanClick();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewItemFilterButtonHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridLayoutViewItemFilterButtonHitTest(void) : Cxgridcustomtableview::TcxGridRecordCellHitTest() { }
	
};


class DELPHICLASS TcxGridLayoutViewItemHitTest;
class PASCALIMPLEMENTATION TcxGridLayoutViewItemHitTest : public Cxgridcustomtableview::TcxGridRecordCellHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordCellHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewItemHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridLayoutViewItemHitTest(void) : Cxgridcustomtableview::TcxGridRecordCellHitTest() { }
	
};


class DELPHICLASS TcxGridLayoutViewRecordCaptionHitTest;
class PASCALIMPLEMENTATION TcxGridLayoutViewRecordCaptionHitTest : public Cxgridcustomtableview::TcxGridRecordHitTest
{
	typedef Cxgridcustomtableview::TcxGridRecordHitTest inherited;
	
protected:
	__classmethod virtual int __fastcall GetHitTestCode();
public:
	/* TcxCustomGridHitTest.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordCaptionHitTest(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TcxGridLayoutViewRecordCaptionHitTest(void) : Cxgridcustomtableview::TcxGridRecordHitTest() { }
	
};


class DELPHICLASS TcxGridLayoutViewItemFilterButtonPainter;
class DELPHICLASS TcxGridLayoutViewItemFilterButtonViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewItemFilterButtonPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridLayoutViewItemFilterButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridLayoutViewItemFilterButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridLayoutViewItemFilterButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewItemFilterButtonPainter(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewItemPainter;
class PASCALIMPLEMENTATION TcxGridLayoutViewItemPainter : public Cxgridcustomtableview::TcxGridTableDataCellPainter
{
	typedef Cxgridcustomtableview::TcxGridTableDataCellPainter inherited;
	
private:
	HIDESBASE TcxGridLayoutViewItemViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual void __fastcall DrawContent(void);
	virtual void __fastcall DrawText(void);
	virtual System::Types::TRect __fastcall GetFocusRect(void);
	__property TcxGridLayoutViewItemViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridLayoutViewItemPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomtableview::TcxGridTableDataCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewItemPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};


class DELPHICLASS TcxGridLayoutViewRecordExpandButtonPainter;
class DELPHICLASS TcxGridLayoutViewRecordExpandButtonViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewRecordExpandButtonPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridLayoutViewRecordExpandButtonViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall Paint(void);
	__property TcxGridLayoutViewRecordExpandButtonViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridLayoutViewRecordExpandButtonPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordExpandButtonPainter(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewRecordCaptionPainter;
class DELPHICLASS TcxGridLayoutViewRecordCaptionViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewRecordCaptionPainter : public Cxgridcustomview::TcxCustomGridCellPainter
{
	typedef Cxgridcustomview::TcxCustomGridCellPainter inherited;
	
private:
	TcxGridLayoutViewRecordCaptionViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual void __fastcall DrawText(void);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	__property TcxGridLayoutViewRecordCaptionViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridLayoutViewRecordCaptionPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomview::TcxCustomGridCellPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordCaptionPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};


class DELPHICLASS TcxGridLayoutViewRecordPainter;
class PASCALIMPLEMENTATION TcxGridLayoutViewRecordPainter : public Cxgridcustomtableview::TcxCustomGridRecordPainter
{
	typedef Cxgridcustomtableview::TcxCustomGridRecordPainter inherited;
	
private:
	Cxgraphics::TcxRegion* FClipRegion;
	HIDESBASE TcxGridLayoutViewRecordViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual void __fastcall AfterPaint(void);
	virtual void __fastcall BeforePaint(void);
	virtual bool __fastcall CanDrawBackground(void);
	virtual bool __fastcall CanDrawExpandButton(void);
	virtual void __fastcall DrawBackground(void)/* overload */;
	virtual void __fastcall DrawLayoutGroups(void);
	virtual void __fastcall DrawRecordBorder(void);
	virtual void __fastcall DrawRecordCaption(void);
	virtual void __fastcall DrawExpandButton(void);
	virtual bool __fastcall DrawExpandButtonBeforePaint(void);
	virtual void __fastcall DrawItems(void);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetState(void);
	bool __fastcall IsRecordExpanded(void);
	virtual void __fastcall Paint(void);
	__property TcxGridLayoutViewRecordViewInfo* ViewInfo = {read=GetViewInfo};
public:
	/* TcxCustomGridCellPainter.Create */ inline __fastcall virtual TcxGridLayoutViewRecordPainter(Cxgraphics::TcxCanvas* ACanvas, Cxgridcustomview::TcxCustomGridCellViewInfo* AViewInfo) : Cxgridcustomtableview::TcxCustomGridRecordPainter(ACanvas, AViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordPainter(void) { }
	
/* Hoisted overloads: */
	
protected:
	inline void __fastcall  DrawBackground(const System::Types::TRect &R){ Cxgridcustomview::TcxCustomGridCellPainter::DrawBackground(R); }
	
};


class DELPHICLASS TcxGridLayoutViewPainter;
class PASCALIMPLEMENTATION TcxGridLayoutViewPainter : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewPainter
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewPainter inherited;
	
public:
	/* TcxGridViewHandler.Create */ inline __fastcall virtual TcxGridLayoutViewPainter(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewPainter(AGridView) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewPainter(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewViewData;
class PASCALIMPLEMENTATION TcxGridLayoutViewViewData : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewData
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewData inherited;
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridRecordClass __fastcall GetRecordClass(const Cxcustomdata::TcxRowInfo &ARecordInfo);
public:
	/* TcxCustomGridTableViewData.Create */ inline __fastcall virtual TcxGridLayoutViewViewData(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewData(AGridView) { }
	/* TcxCustomGridTableViewData.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewViewData(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridLayoutViewItemFilterButtonViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewItemFilterButtonViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewItemFilterButtonViewInfo inherited;
	
private:
	TcxGridLayoutViewItemViewInfo* FItemViewInfo;
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	
protected:
	virtual Cxgridcustomtableview::TcxCustomGridTableItem* __fastcall GetItem(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual System::Types::TRect __fastcall GetDropDownWindowOwnerBounds(void);
	__property TcxGridLayoutViewItemViewInfo* ItemViewInfo = {read=FItemViewInfo};
	
public:
	__fastcall virtual TcxGridLayoutViewItemFilterButtonViewInfo(TcxGridLayoutViewItemViewInfo* ALayoutViewItemViewInfo);
	__property TcxGridLayoutView* GridView = {read=GetGridView};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewItemFilterButtonViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridLayoutViewItemFilterButtonViewInfoClass;

class DELPHICLASS TcxGridLayoutViewRecord;
class PASCALIMPLEMENTATION TcxGridLayoutViewItemViewInfo : public Cxgridcustomtableview::TcxGridTableDataCellViewInfo
{
	typedef Cxgridcustomtableview::TcxGridTableDataCellViewInfo inherited;
	
private:
	TcxGridLayoutViewItemFilterButtonViewInfo* FFilterButtonViewInfo;
	TcxGridLayoutViewItem* FItem;
	TcxGridLayoutItemViewInfo* FLayoutItemViewInfo;
	TcxGridLayoutViewRecordViewInfo* FRecordViewInfo;
	void __fastcall CreateViewInfos(void);
	void __fastcall DestroyViewInfos(void);
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	HIDESBASE TcxGridLayoutViewRecord* __fastcall GetGridRecord(void);
	TcxGridLayoutItemViewInfo* __fastcall GetLayoutItemViewInfo(void);
	TcxGridLayoutViewRecordViewInfo* __fastcall GetRecordViewInfo(void);
	
protected:
	virtual void __fastcall CalculateEditViewInfo(Cxedit::TcxCustomEditViewInfo* AEditViewInfo, const System::Types::TPoint AMousePos);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual void __fastcall DoCalculateParams(void);
	virtual void __fastcall GetCaptionParams(Cxgraphics::TcxViewParams &AParams);
	virtual System::Types::TRect __fastcall GetDesignSelectionBounds(void);
	virtual System::Types::TSize __fastcall GetEditMinSize(Vcl::Graphics::TFont* AFont);
	virtual System::Types::TRect __fastcall GetEditViewDataBounds(void);
	virtual int __fastcall GetExtraCaptionPadding(void);
	virtual System::Types::TRect __fastcall GetFilterButtonBounds(void);
	virtual TcxGridLayoutViewItemFilterButtonViewInfoClass __fastcall GetFilterButtonViewInfoClass(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual Cxlookandfeelpainters::TcxButtonState __fastcall GetPaintState(void);
	virtual bool __fastcall GetIsDesignSelected(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetTransparent(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	virtual bool __fastcall HasFocusRect(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual bool __fastcall InvalidateOnStateChange(void);
	virtual bool __fastcall IsValueTransparent(void);
	virtual void __fastcall StateChanged(Cxgridcommon::TcxGridCellState APrevState);
	virtual bool __fastcall CanFocus(void);
	__property System::Types::TRect FilterButtonBounds = {read=GetFilterButtonBounds};
	__property TcxGridLayoutItemViewInfo* LayoutItemViewInfo = {read=GetLayoutItemViewInfo};
	
public:
	Cxgraphics::TcxViewParams CaptionParams;
	__fastcall virtual TcxGridLayoutViewItemViewInfo(TcxGridLayoutViewRecordViewInfo* ARecordViewInfo, TcxGridLayoutViewItem* AItem);
	__fastcall virtual ~TcxGridLayoutViewItemViewInfo(void);
	virtual void __fastcall Calculate(const System::Types::TRect &ABounds)/* overload */;
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	virtual bool __fastcall MouseDown(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	__property TcxGridLayoutViewRecord* GridRecord = {read=GetGridRecord};
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	__property TcxGridLayoutViewItem* Item = {read=FItem};
	__property TcxGridLayoutViewItemFilterButtonViewInfo* FilterButtonViewInfo = {read=FFilterButtonViewInfo};
	__property TcxGridLayoutViewRecordViewInfo* RecordViewInfo = {read=GetRecordViewInfo};
};


typedef System::TMetaClass* TcxGridLayoutViewItemViewInfoClass;

class PASCALIMPLEMENTATION TcxGridLayoutViewRecordExpandButtonViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridLayoutViewRecordViewInfo* FRecordViewInfo;
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CaptureMouseOnPress(void);
	virtual void __fastcall Click(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual bool __fastcall GetHotTrack(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall InitHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	
public:
	__fastcall virtual TcxGridLayoutViewRecordExpandButtonViewInfo(TcxGridLayoutViewRecordViewInfo* ARecordViewInfo);
	virtual bool __fastcall HasPoint(const System::Types::TPoint P);
	__property TcxGridLayoutViewRecordViewInfo* RecordViewInfo = {read=FRecordViewInfo};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordExpandButtonViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridLayoutViewRecordExpandButtonViewInfoClass;

class PASCALIMPLEMENTATION TcxGridLayoutViewRecordCaptionViewInfo : public Cxgridcustomview::TcxCustomGridViewCellViewInfo
{
	typedef Cxgridcustomview::TcxCustomGridViewCellViewInfo inherited;
	
private:
	TcxGridLayoutViewRecordViewInfo* FRecordViewInfo;
	TcxGridLayoutViewRecord* __fastcall GetGridRecord(void);
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	System::Types::TRect __fastcall GetRotatedTextBounds(void);
	HIDESBASE System::Types::TRect __fastcall GetTextBoundsValue(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall CustomDraw(Cxgraphics::TcxCanvas* ACanvas);
	virtual System::Classes::TAlignment __fastcall GetAlignmentHorz(void);
	virtual Cxclasses::TcxAlignmentVert __fastcall GetAlignmentVert(void);
	virtual Cxgridcustomview::TcxCustomGridHitTestClass __fastcall GetHitTestClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual bool __fastcall HasCustomDraw(void);
	bool __fastcall GetRotatedText(void);
	virtual System::Types::TRect __fastcall GetTextAreaBounds(void);
	virtual int __fastcall GetTextAttributes(bool AForPainting);
	virtual System::UnicodeString __fastcall GetText(void);
	virtual void __fastcall GetViewParams(Cxgraphics::TcxViewParams &AParams);
	virtual bool __fastcall GetVisible(void);
	
public:
	__fastcall virtual TcxGridLayoutViewRecordCaptionViewInfo(TcxGridLayoutViewRecordViewInfo* ARecordViewInfo);
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	__property TcxGridLayoutViewRecord* GridRecord = {read=GetGridRecord};
	__property TcxGridLayoutViewRecordViewInfo* RecordViewInfo = {read=FRecordViewInfo};
	__property bool RotatedText = {read=GetRotatedText, nodefault};
	__property System::Types::TRect TextBounds = {read=GetTextBoundsValue};
public:
	/* TcxCustomGridViewCellViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordCaptionViewInfo(void) { }
	
};


typedef System::TMetaClass* TcxGridLayoutViewRecordCaptionViewInfoClass;

class DELPHICLASS TcxGridLayoutViewRecordViewInfoCacheItem;
class PASCALIMPLEMENTATION TcxGridLayoutViewRecordViewInfoCacheItem : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoCacheItem
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoCacheItem inherited;
	
private:
	bool FIsRecordCaptionHeightAssigned;
	int FRecordCaptionHeight;
	HIDESBASE TcxGridLayoutViewRecord* __fastcall GetGridRecord(void);
	void __fastcall SetRecordCaptionHeight(int Value);
	
protected:
	void __fastcall UnassignHeightValues(void);
	__property TcxGridLayoutViewRecord* GridRecord = {read=GetGridRecord};
	
public:
	virtual void __fastcall UnassignValues(bool AKeepMaster);
	__property int RecordCaptionHeight = {read=FRecordCaptionHeight, write=SetRecordCaptionHeight, nodefault};
	__property bool IsRecordCaptionHeightAssigned = {read=FIsRecordCaptionHeightAssigned, write=FIsRecordCaptionHeightAssigned, nodefault};
public:
	/* TcxCustomGridViewInfoCacheItem.Create */ inline __fastcall virtual TcxGridLayoutViewRecordViewInfoCacheItem(Cxgridcustomview::TcxCustomGridViewInfoCache* AOwner, int AIndex) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoCacheItem(AOwner, AIndex) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordViewInfoCacheItem(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewViewInfo;
class DELPHICLASS TcxGridLayoutViewRecordsViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewRecordViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutRecordViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutRecordViewInfo inherited;
	
private:
	int FCalculatedCaptionHeight;
	TcxGridLayoutViewRecordCaptionViewInfo* FCaptionViewInfo;
	TcxGridLayoutViewRecordExpandButtonViewInfo* FExpandButtonViewInfo;
	bool FIsPixelScrollSizeCalculating;
	Cxclasses::TcxObjectList* FItemViewInfos;
	bool FLayoutCalculated;
	TcxGridLayoutContainerViewInfo* FLayoutViewInfo;
	TcxGridLayoutLookAndFeel* FLayoutLookAndFeel;
	HIDESBASE TcxGridLayoutViewRecordViewInfoCacheItem* __fastcall GetCacheItem(void);
	int __fastcall GetExpandButtonSizeValue(void);
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	HIDESBASE TcxGridLayoutViewViewInfo* __fastcall GetGridViewInfo(void);
	int __fastcall GetItemViewInfoCount(void);
	TcxGridLayoutViewItemViewInfo* __fastcall GetItemViewInfos(int Index);
	TcxGridLayoutViewRecord* __fastcall GetGridRecord(void);
	int __fastcall GetRecordBorderWidth(void);
	HIDESBASE TcxGridLayoutViewRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	
protected:
	virtual int __fastcall CalculateHeight(void);
	virtual int __fastcall CalculateWidth(void);
	virtual bool __fastcall HasFocusRect(void);
	virtual int __fastcall GetHeight(void);
	virtual int __fastcall GetPixelScrollSize(void);
	virtual int __fastcall GetWidth(void);
	virtual bool __fastcall GetTransparent(void);
	virtual bool __fastcall GetVisible(void);
	virtual void __fastcall CalculateExpandButtonBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall CanGenerateExpandButtonHitTest(void);
	virtual TcxGridLayoutViewRecordExpandButtonAlignment __fastcall GetExpandButtonAlignment(void);
	virtual System::Types::TRect __fastcall GetExpandButtonAreaBounds(void);
	virtual int __fastcall GetExpandButtonAreaWidth(void);
	virtual int __fastcall CalculateRecordCaptionHeight(void);
	virtual bool __fastcall CanGetHitTest(void);
	virtual System::Types::TRect __fastcall GetEditViewDataBounds(TcxGridLayoutViewItemViewInfo* AItem);
	virtual System::Types::TRect __fastcall GetRecordCaptionBounds(void);
	virtual int __fastcall GetRecordCaptionHeight(void);
	Cxlookandfeelpainters::TcxGroupBoxCaptionPosition __fastcall GetRecordCaptionPosition(void);
	virtual int __fastcall GetRecordCaptionTailSize(void);
	virtual System::UnicodeString __fastcall GetRecordCaptionText(void);
	virtual bool __fastcall HasRecordCaption(void);
	virtual bool __fastcall HasItemFocusRect(TcxGridLayoutViewItemViewInfo* AItem);
	virtual bool __fastcall IsExpanded(void);
	virtual bool __fastcall IsRecordCaptionRotated(void);
	virtual System::Types::TRect __fastcall GetLayoutAreaBounds(void);
	Cxgraphics::TcxBorders __fastcall GetLayoutAreaBorders(void);
	virtual void __fastcall CalculateItemViewInfos(void);
	virtual void __fastcall CreateItemViewInfos(void);
	virtual void __fastcall DestroyItemViewInfos(void);
	virtual void __fastcall PopulateTabOrderList(System::Classes::TList* AList);
	virtual TcxGridLayoutViewRecordExpandButtonViewInfoClass __fastcall GetExpandButtonViewInfoClass(void);
	virtual TcxGridLayoutViewItemViewInfoClass __fastcall GetItemViewInfoClass(void);
	virtual Cxgridcustomview::TcxCustomGridCellPainterClass __fastcall GetPainterClass(void);
	virtual TcxGridLayoutViewRecordCaptionViewInfoClass __fastcall GetRecordCaptionViewInfoClass(void);
	virtual void __fastcall CalculateLayout(void);
	void __fastcall CheckCloneData(void);
	void __fastcall CheckFocusedItem(void);
	void __fastcall ClearItemLinks(void);
	void __fastcall CloneDataChangedHandler(System::TObject* Sender);
	bool __fastcall IsDefaultCloneData(void);
	bool __fastcall LoadCloneData(void);
	void __fastcall RecalculateCloneData(void);
	virtual void __fastcall ResetCalculated(void);
	void __fastcall ResetCloneData(void);
	void __fastcall PrepareStyles(void);
	void __fastcall SaveCloneData(void);
	void __fastcall CalculateLayoutViewInfo(void);
	void __fastcall CreateLayoutViewInfo(void);
	__property TcxGridLayoutViewRecordViewInfoCacheItem* CacheItem = {read=GetCacheItem};
	__property TcxGridLayoutViewRecordExpandButtonAlignment ExpandButtonAlignment = {read=GetExpandButtonAlignment, nodefault};
	__property int ExpandButtonAreaWidth = {read=GetExpandButtonAreaWidth, nodefault};
	__property int ExpandButtonSize = {read=GetExpandButtonSizeValue, nodefault};
	__property System::Types::TRect LayoutAreaBounds = {read=GetLayoutAreaBounds};
	__property Cxgraphics::TcxBorders LayoutAreaBorders = {read=GetLayoutAreaBorders, nodefault};
	__property System::Types::TRect RecordCaptionBounds = {read=GetRecordCaptionBounds};
	__property Cxlookandfeelpainters::TcxGroupBoxCaptionPosition RecordCaptionPosition = {read=GetRecordCaptionPosition, nodefault};
	
public:
	__fastcall virtual TcxGridLayoutViewRecordViewInfo(Cxgridcustomtableview::TcxCustomGridRecordsViewInfo* ARecordsViewInfo, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__fastcall virtual ~TcxGridLayoutViewRecordViewInfo(void);
	virtual void __fastcall BeforeRecalculation(void);
	virtual void __fastcall Calculate(int ALeftBound, int ATopBound, int AWidth = 0xffffffff, int AHeight = 0xffffffff)/* overload */;
	virtual void __fastcall MainCalculate(int ALeftBound, int ATopBound);
	virtual bool __fastcall Click(Cxgridcustomview::TcxCustomGridHitTest* AHitTest, System::Uitypes::TMouseButton AButton, System::Classes::TShiftState AShift);
	virtual System::Types::TRect __fastcall GetBoundsForItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual Cxgridcustomtableview::TcxGridTableDataCellViewInfo* __fastcall GetCellViewInfoByItem(Cxgridcustomtableview::TcxCustomGridTableItem* AItem);
	virtual Cxgridcustomview::TcxCustomGridHitTest* __fastcall GetHitTest(const System::Types::TPoint P);
	virtual void __fastcall GetRecordBorderViewParams(Cxgraphics::TcxViewParams &AParams);
	__property TcxGridLayoutViewRecordCaptionViewInfo* CaptionViewInfo = {read=FCaptionViewInfo};
	__property TcxGridLayoutViewRecordExpandButtonViewInfo* ExpandButtonViewInfo = {read=FExpandButtonViewInfo};
	__property TcxGridLayoutViewRecord* GridRecord = {read=GetGridRecord};
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	__property TcxGridLayoutViewViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property int ItemViewInfoCount = {read=GetItemViewInfoCount, nodefault};
	__property TcxGridLayoutViewItemViewInfo* ItemViewInfos[int Index] = {read=GetItemViewInfos};
	__property TcxGridLayoutContainerViewInfo* LayoutViewInfo = {read=FLayoutViewInfo};
	__property TcxGridLayoutLookAndFeel* LayoutLookAndFeel = {read=FLayoutLookAndFeel};
	__property int RecordBorderWidth = {read=GetRecordBorderWidth, nodefault};
	__property TcxGridLayoutViewRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
/* Hoisted overloads: */
	
public:
	inline void __fastcall  Calculate(const System::Types::TRect &ABounds){ Cxgridcustomview::TcxCustomGridCellViewInfo::Calculate(ABounds); }
	
};


class DELPHICLASS TcxGridLayoutViewInfoHorizontalCalculator;
class PASCALIMPLEMENTATION TcxGridLayoutViewInfoHorizontalCalculator : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoHorizontalCalculator
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoHorizontalCalculator inherited;
	
private:
	TcxGridLayoutViewRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual void __fastcall DoCalculate(const System::Types::TRect &AContentBounds);
	virtual int __fastcall GetMaxColumnCount(void);
	virtual int __fastcall GetMaxRowCount(void);
	virtual bool __fastcall CanCenterHorizontally(void);
	virtual bool __fastcall CanCenterVertically(void);
	void __fastcall CenterHorizontally(const System::Types::TRect &AContentBounds);
	void __fastcall CenterVertically(const System::Types::TRect &AContentBounds);
	
public:
	__property TcxGridLayoutViewRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridLayoutViewInfoHorizontalCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoHorizontalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewInfoHorizontalCalculator(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewInfoVerticalCalculator;
class PASCALIMPLEMENTATION TcxGridLayoutViewInfoVerticalCalculator : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoVerticalCalculator
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoVerticalCalculator inherited;
	
private:
	TcxGridLayoutViewRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	int __fastcall GetRowCount(void);
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual void __fastcall DoCalculate(const System::Types::TRect &AContentBounds);
	virtual int __fastcall GetMaxColumnCount(void);
	virtual int __fastcall GetMaxRowCount(void);
	virtual bool __fastcall CanCenterHorizontally(void);
	virtual bool __fastcall CanCenterVertically(void);
	void __fastcall CenterHorizontally(const System::Types::TRect &AContentBounds);
	void __fastcall CenterVertically(const System::Types::TRect &AContentBounds);
	
public:
	__property TcxGridLayoutViewRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridLayoutViewInfoVerticalCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewInfoVerticalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewInfoVerticalCalculator(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewInfoSingleRecordCalculator;
class PASCALIMPLEMENTATION TcxGridLayoutViewInfoSingleRecordCalculator : public TcxGridLayoutViewInfoHorizontalCalculator
{
	typedef TcxGridLayoutViewInfoHorizontalCalculator inherited;
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall CanCenterVertically(void);
	virtual int __fastcall GetMaxColumnCount(void);
	virtual int __fastcall GetMaxRowCount(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridLayoutViewInfoSingleRecordCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : TcxGridLayoutViewInfoHorizontalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewInfoSingleRecordCalculator(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewInfoSingleColumnCalculator;
class PASCALIMPLEMENTATION TcxGridLayoutViewInfoSingleColumnCalculator : public TcxGridLayoutViewInfoVerticalCalculator
{
	typedef TcxGridLayoutViewInfoVerticalCalculator inherited;
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall CanCenterHorizontally(void);
	virtual bool __fastcall CanCenterVertically(void);
	virtual int __fastcall GetMaxColumnCount(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridLayoutViewInfoSingleColumnCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : TcxGridLayoutViewInfoVerticalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewInfoSingleColumnCalculator(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewInfoMultiColumnCalculator;
class PASCALIMPLEMENTATION TcxGridLayoutViewInfoMultiColumnCalculator : public TcxGridLayoutViewInfoHorizontalCalculator
{
	typedef TcxGridLayoutViewInfoHorizontalCalculator inherited;
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall CanCenterHorizontally(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridLayoutViewInfoMultiColumnCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : TcxGridLayoutViewInfoHorizontalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewInfoMultiColumnCalculator(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewInfoSingleRowCalculator;
class PASCALIMPLEMENTATION TcxGridLayoutViewInfoSingleRowCalculator : public TcxGridLayoutViewInfoHorizontalCalculator
{
	typedef TcxGridLayoutViewInfoHorizontalCalculator inherited;
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall CanCenterHorizontally(void);
	virtual bool __fastcall CanCenterVertically(void);
	virtual int __fastcall GetMaxRowCount(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridLayoutViewInfoSingleRowCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : TcxGridLayoutViewInfoHorizontalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewInfoSingleRowCalculator(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewInfoMultiRowCalculator;
class PASCALIMPLEMENTATION TcxGridLayoutViewInfoMultiRowCalculator : public TcxGridLayoutViewInfoVerticalCalculator
{
	typedef TcxGridLayoutViewInfoVerticalCalculator inherited;
	
protected:
	virtual void __fastcall AdjustContentBounds(System::Types::TRect &ABounds);
	virtual bool __fastcall CanCenterVertically(void);
public:
	/* TcxGridCustomLayoutRecordsViewInfoBasedCalculator.Create */ inline __fastcall virtual TcxGridLayoutViewInfoMultiRowCalculator(Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo* ARecordsViewInfo) : TcxGridLayoutViewInfoVerticalCalculator(ARecordsViewInfo) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewInfoMultiRowCalculator(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewController;
class DELPHICLASS TcxGridLayoutViewControllerHelper;
class PASCALIMPLEMENTATION TcxGridLayoutViewRecordsViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo inherited;
	
public:
	TcxGridLayoutViewRecordViewInfo* operator[](int Index) { return Items[Index]; }
	
private:
	HIDESBASE TcxGridLayoutViewController* __fastcall GetController(void);
	TcxGridLayoutViewControllerHelper* __fastcall GetControllerHelper(void);
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	HIDESBASE TcxGridLayoutViewViewInfo* __fastcall GetGridViewInfo(void);
	HIDESBASE TcxGridLayoutViewRecordViewInfo* __fastcall GetItem(int Index);
	HIDESBASE TcxGridLayoutViewViewData* __fastcall GetViewData(void);
	
protected:
	virtual int __fastcall CalculateRecordWidth(void);
	virtual void __fastcall CalculateVisibleRecordsBound(/* out */ int &AFirstRecordIndex, /* out */ int &ALastRecordIndex);
	virtual bool __fastcall GetAutoDataRecordHeight(void);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfoBasedCalculatorClass __fastcall GetCalculatorClass(void);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutRecordViewInfoClass __fastcall GetItemViewInfoClass(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsForEdit(void);
	virtual bool __fastcall IsCarouselMode(void);
	bool __fastcall CanCenterRecords(void);
	__property TcxGridLayoutViewController* Controller = {read=GetController};
	__property TcxGridLayoutViewControllerHelper* ControllerHelper = {read=GetControllerHelper};
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	__property TcxGridLayoutViewViewInfo* GridViewInfo = {read=GetGridViewInfo};
	__property TcxGridLayoutViewRecordViewInfo* Items[int Index] = {read=GetItem/*, default*/};
	__property TcxGridLayoutViewViewData* ViewData = {read=GetViewData};
public:
	/* TcxGridCustomLayoutRecordsViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewRecordsViewInfo(Cxgridcustomtableview::TcxCustomGridTableViewInfo* AGridViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutRecordsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutRecordsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordsViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewSeparatorsViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewSeparatorsViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewSeparatorsViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewSeparatorsViewInfo inherited;
	
private:
	HIDESBASE TcxGridLayoutViewRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	
protected:
	int __fastcall CalculateMaxBottom(int ARow);
	int __fastcall CalculateMaxRight(int AColumn);
	int __fastcall CalculateMinLeft(int AColumn);
	int __fastcall CalculateMinTop(int ARow);
	
public:
	__property TcxGridLayoutViewRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewSeparatorsViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewSeparatorsViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewSingleRecordSeparatorsViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewSingleRecordSeparatorsViewInfo : public TcxGridLayoutViewSeparatorsViewInfo
{
	typedef TcxGridLayoutViewSeparatorsViewInfo inherited;
	
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewSingleRecordSeparatorsViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : TcxGridLayoutViewSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewSingleRecordSeparatorsViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewSingleColumnRecordSeparatorsViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewSingleColumnRecordSeparatorsViewInfo : public TcxGridLayoutViewSeparatorsViewInfo
{
	typedef TcxGridLayoutViewSeparatorsViewInfo inherited;
	
public:
	virtual void __fastcall DoCalculate(void);
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewSingleColumnRecordSeparatorsViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : TcxGridLayoutViewSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewSingleColumnRecordSeparatorsViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewSingleRowRecordSeparatorsViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewSingleRowRecordSeparatorsViewInfo : public TcxGridLayoutViewSeparatorsViewInfo
{
	typedef TcxGridLayoutViewSeparatorsViewInfo inherited;
	
public:
	virtual void __fastcall DoCalculate(void);
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewSingleRowRecordSeparatorsViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : TcxGridLayoutViewSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewSingleRowRecordSeparatorsViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewMultiColumnRecordSeparatorsViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewMultiColumnRecordSeparatorsViewInfo : public TcxGridLayoutViewSingleRowRecordSeparatorsViewInfo
{
	typedef TcxGridLayoutViewSingleRowRecordSeparatorsViewInfo inherited;
	
public:
	virtual void __fastcall DoCalculate(void);
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewMultiColumnRecordSeparatorsViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : TcxGridLayoutViewSingleRowRecordSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewMultiColumnRecordSeparatorsViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewMultiRowRecordSeparatorsViewInfo;
class PASCALIMPLEMENTATION TcxGridLayoutViewMultiRowRecordSeparatorsViewInfo : public TcxGridLayoutViewSingleColumnRecordSeparatorsViewInfo
{
	typedef TcxGridLayoutViewSingleColumnRecordSeparatorsViewInfo inherited;
	
public:
	virtual void __fastcall DoCalculate(void);
public:
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewMultiRowRecordSeparatorsViewInfo(Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo* AGridViewInfo) : TcxGridLayoutViewSingleColumnRecordSeparatorsViewInfo(AGridViewInfo) { }
	/* TcxGridCustomLayoutViewSeparatorsViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewMultiRowRecordSeparatorsViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewSite;
class PASCALIMPLEMENTATION TcxGridLayoutViewSite : public Cxgridcustomview::TcxGridSite
{
	typedef Cxgridcustomview::TcxGridSite inherited;
	
private:
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	
protected:
	virtual void __fastcall UpdateSize(void);
	
public:
	__property TcxGridLayoutView* GridView = {read=GetGridView};
public:
	/* TcxGridSite.Create */ inline __fastcall virtual TcxGridLayoutViewSite(Cxgridcustomview::TcxCustomGridViewInfo* AViewInfo) : Cxgridcustomview::TcxGridSite(AViewInfo) { }
	/* TcxGridSite.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewSite(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TcxGridLayoutViewSite(HWND ParentWindow) : Cxgridcustomview::TcxGridSite(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TcxGridLayoutViewViewInfo : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo inherited;
	
private:
	bool FIsHeightCalculating;
	HIDESBASE TcxGridLayoutViewController* __fastcall GetController(void);
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	HIDESBASE TcxGridLayoutViewRecordsViewInfo* __fastcall GetRecordsViewInfo(void);
	
protected:
	virtual void __fastcall CalculateHeight(const System::Types::TPoint AMaxSize, int &AHeight, bool &AFullyVisible);
	virtual bool __fastcall GetAllowBoundsChangedNotification(void);
	virtual int __fastcall GetFirstRecordIndex(void);
	virtual Cxgridcustomtableview::TcxCustomGridRecordsViewInfoClass __fastcall GetRecordsViewInfoClass(void);
	virtual System::Types::TRect __fastcall GetScrollableAreaBoundsForEdit(void);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutViewSeparatorsViewInfoClass __fastcall GetSeparatorsViewInfoClass(void);
	virtual Cxgridcustomview::TcxGridSiteClass __fastcall GetSiteClass(void);
	virtual bool __fastcall IsDoubleBufferedNeeded(void);
	int __fastcall GetRecordCaptionHeight(void);
	bool __fastcall IsCarouselMode(void);
	__property TcxGridLayoutViewController* Controller = {read=GetController};
	__property bool IsHeightCalculating = {read=FIsHeightCalculating, nodefault};
	
public:
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	__property TcxGridLayoutViewRecordsViewInfo* RecordsViewInfo = {read=GetRecordsViewInfo};
public:
	/* TcxCustomGridTableViewInfo.Create */ inline __fastcall virtual TcxGridLayoutViewViewInfo(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewViewInfo(AGridView) { }
	/* TcxCustomGridTableViewInfo.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewViewInfo(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewItemOptions;
class PASCALIMPLEMENTATION TcxGridLayoutViewItemOptions : public Cxgridcustomtableview::TcxCustomGridTableItemOptions
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItemOptions inherited;
	
public:
	/* TcxCustomGridTableItemOptions.Create */ inline __fastcall virtual TcxGridLayoutViewItemOptions(Cxgridcustomtableview::TcxCustomGridTableItem* AItem) : Cxgridcustomtableview::TcxCustomGridTableItemOptions(AItem) { }
	
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewItemOptions(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridLayoutViewItem : public Cxgridcustomtableview::TcxCustomGridTableItem
{
	typedef Cxgridcustomtableview::TcxCustomGridTableItem inherited;
	
private:
	TcxGridLayoutItem* FLayoutItem;
	TcxGridLayoutView* __fastcall GetGridView(void);
	TcxGridLayoutViewItemOptions* __fastcall GetOptions(void);
	void __fastcall SetLayoutItem(TcxGridLayoutItem* const Value);
	HIDESBASE void __fastcall SetOptions(TcxGridLayoutViewItemOptions* Value);
	
protected:
	virtual bool __fastcall GetStoredProperties(System::Classes::TStrings* AProperties);
	virtual void __fastcall GetPropertyValue(const System::UnicodeString AName, System::Variant &AValue);
	virtual void __fastcall SetPropertyValue(const System::UnicodeString AName, const System::Variant &AValue);
	virtual void __fastcall Notification(System::Classes::TComponent* AComponent, System::Classes::TOperation Operation);
	virtual bool __fastcall CanAutoHeight(void);
	virtual bool __fastcall CanFocus(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual void __fastcall CaptionChanged(void);
	virtual void __fastcall ChangeGroupIndex(int Value);
	virtual bool __fastcall GetActuallyVisible(void);
	Cxedit::TcxCustomEditPropertiesClass __fastcall GetEditPropertiesClass(void);
	System::Types::TSize __fastcall GetEditMinSize(Vcl::Graphics::TFont* AFont);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemOptionsClass __fastcall GetOptionsClass(void);
	virtual void __fastcall DoSetVisible(bool Value);
	virtual bool __fastcall GetVisible(void);
	virtual System::UnicodeString __fastcall GetVisibleCaption(void);
	virtual System::UnicodeString __fastcall CaptionToDisplayCaption(const System::UnicodeString ACaption);
	virtual System::UnicodeString __fastcall DisplayCaptionToCaption(const System::UnicodeString ADisplayCaption);
	virtual void __fastcall SetGridView(Cxgridcustomtableview::TcxCustomGridTableView* Value);
	
public:
	__fastcall virtual ~TcxGridLayoutViewItem(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	
__published:
	__property TcxGridLayoutItem* LayoutItem = {read=FLayoutItem, write=SetLayoutItem};
	__property TcxGridLayoutViewItemOptions* Options = {read=GetOptions, write=SetOptions};
	__property SortIndex = {default=-1};
	__property SortOrder;
public:
	/* TcxCustomGridTableItem.Create */ inline __fastcall virtual TcxGridLayoutViewItem(System::Classes::TComponent* AOwner) : Cxgridcustomtableview::TcxCustomGridTableItem(AOwner) { }
	
};


class PASCALIMPLEMENTATION TcxGridLayoutViewRecord : public Cxgridcustomlayoutview::TcxGridCustomLayoutRecord
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutRecord inherited;
	
private:
	System::Classes::TMemoryStream* FCloneDataStream;
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	TcxGridLayoutViewRecordViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall GetExpanded(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoCacheItemClass __fastcall GetViewInfoCacheItemClass(void);
	__property System::Classes::TMemoryStream* CloneDataStream = {read=FCloneDataStream};
	
public:
	__fastcall virtual TcxGridLayoutViewRecord(Cxgridcustomtableview::TcxCustomGridTableViewData* AViewData, int AIndex, const Cxcustomdata::TcxRowInfo &ARecordInfo);
	__fastcall virtual ~TcxGridLayoutViewRecord(void);
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	__property TcxGridLayoutViewRecordViewInfo* ViewInfo = {read=GetViewInfo};
};


class PASCALIMPLEMENTATION TcxGridLayoutViewControllerHelper : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewControllerHelper
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewControllerHelper inherited;
	
private:
	TcxGridLayoutViewController* __fastcall GetController(void);
	TcxGridLayoutContainerViewInfo* __fastcall GetLayoutContainerViewInfo(Cxgridcustomtableview::TcxGridRecordHitTest* AHitTest);
	HIDESBASE TcxGridLayoutViewViewInfo* __fastcall GetViewInfo(void);
	
protected:
	virtual bool __fastcall CanScrollBarVisible(Vcl::Forms::TScrollBarKind AKind);
	virtual void __fastcall DoInitScrollBarParameters(Vcl::Forms::TScrollBarKind AKind, bool ACanHide);
	virtual int __fastcall GetContentPageSize(void) = 0 ;
	virtual int __fastcall GetContentScrollSize(void);
	bool __fastcall NeedContentScrollBar(void);
	__property TcxGridLayoutViewController* Controller = {read=GetController};
	__property TcxGridLayoutViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual Cxcontrols::TcxMouseWheelScrollingKind __fastcall GetMouseWheelScrollingKind(void);
	virtual int __fastcall GetScrollDelta(void);
	DYNAMIC void __fastcall KeyDown(System::Word &Key, System::Classes::TShiftState Shift);
	virtual void __fastcall MouseDown(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseMove(System::Classes::TShiftState Shift, int X, int Y);
	virtual void __fastcall MouseUp(System::Uitypes::TMouseButton Button, System::Classes::TShiftState Shift, int X, int Y);
public:
	/* TcxGridCustomLayoutViewControllerHelper.Create */ inline __fastcall virtual TcxGridLayoutViewControllerHelper(Cxgridcustomlayoutview::TcxGridCustomLayoutViewController* AController) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewControllerHelper(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewControllerHelper(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewControllerHorizontalHelper;
class PASCALIMPLEMENTATION TcxGridLayoutViewControllerHorizontalHelper : public TcxGridLayoutViewControllerHelper
{
	typedef TcxGridLayoutViewControllerHelper inherited;
	
protected:
	virtual bool __fastcall IsDataScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual int __fastcall GetContentPageSize(void);
	virtual int __fastcall GetContentScrollSize(void);
public:
	/* TcxGridCustomLayoutViewControllerHelper.Create */ inline __fastcall virtual TcxGridLayoutViewControllerHorizontalHelper(Cxgridcustomlayoutview::TcxGridCustomLayoutViewController* AController) : TcxGridLayoutViewControllerHelper(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewControllerHorizontalHelper(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewControllerVerticalHelper;
class PASCALIMPLEMENTATION TcxGridLayoutViewControllerVerticalHelper : public TcxGridLayoutViewControllerHelper
{
	typedef TcxGridLayoutViewControllerHelper inherited;
	
protected:
	virtual bool __fastcall IsDataScrollBar(Vcl::Forms::TScrollBarKind AKind);
	virtual int __fastcall GetContentPageSize(void);
	virtual int __fastcall GetContentScrollSize(void);
public:
	/* TcxGridCustomLayoutViewControllerHelper.Create */ inline __fastcall virtual TcxGridLayoutViewControllerVerticalHelper(Cxgridcustomlayoutview::TcxGridCustomLayoutViewController* AController) : TcxGridLayoutViewControllerHelper(AController) { }
	
public:
	/* TObject.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewControllerVerticalHelper(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridLayoutViewController : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewController
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewController inherited;
	
private:
	int FContentScrollBarPosition;
	TcxGridLayoutViewItem* __fastcall GetFocusedItem(void);
	HIDESBASE TcxGridLayoutViewRecordViewInfo* __fastcall GetFocusedRecordViewInfo(void);
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	TcxGridLayoutViewControllerHelper* __fastcall GetHelper(void);
	HIDESBASE TcxGridLayoutViewViewInfo* __fastcall GetViewInfo(void);
	void __fastcall SetContentScrollBarPosition(int Value);
	HIDESBASE void __fastcall SetFocusedItem(TcxGridLayoutViewItem* Value);
	
protected:
	virtual bool __fastcall CanCustomize(void);
	virtual void __fastcall CheckCustomizationFormBounds(System::Types::TRect &R);
	virtual Vcl::Forms::TForm* __fastcall CreateCustomizationForm(void);
	virtual void __fastcall CustomizationChanged(void);
	virtual void __fastcall DoCreateCustomizationForm(void);
	virtual void __fastcall DoScroll(Vcl::Forms::TScrollBarKind AScrollBarKind, System::Uitypes::TScrollCode AScrollCode, int &AScrollPos);
	virtual System::Types::TRect __fastcall GetCustomizationFormBounds(void);
	virtual int __fastcall GetCustomizationFormDefaultWidth(void);
	virtual int __fastcall GetCustomizationFormDefaultHeight(void);
	virtual int __fastcall ShowModalCustomizationForm(void);
	virtual bool __fastcall GetDesignHitTest(Cxgridcustomview::TcxCustomGridHitTest* AHitTest);
	virtual Cxgridcustomlayoutview::TcxGridCustomLayoutViewControllerHelperClass __fastcall GetHelperClass(void);
	void __fastcall CheckFocusItem(TcxGridLayoutViewItemViewInfo* AItemViewInfo);
	int __fastcall GetNextIndex(int AFocusedIndex, bool AGoForward, bool AGoOnCycle, /* out */ bool &ACycleChanged);
	__property int ContentScrollBarPosition = {read=FContentScrollBarPosition, write=SetContentScrollBarPosition, nodefault};
	__property TcxGridLayoutViewRecordViewInfo* FocusedRecordViewInfo = {read=GetFocusedRecordViewInfo};
	__property TcxGridLayoutViewControllerHelper* Helper = {read=GetHelper};
	__property TcxGridLayoutViewViewInfo* ViewInfo = {read=GetViewInfo};
	
public:
	virtual int __fastcall FindNextItem(int AFocusedItemIndex, bool AGoForward, bool AGoOnCycle, bool AFollowVisualOrder, /* out */ bool &ACycleChanged, Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	virtual bool __fastcall FocusNextItemVertically(bool AGoForward, bool AGoOnCycle);
	virtual bool __fastcall IsDataFullyVisible(bool AIsCallFromMaster = false);
	__property TcxGridLayoutViewItem* FocusedItem = {read=GetFocusedItem, write=SetFocusedItem};
	__property TcxGridLayoutView* GridView = {read=GetGridView};
public:
	/* TcxGridCustomLayoutViewController.Create */ inline __fastcall virtual TcxGridLayoutViewController(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewController(AGridView) { }
	/* TcxGridCustomLayoutViewController.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewController(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewDateTimeHandling;
class PASCALIMPLEMENTATION TcxGridLayoutViewDateTimeHandling : public Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling
{
	typedef Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling inherited;
	
public:
	/* TcxCustomGridTableDateTimeHandling.Create */ inline __fastcall virtual TcxGridLayoutViewDateTimeHandling(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableDateTimeHandling(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewDateTimeHandling(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewFiltering;
class PASCALIMPLEMENTATION TcxGridLayoutViewFiltering : public Cxgridcustomtableview::TcxCustomGridTableFiltering
{
	typedef Cxgridcustomtableview::TcxCustomGridTableFiltering inherited;
	
__published:
	__property ItemAddValueItems = {default=1};
	__property ItemFilteredItemsList = {default=0};
	__property ItemMRUItemsList = {default=1};
	__property ItemMRUItemsListCount = {default=5};
	__property ItemPopup;
	__property MRUItemsList = {default=1};
	__property MRUItemsListCount = {default=10};
public:
	/* TcxCustomGridTableFiltering.Create */ inline __fastcall virtual TcxGridLayoutViewFiltering(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableFiltering(AGridView) { }
	/* TcxCustomGridTableFiltering.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewFiltering(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewOptionsData;
class PASCALIMPLEMENTATION TcxGridLayoutViewOptionsData : public Cxgridcustomtableview::TcxCustomGridTableOptionsData
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsData inherited;
	
public:
	/* TcxCustomGridTableOptionsData.Create */ inline __fastcall virtual TcxGridLayoutViewOptionsData(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomtableview::TcxCustomGridTableOptionsData(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewOptionsData(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewOptionsSelection;
class PASCALIMPLEMENTATION TcxGridLayoutViewOptionsSelection : public Cxgridcustomtableview::TcxCustomGridTableOptionsSelection
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsSelection inherited;
	
private:
	bool FRecordBorderSelection;
	void __fastcall SetRecordBorderSelection(bool Value);
	
public:
	__fastcall virtual TcxGridLayoutViewOptionsSelection(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool RecordBorderSelection = {read=FRecordBorderSelection, write=SetRecordBorderSelection, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewOptionsSelection(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewOptionsBehavior;
class PASCALIMPLEMENTATION TcxGridLayoutViewOptionsBehavior : public Cxgridcustomtableview::TcxCustomGridTableOptionsBehavior
{
	typedef Cxgridcustomtableview::TcxCustomGridTableOptionsBehavior inherited;
	
private:
	bool FExpandRecordOnDblClick;
	bool FItemHotTrack;
	void __fastcall SetExpandRecordOnDblClick(const bool Value);
	void __fastcall SetItemHotTrack(const bool Value);
	
public:
	__fastcall virtual TcxGridLayoutViewOptionsBehavior(Cxgridcustomview::TcxCustomGridView* AGridView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property bool ExpandRecordOnDblClick = {read=FExpandRecordOnDblClick, write=SetExpandRecordOnDblClick, default=1};
	__property bool ItemHotTrack = {read=FItemHotTrack, write=SetItemHotTrack, default=1};
public:
	/* TcxCustomGridOptionsBehavior.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewOptionsBehavior(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewOptionsCustomize;
class PASCALIMPLEMENTATION TcxGridLayoutViewOptionsCustomize : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsCustomize
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsCustomize inherited;
	
private:
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	bool __fastcall GetGroupExpanding(void);
	bool __fastcall GetRecordExpanding(void);
	void __fastcall SetGroupExpanding(const bool Value);
	void __fastcall SetRecordExpanding(bool Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	
__published:
	__property bool GroupExpanding = {read=GetGroupExpanding, write=SetGroupExpanding, default=0};
	__property ItemFiltering = {default=1};
	__property bool RecordExpanding = {read=GetRecordExpanding, write=SetRecordExpanding, default=0};
public:
	/* TcxCustomGridTableOptionsCustomize.Create */ inline __fastcall virtual TcxGridLayoutViewOptionsCustomize(Cxgridcustomview::TcxCustomGridView* AGridView) : Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsCustomize(AGridView) { }
	
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewOptionsCustomize(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewCarouselMode;
class DELPHICLASS TcxGridLayoutViewOptionsView;
class PASCALIMPLEMENTATION TcxGridLayoutViewCarouselMode : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	unsigned FAnimatedDelay;
	bool FAutoPitchAngle;
	int FBackgroundRecordAlphaLevel;
	unsigned FBackgroundRecordEndScale;
	unsigned FBackgroundRecordStartScale;
	Dxgdiplusclasses::TdxGPInterpolationMode FInterpolationMode;
	double FPitchAngle;
	unsigned FRadius;
	double FRollAngle;
	int FRecordCount;
	double __fastcall GetDeltaAngle(void);
	TcxGridLayoutView* __fastcall GetGridView(void);
	bool __fastcall IsPitchAngleStored(void);
	bool __fastcall IsRollAngleStored(void);
	void __fastcall SetAutoPitchAngle(bool Value);
	void __fastcall SetBackgroundRecordAlphaLevel(int Value);
	void __fastcall SetBackgroundRecordEndScale(unsigned Value);
	void __fastcall SetBackgroundRecordStartScale(const unsigned Value);
	void __fastcall SetInterpolationMode(Dxgdiplusclasses::TdxGPInterpolationMode Value);
	void __fastcall SetPitchAngle(double Value);
	void __fastcall SetRadius(unsigned Value);
	void __fastcall SetRecordCount(int Value);
	void __fastcall SetRollAngle(double Value);
	
public:
	__fastcall virtual TcxGridLayoutViewCarouselMode(TcxGridLayoutViewOptionsView* AOptionsView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property double DeltaAngle = {read=GetDeltaAngle};
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	
__published:
	__property unsigned AnimationInterval = {read=FAnimatedDelay, write=FAnimatedDelay, default=500};
	__property bool AutoPitchAngle = {read=FAutoPitchAngle, write=SetAutoPitchAngle, default=0};
	__property int BackgroundRecordAlphaLevel = {read=FBackgroundRecordAlphaLevel, write=SetBackgroundRecordAlphaLevel, default=0};
	__property unsigned BackgroundRecordEndScale = {read=FBackgroundRecordEndScale, write=SetBackgroundRecordEndScale, default=20};
	__property unsigned BackgroundRecordStartScale = {read=FBackgroundRecordStartScale, write=SetBackgroundRecordStartScale, default=60};
	__property Dxgdiplusclasses::TdxGPInterpolationMode InterpolationMode = {read=FInterpolationMode, write=SetInterpolationMode, default=0};
	__property double PitchAngle = {read=FPitchAngle, write=SetPitchAngle, stored=IsPitchAngleStored};
	__property unsigned Radius = {read=FRadius, write=SetRadius, default=0};
	__property int RecordCount = {read=FRecordCount, write=SetRecordCount, default=15};
	__property double RollAngle = {read=FRollAngle, write=SetRollAngle, stored=IsRollAngleStored};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewCarouselMode(void) { }
	
};


typedef System::TMetaClass* TcxGridLayoutViewCarouselModeClass;

class DELPHICLASS TcxGridLayoutViewRecordCaption;
class PASCALIMPLEMENTATION TcxGridLayoutViewRecordCaption : public Cxgridcustomview::TcxCustomGridOptions
{
	typedef Cxgridcustomview::TcxCustomGridOptions inherited;
	
private:
	System::UnicodeString FDisplayMask;
	TcxGridLayoutViewRecordExpandButtonAlignment FExpandButtonAlignment;
	System::UnicodeString FFormatString;
	int FHeight;
	bool FIsNeedRecordIndex;
	bool FIsNeedRecordCount;
	Cxclasses::TcxAlignmentVert FTextAlignmentVert;
	System::Classes::TAlignment FTextAlignmentHorz;
	bool FVisible;
	bool __fastcall IsDisplayMaskStored(void);
	void __fastcall SetExpandButtonAlignment(TcxGridLayoutViewRecordExpandButtonAlignment Value);
	void __fastcall SetHeight(int Value);
	void __fastcall SetVisible(bool Value);
	void __fastcall SetTextAlignmentHorz(System::Classes::TAlignment Value);
	void __fastcall SetTextAlignmentVert(Cxclasses::TcxAlignmentVert Value);
	void __fastcall SetDisplayMask(const System::UnicodeString Value);
	
protected:
	void __fastcall BuildFormatString(void);
	__property bool IsNeedRecordIndex = {read=FIsNeedRecordIndex, nodefault};
	__property bool IsNeedRecordCount = {read=FIsNeedRecordCount, nodefault};
	
public:
	__fastcall virtual TcxGridLayoutViewRecordCaption(TcxGridLayoutViewOptionsView* AOptionsView);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual System::UnicodeString __fastcall GetFormattedText(TcxGridLayoutViewRecord* AGridRecord);
	
__published:
	__property System::UnicodeString DisplayMask = {read=FDisplayMask, write=SetDisplayMask, stored=IsDisplayMaskStored};
	__property TcxGridLayoutViewRecordExpandButtonAlignment ExpandButtonAlignment = {read=FExpandButtonAlignment, write=SetExpandButtonAlignment, default=1};
	__property int Height = {read=FHeight, write=SetHeight, default=0};
	__property System::Classes::TAlignment TextAlignmentHorz = {read=FTextAlignmentHorz, write=SetTextAlignmentHorz, default=0};
	__property Cxclasses::TcxAlignmentVert TextAlignmentVert = {read=FTextAlignmentVert, write=SetTextAlignmentVert, default=2};
	__property bool Visible = {read=FVisible, write=SetVisible, default=1};
public:
	/* TcxCustomGridOptions.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewRecordCaption(void) { }
	
};


typedef System::TMetaClass* TcxGridLayoutViewRecordHeaderClass;

enum TcxGridLayoutViewViewMode : unsigned char { lvvmSingleRecord, lvvmSingleRow, lvvmMultiRow, lvvmSingleColumn, lvvmMultiColumn, lvvmCarousel };

enum TcxGridLayoutViewSingleRecordStretch : unsigned char { srsNone, srsHorizontal, srsVertical, srsClient };

class PASCALIMPLEMENTATION TcxGridLayoutViewOptionsView : public Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsView
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutViewOptionsView inherited;
	
private:
	TcxGridLayoutViewCarouselMode* FCarouselMode;
	bool FCenterRecords;
	int FMaxColumnCount;
	int FMaxRowCount;
	int FMinValueWidth;
	int FRecordBorderWidth;
	TcxGridLayoutViewRecordCaption* FRecordCaption;
	bool FShowOnlyEntireRecords;
	TcxGridLayoutViewSingleRecordStretch FSingleRecordStretch;
	TcxGridLayoutViewViewMode FViewMode;
	HIDESBASE TcxGridLayoutView* __fastcall GetGridView(void);
	int __fastcall GetRecordIndent(void);
	void __fastcall SetCarouselMode(TcxGridLayoutViewCarouselMode* Value);
	void __fastcall SetCenterRecords(bool Value);
	void __fastcall SetMaxColumnCount(int Value);
	void __fastcall SetMaxRowCount(int Value);
	void __fastcall SetMinValueWidth(int Value);
	void __fastcall SetRecordCaption(TcxGridLayoutViewRecordCaption* Value);
	void __fastcall SetRecordIndent(int Value);
	void __fastcall SetRecordBorderWidth(int Value);
	void __fastcall SetShowOnlyEntireRecords(bool Value);
	void __fastcall SetSingleRecordStretch(TcxGridLayoutViewSingleRecordStretch Value);
	void __fastcall SetViewMode(TcxGridLayoutViewViewMode Value);
	TcxLayoutViewLookAndFeelItemPadding* __fastcall GetItemPadding(void);
	void __fastcall SetItemPadding(TcxLayoutViewLookAndFeelItemPadding* const Value);
	
protected:
	virtual TcxGridLayoutViewCarouselModeClass __fastcall GetCarouselModeClass(void);
	virtual TcxGridLayoutViewRecordHeaderClass __fastcall GetRecordCaptionClass(void);
	bool __fastcall NeedStretchRecordHeight(void);
	bool __fastcall NeedStretchRecordWidth(void);
	
public:
	__fastcall virtual TcxGridLayoutViewOptionsView(Cxgridcustomview::TcxCustomGridView* AGridView);
	__fastcall virtual ~TcxGridLayoutViewOptionsView(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	__property TcxGridLayoutView* GridView = {read=GetGridView};
	
__published:
	__property TcxGridLayoutViewCarouselMode* CarouselMode = {read=FCarouselMode, write=SetCarouselMode};
	__property bool CenterRecords = {read=FCenterRecords, write=SetCenterRecords, default=1};
	__property TcxLayoutViewLookAndFeelItemPadding* ItemPadding = {read=GetItemPadding, write=SetItemPadding};
	__property int MaxColumnCount = {read=FMaxColumnCount, write=SetMaxColumnCount, default=0};
	__property int MaxRowCount = {read=FMaxRowCount, write=SetMaxRowCount, default=0};
	__property int MinValueWidth = {read=FMinValueWidth, write=SetMinValueWidth, default=80};
	__property int RecordBorderWidth = {read=FRecordBorderWidth, write=SetRecordBorderWidth, default=0};
	__property TcxGridLayoutViewRecordCaption* RecordCaption = {read=FRecordCaption, write=SetRecordCaption};
	__property int RecordIndent = {read=GetRecordIndent, write=SetRecordIndent, default=7};
	__property SeparatorColor = {default=536870912};
	__property SeparatorWidth = {default=2};
	__property ShowItemFilterButtons = {default=1};
	__property bool ShowOnlyEntireRecords = {read=FShowOnlyEntireRecords, write=SetShowOnlyEntireRecords, default=1};
	__property TcxGridLayoutViewSingleRecordStretch SingleRecordStretch = {read=FSingleRecordStretch, write=SetSingleRecordStretch, default=0};
	__property TcxGridLayoutViewViewMode ViewMode = {read=FViewMode, write=SetViewMode, default=0};
};


class DELPHICLASS TcxGridLayoutViewStyles;
class PASCALIMPLEMENTATION TcxGridLayoutViewStyles : public Cxgridcustomtableview::TcxCustomGridTableViewStyles
{
	typedef Cxgridcustomtableview::TcxCustomGridTableViewStyles inherited;
	
private:
	bool FIsRecordCaptionParams;
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetGroupStyle;
	Cxgridcustomtableview::TcxGridGetCellStyleEvent FOnGetItemStyle;
	Cxgridcustomtableview::TcxGridGetRecordStyleEvent FOnGetRecordBorderStyle;
	Cxgridcustomtableview::TcxGridGetRecordStyleEvent FOnGetRecordCaptionStyle;
	HIDESBASE TcxGridLayoutView* __fastcall GetGridViewValue(void);
	void __fastcall SetOnGetItemStyle(Cxgridcustomtableview::TcxGridGetCellStyleEvent Value);
	void __fastcall SetOnGetRecordBorderStyle(Cxgridcustomtableview::TcxGridGetRecordStyleEvent Value);
	void __fastcall SetOnGetRecordCaptionStyle(Cxgridcustomtableview::TcxGridGetRecordStyleEvent Value);
	
protected:
	virtual void __fastcall DoChanged(int AIndex);
	virtual int __fastcall GetBackgroundBitmapIndex(int Index);
	virtual Vcl::Graphics::TBitmap* __fastcall GetDefaultBitmap(int Index);
	virtual void __fastcall GetDefaultViewParams(int Index, System::TObject* AData, /* out */ Cxgraphics::TcxViewParams &AParams);
	
public:
	__fastcall virtual TcxGridLayoutViewStyles(System::Classes::TPersistent* AOwner);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	virtual void __fastcall GetGroupParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetItemParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetItemHottrackParams(Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetRecordBorderParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetRecordCaptionParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	virtual void __fastcall GetRecordBorderVisualParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridLayoutView* GridView = {read=GetGridViewValue};
	__property bool IsRecordCaptionParams = {read=FIsRecordCaptionParams, nodefault};
	
__published:
	__property Cxstyles::TcxStyle* Group = {read=GetValue, write=SetValue, index=10};
	__property Cxstyles::TcxStyle* Item = {read=GetValue, write=SetValue, index=11};
	__property Cxstyles::TcxStyle* ItemHottrack = {read=GetValue, write=SetValue, index=14};
	__property Cxstyles::TcxStyle* RecordBorder = {read=GetValue, write=SetValue, index=12};
	__property Cxstyles::TcxStyle* RecordCaption = {read=GetValue, write=SetValue, index=13};
	__property StyleSheet;
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetGroupStyle = {read=FOnGetGroupStyle, write=FOnGetGroupStyle};
	__property Cxgridcustomtableview::TcxGridGetCellStyleEvent OnGetItemStyle = {read=FOnGetItemStyle, write=SetOnGetItemStyle};
	__property Cxgridcustomtableview::TcxGridGetRecordStyleEvent OnGetRecordBorderStyle = {read=FOnGetRecordBorderStyle, write=SetOnGetRecordBorderStyle};
	__property Cxgridcustomtableview::TcxGridGetRecordStyleEvent OnGetRecordCaptionStyle = {read=FOnGetRecordCaptionStyle, write=SetOnGetRecordCaptionStyle};
public:
	/* TcxCustomStyles.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewStyles(void) { }
	
};


class DELPHICLASS TcxGridLayoutViewStyleSheet;
class PASCALIMPLEMENTATION TcxGridLayoutViewStyleSheet : public Cxstyles::TcxCustomStyleSheet
{
	typedef Cxstyles::TcxCustomStyleSheet inherited;
	
private:
	TcxGridLayoutViewStyles* __fastcall GetStylesValue(void);
	void __fastcall SetStylesValue(TcxGridLayoutViewStyles* Value);
	
public:
	__classmethod virtual Cxstyles::TcxCustomStylesClass __fastcall GetStylesClass();
	
__published:
	__property TcxGridLayoutViewStyles* Styles = {read=GetStylesValue, write=SetStylesValue};
public:
	/* TcxCustomStyleSheet.Create */ inline __fastcall virtual TcxGridLayoutViewStyleSheet(System::Classes::TComponent* AOwner) : Cxstyles::TcxCustomStyleSheet(AOwner) { }
	/* TcxCustomStyleSheet.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewStyleSheet(void) { }
	
};


typedef void __fastcall (__closure *TcxGridLayoutViewCustomDrawRecordHeaderEvent)(TcxGridLayoutView* Sender, Cxgraphics::TcxCanvas* ACanvas, TcxGridLayoutViewRecordCaptionViewInfo* AViewInfo, bool &ADone);

__interface IcxGridLayoutViewStylesHelper;
typedef System::DelphiInterface<IcxGridLayoutViewStylesHelper> _di_IcxGridLayoutViewStylesHelper;
__interface  INTERFACE_UUID("{79CDADCA-DDC3-439F-9881-3406B13399EA}") IcxGridLayoutViewStylesHelper  : public System::IInterface 
{
	
public:
	virtual void __fastcall GetContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams) = 0 ;
	virtual void __fastcall GetGroupParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams) = 0 ;
	virtual void __fastcall GetItemParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams) = 0 ;
	virtual void __fastcall GetRecordCaptionParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams) = 0 ;
};

class DELPHICLASS TcxGridLayoutViewStylesAdapter;
class PASCALIMPLEMENTATION TcxGridLayoutViewStylesAdapter : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	TcxGridLayoutView* FGridView;
	_di_IcxGridLayoutViewStylesHelper FHelper;
	TcxGridLayoutViewStyles* __fastcall GetStyles(void);
	
public:
	__fastcall TcxGridLayoutViewStylesAdapter(TcxGridLayoutView* AGridView);
	void __fastcall GetContentParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	void __fastcall GetGroupParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	void __fastcall GetItemParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, /* out */ Cxgraphics::TcxViewParams &AParams);
	void __fastcall GetRecordCaptionParams(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, /* out */ Cxgraphics::TcxViewParams &AParams);
	__property TcxGridLayoutViewStyles* Styles = {read=GetStyles};
	__property TcxGridLayoutView* GridView = {read=FGridView};
	__property _di_IcxGridLayoutViewStylesHelper Helper = {read=FHelper, write=FHelper};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TcxGridLayoutViewStylesAdapter(void) { }
	
};


class PASCALIMPLEMENTATION TcxGridLayoutView : public Cxgridcustomlayoutview::TcxGridCustomLayoutView
{
	typedef Cxgridcustomlayoutview::TcxGridCustomLayoutView inherited;
	
private:
	TcxGridLayoutContainer* FContainer;
	TcxGridLayoutLookAndFeel* FLayoutLookAndFeel;
	TcxGridLayoutViewStylesAdapter* FStylesAdapter;
	System::Classes::TMemoryStream* FDefaultCloneData;
	TcxGridLayoutContainerViewInfo* FDefaultLayoutViewInfo;
	bool FIsDefaultViewInfoCalculated;
	TcxGridLayoutViewCustomDrawRecordHeaderEvent FOnCustomDrawRecordCaption;
	Cxgrid::TcxCustomGrid* __fastcall GetControl(void);
	HIDESBASE TcxGridLayoutViewController* __fastcall GetController(void);
	Cxgridcustomtableview::TcxGridDataController* __fastcall GetDataController(void);
	TcxGridLayoutViewDateTimeHandling* __fastcall GetDateTimeHandling(void);
	TcxGridLayoutViewFiltering* __fastcall GetFiltering(void);
	HIDESBASE TcxGridLayoutViewItem* __fastcall GetItem(int Index);
	HIDESBASE TcxGridLayoutViewOptionsBehavior* __fastcall GetOptionsBehavior(void);
	HIDESBASE TcxGridLayoutViewOptionsCustomize* __fastcall GetOptionsCustomize(void);
	HIDESBASE TcxGridLayoutViewOptionsData* __fastcall GetOptionsData(void);
	HIDESBASE TcxGridLayoutViewOptionsSelection* __fastcall GetOptionsSelection(void);
	HIDESBASE TcxGridLayoutViewOptionsView* __fastcall GetOptionsView(void);
	Dxlayoutcontainer::TdxLayoutGroup* __fastcall GetRoot(void);
	HIDESBASE TcxGridLayoutViewStyles* __fastcall GetStyles(void);
	HIDESBASE TcxGridLayoutViewViewInfo* __fastcall GetViewInfo(void);
	HIDESBASE TcxGridLayoutViewItem* __fastcall GetVisibleItem(int Index);
	void __fastcall LayoutChangedHandler(System::TObject* Sender);
	void __fastcall SetDataController(Cxgridcustomtableview::TcxGridDataController* Value);
	HIDESBASE void __fastcall SetDateTimeHandling(TcxGridLayoutViewDateTimeHandling* Value);
	HIDESBASE void __fastcall SetFiltering(TcxGridLayoutViewFiltering* Value);
	HIDESBASE void __fastcall SetItem(int Index, TcxGridLayoutViewItem* Value);
	HIDESBASE void __fastcall SetOptionsBehavior(TcxGridLayoutViewOptionsBehavior* Value);
	HIDESBASE void __fastcall SetOptionsCustomize(TcxGridLayoutViewOptionsCustomize* Value);
	HIDESBASE void __fastcall SetOptionsData(TcxGridLayoutViewOptionsData* Value);
	HIDESBASE void __fastcall SetOptionsSelection(TcxGridLayoutViewOptionsSelection* Value);
	HIDESBASE void __fastcall SetOptionsView(TcxGridLayoutViewOptionsView* Value);
	HIDESBASE void __fastcall SetStyles(TcxGridLayoutViewStyles* Value);
	void __fastcall SetOnCustomDrawRecordCaption(TcxGridLayoutViewCustomDrawRecordHeaderEvent Value);
	
protected:
	virtual void __fastcall AfterRestoring(void);
	virtual void __fastcall BeforeRestoring(void);
	virtual void __fastcall DoAssign(Cxgridcustomview::TcxCustomGridView* ASource);
	virtual void __fastcall GetStoredChildren(System::Classes::TStringList* AChildren);
	virtual void __fastcall LookAndFeelChanged(void);
	virtual void __fastcall Init(void);
	virtual bool __fastcall IsRecordPixelScrolling(void);
	virtual bool __fastcall ShowGridViewEditor(void);
	void __fastcall AssignDefaultBounds(TcxGridLayoutContainerViewInfo* AViewInfo);
	void __fastcall RecalculateCloneData(void);
	void __fastcall ResetCalculatedLayoutViewInfo(void);
	void __fastcall ResetCloneData(void);
	void __fastcall PrepareStyles(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, TcxGridLayoutLookAndFeel* &ALayoutLookAndFeel);
	Dxlayoutcontainer::TdxLayoutContainer* __fastcall GetLayoutContainer(void);
	virtual void __fastcall AssignLayout(Cxgridcustomview::TcxCustomGridView* ALayoutView);
	virtual System::UnicodeString __fastcall GetLayoutCustomizationFormButtonCaption(void);
	Cxgraphics::TcxCanvas* __fastcall GetCanvas(void);
	System::Types::TRect __fastcall GetClientBounds(void);
	System::Types::TRect __fastcall GetClientRect(void);
	Dxlayoutcontainer::TdxLayoutContainer* __fastcall GetContainer(void);
	Vcl::Graphics::TFont* __fastcall GetDefaultFont(void);
	bool __fastcall GetHighlightRoot(void);
	void __fastcall CreateLayoutContainer(void);
	void __fastcall DestroyLayoutContainer(void);
	void __fastcall RecreateLayoutContainer(void);
	virtual bool __fastcall CalculateDataCellSelected(Cxgridcustomtableview::TcxCustomGridRecord* ARecord, Cxgridcustomtableview::TcxCustomGridTableItem* AItem, bool AUseViewInfo, Cxgridcustomtableview::TcxGridTableCellViewInfo* ACellViewInfo);
	virtual Cxgridcustomview::TcxCustomGridControllerClass __fastcall GetControllerClass(void);
	virtual Cxcustomdata::TcxCustomDataControllerClass __fastcall GetDataControllerClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableDateTimeHandlingClass __fastcall GetDateTimeHandlingClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableFilteringClass __fastcall GetFilteringClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableItemClass __fastcall GetItemClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsBehaviorClass __fastcall GetOptionsBehaviorClass(void);
	virtual Cxgridcustomtableview::TcxCustomGridTableOptionsCustomizeClass __fastcall GetOptionsCustomizeClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsDataClass __fastcall GetOptionsDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsSelectionClass __fastcall GetOptionsSelectionClass(void);
	virtual Cxgridcustomview::TcxCustomGridOptionsViewClass __fastcall GetOptionsViewClass(void);
	virtual Cxgridcustomview::TcxCustomGridPainterClass __fastcall GetPainterClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewStylesClass __fastcall GetStylesClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewDataClass __fastcall GetViewDataClass(void);
	virtual Cxgridcustomview::TcxCustomGridViewInfoClass __fastcall GetViewInfoClass(void);
	virtual void __fastcall SetControl(Cxcontrols::TcxControl* Value);
	virtual void __fastcall SetName(const System::Classes::TComponentName NewName);
	void __fastcall CopyLayoutStructure(Dxlayoutcontainer::TdxLayoutContainer* AContainer);
	virtual TcxGridLayoutLookAndFeel* __fastcall CreateLayoutLookAndFeel(void);
	virtual TcxGridLayoutContainerClass __fastcall GetLayoutContainerClass(void);
	virtual Dxlayoutcontainer::TdxLayoutGroupClass __fastcall GetLayoutGroupClass(void);
	void __fastcall UpdateSizeDefaultViewInfo(void);
	virtual void __fastcall DoCustomDrawRecordHeader(Cxgraphics::TcxCanvas* ACanvas, TcxGridLayoutViewRecordCaptionViewInfo* AViewInfo, bool &ADone);
	bool __fastcall HasCustomDrawRecordHeader(void);
	virtual bool __fastcall DrawRecordBorderSelected(Cxgridcustomtableview::TcxCustomGridRecord* ARecord);
	__property System::Classes::TMemoryStream* DefaultCloneData = {read=FDefaultCloneData};
	__property TcxGridLayoutContainerViewInfo* DefaultLayoutViewInfo = {read=FDefaultLayoutViewInfo};
	__property bool IsDefaultViewInfoCalculated = {read=FIsDefaultViewInfoCalculated, write=FIsDefaultViewInfoCalculated, nodefault};
	__property Dxlayoutcontainer::TdxLayoutGroup* Root = {read=GetRoot};
	
public:
	__fastcall virtual TcxGridLayoutView(System::Classes::TComponent* AOwner);
	__fastcall virtual TcxGridLayoutView(Cxcontrols::TcxControl* AControl, bool AAssignOwner);
	__fastcall virtual ~TcxGridLayoutView(void);
	DYNAMIC void __fastcall GetChildren(System::Classes::TGetChildProc Proc, System::Classes::TComponent* Root);
	HIDESBASE TcxGridLayoutViewItem* __fastcall CreateItem(void);
	virtual bool __fastcall SizeChanged(bool AUpdateSelfOnly = false, bool AKeepMaster = false);
	__property TcxGridLayoutContainer* Container = {read=FContainer};
	__property Cxgrid::TcxCustomGrid* Control = {read=GetControl};
	__property TcxGridLayoutViewController* Controller = {read=GetController};
	__property TcxGridLayoutLookAndFeel* LayoutLookAndFeel = {read=FLayoutLookAndFeel};
	__property TcxGridLayoutViewStylesAdapter* StylesAdapter = {read=FStylesAdapter};
	__property TcxGridLayoutViewItem* Items[int Index] = {read=GetItem, write=SetItem};
	__property TcxGridLayoutViewViewInfo* ViewInfo = {read=GetViewInfo};
	__property TcxGridLayoutViewItem* VisibleItems[int Index] = {read=GetVisibleItem};
	
__published:
	__property Cxgridcustomtableview::TcxGridDataController* DataController = {read=GetDataController, write=SetDataController};
	__property TcxGridLayoutViewDateTimeHandling* DateTimeHandling = {read=GetDateTimeHandling, write=SetDateTimeHandling};
	__property TcxGridLayoutViewFiltering* Filtering = {read=GetFiltering, write=SetFiltering};
	__property Images;
	__property TcxGridLayoutViewOptionsBehavior* OptionsBehavior = {read=GetOptionsBehavior, write=SetOptionsBehavior};
	__property TcxGridLayoutViewOptionsCustomize* OptionsCustomize = {read=GetOptionsCustomize, write=SetOptionsCustomize};
	__property TcxGridLayoutViewOptionsData* OptionsData = {read=GetOptionsData, write=SetOptionsData};
	__property TcxGridLayoutViewOptionsSelection* OptionsSelection = {read=GetOptionsSelection, write=SetOptionsSelection};
	__property TcxGridLayoutViewOptionsView* OptionsView = {read=GetOptionsView, write=SetOptionsView};
	__property TcxGridLayoutViewStyles* Styles = {read=GetStyles, write=SetStyles};
	__property OnCustomization;
	__property TcxGridLayoutViewCustomDrawRecordHeaderEvent OnCustomDrawRecordCaption = {read=FOnCustomDrawRecordCaption, write=SetOnCustomDrawRecordCaption};
public:
	/* TcxCustomGridView.CreateCloned */ inline __fastcall virtual TcxGridLayoutView(Cxcontrols::TcxControl* AControl) : Cxgridcustomlayoutview::TcxGridCustomLayoutView(AControl) { }
	
private:
	void *__IdxLayoutContainer;	/* Dxlayoutcontainer::IdxLayoutContainer */
	
public:
	#if defined(MANAGED_INTERFACE_OPERATORS)
	// {85310BD8-3D7A-454F-A54B-9898C0AA55A2}
	operator Dxlayoutcontainer::_di_IdxLayoutContainer()
	{
		Dxlayoutcontainer::_di_IdxLayoutContainer intf;
		GetInterface(intf);
		return intf;
	}
	#else
	operator Dxlayoutcontainer::IdxLayoutContainer*(void) { return (Dxlayoutcontainer::IdxLayoutContainer*)&__IdxLayoutContainer; }
	#endif
	
};


//-- var, const, procedure ---------------------------------------------------
static const System::Word cxGridLayoutViewCustomizationFormDefaultWidth = System::Word(0x258);
static const System::Word cxGridLayoutViewCustomizationFormDefaultHeight = System::Word(0x1f4);
static const System::Int8 cxGridLayoutViewCarouselModeDefaultRecordCount = System::Int8(0xf);
static const System::Word cxGridLayoutViewCarouselModeDefaultAnimatedDelay = System::Word(0x1f4);
static const System::Int8 cxGridLayoutViewCarouselModeDefaultBackgroundRecordEndScale = System::Int8(0x14);
static const System::Int8 cxGridLayoutViewCarouselModeDefaultBackgroundRecordStartScale = System::Int8(0x3c);
static const System::Byte htLayoutViewBase = System::Byte(0xaa);
static const System::Byte htLayoutViewItemIndent = System::Byte(0xab);
static const System::Byte htLayoutViewItemExpandButton = System::Byte(0xac);
static const System::Byte htLayoutViewItem = System::Byte(0xad);
static const System::Byte htLayoutViewItemFilterButton = System::Byte(0xae);
static const System::Byte htLayoutViewRecordCaption = System::Byte(0xaf);
static const System::Byte htLayoutViewRecordScrollButtonUp = System::Byte(0xb0);
static const System::Byte htLayoutViewRecordScrollButtonDown = System::Byte(0xb1);
static const System::Byte htLayoutViewRecordSeparator = System::Byte(0xb2);
static const System::Int8 vsLayoutViewFirst = System::Int8(0xa);
static const System::Int8 vsGroup = System::Int8(0xa);
static const System::Int8 vsItem = System::Int8(0xb);
static const System::Int8 vsRecordBorder = System::Int8(0xc);
static const System::Int8 vsRecordCaption = System::Int8(0xd);
static const System::Int8 vsItemHottrack = System::Int8(0xe);
static const System::Int8 cxGridLayoutViewDefaultRecordBorderWidth = System::Int8(0x0);
static const System::Int8 cxGridLayoutViewDefaultMinValueWidth = System::Int8(0x50);
static const System::Int8 cxGridLayoutViewRecordExpandButtonOffset = System::Int8(0x5);
}	/* namespace Cxgridlayoutview */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_CXGRIDLAYOUTVIEW)
using namespace Cxgridlayoutview;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// CxgridlayoutviewHPP
